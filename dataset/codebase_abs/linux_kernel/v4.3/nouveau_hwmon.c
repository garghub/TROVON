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
int
F_35 ( struct V_6 * V_7 )
{
#if F_36 ( V_35 ) || ( F_36 ( V_36 ) && F_36 ( V_37 ) )
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_1 ) ;
struct V_38 * V_39 ;
struct V_1 * V_40 ;
int V_28 = 0 ;
V_39 = V_9 -> V_39 = F_37 ( sizeof( * V_39 ) , V_41 ) ;
if ( ! V_39 )
return - V_42 ;
V_39 -> V_7 = V_7 ;
if ( ! V_11 || ! V_11 -> V_14 || ! V_11 -> V_19 )
return - V_31 ;
V_40 = F_38 ( & V_7 -> V_43 -> V_7 ) ;
if ( F_39 ( V_40 ) ) {
V_28 = F_40 ( V_40 ) ;
F_41 ( V_9 , L_5 , V_28 ) ;
return V_28 ;
}
F_42 ( V_40 , V_7 ) ;
V_28 = F_43 ( & V_40 -> V_44 , & V_45 ) ;
if ( V_28 )
goto error;
if ( F_4 ( V_11 ) >= 0 ) {
V_28 = F_43 ( & V_40 -> V_44 , & V_46 ) ;
if ( V_28 )
goto error;
}
if ( V_11 -> V_30 && V_11 -> V_30 ( V_11 ) >= 0 ) {
V_28 = F_43 ( & V_40 -> V_44 ,
& V_47 ) ;
if ( V_28 )
goto error;
}
if ( F_26 ( V_11 ) >= 0 ) {
V_28 = F_43 ( & V_40 -> V_44 ,
& V_48 ) ;
if ( V_28 )
goto error;
}
V_39 -> V_39 = V_40 ;
return 0 ;
error:
F_41 ( V_9 , L_6 , V_28 ) ;
F_44 ( V_40 ) ;
V_39 -> V_39 = NULL ;
return V_28 ;
#else
return 0 ;
#endif
}
void
F_45 ( struct V_6 * V_7 )
{
#if F_36 ( V_35 ) || ( F_36 ( V_36 ) && F_36 ( V_37 ) )
struct V_38 * V_39 = V_38 ( V_7 ) ;
if ( V_39 -> V_39 ) {
F_46 ( & V_39 -> V_39 -> V_44 , & V_45 ) ;
F_46 ( & V_39 -> V_39 -> V_44 , & V_46 ) ;
F_46 ( & V_39 -> V_39 -> V_44 , & V_47 ) ;
F_46 ( & V_39 -> V_39 -> V_44 , & V_48 ) ;
F_44 ( V_39 -> V_39 ) ;
}
V_8 ( V_7 ) -> V_39 = NULL ;
F_47 ( V_39 ) ;
#endif
}
