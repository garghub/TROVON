static enum V_1 F_1 ( const char * V_2 )\r\n{\r\nif ( ! strcmp ( V_2 , L_1 ) )\r\nreturn V_3 ;\r\nif ( ! strcmp ( V_2 , L_2 ) )\r\nreturn V_4 ;\r\nif ( ! strcmp ( V_2 , L_3 ) || ! strcmp ( V_2 , L_4 ) )\r\nreturn V_5 ;\r\nF_2 ( L_5 , V_2 ) ;\r\nreturn V_6 ;\r\n}\r\nstatic const char * F_3 ( const char * V_7 )\r\n{\r\nstruct V_8 * V_9 ;\r\nfor ( V_9 = V_8 ; V_9 ; V_9 = V_9 -> V_10 ) {\r\nif ( ! strcasecmp ( V_7 , V_9 -> V_7 ) )\r\nreturn V_9 -> V_11 ;\r\n}\r\nreturn NULL ;\r\n}\r\nstatic int F_4 ( void )\r\n{\r\nstruct V_12 V_13 = V_14 ;\r\nstruct V_15 V_16 ;\r\nconst char * V_17 [] = { L_6 , L_7 , NULL } ;\r\nint V_18 ;\r\nmemset ( & V_16 , 0 , sizeof( V_16 ) ) ;\r\nV_16 . V_19 = V_17 ;\r\nV_16 . V_20 = - 1 ;\r\nV_16 . V_21 = 1 ;\r\nif ( F_5 ( & V_16 ) ) {\r\nfprintf ( V_22 , L_8 ) ;\r\nreturn - 1 ;\r\n}\r\nF_6 ( & V_13 , V_16 . V_20 , 20 ) ;\r\nF_7 ( V_16 . V_20 ) ;\r\nF_8 ( & V_16 ) ;\r\nif ( F_9 ( V_13 . V_23 , L_6 ) ) {\r\nfprintf ( V_22 , L_9 ) ;\r\nF_10 ( & V_13 ) ;\r\nreturn - 1 ;\r\n}\r\nF_11 ( & V_13 , 0 , strlen ( L_6 ) ) ;\r\nV_18 = atoi ( V_13 . V_23 ) ;\r\nif ( V_18 < 22 ) {\r\nfprintf ( V_22 ,\r\nL_10 ,\r\nV_18 ) ;\r\nF_10 ( & V_13 ) ;\r\nreturn - 1 ;\r\n}\r\nF_10 ( & V_13 ) ;\r\nreturn 0 ;\r\n}\r\nstatic void F_12 ( const char * V_24 , const char * V_25 )\r\n{\r\nif ( ! F_4 () ) {\r\nstruct V_12 V_26 = V_14 ;\r\nif ( ! V_24 )\r\nV_24 = L_6 ;\r\nF_13 ( & V_26 , L_11 , V_25 ) ;\r\nF_14 ( V_24 , L_6 , L_12 , V_26 . V_23 , NULL ) ;\r\nF_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;\r\n}\r\n}\r\nstatic void F_16 ( const char * V_24 , const char * V_25 )\r\n{\r\nconst char * V_28 = getenv ( L_14 ) ;\r\nif ( V_28 && * V_28 ) {\r\nstruct V_12 V_26 = V_14 ;\r\nconst char * V_29 = L_15 ;\r\nif ( V_24 ) {\r\nconst char * V_30 = strrchr ( V_24 , '/' ) ;\r\nif ( V_30 && ! strcmp ( V_30 + 1 , L_16 ) ) {\r\nchar * V_31 = F_17 ( V_24 ) ;\r\nchar * V_32 = strrchr ( V_31 , '/' ) ;\r\nstrcpy ( V_32 + 1 , L_15 ) ;\r\nV_24 = V_31 ;\r\n}\r\nif ( V_30 )\r\nV_29 = V_30 ;\r\n} else\r\nV_24 = L_15 ;\r\nF_13 ( & V_26 , L_17 , V_25 ) ;\r\nF_14 ( V_24 , V_29 , L_18 , V_26 . V_23 , NULL ) ;\r\nF_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;\r\n}\r\n}\r\nstatic void F_18 ( const char * V_24 , const char * V_25 )\r\n{\r\nif ( ! V_24 )\r\nV_24 = L_1 ;\r\nF_14 ( V_24 , L_1 , V_25 , NULL ) ;\r\nF_15 ( L_13 , V_24 , strerror ( V_27 ) ) ;\r\n}\r\nstatic void F_19 ( const char * V_33 , const char * V_25 )\r\n{\r\nstruct V_12 V_34 = V_14 ;\r\nF_13 ( & V_34 , L_19 , V_33 , V_25 ) ;\r\nF_20 ( L_20 , L_21 , L_22 , V_34 . V_23 , NULL ) ;\r\nF_15 ( L_13 , V_33 , strerror ( V_27 ) ) ;\r\n}\r\nstatic void F_21 ( const char * V_7 )\r\n{\r\nstruct V_35 * * V_36 = & V_35 ;\r\nT_1 V_37 = strlen ( V_7 ) ;\r\nwhile ( * V_36 )\r\nV_36 = & ( ( * V_36 ) -> V_10 ) ;\r\n* V_36 = F_22 ( sizeof( * * V_36 ) + V_37 + 1 ) ;\r\nstrncpy ( ( * V_36 ) -> V_7 , V_7 , V_37 ) ;\r\n}\r\nstatic int F_23 ( const char * V_7 , T_1 V_37 )\r\n{\r\nreturn ( ! strncasecmp ( L_1 , V_7 , V_37 ) ||\r\n! strncasecmp ( L_23 , V_7 , V_37 ) ||\r\n! strncasecmp ( L_16 , V_7 , V_37 ) ) ;\r\n}\r\nstatic void F_24 ( const char * V_7 ,\r\nT_1 V_37 ,\r\nconst char * V_38 )\r\n{\r\nstruct V_8 * V_31 = F_22 ( sizeof( * V_31 ) + V_37 + 1 ) ;\r\nstrncpy ( V_31 -> V_7 , V_7 , V_37 ) ;\r\nV_31 -> V_11 = F_17 ( V_38 ) ;\r\nV_31 -> V_10 = V_8 ;\r\nV_8 = V_31 ;\r\n}\r\nstatic int F_25 ( const char * V_7 ,\r\nT_1 V_37 ,\r\nconst char * V_38 )\r\n{\r\nif ( F_23 ( V_7 , V_37 ) )\r\nF_24 ( V_7 , V_37 , V_38 ) ;\r\nelse\r\nF_15 ( L_24\r\nL_25 ,\r\nV_7 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_26 ( const char * V_7 ,\r\nT_1 V_37 ,\r\nconst char * V_38 )\r\n{\r\nif ( F_23 ( V_7 , V_37 ) )\r\nF_15 ( L_26\r\nL_27 ,\r\nV_7 ) ;\r\nelse\r\nF_24 ( V_7 , V_37 , V_38 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_27 ( const char * V_39 , const char * V_38 )\r\n{\r\nconst char * V_7 = V_39 + 4 ;\r\nconst char * V_40 = strrchr ( V_7 , '.' ) ;\r\nif ( ! V_40 )\r\nreturn error ( L_28 , V_7 ) ;\r\nif ( ! strcmp ( V_40 , L_29 ) ) {\r\nif ( ! V_38 )\r\nreturn F_28 ( V_39 ) ;\r\nreturn F_25 ( V_7 , V_40 - V_7 , V_38 ) ;\r\n}\r\nif ( ! strcmp ( V_40 , L_30 ) ) {\r\nif ( ! V_38 )\r\nreturn F_28 ( V_39 ) ;\r\nreturn F_26 ( V_7 , V_40 - V_7 , V_38 ) ;\r\n}\r\nF_15 ( L_31 , V_40 ) ;\r\nreturn 0 ;\r\n}\r\nstatic int F_29 ( const char * V_39 , const char * V_38 , void * V_41 )\r\n{\r\nenum V_1 * V_42 = V_41 ;\r\nif ( ! strcmp ( V_39 , L_32 ) ) {\r\nif ( ! V_38 )\r\nreturn F_28 ( V_39 ) ;\r\n* V_42 = F_1 ( V_38 ) ;\r\nif ( * V_42 == V_6 )\r\nreturn - 1 ;\r\nreturn 0 ;\r\n}\r\nif ( ! strcmp ( V_39 , L_33 ) ) {\r\nif ( ! V_38 )\r\nreturn F_28 ( V_39 ) ;\r\nF_21 ( V_38 ) ;\r\nreturn 0 ;\r\n}\r\nif ( ! F_9 ( V_39 , L_34 ) )\r\nreturn F_27 ( V_39 , V_38 ) ;\r\nreturn F_30 ( V_39 , V_38 , V_41 ) ;\r\n}\r\nvoid F_31 ( void )\r\n{\r\nunsigned int V_43 , V_44 = 0 ;\r\nfor ( V_43 = 0 ; V_43 < F_32 ( V_45 ) ; V_43 ++ ) {\r\nif ( V_44 < strlen ( V_45 [ V_43 ] . V_7 ) )\r\nV_44 = strlen ( V_45 [ V_43 ] . V_7 ) ;\r\n}\r\nputs ( L_35 ) ;\r\nfor ( V_43 = 0 ; V_43 < F_32 ( V_45 ) ; V_43 ++ ) {\r\nprintf ( L_36 , V_44 , V_45 [ V_43 ] . V_7 ) ;\r\nputs ( V_45 [ V_43 ] . V_46 ) ;\r\n}\r\n}\r\nstatic int F_33 ( const char * V_47 )\r\n{\r\nreturn F_34 ( & V_48 , V_47 ) ||\r\nF_34 ( & V_49 , V_47 ) ;\r\n}\r\nstatic const char * F_35 ( const char * V_50 , const char * V_33 )\r\n{\r\nT_1 V_51 = strlen ( V_50 ) ;\r\nT_1 V_52 = strlen ( V_33 ) ;\r\nchar * V_36 = malloc ( V_51 + V_52 + 1 ) ;\r\nmemcpy ( V_36 , V_50 , V_51 ) ;\r\nstrcpy ( V_36 + V_51 , V_33 ) ;\r\nreturn V_36 ;\r\n}\r\nstatic const char * F_36 ( const char * V_53 )\r\n{\r\nif ( ! V_53 )\r\nreturn L_37 ;\r\nelse if ( ! F_9 ( V_53 , L_37 ) )\r\nreturn V_53 ;\r\nelse\r\nreturn F_35 ( L_38 , V_53 ) ;\r\n}\r\nstatic void F_37 ( void )\r\n{\r\nstruct V_12 V_54 = V_14 ;\r\nconst char * V_55 = getenv ( L_39 ) ;\r\nF_38 ( & V_54 , F_39 ( V_56 ) ) ;\r\nF_40 ( & V_54 , ':' ) ;\r\nif ( V_55 )\r\nF_38 ( & V_54 , V_55 ) ;\r\nF_41 ( L_39 , V_54 . V_23 , 1 ) ;\r\nF_10 ( & V_54 ) ;\r\n}\r\nstatic void F_42 ( const char * V_7 , const char * V_25 )\r\n{\r\nconst char * V_11 = F_3 ( V_7 ) ;\r\nif ( ! strcasecmp ( V_7 , L_1 ) )\r\nF_18 ( V_11 , V_25 ) ;\r\nelse if ( ! strcasecmp ( V_7 , L_23 ) )\r\nF_12 ( V_11 , V_25 ) ;\r\nelse if ( ! strcasecmp ( V_7 , L_16 ) )\r\nF_16 ( V_11 , V_25 ) ;\r\nelse if ( V_11 )\r\nF_19 ( V_11 , V_25 ) ;\r\nelse\r\nF_15 ( L_40 , V_7 ) ;\r\n}\r\nstatic int F_43 ( const char * V_53 )\r\n{\r\nstruct V_35 * V_9 ;\r\nconst char * V_25 = F_36 ( V_53 ) ;\r\nconst char * V_57 = getenv ( L_41 ) ;\r\nF_37 () ;\r\nfor ( V_9 = V_35 ; V_9 ; V_9 = V_9 -> V_10 )\r\nF_42 ( V_9 -> V_7 , V_25 ) ;\r\nif ( V_57 )\r\nF_42 ( V_57 , V_25 ) ;\r\nF_42 ( L_1 , V_25 ) ;\r\nF_2 ( L_42 ) ;\r\nreturn - 1 ;\r\n}\r\nstatic int F_44 ( const char * V_53 )\r\n{\r\nconst char * V_25 = F_36 ( V_53 ) ;\r\nF_41 ( L_43 , F_39 ( V_58 ) , 1 ) ;\r\nF_14 ( L_2 , L_2 , L_44 , V_25 , NULL ) ;\r\nreturn - 1 ;\r\n}\r\nstatic int F_45 ( struct V_12 * V_59 , const char * V_25 )\r\n{\r\nstruct V_60 V_61 ;\r\nconst char * V_62 = F_39 ( V_63 ) ;\r\nif ( V_60 ( F_46 ( L_45 , V_62 ) , & V_61 )\r\n|| ! F_47 ( V_61 . V_64 ) ) {\r\nF_2 ( L_46 , V_62 ) ;\r\nreturn - 1 ;\r\n}\r\nF_48 ( V_59 , 0 ) ;\r\nF_13 ( V_59 , L_47 , V_62 , V_25 ) ;\r\nreturn 0 ;\r\n}\r\nstatic void F_49 ( const char * V_24 )\r\n{\r\nF_50 ( L_48 , L_22 , L_49 , V_24 , NULL ) ;\r\n}\r\nstatic int F_51 ( const char * V_53 )\r\n{\r\nconst char * V_25 = F_36 ( V_53 ) ;\r\nstruct V_12 V_59 ;\r\nif ( F_45 ( & V_59 , V_25 ) != 0 )\r\nreturn - 1 ;\r\nF_49 ( V_59 . V_23 ) ;\r\nreturn 0 ;\r\n}\r\nint F_52 ( int V_65 , const char * * V_19 , const char * V_50 V_66 )\r\n{\r\nbool V_67 = false ;\r\nenum V_1 V_1 = V_3 ;\r\nstruct V_68 V_69 [] = {\r\nF_53 ( 'a' , L_50 , & V_67 , L_51 ) ,\r\nF_54 ( 'm' , L_1 , & V_1 , L_52 , V_3 ) ,\r\nF_54 ( 'w' , L_3 , & V_1 , L_53 ,\r\nV_5 ) ,\r\nF_54 ( 'i' , L_2 , & V_1 , L_54 ,\r\nV_4 ) ,\r\nF_55 () ,\r\n} ;\r\nconst char * const V_70 [] = {\r\nL_55 ,\r\nNULL\r\n} ;\r\nconst char * V_71 ;\r\nint V_72 = 0 ;\r\nF_56 ( L_38 , & V_48 , & V_49 ) ;\r\nF_57 ( F_29 , & V_1 ) ;\r\nV_65 = F_58 ( V_65 , V_19 , V_69 ,\r\nV_70 , 0 ) ;\r\nif ( V_67 ) {\r\nprintf ( L_56 , V_73 ) ;\r\nF_59 ( L_57 , & V_48 , & V_49 ) ;\r\nprintf ( L_58 , V_74 ) ;\r\nreturn 0 ;\r\n}\r\nif ( ! V_19 [ 0 ] ) {\r\nprintf ( L_56 , V_73 ) ;\r\nF_31 () ;\r\nprintf ( L_59 , V_74 ) ;\r\nreturn 0 ;\r\n}\r\nV_71 = F_60 ( V_19 [ 0 ] ) ;\r\nif ( V_71 && ! F_33 ( V_19 [ 0 ] ) ) {\r\nprintf ( L_60 , V_19 [ 0 ] , V_71 ) ;\r\nreturn 0 ;\r\n}\r\nswitch ( V_1 ) {\r\ncase V_3 :\r\nV_72 = F_43 ( V_19 [ 0 ] ) ;\r\nbreak;\r\ncase V_4 :\r\nV_72 = F_44 ( V_19 [ 0 ] ) ;\r\nbreak;\r\ncase V_5 :\r\nV_72 = F_51 ( V_19 [ 0 ] ) ;\r\nbreak;\r\ncase V_6 :\r\ndefault:\r\nV_72 = - 1 ;\r\nbreak;\r\n}\r\nreturn V_72 ;\r\n}
