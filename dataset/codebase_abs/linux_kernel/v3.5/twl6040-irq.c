static inline
struct V_1 * F_1 ( struct V_2 * V_2 ,
int V_3 )
{
return & V_4 [ V_3 - V_2 -> V_5 ] ;
}
static void F_2 ( struct V_6 * V_7 )
{
struct V_2 * V_2 = F_3 ( V_7 ) ;
F_4 ( & V_2 -> V_8 ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_2 * V_2 = F_3 ( V_7 ) ;
if ( V_2 -> V_9 != V_2 -> V_10 ) {
V_2 -> V_10 = V_2 -> V_9 ;
F_6 ( V_2 , V_11 ,
V_2 -> V_9 ) ;
}
F_7 ( & V_2 -> V_8 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_2 * V_2 = F_3 ( V_7 ) ;
struct V_1 * V_6 = F_1 ( V_2 ,
V_7 -> V_3 ) ;
V_2 -> V_9 &= ~ V_6 -> V_12 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_2 * V_2 = F_3 ( V_7 ) ;
struct V_1 * V_6 = F_1 ( V_2 ,
V_7 -> V_3 ) ;
V_2 -> V_9 |= V_6 -> V_12 ;
}
static T_1 F_10 ( int V_3 , void * V_7 )
{
struct V_2 * V_2 = V_7 ;
T_2 V_13 ;
int V_14 ;
V_13 = F_11 ( V_2 , V_15 ) ;
for ( V_14 = F_12 ( V_4 ) - 1 ; V_14 >= 0 ; V_14 -- ) {
if ( V_2 -> V_9 & V_4 [ V_14 ] . V_12 )
V_13 &= ~ V_4 [ V_14 ] . V_16 ;
if ( V_13 & V_4 [ V_14 ] . V_16 )
F_13 ( V_2 -> V_5 + V_14 ) ;
}
F_6 ( V_2 , V_15 , V_13 ) ;
return V_17 ;
}
int F_14 ( struct V_2 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
int V_14 , V_22 , V_5 , V_23 ;
T_2 V_24 ;
F_15 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = V_25 ;
V_2 -> V_10 = V_25 ;
F_6 ( V_2 , V_11 , V_25 ) ;
V_22 = F_12 ( V_4 ) ;
V_5 = F_16 ( - 1 , 0 , V_22 , 0 ) ;
if ( F_17 ( V_5 ) ) {
F_18 ( V_2 -> V_20 , L_1 ) ;
return V_5 ;
}
V_2 -> V_5 = V_5 ;
F_19 ( V_19 , F_12 ( V_4 ) , V_5 , 0 ,
& V_26 , NULL ) ;
for ( V_14 = V_5 ; V_14 < V_5 + V_22 ; V_14 ++ ) {
F_20 ( V_14 , V_2 ) ;
F_21 ( V_14 , & V_27 ,
V_28 ) ;
F_22 ( V_14 , 1 ) ;
#ifdef F_23
F_24 ( V_14 , V_29 ) ;
#else
F_25 ( V_14 ) ;
#endif
}
V_23 = F_26 ( V_2 -> V_3 , NULL , F_10 ,
V_30 , L_2 , V_2 ) ;
if ( V_23 ) {
F_18 ( V_2 -> V_20 , L_3 ,
V_2 -> V_3 , V_23 ) ;
return V_23 ;
}
V_24 = F_11 ( V_2 , V_15 ) ;
F_27 ( V_2 , V_31 , V_32 ) ;
return 0 ;
}
void F_28 ( struct V_2 * V_2 )
{
F_29 ( V_2 -> V_3 , V_2 ) ;
}
