static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_6 ? V_2 -> V_6 -> V_5 : L_2 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_8 , V_9 ;
struct V_10 * V_11 = NULL ;
struct V_10 * V_12 ;
int V_13 = V_7 ;
if ( V_3 [ V_7 - 1 ] == '\n' )
-- V_13 ;
if ( V_13 > 0 ) {
for ( V_8 = 0 ; V_8 < F_4 () ; ++ V_8 ) {
V_11 = F_5 ( V_8 ) ;
if ( F_6 ( V_3 , V_11 -> V_5 ) )
break;
V_11 = NULL ;
}
}
if ( V_13 > 0 && V_11 == NULL )
return - V_14 ;
if ( V_11 )
F_7 ( L_3 , V_11 -> V_5 ) ;
if ( V_11 == V_2 -> V_6 )
return V_7 ;
V_12 = V_2 -> V_6 ;
V_9 = F_8 () ;
if ( V_9 )
return V_9 ;
if ( V_12 ) {
V_9 = V_2 -> V_15 ( V_2 ) ;
if ( V_9 ) {
F_9 ( L_4 ) ;
goto V_16;
}
V_9 = V_12 -> V_17 ( V_12 ) ;
if ( V_9 )
goto V_16;
}
if ( V_11 ) {
V_9 = V_2 -> V_18 ( V_2 , V_11 ) ;
if ( V_9 ) {
F_9 ( L_5 ) ;
goto V_16;
}
V_9 = V_11 -> V_17 ( V_11 ) ;
if ( V_9 )
goto V_16;
}
F_10 () ;
return V_7 ;
V_16:
F_10 () ;
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_22 , V_20 . V_23 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 , V_20 . V_24 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_25 , V_20 . V_26 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_27 ;
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_25 = F_15 ( V_3 , & V_27 , 10 ) ;
++ V_27 ;
if ( V_27 - V_3 >= V_7 )
return - V_14 ;
V_20 . V_26 = F_15 ( V_27 , & V_27 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_6 ,
V_20 . V_29 , V_20 . V_30 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
char * V_27 ;
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_29 = F_15 ( V_3 , & V_27 , 10 ) ;
++ V_27 ;
if ( V_27 - V_3 >= V_7 )
return - V_14 ;
V_20 . V_30 = F_15 ( V_27 , & V_27 , 10 ) ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_18 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_7 , V_2 -> V_31 ( V_2 ) ) ;
}
static T_1 F_19 ( struct V_1 * V_2 , const char * V_3 ,
T_2 V_7 )
{
int V_9 ;
bool V_32 ;
V_9 = F_20 ( V_3 , & V_32 ) ;
if ( V_9 )
return V_9 ;
if ( V_32 )
V_9 = V_2 -> V_32 ( V_2 ) ;
else
V_9 = V_2 -> V_33 ( V_2 ) ;
if ( V_9 )
return V_9 ;
return V_7 ;
}
static T_1 F_21 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 ,
V_20 . V_34 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_35 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_37 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_35 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_34 = V_35 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 ,
V_20 . V_39 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_35 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_40 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_35 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_39 = V_35 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_26 ( struct V_1 * V_2 , char * V_3 )
{
struct V_19 V_20 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
return snprintf ( V_3 , V_4 , L_7 , V_20 . V_41 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_7 )
{
int V_9 ;
T_3 V_41 ;
struct V_19 V_20 ;
if ( ( V_2 -> V_36 & V_42 ) == 0 )
return - V_38 ;
V_9 = F_23 ( V_3 , 0 , & V_41 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_21 ( V_2 , & V_20 ) ;
V_20 . V_41 = V_41 ;
V_9 = V_2 -> V_28 ( V_2 , & V_20 ) ;
if ( V_9 )
return V_9 ;
if ( V_2 -> V_6 ) {
V_9 = V_2 -> V_6 -> V_17 ( V_2 -> V_6 ) ;
if ( V_9 )
return V_9 ;
}
return V_7 ;
}
static T_1 F_28 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_3 )
{
struct V_1 * V_47 ;
struct V_48 * V_49 ;
V_47 = F_29 ( V_44 , struct V_1 , V_44 ) ;
V_49 = F_29 ( V_46 , struct V_48 , V_46 ) ;
if ( ! V_49 -> V_50 )
return - V_51 ;
return V_49 -> V_50 ( V_47 , V_3 ) ;
}
static T_1 F_30 ( struct V_43 * V_44 , struct V_45 * V_46 ,
const char * V_3 , T_2 V_7 )
{
struct V_1 * V_47 ;
struct V_48 * V_49 ;
V_47 = F_29 ( V_44 , struct V_1 , V_44 ) ;
V_49 = F_29 ( V_46 , struct V_48 , V_46 ) ;
if ( ! V_49 -> V_52 )
return - V_51 ;
return V_49 -> V_52 ( V_47 , V_3 , V_7 ) ;
}
int F_31 ( struct V_1 * V_2 ,
struct V_53 * V_54 )
{
return F_32 ( & V_2 -> V_44 , & V_55 ,
& V_54 -> V_56 . V_44 , L_8 , V_2 -> V_57 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_44 ) ;
F_35 ( & V_2 -> V_44 ) ;
}
