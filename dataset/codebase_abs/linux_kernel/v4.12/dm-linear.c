static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
struct V_5 * V_6 ;
unsigned long long V_7 ;
char V_8 ;
int V_9 ;
if ( V_3 != 2 ) {
V_2 -> error = L_1 ;
return - V_10 ;
}
V_6 = F_2 ( sizeof( * V_6 ) , V_11 ) ;
if ( V_6 == NULL ) {
V_2 -> error = L_2 ;
return - V_12 ;
}
V_9 = - V_10 ;
if ( sscanf ( V_4 [ 1 ] , L_3 , & V_7 , & V_8 ) != 1 ) {
V_2 -> error = L_4 ;
goto V_13;
}
V_6 -> V_14 = V_7 ;
V_9 = F_3 ( V_2 , V_4 [ 0 ] , F_4 ( V_2 -> V_15 ) , & V_6 -> V_16 ) ;
if ( V_9 ) {
V_2 -> error = L_5 ;
goto V_13;
}
V_2 -> V_17 = 1 ;
V_2 -> V_18 = 1 ;
V_2 -> V_19 = 1 ;
V_2 -> V_20 = 1 ;
V_2 -> V_21 = V_6 ;
return 0 ;
V_13:
F_5 ( V_6 ) ;
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
F_7 ( V_2 , V_6 -> V_16 ) ;
F_5 ( V_6 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_22 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
return V_6 -> V_14 + F_9 ( V_2 , V_22 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
V_23 -> V_24 = V_6 -> V_16 -> V_25 ;
if ( F_11 ( V_23 ) )
V_23 -> V_26 . V_22 =
F_8 ( V_2 , V_23 -> V_26 . V_22 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_10 ( V_2 , V_23 ) ;
return V_27 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 type ,
unsigned V_28 , char * V_29 , unsigned V_30 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
switch ( type ) {
case V_31 :
V_29 [ 0 ] = '\0' ;
break;
case V_32 :
snprintf ( V_29 , V_30 , L_6 , V_6 -> V_16 -> V_33 ,
( unsigned long long ) V_6 -> V_14 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_34 * * V_25 , T_3 * V_35 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
struct V_36 * V_16 = V_6 -> V_16 ;
* V_25 = V_16 -> V_25 ;
if ( V_6 -> V_14 ||
V_2 -> V_37 != F_15 ( V_16 -> V_25 -> V_38 ) >> V_39 )
return 1 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_4 V_40 , void * V_41 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
return V_40 ( V_2 , V_6 -> V_16 , V_6 -> V_14 , V_2 -> V_37 , V_41 ) ;
}
static long F_17 ( struct V_1 * V_2 , T_5 V_42 ,
long V_43 , void * * V_44 , T_6 * V_45 )
{
long V_9 ;
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_34 * V_25 = V_6 -> V_16 -> V_25 ;
struct V_46 * V_47 = V_6 -> V_16 -> V_47 ;
T_1 V_48 , V_49 = V_42 * V_50 ;
V_48 = F_8 ( V_2 , V_49 ) ;
V_9 = F_18 ( V_25 , V_48 , V_43 * V_51 , & V_42 ) ;
if ( V_9 )
return V_9 ;
return F_19 ( V_47 , V_42 , V_43 , V_44 , V_45 ) ;
}
int T_7 F_20 ( void )
{
int V_52 = F_21 ( & V_53 ) ;
if ( V_52 < 0 )
F_22 ( L_7 , V_52 ) ;
return V_52 ;
}
void F_23 ( void )
{
F_24 ( & V_53 ) ;
}
