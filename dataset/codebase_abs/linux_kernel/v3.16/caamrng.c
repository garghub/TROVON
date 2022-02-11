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
F_2 ( V_2 , V_9 -> V_10 , V_11 ,
V_12 ) ;
F_1 ( V_2 , & V_9 -> V_13 [ 0 ] ) ;
F_1 ( V_2 , & V_9 -> V_13 [ 1 ] ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_14 , T_1 V_15 , void * V_16 )
{
struct V_3 * V_4 ;
V_4 = (struct V_3 * ) ( ( char * ) V_14 -
F_5 ( struct V_3 , V_17 ) ) ;
if ( V_15 )
F_6 ( V_2 , V_15 ) ;
F_7 ( & V_4 -> V_18 , V_19 ) ;
F_8 ( & V_4 -> V_20 ) ;
#ifdef F_9
F_10 ( V_21 , L_1 ,
V_22 , 16 , 4 , V_4 -> V_23 , V_6 , 1 ) ;
#endif
}
static inline int F_11 ( struct V_8 * V_9 , int V_24 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ ! ( V_24 ^ V_9 -> V_25 ) ] ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_4 -> V_17 ;
int V_15 ;
F_12 ( V_2 , L_2 , ! ( V_24 ^ V_9 -> V_25 ) ) ;
F_13 ( & V_4 -> V_20 ) ;
V_15 = F_14 ( V_2 , V_14 , F_4 , V_9 ) ;
if ( V_15 )
F_8 ( & V_4 -> V_20 ) ;
else
F_15 ( & V_4 -> V_18 ) ;
return V_15 ;
}
static int F_16 ( struct V_26 * V_27 , void * V_28 , T_2 V_29 , bool V_30 )
{
struct V_8 * V_9 = V_31 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_9 -> V_25 ] ;
int V_32 , V_33 ;
int V_15 ;
if ( F_17 ( & V_4 -> V_18 ) ) {
if ( F_17 ( & V_4 -> V_18 ) == V_34 ) {
V_15 = F_11 ( V_9 , 1 ) ;
if ( V_15 )
return 0 ;
}
if ( ! V_30 )
return 0 ;
if ( F_17 ( & V_4 -> V_18 ) )
F_18 ( & V_4 -> V_20 ) ;
}
V_32 = V_9 -> V_35 + V_29 ;
F_12 ( V_9 -> V_2 , L_3 ,
V_36 , V_9 -> V_25 , V_9 -> V_35 ) ;
if ( V_32 < V_6 ) {
memcpy ( V_28 , V_4 -> V_23 + V_9 -> V_35 , V_29 ) ;
V_9 -> V_35 = V_32 ;
return V_29 ;
}
V_33 = V_6 - V_9 -> V_35 ;
memcpy ( V_28 , V_4 -> V_23 + V_9 -> V_35 , V_33 ) ;
V_9 -> V_35 = 0 ;
F_7 ( & V_4 -> V_18 , V_34 ) ;
F_11 ( V_9 , 1 ) ;
V_9 -> V_25 = ! V_9 -> V_25 ;
F_12 ( V_9 -> V_2 , L_4 , V_9 -> V_25 ) ;
return V_33 + F_16 ( V_27 , V_28 + V_33 ,
V_29 - V_33 , false ) ;
}
static inline void F_19 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_9 -> V_37 ;
F_20 ( V_14 , V_38 ) ;
F_21 ( V_14 , V_39 | V_40 ) ;
F_22 ( V_14 , V_41 | V_42 ) ;
F_23 ( V_14 , V_6 , V_43 ) ;
V_9 -> V_10 = F_24 ( V_2 , V_14 , F_25 ( V_14 ) ,
V_12 ) ;
#ifdef F_9
F_10 ( V_21 , L_5 , V_22 , 16 , 4 ,
V_14 , F_25 ( V_14 ) , 1 ) ;
#endif
}
static inline void F_26 ( struct V_8 * V_9 , int V_44 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_44 ] ;
T_1 * V_14 = V_4 -> V_17 ;
int V_45 = F_27 ( V_9 -> V_37 ) ;
F_28 ( V_14 , V_9 -> V_10 , V_45 , V_46 |
V_47 ) ;
V_4 -> V_5 = F_24 ( V_2 , V_4 -> V_23 , V_6 , V_7 ) ;
F_29 ( V_14 , V_4 -> V_5 , V_6 , 0 ) ;
#ifdef F_9
F_10 ( V_21 , L_6 , V_22 , 16 , 4 ,
V_14 , F_25 ( V_14 ) , 1 ) ;
#endif
}
static void F_30 ( struct V_26 * V_27 )
{
int V_48 ;
struct V_3 * V_4 ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
V_4 = & V_31 -> V_13 [ V_48 ] ;
if ( F_17 ( & V_4 -> V_18 ) == V_49 )
F_18 ( & V_4 -> V_20 ) ;
}
F_3 ( V_31 ) ;
}
static void F_31 ( struct V_8 * V_9 , int V_44 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ V_44 ] ;
F_26 ( V_9 , V_44 ) ;
F_7 ( & V_4 -> V_18 , V_34 ) ;
F_11 ( V_9 , V_44 == V_9 -> V_25 ) ;
F_18 ( & V_4 -> V_20 ) ;
}
static void F_32 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
V_9 -> V_2 = V_2 ;
F_19 ( V_9 ) ;
V_9 -> V_25 = 0 ;
V_9 -> V_35 = 0 ;
F_31 ( V_9 , 0 ) ;
F_31 ( V_9 , 1 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( V_31 -> V_2 ) ;
F_35 ( & V_50 ) ;
F_36 ( V_31 ) ;
}
static int T_4 F_37 ( void )
{
struct V_1 * V_51 ;
V_51 = F_38 () ;
if ( F_39 ( V_51 ) ) {
F_40 ( L_7 ) ;
return F_41 ( V_51 ) ;
}
V_31 = F_42 ( sizeof( struct V_8 ) , V_52 ) ;
if ( ! V_31 )
return - V_53 ;
F_32 ( V_31 , V_51 ) ;
F_43 ( V_51 , L_8 ) ;
return F_44 ( & V_50 ) ;
}
