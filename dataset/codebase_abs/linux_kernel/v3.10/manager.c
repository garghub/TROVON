int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_5 = F_2 () ;
V_6 = F_3 ( sizeof( struct V_7 ) * V_5 ,
V_8 ) ;
F_4 ( V_6 == NULL ) ;
for ( V_3 = 0 ; V_3 < V_5 ; ++ V_3 ) {
struct V_7 * V_9 = & V_6 [ V_3 ] ;
switch ( V_3 ) {
case 0 :
V_9 -> V_10 = L_1 ;
V_9 -> V_11 = V_12 ;
break;
case 1 :
V_9 -> V_10 = L_2 ;
V_9 -> V_11 = V_13 ;
break;
case 2 :
V_9 -> V_10 = L_3 ;
V_9 -> V_11 = V_14 ;
break;
case 3 :
V_9 -> V_10 = L_4 ;
V_9 -> V_11 = V_15 ;
break;
}
V_9 -> V_16 = 0 ;
V_9 -> V_17 =
F_5 ( V_9 -> V_11 ) ;
V_9 -> V_18 =
F_6 ( V_9 -> V_11 ) ;
F_7 ( & V_9 -> V_19 ) ;
V_4 = F_8 ( V_9 , V_2 ) ;
if ( V_4 )
F_9 ( L_5 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_5 ; ++ V_3 ) {
struct V_7 * V_9 = & V_6 [ V_3 ] ;
F_11 ( V_9 ) ;
}
F_12 ( V_6 ) ;
V_6 = NULL ;
V_5 = 0 ;
}
int F_13 ( void )
{
return V_5 ;
}
struct V_7 * F_14 ( int V_20 )
{
if ( V_20 >= V_5 )
return NULL ;
return & V_6 [ V_20 ] ;
}
int F_15 ( struct V_7 * V_9 ,
const struct V_21 * V_22 )
{
if ( F_16 ( V_23 ) ) {
if ( V_22 -> V_24 && V_22 -> V_25
&& V_22 -> V_26 != V_27 ) {
F_9 ( L_6 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_17 ( struct V_7 * V_9 ,
struct V_29 * * V_30 )
{
struct V_31 * V_32 , * V_33 ;
struct V_29 * V_34 , * V_35 ;
F_18 (ovl1, &mgr->overlays, list) {
V_34 = V_30 [ V_32 -> V_11 ] ;
if ( V_34 == NULL )
continue;
F_18 (ovl2, &mgr->overlays, list) {
if ( V_32 == V_33 )
continue;
V_35 = V_30 [ V_33 -> V_11 ] ;
if ( V_35 == NULL )
continue;
if ( V_34 -> V_36 == V_35 -> V_36 ) {
F_9 ( L_7
L_8 ,
V_32 -> V_11 , V_33 -> V_11 , V_34 -> V_36 ) ;
return - V_28 ;
}
}
}
return 0 ;
}
int F_19 ( struct V_7 * V_9 ,
const struct V_37 * V_38 )
{
if ( ! F_20 ( V_9 -> V_11 , V_38 ) ) {
F_9 ( L_9 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_9 ,
const struct V_39 * V_40 )
{
struct V_41 V_42 = V_40 -> V_43 ;
int V_44 = V_40 -> V_45 ;
bool V_46 = V_40 -> V_46 ;
bool V_47 = V_40 -> V_47 ;
if ( V_42 . V_48 < 1 || V_42 . V_48 > 255 )
return - V_28 ;
if ( V_42 . V_49 < 1 || V_42 . V_49 > 255 )
return - V_28 ;
if ( V_44 != 12 && V_44 != 16 && V_44 != 18 && V_44 != 24 )
return - V_28 ;
if ( V_46 == false && V_47 == true )
return - V_28 ;
return 0 ;
}
int F_22 ( struct V_7 * V_9 ,
struct V_21 * V_22 ,
const struct V_37 * V_50 ,
const struct V_39 * V_51 ,
struct V_29 * * V_30 )
{
struct V_31 * V_52 ;
int V_4 ;
if ( F_16 ( V_53 ) ) {
V_4 = F_17 ( V_9 , V_30 ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_19 ( V_9 , V_50 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_21 ( V_9 , V_51 ) ;
if ( V_4 )
return V_4 ;
F_18 (ovl, &mgr->overlays, list) {
struct V_29 * V_54 ;
int V_4 ;
V_54 = V_30 [ V_52 -> V_11 ] ;
if ( V_54 == NULL )
continue;
V_4 = F_23 ( V_52 , V_54 , V_50 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
