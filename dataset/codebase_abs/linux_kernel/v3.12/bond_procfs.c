static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
__acquires( &bond->lock
static void * F_2 ( struct V_1 * V_2 , void * V_4 , T_1 * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_4 ;
++ * V_3 ;
if ( V_4 == V_9 )
return F_3 ( V_6 ) ;
if ( F_4 ( V_6 , V_8 ) )
return NULL ;
V_8 = F_5 ( V_6 , V_8 ) ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_2 , void * V_4 )
__releases( &bond->lock
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_10 ;
int V_11 ;
F_8 ( & V_6 -> V_12 ) ;
V_10 = V_6 -> V_13 ;
F_9 ( & V_6 -> V_12 ) ;
F_10 ( V_2 , L_1 ,
F_11 ( V_6 -> V_14 . V_15 ) ) ;
if ( V_6 -> V_14 . V_15 == V_16 &&
V_6 -> V_14 . V_17 )
F_10 ( V_2 , L_2 ,
V_18 [ V_6 -> V_14 . V_17 ] . V_19 ) ;
F_10 ( V_2 , L_3 ) ;
if ( V_6 -> V_14 . V_15 == V_20 ||
V_6 -> V_14 . V_15 == V_21 ) {
F_10 ( V_2 , L_4 ,
V_22 [ V_6 -> V_14 . V_23 ] . V_19 ,
V_6 -> V_14 . V_23 ) ;
}
if ( F_12 ( V_6 -> V_14 . V_15 ) ) {
F_10 ( V_2 , L_5 ,
( V_6 -> V_24 ) ?
V_6 -> V_24 -> V_25 -> V_26 : L_6 ) ;
if ( V_6 -> V_24 )
F_10 ( V_2 , L_7 ,
V_27 [ V_6 -> V_14 . V_28 ] . V_19 ) ;
F_10 ( V_2 , L_8 ,
( V_10 ) ? V_10 -> V_25 -> V_26 : L_6 ) ;
}
F_10 ( V_2 , L_9 , F_13 ( V_6 -> V_25 ) ?
L_10 : L_11 ) ;
F_10 ( V_2 , L_12 , V_6 -> V_14 . V_29 ) ;
F_10 ( V_2 , L_13 ,
V_6 -> V_14 . V_30 * V_6 -> V_14 . V_29 ) ;
F_10 ( V_2 , L_14 ,
V_6 -> V_14 . V_31 * V_6 -> V_14 . V_29 ) ;
if ( V_6 -> V_14 . V_32 > 0 ) {
int V_33 = 0 ;
F_10 ( V_2 , L_15 ,
V_6 -> V_14 . V_32 ) ;
F_10 ( V_2 , L_16 ) ;
for ( V_11 = 0 ; ( V_11 < V_34 ) ; V_11 ++ ) {
if ( ! V_6 -> V_14 . V_35 [ V_11 ] )
break;
if ( V_33 )
F_10 ( V_2 , L_17 ) ;
F_10 ( V_2 , L_18 , & V_6 -> V_14 . V_35 [ V_11 ] ) ;
V_33 = 1 ;
}
F_10 ( V_2 , L_3 ) ;
}
if ( V_6 -> V_14 . V_15 == V_21 ) {
struct V_36 V_36 ;
F_14 ( V_2 , L_19 ) ;
F_10 ( V_2 , L_20 ,
( V_6 -> V_14 . V_37 ) ? L_21 : L_22 ) ;
F_10 ( V_2 , L_23 , V_6 -> V_14 . V_38 ) ;
F_10 ( V_2 , L_24 ,
V_39 [ V_6 -> V_14 . V_40 ] . V_19 ) ;
if ( F_15 ( V_6 , & V_36 ) ) {
F_10 ( V_2 , L_25 ,
V_6 -> V_25 -> V_26 ) ;
} else {
F_10 ( V_2 , L_26 ) ;
F_10 ( V_2 , L_27 ,
V_36 . V_41 ) ;
F_10 ( V_2 , L_28 ,
V_36 . V_42 ) ;
F_10 ( V_2 , L_29 ,
V_36 . V_43 ) ;
F_10 ( V_2 , L_30 ,
V_36 . V_44 ) ;
F_10 ( V_2 , L_31 ,
V_36 . V_45 ) ;
}
}
}
static const char * F_16 ( T_3 V_46 )
{
static const char * const V_47 [] = {
[ V_48 ] = L_10 ,
[ V_49 ] = L_32 ,
[ V_50 ] = L_11 ,
[ V_51 ] = L_33 ,
} ;
return V_47 [ V_46 ] ;
}
static void F_17 ( struct V_1 * V_2 ,
const struct V_8 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_2 , L_34 , V_8 -> V_25 -> V_26 ) ;
F_10 ( V_2 , L_9 , F_16 ( V_8 -> V_46 ) ) ;
if ( V_8 -> V_52 == V_53 )
F_10 ( V_2 , L_35 , L_36 ) ;
else
F_10 ( V_2 , L_37 , V_8 -> V_52 ) ;
if ( V_8 -> V_54 == V_55 )
F_10 ( V_2 , L_38 , L_36 ) ;
else
F_10 ( V_2 , L_38 , V_8 -> V_54 ? L_39 : L_40 ) ;
F_10 ( V_2 , L_41 ,
V_8 -> V_56 ) ;
F_10 ( V_2 , L_42 , V_8 -> V_57 ) ;
if ( V_6 -> V_14 . V_15 == V_21 ) {
const struct V_58 * V_59
= F_18 ( V_8 ) . V_60 . V_58 ;
if ( V_59 )
F_10 ( V_2 , L_43 ,
V_59 -> V_61 ) ;
else
F_14 ( V_2 , L_44 ) ;
}
F_10 ( V_2 , L_45 , V_8 -> V_62 ) ;
}
static int F_19 ( struct V_1 * V_2 , void * V_4 )
{
if ( V_4 == V_9 ) {
F_10 ( V_2 , L_46 , V_63 ) ;
F_7 ( V_2 ) ;
} else
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
struct V_1 * V_2 ;
int V_66 ;
V_66 = F_21 ( V_65 , & V_67 ) ;
if ( ! V_66 ) {
V_2 = V_65 -> V_68 ;
V_2 -> V_7 = F_22 ( V_64 ) ;
}
return V_66 ;
}
void F_23 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = V_6 -> V_25 ;
struct V_71 * V_72 = F_24 ( F_25 ( V_70 ) , V_73 ) ;
if ( V_72 -> V_74 ) {
V_6 -> V_75 = F_26 ( V_70 -> V_26 ,
V_76 , V_72 -> V_74 ,
& V_77 , V_6 ) ;
if ( V_6 -> V_75 == NULL )
F_27 ( L_47 ,
V_78 , V_70 -> V_26 ) ;
else
memcpy ( V_6 -> V_79 , V_70 -> V_26 , V_80 ) ;
}
}
void F_28 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = V_6 -> V_25 ;
struct V_71 * V_72 = F_24 ( F_25 ( V_70 ) , V_73 ) ;
if ( V_72 -> V_74 && V_6 -> V_75 ) {
F_29 ( V_6 -> V_79 , V_72 -> V_74 ) ;
memset ( V_6 -> V_79 , 0 , V_80 ) ;
V_6 -> V_75 = NULL ;
}
}
void T_4 F_30 ( struct V_71 * V_72 )
{
if ( ! V_72 -> V_74 ) {
V_72 -> V_74 = F_31 ( V_78 , V_72 -> V_81 -> V_82 ) ;
if ( ! V_72 -> V_74 )
F_27 ( L_48 ,
V_78 ) ;
}
}
void T_5 F_32 ( struct V_71 * V_72 )
{
if ( V_72 -> V_74 ) {
F_29 ( V_78 , V_72 -> V_81 -> V_82 ) ;
V_72 -> V_74 = NULL ;
}
}
