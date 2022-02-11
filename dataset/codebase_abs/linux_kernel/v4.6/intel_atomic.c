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
V_18 -> V_21 = false ;
V_18 -> V_22 = false ;
V_18 -> V_23 = false ;
V_18 -> V_24 = false ;
return & V_18 -> V_9 ;
}
void
F_5 ( struct V_15 * V_16 ,
struct V_14 * V_4 )
{
F_6 ( V_16 , V_4 ) ;
}
int F_7 ( struct V_25 * V_26 ,
struct V_27 * V_27 ,
struct V_17 * V_18 )
{
struct V_28 * V_29 = NULL ;
struct V_30 * V_30 ;
struct V_31 * V_32 = NULL ;
struct V_33 * V_34 =
& V_18 -> V_34 ;
struct V_35 * V_36 = V_18 -> V_9 . V_4 ;
int V_37 ;
int V_8 , V_38 ;
V_37 = F_8 ( V_34 -> V_39 ) ;
if ( V_37 > V_27 -> V_40 ) {
F_9 ( L_1 ,
V_37 , V_27 -> V_40 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < sizeof( V_34 -> V_39 ) * 8 ; V_8 ++ ) {
int * V_41 ;
const char * V_42 ;
int V_43 ;
if ( ! ( V_34 -> V_39 & ( 1 << V_8 ) ) )
continue;
if ( V_8 == V_44 ) {
V_42 = L_2 ;
V_43 = V_27 -> V_9 . V_9 . V_45 ;
V_41 = & V_34 -> V_41 ;
} else {
V_42 = L_3 ;
V_29 = V_36 -> V_46 [ V_8 ] ;
if ( ! V_29 ) {
struct V_47 * V_4 ;
V_29 = F_10 ( V_26 , V_8 ) ;
V_4 = F_11 ( V_36 , V_29 ) ;
if ( F_12 ( V_4 ) ) {
F_9 ( L_4 ,
V_29 -> V_9 . V_45 ) ;
return F_13 ( V_4 ) ;
}
V_18 -> V_9 . V_48 = true ;
}
V_30 = F_14 ( V_29 ) ;
V_43 = V_29 -> V_9 . V_45 ;
if ( F_15 ( V_30 -> V_49 != V_27 -> V_49 ) ) {
continue;
}
V_32 = F_16 ( V_36 -> V_50 [ V_8 ] ) ;
V_41 = & V_32 -> V_41 ;
}
if ( * V_41 < 0 ) {
for ( V_38 = 0 ; V_38 < V_27 -> V_40 ; V_38 ++ ) {
if ( ! V_34 -> V_51 [ V_38 ] . V_52 ) {
V_34 -> V_51 [ V_38 ] . V_52 = 1 ;
* V_41 = V_38 ;
F_9 ( L_5 ,
V_27 -> V_49 , * V_41 , V_42 , V_43 ) ;
break;
}
}
}
if ( F_15 ( * V_41 < 0 ) ) {
F_9 ( L_6 , V_42 , V_43 ) ;
continue;
}
if ( V_37 == 1 && V_27 -> V_49 != V_53 ) {
* V_41 = 0 ;
V_34 -> V_51 [ 0 ] . V_52 = 1 ;
V_34 -> V_51 [ 0 ] . V_54 = V_55 ;
V_34 -> V_51 [ 1 ] . V_52 = 0 ;
} else {
V_34 -> V_51 [ * V_41 ] . V_54 = V_56 ;
}
}
return 0 ;
}
static void
F_17 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
enum V_61 V_8 ;
for ( V_8 = 0 ; V_8 < V_58 -> V_62 ; V_8 ++ ) {
struct V_63 * V_64 = & V_58 -> V_65 [ V_8 ] ;
V_60 [ V_8 ] = V_64 -> V_66 ;
}
}
struct V_59 *
F_18 ( struct V_35 * V_67 )
{
struct V_68 * V_4 = F_19 ( V_67 ) ;
F_15 ( ! F_20 ( & V_67 -> V_26 -> V_69 . V_70 ) ) ;
if ( ! V_4 -> V_71 ) {
V_4 -> V_71 = true ;
F_17 ( F_21 ( V_67 -> V_26 ) ,
V_4 -> V_60 ) ;
}
return V_4 -> V_60 ;
}
struct V_35 *
F_22 ( struct V_25 * V_26 )
{
struct V_68 * V_4 = F_23 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 || F_24 ( V_26 , & V_4 -> V_9 ) < 0 ) {
F_25 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_9 ;
}
void F_26 ( struct V_35 * V_67 )
{
struct V_68 * V_4 = F_19 ( V_67 ) ;
F_27 ( & V_4 -> V_9 ) ;
V_4 -> V_71 = V_4 -> V_72 = false ;
}
