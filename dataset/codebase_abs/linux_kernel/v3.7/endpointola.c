static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 ;
int V_13 ;
V_2 -> V_14 = F_3 ( V_15 , V_5 ) ;
if ( ! V_2 -> V_14 )
return NULL ;
if ( V_6 -> V_16 . V_17 ) {
V_8 = F_3 ( sizeof( V_18 ) +
sizeof( V_19 ) * V_20 , V_5 ) ;
if ( ! V_8 )
goto V_21;
V_10 = F_3 ( sizeof( V_22 ) +
V_23 , V_5 ) ;
if ( ! V_10 )
goto V_21;
V_8 -> V_24 . type = V_25 ;
V_8 -> V_24 . V_26 =
F_4 ( sizeof( V_27 ) + 2 ) ;
V_8 -> V_28 [ 0 ] = F_4 ( V_29 ) ;
V_10 -> V_24 . type = V_30 ;
V_10 -> V_24 . V_26 = F_4 ( sizeof( V_27 ) ) ;
if ( V_6 -> V_16 . V_31 ) {
V_10 -> V_32 [ 0 ] = V_33 ;
V_10 -> V_32 [ 1 ] = V_34 ;
V_10 -> V_24 . V_26 =
F_4 ( sizeof( V_27 ) + 2 ) ;
}
}
V_2 -> V_35 . type = V_36 ;
F_5 ( & V_2 -> V_35 . V_37 , 1 ) ;
V_2 -> V_35 . V_38 = 0 ;
V_2 -> V_35 . V_39 = 1 ;
F_6 ( & V_2 -> V_35 . V_40 ) ;
F_7 ( & V_2 -> V_35 . V_40 , V_41 ) ;
F_8 ( & V_2 -> V_35 . V_42 , 0 ) ;
V_2 -> V_35 . V_4 = V_4 ;
F_9 ( V_2 -> V_35 . V_4 ) ;
F_10 ( & V_2 -> V_43 ) ;
V_2 -> V_44 = V_6 -> V_16 . V_44 ;
V_4 -> V_45 = V_46 ;
V_4 -> V_47 = V_48 ;
F_11 ( V_4 , V_49 ) ;
V_2 -> V_50 = V_6 -> V_16 . V_50 ;
F_12 ( & V_2 -> V_51 [ 0 ] , V_52 ) ;
V_2 -> V_53 = V_2 -> V_54 = 0 ;
V_2 -> V_55 = V_56 ;
F_10 ( & V_2 -> V_57 ) ;
V_12 = F_13 ( 0 , V_58 ) ;
if ( ! V_12 )
goto V_21;
F_14 ( & V_12 -> V_59 , & V_2 -> V_57 ) ;
V_13 = F_15 ( V_2 , V_5 ) ;
if ( V_13 )
goto V_60;
V_2 -> V_61 = V_8 ;
V_2 -> V_62 = V_10 ;
return V_2 ;
V_60:
F_16 ( & V_2 -> V_57 ) ;
V_21:
F_17 ( V_8 ) ;
F_17 ( V_10 ) ;
F_17 ( V_2 -> V_14 ) ;
return NULL ;
}
struct V_1 * F_18 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_1 * V_2 ;
V_2 = F_19 ( struct V_1 , V_5 ) ;
if ( ! V_2 )
goto V_63;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_64;
V_2 -> V_35 . V_39 = 1 ;
F_20 ( V_2 ) ;
return V_2 ;
V_64:
F_17 ( V_2 ) ;
V_63:
return NULL ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = V_2 -> V_35 . V_4 ;
if ( V_66 -> V_67 )
return;
F_22 ( & V_66 -> V_43 , & V_2 -> V_43 ) ;
if ( F_23 ( V_4 , V_68 ) && F_24 ( V_4 , V_69 ) )
V_4 -> V_70 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 . V_38 = 1 ;
V_2 -> V_35 . V_4 -> V_71 = V_72 ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 (ep->base.dead, L_1 , return) ;
F_30 ( F_31 ( V_2 -> V_35 . V_4 ) -> V_73 ) ;
F_17 ( V_2 -> V_14 ) ;
F_16 ( & V_2 -> V_57 ) ;
F_17 ( V_2 -> V_61 ) ;
F_17 ( V_2 -> V_62 ) ;
F_32 ( V_2 -> V_8 ) ;
F_33 ( & V_2 -> V_35 . V_40 ) ;
F_34 ( & V_2 -> V_35 . V_42 ) ;
if ( F_31 ( V_2 -> V_35 . V_4 ) -> V_74 )
F_35 ( V_2 -> V_35 . V_4 ) ;
if ( V_2 -> V_35 . V_4 )
F_36 ( V_2 -> V_35 . V_4 ) ;
if ( V_2 -> V_35 . V_39 ) {
F_17 ( V_2 ) ;
F_37 ( V_2 ) ;
}
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_35 . V_37 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( F_40 ( & V_2 -> V_35 . V_37 ) )
F_28 ( V_2 ) ;
}
struct V_1 * F_41 ( struct V_1 * V_2 ,
struct V_6 * V_6 ,
const union V_75 * V_76 )
{
struct V_1 * V_77 = NULL ;
if ( ( F_4 ( V_2 -> V_35 . V_42 . V_78 ) == V_76 -> V_79 . V_80 ) &&
F_42 ( F_2 ( V_2 -> V_35 . V_4 ) , V_6 ) ) {
if ( F_43 ( & V_2 -> V_35 . V_42 , V_76 ,
F_31 ( V_2 -> V_35 . V_4 ) ) )
V_77 = V_2 ;
}
return V_77 ;
}
static struct V_65 * F_44 (
const struct V_1 * V_2 ,
const union V_75 * V_81 ,
struct V_82 * * V_83 )
{
struct V_65 * V_66 = NULL ;
struct V_65 * V_84 ;
struct V_82 * V_85 = NULL ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_91 ;
int V_92 ;
int V_93 ;
* V_83 = NULL ;
if ( ! V_2 -> V_35 . V_42 . V_78 )
goto V_94;
V_93 = F_45 ( V_81 -> V_79 . V_80 ) ;
V_92 = F_46 ( F_2 ( V_2 -> V_35 . V_4 ) , V_2 -> V_35 . V_42 . V_78 ,
V_93 ) ;
V_87 = & V_95 [ V_92 ] ;
F_47 ( & V_87 -> V_96 ) ;
F_48 (epb, node, &head->chain) {
V_84 = F_49 ( V_89 ) ;
if ( V_84 -> V_2 != V_2 || V_93 != V_84 -> V_97 . V_78 )
continue;
V_85 = F_50 ( V_84 , V_81 ) ;
if ( V_85 ) {
V_66 = V_84 ;
* V_83 = V_85 ;
break;
}
}
F_51 ( & V_87 -> V_96 ) ;
V_94:
return V_66 ;
}
struct V_65 * F_52 (
const struct V_1 * V_2 ,
const union V_75 * V_81 ,
struct V_82 * * V_83 )
{
struct V_65 * V_66 ;
F_53 () ;
V_66 = F_44 ( V_2 , V_81 , V_83 ) ;
F_54 () ;
return V_66 ;
}
int F_55 ( struct V_1 * V_2 ,
const union V_75 * V_81 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_35 . V_4 ) ;
V_101 = & V_2 -> V_35 . V_42 ;
F_56 (addr, &bp->address_list, list) {
if ( F_57 ( V_6 , & V_99 -> V_102 , V_81 ) )
return 1 ;
}
return 0 ;
}
static void V_41 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_58 ( V_104 , struct V_1 ,
V_35 . V_40 . V_105 ) ;
struct V_65 * V_66 ;
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_82 * V_83 ;
struct V_106 * V_107 ;
struct V_108 * V_40 ;
T_2 V_109 ;
T_3 V_110 ;
int error = 0 ;
int V_111 = 1 ;
if ( V_2 -> V_35 . V_38 )
return;
V_66 = NULL ;
V_40 = & V_2 -> V_35 . V_40 ;
V_4 = V_2 -> V_35 . V_4 ;
V_6 = F_2 ( V_4 ) ;
while ( NULL != ( V_107 = F_59 ( V_40 ) ) ) {
V_109 = F_60 ( V_107 -> V_112 -> type ) ;
if ( V_111 && ( V_109 . V_107 == V_113 ) ) {
struct V_114 * V_115 ;
V_115 = F_61 ( V_40 ) ;
if ( ! V_115 )
goto V_116;
if ( V_115 -> type == V_117 ) {
V_107 -> V_118 = F_62 ( V_107 -> V_119 ,
V_120 ) ;
V_107 -> V_121 = 1 ;
continue;
}
}
V_116:
if ( NULL == V_107 -> V_66 ) {
V_66 = F_52 ( V_2 ,
F_63 ( V_107 ) ,
& V_83 ) ;
V_107 -> V_66 = V_66 ;
V_107 -> V_83 = V_83 ;
}
V_110 = V_66 ? V_66 -> V_110 : V_122 ;
if ( F_64 ( V_109 . V_107 , V_66 ) && ! V_107 -> V_121 )
continue;
if ( V_66 && F_65 ( V_107 ) )
V_66 -> V_97 . V_123 = V_107 -> V_83 ;
else
F_66 ( F_2 ( V_2 -> V_35 . V_4 ) , V_124 ) ;
if ( V_107 -> V_83 )
V_107 -> V_83 -> V_125 = V_56 ;
error = F_67 ( V_6 , V_126 , V_109 , V_110 ,
V_2 , V_66 , V_107 , V_120 ) ;
if ( error && V_107 )
V_107 -> V_127 = 1 ;
if ( ! F_31 ( V_4 ) -> V_2 )
break;
if ( V_111 )
V_111 = 0 ;
}
}
