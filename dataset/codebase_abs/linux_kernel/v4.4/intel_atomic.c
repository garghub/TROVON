int
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 . V_10 -> V_11 ; V_8 ++ ) {
if ( V_2 -> V_9 . V_10 -> V_10 [ V_8 ] == V_6 ) {
* V_7 = V_2 -> V_9 . V_10 -> V_12 [ V_8 ] ;
return 0 ;
}
}
return - V_13 ;
}
struct V_14 *
F_2 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
V_18 = F_3 ( V_16 -> V_4 , sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 )
return NULL ;
F_4 ( V_16 , & V_18 -> V_9 ) ;
V_18 -> V_20 = false ;
return & V_18 -> V_9 ;
}
void
F_5 ( struct V_15 * V_16 ,
struct V_14 * V_4 )
{
F_6 ( V_16 , V_4 ) ;
}
int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_23 ,
struct V_17 * V_18 )
{
struct V_24 * V_25 = NULL ;
struct V_26 * V_26 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 =
& V_18 -> V_30 ;
struct V_31 * V_32 = V_18 -> V_9 . V_4 ;
int V_33 ;
int V_8 , V_34 ;
V_33 = F_8 ( V_30 -> V_35 ) ;
if ( V_33 > V_23 -> V_36 ) {
F_9 ( L_1 ,
V_33 , V_23 -> V_36 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < sizeof( V_30 -> V_35 ) * 8 ; V_8 ++ ) {
int * V_37 ;
const char * V_38 ;
int V_39 ;
if ( ! ( V_30 -> V_35 & ( 1 << V_8 ) ) )
continue;
if ( V_8 == V_40 ) {
V_38 = L_2 ;
V_39 = V_23 -> V_9 . V_9 . V_41 ;
V_37 = & V_30 -> V_37 ;
} else {
V_38 = L_3 ;
V_25 = V_32 -> V_42 [ V_8 ] ;
if ( ! V_25 ) {
struct V_43 * V_4 ;
V_25 = F_10 ( V_22 , V_8 ) ;
V_4 = F_11 ( V_32 , V_25 ) ;
if ( F_12 ( V_4 ) ) {
F_9 ( L_4 ,
V_25 -> V_9 . V_41 ) ;
return F_13 ( V_4 ) ;
}
if ( V_25 -> type == V_44 )
V_23 -> V_45 . V_46 = true ;
V_18 -> V_9 . V_47 = true ;
}
V_26 = F_14 ( V_25 ) ;
V_39 = V_25 -> V_9 . V_41 ;
if ( F_15 ( V_26 -> V_48 != V_23 -> V_48 ) ) {
continue;
}
V_28 = F_16 ( V_32 -> V_49 [ V_8 ] ) ;
V_37 = & V_28 -> V_37 ;
}
if ( * V_37 < 0 ) {
for ( V_34 = 0 ; V_34 < V_23 -> V_36 ; V_34 ++ ) {
if ( ! V_30 -> V_50 [ V_34 ] . V_51 ) {
V_30 -> V_50 [ V_34 ] . V_51 = 1 ;
* V_37 = V_34 ;
F_9 ( L_5 ,
V_23 -> V_48 , * V_37 , V_38 , V_39 ) ;
break;
}
}
}
if ( F_15 ( * V_37 < 0 ) ) {
F_9 ( L_6 , V_38 , V_39 ) ;
continue;
}
if ( V_33 == 1 && V_23 -> V_48 != V_52 ) {
* V_37 = 0 ;
V_30 -> V_50 [ 0 ] . V_51 = 1 ;
V_30 -> V_50 [ 0 ] . V_53 = V_54 ;
V_30 -> V_50 [ 1 ] . V_51 = 0 ;
} else {
V_30 -> V_50 [ * V_37 ] . V_53 = V_55 ;
}
}
return 0 ;
}
static void
F_17 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
enum V_60 V_8 ;
for ( V_8 = 0 ; V_8 < V_57 -> V_61 ; V_8 ++ ) {
struct V_62 * V_63 = & V_57 -> V_64 [ V_8 ] ;
V_59 [ V_8 ] = V_63 -> V_65 ;
}
}
struct V_58 *
F_18 ( struct V_31 * V_66 )
{
struct V_67 * V_4 = F_19 ( V_66 ) ;
F_15 ( ! F_20 ( & V_66 -> V_22 -> V_68 . V_69 ) ) ;
if ( ! V_4 -> V_70 ) {
V_4 -> V_70 = true ;
F_17 ( F_21 ( V_66 -> V_22 ) ,
V_4 -> V_59 ) ;
}
return V_4 -> V_59 ;
}
struct V_31 *
F_22 ( struct V_21 * V_22 )
{
struct V_67 * V_4 = F_23 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 || F_24 ( V_22 , & V_4 -> V_9 ) < 0 ) {
F_25 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_9 ;
}
void F_26 ( struct V_31 * V_66 )
{
struct V_67 * V_4 = F_19 ( V_66 ) ;
F_27 ( & V_4 -> V_9 ) ;
V_4 -> V_70 = false ;
}
