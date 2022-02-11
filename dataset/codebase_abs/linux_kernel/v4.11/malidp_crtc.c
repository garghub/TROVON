static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
long V_11 , V_12 = V_4 -> V_13 * 1000 ;
if ( V_12 ) {
V_11 = F_3 ( V_9 -> V_14 , V_12 ) ;
if ( V_11 < V_12 ) {
F_4 ( L_1 ,
V_4 -> V_13 ) ;
return false ;
}
V_11 = F_3 ( V_9 -> V_15 , V_12 ) ;
if ( V_11 != V_12 ) {
F_4 ( L_2 ,
V_12 ) ;
return false ;
}
}
return true ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_16 V_17 ;
F_6 ( & V_2 -> V_18 -> V_5 , & V_17 ) ;
F_7 ( V_9 -> V_15 ) ;
F_8 ( V_9 -> V_15 , V_2 -> V_18 -> V_5 . V_13 * 1000 ) ;
V_9 -> V_19 ( V_9 , & V_17 ) ;
V_9 -> V_20 ( V_9 ) ;
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
F_11 ( V_2 ) ;
V_9 -> V_21 ( V_9 ) ;
F_12 ( V_9 -> V_15 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_18 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_23 * V_24 ;
const struct V_25 * V_26 ;
T_1 V_27 , V_28 ;
int V_29 = 0 ;
F_14 (plane, pstate, state) {
if ( V_26 -> V_30 & V_31 )
V_29 ++ ;
}
V_27 = V_9 -> V_32 [ 0 ] ;
if ( V_29 > 1 )
V_27 += V_9 -> V_32 [ 1 ] ;
F_14 (plane, pstate, state) {
struct V_33 * V_34 = F_15 ( V_24 ) ;
struct V_35 * V_36 = F_16 ( V_26 ) ;
if ( V_26 -> V_30 & V_31 ) {
V_29 -- ;
if ( ! V_29 ) {
V_28 = V_27 ;
} else {
if ( ( V_34 -> V_37 -> V_38 != V_39 ) ||
( V_9 -> V_32 [ 1 ] == 0 ) )
V_28 = V_27 / 2 ;
else
V_28 = V_9 -> V_32 [ 0 ] ;
}
V_27 -= V_28 ;
if ( V_36 -> V_40 > V_28 )
return - V_41 ;
}
}
return 0 ;
}
int F_17 ( struct V_42 * V_43 )
{
struct V_6 * V_7 = V_43 -> V_44 ;
struct V_23 * V_45 = NULL , * V_24 ;
int V_46 ;
V_46 = F_18 ( V_43 ) ;
if ( V_46 < 0 ) {
F_19 ( L_3 ) ;
return V_46 ;
}
F_20 (plane, drm) {
if ( V_24 -> type == V_47 ) {
V_45 = V_24 ;
break;
}
}
if ( ! V_45 ) {
F_19 ( L_4 ) ;
V_46 = - V_41 ;
goto V_48;
}
V_46 = F_21 ( V_43 , & V_7 -> V_2 , V_45 , NULL ,
& V_49 , NULL ) ;
if ( ! V_46 ) {
F_22 ( & V_7 -> V_2 , & V_50 ) ;
return 0 ;
}
V_48:
F_23 ( V_43 ) ;
return V_46 ;
}
