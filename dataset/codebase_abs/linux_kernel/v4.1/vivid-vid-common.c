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
V_43 -> V_59 = 1 ;
V_43 -> V_60 = V_49 -> V_60 ;
V_46 -> V_61 = V_49 -> V_61 ;
V_46 -> V_62 = V_49 -> V_62 ;
memset ( V_46 -> V_52 , 0 , sizeof( V_46 -> V_52 ) ) ;
}
int F_12 ( struct V_63 * V_63 , void * V_64 ,
struct V_39 * V_65 , T_2 V_66 )
{
struct V_39 V_5 ;
struct V_42 * V_43 = & V_5 . V_5 . V_44 ;
struct V_45 * V_46 = & V_43 -> V_47 [ 0 ] ;
struct V_48 * V_49 = & V_65 -> V_5 . V_49 ;
int V_67 ;
F_11 ( V_65 , & V_5 ) ;
V_67 = V_66 ( V_63 , V_64 , & V_5 ) ;
V_49 -> V_12 = V_43 -> V_12 ;
V_49 -> V_14 = V_43 -> V_14 ;
V_49 -> V_4 = V_43 -> V_4 ;
V_49 -> V_55 = V_43 -> V_55 ;
V_49 -> V_56 = V_43 -> V_56 ;
V_49 -> V_57 = V_43 -> V_57 ;
V_49 -> V_58 = V_43 -> V_58 ;
V_49 -> V_61 = V_46 -> V_61 ;
V_49 -> V_62 = V_46 -> V_62 ;
V_49 -> V_60 = V_43 -> V_60 ;
return V_67 ;
}
void F_13 ( struct V_68 * V_69 , const struct V_68 * V_70 )
{
V_69 -> V_12 = V_70 -> V_12 ;
V_69 -> V_14 = V_70 -> V_14 ;
}
void F_14 ( struct V_68 * V_69 , const struct V_68 * V_71 )
{
if ( V_69 -> V_12 < V_71 -> V_12 )
V_69 -> V_12 = V_71 -> V_12 ;
if ( V_69 -> V_14 < V_71 -> V_14 )
V_69 -> V_14 = V_71 -> V_14 ;
}
void F_15 ( struct V_68 * V_69 , const struct V_68 * V_72 )
{
if ( V_69 -> V_12 > V_72 -> V_12 )
V_69 -> V_12 = V_72 -> V_12 ;
if ( V_69 -> V_14 > V_72 -> V_14 )
V_69 -> V_14 = V_72 -> V_14 ;
}
void F_16 ( struct V_68 * V_69 , const struct V_68 * V_73 )
{
F_15 ( V_69 , V_73 ) ;
if ( V_69 -> V_74 < V_73 -> V_74 )
V_69 -> V_74 = V_73 -> V_74 ;
if ( V_69 -> V_75 < V_73 -> V_75 )
V_69 -> V_75 = V_73 -> V_75 ;
if ( V_69 -> V_74 + V_69 -> V_12 > V_73 -> V_12 )
V_69 -> V_74 = V_73 -> V_12 - V_69 -> V_12 ;
if ( V_69 -> V_75 + V_69 -> V_14 > V_73 -> V_14 )
V_69 -> V_75 = V_73 -> V_14 - V_69 -> V_14 ;
}
bool F_17 ( const struct V_68 * V_76 , const struct V_68 * V_77 )
{
return V_76 -> V_12 == V_77 -> V_12 && V_76 -> V_14 == V_77 -> V_14 ;
}
struct V_68 F_18 ( const struct V_68 * V_78 , const struct V_68 * V_79 )
{
struct V_68 V_69 ;
int V_80 , V_81 ;
V_69 . V_75 = F_19 ( V_78 -> V_75 , V_79 -> V_75 ) ;
V_69 . V_74 = F_19 ( V_78 -> V_74 , V_79 -> V_74 ) ;
V_81 = F_20 ( V_78 -> V_75 + V_78 -> V_14 , V_79 -> V_75 + V_79 -> V_14 ) ;
V_80 = F_20 ( V_78 -> V_74 + V_78 -> V_12 , V_79 -> V_74 + V_79 -> V_12 ) ;
V_69 . V_14 = F_19 ( 0 , V_81 - V_69 . V_75 ) ;
V_69 . V_12 = F_19 ( 0 , V_80 - V_69 . V_74 ) ;
return V_69 ;
}
void F_21 ( struct V_68 * V_69 , const struct V_68 * V_82 ,
const struct V_68 * V_83 )
{
if ( V_82 -> V_12 == 0 || V_82 -> V_14 == 0 ) {
V_69 -> V_74 = V_69 -> V_75 = V_69 -> V_12 = V_69 -> V_14 = 0 ;
return;
}
V_69 -> V_74 = ( ( ( V_69 -> V_74 - V_82 -> V_74 ) * V_83 -> V_12 ) / V_82 -> V_12 ) & ~ 1 ;
V_69 -> V_12 = ( ( V_69 -> V_12 * V_83 -> V_12 ) / V_82 -> V_12 ) & ~ 1 ;
V_69 -> V_75 = ( ( V_69 -> V_75 - V_82 -> V_75 ) * V_83 -> V_14 ) / V_82 -> V_14 ;
V_69 -> V_14 = ( V_69 -> V_14 * V_83 -> V_14 ) / V_82 -> V_14 ;
}
bool F_22 ( const struct V_68 * V_76 , const struct V_68 * V_77 )
{
if ( V_76 -> V_74 >= V_77 -> V_74 + V_77 -> V_12 ||
V_77 -> V_74 >= V_76 -> V_74 + V_76 -> V_12 )
return false ;
if ( V_76 -> V_75 >= V_77 -> V_75 + V_77 -> V_14 ||
V_77 -> V_75 >= V_76 -> V_75 + V_76 -> V_14 )
return false ;
return true ;
}
int F_23 ( unsigned V_60 , struct V_68 * V_69 )
{
unsigned V_84 = V_69 -> V_12 ;
unsigned V_85 = V_69 -> V_14 ;
V_84 &= 0xffff ;
V_85 &= 0xffff ;
if ( ! ( V_60 & V_86 ) ) {
V_84 ++ ;
V_85 ++ ;
if ( V_84 < 2 )
V_84 = 2 ;
if ( V_85 < 2 )
V_85 = 2 ;
}
if ( ! ( V_60 & V_87 ) ) {
if ( V_84 > V_88 )
V_84 = V_88 ;
if ( V_85 > V_89 )
V_85 = V_89 ;
}
V_84 = V_84 & ~ 1 ;
V_85 = V_85 & ~ 1 ;
if ( V_84 < 2 || V_85 < 2 )
return - V_90 ;
if ( V_84 > V_88 || V_85 > V_89 )
return - V_90 ;
if ( V_69 -> V_75 < 0 )
V_69 -> V_75 = 0 ;
if ( V_69 -> V_74 < 0 )
V_69 -> V_74 = 0 ;
V_69 -> V_74 &= 0xfffe ;
V_69 -> V_75 &= 0xfffe ;
if ( V_69 -> V_74 + V_84 > V_88 )
V_69 -> V_74 = V_88 - V_84 ;
if ( V_69 -> V_75 + V_85 > V_89 )
V_69 -> V_75 = V_89 - V_85 ;
if ( ( V_60 & ( V_87 | V_86 ) ) ==
( V_87 | V_86 ) &&
( V_69 -> V_12 != V_84 || V_69 -> V_14 != V_85 ) )
return - V_90 ;
V_69 -> V_12 = V_84 ;
V_69 -> V_14 = V_85 ;
return 0 ;
}
int F_24 ( struct V_63 * V_63 , void * V_64 ,
struct V_91 * V_65 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
const struct V_1 * V_5 ;
if ( V_65 -> V_92 >= F_2 ( V_7 ) -
( V_3 -> V_10 ? 0 : V_93 ) )
return - V_94 ;
V_5 = & V_7 [ V_65 -> V_92 ] ;
F_26 ( V_65 -> V_95 , V_5 -> V_96 , sizeof( V_65 -> V_95 ) ) ;
V_65 -> V_4 = V_5 -> V_8 ;
return 0 ;
}
int F_27 ( struct V_63 * V_63 , void * V_64 ,
struct V_91 * V_65 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
if ( ! V_3 -> V_10 )
return - V_97 ;
return F_24 ( V_63 , V_64 , V_65 ) ;
}
int F_28 ( struct V_63 * V_63 , void * V_64 ,
struct V_91 * V_65 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
if ( V_3 -> V_10 )
return - V_97 ;
return F_24 ( V_63 , V_64 , V_65 ) ;
}
int F_29 ( struct V_63 * V_63 , void * V_64 , T_3 * V_33 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
struct V_98 * V_99 = F_30 ( V_63 ) ;
if ( V_99 -> V_100 == V_101 ) {
if ( ! F_31 ( V_3 ) )
return - V_102 ;
* V_33 = V_3 -> V_21 ;
} else {
if ( ! F_5 ( V_3 ) )
return - V_102 ;
* V_33 = V_3 -> V_23 ;
}
return 0 ;
}
int F_32 ( struct V_63 * V_63 , void * V_103 ,
struct V_104 * V_105 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
struct V_98 * V_99 = F_30 ( V_63 ) ;
if ( V_99 -> V_100 == V_101 ) {
if ( ! F_6 ( V_3 ) )
return - V_102 ;
* V_105 = V_3 -> V_106 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_102 ;
* V_105 = V_3 -> V_107 ;
}
return 0 ;
}
int F_33 ( struct V_63 * V_63 , void * V_103 ,
struct V_108 * V_105 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
struct V_98 * V_99 = F_30 ( V_63 ) ;
if ( V_99 -> V_100 == V_101 ) {
if ( ! F_6 ( V_3 ) )
return - V_102 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_102 ;
}
return F_34 ( V_105 , & V_109 ,
NULL , NULL ) ;
}
int F_35 ( struct V_63 * V_63 , void * V_103 ,
struct V_110 * V_111 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
struct V_98 * V_99 = F_30 ( V_63 ) ;
if ( V_99 -> V_100 == V_101 ) {
if ( ! F_6 ( V_3 ) )
return - V_102 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_102 ;
}
* V_111 = V_109 ;
return 0 ;
}
int F_36 ( struct V_63 * V_63 , void * V_103 ,
struct V_112 * V_113 )
{
struct V_2 * V_3 = F_25 ( V_63 ) ;
struct V_98 * V_99 = F_30 ( V_63 ) ;
memset ( V_113 -> V_52 , 0 , sizeof( V_113 -> V_52 ) ) ;
if ( V_99 -> V_100 == V_101 ) {
if ( V_113 -> V_114 >= V_3 -> V_32 )
return - V_94 ;
if ( V_3 -> V_34 [ V_113 -> V_114 ] != V_115 )
return - V_94 ;
} else {
if ( V_113 -> V_114 >= V_3 -> V_116 )
return - V_94 ;
if ( V_3 -> V_117 [ V_113 -> V_114 ] != V_115 )
return - V_94 ;
}
if ( V_113 -> V_118 == 0 && V_113 -> V_119 == 0 ) {
V_113 -> V_119 = V_3 -> V_120 ;
return 0 ;
}
if ( V_3 -> V_120 == 0 )
return - V_102 ;
if ( V_113 -> V_118 >= V_3 -> V_120 )
return - V_94 ;
if ( V_113 -> V_118 + V_113 -> V_119 > V_3 -> V_120 )
V_113 -> V_119 = V_3 -> V_120 - V_113 -> V_118 ;
memcpy ( V_113 -> V_113 , V_3 -> V_113 , V_113 -> V_119 * 128 ) ;
return 0 ;
}
