static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
T_1 V_10 = 0 ;
F_2 () ;
if ( * V_3 == 0 )
return V_11 ;
F_3 (bond, slave, iter)
if ( ++ V_10 == * V_3 )
return V_9 ;
return NULL ;
}
static void * F_4 ( struct V_1 * V_2 , void * V_12 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
bool V_13 = false ;
++ * V_3 ;
if ( V_12 == V_11 )
return F_5 ( V_5 ) ;
F_3 (bond, slave, iter) {
if ( V_13 )
return V_9 ;
if ( V_9 == V_12 )
V_13 = true ;
}
return NULL ;
}
static void F_6 ( struct V_1 * V_2 , void * V_12 )
__releases( T_2 )
{
F_7 () ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
const struct V_14 * V_15 ;
struct V_9 * V_16 , * V_17 ;
int V_18 ;
V_16 = F_9 ( V_5 -> V_19 ) ;
F_10 ( V_2 , L_1 ,
F_11 ( F_12 ( V_5 ) ) ) ;
if ( F_12 ( V_5 ) == V_20 &&
V_5 -> V_21 . V_22 ) {
V_15 = F_13 ( V_23 ,
V_5 -> V_21 . V_22 ) ;
F_10 ( V_2 , L_2 , V_15 -> string ) ;
}
F_10 ( V_2 , L_3 ) ;
if ( F_14 ( V_5 ) ) {
V_15 = F_13 ( V_24 ,
V_5 -> V_21 . V_25 ) ;
F_10 ( V_2 , L_4 ,
V_15 -> string , V_5 -> V_21 . V_25 ) ;
}
if ( F_15 ( V_5 ) ) {
V_17 = F_9 ( V_5 -> V_26 ) ;
F_10 ( V_2 , L_5 ,
V_17 ? V_17 -> V_27 -> V_28 : L_6 ) ;
if ( V_17 ) {
V_15 = F_13 ( V_29 ,
V_5 -> V_21 . V_30 ) ;
F_10 ( V_2 , L_7 ,
V_15 -> string ) ;
}
F_10 ( V_2 , L_8 ,
( V_16 ) ? V_16 -> V_27 -> V_28 : L_6 ) ;
}
F_10 ( V_2 , L_9 , F_16 ( V_5 -> V_27 ) ?
L_10 : L_11 ) ;
F_10 ( V_2 , L_12 , V_5 -> V_21 . V_31 ) ;
F_10 ( V_2 , L_13 ,
V_5 -> V_21 . V_32 * V_5 -> V_21 . V_31 ) ;
F_10 ( V_2 , L_14 ,
V_5 -> V_21 . V_33 * V_5 -> V_21 . V_31 ) ;
if ( V_5 -> V_21 . V_34 > 0 ) {
int V_35 = 0 ;
F_10 ( V_2 , L_15 ,
V_5 -> V_21 . V_34 ) ;
F_10 ( V_2 , L_16 ) ;
for ( V_18 = 0 ; ( V_18 < V_36 ) ; V_18 ++ ) {
if ( ! V_5 -> V_21 . V_37 [ V_18 ] )
break;
if ( V_35 )
F_10 ( V_2 , L_17 ) ;
F_10 ( V_2 , L_18 , & V_5 -> V_21 . V_37 [ V_18 ] ) ;
V_35 = 1 ;
}
F_10 ( V_2 , L_3 ) ;
}
if ( F_12 ( V_5 ) == V_38 ) {
struct V_39 V_39 ;
F_17 ( V_2 , L_19 ) ;
F_10 ( V_2 , L_20 ,
( V_5 -> V_21 . V_40 ) ? L_21 : L_22 ) ;
F_10 ( V_2 , L_23 , V_5 -> V_21 . V_41 ) ;
V_15 = F_13 ( V_42 ,
V_5 -> V_21 . V_43 ) ;
F_10 ( V_2 , L_24 ,
V_15 -> string ) ;
if ( F_18 ( V_5 , & V_39 ) ) {
F_10 ( V_2 , L_25 ,
V_5 -> V_27 -> V_28 ) ;
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
static void F_19 ( struct V_1 * V_2 ,
const struct V_9 * V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_10 ( V_2 , L_32 , V_9 -> V_27 -> V_28 ) ;
F_10 ( V_2 , L_9 , F_20 ( V_9 -> V_49 ) ) ;
if ( V_9 -> V_50 == V_51 )
F_10 ( V_2 , L_33 , L_34 ) ;
else
F_10 ( V_2 , L_35 , V_9 -> V_50 ) ;
if ( V_9 -> V_52 == V_53 )
F_10 ( V_2 , L_36 , L_34 ) ;
else
F_10 ( V_2 , L_36 , V_9 -> V_52 ? L_37 : L_38 ) ;
F_10 ( V_2 , L_39 ,
V_9 -> V_54 ) ;
F_10 ( V_2 , L_40 , V_9 -> V_55 ) ;
F_10 ( V_2 , L_41 , V_9 -> V_56 ) ;
if ( F_12 ( V_5 ) == V_38 ) {
const struct V_57 * V_57 = & F_21 ( V_9 ) -> V_57 ;
const struct V_58 * V_59 = V_57 -> V_58 ;
if ( V_59 ) {
F_10 ( V_2 , L_42 ,
V_59 -> V_60 ) ;
F_10 ( V_2 , L_43 ,
F_22 ( V_57 -> V_61 ) ) ;
F_10 ( V_2 , L_44 ,
F_22 ( V_57 -> V_62 ) ) ;
F_10 ( V_2 , L_45 ,
V_57 -> V_63 ) ;
F_10 ( V_2 , L_46 ,
V_57 -> V_64 ) ;
F_17 ( V_2 , L_47 ) ;
F_10 ( V_2 , L_48 ,
V_57 -> V_65 ) ;
F_10 ( V_2 , L_49 ,
V_57 -> V_66 ) ;
F_10 ( V_2 , L_50 ,
V_57 -> V_67 ) ;
F_10 ( V_2 , L_51 ,
V_57 -> V_68 ) ;
F_10 ( V_2 , L_52 ,
V_57 -> V_69 ) ;
F_17 ( V_2 , L_53 ) ;
F_10 ( V_2 , L_48 ,
V_57 -> V_70 . V_71 ) ;
F_10 ( V_2 , L_54 ,
V_57 -> V_70 . V_72 ) ;
F_10 ( V_2 , L_50 ,
V_57 -> V_70 . V_73 ) ;
F_10 ( V_2 , L_51 ,
V_57 -> V_70 . V_74 ) ;
F_10 ( V_2 , L_52 ,
V_57 -> V_70 . V_75 ) ;
} else {
F_17 ( V_2 , L_55 ) ;
}
}
}
static int F_23 ( struct V_1 * V_2 , void * V_12 )
{
if ( V_12 == V_11 ) {
F_10 ( V_2 , L_56 , V_76 ) ;
F_8 ( V_2 ) ;
} else
F_19 ( V_2 , V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_77 * V_77 , struct V_78 * V_78 )
{
struct V_1 * V_2 ;
int V_79 ;
V_79 = F_25 ( V_78 , & V_80 ) ;
if ( ! V_79 ) {
V_2 = V_78 -> V_81 ;
V_2 -> V_6 = F_26 ( V_77 ) ;
}
return V_79 ;
}
void F_27 ( struct V_4 * V_5 )
{
struct V_82 * V_83 = V_5 -> V_27 ;
struct V_84 * V_85 = F_28 ( F_29 ( V_83 ) , V_86 ) ;
if ( V_85 -> V_87 ) {
V_5 -> V_88 = F_30 ( V_83 -> V_28 ,
V_89 , V_85 -> V_87 ,
& V_90 , V_5 ) ;
if ( V_5 -> V_88 == NULL )
F_31 ( V_83 , L_57 ,
V_91 , V_83 -> V_28 ) ;
else
memcpy ( V_5 -> V_92 , V_83 -> V_28 , V_93 ) ;
}
}
void F_32 ( struct V_4 * V_5 )
{
struct V_82 * V_83 = V_5 -> V_27 ;
struct V_84 * V_85 = F_28 ( F_29 ( V_83 ) , V_86 ) ;
if ( V_85 -> V_87 && V_5 -> V_88 ) {
F_33 ( V_5 -> V_92 , V_85 -> V_87 ) ;
memset ( V_5 -> V_92 , 0 , V_93 ) ;
V_5 -> V_88 = NULL ;
}
}
void T_3 F_34 ( struct V_84 * V_85 )
{
if ( ! V_85 -> V_87 ) {
V_85 -> V_87 = F_35 ( V_91 , V_85 -> V_94 -> V_95 ) ;
if ( ! V_85 -> V_87 )
F_36 ( L_58 ,
V_91 ) ;
}
}
void T_4 F_37 ( struct V_84 * V_85 )
{
if ( V_85 -> V_87 ) {
F_33 ( V_91 , V_85 -> V_94 -> V_95 ) ;
V_85 -> V_87 = NULL ;
}
}
