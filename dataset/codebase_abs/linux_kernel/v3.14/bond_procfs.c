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
struct V_13 * V_14 ;
struct V_10 * V_15 ;
int V_16 ;
F_8 ( & V_6 -> V_17 ) ;
V_15 = V_6 -> V_18 ;
F_9 ( & V_6 -> V_17 ) ;
F_10 ( V_2 , L_1 ,
F_11 ( V_6 -> V_19 . V_20 ) ) ;
if ( V_6 -> V_19 . V_20 == V_21 &&
V_6 -> V_19 . V_22 ) {
V_14 = F_12 ( V_23 ,
V_6 -> V_19 . V_22 ) ;
F_10 ( V_2 , L_2 , V_14 -> string ) ;
}
F_10 ( V_2 , L_3 ) ;
if ( V_6 -> V_19 . V_20 == V_24 ||
V_6 -> V_19 . V_20 == V_25 ) {
V_14 = F_12 ( V_26 ,
V_6 -> V_19 . V_27 ) ;
F_10 ( V_2 , L_4 ,
V_14 -> string , V_6 -> V_19 . V_27 ) ;
}
if ( F_13 ( V_6 -> V_19 . V_20 ) ) {
F_10 ( V_2 , L_5 ,
( V_6 -> V_28 ) ?
V_6 -> V_28 -> V_29 -> V_30 : L_6 ) ;
if ( V_6 -> V_28 ) {
V_14 = F_12 ( V_31 ,
V_6 -> V_19 . V_32 ) ;
F_10 ( V_2 , L_7 ,
V_14 -> string ) ;
}
F_10 ( V_2 , L_8 ,
( V_15 ) ? V_15 -> V_29 -> V_30 : L_6 ) ;
}
F_10 ( V_2 , L_9 , F_14 ( V_6 -> V_29 ) ?
L_10 : L_11 ) ;
F_10 ( V_2 , L_12 , V_6 -> V_19 . V_33 ) ;
F_10 ( V_2 , L_13 ,
V_6 -> V_19 . V_34 * V_6 -> V_19 . V_33 ) ;
F_10 ( V_2 , L_14 ,
V_6 -> V_19 . V_35 * V_6 -> V_19 . V_33 ) ;
if ( V_6 -> V_19 . V_36 > 0 ) {
int V_37 = 0 ;
F_10 ( V_2 , L_15 ,
V_6 -> V_19 . V_36 ) ;
F_10 ( V_2 , L_16 ) ;
for ( V_16 = 0 ; ( V_16 < V_38 ) ; V_16 ++ ) {
if ( ! V_6 -> V_19 . V_39 [ V_16 ] )
break;
if ( V_37 )
F_10 ( V_2 , L_17 ) ;
F_10 ( V_2 , L_18 , & V_6 -> V_19 . V_39 [ V_16 ] ) ;
V_37 = 1 ;
}
F_10 ( V_2 , L_3 ) ;
}
if ( V_6 -> V_19 . V_20 == V_25 ) {
struct V_40 V_40 ;
F_15 ( V_2 , L_19 ) ;
F_10 ( V_2 , L_20 ,
( V_6 -> V_19 . V_41 ) ? L_21 : L_22 ) ;
F_10 ( V_2 , L_23 , V_6 -> V_19 . V_42 ) ;
V_14 = F_12 ( V_43 ,
V_6 -> V_19 . V_44 ) ;
F_10 ( V_2 , L_24 ,
V_14 -> string ) ;
if ( F_16 ( V_6 , & V_40 ) ) {
F_10 ( V_2 , L_25 ,
V_6 -> V_29 -> V_30 ) ;
} else {
F_10 ( V_2 , L_26 ) ;
F_10 ( V_2 , L_27 ,
V_40 . V_45 ) ;
F_10 ( V_2 , L_28 ,
V_40 . V_46 ) ;
F_10 ( V_2 , L_29 ,
V_40 . V_47 ) ;
F_10 ( V_2 , L_30 ,
V_40 . V_48 ) ;
F_10 ( V_2 , L_31 ,
V_40 . V_49 ) ;
}
}
}
static void F_17 ( struct V_1 * V_2 ,
const struct V_10 * V_10 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_10 ( V_2 , L_32 , V_10 -> V_29 -> V_30 ) ;
F_10 ( V_2 , L_9 , F_18 ( V_10 -> V_50 ) ) ;
if ( V_10 -> V_51 == V_52 )
F_10 ( V_2 , L_33 , L_34 ) ;
else
F_10 ( V_2 , L_35 , V_10 -> V_51 ) ;
if ( V_10 -> V_53 == V_54 )
F_10 ( V_2 , L_36 , L_34 ) ;
else
F_10 ( V_2 , L_36 , V_10 -> V_53 ? L_37 : L_38 ) ;
F_10 ( V_2 , L_39 ,
V_10 -> V_55 ) ;
F_10 ( V_2 , L_40 , V_10 -> V_56 ) ;
if ( V_6 -> V_19 . V_20 == V_25 ) {
const struct V_57 * V_58
= F_19 ( V_10 ) . V_59 . V_57 ;
if ( V_58 )
F_10 ( V_2 , L_41 ,
V_58 -> V_60 ) ;
else
F_15 ( V_2 , L_42 ) ;
}
F_10 ( V_2 , L_43 , V_10 -> V_61 ) ;
}
static int F_20 ( struct V_1 * V_2 , void * V_4 )
{
if ( V_4 == V_12 ) {
F_10 ( V_2 , L_44 , V_62 ) ;
F_7 ( V_2 ) ;
} else
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_21 ( struct V_63 * V_63 , struct V_64 * V_64 )
{
struct V_1 * V_2 ;
int V_65 ;
V_65 = F_22 ( V_64 , & V_66 ) ;
if ( ! V_65 ) {
V_2 = V_64 -> V_67 ;
V_2 -> V_7 = F_23 ( V_63 ) ;
}
return V_65 ;
}
void F_24 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = V_6 -> V_29 ;
struct V_70 * V_71 = F_25 ( F_26 ( V_69 ) , V_72 ) ;
if ( V_71 -> V_73 ) {
V_6 -> V_74 = F_27 ( V_69 -> V_30 ,
V_75 , V_71 -> V_73 ,
& V_76 , V_6 ) ;
if ( V_6 -> V_74 == NULL )
F_28 ( L_45 ,
V_77 , V_69 -> V_30 ) ;
else
memcpy ( V_6 -> V_78 , V_69 -> V_30 , V_79 ) ;
}
}
void F_29 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = V_6 -> V_29 ;
struct V_70 * V_71 = F_25 ( F_26 ( V_69 ) , V_72 ) ;
if ( V_71 -> V_73 && V_6 -> V_74 ) {
F_30 ( V_6 -> V_78 , V_71 -> V_73 ) ;
memset ( V_6 -> V_78 , 0 , V_79 ) ;
V_6 -> V_74 = NULL ;
}
}
void T_3 F_31 ( struct V_70 * V_71 )
{
if ( ! V_71 -> V_73 ) {
V_71 -> V_73 = F_32 ( V_77 , V_71 -> V_80 -> V_81 ) ;
if ( ! V_71 -> V_73 )
F_28 ( L_46 ,
V_77 ) ;
}
}
void T_4 F_33 ( struct V_70 * V_71 )
{
if ( V_71 -> V_73 ) {
F_30 ( V_77 , V_71 -> V_80 -> V_81 ) ;
V_71 -> V_73 = NULL ;
}
}
