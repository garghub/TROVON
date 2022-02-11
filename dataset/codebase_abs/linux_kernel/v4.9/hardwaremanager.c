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
V_22 = V_21 == 0 ? true : false ;
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
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_30 != NULL )
return V_2 -> V_8 -> V_30 ( V_2 , V_29 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
const struct V_31 * V_33 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_34 != NULL )
return V_2 -> V_8 -> V_34 (
V_2 ,
V_32 ,
V_33 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_35 != NULL )
return V_2 -> V_8 -> V_35 ( V_2 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , bool V_36 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_37 != NULL )
return V_2 -> V_8 -> V_37 ( V_2 , V_36 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_36 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_38 != NULL )
return V_2 -> V_8 -> V_38 ( V_2 , V_36 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_39 )
return V_2 -> V_8 -> V_39 ( V_2 ) ;
} else {
return F_6 ( V_2 , & ( V_2 -> V_40 ) , NULL , NULL ) ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) ) {
if ( NULL != V_2 -> V_8 -> V_41 )
V_2 -> V_8 -> V_41 ( V_2 ) ;
} else
return F_6 ( V_2 , & V_2 -> V_42 , NULL , NULL ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( F_5 ( V_2 -> V_5 . V_6 ,
V_7 ) )
if ( NULL != V_2 -> V_8 -> V_43 )
V_2 -> V_8 -> V_43 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_44 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_44 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 , const void * V_46 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_47 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_47 ( V_2 , V_46 ) ;
}
int F_22 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
return F_6 ( V_2 , & ( V_2 -> V_50 ) , V_49 , NULL ) ;
}
bool F_23 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_51 == NULL )
return false ;
return V_2 -> V_8 -> V_51 ( V_2 ) ;
}
int F_24 ( struct V_1 * V_2 ,
const struct V_13 * V_52 ,
const struct V_13 * V_53 ,
bool * V_54 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_55 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_55 ( V_2 , V_52 , V_53 , V_54 ) ;
}
int F_25 ( struct V_1 * V_2 ,
const struct V_56 * V_57 )
{
F_4 ( V_2 ) ;
if ( V_57 == NULL )
return - V_45 ;
V_2 -> V_57 = * V_57 ;
if ( V_2 -> V_8 -> V_58 == NULL )
return - V_45 ;
if ( V_2 -> V_8 -> V_58 )
V_2 -> V_8 -> V_58 ( V_2 ,
V_57 -> V_59 ,
V_57 -> V_60 ,
V_57 -> V_61 ,
V_57 -> V_62 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_63 * V_46 )
{
F_4 ( V_2 ) ;
if ( V_46 == NULL || V_2 -> V_8 -> V_64 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_64 ( V_2 , V_46 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_65 != NULL )
return V_2 -> V_8 -> V_65 ( V_2 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , const struct V_13 * V_66 ,
T_1 V_67 , T_2 V_68 ,
T_3 * V_29 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_69 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_69 ( V_2 , V_66 , V_67 , V_68 , V_29 ) ;
}
int F_29 ( struct V_1 * V_2 , const struct V_13 * V_66 , struct V_70 * V_71 ,
T_1 V_67 )
{
int V_72 ;
T_3 V_73 ;
F_4 ( V_2 ) ;
F_30 ((NULL != state), L_1 , return -EINVAL) ;
F_30 ((NULL != pclock_info), L_1 , return -EINVAL) ;
V_72 = F_28 ( V_2 , V_66 , V_74 , 0 , & V_73 ) ;
F_30 ((0 == result), L_2 , return result) ;
V_71 -> V_75 = V_73 . V_76 ;
V_71 -> V_77 = V_73 . V_78 ;
V_71 -> V_79 = V_73 . V_80 * V_73 . V_81 ;
V_72 = F_28 ( V_2 , V_66 , V_67 ,
( V_2 -> V_5 . V_82 - 1 ) , & V_73 ) ;
F_30 ((0 == result), L_3 , return result) ;
V_71 -> V_83 = V_73 . V_76 ;
V_71 -> V_84 = V_73 . V_78 ;
V_71 -> V_85 = V_73 . V_80 * V_73 . V_81 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_13 * V_66 , struct V_70 * V_86 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_87 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_87 ( V_2 , V_66 , V_86 ) ;
}
int F_32 ( struct V_1 * V_2 , enum V_88 type , struct V_89 * V_90 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_91 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_91 ( V_2 , type , V_90 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_63 * V_90 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_8 -> V_92 == NULL )
return - V_45 ;
return V_2 -> V_8 -> V_92 ( V_2 , V_90 ) ;
}
