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
V_36 ,
V_24 -> V_37 / 100000000 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_7 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 10000000 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_8 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 1000000 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_9 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 1000 ) ;
break;
case V_41 :
F_6 ( V_27 , sizeof V_27 ,
L_10 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 ) ;
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
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ) ;
break;
case V_35 :
F_6 ( V_27 , sizeof V_27 ,
L_14 ,
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ,
V_36 ,
V_24 -> V_37 / 100000000 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_15 ,
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ,
V_36 ,
V_24 -> V_37 / 10000000 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_16 ,
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ,
V_36 ,
V_24 -> V_37 / 1000000 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_17 ,
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ,
V_36 ,
V_24 -> V_37 / 1000 ) ;
break;
case V_41 :
F_6 ( V_27 , sizeof V_27 ,
L_18 ,
V_29 -> V_42 + 1900 ,
V_29 -> V_43 + 1 ,
V_29 -> V_44 ,
V_29 -> V_45 ,
V_29 -> V_46 ,
V_29 -> V_47 ,
V_36 ,
V_24 -> V_37 ) ;
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
F_7 ( T_3 * V_24 , int V_25 , T_4 * V_26 , T_5 V_48 )
{
const T_1 * V_49 = V_48 ? L_20 : L_21 ;
const T_1 * V_50 = V_48 ? L_22 : L_21 ;
static T_1 V_27 [ 4 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 2 + 1 + 1 ] ;
if ( V_26 -> V_30 && V_26 -> V_31 > 0 ) {
switch ( V_25 ) {
case V_33 :
F_6 ( V_27 , sizeof V_27 ,
L_23 ,
( unsigned long ) V_24 -> V_34 ,
V_49 ,
V_24 -> V_34 == 1 ? L_21 : V_50 ) ;
break;
case V_35 :
F_6 ( V_27 , sizeof V_27 ,
L_24 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 100000000 ,
V_49 ,
( V_24 -> V_34 == 1 && V_24 -> V_37 == 0 ) ? L_21 : V_50 ) ;
break;
case V_38 :
F_6 ( V_27 , sizeof V_27 ,
L_25 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 10000000 ,
V_49 ,
( V_24 -> V_34 == 1 && V_24 -> V_37 == 0 ) ? L_21 : V_50 ) ;
break;
case V_39 :
F_6 ( V_27 , sizeof V_27 ,
L_26 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 1000000 ,
V_49 ,
( V_24 -> V_34 == 1 && V_24 -> V_37 == 0 ) ? L_21 : V_50 ) ;
break;
case V_40 :
F_6 ( V_27 , sizeof V_27 ,
L_27 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 / 1000 ,
V_49 ,
( V_24 -> V_34 == 1 && V_24 -> V_37 == 0 ) ? L_21 : V_50 ) ;
break;
case V_41 :
F_6 ( V_27 , sizeof V_27 ,
L_28 ,
( unsigned long ) V_24 -> V_34 ,
V_36 ,
V_24 -> V_37 ,
V_49 ,
( V_24 -> V_34 == 1 && V_24 -> V_37 == 0 ) ? L_21 : V_50 ) ;
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
static void F_8 ( const T_1 * V_51 , T_6 V_52 , const T_1 * V_53 , double V_54 ) {
if ( V_54 > 0.0 )
printf ( L_29 , V_51 , V_52 , V_54 , V_53 ) ;
else
printf ( L_30 , V_51 ) ;
}
static void
F_9 ( T_1 * V_55 )
{
T_1 * V_56 ;
if ( V_55 ) {
V_56 = V_55 ;
while ( * V_56 != '\0' ) {
if ( * V_56 == '\n' )
* V_56 = ' ' ;
if ( * V_56 == '\r' )
* V_56 = ' ' ;
V_56 ++ ;
}
}
}
static void
F_10 ( const char * V_57 , const char * V_58 )
{
char * V_55 ;
if ( V_58 != NULL && V_58 [ 0 ] != '\0' ) {
V_55 = F_11 ( V_58 ) ;
F_9 ( V_55 ) ;
printf ( L_31 , V_57 , V_55 ) ;
F_12 ( V_55 ) ;
}
}
static void
F_13 ( const T_1 * V_59 , T_4 * V_26 )
{
const T_1 * V_60 , * V_61 ;
T_1 * V_62 ;
V_60 = F_14 ( V_26 -> V_63 ) ;
V_61 = F_15 ( V_26 -> V_64 ) ;
if ( V_59 ) printf ( L_32 , V_59 ) ;
if ( V_2 ) printf ( L_33 ,
V_60 ,
V_26 -> V_65 ? L_34 : L_21 ) ;
if ( V_3 ) {
printf ( L_35 , V_61 ) ;
if ( V_26 -> V_64 == V_66 ) {
int V_67 ;
printf ( L_36 ) ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_26 -> V_69 [ V_67 ] > 0 )
printf ( L_37 ,
F_15 ( V_67 ) , V_26 -> V_69 [ V_67 ] ) ;
}
}
}
if ( V_8 ) {
printf ( L_38 ,
F_16 ( V_26 -> V_70 ) , V_26 -> V_70 ) ;
}
if ( V_4 && V_26 -> V_71 )
printf ( L_39 , V_26 -> V_72 ) ;
else if ( V_4 && ! V_26 -> V_71 )
printf ( L_40 ) ;
if ( V_26 -> V_73 > 0 ) {
if ( V_26 -> V_74 == V_26 -> V_73 )
printf ( L_41 , V_26 -> V_74 ) ;
else
printf ( L_42 ,
V_26 -> V_74 , V_26 -> V_73 ) ;
}
if ( V_5 ) {
printf ( L_43 ) ;
if ( V_75 ) {
printf ( L_44 , V_26 -> V_31 ) ;
} else {
V_62 = F_17 ( V_26 -> V_31 , V_76 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
if ( V_6 ) {
printf ( L_46 ) ;
if ( V_75 ) {
printf ( L_47 V_77 L_48 , V_26 -> V_78 ) ;
} else {
V_62 = F_17 ( V_26 -> V_78 , V_79 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
if ( V_10 ) {
printf ( L_49 ) ;
if ( V_75 ) {
printf ( L_47 V_77 L_50 , V_26 -> V_80 ) ;
} else {
V_62 = F_17 ( V_26 -> V_80 , V_79 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
if ( V_26 -> V_30 ) {
if ( V_11 )
printf ( L_51 , F_7 ( & V_26 -> V_81 , V_26 -> V_82 , V_26 , TRUE ) ) ;
if ( V_12 )
printf ( L_52 , F_5 ( & V_26 -> V_83 , V_26 -> V_84 , V_26 ) ) ;
if ( V_13 )
printf ( L_53 , F_5 ( & V_26 -> V_85 , V_26 -> V_86 , V_26 ) ) ;
if ( V_15 ) {
printf ( L_54 ) ;
if ( V_75 ) {
F_8 ( L_21 , 2 , L_55 , V_26 -> V_87 ) ;
} else {
V_62 = F_17 ( ( V_88 ) V_26 -> V_87 , V_89 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
if ( V_16 ) {
printf ( L_56 ) ;
if ( V_75 ) {
F_8 ( L_21 , 2 , L_57 , V_26 -> V_87 * 8 ) ;
} else {
V_62 = F_17 ( ( V_88 ) ( V_26 -> V_87 * 8 ) , V_90 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
}
if ( V_17 ) printf ( L_58 , V_26 -> V_91 ) ;
if ( V_26 -> V_30 ) {
if ( V_18 ) {
printf ( L_59 ) ;
if ( V_75 ) {
F_8 ( L_21 , 2 , L_60 , V_26 -> V_92 ) ;
} else {
V_62 = F_17 ( ( V_88 ) V_26 -> V_92 , V_93 ) ;
printf ( L_45 , V_62 ) ;
F_12 ( V_62 ) ;
}
}
}
#ifdef F_2
if ( V_19 ) {
printf ( L_61 , V_94 ) ;
printf ( L_62 , V_95 ) ;
printf ( L_63 , V_96 ) ;
}
#endif
if ( V_14 ) printf ( L_64 , F_4 ( V_26 -> V_20 ) ) ;
if ( V_26 -> V_97 != NULL ) {
if ( V_7 ) {
unsigned int V_67 ;
char * V_55 ;
for ( V_67 = 0 ; F_18 ( V_26 -> V_97 , V_98 , V_67 , & V_55 ) == V_99 ; V_67 ++ ) {
F_10 ( L_65 , V_55 ) ;
}
}
if ( V_8 ) {
char * V_55 ;
if ( F_19 ( V_26 -> V_97 , V_100 , & V_55 ) == V_99 )
F_10 ( L_66 , V_55 ) ;
if ( F_19 ( V_26 -> V_97 , V_101 , & V_55 ) == V_99 )
F_10 ( L_67 , V_55 ) ;
if ( F_19 ( V_26 -> V_97 , V_102 , & V_55 ) == V_99 )
F_10 ( L_68 , V_55 ) ;
}
if ( V_9 && V_26 -> V_103 != 0 ) {
T_7 V_67 ;
F_20 ( V_26 -> V_103 == V_26 -> V_104 -> V_105 ) ;
printf ( L_69 , V_26 -> V_103 ) ;
for ( V_67 = 0 ; V_67 < V_26 -> V_104 -> V_105 ; V_67 ++ ) {
T_1 * V_106 = F_21 ( V_26 -> V_104 , T_1 * , V_67 ) ;
printf ( L_70 , V_67 ) ;
printf ( L_71 , V_106 ) ;
printf ( L_72 , F_21 ( V_26 -> V_107 , V_108 , V_67 ) ) ;
}
}
}
}
static void
F_22 ( void )
{
if ( V_109 ) putchar ( V_109 ) ;
}
static void
F_23 ( void )
{
if ( V_110 ) putchar ( V_110 ) ;
}
static void
F_24 ( const T_1 * V_111 )
{
F_22 () ;
F_23 () ;
printf ( L_71 , V_111 ) ;
F_23 () ;
}
static void
F_25 ( void )
{
F_23 () ;
printf ( L_73 ) ;
F_23 () ;
if ( V_2 ) F_24 ( L_74 ) ;
if ( V_3 ) F_24 ( L_75 ) ;
if ( V_8 ) F_24 ( L_76 ) ;
if ( V_4 ) F_24 ( L_77 ) ;
if ( V_4 ) F_24 ( L_78 ) ;
if ( V_4 ) F_24 ( L_79 ) ;
if ( V_5 ) F_24 ( L_80 ) ;
if ( V_6 ) F_24 ( L_81 ) ;
if ( V_10 ) F_24 ( L_82 ) ;
if ( V_11 ) F_24 ( L_83 ) ;
if ( V_12 ) F_24 ( L_84 ) ;
if ( V_13 ) F_24 ( L_85 ) ;
if ( V_15 ) F_24 ( L_86 ) ;
if ( V_16 ) F_24 ( L_87 ) ;
if ( V_17 ) F_24 ( L_88 ) ;
if ( V_18 ) F_24 ( L_89 ) ;
#ifdef F_2
if ( V_19 ) {
F_24 ( L_90 ) ;
F_24 ( L_91 ) ;
F_24 ( L_92 ) ;
}
#endif
if ( V_14 ) F_24 ( L_93 ) ;
if ( V_7 ) F_24 ( L_94 ) ;
if ( V_8 ) {
F_24 ( L_95 ) ;
F_24 ( L_96 ) ;
F_24 ( L_97 ) ;
}
printf ( L_98 ) ;
}
static void
F_26 ( const T_1 * V_59 , T_4 * V_26 )
{
const T_1 * V_60 , * V_61 ;
V_60 = F_14 ( V_26 -> V_63 ) ;
V_61 = F_15 ( V_26 -> V_64 ) ;
if ( V_59 ) {
F_23 () ;
printf ( L_71 , V_59 ) ;
F_23 () ;
}
if ( V_2 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_60 ) ;
F_23 () ;
}
if ( V_3 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_61 ) ;
F_23 () ;
}
if ( V_8 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , F_16 ( V_26 -> V_70 ) ) ;
F_23 () ;
}
if ( V_4 ) {
F_22 () ;
F_23 () ;
if ( V_26 -> V_71 )
printf ( L_99 , V_26 -> V_72 ) ;
else
printf ( L_100 ) ;
F_23 () ;
if ( V_26 -> V_73 > 0 ) {
F_22 () ;
F_23 () ;
printf ( L_99 , V_26 -> V_74 ) ;
F_23 () ;
F_22 () ;
F_23 () ;
printf ( L_99 , V_26 -> V_73 ) ;
F_23 () ;
}
else {
F_22 () ;
F_23 () ;
printf ( L_19 ) ;
F_23 () ;
F_22 () ;
F_23 () ;
printf ( L_19 ) ;
F_23 () ;
}
}
if ( V_5 ) {
F_22 () ;
F_23 () ;
printf ( L_99 , V_26 -> V_31 ) ;
F_23 () ;
}
if ( V_6 ) {
F_22 () ;
F_23 () ;
printf ( L_47 V_77 L_101 , V_26 -> V_78 ) ;
F_23 () ;
}
if ( V_10 ) {
F_22 () ;
F_23 () ;
printf ( L_47 V_77 L_102 , V_26 -> V_80 ) ;
F_23 () ;
}
if ( V_11 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , F_7 ( & V_26 -> V_81 , V_26 -> V_82 , V_26 , FALSE ) ) ;
F_23 () ;
}
if ( V_12 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , F_5 ( & V_26 -> V_83 , V_26 -> V_84 , V_26 ) ) ;
F_23 () ;
}
if ( V_13 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , F_5 ( & V_26 -> V_85 , V_26 -> V_86 , V_26 ) ) ;
F_23 () ;
}
if ( V_15 ) {
F_22 () ;
F_23 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_87 ) ;
else
printf ( L_19 ) ;
F_23 () ;
}
if ( V_16 ) {
F_22 () ;
F_23 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_87 * 8 ) ;
else
printf ( L_19 ) ;
F_23 () ;
}
if ( V_17 ) {
F_22 () ;
F_23 () ;
printf ( L_103 , V_26 -> V_91 ) ;
F_23 () ;
}
if ( V_18 ) {
F_22 () ;
F_23 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_92 ) ;
else
printf ( L_19 ) ;
F_23 () ;
}
#ifdef F_2
if ( V_19 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_94 ) ;
F_23 () ;
F_22 () ;
F_23 () ;
printf ( L_71 , V_95 ) ;
F_23 () ;
F_22 () ;
F_23 () ;
printf ( L_71 , V_96 ) ;
F_23 () ;
}
#endif
if ( V_14 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , F_4 ( V_26 -> V_20 ) ) ;
F_23 () ;
}
if ( V_26 -> V_97 != NULL ) {
if ( V_7 ) {
unsigned int V_67 ;
char * V_112 ;
for ( V_67 = 0 ; F_18 ( V_26 -> V_97 , V_98 , V_67 , & V_112 ) == V_99 ; V_67 ++ ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_112 ) ;
F_23 () ;
}
}
if ( V_8 ) {
char * V_55 ;
if ( F_19 ( V_26 -> V_97 , V_100 , & V_55 ) == V_99 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_55 ) ;
F_23 () ;
}
if ( F_19 ( V_26 -> V_97 , V_101 , & V_55 ) == V_99 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_55 ) ;
F_23 () ;
}
if ( F_19 ( V_26 -> V_97 , V_102 , & V_55 ) == V_99 ) {
F_22 () ;
F_23 () ;
printf ( L_71 , V_55 ) ;
F_23 () ;
}
}
}
printf ( L_98 ) ;
}
static void
F_27 ( T_4 * V_26 )
{
T_7 V_67 ;
F_20 ( V_26 != NULL ) ;
F_12 ( V_26 -> V_69 ) ;
V_26 -> V_69 = NULL ;
F_28 ( V_26 -> V_107 , TRUE ) ;
V_26 -> V_107 = NULL ;
if ( V_26 -> V_104 ) {
for ( V_67 = 0 ; V_67 < V_26 -> V_104 -> V_105 ; V_67 ++ ) {
T_1 * V_106 = F_21 ( V_26 -> V_104 , T_1 * , V_67 ) ;
F_12 ( V_106 ) ;
}
F_28 ( V_26 -> V_104 , TRUE ) ;
}
V_26 -> V_104 = NULL ;
}
static int
F_29 ( T_8 * V_113 , const char * V_59 )
{
int V_114 = 0 ;
int V_115 ;
T_1 * V_116 ;
V_88 V_117 ;
V_88 V_118 ;
V_108 V_119 = 0 ;
V_88 V_120 = 0 ;
V_108 V_74 = 0xffffffff ;
V_108 V_73 = 0 ;
const struct V_121 * V_122 ;
T_4 V_26 ;
T_5 V_123 = TRUE ;
T_3 V_83 ;
int V_84 ;
T_3 V_85 ;
int V_86 ;
T_3 V_124 ;
T_3 V_125 ;
T_5 V_126 = FALSE ;
T_2 V_20 = V_21 ;
T_7 V_67 ;
T_9 * V_127 ;
F_20 ( V_113 != NULL ) ;
F_20 ( V_59 != NULL ) ;
F_30 ( & V_83 ) ;
V_84 = V_128 ;
F_30 ( & V_85 ) ;
V_86 = V_128 ;
F_30 ( & V_124 ) ;
F_30 ( & V_125 ) ;
V_26 . V_97 = F_31 ( V_113 ) ;
V_26 . V_69 = F_32 ( int , V_68 ) ;
V_127 = F_33 ( V_113 ) ;
F_20 ( V_127 -> V_129 != NULL ) ;
V_26 . V_103 = V_127 -> V_129 -> V_105 ;
V_26 . V_107 = F_34 ( FALSE , TRUE , sizeof( V_108 ) , V_26 . V_103 ) ;
F_35 ( V_26 . V_107 , V_26 . V_103 ) ;
V_26 . V_130 = 0 ;
F_12 ( V_127 ) ;
V_127 = NULL ;
while ( F_36 ( V_113 , & V_115 , & V_116 , & V_118 ) ) {
V_122 = F_37 ( V_113 ) ;
if ( V_122 -> V_131 & V_132 ) {
V_125 = V_124 ;
V_124 = V_122 -> V_133 ;
if ( V_119 == 0 ) {
V_83 = V_122 -> V_133 ;
V_84 = V_122 -> V_134 ;
V_85 = V_122 -> V_133 ;
V_86 = V_122 -> V_134 ;
V_125 = V_122 -> V_133 ;
}
if ( F_38 ( & V_124 , & V_125 ) < 0 ) {
V_20 = V_22 ;
}
if ( F_38 ( & V_124 , & V_83 ) < 0 ) {
V_83 = V_124 ;
V_84 = V_122 -> V_134 ;
}
if ( F_38 ( & V_124 , & V_85 ) > 0 ) {
V_85 = V_124 ;
V_86 = V_122 -> V_134 ;
}
} else {
V_123 = FALSE ;
if ( V_20 != V_22 )
V_20 = V_23 ;
}
if ( V_122 -> V_135 == V_136 ) {
V_120 += V_122 -> V_105 ;
V_119 ++ ;
if ( V_122 -> V_137 < V_122 -> V_105 ) {
if ( V_122 -> V_137 < V_74 )
V_74 = V_122 -> V_137 ;
if ( V_122 -> V_137 > V_73 )
V_73 = V_122 -> V_137 ;
}
if ( ( V_122 -> V_138 > 0 ) && ( V_122 -> V_138 < V_68 ) ) {
V_26 . V_69 [ V_122 -> V_138 ] += 1 ;
} else {
fprintf ( V_139 , L_104 ,
V_122 -> V_138 , V_119 , V_59 ) ;
}
if ( V_122 -> V_131 & V_140 ) {
if ( V_122 -> V_141 >= V_26 . V_103 ) {
V_127 = F_33 ( V_113 ) ;
V_26 . V_103 = V_127 -> V_129 -> V_105 ;
F_35 ( V_26 . V_107 , V_26 . V_103 ) ;
F_12 ( V_127 ) ;
V_127 = NULL ;
}
if ( V_122 -> V_141 < V_26 . V_103 ) {
F_21 ( V_26 . V_107 , V_108 , V_122 -> V_141 ) += 1 ;
}
else {
V_26 . V_130 += 1 ;
}
}
else {
if ( V_26 . V_103 != 0 ) {
F_21 ( V_26 . V_107 , V_108 , 0 ) += 1 ;
}
else {
V_26 . V_130 += 1 ;
}
}
}
}
V_127 = F_33 ( V_113 ) ;
V_26 . V_104 = F_34 ( FALSE , FALSE , sizeof( T_1 * ) , V_26 . V_103 ) ;
V_26 . V_103 = V_127 -> V_129 -> V_105 ;
for ( V_67 = 0 ; V_67 < V_26 . V_103 ; V_67 ++ ) {
const T_10 V_142 = F_21 ( V_127 -> V_129 , T_10 , V_67 ) ;
T_1 * V_106 = F_39 ( V_142 , 21 , L_98 ) ;
F_40 ( V_26 . V_104 , V_106 ) ;
}
F_12 ( V_127 ) ;
V_127 = NULL ;
if ( V_115 != 0 ) {
fprintf ( V_139 ,
L_105 ,
V_119 , V_59 , F_41 ( V_115 ) ) ;
if ( V_115 == V_143 ) {
V_114 = 1 ;
fprintf ( V_139 ,
L_106 ) ;
} else {
if ( V_116 != NULL ) {
fprintf ( V_139 , L_107 , V_116 ) ;
F_12 ( V_116 ) ;
}
F_27 ( & V_26 ) ;
return 1 ;
}
}
V_117 = F_42 ( V_113 , & V_115 ) ;
if ( V_117 == - 1 ) {
fprintf ( V_139 ,
L_108 ,
V_59 , F_43 ( V_115 ) ) ;
F_27 ( & V_26 ) ;
return 1 ;
}
V_26 . V_78 = V_117 ;
V_26 . V_63 = F_44 ( V_113 ) ;
V_26 . V_65 = F_45 ( V_113 ) ;
V_26 . V_64 = F_46 ( V_113 ) ;
V_26 . V_70 = F_47 ( V_113 ) ;
V_26 . V_72 = F_48 ( V_113 ) ;
if ( V_26 . V_72 > 0 )
V_26 . V_71 = TRUE ;
else
V_26 . V_71 = FALSE ;
V_26 . V_74 = V_74 ;
V_26 . V_73 = V_73 ;
V_26 . V_31 = V_119 ;
V_26 . V_30 = V_123 ;
V_26 . V_83 = V_83 ;
V_26 . V_84 = V_84 ;
V_26 . V_85 = V_85 ;
V_26 . V_86 = V_86 ;
F_49 ( & V_26 . V_81 , & V_85 , & V_83 ) ;
if ( V_26 . V_86 > V_26 . V_84 )
V_26 . V_82 = V_26 . V_86 ;
else
V_26 . V_82 = V_26 . V_84 ;
V_26 . V_126 = V_126 ;
V_26 . V_20 = V_20 ;
V_26 . V_80 = V_120 ;
V_26 . V_87 = 0.0 ;
V_26 . V_92 = 0.0 ;
V_26 . V_91 = 0.0 ;
if ( V_119 > 0 ) {
double V_144 = F_50 ( & V_85 ) - F_50 ( & V_83 ) ;
if ( V_144 > 0.0 ) {
V_26 . V_87 = ( double ) V_120 / V_144 ;
V_26 . V_92 = ( double ) V_119 / V_144 ;
}
V_26 . V_91 = ( double ) V_120 / V_119 ;
}
if ( V_145 ) {
F_13 ( V_59 , & V_26 ) ;
} else {
F_26 ( V_59 , & V_26 ) ;
}
F_27 ( & V_26 ) ;
return V_114 ;
}
static void
F_51 ( T_11 * V_146 )
{
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_109 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_110 ) ;
fprintf ( V_146 , L_111 ) ;
fprintf ( V_146 , L_112 ) ;
fprintf ( V_146 , L_113 ) ;
fprintf ( V_146 , L_114 ) ;
#ifdef F_2
fprintf ( V_146 , L_115 ) ;
#endif
fprintf ( V_146 , L_116 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_117 ) ;
fprintf ( V_146 , L_118 ) ;
fprintf ( V_146 , L_119 ) ;
fprintf ( V_146 , L_120 ) ;
fprintf ( V_146 , L_121 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_122 ) ;
fprintf ( V_146 , L_123 ) ;
fprintf ( V_146 , L_124 ) ;
fprintf ( V_146 , L_125 ) ;
fprintf ( V_146 , L_126 ) ;
fprintf ( V_146 , L_127 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_128 ) ;
fprintf ( V_146 , L_129 ) ;
fprintf ( V_146 , L_130 ) ;
fprintf ( V_146 , L_131 ) ;
fprintf ( V_146 , L_132 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_133 ) ;
fprintf ( V_146 , L_134 ) ;
fprintf ( V_146 , L_135 ) ;
fprintf ( V_146 , L_136 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_137 ) ;
fprintf ( V_146 , L_138 ) ;
fprintf ( V_146 , L_139 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_140 ) ;
fprintf ( V_146 , L_141 ) ;
fprintf ( V_146 , L_142 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_143 ) ;
fprintf ( V_146 , L_144 ) ;
fprintf ( V_146 , L_145 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_146 ) ;
fprintf ( V_146 , L_147 ) ;
fprintf ( V_146 , L_148 ) ;
fprintf ( V_146 , L_149 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_150 ) ;
fprintf ( V_146 , L_151 ) ;
fprintf ( V_146 , L_98 ) ;
fprintf ( V_146 , L_152 ) ;
fprintf ( V_146 , L_153 ) ;
#ifndef F_2
fprintf ( V_146 , L_154 ) ;
#endif
}
static void
F_52 ( const char * T_12 V_147 , T_13 T_14 V_147 )
{
return;
}
static void
F_53 ( const unsigned char * V_148 , T_15 V_149 , char * V_55 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < ( int ) V_149 ; V_67 ++ ) {
F_6 ( V_55 + ( V_67 * 2 ) , 3 , L_155 , V_148 [ V_67 ] ) ;
}
}
int
main ( int V_150 , char * V_151 [] )
{
T_16 * V_152 ;
T_16 * V_153 ;
T_8 * V_113 ;
int V_115 ;
T_1 * V_116 ;
int V_154 ;
int V_155 ;
static const struct V_156 V_157 [] = {
{ L_156 , V_158 , NULL , 'h' } ,
{ L_157 , V_158 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_114 = 0 ;
#ifdef F_54
char * V_159 ;
#endif
#ifdef F_2
T_11 * V_160 ;
char * V_161 = NULL ;
T_17 V_162 = NULL ;
T_15 V_163 ;
#endif
setlocale ( V_164 , L_21 ) ;
V_36 = F_11 ( localeconv () -> V_36 ) ;
V_152 = F_55 ( NULL , NULL ) ;
V_153 = F_56 ( NULL ) ;
F_57 ( L_158
L_98
L_71
L_98
L_71 ,
F_58 () , V_152 -> V_55 , V_153 -> V_55 ) ;
#ifdef F_59
F_60 ( V_150 , V_151 ) ;
F_61 () ;
#endif
F_62 () ;
F_63 () ;
#ifdef F_54
if ( ( V_159 = F_64 ( V_151 [ 0 ] , main ) ) ) {
F_65 ( L_159 , V_159 ) ;
F_12 ( V_159 ) ;
} else {
F_66 () ;
F_67 ( F_52 , NULL , NULL , NULL ) ;
F_68 () ;
F_69 () ;
}
#endif
while ( ( V_154 = F_70 ( V_150 , V_151 , L_160 V_165 L_161 , V_157 , NULL ) ) != - 1 ) {
switch ( V_154 ) {
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
V_166 = FALSE ;
break;
case 'A' :
F_1 () ;
break;
case 'L' :
V_145 = TRUE ;
break;
case 'T' :
V_145 = FALSE ;
break;
case 'M' :
V_75 = TRUE ;
break;
case 'R' :
V_167 = TRUE ;
break;
case 'r' :
V_167 = FALSE ;
break;
case 'N' :
V_110 = '\0' ;
break;
case 'q' :
V_110 = '\'' ;
break;
case 'Q' :
V_110 = '"' ;
break;
case 'B' :
V_109 = '\t' ;
break;
case 'm' :
V_109 = ',' ;
break;
case 'b' :
V_109 = ' ' ;
break;
case 'h' :
printf ( L_158
L_162
L_163 ,
F_58 () ) ;
F_51 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_71 ( L_164 , V_152 , V_153 ) ;
F_72 ( V_152 , TRUE ) ;
F_72 ( V_153 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_51 ( V_139 ) ;
exit ( 1 ) ;
break;
}
}
if ( ( V_150 - V_168 ) < 1 ) {
F_51 ( V_139 ) ;
exit ( 1 ) ;
}
if ( ! V_145 && V_167 ) {
F_25 () ;
}
#ifdef F_2
if ( V_19 ) {
F_73 ( NULL ) ;
F_74 ( & V_162 , V_169 , 0 ) ;
if ( V_162 ) {
F_75 ( V_162 , V_170 ) ;
F_75 ( V_162 , V_171 ) ;
}
V_161 = ( char * ) F_76 ( V_172 ) ;
}
#endif
V_155 = 0 ;
for ( V_154 = V_168 ; V_154 < V_150 ; V_154 ++ ) {
#ifdef F_2
F_77 ( V_94 , L_165 , V_173 ) ;
F_77 ( V_95 , L_165 , V_173 ) ;
F_77 ( V_96 , L_165 , V_173 ) ;
if ( V_19 ) {
V_160 = F_78 ( V_151 [ V_154 ] , L_166 ) ;
if ( V_160 && V_162 ) {
while( ( V_163 = fread ( V_161 , 1 , V_172 , V_160 ) ) > 0 ) {
F_79 ( V_162 , V_161 , V_163 ) ;
}
F_80 ( V_162 ) ;
F_53 ( F_81 ( V_162 , V_169 ) , V_174 , V_94 ) ;
F_53 ( F_81 ( V_162 , V_170 ) , V_175 , V_95 ) ;
F_53 ( F_81 ( V_162 , V_171 ) , V_176 , V_96 ) ;
}
if ( V_160 ) fclose ( V_160 ) ;
if ( V_162 ) F_82 ( V_162 ) ;
}
#endif
V_113 = F_83 ( V_151 [ V_154 ] , V_177 , & V_115 , & V_116 , FALSE ) ;
if ( ! V_113 ) {
fprintf ( V_139 , L_167 , V_151 [ V_154 ] ,
F_41 ( V_115 ) ) ;
if ( V_116 != NULL ) {
fprintf ( V_139 , L_107 , V_116 ) ;
F_12 ( V_116 ) ;
}
V_155 = 1 ;
if ( ! V_166 )
exit ( 1 ) ;
}
if ( V_113 ) {
if ( ( V_154 > V_168 ) && ( V_145 ) )
printf ( L_98 ) ;
V_114 = F_29 ( V_113 , V_151 [ V_154 ] ) ;
F_84 ( V_113 ) ;
if ( V_114 )
exit ( V_114 ) ;
}
}
return V_155 ;
}
