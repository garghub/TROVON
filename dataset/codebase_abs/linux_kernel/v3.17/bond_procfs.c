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
const struct V_13 * V_14 ;
struct V_10 * V_15 ;
int V_16 ;
V_15 = F_8 ( V_6 -> V_17 ) ;
F_9 ( V_2 , L_1 ,
F_10 ( F_11 ( V_6 ) ) ) ;
if ( F_11 ( V_6 ) == V_18 &&
V_6 -> V_19 . V_20 ) {
V_14 = F_12 ( V_21 ,
V_6 -> V_19 . V_20 ) ;
F_9 ( V_2 , L_2 , V_14 -> string ) ;
}
F_9 ( V_2 , L_3 ) ;
if ( F_11 ( V_6 ) == V_22 ||
F_11 ( V_6 ) == V_23 ) {
V_14 = F_12 ( V_24 ,
V_6 -> V_19 . V_25 ) ;
F_9 ( V_2 , L_4 ,
V_14 -> string , V_6 -> V_19 . V_25 ) ;
}
if ( F_13 ( V_6 ) ) {
F_9 ( V_2 , L_5 ,
( V_6 -> V_26 ) ?
V_6 -> V_26 -> V_27 -> V_28 : L_6 ) ;
if ( V_6 -> V_26 ) {
V_14 = F_12 ( V_29 ,
V_6 -> V_19 . V_30 ) ;
F_9 ( V_2 , L_7 ,
V_14 -> string ) ;
}
F_9 ( V_2 , L_8 ,
( V_15 ) ? V_15 -> V_27 -> V_28 : L_6 ) ;
}
F_9 ( V_2 , L_9 , F_14 ( V_6 -> V_27 ) ?
L_10 : L_11 ) ;
F_9 ( V_2 , L_12 , V_6 -> V_19 . V_31 ) ;
F_9 ( V_2 , L_13 ,
V_6 -> V_19 . V_32 * V_6 -> V_19 . V_31 ) ;
F_9 ( V_2 , L_14 ,
V_6 -> V_19 . V_33 * V_6 -> V_19 . V_31 ) ;
if ( V_6 -> V_19 . V_34 > 0 ) {
int V_35 = 0 ;
F_9 ( V_2 , L_15 ,
V_6 -> V_19 . V_34 ) ;
F_9 ( V_2 , L_16 ) ;
for ( V_16 = 0 ; ( V_16 < V_36 ) ; V_16 ++ ) {
if ( ! V_6 -> V_19 . V_37 [ V_16 ] )
break;
if ( V_35 )
F_9 ( V_2 , L_17 ) ;
F_9 ( V_2 , L_18 , & V_6 -> V_19 . V_37 [ V_16 ] ) ;
V_35 = 1 ;
}
F_9 ( V_2 , L_3 ) ;
}
if ( F_11 ( V_6 ) == V_23 ) {
struct V_38 V_38 ;
F_15 ( V_2 , L_19 ) ;
F_9 ( V_2 , L_20 ,
( V_6 -> V_19 . V_39 ) ? L_21 : L_22 ) ;
F_9 ( V_2 , L_23 , V_6 -> V_19 . V_40 ) ;
V_14 = F_12 ( V_41 ,
V_6 -> V_19 . V_42 ) ;
F_9 ( V_2 , L_24 ,
V_14 -> string ) ;
if ( F_16 ( V_6 , & V_38 ) ) {
F_9 ( V_2 , L_25 ,
V_6 -> V_27 -> V_28 ) ;
} else {
F_9 ( V_2 , L_26 ) ;
F_9 ( V_2 , L_27 ,
V_38 . V_43 ) ;
F_9 ( V_2 , L_28 ,
V_38 . V_44 ) ;
F_9 ( V_2 , L_29 ,
V_38 . V_45 ) ;
F_9 ( V_2 , L_30 ,
V_38 . V_46 ) ;
F_9 ( V_2 , L_31 ,
V_38 . V_47 ) ;
}
}
}
static void F_17 ( struct V_1 * V_2 ,
const struct V_10 * V_10 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( V_2 , L_32 , V_10 -> V_27 -> V_28 ) ;
F_9 ( V_2 , L_9 , F_18 ( V_10 -> V_48 ) ) ;
if ( V_10 -> V_49 == V_50 )
F_9 ( V_2 , L_33 , L_34 ) ;
else
F_9 ( V_2 , L_35 , V_10 -> V_49 ) ;
if ( V_10 -> V_51 == V_52 )
F_9 ( V_2 , L_36 , L_34 ) ;
else
F_9 ( V_2 , L_36 , V_10 -> V_51 ? L_37 : L_38 ) ;
F_9 ( V_2 , L_39 ,
V_10 -> V_53 ) ;
F_9 ( V_2 , L_40 , V_10 -> V_54 ) ;
if ( F_11 ( V_6 ) == V_23 ) {
const struct V_55 * V_56
= F_19 ( V_10 ) -> V_57 . V_55 ;
if ( V_56 )
F_9 ( V_2 , L_41 ,
V_56 -> V_58 ) ;
else
F_15 ( V_2 , L_42 ) ;
}
F_9 ( V_2 , L_43 , V_10 -> V_59 ) ;
}
static int F_20 ( struct V_1 * V_2 , void * V_4 )
{
if ( V_4 == V_12 ) {
F_9 ( V_2 , L_44 , V_60 ) ;
F_7 ( V_2 ) ;
} else
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_61 * V_61 , struct V_62 * V_62 )
{
struct V_1 * V_2 ;
int V_63 ;
V_63 = F_22 ( V_62 , & V_64 ) ;
if ( ! V_63 ) {
V_2 = V_62 -> V_65 ;
V_2 -> V_7 = F_23 ( V_61 ) ;
}
return V_63 ;
}
void F_24 ( struct V_5 * V_6 )
{
struct V_66 * V_67 = V_6 -> V_27 ;
struct V_68 * V_69 = F_25 ( F_26 ( V_67 ) , V_70 ) ;
if ( V_69 -> V_71 ) {
V_6 -> V_72 = F_27 ( V_67 -> V_28 ,
V_73 , V_69 -> V_71 ,
& V_74 , V_6 ) ;
if ( V_6 -> V_72 == NULL )
F_28 ( V_67 , L_45 ,
V_75 , V_67 -> V_28 ) ;
else
memcpy ( V_6 -> V_76 , V_67 -> V_28 , V_77 ) ;
}
}
void F_29 ( struct V_5 * V_6 )
{
struct V_66 * V_67 = V_6 -> V_27 ;
struct V_68 * V_69 = F_25 ( F_26 ( V_67 ) , V_70 ) ;
if ( V_69 -> V_71 && V_6 -> V_72 ) {
F_30 ( V_6 -> V_76 , V_69 -> V_71 ) ;
memset ( V_6 -> V_76 , 0 , V_77 ) ;
V_6 -> V_72 = NULL ;
}
}
void T_3 F_31 ( struct V_68 * V_69 )
{
if ( ! V_69 -> V_71 ) {
V_69 -> V_71 = F_32 ( V_75 , V_69 -> V_78 -> V_79 ) ;
if ( ! V_69 -> V_71 )
F_33 ( L_46 ,
V_75 ) ;
}
}
void T_4 F_34 ( struct V_68 * V_69 )
{
if ( V_69 -> V_71 ) {
F_30 ( V_75 , V_69 -> V_78 -> V_79 ) ;
V_69 -> V_71 = NULL ;
}
}
