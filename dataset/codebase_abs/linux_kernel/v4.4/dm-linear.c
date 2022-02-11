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
V_2 -> V_20 = V_6 ;
return 0 ;
V_13:
F_5 ( V_6 ) ;
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_20 ;
F_7 ( V_2 , V_6 -> V_16 ) ;
F_5 ( V_6 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_21 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
return V_6 -> V_14 + F_9 ( V_2 , V_21 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_22 * V_22 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
V_22 -> V_23 = V_6 -> V_16 -> V_24 ;
if ( F_11 ( V_22 ) )
V_22 -> V_25 . V_21 =
F_8 ( V_2 , V_22 -> V_25 . V_21 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_22 * V_22 )
{
F_10 ( V_2 , V_22 ) ;
return V_26 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 type ,
unsigned V_27 , char * V_28 , unsigned V_29 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_20 ;
switch ( type ) {
case V_30 :
V_28 [ 0 ] = '\0' ;
break;
case V_31 :
snprintf ( V_28 , V_29 , L_6 , V_6 -> V_16 -> V_32 ,
( unsigned long long ) V_6 -> V_14 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * * V_24 , T_3 * V_34 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_20 ;
struct V_35 * V_16 = V_6 -> V_16 ;
* V_24 = V_16 -> V_24 ;
if ( V_6 -> V_14 ||
V_2 -> V_36 != F_15 ( V_16 -> V_24 -> V_37 ) >> V_38 )
return 1 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_4 V_39 , void * V_40 )
{
struct V_5 * V_6 = V_2 -> V_20 ;
return V_39 ( V_2 , V_6 -> V_16 , V_6 -> V_14 , V_2 -> V_36 , V_40 ) ;
}
int T_5 F_17 ( void )
{
int V_41 = F_18 ( & V_42 ) ;
if ( V_41 < 0 )
F_19 ( L_7 , V_41 ) ;
return V_41 ;
}
void F_20 ( void )
{
F_21 ( & V_42 ) ;
}
