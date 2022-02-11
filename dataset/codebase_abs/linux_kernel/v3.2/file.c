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
struct V_1 * V_1 = V_26 -> V_27 -> V_28 . V_29 -> V_30 ;
int V_31 = 0 ;
int V_32 ;
if ( ! ( F_18 ( V_1 , V_33 ) ) ) {
struct V_34 * V_35 = F_19 ( V_1 -> V_19 ) ;
T_3 V_36 = F_16 ( V_14 , V_15 ) ;
if ( ( V_16 > V_35 -> V_37 ||
( V_16 == V_35 -> V_37 && V_36 > 0 ) ) )
return - V_38 ;
if ( V_16 + V_36 > V_35 -> V_37 ) {
V_15 = F_20 ( (struct V_13 * ) V_14 , V_15 ,
V_35 -> V_37 - V_16 ) ;
}
} else if ( F_21 ( ( V_26 -> V_27 -> V_39 & V_40 ) &&
! F_22 ( V_26 ) ) ) {
V_31 = F_15 ( V_1 , V_14 , V_15 , V_16 ) ;
}
if ( V_31 ) {
static unsigned long V_41 ;
if ( F_23 ( & V_41 , 60 * 60 * 24 * V_42 ) )
F_24 ( V_1 -> V_19 , V_43 ,
L_1
L_2 ,
V_1 -> V_44 , V_45 -> V_46 ) ;
F_25 ( F_26 ( V_1 ) ) ;
F_12 ( V_1 ) ;
}
V_32 = F_27 ( V_26 , V_14 , V_15 , V_16 ) ;
if ( V_31 )
F_28 ( F_26 ( V_1 ) ) ;
return V_32 ;
}
static int F_29 ( struct V_2 * V_2 , struct V_47 * V_48 )
{
struct V_49 * V_50 = V_2 -> V_51 ;
if ( ! V_50 -> V_52 -> V_53 )
return - V_54 ;
F_30 ( V_2 ) ;
V_48 -> V_55 = & V_56 ;
V_48 -> V_57 |= V_58 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_17 * V_18 = V_1 -> V_19 ;
struct V_34 * V_35 = F_19 ( V_1 -> V_19 ) ;
struct V_59 * V_60 = F_6 ( V_1 ) ;
struct V_61 * V_62 = V_3 -> V_28 . V_62 ;
struct V_63 V_63 ;
char V_64 [ 64 ] , * V_65 ;
if ( F_21 ( ! ( V_35 -> V_66 & V_67 ) &&
! ( V_18 -> V_68 & V_69 ) ) ) {
V_35 -> V_66 |= V_67 ;
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
V_63 . V_62 = V_62 ;
V_63 . V_29 = V_62 -> V_70 ;
V_65 = F_32 ( & V_63 , V_64 , sizeof( V_64 ) ) ;
if ( ! F_33 ( V_65 ) ) {
F_34 ( V_35 -> V_71 -> V_72 , V_65 ,
sizeof( V_35 -> V_71 -> V_72 ) ) ;
F_35 ( V_18 ) ;
}
}
if ( V_35 -> V_73 && ! V_60 -> V_74 && ( V_3 -> V_5 & V_6 ) ) {
struct V_75 * V_74 = F_36 ( V_76 ) ;
F_37 ( & V_1 -> V_77 ) ;
if ( ! V_60 -> V_74 ) {
if ( ! V_74 ) {
F_38 ( & V_1 -> V_77 ) ;
return - V_78 ;
}
V_60 -> V_74 = V_74 ;
F_39 ( V_60 -> V_74 , V_1 ) ;
V_74 = NULL ;
}
F_38 ( & V_1 -> V_77 ) ;
if ( F_21 ( V_74 != NULL ) )
F_40 ( V_74 ) ;
}
return F_41 ( V_1 , V_3 ) ;
}
T_2 F_42 ( struct V_2 * V_2 , T_2 V_79 , int V_80 )
{
struct V_1 * V_1 = V_2 -> V_51 -> V_81 ;
T_2 V_82 ;
if ( ! ( F_18 ( V_1 , V_33 ) ) )
V_82 = F_19 ( V_1 -> V_19 ) -> V_37 ;
else
V_82 = V_1 -> V_19 -> V_83 ;
return F_43 ( V_2 , V_79 , V_80 , V_82 ) ;
}
