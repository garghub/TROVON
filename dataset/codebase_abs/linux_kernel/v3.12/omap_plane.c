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
V_22 -> V_39 , V_22 -> V_40 ) ;
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
if ( V_12 -> V_14 )
F_5 ( V_12 -> V_14 ) ;
F_10 ( V_14 ) ;
return F_25 ( V_12 , V_24 , V_14 ,
V_50 , V_51 , V_52 , V_53 ,
V_54 , V_55 , V_56 , V_57 ,
NULL , NULL ) ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
V_4 -> V_20 . V_58 = F_29 ( V_59 ) ;
return F_30 ( V_12 , V_60 ) ;
}
static void F_31 ( struct V_11 * V_12 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
F_9 ( L_7 , V_4 -> V_30 ) ;
F_32 ( V_12 -> V_7 , & V_4 -> V_61 ) ;
F_28 ( V_12 ) ;
F_33 ( V_12 ) ;
F_34 ( & V_4 -> V_5 ) ;
F_35 ( V_4 ) ;
}
int F_30 ( struct V_11 * V_12 , int V_62 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
bool V_27 = ( V_62 == V_63 ) ;
int V_16 = 0 ;
if ( V_27 != V_4 -> V_27 ) {
V_4 -> V_27 = V_27 ;
V_16 = V_18 ( V_12 ) ;
}
return V_16 ;
}
void F_36 ( struct V_11 * V_12 ,
struct V_64 * V_65 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 ;
struct V_66 * V_67 ;
if ( V_42 -> V_68 ) {
V_67 = V_42 -> V_69 ;
if ( ! V_67 ) {
const struct V_70 V_71 [] = {
{ V_59 , L_8 } ,
{ V_72 , L_9 } ,
{ V_73 , L_10 } ,
{ V_74 , L_11 } ,
{ V_75 , L_12 } ,
{ V_76 , L_13 } ,
} ;
V_67 = F_37 ( V_7 , 0 , L_14 ,
V_71 , F_38 ( V_71 ) ) ;
if ( V_67 == NULL )
return;
V_42 -> V_69 = V_67 ;
}
F_39 ( V_65 , V_67 , 0 ) ;
}
V_67 = V_42 -> V_77 ;
if ( ! V_67 ) {
V_67 = F_40 ( V_7 , 0 , L_15 , 0 , 3 ) ;
if ( V_67 == NULL )
return;
V_42 -> V_77 = V_67 ;
}
F_39 ( V_65 , V_67 , 0 ) ;
}
int F_41 ( struct V_11 * V_12 ,
struct V_66 * V_78 , T_2 V_3 )
{
struct V_4 * V_4 = F_8 ( V_12 ) ;
struct V_41 * V_42 = V_12 -> V_7 -> V_43 ;
int V_16 = - V_79 ;
if ( V_78 == V_42 -> V_69 ) {
F_9 ( L_16 , V_4 -> V_30 , ( T_1 ) V_3 ) ;
V_4 -> V_20 . V_58 = V_3 ;
V_16 = V_18 ( V_12 ) ;
} else if ( V_78 == V_42 -> V_77 ) {
F_9 ( L_17 , V_4 -> V_30 , ( T_1 ) V_3 ) ;
V_4 -> V_22 . V_80 = V_3 ;
V_16 = V_18 ( V_12 ) ;
}
return V_16 ;
}
static void F_42 ( struct V_81 * V_82 , T_1 V_83 )
{
struct V_4 * V_4 =
F_2 ( V_82 , struct V_4 , V_61 ) ;
F_43 ( L_18 , V_4 -> V_30 , V_83 ) ;
}
struct V_11 * F_44 ( struct V_6 * V_7 ,
int V_31 , bool V_84 )
{
struct V_41 * V_42 = V_7 -> V_43 ;
struct V_11 * V_12 = NULL ;
struct V_4 * V_4 ;
struct V_21 * V_22 ;
int V_16 ;
F_9 ( L_19 , V_85 [ V_31 ] , V_84 ) ;
V_4 = F_45 ( sizeof( * V_4 ) , V_86 ) ;
if ( ! V_4 )
goto V_87;
V_16 = F_46 ( & V_4 -> V_5 , 16 ,
L_20 , F_1 ) ;
if ( V_16 ) {
F_13 ( V_7 -> V_7 , L_21 ) ;
goto V_87;
}
V_4 -> V_88 = F_47 (
V_4 -> V_89 , F_38 ( V_4 -> V_89 ) ,
F_48 ( V_31 ) ) ;
V_4 -> V_31 = V_31 ;
V_4 -> V_30 = V_85 [ V_31 ] ;
V_12 = & V_4 -> V_8 ;
V_4 -> V_18 . V_90 = F_14 ;
V_4 -> V_18 . V_91 = F_21 ;
V_4 -> V_61 . V_92 = V_93 [ V_31 ] ;
V_4 -> V_61 . V_82 = F_42 ;
F_49 ( V_7 , & V_4 -> V_61 ) ;
F_50 ( V_7 , V_12 , ( 1 << V_42 -> V_94 ) - 1 , & V_95 ,
V_4 -> V_89 , V_4 -> V_88 , V_84 ) ;
F_36 ( V_12 , & V_12 -> V_8 ) ;
V_22 = & V_4 -> V_22 ;
V_22 -> V_96 = V_97 ;
V_22 -> V_58 = V_98 ;
V_22 -> V_99 = 0xff ;
V_22 -> V_100 = 0 ;
if ( V_84 )
V_4 -> V_22 . V_80 = 0 ;
else
V_4 -> V_22 . V_80 = V_31 ;
return V_12 ;
V_87:
if ( V_12 )
F_31 ( V_12 ) ;
return NULL ;
}
