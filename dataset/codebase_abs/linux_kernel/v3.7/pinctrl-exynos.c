static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 = V_4 -> V_10 -> V_11 + V_8 -> V_12 ;
unsigned long V_13 ;
V_13 = F_3 ( V_4 -> V_14 + V_9 ) ;
V_13 &= ~ ( 1 << V_8 -> V_15 ) ;
F_4 ( V_13 , V_4 -> V_14 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_9 = V_4 -> V_10 -> V_11 + V_8 -> V_12 ;
unsigned long V_13 ;
V_13 = F_3 ( V_4 -> V_14 + V_9 ) ;
V_13 |= 1 << V_8 -> V_15 ;
F_4 ( V_13 , V_4 -> V_14 + V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long V_16 = V_4 -> V_10 -> V_17 + V_8 -> V_12 ;
F_4 ( 1 << V_8 -> V_15 , V_4 -> V_14 + V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_18 * V_10 = V_4 -> V_10 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_8 -> V_20 ;
unsigned int V_21 = V_22 * V_8 -> V_15 ;
unsigned int V_23 , V_24 ;
unsigned long V_25 = V_10 -> V_26 + V_8 -> V_12 ;
unsigned int V_13 ;
switch ( type ) {
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
V_24 = V_30 ;
break;
case V_31 :
V_24 = V_32 ;
break;
case V_33 :
V_24 = V_34 ;
break;
case V_35 :
V_24 = V_36 ;
break;
default:
F_8 ( L_1 ) ;
return - V_37 ;
}
if ( type & V_31 )
F_9 ( V_2 -> V_38 , V_39 ) ;
else
F_9 ( V_2 -> V_38 , V_40 ) ;
V_23 = F_3 ( V_4 -> V_14 + V_25 ) ;
V_23 &= ~ ( V_41 << V_21 ) ;
V_23 |= V_24 << V_21 ;
F_4 ( V_23 , V_4 -> V_14 + V_25 ) ;
V_25 = V_20 -> V_42 ;
V_21 = V_8 -> V_15 * V_20 -> V_43 ;
V_13 = ( 1 << V_20 -> V_43 ) - 1 ;
V_23 = F_3 ( V_4 -> V_14 + V_25 ) ;
V_23 &= ~ ( V_13 << V_21 ) ;
V_23 |= V_44 << V_21 ;
F_4 ( V_23 , V_4 -> V_14 + V_25 ) ;
return 0 ;
}
static struct V_7 * F_10 ( T_1 V_45 ,
struct V_3 * V_4 )
{
struct V_19 * V_20 = V_4 -> V_10 -> V_46 ;
struct V_7 * V_47 ;
unsigned int V_48 = V_4 -> V_10 -> V_48 , V_49 ;
unsigned int V_50 = 0 , V_12 = 0 ;
if ( V_45 >= V_4 -> V_10 -> V_51 ) {
F_11 ( V_4 -> V_52 , L_2 ) ;
return NULL ;
}
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ , V_20 ++ ) {
if ( V_20 -> V_53 != V_54 )
continue;
if ( ( V_45 >= V_50 ) && ( V_45 < ( V_50 + V_20 -> V_55 ) ) )
break;
V_50 += V_20 -> V_55 ;
V_12 += 4 ;
}
if ( V_49 == V_48 ) {
F_11 ( V_4 -> V_52 , L_3 ) ;
return NULL ;
}
V_47 = F_12 ( V_4 -> V_52 , sizeof( * V_47 ) , V_56 ) ;
if ( ! V_47 ) {
F_11 ( V_4 -> V_52 , L_4 ) ;
return NULL ;
}
V_47 -> V_20 = V_20 ;
V_47 -> V_15 = V_45 - V_50 ;
V_47 -> V_12 = V_12 ;
return V_47 ;
}
static int F_13 ( struct V_57 * V_58 , unsigned int V_59 ,
T_1 V_45 )
{
struct V_3 * V_4 = V_58 -> V_6 ;
struct V_7 * V_47 ;
V_47 = F_10 ( V_45 , V_4 ) ;
if ( ! V_47 )
return - V_37 ;
F_14 ( V_59 , V_47 ) ;
F_15 ( V_59 , V_58 -> V_6 ) ;
F_16 ( V_59 , & V_60 ,
V_40 ) ;
F_17 ( V_59 , V_61 ) ;
return 0 ;
}
static void F_18 ( struct V_57 * V_58 , unsigned int V_59 )
{
struct V_3 * V_4 = V_58 -> V_6 ;
struct V_7 * V_47 ;
V_47 = F_19 ( V_59 ) ;
F_20 ( V_4 -> V_52 , V_47 ) ;
}
static T_2 F_21 ( int V_38 , void * V_62 )
{
struct V_3 * V_4 = V_62 ;
struct V_18 * V_10 = V_4 -> V_10 ;
struct V_19 * V_20 = V_10 -> V_46 ;
unsigned int V_63 , V_64 , V_15 , V_59 ;
V_63 = F_3 ( V_4 -> V_14 + V_10 -> V_63 ) ;
V_64 = F_22 ( V_63 ) ;
V_15 = V_63 & V_65 ;
if ( ! V_64 )
return V_66 ;
V_20 += ( V_64 - 1 ) ;
V_59 = F_23 ( V_4 -> V_67 , V_20 -> V_50 + V_15 ) ;
if ( ! V_59 )
return V_68 ;
F_24 ( V_59 ) ;
return V_66 ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_69 * V_52 = V_4 -> V_52 ;
unsigned int V_70 ;
if ( ! V_4 -> V_38 ) {
F_11 ( V_52 , L_5 ) ;
return - V_37 ;
}
V_70 = F_26 ( V_52 , V_4 -> V_38 , F_21 ,
0 , F_27 ( V_52 ) , V_4 ) ;
if ( V_70 ) {
F_11 ( V_52 , L_6 ) ;
return - V_71 ;
}
V_4 -> V_67 = F_28 ( V_52 -> V_72 , V_4 -> V_10 -> V_51 ,
& V_73 , V_4 ) ;
if ( ! V_4 -> V_67 ) {
F_11 ( V_52 , L_7 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_30 ( V_2 ) ;
unsigned int V_20 = V_2 -> V_74 / V_75 ;
unsigned int V_15 = V_2 -> V_74 & ( V_75 - 1 ) ;
unsigned long V_9 = V_4 -> V_10 -> V_76 + ( V_20 << 2 ) ;
unsigned long V_13 ;
V_13 = F_3 ( V_4 -> V_14 + V_9 ) ;
V_13 &= ~ ( 1 << V_15 ) ;
F_4 ( V_13 , V_4 -> V_14 + V_9 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_30 ( V_2 ) ;
unsigned int V_20 = V_2 -> V_74 / V_75 ;
unsigned int V_15 = V_2 -> V_74 & ( V_75 - 1 ) ;
unsigned long V_9 = V_4 -> V_10 -> V_76 + ( V_20 << 2 ) ;
unsigned long V_13 ;
V_13 = F_3 ( V_4 -> V_14 + V_9 ) ;
V_13 |= 1 << V_15 ;
F_4 ( V_13 , V_4 -> V_14 + V_9 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_30 ( V_2 ) ;
unsigned int V_20 = V_2 -> V_74 / V_75 ;
unsigned int V_15 = V_2 -> V_74 & ( V_75 - 1 ) ;
unsigned long V_77 = V_4 -> V_10 -> V_78 + ( V_20 << 2 ) ;
F_4 ( 1 << V_15 , V_4 -> V_14 + V_77 ) ;
}
static int F_33 ( struct V_1 * V_2 , unsigned int type )
{
struct V_3 * V_4 = F_30 ( V_2 ) ;
unsigned int V_20 = V_2 -> V_74 / V_75 ;
unsigned int V_15 = V_2 -> V_74 & ( V_75 - 1 ) ;
unsigned long V_25 = V_4 -> V_10 -> V_79 + ( V_20 << 2 ) ;
unsigned long V_21 = V_22 * V_15 ;
unsigned long V_23 , V_24 ;
switch ( type ) {
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
V_24 = V_30 ;
break;
case V_31 :
V_24 = V_32 ;
break;
case V_33 :
V_24 = V_34 ;
break;
case V_35 :
V_24 = V_36 ;
break;
default:
F_8 ( L_1 ) ;
return - V_37 ;
}
if ( type & V_31 )
F_9 ( V_2 -> V_38 , V_39 ) ;
else
F_9 ( V_2 -> V_38 , V_40 ) ;
V_23 = F_3 ( V_4 -> V_14 + V_25 ) ;
V_23 &= ~ ( V_41 << V_21 ) ;
V_23 |= V_24 << V_21 ;
F_4 ( V_23 , V_4 -> V_14 + V_25 ) ;
return 0 ;
}
static void F_34 ( unsigned int V_38 , struct V_80 * V_81 )
{
struct V_82 * V_83 = F_19 ( V_38 ) ;
struct V_84 * V_85 = F_35 ( V_38 ) ;
int V_86 ;
F_36 ( V_85 , V_81 ) ;
V_85 -> V_87 ( & V_81 -> V_1 ) ;
if ( V_85 -> V_88 )
V_85 -> V_88 ( & V_81 -> V_1 ) ;
V_86 = F_23 ( V_83 -> V_5 , V_83 -> V_38 ) ;
F_24 ( V_86 ) ;
V_85 -> V_89 ( & V_81 -> V_1 ) ;
F_37 ( V_85 , V_81 ) ;
}
static inline void F_38 ( int V_50 , unsigned long V_77 ,
struct V_57 * V_5 )
{
unsigned int V_38 ;
while ( V_77 ) {
V_38 = F_39 ( V_77 ) - 1 ;
F_24 ( F_40 ( V_5 , V_50 + V_38 ) ) ;
V_77 &= ~ ( 1 << V_38 ) ;
}
}
static void F_41 ( unsigned int V_38 , struct V_80 * V_81 )
{
struct V_84 * V_85 = F_35 ( V_38 ) ;
struct V_82 * V_83 = F_19 ( V_38 ) ;
struct V_3 * V_4 = V_83 -> V_5 -> V_6 ;
unsigned long V_77 ;
unsigned long V_13 ;
F_36 ( V_85 , V_81 ) ;
V_77 = F_3 ( V_4 -> V_14 + V_4 -> V_10 -> V_78 + 0x8 ) ;
V_13 = F_3 ( V_4 -> V_14 + V_4 -> V_10 -> V_76 + 0x8 ) ;
F_38 ( 16 , V_77 & ~ V_13 , V_83 -> V_5 ) ;
V_77 = F_3 ( V_4 -> V_14 + V_4 -> V_10 -> V_78 + 0xC ) ;
V_13 = F_3 ( V_4 -> V_14 + V_4 -> V_10 -> V_76 + 0xC ) ;
F_38 ( 24 , V_77 & ~ V_13 , V_83 -> V_5 ) ;
F_37 ( V_85 , V_81 ) ;
}
static int F_42 ( struct V_57 * V_58 , unsigned int V_59 ,
T_1 V_45 )
{
F_16 ( V_59 , & V_90 , V_40 ) ;
F_15 ( V_59 , V_58 -> V_6 ) ;
F_17 ( V_59 , V_61 ) ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_69 * V_52 = V_4 -> V_52 ;
struct V_91 * V_92 = NULL ;
struct V_91 * V_93 ;
struct V_82 * V_94 ;
int V_49 , V_38 ;
F_44 (dev->of_node, np) {
if ( F_45 ( V_95 , V_93 ) ) {
V_92 = V_93 ;
break;
}
}
if ( ! V_92 )
return - V_96 ;
V_4 -> V_97 = F_28 ( V_92 , V_4 -> V_10 -> V_98 ,
& V_99 , V_4 ) ;
if ( ! V_4 -> V_97 ) {
F_11 ( V_52 , L_8 ) ;
return - V_71 ;
}
V_94 = F_12 ( V_52 , sizeof( * V_94 ) * 17 , V_56 ) ;
if ( ! V_94 ) {
F_11 ( V_52 , L_9 ) ;
return - V_100 ;
}
V_38 = F_46 ( V_92 , 16 ) ;
if ( V_38 ) {
V_94 [ 16 ] . V_5 = V_4 -> V_97 ;
F_47 ( V_38 , F_41 ) ;
F_14 ( V_38 , & V_94 [ 16 ] ) ;
} else {
F_11 ( V_52 , L_10 ) ;
}
for ( V_49 = 0 ; V_49 < 16 ; V_49 ++ ) {
V_94 [ V_49 ] . V_5 = V_4 -> V_97 ;
V_94 [ V_49 ] . V_38 = V_49 ;
V_38 = F_46 ( V_92 , V_49 ) ;
if ( V_38 ) {
F_14 ( V_38 , & V_94 [ V_49 ] ) ;
F_47 ( V_38 , F_34 ) ;
} else {
F_11 ( V_52 , L_11 , V_49 ) ;
}
}
return 0 ;
}
