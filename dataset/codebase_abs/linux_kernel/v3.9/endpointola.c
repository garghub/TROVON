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
F_12 ( V_2 -> V_51 , sizeof( V_2 -> V_51 ) ) ;
F_10 ( & V_2 -> V_52 ) ;
V_12 = F_13 ( 0 , V_5 ) ;
if ( ! V_12 )
goto V_21;
F_14 ( & V_12 -> V_53 , & V_2 -> V_52 ) ;
V_13 = F_15 ( V_2 , V_5 ) ;
if ( V_13 )
goto V_54;
V_2 -> V_55 = V_8 ;
V_2 -> V_56 = V_10 ;
return V_2 ;
V_54:
F_16 ( & V_2 -> V_52 ) ;
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
goto V_57;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_58;
V_2 -> V_35 . V_39 = 1 ;
F_20 ( V_2 ) ;
return V_2 ;
V_58:
F_17 ( V_2 ) ;
V_57:
return NULL ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_35 . V_4 ;
if ( V_60 -> V_61 )
return;
F_22 ( & V_60 -> V_43 , & V_2 -> V_43 ) ;
if ( F_23 ( V_4 , V_62 ) && F_24 ( V_4 , V_63 ) )
V_4 -> V_64 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 . V_38 = 1 ;
V_2 -> V_35 . V_4 -> V_65 = V_66 ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 (ep->base.dead, L_1 , return) ;
F_30 ( F_31 ( V_2 -> V_35 . V_4 ) -> V_67 ) ;
F_17 ( V_2 -> V_14 ) ;
F_16 ( & V_2 -> V_52 ) ;
F_17 ( V_2 -> V_55 ) ;
F_17 ( V_2 -> V_56 ) ;
F_32 ( V_2 -> V_8 ) ;
F_33 ( & V_2 -> V_35 . V_40 ) ;
F_34 ( & V_2 -> V_35 . V_42 ) ;
memset ( V_2 -> V_51 , 0 , sizeof( V_2 -> V_51 ) ) ;
if ( F_31 ( V_2 -> V_35 . V_4 ) -> V_68 )
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
const union V_69 * V_70 )
{
struct V_1 * V_71 = NULL ;
if ( ( F_4 ( V_2 -> V_35 . V_42 . V_72 ) == V_70 -> V_73 . V_74 ) &&
F_42 ( F_2 ( V_2 -> V_35 . V_4 ) , V_6 ) ) {
if ( F_43 ( & V_2 -> V_35 . V_42 , V_70 ,
F_31 ( V_2 -> V_35 . V_4 ) ) )
V_71 = V_2 ;
}
return V_71 ;
}
static struct V_59 * F_44 (
const struct V_1 * V_2 ,
const union V_69 * V_75 ,
struct V_76 * * V_77 )
{
struct V_59 * V_60 = NULL ;
struct V_59 * V_78 ;
struct V_76 * V_79 = NULL ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
int V_84 ;
int V_85 ;
* V_77 = NULL ;
if ( ! V_2 -> V_35 . V_42 . V_72 )
goto V_86;
V_85 = F_45 ( V_75 -> V_73 . V_74 ) ;
V_84 = F_46 ( F_2 ( V_2 -> V_35 . V_4 ) , V_2 -> V_35 . V_42 . V_72 ,
V_85 ) ;
V_81 = & V_87 [ V_84 ] ;
F_47 ( & V_81 -> V_88 ) ;
F_48 (epb, &head->chain) {
V_78 = F_49 ( V_83 ) ;
if ( V_78 -> V_2 != V_2 || V_85 != V_78 -> V_89 . V_72 )
continue;
V_79 = F_50 ( V_78 , V_75 ) ;
if ( V_79 ) {
V_60 = V_78 ;
* V_77 = V_79 ;
break;
}
}
F_51 ( & V_81 -> V_88 ) ;
V_86:
return V_60 ;
}
struct V_59 * F_52 (
const struct V_1 * V_2 ,
const union V_69 * V_75 ,
struct V_76 * * V_77 )
{
struct V_59 * V_60 ;
F_53 () ;
V_60 = F_44 ( V_2 , V_75 , V_77 ) ;
F_54 () ;
return V_60 ;
}
int F_55 ( struct V_1 * V_2 ,
const union V_69 * V_75 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_35 . V_4 ) ;
V_93 = & V_2 -> V_35 . V_42 ;
F_56 (addr, &bp->address_list, list) {
if ( F_57 ( V_6 , & V_91 -> V_94 , V_75 ) )
return 1 ;
}
return 0 ;
}
static void V_41 ( struct V_95 * V_96 )
{
struct V_1 * V_2 =
F_58 ( V_96 , struct V_1 ,
V_35 . V_40 . V_97 ) ;
struct V_59 * V_60 ;
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_76 * V_77 ;
struct V_98 * V_99 ;
struct V_100 * V_40 ;
T_2 V_101 ;
T_3 V_102 ;
int error = 0 ;
int V_103 = 1 ;
if ( V_2 -> V_35 . V_38 )
return;
V_60 = NULL ;
V_40 = & V_2 -> V_35 . V_40 ;
V_4 = V_2 -> V_35 . V_4 ;
V_6 = F_2 ( V_4 ) ;
while ( NULL != ( V_99 = F_59 ( V_40 ) ) ) {
V_101 = F_60 ( V_99 -> V_104 -> type ) ;
if ( V_103 && ( V_101 . V_99 == V_105 ) ) {
struct V_106 * V_107 ;
V_107 = F_61 ( V_40 ) ;
if ( ! V_107 )
goto V_108;
if ( V_107 -> type == V_109 ) {
V_99 -> V_110 = F_62 ( V_99 -> V_111 ,
V_112 ) ;
V_99 -> V_113 = 1 ;
continue;
}
}
V_108:
if ( NULL == V_99 -> V_60 ) {
V_60 = F_52 ( V_2 ,
F_63 ( V_99 ) ,
& V_77 ) ;
V_99 -> V_60 = V_60 ;
V_99 -> V_77 = V_77 ;
}
V_102 = V_60 ? V_60 -> V_102 : V_114 ;
if ( F_64 ( V_101 . V_99 , V_60 ) && ! V_99 -> V_113 )
continue;
if ( V_60 && F_65 ( V_99 ) )
V_60 -> V_89 . V_115 = V_99 -> V_77 ;
else {
F_66 ( F_2 ( V_2 -> V_35 . V_4 ) , V_116 ) ;
if ( V_60 )
V_60 -> V_117 . V_118 ++ ;
}
if ( V_99 -> V_77 )
V_99 -> V_77 -> V_119 = V_120 ;
error = F_67 ( V_6 , V_121 , V_101 , V_102 ,
V_2 , V_60 , V_99 , V_112 ) ;
if ( error && V_99 )
V_99 -> V_122 = 1 ;
if ( ! F_31 ( V_4 ) -> V_2 )
break;
if ( V_103 )
V_103 = 0 ;
}
}
