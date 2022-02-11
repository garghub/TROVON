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
F_11 ( V_23 , V_6 -> V_16 -> V_24 ) ;
if ( F_12 ( V_23 ) || F_13 ( V_23 ) == V_25 )
V_23 -> V_26 . V_22 =
F_8 ( V_2 , V_23 -> V_26 . V_22 ) ;
}
static int F_14 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_10 ( V_2 , V_23 ) ;
return V_27 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * error )
{
struct V_5 * V_6 = V_2 -> V_21 ;
if ( ! * error && F_13 ( V_23 ) == V_28 )
F_16 ( V_2 , V_23 , V_6 -> V_14 ) ;
return V_29 ;
}
static void F_17 ( struct V_1 * V_2 , T_3 type ,
unsigned V_30 , char * V_31 , unsigned V_32 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
switch ( type ) {
case V_33 :
V_31 [ 0 ] = '\0' ;
break;
case V_34 :
snprintf ( V_31 , V_32 , L_6 , V_6 -> V_16 -> V_35 ,
( unsigned long long ) V_6 -> V_14 ) ;
break;
}
}
static int F_18 ( struct V_1 * V_2 ,
struct V_36 * * V_24 , T_4 * V_37 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
struct V_38 * V_16 = V_6 -> V_16 ;
* V_24 = V_16 -> V_24 ;
if ( V_6 -> V_14 ||
V_2 -> V_39 != F_19 ( V_16 -> V_24 -> V_40 ) >> V_41 )
return 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_5 V_42 , void * V_43 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
return V_42 ( V_2 , V_6 -> V_16 , V_6 -> V_14 , V_2 -> V_39 , V_43 ) ;
}
static long F_21 ( struct V_1 * V_2 , T_6 V_44 ,
long V_45 , void * * V_46 , T_7 * V_47 )
{
long V_9 ;
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_36 * V_24 = V_6 -> V_16 -> V_24 ;
struct V_48 * V_49 = V_6 -> V_16 -> V_49 ;
T_1 V_50 , V_51 = V_44 * V_52 ;
V_50 = F_8 ( V_2 , V_51 ) ;
V_9 = F_22 ( V_24 , V_50 , V_45 * V_53 , & V_44 ) ;
if ( V_9 )
return V_9 ;
return F_23 ( V_49 , V_44 , V_45 , V_46 , V_47 ) ;
}
static T_8 F_24 ( struct V_1 * V_2 , T_6 V_44 ,
void * V_54 , T_8 V_55 , struct V_56 * V_57 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_36 * V_24 = V_6 -> V_16 -> V_24 ;
struct V_48 * V_49 = V_6 -> V_16 -> V_49 ;
T_1 V_50 , V_51 = V_44 * V_52 ;
V_50 = F_8 ( V_2 , V_51 ) ;
if ( F_22 ( V_24 , V_50 , F_25 ( V_55 , V_53 ) , & V_44 ) )
return 0 ;
return F_26 ( V_49 , V_44 , V_54 , V_55 , V_57 ) ;
}
int T_9 F_27 ( void )
{
int V_58 = F_28 ( & V_59 ) ;
if ( V_58 < 0 )
F_29 ( L_7 , V_58 ) ;
return V_58 ;
}
void F_30 ( void )
{
F_31 ( & V_59 ) ;
}
