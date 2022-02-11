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
static T_3 F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
F_18 ( V_33 , & V_2 -> V_2 , L_6 ) ;
return V_56 ;
}
static int F_30 ( struct V_57 * V_57 , void * V_29 )
{
struct V_58 * V_59 , * * V_60 ;
V_60 = (struct V_58 * * ) V_29 ;
if ( V_57 -> V_19 == & V_61 && V_57 -> V_41 ) {
V_59 = F_31 ( V_57 -> V_41 ) ;
if ( V_59 -> V_62 == V_63 ) {
* V_60 = V_59 ;
return 1 ;
}
}
return 0 ;
}
static struct V_58 * F_32 ( struct V_1 * V_2 )
{
struct V_58 * V_60 = NULL ;
F_33 ( & V_2 -> V_2 , & V_60 , F_30 ) ;
return V_60 ;
}
static T_3 F_34 ( struct V_1 * V_2 )
{
struct V_1 * V_64 ;
T_3 V_8 ;
struct V_58 * V_41 ;
if ( V_2 -> V_44 & V_45 ) {
V_64 = V_2 ;
} else {
V_64 = V_2 -> V_19 -> V_65 ;
}
V_41 = F_32 ( V_64 ) ;
if ( V_41 && V_41 -> F_34 ) {
V_8 = V_41 -> F_34 ( V_64 ) ;
} else if ( V_64 -> V_66 ) {
V_8 = F_28 ( V_64 ) ;
} else {
F_18 ( V_33 , & V_2 -> V_2 ,
L_7 ,
F_35 ( V_64 ) ) ;
return V_67 ;
}
if ( V_8 != V_56 ) {
F_18 ( V_33 , & V_2 -> V_2 ,
L_8 ,
F_35 ( V_64 ) ) ;
return V_67 ;
}
return V_8 ;
}
static void F_36 ( struct V_1 * V_2 , int V_24 )
{
T_3 V_8 , V_31 = V_56 ;
enum V_53 V_40 ;
if ( V_24 == V_68 )
V_40 = V_43 ;
else
V_40 = V_51 ;
V_8 = F_26 ( V_2 ,
V_40 ,
L_9 ,
F_19 ) ;
if ( V_24 == V_68 ) {
V_31 = F_34 ( V_2 ) ;
if ( V_31 != V_56 )
goto V_69;
}
if ( V_8 == V_55 )
V_8 = F_26 ( V_2 ,
V_40 ,
L_10 ,
F_23 ) ;
if ( V_8 == V_70 ) {
V_8 = F_26 ( V_2 ,
V_40 ,
L_11 ,
F_24 ) ;
}
if ( V_8 != V_56 )
goto V_69;
F_26 ( V_2 ,
V_40 ,
L_12 ,
F_25 ) ;
F_37 ( & V_2 -> V_2 , L_13 ) ;
return;
V_69:
F_37 ( & V_2 -> V_2 , L_14 ) ;
}
static void F_38 ( struct V_71 * V_72 ,
struct V_1 * V_2 ,
struct V_10 * V_73 )
{
int V_7 ;
if ( V_73 -> V_24 == V_25 ) {
V_7 = F_3 ( V_2 , V_4 ) ;
if ( V_7 )
F_9 ( V_2 , V_7 + V_26 ,
V_73 -> V_8 ) ;
} else
F_36 ( V_2 , V_73 -> V_24 ) ;
}
void F_39 ( int V_74 , unsigned int V_19 , unsigned int V_21 ,
int V_24 , struct V_75 * V_76 )
{
unsigned long V_77 ;
struct V_78 V_79 = {
. V_19 = V_19 ,
. V_21 = V_21 ,
. V_74 = V_74 ,
. V_24 = V_24 ,
. V_80 = V_76 ,
} ;
F_40 ( & V_81 , V_77 ) ;
if ( F_41 ( & V_82 , V_79 ) )
F_42 ( & V_83 ) ;
else
F_43 ( L_15 ,
V_74 , V_19 , F_44 ( V_21 ) , F_45 ( V_21 ) ) ;
F_46 ( & V_81 , V_77 ) ;
}
static void F_47 ( struct V_84 * V_85 )
{
struct V_78 V_79 ;
struct V_1 * V_86 ;
while ( F_48 ( & V_82 , & V_79 ) ) {
V_86 = F_49 ( V_79 . V_74 , V_79 . V_19 ,
V_79 . V_21 ) ;
if ( ! V_86 ) {
F_43 ( L_16 ,
V_79 . V_74 , V_79 . V_19 ,
F_44 ( V_79 . V_21 ) , F_45 ( V_79 . V_21 ) ) ;
continue;
}
F_50 ( V_86 , V_79 . V_24 , V_79 . V_80 ) ;
F_36 ( V_86 , V_79 . V_24 ) ;
F_51 ( V_86 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_10 * V_73 )
{
int V_7 , V_87 ;
V_73 -> V_8 = 0 ;
V_73 -> V_88 = 0 ;
V_7 = F_3 ( V_2 , V_4 ) ;
if ( ! V_7 )
return 1 ;
if ( V_73 -> V_24 == V_25 ) {
F_8 ( V_2 , V_7 + V_26 ,
& V_73 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_27 ,
& V_73 -> V_15 ) ;
if ( ! ( V_73 -> V_8 & ~ V_73 -> V_15 ) )
return 0 ;
} else if ( V_2 -> V_44 & V_45 ||
V_73 -> V_24 == V_89 ) {
F_8 ( V_2 , V_7 + V_9 ,
& V_73 -> V_8 ) ;
F_8 ( V_2 , V_7 + V_28 ,
& V_73 -> V_15 ) ;
if ( ! ( V_73 -> V_8 & ~ V_73 -> V_15 ) )
return 0 ;
F_8 ( V_2 , V_7 + V_90 , & V_87 ) ;
V_73 -> V_91 = F_53 ( V_87 ) ;
if ( V_73 -> V_8 & V_92 ) {
V_73 -> V_88 = 1 ;
F_8 ( V_2 ,
V_7 + V_93 , & V_73 -> V_94 . V_95 ) ;
F_8 ( V_2 ,
V_7 + V_93 + 4 , & V_73 -> V_94 . V_96 ) ;
F_8 ( V_2 ,
V_7 + V_93 + 8 , & V_73 -> V_94 . V_97 ) ;
F_8 ( V_2 ,
V_7 + V_93 + 12 , & V_73 -> V_94 . V_98 ) ;
}
}
return 1 ;
}
static inline void F_54 ( struct V_71 * V_99 ,
struct V_10 * V_11 )
{
int V_100 ;
for ( V_100 = 0 ; V_100 < V_11 -> V_12 && V_11 -> V_2 [ V_100 ] ; V_100 ++ ) {
if ( F_52 ( V_11 -> V_2 [ V_100 ] , V_11 ) )
F_55 ( V_11 -> V_2 [ V_100 ] , V_11 ) ;
}
for ( V_100 = 0 ; V_100 < V_11 -> V_12 && V_11 -> V_2 [ V_100 ] ; V_100 ++ ) {
if ( F_52 ( V_11 -> V_2 [ V_100 ] , V_11 ) )
F_38 ( V_99 , V_11 -> V_2 [ V_100 ] , V_11 ) ;
}
}
static void F_56 ( struct V_71 * V_99 ,
struct V_101 * V_102 )
{
struct V_10 * V_11 ;
V_11 = F_57 ( sizeof( struct V_10 ) , V_103 ) ;
if ( ! V_11 ) {
F_18 ( V_33 , & V_99 -> V_104 -> V_2 ,
L_17 ) ;
return;
}
if ( V_102 -> V_8 & V_105 ) {
V_11 -> V_18 = F_58 ( V_102 -> V_18 ) ;
V_11 -> V_24 = V_25 ;
if ( V_102 -> V_8 & V_106 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_59 ( V_99 -> V_104 , V_11 ) ;
if ( F_16 ( V_99 -> V_104 , V_11 ) )
F_54 ( V_99 , V_11 ) ;
}
if ( V_102 -> V_8 & V_107 ) {
V_11 -> V_18 = F_60 ( V_102 -> V_18 ) ;
if ( V_102 -> V_8 & V_108 )
V_11 -> V_24 = V_68 ;
else
V_11 -> V_24 = V_89 ;
if ( V_102 -> V_8 & V_109 )
V_11 -> V_22 = 1 ;
else
V_11 -> V_22 = 0 ;
F_59 ( V_99 -> V_104 , V_11 ) ;
if ( F_16 ( V_99 -> V_104 , V_11 ) )
F_54 ( V_99 , V_11 ) ;
}
F_61 ( V_11 ) ;
}
static int F_62 ( struct V_110 * V_111 , struct V_101 * V_102 )
{
unsigned long V_77 ;
F_40 ( & V_111 -> V_112 , V_77 ) ;
if ( V_111 -> V_113 == V_111 -> V_114 ) {
F_46 ( & V_111 -> V_112 , V_77 ) ;
return 0 ;
}
* V_102 = V_111 -> V_115 [ V_111 -> V_114 ] ;
V_111 -> V_114 ++ ;
if ( V_111 -> V_114 == V_116 )
V_111 -> V_114 = 0 ;
F_46 ( & V_111 -> V_112 , V_77 ) ;
return 1 ;
}
void F_63 ( struct V_84 * V_85 )
{
struct V_110 * V_111 = F_64 ( V_85 , struct V_110 , V_117 ) ;
struct V_71 * V_99 = V_111 -> V_118 ;
struct V_101 V_119 ( V_102 ) ;
F_65 ( & V_111 -> V_120 ) ;
while ( F_62 ( V_111 , & V_102 ) )
F_56 ( V_99 , & V_102 ) ;
F_66 ( & V_111 -> V_120 ) ;
F_67 ( & V_111 -> V_121 ) ;
}
int F_68 ( struct V_71 * V_2 )
{
if ( V_122 ) {
F_18 ( V_33 , & V_2 -> V_57 ,
L_18 ) ;
F_69 ( V_2 -> V_104 , 0 ) ;
}
return 0 ;
}
