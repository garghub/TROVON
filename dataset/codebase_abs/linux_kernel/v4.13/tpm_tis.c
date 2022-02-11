static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , const char * V_7 )
{
struct V_8 * V_9 ;
F_4 (id, &dev->pnp.ids, list)
if ( ! strcmp ( V_7 , V_9 -> V_9 ) )
return 1 ;
return 0 ;
}
static inline int F_5 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return 0 ;
return F_3 ( V_6 , L_1 ) ;
}
static inline int F_5 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_6 ( struct V_10 * V_6 )
{
const struct V_11 * V_12 = F_7 ( V_13 , V_6 ) ;
struct V_14 * V_15 ;
T_1 V_16 ;
if ( ! V_12 || V_12 -> V_17 != V_18 )
return 0 ;
V_16 =
F_8 ( V_19 , 1 , (struct V_20 * * ) & V_15 ) ;
if ( F_9 ( V_16 ) || V_15 -> V_21 . V_22 < sizeof( * V_15 ) ) {
F_10 ( V_6 , V_23 L_2 ) ;
return - V_24 ;
}
if ( V_15 -> V_25 != V_26 )
return - V_27 ;
return 0 ;
}
static int F_6 ( struct V_10 * V_6 )
{
return 0 ;
}
static inline bool F_11 ( void )
{
return ( ( V_28 . V_29 == V_30 ) ? 1 : 0 ) ;
}
static void F_12 ( void )
{
T_2 V_31 ;
if ( ! F_11 () )
return;
V_31 = F_13 ( V_32 + V_33 ) ;
V_31 &= ~ V_34 ;
F_14 ( V_31 , V_32 + V_33 ) ;
F_15 ( 0xCC , 0x80 ) ;
}
static void F_16 ( void )
{
T_2 V_31 ;
if ( ! F_11 () )
return;
V_31 = F_13 ( V_32 + V_33 ) ;
V_31 |= V_34 ;
F_14 ( V_31 , V_32 + V_33 ) ;
F_15 ( 0xCC , 0x80 ) ;
}
static inline bool F_11 ( void )
{
return false ;
}
static void F_12 ( void )
{
}
static void F_16 ( void )
{
}
static int F_17 ( struct V_2 * V_3 , T_2 V_35 , T_3 V_36 ,
T_4 * V_37 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_12 () ;
while ( V_36 -- )
* V_37 ++ = F_18 ( V_38 -> V_39 + V_35 ) ;
F_16 () ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_2 V_35 , T_3 V_36 ,
T_4 * V_40 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_12 () ;
while ( V_36 -- )
F_20 ( * V_40 ++ , V_38 -> V_39 + V_35 ) ;
F_16 () ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , T_2 V_35 , T_3 * V_37 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_12 () ;
* V_37 = F_22 ( V_38 -> V_39 + V_35 ) ;
F_16 () ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , T_2 V_35 , T_2 * V_37 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_12 () ;
* V_37 = F_13 ( V_38 -> V_39 + V_35 ) ;
F_16 () ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , T_2 V_35 , T_2 V_40 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_12 () ;
F_14 ( V_40 , V_38 -> V_39 + V_35 ) ;
F_16 () ;
return 0 ;
}
static int F_25 ( struct V_10 * V_6 , struct V_41 * V_41 )
{
struct V_1 * V_38 ;
int V_42 = - 1 ;
int V_43 ;
V_43 = F_6 ( V_6 ) ;
if ( V_43 )
return V_43 ;
V_38 = F_26 ( V_6 , sizeof( struct V_1 ) , V_44 ) ;
if ( V_38 == NULL )
return - V_45 ;
V_38 -> V_39 = F_27 ( V_6 , & V_41 -> V_46 ) ;
if ( F_28 ( V_38 -> V_39 ) )
return F_29 ( V_38 -> V_39 ) ;
if ( V_47 )
V_42 = V_41 -> V_42 ;
if ( V_48 || F_5 ( F_30 ( V_6 ) ) )
V_38 -> V_4 . V_49 |= V_50 ;
return F_31 ( V_6 , & V_38 -> V_4 , V_42 , & V_51 ,
F_32 ( V_6 ) ) ;
}
static int F_33 ( struct V_52 * V_52 ,
const struct V_53 * V_54 )
{
struct V_41 V_41 = {} ;
struct V_55 * V_46 ;
V_46 = F_34 ( V_52 , V_56 , 0 ) ;
if ( ! V_46 )
return - V_27 ;
V_41 . V_46 = * V_46 ;
if ( F_35 ( V_52 , 0 ) )
V_41 . V_42 = F_36 ( V_52 , 0 ) ;
else
V_41 . V_42 = - 1 ;
return F_25 ( & V_52 -> V_6 , & V_41 ) ;
}
static void F_37 ( struct V_52 * V_6 )
{
struct V_57 * V_58 = F_38 ( V_6 ) ;
F_39 ( V_58 ) ;
F_40 ( V_58 ) ;
}
static int F_41 ( struct V_59 * V_60 )
{
struct V_41 V_41 = {} ;
struct V_55 * V_46 ;
V_46 = F_42 ( V_60 , V_56 , 0 ) ;
if ( V_46 == NULL ) {
F_10 ( & V_60 -> V_6 , L_3 ) ;
return - V_27 ;
}
V_41 . V_46 = * V_46 ;
V_41 . V_42 = F_43 ( V_60 , 0 ) ;
if ( V_41 . V_42 <= 0 ) {
if ( V_60 != V_61 )
V_41 . V_42 = - 1 ;
else
V_41 . V_42 = 0 ;
}
return F_25 ( & V_60 -> V_6 , & V_41 ) ;
}
static int F_44 ( struct V_59 * V_60 )
{
struct V_57 * V_58 = F_45 ( & V_60 -> V_6 ) ;
F_39 ( V_58 ) ;
F_40 ( V_58 ) ;
return 0 ;
}
static int F_46 ( void )
{
struct V_59 * V_60 ;
static const struct V_55 V_62 [] = {
{
. V_63 = 0xFED40000 ,
. V_64 = 0xFED40000 + V_65 - 1 ,
. V_49 = V_56 ,
} ,
} ;
if ( ! V_66 )
return 0 ;
V_60 = F_47 ( L_4 , - 1 , V_62 ,
F_48 ( V_62 ) ) ;
if ( F_28 ( V_60 ) )
return F_29 ( V_60 ) ;
V_61 = V_60 ;
return 0 ;
}
static int T_5 F_49 ( void )
{
int V_43 ;
V_43 = F_46 () ;
if ( V_43 )
goto V_67;
#ifdef F_50
if ( F_11 () )
V_32 = F_51 ( V_68 ,
V_69 ) ;
#endif
V_43 = F_52 ( & V_70 ) ;
if ( V_43 )
goto V_71;
if ( F_53 ( V_72 ) ) {
V_43 = F_54 ( & V_73 ) ;
if ( V_43 )
goto V_74;
}
return 0 ;
V_74:
F_55 ( & V_70 ) ;
V_71:
if ( V_61 )
F_56 ( V_61 ) ;
#ifdef F_50
if ( F_11 () )
F_57 ( V_32 ) ;
#endif
V_67:
return V_43 ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_73 ) ;
F_55 ( & V_70 ) ;
#ifdef F_50
if ( F_11 () )
F_57 ( V_32 ) ;
#endif
if ( V_61 )
F_56 ( V_61 ) ;
}
