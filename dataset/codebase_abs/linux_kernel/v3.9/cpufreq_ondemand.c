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
if ( ! V_3 -> V_5 ) {
V_3 -> V_6 = 0 ;
V_3 -> V_25 = 0 ;
return V_15 ;
}
F_7 ( V_14 , V_3 -> V_5 , V_15 ,
V_16 , & V_21 ) ;
V_17 = V_3 -> V_5 [ V_21 ] . V_26 ;
V_18 = V_17 * V_27 . V_28 / 1000 ;
V_19 = V_17 - V_18 ;
V_21 = 0 ;
F_7 ( V_14 , V_3 -> V_5 , V_19 ,
V_29 , & V_21 ) ;
V_6 = V_3 -> V_5 [ V_21 ] . V_26 ;
V_21 = 0 ;
F_7 ( V_14 , V_3 -> V_5 , V_19 ,
V_30 , & V_21 ) ;
V_20 = V_3 -> V_5 [ V_21 ] . V_26 ;
if ( V_20 == V_6 ) {
V_3 -> V_6 = 0 ;
V_3 -> V_25 = 0 ;
return V_6 ;
}
V_22 = F_8 ( V_27 . V_31 ) ;
V_23 = ( V_19 - V_6 ) * V_22 ;
V_23 += ( ( V_20 - V_6 ) / 2 ) ;
V_23 /= ( V_20 - V_6 ) ;
V_24 = V_22 - V_23 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_25 = V_24 ;
V_3 -> V_32 = V_23 ;
return V_20 ;
}
static void F_9 ( void )
{
int V_33 ;
F_10 (i) {
F_1 ( V_33 ) ;
}
}
static void F_11 ( struct V_13 * V_34 , unsigned int V_35 )
{
if ( V_27 . V_28 )
V_35 = F_6 ( V_34 , V_35 , V_29 ) ;
else if ( V_34 -> V_36 == V_34 -> V_37 )
return;
F_12 ( V_34 , V_35 , V_27 . V_28 ?
V_30 : V_29 ) ;
}
static void F_13 ( int V_1 , unsigned int V_38 )
{
struct V_2 * V_3 = & F_2 ( V_4 , V_1 ) ;
struct V_13 * V_14 = V_3 -> V_39 . V_40 ;
V_3 -> V_6 = 0 ;
if ( V_38 > V_27 . V_41 * V_14 -> V_36 ) {
if ( V_14 -> V_36 < V_14 -> V_37 )
V_3 -> V_42 =
V_27 . V_43 ;
F_11 ( V_14 , V_14 -> V_37 ) ;
return;
}
if ( V_14 -> V_36 == V_14 -> V_44 )
return;
if ( V_38 < V_27 . V_45 * V_14 -> V_36 ) {
unsigned int V_15 ;
V_15 = V_38 / V_27 . V_45 ;
V_3 -> V_42 = 1 ;
if ( V_15 < V_14 -> V_44 )
V_15 = V_14 -> V_44 ;
if ( ! V_27 . V_28 ) {
F_12 ( V_14 , V_15 ,
V_30 ) ;
} else {
int V_35 = F_6 ( V_14 , V_15 ,
V_30 ) ;
F_12 ( V_14 , V_35 ,
V_30 ) ;
}
}
}
static void F_14 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = F_15 ( V_47 ) ;
struct V_2 * V_3 =
F_16 ( V_47 , struct V_2 , V_39 . V_47 . V_47 ) ;
unsigned int V_1 = V_3 -> V_39 . V_40 -> V_1 ;
struct V_2 * V_50 = & F_2 ( V_4 ,
V_1 ) ;
int V_51 , V_52 = V_50 -> V_52 ;
bool V_53 ;
F_17 ( & V_50 -> V_39 . V_54 ) ;
V_53 = F_18 ( & V_50 -> V_39 ,
V_27 . V_31 ) ;
V_50 -> V_52 = V_55 ;
if ( V_52 == V_56 ) {
V_51 = V_50 -> V_25 ;
if ( V_53 )
F_12 ( V_50 -> V_39 . V_40 ,
V_50 -> V_6 ,
V_29 ) ;
} else {
if ( V_53 )
F_19 ( & V_57 , V_1 ) ;
if ( V_50 -> V_6 ) {
V_50 -> V_52 = V_56 ;
V_51 = V_50 -> V_32 ;
} else {
V_51 = F_20 ( V_27 . V_31
* V_50 -> V_42 ) ;
}
}
F_21 ( F_22 () , V_49 , V_51 ) ;
F_23 ( & V_50 -> V_39 . V_54 ) ;
}
static T_1 F_24 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
return sprintf ( V_62 , L_1 , V_57 . V_63 ) ;
}
static void F_25 ( unsigned int V_64 )
{
int V_1 ;
V_27 . V_31 = V_64 = V_37 ( V_64 ,
V_57 . V_63 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_65 , V_66 ;
V_14 = F_26 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_67 != & V_68 ) {
F_27 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_1 ) ;
F_27 ( V_14 ) ;
F_17 ( & V_3 -> V_39 . V_54 ) ;
if ( ! F_28 ( & V_3 -> V_39 . V_47 ) ) {
F_23 ( & V_3 -> V_39 . V_54 ) ;
continue;
}
V_65 = V_69 + F_8 ( V_64 ) ;
V_66 = V_3 -> V_39 . V_47 . V_70 . V_71 ;
if ( F_29 ( V_65 , V_66 ) ) {
F_23 ( & V_3 -> V_39 . V_54 ) ;
F_30 ( & V_3 -> V_39 . V_47 ) ;
F_17 ( & V_3 -> V_39 . V_54 ) ;
F_21 ( V_1 , & V_3 -> V_39 . V_47 ,
F_8 ( V_64 ) ) ;
}
F_23 ( & V_3 -> V_39 . V_54 ) ;
}
}
static T_1 F_31 ( struct V_58 * V_72 , struct V_60 * V_73 ,
const char * V_62 , T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
F_25 ( V_75 ) ;
return V_74 ;
}
static T_1 F_32 ( struct V_58 * V_72 , struct V_60 * V_73 ,
const char * V_62 , T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
V_27 . V_78 = ! ! V_75 ;
return V_74 ;
}
static T_1 F_33 ( struct V_58 * V_72 , struct V_60 * V_73 ,
const char * V_62 , T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 || V_75 > V_79 ||
V_75 < V_80 ) {
return - V_77 ;
}
V_27 . V_45 += V_75 ;
V_27 . V_45 -= V_27 . V_41 ;
V_27 . V_41 = V_75 ;
return V_74 ;
}
static T_1 F_34 ( struct V_58 * V_72 ,
struct V_60 * V_73 , const char * V_62 , T_2 V_74 )
{
unsigned int V_75 , V_81 ;
int V_76 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 || V_75 > V_82 || V_75 < 1 )
return - V_77 ;
V_27 . V_43 = V_75 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_81 ) ;
V_3 -> V_42 = 1 ;
}
return V_74 ;
}
static T_1 F_35 ( struct V_58 * V_72 , struct V_60 * V_73 ,
const char * V_62 , T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
unsigned int V_81 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
if ( V_75 > 1 )
V_75 = 1 ;
if ( V_75 == V_27 . V_83 ) {
return V_74 ;
}
V_27 . V_83 = V_75 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_81 ) ;
V_3 -> V_39 . V_84 = F_36 ( V_81 ,
& V_3 -> V_39 . V_85 ) ;
if ( V_27 . V_83 )
V_3 -> V_39 . V_86 =
F_37 ( V_81 ) . V_87 [ V_88 ] ;
}
return V_74 ;
}
static T_1 F_38 ( struct V_58 * V_72 , struct V_60 * V_73 ,
const char * V_62 , T_2 V_74 )
{
unsigned int V_75 ;
int V_76 ;
V_76 = sscanf ( V_62 , L_2 , & V_75 ) ;
if ( V_76 != 1 )
return - V_77 ;
if ( V_75 > 1000 )
V_75 = 1000 ;
V_27 . V_28 = V_75 ;
F_9 () ;
return V_74 ;
}
static int F_39 ( struct V_13 * V_14 ,
unsigned int V_89 )
{
return F_40 ( & V_57 , V_14 , V_89 ) ;
}
static int T_3 F_41 ( void )
{
T_4 V_90 ;
int V_1 = F_42 () ;
F_43 ( & V_57 . V_91 ) ;
V_90 = F_44 ( V_1 , NULL ) ;
F_45 () ;
if ( V_90 != - 1ULL ) {
V_27 . V_41 = V_92 ;
V_27 . V_45 = V_92 -
V_93 ;
V_57 . V_63 = V_94 ;
} else {
V_57 . V_63 = V_95 *
F_46 ( 10 ) ;
}
return F_47 ( & V_68 ) ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_68 ) ;
}
