static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned long V_7 = 0 ;
int V_8 ;
F_3 ( & V_6 -> V_9 ) ;
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 <= 0 ) {
F_5 ( & V_6 -> V_9 ) ;
return V_11 ;
}
if ( V_8 & V_12 )
F_6 ( & V_4 -> V_13 , L_1 ) ;
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_13 , L_2 ) ;
if ( V_8 & V_15 ) {
V_8 &= ~ V_15 ;
V_6 -> V_16 &= ~ V_17 ;
V_7 |= V_18 ;
}
if ( V_8 & V_19 ) {
V_8 &= ~ V_19 ;
V_6 -> V_16 &= ~ V_20 ;
V_7 |= V_21 ;
}
if ( V_8 & V_22 ) {
V_8 &= ~ V_22 ;
V_6 -> V_16 &= ~ V_23 ;
V_7 |= V_24 ;
}
if ( V_7 ) {
F_7 ( V_6 -> V_25 , 1 , V_7 ) ;
F_8 ( V_4 , V_10 , V_8 ) ;
F_8 ( V_6 -> V_4 , V_26 ,
V_6 -> V_16 ) ;
}
F_5 ( & V_6 -> V_9 ) ;
return V_27 ;
}
static int F_9 ( struct V_28 * V_13 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_31 [ 7 ] ;
T_2 V_32 [ 7 ] ;
T_2 * V_33 = V_31 ;
int V_34 , V_8 ;
V_8 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_14 ) {
F_6 ( V_13 , L_3 ) ;
return - V_35 ;
}
V_34 = F_11 ( V_6 -> V_4 , V_36 ,
7 , V_33 ) ;
if ( V_34 != 7 )
return V_34 < 0 ? V_34 : - V_37 ;
if ( ( V_31 [ V_36 ] & 0x7f ) == F_12 ( 59 ) ) {
V_34 = F_11 ( V_6 -> V_4 , V_36 ,
7 , V_32 ) ;
if ( V_34 != 7 )
return V_34 < 0 ? V_34 : - V_37 ;
if ( ( V_32 [ V_36 ] & 0x7f ) != F_12 ( 59 ) )
V_33 = V_32 ;
}
V_30 -> V_38 = F_13 ( V_33 [ V_36 ] & 0x7f ) ;
V_30 -> V_39 = F_13 ( V_33 [ V_40 ] & 0x7f ) ;
V_30 -> V_41 = F_13 ( V_33 [ V_42 ] & 0x3f ) ;
V_30 -> V_43 = F_14 ( V_33 [ V_44 ] & 0x7f ) ;
V_30 -> V_45 = F_13 ( V_33 [ V_46 ] & 0x3f ) ;
V_30 -> V_47 = F_13 ( V_33 [ V_48 ] & 0x1f ) - 1 ;
V_30 -> V_49 = F_13 ( V_33 [ V_50 ] ) + 100 ;
return F_15 ( V_30 ) ;
}
static int F_16 ( struct V_28 * V_13 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_33 [ 7 ] ;
int V_8 , V_34 ;
unsigned long V_51 ;
if ( ( V_30 -> V_49 < 100 ) || ( V_30 -> V_49 > 199 ) )
return - V_35 ;
V_33 [ V_36 ] = F_12 ( V_30 -> V_38 ) ;
V_33 [ V_40 ] = F_12 ( V_30 -> V_39 ) ;
V_33 [ V_42 ] = F_12 ( V_30 -> V_41 ) ;
V_33 [ V_44 ] = 1 << ( V_30 -> V_43 ) ;
V_33 [ V_46 ] = F_12 ( V_30 -> V_45 ) ;
V_33 [ V_48 ] = F_12 ( V_30 -> V_47 + 1 ) ;
V_33 [ V_50 ] = F_12 ( V_30 -> V_49 - 100 ) ;
V_34 = F_17 ( V_6 -> V_4 , V_36 ,
7 , V_33 ) ;
if ( V_34 < 0 )
return V_34 ;
F_18 ( & V_6 -> V_9 , V_51 ) ;
V_8 = F_4 ( V_6 -> V_4 , V_10 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_8 ;
}
V_34 = F_8 ( V_6 -> V_4 , V_10 ,
V_8 & ~ V_14 ) ;
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_34 ;
}
static int F_20 ( struct V_28 * V_13 , struct V_52 * V_53 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_54 [ 3 ] ;
int V_8 , V_34 ;
V_34 = F_11 ( V_4 , V_55 ,
3 , V_54 ) ;
if ( V_34 != 3 )
return V_34 < 0 ? V_34 : - V_37 ;
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_53 -> time . V_38 = 0 ;
V_53 -> time . V_39 = F_13 ( V_54 [ 0 ] & 0x7f ) ;
V_53 -> time . V_41 = F_13 ( V_54 [ 1 ] & 0x3f ) ;
V_53 -> time . V_43 = - 1 ;
V_53 -> time . V_45 = F_13 ( V_54 [ 2 ] & 0x3f ) ;
V_53 -> time . V_47 = - 1 ;
V_53 -> time . V_49 = - 1 ;
V_53 -> V_56 = ! ! ( V_6 -> V_16 & V_20 ) ;
V_53 -> V_57 = ( V_8 & V_19 ) && V_53 -> V_56 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_13 , struct V_52 * V_53 )
{
struct V_3 * V_4 = F_22 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
T_2 V_54 [ 3 ] ;
T_2 V_16 [ 2 ] ;
int V_34 , V_58 ;
unsigned long V_51 ;
if ( V_53 -> time . V_38 ) {
T_3 V_59 = F_23 ( & V_53 -> time ) ;
V_59 += 60 - V_53 -> time . V_38 ;
F_24 ( V_59 , & V_53 -> time ) ;
}
F_18 ( & V_6 -> V_9 , V_51 ) ;
V_34 = F_11 ( V_4 , V_10 , 2 , V_16 ) ;
if ( V_34 != 2 ) {
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_34 < 0 ? V_34 : - V_37 ;
}
V_54 [ 0 ] = F_12 ( V_53 -> time . V_39 ) ;
V_54 [ 1 ] = F_12 ( V_53 -> time . V_41 ) ;
V_54 [ 2 ] = F_12 ( V_53 -> time . V_45 ) ;
if ( V_6 -> V_16 & ( V_20 | V_23 ) ) {
V_6 -> V_16 &= ~ ( V_20 | V_23 ) ;
V_58 = F_8 ( V_6 -> V_4 , V_26 ,
V_6 -> V_16 ) ;
if ( V_58 ) {
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_58 ;
}
}
V_16 [ 1 ] &= ~ V_19 ;
V_58 = F_8 ( V_6 -> V_4 , V_10 , V_16 [ 1 ] ) ;
F_19 ( & V_6 -> V_9 , V_51 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_17 ( V_6 -> V_4 , V_55 ,
3 , V_54 ) ;
if ( V_58 )
return V_58 ;
if ( V_53 -> V_56 ) {
if ( V_6 -> V_25 -> V_60 . V_56 )
V_6 -> V_16 |= V_23 ;
if ( V_6 -> V_25 -> V_61 . V_56 )
V_6 -> V_16 |= V_20 ;
V_58 = F_8 ( V_6 -> V_4 , V_26 ,
V_6 -> V_16 ) ;
if ( V_58 )
return V_58 ;
}
return 0 ;
}
static int F_25 ( struct V_28 * V_13 , unsigned int V_56 )
{
struct V_3 * V_4 = F_22 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
int V_16 , V_8 , V_58 ;
unsigned long V_51 ;
V_16 = V_6 -> V_16 ;
if ( V_56 ) {
if ( V_6 -> V_25 -> V_60 . V_56 )
V_16 |= V_23 ;
if ( V_6 -> V_25 -> V_61 . V_56 )
V_16 |= V_20 ;
} else {
if ( ! V_6 -> V_25 -> V_60 . V_56 )
V_16 &= ~ V_23 ;
if ( ! V_6 -> V_25 -> V_61 . V_56 )
V_16 &= ~ V_20 ;
}
F_18 ( & V_6 -> V_9 , V_51 ) ;
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_8 ;
}
V_8 &= ~ ( V_19 | V_22 ) ;
V_58 = F_8 ( V_4 , V_10 , V_8 ) ;
F_19 ( & V_6 -> V_9 , V_51 ) ;
if ( V_58 )
return V_58 ;
if ( V_16 != V_6 -> V_16 ) {
V_6 -> V_16 = V_16 ;
V_58 = F_8 ( V_4 , V_26 ,
V_6 -> V_16 ) ;
if ( V_58 )
return V_58 ;
}
return 0 ;
}
static int F_26 ( struct V_28 * V_13 , unsigned int V_62 , unsigned long V_63 )
{
struct V_3 * V_4 = F_22 ( V_13 ) ;
struct V_5 * V_6 = F_10 ( V_13 ) ;
int V_8 , V_34 = 0 ;
unsigned long V_51 ;
switch ( V_62 ) {
case V_64 :
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_12 )
F_6 ( & V_4 -> V_13 , L_1 ) ;
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_13 , L_2 ) ;
V_8 &= V_12 | V_14 ;
if ( F_27 ( ( void V_65 * ) V_63 , & V_8 , sizeof( int ) ) )
return - V_66 ;
return 0 ;
case V_67 :
F_18 ( & V_6 -> V_9 , V_51 ) ;
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 < 0 ) {
F_19 ( & V_6 -> V_9 , V_51 ) ;
return V_8 ;
}
V_8 &= ~ ( V_12 | V_14 ) ;
V_34 = F_8 ( V_4 , V_10 , V_8 ) ;
F_19 ( & V_6 -> V_9 , V_51 ) ;
if ( V_34 < 0 )
return V_34 ;
return 0 ;
default:
return - V_68 ;
}
}
static T_4 F_28 ( struct V_69 * V_70 , struct V_71 * V_72 ,
struct V_73 * V_74 ,
char * V_75 , T_5 V_76 , T_6 V_77 )
{
struct V_28 * V_13 = F_29 ( V_72 ) ;
struct V_3 * V_4 = F_22 ( V_13 ) ;
int V_34 ;
V_34 = F_8 ( V_4 , V_78 , V_75 [ 0 ] ) ;
if ( V_34 < 0 )
return V_34 ;
return 1 ;
}
static T_4 F_30 ( struct V_69 * V_70 , struct V_71 * V_72 ,
struct V_73 * V_74 ,
char * V_75 , T_5 V_76 , T_6 V_77 )
{
struct V_28 * V_13 = F_29 ( V_72 ) ;
struct V_3 * V_4 = F_22 ( V_13 ) ;
int V_34 ;
V_34 = F_4 ( V_4 , V_78 ) ;
if ( V_34 < 0 )
return V_34 ;
V_75 [ 0 ] = V_34 ;
return 1 ;
}
static int F_31 ( struct V_3 * V_4 ,
const struct V_79 * V_80 )
{
struct V_81 * V_82 = F_32 ( V_4 -> V_13 . V_83 ) ;
struct V_5 * V_6 ;
int V_58 , V_8 ;
if ( ! F_33 ( V_82 , V_84 |
V_85 ) ) {
F_34 ( & V_82 -> V_13 , L_4 ) ;
return - V_37 ;
}
V_6 = F_35 ( & V_4 -> V_13 , sizeof( struct V_5 ) ,
V_86 ) ;
if ( ! V_6 )
return - V_87 ;
V_6 -> V_4 = V_4 ;
F_36 ( V_4 , V_6 ) ;
V_8 = F_4 ( V_4 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_12 )
F_6 ( & V_4 -> V_13 , L_1 ) ;
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_13 , L_2 ) ;
if ( V_8 & V_19 )
F_6 ( & V_4 -> V_13 , L_5 ) ;
if ( V_4 -> V_1 > 0 ) {
V_58 = F_37 ( & V_4 -> V_13 , V_4 -> V_1 ,
NULL , F_1 ,
V_88 | V_89 ,
L_6 , V_4 ) ;
if ( V_58 ) {
F_6 ( & V_4 -> V_13 , L_7 ) ;
V_4 -> V_1 = 0 ;
} else {
V_90 . V_91 = F_20 ;
V_90 . V_92 = F_21 ;
V_90 . V_93 = F_25 ;
}
}
V_6 -> V_25 = F_38 ( & V_4 -> V_13 , V_4 -> V_94 ,
& V_90 , V_95 ) ;
if ( F_39 ( V_6 -> V_25 ) ) {
F_34 ( & V_4 -> V_13 , L_8 ) ;
return F_40 ( V_6 -> V_25 ) ;
}
V_58 = F_8 ( V_6 -> V_4 , V_96 ,
V_97 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_41 ( & V_4 -> V_13 , & V_98 ) ;
if ( V_58 )
return V_58 ;
V_6 -> V_25 -> V_99 = 1 ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 )
{
F_43 ( & V_4 -> V_13 , & V_98 ) ;
return 0 ;
}
