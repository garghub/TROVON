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
return NULL ;
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
F_16 ( & V_24 , F_17 ( V_8 ) , V_19 ,
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
struct V_12 * V_13 ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
int V_40 ;
int V_9 ;
T_3 V_41 ;
int V_42 ;
if ( F_15 ( ! F_5 ( V_8 ) -> V_14 ) ) {
V_42 = - V_43 ;
goto error;
}
V_13 = & F_5 ( V_8 ) -> V_14 -> V_15 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_44 = V_13 -> V_45 ;
V_37 . V_46 = V_13 -> V_47 ;
V_37 . V_48 = F_22 ( V_13 -> V_49 ) ;
V_37 . V_50 = V_8 -> V_51 ;
V_37 . V_52 = V_53 ;
V_39 = F_23 ( V_34 , & V_37 ) ;
if ( F_7 ( V_39 ) )
return F_24 ( V_39 ) ;
V_9 = F_25 ( V_13 -> V_16 ) ;
V_40 = F_26 ( V_39 -> V_54 . V_27 ) + V_39 -> V_54 . V_55
+ V_9 + sizeof( struct V_56 )
+ ( F_27 ( V_8 ) ? V_57 : 0 ) ;
if ( F_28 ( V_8 ) < V_40 || F_29 ( V_8 ) ) {
int V_58 = F_30 ( V_40 -
F_28 ( V_8 ) +
16 ) ;
V_42 = F_31 ( V_8 , F_32 ( int , V_58 , 0 ) ,
0 , V_59 ) ;
if ( F_15 ( V_42 ) )
goto V_60;
}
if ( F_27 ( V_8 ) ) {
if ( F_15 ( ! F_33 ( V_8 ,
V_8 -> V_61 ,
F_34 ( V_8 ) ) ) ) {
V_42 = - V_62 ;
goto V_60;
}
V_8 -> V_63 = 0 ;
}
V_8 = F_4 ( V_8 , V_9 ) ;
if ( F_15 ( ! V_8 ) ) {
V_42 = 0 ;
goto V_60;
}
V_41 = V_13 -> V_16 & V_64 ?
F_8 ( V_65 ) : 0 ;
V_8 -> V_66 = 1 ;
return F_35 ( V_8 -> V_67 , V_39 , V_8 , V_37 . V_46 ,
V_13 -> V_45 , V_53 ,
V_13 -> V_49 , V_13 -> V_68 , V_41 , false ) ;
V_60:
F_36 ( V_39 ) ;
error:
return V_42 ;
}
static int F_37 ( void )
{
int V_42 ;
V_69 ++ ;
if ( V_69 > 1 )
return 0 ;
V_42 = F_38 ( & V_70 ) ;
if ( V_42 )
F_39 ( L_1 ) ;
return V_42 ;
}
static void F_40 ( void )
{
V_69 -- ;
if ( V_69 > 0 )
return;
F_41 ( & V_70 ) ;
}
static const char * F_42 ( const struct V_26 * V_26 )
{
return F_43 ( V_26 ) ;
}
static struct V_26 * F_44 ( const struct V_71 * V_72 )
{
struct V_34 * V_34 = F_21 ( V_72 -> V_35 ) ;
struct V_25 * V_25 ;
struct V_26 * V_26 ;
int V_42 ;
V_42 = F_37 () ;
if ( V_42 )
return F_45 ( V_42 ) ;
V_25 = F_12 ( V_34 , V_28 ) ;
if ( F_46 ( V_25 -> V_29 . V_30 ) ) {
V_26 = F_45 ( - V_73 ) ;
goto error;
}
V_26 = F_47 ( V_74 , & V_75 , V_72 ) ;
if ( F_7 ( V_26 ) )
goto error;
strncpy ( F_43 ( V_26 ) , V_72 -> V_76 , V_74 ) ;
F_48 ( V_25 -> V_29 . V_30 , V_26 ) ;
return V_26 ;
error:
F_40 () ;
return V_26 ;
}
static void F_49 ( struct V_26 * V_26 )
{
struct V_34 * V_34 = F_21 ( V_26 -> V_35 ) ;
struct V_25 * V_25 ;
V_25 = F_12 ( V_34 , V_28 ) ;
F_50 ( V_25 -> V_29 . V_30 , NULL ) ;
F_51 ( V_26 ) ;
F_40 () ;
}
