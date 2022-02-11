int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 )
{
const struct V_1 * V_6 ;
const struct V_7 * V_8 ;
F_2 (sk2, node, &tb->owners) {
if ( V_2 != V_6 &&
( ! V_2 -> V_9 ||
! V_6 -> V_9 ||
V_2 -> V_9 == V_6 -> V_9 ) &&
( ! V_2 -> V_10 || ! V_6 -> V_10 ||
V_6 -> V_11 == V_12 ) &&
F_3 ( V_2 , V_6 ) )
break;
}
return V_8 != NULL ;
}
struct V_13 * F_4 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = F_5 ( V_15 ) ;
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_20 * V_21 , V_22 ;
struct V_13 * V_23 ;
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_27 ;
V_25 . V_28 = V_17 -> V_29 ;
V_21 = F_7 ( & V_25 , V_19 -> V_30 , & V_22 ) ;
V_25 . V_31 = V_17 -> V_32 ;
V_25 . V_33 = V_2 -> V_9 ;
V_25 . V_34 = V_2 -> V_35 ;
V_25 . V_36 = F_8 ( V_15 ) -> V_37 ;
V_25 . V_38 = F_8 ( V_15 ) -> V_39 ;
F_9 ( V_15 , F_10 ( & V_25 ) ) ;
V_23 = F_11 ( V_2 , & V_25 , V_21 , false ) ;
if ( F_12 ( V_23 ) )
return NULL ;
return V_23 ;
}
static T_1 F_13 ( const struct V_20 * V_40 , const T_2 V_41 ,
const T_1 V_42 , const T_1 V_43 )
{
T_1 V_44 ;
V_44 = F_14 ( ( V_45 T_1 ) V_40 -> V_46 [ 0 ] ,
( V_45 T_1 ) V_40 -> V_46 [ 1 ] ,
( V_45 T_1 ) V_40 -> V_46 [ 2 ] ,
V_42 ) ;
V_44 = F_15 ( ( V_45 T_1 ) V_40 -> V_46 [ 3 ] ,
( V_45 T_1 ) V_41 ,
V_44 ) ;
return V_44 & ( V_43 - 1 ) ;
}
struct V_14 * F_16 ( const struct V_1 * V_2 ,
struct V_14 * * * V_47 ,
const T_2 V_41 ,
const struct V_20 * V_40 ,
const struct V_20 * V_48 ,
const int V_49 )
{
const struct V_50 * V_51 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
struct V_14 * V_15 , * * V_56 ;
for ( V_56 = & V_53 -> V_57 [ F_13 ( V_40 , V_41 ,
V_53 -> V_58 ,
V_53 -> V_59 ) ] ;
( V_15 = * V_56 ) != NULL ;
V_56 = & V_15 -> V_60 ) {
const struct V_16 * V_17 = F_5 ( V_15 ) ;
if ( F_8 ( V_15 ) -> V_37 == V_41 &&
V_15 -> V_61 -> V_62 == V_63 &&
F_18 ( & V_17 -> V_29 , V_40 ) &&
F_18 ( & V_17 -> V_32 , V_48 ) &&
( ! V_17 -> V_49 || V_17 -> V_49 == V_49 ) ) {
F_19 ( V_15 -> V_2 != NULL ) ;
* V_47 = V_56 ;
return V_15 ;
}
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
const unsigned long V_64 )
{
struct V_50 * V_51 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
const T_1 V_65 = F_13 ( & F_5 ( V_15 ) -> V_29 ,
F_8 ( V_15 ) -> V_37 ,
V_53 -> V_58 , V_53 -> V_59 ) ;
F_21 ( & V_51 -> V_54 , V_65 , V_15 , V_64 ) ;
F_22 ( V_2 , V_64 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_68 * V_69 = (struct V_68 * ) V_67 ;
V_69 -> V_70 = V_63 ;
V_69 -> V_71 = V_19 -> V_28 ;
V_69 -> V_72 = F_24 ( V_2 ) -> V_73 ;
V_69 -> V_74 = 0 ;
V_69 -> V_75 = 0 ;
if ( V_2 -> V_9 &&
F_25 ( & V_69 -> V_71 ) & V_76 )
V_69 -> V_75 = V_2 -> V_9 ;
}
static inline
void F_26 ( struct V_1 * V_2 , struct V_13 * V_23 ,
struct V_20 * V_28 , struct V_20 * V_31 )
{
F_27 ( V_2 , V_23 , V_28 , V_31 ) ;
#ifdef F_28
{
struct V_77 * V_78 = (struct V_77 * ) V_23 ;
V_78 -> V_79 = F_29 ( & V_80 ) ;
}
#endif
}
static inline
struct V_13 * F_30 ( struct V_1 * V_2 , T_1 V_81 )
{
struct V_13 * V_23 ;
V_23 = F_31 ( V_2 , V_81 ) ;
#ifdef F_28
if ( V_23 ) {
struct V_77 * V_78 = (struct V_77 * ) V_23 ;
if ( V_78 -> V_79 != F_29 ( & V_80 ) ) {
F_32 ( V_2 ) ;
V_23 = NULL ;
}
}
#endif
return V_23 ;
}
int F_33 ( struct V_82 * V_83 , struct V_84 * V_85 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_86 * V_87 = F_24 ( V_2 ) ;
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_24 V_25 ;
struct V_13 * V_23 ;
struct V_20 * V_21 , V_22 ;
int V_88 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = V_2 -> V_89 ;
V_25 . V_28 = V_19 -> V_28 ;
V_25 . V_31 = V_19 -> V_31 ;
V_25 . V_90 = V_19 -> V_91 ;
F_34 ( V_2 , V_25 . V_90 ) ;
V_25 . V_33 = V_2 -> V_9 ;
V_25 . V_34 = V_2 -> V_35 ;
V_25 . V_38 = V_87 -> V_92 ;
V_25 . V_36 = V_87 -> V_73 ;
F_35 ( V_2 , F_10 ( & V_25 ) ) ;
V_21 = F_7 ( & V_25 , V_19 -> V_30 , & V_22 ) ;
V_23 = F_30 ( V_2 , V_19 -> V_93 ) ;
if ( V_23 == NULL ) {
V_23 = F_11 ( V_2 , & V_25 , V_21 , false ) ;
if ( F_12 ( V_23 ) ) {
V_2 -> V_94 = - F_36 ( V_23 ) ;
V_2 -> V_95 = 0 ;
F_37 ( V_83 ) ;
return F_36 ( V_23 ) ;
}
F_26 ( V_2 , V_23 , NULL , NULL ) ;
}
F_38 () ;
F_39 ( V_83 , V_23 ) ;
V_25 . V_28 = V_19 -> V_28 ;
V_88 = F_40 ( V_2 , V_83 , & V_25 , V_19 -> V_30 , V_19 -> V_96 ) ;
F_41 () ;
return V_88 ;
}
