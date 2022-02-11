static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 = F_2 ( V_3 ) ;
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_15 * V_16 ;
V_8 = & F_3 ( V_3 ) -> V_17 ;
if ( ! V_12 || ! F_4 ( V_12 -> V_18 , V_5 -> V_19 . V_20 ) ) {
V_8 -> V_21 = V_3 ;
V_8 -> V_22 = V_12 ;
V_8 -> V_23 = NULL ;
} else {
V_16 = F_5 ( V_3 , V_10 , V_7 -> V_24 ) ;
if ( ! F_6 ( V_16 ) ) {
V_8 -> V_21 = V_16 -> V_25 ;
V_8 -> V_22 = V_16 -> V_26 ;
V_8 -> V_23 = V_16 ;
} else {
V_8 = ( void * ) V_16 ;
}
}
return V_8 ;
}
static void F_7 ( struct V_1 * V_8 )
{
if ( V_8 && V_8 -> V_23 )
F_8 ( V_8 -> V_23 ) ;
}
static int F_9 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 ;
int V_27 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
V_27 = F_10 ( V_8 -> V_21 , & V_7 -> V_28 ,
V_8 -> V_22 ) ;
F_7 ( V_8 ) ;
} else {
V_27 = F_11 ( V_8 ) ;
}
return V_27 ;
}
static struct V_29 * F_12 ( const struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_4 * V_32 )
{
int V_27 = 0 ;
int V_33 ;
int V_34 ;
T_1 V_35 ;
T_1 V_36 ;
T_1 V_37 ;
T_1 V_38 ;
struct V_39 * V_40 = F_13 ( V_31 ) ;
struct V_41 * V_42 = F_14 ( V_40 ) ;
struct V_29 * V_43 ;
V_37 = F_15 ( F_16 ( V_40 ) , V_32 -> V_19 . V_44 ) ;
V_38 = F_15 ( F_16 ( V_40 ) , V_32 -> V_19 . V_45 + 1 ) - 1 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_42 -> V_46 ; V_33 ++ ) {
if ( F_17 ( V_42 -> V_47 [ V_33 ] ) &&
F_18 ( V_40 -> V_48 , V_33 ,
V_37 , V_38 , & V_35 , & V_36 ) )
V_34 ++ ;
}
F_19 ( V_34 > 0 ) ;
V_43 = F_20 ( F_21 ( struct V_29 , V_49 [ V_34 ] ) ,
V_50 ) ;
if ( ! V_43 )
return F_22 ( - V_51 ) ;
V_43 -> V_52 = V_34 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_42 -> V_46 ; ++ V_33 ) {
if ( F_17 ( V_42 -> V_47 [ V_33 ] ) &&
F_18 ( V_40 -> V_48 , V_33 ,
V_37 , V_38 , & V_35 , & V_36 ) ) {
struct V_6 * V_7 = & V_43 -> V_49 [ V_34 ] ;
struct V_53 * V_54 ;
V_54 = & V_7 -> V_28 . V_19 ;
F_19 ( ! V_54 -> V_20 ) ;
V_54 -> V_20 = F_23 ( V_42 -> V_47 [ V_33 ] ) ;
V_54 -> V_44 = F_24 ( V_54 -> V_20 , V_35 ) ;
V_54 -> V_45 = F_24 ( V_54 -> V_20 , V_36 ) ;
V_54 -> V_55 = V_32 -> V_19 . V_55 ;
V_54 -> V_56 = V_32 -> V_19 . V_56 ;
V_54 -> V_57 = V_32 -> V_19 . V_57 ;
V_7 -> V_24 = V_33 ;
V_27 = F_9 ( V_3 , V_32 , V_7 ) ;
if ( V_27 < 0 )
break;
V_7 -> V_58 = 1 ;
V_34 ++ ;
}
}
F_19 ( F_25 ( V_27 == 0 , V_34 == V_43 -> V_52 ) ) ;
if ( V_27 != 0 ) {
for ( V_33 = 0 ; V_33 < V_34 ; ++ V_33 ) {
if ( ! V_43 -> V_49 [ V_33 ] . V_58 )
break;
F_26 ( V_3 , & V_43 -> V_49 [ V_33 ] . V_28 ) ;
}
F_27 ( V_43 ) ;
V_43 = F_22 ( V_27 ) ;
}
return V_43 ;
}
static void F_28 ( const struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_29 * V_43 ;
int V_33 ;
V_43 = F_29 ( V_60 ) ;
for ( V_33 = 0 ; V_33 < V_43 -> V_52 ; ++ V_33 ) {
F_19 ( ! V_43 -> V_49 [ V_33 ] . V_61 ) ;
if ( V_43 -> V_49 [ V_33 ] . V_58 )
F_26 ( V_3 , & V_43 -> V_49 [ V_33 ] . V_28 ) ;
}
F_27 ( V_43 ) ;
}
static int F_30 ( const struct V_2 * V_3 ,
const struct V_59 * V_60 ,
struct V_11 * V_12 , struct V_62 * V_63 )
{
struct V_4 * V_32 = V_60 -> V_64 ;
struct V_29 * V_43 = F_29 ( V_60 ) ;
int V_33 ;
int V_65 = 0 ;
for ( V_33 = 0 ; V_33 < V_43 -> V_52 ; ++ V_33 ) {
struct V_6 * V_7 = & V_43 -> V_49 [ V_33 ] ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_32 , V_7 ) ;
if ( F_6 ( V_8 ) ) {
V_65 = F_11 ( V_8 ) ;
break;
}
V_65 = F_31 ( V_8 -> V_21 , V_8 -> V_22 ,
& V_7 -> V_28 , V_63 ) ;
F_7 ( V_8 ) ;
if ( V_65 != 0 )
break;
V_7 -> V_61 = 1 ;
}
return V_65 ;
}
static void F_32 ( const struct V_2 * V_3 ,
const struct V_59 * V_60 )
{
struct V_4 * V_32 = V_60 -> V_64 ;
struct V_29 * V_43 = F_29 ( V_60 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_43 -> V_52 ; ++ V_33 ) {
struct V_6 * V_7 = & V_43 -> V_49 [ V_33 ] ;
struct V_4 * V_66 = & V_7 -> V_28 ;
struct V_1 * V_8 ;
if ( ! V_7 -> V_61 )
continue;
V_7 -> V_61 = 0 ;
V_8 = F_1 ( V_3 , V_32 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
F_33 ( V_8 -> V_21 , V_66 ) ;
F_7 ( V_8 ) ;
} else {
F_34 ( V_67 , V_3 , V_60 -> V_64 ,
L_1 ,
F_11 ( V_8 ) ) ;
}
}
}
static int F_35 ( const struct V_2 * V_3 , void * V_68 ,
T_2 V_69 , const struct V_59 * V_60 )
{
struct V_29 * V_70 = F_29 ( V_60 ) ;
int V_33 ;
(* V_69)( V_3 , V_68 , L_2 , V_70 -> V_52 ) ;
for ( V_33 = 0 ; V_33 < V_70 -> V_52 ; ++ V_33 ) {
struct V_6 * V_16 ;
V_16 = & V_70 -> V_49 [ V_33 ] ;
(* V_69)( V_3 , V_68 , L_3 , V_33 , V_16 -> V_61 ) ;
F_36 ( V_3 , V_68 , V_69 , & V_16 -> V_28 ) ;
}
return 0 ;
}
int F_37 ( const struct V_2 * V_3 , struct V_30 * V_31 ,
struct V_4 * V_32 , const struct V_11 * V_12 )
{
struct V_29 * V_70 ;
int V_27 = 0 ;
V_70 = F_12 ( V_3 , V_31 , V_32 ) ;
if ( ! F_6 ( V_70 ) )
F_38 ( V_32 , & V_70 -> V_71 , V_31 , & V_72 ) ;
else
V_27 = F_11 ( V_70 ) ;
return V_27 ;
}
static void F_39 ( const struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_29 * V_70 = F_29 ( V_60 ) ;
F_40 ( V_73 , V_70 ) ;
}
static int F_41 ( const struct V_2 * V_3 , void * V_68 ,
T_2 V_69 ,
const struct V_59 * V_60 )
{
(* V_69)( V_3 , V_68 , L_4 ) ;
return 0 ;
}
int F_42 ( const struct V_2 * V_3 , struct V_30 * V_31 ,
struct V_4 * V_32 , const struct V_11 * V_12 )
{
struct V_29 * V_70 ;
int V_27 = - V_51 ;
V_70 = F_43 ( V_73 , V_50 ) ;
if ( V_70 ) {
F_38 ( V_32 , & V_70 -> V_71 , V_31 , & V_74 ) ;
V_27 = 0 ;
}
return V_27 ;
}
