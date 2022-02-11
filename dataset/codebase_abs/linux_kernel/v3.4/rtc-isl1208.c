static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 [] ,
unsigned V_5 )
{
T_1 V_6 [ 1 ] = { V_3 } ;
struct V_7 V_8 [ 2 ] = {
{ V_2 -> V_9 , 0 , sizeof( V_6 ) , V_6 }
,
{ V_2 -> V_9 , V_10 , V_5 , V_4 }
} ;
int V_11 ;
F_2 ( V_3 > V_12 ) ;
F_2 ( V_3 + V_5 > V_12 + 1 ) ;
V_11 = F_3 ( V_2 -> V_13 , V_8 , 2 ) ;
if ( V_11 > 0 )
V_11 = 0 ;
return V_11 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 const V_4 [] ,
unsigned V_5 )
{
T_1 V_14 [ V_12 + 2 ] ;
struct V_7 V_8 [ 1 ] = {
{ V_2 -> V_9 , 0 , V_5 + 1 , V_14 }
} ;
int V_11 ;
F_2 ( V_3 > V_12 ) ;
F_2 ( V_3 + V_5 > V_12 + 1 ) ;
V_14 [ 0 ] = V_3 ;
memcpy ( & V_14 [ 1 ] , & V_4 [ 0 ] , V_5 ) ;
V_11 = F_3 ( V_2 -> V_13 , V_8 , 1 ) ;
if ( V_11 > 0 )
V_11 = 0 ;
return V_11 ;
}
static int
F_5 ( struct V_1 * V_2 )
{
T_1 V_15 [ V_16 ] = { 0 , } ;
T_1 V_17 [ V_16 ] = {
0x80 , 0x80 , 0x40 , 0xc0 , 0xe0 , 0x00 , 0xf8
} ;
int V_18 ;
int V_11 ;
V_11 = F_1 ( V_2 , 0 , V_15 , V_16 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_18 = 0 ; V_18 < V_16 ; ++ V_18 ) {
if ( V_15 [ V_18 ] & V_17 [ V_18 ] )
return - V_19 ;
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 )
{
int V_20 = F_7 ( V_2 , V_21 ) ;
if ( V_20 < 0 )
return - V_22 ;
return V_20 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
int V_23 = F_7 ( V_2 , V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 &= 0x3f ;
V_23 ^= 1 << 5 ;
V_23 += 2 * 9 ;
return V_23 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
int V_25 = F_7 ( V_2 , V_26 ) ;
if ( V_25 < 0 )
return - V_22 ;
V_25 = ( ( V_25 & 0x3 ) * 20 ) * ( V_25 & ( 1 << 2 ) ? - 1 : 1 ) ;
return V_25 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
T_1 V_4 [ V_27 ] = { 0 , } ;
int V_11 ;
V_11 = F_1 ( V_2 , V_28 , V_4 ,
V_27 ) ;
if ( V_11 < 0 )
return V_11 ;
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
int V_20 , V_25 , V_23 , V_29 ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_20 ;
}
F_17 ( V_39 , L_4 ,
( V_20 & V_40 ) ? L_5 : L_6 ,
( V_20 & V_41 ) ? L_7 : L_6 ,
( V_20 & V_42 ) ? L_8 : L_6 ,
( V_20 & V_43 ) ? L_9 : L_6 ,
( V_20 & V_44 ) ? L_10 : L_6 ,
( V_20 & V_45 ) ? L_11 : L_6 , V_20 ) ;
F_17 ( V_39 , L_12 ,
( V_20 & V_40 ) ? L_13 : L_14 ) ;
V_25 = F_9 ( V_2 ) ;
if ( V_25 >= 0 - 1 )
F_17 ( V_39 , L_15 , V_25 ) ;
V_23 = F_8 ( V_2 ) ;
if ( V_23 >= 0 )
F_17 ( V_39 , L_16 ,
V_23 >> 2 , ( V_23 & 0x3 ) * 25 ) ;
V_29 = F_10 ( V_2 ) ;
if ( V_29 >= 0 )
F_17 ( V_39 , L_17 , V_29 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
int V_20 ;
T_1 V_15 [ V_16 ] = { 0 , } ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return - V_22 ;
}
V_20 = F_1 ( V_2 , 0 , V_15 , V_16 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_18 ,
V_34 ) ;
return V_20 ;
}
V_47 -> V_48 = F_19 ( V_15 [ V_49 ] ) ;
V_47 -> V_50 = F_19 ( V_15 [ V_51 ] ) ;
{
const T_1 V_52 = V_15 [ V_53 ] ;
if ( V_52 & V_54 )
V_47 -> V_55 = F_19 ( V_52 & 0x3f ) ;
else {
V_47 -> V_55 = F_19 ( V_52 & 0x1f ) ;
if ( V_52 & V_56 )
V_47 -> V_55 += 12 ;
}
}
V_47 -> V_57 = F_19 ( V_15 [ V_58 ] ) ;
V_47 -> V_59 = F_19 ( V_15 [ V_60 ] ) - 1 ;
V_47 -> V_61 = F_19 ( V_15 [ V_62 ] ) + 100 ;
V_47 -> V_63 = F_19 ( V_15 [ V_64 ] ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_46 * const V_47 = & V_66 -> time ;
T_1 V_15 [ V_67 ] = { 0 , } ;
int V_31 , V_68 , V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_20 ;
}
V_20 = F_1 ( V_2 , V_69 , V_15 ,
V_67 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_19 ,
V_34 ) ;
return V_20 ;
}
V_47 -> V_48 = F_19 ( V_15 [ V_69 - V_69 ] & 0x7f ) ;
V_47 -> V_50 = F_19 ( V_15 [ V_70 - V_69 ] & 0x7f ) ;
V_47 -> V_55 = F_19 ( V_15 [ V_71 - V_69 ] & 0x3f ) ;
V_47 -> V_57 = F_19 ( V_15 [ V_72 - V_69 ] & 0x3f ) ;
V_47 -> V_59 =
F_19 ( V_15 [ V_73 - V_69 ] & 0x1f ) - 1 ;
V_47 -> V_63 = F_19 ( V_15 [ V_74 - V_69 ] & 0x03 ) ;
V_68 = F_7 ( V_2 , V_62 ) ;
if ( V_68 < 0 ) {
F_13 ( & V_2 -> V_33 , L_20 , V_34 ) ;
return V_68 ;
}
V_47 -> V_61 = F_19 ( V_68 ) + 100 ;
V_31 = F_7 ( V_2 , V_32 ) ;
if ( V_31 < 0 ) {
F_13 ( & V_2 -> V_33 , L_1 , V_34 ) ;
return V_31 ;
}
V_66 -> V_75 = ! ! ( V_31 & V_35 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_46 * V_76 = & V_66 -> time ;
T_1 V_15 [ V_67 ] = { 0 , } ;
const int V_77 = V_69 ;
unsigned long V_78 , V_79 ;
struct V_46 V_80 ;
int V_81 , V_30 ;
V_81 = F_18 ( V_2 , & V_80 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( & V_80 , & V_78 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_22 ( V_76 , & V_79 ) ;
if ( V_81 )
return V_81 ;
if ( ! V_66 -> V_75 || V_79 <= V_78 )
V_30 = 0x00 ;
else
V_30 = 0x80 ;
V_15 [ V_69 - V_77 ] = F_23 ( V_76 -> V_48 ) | V_30 ;
V_15 [ V_70 - V_77 ] = F_23 ( V_76 -> V_50 ) | V_30 ;
V_15 [ V_71 - V_77 ] = F_23 ( V_76 -> V_55 ) |
V_54 | V_30 ;
V_15 [ V_72 - V_77 ] = F_23 ( V_76 -> V_57 ) | V_30 ;
V_15 [ V_73 - V_77 ] = F_23 ( V_76 -> V_59 + 1 ) | V_30 ;
V_15 [ V_74 - V_77 ] = F_23 ( V_76 -> V_63 & 7 ) | V_30 ;
V_81 = F_4 ( V_2 , V_77 , V_15 ,
V_67 ) ;
if ( V_81 < 0 ) {
F_13 ( & V_2 -> V_33 , L_21 ,
V_34 ) ;
return V_81 ;
}
V_81 = F_12 ( V_2 , V_30 ) ;
if ( V_81 )
return V_81 ;
return 0 ;
}
static int
F_24 ( struct V_37 * V_33 , struct V_46 * V_47 )
{
return F_18 ( F_16 ( V_33 ) , V_47 ) ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_46 const * V_47 )
{
int V_20 ;
T_1 V_15 [ V_16 ] = { 0 , } ;
if ( V_47 -> V_61 < 100 )
return - V_82 ;
V_15 [ V_49 ] = F_23 ( V_47 -> V_48 ) ;
V_15 [ V_51 ] = F_23 ( V_47 -> V_50 ) ;
V_15 [ V_53 ] = F_23 ( V_47 -> V_55 ) | V_54 ;
V_15 [ V_58 ] = F_23 ( V_47 -> V_57 ) ;
V_15 [ V_60 ] = F_23 ( V_47 -> V_59 + 1 ) ;
V_15 [ V_62 ] = F_23 ( V_47 -> V_61 - 100 ) ;
V_15 [ V_64 ] = F_23 ( V_47 -> V_63 & 7 ) ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_3 , V_34 ) ;
return V_20 ;
}
V_20 = F_14 ( V_2 , V_21 ,
V_20 | V_43 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_22 , V_34 ) ;
return V_20 ;
}
V_20 = F_4 ( V_2 , 0 , V_15 , V_16 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_23 ,
V_34 ) ;
return V_20 ;
}
V_20 = F_14 ( V_2 , V_21 ,
V_20 & ~ V_43 ) ;
if ( V_20 < 0 ) {
F_13 ( & V_2 -> V_33 , L_22 , V_34 ) ;
return V_20 ;
}
return 0 ;
}
static int
F_26 ( struct V_37 * V_33 , struct V_46 * V_47 )
{
return F_25 ( F_16 ( V_33 ) , V_47 ) ;
}
static int
F_27 ( struct V_37 * V_33 , struct V_65 * V_66 )
{
return F_20 ( F_16 ( V_33 ) , V_66 ) ;
}
static int
F_28 ( struct V_37 * V_33 , struct V_65 * V_66 )
{
return F_21 ( F_16 ( V_33 ) , V_66 ) ;
}
static T_3
F_29 ( int V_83 , void * V_84 )
{
unsigned long V_85 = V_86 + F_30 ( 1000 ) ;
struct V_1 * V_2 = V_84 ;
int V_87 = 0 , V_20 , V_81 ;
while ( 1 ) {
V_20 = F_6 ( V_2 ) ;
if ( V_20 >= 0 )
break;
if ( F_31 ( V_86 , V_85 ) ) {
F_13 ( & V_2 -> V_33 , L_3 ,
V_34 ) ;
return V_20 ;
}
}
if ( V_20 & V_42 ) {
F_32 ( & V_2 -> V_33 , L_24 ) ;
V_20 &= ~ V_42 ;
V_20 = F_14 ( V_2 , V_21 , V_20 ) ;
if ( V_20 < 0 )
F_13 ( & V_2 -> V_33 , L_22 ,
V_34 ) ;
else
V_87 = 1 ;
V_81 = F_12 ( V_2 , 0 ) ;
if ( V_81 )
return V_81 ;
}
return V_87 ? V_88 : V_89 ;
}
static T_4
F_33 ( struct V_37 * V_33 ,
struct V_90 * V_91 , char * V_4 )
{
int V_23 = F_8 ( F_16 ( V_33 ) ) ;
if ( V_23 < 0 )
return V_23 ;
return sprintf ( V_4 , L_25 , V_23 >> 2 , ( V_23 & 0x3 ) * 25 ) ;
}
static T_4
F_34 ( struct V_37 * V_33 ,
struct V_90 * V_91 , char * V_4 )
{
int V_25 = F_9 ( F_16 ( V_33 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return sprintf ( V_4 , L_26 , V_25 ) ;
}
static T_4
F_35 ( struct V_37 * V_33 ,
struct V_90 * V_91 , char * V_4 )
{
int V_29 = F_10 ( F_16 ( V_33 ) ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_4 , L_27 , V_29 ) ;
}
static T_4
F_36 ( struct V_37 * V_33 ,
struct V_90 * V_91 ,
const char * V_4 , T_5 V_92 )
{
int V_29 = - 1 ;
if ( V_4 [ 0 ] == '0' && ( V_4 [ 1 ] == 'x' || V_4 [ 1 ] == 'X' ) ) {
if ( sscanf ( V_4 , L_28 , & V_29 ) != 1 )
return - V_82 ;
} else {
if ( sscanf ( V_4 , L_29 , & V_29 ) != 1 )
return - V_82 ;
}
if ( V_29 < 0 || V_29 > 0xffff )
return - V_82 ;
return F_11 ( F_16 ( V_33 ) , V_29 ) ? - V_22 : V_92 ;
}
static int
F_37 ( struct V_1 * V_2 , const struct V_93 * V_94 )
{
int V_95 = 0 ;
struct V_96 * V_97 ;
if ( ! F_38 ( V_2 -> V_13 , V_98 ) )
return - V_19 ;
if ( F_5 ( V_2 ) < 0 )
return - V_19 ;
F_39 ( & V_2 -> V_33 ,
L_30 V_99 L_31 ) ;
if ( V_2 -> V_83 > 0 ) {
V_95 = F_40 ( V_2 -> V_83 , NULL ,
F_29 ,
V_100 ,
V_101 . V_102 . V_103 , V_2 ) ;
if ( ! V_95 ) {
F_41 ( & V_2 -> V_33 , 1 ) ;
F_42 ( V_2 -> V_83 ) ;
} else {
F_13 ( & V_2 -> V_33 ,
L_32 ,
V_2 -> V_83 ) ;
V_2 -> V_83 = 0 ;
}
}
V_97 = F_43 ( V_101 . V_102 . V_103 ,
& V_2 -> V_33 , & V_104 ,
V_105 ) ;
if ( F_44 ( V_97 ) ) {
V_95 = F_45 ( V_97 ) ;
goto V_106;
}
F_46 ( V_2 , V_97 ) ;
V_95 = F_6 ( V_2 ) ;
if ( V_95 < 0 ) {
F_13 ( & V_2 -> V_33 , L_33 ) ;
goto V_107;
}
if ( V_95 & V_40 )
F_47 ( & V_2 -> V_33 , L_34
L_35 ) ;
V_95 = F_48 ( & V_2 -> V_33 . V_108 , & V_109 ) ;
if ( V_95 )
goto V_107;
return 0 ;
V_107:
F_49 ( V_97 ) ;
V_106:
if ( V_2 -> V_83 )
F_50 ( V_2 -> V_83 , V_2 ) ;
return V_95 ;
}
static int
F_51 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_52 ( V_2 ) ;
F_53 ( & V_2 -> V_33 . V_108 , & V_109 ) ;
F_49 ( V_97 ) ;
if ( V_2 -> V_83 )
F_50 ( V_2 -> V_83 , V_2 ) ;
return 0 ;
}
