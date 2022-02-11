int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 =
F_3 ( V_4 ) ;
if ( V_6 == V_11 -> V_14 )
* V_7 = V_13 -> V_15 ;
else if ( V_6 == V_11 -> V_16 )
* V_7 = V_13 -> V_17 ;
else {
F_4 ( L_1 , V_6 -> V_18 ) ;
return - V_19 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_9 ) ;
struct V_12 * V_13 =
F_3 ( V_4 ) ;
if ( V_6 == V_11 -> V_14 ) {
V_13 -> V_15 = V_7 ;
return 0 ;
}
if ( V_6 == V_11 -> V_16 ) {
V_13 -> V_17 = V_7 ;
return 0 ;
}
F_4 ( L_1 , V_6 -> V_18 ) ;
return - V_19 ;
}
int F_6 ( struct V_1 * V_20 ,
struct V_3 * V_21 )
{
struct V_12 * V_22 =
F_3 ( V_21 ) ;
struct V_3 * V_23 =
F_7 ( V_21 -> V_4 , V_20 ) ;
struct V_12 * V_24 =
F_3 ( V_23 ) ;
struct V_25 * V_26 ;
if ( ! V_21 -> V_27 )
return 0 ;
V_26 = F_8 ( V_21 -> V_4 , V_21 -> V_27 ) ;
if ( V_22 -> V_15 != V_24 -> V_15 ||
V_22 -> V_17 != V_24 -> V_17 ||
V_22 -> V_28 . V_29 != V_24 -> V_28 . V_29 ||
V_22 -> V_28 . V_30 != V_24 -> V_28 . V_30 )
V_26 -> V_31 = true ;
return 0 ;
}
struct V_3 *
F_9 ( struct V_1 * V_2 )
{
struct V_12 * V_4 ;
V_4 = F_10 ( V_2 -> V_4 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return NULL ;
F_11 ( V_2 , & V_4 -> V_28 ) ;
return & V_4 -> V_28 ;
}
struct V_25 *
F_12 ( struct V_33 * V_27 )
{
struct V_34 * V_26 ;
V_26 = F_10 ( V_27 -> V_4 , sizeof( * V_26 ) , V_32 ) ;
if ( ! V_26 )
return NULL ;
F_13 ( V_27 , & V_26 -> V_28 ) ;
V_26 -> V_35 = false ;
V_26 -> V_36 = false ;
V_26 -> V_37 = false ;
V_26 -> V_38 = false ;
V_26 -> V_39 = false ;
V_26 -> V_40 = false ;
V_26 -> V_41 = false ;
V_26 -> V_42 . V_43 = false ;
V_26 -> V_44 = 0 ;
return & V_26 -> V_28 ;
}
void
F_14 ( struct V_33 * V_27 ,
struct V_25 * V_4 )
{
F_15 ( V_27 , V_4 ) ;
}
int F_16 ( struct V_10 * V_11 ,
struct V_45 * V_45 ,
struct V_34 * V_26 )
{
struct V_46 * V_47 = NULL ;
struct V_48 * V_48 ;
struct V_49 * V_50 = NULL ;
struct V_51 * V_52 =
& V_26 -> V_52 ;
struct V_53 * V_54 = V_26 -> V_28 . V_4 ;
int V_55 ;
int V_56 , V_57 ;
V_55 = F_17 ( V_52 -> V_58 ) ;
if ( V_55 > V_45 -> V_59 ) {
F_18 ( L_2 ,
V_55 , V_45 -> V_59 ) ;
return - V_19 ;
}
for ( V_56 = 0 ; V_56 < sizeof( V_52 -> V_58 ) * 8 ; V_56 ++ ) {
int * V_60 ;
const char * V_18 ;
int V_61 ;
if ( ! ( V_52 -> V_58 & ( 1 << V_56 ) ) )
continue;
if ( V_56 == V_62 ) {
V_18 = L_3 ;
V_61 = V_45 -> V_28 . V_28 . V_63 ;
V_60 = & V_52 -> V_60 ;
} else {
V_18 = L_4 ;
V_47 = V_54 -> V_64 [ V_56 ] . V_65 ;
if ( ! V_47 ) {
struct V_66 * V_4 ;
V_47 = F_19 ( & V_11 -> V_67 , V_56 ) ;
V_4 = F_20 ( V_54 , V_47 ) ;
if ( F_21 ( V_4 ) ) {
F_18 ( L_5 ,
V_47 -> V_28 . V_63 ) ;
return F_22 ( V_4 ) ;
}
V_26 -> V_28 . V_68 = true ;
}
V_48 = F_23 ( V_47 ) ;
V_61 = V_47 -> V_28 . V_63 ;
if ( F_24 ( V_48 -> V_69 != V_45 -> V_69 ) ) {
continue;
}
V_50 = F_25 ( V_54 ,
V_48 ) ;
V_60 = & V_50 -> V_60 ;
}
if ( * V_60 < 0 ) {
for ( V_57 = 0 ; V_57 < V_45 -> V_59 ; V_57 ++ ) {
if ( ! V_52 -> V_70 [ V_57 ] . V_71 ) {
V_52 -> V_70 [ V_57 ] . V_71 = 1 ;
* V_60 = V_57 ;
F_18 ( L_6 ,
V_45 -> V_69 , * V_60 , V_18 , V_61 ) ;
break;
}
}
}
if ( F_24 ( * V_60 < 0 ) ) {
F_18 ( L_7 , V_18 , V_61 ) ;
continue;
}
if ( F_26 ( V_11 ) || F_27 ( V_11 ) ) {
V_52 -> V_70 [ * V_60 ] . V_72 = 0 ;
} else if ( V_55 == 1 && V_45 -> V_69 != V_73 ) {
* V_60 = 0 ;
V_52 -> V_70 [ 0 ] . V_71 = 1 ;
V_52 -> V_70 [ 0 ] . V_72 = V_74 ;
V_52 -> V_70 [ 1 ] . V_71 = 0 ;
} else {
V_52 -> V_70 [ * V_60 ] . V_72 = V_75 ;
}
}
return 0 ;
}
struct V_53 *
F_28 ( struct V_8 * V_9 )
{
struct V_76 * V_4 = F_29 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 || F_30 ( V_9 , & V_4 -> V_28 ) < 0 ) {
F_31 ( V_4 ) ;
return NULL ;
}
return & V_4 -> V_28 ;
}
void F_32 ( struct V_53 * V_77 )
{
struct V_76 * V_4 = F_33 ( V_77 ) ;
F_34 ( & V_4 -> V_28 ) ;
V_4 -> V_78 = V_4 -> V_79 = false ;
}
