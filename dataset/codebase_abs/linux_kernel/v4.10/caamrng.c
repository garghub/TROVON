static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 )
F_2 ( V_2 , V_4 -> V_5 , V_6 ,
V_7 ) ;
}
static inline void F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( V_9 -> V_10 )
F_2 ( V_2 , V_9 -> V_10 ,
F_4 ( V_9 -> V_11 ) , V_12 ) ;
F_1 ( V_2 , & V_9 -> V_13 [ 0 ] ) ;
F_1 ( V_2 , & V_9 -> V_13 [ 1 ] ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_14 , T_1 V_15 , void * V_16 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( V_14 , struct V_3 , V_17 [ 0 ] ) ;
if ( V_15 )
F_7 ( V_2 , V_15 ) ;
F_8 ( & V_4 -> V_18 , V_19 ) ;
F_9 ( & V_4 -> V_20 ) ;
F_10 ( V_2 , V_4 -> V_5 , V_6 , V_7 ) ;
#ifdef F_11
F_12 ( V_21 , L_1 ,
V_22 , 16 , 4 , V_4 -> V_23 , V_6 , 1 ) ;
#endif
}
static inline int F_13 ( struct V_8 * V_9 , int V_24 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ ! ( V_24 ^ V_9 -> V_25 ) ] ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_4 -> V_17 ;
int V_15 ;
F_14 ( V_2 , L_2 , ! ( V_24 ^ V_9 -> V_25 ) ) ;
F_15 ( & V_4 -> V_20 ) ;
V_15 = F_16 ( V_2 , V_14 , F_5 , V_9 ) ;
if ( V_15 )
F_9 ( & V_4 -> V_20 ) ;
else
F_17 ( & V_4 -> V_18 ) ;
return V_15 ;
}
static int F_18 ( struct V_26 * V_27 , void * V_28 , T_2 V_29 , bool V_30 )
{
struct V_8 * V_9 = V_31 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_9 -> V_25 ] ;
int V_32 , V_33 ;
int V_15 ;
if ( F_19 ( & V_4 -> V_18 ) ) {
if ( F_19 ( & V_4 -> V_18 ) == V_34 ) {
V_15 = F_13 ( V_9 , 1 ) ;
if ( V_15 )
return 0 ;
}
if ( ! V_30 )
return 0 ;
if ( F_19 ( & V_4 -> V_18 ) )
F_20 ( & V_4 -> V_20 ) ;
}
V_32 = V_9 -> V_35 + V_29 ;
F_14 ( V_9 -> V_2 , L_3 ,
V_36 , V_9 -> V_25 , V_9 -> V_35 ) ;
if ( V_32 < V_6 ) {
memcpy ( V_28 , V_4 -> V_23 + V_9 -> V_35 , V_29 ) ;
V_9 -> V_35 = V_32 ;
return V_29 ;
}
V_33 = V_6 - V_9 -> V_35 ;
memcpy ( V_28 , V_4 -> V_23 + V_9 -> V_35 , V_33 ) ;
V_9 -> V_35 = 0 ;
F_8 ( & V_4 -> V_18 , V_34 ) ;
F_13 ( V_9 , 1 ) ;
V_9 -> V_25 = ! V_9 -> V_25 ;
F_14 ( V_9 -> V_2 , L_4 , V_9 -> V_25 ) ;
return V_33 + F_18 ( V_27 , V_28 + V_33 ,
V_29 - V_33 , false ) ;
}
static inline int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_9 -> V_11 ;
F_22 ( V_14 , V_37 ) ;
F_23 ( V_14 , V_38 | V_39 ) ;
F_24 ( V_14 , V_6 , V_40 ) ;
V_9 -> V_10 = F_25 ( V_2 , V_14 , F_4 ( V_14 ) ,
V_12 ) ;
if ( F_26 ( V_2 , V_9 -> V_10 ) ) {
F_27 ( V_2 , L_5 ) ;
return - V_41 ;
}
#ifdef F_11
F_12 ( V_21 , L_6 , V_22 , 16 , 4 ,
V_14 , F_4 ( V_14 ) , 1 ) ;
#endif
return 0 ;
}
static inline int F_28 ( struct V_8 * V_9 , int V_42 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_42 ] ;
T_1 * V_14 = V_4 -> V_17 ;
int V_43 = F_29 ( V_9 -> V_11 ) ;
F_30 ( V_14 , V_9 -> V_10 , V_43 , V_44 |
V_45 ) ;
V_4 -> V_5 = F_25 ( V_2 , V_4 -> V_23 , V_6 , V_7 ) ;
if ( F_26 ( V_2 , V_4 -> V_5 ) ) {
F_27 ( V_2 , L_7 ) ;
return - V_41 ;
}
F_31 ( V_14 , V_4 -> V_5 , V_6 , 0 ) ;
#ifdef F_11
F_12 ( V_21 , L_8 , V_22 , 16 , 4 ,
V_14 , F_4 ( V_14 ) , 1 ) ;
#endif
return 0 ;
}
static void F_32 ( struct V_26 * V_27 )
{
int V_46 ;
struct V_3 * V_4 ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
V_4 = & V_31 -> V_13 [ V_46 ] ;
if ( F_19 ( & V_4 -> V_18 ) == V_47 )
F_20 ( & V_4 -> V_20 ) ;
}
F_3 ( V_31 ) ;
}
static int F_33 ( struct V_8 * V_9 , int V_42 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ V_42 ] ;
int V_15 ;
V_15 = F_28 ( V_9 , V_42 ) ;
if ( V_15 )
return V_15 ;
F_8 ( & V_4 -> V_18 , V_34 ) ;
F_13 ( V_9 , V_42 == V_9 -> V_25 ) ;
F_20 ( & V_4 -> V_20 ) ;
return 0 ;
}
static int F_34 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_15 ;
V_9 -> V_2 = V_2 ;
V_15 = F_21 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_9 -> V_25 = 0 ;
V_9 -> V_35 = 0 ;
V_15 = F_33 ( V_9 , 0 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_33 ( V_9 , 1 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
static void T_3 F_35 ( void )
{
F_36 ( V_31 -> V_2 ) ;
F_37 ( & V_48 ) ;
F_38 ( V_31 ) ;
}
static int T_4 F_39 ( void )
{
struct V_1 * V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_1 * V_54 ;
struct V_55 * V_56 ;
int V_15 ;
V_51 = F_40 ( NULL , NULL , L_9 ) ;
if ( ! V_51 ) {
V_51 = F_40 ( NULL , NULL , L_10 ) ;
if ( ! V_51 )
return - V_57 ;
}
V_53 = F_41 ( V_51 ) ;
if ( ! V_53 ) {
F_42 ( V_51 ) ;
return - V_57 ;
}
V_54 = & V_53 -> V_49 ;
V_56 = F_43 ( V_54 ) ;
F_42 ( V_51 ) ;
if ( ! V_56 )
return - V_57 ;
if ( ! ( F_44 ( & V_56 -> V_58 -> V_59 . V_60 ) & V_61 ) )
return - V_57 ;
V_49 = F_45 () ;
if ( F_46 ( V_49 ) ) {
F_47 ( L_11 ) ;
return F_48 ( V_49 ) ;
}
V_31 = F_49 ( sizeof( * V_31 ) , V_62 | V_63 ) ;
if ( ! V_31 ) {
V_15 = - V_41 ;
goto V_64;
}
V_15 = F_34 ( V_31 , V_49 ) ;
if ( V_15 )
goto V_65;
F_50 ( V_49 , L_12 ) ;
return F_51 ( & V_48 ) ;
V_65:
F_38 ( V_31 ) ;
V_64:
F_36 ( V_49 ) ;
return V_15 ;
}
