int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
int V_4 ;
if ( F_2 ( V_2 ) )
return - V_5 ;
V_4 = F_3 ( V_2 , V_6 ) ;
if ( ! V_4 )
return - V_5 ;
V_4 = F_4 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_5 ( V_2 , V_4 + V_7 , & V_3 ) ;
V_3 |= ( V_8 |
V_9 |
V_10 |
V_11 ) ;
F_6 ( V_2 , V_4 + V_7 , V_3 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
int V_4 ;
if ( F_2 ( V_2 ) )
return - V_5 ;
V_4 = F_4 ( V_2 ) ;
if ( ! V_4 )
return - V_5 ;
F_5 ( V_2 , V_4 + V_7 , & V_3 ) ;
V_3 &= ~ ( V_8 |
V_9 |
V_10 |
V_11 ) ;
F_6 ( V_2 , V_4 + V_7 , V_3 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_12 ;
V_4 = F_3 ( V_2 , V_6 ) ;
if ( ! V_4 )
return - V_5 ;
F_9 ( V_2 , V_4 + V_13 , & V_12 ) ;
if ( V_12 )
F_10 ( V_2 , V_4 + V_13 , V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
if ( V_15 -> V_16 < V_17 ) {
V_15 -> V_2 [ V_15 -> V_16 ] = V_2 ;
V_15 -> V_16 ++ ;
return 0 ;
}
return - V_18 ;
}
static bool F_12 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
int V_4 ;
T_2 V_12 , V_19 ;
T_1 V_3 ;
if ( ! V_20 && ( F_13 ( V_15 -> V_21 ) != 0 ) ) {
if ( V_15 -> V_21 == ( ( V_2 -> V_22 -> V_23 << 8 ) | V_2 -> V_24 ) )
return true ;
if ( ! V_15 -> V_25 )
return false ;
}
if ( F_14 ( & V_2 -> V_26 ) == 0 )
return false ;
V_4 = F_4 ( V_2 ) ;
if ( ! V_4 )
return false ;
F_5 ( V_2 , V_4 + V_7 , & V_3 ) ;
if ( ! ( V_3 & (
V_8 |
V_9 |
V_10 |
V_11 ) ) )
return false ;
V_4 = F_3 ( V_2 , V_6 ) ;
if ( ! V_4 )
return false ;
if ( V_15 -> V_27 == V_28 ) {
F_9 ( V_2 , V_4 + V_29 , & V_12 ) ;
F_9 ( V_2 , V_4 + V_30 , & V_19 ) ;
} else {
F_9 ( V_2 , V_4 + V_13 , & V_12 ) ;
F_9 ( V_2 , V_4 + V_31 , & V_19 ) ;
}
if ( V_12 & ~ V_19 )
return true ;
return false ;
}
static int F_15 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_15 = (struct V_14 * ) V_32 ;
if ( F_12 ( V_2 , V_15 ) ) {
if ( F_11 ( V_15 , V_2 ) ) {
return 1 ;
}
if ( ! V_15 -> V_25 )
return 1 ;
}
return 0 ;
}
static bool F_16 ( struct V_1 * V_33 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = V_33 ;
int V_34 ;
V_15 -> V_16 = 0 ;
V_34 = F_15 ( V_2 , V_15 ) ;
if ( V_34 )
return true ;
F_17 ( V_33 -> V_35 , F_15 , V_15 ) ;
if ( ! V_15 -> V_16 ) {
F_18 ( V_36 , & V_33 -> V_2 ,
L_1 ,
V_15 -> V_21 ) ;
return false ;
}
return true ;
}
static int F_19 ( struct V_1 * V_2 , void * V_32 )
{
T_3 V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_32 ;
V_2 -> V_42 = V_41 -> V_43 ;
if ( ! V_2 -> V_44 ||
! V_2 -> V_44 -> V_39 ||
! V_2 -> V_44 -> V_39 -> V_45 ) {
if ( V_41 -> V_43 == V_46 &&
! ( V_2 -> V_47 & V_48 ) ) {
F_18 ( V_36 , & V_2 -> V_2 , L_2 ,
V_2 -> V_44 ?
L_3 : L_4 ) ;
}
return 0 ;
}
V_39 = V_2 -> V_44 -> V_39 ;
V_37 = V_39 -> V_45 ( V_2 , V_41 -> V_43 ) ;
V_41 -> V_34 = F_20 ( V_41 -> V_34 , V_37 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , void * V_32 )
{
T_3 V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_32 ;
if ( ! V_2 -> V_44 ||
! V_2 -> V_44 -> V_39 ||
! V_2 -> V_44 -> V_39 -> V_49 )
return 0 ;
V_39 = V_2 -> V_44 -> V_39 ;
V_37 = V_39 -> V_49 ( V_2 ) ;
V_41 -> V_34 = F_20 ( V_41 -> V_34 , V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_32 )
{
T_3 V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_41 = (struct V_40 * ) V_32 ;
if ( ! V_2 -> V_44 ||
! V_2 -> V_44 -> V_39 ||
! V_2 -> V_44 -> V_39 -> V_50 )
return 0 ;
V_39 = V_2 -> V_44 -> V_39 ;
V_37 = V_39 -> V_50 ( V_2 ) ;
V_41 -> V_34 = F_20 ( V_41 -> V_34 , V_37 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_32 )
{
struct V_38 * V_39 ;
V_2 -> V_42 = V_51 ;
if ( ! V_2 -> V_44 ||
! V_2 -> V_44 -> V_39 ||
! V_2 -> V_44 -> V_39 -> V_52 )
return 0 ;
V_39 = V_2 -> V_44 -> V_39 ;
V_39 -> V_52 ( V_2 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_1 * V_2 ,
enum V_53 V_43 ,
char * V_54 ,
int (* F_25)( struct V_1 * , void * ) )
{
struct V_40 V_41 ;
F_18 ( V_36 , & V_2 -> V_2 , L_5 , V_54 ) ;
V_41 . V_43 = V_43 ;
if ( F_25 == F_19 )
V_41 . V_34 = V_55 ;
else
V_41 . V_34 = V_56 ;
if ( V_2 -> V_47 & V_48 ) {
if ( F_25 == F_19 )
V_2 -> V_42 = V_43 ;
F_17 ( V_2 -> V_35 , F_25 , & V_41 ) ;
if ( F_25 == F_23 ) {
F_8 ( V_2 ) ;
V_2 -> V_42 = V_51 ;
}
} else {
F_17 ( V_2 -> V_22 , F_25 , & V_41 ) ;
}
return V_41 . V_34 ;
}
void F_26 ( struct V_1 * V_2 )
{
T_1 V_57 ;
F_5 ( V_2 , V_58 , & V_57 ) ;
V_57 |= V_59 ;
F_6 ( V_2 , V_58 , V_57 ) ;
F_27 ( 2 ) ;
V_57 &= ~ V_59 ;
F_6 ( V_2 , V_58 , V_57 ) ;
F_27 ( 200 ) ;
}
static T_3 F_28 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
F_18 ( V_36 , & V_2 -> V_2 ,
L_6 ) ;
return V_56 ;
}
static int F_29 ( struct V_60 * V_60 , void * V_32 )
{
struct V_61 * V_62 , * * V_63 ;
V_63 = (struct V_61 * * ) V_32 ;
if ( V_60 -> V_22 == & V_64 && V_60 -> V_44 ) {
V_62 = F_30 ( V_60 -> V_44 ) ;
if ( V_62 -> V_65 == V_66 ) {
* V_63 = V_62 ;
return 1 ;
}
}
return 0 ;
}
static struct V_61 * F_31 ( struct V_1 * V_2 )
{
struct V_61 * V_63 = NULL ;
F_32 ( & V_2 -> V_2 , & V_63 , F_29 ) ;
return V_63 ;
}
static T_3 F_33 ( struct V_1 * V_2 )
{
struct V_1 * V_67 ;
T_3 V_12 ;
struct V_61 * V_44 ;
if ( V_2 -> V_47 & V_48 ) {
V_67 = V_2 ;
} else {
V_67 = V_2 -> V_22 -> V_68 ;
}
V_44 = F_31 ( V_67 ) ;
if ( V_44 && V_44 -> F_33 ) {
V_12 = V_44 -> F_33 ( V_67 ) ;
} else if ( V_67 -> V_69 == V_70 ) {
V_12 = F_28 ( V_67 ) ;
} else {
F_18 ( V_36 , & V_2 -> V_2 ,
L_7 ,
F_34 ( V_67 ) ) ;
return V_71 ;
}
if ( V_12 != V_56 ) {
F_18 ( V_36 , & V_2 -> V_2 ,
L_8 ,
F_34 ( V_67 ) ) ;
return V_71 ;
}
return V_12 ;
}
static void F_35 ( struct V_1 * V_2 , int V_27 )
{
T_3 V_12 , V_34 = V_56 ;
enum V_53 V_43 ;
if ( V_27 == V_72 )
V_43 = V_46 ;
else
V_43 = V_51 ;
V_12 = F_24 ( V_2 ,
V_43 ,
L_9 ,
F_19 ) ;
if ( V_27 == V_72 ) {
V_34 = F_33 ( V_2 ) ;
if ( V_34 != V_56 )
goto V_73;
}
if ( V_12 == V_55 )
V_12 = F_24 ( V_2 ,
V_43 ,
L_10 ,
F_21 ) ;
if ( V_12 == V_74 ) {
V_12 = F_24 ( V_2 ,
V_43 ,
L_11 ,
F_22 ) ;
}
if ( V_12 != V_56 )
goto V_73;
F_24 ( V_2 ,
V_43 ,
L_12 ,
F_23 ) ;
F_18 ( V_36 , & V_2 -> V_2 ,
L_13 ) ;
return;
V_73:
F_18 ( V_36 , & V_2 -> V_2 ,
L_14 ) ;
}
static void F_36 ( struct V_75 * V_76 ,
struct V_1 * V_2 ,
struct V_14 * V_77 )
{
int V_4 ;
if ( V_77 -> V_27 == V_28 ) {
V_4 = F_3 ( V_2 , V_6 ) ;
if ( V_4 )
F_10 ( V_2 , V_4 + V_29 ,
V_77 -> V_12 ) ;
} else
F_35 ( V_2 , V_77 -> V_27 ) ;
}
void F_37 ( int V_78 , unsigned int V_22 , unsigned int V_24 ,
int V_27 )
{
unsigned long V_79 ;
struct V_80 V_81 = {
. V_22 = V_22 ,
. V_24 = V_24 ,
. V_78 = V_78 ,
. V_27 = V_27 ,
} ;
F_38 ( & V_82 , V_79 ) ;
if ( F_39 ( & V_83 , & V_81 ) )
F_40 ( & V_84 ) ;
else
F_41 ( L_15 ,
V_78 , V_22 , F_42 ( V_24 ) , F_43 ( V_24 ) ) ;
F_44 ( & V_82 , V_79 ) ;
}
static void F_45 ( struct V_85 * V_86 )
{
struct V_80 V_81 ;
struct V_1 * V_87 ;
while ( F_46 ( & V_83 , & V_81 ) ) {
V_87 = F_47 ( V_81 . V_78 , V_81 . V_22 ,
V_81 . V_24 ) ;
if ( ! V_87 ) {
F_41 ( L_16 ,
V_81 . V_78 , V_81 . V_22 ,
F_42 ( V_81 . V_24 ) , F_43 ( V_81 . V_24 ) ) ;
continue;
}
F_35 ( V_87 , V_81 . V_27 ) ;
}
}
static int F_48 ( struct V_1 * V_2 , struct V_14 * V_77 )
{
int V_4 , V_88 ;
V_77 -> V_12 = 0 ;
V_77 -> V_89 = 0 ;
V_4 = F_3 ( V_2 , V_6 ) ;
if ( ! V_4 )
return 1 ;
if ( V_77 -> V_27 == V_28 ) {
F_9 ( V_2 , V_4 + V_29 ,
& V_77 -> V_12 ) ;
F_9 ( V_2 , V_4 + V_30 ,
& V_77 -> V_19 ) ;
if ( ! ( V_77 -> V_12 & ~ V_77 -> V_19 ) )
return 0 ;
} else if ( V_2 -> V_47 & V_48 ||
V_77 -> V_27 == V_90 ) {
F_9 ( V_2 , V_4 + V_13 ,
& V_77 -> V_12 ) ;
F_9 ( V_2 , V_4 + V_31 ,
& V_77 -> V_19 ) ;
if ( ! ( V_77 -> V_12 & ~ V_77 -> V_19 ) )
return 0 ;
F_9 ( V_2 , V_4 + V_91 , & V_88 ) ;
V_77 -> V_92 = F_49 ( V_88 ) ;
if ( V_77 -> V_12 & V_93 ) {
V_77 -> V_89 = 1 ;
F_9 ( V_2 ,
V_4 + V_94 , & V_77 -> V_95 . V_96 ) ;
F_9 ( V_2 ,
V_4 + V_94 + 4 , & V_77 -> V_95 . V_97 ) ;
F_9 ( V_2 ,
V_4 + V_94 + 8 , & V_77 -> V_95 . V_98 ) ;
F_9 ( V_2 ,
V_4 + V_94 + 12 , & V_77 -> V_95 . V_99 ) ;
}
}
return 1 ;
}
static inline void F_50 ( struct V_75 * V_100 ,
struct V_14 * V_15 )
{
int V_101 ;
for ( V_101 = 0 ; V_101 < V_15 -> V_16 && V_15 -> V_2 [ V_101 ] ; V_101 ++ ) {
if ( F_48 ( V_15 -> V_2 [ V_101 ] , V_15 ) )
F_51 ( V_15 -> V_2 [ V_101 ] , V_15 ) ;
}
for ( V_101 = 0 ; V_101 < V_15 -> V_16 && V_15 -> V_2 [ V_101 ] ; V_101 ++ ) {
if ( F_48 ( V_15 -> V_2 [ V_101 ] , V_15 ) )
F_36 ( V_100 , V_15 -> V_2 [ V_101 ] , V_15 ) ;
}
}
static void F_52 ( struct V_75 * V_100 ,
struct V_102 * V_103 )
{
struct V_14 * V_15 ;
V_15 = F_53 ( sizeof( struct V_14 ) , V_104 ) ;
if ( ! V_15 ) {
F_18 ( V_36 , & V_100 -> V_105 -> V_2 ,
L_17 ) ;
return;
}
if ( V_103 -> V_12 & V_106 ) {
V_15 -> V_21 = F_54 ( V_103 -> V_21 ) ;
V_15 -> V_27 = V_28 ;
if ( V_103 -> V_12 & V_107 )
V_15 -> V_25 = 1 ;
else
V_15 -> V_25 = 0 ;
F_55 ( V_100 -> V_105 , V_15 ) ;
if ( F_16 ( V_100 -> V_105 , V_15 ) )
F_50 ( V_100 , V_15 ) ;
}
if ( V_103 -> V_12 & V_108 ) {
V_15 -> V_21 = F_56 ( V_103 -> V_21 ) ;
if ( V_103 -> V_12 & V_109 )
V_15 -> V_27 = V_72 ;
else
V_15 -> V_27 = V_90 ;
if ( V_103 -> V_12 & V_110 )
V_15 -> V_25 = 1 ;
else
V_15 -> V_25 = 0 ;
F_55 ( V_100 -> V_105 , V_15 ) ;
if ( F_16 ( V_100 -> V_105 , V_15 ) )
F_50 ( V_100 , V_15 ) ;
}
F_57 ( V_15 ) ;
}
static int F_58 ( struct V_111 * V_112 , struct V_102 * V_103 )
{
unsigned long V_79 ;
F_38 ( & V_112 -> V_113 , V_79 ) ;
if ( V_112 -> V_114 == V_112 -> V_115 ) {
F_44 ( & V_112 -> V_113 , V_79 ) ;
return 0 ;
}
* V_103 = V_112 -> V_116 [ V_112 -> V_115 ] ;
V_112 -> V_115 ++ ;
if ( V_112 -> V_115 == V_117 )
V_112 -> V_115 = 0 ;
F_44 ( & V_112 -> V_113 , V_79 ) ;
return 1 ;
}
void F_59 ( struct V_85 * V_86 )
{
struct V_111 * V_112 = F_60 ( V_86 , struct V_111 , V_118 ) ;
struct V_75 * V_100 = V_112 -> V_119 ;
struct V_102 V_120 ( V_103 ) ;
F_61 ( & V_112 -> V_121 ) ;
while ( F_58 ( V_112 , & V_103 ) )
F_52 ( V_100 , & V_103 ) ;
F_62 ( & V_112 -> V_121 ) ;
F_63 ( & V_112 -> V_122 ) ;
}
int F_64 ( struct V_75 * V_2 )
{
if ( V_123 ) {
F_18 ( V_36 , & V_2 -> V_60 ,
L_18 ) ;
F_65 ( V_2 -> V_105 , 0 ) ;
}
return 0 ;
}
