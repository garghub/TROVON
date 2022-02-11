int F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 )
{
const struct V_1 * V_6 ;
int V_7 = V_2 -> V_8 ;
int V_9 = V_2 -> V_10 ;
T_1 V_11 = F_2 ( (struct V_1 * ) V_2 ) ;
F_3 (sk2, &tb->owners) {
if ( V_2 != V_6 &&
( ! V_2 -> V_12 ||
! V_6 -> V_12 ||
V_2 -> V_12 == V_6 -> V_12 ) ) {
if ( ( ! V_7 || ! V_6 -> V_8 ||
V_6 -> V_13 == V_14 ) &&
( ! V_9 || ! V_6 -> V_10 ||
( V_6 -> V_13 != V_15 &&
! F_4 ( V_11 ,
F_2 ( (struct V_1 * ) V_6 ) ) ) ) ) {
if ( F_5 ( V_2 , V_6 ) )
break;
}
}
}
return V_6 != NULL ;
}
struct V_16 * F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_21 * V_22 = F_7 ( V_20 ) ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_25 * V_26 , V_27 ;
struct V_16 * V_28 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_29 = V_30 ;
V_18 -> V_31 = V_22 -> V_32 ;
V_26 = F_9 ( V_18 , V_24 -> V_33 , & V_27 ) ;
V_18 -> V_34 = V_22 -> V_35 ;
V_18 -> V_36 = V_22 -> V_37 ;
V_18 -> V_38 = V_2 -> V_39 ;
V_18 -> V_40 = F_10 ( V_20 ) -> V_41 ;
V_18 -> V_42 = F_10 ( V_20 ) -> V_43 ;
F_11 ( V_20 , F_12 ( V_18 ) ) ;
V_28 = F_13 ( V_2 , V_18 , V_26 , false ) ;
if ( F_14 ( V_28 ) )
return NULL ;
return V_28 ;
}
static T_2 F_15 ( const struct V_25 * V_44 , const T_3 V_45 ,
const T_2 V_46 , const T_2 V_47 )
{
T_2 V_48 ;
V_48 = F_16 ( ( V_49 T_2 ) V_44 -> V_50 [ 0 ] ,
( V_49 T_2 ) V_44 -> V_50 [ 1 ] ,
( V_49 T_2 ) V_44 -> V_50 [ 2 ] ,
V_46 ) ;
V_48 = F_17 ( ( V_49 T_2 ) V_44 -> V_50 [ 3 ] ,
( V_49 T_2 ) V_45 ,
V_48 ) ;
return V_48 & ( V_47 - 1 ) ;
}
struct V_19 * F_18 ( const struct V_1 * V_2 ,
struct V_19 * * * V_51 ,
const T_3 V_45 ,
const struct V_25 * V_44 ,
const struct V_25 * V_52 ,
const int V_37 )
{
const struct V_53 * V_54 = F_19 ( V_2 ) ;
struct V_55 * V_56 = V_54 -> V_57 . V_58 ;
struct V_19 * V_20 , * * V_59 ;
for ( V_59 = & V_56 -> V_60 [ F_15 ( V_44 , V_45 ,
V_56 -> V_61 ,
V_56 -> V_62 ) ] ;
( V_20 = * V_59 ) != NULL ;
V_59 = & V_20 -> V_63 ) {
const struct V_21 * V_22 = F_7 ( V_20 ) ;
if ( F_10 ( V_20 ) -> V_41 == V_45 &&
V_20 -> V_64 -> V_65 == V_66 &&
F_20 ( & V_22 -> V_32 , V_44 ) &&
F_20 ( & V_22 -> V_35 , V_52 ) &&
( ! V_22 -> V_37 || V_22 -> V_37 == V_37 ) ) {
F_21 ( V_20 -> V_2 != NULL ) ;
* V_51 = V_59 ;
return V_20 ;
}
}
return NULL ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const unsigned long V_67 )
{
struct V_53 * V_54 = F_19 ( V_2 ) ;
struct V_55 * V_56 = V_54 -> V_57 . V_58 ;
const T_2 V_68 = F_15 ( & F_7 ( V_20 ) -> V_32 ,
F_10 ( V_20 ) -> V_41 ,
V_56 -> V_61 , V_56 -> V_62 ) ;
F_23 ( & V_54 -> V_57 , V_68 , V_20 , V_67 ) ;
F_24 ( V_2 , V_67 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_71 * V_72 = (struct V_71 * ) V_70 ;
V_72 -> V_73 = V_66 ;
V_72 -> V_74 = V_24 -> V_31 ;
V_72 -> V_75 = F_26 ( V_2 ) -> V_76 ;
V_72 -> V_77 = 0 ;
V_72 -> V_78 = 0 ;
if ( V_2 -> V_12 &&
F_27 ( & V_72 -> V_74 ) & V_79 )
V_72 -> V_78 = V_2 -> V_12 ;
}
static inline
void F_28 ( struct V_1 * V_2 , struct V_16 * V_28 ,
const struct V_25 * V_31 ,
const struct V_25 * V_34 )
{
F_29 ( V_2 , V_28 , V_31 , V_34 ) ;
}
static inline
struct V_16 * F_30 ( struct V_1 * V_2 , T_2 V_80 )
{
return F_31 ( V_2 , V_80 ) ;
}
static struct V_16 * F_32 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_81 * V_82 = F_26 ( V_2 ) ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_25 * V_26 , V_27 ;
struct V_16 * V_28 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_29 = V_2 -> V_83 ;
V_18 -> V_31 = V_24 -> V_31 ;
V_18 -> V_34 = V_24 -> V_34 ;
V_18 -> V_84 = V_24 -> V_85 ;
F_33 ( V_2 , V_18 -> V_84 ) ;
V_18 -> V_36 = V_2 -> V_12 ;
V_18 -> V_38 = V_2 -> V_39 ;
V_18 -> V_42 = V_82 -> V_86 ;
V_18 -> V_40 = V_82 -> V_76 ;
F_34 ( V_2 , F_12 ( V_18 ) ) ;
V_26 = F_9 ( V_18 , V_24 -> V_33 , & V_27 ) ;
V_28 = F_30 ( V_2 , V_24 -> V_87 ) ;
if ( ! V_28 ) {
V_28 = F_13 ( V_2 , V_18 , V_26 , false ) ;
if ( ! F_14 ( V_28 ) )
F_28 ( V_2 , V_28 , NULL , NULL ) ;
}
return V_28 ;
}
int F_35 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_17 V_18 ;
struct V_16 * V_28 ;
int V_92 ;
V_28 = F_32 ( V_2 , & V_18 ) ;
if ( F_14 ( V_28 ) ) {
V_2 -> V_93 = - F_36 ( V_28 ) ;
V_2 -> V_94 = 0 ;
F_37 ( V_89 ) ;
return F_36 ( V_28 ) ;
}
F_38 () ;
F_39 ( V_89 , V_28 ) ;
V_18 . V_31 = V_24 -> V_31 ;
V_92 = F_40 ( V_2 , V_89 , & V_18 , V_24 -> V_33 , V_24 -> V_95 ) ;
F_41 () ;
return V_92 ;
}
struct V_16 * F_42 ( struct V_1 * V_2 , T_2 V_96 )
{
struct V_17 V_18 ;
struct V_16 * V_28 = F_32 ( V_2 , & V_18 ) ;
if ( F_14 ( V_28 ) )
return NULL ;
V_28 -> V_97 -> V_98 ( V_28 , V_2 , NULL , V_96 ) ;
V_28 = F_32 ( V_2 , & V_18 ) ;
return F_14 ( V_28 ) ? NULL : V_28 ;
}
