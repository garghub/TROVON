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
V_8 = F_3 ( sizeof( * V_8 ) +
sizeof( V_18 ) * V_19 , V_5 ) ;
if ( ! V_8 )
goto V_20;
V_10 = F_3 ( sizeof( * V_10 ) +
V_21 , V_5 ) ;
if ( ! V_10 )
goto V_20;
V_8 -> V_22 . type = V_23 ;
V_8 -> V_22 . V_24 =
F_4 ( sizeof( struct V_25 ) + 2 ) ;
V_8 -> V_26 [ 0 ] = F_4 ( V_27 ) ;
V_10 -> V_22 . type = V_28 ;
V_10 -> V_22 . V_24 =
F_4 ( sizeof( struct V_25 ) ) ;
if ( V_6 -> V_17 . V_29 ) {
V_10 -> V_30 [ 0 ] = V_31 ;
V_10 -> V_30 [ 1 ] = V_32 ;
V_10 -> V_22 . V_24 =
F_4 ( sizeof( struct V_25 ) + 2 ) ;
}
}
V_2 -> V_33 . type = V_34 ;
F_5 ( & V_2 -> V_33 . V_35 , 1 ) ;
V_2 -> V_33 . V_36 = false ;
F_6 ( & V_2 -> V_33 . V_37 ) ;
F_7 ( & V_2 -> V_33 . V_37 , V_38 ) ;
F_8 ( & V_2 -> V_33 . V_39 , 0 ) ;
V_2 -> V_33 . V_4 = V_4 ;
F_9 ( V_2 -> V_33 . V_4 ) ;
F_10 ( & V_2 -> V_40 ) ;
V_2 -> V_41 = V_6 -> V_17 . V_41 ;
V_4 -> V_42 = V_43 ;
V_4 -> V_44 = V_45 ;
F_11 ( V_4 , V_46 ) ;
V_2 -> V_47 = V_6 -> V_17 . V_47 ;
F_12 ( V_2 -> V_48 , sizeof( V_2 -> V_48 ) ) ;
F_10 ( & V_2 -> V_49 ) ;
V_12 = F_13 ( 0 , V_5 ) ;
if ( ! V_12 )
goto V_20;
F_14 ( & V_12 -> V_50 , & V_2 -> V_49 ) ;
V_13 = F_15 ( V_2 , V_5 ) ;
if ( V_13 )
goto V_51;
V_2 -> V_52 = V_8 ;
V_2 -> V_53 = V_10 ;
V_2 -> V_54 = V_6 -> V_17 . V_54 ;
V_2 -> V_55 = V_6 -> V_17 . V_55 ;
return V_2 ;
V_51:
F_16 ( & V_2 -> V_49 ) ;
V_20:
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
goto V_56;
if ( ! F_1 ( V_2 , V_4 , V_5 ) )
goto V_57;
F_19 ( V_2 ) ;
return V_2 ;
V_57:
F_17 ( V_2 ) ;
V_56:
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_3 * V_4 = V_2 -> V_33 . V_4 ;
if ( V_59 -> V_60 )
return;
F_21 ( & V_59 -> V_40 , & V_2 -> V_40 ) ;
if ( F_22 ( V_4 , V_61 ) && F_23 ( V_4 , V_62 ) )
V_4 -> V_63 ++ ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_33 . V_36 = true ;
V_2 -> V_33 . V_4 -> V_64 = V_65 ;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( F_28 ( ! V_2 -> V_33 . V_36 ) ) {
F_29 ( 1 , L_1 , V_2 ) ;
return;
}
F_17 ( V_2 -> V_14 ) ;
F_16 ( & V_2 -> V_49 ) ;
F_17 ( V_2 -> V_52 ) ;
F_17 ( V_2 -> V_53 ) ;
F_30 ( V_2 -> V_8 ) ;
F_31 ( & V_2 -> V_33 . V_37 ) ;
F_32 ( & V_2 -> V_33 . V_39 ) ;
memset ( V_2 -> V_48 , 0 , sizeof( V_2 -> V_48 ) ) ;
V_4 = V_2 -> V_33 . V_4 ;
if ( F_33 ( V_4 ) -> V_66 )
F_34 ( V_4 ) ;
F_33 ( V_4 ) -> V_2 = NULL ;
F_35 ( V_4 ) ;
F_17 ( V_2 ) ;
F_36 ( V_2 ) ;
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
struct V_6 * V_6 ,
const union V_67 * V_68 )
{
struct V_1 * V_69 = NULL ;
if ( ( F_4 ( V_2 -> V_33 . V_39 . V_70 ) == V_68 -> V_71 . V_72 ) &&
F_41 ( F_2 ( V_2 -> V_33 . V_4 ) , V_6 ) ) {
if ( F_42 ( & V_2 -> V_33 . V_39 , V_68 ,
F_33 ( V_2 -> V_33 . V_4 ) ) )
V_69 = V_2 ;
}
return V_69 ;
}
struct V_58 * F_43 (
const struct V_1 * V_2 ,
const union V_67 * V_73 ,
struct V_74 * * V_75 )
{
struct V_58 * V_59 = NULL ;
struct V_74 * V_76 ;
* V_75 = NULL ;
if ( ! V_2 -> V_33 . V_39 . V_70 )
return NULL ;
F_44 () ;
V_76 = F_45 ( V_2 , V_73 ) ;
if ( ! V_76 )
goto V_77;
* V_75 = V_76 ;
V_59 = V_76 -> V_59 ;
V_77:
F_46 () ;
return V_59 ;
}
int F_47 ( struct V_1 * V_2 ,
const union V_67 * V_73 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_33 . V_4 ) ;
V_81 = & V_2 -> V_33 . V_39 ;
F_48 (addr, &bp->address_list, list) {
if ( F_49 ( V_6 , & V_79 -> V_82 , V_73 ) )
return 1 ;
}
return 0 ;
}
static void V_38 ( struct V_83 * V_84 )
{
struct V_1 * V_2 =
F_50 ( V_84 , struct V_1 ,
V_33 . V_37 . V_85 ) ;
struct V_58 * V_59 ;
struct V_3 * V_4 ;
struct V_6 * V_6 ;
struct V_74 * V_75 ;
struct V_86 * V_87 ;
struct V_88 * V_37 ;
union V_89 V_90 ;
enum V_91 V_92 ;
int error = 0 ;
int V_93 = 1 ;
if ( V_2 -> V_33 . V_36 )
return;
V_59 = NULL ;
V_37 = & V_2 -> V_33 . V_37 ;
V_4 = V_2 -> V_33 . V_4 ;
V_6 = F_2 ( V_4 ) ;
while ( NULL != ( V_87 = F_51 ( V_37 ) ) ) {
V_90 = F_52 ( V_87 -> V_94 -> type ) ;
if ( V_93 && ( V_90 . V_87 == V_95 ) ) {
struct V_96 * V_97 ;
V_97 = F_53 ( V_37 ) ;
if ( ! V_97 )
goto V_98;
if ( V_97 -> type == V_99 ) {
V_87 -> V_100 = F_54 ( V_87 -> V_101 ,
V_102 ) ;
V_87 -> V_103 = 1 ;
continue;
}
}
V_98:
if ( NULL == V_87 -> V_59 ) {
V_59 = F_43 ( V_2 ,
F_55 ( V_87 ) ,
& V_75 ) ;
V_87 -> V_59 = V_59 ;
V_87 -> V_75 = V_75 ;
}
V_92 = V_59 ? V_59 -> V_92 : V_104 ;
if ( F_56 ( V_90 . V_87 , V_59 ) && ! V_87 -> V_103 )
continue;
if ( V_59 && F_57 ( V_87 ) )
V_59 -> V_105 . V_106 = V_87 -> V_75 ;
else {
F_58 ( F_2 ( V_2 -> V_33 . V_4 ) , V_107 ) ;
if ( V_59 )
V_59 -> V_108 . V_109 ++ ;
}
if ( V_87 -> V_75 )
V_87 -> V_75 -> V_110 = F_59 () ;
error = F_60 ( V_6 , V_111 , V_90 , V_92 ,
V_2 , V_59 , V_87 , V_102 ) ;
if ( error && V_87 )
V_87 -> V_112 = 1 ;
if ( ! F_33 ( V_4 ) -> V_2 )
break;
if ( V_93 )
V_93 = 0 ;
}
}
