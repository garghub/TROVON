static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 ,
enum V_7 V_8 )
{
unsigned long V_9 ;
F_2 ( & V_2 -> V_10 -> V_11 , L_1 ,
V_12 , V_4 , V_6 , V_8 ) ;
F_3 ( & V_4 -> V_13 , V_9 ) ;
V_4 -> V_14 . V_15 = V_6 ;
V_4 -> V_14 . V_16 = V_8 ;
V_4 -> V_17 |= V_18 ;
V_4 -> V_17 &= ~ ( V_19 |
V_20 ) ;
V_4 -> V_21 = NULL ;
F_4 ( & V_4 -> V_13 , V_9 ) ;
V_4 -> V_22 ( V_4 ) ;
}
static inline int F_5 ( struct V_23 * V_24 ,
struct V_3 * V_4 )
{
return V_24 ? F_6 ( V_25 , & V_24 -> V_9 ) ||
( F_6 ( V_26 , & V_24 -> V_9 ) &&
F_7 ( V_4 ) )
: 0 ;
}
int F_8 ( struct V_3 * V_4 , int V_27 , T_1 V_28 )
{
struct V_1 * V_2 = F_9 ( V_4 -> V_11 ) ;
struct V_23 * V_24 ;
unsigned long V_9 ;
bool V_29 ;
T_2 V_30 ;
F_2 ( & V_2 -> V_10 -> V_11 , L_2 , V_12 , V_27 ) ;
F_10 (num, task) {
enum V_31 V_8 = V_32 ;
F_3 ( & V_2 -> V_33 , V_9 ) ;
V_24 = F_11 ( V_4 -> V_11 ) ;
V_29 = F_5 ( V_24 , V_4 ) ;
V_30 = F_12 ( V_2 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
F_2 ( & V_2 -> V_10 -> V_11 ,
L_3 ,
V_4 , V_27 , V_4 -> V_11 , V_24 , V_24 ? V_24 -> V_9 : 0 ,
V_4 -> V_34 ) ;
if ( ! V_24 ) {
F_1 ( V_2 , V_4 , V_35 ,
V_36 ) ;
} else if ( ! V_29 || V_30 == V_37 ) {
F_1 ( V_2 , V_4 , V_38 ,
V_39 ) ;
} else {
F_3 ( & V_4 -> V_13 , V_9 ) ;
if ( V_4 -> V_17 & V_40 ) {
F_4 ( & V_4 -> V_13 ,
V_9 ) ;
F_1 ( V_2 , V_4 ,
V_35 ,
V_41 ) ;
} else {
V_4 -> V_17 |= V_19 ;
F_4 ( & V_4 -> V_13 , V_9 ) ;
V_8 = F_13 ( V_2 , V_24 , V_4 , V_30 ) ;
if ( V_8 != V_42 ) {
F_3 ( & V_4 -> V_13 , V_9 ) ;
V_4 -> V_17 &= ~ V_19 ;
F_4 ( & V_4 -> V_13 , V_9 ) ;
if ( F_6 ( V_43 , & V_24 -> V_9 ) ) {
F_1 ( V_2 , V_4 ,
V_35 ,
V_36 ) ;
} else {
F_1 ( V_2 , V_4 ,
V_38 ,
V_39 ) ;
}
}
}
}
if ( V_8 != V_42 && V_30 != V_37 ) {
F_3 ( & V_2 -> V_33 , V_9 ) ;
F_14 ( V_2 , F_15 ( V_30 ) ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
}
F_16 ( V_24 ) ;
}
return 0 ;
}
static struct V_44 * F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
T_2 V_30 , struct V_45 * V_45 )
{
enum V_31 V_8 = V_32 ;
struct V_44 * V_46 = NULL ;
struct V_47 * V_11 ;
F_2 ( & V_2 -> V_10 -> V_11 ,
L_4 , V_12 , V_45 ) ;
V_11 = V_24 -> V_48 ;
V_46 = F_18 ( V_2 , V_45 , V_30 ) ;
if ( ! V_46 )
return NULL ;
V_8 = F_19 ( V_2 , V_24 , V_30 ,
V_46 ) ;
if ( V_8 != V_42 ) {
F_20 ( & V_2 -> V_10 -> V_11 ,
L_5
L_6 ,
V_12 ,
V_8 ) ;
return NULL ;
}
if ( V_11 -> V_49 == V_50 ) {
V_45 -> V_51 = V_52 ;
V_8 = F_21 ( V_46 ) ;
if ( V_8 != V_42 )
return NULL ;
}
return V_46 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_45 * V_53 , unsigned long V_54 )
{
F_23 ( V_55 ) ;
enum V_56 V_8 = V_57 ;
struct V_44 * V_46 ;
int V_58 = V_59 ;
unsigned long V_9 ;
unsigned long V_60 ;
T_2 V_30 ;
F_3 ( & V_2 -> V_33 , V_9 ) ;
V_30 = F_12 ( V_2 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
if ( V_30 == V_37 )
return V_58 ;
if ( ! V_24 ||
( ! F_6 ( V_25 , & V_24 -> V_9 ) &&
! F_6 ( V_26 , & V_24 -> V_9 ) ) ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_7 ,
V_12 ,
V_24 , V_24 ? V_24 -> V_9 : 0 ) ;
goto V_61;
} else
F_2 ( & V_2 -> V_10 -> V_11 ,
L_8 ,
V_12 , V_24 ) ;
V_53 -> V_62 = & V_55 ;
V_53 -> V_8 = V_63 ;
V_46 = F_17 ( V_2 , V_24 , V_30 , V_53 ) ;
if ( ! V_46 )
goto V_61;
F_3 ( & V_2 -> V_33 , V_9 ) ;
V_8 = F_24 ( V_2 , V_24 , V_46 ) ;
if ( V_8 != V_64 ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_9 ,
V_12 ,
V_8 ,
V_46 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
goto V_61;
}
F_4 ( & V_2 -> V_33 , V_9 ) ;
F_25 ( V_2 , V_24 ) ;
V_60 = F_26 ( & V_55 ,
F_27 ( V_54 ) ) ;
if ( V_60 == 0 ) {
F_28 ( V_2 , V_24 , V_46 ) ;
}
F_29 ( V_2 , V_53 ) ;
if ( V_53 -> V_8 == V_42 )
V_58 = V_65 ;
else if ( V_53 -> V_8 == V_66 ) {
F_2 ( & V_2 -> V_10 -> V_11 ,
L_10
L_11 ,
V_12 ) ;
V_58 = V_65 ;
}
F_2 ( & V_2 -> V_10 -> V_11 ,
L_12 ,
V_12 ,
V_46 ) ;
return V_58 ;
V_61:
F_3 ( & V_2 -> V_33 , V_9 ) ;
F_14 ( V_2 , F_15 ( V_30 ) ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
return V_58 ;
}
static void F_30 ( struct V_45 * V_53 ,
enum V_67 V_68 )
{
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
V_53 -> V_69 = V_68 ;
}
static void F_31 ( struct V_45 * V_53 ,
enum V_67 V_68 ,
struct V_44 * V_70 )
{
F_30 ( V_53 , V_68 ) ;
V_53 -> V_71 = V_70 -> V_71 ;
}
static int F_32 (
struct V_1 * V_1 ,
struct V_23 * V_72 ,
T_3 * V_73 )
{
struct V_45 V_53 ;
int V_58 = V_59 ;
F_2 ( & V_1 -> V_10 -> V_11 ,
L_13 ,
V_12 , V_1 , V_72 ) ;
F_30 ( & V_53 , V_74 ) ;
#define F_33 2000
V_58 = F_22 ( V_1 , V_72 , & V_53 , F_33 ) ;
if ( V_58 == V_65 )
F_2 ( & V_1 -> V_10 -> V_11 ,
L_14 ,
V_12 , V_72 ) ;
else
F_2 ( & V_1 -> V_10 -> V_11 ,
L_15 ,
V_12 , V_72 , V_58 ) ;
return V_58 ;
}
int F_34 ( struct V_47 * V_11 , T_3 * V_73 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_23 * V_24 ;
unsigned long V_9 ;
int V_58 = V_65 ;
F_3 ( & V_2 -> V_33 , V_9 ) ;
V_24 = F_35 ( V_11 -> V_75 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
F_2 ( & V_2 -> V_10 -> V_11 ,
L_16 ,
V_12 , V_11 , V_2 , V_24 ) ;
if ( ! V_24 ) {
F_2 ( & V_2 -> V_10 -> V_11 , L_17 , V_12 ) ;
V_58 = V_59 ;
goto V_76;
}
if ( F_28 ( V_2 , V_24 , NULL )
!= V_42 ) {
V_58 = V_59 ;
goto V_76;
}
if ( ! F_6 ( V_43 , & V_24 -> V_9 ) ) {
if ( F_36 ( V_11 ) )
F_37 ( V_11 ) ;
else
V_58 = F_32 ( V_2 , V_24 , V_73 ) ;
}
V_76:
F_16 ( V_24 ) ;
return V_58 ;
}
int F_38 ( struct V_77 * V_78 )
{
return V_59 ;
}
int F_39 ( struct V_79 * V_80 )
{
return V_59 ;
}
int F_40 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_9 ( V_4 -> V_11 ) ;
F_23 ( V_81 ) ;
struct V_44 * V_70 = NULL ;
struct V_23 * V_24 = NULL ;
struct V_45 V_53 ;
int V_58 = V_59 ;
unsigned long V_9 ;
int V_82 = 0 ;
F_3 ( & V_2 -> V_33 , V_9 ) ;
F_41 ( & V_4 -> V_13 ) ;
V_70 = V_4 -> V_21 ;
if ( ! ( V_4 -> V_17 & V_18 ) &&
( V_4 -> V_17 & V_19 ) &&
V_70 ) {
V_24 = F_35 ( V_4 -> V_11 -> V_75 ) ;
V_82 = F_6 ( V_83 ,
& V_70 -> V_9 ) ;
}
F_42 ( & V_4 -> V_13 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
F_20 ( & V_2 -> V_10 -> V_11 ,
L_18 ,
V_12 , V_24 ,
( F_36 ( V_4 -> V_11 ) ? L_19
: ( ( F_43 ( V_4 -> V_11 ) )
? L_20
: L_21 ) ) ,
( ( V_24 ) ? ( ( F_6 ( V_43 , & V_24 -> V_9 ) )
? L_22
: L_23 )
: L_24 ) ,
V_4 , V_70 ) ;
if ( ! V_24 || ! V_70 ) {
F_3 ( & V_4 -> V_13 , V_9 ) ;
V_4 -> V_17 |= V_18 ;
V_4 -> V_17 &= ~ ( V_19 |
V_20 ) ;
F_4 ( & V_4 -> V_13 , V_9 ) ;
V_58 = V_65 ;
F_20 ( & V_2 -> V_10 -> V_11 ,
L_25 ,
V_12 , V_4 ) ;
goto V_76;
}
if ( F_28 ( V_2 , V_24 , V_70 )
!= V_42 ) {
F_20 ( & V_2 -> V_10 -> V_11 ,
L_26
L_27 ,
V_12 , V_24 , V_70 , V_4 ) ;
V_58 = V_59 ;
goto V_76;
}
F_3 ( & V_2 -> V_33 , V_9 ) ;
if ( V_4 -> V_84 == V_85 ||
F_44 ( V_4 -> V_84 ) ||
V_82 ||
F_6 ( V_43 , & V_24 -> V_9 ) ) {
F_4 ( & V_2 -> V_33 , V_9 ) ;
F_25 ( V_2 , V_24 ) ;
F_20 ( & V_2 -> V_10 -> V_11 ,
L_28
L_29
L_30 ,
V_12 ,
( ( V_4 -> V_84 == V_85 )
? L_20
: ( F_44 ( V_4 -> V_84 )
? L_31
: L_32 )
) ,
F_6 ( V_83 ,
& V_70 -> V_9 ) ,
F_6 ( V_43 , & V_24 -> V_9 ) ) ;
F_3 ( & V_4 -> V_13 , V_9 ) ;
V_4 -> V_17 &= ~ ( V_19 |
V_20 ) ;
V_4 -> V_17 |= V_18 ;
F_4 ( & V_4 -> V_13 , V_9 ) ;
V_58 = V_65 ;
} else {
F_31 ( & V_53 , V_86 ,
V_70 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
#define F_45 500
V_58 = F_22 ( V_2 , V_24 , & V_53 ,
F_45 ) ;
}
V_76:
F_20 ( & V_2 -> V_10 -> V_11 ,
L_33 ,
V_12 , V_24 , V_4 , V_70 ) ;
F_16 ( V_24 ) ;
return V_58 ;
}
int F_46 (
struct V_47 * V_87 ,
T_3 * V_73 )
{
return V_59 ;
}
int F_47 (
struct V_47 * V_87 ,
T_3 * V_73 )
{
return V_59 ;
}
int F_48 (
struct V_47 * V_87 ,
T_3 * V_73 )
{
return V_59 ;
}
int F_49 (
struct V_3 * V_4 )
{
if ( V_4 -> V_17 & V_88 )
return V_59 ;
else
return V_89 ;
}
void
F_50 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
enum V_56 V_90 )
{
struct V_45 * V_53 = F_51 ( V_46 ) ;
struct V_55 * V_91 = NULL ;
F_2 ( & V_2 -> V_10 -> V_11 ,
L_34 ,
V_12 , V_46 , V_90 ) ;
F_52 ( V_83 , & V_46 -> V_9 ) ;
if ( V_53 ) {
V_53 -> V_8 = V_90 ;
if ( V_53 -> V_51 == V_52 ) {
memcpy ( & V_53 -> V_15 . V_92 ,
& V_46 -> V_93 . V_94 ,
V_95 ) ;
} else if ( V_53 -> V_51 == V_96 ) {
memcpy ( & V_53 -> V_15 . V_97 ,
& V_46 -> V_98 . V_94 ,
sizeof( struct V_99 ) ) ;
}
V_91 = V_53 -> V_62 ;
}
F_53 ( V_2 , V_46 -> V_100 , V_46 ) ;
F_52 ( V_101 , & V_46 -> V_9 ) ;
if ( F_54 ( V_102 , & V_46 -> V_9 ) )
F_55 ( & V_2 -> V_103 ) ;
if ( ! F_6 ( V_104 , & V_46 -> V_9 ) )
F_56 ( V_2 , V_46 -> V_71 ) ;
if ( V_91 )
V_62 ( V_91 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_47 * V_11 ,
struct V_23 * V_24 )
{
int V_105 = V_65 , V_106 = - 1 ;
struct V_107 * V_108 = F_58 ( V_11 ) ;
struct V_109 * V_110 = V_11 -> V_78 -> V_111 ;
F_2 ( & V_2 -> V_10 -> V_11 , L_35 , V_12 , V_24 ) ;
if ( F_28 ( V_2 , V_24 , NULL )
!= V_42 ) {
V_105 = V_59 ;
goto V_76;
}
if ( ! F_6 ( V_43 , & V_24 -> V_9 ) ) {
if ( F_59 ( V_108 ) ) {
struct V_112 * V_113 = & V_2 -> V_114 [ V_108 -> V_115 ] ;
V_106 = F_60 ( V_2 , V_110 ,
V_113 ) ;
} else
V_106 = F_61 ( V_108 , ! F_36 ( V_11 ) ) ;
}
F_25 ( V_2 , V_24 ) ;
F_2 ( & V_2 -> V_10 -> V_11 , L_36 ,
V_12 , V_24 , V_106 ) ;
V_76:
F_62 ( V_108 ) ;
return V_105 ;
}
int F_63 ( struct V_47 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_23 * V_24 ;
unsigned long V_9 ;
int V_58 ;
F_3 ( & V_2 -> V_33 , V_9 ) ;
V_24 = F_35 ( V_11 -> V_75 ) ;
F_4 ( & V_2 -> V_33 , V_9 ) ;
if ( ! V_24 ) {
V_58 = - V_116 ;
goto V_76;
}
V_58 = F_57 ( V_2 , V_11 , V_24 ) ;
V_76:
F_16 ( V_24 ) ;
return V_58 ;
}
