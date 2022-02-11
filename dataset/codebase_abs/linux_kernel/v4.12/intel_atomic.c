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
V_18 -> V_26 = false ;
V_18 -> V_27 . V_28 = false ;
V_18 -> V_29 = 0 ;
return & V_18 -> V_9 ;
}
void
F_5 ( struct V_15 * V_16 ,
struct V_14 * V_4 )
{
F_6 ( V_16 , V_4 ) ;
}
int F_7 ( struct V_30 * V_31 ,
struct V_32 * V_32 ,
struct V_17 * V_18 )
{
struct V_33 * V_34 = NULL ;
struct V_35 * V_35 ;
struct V_36 * V_37 = NULL ;
struct V_38 * V_39 =
& V_18 -> V_39 ;
struct V_40 * V_41 = V_18 -> V_9 . V_4 ;
int V_42 ;
int V_8 , V_43 ;
V_42 = F_8 ( V_39 -> V_44 ) ;
if ( V_42 > V_32 -> V_45 ) {
F_9 ( L_1 ,
V_42 , V_32 -> V_45 ) ;
return - V_13 ;
}
for ( V_8 = 0 ; V_8 < sizeof( V_39 -> V_44 ) * 8 ; V_8 ++ ) {
int * V_46 ;
const char * V_47 ;
int V_48 ;
if ( ! ( V_39 -> V_44 & ( 1 << V_8 ) ) )
continue;
if ( V_8 == V_49 ) {
V_47 = L_2 ;
V_48 = V_32 -> V_9 . V_9 . V_50 ;
V_46 = & V_39 -> V_46 ;
} else {
V_47 = L_3 ;
V_34 = V_41 -> V_51 [ V_8 ] . V_52 ;
if ( ! V_34 ) {
struct V_53 * V_4 ;
V_34 = F_10 ( & V_31 -> V_54 , V_8 ) ;
V_4 = F_11 ( V_41 , V_34 ) ;
if ( F_12 ( V_4 ) ) {
F_9 ( L_4 ,
V_34 -> V_9 . V_50 ) ;
return F_13 ( V_4 ) ;
}
V_18 -> V_9 . V_55 = true ;
}
V_35 = F_14 ( V_34 ) ;
V_48 = V_34 -> V_9 . V_50 ;
if ( F_15 ( V_35 -> V_56 != V_32 -> V_56 ) ) {
continue;
}
V_37 = F_16 ( V_41 ,
V_35 ) ;
V_46 = & V_37 -> V_46 ;
}
if ( * V_46 < 0 ) {
for ( V_43 = 0 ; V_43 < V_32 -> V_45 ; V_43 ++ ) {
if ( ! V_39 -> V_57 [ V_43 ] . V_58 ) {
V_39 -> V_57 [ V_43 ] . V_58 = 1 ;
* V_46 = V_43 ;
F_9 ( L_5 ,
V_32 -> V_56 , * V_46 , V_47 , V_48 ) ;
break;
}
}
}
if ( F_15 ( * V_46 < 0 ) ) {
F_9 ( L_6 , V_47 , V_48 ) ;
continue;
}
if ( F_17 ( V_31 ) ) {
V_39 -> V_57 [ * V_46 ] . V_59 = 0 ;
} else if ( V_42 == 1 && V_32 -> V_56 != V_60 ) {
* V_46 = 0 ;
V_39 -> V_57 [ 0 ] . V_58 = 1 ;
V_39 -> V_57 [ 0 ] . V_59 = V_61 ;
V_39 -> V_57 [ 1 ] . V_58 = 0 ;
} else {
V_39 -> V_57 [ * V_46 ] . V_59 = V_62 ;
}
}
return 0 ;
}
struct V_40 *
F_18 ( struct V_63 * V_64 )
{
struct V_65 * V_4 = F_19 ( sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 || F_20 ( V_64 , & V_4 -> V_9 ) < 0 ) {
F_21 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_9 ;
}
void F_22 ( struct V_40 * V_66 )
{
struct V_65 * V_4 = F_23 ( V_66 ) ;
F_24 ( & V_4 -> V_9 ) ;
V_4 -> V_67 = V_4 -> V_68 = false ;
}
