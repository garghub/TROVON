static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline void F_3 ( unsigned long V_4 )
{
if ( ! V_4 )
V_4 = 1 ;
F_1 ( V_4 , V_5 ) ;
F_1 ( 0x0f , V_6 ) ;
}
static inline void F_4 ( void )
{
F_1 ( 0x0 , V_6 ) ;
}
static int F_5 ( unsigned long V_7 ,
struct V_8 * V_9 )
{
F_3 ( V_7 ) ;
return 0 ;
}
static void F_6 ( enum V_10 V_11 ,
struct V_8 * V_12 )
{
F_4 () ;
switch ( V_11 ) {
case V_13 :
F_3 ( V_14 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
break;
case V_18 :
break;
}
}
static T_1 F_7 ( int V_19 , void * V_20 )
{
struct V_8 * V_12 = & V_21 ;
F_8 () ;
V_12 -> V_22 ( V_12 ) ;
return V_23 ;
}
static T_2 void F_9 ( void )
{
F_10 ( V_24 , & V_25 ) ;
V_21 . V_26 = F_11 ( 0 ) ;
F_12 ( & V_21 ,
V_27 , 1 , 0xfffffffe ) ;
}
int T_2 F_13 ( void )
{
int V_28 = - V_29 ;
if ( F_14 () ) {
void T_3 * V_30 ;
struct V_31 * V_32 ;
V_30 = F_15 ( V_33 , V_34 ) ;
if ( ! V_30 ) {
F_16 ( L_1 ) ;
return - V_29 ;
}
V_32 = F_17 ( NULL , L_2 ) ;
if ( ! F_18 ( V_32 ) )
F_19 ( V_32 ) ;
V_28 = F_20 ( V_30 ) ;
}
if ( ! V_28 )
F_9 () ;
return V_28 ;
}
