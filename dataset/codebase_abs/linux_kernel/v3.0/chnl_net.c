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
struct V_11 * V_12 = F_7 ( V_6 , struct V_11 , V_13 ) ;
int V_14 ;
int V_15 = 0 ;
const T_1 * V_16 ;
T_1 V_17 ;
V_12 = F_7 ( V_6 , struct V_11 , V_13 ) ;
if ( ! V_12 )
return - V_18 ;
V_10 = (struct V_9 * ) F_8 ( V_8 ) ;
V_14 = V_10 -> V_19 ;
V_10 -> V_20 = V_12 -> V_21 ;
V_16 = F_9 ( V_10 , 0 , 1 , & V_17 ) ;
if ( ! V_16 )
return - V_18 ;
switch ( * V_16 >> 4 ) {
case 4 :
V_10 -> V_22 = F_10 ( V_23 ) ;
break;
case 6 :
V_10 -> V_22 = F_10 ( V_24 ) ;
break;
default:
return - V_18 ;
}
if ( V_12 -> V_25 . V_22 == V_26 )
V_10 -> V_27 = V_28 ;
else
V_10 -> V_27 = V_29 ;
if ( F_11 () )
F_12 ( V_10 ) ;
else
F_13 ( V_10 ) ;
V_12 -> V_21 -> V_30 . V_31 ++ ;
V_12 -> V_21 -> V_30 . V_32 += V_14 ;
return V_15 ;
}
static int F_14 ( struct V_11 * V_20 )
{
F_2 () ;
if ( V_20 -> V_21 )
F_15 ( V_20 -> V_21 ) ;
return 0 ;
}
static void F_16 ( struct V_33 * V_34 )
{
struct V_11 * V_20 = NULL ;
struct V_1 * V_3 ;
struct V_1 * V_35 ;
F_17 () ;
F_3 (list_node, _tmp, &chnl_net_list) {
V_20 = F_18 ( V_3 , struct V_11 , V_36 ) ;
if ( V_20 -> V_37 == V_38 )
F_19 ( V_20 -> V_21 ) ;
}
F_20 () ;
}
static void F_21 ( struct V_5 * V_39 )
{
struct V_11 * V_12 = F_7 ( V_39 , struct V_11 , V_13 ) ;
F_22 ( V_12 -> V_21 ) ;
}
static void F_23 ( struct V_5 * V_39 )
{
struct V_11 * V_12 = F_7 ( V_39 , struct V_11 , V_13 ) ;
F_24 ( V_12 -> V_21 ) ;
}
static void F_25 ( struct V_5 * V_6 , enum V_40 V_41 ,
int V_42 )
{
struct V_11 * V_12 = F_7 ( V_6 , struct V_11 , V_13 ) ;
F_26 ( L_1 ,
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
F_27 ( V_12 -> V_21 ) ;
break;
case V_46 :
V_12 -> V_37 = V_50 ;
break;
case V_47 :
V_12 -> V_37 = V_50 ;
F_28 ( & V_12 -> V_51 ) ;
break;
case V_48 :
V_12 -> V_37 = V_38 ;
F_29 ( V_12 -> V_21 ) ;
F_30 ( & V_52 ) ;
break;
case V_43 :
V_12 -> V_49 = true ;
F_31 ( V_12 -> V_21 ) ;
break;
case V_44 :
F_32 ( & V_12 -> V_13 , F_21 , F_23 ) ;
V_12 -> V_37 = V_53 ;
V_12 -> V_49 = true ;
F_31 ( V_12 -> V_21 ) ;
F_28 ( & V_12 -> V_51 ) ;
break;
default:
break;
}
}
static int F_33 ( struct V_9 * V_10 , struct V_54 * V_20 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 = NULL ;
int V_19 ;
int V_55 = - 1 ;
V_12 = F_34 ( V_20 ) ;
if ( V_10 -> V_19 > V_12 -> V_21 -> V_56 ) {
F_35 ( L_9 ) ;
return - V_57 ;
}
if ( ! V_12 -> V_49 ) {
F_26 ( L_10 ) ;
return V_58 ;
}
if ( V_12 -> V_25 . V_22 == V_26 )
F_36 ( F_37 ( V_10 ) -> V_59 , F_37 ( V_10 ) -> V_60 ) ;
V_19 = V_10 -> V_19 ;
V_8 = F_38 ( V_61 , ( void * ) V_10 ) ;
V_55 = V_12 -> V_13 . V_62 -> V_63 ( V_12 -> V_13 . V_62 , V_8 ) ;
if ( V_55 ) {
if ( V_55 == - V_64 )
V_55 = V_58 ;
return V_55 ;
}
V_20 -> V_30 . V_65 ++ ;
V_20 -> V_30 . V_66 += V_19 ;
return V_67 ;
}
static int F_39 ( struct V_54 * V_20 )
{
struct V_11 * V_12 = NULL ;
int V_55 = - 1 ;
int V_68 , V_69 , V_70 , V_56 ;
struct V_54 * V_71 ;
F_2 () ;
V_12 = F_34 ( V_20 ) ;
if ( ! V_12 ) {
F_26 ( L_11 ) ;
return - V_72 ;
}
if ( V_12 -> V_37 != V_73 ) {
V_12 -> V_37 = V_73 ;
V_55 = F_40 ( F_41 ( V_20 ) , & V_12 -> V_25 ,
& V_12 -> V_13 , & V_68 ,
& V_69 , & V_70 ) ;
if ( V_55 != 0 ) {
F_26 ( L_12
L_13
L_14 ,
V_55 ) ;
goto error;
}
V_71 = F_42 ( F_41 ( V_20 ) , V_68 ) ;
if ( V_71 == NULL ) {
F_26 ( L_15 ) ;
V_55 = - V_72 ;
goto error;
}
V_20 -> V_74 = V_70 + V_71 -> V_74 ;
V_20 -> V_75 = V_69 + V_71 -> V_75 +
V_71 -> V_74 ;
V_56 = F_43 ( int , V_20 -> V_56 , V_71 -> V_56 - ( V_69 + V_70 ) ) ;
V_56 = F_43 ( int , V_76 , V_56 ) ;
F_44 ( V_20 , V_56 ) ;
F_24 ( V_71 ) ;
if ( V_56 < 100 ) {
F_35 ( L_16 , V_56 ) ;
V_55 = - V_72 ;
goto error;
}
}
F_20 () ;
V_55 = F_45 ( V_12 -> V_51 ,
V_12 -> V_37 != V_73 ,
V_77 ) ;
F_17 () ;
if ( V_55 == - V_78 ) {
F_26 ( L_17 ) ;
V_55 = - V_78 ;
goto error;
}
if ( V_55 == 0 ) {
F_26 ( L_18 ) ;
F_46 ( F_41 ( V_20 ) , & V_12 -> V_13 ) ;
V_12 -> V_37 = V_50 ;
F_26 ( L_19 ) ;
V_55 = - V_79 ;
goto error;
}
if ( V_12 -> V_37 != V_53 ) {
F_26 ( L_20 ) ;
V_55 = - V_80 ;
goto error;
}
F_26 ( L_21 ) ;
return 0 ;
error:
F_46 ( F_41 ( V_20 ) , & V_12 -> V_13 ) ;
V_12 -> V_37 = V_50 ;
F_26 ( L_19 ) ;
return V_55 ;
}
static int F_47 ( struct V_54 * V_20 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_34 ( V_20 ) ;
V_12 -> V_37 = V_50 ;
F_46 ( F_41 ( V_20 ) , & V_12 -> V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_54 * V_20 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_34 ( V_20 ) ;
strncpy ( V_12 -> V_81 , V_20 -> V_81 , sizeof( V_12 -> V_81 ) ) ;
return 0 ;
}
static void F_49 ( struct V_54 * V_20 )
{
struct V_11 * V_12 ;
F_2 () ;
V_12 = F_34 ( V_20 ) ;
F_1 ( & V_12 -> V_36 ) ;
}
static void F_50 ( struct V_54 * V_20 )
{
struct V_11 * V_12 = F_34 ( V_20 ) ;
F_51 ( & V_12 -> V_13 ) ;
F_52 ( V_20 ) ;
}
static void F_53 ( struct V_54 * V_20 )
{
struct V_11 * V_12 ;
V_20 -> V_82 = & V_82 ;
V_20 -> V_83 = F_50 ;
V_20 -> V_84 |= V_85 ;
V_20 -> V_84 |= V_86 ;
V_20 -> V_56 = V_76 ;
V_20 -> V_87 = V_88 ;
V_12 = F_34 ( V_20 ) ;
V_12 -> V_13 . V_89 = F_6 ;
V_12 -> V_13 . V_90 = F_25 ;
V_12 -> V_21 = V_20 ;
V_12 -> V_25 . V_22 = V_91 ;
V_12 -> V_25 . V_92 = V_93 ;
V_12 -> V_25 . V_94 = V_95 ;
V_12 -> V_25 . V_96 . V_97 . V_98 . V_99 = 0 ;
V_12 -> V_49 = false ;
F_54 ( & V_12 -> V_51 ) ;
}
static int F_55 ( struct V_9 * V_10 , const struct V_54 * V_20 )
{
struct V_11 * V_12 ;
T_1 V_100 ;
V_12 = F_34 ( V_20 ) ;
F_56 ( V_10 , V_101 ,
V_12 -> V_25 . V_96 . V_97 . V_98 . V_99 ) ;
F_56 ( V_10 , V_102 ,
V_12 -> V_25 . V_96 . V_97 . V_98 . V_99 ) ;
V_100 = V_12 -> V_25 . V_22 == V_26 ;
F_57 ( V_10 , V_103 , V_100 ) ;
return 0 ;
V_104:
return - V_105 ;
}
static void F_58 ( struct V_106 * V_107 [] ,
struct V_108 * V_25 )
{
if ( ! V_107 ) {
F_35 ( L_22 ) ;
return;
}
if ( V_107 [ V_101 ] )
V_25 -> V_96 . V_97 . V_98 . V_99 =
F_59 ( V_107 [ V_101 ] ) ;
if ( V_107 [ V_102 ] )
V_25 -> V_96 . V_97 . V_98 . V_99 =
F_59 ( V_107 [ V_102 ] ) ;
if ( V_107 [ V_103 ] ) {
if ( F_60 ( V_107 [ V_103 ] ) )
V_25 -> V_22 = V_26 ;
else
V_25 -> V_22 = V_91 ;
}
}
static int F_61 ( struct V_109 * V_110 , struct V_54 * V_20 ,
struct V_106 * V_111 [] , struct V_106 * V_107 [] )
{
int V_112 ;
struct V_11 * V_113 ;
F_2 () ;
V_113 = F_34 ( V_20 ) ;
F_58 ( V_107 , & V_113 -> V_25 ) ;
F_62 ( V_113 -> V_21 , V_110 ) ;
V_112 = F_63 ( V_20 ) ;
if ( V_112 )
F_35 ( L_23 ) ;
else
F_64 ( & V_113 -> V_36 , & V_114 ) ;
if ( V_113 -> V_25 . V_96 . V_97 . V_98 . V_99 == 0 )
V_113 -> V_25 . V_96 . V_97 . V_98 . V_99 = V_20 -> V_115 ;
return V_112 ;
}
static int F_65 ( struct V_54 * V_20 , struct V_106 * V_111 [] ,
struct V_106 * V_107 [] )
{
struct V_11 * V_113 ;
F_2 () ;
V_113 = F_34 ( V_20 ) ;
F_58 ( V_107 , & V_113 -> V_25 ) ;
F_66 ( V_20 ) ;
return 0 ;
}
static T_2 F_67 ( const struct V_54 * V_20 )
{
return
F_68 ( 4 ) +
F_68 ( 4 ) +
F_68 ( 2 ) +
0 ;
}
static int T_3 F_69 ( void )
{
return F_70 ( & V_116 ) ;
}
static void T_4 F_71 ( void )
{
struct V_11 * V_20 = NULL ;
struct V_1 * V_3 ;
struct V_1 * V_35 ;
F_72 ( & V_116 ) ;
F_17 () ;
F_3 (list_node, _tmp, &chnl_net_list) {
V_20 = F_18 ( V_3 , struct V_11 , V_36 ) ;
F_4 ( V_3 ) ;
F_14 ( V_20 ) ;
}
F_20 () ;
}
