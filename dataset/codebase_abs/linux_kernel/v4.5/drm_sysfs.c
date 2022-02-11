static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> type == & V_4 ) {
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 ;
if ( V_5 -> type == V_8 &&
! F_3 ( V_7 , V_9 ) &&
V_7 -> V_10 -> V_11 )
return V_7 -> V_10 -> V_11 ( V_7 , V_3 ) ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> type == & V_4 ) {
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 ;
if ( V_5 -> type == V_8 &&
! F_3 ( V_7 , V_9 ) &&
V_7 -> V_10 -> V_14 )
return V_7 -> V_10 -> V_14 ( V_7 ) ;
}
return 0 ;
}
static char * F_7 ( struct V_1 * V_2 , T_2 * V_15 )
{
return F_8 ( V_16 , L_1 , F_9 ( V_2 ) ) ;
}
int F_10 ( void )
{
int V_17 ;
V_18 = F_11 ( V_19 , L_2 ) ;
if ( F_12 ( V_18 ) )
return F_13 ( V_18 ) ;
V_18 -> V_20 = & V_21 ;
V_17 = F_14 ( V_18 , & V_22 . V_23 ) ;
if ( V_17 ) {
F_15 ( V_18 ) ;
V_18 = NULL ;
return V_17 ;
}
V_18 -> V_24 = F_7 ;
return 0 ;
}
void F_16 ( void )
{
if ( F_17 ( V_18 ) )
return;
F_18 ( V_18 , & V_22 . V_23 ) ;
F_15 ( V_18 ) ;
V_18 = NULL ;
}
static T_3 F_19 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
const char * V_26 , T_4 V_27 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
enum V_30 V_31 ;
int V_32 ;
V_32 = F_21 ( & V_2 -> V_33 . V_34 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_29 -> V_35 ;
if ( F_22 ( V_26 , L_3 ) )
V_29 -> V_35 = 0 ;
else if ( F_22 ( V_26 , L_4 ) )
V_29 -> V_35 = V_36 ;
else if ( F_22 ( V_26 , L_5 ) )
V_29 -> V_35 = V_37 ;
else if ( F_22 ( V_26 , L_6 ) )
V_29 -> V_35 = V_38 ;
else
V_32 = - V_39 ;
if ( V_31 != V_29 -> V_35 || ! V_29 -> V_35 ) {
F_23 ( L_7 ,
V_29 -> V_40 . V_41 ,
V_29 -> V_42 ,
V_31 , V_29 -> V_35 ) ;
V_29 -> V_43 -> V_44 ( V_29 ,
V_2 -> V_33 . V_45 ,
V_2 -> V_33 . V_46 ) ;
}
F_24 ( & V_2 -> V_33 . V_34 ) ;
return V_32 ? V_32 : V_27 ;
}
static T_3 F_25 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
return snprintf ( V_26 , V_47 , L_8 ,
F_26 ( V_29 -> V_48 ) ) ;
}
static T_3 F_27 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
int V_49 ;
V_49 = F_28 ( V_29 -> V_49 ) ;
return snprintf ( V_26 , V_47 , L_8 ,
F_29 ( V_49 ) ) ;
}
static T_3 F_30 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
return snprintf ( V_26 , V_47 , L_8 , V_29 -> V_50 ? L_9 :
L_10 ) ;
}
static T_3 F_31 ( struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_55 * V_23 , char * V_26 , T_5 V_56 ,
T_4 V_27 )
{
struct V_1 * V_57 = F_32 ( V_54 ) ;
struct V_28 * V_29 = F_20 ( V_57 ) ;
unsigned char * V_58 ;
T_4 V_59 ;
T_3 V_32 = 0 ;
F_33 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
if ( ! V_29 -> V_60 )
goto V_61;
V_58 = V_29 -> V_60 -> V_62 ;
V_59 = V_29 -> V_60 -> V_63 ;
if ( ! V_58 )
goto V_61;
if ( V_56 >= V_59 )
goto V_61;
if ( V_56 + V_27 > V_59 )
V_27 = V_59 - V_56 ;
memcpy ( V_26 , V_58 + V_56 , V_27 ) ;
V_32 = V_27 ;
V_61:
F_24 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
return V_32 ;
}
static T_3 F_34 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_64 * V_15 ;
int V_65 = 0 ;
F_33 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
F_35 (mode, &connector->modes, head) {
V_65 += snprintf ( V_26 + V_65 , V_47 - V_65 , L_8 ,
V_15 -> V_42 ) ;
}
F_24 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
return V_65 ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_66 * V_67 ;
T_6 V_68 ;
int V_32 ;
V_67 = V_2 -> V_33 . V_69 ;
if ( ! V_67 ) {
F_37 ( L_11 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_40 , V_67 , & V_68 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_47 , L_12 ,
F_39 ( ( int ) V_68 ) ) ;
}
static T_3 F_40 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_66 * V_67 ;
T_6 V_68 ;
int V_32 ;
V_67 = V_2 -> V_33 . V_70 ;
if ( ! V_67 ) {
F_37 ( L_13 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_40 , V_67 , & V_68 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_47 , L_12 ,
F_41 ( ( int ) V_68 ) ) ;
}
static T_3 F_42 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_66 * V_67 ;
T_6 V_68 ;
int V_32 ;
V_67 = V_2 -> V_33 . V_71 ;
if ( ! V_67 ) {
F_37 ( L_11 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_40 , V_67 , & V_68 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_47 , L_12 ,
F_43 ( ( int ) V_68 ) ) ;
}
static T_3 F_44 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_66 * V_67 ;
T_6 V_68 ;
int V_32 ;
V_67 = V_2 -> V_33 . V_72 ;
if ( ! V_67 ) {
F_37 ( L_13 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_40 , V_67 , & V_68 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_47 , L_12 ,
F_45 ( ( int ) V_68 ) ) ;
}
static int F_46 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_32 ( V_54 ) ;
struct V_28 * V_29 = F_20 ( V_2 ) ;
return V_29 -> V_73 ;
}
static T_2 F_47 ( struct V_53 * V_54 ,
struct V_74 * V_23 , int V_75 )
{
return F_46 ( V_54 ) == V_76 ?
V_23 -> V_15 : 0 ;
}
static T_2 F_48 ( struct V_53 * V_54 ,
struct V_74 * V_23 , int V_75 )
{
switch ( F_46 ( V_54 ) ) {
case V_77 :
case V_78 :
case V_79 :
case V_80 :
return V_23 -> V_15 ;
}
return 0 ;
}
int F_49 ( struct V_28 * V_29 )
{
struct V_6 * V_2 = V_29 -> V_2 ;
if ( V_29 -> V_81 )
return 0 ;
V_29 -> V_81 =
F_50 ( V_18 , V_2 -> V_82 -> V_81 , 0 ,
V_29 , V_83 ,
L_14 , V_2 -> V_82 -> V_84 ,
V_29 -> V_42 ) ;
F_51 ( L_15 ,
V_29 -> V_42 ) ;
if ( F_12 ( V_29 -> V_81 ) ) {
F_37 ( L_16 , F_13 ( V_29 -> V_81 ) ) ;
return F_13 ( V_29 -> V_81 ) ;
}
F_52 ( V_2 ) ;
return 0 ;
}
void F_53 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_81 )
return;
F_51 ( L_17 ,
V_29 -> V_42 ) ;
F_54 ( V_29 -> V_81 ) ;
V_29 -> V_81 = NULL ;
}
void F_52 ( struct V_6 * V_2 )
{
char * V_85 = L_18 ;
char * V_86 [] = { V_85 , NULL } ;
F_51 ( L_19 ) ;
F_55 ( & V_2 -> V_82 -> V_81 -> V_54 , V_87 , V_86 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
}
struct V_1 * F_58 ( struct V_5 * V_88 )
{
const char * V_89 ;
struct V_1 * V_81 ;
int V_90 ;
if ( V_88 -> type == V_91 )
V_89 = L_20 ;
else if ( V_88 -> type == V_92 )
V_89 = L_21 ;
else
V_89 = L_22 ;
V_81 = F_59 ( sizeof( * V_81 ) , V_16 ) ;
if ( ! V_81 )
return F_60 ( - V_93 ) ;
F_61 ( V_81 ) ;
V_81 -> V_94 = F_62 ( V_95 , V_88 -> V_84 ) ;
V_81 -> V_96 = V_18 ;
V_81 -> type = & V_4 ;
V_81 -> V_97 = V_88 -> V_2 -> V_2 ;
V_81 -> V_98 = F_56 ;
F_63 ( V_81 , V_88 ) ;
V_90 = F_64 ( V_81 , V_89 , V_88 -> V_84 ) ;
if ( V_90 < 0 )
goto V_99;
return V_81 ;
V_99:
F_65 ( V_81 ) ;
return F_60 ( V_90 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
if ( ! V_18 || F_12 ( V_18 ) )
return - V_100 ;
V_2 -> V_96 = V_18 ;
return F_67 ( V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
return F_54 ( V_2 ) ;
}
