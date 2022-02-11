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
return F_7 ( V_2 , V_21 ) ;
}
static int
F_8 ( struct V_1 * V_2 )
{
int V_22 = F_7 ( V_2 , V_23 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 &= 0x3f ;
V_22 ^= 1 << 5 ;
V_22 += 2 * 9 ;
return V_22 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
int V_24 = F_7 ( V_2 , V_25 ) ;
if ( V_24 < 0 )
return - V_26 ;
V_24 = ( ( V_24 & 0x3 ) * 20 ) * ( V_24 & ( 1 << 2 ) ? - 1 : 1 ) ;
return V_24 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
T_1 V_4 [ V_27 ] = { 0 , } ;
int V_12 ;
V_12 = F_1 ( V_2 , V_28 , V_4 ,
V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
return ( V_4 [ 1 ] << 8 ) | V_4 [ 0 ] ;
}
static int
F_11 ( struct V_1 * V_2 , T_2 V_29 )
{
T_1 V_4 [ V_27 ] ;
V_4 [ 0 ] = V_29 & 0xff ;
V_4 [ 1 ] = ( V_29 >> 8 ) & 0xff ;
return F_4 ( V_2 , V_28 , V_4 ,
V_27 ) ;
}
static int
F_12 ( struct V_1 * V_2 , int V_30 )
{
int V_31 = F_7 ( V_2 , V_32 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_33 , L_1 , V_34 ) ;
return V_31 ;
}
if ( V_30 )
V_31 |= V_35 | V_36 ;
else
V_31 &= ~ ( V_35 | V_36 ) ;
V_31 = F_14 ( V_2 , V_32 , V_31 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_33 , L_2 , V_34 ) ;
return V_31 ;
}
return 0 ;
}
static int
F_15 ( struct V_37 * V_33 , struct V_38 * V_39 )
{
struct V_1 * const V_2 = F_16 ( V_33 ) ;
int V_40 , V_24 , V_22 , V_29 ;
V_40 = F_6 ( V_2 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_40 ;
}
F_17 ( V_39 , L_4 ,
( V_40 & V_41 ) ? L_5 : L_6 ,
( V_40 & V_42 ) ? L_7 : L_6 ,
( V_40 & V_43 ) ? L_8 : L_6 ,
( V_40 & V_44 ) ? L_9 : L_6 ,
( V_40 & V_45 ) ? L_10 : L_6 ,
( V_40 & V_46 ) ? L_11 : L_6 , V_40 ) ;
F_17 ( V_39 , L_12 ,
( V_40 & V_41 ) ? L_13 : L_14 ) ;
V_24 = F_9 ( V_2 ) ;
if ( V_24 >= 0 - 1 )
F_17 ( V_39 , L_15 , V_24 ) ;
V_22 = F_8 ( V_2 ) ;
if ( V_22 >= 0 )
F_17 ( V_39 , L_16 ,
V_22 >> 2 , ( V_22 & 0x3 ) * 25 ) ;
V_29 = F_10 ( V_2 ) ;
if ( V_29 >= 0 )
F_17 ( V_39 , L_17 , V_29 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
int V_40 ;
T_1 V_16 [ V_17 ] = { 0 , } ;
V_40 = F_6 ( V_2 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return - V_26 ;
}
V_40 = F_1 ( V_2 , 0 , V_16 , V_17 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_18 ,
V_34 ) ;
return V_40 ;
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
int V_31 , V_69 , V_40 = F_6 ( V_2 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_40 ;
}
V_40 = F_1 ( V_2 , V_70 , V_16 ,
V_68 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_19 ,
V_34 ) ;
return V_40 ;
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
F_13 ( & V_2 -> V_33 , L_20 , V_34 ) ;
return V_69 ;
}
V_48 -> V_62 = F_19 ( V_69 ) + 100 ;
V_31 = F_7 ( V_2 , V_32 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_33 , L_1 , V_34 ) ;
return V_31 ;
}
V_67 -> V_76 = ! ! ( V_31 & V_35 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_47 * V_77 = & V_67 -> time ;
T_1 V_16 [ V_68 ] = { 0 , } ;
const int V_78 = V_70 ;
struct V_47 V_79 ;
int V_80 , V_30 ;
V_80 = F_18 ( V_2 , & V_79 ) ;
if ( V_80 )
return V_80 ;
if ( ! V_67 -> V_76 || F_22 ( V_77 , & V_79 ) <= 0 )
V_30 = 0x00 ;
else
V_30 = 0x80 ;
V_16 [ V_70 - V_78 ] = F_23 ( V_77 -> V_49 ) | V_30 ;
V_16 [ V_71 - V_78 ] = F_23 ( V_77 -> V_51 ) | V_30 ;
V_16 [ V_72 - V_78 ] = F_23 ( V_77 -> V_56 ) |
V_55 | V_30 ;
V_16 [ V_73 - V_78 ] = F_23 ( V_77 -> V_58 ) | V_30 ;
V_16 [ V_74 - V_78 ] = F_23 ( V_77 -> V_60 + 1 ) | V_30 ;
V_16 [ V_75 - V_78 ] = F_23 ( V_77 -> V_64 & 7 ) | V_30 ;
V_80 = F_4 ( V_2 , V_78 , V_16 ,
V_68 ) ;
if ( V_80 < 0 ) {
F_13 ( & V_2 -> V_33 , L_21 ,
V_34 ) ;
return V_80 ;
}
V_80 = F_12 ( V_2 , V_30 ) ;
if ( V_80 )
return V_80 ;
return 0 ;
}
static int
F_24 ( struct V_37 * V_33 , struct V_47 * V_48 )
{
return F_18 ( F_16 ( V_33 ) , V_48 ) ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_47 const * V_48 )
{
int V_40 ;
T_1 V_16 [ V_17 ] = { 0 , } ;
if ( V_48 -> V_62 < 100 )
return - V_81 ;
V_16 [ V_50 ] = F_23 ( V_48 -> V_49 ) ;
V_16 [ V_52 ] = F_23 ( V_48 -> V_51 ) ;
V_16 [ V_54 ] = F_23 ( V_48 -> V_56 ) | V_55 ;
V_16 [ V_59 ] = F_23 ( V_48 -> V_58 ) ;
V_16 [ V_61 ] = F_23 ( V_48 -> V_60 + 1 ) ;
V_16 [ V_63 ] = F_23 ( V_48 -> V_62 - 100 ) ;
V_16 [ V_65 ] = F_23 ( V_48 -> V_64 & 7 ) ;
V_40 = F_6 ( V_2 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_40 ;
}
V_40 = F_14 ( V_2 , V_21 ,
V_40 | V_44 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_22 , V_34 ) ;
return V_40 ;
}
V_40 = F_4 ( V_2 , 0 , V_16 , V_17 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_23 ,
V_34 ) ;
return V_40 ;
}
V_40 = F_14 ( V_2 , V_21 ,
V_40 & ~ V_44 ) ;
if ( V_40 < 0 ) {
F_13 ( & V_2 -> V_33 , L_22 , V_34 ) ;
return V_40 ;
}
return 0 ;
}
static int
F_26 ( struct V_37 * V_33 , struct V_47 * V_48 )
{
return F_25 ( F_16 ( V_33 ) , V_48 ) ;
}
static int
F_27 ( struct V_37 * V_33 , struct V_66 * V_67 )
{
return F_20 ( F_16 ( V_33 ) , V_67 ) ;
}
static int
F_28 ( struct V_37 * V_33 , struct V_66 * V_67 )
{
return F_21 ( F_16 ( V_33 ) , V_67 ) ;
}
static T_3
F_29 ( int V_82 , void * V_83 )
{
unsigned long V_84 = V_85 + F_30 ( 1000 ) ;
struct V_1 * V_2 = V_83 ;
struct V_86 * V_87 = F_31 ( V_2 ) ;
int V_88 = 0 , V_40 , V_80 ;
while ( 1 ) {
V_40 = F_6 ( V_2 ) ;
if ( V_40 >= 0 )
break;
if ( F_32 ( V_85 , V_84 ) ) {
F_13 ( & V_2 -> V_33 , L_3 ,
V_34 ) ;
return V_40 ;
}
}
if ( V_40 & V_43 ) {
F_33 ( & V_2 -> V_33 , L_24 ) ;
F_34 ( V_87 , 1 , V_89 | V_90 ) ;
V_40 &= ~ V_43 ;
V_40 = F_14 ( V_2 , V_21 , V_40 ) ;
if ( V_40 < 0 )
F_13 ( & V_2 -> V_33 , L_22 ,
V_34 ) ;
else
V_88 = 1 ;
V_80 = F_12 ( V_2 , 0 ) ;
if ( V_80 )
return V_80 ;
}
return V_88 ? V_91 : V_92 ;
}
static T_4
F_35 ( struct V_37 * V_33 ,
struct V_93 * V_94 , char * V_4 )
{
int V_22 = F_8 ( F_16 ( V_33 ) ) ;
if ( V_22 < 0 )
return V_22 ;
return sprintf ( V_4 , L_25 , V_22 >> 2 , ( V_22 & 0x3 ) * 25 ) ;
}
static T_4
F_36 ( struct V_37 * V_33 ,
struct V_93 * V_94 , char * V_4 )
{
int V_24 = F_9 ( F_16 ( V_33 ) ) ;
if ( V_24 < 0 )
return V_24 ;
return sprintf ( V_4 , L_26 , V_24 ) ;
}
static T_4
F_37 ( struct V_37 * V_33 ,
struct V_93 * V_94 , char * V_4 )
{
int V_29 = F_10 ( F_16 ( V_33 ) ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_4 , L_27 , V_29 ) ;
}
static T_4
F_38 ( struct V_37 * V_33 ,
struct V_93 * V_94 ,
const char * V_4 , T_5 V_95 )
{
int V_29 = - 1 ;
if ( V_4 [ 0 ] == '0' && ( V_4 [ 1 ] == 'x' || V_4 [ 1 ] == 'X' ) ) {
if ( sscanf ( V_4 , L_28 , & V_29 ) != 1 )
return - V_81 ;
} else {
if ( sscanf ( V_4 , L_29 , & V_29 ) != 1 )
return - V_81 ;
}
if ( V_29 < 0 || V_29 > 0xffff )
return - V_81 ;
return F_11 ( F_16 ( V_33 ) , V_29 ) ? - V_26 : V_95 ;
}
static int
F_39 ( struct V_1 * V_2 , const struct V_96 * V_97 )
{
int V_98 = 0 ;
struct V_86 * V_87 ;
if ( ! F_40 ( V_2 -> V_14 , V_99 ) )
return - V_20 ;
if ( F_5 ( V_2 ) < 0 )
return - V_20 ;
F_41 ( & V_2 -> V_33 ,
L_30 V_100 L_31 ) ;
if ( V_2 -> V_82 > 0 ) {
V_98 = F_42 ( & V_2 -> V_33 , V_2 -> V_82 , NULL ,
F_29 ,
V_101 ,
V_102 . V_103 . V_104 ,
V_2 ) ;
if ( ! V_98 ) {
F_43 ( & V_2 -> V_33 , 1 ) ;
F_44 ( V_2 -> V_82 ) ;
} else {
F_13 ( & V_2 -> V_33 ,
L_32 ,
V_2 -> V_82 ) ;
V_2 -> V_82 = 0 ;
}
}
V_87 = F_45 ( & V_2 -> V_33 , V_102 . V_103 . V_104 ,
& V_105 ,
V_106 ) ;
if ( F_46 ( V_87 ) )
return F_47 ( V_87 ) ;
F_48 ( V_2 , V_87 ) ;
V_98 = F_6 ( V_2 ) ;
if ( V_98 < 0 ) {
F_13 ( & V_2 -> V_33 , L_33 ) ;
return V_98 ;
}
if ( V_98 & V_41 )
F_49 ( & V_2 -> V_33 , L_34
L_35 ) ;
V_98 = F_50 ( & V_2 -> V_33 . V_107 , & V_108 ) ;
if ( V_98 )
return V_98 ;
return 0 ;
}
static int
F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_33 . V_107 , & V_108 ) ;
return 0 ;
}
