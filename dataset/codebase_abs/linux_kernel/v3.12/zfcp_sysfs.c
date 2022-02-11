static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
if ( F_3 ( & V_7 -> V_8 ) & V_9 )
return sprintf ( V_5 , L_1 ) ;
return sprintf ( V_5 , L_2 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
unsigned long V_11 ;
if ( F_5 ( V_5 , 0 , & V_11 ) || V_11 != 0 )
return - V_12 ;
F_6 ( V_7 , V_13 ) ;
F_7 ( V_7 , V_9 , L_3 ) ;
F_8 ( V_7 -> V_14 ) ;
return V_10 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_15 * V_16 = F_2 ( V_2 , struct V_15 , V_2 ) ;
struct V_17 * V_18 ;
unsigned int V_8 , V_19 = 1 ;
V_18 = F_10 ( V_16 ) ;
if ( V_18 ) {
V_8 = F_3 ( & F_11 ( V_18 ) -> V_8 ) ;
V_19 = V_8 & V_9 ? 1 : 0 ;
F_12 ( V_18 ) ;
}
return sprintf ( V_5 , L_4 , V_19 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_15 * V_16 = F_2 ( V_2 , struct V_15 , V_2 ) ;
unsigned long V_11 ;
struct V_17 * V_18 ;
if ( F_5 ( V_5 , 0 , & V_11 ) || V_11 != 0 )
return - V_12 ;
V_18 = F_10 ( V_16 ) ;
if ( V_18 ) {
F_14 ( V_18 , V_13 ) ;
F_15 ( V_18 , V_9 ,
L_5 ) ;
F_8 ( V_16 -> V_7 -> V_14 ) ;
} else
F_16 ( V_16 ) ;
return V_10 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_22 * V_14 = F_19 ( V_21 ) ;
int V_23 ;
if ( ! V_14 )
return - V_24 ;
if ( F_3 ( & V_14 -> V_8 ) & V_9 )
V_23 = sprintf ( V_5 , L_1 ) ;
else
V_23 = sprintf ( V_5 , L_2 ) ;
F_20 ( V_14 ) ;
return V_23 ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_22 * V_14 = F_19 ( V_21 ) ;
unsigned long V_11 ;
int V_25 = 0 ;
if ( ! V_14 )
return - V_24 ;
if ( F_5 ( V_5 , 0 , & V_11 ) || V_11 != 0 ) {
V_25 = - V_12 ;
goto V_26;
}
F_22 ( V_14 , V_13 ) ;
F_23 ( V_14 , V_9 ,
L_6 ) ;
F_8 ( V_14 ) ;
V_26:
F_20 ( V_14 ) ;
return V_25 ? V_25 : ( T_1 ) V_10 ;
}
static T_1 F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_22 * V_14 = F_19 ( V_21 ) ;
if ( ! V_14 )
return - V_24 ;
F_25 ( V_14 -> V_27 , & V_14 -> V_28 ) ;
F_26 ( & V_14 -> V_28 ) ;
F_20 ( V_14 ) ;
return ( T_1 ) V_10 ;
}
static T_1 F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_20 * V_21 = F_18 ( V_2 ) ;
struct V_22 * V_14 = F_19 ( V_21 ) ;
struct V_6 * V_7 ;
T_3 V_29 ;
int V_25 = - V_12 ;
if ( ! V_14 )
return - V_24 ;
if ( F_28 ( V_5 , 0 , ( unsigned long long * ) & V_29 ) )
goto V_26;
V_7 = F_29 ( V_14 , V_29 ) ;
if ( ! V_7 )
goto V_26;
else
V_25 = 0 ;
F_30 ( & V_30 ) ;
if ( F_3 ( & V_7 -> V_31 ) > 0 ) {
V_25 = - V_32 ;
F_31 ( & V_30 ) ;
goto V_26;
}
F_32 ( & V_7 -> V_31 , - 1 ) ;
F_31 ( & V_30 ) ;
F_33 ( & V_14 -> V_33 ) ;
F_34 ( & V_7 -> V_34 ) ;
F_35 ( & V_14 -> V_33 ) ;
F_36 ( & V_7 -> V_2 ) ;
F_37 ( V_7 , 0 , L_7 ) ;
F_38 ( & V_7 -> V_2 ) ;
V_26:
F_20 ( V_14 ) ;
return V_25 ? V_25 : ( T_1 ) V_10 ;
}
static T_1 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_3 V_35 ;
int V_25 ;
if ( F_28 ( V_5 , 0 , ( unsigned long long * ) & V_35 ) )
return - V_12 ;
V_25 = F_40 ( V_7 , V_35 ) ;
if ( V_25 )
return V_25 ;
return V_10 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
T_3 V_35 ;
if ( F_28 ( V_5 , 0 , ( unsigned long long * ) & V_35 ) )
return - V_12 ;
if ( F_42 ( V_7 , V_35 ) )
return - V_12 ;
return V_10 ;
}
static T_1 F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_17 * V_18 = F_44 ( V_2 ) ;
return sprintf ( V_5 , L_8 , F_45 ( V_18 ) ) ;
}
static T_1 F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_36 * V_37 = F_47 ( V_2 ) ;
struct V_38 * V_39 ;
struct V_22 * V_14 ;
int V_25 ;
V_14 = (struct V_22 * ) V_37 -> V_40 [ 0 ] ;
if ( ! ( V_14 -> V_41 & V_42 ) )
return - V_43 ;
V_39 = F_48 ( sizeof( struct V_38 ) , V_44 ) ;
if ( ! V_39 )
return - V_45 ;
V_25 = F_49 ( V_14 -> V_46 , V_39 ) ;
if ( ! V_25 )
V_25 = sprintf ( V_5 , L_9 , V_39 -> V_47 ,
V_39 -> V_48 , V_39 -> V_49 ) ;
F_50 ( V_39 ) ;
return V_25 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_36 * V_37 = F_47 ( V_2 ) ;
struct V_52 * V_53 ;
struct V_22 * V_14 ;
int V_25 ;
V_14 = (struct V_22 * ) V_37 -> V_40 [ 0 ] ;
if ( ! ( V_14 -> V_41 & V_42 ) )
return - V_43 ;
V_53 = F_48 ( sizeof( struct V_52 ) ,
V_44 ) ;
if ( ! V_53 )
return - V_45 ;
V_25 = F_52 ( V_14 -> V_46 , V_53 ) ;
if ( ! V_25 )
* V_51 = V_53 -> V_54 ;
F_50 ( V_53 ) ;
return V_25 ;
}
static T_1 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_36 * V_37 = F_54 ( V_2 ) ;
struct V_55 * V_46 =
( (struct V_22 * ) V_37 -> V_40 [ 0 ] ) -> V_46 ;
T_3 V_56 ;
F_55 ( & V_46 -> V_57 ) ;
V_56 = V_46 -> V_58 ;
F_56 ( & V_46 -> V_57 ) ;
return sprintf ( V_5 , L_10 , F_3 ( & V_46 -> V_59 ) ,
( unsigned long long ) V_56 ) ;
}
