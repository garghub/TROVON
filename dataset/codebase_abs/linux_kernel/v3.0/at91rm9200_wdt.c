static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
}
static inline void F_3 ( void )
{
F_2 ( V_1 , V_2 | V_3 |
( ( ( 65536 * V_4 ) >> 8 ) & V_5 ) ) ;
F_2 ( V_6 , V_7 ) ;
}
static inline void F_4 ( void )
{
F_2 ( V_6 , V_7 ) ;
}
static int F_5 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
if ( F_6 ( 0 , & V_10 ) )
return - V_11 ;
F_3 () ;
return F_7 ( V_8 , V_9 ) ;
}
static int F_8 ( struct V_8 * V_8 , struct V_9 * V_9 )
{
if ( ! V_12 )
F_1 () ;
F_9 ( 0 , & V_10 ) ;
return 0 ;
}
static int F_10 ( int V_13 )
{
if ( ( V_13 <= 0 ) || ( V_13 > V_14 ) )
return - V_15 ;
V_4 = V_13 ;
return 0 ;
}
static long F_11 ( struct V_9 * V_9 ,
unsigned int V_16 , unsigned long V_17 )
{
void T_1 * V_18 = ( void T_1 * ) V_17 ;
int T_1 * V_19 = V_18 ;
int V_20 ;
switch ( V_16 ) {
case V_21 :
return F_12 ( V_18 , & V_22 ,
sizeof( V_22 ) ) ? - V_23 : 0 ;
case V_24 :
case V_25 :
return F_13 ( 0 , V_19 ) ;
case V_26 :
if ( F_14 ( V_20 , V_19 ) )
return - V_23 ;
if ( V_20 & V_27 )
F_1 () ;
if ( V_20 & V_28 )
F_3 () ;
return 0 ;
case V_29 :
F_4 () ;
return 0 ;
case V_30 :
if ( F_14 ( V_20 , V_19 ) )
return - V_23 ;
if ( F_10 ( V_20 ) )
return - V_15 ;
F_3 () ;
return F_13 ( V_4 , V_19 ) ;
case V_31 :
return F_13 ( V_4 , V_19 ) ;
default:
return - V_32 ;
}
}
static T_2 F_15 ( struct V_9 * V_9 , const char * V_33 ,
T_3 V_34 , T_4 * V_35 )
{
F_4 () ;
return V_34 ;
}
static int T_5 F_16 ( struct V_36 * V_37 )
{
int V_38 ;
if ( V_39 . V_40 )
return - V_11 ;
V_39 . V_40 = & V_37 -> V_41 ;
V_38 = F_17 ( & V_39 ) ;
if ( V_38 )
return V_38 ;
F_18 ( V_42 L_1 ,
V_4 , V_12 ? L_2 : L_3 ) ;
return 0 ;
}
static int T_6 F_19 ( struct V_36 * V_37 )
{
int V_38 ;
V_38 = F_20 ( & V_39 ) ;
if ( ! V_38 )
V_39 . V_40 = NULL ;
return V_38 ;
}
static void F_21 ( struct V_36 * V_37 )
{
F_1 () ;
}
static int F_22 ( struct V_36 * V_37 , T_7 V_43 )
{
F_1 () ;
return 0 ;
}
static int F_23 ( struct V_36 * V_37 )
{
if ( V_10 )
F_3 () ;
return 0 ;
}
static int T_8 F_24 ( void )
{
if ( F_10 ( V_4 ) ) {
F_10 ( V_44 ) ;
F_25 ( L_4
L_5 , V_4 ) ;
}
return F_26 ( & V_45 ) ;
}
static void T_9 F_27 ( void )
{
F_28 ( & V_45 ) ;
}
