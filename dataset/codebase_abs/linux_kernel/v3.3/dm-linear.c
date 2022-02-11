static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
struct V_5 * V_6 ;
unsigned long long V_7 ;
if ( V_3 != 2 ) {
V_2 -> error = L_1 ;
return - V_8 ;
}
V_6 = F_2 ( sizeof( * V_6 ) , V_9 ) ;
if ( V_6 == NULL ) {
V_2 -> error = L_2 ;
return - V_10 ;
}
if ( sscanf ( V_4 [ 1 ] , L_3 , & V_7 ) != 1 ) {
V_2 -> error = L_4 ;
goto V_11;
}
V_6 -> V_12 = V_7 ;
if ( F_3 ( V_2 , V_4 [ 0 ] , F_4 ( V_2 -> V_13 ) , & V_6 -> V_14 ) ) {
V_2 -> error = L_5 ;
goto V_11;
}
V_2 -> V_15 = 1 ;
V_2 -> V_16 = 1 ;
V_2 -> V_17 = V_6 ;
return 0 ;
V_11:
F_5 ( V_6 ) ;
return - V_8 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_17 ;
F_7 ( V_2 , V_6 -> V_14 ) ;
F_5 ( V_6 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_18 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
return V_6 -> V_12 + F_9 ( V_2 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_19 * V_19 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
V_19 -> V_20 = V_6 -> V_14 -> V_21 ;
if ( F_11 ( V_19 ) )
V_19 -> V_18 = F_8 ( V_2 , V_19 -> V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_19 * V_19 ,
union V_22 * V_23 )
{
F_10 ( V_2 , V_19 ) ;
return V_24 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 type ,
char * V_25 , unsigned int V_26 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_17 ;
switch ( type ) {
case V_27 :
V_25 [ 0 ] = '\0' ;
break;
case V_28 :
snprintf ( V_25 , V_26 , L_6 , V_6 -> V_14 -> V_29 ,
( unsigned long long ) V_6 -> V_12 ) ;
break;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_30 ,
unsigned long V_31 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_17 ;
struct V_32 * V_14 = V_6 -> V_14 ;
int V_33 = 0 ;
if ( V_6 -> V_12 ||
V_2 -> V_34 != F_15 ( V_14 -> V_21 -> V_35 ) >> V_36 )
V_33 = F_16 ( NULL , V_30 ) ;
return V_33 ? : F_17 ( V_14 -> V_21 , V_14 -> V_37 , V_30 , V_31 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
struct V_43 * V_44 = F_19 ( V_6 -> V_14 -> V_21 ) ;
if ( ! V_44 -> V_45 )
return V_42 ;
V_39 -> V_20 = V_6 -> V_14 -> V_21 ;
V_39 -> V_18 = F_8 ( V_2 , V_39 -> V_18 ) ;
return F_20 ( V_42 , V_44 -> V_45 ( V_44 , V_39 , V_41 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_46 , void * V_47 )
{
struct V_5 * V_6 = V_2 -> V_17 ;
return V_46 ( V_2 , V_6 -> V_14 , V_6 -> V_12 , V_2 -> V_34 , V_47 ) ;
}
int T_4 F_22 ( void )
{
int V_33 = F_23 ( & V_48 ) ;
if ( V_33 < 0 )
F_24 ( L_7 , V_33 ) ;
return V_33 ;
}
void F_25 ( void )
{
F_26 ( & V_48 ) ;
}
