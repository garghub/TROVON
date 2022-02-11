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
if ( V_15 ) {
char V_18 [ V_19 ] ;
F_6 ( V_2 , L_1 , V_15 , F_7 ( V_18 , V_15 ) ) ;
}
F_8 ( & V_4 -> V_20 , V_21 ) ;
F_9 ( & V_4 -> V_22 ) ;
#ifdef F_10
F_11 ( V_23 , L_2 ,
V_24 , 16 , 4 , V_4 -> V_25 , V_6 , 1 ) ;
#endif
}
static inline int F_12 ( struct V_8 * V_9 , int V_26 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ ! ( V_26 ^ V_9 -> V_27 ) ] ;
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_4 -> V_17 ;
int V_15 ;
F_13 ( V_2 , L_3 , ! ( V_26 ^ V_9 -> V_27 ) ) ;
F_14 ( & V_4 -> V_22 ) ;
V_15 = F_15 ( V_2 , V_14 , F_4 , V_9 ) ;
if ( V_15 )
F_9 ( & V_4 -> V_22 ) ;
else
F_16 ( & V_4 -> V_20 ) ;
return V_15 ;
}
static int F_17 ( struct V_28 * V_29 , void * V_30 , T_2 V_31 , bool V_32 )
{
struct V_8 * V_9 = & V_33 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_9 -> V_27 ] ;
int V_34 , V_35 ;
int V_15 ;
if ( F_18 ( & V_4 -> V_20 ) ) {
if ( F_18 ( & V_4 -> V_20 ) == V_36 ) {
V_15 = F_12 ( V_9 , 1 ) ;
if ( V_15 )
return 0 ;
}
if ( ! V_32 )
return 0 ;
if ( F_18 ( & V_4 -> V_20 ) )
F_19 ( & V_4 -> V_22 ) ;
}
V_34 = V_9 -> V_37 + V_31 ;
F_13 ( V_9 -> V_2 , L_4 ,
V_38 , V_9 -> V_27 , V_9 -> V_37 ) ;
if ( V_34 < V_6 ) {
memcpy ( V_30 , V_4 -> V_25 + V_9 -> V_37 , V_31 ) ;
V_9 -> V_37 = V_34 ;
return V_31 ;
}
V_35 = V_6 - V_9 -> V_37 ;
memcpy ( V_30 , V_4 -> V_25 + V_9 -> V_37 , V_35 ) ;
V_9 -> V_37 = 0 ;
F_8 ( & V_4 -> V_20 , V_36 ) ;
F_12 ( V_9 , 1 ) ;
V_9 -> V_27 = ! V_9 -> V_27 ;
F_13 ( V_9 -> V_2 , L_5 , V_9 -> V_27 ) ;
return V_35 + F_17 ( V_29 , V_30 + V_35 ,
V_31 - V_35 , false ) ;
}
static inline void F_20 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 * V_14 = V_9 -> V_39 ;
F_21 ( V_14 , V_40 ) ;
F_22 ( V_14 , V_41 | V_42 ) ;
F_23 ( V_14 , V_43 | V_44 ) ;
F_24 ( V_14 , V_6 , V_45 ) ;
V_9 -> V_10 = F_25 ( V_2 , V_14 , F_26 ( V_14 ) ,
V_12 ) ;
#ifdef F_10
F_11 ( V_23 , L_6 , V_24 , 16 , 4 ,
V_14 , F_26 ( V_14 ) , 1 ) ;
#endif
}
static inline void F_27 ( struct V_8 * V_9 , int V_46 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = & V_9 -> V_13 [ V_46 ] ;
T_1 * V_14 = V_4 -> V_17 ;
int V_47 = F_28 ( V_9 -> V_39 ) ;
F_29 ( V_14 , V_9 -> V_10 , V_47 , V_48 |
V_49 ) ;
V_4 -> V_5 = F_25 ( V_2 , V_4 -> V_25 , V_6 , V_7 ) ;
F_30 ( V_14 , V_4 -> V_5 , V_6 , 0 ) ;
#ifdef F_10
F_11 ( V_23 , L_7 , V_24 , 16 , 4 ,
V_14 , F_26 ( V_14 ) , 1 ) ;
#endif
}
static void F_31 ( struct V_28 * V_29 )
{
int V_50 ;
struct V_3 * V_4 ;
for ( V_50 = 0 ; V_50 < 2 ; V_50 ++ ) {
V_4 = & V_33 . V_13 [ V_50 ] ;
if ( F_18 ( & V_4 -> V_20 ) == V_51 )
F_19 ( & V_4 -> V_22 ) ;
}
F_3 ( & V_33 ) ;
}
static void F_32 ( struct V_8 * V_9 , int V_46 )
{
struct V_3 * V_4 = & V_9 -> V_13 [ V_46 ] ;
F_27 ( V_9 , V_46 ) ;
F_8 ( & V_4 -> V_20 , V_36 ) ;
F_12 ( V_9 , V_46 == V_9 -> V_27 ) ;
F_19 ( & V_4 -> V_22 ) ;
}
static void F_33 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
V_9 -> V_2 = V_2 ;
F_20 ( V_9 ) ;
V_9 -> V_27 = 0 ;
V_9 -> V_37 = 0 ;
F_32 ( V_9 , 0 ) ;
F_32 ( V_9 , 1 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_52 ) ;
}
static int T_4 F_36 ( void )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_1 * V_57 ;
struct V_58 * V_59 ;
V_54 = F_37 ( NULL , NULL , L_8 ) ;
if ( ! V_54 ) {
V_54 = F_37 ( NULL , NULL , L_9 ) ;
if ( ! V_54 )
return - V_60 ;
}
V_56 = F_38 ( V_54 ) ;
if ( ! V_56 )
return - V_60 ;
V_57 = & V_56 -> V_61 ;
V_59 = F_39 ( V_57 ) ;
F_40 ( V_54 ) ;
F_33 ( & V_33 , V_59 -> V_2 [ 0 ] ) ;
F_41 ( V_59 -> V_2 [ 0 ] , L_10 ) ;
return F_42 ( & V_52 ) ;
}
