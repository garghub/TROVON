void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 type ,
const T_1 * V_6 , const T_1 * V_7 )
{
struct V_8 V_9 ;
unsigned int V_10 = 0 ;
V_9 . type = type ;
switch ( type ) {
case V_11 :
V_9 . V_12 = V_13 ;
break;
case V_14 :
case V_15 :
case V_16 :
V_9 . V_12 = V_17 ;
break;
case V_18 :
V_9 . V_12 = V_19 ;
break;
default:
V_9 . V_12 = V_20 ;
break;
}
memset ( V_9 . V_6 , 0 , sizeof( V_9 . V_6 ) ) ;
if ( V_6 )
memcpy ( V_9 . V_6 , V_6 , V_21 ) ;
memset ( V_9 . V_7 , 0 , sizeof( V_9 . V_7 ) ) ;
if ( V_7 )
memcpy ( V_9 . V_7 , V_7 , V_21 ) ;
V_10 |= V_22 ;
if ( V_6 || ( ! V_2 -> V_23 && ! V_2 -> V_24 ) )
V_10 |= V_25 ;
if ( V_7 || ( ! V_2 -> V_23 && ! V_2 -> V_24 ) )
V_10 |= V_26 ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_4 , & V_9 , V_10 ) ;
}
void F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_30 * V_31 ,
T_2 V_32 )
{
struct V_33 V_34 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
V_34 . V_35 = V_31 -> V_36 ;
V_34 . V_37 = V_31 -> V_38 ;
V_34 . V_39 = V_31 -> V_40 ? V_41 : V_42 ;
V_34 . V_43 = V_44 ;
V_34 . V_45 = V_31 -> V_40 ? V_46 : V_47 ;
V_34 . V_48 = V_31 -> V_40 ? V_49 : V_50 ;
V_34 . V_51 = V_31 -> V_40 ? V_52 : V_53 ;
V_34 . V_54 = V_31 -> V_54 ;
V_34 . V_55 = V_31 -> V_55 ;
V_2 -> V_56 = V_31 -> V_57 ? V_31 -> V_56 : 0 ;
V_2 -> V_58 = V_31 -> V_59 ;
V_2 -> V_55 = V_31 -> V_55 ;
if ( V_32 & V_60 )
V_34 . V_61 = V_31 -> V_62 ;
V_2 -> V_27 -> V_28 -> V_63 ( V_2 , & V_34 , V_32 ) ;
}
void F_3 ( struct V_1 * V_2 ,
struct V_64 V_65 )
{
struct V_66 * V_67 = & V_2 -> V_68 . V_67 ;
struct V_64 * V_69 = & V_2 -> V_70 ;
struct V_64 * V_71 = & V_2 -> V_68 . V_67 . V_71 ;
if ( ! ( V_67 -> V_10 & V_72 ) ) {
if ( V_65 . V_73 == V_74 ) {
V_67 -> V_10 |= V_72 ;
if ( V_69 -> V_73 == V_74 )
V_65 . V_73 = V_75 ;
else
V_65 . V_73 = V_69 -> V_73 ;
}
} else if ( V_65 . V_73 == V_74 )
V_65 . V_73 = V_71 -> V_73 ;
if ( ! ( V_67 -> V_10 & V_76 ) ) {
if ( V_65 . V_77 == V_74 ) {
V_67 -> V_10 |= V_76 ;
if ( V_69 -> V_77 == V_74 )
V_65 . V_77 = V_75 ;
else
V_65 . V_77 = V_69 -> V_77 ;
}
} else if ( V_65 . V_77 == V_74 )
V_65 . V_77 = V_71 -> V_77 ;
if ( F_4 ( V_78 , & V_2 -> V_10 ) )
F_5 ( V_2 -> V_73 ) ;
V_2 -> V_27 -> V_28 -> V_79 ( V_2 , & V_65 ) ;
F_6 ( V_2 , true ) ;
memcpy ( V_71 , & V_65 , sizeof( V_65 ) ) ;
if ( F_4 ( V_78 , & V_2 -> V_10 ) )
F_7 ( V_2 -> V_73 ) ;
}
static T_3 F_8 ( struct V_1 * V_2 ,
struct V_80 * V_9 )
{
struct V_81 * V_82 = & V_2 -> V_82 ;
int V_83 ;
T_3 V_84 ;
V_83 = V_82 -> V_85 [ V_9 -> V_86 -> V_87 ] . V_86 ;
if ( F_9 ( V_9 ) )
V_83 += 2 ;
else if ( F_10 ( V_9 ) )
V_83 -= ( V_83 == 14 ) ? 1 : 2 ;
for ( V_84 = 0 ; V_84 < V_82 -> V_88 ; V_84 ++ )
if ( V_82 -> V_85 [ V_84 ] . V_86 == V_83 )
return V_84 ;
F_11 ( 1 ) ;
return V_9 -> V_86 -> V_87 ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_80 * V_9 ,
unsigned int V_89 )
{
struct V_90 V_91 ;
T_3 V_87 ;
T_3 V_92 ;
T_3 V_55 ;
T_3 V_93 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_9 = V_9 ;
if ( V_89 & V_94 ) {
if ( F_13 ( V_9 ) ) {
F_14 ( V_95 , & V_2 -> V_10 ) ;
V_87 = F_8 ( V_2 , V_9 ) ;
} else {
F_15 ( V_95 , & V_2 -> V_10 ) ;
V_87 = V_9 -> V_86 -> V_87 ;
}
memcpy ( & V_91 . V_96 ,
& V_2 -> V_82 . V_85 [ V_87 ] ,
sizeof( V_91 . V_96 ) ) ;
memcpy ( & V_91 . V_86 ,
& V_2 -> V_82 . V_97 [ V_87 ] ,
sizeof( V_91 . V_86 ) ) ;
}
if ( F_4 ( V_98 , & V_2 -> V_99 ) &&
( V_89 & V_100 ) )
F_16 ( & V_2 -> V_101 ) ;
V_2 -> V_27 -> V_28 -> V_65 ( V_2 , & V_91 , V_89 ) ;
if ( V_89 & V_94 )
F_6 ( V_2 , false ) ;
if ( F_4 ( V_102 , & V_2 -> V_10 ) &&
F_4 ( V_98 , & V_2 -> V_99 ) &&
( V_89 & V_100 ) &&
( V_9 -> V_10 & V_103 ) ) {
V_93 = ( long ) V_104 - ( long ) V_2 -> V_58 ;
V_55 = F_17 ( V_2 -> V_55 ) ;
if ( V_93 > V_55 )
V_93 = 0 ;
V_92 = ( V_9 -> V_105 * V_55 ) - V_93 ;
F_18 ( V_2 -> V_106 ,
& V_2 -> V_101 ,
V_92 - 15 ) ;
}
if ( V_9 -> V_10 & V_103 )
F_14 ( V_107 , & V_2 -> V_10 ) ;
else
F_15 ( V_107 , & V_2 -> V_10 ) ;
V_2 -> V_108 = V_9 -> V_86 -> V_109 ;
V_2 -> V_110 = V_9 -> V_86 -> V_111 ;
V_2 -> V_112 = V_9 -> V_113 ;
V_2 -> V_114 = V_9 -> V_115 ;
V_2 -> V_116 = V_9 -> V_117 ;
}
