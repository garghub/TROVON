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
if ( F_11 ( V_23 ) || F_12 ( V_23 ) == V_26 )
V_23 -> V_27 . V_22 =
F_8 ( V_2 , V_23 -> V_27 . V_22 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
F_10 ( V_2 , V_23 ) ;
return V_28 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_23 * V_23 ,
T_2 * error )
{
struct V_5 * V_6 = V_2 -> V_21 ;
if ( ! * error && F_12 ( V_23 ) == V_29 )
F_15 ( V_2 , V_23 , V_6 -> V_14 ) ;
return V_30 ;
}
static void F_16 ( struct V_1 * V_2 , T_3 type ,
unsigned V_31 , char * V_32 , unsigned V_33 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
switch ( type ) {
case V_34 :
V_32 [ 0 ] = '\0' ;
break;
case V_35 :
snprintf ( V_32 , V_33 , L_6 , V_6 -> V_16 -> V_36 ,
( unsigned long long ) V_6 -> V_14 ) ;
break;
}
}
static int F_17 ( struct V_1 * V_2 ,
struct V_37 * * V_25 , T_4 * V_38 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_21 ;
struct V_39 * V_16 = V_6 -> V_16 ;
* V_25 = V_16 -> V_25 ;
if ( V_6 -> V_14 ||
V_2 -> V_40 != F_18 ( V_16 -> V_25 -> V_41 ) >> V_42 )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_5 V_43 , void * V_44 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
return V_43 ( V_2 , V_6 -> V_16 , V_6 -> V_14 , V_2 -> V_40 , V_44 ) ;
}
static long F_20 ( struct V_1 * V_2 , T_6 V_45 ,
long V_46 , void * * V_47 , T_7 * V_48 )
{
long V_9 ;
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_37 * V_25 = V_6 -> V_16 -> V_25 ;
struct V_49 * V_50 = V_6 -> V_16 -> V_50 ;
T_1 V_51 , V_52 = V_45 * V_53 ;
V_51 = F_8 ( V_2 , V_52 ) ;
V_9 = F_21 ( V_25 , V_51 , V_46 * V_54 , & V_45 ) ;
if ( V_9 )
return V_9 ;
return F_22 ( V_50 , V_45 , V_46 , V_47 , V_48 ) ;
}
static T_8 F_23 ( struct V_1 * V_2 , T_6 V_45 ,
void * V_55 , T_8 V_56 , struct V_57 * V_58 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_37 * V_25 = V_6 -> V_16 -> V_25 ;
struct V_49 * V_50 = V_6 -> V_16 -> V_50 ;
T_1 V_51 , V_52 = V_45 * V_53 ;
V_51 = F_8 ( V_2 , V_52 ) ;
if ( F_21 ( V_25 , V_51 , F_24 ( V_56 , V_54 ) , & V_45 ) )
return 0 ;
return F_25 ( V_50 , V_45 , V_55 , V_56 , V_58 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_6 V_45 , void * V_55 ,
T_8 V_59 )
{
struct V_5 * V_6 = V_2 -> V_21 ;
struct V_37 * V_25 = V_6 -> V_16 -> V_25 ;
struct V_49 * V_50 = V_6 -> V_16 -> V_50 ;
T_1 V_51 , V_52 = V_45 * V_53 ;
V_51 = F_8 ( V_2 , V_52 ) ;
if ( F_21 ( V_25 , V_51 , F_24 ( V_59 , V_54 ) , & V_45 ) )
return;
F_27 ( V_50 , V_45 , V_55 , V_59 ) ;
}
int T_9 F_28 ( void )
{
int V_60 = F_29 ( & V_61 ) ;
if ( V_60 < 0 )
F_30 ( L_7 , V_60 ) ;
return V_60 ;
}
void F_31 ( void )
{
F_32 ( & V_61 ) ;
}
