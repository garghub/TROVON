static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
__acquires( T_2 )
__acquires( &bond->lock
static void * F_2 ( struct V_1 * V_2 , void * V_4 , T_1 * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_8 = V_4 ;
++ * V_3 ;
if ( V_4 == V_9 )
return V_6 -> V_10 ;
V_8 = V_8 -> V_11 ;
return ( V_8 == V_6 -> V_10 ) ? NULL : V_8 ;
}
static void F_3 ( struct V_1 * V_2 , void * V_4 )
__releases( &bond->lock
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_12 ;
int V_13 ;
F_5 ( & V_6 -> V_14 ) ;
V_12 = V_6 -> V_15 ;
F_6 ( & V_6 -> V_14 ) ;
F_7 ( V_2 , L_1 ,
F_8 ( V_6 -> V_16 . V_17 ) ) ;
if ( V_6 -> V_16 . V_17 == V_18 &&
V_6 -> V_16 . V_19 )
F_7 ( V_2 , L_2 ,
V_20 [ V_6 -> V_16 . V_19 ] . V_21 ) ;
F_7 ( V_2 , L_3 ) ;
if ( V_6 -> V_16 . V_17 == V_22 ||
V_6 -> V_16 . V_17 == V_23 ) {
F_7 ( V_2 , L_4 ,
V_24 [ V_6 -> V_16 . V_25 ] . V_21 ,
V_6 -> V_16 . V_25 ) ;
}
if ( F_9 ( V_6 -> V_16 . V_17 ) ) {
F_7 ( V_2 , L_5 ,
( V_6 -> V_26 ) ?
V_6 -> V_26 -> V_27 -> V_28 : L_6 ) ;
if ( V_6 -> V_26 )
F_7 ( V_2 , L_7 ,
V_29 [ V_6 -> V_16 . V_30 ] . V_21 ) ;
F_7 ( V_2 , L_8 ,
( V_12 ) ? V_12 -> V_27 -> V_28 : L_6 ) ;
}
F_7 ( V_2 , L_9 , F_10 ( V_6 -> V_27 ) ?
L_10 : L_11 ) ;
F_7 ( V_2 , L_12 , V_6 -> V_16 . V_31 ) ;
F_7 ( V_2 , L_13 ,
V_6 -> V_16 . V_32 * V_6 -> V_16 . V_31 ) ;
F_7 ( V_2 , L_14 ,
V_6 -> V_16 . V_33 * V_6 -> V_16 . V_31 ) ;
if ( V_6 -> V_16 . V_34 > 0 ) {
int V_35 = 0 ;
F_7 ( V_2 , L_15 ,
V_6 -> V_16 . V_34 ) ;
F_7 ( V_2 , L_16 ) ;
for ( V_13 = 0 ; ( V_13 < V_36 ) ; V_13 ++ ) {
if ( ! V_6 -> V_16 . V_37 [ V_13 ] )
break;
if ( V_35 )
F_7 ( V_2 , L_17 ) ;
F_7 ( V_2 , L_18 , & V_6 -> V_16 . V_37 [ V_13 ] ) ;
V_35 = 1 ;
}
F_7 ( V_2 , L_3 ) ;
}
if ( V_6 -> V_16 . V_17 == V_23 ) {
struct V_38 V_38 ;
F_11 ( V_2 , L_19 ) ;
F_7 ( V_2 , L_20 ,
( V_6 -> V_16 . V_39 ) ? L_21 : L_22 ) ;
F_7 ( V_2 , L_23 , V_6 -> V_16 . V_40 ) ;
F_7 ( V_2 , L_24 ,
V_41 [ V_6 -> V_16 . V_42 ] . V_21 ) ;
if ( F_12 ( V_6 , & V_38 ) ) {
F_7 ( V_2 , L_25 ,
V_6 -> V_27 -> V_28 ) ;
} else {
F_7 ( V_2 , L_26 ) ;
F_7 ( V_2 , L_27 ,
V_38 . V_43 ) ;
F_7 ( V_2 , L_28 ,
V_38 . V_44 ) ;
F_7 ( V_2 , L_29 ,
V_38 . V_45 ) ;
F_7 ( V_2 , L_30 ,
V_38 . V_46 ) ;
F_7 ( V_2 , L_31 ,
V_38 . V_47 ) ;
}
}
}
static void F_13 ( struct V_1 * V_2 ,
const struct V_8 * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_7 ( V_2 , L_32 , V_8 -> V_27 -> V_28 ) ;
F_7 ( V_2 , L_9 ,
( V_8 -> V_48 == V_49 ) ? L_10 : L_11 ) ;
if ( V_8 -> V_50 == V_51 )
F_7 ( V_2 , L_33 , L_34 ) ;
else
F_7 ( V_2 , L_35 , V_8 -> V_50 ) ;
if ( V_8 -> V_52 == V_53 )
F_7 ( V_2 , L_36 , L_34 ) ;
else
F_7 ( V_2 , L_36 , V_8 -> V_52 ? L_37 : L_38 ) ;
F_7 ( V_2 , L_39 ,
V_8 -> V_54 ) ;
F_7 ( V_2 , L_40 , V_8 -> V_55 ) ;
if ( V_6 -> V_16 . V_17 == V_23 ) {
const struct V_56 * V_57
= F_14 ( V_8 ) . V_58 . V_56 ;
if ( V_57 )
F_7 ( V_2 , L_41 ,
V_57 -> V_59 ) ;
else
F_11 ( V_2 , L_42 ) ;
}
F_7 ( V_2 , L_43 , V_8 -> V_60 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_4 )
{
if ( V_4 == V_9 ) {
F_7 ( V_2 , L_44 , V_61 ) ;
F_4 ( V_2 ) ;
} else
F_13 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_16 ( struct V_62 * V_62 , struct V_63 * V_63 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
int V_66 ;
V_66 = F_17 ( V_63 , & V_67 ) ;
if ( ! V_66 ) {
V_2 = V_63 -> V_68 ;
V_65 = F_18 ( V_62 ) ;
V_2 -> V_7 = V_65 -> V_69 ;
}
return V_66 ;
}
void F_19 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = V_6 -> V_27 ;
struct V_72 * V_73 = F_20 ( F_21 ( V_71 ) , V_74 ) ;
if ( V_73 -> V_75 ) {
V_6 -> V_76 = F_22 ( V_71 -> V_28 ,
V_77 , V_73 -> V_75 ,
& V_78 , V_6 ) ;
if ( V_6 -> V_76 == NULL )
F_23 ( L_45 ,
V_79 , V_71 -> V_28 ) ;
else
memcpy ( V_6 -> V_80 , V_71 -> V_28 , V_81 ) ;
}
}
void F_24 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = V_6 -> V_27 ;
struct V_72 * V_73 = F_20 ( F_21 ( V_71 ) , V_74 ) ;
if ( V_73 -> V_75 && V_6 -> V_76 ) {
F_25 ( V_6 -> V_80 , V_73 -> V_75 ) ;
memset ( V_6 -> V_80 , 0 , V_81 ) ;
V_6 -> V_76 = NULL ;
}
}
void T_3 F_26 ( struct V_72 * V_73 )
{
if ( ! V_73 -> V_75 ) {
V_73 -> V_75 = F_27 ( V_79 , V_73 -> V_82 -> V_83 ) ;
if ( ! V_73 -> V_75 )
F_23 ( L_46 ,
V_79 ) ;
}
}
void T_4 F_28 ( struct V_72 * V_73 )
{
if ( V_73 -> V_75 ) {
F_25 ( V_79 , V_73 -> V_82 -> V_83 ) ;
V_73 -> V_75 = NULL ;
}
}
