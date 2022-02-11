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
int F_15 ( struct V_1 * V_2 , enum V_47 V_48 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_49 != NULL )
return V_2 -> V_30 -> V_49 ( V_2 , V_48 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
const struct V_50 * V_52 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_53 != NULL )
return V_2 -> V_30 -> V_53 (
V_2 ,
V_51 ,
V_52 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_54 != NULL )
return V_2 -> V_30 -> V_54 ( V_2 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , bool V_55 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_56 != NULL )
return V_2 -> V_30 -> V_56 ( V_2 , V_55 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , bool V_55 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_57 != NULL )
return V_2 -> V_30 -> V_57 ( V_2 , V_55 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_58 )
return V_2 -> V_30 -> V_58 ( V_2 ) ;
} else {
return F_10 ( V_2 , & ( V_2 -> V_59 ) , NULL , NULL ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) ) {
if ( NULL != V_2 -> V_30 -> V_60 )
V_2 -> V_30 -> V_60 ( V_2 ) ;
} else
return F_10 ( V_2 , & V_2 -> V_61 , NULL , NULL ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( F_9 ( V_2 -> V_3 . V_4 ,
V_29 ) )
if ( NULL != V_2 -> V_30 -> V_62 )
V_2 -> V_30 -> V_62 ( V_2 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_63 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_63 ( V_2 ) ;
}
int F_24 ( struct V_1 * V_2 , const void * V_65 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_66 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_66 ( V_2 , V_65 ) ;
}
int F_25 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
return F_10 ( V_2 , & ( V_2 -> V_69 ) , V_68 , NULL ) ;
}
bool F_26 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_70 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_70 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 ,
const struct V_35 * V_71 ,
const struct V_35 * V_72 ,
bool * V_73 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_74 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_74 ( V_2 , V_71 , V_72 , V_73 ) ;
}
int F_28 ( struct V_1 * V_2 ,
const struct V_75 * V_76 )
{
F_8 ( V_2 ) ;
if ( V_76 == NULL )
return - V_64 ;
V_2 -> V_76 = * V_76 ;
if ( V_2 -> V_30 -> V_77 == NULL )
return - V_64 ;
if ( V_2 -> V_30 -> V_77 )
V_2 -> V_30 -> V_77 ( V_2 ,
V_76 -> V_78 ,
V_76 -> V_79 ,
V_76 -> V_80 ,
V_76 -> V_81 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_82 * V_65 )
{
F_8 ( V_2 ) ;
if ( V_65 == NULL || V_2 -> V_30 -> V_83 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_83 ( V_2 , V_65 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_84 != NULL )
return V_2 -> V_30 -> V_84 ( V_2 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_35 * V_85 ,
T_1 V_86 , T_2 V_87 ,
T_3 * V_48 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_88 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_88 ( V_2 , V_85 , V_86 , V_87 , V_48 ) ;
}
int F_32 ( struct V_1 * V_2 , const struct V_35 * V_85 , struct V_89 * V_90 ,
T_1 V_86 )
{
int V_91 ;
T_3 V_92 ;
F_8 ( V_2 ) ;
F_33 ((NULL != state), L_1 , return -EINVAL) ;
F_33 ((NULL != pclock_info), L_1 , return -EINVAL) ;
V_91 = F_31 ( V_2 , V_85 , V_93 , 0 , & V_92 ) ;
F_33 ((0 == result), L_2 , return result) ;
V_90 -> V_94 = V_92 . V_95 ;
V_90 -> V_96 = V_92 . V_97 ;
V_90 -> V_98 = V_92 . V_99 * V_92 . V_100 ;
V_91 = F_31 ( V_2 , V_85 , V_86 ,
( V_2 -> V_3 . V_101 - 1 ) , & V_92 ) ;
F_33 ((0 == result), L_3 , return result) ;
V_90 -> V_102 = V_92 . V_95 ;
V_90 -> V_103 = V_92 . V_97 ;
V_90 -> V_104 = V_92 . V_99 * V_92 . V_100 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , const struct V_35 * V_85 , struct V_89 * V_105 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_106 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_106 ( V_2 , V_85 , V_105 ) ;
}
int F_35 ( struct V_1 * V_2 , enum V_107 type , struct V_108 * V_109 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_110 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_110 ( V_2 , type , V_109 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_82 * V_109 )
{
F_8 ( V_2 ) ;
if ( V_2 -> V_30 -> V_111 == NULL )
return - V_64 ;
return V_2 -> V_30 -> V_111 ( V_2 , V_109 ) ;
}
