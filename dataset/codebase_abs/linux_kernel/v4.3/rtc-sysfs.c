static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_2 ( V_2 ) -> V_6 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
T_1 V_7 ;
struct V_8 V_9 ;
V_7 = F_4 ( F_2 ( V_2 ) , & V_9 ) ;
if ( V_7 == 0 ) {
V_7 = sprintf ( V_5 , L_2 ,
V_9 . V_10 + 1900 , V_9 . V_11 + 1 , V_9 . V_12 ) ;
}
return V_7 ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
T_1 V_7 ;
struct V_8 V_9 ;
V_7 = F_4 ( F_2 ( V_2 ) , & V_9 ) ;
if ( V_7 == 0 ) {
V_7 = sprintf ( V_5 , L_3 ,
V_9 . V_13 , V_9 . V_14 , V_9 . V_15 ) ;
}
return V_7 ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
T_1 V_7 ;
struct V_8 V_9 ;
V_7 = F_4 ( F_2 ( V_2 ) , & V_9 ) ;
if ( V_7 == 0 ) {
unsigned long time ;
F_7 ( & V_9 , & time ) ;
V_7 = sprintf ( V_5 , L_4 , time ) ;
}
return V_7 ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_5 , F_2 ( V_2 ) -> V_16 ) ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
struct V_18 * V_19 = F_2 ( V_2 ) ;
unsigned long V_20 = F_10 ( V_5 , NULL , 0 ) ;
if ( V_20 >= 4096 || V_20 == 0 )
return - V_21 ;
V_19 -> V_16 = ( int ) V_20 ;
return V_17 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
#ifdef F_12
if ( V_22 == 0 &&
strcmp ( F_13 ( & F_2 ( V_2 ) -> V_2 ) ,
F_12 ) == 0 )
return sprintf ( V_5 , L_6 ) ;
else
#endif
return sprintf ( V_5 , L_7 ) ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
T_1 V_7 ;
unsigned long V_23 ;
struct V_24 V_25 ;
V_7 = F_15 ( F_2 ( V_2 ) , & V_25 ) ;
if ( V_7 == 0 && V_25 . V_26 ) {
F_7 ( & V_25 . time , & V_23 ) ;
V_7 = sprintf ( V_5 , L_4 , V_23 ) ;
}
return V_7 ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
T_1 V_7 ;
unsigned long V_27 , V_23 ;
unsigned long V_28 = 0 ;
struct V_24 V_25 ;
struct V_18 * V_19 = F_2 ( V_2 ) ;
char * V_29 ;
int V_30 = 0 ;
V_7 = F_4 ( V_19 , & V_25 . time ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( & V_25 . time , & V_27 ) ;
V_29 = ( char * ) V_5 ;
if ( * V_29 == '+' ) {
V_29 ++ ;
if ( * V_29 == '=' ) {
V_29 ++ ;
V_28 = 1 ;
} else
V_30 = 1 ;
}
V_23 = F_10 ( V_29 , NULL , 0 ) ;
if ( V_30 ) {
V_23 += V_27 ;
}
if ( V_23 > V_27 || V_28 ) {
V_7 = F_15 ( V_19 , & V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_25 . V_26 ) {
if ( V_28 ) {
F_7 ( & V_25 . time , & V_28 ) ;
V_23 += V_28 ;
} else
return - V_31 ;
} else if ( V_28 )
return - V_21 ;
V_25 . V_26 = 1 ;
} else {
V_25 . V_26 = 0 ;
V_23 = V_27 + 300 ;
}
F_17 ( V_23 , & V_25 . time ) ;
V_7 = F_18 ( V_19 , & V_25 ) ;
return ( V_7 < 0 ) ? V_7 : V_17 ;
}
static bool F_19 ( struct V_18 * V_19 )
{
if ( ! F_20 ( V_19 -> V_2 . V_32 ) )
return false ;
return V_19 -> V_33 -> V_34 != NULL ;
}
static T_3 F_21 ( struct V_35 * V_36 ,
struct V_37 * V_4 , int V_17 )
{
struct V_1 * V_2 = F_22 ( V_36 , struct V_1 , V_36 ) ;
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_3 V_38 = V_4 -> V_38 ;
if ( V_4 == & V_39 . V_4 )
if ( ! F_19 ( V_19 ) )
V_38 = 0 ;
return V_38 ;
}
const struct V_40 * * F_23 ( void )
{
return V_41 ;
}
