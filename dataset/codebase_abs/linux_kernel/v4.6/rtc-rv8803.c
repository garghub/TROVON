static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned long V_7 = 0 ;
int V_8 , V_9 = 0 ;
F_3 ( & V_6 -> V_10 ) ;
do {
V_8 = F_4 ( V_4 , V_11 ) ;
V_9 ++ ;
} while ( ( V_8 == - V_12 ) && ( V_9 < 3 ) );
if ( V_8 <= 0 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_13 ;
}
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_15 , L_1 ) ;
if ( V_8 & V_16 )
F_6 ( & V_4 -> V_15 , L_2 ) ;
if ( V_8 & V_17 ) {
V_8 &= ~ V_17 ;
V_6 -> V_18 &= ~ V_19 ;
V_7 |= V_20 ;
}
if ( V_8 & V_21 ) {
V_8 &= ~ V_21 ;
V_6 -> V_18 &= ~ V_22 ;
V_7 |= V_23 ;
}
if ( V_8 & V_24 ) {
V_8 &= ~ V_24 ;
V_6 -> V_18 &= ~ V_25 ;
V_7 |= V_26 ;
}
if ( V_7 ) {
F_7 ( V_6 -> V_27 , 1 , V_7 ) ;
F_8 ( V_4 , V_11 , V_8 ) ;
F_8 ( V_6 -> V_4 , V_28 ,
V_6 -> V_18 ) ;
}
F_5 ( & V_6 -> V_10 ) ;
return V_29 ;
}
static int F_9 ( struct V_30 * V_15 , struct V_31 * V_32 )
{
struct V_5 * V_6 = F_10 ( V_15 ) ;
T_2 V_33 [ 7 ] ;
T_2 V_34 [ 7 ] ;
T_2 * V_35 = V_33 ;
int V_36 , V_8 ;
V_8 = F_4 ( V_6 -> V_4 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_16 ) {
F_6 ( V_15 , L_3 ) ;
return - V_37 ;
}
V_36 = F_11 ( V_6 -> V_4 , V_38 ,
7 , V_35 ) ;
if ( V_36 != 7 )
return V_36 < 0 ? V_36 : - V_39 ;
if ( ( V_33 [ V_38 ] & 0x7f ) == F_12 ( 59 ) ) {
V_36 = F_11 ( V_6 -> V_4 , V_38 ,
7 , V_34 ) ;
if ( V_36 != 7 )
return V_36 < 0 ? V_36 : - V_39 ;
if ( ( V_34 [ V_38 ] & 0x7f ) != F_12 ( 59 ) )
V_35 = V_34 ;
}
V_32 -> V_40 = F_13 ( V_35 [ V_38 ] & 0x7f ) ;
V_32 -> V_41 = F_13 ( V_35 [ V_42 ] & 0x7f ) ;
V_32 -> V_43 = F_13 ( V_35 [ V_44 ] & 0x3f ) ;
V_32 -> V_45 = F_14 ( V_35 [ V_46 ] & 0x7f ) ;
V_32 -> V_47 = F_13 ( V_35 [ V_48 ] & 0x3f ) ;
V_32 -> V_49 = F_13 ( V_35 [ V_50 ] & 0x1f ) - 1 ;
V_32 -> V_51 = F_13 ( V_35 [ V_52 ] ) + 100 ;
return F_15 ( V_32 ) ;
}
static int F_16 ( struct V_30 * V_15 , struct V_31 * V_32 )
{
struct V_5 * V_6 = F_10 ( V_15 ) ;
T_2 V_35 [ 7 ] ;
int V_8 , V_36 ;
if ( ( V_32 -> V_51 < 100 ) || ( V_32 -> V_51 > 199 ) )
return - V_37 ;
V_35 [ V_38 ] = F_12 ( V_32 -> V_40 ) ;
V_35 [ V_42 ] = F_12 ( V_32 -> V_41 ) ;
V_35 [ V_44 ] = F_12 ( V_32 -> V_43 ) ;
V_35 [ V_46 ] = 1 << ( V_32 -> V_45 ) ;
V_35 [ V_48 ] = F_12 ( V_32 -> V_47 ) ;
V_35 [ V_50 ] = F_12 ( V_32 -> V_49 + 1 ) ;
V_35 [ V_52 ] = F_12 ( V_32 -> V_51 - 100 ) ;
V_36 = F_17 ( V_6 -> V_4 , V_38 ,
7 , V_35 ) ;
if ( V_36 < 0 )
return V_36 ;
F_3 ( & V_6 -> V_10 ) ;
V_8 = F_4 ( V_6 -> V_4 , V_11 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_8 ;
}
V_36 = F_8 ( V_6 -> V_4 , V_11 ,
V_8 & ~ V_16 ) ;
F_5 ( & V_6 -> V_10 ) ;
return V_36 ;
}
static int F_18 ( struct V_30 * V_15 , struct V_53 * V_54 )
{
struct V_5 * V_6 = F_10 ( V_15 ) ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_2 V_55 [ 3 ] ;
int V_8 , V_36 ;
V_36 = F_11 ( V_4 , V_56 ,
3 , V_55 ) ;
if ( V_36 != 3 )
return V_36 < 0 ? V_36 : - V_39 ;
V_8 = F_4 ( V_4 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_54 -> time . V_40 = 0 ;
V_54 -> time . V_41 = F_13 ( V_55 [ 0 ] & 0x7f ) ;
V_54 -> time . V_43 = F_13 ( V_55 [ 1 ] & 0x3f ) ;
V_54 -> time . V_45 = - 1 ;
V_54 -> time . V_47 = F_13 ( V_55 [ 2 ] & 0x3f ) ;
V_54 -> time . V_49 = - 1 ;
V_54 -> time . V_51 = - 1 ;
V_54 -> V_57 = ! ! ( V_6 -> V_18 & V_22 ) ;
V_54 -> V_58 = ( V_8 & V_21 ) && V_54 -> V_57 ;
return 0 ;
}
static int F_19 ( struct V_30 * V_15 , struct V_53 * V_54 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
T_2 V_55 [ 3 ] ;
T_2 V_18 [ 2 ] ;
int V_36 , V_59 ;
if ( V_54 -> time . V_40 ) {
T_3 V_60 = F_21 ( & V_54 -> time ) ;
V_60 += 60 - V_54 -> time . V_40 ;
F_22 ( V_60 , & V_54 -> time ) ;
}
F_3 ( & V_6 -> V_10 ) ;
V_36 = F_11 ( V_4 , V_11 , 2 , V_18 ) ;
if ( V_36 != 2 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_36 < 0 ? V_36 : - V_39 ;
}
V_55 [ 0 ] = F_12 ( V_54 -> time . V_41 ) ;
V_55 [ 1 ] = F_12 ( V_54 -> time . V_43 ) ;
V_55 [ 2 ] = F_12 ( V_54 -> time . V_47 ) ;
if ( V_6 -> V_18 & ( V_22 | V_25 ) ) {
V_6 -> V_18 &= ~ ( V_22 | V_25 ) ;
V_59 = F_8 ( V_6 -> V_4 , V_28 ,
V_6 -> V_18 ) ;
if ( V_59 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_59 ;
}
}
V_18 [ 1 ] &= ~ V_21 ;
V_59 = F_8 ( V_6 -> V_4 , V_11 , V_18 [ 1 ] ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_17 ( V_6 -> V_4 , V_56 ,
3 , V_55 ) ;
if ( V_59 )
return V_59 ;
if ( V_54 -> V_57 ) {
if ( V_6 -> V_27 -> V_61 . V_57 )
V_6 -> V_18 |= V_25 ;
if ( V_6 -> V_27 -> V_62 . V_57 )
V_6 -> V_18 |= V_22 ;
V_59 = F_8 ( V_6 -> V_4 , V_28 ,
V_6 -> V_18 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static int F_23 ( struct V_30 * V_15 , unsigned int V_57 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
int V_18 , V_8 , V_59 ;
V_18 = V_6 -> V_18 ;
if ( V_57 ) {
if ( V_6 -> V_27 -> V_61 . V_57 )
V_18 |= V_25 ;
if ( V_6 -> V_27 -> V_62 . V_57 )
V_18 |= V_22 ;
} else {
if ( ! V_6 -> V_27 -> V_61 . V_57 )
V_18 &= ~ V_25 ;
if ( ! V_6 -> V_27 -> V_62 . V_57 )
V_18 &= ~ V_22 ;
}
F_3 ( & V_6 -> V_10 ) ;
V_8 = F_4 ( V_4 , V_11 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_8 ;
}
V_8 &= ~ ( V_21 | V_24 ) ;
V_59 = F_8 ( V_4 , V_11 , V_8 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( V_59 )
return V_59 ;
if ( V_18 != V_6 -> V_18 ) {
V_6 -> V_18 = V_18 ;
V_59 = F_8 ( V_4 , V_28 ,
V_6 -> V_18 ) ;
if ( V_59 )
return V_59 ;
}
return 0 ;
}
static int F_24 ( struct V_30 * V_15 , unsigned int V_63 , unsigned long V_64 )
{
struct V_3 * V_4 = F_20 ( V_15 ) ;
struct V_5 * V_6 = F_10 ( V_15 ) ;
int V_8 , V_36 = 0 ;
switch ( V_63 ) {
case V_65 :
V_8 = F_4 ( V_4 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_15 , L_1 ) ;
if ( V_8 & V_16 )
F_6 ( & V_4 -> V_15 , L_2 ) ;
V_8 &= V_14 | V_16 ;
if ( F_25 ( ( void V_66 * ) V_64 , & V_8 , sizeof( int ) ) )
return - V_67 ;
return 0 ;
case V_68 :
F_3 ( & V_6 -> V_10 ) ;
V_8 = F_4 ( V_4 , V_11 ) ;
if ( V_8 < 0 ) {
F_5 ( & V_6 -> V_10 ) ;
return V_8 ;
}
V_8 &= ~ ( V_14 | V_16 ) ;
V_36 = F_8 ( V_4 , V_11 , V_8 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( V_36 < 0 )
return V_36 ;
return 0 ;
default:
return - V_69 ;
}
}
static T_4 F_26 ( struct V_70 * V_71 , struct V_72 * V_73 ,
struct V_74 * V_75 ,
char * V_76 , T_5 V_77 , T_6 V_78 )
{
struct V_30 * V_15 = F_27 ( V_73 ) ;
struct V_3 * V_4 = F_20 ( V_15 ) ;
int V_36 ;
V_36 = F_8 ( V_4 , V_79 , V_76 [ 0 ] ) ;
if ( V_36 < 0 )
return V_36 ;
return 1 ;
}
static T_4 F_28 ( struct V_70 * V_71 , struct V_72 * V_73 ,
struct V_74 * V_75 ,
char * V_76 , T_5 V_77 , T_6 V_78 )
{
struct V_30 * V_15 = F_27 ( V_73 ) ;
struct V_3 * V_4 = F_20 ( V_15 ) ;
int V_36 ;
V_36 = F_4 ( V_4 , V_79 ) ;
if ( V_36 < 0 )
return V_36 ;
V_76 [ 0 ] = V_36 ;
return 1 ;
}
static int F_29 ( struct V_3 * V_4 ,
const struct V_80 * V_81 )
{
struct V_82 * V_83 = F_30 ( V_4 -> V_15 . V_84 ) ;
struct V_5 * V_6 ;
int V_59 , V_8 , V_9 = 0 ;
if ( ! F_31 ( V_83 , V_85 |
V_86 ) ) {
F_32 ( & V_83 -> V_15 , L_4 ) ;
return - V_39 ;
}
V_6 = F_33 ( & V_4 -> V_15 , sizeof( struct V_5 ) ,
V_87 ) ;
if ( ! V_6 )
return - V_88 ;
F_34 ( & V_6 -> V_10 ) ;
V_6 -> V_4 = V_4 ;
F_35 ( V_4 , V_6 ) ;
do {
V_8 = F_4 ( V_4 , V_11 ) ;
V_9 ++ ;
} while ( ( V_8 == - V_12 ) && ( V_9 < 3 ) );
if ( V_8 < 0 )
return V_8 ;
if ( V_8 & V_14 )
F_6 ( & V_4 -> V_15 , L_1 ) ;
if ( V_8 & V_16 )
F_6 ( & V_4 -> V_15 , L_2 ) ;
if ( V_8 & V_21 )
F_6 ( & V_4 -> V_15 , L_5 ) ;
if ( V_4 -> V_1 > 0 ) {
V_59 = F_36 ( & V_4 -> V_15 , V_4 -> V_1 ,
NULL , F_1 ,
V_89 | V_90 ,
L_6 , V_4 ) ;
if ( V_59 ) {
F_6 ( & V_4 -> V_15 , L_7 ) ;
V_4 -> V_1 = 0 ;
} else {
V_91 . V_92 = F_18 ;
V_91 . V_93 = F_19 ;
V_91 . V_94 = F_23 ;
}
}
V_6 -> V_27 = F_37 ( & V_4 -> V_15 , V_4 -> V_95 ,
& V_91 , V_96 ) ;
if ( F_38 ( V_6 -> V_27 ) ) {
F_32 ( & V_4 -> V_15 , L_8 ) ;
return F_39 ( V_6 -> V_27 ) ;
}
V_9 = 0 ;
do {
V_59 = F_8 ( V_6 -> V_4 , V_97 ,
V_98 ) ;
V_9 ++ ;
} while ( ( V_59 == - V_12 ) && ( V_9 < 3 ) );
if ( V_59 )
return V_59 ;
V_59 = F_40 ( & V_4 -> V_15 , & V_99 ) ;
if ( V_59 )
return V_59 ;
V_6 -> V_27 -> V_100 = 1 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_15 , & V_99 ) ;
return 0 ;
}
