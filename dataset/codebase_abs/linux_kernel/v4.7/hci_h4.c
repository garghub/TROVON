static int F_1 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 * V_4 ;\r\nF_2 ( L_1 , V_2 ) ;\r\nV_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;\r\nif ( ! V_4 )\r\nreturn - V_6 ;\r\nF_4 ( & V_4 -> V_7 ) ;\r\nV_2 -> V_8 = V_4 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_5 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 * V_4 = V_2 -> V_8 ;\r\nF_2 ( L_1 , V_2 ) ;\r\nF_6 ( & V_4 -> V_7 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_7 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 * V_4 = V_2 -> V_8 ;\r\nV_2 -> V_8 = NULL ;\r\nF_2 ( L_1 , V_2 ) ;\r\nF_6 ( & V_4 -> V_7 ) ;\r\nF_8 ( V_4 -> V_9 ) ;\r\nV_2 -> V_8 = NULL ;\r\nF_9 ( V_4 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )\r\n{\r\nstruct V_3 * V_4 = V_2 -> V_8 ;\r\nF_2 ( L_2 , V_2 , V_11 ) ;\r\nmemcpy ( F_11 ( V_11 , 1 ) , & F_12 ( V_11 ) , 1 ) ;\r\nF_13 ( & V_4 -> V_7 , V_11 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_14 ( struct V_1 * V_2 , const void * V_12 , int V_13 )\r\n{\r\nstruct V_3 * V_4 = V_2 -> V_8 ;\r\nif ( ! F_15 ( V_14 , & V_2 -> V_15 ) )\r\nreturn - V_16 ;\r\nV_4 -> V_9 = F_16 ( V_2 -> V_17 , V_4 -> V_9 , V_12 , V_13 ,\r\nV_18 , F_17 ( V_18 ) ) ;\r\nif ( F_18 ( V_4 -> V_9 ) ) {\r\nint V_19 = F_19 ( V_4 -> V_9 ) ;\r\nF_20 ( L_3 , V_2 -> V_17 -> V_20 , V_19 ) ;\r\nV_4 -> V_9 = NULL ;\r\nreturn V_19 ;\r\n}\r\nreturn V_13 ;\r\n}\r\nstatic struct V_10 * F_21 ( struct V_1 * V_2 )\r\n{\r\nstruct V_3 * V_4 = V_2 -> V_8 ;\r\nreturn F_22 ( & V_4 -> V_7 ) ;\r\n}\r\nint T_1 F_23 ( void )\r\n{\r\nreturn F_24 ( & V_21 ) ;\r\n}\r\nint T_2 F_25 ( void )\r\n{\r\nreturn F_26 ( & V_21 ) ;\r\n}\r\nstruct V_10 * F_16 ( struct V_22 * V_17 , struct V_10 * V_11 ,\r\nconst unsigned char * V_23 , int V_13 ,\r\nconst struct V_24 * V_25 , int V_26 )\r\n{\r\nwhile ( V_13 ) {\r\nint V_27 , V_28 ;\r\nif ( ! V_11 ) {\r\nfor ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {\r\nif ( V_23 [ 0 ] != ( & V_25 [ V_27 ] ) -> type )\r\ncontinue;\r\nV_11 = F_27 ( ( & V_25 [ V_27 ] ) -> V_29 ,\r\nV_30 ) ;\r\nif ( ! V_11 )\r\nreturn F_28 ( - V_6 ) ;\r\nF_12 ( V_11 ) = ( & V_25 [ V_27 ] ) -> type ;\r\nF_29 ( V_11 ) = ( & V_25 [ V_27 ] ) -> V_31 ;\r\nbreak;\r\n}\r\nif ( ! V_11 )\r\nreturn F_28 ( - V_32 ) ;\r\nV_13 -= 1 ;\r\nV_23 += 1 ;\r\n}\r\nV_28 = F_30 ( V_33 , F_29 ( V_11 ) - V_11 -> V_28 , V_13 ) ;\r\nmemcpy ( F_31 ( V_11 , V_28 ) , V_23 , V_28 ) ;\r\nV_13 -= V_28 ;\r\nV_23 += V_28 ;\r\nif ( V_11 -> V_28 < F_29 ( V_11 ) )\r\ncontinue;\r\nfor ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {\r\nif ( F_12 ( V_11 ) == ( & V_25 [ V_27 ] ) -> type )\r\nbreak;\r\n}\r\nif ( V_27 >= V_26 ) {\r\nF_8 ( V_11 ) ;\r\nreturn F_28 ( - V_32 ) ;\r\n}\r\nif ( V_11 -> V_28 == ( & V_25 [ V_27 ] ) -> V_31 ) {\r\nT_3 V_34 ;\r\nswitch ( ( & V_25 [ V_27 ] ) -> V_35 ) {\r\ncase 0 :\r\nV_34 = 0 ;\r\nbreak;\r\ncase 1 :\r\nV_34 = V_11 -> V_12 [ ( & V_25 [ V_27 ] ) -> V_36 ] ;\r\nF_29 ( V_11 ) += V_34 ;\r\nif ( F_32 ( V_11 ) < V_34 ) {\r\nF_8 ( V_11 ) ;\r\nreturn F_28 ( - V_37 ) ;\r\n}\r\nbreak;\r\ncase 2 :\r\nV_34 = F_33 ( V_11 -> V_12 +\r\n( & V_25 [ V_27 ] ) -> V_36 ) ;\r\nF_29 ( V_11 ) += V_34 ;\r\nif ( F_32 ( V_11 ) < V_34 ) {\r\nF_8 ( V_11 ) ;\r\nreturn F_28 ( - V_37 ) ;\r\n}\r\nbreak;\r\ndefault:\r\nF_8 ( V_11 ) ;\r\nreturn F_28 ( - V_32 ) ;\r\n}\r\nif ( ! V_34 ) {\r\n( & V_25 [ V_27 ] ) -> V_38 ( V_17 , V_11 ) ;\r\nV_11 = NULL ;\r\n}\r\n} else {\r\n( & V_25 [ V_27 ] ) -> V_38 ( V_17 , V_11 ) ;\r\nV_11 = NULL ;\r\n}\r\n}\r\nreturn V_11 ;\r\n}
