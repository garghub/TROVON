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
struct V_13 * V_14 = V_3 -> V_44 . V_45 ;
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
static void F_14 ( struct V_55 * V_56 )
{
struct V_2 * V_3 =
F_15 ( V_56 , struct V_2 , V_44 . V_56 . V_56 ) ;
unsigned int V_1 = V_3 -> V_44 . V_45 -> V_1 ;
struct V_2 * V_57 = & F_2 ( V_4 ,
V_1 ) ;
struct V_25 * V_25 = V_3 -> V_44 . V_45 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
int V_58 = 0 , V_59 = V_57 -> V_59 ;
bool V_60 = true ;
F_16 ( & V_57 -> V_44 . V_61 ) ;
if ( ! F_17 ( & V_57 -> V_44 , V_28 -> V_35 ) ) {
V_60 = false ;
goto V_62;
}
V_57 -> V_59 = V_63 ;
if ( V_59 == V_64 ) {
V_58 = V_57 -> V_30 ;
F_12 ( V_57 -> V_44 . V_45 ,
V_57 -> V_6 , V_33 ) ;
} else {
F_18 ( V_25 , V_1 ) ;
if ( V_57 -> V_6 ) {
V_57 -> V_59 = V_64 ;
V_58 = V_57 -> V_36 ;
}
}
V_62:
if ( ! V_58 )
V_58 = F_19 ( V_28 -> V_35
* V_57 -> V_47 ) ;
F_20 ( V_25 , V_3 -> V_44 . V_45 , V_58 , V_60 ) ;
F_21 ( & V_57 -> V_44 . V_61 ) ;
}
static void F_22 ( struct V_25 * V_25 ,
unsigned int V_65 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
int V_1 ;
V_28 -> V_35 = V_65 = V_42 ( V_65 ,
V_25 -> V_66 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_67 , V_68 ;
V_14 = F_23 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_69 != & V_70 ) {
F_24 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_1 ) ;
F_24 ( V_14 ) ;
F_16 ( & V_3 -> V_44 . V_61 ) ;
if ( ! F_25 ( & V_3 -> V_44 . V_56 ) ) {
F_21 ( & V_3 -> V_44 . V_61 ) ;
continue;
}
V_67 = V_71 + F_8 ( V_65 ) ;
V_68 = V_3 -> V_44 . V_56 . V_72 . V_73 ;
if ( F_26 ( V_67 , V_68 ) ) {
F_21 ( & V_3 -> V_44 . V_61 ) ;
F_27 ( & V_3 -> V_44 . V_56 ) ;
F_16 ( & V_3 -> V_44 . V_61 ) ;
F_20 ( V_25 , V_3 -> V_44 . V_45 ,
F_8 ( V_65 ) , true ) ;
}
F_21 ( & V_3 -> V_44 . V_61 ) ;
}
}
static T_1 F_28 ( struct V_25 * V_25 , const char * V_74 ,
T_2 V_75 )
{
unsigned int V_76 ;
int V_77 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 )
return - V_78 ;
F_22 ( V_25 , V_76 ) ;
return V_75 ;
}
static T_1 F_29 ( struct V_25 * V_25 , const char * V_74 ,
T_2 V_75 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_76 ;
int V_77 ;
unsigned int V_79 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 )
return - V_78 ;
V_28 -> V_80 = ! ! V_76 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_79 ) ;
V_3 -> V_44 . V_81 = F_30 ( V_79 ,
& V_3 -> V_44 . V_82 , V_28 -> V_80 ) ;
}
return V_75 ;
}
static T_1 F_31 ( struct V_25 * V_25 , const char * V_74 ,
T_2 V_75 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_76 ;
int V_77 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 || V_76 > V_83 ||
V_76 < V_84 ) {
return - V_78 ;
}
V_28 -> V_46 = V_76 ;
return V_75 ;
}
static T_1 F_32 ( struct V_25 * V_25 ,
const char * V_74 , T_2 V_75 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_76 , V_79 ;
int V_77 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 || V_76 > V_85 || V_76 < 1 )
return - V_78 ;
V_28 -> V_48 = V_76 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_79 ) ;
V_3 -> V_47 = 1 ;
}
return V_75 ;
}
static T_1 F_33 ( struct V_25 * V_25 ,
const char * V_74 , T_2 V_75 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_76 ;
int V_77 ;
unsigned int V_79 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 )
return - V_78 ;
if ( V_76 > 1 )
V_76 = 1 ;
if ( V_76 == V_28 -> V_86 ) {
return V_75 ;
}
V_28 -> V_86 = V_76 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_79 ) ;
V_3 -> V_44 . V_81 = F_30 ( V_79 ,
& V_3 -> V_44 . V_82 , V_28 -> V_80 ) ;
if ( V_28 -> V_86 )
V_3 -> V_44 . V_87 =
F_34 ( V_79 ) . V_88 [ V_89 ] ;
}
return V_75 ;
}
static T_1 F_35 ( struct V_25 * V_25 , const char * V_74 ,
T_2 V_75 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_76 ;
int V_77 ;
V_77 = sscanf ( V_74 , L_1 , & V_76 ) ;
if ( V_77 != 1 )
return - V_78 ;
if ( V_76 > 1000 )
V_76 = 1000 ;
V_28 -> V_32 = V_76 ;
F_9 () ;
return V_75 ;
}
static int F_36 ( struct V_25 * V_25 )
{
struct V_27 * V_29 ;
T_3 V_90 ;
int V_1 ;
V_29 = F_37 ( sizeof( * V_29 ) , V_91 ) ;
if ( ! V_29 ) {
F_38 ( L_2 , V_92 ) ;
return - V_93 ;
}
V_1 = F_39 () ;
V_90 = F_40 ( V_1 , NULL ) ;
F_41 () ;
if ( V_90 != - 1ULL ) {
V_29 -> V_46 = V_94 ;
V_25 -> V_66 = V_95 ;
} else {
V_29 -> V_46 = V_96 ;
V_25 -> V_66 = V_97 *
F_42 ( 10 ) ;
}
V_29 -> V_48 = V_98 ;
V_29 -> V_86 = 0 ;
V_29 -> V_32 = V_99 ;
V_29 -> V_80 = F_4 () ;
V_25 -> V_29 = V_29 ;
F_43 ( & V_25 -> V_100 ) ;
return 0 ;
}
static void F_44 ( struct V_25 * V_25 )
{
F_45 ( V_25 -> V_29 ) ;
}
static void F_46 ( unsigned int V_32 )
{
struct V_13 * V_14 ;
struct V_25 * V_25 ;
struct V_27 * V_28 ;
unsigned int V_1 ;
T_4 V_101 ;
V_99 = V_32 ;
F_47 ( & V_101 ) ;
F_48 () ;
F_10 (cpu) {
if ( F_49 ( V_1 , & V_101 ) )
continue;
V_14 = F_2 ( V_4 , V_1 ) . V_44 . V_45 ;
if ( ! V_14 )
continue;
F_50 ( & V_101 , & V_101 , V_14 -> V_102 ) ;
if ( V_14 -> V_69 != & V_70 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_99 ;
}
F_51 () ;
}
void F_52 ( void )
{
V_39 . V_40 = F_6 ;
F_46 ( 0 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
unsigned int V_103 )
{
return F_54 ( V_14 , & V_104 , V_103 ) ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_70 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_70 ) ;
}
