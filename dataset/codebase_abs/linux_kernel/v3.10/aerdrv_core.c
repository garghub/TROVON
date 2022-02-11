int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return - V_3 ;
if ( ! F_3 ( V_2 , V_4 ) )
return - V_3 ;
return F_4 ( V_2 , V_5 , V_6 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return - V_3 ;
return F_6 ( V_2 , V_5 ,
V_6 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return - V_3 ;
F_8 ( V_2 , V_7 + V_9 , & V_8 ) ;
if ( V_8 )
F_9 ( V_2 , V_7 + V_9 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
if ( V_11 -> V_12 < V_13 ) {
V_11 -> V_2 [ V_11 -> V_12 ] = V_2 ;
V_11 -> V_12 ++ ;
return 0 ;
}
return - V_14 ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
int V_7 ;
T_1 V_8 , V_15 ;
T_2 V_16 ;
if ( ! V_17 && ( F_12 ( V_11 -> V_18 ) != 0 ) ) {
if ( V_11 -> V_18 == ( ( V_2 -> V_19 -> V_20 << 8 ) | V_2 -> V_21 ) )
return true ;
if ( ! V_11 -> V_22 )
return false ;
}
if ( F_13 ( & V_2 -> V_23 ) == 0 )
return false ;
F_14 ( V_2 , V_5 , & V_16 ) ;
if ( ! ( V_16 & V_6 ) )
return false ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return false ;
if ( V_11 -> V_24 == V_25 ) {
F_8 ( V_2 , V_7 + V_26 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_27 , & V_15 ) ;
} else {
F_8 ( V_2 , V_7 + V_9 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_28 , & V_15 ) ;
}
if ( V_8 & ~ V_15 )
return true ;
return false ;
}
static int F_15 ( struct V_1 * V_2 , void * V_29 )
{
struct V_10 * V_11 = (struct V_10 * ) V_29 ;
if ( F_11 ( V_2 , V_11 ) ) {
if ( F_10 ( V_11 , V_2 ) ) {
return 1 ;
}
if ( ! V_11 -> V_22 )
return 1 ;
}
return 0 ;
}
static bool F_16 ( struct V_1 * V_30 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = V_30 ;
int V_31 ;
V_11 -> V_12 = 0 ;
V_31 = F_15 ( V_2 , V_11 ) ;
if ( V_31 )
return true ;
F_17 ( V_30 -> V_32 , F_15 , V_11 ) ;
if ( ! V_11 -> V_12 ) {
F_18 ( V_33 , & V_30 -> V_2 ,
L_1 ,
V_11 -> V_18 ) ;
return false ;
}
return true ;
}
static int F_19 ( struct V_1 * V_2 , void * V_29 )
{
T_3 V_34 ;
const struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) V_29 ;
F_20 ( & V_2 -> V_2 ) ;
V_2 -> V_39 = V_38 -> V_40 ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_36 ||
! V_2 -> V_41 -> V_36 -> V_42 ) {
if ( V_38 -> V_40 == V_43 &&
! ( V_2 -> V_44 & V_45 ) ) {
F_18 ( V_33 , & V_2 -> V_2 , L_2 ,
V_2 -> V_41 ?
L_3 : L_4 ) ;
}
if ( ! ( V_2 -> V_44 & V_45 ) )
V_34 = V_46 ;
else
V_34 = V_47 ;
} else {
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_42 ( V_2 , V_38 -> V_40 ) ;
}
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_29 )
{
T_3 V_34 ;
const struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) V_29 ;
F_20 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_36 ||
! V_2 -> V_41 -> V_36 -> V_48 )
goto V_49;
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_48 ( V_2 ) ;
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
V_49:
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , void * V_29 )
{
T_3 V_34 ;
const struct V_35 * V_36 ;
struct V_37 * V_38 ;
V_38 = (struct V_37 * ) V_29 ;
F_20 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_36 ||
! V_2 -> V_41 -> V_36 -> V_50 )
goto V_49;
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_50 ( V_2 ) ;
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
V_49:
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_29 )
{
const struct V_35 * V_36 ;
F_20 ( & V_2 -> V_2 ) ;
V_2 -> V_39 = V_51 ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_36 ||
! V_2 -> V_41 -> V_36 -> V_52 )
goto V_49;
V_36 = V_2 -> V_41 -> V_36 ;
V_36 -> V_52 ( V_2 ) ;
V_49:
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static T_3 F_26 ( struct V_1 * V_2 ,
enum V_53 V_40 ,
char * V_54 ,
int (* F_27)( struct V_1 * , void * ) )
{
struct V_37 V_38 ;
F_18 ( V_33 , & V_2 -> V_2 , L_5 , V_54 ) ;
V_38 . V_40 = V_40 ;
if ( F_27 == F_19 )
V_38 . V_31 = V_55 ;
else
V_38 . V_31 = V_56 ;
if ( V_2 -> V_44 & V_45 ) {
if ( F_27 == F_19 )
V_2 -> V_39 = V_40 ;
F_17 ( V_2 -> V_32 , F_27 , & V_38 ) ;
if ( F_27 == F_25 ) {
F_7 ( V_2 ) ;
V_2 -> V_39 = V_51 ;
}
} else {
F_17 ( V_2 -> V_19 , F_27 , & V_38 ) ;
}
return V_38 . V_31 ;
}
void F_28 ( struct V_1 * V_2 )
{
T_2 V_57 ;
F_29 ( V_2 , V_58 , & V_57 ) ;
V_57 |= V_59 ;
F_30 ( V_2 , V_58 , V_57 ) ;
F_31 ( 2 ) ;
V_57 &= ~ V_59 ;
F_30 ( V_2 , V_58 , V_57 ) ;
F_31 ( 200 ) ;
}
static T_3 F_32 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_18 ( V_33 , & V_2 -> V_2 ,
L_6 ) ;
return V_56 ;
}
static int F_33 ( struct V_60 * V_60 , void * V_29 )
{
struct V_61 * V_62 , * * V_63 ;
V_63 = (struct V_61 * * ) V_29 ;
if ( V_60 -> V_19 == & V_64 && V_60 -> V_41 ) {
V_62 = F_34 ( V_60 -> V_41 ) ;
if ( V_62 -> V_65 == V_66 ) {
* V_63 = V_62 ;
return 1 ;
}
}
return 0 ;
}
static struct V_61 * F_35 ( struct V_1 * V_2 )
{
struct V_61 * V_63 = NULL ;
F_36 ( & V_2 -> V_2 , & V_63 , F_33 ) ;
return V_63 ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_1 * V_67 ;
T_3 V_8 ;
struct V_61 * V_41 ;
if ( V_2 -> V_44 & V_45 ) {
V_67 = V_2 ;
} else {
V_67 = V_2 -> V_19 -> V_68 ;
}
V_41 = F_35 ( V_67 ) ;
if ( V_41 && V_41 -> F_37 ) {
V_8 = V_41 -> F_37 ( V_67 ) ;
} else if ( F_38 ( V_67 ) == V_69 ) {
V_8 = F_32 ( V_67 ) ;
} else {
F_18 ( V_33 , & V_2 -> V_2 ,
L_7 ,
F_39 ( V_67 ) ) ;
return V_70 ;
}
if ( V_8 != V_56 ) {
F_18 ( V_33 , & V_2 -> V_2 ,
L_8 ,
F_39 ( V_67 ) ) ;
return V_70 ;
}
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 , int V_24 )
{
T_3 V_8 , V_31 = V_56 ;
enum V_53 V_40 ;
if ( V_24 == V_71 )
V_40 = V_43 ;
else
V_40 = V_51 ;
V_8 = F_26 ( V_2 ,
V_40 ,
L_9 ,
F_19 ) ;
if ( V_24 == V_71 ) {
V_31 = F_37 ( V_2 ) ;
if ( V_31 != V_56 )
goto V_72;
}
if ( V_8 == V_55 )
V_8 = F_26 ( V_2 ,
V_40 ,
L_10 ,
F_23 ) ;
if ( V_8 == V_73 ) {
V_8 = F_26 ( V_2 ,
V_40 ,
L_11 ,
F_24 ) ;
}
if ( V_8 != V_56 )
goto V_72;
F_26 ( V_2 ,
V_40 ,
L_12 ,
F_25 ) ;
F_41 ( & V_2 -> V_2 , L_13 ) ;
return;
V_72:
F_41 ( & V_2 -> V_2 , L_14 ) ;
}
static void F_42 ( struct V_74 * V_75 ,
struct V_1 * V_2 ,
struct V_10 * V_76 )
{
int V_7 ;
if ( V_76 -> V_24 == V_25 ) {
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
F_9 ( V_2 , V_7 + V_26 ,
V_76 -> V_8 ) ;
} else
F_40 ( V_2 , V_76 -> V_24 ) ;
}
void F_43 ( int V_77 , unsigned int V_19 , unsigned int V_21 ,
int V_24 , struct V_78 * V_79 )
{
unsigned long V_80 ;
struct V_81 V_82 = {
. V_19 = V_19 ,
. V_21 = V_21 ,
. V_77 = V_77 ,
. V_24 = V_24 ,
. V_83 = V_79 ,
} ;
F_44 ( & V_84 , V_80 ) ;
if ( F_45 ( & V_85 , & V_82 ) )
F_46 ( & V_86 ) ;
else
F_47 ( L_15 ,
V_77 , V_19 , F_48 ( V_21 ) , F_49 ( V_21 ) ) ;
F_50 ( & V_84 , V_80 ) ;
}
static void F_51 ( struct V_87 * V_88 )
{
struct V_81 V_82 ;
struct V_1 * V_89 ;
while ( F_52 ( & V_85 , & V_82 ) ) {
V_89 = F_53 ( V_82 . V_77 , V_82 . V_19 ,
V_82 . V_21 ) ;
if ( ! V_89 ) {
F_47 ( L_16 ,
V_82 . V_77 , V_82 . V_19 ,
F_48 ( V_82 . V_21 ) , F_49 ( V_82 . V_21 ) ) ;
continue;
}
F_54 ( V_89 , V_82 . V_24 , V_82 . V_83 ) ;
F_40 ( V_89 , V_82 . V_24 ) ;
F_55 ( V_89 ) ;
}
}
static int F_56 ( struct V_1 * V_2 , struct V_10 * V_76 )
{
int V_7 , V_90 ;
V_76 -> V_8 = 0 ;
V_76 -> V_91 = 0 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return 1 ;
if ( V_76 -> V_24 == V_25 ) {
F_8 ( V_2 , V_7 + V_26 ,
& V_76 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_27 ,
& V_76 -> V_15 ) ;
if ( ! ( V_76 -> V_8 & ~ V_76 -> V_15 ) )
return 0 ;
} else if ( V_2 -> V_44 & V_45 ||
V_76 -> V_24 == V_92 ) {
F_8 ( V_2 , V_7 + V_9 ,
& V_76 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_28 ,
& V_76 -> V_15 ) ;
if ( ! ( V_76 -> V_8 & ~ V_76 -> V_15 ) )
return 0 ;
F_8 ( V_2 , V_7 + V_93 , & V_90 ) ;
V_76 -> V_94 = F_57 ( V_90 ) ;
if ( V_76 -> V_8 & V_95 ) {
V_76 -> V_91 = 1 ;
F_8 ( V_2 ,
V_7 + V_96 , & V_76 -> V_97 . V_98 ) ;
F_8 ( V_2 ,
V_7 + V_96 + 4 , & V_76 -> V_97 . V_99 ) ;
F_8 ( V_2 ,
V_7 + V_96 + 8 , & V_76 -> V_97 . V_100 ) ;
F_8 ( V_2 ,
V_7 + V_96 + 12 , & V_76 -> V_97 . V_101 ) ;
}
}
return 1 ;
}
static inline void F_58 ( struct V_74 * V_102 ,
struct V_10 * V_11 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_11 -> V_12 && V_11 -> V_2 [ V_103 ] ; V_103 ++ ) {
if ( F_56 ( V_11 -> V_2 [ V_103 ] , V_11 ) )
F_59 ( V_11 -> V_2 [ V_103 ] , V_11 ) ;
}
for ( V_103 = 0 ; V_103 < V_11 -> V_12 && V_11 -> V_2 [ V_103 ] ; V_103 ++ ) {
if ( F_56 ( V_11 -> V_2 [ V_103 ] , V_11 ) )
F_42 ( V_102 , V_11 -> V_2 [ V_103 ] , V_11 ) ;
}
}
static void F_60 ( struct V_74 * V_102 ,
struct V_104 * V_105 )
{
struct V_10 * V_11 ;
V_11 = F_61 ( sizeof( struct V_10 ) , V_106 ) ;
if ( ! V_11 ) {
F_18 ( V_33 , & V_102 -> V_107 -> V_2 ,
L_17 ) ;
return;
}
if ( V_105 -> V_8 & V_108 ) {
V_11 -> V_18 = F_62 ( V_105 -> V_18 ) ;
V_11 -> V_24 = V_25 ;
if ( V_105 -> V_8 & V_109 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_63 ( V_102 -> V_107 , V_11 ) ;
if ( F_16 ( V_102 -> V_107 , V_11 ) )
F_58 ( V_102 , V_11 ) ;
}
if ( V_105 -> V_8 & V_110 ) {
V_11 -> V_18 = F_64 ( V_105 -> V_18 ) ;
if ( V_105 -> V_8 & V_111 )
V_11 -> V_24 = V_71 ;
else
V_11 -> V_24 = V_92 ;
if ( V_105 -> V_8 & V_112 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_63 ( V_102 -> V_107 , V_11 ) ;
if ( F_16 ( V_102 -> V_107 , V_11 ) )
F_58 ( V_102 , V_11 ) ;
}
F_65 ( V_11 ) ;
}
static int F_66 ( struct V_113 * V_114 , struct V_104 * V_105 )
{
unsigned long V_80 ;
F_44 ( & V_114 -> V_115 , V_80 ) ;
if ( V_114 -> V_116 == V_114 -> V_117 ) {
F_50 ( & V_114 -> V_115 , V_80 ) ;
return 0 ;
}
* V_105 = V_114 -> V_118 [ V_114 -> V_117 ] ;
V_114 -> V_117 ++ ;
if ( V_114 -> V_117 == V_119 )
V_114 -> V_117 = 0 ;
F_50 ( & V_114 -> V_115 , V_80 ) ;
return 1 ;
}
void F_67 ( struct V_87 * V_88 )
{
struct V_113 * V_114 = F_68 ( V_88 , struct V_113 , V_120 ) ;
struct V_74 * V_102 = V_114 -> V_121 ;
struct V_104 V_122 ( V_105 ) ;
F_69 ( & V_114 -> V_123 ) ;
while ( F_66 ( V_114 , & V_105 ) )
F_60 ( V_102 , & V_105 ) ;
F_70 ( & V_114 -> V_123 ) ;
F_71 ( & V_114 -> V_124 ) ;
}
int F_72 ( struct V_74 * V_2 )
{
if ( V_125 ) {
F_18 ( V_33 , & V_2 -> V_60 ,
L_18 ) ;
F_73 ( V_2 -> V_107 , 0 ) ;
}
return 0 ;
}
