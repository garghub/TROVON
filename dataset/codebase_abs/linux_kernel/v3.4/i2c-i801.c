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
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_9 )
{
int V_10 = 0 ;
if ( V_9 ) {
F_4 ( & V_2 -> V_5 -> V_6 , L_4 ) ;
F_5 ( & V_2 -> V_5 -> V_6 , L_5 ) ;
F_6 ( F_2 ( F_8 ( V_2 ) ) | V_11 ,
F_8 ( V_2 ) ) ;
F_9 ( 1000 , 2000 ) ;
F_6 ( F_2 ( F_8 ( V_2 ) ) & ( ~ V_11 ) ,
F_8 ( V_2 ) ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( ( V_3 & V_4 ) ||
! ( V_3 & V_12 ) )
F_4 ( & V_2 -> V_5 -> V_6 ,
L_6 ) ;
F_6 ( V_8 , F_3 ( V_2 ) ) ;
return - V_13 ;
}
if ( V_3 & V_12 ) {
V_10 = - V_14 ;
F_4 ( & V_2 -> V_5 -> V_6 , L_7 ) ;
}
if ( V_3 & V_15 ) {
V_10 = - V_16 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_8 ) ;
}
if ( V_3 & V_17 ) {
V_10 = - V_18 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_9 ) ;
}
if ( V_10 ) {
F_6 ( V_3 & V_8 , F_3 ( V_2 ) ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) & V_8 ;
if ( V_3 ) {
F_10 ( & V_2 -> V_5 -> V_6 , L_10
L_11 ,
V_3 ) ;
}
}
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 , int V_19 )
{
int V_3 ;
int V_10 ;
int V_9 = 0 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
F_6 ( V_19 | V_20 , F_8 ( V_2 ) ) ;
do {
F_9 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ( V_3 & V_4 ) && ( V_9 ++ < V_21 ) );
V_10 = F_7 ( V_2 , V_3 , V_9 > V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
F_6 ( V_22 , F_3 ( V_2 ) ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
int V_3 ;
do {
F_9 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ( ! ( V_3 & V_22 ) )
&& ( V_9 ++ < V_21 ) );
if ( V_9 > V_21 )
F_5 ( & V_2 -> V_5 -> V_6 , L_12 ) ;
F_6 ( V_3 , F_3 ( V_2 ) ) ;
}
static int F_13 ( struct V_1 * V_2 ,
union V_23 * V_24 ,
char V_25 , int V_26 )
{
int V_27 , V_28 ;
int V_3 ;
F_2 ( F_8 ( V_2 ) ) ;
if ( V_25 == V_29 ) {
V_28 = V_24 -> V_30 [ 0 ] ;
F_6 ( V_28 , F_14 ( V_2 ) ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
F_6 ( V_24 -> V_30 [ V_27 + 1 ] , F_15 ( V_2 ) ) ;
}
V_3 = F_11 ( V_2 , V_31 | V_32 |
V_33 * V_26 ) ;
if ( V_3 )
return V_3 ;
if ( V_25 == V_34 ) {
V_28 = F_2 ( F_14 ( V_2 ) ) ;
if ( V_28 < 1 || V_28 > V_35 )
return - V_36 ;
V_24 -> V_30 [ 0 ] = V_28 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ )
V_24 -> V_30 [ V_27 + 1 ] = F_2 ( F_15 ( V_2 ) ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_23 * V_24 ,
char V_25 , int V_37 ,
int V_26 )
{
int V_27 , V_28 ;
int V_38 ;
int V_3 ;
int V_10 ;
int V_9 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_28 = V_24 -> V_30 [ 0 ] ;
if ( V_25 == V_29 ) {
F_6 ( V_28 , F_14 ( V_2 ) ) ;
F_6 ( V_24 -> V_30 [ 1 ] , F_15 ( V_2 ) ) ;
}
for ( V_27 = 1 ; V_27 <= V_28 ; V_27 ++ ) {
if ( V_27 == V_28 && V_25 == V_34 ) {
if ( V_37 == V_39 )
V_38 = V_40 ;
else
V_38 = V_41 ;
} else {
if ( V_37 == V_39
&& V_25 == V_34 )
V_38 = V_42 ;
else
V_38 = V_31 ;
}
F_6 ( V_38 | V_32 , F_8 ( V_2 ) ) ;
if ( V_27 == 1 )
F_6 ( F_17 ( F_8 ( V_2 ) ) | V_20 ,
F_8 ( V_2 ) ) ;
V_9 = 0 ;
do {
F_9 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ( ! ( V_3 & V_43 ) )
&& ( V_9 ++ < V_21 ) );
V_10 = F_7 ( V_2 , V_3 , V_9 > V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_27 == 1 && V_25 == V_34
&& V_37 != V_39 ) {
V_28 = F_2 ( F_14 ( V_2 ) ) ;
if ( V_28 < 1 || V_28 > V_35 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_13 ,
V_28 ) ;
while ( F_2 ( F_3 ( V_2 ) ) &
V_4 )
F_6 ( V_43 ,
F_3 ( V_2 ) ) ;
F_6 ( V_22 , F_3 ( V_2 ) ) ;
return - V_36 ;
}
V_24 -> V_30 [ 0 ] = V_28 ;
}
if ( V_25 == V_34 )
V_24 -> V_30 [ V_27 ] = F_2 ( F_15 ( V_2 ) ) ;
if ( V_25 == V_29 && V_27 + 1 <= V_28 )
F_6 ( V_24 -> V_30 [ V_27 + 1 ] , F_15 ( V_2 ) ) ;
F_6 ( V_43 | V_22 , F_3 ( V_2 ) ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( F_19 ( V_2 ) ) | V_44 , F_19 ( V_2 ) ) ;
if ( ( F_2 ( F_19 ( V_2 ) ) & V_44 ) == 0 )
return - V_14 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
union V_23 * V_24 , char V_25 ,
int V_37 , int V_26 )
{
int V_10 = 0 ;
unsigned char V_45 ;
if ( V_37 == V_39 ) {
if ( V_25 == V_29 ) {
F_21 ( V_2 -> V_5 , V_46 , & V_45 ) ;
F_22 ( V_2 -> V_5 , V_46 ,
V_45 | V_47 ) ;
} else if ( ! ( V_2 -> V_48 & V_49 ) ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_14 ) ;
return - V_50 ;
}
}
if ( V_25 == V_29
|| V_37 == V_39 ) {
if ( V_24 -> V_30 [ 0 ] < 1 )
V_24 -> V_30 [ 0 ] = 1 ;
if ( V_24 -> V_30 [ 0 ] > V_35 )
V_24 -> V_30 [ 0 ] = V_35 ;
} else {
V_24 -> V_30 [ 0 ] = 32 ;
}
if ( ( V_2 -> V_48 & V_51 )
&& V_37 != V_39
&& F_18 ( V_2 ) == 0 )
V_10 = F_13 ( V_2 , V_24 ,
V_25 , V_26 ) ;
else
V_10 = F_16 ( V_2 , V_24 ,
V_25 ,
V_37 , V_26 ) ;
if ( V_10 == 0 && V_26 )
F_12 ( V_2 ) ;
if ( V_37 == V_39
&& V_25 == V_29 ) {
F_22 ( V_2 -> V_5 , V_46 , V_45 ) ;
}
return V_10 ;
}
static T_1 F_23 ( struct V_52 * V_53 , T_2 V_54 ,
unsigned short V_55 , char V_25 , T_3 V_37 ,
int V_56 , union V_23 * V_24 )
{
int V_26 ;
int V_30 = 0 ;
int V_57 , V_19 = 0 ;
struct V_1 * V_2 = F_24 ( V_53 ) ;
V_26 = ( V_2 -> V_48 & V_58 ) && ( V_55 & V_59 )
&& V_56 != V_60
&& V_56 != V_39 ;
switch ( V_56 ) {
case V_60 :
F_6 ( ( ( V_54 & 0x7f ) << 1 ) | ( V_25 & 0x01 ) ,
F_25 ( V_2 ) ) ;
V_19 = V_61 ;
break;
case V_62 :
F_6 ( ( ( V_54 & 0x7f ) << 1 ) | ( V_25 & 0x01 ) ,
F_25 ( V_2 ) ) ;
if ( V_25 == V_29 )
F_6 ( V_37 , F_26 ( V_2 ) ) ;
V_19 = V_63 ;
break;
case V_64 :
F_6 ( ( ( V_54 & 0x7f ) << 1 ) | ( V_25 & 0x01 ) ,
F_25 ( V_2 ) ) ;
F_6 ( V_37 , F_26 ( V_2 ) ) ;
if ( V_25 == V_29 )
F_6 ( V_24 -> V_65 , F_14 ( V_2 ) ) ;
V_19 = V_66 ;
break;
case V_67 :
F_6 ( ( ( V_54 & 0x7f ) << 1 ) | ( V_25 & 0x01 ) ,
F_25 ( V_2 ) ) ;
F_6 ( V_37 , F_26 ( V_2 ) ) ;
if ( V_25 == V_29 ) {
F_6 ( V_24 -> V_68 & 0xff , F_14 ( V_2 ) ) ;
F_6 ( ( V_24 -> V_68 & 0xff00 ) >> 8 , F_27 ( V_2 ) ) ;
}
V_19 = V_69 ;
break;
case V_70 :
F_6 ( ( ( V_54 & 0x7f ) << 1 ) | ( V_25 & 0x01 ) ,
F_25 ( V_2 ) ) ;
F_6 ( V_37 , F_26 ( V_2 ) ) ;
V_30 = 1 ;
break;
case V_39 :
F_6 ( ( V_54 & 0x7f ) << 1 , F_25 ( V_2 ) ) ;
if ( V_25 == V_34 ) {
F_6 ( V_37 , F_27 ( V_2 ) ) ;
} else
F_6 ( V_37 , F_26 ( V_2 ) ) ;
V_30 = 1 ;
break;
default:
F_4 ( & V_2 -> V_5 -> V_6 , L_15 ,
V_56 ) ;
return - V_50 ;
}
if ( V_26 )
F_6 ( F_2 ( F_19 ( V_2 ) ) | V_71 , F_19 ( V_2 ) ) ;
else
F_6 ( F_2 ( F_19 ( V_2 ) ) & ( ~ V_71 ) ,
F_19 ( V_2 ) ) ;
if ( V_30 )
V_57 = F_20 ( V_2 , V_24 , V_25 , V_56 ,
V_26 ) ;
else
V_57 = F_11 ( V_2 , V_19 | V_32 ) ;
if ( V_26 || V_30 )
F_6 ( F_2 ( F_19 ( V_2 ) ) &
~ ( V_71 | V_44 ) , F_19 ( V_2 ) ) ;
if ( V_30 )
return V_57 ;
if ( V_57 )
return V_57 ;
if ( ( V_25 == V_29 ) || ( V_19 == V_61 ) )
return 0 ;
switch ( V_19 & 0x7f ) {
case V_63 :
case V_66 :
V_24 -> V_65 = F_2 ( F_14 ( V_2 ) ) ;
break;
case V_69 :
V_24 -> V_68 = F_2 ( F_14 ( V_2 ) ) +
( F_2 ( F_27 ( V_2 ) ) << 8 ) ;
break;
}
return 0 ;
}
static T_4 F_28 ( struct V_52 * V_72 )
{
struct V_1 * V_2 = F_24 ( V_72 ) ;
return V_73 | V_74 |
V_75 | V_76 |
V_77 | V_78 |
( ( V_2 -> V_48 & V_58 ) ? V_79 : 0 ) |
( ( V_2 -> V_48 & V_49 ) ?
V_80 : 0 ) ;
}
static T_5 const void T_6 * F_29 ( const void T_6 * V_81 )
{
T_7 V_82 ;
const unsigned char V_83 [] = L_16 ;
for ( V_82 = 0 ; V_82 < 0x10000 ; V_82 += 0x10 ) {
if ( F_30 ( V_81 + V_82 , V_83 ,
sizeof( V_83 ) - 1 ) )
return V_81 + V_82 ;
}
return NULL ;
}
static void T_5 F_31 ( void )
{
void T_6 * V_81 ;
const void T_6 * V_84 ;
V_81 = F_32 ( 0xF0000 , 0x10000 ) ;
V_84 = F_29 ( V_81 ) ;
if ( V_84 ) {
V_85 = F_33 ( V_84 + 8 + 3 ) >> 1 ;
}
F_34 ( V_81 ) ;
}
static void T_8 F_35 ( T_3 type , const char * V_86 ,
struct V_52 * V_53 )
{
int V_27 ;
struct V_87 V_88 ;
for ( V_27 = 0 ; V_27 < F_36 ( V_89 ) ; V_27 ++ ) {
if ( ( type & ~ 0x80 ) != V_89 [ V_27 ] . type )
continue;
if ( strcasecmp ( V_86 , V_89 [ V_27 ] . V_86 ) )
continue;
memset ( & V_88 , 0 , sizeof( struct V_87 ) ) ;
V_88 . V_54 = V_89 [ V_27 ] . V_90 ;
F_37 ( V_88 . type , V_89 [ V_27 ] . V_91 , V_92 ) ;
F_38 ( V_53 , & V_88 ) ;
break;
}
}
static void T_8 F_39 ( const struct V_93 * V_94 ,
void * V_53 )
{
int V_27 , V_95 ;
if ( V_94 -> type != 10 )
return;
V_95 = ( V_94 -> V_96 - sizeof( struct V_93 ) ) / 2 ;
for ( V_27 = 0 ; V_27 < V_95 ; V_27 ++ ) {
const T_3 * V_97 = ( char * ) ( V_94 + 1 ) + ( V_27 * 2 ) ;
const char * V_86 = ( ( char * ) V_94 ) + V_94 -> V_96 ;
T_3 type = V_97 [ 0 ] ;
T_3 V_98 = V_97 [ 1 ] ;
if ( ! V_98 )
continue;
V_98 -- ;
while ( V_98 > 0 && V_86 [ 0 ] ) {
V_86 += strlen ( V_86 ) + 1 ;
V_98 -- ;
}
if ( V_86 [ 0 ] == 0 )
continue;
F_35 ( type , V_86 , V_53 ) ;
}
}
static void T_8 F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 & V_99 )
return;
if ( V_85 ) {
struct V_87 V_88 ;
memset ( & V_88 , 0 , sizeof( struct V_87 ) ) ;
V_88 . V_54 = V_85 ;
F_37 ( V_88 . type , L_17 , V_92 ) ;
F_38 ( & V_2 -> V_72 , & V_88 ) ;
}
if ( F_41 ( L_18 ) )
F_42 ( F_39 , & V_2 -> V_72 ) ;
}
static void T_5 F_31 ( void ) {}
static void T_8 F_40 ( struct V_1 * V_2 ) {}
static int T_8 F_43 ( struct V_5 * V_6 ,
const struct V_100 * V_101 )
{
unsigned char V_102 ;
int V_103 , V_27 ;
struct V_1 * V_2 ;
V_2 = F_44 ( sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_45 ( & V_2 -> V_72 , V_2 ) ;
V_2 -> V_72 . V_106 = V_107 ;
V_2 -> V_72 . V_108 = V_109 | V_110 ;
V_2 -> V_72 . V_111 = & V_112 ;
V_2 -> V_5 = V_6 ;
switch ( V_6 -> V_113 ) {
case V_114 :
case V_115 :
case V_116 :
V_2 -> V_48 |= V_99 ;
default:
V_2 -> V_48 |= V_49 ;
case V_117 :
V_2 -> V_48 |= V_58 ;
V_2 -> V_48 |= V_51 ;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
break;
}
for ( V_27 = 0 ; V_27 < F_36 ( V_122 ) ; V_27 ++ ) {
if ( V_2 -> V_48 & V_123 & ( 1 << V_27 ) )
F_46 ( & V_6 -> V_6 , L_19 ,
V_122 [ V_27 ] ) ;
}
V_2 -> V_48 &= ~ V_123 ;
V_103 = F_47 ( V_6 ) ;
if ( V_103 ) {
F_4 ( & V_6 -> V_6 , L_20 ,
V_103 ) ;
goto exit;
}
V_2 -> V_124 = F_48 ( V_6 , V_125 ) ;
if ( ! V_2 -> V_124 ) {
F_4 ( & V_6 -> V_6 , L_21
L_22 ) ;
V_103 = - V_126 ;
goto exit;
}
V_103 = F_49 ( & V_6 -> V_127 [ V_125 ] ) ;
if ( V_103 ) {
V_103 = - V_126 ;
goto exit;
}
V_103 = F_50 ( V_6 , V_125 , V_128 . V_86 ) ;
if ( V_103 ) {
F_4 ( & V_6 -> V_6 , L_23
L_24 , V_2 -> V_124 ,
( unsigned long long ) F_51 ( V_6 , V_125 ) ) ;
goto exit;
}
F_21 ( V_2 -> V_5 , V_46 , & V_102 ) ;
V_2 -> V_129 = V_102 ;
V_102 &= ~ V_47 ;
if ( ! ( V_102 & V_130 ) ) {
F_52 ( & V_6 -> V_6 , L_25 ) ;
V_102 |= V_130 ;
}
F_22 ( V_2 -> V_5 , V_46 , V_102 ) ;
if ( V_102 & V_131 )
F_5 ( & V_6 -> V_6 , L_26 ) ;
else
F_5 ( & V_6 -> V_6 , L_27 ) ;
if ( V_2 -> V_48 & ( V_58 | V_51 ) )
F_6 ( F_2 ( F_19 ( V_2 ) ) &
~ ( V_71 | V_44 ) , F_19 ( V_2 ) ) ;
V_2 -> V_72 . V_6 . V_132 = & V_6 -> V_6 ;
V_2 -> V_72 . V_133 = 3 ;
snprintf ( V_2 -> V_72 . V_86 , sizeof( V_2 -> V_72 . V_86 ) ,
L_28 , V_2 -> V_124 ) ;
V_103 = F_53 ( & V_2 -> V_72 ) ;
if ( V_103 ) {
F_4 ( & V_6 -> V_6 , L_29 ) ;
goto V_134;
}
F_40 ( V_2 ) ;
F_54 ( V_6 , V_2 ) ;
return 0 ;
V_134:
F_55 ( V_6 , V_125 ) ;
exit:
F_56 ( V_2 ) ;
return V_103 ;
}
static void T_9 F_57 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_58 ( V_6 ) ;
F_59 ( & V_2 -> V_72 ) ;
F_22 ( V_6 , V_46 , V_2 -> V_129 ) ;
F_55 ( V_6 , V_125 ) ;
F_54 ( V_6 , NULL ) ;
F_56 ( V_2 ) ;
}
static int F_60 ( struct V_5 * V_6 , T_10 V_135 )
{
struct V_1 * V_2 = F_58 ( V_6 ) ;
F_61 ( V_6 ) ;
F_22 ( V_6 , V_46 , V_2 -> V_129 ) ;
F_62 ( V_6 , F_63 ( V_6 , V_135 ) ) ;
return 0 ;
}
static int F_64 ( struct V_5 * V_6 )
{
F_62 ( V_6 , V_136 ) ;
F_65 ( V_6 ) ;
return F_47 ( V_6 ) ;
}
static int T_5 F_66 ( void )
{
if ( F_41 ( L_18 ) )
F_31 () ;
return F_67 ( & V_128 ) ;
}
static void T_11 F_68 ( void )
{
F_69 ( & V_128 ) ;
}
