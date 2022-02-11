static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_2 * V_5 , int V_6 )
{
struct V_7 * V_8 = V_5 -> V_8 ;
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_9 * V_9 = V_3 -> V_10 -> V_11 -> V_9 ;
unsigned int V_12 ;
if ( V_6 != V_13 )
V_6 = V_14 ;
if ( V_3 -> V_15 == V_6 )
return;
F_4 ( V_8 -> V_8 ) ;
if ( V_6 != V_13 ) {
F_5 ( V_9 , V_16 , V_17 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
( V_12 & V_17 ) )
F_7 () ;
F_5 ( V_9 , V_16 , V_19 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
( V_12 & V_19 ) )
F_7 () ;
F_5 ( V_9 , V_16 , V_20 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
( V_12 & V_20 ) )
F_7 () ;
F_8 ( V_3 -> V_10 -> V_11 -> V_21 ) ;
F_9 ( V_8 -> V_8 ) ;
} else {
F_10 ( V_8 -> V_8 ) ;
F_11 ( V_3 -> V_10 -> V_11 -> V_21 ) ;
F_5 ( V_9 , V_22 , V_20 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
! ( V_12 & V_20 ) )
F_7 () ;
F_5 ( V_9 , V_22 , V_19 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
! ( V_12 & V_19 ) )
F_7 () ;
F_5 ( V_9 , V_22 , V_17 ) ;
while ( ! F_6 ( V_9 , V_18 , & V_12 ) &&
! ( V_12 & V_17 ) )
F_7 () ;
}
F_12 ( V_8 -> V_8 ) ;
V_3 -> V_15 = V_6 ;
}
static int F_13 ( struct V_2 * V_5 ,
struct V_23 * V_6 ,
struct V_23 * V_24 ,
int V_25 , int V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_9 * V_9 = V_3 -> V_10 -> V_11 -> V_9 ;
struct V_29 * V_30 = V_5 -> V_31 ;
struct V_27 * V_32 ;
unsigned long V_33 ;
struct V_34 V_35 ;
unsigned long V_36 ;
unsigned int V_37 ;
int div ;
if ( F_14 ( V_3 -> V_10 , V_24 ) != V_38 )
return - V_39 ;
V_35 . V_40 = V_24 -> V_41 - V_24 -> V_42 ;
V_35 . V_43 = V_24 -> V_44 - V_24 -> V_45 ;
V_35 . V_46 = V_24 -> V_45 - V_24 -> V_41 ;
V_35 . V_47 = V_24 -> V_48 - V_24 -> V_49 ;
V_35 . V_50 = V_24 -> V_51 - V_24 -> V_52 ;
V_35 . V_53 = V_24 -> V_52 - V_24 -> V_48 ;
F_5 ( V_9 , F_15 ( 1 ) ,
( V_35 . V_53 - 1 ) | ( ( V_35 . V_46 - 1 ) << 16 ) ) ;
F_5 ( V_9 , F_15 ( 2 ) ,
( V_35 . V_40 - 1 ) | ( V_35 . V_43 << 16 ) ) ;
F_5 ( V_9 , F_15 ( 3 ) ,
( V_35 . V_47 - 1 ) | ( ( V_35 . V_50 - 1 ) << 16 ) ) ;
F_5 ( V_9 , F_15 ( 4 ) ,
( V_24 -> V_49 - 1 ) |
( ( V_24 -> V_42 - 1 ) << 16 ) ) ;
V_37 = 0 ;
V_36 = F_16 ( V_3 -> V_10 -> V_11 -> V_21 ) ;
V_33 = V_6 -> V_54 * 1000 ;
if ( ( V_36 / 2 ) < V_33 ) {
V_36 *= 2 ;
V_37 |= V_55 ;
}
div = F_17 ( V_36 , V_33 ) ;
if ( div < 2 )
div = 2 ;
V_37 |= F_18 ( div ) ;
F_19 ( V_9 , F_15 ( 0 ) ,
V_55 | V_56 |
V_57 , V_37 ) ;
V_37 = 0 ;
if ( V_6 -> V_58 & V_59 )
V_37 |= V_60 ;
if ( V_6 -> V_58 & V_61 )
V_37 |= V_62 ;
F_19 ( V_9 , F_15 ( 5 ) ,
V_62 | V_60 |
V_63 | V_64 |
V_65 | V_66 |
V_67 | V_68 |
V_69 ,
V_37 ) ;
V_32 = V_30 -> V_32 ;
V_30 -> V_32 = V_28 ;
return F_20 ( V_30 , V_5 , V_32 , 0 , 0 ,
V_24 -> V_70 , V_24 -> V_71 ,
V_25 << 16 , V_26 << 16 ,
V_24 -> V_70 << 16 ,
V_24 -> V_71 << 16 ,
V_24 ) ;
}
int F_21 ( struct V_2 * V_5 , int V_25 , int V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = V_5 -> V_31 ;
struct V_27 * V_32 = V_30 -> V_32 ;
struct V_23 * V_6 = & V_5 -> V_72 ;
V_30 -> V_32 = V_28 ;
return V_30 -> V_73 -> V_74 ( V_30 , V_5 , V_32 ,
0 , 0 ,
V_6 -> V_70 ,
V_6 -> V_71 ,
V_25 << 16 , V_26 << 16 ,
V_6 -> V_70 << 16 ,
V_6 -> V_71 << 16 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
F_3 ( V_3 , V_14 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
F_3 ( V_3 , V_13 ) ;
}
static bool F_24 ( struct V_2 * V_3 ,
const struct V_23 * V_6 ,
struct V_23 * V_75 )
{
return true ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_29 * V_30 ;
F_3 ( V_3 , V_14 ) ;
V_3 -> V_31 -> V_73 -> V_76 ( V_3 -> V_31 ) ;
F_26 (plane, &crtc->dev->mode_config.plane_list) {
if ( V_30 -> V_3 != V_3 )
continue;
V_30 -> V_73 -> V_76 ( V_3 -> V_31 ) ;
V_30 -> V_3 = NULL ;
}
}
static void F_27 ( struct V_2 * V_5 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
F_28 ( V_5 ) ;
F_29 ( V_3 ) ;
}
void F_30 ( struct V_2 * V_5 ,
struct V_77 * V_78 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_79 * V_80 ;
struct V_7 * V_8 = V_5 -> V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_81 , V_58 ) ;
V_80 = V_3 -> V_80 ;
if ( V_80 && V_80 -> V_4 . V_82 == V_78 ) {
V_80 -> V_4 . V_83 ( & V_80 -> V_4 ) ;
F_32 ( V_8 , V_3 -> V_84 ) ;
V_3 -> V_80 = NULL ;
}
F_33 ( & V_8 -> V_81 , V_58 ) ;
}
static void F_34 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_4 . V_8 ;
unsigned long V_58 ;
F_31 ( & V_8 -> V_81 , V_58 ) ;
if ( V_3 -> V_80 ) {
F_35 ( V_8 , V_3 -> V_84 , V_3 -> V_80 ) ;
F_32 ( V_8 , V_3 -> V_84 ) ;
V_3 -> V_80 = NULL ;
}
F_33 ( & V_8 -> V_81 , V_58 ) ;
}
void F_36 ( struct V_2 * V_5 )
{
F_37 ( V_5 -> V_8 , 0 ) ;
F_34 ( F_1 ( V_5 ) ) ;
}
static int F_38 ( struct V_2 * V_5 ,
struct V_27 * V_32 ,
struct V_79 * V_80 ,
T_1 V_85 )
{
struct V_1 * V_3 = F_1 ( V_5 ) ;
struct V_86 V_87 ;
struct V_29 * V_30 = V_5 -> V_31 ;
struct V_7 * V_8 = V_5 -> V_8 ;
unsigned long V_58 ;
int V_88 = 0 ;
F_31 ( & V_8 -> V_81 , V_58 ) ;
if ( V_3 -> V_80 )
V_88 = - V_89 ;
F_33 ( & V_8 -> V_81 , V_58 ) ;
if ( V_88 )
return V_88 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_90 = 0 ;
V_87 . V_91 = 0 ;
V_87 . V_92 = V_5 -> V_6 . V_42 ;
V_87 . V_93 = V_5 -> V_6 . V_49 ;
V_87 . V_94 = V_5 -> V_25 << 16 ;
V_87 . V_95 = V_5 -> V_26 << 16 ;
V_87 . V_96 = V_87 . V_93 << 16 ;
V_87 . V_97 = V_87 . V_92 << 16 ;
V_87 . V_32 = V_32 ;
V_88 = F_39 ( V_30 , & V_87 , & V_5 -> V_72 ) ;
if ( V_88 )
return V_88 ;
if ( V_80 ) {
F_40 ( V_5 -> V_8 , V_3 -> V_84 ) ;
F_31 ( & V_8 -> V_81 , V_58 ) ;
V_3 -> V_80 = V_80 ;
F_33 ( & V_8 -> V_81 , V_58 ) ;
}
V_88 = F_41 ( V_30 , & V_87 ) ;
if ( V_88 )
V_3 -> V_80 = NULL ;
else
V_30 -> V_32 = V_32 ;
return V_88 ;
}
int F_42 ( struct V_7 * V_8 )
{
struct V_98 * V_10 = V_8 -> V_99 ;
struct V_100 * V_101 = V_10 -> V_101 ;
struct V_1 * V_3 ;
int V_88 ;
int V_102 ;
V_3 = F_43 ( sizeof( * V_3 ) , V_103 ) ;
if ( ! V_3 )
return - V_104 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_10 = V_10 ;
V_88 = F_44 ( V_8 , & V_3 -> V_4 ,
& V_101 -> V_31 -> V_4 ,
V_101 -> V_105 ? & V_101 -> V_105 -> V_4 : NULL ,
& V_106 ) ;
if ( V_88 < 0 )
goto V_107;
V_3 -> V_84 = F_45 ( & V_3 -> V_4 ) ;
if ( V_101 -> V_105 )
V_101 -> V_105 -> V_4 . V_108 = 1 << V_3 -> V_84 ;
for ( V_102 = 0 ; V_102 < V_101 -> V_109 ; V_102 ++ )
V_101 -> V_110 [ V_102 ] -> V_4 . V_108 = 1 << V_3 -> V_84 ;
F_46 ( & V_3 -> V_4 , & V_111 ) ;
V_10 -> V_3 = & V_3 -> V_4 ;
return 0 ;
V_107:
F_27 ( & V_3 -> V_4 ) ;
return V_88 ;
}
