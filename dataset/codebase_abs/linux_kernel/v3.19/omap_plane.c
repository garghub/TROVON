static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 =
F_2 ( V_2 , struct V_4 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_8 . V_7 ;
F_3 ( V_3 ) ;
F_4 ( & V_7 -> V_9 . V_10 ) ;
F_5 ( V_3 ) ;
F_6 ( & V_7 -> V_9 . V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_13 * V_15 = V_4 -> V_15 ;
if ( V_15 != V_14 ) {
int V_16 = 0 ;
F_9 ( L_1 , V_15 , V_14 ) ;
if ( V_14 ) {
F_10 ( V_14 ) ;
V_16 = F_11 ( V_14 ) ;
}
if ( V_15 )
F_12 ( & V_4 -> V_5 , V_15 ) ;
if ( V_16 ) {
F_13 ( V_12 -> V_7 -> V_7 , L_2 ,
V_4 -> V_15 , V_14 ) ;
F_5 ( V_14 ) ;
V_4 -> V_15 = NULL ;
return V_16 ;
}
V_4 -> V_15 = V_14 ;
}
return 0 ;
}
static void F_14 ( struct V_17 * V_18 )
{
struct V_4 * V_4 =
F_2 ( V_18 , struct V_4 , V_18 ) ;
struct V_19 * V_20 = & V_4 -> V_20 ;
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_21 * V_22 = & V_4 -> V_22 ;
struct V_23 * V_24 = V_12 -> V_24 ;
enum V_25 V_26 ;
bool V_27 = V_4 -> V_27 && V_24 ;
bool V_28 , V_29 ;
int V_16 ;
F_9 ( L_3 , V_4 -> V_30 , V_27 ) ;
F_7 ( V_12 , V_27 ? V_12 -> V_14 : NULL ) ;
if ( ! V_27 ) {
F_15 ( V_4 -> V_31 , false ) ;
return;
}
V_26 = F_16 ( V_24 ) ;
F_17 ( V_12 -> V_14 , V_20 , V_22 ) ;
F_9 ( L_4 , V_22 -> V_32 , V_22 -> V_33 ,
V_22 -> V_34 , V_22 -> V_35 ,
V_22 -> V_36 ) ;
F_9 ( L_5 , V_22 -> V_37 , V_22 -> V_38 ,
& V_22 -> V_39 , & V_22 -> V_40 ) ;
V_28 = false ;
V_29 = false ;
V_16 = F_18 ( V_4 -> V_31 , V_22 ,
V_29 , F_19 ( V_24 ) , false ) ;
if ( V_16 ) {
F_13 ( V_7 -> V_7 , L_6 , V_16 ) ;
return;
}
F_15 ( V_4 -> V_31 , true ) ;
F_20 ( V_4 -> V_31 , V_26 ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_4 * V_4 =
F_2 ( V_18 , struct V_4 , V_18 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_41 * V_42 = V_12 -> V_7 -> V_43 ;
struct V_21 * V_22 = & V_4 -> V_22 ;
struct V_44 V_45 ;
V_45 = V_4 -> V_46 ;
V_4 -> V_46 . V_47 = NULL ;
F_22 ( & V_4 -> V_5 , V_42 -> V_48 ) ;
if ( V_45 . V_47 )
V_45 . V_47 ( V_45 . V_49 ) ;
if ( V_4 -> V_27 ) {
F_23 ( V_12 -> V_14 , V_22 -> V_37 , V_22 -> V_38 ,
V_22 -> V_34 , V_22 -> V_35 ) ;
}
}
static int V_18 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 ) {
struct V_4 * V_4 = F_8 ( V_12 ) ;
return F_24 ( V_12 -> V_24 , & V_4 -> V_18 ) ;
}
return 0 ;
}
int F_25 ( struct V_11 * V_12 ,
struct V_23 * V_24 , struct V_13 * V_14 ,
int V_50 , int V_51 ,
unsigned int V_52 , unsigned int V_53 ,
T_1 V_54 , T_1 V_55 ,
T_1 V_56 , T_1 V_57 ,
void (* V_47)( void * ) , void * V_49 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_19 * V_20 = & V_4 -> V_20 ;
V_20 -> V_50 = V_50 ;
V_20 -> V_51 = V_51 ;
V_20 -> V_52 = V_52 ;
V_20 -> V_53 = V_53 ;
V_20 -> V_54 = V_54 >> 16 ;
V_20 -> V_55 = V_55 >> 16 ;
V_20 -> V_56 = V_56 >> 16 ;
V_20 -> V_57 = V_57 >> 16 ;
if ( V_47 ) {
F_26 ( V_4 -> V_46 . V_47 ) ;
V_4 -> V_46 . V_47 = V_47 ;
V_4 -> V_46 . V_49 = V_49 ;
}
if ( V_12 -> V_14 )
F_5 ( V_12 -> V_14 ) ;
F_10 ( V_14 ) ;
V_12 -> V_14 = V_14 ;
V_12 -> V_24 = V_24 ;
return V_18 ( V_12 ) ;
}
static int F_27 ( struct V_11 * V_12 ,
struct V_23 * V_24 , struct V_13 * V_14 ,
int V_50 , int V_51 ,
unsigned int V_52 , unsigned int V_53 ,
T_1 V_54 , T_1 V_55 ,
T_1 V_56 , T_1 V_57 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
V_4 -> V_27 = true ;
switch ( V_4 -> V_20 . V_58 & 0xf ) {
case F_28 ( V_59 ) :
case F_28 ( V_60 ) :
F_29 ( V_56 , V_57 ) ;
break;
}
return F_25 ( V_12 , V_24 , V_14 ,
V_50 , V_51 , V_52 , V_53 ,
V_54 , V_55 , V_56 , V_57 ,
NULL , NULL ) ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
V_4 -> V_20 . V_58 = F_28 ( V_61 ) ;
return F_31 ( V_12 , V_62 ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
F_9 ( L_7 , V_4 -> V_30 ) ;
F_33 ( V_12 -> V_7 , & V_4 -> V_63 ) ;
F_30 ( V_12 ) ;
F_34 ( V_12 ) ;
F_35 ( & V_4 -> V_5 ) ;
F_36 ( V_4 ) ;
}
int F_31 ( struct V_11 * V_12 , int V_64 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
bool V_27 = ( V_64 == V_65 ) ;
int V_16 = 0 ;
if ( V_27 != V_4 -> V_27 ) {
V_4 -> V_27 = V_27 ;
V_16 = V_18 ( V_12 ) ;
}
return V_16 ;
}
void F_37 ( struct V_11 * V_12 ,
struct V_66 * V_67 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 ;
struct V_68 * V_69 ;
if ( V_42 -> V_70 ) {
V_69 = V_42 -> V_71 ;
if ( ! V_69 ) {
V_69 = F_38 ( V_7 ,
F_28 ( V_61 ) |
F_28 ( V_59 ) |
F_28 ( V_72 ) |
F_28 ( V_60 ) |
F_28 ( V_73 ) |
F_28 ( V_74 ) ) ;
if ( V_69 == NULL )
return;
V_42 -> V_71 = V_69 ;
}
F_39 ( V_67 , V_69 , 0 ) ;
}
V_69 = V_42 -> V_75 ;
if ( ! V_69 ) {
V_69 = F_40 ( V_7 , 0 , L_8 , 0 , 3 ) ;
if ( V_69 == NULL )
return;
V_42 -> V_75 = V_69 ;
}
F_39 ( V_67 , V_69 , 0 ) ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_68 * V_76 , T_2 V_3 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_41 * V_42 = V_12 -> V_7 -> V_43 ;
int V_16 = - V_77 ;
if ( V_76 == V_42 -> V_71 ) {
F_9 ( L_9 , V_4 -> V_30 , ( T_1 ) V_3 ) ;
V_4 -> V_20 . V_58 = V_3 ;
V_16 = V_18 ( V_12 ) ;
} else if ( V_76 == V_42 -> V_75 ) {
F_9 ( L_10 , V_4 -> V_30 , ( T_1 ) V_3 ) ;
V_4 -> V_22 . V_78 = V_3 ;
V_16 = V_18 ( V_12 ) ;
}
return V_16 ;
}
static void F_42 ( struct V_79 * V_80 , T_1 V_81 )
{
struct V_4 * V_4 =
F_2 ( V_80 , struct V_4 , V_63 ) ;
F_43 ( L_11 , V_4 -> V_30 , V_81 ) ;
}
struct V_11 * F_44 ( struct V_6 * V_7 ,
int V_31 , bool V_82 )
{
struct V_41 * V_42 = V_7 -> V_43 ;
struct V_11 * V_12 = NULL ;
struct V_4 * V_4 ;
struct V_21 * V_22 ;
F_9 ( L_12 , V_83 [ V_31 ] , V_82 ) ;
V_4 = F_45 ( sizeof( * V_4 ) , V_84 ) ;
if ( ! V_4 )
return NULL ;
F_46 ( & V_4 -> V_5 ,
L_13 , F_1 ) ;
V_4 -> V_85 = F_47 (
V_4 -> V_86 , F_48 ( V_4 -> V_86 ) ,
F_49 ( V_31 ) ) ;
V_4 -> V_31 = V_31 ;
V_4 -> V_30 = V_83 [ V_31 ] ;
V_12 = & V_4 -> V_8 ;
V_4 -> V_18 . V_87 = F_14 ;
V_4 -> V_18 . V_88 = F_21 ;
V_4 -> V_63 . V_89 = V_90 [ V_31 ] ;
V_4 -> V_63 . V_80 = F_42 ;
F_50 ( V_7 , & V_4 -> V_63 ) ;
F_51 ( V_7 , V_12 , ( 1 << V_42 -> V_91 ) - 1 , & V_92 ,
V_4 -> V_86 , V_4 -> V_85 , V_82 ) ;
F_37 ( V_12 , & V_12 -> V_8 ) ;
V_22 = & V_4 -> V_22 ;
V_22 -> V_93 = V_94 ;
V_22 -> V_58 = V_95 ;
V_22 -> V_96 = 0xff ;
V_22 -> V_97 = 0 ;
if ( V_82 )
V_4 -> V_22 . V_78 = 0 ;
else
V_4 -> V_22 . V_78 = V_31 ;
return V_12 ;
}
