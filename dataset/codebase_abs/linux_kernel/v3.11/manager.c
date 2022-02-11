int F_1 ( void )
{
int V_1 ;
V_2 = F_2 () ;
V_3 = F_3 ( sizeof( struct V_4 ) * V_2 ,
V_5 ) ;
F_4 ( V_3 == NULL ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_4 * V_6 = & V_3 [ V_1 ] ;
switch ( V_1 ) {
case 0 :
V_6 -> V_7 = L_1 ;
V_6 -> V_8 = V_9 ;
break;
case 1 :
V_6 -> V_7 = L_2 ;
V_6 -> V_8 = V_10 ;
break;
case 2 :
V_6 -> V_7 = L_3 ;
V_6 -> V_8 = V_11 ;
break;
case 3 :
V_6 -> V_7 = L_4 ;
V_6 -> V_8 = V_12 ;
break;
}
V_6 -> V_13 = 0 ;
V_6 -> V_14 =
F_5 ( V_6 -> V_8 ) ;
V_6 -> V_15 =
F_6 ( V_6 -> V_8 ) ;
F_7 ( & V_6 -> V_16 ) ;
}
return 0 ;
}
int F_8 ( struct V_17 * V_18 )
{
int V_1 , V_19 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_4 * V_6 = & V_3 [ V_1 ] ;
V_19 = F_9 ( V_6 , V_18 ) ;
if ( V_19 )
F_10 ( L_5 ) ;
}
return 0 ;
}
void F_11 ( void )
{
F_12 ( V_3 ) ;
V_3 = NULL ;
V_2 = 0 ;
}
void F_13 ( struct V_17 * V_18 )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
struct V_4 * V_6 = & V_3 [ V_1 ] ;
F_14 ( V_6 ) ;
}
}
int F_15 ( void )
{
return V_2 ;
}
struct V_4 * F_16 ( int V_20 )
{
if ( V_20 >= V_2 )
return NULL ;
return & V_3 [ V_20 ] ;
}
int F_17 ( struct V_4 * V_6 ,
const struct V_21 * V_22 )
{
if ( F_18 ( V_23 ) ) {
if ( V_22 -> V_24 && V_22 -> V_25
&& V_22 -> V_26 != V_27 ) {
F_10 ( L_6 ) ;
return - V_28 ;
}
}
return 0 ;
}
static int F_19 ( struct V_4 * V_6 ,
struct V_29 * * V_30 )
{
struct V_31 * V_32 , * V_33 ;
struct V_29 * V_34 , * V_35 ;
F_20 (ovl1, &mgr->overlays, list) {
V_34 = V_30 [ V_32 -> V_8 ] ;
if ( V_34 == NULL )
continue;
F_20 (ovl2, &mgr->overlays, list) {
if ( V_32 == V_33 )
continue;
V_35 = V_30 [ V_33 -> V_8 ] ;
if ( V_35 == NULL )
continue;
if ( V_34 -> V_36 == V_35 -> V_36 ) {
F_10 ( L_7
L_8 ,
V_32 -> V_8 , V_33 -> V_8 , V_34 -> V_36 ) ;
return - V_28 ;
}
}
}
return 0 ;
}
int F_21 ( struct V_4 * V_6 ,
const struct V_37 * V_38 )
{
if ( ! F_22 ( V_6 -> V_8 , V_38 ) ) {
F_10 ( L_9 ) ;
return - V_28 ;
}
return 0 ;
}
static int F_23 ( struct V_4 * V_6 ,
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
int F_24 ( struct V_4 * V_6 ,
struct V_21 * V_22 ,
const struct V_37 * V_50 ,
const struct V_39 * V_51 ,
struct V_29 * * V_30 )
{
struct V_31 * V_52 ;
int V_19 ;
if ( F_18 ( V_53 ) ) {
V_19 = F_19 ( V_6 , V_30 ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_21 ( V_6 , V_50 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_23 ( V_6 , V_51 ) ;
if ( V_19 )
return V_19 ;
F_20 (ovl, &mgr->overlays, list) {
struct V_29 * V_54 ;
int V_19 ;
V_54 = V_30 [ V_52 -> V_8 ] ;
if ( V_54 == NULL )
continue;
V_19 = F_25 ( V_52 , V_54 , V_50 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
