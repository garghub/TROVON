static int F_1 ( char * V_1 , int * V_2 )
{
V_3 = V_1 ;
return 0 ;
}
static int F_2 ( char * V_1 , int * V_2 )
{
V_4 = V_1 ;
return 0 ;
}
static T_1 F_3 ( struct V_5 * V_5 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
void * V_12 ;
int V_13 ;
#ifdef F_4
F_5 ( V_14 L_1 , V_7 ) ;
#endif
V_12 = F_6 ( V_7 , V_15 ) ;
if ( V_12 == NULL )
return - V_16 ;
V_13 = F_7 ( V_10 -> V_17 , V_12 , V_7 ) ;
if ( V_13 < 0 )
goto V_18;
if ( F_8 ( V_6 , V_12 , V_13 ) )
V_13 = - V_19 ;
V_18:
F_9 ( V_12 ) ;
return V_13 ;
}
static T_1 F_10 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
void * V_12 ;
int V_13 ;
#ifdef F_4
F_5 ( V_14 L_2 , V_7 ) ;
#endif
V_12 = F_6 ( V_7 , V_15 ) ;
if ( V_12 == NULL )
return - V_16 ;
V_13 = - V_19 ;
if ( F_11 ( V_12 , V_6 , V_7 ) )
goto V_18;
V_13 = F_12 ( V_10 -> V_17 , V_12 , V_7 ) ;
if ( V_13 < 0 )
goto V_18;
* V_8 += V_13 ;
V_18:
F_9 ( V_12 ) ;
return V_13 ;
}
static unsigned int F_13 ( struct V_5 * V_5 ,
struct V_20 * V_21 )
{
unsigned int V_22 = 0 ;
#ifdef F_4
F_5 ( V_14 L_3 ) ;
#endif
return V_22 ;
}
static long F_14 ( struct V_5 * V_5 ,
unsigned int V_23 , unsigned long V_24 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
unsigned long V_25 = 0 ;
int V_13 ;
#ifdef F_4
F_5 ( V_14 L_4 , V_23 ) ;
#endif
switch( V_23 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
if ( F_15 ( V_25 , ( int T_2 * ) V_24 ) )
return - V_19 ;
break;
default:
break;
}
V_13 = F_16 ( V_10 -> V_17 , V_23 , ( unsigned long ) & V_25 ) ;
switch( V_23 ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
if ( F_17 ( V_25 , ( int T_2 * ) V_24 ) )
return - V_19 ;
break;
default:
break;
}
return V_13 ;
}
static int F_18 ( struct V_32 * V_32 , struct V_5 * V_5 )
{
struct V_9 * V_10 ;
int V_33 = 0 , V_34 = 0 ;
int V_35 ;
#ifdef F_4
F_19 ( V_3 ) ;
F_5 ( V_14 L_5 , V_3 ) ;
F_20 ( V_3 ) ;
#endif
V_10 = F_6 ( sizeof( struct V_9 ) , V_15 ) ;
if ( V_10 == NULL )
return - V_16 ;
if ( V_5 -> V_36 & V_37 )
V_33 = 1 ;
if ( V_5 -> V_36 & V_38 )
V_34 = 1 ;
F_19 ( V_3 ) ;
F_21 ( & V_39 ) ;
V_35 = F_22 ( V_3 , F_23 ( F_24 () , V_33 , V_34 ) , 0 ) ;
F_25 ( & V_39 ) ;
F_20 ( V_3 ) ;
if ( V_35 < 0 ) {
F_9 ( V_10 ) ;
return V_35 ;
}
V_10 -> V_17 = V_35 ;
V_5 -> V_11 = V_10 ;
return 0 ;
}
static int F_26 ( struct V_32 * V_32 , struct V_5 * V_5 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
#ifdef F_4
F_5 ( V_14 L_6 ) ;
#endif
F_27 ( V_10 -> V_17 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static long F_28 ( struct V_5 * V_5 ,
unsigned int V_23 , unsigned long V_24 )
{
struct V_40 * V_10 = V_5 -> V_11 ;
#ifdef F_4
F_5 ( V_14 L_7 ) ;
#endif
return F_16 ( V_10 -> V_17 , V_23 , V_24 ) ;
}
static int F_29 ( struct V_32 * V_32 , struct V_5 * V_5 )
{
struct V_40 * V_10 ;
int V_33 = 0 , V_34 = 0 ;
int V_35 ;
#ifdef F_4
F_5 ( V_14 L_8 , V_4 ) ;
#endif
V_10 = F_6 ( sizeof( struct V_40 ) , V_15 ) ;
if ( V_10 == NULL )
return - V_16 ;
if ( V_5 -> V_36 & V_37 )
V_33 = 1 ;
if ( V_5 -> V_36 & V_38 )
V_34 = 1 ;
F_19 ( V_4 ) ;
F_21 ( & V_39 ) ;
V_35 = F_22 ( V_4 , F_23 ( F_24 () , V_33 , V_34 ) , 0 ) ;
F_25 ( & V_39 ) ;
F_20 ( V_4 ) ;
if ( V_35 < 0 ) {
F_19 ( V_3 ) ;
F_5 ( V_41 L_9
L_10 , V_3 , - V_35 ) ;
F_20 ( V_3 ) ;
F_9 ( V_10 ) ;
return V_35 ;
}
V_5 -> V_11 = V_10 ;
return 0 ;
}
static int F_30 ( struct V_32 * V_32 , struct V_5 * V_5 )
{
struct V_40 * V_10 = V_5 -> V_11 ;
#ifdef F_4
F_5 ( V_14 L_11 ) ;
#endif
F_27 ( V_10 -> V_17 ) ;
F_9 ( V_10 ) ;
return 0 ;
}
static int T_5 F_31 ( void )
{
F_32 () ;
F_5 ( V_42 L_12 ,
V_3 , V_4 ) ;
F_33 () ;
V_43 . V_44 = F_34 ( & V_45 , - 1 ) ;
if ( V_43 . V_44 < 0 ) {
F_5 ( V_41 L_13 ) ;
return - V_46 ;
}
V_43 . V_47 = F_35 ( & V_48 , - 1 ) ;
if ( V_43 . V_47 < 0 ) {
F_5 ( V_41 L_14
L_15 ) ;
F_36 ( V_43 . V_44 ) ;
return - V_46 ;
}
return 0 ;
}
static void T_6 F_37 ( void )
{
F_38 ( V_43 . V_47 ) ;
F_36 ( V_43 . V_44 ) ;
}
