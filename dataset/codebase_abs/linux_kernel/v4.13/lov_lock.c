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
F_15 ( V_44 , L_1 V_45 L_2 V_45 L_3 ,
V_40 , F_16 ( F_17 ( F_18 ( V_40 ) ) ) ,
F_16 ( F_17 ( & V_31 -> V_46 ) ) ,
F_19 ( V_40 ) , V_31 ) ;
V_37 = F_20 ( F_19 ( V_40 ) , V_32 -> V_19 . V_47 ) ;
V_38 = F_20 ( F_19 ( V_40 ) , V_32 -> V_19 . V_48 + 1 ) - 1 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_42 -> V_49 ; V_33 ++ ) {
if ( F_21 ( V_42 -> V_50 [ V_33 ] ) &&
F_22 ( V_40 -> V_51 , V_33 ,
V_37 , V_38 , & V_35 , & V_36 ) )
V_34 ++ ;
}
F_23 ( V_34 > 0 ) ;
V_43 = F_24 ( F_25 ( struct V_29 , V_52 [ V_34 ] ) ,
V_53 ) ;
if ( ! V_43 )
return F_26 ( - V_54 ) ;
V_43 -> V_55 = V_34 ;
for ( V_33 = 0 , V_34 = 0 ; V_33 < V_42 -> V_49 ; ++ V_33 ) {
if ( F_21 ( V_42 -> V_50 [ V_33 ] ) &&
F_22 ( V_40 -> V_51 , V_33 ,
V_37 , V_38 , & V_35 , & V_36 ) ) {
struct V_6 * V_7 = & V_43 -> V_52 [ V_34 ] ;
struct V_56 * V_57 ;
V_57 = & V_7 -> V_28 . V_19 ;
F_23 ( ! V_57 -> V_20 ) ;
V_57 -> V_20 = F_27 ( V_42 -> V_50 [ V_33 ] ) ;
V_57 -> V_47 = F_28 ( V_57 -> V_20 , V_35 ) ;
V_57 -> V_48 = F_28 ( V_57 -> V_20 , V_36 ) ;
V_57 -> V_58 = V_32 -> V_19 . V_58 ;
V_57 -> V_59 = V_32 -> V_19 . V_59 ;
V_57 -> V_60 = V_32 -> V_19 . V_60 ;
V_7 -> V_24 = V_33 ;
V_27 = F_9 ( V_3 , V_32 , V_7 ) ;
if ( V_27 < 0 )
break;
V_7 -> V_61 = 1 ;
V_34 ++ ;
}
}
F_23 ( F_29 ( V_27 == 0 , V_34 == V_43 -> V_55 ) ) ;
if ( V_27 != 0 ) {
for ( V_33 = 0 ; V_33 < V_34 ; ++ V_33 ) {
if ( ! V_43 -> V_52 [ V_33 ] . V_61 )
break;
F_30 ( V_3 , & V_43 -> V_52 [ V_33 ] . V_28 ) ;
}
F_31 ( V_43 ) ;
V_43 = F_26 ( V_27 ) ;
}
return V_43 ;
}
static void F_32 ( const struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_29 * V_43 ;
int V_33 ;
V_43 = F_33 ( V_63 ) ;
for ( V_33 = 0 ; V_33 < V_43 -> V_55 ; ++ V_33 ) {
F_23 ( ! V_43 -> V_52 [ V_33 ] . V_64 ) ;
if ( V_43 -> V_52 [ V_33 ] . V_61 )
F_30 ( V_3 , & V_43 -> V_52 [ V_33 ] . V_28 ) ;
}
F_31 ( V_43 ) ;
}
static int F_34 ( const struct V_2 * V_3 ,
const struct V_62 * V_63 ,
struct V_11 * V_12 , struct V_65 * V_66 )
{
struct V_4 * V_32 = V_63 -> V_67 ;
struct V_29 * V_43 = F_33 ( V_63 ) ;
int V_33 ;
int V_68 = 0 ;
for ( V_33 = 0 ; V_33 < V_43 -> V_55 ; ++ V_33 ) {
struct V_6 * V_7 = & V_43 -> V_52 [ V_33 ] ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_32 , V_7 ) ;
if ( F_6 ( V_8 ) ) {
V_68 = F_11 ( V_8 ) ;
break;
}
V_68 = F_35 ( V_8 -> V_21 , V_8 -> V_22 ,
& V_7 -> V_28 , V_66 ) ;
F_7 ( V_8 ) ;
if ( V_68 != 0 )
break;
V_7 -> V_64 = 1 ;
}
return V_68 ;
}
static void F_36 ( const struct V_2 * V_3 ,
const struct V_62 * V_63 )
{
struct V_4 * V_32 = V_63 -> V_67 ;
struct V_29 * V_43 = F_33 ( V_63 ) ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_43 -> V_55 ; ++ V_33 ) {
struct V_6 * V_7 = & V_43 -> V_52 [ V_33 ] ;
struct V_4 * V_69 = & V_7 -> V_28 ;
struct V_1 * V_8 ;
if ( ! V_7 -> V_64 )
continue;
V_7 -> V_64 = 0 ;
V_8 = F_1 ( V_3 , V_32 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
F_37 ( V_8 -> V_21 , V_69 ) ;
F_7 ( V_8 ) ;
} else {
F_38 ( V_70 , V_3 , V_63 -> V_67 ,
L_4 ,
F_11 ( V_8 ) ) ;
}
}
}
static int F_39 ( const struct V_2 * V_3 , void * V_71 ,
T_2 V_72 , const struct V_62 * V_63 )
{
struct V_29 * V_73 = F_33 ( V_63 ) ;
int V_33 ;
(* V_72)( V_3 , V_71 , L_5 , V_73 -> V_55 ) ;
for ( V_33 = 0 ; V_33 < V_73 -> V_55 ; ++ V_33 ) {
struct V_6 * V_16 ;
V_16 = & V_73 -> V_52 [ V_33 ] ;
(* V_72)( V_3 , V_71 , L_6 , V_33 , V_16 -> V_64 ) ;
F_40 ( V_3 , V_71 , V_72 , & V_16 -> V_28 ) ;
}
return 0 ;
}
int F_41 ( const struct V_2 * V_3 , struct V_30 * V_31 ,
struct V_4 * V_32 , const struct V_11 * V_12 )
{
struct V_29 * V_73 ;
int V_27 = 0 ;
V_73 = F_12 ( V_3 , V_31 , V_32 ) ;
if ( ! F_6 ( V_73 ) )
F_42 ( V_32 , & V_73 -> V_74 , V_31 , & V_75 ) ;
else
V_27 = F_11 ( V_73 ) ;
return V_27 ;
}
static void F_43 ( const struct V_2 * V_3 ,
struct V_62 * V_63 )
{
struct V_29 * V_73 = F_33 ( V_63 ) ;
F_44 ( V_76 , V_73 ) ;
}
static int F_45 ( const struct V_2 * V_3 , void * V_71 ,
T_2 V_72 ,
const struct V_62 * V_63 )
{
(* V_72)( V_3 , V_71 , L_7 ) ;
return 0 ;
}
int F_46 ( const struct V_2 * V_3 , struct V_30 * V_31 ,
struct V_4 * V_32 , const struct V_11 * V_12 )
{
struct V_29 * V_73 ;
int V_27 = - V_54 ;
V_73 = F_47 ( V_76 , V_53 ) ;
if ( V_73 ) {
F_42 ( V_32 , & V_73 -> V_74 , V_31 , & V_77 ) ;
V_27 = 0 ;
}
return V_27 ;
}
