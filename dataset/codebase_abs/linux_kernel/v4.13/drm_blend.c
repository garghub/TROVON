int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
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
struct V_13 * V_14 ;
F_3 ( ( V_4 & V_15 ) == 0 ) ;
F_3 ( ! F_4 ( V_3 & V_15 ) ) ;
F_3 ( V_3 & ~ V_4 ) ;
V_14 = F_5 ( V_2 -> V_16 , 0 , L_7 ,
V_6 , F_6 ( V_6 ) ,
V_4 ) ;
if ( ! V_14 )
return - V_17 ;
F_7 ( & V_2 -> V_18 , V_14 , V_3 ) ;
if ( V_2 -> V_19 )
V_2 -> V_19 -> V_3 = V_3 ;
V_2 -> V_20 = V_14 ;
return 0 ;
}
unsigned int F_8 ( unsigned int V_3 ,
unsigned int V_4 )
{
if ( V_3 & ~ V_4 ) {
V_3 ^= V_11 | V_12 ;
V_3 = ( V_3 & V_21 ) |
F_9 ( ( F_10 ( V_3 & V_15 ) + 1 )
% 4 ) ;
}
return V_3 ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned int V_22 ,
unsigned int V_23 , unsigned int V_24 )
{
struct V_13 * V_14 ;
V_14 = F_12 ( V_2 -> V_16 , 0 , L_8 , V_23 , V_24 ) ;
if ( ! V_14 )
return - V_17 ;
F_7 ( & V_2 -> V_18 , V_14 , V_22 ) ;
V_2 -> V_25 = V_14 ;
if ( V_2 -> V_19 ) {
V_2 -> V_19 -> V_22 = V_22 ;
V_2 -> V_19 -> V_26 = V_22 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned int V_22 )
{
struct V_13 * V_14 ;
V_14 = F_12 ( V_2 -> V_16 , V_27 ,
L_8 , V_22 , V_22 ) ;
if ( ! V_14 )
return - V_17 ;
F_7 ( & V_2 -> V_18 , V_14 , V_22 ) ;
V_2 -> V_25 = V_14 ;
if ( V_2 -> V_19 ) {
V_2 -> V_19 -> V_22 = V_22 ;
V_2 -> V_19 -> V_26 = V_22 ;
}
return 0 ;
}
static int F_14 ( const void * V_28 , const void * V_29 )
{
const struct V_30 * V_31 = * (struct V_30 * * ) V_28 ;
const struct V_30 * V_32 = * (struct V_30 * * ) V_29 ;
if ( V_31 -> V_22 != V_32 -> V_22 )
return V_31 -> V_22 - V_32 -> V_22 ;
else
return V_31 -> V_2 -> V_18 . V_33 - V_32 -> V_2 -> V_18 . V_33 ;
}
static int F_15 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_19 = V_37 -> V_19 ;
struct V_39 * V_16 = V_35 -> V_16 ;
int V_40 = V_16 -> V_41 . V_42 ;
struct V_30 * * V_43 ;
struct V_1 * V_2 ;
int V_44 , V_45 = 0 ;
int V_46 = 0 ;
F_16 ( L_9 ,
V_35 -> V_18 . V_33 , V_35 -> V_47 ) ;
V_43 = F_17 ( V_40 , sizeof( * V_43 ) , V_48 ) ;
if ( ! V_43 )
return - V_17 ;
F_18 (plane, dev, crtc_state->plane_mask) {
struct V_30 * V_49 =
F_19 ( V_19 , V_2 ) ;
if ( F_20 ( V_49 ) ) {
V_46 = F_21 ( V_49 ) ;
goto V_50;
}
V_43 [ V_45 ++ ] = V_49 ;
F_16 ( L_10 ,
V_2 -> V_18 . V_33 , V_2 -> V_47 ,
V_49 -> V_22 ) ;
}
F_22 ( V_43 , V_45 , sizeof( * V_43 ) , F_14 , NULL ) ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
V_2 = V_43 [ V_44 ] -> V_2 ;
V_43 [ V_44 ] -> V_26 = V_44 ;
F_16 ( L_11 ,
V_2 -> V_18 . V_33 , V_2 -> V_47 , V_44 ) ;
}
V_37 -> V_51 = true ;
V_50:
F_23 ( V_43 ) ;
return V_46 ;
}
int F_24 ( struct V_39 * V_16 ,
struct V_38 * V_19 )
{
struct V_34 * V_35 ;
struct V_36 * V_52 , * V_53 ;
struct V_1 * V_2 ;
struct V_30 * V_54 , * V_55 ;
int V_44 , V_46 = 0 ;
F_25 (state, plane, old_plane_state, new_plane_state, i) {
V_35 = V_55 -> V_35 ;
if ( ! V_35 )
continue;
if ( V_54 -> V_22 != V_55 -> V_22 ) {
V_53 = F_26 ( V_19 , V_35 ) ;
V_53 -> V_51 = true ;
}
}
F_27 (state, crtc, old_crtc_state, new_crtc_state, i) {
if ( V_52 -> V_56 != V_53 -> V_56 ||
V_53 -> V_51 ) {
V_46 = F_15 ( V_35 ,
V_53 ) ;
if ( V_46 )
return V_46 ;
}
}
return 0 ;
}
