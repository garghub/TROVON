static inline int F_1 ( void )
{
return F_2 ( V_1 . V_2 + V_3 ) &
V_4 ;
}
static inline int F_3 ( unsigned V_5 )
{
return ( 1 << ( 16 + V_5 ) ) / F_4 ( V_1 . V_6 ) ;
}
static int F_5 ( void )
{
int V_5 = F_2 ( V_1 . V_2 + V_7 ) & 0xF ;
return F_3 ( V_5 ) ;
}
static inline void F_6 ( void )
{
V_1 . V_8 = V_9 + F_5 () * V_10 ;
}
static int F_7 ( unsigned V_11 )
{
int V_12 , V_13 = V_14 ;
for ( V_12 = 0 ; V_12 <= V_14 ; ++ V_12 )
if ( F_3 ( V_12 ) >= V_11 ) {
V_13 = V_12 ;
break;
}
F_8 ( V_13 , V_1 . V_2 + V_7 ) ;
F_6 () ;
return F_3 ( V_13 ) ;
}
static void F_9 ( void )
{
F_8 ( V_15 , V_1 . V_2 +
V_16 ) ;
}
static void F_10 ( unsigned long V_17 )
{
if ( F_11 ( V_9 , V_1 . V_8 ) ||
( ! V_18 && ! V_1 . V_19 ) ) {
F_9 () ;
F_12 ( & V_1 . V_20 , V_9 + V_21 ) ;
} else
F_13 ( L_1 ) ;
}
static int F_14 ( struct V_22 * V_22 , struct V_23 * V_24 )
{
if ( F_15 ( 0 , & V_1 . V_19 ) )
return - V_25 ;
F_16 ( V_26 ) ;
F_17 ( & V_1 . V_27 ) ;
if ( ! F_1 () ) {
F_7 ( V_14 ) ;
F_8 ( V_4 ,
V_1 . V_2 + V_3 ) ;
}
F_6 () ;
F_18 ( & V_1 . V_27 ) ;
return F_19 ( V_22 , V_24 ) ;
}
static T_1 F_20 ( struct V_23 * V_24 , const char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
if ( ! V_29 )
return 0 ;
if ( ! V_18 ) {
T_3 V_12 ;
V_1 . V_31 = 0 ;
for ( V_12 = 0 ; V_12 < V_29 ; ++ V_12 ) {
char V_32 ;
if ( F_21 ( V_32 , V_28 + V_12 ) )
return - V_33 ;
if ( V_32 == 'V' ) {
V_1 . V_31 = 1 ;
break;
}
}
}
F_6 () ;
F_12 ( & V_1 . V_20 , V_9 + V_21 ) ;
return V_29 ;
}
static T_5 F_22 ( void )
{
return F_2 ( V_1 . V_2 + V_34 ) /
F_4 ( V_1 . V_6 ) ;
}
static long F_23 ( struct V_23 * V_24 , unsigned int V_35 , unsigned long V_36 )
{
unsigned long V_37 ;
int V_38 ;
switch ( V_35 ) {
case V_39 :
return F_24 ( ( void T_2 * ) V_36 , & V_40 ,
sizeof( V_40 ) ) ? - V_33 : 0 ;
case V_41 :
case V_42 :
return F_25 ( 0 , ( int T_2 * ) V_36 ) ;
case V_43 :
F_6 () ;
return 0 ;
case V_44 :
if ( F_21 ( V_37 , ( int T_2 * ) V_36 ) )
return - V_33 ;
V_38 = F_7 ( V_37 ) ;
return F_25 ( V_38 , ( int T_2 * ) V_36 ) ;
case V_45 :
return F_25 ( F_5 () , ( int T_2 * ) V_36 ) ;
case V_46 :
if ( F_21 ( V_37 , ( int T_2 * ) V_36 ) )
return - V_33 ;
return F_25 ( F_22 () , ( int T_2 * ) V_36 ) ;
default:
return - V_47 ;
}
}
static int F_26 ( struct V_22 * V_22 , struct V_23 * V_24 )
{
F_27 ( 0 , & V_1 . V_19 ) ;
if ( ! V_1 . V_31 ) {
F_28 ( & V_1 . V_20 ) ;
if ( ! V_18 )
F_13 ( L_2 ) ;
else
F_13 ( L_3 ) ;
}
V_1 . V_31 = 0 ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 )
{
F_30 ( V_1 . V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_48 * V_49 )
{
int V_50 = F_32 ( V_1 . V_6 ) ;
if ( V_50 )
return V_50 ;
F_9 () ;
return 0 ;
}
static int F_33 ( struct V_51 * V_52 )
{
int V_53 ;
struct V_54 * V_55 = F_34 ( V_52 , V_56 , 0 ) ;
if ( ! V_55 )
return - V_57 ;
V_1 . V_2 = F_35 ( & V_52 -> V_49 , V_55 ) ;
if ( F_36 ( V_1 . V_2 ) )
return F_37 ( V_1 . V_2 ) ;
V_1 . V_6 = F_38 ( & V_52 -> V_49 , NULL ) ;
if ( F_36 ( V_1 . V_6 ) )
return F_37 ( V_1 . V_6 ) ;
V_53 = F_32 ( V_1 . V_6 ) ;
if ( V_53 )
return V_53 ;
F_39 ( & V_1 . V_27 ) ;
V_53 = F_40 ( & V_58 ) ;
if ( V_53 )
goto V_59;
F_6 () ;
F_41 ( & V_1 . V_20 , F_10 , 0 ) ;
F_12 ( & V_1 . V_20 , V_9 + V_21 ) ;
return 0 ;
V_59:
F_30 ( V_1 . V_6 ) ;
return V_53 ;
}
static int F_42 ( struct V_51 * V_52 )
{
F_43 ( & V_58 ) ;
F_30 ( V_1 . V_6 ) ;
return 0 ;
}
