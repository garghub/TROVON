int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return - V_3 ;
if ( ! V_2 -> V_4 )
return - V_3 ;
return F_3 ( V_2 , V_5 , V_6 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return - V_3 ;
return F_5 ( V_2 , V_5 ,
V_6 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
V_7 = V_2 -> V_4 ;
if ( ! V_7 )
return - V_3 ;
F_7 ( V_2 , V_7 + V_9 , & V_8 ) ;
if ( V_8 )
F_8 ( V_2 , V_7 + V_9 , V_8 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
int V_10 ;
if ( ! F_10 ( V_2 ) )
return - V_11 ;
V_7 = V_2 -> V_4 ;
if ( ! V_7 )
return - V_3 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 == V_12 ) {
F_7 ( V_2 , V_7 + V_13 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_13 , V_8 ) ;
}
F_7 ( V_2 , V_7 + V_14 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_14 , V_8 ) ;
F_7 ( V_2 , V_7 + V_9 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_9 , V_8 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_4 = F_13 ( V_2 , V_15 ) ;
return F_9 ( V_2 ) ;
}
static int F_14 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
if ( V_17 -> V_18 < V_19 ) {
V_17 -> V_2 [ V_17 -> V_18 ] = V_2 ;
V_17 -> V_18 ++ ;
return 0 ;
}
return - V_20 ;
}
static bool F_15 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_7 ;
T_1 V_8 , V_21 ;
T_2 V_22 ;
if ( ( F_16 ( V_17 -> V_23 ) != 0 ) &&
! ( V_2 -> V_24 -> V_25 & V_26 ) ) {
if ( V_17 -> V_23 == ( ( V_2 -> V_24 -> V_27 << 8 ) | V_2 -> V_28 ) )
return true ;
if ( ! V_17 -> V_29 )
return false ;
}
if ( F_17 ( & V_2 -> V_30 ) == 0 )
return false ;
F_18 ( V_2 , V_5 , & V_22 ) ;
if ( ! ( V_22 & V_6 ) )
return false ;
V_7 = V_2 -> V_4 ;
if ( ! V_7 )
return false ;
if ( V_17 -> V_31 == V_32 ) {
F_7 ( V_2 , V_7 + V_14 , & V_8 ) ;
F_7 ( V_2 , V_7 + V_33 , & V_21 ) ;
} else {
F_7 ( V_2 , V_7 + V_9 , & V_8 ) ;
F_7 ( V_2 , V_7 + V_34 , & V_21 ) ;
}
if ( V_8 & ~ V_21 )
return true ;
return false ;
}
static int F_19 ( struct V_1 * V_2 , void * V_35 )
{
struct V_16 * V_17 = (struct V_16 * ) V_35 ;
if ( F_15 ( V_2 , V_17 ) ) {
if ( F_14 ( V_17 , V_2 ) ) {
return 1 ;
}
if ( ! V_17 -> V_29 )
return 1 ;
}
return 0 ;
}
static bool F_20 ( struct V_1 * V_36 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_36 ;
int V_37 ;
V_17 -> V_18 = 0 ;
V_37 = F_19 ( V_2 , V_17 ) ;
if ( V_37 )
return true ;
F_21 ( V_36 -> V_38 , F_19 , V_17 ) ;
if ( ! V_17 -> V_18 ) {
F_22 ( V_39 , & V_36 -> V_2 ,
L_1 ,
V_17 -> V_23 ) ;
return false ;
}
return true ;
}
static int F_23 ( struct V_1 * V_2 , void * V_35 )
{
T_3 V_40 ;
const struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_44 = (struct V_43 * ) V_35 ;
F_24 ( & V_2 -> V_2 ) ;
V_2 -> V_45 = V_44 -> V_46 ;
if ( ! V_2 -> V_47 ||
! V_2 -> V_47 -> V_42 ||
! V_2 -> V_47 -> V_42 -> V_48 ) {
if ( V_44 -> V_46 == V_49 &&
V_2 -> V_50 != V_51 ) {
F_22 ( V_39 , & V_2 -> V_2 , L_2 ,
V_2 -> V_47 ?
L_3 : L_4 ) ;
}
if ( V_2 -> V_50 != V_51 )
V_40 = V_52 ;
else
V_40 = V_53 ;
} else {
V_42 = V_2 -> V_47 -> V_42 ;
V_40 = V_42 -> V_48 ( V_2 , V_44 -> V_46 ) ;
}
V_44 -> V_37 = F_25 ( V_44 -> V_37 , V_40 ) ;
F_26 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_35 )
{
T_3 V_40 ;
const struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_44 = (struct V_43 * ) V_35 ;
F_24 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_47 ||
! V_2 -> V_47 -> V_42 ||
! V_2 -> V_47 -> V_42 -> V_54 )
goto V_55;
V_42 = V_2 -> V_47 -> V_42 ;
V_40 = V_42 -> V_54 ( V_2 ) ;
V_44 -> V_37 = F_25 ( V_44 -> V_37 , V_40 ) ;
V_55:
F_26 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_35 )
{
T_3 V_40 ;
const struct V_41 * V_42 ;
struct V_43 * V_44 ;
V_44 = (struct V_43 * ) V_35 ;
F_24 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_47 ||
! V_2 -> V_47 -> V_42 ||
! V_2 -> V_47 -> V_42 -> V_56 )
goto V_55;
V_42 = V_2 -> V_47 -> V_42 ;
V_40 = V_42 -> V_56 ( V_2 ) ;
V_44 -> V_37 = F_25 ( V_44 -> V_37 , V_40 ) ;
V_55:
F_26 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , void * V_35 )
{
const struct V_41 * V_42 ;
F_24 ( & V_2 -> V_2 ) ;
V_2 -> V_45 = V_57 ;
if ( ! V_2 -> V_47 ||
! V_2 -> V_47 -> V_42 ||
! V_2 -> V_47 -> V_42 -> V_58 )
goto V_55;
V_42 = V_2 -> V_47 -> V_42 ;
V_42 -> V_58 ( V_2 ) ;
V_55:
F_26 ( & V_2 -> V_2 ) ;
return 0 ;
}
static T_3 F_30 ( struct V_1 * V_2 ,
enum V_59 V_46 ,
char * V_60 ,
int (* F_31)( struct V_1 * , void * ) )
{
struct V_43 V_44 ;
F_22 ( V_39 , & V_2 -> V_2 , L_5 , V_60 ) ;
V_44 . V_46 = V_46 ;
if ( F_31 == F_23 )
V_44 . V_37 = V_61 ;
else
V_44 . V_37 = V_62 ;
if ( V_2 -> V_50 == V_51 ) {
if ( F_31 == F_23 )
V_2 -> V_45 = V_46 ;
F_21 ( V_2 -> V_38 , F_31 , & V_44 ) ;
if ( F_31 == F_29 ) {
F_6 ( V_2 ) ;
V_2 -> V_45 = V_57 ;
}
} else {
F_21 ( V_2 -> V_24 , F_31 , & V_44 ) ;
}
return V_44 . V_37 ;
}
static T_3 F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 ) ;
F_22 ( V_39 , & V_2 -> V_2 , L_6 ) ;
return V_62 ;
}
static int F_34 ( struct V_63 * V_63 , void * V_35 )
{
struct V_64 * V_65 , * * V_66 ;
V_66 = (struct V_64 * * ) V_35 ;
if ( V_63 -> V_24 == & V_67 && V_63 -> V_47 ) {
V_65 = F_35 ( V_63 -> V_47 ) ;
if ( V_65 -> V_68 == V_69 ) {
* V_66 = V_65 ;
return 1 ;
}
}
return 0 ;
}
static struct V_64 * F_36 ( struct V_1 * V_2 )
{
struct V_64 * V_66 = NULL ;
F_37 ( & V_2 -> V_2 , & V_66 , F_34 ) ;
return V_66 ;
}
static T_3 F_38 ( struct V_1 * V_2 )
{
struct V_1 * V_70 ;
T_3 V_8 ;
struct V_64 * V_47 ;
if ( V_2 -> V_50 == V_51 ) {
V_70 = V_2 ;
} else {
V_70 = V_2 -> V_24 -> V_71 ;
}
V_47 = F_36 ( V_70 ) ;
if ( V_47 && V_47 -> F_38 ) {
V_8 = V_47 -> F_38 ( V_70 ) ;
} else if ( V_70 -> V_72 ) {
V_8 = F_32 ( V_70 ) ;
} else {
F_22 ( V_39 , & V_2 -> V_2 ,
L_7 ,
F_39 ( V_70 ) ) ;
return V_73 ;
}
if ( V_8 != V_62 ) {
F_22 ( V_39 , & V_2 -> V_2 ,
L_8 ,
F_39 ( V_70 ) ) ;
return V_73 ;
}
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 , int V_31 )
{
T_3 V_8 , V_37 = V_62 ;
enum V_59 V_46 ;
if ( V_31 == V_74 )
V_46 = V_49 ;
else
V_46 = V_57 ;
V_8 = F_30 ( V_2 ,
V_46 ,
L_9 ,
F_23 ) ;
if ( V_31 == V_74 ) {
V_37 = F_38 ( V_2 ) ;
if ( V_37 != V_62 )
goto V_75;
}
if ( V_8 == V_61 )
V_8 = F_30 ( V_2 ,
V_46 ,
L_10 ,
F_27 ) ;
if ( V_8 == V_76 ) {
V_8 = F_30 ( V_2 ,
V_46 ,
L_11 ,
F_28 ) ;
}
if ( V_8 != V_62 )
goto V_75;
F_30 ( V_2 ,
V_46 ,
L_12 ,
F_29 ) ;
F_41 ( & V_2 -> V_2 , L_13 ) ;
return;
V_75:
F_41 ( & V_2 -> V_2 , L_14 ) ;
}
static void F_42 ( struct V_77 * V_78 ,
struct V_1 * V_2 ,
struct V_16 * V_79 )
{
int V_7 ;
if ( V_79 -> V_31 == V_32 ) {
V_7 = V_2 -> V_4 ;
if ( V_7 )
F_8 ( V_2 , V_7 + V_14 ,
V_79 -> V_8 ) ;
} else
F_40 ( V_2 , V_79 -> V_31 ) ;
}
void F_43 ( int V_80 , unsigned int V_24 , unsigned int V_28 ,
int V_31 , struct V_81 * V_82 )
{
unsigned long V_83 ;
struct V_84 V_85 = {
. V_24 = V_24 ,
. V_28 = V_28 ,
. V_80 = V_80 ,
. V_31 = V_31 ,
. V_86 = V_82 ,
} ;
F_44 ( & V_87 , V_83 ) ;
if ( F_45 ( & V_88 , V_85 ) )
F_46 ( & V_89 ) ;
else
F_47 ( L_15 ,
V_80 , V_24 , F_48 ( V_28 ) , F_49 ( V_28 ) ) ;
F_50 ( & V_87 , V_83 ) ;
}
static void F_51 ( struct V_90 * V_91 )
{
struct V_84 V_85 ;
struct V_1 * V_92 ;
while ( F_52 ( & V_88 , & V_85 ) ) {
V_92 = F_53 ( V_85 . V_80 , V_85 . V_24 ,
V_85 . V_28 ) ;
if ( ! V_92 ) {
F_47 ( L_16 ,
V_85 . V_80 , V_85 . V_24 ,
F_48 ( V_85 . V_28 ) , F_49 ( V_85 . V_28 ) ) ;
continue;
}
F_54 ( V_92 , V_85 . V_31 , V_85 . V_86 ) ;
F_40 ( V_92 , V_85 . V_31 ) ;
F_55 ( V_92 ) ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_16 * V_79 )
{
int V_7 , V_93 ;
V_79 -> V_8 = 0 ;
V_79 -> V_94 = 0 ;
V_7 = V_2 -> V_4 ;
if ( ! V_7 )
return 1 ;
if ( V_79 -> V_31 == V_32 ) {
F_7 ( V_2 , V_7 + V_14 ,
& V_79 -> V_8 ) ;
F_7 ( V_2 , V_7 + V_33 ,
& V_79 -> V_21 ) ;
if ( ! ( V_79 -> V_8 & ~ V_79 -> V_21 ) )
return 0 ;
} else if ( V_2 -> V_50 == V_51 ||
V_79 -> V_31 == V_95 ) {
F_7 ( V_2 , V_7 + V_9 ,
& V_79 -> V_8 ) ;
F_7 ( V_2 , V_7 + V_34 ,
& V_79 -> V_21 ) ;
if ( ! ( V_79 -> V_8 & ~ V_79 -> V_21 ) )
return 0 ;
F_7 ( V_2 , V_7 + V_96 , & V_93 ) ;
V_79 -> V_97 = F_57 ( V_93 ) ;
if ( V_79 -> V_8 & V_98 ) {
V_79 -> V_94 = 1 ;
F_7 ( V_2 ,
V_7 + V_99 , & V_79 -> V_100 . V_101 ) ;
F_7 ( V_2 ,
V_7 + V_99 + 4 , & V_79 -> V_100 . V_102 ) ;
F_7 ( V_2 ,
V_7 + V_99 + 8 , & V_79 -> V_100 . V_103 ) ;
F_7 ( V_2 ,
V_7 + V_99 + 12 , & V_79 -> V_100 . V_104 ) ;
}
}
return 1 ;
}
static inline void F_58 ( struct V_77 * V_105 ,
struct V_16 * V_17 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_17 -> V_18 && V_17 -> V_2 [ V_106 ] ; V_106 ++ ) {
if ( F_56 ( V_17 -> V_2 [ V_106 ] , V_17 ) )
F_59 ( V_17 -> V_2 [ V_106 ] , V_17 ) ;
}
for ( V_106 = 0 ; V_106 < V_17 -> V_18 && V_17 -> V_2 [ V_106 ] ; V_106 ++ ) {
if ( F_56 ( V_17 -> V_2 [ V_106 ] , V_17 ) )
F_42 ( V_105 , V_17 -> V_2 [ V_106 ] , V_17 ) ;
}
}
static void F_60 ( struct V_77 * V_105 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 = F_61 ( V_105 ) ;
struct V_16 * V_17 = & V_110 -> V_17 ;
if ( V_108 -> V_8 & V_111 ) {
V_17 -> V_23 = F_62 ( V_108 -> V_23 ) ;
V_17 -> V_31 = V_32 ;
if ( V_108 -> V_8 & V_112 )
V_17 -> V_29 = 1 ;
else
V_17 -> V_29 = 0 ;
F_63 ( V_105 -> V_113 , V_17 ) ;
if ( F_20 ( V_105 -> V_113 , V_17 ) )
F_58 ( V_105 , V_17 ) ;
}
if ( V_108 -> V_8 & V_114 ) {
V_17 -> V_23 = F_64 ( V_108 -> V_23 ) ;
if ( V_108 -> V_8 & V_115 )
V_17 -> V_31 = V_74 ;
else
V_17 -> V_31 = V_95 ;
if ( V_108 -> V_8 & V_116 )
V_17 -> V_29 = 1 ;
else
V_17 -> V_29 = 0 ;
F_63 ( V_105 -> V_113 , V_17 ) ;
if ( F_20 ( V_105 -> V_113 , V_17 ) )
F_58 ( V_105 , V_17 ) ;
}
}
static int F_65 ( struct V_109 * V_110 , struct V_107 * V_108 )
{
unsigned long V_83 ;
F_44 ( & V_110 -> V_117 , V_83 ) ;
if ( V_110 -> V_118 == V_110 -> V_119 ) {
F_50 ( & V_110 -> V_117 , V_83 ) ;
return 0 ;
}
* V_108 = V_110 -> V_120 [ V_110 -> V_119 ] ;
V_110 -> V_119 ++ ;
if ( V_110 -> V_119 == V_121 )
V_110 -> V_119 = 0 ;
F_50 ( & V_110 -> V_117 , V_83 ) ;
return 1 ;
}
void F_66 ( struct V_90 * V_91 )
{
struct V_109 * V_110 = F_67 ( V_91 , struct V_109 , V_122 ) ;
struct V_77 * V_105 = V_110 -> V_123 ;
struct V_107 V_124 ( V_108 ) ;
F_68 ( & V_110 -> V_125 ) ;
while ( F_65 ( V_110 , & V_108 ) )
F_60 ( V_105 , & V_108 ) ;
F_69 ( & V_110 -> V_125 ) ;
}
