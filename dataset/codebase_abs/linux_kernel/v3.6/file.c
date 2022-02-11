static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_1 , V_4 ) ) {
F_3 ( V_1 ) ;
F_4 ( V_1 , V_4 ) ;
}
if ( ( V_3 -> V_5 & V_6 ) &&
( F_5 ( & V_1 -> V_7 ) == 1 ) &&
! F_6 ( V_1 ) -> V_8 )
{
F_7 ( & F_6 ( V_1 ) -> V_9 ) ;
F_8 ( V_1 ) ;
F_9 ( & F_6 ( V_1 ) -> V_9 ) ;
}
if ( F_10 ( V_1 ) && V_3 -> V_10 )
F_11 ( V_3 -> V_10 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
T_1 * V_11 = F_13 ( V_1 ) ;
F_14 ( * V_11 , ( F_5 ( & F_6 ( V_1 ) -> V_12 ) == 0 ) ) ;
}
static int
F_15 ( struct V_1 * V_1 , const struct V_13 * V_14 ,
unsigned long V_15 , T_2 V_16 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
int V_20 = V_18 -> V_21 - 1 ;
T_3 V_22 = F_16 ( V_14 , V_15 ) ;
T_2 V_23 = V_16 + V_22 ;
if ( V_16 >= V_1 -> V_24 )
return 0 ;
if ( ( V_16 & V_20 ) || ( V_23 & V_20 ) )
return 1 ;
return 0 ;
}
static T_4
F_17 ( struct V_25 * V_26 , const struct V_13 * V_14 ,
unsigned long V_15 , T_2 V_16 )
{
struct V_2 * V_2 = V_26 -> V_27 ;
struct V_1 * V_1 = V_2 -> V_28 -> V_29 ;
struct V_30 V_31 ;
int V_32 = 0 ;
T_4 V_33 ;
int V_34 = 0 ;
T_3 V_35 = F_16 ( V_14 , V_15 ) ;
if ( F_18 ( V_1 , V_36 ) &&
! F_19 ( V_26 ) )
V_32 = F_15 ( V_1 , V_14 , V_15 , V_16 ) ;
if ( V_32 ) {
static unsigned long V_37 ;
if ( F_20 ( & V_37 , 60 * 60 * 24 * V_38 ) )
F_21 ( V_1 -> V_19 , V_39 ,
L_1
L_2 ,
V_1 -> V_40 , V_41 -> V_42 ) ;
F_22 ( F_23 ( V_1 ) ) ;
F_12 ( V_1 ) ;
}
F_24 ( V_26 -> V_43 != V_16 ) ;
F_22 ( & V_1 -> V_44 ) ;
F_25 ( & V_31 ) ;
V_26 -> V_45 = & V_34 ;
if ( F_26 ( V_1 ) && ! V_32 &&
! V_2 -> V_28 -> V_46 && V_16 + V_35 <= F_27 ( V_1 ) ) {
struct V_47 V_48 ;
unsigned int V_49 = V_1 -> V_50 ;
int V_51 , V_52 ;
V_48 . V_53 = V_16 >> V_49 ;
V_48 . V_54 = ( F_28 ( V_16 + V_35 , V_49 ) >> V_49 )
- V_48 . V_53 ;
V_52 = V_48 . V_54 ;
V_51 = V_47 ( NULL , V_1 , & V_48 , 0 ) ;
if ( V_51 == V_52 && ( V_48 . V_55 & V_56 ) )
V_34 = 1 ;
}
V_33 = F_29 ( V_26 , V_14 , V_15 , & V_26 -> V_43 ) ;
F_30 ( & V_1 -> V_44 ) ;
if ( V_33 > 0 || V_33 == - V_57 ) {
T_4 V_51 ;
V_51 = F_31 ( V_2 , V_16 , V_33 ) ;
if ( V_51 < 0 && V_33 > 0 )
V_33 = V_51 ;
}
F_32 ( & V_31 ) ;
if ( V_32 )
F_30 ( F_23 ( V_1 ) ) ;
return V_33 ;
}
static T_4
F_33 ( struct V_25 * V_26 , const struct V_13 * V_14 ,
unsigned long V_15 , T_2 V_16 )
{
struct V_1 * V_1 = V_26 -> V_27 -> V_58 . V_59 -> V_60 ;
T_4 V_33 ;
if ( ! ( F_18 ( V_1 , V_36 ) ) ) {
struct V_61 * V_62 = F_34 ( V_1 -> V_19 ) ;
T_3 V_35 = F_16 ( V_14 , V_15 ) ;
if ( ( V_16 > V_62 -> V_63 ||
( V_16 == V_62 -> V_63 && V_35 > 0 ) ) )
return - V_64 ;
if ( V_16 + V_35 > V_62 -> V_63 ) {
V_15 = F_35 ( (struct V_13 * ) V_14 , V_15 ,
V_62 -> V_63 - V_16 ) ;
}
}
if ( F_36 ( V_26 -> V_27 -> V_65 & V_66 ) )
V_33 = F_17 ( V_26 , V_14 , V_15 , V_16 ) ;
else
V_33 = F_37 ( V_26 , V_14 , V_15 , V_16 ) ;
return V_33 ;
}
static int F_38 ( struct V_2 * V_2 , struct V_67 * V_68 )
{
struct V_69 * V_70 = V_2 -> V_28 ;
if ( ! V_70 -> V_71 -> V_72 )
return - V_73 ;
F_39 ( V_2 ) ;
V_68 -> V_74 = & V_75 ;
V_68 -> V_76 |= V_77 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_61 * V_62 = F_34 ( V_1 -> V_19 ) ;
struct V_78 * V_79 = F_6 ( V_1 ) ;
struct V_80 * V_81 = V_3 -> V_58 . V_81 ;
struct V_82 V_82 ;
char V_83 [ 64 ] , * V_84 ;
if ( F_36 ( ! ( V_62 -> V_85 & V_86 ) &&
! ( V_18 -> V_87 & V_88 ) ) ) {
V_62 -> V_85 |= V_86 ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
V_82 . V_81 = V_81 ;
V_82 . V_59 = V_81 -> V_89 ;
V_84 = F_41 ( & V_82 , V_83 , sizeof( V_83 ) ) ;
if ( ! F_42 ( V_84 ) ) {
T_5 * V_90 ;
int V_51 ;
V_90 = F_43 ( V_18 , 1 ) ;
if ( F_42 ( V_90 ) )
return F_44 ( V_90 ) ;
V_51 = F_45 ( V_90 , V_62 -> V_91 ) ;
if ( V_51 ) {
F_46 ( V_90 ) ;
return V_51 ;
}
F_47 ( V_62 -> V_92 -> V_93 , V_84 ,
sizeof( V_62 -> V_92 -> V_93 ) ) ;
F_48 ( V_90 , V_18 ) ;
F_46 ( V_90 ) ;
}
}
if ( V_62 -> V_94 && ! V_79 -> V_95 && ( V_3 -> V_5 & V_6 ) ) {
struct V_96 * V_95 = F_49 ( V_97 ) ;
F_50 ( & V_1 -> V_98 ) ;
if ( ! V_79 -> V_95 ) {
if ( ! V_95 ) {
F_51 ( & V_1 -> V_98 ) ;
return - V_99 ;
}
V_79 -> V_95 = V_95 ;
F_52 ( V_79 -> V_95 , V_1 ) ;
V_95 = NULL ;
}
F_51 ( & V_1 -> V_98 ) ;
if ( F_36 ( V_95 != NULL ) )
F_53 ( V_95 ) ;
}
return F_54 ( V_1 , V_3 ) ;
}
T_2 F_55 ( struct V_2 * V_2 , T_2 V_100 , int V_101 )
{
struct V_1 * V_1 = V_2 -> V_28 -> V_29 ;
T_2 V_102 ;
if ( ! ( F_18 ( V_1 , V_36 ) ) )
V_102 = F_34 ( V_1 -> V_19 ) -> V_63 ;
else
V_102 = V_1 -> V_19 -> V_103 ;
return F_56 ( V_2 , V_100 , V_101 ,
V_102 , F_27 ( V_1 ) ) ;
}
