struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
static const struct V_5 V_6 [] = {
{ F_2 ( V_7 ) - 1 , L_1 } ,
{ F_2 ( V_8 ) - 1 , L_2 } ,
{ F_2 ( V_9 ) - 1 , L_3 } ,
{ F_2 ( V_10 ) - 1 , L_4 } ,
{ F_2 ( V_11 ) - 1 , L_5 } ,
{ F_2 ( V_12 ) - 1 , L_6 } ,
} ;
return F_3 ( V_3 , 0 , L_7 ,
V_6 , F_4 ( V_6 ) ,
V_4 ) ;
}
unsigned int F_5 ( unsigned int V_13 ,
unsigned int V_4 )
{
if ( V_13 & ~ V_4 ) {
V_13 ^= V_11 | V_12 ;
V_13 = ( V_13 & V_14 ) |
F_6 ( ( F_7 ( V_13 & V_15 ) + 1 ) % 4 ) ;
}
return V_13 ;
}
int F_8 ( struct V_16 * V_17 ,
unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 )
{
struct V_1 * V_21 ;
V_21 = F_9 ( V_17 -> V_3 , 0 , L_8 , V_19 , V_20 ) ;
if ( ! V_21 )
return - V_22 ;
F_10 ( & V_17 -> V_23 , V_21 , V_18 ) ;
V_17 -> V_24 = V_21 ;
if ( V_17 -> V_25 ) {
V_17 -> V_25 -> V_18 = V_18 ;
V_17 -> V_25 -> V_26 = V_18 ;
}
return 0 ;
}
int F_11 ( struct V_16 * V_17 ,
unsigned int V_18 )
{
struct V_1 * V_21 ;
V_21 = F_9 ( V_17 -> V_3 , V_27 ,
L_8 , V_18 , V_18 ) ;
if ( ! V_21 )
return - V_22 ;
F_10 ( & V_17 -> V_23 , V_21 , V_18 ) ;
V_17 -> V_24 = V_21 ;
if ( V_17 -> V_25 ) {
V_17 -> V_25 -> V_18 = V_18 ;
V_17 -> V_25 -> V_26 = V_18 ;
}
return 0 ;
}
static int F_12 ( const void * V_28 , const void * V_29 )
{
const struct V_30 * V_31 = * (struct V_30 * * ) V_28 ;
const struct V_30 * V_32 = * (struct V_30 * * ) V_29 ;
if ( V_31 -> V_18 != V_32 -> V_18 )
return V_31 -> V_18 - V_32 -> V_18 ;
else
return V_31 -> V_17 -> V_23 . V_33 - V_32 -> V_17 -> V_23 . V_33 ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_25 = V_37 -> V_25 ;
struct V_2 * V_3 = V_35 -> V_3 ;
int V_39 = V_3 -> V_40 . V_41 ;
struct V_30 * * V_42 ;
struct V_16 * V_17 ;
int V_43 , V_44 = 0 ;
int V_45 = 0 ;
F_14 ( L_9 ,
V_35 -> V_23 . V_33 , V_35 -> V_46 ) ;
V_42 = F_15 ( V_39 , sizeof( * V_42 ) , V_47 ) ;
if ( ! V_42 )
return - V_22 ;
F_16 (plane, dev, crtc_state->plane_mask) {
struct V_30 * V_48 =
F_17 ( V_25 , V_17 ) ;
if ( F_18 ( V_48 ) ) {
V_45 = F_19 ( V_48 ) ;
goto V_49;
}
V_42 [ V_44 ++ ] = V_48 ;
F_14 ( L_10 ,
V_17 -> V_23 . V_33 , V_17 -> V_46 ,
V_48 -> V_18 ) ;
}
F_20 ( V_42 , V_44 , sizeof( * V_42 ) , F_12 , NULL ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_17 = V_42 [ V_43 ] -> V_17 ;
V_42 [ V_43 ] -> V_26 = V_43 ;
F_14 ( L_11 ,
V_17 -> V_23 . V_33 , V_17 -> V_46 , V_43 ) ;
}
V_37 -> V_50 = true ;
V_49:
F_21 ( V_42 ) ;
return V_45 ;
}
int F_22 ( struct V_2 * V_3 ,
struct V_38 * V_25 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_16 * V_17 ;
struct V_30 * V_48 ;
int V_43 , V_45 = 0 ;
F_23 (state, plane, plane_state, i) {
V_35 = V_48 -> V_35 ;
if ( ! V_35 )
continue;
if ( V_17 -> V_25 -> V_18 != V_48 -> V_18 ) {
V_37 =
F_24 ( V_25 , V_35 ) ;
V_37 -> V_50 = true ;
}
}
F_25 (state, crtc, crtc_state, i) {
if ( V_37 -> V_51 != V_35 -> V_25 -> V_51 ||
V_37 -> V_50 ) {
V_45 = F_13 ( V_35 ,
V_37 ) ;
if ( V_45 )
return V_45 ;
}
}
return 0 ;
}
