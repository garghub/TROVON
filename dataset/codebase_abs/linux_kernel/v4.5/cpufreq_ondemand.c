static void F_1 ( int V_1 )
{
struct V_2 * V_3 = & F_2 ( V_4 , V_1 ) ;
V_3 -> V_5 = F_3 ( V_1 ) ;
V_3 -> V_6 = 0 ;
}
static int F_4 ( void )
{
#if F_5 ( V_7 )
if ( V_8 . V_9 == V_10 &&
V_8 . V_11 == 6 &&
V_8 . V_12 >= 15 )
return 1 ;
#endif
return 0 ;
}
static unsigned int F_6 ( struct V_13 * V_14 ,
unsigned int V_15 , unsigned int V_16 )
{
unsigned int V_17 , V_18 , V_19 ;
unsigned int V_20 , V_6 ;
unsigned int V_21 = 0 ;
unsigned int V_22 , V_23 , V_24 ;
struct V_2 * V_3 = & F_2 ( V_4 ,
V_14 -> V_1 ) ;
struct V_25 * V_25 = V_14 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
if ( ! V_3 -> V_5 ) {
V_3 -> V_6 = 0 ;
V_3 -> V_30 = 0 ;
return V_15 ;
}
F_7 ( V_14 , V_3 -> V_5 , V_15 ,
V_16 , & V_21 ) ;
V_17 = V_3 -> V_5 [ V_21 ] . V_31 ;
V_18 = V_17 * V_28 -> V_32 / 1000 ;
V_19 = V_17 - V_18 ;
V_21 = 0 ;
F_7 ( V_14 , V_3 -> V_5 , V_19 ,
V_33 , & V_21 ) ;
V_6 = V_3 -> V_5 [ V_21 ] . V_31 ;
V_21 = 0 ;
F_7 ( V_14 , V_3 -> V_5 , V_19 ,
V_34 , & V_21 ) ;
V_20 = V_3 -> V_5 [ V_21 ] . V_31 ;
if ( V_20 == V_6 ) {
V_3 -> V_6 = 0 ;
V_3 -> V_30 = 0 ;
return V_6 ;
}
V_22 = F_8 ( V_28 -> V_35 ) ;
V_23 = ( V_19 - V_6 ) * V_22 ;
V_23 += ( ( V_20 - V_6 ) / 2 ) ;
V_23 /= ( V_20 - V_6 ) ;
V_24 = V_22 - V_23 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_30 = V_24 ;
V_3 -> V_36 = V_23 ;
return V_20 ;
}
static void F_9 ( void )
{
int V_37 ;
F_10 (i) {
F_1 ( V_37 ) ;
}
}
static void F_11 ( struct V_13 * V_14 , unsigned int V_38 )
{
struct V_25 * V_25 = V_14 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
if ( V_28 -> V_32 )
V_38 = V_39 . V_40 ( V_14 , V_38 ,
V_33 ) ;
else if ( V_14 -> V_41 == V_14 -> V_42 )
return;
F_12 ( V_14 , V_38 , V_28 -> V_32 ?
V_34 : V_33 ) ;
}
static void F_13 ( int V_1 , unsigned int V_43 )
{
struct V_2 * V_3 = & F_2 ( V_4 , V_1 ) ;
struct V_13 * V_14 = V_3 -> V_44 . V_45 -> V_14 ;
struct V_25 * V_25 = V_14 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
V_3 -> V_6 = 0 ;
if ( V_43 > V_28 -> V_46 ) {
if ( V_14 -> V_41 < V_14 -> V_42 )
V_3 -> V_47 =
V_28 -> V_48 ;
F_11 ( V_14 , V_14 -> V_42 ) ;
} else {
unsigned int V_15 , V_49 , V_50 ;
V_49 = V_14 -> V_51 . V_52 ;
V_50 = V_14 -> V_51 . V_53 ;
V_15 = V_49 + V_43 * ( V_50 - V_49 ) / 100 ;
V_3 -> V_47 = 1 ;
if ( ! V_28 -> V_32 ) {
F_12 ( V_14 , V_15 ,
V_54 ) ;
return;
}
V_15 = V_39 . V_40 ( V_14 , V_15 ,
V_34 ) ;
F_12 ( V_14 , V_15 , V_54 ) ;
}
}
static unsigned int F_14 ( struct V_13 * V_14 , bool V_55 )
{
struct V_25 * V_25 = V_14 -> V_26 ;
unsigned int V_1 = V_14 -> V_1 ;
struct V_2 * V_3 = & F_2 ( V_4 ,
V_1 ) ;
struct V_27 * V_28 = V_25 -> V_29 ;
int V_56 = 0 , V_57 = V_3 -> V_57 ;
if ( ! V_55 )
goto V_58;
V_3 -> V_57 = V_59 ;
if ( V_57 == V_60 ) {
V_56 = V_3 -> V_30 ;
F_12 ( V_14 , V_3 -> V_6 ,
V_33 ) ;
} else {
F_15 ( V_25 , V_1 ) ;
if ( V_3 -> V_6 ) {
V_3 -> V_57 = V_60 ;
V_56 = V_3 -> V_36 ;
}
}
V_58:
if ( ! V_56 )
V_56 = F_16 ( V_28 -> V_35
* V_3 -> V_47 ) ;
return V_56 ;
}
static void F_17 ( struct V_25 * V_25 ,
unsigned int V_61 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
struct V_62 V_62 ;
int V_1 ;
V_28 -> V_35 = V_61 = V_42 ( V_61 ,
V_25 -> V_63 ) ;
F_18 ( & V_64 . V_65 ) ;
F_19 ( & V_62 , V_66 ) ;
F_20 (cpu, &cpumask) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
struct V_67 * V_44 ;
struct V_68 * V_45 ;
unsigned long V_69 , V_70 ;
V_3 = & F_2 ( V_4 , V_1 ) ;
V_44 = & V_3 -> V_44 ;
V_45 = V_44 -> V_45 ;
if ( ! V_45 || ! V_45 -> V_14 )
continue;
V_14 = V_45 -> V_14 ;
F_21 ( & V_62 , & V_62 , V_14 -> V_71 ) ;
if ( V_25 != V_14 -> V_26 )
continue;
V_69 = V_72 + F_8 ( V_61 ) ;
V_70 = V_3 -> V_44 . V_73 . V_74 ;
if ( F_22 ( V_69 , V_70 ) ) {
F_23 ( V_45 ) ;
F_24 ( V_14 , F_8 ( V_61 ) ) ;
}
}
F_25 ( & V_64 . V_65 ) ;
}
static T_1 F_26 ( struct V_25 * V_25 , const char * V_75 ,
T_2 V_76 )
{
unsigned int V_77 ;
int V_78 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 )
return - V_79 ;
F_17 ( V_25 , V_77 ) ;
return V_76 ;
}
static T_1 F_27 ( struct V_25 * V_25 , const char * V_75 ,
T_2 V_76 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_77 ;
int V_78 ;
unsigned int V_80 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 )
return - V_79 ;
V_28 -> V_81 = ! ! V_77 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_80 ) ;
V_3 -> V_44 . V_82 = F_28 ( V_80 ,
& V_3 -> V_44 . V_83 , V_28 -> V_81 ) ;
}
return V_76 ;
}
static T_1 F_29 ( struct V_25 * V_25 , const char * V_75 ,
T_2 V_76 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_77 ;
int V_78 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 || V_77 > V_84 ||
V_77 < V_85 ) {
return - V_79 ;
}
V_28 -> V_46 = V_77 ;
return V_76 ;
}
static T_1 F_30 ( struct V_25 * V_25 ,
const char * V_75 , T_2 V_76 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_77 , V_80 ;
int V_78 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 || V_77 > V_86 || V_77 < 1 )
return - V_79 ;
V_28 -> V_48 = V_77 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_80 ) ;
V_3 -> V_47 = 1 ;
}
return V_76 ;
}
static T_1 F_31 ( struct V_25 * V_25 ,
const char * V_75 , T_2 V_76 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_77 ;
int V_78 ;
unsigned int V_80 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 )
return - V_79 ;
if ( V_77 > 1 )
V_77 = 1 ;
if ( V_77 == V_28 -> V_87 ) {
return V_76 ;
}
V_28 -> V_87 = V_77 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_80 ) ;
V_3 -> V_44 . V_82 = F_28 ( V_80 ,
& V_3 -> V_44 . V_83 , V_28 -> V_81 ) ;
if ( V_28 -> V_87 )
V_3 -> V_44 . V_88 =
F_32 ( V_80 ) . V_89 [ V_90 ] ;
}
return V_76 ;
}
static T_1 F_33 ( struct V_25 * V_25 , const char * V_75 ,
T_2 V_76 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_77 ;
int V_78 ;
V_78 = sscanf ( V_75 , L_1 , & V_77 ) ;
if ( V_78 != 1 )
return - V_79 ;
if ( V_77 > 1000 )
V_77 = 1000 ;
V_28 -> V_32 = V_77 ;
F_9 () ;
return V_76 ;
}
static int F_34 ( struct V_25 * V_25 , bool V_91 )
{
struct V_27 * V_29 ;
T_3 V_92 ;
int V_1 ;
V_29 = F_35 ( sizeof( * V_29 ) , V_93 ) ;
if ( ! V_29 ) {
F_36 ( L_2 , V_94 ) ;
return - V_95 ;
}
V_1 = F_37 () ;
V_92 = F_38 ( V_1 , NULL ) ;
F_39 () ;
if ( V_92 != - 1ULL ) {
V_29 -> V_46 = V_96 ;
V_25 -> V_63 = V_97 ;
} else {
V_29 -> V_46 = V_98 ;
V_25 -> V_63 = V_99 *
F_40 ( 10 ) ;
}
V_29 -> V_48 = V_100 ;
V_29 -> V_87 = 0 ;
V_29 -> V_32 = V_101 ;
V_29 -> V_81 = F_4 () ;
V_25 -> V_29 = V_29 ;
return 0 ;
}
static void F_41 ( struct V_25 * V_25 , bool V_91 )
{
F_42 ( V_25 -> V_29 ) ;
}
static void F_43 ( unsigned int V_32 )
{
struct V_13 * V_14 ;
struct V_25 * V_25 ;
struct V_27 * V_28 ;
unsigned int V_1 ;
T_4 V_102 ;
V_101 = V_32 ;
F_44 ( & V_102 ) ;
F_45 () ;
F_10 (cpu) {
struct V_68 * V_45 ;
if ( F_46 ( V_1 , & V_102 ) )
continue;
V_45 = F_2 ( V_4 , V_1 ) . V_44 . V_45 ;
if ( ! V_45 )
continue;
V_14 = V_45 -> V_14 ;
F_47 ( & V_102 , & V_102 , V_14 -> V_71 ) ;
if ( V_14 -> V_103 != & V_104 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_101 ;
}
F_48 () ;
}
void F_49 ( void )
{
V_39 . V_40 = F_6 ;
F_43 ( 0 ) ;
}
static int F_50 ( struct V_13 * V_14 ,
unsigned int V_105 )
{
return F_51 ( V_14 , & V_64 , V_105 ) ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_104 ) ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_104 ) ;
}
