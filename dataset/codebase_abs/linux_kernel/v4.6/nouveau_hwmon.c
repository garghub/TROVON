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
return sprintf ( V_5 , L_5 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_37 * V_38 = F_40 ( & V_9 -> V_1 ) ;
int V_39 = F_41 ( V_38 ) ;
if ( V_39 < 0 )
return V_39 ;
return sprintf ( V_5 , L_4 , V_39 ) ;
}
int
F_42 ( struct V_6 * V_7 )
{
#if F_43 ( V_40 ) || ( F_43 ( V_41 ) && F_43 ( V_42 ) )
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
struct V_35 * V_36 = F_36 ( & V_9 -> V_1 ) ;
struct V_37 * V_38 = F_40 ( & V_9 -> V_1 ) ;
struct V_43 * V_44 ;
struct V_1 * V_45 ;
int V_28 = 0 ;
V_44 = V_9 -> V_44 = F_44 ( sizeof( * V_44 ) , V_46 ) ;
if ( ! V_44 )
return - V_47 ;
V_44 -> V_7 = V_7 ;
V_45 = F_45 ( V_7 -> V_7 ) ;
if ( F_46 ( V_45 ) ) {
V_28 = F_47 ( V_45 ) ;
F_48 ( V_9 , L_6 , V_28 ) ;
return V_28 ;
}
F_49 ( V_45 , V_7 ) ;
V_28 = F_50 ( & V_45 -> V_48 , & V_49 ) ;
if ( V_28 )
goto error;
if ( V_11 && V_11 -> V_14 && V_11 -> V_19 ) {
if ( F_4 ( V_11 ) >= 0 ) {
V_28 = F_50 ( & V_45 -> V_48 , & V_50 ) ;
if ( V_28 )
goto error;
}
if ( V_11 -> V_30 && V_11 -> V_30 ( V_11 ) >= 0 ) {
V_28 = F_50 ( & V_45 -> V_48 ,
& V_51 ) ;
if ( V_28 )
goto error;
}
}
if ( V_11 && F_26 ( V_11 ) >= 0 ) {
V_28 = F_50 ( & V_45 -> V_48 ,
& V_52 ) ;
if ( V_28 )
goto error;
}
if ( V_36 && F_37 ( V_36 ) >= 0 ) {
V_28 = F_50 ( & V_45 -> V_48 ,
& V_53 ) ;
if ( V_28 )
goto error;
}
if ( V_38 && V_38 -> V_54 && V_38 -> V_55 ) {
V_28 = F_50 ( & V_45 -> V_48 ,
& V_56 ) ;
if ( V_28 )
goto error;
}
V_44 -> V_44 = V_45 ;
return 0 ;
error:
F_48 ( V_9 , L_7 , V_28 ) ;
F_51 ( V_45 ) ;
V_44 -> V_44 = NULL ;
return V_28 ;
#else
return 0 ;
#endif
}
void
F_52 ( struct V_6 * V_7 )
{
#if F_43 ( V_40 ) || ( F_43 ( V_41 ) && F_43 ( V_42 ) )
struct V_43 * V_44 = V_43 ( V_7 ) ;
if ( V_44 -> V_44 ) {
F_53 ( & V_44 -> V_44 -> V_48 , & V_49 ) ;
F_53 ( & V_44 -> V_44 -> V_48 , & V_50 ) ;
F_53 ( & V_44 -> V_44 -> V_48 , & V_51 ) ;
F_53 ( & V_44 -> V_44 -> V_48 , & V_52 ) ;
F_53 ( & V_44 -> V_44 -> V_48 , & V_53 ) ;
F_53 ( & V_44 -> V_44 -> V_48 , & V_56 ) ;
F_51 ( V_44 -> V_44 ) ;
}
V_8 ( V_7 ) -> V_44 = NULL ;
F_54 ( V_44 ) ;
#endif
}
