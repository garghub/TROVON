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
return;
} else {
unsigned int V_15 ;
V_15 = V_43 * V_14 -> V_49 . V_50 / 100 ;
V_3 -> V_47 = 1 ;
if ( ! V_28 -> V_32 ) {
F_12 ( V_14 , V_15 ,
V_34 ) ;
return;
}
V_15 = V_39 . V_40 ( V_14 , V_15 ,
V_34 ) ;
F_12 ( V_14 , V_15 , V_34 ) ;
}
}
static void F_14 ( struct V_51 * V_52 )
{
struct V_2 * V_3 =
F_15 ( V_52 , struct V_2 , V_44 . V_52 . V_52 ) ;
unsigned int V_1 = V_3 -> V_44 . V_45 -> V_1 ;
struct V_2 * V_53 = & F_2 ( V_4 ,
V_1 ) ;
struct V_25 * V_25 = V_3 -> V_44 . V_45 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
int V_54 = 0 , V_55 = V_53 -> V_55 ;
bool V_56 = true ;
F_16 ( & V_53 -> V_44 . V_57 ) ;
if ( ! F_17 ( & V_53 -> V_44 , V_28 -> V_35 ) ) {
V_56 = false ;
goto V_58;
}
V_53 -> V_55 = V_59 ;
if ( V_55 == V_60 ) {
V_54 = V_53 -> V_30 ;
F_12 ( V_53 -> V_44 . V_45 ,
V_53 -> V_6 , V_33 ) ;
} else {
F_18 ( V_25 , V_1 ) ;
if ( V_53 -> V_6 ) {
V_53 -> V_55 = V_60 ;
V_54 = V_53 -> V_36 ;
}
}
V_58:
if ( ! V_54 )
V_54 = F_19 ( V_28 -> V_35
* V_53 -> V_47 ) ;
F_20 ( V_25 , V_3 -> V_44 . V_45 , V_54 , V_56 ) ;
F_21 ( & V_53 -> V_44 . V_57 ) ;
}
static void F_22 ( struct V_25 * V_25 ,
unsigned int V_61 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
int V_1 ;
V_28 -> V_35 = V_61 = V_42 ( V_61 ,
V_25 -> V_62 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_63 , V_64 ;
V_14 = F_23 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_65 != & V_66 ) {
F_24 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_1 ) ;
F_24 ( V_14 ) ;
F_16 ( & V_3 -> V_44 . V_57 ) ;
if ( ! F_25 ( & V_3 -> V_44 . V_52 ) ) {
F_21 ( & V_3 -> V_44 . V_57 ) ;
continue;
}
V_63 = V_67 + F_8 ( V_61 ) ;
V_64 = V_3 -> V_44 . V_52 . V_68 . V_69 ;
if ( F_26 ( V_63 , V_64 ) ) {
F_21 ( & V_3 -> V_44 . V_57 ) ;
F_27 ( & V_3 -> V_44 . V_52 ) ;
F_16 ( & V_3 -> V_44 . V_57 ) ;
F_20 ( V_25 , V_3 -> V_44 . V_45 ,
F_8 ( V_61 ) , true ) ;
}
F_21 ( & V_3 -> V_44 . V_57 ) ;
}
}
static T_1 F_28 ( struct V_25 * V_25 , const char * V_70 ,
T_2 V_71 )
{
unsigned int V_72 ;
int V_73 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 )
return - V_74 ;
F_22 ( V_25 , V_72 ) ;
return V_71 ;
}
static T_1 F_29 ( struct V_25 * V_25 , const char * V_70 ,
T_2 V_71 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_72 ;
int V_73 ;
unsigned int V_75 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 )
return - V_74 ;
V_28 -> V_76 = ! ! V_72 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_75 ) ;
V_3 -> V_44 . V_77 = F_30 ( V_75 ,
& V_3 -> V_44 . V_78 , V_28 -> V_76 ) ;
}
return V_71 ;
}
static T_1 F_31 ( struct V_25 * V_25 , const char * V_70 ,
T_2 V_71 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_72 ;
int V_73 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 || V_72 > V_79 ||
V_72 < V_80 ) {
return - V_74 ;
}
V_28 -> V_46 = V_72 ;
return V_71 ;
}
static T_1 F_32 ( struct V_25 * V_25 ,
const char * V_70 , T_2 V_71 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_72 , V_75 ;
int V_73 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 || V_72 > V_81 || V_72 < 1 )
return - V_74 ;
V_28 -> V_48 = V_72 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_75 ) ;
V_3 -> V_47 = 1 ;
}
return V_71 ;
}
static T_1 F_33 ( struct V_25 * V_25 ,
const char * V_70 , T_2 V_71 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_72 ;
int V_73 ;
unsigned int V_75 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 )
return - V_74 ;
if ( V_72 > 1 )
V_72 = 1 ;
if ( V_72 == V_28 -> V_82 ) {
return V_71 ;
}
V_28 -> V_82 = V_72 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_75 ) ;
V_3 -> V_44 . V_77 = F_30 ( V_75 ,
& V_3 -> V_44 . V_78 , V_28 -> V_76 ) ;
if ( V_28 -> V_82 )
V_3 -> V_44 . V_83 =
F_34 ( V_75 ) . V_84 [ V_85 ] ;
}
return V_71 ;
}
static T_1 F_35 ( struct V_25 * V_25 , const char * V_70 ,
T_2 V_71 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_72 ;
int V_73 ;
V_73 = sscanf ( V_70 , L_1 , & V_72 ) ;
if ( V_73 != 1 )
return - V_74 ;
if ( V_72 > 1000 )
V_72 = 1000 ;
V_28 -> V_32 = V_72 ;
F_9 () ;
return V_71 ;
}
static int F_36 ( struct V_25 * V_25 )
{
struct V_27 * V_29 ;
T_3 V_86 ;
int V_1 ;
V_29 = F_37 ( sizeof( * V_29 ) , V_87 ) ;
if ( ! V_29 ) {
F_38 ( L_2 , V_88 ) ;
return - V_89 ;
}
V_1 = F_39 () ;
V_86 = F_40 ( V_1 , NULL ) ;
F_41 () ;
if ( V_86 != - 1ULL ) {
V_29 -> V_46 = V_90 ;
V_25 -> V_62 = V_91 ;
} else {
V_29 -> V_46 = V_92 ;
V_25 -> V_62 = V_93 *
F_42 ( 10 ) ;
}
V_29 -> V_48 = V_94 ;
V_29 -> V_82 = 0 ;
V_29 -> V_32 = V_95 ;
V_29 -> V_76 = F_4 () ;
V_25 -> V_29 = V_29 ;
F_43 ( & V_25 -> V_96 ) ;
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
T_4 V_97 ;
V_95 = V_32 ;
F_47 ( & V_97 ) ;
F_48 () ;
F_10 (cpu) {
if ( F_49 ( V_1 , & V_97 ) )
continue;
V_14 = F_2 ( V_4 , V_1 ) . V_44 . V_45 ;
if ( ! V_14 )
continue;
F_50 ( & V_97 , & V_97 , V_14 -> V_98 ) ;
if ( V_14 -> V_65 != & V_66 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_95 ;
}
F_51 () ;
}
void F_52 ( void )
{
V_39 . V_40 = F_6 ;
F_46 ( 0 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
unsigned int V_99 )
{
return F_54 ( V_14 , & V_100 , V_99 ) ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_66 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_66 ) ;
}
