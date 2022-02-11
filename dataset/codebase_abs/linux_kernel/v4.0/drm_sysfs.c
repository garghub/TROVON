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
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
enum V_34 V_35 ;
int V_36 ;
V_36 = F_21 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
if ( V_36 )
return V_36 ;
V_35 = V_33 -> V_39 -> V_40 ( V_33 , true ) ;
F_22 ( & V_33 -> V_2 -> V_37 . V_38 ) ;
return snprintf ( V_31 , V_41 , L_2 ,
F_23 ( V_35 ) ) ;
}
static T_3 F_24 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
T_4 V_42 ;
int V_36 ;
V_36 = F_25 ( & V_33 -> V_43 ,
V_2 -> V_37 . V_44 ,
& V_42 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_2 ,
F_26 ( ( int ) V_42 ) ) ;
}
static T_3 F_27 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
return snprintf ( V_31 , V_41 , L_2 , V_33 -> V_45 ? L_3 :
L_4 ) ;
}
static T_3 F_28 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_26 , char * V_31 , T_5 V_51 ,
T_6 V_52 )
{
struct V_1 * V_53 = F_29 ( V_49 , struct V_1 , V_49 ) ;
struct V_32 * V_33 = F_20 ( V_53 ) ;
unsigned char * V_54 ;
T_6 V_55 ;
if ( ! V_33 -> V_56 )
return 0 ;
V_54 = V_33 -> V_56 -> V_57 ;
V_55 = V_33 -> V_56 -> V_58 ;
if ( ! V_54 )
return 0 ;
if ( V_51 >= V_55 )
return 0 ;
if ( V_51 + V_52 > V_55 )
V_52 = V_55 - V_51 ;
memcpy ( V_31 , V_54 + V_51 , V_52 ) ;
return V_52 ;
}
static T_3 F_30 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_59 * V_15 ;
int V_60 = 0 ;
F_31 (mode, &connector->modes, head) {
V_60 += snprintf ( V_31 + V_60 , V_41 - V_60 , L_2 ,
V_15 -> V_20 ) ;
}
return V_60 ;
}
static T_3 F_32 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
struct V_61 * V_62 = NULL ;
T_4 V_63 ;
int V_64 = 0 ;
int V_36 ;
switch ( V_33 -> V_65 ) {
case V_66 :
V_62 = V_2 -> V_37 . V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_62 = V_2 -> V_37 . V_72 ;
V_64 = 1 ;
break;
default:
F_33 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_33 ( L_6 ) ;
return 0 ;
}
V_36 = F_25 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_34 ( ( int ) V_63 ) :
F_35 ( ( int ) V_63 ) ) ;
}
static T_3 F_36 ( struct V_1 * V_1 ,
struct V_30 * V_26 ,
char * V_31 )
{
struct V_32 * V_33 = F_20 ( V_1 ) ;
struct V_6 * V_2 = V_33 -> V_2 ;
struct V_61 * V_62 = NULL ;
T_4 V_63 ;
int V_64 = 0 ;
int V_36 ;
switch ( V_33 -> V_65 ) {
case V_66 :
V_62 = V_2 -> V_37 . V_73 ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_62 = V_2 -> V_37 . V_74 ;
V_64 = 1 ;
break;
default:
F_33 ( L_5 ) ;
return 0 ;
}
if ( ! V_62 ) {
F_33 ( L_8 ) ;
return 0 ;
}
V_36 = F_25 ( & V_33 -> V_43 , V_62 , & V_63 ) ;
if ( V_36 )
return 0 ;
return snprintf ( V_31 , V_41 , L_7 , V_64 ?
F_37 ( ( int ) V_63 ) :
F_38 ( ( int ) V_63 ) ) ;
}
static T_2 F_39 ( struct V_48 * V_49 ,
struct V_75 * V_26 , int V_76 )
{
struct V_1 * V_2 = F_40 ( V_49 ) ;
struct V_32 * V_33 = F_20 ( V_2 ) ;
switch ( V_33 -> V_65 ) {
case V_66 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
return V_26 -> V_15 ;
}
return 0 ;
}
int F_41 ( struct V_32 * V_33 )
{
struct V_6 * V_2 = V_33 -> V_2 ;
if ( V_33 -> V_77 )
return 0 ;
V_33 -> V_77 =
F_42 ( V_29 , V_2 -> V_78 -> V_77 , 0 ,
V_33 , V_79 ,
L_9 , V_2 -> V_78 -> V_80 ,
V_33 -> V_20 ) ;
F_43 ( L_10 ,
V_33 -> V_20 ) ;
if ( F_12 ( V_33 -> V_77 ) ) {
F_33 ( L_11 , F_13 ( V_33 -> V_77 ) ) ;
return F_13 ( V_33 -> V_77 ) ;
}
F_44 ( V_2 ) ;
return 0 ;
}
void F_45 ( struct V_32 * V_33 )
{
if ( ! V_33 -> V_77 )
return;
F_43 ( L_12 ,
V_33 -> V_20 ) ;
F_46 ( V_33 -> V_77 ) ;
V_33 -> V_77 = NULL ;
}
void F_44 ( struct V_6 * V_2 )
{
char * V_81 = L_13 ;
char * V_82 [] = { V_81 , NULL } ;
F_43 ( L_14 ) ;
F_47 ( & V_2 -> V_78 -> V_77 -> V_49 , V_83 , V_82 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( V_2 ) ;
}
struct V_1 * F_50 ( struct V_5 * V_84 )
{
const char * V_85 ;
struct V_1 * V_77 ;
int V_86 ;
if ( V_84 -> type == V_87 )
V_85 = L_15 ;
else if ( V_84 -> type == V_88 )
V_85 = L_16 ;
else
V_85 = L_17 ;
V_77 = F_51 ( sizeof( * V_77 ) , V_16 ) ;
if ( ! V_77 )
return F_16 ( - V_89 ) ;
F_52 ( V_77 ) ;
V_77 -> V_90 = F_53 ( V_91 , V_84 -> V_80 ) ;
V_77 -> V_17 = V_29 ;
V_77 -> type = & V_4 ;
V_77 -> V_92 = V_84 -> V_2 -> V_2 ;
V_77 -> V_93 = F_48 ;
F_54 ( V_77 , V_84 ) ;
V_86 = F_55 ( V_77 , V_85 , V_84 -> V_80 ) ;
if ( V_86 < 0 )
goto V_94;
return V_77 ;
V_94:
F_56 ( V_77 ) ;
return F_16 ( V_86 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
if ( ! V_29 || F_12 ( V_29 ) )
return - V_95 ;
V_2 -> V_17 = V_29 ;
return F_58 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
return F_46 ( V_2 ) ;
}
