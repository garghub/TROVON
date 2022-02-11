bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
int F_2 ( struct V_1 * V_2 , bool V_4 )
{
V_2 -> V_3 = V_4 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_9 )
return V_2 -> V_8 -> V_9 ( V_2 ) ;
} else {
return F_6 ( V_2 , & ( V_2 -> V_10 ) ,
NULL , NULL ) ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_11 )
return V_2 -> V_8 -> V_11 ( V_2 ) ;
} else {
return F_6 ( V_2 , & ( V_2 -> V_12 ) ,
NULL , NULL ) ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
const struct V_13 * V_15 )
{
struct V_16 V_17 ;
F_4 ( V_2 ) ;
V_17 . V_14 = V_14 ;
V_17 . V_18 = V_15 ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_19 )
return V_2 -> V_8 -> V_19 ( V_2 , & V_17 ) ;
} else {
return F_6 ( V_2 , & ( V_2 -> V_20 ) , & V_17 , NULL ) ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_21 = 1 ;
bool V_22 ;
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_23 )
V_21 = V_2 -> V_8 -> V_23 ( V_2 ) ;
} else {
V_21 = F_6 ( V_2 ,
& ( V_2 -> V_24 ) ,
NULL , NULL ) ;
}
V_22 = V_21 == 0 ;
F_10 ( V_2 -> V_25 , V_22 ) ;
return V_21 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_21 = - 1 ;
bool V_22 ;
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( V_2 -> V_8 -> V_26 )
V_21 = V_2 -> V_8 -> V_26 ( V_2 ) ;
} else {
V_21 = F_6 ( V_2 ,
& ( V_2 -> V_27 ) ,
NULL , NULL ) ;
}
V_22 = V_21 == 0 ? false : true ;
F_10 ( V_2 -> V_25 , V_22 ) ;
return V_21 ;
}
int F_12 ( struct V_1 * V_2 , enum V_28 V_29 )
{
int V_21 = 0 ;
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_30 != NULL ) {
V_21 = V_2 -> V_8 -> V_30 ( V_2 , V_29 ) ;
if ( V_21 )
return V_21 ;
if ( V_2 -> V_8 -> V_31 ) {
if ( V_2 -> V_32 == V_33 )
V_21 = V_2 -> V_8 -> V_31 (
V_2 ,
& V_2 -> V_34 ) ;
else if ( V_2 -> V_32 == V_35 )
V_21 = V_2 -> V_8 -> V_31 (
V_2 ,
& V_2 -> V_36 ) ;
}
}
return V_21 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
const struct V_37 * V_39 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_40 != NULL )
return V_2 -> V_8 -> V_40 (
V_2 ,
V_38 ,
V_39 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_41 != NULL )
return V_2 -> V_8 -> V_41 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , bool V_42 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_43 != NULL )
return V_2 -> V_8 -> V_43 ( V_2 , V_42 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_42 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_44 != NULL )
return V_2 -> V_8 -> V_44 ( V_2 , V_42 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_45 )
return V_2 -> V_8 -> V_45 ( V_2 ) ;
} else {
return F_6 ( V_2 , & ( V_2 -> V_46 ) , NULL , NULL ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_47 )
return V_2 -> V_8 -> V_47 ( V_2 ) ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_48 )
V_2 -> V_8 -> V_48 ( V_2 ) ;
} else
return F_6 ( V_2 , & V_2 -> V_49 , NULL , NULL ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) )
if ( NULL != V_2 -> V_8 -> V_50 )
V_2 -> V_8 -> V_50 ( V_2 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_51 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_51 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 , const void * V_53 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_54 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_54 ( V_2 , V_53 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
return F_6 ( V_2 , & ( V_2 -> V_57 ) , V_56 , NULL ) ;
}
bool F_24 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_58 == NULL )
return false ;
return V_2 -> V_8 -> V_58 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_2 ,
const struct V_13 * V_59 ,
const struct V_13 * V_60 ,
bool * V_61 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_62 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_62 ( V_2 , V_59 , V_60 , V_61 ) ;
}
int F_26 ( struct V_1 * V_2 ,
const struct V_63 * V_64 )
{
F_4 ( V_2 ) ;
if ( V_64 == NULL )
return - V_52 ;
V_2 -> V_64 = * V_64 ;
if ( V_2 -> V_8 -> V_65 == NULL )
return - V_52 ;
if ( V_2 -> V_8 -> V_65 )
V_2 -> V_8 -> V_65 ( V_2 ,
V_64 -> V_66 ,
V_64 -> V_67 ,
V_64 -> V_68 ,
V_64 -> V_69 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_70 * V_53 )
{
F_4 ( V_2 ) ;
if ( V_53 == NULL || V_2 -> V_8 -> V_71 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_71 ( V_2 , V_53 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_72 != NULL )
return V_2 -> V_8 -> V_72 ( V_2 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , const struct V_13 * V_73 ,
T_1 V_74 , T_2 V_75 ,
T_3 * V_29 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_76 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_76 ( V_2 , V_73 , V_74 , V_75 , V_29 ) ;
}
int F_30 ( struct V_1 * V_2 , const struct V_13 * V_73 , struct V_77 * V_78 ,
T_1 V_74 )
{
int V_79 ;
T_3 V_80 ;
F_4 ( V_2 ) ;
F_31 ((NULL != state), L_1 , return -EINVAL) ;
F_31 ((NULL != pclock_info), L_1 , return -EINVAL) ;
V_79 = F_29 ( V_2 , V_73 , V_81 , 0 , & V_80 ) ;
F_31 ((0 == result), L_2 , return result) ;
V_78 -> V_82 = V_80 . V_83 ;
V_78 -> V_84 = V_80 . V_85 ;
V_78 -> V_86 = V_80 . V_87 * V_80 . V_88 ;
V_79 = F_29 ( V_2 , V_73 , V_74 ,
( V_2 -> V_5 . V_89 - 1 ) , & V_80 ) ;
F_31 ((0 == result), L_3 , return result) ;
V_78 -> V_90 = V_80 . V_83 ;
V_78 -> V_91 = V_80 . V_85 ;
V_78 -> V_92 = V_80 . V_87 * V_80 . V_88 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 , const struct V_13 * V_73 , struct V_77 * V_93 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_94 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_94 ( V_2 , V_73 , V_93 ) ;
}
int F_33 ( struct V_1 * V_2 , enum V_95 type , struct V_96 * V_97 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_98 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_98 ( V_2 , type , V_97 ) ;
}
int F_34 ( struct V_1 * V_2 ,
enum V_95 type ,
struct V_99 * V_97 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_100 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_100 ( V_2 , type , V_97 ) ;
}
int F_35 ( struct V_1 * V_2 ,
enum V_95 type ,
struct V_101 * V_97 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_102 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_102 ( V_2 , type , V_97 ) ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
F_4 ( V_2 ) ;
if ( ! V_2 -> V_8 -> V_105 )
return - V_52 ;
return V_2 -> V_8 -> V_105 ( V_2 ,
V_104 ) ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_106 * clock )
{
F_4 ( V_2 ) ;
if ( ! V_2 -> V_8 -> V_107 )
return - V_52 ;
return V_2 -> V_8 -> V_107 ( V_2 , clock ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_70 * V_97 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_108 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_108 ( V_2 , V_97 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_109 == NULL )
return - V_52 ;
return V_2 -> V_8 -> V_109 ( V_2 ) ;
}
