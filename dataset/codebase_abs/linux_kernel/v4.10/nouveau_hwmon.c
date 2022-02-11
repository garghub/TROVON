static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_12 = F_4 ( V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return snprintf ( V_5 , V_13 , L_1 , V_12 * 1000 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_13 , L_1 , 100 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_15 ) * 1000 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_15 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_20 ) * 1000 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_20 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_21 ) * 1000 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_21 , V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_22 ) * 1000 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_22 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_23 ) * 1000 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_23 , V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_24 ) * 1000 ) ;
}
static T_1
F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_24 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_25 ) * 1000 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_25 , V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 ,
V_11 -> V_14 ( V_11 , V_26 ) * 1000 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_11 -> V_19 ( V_11 , V_26 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1 F_23 ( struct V_1 * V_7 ,
struct V_3 * V_27 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_24 ( struct V_1 * V_7 ,
struct V_3 * V_27 ,
char * V_5 )
{
return sprintf ( V_5 , L_3 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_27 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
return snprintf ( V_5 , V_13 , L_1 , F_26 ( V_11 ) ) ;
}
static T_1
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_28 ;
V_28 = V_11 -> V_14 ( V_11 , V_29 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_5 , L_4 , V_28 ) ;
}
static T_1
F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
int V_28 ;
V_28 = F_8 ( V_5 , 10 , & V_17 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_11 -> V_19 ( V_11 , V_29 , V_17 ) ;
if ( V_28 )
return V_28 ;
else
return V_16 ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_28 ;
V_28 = V_11 -> V_30 ( V_11 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_5 , L_4 , V_28 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_28 = - V_31 ;
long V_17 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return - V_18 ;
V_28 = V_11 -> V_32 ( V_11 , V_17 ) ;
if ( V_28 )
return V_28 ;
return V_16 ;
}
static T_1
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_28 ;
V_28 = V_11 -> V_14 ( V_11 , V_33 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_5 , L_4 , V_28 ) ;
}
static T_1
F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
int V_28 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return - V_18 ;
V_28 = V_11 -> V_19 ( V_11 , V_33 , V_17 ) ;
if ( V_28 < 0 )
return V_28 ;
return V_16 ;
}
static T_1
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
int V_28 ;
V_28 = V_11 -> V_14 ( V_11 , V_34 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_5 , L_4 , V_28 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
long V_17 ;
int V_28 ;
if ( F_8 ( V_5 , 10 , & V_17 ) == - V_18 )
return - V_18 ;
V_28 = V_11 -> V_19 ( V_11 , V_34 , V_17 ) ;
if ( V_28 < 0 )
return V_28 ;
return V_16 ;
}
static T_1
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_35 * V_36 = F_36 ( & V_9 -> V_1 ) ;
int V_28 ;
V_28 = F_37 ( V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
return sprintf ( V_5 , L_4 , V_28 / 1000 ) ;
}
static T_1
F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_35 * V_36 = F_36 ( & V_9 -> V_1 ) ;
if ( ! V_36 || ! V_36 -> V_37 )
return - V_31 ;
return sprintf ( V_5 , L_4 , V_36 -> V_37 / 1000 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_35 * V_36 = F_36 ( & V_9 -> V_1 ) ;
if ( ! V_36 || ! V_36 -> V_38 )
return - V_31 ;
return sprintf ( V_5 , L_4 , V_36 -> V_38 / 1000 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_5 ) ;
}
static T_1
F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_39 * V_40 = F_42 ( & V_9 -> V_1 ) ;
int V_41 = F_43 ( V_40 ) ;
if ( V_41 < 0 )
return V_41 ;
return sprintf ( V_5 , L_4 , V_41 ) ;
}
int
F_44 ( struct V_6 * V_7 )
{
#if F_45 ( V_42 ) || ( F_45 ( V_43 ) && F_45 ( V_44 ) )
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
struct V_35 * V_36 = F_36 ( & V_9 -> V_1 ) ;
struct V_39 * V_40 = F_42 ( & V_9 -> V_1 ) ;
struct V_45 * V_46 ;
struct V_1 * V_47 ;
int V_28 = 0 ;
V_46 = V_9 -> V_46 = F_46 ( sizeof( * V_46 ) , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
V_46 -> V_7 = V_7 ;
V_47 = F_47 ( V_7 -> V_7 ) ;
if ( F_48 ( V_47 ) ) {
V_28 = F_49 ( V_47 ) ;
F_50 ( V_9 , L_6 , V_28 ) ;
return V_28 ;
}
F_51 ( V_47 , V_7 ) ;
V_28 = F_52 ( & V_47 -> V_50 , & V_51 ) ;
if ( V_28 )
goto error;
if ( V_11 && V_11 -> V_14 && V_11 -> V_19 ) {
if ( F_4 ( V_11 ) >= 0 ) {
V_28 = F_52 ( & V_47 -> V_50 , & V_52 ) ;
if ( V_28 )
goto error;
}
if ( V_11 -> V_30 && V_11 -> V_30 ( V_11 ) >= 0 ) {
V_28 = F_52 ( & V_47 -> V_50 ,
& V_53 ) ;
if ( V_28 )
goto error;
}
}
if ( V_11 && F_26 ( V_11 ) >= 0 ) {
V_28 = F_52 ( & V_47 -> V_50 ,
& V_54 ) ;
if ( V_28 )
goto error;
}
if ( V_36 && F_37 ( V_36 ) >= 0 ) {
V_28 = F_52 ( & V_47 -> V_50 ,
& V_55 ) ;
if ( V_28 )
goto error;
}
if ( V_40 && V_40 -> V_56 && ! F_53 ( & V_40 -> V_57 ) ) {
V_28 = F_52 ( & V_47 -> V_50 ,
& V_58 ) ;
if ( V_28 )
goto error;
}
V_46 -> V_46 = V_47 ;
return 0 ;
error:
F_50 ( V_9 , L_7 , V_28 ) ;
F_54 ( V_47 ) ;
V_46 -> V_46 = NULL ;
return V_28 ;
#else
return 0 ;
#endif
}
void
F_55 ( struct V_6 * V_7 )
{
#if F_45 ( V_42 ) || ( F_45 ( V_43 ) && F_45 ( V_44 ) )
struct V_45 * V_46 = V_45 ( V_7 ) ;
if ( V_46 -> V_46 ) {
F_56 ( & V_46 -> V_46 -> V_50 , & V_51 ) ;
F_56 ( & V_46 -> V_46 -> V_50 , & V_52 ) ;
F_56 ( & V_46 -> V_46 -> V_50 , & V_53 ) ;
F_56 ( & V_46 -> V_46 -> V_50 , & V_54 ) ;
F_56 ( & V_46 -> V_46 -> V_50 , & V_55 ) ;
F_56 ( & V_46 -> V_46 -> V_50 , & V_58 ) ;
F_54 ( V_46 -> V_46 ) ;
}
V_8 ( V_7 ) -> V_46 = NULL ;
F_57 ( V_46 ) ;
#endif
}
