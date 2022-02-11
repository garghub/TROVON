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
static void F_11 ( struct V_13 * V_38 , unsigned int V_39 )
{
struct V_25 * V_25 = V_38 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
if ( V_28 -> V_32 )
V_39 = V_40 . V_41 ( V_38 , V_39 ,
V_33 ) ;
else if ( V_38 -> V_42 == V_38 -> V_43 )
return;
F_12 ( V_38 , V_39 , V_28 -> V_32 ?
V_34 : V_33 ) ;
}
static void F_13 ( int V_1 , unsigned int V_44 )
{
struct V_2 * V_3 = & F_2 ( V_4 , V_1 ) ;
struct V_13 * V_14 = V_3 -> V_45 . V_46 ;
struct V_25 * V_25 = V_14 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
V_3 -> V_6 = 0 ;
if ( V_44 > V_28 -> V_47 * V_14 -> V_42 ) {
if ( V_14 -> V_42 < V_14 -> V_43 )
V_3 -> V_48 =
V_28 -> V_49 ;
F_11 ( V_14 , V_14 -> V_43 ) ;
return;
}
if ( V_14 -> V_42 == V_14 -> V_50 )
return;
if ( V_44 < V_28 -> V_51
* V_14 -> V_42 ) {
unsigned int V_15 ;
V_15 = V_44 / V_28 -> V_51 ;
V_3 -> V_48 = 1 ;
if ( V_15 < V_14 -> V_50 )
V_15 = V_14 -> V_50 ;
if ( ! V_28 -> V_32 ) {
F_12 ( V_14 , V_15 ,
V_34 ) ;
return;
}
V_15 = V_40 . V_41 ( V_14 , V_15 ,
V_34 ) ;
F_12 ( V_14 , V_15 , V_34 ) ;
}
}
static void F_14 ( struct V_52 * V_53 )
{
struct V_2 * V_3 =
F_15 ( V_53 , struct V_2 , V_45 . V_53 . V_53 ) ;
unsigned int V_1 = V_3 -> V_45 . V_46 -> V_1 ;
struct V_2 * V_54 = & F_2 ( V_4 ,
V_1 ) ;
struct V_25 * V_25 = V_3 -> V_45 . V_46 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_29 ;
int V_55 = 0 , V_56 = V_54 -> V_56 ;
bool V_57 = true ;
F_16 ( & V_54 -> V_45 . V_58 ) ;
if ( ! F_17 ( & V_54 -> V_45 , V_28 -> V_35 ) ) {
V_57 = false ;
goto V_59;
}
V_54 -> V_56 = V_60 ;
if ( V_56 == V_61 ) {
V_55 = V_54 -> V_30 ;
F_12 ( V_54 -> V_45 . V_46 ,
V_54 -> V_6 , V_33 ) ;
} else {
F_18 ( V_25 , V_1 ) ;
if ( V_54 -> V_6 ) {
V_54 -> V_56 = V_61 ;
V_55 = V_54 -> V_36 ;
}
}
V_59:
if ( ! V_55 )
V_55 = F_19 ( V_28 -> V_35
* V_54 -> V_48 ) ;
F_20 ( V_25 , V_3 -> V_45 . V_46 , V_55 , V_57 ) ;
F_21 ( & V_54 -> V_45 . V_58 ) ;
}
static void F_22 ( struct V_25 * V_25 ,
unsigned int V_62 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
int V_1 ;
V_28 -> V_35 = V_62 = V_43 ( V_62 ,
V_25 -> V_63 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_64 , V_65 ;
V_14 = F_23 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_66 != & V_67 ) {
F_24 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_1 ) ;
F_24 ( V_14 ) ;
F_16 ( & V_3 -> V_45 . V_58 ) ;
if ( ! F_25 ( & V_3 -> V_45 . V_53 ) ) {
F_21 ( & V_3 -> V_45 . V_58 ) ;
continue;
}
V_64 = V_68 + F_8 ( V_62 ) ;
V_65 = V_3 -> V_45 . V_53 . V_69 . V_70 ;
if ( F_26 ( V_64 , V_65 ) ) {
F_21 ( & V_3 -> V_45 . V_58 ) ;
F_27 ( & V_3 -> V_45 . V_53 ) ;
F_16 ( & V_3 -> V_45 . V_58 ) ;
F_20 ( V_25 , V_3 -> V_45 . V_46 ,
F_8 ( V_62 ) , true ) ;
}
F_21 ( & V_3 -> V_45 . V_58 ) ;
}
}
static T_1 F_28 ( struct V_25 * V_25 , const char * V_71 ,
T_2 V_72 )
{
unsigned int V_73 ;
int V_74 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 )
return - V_75 ;
F_22 ( V_25 , V_73 ) ;
return V_72 ;
}
static T_1 F_29 ( struct V_25 * V_25 , const char * V_71 ,
T_2 V_72 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_73 ;
int V_74 ;
unsigned int V_76 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 )
return - V_75 ;
V_28 -> V_77 = ! ! V_73 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_76 ) ;
V_3 -> V_45 . V_78 = F_30 ( V_76 ,
& V_3 -> V_45 . V_79 , V_28 -> V_77 ) ;
}
return V_72 ;
}
static T_1 F_31 ( struct V_25 * V_25 , const char * V_71 ,
T_2 V_72 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_73 ;
int V_74 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 || V_73 > V_80 ||
V_73 < V_81 ) {
return - V_75 ;
}
V_28 -> V_51 += V_73 ;
V_28 -> V_51 -= V_28 -> V_47 ;
V_28 -> V_47 = V_73 ;
return V_72 ;
}
static T_1 F_32 ( struct V_25 * V_25 ,
const char * V_71 , T_2 V_72 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_73 , V_76 ;
int V_74 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 || V_73 > V_82 || V_73 < 1 )
return - V_75 ;
V_28 -> V_49 = V_73 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_76 ) ;
V_3 -> V_48 = 1 ;
}
return V_72 ;
}
static T_1 F_33 ( struct V_25 * V_25 ,
const char * V_71 , T_2 V_72 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_73 ;
int V_74 ;
unsigned int V_76 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 )
return - V_75 ;
if ( V_73 > 1 )
V_73 = 1 ;
if ( V_73 == V_28 -> V_83 ) {
return V_72 ;
}
V_28 -> V_83 = V_73 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_76 ) ;
V_3 -> V_45 . V_78 = F_30 ( V_76 ,
& V_3 -> V_45 . V_79 , V_28 -> V_77 ) ;
if ( V_28 -> V_83 )
V_3 -> V_45 . V_84 =
F_34 ( V_76 ) . V_85 [ V_86 ] ;
}
return V_72 ;
}
static T_1 F_35 ( struct V_25 * V_25 , const char * V_71 ,
T_2 V_72 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_73 ;
int V_74 ;
V_74 = sscanf ( V_71 , L_1 , & V_73 ) ;
if ( V_74 != 1 )
return - V_75 ;
if ( V_73 > 1000 )
V_73 = 1000 ;
V_28 -> V_32 = V_73 ;
F_9 () ;
return V_72 ;
}
static int F_36 ( struct V_25 * V_25 )
{
struct V_27 * V_29 ;
T_3 V_87 ;
int V_1 ;
V_29 = F_37 ( sizeof( struct V_27 ) , V_88 ) ;
if ( ! V_29 ) {
F_38 ( L_2 , V_89 ) ;
return - V_90 ;
}
V_1 = F_39 () ;
V_87 = F_40 ( V_1 , NULL ) ;
F_41 () ;
if ( V_87 != - 1ULL ) {
V_29 -> V_47 = V_91 ;
V_29 -> V_51 = V_91 -
V_92 ;
V_25 -> V_63 = V_93 ;
} else {
V_29 -> V_47 = V_94 ;
V_29 -> V_51 = V_94 -
V_95 ;
V_25 -> V_63 = V_96 *
F_42 ( 10 ) ;
}
V_29 -> V_49 = V_97 ;
V_29 -> V_83 = 0 ;
V_29 -> V_32 = V_98 ;
V_29 -> V_77 = F_4 () ;
V_25 -> V_29 = V_29 ;
F_43 ( & V_25 -> V_99 ) ;
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
T_4 V_100 ;
V_98 = V_32 ;
F_47 ( & V_100 ) ;
F_48 () ;
F_10 (cpu) {
if ( F_49 ( V_1 , & V_100 ) )
continue;
V_14 = F_2 ( V_4 , V_1 ) . V_45 . V_46 ;
if ( ! V_14 )
continue;
F_50 ( & V_100 , & V_100 , V_14 -> V_101 ) ;
if ( V_14 -> V_66 != & V_67 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_98 ;
}
F_51 () ;
}
void F_52 ( void )
{
V_40 . V_41 = F_6 ;
F_46 ( 0 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
unsigned int V_102 )
{
return F_54 ( V_14 , & V_103 , V_102 ) ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_67 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_67 ) ;
}
