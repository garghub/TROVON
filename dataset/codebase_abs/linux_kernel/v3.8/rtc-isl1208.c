static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 [] ,
unsigned V_5 )
{
T_1 V_6 [ 1 ] = { V_3 } ;
struct V_7 V_8 [ 2 ] = {
{
. V_9 = V_2 -> V_9 ,
. V_5 = sizeof( V_6 ) ,
. V_4 = V_6
} ,
{
. V_9 = V_2 -> V_9 ,
. V_10 = V_11 ,
. V_5 = V_5 ,
. V_4 = V_4
}
} ;
int V_12 ;
F_2 ( V_3 > V_13 ) ;
F_2 ( V_3 + V_5 > V_13 + 1 ) ;
V_12 = F_3 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_12 > 0 )
V_12 = 0 ;
return V_12 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 const V_4 [] ,
unsigned V_5 )
{
T_1 V_15 [ V_13 + 2 ] ;
struct V_7 V_8 [ 1 ] = {
{
. V_9 = V_2 -> V_9 ,
. V_5 = V_5 + 1 ,
. V_4 = V_15
}
} ;
int V_12 ;
F_2 ( V_3 > V_13 ) ;
F_2 ( V_3 + V_5 > V_13 + 1 ) ;
V_15 [ 0 ] = V_3 ;
memcpy ( & V_15 [ 1 ] , & V_4 [ 0 ] , V_5 ) ;
V_12 = F_3 ( V_2 -> V_14 , V_8 , 1 ) ;
if ( V_12 > 0 )
V_12 = 0 ;
return V_12 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
T_1 V_16 [ V_17 ] = { 0 , } ;
T_1 V_18 [ V_17 ] = {
0x80 , 0x80 , 0x40 , 0xc0 , 0xe0 , 0x00 , 0xf8
} ;
int V_19 ;
int V_12 ;
V_12 = F_1 ( V_2 , 0 , V_16 , V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
for ( V_19 = 0 ; V_19 < V_17 ; ++ V_19 ) {
if ( V_16 [ V_19 ] & V_18 [ V_19 ] )
return - V_20 ;
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 )
{
int V_21 = F_7 ( V_2 , V_22 ) ;
if ( V_21 < 0 )
return - V_23 ;
return V_21 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
int V_24 = F_7 ( V_2 , V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 &= 0x3f ;
V_24 ^= 1 << 5 ;
V_24 += 2 * 9 ;
return V_24 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
int V_26 = F_7 ( V_2 , V_27 ) ;
if ( V_26 < 0 )
return - V_23 ;
V_26 = ( ( V_26 & 0x3 ) * 20 ) * ( V_26 & ( 1 << 2 ) ? - 1 : 1 ) ;
return V_26 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
T_1 V_4 [ V_28 ] = { 0 , } ;
int V_12 ;
V_12 = F_1 ( V_2 , V_29 , V_4 ,
V_28 ) ;
if ( V_12 < 0 )
return V_12 ;
return ( V_4 [ 1 ] << 8 ) | V_4 [ 0 ] ;
}
static int
F_11 ( struct V_1 * V_2 , T_2 V_30 )
{
T_1 V_4 [ V_28 ] ;
V_4 [ 0 ] = V_30 & 0xff ;
V_4 [ 1 ] = ( V_30 >> 8 ) & 0xff ;
return F_4 ( V_2 , V_29 , V_4 ,
V_28 ) ;
}
static int
F_12 ( struct V_1 * V_2 , int V_31 )
{
int V_32 = F_7 ( V_2 , V_33 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_34 , L_1 , V_35 ) ;
return V_32 ;
}
if ( V_31 )
V_32 |= V_36 | V_37 ;
else
V_32 &= ~ ( V_36 | V_37 ) ;
V_32 = F_14 ( V_2 , V_33 , V_32 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_34 , L_2 , V_35 ) ;
return V_32 ;
}
return 0 ;
}
static int
F_15 ( struct V_38 * V_34 , struct V_39 * V_40 )
{
struct V_1 * const V_2 = F_16 ( V_34 ) ;
int V_21 , V_26 , V_24 , V_30 ;
V_21 = F_6 ( V_2 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_3 , V_35 ) ;
return V_21 ;
}
F_17 ( V_40 , L_4 ,
( V_21 & V_41 ) ? L_5 : L_6 ,
( V_21 & V_42 ) ? L_7 : L_6 ,
( V_21 & V_43 ) ? L_8 : L_6 ,
( V_21 & V_44 ) ? L_9 : L_6 ,
( V_21 & V_45 ) ? L_10 : L_6 ,
( V_21 & V_46 ) ? L_11 : L_6 , V_21 ) ;
F_17 ( V_40 , L_12 ,
( V_21 & V_41 ) ? L_13 : L_14 ) ;
V_26 = F_9 ( V_2 ) ;
if ( V_26 >= 0 - 1 )
F_17 ( V_40 , L_15 , V_26 ) ;
V_24 = F_8 ( V_2 ) ;
if ( V_24 >= 0 )
F_17 ( V_40 , L_16 ,
V_24 >> 2 , ( V_24 & 0x3 ) * 25 ) ;
V_30 = F_10 ( V_2 ) ;
if ( V_30 >= 0 )
F_17 ( V_40 , L_17 , V_30 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_21 ;
T_1 V_16 [ V_17 ] = { 0 , } ;
V_21 = F_6 ( V_2 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_3 , V_35 ) ;
return - V_23 ;
}
V_21 = F_1 ( V_2 , 0 , V_16 , V_17 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_18 ,
V_35 ) ;
return V_21 ;
}
V_48 -> V_49 = F_19 ( V_16 [ V_50 ] ) ;
V_48 -> V_51 = F_19 ( V_16 [ V_52 ] ) ;
{
const T_1 V_53 = V_16 [ V_54 ] ;
if ( V_53 & V_55 )
V_48 -> V_56 = F_19 ( V_53 & 0x3f ) ;
else {
V_48 -> V_56 = F_19 ( V_53 & 0x1f ) ;
if ( V_53 & V_57 )
V_48 -> V_56 += 12 ;
}
}
V_48 -> V_58 = F_19 ( V_16 [ V_59 ] ) ;
V_48 -> V_60 = F_19 ( V_16 [ V_61 ] ) - 1 ;
V_48 -> V_62 = F_19 ( V_16 [ V_63 ] ) + 100 ;
V_48 -> V_64 = F_19 ( V_16 [ V_65 ] ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_47 * const V_48 = & V_67 -> time ;
T_1 V_16 [ V_68 ] = { 0 , } ;
int V_32 , V_69 , V_21 = F_6 ( V_2 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_3 , V_35 ) ;
return V_21 ;
}
V_21 = F_1 ( V_2 , V_70 , V_16 ,
V_68 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_19 ,
V_35 ) ;
return V_21 ;
}
V_48 -> V_49 = F_19 ( V_16 [ V_70 - V_70 ] & 0x7f ) ;
V_48 -> V_51 = F_19 ( V_16 [ V_71 - V_70 ] & 0x7f ) ;
V_48 -> V_56 = F_19 ( V_16 [ V_72 - V_70 ] & 0x3f ) ;
V_48 -> V_58 = F_19 ( V_16 [ V_73 - V_70 ] & 0x3f ) ;
V_48 -> V_60 =
F_19 ( V_16 [ V_74 - V_70 ] & 0x1f ) - 1 ;
V_48 -> V_64 = F_19 ( V_16 [ V_75 - V_70 ] & 0x03 ) ;
V_69 = F_7 ( V_2 , V_63 ) ;
if ( V_69 < 0 ) {
F_13 ( & V_2 -> V_34 , L_20 , V_35 ) ;
return V_69 ;
}
V_48 -> V_62 = F_19 ( V_69 ) + 100 ;
V_32 = F_7 ( V_2 , V_33 ) ;
if ( V_32 < 0 ) {
F_13 ( & V_2 -> V_34 , L_1 , V_35 ) ;
return V_32 ;
}
V_67 -> V_76 = ! ! ( V_32 & V_36 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_47 * V_77 = & V_67 -> time ;
T_1 V_16 [ V_68 ] = { 0 , } ;
const int V_78 = V_70 ;
unsigned long V_79 , V_80 ;
struct V_47 V_81 ;
int V_82 , V_31 ;
V_82 = F_18 ( V_2 , & V_81 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_22 ( & V_81 , & V_79 ) ;
if ( V_82 )
return V_82 ;
V_82 = F_22 ( V_77 , & V_80 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_67 -> V_76 || V_80 <= V_79 )
V_31 = 0x00 ;
else
V_31 = 0x80 ;
V_16 [ V_70 - V_78 ] = F_23 ( V_77 -> V_49 ) | V_31 ;
V_16 [ V_71 - V_78 ] = F_23 ( V_77 -> V_51 ) | V_31 ;
V_16 [ V_72 - V_78 ] = F_23 ( V_77 -> V_56 ) |
V_55 | V_31 ;
V_16 [ V_73 - V_78 ] = F_23 ( V_77 -> V_58 ) | V_31 ;
V_16 [ V_74 - V_78 ] = F_23 ( V_77 -> V_60 + 1 ) | V_31 ;
V_16 [ V_75 - V_78 ] = F_23 ( V_77 -> V_64 & 7 ) | V_31 ;
V_82 = F_4 ( V_2 , V_78 , V_16 ,
V_68 ) ;
if ( V_82 < 0 ) {
F_13 ( & V_2 -> V_34 , L_21 ,
V_35 ) ;
return V_82 ;
}
V_82 = F_12 ( V_2 , V_31 ) ;
if ( V_82 )
return V_82 ;
return 0 ;
}
static int
F_24 ( struct V_38 * V_34 , struct V_47 * V_48 )
{
return F_18 ( F_16 ( V_34 ) , V_48 ) ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_47 const * V_48 )
{
int V_21 ;
T_1 V_16 [ V_17 ] = { 0 , } ;
if ( V_48 -> V_62 < 100 )
return - V_83 ;
V_16 [ V_50 ] = F_23 ( V_48 -> V_49 ) ;
V_16 [ V_52 ] = F_23 ( V_48 -> V_51 ) ;
V_16 [ V_54 ] = F_23 ( V_48 -> V_56 ) | V_55 ;
V_16 [ V_59 ] = F_23 ( V_48 -> V_58 ) ;
V_16 [ V_61 ] = F_23 ( V_48 -> V_60 + 1 ) ;
V_16 [ V_63 ] = F_23 ( V_48 -> V_62 - 100 ) ;
V_16 [ V_65 ] = F_23 ( V_48 -> V_64 & 7 ) ;
V_21 = F_6 ( V_2 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_3 , V_35 ) ;
return V_21 ;
}
V_21 = F_14 ( V_2 , V_22 ,
V_21 | V_44 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_22 , V_35 ) ;
return V_21 ;
}
V_21 = F_4 ( V_2 , 0 , V_16 , V_17 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_23 ,
V_35 ) ;
return V_21 ;
}
V_21 = F_14 ( V_2 , V_22 ,
V_21 & ~ V_44 ) ;
if ( V_21 < 0 ) {
F_13 ( & V_2 -> V_34 , L_22 , V_35 ) ;
return V_21 ;
}
return 0 ;
}
static int
F_26 ( struct V_38 * V_34 , struct V_47 * V_48 )
{
return F_25 ( F_16 ( V_34 ) , V_48 ) ;
}
static int
F_27 ( struct V_38 * V_34 , struct V_66 * V_67 )
{
return F_20 ( F_16 ( V_34 ) , V_67 ) ;
}
static int
F_28 ( struct V_38 * V_34 , struct V_66 * V_67 )
{
return F_21 ( F_16 ( V_34 ) , V_67 ) ;
}
static T_3
F_29 ( int V_84 , void * V_85 )
{
unsigned long V_86 = V_87 + F_30 ( 1000 ) ;
struct V_1 * V_2 = V_85 ;
struct V_88 * V_89 = F_31 ( V_2 ) ;
int V_90 = 0 , V_21 , V_82 ;
while ( 1 ) {
V_21 = F_6 ( V_2 ) ;
if ( V_21 >= 0 )
break;
if ( F_32 ( V_87 , V_86 ) ) {
F_13 ( & V_2 -> V_34 , L_3 ,
V_35 ) ;
return V_21 ;
}
}
if ( V_21 & V_43 ) {
F_33 ( & V_2 -> V_34 , L_24 ) ;
F_34 ( V_89 , 1 , V_91 | V_92 ) ;
V_21 &= ~ V_43 ;
V_21 = F_14 ( V_2 , V_22 , V_21 ) ;
if ( V_21 < 0 )
F_13 ( & V_2 -> V_34 , L_22 ,
V_35 ) ;
else
V_90 = 1 ;
V_82 = F_12 ( V_2 , 0 ) ;
if ( V_82 )
return V_82 ;
}
return V_90 ? V_93 : V_94 ;
}
static T_4
F_35 ( struct V_38 * V_34 ,
struct V_95 * V_96 , char * V_4 )
{
int V_24 = F_8 ( F_16 ( V_34 ) ) ;
if ( V_24 < 0 )
return V_24 ;
return sprintf ( V_4 , L_25 , V_24 >> 2 , ( V_24 & 0x3 ) * 25 ) ;
}
static T_4
F_36 ( struct V_38 * V_34 ,
struct V_95 * V_96 , char * V_4 )
{
int V_26 = F_9 ( F_16 ( V_34 ) ) ;
if ( V_26 < 0 )
return V_26 ;
return sprintf ( V_4 , L_26 , V_26 ) ;
}
static T_4
F_37 ( struct V_38 * V_34 ,
struct V_95 * V_96 , char * V_4 )
{
int V_30 = F_10 ( F_16 ( V_34 ) ) ;
if ( V_30 < 0 )
return V_30 ;
return sprintf ( V_4 , L_27 , V_30 ) ;
}
static T_4
F_38 ( struct V_38 * V_34 ,
struct V_95 * V_96 ,
const char * V_4 , T_5 V_97 )
{
int V_30 = - 1 ;
if ( V_4 [ 0 ] == '0' && ( V_4 [ 1 ] == 'x' || V_4 [ 1 ] == 'X' ) ) {
if ( sscanf ( V_4 , L_28 , & V_30 ) != 1 )
return - V_83 ;
} else {
if ( sscanf ( V_4 , L_29 , & V_30 ) != 1 )
return - V_83 ;
}
if ( V_30 < 0 || V_30 > 0xffff )
return - V_83 ;
return F_11 ( F_16 ( V_34 ) , V_30 ) ? - V_23 : V_97 ;
}
static int
F_39 ( struct V_1 * V_2 , const struct V_98 * V_99 )
{
int V_100 = 0 ;
struct V_88 * V_89 ;
if ( ! F_40 ( V_2 -> V_14 , V_101 ) )
return - V_20 ;
if ( F_5 ( V_2 ) < 0 )
return - V_20 ;
F_41 ( & V_2 -> V_34 ,
L_30 V_102 L_31 ) ;
if ( V_2 -> V_84 > 0 ) {
V_100 = F_42 ( V_2 -> V_84 , NULL ,
F_29 ,
V_103 ,
V_104 . V_105 . V_106 , V_2 ) ;
if ( ! V_100 ) {
F_43 ( & V_2 -> V_34 , 1 ) ;
F_44 ( V_2 -> V_84 ) ;
} else {
F_13 ( & V_2 -> V_34 ,
L_32 ,
V_2 -> V_84 ) ;
V_2 -> V_84 = 0 ;
}
}
V_89 = F_45 ( V_104 . V_105 . V_106 ,
& V_2 -> V_34 , & V_107 ,
V_108 ) ;
if ( F_46 ( V_89 ) ) {
V_100 = F_47 ( V_89 ) ;
goto V_109;
}
F_48 ( V_2 , V_89 ) ;
V_100 = F_6 ( V_2 ) ;
if ( V_100 < 0 ) {
F_13 ( & V_2 -> V_34 , L_33 ) ;
goto V_110;
}
if ( V_100 & V_41 )
F_49 ( & V_2 -> V_34 , L_34
L_35 ) ;
V_100 = F_50 ( & V_2 -> V_34 . V_111 , & V_112 ) ;
if ( V_100 )
goto V_110;
return 0 ;
V_110:
F_51 ( V_89 ) ;
V_109:
if ( V_2 -> V_84 )
F_52 ( V_2 -> V_84 , V_2 ) ;
return V_100 ;
}
static int
F_53 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = F_31 ( V_2 ) ;
F_54 ( & V_2 -> V_34 . V_111 , & V_112 ) ;
F_51 ( V_89 ) ;
if ( V_2 -> V_84 )
F_52 ( V_2 -> V_84 , V_2 ) ;
return 0 ;
}
