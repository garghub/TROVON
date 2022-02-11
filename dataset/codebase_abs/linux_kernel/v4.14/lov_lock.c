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
} else {
V_16 = F_5 ( V_3 , V_10 , V_7 -> V_23 ) ;
if ( ! F_6 ( V_16 ) ) {
V_8 -> V_21 = V_16 -> V_24 ;
V_8 -> V_22 = V_16 -> V_25 ;
} else {
V_8 = ( void * ) V_16 ;
}
}
return V_8 ;
}
static int F_7 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 ;
int V_26 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
V_26 = F_8 ( V_8 -> V_21 , & V_7 -> V_27 ,
V_8 -> V_22 ) ;
} else {
V_26 = F_9 ( V_8 ) ;
}
return V_26 ;
}
static struct V_28 * F_10 ( const struct V_2 * V_3 ,
const struct V_29 * V_30 ,
struct V_4 * V_31 )
{
int V_26 = 0 ;
int V_32 ;
int V_33 ;
T_1 V_34 ;
T_1 V_35 ;
T_1 V_36 ;
T_1 V_37 ;
struct V_38 * V_39 = F_11 ( V_30 ) ;
struct V_40 * V_41 = F_12 ( V_39 ) ;
struct V_28 * V_42 ;
F_13 ( V_43 , L_1 V_44 L_2 V_44 L_3 ,
V_39 , F_14 ( F_15 ( F_16 ( V_39 ) ) ) ,
F_14 ( F_15 ( & V_30 -> V_45 ) ) ,
F_17 ( V_39 ) , V_30 ) ;
V_36 = F_18 ( F_17 ( V_39 ) , V_31 -> V_19 . V_46 ) ;
V_37 = F_18 ( F_17 ( V_39 ) , V_31 -> V_19 . V_47 + 1 ) - 1 ;
for ( V_32 = 0 , V_33 = 0 ; V_32 < V_41 -> V_48 ; V_32 ++ ) {
if ( F_19 ( V_41 -> V_49 [ V_32 ] ) &&
F_20 ( V_39 -> V_50 , V_32 ,
V_36 , V_37 , & V_34 , & V_35 ) )
V_33 ++ ;
}
F_21 ( V_33 > 0 ) ;
V_42 = F_22 ( F_23 ( struct V_28 , V_51 [ V_33 ] ) ,
V_52 ) ;
if ( ! V_42 )
return F_24 ( - V_53 ) ;
V_42 -> V_54 = V_33 ;
for ( V_32 = 0 , V_33 = 0 ; V_32 < V_41 -> V_48 ; ++ V_32 ) {
if ( F_19 ( V_41 -> V_49 [ V_32 ] ) &&
F_20 ( V_39 -> V_50 , V_32 ,
V_36 , V_37 , & V_34 , & V_35 ) ) {
struct V_6 * V_7 = & V_42 -> V_51 [ V_33 ] ;
struct V_55 * V_56 ;
V_56 = & V_7 -> V_27 . V_19 ;
F_21 ( ! V_56 -> V_20 ) ;
V_56 -> V_20 = F_25 ( V_41 -> V_49 [ V_32 ] ) ;
V_56 -> V_46 = F_26 ( V_56 -> V_20 , V_34 ) ;
V_56 -> V_47 = F_26 ( V_56 -> V_20 , V_35 ) ;
V_56 -> V_57 = V_31 -> V_19 . V_57 ;
V_56 -> V_58 = V_31 -> V_19 . V_58 ;
V_56 -> V_59 = V_31 -> V_19 . V_59 ;
V_7 -> V_23 = V_32 ;
V_26 = F_7 ( V_3 , V_31 , V_7 ) ;
if ( V_26 < 0 )
break;
V_7 -> V_60 = 1 ;
V_33 ++ ;
}
}
F_21 ( F_27 ( V_26 == 0 , V_33 == V_42 -> V_54 ) ) ;
if ( V_26 != 0 ) {
for ( V_32 = 0 ; V_32 < V_33 ; ++ V_32 ) {
if ( ! V_42 -> V_51 [ V_32 ] . V_60 )
break;
F_28 ( V_3 , & V_42 -> V_51 [ V_32 ] . V_27 ) ;
}
F_29 ( V_42 ) ;
V_42 = F_24 ( V_26 ) ;
}
return V_42 ;
}
static void F_30 ( const struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_28 * V_42 ;
int V_32 ;
V_42 = F_31 ( V_62 ) ;
for ( V_32 = 0 ; V_32 < V_42 -> V_54 ; ++ V_32 ) {
F_21 ( ! V_42 -> V_51 [ V_32 ] . V_63 ) ;
if ( V_42 -> V_51 [ V_32 ] . V_60 )
F_28 ( V_3 , & V_42 -> V_51 [ V_32 ] . V_27 ) ;
}
F_29 ( V_42 ) ;
}
static int F_32 ( const struct V_2 * V_3 ,
const struct V_61 * V_62 ,
struct V_11 * V_12 , struct V_64 * V_65 )
{
struct V_4 * V_31 = V_62 -> V_66 ;
struct V_28 * V_42 = F_31 ( V_62 ) ;
int V_32 ;
int V_67 = 0 ;
for ( V_32 = 0 ; V_32 < V_42 -> V_54 ; ++ V_32 ) {
struct V_6 * V_7 = & V_42 -> V_51 [ V_32 ] ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_31 , V_7 ) ;
if ( F_6 ( V_8 ) ) {
V_67 = F_9 ( V_8 ) ;
break;
}
V_67 = F_33 ( V_8 -> V_21 , V_8 -> V_22 ,
& V_7 -> V_27 , V_65 ) ;
if ( V_67 != 0 )
break;
V_7 -> V_63 = 1 ;
}
return V_67 ;
}
static void F_34 ( const struct V_2 * V_3 ,
const struct V_61 * V_62 )
{
struct V_4 * V_31 = V_62 -> V_66 ;
struct V_28 * V_42 = F_31 ( V_62 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_42 -> V_54 ; ++ V_32 ) {
struct V_6 * V_7 = & V_42 -> V_51 [ V_32 ] ;
struct V_4 * V_68 = & V_7 -> V_27 ;
struct V_1 * V_8 ;
if ( ! V_7 -> V_63 )
continue;
V_7 -> V_63 = 0 ;
V_8 = F_1 ( V_3 , V_31 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
F_35 ( V_8 -> V_21 , V_68 ) ;
} else {
F_36 ( V_69 , V_3 , V_62 -> V_66 ,
L_4 ,
V_70 , F_9 ( V_8 ) ) ;
}
}
}
static int F_37 ( const struct V_2 * V_3 , void * V_71 ,
T_2 V_72 , const struct V_61 * V_62 )
{
struct V_28 * V_73 = F_31 ( V_62 ) ;
int V_32 ;
(* V_72)( V_3 , V_71 , L_5 , V_73 -> V_54 ) ;
for ( V_32 = 0 ; V_32 < V_73 -> V_54 ; ++ V_32 ) {
struct V_6 * V_16 ;
V_16 = & V_73 -> V_51 [ V_32 ] ;
(* V_72)( V_3 , V_71 , L_6 , V_32 , V_16 -> V_63 ) ;
F_38 ( V_3 , V_71 , V_72 , & V_16 -> V_27 ) ;
}
return 0 ;
}
int F_39 ( const struct V_2 * V_3 , struct V_29 * V_30 ,
struct V_4 * V_31 , const struct V_11 * V_12 )
{
struct V_28 * V_73 ;
int V_26 = 0 ;
V_73 = F_10 ( V_3 , V_30 , V_31 ) ;
if ( ! F_6 ( V_73 ) )
F_40 ( V_31 , & V_73 -> V_74 , V_30 , & V_75 ) ;
else
V_26 = F_9 ( V_73 ) ;
return V_26 ;
}
static void F_41 ( const struct V_2 * V_3 ,
struct V_61 * V_62 )
{
struct V_28 * V_73 = F_31 ( V_62 ) ;
F_42 ( V_76 , V_73 ) ;
}
static int F_43 ( const struct V_2 * V_3 , void * V_71 ,
T_2 V_72 ,
const struct V_61 * V_62 )
{
(* V_72)( V_3 , V_71 , L_7 ) ;
return 0 ;
}
int F_44 ( const struct V_2 * V_3 , struct V_29 * V_30 ,
struct V_4 * V_31 , const struct V_11 * V_12 )
{
struct V_28 * V_73 ;
int V_26 = - V_53 ;
V_73 = F_45 ( V_76 , V_52 ) ;
if ( V_73 ) {
F_40 ( V_31 , & V_73 -> V_74 , V_30 , & V_77 ) ;
V_26 = 0 ;
}
return V_26 ;
}
