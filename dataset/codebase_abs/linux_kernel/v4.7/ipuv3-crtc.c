static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( V_1 -> V_6 )
return;
F_3 ( V_3 ) ;
F_4 ( V_1 -> V_7 [ 0 ] ) ;
F_5 ( V_1 -> V_8 ) ;
F_6 ( V_1 -> V_9 ) ;
F_7 ( & V_1 -> V_10 ) ;
V_1 -> V_6 = 1 ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
if ( ! V_1 -> V_6 )
return;
F_9 ( V_1 -> V_8 ) ;
F_10 ( V_1 -> V_9 ) ;
F_11 ( V_1 -> V_7 [ 0 ] ) ;
F_12 ( V_3 ) ;
F_13 ( & V_1 -> V_10 ) ;
V_1 -> V_6 = 0 ;
}
static void F_14 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_16 ( V_1 -> V_4 , L_1 , V_14 , V_13 ) ;
switch ( V_13 ) {
case V_15 :
F_1 ( V_1 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
F_8 ( V_1 ) ;
break;
}
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_21 * V_22 =
F_18 ( V_20 , struct V_21 , V_23 ) ;
F_19 ( V_22 -> V_24 ) ;
F_20 ( V_22 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_21 * V_22 =
F_18 ( V_20 , struct V_21 , V_25 ) ;
int V_26 ;
if ( V_22 -> V_27 ) {
F_22 ( V_22 -> V_27 , false ) ;
F_23 ( V_22 -> V_27 ) ;
}
for ( V_26 = 0 ; V_26 < V_22 -> V_28 ; V_26 ++ ) {
F_22 ( V_22 -> V_29 [ V_26 ] , false ) ;
F_23 ( V_22 -> V_29 [ V_26 ] ) ;
}
V_22 -> V_12 -> V_30 = V_31 ;
}
static int F_24 ( struct V_11 * V_12 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
T_1 V_36 )
{
struct V_37 * V_38 = F_25 ( V_33 , 0 ) ;
struct V_1 * V_1 = F_15 ( V_12 ) ;
struct V_21 * V_39 ;
int V_40 ;
if ( V_1 -> V_30 != V_41 )
return - V_42 ;
V_40 = F_26 ( V_1 -> V_43 ) ;
if ( V_40 ) {
F_16 ( V_1 -> V_4 , L_2 ) ;
F_27 ( & V_35 -> V_10 . V_44 ) ;
return V_40 ;
}
V_39 = F_28 ( sizeof *V_39 , V_45 ) ;
if ( ! V_39 ) {
V_40 = - V_46 ;
goto V_47;
}
F_29 ( & V_39 -> V_23 , F_17 ) ;
V_39 -> V_48 = V_35 ;
V_39 -> V_24 = & F_25 ( V_12 -> V_49 -> V_33 , 0 ) -> V_10 ;
F_30 ( V_39 -> V_24 ) ;
V_1 -> V_39 = V_39 ;
if ( V_38 -> V_10 . V_50 ) {
F_29 ( & V_39 -> V_25 , F_21 ) ;
V_39 -> V_12 = V_1 ;
V_40 = F_31 (
V_38 -> V_10 . V_50 -> V_51 , & V_39 -> V_27 ,
& V_39 -> V_28 , & V_39 -> V_29 ) ;
if ( F_32 ( V_40 ) ) {
F_33 ( L_3 ) ;
goto V_52;
}
if ( ! V_39 -> V_27 && ! V_39 -> V_28 ) {
V_1 -> V_30 = V_31 ;
} else {
V_1 -> V_30 = V_53 ;
F_34 ( V_1 -> V_54 ,
& V_39 -> V_25 ) ;
}
} else {
V_1 -> V_30 = V_31 ;
}
return 0 ;
V_52:
F_19 ( V_39 -> V_24 ) ;
F_20 ( V_39 ) ;
V_1 -> V_39 = NULL ;
V_47:
F_35 ( V_1 -> V_43 ) ;
return V_40 ;
}
static int F_36 ( struct V_11 * V_12 ,
struct V_55 * V_56 ,
struct V_55 * V_13 ,
int V_57 , int V_58 ,
struct V_32 * V_59 )
{
struct V_60 * V_4 = V_12 -> V_4 ;
struct V_61 * V_62 ;
struct V_1 * V_1 = F_15 ( V_12 ) ;
struct V_63 V_64 = {} ;
unsigned long V_65 = 0 ;
int V_40 ;
F_16 ( V_1 -> V_4 , L_4 , V_14 ,
V_13 -> V_66 ) ;
F_16 ( V_1 -> V_4 , L_5 , V_14 ,
V_13 -> V_67 ) ;
F_37 (encoder, &dev->mode_config.encoder_list, head)
if ( V_62 -> V_12 == V_12 )
V_65 |= F_38 ( V_62 -> V_68 ) ;
F_16 ( V_1 -> V_4 , L_6 ,
V_14 , V_65 ) ;
if ( V_65 & ( F_38 ( V_69 ) |
F_38 ( V_70 ) ) )
V_64 . V_71 = V_72 | V_73 ;
else if ( V_65 & F_38 ( V_74 ) )
V_64 . V_71 = V_73 ;
else
V_64 . V_71 = 0 ;
V_64 . V_75 = ! ( V_1 -> V_76 & V_77 ) ;
V_64 . V_78 = ! ! ( V_1 -> V_76 &
V_79 ) ;
V_64 . V_80 = V_1 -> V_80 ;
V_64 . V_81 = 0 ;
V_64 . V_82 = V_1 -> V_83 ;
V_64 . V_84 = V_1 -> V_85 ;
F_39 ( V_13 , & V_64 . V_13 ) ;
V_40 = F_40 ( V_1 -> V_8 , V_1 -> V_9 ,
V_13 -> V_86 & V_87 ,
V_1 -> V_80 , V_13 -> V_66 ) ;
if ( V_40 ) {
F_41 ( V_1 -> V_4 ,
L_7 ,
V_40 ) ;
return V_40 ;
}
V_40 = F_42 ( V_1 -> V_9 , & V_64 ) ;
if ( V_40 ) {
F_41 ( V_1 -> V_4 ,
L_8 , V_40 ) ;
return V_40 ;
}
return F_43 ( V_1 -> V_7 [ 0 ] , V_12 , V_13 ,
V_12 -> V_49 -> V_33 ,
0 , 0 , V_13 -> V_66 , V_13 -> V_67 ,
V_57 , V_58 , V_13 -> V_66 , V_13 -> V_67 ,
V_13 -> V_86 & V_87 ) ;
}
static void F_44 ( struct V_1 * V_1 )
{
unsigned long V_86 ;
struct V_60 * V_88 = V_1 -> V_10 . V_4 ;
struct V_21 * V_22 = V_1 -> V_39 ;
F_45 ( & V_88 -> V_89 , V_86 ) ;
if ( V_22 -> V_48 )
F_46 ( & V_1 -> V_10 ,
V_22 -> V_48 ) ;
F_35 ( V_1 -> V_43 ) ;
F_47 ( & V_88 -> V_89 , V_86 ) ;
}
static T_2 F_48 ( int V_90 , void * V_91 )
{
struct V_1 * V_1 = V_91 ;
F_49 ( V_1 -> V_43 ) ;
if ( V_1 -> V_30 == V_31 ) {
struct V_92 * V_7 = V_1 -> V_7 [ 0 ] ;
F_50 ( V_7 , V_1 -> V_10 . V_49 -> V_33 ,
V_7 -> V_57 , V_7 -> V_58 ) ;
F_44 ( V_1 ) ;
F_34 ( V_1 -> V_54 ,
& V_1 -> V_39 -> V_23 ) ;
V_1 -> V_30 = V_41 ;
}
return V_93 ;
}
static bool F_51 ( struct V_11 * V_12 ,
const struct V_55 * V_13 ,
struct V_55 * V_94 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
struct V_95 V_96 ;
int V_40 ;
F_39 ( V_94 , & V_96 ) ;
V_40 = F_52 ( V_1 -> V_9 , & V_96 ) ;
if ( V_40 )
return false ;
F_53 ( & V_96 , V_94 ) ;
return true ;
}
static void F_54 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_8 ( V_1 ) ;
}
static void F_55 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_1 ( V_1 ) ;
}
static int F_56 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_57 ( V_1 -> V_90 ) ;
return 0 ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
F_59 ( V_1 -> V_90 ) ;
}
static int F_60 ( struct V_11 * V_12 ,
T_3 V_80 , int V_82 , int V_84 , T_3 V_76 )
{
struct V_1 * V_1 = F_15 ( V_12 ) ;
V_1 -> V_80 = V_80 ;
V_1 -> V_76 = V_76 ;
V_1 -> V_83 = V_82 ;
V_1 -> V_85 = V_84 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_1 )
{
if ( ! F_62 ( V_1 -> V_8 ) )
F_63 ( V_1 -> V_8 ) ;
if ( ! F_62 ( V_1 -> V_9 ) )
F_64 ( V_1 -> V_9 ) ;
}
static int F_65 ( struct V_1 * V_1 ,
struct V_97 * V_98 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_40 ;
V_1 -> V_8 = F_66 ( V_3 , V_98 -> V_8 ) ;
if ( F_67 ( V_1 -> V_8 ) ) {
V_40 = F_68 ( V_1 -> V_8 ) ;
goto V_99;
}
V_1 -> V_9 = F_69 ( V_3 , V_98 -> V_9 ) ;
if ( F_67 ( V_1 -> V_9 ) ) {
V_40 = F_68 ( V_1 -> V_9 ) ;
goto V_99;
}
return 0 ;
V_99:
F_61 ( V_1 ) ;
return V_40 ;
}
static int F_70 ( struct V_1 * V_1 ,
struct V_97 * V_98 , struct V_60 * V_88 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 -> V_5 ) ;
int V_100 = - V_101 ;
int V_40 ;
V_40 = F_65 ( V_1 , V_98 ) ;
if ( V_40 ) {
F_41 ( V_1 -> V_4 , L_9 ,
V_40 ) ;
return V_40 ;
}
if ( V_98 -> V_100 >= 0 )
V_100 = V_102 ;
V_1 -> V_7 [ 0 ] = F_71 ( V_88 , V_3 , V_98 -> V_103 [ 0 ] , V_100 , 0 ,
V_104 ) ;
if ( F_67 ( V_1 -> V_7 [ 0 ] ) ) {
V_40 = F_68 ( V_1 -> V_7 [ 0 ] ) ;
goto V_105;
}
V_40 = F_72 ( V_88 , & V_1 -> V_10 , & V_1 -> V_43 ,
& V_1 -> V_7 [ 0 ] -> V_10 , & V_106 ,
V_98 -> V_107 ) ;
if ( V_40 ) {
F_41 ( V_1 -> V_4 , L_10 , V_40 ) ;
goto V_105;
}
V_40 = F_73 ( V_1 -> V_7 [ 0 ] ) ;
if ( V_40 ) {
F_41 ( V_1 -> V_4 , L_11 ,
V_40 ) ;
goto V_108;
}
if ( V_98 -> V_100 >= 0 && V_98 -> V_103 [ 1 ] > 0 ) {
V_1 -> V_7 [ 1 ] = F_71 ( V_88 , V_3 , V_98 -> V_103 [ 1 ] ,
V_109 ,
F_74 ( & V_1 -> V_10 ) ,
V_110 ) ;
if ( F_67 ( V_1 -> V_7 [ 1 ] ) )
V_1 -> V_7 [ 1 ] = NULL ;
}
V_1 -> V_90 = F_75 ( V_1 -> V_7 [ 0 ] ) ;
V_40 = F_76 ( V_1 -> V_4 , V_1 -> V_90 , F_48 , 0 ,
L_12 , V_1 ) ;
if ( V_40 < 0 ) {
F_41 ( V_1 -> V_4 , L_13 , V_40 ) ;
goto V_111;
}
F_77 ( V_1 -> V_90 ) ;
V_1 -> V_54 = F_78 ( L_14 ) ;
return 0 ;
V_111:
F_79 ( V_1 -> V_7 [ 0 ] ) ;
V_108:
F_80 ( V_1 -> V_43 ) ;
V_105:
F_61 ( V_1 ) ;
return V_40 ;
}
static int F_81 ( struct V_112 * V_4 , struct V_112 * V_113 , void * V_114 )
{
struct V_97 * V_98 = V_4 -> V_115 ;
struct V_60 * V_88 = V_114 ;
struct V_1 * V_1 ;
int V_40 ;
V_1 = F_82 ( V_4 , sizeof( * V_1 ) , V_45 ) ;
if ( ! V_1 )
return - V_46 ;
V_1 -> V_4 = V_4 ;
V_40 = F_70 ( V_1 , V_98 , V_88 ) ;
if ( V_40 )
return V_40 ;
F_83 ( V_4 , V_1 ) ;
return 0 ;
}
static void F_84 ( struct V_112 * V_4 , struct V_112 * V_113 ,
void * V_114 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_80 ( V_1 -> V_43 ) ;
F_85 ( V_1 -> V_54 ) ;
F_79 ( V_1 -> V_7 [ 0 ] ) ;
F_61 ( V_1 ) ;
}
static int F_86 ( struct V_116 * V_117 )
{
struct V_112 * V_4 = & V_117 -> V_4 ;
int V_40 ;
if ( ! V_4 -> V_115 )
return - V_101 ;
V_40 = F_87 ( V_4 , F_88 ( 32 ) ) ;
if ( V_40 )
return V_40 ;
return F_89 ( V_4 , & V_118 ) ;
}
static int F_90 ( struct V_116 * V_117 )
{
F_91 ( & V_117 -> V_4 , & V_118 ) ;
return 0 ;
}
