int F_1 ( char * * V_1 , int Remove )
{
struct V_2 * V_3 , * V_4 , * line , * V_5 ;
int V_6 ;
char * V_7 = NULL , * V_8 = NULL ;
int V_9 = 0 ;
V_3 = & V_10 ;
V_4 = line = V_5 = NULL ;
while ( V_3 -> V_11 != NULL ) {
V_3 = V_3 -> V_11 ;
}
while ( ( V_6 = F_2 ( V_1 , V_3 ) ) != V_12 ) {
if ( V_6 == 0 ) {
F_3 ( L_1 ) ;
return ( - 1 ) ;
}
}
for (; ; ) {
V_6 = F_2 ( V_1 , V_3 ) ;
if ( V_6 == 0 ) {
F_3 ( L_1 ) ;
return ( - 1 ) ;
}
switch ( V_6 ) {
case 0 :
F_3 ( L_2 ) ;
return ( - 1 ) ;
case V_12 :
F_3 ( L_3 ) ;
return ( - 1 ) ;
case V_13 :
return ( 0 ) ;
case V_14 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_15 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_3 -> V_16 . V_17 . V_18 = F_6 ( L_5 ) ;
line = V_5 = NULL ;
V_4 = V_3 ;
V_9 = - 1 ;
break;
case V_19 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_6 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_19 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
F_7 ( ( L_7 ) ) ;
break;
case V_21 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_8 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_21 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
F_7 ( ( L_9 ) ) ;
break;
case V_22 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_10 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_22 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
F_7 ( ( L_11 ) ) ;
break;
case V_23 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_12 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_23 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
F_7 ( ( L_13 ) ) ;
break;
case V_24 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_14 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_24 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
F_7 ( ( L_15 ) ) ;
break;
case V_25 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_16 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_25 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
V_3 -> V_16 . V_17 . V_26 = 0 ;
V_3 -> V_16 . V_17 . V_27 = 0 ;
V_3 -> V_16 . V_17 . V_28 = 0 ;
V_3 -> V_16 . V_17 . V_29 = 0 ;
F_7 ( ( L_17 ) ) ;
break;
case V_30 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_18 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_30 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
V_3 -> V_16 . V_17 . V_26 = 0 ;
V_3 -> V_16 . V_17 . V_27 = 0 ;
V_3 -> V_16 . V_17 . V_28 = 0 ;
V_3 -> V_16 . V_17 . V_29 = 0 ;
F_7 ( ( L_19 ) ) ;
break;
case V_31 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_20 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . type = V_31 ;
V_3 -> V_16 . V_17 . V_20 = 1 ;
V_3 -> V_16 . V_17 . V_26 = 0 ;
V_3 -> V_16 . V_17 . V_27 = 0 ;
F_7 ( ( L_21 ) ) ;
break;
case V_32 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_22 ) ;
return ( - 1 ) ;
}
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_33 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_17 . V_34 = ( short ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( short ) strlen ( V_7 ) > ( short ) ( V_8 - V_7 ) ) {
F_3 ( L_23 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_35 = 1 ;
F_7 ( ( L_24 , V_7 ) ) ;
break;
case V_36 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_25 ) ;
return ( - 1 ) ;
}
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_37 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_17 . V_38 = F_10 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_26 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_39 = 1 ;
F_7 ( ( L_27 , V_7 ) ) ;
break;
case V_40 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_25 ) ;
return ( - 1 ) ;
}
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_41 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_17 . V_42 = F_10 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_28 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_43 = 1 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_44 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_17 . V_45 = F_10 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_29 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_46 = 1 ;
F_7 ( ( L_30 , V_3 -> V_16 . V_17 . V_41 ,
V_3 -> V_16 . V_17 . V_44 ) ) ;
break;
case V_47 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_31 ) ;
return ( - 1 ) ;
}
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_48 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_17 . V_49 = 1 ;
F_7 ( ( L_32 , V_7 ) ) ;
break;
case V_50 :
if ( V_3 -> type != V_15 ) {
F_3 ( L_33 ) ;
return ( - 1 ) ;
}
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_18 = F_6 ( V_7 ) ;
F_7 ( ( L_34 , V_7 ) ) ;
break;
case V_51 :
if ( V_3 -> type == V_15 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_52 = ( char ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_35 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_53 = 1 ;
} else if ( V_3 -> type == V_54 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_52 = ( char ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_35 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_53 = 1 ;
} else if ( V_3 -> type == V_55 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . V_52 = ( char ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_35 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . V_53 = 1 ;
} else {
F_3 ( L_36 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_37 , V_7 ) ) ;
break;
case V_57 :
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_18 = F_6 ( V_7 ) ;
if ( V_3 -> type == V_54 ) {
V_3 -> V_16 . V_5 . V_58 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_5 . V_59 = 1 ;
} else if ( V_3 -> type == V_55 ) {
V_3 -> V_16 . V_56 . V_58 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_56 . V_59 = 1 ;
} else {
F_3 ( L_38 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_39 , V_7 ) ) ;
break;
case V_60 :
if ( V_3 -> type == V_15 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_61 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_40 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_17 . V_62 = 1 ;
} else if ( V_3 -> type == V_54 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_61 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_40 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_62 = 1 ;
} else if ( V_3 -> type == V_55 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . V_61 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_40 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . V_62 = 1 ;
} else {
F_3 ( L_41 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_42 , V_7 ) ) ;
break;
case V_63 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_64 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
if ( ( V_7 = F_8 ( V_1 ) ) == NULL ) {
F_3 ( L_43 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_16 . V_65 = F_6 ( V_7 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_44 , V_7 ) ) ;
break;
case V_66 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_67 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
if ( ( V_7 = F_8 ( V_1 ) ) == NULL ) {
F_3 ( L_43 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_16 . V_68 = F_6 ( V_7 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_45 , V_7 ) ) ;
break;
case LINE :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( V_4 == NULL ) {
F_3 ( L_46 ) ;
return ( - 1 ) ;
}
switch ( V_4 -> V_16 . V_17 . type ) {
case V_31 :
F_3 ( L_47 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_11 = F_5 ( V_69 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_5 = NULL ;
line = V_3 ;
V_9 ++ ;
F_7 ( ( L_48 ) ) ;
break;
case V_70 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( line == NULL ) {
F_3 ( L_49 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_11 = F_5 ( V_54 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_5 = V_3 ;
if ( V_9 )
V_4 -> V_16 . V_17 . V_27 ++ ;
else
V_4 -> V_16 . V_17 . V_26 ++ ;
F_7 ( ( L_50 ) ) ;
break;
case V_71 :
if ( V_3 -> type != V_54 ) {
F_3 ( L_51 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . type = V_71 ;
V_3 -> V_16 . V_5 . V_20 = 1 ;
F_7 ( ( L_52 ) ) ;
break;
case V_72 :
if ( V_3 -> type != V_54 ) {
F_3 ( L_51 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . type = V_72 ;
V_3 -> V_16 . V_5 . V_20 = 1 ;
F_7 ( ( L_53 ) ) ;
break;
case V_73 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( V_4 == NULL ) {
F_3 ( L_54 ) ;
return ( - 1 ) ;
}
switch ( V_4 -> V_16 . V_17 . type ) {
case V_31 :
V_9 = 0 ;
break;
default:
if ( V_5 == NULL ) {
F_3 ( L_55 ) ;
return ( - 1 ) ;
}
}
if ( ( V_3 -> V_11 = F_5 ( V_55 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
if ( V_9 )
V_4 -> V_16 . V_17 . V_29 ++ ;
else
V_4 -> V_16 . V_17 . V_28 ++ ;
F_7 ( ( L_56 ) ) ;
break;
case V_74 :
if ( V_3 -> type != V_55 ) {
F_3 ( L_57 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . type = V_74 ;
V_3 -> V_16 . V_56 . V_20 = 1 ;
F_7 ( ( L_58 ) ) ;
break;
case V_75 :
if ( V_3 -> type != V_55 ) {
F_3 ( L_59 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_56 . type = V_75 ;
V_3 -> V_16 . V_56 . V_20 = 1 ;
F_7 ( ( L_60 ) ) ;
break;
case V_76 :
if ( V_3 -> type == V_69 ) {
if ( ( V_7 = F_8 ( V_1 ) ) == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . line . V_77 = F_6 ( V_7 ) ;
V_3 -> V_16 . line . V_78 = 1 ;
}
F_7 ( ( L_61 , V_7 ) ) ;
break;
case V_79 :
if ( V_3 -> type == V_69 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . line . V_80 = ( char ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( short ) strlen ( V_7 ) > ( short ) ( V_8 - V_7 ) ) {
F_3 ( L_62 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . line . V_81 = 1 ;
} else if ( V_3 -> type == V_54 ) {
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_80 = ( char ) F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( short ) strlen ( V_7 ) > ( short ) ( V_8 - V_7 ) ) {
F_3 ( L_62 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_81 = 1 ;
} else {
F_3 ( L_63 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_64 , V_7 ) ) ;
break;
case V_82 :
if ( V_3 -> type == V_54 ) {
if ( ( V_7 = F_8 ( V_1 ) ) == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_5 . V_83 = F_6 ( V_7 ) ;
V_3 -> V_16 . V_5 . V_84 = 1 ;
}
F_7 ( ( L_65 , V_7 ) ) ;
break;
case V_85 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_86 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
if ( ( V_7 = F_8 ( V_1 ) ) == NULL ) {
F_3 ( L_43 ) ;
return ( - 1 ) ;
}
if ( ( V_3 -> V_16 . V_87 = F_6 ( V_7 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_66 , V_7 ) ) ;
break;
case V_88 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_89 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_90 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_67 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_68 , V_7 ) ) ;
break;
case V_91 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_92 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_93 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_69 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_70 , V_7 ) ) ;
break;
case V_94 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_95 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_96 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_71 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_72 , V_7 ) ) ;
break;
case V_97 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_98 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_99 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_73 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_74 , V_7 ) ) ;
break;
case V_100 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_101 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_102 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_75 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_76 , V_7 ) ) ;
break;
case V_103 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_104 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_105 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_77 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_78 , V_7 ) ) ;
break;
case V_106 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_107 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_108 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_79 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_80 , V_7 ) ) ;
break;
case V_109 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_110 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_111 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_81 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_82 , V_7 ) ) ;
break;
case V_112 :
if ( F_4 ( V_3 ) )
return ( - 1 ) ;
if ( ( V_3 -> V_11 = F_5 ( V_113 ) ) == NULL ) {
F_3 ( L_4 ) ;
return ( - 1 ) ;
}
V_3 = V_3 -> V_11 ;
V_7 = F_8 ( V_1 ) ;
if ( V_7 == NULL ) {
F_3 ( L_2 ) ;
return ( - 1 ) ;
}
V_3 -> V_16 . V_114 = F_9 ( V_7 , & V_8 , 0 ) ;
if ( ( int ) strlen ( V_7 ) > ( int ) ( V_8 - V_7 ) ) {
F_3 ( L_83 ) ;
return ( - 1 ) ;
}
F_7 ( ( L_84 , V_7 ) ) ;
break;
}
}
}
static char * F_11 ( char * string , char * V_115 )
{
char * V_116 ;
if ( ! string || ! V_115 )
return ( char * ) NULL ;
if ( * V_115 == '^' ) {
V_115 ++ ;
for (; * string ; string ++ ) {
for ( V_116 = V_115 ; * V_116 ; V_116 ++ ) {
if ( * V_116 == * string )
break;
}
if ( * V_116 == '\0' )
return string ;
}
}
else {
for (; * string ; string ++ ) {
for ( V_116 = V_115 ; * V_116 ; V_116 ++ ) {
if ( * V_116 == * string )
return string ;
}
}
}
return ( char * ) NULL ;
}
static int F_2 ( char * * V_1 , struct V_2 * V_3 )
{
char * V_117 ;
struct V_118 * V_119 ;
if ( strstr ( V_120 , L_85 ) ) {
V_117 = F_8 ( V_1 ) ;
snprintf ( V_120 , V_121 , L_86 , V_117 ) ;
for ( V_119 = V_122 ; V_119 -> V_123 != 0 ; V_119 ++ ) {
if ( ! strcmp ( V_117 , V_119 -> string ) ) {
return ( V_119 -> V_123 ) ;
}
}
F_3 ( L_87 ) ;
return ( 1 ) ;
}
else {
while ( ( V_117 = F_8 ( V_1 ) ) != NULL ) {
snprintf ( V_120 , V_121 , L_86 , V_117 ) ;
for ( V_119 = V_122 ; V_119 -> V_123 != 0 ; V_119 ++ ) {
if ( ! strcmp ( V_117 , V_119 -> string ) )
return ( V_119 -> V_123 ) ;
}
}
return ( 0 ) ;
}
}
static char * F_8 ( char * * V_1 )
{
char * V_124 = * V_1 ;
char * V_116 = F_11 ( * V_1 , L_88 ) ;
if ( ! V_116 )
return NULL ;
* V_116 = '\0' ;
* V_1 = V_116 + 1 ;
while ( * V_1 && * * V_1 && ( ( * * V_1 == ' ' ) || ( * * V_1 == '\t' ) || ( * * V_1 == '\n' ) ) ) {
* * V_1 = '\0' ;
* V_1 = * V_1 + 1 ;
}
return V_124 ;
}
static void F_3 ( char * V_7 )
{
F_12 ( L_89 , V_7 ) ;
}
static struct V_2 * F_5 ( int V_119 )
{
struct V_2 * V_125 ;
if ( ( V_125 = (struct V_2 * ) F_13 ( sizeof( struct V_2 ) , V_126 ) ) != NULL ) {
memset ( ( char * ) V_125 , 0 , sizeof( struct V_2 ) ) ;
V_125 -> type = V_119 ;
}
return ( V_125 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
switch ( V_3 -> type ) {
case V_15 :
if ( V_3 -> V_16 . V_17 . V_20 == 0 ) {
F_3 ( L_90 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
case V_69 :
if ( V_3 -> V_16 . line . V_81 == 0 ) {
F_3 ( L_91 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
case V_54 :
if ( V_3 -> V_16 . V_5 . V_20 == 0 ) {
F_3 ( L_92 ) ;
return ( 1 ) ;
}
if ( V_3 -> V_16 . V_5 . V_81 == 0 ) {
F_3 ( L_93 ) ;
return ( 1 ) ;
}
if ( V_3 -> V_16 . V_5 . V_53 == 0 ) {
F_3 ( L_94 ) ;
return ( 1 ) ;
}
if ( V_3 -> V_16 . V_5 . V_59 == 0 ) {
F_3 ( L_95 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
case V_55 :
if ( V_3 -> V_16 . V_56 . V_20 == 0 ) {
F_3 ( L_96 ) ;
return ( 1 ) ;
}
if ( V_3 -> V_16 . V_56 . V_53 == 0 ) {
F_3 ( L_97 ) ;
return ( 1 ) ;
}
if ( V_3 -> V_16 . V_56 . V_59 == 0 ) {
F_3 ( L_98 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
return ( 0 ) ;
}
static char * F_6 ( char * V_7 )
{
char * V_3 ;
if ( ( V_3 = F_13 ( strlen ( V_7 ) + 1 , V_126 ) ) != NULL ) {
strcpy ( V_3 , V_7 ) ;
}
return ( V_3 ) ;
}
T_1 F_14 ( struct V_127 * V_128 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_128 )
return ( 0 ) ;
for ( V_3 = V_128 -> V_129 ; V_3 ; V_3 = V_3 -> V_11 ) {
switch ( V_3 -> type ) {
case V_95 :
return V_3 -> V_16 . V_96 ;
default:
break;
}
}
return 0 ;
}
T_1 F_15 ( struct V_127 * V_128 )
{
struct V_2 * V_3 = NULL ;
if ( ! V_128 )
return ( 0 ) ;
for ( V_3 = V_128 -> V_129 ; V_3 ; V_3 = V_3 -> V_11 ) {
switch ( V_3 -> type ) {
case V_92 :
return V_3 -> V_16 . V_93 ;
default:
break;
}
}
return 0 ;
}
struct V_2 * F_16 ( int type , int V_130 , int V_131 )
{
struct V_2 * V_3 , * V_132 = NULL , * V_133 = NULL , * V_134 = NULL ;
V_3 = & V_10 ;
while ( V_3 -> V_11 != NULL ) {
V_132 = V_3 ;
V_3 = V_3 -> V_11 ;
if ( V_3 -> type == V_15 ) {
if ( V_3 -> V_16 . V_17 . type == type ) {
if ( V_3 -> V_16 . V_17 . V_43 && V_3 -> V_16 . V_17 . V_42 != V_130 ) {
F_17 ( ( L_99 ,
V_130 , V_3 -> V_16 . V_17 . V_42 ) ) ;
continue;
}
if ( V_3 -> V_16 . V_17 . V_46 && V_3 -> V_16 . V_17 . V_45 != V_131 ) {
F_7 ( ( L_100 ,
V_131 , V_3 -> V_16 . V_17 . V_45 ) ) ;
continue;
}
F_7 ( ( L_101 ) ) ;
V_134 = V_3 ;
while ( V_3 -> V_11 != NULL ) {
V_133 = V_3 ;
V_3 = V_3 -> V_11 ;
if ( V_3 -> type == V_15 ) {
V_133 -> V_11 = NULL ;
V_132 -> V_11 = V_3 ;
return V_134 ;
}
}
V_132 -> V_11 = NULL ;
return V_134 ;
}
}
}
return NULL ;
}
T_1 F_18 ( struct V_127 * V_128 )
{
int V_135 = 0 ;
struct V_2 * V_3 = NULL ;
if ( ! V_128 )
return ( 0 ) ;
for ( V_3 = V_128 -> V_129 ; V_3 ; V_3 = V_3 -> V_11 ) {
switch ( V_3 -> type ) {
case V_15 :
if ( V_3 -> V_16 . V_17 . type > V_136 )
V_135 += V_3 -> V_16 . V_17 . V_52 ;
break;
case V_54 :
V_135 += V_3 -> V_16 . V_5 . V_52 ;
break;
case V_55 :
V_135 += V_3 -> V_16 . V_56 . V_52 ;
break;
}
}
return ( V_135 ) ;
}
char * F_19 ( struct V_127 * V_128 , char * string )
{
char * V_116 = string ;
struct V_2 * V_3 = NULL ;
struct V_2 * V_137 = NULL ;
int V_80 ;
if ( ! V_128 ) {
* V_116 = 0xff ;
return string ;
}
for ( V_3 = V_128 -> V_129 ; V_3 ; V_3 = V_3 -> V_11 ) {
switch ( V_3 -> type ) {
case V_69 :
* V_116 = '\0' ;
V_116 ++ ;
* V_116 = V_3 -> V_16 . line . V_80 ;
V_116 ++ ;
break;
case V_54 :
V_80 = V_3 -> V_16 . V_5 . V_80 ;
V_137 = V_3 -> V_11 ;
if ( ( V_137 != NULL ) && ( V_137 -> type == V_55 ) ) {
* V_116 = ( V_3 -> V_16 . V_5 . V_52 + 0x80 ) ;
V_116 ++ ;
V_3 = V_137 ;
while ( ( V_137 -> V_11 != NULL ) && ( V_137 -> V_11 -> type ) == V_55 ) {
* V_116 = ( V_137 -> V_16 . V_56 . V_52 + 0x80 ) ;
V_116 ++ ;
V_3 = V_137 ;
V_137 = V_137 -> V_11 ;
}
* V_116 = V_137 -> V_16 . V_56 . V_52 ;
V_116 ++ ;
} else {
* V_116 = V_3 -> V_16 . V_5 . V_52 ;
V_116 ++ ;
}
* V_116 = V_80 ;
V_116 ++ ;
break;
}
}
* V_116 = 0xff ;
return string ;
}
char * F_20 ( struct V_127 * V_128 , char * string )
{
int V_134 = FALSE ;
char * V_116 = string ;
struct V_2 * V_138 = NULL ;
int V_139 = 0 ;
int V_140 = V_141 ;
if ( ! V_128 ) {
return L_102 ;
}
for ( V_138 = V_128 -> V_129 ; V_138 ; V_138 = V_138 -> V_11 ) {
if ( ( V_138 -> type == V_15 ) &&
( ( V_138 -> V_16 . V_17 . type == V_19 ) || ( V_138 -> V_16 . V_17 . type == V_21 ) ||
( V_138 -> V_16 . V_17 . type == V_22 ) || ( V_138 -> V_16 . V_17 . type == V_23 ) ||
( V_138 -> V_16 . V_17 . type == V_24 ) ) ) {
V_134 = TRUE ;
}
if ( V_138 -> type == V_64 && V_134 == TRUE ) {
char * V_142 ;
if ( strstr ( V_138 -> V_16 . V_65 , L_103 ) ) {
V_142 = V_138 -> V_16 . V_65 ;
V_142 += 3 ;
}
else {
V_142 = V_138 -> V_16 . V_65 ;
}
if ( V_142 ) {
V_139 = snprintf ( V_116 , V_140 , L_86 , V_142 ) ;
V_140 -= V_139 ;
V_116 += V_139 ;
if ( V_140 <= 0 )
break;
}
}
if ( V_138 -> type == V_54 ) {
if ( V_138 -> V_16 . V_5 . V_58 ) {
V_139 = snprintf ( V_116 , V_140 , L_86 , V_138 -> V_16 . V_5 . V_58 ) ;
V_140 -= V_139 ;
V_116 += V_139 ;
if ( V_140 <= 0 )
break;
}
}
if ( V_138 -> type == V_55 ) {
if ( V_138 -> V_16 . V_56 . V_58 ) {
V_139 = snprintf ( V_116 , V_140 , L_86 , V_138 -> V_16 . V_56 . V_58 ) ;
V_140 -= V_139 ;
V_116 += V_139 ;
if ( V_140 <= 0 )
break;
}
}
}
return string ;
}
