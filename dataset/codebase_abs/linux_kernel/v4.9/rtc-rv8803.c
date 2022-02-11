static int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = V_5 ;
T_2 V_6 ;
do
V_6 = F_2 ( V_2 , V_3 ) ;
while ( ( V_6 == - V_7 || V_6 == - V_8 ) && -- V_4 );
if ( V_6 < 0 )
F_3 ( & V_2 -> V_9 , L_1 , V_3 ) ;
return V_6 ;
}
static int F_4 ( const struct V_1 * V_2 ,
T_1 V_3 , T_1 V_10 , T_1 * V_11 )
{
int V_4 = V_5 ;
T_2 V_6 ;
do
V_6 = F_5 ( V_2 , V_3 , V_10 , V_11 ) ;
while ( ( V_6 == - V_7 || V_6 == - V_8 ) && -- V_4 );
if ( V_6 != V_10 ) {
F_3 ( & V_2 -> V_9 ,
L_2 ,
V_3 , V_3 + V_10 - 1 ) ;
return V_6 < 0 ? V_6 : - V_8 ;
}
return 0 ;
}
static int F_6 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
int V_4 = V_5 ;
T_2 V_6 ;
do
V_6 = F_7 ( V_2 , V_3 , V_12 ) ;
while ( ( V_6 == - V_7 || V_6 == - V_8 ) && -- V_4 );
if ( V_6 )
F_3 ( & V_2 -> V_9 , L_3 , V_3 ) ;
return V_6 ;
}
static int F_8 ( const struct V_1 * V_2 ,
T_1 V_3 , T_1 V_10 , const T_1 * V_11 )
{
int V_4 = V_5 ;
T_2 V_6 ;
do
V_6 = F_9 ( V_2 , V_3 , V_10 ,
V_11 ) ;
while ( ( V_6 == - V_7 || V_6 == - V_8 ) && -- V_4 );
if ( V_6 )
F_3 ( & V_2 -> V_9 ,
L_4 ,
V_3 , V_3 + V_10 - 1 ) ;
return V_6 ;
}
static T_3 F_10 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_15 * V_16 = F_11 ( V_2 ) ;
unsigned long V_17 = 0 ;
int V_18 ;
F_12 ( & V_16 -> V_19 ) ;
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 <= 0 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_21 ;
}
if ( V_18 & V_22 )
F_14 ( & V_2 -> V_9 , L_5 ) ;
if ( V_18 & V_23 )
F_14 ( & V_2 -> V_9 , L_6 ) ;
if ( V_18 & V_24 ) {
V_18 &= ~ V_24 ;
V_16 -> V_25 &= ~ V_26 ;
V_17 |= V_27 ;
}
if ( V_18 & V_28 ) {
V_18 &= ~ V_28 ;
V_16 -> V_25 &= ~ V_29 ;
V_17 |= V_30 ;
}
if ( V_18 & V_31 ) {
V_18 &= ~ V_31 ;
V_16 -> V_25 &= ~ V_32 ;
V_17 |= V_33 ;
}
if ( V_17 ) {
F_15 ( V_16 -> V_34 , 1 , V_17 ) ;
F_6 ( V_2 , V_20 , V_18 ) ;
F_6 ( V_16 -> V_2 , V_35 , V_16 -> V_25 ) ;
}
F_13 ( & V_16 -> V_19 ) ;
return V_36 ;
}
static int F_16 ( struct V_37 * V_9 , struct V_38 * V_39 )
{
struct V_15 * V_16 = F_17 ( V_9 ) ;
T_1 V_40 [ 7 ] ;
T_1 V_41 [ 7 ] ;
T_1 * V_42 = V_40 ;
int V_6 , V_18 ;
V_18 = F_1 ( V_16 -> V_2 , V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_23 ) {
F_14 ( V_9 , L_7 ) ;
return - V_43 ;
}
V_6 = F_4 ( V_16 -> V_2 , V_44 , 7 , V_42 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_40 [ V_44 ] & 0x7f ) == F_18 ( 59 ) ) {
V_6 = F_4 ( V_16 -> V_2 , V_44 , 7 , V_41 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_41 [ V_44 ] & 0x7f ) != F_18 ( 59 ) )
V_42 = V_41 ;
}
V_39 -> V_45 = F_19 ( V_42 [ V_44 ] & 0x7f ) ;
V_39 -> V_46 = F_19 ( V_42 [ V_47 ] & 0x7f ) ;
V_39 -> V_48 = F_19 ( V_42 [ V_49 ] & 0x3f ) ;
V_39 -> V_50 = F_20 ( V_42 [ V_51 ] & 0x7f ) ;
V_39 -> V_52 = F_19 ( V_42 [ V_53 ] & 0x3f ) ;
V_39 -> V_54 = F_19 ( V_42 [ V_55 ] & 0x1f ) - 1 ;
V_39 -> V_56 = F_19 ( V_42 [ V_57 ] ) + 100 ;
return 0 ;
}
static int F_21 ( struct V_37 * V_9 , struct V_38 * V_39 )
{
struct V_15 * V_16 = F_17 ( V_9 ) ;
T_1 V_42 [ 7 ] ;
int V_25 , V_18 , V_6 ;
if ( ( V_39 -> V_56 < 100 ) || ( V_39 -> V_56 > 199 ) )
return - V_43 ;
V_25 = F_1 ( V_16 -> V_2 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
V_6 = F_6 ( V_16 -> V_2 , V_35 ,
V_25 | V_58 ) ;
if ( V_6 )
return V_6 ;
V_42 [ V_44 ] = F_18 ( V_39 -> V_45 ) ;
V_42 [ V_47 ] = F_18 ( V_39 -> V_46 ) ;
V_42 [ V_49 ] = F_18 ( V_39 -> V_48 ) ;
V_42 [ V_51 ] = 1 << ( V_39 -> V_50 ) ;
V_42 [ V_53 ] = F_18 ( V_39 -> V_52 ) ;
V_42 [ V_55 ] = F_18 ( V_39 -> V_54 + 1 ) ;
V_42 [ V_57 ] = F_18 ( V_39 -> V_56 - 100 ) ;
V_6 = F_8 ( V_16 -> V_2 , V_44 , 7 , V_42 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_6 ( V_16 -> V_2 , V_35 ,
V_25 & ~ V_58 ) ;
if ( V_6 )
return V_6 ;
F_12 ( & V_16 -> V_19 ) ;
V_18 = F_1 ( V_16 -> V_2 , V_20 ) ;
if ( V_18 < 0 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_18 ;
}
V_6 = F_6 ( V_16 -> V_2 , V_20 ,
V_18 & ~ ( V_22 | V_23 ) ) ;
F_13 ( & V_16 -> V_19 ) ;
return V_6 ;
}
static int F_22 ( struct V_37 * V_9 , struct V_59 * V_60 )
{
struct V_15 * V_16 = F_17 ( V_9 ) ;
struct V_1 * V_2 = V_16 -> V_2 ;
T_1 V_61 [ 3 ] ;
int V_18 , V_6 ;
V_6 = F_4 ( V_2 , V_62 , 3 , V_61 ) ;
if ( V_6 )
return V_6 ;
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
V_60 -> time . V_45 = 0 ;
V_60 -> time . V_46 = F_19 ( V_61 [ 0 ] & 0x7f ) ;
V_60 -> time . V_48 = F_19 ( V_61 [ 1 ] & 0x3f ) ;
V_60 -> time . V_52 = F_19 ( V_61 [ 2 ] & 0x3f ) ;
V_60 -> V_63 = ! ! ( V_16 -> V_25 & V_29 ) ;
V_60 -> V_64 = ( V_18 & V_28 ) && V_60 -> V_63 ;
return 0 ;
}
static int F_23 ( struct V_37 * V_9 , struct V_59 * V_60 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_15 * V_16 = F_17 ( V_9 ) ;
T_1 V_61 [ 3 ] ;
T_1 V_25 [ 2 ] ;
int V_6 , V_65 ;
if ( V_60 -> time . V_45 ) {
T_4 V_66 = F_25 ( & V_60 -> time ) ;
V_66 += 60 - V_60 -> time . V_45 ;
F_26 ( V_66 , & V_60 -> time ) ;
}
F_12 ( & V_16 -> V_19 ) ;
V_6 = F_4 ( V_2 , V_20 , 2 , V_25 ) ;
if ( V_6 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_6 ;
}
V_61 [ 0 ] = F_18 ( V_60 -> time . V_46 ) ;
V_61 [ 1 ] = F_18 ( V_60 -> time . V_48 ) ;
V_61 [ 2 ] = F_18 ( V_60 -> time . V_52 ) ;
if ( V_16 -> V_25 & ( V_29 | V_32 ) ) {
V_16 -> V_25 &= ~ ( V_29 | V_32 ) ;
V_65 = F_6 ( V_16 -> V_2 , V_35 ,
V_16 -> V_25 ) ;
if ( V_65 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_65 ;
}
}
V_25 [ 1 ] &= ~ V_28 ;
V_65 = F_6 ( V_16 -> V_2 , V_20 , V_25 [ 1 ] ) ;
F_13 ( & V_16 -> V_19 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_8 ( V_16 -> V_2 , V_62 , 3 , V_61 ) ;
if ( V_65 )
return V_65 ;
if ( V_60 -> V_63 ) {
if ( V_16 -> V_34 -> V_67 . V_63 )
V_16 -> V_25 |= V_32 ;
if ( V_16 -> V_34 -> V_68 . V_63 )
V_16 -> V_25 |= V_29 ;
V_65 = F_6 ( V_16 -> V_2 , V_35 ,
V_16 -> V_25 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_27 ( struct V_37 * V_9 , unsigned int V_63 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_15 * V_16 = F_17 ( V_9 ) ;
int V_25 , V_18 , V_65 ;
V_25 = V_16 -> V_25 ;
if ( V_63 ) {
if ( V_16 -> V_34 -> V_67 . V_63 )
V_25 |= V_32 ;
if ( V_16 -> V_34 -> V_68 . V_63 )
V_25 |= V_29 ;
} else {
if ( ! V_16 -> V_34 -> V_67 . V_63 )
V_25 &= ~ V_32 ;
if ( ! V_16 -> V_34 -> V_68 . V_63 )
V_25 &= ~ V_29 ;
}
F_12 ( & V_16 -> V_19 ) ;
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 < 0 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_18 ;
}
V_18 &= ~ ( V_28 | V_31 ) ;
V_65 = F_6 ( V_2 , V_20 , V_18 ) ;
F_13 ( & V_16 -> V_19 ) ;
if ( V_65 )
return V_65 ;
if ( V_25 != V_16 -> V_25 ) {
V_16 -> V_25 = V_25 ;
V_65 = F_6 ( V_2 , V_35 , V_16 -> V_25 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_28 ( struct V_37 * V_9 , unsigned int V_69 , unsigned long V_70 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
struct V_15 * V_16 = F_17 ( V_9 ) ;
int V_18 , V_6 = 0 ;
switch ( V_69 ) {
case V_71 :
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_22 )
F_14 ( & V_2 -> V_9 , L_5 ) ;
if ( V_18 & V_23 )
F_14 ( & V_2 -> V_9 , L_6 ) ;
V_18 &= V_22 | V_23 ;
if ( F_29 ( ( void V_72 * ) V_70 , & V_18 , sizeof( int ) ) )
return - V_73 ;
return 0 ;
case V_74 :
F_12 ( & V_16 -> V_19 ) ;
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 < 0 ) {
F_13 ( & V_16 -> V_19 ) ;
return V_18 ;
}
V_18 &= ~ ( V_22 | V_23 ) ;
V_6 = F_6 ( V_2 , V_20 , V_18 ) ;
F_13 ( & V_16 -> V_19 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
default:
return - V_75 ;
}
}
static T_5 F_30 ( struct V_76 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_81 ,
char * V_82 , T_6 V_83 , T_7 V_10 )
{
struct V_37 * V_9 = F_31 ( V_79 ) ;
struct V_1 * V_2 = F_24 ( V_9 ) ;
int V_6 ;
V_6 = F_6 ( V_2 , V_84 , V_82 [ 0 ] ) ;
if ( V_6 )
return V_6 ;
return 1 ;
}
static T_5 F_32 ( struct V_76 * V_77 , struct V_78 * V_79 ,
struct V_80 * V_81 ,
char * V_82 , T_6 V_83 , T_7 V_10 )
{
struct V_37 * V_9 = F_31 ( V_79 ) ;
struct V_1 * V_2 = F_24 ( V_9 ) ;
int V_6 ;
V_6 = F_1 ( V_2 , V_84 ) ;
if ( V_6 < 0 )
return V_6 ;
V_82 [ 0 ] = V_6 ;
return 1 ;
}
static int F_33 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
struct V_85 * V_86 = V_2 -> V_9 . V_87 ;
int V_65 ;
T_1 V_18 ;
if ( ! V_86 )
return 0 ;
if ( V_16 -> type != V_88 )
return 0 ;
V_65 = F_2 ( V_16 -> V_2 , V_89 ) ;
if ( V_65 < 0 )
return V_65 ;
V_18 = ~ ( V_90 | V_91 ) & ( T_1 ) V_65 ;
if ( F_34 ( V_86 , L_8 ) )
V_18 |= V_90 ;
if ( F_34 ( V_86 , L_9 ) )
V_18 |= V_91 ;
return F_7 ( V_16 -> V_2 , V_89 ,
V_18 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
const struct V_92 * V_93 )
{
struct V_94 * V_95 = F_36 ( V_2 -> V_9 . V_96 ) ;
struct V_15 * V_16 ;
int V_65 , V_18 ;
if ( ! F_37 ( V_95 , V_97 |
V_98 ) ) {
F_3 ( & V_95 -> V_9 , L_10 ) ;
return - V_8 ;
}
V_16 = F_38 ( & V_2 -> V_9 , sizeof( struct V_15 ) ,
V_99 ) ;
if ( ! V_16 )
return - V_100 ;
F_39 ( & V_16 -> V_19 ) ;
V_16 -> V_2 = V_2 ;
V_16 -> type = V_93 -> V_101 ;
F_40 ( V_2 , V_16 ) ;
V_18 = F_1 ( V_2 , V_20 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_22 )
F_14 ( & V_2 -> V_9 , L_5 ) ;
if ( V_18 & V_23 )
F_14 ( & V_2 -> V_9 , L_6 ) ;
if ( V_18 & V_28 )
F_14 ( & V_2 -> V_9 , L_11 ) ;
if ( V_2 -> V_13 > 0 ) {
V_65 = F_41 ( & V_2 -> V_9 , V_2 -> V_13 ,
NULL , F_10 ,
V_102 | V_103 ,
L_12 , V_2 ) ;
if ( V_65 ) {
F_14 ( & V_2 -> V_9 , L_13 ) ;
V_2 -> V_13 = 0 ;
} else {
V_104 . V_105 = F_22 ;
V_104 . V_106 = F_23 ;
V_104 . V_107 = F_27 ;
}
}
V_16 -> V_34 = F_42 ( & V_2 -> V_9 , V_2 -> V_108 ,
& V_104 , V_109 ) ;
if ( F_43 ( V_16 -> V_34 ) ) {
F_3 ( & V_2 -> V_9 , L_14 ) ;
return F_44 ( V_16 -> V_34 ) ;
}
V_65 = F_6 ( V_16 -> V_2 , V_110 , V_111 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_33 ( V_16 ) ;
if ( V_65 ) {
F_3 ( & V_2 -> V_9 , L_15 ) ;
return V_65 ;
}
V_65 = F_45 ( & V_2 -> V_9 , & V_112 ) ;
if ( V_65 )
return V_65 ;
V_16 -> V_34 -> V_113 = 1 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_9 , & V_112 ) ;
return 0 ;
}
