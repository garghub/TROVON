static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 & V_4 ) {
F_4 ( & V_2 -> V_5 -> V_6 , L_1 ) ;
return - V_7 ;
}
V_3 &= V_8 ;
if ( V_3 ) {
F_5 ( & V_2 -> V_5 -> V_6 , L_2 ,
V_3 ) ;
F_6 ( V_3 , F_3 ( V_2 ) ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) & V_8 ;
if ( V_3 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_3 ,
V_3 ) ;
return - V_7 ;
}
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
int V_9 = 0 ;
if ( F_8 ( V_3 < 0 ) ) {
F_4 ( & V_2 -> V_5 -> V_6 , L_4 ) ;
F_5 ( & V_2 -> V_5 -> V_6 , L_5 ) ;
F_6 ( F_2 ( F_9 ( V_2 ) ) | V_10 ,
F_9 ( V_2 ) ) ;
F_10 ( 1000 , 2000 ) ;
F_6 ( F_2 ( F_9 ( V_2 ) ) & ( ~ V_10 ) ,
F_9 ( V_2 ) ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( ( V_3 & V_4 ) ||
! ( V_3 & V_11 ) )
F_4 ( & V_2 -> V_5 -> V_6 ,
L_6 ) ;
F_6 ( V_8 , F_3 ( V_2 ) ) ;
return - V_12 ;
}
if ( V_3 & V_11 ) {
V_9 = - V_13 ;
F_4 ( & V_2 -> V_5 -> V_6 , L_7 ) ;
}
if ( V_3 & V_14 ) {
V_9 = - V_15 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_8 ) ;
}
if ( V_3 & V_16 ) {
V_9 = - V_17 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_9 ) ;
}
F_6 ( V_3 , F_3 ( V_2 ) ) ;
return V_9 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
int V_3 ;
do {
F_10 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ( ( V_3 & V_4 ) ||
! ( V_3 & ( V_19 | V_20 ) ) ) &&
( V_18 ++ < V_21 ) );
if ( V_18 > V_21 ) {
F_5 ( & V_2 -> V_5 -> V_6 , L_10 ) ;
return - V_12 ;
}
return V_3 & ( V_19 | V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
int V_3 ;
do {
F_10 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ! ( V_3 & ( V_19 | V_22 ) ) &&
( V_18 ++ < V_21 ) );
if ( V_18 > V_21 ) {
F_5 ( & V_2 -> V_5 -> V_6 , L_11 ) ;
return - V_12 ;
}
return V_3 & V_19 ;
}
static int F_13 ( struct V_1 * V_2 , int V_23 )
{
int V_3 ;
int V_9 ;
const struct V_24 * V_25 = & V_2 -> V_26 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_2 -> V_27 & V_28 ) {
F_6 ( V_23 | V_29 | V_30 ,
F_9 ( V_2 ) ) ;
V_9 = F_14 ( V_2 -> V_31 ,
( V_3 = V_2 -> V_3 ) ,
V_25 -> V_18 ) ;
if ( ! V_9 ) {
V_3 = - V_12 ;
F_15 ( & V_2 -> V_5 -> V_6 ,
L_12 ) ;
}
V_2 -> V_3 = 0 ;
return F_7 ( V_2 , V_3 ) ;
}
F_6 ( V_23 | V_30 , F_9 ( V_2 ) ) ;
V_3 = F_11 ( V_2 ) ;
return F_7 ( V_2 , V_3 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_32 * V_33 ,
char V_34 , int V_35 )
{
int V_36 , V_37 ;
int V_3 ;
F_2 ( F_9 ( V_2 ) ) ;
if ( V_34 == V_38 ) {
V_37 = V_33 -> V_39 [ 0 ] ;
F_6 ( V_37 , F_17 ( V_2 ) ) ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_6 ( V_33 -> V_39 [ V_36 + 1 ] , F_18 ( V_2 ) ) ;
}
V_3 = F_13 ( V_2 , V_40 |
( V_35 ? V_41 : 0 ) ) ;
if ( V_3 )
return V_3 ;
if ( V_34 == V_42 ) {
V_37 = F_2 ( F_17 ( V_2 ) ) ;
if ( V_37 < 1 || V_37 > V_43 )
return - V_44 ;
V_33 -> V_39 [ 0 ] = V_37 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_33 -> V_39 [ V_36 + 1 ] = F_2 ( F_18 ( V_2 ) ) ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_45 ) {
if ( ( ( V_2 -> V_46 & 0x1c ) == V_40 ) &&
( V_2 -> V_47 == 0 ) ) {
V_2 -> V_37 = F_2 ( F_17 ( V_2 ) ) ;
if ( V_2 -> V_37 < 1 || V_2 -> V_37 > V_43 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_13 ,
V_2 -> V_37 ) ;
V_2 -> V_37 = V_43 ;
} else {
F_5 ( & V_2 -> V_5 -> V_6 ,
L_14 ,
V_2 -> V_37 ) ;
}
V_2 -> V_33 [ - 1 ] = V_2 -> V_37 ;
}
if ( V_2 -> V_47 < V_2 -> V_37 )
V_2 -> V_33 [ V_2 -> V_47 ++ ] = F_20 ( F_18 ( V_2 ) ) ;
else
F_5 ( & V_2 -> V_5 -> V_6 ,
L_15 ) ;
if ( V_2 -> V_47 == V_2 -> V_37 - 1 )
F_6 ( V_2 -> V_46 | V_48 ,
F_9 ( V_2 ) ) ;
} else if ( V_2 -> V_47 < V_2 -> V_37 - 1 ) {
F_6 ( V_2 -> V_33 [ ++ V_2 -> V_47 ] , F_18 ( V_2 ) ) ;
}
F_6 ( V_22 , F_3 ( V_2 ) ) ;
}
static T_1 F_21 ( int V_49 , void * V_50 )
{
struct V_1 * V_2 = V_50 ;
T_2 V_51 ;
T_3 V_3 ;
F_22 ( V_2 -> V_5 , V_52 , & V_51 ) ;
if ( ! ( V_51 & V_53 ) )
return V_54 ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 & V_22 )
F_19 ( V_2 ) ;
V_3 &= V_20 | V_19 ;
if ( V_3 ) {
F_6 ( V_3 , F_3 ( V_2 ) ) ;
V_2 -> V_3 |= V_3 ;
F_23 ( & V_2 -> V_31 ) ;
}
return V_55 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_32 * V_33 ,
char V_34 , int V_56 ,
int V_35 )
{
int V_36 , V_37 ;
int V_57 ;
int V_3 ;
int V_9 ;
const struct V_24 * V_25 = & V_2 -> V_26 ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_37 = V_33 -> V_39 [ 0 ] ;
if ( V_34 == V_38 ) {
F_6 ( V_37 , F_17 ( V_2 ) ) ;
F_6 ( V_33 -> V_39 [ 1 ] , F_18 ( V_2 ) ) ;
}
if ( V_56 == V_58 &&
V_34 == V_42 )
V_57 = V_59 ;
else
V_57 = V_40 ;
if ( V_2 -> V_27 & V_28 ) {
V_2 -> V_45 = ( V_34 == V_42 ) ;
if ( V_37 == 1 && V_2 -> V_45 )
V_57 |= V_48 ;
V_2 -> V_46 = V_57 | V_29 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_47 = 0 ;
V_2 -> V_33 = & V_33 -> V_39 [ 1 ] ;
F_6 ( V_2 -> V_46 | V_30 , F_9 ( V_2 ) ) ;
V_9 = F_14 ( V_2 -> V_31 ,
( V_3 = V_2 -> V_3 ) ,
V_25 -> V_18 ) ;
if ( ! V_9 ) {
V_3 = - V_12 ;
F_15 ( & V_2 -> V_5 -> V_6 ,
L_12 ) ;
}
V_2 -> V_3 = 0 ;
return F_7 ( V_2 , V_3 ) ;
}
for ( V_36 = 1 ; V_36 <= V_37 ; V_36 ++ ) {
if ( V_36 == V_37 && V_34 == V_42 )
V_57 |= V_48 ;
F_6 ( V_57 , F_9 ( V_2 ) ) ;
if ( V_36 == 1 )
F_6 ( F_20 ( F_9 ( V_2 ) ) | V_30 ,
F_9 ( V_2 ) ) ;
V_3 = F_12 ( V_2 ) ;
if ( V_3 )
goto exit;
if ( V_36 == 1 && V_34 == V_42
&& V_56 != V_58 ) {
V_37 = F_2 ( F_17 ( V_2 ) ) ;
if ( V_37 < 1 || V_37 > V_43 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_13 ,
V_37 ) ;
while ( F_2 ( F_3 ( V_2 ) ) &
V_4 )
F_6 ( V_22 ,
F_3 ( V_2 ) ) ;
F_6 ( V_20 , F_3 ( V_2 ) ) ;
return - V_44 ;
}
V_33 -> V_39 [ 0 ] = V_37 ;
}
if ( V_34 == V_42 )
V_33 -> V_39 [ V_36 ] = F_2 ( F_18 ( V_2 ) ) ;
if ( V_34 == V_38 && V_36 + 1 <= V_37 )
F_6 ( V_33 -> V_39 [ V_36 + 1 ] , F_18 ( V_2 ) ) ;
F_6 ( V_22 , F_3 ( V_2 ) ) ;
}
V_3 = F_11 ( V_2 ) ;
exit:
return F_7 ( V_2 , V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( F_26 ( V_2 ) ) | V_60 , F_26 ( V_2 ) ) ;
if ( ( F_2 ( F_26 ( V_2 ) ) & V_60 ) == 0 )
return - V_13 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_32 * V_33 , char V_34 ,
int V_56 , int V_35 )
{
int V_9 = 0 ;
unsigned char V_61 ;
if ( V_56 == V_58 ) {
if ( V_34 == V_38 ) {
F_28 ( V_2 -> V_5 , V_62 , & V_61 ) ;
F_29 ( V_2 -> V_5 , V_62 ,
V_61 | V_63 ) ;
} else if ( ! ( V_2 -> V_27 & V_64 ) ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_16 ) ;
return - V_65 ;
}
}
if ( V_34 == V_38
|| V_56 == V_58 ) {
if ( V_33 -> V_39 [ 0 ] < 1 )
V_33 -> V_39 [ 0 ] = 1 ;
if ( V_33 -> V_39 [ 0 ] > V_43 )
V_33 -> V_39 [ 0 ] = V_43 ;
} else {
V_33 -> V_39 [ 0 ] = 32 ;
}
if ( ( V_2 -> V_27 & V_66 )
&& V_56 != V_58
&& F_25 ( V_2 ) == 0 )
V_9 = F_16 ( V_2 , V_33 ,
V_34 , V_35 ) ;
else
V_9 = F_24 ( V_2 , V_33 ,
V_34 ,
V_56 , V_35 ) ;
if ( V_56 == V_58
&& V_34 == V_38 ) {
F_29 ( V_2 -> V_5 , V_62 , V_61 ) ;
}
return V_9 ;
}
static T_4 F_30 ( struct V_24 * V_25 , T_2 V_67 ,
unsigned short V_68 , char V_34 , T_3 V_56 ,
int V_69 , union V_32 * V_33 )
{
int V_35 ;
int V_39 = 0 ;
int V_70 = 0 , V_23 = 0 ;
struct V_1 * V_2 = F_31 ( V_25 ) ;
F_32 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_72 ) {
F_33 ( & V_2 -> V_71 ) ;
return - V_7 ;
}
F_34 ( & V_2 -> V_5 -> V_6 ) ;
V_35 = ( V_2 -> V_27 & V_73 ) && ( V_68 & V_74 )
&& V_69 != V_75
&& V_69 != V_58 ;
switch ( V_69 ) {
case V_75 :
F_6 ( ( ( V_67 & 0x7f ) << 1 ) | ( V_34 & 0x01 ) ,
F_35 ( V_2 ) ) ;
V_23 = V_76 ;
break;
case V_77 :
F_6 ( ( ( V_67 & 0x7f ) << 1 ) | ( V_34 & 0x01 ) ,
F_35 ( V_2 ) ) ;
if ( V_34 == V_38 )
F_6 ( V_56 , F_36 ( V_2 ) ) ;
V_23 = V_78 ;
break;
case V_79 :
F_6 ( ( ( V_67 & 0x7f ) << 1 ) | ( V_34 & 0x01 ) ,
F_35 ( V_2 ) ) ;
F_6 ( V_56 , F_36 ( V_2 ) ) ;
if ( V_34 == V_38 )
F_6 ( V_33 -> V_80 , F_17 ( V_2 ) ) ;
V_23 = V_81 ;
break;
case V_82 :
F_6 ( ( ( V_67 & 0x7f ) << 1 ) | ( V_34 & 0x01 ) ,
F_35 ( V_2 ) ) ;
F_6 ( V_56 , F_36 ( V_2 ) ) ;
if ( V_34 == V_38 ) {
F_6 ( V_33 -> V_83 & 0xff , F_17 ( V_2 ) ) ;
F_6 ( ( V_33 -> V_83 & 0xff00 ) >> 8 , F_37 ( V_2 ) ) ;
}
V_23 = V_84 ;
break;
case V_85 :
F_6 ( ( ( V_67 & 0x7f ) << 1 ) | ( V_34 & 0x01 ) ,
F_35 ( V_2 ) ) ;
F_6 ( V_56 , F_36 ( V_2 ) ) ;
V_39 = 1 ;
break;
case V_58 :
F_6 ( ( V_67 & 0x7f ) << 1 , F_35 ( V_2 ) ) ;
if ( V_34 == V_42 ) {
F_6 ( V_56 , F_37 ( V_2 ) ) ;
} else
F_6 ( V_56 , F_36 ( V_2 ) ) ;
V_39 = 1 ;
break;
default:
F_4 ( & V_2 -> V_5 -> V_6 , L_17 ,
V_69 ) ;
V_70 = - V_65 ;
goto V_86;
}
if ( V_35 )
F_6 ( F_2 ( F_26 ( V_2 ) ) | V_87 , F_26 ( V_2 ) ) ;
else
F_6 ( F_2 ( F_26 ( V_2 ) ) & ( ~ V_87 ) ,
F_26 ( V_2 ) ) ;
if ( V_39 )
V_70 = F_27 ( V_2 , V_33 , V_34 , V_69 ,
V_35 ) ;
else
V_70 = F_13 ( V_2 , V_23 ) ;
if ( V_35 || V_39 )
F_6 ( F_2 ( F_26 ( V_2 ) ) &
~ ( V_87 | V_60 ) , F_26 ( V_2 ) ) ;
if ( V_39 )
goto V_86;
if ( V_70 )
goto V_86;
if ( ( V_34 == V_38 ) || ( V_23 == V_76 ) )
goto V_86;
switch ( V_23 & 0x7f ) {
case V_78 :
case V_81 :
V_33 -> V_80 = F_2 ( F_17 ( V_2 ) ) ;
break;
case V_84 :
V_33 -> V_83 = F_2 ( F_17 ( V_2 ) ) +
( F_2 ( F_37 ( V_2 ) ) << 8 ) ;
break;
}
V_86:
F_38 ( & V_2 -> V_5 -> V_6 ) ;
F_39 ( & V_2 -> V_5 -> V_6 ) ;
F_33 ( & V_2 -> V_71 ) ;
return V_70 ;
}
static T_5 F_40 ( struct V_24 * V_26 )
{
struct V_1 * V_2 = F_31 ( V_26 ) ;
return V_88 | V_89 |
V_90 | V_91 |
V_92 | V_93 |
( ( V_2 -> V_27 & V_73 ) ? V_94 : 0 ) |
( ( V_2 -> V_27 & V_64 ) ?
V_95 : 0 ) ;
}
static T_6 const void T_7 * F_41 ( const void T_7 * V_96 )
{
T_8 V_97 ;
const unsigned char V_98 [] = L_18 ;
for ( V_97 = 0 ; V_97 < 0x10000 ; V_97 += 0x10 ) {
if ( F_42 ( V_96 + V_97 , V_98 ,
sizeof( V_98 ) - 1 ) )
return V_96 + V_97 ;
}
return NULL ;
}
static void T_6 F_43 ( void )
{
void T_7 * V_96 ;
const void T_7 * V_99 ;
V_96 = F_44 ( 0xF0000 , 0x10000 ) ;
V_99 = F_41 ( V_96 ) ;
if ( V_99 ) {
V_100 = F_45 ( V_99 + 8 + 3 ) >> 1 ;
}
F_46 ( V_96 ) ;
}
static void F_47 ( T_3 type , const char * V_101 ,
struct V_24 * V_25 )
{
int V_36 ;
struct V_102 V_103 ;
for ( V_36 = 0 ; V_36 < F_48 ( V_104 ) ; V_36 ++ ) {
if ( ( type & ~ 0x80 ) != V_104 [ V_36 ] . type )
continue;
if ( strcasecmp ( V_101 , V_104 [ V_36 ] . V_101 ) )
continue;
memset ( & V_103 , 0 , sizeof( struct V_102 ) ) ;
V_103 . V_67 = V_104 [ V_36 ] . V_105 ;
F_49 ( V_103 . type , V_104 [ V_36 ] . V_106 , V_107 ) ;
F_50 ( V_25 , & V_103 ) ;
break;
}
}
static void F_51 ( const struct V_108 * V_109 , void * V_25 )
{
int V_36 , V_47 ;
if ( V_109 -> type != 10 )
return;
V_47 = ( V_109 -> V_110 - sizeof( struct V_108 ) ) / 2 ;
for ( V_36 = 0 ; V_36 < V_47 ; V_36 ++ ) {
const T_3 * V_111 = ( char * ) ( V_109 + 1 ) + ( V_36 * 2 ) ;
const char * V_101 = ( ( char * ) V_109 ) + V_109 -> V_110 ;
T_3 type = V_111 [ 0 ] ;
T_3 V_112 = V_111 [ 1 ] ;
if ( ! V_112 )
continue;
V_112 -- ;
while ( V_112 > 0 && V_101 [ 0 ] ) {
V_101 += strlen ( V_101 ) + 1 ;
V_112 -- ;
}
if ( V_101 [ 0 ] == 0 )
continue;
F_47 ( type , V_101 , V_25 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 & V_113 )
return;
if ( V_100 ) {
struct V_102 V_103 ;
memset ( & V_103 , 0 , sizeof( struct V_102 ) ) ;
V_103 . V_67 = V_100 ;
F_49 ( V_103 . type , L_19 , V_107 ) ;
F_50 ( & V_2 -> V_26 , & V_103 ) ;
}
if ( F_53 ( L_20 ) )
F_54 ( F_51 , & V_2 -> V_26 ) ;
}
static void T_6 F_43 ( void ) {}
static void F_52 ( struct V_1 * V_2 ) {}
static int F_55 ( struct V_1 * V_2 )
{
struct V_114 * V_6 = & V_2 -> V_26 . V_6 ;
const struct V_115 * V_116 ;
struct V_117 V_118 ;
int V_119 ;
if ( ! V_2 -> V_120 )
return 0 ;
V_116 = V_2 -> V_120 ;
memset ( & V_118 , 0 , sizeof( struct V_117 ) ) ;
V_118 . V_121 = V_2 -> V_26 . V_122 ;
V_118 . V_123 = V_116 -> V_123 ;
V_118 . V_124 = V_116 -> V_124 ;
V_118 . V_125 = V_116 -> V_125 ;
V_118 . V_126 = V_116 -> V_126 ;
V_118 . V_127 = V_116 -> V_127 ;
V_118 . V_128 = V_116 -> V_128 ;
V_118 . V_129 = V_130 ;
V_2 -> V_131 = F_56 ( V_6 , L_21 ,
V_132 , & V_118 ,
sizeof( struct V_117 ) ) ;
if ( F_57 ( V_2 -> V_131 ) ) {
V_119 = F_58 ( V_2 -> V_131 ) ;
V_2 -> V_131 = NULL ;
F_4 ( V_6 , L_22 ) ;
return V_119 ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_131 )
F_60 ( V_2 -> V_131 ) ;
}
static unsigned int F_61 ( struct V_1 * V_2 )
{
const struct V_133 * V_134 ;
const struct V_115 * V_116 ;
unsigned int V_135 = V_136 | V_137 ;
int V_36 ;
V_134 = F_62 ( V_138 ) ;
if ( V_134 ) {
V_116 = V_134 -> V_139 ;
for ( V_36 = 0 ; V_36 < V_116 -> V_124 ; V_36 ++ )
V_135 &= ~ V_116 -> V_125 [ V_36 ] ;
V_2 -> V_120 = V_116 ;
}
return V_135 ;
}
static inline int F_55 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_59 ( struct V_1 * V_2 ) { }
static inline unsigned int F_61 ( struct V_1 * V_2 )
{
return V_136 | V_137 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_140 V_141 [ 3 ] , * V_142 ;
struct V_143 * V_144 ;
unsigned int V_145 ;
T_5 V_146 , V_147 ;
T_5 V_148 , V_149 ;
T_9 V_150 ;
if ( ! ( V_2 -> V_27 & V_151 ) )
return;
F_64 ( V_5 , V_152 , & V_146 ) ;
F_64 ( V_5 , V_153 , & V_147 ) ;
if ( ! ( V_147 & V_154 ) )
return;
memset ( V_141 , 0 , sizeof( V_141 ) ) ;
V_142 = & V_141 [ V_155 ] ;
V_142 -> V_156 = V_146 & ~ 1 ;
V_142 -> V_157 = V_142 -> V_156 + 32 - 1 ;
V_142 -> V_68 = V_158 ;
V_145 = F_65 ( F_66 ( V_5 -> V_145 ) , 2 ) ;
F_67 ( V_5 -> V_159 , V_145 , V_160 , & V_148 ) ;
V_142 = & V_141 [ V_161 ] ;
V_142 -> V_156 = ( V_148 & ~ 1 ) + V_162 ;
V_142 -> V_157 = V_142 -> V_156 + 3 ;
V_142 -> V_68 = V_158 ;
F_67 ( V_5 -> V_159 , V_145 , V_163 , & V_149 ) ;
V_149 |= V_164 ;
F_68 ( V_5 -> V_159 , V_145 , V_163 , V_149 ) ;
F_69 ( & V_165 ) ;
V_145 = F_65 ( F_66 ( V_5 -> V_145 ) , 1 ) ;
F_70 ( V_5 -> V_159 , V_145 , 0xe1 , 0x0 ) ;
F_67 ( V_5 -> V_159 , V_145 , V_166 , & V_148 ) ;
V_150 = V_148 & 0xfffffff0 ;
F_67 ( V_5 -> V_159 , V_145 , V_166 + 0x4 , & V_148 ) ;
V_150 |= ( T_9 ) V_148 << 32 ;
F_70 ( V_5 -> V_159 , V_145 , 0xe1 , 0x1 ) ;
F_71 ( & V_165 ) ;
V_142 = & V_141 [ V_167 ] ;
V_142 -> V_156 = ( V_168 ) V_150 + V_169 ;
V_142 -> V_157 = V_142 -> V_156 + 3 ;
V_142 -> V_68 = V_170 ;
V_144 = F_72 ( & V_5 -> V_6 , L_23 , - 1 ,
V_141 , 3 , & V_171 ,
sizeof( V_171 ) ) ;
if ( F_57 ( V_144 ) ) {
F_15 ( & V_5 -> V_6 , L_24 ) ;
return;
}
V_2 -> V_172 = V_144 ;
}
static T_10
F_73 ( T_5 V_173 , T_11 V_174 , T_5 V_175 ,
T_9 * V_176 , void * V_177 , void * V_178 )
{
struct V_1 * V_2 = V_177 ;
struct V_5 * V_144 = V_2 -> V_5 ;
T_10 V_3 ;
F_32 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_72 ) {
V_2 -> V_72 = true ;
F_15 ( & V_144 -> V_6 , L_25 ) ;
F_15 ( & V_144 -> V_6 , L_26 ) ;
F_34 ( & V_144 -> V_6 ) ;
}
if ( ( V_173 & V_179 ) == V_180 )
V_3 = F_74 ( V_174 , ( T_5 * ) V_176 , V_175 ) ;
else
V_3 = F_75 ( V_174 , ( T_5 ) * V_176 , V_175 ) ;
F_33 ( & V_2 -> V_71 ) ;
return V_3 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_181 * V_182 ;
T_10 V_3 ;
V_182 = F_77 ( & V_2 -> V_5 -> V_6 ) ;
if ( V_182 ) {
V_3 = F_78 ( V_182 -> V_183 ,
V_184 , F_73 ,
NULL , V_2 ) ;
if ( F_79 ( V_3 ) )
return 0 ;
}
return F_80 ( & V_2 -> V_5 -> V_140 [ V_185 ] ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_181 * V_182 ;
V_182 = F_77 ( & V_2 -> V_5 -> V_6 ) ;
if ( ! V_182 )
return;
F_82 ( V_182 -> V_183 ,
V_184 , F_73 ) ;
F_32 ( & V_2 -> V_71 ) ;
if ( V_2 -> V_72 )
F_83 ( & V_2 -> V_5 -> V_6 ) ;
F_33 ( & V_2 -> V_71 ) ;
}
static inline int F_76 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_81 ( struct V_1 * V_2 ) { }
static int F_84 ( struct V_5 * V_6 , const struct V_186 * V_134 )
{
unsigned char V_187 ;
int V_119 , V_36 ;
struct V_1 * V_2 ;
V_2 = F_85 ( & V_6 -> V_6 , sizeof( * V_2 ) , V_188 ) ;
if ( ! V_2 )
return - V_189 ;
F_86 ( & V_2 -> V_26 , V_2 ) ;
V_2 -> V_26 . V_190 = V_191 ;
V_2 -> V_26 . V_135 = F_61 ( V_2 ) ;
V_2 -> V_26 . V_192 = & V_193 ;
V_2 -> V_26 . V_6 . V_121 = & V_6 -> V_6 ;
F_87 ( & V_2 -> V_26 . V_6 , F_77 ( & V_6 -> V_6 ) ) ;
V_2 -> V_26 . V_194 = 3 ;
F_88 ( & V_2 -> V_71 ) ;
V_2 -> V_5 = V_6 ;
switch ( V_6 -> V_114 ) {
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
V_2 -> V_27 |= V_64 ;
V_2 -> V_27 |= V_28 ;
V_2 -> V_27 |= V_73 ;
V_2 -> V_27 |= V_66 ;
V_2 -> V_27 |= V_151 ;
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_2 -> V_27 |= V_113 ;
default:
V_2 -> V_27 |= V_64 ;
V_2 -> V_27 |= V_28 ;
case V_206 :
V_2 -> V_27 |= V_73 ;
V_2 -> V_27 |= V_66 ;
case V_207 :
case V_208 :
case V_209 :
case V_210 :
break;
}
for ( V_36 = 0 ; V_36 < F_48 ( V_211 ) ; V_36 ++ ) {
if ( V_2 -> V_27 & V_212 & ( 1 << V_36 ) )
F_89 ( & V_6 -> V_6 , L_27 ,
V_211 [ V_36 ] ) ;
}
V_2 -> V_27 &= ~ V_212 ;
V_119 = F_90 ( V_6 ) ;
if ( V_119 ) {
F_4 ( & V_6 -> V_6 , L_28 ,
V_119 ) ;
return V_119 ;
}
F_91 ( V_6 ) ;
V_2 -> V_213 = F_92 ( V_6 , V_185 ) ;
if ( ! V_2 -> V_213 ) {
F_4 ( & V_6 -> V_6 ,
L_29 ) ;
return - V_214 ;
}
if ( F_76 ( V_2 ) )
return - V_214 ;
V_119 = F_93 ( V_6 , 1 << V_185 ,
F_94 ( & V_6 -> V_6 ) ) ;
if ( V_119 ) {
F_4 ( & V_6 -> V_6 ,
L_30 ,
V_2 -> V_213 ,
( unsigned long long ) F_95 ( V_6 , V_185 ) ) ;
F_81 ( V_2 ) ;
return V_119 ;
}
F_28 ( V_2 -> V_5 , V_62 , & V_187 ) ;
V_2 -> V_215 = V_187 ;
V_187 &= ~ V_63 ;
if ( ! ( V_187 & V_216 ) ) {
F_96 ( & V_6 -> V_6 , L_31 ) ;
V_187 |= V_216 ;
}
F_29 ( V_2 -> V_5 , V_62 , V_187 ) ;
if ( V_187 & V_217 ) {
F_5 ( & V_6 -> V_6 , L_32 ) ;
V_2 -> V_27 &= ~ V_28 ;
}
if ( V_2 -> V_27 & ( V_73 | V_66 ) )
F_6 ( F_2 ( F_26 ( V_2 ) ) &
~ ( V_87 | V_60 ) , F_26 ( V_2 ) ) ;
V_2 -> V_26 . V_18 = V_218 / 5 ;
if ( V_2 -> V_27 & V_28 ) {
T_2 V_219 , V_51 ;
F_22 ( V_2 -> V_5 , V_52 , & V_51 ) ;
if ( V_51 & V_53 )
F_15 ( & V_6 -> V_6 , L_33 ) ;
F_22 ( V_2 -> V_5 , V_220 , & V_219 ) ;
if ( V_219 & V_221 ) {
F_96 ( & V_6 -> V_6 , L_34 ) ;
V_2 -> V_27 &= ~ V_28 ;
}
}
if ( V_2 -> V_27 & V_28 ) {
F_97 ( & V_2 -> V_31 ) ;
V_119 = F_98 ( & V_6 -> V_6 , V_6 -> V_49 , F_21 ,
V_222 ,
F_94 ( & V_6 -> V_6 ) , V_2 ) ;
if ( V_119 ) {
F_4 ( & V_6 -> V_6 , L_35 ,
V_6 -> V_49 , V_119 ) ;
V_2 -> V_27 &= ~ V_28 ;
}
}
F_96 ( & V_6 -> V_6 , L_36 ,
V_2 -> V_27 & V_28 ? L_37 : L_38 ) ;
F_63 ( V_2 ) ;
snprintf ( V_2 -> V_26 . V_101 , sizeof( V_2 -> V_26 . V_101 ) ,
L_39 , V_2 -> V_213 ) ;
V_119 = F_99 ( & V_2 -> V_26 ) ;
if ( V_119 ) {
F_4 ( & V_6 -> V_6 , L_40 ) ;
F_81 ( V_2 ) ;
return V_119 ;
}
F_52 ( V_2 ) ;
F_55 ( V_2 ) ;
F_100 ( V_6 , V_2 ) ;
F_101 ( & V_6 -> V_6 , 1000 ) ;
F_102 ( & V_6 -> V_6 ) ;
F_39 ( & V_6 -> V_6 ) ;
F_103 ( & V_6 -> V_6 ) ;
return 0 ;
}
static void F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_105 ( V_6 ) ;
F_106 ( & V_6 -> V_6 ) ;
F_107 ( & V_6 -> V_6 ) ;
F_59 ( V_2 ) ;
F_108 ( & V_2 -> V_26 ) ;
F_81 ( V_2 ) ;
F_29 ( V_6 , V_62 , V_2 -> V_215 ) ;
F_60 ( V_2 -> V_172 ) ;
}
static int F_109 ( struct V_114 * V_6 )
{
struct V_5 * V_5 = F_110 ( V_6 ) ;
struct V_1 * V_2 = F_105 ( V_5 ) ;
F_29 ( V_5 , V_62 , V_2 -> V_215 ) ;
return 0 ;
}
static int F_111 ( struct V_114 * V_6 )
{
return 0 ;
}
static int T_6 F_112 ( void )
{
if ( F_53 ( L_20 ) )
F_43 () ;
return F_113 ( & V_223 ) ;
}
static void T_12 F_114 ( void )
{
F_115 ( & V_223 ) ;
}
