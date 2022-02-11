static void F_1 ( T_1 V_1 )
{
V_2 = ( V_3 * ) V_1 ;
}
static T_2
F_2 ( T_3 V_4 , T_3 V_5 )
{
const T_4 * V_6 = ( const T_4 * ) V_4 ;
const T_4 * V_7 = ( const T_4 * ) V_5 ;
return F_3 ( V_6 -> V_8 , V_7 -> V_8 ) ;
}
void
F_4 ( void (F_5)( T_5 V_9 , T_1 V_10 ) ,
void (F_6)( T_5 V_9 , T_1 V_10 ) ,
T_5 V_9 ,
T_1 V_10 )
{
F_7 () ;
V_11 = F_8 ( V_12 , V_13 , V_14 , NULL ) ;
V_15 = F_9 ( V_16 , V_17 ) ;
V_18 = F_9 ( V_16 , V_17 ) ;
V_19 . V_20 = 0 ;
V_19 . V_21 = 0 ;
V_19 . V_22 = NULL ;
V_23 = F_10 ( V_24 , NULL , NULL , F_1 ) ;
F_11 () ;
V_25 = F_12 ( & V_26 , - 1 ) ;
F_13 () ;
F_14 () ;
F_5 ( V_9 , V_10 ) ;
#ifdef F_15
if ( V_9 )
(* V_9)( V_27 , NULL , V_10 ) ;
F_16 () ;
#endif
#ifdef F_17
if ( V_9 )
(* V_9)( V_28 , NULL , V_10 ) ;
F_18 () ;
F_19 () ;
#endif
F_6 ( V_9 , V_10 ) ;
#ifdef F_15
if ( V_9 )
(* V_9)( V_29 , NULL , V_10 ) ;
F_20 () ;
#endif
#ifdef F_17
if ( V_9 )
(* V_9)( V_30 , NULL , V_10 ) ;
F_21 () ;
#endif
V_31 = F_22 ( V_31 , F_2 ) ;
V_32 = F_23 ( V_33 , ( V_34 / 32 ) + 1 ) ;
}
void
F_7 ( void )
{
if ( V_23 ) {
F_24 ( V_23 ) ;
V_23 = NULL ;
}
while ( V_31 ) {
T_4 * V_35 = ( T_4 * ) V_31 -> V_1 ;
V_3 * V_36 ;
F_25 ( V_35 -> V_37 , V_36 ) ;
F_26 ( V_35 -> V_37 == V_36 -> V_38 ) ;
F_27 ( V_3 , V_36 ) ;
F_28 ( V_35 -> V_39 ) ;
V_31 = F_29 ( V_31 , V_35 ) ;
V_14 ( V_35 ) ;
}
if ( V_11 ) {
F_30 ( V_11 ) ;
V_11 = NULL ;
}
if ( V_15 ) {
F_30 ( V_15 ) ;
V_15 = NULL ;
}
if ( V_18 ) {
F_30 ( V_18 ) ;
V_18 = NULL ;
}
if ( V_19 . V_21 ) {
V_19 . V_20 = 0 ;
V_19 . V_21 = 0 ;
V_14 ( V_19 . V_22 ) ;
V_19 . V_22 = NULL ;
}
V_14 ( V_32 ) ;
V_32 = NULL ;
}
static T_6
F_31 ( T_7 * V_40 , T_8 V_41 ,
T_1 V_1 )
{
T_9 * V_42 = V_40 ;
T_9 * V_43 ;
T_9 * V_44 ;
if ( V_41 ( V_42 , V_1 ) )
return TRUE ;
V_43 = V_42 -> V_45 ;
while ( V_43 != NULL ) {
V_44 = V_43 ;
V_43 = V_44 -> V_46 ;
if ( F_31 ( ( T_7 * ) V_44 , V_41 , V_1 ) )
return TRUE ;
}
return FALSE ;
}
T_6
F_32 ( T_7 * V_40 , T_8 V_41 ,
T_1 V_1 )
{
T_9 * V_42 = V_40 ;
T_9 * V_43 ;
T_9 * V_44 ;
V_43 = V_42 -> V_45 ;
while ( V_43 != NULL ) {
V_44 = V_43 ;
V_43 = V_44 -> V_46 ;
if ( F_32 ( ( T_7 * ) V_44 , V_41 , V_1 ) )
return TRUE ;
}
if ( V_41 ( V_42 , V_1 ) )
return TRUE ;
return FALSE ;
}
void
F_33 ( T_7 * V_40 , T_10 V_41 ,
T_1 V_1 )
{
T_9 * V_47 = V_40 ;
T_9 * V_44 ;
if ( ! V_47 )
return;
V_47 = V_47 -> V_45 ;
while ( V_47 != NULL ) {
V_44 = V_47 ;
V_47 = V_44 -> V_46 ;
V_41 ( ( T_7 * ) V_44 , V_1 ) ;
}
}
static void
F_34 ( T_1 V_48 , T_1 V_49 , T_1 T_11 V_50 )
{
T_12 * V_51 = ( T_12 * ) V_49 ;
T_2 V_52 = ( T_2 ) ( long ) V_48 ;
V_3 * V_36 ;
F_25 ( V_52 , V_36 ) ;
if ( V_36 -> V_53 != V_54 ) {
if ( V_36 -> V_55 != - 1 ) {
V_3 * V_56 ;
F_25 ( V_36 -> V_55 , V_56 ) ;
V_56 -> V_53 = V_54 ;
}
V_36 -> V_53 = V_54 ;
}
F_35 ( V_51 , TRUE ) ;
}
static void
F_36 ( T_9 * V_47 , T_1 V_1 V_50 )
{
T_13 * V_57 = F_37 ( V_47 ) ;
F_33 ( V_47 , F_36 , NULL ) ;
F_38 ( & V_57 -> V_49 ) ;
}
void
F_39 ( T_7 * V_40 )
{
T_14 * V_58 = F_40 ( V_40 ) ;
T_15 * V_59 = F_41 ( V_40 ) ;
F_33 ( V_40 , F_36 , NULL ) ;
if ( V_59 -> V_60 ) {
F_42 ( V_59 -> V_60 ,
F_34 , NULL ) ;
F_30 ( V_59 -> V_60 ) ;
}
if ( V_61 ) {
F_43 ( V_58 ) ;
}
else {
F_44 ( V_58 ) ;
V_61 = V_58 ;
}
}
T_6
F_45 ( T_7 * V_40 , T_6 V_62 )
{
T_6 V_63 = F_41 ( V_40 ) -> V_62 ;
F_41 ( V_40 ) -> V_62 = V_62 ;
return V_63 ;
}
void
F_46 ( T_7 * V_40 , T_6 V_64 )
{
F_41 ( V_40 ) -> V_64 = V_64 ;
}
T_6
F_47 ( T_7 * V_40 , int V_37 )
{
register V_3 * V_36 ;
if ( ! V_40 )
return FALSE ;
if ( F_41 ( V_40 ) -> V_62 )
return TRUE ;
F_25 ( V_37 , V_36 ) ;
if ( V_36 -> V_53 != V_54 )
return TRUE ;
if ( V_36 -> type == V_65 && ! F_41 ( V_40 ) -> V_64 )
return TRUE ;
return FALSE ;
}
V_3 *
F_48 ( T_16 V_66 )
{
register V_3 * V_36 ;
F_25 ( V_66 , V_36 ) ;
return V_36 ;
}
static T_16
F_49 ( T_3 V_48 ) {
T_17 * V_67 = F_50 ( ( const T_17 * ) V_48 ) ;
T_17 * V_68 = V_67 ;
for (; * V_68 ; V_68 ++ ) {
if ( * V_68 == '.' ) {
* V_68 = 0 ;
break;
}
}
return F_51 ( V_67 ) ;
}
static T_6
F_52 ( T_3 V_69 , T_3 V_70 ) {
const T_17 * V_71 = ( const T_17 * ) V_69 ;
const T_17 * V_72 = ( const T_17 * ) V_70 ;
do {
T_17 V_73 = * V_71 ++ ;
T_17 V_74 = * V_72 ++ ;
if ( ( V_73 == '.' || V_73 == '\0' ) && ( V_74 == '.' || V_74 == '\0' ) ) return TRUE ;
if ( ( V_73 == '.' || V_73 == '\0' ) && ! ( V_74 == '.' || V_74 == '\0' ) ) return FALSE ;
if ( ( V_74 == '.' || V_74 == '\0' ) && ! ( V_73 == '.' || V_73 == '\0' ) ) return FALSE ;
if ( V_73 != V_74 ) return FALSE ;
} while ( 1 );
return FALSE ;
}
void
F_53 ( const char * V_75 , T_18 V_76 ) {
if ( ! V_77 ) {
V_77 = F_9 ( F_49 , F_52 ) ;
}
F_54 ( V_77 , ( T_1 ) V_75 , V_76 ) ;
}
static T_6
F_55 ( T_1 V_78 , T_1 V_79 , T_1 T_19 V_50 ) {
( ( T_18 ) V_79 ) ( ( const char * ) V_78 ) ;
return TRUE ;
}
void
F_56 ( void ) {
F_57 ( V_77 , F_55 , NULL ) ;
}
V_3 *
F_58 ( const char * V_80 )
{
V_3 * V_36 ;
T_18 V_76 ;
if ( ! V_80 )
return NULL ;
V_36 = ( V_3 * ) F_59 ( V_23 , V_80 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_77 )
return NULL ;
if ( ( V_76 = ( T_18 ) F_60 ( V_77 , V_80 ) ) != NULL ) {
V_76 ( V_80 ) ;
F_61 ( V_77 , V_80 ) ;
} else {
return NULL ;
}
return ( V_3 * ) F_59 ( V_23 , V_80 ) ;
}
int
F_62 ( const char * V_80 )
{
V_3 * V_36 ;
V_36 = F_58 ( V_80 ) ;
if ( ! V_36 )
return - 1 ;
return V_36 -> V_38 ;
}
static void
F_63 ( T_20 * V_81 )
{
T_21 * V_82 ;
F_26 ( V_81 -> V_83 <= V_84 - V_85 ) ;
V_81 -> V_83 += V_85 ;
V_82 = ( T_21 * ) F_64 ( sizeof( T_21 ) * V_81 -> V_83 ) ;
F_26 ( V_82 != NULL ) ;
if ( V_81 -> V_82 )
memcpy ( V_82 , V_81 -> V_82 , V_81 -> V_83 - V_85 ) ;
V_81 -> V_82 = V_82 ;
}
static void
F_65 ( T_20 * V_81 )
{
V_81 -> V_82 = NULL ;
V_81 -> V_83 = 0 ;
F_26 ( V_81 -> V_86 == 0 ) ;
V_81 -> V_86 = 0 ;
}
T_20 *
F_66 ( T_7 * V_40 , T_22 * V_87 , T_2 V_88 )
{
T_20 * V_81 ;
V_81 = ( T_20 * ) F_64 ( sizeof( T_20 ) ) ;
V_81 -> V_40 = V_40 ;
V_81 -> V_87 = V_87 ;
V_81 -> V_88 = V_88 ;
V_81 -> V_82 = NULL ;
V_81 -> V_83 = 0 ;
V_81 -> V_86 = 0 ;
return V_81 ;
}
void
F_67 ( T_20 * V_81 )
{
F_65 ( V_81 ) ;
}
T_22 *
F_68 ( T_20 * V_81 )
{
return V_81 -> V_87 ;
}
T_2
F_69 ( T_20 * V_81 )
{
return V_81 -> V_88 ;
}
T_7 *
F_70 ( T_20 * V_81 )
{
if ( ! V_81 )
return NULL ;
return V_81 -> V_40 ;
}
void
F_71 ( T_20 * V_81 , T_7 * V_40 )
{
V_81 -> V_40 = V_40 ;
}
T_7 *
F_72 ( T_20 * V_81 , T_23 * V_89 , T_2 V_90 )
{
T_21 * V_91 ;
if ( V_81 -> V_86 >= V_81 -> V_83 )
F_63 ( V_81 ) ;
V_91 = V_81 -> V_82 + V_81 -> V_86 ;
V_91 -> V_40 = V_81 -> V_40 ;
V_91 -> V_89 = NULL ;
V_81 -> V_86 ++ ;
return F_73 ( V_81 , V_89 , V_90 ) ;
}
void
F_74 ( T_20 * V_81 )
{
T_21 * V_91 ;
if ( V_81 -> V_86 <= 0 )
return;
V_81 -> V_86 -- ;
V_91 = V_81 -> V_82 + V_81 -> V_86 ;
if ( V_91 -> V_89 != NULL )
F_75 ( V_91 -> V_89 , F_69 ( V_81 ) - V_91 -> V_92 ) ;
V_81 -> V_40 = V_91 -> V_40 ;
}
static void
F_76 ( T_20 * V_81 , T_23 * V_89 )
{
T_21 * V_91 ;
F_26 ( V_81 -> V_86 > 0 ) ;
V_91 = V_81 -> V_82 + V_81 -> V_86 - 1 ;
V_91 -> V_89 = V_89 ;
V_91 -> V_92 = F_69 ( V_81 ) ;
}
T_7 *
F_73 ( T_20 * V_81 , T_23 * V_89 , T_2 V_90 )
{
V_81 -> V_40 = F_77 ( V_89 , V_90 ) ;
return V_81 -> V_40 ;
}
static T_7 *
F_78 ( T_20 * V_81 , T_23 * V_89 , T_2 V_90 , T_2 V_93 )
{
F_72 ( V_81 , V_89 , V_90 ) ;
if ( V_93 == V_94 )
F_76 ( V_81 , V_89 ) ;
return F_70 ( V_81 ) ;
}
T_7 *
F_79 ( T_20 * V_81 , int V_66 , T_2 V_93 ,
const T_16 V_95 , T_2 V_90 )
{
T_23 * V_89 ;
V_89 = F_80 ( V_81 , V_66 , V_93 , V_95 ) ;
return F_78 ( V_81 , V_89 , V_90 , V_93 ) ;
}
T_7 *
F_81 ( T_20 * V_81 , T_2 V_93 ,
T_2 V_90 , const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
T_7 * V_40 ;
V_40 = F_70 ( V_81 ) ;
F_82 ( V_40 , V_25 , V_36 ) ;
V_76 = F_83 ( V_40 , F_68 ( V_81 ) ,
F_69 ( V_81 ) , V_93 ) ;
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return F_78 ( V_81 , V_76 , V_90 , V_93 ) ;
}
static T_23 *
F_83 ( T_7 * V_40 , T_22 * V_87 , T_2 V_97 , T_2 V_93 )
{
T_23 * V_76 ;
if ( V_40 == NULL )
return NULL ;
V_76 = F_86 ( V_40 , & V_26 , V_87 , V_97 , & V_93 ) ;
return V_76 ;
}
T_23 *
F_87 ( T_7 * V_40 , T_22 * V_87 , T_2 V_97 , T_2 V_93 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
F_82 ( V_40 , V_25 , V_36 ) ;
V_76 = F_83 ( V_40 , V_87 , V_97 , V_93 ) ;
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return V_76 ;
}
T_23 *
F_88 ( T_7 * V_40 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const char * V_96 , T_24 V_69 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_25 , V_36 ) ;
V_76 = F_83 ( V_40 , V_87 , V_97 , V_93 ) ;
F_84 ( V_76 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
return V_76 ;
}
T_23 *
F_89 ( T_7 * V_40 , const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_83 ( V_40 , NULL , 0 , 0 ) ;
if ( V_76 ) {
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
va_start ( V_69 , V_96 ) ;
vprintf ( V_96 , V_69 ) ;
va_end ( V_69 ) ;
printf ( L_1 ) ;
return V_76 ;
}
static void
F_90 ( T_7 * V_40 , const T_17 * V_98 , int V_93 , T_6 V_99 ) {
if ( V_99 ) {
F_91 ( NULL , V_40 , & V_100 , L_2 , V_98 , V_93 ) ;
} else {
F_91 ( NULL , V_40 , & V_101 , L_2 , V_98 , V_93 ) ;
}
if ( V_99 ) {
F_92 ( V_102 ) ;
}
}
static V_33
F_93 ( T_7 * V_40 , T_22 * V_87 , T_2 V_88 , T_2 V_93 , const T_16 V_95 )
{
V_33 V_49 ;
T_6 V_103 ;
switch ( V_93 ) {
case 1 :
V_49 = F_94 ( V_87 , V_88 ) ;
break;
case 2 :
V_49 = ( V_95 & V_104 ) ? F_95 ( V_87 , V_88 )
: F_96 ( V_87 , V_88 ) ;
break;
case 3 :
V_49 = ( V_95 & V_104 ) ? F_97 ( V_87 , V_88 )
: F_98 ( V_87 , V_88 ) ;
break;
case 4 :
V_49 = ( V_95 & V_104 ) ? F_99 ( V_87 , V_88 )
: F_100 ( V_87 , V_88 ) ;
break;
default:
if ( V_93 < 1 ) {
V_103 = TRUE ;
V_49 = 0 ;
} else {
V_103 = FALSE ;
V_49 = ( V_95 & V_104 ) ? F_99 ( V_87 , V_88 )
: F_100 ( V_87 , V_88 ) ;
}
F_90 ( V_40 , L_3 , V_93 , V_103 ) ;
break;
}
return V_49 ;
}
static T_25
F_101 ( T_7 * V_40 , T_22 * V_87 , T_2 V_88 , T_2 V_93 , const T_16 V_95 )
{
T_25 V_49 ;
T_6 V_103 ;
switch ( V_93 ) {
case 1 :
V_49 = ( V_105 ) F_94 ( V_87 , V_88 ) ;
break;
case 2 :
V_49 = ( V_106 ) ( V_95 ? F_95 ( V_87 , V_88 )
: F_96 ( V_87 , V_88 ) ) ;
break;
case 3 :
V_49 = V_95 ? F_97 ( V_87 , V_88 )
: F_98 ( V_87 , V_88 ) ;
if ( V_49 & 0x00800000 ) {
V_49 |= 0xFF000000 ;
}
break;
case 4 :
V_49 = V_95 ? F_99 ( V_87 , V_88 )
: F_100 ( V_87 , V_88 ) ;
break;
default:
if ( V_93 < 1 ) {
V_103 = TRUE ;
V_49 = 0 ;
} else {
V_103 = FALSE ;
V_49 = V_95 ? F_99 ( V_87 , V_88 )
: F_100 ( V_87 , V_88 ) ;
}
F_90 ( V_40 , L_4 , V_93 , V_103 ) ;
break;
}
return V_49 ;
}
static void
F_102 ( T_15 * V_59 , T_13 * V_107 )
{
const V_3 * V_36 = V_107 -> V_36 ;
if ( V_36 -> V_53 == V_108 ) {
T_12 * V_51 = NULL ;
if ( V_59 -> V_60 == NULL ) {
V_59 -> V_60 =
F_9 ( V_109 , NULL ) ;
} else
V_51 = ( T_12 * ) F_60 ( V_59 -> V_60 ,
F_103 ( V_36 -> V_38 ) ) ;
if ( ! V_51 ) {
V_51 = F_104 () ;
F_54 ( V_59 -> V_60 ,
F_103 ( V_36 -> V_38 ) , V_51 ) ;
}
F_105 ( V_51 , V_107 ) ;
}
}
static T_23 *
F_106 ( T_13 * V_110 , T_7 * V_40 ,
T_22 * V_87 , T_2 V_97 , T_2 V_93 ,
T_16 V_95 )
{
T_23 * V_76 ;
V_33 V_49 , V_111 ;
float V_112 ;
double V_113 ;
const char * string ;
T_26 V_114 ;
V_33 V_115 ;
T_27 V_116 ;
T_6 V_103 ;
switch ( V_110 -> V_36 -> type ) {
case V_117 :
break;
case V_65 :
F_107 ( V_110 , V_87 ) ;
break;
case V_118 :
F_108 ( V_110 , V_87 , V_97 , V_93 ) ;
break;
case V_119 :
if ( V_95 )
V_95 = V_104 ;
V_111 = F_93 ( V_40 , V_87 , V_97 , V_93 , V_95 ) ;
F_108 ( V_110 , V_87 , V_97 + V_93 , V_111 ) ;
V_110 -> V_93 = V_111 + V_93 ;
break;
case V_120 :
if ( V_95 )
V_95 = V_104 ;
F_109 ( V_110 ,
F_93 ( V_40 , V_87 , V_97 , V_93 , V_95 ) ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
if ( V_95 )
V_95 = V_104 ;
F_110 ( V_110 ,
F_93 ( V_40 , V_87 , V_97 , V_93 , V_95 ) ) ;
break;
case V_125 :
case V_126 :
if ( V_95 )
V_95 = V_104 ;
if ( V_93 < 1 || V_93 > 8 ) {
V_103 = V_93 < 1 ? TRUE : FALSE ;
F_90 ( V_40 , L_5 , V_93 , V_103 ) ;
}
F_111 ( V_110 , V_87 , V_97 , V_93 , V_95 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
if ( V_95 )
V_95 = V_104 ;
F_112 ( V_110 ,
F_101 ( V_40 , V_87 , V_97 , V_93 , V_95 ) ) ;
break;
case V_131 :
if ( V_95 )
V_95 = V_104 ;
if ( V_93 != V_132 ) {
V_103 = V_93 < V_132 ? TRUE : FALSE ;
F_90 ( V_40 , L_6 , V_93 , V_103 ) ;
}
V_49 = F_113 ( V_87 , V_97 ) ;
F_114 ( V_110 , V_95 ? F_115 ( V_49 ) : V_49 ) ;
break;
case V_133 :
if ( V_93 != V_134 ) {
V_103 = V_93 < V_134 ? TRUE : FALSE ;
F_90 ( V_40 , L_7 , V_93 , V_103 ) ;
}
F_116 ( V_110 ,
F_93 ( V_40 , V_87 , V_97 , V_134 , V_135 ) ) ;
break;
case V_136 :
if ( V_93 != V_137 ) {
V_103 = V_93 < V_137 ? TRUE : FALSE ;
F_90 ( V_40 , L_8 , V_93 , V_103 ) ;
}
F_117 ( V_110 , V_87 , V_97 , V_93 ) ;
break;
case V_138 :
if ( V_93 != 7 ) {
V_103 = V_93 < 7 ? TRUE : FALSE ;
F_90 ( V_40 , L_9 , V_93 , V_103 ) ;
}
F_118 ( V_110 , V_87 , V_97 ) ;
break;
case V_139 :
if ( V_93 != V_140 ) {
V_103 = V_93 < V_140 ? TRUE : FALSE ;
F_90 ( V_40 , L_10 , V_93 , V_103 ) ;
}
F_119 ( V_110 , V_87 , V_97 ) ;
break;
case V_141 :
if ( V_93 != V_142 ) {
V_103 = V_93 < V_142 ? TRUE : FALSE ;
F_90 ( V_40 , L_11 , V_93 , V_103 ) ;
}
F_120 ( V_110 , V_87 , V_97 ) ;
break;
case V_143 :
if ( V_95 )
V_95 = V_104 ;
if ( V_93 != V_144 ) {
V_103 = V_93 < V_144 ? TRUE : FALSE ;
F_90 ( V_40 , L_12 , V_93 , V_103 ) ;
}
F_121 ( V_110 , V_87 , V_97 , V_95 ) ;
break;
case V_145 :
if ( V_95 )
V_95 = V_104 ;
if ( V_93 != V_146 ) {
V_103 = V_93 < V_146 ? TRUE : FALSE ;
F_90 ( V_40 , L_13 , V_93 , V_103 ) ;
}
F_122 ( V_110 , V_87 , V_97 , V_95 ) ;
break;
case V_147 :
case V_148 :
F_123 ( V_110 , V_87 , V_97 , V_93 ) ;
break;
case V_149 :
if ( V_95 )
V_95 = V_104 ;
if ( V_93 != 4 ) {
V_103 = V_93 < 4 ? TRUE : FALSE ;
F_90 ( V_40 , L_14 , V_93 , V_103 ) ;
}
if ( V_95 )
V_112 = F_124 ( V_87 , V_97 ) ;
else
V_112 = F_125 ( V_87 , V_97 ) ;
F_126 ( V_110 , V_112 ) ;
break;
case V_150 :
if ( V_95 == TRUE )
V_95 = V_104 ;
if ( V_93 != 8 ) {
V_103 = V_93 < 8 ? TRUE : FALSE ;
F_90 ( V_40 , L_15 , V_93 , V_103 ) ;
}
if ( V_95 )
V_113 = F_127 ( V_87 , V_97 ) ;
else
V_113 = F_128 ( V_87 , V_97 ) ;
F_129 ( V_110 , V_113 ) ;
break;
case V_151 :
F_130 ( V_110 , V_87 , V_97 , V_93 ,
V_95 ) ;
break;
case V_152 :
if ( V_93 < - 1 ) {
F_90 ( V_40 , L_16 , V_93 , TRUE ) ;
}
if ( V_93 == - 1 ) {
string = F_131 ( F_132 () , V_87 , V_97 , & V_93 , V_95 ) ;
} else if ( V_93 == 0 ) {
string = L_17 ;
} else {
string = F_133 ( F_132 () , V_87 , V_97 , V_93 , V_95 ) ;
}
V_110 -> V_93 = V_93 ;
F_134 ( V_110 , string ) ;
break;
case V_153 :
if ( V_95 == TRUE )
V_95 = V_154 | V_104 ;
V_111 = F_93 ( V_40 , V_87 , V_97 , V_93 , V_95 & ~ V_155 ) ;
F_130 ( V_110 , V_87 , V_97 + V_93 , V_111 ,
V_95 ) ;
V_110 -> V_93 = V_111 + V_93 ;
break;
case V_156 :
if ( V_95 == TRUE )
V_95 = V_157 | V_104 ;
if ( V_93 != 8 && V_93 != 4 ) {
V_103 = V_93 < 4 ? TRUE : FALSE ;
F_90 ( V_40 , L_18 , V_93 , V_103 ) ;
}
switch ( V_95 ) {
case V_157 | V_135 :
V_114 . V_158 = F_100 ( V_87 , V_97 ) ;
if ( V_93 == 8 )
V_114 . V_159 = F_100 ( V_87 , V_97 + 4 ) ;
else
V_114 . V_159 = 0 ;
break;
case V_157 | V_104 :
V_114 . V_158 = F_99 ( V_87 , V_97 ) ;
if ( V_93 == 8 )
V_114 . V_159 = F_99 ( V_87 , V_97 + 4 ) ;
else
V_114 . V_159 = 0 ;
break;
case V_160 | V_135 :
#define F_135 2208988800ul
V_116 = F_136 ( V_87 , V_97 ) >> 12 ;
V_114 . V_158 = ( V_161 ) ( ( V_116 / 1000000 ) - F_135 ) ;
V_114 . V_159 = ( int ) ( ( V_116 % 1000000 ) * 1000 ) ;
break;
case V_160 | V_104 :
V_116 = F_137 ( V_87 , V_97 ) >> 12 ;
V_114 . V_158 = ( V_161 ) ( ( V_116 / 1000000 ) - F_135 ) ;
V_114 . V_159 = ( int ) ( ( V_116 % 1000000 ) * 1000 ) ;
break;
case V_162 | V_135 :
#define F_138 2208988800ul
V_115 = F_100 ( V_87 , V_97 ) ;
if ( V_115 )
V_114 . V_158 = V_115 - ( V_33 ) F_138 ;
else
V_114 . V_158 = V_115 ;
if ( V_93 == 8 ) {
V_114 . V_159 = ( int ) ( 1000000 * ( F_100 ( V_87 , V_97 + 4 ) / 4294967296.0 ) ) ;
V_114 . V_159 *= 1000 ;
} else {
V_114 . V_159 = 0 ;
}
break;
case V_162 | V_104 :
V_115 = F_99 ( V_87 , V_97 ) ;
if ( V_115 )
V_114 . V_158 = V_115 - ( V_33 ) F_138 ;
else
V_114 . V_158 = V_115 ;
if ( V_93 == 8 ) {
V_114 . V_159 = ( int ) ( 1000000 * ( F_99 ( V_87 , V_97 + 4 ) / 4294967296.0 ) ) ;
V_114 . V_159 *= 1000 ;
} else {
V_114 . V_159 = 0 ;
}
break;
default:
F_139 () ;
V_114 . V_158 = 0 ;
V_114 . V_159 = 0 ;
break;
}
F_140 ( V_110 , & V_114 ) ;
break;
case V_163 :
if ( V_95 == TRUE )
V_95 = V_157 | V_104 ;
switch ( V_95 ) {
if ( V_93 != 8 && V_93 != 4 ) {
V_103 = V_93 < 4 ? TRUE : FALSE ;
F_90 ( V_40 , L_19 , V_93 , V_103 ) ;
}
case V_157 | V_135 :
V_114 . V_158 = F_100 ( V_87 , V_97 ) ;
if ( V_93 == 8 )
V_114 . V_159 = F_100 ( V_87 , V_97 + 4 ) ;
else
V_114 . V_159 = 0 ;
break;
case V_157 | V_104 :
V_114 . V_158 = F_99 ( V_87 , V_97 ) ;
if ( V_93 == 8 )
V_114 . V_159 = F_99 ( V_87 , V_97 + 4 ) ;
else
V_114 . V_159 = 0 ;
break;
}
F_140 ( V_110 , & V_114 ) ;
break;
default:
F_141 ( L_20 ,
V_110 -> V_36 -> type ,
F_142 ( V_110 -> V_36 -> type ) ) ;
F_139 () ;
break;
}
F_143 ( V_110 , ( V_95 & V_104 ) ? V_164 : V_165 ) ;
V_76 = F_144 ( V_40 , V_110 ) ;
return V_76 ;
}
T_23 *
F_145 ( T_20 * V_81 , int V_66 , T_2 V_93 ,
const T_16 V_95 )
{
T_13 * V_110 ;
V_3 * V_36 ;
T_2 V_166 ;
V_33 V_111 ;
int V_88 ;
V_88 = V_81 -> V_88 ;
F_25 ( V_66 , V_36 ) ;
F_146 ( V_36 , V_81 -> V_87 , V_88 , & V_93 , & V_166 ) ;
V_81 -> V_88 += V_93 ;
if ( V_36 -> type == V_119 || V_36 -> type == V_153 ) {
V_111 = F_93 ( V_81 -> V_40 , V_81 -> V_87 , V_88 , V_93 , V_95 ) ;
V_81 -> V_88 += V_111 ;
}
F_82 ( V_81 -> V_40 , V_66 , V_36 ) ;
V_110 = F_147 ( V_81 -> V_40 , V_36 , V_81 -> V_87 , V_88 , V_166 ) ;
return F_106 ( V_110 , V_81 -> V_40 , V_81 -> V_87 ,
V_88 , V_93 , V_95 ) ;
}
T_23 *
F_148 ( T_7 * V_40 , V_3 * V_36 , T_22 * V_87 ,
const T_2 V_97 , T_2 V_93 , const T_16 V_95 )
{
T_13 * V_110 ;
T_2 V_166 ;
F_149 ( V_36 != NULL , L_21 ) ;
if ( V_87 ) {
F_150 ( V_87 , V_97 ) ;
}
F_82 ( V_40 , V_36 -> V_38 , V_36 ) ;
F_146 ( V_36 , V_87 , V_97 , & V_93 , & V_166 ) ;
V_110 = F_147 ( V_40 , V_36 , V_87 , V_97 , V_166 ) ;
if ( V_110 == NULL )
return NULL ;
return F_106 ( V_110 , V_40 , V_87 , V_97 , V_93 , V_95 ) ;
}
T_23 *
F_151 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
const T_2 V_97 , T_2 V_93 , const T_16 V_95 )
{
return F_148 ( V_40 , F_48 ( V_66 ) , V_87 , V_97 , V_93 , V_95 ) ;
}
T_23 *
F_152 ( T_7 * V_40 , const int V_66 , T_22 * V_87 ,
const T_2 V_97 , T_2 V_93 , const char * V_96 ,
... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_117 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return V_76 ;
}
T_23 *
F_80 ( T_20 * V_81 , int V_167 , T_2 V_93 ,
const T_16 V_95 )
{
T_23 * V_168 ;
V_168 = F_151 ( V_81 -> V_40 , V_167 , V_81 -> V_87 , V_81 -> V_88 ,
V_93 , V_95 ) ;
return V_168 ;
}
void
F_153 ( T_20 * V_81 , T_2 V_93 )
{
V_81 -> V_88 += V_93 ;
}
static void
F_107 ( T_13 * V_107 , T_22 * V_87 )
{
F_154 ( & V_107 -> V_49 , V_87 , TRUE ) ;
}
T_23 *
F_155 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_65 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_107 ( F_37 ( V_76 ) , ( V_97 == 0 ? V_87 : F_156 ( V_87 , V_97 , V_93 , V_93 ) ) ) ;
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return V_76 ;
}
T_23 *
F_157 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_28 * V_169 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_118 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_158 ( F_37 ( V_76 ) , V_169 , V_93 ) ;
return V_76 ;
}
T_23 *
F_159 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 ,
const T_28 * V_169 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
if ( V_169 )
V_76 = F_157 ( V_40 , V_66 , V_87 , V_97 , V_93 ,
V_169 ) ;
else
V_76 = F_157 ( V_40 , V_66 , V_87 , V_97 , V_93 ,
F_160 ( V_87 , V_97 , V_93 ) ) ;
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return V_76 ;
}
T_23 *
F_162 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_28 * V_169 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
if ( V_169 )
V_76 = F_157 ( V_40 , V_66 , V_87 , V_97 , V_93 ,
V_169 ) ;
else
V_76 = F_157 ( V_40 , V_66 , V_87 , V_97 , V_93 ,
F_160 ( V_87 , V_97 , V_93 ) ) ;
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
return V_76 ;
}
static void
F_158 ( T_13 * V_107 , const T_28 * V_169 , T_2 V_93 )
{
T_29 * V_170 ;
F_26 ( V_169 != NULL || V_93 == 0 ) ;
V_170 = F_163 () ;
if ( V_93 > 0 ) {
F_164 ( V_170 , V_169 , V_93 ) ;
}
F_154 ( & V_107 -> V_49 , V_170 , TRUE ) ;
}
static void
F_108 ( T_13 * V_107 , T_22 * V_87 , T_2 V_88 , T_2 V_93 )
{
F_158 ( V_107 , F_160 ( V_87 , V_88 , V_93 ) , V_93 ) ;
}
T_23 *
F_165 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , T_26 * V_171 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_156 ||
V_36 -> type == V_163 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_140 ( F_37 ( V_76 ) , V_171 ) ;
return V_76 ;
}
T_23 *
F_166 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_26 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_165 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_167 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_26 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_165 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_140 ( T_13 * V_107 , T_26 * V_171 )
{
F_26 ( V_171 != NULL ) ;
F_154 ( & V_107 -> V_49 , V_171 , FALSE ) ;
}
T_23 *
F_168 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , V_33 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_133 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_116 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_169 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_168 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_170 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_168 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_116 ( T_13 * V_107 , V_33 V_49 )
{
F_171 ( & V_107 -> V_49 , V_49 ) ;
}
T_23 *
F_172 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , V_33 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_131 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_114 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_173 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_172 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_174 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_172 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_114 ( T_13 * V_107 , V_33 V_49 )
{
F_171 ( & V_107 -> V_49 , V_49 ) ;
}
T_23 *
F_175 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_28 * V_171 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_136 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_176 ( F_37 ( V_76 ) , V_171 ) ;
return V_76 ;
}
T_23 *
F_177 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 ,
const T_28 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_175 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_178 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_28 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_175 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_176 ( T_13 * V_107 , const T_28 * V_171 )
{
F_26 ( V_171 != NULL ) ;
F_154 ( & V_107 -> V_49 , ( T_1 ) V_171 , FALSE ) ;
}
static void
F_117 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 , T_2 V_93 )
{
F_176 ( V_107 , F_160 ( V_87 , V_97 , V_93 ) ) ;
}
T_23 *
F_179 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_30 * V_171 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_145 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_180 ( F_37 ( V_76 ) , V_171 ) ;
return V_76 ;
}
T_23 *
F_181 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 ,
const T_30 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_179 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_182 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_30 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_179 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_180 ( T_13 * V_107 , const T_30 * V_171 )
{
F_26 ( V_171 != NULL ) ;
F_154 ( & V_107 -> V_49 , ( T_1 ) V_171 , FALSE ) ;
}
static void
F_122 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 ,
const T_16 V_95 )
{
T_30 V_172 ;
F_183 ( V_87 , V_97 , & V_172 , V_95 ) ;
F_180 ( V_107 , & V_172 ) ;
}
T_23 *
F_184 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_28 * V_171 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_147 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_185 ( F_37 ( V_76 ) , V_171 , V_93 ) ;
return V_76 ;
}
T_23 *
F_186 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 ,
const T_28 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_184 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_187 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_28 * V_171 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_184 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_171 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_185 ( T_13 * V_107 , const T_28 * V_171 , T_2 V_93 )
{
T_29 * V_170 ;
F_26 ( V_171 != NULL || V_93 == 0 ) ;
V_170 = F_163 () ;
if ( V_93 > 0 ) {
F_164 ( V_170 , V_171 , V_93 ) ;
}
F_154 ( & V_107 -> V_49 , V_170 , TRUE ) ;
}
static void
F_123 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 , T_2 V_93 )
{
F_185 ( V_107 , F_160 ( V_87 , V_97 , V_93 ) , V_93 ) ;
}
static void
F_188 ( T_13 * V_107 , T_27 V_49 )
{
F_189 ( & V_107 -> V_49 , V_49 ) ;
}
static void
F_111 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 ,
T_16 V_93 , const T_16 V_95 )
{
T_27 V_49 = 0 ;
T_28 * V_72 = ( T_28 * ) F_190 ( F_132 () , V_87 , V_97 , V_93 ) ;
if ( V_95 ) {
V_72 += V_93 ;
switch ( V_93 ) {
default: F_139 () ;
case 8 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 7 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 6 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 5 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 4 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 3 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 2 : V_49 <<= 8 ; V_49 += * -- V_72 ;
case 1 : V_49 <<= 8 ; V_49 += * -- V_72 ;
break;
}
} else {
switch ( V_93 ) {
default: F_139 () ;
case 8 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 7 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 6 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 5 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 4 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 3 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 2 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
case 1 : V_49 <<= 8 ; V_49 += * V_72 ++ ;
break;
}
}
F_188 ( V_107 , V_49 ) ;
}
T_23 *
F_191 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const char * V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_151 || V_36 -> type == V_152 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_26 ( V_93 >= 0 ) ;
F_134 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_192 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const char * V_49 )
{
F_26 ( F_193 ( V_49 , - 1 , NULL ) ) ;
return F_194 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 , L_22 , V_49 ) ;
}
T_23 *
F_194 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const char * V_49 ,
const char * V_96 ,
... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_191 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_195 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const char * V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_191 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
void
F_196 ( T_23 * V_76 , const char * V_173 )
{
T_13 * V_107 ;
V_3 * V_36 ;
const T_17 * V_174 , * V_175 ;
if ( ! V_76 )
return;
if ( ! * V_173 )
return;
V_107 = F_197 ( V_76 ) ;
F_149 ( V_107 , L_23 ) ;
V_36 = V_107 -> V_36 ;
if ( V_36 -> type == V_65 ) {
return;
}
F_26 ( V_36 -> type == V_151 || V_36 -> type == V_152 ) ;
V_174 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
if ( V_174 && V_174 [ 0 ] )
V_175 = F_199 ( V_174 , V_173 , NULL ) ;
else
V_175 = V_173 ;
F_154 ( & V_107 -> V_49 , ( T_1 ) V_175 , FALSE ) ;
}
static void
F_134 ( T_13 * V_107 , const char * V_49 )
{
if ( V_49 ) {
F_154 ( & V_107 -> V_49 , ( T_1 ) V_49 , FALSE ) ;
} else {
F_154 ( & V_107 -> V_49 , ( T_1 ) L_24 , FALSE ) ;
}
}
static void
F_130 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 , T_2 V_93 , T_2 V_95 )
{
T_17 * string ;
if ( V_93 == - 1 ) {
V_93 = F_200 ( V_87 , V_97 ) ;
}
string = F_133 ( F_132 () , V_87 , V_97 , V_93 , V_95 ) ;
F_134 ( V_107 , string ) ;
}
T_23 *
F_201 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 , T_2 V_93 ,
const T_28 * V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_138 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_202 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
static void
F_202 ( T_13 * V_107 , const T_28 * V_49 )
{
F_154 ( & V_107 -> V_49 , ( T_1 ) V_49 , FALSE ) ;
}
static void
F_118 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 )
{
F_202 ( V_107 , F_160 ( V_87 , V_97 , 7 ) ) ;
}
static void
F_203 ( T_13 * V_107 , const T_28 * V_49 )
{
F_154 ( & V_107 -> V_49 , ( T_1 ) V_49 , FALSE ) ;
}
static void
F_119 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 )
{
F_203 ( V_107 , F_160 ( V_87 , V_97 , V_176 ) ) ;
}
T_23 *
F_204 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_28 * V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_141 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_205 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_206 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_28 * V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_204 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_207 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_28 * V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_204 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_205 ( T_13 * V_107 , const T_28 * V_49 )
{
F_154 ( & V_107 -> V_49 , ( T_1 ) V_49 , FALSE ) ;
}
static void
F_120 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 )
{
F_205 ( V_107 , F_160 ( V_87 , V_97 , V_142 ) ) ;
}
T_23 *
F_208 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , V_33 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_120 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_109 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_209 ( T_7 * V_40 , int V_66 ,
T_22 * V_87 , T_2 V_97 , T_2 V_93 ,
V_33 V_49 , const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_208 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_210 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_208 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_109 ( T_13 * V_107 , V_33 V_49 )
{
F_110 ( V_107 , V_49 ) ;
}
T_23 *
F_211 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , float V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_149 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_126 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_212 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , float V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_211 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_213 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , float V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_211 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_126 ( T_13 * V_107 , float V_49 )
{
F_214 ( & V_107 -> V_49 , V_49 ) ;
}
T_23 *
F_215 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , double V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_150 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_129 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_216 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , double V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_215 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_217 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , double V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_215 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_129 ( T_13 * V_107 , double V_49 )
{
F_214 ( & V_107 -> V_49 , V_49 ) ;
}
T_23 *
F_218 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , V_33 V_49 )
{
T_23 * V_76 = NULL ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
switch ( V_36 -> type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_177 :
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_110 ( F_37 ( V_76 ) , V_49 ) ;
break;
default:
F_139 () ;
}
return V_76 ;
}
T_23 *
F_219 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_218 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_220 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , V_33 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_218 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_110 ( T_13 * V_107 , V_33 V_49 )
{
V_3 * V_36 ;
V_33 integer ;
V_36 = V_107 -> V_36 ;
integer = V_49 ;
if ( V_36 -> V_178 ) {
integer &= V_36 -> V_178 ;
integer >>= F_221 ( V_36 ) ;
}
F_171 ( & V_107 -> V_49 , integer ) ;
}
T_23 *
F_222 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , T_27 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_126 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_188 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_223 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_27 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_222 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_224 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_27 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_222 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_225 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , T_25 V_49 )
{
T_23 * V_76 = NULL ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
switch ( V_36 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_112 ( F_37 ( V_76 ) , V_49 ) ;
break;
default:
F_139 () ;
}
return V_76 ;
}
T_23 *
F_226 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_25 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_225 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_227 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_25 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_225 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_112 ( T_13 * V_107 , T_25 V_49 )
{
V_3 * V_36 ;
V_33 integer ;
T_2 V_179 ;
V_36 = V_107 -> V_36 ;
integer = ( V_33 ) V_49 ;
if ( V_36 -> V_178 ) {
integer &= V_36 -> V_178 ;
integer >>= F_221 ( V_36 ) ;
V_179 = F_228 ( V_36 -> V_178 ) ;
if ( integer & ( 1 << ( V_179 - 1 ) ) )
integer |= ( - 1 << V_179 ) ;
}
F_229 ( & V_107 -> V_49 , integer ) ;
}
T_23 *
F_230 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , T_31 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_125 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_188 ( F_37 ( V_76 ) , ( T_27 ) V_49 ) ;
return V_76 ;
}
T_23 *
F_231 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_31 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_230 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_232 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , T_31 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_230 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_233 ( T_7 * V_40 , int V_66 , T_22 * V_87 , T_2 V_97 ,
T_2 V_93 , const T_27 V_49 )
{
T_23 * V_76 ;
V_3 * V_36 ;
F_82 ( V_40 , V_66 , V_36 ) ;
F_26 ( V_36 -> type == V_143 ) ;
V_76 = F_86 ( V_40 , V_36 , V_87 , V_97 , & V_93 ) ;
F_234 ( F_37 ( V_76 ) , V_49 ) ;
return V_76 ;
}
T_23 *
F_235 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_27 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_233 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
va_start ( V_69 , V_96 ) ;
F_161 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
T_23 *
F_236 ( T_7 * V_40 , int V_66 , T_22 * V_87 ,
T_2 V_97 , T_2 V_93 , const T_27 V_49 ,
const char * V_96 , ... )
{
T_23 * V_76 ;
T_24 V_69 ;
V_76 = F_233 ( V_40 , V_66 , V_87 , V_97 , V_93 , V_49 ) ;
if ( V_76 != V_40 ) {
F_84 ( V_76 ) ;
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
return V_76 ;
}
static void
F_234 ( T_13 * V_107 , const T_27 V_49 )
{
F_189 ( & V_107 -> V_49 , V_49 ) ;
}
static void
F_121 ( T_13 * V_107 , T_22 * V_87 , T_2 V_97 , const T_16 V_95 )
{
if ( V_95 )
{
F_234 ( V_107 , F_137 ( V_87 , V_97 ) ) ;
} else {
F_234 ( V_107 , F_136 ( V_87 , V_97 ) ) ;
}
}
static T_23 *
F_144 ( T_7 * V_40 , T_13 * V_107 )
{
T_9 * V_42 , * V_180 , * V_181 ;
T_13 * V_182 ;
V_180 = V_40 ;
V_182 = F_37 ( V_180 ) ;
if ( V_182 != NULL && ( V_182 -> V_183 < 0 || V_182 -> V_183 >= V_34 ) ) {
F_237 ( F_238 ( L_25 ,
V_107 -> V_36 -> V_184 , V_107 -> V_36 -> V_185 , V_182 -> V_183 , __FILE__ , __LINE__ ) ) ;
}
F_239 ( F_40 ( V_40 ) , V_42 ) ;
V_42 -> V_55 = V_180 ;
F_37 ( V_42 ) = V_107 ;
V_42 -> V_59 = F_41 ( V_40 ) ;
if ( V_180 -> V_186 != NULL ) {
V_181 = V_180 -> V_186 ;
F_26 ( V_181 -> V_46 == NULL ) ;
V_181 -> V_46 = V_42 ;
} else
V_180 -> V_45 = V_42 ;
V_180 -> V_186 = V_42 ;
F_102 ( V_42 -> V_59 , V_107 ) ;
return ( T_23 * ) V_42 ;
}
static T_23 *
F_86 ( T_7 * V_40 , V_3 * V_36 , T_22 * V_87 , T_2 V_97 ,
T_2 * V_93 )
{
T_23 * V_76 ;
T_13 * V_107 ;
V_107 = F_240 ( V_40 , V_36 , V_87 , V_97 , V_93 ) ;
V_76 = F_144 ( V_40 , V_107 ) ;
return V_76 ;
}
static void
F_146 ( V_3 * V_36 , T_22 * V_87 , const T_2 V_97 , T_2 * V_93 ,
T_2 * V_166 )
{
T_2 V_187 ;
F_26 ( V_87 != NULL || * V_93 == 0 ) ;
if ( * V_93 == - 1 ) {
switch ( V_36 -> type ) {
case V_65 :
* V_93 = F_241 ( V_87 , V_97 ) ;
if ( * V_93 < 0 ) {
F_242 ( V_87 , V_97 , 0 ) ;
}
F_26 ( * V_93 >= 0 ) ;
break;
case V_117 :
case V_118 :
case V_151 :
* V_93 = F_200 ( V_87 , V_97 ) ;
F_26 ( * V_93 >= 0 ) ;
break;
case V_152 :
break;
default:
F_139 () ;
}
* V_166 = * V_93 ;
} else {
* V_166 = * V_93 ;
if ( V_36 -> type == V_65 || V_36 -> type == V_117 ) {
if ( V_87 ) {
V_187 = F_241 ( V_87 , V_97 ) ;
if ( * V_166 < 0 ||
( * V_166 > 0 &&
( V_187 < * V_166 ) ) )
* V_166 = V_187 ;
}
}
if ( * V_166 < 0 ) {
F_92 ( V_102 ) ;
}
}
}
static T_13 *
F_147 ( T_7 * V_40 , V_3 * V_36 , T_22 * V_87 ,
const T_2 V_97 , const T_2 V_166 )
{
T_13 * V_107 ;
F_243 ( F_40 ( V_40 ) , V_107 ) ;
V_107 -> V_36 = V_36 ;
V_107 -> V_97 = V_97 ;
V_107 -> V_97 += ( V_87 ) ? F_244 ( V_87 ) : 0 ;
V_107 -> V_93 = V_166 ;
V_107 -> V_183 = - 1 ;
V_107 -> V_188 = 0 ;
if ( ! F_41 ( V_40 ) -> V_62 )
F_143 ( V_107 , V_189 ) ;
F_245 ( & V_107 -> V_49 , V_107 -> V_36 -> type ) ;
V_107 -> V_190 = NULL ;
V_107 -> V_191 = V_87 ? F_246 ( V_87 ) : NULL ;
V_107 -> V_192 = 0 ;
V_107 -> V_193 = 0 ;
return V_107 ;
}
static T_13 *
F_240 ( T_7 * V_40 , V_3 * V_36 , T_22 * V_87 , const T_2 V_97 ,
T_2 * V_93 )
{
T_2 V_166 ;
F_146 ( V_36 , V_87 , V_97 , V_93 , & V_166 ) ;
return F_147 ( V_40 , V_36 , V_87 , V_97 , V_166 ) ;
}
static void
F_247 ( char * V_194 )
{
static const char V_195 [] = L_26 ;
const T_32 V_196 = sizeof( V_195 ) - 1 ;
memmove ( V_194 + V_196 , V_194 , V_197 - V_196 ) ;
memcpy ( V_194 , V_195 , V_196 ) ;
V_194 [ V_197 - 1 ] = '\0' ;
}
static void
F_161 ( T_23 * V_76 , const char * V_96 , T_24 V_69 )
{
F_248 ( V_76 ) ;
if ( F_41 ( V_76 ) -> V_62 && ! F_249 ( V_76 ) ) {
int V_198 = 0 ;
T_13 * V_107 = F_197 ( V_76 ) ;
V_3 * V_167 ;
F_26 ( V_107 ) ;
V_167 = V_107 -> V_36 ;
F_250 ( F_40 ( V_76 ) , V_107 -> V_190 ) ;
if ( V_167 -> V_178 && ( V_167 -> type == V_120 || F_251 ( V_167 -> type ) ) ) {
V_33 V_199 ;
char * V_200 ;
V_199 = F_252 ( & V_107 -> V_49 ) ;
V_199 <<= F_221 ( V_167 ) ;
V_200 = F_253 ( V_107 -> V_190 -> V_201 , V_199 , V_167 -> V_178 , F_254 ( V_167 ) ) ;
V_198 = ( int ) ( V_200 - V_107 -> V_190 -> V_201 ) ;
}
V_198 += F_255 ( V_107 -> V_190 -> V_201 + V_198 , V_197 - V_198 , L_27 , V_167 -> V_184 ) ;
if ( V_198 < V_197 ) {
V_198 += F_256 ( V_107 -> V_190 -> V_201 + V_198 ,
V_197 - V_198 , V_96 , V_69 ) ;
}
if ( V_198 >= V_197 ) {
F_247 ( V_107 -> V_190 -> V_201 ) ;
}
}
}
static void
F_85 ( T_23 * V_76 , const char * V_96 , T_24 V_69 )
{
int V_198 ;
T_13 * V_107 = F_197 ( V_76 ) ;
F_26 ( V_107 ) ;
if ( ! F_249 ( V_76 ) ) {
F_250 ( F_40 ( V_76 ) , V_107 -> V_190 ) ;
V_198 = F_256 ( V_107 -> V_190 -> V_201 , V_197 ,
V_96 , V_69 ) ;
if ( V_198 >= V_197 ) {
F_247 ( V_107 -> V_190 -> V_201 ) ;
}
}
}
static int
F_257 ( T_17 * V_202 , const T_17 * V_203 , T_33 V_204 )
{
T_33 V_205 = F_258 ( V_202 , V_203 , V_204 ) ;
if ( V_205 > V_204 )
V_205 = V_204 ;
return ( int ) V_205 ;
}
static V_3 *
F_259 ( const V_3 * V_36 )
{
if ( V_36 -> V_206 == - 1 )
return NULL ;
return F_48 ( V_36 -> V_206 ) ;
}
const T_17 *
F_260 ( T_7 * V_40 , const int V_207 , T_2 V_208 ,
T_17 * V_209 , T_17 * V_210 , const int V_211 )
{
V_33 V_212 ;
T_28 * V_170 ;
T_34 * V_213 ;
struct V_214 * V_215 ;
T_35 V_216 ;
V_33 V_217 ;
const T_36 * V_218 ;
int V_20 , V_219 = 0 , V_220 , V_221 , V_222 = 0 , V_223 = 0 ;
T_12 * V_224 ;
T_13 * V_57 = NULL ;
V_3 * V_36 ;
const T_17 * V_185 = NULL ;
const char * V_225 ;
char V_226 [ 32 ] ;
const char * V_227 ;
F_248 ( V_207 >= 0 ) ;
V_36 = F_48 ( ( T_16 ) V_207 ) ;
if ( ! V_36 )
return L_28 ;
if ( V_208 < 0 ) {
while ( V_36 -> V_206 != - 1 ) {
V_36 = F_48 ( V_36 -> V_206 ) ;
}
}
while ( V_36 ) {
V_224 = F_261 ( V_40 , V_36 -> V_38 ) ;
if ( ! V_224 || ! ( V_20 = F_262 ( V_224 ) ) ) {
if ( V_208 < 0 ) {
V_36 = V_36 -> V_228 ;
} else {
V_36 = F_259 ( V_36 ) ;
}
continue;
}
if ( ( ( V_208 - V_219 ) > V_20 ) || ( ( V_208 + V_219 ) < - V_20 ) ) {
if ( V_208 < 0 ) {
V_36 = V_36 -> V_228 ;
} else {
V_36 = F_259 ( V_36 ) ;
}
V_219 += V_20 ;
continue;
}
if ( V_208 < 0 ) {
V_221 = V_208 + V_20 + V_219 ;
V_220 = V_221 ;
} else if ( V_208 > 0 ) {
V_221 = V_208 - 1 - V_219 ;
V_220 = V_221 ;
} else {
V_221 = 0 ;
V_220 = V_20 - 1 ;
}
V_219 += V_20 ;
while ( V_221 <= V_220 ) {
V_57 = ( T_13 * ) F_263 ( V_224 , V_221 ) ;
if ( V_222 && ( V_222 < ( V_211 - 2 ) ) )
V_209 [ V_222 ++ ] = ',' ;
if ( V_223 && ( V_223 < ( V_211 - 2 ) ) )
V_210 [ V_223 ++ ] = ',' ;
switch ( V_36 -> type ) {
case V_117 :
if ( V_222 == 0 ) {
V_209 [ 0 ] = '\0' ;
} else if ( V_209 [ V_222 - 1 ] == ',' ) {
V_209 [ V_222 - 1 ] = '\0' ;
}
break;
case V_65 :
F_258 ( V_209 , L_29 , V_211 ) ;
break;
case V_119 :
case V_118 :
V_170 = ( T_28 * ) F_198 ( & V_57 -> V_49 ) ;
V_222 += F_257 ( V_209 + V_222 ,
F_264 ( V_170 ,
F_265 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
break;
case V_156 :
V_222 += F_257 ( V_209 + V_222 ,
F_266 ( ( const T_26 * ) F_198 ( & V_57 -> V_49 ) ,
( V_229 ) V_36 -> V_230 , TRUE ) ,
V_211 - V_222 ) ;
break;
case V_163 :
V_222 += F_257 ( V_209 + V_222 ,
F_267 ( ( const T_26 * ) F_198 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
break;
case V_120 :
V_212 = F_252 ( & V_57 -> V_49 ) ;
V_218 = ( const T_36 * ) & V_231 ;
if ( V_36 -> V_232 ) {
V_218 = ( const struct T_36 * ) V_36 -> V_232 ;
}
V_222 += F_257 ( V_209 + V_222 ,
V_212 ?
V_218 -> V_233 :
V_218 -> V_234 , V_211 - V_222 ) ;
V_223 += F_257 ( V_210 + V_223 ,
V_212 ? L_30 : L_31 , V_211 - V_223 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_177 :
V_225 = NULL ;
V_212 = F_268 ( V_36 -> type ) ?
( V_33 ) F_269 ( & V_57 -> V_49 ) :
F_252 ( & V_57 -> V_49 ) ;
if ( ( V_36 -> V_230 & V_235 ) == V_236 ) {
T_17 V_237 [ V_197 ] ;
T_37 V_238 = ( T_37 ) V_36 -> V_232 ;
F_26 ( V_238 ) ;
V_238 ( V_237 , V_212 ) ;
V_222 += F_257 ( V_209 + V_222 , V_237 , V_211 - V_222 ) ;
} else if ( V_36 -> V_232 ) {
V_227 = V_225 = F_270 ( V_212 , V_36 ) ;
if ( ! V_227 )
V_227 = F_271 ( V_36 , V_239 , V_226 , V_212 ) ;
V_222 += F_257 ( V_209 + V_222 , V_227 , V_211 - V_222 ) ;
} else {
V_227 = F_272 ( V_36 , V_226 , V_212 ) ;
V_222 += F_257 ( V_209 + V_222 , V_227 , V_211 - V_222 ) ;
}
if ( V_225 && ( V_36 -> V_230 & V_235 ) == V_240 ) {
F_255 ( V_210 + V_223 , V_211 - V_223 , L_32 , V_225 ) ;
} else {
V_227 = F_273 ( V_36 , V_226 , V_212 ) ;
F_258 ( V_210 + V_223 , V_227 , V_211 - V_223 ) ;
}
V_223 = ( int ) strlen ( V_210 ) ;
break;
case V_125 :
F_255 ( V_209 + V_222 , V_211 - V_222 ,
L_33 V_241 L_34 ,
F_274 ( & V_57 -> V_49 ) ) ;
V_222 = ( int ) strlen ( V_209 ) ;
break;
case V_126 :
F_255 ( V_209 + V_222 , V_211 - V_222 ,
L_33 V_241 L_35 ,
F_274 ( & V_57 -> V_49 ) ) ;
V_222 = ( int ) strlen ( V_209 ) ;
break;
case V_143 :
V_222 += F_257 ( V_209 + V_222 ,
F_275 ( F_274 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
break;
case V_131 :
V_213 = ( T_34 * ) F_198 ( & V_57 -> V_49 ) ;
V_217 = F_276 ( V_213 ) ;
V_222 += F_257 ( V_209 + V_222 ,
F_277 ( ( T_28 * ) & V_217 ) ,
V_211 - V_222 ) ;
break;
case V_136 :
V_215 = (struct V_214 * ) F_198 ( & V_57 -> V_49 ) ;
F_278 ( & V_216 , V_242 , sizeof( struct V_214 ) , V_215 ) ;
F_279 ( & V_216 , V_209 + V_222 , V_211 - V_222 ) ;
V_222 = ( int ) strlen ( V_209 ) ;
break;
case V_141 :
V_222 += F_257 ( V_209 + V_222 ,
F_280 ( ( const T_28 * ) F_198 ( & V_57 -> V_49 ) ,
V_142 , ':' ) ,
V_211 - V_222 ) ;
break;
case V_145 :
V_222 += F_257 ( V_209 + V_222 ,
F_281 ( ( T_30 * ) F_198 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
break;
case V_148 :
V_170 = ( T_28 * ) F_198 ( & V_57 -> V_49 ) ;
V_222 += F_257 ( V_209 + V_222 ,
F_282 ( V_170 ,
F_265 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
V_223 += F_257 ( V_210 + V_223 ,
F_283 ( V_170 , F_265 ( & V_57 -> V_49 ) ) ,
V_211 - V_223 ) ;
break;
case V_147 :
V_170 = ( T_28 * ) F_198 ( & V_57 -> V_49 ) ;
V_222 += F_257 ( V_209 + V_222 ,
F_284 ( V_170 ,
F_265 ( & V_57 -> V_49 ) ) ,
V_211 - V_222 ) ;
V_223 += F_257 ( V_210 + V_223 ,
F_285 ( V_170 , F_265 ( & V_57 -> V_49 ) ) ,
V_211 - V_223 ) ;
break;
case V_149 :
F_255 ( V_209 + V_222 , V_211 - V_222 ,
L_36 F_286 ( V_243 ) L_37 , F_287 ( & V_57 -> V_49 ) ) ;
V_222 = ( int ) strlen ( V_209 ) ;
break;
case V_150 :
F_255 ( V_209 + V_222 , V_211 - V_222 ,
L_36 F_286 ( V_244 ) L_37 , F_287 ( & V_57 -> V_49 ) ) ;
V_222 = ( int ) strlen ( V_209 ) ;
break;
case V_151 :
case V_152 :
case V_153 :
V_170 = ( T_28 * ) F_198 ( & V_57 -> V_49 ) ;
V_222 += F_257 ( V_209 + V_222 ,
F_288 ( V_170 , strlen ( V_170 ) ) ,
V_211 - V_222 ) ;
break;
case V_133 :
case V_245 :
default:
F_141 ( L_38 ,
V_36 -> type ,
F_142 ( V_36 -> type ) ) ;
F_139 () ;
break;
}
V_221 ++ ;
}
switch ( V_36 -> type ) {
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_177 :
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_147 :
case V_148 :
break;
default:
F_258 ( V_210 , V_209 , V_211 ) ;
break;
}
if ( ! V_185 ) {
V_185 = V_36 -> V_185 ;
}
if ( V_208 == 0 ) {
V_36 = F_259 ( V_36 ) ;
} else {
V_36 = NULL ;
}
}
return V_185 ? V_185 : L_28 ;
}
void
F_289 ( T_23 * V_76 , const char * V_96 , ... )
{
T_13 * V_107 = NULL ;
T_24 V_69 ;
if ( V_76 == NULL ) {
return;
}
V_107 = F_197 ( V_76 ) ;
if ( V_107 == NULL )
return;
if ( V_107 -> V_190 ) {
F_290 ( F_40 ( V_76 ) , V_107 -> V_190 ) ;
V_107 -> V_190 = NULL ;
}
va_start ( V_69 , V_96 ) ;
F_85 ( V_76 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
void
F_291 ( T_23 * V_76 , const char * V_96 , ... )
{
T_13 * V_107 = NULL ;
T_32 V_246 ;
T_24 V_69 ;
if ( V_76 == NULL ) {
return;
}
V_107 = F_197 ( V_76 ) ;
if ( V_107 == NULL ) {
return;
}
if ( ! F_249 ( V_76 ) ) {
if ( V_107 -> V_190 == NULL ) {
F_250 ( F_40 ( V_76 ) , V_107 -> V_190 ) ;
F_292 ( V_107 , V_107 -> V_190 -> V_201 ) ;
}
V_246 = strlen ( V_107 -> V_190 -> V_201 ) ;
if ( V_197 > V_246 ) {
va_start ( V_69 , V_96 ) ;
F_256 ( V_107 -> V_190 -> V_201 + V_246 ,
V_197 - ( V_247 ) V_246 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
}
}
}
void
F_293 ( T_23 * V_76 , const char * V_96 , ... )
{
T_13 * V_107 = NULL ;
char V_201 [ V_197 ] ;
T_24 V_69 ;
if ( V_76 == NULL ) {
return;
}
V_107 = F_197 ( V_76 ) ;
if ( V_107 == NULL ) {
return;
}
if ( ! F_249 ( V_76 ) ) {
if ( V_107 -> V_190 == NULL ) {
F_250 ( F_40 ( V_76 ) , V_107 -> V_190 ) ;
F_292 ( V_107 , V_201 ) ;
} else
F_258 ( V_201 , V_107 -> V_190 -> V_201 , V_197 ) ;
va_start ( V_69 , V_96 ) ;
F_256 ( V_107 -> V_190 -> V_201 ,
V_197 , V_96 , V_69 ) ;
va_end ( V_69 ) ;
F_294 ( V_107 -> V_190 -> V_201 , V_201 , V_197 ) ;
}
}
void
F_75 ( T_23 * V_76 , const T_2 V_93 )
{
T_13 * V_107 ;
if ( V_76 == NULL )
return;
V_107 = F_197 ( V_76 ) ;
if ( V_107 == NULL )
return;
F_26 ( V_93 >= 0 ) ;
V_107 -> V_93 = V_93 ;
if ( V_107 -> V_49 . V_248 -> V_248 == V_118 && V_93 <= ( T_2 ) V_107 -> V_49 . V_49 . V_170 -> V_20 )
V_107 -> V_49 . V_49 . V_170 -> V_20 = V_93 ;
}
void
F_295 ( T_23 * V_76 , T_22 * V_87 , T_2 V_249 )
{
T_13 * V_107 ;
if ( V_76 == NULL )
return;
V_107 = F_197 ( V_76 ) ;
if ( V_107 == NULL )
return;
V_249 += F_244 ( V_87 ) ;
F_26 ( V_249 >= V_107 -> V_97 ) ;
V_107 -> V_93 = V_249 - V_107 -> V_97 ;
}
int
F_296 ( const T_23 * V_76 )
{
T_13 * V_107 = F_197 ( V_76 ) ;
return V_107 ? V_107 -> V_93 : - 1 ;
}
T_7 *
F_297 ( T_38 * V_250 )
{
T_14 * V_58 ;
T_9 * V_42 ;
if ( V_61 ) {
V_58 = V_61 ;
V_61 = NULL ;
}
else {
V_58 = F_298 ( V_251 ) ;
}
F_239 ( V_58 , V_42 ) ;
V_42 -> V_55 = NULL ;
F_37 ( V_42 ) = NULL ;
V_42 -> V_59 = F_299 ( V_58 , T_15 ) ;
V_42 -> V_59 -> V_250 = V_250 ;
V_42 -> V_59 -> V_252 = V_58 ;
V_42 -> V_59 -> V_60 = NULL ;
V_42 -> V_59 -> V_62 = FALSE ;
V_42 -> V_59 -> V_64 = TRUE ;
V_42 -> V_59 -> V_253 = 0 ;
return ( T_7 * ) V_42 ;
}
void
F_300 ( T_7 * V_40 V_50 , const T_2 V_52 )
{
V_3 * V_36 ;
F_25 ( V_52 , V_36 ) ;
V_36 -> V_53 = V_108 ;
if ( V_36 -> V_55 != - 1 ) {
V_3 * V_56 ;
F_25 ( V_36 -> V_55 , V_56 ) ;
if ( V_56 -> V_53 != V_108 )
V_56 -> V_53 = V_254 ;
}
}
T_7 *
F_77 ( T_23 * V_76 , const T_2 V_255 ) {
T_13 * V_107 ;
if ( ! V_76 )
return NULL ;
F_26 ( V_255 >= 0 && V_255 < V_34 ) ;
V_107 = F_197 ( V_76 ) ;
if ( ! V_107 )
return ( T_7 * ) V_76 ;
V_107 -> V_183 = V_255 ;
return ( T_7 * ) V_76 ;
}
T_7 *
F_301 ( const T_23 * V_76 ) {
T_13 * V_107 ;
if ( ! V_76 )
return NULL ;
V_107 = F_197 ( V_76 ) ;
if ( ( ! V_107 ) || ( V_107 -> V_183 == - 1 ) )
return NULL ;
return ( T_7 * ) V_76 ;
}
T_23 *
F_302 ( const T_23 * V_256 ) {
if ( ! V_256 )
return NULL ;
return V_256 -> V_55 ;
}
T_23 *
F_303 ( T_23 * V_256 , int V_257 ) {
if ( ! V_256 )
return NULL ;
while ( V_257 -- ) {
V_256 = V_256 -> V_55 ;
if ( ! V_256 )
return NULL ;
}
return V_256 ;
}
T_23 *
F_304 ( const T_7 * V_40 ) {
if ( ! V_40 )
return NULL ;
return ( T_23 * ) V_40 ;
}
T_7 *
F_305 ( T_7 * V_40 ) {
if ( ! V_40 )
return NULL ;
while ( V_40 -> V_55 ) {
V_40 = V_40 -> V_55 ;
}
return V_40 ;
}
void
F_306 ( T_7 * V_40 , T_23 * V_258 ,
T_23 * V_259 )
{
if ( ! V_40 || ! F_41 ( V_40 ) -> V_62 )
return;
F_26 ( V_259 -> V_55 == V_40 ) ;
F_26 ( V_258 -> V_55 == V_40 ) ;
if ( V_40 -> V_45 == V_259 ) {
V_40 -> V_45 = V_259 -> V_46 ;
F_26 ( V_40 -> V_186 != V_259 ) ;
} else {
T_23 * V_260 ;
for( V_260 = V_40 -> V_45 ; V_260 != NULL ; V_260 = V_260 -> V_46 ) {
if ( V_260 -> V_46 == V_259 ) {
break;
}
}
F_26 ( V_260 ) ;
V_260 -> V_46 = V_259 -> V_46 ;
if ( V_40 -> V_186 == V_259 ) {
V_40 -> V_186 = V_260 ;
}
}
V_259 -> V_46 = V_258 -> V_46 ;
V_258 -> V_46 = V_259 ;
if ( V_40 -> V_186 == V_258 ) {
V_40 -> V_186 = V_259 ;
}
}
void
F_307 ( T_7 * V_40 , T_22 * V_87 , T_2 V_97 ,
const T_2 V_93 )
{
T_13 * V_107 ;
if ( V_40 == NULL )
return;
V_107 = F_308 ( V_40 ) ;
if ( V_107 == NULL )
return;
V_97 += F_244 ( V_87 ) ;
F_26 ( V_97 >= 0 ) ;
F_26 ( V_93 >= 0 ) ;
V_107 -> V_192 = V_97 ;
V_107 -> V_193 = V_93 ;
}
int
F_309 ( const char * V_184 , const char * V_8 ,
const char * V_261 )
{
T_4 * V_35 ;
V_3 * V_36 ;
int V_37 ;
char * V_262 ;
T_2 * V_48 ;
T_16 V_221 ;
T_39 V_68 ;
T_6 V_263 ;
V_48 = ( T_2 * ) F_310 ( sizeof( T_2 ) ) ;
* V_48 = V_16 ( V_184 ) ;
V_262 = ( char * ) F_60 ( V_11 , V_48 ) ;
if ( V_262 != NULL ) {
F_141 ( L_39
L_40 , V_184 ) ;
}
F_54 ( V_11 , V_48 , ( T_1 ) V_184 ) ;
V_262 = ( char * ) F_60 ( V_15 , ( T_1 ) V_8 ) ;
if ( V_262 != NULL ) {
F_141 ( L_41
L_40 , V_8 ) ;
}
F_54 ( V_15 , ( T_1 ) V_8 , ( T_1 ) V_8 ) ;
V_263 = FALSE ;
for ( V_221 = 0 ; V_261 [ V_221 ] ; V_221 ++ ) {
V_68 = V_261 [ V_221 ] ;
if ( ! ( islower ( V_68 ) || isdigit ( V_68 ) || V_68 == '-' || V_68 == '_' || V_68 == '.' ) ) {
V_263 = TRUE ;
}
}
if ( V_263 ) {
F_141 ( L_42
L_43
L_40 , V_261 ) ;
}
V_262 = ( char * ) F_60 ( V_18 , ( T_1 ) V_261 ) ;
if ( V_262 != NULL ) {
F_141 ( L_44
L_40 , V_261 ) ;
}
F_54 ( V_18 , ( T_1 ) V_261 , ( T_1 ) V_261 ) ;
V_35 = F_311 ( T_4 , 1 ) ;
V_35 -> V_184 = V_184 ;
V_35 -> V_8 = V_8 ;
V_35 -> V_261 = V_261 ;
V_35 -> V_39 = NULL ;
V_35 -> V_264 = TRUE ;
V_35 -> V_265 = TRUE ;
V_35 -> V_266 = FALSE ;
V_31 = F_312 ( V_31 , V_35 ) ;
V_36 = F_313 ( V_3 ) ;
V_36 -> V_184 = V_184 ;
V_36 -> V_185 = V_261 ;
V_36 -> type = V_65 ;
V_36 -> V_230 = V_240 ;
V_36 -> V_232 = V_35 ;
V_36 -> V_178 = 0 ;
V_36 -> V_53 = V_54 ;
V_36 -> V_267 = NULL ;
V_36 -> V_55 = - 1 ;
V_37 = F_12 ( V_36 , V_36 -> V_55 ) ;
V_35 -> V_37 = V_37 ;
return V_37 ;
}
void
F_314 ( const int V_37 )
{
T_4 * V_35 = F_315 ( V_37 ) ;
if ( V_35 )
V_35 -> V_266 = TRUE ;
}
T_6
F_316 ( const int V_37 )
{
T_4 * V_35 = F_315 ( V_37 ) ;
if ( V_35 )
return V_35 -> V_266 ;
else
return FALSE ;
}
int
F_317 ( void * * V_268 )
{
T_4 * V_35 ;
if ( V_31 == NULL )
return - 1 ;
* V_268 = V_31 ;
V_35 = ( T_4 * ) V_31 -> V_1 ;
return V_35 -> V_37 ;
}
int
F_318 ( void * V_268 )
{
T_40 * V_269 = ( T_40 * ) V_268 ;
T_4 * V_35 = ( T_4 * ) V_269 -> V_1 ;
return V_35 -> V_37 ;
}
int
F_319 ( void * * V_268 )
{
T_40 * V_269 = ( T_40 * ) * V_268 ;
T_4 * V_35 ;
V_269 = F_320 ( V_269 ) ;
if ( V_269 == NULL )
return - 1 ;
* V_268 = V_269 ;
V_35 = ( T_4 * ) V_269 -> V_1 ;
return V_35 -> V_37 ;
}
V_3 *
F_321 ( const int V_37 , void * * V_268 )
{
T_4 * V_35 = F_315 ( V_37 ) ;
if ( ( V_35 == NULL ) || ( V_35 -> V_39 == NULL ) )
return NULL ;
* V_268 = V_35 -> V_39 ;
return ( V_3 * ) V_35 -> V_39 -> V_1 ;
}
V_3 *
F_322 ( void * * V_268 )
{
T_41 * V_269 = ( T_41 * ) * V_268 ;
V_269 = F_323 ( V_269 ) ;
if ( V_269 == NULL )
return NULL ;
* V_268 = V_269 ;
return ( V_3 * ) V_269 -> V_1 ;
}
T_4 *
F_315 ( const int V_37 )
{
V_3 * V_36 ;
if ( V_37 < 0 )
return NULL ;
F_25 ( V_37 , V_36 ) ;
F_26 ( V_36 -> type == V_65 ) ;
return ( T_4 * ) V_36 -> V_232 ;
}
static T_2 F_324 ( T_3 V_270 ,
T_3 V_261 )
{
const T_4 * V_35 = ( const T_4 * ) V_270 ;
const T_17 * V_271 = ( const T_17 * ) V_261 ;
return ( strcmp ( V_35 -> V_261 , V_271 ) ) ;
}
int
F_325 ( const T_4 * V_35 )
{
return V_35 -> V_37 ;
}
int F_326 ( const T_17 * V_261 )
{
T_40 * V_272 ;
T_4 * V_35 ;
if( ! V_261 ) {
fprintf ( V_273 , L_45 ) ;
F_26 ( V_261 ) ;
}
V_272 = F_327 ( V_31 , V_261 ,
F_324 ) ;
if ( V_272 == NULL )
return - 1 ;
V_35 = ( T_4 * ) V_272 -> V_1 ;
return V_35 -> V_37 ;
}
const char *
F_328 ( const int V_37 )
{
T_4 * V_35 ;
V_35 = F_315 ( V_37 ) ;
if ( V_35 == NULL )
return NULL ;
return V_35 -> V_184 ;
}
const char *
F_329 ( const T_4 * V_35 )
{
if ( V_35 == NULL )
return L_46 ;
return V_35 -> V_8 ;
}
const char *
F_330 ( const T_4 * V_35 )
{
if ( V_35 == NULL )
return L_46 ;
return V_35 -> V_184 ;
}
const char *
F_331 ( const int V_37 )
{
T_4 * V_35 ;
V_35 = F_315 ( V_37 ) ;
if ( V_35 == NULL )
return L_46 ;
return V_35 -> V_261 ;
}
T_6
F_332 ( const T_4 * V_35 )
{
return V_35 -> V_264 ;
}
T_6
F_333 ( const int V_37 )
{
T_4 * V_35 ;
V_35 = F_315 ( V_37 ) ;
return V_35 -> V_265 ;
}
void
F_334 ( const int V_37 , const T_6 V_274 )
{
T_4 * V_35 ;
V_35 = F_315 ( V_37 ) ;
F_26 ( V_35 -> V_265 ) ;
V_35 -> V_264 = V_274 ;
}
void
F_335 ( void )
{
T_4 * V_35 ;
T_40 * V_269 = V_31 ;
if ( V_31 == NULL )
return;
while ( V_269 ) {
V_35 = ( T_4 * ) V_269 -> V_1 ;
if ( V_35 -> V_265 )
V_35 -> V_264 = TRUE ;
V_269 = F_320 ( V_269 ) ;
}
}
void
F_336 ( const int V_37 )
{
T_4 * V_35 ;
V_35 = F_315 ( V_37 ) ;
V_35 -> V_265 = FALSE ;
}
void
F_337 ( const int V_55 , T_42 * V_167 , const int V_275 )
{
int V_207 , V_221 ;
T_42 * V_276 = V_167 ;
T_4 * V_277 ;
V_277 = F_315 ( V_55 ) ;
for ( V_221 = 0 ; V_221 < V_275 ; V_221 ++ , V_276 ++ ) {
if ( * V_276 -> V_278 != - 1 && * V_276 -> V_278 != 0 ) {
fprintf ( V_273 ,
L_47 ,
V_276 -> V_36 . V_185 ) ;
return;
}
if ( V_277 != NULL ) {
if ( V_277 -> V_39 == NULL ) {
V_277 -> V_39 = F_338 ( NULL , & V_276 -> V_36 ) ;
V_277 -> V_279 = V_277 -> V_39 ;
} else {
V_277 -> V_279 =
F_338 ( V_277 -> V_279 , & V_276 -> V_36 ) -> V_46 ;
}
}
V_207 = F_12 ( & V_276 -> V_36 , V_55 ) ;
* V_276 -> V_278 = V_207 ;
}
}
void
F_339 ( const int V_55 , V_3 * * V_22 , const int V_275 )
{
int V_221 ;
T_4 * V_277 ;
V_277 = F_315 ( V_55 ) ;
for ( V_221 = 0 ; V_221 < V_275 ; V_221 ++ ) {
if ( V_22 [ V_221 ] -> V_38 != - 1 ) {
fprintf ( V_273 ,
L_47 ,
V_22 [ V_221 ] -> V_185 ) ;
return;
}
if ( V_277 != NULL ) {
if ( V_277 -> V_39 == NULL ) {
V_277 -> V_39 = F_338 ( NULL , V_22 [ V_221 ] ) ;
V_277 -> V_279 = V_277 -> V_39 ;
} else {
V_277 -> V_279 =
F_338 ( V_277 -> V_279 , V_22 [ V_221 ] ) -> V_46 ;
}
}
F_12 ( V_22 [ V_221 ] , V_55 ) ;
}
}
void
F_340 ( const int V_55 , T_2 V_280 )
{
T_42 * V_167 ;
T_4 * V_277 ;
T_41 * V_281 ;
if ( V_280 == - 1 || V_280 == 0 )
return;
V_277 = F_315 ( V_55 ) ;
if ( ! V_277 || ! V_277 -> V_39 ) {
return;
}
for ( V_281 = V_277 -> V_39 ; V_281 ; V_281 = V_281 -> V_46 ) {
V_167 = ( T_42 * ) V_281 -> V_1 ;
if ( * V_167 -> V_278 == V_280 ) {
F_341 ( V_23 , V_167 -> V_36 . V_185 ) ;
V_277 -> V_39 = F_342 ( V_277 -> V_39 , V_281 ) ;
V_277 -> V_279 = F_343 ( V_277 -> V_39 ) ;
break;
}
}
}
static void
F_344 ( V_3 * V_36 )
{
if ( ! V_36 -> V_184 || ! V_36 -> V_184 [ 0 ] ) {
if ( V_36 -> V_185 )
F_141 ( L_48 ,
V_36 -> V_185 ) ;
else
F_141 ( L_49 ) ;
}
if ( ! V_36 -> V_185 || ! V_36 -> V_185 [ 0 ] )
F_141 ( L_50 , V_36 -> V_184 ) ;
if ( V_36 -> V_232 != NULL && ! (
( V_36 -> type == V_121 ) ||
( V_36 -> type == V_122 ) ||
( V_36 -> type == V_123 ) ||
( V_36 -> type == V_124 ) ||
( V_36 -> type == V_126 ) ||
( V_36 -> type == V_127 ) ||
( V_36 -> type == V_128 ) ||
( V_36 -> type == V_129 ) ||
( V_36 -> type == V_130 ) ||
( V_36 -> type == V_125 ) ||
( V_36 -> type == V_120 ) ||
( V_36 -> type == V_65 ) ) )
F_141 ( L_51
L_52 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ) ;
#if 0
if ((hfinfo->strings != NULL) &&
!(hfinfo->display & BASE_RANGE_STRING) &&
!((hfinfo->display & BASE_DISPLAY_E_MASK) == BASE_CUSTOM) &&
(
(hfinfo->type == FT_UINT8) ||
(hfinfo->type == FT_UINT16) ||
(hfinfo->type == FT_UINT24) ||
(hfinfo->type == FT_UINT32) ||
(hfinfo->type == FT_INT8) ||
(hfinfo->type == FT_INT16) ||
(hfinfo->type == FT_INT24) ||
(hfinfo->type == FT_INT32) ||
(hfinfo->type == FT_FRAMENUM) )) {
int n, m;
const value_string *start_values;
const value_string *current;
if (hfinfo->display & BASE_EXT_STRING)
start_values = VALUE_STRING_EXT_VS_P(((const value_string_ext*)hfinfo->strings));
else
start_values = (const value_string*)hfinfo->strings;
current = start_values;
for (n=0; current; n++, current++) {
if ((current->value == 0) && (current->strptr == NULL)) {
break;
}
for (m=0; m < n; m++) {
if ((start_values[m].value == current->value) &&
(strcmp(start_values[m].strptr, current->strptr) != 0)) {
g_warning("Field '%s' (%s) has a conflicting entry in its"
" value_string: %u is at indices %u (%s) and %u (%s))\n",
hfinfo->name, hfinfo->abbrev,
current->value, m, start_values[m].strptr, n, current->strptr);
}
}
}
}
#endif
switch ( V_36 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_125 :
switch ( V_36 -> V_230 & V_235 ) {
case V_283 :
case V_284 :
case V_285 :
case V_286 :
F_141 ( L_54 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ,
F_345 ( V_36 -> V_230 , V_287 , L_55 ) ) ;
}
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_126 :
switch ( V_36 -> V_230 & V_235 ) {
case V_239 :
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_236 :
break;
default:
F_141 ( L_56
L_57 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ,
F_345 ( V_36 -> V_230 , V_287 , L_58 ) ) ;
}
break;
case V_65 :
case V_177 :
if ( V_36 -> V_230 != V_240 )
F_141 ( L_59 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ,
F_345 ( V_36 -> V_230 , V_287 , L_55 ) ) ;
if ( V_36 -> V_178 != 0 )
F_141 ( L_60 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ) ;
break;
case V_120 :
break;
case V_156 :
if ( ! ( V_36 -> V_230 == V_288 ||
V_36 -> V_230 == V_289 ||
V_36 -> V_230 == V_290 ) )
F_141 ( L_61 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ,
F_345 ( V_36 -> V_230 , V_287 , L_55 ) ) ;
if ( V_36 -> V_178 != 0 )
F_141 ( L_60 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ) ;
break;
default:
if ( V_36 -> V_230 != V_240 )
F_141 ( L_59 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ,
F_345 ( V_36 -> V_230 , V_287 , L_55 ) ) ;
if ( V_36 -> V_178 != 0 )
F_141 ( L_60 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ) ;
if ( V_36 -> V_232 != NULL )
F_141 ( L_62 ,
V_36 -> V_184 , V_36 -> V_185 ,
F_345 ( V_36 -> type , V_282 , L_53 ) ) ;
break;
}
}
static void
F_14 ( void )
{
static T_43 V_291 [] = {
{ & V_100 , { L_63 , V_292 , V_293 , L_64 , V_294 } } ,
{ & V_101 , { L_63 , V_292 , V_295 , L_64 , V_294 } } ,
} ;
T_44 * V_296 ;
V_297 = F_309 ( L_65 , L_66 , L_67 ) ;
V_296 = F_346 ( V_297 ) ;
F_347 ( V_296 , V_291 , F_348 ( V_291 ) ) ;
F_336 ( V_297 ) ;
}
static int
F_12 ( V_3 * V_36 , const int V_55 )
{
F_344 ( V_36 ) ;
V_36 -> V_55 = V_55 ;
V_36 -> V_228 = NULL ;
V_36 -> V_206 = - 1 ;
if ( V_19 . V_20 >= V_19 . V_21 ) {
if ( ! V_19 . V_22 ) {
V_19 . V_21 = V_298 ;
V_19 . V_22 = ( V_3 * * ) F_310 ( sizeof( V_3 * ) * V_298 ) ;
} else {
V_19 . V_21 += 1000 ;
V_19 . V_22 = ( V_3 * * ) F_349 ( V_19 . V_22 ,
sizeof( V_3 * ) * V_19 . V_21 ) ;
}
}
V_19 . V_22 [ V_19 . V_20 ] = V_36 ;
V_19 . V_20 ++ ;
V_36 -> V_38 = V_19 . V_20 - 1 ;
if ( ( V_36 -> V_184 [ 0 ] != 0 ) && ( V_36 -> V_185 [ 0 ] != 0 ) ) {
V_3 * V_299 ;
T_39 V_68 ;
V_68 = F_350 ( V_300 , V_36 -> V_185 ) ;
if ( V_68 ) {
fprintf ( V_273 , L_68 , V_68 , V_36 -> V_185 ) ;
F_26 ( ! V_68 ) ;
}
V_2 = NULL ;
F_351 ( V_23 , ( T_1 ) ( V_36 -> V_185 ) , V_36 ) ;
if ( V_2 ) {
V_299 =
V_2 -> V_228 ;
V_36 -> V_228 = V_299 ;
if ( V_299 )
V_299 -> V_206 = V_36 -> V_38 ;
V_2 -> V_228 = V_36 ;
V_36 -> V_206 = V_2 -> V_38 ;
}
}
return V_36 -> V_38 ;
}
void
F_352 ( T_2 * const * V_301 , const int V_302 )
{
int V_221 ;
T_2 * const * V_276 = V_301 ;
if ( V_32 != NULL ) {
V_32 = ( V_33 * ) F_349 ( V_32 , ( 1 + ( ( V_34 + V_302 ) / 32 ) ) * sizeof( V_33 ) ) ;
for ( V_221 = V_34 ; V_221 < V_34 + V_302 ; V_221 ++ )
V_32 [ V_221 >> 5 ] &= ~ ( 1 << ( V_221 & 31 ) ) ;
}
for ( V_221 = 0 ; V_221 < V_302 ; V_221 ++ , V_276 ++ , V_34 ++ ) {
if ( * * V_276 != - 1 ) {
F_141 ( L_69
L_70
L_71
L_72 ) ;
}
* * V_276 = V_34 ;
}
}
static inline T_33
F_353 ( char * V_194 , T_33 V_303 , const char * V_173 )
{
if ( V_303 < V_197 )
V_303 += F_258 ( V_194 + V_303 , V_173 , V_197 - V_303 ) ;
return V_303 ;
}
static void
F_354 ( char * V_194 , T_33 V_304 )
{
static const char V_195 [] = L_73 ;
const T_32 V_196 = sizeof( V_195 ) - 1 ;
if ( V_304 < V_197 - V_196 ) {
memmove ( V_194 + V_304 + V_196 , V_194 + V_304 , V_197 - V_304 - V_196 ) ;
memcpy ( V_194 + V_304 , V_195 , V_196 ) ;
V_194 [ V_197 - 1 ] = '\0' ;
} else if ( V_304 < V_197 )
F_258 ( V_194 + V_304 , V_195 , V_197 - V_304 ) ;
}
static T_33
F_355 ( char * V_194 , T_33 V_303 , const V_3 * V_36 , const char * V_305 )
{
T_33 V_304 ;
V_304 = V_303 = F_353 ( V_194 , V_303 , V_36 -> V_184 ) ;
V_303 = F_353 ( V_194 , V_303 , L_74 ) ;
V_303 = F_353 ( V_194 , V_303 , V_305 ? V_305 : L_75 ) ;
if ( V_303 >= V_197 ) {
F_354 ( V_194 , V_304 ) ;
}
return V_303 ;
}
static T_33
F_356 ( char * V_194 , T_33 V_303 , const V_3 * V_36 , const char * V_305 , const char * V_98 )
{
T_33 V_304 ;
V_304 = V_303 = F_353 ( V_194 , V_303 , V_36 -> V_184 ) ;
V_303 = F_353 ( V_194 , V_303 , L_74 ) ;
V_303 = F_353 ( V_194 , V_303 , V_305 ? V_305 : L_75 ) ;
V_303 = F_353 ( V_194 , V_303 , L_76 ) ;
V_303 = F_353 ( V_194 , V_303 , V_98 ? V_98 : L_75 ) ;
V_303 = F_353 ( V_194 , V_303 , L_77 ) ;
if ( V_303 >= V_197 ) {
F_354 ( V_194 , V_304 ) ;
}
return V_303 ;
}
void
F_292 ( T_13 * V_107 , T_17 * V_194 )
{
V_3 * V_36 ;
T_28 * V_170 ;
V_33 integer ;
T_27 V_306 ;
T_34 * V_213 ;
T_30 * V_172 ;
V_33 V_217 ;
const T_17 * V_184 ;
T_35 V_216 ;
if ( ! V_107 ) {
if ( V_194 )
V_194 [ 0 ] = '\0' ;
return;
}
V_36 = V_107 -> V_36 ;
switch ( V_36 -> type ) {
case V_117 :
case V_65 :
F_258 ( V_194 , V_36 -> V_184 , V_197 ) ;
break;
case V_120 :
F_357 ( V_107 , V_194 ) ;
break;
case V_118 :
case V_119 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_355 ( V_194 , 0 , V_36 ,
( V_170 ) ? F_264 ( V_170 , F_265 ( & V_107 -> V_49 ) ) : L_78 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
if ( V_36 -> V_178 ) {
F_358 ( V_107 , V_194 , FALSE ) ;
} else {
F_359 ( V_107 , V_194 , FALSE ) ;
}
break;
case V_177 :
F_359 ( V_107 , V_194 , FALSE ) ;
break;
case V_126 :
F_360 ( V_107 , V_194 , FALSE ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
if ( V_36 -> V_178 ) {
F_358 ( V_107 , V_194 , TRUE ) ;
} else {
F_359 ( V_107 , V_194 , TRUE ) ;
}
break;
case V_125 :
F_360 ( V_107 , V_194 , TRUE ) ;
break;
case V_149 :
F_255 ( V_194 , V_197 ,
L_79 F_286 ( V_243 ) L_37 ,
V_36 -> V_184 , F_287 ( & V_107 -> V_49 ) ) ;
break;
case V_150 :
F_255 ( V_194 , V_197 ,
L_79 F_286 ( V_244 ) L_37 ,
V_36 -> V_184 , F_287 ( & V_107 -> V_49 ) ) ;
break;
case V_156 :
F_355 ( V_194 , 0 , V_36 ,
F_266 ( ( const T_26 * ) F_198 ( & V_107 -> V_49 ) ,
( V_229 ) V_36 -> V_230 , TRUE ) ) ;
break;
case V_163 :
F_255 ( V_194 , V_197 ,
L_80 , V_36 -> V_184 ,
F_267 ( ( const T_26 * ) F_198 ( & V_107 -> V_49 ) ) ) ;
break;
case V_133 :
integer = F_252 ( & V_107 -> V_49 ) ;
F_255 ( V_194 , V_197 ,
L_81 , V_36 -> V_184 ,
F_361 ( integer ) , integer ) ;
break;
case V_138 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_356 ( V_194 , 0 , V_36 ,
F_362 ( V_170 ) ,
F_363 ( V_170 ) ) ;
break;
case V_139 :
V_216 . type = V_307 ;
V_216 . V_20 = V_140 ;
V_216 . V_1 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_255 ( V_194 , V_197 ,
L_82 , V_36 -> V_184 ,
F_364 ( & V_216 ) ) ;
break;
case V_141 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_356 ( V_194 , 0 , V_36 ,
F_365 ( V_170 ) ,
F_366 ( V_170 ) ) ;
break;
case V_131 :
V_213 = ( T_34 * ) F_198 ( & V_107 -> V_49 ) ;
V_217 = F_276 ( V_213 ) ;
F_356 ( V_194 , 0 , V_36 ,
F_367 ( V_217 ) ,
F_277 ( ( T_28 * ) & V_217 ) ) ;
break;
case V_136 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_356 ( V_194 , 0 , V_36 ,
F_368 ( (struct V_214 * ) V_170 ) ,
F_369 ( (struct V_214 * ) V_170 ) ) ;
break;
case V_145 :
V_172 = ( T_30 * ) F_198 ( & V_107 -> V_49 ) ;
F_355 ( V_194 , 0 , V_36 , F_281 ( V_172 ) ) ;
break;
case V_147 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
V_184 = F_284 ( V_170 , F_265 ( & V_107 -> V_49 ) ) ;
if ( V_184 ) {
F_356 ( V_194 , 0 , V_36 ,
F_285 ( V_170 , F_265 ( & V_107 -> V_49 ) ) , V_184 ) ;
} else {
F_355 ( V_194 , 0 , V_36 ,
F_285 ( V_170 , F_265 ( & V_107 -> V_49 ) ) ) ;
}
break;
case V_148 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
V_184 = F_282 ( V_170 , F_265 ( & V_107 -> V_49 ) ) ;
if ( V_184 ) {
F_356 ( V_194 , 0 , V_36 ,
F_283 ( V_170 , F_265 ( & V_107 -> V_49 ) ) , V_184 ) ;
} else {
F_355 ( V_194 , 0 , V_36 ,
F_283 ( V_170 , F_265 ( & V_107 -> V_49 ) ) ) ;
}
break;
case V_143 :
V_306 = F_274 ( & V_107 -> V_49 ) ;
F_356 ( V_194 , 0 , V_36 ,
F_370 ( V_306 ) ,
F_275 ( V_306 ) ) ;
break;
case V_151 :
case V_152 :
case V_153 :
V_170 = ( T_28 * ) F_198 ( & V_107 -> V_49 ) ;
F_355 ( V_194 , 0 , V_36 , F_288 ( V_170 , strlen ( V_170 ) ) ) ;
break;
default:
F_141 ( L_38 ,
V_36 -> type , F_142 ( V_36 -> type ) ) ;
F_139 () ;
break;
}
}
static void
F_357 ( T_13 * V_107 , T_17 * V_194 )
{
char * V_200 = V_194 ;
int V_308 = 0 , V_309 ;
V_33 V_310 ;
V_33 V_49 ;
V_3 * V_36 = V_107 -> V_36 ;
const T_36 * V_218 = ( const T_36 * ) & V_231 ;
if ( V_36 -> V_232 ) {
V_218 = ( const struct T_36 * ) V_36 -> V_232 ;
}
V_49 = F_252 ( & V_107 -> V_49 ) ;
if ( V_36 -> V_178 ) {
V_309 = F_254 ( V_36 ) ;
V_310 = V_49 ;
V_310 <<= F_221 ( V_36 ) ;
V_200 = F_253 ( V_194 , V_310 , V_36 -> V_178 , V_309 ) ;
V_308 = ( int ) ( V_200 - V_194 ) ;
}
F_355 ( V_194 , V_308 , V_36 , V_49 ? V_218 -> V_233 : V_218 -> V_234 ) ;
}
static const char *
F_270 ( V_33 V_49 , const V_3 * V_36 )
{
if ( V_36 -> V_230 & V_311 )
return F_371 ( V_49 , ( const V_312 * ) V_36 -> V_232 ) ;
if ( V_36 -> V_230 & V_313 )
return F_372 ( V_49 , ( const V_314 * ) V_36 -> V_232 ) ;
if ( V_36 -> V_230 & V_315 )
return F_373 ( V_49 , ( const V_316 * ) V_36 -> V_232 ) ;
return F_374 ( V_49 , ( const V_317 * ) V_36 -> V_232 ) ;
}
static const char *
F_375 ( T_27 V_49 , const V_3 * V_36 )
{
if ( V_36 -> V_230 & V_315 )
return F_373 ( V_49 , ( const V_316 * ) V_36 -> V_232 ) ;
F_139 () ;
return NULL ;
}
static const char *
F_376 ( V_33 V_49 , const V_3 * V_36 , const char * V_318 )
{
const char * V_173 = F_270 ( V_49 , V_36 ) ;
return ( V_173 ) ? V_173 : V_318 ;
}
static const char *
F_377 ( T_27 V_49 , const V_3 * V_36 , const char * V_318 )
{
const char * V_173 = F_375 ( V_49 , V_36 ) ;
return ( V_173 ) ? V_173 : V_318 ;
}
static void
F_358 ( T_13 * V_107 , T_17 * V_194 , T_6 V_319 )
{
char * V_200 ;
int V_308 , V_309 ;
V_33 V_310 ;
V_33 V_49 ;
char V_320 [ 32 ] ;
const char * V_321 ;
V_3 * V_36 = V_107 -> V_36 ;
V_309 = F_254 ( V_36 ) ;
if ( V_319 )
V_310 = F_269 ( & V_107 -> V_49 ) ;
else
V_310 = F_252 ( & V_107 -> V_49 ) ;
V_49 = V_310 ;
if ( V_36 -> V_178 ) {
V_310 <<= F_221 ( V_36 ) ;
}
V_200 = F_253 ( V_194 , V_310 , V_36 -> V_178 , V_309 ) ;
V_308 = ( int ) ( V_200 - V_194 ) ;
if ( V_36 -> V_230 == V_236 ) {
T_17 V_237 [ V_197 ] ;
const T_37 V_238 = ( const T_37 ) V_36 -> V_232 ;
F_26 ( V_238 ) ;
V_238 ( V_237 , V_49 ) ;
F_355 ( V_194 , V_308 , V_36 , V_237 ) ;
}
else if ( V_36 -> V_232 ) {
const char * V_322 = F_376 ( V_49 , V_36 , L_83 ) ;
V_321 = F_378 ( V_36 , V_320 , V_49 ) ;
if ( V_321 == NULL )
F_355 ( V_194 , V_308 , V_36 , V_322 ) ;
else
F_356 ( V_194 , V_308 , V_36 , V_322 , V_321 ) ;
}
else {
V_321 = F_272 ( V_36 , V_320 , V_49 ) ;
F_355 ( V_194 , V_308 , V_36 , V_321 ) ;
}
}
static void
F_359 ( T_13 * V_107 , T_17 * V_194 , T_6 V_319 )
{
V_3 * V_36 = V_107 -> V_36 ;
V_33 V_49 ;
char V_320 [ 32 ] ;
const char * V_321 ;
if ( V_319 )
V_49 = F_269 ( & V_107 -> V_49 ) ;
else
V_49 = F_252 ( & V_107 -> V_49 ) ;
if ( V_36 -> V_230 == V_236 ) {
T_17 V_237 [ V_197 ] ;
const T_37 V_238 = ( const T_37 ) V_36 -> V_232 ;
F_26 ( V_238 ) ;
V_238 ( V_237 , V_49 ) ;
F_355 ( V_194 , 0 , V_36 , V_237 ) ;
}
else if ( V_36 -> V_232 ) {
const char * V_322 = F_376 ( V_49 , V_36 , L_83 ) ;
V_321 = F_378 ( V_36 , V_320 , V_49 ) ;
if ( V_321 == NULL )
F_355 ( V_194 , 0 , V_36 , V_322 ) ;
else
F_356 ( V_194 , 0 , V_36 , V_322 , V_321 ) ;
}
else {
V_321 = F_272 ( V_36 , V_320 , V_49 ) ;
F_355 ( V_194 , 0 , V_36 , V_321 ) ;
}
}
static void
F_360 ( T_13 * V_107 , T_17 * V_194 , T_6 V_319 )
{
const char * V_96 = NULL ;
V_3 * V_36 = V_107 -> V_36 ;
T_27 V_49 ;
char V_237 [ V_197 + 1 ] ;
if ( V_319 )
V_96 = F_379 ( V_36 ) ;
else
V_96 = F_380 ( V_36 ) ;
V_49 = F_274 ( & V_107 -> V_49 ) ;
if ( F_381 ( V_36 -> V_230 ) )
F_255 ( V_237 , V_197 , V_96 , V_49 , V_49 ) ;
else
F_255 ( V_237 , V_197 , V_96 , V_49 ) ;
if ( V_36 -> V_232 ) {
const char * V_322 = F_377 ( V_49 , V_36 , L_83 ) ;
if ( ( V_36 -> V_230 & V_235 ) == V_240 ) {
F_355 ( V_194 , 0 , V_36 , V_322 ) ;
}
else {
F_356 ( V_194 , 0 , V_36 , V_322 , V_237 ) ;
}
}
else {
F_355 ( V_194 , 0 , V_36 , V_237 ) ;
}
}
int
F_221 ( const V_3 * V_36 )
{
const V_33 V_178 = V_36 -> V_178 ;
#if F_382 ( V_323 ) && ( ( V_323 > 3 ) || ( V_323 == 3 && V_324 >= 4 ) )
F_248 ( V_178 != 0 ) ;
return F_383 ( V_178 ) ;
#else
static const int V_325 [ 32 ] = {
0 , 1 , 28 , 2 , 29 , 14 , 24 , 3 , 30 , 22 , 20 , 15 , 25 , 17 , 4 , 8 ,
31 , 27 , 13 , 23 , 21 , 19 , 16 , 7 , 26 , 12 , 18 , 6 , 11 , 5 , 10 , 9
} ;
return V_325 [ ( ( V_33 ) ( ( V_178 & - ( T_25 ) V_178 ) * 0x077CB531U ) ) >> 27 ] ;
#endif
}
int
F_254 ( const V_3 * V_36 )
{
int V_309 = 0 ;
if ( ! V_36 -> V_178 ) {
return 0 ;
}
switch ( V_36 -> type ) {
case V_121 :
case V_127 :
V_309 = 8 ;
break;
case V_122 :
case V_128 :
V_309 = 16 ;
break;
case V_123 :
case V_129 :
V_309 = 24 ;
break;
case V_124 :
case V_130 :
V_309 = 32 ;
break;
case V_120 :
V_309 = V_36 -> V_230 ;
break;
default:
F_139 () ;
;
}
return V_309 ;
}
static int
F_384 ( int type )
{
switch ( type ) {
case V_127 :
case V_121 :
return 2 ;
case V_122 :
case V_128 :
return 4 ;
case V_123 :
case V_129 :
return 6 ;
case V_124 :
case V_130 :
return 8 ;
default:
F_139 () ;
;
}
return - 1 ;
}
static const char *
F_271 ( const V_3 * V_36 , int V_230 , char V_320 [ 32 ] , V_33 V_49 )
{
char * V_276 = & V_320 [ 31 ] ;
T_6 V_326 = F_268 ( V_36 -> type ) ;
* V_276 = '\0' ;
switch ( V_230 ) {
case V_239 :
return V_326 ? F_385 ( V_276 , ( T_25 ) V_49 ) : F_386 ( V_276 , V_49 ) ;
case V_285 :
* ( -- V_276 ) = ')' ;
V_276 = F_387 ( V_276 , F_384 ( V_36 -> type ) , V_49 ) ;
* ( -- V_276 ) = '(' ;
* ( -- V_276 ) = ' ' ;
V_276 = V_326 ? F_385 ( V_276 , ( T_25 ) V_49 ) : F_386 ( V_276 , V_49 ) ;
return V_276 ;
case V_284 :
return F_388 ( V_276 , V_49 ) ;
case V_283 :
return F_387 ( V_276 , F_384 ( V_36 -> type ) , V_49 ) ;
case V_286 :
* ( -- V_276 ) = ')' ;
V_276 = V_326 ? F_385 ( V_276 , ( T_25 ) V_49 ) : F_386 ( V_276 , V_49 ) ;
* ( -- V_276 ) = '(' ;
* ( -- V_276 ) = ' ' ;
V_276 = F_387 ( V_276 , F_384 ( V_36 -> type ) , V_49 ) ;
return V_276 ;
default:
F_139 () ;
;
}
return V_276 ;
}
static const char *
F_272 ( const V_3 * V_36 , char V_320 [ 32 ] , V_33 V_49 )
{
int V_230 = V_36 -> V_230 ;
if ( V_36 -> type == V_177 ) {
V_230 = V_239 ;
}
return F_271 ( V_36 , V_230 , V_320 , V_49 ) ;
}
static const char *
F_273 ( const V_3 * V_36 , char V_320 [ 32 ] , V_33 V_49 )
{
int V_230 = V_36 -> V_230 & V_235 ;
if ( V_36 -> type == V_177 ) {
V_230 = V_239 ;
}
switch ( V_230 ) {
case V_240 :
case V_285 :
case V_284 :
case V_236 :
V_230 = V_239 ;
break;
case V_286 :
V_230 = V_283 ;
break;
}
return F_271 ( V_36 , V_230 , V_320 , V_49 ) ;
}
static const char *
F_378 ( const V_3 * V_36 , char V_320 [ 32 ] , V_33 V_49 )
{
int V_230 = V_36 -> V_230 & V_235 ;
if ( V_230 == V_240 )
return NULL ;
if ( V_230 == V_285 )
V_230 = V_239 ;
if ( V_230 == V_286 )
V_230 = V_283 ;
return F_271 ( V_36 , V_230 , V_320 , V_49 ) ;
}
static const char *
F_380 ( const V_3 * V_36 )
{
const char * V_96 = NULL ;
switch ( V_36 -> V_230 & V_235 ) {
case V_239 :
V_96 = L_33 V_241 L_35 ;
break;
case V_285 :
V_96 = L_33 V_241 L_84 V_241 L_85 ;
break;
case V_284 :
V_96 = L_86 V_241 L_87 ;
break;
case V_283 :
V_96 = L_88 V_241 L_89 ;
break;
case V_286 :
V_96 = L_88 V_241 L_90 V_241 L_91 ;
break;
default:
F_139 () ;
;
}
return V_96 ;
}
static const char *
F_379 ( const V_3 * V_36 )
{
const char * V_96 = NULL ;
switch ( V_36 -> V_230 & V_235 ) {
case V_239 :
V_96 = L_33 V_241 L_34 ;
break;
case V_285 :
V_96 = L_33 V_241 L_92 V_241 L_85 ;
break;
case V_284 :
V_96 = L_86 V_241 L_87 ;
break;
case V_283 :
V_96 = L_88 V_241 L_89 ;
break;
case V_286 :
V_96 = L_88 V_241 L_90 V_241 L_93 ;
break;
default:
F_139 () ;
;
}
return V_96 ;
}
int
F_389 ( void )
{
return V_19 . V_20 ;
}
const char *
F_390 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return V_36 -> V_184 ;
}
const char *
F_391 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return V_36 -> V_185 ;
}
enum V_327
F_392 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return V_36 -> type ;
}
int
F_393 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return V_36 -> V_55 ;
}
T_6
F_394 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return ( V_36 -> V_55 == - 1 ? TRUE : FALSE ) ;
}
T_2
F_395 ( const int V_111 )
{
V_3 * V_36 ;
F_25 ( V_111 , V_36 ) ;
return F_396 ( V_36 -> type ) ;
}
T_6
F_397 ( const T_7 * V_40 , const int V_38 )
{
T_12 * V_51 = F_261 ( V_40 , V_38 ) ;
if ( ! V_51 ) {
return FALSE ;
}
else if ( F_262 ( V_51 ) > 0 ) {
return TRUE ;
}
else {
return FALSE ;
}
}
T_12 *
F_261 ( const T_7 * V_40 , const int V_38 )
{
if ( ! V_40 )
return NULL ;
if ( F_41 ( V_40 ) -> V_60 != NULL )
return ( T_12 * ) F_60 ( F_41 ( V_40 ) -> V_60 ,
F_103 ( V_38 ) ) ;
else
return NULL ;
}
T_6
F_398 ( const T_7 * V_40 )
{
if ( ! V_40 )
return FALSE ;
return ( F_41 ( V_40 ) -> V_60 != NULL ) ;
}
static T_6
F_399 ( T_9 * V_47 , T_1 V_1 )
{
T_13 * V_107 = F_37 ( V_47 ) ;
if ( V_107 && V_107 -> V_36 ) {
if ( V_107 -> V_36 -> V_38 == ( ( V_328 * ) V_1 ) -> V_38 ) {
F_105 ( ( ( V_328 * ) V_1 ) -> V_329 , V_107 ) ;
}
}
return FALSE ;
}
T_12 *
F_400 ( T_7 * V_40 , const int V_38 )
{
V_328 V_330 ;
V_330 . V_329 = F_104 () ;
V_330 . V_38 = V_38 ;
F_31 ( V_40 , F_399 , & V_330 ) ;
return V_330 . V_329 ;
}
static T_6
F_401 ( T_9 * V_47 , T_1 V_1 )
{
T_13 * V_107 = F_37 ( V_47 ) ;
if ( V_107 && V_107 -> V_36 ) {
F_105 ( ( ( V_328 * ) V_1 ) -> V_329 , V_107 ) ;
}
return FALSE ;
}
T_12 *
F_402 ( T_7 * V_40 )
{
V_328 V_330 ;
V_330 . V_329 = F_104 () ;
V_330 . V_38 = 0 ;
F_31 ( V_40 , F_401 , & V_330 ) ;
return V_330 . V_329 ;
}
static T_6
F_403 ( T_9 * V_47 , const T_1 V_1 )
{
T_13 * V_107 = F_37 ( V_47 ) ;
T_45 * V_331 = ( T_45 * ) V_1 ;
if ( V_107 && ! F_249 ( V_47 ) && V_107 -> V_191 && V_331 -> V_87 == V_107 -> V_191 ) {
if ( V_331 -> V_88 >= ( T_16 ) V_107 -> V_97 &&
V_331 -> V_88 < ( T_16 ) ( V_107 -> V_97 + V_107 -> V_93 ) ) {
V_331 -> V_57 = V_107 ;
return FALSE ;
}
}
return FALSE ;
}
T_13 *
F_404 ( T_7 * V_40 , T_16 V_88 , T_22 * V_87 )
{
T_45 V_331 ;
V_331 . V_88 = V_88 ;
V_331 . V_57 = NULL ;
V_331 . V_87 = V_87 ;
F_31 ( V_40 , F_403 , & V_331 ) ;
return V_331 . V_57 ;
}
void
F_405 ( void )
{
T_4 * V_35 ;
int V_221 ;
void * V_268 = NULL ;
V_221 = F_317 ( & V_268 ) ;
while ( V_221 != - 1 ) {
V_35 = F_315 ( V_221 ) ;
printf ( L_94 , V_35 -> V_184 , V_35 -> V_8 ,
V_35 -> V_261 ) ;
V_221 = F_319 ( & V_268 ) ;
}
}
void
F_406 ( void )
{
V_3 * V_36 ;
int V_221 , V_20 , V_332 ;
const V_317 * V_333 ;
const V_316 * V_334 ;
const V_312 * V_335 ;
const T_36 * V_336 ;
V_20 = V_19 . V_20 ;
for ( V_221 = 0 ; V_221 < V_20 ; V_221 ++ ) {
F_25 ( V_221 , V_36 ) ;
if ( V_36 -> V_38 == V_25 ) {
continue;
}
if ( F_394 ( V_221 ) ) {
continue;
}
else {
if ( V_36 -> V_206 != - 1 )
continue;
V_333 = NULL ;
V_334 = NULL ;
V_335 = NULL ;
V_336 = NULL ;
if ( V_36 -> V_232 != NULL ) {
if ( ( V_36 -> V_230 & V_235 ) != V_236 &&
( V_36 -> type == V_121 ||
V_36 -> type == V_122 ||
V_36 -> type == V_123 ||
V_36 -> type == V_124 ||
V_36 -> type == V_126 ||
V_36 -> type == V_127 ||
V_36 -> type == V_128 ||
V_36 -> type == V_129 ||
V_36 -> type == V_130 ||
V_36 -> type == V_125 ) ) {
if ( V_36 -> V_230 & V_311 ) {
V_335 = ( const V_312 * ) V_36 -> V_232 ;
} else if ( V_36 -> V_230 & V_313 ) {
V_333 = F_407 ( ( const V_314 * ) V_36 -> V_232 ) ;
} else if ( V_36 -> V_230 & V_315 ) {
V_334 = ( const V_316 * ) V_36 -> V_232 ;
} else {
V_333 = ( const V_317 * ) V_36 -> V_232 ;
}
}
else if ( V_36 -> type == V_120 ) {
V_336 = ( const struct T_36 * ) V_36 -> V_232 ;
}
}
if ( V_333 ) {
if ( V_36 -> V_230 & V_313 ) {
const V_314 * V_337 = ( const V_314 * ) V_36 -> V_232 ;
if ( ! F_408 ( V_337 ) ) {
F_409 ( L_95 , V_36 -> V_185 ) ;
continue;
}
F_372 ( 0 , V_337 ) ;
printf ( L_96 ,
V_36 -> V_185 ,
F_410 ( V_337 ) ,
F_411 ( V_337 ) ,
F_412 ( V_337 ) ) ;
}
V_332 = 0 ;
while ( V_333 [ V_332 ] . V_338 ) {
if ( V_36 -> V_230 == V_283 ) {
printf ( L_97 ,
V_36 -> V_185 ,
V_333 [ V_332 ] . V_49 ,
V_333 [ V_332 ] . V_338 ) ;
}
else {
printf ( L_98 ,
V_36 -> V_185 ,
V_333 [ V_332 ] . V_49 ,
V_333 [ V_332 ] . V_338 ) ;
}
V_332 ++ ;
}
}
else if ( V_334 ) {
V_332 = 0 ;
while ( V_334 [ V_332 ] . V_338 ) {
printf ( L_99 V_241 L_100 ,
V_36 -> V_185 ,
V_334 [ V_332 ] . V_49 ,
V_334 [ V_332 ] . V_338 ) ;
V_332 ++ ;
}
}
else if ( V_335 ) {
V_332 = 0 ;
while ( V_335 [ V_332 ] . V_338 ) {
if ( ( V_36 -> V_230 & V_235 ) == V_283 ) {
printf ( L_101 ,
V_36 -> V_185 ,
V_335 [ V_332 ] . V_339 ,
V_335 [ V_332 ] . V_340 ,
V_335 [ V_332 ] . V_338 ) ;
}
else {
printf ( L_102 ,
V_36 -> V_185 ,
V_335 [ V_332 ] . V_339 ,
V_335 [ V_332 ] . V_340 ,
V_335 [ V_332 ] . V_338 ) ;
}
V_332 ++ ;
}
}
else if ( V_336 ) {
printf ( L_103 , V_36 -> V_185 ,
V_336 -> V_233 , V_336 -> V_234 ) ;
}
}
}
}
void
F_413 ( void )
{
V_3 * V_36 , * V_56 ;
int V_221 , V_20 ;
const char * V_341 ;
const char * V_342 ;
const char * V_267 ;
char V_343 [ 5 ] ;
V_20 = V_19 . V_20 ;
for ( V_221 = 0 ; V_221 < V_20 ; V_221 ++ ) {
F_25 ( V_221 , V_36 ) ;
if ( V_36 -> V_38 == V_25 )
continue;
if ( F_394 ( V_221 ) ) {
printf ( L_104 , V_36 -> V_184 , V_36 -> V_185 ) ;
}
else {
if ( V_36 -> V_206 != - 1 )
continue;
F_25 ( V_36 -> V_55 , V_56 ) ;
V_341 = F_142 ( V_36 -> type ) ;
V_342 = L_28 ;
if ( V_36 -> type == V_121 ||
V_36 -> type == V_122 ||
V_36 -> type == V_123 ||
V_36 -> type == V_124 ||
V_36 -> type == V_126 ||
V_36 -> type == V_127 ||
V_36 -> type == V_128 ||
V_36 -> type == V_129 ||
V_36 -> type == V_130 ||
V_36 -> type == V_125 ) {
switch ( V_36 -> V_230 & V_235 ) {
case V_240 :
V_342 = L_105 ;
break;
case V_239 :
V_342 = L_106 ;
break;
case V_283 :
V_342 = L_107 ;
break;
case V_284 :
V_342 = L_108 ;
break;
case V_285 :
V_342 = L_109 ;
break;
case V_286 :
V_342 = L_110 ;
break;
case V_236 :
V_342 = L_111 ;
break;
default:
V_342 = L_112 ;
break;
}
} else if ( V_36 -> type == V_120 ) {
F_255 ( V_343 , sizeof( V_343 ) , L_113 , V_36 -> V_230 ) ;
V_342 = V_343 ;
}
V_267 = V_36 -> V_267 ;
if ( V_267 == NULL )
V_267 = L_28 ;
else if ( strlen ( V_267 ) == 0 )
V_267 = L_114 ;
printf ( L_115 ,
V_36 -> V_184 , V_36 -> V_185 , V_341 ,
V_56 -> V_185 , V_342 , V_36 -> V_178 , V_267 ) ;
}
}
}
void
F_414 ( void )
{
int V_344 ;
for ( V_344 = 0 ; V_344 < V_345 ; V_344 ++ ) {
printf ( L_116 , F_142 ( ( V_346 ) V_344 ) , F_415 ( ( V_346 ) V_344 ) ) ;
}
}
static const char *
F_416 ( const V_3 * V_36 )
{
const char * V_96 = NULL ;
switch ( V_36 -> V_230 & V_235 ) {
case V_239 :
case V_285 :
case V_284 :
case V_236 :
switch ( V_36 -> type ) {
case V_126 :
V_96 = L_117 V_241 L_35 ;
break;
case V_125 :
V_96 = L_117 V_241 L_34 ;
break;
default:
F_139 () ;
;
}
break;
case V_283 :
case V_286 :
switch ( V_36 -> type ) {
case V_126 :
case V_125 :
V_96 = L_118 V_241 L_89 ;
break;
default:
F_139 () ;
;
}
break;
default:
F_139 () ;
;
}
return V_96 ;
}
static T_6
F_417 ( T_13 * V_57 , T_46 * V_347 ,
char * * V_348 )
{
V_3 * V_36 ;
int V_349 ;
char * V_276 ;
int V_350 ;
int V_351 , V_221 ;
T_2 V_97 , V_93 , V_187 ;
T_28 V_68 ;
T_17 V_352 = FALSE ;
if ( ! V_57 )
return FALSE ;
V_36 = V_57 -> V_36 ;
F_26 ( V_36 ) ;
V_349 = ( int ) strlen ( V_36 -> V_185 ) ;
if ( V_36 -> V_232 && ( V_36 -> V_230 & V_235 ) == V_240 ) {
const T_17 * V_173 = NULL ;
switch ( V_36 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_173 = F_270 ( F_269 ( & V_57 -> V_49 ) , V_36 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_173 = F_270 ( F_252 ( & V_57 -> V_49 ) , V_36 ) ;
break;
default:
break;
}
if ( V_173 != NULL && V_348 != NULL ) {
* V_348 = F_238 ( L_119 , V_36 -> V_185 , V_173 ) ;
return TRUE ;
}
}
switch ( V_36 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_352 = TRUE ;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_177 :
if ( V_348 != NULL ) {
V_33 V_212 ;
char V_320 [ 32 ] ;
const char * V_321 ;
if ( V_352 )
V_212 = F_269 ( & V_57 -> V_49 ) ;
else
V_212 = F_252 ( & V_57 -> V_49 ) ;
V_321 = F_273 ( V_36 , V_320 , V_212 ) ;
* V_348 = F_238 ( L_120 , V_36 -> V_185 , V_321 ) ;
}
break;
case V_125 :
case V_126 :
if ( V_348 != NULL ) {
const char * V_96 = F_416 ( V_36 ) ;
* V_348 = F_238 ( V_96 ,
V_36 -> V_185 ,
F_274 ( & V_57 -> V_49 ) ) ;
}
break;
case V_65 :
if ( V_348 != NULL )
* V_348 = F_50 ( V_57 -> V_36 -> V_185 ) ;
break;
case V_117 :
V_93 = V_57 -> V_93 ;
if ( V_93 == 0 ) {
if ( V_348 != NULL )
* V_348 = F_50 ( V_57 -> V_36 -> V_185 ) ;
break;
}
if ( V_93 < 0 )
return FALSE ;
if ( V_347 == NULL )
return FALSE ;
if ( V_57 -> V_191 != V_347 -> V_87 )
return FALSE ;
V_187 = F_241 ( V_57 -> V_191 , V_57 -> V_97 ) ;
if ( V_93 > V_187 )
V_93 = V_187 ;
if ( V_93 <= 0 )
return FALSE ;
if ( V_348 != NULL ) {
V_97 = V_57 -> V_97 ;
V_350 = 32 + V_93 * 3 ;
* V_348 = ( char * ) F_418 ( V_350 ) ;
V_276 = * V_348 ;
V_276 += F_255 ( V_276 , ( V_247 ) ( V_350 - ( V_276 - * V_348 ) ) ,
L_121 , V_57 -> V_97 , V_93 ) ;
for ( V_221 = 0 ; V_221 < V_93 ; V_221 ++ ) {
V_68 = F_94 ( V_57 -> V_191 , V_97 ) ;
V_97 ++ ;
if ( V_221 == 0 ) {
V_276 += F_255 ( V_276 , ( V_247 ) ( V_350 - ( V_276 - * V_348 ) ) , L_122 , V_68 ) ;
}
else {
V_276 += F_255 ( V_276 , ( V_247 ) ( V_350 - ( V_276 - * V_348 ) ) , L_123 , V_68 ) ;
}
}
}
break;
case V_245 :
F_139 () ;
break;
default:
if ( V_348 != NULL ) {
V_351 = F_419 ( & V_57 -> V_49 ,
V_353 ) ;
V_351 += V_349 + 4 + 1 ;
* V_348 = ( char * ) F_418 ( V_351 ) ;
F_255 ( * V_348 , V_351 , L_124 ,
V_36 -> V_185 ) ;
F_420 ( & V_57 -> V_49 ,
V_353 ,
& ( * V_348 ) [ V_349 + 4 ] ) ;
}
break;
}
return TRUE ;
}
T_6
F_421 ( T_13 * V_57 , T_46 * V_347 )
{
return F_417 ( V_57 , V_347 , NULL ) ;
}
char *
F_422 ( T_13 * V_57 , T_46 * V_347 )
{
char * V_348 ;
if ( ! F_417 ( V_57 , V_347 , & V_348 ) )
return NULL ;
return V_348 ;
}
static T_6
F_423 ( T_23 * V_168 , T_22 * V_87 , const int V_88 ,
const int V_20 , const T_2 V_354 , const int * * V_39 ,
const T_16 V_95 , const int V_188 ,
T_6 V_355 )
{
V_33 V_49 = 0 ;
V_33 V_356 = 0 ;
V_33 V_357 ;
T_7 * V_40 = NULL ;
V_3 * V_167 ;
switch ( V_20 ) {
case 1 :
V_49 = F_94 ( V_87 , V_88 ) ;
V_356 = 0xFF ;
break;
case 2 :
V_49 = V_95 ? F_95 ( V_87 , V_88 ) :
F_96 ( V_87 , V_88 ) ;
V_356 = 0xFFFF ;
break;
case 3 :
V_49 = V_95 ? F_97 ( V_87 , V_88 ) :
F_98 ( V_87 , V_88 ) ;
V_356 = 0xFFFFFF ;
break;
case 4 :
V_49 = V_95 ? F_99 ( V_87 , V_88 ) :
F_100 ( V_87 , V_88 ) ;
V_356 = 0xFFFFFFFF ;
break;
default:
F_424 () ;
}
V_40 = F_77 ( V_168 , V_354 ) ;
while ( * V_39 ) {
V_33 V_358 ;
V_167 = F_48 ( * * V_39 ) ;
F_26 ( V_167 -> V_178 != 0 ) ;
V_358 = V_356 & V_167 -> V_178 ;
if ( V_358 != V_167 -> V_178 ) {
V_39 ++ ;
continue;
}
F_151 ( V_40 , * * V_39 , V_87 , V_88 , V_20 , V_95 ) ;
if ( V_188 & V_359 ) {
V_39 ++ ;
continue;
}
V_357 = ( V_49 & V_167 -> V_178 ) >> F_221 ( V_167 ) ;
switch ( V_167 -> type ) {
case V_127 :
case V_121 :
case V_128 :
case V_122 :
case V_129 :
case V_123 :
case V_130 :
case V_124 :
if ( V_167 -> V_230 == V_236 ) {
T_17 V_360 [ V_197 ] ;
const T_37 V_238 = ( const T_37 ) V_167 -> V_232 ;
F_26 ( V_238 ) ;
V_238 ( V_360 , V_357 ) ;
F_291 ( V_168 , L_125 , V_355 ? L_28 : L_126 ,
V_167 -> V_184 , V_360 ) ;
V_355 = FALSE ;
}
else if ( V_167 -> V_232 ) {
F_291 ( V_168 , L_125 , V_355 ? L_28 : L_126 ,
V_167 -> V_184 , F_376 ( V_357 , V_167 , L_83 ) ) ;
V_355 = FALSE ;
}
else if ( ! ( V_188 & V_361 ) ) {
char V_320 [ 32 ] ;
const char * V_321 ;
if ( ! V_355 ) {
F_291 ( V_168 , L_126 ) ;
}
V_321 = F_272 ( V_167 , V_320 , V_357 ) ;
F_291 ( V_168 , L_82 , V_167 -> V_184 , V_321 ) ;
V_355 = FALSE ;
}
break;
case V_120 :
if ( V_167 -> V_232 && ! ( V_188 & V_362 ) ) {
const struct T_36 * V_336 =
( const struct T_36 * ) V_167 -> V_232 ;
if ( V_357 ) {
F_291 ( V_168 , L_125 , V_355 ? L_28 : L_126 ,
V_167 -> V_184 , V_336 -> V_233 ) ;
V_355 = FALSE ;
} else if ( ! ( V_188 & V_363 ) ) {
F_291 ( V_168 , L_125 , V_355 ? L_28 : L_126 ,
V_167 -> V_184 , V_336 -> V_234 ) ;
V_355 = FALSE ;
}
} else if ( V_167 -> V_178 & V_49 ) {
F_291 ( V_168 , L_127 , V_355 ? L_28 : L_126 , V_167 -> V_184 ) ;
V_355 = FALSE ;
}
break;
default:
F_424 () ;
}
V_39 ++ ;
}
return V_355 ;
}
T_23 *
F_425 ( T_7 * V_364 , T_22 * V_87 ,
const T_16 V_88 , const int V_365 ,
const T_2 V_354 , const int * * V_39 ,
const T_16 V_95 )
{
T_23 * V_168 = NULL ;
V_3 * V_167 ;
int V_20 ;
V_167 = F_48 ( V_365 ) ;
F_26 ( F_268 ( V_167 -> type ) || F_251 ( V_167 -> type ) ) ;
V_20 = F_396 ( V_167 -> type ) ;
if ( V_364 ) {
V_168 = F_151 ( V_364 , V_365 , V_87 , V_88 , V_20 , V_95 ) ;
F_423 ( V_168 , V_87 , V_88 , V_20 , V_354 , V_39 , V_95 ,
V_361 | V_362 , FALSE ) ;
}
return V_168 ;
}
T_23 *
F_426 ( T_7 * V_364 , T_22 * V_87 ,
const T_16 V_88 , const T_16 V_20 , const int V_365 ,
const T_2 V_354 , const int * * V_39 , struct V_366 * exp ,
const T_16 V_95 )
{
T_23 * V_168 = NULL ;
V_3 * V_167 ;
T_16 V_367 ;
T_16 V_368 ;
V_33 V_369 ;
V_167 = F_48 ( V_365 ) ;
F_26 ( F_268 ( V_167 -> type ) || F_251 ( V_167 -> type ) ) ;
V_368 = V_88 ;
V_367 = F_427 ( V_20 , ( T_16 ) F_396 ( V_167 -> type ) ) ;
if ( V_95 == V_135 ) {
V_368 += ( V_20 - V_367 ) ;
}
if ( V_364 ) {
V_369 = F_93 ( V_364 , V_87 , V_368 ,
V_367 , V_95 ) ;
V_168 = F_218 ( V_364 , V_365 , V_87 , V_88 , V_20 ,
V_369 ) ;
}
if ( V_367 < V_20 ) {
F_91 ( NULL , V_168 , exp ,
L_128 ,
V_367 , V_20 ) ;
}
if ( V_168 ) {
F_423 ( V_168 , V_87 , V_368 , V_367 ,
V_354 , V_39 , V_95 , V_361 | V_362 , FALSE ) ;
}
return V_168 ;
}
T_23 *
F_428 ( T_7 * V_364 , T_22 * V_87 ,
const T_16 V_88 , const T_16 V_20 ,
const char * V_184 , const char * V_370 ,
const T_2 V_354 , const int * * V_39 ,
const T_16 V_95 , const int V_188 )
{
T_23 * V_168 = NULL ;
if ( V_364 ) {
V_168 = F_87 ( V_364 , V_87 , V_88 , V_20 , L_22 , V_184 ? V_184 : L_28 ) ;
if ( F_423 ( V_168 , V_87 , V_88 , V_20 , V_354 , V_39 , V_95 ,
V_188 , TRUE ) && V_370 ) {
F_291 ( V_168 , L_22 , V_370 ) ;
}
}
return V_168 ;
}
T_23 *
F_429 ( T_7 * V_40 , const int V_66 , T_22 * V_87 ,
const T_16 V_371 , const T_2 V_179 ,
const T_16 V_95 )
{
V_3 * V_36 ;
T_2 V_372 ;
F_25 ( V_66 , V_36 ) ;
V_372 = V_371 >> 3 ;
if ( V_87 ) {
F_150 ( V_87 , V_372 ) ;
}
F_82 ( V_40 , V_66 , V_36 ) ;
return F_430 ( V_40 , V_66 , V_87 , V_371 , V_179 , NULL , V_95 ) ;
}
static T_23 *
F_431 ( T_7 * V_40 , const int V_66 , T_22 * V_87 ,
const T_16 V_371 , const T_2 V_179 ,
T_27 * V_373 , const T_16 V_95 )
{
T_2 V_88 ;
T_16 V_93 ;
T_28 V_374 ;
char * V_375 ;
char V_376 [ V_197 ] ;
T_27 V_49 = 0 ;
T_23 * V_76 ;
V_3 * V_377 ;
const T_36 * V_218 ;
F_25 ( V_66 , V_377 ) ;
if ( V_377 -> V_178 != 0 ) {
F_237 ( F_238 ( L_129
L_130 ,
V_377 -> V_185 , V_377 -> V_184 ) ) ;
}
F_26 ( V_179 > 0 ) ;
V_88 = V_371 >> 3 ;
V_374 = ( ( V_371 & 0x7 ) + V_179 ) ;
V_93 = ( V_374 + 7 ) >> 3 ;
if ( V_179 < 65 ) {
V_49 = F_432 ( V_87 , V_371 , V_179 , V_95 ) ;
} else {
F_139 () ;
return NULL ;
}
switch ( V_377 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_125 :
if ( V_49 & ( F_433 ( 1 ) << ( V_179 - 1 ) ) )
V_49 |= ( F_433 ( - 1 ) << V_179 ) ;
break;
default:
break;
}
if ( V_373 ) {
* V_373 = V_49 ;
}
F_82 ( V_40 , V_66 , V_377 ) ;
V_375 = F_434 ( V_371 , V_179 , V_49 ) ;
switch ( V_377 -> type ) {
case V_120 :
V_218 = ( const T_36 * ) & V_231 ;
if ( V_377 -> V_232 )
V_218 = ( const T_36 * ) V_377 -> V_232 ;
return F_210 ( V_40 , V_66 , V_87 , V_88 , V_93 , ( V_33 ) V_49 ,
L_131 ,
V_375 , V_377 -> V_184 ,
( V_33 ) V_49 ? V_218 -> V_233 : V_218 -> V_234 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_76 = F_218 ( V_40 , V_66 , V_87 , V_88 , V_93 , ( V_33 ) V_49 ) ;
F_359 ( F_197 ( V_76 ) , V_376 , FALSE ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_76 = F_225 ( V_40 , V_66 , V_87 , V_88 , V_93 , ( T_25 ) V_49 ) ;
F_359 ( F_197 ( V_76 ) , V_376 , TRUE ) ;
break;
case V_126 :
V_76 = F_222 ( V_40 , V_66 , V_87 , V_88 , V_93 , V_49 ) ;
F_360 ( F_197 ( V_76 ) , V_376 , FALSE ) ;
break;
case V_125 :
V_76 = F_230 ( V_40 , V_66 , V_87 , V_88 , V_93 , ( T_31 ) V_49 ) ;
F_360 ( F_197 ( V_76 ) , V_376 , TRUE ) ;
break;
default:
F_139 () ;
return NULL ;
break;
}
F_289 ( V_76 , L_132 , V_375 , V_376 ) ;
return V_76 ;
}
T_23 *
F_435 ( T_7 * V_40 , const int V_66 , T_22 * V_87 ,
const T_16 V_371 , const T_47 * V_378 ,
T_27 * V_373 )
{
T_23 * V_76 ;
T_2 V_179 ;
T_2 V_372 ;
T_16 V_379 ;
T_16 V_380 ;
T_16 V_381 ;
T_28 V_221 ;
char * V_375 ;
char V_376 [ V_197 ] ;
T_27 V_49 ;
T_27 V_382 ;
T_27 V_383 ;
V_3 * V_377 ;
const T_36 * V_218 ;
F_25 ( V_66 , V_377 ) ;
if ( V_377 -> V_178 != 0 ) {
F_237 ( F_238 (
L_133
L_130 ,
V_377 -> V_185 , V_377 -> V_184 ) ) ;
}
V_379 = V_371 % 8 ;
V_179 = 0 ;
V_49 = 0 ;
V_221 = 0 ;
V_380 = 0 ;
V_382 = 0 ;
V_383 = 0 ;
while ( V_378 [ V_221 ] . V_384 != 0 ) {
T_27 V_385 , V_386 ;
T_28 V_387 ;
F_26 ( V_221 < 64 ) ;
V_386 = F_432 ( V_87 ,
V_371 + V_378 [ V_221 ] . V_388 ,
V_378 [ V_221 ] . V_384 ,
V_135 ) ;
V_49 += V_386 ;
V_179 += V_378 [ V_221 ] . V_384 ;
if ( V_380 < 32 ) {
V_387 = V_379
+ V_378 [ V_221 ] . V_388
+ V_378 [ V_221 ] . V_384 ;
V_385 = ( F_436 ( 1 ) << V_378 [ V_221 ] . V_384 ) - 1 ;
if ( V_387 > V_380 ) {
V_380 = V_387 ;
}
V_382 |= ( V_385 << ( 64 - V_387 ) ) ;
V_383 |= ( V_386 << ( 64 - V_387 ) ) ;
}
V_49 <<= V_378 [ ++ V_221 ] . V_384 ;
}
switch ( V_377 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_125 :
if ( V_179 && ( V_49 & ( F_433 ( 1 ) << ( V_179 - 1 ) ) ) )
V_49 |= ( F_433 ( - 1 ) << V_179 ) ;
break;
default:
break;
}
if ( V_373 ) {
* V_373 = V_49 ;
}
F_82 ( V_40 , V_66 , V_377 ) ;
V_375 = ( char * ) F_64 ( 256 ) ;
V_375 [ 0 ] = '\0' ;
V_372 = V_371 >> 3 ;
V_381 = ( ( V_380 + 7 ) >> 3 ) ;
V_380 = V_381 << 3 ;
if ( V_380 <= 32 ) {
F_437 ( V_375 ,
( V_33 ) ( V_383 >> ( 64 - V_380 ) ) ,
( V_33 ) ( V_382 >> ( 64 - V_380 ) ) ,
V_380 ) ;
}
switch ( V_377 -> type ) {
case V_120 :
V_218 = ( const T_36 * ) & V_231 ;
if ( V_377 -> V_232 )
V_218 = ( const T_36 * ) V_377 -> V_232 ;
return F_210 ( V_40 , V_66 ,
V_87 , V_372 , V_381 , ( V_33 ) V_49 ,
L_131 ,
V_375 , V_377 -> V_184 ,
( V_33 ) V_49 ? V_218 -> V_233 : V_218 -> V_234 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_76 = F_218 ( V_40 , V_66 , V_87 , V_372 , V_381 , ( V_33 ) V_49 ) ;
F_359 ( F_197 ( V_76 ) , V_376 , FALSE ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
V_76 = F_225 ( V_40 , V_66 , V_87 , V_372 , V_381 , ( T_25 ) V_49 ) ;
F_359 ( F_197 ( V_76 ) , V_376 , TRUE ) ;
break;
case V_126 :
V_76 = F_222 ( V_40 , V_66 , V_87 , V_372 , V_381 , V_49 ) ;
F_360 ( F_197 ( V_76 ) , V_376 , FALSE ) ;
break;
case V_125 :
V_76 = F_230 ( V_40 , V_66 , V_87 , V_372 , V_381 , ( T_31 ) V_49 ) ;
F_360 ( F_197 ( V_76 ) , V_376 , TRUE ) ;
break;
default:
F_139 () ;
return NULL ;
break;
}
F_289 ( V_76 , L_132 , V_375 , V_376 ) ;
return V_76 ;
}
void
F_438 ( T_7 * V_40 , const int V_66 , T_22 * V_87 , const T_16 V_371 ,
const T_47 * V_378 , T_48 V_389 )
{
V_3 * V_36 ;
F_25 ( V_66 , V_36 ) ;
F_87 ( V_40 , V_87 ,
V_371 >> 3 ,
( ( V_371 + V_378 [ V_389 ] . V_384 - 1 ) >> 3 ) - ( V_371 >> 3 ) + 1 ,
L_134 ,
F_434 ( V_371 , V_378 [ V_389 ] . V_384 ,
F_439 ( V_87 ,
V_371 ,
V_378 [ V_389 ] . V_384 ,
V_135 ) ) ,
V_389 ,
V_36 -> V_184 ) ;
}
T_23 *
F_430 ( T_7 * V_40 , const int V_66 , T_22 * V_87 ,
const T_16 V_371 , const T_2 V_179 ,
T_27 * V_373 , const T_16 V_95 )
{
T_23 * V_168 ;
if ( ( V_168 = F_431 ( V_40 , V_66 , V_87 ,
V_371 , V_179 ,
V_373 , V_95 ) ) ) {
F_143 ( F_37 ( V_168 ) , F_440 ( V_371 ) ) ;
F_143 ( F_37 ( V_168 ) , F_441 ( V_179 ) ) ;
}
return V_168 ;
}
static T_23 *
F_442 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , void * V_171 ,
T_17 * V_390 )
{
T_2 V_88 ;
T_16 V_93 ;
T_28 V_374 ;
char * V_173 ;
T_27 V_49 = 0 ;
V_3 * V_377 ;
F_82 ( V_40 , V_66 , V_377 ) ;
if ( V_377 -> V_178 != 0 ) {
F_237 ( F_238 (
L_135
L_130 ,
V_377 -> V_185 , V_377 -> V_184 ) ) ;
}
F_26 ( V_179 > 0 ) ;
V_88 = V_371 >> 3 ;
V_374 = ( ( V_371 & 0x7 ) + V_179 ) ;
V_93 = V_374 >> 3 ;
if ( V_374 & 0x07 )
V_93 ++ ;
if ( V_179 < 65 ) {
V_49 = F_432 ( V_87 , V_371 , V_179 , V_135 ) ;
} else {
F_139 () ;
return NULL ;
}
V_173 = F_434 ( V_371 , V_179 , V_49 ) ;
strcat ( V_173 , L_136 ) ;
strcat ( V_173 , V_377 -> V_184 ) ;
switch ( V_377 -> type ) {
case V_120 :
return F_210 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( V_33 * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
case V_124 :
return F_220 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( V_33 * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
case V_126 :
return F_224 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( T_27 * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
return F_227 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( T_25 * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
case V_125 :
return F_232 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( T_31 * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
case V_149 :
return F_213 ( V_40 , V_66 , V_87 , V_88 , V_93 , * ( float * ) V_171 ,
L_82 , V_173 , V_390 ) ;
break;
default:
F_139 () ;
return NULL ;
break;
}
}
static T_23 *
F_443 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , void * V_171 ,
T_17 * V_390 )
{
T_23 * V_168 ;
if ( ( V_168 = F_442 ( V_40 , V_66 ,
V_87 , V_371 , V_179 ,
V_171 , V_390 ) ) ) {
F_143 ( F_37 ( V_168 ) , F_440 ( V_371 ) ) ;
F_143 ( F_37 ( V_168 ) , F_441 ( V_179 ) ) ;
}
return V_168 ;
}
T_23 *
F_444 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , V_33 V_49 ,
const char * V_96 , ... )
{
T_24 V_69 ;
T_17 * V_391 ;
V_3 * V_377 ;
F_82 ( V_40 , V_66 , V_377 ) ;
switch ( V_377 -> type ) {
case V_121 :
case V_122 :
case V_123 :
case V_124 :
break;
default:
F_139 () ;
return NULL ;
break;
}
F_445 ( V_391 , V_96 , V_69 ) ;
return F_443 ( V_40 , V_66 , V_87 , V_371 , V_179 , & V_49 , V_391 ) ;
}
T_23 *
F_446 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , float V_49 ,
const char * V_96 , ... )
{
T_24 V_69 ;
T_17 * V_391 ;
V_3 * V_377 ;
F_82 ( V_40 , V_66 , V_377 ) ;
F_26 ( V_377 -> type == V_149 ) ;
F_445 ( V_391 , V_96 , V_69 ) ;
return F_443 ( V_40 , V_66 , V_87 , V_371 , V_179 , & V_49 , V_391 ) ;
}
T_23 *
F_447 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , T_25 V_49 ,
const char * V_96 , ... )
{
T_24 V_69 ;
T_17 * V_391 ;
V_3 * V_377 ;
F_82 ( V_40 , V_66 , V_377 ) ;
switch ( V_377 -> type ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
break;
default:
F_139 () ;
return NULL ;
break;
}
F_445 ( V_391 , V_96 , V_69 ) ;
return F_443 ( V_40 , V_66 , V_87 , V_371 , V_179 , & V_49 , V_391 ) ;
}
T_23 *
F_448 ( T_7 * V_40 , const int V_66 ,
T_22 * V_87 , const T_16 V_371 ,
const T_2 V_179 , V_33 V_49 ,
const char * V_96 , ... )
{
T_24 V_69 ;
T_17 * V_391 ;
V_3 * V_377 ;
F_82 ( V_40 , V_66 , V_377 ) ;
F_26 ( V_377 -> type == V_120 ) ;
F_445 ( V_391 , V_96 , V_69 ) ;
return F_443 ( V_40 , V_66 , V_87 , V_371 , V_179 , & V_49 , V_391 ) ;
}
T_39
F_449 ( const T_17 * V_80 )
{
return F_350 ( V_300 , V_80 ) ;
}
T_6
F_450 ( int V_183 )
{
F_248 ( V_183 >= 0 && V_183 < V_34 ) ;
return V_32 [ V_183 >> 5 ] & ( 1 << ( V_183 & 31 ) ) ;
}
void
F_451 ( int V_183 , T_6 V_49 )
{
F_248 ( V_183 >= 0 && V_183 < V_34 ) ;
if ( V_49 )
V_32 [ V_183 >> 5 ] |= ( 1 << ( V_183 & 31 ) ) ;
else
V_32 [ V_183 >> 5 ] &= ~ ( 1 << ( V_183 & 31 ) ) ;
}
