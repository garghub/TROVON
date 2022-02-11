static inline void F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 ) ;
V_1 = F_3 ( V_3 + V_4 ) ;
F_4 ( V_1 & ~ V_5 , V_3 + V_4 ) ;
F_5 ( & V_2 ) ;
}
static inline void F_6 ( void )
{
unsigned long V_1 ;
unsigned long V_6 = V_7 * V_8 ;
F_2 ( & V_2 ) ;
V_1 = F_3 ( V_3 + V_4 ) ;
F_4 ( V_1 & ~ V_5 , V_3 + V_4 ) ;
F_4 ( V_6 | V_9 , V_3 + V_10 ) ;
V_1 = F_3 ( V_3 + V_4 ) ;
F_4 ( V_1 | V_5 , V_3 + V_4 ) ;
F_5 ( & V_2 ) ;
}
static inline void F_7 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 ) ;
V_1 = F_3 ( V_3 + V_4 ) ;
F_4 ( V_1 & ~ V_5 , V_3 + V_4 ) ;
F_4 ( V_1 | V_5 , V_3 + V_4 ) ;
F_5 ( & V_2 ) ;
}
static int F_8 ( int V_11 )
{
if ( ( V_11 <= 0 ) || ( V_11 > V_12 ) )
return - V_13 ;
V_7 = V_11 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( F_10 ( 0 , & V_16 ) )
return - V_17 ;
F_6 () ;
return F_11 ( V_14 , V_15 ) ;
}
static int F_12 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( ! V_18 )
F_1 () ;
F_13 ( 0 , & V_16 ) ;
return 0 ;
}
static long F_14 ( struct V_15 * V_15 , unsigned int V_19 ,
unsigned long V_20 )
{
void T_1 * V_21 = ( void T_1 * ) V_20 ;
int T_1 * V_22 = V_21 ;
int V_23 ;
switch ( V_19 ) {
case V_24 :
return F_15 ( V_21 , & V_25 ,
sizeof( V_25 ) ) ? - V_26 : 0 ;
case V_27 :
case V_28 :
return F_16 ( 0 , V_22 ) ;
case V_29 :
if ( F_17 ( V_23 , V_22 ) )
return - V_26 ;
if ( V_23 & V_30 )
F_1 () ;
if ( V_23 & V_31 )
F_6 () ;
return 0 ;
case V_32 :
F_7 () ;
return 0 ;
case V_33 :
if ( F_17 ( V_23 , V_22 ) )
return - V_26 ;
if ( F_8 ( V_23 ) )
return - V_13 ;
F_6 () ;
return F_16 ( V_7 , V_22 ) ;
case V_34 :
return F_16 ( V_7 , V_22 ) ;
default:
return - V_35 ;
}
}
static T_2 F_18 ( struct V_15 * V_15 , const char * V_36 ,
T_3 V_37 , T_4 * V_38 )
{
F_7 () ;
return V_37 ;
}
static int F_19 ( struct V_39 * V_40 )
{
int V_41 ;
if ( V_42 . V_43 )
return - V_17 ;
V_42 . V_43 = & V_40 -> V_44 ;
V_41 = F_20 ( & V_42 ) ;
if ( V_41 )
return V_41 ;
F_21 ( L_1 ,
V_7 , V_18 ? L_2 : L_3 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_40 )
{
int V_41 ;
V_41 = F_23 ( & V_42 ) ;
if ( ! V_41 )
V_42 . V_43 = NULL ;
return V_41 ;
}
static void F_24 ( struct V_39 * V_40 )
{
F_1 () ;
}
static int F_25 ( struct V_39 * V_40 , T_5 V_45 )
{
F_1 () ;
return 0 ;
}
static int F_26 ( struct V_39 * V_40 )
{
if ( V_16 )
F_6 () ;
return 0 ;
}
static int T_6 F_27 ( void )
{
if ( F_8 ( V_7 ) ) {
F_8 ( V_46 ) ;
F_21 ( L_4
L_5 , V_7 , V_12 ) ;
}
return F_28 ( & V_47 ) ;
}
static void T_7 F_29 ( void )
{
F_30 ( & V_47 ) ;
}
