static int F_1 ( int V_1 )\r\n{\r\nint V_2 = 0 ;\r\nif ( V_1 & V_3 )\r\nV_2 |= V_4 ;\r\nif ( V_1 & V_5 )\r\nV_2 |= V_6 ;\r\nif ( V_1 & V_7 )\r\nV_2 |= V_8 ;\r\nif ( V_1 & V_9 )\r\nV_2 |= V_10 ;\r\nif ( V_1 & V_11 )\r\nV_2 |= V_12 ;\r\nif ( V_1 & V_13 )\r\nV_2 |= V_14 ;\r\nif ( V_1 & V_15 )\r\nV_2 |= V_16 ;\r\nreturn V_2 ;\r\n}\r\nstatic int F_2 ( int V_17 )\r\n{\r\nint V_2 = 0 ;\r\nif ( V_17 & V_18 )\r\nV_2 |= V_19 ;\r\nif ( V_17 & V_20 )\r\nV_2 |= V_21 ;\r\nreturn V_2 ;\r\n}\r\nstatic int F_3 ( struct V_22 * V_23 )\r\n{\r\nreturn V_24 | F_1 ( V_23 -> V_1 ) |\r\nF_2 ( V_23 -> V_25 -> V_17 ) ;\r\n}\r\nstatic int F_4 ( struct V_26 * V_26 , struct V_27 * V_28 )\r\n{\r\nint V_29 ;\r\nif ( ! V_26 -> V_30 -> V_31 -> V_32 )\r\nreturn - V_33 ;\r\nmemset ( V_28 , 0 , sizeof( * V_28 ) ) ;\r\nV_29 = F_5 ( V_26 ) ;\r\nif ( V_29 )\r\nreturn V_29 ;\r\nV_29 = V_26 -> V_30 -> V_31 -> V_32 ( V_26 , V_28 ) ;\r\nif ( V_29 == 0 && V_28 -> V_34 == 0 )\r\nV_28 -> V_34 = V_28 -> V_35 ;\r\nreturn V_29 ;\r\n}\r\nint F_6 ( struct V_36 * V_36 , struct V_27 * V_28 )\r\n{\r\nint error ;\r\nerror = F_4 ( V_36 -> V_26 , V_28 ) ;\r\nif ( ! error )\r\nV_28 -> V_37 = F_3 ( V_36 -> V_23 ) ;\r\nreturn error ;\r\n}\r\nint F_7 ( const char T_1 * V_38 , struct V_27 * V_39 )\r\n{\r\nstruct V_36 V_36 ;\r\nint error ;\r\nunsigned int V_40 = V_41 | V_42 ;\r\nV_43:\r\nerror = F_8 ( V_44 , V_38 , V_40 , & V_36 ) ;\r\nif ( ! error ) {\r\nerror = F_6 ( & V_36 , V_39 ) ;\r\nF_9 ( & V_36 ) ;\r\nif ( F_10 ( error , V_40 ) ) {\r\nV_40 |= V_45 ;\r\ngoto V_43;\r\n}\r\n}\r\nreturn error ;\r\n}\r\nint F_11 ( int V_46 , struct V_27 * V_39 )\r\n{\r\nstruct V_46 V_47 = F_12 ( V_46 ) ;\r\nint error = - V_48 ;\r\nif ( V_47 . V_49 ) {\r\nerror = F_6 ( & V_47 . V_49 -> V_50 , V_39 ) ;\r\nF_13 ( V_47 ) ;\r\n}\r\nreturn error ;\r\n}\r\nstatic int F_14 ( struct V_27 * V_39 , struct V_32 T_1 * V_51 )\r\n{\r\nstruct V_32 V_28 ;\r\nif ( sizeof( V_28 ) == sizeof( * V_39 ) )\r\nmemcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;\r\nelse {\r\nif ( sizeof V_28 . V_52 == 4 ) {\r\nif ( ( V_39 -> V_52 | V_39 -> V_53 | V_39 -> V_54 |\r\nV_39 -> V_35 | V_39 -> V_34 ) &\r\n0xffffffff00000000ULL )\r\nreturn - V_55 ;\r\nif ( V_39 -> V_56 != - 1 &&\r\n( V_39 -> V_56 & 0xffffffff00000000ULL ) )\r\nreturn - V_55 ;\r\nif ( V_39 -> V_57 != - 1 &&\r\n( V_39 -> V_57 & 0xffffffff00000000ULL ) )\r\nreturn - V_55 ;\r\n}\r\nV_28 . V_58 = V_39 -> V_58 ;\r\nV_28 . V_35 = V_39 -> V_35 ;\r\nV_28 . V_52 = V_39 -> V_52 ;\r\nV_28 . V_53 = V_39 -> V_53 ;\r\nV_28 . V_54 = V_39 -> V_54 ;\r\nV_28 . V_56 = V_39 -> V_56 ;\r\nV_28 . V_57 = V_39 -> V_57 ;\r\nV_28 . V_59 = V_39 -> V_59 ;\r\nV_28 . V_60 = V_39 -> V_60 ;\r\nV_28 . V_34 = V_39 -> V_34 ;\r\nV_28 . V_37 = V_39 -> V_37 ;\r\nmemset ( V_28 . V_61 , 0 , sizeof( V_28 . V_61 ) ) ;\r\n}\r\nif ( F_15 ( V_51 , & V_28 , sizeof( V_28 ) ) )\r\nreturn - V_62 ;\r\nreturn 0 ;\r\n}\r\nstatic int F_16 ( struct V_27 * V_39 , struct V_63 T_1 * V_51 )\r\n{\r\nstruct V_63 V_28 ;\r\nif ( sizeof( V_28 ) == sizeof( * V_39 ) )\r\nmemcpy ( & V_28 , V_39 , sizeof( * V_39 ) ) ;\r\nelse {\r\nV_28 . V_58 = V_39 -> V_58 ;\r\nV_28 . V_35 = V_39 -> V_35 ;\r\nV_28 . V_52 = V_39 -> V_52 ;\r\nV_28 . V_53 = V_39 -> V_53 ;\r\nV_28 . V_54 = V_39 -> V_54 ;\r\nV_28 . V_56 = V_39 -> V_56 ;\r\nV_28 . V_57 = V_39 -> V_57 ;\r\nV_28 . V_59 = V_39 -> V_59 ;\r\nV_28 . V_60 = V_39 -> V_60 ;\r\nV_28 . V_34 = V_39 -> V_34 ;\r\nV_28 . V_37 = V_39 -> V_37 ;\r\nmemset ( V_28 . V_61 , 0 , sizeof( V_28 . V_61 ) ) ;\r\n}\r\nif ( F_15 ( V_51 , & V_28 , sizeof( V_28 ) ) )\r\nreturn - V_62 ;\r\nreturn 0 ;\r\n}\r\nint F_17 ( T_2 V_64 , struct V_27 * V_65 )\r\n{\r\nstruct V_66 * V_67 = F_18 ( V_64 ) ;\r\nint V_68 ;\r\nif ( ! V_67 )\r\nreturn - V_69 ;\r\nV_68 = F_4 ( V_67 -> V_70 , V_65 ) ;\r\nF_19 ( V_67 ) ;\r\nreturn V_68 ;\r\n}
