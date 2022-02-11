static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
struct V_5 * V_6 ;
unsigned long long V_7 ;
char V_8 ;
if ( V_3 != 2 ) {
V_2 -> error = L_1 ;
return - V_9 ;
}
V_6 = F_2 ( sizeof( * V_6 ) , V_10 ) ;
if ( V_6 == NULL ) {
V_2 -> error = L_2 ;
return - V_11 ;
}
if ( sscanf ( V_4 [ 1 ] , L_3 , & V_7 , & V_8 ) != 1 ) {
V_2 -> error = L_4 ;
goto V_12;
}
V_6 -> V_13 = V_7 ;
if ( F_3 ( V_2 , V_4 [ 0 ] , F_4 ( V_2 -> V_14 ) , & V_6 -> V_15 ) ) {
V_2 -> error = L_5 ;
goto V_12;
}
V_2 -> V_16 = 1 ;
V_2 -> V_17 = 1 ;
V_2 -> V_18 = 1 ;
V_2 -> V_19 = V_6 ;
return 0 ;
V_12:
F_5 ( V_6 ) ;
return - V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_19 ;
F_7 ( V_2 , V_6 -> V_15 ) ;
F_5 ( V_6 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_20 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
return V_6 -> V_13 + F_9 ( V_2 , V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_21 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
V_21 -> V_22 = V_6 -> V_15 -> V_23 ;
if ( F_11 ( V_21 ) )
V_21 -> V_20 = F_8 ( V_2 , V_21 -> V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_21 * V_21 )
{
F_10 ( V_2 , V_21 ) ;
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 type ,
unsigned V_25 , char * V_26 , unsigned V_27 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_19 ;
switch ( type ) {
case V_28 :
V_26 [ 0 ] = '\0' ;
break;
case V_29 :
snprintf ( V_26 , V_27 , L_6 , V_6 -> V_15 -> V_30 ,
( unsigned long long ) V_6 -> V_13 ) ;
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_31 ,
unsigned long V_32 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_19 ;
struct V_33 * V_15 = V_6 -> V_15 ;
int V_34 = 0 ;
if ( V_6 -> V_13 ||
V_2 -> V_35 != F_15 ( V_15 -> V_23 -> V_36 ) >> V_37 )
V_34 = F_16 ( NULL , V_31 ) ;
return V_34 ? : F_17 ( V_15 -> V_23 , V_15 -> V_38 , V_31 , V_32 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_41 * V_42 , int V_43 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
struct V_44 * V_45 = F_19 ( V_6 -> V_15 -> V_23 ) ;
if ( ! V_45 -> V_46 )
return V_43 ;
V_40 -> V_22 = V_6 -> V_15 -> V_23 ;
V_40 -> V_20 = F_8 ( V_2 , V_40 -> V_20 ) ;
return F_20 ( V_43 , V_45 -> V_46 ( V_45 , V_40 , V_42 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_47 , void * V_48 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
return V_47 ( V_2 , V_6 -> V_15 , V_6 -> V_13 , V_2 -> V_35 , V_48 ) ;
}
int T_4 F_22 ( void )
{
int V_34 = F_23 ( & V_49 ) ;
if ( V_34 < 0 )
F_24 ( L_7 , V_34 ) ;
return V_34 ;
}
void F_25 ( void )
{
F_26 ( & V_49 ) ;
}
