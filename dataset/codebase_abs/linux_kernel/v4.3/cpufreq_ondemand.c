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
static unsigned int F_14 ( struct V_55 * V_44 ,
struct V_25 * V_25 , bool V_56 )
{
struct V_13 * V_14 = V_44 -> V_45 -> V_14 ;
unsigned int V_1 = V_14 -> V_1 ;
struct V_2 * V_3 = & F_2 ( V_4 ,
V_1 ) ;
struct V_27 * V_28 = V_25 -> V_29 ;
int V_57 = 0 , V_58 = V_3 -> V_58 ;
if ( ! V_56 )
goto V_59;
V_3 -> V_58 = V_60 ;
if ( V_58 == V_61 ) {
V_57 = V_3 -> V_30 ;
F_12 ( V_14 , V_3 -> V_6 ,
V_33 ) ;
} else {
F_15 ( V_25 , V_1 ) ;
if ( V_3 -> V_6 ) {
V_3 -> V_58 = V_61 ;
V_57 = V_3 -> V_36 ;
}
}
V_59:
if ( ! V_57 )
V_57 = F_16 ( V_28 -> V_35
* V_3 -> V_47 ) ;
return V_57 ;
}
static void F_17 ( struct V_25 * V_25 ,
unsigned int V_62 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
int V_1 ;
V_28 -> V_35 = V_62 = V_42 ( V_62 ,
V_25 -> V_63 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_64 , V_65 ;
V_14 = F_18 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_66 != & V_67 ) {
F_19 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_1 ) ;
F_19 ( V_14 ) ;
F_20 ( & V_3 -> V_44 . V_45 -> V_68 ) ;
if ( ! F_21 ( & V_3 -> V_44 . V_69 ) ) {
F_22 ( & V_3 -> V_44 . V_45 -> V_68 ) ;
continue;
}
V_64 = V_70 + F_8 ( V_62 ) ;
V_65 = V_3 -> V_44 . V_69 . V_71 . V_72 ;
if ( F_23 ( V_64 , V_65 ) ) {
F_22 ( & V_3 -> V_44 . V_45 -> V_68 ) ;
F_24 ( & V_3 -> V_44 . V_69 ) ;
F_20 ( & V_3 -> V_44 . V_45 -> V_68 ) ;
F_25 ( V_25 , V_14 ,
F_8 ( V_62 ) , true ) ;
}
F_22 ( & V_3 -> V_44 . V_45 -> V_68 ) ;
}
}
static T_1 F_26 ( struct V_25 * V_25 , const char * V_73 ,
T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
F_17 ( V_25 , V_75 ) ;
return V_74 ;
}
static T_1 F_27 ( struct V_25 * V_25 , const char * V_73 ,
T_2 V_74 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_75 ;
int V_76 ;
unsigned int V_78 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
V_28 -> V_79 = ! ! V_75 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_78 ) ;
V_3 -> V_44 . V_80 = F_28 ( V_78 ,
& V_3 -> V_44 . V_81 , V_28 -> V_79 ) ;
}
return V_74 ;
}
static T_1 F_29 ( struct V_25 * V_25 , const char * V_73 ,
T_2 V_74 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 || V_75 > V_82 ||
V_75 < V_83 ) {
return - V_77 ;
}
V_28 -> V_46 = V_75 ;
return V_74 ;
}
static T_1 F_30 ( struct V_25 * V_25 ,
const char * V_73 , T_2 V_74 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_75 , V_78 ;
int V_76 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 || V_75 > V_84 || V_75 < 1 )
return - V_77 ;
V_28 -> V_48 = V_75 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_78 ) ;
V_3 -> V_47 = 1 ;
}
return V_74 ;
}
static T_1 F_31 ( struct V_25 * V_25 ,
const char * V_73 , T_2 V_74 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_75 ;
int V_76 ;
unsigned int V_78 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
if ( V_75 > 1 )
V_75 = 1 ;
if ( V_75 == V_28 -> V_85 ) {
return V_74 ;
}
V_28 -> V_85 = V_75 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_78 ) ;
V_3 -> V_44 . V_80 = F_28 ( V_78 ,
& V_3 -> V_44 . V_81 , V_28 -> V_79 ) ;
if ( V_28 -> V_85 )
V_3 -> V_44 . V_86 =
F_32 ( V_78 ) . V_87 [ V_88 ] ;
}
return V_74 ;
}
static T_1 F_33 ( struct V_25 * V_25 , const char * V_73 ,
T_2 V_74 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_73 , L_1 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
if ( V_75 > 1000 )
V_75 = 1000 ;
V_28 -> V_32 = V_75 ;
F_9 () ;
return V_74 ;
}
static int F_34 ( struct V_25 * V_25 , bool V_89 )
{
struct V_27 * V_29 ;
T_3 V_90 ;
int V_1 ;
V_29 = F_35 ( sizeof( * V_29 ) , V_91 ) ;
if ( ! V_29 ) {
F_36 ( L_2 , V_92 ) ;
return - V_93 ;
}
V_1 = F_37 () ;
V_90 = F_38 ( V_1 , NULL ) ;
F_39 () ;
if ( V_90 != - 1ULL ) {
V_29 -> V_46 = V_94 ;
V_25 -> V_63 = V_95 ;
} else {
V_29 -> V_46 = V_96 ;
V_25 -> V_63 = V_97 *
F_40 ( 10 ) ;
}
V_29 -> V_48 = V_98 ;
V_29 -> V_85 = 0 ;
V_29 -> V_32 = V_99 ;
V_29 -> V_79 = F_4 () ;
V_25 -> V_29 = V_29 ;
return 0 ;
}
static void F_41 ( struct V_25 * V_25 , bool V_89 )
{
F_42 ( V_25 -> V_29 ) ;
}
static void F_43 ( unsigned int V_32 )
{
struct V_13 * V_14 ;
struct V_25 * V_25 ;
struct V_27 * V_28 ;
unsigned int V_1 ;
T_4 V_100 ;
V_99 = V_32 ;
F_44 ( & V_100 ) ;
F_45 () ;
F_10 (cpu) {
struct V_101 * V_45 ;
if ( F_46 ( V_1 , & V_100 ) )
continue;
V_45 = F_2 ( V_4 , V_1 ) . V_44 . V_45 ;
if ( ! V_45 )
continue;
V_14 = V_45 -> V_14 ;
F_47 ( & V_100 , & V_100 , V_14 -> V_102 ) ;
if ( V_14 -> V_66 != & V_67 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_99 ;
}
F_48 () ;
}
void F_49 ( void )
{
V_39 . V_40 = F_6 ;
F_43 ( 0 ) ;
}
static int F_50 ( struct V_13 * V_14 ,
unsigned int V_103 )
{
return F_51 ( V_14 , & V_104 , V_103 ) ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_67 ) ;
}
static void T_6 F_54 ( void )
{
F_55 ( & V_67 ) ;
}
