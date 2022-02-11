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
if ( V_38 < ( V_27 . V_41 - V_27 . V_45 ) *
V_14 -> V_36 ) {
unsigned int V_15 ;
V_15 = V_38 / ( V_27 . V_41 -
V_27 . V_45 ) ;
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
struct V_2 * V_3 =
F_15 ( V_47 , struct V_2 , V_39 . V_47 . V_47 ) ;
unsigned int V_1 = V_3 -> V_39 . V_1 ;
int V_48 , V_49 = V_3 -> V_49 ;
F_16 ( & V_3 -> V_39 . V_50 ) ;
V_3 -> V_49 = V_51 ;
if ( V_49 == V_52 ) {
V_48 = V_3 -> V_25 ;
F_12 ( V_3 -> V_39 . V_40 ,
V_3 -> V_6 , V_29 ) ;
} else {
F_17 ( & V_53 , V_1 ) ;
if ( V_3 -> V_6 ) {
V_3 -> V_49 = V_52 ;
V_48 = V_3 -> V_32 ;
} else {
V_48 = F_18 ( V_27 . V_31
* V_3 -> V_42 ) ;
}
}
F_19 ( V_1 , & V_3 -> V_39 . V_47 , V_48 ) ;
F_20 ( & V_3 -> V_39 . V_50 ) ;
}
static T_1 F_21 ( struct V_54 * V_55 ,
struct V_56 * V_57 , char * V_58 )
{
return sprintf ( V_58 , L_1 , V_53 . V_59 ) ;
}
static void F_22 ( unsigned int V_60 )
{
int V_1 ;
V_27 . V_31 = V_60 = V_37 ( V_60 ,
V_53 . V_59 ) ;
F_10 (cpu) {
struct V_13 * V_14 ;
struct V_2 * V_3 ;
unsigned long V_61 , V_62 ;
V_14 = F_23 ( V_1 ) ;
if ( ! V_14 )
continue;
if ( V_14 -> V_63 != & V_64 ) {
F_24 ( V_14 ) ;
continue;
}
V_3 = & F_2 ( V_4 , V_14 -> V_1 ) ;
F_24 ( V_14 ) ;
F_16 ( & V_3 -> V_39 . V_50 ) ;
if ( ! F_25 ( & V_3 -> V_39 . V_47 ) ) {
F_20 ( & V_3 -> V_39 . V_50 ) ;
continue;
}
V_61 = V_65 + F_8 ( V_60 ) ;
V_62 = V_3 -> V_39 . V_47 . V_66 . V_67 ;
if ( F_26 ( V_61 , V_62 ) ) {
F_20 ( & V_3 -> V_39 . V_50 ) ;
F_27 ( & V_3 -> V_39 . V_47 ) ;
F_16 ( & V_3 -> V_39 . V_50 ) ;
F_19 ( V_3 -> V_39 . V_1 ,
& V_3 -> V_39 . V_47 ,
F_8 ( V_60 ) ) ;
}
F_20 ( & V_3 -> V_39 . V_50 ) ;
}
}
static T_1 F_28 ( struct V_54 * V_68 , struct V_56 * V_69 ,
const char * V_58 , T_2 V_70 )
{
unsigned int V_71 ;
int V_72 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 )
return - V_73 ;
F_22 ( V_71 ) ;
return V_70 ;
}
static T_1 F_29 ( struct V_54 * V_68 , struct V_56 * V_69 ,
const char * V_58 , T_2 V_70 )
{
unsigned int V_71 ;
int V_72 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 )
return - V_73 ;
V_27 . V_74 = ! ! V_71 ;
return V_70 ;
}
static T_1 F_30 ( struct V_54 * V_68 , struct V_56 * V_69 ,
const char * V_58 , T_2 V_70 )
{
unsigned int V_71 ;
int V_72 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 || V_71 > V_75 ||
V_71 < V_76 ) {
return - V_73 ;
}
V_27 . V_41 = V_71 ;
return V_70 ;
}
static T_1 F_31 ( struct V_54 * V_68 ,
struct V_56 * V_69 , const char * V_58 , T_2 V_70 )
{
unsigned int V_71 , V_77 ;
int V_72 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 || V_71 > V_78 || V_71 < 1 )
return - V_73 ;
V_27 . V_43 = V_71 ;
F_10 (j) {
struct V_2 * V_3 = & F_2 ( V_4 ,
V_77 ) ;
V_3 -> V_42 = 1 ;
}
return V_70 ;
}
static T_1 F_32 ( struct V_54 * V_68 , struct V_56 * V_69 ,
const char * V_58 , T_2 V_70 )
{
unsigned int V_71 ;
int V_72 ;
unsigned int V_77 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 )
return - V_73 ;
if ( V_71 > 1 )
V_71 = 1 ;
if ( V_71 == V_27 . V_79 ) {
return V_70 ;
}
V_27 . V_79 = V_71 ;
F_10 (j) {
struct V_2 * V_3 ;
V_3 = & F_2 ( V_4 , V_77 ) ;
V_3 -> V_39 . V_80 = F_33 ( V_77 ,
& V_3 -> V_39 . V_81 ) ;
if ( V_27 . V_79 )
V_3 -> V_39 . V_82 =
F_34 ( V_77 ) . V_83 [ V_84 ] ;
}
return V_70 ;
}
static T_1 F_35 ( struct V_54 * V_68 , struct V_56 * V_69 ,
const char * V_58 , T_2 V_70 )
{
unsigned int V_71 ;
int V_72 ;
V_72 = sscanf ( V_58 , L_2 , & V_71 ) ;
if ( V_72 != 1 )
return - V_73 ;
if ( V_71 > 1000 )
V_71 = 1000 ;
V_27 . V_28 = V_71 ;
F_9 () ;
return V_70 ;
}
static int F_36 ( struct V_13 * V_14 ,
unsigned int V_85 )
{
return F_37 ( & V_53 , V_14 , V_85 ) ;
}
static int T_3 F_38 ( void )
{
T_4 V_86 ;
int V_1 = F_39 () ;
F_40 ( & V_53 . V_87 ) ;
V_86 = F_41 ( V_1 , NULL ) ;
F_42 () ;
if ( V_86 != - 1ULL ) {
V_27 . V_41 = V_88 ;
V_27 . V_45 = V_89 ;
V_53 . V_59 = V_90 ;
} else {
V_53 . V_59 = V_91 *
F_43 ( 10 ) ;
}
return F_44 ( & V_64 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_64 ) ;
}
