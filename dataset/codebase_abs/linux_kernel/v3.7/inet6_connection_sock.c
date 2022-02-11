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
struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 , V_24 ;
struct V_13 * V_25 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 = V_27 ;
V_15 -> V_28 = V_19 -> V_29 ;
V_23 = F_7 ( V_15 , V_21 -> V_30 , & V_24 ) ;
V_15 -> V_31 = V_19 -> V_32 ;
V_15 -> V_33 = V_19 -> V_34 ;
V_15 -> V_35 = V_2 -> V_36 ;
V_15 -> V_37 = F_8 ( V_17 ) -> V_38 ;
V_15 -> V_39 = F_8 ( V_17 ) -> V_40 ;
F_9 ( V_17 , F_10 ( V_15 ) ) ;
V_25 = F_11 ( V_2 , V_15 , V_23 , false ) ;
if ( F_12 ( V_25 ) )
return NULL ;
return V_25 ;
}
static T_1 F_13 ( const struct V_22 * V_41 , const T_2 V_42 ,
const T_1 V_43 , const T_1 V_44 )
{
T_1 V_45 ;
V_45 = F_14 ( ( V_46 T_1 ) V_41 -> V_47 [ 0 ] ,
( V_46 T_1 ) V_41 -> V_47 [ 1 ] ,
( V_46 T_1 ) V_41 -> V_47 [ 2 ] ,
V_43 ) ;
V_45 = F_15 ( ( V_46 T_1 ) V_41 -> V_47 [ 3 ] ,
( V_46 T_1 ) V_42 ,
V_45 ) ;
return V_45 & ( V_44 - 1 ) ;
}
struct V_16 * F_16 ( const struct V_1 * V_2 ,
struct V_16 * * * V_48 ,
const T_2 V_42 ,
const struct V_22 * V_41 ,
const struct V_22 * V_49 ,
const int V_34 )
{
const struct V_50 * V_51 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
struct V_16 * V_17 , * * V_56 ;
for ( V_56 = & V_53 -> V_57 [ F_13 ( V_41 , V_42 ,
V_53 -> V_58 ,
V_53 -> V_59 ) ] ;
( V_17 = * V_56 ) != NULL ;
V_56 = & V_17 -> V_60 ) {
const struct V_18 * V_19 = F_5 ( V_17 ) ;
if ( F_8 ( V_17 ) -> V_38 == V_42 &&
V_17 -> V_61 -> V_62 == V_63 &&
F_18 ( & V_19 -> V_29 , V_41 ) &&
F_18 ( & V_19 -> V_32 , V_49 ) &&
( ! V_19 -> V_34 || V_19 -> V_34 == V_34 ) ) {
F_19 ( V_17 -> V_2 != NULL ) ;
* V_48 = V_56 ;
return V_17 ;
}
}
return NULL ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const unsigned long V_64 )
{
struct V_50 * V_51 = F_17 ( V_2 ) ;
struct V_52 * V_53 = V_51 -> V_54 . V_55 ;
const T_1 V_65 = F_13 ( & F_5 ( V_17 ) -> V_29 ,
F_8 ( V_17 ) -> V_38 ,
V_53 -> V_58 , V_53 -> V_59 ) ;
F_21 ( & V_51 -> V_54 , V_65 , V_17 , V_64 ) ;
F_22 ( V_2 , V_64 ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_20 * V_21 = F_6 ( V_2 ) ;
struct V_68 * V_69 = (struct V_68 * ) V_67 ;
V_69 -> V_70 = V_63 ;
V_69 -> V_71 = V_21 -> V_28 ;
V_69 -> V_72 = F_24 ( V_2 ) -> V_73 ;
V_69 -> V_74 = 0 ;
V_69 -> V_75 = 0 ;
if ( V_2 -> V_9 &&
F_25 ( & V_69 -> V_71 ) & V_76 )
V_69 -> V_75 = V_2 -> V_9 ;
}
static inline
void F_26 ( struct V_1 * V_2 , struct V_13 * V_25 ,
const struct V_22 * V_28 ,
const struct V_22 * V_31 )
{
F_27 ( V_2 , V_25 , V_28 , V_31 ) ;
}
static inline
struct V_13 * F_28 ( struct V_1 * V_2 , T_1 V_77 )
{
return F_29 ( V_2 , V_77 ) ;
}
static struct V_13 * F_30 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_78 * V_79 = F_24 ( V_2 ) ;
struct V_20 * V_21 = F_6 ( V_2 ) ;
struct V_22 * V_23 , V_24 ;
struct V_13 * V_25 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_26 = V_2 -> V_80 ;
V_15 -> V_28 = V_21 -> V_28 ;
V_15 -> V_31 = V_21 -> V_31 ;
V_15 -> V_81 = V_21 -> V_82 ;
F_31 ( V_2 , V_15 -> V_81 ) ;
V_15 -> V_33 = V_2 -> V_9 ;
V_15 -> V_35 = V_2 -> V_36 ;
V_15 -> V_39 = V_79 -> V_83 ;
V_15 -> V_37 = V_79 -> V_73 ;
F_32 ( V_2 , F_10 ( V_15 ) ) ;
V_23 = F_7 ( V_15 , V_21 -> V_30 , & V_24 ) ;
V_25 = F_28 ( V_2 , V_21 -> V_84 ) ;
if ( ! V_25 ) {
V_25 = F_11 ( V_2 , V_15 , V_23 , false ) ;
if ( ! F_12 ( V_25 ) )
F_26 ( V_2 , V_25 , NULL , NULL ) ;
}
return V_25 ;
}
int F_33 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
struct V_1 * V_2 = V_86 -> V_2 ;
struct V_20 * V_21 = F_6 ( V_2 ) ;
struct V_14 V_15 ;
struct V_13 * V_25 ;
int V_89 ;
V_25 = F_30 ( V_2 , & V_15 ) ;
if ( F_12 ( V_25 ) ) {
V_2 -> V_90 = - F_34 ( V_25 ) ;
V_2 -> V_91 = 0 ;
F_35 ( V_86 ) ;
return F_34 ( V_25 ) ;
}
F_36 () ;
F_37 ( V_86 , V_25 ) ;
V_15 . V_28 = V_21 -> V_28 ;
V_89 = F_38 ( V_2 , V_86 , & V_15 , V_21 -> V_30 , V_21 -> V_92 ) ;
F_39 () ;
return V_89 ;
}
struct V_13 * F_40 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_14 V_15 ;
struct V_13 * V_25 = F_30 ( V_2 , & V_15 ) ;
if ( F_12 ( V_25 ) )
return NULL ;
V_25 -> V_94 -> V_95 ( V_25 , V_2 , NULL , V_93 ) ;
V_25 = F_30 ( V_2 , & V_15 ) ;
return F_12 ( V_25 ) ? NULL : V_25 ;
}
