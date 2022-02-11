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
static void F_7 ( void )
{
F_8 ( V_11 , V_1 . V_2 +
V_12 ) ;
}
static int F_9 ( unsigned V_13 )
{
int V_14 , V_15 = V_16 ;
for ( V_14 = 0 ; V_14 <= V_16 ; ++ V_14 )
if ( F_3 ( V_14 ) >= V_13 ) {
V_15 = V_14 ;
break;
}
F_8 ( V_15 | V_15 << V_17 ,
V_1 . V_2 + V_7 ) ;
F_7 () ;
F_6 () ;
return F_3 ( V_15 ) ;
}
static int F_10 ( struct V_18 * V_19 ,
unsigned long V_20 , void * V_21 )
{
T_1 V_22 ;
F_8 ( 0 , V_1 . V_2 + V_7 ) ;
V_22 = F_2 ( V_1 . V_2 + V_3 ) ;
if ( V_22 & V_4 )
F_8 ( V_11 , V_1 . V_2 +
V_12 ) ;
else
F_8 ( V_4 ,
V_1 . V_2 + V_3 ) ;
F_11 ( 500 ) ;
return V_23 ;
}
static void F_12 ( unsigned long V_24 )
{
if ( F_13 ( V_9 , V_1 . V_8 ) ||
( ! V_25 && ! V_1 . V_26 ) ) {
F_7 () ;
F_14 ( & V_1 . V_27 , V_9 + V_28 ) ;
} else
F_15 ( L_1 ) ;
}
static int F_16 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
if ( F_17 ( 0 , & V_1 . V_26 ) )
return - V_32 ;
F_18 ( V_33 ) ;
if ( ! F_1 () ) {
F_9 ( V_34 ) ;
F_8 ( V_4 ,
V_1 . V_2 + V_3 ) ;
}
F_6 () ;
return F_19 ( V_29 , V_31 ) ;
}
static T_2 F_20 ( struct V_30 * V_31 , const char T_3 * V_35 ,
T_4 V_36 , T_5 * V_37 )
{
if ( ! V_36 )
return 0 ;
if ( ! V_25 ) {
T_4 V_14 ;
V_1 . V_38 = 0 ;
for ( V_14 = 0 ; V_14 < V_36 ; ++ V_14 ) {
char V_39 ;
if ( F_21 ( V_39 , V_35 + V_14 ) )
return - V_40 ;
if ( V_39 == 'V' ) {
V_1 . V_38 = 1 ;
break;
}
}
}
F_6 () ;
F_7 () ;
F_14 ( & V_1 . V_27 , V_9 + V_28 ) ;
return V_36 ;
}
static T_1 F_22 ( void )
{
return F_2 ( V_1 . V_2 + V_41 ) /
F_4 ( V_1 . V_6 ) ;
}
static long F_23 ( struct V_30 * V_31 , unsigned int V_21 , unsigned long V_42 )
{
unsigned long V_22 ;
int V_43 ;
switch ( V_21 ) {
case V_44 :
return F_24 ( ( void T_3 * ) V_42 , & V_45 ,
sizeof( V_45 ) ) ? - V_40 : 0 ;
case V_46 :
case V_47 :
return F_25 ( 0 , ( int T_3 * ) V_42 ) ;
case V_48 :
F_6 () ;
return 0 ;
case V_49 :
if ( F_21 ( V_22 , ( int T_3 * ) V_42 ) )
return - V_40 ;
V_43 = F_9 ( V_22 ) ;
return F_25 ( V_43 , ( int T_3 * ) V_42 ) ;
case V_50 :
return F_25 ( F_5 () , ( int T_3 * ) V_42 ) ;
case V_51 :
if ( F_21 ( V_22 , ( int T_3 * ) V_42 ) )
return - V_40 ;
return F_25 ( F_22 () , ( int T_3 * ) V_42 ) ;
default:
return - V_52 ;
}
}
static int F_26 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
F_27 ( 0 , & V_1 . V_26 ) ;
if ( ! V_1 . V_38 ) {
F_28 ( & V_1 . V_27 ) ;
if ( ! V_25 )
F_15 ( L_2 ) ;
else
F_15 ( L_3 ) ;
}
V_1 . V_38 = 0 ;
return 0 ;
}
static int F_29 ( struct V_53 * V_54 )
{
F_30 ( V_1 . V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_53 * V_54 )
{
int V_55 = F_32 ( V_1 . V_6 ) ;
if ( V_55 )
return V_55 ;
F_7 () ;
return 0 ;
}
static int F_33 ( struct V_56 * V_57 )
{
int V_58 ;
struct V_59 * V_60 = F_34 ( V_57 , V_61 , 0 ) ;
V_1 . V_2 = F_35 ( & V_57 -> V_54 , V_60 ) ;
if ( F_36 ( V_1 . V_2 ) )
return F_37 ( V_1 . V_2 ) ;
V_1 . V_6 = F_38 ( & V_57 -> V_54 , NULL ) ;
if ( F_36 ( V_1 . V_6 ) )
return F_37 ( V_1 . V_6 ) ;
V_58 = F_32 ( V_1 . V_6 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_39 ( & V_62 ) ;
if ( V_58 )
goto V_63;
V_1 . V_64 . V_65 = F_10 ;
V_1 . V_64 . V_66 = 128 ;
V_58 = F_40 ( & V_1 . V_64 ) ;
if ( V_58 )
F_41 ( L_4 ) ;
F_6 () ;
F_42 ( & V_1 . V_27 , F_12 , 0 ) ;
F_14 ( & V_1 . V_27 , V_9 + V_28 ) ;
return 0 ;
V_63:
F_30 ( V_1 . V_6 ) ;
return V_58 ;
}
static int F_43 ( struct V_56 * V_57 )
{
F_44 ( & V_1 . V_64 ) ;
F_45 ( & V_62 ) ;
F_30 ( V_1 . V_6 ) ;
return 0 ;
}
