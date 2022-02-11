static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline unsigned long F_3 ( int V_2 )
{
return F_4 ( V_3 + V_2 ) & 0xffffff ;
}
static inline void F_5 ( unsigned long V_4 )
{
if ( ! V_4 )
V_4 = 1 ;
F_1 ( V_4 , V_5 ) ;
F_1 ( 0x0f , V_6 ) ;
}
static inline void F_6 ( void )
{
F_1 ( 0x0 , V_6 ) ;
}
static int F_7 ( unsigned long V_7 ,
struct V_8 * V_9 )
{
F_5 ( V_7 ) ;
return 0 ;
}
static void F_8 ( enum V_10 V_11 ,
struct V_8 * V_12 )
{
F_6 () ;
switch ( V_11 ) {
case V_13 :
F_5 ( V_14 ) ;
break;
case V_15 :
case V_16 :
case V_17 :
break;
case V_18 :
break;
}
}
static T_1 F_9 ( int V_19 , void * V_20 )
{
struct V_8 * V_12 = & V_21 ;
F_10 () ;
V_12 -> V_22 ( V_12 ) ;
return V_23 ;
}
static T_2 void F_11 ( void )
{
F_12 ( V_24 , & V_25 ) ;
V_21 . V_26 = F_13 ( V_27 ,
V_28 ,
V_21 . V_29 ) ;
V_21 . V_30 =
F_14 ( 0xfffffffe , & V_21 ) ;
V_21 . V_31 =
F_14 ( 1 , & V_21 ) ;
V_21 . V_32 = F_15 ( 0 ) ;
F_16 ( & V_21 ) ;
}
bool T_2 F_17 ( void )
{
F_18 () ;
F_11 () ;
return true ;
}
