static inline int F_1 ( struct V_1 * V_1 ,\r\nunsigned long V_2 , int V_3 )\r\n{\r\nstruct V_4 * V_5 = F_2 ( V_1 ) ;\r\nif ( V_5 == NULL )\r\nreturn 0 ;\r\nif ( ! V_3 ) {\r\nif ( ! V_2 || F_3 ( V_5 -> V_6 + V_2 , V_7 ) )\r\nreturn 0 ;\r\nV_5 -> V_6 = V_7 ;\r\n}\r\nreturn 1 ;\r\n}\r\nstatic int F_4 ( struct V_8 * V_9 , struct V_1 * V_1 )\r\n{\r\nstruct V_1 * V_10 = V_1 ;\r\nstruct V_11 V_11 = { . V_9 = V_9 , . V_1 = V_1 } ;\r\nint V_12 = 1 ;\r\nF_5 ( L_1 ,\r\nV_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;\r\nF_6 ( & V_11 ) ;\r\nif ( ! F_7 ( & V_11 ) )\r\ngoto V_16;\r\nif ( F_8 ( V_11 . V_1 ) ) {\r\nstruct V_17 * V_18 = F_9 ( V_11 . V_1 -> V_19 ) ;\r\nif ( F_10 ( V_18 -> type ) )\r\ngoto V_16;\r\nif ( ! F_11 ( V_11 . V_1 ) ) {\r\nV_12 = 0 ;\r\ngoto V_16;\r\n}\r\n}\r\nif ( ! F_12 ( V_11 . V_9 ) ) {\r\nstruct V_4 * V_5 = F_2 ( V_10 ) ;\r\nV_5 -> V_6 = V_20 ;\r\ngoto V_16;\r\n}\r\nV_12 = 0 ;\r\nV_16:\r\nF_5 ( L_2 , V_12 ) ;\r\nF_13 ( & V_11 ) ;\r\nreturn V_12 ;\r\n}\r\nstatic struct V_1 * F_14 ( struct V_1 * V_21 ,\r\nstruct V_1 * V_22 )\r\n{\r\nstruct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;\r\nstruct V_23 * V_24 ;\r\nstruct V_1 * V_25 ;\r\nF_15 ( & V_18 -> V_26 ) ;\r\nF_15 ( & V_22 -> V_27 ) ;\r\nif ( V_21 )\r\nV_24 = V_21 -> V_28 . V_29 . V_24 ;\r\nelse {\r\nV_21 = F_16 ( V_22 ) ;\r\nV_24 = V_21 -> V_30 . V_24 ;\r\n}\r\nV_31:\r\nif ( V_24 == & V_22 -> V_30 ) {\r\nF_17 ( & V_22 -> V_27 ) ;\r\nF_17 ( & V_18 -> V_26 ) ;\r\nF_18 ( V_21 ) ;\r\nreturn NULL ;\r\n}\r\nV_25 = F_19 ( V_24 , struct V_1 , V_28 . V_29 ) ;\r\nF_20 ( & V_25 -> V_27 , V_32 ) ;\r\nif ( V_25 -> V_33 == 0 || ! F_21 ( V_25 ) ) {\r\nF_17 ( & V_25 -> V_27 ) ;\r\nV_24 = V_25 -> V_28 . V_29 . V_24 ;\r\ngoto V_31;\r\n}\r\nF_16 ( V_25 ) ;\r\nF_17 ( & V_25 -> V_27 ) ;\r\nF_17 ( & V_22 -> V_27 ) ;\r\nF_17 ( & V_18 -> V_26 ) ;\r\nF_18 ( V_21 ) ;\r\nreturn V_25 ;\r\n}\r\nstatic struct V_1 * F_22 ( struct V_1 * V_21 ,\r\nstruct V_1 * V_22 )\r\n{\r\nstruct V_17 * V_18 = F_9 ( V_22 -> V_19 ) ;\r\nstruct V_23 * V_24 ;\r\nstruct V_1 * V_34 , * V_35 ;\r\nif ( V_21 == NULL )\r\nreturn F_23 ( V_22 ) ;\r\nF_15 ( & V_18 -> V_26 ) ;\r\nV_36:\r\nV_34 = V_21 ;\r\nF_15 ( & V_34 -> V_27 ) ;\r\nV_37:\r\nV_24 = V_34 -> V_30 . V_24 ;\r\nif ( V_24 == & V_34 -> V_30 ) {\r\nwhile ( 1 ) {\r\nstruct V_1 * V_38 ;\r\nif ( V_34 == V_22 ) {\r\nF_17 ( & V_34 -> V_27 ) ;\r\nF_17 ( & V_18 -> V_26 ) ;\r\nF_18 ( V_21 ) ;\r\nreturn NULL ;\r\n}\r\nV_38 = V_34 -> V_39 ;\r\nif ( ! F_24 ( & V_38 -> V_27 ) ) {\r\nF_17 ( & V_34 -> V_27 ) ;\r\nF_25 () ;\r\ngoto V_36;\r\n}\r\nF_17 ( & V_34 -> V_27 ) ;\r\nV_24 = V_34 -> V_28 . V_29 . V_24 ;\r\nV_34 = V_38 ;\r\nif ( V_24 != & V_38 -> V_30 )\r\nbreak;\r\n}\r\n}\r\nV_35 = F_19 ( V_24 , struct V_1 , V_28 . V_29 ) ;\r\nF_20 ( & V_35 -> V_27 , V_32 ) ;\r\nif ( ! F_21 ( V_35 ) ) {\r\nF_17 ( & V_34 -> V_27 ) ;\r\nF_26 ( & V_35 -> V_27 . V_40 , 0 , V_41 ) ;\r\nV_34 = V_35 ;\r\ngoto V_37;\r\n}\r\nF_16 ( V_35 ) ;\r\nF_17 ( & V_35 -> V_27 ) ;\r\nF_17 ( & V_34 -> V_27 ) ;\r\nF_17 ( & V_18 -> V_26 ) ;\r\nF_18 ( V_21 ) ;\r\nreturn V_35 ;\r\n}\r\nstatic int F_27 ( struct V_8 * V_9 ,\r\nstruct V_1 * V_10 ,\r\nunsigned long V_2 ,\r\nint V_3 )\r\n{\r\nF_5 ( L_3 ,\r\nV_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;\r\nif ( ! F_12 ( V_9 ) ) {\r\nstruct V_4 * V_5 = F_2 ( V_10 ) ;\r\nif ( V_5 )\r\nV_5 -> V_6 = V_20 ;\r\nreturn 1 ;\r\n}\r\nif ( ! F_1 ( V_10 , V_2 , V_3 ) )\r\nreturn 1 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_28 ( struct V_8 * V_9 ,\r\nstruct V_1 * V_10 ,\r\nunsigned long V_2 ,\r\nint V_3 )\r\n{\r\nstruct V_4 * V_42 = F_2 ( V_10 ) ;\r\nstruct V_1 * V_34 ;\r\nF_5 ( L_3 ,\r\nV_10 , ( int ) V_10 -> V_13 . V_14 , V_10 -> V_13 . V_15 ) ;\r\nif ( ! F_21 ( V_10 ) )\r\nreturn 1 ;\r\nV_34 = NULL ;\r\nwhile ( ( V_34 = F_22 ( V_34 , V_10 ) ) ) {\r\nF_5 ( L_1 ,\r\nV_34 , ( int ) V_34 -> V_13 . V_14 , V_34 -> V_13 . V_15 ) ;\r\nif ( F_11 ( V_34 ) ) {\r\nif ( F_4 ( V_9 , V_34 ) ) {\r\nV_42 -> V_6 = V_20 ;\r\nF_18 ( V_34 ) ;\r\nreturn 1 ;\r\n}\r\n} else {\r\nstruct V_4 * V_5 = F_2 ( V_34 ) ;\r\nunsigned int V_43 = F_29 ( & V_5 -> V_44 ) ;\r\nF_30 ( V_34 ) ;\r\nif ( V_34 == V_10 )\r\nV_43 += 2 ;\r\nelse\r\nV_43 ++ ;\r\nif ( V_34 -> V_33 > V_43 ) {\r\nV_42 -> V_6 = V_20 ;\r\nF_18 ( V_34 ) ;\r\nreturn 1 ;\r\n}\r\n}\r\n}\r\nif ( ! F_1 ( V_10 , V_2 , V_3 ) )\r\nreturn 1 ;\r\nreturn 0 ;\r\n}\r\nstatic struct V_1 * F_31 ( struct V_8 * V_9 ,\r\nstruct V_1 * V_38 ,\r\nunsigned long V_2 ,\r\nint V_3 )\r\n{\r\nstruct V_1 * V_34 ;\r\nF_5 ( L_4 ,\r\nV_38 , ( int ) V_38 -> V_13 . V_14 , V_38 -> V_13 . V_15 ) ;\r\nV_34 = NULL ;\r\nwhile ( ( V_34 = F_22 ( V_34 , V_38 ) ) ) {\r\nF_5 ( L_1 ,\r\nV_34 , ( int ) V_34 -> V_13 . V_14 , V_34 -> V_13 . V_15 ) ;\r\nif ( F_11 ( V_34 ) ) {\r\nif ( F_4 ( V_9 , V_34 ) )\r\ncontinue;\r\nif ( F_1 ( V_34 , V_2 , V_3 ) )\r\nreturn V_34 ;\r\n}\r\n}\r\nreturn NULL ;\r\n}\r\nstruct V_1 * F_32 ( struct V_45 * V_46 ,\r\nstruct V_8 * V_9 ,\r\nstruct V_17 * V_18 ,\r\nint V_47 )\r\n{\r\nunsigned long V_2 ;\r\nstruct V_1 * V_22 = F_23 ( V_46 -> V_48 ) ;\r\nint V_3 = V_47 & V_49 ;\r\nstruct V_4 * V_5 ;\r\nif ( ! V_22 )\r\nreturn NULL ;\r\nV_7 = V_20 ;\r\nV_2 = V_18 -> V_50 ;\r\nF_15 ( & V_18 -> V_51 ) ;\r\nV_5 = F_2 ( V_22 ) ;\r\nif ( V_5 -> V_52 & V_53 )\r\ngoto V_54;\r\nif ( ! F_27 ( V_9 , V_22 , V_2 , V_3 ) ) {\r\nstruct V_4 * V_5 = F_2 ( V_22 ) ;\r\nV_5 -> V_52 |= V_55 ;\r\nF_33 ( & V_5 -> V_56 ) ;\r\nF_17 ( & V_18 -> V_51 ) ;\r\nreturn V_22 ;\r\n}\r\nV_54:\r\nF_17 ( & V_18 -> V_51 ) ;\r\nF_18 ( V_22 ) ;\r\nreturn NULL ;\r\n}\r\nstruct V_1 * F_34 ( struct V_45 * V_46 ,\r\nstruct V_8 * V_9 ,\r\nstruct V_17 * V_18 ,\r\nint V_47 )\r\n{\r\nunsigned long V_2 ;\r\nstruct V_1 * V_22 = V_46 -> V_48 ;\r\nstruct V_1 * V_1 ;\r\nstruct V_1 * V_57 = NULL ;\r\nint V_3 = V_47 & V_49 ;\r\nint V_58 = V_47 & V_59 ;\r\nstruct V_4 * V_5 ;\r\nunsigned int V_43 ;\r\nif ( ! V_22 )\r\nreturn NULL ;\r\nV_7 = V_20 ;\r\nV_2 = V_18 -> V_50 ;\r\nV_1 = NULL ;\r\nwhile ( ( V_1 = F_14 ( V_1 , V_22 ) ) ) {\r\nF_15 ( & V_18 -> V_51 ) ;\r\nV_5 = F_2 ( V_1 ) ;\r\nif ( V_5 -> V_52 & V_53 )\r\ngoto V_24;\r\nif ( F_11 ( V_1 ) ) {\r\nF_5 ( L_5 ,\r\nV_1 , ( int ) V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;\r\nif ( F_4 ( V_9 , V_1 ) )\r\ngoto V_24;\r\nif ( F_1 ( V_1 , V_2 , V_3 ) ) {\r\nV_57 = V_1 ;\r\ngoto V_60;\r\n}\r\ngoto V_24;\r\n}\r\nif ( F_35 ( V_1 ) )\r\ngoto V_24;\r\nif ( ! V_58 ) {\r\nV_43 = F_29 ( & V_5 -> V_44 ) + 1 ;\r\nif ( V_1 -> V_33 > V_43 )\r\ngoto V_24;\r\nif ( ! F_28 ( V_9 , V_1 , V_2 , V_3 ) ) {\r\nV_57 = V_1 ;\r\ngoto V_60;\r\n}\r\n} else {\r\nV_43 = F_29 ( & V_5 -> V_44 ) + 1 ;\r\nif ( V_1 -> V_33 > V_43 )\r\ngoto V_24;\r\nV_57 = F_31 ( V_9 , V_1 , V_2 , V_3 ) ;\r\nif ( V_57 ) {\r\nF_18 ( V_1 ) ;\r\ngoto V_60;\r\n}\r\n}\r\nV_24:\r\nF_17 ( & V_18 -> V_51 ) ;\r\n}\r\nreturn NULL ;\r\nV_60:\r\nF_5 ( L_6 ,\r\nV_57 , ( int ) V_57 -> V_13 . V_14 , V_57 -> V_13 . V_15 ) ;\r\nV_5 = F_2 ( V_57 ) ;\r\nV_5 -> V_52 |= V_55 ;\r\nF_33 ( & V_5 -> V_56 ) ;\r\nF_17 ( & V_18 -> V_51 ) ;\r\nF_15 ( & V_18 -> V_26 ) ;\r\nF_15 ( & V_57 -> V_39 -> V_27 ) ;\r\nF_20 ( & V_57 -> V_27 , V_32 ) ;\r\nF_36 ( & V_57 -> V_39 -> V_30 , & V_57 -> V_28 . V_29 ) ;\r\nF_17 ( & V_57 -> V_27 ) ;\r\nF_17 ( & V_57 -> V_39 -> V_27 ) ;\r\nF_17 ( & V_18 -> V_26 ) ;\r\nreturn V_57 ;\r\n}\r\nint F_37 ( struct V_1 * V_1 )\r\n{\r\nstruct V_17 * V_18 = F_9 ( V_1 -> V_19 ) ;\r\nstruct V_4 * V_5 = F_2 ( V_1 ) ;\r\nint V_12 ;\r\nF_15 ( & V_18 -> V_51 ) ;\r\nif ( V_5 -> V_52 & V_55 ) {\r\nF_17 ( & V_18 -> V_51 ) ;\r\nF_5 ( L_7 ,\r\nV_1 , V_1 -> V_13 . V_14 , V_1 -> V_13 . V_15 ) ;\r\nV_12 = F_38 ( V_18 , V_1 , V_61 ) ;\r\nF_39 ( & V_5 -> V_56 ) ;\r\nF_5 ( L_8 , V_12 ) ;\r\nif ( F_40 ( V_1 ) )\r\nreturn - V_62 ;\r\nreturn V_12 ;\r\n}\r\nF_17 ( & V_18 -> V_51 ) ;\r\nreturn 0 ;\r\n}\r\nint F_41 ( struct V_45 * V_46 ,\r\nstruct V_8 * V_9 ,\r\nstruct V_17 * V_18 ,\r\nstruct V_63 T_1 * V_64 )\r\n{\r\nstruct V_63 V_65 ;\r\nstruct V_4 * V_5 ;\r\nstruct V_1 * V_1 ;\r\nint V_35 = 0 ;\r\nmemset ( & V_65 , 0 , sizeof V_65 ) ;\r\nV_65 . V_66 . V_67 = V_18 -> V_68 ;\r\nV_65 . V_66 . type = V_69 ;\r\nif ( ( V_1 = F_34 ( V_46 , V_9 , V_18 , 0 ) ) == NULL )\r\nreturn - V_62 ;\r\nV_65 . V_14 = V_1 -> V_13 . V_14 ;\r\nmemcpy ( V_65 . V_15 , V_1 -> V_13 . V_15 , V_65 . V_14 ) ;\r\nV_65 . V_15 [ V_65 . V_14 ] = '\0' ;\r\nF_18 ( V_1 ) ;\r\nif ( F_42 ( V_64 , & V_65 , sizeof( struct V_63 ) ) )\r\nV_35 = - V_70 ;\r\nF_15 ( & V_18 -> V_51 ) ;\r\nV_5 = F_2 ( V_1 ) ;\r\nV_5 -> V_52 &= ~ V_55 ;\r\nF_43 ( & V_5 -> V_56 ) ;\r\nF_17 ( & V_18 -> V_51 ) ;\r\nreturn V_35 ;\r\n}\r\nint F_44 ( struct V_45 * V_46 , struct V_8 * V_9 ,\r\nstruct V_17 * V_18 , int V_71 )\r\n{\r\nstruct V_1 * V_1 ;\r\nint V_35 = - V_62 ;\r\nif ( F_45 ( V_18 -> type ) )\r\nV_1 = F_32 ( V_46 , V_9 , V_18 , V_71 ) ;\r\nelse\r\nV_1 = F_34 ( V_46 , V_9 , V_18 , V_71 ) ;\r\nif ( V_1 ) {\r\nstruct V_4 * V_5 = F_2 ( V_1 ) ;\r\nV_35 = F_38 ( V_18 , V_1 , V_72 ) ;\r\nF_15 ( & V_18 -> V_51 ) ;\r\nV_5 -> V_52 &= ~ V_55 ;\r\nF_15 ( & V_1 -> V_27 ) ;\r\nif ( ! V_35 ) {\r\nif ( ( F_46 ( V_1 ) ||\r\n( F_10 ( V_18 -> type ) &&\r\nF_46 ( V_1 -> V_39 ) ) ) &&\r\n! ( V_1 -> V_73 & V_74 ) )\r\nF_47 ( V_1 ) ;\r\n}\r\nF_17 ( & V_1 -> V_27 ) ;\r\nF_43 ( & V_5 -> V_56 ) ;\r\nF_17 ( & V_18 -> V_51 ) ;\r\nF_18 ( V_1 ) ;\r\n}\r\nreturn V_35 ;\r\n}\r\nint F_48 ( struct V_45 * V_46 , struct V_8 * V_9 ,\r\nstruct V_17 * V_18 , int T_1 * V_75 )\r\n{\r\nint V_3 = 0 ;\r\nif ( V_75 && F_49 ( V_3 , V_75 ) )\r\nreturn - V_70 ;\r\nreturn F_44 ( V_46 , V_9 , V_18 , V_3 ) ;\r\n}
