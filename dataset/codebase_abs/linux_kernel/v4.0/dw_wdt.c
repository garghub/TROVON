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
F_19 ( & V_1 . V_34 ) ;
if ( ! F_1 () ) {
F_9 ( V_35 ) ;
F_8 ( V_4 ,
V_1 . V_2 + V_3 ) ;
}
F_6 () ;
F_20 ( & V_1 . V_34 ) ;
return F_21 ( V_29 , V_31 ) ;
}
static T_2 F_22 ( struct V_30 * V_31 , const char T_3 * V_36 ,
T_4 V_37 , T_5 * V_38 )
{
if ( ! V_37 )
return 0 ;
if ( ! V_25 ) {
T_4 V_14 ;
V_1 . V_39 = 0 ;
for ( V_14 = 0 ; V_14 < V_37 ; ++ V_14 ) {
char V_40 ;
if ( F_23 ( V_40 , V_36 + V_14 ) )
return - V_41 ;
if ( V_40 == 'V' ) {
V_1 . V_39 = 1 ;
break;
}
}
}
F_6 () ;
F_14 ( & V_1 . V_27 , V_9 + V_28 ) ;
return V_37 ;
}
static T_1 F_24 ( void )
{
return F_2 ( V_1 . V_2 + V_42 ) /
F_4 ( V_1 . V_6 ) ;
}
static long F_25 ( struct V_30 * V_31 , unsigned int V_21 , unsigned long V_43 )
{
unsigned long V_22 ;
int V_44 ;
switch ( V_21 ) {
case V_45 :
return F_26 ( ( void T_3 * ) V_43 , & V_46 ,
sizeof( V_46 ) ) ? - V_41 : 0 ;
case V_47 :
case V_48 :
return F_27 ( 0 , ( int T_3 * ) V_43 ) ;
case V_49 :
F_6 () ;
return 0 ;
case V_50 :
if ( F_23 ( V_22 , ( int T_3 * ) V_43 ) )
return - V_41 ;
V_44 = F_9 ( V_22 ) ;
return F_27 ( V_44 , ( int T_3 * ) V_43 ) ;
case V_51 :
return F_27 ( F_5 () , ( int T_3 * ) V_43 ) ;
case V_52 :
if ( F_23 ( V_22 , ( int T_3 * ) V_43 ) )
return - V_41 ;
return F_27 ( F_24 () , ( int T_3 * ) V_43 ) ;
default:
return - V_53 ;
}
}
static int F_28 ( struct V_29 * V_29 , struct V_30 * V_31 )
{
F_29 ( 0 , & V_1 . V_26 ) ;
if ( ! V_1 . V_39 ) {
F_30 ( & V_1 . V_27 ) ;
if ( ! V_25 )
F_15 ( L_2 ) ;
else
F_15 ( L_3 ) ;
}
V_1 . V_39 = 0 ;
return 0 ;
}
static int F_31 ( struct V_54 * V_55 )
{
F_32 ( V_1 . V_6 ) ;
return 0 ;
}
static int F_33 ( struct V_54 * V_55 )
{
int V_56 = F_34 ( V_1 . V_6 ) ;
if ( V_56 )
return V_56 ;
F_7 () ;
return 0 ;
}
static int F_35 ( struct V_57 * V_58 )
{
int V_59 ;
struct V_60 * V_61 = F_36 ( V_58 , V_62 , 0 ) ;
V_1 . V_2 = F_37 ( & V_58 -> V_55 , V_61 ) ;
if ( F_38 ( V_1 . V_2 ) )
return F_39 ( V_1 . V_2 ) ;
V_1 . V_6 = F_40 ( & V_58 -> V_55 , NULL ) ;
if ( F_38 ( V_1 . V_6 ) )
return F_39 ( V_1 . V_6 ) ;
V_59 = F_34 ( V_1 . V_6 ) ;
if ( V_59 )
return V_59 ;
F_41 ( & V_1 . V_34 ) ;
V_59 = F_42 ( & V_63 ) ;
if ( V_59 )
goto V_64;
V_1 . V_65 . V_66 = F_10 ;
V_1 . V_65 . V_67 = 128 ;
V_59 = F_43 ( & V_1 . V_65 ) ;
if ( V_59 )
F_44 ( L_4 ) ;
F_6 () ;
F_45 ( & V_1 . V_27 , F_12 , 0 ) ;
F_14 ( & V_1 . V_27 , V_9 + V_28 ) ;
return 0 ;
V_64:
F_32 ( V_1 . V_6 ) ;
return V_59 ;
}
static int F_46 ( struct V_57 * V_58 )
{
F_47 ( & V_1 . V_65 ) ;
F_48 ( & V_63 ) ;
F_32 ( V_1 . V_6 ) ;
return 0 ;
}
