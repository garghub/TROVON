static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 = NULL ;
struct V_10 * V_11 ;
int V_12 ;
V_2 -> V_13 = F_2 ( V_14 , V_5 ) ;
if ( ! V_2 -> V_13 )
return NULL ;
if ( V_15 ) {
V_7 = F_2 ( sizeof( V_16 ) +
sizeof( V_17 ) * V_18 , V_5 ) ;
if ( ! V_7 )
goto V_19;
V_9 = F_2 ( sizeof( V_20 ) +
V_21 , V_5 ) ;
if ( ! V_9 )
goto V_19;
V_7 -> V_22 . type = V_23 ;
V_7 -> V_22 . V_24 =
F_3 ( sizeof( V_25 ) + 2 ) ;
V_7 -> V_26 [ 0 ] = F_3 ( V_27 ) ;
V_9 -> V_22 . type = V_28 ;
V_9 -> V_22 . V_24 = F_3 ( sizeof( V_25 ) ) ;
if ( V_29 ) {
V_9 -> V_30 [ 0 ] = V_31 ;
V_9 -> V_30 [ 1 ] = V_32 ;
V_9 -> V_22 . V_24 =
F_3 ( sizeof( V_25 ) + 2 ) ;
}
}
V_2 -> V_33 . type = V_34 ;
F_4 ( & V_2 -> V_33 . V_35 , 1 ) ;
V_2 -> V_33 . V_36 = 0 ;
V_2 -> V_33 . V_37 = 1 ;
F_5 ( & V_2 -> V_33 . V_38 ) ;
F_6 ( & V_2 -> V_33 . V_38 , V_39 ) ;
F_7 ( & V_2 -> V_33 . V_40 , 0 ) ;
V_2 -> V_33 . V_4 = V_4 ;
F_8 ( V_2 -> V_33 . V_4 ) ;
F_9 ( & V_2 -> V_41 ) ;
V_2 -> V_42 = V_43 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_47 ;
F_10 ( V_4 , V_48 ) ;
V_2 -> V_49 = V_50 ;
F_11 ( & V_2 -> V_51 [ 0 ] , V_52 ) ;
V_2 -> V_53 = V_2 -> V_54 = 0 ;
V_2 -> V_55 = V_56 ;
F_9 ( & V_2 -> V_57 ) ;
V_11 = F_12 ( 0 , V_58 ) ;
if ( ! V_11 )
goto V_19;
F_13 ( & V_11 -> V_59 , & V_2 -> V_57 ) ;
V_12 = F_14 ( V_2 , V_5 ) ;
if ( V_12 )
goto V_60;
V_2 -> V_61 = V_7 ;
V_2 -> V_62 = V_9 ;
return V_2 ;
V_60:
F_15 ( & V_2 -> V_57 ) ;
V_19:
F_16 ( V_7 ) ;
F_16 ( V_9 ) ;
F_16 ( V_2 -> V_13 ) ;
return NULL ;
}
struct V_1 * F_17 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( struct V_1 , V_5 ) ;
if ( ! V_2 )
goto V_63;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_64;
V_2 -> V_33 . V_37 = 1 ;
F_19 ( V_2 ) ;
return V_2 ;
V_64:
F_16 ( V_2 ) ;
V_63:
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
struct V_3 * V_4 = V_2 -> V_33 . V_4 ;
if ( V_66 -> V_67 )
return;
F_21 ( & V_66 -> V_41 , & V_2 -> V_41 ) ;
if ( F_22 ( V_4 , V_68 ) && F_23 ( V_4 , V_69 ) )
V_4 -> V_70 ++ ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_36 = 1 ;
V_2 -> V_33 . V_4 -> V_71 = V_72 ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 (ep->base.dead, L_1 , return) ;
F_29 ( F_30 ( V_2 -> V_33 . V_4 ) -> V_73 ) ;
F_16 ( V_2 -> V_13 ) ;
F_15 ( & V_2 -> V_57 ) ;
F_16 ( V_2 -> V_61 ) ;
F_16 ( V_2 -> V_62 ) ;
F_31 ( V_2 -> V_7 ) ;
F_32 ( & V_2 -> V_33 . V_38 ) ;
F_33 ( & V_2 -> V_33 . V_40 ) ;
if ( F_30 ( V_2 -> V_33 . V_4 ) -> V_74 )
F_34 ( V_2 -> V_33 . V_4 ) ;
if ( V_2 -> V_33 . V_4 )
F_35 ( V_2 -> V_33 . V_4 ) ;
if ( V_2 -> V_33 . V_37 ) {
F_16 ( V_2 ) ;
F_36 ( V_2 ) ;
}
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_33 . V_35 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_39 ( & V_2 -> V_33 . V_35 ) )
F_27 ( V_2 ) ;
}
struct V_1 * F_40 ( struct V_1 * V_2 ,
const union V_75 * V_76 )
{
struct V_1 * V_77 = NULL ;
if ( F_3 ( V_2 -> V_33 . V_40 . V_78 ) == V_76 -> V_79 . V_80 ) {
if ( F_41 ( & V_2 -> V_33 . V_40 , V_76 ,
F_30 ( V_2 -> V_33 . V_4 ) ) )
V_77 = V_2 ;
}
return V_77 ;
}
static struct V_65 * F_42 (
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
if ( ! V_2 -> V_33 . V_40 . V_78 )
goto V_94;
V_93 = F_43 ( V_81 -> V_79 . V_80 ) ;
V_92 = F_44 ( V_2 -> V_33 . V_40 . V_78 , V_93 ) ;
V_87 = & V_95 [ V_92 ] ;
F_45 ( & V_87 -> V_96 ) ;
F_46 (epb, node, &head->chain) {
V_84 = F_47 ( V_89 ) ;
if ( V_84 -> V_2 != V_2 || V_93 != V_84 -> V_97 . V_78 )
continue;
V_85 = F_48 ( V_84 , V_81 ) ;
if ( V_85 ) {
V_66 = V_84 ;
* V_83 = V_85 ;
break;
}
}
F_49 ( & V_87 -> V_96 ) ;
V_94:
return V_66 ;
}
struct V_65 * F_50 (
const struct V_1 * V_2 ,
const union V_75 * V_81 ,
struct V_82 * * V_83 )
{
struct V_65 * V_66 ;
F_51 () ;
V_66 = F_42 ( V_2 , V_81 , V_83 ) ;
F_52 () ;
return V_66 ;
}
int F_53 ( struct V_1 * V_2 ,
const union V_75 * V_81 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
V_101 = & V_2 -> V_33 . V_40 ;
F_54 (addr, &bp->address_list, list) {
if ( F_55 ( & V_99 -> V_102 , V_81 ) )
return 1 ;
}
return 0 ;
}
static void V_39 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_56 ( V_104 , struct V_1 ,
V_33 . V_38 . V_105 ) ;
struct V_65 * V_66 ;
struct V_3 * V_4 ;
struct V_82 * V_83 ;
struct V_106 * V_107 ;
struct V_108 * V_38 ;
T_2 V_109 ;
T_3 V_110 ;
int error = 0 ;
int V_111 = 1 ;
if ( V_2 -> V_33 . V_36 )
return;
V_66 = NULL ;
V_38 = & V_2 -> V_33 . V_38 ;
V_4 = V_2 -> V_33 . V_4 ;
while ( NULL != ( V_107 = F_57 ( V_38 ) ) ) {
V_109 = F_58 ( V_107 -> V_112 -> type ) ;
if ( V_111 && ( V_109 . V_107 == V_113 ) ) {
struct V_114 * V_115 ;
V_115 = F_59 ( V_38 ) ;
if ( ! V_115 )
goto V_116;
if ( V_115 -> type == V_117 ) {
V_107 -> V_118 = F_60 ( V_107 -> V_119 ,
V_120 ) ;
V_107 -> V_121 = 1 ;
continue;
}
}
V_116:
if ( NULL == V_107 -> V_66 ) {
V_66 = F_50 ( V_2 ,
F_61 ( V_107 ) ,
& V_83 ) ;
V_107 -> V_66 = V_66 ;
V_107 -> V_83 = V_83 ;
}
V_110 = V_66 ? V_66 -> V_110 : V_122 ;
if ( F_62 ( V_109 . V_107 , V_66 ) && ! V_107 -> V_121 )
continue;
if ( V_66 && F_63 ( V_107 ) )
V_66 -> V_97 . V_123 = V_107 -> V_83 ;
else
F_64 ( V_124 ) ;
if ( V_107 -> V_83 )
V_107 -> V_83 -> V_125 = V_56 ;
error = F_65 ( V_126 , V_109 , V_110 ,
V_2 , V_66 , V_107 , V_120 ) ;
if ( error && V_107 )
V_107 -> V_127 = 1 ;
if ( ! F_30 ( V_4 ) -> V_2 )
break;
if ( V_111 )
V_111 = 0 ;
}
}
