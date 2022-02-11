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
V_41 -> V_55 = 1 ;
V_41 -> V_56 = V_47 -> V_56 ;
V_44 -> V_57 = V_47 -> V_57 ;
V_44 -> V_58 = V_47 -> V_58 ;
memset ( V_44 -> V_50 , 0 , sizeof( V_44 -> V_50 ) ) ;
}
int F_12 ( struct V_59 * V_59 , void * V_60 ,
struct V_37 * V_61 , T_2 V_62 )
{
struct V_37 V_5 ;
struct V_40 * V_41 = & V_5 . V_5 . V_42 ;
struct V_43 * V_44 = & V_41 -> V_45 [ 0 ] ;
struct V_46 * V_47 = & V_61 -> V_5 . V_47 ;
int V_63 ;
F_11 ( V_61 , & V_5 ) ;
V_63 = V_62 ( V_59 , V_60 , & V_5 ) ;
V_47 -> V_12 = V_41 -> V_12 ;
V_47 -> V_14 = V_41 -> V_14 ;
V_47 -> V_4 = V_41 -> V_4 ;
V_47 -> V_53 = V_41 -> V_53 ;
V_47 -> V_54 = V_41 -> V_54 ;
V_47 -> V_57 = V_44 -> V_57 ;
V_47 -> V_58 = V_44 -> V_58 ;
V_47 -> V_56 = V_41 -> V_56 ;
return V_63 ;
}
void F_13 ( struct V_64 * V_65 , const struct V_64 * V_66 )
{
V_65 -> V_12 = V_66 -> V_12 ;
V_65 -> V_14 = V_66 -> V_14 ;
}
void F_14 ( struct V_64 * V_65 , const struct V_64 * V_67 )
{
if ( V_65 -> V_12 < V_67 -> V_12 )
V_65 -> V_12 = V_67 -> V_12 ;
if ( V_65 -> V_14 < V_67 -> V_14 )
V_65 -> V_14 = V_67 -> V_14 ;
}
void F_15 ( struct V_64 * V_65 , const struct V_64 * V_68 )
{
if ( V_65 -> V_12 > V_68 -> V_12 )
V_65 -> V_12 = V_68 -> V_12 ;
if ( V_65 -> V_14 > V_68 -> V_14 )
V_65 -> V_14 = V_68 -> V_14 ;
}
void F_16 ( struct V_64 * V_65 , const struct V_64 * V_69 )
{
F_15 ( V_65 , V_69 ) ;
if ( V_65 -> V_70 < V_69 -> V_70 )
V_65 -> V_70 = V_69 -> V_70 ;
if ( V_65 -> V_71 < V_69 -> V_71 )
V_65 -> V_71 = V_69 -> V_71 ;
if ( V_65 -> V_70 + V_65 -> V_12 > V_69 -> V_12 )
V_65 -> V_70 = V_69 -> V_12 - V_65 -> V_12 ;
if ( V_65 -> V_71 + V_65 -> V_14 > V_69 -> V_14 )
V_65 -> V_71 = V_69 -> V_14 - V_65 -> V_14 ;
}
bool F_17 ( const struct V_64 * V_72 , const struct V_64 * V_73 )
{
return V_72 -> V_12 == V_73 -> V_12 && V_72 -> V_14 == V_73 -> V_14 ;
}
struct V_64 F_18 ( const struct V_64 * V_74 , const struct V_64 * V_75 )
{
struct V_64 V_65 ;
int V_76 , V_77 ;
V_65 . V_71 = F_19 ( V_74 -> V_71 , V_75 -> V_71 ) ;
V_65 . V_70 = F_19 ( V_74 -> V_70 , V_75 -> V_70 ) ;
V_77 = F_20 ( V_74 -> V_71 + V_74 -> V_14 , V_75 -> V_71 + V_75 -> V_14 ) ;
V_76 = F_20 ( V_74 -> V_70 + V_74 -> V_12 , V_75 -> V_70 + V_75 -> V_12 ) ;
V_65 . V_14 = F_19 ( 0 , V_77 - V_65 . V_71 ) ;
V_65 . V_12 = F_19 ( 0 , V_76 - V_65 . V_70 ) ;
return V_65 ;
}
void F_21 ( struct V_64 * V_65 , const struct V_64 * V_78 ,
const struct V_64 * V_79 )
{
if ( V_78 -> V_12 == 0 || V_78 -> V_14 == 0 ) {
V_65 -> V_70 = V_65 -> V_71 = V_65 -> V_12 = V_65 -> V_14 = 0 ;
return;
}
V_65 -> V_70 = ( ( ( V_65 -> V_70 - V_78 -> V_70 ) * V_79 -> V_12 ) / V_78 -> V_12 ) & ~ 1 ;
V_65 -> V_12 = ( ( V_65 -> V_12 * V_79 -> V_12 ) / V_78 -> V_12 ) & ~ 1 ;
V_65 -> V_71 = ( ( V_65 -> V_71 - V_78 -> V_71 ) * V_79 -> V_14 ) / V_78 -> V_14 ;
V_65 -> V_14 = ( V_65 -> V_14 * V_79 -> V_14 ) / V_78 -> V_14 ;
}
bool F_22 ( const struct V_64 * V_72 , const struct V_64 * V_73 )
{
if ( V_72 -> V_70 >= V_73 -> V_70 + V_73 -> V_12 ||
V_73 -> V_70 >= V_72 -> V_70 + V_72 -> V_12 )
return false ;
if ( V_72 -> V_71 >= V_73 -> V_71 + V_73 -> V_14 ||
V_73 -> V_71 >= V_72 -> V_71 + V_72 -> V_14 )
return false ;
return true ;
}
int F_23 ( unsigned V_56 , struct V_64 * V_65 )
{
unsigned V_80 = V_65 -> V_12 ;
unsigned V_81 = V_65 -> V_14 ;
if ( ! ( V_56 & V_82 ) ) {
V_80 ++ ;
V_81 ++ ;
if ( V_80 < 2 )
V_80 = 2 ;
if ( V_81 < 2 )
V_81 = 2 ;
}
if ( ! ( V_56 & V_83 ) ) {
if ( V_80 > V_84 )
V_80 = V_84 ;
if ( V_81 > V_85 )
V_81 = V_85 ;
}
V_80 = V_80 & ~ 1 ;
V_81 = V_81 & ~ 1 ;
if ( V_80 < 2 || V_81 < 2 )
return - V_86 ;
if ( V_80 > V_84 || V_81 > V_85 )
return - V_86 ;
if ( V_65 -> V_71 < 0 )
V_65 -> V_71 = 0 ;
if ( V_65 -> V_70 < 0 )
V_65 -> V_70 = 0 ;
V_65 -> V_70 &= ~ 1 ;
V_65 -> V_71 &= ~ 1 ;
if ( V_65 -> V_70 + V_80 > V_84 )
V_65 -> V_70 = V_84 - V_80 ;
if ( V_65 -> V_71 + V_81 > V_85 )
V_65 -> V_71 = V_85 - V_81 ;
if ( ( V_56 & ( V_83 | V_82 ) ) ==
( V_83 | V_82 ) &&
( V_65 -> V_12 != V_80 || V_65 -> V_14 != V_81 ) )
return - V_86 ;
V_65 -> V_12 = V_80 ;
V_65 -> V_14 = V_81 ;
return 0 ;
}
int F_24 ( struct V_59 * V_59 , void * V_60 ,
struct V_87 * V_61 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
const struct V_1 * V_5 ;
if ( V_61 -> V_88 >= F_2 ( V_7 ) -
( V_3 -> V_10 ? 0 : V_89 ) )
return - V_90 ;
V_5 = & V_7 [ V_61 -> V_88 ] ;
F_26 ( V_61 -> V_91 , V_5 -> V_92 , sizeof( V_61 -> V_91 ) ) ;
V_61 -> V_4 = V_5 -> V_8 ;
return 0 ;
}
int F_27 ( struct V_59 * V_59 , void * V_60 ,
struct V_87 * V_61 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
if ( ! V_3 -> V_10 )
return - V_93 ;
return F_24 ( V_59 , V_60 , V_61 ) ;
}
int F_28 ( struct V_59 * V_59 , void * V_60 ,
struct V_87 * V_61 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
if ( V_3 -> V_10 )
return - V_93 ;
return F_24 ( V_59 , V_60 , V_61 ) ;
}
int F_29 ( struct V_59 * V_59 , void * V_60 , T_3 * V_31 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
struct V_94 * V_95 = F_30 ( V_59 ) ;
if ( V_95 -> V_96 == V_97 ) {
if ( ! F_31 ( V_3 ) )
return - V_98 ;
* V_31 = V_3 -> V_19 ;
} else {
if ( ! F_5 ( V_3 ) )
return - V_98 ;
* V_31 = V_3 -> V_21 ;
}
return 0 ;
}
int F_32 ( struct V_59 * V_59 , void * V_99 ,
struct V_100 * V_101 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
struct V_94 * V_95 = F_30 ( V_59 ) ;
if ( V_95 -> V_96 == V_97 ) {
if ( ! F_6 ( V_3 ) )
return - V_98 ;
* V_101 = V_3 -> V_102 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_98 ;
* V_101 = V_3 -> V_103 ;
}
return 0 ;
}
int F_33 ( struct V_59 * V_59 , void * V_99 ,
struct V_104 * V_101 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
struct V_94 * V_95 = F_30 ( V_59 ) ;
if ( V_95 -> V_96 == V_97 ) {
if ( ! F_6 ( V_3 ) )
return - V_98 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_98 ;
}
return F_34 ( V_101 , & V_105 ,
NULL , NULL ) ;
}
int F_35 ( struct V_59 * V_59 , void * V_99 ,
struct V_106 * V_107 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
struct V_94 * V_95 = F_30 ( V_59 ) ;
if ( V_95 -> V_96 == V_97 ) {
if ( ! F_6 ( V_3 ) )
return - V_98 ;
} else {
if ( ! F_7 ( V_3 ) )
return - V_98 ;
}
* V_107 = V_105 ;
return 0 ;
}
int F_36 ( struct V_59 * V_59 , void * V_99 ,
struct V_108 * V_109 )
{
struct V_2 * V_3 = F_25 ( V_59 ) ;
struct V_94 * V_95 = F_30 ( V_59 ) ;
memset ( V_109 -> V_50 , 0 , sizeof( V_109 -> V_50 ) ) ;
if ( V_95 -> V_96 == V_97 ) {
if ( V_109 -> V_110 >= V_3 -> V_30 )
return - V_90 ;
if ( V_3 -> V_32 [ V_109 -> V_110 ] != V_111 )
return - V_90 ;
} else {
if ( V_109 -> V_110 >= V_3 -> V_112 )
return - V_90 ;
if ( V_3 -> V_113 [ V_109 -> V_110 ] != V_111 )
return - V_90 ;
}
if ( V_109 -> V_114 == 0 && V_109 -> V_115 == 0 ) {
V_109 -> V_115 = V_3 -> V_116 ;
return 0 ;
}
if ( V_3 -> V_116 == 0 )
return - V_98 ;
if ( V_109 -> V_114 >= V_3 -> V_116 )
return - V_90 ;
if ( V_109 -> V_114 + V_109 -> V_115 > V_3 -> V_116 )
V_109 -> V_115 = V_3 -> V_116 - V_109 -> V_114 ;
memcpy ( V_109 -> V_109 , V_3 -> V_109 , V_109 -> V_115 * 128 ) ;
return 0 ;
}
