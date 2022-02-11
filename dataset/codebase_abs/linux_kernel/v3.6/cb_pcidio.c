static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_6 = NULL ;
int V_7 = V_5 -> V_8 [ 0 ] ;
int V_9 = V_5 -> V_8 [ 1 ] ;
int V_10 ;
F_2 (pcidev) {
if ( V_7 || V_9 ) {
if ( V_7 != V_6 -> V_7 -> V_11 ||
V_9 != F_3 ( V_6 -> V_12 ) )
continue;
}
if ( V_6 -> V_13 != V_14 )
continue;
for ( V_10 = 0 ; V_10 < F_4 ( V_15 ) ; V_10 ++ ) {
if ( V_15 [ V_10 ] . V_16 != V_6 -> V_17 )
continue;
V_3 -> V_18 = V_15 + V_10 ;
return V_6 ;
}
}
F_5 ( V_3 -> V_19 ,
L_1 ,
V_7 , V_9 ) ;
return NULL ;
}
static int F_6 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
int V_10 ;
int V_20 ;
V_6 = F_1 ( V_3 , V_5 ) ;
if ( ! V_6 )
return - V_21 ;
F_7 ( V_3 , & V_6 -> V_3 ) ;
V_3 -> V_22 = V_23 -> V_24 ;
if ( F_8 ( V_6 , V_23 -> V_24 ) )
return - V_21 ;
V_3 -> V_25 = F_9 ( V_6 , V_23 -> V_26 ) ;
V_20 = F_10 ( V_3 , V_23 -> V_27 ) ;
if ( V_20 )
return V_20 ;
for ( V_10 = 0 ; V_10 < V_23 -> V_27 ; V_10 ++ ) {
F_11 ( V_3 , V_3 -> V_28 + V_10 ,
NULL , V_3 -> V_25 + V_10 * 4 ) ;
F_12 ( V_3 -> V_19 , L_2 , V_10 ,
V_3 -> V_25 + V_10 * 4 ) ;
}
return 1 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_14 ( V_3 ) ;
if ( V_6 ) {
if ( V_3 -> V_25 )
F_15 ( V_6 ) ;
F_16 ( V_6 ) ;
}
if ( V_3 -> V_28 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_23 -> V_27 ; V_10 ++ )
F_17 ( V_3 , V_3 -> V_28 + V_10 ) ;
}
}
static int T_1 F_18 ( struct V_1 * V_3 ,
const struct V_29 * V_30 )
{
return F_19 ( V_3 , & V_31 ) ;
}
static void T_2 F_20 ( struct V_1 * V_3 )
{
F_21 ( V_3 ) ;
}
