static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_12 = V_11 -> V_13 ( V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return snprintf ( V_5 , V_14 , L_1 , V_12 * 1000 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_14 , L_1 , 100 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_16 ) * 1000 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_16 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_21 ) * 1000 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_21 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_22 ) * 1000 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_22 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_23 ) * 1000 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_23 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_24 ) * 1000 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_24 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_25 ) * 1000 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_25 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_26 ) * 1000 ) ;
}
static T_1
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_26 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_27 ) * 1000 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_27 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1 F_21 ( struct V_1 * V_7 ,
struct V_3 * V_28 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_22 ( struct V_1 * V_7 ,
struct V_3 * V_28 ,
char * V_5 )
{
return sprintf ( V_5 , L_3 ) ;
}
static T_1
F_23 ( struct V_1 * V_2 , struct V_3 * V_28 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 , V_11 -> V_29 ( V_11 ) ) ;
}
static T_1
F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_30 ;
V_30 = V_11 -> V_15 ( V_11 , V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
return sprintf ( V_5 , L_4 , V_30 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
int V_30 ;
V_30 = F_6 ( V_5 , 10 , & V_18 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_11 -> V_20 ( V_11 , V_31 , V_18 ) ;
if ( V_30 )
return V_30 ;
else
return V_17 ;
}
static T_1
F_26 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_30 ;
V_30 = V_11 -> V_32 ( V_11 ) ;
if ( V_30 < 0 )
return V_30 ;
return sprintf ( V_5 , L_4 , V_30 ) ;
}
static T_1
F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_30 = - V_33 ;
long V_18 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_30 = V_11 -> V_34 ( V_11 , V_18 ) ;
if ( V_30 )
return V_30 ;
return V_17 ;
}
static T_1
F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_30 ;
V_30 = V_11 -> V_15 ( V_11 , V_35 ) ;
if ( V_30 < 0 )
return V_30 ;
return sprintf ( V_5 , L_4 , V_30 ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
int V_30 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_30 = V_11 -> V_20 ( V_11 , V_35 , V_18 ) ;
if ( V_30 < 0 )
return V_30 ;
return V_17 ;
}
static T_1
F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
int V_30 ;
V_30 = V_11 -> V_15 ( V_11 , V_36 ) ;
if ( V_30 < 0 )
return V_30 ;
return sprintf ( V_5 , L_4 , V_30 ) ;
}
static T_1
F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
long V_18 ;
int V_30 ;
if ( F_6 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_30 = V_11 -> V_20 ( V_11 , V_36 , V_18 ) ;
if ( V_30 < 0 )
return V_30 ;
return V_17 ;
}
int
F_32 ( struct V_6 * V_7 )
{
#if F_33 ( V_37 ) || ( F_33 ( V_38 ) && F_33 ( V_39 ) )
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_10 ( V_9 -> V_1 ) ;
struct V_40 * V_41 ;
struct V_1 * V_42 ;
int V_30 = 0 ;
V_41 = V_9 -> V_41 = F_34 ( sizeof( * V_41 ) , V_43 ) ;
if ( ! V_41 )
return - V_44 ;
V_41 -> V_7 = V_7 ;
if ( ! V_11 || ! V_11 -> V_13 || ! V_11 -> V_15 || ! V_11 -> V_20 )
return - V_33 ;
V_42 = F_35 ( & V_7 -> V_45 -> V_7 ) ;
if ( F_36 ( V_42 ) ) {
V_30 = F_37 ( V_42 ) ;
F_38 ( V_9 , L_5 , V_30 ) ;
return V_30 ;
}
F_39 ( V_42 , V_7 ) ;
V_30 = F_40 ( & V_42 -> V_46 , & V_47 ) ;
if ( V_30 )
goto error;
if ( V_11 -> V_13 ( V_11 ) >= 0 ) {
V_30 = F_40 ( & V_42 -> V_46 , & V_48 ) ;
if ( V_30 )
goto error;
}
if ( V_11 -> V_32 && V_11 -> V_32 ( V_11 ) >= 0 ) {
V_30 = F_40 ( & V_42 -> V_46 ,
& V_49 ) ;
if ( V_30 )
goto error;
}
if ( V_11 -> V_29 ( V_11 ) >= 0 ) {
V_30 = F_40 ( & V_42 -> V_46 ,
& V_50 ) ;
if ( V_30 )
goto error;
}
V_41 -> V_41 = V_42 ;
return 0 ;
error:
F_38 ( V_9 , L_6 , V_30 ) ;
F_41 ( V_42 ) ;
V_41 -> V_41 = NULL ;
return V_30 ;
#else
return 0 ;
#endif
}
void
F_42 ( struct V_6 * V_7 )
{
#if F_33 ( V_37 ) || ( F_33 ( V_38 ) && F_33 ( V_39 ) )
struct V_40 * V_41 = V_40 ( V_7 ) ;
if ( V_41 -> V_41 ) {
F_43 ( & V_41 -> V_41 -> V_46 , & V_47 ) ;
F_43 ( & V_41 -> V_41 -> V_46 , & V_48 ) ;
F_43 ( & V_41 -> V_41 -> V_46 , & V_49 ) ;
F_43 ( & V_41 -> V_41 -> V_46 , & V_50 ) ;
F_41 ( V_41 -> V_41 ) ;
}
V_8 ( V_7 ) -> V_41 = NULL ;
F_44 ( V_41 ) ;
#endif
}
