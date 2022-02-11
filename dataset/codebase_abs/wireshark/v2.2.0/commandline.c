void
F_1 ( T_1 V_1 ) {
T_2 * V_2 ;
#ifdef F_2
F_3 () ;
#endif
if ( V_1 ) {
V_2 = stdout ;
fprintf ( V_2 , L_1
L_2
L_3 ,
F_4 () ) ;
} else {
V_2 = V_3 ;
}
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_5 ) ;
fprintf ( V_2 , L_4 ) ;
#ifdef F_5
fprintf ( V_2 , L_6 ) ;
fprintf ( V_2 , L_7 ) ;
fprintf ( V_2 , L_8 ) ;
fprintf ( V_2 , L_9 ) ;
fprintf ( V_2 , L_10 ) ;
fprintf ( V_2 , L_11 ) ;
fprintf ( V_2 , L_12 ) ;
fprintf ( V_2 , L_13 ) ;
#ifdef F_6
fprintf ( V_2 , L_14 ) ;
#endif
#ifdef F_7
fprintf ( V_2 , L_15 , V_4 ) ;
#endif
fprintf ( V_2 , L_16 ) ;
fprintf ( V_2 , L_17 ) ;
fprintf ( V_2 , L_18 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_19 ) ;
fprintf ( V_2 , L_20 ) ;
fprintf ( V_2 , L_21 ) ;
fprintf ( V_2 , L_22 ) ;
fprintf ( V_2 , L_23 ) ;
fprintf ( V_2 , L_24 ) ;
fprintf ( V_2 , L_25 ) ;
fprintf ( V_2 , L_26 ) ;
fprintf ( V_2 , L_27 ) ;
#endif
#ifdef F_8
fprintf ( V_2 , L_28 ) ;
fprintf ( V_2 , L_29 ) ;
#endif
fprintf ( V_2 , L_30 ) ;
fprintf ( V_2 , L_31 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_32 ) ;
fprintf ( V_2 , L_33 ) ;
fprintf ( V_2 , L_34 ) ;
fprintf ( V_2 , L_35 ) ;
fprintf ( V_2 , L_36 , V_5 ) ;
fprintf ( V_2 , L_37 ) ;
fprintf ( V_2 , L_38 ) ;
fprintf ( V_2 , L_39 ) ;
fprintf ( V_2 , L_40 ) ;
fprintf ( V_2 , L_41 ) ;
fprintf ( V_2 , L_42 ) ;
fprintf ( V_2 , L_43 ) ;
fprintf ( V_2 , L_44 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_45 ) ;
fprintf ( V_2 , L_46 ) ;
fprintf ( V_2 , L_47 ) ;
fprintf ( V_2 , L_48 ) ;
fprintf ( V_2 , L_49 ) ;
fprintf ( V_2 , L_50 ) ;
fprintf ( V_2 , L_51 ) ;
fprintf ( V_2 , L_52 ) ;
fprintf ( V_2 , L_53 ) ;
fprintf ( V_2 , L_54 ) ;
fprintf ( V_2 , L_55 ) ;
fprintf ( V_2 , L_56 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_57 ) ;
fprintf ( V_2 , L_58 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_59 ) ;
fprintf ( V_2 , L_60 ) ;
fprintf ( V_2 , L_61 ) ;
fprintf ( V_2 , L_62 ) ;
fprintf ( V_2 , L_63 ) ;
fprintf ( V_2 , L_64 ) ;
fprintf ( V_2 , L_65 ) ;
#ifndef F_2
fprintf ( V_2 , L_66 ) ;
#endif
#ifdef F_2
F_9 () ;
#endif
}
static void F_10 ( void )
{
F_11 ( L_67 ) ;
}
void F_12 ( int V_6 , char * V_7 [] ,
T_3 * V_8 , T_3 * V_9 )
{
int V_10 ;
#ifdef F_5
int V_11 ;
T_4 * V_12 ;
T_5 * V_13 ;
#else
T_1 V_14 ;
#endif
V_15 = 0 ;
#ifndef F_5
V_14 = FALSE ;
#endif
while ( ( V_10 = F_13 ( V_6 , V_7 , V_16 , V_17 , NULL ) ) != - 1 ) {
switch ( V_10 ) {
case 'C' :
if ( F_14 ( V_18 , FALSE ) ) {
F_15 ( V_18 ) ;
} else {
F_11 ( L_68 , V_18 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_5
V_12 = F_16 ( & V_11 , & V_13 , NULL ) ;
if ( V_12 == NULL ) {
if ( V_11 == 0 )
F_11 ( L_69 ) ;
else {
F_11 ( L_70 , V_13 ) ;
F_17 ( V_13 ) ;
}
exit ( 2 ) ;
}
#ifdef F_2
F_3 () ;
#endif
F_18 ( V_12 ) ;
F_19 ( V_12 ) ;
#ifdef F_2
F_9 () ;
#endif
exit ( 0 ) ;
#else
V_14 = TRUE ;
#endif
break;
case 'h' :
F_1 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_2
case 'i' :
if ( strcmp ( V_18 , L_71 ) == 0 )
F_20 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_21 ( V_10 , V_18 ) ) {
F_11 ( L_72 , V_18 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_2
F_3 () ;
#endif
F_22 ( L_73 , V_8 , V_9 ) ;
#ifdef F_2
F_9 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_23 ( V_18 ) ;
break;
case '?' :
break;
}
}
#ifndef F_5
if ( V_14 ) {
F_10 () ;
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#endif
}
void F_24 ( int V_6 , char * V_7 [] , T_1 V_19 )
{
int V_10 ;
T_1 V_20 = FALSE ;
#ifdef F_5
int V_21 ;
#else
T_1 V_14 ;
#endif
char V_22 ;
if ( V_19 ) {
#ifdef F_25
V_23 = 1 ;
V_24 = 1 ;
#else
V_24 = 0 ;
#endif
V_15 = 1 ;
}
V_25 . V_26 = V_27 ;
V_25 . V_28 = 0 ;
V_25 . V_29 = NULL ;
V_25 . V_30 = NULL ;
V_25 . V_31 = NULL ;
V_25 . V_32 = NULL ;
V_25 . V_33 = V_34 ;
#ifdef F_5
V_25 . V_35 = FALSE ;
V_25 . V_36 = FALSE ;
V_25 . V_37 = getenv ( L_74 ) ? TRUE : FALSE ;
#endif
V_25 . V_38 = NULL ;
V_25 . V_39 = NULL ;
V_25 . V_40 = NULL ;
while ( ( V_10 = F_13 ( V_6 , V_7 , V_16 , V_17 , NULL ) ) != - 1 ) {
switch ( V_10 ) {
case 'a' :
case 'b' :
case 'c' :
case 'f' :
case 'k' :
case 'H' :
case 'p' :
case 'i' :
#ifdef F_6
case 'I' :
#endif
#ifdef F_8
case 'A' :
#endif
case 's' :
case 'S' :
case 'w' :
case 'y' :
#ifdef F_7
case 'B' :
#endif
#ifdef F_5
V_21 = F_26 ( & V_41 , V_10 , V_18 ,
& V_25 . V_35 ) ;
if( V_21 != 0 ) {
exit ( V_21 ) ;
}
#else
V_14 = TRUE ;
V_20 = TRUE ;
#endif
break;
#if F_27 ( V_42 ) || F_27 ( V_43 )
case 'K' :
F_28 ( V_18 ) ;
break;
#endif
case 'C' :
break;
case 'd' :
if ( ! F_29 ( V_18 ) )
exit ( 1 ) ;
break;
case 'j' :
V_25 . V_26 = V_44 ;
break;
case 'g' :
V_25 . V_28 = F_30 ( V_18 , L_75 ) ;
break;
case 'J' :
V_25 . V_29 = V_18 ;
break;
case 'l' :
#ifdef F_5
V_45 = TRUE ;
#else
V_14 = TRUE ;
V_20 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_5
V_25 . V_36 = TRUE ;
#else
V_14 = TRUE ;
V_20 = TRUE ;
#endif
break;
case 'm' :
F_17 ( V_25 . V_46 -> V_47 ) ;
V_25 . V_46 -> V_47 = F_31 ( V_18 ) ;
break;
case 'n' :
F_32 () ;
break;
case 'N' :
V_22 = F_33 ( V_18 , & V_48 ) ;
if ( V_22 != '\0' ) {
F_11 ( L_76 ,
V_22 ) ;
exit ( 1 ) ;
}
break;
case 'o' :
switch ( F_34 ( V_18 ) ) {
case V_49 :
break;
case V_50 :
F_11 ( L_77 , V_18 ) ;
exit ( 1 ) ;
break;
case V_51 :
switch ( F_35 ( V_18 ) ) {
case V_49 :
break;
case V_50 :
F_11 ( L_77 , V_18 ) ;
exit ( 1 ) ;
break;
case V_51 :
case V_52 :
F_11 ( L_78 ,
V_18 ) ;
exit ( 1 ) ;
break;
default:
F_36 () ;
}
break;
case V_52 :
F_11 ( L_79 ,
V_18 ) ;
exit ( 1 ) ;
break;
default:
F_36 () ;
}
break;
case 'P' :
break;
case 'r' :
V_25 . V_30 = F_31 ( V_18 ) ;
break;
case 'R' :
V_25 . V_31 = V_18 ;
break;
case 't' :
if ( strcmp ( V_18 , L_80 ) == 0 )
V_25 . V_33 = V_53 ;
else if ( strcmp ( V_18 , L_81 ) == 0 )
V_25 . V_33 = V_54 ;
else if ( strcmp ( V_18 , L_82 ) == 0 )
V_25 . V_33 = V_55 ;
else if ( strcmp ( V_18 , L_83 ) == 0 )
V_25 . V_33 = V_56 ;
else if ( strcmp ( V_18 , L_84 ) == 0 )
V_25 . V_33 = V_57 ;
else if ( strcmp ( V_18 , L_85 ) == 0 )
V_25 . V_33 = V_58 ;
else if ( strcmp ( V_18 , L_86 ) == 0 )
V_25 . V_33 = V_59 ;
else if ( strcmp ( V_18 , L_87 ) == 0 )
V_25 . V_33 = V_60 ;
else if ( strcmp ( V_18 , L_88 ) == 0 )
V_25 . V_33 = V_61 ;
else if ( strcmp ( V_18 , L_89 ) == 0 )
V_25 . V_33 = V_62 ;
else {
F_11 ( L_90 , V_18 ) ;
F_37 ( L_91 ) ;
F_37 ( L_92 ) ;
F_37 ( L_93 ) ;
F_37 ( L_94 ) ;
F_37 ( L_95 ) ;
exit ( 1 ) ;
}
break;
case 'u' :
if ( strcmp ( V_18 , L_96 ) == 0 )
F_38 ( V_63 ) ;
else if ( strcmp ( V_18 , L_97 ) == 0 )
F_38 ( V_64 ) ;
else {
F_11 ( L_98 , V_18 ) ;
F_37 ( L_99 ) ;
exit ( 1 ) ;
}
break;
case 'X' :
break;
case 'Y' :
V_25 . V_32 = V_18 ;
break;
case 'z' :
if ( strcmp ( L_100 , V_18 ) == 0 ) {
fprintf ( V_3 , L_101 ) ;
F_39 () ;
exit ( 0 ) ;
}
if ( ! F_40 ( V_18 ) ) {
F_11 ( L_102 ) ;
F_37 ( L_103 ) ;
F_39 () ;
exit ( 1 ) ;
}
break;
case V_65 :
V_25 . V_38 = F_41 ( V_25 . V_38 , V_18 ) ;
break;
case V_66 :
V_25 . V_39 = F_41 ( V_25 . V_39 , V_18 ) ;
break;
case V_67 :
V_25 . V_40 = F_41 ( V_25 . V_40 , V_18 ) ;
break;
default:
case '?' :
V_20 = TRUE ;
break;
}
}
if ( ! V_20 ) {
V_6 -= V_24 ;
V_7 += V_24 ;
if ( V_6 >= 1 ) {
if ( V_25 . V_30 != NULL ) {
F_11 ( L_104 ) ;
V_20 = TRUE ;
} else {
#ifndef F_42
V_25 . V_30 = F_31 ( V_7 [ 0 ] ) ;
#endif
}
V_6 -- ;
V_7 ++ ;
}
if ( V_6 != 0 ) {
F_11 ( L_105 , V_7 [ 0 ] ) ;
V_20 = TRUE ;
}
}
if ( V_20 ) {
#ifndef F_5
if ( V_14 ) {
F_10 () ;
}
#endif
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_5
if ( V_25 . V_35 && V_25 . V_36 ) {
F_11 ( L_106 ) ;
exit ( 1 ) ;
}
if ( V_25 . V_36 ) {
if ( V_25 . V_30 ) {
F_11 ( L_107 ) ;
exit ( 1 ) ;
}
if ( V_41 . V_68 ) {
F_11 ( L_108 ) ;
exit ( 1 ) ;
}
} else {
if ( V_25 . V_35 && V_25 . V_30 ) {
F_11 ( L_109 ) ;
exit ( 1 ) ;
}
if ( V_41 . V_68 ) {
if ( V_41 . V_69 == NULL ) {
F_11 ( L_110 ) ;
V_41 . V_68 = FALSE ;
}
if ( ! V_41 . V_70 && ! V_41 . V_71 ) {
F_11 ( L_111 ) ;
}
}
}
#endif
}
