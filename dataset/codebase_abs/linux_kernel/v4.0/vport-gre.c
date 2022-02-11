static T_1 F_1 ( T_2 V_1 )
{
#ifdef F_2
return ( V_2 T_1 ) V_1 ;
#else
return ( V_2 T_1 ) ( ( V_2 V_3 ) V_1 >> 32 ) ;
#endif
}
static T_3 F_3 ( T_3 V_4 )
{
return V_4 & ( V_5 | V_6 ) ;
}
static struct V_7 * F_4 ( struct V_7 * V_8 ,
int V_9 )
{
struct V_10 V_11 ;
const struct V_12 * V_13 ;
V_13 = & F_5 ( V_8 ) -> V_14 -> V_15 ;
V_8 = F_6 ( V_8 , ! ! ( V_13 -> V_16 & V_5 ) ) ;
if ( F_7 ( V_8 ) )
return V_8 ;
V_11 . V_4 = F_3 ( V_13 -> V_16 ) ;
V_11 . V_17 = F_8 ( V_18 ) ;
V_11 . V_19 = F_1 ( V_13 -> V_20 ) ;
V_11 . V_21 = 0 ;
F_9 ( V_8 , & V_11 , V_9 ) ;
return V_8 ;
}
static T_2 F_10 ( T_1 V_19 , T_1 V_21 )
{
#ifdef F_2
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_21 << 32 | ( V_2 V_22 ) V_19 ) ;
#else
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_19 << 32 | ( V_2 V_22 ) V_21 ) ;
#endif
}
static int F_11 ( struct V_7 * V_8 ,
const struct V_10 * V_11 )
{
struct V_23 V_24 ;
struct V_25 * V_25 ;
struct V_26 * V_26 ;
T_2 V_19 ;
V_25 = F_12 ( F_13 ( V_8 -> V_27 ) , V_28 ) ;
V_26 = F_14 ( V_25 -> V_29 . V_30 ) ;
if ( F_15 ( ! V_26 ) )
return V_31 ;
V_19 = F_10 ( V_11 -> V_19 , V_11 -> V_21 ) ;
F_16 ( & V_24 , F_17 ( V_8 ) , 0 , 0 , V_19 ,
F_3 ( V_11 -> V_4 ) , NULL , 0 ) ;
F_18 ( V_26 , V_8 , & V_24 ) ;
return V_32 ;
}
static int F_19 ( struct V_7 * V_8 , V_22 V_33 ,
const struct V_10 * V_11 )
{
struct V_25 * V_25 ;
struct V_26 * V_26 ;
V_25 = F_12 ( F_13 ( V_8 -> V_27 ) , V_28 ) ;
V_26 = F_14 ( V_25 -> V_29 . V_30 ) ;
if ( F_15 ( ! V_26 ) )
return V_31 ;
else
return V_32 ;
}
static int F_20 ( struct V_26 * V_26 , struct V_7 * V_8 )
{
struct V_34 * V_34 = F_21 ( V_26 -> V_35 ) ;
const struct V_12 * V_13 ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
int V_40 ;
int V_9 ;
T_3 V_41 ;
int V_42 ;
if ( F_15 ( ! F_5 ( V_8 ) -> V_14 ) ) {
V_42 = - V_43 ;
goto V_44;
}
V_13 = & F_5 ( V_8 ) -> V_14 -> V_15 ;
V_39 = F_22 ( V_34 , V_13 , V_8 -> V_45 , & V_37 , V_46 ) ;
if ( F_7 ( V_39 ) ) {
V_42 = F_23 ( V_39 ) ;
goto V_44;
}
V_9 = F_24 ( V_13 -> V_16 ) ;
V_40 = F_25 ( V_39 -> V_47 . V_27 ) + V_39 -> V_47 . V_48
+ V_9 + sizeof( struct V_49 )
+ ( F_26 ( V_8 ) ? V_50 : 0 ) ;
if ( F_27 ( V_8 ) < V_40 || F_28 ( V_8 ) ) {
int V_51 = F_29 ( V_40 -
F_27 ( V_8 ) +
16 ) ;
V_42 = F_30 ( V_8 , F_31 ( int , V_51 , 0 ) ,
0 , V_52 ) ;
if ( F_15 ( V_42 ) )
goto V_53;
}
V_8 = F_32 ( V_8 ) ;
if ( F_15 ( ! V_8 ) ) {
V_42 = - V_54 ;
goto V_53;
}
V_8 = F_4 ( V_8 , V_9 ) ;
if ( F_7 ( V_8 ) ) {
V_42 = F_23 ( V_8 ) ;
V_8 = NULL ;
goto V_53;
}
V_41 = V_13 -> V_16 & V_55 ?
F_8 ( V_56 ) : 0 ;
V_8 -> V_57 = 1 ;
return F_33 ( V_8 -> V_58 , V_39 , V_8 , V_37 . V_59 ,
V_13 -> V_60 , V_46 ,
V_13 -> V_61 , V_13 -> V_62 , V_41 , false ) ;
V_53:
F_34 ( V_39 ) ;
V_44:
F_35 ( V_8 ) ;
return V_42 ;
}
static int F_36 ( void )
{
int V_42 ;
V_63 ++ ;
if ( V_63 > 1 )
return 0 ;
V_42 = F_37 ( & V_64 ) ;
if ( V_42 )
F_38 ( L_1 ) ;
return V_42 ;
}
static void F_39 ( void )
{
V_63 -- ;
if ( V_63 > 0 )
return;
F_40 ( & V_64 ) ;
}
static const char * F_41 ( const struct V_26 * V_26 )
{
return F_42 ( V_26 ) ;
}
static struct V_26 * F_43 ( const struct V_65 * V_66 )
{
struct V_34 * V_34 = F_21 ( V_66 -> V_35 ) ;
struct V_25 * V_25 ;
struct V_26 * V_26 ;
int V_42 ;
V_42 = F_36 () ;
if ( V_42 )
return F_44 ( V_42 ) ;
V_25 = F_12 ( V_34 , V_28 ) ;
if ( F_45 ( V_25 -> V_29 . V_30 ) ) {
V_26 = F_44 ( - V_67 ) ;
goto error;
}
V_26 = F_46 ( V_68 , & V_69 , V_66 ) ;
if ( F_7 ( V_26 ) )
goto error;
strncpy ( F_42 ( V_26 ) , V_66 -> V_70 , V_68 ) ;
F_47 ( V_25 -> V_29 . V_30 , V_26 ) ;
return V_26 ;
error:
F_39 () ;
return V_26 ;
}
static void F_48 ( struct V_26 * V_26 )
{
struct V_34 * V_34 = F_21 ( V_26 -> V_35 ) ;
struct V_25 * V_25 ;
V_25 = F_12 ( V_34 , V_28 ) ;
F_49 ( V_25 -> V_29 . V_30 , NULL ) ;
F_50 ( V_26 ) ;
F_39 () ;
}
static int F_51 ( struct V_26 * V_26 , struct V_7 * V_8 ,
struct V_23 * V_14 )
{
return F_52 ( V_14 ,
F_21 ( V_26 -> V_35 ) ,
F_5 ( V_8 ) -> V_14 ,
V_46 , V_8 -> V_45 , 0 , 0 ) ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_69 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_69 ) ;
}
