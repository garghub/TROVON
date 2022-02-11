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
F_6 ( ( ( V_52 & 0x7f ) << 1 ) |
( ( V_2 -> V_91 & V_92 ) ?
( V_37 & 0x01 ) : 0 ) ,
F_42 ( V_2 ) ) ;
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
goto V_93;
}
if ( V_38 )
F_6 ( F_2 ( F_33 ( V_2 ) ) | V_94 , F_33 ( V_2 ) ) ;
else
F_6 ( F_2 ( F_33 ( V_2 ) ) & ( ~ V_94 ) ,
F_33 ( V_2 ) ) ;
if ( V_42 )
V_76 = F_34 ( V_2 , V_36 , V_37 , V_75 ,
V_38 ) ;
else
V_76 = F_14 ( V_2 , V_27 ) ;
if ( V_38 || V_42 )
F_6 ( F_2 ( F_33 ( V_2 ) ) &
~ ( V_94 | V_67 ) , F_33 ( V_2 ) ) ;
if ( V_42 )
goto V_93;
if ( V_76 )
goto V_93;
if ( ( V_37 == V_41 ) || ( V_27 == V_81 ) )
goto V_93;
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
V_93:
F_45 ( & V_2 -> V_5 -> V_6 ) ;
F_46 ( & V_2 -> V_5 -> V_6 ) ;
F_40 ( & V_2 -> V_77 ) ;
return V_76 ;
}
static T_5 F_47 ( struct V_28 * V_30 )
{
struct V_1 * V_2 = F_38 ( V_30 ) ;
return V_95 | V_96 |
V_97 | V_98 |
V_99 | V_100 |
( ( V_2 -> V_9 & V_10 ) ? V_101 : 0 ) |
( ( V_2 -> V_9 & V_71 ) ?
V_102 : 0 ) |
( ( V_2 -> V_9 & V_62 ) ?
V_103 : 0 ) ;
}
static int F_48 ( struct V_28 * V_30 )
{
struct V_1 * V_2 = F_38 ( V_30 ) ;
if ( ! ( V_2 -> V_9 & V_62 ) )
return - V_104 ;
if ( ! V_2 -> V_53 )
V_2 -> V_53 = F_49 ( V_30 ) ;
if ( ! V_2 -> V_53 )
return - V_105 ;
F_6 ( V_106 , F_50 ( V_2 ) ) ;
F_6 ( V_54 , F_27 ( V_2 ) ) ;
return 0 ;
}
static T_6 const void T_7 * F_51 ( const void T_7 * V_107 )
{
T_8 V_108 ;
const unsigned char V_109 [] = L_21 ;
for ( V_108 = 0 ; V_108 < 0x10000 ; V_108 += 0x10 ) {
if ( F_52 ( V_107 + V_108 , V_109 ,
sizeof( V_109 ) - 1 ) )
return V_107 + V_108 ;
}
return NULL ;
}
static void T_6 F_53 ( void )
{
void T_7 * V_107 ;
const void T_7 * V_110 ;
V_107 = F_54 ( 0xF0000 , 0x10000 ) ;
V_110 = F_51 ( V_107 ) ;
if ( V_110 ) {
V_111 = F_55 ( V_110 + 8 + 3 ) >> 1 ;
}
F_56 ( V_107 ) ;
}
static void F_57 ( T_3 type , const char * V_112 ,
struct V_28 * V_29 )
{
int V_39 ;
struct V_113 V_114 ;
for ( V_39 = 0 ; V_39 < F_58 ( V_115 ) ; V_39 ++ ) {
if ( ( type & ~ 0x80 ) != V_115 [ V_39 ] . type )
continue;
if ( strcasecmp ( V_112 , V_115 [ V_39 ] . V_112 ) )
continue;
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_52 = V_115 [ V_39 ] . V_116 ;
F_59 ( V_114 . type , V_115 [ V_39 ] . V_117 , V_118 ) ;
F_60 ( V_29 , & V_114 ) ;
break;
}
}
static void F_61 ( const struct V_119 * V_120 , void * V_29 )
{
int V_39 , V_50 ;
if ( V_120 -> type != 10 )
return;
V_50 = ( V_120 -> V_121 - sizeof( struct V_119 ) ) / 2 ;
for ( V_39 = 0 ; V_39 < V_50 ; V_39 ++ ) {
const T_3 * V_122 = ( char * ) ( V_120 + 1 ) + ( V_39 * 2 ) ;
const char * V_112 = ( ( char * ) V_120 ) + V_120 -> V_121 ;
T_3 type = V_122 [ 0 ] ;
T_3 V_123 = V_122 [ 1 ] ;
if ( ! V_123 )
continue;
V_123 -- ;
while ( V_123 > 0 && V_112 [ 0 ] ) {
V_112 += strlen ( V_112 ) + 1 ;
V_123 -- ;
}
if ( V_112 [ 0 ] == 0 )
continue;
F_57 ( type , V_112 , V_29 ) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_124 )
return;
if ( V_111 ) {
struct V_113 V_114 ;
memset ( & V_114 , 0 , sizeof( struct V_113 ) ) ;
V_114 . V_52 = V_111 ;
F_59 ( V_114 . type , L_22 , V_118 ) ;
F_60 ( & V_2 -> V_30 , & V_114 ) ;
}
if ( F_63 ( L_23 ) )
F_64 ( F_61 , & V_2 -> V_30 ) ;
}
static void T_6 F_53 ( void ) {}
static void F_62 ( struct V_1 * V_2 ) {}
static int F_65 ( struct V_1 * V_2 )
{
struct V_125 * V_6 = & V_2 -> V_30 . V_6 ;
const struct V_126 * V_127 ;
struct V_128 V_129 ;
int V_130 ;
if ( ! V_2 -> V_131 )
return 0 ;
V_127 = V_2 -> V_131 ;
memset ( & V_129 , 0 , sizeof( struct V_128 ) ) ;
V_129 . V_132 = V_2 -> V_30 . V_133 ;
V_129 . V_134 = V_127 -> V_134 ;
V_129 . V_135 = V_127 -> V_135 ;
V_129 . V_136 = V_127 -> V_136 ;
V_129 . V_137 = V_127 -> V_137 ;
V_129 . V_138 = V_127 -> V_138 ;
V_129 . V_139 = V_127 -> V_139 ;
V_129 . V_140 = V_141 ;
V_2 -> V_142 = F_66 ( V_6 , L_24 ,
V_143 , & V_129 ,
sizeof( struct V_128 ) ) ;
if ( F_67 ( V_2 -> V_142 ) ) {
V_130 = F_68 ( V_2 -> V_142 ) ;
V_2 -> V_142 = NULL ;
F_4 ( V_6 , L_25 ) ;
return V_130 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_142 )
F_70 ( V_2 -> V_142 ) ;
}
static unsigned int F_71 ( struct V_1 * V_2 )
{
const struct V_144 * V_145 ;
const struct V_126 * V_127 ;
unsigned int V_146 = V_147 | V_148 ;
int V_39 ;
V_145 = F_72 ( V_149 ) ;
if ( V_145 ) {
V_127 = V_145 -> V_150 ;
for ( V_39 = 0 ; V_39 < V_127 -> V_135 ; V_39 ++ )
V_146 &= ~ V_127 -> V_136 [ V_39 ] ;
V_2 -> V_131 = V_127 ;
}
return V_146 ;
}
static inline int F_65 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_69 ( struct V_1 * V_2 ) { }
static inline unsigned int F_71 ( struct V_1 * V_2 )
{
return V_147 | V_148 ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
struct V_151 V_152 [ 3 ] , * V_153 ;
struct V_154 * V_155 ;
unsigned int V_156 ;
T_5 V_157 , V_158 ;
T_5 V_159 , V_160 ;
T_9 V_161 ;
if ( ! ( V_2 -> V_9 & V_162 ) )
return;
F_74 ( V_5 , V_163 , & V_157 ) ;
F_74 ( V_5 , V_164 , & V_158 ) ;
if ( ! ( V_158 & V_165 ) )
return;
memset ( V_152 , 0 , sizeof( V_152 ) ) ;
V_153 = & V_152 [ V_166 ] ;
V_153 -> V_167 = V_157 & ~ 1 ;
V_153 -> V_168 = V_153 -> V_167 + 32 - 1 ;
V_153 -> V_74 = V_169 ;
V_156 = F_75 ( F_76 ( V_5 -> V_156 ) , 2 ) ;
F_77 ( V_5 -> V_170 , V_156 , V_171 , & V_159 ) ;
V_153 = & V_152 [ V_172 ] ;
V_153 -> V_167 = ( V_159 & ~ 1 ) + V_173 ;
V_153 -> V_168 = V_153 -> V_167 + 3 ;
V_153 -> V_74 = V_169 ;
F_77 ( V_5 -> V_170 , V_156 , V_174 , & V_160 ) ;
V_160 |= V_175 ;
F_78 ( V_5 -> V_170 , V_156 , V_174 , V_160 ) ;
F_79 ( & V_176 ) ;
V_156 = F_75 ( F_76 ( V_5 -> V_156 ) , 1 ) ;
F_80 ( V_5 -> V_170 , V_156 , 0xe1 , 0x0 ) ;
F_77 ( V_5 -> V_170 , V_156 , V_177 , & V_159 ) ;
V_161 = V_159 & 0xfffffff0 ;
F_77 ( V_5 -> V_170 , V_156 , V_177 + 0x4 , & V_159 ) ;
V_161 |= ( T_9 ) V_159 << 32 ;
F_80 ( V_5 -> V_170 , V_156 , 0xe1 , 0x1 ) ;
F_81 ( & V_176 ) ;
V_153 = & V_152 [ V_178 ] ;
V_153 -> V_167 = ( V_179 ) V_161 + V_180 ;
V_153 -> V_168 = V_153 -> V_167 + 3 ;
V_153 -> V_74 = V_181 ;
V_155 = F_82 ( & V_5 -> V_6 , L_26 , - 1 ,
V_152 , 3 , & V_182 ,
sizeof( V_182 ) ) ;
if ( F_67 ( V_155 ) ) {
F_16 ( & V_5 -> V_6 , L_27 ) ;
return;
}
V_2 -> V_183 = V_155 ;
}
static T_10
F_83 ( T_5 V_184 , T_11 V_185 , T_5 V_186 ,
T_9 * V_187 , void * V_188 , void * V_189 )
{
struct V_1 * V_2 = V_188 ;
struct V_5 * V_155 = V_2 -> V_5 ;
T_10 V_3 ;
F_39 ( & V_2 -> V_77 ) ;
if ( ! V_2 -> V_78 ) {
V_2 -> V_78 = true ;
F_16 ( & V_155 -> V_6 , L_28 ) ;
F_16 ( & V_155 -> V_6 , L_29 ) ;
F_41 ( & V_155 -> V_6 ) ;
}
if ( ( V_184 & V_190 ) == V_191 )
V_3 = F_84 ( V_185 , ( T_5 * ) V_187 , V_186 ) ;
else
V_3 = F_85 ( V_185 , ( T_5 ) * V_187 , V_186 ) ;
F_40 ( & V_2 -> V_77 ) ;
return V_3 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_192 * V_193 ;
T_10 V_3 ;
V_193 = F_87 ( & V_2 -> V_5 -> V_6 ) ;
if ( V_193 ) {
V_3 = F_88 ( V_193 -> V_194 ,
V_195 , F_83 ,
NULL , V_2 ) ;
if ( F_89 ( V_3 ) )
return 0 ;
}
return F_90 ( & V_2 -> V_5 -> V_151 [ V_196 ] ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_192 * V_193 ;
V_193 = F_87 ( & V_2 -> V_5 -> V_6 ) ;
if ( ! V_193 )
return;
F_92 ( V_193 -> V_194 ,
V_195 , F_83 ) ;
F_39 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_78 )
F_93 ( & V_2 -> V_5 -> V_6 ) ;
F_40 ( & V_2 -> V_77 ) ;
}
static inline int F_86 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_91 ( struct V_1 * V_2 ) { }
static int F_94 ( struct V_5 * V_6 , const struct V_197 * V_145 )
{
unsigned char V_198 ;
int V_130 , V_39 ;
struct V_1 * V_2 ;
V_2 = F_95 ( & V_6 -> V_6 , sizeof( * V_2 ) , V_199 ) ;
if ( ! V_2 )
return - V_105 ;
F_96 ( & V_2 -> V_30 , V_2 ) ;
V_2 -> V_30 . V_200 = V_201 ;
V_2 -> V_30 . V_146 = F_71 ( V_2 ) ;
V_2 -> V_30 . V_202 = & V_203 ;
V_2 -> V_30 . V_6 . V_132 = & V_6 -> V_6 ;
F_97 ( & V_2 -> V_30 . V_6 , F_87 ( & V_6 -> V_6 ) ) ;
V_2 -> V_30 . V_204 = 3 ;
F_98 ( & V_2 -> V_77 ) ;
V_2 -> V_5 = V_6 ;
switch ( V_6 -> V_125 ) {
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
V_2 -> V_9 |= V_71 ;
V_2 -> V_9 |= V_31 ;
V_2 -> V_9 |= V_10 ;
V_2 -> V_9 |= V_73 ;
if ( ! F_99 () )
V_2 -> V_9 |= V_162 ;
V_2 -> V_9 |= V_62 ;
break;
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
V_2 -> V_9 |= V_124 ;
default:
V_2 -> V_9 |= V_71 ;
V_2 -> V_9 |= V_31 ;
case V_217 :
V_2 -> V_9 |= V_10 ;
V_2 -> V_9 |= V_73 ;
case V_218 :
V_2 -> V_9 |= V_62 ;
case V_219 :
case V_220 :
case V_221 :
break;
}
for ( V_39 = 0 ; V_39 < F_58 ( V_222 ) ; V_39 ++ ) {
if ( V_2 -> V_9 & V_223 & ( 1 << V_39 ) )
F_100 ( & V_6 -> V_6 , L_30 ,
V_222 [ V_39 ] ) ;
}
V_2 -> V_9 &= ~ V_223 ;
V_130 = F_101 ( V_6 ) ;
if ( V_130 ) {
F_4 ( & V_6 -> V_6 , L_31 ,
V_130 ) ;
return V_130 ;
}
F_102 ( V_6 ) ;
V_2 -> V_224 = F_103 ( V_6 , V_196 ) ;
if ( ! V_2 -> V_224 ) {
F_4 ( & V_6 -> V_6 ,
L_32 ) ;
return - V_225 ;
}
if ( F_86 ( V_2 ) )
return - V_225 ;
V_130 = F_104 ( V_6 , 1 << V_196 ,
F_105 ( & V_6 -> V_6 ) ) ;
if ( V_130 ) {
F_4 ( & V_6 -> V_6 ,
L_33 ,
V_2 -> V_224 ,
( unsigned long long ) F_106 ( V_6 , V_196 ) ) ;
F_91 ( V_2 ) ;
return V_130 ;
}
F_35 ( V_2 -> V_5 , V_69 , & V_198 ) ;
V_2 -> V_91 = V_198 ;
V_198 &= ~ V_70 ;
if ( ! ( V_198 & V_226 ) ) {
F_107 ( & V_6 -> V_6 , L_34 ) ;
V_198 |= V_226 ;
}
F_36 ( V_2 -> V_5 , V_69 , V_198 ) ;
if ( V_198 & V_227 ) {
F_5 ( & V_6 -> V_6 , L_35 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
if ( V_198 & V_92 )
F_107 ( & V_6 -> V_6 , L_36 ) ;
if ( V_2 -> V_9 & ( V_10 | V_73 ) )
F_6 ( F_2 ( F_33 ( V_2 ) ) &
~ ( V_94 | V_67 ) , F_33 ( V_2 ) ) ;
V_2 -> V_30 . V_22 = V_228 / 5 ;
if ( V_2 -> V_9 & V_31 ) {
T_2 V_229 , V_58 ;
F_29 ( V_2 -> V_5 , V_59 , & V_58 ) ;
if ( V_58 & V_60 )
F_16 ( & V_6 -> V_6 , L_37 ) ;
F_29 ( V_2 -> V_5 , V_230 , & V_229 ) ;
if ( V_229 & V_231 ) {
F_107 ( & V_6 -> V_6 , L_38 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
}
if ( V_2 -> V_9 & V_31 ) {
F_108 ( & V_2 -> V_34 ) ;
V_130 = F_109 ( & V_6 -> V_6 , V_6 -> V_56 , F_28 ,
V_232 ,
F_105 ( & V_6 -> V_6 ) , V_2 ) ;
if ( V_130 ) {
F_4 ( & V_6 -> V_6 , L_39 ,
V_6 -> V_56 , V_130 ) ;
V_2 -> V_9 &= ~ V_31 ;
}
}
F_107 ( & V_6 -> V_6 , L_40 ,
V_2 -> V_9 & V_31 ? L_41 : L_42 ) ;
F_73 ( V_2 ) ;
snprintf ( V_2 -> V_30 . V_112 , sizeof( V_2 -> V_30 . V_112 ) ,
L_43 , V_2 -> V_224 ) ;
V_130 = F_110 ( & V_2 -> V_30 ) ;
if ( V_130 ) {
F_91 ( V_2 ) ;
return V_130 ;
}
V_130 = F_48 ( & V_2 -> V_30 ) ;
if ( V_130 && V_130 != - V_104 )
F_16 ( & V_6 -> V_6 , L_44 ) ;
F_62 ( V_2 ) ;
F_65 ( V_2 ) ;
F_111 ( V_6 , V_2 ) ;
F_112 ( & V_6 -> V_6 , 1000 ) ;
F_113 ( & V_6 -> V_6 ) ;
F_46 ( & V_6 -> V_6 ) ;
F_114 ( & V_6 -> V_6 ) ;
return 0 ;
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_116 ( V_6 ) ;
F_117 ( & V_6 -> V_6 ) ;
F_118 ( & V_6 -> V_6 ) ;
F_69 ( V_2 ) ;
F_119 ( & V_2 -> V_30 ) ;
F_91 ( V_2 ) ;
F_36 ( V_6 , V_69 , V_2 -> V_91 ) ;
F_70 ( V_2 -> V_183 ) ;
}
static int F_120 ( struct V_125 * V_6 )
{
struct V_5 * V_5 = F_121 ( V_6 ) ;
struct V_1 * V_2 = F_116 ( V_5 ) ;
F_36 ( V_5 , V_69 , V_2 -> V_91 ) ;
return 0 ;
}
static int F_122 ( struct V_125 * V_6 )
{
struct V_5 * V_5 = F_121 ( V_6 ) ;
struct V_1 * V_2 = F_116 ( V_5 ) ;
int V_130 ;
V_130 = F_48 ( & V_2 -> V_30 ) ;
if ( V_130 && V_130 != - V_104 )
F_16 ( V_6 , L_44 ) ;
return 0 ;
}
static int T_6 F_123 ( void )
{
if ( F_63 ( L_23 ) )
F_53 () ;
return F_124 ( & V_233 ) ;
}
static void T_12 F_125 ( void )
{
F_126 ( & V_233 ) ;
}
