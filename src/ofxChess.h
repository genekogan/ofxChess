#pragma once

#include "ofMain.h"

class ofxChessPiece;



enum ofxChessPieceType { PAWN, BISHOP };
enum ofxChessPieceColor { WHITE, BLACK };


class ofxChessMove {
public:
    ofxChessMove(ofPoint origin,
                 ofPoint destination,
                 vector<ofPoint> path) {
        this->origin = origin;
        this->destination = destination;
        this->path = path;
    }
    ofPoint origin;
    ofPoint destination;
    vector<ofPoint> path;
};


class ofxChessBoard {
public:
    void addPiece(int r, int c, ofxChessPieceColor color, ofxChessPieceType type);
    ofxChessPiece * getPiece(int r, int c) {return pieces[r][c];}
    ofxChessPiece *pieces[8][8];
};


class ofxChessPiece {
public:
    ofxChessPiece(ofxChessPieceColor color, ofPoint position){
        this->color=color;
        this->position = position;
    }
    ofxChessPieceType getType() {return type;}
    ofxChessPieceColor getColor() {return color;}
    virtual void updateMoves() {
        possibleMoves.clear();
        eligibleMoves.clear();
    }
    bool checkPositionEligible(ofPoint pos) {
        // ineligible if position
        //   : off-board
        //   : path is blocked
        //   : occupied
        //   : leaves king in check
        
        if (board->getPiece(pos.x, pos.y) != NULL) {
            return false;
        }
        
        
    }
    
    void analyze();
protected:
    ofxChessPieceType type;
    ofxChessBoard *board;
    ofPoint position;
    ofxChessPieceColor color;
    vector<ofxChessMove> possibleMoves;
    vector<ofxChessMove> eligibleMoves;
};



class ofxChessPawn : public ofxChessPiece {
public:
    ofxChessPawn(ofxChessPieceColor color, ofPoint position) : ofxChessPiece(color, position) {
        type = PAWN;
    }
    void updateMoves();
private:
};

class ofxChessBishop : public ofxChessPiece {
public:
    ofxChessBishop(ofxChessPieceColor color, ofPoint position) : ofxChessPiece(color, position) {
        type = BISHOP;
    }
    void updateMoves();
private:
};




class ofxChess {
public:
    void setup();
    void update();
    void draw();
private:

    ofxChessBoard board;
};

