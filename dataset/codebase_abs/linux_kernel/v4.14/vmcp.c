static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( F_3 ( V_1 , NULL ) , V_3 ) ;
return 0 ;
}
void T_1 F_4 ( void )
{
if ( ! V_4 )
return;
F_5 ( 0 , V_2 , 0 , 0 , 0 , false , L_1 , & V_5 ) ;
}
static void F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_8 = NULL ;
int V_9 , V_10 ;
V_10 = F_7 ( V_7 -> V_11 ) ;
V_9 = F_2 ( V_7 -> V_11 , V_3 ) >> V_12 ;
if ( V_10 > 2 )
V_8 = F_8 ( V_5 , V_9 , 0 , V_13 ) ;
if ( V_8 ) {
V_7 -> V_14 = ( char * ) F_9 ( V_8 ) ;
V_7 -> F_8 = 1 ;
return;
}
V_7 -> V_14 = ( char * ) F_10 ( V_13 | V_15 , V_10 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
int V_9 , V_10 ;
struct V_8 * V_8 ;
if ( ! V_7 -> V_14 )
return;
V_10 = F_7 ( V_7 -> V_11 ) ;
V_9 = F_2 ( V_7 -> V_11 , V_3 ) >> V_12 ;
if ( V_7 -> F_8 ) {
V_8 = F_12 ( ( unsigned long ) V_7 -> V_14 ) ;
F_13 ( V_5 , V_8 , V_9 ) ;
V_7 -> F_8 = 0 ;
} else {
F_14 ( ( unsigned long ) V_7 -> V_14 , V_10 ) ;
}
V_7 -> V_14 = NULL ;
}
static int F_15 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_6 * V_7 ;
if ( ! F_16 ( V_18 ) )
return - V_19 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_11 = V_3 ;
V_7 -> V_14 = NULL ;
V_7 -> V_21 = 0 ;
F_18 ( & V_7 -> V_22 ) ;
V_17 -> V_23 = V_7 ;
return F_19 ( V_16 , V_17 ) ;
}
static int F_20 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
struct V_6 * V_7 ;
V_7 = V_17 -> V_23 ;
V_17 -> V_23 = NULL ;
F_11 ( V_7 ) ;
F_21 ( V_7 ) ;
return 0 ;
}
static T_2
F_22 ( struct V_17 * V_17 , char T_3 * V_24 , T_4 V_25 , T_5 * V_26 )
{
T_2 V_27 ;
T_4 V_28 ;
struct V_6 * V_7 ;
V_7 = V_17 -> V_23 ;
if ( F_23 ( & V_7 -> V_22 ) )
return - V_29 ;
if ( ! V_7 -> V_14 ) {
F_24 ( & V_7 -> V_22 ) ;
return 0 ;
}
V_28 = F_25 ( T_4 , V_7 -> V_21 , V_7 -> V_11 ) ;
V_27 = F_26 ( V_24 , V_25 , V_26 ,
V_7 -> V_14 , V_28 ) ;
F_24 ( & V_7 -> V_22 ) ;
return V_27 ;
}
static T_2
F_27 ( struct V_17 * V_17 , const char T_3 * V_24 , T_4 V_25 ,
T_5 * V_26 )
{
char * V_30 ;
struct V_6 * V_7 ;
if ( V_25 > 240 )
return - V_31 ;
V_30 = F_28 ( V_24 , V_25 ) ;
if ( F_29 ( V_30 ) )
return F_30 ( V_30 ) ;
V_7 = V_17 -> V_23 ;
if ( F_23 ( & V_7 -> V_22 ) ) {
F_21 ( V_30 ) ;
return - V_29 ;
}
if ( ! V_7 -> V_14 )
F_6 ( V_7 ) ;
if ( ! V_7 -> V_14 ) {
F_24 ( & V_7 -> V_22 ) ;
F_21 ( V_30 ) ;
return - V_20 ;
}
F_31 ( V_32 , 1 , V_30 ) ;
V_7 -> V_21 = F_32 ( V_30 , V_7 -> V_14 , V_7 -> V_11 ,
& V_7 -> V_33 ) ;
F_24 ( & V_7 -> V_22 ) ;
F_21 ( V_30 ) ;
* V_26 = 0 ;
return V_25 ;
}
static long F_33 ( struct V_17 * V_17 , unsigned int V_30 , unsigned long V_34 )
{
struct V_6 * V_7 ;
int V_27 = - V_35 ;
int T_3 * V_36 ;
V_7 = V_17 -> V_23 ;
if ( F_34 () )
V_36 = F_35 ( V_34 ) ;
else
V_36 = ( int T_3 * ) V_34 ;
if ( F_23 ( & V_7 -> V_22 ) )
return - V_29 ;
switch ( V_30 ) {
case V_37 :
V_27 = F_36 ( V_7 -> V_33 , V_36 ) ;
break;
case V_38 :
F_11 ( V_7 ) ;
V_27 = F_37 ( V_7 -> V_11 , V_36 ) ;
if ( V_27 )
V_7 -> V_11 = V_3 ;
if ( ! V_7 -> V_11 || F_7 ( V_7 -> V_11 ) > 8 ) {
V_7 -> V_11 = V_3 ;
V_27 = - V_31 ;
}
break;
case V_39 :
V_27 = F_36 ( V_7 -> V_21 , V_36 ) ;
break;
default:
break;
}
F_24 ( & V_7 -> V_22 ) ;
return V_27 ;
}
static int T_1 F_38 ( void )
{
int V_27 ;
if ( ! V_4 )
return 0 ;
V_32 = F_39 ( L_1 , 1 , 1 , 240 ) ;
if ( ! V_32 )
return - V_20 ;
V_27 = F_40 ( V_32 , & V_40 ) ;
if ( V_27 ) {
F_41 ( V_32 ) ;
return V_27 ;
}
V_27 = F_42 ( & V_41 ) ;
if ( V_27 )
F_41 ( V_32 ) ;
return V_27 ;
}
