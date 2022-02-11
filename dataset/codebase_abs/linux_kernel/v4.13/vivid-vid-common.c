const struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
const struct V_1 * V_5 ;
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
V_5 = & V_7 [ V_6 ] ;
if ( V_5 -> V_8 == V_4 )
if ( V_5 -> V_9 == 1 || V_3 -> V_10 )
return V_5 ;
}
return NULL ;
}
bool F_3 ( struct V_2 * V_3 )
{
if ( V_3 -> V_11 . V_12 != V_3 -> V_13 . V_12 ||
V_3 -> V_11 . V_14 != V_3 -> V_13 . V_14 )
return false ;
if ( V_3 -> V_15 -> V_8 != V_3 -> V_16 -> V_8 )
return false ;
if ( V_3 -> V_17 != V_3 -> V_18 )
return false ;
if ( V_3 -> V_17 == V_19 ||
V_3 -> V_17 == V_20 )
return false ;
if ( F_4 ( V_3 ) && F_5 ( V_3 ) ) {
if ( ! ( V_3 -> V_21 & V_22 ) !=
! ( V_3 -> V_23 & V_22 ) )
return false ;
return true ;
}
if ( F_6 ( V_3 ) && F_7 ( V_3 ) )
return true ;
return false ;
}
void F_8 ( struct V_2 * V_3 , unsigned type )
{
struct V_24 V_25 = {
. type = V_26 ,
. V_27 . V_28 . V_29 = V_30 ,
} ;
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_3 -> V_32 ; V_31 ++ ) {
V_25 . V_33 = V_31 ;
if ( V_3 -> V_34 [ V_31 ] == type ) {
if ( F_9 ( & V_3 -> V_35 ) && V_3 -> V_36 )
F_10 ( & V_3 -> V_35 , & V_25 ) ;
if ( F_9 ( & V_3 -> V_37 ) && V_3 -> V_38 )
F_10 ( & V_3 -> V_37 , & V_25 ) ;
}
}
}
void F_11 ( const struct V_39 * V_40 , struct V_39 * V_41 )
{
struct V_42 * V_43 = & V_41 -> V_5 . V_44 ;
struct V_45 * V_46 = & V_43 -> V_47 [ 0 ] ;
const struct V_48 * V_49 = & V_40 -> V_5 . V_49 ;
bool V_50 = V_40 -> type == V_51 ;
memset ( V_43 -> V_52 , 0 , sizeof( V_43 -> V_52 ) ) ;
V_41 -> type = V_50 ? V_53 :
V_54 ;
V_43 -> V_12 = V_49 -> V_12 ;
V_43 -> V_14 = V_49 -> V_14 ;
V_43 -> V_4 = V_49 -> V_4 ;
V_43 -> V_55 = V_49 -> V_55 ;
V_43 -> V_56 = V_49 -> V_56 ;
V_43 -> V_57 = V_49 -> V_57 ;
V_43 -> V_58 = V_49 -> V_58 ;
V_43 -> V_59 = V_49 -> V_59 ;
V_43 -> V_60 = 1 ;
V_43 -> V_61 = V_49 -> V_61 ;
V_46 -> V_62 = V_49 -> V_62 ;
V_46 -> V_63 = V_49 -> V_63 ;
memset ( V_46 -> V_52 , 0 , sizeof( V_46 -> V_52 ) ) ;
}
int F_12 ( struct V_64 * V_64 , void * V_65 ,
struct V_39 * V_66 , T_2 V_67 )
{
struct V_39 V_5 ;
struct V_42 * V_43 = & V_5 . V_5 . V_44 ;
struct V_45 * V_46 = & V_43 -> V_47 [ 0 ] ;
struct V_48 * V_49 = & V_66 -> V_5 . V_49 ;
int V_68 ;
F_11 ( V_66 , & V_5 ) ;
V_68 = V_67 ( V_64 , V_65 , & V_5 ) ;
V_49 -> V_12 = V_43 -> V_12 ;
V_49 -> V_14 = V_43 -> V_14 ;
V_49 -> V_4 = V_43 -> V_4 ;
V_49 -> V_55 = V_43 -> V_55 ;
V_49 -> V_56 = V_43 -> V_56 ;
V_49 -> V_57 = V_43 -> V_57 ;
V_49 -> V_58 = V_43 -> V_58 ;
V_49 -> V_59 = V_43 -> V_59 ;
V_49 -> V_62 = V_46 -> V_62 ;
V_49 -> V_63 = V_46 -> V_63 ;
V_49 -> V_61 = V_43 -> V_61 ;
return V_68 ;
}
int F_13 ( unsigned V_61 , struct V_69 * V_70 )
{
unsigned V_71 = V_70 -> V_12 ;
unsigned V_72 = V_70 -> V_14 ;
V_71 &= 0xffff ;
V_72 &= 0xffff ;
if ( ! ( V_61 & V_73 ) ) {
V_71 ++ ;
V_72 ++ ;
if ( V_71 < 2 )
V_71 = 2 ;
if ( V_72 < 2 )
V_72 = 2 ;
}
if ( ! ( V_61 & V_74 ) ) {
if ( V_71 > V_75 )
V_71 = V_75 ;
if ( V_72 > V_76 )
V_72 = V_76 ;
}
V_71 = V_71 & ~ 1 ;
V_72 = V_72 & ~ 1 ;
if ( V_71 < 2 || V_72 < 2 )
return - V_77 ;
if ( V_71 > V_75 || V_72 > V_76 )
return - V_77 ;
if ( V_70 -> V_78 < 0 )
V_70 -> V_78 = 0 ;
if ( V_70 -> V_79 < 0 )
V_70 -> V_79 = 0 ;
V_70 -> V_79 &= 0xfffe ;
V_70 -> V_78 &= 0xfffe ;
if ( V_70 -> V_79 + V_71 > V_75 )
V_70 -> V_79 = V_75 - V_71 ;
if ( V_70 -> V_78 + V_72 > V_76 )
V_70 -> V_78 = V_76 - V_72 ;
if ( ( V_61 & ( V_74 | V_73 ) ) ==
( V_74 | V_73 ) &&
( V_70 -> V_12 != V_71 || V_70 -> V_14 != V_72 ) )
return - V_77 ;
V_70 -> V_12 = V_71 ;
V_70 -> V_14 = V_72 ;
return 0 ;
}
int F_14 ( struct V_64 * V_64 , void * V_65 ,
struct V_80 * V_66 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
const struct V_1 * V_5 ;
if ( V_66 -> V_81 >= F_2 ( V_7 ) -
( V_3 -> V_10 ? 0 : V_82 ) )
return - V_83 ;
V_5 = & V_7 [ V_66 -> V_81 ] ;
V_66 -> V_4 = V_5 -> V_8 ;
return 0 ;
}
int F_16 ( struct V_64 * V_64 , void * V_65 ,
struct V_80 * V_66 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
if ( ! V_3 -> V_10 )
return - V_84 ;
return F_14 ( V_64 , V_65 , V_66 ) ;
}
int F_17 ( struct V_64 * V_64 , void * V_65 ,
struct V_80 * V_66 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
if ( V_3 -> V_10 )
return - V_84 ;
return F_14 ( V_64 , V_65 , V_66 ) ;
}
int F_18 ( struct V_64 * V_64 , void * V_65 , T_3 * V_33 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
struct V_85 * V_86 = F_19 ( V_64 ) ;
if ( V_86 -> V_87 == V_88 ) {
if ( ! F_20 ( V_3 ) )
return - V_89 ;
* V_33 = V_3 -> V_21 ;
} else {
if ( ! F_5 ( V_3 ) )
return - V_89 ;
* V_33 = V_3 -> V_23 ;
}
return 0 ;
}
int F_21 ( struct V_64 * V_64 , void * V_90 ,
struct V_91 * V_92 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
struct V_85 * V_86 = F_19 ( V_64 ) ;
if ( V_86 -> V_87 == V_88 ) {
if ( ! F_6 ( V_3 ) )
return - V_89 ;
* V_92 = V_3 -> V_93 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_89 ;
* V_92 = V_3 -> V_94 ;
}
return 0 ;
}
int F_22 ( struct V_64 * V_64 , void * V_90 ,
struct V_95 * V_92 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
struct V_85 * V_86 = F_19 ( V_64 ) ;
if ( V_86 -> V_87 == V_88 ) {
if ( ! F_6 ( V_3 ) )
return - V_89 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_89 ;
}
return F_23 ( V_92 , & V_96 ,
NULL , NULL ) ;
}
int F_24 ( struct V_64 * V_64 , void * V_90 ,
struct V_97 * V_98 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
struct V_85 * V_86 = F_19 ( V_64 ) ;
if ( V_86 -> V_87 == V_88 ) {
if ( ! F_6 ( V_3 ) )
return - V_89 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_89 ;
}
* V_98 = V_96 ;
return 0 ;
}
int F_25 ( struct V_64 * V_64 , void * V_90 ,
struct V_99 * V_100 )
{
struct V_2 * V_3 = F_15 ( V_64 ) ;
struct V_85 * V_86 = F_19 ( V_64 ) ;
struct V_101 * V_102 ;
memset ( V_100 -> V_52 , 0 , sizeof( V_100 -> V_52 ) ) ;
if ( V_86 -> V_87 == V_88 ) {
if ( V_100 -> V_103 >= V_3 -> V_32 )
return - V_83 ;
if ( V_3 -> V_34 [ V_100 -> V_103 ] != V_104 )
return - V_83 ;
V_102 = V_3 -> V_105 ;
} else {
unsigned int V_106 ;
if ( V_100 -> V_103 >= V_3 -> V_107 )
return - V_83 ;
if ( V_3 -> V_108 [ V_100 -> V_103 ] != V_104 )
return - V_83 ;
V_106 = V_3 -> V_109 [ V_100 -> V_103 ] ;
V_102 = V_3 -> V_110 [ V_106 ] ;
}
if ( V_100 -> V_111 == 0 && V_100 -> V_112 == 0 ) {
V_100 -> V_112 = V_3 -> V_113 ;
return 0 ;
}
if ( V_3 -> V_113 == 0 )
return - V_89 ;
if ( V_100 -> V_111 >= V_3 -> V_113 )
return - V_83 ;
if ( V_100 -> V_111 + V_100 -> V_112 > V_3 -> V_113 )
V_100 -> V_112 = V_3 -> V_113 - V_100 -> V_111 ;
F_26 ( V_3 -> V_100 , V_3 -> V_113 * 128 , V_102 -> V_114 ) ;
memcpy ( V_100 -> V_100 , V_3 -> V_100 + V_100 -> V_111 * 128 , V_100 -> V_112 * 128 ) ;
return 0 ;
}
