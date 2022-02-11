static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_4 ( V_4 , V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
return F_8 ( V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static inline T_1 F_9 ( struct V_1 * V_2 , int V_3 )
{
return F_10 ( V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static inline T_1 F_11 ( struct V_1 * V_2 , int V_3 )
{
return F_12 ( V_2 -> V_5 + ( V_3 << V_2 -> V_6 ) ) ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
V_2 -> V_7 ( V_2 , V_3 , V_4 ) ;
}
static inline T_1 F_14 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_8 ( V_2 , V_3 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
T_1 V_11 = F_14 ( V_2 , V_12 ) ;
if ( ( V_2 -> V_13 == V_14 ) || ( V_2 -> V_13 == V_15 ) ) {
F_13 ( V_2 , V_16 , V_17 ) ;
F_16 ( & V_2 -> V_18 ) ;
return;
}
if ( V_11 & V_19 ) {
V_2 -> V_13 = V_15 ;
F_13 ( V_2 , V_16 , V_20 ) ;
return;
}
if ( ( V_2 -> V_13 == V_21 ) || ( V_2 -> V_13 == V_22 ) ) {
V_2 -> V_13 =
( V_10 -> V_23 & V_24 ) ? V_25 : V_22 ;
if ( V_11 & V_26 ) {
V_2 -> V_13 = V_15 ;
F_13 ( V_2 , V_16 , V_20 ) ;
return;
}
} else
V_10 -> V_27 [ V_2 -> V_28 ++ ] = F_14 ( V_2 , V_29 ) ;
if ( V_2 -> V_28 == V_10 -> V_30 ) {
V_2 -> V_31 -- ;
V_2 -> V_10 ++ ;
V_2 -> V_28 = 0 ;
V_10 = V_2 -> V_10 ;
if ( V_2 -> V_31 ) {
if ( ! ( V_10 -> V_23 & V_32 ) ) {
T_1 V_33 = ( V_10 -> V_33 << 1 ) ;
if ( V_10 -> V_23 & V_24 )
V_33 |= 1 ;
V_2 -> V_13 = V_21 ;
F_13 ( V_2 , V_29 , V_33 ) ;
F_13 ( V_2 , V_16 , V_34 ) ;
return;
} else
V_2 -> V_13 = ( V_10 -> V_23 & V_24 )
? V_25 : V_22 ;
} else {
V_2 -> V_13 = V_14 ;
F_13 ( V_2 , V_16 , V_20 ) ;
return;
}
}
if ( V_2 -> V_13 == V_25 ) {
F_13 ( V_2 , V_16 , V_2 -> V_28 == ( V_10 -> V_30 - 1 ) ?
V_35 : V_36 ) ;
} else {
F_13 ( V_2 , V_29 , V_10 -> V_27 [ V_2 -> V_28 ++ ] ) ;
F_13 ( V_2 , V_16 , V_37 ) ;
}
}
static T_2 F_17 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
F_15 ( V_2 ) ;
return V_40 ;
}
static int F_18 ( struct V_41 * V_42 , struct V_9 * V_43 , int V_44 )
{
struct V_1 * V_2 = F_19 ( V_42 ) ;
V_2 -> V_10 = V_43 ;
V_2 -> V_28 = 0 ;
V_2 -> V_31 = V_44 ;
V_2 -> V_13 = V_21 ;
F_13 ( V_2 , V_29 ,
( V_2 -> V_10 -> V_33 << 1 ) |
( ( V_2 -> V_10 -> V_23 & V_24 ) ? 1 : 0 ) ) ;
F_13 ( V_2 , V_16 , V_34 ) ;
if ( F_20 ( V_2 -> V_18 , ( V_2 -> V_13 == V_15 ) ||
( V_2 -> V_13 == V_14 ) , V_45 ) )
return ( V_2 -> V_13 == V_14 ) ? V_44 : - V_46 ;
else
return - V_47 ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_48 ;
T_1 V_49 = F_14 ( V_2 , V_50 ) ;
F_13 ( V_2 , V_50 , V_49 & ~ ( V_51 | V_52 ) ) ;
V_48 = ( V_2 -> V_53 / ( 5 * 100 ) ) - 1 ;
F_13 ( V_2 , V_54 , V_48 & 0xff ) ;
F_13 ( V_2 , V_55 , V_48 >> 8 ) ;
F_13 ( V_2 , V_16 , V_17 ) ;
F_13 ( V_2 , V_50 , V_49 | V_52 | V_51 ) ;
}
static T_3 F_22 ( struct V_41 * V_42 )
{
return V_56 | V_57 ;
}
static T_1 F_23 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_58 ;
int V_59 = V_3 ;
if ( V_3 != V_54 )
V_59 -- ;
V_58 = F_24 ( V_2 -> V_5 + ( V_59 << V_2 -> V_6 ) ) ;
if ( V_3 == V_55 )
return ( T_1 ) ( V_58 >> 8 ) ;
else
return ( T_1 ) V_58 ;
}
static void F_25 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_3 V_60 , V_61 ;
int V_59 = V_3 ;
if ( V_3 != V_54 )
V_59 -- ;
if ( V_3 == V_54 || V_3 == V_55 ) {
V_60 = F_24 ( V_2 -> V_5 + ( V_59 << V_2 -> V_6 ) ) ;
if ( V_3 == V_54 )
V_61 = ( V_60 & 0xff00 ) | V_4 ;
else
V_61 = ( ( ( T_3 ) V_4 ) << 8 ) | ( V_60 & 0xff ) ;
} else {
V_61 = V_4 ;
}
F_26 ( V_61 , V_2 -> V_5 + ( V_59 << V_2 -> V_6 ) ) ;
}
static int F_27 ( struct V_62 * V_63 ,
struct V_1 * V_2 )
{
struct V_64 * V_65 = V_63 -> V_66 . V_67 ;
const struct V_68 * V_69 ;
T_3 V_70 ;
if ( F_28 ( V_65 , L_1 , & V_2 -> V_6 ) ) {
if ( ! F_28 ( V_65 , L_2 , & V_70 ) ) {
if ( ! F_29 ( V_70 ) ) {
F_30 ( & V_63 -> V_66 , L_3 ,
V_70 ) ;
return - V_71 ;
}
V_2 -> V_6 = F_31 ( V_70 ) ;
F_32 ( & V_63 -> V_66 ,
L_4 ) ;
}
}
if ( F_28 ( V_65 , L_5 , & V_70 ) ) {
F_30 ( & V_63 -> V_66 ,
L_6 ) ;
return - V_72 ;
}
V_2 -> V_53 = V_70 / 1000 ;
F_28 ( V_63 -> V_66 . V_67 , L_7 ,
& V_2 -> V_73 ) ;
V_69 = F_33 ( V_74 , V_63 -> V_66 . V_67 ) ;
if ( V_69 && ( long ) V_69 -> V_75 == V_76 ) {
F_34 ( & V_63 -> V_66 , L_8 ) ;
V_2 -> V_7 = F_25 ;
V_2 -> V_8 = F_23 ;
}
return 0 ;
}
static int F_35 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
int V_38 ;
int V_81 ;
int V_82 ;
V_80 = F_36 ( V_63 , V_83 , 0 ) ;
if ( ! V_80 )
return - V_72 ;
V_38 = F_37 ( V_63 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 = F_38 ( & V_63 -> V_66 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_5 = F_39 ( & V_63 -> V_66 , V_80 ) ;
if ( F_40 ( V_2 -> V_5 ) )
return F_41 ( V_2 -> V_5 ) ;
V_78 = V_63 -> V_66 . V_86 ;
if ( V_78 ) {
V_2 -> V_6 = V_78 -> V_6 ;
V_2 -> V_73 = V_78 -> V_73 ;
V_2 -> V_53 = V_78 -> V_53 ;
} else {
V_81 = F_27 ( V_63 , V_2 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_2 -> V_73 == 0 )
V_2 -> V_73 = 1 ;
if ( ! V_2 -> V_7 || ! V_2 -> V_8 ) {
switch ( V_2 -> V_73 ) {
case 1 :
V_2 -> V_7 = F_1 ;
V_2 -> V_8 = F_7 ;
break;
case 2 :
V_2 -> V_7 = F_3 ;
V_2 -> V_8 = F_9 ;
break;
case 4 :
V_2 -> V_7 = F_5 ;
V_2 -> V_8 = F_11 ;
break;
default:
F_30 ( & V_63 -> V_66 , L_9 ,
V_2 -> V_73 ) ;
return - V_71 ;
}
}
F_21 ( V_2 ) ;
F_42 ( & V_2 -> V_18 ) ;
V_81 = F_43 ( & V_63 -> V_66 , V_38 , F_17 , 0 ,
V_63 -> V_87 , V_2 ) ;
if ( V_81 ) {
F_30 ( & V_63 -> V_66 , L_10 ) ;
return V_81 ;
}
F_44 ( V_63 , V_2 ) ;
V_2 -> V_42 = V_88 ;
F_45 ( & V_2 -> V_42 , V_2 ) ;
V_2 -> V_42 . V_66 . V_89 = & V_63 -> V_66 ;
V_2 -> V_42 . V_66 . V_67 = V_63 -> V_66 . V_67 ;
V_81 = F_46 ( & V_2 -> V_42 ) ;
if ( V_81 ) {
F_30 ( & V_63 -> V_66 , L_11 ) ;
return V_81 ;
}
if ( V_78 ) {
for ( V_82 = 0 ; V_82 < V_78 -> V_90 ; V_82 ++ )
F_47 ( & V_2 -> V_42 , V_78 -> V_91 + V_82 ) ;
} else {
F_48 ( & V_2 -> V_42 ) ;
}
return 0 ;
}
static int F_49 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_50 ( V_63 ) ;
F_13 ( V_2 , V_50 , F_14 ( V_2 , V_50 )
& ~ ( V_51 | V_52 ) ) ;
F_51 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_52 ( struct V_92 * V_66 )
{
struct V_1 * V_2 = F_53 ( V_66 ) ;
T_1 V_49 = F_14 ( V_2 , V_50 ) ;
F_13 ( V_2 , V_50 , V_49 & ~ ( V_51 | V_52 ) ) ;
return 0 ;
}
static int F_54 ( struct V_92 * V_66 )
{
struct V_1 * V_2 = F_53 ( V_66 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
