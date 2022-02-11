static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
F_2 ( V_5 , V_6 ,
V_7 | V_8 | 1 ) ;
F_2 ( V_5 , V_9 , V_10 ) ;
F_3 ( 2000 ) ;
F_4 ( L_1 ) ;
return V_11 ;
}
static inline void F_5 ( void )
{
F_2 ( V_5 , V_6 , V_8 ) ;
}
static inline void F_6 ( void )
{
F_2 ( V_5 , V_6 , V_8 | V_7 |
( ( ( 65536 * V_12 ) >> 8 ) & V_13 ) ) ;
F_2 ( V_5 , V_9 , V_10 ) ;
}
static inline void F_7 ( void )
{
F_2 ( V_5 , V_9 , V_10 ) ;
}
static int F_8 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( F_9 ( 0 , & V_16 ) )
return - V_17 ;
F_6 () ;
return F_10 ( V_14 , V_15 ) ;
}
static int F_11 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
if ( ! V_18 )
F_5 () ;
F_12 ( 0 , & V_16 ) ;
return 0 ;
}
static int F_13 ( int V_19 )
{
if ( ( V_19 <= 0 ) || ( V_19 > V_20 ) )
return - V_21 ;
V_12 = V_19 ;
return 0 ;
}
static long F_14 ( struct V_15 * V_15 ,
unsigned int V_4 , unsigned long V_22 )
{
void T_1 * V_23 = ( void T_1 * ) V_22 ;
int T_1 * V_24 = V_23 ;
int V_25 ;
switch ( V_4 ) {
case V_26 :
return F_15 ( V_23 , & V_27 ,
sizeof( V_27 ) ) ? - V_28 : 0 ;
case V_29 :
case V_30 :
return F_16 ( 0 , V_24 ) ;
case V_31 :
if ( F_17 ( V_25 , V_24 ) )
return - V_28 ;
if ( V_25 & V_32 )
F_5 () ;
if ( V_25 & V_33 )
F_6 () ;
return 0 ;
case V_34 :
F_7 () ;
return 0 ;
case V_35 :
if ( F_17 ( V_25 , V_24 ) )
return - V_28 ;
if ( F_13 ( V_25 ) )
return - V_21 ;
F_6 () ;
return F_16 ( V_12 , V_24 ) ;
case V_36 :
return F_16 ( V_12 , V_24 ) ;
default:
return - V_37 ;
}
}
static T_2 F_18 ( struct V_15 * V_15 , const char * V_38 ,
T_3 V_39 , T_4 * V_40 )
{
F_7 () ;
return V_39 ;
}
static int F_19 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
struct V_43 * V_45 ;
int V_46 ;
if ( V_47 . V_45 )
return - V_17 ;
V_47 . V_45 = & V_42 -> V_44 ;
V_45 = V_44 -> V_45 ;
if ( ! V_45 ) {
F_20 ( V_44 , L_2 ) ;
return - V_48 ;
}
V_5 = F_21 ( V_45 -> V_49 ) ;
if ( ! V_5 )
return - V_48 ;
V_46 = F_22 ( & V_47 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_23 ( & V_50 ) ;
if ( V_46 )
F_24 ( V_44 , L_3 ) ;
F_25 ( L_4 ,
V_12 , V_18 ? L_5 : L_6 ) ;
return 0 ;
}
static int F_26 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_44 ;
int V_46 ;
V_46 = F_27 ( & V_50 ) ;
if ( V_46 )
F_24 ( V_44 , L_7 ) ;
V_46 = F_28 ( & V_47 ) ;
if ( ! V_46 )
V_47 . V_45 = NULL ;
return V_46 ;
}
static void F_29 ( struct V_41 * V_42 )
{
F_5 () ;
}
static int F_30 ( struct V_41 * V_42 , T_5 V_51 )
{
F_5 () ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 )
{
if ( V_16 )
F_6 () ;
return 0 ;
}
static int T_6 F_32 ( void )
{
if ( F_13 ( V_12 ) ) {
F_13 ( V_52 ) ;
F_25 ( L_8 ,
V_12 ) ;
}
return F_33 ( & V_53 ) ;
}
static void T_7 F_34 ( void )
{
F_35 ( & V_53 ) ;
}
