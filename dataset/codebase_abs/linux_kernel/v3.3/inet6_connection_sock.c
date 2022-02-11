int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_1 * V_5 ;
const struct V_6 * V_7 ;
F_2 (sk2, node, &tb->owners) {
if ( V_2 != V_5 &&
( ! V_2 -> V_8 ||
! V_5 -> V_8 ||
V_2 -> V_8 == V_5 -> V_8 ) &&
( ! V_2 -> V_9 || ! V_5 -> V_9 ||
V_5 -> V_10 == V_11 ) &&
F_3 ( V_2 , V_5 ) )
break;
}
return V_7 != NULL ;
}
struct V_12 * F_4 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_15 * V_16 = F_5 ( V_14 ) ;
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_19 * V_20 , V_21 ;
struct V_12 * V_22 ;
struct V_23 V_24 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 = V_26 ;
V_24 . V_27 = V_16 -> V_28 ;
V_20 = F_7 ( & V_24 , V_18 -> V_29 , & V_21 ) ;
V_24 . V_30 = V_16 -> V_31 ;
V_24 . V_32 = V_2 -> V_8 ;
V_24 . V_33 = V_2 -> V_34 ;
V_24 . V_35 = F_8 ( V_14 ) -> V_36 ;
V_24 . V_37 = F_8 ( V_14 ) -> V_38 ;
F_9 ( V_14 , F_10 ( & V_24 ) ) ;
V_22 = F_11 ( V_2 , & V_24 , V_20 , false ) ;
if ( F_12 ( V_22 ) )
return NULL ;
return V_22 ;
}
static T_1 F_13 ( const struct V_19 * V_39 , const T_2 V_40 ,
const T_1 V_41 , const T_1 V_42 )
{
T_1 V_43 ;
V_43 = F_14 ( ( V_44 T_1 ) V_39 -> V_45 [ 0 ] ,
( V_44 T_1 ) V_39 -> V_45 [ 1 ] ,
( V_44 T_1 ) V_39 -> V_45 [ 2 ] ,
V_41 ) ;
V_43 = F_15 ( ( V_44 T_1 ) V_39 -> V_45 [ 3 ] ,
( V_44 T_1 ) V_40 ,
V_43 ) ;
return V_43 & ( V_42 - 1 ) ;
}
struct V_13 * F_16 ( const struct V_1 * V_2 ,
struct V_13 * * * V_46 ,
const T_2 V_40 ,
const struct V_19 * V_39 ,
const struct V_19 * V_47 ,
const int V_48 )
{
const struct V_49 * V_50 = F_17 ( V_2 ) ;
struct V_51 * V_52 = V_50 -> V_53 . V_54 ;
struct V_13 * V_14 , * * V_55 ;
for ( V_55 = & V_52 -> V_56 [ F_13 ( V_39 , V_40 ,
V_52 -> V_57 ,
V_52 -> V_58 ) ] ;
( V_14 = * V_55 ) != NULL ;
V_55 = & V_14 -> V_59 ) {
const struct V_15 * V_16 = F_5 ( V_14 ) ;
if ( F_8 ( V_14 ) -> V_36 == V_40 &&
V_14 -> V_60 -> V_61 == V_62 &&
F_18 ( & V_16 -> V_28 , V_39 ) &&
F_18 ( & V_16 -> V_31 , V_47 ) &&
( ! V_16 -> V_48 || V_16 -> V_48 == V_48 ) ) {
F_19 ( V_14 -> V_2 != NULL ) ;
* V_46 = V_55 ;
return V_14 ;
}
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
const unsigned long V_63 )
{
struct V_49 * V_50 = F_17 ( V_2 ) ;
struct V_51 * V_52 = V_50 -> V_53 . V_54 ;
const T_1 V_64 = F_13 ( & F_5 ( V_14 ) -> V_28 ,
F_8 ( V_14 ) -> V_36 ,
V_52 -> V_57 , V_52 -> V_58 ) ;
F_21 ( & V_50 -> V_53 , V_64 , V_14 , V_63 ) ;
F_22 ( V_2 , V_63 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_65 * V_66 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_67 * V_68 = (struct V_67 * ) V_66 ;
V_68 -> V_69 = V_62 ;
V_68 -> V_70 = V_18 -> V_27 ;
V_68 -> V_71 = F_24 ( V_2 ) -> V_72 ;
V_68 -> V_73 = 0 ;
V_68 -> V_74 = 0 ;
if ( V_2 -> V_8 &&
F_25 ( & V_68 -> V_70 ) & V_75 )
V_68 -> V_74 = V_2 -> V_8 ;
}
static inline
void F_26 ( struct V_1 * V_2 , struct V_12 * V_22 ,
struct V_19 * V_27 , struct V_19 * V_30 )
{
F_27 ( V_2 , V_22 , V_27 , V_30 ) ;
#ifdef F_28
{
struct V_76 * V_77 = (struct V_76 * ) V_22 ;
V_77 -> V_78 = F_29 ( & V_79 ) ;
}
#endif
}
static inline
struct V_12 * F_30 ( struct V_1 * V_2 , T_1 V_80 )
{
struct V_12 * V_22 ;
V_22 = F_31 ( V_2 , V_80 ) ;
#ifdef F_28
if ( V_22 ) {
struct V_76 * V_77 = (struct V_76 * ) V_22 ;
if ( V_77 -> V_78 != F_29 ( & V_79 ) ) {
F_32 ( V_2 ) ;
V_22 = NULL ;
}
}
#endif
return V_22 ;
}
int F_33 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_1 * V_2 = V_82 -> V_2 ;
struct V_85 * V_86 = F_24 ( V_2 ) ;
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_23 V_24 ;
struct V_12 * V_22 ;
struct V_19 * V_20 , V_21 ;
int V_87 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_25 = V_2 -> V_88 ;
V_24 . V_27 = V_18 -> V_27 ;
V_24 . V_30 = V_18 -> V_30 ;
V_24 . V_89 = V_18 -> V_90 ;
F_34 ( V_2 , V_24 . V_89 ) ;
V_24 . V_32 = V_2 -> V_8 ;
V_24 . V_33 = V_2 -> V_34 ;
V_24 . V_37 = V_86 -> V_91 ;
V_24 . V_35 = V_86 -> V_72 ;
F_35 ( V_2 , F_10 ( & V_24 ) ) ;
V_20 = F_7 ( & V_24 , V_18 -> V_29 , & V_21 ) ;
V_22 = F_30 ( V_2 , V_18 -> V_92 ) ;
if ( V_22 == NULL ) {
V_22 = F_11 ( V_2 , & V_24 , V_20 , false ) ;
if ( F_12 ( V_22 ) ) {
V_2 -> V_93 = - F_36 ( V_22 ) ;
V_2 -> V_94 = 0 ;
F_37 ( V_82 ) ;
return F_36 ( V_22 ) ;
}
F_26 ( V_2 , V_22 , NULL , NULL ) ;
}
F_38 () ;
F_39 ( V_82 , V_22 ) ;
V_24 . V_27 = V_18 -> V_27 ;
V_87 = F_40 ( V_2 , V_82 , & V_24 , V_18 -> V_29 , V_18 -> V_95 ) ;
F_41 () ;
return V_87 ;
}
