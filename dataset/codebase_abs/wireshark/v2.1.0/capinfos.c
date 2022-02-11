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
F_9 ( T_1 * V_54 )
{
T_1 * V_55 ;
if ( V_54 ) {
V_55 = V_54 ;
while ( * V_55 != '\0' ) {
if ( * V_55 == '\n' )
* V_55 = ' ' ;
if ( * V_55 == '\r' )
* V_55 = ' ' ;
V_55 ++ ;
}
}
}
static void
F_10 ( const char * V_56 , const char * V_57 )
{
char * V_54 ;
if ( V_57 != NULL && V_57 [ 0 ] != '\0' ) {
V_54 = F_11 ( V_57 ) ;
F_9 ( V_54 ) ;
printf ( L_31 , V_56 , V_54 ) ;
F_12 ( V_54 ) ;
}
}
static void
F_13 ( const T_1 * V_58 , T_4 * V_26 )
{
const T_1 * V_59 , * V_60 ;
T_1 * V_61 ;
V_59 = F_14 ( V_26 -> V_62 ) ;
V_60 = F_15 ( V_26 -> V_63 ) ;
if ( V_58 ) printf ( L_32 , V_58 ) ;
if ( V_2 ) printf ( L_33 ,
V_59 ,
V_26 -> V_64 ? L_34 : L_21 ) ;
if ( V_3 ) {
printf ( L_35 , V_60 ) ;
if ( V_26 -> V_63 == V_65 ) {
int V_66 ;
printf ( L_36 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
if ( V_26 -> V_68 [ V_66 ] > 0 )
printf ( L_37 ,
F_15 ( V_66 ) , V_26 -> V_68 [ V_66 ] ) ;
}
}
}
if ( V_8 ) {
printf ( L_38 ,
F_16 ( V_26 -> V_69 ) , V_26 -> V_69 ) ;
}
if ( V_4 && V_26 -> V_70 )
printf ( L_39 , V_26 -> V_71 ) ;
else if ( V_4 && ! V_26 -> V_70 )
printf ( L_40 ) ;
if ( V_26 -> V_72 > 0 ) {
if ( V_26 -> V_73 == V_26 -> V_72 )
printf ( L_41 , V_26 -> V_73 ) ;
else
printf ( L_42 ,
V_26 -> V_73 , V_26 -> V_72 ) ;
}
if ( V_5 ) {
printf ( L_43 ) ;
if ( V_74 ) {
printf ( L_44 , V_26 -> V_31 ) ;
} else {
V_61 = F_17 ( V_26 -> V_31 , V_75 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
if ( V_6 ) {
printf ( L_46 ) ;
if ( V_74 ) {
printf ( L_47 V_76 L_48 , V_26 -> V_77 ) ;
} else {
V_61 = F_17 ( V_26 -> V_77 , V_78 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
if ( V_10 ) {
printf ( L_49 ) ;
if ( V_74 ) {
printf ( L_47 V_76 L_50 , V_26 -> V_79 ) ;
} else {
V_61 = F_17 ( V_26 -> V_79 , V_78 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
if ( V_26 -> V_30 ) {
if ( V_11 )
printf ( L_51 , F_7 ( & V_26 -> V_80 , V_26 -> V_81 , V_26 , TRUE ) ) ;
if ( V_12 )
printf ( L_52 , F_5 ( & V_26 -> V_82 , V_26 -> V_83 , V_26 ) ) ;
if ( V_13 )
printf ( L_53 , F_5 ( & V_26 -> V_84 , V_26 -> V_85 , V_26 ) ) ;
if ( V_15 ) {
printf ( L_54 ) ;
if ( V_74 ) {
F_8 ( L_21 , 2 , L_55 , V_26 -> V_86 ) ;
} else {
V_61 = F_17 ( ( V_87 ) V_26 -> V_86 , V_88 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
if ( V_16 ) {
printf ( L_56 ) ;
if ( V_74 ) {
F_8 ( L_21 , 2 , L_57 , V_26 -> V_86 * 8 ) ;
} else {
V_61 = F_17 ( ( V_87 ) ( V_26 -> V_86 * 8 ) , V_89 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
}
if ( V_17 ) printf ( L_58 , V_26 -> V_90 ) ;
if ( V_26 -> V_30 ) {
if ( V_18 ) {
printf ( L_59 ) ;
if ( V_74 ) {
F_8 ( L_21 , 2 , L_60 , V_26 -> V_91 ) ;
} else {
V_61 = F_17 ( ( V_87 ) V_26 -> V_91 , V_92 ) ;
printf ( L_45 , V_61 ) ;
F_12 ( V_61 ) ;
}
}
}
#ifdef F_2
if ( V_19 ) {
printf ( L_61 , V_93 ) ;
printf ( L_62 , V_94 ) ;
printf ( L_63 , V_95 ) ;
}
#endif
if ( V_14 ) printf ( L_64 , F_4 ( V_26 -> V_20 ) ) ;
if ( V_26 -> V_96 != NULL ) {
if ( V_7 ) {
T_7 * V_97 ;
unsigned int V_66 ;
F_18 ( V_26 -> V_96 , V_98 , & V_97 ) ;
for ( V_66 = 0 ; V_66 < V_97 -> V_99 ; V_66 ++ ) {
F_10 ( L_65 , F_19 ( V_97 , char * , V_66 ) ) ;
}
F_20 ( V_97 , TRUE ) ;
}
if ( V_8 ) {
char * V_54 ;
F_21 ( V_26 -> V_96 , V_100 , & V_54 ) ;
F_10 ( L_66 , V_54 ) ;
F_21 ( V_26 -> V_96 , V_101 , & V_54 ) ;
F_10 ( L_67 , V_54 ) ;
F_21 ( V_26 -> V_96 , V_102 , & V_54 ) ;
F_10 ( L_68 , V_54 ) ;
}
if ( V_9 && V_26 -> V_103 != 0 ) {
T_8 V_66 ;
F_22 ( V_26 -> V_103 == V_26 -> V_104 -> V_99 ) ;
printf ( L_69 , V_26 -> V_103 ) ;
for ( V_66 = 0 ; V_66 < V_26 -> V_104 -> V_99 ; V_66 ++ ) {
T_1 * V_105 = F_19 ( V_26 -> V_104 , T_1 * , V_66 ) ;
printf ( L_70 , V_66 ) ;
printf ( L_71 , V_105 ) ;
printf ( L_72 , V_26 -> V_106 [ V_66 ] ) ;
}
}
}
}
static void
F_23 ( void )
{
if ( V_107 ) putchar ( V_107 ) ;
}
static void
F_24 ( void )
{
if ( V_108 ) putchar ( V_108 ) ;
}
static void
F_25 ( const T_1 * V_109 )
{
F_23 () ;
F_24 () ;
printf ( L_71 , V_109 ) ;
F_24 () ;
}
static void
F_26 ( void )
{
F_24 () ;
printf ( L_73 ) ;
F_24 () ;
if ( V_2 ) F_25 ( L_74 ) ;
if ( V_3 ) F_25 ( L_75 ) ;
if ( V_8 ) F_25 ( L_76 ) ;
if ( V_4 ) F_25 ( L_77 ) ;
if ( V_4 ) F_25 ( L_78 ) ;
if ( V_4 ) F_25 ( L_79 ) ;
if ( V_5 ) F_25 ( L_80 ) ;
if ( V_6 ) F_25 ( L_81 ) ;
if ( V_10 ) F_25 ( L_82 ) ;
if ( V_11 ) F_25 ( L_83 ) ;
if ( V_12 ) F_25 ( L_84 ) ;
if ( V_13 ) F_25 ( L_85 ) ;
if ( V_15 ) F_25 ( L_86 ) ;
if ( V_16 ) F_25 ( L_87 ) ;
if ( V_17 ) F_25 ( L_88 ) ;
if ( V_18 ) F_25 ( L_89 ) ;
#ifdef F_2
if ( V_19 ) {
F_25 ( L_90 ) ;
F_25 ( L_91 ) ;
F_25 ( L_92 ) ;
}
#endif
if ( V_14 ) F_25 ( L_93 ) ;
if ( V_7 ) F_25 ( L_94 ) ;
if ( V_8 ) {
F_25 ( L_95 ) ;
F_25 ( L_96 ) ;
F_25 ( L_97 ) ;
}
printf ( L_98 ) ;
}
static void
F_27 ( const T_1 * V_58 , T_4 * V_26 )
{
const T_1 * V_59 , * V_60 ;
V_59 = F_14 ( V_26 -> V_62 ) ;
V_60 = F_15 ( V_26 -> V_63 ) ;
if ( V_58 ) {
F_24 () ;
printf ( L_71 , V_58 ) ;
F_24 () ;
}
if ( V_2 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_59 ) ;
F_24 () ;
}
if ( V_3 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_60 ) ;
F_24 () ;
}
if ( V_8 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , F_16 ( V_26 -> V_69 ) ) ;
F_24 () ;
}
if ( V_4 ) {
F_23 () ;
F_24 () ;
if ( V_26 -> V_70 )
printf ( L_99 , V_26 -> V_71 ) ;
else
printf ( L_100 ) ;
F_24 () ;
if ( V_26 -> V_72 > 0 ) {
F_23 () ;
F_24 () ;
printf ( L_99 , V_26 -> V_73 ) ;
F_24 () ;
F_23 () ;
F_24 () ;
printf ( L_99 , V_26 -> V_72 ) ;
F_24 () ;
}
else {
F_23 () ;
F_24 () ;
printf ( L_19 ) ;
F_24 () ;
F_23 () ;
F_24 () ;
printf ( L_19 ) ;
F_24 () ;
}
}
if ( V_5 ) {
F_23 () ;
F_24 () ;
printf ( L_99 , V_26 -> V_31 ) ;
F_24 () ;
}
if ( V_6 ) {
F_23 () ;
F_24 () ;
printf ( L_47 V_76 L_101 , V_26 -> V_77 ) ;
F_24 () ;
}
if ( V_10 ) {
F_23 () ;
F_24 () ;
printf ( L_47 V_76 L_102 , V_26 -> V_79 ) ;
F_24 () ;
}
if ( V_11 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , F_7 ( & V_26 -> V_80 , V_26 -> V_81 , V_26 , FALSE ) ) ;
F_24 () ;
}
if ( V_12 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , F_5 ( & V_26 -> V_82 , V_26 -> V_83 , V_26 ) ) ;
F_24 () ;
}
if ( V_13 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , F_5 ( & V_26 -> V_84 , V_26 -> V_85 , V_26 ) ) ;
F_24 () ;
}
if ( V_15 ) {
F_23 () ;
F_24 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_86 ) ;
else
printf ( L_19 ) ;
F_24 () ;
}
if ( V_16 ) {
F_23 () ;
F_24 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_86 * 8 ) ;
else
printf ( L_19 ) ;
F_24 () ;
}
if ( V_17 ) {
F_23 () ;
F_24 () ;
printf ( L_103 , V_26 -> V_90 ) ;
F_24 () ;
}
if ( V_18 ) {
F_23 () ;
F_24 () ;
if ( V_26 -> V_30 )
printf ( L_103 , V_26 -> V_91 ) ;
else
printf ( L_19 ) ;
F_24 () ;
}
#ifdef F_2
if ( V_19 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_93 ) ;
F_24 () ;
F_23 () ;
F_24 () ;
printf ( L_71 , V_94 ) ;
F_24 () ;
F_23 () ;
F_24 () ;
printf ( L_71 , V_95 ) ;
F_24 () ;
}
#endif
if ( V_14 ) {
F_23 () ;
F_24 () ;
printf ( L_71 , F_4 ( V_26 -> V_20 ) ) ;
F_24 () ;
}
if ( V_26 -> V_96 != NULL ) {
if ( V_7 ) {
T_7 * V_97 ;
unsigned int V_66 ;
F_18 ( V_26 -> V_96 , V_98 , & V_97 ) ;
for ( V_66 = 0 ; V_66 < V_97 -> V_99 ; V_66 ++ ) {
const char * V_110 = F_19 ( V_97 , char * , V_66 ) ;
if ( V_110 != NULL ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_110 ) ;
F_24 () ;
}
}
F_20 ( V_97 , TRUE ) ;
}
if ( V_8 ) {
char * V_54 ;
F_21 ( V_26 -> V_96 , V_100 , & V_54 ) ;
if ( V_54 != NULL ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_54 ) ;
F_24 () ;
}
F_21 ( V_26 -> V_96 , V_101 , & V_54 ) ;
if ( V_54 != NULL ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_54 ) ;
F_24 () ;
}
F_21 ( V_26 -> V_96 , V_102 , & V_54 ) ;
if ( V_54 != NULL ) {
F_23 () ;
F_24 () ;
printf ( L_71 , V_54 ) ;
F_24 () ;
}
}
}
printf ( L_98 ) ;
}
static void
F_28 ( T_4 * V_26 )
{
T_8 V_66 ;
F_22 ( V_26 != NULL ) ;
F_12 ( V_26 -> V_68 ) ;
V_26 -> V_68 = NULL ;
F_12 ( V_26 -> V_106 ) ;
V_26 -> V_106 = NULL ;
if ( V_26 -> V_104 ) {
for ( V_66 = 0 ; V_66 < V_26 -> V_104 -> V_99 ; V_66 ++ ) {
T_1 * V_105 = F_19 ( V_26 -> V_104 , T_1 * , V_66 ) ;
F_12 ( V_105 ) ;
}
F_20 ( V_26 -> V_104 , TRUE ) ;
}
V_26 -> V_104 = NULL ;
}
static int
F_29 ( T_9 * V_111 , const char * V_58 )
{
int V_112 = 0 ;
int V_113 ;
T_1 * V_114 ;
V_87 V_115 ;
V_87 V_116 ;
T_10 V_117 = 0 ;
V_87 V_118 = 0 ;
T_10 V_73 = 0xffffffff ;
T_10 V_72 = 0 ;
const struct V_119 * V_120 ;
T_4 V_26 ;
T_5 V_121 = TRUE ;
T_3 V_82 ;
int V_83 ;
T_3 V_84 ;
int V_85 ;
T_3 V_122 ;
T_3 V_123 ;
T_5 V_124 = FALSE ;
T_2 V_20 = V_21 ;
T_8 V_66 ;
T_11 * V_125 ;
F_22 ( V_111 != NULL ) ;
F_22 ( V_58 != NULL ) ;
F_30 ( & V_82 ) ;
V_83 = V_126 ;
F_30 ( & V_84 ) ;
V_85 = V_126 ;
F_30 ( & V_122 ) ;
F_30 ( & V_123 ) ;
V_26 . V_96 = F_31 ( V_111 ) ;
V_26 . V_68 = F_32 ( int , V_67 ) ;
V_125 = F_33 ( V_111 ) ;
F_22 ( V_125 -> V_127 != NULL ) ;
V_26 . V_103 = V_125 -> V_127 -> V_99 ;
V_26 . V_106 = F_32 ( T_10 , V_26 . V_103 ) ;
V_26 . V_128 = 0 ;
V_26 . V_104 = F_34 ( FALSE , FALSE , sizeof( T_1 * ) , V_26 . V_103 ) ;
for ( V_66 = 0 ; V_66 < V_26 . V_103 ; V_66 ++ ) {
const T_12 V_129 = F_19 ( V_125 -> V_127 , T_12 , V_66 ) ;
T_1 * V_105 = F_35 ( V_129 , 21 , L_98 ) ;
F_36 ( V_26 . V_104 , V_105 ) ;
}
F_12 ( V_125 ) ;
V_125 = NULL ;
while ( F_37 ( V_111 , & V_113 , & V_114 , & V_116 ) ) {
V_120 = F_38 ( V_111 ) ;
if ( V_120 -> V_130 & V_131 ) {
V_123 = V_122 ;
V_122 = V_120 -> V_132 ;
if ( V_117 == 0 ) {
V_82 = V_120 -> V_132 ;
V_83 = V_120 -> V_133 ;
V_84 = V_120 -> V_132 ;
V_85 = V_120 -> V_133 ;
V_123 = V_120 -> V_132 ;
}
if ( F_39 ( & V_122 , & V_123 ) < 0 ) {
V_20 = V_22 ;
}
if ( F_39 ( & V_122 , & V_82 ) < 0 ) {
V_82 = V_122 ;
V_83 = V_120 -> V_133 ;
}
if ( F_39 ( & V_122 , & V_84 ) > 0 ) {
V_84 = V_122 ;
V_85 = V_120 -> V_133 ;
}
} else {
V_121 = FALSE ;
if ( V_20 != V_22 )
V_20 = V_23 ;
}
if ( V_120 -> V_134 == V_135 ) {
V_118 += V_120 -> V_99 ;
V_117 ++ ;
if ( V_120 -> V_136 < V_120 -> V_99 ) {
if ( V_120 -> V_136 < V_73 )
V_73 = V_120 -> V_136 ;
if ( V_120 -> V_136 > V_72 )
V_72 = V_120 -> V_136 ;
}
if ( F_40 ( V_111 ) == V_65 ) {
if ( ( V_120 -> V_137 > 0 ) && ( V_120 -> V_137 < V_67 ) ) {
V_26 . V_68 [ V_120 -> V_137 ] += 1 ;
} else {
fprintf ( V_138 , L_104 ,
V_120 -> V_137 , V_117 , V_58 ) ;
}
}
if ( V_120 -> V_130 & V_139 ) {
if ( V_120 -> V_140 < V_26 . V_103 ) {
V_26 . V_106 [ V_120 -> V_140 ] += 1 ;
}
else {
V_26 . V_128 += 1 ;
}
}
else {
if ( V_26 . V_103 != 0 ) {
V_26 . V_106 [ 0 ] += 1 ;
}
else {
V_26 . V_128 += 1 ;
}
}
}
}
if ( V_113 != 0 ) {
fprintf ( V_138 ,
L_105 ,
V_117 , V_58 , F_41 ( V_113 ) ) ;
if ( V_113 == V_141 ) {
V_112 = 1 ;
fprintf ( V_138 ,
L_106 ) ;
} else {
if ( V_114 != NULL ) {
fprintf ( V_138 , L_107 , V_114 ) ;
F_12 ( V_114 ) ;
}
F_28 ( & V_26 ) ;
return 1 ;
}
}
V_115 = F_42 ( V_111 , & V_113 ) ;
if ( V_115 == - 1 ) {
fprintf ( V_138 ,
L_108 ,
V_58 , F_43 ( V_113 ) ) ;
F_28 ( & V_26 ) ;
return 1 ;
}
V_26 . V_77 = V_115 ;
V_26 . V_62 = F_44 ( V_111 ) ;
V_26 . V_64 = F_45 ( V_111 ) ;
V_26 . V_63 = F_40 ( V_111 ) ;
V_26 . V_69 = F_46 ( V_111 ) ;
V_26 . V_71 = F_47 ( V_111 ) ;
if ( V_26 . V_71 > 0 )
V_26 . V_70 = TRUE ;
else
V_26 . V_70 = FALSE ;
V_26 . V_73 = V_73 ;
V_26 . V_72 = V_72 ;
V_26 . V_31 = V_117 ;
V_26 . V_30 = V_121 ;
V_26 . V_82 = V_82 ;
V_26 . V_83 = V_83 ;
V_26 . V_84 = V_84 ;
V_26 . V_85 = V_85 ;
F_48 ( & V_26 . V_80 , & V_84 , & V_82 ) ;
if ( V_26 . V_85 > V_26 . V_83 )
V_26 . V_81 = V_26 . V_85 ;
else
V_26 . V_81 = V_26 . V_83 ;
V_26 . V_124 = V_124 ;
V_26 . V_20 = V_20 ;
V_26 . V_79 = V_118 ;
V_26 . V_86 = 0.0 ;
V_26 . V_91 = 0.0 ;
V_26 . V_90 = 0.0 ;
if ( V_117 > 0 ) {
double V_142 = F_49 ( & V_84 ) - F_49 ( & V_82 ) ;
if ( V_142 > 0.0 ) {
V_26 . V_86 = ( double ) V_118 / V_142 ;
V_26 . V_91 = ( double ) V_117 / V_142 ;
}
V_26 . V_90 = ( double ) V_118 / V_117 ;
}
if ( V_143 ) {
F_13 ( V_58 , & V_26 ) ;
} else {
F_27 ( V_58 , & V_26 ) ;
}
F_28 ( & V_26 ) ;
return V_112 ;
}
static void
F_50 ( T_13 * V_144 )
{
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_109 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_110 ) ;
fprintf ( V_144 , L_111 ) ;
fprintf ( V_144 , L_112 ) ;
fprintf ( V_144 , L_113 ) ;
fprintf ( V_144 , L_114 ) ;
#ifdef F_2
fprintf ( V_144 , L_115 ) ;
#endif
fprintf ( V_144 , L_116 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_117 ) ;
fprintf ( V_144 , L_118 ) ;
fprintf ( V_144 , L_119 ) ;
fprintf ( V_144 , L_120 ) ;
fprintf ( V_144 , L_121 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_122 ) ;
fprintf ( V_144 , L_123 ) ;
fprintf ( V_144 , L_124 ) ;
fprintf ( V_144 , L_125 ) ;
fprintf ( V_144 , L_126 ) ;
fprintf ( V_144 , L_127 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_128 ) ;
fprintf ( V_144 , L_129 ) ;
fprintf ( V_144 , L_130 ) ;
fprintf ( V_144 , L_131 ) ;
fprintf ( V_144 , L_132 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_133 ) ;
fprintf ( V_144 , L_134 ) ;
fprintf ( V_144 , L_135 ) ;
fprintf ( V_144 , L_136 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_137 ) ;
fprintf ( V_144 , L_138 ) ;
fprintf ( V_144 , L_139 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_140 ) ;
fprintf ( V_144 , L_141 ) ;
fprintf ( V_144 , L_142 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_143 ) ;
fprintf ( V_144 , L_144 ) ;
fprintf ( V_144 , L_145 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_146 ) ;
fprintf ( V_144 , L_147 ) ;
fprintf ( V_144 , L_148 ) ;
fprintf ( V_144 , L_149 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_150 ) ;
fprintf ( V_144 , L_151 ) ;
fprintf ( V_144 , L_98 ) ;
fprintf ( V_144 , L_152 ) ;
fprintf ( V_144 , L_153 ) ;
#ifndef F_2
fprintf ( V_144 , L_154 ) ;
#endif
}
static void
F_51 ( const char * T_14 V_145 , T_15 T_16 V_145 )
{
return;
}
static void
F_52 ( const unsigned char * V_146 , T_17 V_147 , char * V_54 ) {
int V_66 ;
for ( V_66 = 0 ; V_66 < ( int ) V_147 ; V_66 ++ ) {
F_6 ( V_54 + ( V_66 * 2 ) , 3 , L_155 , V_146 [ V_66 ] ) ;
}
}
int
main ( int V_148 , char * V_149 [] )
{
T_18 * V_150 ;
T_18 * V_151 ;
T_9 * V_111 ;
int V_113 ;
T_1 * V_114 ;
int V_152 ;
int V_153 ;
static const struct V_154 V_155 [] = {
{ L_156 , V_156 , NULL , 'h' } ,
{ L_157 , V_156 , NULL , 'v' } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_112 = 0 ;
#ifdef F_53
char * V_157 ;
#endif
#ifdef F_2
T_13 * V_158 ;
char * V_159 = NULL ;
T_19 V_160 = NULL ;
T_17 V_161 ;
#endif
setlocale ( V_162 , L_21 ) ;
V_150 = F_54 ( NULL , NULL ) ;
V_151 = F_55 ( NULL ) ;
F_56 ( L_158
L_98
L_71
L_98
L_71 ,
F_57 () , V_150 -> V_54 , V_151 -> V_54 ) ;
#ifdef F_58
F_59 ( V_148 , V_149 ) ;
F_60 () ;
#endif
F_61 () ;
F_62 () ;
#ifdef F_53
if ( ( V_157 = F_63 ( V_149 [ 0 ] , main ) ) ) {
F_64 ( L_159 , V_157 ) ;
F_12 ( V_157 ) ;
} else {
F_65 () ;
F_66 ( F_51 , NULL , NULL , NULL ) ;
F_67 () ;
F_68 () ;
}
#endif
while ( ( V_152 = F_69 ( V_148 , V_149 , L_160 V_163 L_161 , V_155 , NULL ) ) != - 1 ) {
switch ( V_152 ) {
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
V_164 = FALSE ;
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
V_74 = TRUE ;
break;
case 'R' :
V_165 = TRUE ;
break;
case 'r' :
V_165 = FALSE ;
break;
case 'N' :
V_108 = '\0' ;
break;
case 'q' :
V_108 = '\'' ;
break;
case 'Q' :
V_108 = '"' ;
break;
case 'B' :
V_107 = '\t' ;
break;
case 'm' :
V_107 = ',' ;
break;
case 'b' :
V_107 = ' ' ;
break;
case 'h' :
printf ( L_158
L_162
L_163 ,
F_57 () ) ;
F_50 ( stdout ) ;
exit ( 0 ) ;
break;
case 'v' :
F_70 ( L_164 , V_150 , V_151 ) ;
F_71 ( V_150 , TRUE ) ;
F_71 ( V_151 , TRUE ) ;
exit ( 0 ) ;
break;
case '?' :
F_50 ( V_138 ) ;
exit ( 1 ) ;
break;
}
}
if ( ( V_148 - V_166 ) < 1 ) {
F_50 ( V_138 ) ;
exit ( 1 ) ;
}
if ( ! V_143 && V_165 ) {
F_26 () ;
}
#ifdef F_2
if ( V_19 ) {
F_72 ( NULL ) ;
F_73 ( & V_160 , V_167 , 0 ) ;
if ( V_160 ) {
F_74 ( V_160 , V_168 ) ;
F_74 ( V_160 , V_169 ) ;
}
V_159 = ( char * ) F_75 ( V_170 ) ;
}
#endif
V_153 = 0 ;
for ( V_152 = V_166 ; V_152 < V_148 ; V_152 ++ ) {
#ifdef F_2
F_76 ( V_93 , L_165 , V_171 ) ;
F_76 ( V_94 , L_165 , V_171 ) ;
F_76 ( V_95 , L_165 , V_171 ) ;
if ( V_19 ) {
V_158 = F_77 ( V_149 [ V_152 ] , L_166 ) ;
if ( V_158 && V_160 ) {
while( ( V_161 = fread ( V_159 , 1 , V_170 , V_158 ) ) > 0 ) {
F_78 ( V_160 , V_159 , V_161 ) ;
}
F_79 ( V_160 ) ;
F_52 ( F_80 ( V_160 , V_167 ) , V_172 , V_93 ) ;
F_52 ( F_80 ( V_160 , V_168 ) , V_173 , V_94 ) ;
F_52 ( F_80 ( V_160 , V_169 ) , V_174 , V_95 ) ;
}
if ( V_158 ) fclose ( V_158 ) ;
if ( V_160 ) F_81 ( V_160 ) ;
}
#endif
V_111 = F_82 ( V_149 [ V_152 ] , V_175 , & V_113 , & V_114 , FALSE ) ;
if ( ! V_111 ) {
fprintf ( V_138 , L_167 , V_149 [ V_152 ] ,
F_41 ( V_113 ) ) ;
if ( V_114 != NULL ) {
fprintf ( V_138 , L_107 , V_114 ) ;
F_12 ( V_114 ) ;
}
V_153 = 1 ;
if ( ! V_164 )
exit ( 1 ) ;
}
if ( V_111 ) {
if ( ( V_152 > V_166 ) && ( V_143 ) )
printf ( L_98 ) ;
V_112 = F_29 ( V_111 , V_149 [ V_152 ] ) ;
F_83 ( V_111 ) ;
if ( V_112 )
exit ( V_112 ) ;
}
}
return V_153 ;
}
