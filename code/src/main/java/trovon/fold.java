/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trovon;

import java.util.LinkedList;

/**
 *
 * @author aayush.garg
 */
public class fold {

    String name;
    LinkedList<String> listLHS;
    LinkedList<String> listRHS;
    String strMapFoldnCommits;

    fold(String name, LinkedList<String> listLHS, LinkedList<String> listRHS, String strMapFoldnCommits) {
        this.name = name;

        this.listLHS = new LinkedList();
        for (String lhs : listLHS) {
            this.listLHS.add(lhs);
        }

        this.listRHS = new LinkedList();
        for (String rhs : listRHS) {
            this.listRHS.add(rhs);
        }

        this.strMapFoldnCommits = strMapFoldnCommits;
    }

    fold Append(fold argFold, LinkedList<String> listLHS, LinkedList<String> listRHS, String strMapFoldnCommits) {
        fold newFold = new fold(argFold.name, argFold.listLHS, argFold.listRHS, argFold.strMapFoldnCommits);
        for (String lhs : listLHS) {
            newFold.listLHS.add(lhs);
        }

        for (String rhs : listRHS) {
            newFold.listRHS.add(rhs);
        }

        newFold.strMapFoldnCommits += data._elementSymbolSeparator + strMapFoldnCommits;

        return newFold;
    }
}
