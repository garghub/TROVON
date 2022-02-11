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
unsigned long V_20 ;
int V_21 ;
V_21 = F_10 ( V_5 , 0 , & V_20 ) ;
if ( V_21 )
return V_21 ;
if ( V_20 >= 4096 || V_20 == 0 )
return - V_22 ;
V_19 -> V_16 = ( int ) V_20 ;
return V_17 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
#ifdef F_12
if ( V_23 == 0 &&
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
unsigned long V_24 ;
struct V_25 V_26 ;
V_7 = F_15 ( F_2 ( V_2 ) , & V_26 ) ;
if ( V_7 == 0 && V_26 . V_27 ) {
F_7 ( & V_26 . time , & V_24 ) ;
V_7 = sprintf ( V_5 , L_4 , V_24 ) ;
}
return V_7 ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
T_1 V_7 ;
unsigned long V_28 , V_24 ;
unsigned long V_29 = 0 ;
struct V_25 V_26 ;
struct V_18 * V_19 = F_2 ( V_2 ) ;
const char * V_30 ;
int V_31 = 0 ;
V_7 = F_4 ( V_19 , & V_26 . time ) ;
if ( V_7 < 0 )
return V_7 ;
F_7 ( & V_26 . time , & V_28 ) ;
V_30 = V_5 ;
if ( * V_30 == '+' ) {
V_30 ++ ;
if ( * V_30 == '=' ) {
V_30 ++ ;
V_29 = 1 ;
} else
V_31 = 1 ;
}
V_7 = F_10 ( V_30 , 0 , & V_24 ) ;
if ( V_7 )
return V_7 ;
if ( V_31 ) {
V_24 += V_28 ;
}
if ( V_24 > V_28 || V_29 ) {
V_7 = F_15 ( V_19 , & V_26 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_26 . V_27 ) {
if ( V_29 ) {
F_7 ( & V_26 . time , & V_29 ) ;
V_24 += V_29 ;
} else
return - V_32 ;
} else if ( V_29 )
return - V_22 ;
V_26 . V_27 = 1 ;
} else {
V_26 . V_27 = 0 ;
V_24 = V_28 + 300 ;
}
F_17 ( V_24 , & V_26 . time ) ;
V_7 = F_18 ( V_19 , & V_26 ) ;
return ( V_7 < 0 ) ? V_7 : V_17 ;
}
static T_1
F_19 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
T_1 V_7 ;
long V_33 ;
V_7 = F_20 ( F_2 ( V_2 ) , & V_33 ) ;
if ( V_7 == 0 )
V_7 = sprintf ( V_5 , L_8 , V_33 ) ;
return V_7 ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_17 )
{
T_1 V_7 ;
long V_33 ;
V_7 = F_22 ( V_5 , 10 , & V_33 ) ;
if ( V_7 == 0 )
V_7 = F_23 ( F_2 ( V_2 ) , V_33 ) ;
return ( V_7 < 0 ) ? V_7 : V_17 ;
}
static bool F_24 ( struct V_18 * V_19 )
{
if ( ! F_25 ( V_19 -> V_2 . V_34 ) )
return false ;
return V_19 -> V_35 -> V_36 != NULL ;
}
static T_3 F_26 ( struct V_37 * V_38 ,
struct V_39 * V_4 , int V_17 )
{
struct V_1 * V_2 = F_27 ( V_38 , struct V_1 , V_38 ) ;
struct V_18 * V_19 = F_2 ( V_2 ) ;
T_3 V_40 = V_4 -> V_40 ;
if ( V_4 == & V_41 . V_4 ) {
if ( ! F_24 ( V_19 ) )
V_40 = 0 ;
} else if ( V_4 == & V_42 . V_4 ) {
if ( ! V_19 -> V_35 -> V_43 )
V_40 = 0 ;
}
return V_40 ;
}
const struct V_44 * * F_28 ( void )
{
return V_45 ;
}
