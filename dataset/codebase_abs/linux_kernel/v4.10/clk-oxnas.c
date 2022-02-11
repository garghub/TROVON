static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_5 ;
unsigned int V_6 ;
V_5 = F_4 ( V_4 -> V_7 , V_8 , & V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_6 & F_5 ( V_4 -> V_9 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_7 ( V_4 -> V_7 , V_10 , F_5 ( V_4 -> V_9 ) ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_7 ( V_4 -> V_7 , V_11 , F_5 ( V_4 -> V_9 ) ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 . V_17 ;
const struct V_18 * V_19 ;
const struct V_20 * V_21 ;
struct V_7 * V_7 ;
int V_5 ;
int V_22 ;
V_21 = F_10 ( V_23 , & V_13 -> V_16 ) ;
if ( ! V_21 )
return - V_24 ;
V_19 = V_21 -> V_19 ;
V_7 = F_11 ( F_12 ( V_15 ) ) ;
if ( F_13 ( V_7 ) ) {
F_14 ( & V_13 -> V_16 , L_1 ) ;
return F_15 ( V_7 ) ;
}
for ( V_22 = 0 ; V_22 < V_19 -> V_25 ; ++ V_22 )
V_19 -> V_26 [ V_22 ] -> V_7 = V_7 ;
for ( V_22 = 0 ; V_22 < V_19 -> V_27 -> V_28 ; V_22 ++ ) {
if ( ! V_19 -> V_27 -> V_29 [ V_22 ] )
continue;
V_5 = F_16 ( & V_13 -> V_16 ,
V_19 -> V_27 -> V_29 [ V_22 ] ) ;
if ( V_5 )
return V_5 ;
}
return F_17 ( V_15 , V_30 ,
V_19 -> V_27 ) ;
}
