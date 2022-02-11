static char * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return F_2 ( V_4 , L_1 , F_3 ( V_2 ) ) ;
}
int F_4 ( void )
{
int V_5 ;
V_6 = F_5 ( V_7 , L_2 ) ;
if ( F_6 ( V_6 ) )
return F_7 ( V_6 ) ;
V_5 = F_8 ( V_6 , & V_8 . V_9 ) ;
if ( V_5 ) {
F_9 ( V_6 ) ;
V_6 = NULL ;
return V_5 ;
}
V_6 -> V_10 = F_1 ;
return 0 ;
}
void F_10 ( void )
{
if ( F_11 ( V_6 ) )
return;
F_12 ( V_6 , & V_8 . V_9 ) ;
F_9 ( V_6 ) ;
V_6 = NULL ;
}
static T_2 F_13 ( struct V_1 * V_1 ,
struct V_11 * V_9 ,
const char * V_12 , T_3 V_13 )
{
struct V_14 * V_15 = F_14 ( V_1 ) ;
struct V_16 * V_2 = V_15 -> V_2 ;
enum V_17 V_18 ;
int V_19 ;
V_19 = F_15 ( & V_2 -> V_20 . V_21 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_15 -> V_22 ;
if ( F_16 ( V_12 , L_3 ) )
V_15 -> V_22 = 0 ;
else if ( F_16 ( V_12 , L_4 ) )
V_15 -> V_22 = V_23 ;
else if ( F_16 ( V_12 , L_5 ) )
V_15 -> V_22 = V_24 ;
else if ( F_16 ( V_12 , L_6 ) )
V_15 -> V_22 = V_25 ;
else
V_19 = - V_26 ;
if ( V_18 != V_15 -> V_22 || ! V_15 -> V_22 ) {
F_17 ( L_7 ,
V_15 -> V_27 . V_28 ,
V_15 -> V_29 ,
V_18 , V_15 -> V_22 ) ;
V_15 -> V_30 -> V_31 ( V_15 ,
V_2 -> V_20 . V_32 ,
V_2 -> V_20 . V_33 ) ;
}
F_18 ( & V_2 -> V_20 . V_21 ) ;
return V_19 ? V_19 : V_13 ;
}
static T_2 F_19 ( struct V_1 * V_1 ,
struct V_11 * V_9 ,
char * V_12 )
{
struct V_14 * V_15 = F_14 ( V_1 ) ;
enum V_34 V_35 ;
V_35 = F_20 ( V_15 -> V_35 ) ;
return snprintf ( V_12 , V_36 , L_8 ,
F_21 ( V_35 ) ) ;
}
static T_2 F_22 ( struct V_1 * V_1 ,
struct V_11 * V_9 ,
char * V_12 )
{
struct V_14 * V_15 = F_14 ( V_1 ) ;
int V_37 ;
V_37 = F_20 ( V_15 -> V_37 ) ;
return snprintf ( V_12 , V_36 , L_8 ,
F_23 ( V_37 ) ) ;
}
static T_2 F_24 ( struct V_1 * V_1 ,
struct V_11 * V_9 ,
char * V_12 )
{
struct V_14 * V_15 = F_14 ( V_1 ) ;
bool V_38 ;
V_38 = F_20 ( V_15 -> V_39 ) ;
return snprintf ( V_12 , V_36 , V_38 ? L_9 : L_10 ) ;
}
static T_2 F_25 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_44 * V_9 , char * V_12 , T_4 V_45 ,
T_3 V_13 )
{
struct V_1 * V_46 = F_26 ( V_43 ) ;
struct V_14 * V_15 = F_14 ( V_46 ) ;
unsigned char * V_47 ;
T_3 V_48 ;
T_2 V_19 = 0 ;
F_27 ( & V_15 -> V_2 -> V_20 . V_21 ) ;
if ( ! V_15 -> V_49 )
goto V_50;
V_47 = V_15 -> V_49 -> V_51 ;
V_48 = V_15 -> V_49 -> V_52 ;
if ( ! V_47 )
goto V_50;
if ( V_45 >= V_48 )
goto V_50;
if ( V_45 + V_13 > V_48 )
V_13 = V_48 - V_45 ;
memcpy ( V_12 , V_47 + V_45 , V_13 ) ;
V_19 = V_13 ;
V_50:
F_18 ( & V_15 -> V_2 -> V_20 . V_21 ) ;
return V_19 ;
}
static T_2 F_28 ( struct V_1 * V_1 ,
struct V_11 * V_9 ,
char * V_12 )
{
struct V_14 * V_15 = F_14 ( V_1 ) ;
struct V_53 * V_3 ;
int V_54 = 0 ;
F_27 ( & V_15 -> V_2 -> V_20 . V_21 ) ;
F_29 (mode, &connector->modes, head) {
V_54 += snprintf ( V_12 + V_54 , V_36 - V_54 , L_8 ,
V_3 -> V_29 ) ;
}
F_18 ( & V_15 -> V_2 -> V_20 . V_21 ) ;
return V_54 ;
}
int F_30 ( struct V_14 * V_15 )
{
struct V_16 * V_2 = V_15 -> V_2 ;
if ( V_15 -> V_55 )
return 0 ;
V_15 -> V_55 =
F_31 ( V_6 , V_2 -> V_56 -> V_55 , 0 ,
V_15 , V_57 ,
L_11 , V_2 -> V_56 -> V_58 ,
V_15 -> V_29 ) ;
F_32 ( L_12 ,
V_15 -> V_29 ) ;
if ( F_6 ( V_15 -> V_55 ) ) {
F_33 ( L_13 , F_7 ( V_15 -> V_55 ) ) ;
return F_7 ( V_15 -> V_55 ) ;
}
F_34 ( V_2 ) ;
return 0 ;
}
void F_35 ( struct V_14 * V_15 )
{
if ( ! V_15 -> V_55 )
return;
F_32 ( L_14 ,
V_15 -> V_29 ) ;
F_36 ( V_15 -> V_55 ) ;
V_15 -> V_55 = NULL ;
}
void F_34 ( struct V_16 * V_2 )
{
char * V_59 = L_15 ;
char * V_60 [] = { V_59 , NULL } ;
F_32 ( L_16 ) ;
F_37 ( & V_2 -> V_56 -> V_55 -> V_43 , V_61 , V_60 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 ) ;
}
struct V_1 * F_40 ( struct V_62 * V_63 )
{
const char * V_64 ;
struct V_1 * V_55 ;
int V_65 ;
if ( V_63 -> type == V_66 )
V_64 = L_17 ;
else if ( V_63 -> type == V_67 )
V_64 = L_18 ;
else
V_64 = L_19 ;
V_55 = F_41 ( sizeof( * V_55 ) , V_4 ) ;
if ( ! V_55 )
return F_42 ( - V_68 ) ;
F_43 ( V_55 ) ;
V_55 -> V_69 = F_44 ( V_70 , V_63 -> V_58 ) ;
V_55 -> V_71 = V_6 ;
V_55 -> type = & V_72 ;
V_55 -> V_73 = V_63 -> V_2 -> V_2 ;
V_55 -> V_74 = F_38 ;
F_45 ( V_55 , V_63 ) ;
V_65 = F_46 ( V_55 , V_64 , V_63 -> V_58 ) ;
if ( V_65 < 0 )
goto V_75;
return V_55 ;
V_75:
F_47 ( V_55 ) ;
return F_42 ( V_65 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
if ( ! V_6 || F_6 ( V_6 ) )
return - V_76 ;
V_2 -> V_71 = V_6 ;
return F_49 ( V_2 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
return F_36 ( V_2 ) ;
}
