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
if ( V_2 -> V_9 & V_10 ) {
V_3 = F_2 ( F_7 ( V_2 ) ) & V_11 ;
if ( V_3 ) {
F_5 ( & V_2 -> V_5 -> V_6 ,
L_4 , V_3 ) ;
F_6 ( V_3 , F_7 ( V_2 ) ) ;
V_3 = F_2 ( F_7 ( V_2 ) ) & V_11 ;
if ( V_3 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_5 ,
V_3 ) ;
return - V_7 ;
}
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
int V_12 = 0 ;
if ( F_9 ( V_3 < 0 ) ) {
F_4 ( & V_2 -> V_5 -> V_6 , L_6 ) ;
F_5 ( & V_2 -> V_5 -> V_6 , L_7 ) ;
F_6 ( F_2 ( F_10 ( V_2 ) ) | V_13 ,
F_10 ( V_2 ) ) ;
F_11 ( 1000 , 2000 ) ;
F_6 ( F_2 ( F_10 ( V_2 ) ) & ( ~ V_13 ) ,
F_10 ( V_2 ) ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( ( V_3 & V_4 ) ||
! ( V_3 & V_14 ) )
F_4 ( & V_2 -> V_5 -> V_6 ,
L_8 ) ;
F_6 ( V_8 , F_3 ( V_2 ) ) ;
return - V_15 ;
}
if ( V_3 & V_14 ) {
V_12 = - V_16 ;
F_4 ( & V_2 -> V_5 -> V_6 , L_9 ) ;
}
if ( V_3 & V_17 ) {
if ( ( V_2 -> V_9 & V_10 ) &&
( F_2 ( F_7 ( V_2 ) ) & V_11 ) ) {
F_6 ( V_11 , F_7 ( V_2 ) ) ;
V_12 = - V_18 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_10 ) ;
} else {
V_12 = - V_19 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_11 ) ;
}
}
if ( V_3 & V_20 ) {
V_12 = - V_21 ;
F_5 ( & V_2 -> V_5 -> V_6 , L_12 ) ;
}
F_6 ( V_3 , F_3 ( V_2 ) ) ;
return V_12 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
int V_3 ;
do {
F_11 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ( ( V_3 & V_4 ) ||
! ( V_3 & ( V_23 | V_24 ) ) ) &&
( V_22 ++ < V_25 ) );
if ( V_22 > V_25 ) {
F_5 ( & V_2 -> V_5 -> V_6 , L_13 ) ;
return - V_15 ;
}
return V_3 & ( V_23 | V_24 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_22 = 0 ;
int V_3 ;
do {
F_11 ( 250 , 500 ) ;
V_3 = F_2 ( F_3 ( V_2 ) ) ;
} while ( ! ( V_3 & ( V_23 | V_26 ) ) &&
( V_22 ++ < V_25 ) );
if ( V_22 > V_25 ) {
F_5 ( & V_2 -> V_5 -> V_6 , L_14 ) ;
return - V_15 ;
}
return V_3 & V_23 ;
}
static int F_14 ( struct V_1 * V_2 , int V_27 )
{
int V_3 ;
int V_12 ;
const struct V_28 * V_29 = & V_2 -> V_30 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_2 -> V_9 & V_31 ) {
F_6 ( V_27 | V_32 | V_33 ,
F_10 ( V_2 ) ) ;
V_12 = F_15 ( V_2 -> V_34 ,
( V_3 = V_2 -> V_3 ) ,
V_29 -> V_22 ) ;
if ( ! V_12 ) {
V_3 = - V_15 ;
F_16 ( & V_2 -> V_5 -> V_6 ,
L_15 ) ;
}
V_2 -> V_3 = 0 ;
return F_8 ( V_2 , V_3 ) ;
}
F_6 ( V_27 | V_33 , F_10 ( V_2 ) ) ;
V_3 = F_12 ( V_2 ) ;
return F_8 ( V_2 , V_3 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
union V_35 * V_36 ,
char V_37 , int V_38 )
{
int V_39 , V_40 ;
int V_3 ;
F_2 ( F_10 ( V_2 ) ) ;
if ( V_37 == V_41 ) {
V_40 = V_36 -> V_42 [ 0 ] ;
F_6 ( V_40 , F_18 ( V_2 ) ) ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
F_6 ( V_36 -> V_42 [ V_39 + 1 ] , F_19 ( V_2 ) ) ;
}
V_3 = F_14 ( V_2 , V_43 |
( V_38 ? V_44 : 0 ) ) ;
if ( V_3 )
return V_3 ;
if ( V_37 == V_45 ) {
V_40 = F_2 ( F_18 ( V_2 ) ) ;
if ( V_40 < 1 || V_40 > V_46 )
return - V_47 ;
V_36 -> V_42 [ 0 ] = V_40 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ )
V_36 -> V_42 [ V_39 + 1 ] = F_2 ( F_19 ( V_2 ) ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 ) {
if ( ( ( V_2 -> V_49 & 0x1c ) == V_43 ) &&
( V_2 -> V_50 == 0 ) ) {
V_2 -> V_40 = F_2 ( F_18 ( V_2 ) ) ;
if ( V_2 -> V_40 < 1 || V_2 -> V_40 > V_46 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_16 ,
V_2 -> V_40 ) ;
V_2 -> V_40 = V_46 ;
} else {
F_5 ( & V_2 -> V_5 -> V_6 ,
L_17 ,
V_2 -> V_40 ) ;
}
V_2 -> V_36 [ - 1 ] = V_2 -> V_40 ;
}
if ( V_2 -> V_50 < V_2 -> V_40 )
V_2 -> V_36 [ V_2 -> V_50 ++ ] = F_21 ( F_19 ( V_2 ) ) ;
else
F_5 ( & V_2 -> V_5 -> V_6 ,
L_18 ) ;
if ( V_2 -> V_50 == V_2 -> V_40 - 1 )
F_6 ( V_2 -> V_49 | V_51 ,
F_10 ( V_2 ) ) ;
} else if ( V_2 -> V_50 < V_2 -> V_40 - 1 ) {
F_6 ( V_2 -> V_36 [ ++ V_2 -> V_50 ] , F_19 ( V_2 ) ) ;
}
F_6 ( V_26 , F_3 ( V_2 ) ) ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
unsigned short V_52 ;
unsigned int V_36 ;
V_52 = F_2 ( F_23 ( V_2 ) ) >> 1 ;
V_36 = F_24 ( F_25 ( V_2 ) ) ;
F_26 ( V_2 -> V_53 , V_52 , V_36 ) ;
F_6 ( V_54 , F_27 ( V_2 ) ) ;
return V_55 ;
}
static T_1 F_28 ( int V_56 , void * V_57 )
{
struct V_1 * V_2 = V_57 ;
T_2 V_58 ;
T_3 V_3 ;
F_29 ( V_2 -> V_5 , V_59 , & V_58 ) ;
if ( ! ( V_58 & V_60 ) )
return V_61 ;
if ( V_2 -> V_9 & V_62 ) {
V_3 = F_2 ( F_27 ( V_2 ) ) ;
if ( V_3 & V_54 )
return F_22 ( V_2 ) ;
}
V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 & V_26 )
F_20 ( V_2 ) ;
V_3 &= V_24 | V_23 ;
if ( V_3 ) {
F_6 ( V_3 , F_3 ( V_2 ) ) ;
V_2 -> V_3 = V_3 ;
F_30 ( & V_2 -> V_34 ) ;
}
return V_55 ;
}
static int F_31 ( struct V_1 * V_2 ,
union V_35 * V_36 ,
char V_37 , int V_63 ,
int V_38 )
{
int V_39 , V_40 ;
int V_64 ;
int V_3 ;
int V_12 ;
const struct V_28 * V_29 = & V_2 -> V_30 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
V_40 = V_36 -> V_42 [ 0 ] ;
if ( V_37 == V_41 ) {
F_6 ( V_40 , F_18 ( V_2 ) ) ;
F_6 ( V_36 -> V_42 [ 1 ] , F_19 ( V_2 ) ) ;
}
if ( V_63 == V_65 &&
V_37 == V_45 )
V_64 = V_66 ;
else
V_64 = V_43 ;
if ( V_2 -> V_9 & V_31 ) {
V_2 -> V_48 = ( V_37 == V_45 ) ;
if ( V_40 == 1 && V_2 -> V_48 )
V_64 |= V_51 ;
V_2 -> V_49 = V_64 | V_32 ;
V_2 -> V_40 = V_40 ;
V_2 -> V_50 = 0 ;
V_2 -> V_36 = & V_36 -> V_42 [ 1 ] ;
F_6 ( V_2 -> V_49 | V_33 , F_10 ( V_2 ) ) ;
V_12 = F_15 ( V_2 -> V_34 ,
( V_3 = V_2 -> V_3 ) ,
V_29 -> V_22 ) ;
if ( ! V_12 ) {
V_3 = - V_15 ;
F_16 ( & V_2 -> V_5 -> V_6 ,
L_15 ) ;
}
V_2 -> V_3 = 0 ;
return F_8 ( V_2 , V_3 ) ;
}
for ( V_39 = 1 ; V_39 <= V_40 ; V_39 ++ ) {
if ( V_39 == V_40 && V_37 == V_45 )
V_64 |= V_51 ;
F_6 ( V_64 , F_10 ( V_2 ) ) ;
if ( V_39 == 1 )
F_6 ( F_21 ( F_10 ( V_2 ) ) | V_33 ,
F_10 ( V_2 ) ) ;
V_3 = F_13 ( V_2 ) ;
if ( V_3 )
goto exit;
if ( V_39 == 1 && V_37 == V_45
&& V_63 != V_65 ) {
V_40 = F_2 ( F_18 ( V_2 ) ) ;
if ( V_40 < 1 || V_40 > V_46 ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_16 ,
V_40 ) ;
while ( F_2 ( F_3 ( V_2 ) ) &
V_4 )
F_6 ( V_26 ,
F_3 ( V_2 ) ) ;
F_6 ( V_24 , F_3 ( V_2 ) ) ;
return - V_47 ;
}
V_36 -> V_42 [ 0 ] = V_40 ;
}
if ( V_37 == V_45 )
V_36 -> V_42 [ V_39 ] = F_2 ( F_19 ( V_2 ) ) ;
if ( V_37 == V_41 && V_39 + 1 <= V_40 )
F_6 ( V_36 -> V_42 [ V_39 + 1 ] , F_19 ( V_2 ) ) ;
F_6 ( V_26 , F_3 ( V_2 ) ) ;
}
V_3 = F_12 ( V_2 ) ;
exit:
return F_8 ( V_2 , V_3 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( F_33 ( V_2 ) ) | V_67 , F_33 ( V_2 ) ) ;
if ( ( F_2 ( F_33 ( V_2 ) ) & V_67 ) == 0 )
return - V_16 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
union V_35 * V_36 , char V_37 ,
int V_63 , int V_38 )
{
int V_12 = 0 ;
unsigned char V_68 ;
if ( V_63 == V_65 ) {
if ( V_37 == V_41 ) {
F_35 ( V_2 -> V_5 , V_69 , & V_68 ) ;
F_36 ( V_2 -> V_5 , V_69 ,
V_68 | V_70 ) ;
} else if ( ! ( V_2 -> V_9 & V_71 ) ) {
F_4 ( & V_2 -> V_5 -> V_6 ,
L_19 ) ;
return - V_72 ;
}
}
if ( V_37 == V_41
|| V_63 == V_65 ) {
if ( V_36 -> V_42 [ 0 ] < 1 )
V_36 -> V_42 [ 0 ] = 1 ;
if ( V_36 -> V_42 [ 0 ] > V_46 )
V_36 -> V_42 [ 0 ] = V_46 ;
} else {
V_36 -> V_42 [ 0 ] = 32 ;
}
if ( ( V_2 -> V_9 & V_73 )
&& V_63 != V_65
&& F_32 ( V_2 ) == 0 )
V_12 = F_17 ( V_2 , V_36 ,
V_37 , V_38 ) ;
else
V_12 = F_31 ( V_2 , V_36 ,
V_37 ,
V_63 , V_38 ) ;
if ( V_63 == V_65
&& V_37 == V_41 ) {
F_36 ( V_2 -> V_5 , V_69 , V_68 ) ;
}
return V_12 ;
}
static T_4 F_37 ( struct V_28 * V_29 , T_2 V_52 ,
unsigned short V_74 , char V_37 , T_3 V_63 ,
int V_75 , union V_35 * V_36 )
{
int V_38 ;
int V_42 = 0 ;
int V_76 = 0 , V_27 = 0 ;
struct V_1 * V_2 = F_38 ( V_29 ) ;
F_39 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 ) {
F_40 ( & V_2 -> V_77 ) ;
return - V_7 ;
}
F_41 ( & V_2 -> V_5 -> V_6 ) ;
V_38 = ( V_2 -> V_9 & V_10 ) && ( V_74 & V_79 )
&& V_75 != V_80
&& V_75 != V_65 ;
switch ( V_75 ) {
case V_80 :
F_6 ( ( ( V_52 & 0x7f ) << 1 ) | ( V_37 & 0x01 ) ,
F_42 ( V_2 ) ) ;
V_27 = V_81 ;
break;
case V_82 :
F_6 ( ( ( V_52 & 0x7f ) << 1 ) | ( V_37 & 0x01 ) ,
F_42 ( V_2 ) ) ;
if ( V_37 == V_41 )
F_6 ( V_63 , F_43 ( V_2 ) ) ;
V_27 = V_83 ;
break;
case V_84 :
F_6 ( ( ( V_52 & 0x7f ) << 1 ) | ( V_37 & 0x01 ) ,
F_42 ( V_2 ) ) ;
F_6 ( V_63 , F_43 ( V_2 ) ) ;
if ( V_37 == V_41 )
F_6 ( V_36 -> V_85 , F_18 ( V_2 ) ) ;
V_27 = V_86 ;
break;
case V_87 :
F_6 ( ( ( V_52 & 0x7f ) << 1 ) | ( V_37 & 0x01 ) ,
F_42 ( V_2 ) ) ;
F_6 ( V_63 , F_43 ( V_2 ) ) ;
if ( V_37 == V_41 ) {
F_6 ( V_36 -> V_88 & 0xff , F_18 ( V_2 ) ) ;
F_6 ( ( V_36 -> V_88 & 0xff00 ) >> 8 , F_44 ( V_2 ) ) ;
}
V_27 = V_89 ;
break;
case V_90 :
F_6 ( ( ( V_52 & 0x7f ) << 1 ) | ( V_37 & 0x01 ) ,
F_42 ( V_2 ) ) ;
F_6 ( V_63 , F_43 ( V_2 ) ) ;
V_42 = 1 ;
break;
case V_65 :
F_6 ( ( V_52 & 0x7f ) << 1 , F_42 ( V_2 ) ) ;
if ( V_37 == V_45 ) {
F_6 ( V_63 , F_44 ( V_2 ) ) ;
} else
F_6 ( V_63 , F_43 ( V_2 ) ) ;
V_42 = 1 ;
break;
default:
F_4 ( & V_2 -> V_5 -> V_6 , L_20 ,
V_75 ) ;
V_76 = - V_72 ;
goto V_91;
}
if ( V_38 )
F_6 ( F_2 ( F_33 ( V_2 ) ) | V_92 , F_33 ( V_2 ) ) ;
else
F_6 ( F_2 ( F_33 ( V_2 ) ) & ( ~ V_92 ) ,
F_33 ( V_2 ) ) ;
if ( V_42 )
V_76 = F_34 ( V_2 , V_36 , V_37 , V_75 ,
V_38 ) ;
else
V_76 = F_14 ( V_2 , V_27 ) ;
if ( V_38 || V_42 )
F_6 ( F_2 ( F_33 ( V_2 ) ) &
~ ( V_92 | V_67 ) , F_33 ( V_2 ) ) ;
if ( V_42 )
goto V_91;
if ( V_76 )
goto V_91;
if ( ( V_37 == V_41 ) || ( V_27 == V_81 ) )
goto V_91;
switch ( V_27 & 0x7f ) {
case V_83 :
case V_86 :
V_36 -> V_85 = F_2 ( F_18 ( V_2 ) ) ;
break;
case V_89 :
V_36 -> V_88 = F_2 ( F_18 ( V_2 ) ) +
( F_2 ( F_44 ( V_2 ) ) << 8 ) ;
break;
}
V_91:
F_45 ( & V_2 -> V_5 -> V_6 ) ;
F_46 ( & V_2 -> V_5 -> V_6 ) ;
F_40 ( & V_2 -> V_77 ) ;
return V_76 ;
}
static T_5 F_47 ( struct V_28 * V_30 )
{
struct V_1 * V_2 = F_38 ( V_30 ) ;
return V_93 | V_94 |
V_95 | V_96 |
V_97 | V_98 |
( ( V_2 -> V_9 & V_10 ) ? V_99 : 0 ) |
( ( V_2 -> V_9 & V_71 ) ?
V_100 : 0 ) |
( ( V_2 -> V_9 & V_62 ) ?
V_101 : 0 ) ;
}
static int F_48 ( struct V_28 * V_30 )
{
struct V_1 * V_2 = F_38 ( V_30 ) ;
if ( ! ( V_2 -> V_9 & V_62 ) )
return - V_102 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = F_49 ( V_30 ) ;
if ( ! V_2 -> V_53 )
return - V_103 ;
F_6 ( V_104 , F_50 ( V_2 ) ) ;
F_6 ( V_54 , F_27 ( V_2 ) ) ;
return 0 ;
}
static T_6 const void T_7 * F_51 ( const void T_7 * V_105 )
{
T_8 V_106 ;
const unsigned char V_107 [] = L_21 ;
for ( V_106 = 0 ; V_106 < 0x10000 ; V_106 += 0x10 ) {
if ( F_52 ( V_105 + V_106 , V_107 ,
sizeof( V_107 ) - 1 ) )
return V_105 + V_106 ;
}
return NULL ;
}
static void T_6 F_53 ( void )
{
void T_7 * V_105 ;
const void T_7 * V_108 ;
V_105 = F_54 ( 0xF0000 , 0x10000 ) ;
V_108 = F_51 ( V_105 ) ;
if ( V_108 ) {
V_109 = F_55 ( V_108 + 8 + 3 ) >> 1 ;
}
F_56 ( V_105 ) ;
}
static void F_57 ( T_3 type , const char * V_110 ,
struct V_28 * V_29 )
{
int V_39 ;
struct V_111 V_112 ;
for ( V_39 = 0 ; V_39 < F_58 ( V_113 ) ; V_39 ++ ) {
if ( ( type & ~ 0x80 ) != V_113 [ V_39 ] . type )
continue;
if ( strcasecmp ( V_110 , V_113 [ V_39 ] . V_110 ) )
continue;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 . V_52 = V_113 [ V_39 ] . V_114 ;
F_59 ( V_112 . type , V_113 [ V_39 ] . V_115 , V_116 ) ;
F_60 ( V_29 , & V_112 ) ;
break;
}
}
static void F_61 ( const struct V_117 * V_118 , void * V_29 )
{
int V_39 , V_50 ;
if ( V_118 -> type != 10 )
return;
V_50 = ( V_118 -> V_119 - sizeof( struct V_117 ) ) / 2 ;
for ( V_39 = 0 ; V_39 < V_50 ; V_39 ++ ) {
const T_3 * V_120 = ( char * ) ( V_118 + 1 ) + ( V_39 * 2 ) ;
const char * V_110 = ( ( char * ) V_118 ) + V_118 -> V_119 ;
T_3 type = V_120 [ 0 ] ;
T_3 V_121 = V_120 [ 1 ] ;
if ( ! V_121 )
continue;
V_121 -- ;
while ( V_121 > 0 && V_110 [ 0 ] ) {
V_110 += strlen ( V_110 ) + 1 ;
V_121 -- ;
}
if ( V_110 [ 0 ] == 0 )
continue;
F_57 ( type , V_110 , V_29 ) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_122 )
return;
if ( V_109 ) {
struct V_111 V_112 ;
memset ( & V_112 , 0 , sizeof( struct V_111 ) ) ;
V_112 . V_52 = V_109 ;
F_59 ( V_112 . type , L_22 , V_116 ) ;
F_60 ( & V_2 -> V_30 , & V_112 ) ;
}
if ( F_63 ( L_23 ) )
F_64 ( F_61 , & V_2 -> V_30 ) ;
}
static void T_6 F_53 ( void ) {}
static void F_62 ( struct V_1 * V_2 ) {}
static int F_65 ( struct V_1 * V_2 )
{
struct V_123 * V_6 = & V_2 -> V_30 . V_6 ;
const struct V_124 * V_125 ;
struct V_126 V_127 ;
int V_128 ;
if ( ! V_2 -> V_129 )
return 0 ;
V_125 = V_2 -> V_129 ;
memset ( & V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 . V_130 = V_2 -> V_30 . V_131 ;
V_127 . V_132 = V_125 -> V_132 ;
V_127 . V_133 = V_125 -> V_133 ;
V_127 . V_134 = V_125 -> V_134 ;
V_127 . V_135 = V_125 -> V_135 ;
V_127 . V_136 = V_125 -> V_136 ;
V_127 . V_137 = V_125 -> V_137 ;
V_127 . V_138 = V_139 ;
V_2 -> V_140 = F_66 ( V_6 , L_24 ,
V_141 , & V_127 ,
sizeof( struct V_126 ) ) ;
if ( F_67 ( V_2 -> V_140 ) ) {
V_128 = F_68 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
F_4 ( V_6 , L_25 ) ;
return V_128 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_140 )
F_70 ( V_2 -> V_140 ) ;
}
static unsigned int F_71 ( struct V_1 * V_2 )
{
const struct V_142 * V_143 ;
const struct V_124 * V_125 ;
unsigned int V_144 = V_145 | V_146 ;
int V_39 ;
V_143 = F_72 ( V_147 ) ;
if ( V_143 ) {
V_125 = V_143 -> V_148 ;
for ( V_39 = 0 ; V_39 < V_125 -> V_133 ; V_39 ++ )
V_144 &= ~ V_125 -> V_134 [ V_39 ] ;
V_2 -> V_129 = V_125 ;
}
return V_144 ;
}
static inline int F_65 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_69 ( struct V_1 * V_2 ) { }
static inline unsigned int F_71 ( struct V_1 * V_2 )
{
return V_145 | V_146 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_149 V_150 [ 3 ] , * V_151 ;
struct V_152 * V_153 ;
unsigned int V_154 ;
T_5 V_155 , V_156 ;
T_5 V_157 , V_158 ;
T_9 V_159 ;
if ( ! ( V_2 -> V_9 & V_160 ) )
return;
F_74 ( V_5 , V_161 , & V_155 ) ;
F_74 ( V_5 , V_162 , & V_156 ) ;
if ( ! ( V_156 & V_163 ) )
return;
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
V_151 = & V_150 [ V_164 ] ;
V_151 -> V_165 = V_155 & ~ 1 ;
V_151 -> V_166 = V_151 -> V_165 + 32 - 1 ;
V_151 -> V_74 = V_167 ;
V_154 = F_75 ( F_76 ( V_5 -> V_154 ) , 2 ) ;
F_77 ( V_5 -> V_168 , V_154 , V_169 , & V_157 ) ;
V_151 = & V_150 [ V_170 ] ;
V_151 -> V_165 = ( V_157 & ~ 1 ) + V_171 ;
V_151 -> V_166 = V_151 -> V_165 + 3 ;
V_151 -> V_74 = V_167 ;
F_77 ( V_5 -> V_168 , V_154 , V_172 , & V_158 ) ;
V_158 |= V_173 ;
F_78 ( V_5 -> V_168 , V_154 , V_172 , V_158 ) ;
F_79 ( & V_174 ) ;
V_154 = F_75 ( F_76 ( V_5 -> V_154 ) , 1 ) ;
F_80 ( V_5 -> V_168 , V_154 , 0xe1 , 0x0 ) ;
F_77 ( V_5 -> V_168 , V_154 , V_175 , & V_157 ) ;
V_159 = V_157 & 0xfffffff0 ;
F_77 ( V_5 -> V_168 , V_154 , V_175 + 0x4 , & V_157 ) ;
V_159 |= ( T_9 ) V_157 << 32 ;
F_80 ( V_5 -> V_168 , V_154 , 0xe1 , 0x1 ) ;
F_81 ( & V_174 ) ;
V_151 = & V_150 [ V_176 ] ;
V_151 -> V_165 = ( V_177 ) V_159 + V_178 ;
V_151 -> V_166 = V_151 -> V_165 + 3 ;
V_151 -> V_74 = V_179 ;
V_153 = F_82 ( & V_5 -> V_6 , L_26 , - 1 ,
V_150 , 3 , & V_180 ,
sizeof( V_180 ) ) ;
if ( F_67 ( V_153 ) ) {
F_16 ( & V_5 -> V_6 , L_27 ) ;
return;
}
V_2 -> V_181 = V_153 ;
}
static T_10
F_83 ( T_5 V_182 , T_11 V_183 , T_5 V_184 ,
T_9 * V_185 , void * V_186 , void * V_187 )
{
struct V_1 * V_2 = V_186 ;
struct V_5 * V_153 = V_2 -> V_5 ;
T_10 V_3 ;
F_39 ( & V_2 -> V_77 ) ;
if ( ! V_2 -> V_78 ) {
V_2 -> V_78 = true ;
F_16 ( & V_153 -> V_6 , L_28 ) ;
F_16 ( & V_153 -> V_6 , L_29 ) ;
F_41 ( & V_153 -> V_6 ) ;
}
if ( ( V_182 & V_188 ) == V_189 )
V_3 = F_84 ( V_183 , ( T_5 * ) V_185 , V_184 ) ;
else
V_3 = F_85 ( V_183 , ( T_5 ) * V_185 , V_184 ) ;
F_40 ( & V_2 -> V_77 ) ;
return V_3 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_190 * V_191 ;
T_10 V_3 ;
V_191 = F_87 ( & V_2 -> V_5 -> V_6 ) ;
if ( V_191 ) {
V_3 = F_88 ( V_191 -> V_192 ,
V_193 , F_83 ,
NULL , V_2 ) ;
if ( F_89 ( V_3 ) )
return 0 ;
}
return F_90 ( & V_2 -> V_5 -> V_149 [ V_194 ] ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_190 * V_191 ;
V_191 = F_87 ( & V_2 -> V_5 -> V_6 ) ;
if ( ! V_191 )
return;
F_92 ( V_191 -> V_192 ,
V_193 , F_83 ) ;
F_39 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 )
F_93 ( & V_2 -> V_5 -> V_6 ) ;
F_40 ( & V_2 -> V_77 ) ;
}
static inline int F_86 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_91 ( struct V_1 * V_2 ) { }
static int F_94 ( struct V_5 * V_6 , const struct V_195 * V_143 )
{
unsigned char V_196 ;
int V_128 , V_39 ;
struct V_1 * V_2 ;
V_2 = F_95 ( & V_6 -> V_6 , sizeof( * V_2 ) , V_197 ) ;
if ( ! V_2 )
return - V_103 ;
F_96 ( & V_2 -> V_30 , V_2 ) ;
V_2 -> V_30 . V_198 = V_199 ;
V_2 -> V_30 . V_144 = F_71 ( V_2 ) ;
V_2 -> V_30 . V_200 = & V_201 ;
V_2 -> V_30 . V_6 . V_130 = & V_6 -> V_6 ;
F_97 ( & V_2 -> V_30 . V_6 , F_87 ( & V_6 -> V_6 ) ) ;
V_2 -> V_30 . V_202 = 3 ;
F_98 ( & V_2 -> V_77 ) ;
V_2 -> V_5 = V_6 ;
switch ( V_6 -> V_123 ) {
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
V_2 -> V_9 |= V_71 ;
V_2 -> V_9 |= V_31 ;
V_2 -> V_9 |= V_10 ;
V_2 -> V_9 |= V_73 ;
V_2 -> V_9 |= V_160 ;
V_2 -> V_9 |= V_62 ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
V_2 -> V_9 |= V_122 ;
default:
V_2 -> V_9 |= V_71 ;
V_2 -> V_9 |= V_31 ;
case V_214 :
V_2 -> V_9 |= V_10 ;
V_2 -> V_9 |= V_73 ;
case V_215 :
V_2 -> V_9 |= V_62 ;
case V_216 :
case V_217 :
case V_218 :
break;
}
for ( V_39 = 0 ; V_39 < F_58 ( V_219 ) ; V_39 ++ ) {
if ( V_2 -> V_9 & V_220 & ( 1 << V_39 ) )
F_99 ( & V_6 -> V_6 , L_30 ,
V_219 [ V_39 ] ) ;
}
V_2 -> V_9 &= ~ V_220 ;
V_128 = F_100 ( V_6 ) ;
if ( V_128 ) {
F_4 ( & V_6 -> V_6 , L_31 ,
V_128 ) ;
return V_128 ;
}
F_101 ( V_6 ) ;
V_2 -> V_221 = F_102 ( V_6 , V_194 ) ;
if ( ! V_2 -> V_221 ) {
F_4 ( & V_6 -> V_6 ,
L_32 ) ;
return - V_222 ;
}
if ( F_86 ( V_2 ) )
return - V_222 ;
V_128 = F_103 ( V_6 , 1 << V_194 ,
F_104 ( & V_6 -> V_6 ) ) ;
if ( V_128 ) {
F_4 ( & V_6 -> V_6 ,
L_33 ,
V_2 -> V_221 ,
( unsigned long long ) F_105 ( V_6 , V_194 ) ) ;
F_91 ( V_2 ) ;
return V_128 ;
}
F_35 ( V_2 -> V_5 , V_69 , & V_196 ) ;
V_2 -> V_223 = V_196 ;
V_196 &= ~ V_70 ;
if ( ! ( V_196 & V_224 ) ) {
F_106 ( & V_6 -> V_6 , L_34 ) ;
V_196 |= V_224 ;
}
F_36 ( V_2 -> V_5 , V_69 , V_196 ) ;
if ( V_196 & V_225 ) {
F_5 ( & V_6 -> V_6 , L_35 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
if ( V_2 -> V_9 & ( V_10 | V_73 ) )
F_6 ( F_2 ( F_33 ( V_2 ) ) &
~ ( V_92 | V_67 ) , F_33 ( V_2 ) ) ;
V_2 -> V_30 . V_22 = V_226 / 5 ;
if ( V_2 -> V_9 & V_31 ) {
T_2 V_227 , V_58 ;
F_29 ( V_2 -> V_5 , V_59 , & V_58 ) ;
if ( V_58 & V_60 )
F_16 ( & V_6 -> V_6 , L_36 ) ;
F_29 ( V_2 -> V_5 , V_228 , & V_227 ) ;
if ( V_227 & V_229 ) {
F_106 ( & V_6 -> V_6 , L_37 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
}
if ( V_2 -> V_9 & V_31 ) {
F_107 ( & V_2 -> V_34 ) ;
V_128 = F_108 ( & V_6 -> V_6 , V_6 -> V_56 , F_28 ,
V_230 ,
F_104 ( & V_6 -> V_6 ) , V_2 ) ;
if ( V_128 ) {
F_4 ( & V_6 -> V_6 , L_38 ,
V_6 -> V_56 , V_128 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
}
F_106 ( & V_6 -> V_6 , L_39 ,
V_2 -> V_9 & V_31 ? L_40 : L_41 ) ;
F_73 ( V_2 ) ;
snprintf ( V_2 -> V_30 . V_110 , sizeof( V_2 -> V_30 . V_110 ) ,
L_42 , V_2 -> V_221 ) ;
V_128 = F_109 ( & V_2 -> V_30 ) ;
if ( V_128 ) {
F_4 ( & V_6 -> V_6 , L_43 ) ;
F_91 ( V_2 ) ;
return V_128 ;
}
V_128 = F_48 ( & V_2 -> V_30 ) ;
if ( V_128 && V_128 != - V_102 )
F_16 ( & V_6 -> V_6 , L_44 ) ;
F_62 ( V_2 ) ;
F_65 ( V_2 ) ;
F_110 ( V_6 , V_2 ) ;
F_111 ( & V_6 -> V_6 , 1000 ) ;
F_112 ( & V_6 -> V_6 ) ;
F_46 ( & V_6 -> V_6 ) ;
F_113 ( & V_6 -> V_6 ) ;
return 0 ;
}
static void F_114 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_115 ( V_6 ) ;
F_116 ( & V_6 -> V_6 ) ;
F_117 ( & V_6 -> V_6 ) ;
F_69 ( V_2 ) ;
F_118 ( & V_2 -> V_30 ) ;
F_91 ( V_2 ) ;
F_36 ( V_6 , V_69 , V_2 -> V_223 ) ;
F_70 ( V_2 -> V_181 ) ;
}
static int F_119 ( struct V_123 * V_6 )
{
struct V_5 * V_5 = F_120 ( V_6 ) ;
struct V_1 * V_2 = F_115 ( V_5 ) ;
F_36 ( V_5 , V_69 , V_2 -> V_223 ) ;
return 0 ;
}
static int F_121 ( struct V_123 * V_6 )
{
struct V_5 * V_5 = F_120 ( V_6 ) ;
struct V_1 * V_2 = F_115 ( V_5 ) ;
int V_128 ;
V_128 = F_48 ( & V_2 -> V_30 ) ;
if ( V_128 && V_128 != - V_102 )
F_16 ( V_6 , L_44 ) ;
return 0 ;
}
static int T_6 F_122 ( void )
{
if ( F_63 ( L_23 ) )
F_53 () ;
return F_123 ( & V_231 ) ;
}
static void T_12 F_124 ( void )
{
F_125 ( & V_231 ) ;
}
