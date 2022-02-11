static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_13 = F_4 ( V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return snprintf ( V_5 , V_14 , L_1 , V_13 * 1000 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_14 , L_1 , 100 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_16 ) * 1000 ) ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_16 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_21 ) * 1000 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_21 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_22 ) * 1000 ) ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_22 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_23 ) * 1000 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_23 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_24 ) * 1000 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_24 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_25 ) * 1000 ) ;
}
static T_1
F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_25 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_26 ) * 1000 ) ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_26 , V_18 / 1000 ) ;
return V_17 ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 ,
V_11 -> V_15 ( V_11 , V_27 ) * 1000 ) ;
}
static T_1
F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return V_17 ;
V_11 -> V_20 ( V_11 , V_27 ,
V_18 / 1000 ) ;
return V_17 ;
}
static T_1 F_23 ( struct V_1 * V_7 ,
struct V_3 * V_28 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_24 ( struct V_1 * V_7 ,
struct V_3 * V_28 ,
char * V_5 )
{
return sprintf ( V_5 , L_3 ) ;
}
static T_1
F_25 ( struct V_1 * V_2 , struct V_3 * V_28 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
return snprintf ( V_5 , V_14 , L_1 , F_26 ( V_11 ) ) ;
}
static T_1
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_29 ;
V_29 = V_11 -> V_15 ( V_11 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_5 , L_4 , V_29 ) ;
}
static T_1
F_28 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
int V_29 ;
V_29 = F_8 ( V_5 , 10 , & V_18 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_11 -> V_20 ( V_11 , V_30 , V_18 ) ;
if ( V_29 )
return V_29 ;
else
return V_17 ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_29 ;
V_29 = V_11 -> V_31 ( V_11 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_5 , L_4 , V_29 ) ;
}
static T_1
F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_29 = - V_32 ;
long V_18 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_29 = V_11 -> V_33 ( V_11 , V_18 ) ;
if ( V_29 )
return V_29 ;
return V_17 ;
}
static T_1
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_29 ;
V_29 = V_11 -> V_15 ( V_11 , V_34 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_5 , L_4 , V_29 ) ;
}
static T_1
F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
int V_29 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_29 = V_11 -> V_20 ( V_11 , V_34 , V_18 ) ;
if ( V_29 < 0 )
return V_29 ;
return V_17 ;
}
static T_1
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
int V_29 ;
V_29 = V_11 -> V_15 ( V_11 , V_35 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_5 , L_4 , V_29 ) ;
}
static T_1
F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
long V_18 ;
int V_29 ;
if ( F_8 ( V_5 , 10 , & V_18 ) == - V_19 )
return - V_19 ;
V_29 = V_11 -> V_20 ( V_11 , V_35 , V_18 ) ;
if ( V_29 < 0 )
return V_29 ;
return V_17 ;
}
static T_1
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_36 * V_37 = F_36 ( & V_9 -> V_12 . V_1 ) ;
int V_29 ;
V_29 = F_37 ( V_37 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_5 , L_4 , V_29 / 1000 ) ;
}
static T_1
F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_36 * V_37 = F_36 ( & V_9 -> V_12 . V_1 ) ;
if ( ! V_37 || ! V_37 -> V_38 )
return - V_32 ;
return sprintf ( V_5 , L_4 , V_37 -> V_38 / 1000 ) ;
}
static T_1
F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_36 * V_37 = F_36 ( & V_9 -> V_12 . V_1 ) ;
if ( ! V_37 || ! V_37 -> V_39 )
return - V_32 ;
return sprintf ( V_5 , L_4 , V_37 -> V_39 / 1000 ) ;
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
struct V_40 * V_41 = F_42 ( & V_9 -> V_12 . V_1 ) ;
int V_42 = F_43 ( V_41 ) ;
if ( V_42 < 0 )
return V_42 ;
return sprintf ( V_5 , L_4 , V_42 ) ;
}
static T_1
F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_40 * V_41 = F_42 ( & V_9 -> V_12 . V_1 ) ;
return sprintf ( V_5 , L_4 , V_41 -> V_43 ) ;
}
static T_1
F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_40 * V_41 = F_42 ( & V_9 -> V_12 . V_1 ) ;
return sprintf ( V_5 , L_4 , V_41 -> V_44 ) ;
}
int
F_46 ( struct V_6 * V_7 )
{
#if F_47 ( V_45 ) || ( F_47 ( V_46 ) && F_47 ( V_47 ) )
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = F_3 ( & V_9 -> V_12 . V_1 ) ;
struct V_36 * V_37 = F_36 ( & V_9 -> V_12 . V_1 ) ;
struct V_40 * V_41 = F_42 ( & V_9 -> V_12 . V_1 ) ;
struct V_48 * V_49 ;
struct V_1 * V_50 ;
int V_29 = 0 ;
V_49 = V_9 -> V_49 = F_48 ( sizeof( * V_49 ) , V_51 ) ;
if ( ! V_49 )
return - V_52 ;
V_49 -> V_7 = V_7 ;
V_50 = F_49 ( V_7 -> V_7 ) ;
if ( F_50 ( V_50 ) ) {
V_29 = F_51 ( V_50 ) ;
F_52 ( V_9 , L_6 , V_29 ) ;
return V_29 ;
}
F_53 ( V_50 , V_7 ) ;
V_29 = F_54 ( & V_50 -> V_53 , & V_54 ) ;
if ( V_29 )
goto error;
if ( V_11 && V_11 -> V_15 && V_11 -> V_20 ) {
if ( F_4 ( V_11 ) >= 0 ) {
V_29 = F_54 ( & V_50 -> V_53 , & V_55 ) ;
if ( V_29 )
goto error;
}
if ( V_11 -> V_31 && V_11 -> V_31 ( V_11 ) >= 0 ) {
V_29 = F_54 ( & V_50 -> V_53 ,
& V_56 ) ;
if ( V_29 )
goto error;
}
}
if ( V_11 && F_26 ( V_11 ) >= 0 ) {
V_29 = F_54 ( & V_50 -> V_53 ,
& V_57 ) ;
if ( V_29 )
goto error;
}
if ( V_37 && F_37 ( V_37 ) >= 0 ) {
V_29 = F_54 ( & V_50 -> V_53 ,
& V_58 ) ;
if ( V_29 )
goto error;
}
if ( V_41 && V_41 -> V_59 && ! F_55 ( & V_41 -> V_60 ) ) {
V_29 = F_54 ( & V_50 -> V_53 ,
& V_61 ) ;
if ( V_29 )
goto error;
if ( V_41 -> V_43 && V_41 -> V_44 ) {
V_29 = F_54 ( & V_50 -> V_53 ,
& V_62 ) ;
if ( V_29 )
goto error;
}
}
V_49 -> V_49 = V_50 ;
return 0 ;
error:
F_52 ( V_9 , L_7 , V_29 ) ;
F_56 ( V_50 ) ;
V_49 -> V_49 = NULL ;
return V_29 ;
#else
return 0 ;
#endif
}
void
F_57 ( struct V_6 * V_7 )
{
#if F_47 ( V_45 ) || ( F_47 ( V_46 ) && F_47 ( V_47 ) )
struct V_48 * V_49 = V_48 ( V_7 ) ;
if ( V_49 -> V_49 ) {
F_58 ( & V_49 -> V_49 -> V_53 , & V_54 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_55 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_56 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_57 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_58 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_61 ) ;
F_58 ( & V_49 -> V_49 -> V_53 , & V_62 ) ;
F_56 ( V_49 -> V_49 ) ;
}
V_8 ( V_7 ) -> V_49 = NULL ;
F_59 ( V_49 ) ;
#endif
}
