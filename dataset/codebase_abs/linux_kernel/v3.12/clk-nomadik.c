static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( & V_6 ) ;
V_5 = F_4 ( V_7 + V_8 ) ;
if ( V_4 -> V_9 == 1 ) {
if ( V_5 & V_10 ) {
V_5 |= V_11 ;
F_5 ( V_5 , V_7 + V_8 ) ;
}
} else if ( V_4 -> V_9 == 2 ) {
V_5 |= V_12 ;
F_5 ( V_5 , V_7 + V_8 ) ;
}
F_6 ( & V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( & V_6 ) ;
V_5 = F_4 ( V_7 + V_8 ) ;
if ( V_4 -> V_9 == 1 ) {
if ( V_5 & V_10 ) {
V_5 &= ~ V_11 ;
F_5 ( V_5 , V_7 + V_8 ) ;
}
} else if ( V_4 -> V_9 == 2 ) {
V_5 &= ~ V_12 ;
F_5 ( V_5 , V_7 + V_8 ) ;
}
F_6 ( & V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_4 ( V_7 + V_8 ) ;
if ( V_4 -> V_9 == 1 ) {
if ( V_5 & V_10 )
return ! ! ( V_5 & V_11 ) ;
} else if ( V_4 -> V_9 == 2 ) {
return ! ! ( V_5 & V_12 ) ;
}
return 1 ;
}
static unsigned long F_9 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_4 ( V_7 + V_14 ) ;
if ( V_4 -> V_9 == 1 ) {
T_2 V_15 ;
T_2 div ;
V_15 = ( V_5 >> 8 ) & 0x3FU ;
V_15 += 2 ;
div = V_5 & 0x07U ;
return ( V_13 * V_15 ) >> div ;
}
if ( V_4 -> V_9 == 2 ) {
T_2 V_15 ;
V_15 = ( V_5 >> 24 ) & 0x3FU ;
V_15 += 2 ;
return ( V_13 * V_15 ) ;
}
return 0 ;
}
static struct V_16 * T_3
F_10 ( struct V_17 * V_18 , const char * V_19 ,
const char * V_20 , T_1 V_9 )
{
struct V_16 * V_16 ;
struct V_3 * V_4 ;
struct V_21 V_22 ;
if ( V_9 != 1 && V_9 != 2 ) {
F_11 ( L_1 , V_23 ) ;
return F_12 ( - V_24 ) ;
}
V_4 = F_13 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 ) {
F_11 ( L_2 , V_23 ) ;
return F_12 ( - V_26 ) ;
}
V_22 . V_19 = V_19 ;
V_22 . V_27 = & V_28 ;
V_22 . V_29 = ( V_20 ? & V_20 : NULL ) ;
V_22 . V_30 = ( V_20 ? 1 : 0 ) ;
V_4 -> V_2 . V_22 = & V_22 ;
V_4 -> V_9 = V_9 ;
F_14 ( L_3 , V_19 ) ;
V_16 = F_15 ( V_18 , & V_4 -> V_2 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_4 ) ;
return V_16 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_19 ( V_2 ) ;
T_1 V_33 = V_32 -> V_34 ? V_35 : V_36 ;
T_1 V_37 = V_32 -> V_34 ? V_38 : V_39 ;
F_5 ( V_32 -> V_40 , V_7 + V_33 ) ;
while ( ! ( F_4 ( V_7 + V_37 ) & V_32 -> V_40 ) )
F_20 () ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_19 ( V_2 ) ;
T_1 V_41 = V_32 -> V_34 ? V_42 : V_43 ;
T_1 V_37 = V_32 -> V_34 ? V_38 : V_39 ;
F_5 ( V_32 -> V_40 , V_7 + V_41 ) ;
while ( F_4 ( V_7 + V_37 ) & V_32 -> V_40 )
F_20 () ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_19 ( V_2 ) ;
T_1 V_37 = V_32 -> V_34 ? V_38 : V_39 ;
T_1 V_5 = F_4 ( V_7 + V_37 ) ;
return ! ! ( V_5 & V_32 -> V_40 ) ;
}
static unsigned long
F_23 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
return V_13 ;
}
static struct V_16 * T_3
F_24 ( struct V_17 * V_18 , const char * V_19 ,
const char * V_20 , T_2 V_9 )
{
struct V_16 * V_16 ;
struct V_31 * V_32 ;
struct V_21 V_22 ;
V_32 = F_13 ( sizeof( * V_32 ) , V_25 ) ;
if ( ! V_32 ) {
F_11 ( L_4 ,
V_19 ) ;
return F_12 ( - V_26 ) ;
}
V_22 . V_19 = V_19 ;
V_22 . V_27 = & V_44 ;
if ( V_9 == 2 )
V_22 . V_45 = V_46 ;
else
V_22 . V_45 = 0 ;
V_22 . V_29 = ( V_20 ? & V_20 : NULL ) ;
V_22 . V_30 = ( V_20 ? 1 : 0 ) ;
V_32 -> V_2 . V_22 = & V_22 ;
V_32 -> V_9 = V_9 ;
V_32 -> V_34 = ( V_9 > 31 ) ;
V_32 -> V_40 = F_25 ( V_9 & 0x1f ) ;
F_14 ( L_5 ,
V_19 , V_9 , V_32 -> V_34 , V_32 -> V_40 ) ;
V_16 = F_15 ( V_18 , & V_32 -> V_2 ) ;
if ( F_16 ( V_16 ) )
F_17 ( V_32 ) ;
return V_16 ;
}
static int F_26 ( struct V_47 * V_48 , void * V_49 )
{
int V_50 ;
T_1 V_51 = F_4 ( V_7 + V_39 ) ;
T_1 V_52 = F_4 ( V_7 + V_38 ) ;
T_1 V_53 = F_4 ( V_7 + V_54 ) ;
T_1 V_55 = F_4 ( V_7 + V_56 ) ;
F_27 ( V_48 , L_6 ) ;
for ( V_50 = 0 ; V_50 < F_28 ( V_57 ) ; V_50 ++ ) {
T_1 V_58 = ( V_50 < 0x20 ) ? V_59 : V_60 ;
T_1 V_61 = ( V_50 < 0x20 ) ? V_51 : V_52 ;
T_1 V_62 = ( V_50 < 0x20 ) ? V_53 : V_55 ;
T_1 V_63 = F_25 ( V_50 & 0x1f ) ;
F_27 ( V_48 , L_7 ,
V_57 [ V_50 ] ,
( V_58 & V_63 ) ? L_8 : L_9 ,
( V_61 & V_63 ) ? L_8 : L_9 ,
( V_62 & V_63 ) ? L_8 : L_9 ) ;
}
return 0 ;
}
static int F_29 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_30 ( V_65 , F_26 , NULL ) ;
}
static int T_3 F_31 ( void )
{
V_59 = F_4 ( V_7 + V_39 ) ;
V_60 = F_4 ( V_7 + V_38 ) ;
F_32 ( L_10 , V_66 | V_67 ,
NULL , NULL , & V_68 ) ;
return 0 ;
}
static void T_3 F_33 ( struct V_69 * V_70 )
{
struct V_16 * V_16 = F_12 ( - V_24 ) ;
const char * V_71 = V_70 -> V_19 ;
const char * V_20 ;
T_1 V_72 ;
if ( F_34 ( V_70 , L_11 , & V_72 ) ) {
F_11 ( L_12 ,
V_23 , V_71 ) ;
return;
}
V_20 = F_35 ( V_70 , 0 ) ;
V_16 = F_10 ( NULL , V_71 , V_20 , V_72 ) ;
if ( ! F_16 ( V_16 ) )
F_36 ( V_70 , V_73 , V_16 ) ;
}
static void T_3 F_37 ( struct V_69 * V_70 )
{
struct V_16 * V_16 = F_12 ( - V_24 ) ;
const char * V_71 = V_70 -> V_19 ;
const char * V_20 ;
V_20 = F_35 ( V_70 , 0 ) ;
V_16 = F_38 ( NULL , V_71 , V_20 ,
0 , V_7 + V_74 ,
13 , 2 ,
V_75 | V_76 ,
& V_6 ) ;
if ( ! F_16 ( V_16 ) )
F_36 ( V_70 , V_73 , V_16 ) ;
}
static void T_3 F_39 ( struct V_69 * V_70 )
{
struct V_16 * V_16 = F_12 ( - V_24 ) ;
const char * V_71 = V_70 -> V_19 ;
const char * V_20 ;
T_1 V_77 ;
if ( F_34 ( V_70 , L_13 , & V_77 ) ) {
F_11 ( L_14 ,
V_23 , V_71 ) ;
return;
}
V_20 = F_35 ( V_70 , 0 ) ;
V_16 = F_24 ( NULL , V_71 , V_20 , V_77 ) ;
if ( ! F_16 ( V_16 ) )
F_36 ( V_70 , V_73 , V_16 ) ;
}
static int F_40 ( struct V_78 * V_79 ,
unsigned long V_80 ,
void * V_81 )
{
T_1 V_5 ;
V_5 = F_4 ( V_7 + V_82 ) ;
V_5 &= ~ V_83 ;
V_5 |= V_84 ;
F_41 ( L_15 ) ;
F_5 ( V_5 , V_7 + V_82 ) ;
return V_85 ;
}
void T_3 F_42 ( void )
{
struct V_69 * V_70 ;
T_1 V_5 ;
V_70 = F_43 ( NULL , V_86 ) ;
if ( ! V_70 ) {
F_41 ( L_16 ) ;
return;
}
V_7 = F_44 ( V_70 , 0 ) ;
if ( ! V_7 ) {
F_11 ( L_17 ,
V_23 , V_70 -> V_19 ) ;
return;
}
V_5 = F_4 ( V_7 + V_74 ) ;
V_5 |= V_87 ;
V_5 |= V_88 ;
V_5 |= V_89 ;
V_5 |= V_90 ;
V_5 |= V_91 ;
V_5 |= V_92 ;
V_5 |= V_93 ;
V_5 |= V_94 ;
F_5 ( V_5 , V_7 + V_74 ) ;
V_5 = F_4 ( V_7 + V_82 ) ;
F_45 ( L_18 ,
( V_5 & V_95 ) ? L_19 : L_20 ) ;
F_45 ( L_21 ,
( V_5 & V_96 ) ? L_20 : L_19 ) ;
if ( F_46 ( V_70 , L_22 ) ) {
V_5 |= V_95 ;
F_45 ( L_23 ) ;
}
if ( F_46 ( V_70 , L_24 ) ) {
V_5 |= V_83 ;
V_5 &= ~ V_84 ;
F_45 ( L_25 ) ;
}
F_5 ( V_5 , V_7 + V_82 ) ;
F_47 ( & V_97 ) ;
F_48 ( V_98 ) ;
}
