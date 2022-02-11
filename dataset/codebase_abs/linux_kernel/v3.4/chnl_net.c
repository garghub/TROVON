static void F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
struct V_1 * V_4 ;
F_2 () ;
F_3 (list_node, n, &chnl_net_list) {
if ( V_3 == V_2 ) {
F_4 ( V_3 ) ;
return;
}
}
F_5 ( 1 ) ;
}
static int F_6 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
const T_1 * V_14 ;
T_1 V_15 ;
V_12 = F_7 ( V_6 , struct V_11 , V_16 ) ;
if ( ! V_12 )
return - V_17 ;
V_10 = (struct V_9 * ) F_8 ( V_8 ) ;
V_13 = V_10 -> V_18 ;
V_10 -> V_19 = V_12 -> V_20 ;
V_14 = F_9 ( V_10 , 0 , 1 , & V_15 ) ;
switch ( * V_14 >> 4 ) {
case 4 :
V_10 -> V_21 = F_10 ( V_22 ) ;
break;
case 6 :
V_10 -> V_21 = F_10 ( V_23 ) ;
break;
default:
F_11 ( V_10 ) ;
V_12 -> V_20 -> V_24 . V_25 ++ ;
return - V_17 ;
}
if ( V_12 -> V_26 . V_21 == V_27 )
V_10 -> V_28 = V_29 ;
else
V_10 -> V_28 = V_30 ;
if ( F_12 () )
F_13 ( V_10 ) ;
else
F_14 ( V_10 ) ;
V_12 -> V_20 -> V_24 . V_31 ++ ;
V_12 -> V_20 -> V_24 . V_32 += V_13 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_19 )
{
F_2 () ;
if ( V_19 -> V_20 )
F_16 ( V_19 -> V_20 ) ;
return 0 ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_11 * V_19 = NULL ;
struct V_1 * V_3 ;
struct V_1 * V_35 ;
F_18 () ;
F_3 (list_node, _tmp, &chnl_net_list) {
V_19 = F_19 ( V_3 , struct V_11 , V_36 ) ;
if ( V_19 -> V_37 == V_38 )
F_20 ( V_19 -> V_20 ) ;
}
F_21 () ;
}
static void F_22 ( struct V_5 * V_39 )
{
struct V_11 * V_12 = F_7 ( V_39 , struct V_11 , V_16 ) ;
F_23 ( V_12 -> V_20 ) ;
}
static void F_24 ( struct V_5 * V_39 )
{
struct V_11 * V_12 = F_7 ( V_39 , struct V_11 , V_16 ) ;
F_25 ( V_12 -> V_20 ) ;
}
static void F_26 ( struct V_5 * V_6 , enum V_40 V_41 ,
int V_42 )
{
struct V_11 * V_12 = F_7 ( V_6 , struct V_11 , V_16 ) ;
F_27 ( L_1 ,
V_41 == V_43 ? L_2 :
V_41 == V_44 ? L_3 :
V_41 == V_45 ? L_4 :
V_41 == V_46 ? L_5 :
V_41 == V_47 ? L_6 :
V_41 == V_48 ?
L_7 : L_8 ) ;
switch ( V_41 ) {
case V_45 :
V_12 -> V_49 = false ;
F_28 ( V_12 -> V_20 ) ;
break;
case V_46 :
V_12 -> V_37 = V_50 ;
break;
case V_47 :
V_12 -> V_37 = V_50 ;
F_29 ( & V_12 -> V_51 ) ;
break;
case V_48 :
V_12 -> V_37 = V_38 ;
F_30 ( V_12 -> V_20 ) ;
F_31 ( & V_52 ) ;
break;
case V_43 :
V_12 -> V_49 = true ;
F_32 ( V_12 -> V_20 ) ;
break;
case V_44 :
F_33 ( & V_12 -> V_16 , F_22 , F_24 ) ;
V_12 -> V_37 = V_53 ;
V_12 -> V_49 = true ;
F_32 ( V_12 -> V_20 ) ;
F_29 ( & V_12 -> V_51 ) ;
break;
default:
break;
}
}
static int F_34 ( struct V_9 * V_10 , struct V_54 * V_19 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 = NULL ;
int V_18 ;
int V_55 = - 1 ;
V_12 = F_35 ( V_19 ) ;
if ( V_10 -> V_18 > V_12 -> V_20 -> V_56 ) {
F_36 ( L_9 ) ;
F_11 ( V_10 ) ;
V_19 -> V_24 . V_57 ++ ;
return V_58 ;
}
if ( ! V_12 -> V_49 ) {
F_27 ( L_10 ) ;
F_11 ( V_10 ) ;
V_19 -> V_24 . V_59 ++ ;
return V_58 ;
}
if ( V_12 -> V_26 . V_21 == V_27 )
F_37 ( F_38 ( V_10 ) -> V_60 , F_38 ( V_10 ) -> V_61 ) ;
V_18 = V_10 -> V_18 ;
V_8 = F_39 ( V_62 , ( void * ) V_10 ) ;
V_55 = V_12 -> V_16 . V_63 -> V_64 ( V_12 -> V_16 . V_63 , V_8 ) ;
if ( V_55 ) {
V_19 -> V_24 . V_59 ++ ;
return V_58 ;
}
V_19 -> V_24 . V_65 ++ ;
V_19 -> V_24 . V_66 += V_18 ;
return V_58 ;
}
static int F_40 ( struct V_54 * V_19 )
{
struct V_11 * V_12 = NULL ;
int V_55 = - 1 ;
int V_67 , V_68 , V_69 , V_56 ;
struct V_54 * V_70 ;
F_2 () ;
V_12 = F_35 ( V_19 ) ;
if ( ! V_12 ) {
F_27 ( L_11 ) ;
return - V_71 ;
}
if ( V_12 -> V_37 != V_72 ) {
V_12 -> V_37 = V_72 ;
V_55 = F_41 ( F_42 ( V_19 ) , & V_12 -> V_26 ,
& V_12 -> V_16 , & V_67 ,
& V_68 , & V_69 ) ;
if ( V_55 != 0 ) {
F_27 ( L_12
L_13
L_14 ,
V_55 ) ;
goto error;
}
V_70 = F_43 ( F_42 ( V_19 ) , V_67 ) ;
if ( V_70 == NULL ) {
F_27 ( L_15 ) ;
V_55 = - V_71 ;
goto error;
}
V_19 -> V_73 = V_69 + V_70 -> V_73 ;
V_19 -> V_74 = V_68 + V_70 -> V_74 +
V_70 -> V_73 ;
V_56 = F_44 ( int , V_19 -> V_56 , V_70 -> V_56 - ( V_68 + V_69 ) ) ;
V_56 = F_44 ( int , V_75 , V_56 ) ;
F_45 ( V_19 , V_56 ) ;
F_25 ( V_70 ) ;
if ( V_56 < 100 ) {
F_36 ( L_16 , V_56 ) ;
V_55 = - V_71 ;
goto error;
}
}
F_21 () ;
V_55 = F_46 ( V_12 -> V_51 ,
V_12 -> V_37 != V_72 ,
V_76 ) ;
F_18 () ;
if ( V_55 == - V_77 ) {
F_27 ( L_17 ) ;
V_55 = - V_77 ;
goto error;
}
if ( V_55 == 0 ) {
F_27 ( L_18 ) ;
F_47 ( F_42 ( V_19 ) , & V_12 -> V_16 ) ;
V_12 -> V_37 = V_50 ;
F_27 ( L_19 ) ;
V_55 = - V_78 ;
goto error;
}
if ( V_12 -> V_37 != V_53 ) {
F_27 ( L_20 ) ;
V_55 = - V_79 ;
goto error;
}
F_27 ( L_21 ) ;
return 0 ;
error:
F_47 ( F_42 ( V_19 ) , & V_12 -> V_16 ) ;
V_12 -> V_37 = V_50 ;
F_27 ( L_19 ) ;
return V_55 ;
}
static int F_48 ( struct V_54 * V_19 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_35 ( V_19 ) ;
V_12 -> V_37 = V_50 ;
F_47 ( F_42 ( V_19 ) , & V_12 -> V_16 ) ;
return 0 ;
}
static int F_49 ( struct V_54 * V_19 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_35 ( V_19 ) ;
strncpy ( V_12 -> V_80 , V_19 -> V_80 , sizeof( V_12 -> V_80 ) ) ;
return 0 ;
}
static void F_50 ( struct V_54 * V_19 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_35 ( V_19 ) ;
F_1 ( & V_12 -> V_36 ) ;
}
static void F_51 ( struct V_54 * V_19 )
{
struct V_11 * V_12 = F_35 ( V_19 ) ;
F_52 ( & V_12 -> V_16 ) ;
F_53 ( V_19 ) ;
}
static void F_54 ( struct V_54 * V_19 )
{
struct V_11 * V_12 ;
V_19 -> V_81 = & V_81 ;
V_19 -> V_82 = F_51 ;
V_19 -> V_83 |= V_84 ;
V_19 -> V_83 |= V_85 ;
V_19 -> V_56 = V_75 ;
V_19 -> V_86 = V_87 ;
V_12 = F_35 ( V_19 ) ;
V_12 -> V_16 . V_88 = F_6 ;
V_12 -> V_16 . V_89 = F_26 ;
V_12 -> V_20 = V_19 ;
V_12 -> V_26 . V_21 = V_90 ;
V_12 -> V_26 . V_91 = V_92 ;
V_12 -> V_26 . V_93 = V_94 ;
V_12 -> V_26 . V_95 . V_96 . V_97 . V_98 = V_99 ;
V_12 -> V_49 = false ;
F_55 ( & V_12 -> V_51 ) ;
}
static int F_56 ( struct V_9 * V_10 , const struct V_54 * V_19 )
{
struct V_11 * V_12 ;
T_1 V_100 ;
V_12 = F_35 ( V_19 ) ;
F_57 ( V_10 , V_101 ,
V_12 -> V_26 . V_95 . V_96 . V_97 . V_98 ) ;
F_57 ( V_10 , V_102 ,
V_12 -> V_26 . V_95 . V_96 . V_97 . V_98 ) ;
V_100 = V_12 -> V_26 . V_21 == V_27 ;
F_58 ( V_10 , V_103 , V_100 ) ;
return 0 ;
V_104:
return - V_105 ;
}
static void F_59 ( struct V_106 * V_107 [] ,
struct V_108 * V_26 )
{
if ( ! V_107 ) {
F_36 ( L_22 ) ;
return;
}
if ( V_107 [ V_101 ] )
V_26 -> V_95 . V_96 . V_97 . V_98 =
F_60 ( V_107 [ V_101 ] ) ;
if ( V_107 [ V_102 ] )
V_26 -> V_95 . V_96 . V_97 . V_98 =
F_60 ( V_107 [ V_102 ] ) ;
if ( V_107 [ V_103 ] ) {
if ( F_61 ( V_107 [ V_103 ] ) )
V_26 -> V_21 = V_27 ;
else
V_26 -> V_21 = V_90 ;
}
}
static int F_62 ( struct V_109 * V_110 , struct V_54 * V_19 ,
struct V_106 * V_111 [] , struct V_106 * V_107 [] )
{
int V_112 ;
struct V_11 * V_113 ;
F_2 () ;
V_113 = F_35 ( V_19 ) ;
F_59 ( V_107 , & V_113 -> V_26 ) ;
F_63 ( V_113 -> V_20 , V_110 ) ;
V_112 = F_64 ( V_19 ) ;
if ( V_112 )
F_36 ( L_23 ) ;
else
F_65 ( & V_113 -> V_36 , & V_114 ) ;
if ( V_113 -> V_26 . V_95 . V_96 . V_97 . V_98 == V_99 ) {
V_113 -> V_26 . V_95 . V_96 . V_97 . V_98 = V_19 -> V_115 ;
V_113 -> V_26 . V_21 = V_27 ;
}
return V_112 ;
}
static int F_66 ( struct V_54 * V_19 , struct V_106 * V_111 [] ,
struct V_106 * V_107 [] )
{
struct V_11 * V_113 ;
F_2 () ;
V_113 = F_35 ( V_19 ) ;
F_59 ( V_107 , & V_113 -> V_26 ) ;
F_67 ( V_19 ) ;
return 0 ;
}
static T_2 F_68 ( const struct V_54 * V_19 )
{
return
F_69 ( 4 ) +
F_69 ( 4 ) +
F_69 ( 2 ) +
0 ;
}
static int T_3 F_70 ( void )
{
return F_71 ( & V_116 ) ;
}
static void T_4 F_72 ( void )
{
struct V_11 * V_19 = NULL ;
struct V_1 * V_3 ;
struct V_1 * V_35 ;
F_73 ( & V_116 ) ;
F_18 () ;
F_3 (list_node, _tmp, &chnl_net_list) {
V_19 = F_19 ( V_3 , struct V_11 , V_36 ) ;
F_4 ( V_3 ) ;
F_15 ( V_19 ) ;
}
F_21 () ;
}
