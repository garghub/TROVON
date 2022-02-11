static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
struct V_5 * V_6 ;
unsigned long long V_7 ;
if ( V_3 != 4 ) {
V_2 -> error = L_1 ;
return - V_8 ;
}
V_6 = F_2 ( sizeof( * V_6 ) , V_9 ) ;
if ( ! V_6 ) {
V_2 -> error = L_2 ;
return - V_10 ;
}
V_6 -> V_11 = V_12 ;
if ( sscanf ( V_4 [ 1 ] , L_3 , & V_7 ) != 1 ) {
V_2 -> error = L_4 ;
goto V_13;
}
V_6 -> V_14 = V_7 ;
if ( sscanf ( V_4 [ 2 ] , L_5 , & V_6 -> V_15 ) != 1 ) {
V_2 -> error = L_6 ;
goto V_13;
}
if ( sscanf ( V_4 [ 3 ] , L_5 , & V_6 -> V_16 ) != 1 ) {
V_2 -> error = L_7 ;
goto V_13;
}
if ( ! ( V_6 -> V_15 + V_6 -> V_16 ) ) {
V_2 -> error = L_8 ;
goto V_13;
}
if ( V_6 -> V_15 + V_6 -> V_16 < V_6 -> V_15 ) {
V_2 -> error = L_9 ;
goto V_13;
}
if ( F_3 ( V_2 , V_4 [ 0 ] , F_4 ( V_2 -> V_17 ) , & V_6 -> V_18 ) ) {
V_2 -> error = L_10 ;
goto V_13;
}
V_2 -> V_19 = 1 ;
V_2 -> V_20 = V_6 ;
return 0 ;
V_13:
F_5 ( V_6 ) ;
return - V_8 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
F_7 ( V_2 , V_6 -> V_18 ) ;
F_5 ( V_6 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_21 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
return V_6 -> V_14 + ( V_21 - V_2 -> V_22 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
V_23 -> V_24 = V_6 -> V_18 -> V_25 ;
if ( F_10 ( V_23 ) )
V_23 -> V_21 = F_8 ( V_2 , V_23 -> V_21 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_23 * V_23 ,
union V_26 * V_27 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
unsigned V_28 ;
V_28 = ( V_12 - V_6 -> V_11 ) / V_29 ;
if ( V_28 % ( V_6 -> V_15 + V_6 -> V_16 ) >= V_6 -> V_15 )
return - V_30 ;
F_9 ( V_2 , V_23 ) ;
return V_31 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 type ,
char * V_32 , unsigned int V_33 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
switch ( type ) {
case V_34 :
V_32 [ 0 ] = '\0' ;
break;
case V_35 :
snprintf ( V_32 , V_33 , L_11 , V_6 -> V_18 -> V_36 ,
( unsigned long long ) V_6 -> V_14 , V_6 -> V_15 ,
V_6 -> V_16 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_37 , unsigned long V_38 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
return F_14 ( V_6 -> V_18 -> V_25 , V_6 -> V_18 -> V_39 , V_37 , V_38 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
struct V_45 * V_46 = F_16 ( V_6 -> V_18 -> V_25 ) ;
if ( ! V_46 -> V_47 )
return V_44 ;
V_41 -> V_24 = V_6 -> V_18 -> V_25 ;
V_41 -> V_21 = F_8 ( V_2 , V_41 -> V_21 ) ;
return F_17 ( V_44 , V_46 -> V_47 ( V_46 , V_41 , V_43 ) ) ;
}
static int F_18 ( struct V_1 * V_2 , T_3 V_48 , void * V_49 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
return V_48 ( V_2 , V_6 -> V_18 , V_6 -> V_14 , V_2 -> V_50 , V_49 ) ;
}
static int T_4 F_19 ( void )
{
int V_51 = F_20 ( & V_52 ) ;
if ( V_51 < 0 )
F_21 ( L_12 , V_51 ) ;
return V_51 ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_52 ) ;
}
