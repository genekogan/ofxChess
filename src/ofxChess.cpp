#include "ofxChess.h"



void ofxChessBoard::addPiece(int r, int c, ofxChessPieceColor color, ofxChessPieceType type) {
    if (type == PAWN) {
        pieces[r][c] = new ofxChessPawn(color, ofPoint(r,c));
    }
    else if (type == BISHOP) {
        pieces[r][c] = new ofxChessBishop(color, ofPoint(r,c));
    }
}



void ofxChessPiece::analyze() {
    
}

void ofxChessPawn::updateMoves() {
    ofxChessPiece::updateMoves();
    
    ofPoint origin = position;
    ofPoint destination = ofPoint(position.x, position.y+(color==WHITE?-1:1));
    vector<ofPoint> path;
    path.push_back(origin);
    path.push_back(destination);

    possibleMoves.push_back(ofxChessMove(origin, destination, path));
    for (int i=0; i<possibleMoves.size(); i++) {
        
    }
}

void ofxChessBishop::updateMoves() {
    ofxChessPiece::updateMoves();
    
    ofPoint origin = position;
    ofPoint destination = ofPoint(position.x, position.y+(color==WHITE?-1:1));
    vector<ofPoint> path;
    path.push_back(origin);
    path.push_back(destination);
    
    possibleMoves.push_back(ofxChessMove(origin, destination, path));
    for (int i=0; i<possibleMoves.size(); i++) {
        
    }
}




//---------
void ofxChess::setup() {
    board.addPiece(3, 3, WHITE, PAWN);
    board.addPiece(4, 3, WHITE, BISHOP);

    board.addPiece(4, 6, BLACK, PAWN);
    board.addPiece(5, 6, BLACK, BISHOP);

}

//---------
void ofxChess::update() {
    
}

//---------
void ofxChess::draw() {

    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(100, 100);

    ofSetColor(0);
    
    for (int r=0; r<8; r++) {
        for (int c=0; c<8; c++) {
            
            ofPushMatrix();
            ofPushStyle();
            
            ofTranslate(r*50, c*50);
            ofNoFill();
            ofRect(0, 0, 50, 50);
            
            if (board.getPiece(r, c) == NULL) {
                
            }
            else {
                ofxChessPieceType type = board.getPiece(r, c)->getType();
                ofxChessPieceColor color = board.getPiece(r, c)->getColor();
                if (type == PAWN) {
                    ofDrawBitmapString("P", 5, 30);
                }
                else if (type == BISHOP) {
                    ofDrawBitmapString("B", 5, 30);
                }
            }
            
            ofPopStyle();
            ofPopMatrix();

        }
    }
    
    ofPopStyle();
    ofPopMatrix();

}

