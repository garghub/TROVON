static void * F_1 ( struct V_1 * V_2 , void * V_3 ,\r\nint V_4 )\r\n{\r\nstruct V_5 * V_5 = V_3 ;\r\nstruct V_6 * V_7 ;\r\nint V_8 = V_2 -> V_9 ;\r\nint V_10 , V_11 ;\r\nif ( V_5 ) {\r\nif ( V_4 < sizeof( * V_5 ) ) {\r\nV_10 = - V_12 ;\r\ngoto V_13;\r\n}\r\nV_8 = F_2 ( V_5 -> V_14 ) ;\r\nV_11 = F_3 ( V_8 ) - 1 ;\r\nif ( V_8 != ( 1 << V_11 ) && V_8 != ( 1 << V_11 ) +\r\n( 1 << ( V_11 + 1 ) ) ) {\r\nV_10 = - V_12 ;\r\ngoto V_13;\r\n}\r\n}\r\nV_8 = F_4 ( int , V_8 , V_15 ) ;\r\nV_7 = F_5 ( sizeof( * V_7 ) , V_16 ) ;\r\nif ( V_7 == NULL ) {\r\nV_10 = - V_17 ;\r\ngoto V_13;\r\n}\r\nV_7 -> V_18 = F_6 ( V_19 , V_8 ) ;\r\nif ( V_7 -> V_18 == NULL ) {\r\nF_7 ( V_7 ) ;\r\nV_10 = - V_17 ;\r\ngoto V_13;\r\n}\r\nreturn V_7 ;\r\nV_13:\r\nERROR ( L_1 ) ;\r\nreturn F_8 ( V_10 ) ;\r\n}\r\nstatic void F_9 ( void * V_20 )\r\n{\r\nstruct V_6 * V_7 = V_20 ;\r\nif ( V_7 ) {\r\nF_10 ( V_7 -> V_18 ) ;\r\nF_7 ( V_7 ) ;\r\n}\r\n}\r\nstatic int F_11 ( struct V_1 * V_2 , void * * V_21 ,\r\nstruct V_22 * * V_23 , int V_24 , int V_25 , int V_26 , int V_27 ,\r\nint V_28 )\r\n{\r\nenum V_29 V_30 ;\r\nint V_31 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;\r\nstruct V_6 * V_7 = V_2 -> V_7 ;\r\nF_12 ( & V_2 -> V_35 ) ;\r\nF_13 ( V_7 -> V_18 ) ;\r\nV_7 -> V_36 . V_37 = 0 ;\r\nV_7 -> V_36 . V_38 = 0 ;\r\nV_7 -> V_36 . V_39 = 0 ;\r\nV_7 -> V_36 . V_40 = V_41 ;\r\nV_7 -> V_36 . V_42 = V_21 [ V_34 ++ ] ;\r\ndo {\r\nif ( V_7 -> V_36 . V_37 == V_7 -> V_36 . V_38 && V_33 < V_24 ) {\r\nV_31 = F_14 ( V_26 , V_2 -> V_43 - V_25 ) ;\r\nV_26 -= V_31 ;\r\nF_15 ( V_23 [ V_33 ] ) ;\r\nif ( ! F_16 ( V_23 [ V_33 ] ) )\r\ngoto V_44;\r\nV_7 -> V_36 . V_45 = V_23 [ V_33 ] -> V_46 + V_25 ;\r\nV_7 -> V_36 . V_38 = V_31 ;\r\nV_7 -> V_36 . V_37 = 0 ;\r\nV_25 = 0 ;\r\n}\r\nif ( V_7 -> V_36 . V_39 == V_7 -> V_36 . V_40\r\n&& V_34 < V_28 ) {\r\nV_7 -> V_36 . V_42 = V_21 [ V_34 ++ ] ;\r\nV_7 -> V_36 . V_39 = 0 ;\r\nV_32 += V_41 ;\r\n}\r\nV_30 = F_17 ( V_7 -> V_18 , & V_7 -> V_36 ) ;\r\nif ( V_7 -> V_36 . V_37 == V_7 -> V_36 . V_38 && V_33 < V_24 )\r\nF_18 ( V_23 [ V_33 ++ ] ) ;\r\n} while ( V_30 == V_47 );\r\nif ( V_30 != V_48 ) {\r\nERROR ( L_2 ) ;\r\ngoto V_44;\r\n}\r\nif ( V_33 < V_24 ) {\r\nERROR ( L_3 ) ;\r\ngoto V_44;\r\n}\r\nV_32 += V_7 -> V_36 . V_39 ;\r\nF_19 ( & V_2 -> V_35 ) ;\r\nreturn V_32 ;\r\nV_44:\r\nF_19 ( & V_2 -> V_35 ) ;\r\nfor (; V_33 < V_24 ; V_33 ++ )\r\nF_18 ( V_23 [ V_33 ] ) ;\r\nreturn - V_12 ;\r\n}
