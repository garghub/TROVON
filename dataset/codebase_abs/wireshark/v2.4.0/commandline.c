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
#ifdef F_6
fprintf ( V_2 , L_9 ) ;
#else
fprintf ( V_2 , L_10 , V_4 ) ;
#endif
fprintf ( V_2 , L_11 ) ;
fprintf ( V_2 , L_12 ) ;
fprintf ( V_2 , L_13 ) ;
fprintf ( V_2 , L_14 ) ;
#ifdef F_6
fprintf ( V_2 , L_15 ) ;
#endif
#ifdef F_7
fprintf ( V_2 , L_16 , V_5 ) ;
#endif
fprintf ( V_2 , L_17 ) ;
fprintf ( V_2 , L_18 ) ;
fprintf ( V_2 , L_19 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_20 ) ;
fprintf ( V_2 , L_21 ) ;
fprintf ( V_2 , L_22 ) ;
fprintf ( V_2 , L_23 ) ;
fprintf ( V_2 , L_24 ) ;
fprintf ( V_2 , L_25 ) ;
fprintf ( V_2 , L_26 ) ;
fprintf ( V_2 , L_27 ) ;
fprintf ( V_2 , L_28 ) ;
#endif
#ifdef F_8
fprintf ( V_2 , L_29 ) ;
fprintf ( V_2 , L_30 ) ;
#endif
fprintf ( V_2 , L_31 ) ;
fprintf ( V_2 , L_32 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_33 ) ;
fprintf ( V_2 , L_34 ) ;
fprintf ( V_2 , L_35 ) ;
fprintf ( V_2 , L_36 ) ;
fprintf ( V_2 , L_37 , V_6 ) ;
fprintf ( V_2 , L_38 ) ;
fprintf ( V_2 , L_39 ) ;
fprintf ( V_2 , L_40 ) ;
fprintf ( V_2 , L_41 ) ;
fprintf ( V_2 , L_42 ) ;
fprintf ( V_2 , L_43 ) ;
fprintf ( V_2 , L_44 ) ;
fprintf ( V_2 , L_45 ) ;
fprintf ( V_2 , L_46 ) ;
fprintf ( V_2 , L_47 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_48 ) ;
fprintf ( V_2 , L_49 ) ;
fprintf ( V_2 , L_50 ) ;
fprintf ( V_2 , L_51 ) ;
fprintf ( V_2 , L_52 ) ;
fprintf ( V_2 , L_53 ) ;
fprintf ( V_2 , L_54 ) ;
fprintf ( V_2 , L_55 ) ;
fprintf ( V_2 , L_56 ) ;
fprintf ( V_2 , L_57 ) ;
fprintf ( V_2 , L_58 ) ;
fprintf ( V_2 , L_59 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_60 ) ;
fprintf ( V_2 , L_61 ) ;
fprintf ( V_2 , L_4 ) ;
fprintf ( V_2 , L_62 ) ;
fprintf ( V_2 , L_63 ) ;
fprintf ( V_2 , L_64 ) ;
fprintf ( V_2 , L_65 ) ;
fprintf ( V_2 , L_66 ) ;
fprintf ( V_2 , L_67 ) ;
fprintf ( V_2 , L_68 ) ;
#ifndef F_2
fprintf ( V_2 , L_69 ) ;
#endif
fprintf ( V_2 , L_70 ) ;
#ifdef F_2
F_9 () ;
#endif
}
static void F_10 ( void )
{
F_11 ( L_71 ) ;
}
void F_12 ( int V_7 , char * V_8 [] ,
T_3 * V_9 , T_3 * V_10 )
{
int V_11 ;
#ifdef F_5
int V_12 ;
T_4 * V_13 ;
T_5 * V_14 ;
#else
T_1 V_15 ;
#endif
V_16 = 0 ;
#ifndef F_5
V_15 = FALSE ;
#endif
while ( ( V_11 = F_13 ( V_7 , V_8 , V_17 , V_18 , NULL ) ) != - 1 ) {
switch ( V_11 ) {
case 'C' :
if ( F_14 ( V_19 , FALSE ) ) {
F_15 ( V_19 ) ;
} else {
F_11 ( L_72 , V_19 ) ;
exit ( 1 ) ;
}
break;
case 'D' :
#ifdef F_5
V_13 = F_16 ( & V_12 , & V_14 , NULL ) ;
if ( V_13 == NULL ) {
if ( V_12 == 0 )
F_11 ( L_73 ) ;
else {
F_11 ( L_74 , V_14 ) ;
F_17 ( V_14 ) ;
}
exit ( 2 ) ;
}
#ifdef F_2
F_3 () ;
#endif
F_18 ( V_13 ) ;
F_19 ( V_13 ) ;
#ifdef F_2
F_9 () ;
#endif
exit ( 0 ) ;
#else
V_15 = TRUE ;
#endif
break;
case 'h' :
F_1 ( TRUE ) ;
exit ( 0 ) ;
break;
#ifdef F_2
case 'i' :
if ( strcmp ( V_19 , L_75 ) == 0 )
F_20 ( TRUE ) ;
break;
#endif
case 'P' :
if ( ! F_21 ( V_11 , V_19 ) ) {
F_11 ( L_76 , V_19 ) ;
exit ( 2 ) ;
}
break;
case 'v' :
#ifdef F_2
F_3 () ;
#endif
F_22 ( L_77 , V_9 , V_10 ) ;
#ifdef F_2
F_9 () ;
#endif
exit ( 0 ) ;
break;
case 'X' :
F_23 ( V_19 ) ;
break;
case '?' :
break;
}
}
#ifndef F_5
if ( V_15 ) {
F_10 () ;
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#endif
}
void F_24 ( int V_7 , char * V_8 [] , T_1 V_20 )
{
int V_11 ;
T_1 V_21 = FALSE ;
#ifdef F_5
int V_22 ;
#else
T_1 V_15 ;
#endif
if ( V_20 ) {
#ifdef F_25
V_23 = 1 ;
V_24 = 1 ;
#else
V_24 = 0 ;
#endif
V_16 = 1 ;
}
F_26 () ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = 0 ;
V_25 . V_29 = NULL ;
V_25 . V_30 = NULL ;
V_25 . V_31 = NULL ;
V_25 . V_32 = NULL ;
#ifdef F_5
V_25 . V_33 = FALSE ;
V_25 . V_34 = FALSE ;
V_25 . V_35 = getenv ( L_78 ) ? TRUE : FALSE ;
#endif
V_25 . V_36 = FALSE ;
while ( ( V_11 = F_13 ( V_7 , V_8 , V_17 , V_18 , NULL ) ) != - 1 ) {
switch ( V_11 ) {
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
V_22 = F_27 ( & V_37 , V_11 , V_19 ,
& V_25 . V_33 ) ;
if( V_22 != 0 ) {
exit ( V_22 ) ;
}
#else
V_15 = TRUE ;
V_21 = TRUE ;
#endif
break;
case 'C' :
break;
case 'j' :
V_25 . V_26 = V_38 ;
break;
case 'g' :
V_25 . V_28 = F_28 ( V_19 , L_79 ) ;
break;
case 'J' :
V_25 . V_29 = V_19 ;
break;
case 'l' :
#ifdef F_5
V_39 = TRUE ;
#else
V_15 = TRUE ;
V_21 = TRUE ;
#endif
break;
case 'L' :
#ifdef F_5
V_25 . V_34 = TRUE ;
#else
V_15 = TRUE ;
V_21 = TRUE ;
#endif
break;
case 'o' :
{
char * V_40 = NULL ;
switch ( F_29 ( V_19 , & V_40 ) ) {
case V_41 :
break;
case V_42 :
F_11 ( L_80 , V_19 ,
V_40 ? L_81 : L_82 , V_40 ? V_40 : L_82 ) ;
F_17 ( V_40 ) ;
exit ( 1 ) ;
break;
case V_43 :
switch ( F_30 ( V_19 ) ) {
case V_41 :
break;
case V_42 :
F_11 ( L_83 , V_19 ) ;
exit ( 1 ) ;
break;
case V_43 :
case V_44 :
F_11 ( L_84 ,
V_19 ) ;
exit ( 1 ) ;
break;
default:
F_31 () ;
}
break;
case V_44 :
F_11 ( L_85 ,
V_19 ) ;
exit ( 1 ) ;
break;
default:
F_31 () ;
}
break;
}
case 'P' :
break;
case 'r' :
V_25 . V_30 = F_32 ( V_19 ) ;
break;
case 'R' :
V_25 . V_31 = V_19 ;
break;
case 'X' :
break;
case 'Y' :
V_25 . V_32 = V_19 ;
break;
case 'z' :
if ( strcmp ( L_86 , V_19 ) == 0 ) {
fprintf ( V_3 , L_87 ) ;
F_33 () ;
exit ( 0 ) ;
}
if ( ! F_34 ( V_19 ) ) {
F_11 ( L_88 ) ;
F_35 ( L_89 ) ;
F_33 () ;
exit ( 1 ) ;
}
break;
case 'd' :
case 'K' :
case 'n' :
case 'N' :
case 't' :
case 'u' :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
if ( ! F_36 ( V_11 , V_19 ) )
exit ( 1 ) ;
break;
case V_49 :
V_25 . V_36 = TRUE ;
break;
default:
case '?' :
V_21 = TRUE ;
break;
}
}
if ( ! V_21 ) {
V_7 -= V_24 ;
V_8 += V_24 ;
if ( V_7 >= 1 ) {
if ( V_25 . V_30 != NULL ) {
F_11 ( L_90 ) ;
V_21 = TRUE ;
} else {
#ifndef F_37
V_25 . V_30 = F_32 ( V_8 [ 0 ] ) ;
#endif
}
V_7 -- ;
V_8 ++ ;
}
if ( V_7 != 0 ) {
F_11 ( L_91 , V_8 [ 0 ] ) ;
V_21 = TRUE ;
}
}
if ( V_21 ) {
#ifndef F_5
if ( V_15 ) {
F_10 () ;
}
#endif
F_1 ( FALSE ) ;
exit ( 1 ) ;
}
#ifdef F_5
if ( V_25 . V_33 && V_25 . V_34 ) {
F_11 ( L_92 ) ;
exit ( 1 ) ;
}
if ( V_25 . V_34 ) {
if ( V_25 . V_30 ) {
F_11 ( L_93 ) ;
exit ( 1 ) ;
}
if ( V_37 . V_50 ) {
F_11 ( L_94 ) ;
exit ( 1 ) ;
}
} else {
if ( V_25 . V_33 && V_25 . V_30 ) {
F_11 ( L_95 ) ;
exit ( 1 ) ;
}
if ( V_37 . V_50 ) {
if ( V_37 . V_51 == NULL ) {
F_11 ( L_96 ) ;
V_37 . V_50 = FALSE ;
}
if ( ! V_37 . V_52 && ! V_37 . V_53 ) {
F_11 ( L_97 ) ;
}
}
}
#endif
}
