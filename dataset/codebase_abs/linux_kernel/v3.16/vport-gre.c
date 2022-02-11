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
const struct V_10 * V_11 = F_5 ( V_8 ) -> V_11 ;
struct V_12 V_13 ;
V_8 = F_6 ( V_8 , ! ! ( V_11 -> V_14 & V_5 ) ) ;
if ( F_7 ( V_8 ) )
return NULL ;
V_13 . V_4 = F_3 ( V_11 -> V_14 ) ;
V_13 . V_15 = F_8 ( V_16 ) ;
V_13 . V_17 = F_1 ( V_11 -> V_18 ) ;
V_13 . V_19 = 0 ;
F_9 ( V_8 , & V_13 , V_9 ) ;
return V_8 ;
}
static T_2 F_10 ( T_1 V_17 , T_1 V_19 )
{
#ifdef F_2
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_19 << 32 | ( V_2 V_20 ) V_17 ) ;
#else
return ( V_2 T_2 ) ( ( V_2 V_3 ) V_17 << 32 | ( V_2 V_20 ) V_19 ) ;
#endif
}
static int F_11 ( struct V_7 * V_8 ,
const struct V_12 * V_13 )
{
struct V_10 V_11 ;
struct V_21 * V_21 ;
struct V_22 * V_22 ;
T_2 V_17 ;
V_21 = F_12 ( F_13 ( V_8 -> V_23 ) , V_24 ) ;
V_22 = F_14 ( V_21 -> V_25 . V_26 ) ;
if ( F_15 ( ! V_22 ) )
return V_27 ;
V_17 = F_10 ( V_13 -> V_17 , V_13 -> V_19 ) ;
F_16 ( & V_11 , F_17 ( V_8 ) , V_17 ,
F_3 ( V_13 -> V_4 ) ) ;
F_18 ( V_22 , V_8 , & V_11 ) ;
return V_28 ;
}
static int F_19 ( struct V_7 * V_8 , V_20 V_29 ,
const struct V_12 * V_13 )
{
struct V_21 * V_21 ;
struct V_22 * V_22 ;
V_21 = F_12 ( F_13 ( V_8 -> V_23 ) , V_24 ) ;
V_22 = F_14 ( V_21 -> V_25 . V_26 ) ;
if ( F_15 ( ! V_22 ) )
return V_27 ;
else
return V_28 ;
}
static int F_20 ( struct V_22 * V_22 , struct V_7 * V_8 )
{
struct V_30 * V_30 = F_21 ( V_22 -> V_31 ) ;
struct V_32 V_33 ;
struct V_34 * V_35 ;
int V_36 ;
int V_9 ;
T_3 V_37 ;
int V_38 ;
if ( F_15 ( ! F_5 ( V_8 ) -> V_11 ) ) {
V_38 = - V_39 ;
goto error;
}
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_40 = F_5 ( V_8 ) -> V_11 -> V_41 ;
V_33 . V_42 = F_5 ( V_8 ) -> V_11 -> V_43 ;
V_33 . V_44 = F_22 ( F_5 ( V_8 ) -> V_11 -> V_45 ) ;
V_33 . V_46 = V_8 -> V_47 ;
V_33 . V_48 = V_49 ;
V_35 = F_23 ( V_30 , & V_33 ) ;
if ( F_7 ( V_35 ) )
return F_24 ( V_35 ) ;
V_9 = F_25 ( F_5 ( V_8 ) -> V_11 -> V_14 ) ;
V_36 = F_26 ( V_35 -> V_50 . V_23 ) + V_35 -> V_50 . V_51
+ V_9 + sizeof( struct V_52 )
+ ( F_27 ( V_8 ) ? V_53 : 0 ) ;
if ( F_28 ( V_8 ) < V_36 || F_29 ( V_8 ) ) {
int V_54 = F_30 ( V_36 -
F_28 ( V_8 ) +
16 ) ;
V_38 = F_31 ( V_8 , F_32 ( int , V_54 , 0 ) ,
0 , V_55 ) ;
if ( F_15 ( V_38 ) )
goto V_56;
}
if ( F_27 ( V_8 ) ) {
if ( F_15 ( ! F_33 ( V_8 ,
V_8 -> V_57 ,
F_34 ( V_8 ) ) ) ) {
V_38 = - V_58 ;
goto V_56;
}
V_8 -> V_59 = 0 ;
}
V_8 = F_4 ( V_8 , V_9 ) ;
if ( F_15 ( ! V_8 ) ) {
V_38 = 0 ;
goto V_56;
}
V_37 = F_5 ( V_8 ) -> V_11 -> V_14 & V_60 ?
F_8 ( V_61 ) : 0 ;
V_8 -> V_62 = 1 ;
return F_35 ( V_8 -> V_63 , V_35 , V_8 , V_33 . V_42 ,
F_5 ( V_8 ) -> V_11 -> V_41 , V_49 ,
F_5 ( V_8 ) -> V_11 -> V_45 ,
F_5 ( V_8 ) -> V_11 -> V_64 , V_37 , false ) ;
V_56:
F_36 ( V_35 ) ;
error:
return V_38 ;
}
static int F_37 ( void )
{
int V_38 ;
V_65 ++ ;
if ( V_65 > 1 )
return 0 ;
V_38 = F_38 ( & V_66 ) ;
if ( V_38 )
F_39 ( L_1 ) ;
return V_38 ;
}
static void F_40 ( void )
{
V_65 -- ;
if ( V_65 > 0 )
return;
F_41 ( & V_66 ) ;
}
static const char * F_42 ( const struct V_22 * V_22 )
{
return F_43 ( V_22 ) ;
}
static struct V_22 * F_44 ( const struct V_67 * V_68 )
{
struct V_30 * V_30 = F_21 ( V_68 -> V_31 ) ;
struct V_21 * V_21 ;
struct V_22 * V_22 ;
int V_38 ;
V_38 = F_37 () ;
if ( V_38 )
return F_45 ( V_38 ) ;
V_21 = F_12 ( V_30 , V_24 ) ;
if ( F_46 ( V_21 -> V_25 . V_26 ) ) {
V_22 = F_45 ( - V_69 ) ;
goto error;
}
V_22 = F_47 ( V_70 , & V_71 , V_68 ) ;
if ( F_7 ( V_22 ) )
goto error;
strncpy ( F_43 ( V_22 ) , V_68 -> V_72 , V_70 ) ;
F_48 ( V_21 -> V_25 . V_26 , V_22 ) ;
return V_22 ;
error:
F_40 () ;
return V_22 ;
}
static void F_49 ( struct V_22 * V_22 )
{
struct V_30 * V_30 = F_21 ( V_22 -> V_31 ) ;
struct V_21 * V_21 ;
V_21 = F_12 ( V_30 , V_24 ) ;
F_50 ( V_21 -> V_25 . V_26 , NULL ) ;
F_51 ( V_22 ) ;
F_40 () ;
}
