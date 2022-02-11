static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
__acquires( &bond->lock
static void * F_2 ( struct V_1 * V_2 , void * V_4 , T_1 * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_10 ;
bool V_11 = false ;
++ * V_3 ;
if ( V_4 == V_12 )
return F_3 ( V_6 ) ;
if ( F_4 ( V_6 , V_4 ) )
return NULL ;
F_5 (bond, slave, iter) {
if ( V_11 )
return V_10 ;
if ( V_10 == V_4 )
V_11 = true ;
}
return NULL ;
}
static void F_6 ( struct V_1 * V_2 , void * V_4 )
__releases( &bond->lock
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_13 ;
int V_14 ;
F_8 ( & V_6 -> V_15 ) ;
V_13 = V_6 -> V_16 ;
F_9 ( & V_6 -> V_15 ) ;
F_10 ( V_2 , L_1 ,
F_11 ( V_6 -> V_17 . V_18 ) ) ;
if ( V_6 -> V_17 . V_18 == V_19 &&
V_6 -> V_17 . V_20 )
F_10 ( V_2 , L_2 ,
V_21 [ V_6 -> V_17 . V_20 ] . V_22 ) ;
F_10 ( V_2 , L_3 ) ;
if ( V_6 -> V_17 . V_18 == V_23 ||
V_6 -> V_17 . V_18 == V_24 ) {
F_10 ( V_2 , L_4 ,
V_25 [ V_6 -> V_17 . V_26 ] . V_22 ,
V_6 -> V_17 . V_26 ) ;
}
if ( F_12 ( V_6 -> V_17 . V_18 ) ) {
F_10 ( V_2 , L_5 ,
( V_6 -> V_27 ) ?
V_6 -> V_27 -> V_28 -> V_29 : L_6 ) ;
if ( V_6 -> V_27 )
F_10 ( V_2 , L_7 ,
V_30 [ V_6 -> V_17 . V_31 ] . V_22 ) ;
F_10 ( V_2 , L_8 ,
( V_13 ) ? V_13 -> V_28 -> V_29 : L_6 ) ;
}
F_10 ( V_2 , L_9 , F_13 ( V_6 -> V_28 ) ?
L_10 : L_11 ) ;
F_10 ( V_2 , L_12 , V_6 -> V_17 . V_32 ) ;
F_10 ( V_2 , L_13 ,
V_6 -> V_17 . V_33 * V_6 -> V_17 . V_32 ) ;
F_10 ( V_2 , L_14 ,
V_6 -> V_17 . V_34 * V_6 -> V_17 . V_32 ) ;
if ( V_6 -> V_17 . V_35 > 0 ) {
int V_36 = 0 ;
F_10 ( V_2 , L_15 ,
V_6 -> V_17 . V_35 ) ;
F_10 ( V_2 , L_16 ) ;
for ( V_14 = 0 ; ( V_14 < V_37 ) ; V_14 ++ ) {
if ( ! V_6 -> V_17 . V_38 [ V_14 ] )
break;
if ( V_36 )
F_10 ( V_2 , L_17 ) ;
F_10 ( V_2 , L_18 , & V_6 -> V_17 . V_38 [ V_14 ] ) ;
V_36 = 1 ;
}
F_10 ( V_2 , L_3 ) ;
}
if ( V_6 -> V_17 . V_18 == V_24 ) {
struct V_39 V_39 ;
F_14 ( V_2 , L_19 ) ;
F_10 ( V_2 , L_20 ,
( V_6 -> V_17 . V_40 ) ? L_21 : L_22 ) ;
F_10 ( V_2 , L_23 , V_6 -> V_17 . V_41 ) ;
F_10 ( V_2 , L_24 ,
V_42 [ V_6 -> V_17 . V_43 ] . V_22 ) ;
if ( F_15 ( V_6 , & V_39 ) ) {
F_10 ( V_2 , L_25 ,
V_6 -> V_28 -> V_29 ) ;
} else {
F_10 ( V_2 , L_26 ) ;
F_10 ( V_2 , L_27 ,
V_39 . V_44 ) ;
F_10 ( V_2 , L_28 ,
V_39 . V_45 ) ;
F_10 ( V_2 , L_29 ,
V_39 . V_46 ) ;
F_10 ( V_2 , L_30 ,
V_39 . V_47 ) ;
F_10 ( V_2 , L_31 ,
V_39 . V_48 ) ;
}
}
}
static const char * F_16 ( T_3 V_49 )
{
static const char * const V_50 [] = {
[ V_51 ] = L_10 ,
[ V_52 ] = L_32 ,
[ V_53 ] = L_11 ,
[ V_54 ] = L_33 ,
} ;
return V_50 [ V_49 ] ;
}
static void F_17 ( struct V_1 * V_2 ,
const struct V_10 * V_10 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_2 , L_34 , V_10 -> V_28 -> V_29 ) ;
F_10 ( V_2 , L_9 , F_16 ( V_10 -> V_49 ) ) ;
if ( V_10 -> V_55 == V_56 )
F_10 ( V_2 , L_35 , L_36 ) ;
else
F_10 ( V_2 , L_37 , V_10 -> V_55 ) ;
if ( V_10 -> V_57 == V_58 )
F_10 ( V_2 , L_38 , L_36 ) ;
else
F_10 ( V_2 , L_38 , V_10 -> V_57 ? L_39 : L_40 ) ;
F_10 ( V_2 , L_41 ,
V_10 -> V_59 ) ;
F_10 ( V_2 , L_42 , V_10 -> V_60 ) ;
if ( V_6 -> V_17 . V_18 == V_24 ) {
const struct V_61 * V_62
= F_18 ( V_10 ) . V_63 . V_61 ;
if ( V_62 )
F_10 ( V_2 , L_43 ,
V_62 -> V_64 ) ;
else
F_14 ( V_2 , L_44 ) ;
}
F_10 ( V_2 , L_45 , V_10 -> V_65 ) ;
}
static int F_19 ( struct V_1 * V_2 , void * V_4 )
{
if ( V_4 == V_12 ) {
F_10 ( V_2 , L_46 , V_66 ) ;
F_7 ( V_2 ) ;
} else
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
struct V_1 * V_2 ;
int V_69 ;
V_69 = F_21 ( V_68 , & V_70 ) ;
if ( ! V_69 ) {
V_2 = V_68 -> V_71 ;
V_2 -> V_7 = F_22 ( V_67 ) ;
}
return V_69 ;
}
void F_23 ( struct V_5 * V_6 )
{
struct V_72 * V_73 = V_6 -> V_28 ;
struct V_74 * V_75 = F_24 ( F_25 ( V_73 ) , V_76 ) ;
if ( V_75 -> V_77 ) {
V_6 -> V_78 = F_26 ( V_73 -> V_29 ,
V_79 , V_75 -> V_77 ,
& V_80 , V_6 ) ;
if ( V_6 -> V_78 == NULL )
F_27 ( L_47 ,
V_81 , V_73 -> V_29 ) ;
else
memcpy ( V_6 -> V_82 , V_73 -> V_29 , V_83 ) ;
}
}
void F_28 ( struct V_5 * V_6 )
{
struct V_72 * V_73 = V_6 -> V_28 ;
struct V_74 * V_75 = F_24 ( F_25 ( V_73 ) , V_76 ) ;
if ( V_75 -> V_77 && V_6 -> V_78 ) {
F_29 ( V_6 -> V_82 , V_75 -> V_77 ) ;
memset ( V_6 -> V_82 , 0 , V_83 ) ;
V_6 -> V_78 = NULL ;
}
}
void T_4 F_30 ( struct V_74 * V_75 )
{
if ( ! V_75 -> V_77 ) {
V_75 -> V_77 = F_31 ( V_81 , V_75 -> V_84 -> V_85 ) ;
if ( ! V_75 -> V_77 )
F_27 ( L_48 ,
V_81 ) ;
}
}
void T_5 F_32 ( struct V_74 * V_75 )
{
if ( V_75 -> V_77 ) {
F_29 ( V_81 , V_75 -> V_84 -> V_85 ) ;
V_75 -> V_77 = NULL ;
}
}
