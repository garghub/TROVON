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
V_2 -> V_16 = V_6 -> V_17 . V_16 ;
if ( V_2 -> V_16 ) {
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
if ( V_6 -> V_17 . V_31 ) {
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
V_2 -> V_43 = V_6 -> V_17 . V_43 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_47 ;
F_11 ( V_4 , V_48 ) ;
V_2 -> V_49 = V_6 -> V_17 . V_49 ;
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
V_2 -> V_56 = V_6 -> V_17 . V_56 ;
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
V_2 = F_3 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
goto V_57;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_58;
F_19 ( V_2 ) ;
return V_2 ;
V_58:
F_17 ( V_2 ) ;
V_57:
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_35 . V_4 ;
if ( V_60 -> V_61 )
return;
F_21 ( & V_60 -> V_42 , & V_2 -> V_42 ) ;
if ( F_22 ( V_4 , V_62 ) && F_23 ( V_4 , V_63 ) )
V_4 -> V_64 ++ ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_35 . V_38 = true ;
V_2 -> V_35 . V_4 -> V_65 = V_66 ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_28 ( ! V_2 -> V_35 . V_38 ) ) {
F_29 ( 1 , L_1 , V_2 ) ;
return;
}
F_17 ( V_2 -> V_14 ) ;
F_16 ( & V_2 -> V_51 ) ;
F_17 ( V_2 -> V_54 ) ;
F_17 ( V_2 -> V_55 ) ;
F_30 ( V_2 -> V_8 ) ;
F_31 ( & V_2 -> V_35 . V_39 ) ;
F_32 ( & V_2 -> V_35 . V_41 ) ;
memset ( V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
V_4 = V_2 -> V_35 . V_4 ;
if ( V_4 != NULL ) {
if ( F_33 ( V_4 ) -> V_67 )
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
}
F_17 ( V_2 ) ;
F_36 ( V_2 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_35 . V_37 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
if ( F_39 ( & V_2 -> V_35 . V_37 ) )
F_27 ( V_2 ) ;
}
struct V_1 * F_40 ( struct V_1 * V_2 ,
struct V_6 * V_6 ,
const union V_68 * V_69 )
{
struct V_1 * V_70 = NULL ;
if ( ( F_4 ( V_2 -> V_35 . V_41 . V_71 ) == V_69 -> V_72 . V_73 ) &&
F_41 ( F_2 ( V_2 -> V_35 . V_4 ) , V_6 ) ) {
if ( F_42 ( & V_2 -> V_35 . V_41 , V_69 ,
F_33 ( V_2 -> V_35 . V_4 ) ) )
V_70 = V_2 ;
}
return V_70 ;
}
struct V_59 * F_43 (
const struct V_1 * V_2 ,
const union V_68 * V_74 ,
struct V_75 * * V_76 )
{
struct V_59 * V_60 = NULL ;
struct V_75 * V_77 ;
* V_76 = NULL ;
if ( ! V_2 -> V_35 . V_41 . V_71 )
goto V_78;
V_77 = F_44 ( V_2 , V_74 ) ;
if ( ! V_77 )
goto V_78;
* V_76 = V_77 ;
V_60 = V_77 -> V_60 ;
V_78:
return V_60 ;
}
int F_45 ( struct V_1 * V_2 ,
const union V_68 * V_74 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_35 . V_4 ) ;
V_82 = & V_2 -> V_35 . V_41 ;
F_46 (addr, &bp->address_list, list) {
if ( F_47 ( V_6 , & V_80 -> V_83 , V_74 ) )
return 1 ;
}
return 0 ;
}
static void V_40 ( struct V_84 * V_85 )
{
struct V_1 * V_2 =
F_48 ( V_85 , struct V_1 ,
V_35 . V_39 . V_86 ) ;
struct V_59 * V_60 ;
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_75 * V_76 ;
struct V_87 * V_88 ;
struct V_89 * V_39 ;
T_2 V_90 ;
T_3 V_91 ;
int error = 0 ;
int V_92 = 1 ;
if ( V_2 -> V_35 . V_38 )
return;
V_60 = NULL ;
V_39 = & V_2 -> V_35 . V_39 ;
V_4 = V_2 -> V_35 . V_4 ;
V_6 = F_2 ( V_4 ) ;
while ( NULL != ( V_88 = F_49 ( V_39 ) ) ) {
V_90 = F_50 ( V_88 -> V_93 -> type ) ;
if ( V_92 && ( V_90 . V_88 == V_94 ) ) {
struct V_95 * V_96 ;
V_96 = F_51 ( V_39 ) ;
if ( ! V_96 )
goto V_97;
if ( V_96 -> type == V_98 ) {
V_88 -> V_99 = F_52 ( V_88 -> V_100 ,
V_101 ) ;
V_88 -> V_102 = 1 ;
continue;
}
}
V_97:
if ( NULL == V_88 -> V_60 ) {
V_60 = F_43 ( V_2 ,
F_53 ( V_88 ) ,
& V_76 ) ;
V_88 -> V_60 = V_60 ;
V_88 -> V_76 = V_76 ;
}
V_91 = V_60 ? V_60 -> V_91 : V_103 ;
if ( F_54 ( V_90 . V_88 , V_60 ) && ! V_88 -> V_102 )
continue;
if ( V_60 && F_55 ( V_88 ) )
V_60 -> V_104 . V_105 = V_88 -> V_76 ;
else {
F_56 ( F_2 ( V_2 -> V_35 . V_4 ) , V_106 ) ;
if ( V_60 )
V_60 -> V_107 . V_108 ++ ;
}
if ( V_88 -> V_76 )
V_88 -> V_76 -> V_109 = F_57 () ;
error = F_58 ( V_6 , V_110 , V_90 , V_91 ,
V_2 , V_60 , V_88 , V_101 ) ;
if ( error && V_88 )
V_88 -> V_111 = 1 ;
if ( ! F_33 ( V_4 ) -> V_2 )
break;
if ( V_92 )
V_92 = 0 ;
}
}
