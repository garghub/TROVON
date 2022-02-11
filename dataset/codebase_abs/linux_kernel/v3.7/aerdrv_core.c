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
goto V_46;
}
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_42 ( V_2 , V_38 -> V_40 ) ;
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
V_46:
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
! V_2 -> V_41 -> V_36 -> V_47 )
goto V_46;
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_47 ( V_2 ) ;
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
V_46:
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
! V_2 -> V_41 -> V_36 -> V_48 )
goto V_46;
V_36 = V_2 -> V_41 -> V_36 ;
V_34 = V_36 -> V_48 ( V_2 ) ;
V_38 -> V_31 = F_21 ( V_38 -> V_31 , V_34 ) ;
V_46:
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , void * V_29 )
{
const struct V_35 * V_36 ;
F_20 ( & V_2 -> V_2 ) ;
V_2 -> V_39 = V_49 ;
if ( ! V_2 -> V_41 ||
! V_2 -> V_41 -> V_36 ||
! V_2 -> V_41 -> V_36 -> V_50 )
goto V_46;
V_36 = V_2 -> V_41 -> V_36 ;
V_36 -> V_50 ( V_2 ) ;
V_46:
F_22 ( & V_2 -> V_2 ) ;
return 0 ;
}
static T_3 F_26 ( struct V_1 * V_2 ,
enum V_51 V_40 ,
char * V_52 ,
int (* F_27)( struct V_1 * , void * ) )
{
struct V_37 V_38 ;
F_18 ( V_33 , & V_2 -> V_2 , L_5 , V_52 ) ;
V_38 . V_40 = V_40 ;
if ( F_27 == F_19 )
V_38 . V_31 = V_53 ;
else
V_38 . V_31 = V_54 ;
if ( V_2 -> V_44 & V_45 ) {
if ( F_27 == F_19 )
V_2 -> V_39 = V_40 ;
F_17 ( V_2 -> V_32 , F_27 , & V_38 ) ;
if ( F_27 == F_25 ) {
F_7 ( V_2 ) ;
V_2 -> V_39 = V_49 ;
}
} else {
F_17 ( V_2 -> V_19 , F_27 , & V_38 ) ;
}
return V_38 . V_31 ;
}
void F_28 ( struct V_1 * V_2 )
{
T_2 V_55 ;
F_29 ( V_2 , V_56 , & V_55 ) ;
V_55 |= V_57 ;
F_30 ( V_2 , V_56 , V_55 ) ;
F_31 ( 2 ) ;
V_55 &= ~ V_57 ;
F_30 ( V_2 , V_56 , V_55 ) ;
F_31 ( 200 ) ;
}
static T_3 F_32 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
F_18 ( V_33 , & V_2 -> V_2 ,
L_6 ) ;
return V_54 ;
}
static int F_33 ( struct V_58 * V_58 , void * V_29 )
{
struct V_59 * V_60 , * * V_61 ;
V_61 = (struct V_59 * * ) V_29 ;
if ( V_58 -> V_19 == & V_62 && V_58 -> V_41 ) {
V_60 = F_34 ( V_58 -> V_41 ) ;
if ( V_60 -> V_63 == V_64 ) {
* V_61 = V_60 ;
return 1 ;
}
}
return 0 ;
}
static struct V_59 * F_35 ( struct V_1 * V_2 )
{
struct V_59 * V_61 = NULL ;
F_36 ( & V_2 -> V_2 , & V_61 , F_33 ) ;
return V_61 ;
}
static T_3 F_37 ( struct V_1 * V_2 )
{
struct V_1 * V_65 ;
T_3 V_8 ;
struct V_59 * V_41 ;
if ( V_2 -> V_44 & V_45 ) {
V_65 = V_2 ;
} else {
V_65 = V_2 -> V_19 -> V_66 ;
}
V_41 = F_35 ( V_65 ) ;
if ( V_41 && V_41 -> F_37 ) {
V_8 = V_41 -> F_37 ( V_65 ) ;
} else if ( F_38 ( V_65 ) == V_67 ) {
V_8 = F_32 ( V_65 ) ;
} else {
F_18 ( V_33 , & V_2 -> V_2 ,
L_7 ,
F_39 ( V_65 ) ) ;
return V_68 ;
}
if ( V_8 != V_54 ) {
F_18 ( V_33 , & V_2 -> V_2 ,
L_8 ,
F_39 ( V_65 ) ) ;
return V_68 ;
}
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 , int V_24 )
{
T_3 V_8 , V_31 = V_54 ;
enum V_51 V_40 ;
if ( V_24 == V_69 )
V_40 = V_43 ;
else
V_40 = V_49 ;
V_8 = F_26 ( V_2 ,
V_40 ,
L_9 ,
F_19 ) ;
if ( V_24 == V_69 ) {
V_31 = F_37 ( V_2 ) ;
if ( V_31 != V_54 )
goto V_70;
}
if ( V_8 == V_53 )
V_8 = F_26 ( V_2 ,
V_40 ,
L_10 ,
F_23 ) ;
if ( V_8 == V_71 ) {
V_8 = F_26 ( V_2 ,
V_40 ,
L_11 ,
F_24 ) ;
}
if ( V_8 != V_54 )
goto V_70;
F_26 ( V_2 ,
V_40 ,
L_12 ,
F_25 ) ;
F_41 ( & V_2 -> V_2 , L_13 ) ;
return;
V_70:
F_41 ( & V_2 -> V_2 , L_14 ) ;
}
static void F_42 ( struct V_72 * V_73 ,
struct V_1 * V_2 ,
struct V_10 * V_74 )
{
int V_7 ;
if ( V_74 -> V_24 == V_25 ) {
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
F_9 ( V_2 , V_7 + V_26 ,
V_74 -> V_8 ) ;
} else
F_40 ( V_2 , V_74 -> V_24 ) ;
}
void F_43 ( int V_75 , unsigned int V_19 , unsigned int V_21 ,
int V_24 )
{
unsigned long V_76 ;
struct V_77 V_78 = {
. V_19 = V_19 ,
. V_21 = V_21 ,
. V_75 = V_75 ,
. V_24 = V_24 ,
} ;
F_44 ( & V_79 , V_76 ) ;
if ( F_45 ( & V_80 , & V_78 ) )
F_46 ( & V_81 ) ;
else
F_47 ( L_15 ,
V_75 , V_19 , F_48 ( V_21 ) , F_49 ( V_21 ) ) ;
F_50 ( & V_79 , V_76 ) ;
}
static void F_51 ( struct V_82 * V_83 )
{
struct V_77 V_78 ;
struct V_1 * V_84 ;
while ( F_52 ( & V_80 , & V_78 ) ) {
V_84 = F_53 ( V_78 . V_75 , V_78 . V_19 ,
V_78 . V_21 ) ;
if ( ! V_84 ) {
F_47 ( L_16 ,
V_78 . V_75 , V_78 . V_19 ,
F_48 ( V_78 . V_21 ) , F_49 ( V_78 . V_21 ) ) ;
continue;
}
F_40 ( V_84 , V_78 . V_24 ) ;
}
}
static int F_54 ( struct V_1 * V_2 , struct V_10 * V_74 )
{
int V_7 , V_85 ;
V_74 -> V_8 = 0 ;
V_74 -> V_86 = 0 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return 1 ;
if ( V_74 -> V_24 == V_25 ) {
F_8 ( V_2 , V_7 + V_26 ,
& V_74 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_27 ,
& V_74 -> V_15 ) ;
if ( ! ( V_74 -> V_8 & ~ V_74 -> V_15 ) )
return 0 ;
} else if ( V_2 -> V_44 & V_45 ||
V_74 -> V_24 == V_87 ) {
F_8 ( V_2 , V_7 + V_9 ,
& V_74 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_28 ,
& V_74 -> V_15 ) ;
if ( ! ( V_74 -> V_8 & ~ V_74 -> V_15 ) )
return 0 ;
F_8 ( V_2 , V_7 + V_88 , & V_85 ) ;
V_74 -> V_89 = F_55 ( V_85 ) ;
if ( V_74 -> V_8 & V_90 ) {
V_74 -> V_86 = 1 ;
F_8 ( V_2 ,
V_7 + V_91 , & V_74 -> V_92 . V_93 ) ;
F_8 ( V_2 ,
V_7 + V_91 + 4 , & V_74 -> V_92 . V_94 ) ;
F_8 ( V_2 ,
V_7 + V_91 + 8 , & V_74 -> V_92 . V_95 ) ;
F_8 ( V_2 ,
V_7 + V_91 + 12 , & V_74 -> V_92 . V_96 ) ;
}
}
return 1 ;
}
static inline void F_56 ( struct V_72 * V_97 ,
struct V_10 * V_11 )
{
int V_98 ;
for ( V_98 = 0 ; V_98 < V_11 -> V_12 && V_11 -> V_2 [ V_98 ] ; V_98 ++ ) {
if ( F_54 ( V_11 -> V_2 [ V_98 ] , V_11 ) )
F_57 ( V_11 -> V_2 [ V_98 ] , V_11 ) ;
}
for ( V_98 = 0 ; V_98 < V_11 -> V_12 && V_11 -> V_2 [ V_98 ] ; V_98 ++ ) {
if ( F_54 ( V_11 -> V_2 [ V_98 ] , V_11 ) )
F_42 ( V_97 , V_11 -> V_2 [ V_98 ] , V_11 ) ;
}
}
static void F_58 ( struct V_72 * V_97 ,
struct V_99 * V_100 )
{
struct V_10 * V_11 ;
V_11 = F_59 ( sizeof( struct V_10 ) , V_101 ) ;
if ( ! V_11 ) {
F_18 ( V_33 , & V_97 -> V_102 -> V_2 ,
L_17 ) ;
return;
}
if ( V_100 -> V_8 & V_103 ) {
V_11 -> V_18 = F_60 ( V_100 -> V_18 ) ;
V_11 -> V_24 = V_25 ;
if ( V_100 -> V_8 & V_104 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_61 ( V_97 -> V_102 , V_11 ) ;
if ( F_16 ( V_97 -> V_102 , V_11 ) )
F_56 ( V_97 , V_11 ) ;
}
if ( V_100 -> V_8 & V_105 ) {
V_11 -> V_18 = F_62 ( V_100 -> V_18 ) ;
if ( V_100 -> V_8 & V_106 )
V_11 -> V_24 = V_69 ;
else
V_11 -> V_24 = V_87 ;
if ( V_100 -> V_8 & V_107 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_61 ( V_97 -> V_102 , V_11 ) ;
if ( F_16 ( V_97 -> V_102 , V_11 ) )
F_56 ( V_97 , V_11 ) ;
}
F_63 ( V_11 ) ;
}
static int F_64 ( struct V_108 * V_109 , struct V_99 * V_100 )
{
unsigned long V_76 ;
F_44 ( & V_109 -> V_110 , V_76 ) ;
if ( V_109 -> V_111 == V_109 -> V_112 ) {
F_50 ( & V_109 -> V_110 , V_76 ) ;
return 0 ;
}
* V_100 = V_109 -> V_113 [ V_109 -> V_112 ] ;
V_109 -> V_112 ++ ;
if ( V_109 -> V_112 == V_114 )
V_109 -> V_112 = 0 ;
F_50 ( & V_109 -> V_110 , V_76 ) ;
return 1 ;
}
void F_65 ( struct V_82 * V_83 )
{
struct V_108 * V_109 = F_66 ( V_83 , struct V_108 , V_115 ) ;
struct V_72 * V_97 = V_109 -> V_116 ;
struct V_99 V_117 ( V_100 ) ;
F_67 ( & V_109 -> V_118 ) ;
while ( F_64 ( V_109 , & V_100 ) )
F_58 ( V_97 , & V_100 ) ;
F_68 ( & V_109 -> V_118 ) ;
F_69 ( & V_109 -> V_119 ) ;
}
int F_70 ( struct V_72 * V_2 )
{
if ( V_120 ) {
F_18 ( V_33 , & V_2 -> V_58 ,
L_18 ) ;
F_71 ( V_2 -> V_102 , 0 ) ;
}
return 0 ;
}
