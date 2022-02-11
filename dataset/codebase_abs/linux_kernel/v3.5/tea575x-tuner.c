static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
V_2 -> V_6 -> V_7 ( V_2 , 1 ) ;
F_2 ( 16 ) ;
for ( V_4 = 25 ; V_4 > 0 ; V_4 -- ) {
V_5 = ( V_3 >> 24 ) & V_8 ;
V_3 <<= 1 ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 | V_11 ) ;
F_2 ( 2 ) ;
V_2 -> V_6 -> V_9 ( V_2 , V_5 | V_10 ) ;
F_2 ( 2 ) ;
}
if ( ! V_2 -> V_12 )
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
}
static T_3 F_3 ( struct V_1 * V_2 )
{
T_1 V_4 , V_13 ;
T_3 V_5 = 0 ;
V_2 -> V_6 -> V_7 ( V_2 , 0 ) ;
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
F_2 ( 16 ) ;
for ( V_4 = 24 ; V_4 -- ; ) {
V_2 -> V_6 -> V_9 ( V_2 , V_11 ) ;
F_2 ( 2 ) ;
if ( ! V_4 )
V_2 -> V_14 = V_2 -> V_6 -> V_15 ( V_2 ) & V_16 ? 0 : 1 ;
V_2 -> V_6 -> V_9 ( V_2 , 0 ) ;
F_2 ( 2 ) ;
V_5 <<= 1 ;
V_13 = V_2 -> V_6 -> V_15 ( V_2 ) ;
if ( ! V_4 )
V_2 -> V_17 = ( V_13 & V_16 ) ? 0 : 1 ;
if ( V_13 & V_8 )
V_5 ++ ;
F_2 ( 2 ) ;
}
if ( V_2 -> V_12 )
V_2 -> V_6 -> V_9 ( V_2 , V_10 ) ;
return V_5 ;
}
static T_3 F_4 ( struct V_1 * V_2 , T_3 V_3 )
{
T_3 V_18 = V_3 & V_19 ;
if ( V_18 == 0 )
return V_18 ;
V_18 *= 125 ;
V_18 /= 10 ;
if ( V_2 -> V_20 )
V_18 += V_21 ;
else
V_18 -= V_21 ;
return F_5 ( V_18 * 16 , V_22 , V_23 ) ;
}
static T_3 F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , F_3 ( V_2 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_3 V_18 = V_2 -> V_18 ;
V_18 /= 16 ;
if ( V_2 -> V_20 )
V_18 -= V_21 ;
else
V_18 += V_21 ;
V_18 *= 10 ;
V_18 /= 125 ;
V_2 -> V_3 &= ~ V_19 ;
V_2 -> V_3 |= V_18 & V_19 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_2 -> V_18 = F_4 ( V_2 , V_2 -> V_3 ) ;
}
static int F_8 ( struct V_24 * V_24 , void * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
F_10 ( V_27 -> V_28 , V_2 -> V_29 -> V_30 , sizeof( V_27 -> V_28 ) ) ;
F_10 ( V_27 -> V_31 , V_2 -> V_31 , sizeof( V_27 -> V_31 ) ) ;
F_11 ( V_27 -> V_31 , V_2 -> V_20 ? L_1 : L_2 , sizeof( V_27 -> V_31 ) ) ;
F_10 ( V_27 -> V_32 , V_2 -> V_32 , sizeof( V_27 -> V_32 ) ) ;
V_27 -> V_33 = V_34 | V_35 ;
if ( ! V_2 -> V_36 )
V_27 -> V_33 |= V_37 ;
V_27 -> V_38 = V_27 -> V_33 | V_39 ;
return 0 ;
}
static int F_12 ( struct V_24 * V_24 , void * V_25 ,
struct V_40 * V_27 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
if ( V_27 -> V_41 > 0 )
return - V_42 ;
F_3 ( V_2 ) ;
strcpy ( V_27 -> V_30 , L_3 ) ;
V_27 -> type = V_43 ;
V_27 -> V_44 = V_45 | V_46 ;
V_27 -> V_47 = V_22 ;
V_27 -> V_48 = V_23 ;
V_27 -> V_49 = V_2 -> V_17 ? V_50 : V_51 ;
V_27 -> V_52 = ( V_2 -> V_3 & V_53 ) ?
V_54 : V_55 ;
V_27 -> signal = V_2 -> V_14 ? 0xffff : 0 ;
return 0 ;
}
static int F_13 ( struct V_24 * V_24 , void * V_25 ,
struct V_40 * V_27 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
if ( V_27 -> V_41 )
return - V_42 ;
V_2 -> V_3 &= ~ V_53 ;
if ( V_27 -> V_52 == V_54 )
V_2 -> V_3 |= V_53 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
return 0 ;
}
static int F_14 ( struct V_24 * V_24 , void * V_25 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
if ( V_57 -> V_58 != 0 )
return - V_42 ;
V_57 -> type = V_43 ;
V_57 -> V_59 = V_2 -> V_18 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_24 , void * V_25 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
if ( V_57 -> V_58 != 0 || V_57 -> type != V_43 )
return - V_42 ;
V_2 -> V_3 &= ~ V_60 ;
V_2 -> V_18 = F_5 ( V_57 -> V_59 , V_22 , V_23 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_24 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_9 ( V_24 ) ;
unsigned long V_64 ;
int V_65 ;
if ( V_2 -> V_36 )
return - V_66 ;
if ( V_63 -> V_58 || V_63 -> V_67 )
return - V_42 ;
V_2 -> V_3 &= ~ V_19 ;
V_2 -> V_3 |= V_60 ;
if ( V_63 -> V_68 )
V_2 -> V_3 |= V_69 ;
else
V_2 -> V_3 &= ~ V_69 ;
F_1 ( V_2 , V_2 -> V_3 ) ;
V_64 = V_70 + F_17 ( 10000 ) ;
for (; ; ) {
if ( F_18 ( V_70 , V_64 ) )
break;
if ( F_19 ( F_17 ( 10 ) ) ) {
V_2 -> V_3 &= ~ V_60 ;
F_7 ( V_2 ) ;
return - V_71 ;
}
if ( ! ( F_3 ( V_2 ) & V_60 ) ) {
T_3 V_18 ;
for ( V_65 = 0 ; V_65 < 100 ; V_65 ++ ) {
F_20 ( 10 ) ;
V_18 = F_6 ( V_2 ) ;
if ( V_18 )
break;
}
if ( V_18 == 0 )
break;
if ( abs ( V_2 -> V_18 - V_18 ) < 16 * 50 ||
( V_63 -> V_68 && V_18 < V_2 -> V_18 ) ||
( ! V_63 -> V_68 && V_18 > V_2 -> V_18 ) ) {
F_1 ( V_2 , V_2 -> V_3 ) ;
continue;
}
V_2 -> V_18 = V_18 ;
V_2 -> V_3 &= ~ V_60 ;
return 0 ;
}
}
V_2 -> V_3 &= ~ V_60 ;
F_7 ( V_2 ) ;
return - V_72 ;
}
static int F_21 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_22 ( V_74 -> V_75 , struct V_1 , V_76 ) ;
switch ( V_74 -> V_77 ) {
case V_78 :
V_2 -> V_12 = V_74 -> V_3 ;
F_7 ( V_2 ) ;
return 0 ;
}
return - V_42 ;
}
int F_23 ( struct V_1 * V_2 , struct V_79 * V_80 )
{
int V_81 ;
V_2 -> V_12 = true ;
if ( ! V_2 -> V_36 ) {
F_1 ( V_2 , 0x55AA ) ;
if ( F_3 ( V_2 ) != 0x55AA )
return - V_82 ;
}
V_2 -> V_3 = V_83 | V_84 ;
V_2 -> V_18 = 90500 * 16 ;
F_7 ( V_2 ) ;
V_2 -> V_85 = V_86 ;
F_24 ( & V_2 -> V_85 , V_2 ) ;
F_25 ( & V_2 -> V_87 ) ;
F_10 ( V_2 -> V_85 . V_30 , V_2 -> V_29 -> V_30 , sizeof( V_2 -> V_85 . V_30 ) ) ;
V_2 -> V_85 . V_88 = & V_2 -> V_87 ;
V_2 -> V_85 . V_29 = V_2 -> V_29 ;
V_2 -> V_85 . V_76 = & V_2 -> V_76 ;
V_2 -> V_89 = V_90 ;
V_2 -> V_89 . V_80 = V_80 ;
V_2 -> V_85 . V_89 = & V_2 -> V_89 ;
F_26 ( V_91 , & V_2 -> V_85 . V_92 ) ;
if ( V_2 -> V_36 )
F_27 ( & V_2 -> V_85 , V_93 ) ;
F_28 ( & V_2 -> V_76 , 1 ) ;
F_29 ( & V_2 -> V_76 , & V_94 , V_78 , 0 , 1 , 1 , 1 ) ;
V_81 = V_2 -> V_76 . error ;
if ( V_81 ) {
F_30 ( V_2 -> V_29 , L_4 ) ;
F_31 ( & V_2 -> V_76 ) ;
return V_81 ;
}
if ( V_2 -> V_95 ) {
V_81 = V_2 -> V_95 ( V_2 ) ;
if ( V_81 ) {
F_31 ( & V_2 -> V_76 ) ;
return V_81 ;
}
}
F_32 ( & V_2 -> V_76 ) ;
V_81 = F_33 ( & V_2 -> V_85 , V_96 , V_2 -> V_97 ) ;
if ( V_81 ) {
F_30 ( V_2 -> V_29 , L_5 ) ;
F_31 ( & V_2 -> V_76 ) ;
return V_81 ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_85 ) ;
F_31 ( & V_2 -> V_76 ) ;
}
static int T_4 F_36 ( void )
{
return 0 ;
}
static void T_5 F_37 ( void )
{
}
