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
if ( F_22 ( V_26 , L_3 ) ) {
V_29 -> V_36 = 0 ;
V_29 -> V_35 = V_29 -> V_37 -> V_38 ( V_29 , true ) ;
} else if ( F_22 ( V_26 , L_4 ) ) {
V_29 -> V_36 = V_39 ;
} else if ( F_22 ( V_26 , L_5 ) ) {
V_29 -> V_36 = V_40 ;
} else if ( F_22 ( V_26 , L_6 ) ) {
V_29 -> V_36 = V_41 ;
} else
V_32 = - V_42 ;
if ( V_32 == 0 && V_29 -> V_36 ) {
if ( V_29 -> V_36 == V_39 ||
V_29 -> V_36 == V_40 )
V_29 -> V_35 = V_43 ;
else
V_29 -> V_35 = V_44 ;
if ( V_29 -> V_37 -> V_36 )
V_29 -> V_37 -> V_36 ( V_29 ) ;
}
if ( V_31 != V_29 -> V_35 ) {
F_23 ( L_7 ,
V_29 -> V_45 . V_46 ,
V_29 -> V_47 ,
V_31 , V_29 -> V_35 ) ;
V_2 -> V_33 . V_48 = true ;
if ( V_2 -> V_33 . V_49 )
F_24 ( & V_2 -> V_33 . V_50 ,
0 ) ;
}
F_25 ( & V_2 -> V_33 . V_34 ) ;
return V_32 ? V_32 : V_27 ;
}
static T_3 F_26 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
return snprintf ( V_26 , V_51 , L_8 ,
F_27 ( V_29 -> V_35 ) ) ;
}
static T_3 F_28 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
int V_52 ;
V_52 = F_29 ( V_29 -> V_52 ) ;
return snprintf ( V_26 , V_51 , L_8 ,
F_30 ( V_52 ) ) ;
}
static T_3 F_31 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
return snprintf ( V_26 , V_51 , L_8 , V_29 -> V_53 ? L_9 :
L_10 ) ;
}
static T_3 F_32 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_58 * V_23 , char * V_26 , T_5 V_59 ,
T_4 V_27 )
{
struct V_1 * V_60 = F_33 ( V_57 , struct V_1 , V_57 ) ;
struct V_28 * V_29 = F_20 ( V_60 ) ;
unsigned char * V_61 ;
T_4 V_62 ;
if ( ! V_29 -> V_63 )
return 0 ;
V_61 = V_29 -> V_63 -> V_64 ;
V_62 = V_29 -> V_63 -> V_65 ;
if ( ! V_61 )
return 0 ;
if ( V_59 >= V_62 )
return 0 ;
if ( V_59 + V_27 > V_62 )
V_27 = V_62 - V_59 ;
memcpy ( V_26 , V_61 + V_59 , V_27 ) ;
return V_27 ;
}
static T_3 F_34 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_66 * V_15 ;
int V_67 = 0 ;
F_35 (mode, &connector->modes, head) {
V_67 += snprintf ( V_26 + V_67 , V_51 - V_67 , L_8 ,
V_15 -> V_47 ) ;
}
return V_67 ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_68 * V_69 ;
T_6 V_70 ;
int V_32 ;
V_69 = V_2 -> V_33 . V_71 ;
if ( ! V_69 ) {
F_37 ( L_11 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_45 , V_69 , & V_70 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_51 , L_12 ,
F_39 ( ( int ) V_70 ) ) ;
}
static T_3 F_40 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_68 * V_69 ;
T_6 V_70 ;
int V_32 ;
V_69 = V_2 -> V_33 . V_72 ;
if ( ! V_69 ) {
F_37 ( L_13 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_45 , V_69 , & V_70 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_51 , L_12 ,
F_41 ( ( int ) V_70 ) ) ;
}
static T_3 F_42 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_68 * V_69 ;
T_6 V_70 ;
int V_32 ;
V_69 = V_2 -> V_33 . V_73 ;
if ( ! V_69 ) {
F_37 ( L_11 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_45 , V_69 , & V_70 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_51 , L_12 ,
F_43 ( ( int ) V_70 ) ) ;
}
static T_3 F_44 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_29 -> V_2 ;
struct V_68 * V_69 ;
T_6 V_70 ;
int V_32 ;
V_69 = V_2 -> V_33 . V_74 ;
if ( ! V_69 ) {
F_37 ( L_13 ) ;
return 0 ;
}
V_32 = F_38 ( & V_29 -> V_45 , V_69 , & V_70 ) ;
if ( V_32 )
return 0 ;
return snprintf ( V_26 , V_51 , L_12 ,
F_45 ( ( int ) V_70 ) ) ;
}
static int F_46 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_47 ( V_57 ) ;
struct V_28 * V_29 = F_20 ( V_2 ) ;
return V_29 -> V_75 ;
}
static T_2 F_48 ( struct V_56 * V_57 ,
struct V_76 * V_23 , int V_77 )
{
return F_46 ( V_57 ) == V_78 ?
V_23 -> V_15 : 0 ;
}
static T_2 F_49 ( struct V_56 * V_57 ,
struct V_76 * V_23 , int V_77 )
{
switch ( F_46 ( V_57 ) ) {
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return V_23 -> V_15 ;
}
return 0 ;
}
int F_50 ( struct V_28 * V_29 )
{
struct V_6 * V_2 = V_29 -> V_2 ;
if ( V_29 -> V_83 )
return 0 ;
V_29 -> V_83 =
F_51 ( V_18 , V_2 -> V_84 -> V_83 , 0 ,
V_29 , V_85 ,
L_14 , V_2 -> V_84 -> V_86 ,
V_29 -> V_47 ) ;
F_52 ( L_15 ,
V_29 -> V_47 ) ;
if ( F_12 ( V_29 -> V_83 ) ) {
F_37 ( L_16 , F_13 ( V_29 -> V_83 ) ) ;
return F_13 ( V_29 -> V_83 ) ;
}
F_53 ( V_2 ) ;
return 0 ;
}
void F_54 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_83 )
return;
F_52 ( L_17 ,
V_29 -> V_47 ) ;
F_55 ( V_29 -> V_83 ) ;
V_29 -> V_83 = NULL ;
}
void F_53 ( struct V_6 * V_2 )
{
char * V_87 = L_18 ;
char * V_88 [] = { V_87 , NULL } ;
F_52 ( L_19 ) ;
F_56 ( & V_2 -> V_84 -> V_83 -> V_57 , V_89 , V_88 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( V_2 ) ;
}
struct V_1 * F_59 ( struct V_5 * V_90 )
{
const char * V_91 ;
struct V_1 * V_83 ;
int V_92 ;
if ( V_90 -> type == V_93 )
V_91 = L_20 ;
else if ( V_90 -> type == V_94 )
V_91 = L_21 ;
else
V_91 = L_22 ;
V_83 = F_60 ( sizeof( * V_83 ) , V_16 ) ;
if ( ! V_83 )
return F_61 ( - V_95 ) ;
F_62 ( V_83 ) ;
V_83 -> V_96 = F_63 ( V_97 , V_90 -> V_86 ) ;
V_83 -> V_98 = V_18 ;
V_83 -> type = & V_4 ;
V_83 -> V_99 = V_90 -> V_2 -> V_2 ;
V_83 -> V_100 = F_57 ;
F_64 ( V_83 , V_90 ) ;
V_92 = F_65 ( V_83 , V_91 , V_90 -> V_86 ) ;
if ( V_92 < 0 )
goto V_101;
return V_83 ;
V_101:
F_66 ( V_83 ) ;
return F_61 ( V_92 ) ;
}
int F_67 ( struct V_1 * V_2 )
{
if ( ! V_18 || F_12 ( V_18 ) )
return - V_102 ;
V_2 -> V_98 = V_18 ;
return F_68 ( V_2 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
return F_55 ( V_2 ) ;
}
