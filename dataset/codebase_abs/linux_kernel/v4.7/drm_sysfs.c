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
enum V_47 V_48 ;
V_48 = F_26 ( V_29 -> V_48 ) ;
return snprintf ( V_26 , V_49 , L_8 ,
F_27 ( V_48 ) ) ;
}
static T_3 F_28 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
int V_50 ;
V_50 = F_26 ( V_29 -> V_50 ) ;
return snprintf ( V_26 , V_49 , L_8 ,
F_29 ( V_50 ) ) ;
}
static T_3 F_30 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
bool V_51 ;
V_51 = F_26 ( V_29 -> V_52 ) ;
return snprintf ( V_26 , V_49 , V_51 ? L_9 : L_10 ) ;
}
static T_3 F_31 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_23 , char * V_26 , T_5 V_58 ,
T_4 V_27 )
{
struct V_1 * V_59 = F_32 ( V_56 ) ;
struct V_28 * V_29 = F_20 ( V_59 ) ;
unsigned char * V_60 ;
T_4 V_61 ;
T_3 V_32 = 0 ;
F_33 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
if ( ! V_29 -> V_62 )
goto V_63;
V_60 = V_29 -> V_62 -> V_64 ;
V_61 = V_29 -> V_62 -> V_65 ;
if ( ! V_60 )
goto V_63;
if ( V_58 >= V_61 )
goto V_63;
if ( V_58 + V_27 > V_61 )
V_27 = V_61 - V_58 ;
memcpy ( V_26 , V_60 + V_58 , V_27 ) ;
V_32 = V_27 ;
V_63:
F_24 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
return V_32 ;
}
static T_3 F_34 ( struct V_1 * V_1 ,
struct V_25 * V_23 ,
char * V_26 )
{
struct V_28 * V_29 = F_20 ( V_1 ) ;
struct V_66 * V_15 ;
int V_67 = 0 ;
F_33 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
F_35 (mode, &connector->modes, head) {
V_67 += snprintf ( V_26 + V_67 , V_49 - V_67 , L_8 ,
V_15 -> V_42 ) ;
}
F_24 ( & V_29 -> V_2 -> V_33 . V_34 ) ;
return V_67 ;
}
int F_36 ( struct V_28 * V_29 )
{
struct V_6 * V_2 = V_29 -> V_2 ;
if ( V_29 -> V_68 )
return 0 ;
V_29 -> V_68 =
F_37 ( V_18 , V_2 -> V_69 -> V_68 , 0 ,
V_29 , V_70 ,
L_11 , V_2 -> V_69 -> V_71 ,
V_29 -> V_42 ) ;
F_38 ( L_12 ,
V_29 -> V_42 ) ;
if ( F_12 ( V_29 -> V_68 ) ) {
F_39 ( L_13 , F_13 ( V_29 -> V_68 ) ) ;
return F_13 ( V_29 -> V_68 ) ;
}
F_40 ( V_2 ) ;
return 0 ;
}
void F_41 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_68 )
return;
F_38 ( L_14 ,
V_29 -> V_42 ) ;
F_42 ( V_29 -> V_68 ) ;
V_29 -> V_68 = NULL ;
}
void F_40 ( struct V_6 * V_2 )
{
char * V_72 = L_15 ;
char * V_73 [] = { V_72 , NULL } ;
F_38 ( L_16 ) ;
F_43 ( & V_2 -> V_69 -> V_68 -> V_56 , V_74 , V_73 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
}
struct V_1 * F_46 ( struct V_5 * V_75 )
{
const char * V_76 ;
struct V_1 * V_68 ;
int V_77 ;
if ( V_75 -> type == V_78 )
V_76 = L_17 ;
else if ( V_75 -> type == V_79 )
V_76 = L_18 ;
else
V_76 = L_19 ;
V_68 = F_47 ( sizeof( * V_68 ) , V_16 ) ;
if ( ! V_68 )
return F_48 ( - V_80 ) ;
F_49 ( V_68 ) ;
V_68 -> V_81 = F_50 ( V_82 , V_75 -> V_71 ) ;
V_68 -> V_83 = V_18 ;
V_68 -> type = & V_4 ;
V_68 -> V_84 = V_75 -> V_2 -> V_2 ;
V_68 -> V_85 = F_44 ;
F_51 ( V_68 , V_75 ) ;
V_77 = F_52 ( V_68 , V_76 , V_75 -> V_71 ) ;
if ( V_77 < 0 )
goto V_86;
return V_68 ;
V_86:
F_53 ( V_68 ) ;
return F_48 ( V_77 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
if ( ! V_18 || F_12 ( V_18 ) )
return - V_87 ;
V_2 -> V_83 = V_18 ;
return F_55 ( V_2 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
return F_42 ( V_2 ) ;
}
