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
V_18 -> V_25 = false ;
V_18 -> V_26 . V_27 = false ;
V_18 -> V_28 = 0 ;
return & V_18 -> V_9 ;
}
void
F_5 ( struct V_15 * V_16 ,
struct V_14 * V_4 )
{
F_6 ( V_16 , V_4 ) ;
}
int F_7 ( struct V_29 * V_30 ,
struct V_31 * V_31 ,
struct V_17 * V_18 )
{
struct V_32 * V_33 = NULL ;
struct V_34 * V_34 ;
struct V_35 * V_36 = NULL ;
struct V_37 * V_38 =
& V_18 -> V_38 ;
struct V_39 * V_40 = V_18 -> V_9 . V_4 ;
int V_41 ;
int V_8 , V_42 ;
V_41 = F_8 ( V_38 -> V_43 ) ;
if ( V_41 > V_31 -> V_44 ) {
F_9 ( L_1 ,
V_41 , V_31 -> V_44 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < sizeof( V_38 -> V_43 ) * 8 ; V_8 ++ ) {
int * V_45 ;
const char * V_46 ;
int V_47 ;
if ( ! ( V_38 -> V_43 & ( 1 << V_8 ) ) )
continue;
if ( V_8 == V_48 ) {
V_46 = L_2 ;
V_47 = V_31 -> V_9 . V_9 . V_49 ;
V_45 = & V_38 -> V_45 ;
} else {
V_46 = L_3 ;
V_33 = V_40 -> V_50 [ V_8 ] . V_51 ;
if ( ! V_33 ) {
struct V_52 * V_4 ;
V_33 = F_10 ( V_30 , V_8 ) ;
V_4 = F_11 ( V_40 , V_33 ) ;
if ( F_12 ( V_4 ) ) {
F_9 ( L_4 ,
V_33 -> V_9 . V_49 ) ;
return F_13 ( V_4 ) ;
}
V_18 -> V_9 . V_53 = true ;
}
V_34 = F_14 ( V_33 ) ;
V_47 = V_33 -> V_9 . V_49 ;
if ( F_15 ( V_34 -> V_54 != V_31 -> V_54 ) ) {
continue;
}
V_36 = F_16 ( V_40 ,
V_34 ) ;
V_45 = & V_36 -> V_45 ;
}
if ( * V_45 < 0 ) {
for ( V_42 = 0 ; V_42 < V_31 -> V_44 ; V_42 ++ ) {
if ( ! V_38 -> V_55 [ V_42 ] . V_56 ) {
V_38 -> V_55 [ V_42 ] . V_56 = 1 ;
* V_45 = V_42 ;
F_9 ( L_5 ,
V_31 -> V_54 , * V_45 , V_46 , V_47 ) ;
break;
}
}
}
if ( F_15 ( * V_45 < 0 ) ) {
F_9 ( L_6 , V_46 , V_47 ) ;
continue;
}
if ( V_41 == 1 && V_31 -> V_54 != V_57 ) {
* V_45 = 0 ;
V_38 -> V_55 [ 0 ] . V_56 = 1 ;
V_38 -> V_55 [ 0 ] . V_58 = V_59 ;
V_38 -> V_55 [ 1 ] . V_56 = 0 ;
} else {
V_38 -> V_55 [ * V_45 ] . V_58 = V_60 ;
}
}
return 0 ;
}
static void
F_17 ( struct V_61 * V_62 ,
struct V_63 * V_64 )
{
enum V_65 V_8 ;
for ( V_8 = 0 ; V_8 < V_62 -> V_66 ; V_8 ++ ) {
struct V_67 * V_68 = & V_62 -> V_69 [ V_8 ] ;
V_64 [ V_8 ] = V_68 -> V_70 ;
}
}
struct V_63 *
F_18 ( struct V_39 * V_71 )
{
struct V_72 * V_4 = F_19 ( V_71 ) ;
F_15 ( ! F_20 ( & V_71 -> V_30 -> V_73 . V_74 ) ) ;
if ( ! V_4 -> V_75 ) {
V_4 -> V_75 = true ;
F_17 ( F_21 ( V_71 -> V_30 ) ,
V_4 -> V_64 ) ;
}
return V_4 -> V_64 ;
}
struct V_39 *
F_22 ( struct V_29 * V_30 )
{
struct V_72 * V_4 = F_23 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 || F_24 ( V_30 , & V_4 -> V_9 ) < 0 ) {
F_25 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_9 ;
}
void F_26 ( struct V_39 * V_71 )
{
struct V_72 * V_4 = F_19 ( V_71 ) ;
F_27 ( & V_4 -> V_9 ) ;
V_4 -> V_75 = V_4 -> V_76 = false ;
}
