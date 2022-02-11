static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
if ( V_2 -> V_6 -> V_7 )
return V_2 -> V_6 -> V_7 ( V_2 , V_3 ) ;
V_2 -> V_6 -> V_8 ( V_2 , 1 ) ;
F_2 ( 16 ) ;
for ( V_4 = 25 ; V_4 > 0 ; V_4 -- ) {
V_5 = ( V_3 >> 24 ) & V_9 ;
V_3 <<= 1 ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 | V_12 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_10 ( V_2 , V_5 | V_11 ) ;
F_2 ( 2 ) ;
}
if ( ! V_2 -> V_13 )
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
}
static T_3 F_3 ( struct V_1 * V_2 )
{
T_1 V_4 , V_14 ;
T_3 V_5 = 0 ;
if ( V_2 -> V_6 -> V_15 )
return V_2 -> V_6 -> V_15 ( V_2 ) ;
V_2 -> V_6 -> V_8 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
F_2 ( 16 ) ;
for ( V_4 = 24 ; V_4 -- ; ) {
V_2 -> V_6 -> V_10 ( V_2 , V_12 ) ;
F_2 ( 2 ) ;
if ( ! V_4 )
V_2 -> V_16 = V_2 -> V_6 -> V_17 ( V_2 ) & V_18 ? 0 : 1 ;
V_2 -> V_6 -> V_10 ( V_2 , 0 ) ;
F_2 ( 2 ) ;
V_5 <<= 1 ;
V_14 = V_2 -> V_6 -> V_17 ( V_2 ) ;
if ( ! V_4 )
V_2 -> V_19 = ( V_14 & V_18 ) ? 0 : 1 ;
if ( V_14 & V_9 )
V_5 ++ ;
F_2 ( 2 ) ;
}
if ( V_2 -> V_13 )
V_2 -> V_6 -> V_10 ( V_2 , V_11 ) ;
return V_5 ;
}
static T_3 F_4 ( struct V_1 * V_2 , T_3 V_3 )
{
T_3 V_20 = V_3 & V_21 ;
if ( V_20 == 0 )
return V_20 ;
V_20 *= 125 ;
V_20 /= 10 ;
if ( V_2 -> V_22 )
V_20 += V_23 ;
else
V_20 -= V_23 ;
return F_5 ( V_20 * 16 , V_24 , V_25 ) ;
}
static T_3 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , F_3 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_3 V_20 = V_2 -> V_20 ;
V_20 /= 16 ;
if ( V_2 -> V_22 )
V_20 -= V_23 ;
else
V_20 += V_23 ;
V_20 *= 10 ;
V_20 /= 125 ;
V_2 -> V_3 &= ~ V_21 ;
V_2 -> V_3 |= V_20 & V_21 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_2 -> V_20 = F_4 ( V_2 , V_2 -> V_3 ) ;
}
static int F_8 ( struct V_26 * V_26 , void * V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
F_10 ( V_29 -> V_30 , V_2 -> V_31 -> V_32 , sizeof( V_29 -> V_30 ) ) ;
F_10 ( V_29 -> V_33 , V_2 -> V_33 , sizeof( V_29 -> V_33 ) ) ;
F_11 ( V_29 -> V_33 , V_2 -> V_22 ? L_1 : L_2 , sizeof( V_29 -> V_33 ) ) ;
F_10 ( V_29 -> V_34 , V_2 -> V_34 , sizeof( V_29 -> V_34 ) ) ;
V_29 -> V_35 = V_36 | V_37 ;
if ( ! V_2 -> V_38 )
V_29 -> V_35 |= V_39 ;
V_29 -> V_40 = V_29 -> V_35 | V_41 ;
return 0 ;
}
static int F_12 ( struct V_26 * V_26 , void * V_27 ,
struct V_42 * V_29 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
if ( V_29 -> V_43 > 0 )
return - V_44 ;
F_3 ( V_2 ) ;
strcpy ( V_29 -> V_32 , L_3 ) ;
V_29 -> type = V_45 ;
V_29 -> V_46 = V_47 | V_48 ;
if ( ! V_2 -> V_38 )
V_29 -> V_46 |= V_49 ;
V_29 -> V_50 = V_24 ;
V_29 -> V_51 = V_25 ;
V_29 -> V_52 = V_2 -> V_19 ? V_53 : V_54 ;
V_29 -> V_55 = ( V_2 -> V_3 & V_56 ) ?
V_57 : V_58 ;
V_29 -> signal = V_2 -> V_16 ? 0xffff : 0 ;
return 0 ;
}
static int F_13 ( struct V_26 * V_26 , void * V_27 ,
struct V_42 * V_29 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
if ( V_29 -> V_43 )
return - V_44 ;
V_2 -> V_3 &= ~ V_56 ;
if ( V_29 -> V_55 == V_57 )
V_2 -> V_3 |= V_56 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_26 * V_26 , void * V_27 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
if ( V_60 -> V_61 != 0 )
return - V_44 ;
V_60 -> type = V_45 ;
V_60 -> V_62 = V_2 -> V_20 ;
return 0 ;
}
static int F_15 ( struct V_26 * V_26 , void * V_27 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
if ( V_60 -> V_61 != 0 || V_60 -> type != V_45 )
return - V_44 ;
V_2 -> V_3 &= ~ V_63 ;
V_2 -> V_20 = F_5 ( V_60 -> V_62 , V_24 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_26 * V_26 , void * V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_9 ( V_26 ) ;
unsigned long V_67 ;
int V_68 ;
if ( V_2 -> V_38 )
return - V_69 ;
if ( V_66 -> V_61 || V_66 -> V_70 )
return - V_44 ;
V_2 -> V_3 &= ~ V_21 ;
V_2 -> V_3 |= V_63 ;
if ( V_66 -> V_71 )
V_2 -> V_3 |= V_72 ;
else
V_2 -> V_3 &= ~ V_72 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_67 = V_73 + F_17 ( 10000 ) ;
for (; ; ) {
if ( F_18 ( V_73 , V_67 ) )
break;
if ( F_19 ( F_17 ( 10 ) ) ) {
V_2 -> V_3 &= ~ V_63 ;
F_7 ( V_2 ) ;
return - V_74 ;
}
if ( ! ( F_3 ( V_2 ) & V_63 ) ) {
T_3 V_20 ;
for ( V_68 = 0 ; V_68 < 100 ; V_68 ++ ) {
F_20 ( 10 ) ;
V_20 = F_6 ( V_2 ) ;
if ( V_20 )
break;
}
if ( V_20 == 0 )
break;
if ( abs ( V_2 -> V_20 - V_20 ) < 16 * 50 ||
( V_66 -> V_71 && V_20 < V_2 -> V_20 ) ||
( ! V_66 -> V_71 && V_20 > V_2 -> V_20 ) ) {
F_1 ( V_2 , V_2 -> V_3 ) ;
continue;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_3 &= ~ V_63 ;
return 0 ;
}
}
V_2 -> V_3 &= ~ V_63 ;
F_7 ( V_2 ) ;
return - V_75 ;
}
static int F_21 ( struct V_76 * V_77 )
{
struct V_1 * V_2 = F_22 ( V_77 -> V_78 , struct V_1 , V_79 ) ;
switch ( V_77 -> V_80 ) {
case V_81 :
V_2 -> V_13 = V_77 -> V_3 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_44 ;
}
int F_23 ( struct V_1 * V_2 , struct V_82 * V_83 )
{
int V_84 ;
V_2 -> V_13 = true ;
if ( ! V_2 -> V_38 ) {
F_1 ( V_2 , 0x55AA ) ;
if ( F_3 ( V_2 ) != 0x55AA )
return - V_85 ;
}
V_2 -> V_3 = V_86 | V_87 ;
V_2 -> V_20 = 90500 * 16 ;
F_7 ( V_2 ) ;
V_2 -> V_88 = V_89 ;
F_24 ( & V_2 -> V_88 , V_2 ) ;
F_25 ( & V_2 -> V_90 ) ;
F_10 ( V_2 -> V_88 . V_32 , V_2 -> V_31 -> V_32 , sizeof( V_2 -> V_88 . V_32 ) ) ;
V_2 -> V_88 . V_91 = & V_2 -> V_90 ;
V_2 -> V_88 . V_31 = V_2 -> V_31 ;
V_2 -> V_92 = V_93 ;
V_2 -> V_92 . V_83 = V_83 ;
V_2 -> V_88 . V_92 = & V_2 -> V_92 ;
F_26 ( V_94 , & V_2 -> V_88 . V_95 ) ;
if ( V_2 -> V_38 )
F_27 ( & V_2 -> V_88 , V_96 ) ;
if ( ! V_2 -> V_97 ) {
V_2 -> V_88 . V_79 = & V_2 -> V_79 ;
F_28 ( & V_2 -> V_79 , 1 ) ;
F_29 ( & V_2 -> V_79 , & V_98 ,
V_81 , 0 , 1 , 1 , 1 ) ;
V_84 = V_2 -> V_79 . error ;
if ( V_84 ) {
F_30 ( V_2 -> V_31 , L_4 ) ;
F_31 ( & V_2 -> V_79 ) ;
return V_84 ;
}
if ( V_2 -> V_99 ) {
V_84 = V_2 -> V_99 ( V_2 ) ;
if ( V_84 ) {
F_31 ( & V_2 -> V_79 ) ;
return V_84 ;
}
}
F_32 ( & V_2 -> V_79 ) ;
}
V_84 = F_33 ( & V_2 -> V_88 , V_100 , V_2 -> V_101 ) ;
if ( V_84 ) {
F_30 ( V_2 -> V_31 , L_5 ) ;
F_31 ( V_2 -> V_88 . V_79 ) ;
return V_84 ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_88 ) ;
F_31 ( V_2 -> V_88 . V_79 ) ;
}
static int T_4 F_36 ( void )
{
return 0 ;
}
static void T_5 F_37 ( void )
{
}
