static void
F_1 ( void )
{
V_1 = TRUE ;
V_2 = TRUE ;
V_3 = TRUE ;
V_4 = TRUE ;
V_5 = TRUE ;
V_6 = TRUE ;
V_7 = TRUE ;
V_8 = TRUE ;
V_9 = TRUE ;
V_10 = TRUE ;
V_11 = TRUE ;
V_12 = TRUE ;
V_13 = TRUE ;
V_14 = TRUE ;
V_15 = TRUE ;
V_16 = TRUE ;
V_17 = TRUE ;
V_18 = TRUE ;
#ifdef F_2
V_19 = TRUE ;
#endif
}
static void
F_3 ( void )
{
V_1 = FALSE ;
V_2 = FALSE ;
V_3 = FALSE ;
V_4 = FALSE ;
V_5 = FALSE ;
V_6 = FALSE ;
V_7 = FALSE ;
V_8 = FALSE ;
V_9 = FALSE ;
V_10 = FALSE ;
V_11 = FALSE ;
V_12 = FALSE ;
V_13 = FALSE ;
V_14 = FALSE ;
V_15 = FALSE ;
V_16 = FALSE ;
V_17 = FALSE ;
V_18 = FALSE ;
#ifdef F_2
V_19 = FALSE ;
#endif
}
static const T_1 *
F_4 ( T_2 V_20 )
{
switch ( V_20 ) {
case V_21 :
return L_1 ;
case V_22 :
return L_2 ;
case V_23 :
return L_3 ;
default:
return L_4 ;
}
}
static T_1 *
F_5 ( T_3 * V_24 , int V_25 , T_4 * V_26 )
{
static T_1 V_27 [ 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 9 + 1 + 1 ] ;
struct V_28 * V_29 ;
if ( V_26 -> V_30 && V_26 -> V_31 > 0 ) {
if ( V_32 ) {
switch ( V_25 ) {
case V_33 :
F_6 ( V_27 , sizeof V_27 ,
L_5 ,
( unsigned long ) V_24 -> V_34 ) ;
break;
case V_35 :
F_6 ( V_27 , sizeof V_27 ,
L_6 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 100000000 ) ;
break;
case V_37 :
F_6 ( V_27 , sizeof V_27 ,
L_7 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 10000000 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_8 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 1000000 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_9 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 1000 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_10 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 ) ;
break;
default:
F_6 ( V_27 , sizeof V_27 ,
L_11 ,
V_25 ) ;
break;
}
return V_27 ;
} else {
V_29 = localtime ( & V_24 -> V_34 ) ;
if ( V_29 == NULL ) {
F_6 ( V_27 , sizeof V_27 , L_12 ) ;
return V_27 ;
}
switch ( V_25 ) {
case V_33 :
F_6 ( V_27 , sizeof V_27 ,
L_13 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ) ;
break;
case V_35 :
F_6 ( V_27 , sizeof V_27 ,
L_14 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_24 -> V_36 / 100000000 ) ;
break;
case V_37 :
F_6 ( V_27 , sizeof V_27 ,
L_15 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_24 -> V_36 / 10000000 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_16 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_24 -> V_36 / 1000000 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_17 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_24 -> V_36 / 1000 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_18 ,
V_29 -> V_41 + 1900 ,
V_29 -> V_42 + 1 ,
V_29 -> V_43 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_24 -> V_36 ) ;
break;
default:
F_6 ( V_27 , sizeof V_27 ,
L_11 ,
V_25 ) ;
break;
}
return V_27 ;
}
}
F_6 ( V_27 , sizeof V_27 , L_19 ) ;
return V_27 ;
}
static T_1 *
F_7 ( T_3 * V_24 , int V_25 , T_4 * V_26 , T_5 V_47 )
{
const T_1 * V_48 = V_47 ? L_20 : L_21 ;
const T_1 * V_49 = V_47 ? L_22 : L_21 ;
static T_1 V_27 [ 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 1 ] ;
if ( V_26 -> V_30 && V_26 -> V_31 > 0 ) {
switch ( V_25 ) {
case V_33 :
F_6 ( V_27 , sizeof V_27 ,
L_23 ,
( unsigned long ) V_24 -> V_34 ,
V_48 ,
V_24 -> V_34 == 1 ? L_21 : V_49 ) ;
break;
case V_35 :
F_6 ( V_27 , sizeof V_27 ,
L_24 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 100000000 ,
V_48 ,
( V_24 -> V_34 == 1 && V_24 -> V_36 == 0 ) ? L_21 : V_49 ) ;
break;
case V_37 :
F_6 ( V_27 , sizeof V_27 ,
L_25 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 10000000 ,
V_48 ,
( V_24 -> V_34 == 1 && V_24 -> V_36 == 0 ) ? L_21 : V_49 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_26 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 1000000 ,
V_48 ,
( V_24 -> V_34 == 1 && V_24 -> V_36 == 0 ) ? L_21 : V_49 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_27 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 / 1000 ,
V_48 ,
( V_24 -> V_34 == 1 && V_24 -> V_36 == 0 ) ? L_21 : V_49 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_28 ,
( unsigned long ) V_24 -> V_34 ,
V_24 -> V_36 ,
V_48 ,
( V_24 -> V_34 == 1 && V_24 -> V_36 == 0 ) ? L_21 : V_49 ) ;
break;
default:
F_6 ( V_27 , sizeof V_27 ,
L_11 ,
V_25 ) ;
break;
}
return V_27 ;
}
F_6 ( V_27 , sizeof V_27 , L_19 ) ;
return V_27 ;
}
static void F_8 ( const T_1 * V_50 , T_6 V_51 , const T_1 * V_52 , double V_53 ) {
if ( V_53 > 0.0 )
printf ( L_29 , V_50 , V_51 , V_53 , V_52 ) ;
else
printf ( L_30 , V_50 ) ;
}
static void
F_9 ( const T_1 * V_54 , T_4 * V_26 )
{
const T_1 * V_55 , * V_56 ;
T_1 * V_57 ;
V_55 = F_10 ( V_26 -> V_58 ) ;
V_56 = F_11 ( V_26 -> V_59 ) ;
if ( V_54 ) printf ( L_31 , V_54 ) ;
if ( V_2 ) printf ( L_32 ,
V_55 ,
V_26 -> V_60 ? L_33 : L_21 ) ;
if ( V_3 ) {
printf ( L_34 , V_56 ) ;
if ( V_26 -> V_59 == V_61 ) {
int V_62 ;
printf ( L_35 ) ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
if ( V_26 -> V_64 [ V_62 ] > 0 )
printf ( L_36 ,
F_11 ( V_62 ) , V_26 -> V_64 [ V_62 ] ) ;
}
}
}
if ( V_8 ) {
printf ( L_37 ,
F_12 ( V_26 -> V_65 ) , V_26 -> V_65 ) ;
}
if ( V_4 && V_26 -> V_66 )
printf ( L_38 , V_26 -> V_67 ) ;
else if ( V_4 && ! V_26 -> V_66 )
printf ( L_39 ) ;
if ( V_26 -> V_68 > 0 ) {
if ( V_26 -> V_69 == V_26 -> V_68 )
printf ( L_40 , V_26 -> V_69 ) ;
else
printf ( L_41 ,
V_26 -> V_69 , V_26 -> V_68 ) ;
}
if ( V_5 ) {
printf ( L_42 ) ;
if ( V_70 ) {
printf ( L_43 , V_26 -> V_31 ) ;
} else {
V_57 = F_13 ( V_26 -> V_31 , V_71 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
if ( V_6 ) {
printf ( L_45 ) ;
if ( V_70 ) {
printf ( L_46 V_72 L_47 , V_26 -> V_73 ) ;
} else {
V_57 = F_13 ( V_26 -> V_73 , V_74 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
if ( V_10 ) {
printf ( L_48 ) ;
if ( V_70 ) {
printf ( L_46 V_72 L_49 , V_26 -> V_75 ) ;
} else {
V_57 = F_13 ( V_26 -> V_75 , V_74 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
if ( V_26 -> V_30 ) {
if ( V_11 )
printf ( L_50 , F_7 ( & V_26 -> V_76 , V_26 -> V_77 , V_26 , TRUE ) ) ;
if ( V_12 )
printf ( L_51 , F_5 ( & V_26 -> V_78 , V_26 -> V_79 , V_26 ) ) ;
if ( V_13 )
printf ( L_52 , F_5 ( & V_26 -> V_80 , V_26 -> V_81 , V_26 ) ) ;
if ( V_15 ) {
printf ( L_53 ) ;
if ( V_70 ) {
F_8 ( L_21 , 2 , L_54 , V_26 -> V_82 ) ;
} else {
V_57 = F_13 ( ( V_83 ) V_26 -> V_82 , V_84 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
if ( V_16 ) {
printf ( L_55 ) ;
if ( V_70 ) {
F_8 ( L_21 , 2 , L_56 , V_26 -> V_82 * 8 ) ;
} else {
V_57 = F_13 ( ( V_83 ) ( V_26 -> V_82 * 8 ) , V_85 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
}
if ( V_17 ) printf ( L_57 , V_26 -> V_86 ) ;
if ( V_26 -> V_30 ) {
if ( V_18 ) {
printf ( L_58 ) ;
if ( V_70 ) {
F_8 ( L_21 , 2 , L_59 , V_26 -> V_87 ) ;
} else {
V_57 = F_13 ( ( V_83 ) V_26 -> V_87 , V_88 ) ;
printf ( L_44 , V_57 ) ;
F_14 ( V_57 ) ;
}
}
}
#ifdef F_2
if ( V_19 ) {
printf ( L_60 , V_89 ) ;
printf ( L_61 , V_90 ) ;
printf ( L_62 , V_91 ) ;
}
#endif
if ( V_14 ) printf ( L_63 , F_4 ( V_26 -> V_20 ) ) ;
if ( V_7 && V_26 -> V_92 )
printf ( L_64 , V_26 -> V_92 ) ;
if ( V_8 ) {
if ( V_26 -> V_93 )
printf ( L_65 , V_26 -> V_93 ) ;
if ( V_26 -> V_94 )
printf ( L_66 , V_26 -> V_94 ) ;
if ( V_26 -> V_95 )
printf ( L_67 , V_26 -> V_95 ) ;
}
if ( V_9 && V_26 -> V_96 != 0 ) {
T_7 V_62 ;
F_15 ( V_26 -> V_96 == V_26 -> V_97 -> V_98 ) ;
printf ( L_68 , V_26 -> V_96 ) ;
for ( V_62 = 0 ; V_62 < V_26 -> V_97 -> V_98 ; V_62 ++ ) {
T_1 * V_99 = F_16 ( V_26 -> V_97 , T_1 * , V_62 ) ;
printf ( L_69 , V_62 ) ;
printf ( L_70 , V_99 ) ;
printf ( L_71 , V_26 -> V_100 [ V_62 ] ) ;
}
}
}
static void
F_17 ( void )
{
if ( V_101 ) putchar ( V_101 ) ;
}
static void
F_18 ( void )
{
if ( V_102 ) putchar ( V_102 ) ;
}
static void
F_19 ( const T_1 * V_103 )
{
F_17 () ;
F_18 () ;
printf ( L_70 , V_103 ) ;
F_18 () ;
}
static void
F_20 ( void )
{
F_18 () ;
printf ( L_72 ) ;
F_18 () ;
if ( V_2 ) F_19 ( L_73 ) ;
if ( V_3 ) F_19 ( L_74 ) ;
if ( V_8 ) F_19 ( L_75 ) ;
if ( V_4 ) F_19 ( L_76 ) ;
if ( V_4 ) F_19 ( L_77 ) ;
if ( V_4 ) F_19 ( L_78 ) ;
if ( V_5 ) F_19 ( L_79 ) ;
if ( V_6 ) F_19 ( L_80 ) ;
if ( V_10 ) F_19 ( L_81 ) ;
if ( V_11 ) F_19 ( L_82 ) ;
if ( V_12 ) F_19 ( L_83 ) ;
if ( V_13 ) F_19 ( L_84 ) ;
if ( V_15 ) F_19 ( L_85 ) ;
if ( V_16 ) F_19 ( L_86 ) ;
if ( V_17 ) F_19 ( L_87 ) ;
if ( V_18 ) F_19 ( L_88 ) ;
#ifdef F_2
if ( V_19 ) {
F_19 ( L_89 ) ;
F_19 ( L_90 ) ;
F_19 ( L_91 ) ;
}
#endif
if ( V_14 ) F_19 ( L_92 ) ;
if ( V_7 ) F_19 ( L_93 ) ;
if ( V_8 ) {
F_19 ( L_94 ) ;
F_19 ( L_95 ) ;
F_19 ( L_96 ) ;
}
printf ( L_97 ) ;
}
static void
F_21 ( const T_1 * V_54 , T_4 * V_26 )
{
const T_1 * V_55 , * V_56 ;
V_55 = F_10 ( V_26 -> V_58 ) ;
V_56 = F_11 ( V_26 -> V_59 ) ;
if ( V_54 ) {
F_18 () ;
printf ( L_70 , V_54 ) ;
F_18 () ;
}
if ( V_2 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , V_55 ) ;
F_18 () ;
}
if ( V_3 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , V_56 ) ;
F_18 () ;
}
if ( V_8 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , F_12 ( V_26 -> V_65 ) ) ;
F_18 () ;
}
if ( V_4 ) {
F_17 () ;
F_18 () ;
if ( V_26 -> V_66 )
printf ( L_98 , V_26 -> V_67 ) ;
else
printf ( L_99 ) ;
F_18 () ;
if ( V_26 -> V_68 > 0 ) {
F_17 () ;
F_18 () ;
printf ( L_98 , V_26 -> V_69 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_98 , V_26 -> V_68 ) ;
F_18 () ;
}
else {
F_17 () ;
F_18 () ;
printf ( L_19 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_19 ) ;
F_18 () ;
}
}
if ( V_5 ) {
F_17 () ;
F_18 () ;
printf ( L_98 , V_26 -> V_31 ) ;
F_18 () ;
}
if ( V_6 ) {
F_17 () ;
F_18 () ;
printf ( L_46 V_72 L_100 , V_26 -> V_73 ) ;
F_18 () ;
}
if ( V_10 ) {
F_17 () ;
F_18 () ;
printf ( L_46 V_72 L_101 , V_26 -> V_75 ) ;
F_18 () ;
}
if ( V_11 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , F_7 ( & V_26 -> V_76 , V_26 -> V_77 , V_26 , FALSE ) ) ;
F_18 () ;
}
if ( V_12 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , F_5 ( & V_26 -> V_78 , V_26 -> V_79 , V_26 ) ) ;
F_18 () ;
}
if ( V_13 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , F_5 ( & V_26 -> V_80 , V_26 -> V_81 , V_26 ) ) ;
F_18 () ;
}
if ( V_15 ) {
F_17 () ;
F_18 () ;
if ( V_26 -> V_30 )
printf ( L_102 , V_26 -> V_82 ) ;
else
printf ( L_19 ) ;
F_18 () ;
}
if ( V_16 ) {
F_17 () ;
F_18 () ;
if ( V_26 -> V_30 )
printf ( L_102 , V_26 -> V_82 * 8 ) ;
else
printf ( L_19 ) ;
F_18 () ;
}
if ( V_17 ) {
F_17 () ;
F_18 () ;
printf ( L_102 , V_26 -> V_86 ) ;
F_18 () ;
}
if ( V_18 ) {
F_17 () ;
F_18 () ;
if ( V_26 -> V_30 )
printf ( L_102 , V_26 -> V_87 ) ;
else
printf ( L_19 ) ;
F_18 () ;
}
#ifdef F_2
if ( V_19 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , V_89 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_70 , V_90 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_70 , V_91 ) ;
F_18 () ;
}
#endif
if ( V_14 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , F_4 ( V_26 -> V_20 ) ) ;
F_18 () ;
}
if ( V_7 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , V_26 -> V_92 ) ;
F_18 () ;
}
if ( V_8 ) {
F_17 () ;
F_18 () ;
printf ( L_70 , V_26 -> V_93 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_70 , V_26 -> V_94 ) ;
F_18 () ;
F_17 () ;
F_18 () ;
printf ( L_70 , V_26 -> V_95 ) ;
F_18 () ;
}
printf ( L_97 ) ;
}
static void
F_22 ( T_4 * V_26 )
{
T_7 V_62 ;
F_15 ( V_26 != NULL ) ;
F_14 ( V_26 -> V_92 ) ;
V_26 -> V_92 = NULL ;
F_14 ( V_26 -> V_93 ) ;
V_26 -> V_93 = NULL ;
F_14 ( V_26 -> V_94 ) ;
V_26 -> V_94 = NULL ;
F_14 ( V_26 -> V_95 ) ;
V_26 -> V_95 = NULL ;
F_14 ( V_26 -> V_64 ) ;
V_26 -> V_64 = NULL ;
F_14 ( V_26 -> V_100 ) ;
V_26 -> V_100 = NULL ;
if ( V_26 -> V_97 ) {
for ( V_62 = 0 ; V_62 < V_26 -> V_97 -> V_98 ; V_62 ++ ) {
T_1 * V_99 = F_16 ( V_26 -> V_97 , T_1 * , V_62 ) ;
F_14 ( V_99 ) ;
}
F_23 ( V_26 -> V_97 , TRUE ) ;
}
V_26 -> V_97 = NULL ;
}
static void
F_24 ( T_1 * V_104 )
{
T_1 * V_105 ;
if ( V_104 ) {
V_105 = V_104 ;
while ( * V_105 != '\0' ) {
if ( * V_105 == '\n' )
* V_105 = ' ' ;
if ( * V_105 == '\r' )
* V_105 = ' ' ;
V_105 ++ ;
}
}
}
static int
F_25 ( T_8 * V_106 , const char * V_54 )
{
int V_107 = 0 ;
int V_108 ;
T_1 * V_109 ;
V_83 V_110 ;
V_83 V_111 ;
T_9 V_112 = 0 ;
V_83 V_113 = 0 ;
T_9 V_69 = 0xffffffff ;
T_9 V_68 = 0 ;
const struct V_114 * V_115 ;
T_4 V_26 ;
T_5 V_116 = TRUE ;
T_3 V_78 ;
int V_79 ;
T_3 V_80 ;
int V_81 ;
T_3 V_117 ;
T_3 V_118 ;
T_5 V_119 = FALSE ;
T_2 V_20 = V_21 ;
const T_10 * V_120 ;
T_7 V_62 ;
T_11 * V_121 ;
F_15 ( V_106 != NULL ) ;
F_15 ( V_54 != NULL ) ;
F_26 ( & V_78 ) ;
V_79 = V_122 ;
F_26 ( & V_80 ) ;
V_81 = V_122 ;
F_26 ( & V_117 ) ;
F_26 ( & V_118 ) ;
V_26 . V_92 = NULL ;
V_26 . V_93 = NULL ;
V_26 . V_94 = NULL ;
V_26 . V_95 = NULL ;
V_26 . V_64 = F_27 ( int , V_63 ) ;
V_121 = F_28 ( V_106 ) ;
F_15 ( V_121 -> V_123 != NULL ) ;
V_26 . V_96 = V_121 -> V_123 -> V_98 ;
V_26 . V_100 = F_27 ( T_9 , V_26 . V_96 ) ;
V_26 . V_124 = 0 ;
V_26 . V_97 = F_29 ( FALSE , FALSE , sizeof( T_1 * ) , V_26 . V_96 ) ;
for ( V_62 = 0 ; V_62 < V_26 . V_96 ; V_62 ++ ) {
const T_12 * V_125 = & F_16 ( V_121 -> V_123 , T_12 , V_62 ) ;
T_1 * V_99 = F_30 ( V_125 , 21 , L_97 ) ;
F_31 ( V_26 . V_97 , V_99 ) ;
}
F_14 ( V_121 ) ;
V_121 = NULL ;
while ( F_32 ( V_106 , & V_108 , & V_109 , & V_111 ) ) {
V_115 = F_33 ( V_106 ) ;
if ( V_115 -> V_126 & V_127 ) {
V_118 = V_117 ;
V_117 = V_115 -> V_128 ;
if ( V_112 == 0 ) {
V_78 = V_115 -> V_128 ;
V_79 = V_115 -> V_129 ;
V_80 = V_115 -> V_128 ;
V_81 = V_115 -> V_129 ;
V_118 = V_115 -> V_128 ;
}
if ( F_34 ( & V_117 , & V_118 ) < 0 ) {
V_20 = V_22 ;
}
if ( F_34 ( & V_117 , & V_78 ) < 0 ) {
V_78 = V_117 ;
V_79 = V_115 -> V_129 ;
}
if ( F_34 ( & V_117 , & V_80 ) > 0 ) {
V_80 = V_117 ;
V_81 = V_115 -> V_129 ;
}
} else {
V_116 = FALSE ;
if ( V_20 != V_22 )
V_20 = V_23 ;
}
if ( V_115 -> V_130 == V_131 ) {
V_113 += V_115 -> V_98 ;
V_112 ++ ;
if ( V_115 -> V_132 < V_115 -> V_98 ) {
if ( V_115 -> V_132 < V_69 )
V_69 = V_115 -> V_132 ;
if ( V_115 -> V_132 > V_68 )
V_68 = V_115 -> V_132 ;
}
if ( F_35 ( V_106 ) == V_61 ) {
if ( ( V_115 -> V_133 > 0 ) && ( V_115 -> V_133 < V_63 ) ) {
V_26 . V_64 [ V_115 -> V_133 ] += 1 ;
} else {
fprintf ( V_134 , L_103 ,
V_115 -> V_133 , V_112 , V_54 ) ;
}
}
if ( V_115 -> V_126 & V_135 ) {
if ( V_115 -> V_136 < V_26 . V_96 ) {
V_26 . V_100 [ V_115 -> V_136 ] += 1 ;
}
else {
V_26 . V_124 += 1 ;
}
}
else {
if ( V_26 . V_96 != 0 ) {
V_26 . V_100 [ 0 ] += 1 ;
}
else {
V_26 . V_124 += 1 ;
}
}
}
}
if ( V_108 != 0 ) {
fprintf ( V_134 ,
L_104 ,
V_112 , V_54 , F_36 ( V_108 ) ) ;
if ( V_108 == V_137 ) {
V_107 = 1 ;
fprintf ( V_134 ,
L_105 ) ;
} else {
if ( V_109 != NULL ) {
fprintf ( V_134 , L_106 , V_109 ) ;
F_14 ( V_109 ) ;
}
F_22 ( & V_26 ) ;
return 1 ;
}
}
V_110 = F_37 ( V_106 , & V_108 ) ;
if ( V_110 == - 1 ) {
fprintf ( V_134 ,
L_107 ,
V_54 , F_38 ( V_108 ) ) ;
F_22 ( & V_26 ) ;
return 1 ;
}
V_26 . V_73 = V_110 ;
V_26 . V_58 = F_39 ( V_106 ) ;
V_26 . V_60 = F_40 ( V_106 ) ;
V_26 . V_59 = F_35 ( V_106 ) ;
V_26 . V_65 = F_41 ( V_106 ) ;
V_26 . V_67 = F_42 ( V_106 ) ;
if ( V_26 . V_67 > 0 )
V_26 . V_66 = TRUE ;
else
V_26 . V_66 = FALSE ;
V_26 . V_69 = V_69 ;
V_26 . V_68 = V_68 ;
V_26 . V_31 = V_112 ;
V_26 . V_30 = V_116 ;
V_26 . V_78 = V_78 ;
V_26 . V_79 = V_79 ;
V_26 . V_80 = V_80 ;
V_26 . V_81 = V_81 ;
F_43 ( & V_26 . V_76 , & V_80 , & V_78 ) ;
if ( V_26 . V_81 > V_26 . V_79 )
V_26 . V_77 = V_26 . V_81 ;
else
V_26 . V_77 = V_26 . V_79 ;
V_26 . V_119 = V_119 ;
V_26 . V_20 = V_20 ;
V_26 . V_75 = V_113 ;
V_26 . V_82 = 0.0 ;
V_26 . V_87 = 0.0 ;
V_26 . V_86 = 0.0 ;
if ( V_112 > 0 ) {
double V_138 = F_44 ( & V_80 ) - F_44 ( & V_78 ) ;
if ( V_138 > 0.0 ) {
V_26 . V_82 = ( double ) V_113 / V_138 ;
V_26 . V_87 = ( double ) V_112 / V_138 ;
}
V_26 . V_86 = ( double ) V_113 / V_112 ;
}
V_120 = F_45 ( V_106 ) ;
if ( V_120 ) {
V_26 . V_92 = F_46 ( V_120 -> V_139 ) ;
V_26 . V_93 = F_46 ( V_120 -> V_140 ) ;
V_26 . V_94 = F_46 ( V_120 -> V_141 ) ;
V_26 . V_95 = F_46 ( V_120 -> V_142 ) ;
}
F_24 ( V_26 . V_92 ) ;
F_24 ( V_26 . V_93 ) ;
F_24 ( V_26 . V_94 ) ;
F_24 ( V_26 . V_95 ) ;
if ( V_143 ) {
F_9 ( V_54 , & V_26 ) ;
} else {
F_21 ( V_54 , & V_26 ) ;
}
F_22 ( & V_26 ) ;
return V_107 ;
}
static void
F_47 ( T_13 * V_144 )
{
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_108 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_109 ) ;
fprintf ( V_144 , L_110 ) ;
fprintf ( V_144 , L_111 ) ;
fprintf ( V_144 , L_112 ) ;
fprintf ( V_144 , L_113 ) ;
#ifdef F_2
fprintf ( V_144 , L_114 ) ;
#endif
fprintf ( V_144 , L_115 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_116 ) ;
fprintf ( V_144 , L_117 ) ;
fprintf ( V_144 , L_118 ) ;
fprintf ( V_144 , L_119 ) ;
fprintf ( V_144 , L_120 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_121 ) ;
fprintf ( V_144 , L_122 ) ;
fprintf ( V_144 , L_123 ) ;
fprintf ( V_144 , L_124 ) ;
fprintf ( V_144 , L_125 ) ;
fprintf ( V_144 , L_126 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_127 ) ;
fprintf ( V_144 , L_128 ) ;
fprintf ( V_144 , L_129 ) ;
fprintf ( V_144 , L_130 ) ;
fprintf ( V_144 , L_131 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_132 ) ;
fprintf ( V_144 , L_133 ) ;
fprintf ( V_144 , L_134 ) ;
fprintf ( V_144 , L_135 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_136 ) ;
fprintf ( V_144 , L_137 ) ;
fprintf ( V_144 , L_138 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_139 ) ;
fprintf ( V_144 , L_140 ) ;
fprintf ( V_144 , L_141 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_142 ) ;
fprintf ( V_144 , L_143 ) ;
fprintf ( V_144 , L_144 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_145 ) ;
fprintf ( V_144 , L_146 ) ;
fprintf ( V_144 , L_147 ) ;
fprintf ( V_144 , L_148 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_149 ) ;
fprintf ( V_144 , L_150 ) ;
fprintf ( V_144 , L_97 ) ;
fprintf ( V_144 , L_151 ) ;
fprintf ( V_144 , L_152 ) ;
#ifndef F_2
fprintf ( V_144 , L_153 ) ;
#endif
}
static void
F_48 ( const char * T_14 V_145 , T_15 T_16 V_145 )
{
return;
}
static void
F_49 ( const unsigned char * V_146 , T_17 V_147 , char * V_104 ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < ( int ) V_147 ; V_62 ++ ) {
F_6 ( V_104 + ( V_62 * 2 ) , 3 , L_154 , V_146 [ V_62 ] ) ;
}
}
static void
F_50 ( T_18 * V_104 )
{
F_51 ( V_104 , L_155 ) ;
#ifdef F_52
F_51 ( V_104 , L_156 ) ;
#ifdef F_53
F_51 ( V_104 , F_53 ) ;
#else
F_51 ( V_104 , L_157 ) ;
#endif
#else
F_51 ( V_104 , L_158 ) ;
#endif
}
static void
F_54 ( T_18 * V_104 )
{
#if F_55 ( F_52 ) && ! F_55 ( V_148 )
F_56 ( V_104 , L_159 , F_57 () ) ;
#endif
}
int
main ( int V_149 , char * V_150 [] )
{
T_18 * V_151 ;
T_18 * V_152 ;
T_8 * V_106 ;
int V_108 ;
T_1 * V_109 ;
int V_153 ;
int V_154 ;
F_58 (cast-qual)
static const struct V_155 V_156 [] = {
{ ( char * ) L_160 , V_157 , NULL , 'h' } ,
{ ( char * ) L_161 , V_157 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
F_59 (cast-qual)
int V_107 = 0 ;
#ifdef F_60
char * V_158 ;
#endif
#ifdef F_2
T_13 * V_159 ;
char * V_160 = NULL ;
T_19 V_161 = NULL ;
T_17 V_162 ;
#endif
setlocale ( V_163 , L_21 ) ;
V_151 = F_61 ( NULL , F_50 ) ;
V_152 = F_62 ( F_54 ) ;
F_63 ( L_162
L_97
L_70
L_97
L_70 ,
F_64 () , V_151 -> V_104 , V_152 -> V_104 ) ;
#ifdef V_148
F_65 ( V_149 , V_150 ) ;
F_66 () ;
#endif
F_67 () ;
F_68 () ;
#ifdef F_60
if ( ( V_158 = F_69 ( V_150 [ 0 ] , ( void * )main ) ) ) {
F_70 ( L_163 , V_158 ) ;
F_14 ( V_158 ) ;
} else {
F_71 () ;
F_72 ( F_48 , NULL , NULL , NULL ) ;
F_73 () ;
F_74 () ;
}
#endif
while ( ( V_153 = F_75 ( V_149 , V_150 , L_164 V_164 L_165 , V_156 , NULL ) ) != - 1 ) {
switch ( V_153 ) {
case 't' :
if ( V_1 ) F_3 () ;
V_2 = TRUE ;
break;
case 'E' :
if ( V_1 ) F_3 () ;
V_3 = TRUE ;
break;
case 'l' :
if ( V_1 ) F_3 () ;
V_4 = TRUE ;
break;
case 'c' :
if ( V_1 ) F_3 () ;
V_5 = TRUE ;
break;
case 's' :
if ( V_1 ) F_3 () ;
V_6 = TRUE ;
break;
case 'd' :
if ( V_1 ) F_3 () ;
V_10 = TRUE ;
break;
case 'u' :
if ( V_1 ) F_3 () ;
V_11 = TRUE ;
break;
case 'a' :
if ( V_1 ) F_3 () ;
V_12 = TRUE ;
break;
case 'e' :
if ( V_1 ) F_3 () ;
V_13 = TRUE ;
break;
case 'S' :
V_32 = TRUE ;
break;
case 'y' :
if ( V_1 ) F_3 () ;
V_15 = TRUE ;
break;
case 'i' :
if ( V_1 ) F_3 () ;
V_16 = TRUE ;
break;
case 'z' :
if ( V_1 ) F_3 () ;
V_17 = TRUE ;
break;
case 'x' :
if ( V_1 ) F_3 () ;
V_18 = TRUE ;
break;
#ifdef F_2
case 'H' :
if ( V_1 ) F_3 () ;
V_19 = TRUE ;
break;
#endif
case 'o' :
if ( V_1 ) F_3 () ;
V_14 = TRUE ;
break;
case 'k' :
if ( V_1 ) F_3 () ;
V_7 = TRUE ;
break;
case 'F' :
if ( V_1 ) F_3 () ;
V_8 = TRUE ;
break;
case 'I' :
if ( V_1 ) F_3 () ;
V_9 = TRUE ;
break;
case 'C' :
V_165 = FALSE ;
break;
case 'A' :
F_1 () ;
break;
case 'L' :
V_143 = TRUE ;
break;
case 'T' :
V_143 = FALSE ;
break;
case 'M' :
V_70 = TRUE ;
break;
case 'R' :
V_166 = TRUE ;
break;
case 'r' :
V_166 = FALSE ;
break;
case 'N' :
V_102 = '\0' ;
break;
case 'q' :
V_102 = '\'' ;
break;
case 'Q' :
V_102 = '"' ;
break;
case 'B' :
V_101 = '\t' ;
break;
case 'm' :
V_101 = ',' ;
break;
case 'b' :
V_101 = ' ' ;
break;
case 'h' :
printf ( L_162
L_166
L_167 ,
F_64 () ) ;
F_47 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_76 ( L_168 , V_151 , V_152 ) ;
F_77 ( V_151 , TRUE ) ;
F_77 ( V_152 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_47 ( V_134 ) ;
exit ( 1 ) ;
break;
}
}
if ( ( V_149 - V_167 ) < 1 ) {
F_47 ( V_134 ) ;
exit ( 1 ) ;
}
if ( ! V_143 && V_166 ) {
F_20 () ;
}
#ifdef F_2
if ( V_19 ) {
F_78 ( NULL ) ;
F_79 ( & V_161 , V_168 , 0 ) ;
if ( V_161 ) {
F_80 ( V_161 , V_169 ) ;
F_80 ( V_161 , V_170 ) ;
}
V_160 = ( char * ) F_81 ( V_171 ) ;
}
#endif
V_154 = 0 ;
for ( V_153 = V_167 ; V_153 < V_149 ; V_153 ++ ) {
#ifdef F_2
F_82 ( V_89 , L_169 , V_172 ) ;
F_82 ( V_90 , L_169 , V_172 ) ;
F_82 ( V_91 , L_169 , V_172 ) ;
if ( V_19 ) {
V_159 = F_83 ( V_150 [ V_153 ] , L_170 ) ;
if ( V_159 && V_161 ) {
while( ( V_162 = fread ( V_160 , 1 , V_171 , V_159 ) ) > 0 ) {
F_84 ( V_161 , V_160 , V_162 ) ;
}
F_85 ( V_161 ) ;
F_49 ( F_86 ( V_161 , V_168 ) , V_173 , V_89 ) ;
F_49 ( F_86 ( V_161 , V_169 ) , V_174 , V_90 ) ;
F_49 ( F_86 ( V_161 , V_170 ) , V_175 , V_91 ) ;
}
if ( V_159 ) fclose ( V_159 ) ;
if ( V_161 ) F_87 ( V_161 ) ;
}
#endif
V_106 = F_88 ( V_150 [ V_153 ] , V_176 , & V_108 , & V_109 , FALSE ) ;
if ( ! V_106 ) {
fprintf ( V_134 , L_171 , V_150 [ V_153 ] ,
F_36 ( V_108 ) ) ;
if ( V_109 != NULL ) {
fprintf ( V_134 , L_106 , V_109 ) ;
F_14 ( V_109 ) ;
}
V_154 = 1 ;
if ( ! V_165 )
exit ( 1 ) ;
}
if ( V_106 ) {
if ( ( V_153 > V_167 ) && ( V_143 ) )
printf ( L_97 ) ;
V_107 = F_25 ( V_106 , V_150 [ V_153 ] ) ;
F_89 ( V_106 ) ;
if ( V_107 )
exit ( V_107 ) ;
}
}
return V_154 ;
}
