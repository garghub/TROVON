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
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
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
int V_16 ;
F_9 ( L_3 , V_4 -> V_28 , V_27 ) ;
F_7 ( V_12 , V_27 ? V_12 -> V_14 : NULL ) ;
if ( ! V_27 ) {
F_15 ( V_4 -> V_29 , false ) ;
return;
}
V_26 = F_16 ( V_24 ) ;
F_17 ( V_12 -> V_14 , V_20 , V_22 ) ;
F_9 ( L_4 , V_22 -> V_30 , V_22 -> V_31 ,
V_22 -> V_32 , V_22 -> V_33 ,
V_22 -> V_34 ) ;
F_9 ( L_5 , V_22 -> V_35 , V_22 -> V_36 ,
& V_22 -> V_37 , & V_22 -> V_38 ) ;
F_18 ( V_4 -> V_29 , V_26 ) ;
V_16 = F_19 ( V_4 -> V_29 , V_22 , false ,
F_20 ( V_24 ) , false ) ;
if ( V_16 ) {
F_13 ( V_7 -> V_7 , L_6 , V_16 ) ;
return;
}
F_15 ( V_4 -> V_29 , true ) ;
}
static void F_21 ( struct V_17 * V_18 )
{
struct V_4 * V_4 =
F_2 ( V_18 , struct V_4 , V_18 ) ;
struct V_11 * V_12 = & V_4 -> V_8 ;
struct V_39 * V_40 = V_12 -> V_7 -> V_41 ;
struct V_42 V_43 ;
V_43 = V_4 -> V_44 ;
V_4 -> V_44 . V_45 = NULL ;
F_22 ( & V_4 -> V_5 , V_40 -> V_46 ) ;
if ( V_43 . V_45 )
V_43 . V_45 ( V_43 . V_47 ) ;
}
static int F_23 ( struct V_11 * V_12 )
{
if ( V_12 -> V_24 ) {
struct V_4 * V_4 = F_8 ( V_12 ) ;
return F_24 ( V_12 -> V_24 , & V_4 -> V_18 ) ;
}
return 0 ;
}
int F_25 ( struct V_11 * V_12 ,
struct V_23 * V_24 , struct V_13 * V_14 ,
int V_48 , int V_49 ,
unsigned int V_50 , unsigned int V_51 ,
unsigned int V_52 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 ,
void (* V_45)( void * ) , void * V_47 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_19 * V_20 = & V_4 -> V_20 ;
V_20 -> V_48 = V_48 ;
V_20 -> V_49 = V_49 ;
V_20 -> V_50 = V_50 ;
V_20 -> V_51 = V_51 ;
V_20 -> V_52 = V_52 ;
V_20 -> V_53 = V_53 ;
V_20 -> V_54 = V_54 ;
V_20 -> V_55 = V_55 ;
if ( V_45 ) {
F_26 ( V_4 -> V_44 . V_45 ) ;
V_4 -> V_44 . V_45 = V_45 ;
V_4 -> V_44 . V_47 = V_47 ;
}
return F_23 ( V_12 ) ;
}
static int F_27 ( struct V_11 * V_12 ,
struct V_23 * V_24 , struct V_13 * V_14 ,
int V_48 , int V_49 ,
unsigned int V_50 , unsigned int V_51 ,
T_1 V_52 , T_1 V_53 ,
T_1 V_54 , T_1 V_55 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
V_4 -> V_27 = true ;
switch ( V_4 -> V_20 . V_56 & 0xf ) {
case F_28 ( V_57 ) :
case F_28 ( V_58 ) :
F_29 ( V_54 , V_55 ) ;
break;
}
V_12 -> V_14 = V_14 ;
V_12 -> V_24 = V_24 ;
return F_25 ( V_12 , V_24 , V_14 ,
V_48 , V_49 , V_50 , V_51 ,
V_52 >> 16 , V_53 >> 16 , V_54 >> 16 , V_55 >> 16 ,
NULL , NULL ) ;
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
V_4 -> V_20 . V_56 = F_28 ( V_59 ) ;
V_4 -> V_22 . V_60 = V_12 -> type == V_61
? 0 : V_4 -> V_29 ;
return F_31 ( V_12 , false ) ;
}
static void F_32 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
F_9 ( L_7 , V_4 -> V_28 ) ;
F_33 ( V_12 -> V_7 , & V_4 -> V_62 ) ;
F_34 ( V_12 ) ;
F_35 ( & V_4 -> V_5 ) ;
F_36 ( V_4 ) ;
}
int F_31 ( struct V_11 * V_12 , bool V_63 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
if ( V_63 == V_4 -> V_27 )
return 0 ;
V_4 -> V_27 = V_63 ;
return F_23 ( V_12 ) ;
}
void F_37 ( struct V_11 * V_12 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_39 * V_40 = V_7 -> V_41 ;
struct V_66 * V_67 ;
if ( V_40 -> V_68 ) {
V_67 = V_40 -> V_69 ;
if ( ! V_67 ) {
V_67 = F_38 ( V_7 ,
F_28 ( V_59 ) |
F_28 ( V_57 ) |
F_28 ( V_70 ) |
F_28 ( V_58 ) |
F_28 ( V_71 ) |
F_28 ( V_72 ) ) ;
if ( V_67 == NULL )
return;
V_40 -> V_69 = V_67 ;
}
F_39 ( V_65 , V_67 , 0 ) ;
}
V_67 = V_40 -> V_73 ;
if ( ! V_67 ) {
V_67 = F_40 ( V_7 , 0 , L_8 , 0 , 3 ) ;
if ( V_67 == NULL )
return;
V_40 -> V_73 = V_67 ;
}
F_39 ( V_65 , V_67 , 0 ) ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_66 * V_74 , T_2 V_3 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_39 * V_40 = V_12 -> V_7 -> V_41 ;
int V_16 = - V_75 ;
if ( V_74 == V_40 -> V_69 ) {
F_9 ( L_9 , V_4 -> V_28 , ( T_1 ) V_3 ) ;
V_4 -> V_20 . V_56 = V_3 ;
V_16 = F_23 ( V_12 ) ;
} else if ( V_74 == V_40 -> V_73 ) {
F_9 ( L_10 , V_4 -> V_28 , ( T_1 ) V_3 ) ;
V_4 -> V_22 . V_60 = V_3 ;
V_16 = F_23 ( V_12 ) ;
}
return V_16 ;
}
static void F_42 ( struct V_76 * V_77 , T_1 V_78 )
{
struct V_4 * V_4 =
F_2 ( V_77 , struct V_4 , V_62 ) ;
F_43 ( L_11 , V_4 -> V_28 ,
V_78 ) ;
}
struct V_11 * F_44 ( struct V_6 * V_7 ,
int V_29 , enum V_79 type )
{
struct V_39 * V_40 = V_7 -> V_41 ;
struct V_11 * V_12 ;
struct V_4 * V_4 ;
struct V_21 * V_22 ;
int V_16 ;
F_9 ( L_12 , V_80 [ V_29 ] , type ) ;
V_4 = F_45 ( sizeof( * V_4 ) , V_81 ) ;
if ( ! V_4 )
return F_46 ( - V_82 ) ;
F_47 ( & V_4 -> V_5 ,
L_13 , F_1 ) ;
V_4 -> V_83 = F_48 (
V_4 -> V_84 , F_49 ( V_4 -> V_84 ) ,
F_50 ( V_29 ) ) ;
V_4 -> V_29 = V_29 ;
V_4 -> V_28 = V_80 [ V_29 ] ;
V_12 = & V_4 -> V_8 ;
V_4 -> V_18 . V_85 = F_14 ;
V_4 -> V_18 . V_86 = F_21 ;
V_4 -> V_62 . V_87 = V_88 [ V_29 ] ;
V_4 -> V_62 . V_77 = F_42 ;
F_51 ( V_7 , & V_4 -> V_62 ) ;
V_16 = F_52 ( V_7 , V_12 , ( 1 << V_40 -> V_89 ) - 1 ,
& V_90 , V_4 -> V_84 ,
V_4 -> V_83 , type ) ;
if ( V_16 < 0 )
goto error;
F_37 ( V_12 , & V_12 -> V_8 ) ;
V_22 = & V_4 -> V_22 ;
V_22 -> V_91 = V_92 ;
V_22 -> V_56 = V_93 ;
V_22 -> V_94 = 0xff ;
V_22 -> V_95 = 0 ;
if ( type == V_61 )
V_4 -> V_22 . V_60 = 0 ;
else
V_4 -> V_22 . V_60 = V_29 ;
return V_12 ;
error:
F_33 ( V_12 -> V_7 , & V_4 -> V_62 ) ;
F_36 ( V_4 ) ;
return NULL ;
}
