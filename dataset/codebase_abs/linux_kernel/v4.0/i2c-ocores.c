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
static int F_21 ( struct V_48 * V_49 , struct V_1 * V_2 )
{
int V_50 ;
int V_51 ;
T_1 V_52 = F_14 ( V_2 , V_53 ) ;
F_13 ( V_2 , V_53 , V_52 & ~ ( V_54 | V_55 ) ) ;
V_50 = ( V_2 -> V_56 / ( 5 * V_2 -> V_57 ) ) - 1 ;
V_50 = F_22 ( V_50 , 0 , 0xffff ) ;
V_51 = V_2 -> V_56 / ( 5 * ( V_50 + 1 ) ) - V_2 -> V_57 ;
if ( abs ( V_51 ) > V_2 -> V_57 / 10 ) {
F_23 ( V_49 ,
L_1 ,
V_2 -> V_56 , V_2 -> V_57 ) ;
return - V_58 ;
}
F_13 ( V_2 , V_59 , V_50 & 0xff ) ;
F_13 ( V_2 , V_60 , V_50 >> 8 ) ;
F_13 ( V_2 , V_16 , V_17 ) ;
F_13 ( V_2 , V_53 , V_52 | V_55 | V_54 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_41 * V_42 )
{
return V_61 | V_62 ;
}
static T_1 F_25 ( struct V_1 * V_2 , int V_3 )
{
T_3 V_63 ;
int V_64 = V_3 ;
if ( V_3 != V_59 )
V_64 -- ;
V_63 = F_26 ( V_2 -> V_5 + ( V_64 << V_2 -> V_6 ) ) ;
if ( V_3 == V_60 )
return ( T_1 ) ( V_63 >> 8 ) ;
else
return ( T_1 ) V_63 ;
}
static void F_27 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
T_3 V_65 , V_66 ;
int V_64 = V_3 ;
if ( V_3 != V_59 )
V_64 -- ;
if ( V_3 == V_59 || V_3 == V_60 ) {
V_65 = F_26 ( V_2 -> V_5 + ( V_64 << V_2 -> V_6 ) ) ;
if ( V_3 == V_59 )
V_66 = ( V_65 & 0xff00 ) | V_4 ;
else
V_66 = ( ( ( T_3 ) V_4 ) << 8 ) | ( V_65 & 0xff ) ;
} else {
V_66 = V_4 ;
}
F_28 ( V_66 , V_2 -> V_5 + ( V_64 << V_2 -> V_6 ) ) ;
}
static int F_29 ( struct V_67 * V_68 ,
struct V_1 * V_2 )
{
struct V_69 * V_70 = V_68 -> V_49 . V_71 ;
const struct V_72 * V_73 ;
T_3 V_74 ;
T_3 V_75 ;
bool V_76 ;
if ( F_30 ( V_70 , L_2 , & V_2 -> V_6 ) ) {
if ( ! F_30 ( V_70 , L_3 , & V_74 ) ) {
if ( ! F_31 ( V_74 ) ) {
F_23 ( & V_68 -> V_49 , L_4 ,
V_74 ) ;
return - V_58 ;
}
V_2 -> V_6 = F_32 ( V_74 ) ;
F_33 ( & V_68 -> V_49 ,
L_5 ) ;
}
}
V_76 = ! F_30 ( V_70 , L_6 ,
& V_75 ) ;
V_2 -> V_57 = 100 ;
V_2 -> V_77 = F_34 ( & V_68 -> V_49 , NULL ) ;
if ( ! F_35 ( V_2 -> V_77 ) ) {
int V_78 = F_36 ( V_2 -> V_77 ) ;
if ( V_78 ) {
F_23 ( & V_68 -> V_49 ,
L_7 , V_78 ) ;
return V_78 ;
}
V_2 -> V_56 = F_37 ( V_2 -> V_77 ) / 1000 ;
if ( V_76 )
V_2 -> V_57 = V_75 / 1000 ;
}
if ( V_2 -> V_56 == 0 ) {
if ( F_30 ( V_70 , L_8 ,
& V_74 ) ) {
if ( ! V_76 ) {
F_23 ( & V_68 -> V_49 ,
L_9 ) ;
return - V_79 ;
}
V_2 -> V_56 = V_75 / 1000 ;
F_33 ( & V_68 -> V_49 ,
L_10 ) ;
} else {
V_2 -> V_56 = V_74 / 1000 ;
if ( V_76 )
V_2 -> V_57 = V_75 / 1000 ;
}
}
F_30 ( V_68 -> V_49 . V_71 , L_11 ,
& V_2 -> V_80 ) ;
V_73 = F_38 ( V_81 , V_68 -> V_49 . V_71 ) ;
if ( V_73 && ( long ) V_73 -> V_82 == V_83 ) {
F_39 ( & V_68 -> V_49 , L_12 ) ;
V_2 -> V_7 = F_27 ;
V_2 -> V_8 = F_25 ;
}
return 0 ;
}
static int F_40 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
int V_38 ;
int V_78 ;
int V_88 ;
V_38 = F_41 ( V_68 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_2 = F_42 ( & V_68 -> V_49 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
V_87 = F_43 ( V_68 , V_91 , 0 ) ;
V_2 -> V_5 = F_44 ( & V_68 -> V_49 , V_87 ) ;
if ( F_35 ( V_2 -> V_5 ) )
return F_45 ( V_2 -> V_5 ) ;
V_85 = F_46 ( & V_68 -> V_49 ) ;
if ( V_85 ) {
V_2 -> V_6 = V_85 -> V_6 ;
V_2 -> V_80 = V_85 -> V_80 ;
V_2 -> V_56 = V_85 -> V_92 ;
V_2 -> V_57 = 100 ;
} else {
V_78 = F_29 ( V_68 , V_2 ) ;
if ( V_78 )
return V_78 ;
}
if ( V_2 -> V_80 == 0 )
V_2 -> V_80 = 1 ;
if ( ! V_2 -> V_7 || ! V_2 -> V_8 ) {
switch ( V_2 -> V_80 ) {
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
F_23 ( & V_68 -> V_49 , L_13 ,
V_2 -> V_80 ) ;
return - V_58 ;
}
}
V_78 = F_21 ( & V_68 -> V_49 , V_2 ) ;
if ( V_78 )
return V_78 ;
F_47 ( & V_2 -> V_18 ) ;
V_78 = F_48 ( & V_68 -> V_49 , V_38 , F_17 , 0 ,
V_68 -> V_93 , V_2 ) ;
if ( V_78 ) {
F_23 ( & V_68 -> V_49 , L_14 ) ;
return V_78 ;
}
F_49 ( V_68 , V_2 ) ;
V_2 -> V_42 = V_94 ;
F_50 ( & V_2 -> V_42 , V_2 ) ;
V_2 -> V_42 . V_49 . V_95 = & V_68 -> V_49 ;
V_2 -> V_42 . V_49 . V_71 = V_68 -> V_49 . V_71 ;
V_78 = F_51 ( & V_2 -> V_42 ) ;
if ( V_78 ) {
F_23 ( & V_68 -> V_49 , L_15 ) ;
return V_78 ;
}
if ( V_85 ) {
for ( V_88 = 0 ; V_88 < V_85 -> V_96 ; V_88 ++ )
F_52 ( & V_2 -> V_42 , V_85 -> V_97 + V_88 ) ;
}
return 0 ;
}
static int F_53 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = F_54 ( V_68 ) ;
F_13 ( V_2 , V_53 , F_14 ( V_2 , V_53 )
& ~ ( V_54 | V_55 ) ) ;
F_55 ( & V_2 -> V_42 ) ;
if ( ! F_35 ( V_2 -> V_77 ) )
F_56 ( V_2 -> V_77 ) ;
return 0 ;
}
static int F_57 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_58 ( V_49 ) ;
T_1 V_52 = F_14 ( V_2 , V_53 ) ;
F_13 ( V_2 , V_53 , V_52 & ~ ( V_54 | V_55 ) ) ;
if ( ! F_35 ( V_2 -> V_77 ) )
F_56 ( V_2 -> V_77 ) ;
return 0 ;
}
static int F_59 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_58 ( V_49 ) ;
if ( ! F_35 ( V_2 -> V_77 ) ) {
unsigned long V_98 ;
int V_78 = F_36 ( V_2 -> V_77 ) ;
if ( V_78 ) {
F_23 ( V_49 ,
L_7 , V_78 ) ;
return V_78 ;
}
V_98 = F_37 ( V_2 -> V_77 ) / 1000 ;
if ( V_98 )
V_2 -> V_56 = V_98 ;
}
return F_21 ( V_49 , V_2 ) ;
}
