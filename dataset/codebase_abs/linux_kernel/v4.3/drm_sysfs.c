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
struct V_17 * F_10 ( struct V_18 * V_19 , char * V_20 )
{
struct V_17 * V_17 ;
int V_21 ;
V_17 = F_11 ( V_19 , V_20 ) ;
if ( F_12 ( V_17 ) ) {
V_21 = F_13 ( V_17 ) ;
goto V_22;
}
V_17 -> V_23 = & V_24 ;
V_21 = F_14 ( V_17 , & V_25 . V_26 ) ;
if ( V_21 )
goto V_27;
V_17 -> V_28 = F_7 ;
return V_17 ;
V_27:
F_15 ( V_17 ) ;
V_22:
return F_16 ( V_21 ) ;
}
void F_17 ( void )
{
if ( ( V_29 == NULL ) || ( F_12 ( V_29 ) ) )
return;
F_18 ( V_29 , & V_25 . V_26 ) ;
F_15 ( V_29 ) ;
V_29 = NULL ;
}
static T_3 F_19 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
const char * V_31 , T_4 V_32 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
enum V_35 V_36 ;
int V_37 ;
V_37 = F_21 ( & V_2 -> V_38 . V_39 ) ;
if ( V_37 )
return V_37 ;
V_36 = V_34 -> V_40 ;
if ( F_22 ( V_31 , L_2 ) ) {
V_34 -> V_41 = 0 ;
V_34 -> V_40 = V_34 -> V_42 -> V_43 ( V_34 , true ) ;
} else if ( F_22 ( V_31 , L_3 ) ) {
V_34 -> V_41 = V_44 ;
} else if ( F_22 ( V_31 , L_4 ) ) {
V_34 -> V_41 = V_45 ;
} else if ( F_22 ( V_31 , L_5 ) ) {
V_34 -> V_41 = V_46 ;
} else
V_37 = - V_47 ;
if ( V_37 == 0 && V_34 -> V_41 ) {
if ( V_34 -> V_41 == V_44 ||
V_34 -> V_41 == V_45 )
V_34 -> V_40 = V_48 ;
else
V_34 -> V_40 = V_49 ;
if ( V_34 -> V_42 -> V_41 )
V_34 -> V_42 -> V_41 ( V_34 ) ;
}
if ( V_36 != V_34 -> V_40 ) {
F_23 ( L_6 ,
V_34 -> V_50 . V_51 ,
V_34 -> V_20 ,
V_36 , V_34 -> V_40 ) ;
V_2 -> V_38 . V_52 = true ;
if ( V_2 -> V_38 . V_53 )
F_24 ( & V_2 -> V_38 . V_54 ,
0 ) ;
}
F_25 ( & V_2 -> V_38 . V_39 ) ;
return V_37 ? V_37 : V_32 ;
}
static T_3 F_26 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
return snprintf ( V_31 , V_55 , L_7 ,
F_27 ( V_34 -> V_40 ) ) ;
}
static T_3 F_28 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
int V_56 ;
V_56 = F_29 ( V_34 -> V_56 ) ;
return snprintf ( V_31 , V_55 , L_7 ,
F_30 ( V_56 ) ) ;
}
static T_3 F_31 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
return snprintf ( V_31 , V_55 , L_7 , V_34 -> V_57 ? L_8 :
L_9 ) ;
}
static T_3 F_32 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_26 , char * V_31 , T_5 V_63 ,
T_4 V_32 )
{
struct V_1 * V_64 = F_33 ( V_61 , struct V_1 , V_61 ) ;
struct V_33 * V_34 = F_20 ( V_64 ) ;
unsigned char * V_65 ;
T_4 V_66 ;
if ( ! V_34 -> V_67 )
return 0 ;
V_65 = V_34 -> V_67 -> V_68 ;
V_66 = V_34 -> V_67 -> V_69 ;
if ( ! V_65 )
return 0 ;
if ( V_63 >= V_66 )
return 0 ;
if ( V_63 + V_32 > V_66 )
V_32 = V_66 - V_63 ;
memcpy ( V_31 , V_65 + V_63 , V_32 ) ;
return V_32 ;
}
static T_3 F_34 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_70 * V_15 ;
int V_71 = 0 ;
F_35 (mode, &connector->modes, head) {
V_71 += snprintf ( V_31 + V_71 , V_55 - V_71 , L_7 ,
V_15 -> V_20 ) ;
}
return V_71 ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_72 * V_73 ;
T_6 V_74 ;
int V_37 ;
V_73 = V_2 -> V_38 . V_75 ;
if ( ! V_73 ) {
F_37 ( L_10 ) ;
return 0 ;
}
V_37 = F_38 ( & V_34 -> V_50 , V_73 , & V_74 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_11 ,
F_39 ( ( int ) V_74 ) ) ;
}
static T_3 F_40 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_72 * V_73 ;
T_6 V_74 ;
int V_37 ;
V_73 = V_2 -> V_38 . V_76 ;
if ( ! V_73 ) {
F_37 ( L_12 ) ;
return 0 ;
}
V_37 = F_38 ( & V_34 -> V_50 , V_73 , & V_74 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_11 ,
F_41 ( ( int ) V_74 ) ) ;
}
static T_3 F_42 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_72 * V_73 ;
T_6 V_74 ;
int V_37 ;
V_73 = V_2 -> V_38 . V_77 ;
if ( ! V_73 ) {
F_37 ( L_10 ) ;
return 0 ;
}
V_37 = F_38 ( & V_34 -> V_50 , V_73 , & V_74 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_11 ,
F_43 ( ( int ) V_74 ) ) ;
}
static T_3 F_44 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_72 * V_73 ;
T_6 V_74 ;
int V_37 ;
V_73 = V_2 -> V_38 . V_78 ;
if ( ! V_73 ) {
F_37 ( L_12 ) ;
return 0 ;
}
V_37 = F_38 ( & V_34 -> V_50 , V_73 , & V_74 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_11 ,
F_45 ( ( int ) V_74 ) ) ;
}
static int F_46 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_47 ( V_61 ) ;
struct V_33 * V_34 = F_20 ( V_2 ) ;
return V_34 -> V_79 ;
}
static T_2 F_48 ( struct V_60 * V_61 ,
struct V_80 * V_26 , int V_81 )
{
return F_46 ( V_61 ) == V_82 ?
V_26 -> V_15 : 0 ;
}
static T_2 F_49 ( struct V_60 * V_61 ,
struct V_80 * V_26 , int V_81 )
{
switch ( F_46 ( V_61 ) ) {
case V_83 :
case V_84 :
case V_85 :
case V_86 :
return V_26 -> V_15 ;
}
return 0 ;
}
int F_50 ( struct V_33 * V_34 )
{
struct V_6 * V_2 = V_34 -> V_2 ;
if ( V_34 -> V_87 )
return 0 ;
V_34 -> V_87 =
F_51 ( V_29 , V_2 -> V_88 -> V_87 , 0 ,
V_34 , V_89 ,
L_13 , V_2 -> V_88 -> V_90 ,
V_34 -> V_20 ) ;
F_52 ( L_14 ,
V_34 -> V_20 ) ;
if ( F_12 ( V_34 -> V_87 ) ) {
F_37 ( L_15 , F_13 ( V_34 -> V_87 ) ) ;
return F_13 ( V_34 -> V_87 ) ;
}
F_53 ( V_2 ) ;
return 0 ;
}
void F_54 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_87 )
return;
F_52 ( L_16 ,
V_34 -> V_20 ) ;
F_55 ( V_34 -> V_87 ) ;
V_34 -> V_87 = NULL ;
}
void F_53 ( struct V_6 * V_2 )
{
char * V_91 = L_17 ;
char * V_92 [] = { V_91 , NULL } ;
F_52 ( L_18 ) ;
F_56 ( & V_2 -> V_88 -> V_87 -> V_61 , V_93 , V_92 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
struct V_1 * F_59 ( struct V_5 * V_94 )
{
const char * V_95 ;
struct V_1 * V_87 ;
int V_96 ;
if ( V_94 -> type == V_97 )
V_95 = L_19 ;
else if ( V_94 -> type == V_98 )
V_95 = L_20 ;
else
V_95 = L_21 ;
V_87 = F_60 ( sizeof( * V_87 ) , V_16 ) ;
if ( ! V_87 )
return F_16 ( - V_99 ) ;
F_61 ( V_87 ) ;
V_87 -> V_100 = F_62 ( V_101 , V_94 -> V_90 ) ;
V_87 -> V_17 = V_29 ;
V_87 -> type = & V_4 ;
V_87 -> V_102 = V_94 -> V_2 -> V_2 ;
V_87 -> V_103 = F_57 ;
F_63 ( V_87 , V_94 ) ;
V_96 = F_64 ( V_87 , V_95 , V_94 -> V_90 ) ;
if ( V_96 < 0 )
goto V_104;
return V_87 ;
V_104:
F_65 ( V_87 ) ;
return F_16 ( V_96 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
if ( ! V_29 || F_12 ( V_29 ) )
return - V_105 ;
V_2 -> V_17 = V_29 ;
return F_67 ( V_2 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
return F_55 ( V_2 ) ;
}
