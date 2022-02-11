static inline int F_1 ( int V_1 , int V_2 )
{
if ( ( V_2 <= 0 ) || ( V_2 > V_3 ) || ( V_1 <= 0 ) ||
( V_1 > V_4 ) )
{
F_2 ( V_5 L_1 , V_1 , V_2 ) ;
return - 1 ;
}
return ( ( V_6 [ V_1 - 1 ] . V_7 & ( 1 << ( V_2 - 1 ) ) ) != 0 ) ;
}
static void
F_3 ( struct V_8 * V_9 )
{
T_1 * V_10 = V_9 -> V_11 ;
#ifdef F_4
F_2 ( V_12 L_2 ) ;
#endif
F_5 ( & V_10 -> V_13 ) ;
F_6 ( V_9 ) ;
}
static void
F_7 ( struct V_8 * V_9 )
{
int V_14 ;
T_1 * V_10 = NULL ;
T_2 * V_15 = NULL ;
#ifdef F_4
F_2 ( V_12 L_3 ) ;
#endif
V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
if ( ! V_10 ) {
F_2 ( V_5 L_4 ) ;
return;
}
V_15 = V_10 -> V_15 ;
F_8 ( V_9 ) ;
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
if ( V_6 [ V_14 ] . V_16 [ V_9 -> V_17 - 1 ] ) {
F_9 ( V_6 [ V_14 ] . V_16 [ V_9 -> V_17 - 1 ] ) ;
V_6 [ V_14 ] . V_16 [ V_9 -> V_17 - 1 ] = NULL ;
}
}
F_10 ( V_9 ) ;
V_9 -> V_11 = NULL ;
F_11 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
}
static void
F_12 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
T_2 * V_15 = V_10 -> V_15 ;
F_13 ( & V_10 -> V_21 ) ;
#ifdef F_4
F_2 ( V_12 L_5 ) ;
#endif
V_10 -> V_22 [ V_10 -> V_23 ++ ] = V_20 ;
if ( V_10 -> V_23 >= V_24 )
V_10 -> V_23 = 0 ;
V_10 -> V_25 ++ ;
if ( V_10 -> V_25 >= V_24 ) {
F_2 ( V_5 L_6 ,
V_15 -> V_26 ) ;
F_8 ( V_9 ) ;
}
V_10 -> V_27 = V_20 ;
F_14 ( & V_10 -> V_21 ) ;
F_15 ( & V_15 -> V_28 ) ;
}
static void
F_16 ( struct V_8 * V_9 , T_3 V_29 ,
T_4 * V_30 )
{
char V_31 [] = L_7 ;
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
T_2 * V_15 = V_10 -> V_15 ;
struct V_19 * V_20 ;
T_3 V_32 ;
T_5 V_33 = 0xa0 , V_34 = 0x80 ;
T_3 V_35 = 0x0000 ;
T_3 V_36 = 0 ;
int V_37 = strlen ( V_31 ) ;
#ifdef F_4
F_2 ( V_12 L_8 ) ;
#endif
V_36 = V_30 -> V_38 * V_30 -> V_39 * V_30 -> V_40 ;
V_32 = V_41 + 8 + V_37 + 1 ;
if ( ! ( V_20 = F_17 ( V_32 , V_42 ) ) ) {
F_2 ( V_5 L_9 ,
V_15 -> V_26 ) ;
return;
}
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_32 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_29 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_5 ) ) , & V_33 , sizeof( V_33 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_5 ) ) , & V_34 , sizeof( V_34 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_35 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_36 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & ( V_30 -> V_38 ) , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & ( V_30 -> V_39 ) , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & ( V_30 -> V_40 ) , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , V_37 ) , V_31 , V_37 ) ;
V_6 [ V_29 - 1 ] . V_7 |= ( 1 << ( V_9 -> V_17 - 1 ) ) ;
F_19 ( V_9 , V_20 ) ;
}
static void F_20 ( struct V_8 * V_9 )
{
int V_14 ;
struct V_19 * V_20 ;
#ifdef F_4
F_2 ( V_43 L_10 ) ;
#endif
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
if ( F_1 ( V_14 + 1 , V_9 -> V_17 ) == 1 ) {
F_16 ( V_9 , V_14 + 1 ,
& V_6 [ V_14 ] . V_30 ) ;
if ( V_6 [ V_14 ] . V_16 [ V_9 -> V_17 - 1 ] ) {
V_20 = F_21 ( V_6 [ V_14 ] . V_16 [ V_9 -> V_17 - 1 ] , V_42 ) ;
F_12 ( V_9 , V_20 ) ;
}
}
}
}
static void
F_22 ( struct V_8 * V_9 , T_3 V_29 ,
T_4 * V_30 )
{
int V_44 = 0 , V_45 = 0 , V_46 = 0 ;
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
T_2 * V_15 = V_10 -> V_15 ;
int V_47 = F_1 ( V_29 , V_9 -> V_17 ) ;
if ( V_47 < 0 ) {
return;
}
if ( V_47 == 1 ) {
F_2 ( V_48 L_11 , V_29 ) ;
return;
}
V_45 = V_30 -> V_39 > V_49 ? V_49 : V_30 -> V_39 ;
V_30 -> V_39 = V_45 ;
V_46 = V_30 -> V_40 < 1024 ? 1024 : V_30 -> V_40 ;
V_30 -> V_40 = V_46 ;
V_44 = V_30 -> V_38 ;
if ( V_44 < 0 ) {
V_44 = V_15 -> V_50 * - V_44 ;
}
if ( V_44 == 0 ) {
V_44 = V_15 -> V_50 ;
}
V_30 -> V_38 = V_44 ;
memcpy ( & V_6 [ V_29 - 1 ] . V_30 ,
V_30 , sizeof( T_4 ) ) ;
}
static void F_23 ( struct V_8 * V_9 , T_3 V_29 )
{
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
T_2 * V_15 = V_10 -> V_15 ;
struct V_19 * V_20 ;
T_3 V_32 ;
T_5 V_33 = 0xa1 , V_34 = 0x80 ;
T_3 V_35 = 0x0000 ;
F_24 ( & V_10 -> V_13 , V_29 ) ;
#ifdef F_4
F_2 ( V_12 L_12 ) ;
#endif
V_32 = V_41 ;
if ( ! ( V_20 = F_17 ( V_32 , V_42 ) ) ) {
F_2 ( V_5 L_9 ,
V_15 -> V_26 ) ;
return;
}
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_32 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_29 , sizeof( T_3 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_5 ) ) , & V_33 , sizeof( V_33 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_5 ) ) , & V_34 , sizeof( V_34 ) ) ;
memcpy ( F_18 ( V_20 , sizeof( T_3 ) ) , & V_35 , sizeof( T_3 ) ) ;
F_19 ( V_9 , V_20 ) ;
V_6 [ V_29 - 1 ] . V_7 &= ~ ( 1 << ( V_9 -> V_17 - 1 ) ) ;
}
static void
F_25 ( struct V_8 * V_9 , T_3 V_29 )
{
int V_47 ;
V_47 = F_1 ( V_29 , V_9 -> V_17 ) ;
if ( V_47 < 0 ) {
F_2 ( V_5 L_13 , V_29 , V_9 -> V_17 ) ;
return;
}
if ( V_6 [ V_29 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] ) {
F_9 ( V_6 [ V_29 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] ) ;
V_6 [ V_29 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] = NULL ;
}
if ( V_47 == 1 )
{
F_23 ( V_9 , V_29 ) ;
}
}
int F_26 ( T_2 * V_15 )
{
T_1 * V_10 = V_15 -> V_18 ;
struct V_8 * V_9 ;
#ifdef F_4
F_2 ( V_12 L_14 ) ;
#endif
if ( V_10 ) {
V_9 = & V_10 -> V_51 ;
F_7 ( V_9 ) ;
}
return 0 ;
}
int F_27 ( T_2 * V_15 )
{
T_1 * V_10 = V_15 -> V_18 ;
struct V_8 * V_9 ;
#ifdef F_4
F_2 ( V_12 L_15 ) ;
#endif
if ( V_10 ) {
V_9 = & V_10 -> V_51 ;
F_6 ( V_9 ) ;
}
return 0 ;
}
static T_6 F_19 ( struct V_8 * V_9 , struct V_19 * V_20 )
{
T_3 V_52 ;
int V_53 , V_54 ;
T_5 V_55 [ 64 ] ;
T_1 * V_10 = V_9 -> V_11 ;
T_6 V_56 = V_57 ;
V_52 = F_28 ( V_20 -> V_58 ) ;
switch ( F_1 ( V_52 , V_9 -> V_17 ) )
{
case 0 :
F_16 ( V_9 ,
V_52 ,
& ( V_6 [ V_52 - 1 ] . V_30 ) ) ;
break;
case 1 :
break;
default:
F_2 ( V_5 L_16 ) ;
V_56 = V_59 ;
goto V_60;
}
switch ( F_29 ( V_20 -> V_58 ) ) {
case V_61 :
F_30 ( & V_10 -> V_13 , V_52 ,
F_31 ( V_20 -> V_58 ) ) ;
break;
case V_62 :
V_53 = F_32 ( V_20 -> V_58 ) ;
if ( V_53 > 22 ) {
V_54 = V_53 - 22 ;
F_33 ( V_20 , V_55 , 22 ) ;
F_34 ( V_20 , V_54 ,
V_55 , 22 ) ;
F_35 ( V_20 , V_54 ) ;
F_36 ( V_20 -> V_58 , 22 ) ;
V_56 = F_37 ( & V_10 -> V_13 ,
F_28 ( V_20 -> V_58 ) ,
F_31 ( V_20 -> V_58 ) ,
F_38 ( V_20 -> V_58 ) ) ;
}
break;
case V_63 :
if ( V_6 [ V_52 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] )
{
F_9 ( V_6 [ V_52 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] ) ;
V_6 [ V_52 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] = NULL ;
}
if ( ! ( V_6 [ V_52 - 1 ] . V_16 [ V_9 -> V_17 - 1 ] = F_21 ( V_20 , V_42 ) ) )
{
F_2 ( V_5 L_17 ) ;
}
break;
default:
break;
}
V_60:
if ( V_56 == V_57 )
F_12 ( V_9 , V_20 ) ;
else
F_39 ( V_20 ) ;
return V_56 ;
}
static int F_40 ( struct V_64 * V_65 , void * V_66 )
{
struct V_8 * V_9 = V_65 -> V_67 ;
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
T_2 * V_15 = V_10 -> V_15 ;
char * V_68 ;
F_41 ( V_65 , L_18 , L_19 , V_10 -> V_69 ) ;
F_41 ( V_65 , L_20 , L_21 , V_15 -> V_70 ) ;
F_41 ( V_65 , L_22 , L_23 , V_15 -> V_71 ) ;
switch ( V_15 -> V_72 ) {
case V_73 : V_68 = L_24 ; break;
case V_74 : V_68 = L_25 ; break;
case V_75 : V_68 = L_26 ; break;
case V_76 : V_68 = L_27 ; break;
case V_77 : V_68 = L_28 ; break;
default: V_68 = L_29 ; break;
}
F_41 ( V_65 , L_18 , L_30 , V_68 ) ;
if ( ( V_68 = V_10 -> V_78 [ V_79 ] ) != NULL )
F_41 ( V_65 , L_18 , L_31 , V_68 ) ;
if ( ( V_68 = V_10 -> V_78 [ V_80 ] ) != NULL )
F_41 ( V_65 , L_18 , L_32 , V_68 ) ;
if ( ( V_68 = V_10 -> V_78 [ V_81 ] ) != NULL )
F_41 ( V_65 , L_18 , L_33 , V_68 ) ;
F_41 ( V_65 , L_18 , L_34 , V_10 -> V_69 ) ;
return 0 ;
}
static int F_42 ( struct V_82 * V_82 , struct V_83 * V_83 )
{
return F_43 ( V_83 , F_40 , F_44 ( V_82 ) -> V_58 ) ;
}
static int F_45 ( struct V_8 * V_9 , T_7 * V_58 )
{
#ifdef F_4
F_2 ( V_12 L_35 ) ;
#endif
return 0 ;
}
static char * F_46 ( struct V_8 * V_9 )
{
T_1 * V_10 = ( T_1 * ) ( V_9 -> V_11 ) ;
#ifdef F_4
F_2 ( V_12 L_36 ) ;
#endif
if ( ! V_10 )
return L_37 ;
sprintf ( V_10 -> V_84 , L_38 ,
V_10 -> V_69 [ 0 ] ? V_10 -> V_69 : L_39 ,
V_10 -> V_78 [ V_79 ] ? V_10 -> V_78 [ V_79 ] : L_39 ,
V_10 -> V_15 ? V_10 -> V_15 -> V_70 : 0x0 ,
V_10 -> V_15 ? V_10 -> V_15 -> V_71 : 0 ,
V_85
) ;
return V_10 -> V_84 ;
}
void
F_47 ( T_2 * V_15 , unsigned char * V_86 , unsigned short V_32 )
{
struct V_19 * V_20 ;
T_1 * V_10 = V_15 -> V_18 ;
struct V_8 * V_9 ;
T_3 V_87 ;
T_3 V_88 , V_89 ;
T_3 V_90 , V_91 ;
T_8 V_92 [ 2 ] = { 0 , 0 } ;
#ifdef F_4
F_2 ( V_12 L_40 ) ;
#endif
if ( ! V_10 ) {
return;
}
V_9 = & V_10 -> V_51 ;
if ( V_32 < V_41 ) {
F_2 ( V_5 L_41 ,
V_15 -> V_26 , V_32 ) ;
return;
}
V_88 = F_32 ( V_86 ) ;
V_87 = F_28 ( V_86 ) ;
V_91 = F_29 ( V_86 ) ;
if ( ( V_91 == V_93 ) && ( V_88 < 30 ) ) {
V_90 = V_32 + ( 30 - V_88 ) ;
if ( ! ( V_20 = F_17 ( V_90 , V_42 ) ) ) {
F_2 ( V_5 L_42 ,
V_15 -> V_26 ) ;
return;
}
memcpy ( F_18 ( V_20 , V_88 ) , V_86 , V_88 ) ;
memcpy ( F_18 ( V_20 , 2 * sizeof( T_8 ) ) , V_92 , 2 * sizeof( T_8 ) ) ;
memcpy ( F_18 ( V_20 , V_32 - V_88 ) , V_86 + V_88 ,
V_32 - V_88 ) ;
F_36 ( V_20 -> V_58 , 30 ) ;
} else {
if ( ! ( V_20 = F_17 ( V_32 , V_42 ) ) ) {
F_2 ( V_5 L_42 ,
V_15 -> V_26 ) ;
return;
}
memcpy ( F_18 ( V_20 , V_32 ) , V_86 , V_32 ) ;
}
switch ( F_29 ( V_20 -> V_58 ) )
{
case V_94 :
V_89 = F_48 ( V_20 -> V_58 , 12 ) ;
switch ( V_89 )
{
case 0 :
F_49 ( & V_10 -> V_13 , V_87 , F_31 ( V_20 -> V_58 ) ,
V_6 [ V_87 - 1 ] . V_30 . V_39 ) ;
break;
case 0x0001 :
F_2 ( V_5 L_43
L_44 , V_15 -> V_26 ) ;
break;
case 0x2001 :
F_2 ( V_5 L_45
L_46 , V_15 -> V_26 ) ;
break;
case 0x2002 :
F_2 ( V_5 L_47 , V_15 -> V_26 ) ;
break;
case 0x2004 :
F_2 ( V_5 L_48 , V_15 -> V_26 ) ;
break;
case 0x3008 :
F_2 ( V_5 L_49 ,
V_15 -> V_26 ) ;
break;
default:
F_2 ( V_5 L_50 ,
V_15 -> V_26 , V_89 ) ;
break;
}
break;
case V_95 :
F_49 ( & V_10 -> V_13 , V_87 ,
F_31 ( V_20 -> V_58 ) ,
V_6 [ V_87 - 1 ] . V_30 . V_39 ) ;
break;
case V_96 :
F_50 ( & V_10 -> V_13 , V_87 ,
F_31 ( V_20 -> V_58 ) ,
F_38 ( V_20 -> V_58 ) ) ;
break;
default:
break;
}
F_51 ( V_9 , V_87 , V_20 ) ;
}
void F_52 ( T_2 * V_15 )
{
T_1 * V_10 = V_15 -> V_18 ;
#ifdef F_4
F_2 ( V_12 L_51 ) ;
#endif
if ( ! V_10 ) {
return;
}
F_13 ( & V_10 -> V_21 ) ;
F_9 ( V_10 -> V_22 [ V_10 -> V_97 ] ) ;
V_10 -> V_22 [ V_10 -> V_97 ++ ] = NULL ;
if ( V_10 -> V_97 >= V_24 )
V_10 -> V_97 = 0 ;
if ( V_10 -> V_25 -- == V_24 )
F_53 ( & V_10 -> V_51 ) ;
F_14 ( & V_10 -> V_21 ) ;
}
struct V_19 *
F_54 ( T_2 * V_15 )
{
T_1 * V_10 = V_15 -> V_18 ;
if ( ! V_10 ) {
return (struct V_19 * ) NULL ;
}
if ( ! V_10 -> V_25 )
return (struct V_19 * ) NULL ;
return ( V_10 -> V_22 [ V_10 -> V_97 ] ) ;
}
int F_55 ( void )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
memset ( & ( V_6 [ V_14 ] ) , 0 , sizeof( V_98 ) ) ;
}
return ( 0 ) ;
}
void
F_56 ( void )
{
}
static void F_57 ( T_2 * V_15 )
{
T_1 * V_10 = NULL ;
struct V_8 * V_9 = NULL ;
V_10 = V_15 -> V_18 ;
if ( ! V_10 ) return;
V_9 = & V_10 -> V_51 ;
strcpy ( V_9 -> V_99 , L_52 ) ;
V_9 -> V_78 . V_100 = 2 ;
V_9 -> V_78 . V_101 = 0 ;
V_9 -> V_78 . V_102 = 3 ;
V_9 -> V_78 . V_103 = 2 ;
V_9 -> V_104 . V_105 = V_15 -> V_26 ;
V_9 -> V_104 . V_106 = V_15 -> V_50 ;
V_9 -> V_104 . V_107 = V_108 |
V_109 ;
V_9 -> V_104 . V_110 = V_111 |
( V_15 -> V_112 ? V_113 : 0 ) |
V_114 ;
V_9 -> V_104 . V_115 = V_116 |
( V_15 -> V_112 ? V_117 : 0 ) |
V_118 ;
V_9 -> V_104 . V_119 = V_120 |
V_121 |
( V_15 -> V_112 ? V_122 : 0 ) |
( V_15 -> V_112 ? V_123 : 0 ) |
V_124 ;
}
int
F_58 ( T_2 * V_15 )
{
T_1 * V_10 = NULL ;
struct V_8 * V_9 = NULL ;
int V_56 ;
#ifdef F_4
F_2 ( V_12 L_53 ) ;
#endif
if ( ( V_125 & ( 1 << V_15 -> V_26 ) ) == 0 ) {
return 1 ;
}
if ( ! V_15 -> V_18 ) {
V_10 = F_59 ( sizeof( T_1 ) , V_42 ) ;
if ( ! V_10 ) {
F_2 ( V_43 L_54 ) ;
return - V_126 ;
}
V_15 -> V_18 = V_10 ;
V_10 -> V_15 = V_15 ;
F_60 ( & V_10 -> V_21 ) ;
F_61 ( & V_10 -> V_13 ) ;
switch ( V_15 -> V_72 ) {
case V_73 : strcpy ( V_10 -> V_69 , L_24 ) ; break;
case V_74 : strcpy ( V_10 -> V_69 , L_25 ) ; break;
case V_75 : strcpy ( V_10 -> V_69 , L_26 ) ; break;
case V_76 : strcpy ( V_10 -> V_69 , L_27 ) ; break;
case V_77 : strcpy ( V_10 -> V_69 , L_28 ) ; break;
default: strcpy ( V_10 -> V_69 , L_55 ) ; break;
}
V_9 = & V_10 -> V_51 ;
V_9 -> V_127 = L_56 ;
V_9 -> V_11 = V_10 ;
V_9 -> V_128 = F_22 ;
V_9 -> V_129 = F_25 ;
V_9 -> V_130 = F_19 ;
V_9 -> V_131 = F_45 ;
V_9 -> V_132 = F_3 ;
V_9 -> V_133 = F_46 ;
V_9 -> V_134 = & V_135 ;
strcpy ( V_9 -> V_136 , V_10 -> V_69 ) ;
V_9 -> V_137 = V_138 ;
V_56 = F_62 ( V_9 ) ;
if ( V_56 ) {
F_2 ( V_5 L_57 ) ;
return - V_139 ;
}
F_57 ( V_15 ) ;
F_63 ( V_9 ) ;
} else {
V_9 = & V_15 -> V_18 -> V_51 ;
F_57 ( V_15 ) ;
F_63 ( V_9 ) ;
F_20 ( V_9 ) ;
}
return 0 ;
}
