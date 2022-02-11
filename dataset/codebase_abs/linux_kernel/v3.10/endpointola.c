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
V_2 -> V_35 . V_38 = false ;
F_6 ( & V_2 -> V_35 . V_39 ) ;
F_7 ( & V_2 -> V_35 . V_39 , V_40 ) ;
F_8 ( & V_2 -> V_35 . V_41 , 0 ) ;
V_2 -> V_35 . V_4 = V_4 ;
F_9 ( V_2 -> V_35 . V_4 ) ;
F_10 ( & V_2 -> V_42 ) ;
V_2 -> V_43 = V_6 -> V_16 . V_43 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_47 ;
F_11 ( V_4 , V_48 ) ;
V_2 -> V_49 = V_6 -> V_16 . V_49 ;
F_12 ( V_2 -> V_50 , sizeof( V_2 -> V_50 ) ) ;
F_10 ( & V_2 -> V_51 ) ;
V_12 = F_13 ( 0 , V_5 ) ;
if ( ! V_12 )
goto V_21;
F_14 ( & V_12 -> V_52 , & V_2 -> V_51 ) ;
V_13 = F_15 ( V_2 , V_5 ) ;
if ( V_13 )
goto V_53;
V_2 -> V_54 = V_8 ;
V_2 -> V_55 = V_10 ;
return V_2 ;
V_53:
F_16 ( & V_2 -> V_51 ) ;
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
goto V_56;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_57;
F_20 ( V_2 ) ;
return V_2 ;
V_57:
F_17 ( V_2 ) ;
V_56:
return NULL ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = V_2 -> V_35 . V_4 ;
if ( V_59 -> V_60 )
return;
F_22 ( & V_59 -> V_42 , & V_2 -> V_42 ) ;
if ( F_23 ( V_4 , V_61 ) && F_24 ( V_4 , V_62 ) )
V_4 -> V_63 ++ ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_35 . V_38 = true ;
V_2 -> V_35 . V_4 -> V_64 = V_65 ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 (ep->base.dead, L_1 , return) ;
F_30 ( F_31 ( V_2 -> V_35 . V_4 ) -> V_66 ) ;
F_17 ( V_2 -> V_14 ) ;
F_16 ( & V_2 -> V_51 ) ;
F_17 ( V_2 -> V_54 ) ;
F_17 ( V_2 -> V_55 ) ;
F_32 ( V_2 -> V_8 ) ;
F_33 ( & V_2 -> V_35 . V_39 ) ;
F_34 ( & V_2 -> V_35 . V_41 ) ;
memset ( V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
if ( F_31 ( V_2 -> V_35 . V_4 ) -> V_67 )
F_35 ( V_2 -> V_35 . V_4 ) ;
if ( V_2 -> V_35 . V_4 )
F_36 ( V_2 -> V_35 . V_4 ) ;
F_17 ( V_2 ) ;
F_37 ( V_2 ) ;
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
const union V_68 * V_69 )
{
struct V_1 * V_70 = NULL ;
if ( ( F_4 ( V_2 -> V_35 . V_41 . V_71 ) == V_69 -> V_72 . V_73 ) &&
F_42 ( F_2 ( V_2 -> V_35 . V_4 ) , V_6 ) ) {
if ( F_43 ( & V_2 -> V_35 . V_41 , V_69 ,
F_31 ( V_2 -> V_35 . V_4 ) ) )
V_70 = V_2 ;
}
return V_70 ;
}
static struct V_58 * F_44 (
const struct V_1 * V_2 ,
const union V_68 * V_74 ,
struct V_75 * * V_76 )
{
struct V_58 * V_59 = NULL ;
struct V_58 * V_77 ;
struct V_75 * V_78 = NULL ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
int V_83 ;
int V_84 ;
* V_76 = NULL ;
if ( ! V_2 -> V_35 . V_41 . V_71 )
goto V_85;
V_84 = F_45 ( V_74 -> V_72 . V_73 ) ;
V_83 = F_46 ( F_2 ( V_2 -> V_35 . V_4 ) , V_2 -> V_35 . V_41 . V_71 ,
V_84 ) ;
V_80 = & V_86 [ V_83 ] ;
F_47 ( & V_80 -> V_87 ) ;
F_48 (epb, &head->chain) {
V_77 = F_49 ( V_82 ) ;
if ( V_77 -> V_2 != V_2 || V_84 != V_77 -> V_88 . V_71 )
continue;
V_78 = F_50 ( V_77 , V_74 ) ;
if ( V_78 ) {
V_59 = V_77 ;
* V_76 = V_78 ;
break;
}
}
F_51 ( & V_80 -> V_87 ) ;
V_85:
return V_59 ;
}
struct V_58 * F_52 (
const struct V_1 * V_2 ,
const union V_68 * V_74 ,
struct V_75 * * V_76 )
{
struct V_58 * V_59 ;
F_53 () ;
V_59 = F_44 ( V_2 , V_74 , V_76 ) ;
F_54 () ;
return V_59 ;
}
int F_55 ( struct V_1 * V_2 ,
const union V_68 * V_74 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_35 . V_4 ) ;
V_92 = & V_2 -> V_35 . V_41 ;
F_56 (addr, &bp->address_list, list) {
if ( F_57 ( V_6 , & V_90 -> V_93 , V_74 ) )
return 1 ;
}
return 0 ;
}
static void V_40 ( struct V_94 * V_95 )
{
struct V_1 * V_2 =
F_58 ( V_95 , struct V_1 ,
V_35 . V_39 . V_96 ) ;
struct V_58 * V_59 ;
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_75 * V_76 ;
struct V_97 * V_98 ;
struct V_99 * V_39 ;
T_2 V_100 ;
T_3 V_101 ;
int error = 0 ;
int V_102 = 1 ;
if ( V_2 -> V_35 . V_38 )
return;
V_59 = NULL ;
V_39 = & V_2 -> V_35 . V_39 ;
V_4 = V_2 -> V_35 . V_4 ;
V_6 = F_2 ( V_4 ) ;
while ( NULL != ( V_98 = F_59 ( V_39 ) ) ) {
V_100 = F_60 ( V_98 -> V_103 -> type ) ;
if ( V_102 && ( V_100 . V_98 == V_104 ) ) {
struct V_105 * V_106 ;
V_106 = F_61 ( V_39 ) ;
if ( ! V_106 )
goto V_107;
if ( V_106 -> type == V_108 ) {
V_98 -> V_109 = F_62 ( V_98 -> V_110 ,
V_111 ) ;
V_98 -> V_112 = 1 ;
continue;
}
}
V_107:
if ( NULL == V_98 -> V_59 ) {
V_59 = F_52 ( V_2 ,
F_63 ( V_98 ) ,
& V_76 ) ;
V_98 -> V_59 = V_59 ;
V_98 -> V_76 = V_76 ;
}
V_101 = V_59 ? V_59 -> V_101 : V_113 ;
if ( F_64 ( V_100 . V_98 , V_59 ) && ! V_98 -> V_112 )
continue;
if ( V_59 && F_65 ( V_98 ) )
V_59 -> V_88 . V_114 = V_98 -> V_76 ;
else {
F_66 ( F_2 ( V_2 -> V_35 . V_4 ) , V_115 ) ;
if ( V_59 )
V_59 -> V_116 . V_117 ++ ;
}
if ( V_98 -> V_76 )
V_98 -> V_76 -> V_118 = V_119 ;
error = F_67 ( V_6 , V_120 , V_100 , V_101 ,
V_2 , V_59 , V_98 , V_111 ) ;
if ( error && V_98 )
V_98 -> V_121 = 1 ;
if ( ! F_31 ( V_4 ) -> V_2 )
break;
if ( V_102 )
V_102 = 0 ;
}
}
