void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 . V_4 , V_5 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_6 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_7 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_8 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_9 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_10 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_11 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_12 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_13 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_14 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_15 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_16 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_17 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_18 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_19 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_20 ) ;
F_2 ( V_2 -> V_3 . V_4 , V_21 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_22 ) ;
F_3 ( V_2 -> V_3 . V_4 , V_23 ) ;
if ( F_4 ( V_2 -> V_24 , V_25 ) &&
F_4 ( V_2 -> V_24 , V_26 ) )
F_3 ( V_2 -> V_3 . V_4 , V_18 ) ;
}
bool F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_27 ;
}
int F_6 ( struct V_1 * V_2 , bool V_28 )
{
V_2 -> V_27 = V_28 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_31 )
return V_2 -> V_30 -> V_31 ( V_2 ) ;
} else {
return F_10 ( V_2 , & ( V_2 -> V_32 ) ,
NULL , NULL ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_33 )
return V_2 -> V_30 -> V_33 ( V_2 ) ;
} else {
return F_10 ( V_2 , & ( V_2 -> V_34 ) ,
NULL , NULL ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
const struct V_35 * V_36 ,
const struct V_35 * V_37 )
{
struct V_38 V_39 ;
F_8 ( V_2 ) ;
V_39 . V_36 = V_36 ;
V_39 . V_40 = V_37 ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_41 )
return V_2 -> V_30 -> V_41 ( V_2 , & V_39 ) ;
} else {
return F_10 ( V_2 , & ( V_2 -> V_42 ) , & V_39 , NULL ) ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
int V_43 = 1 ;
bool V_44 ;
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_45 )
V_43 = V_2 -> V_30 -> V_45 ( V_2 ) ;
} else {
V_43 = F_10 ( V_2 ,
& ( V_2 -> V_46 ) ,
NULL , NULL ) ;
}
V_44 = V_43 == 0 ? true : false ;
F_14 ( V_2 -> V_24 , V_44 ) ;
return V_43 ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_43 = - 1 ;
bool V_44 ;
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( V_2 -> V_30 -> V_47 )
V_43 = V_2 -> V_30 -> V_47 ( V_2 ) ;
} else {
V_43 = F_10 ( V_2 ,
& ( V_2 -> V_48 ) ,
NULL , NULL ) ;
}
V_44 = V_43 == 0 ? false : true ;
F_14 ( V_2 -> V_24 , V_44 ) ;
return V_43 ;
}
int F_16 ( struct V_1 * V_2 , enum V_49 V_50 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_51 != NULL )
return V_2 -> V_30 -> V_51 ( V_2 , V_50 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_52 * V_53 ,
const struct V_52 * V_54 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_55 != NULL )
return V_2 -> V_30 -> V_55 (
V_2 ,
V_53 ,
V_54 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_56 != NULL )
return V_2 -> V_30 -> V_56 ( V_2 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , bool V_57 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_58 != NULL )
return V_2 -> V_30 -> V_58 ( V_2 , V_57 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , bool V_57 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_59 != NULL )
return V_2 -> V_30 -> V_59 ( V_2 , V_57 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_60 )
return V_2 -> V_30 -> V_60 ( V_2 ) ;
} else {
return F_10 ( V_2 , & ( V_2 -> V_61 ) , NULL , NULL ) ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_62 )
V_2 -> V_30 -> V_62 ( V_2 ) ;
} else
return F_10 ( V_2 , & V_2 -> V_63 , NULL , NULL ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) )
if ( NULL != V_2 -> V_30 -> V_64 )
V_2 -> V_30 -> V_64 ( V_2 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_65 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_65 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_2 , const void * V_67 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_68 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_68 ( V_2 , V_67 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
return F_10 ( V_2 , & ( V_2 -> V_71 ) , V_70 , NULL ) ;
}
bool F_27 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_72 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_72 ( V_2 ) ;
}
int F_28 ( struct V_1 * V_2 ,
const struct V_35 * V_73 ,
const struct V_35 * V_74 ,
bool * V_75 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_76 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_76 ( V_2 , V_73 , V_74 , V_75 ) ;
}
int F_29 ( struct V_1 * V_2 ,
const struct V_77 * V_78 )
{
F_8 ( V_2 ) ;
if ( V_78 == NULL )
return - V_66 ;
V_2 -> V_78 = * V_78 ;
if ( V_2 -> V_30 -> V_79 == NULL )
return - V_66 ;
if ( V_2 -> V_30 -> V_79 )
V_2 -> V_30 -> V_79 ( V_2 ,
V_78 -> V_80 ,
V_78 -> V_81 ,
V_78 -> V_82 ,
V_78 -> V_83 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_84 * V_67 )
{
F_8 ( V_2 ) ;
if ( V_67 == NULL || V_2 -> V_30 -> V_85 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_85 ( V_2 , V_67 ) ;
}
int F_31 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_86 != NULL )
return V_2 -> V_30 -> V_86 ( V_2 ) ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , const struct V_35 * V_87 ,
T_1 V_88 , T_2 V_89 ,
T_3 * V_50 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_90 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_90 ( V_2 , V_87 , V_88 , V_89 , V_50 ) ;
}
int F_33 ( struct V_1 * V_2 , const struct V_35 * V_87 , struct V_91 * V_92 ,
T_1 V_88 )
{
int V_93 ;
T_3 V_94 ;
F_8 ( V_2 ) ;
F_34 ((NULL != state), L_1 , return -EINVAL) ;
F_34 ((NULL != pclock_info), L_1 , return -EINVAL) ;
V_93 = F_32 ( V_2 , V_87 , V_95 , 0 , & V_94 ) ;
F_34 ((0 == result), L_2 , return result) ;
V_92 -> V_96 = V_94 . V_97 ;
V_92 -> V_98 = V_94 . V_99 ;
V_92 -> V_100 = V_94 . V_101 * V_94 . V_102 ;
V_93 = F_32 ( V_2 , V_87 , V_88 ,
( V_2 -> V_3 . V_103 - 1 ) , & V_94 ) ;
F_34 ((0 == result), L_3 , return result) ;
V_92 -> V_104 = V_94 . V_97 ;
V_92 -> V_105 = V_94 . V_99 ;
V_92 -> V_106 = V_94 . V_101 * V_94 . V_102 ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , const struct V_35 * V_87 , struct V_91 * V_107 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_108 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_108 ( V_2 , V_87 , V_107 ) ;
}
int F_36 ( struct V_1 * V_2 , enum V_109 type , struct V_110 * V_111 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_112 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_112 ( V_2 , type , V_111 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_84 * V_111 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_113 == NULL )
return - V_66 ;
return V_2 -> V_30 -> V_113 ( V_2 , V_111 ) ;
}
