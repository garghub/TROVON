int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 . V_7 ;
int V_8 = V_2 -> V_6 . V_9 ;
int V_10 = V_2 -> V_6 . V_11 ;
enum V_12 V_13 = V_14 ;
struct V_15 * V_16 = NULL ;
struct V_17 * V_18 = NULL ;
int V_19 ;
int V_20 ;
bool V_21 = false ;
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
struct V_22 * V_23 = F_2 ( V_4 -> V_24 [ V_20 ] ) ;
if ( ! V_23 )
continue;
if ( V_13 == V_14 ) {
V_13 = V_23 -> V_12 ;
} else if ( V_13 != V_23 -> V_12 ) {
F_3 ( L_1 ) ;
return - V_25 ;
}
}
V_4 -> V_26 = false ;
for ( V_20 = 0 ; V_20 < V_8 ; V_20 ++ ) {
struct V_15 * V_27 = F_4 ( V_4 -> V_28 [ V_20 ] ) ;
if ( V_27 )
memset ( & V_27 -> V_29 , 0 , sizeof( V_27 -> V_29 ) ) ;
if ( V_27 && V_27 -> V_12 != V_13 )
V_21 = true ;
if ( V_27 && V_27 -> V_12 == V_13 ) {
V_16 = V_27 ;
V_18 = F_5 ( V_4 -> V_30 [ V_20 ] ) ;
}
}
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ )
if ( V_4 -> V_31 [ V_20 ] != NULL )
V_21 = true ;
if ( V_21 ) {
F_3 ( L_2 ) ;
return - V_25 ;
}
V_19 = F_6 ( V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_7 ( V_2 , V_16 , V_18 ) ;
if ( V_19 )
return V_19 ;
return V_19 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_32 )
{
struct V_33 * V_18 ;
struct V_34 * V_27 ;
int V_19 , V_20 ;
if ( V_32 ) {
F_3 ( L_3 ) ;
return - V_25 ;
}
V_19 = F_9 ( V_2 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_10 ( V_2 , V_4 ) ;
F_11 (state, crtc, crtc_state, i) {
F_4 ( V_27 ) -> V_35 = F_5 ( V_27 -> V_4 ) ;
if ( F_12 ( V_2 ) -> V_36 >= 9 )
F_13 ( F_4 ( V_27 ) ) ;
F_14 ( V_18 ) ;
}
F_15 ( V_2 , V_4 ) ;
F_16 ( V_2 , V_4 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
int
F_18 ( struct V_37 * V_38 ,
const struct V_39 * V_4 ,
struct V_40 * V_41 ,
T_1 * V_42 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_38 -> V_43 . V_44 -> V_45 ; V_20 ++ ) {
if ( V_38 -> V_43 . V_44 -> V_44 [ V_20 ] == V_41 ) {
* V_42 = V_38 -> V_43 . V_44 -> V_46 [ V_20 ] ;
return 0 ;
}
}
return - V_25 ;
}
struct V_33 *
F_19 ( struct V_34 * V_27 )
{
struct V_15 * V_15 = F_4 ( V_27 ) ;
struct V_17 * V_18 ;
if ( F_20 ( ! V_15 -> V_35 ) )
V_18 = F_21 ( sizeof( * V_18 ) , V_47 ) ;
else
V_18 = F_22 ( V_15 -> V_35 ,
sizeof( * V_15 -> V_35 ) , V_47 ) ;
if ( ! V_18 )
return NULL ;
F_23 ( V_27 , & V_18 -> V_43 ) ;
V_18 -> V_43 . V_27 = V_27 ;
return & V_18 -> V_43 ;
}
void
F_24 ( struct V_34 * V_27 ,
struct V_33 * V_4 )
{
F_25 ( V_27 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_15 ,
struct V_17 * V_18 )
{
struct V_48 * V_23 = NULL ;
struct V_22 * V_22 ;
struct V_49 * V_50 = NULL ;
struct V_51 * V_52 ;
struct V_3 * V_53 ;
int V_54 ;
int V_20 , V_55 ;
if ( F_12 ( V_2 ) -> V_36 < 9 || ! V_15 || ! V_18 )
return 0 ;
V_52 = & V_18 -> V_52 ;
V_53 = V_18 -> V_43 . V_4 ;
V_54 = F_26 ( V_52 -> V_56 ) ;
F_3 ( L_4 ,
V_18 , V_54 , V_15 -> V_57 ,
V_52 -> V_56 ) ;
if ( V_54 > V_15 -> V_57 ) {
F_3 ( L_5 ,
V_54 , V_15 -> V_57 ) ;
return - V_25 ;
}
for ( V_20 = 0 ; V_20 < sizeof( V_52 -> V_56 ) * 8 ; V_20 ++ ) {
int * V_58 ;
if ( ! ( V_52 -> V_56 & ( 1 << V_20 ) ) )
continue;
if ( V_20 == V_59 ) {
V_58 = & V_52 -> V_58 ;
} else {
if ( ! V_53 )
continue;
V_23 = V_53 -> V_24 [ V_20 ] ;
if ( ! V_23 ) {
struct V_60 * V_4 ;
V_23 = F_27 ( V_2 , V_20 ) ;
V_4 = F_28 ( V_53 , V_23 ) ;
if ( F_29 ( V_4 ) ) {
F_3 ( L_6 ,
V_23 -> V_43 . V_61 ) ;
return F_30 ( V_4 ) ;
}
}
V_22 = F_2 ( V_23 ) ;
if ( F_20 ( V_22 -> V_12 != V_15 -> V_12 ) ) {
continue;
}
V_50 = F_31 ( V_53 -> V_62 [ V_20 ] ) ;
V_58 = & V_50 -> V_58 ;
}
if ( * V_58 < 0 ) {
for ( V_55 = 0 ; V_55 < V_15 -> V_57 ; V_55 ++ ) {
if ( ! V_52 -> V_63 [ V_55 ] . V_64 ) {
V_52 -> V_63 [ V_55 ] . V_64 = 1 ;
* V_58 = V_52 -> V_63 [ V_55 ] . V_61 ;
F_3 ( L_7 ,
V_15 -> V_12 ,
V_20 == V_59 ? V_52 -> V_58 :
V_50 -> V_58 ,
V_20 == V_59 ? L_8 : L_9 ,
V_20 == V_59 ? V_15 -> V_43 . V_43 . V_61 :
V_23 -> V_43 . V_61 ) ;
break;
}
}
}
if ( F_20 ( * V_58 < 0 ) ) {
F_3 ( L_10 ,
V_20 == V_59 ? L_8 : L_9 ,
V_20 == V_59 ? V_15 -> V_43 . V_43 . V_61 : V_23 -> V_43 . V_61 ) ;
continue;
}
if ( V_54 == 1 && V_15 -> V_12 != V_65 ) {
* V_58 = 0 ;
V_52 -> V_63 [ 0 ] . V_64 = 1 ;
V_52 -> V_63 [ 0 ] . V_66 = V_67 ;
V_52 -> V_63 [ 1 ] . V_64 = 0 ;
} else {
V_52 -> V_63 [ * V_58 ] . V_66 = V_68 ;
}
}
return 0 ;
}
