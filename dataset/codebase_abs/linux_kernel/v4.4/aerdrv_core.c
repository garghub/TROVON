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
int F_10 ( struct V_1 * V_2 )
{
int V_7 ;
T_1 V_8 ;
int V_10 ;
if ( ! F_11 ( V_2 ) )
return - V_11 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return - V_3 ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 == V_12 ) {
F_8 ( V_2 , V_7 + V_13 , & V_8 ) ;
F_9 ( V_2 , V_7 + V_13 , V_8 ) ;
}
F_8 ( V_2 , V_7 + V_14 , & V_8 ) ;
F_9 ( V_2 , V_7 + V_14 , V_8 ) ;
F_8 ( V_2 , V_7 + V_9 , & V_8 ) ;
F_9 ( V_2 , V_7 + V_9 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_17 < V_18 ) {
V_16 -> V_2 [ V_16 -> V_17 ] = V_2 ;
V_16 -> V_17 ++ ;
return 0 ;
}
return - V_19 ;
}
static bool F_14 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_7 ;
T_1 V_8 , V_20 ;
T_2 V_21 ;
if ( ! V_22 && ( F_15 ( V_16 -> V_23 ) != 0 ) ) {
if ( V_16 -> V_23 == ( ( V_2 -> V_24 -> V_25 << 8 ) | V_2 -> V_26 ) )
return true ;
if ( ! V_16 -> V_27 )
return false ;
}
if ( F_16 ( & V_2 -> V_28 ) == 0 )
return false ;
F_17 ( V_2 , V_5 , & V_21 ) ;
if ( ! ( V_21 & V_6 ) )
return false ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return false ;
if ( V_16 -> V_29 == V_30 ) {
F_8 ( V_2 , V_7 + V_14 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_31 , & V_20 ) ;
} else {
F_8 ( V_2 , V_7 + V_9 , & V_8 ) ;
F_8 ( V_2 , V_7 + V_32 , & V_20 ) ;
}
if ( V_8 & ~ V_20 )
return true ;
return false ;
}
static int F_18 ( struct V_1 * V_2 , void * V_33 )
{
struct V_15 * V_16 = (struct V_15 * ) V_33 ;
if ( F_14 ( V_2 , V_16 ) ) {
if ( F_13 ( V_16 , V_2 ) ) {
return 1 ;
}
if ( ! V_16 -> V_27 )
return 1 ;
}
return 0 ;
}
static bool F_19 ( struct V_1 * V_34 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = V_34 ;
int V_35 ;
V_16 -> V_17 = 0 ;
V_35 = F_18 ( V_2 , V_16 ) ;
if ( V_35 )
return true ;
F_20 ( V_34 -> V_36 , F_18 , V_16 ) ;
if ( ! V_16 -> V_17 ) {
F_21 ( V_37 , & V_34 -> V_2 ,
L_1 ,
V_16 -> V_23 ) ;
return false ;
}
return true ;
}
static int F_22 ( struct V_1 * V_2 , void * V_33 )
{
T_3 V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) V_33 ;
F_23 ( & V_2 -> V_2 ) ;
V_2 -> V_43 = V_42 -> V_44 ;
if ( ! V_2 -> V_45 ||
! V_2 -> V_45 -> V_40 ||
! V_2 -> V_45 -> V_40 -> V_46 ) {
if ( V_42 -> V_44 == V_47 &&
! ( V_2 -> V_48 & V_49 ) ) {
F_21 ( V_37 , & V_2 -> V_2 , L_2 ,
V_2 -> V_45 ?
L_3 : L_4 ) ;
}
if ( ! ( V_2 -> V_48 & V_49 ) )
V_38 = V_50 ;
else
V_38 = V_51 ;
} else {
V_40 = V_2 -> V_45 -> V_40 ;
V_38 = V_40 -> V_46 ( V_2 , V_42 -> V_44 ) ;
}
V_42 -> V_35 = F_24 ( V_42 -> V_35 , V_38 ) ;
F_25 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_33 )
{
T_3 V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) V_33 ;
F_23 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_45 ||
! V_2 -> V_45 -> V_40 ||
! V_2 -> V_45 -> V_40 -> V_52 )
goto V_53;
V_40 = V_2 -> V_45 -> V_40 ;
V_38 = V_40 -> V_52 ( V_2 ) ;
V_42 -> V_35 = F_24 ( V_42 -> V_35 , V_38 ) ;
V_53:
F_25 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , void * V_33 )
{
T_3 V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 ;
V_42 = (struct V_41 * ) V_33 ;
F_23 ( & V_2 -> V_2 ) ;
if ( ! V_2 -> V_45 ||
! V_2 -> V_45 -> V_40 ||
! V_2 -> V_45 -> V_40 -> V_54 )
goto V_53;
V_40 = V_2 -> V_45 -> V_40 ;
V_38 = V_40 -> V_54 ( V_2 ) ;
V_42 -> V_35 = F_24 ( V_42 -> V_35 , V_38 ) ;
V_53:
F_25 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , void * V_33 )
{
const struct V_39 * V_40 ;
F_23 ( & V_2 -> V_2 ) ;
V_2 -> V_43 = V_55 ;
if ( ! V_2 -> V_45 ||
! V_2 -> V_45 -> V_40 ||
! V_2 -> V_45 -> V_40 -> V_56 )
goto V_53;
V_40 = V_2 -> V_45 -> V_40 ;
V_40 -> V_56 ( V_2 ) ;
V_53:
F_25 ( & V_2 -> V_2 ) ;
return 0 ;
}
static T_3 F_29 ( struct V_1 * V_2 ,
enum V_57 V_44 ,
char * V_58 ,
int (* F_30)( struct V_1 * , void * ) )
{
struct V_41 V_42 ;
F_21 ( V_37 , & V_2 -> V_2 , L_5 , V_58 ) ;
V_42 . V_44 = V_44 ;
if ( F_30 == F_22 )
V_42 . V_35 = V_59 ;
else
V_42 . V_35 = V_60 ;
if ( V_2 -> V_48 & V_49 ) {
if ( F_30 == F_22 )
V_2 -> V_43 = V_44 ;
F_20 ( V_2 -> V_36 , F_30 , & V_42 ) ;
if ( F_30 == F_28 ) {
F_7 ( V_2 ) ;
V_2 -> V_43 = V_55 ;
}
} else {
F_20 ( V_2 -> V_24 , F_30 , & V_42 ) ;
}
return V_42 . V_35 ;
}
static T_3 F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
F_21 ( V_37 , & V_2 -> V_2 , L_6 ) ;
return V_60 ;
}
static int F_33 ( struct V_61 * V_61 , void * V_33 )
{
struct V_62 * V_63 , * * V_64 ;
V_64 = (struct V_62 * * ) V_33 ;
if ( V_61 -> V_24 == & V_65 && V_61 -> V_45 ) {
V_63 = F_34 ( V_61 -> V_45 ) ;
if ( V_63 -> V_66 == V_67 ) {
* V_64 = V_63 ;
return 1 ;
}
}
return 0 ;
}
static struct V_62 * F_35 ( struct V_1 * V_2 )
{
struct V_62 * V_64 = NULL ;
F_36 ( & V_2 -> V_2 , & V_64 , F_33 ) ;
return V_64 ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_1 * V_68 ;
T_3 V_8 ;
struct V_62 * V_45 ;
if ( V_2 -> V_48 & V_49 ) {
V_68 = V_2 ;
} else {
V_68 = V_2 -> V_24 -> V_69 ;
}
V_45 = F_35 ( V_68 ) ;
if ( V_45 && V_45 -> F_37 ) {
V_8 = V_45 -> F_37 ( V_68 ) ;
} else if ( V_68 -> V_70 ) {
V_8 = F_31 ( V_68 ) ;
} else {
F_21 ( V_37 , & V_2 -> V_2 ,
L_7 ,
F_38 ( V_68 ) ) ;
return V_71 ;
}
if ( V_8 != V_60 ) {
F_21 ( V_37 , & V_2 -> V_2 ,
L_8 ,
F_38 ( V_68 ) ) ;
return V_71 ;
}
return V_8 ;
}
static void F_39 ( struct V_1 * V_2 , int V_29 )
{
T_3 V_8 , V_35 = V_60 ;
enum V_57 V_44 ;
if ( V_29 == V_72 )
V_44 = V_47 ;
else
V_44 = V_55 ;
V_8 = F_29 ( V_2 ,
V_44 ,
L_9 ,
F_22 ) ;
if ( V_29 == V_72 ) {
V_35 = F_37 ( V_2 ) ;
if ( V_35 != V_60 )
goto V_73;
}
if ( V_8 == V_59 )
V_8 = F_29 ( V_2 ,
V_44 ,
L_10 ,
F_26 ) ;
if ( V_8 == V_74 ) {
V_8 = F_29 ( V_2 ,
V_44 ,
L_11 ,
F_27 ) ;
}
if ( V_8 != V_60 )
goto V_73;
F_29 ( V_2 ,
V_44 ,
L_12 ,
F_28 ) ;
F_40 ( & V_2 -> V_2 , L_13 ) ;
return;
V_73:
F_40 ( & V_2 -> V_2 , L_14 ) ;
}
static void F_41 ( struct V_75 * V_76 ,
struct V_1 * V_2 ,
struct V_15 * V_77 )
{
int V_7 ;
if ( V_77 -> V_29 == V_30 ) {
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
F_9 ( V_2 , V_7 + V_14 ,
V_77 -> V_8 ) ;
} else
F_39 ( V_2 , V_77 -> V_29 ) ;
}
void F_42 ( int V_78 , unsigned int V_24 , unsigned int V_26 ,
int V_29 , struct V_79 * V_80 )
{
unsigned long V_81 ;
struct V_82 V_83 = {
. V_24 = V_24 ,
. V_26 = V_26 ,
. V_78 = V_78 ,
. V_29 = V_29 ,
. V_84 = V_80 ,
} ;
F_43 ( & V_85 , V_81 ) ;
if ( F_44 ( & V_86 , V_83 ) )
F_45 ( & V_87 ) ;
else
F_46 ( L_15 ,
V_78 , V_24 , F_47 ( V_26 ) , F_48 ( V_26 ) ) ;
F_49 ( & V_85 , V_81 ) ;
}
static void F_50 ( struct V_88 * V_89 )
{
struct V_82 V_83 ;
struct V_1 * V_90 ;
while ( F_51 ( & V_86 , & V_83 ) ) {
V_90 = F_52 ( V_83 . V_78 , V_83 . V_24 ,
V_83 . V_26 ) ;
if ( ! V_90 ) {
F_46 ( L_16 ,
V_83 . V_78 , V_83 . V_24 ,
F_47 ( V_83 . V_26 ) , F_48 ( V_83 . V_26 ) ) ;
continue;
}
F_53 ( V_90 , V_83 . V_29 , V_83 . V_84 ) ;
F_39 ( V_90 , V_83 . V_29 ) ;
F_54 ( V_90 ) ;
}
}
static int F_55 ( struct V_1 * V_2 , struct V_15 * V_77 )
{
int V_7 , V_91 ;
V_77 -> V_8 = 0 ;
V_77 -> V_92 = 0 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return 1 ;
if ( V_77 -> V_29 == V_30 ) {
F_8 ( V_2 , V_7 + V_14 ,
& V_77 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_31 ,
& V_77 -> V_20 ) ;
if ( ! ( V_77 -> V_8 & ~ V_77 -> V_20 ) )
return 0 ;
} else if ( V_2 -> V_48 & V_49 ||
V_77 -> V_29 == V_93 ) {
F_8 ( V_2 , V_7 + V_9 ,
& V_77 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_32 ,
& V_77 -> V_20 ) ;
if ( ! ( V_77 -> V_8 & ~ V_77 -> V_20 ) )
return 0 ;
F_8 ( V_2 , V_7 + V_94 , & V_91 ) ;
V_77 -> V_95 = F_56 ( V_91 ) ;
if ( V_77 -> V_8 & V_96 ) {
V_77 -> V_92 = 1 ;
F_8 ( V_2 ,
V_7 + V_97 , & V_77 -> V_98 . V_99 ) ;
F_8 ( V_2 ,
V_7 + V_97 + 4 , & V_77 -> V_98 . V_100 ) ;
F_8 ( V_2 ,
V_7 + V_97 + 8 , & V_77 -> V_98 . V_101 ) ;
F_8 ( V_2 ,
V_7 + V_97 + 12 , & V_77 -> V_98 . V_102 ) ;
}
}
return 1 ;
}
static inline void F_57 ( struct V_75 * V_103 ,
struct V_15 * V_16 )
{
int V_104 ;
for ( V_104 = 0 ; V_104 < V_16 -> V_17 && V_16 -> V_2 [ V_104 ] ; V_104 ++ ) {
if ( F_55 ( V_16 -> V_2 [ V_104 ] , V_16 ) )
F_58 ( V_16 -> V_2 [ V_104 ] , V_16 ) ;
}
for ( V_104 = 0 ; V_104 < V_16 -> V_17 && V_16 -> V_2 [ V_104 ] ; V_104 ++ ) {
if ( F_55 ( V_16 -> V_2 [ V_104 ] , V_16 ) )
F_41 ( V_103 , V_16 -> V_2 [ V_104 ] , V_16 ) ;
}
}
static void F_59 ( struct V_75 * V_103 ,
struct V_105 * V_106 )
{
struct V_15 * V_16 ;
V_16 = F_60 ( sizeof( struct V_15 ) , V_107 ) ;
if ( ! V_16 ) {
F_21 ( V_37 , & V_103 -> V_108 -> V_2 ,
L_17 ) ;
return;
}
if ( V_106 -> V_8 & V_109 ) {
V_16 -> V_23 = F_61 ( V_106 -> V_23 ) ;
V_16 -> V_29 = V_30 ;
if ( V_106 -> V_8 & V_110 )
V_16 -> V_27 = 1 ;
else
V_16 -> V_27 = 0 ;
F_62 ( V_103 -> V_108 , V_16 ) ;
if ( F_19 ( V_103 -> V_108 , V_16 ) )
F_57 ( V_103 , V_16 ) ;
}
if ( V_106 -> V_8 & V_111 ) {
V_16 -> V_23 = F_63 ( V_106 -> V_23 ) ;
if ( V_106 -> V_8 & V_112 )
V_16 -> V_29 = V_72 ;
else
V_16 -> V_29 = V_93 ;
if ( V_106 -> V_8 & V_113 )
V_16 -> V_27 = 1 ;
else
V_16 -> V_27 = 0 ;
F_62 ( V_103 -> V_108 , V_16 ) ;
if ( F_19 ( V_103 -> V_108 , V_16 ) )
F_57 ( V_103 , V_16 ) ;
}
F_64 ( V_16 ) ;
}
static int F_65 ( struct V_114 * V_115 , struct V_105 * V_106 )
{
unsigned long V_81 ;
F_43 ( & V_115 -> V_116 , V_81 ) ;
if ( V_115 -> V_117 == V_115 -> V_118 ) {
F_49 ( & V_115 -> V_116 , V_81 ) ;
return 0 ;
}
* V_106 = V_115 -> V_119 [ V_115 -> V_118 ] ;
V_115 -> V_118 ++ ;
if ( V_115 -> V_118 == V_120 )
V_115 -> V_118 = 0 ;
F_49 ( & V_115 -> V_116 , V_81 ) ;
return 1 ;
}
void F_66 ( struct V_88 * V_89 )
{
struct V_114 * V_115 = F_67 ( V_89 , struct V_114 , V_121 ) ;
struct V_75 * V_103 = V_115 -> V_122 ;
struct V_105 V_123 ( V_106 ) ;
F_68 ( & V_115 -> V_124 ) ;
while ( F_65 ( V_115 , & V_106 ) )
F_59 ( V_103 , & V_106 ) ;
F_69 ( & V_115 -> V_124 ) ;
F_70 ( & V_115 -> V_125 ) ;
}
int F_71 ( struct V_75 * V_2 )
{
if ( V_126 ) {
F_21 ( V_37 , & V_2 -> V_61 ,
L_18 ) ;
F_72 ( V_2 -> V_108 , 0 ) ;
}
return 0 ;
}
