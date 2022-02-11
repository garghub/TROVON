int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 . V_7 ;
int V_8 = V_2 -> V_6 . V_9 ;
int V_10 = V_2 -> V_6 . V_11 ;
enum V_12 V_13 = V_14 ;
int V_15 ;
int V_16 ;
bool V_17 = false ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ ) {
struct V_18 * V_19 = F_2 ( V_4 -> V_20 [ V_16 ] ) ;
if ( ! V_19 )
continue;
if ( V_13 == V_14 ) {
V_13 = V_19 -> V_12 ;
} else if ( V_13 != V_19 -> V_12 ) {
F_3 ( L_1 ) ;
return - V_21 ;
}
}
V_4 -> V_22 = false ;
for ( V_16 = 0 ; V_16 < V_8 ; V_16 ++ ) {
struct V_23 * V_24 = F_4 ( V_4 -> V_25 [ V_16 ] ) ;
if ( V_24 && V_24 -> V_12 != V_13 )
V_17 = true ;
}
for ( V_16 = 0 ; V_16 < V_10 ; V_16 ++ )
if ( V_4 -> V_26 [ V_16 ] != NULL )
V_17 = true ;
if ( V_17 ) {
F_3 ( L_2 ) ;
return - V_21 ;
}
V_15 = F_5 ( V_2 , V_4 ) ;
if ( V_15 )
return V_15 ;
return V_15 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_27 )
{
int V_15 ;
int V_16 ;
if ( V_27 ) {
F_3 ( L_3 ) ;
return - V_21 ;
}
V_15 = F_7 ( V_2 , V_4 ) ;
if ( V_15 )
return V_15 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_6 . V_7 ; V_16 ++ ) {
struct V_28 * V_19 = V_4 -> V_20 [ V_16 ] ;
if ( ! V_19 )
continue;
V_19 -> V_4 -> V_4 = V_4 ;
F_8 ( V_4 -> V_29 [ V_16 ] , V_19 -> V_4 ) ;
V_19 -> V_4 -> V_4 = NULL ;
}
F_9 ( V_2 , V_4 ) ;
F_10 ( V_2 , V_4 ) ;
F_11 ( V_2 , V_4 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
int
F_13 ( struct V_30 * V_31 ,
const struct V_32 * V_4 ,
struct V_33 * V_34 ,
T_1 * V_35 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_31 -> V_36 . V_37 -> V_38 ; V_16 ++ ) {
if ( V_31 -> V_36 . V_37 -> V_37 [ V_16 ] == V_34 ) {
* V_35 = V_31 -> V_36 . V_37 -> V_39 [ V_16 ] ;
return 0 ;
}
}
return - V_21 ;
}
struct V_40 *
F_14 ( struct V_41 * V_24 )
{
struct V_23 * V_23 = F_4 ( V_24 ) ;
struct V_42 * V_43 ;
if ( F_15 ( ! V_23 -> V_44 ) )
V_43 = F_16 ( sizeof( * V_43 ) , V_45 ) ;
else
V_43 = F_17 ( V_23 -> V_44 ,
sizeof( * V_23 -> V_44 ) , V_45 ) ;
if ( V_43 )
V_43 -> V_36 . V_24 = V_24 ;
return & V_43 -> V_36 ;
}
void
F_18 ( struct V_41 * V_24 ,
struct V_40 * V_4 )
{
F_19 ( V_24 , V_4 ) ;
}
