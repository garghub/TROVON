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
if ( ! V_5 && V_7 && V_6 -> V_8 &&
V_6 -> V_13 != V_14 &&
F_5 ( V_2 , V_6 ) )
break;
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
V_18 -> V_40 = V_22 -> V_41 ;
V_18 -> V_42 = F_10 ( V_22 -> V_43 ) ;
F_11 ( V_20 , F_12 ( V_18 ) ) ;
V_28 = F_13 ( V_2 , V_18 , V_26 ) ;
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
const int V_53 )
{
const struct V_54 * V_55 = F_19 ( V_2 ) ;
struct V_56 * V_57 = V_55 -> V_58 . V_59 ;
struct V_19 * V_20 , * * V_60 ;
for ( V_60 = & V_57 -> V_61 [ F_15 ( V_44 , V_45 ,
V_57 -> V_62 ,
V_57 -> V_63 ) ] ;
( V_20 = * V_60 ) != NULL ;
V_60 = & V_20 -> V_64 ) {
const struct V_21 * V_22 = F_7 ( V_20 ) ;
if ( V_22 -> V_41 == V_45 &&
V_20 -> V_65 -> V_66 == V_67 &&
F_20 ( & V_22 -> V_32 , V_44 ) &&
F_20 ( & V_22 -> V_35 , V_52 ) &&
( ! V_22 -> V_37 || V_22 -> V_37 == V_53 ) ) {
F_21 ( V_20 -> V_2 != NULL ) ;
* V_51 = V_60 ;
return V_20 ;
}
}
return NULL ;
}
void F_22 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
const unsigned long V_68 )
{
struct V_54 * V_55 = F_19 ( V_2 ) ;
struct V_56 * V_57 = V_55 -> V_58 . V_59 ;
const T_2 V_69 = F_15 ( & F_7 ( V_20 ) -> V_32 ,
F_7 ( V_20 ) -> V_41 ,
V_57 -> V_62 , V_57 -> V_63 ) ;
F_23 ( & V_55 -> V_58 , V_69 , V_20 , V_68 ) ;
F_24 ( V_2 , V_68 ) ;
}
void F_25 ( struct V_1 * V_2 , struct V_70 * V_71 )
{
struct V_72 * V_73 = (struct V_72 * ) V_71 ;
V_73 -> V_74 = V_67 ;
V_73 -> V_75 = V_2 -> V_76 ;
V_73 -> V_77 = F_26 ( V_2 ) -> V_78 ;
V_73 -> V_79 = 0 ;
V_73 -> V_80 = F_27 ( & V_73 -> V_75 ,
V_2 -> V_12 ) ;
}
static inline
void F_28 ( struct V_1 * V_2 , struct V_16 * V_28 ,
const struct V_25 * V_31 ,
const struct V_25 * V_34 )
{
F_29 ( V_2 , V_28 , V_31 , V_34 ) ;
}
static inline
struct V_16 * F_30 ( struct V_1 * V_2 , T_2 V_81 )
{
return F_31 ( V_2 , V_81 ) ;
}
static struct V_16 * F_32 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_82 * V_83 = F_26 ( V_2 ) ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_25 * V_26 , V_27 ;
struct V_16 * V_28 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_29 = V_2 -> V_84 ;
V_18 -> V_31 = V_2 -> V_76 ;
V_18 -> V_34 = V_24 -> V_34 ;
V_18 -> V_85 = V_24 -> V_86 ;
F_33 ( V_2 , V_18 -> V_85 ) ;
V_18 -> V_36 = V_2 -> V_12 ;
V_18 -> V_38 = V_2 -> V_39 ;
V_18 -> V_42 = V_83 -> V_87 ;
V_18 -> V_40 = V_83 -> V_78 ;
F_34 ( V_2 , F_12 ( V_18 ) ) ;
V_26 = F_9 ( V_18 , V_24 -> V_33 , & V_27 ) ;
V_28 = F_30 ( V_2 , V_24 -> V_88 ) ;
if ( ! V_28 ) {
V_28 = F_13 ( V_2 , V_18 , V_26 ) ;
if ( ! F_14 ( V_28 ) )
F_28 ( V_2 , V_28 , NULL , NULL ) ;
}
return V_28 ;
}
int F_35 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_23 * V_24 = F_8 ( V_2 ) ;
struct V_17 V_18 ;
struct V_16 * V_28 ;
int V_93 ;
V_28 = F_32 ( V_2 , & V_18 ) ;
if ( F_14 ( V_28 ) ) {
V_2 -> V_94 = - F_36 ( V_28 ) ;
V_2 -> V_95 = 0 ;
F_37 ( V_90 ) ;
return F_36 ( V_28 ) ;
}
F_38 () ;
F_39 ( V_90 , V_28 ) ;
V_18 . V_31 = V_2 -> V_76 ;
V_93 = F_40 ( V_2 , V_90 , & V_18 , V_24 -> V_33 , V_24 -> V_96 ) ;
F_41 () ;
return V_93 ;
}
struct V_16 * F_42 ( struct V_1 * V_2 , T_2 V_97 )
{
struct V_17 V_18 ;
struct V_16 * V_28 = F_32 ( V_2 , & V_18 ) ;
if ( F_14 ( V_28 ) )
return NULL ;
V_28 -> V_98 -> V_99 ( V_28 , V_2 , NULL , V_97 ) ;
V_28 = F_32 ( V_2 , & V_18 ) ;
return F_14 ( V_28 ) ? NULL : V_28 ;
}
