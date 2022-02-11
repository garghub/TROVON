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
if ( F_4 ( V_3 ) && F_5 ( V_3 ) ) {
if ( ! ( V_3 -> V_19 & V_20 ) !=
! ( V_3 -> V_21 & V_20 ) )
return false ;
return true ;
}
if ( F_6 ( V_3 ) && F_7 ( V_3 ) )
return true ;
return false ;
}
void F_8 ( struct V_2 * V_3 , unsigned type )
{
struct V_22 V_23 = {
. type = V_24 ,
. V_25 . V_26 . V_27 = V_28 ,
} ;
unsigned V_29 ;
for ( V_29 = 0 ; V_29 < V_3 -> V_30 ; V_29 ++ ) {
V_23 . V_31 = V_29 ;
if ( V_3 -> V_32 [ V_29 ] == type ) {
if ( F_9 ( & V_3 -> V_33 ) && V_3 -> V_34 )
F_10 ( & V_3 -> V_33 , & V_23 ) ;
if ( F_9 ( & V_3 -> V_35 ) && V_3 -> V_36 )
F_10 ( & V_3 -> V_35 , & V_23 ) ;
}
}
}
void F_11 ( const struct V_37 * V_38 , struct V_37 * V_39 )
{
struct V_40 * V_41 = & V_39 -> V_5 . V_42 ;
struct V_43 * V_44 = & V_41 -> V_45 [ 0 ] ;
const struct V_46 * V_47 = & V_38 -> V_5 . V_47 ;
bool V_48 = V_38 -> type == V_49 ;
memset ( V_41 -> V_50 , 0 , sizeof( V_41 -> V_50 ) ) ;
V_39 -> type = V_48 ? V_51 :
V_52 ;
V_41 -> V_12 = V_47 -> V_12 ;
V_41 -> V_14 = V_47 -> V_14 ;
V_41 -> V_4 = V_47 -> V_4 ;
V_41 -> V_53 = V_47 -> V_53 ;
V_41 -> V_54 = V_47 -> V_54 ;
V_41 -> V_55 = V_47 -> V_55 ;
V_41 -> V_56 = V_47 -> V_56 ;
V_41 -> V_57 = 1 ;
V_41 -> V_58 = V_47 -> V_58 ;
V_44 -> V_59 = V_47 -> V_59 ;
V_44 -> V_60 = V_47 -> V_60 ;
memset ( V_44 -> V_50 , 0 , sizeof( V_44 -> V_50 ) ) ;
}
int F_12 ( struct V_61 * V_61 , void * V_62 ,
struct V_37 * V_63 , T_2 V_64 )
{
struct V_37 V_5 ;
struct V_40 * V_41 = & V_5 . V_5 . V_42 ;
struct V_43 * V_44 = & V_41 -> V_45 [ 0 ] ;
struct V_46 * V_47 = & V_63 -> V_5 . V_47 ;
int V_65 ;
F_11 ( V_63 , & V_5 ) ;
V_65 = V_64 ( V_61 , V_62 , & V_5 ) ;
V_47 -> V_12 = V_41 -> V_12 ;
V_47 -> V_14 = V_41 -> V_14 ;
V_47 -> V_4 = V_41 -> V_4 ;
V_47 -> V_53 = V_41 -> V_53 ;
V_47 -> V_54 = V_41 -> V_54 ;
V_47 -> V_55 = V_41 -> V_55 ;
V_47 -> V_56 = V_41 -> V_56 ;
V_47 -> V_59 = V_44 -> V_59 ;
V_47 -> V_60 = V_44 -> V_60 ;
V_47 -> V_58 = V_41 -> V_58 ;
return V_65 ;
}
void F_13 ( struct V_66 * V_67 , const struct V_66 * V_68 )
{
V_67 -> V_12 = V_68 -> V_12 ;
V_67 -> V_14 = V_68 -> V_14 ;
}
void F_14 ( struct V_66 * V_67 , const struct V_66 * V_69 )
{
if ( V_67 -> V_12 < V_69 -> V_12 )
V_67 -> V_12 = V_69 -> V_12 ;
if ( V_67 -> V_14 < V_69 -> V_14 )
V_67 -> V_14 = V_69 -> V_14 ;
}
void F_15 ( struct V_66 * V_67 , const struct V_66 * V_70 )
{
if ( V_67 -> V_12 > V_70 -> V_12 )
V_67 -> V_12 = V_70 -> V_12 ;
if ( V_67 -> V_14 > V_70 -> V_14 )
V_67 -> V_14 = V_70 -> V_14 ;
}
void F_16 ( struct V_66 * V_67 , const struct V_66 * V_71 )
{
F_15 ( V_67 , V_71 ) ;
if ( V_67 -> V_72 < V_71 -> V_72 )
V_67 -> V_72 = V_71 -> V_72 ;
if ( V_67 -> V_73 < V_71 -> V_73 )
V_67 -> V_73 = V_71 -> V_73 ;
if ( V_67 -> V_72 + V_67 -> V_12 > V_71 -> V_12 )
V_67 -> V_72 = V_71 -> V_12 - V_67 -> V_12 ;
if ( V_67 -> V_73 + V_67 -> V_14 > V_71 -> V_14 )
V_67 -> V_73 = V_71 -> V_14 - V_67 -> V_14 ;
}
bool F_17 ( const struct V_66 * V_74 , const struct V_66 * V_75 )
{
return V_74 -> V_12 == V_75 -> V_12 && V_74 -> V_14 == V_75 -> V_14 ;
}
struct V_66 F_18 ( const struct V_66 * V_76 , const struct V_66 * V_77 )
{
struct V_66 V_67 ;
int V_78 , V_79 ;
V_67 . V_73 = F_19 ( V_76 -> V_73 , V_77 -> V_73 ) ;
V_67 . V_72 = F_19 ( V_76 -> V_72 , V_77 -> V_72 ) ;
V_79 = F_20 ( V_76 -> V_73 + V_76 -> V_14 , V_77 -> V_73 + V_77 -> V_14 ) ;
V_78 = F_20 ( V_76 -> V_72 + V_76 -> V_12 , V_77 -> V_72 + V_77 -> V_12 ) ;
V_67 . V_14 = F_19 ( 0 , V_79 - V_67 . V_73 ) ;
V_67 . V_12 = F_19 ( 0 , V_78 - V_67 . V_72 ) ;
return V_67 ;
}
void F_21 ( struct V_66 * V_67 , const struct V_66 * V_80 ,
const struct V_66 * V_81 )
{
if ( V_80 -> V_12 == 0 || V_80 -> V_14 == 0 ) {
V_67 -> V_72 = V_67 -> V_73 = V_67 -> V_12 = V_67 -> V_14 = 0 ;
return;
}
V_67 -> V_72 = ( ( ( V_67 -> V_72 - V_80 -> V_72 ) * V_81 -> V_12 ) / V_80 -> V_12 ) & ~ 1 ;
V_67 -> V_12 = ( ( V_67 -> V_12 * V_81 -> V_12 ) / V_80 -> V_12 ) & ~ 1 ;
V_67 -> V_73 = ( ( V_67 -> V_73 - V_80 -> V_73 ) * V_81 -> V_14 ) / V_80 -> V_14 ;
V_67 -> V_14 = ( V_67 -> V_14 * V_81 -> V_14 ) / V_80 -> V_14 ;
}
bool F_22 ( const struct V_66 * V_74 , const struct V_66 * V_75 )
{
if ( V_74 -> V_72 >= V_75 -> V_72 + V_75 -> V_12 ||
V_75 -> V_72 >= V_74 -> V_72 + V_74 -> V_12 )
return false ;
if ( V_74 -> V_73 >= V_75 -> V_73 + V_75 -> V_14 ||
V_75 -> V_73 >= V_74 -> V_73 + V_74 -> V_14 )
return false ;
return true ;
}
int F_23 ( unsigned V_58 , struct V_66 * V_67 )
{
unsigned V_82 = V_67 -> V_12 ;
unsigned V_83 = V_67 -> V_14 ;
if ( ! ( V_58 & V_84 ) ) {
V_82 ++ ;
V_83 ++ ;
if ( V_82 < 2 )
V_82 = 2 ;
if ( V_83 < 2 )
V_83 = 2 ;
}
if ( ! ( V_58 & V_85 ) ) {
if ( V_82 > V_86 )
V_82 = V_86 ;
if ( V_83 > V_87 )
V_83 = V_87 ;
}
V_82 = V_82 & ~ 1 ;
V_83 = V_83 & ~ 1 ;
if ( V_82 < 2 || V_83 < 2 )
return - V_88 ;
if ( V_82 > V_86 || V_83 > V_87 )
return - V_88 ;
if ( V_67 -> V_73 < 0 )
V_67 -> V_73 = 0 ;
if ( V_67 -> V_72 < 0 )
V_67 -> V_72 = 0 ;
V_67 -> V_72 &= ~ 1 ;
V_67 -> V_73 &= ~ 1 ;
if ( V_67 -> V_72 + V_82 > V_86 )
V_67 -> V_72 = V_86 - V_82 ;
if ( V_67 -> V_73 + V_83 > V_87 )
V_67 -> V_73 = V_87 - V_83 ;
if ( ( V_58 & ( V_85 | V_84 ) ) ==
( V_85 | V_84 ) &&
( V_67 -> V_12 != V_82 || V_67 -> V_14 != V_83 ) )
return - V_88 ;
V_67 -> V_12 = V_82 ;
V_67 -> V_14 = V_83 ;
return 0 ;
}
int F_24 ( struct V_61 * V_61 , void * V_62 ,
struct V_89 * V_63 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
const struct V_1 * V_5 ;
if ( V_63 -> V_90 >= F_2 ( V_7 ) -
( V_3 -> V_10 ? 0 : V_91 ) )
return - V_92 ;
V_5 = & V_7 [ V_63 -> V_90 ] ;
F_26 ( V_63 -> V_93 , V_5 -> V_94 , sizeof( V_63 -> V_93 ) ) ;
V_63 -> V_4 = V_5 -> V_8 ;
return 0 ;
}
int F_27 ( struct V_61 * V_61 , void * V_62 ,
struct V_89 * V_63 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
if ( ! V_3 -> V_10 )
return - V_95 ;
return F_24 ( V_61 , V_62 , V_63 ) ;
}
int F_28 ( struct V_61 * V_61 , void * V_62 ,
struct V_89 * V_63 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
if ( V_3 -> V_10 )
return - V_95 ;
return F_24 ( V_61 , V_62 , V_63 ) ;
}
int F_29 ( struct V_61 * V_61 , void * V_62 , T_3 * V_31 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
struct V_96 * V_97 = F_30 ( V_61 ) ;
if ( V_97 -> V_98 == V_99 ) {
if ( ! F_31 ( V_3 ) )
return - V_100 ;
* V_31 = V_3 -> V_19 ;
} else {
if ( ! F_5 ( V_3 ) )
return - V_100 ;
* V_31 = V_3 -> V_21 ;
}
return 0 ;
}
int F_32 ( struct V_61 * V_61 , void * V_101 ,
struct V_102 * V_103 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
struct V_96 * V_97 = F_30 ( V_61 ) ;
if ( V_97 -> V_98 == V_99 ) {
if ( ! F_6 ( V_3 ) )
return - V_100 ;
* V_103 = V_3 -> V_104 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_100 ;
* V_103 = V_3 -> V_105 ;
}
return 0 ;
}
int F_33 ( struct V_61 * V_61 , void * V_101 ,
struct V_106 * V_103 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
struct V_96 * V_97 = F_30 ( V_61 ) ;
if ( V_97 -> V_98 == V_99 ) {
if ( ! F_6 ( V_3 ) )
return - V_100 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_100 ;
}
return F_34 ( V_103 , & V_107 ,
NULL , NULL ) ;
}
int F_35 ( struct V_61 * V_61 , void * V_101 ,
struct V_108 * V_109 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
struct V_96 * V_97 = F_30 ( V_61 ) ;
if ( V_97 -> V_98 == V_99 ) {
if ( ! F_6 ( V_3 ) )
return - V_100 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_100 ;
}
* V_109 = V_107 ;
return 0 ;
}
int F_36 ( struct V_61 * V_61 , void * V_101 ,
struct V_110 * V_111 )
{
struct V_2 * V_3 = F_25 ( V_61 ) ;
struct V_96 * V_97 = F_30 ( V_61 ) ;
memset ( V_111 -> V_50 , 0 , sizeof( V_111 -> V_50 ) ) ;
if ( V_97 -> V_98 == V_99 ) {
if ( V_111 -> V_112 >= V_3 -> V_30 )
return - V_92 ;
if ( V_3 -> V_32 [ V_111 -> V_112 ] != V_113 )
return - V_92 ;
} else {
if ( V_111 -> V_112 >= V_3 -> V_114 )
return - V_92 ;
if ( V_3 -> V_115 [ V_111 -> V_112 ] != V_113 )
return - V_92 ;
}
if ( V_111 -> V_116 == 0 && V_111 -> V_117 == 0 ) {
V_111 -> V_117 = V_3 -> V_118 ;
return 0 ;
}
if ( V_3 -> V_118 == 0 )
return - V_100 ;
if ( V_111 -> V_116 >= V_3 -> V_118 )
return - V_92 ;
if ( V_111 -> V_116 + V_111 -> V_117 > V_3 -> V_118 )
V_111 -> V_117 = V_3 -> V_118 - V_111 -> V_116 ;
memcpy ( V_111 -> V_111 , V_3 -> V_111 , V_111 -> V_117 * 128 ) ;
return 0 ;
}
