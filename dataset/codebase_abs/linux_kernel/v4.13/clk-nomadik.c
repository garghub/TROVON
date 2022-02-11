static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
void * V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
V_5 |= V_9 ;
F_3 ( L_1 ) ;
F_4 ( V_5 , V_6 + V_7 ) ;
return V_10 ;
}
static void T_2 F_5 ( void )
{
struct V_11 * V_12 ;
T_1 V_5 ;
V_12 = F_6 ( NULL , V_13 ) ;
if ( ! V_12 ) {
F_3 ( L_2 ) ;
return;
}
V_6 = F_7 ( V_12 , 0 ) ;
if ( ! V_6 ) {
F_8 ( L_3 ,
V_14 , V_12 -> V_15 ) ;
return;
}
V_5 = F_2 ( V_6 + V_16 ) ;
V_5 |= V_17 ;
V_5 |= V_18 ;
V_5 |= V_19 ;
V_5 |= V_20 ;
V_5 |= V_21 ;
V_5 |= V_22 ;
V_5 |= V_23 ;
V_5 |= V_24 ;
F_4 ( V_5 , V_6 + V_16 ) ;
V_5 = F_2 ( V_6 + V_7 ) ;
F_9 ( L_4 ,
( V_5 & V_25 ) ? L_5 : L_6 ) ;
F_9 ( L_7 ,
( V_5 & V_26 ) ? L_6 : L_5 ) ;
if ( F_10 ( V_12 , L_8 ) ) {
V_5 |= V_25 ;
F_9 ( L_9 ) ;
}
if ( F_10 ( V_12 , L_10 ) ) {
V_5 |= V_8 ;
V_5 &= ~ V_9 ;
F_9 ( L_11 ) ;
}
F_4 ( V_5 , V_6 + V_7 ) ;
F_11 ( & V_27 ) ;
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_13 ( V_29 ) ;
T_1 V_5 ;
F_14 ( & V_32 ) ;
V_5 = F_2 ( V_6 + V_33 ) ;
if ( V_31 -> V_34 == 1 ) {
if ( V_5 & V_35 ) {
V_5 |= V_36 ;
F_4 ( V_5 , V_6 + V_33 ) ;
}
} else if ( V_31 -> V_34 == 2 ) {
V_5 |= V_37 ;
F_4 ( V_5 , V_6 + V_33 ) ;
}
F_15 ( & V_32 ) ;
return 0 ;
}
static void F_16 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_13 ( V_29 ) ;
T_1 V_5 ;
F_14 ( & V_32 ) ;
V_5 = F_2 ( V_6 + V_33 ) ;
if ( V_31 -> V_34 == 1 ) {
if ( V_5 & V_35 ) {
V_5 &= ~ V_36 ;
F_4 ( V_5 , V_6 + V_33 ) ;
}
} else if ( V_31 -> V_34 == 2 ) {
V_5 &= ~ V_37 ;
F_4 ( V_5 , V_6 + V_33 ) ;
}
F_15 ( & V_32 ) ;
}
static int F_17 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_13 ( V_29 ) ;
T_1 V_5 ;
V_5 = F_2 ( V_6 + V_33 ) ;
if ( V_31 -> V_34 == 1 ) {
if ( V_5 & V_35 )
return ! ! ( V_5 & V_36 ) ;
} else if ( V_31 -> V_34 == 2 ) {
return ! ! ( V_5 & V_37 ) ;
}
return 1 ;
}
static unsigned long F_18 ( struct V_28 * V_29 ,
unsigned long V_38 )
{
struct V_30 * V_31 = F_13 ( V_29 ) ;
T_1 V_5 ;
V_5 = F_2 ( V_6 + V_39 ) ;
if ( V_31 -> V_34 == 1 ) {
T_3 V_40 ;
T_3 div ;
V_40 = ( V_5 >> 8 ) & 0x3FU ;
V_40 += 2 ;
div = V_5 & 0x07U ;
return ( V_38 * V_40 ) >> div ;
}
if ( V_31 -> V_34 == 2 ) {
T_3 V_40 ;
V_40 = ( V_5 >> 24 ) & 0x3FU ;
V_40 += 2 ;
return ( V_38 * V_40 ) ;
}
return 0 ;
}
static struct V_28 * T_2
F_19 ( struct V_41 * V_42 , const char * V_15 ,
const char * V_43 , T_1 V_34 )
{
int V_44 ;
struct V_30 * V_31 ;
struct V_45 V_46 ;
if ( V_34 != 1 && V_34 != 2 ) {
F_8 ( L_12 , V_14 ) ;
return F_20 ( - V_47 ) ;
}
V_31 = F_21 ( sizeof( * V_31 ) , V_48 ) ;
if ( ! V_31 )
return F_20 ( - V_49 ) ;
V_46 . V_15 = V_15 ;
V_46 . V_50 = & V_51 ;
V_46 . V_52 = ( V_43 ? & V_43 : NULL ) ;
V_46 . V_53 = ( V_43 ? 1 : 0 ) ;
V_31 -> V_29 . V_46 = & V_46 ;
V_31 -> V_34 = V_34 ;
F_22 ( L_13 , V_15 ) ;
V_44 = F_23 ( V_42 , & V_31 -> V_29 ) ;
if ( V_44 ) {
F_24 ( V_31 ) ;
return F_20 ( V_44 ) ;
}
return & V_31 -> V_29 ;
}
static int F_25 ( struct V_28 * V_29 )
{
struct V_54 * V_55 = F_26 ( V_29 ) ;
T_1 V_56 = V_55 -> V_57 ? V_58 : V_59 ;
T_1 V_60 = V_55 -> V_57 ? V_61 : V_62 ;
F_4 ( V_55 -> V_63 , V_6 + V_56 ) ;
while ( ! ( F_2 ( V_6 + V_60 ) & V_55 -> V_63 ) )
F_27 () ;
return 0 ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_54 * V_55 = F_26 ( V_29 ) ;
T_1 V_64 = V_55 -> V_57 ? V_65 : V_66 ;
T_1 V_60 = V_55 -> V_57 ? V_61 : V_62 ;
F_4 ( V_55 -> V_63 , V_6 + V_64 ) ;
while ( F_2 ( V_6 + V_60 ) & V_55 -> V_63 )
F_27 () ;
}
static int F_29 ( struct V_28 * V_29 )
{
struct V_54 * V_55 = F_26 ( V_29 ) ;
T_1 V_60 = V_55 -> V_57 ? V_61 : V_62 ;
T_1 V_5 = F_2 ( V_6 + V_60 ) ;
return ! ! ( V_5 & V_55 -> V_63 ) ;
}
static unsigned long
F_30 ( struct V_28 * V_29 ,
unsigned long V_38 )
{
return V_38 ;
}
static struct V_28 * T_2
F_31 ( struct V_41 * V_42 , const char * V_15 ,
const char * V_43 , T_3 V_34 )
{
int V_44 ;
struct V_54 * V_55 ;
struct V_45 V_46 ;
V_55 = F_21 ( sizeof( * V_55 ) , V_48 ) ;
if ( ! V_55 )
return F_20 ( - V_49 ) ;
V_46 . V_15 = V_15 ;
V_46 . V_50 = & V_67 ;
if ( V_34 == 2 )
V_46 . V_68 = V_69 ;
else
V_46 . V_68 = 0 ;
V_46 . V_52 = ( V_43 ? & V_43 : NULL ) ;
V_46 . V_53 = ( V_43 ? 1 : 0 ) ;
V_55 -> V_29 . V_46 = & V_46 ;
V_55 -> V_34 = V_34 ;
V_55 -> V_57 = ( V_34 > 31 ) ;
V_55 -> V_63 = F_32 ( V_34 & 0x1f ) ;
F_22 ( L_14 ,
V_15 , V_34 , V_55 -> V_57 , V_55 -> V_63 ) ;
V_44 = F_23 ( V_42 , & V_55 -> V_29 ) ;
if ( V_44 ) {
F_24 ( V_55 ) ;
return F_20 ( V_44 ) ;
}
return & V_55 -> V_29 ;
}
static int F_33 ( struct V_70 * V_71 , void * V_72 )
{
int V_73 ;
T_1 V_74 = F_2 ( V_6 + V_62 ) ;
T_1 V_75 = F_2 ( V_6 + V_61 ) ;
T_1 V_76 = F_2 ( V_6 + V_77 ) ;
T_1 V_78 = F_2 ( V_6 + V_79 ) ;
F_34 ( V_71 , L_15 ) ;
for ( V_73 = 0 ; V_73 < F_35 ( V_80 ) ; V_73 ++ ) {
T_1 V_81 = ( V_73 < 0x20 ) ? V_82 : V_83 ;
T_1 V_84 = ( V_73 < 0x20 ) ? V_74 : V_75 ;
T_1 V_85 = ( V_73 < 0x20 ) ? V_76 : V_78 ;
T_1 V_86 = F_32 ( V_73 & 0x1f ) ;
F_36 ( V_71 , L_16 ,
V_80 [ V_73 ] ,
( V_81 & V_86 ) ? L_17 : L_18 ,
( V_84 & V_86 ) ? L_17 : L_18 ,
( V_85 & V_86 ) ? L_17 : L_18 ) ;
}
return 0 ;
}
static int F_37 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_38 ( V_88 , F_33 , NULL ) ;
}
static int T_2 F_39 ( void )
{
if ( ! V_6 )
return - V_89 ;
V_82 = F_2 ( V_6 + V_62 ) ;
V_83 = F_2 ( V_6 + V_61 ) ;
F_40 ( L_19 , V_90 | V_91 ,
NULL , NULL , & V_92 ) ;
return 0 ;
}
static void T_2 F_41 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
const char * V_93 = V_12 -> V_15 ;
const char * V_43 ;
T_1 V_94 ;
if ( ! V_6 )
F_5 () ;
if ( F_42 ( V_12 , L_20 , & V_94 ) ) {
F_8 ( L_21 ,
V_14 , V_93 ) ;
return;
}
V_43 = F_43 ( V_12 , 0 ) ;
V_29 = F_19 ( NULL , V_93 , V_43 , V_94 ) ;
if ( ! F_44 ( V_29 ) )
F_45 ( V_12 , V_95 , V_29 ) ;
}
static void T_2 F_46 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
const char * V_93 = V_12 -> V_15 ;
const char * V_43 ;
if ( ! V_6 )
F_5 () ;
V_43 = F_43 ( V_12 , 0 ) ;
V_29 = F_47 ( NULL , V_93 , V_43 ,
0 , V_6 + V_16 ,
13 , 2 ,
V_96 | V_97 ,
& V_32 ) ;
if ( ! F_44 ( V_29 ) )
F_45 ( V_12 , V_95 , V_29 ) ;
}
static void T_2 F_48 ( struct V_11 * V_12 )
{
struct V_28 * V_29 ;
const char * V_93 = V_12 -> V_15 ;
const char * V_43 ;
T_1 V_98 ;
if ( ! V_6 )
F_5 () ;
if ( F_42 ( V_12 , L_22 , & V_98 ) ) {
F_8 ( L_23 ,
V_14 , V_93 ) ;
return;
}
V_43 = F_43 ( V_12 , 0 ) ;
V_29 = F_31 ( NULL , V_93 , V_43 , V_98 ) ;
if ( ! F_44 ( V_29 ) )
F_45 ( V_12 , V_95 , V_29 ) ;
}
