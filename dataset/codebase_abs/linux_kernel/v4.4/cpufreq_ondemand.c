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
if ( ! F_20 ( & V_3 -> V_44 . V_68 ) )
continue;
V_64 = V_69 + F_8 ( V_62 ) ;
V_65 = V_3 -> V_44 . V_68 . V_70 . V_71 ;
if ( F_21 ( V_64 , V_65 ) ) {
F_22 ( & V_3 -> V_44 . V_68 ) ;
F_23 ( V_25 , V_14 ,
F_8 ( V_62 ) , true ) ;
}
}
}
static T_1 F_24 ( struct V_25 * V_25 , const char * V_72 ,
T_2 V_73 )
{
unsigned int V_74 ;
int V_75 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 )
return - V_76 ;
F_17 ( V_25 , V_74 ) ;
return V_73 ;
}
static T_1 F_25 ( struct V_25 * V_25 , const char * V_72 ,
T_2 V_73 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_74 ;
int V_75 ;
unsigned int V_77 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 )
return - V_76 ;
V_28 -> V_78 = ! ! V_74 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_77 ) ;
V_3 -> V_44 . V_79 = F_26 ( V_77 ,
& V_3 -> V_44 . V_80 , V_28 -> V_78 ) ;
}
return V_73 ;
}
static T_1 F_27 ( struct V_25 * V_25 , const char * V_72 ,
T_2 V_73 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_74 ;
int V_75 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 || V_74 > V_81 ||
V_74 < V_82 ) {
return - V_76 ;
}
V_28 -> V_46 = V_74 ;
return V_73 ;
}
static T_1 F_28 ( struct V_25 * V_25 ,
const char * V_72 , T_2 V_73 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_74 , V_77 ;
int V_75 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 || V_74 > V_83 || V_74 < 1 )
return - V_76 ;
V_28 -> V_48 = V_74 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_77 ) ;
V_3 -> V_47 = 1 ;
}
return V_73 ;
}
static T_1 F_29 ( struct V_25 * V_25 ,
const char * V_72 , T_2 V_73 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_74 ;
int V_75 ;
unsigned int V_77 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 )
return - V_76 ;
if ( V_74 > 1 )
V_74 = 1 ;
if ( V_74 == V_28 -> V_84 ) {
return V_73 ;
}
V_28 -> V_84 = V_74 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_77 ) ;
V_3 -> V_44 . V_79 = F_26 ( V_77 ,
& V_3 -> V_44 . V_80 , V_28 -> V_78 ) ;
if ( V_28 -> V_84 )
V_3 -> V_44 . V_85 =
F_30 ( V_77 ) . V_86 [ V_87 ] ;
}
return V_73 ;
}
static T_1 F_31 ( struct V_25 * V_25 , const char * V_72 ,
T_2 V_73 )
{
struct V_27 * V_28 = V_25 -> V_29 ;
unsigned int V_74 ;
int V_75 ;
V_75 = sscanf ( V_72 , L_1 , & V_74 ) ;
if ( V_75 != 1 )
return - V_76 ;
if ( V_74 > 1000 )
V_74 = 1000 ;
V_28 -> V_32 = V_74 ;
F_9 () ;
return V_73 ;
}
static int F_32 ( struct V_25 * V_25 , bool V_88 )
{
struct V_27 * V_29 ;
T_3 V_89 ;
int V_1 ;
V_29 = F_33 ( sizeof( * V_29 ) , V_90 ) ;
if ( ! V_29 ) {
F_34 ( L_2 , V_91 ) ;
return - V_92 ;
}
V_1 = F_35 () ;
V_89 = F_36 ( V_1 , NULL ) ;
F_37 () ;
if ( V_89 != - 1ULL ) {
V_29 -> V_46 = V_93 ;
V_25 -> V_63 = V_94 ;
} else {
V_29 -> V_46 = V_95 ;
V_25 -> V_63 = V_96 *
F_38 ( 10 ) ;
}
V_29 -> V_48 = V_97 ;
V_29 -> V_84 = 0 ;
V_29 -> V_32 = V_98 ;
V_29 -> V_78 = F_4 () ;
V_25 -> V_29 = V_29 ;
return 0 ;
}
static void F_39 ( struct V_25 * V_25 , bool V_88 )
{
F_40 ( V_25 -> V_29 ) ;
}
static void F_41 ( unsigned int V_32 )
{
struct V_13 * V_14 ;
struct V_25 * V_25 ;
struct V_27 * V_28 ;
unsigned int V_1 ;
T_4 V_99 ;
V_98 = V_32 ;
F_42 ( & V_99 ) ;
F_43 () ;
F_10 (cpu) {
struct V_100 * V_45 ;
if ( F_44 ( V_1 , & V_99 ) )
continue;
V_45 = F_2 ( V_4 , V_1 ) . V_44 . V_45 ;
if ( ! V_45 )
continue;
V_14 = V_45 -> V_14 ;
F_45 ( & V_99 , & V_99 , V_14 -> V_101 ) ;
if ( V_14 -> V_66 != & V_67 )
continue;
V_25 = V_14 -> V_26 ;
V_28 = V_25 -> V_29 ;
V_28 -> V_32 = V_98 ;
}
F_46 () ;
}
void F_47 ( void )
{
V_39 . V_40 = F_6 ;
F_41 ( 0 ) ;
}
static int F_48 ( struct V_13 * V_14 ,
unsigned int V_102 )
{
return F_49 ( V_14 , & V_103 , V_102 ) ;
}
static int T_5 F_50 ( void )
{
return F_51 ( & V_67 ) ;
}
static void T_6 F_52 ( void )
{
F_53 ( & V_67 ) ;
}
