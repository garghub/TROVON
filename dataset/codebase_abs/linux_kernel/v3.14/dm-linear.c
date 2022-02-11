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
V_21 -> V_24 . V_20 =
F_8 ( V_2 , V_21 -> V_24 . V_20 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_21 * V_21 )
{
F_10 ( V_2 , V_21 ) ;
return V_25 ;
}
static void F_13 ( struct V_1 * V_2 , T_2 type ,
unsigned V_26 , char * V_27 , unsigned V_28 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_19 ;
switch ( type ) {
case V_29 :
V_27 [ 0 ] = '\0' ;
break;
case V_30 :
snprintf ( V_27 , V_28 , L_6 , V_6 -> V_15 -> V_31 ,
( unsigned long long ) V_6 -> V_13 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_32 ,
unsigned long V_33 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_19 ;
struct V_34 * V_15 = V_6 -> V_15 ;
int V_35 = 0 ;
if ( V_6 -> V_13 ||
V_2 -> V_36 != F_15 ( V_15 -> V_23 -> V_37 ) >> V_38 )
V_35 = F_16 ( NULL , V_32 ) ;
return V_35 ? : F_17 ( V_15 -> V_23 , V_15 -> V_39 , V_32 , V_33 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
struct V_45 * V_46 = F_19 ( V_6 -> V_15 -> V_23 ) ;
if ( ! V_46 -> V_47 )
return V_44 ;
V_41 -> V_22 = V_6 -> V_15 -> V_23 ;
V_41 -> V_20 = F_8 ( V_2 , V_41 -> V_20 ) ;
return F_20 ( V_44 , V_46 -> V_47 ( V_46 , V_41 , V_43 ) ) ;
}
static int F_21 ( struct V_1 * V_2 ,
T_3 V_48 , void * V_49 )
{
struct V_5 * V_6 = V_2 -> V_19 ;
return V_48 ( V_2 , V_6 -> V_15 , V_6 -> V_13 , V_2 -> V_36 , V_49 ) ;
}
int T_4 F_22 ( void )
{
int V_35 = F_23 ( & V_50 ) ;
if ( V_35 < 0 )
F_24 ( L_7 , V_35 ) ;
return V_35 ;
}
void F_25 ( void )
{
F_26 ( & V_50 ) ;
}
