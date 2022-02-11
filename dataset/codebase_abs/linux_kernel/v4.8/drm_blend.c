int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 -> V_8 , 0 , L_1 , V_4 , V_5 ) ;
if ( ! V_7 )
return - V_9 ;
F_3 ( & V_2 -> V_10 , V_7 , V_3 ) ;
V_2 -> V_11 = V_7 ;
if ( V_2 -> V_12 ) {
V_2 -> V_12 -> V_3 = V_3 ;
V_2 -> V_12 -> V_13 = V_3 ;
}
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_14 ,
L_1 , V_3 , V_3 ) ;
if ( ! V_7 )
return - V_9 ;
F_3 ( & V_2 -> V_10 , V_7 , V_3 ) ;
V_2 -> V_11 = V_7 ;
if ( V_2 -> V_12 ) {
V_2 -> V_12 -> V_3 = V_3 ;
V_2 -> V_12 -> V_13 = V_3 ;
}
return 0 ;
}
static int F_5 ( const void * V_15 , const void * V_16 )
{
const struct V_17 * V_18 = * (struct V_17 * * ) V_15 ;
const struct V_17 * V_19 = * (struct V_17 * * ) V_16 ;
if ( V_18 -> V_3 != V_19 -> V_3 )
return V_18 -> V_3 - V_19 -> V_3 ;
else
return V_18 -> V_2 -> V_10 . V_20 - V_19 -> V_2 -> V_10 . V_20 ;
}
static int F_6 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_12 = V_24 -> V_12 ;
struct V_26 * V_8 = V_22 -> V_8 ;
int V_27 = V_8 -> V_28 . V_29 ;
struct V_17 * * V_30 ;
struct V_1 * V_2 ;
int V_31 , V_32 = 0 ;
int V_33 = 0 ;
F_7 ( L_2 ,
V_22 -> V_10 . V_20 , V_22 -> V_34 ) ;
V_30 = F_8 ( V_27 , sizeof( * V_30 ) , V_35 ) ;
if ( ! V_30 )
return - V_9 ;
F_9 (plane, dev, crtc_state->plane_mask) {
struct V_17 * V_36 =
F_10 ( V_12 , V_2 ) ;
if ( F_11 ( V_36 ) ) {
V_33 = F_12 ( V_36 ) ;
goto V_37;
}
V_30 [ V_32 ++ ] = V_36 ;
F_7 ( L_3 ,
V_2 -> V_10 . V_20 , V_2 -> V_34 ,
V_36 -> V_3 ) ;
}
F_13 ( V_30 , V_32 , sizeof( * V_30 ) , F_5 , NULL ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_2 = V_30 [ V_31 ] -> V_2 ;
V_30 [ V_31 ] -> V_13 = V_31 ;
F_7 ( L_4 ,
V_2 -> V_10 . V_20 , V_2 -> V_34 , V_31 ) ;
}
V_24 -> V_38 = true ;
V_37:
F_14 ( V_30 ) ;
return V_33 ;
}
int F_15 ( struct V_26 * V_8 ,
struct V_25 * V_12 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_1 * V_2 ;
struct V_17 * V_36 ;
int V_31 , V_33 = 0 ;
F_16 (state, plane, plane_state, i) {
V_22 = V_36 -> V_22 ;
if ( ! V_22 )
continue;
if ( V_2 -> V_12 -> V_3 != V_36 -> V_3 ) {
V_24 =
F_17 ( V_12 , V_22 ) ;
V_24 -> V_38 = true ;
}
}
F_18 (state, crtc, crtc_state, i) {
if ( V_24 -> V_39 != V_22 -> V_12 -> V_39 ||
V_24 -> V_38 ) {
V_33 = F_6 ( V_22 ,
V_24 ) ;
if ( V_33 )
return V_33 ;
}
}
return 0 ;
}
