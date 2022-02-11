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
struct V_6 * V_2 = V_34 -> V_2 ;
T_5 V_56 ;
int V_37 ;
V_37 = F_29 ( & V_34 -> V_50 ,
V_2 -> V_38 . V_57 ,
& V_56 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_7 ,
F_30 ( ( int ) V_56 ) ) ;
}
static T_3 F_31 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
return snprintf ( V_31 , V_55 , L_7 , V_34 -> V_58 ? L_8 :
L_9 ) ;
}
static T_3 F_32 ( struct V_59 * V_60 , struct V_61 * V_62 ,
struct V_63 * V_26 , char * V_31 , T_6 V_64 ,
T_4 V_32 )
{
struct V_1 * V_65 = F_33 ( V_62 , struct V_1 , V_62 ) ;
struct V_33 * V_34 = F_20 ( V_65 ) ;
unsigned char * V_66 ;
T_4 V_67 ;
if ( ! V_34 -> V_68 )
return 0 ;
V_66 = V_34 -> V_68 -> V_69 ;
V_67 = V_34 -> V_68 -> V_70 ;
if ( ! V_66 )
return 0 ;
if ( V_64 >= V_67 )
return 0 ;
if ( V_64 + V_32 > V_67 )
V_32 = V_67 - V_64 ;
memcpy ( V_31 , V_66 + V_64 , V_32 ) ;
return V_32 ;
}
static T_3 F_34 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_71 * V_15 ;
int V_72 = 0 ;
F_35 (mode, &connector->modes, head) {
V_72 += snprintf ( V_31 + V_72 , V_55 - V_72 , L_7 ,
V_15 -> V_20 ) ;
}
return V_72 ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_73 * V_74 = NULL ;
T_5 V_75 ;
int V_76 = 0 ;
int V_37 ;
switch ( V_34 -> V_77 ) {
case V_78 :
V_74 = V_2 -> V_38 . V_79 ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_74 = V_2 -> V_38 . V_84 ;
V_76 = 1 ;
break;
default:
F_37 ( L_10 ) ;
return 0 ;
}
if ( ! V_74 ) {
F_37 ( L_11 ) ;
return 0 ;
}
V_37 = F_29 ( & V_34 -> V_50 , V_74 , & V_75 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_12 , V_76 ?
F_38 ( ( int ) V_75 ) :
F_39 ( ( int ) V_75 ) ) ;
}
static T_3 F_40 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_33 * V_34 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_34 -> V_2 ;
struct V_73 * V_74 = NULL ;
T_5 V_75 ;
int V_76 = 0 ;
int V_37 ;
switch ( V_34 -> V_77 ) {
case V_78 :
V_74 = V_2 -> V_38 . V_85 ;
break;
case V_80 :
case V_81 :
case V_82 :
case V_83 :
V_74 = V_2 -> V_38 . V_86 ;
V_76 = 1 ;
break;
default:
F_37 ( L_10 ) ;
return 0 ;
}
if ( ! V_74 ) {
F_37 ( L_13 ) ;
return 0 ;
}
V_37 = F_29 ( & V_34 -> V_50 , V_74 , & V_75 ) ;
if ( V_37 )
return 0 ;
return snprintf ( V_31 , V_55 , L_12 , V_76 ?
F_41 ( ( int ) V_75 ) :
F_42 ( ( int ) V_75 ) ) ;
}
static T_2 F_43 ( struct V_61 * V_62 ,
struct V_87 * V_26 , int V_88 )
{
struct V_1 * V_2 = F_44 ( V_62 ) ;
struct V_33 * V_34 = F_20 ( V_2 ) ;
switch ( V_34 -> V_77 ) {
case V_78 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
return V_26 -> V_15 ;
}
return 0 ;
}
int F_45 ( struct V_33 * V_34 )
{
struct V_6 * V_2 = V_34 -> V_2 ;
if ( V_34 -> V_89 )
return 0 ;
V_34 -> V_89 =
F_46 ( V_29 , V_2 -> V_90 -> V_89 , 0 ,
V_34 , V_91 ,
L_14 , V_2 -> V_90 -> V_92 ,
V_34 -> V_20 ) ;
F_47 ( L_15 ,
V_34 -> V_20 ) ;
if ( F_12 ( V_34 -> V_89 ) ) {
F_37 ( L_16 , F_13 ( V_34 -> V_89 ) ) ;
return F_13 ( V_34 -> V_89 ) ;
}
F_48 ( V_2 ) ;
return 0 ;
}
void F_49 ( struct V_33 * V_34 )
{
if ( ! V_34 -> V_89 )
return;
F_47 ( L_17 ,
V_34 -> V_20 ) ;
F_50 ( V_34 -> V_89 ) ;
V_34 -> V_89 = NULL ;
}
void F_48 ( struct V_6 * V_2 )
{
char * V_93 = L_18 ;
char * V_94 [] = { V_93 , NULL } ;
F_47 ( L_19 ) ;
F_51 ( & V_2 -> V_90 -> V_89 -> V_62 , V_95 , V_94 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 ) ;
}
struct V_1 * F_54 ( struct V_5 * V_96 )
{
const char * V_97 ;
struct V_1 * V_89 ;
int V_98 ;
if ( V_96 -> type == V_99 )
V_97 = L_20 ;
else if ( V_96 -> type == V_100 )
V_97 = L_21 ;
else
V_97 = L_22 ;
V_89 = F_55 ( sizeof( * V_89 ) , V_16 ) ;
if ( ! V_89 )
return F_16 ( - V_101 ) ;
F_56 ( V_89 ) ;
V_89 -> V_102 = F_57 ( V_103 , V_96 -> V_92 ) ;
V_89 -> V_17 = V_29 ;
V_89 -> type = & V_4 ;
V_89 -> V_104 = V_96 -> V_2 -> V_2 ;
V_89 -> V_105 = F_52 ;
F_58 ( V_89 , V_96 ) ;
V_98 = F_59 ( V_89 , V_97 , V_96 -> V_92 ) ;
if ( V_98 < 0 )
goto V_106;
return V_89 ;
V_106:
F_60 ( V_89 ) ;
return F_16 ( V_98 ) ;
}
int F_61 ( struct V_1 * V_2 )
{
if ( ! V_29 || F_12 ( V_29 ) )
return - V_107 ;
V_2 -> V_17 = V_29 ;
return F_62 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
return F_50 ( V_2 ) ;
}
