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
return F_3 ( V_6 , L_1 ) ;
}
static inline int F_5 ( struct V_5 * V_6 )
{
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 ,
T_3 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
while ( V_11 -- )
* V_12 ++ = F_7 ( V_13 -> V_14 + V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_10 , T_2 V_11 ,
T_3 * V_15 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
while ( V_11 -- )
F_9 ( * V_15 ++ , V_13 -> V_14 + V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_10 , T_2 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
* V_12 = F_11 ( V_13 -> V_14 + V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , T_1 V_10 , T_1 * V_12 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
* V_12 = F_13 ( V_13 -> V_14 + V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_10 , T_1 V_15 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
F_15 ( V_15 , V_13 -> V_14 + V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_6 , struct V_17 * V_17 ,
T_4 V_18 )
{
struct V_1 * V_13 ;
int V_19 = - 1 ;
V_13 = F_17 ( V_6 , sizeof( struct V_1 ) , V_20 ) ;
if ( V_13 == NULL )
return - V_21 ;
V_13 -> V_14 = F_18 ( V_6 , & V_17 -> V_22 ) ;
if ( F_19 ( V_13 -> V_14 ) )
return F_20 ( V_13 -> V_14 ) ;
if ( V_23 )
V_19 = V_17 -> V_19 ;
if ( V_24 )
V_13 -> V_4 . V_25 |= V_26 ;
return F_21 ( V_6 , & V_13 -> V_4 , V_19 , & V_27 ,
V_18 ) ;
}
static int F_22 ( struct V_28 * V_28 ,
const struct V_29 * V_30 )
{
struct V_17 V_17 = {} ;
T_4 V_18 = NULL ;
struct V_31 * V_22 ;
V_22 = F_23 ( V_28 , V_32 , 0 ) ;
if ( ! V_22 )
return - V_33 ;
V_17 . V_22 = * V_22 ;
if ( F_24 ( V_28 , 0 ) )
V_17 . V_19 = F_25 ( V_28 , 0 ) ;
else
V_17 . V_19 = - 1 ;
if ( F_26 ( V_28 ) ) {
if ( F_5 ( F_26 ( V_28 ) ) )
V_24 = true ;
V_18 = F_27 ( & V_28 -> V_6 ) ;
}
return F_16 ( & V_28 -> V_6 , & V_17 , V_18 ) ;
}
static void F_28 ( struct V_28 * V_6 )
{
struct V_34 * V_35 = F_29 ( V_6 ) ;
F_30 ( V_35 ) ;
F_31 ( V_35 ) ;
}
static int F_32 ( struct V_36 * V_37 , void * V_3 )
{
struct V_17 * V_17 = (struct V_17 * ) V_3 ;
struct V_31 V_22 ;
if ( F_33 ( V_37 , 0 , & V_22 ) )
V_17 -> V_19 = V_22 . V_38 ;
else if ( F_34 ( V_37 , & V_22 ) ) {
V_17 -> V_22 = V_22 ;
V_17 -> V_22 . V_39 = NULL ;
}
return 1 ;
}
static int F_35 ( struct V_5 * V_40 )
{
struct V_41 * V_42 ;
T_5 V_43 ;
struct V_44 V_45 ;
struct V_17 V_17 = {} ;
int V_46 ;
V_43 = F_36 ( V_47 , 1 ,
(struct V_48 * * ) & V_42 ) ;
if ( F_37 ( V_43 ) || V_42 -> V_49 . V_50 < sizeof( * V_42 ) ) {
F_38 ( & V_40 -> V_6 ,
V_51 L_2 ) ;
return - V_52 ;
}
if ( V_42 -> V_53 != V_54 )
return - V_33 ;
F_39 ( & V_45 ) ;
V_17 . V_19 = - 1 ;
V_46 = F_40 ( V_40 , & V_45 , F_32 ,
& V_17 ) ;
if ( V_46 < 0 )
return V_46 ;
F_41 ( & V_45 ) ;
if ( F_42 ( & V_17 . V_22 ) != V_32 ) {
F_38 ( & V_40 -> V_6 ,
V_51 L_3 ) ;
return - V_52 ;
}
if ( F_5 ( V_40 ) )
V_24 = true ;
return F_16 ( & V_40 -> V_6 , & V_17 , V_40 -> V_55 ) ;
}
static int F_43 ( struct V_5 * V_6 )
{
struct V_34 * V_35 = F_44 ( & V_6 -> V_6 ) ;
F_30 ( V_35 ) ;
F_31 ( V_35 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_17 V_17 = {} ;
struct V_31 * V_22 ;
V_22 = F_46 ( V_57 , V_32 , 0 ) ;
if ( V_22 == NULL ) {
F_38 ( & V_57 -> V_6 , L_4 ) ;
return - V_33 ;
}
V_17 . V_22 = * V_22 ;
V_22 = F_46 ( V_57 , V_58 , 0 ) ;
if ( V_22 ) {
V_17 . V_19 = V_22 -> V_38 ;
} else {
if ( V_57 == V_59 )
V_17 . V_19 = - 1 ;
else
V_17 . V_19 = 0 ;
}
return F_16 ( & V_57 -> V_6 , & V_17 , NULL ) ;
}
static int F_47 ( struct V_56 * V_57 )
{
struct V_34 * V_35 = F_44 ( & V_57 -> V_6 ) ;
F_30 ( V_35 ) ;
F_31 ( V_35 ) ;
return 0 ;
}
static int F_48 ( void )
{
struct V_56 * V_57 ;
static const struct V_31 V_60 [] = {
{
. V_38 = 0xFED40000 ,
. V_61 = 0xFED40000 + V_62 - 1 ,
. V_25 = V_32 ,
} ,
} ;
if ( ! V_63 )
return 0 ;
V_57 = F_49 ( L_5 , - 1 , V_60 ,
F_50 ( V_60 ) ) ;
if ( F_19 ( V_57 ) )
return F_20 ( V_57 ) ;
V_59 = V_57 ;
return 0 ;
}
static int T_6 F_51 ( void )
{
int V_64 ;
V_64 = F_48 () ;
if ( V_64 )
goto V_65;
V_64 = F_52 ( & V_66 ) ;
if ( V_64 )
goto V_67;
#ifdef F_53
V_64 = F_54 ( & V_68 ) ;
if ( V_64 )
goto V_69;
#endif
if ( F_55 ( V_70 ) ) {
V_64 = F_56 ( & V_71 ) ;
if ( V_64 )
goto V_72;
}
return 0 ;
V_72:
#ifdef F_53
F_57 ( & V_68 ) ;
V_69:
#endif
F_58 ( V_59 ) ;
V_67:
if ( V_59 )
F_58 ( V_59 ) ;
V_65:
return V_64 ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_71 ) ;
#ifdef F_53
F_57 ( & V_68 ) ;
#endif
F_61 ( & V_66 ) ;
if ( V_59 )
F_58 ( V_59 ) ;
}
