static const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case - V_2 :
return L_1 ;
case - V_3 :
return L_2 ;
case - V_4 :
return L_3 ;
case - V_5 :
return L_4 ;
case - V_6 :
return L_5 ;
case - V_7 :
return L_6 ;
case - V_8 :
case - V_9 :
case - V_10 :
case - V_11 :
return L_7 ;
default:
return L_8 ;
}
}
static void F_2 ( struct V_12 * V_13 )
{
if ( F_3 ( V_14 , & V_13 -> V_15 ) ) {
F_4 ( & V_13 -> V_16 ) ;
F_4 ( & V_13 -> V_17 ) ;
}
}
static void F_5 ( struct V_12 * V_13 )
{
if ( F_3 ( V_18 , & V_13 -> V_15 ) )
F_4 ( & V_13 -> V_19 ) ;
}
static void F_6 ( struct V_20 * V_21 )
{
struct V_22 * V_20 = (struct V_22 * ) V_21 ;
struct V_12 * V_13 = V_20 -> V_20 . V_23 ;
unsigned long V_24 ;
if ( F_7 ( V_20 -> V_20 . V_25 == - V_3 ||
V_20 -> V_20 . V_25 == - V_2 ||
V_20 -> V_20 . V_25 == - V_26 ||
V_20 -> V_20 . V_25 == - V_6 ) ) {
F_5 ( V_13 ) ;
F_8 ( V_13 ) ;
return;
}
if ( F_9 ( V_18 , & V_13 -> V_15 ) ) {
F_10 ( & V_13 -> V_27 , V_24 ) ;
F_11 ( & V_20 -> V_28 , & V_13 -> V_29 ) ;
if ( V_13 -> V_30 > 0 )
F_12 ( & V_13 -> V_31 ) ;
V_13 -> V_32 . V_33 -> V_34 -> V_35 -=
V_20 -> V_20 . V_36 [ 0 ] . V_37 /
V_13 -> V_32 . V_38 ;
F_13 ( & V_13 -> V_27 , V_24 ) ;
}
}
static void F_14 ( struct V_20 * V_20 )
{
struct V_12 * V_13 = V_20 -> V_23 ;
V_20 -> V_39 = F_6 ;
F_6 ( V_20 ) ;
F_15 ( V_40 , & V_13 -> V_15 ) ;
F_4 ( & V_13 -> V_19 ) ;
}
static bool F_16 ( struct V_41 * V_42 , struct V_20 * V_20 ,
unsigned int V_43 )
{
struct V_44 * V_34 ;
unsigned int V_38 , V_45 ;
const T_1 * V_46 ;
V_34 = V_42 -> V_33 -> V_34 ;
V_38 = V_42 -> V_38 ;
V_46 = V_34 -> V_47 + V_42 -> V_48 * V_38 ;
if ( V_42 -> V_48 + V_43 <= V_34 -> V_49 ) {
memcpy ( V_20 -> V_50 , V_46 , V_43 * V_38 ) ;
} else {
V_45 = V_34 -> V_49 - V_42 -> V_48 ;
memcpy ( V_20 -> V_50 , V_46 , V_45 * V_38 ) ;
memcpy ( V_20 -> V_50 + V_45 * V_38 ,
V_34 -> V_47 , ( V_43 - V_45 ) * V_38 ) ;
}
V_42 -> V_48 += V_43 ;
if ( V_42 -> V_48 >= V_34 -> V_49 )
V_42 -> V_48 -= V_34 -> V_49 ;
V_42 -> V_51 += V_43 ;
if ( V_42 -> V_51 >= V_34 -> V_52 ) {
V_42 -> V_51 -= V_34 -> V_52 ;
return true ;
}
return false ;
}
static inline void F_17 ( struct V_12 * V_13 ,
unsigned int * V_53 , unsigned int V_54 )
{
* V_53 += V_54 ;
if ( * V_53 >= V_13 -> V_32 . V_55 )
* V_53 -= V_13 -> V_32 . V_55 ;
}
static void V_31 ( unsigned long V_56 )
{
struct V_12 * V_13 = ( void * ) V_56 ;
unsigned long V_24 ;
unsigned int V_43 ;
struct V_22 * V_20 ;
bool V_57 = false ;
int V_1 ;
if ( F_7 ( ! F_9 ( V_18 , & V_13 -> V_15 ) ) )
return;
F_10 ( & V_13 -> V_27 , V_24 ) ;
while ( V_13 -> V_30 > 0 &&
! F_18 ( & V_13 -> V_29 ) ) {
V_43 = V_13 -> V_58 [ V_13 -> V_59 ] ;
F_17 ( V_13 , & V_13 -> V_59 , 1 ) ;
V_13 -> V_30 -- ;
V_20 = F_19 ( & V_13 -> V_29 ,
struct V_22 , V_28 ) ;
F_20 ( & V_20 -> V_28 ) ;
V_20 -> V_20 . V_36 [ 0 ] . V_37 =
V_43 * V_13 -> V_32 . V_38 ;
if ( F_9 ( V_60 , & V_13 -> V_15 ) )
V_57 |= F_16 ( & V_13 -> V_32 ,
& V_20 -> V_20 ,
V_43 ) ;
else
memset ( V_20 -> V_20 . V_50 , 0 ,
V_20 -> V_20 . V_36 [ 0 ] . V_37 ) ;
V_1 = F_21 ( & V_20 -> V_20 , V_61 ) ;
if ( F_7 ( V_1 < 0 ) ) {
F_13 ( & V_13 -> V_27 , V_24 ) ;
F_5 ( V_13 ) ;
F_8 ( V_13 ) ;
F_22 ( & V_13 -> V_62 -> V_62 , L_9 ,
V_1 , F_1 ( V_1 ) ) ;
return;
}
V_13 -> V_32 . V_33 -> V_34 -> V_35 += V_43 ;
}
F_13 ( & V_13 -> V_27 , V_24 ) ;
if ( V_57 )
F_23 ( V_13 -> V_32 . V_33 ) ;
}
static bool F_24 ( struct V_41 * V_42 , struct V_20 * V_20 ,
unsigned int V_43 )
{
struct V_44 * V_34 ;
unsigned int V_38 , V_45 ;
T_1 * V_63 ;
V_34 = V_42 -> V_33 -> V_34 ;
V_38 = V_42 -> V_38 ;
V_63 = V_34 -> V_47 + V_42 -> V_48 * V_38 ;
if ( V_42 -> V_48 + V_43 <= V_34 -> V_49 ) {
memcpy ( V_63 , V_20 -> V_50 , V_43 * V_38 ) ;
} else {
V_45 = V_34 -> V_49 - V_42 -> V_48 ;
memcpy ( V_63 , V_20 -> V_50 , V_45 * V_38 ) ;
memcpy ( V_34 -> V_47 ,
V_20 -> V_50 + V_45 * V_38 ,
( V_43 - V_45 ) * V_38 ) ;
}
V_42 -> V_48 += V_43 ;
if ( V_42 -> V_48 >= V_34 -> V_49 )
V_42 -> V_48 -= V_34 -> V_49 ;
V_42 -> V_51 += V_43 ;
if ( V_42 -> V_51 >= V_34 -> V_52 ) {
V_42 -> V_51 -= V_34 -> V_52 ;
return true ;
}
return false ;
}
static void F_25 ( struct V_20 * V_20 )
{
struct V_12 * V_13 = V_20 -> V_23 ;
struct V_41 * V_42 = & V_13 -> V_64 ;
unsigned long V_24 ;
unsigned int V_43 , V_65 ;
bool V_57 ;
int V_1 ;
if ( F_7 ( V_20 -> V_25 == - V_3 ||
V_20 -> V_25 == - V_2 ||
V_20 -> V_25 == - V_26 ||
V_20 -> V_25 == - V_6 ) )
goto V_66;
if ( V_20 -> V_25 >= 0 && V_20 -> V_36 [ 0 ] . V_25 >= 0 )
V_43 = V_20 -> V_36 [ 0 ] . V_67 /
V_42 -> V_38 ;
else
V_43 = 0 ;
F_10 ( & V_13 -> V_27 , V_24 ) ;
if ( V_43 > 0 && F_9 ( V_68 , & V_13 -> V_15 ) )
V_57 = F_24 ( V_42 , V_20 , V_43 ) ;
else
V_57 = false ;
if ( F_9 ( V_14 , & V_13 -> V_15 ) ) {
V_1 = F_21 ( V_20 , V_61 ) ;
if ( F_7 ( V_1 < 0 ) ) {
F_13 ( & V_13 -> V_27 , V_24 ) ;
F_22 ( & V_13 -> V_62 -> V_62 , L_9 ,
V_1 , F_1 ( V_1 ) ) ;
goto V_66;
}
V_65 = V_13 -> V_59 ;
F_17 ( V_13 , & V_65 , V_13 -> V_30 ) ;
V_13 -> V_58 [ V_65 ] = V_43 ;
if ( V_13 -> V_30 < V_13 -> V_32 . V_55 ) {
V_13 -> V_30 ++ ;
if ( V_13 -> V_30 ==
V_13 -> V_32 . V_55 )
F_4 ( & V_13 -> V_17 ) ;
} else {
F_17 ( V_13 , & V_13 -> V_59 , 1 ) ;
}
if ( F_9 ( V_18 , & V_13 -> V_15 ) &&
! F_18 ( & V_13 -> V_29 ) )
F_12 ( & V_13 -> V_31 ) ;
}
F_13 ( & V_13 -> V_27 , V_24 ) ;
if ( V_57 )
F_23 ( V_42 -> V_33 ) ;
return;
V_66:
F_5 ( V_13 ) ;
F_2 ( V_13 ) ;
F_8 ( V_13 ) ;
F_26 ( V_13 ) ;
}
static void F_27 ( struct V_20 * V_20 )
{
struct V_12 * V_13 = V_20 -> V_23 ;
V_20 -> V_39 = F_25 ;
F_25 ( V_20 ) ;
F_15 ( V_69 , & V_13 -> V_15 ) ;
F_4 ( & V_13 -> V_16 ) ;
}
static int F_28 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_42 -> V_55 ; ++ V_70 ) {
int V_1 = F_21 ( & V_42 -> V_71 [ V_70 ] -> V_20 , V_72 ) ;
if ( V_1 < 0 ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_9 ,
V_1 , F_1 ( V_1 ) ) ;
return V_1 ;
}
}
return 0 ;
}
static void F_29 ( struct V_41 * V_42 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_42 -> V_55 ; ++ V_70 )
if ( V_42 -> V_71 [ V_70 ] )
F_30 ( & V_42 -> V_71 [ V_70 ] -> V_20 ) ;
}
static int F_31 ( struct V_12 * V_13 , unsigned int V_73 )
{
struct V_74 * V_75 ;
V_75 = V_13 -> V_76 [ V_73 ] -> V_77 ;
if ( V_75 -> V_78 . V_79 != 1 ) {
int V_1 = F_32 ( V_13 -> V_62 ,
V_75 -> V_78 . V_80 , 1 ) ;
if ( V_1 < 0 ) {
F_22 ( & V_13 -> V_62 -> V_62 ,
L_10 ,
V_1 , F_1 ( V_1 ) ) ;
return V_1 ;
}
}
return 0 ;
}
static void F_33 ( struct V_12 * V_13 , unsigned int V_73 )
{
struct V_74 * V_75 ;
if ( ! V_13 -> V_76 [ V_73 ] )
return;
V_75 = V_13 -> V_76 [ V_73 ] -> V_77 ;
if ( V_75 -> V_78 . V_79 != 0 ) {
int V_1 = F_32 ( V_13 -> V_62 ,
V_75 -> V_78 . V_80 , 0 ) ;
if ( V_1 < 0 && ! F_9 ( V_81 , & V_13 -> V_15 ) )
F_34 ( & V_13 -> V_62 -> V_62 ,
L_11 ,
V_1 , F_1 ( V_1 ) ) ;
}
}
static void F_35 ( struct V_12 * V_13 )
{
F_36 ( V_14 , & V_13 -> V_15 ) ;
F_29 ( & V_13 -> V_64 ) ;
F_33 ( V_13 , V_82 ) ;
}
static int F_37 ( struct V_12 * V_13 )
{
int V_1 ;
if ( F_9 ( V_81 , & V_13 -> V_15 ) )
return - V_2 ;
if ( F_9 ( V_14 , & V_13 -> V_15 ) )
return 0 ;
F_29 ( & V_13 -> V_64 ) ;
V_1 = F_31 ( V_13 , V_82 ) ;
if ( V_1 < 0 )
return V_1 ;
F_36 ( V_69 , & V_13 -> V_15 ) ;
V_13 -> V_64 . V_71 [ 0 ] -> V_20 . V_39 = F_27 ;
V_13 -> V_59 = 0 ;
V_13 -> V_30 = 0 ;
F_15 ( V_14 , & V_13 -> V_15 ) ;
V_1 = F_28 ( V_13 , & V_13 -> V_64 ) ;
if ( V_1 < 0 )
F_35 ( V_13 ) ;
return V_1 ;
}
static void F_38 ( struct V_12 * V_13 )
{
F_36 ( V_18 , & V_13 -> V_15 ) ;
F_29 ( & V_13 -> V_32 ) ;
F_39 ( & V_13 -> V_31 ) ;
F_33 ( V_13 , V_83 ) ;
}
static int F_40 ( struct V_12 * V_13 )
{
unsigned int V_70 , V_43 ;
struct V_20 * V_20 ;
int V_1 = 0 ;
if ( F_9 ( V_81 , & V_13 -> V_15 ) )
return - V_2 ;
if ( F_9 ( V_18 , & V_13 -> V_15 ) )
return 0 ;
F_29 ( & V_13 -> V_32 ) ;
F_39 ( & V_13 -> V_31 ) ;
V_1 = F_31 ( V_13 , V_83 ) ;
if ( V_1 < 0 )
return V_1 ;
F_36 ( V_40 , & V_13 -> V_15 ) ;
V_13 -> V_32 . V_71 [ 0 ] -> V_20 . V_39 =
F_14 ;
F_41 ( & V_13 -> V_27 ) ;
F_42 ( & V_13 -> V_29 ) ;
F_43 ( & V_13 -> V_27 ) ;
F_44 ( V_13 -> V_17 ,
V_13 -> V_30 >= V_13 -> V_32 . V_55 ||
! F_9 ( V_14 , & V_13 -> V_15 ) ||
F_9 ( V_81 , & V_13 -> V_15 ) ) ;
if ( F_9 ( V_81 , & V_13 -> V_15 ) ) {
F_38 ( V_13 ) ;
return - V_2 ;
}
if ( ! F_9 ( V_14 , & V_13 -> V_15 ) ) {
F_38 ( V_13 ) ;
return - V_84 ;
}
for ( V_70 = 0 ; V_70 < V_13 -> V_32 . V_55 ; ++ V_70 ) {
F_41 ( & V_13 -> V_27 ) ;
V_43 = V_13 -> V_58 [ V_13 -> V_59 ] ;
F_17 ( V_13 , & V_13 -> V_59 , 1 ) ;
V_13 -> V_30 -- ;
F_43 ( & V_13 -> V_27 ) ;
V_20 = & V_13 -> V_32 . V_71 [ V_70 ] -> V_20 ;
V_20 -> V_36 [ 0 ] . V_37 =
V_43 * V_13 -> V_32 . V_38 ;
memset ( V_20 -> V_50 , 0 ,
V_20 -> V_36 [ 0 ] . V_37 ) ;
}
F_15 ( V_18 , & V_13 -> V_15 ) ;
V_1 = F_28 ( V_13 , & V_13 -> V_32 ) ;
if ( V_1 < 0 )
F_38 ( V_13 ) ;
return V_1 ;
}
static void F_26 ( struct V_12 * V_13 )
{
if ( F_9 ( V_68 , & V_13 -> V_15 ) )
F_45 ( V_13 -> V_64 . V_33 , V_85 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
if ( F_9 ( V_60 , & V_13 -> V_15 ) )
F_45 ( V_13 -> V_32 . V_33 , V_85 ) ;
}
static int F_46 ( struct V_12 * V_13 , struct V_86 * V_33 ,
unsigned int V_87 )
{
int V_1 ;
V_33 -> V_34 -> V_88 . V_89 =
V_90 |
V_91 |
V_92 |
V_93 |
V_94 |
V_95 ;
V_33 -> V_34 -> V_88 . V_96 = V_13 -> V_97 ;
V_33 -> V_34 -> V_88 . V_98 = F_47 ( V_13 -> V_99 ) ;
V_33 -> V_34 -> V_88 . V_100 = V_13 -> V_99 ;
V_33 -> V_34 -> V_88 . V_101 = V_13 -> V_99 ;
V_33 -> V_34 -> V_88 . V_102 = V_87 ;
V_33 -> V_34 -> V_88 . V_103 = V_87 ;
V_33 -> V_34 -> V_88 . V_104 = 45000 * 1024 ;
V_33 -> V_34 -> V_88 . V_105 = 1 ;
V_33 -> V_34 -> V_88 . V_106 = V_107 ;
V_33 -> V_34 -> V_88 . V_108 = 2 ;
V_33 -> V_34 -> V_88 . V_109 = V_107 ;
V_1 = F_48 ( V_33 -> V_34 ,
V_110 ,
1500000 / V_13 -> V_111 ,
V_107 ) ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_49 ( V_33 -> V_34 , 0 , 32 , 24 ) ;
return V_1 ;
}
static int F_50 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
V_13 -> V_64 . V_33 = V_33 ;
V_1 = F_46 ( V_13 , V_33 , V_13 -> V_64 . V_87 ) ;
if ( V_1 < 0 )
return V_1 ;
V_33 -> V_34 -> V_88 . V_113 =
F_51 ( V_13 -> V_99 , V_13 -> V_111 ) ;
V_33 -> V_34 -> V_35 = V_33 -> V_34 -> V_88 . V_113 ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
F_15 ( V_115 , & V_13 -> V_15 ) ;
F_53 ( & V_13 -> V_114 ) ;
return V_1 ;
}
static int F_54 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
V_13 -> V_32 . V_33 = V_33 ;
V_1 = F_46 ( V_13 , V_33 , V_13 -> V_32 . V_87 ) ;
if ( V_1 < 0 )
return V_1 ;
V_33 -> V_34 -> V_88 . V_113 =
F_51 ( V_13 -> V_99 * V_13 -> V_32 . V_55 ,
V_13 -> V_111 ) ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 < 0 )
goto error;
V_1 = F_40 ( V_13 ) ;
if ( V_1 < 0 ) {
if ( ! F_9 ( V_115 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
goto error;
}
F_15 ( V_116 , & V_13 -> V_15 ) ;
error:
F_53 ( & V_13 -> V_114 ) ;
return V_1 ;
}
static int F_55 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
F_52 ( & V_13 -> V_114 ) ;
F_36 ( V_115 , & V_13 -> V_15 ) ;
if ( ! F_9 ( V_116 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
return 0 ;
}
static int F_56 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
F_52 ( & V_13 -> V_114 ) ;
F_38 ( V_13 ) ;
F_36 ( V_116 , & V_13 -> V_15 ) ;
if ( ! F_9 ( V_115 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_33 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_58 ( V_33 ,
F_59 ( V_118 ) ) ;
}
static int F_60 ( struct V_86 * V_33 ,
struct V_117 * V_118 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
V_1 = F_40 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_58 ( V_33 ,
F_59 ( V_118 ) ) ;
}
static int F_61 ( struct V_86 * V_33 )
{
return F_62 ( V_33 ) ;
}
static int F_63 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
if ( V_1 < 0 )
return V_1 ;
F_44 ( V_13 -> V_16 ,
F_9 ( V_69 , & V_13 -> V_15 ) ||
! F_9 ( V_14 , & V_13 -> V_15 ) ) ;
if ( F_9 ( V_81 , & V_13 -> V_15 ) )
return - V_2 ;
if ( ! F_9 ( V_14 , & V_13 -> V_15 ) )
return - V_84 ;
V_13 -> V_64 . V_51 = 0 ;
V_13 -> V_64 . V_48 = 0 ;
return 0 ;
}
static int F_64 ( struct V_86 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
int V_1 ;
F_52 ( & V_13 -> V_114 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
V_1 = F_40 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
if ( V_1 < 0 )
return V_1 ;
F_44 ( V_13 -> V_19 ,
F_9 ( V_40 , & V_13 -> V_15 ) ||
! F_9 ( V_18 , & V_13 -> V_15 ) ) ;
if ( F_9 ( V_81 , & V_13 -> V_15 ) )
return - V_2 ;
if ( ! F_9 ( V_18 , & V_13 -> V_15 ) )
return - V_84 ;
V_33 -> V_34 -> V_35 = 0 ;
V_13 -> V_32 . V_51 = 0 ;
V_13 -> V_32 . V_48 = 0 ;
return 0 ;
}
static int F_65 ( struct V_86 * V_33 , int V_119 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
switch ( V_119 ) {
case V_120 :
if ( ! F_9 ( V_14 , & V_13 -> V_15 ) )
return - V_84 ;
F_15 ( V_68 , & V_13 -> V_15 ) ;
return 0 ;
case V_121 :
F_36 ( V_68 , & V_13 -> V_15 ) ;
return 0 ;
default:
return - V_8 ;
}
}
static int F_66 ( struct V_86 * V_33 , int V_119 )
{
struct V_12 * V_13 = V_33 -> V_112 ;
switch ( V_119 ) {
case V_120 :
if ( ! F_9 ( V_18 , & V_13 -> V_15 ) )
return - V_84 ;
F_15 ( V_60 , & V_13 -> V_15 ) ;
return 0 ;
case V_121 :
F_36 ( V_60 , & V_13 -> V_15 ) ;
return 0 ;
default:
return - V_8 ;
}
}
static inline T_2 F_67 ( struct V_12 * V_13 ,
struct V_41 * V_42 )
{
unsigned long V_24 ;
unsigned int V_122 ;
F_10 ( & V_13 -> V_27 , V_24 ) ;
V_122 = V_42 -> V_48 ;
F_13 ( & V_13 -> V_27 , V_24 ) ;
return V_122 ;
}
static T_2 F_68 ( struct V_86 * V_123 )
{
struct V_12 * V_13 = V_123 -> V_112 ;
return F_67 ( V_13 , & V_13 -> V_64 ) ;
}
static T_2 F_69 ( struct V_86 * V_123 )
{
struct V_12 * V_13 = V_123 -> V_112 ;
return F_67 ( V_13 , & V_13 -> V_32 ) ;
}
static const struct V_124 *
F_70 ( struct V_125 * V_126 )
{
struct V_74 * V_127 ;
T_1 * V_128 ;
int V_129 ;
if ( V_126 -> V_130 != 2 ) {
F_22 ( & V_126 -> V_62 , L_12 ) ;
return NULL ;
}
V_127 = & V_126 -> V_131 [ 0 ] ;
if ( V_127 -> V_78 . V_132 != 0 ) {
F_22 ( & V_126 -> V_62 , L_13 ) ;
return NULL ;
}
V_127 = & V_126 -> V_131 [ 1 ] ;
if ( V_127 -> V_78 . V_132 != 1 ) {
F_22 ( & V_126 -> V_62 , L_13 ) ;
return NULL ;
}
V_128 = V_127 -> V_128 ;
V_129 = V_127 -> V_129 ;
while ( V_129 >= sizeof( struct V_133 ) ) {
struct V_124 * V_78 ;
V_78 = (struct V_124 * ) V_128 ;
if ( V_78 -> V_134 > V_129 ) {
F_22 ( & V_126 -> V_62 , L_14 ) ;
return NULL ;
}
if ( V_78 -> V_134 == F_71 ( 1 ) &&
V_78 -> V_135 == V_136 &&
V_78 -> V_137 == V_138 ) {
if ( V_78 -> V_139 != V_140 ||
V_78 -> V_141 != 1 ) {
F_22 ( & V_126 -> V_62 ,
L_15 ) ;
return NULL ;
}
return V_78 ;
}
V_129 -= V_78 -> V_134 ;
V_128 += V_78 -> V_134 ;
}
F_22 ( & V_126 -> V_62 , L_16 ) ;
return NULL ;
}
static int F_72 ( struct V_12 * V_13 )
{
const struct V_124 * V_142 ;
const struct V_124 * V_143 ;
const struct V_144 * V_145 ;
unsigned int V_146 ;
V_142 = F_70 ( V_13 -> V_76 [ V_82 ] ) ;
V_143 = F_70 ( V_13 -> V_76 [ V_83 ] ) ;
if ( ! V_142 || ! V_143 )
return - V_147 ;
switch ( V_142 -> V_148 ) {
case 3 :
V_13 -> V_97 = V_149 ;
break;
case 4 :
V_13 -> V_97 = V_150 ;
break;
default:
F_22 ( & V_13 -> V_62 -> V_62 , L_17 ) ;
return - V_147 ;
}
if ( V_142 -> V_148 != V_143 -> V_148 ) {
F_22 ( & V_13 -> V_62 -> V_62 ,
L_18 ) ;
return - V_147 ;
}
if ( V_142 -> V_151 != 24 ||
V_143 -> V_151 != 24 ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_19 ) ;
return - V_147 ;
}
V_13 -> V_99 = F_73 ( V_142 -> V_152 [ 0 ] ) ;
V_146 = F_73 ( V_143 -> V_152 [ 0 ] ) ;
if ( V_13 -> V_99 != V_146 ) {
F_22 ( & V_13 -> V_62 -> V_62 ,
L_20 ,
V_146 , V_13 -> V_99 ) ;
return - V_147 ;
}
switch ( V_13 -> V_62 -> V_153 ) {
case V_154 :
V_13 -> V_111 = 1000 ;
break;
case V_155 :
V_13 -> V_111 = 8000 ;
break;
default:
F_22 ( & V_13 -> V_62 -> V_62 , L_21 ) ;
return - V_147 ;
}
V_13 -> V_64 . V_87 = V_142 -> V_156 ;
V_13 -> V_32 . V_87 = V_143 -> V_156 ;
V_13 -> V_64 . V_38 =
V_142 -> V_148 * V_13 -> V_64 . V_87 ;
V_13 -> V_32 . V_38 =
V_143 -> V_148 * V_13 -> V_32 . V_87 ;
V_145 = & V_13 -> V_76 [ V_82 ] -> V_131 [ 1 ] . V_157 [ 0 ] . V_78 ;
if ( ! F_74 ( V_145 ) ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_22 ) ;
return - V_147 ;
}
V_13 -> V_64 . V_158 = F_75 ( V_13 -> V_62 , F_76 ( V_145 ) ) ;
V_13 -> V_64 . V_159 = F_77 ( V_145 -> V_160 ) ;
V_145 = & V_13 -> V_76 [ V_83 ] -> V_131 [ 1 ] . V_157 [ 0 ] . V_78 ;
if ( ! F_78 ( V_145 ) ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_23 ) ;
return - V_147 ;
}
V_13 -> V_32 . V_158 = F_79 ( V_13 -> V_62 , F_76 ( V_145 ) ) ;
V_13 -> V_32 . V_159 = F_77 ( V_145 -> V_160 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
unsigned int V_161 , V_162 , V_163 , V_70 ;
T_3 V_164 ;
V_42 -> V_55 = V_55 ;
V_42 -> V_55 = F_81 ( V_42 -> V_55 ,
( unsigned int ) V_165 ) ;
V_42 -> V_55 = F_82 ( V_42 -> V_55 ,
( unsigned int ) V_166 ) ;
V_161 = V_42 -> V_55 ;
V_163 = V_167 / V_42 -> V_159 ;
for ( V_70 = 0 ; V_70 < F_83 ( V_42 -> V_168 ) ; ++ V_70 ) {
V_162 = F_82 ( V_161 , V_163 ) ;
V_164 = V_162 * V_42 -> V_159 ;
V_42 -> V_168 [ V_70 ] . V_169 =
F_84 ( V_13 -> V_62 , V_164 , V_72 ,
& V_42 -> V_168 [ V_70 ] . V_170 ) ;
if ( ! V_42 -> V_168 [ V_70 ] . V_169 )
return - V_171 ;
V_42 -> V_168 [ V_70 ] . V_164 = V_164 ;
V_161 -= V_162 ;
if ( ! V_161 )
break;
}
if ( V_161 ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_24 ) ;
return - V_147 ;
}
return 0 ;
}
static void F_85 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < F_83 ( V_42 -> V_168 ) ; ++ V_70 )
F_86 ( V_13 -> V_62 ,
V_42 -> V_168 [ V_70 ] . V_164 ,
V_42 -> V_168 [ V_70 ] . V_169 ,
V_42 -> V_168 [ V_70 ] . V_170 ) ;
}
static int F_87 ( struct V_12 * V_13 , struct V_41 * V_42 ,
void (* F_88)( struct V_20 * ) )
{
unsigned V_172 = V_42 -> V_159 ;
struct V_22 * V_20 ;
unsigned int V_173 , V_174 = 0 ;
for ( V_173 = 0 ; V_173 < F_83 ( V_42 -> V_168 ) ; ++ V_173 ) {
unsigned int V_164 = V_42 -> V_168 [ V_173 ] . V_164 ;
T_1 * V_169 = V_42 -> V_168 [ V_173 ] . V_169 ;
T_4 V_170 = V_42 -> V_168 [ V_173 ] . V_170 ;
while ( V_164 >= V_172 ) {
if ( V_174 >= V_42 -> V_55 )
goto V_175;
V_20 = F_89 ( sizeof( * V_20 ) , V_72 ) ;
if ( ! V_20 )
return - V_171 ;
F_90 ( & V_20 -> V_20 ) ;
V_20 -> V_20 . V_62 = V_13 -> V_62 ;
V_20 -> V_20 . V_176 = V_42 -> V_158 ;
V_20 -> V_20 . V_177 = V_178 |
V_179 ;
V_20 -> V_20 . V_50 = V_169 ;
V_20 -> V_20 . V_180 = V_170 ;
V_20 -> V_20 . V_181 = V_172 ;
V_20 -> V_20 . V_182 = 1 ;
V_20 -> V_20 . V_183 = 1 ;
V_20 -> V_20 . V_23 = V_13 ;
V_20 -> V_20 . V_39 = F_88 ;
V_20 -> V_20 . V_36 [ 0 ] . V_184 = 0 ;
V_20 -> V_20 . V_36 [ 0 ] . V_37 = V_172 ;
V_42 -> V_71 [ V_174 ++ ] = V_20 ;
V_164 -= V_172 ;
V_169 += V_172 ;
V_170 += V_172 ;
}
}
if ( V_174 == V_42 -> V_55 )
return 0 ;
V_175:
F_22 ( & V_13 -> V_62 -> V_62 , L_25 ) ;
return - V_147 ;
}
static void F_91 ( struct V_41 * V_42 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < V_42 -> V_55 ; ++ V_70 ) {
F_92 ( V_42 -> V_71 [ V_70 ] ) ;
V_42 -> V_71 [ V_70 ] = NULL ;
}
}
static void F_93 ( struct V_12 * V_13 ,
struct V_125 * V_126 )
{
unsigned int V_70 ;
struct V_125 * V_76 ;
F_52 ( & V_13 -> V_114 ) ;
F_91 ( & V_13 -> V_64 ) ;
F_91 ( & V_13 -> V_32 ) ;
F_53 ( & V_13 -> V_114 ) ;
F_85 ( V_13 , & V_13 -> V_64 ) ;
F_85 ( V_13 , & V_13 -> V_32 ) ;
for ( V_70 = 0 ; V_70 < F_83 ( V_13 -> V_76 ) ; ++ V_70 ) {
F_52 ( & V_13 -> V_114 ) ;
V_76 = V_13 -> V_76 [ V_70 ] ;
V_13 -> V_76 [ V_70 ] = NULL ;
F_53 ( & V_13 -> V_114 ) ;
if ( V_76 ) {
F_94 ( V_76 , NULL ) ;
if ( V_76 != V_126 )
F_95 ( & V_185 ,
V_76 ) ;
}
}
}
static void F_96 ( struct V_186 * V_187 )
{
struct V_12 * V_13 = V_187 -> V_112 ;
F_97 ( & V_13 -> V_114 ) ;
}
static int F_98 ( struct V_125 * V_126 ,
const struct V_188 * V_189 )
{
static const struct V_190 V_191 = {
. V_192 = 0x0001 ,
. V_193 = 0x0001
} ;
static const struct V_194 V_195 = {
. type = V_196 ,
. V_56 = & V_191
} ;
static const int V_197 [ 2 ] [ 3 ] = {
{
[ V_83 ] = 0 ,
[ V_82 ] = 1 ,
[ V_198 ] = 2 ,
} ,
{
[ V_82 ] = 1 ,
[ V_83 ] = 2 ,
[ V_198 ] = 3 ,
} ,
} ;
struct V_186 * V_187 ;
struct V_12 * V_13 ;
unsigned int V_199 , V_70 ;
int V_200 ;
const char * V_201 ;
char V_202 [ 32 ] ;
int V_1 ;
V_200 = V_189 -> V_203 == 0x0044 ;
if ( V_126 -> V_131 -> V_78 . V_80 !=
V_197 [ V_200 ] [ 0 ] )
return - V_2 ;
F_52 ( & V_204 ) ;
for ( V_199 = 0 ; V_199 < V_205 ; ++ V_199 )
if ( V_206 [ V_199 ] && ! ( V_207 & ( 1 << V_199 ) ) )
break;
if ( V_199 >= V_205 ) {
F_53 ( & V_204 ) ;
return - V_3 ;
}
V_1 = F_99 ( V_208 [ V_199 ] , V_209 [ V_199 ] , V_210 ,
sizeof( * V_13 ) , & V_187 ) ;
if ( V_1 < 0 ) {
F_53 ( & V_204 ) ;
return V_1 ;
}
V_187 -> V_211 = F_96 ;
V_13 = V_187 -> V_112 ;
V_13 -> V_62 = F_100 ( V_126 ) ;
V_13 -> V_187 = V_187 ;
V_13 -> V_199 = V_199 ;
F_42 ( & V_13 -> V_212 ) ;
F_101 ( & V_13 -> V_27 ) ;
F_102 ( & V_13 -> V_114 ) ;
F_42 ( & V_13 -> V_29 ) ;
F_103 ( & V_13 -> V_31 ,
V_31 , ( unsigned long ) V_13 ) ;
F_104 ( & V_13 -> V_16 ) ;
F_104 ( & V_13 -> V_17 ) ;
F_104 ( & V_13 -> V_19 ) ;
V_13 -> V_76 [ 0 ] = V_126 ;
for ( V_70 = 1 ; V_70 < F_83 ( V_13 -> V_76 ) ; ++ V_70 ) {
V_13 -> V_76 [ V_70 ] = F_105 ( V_13 -> V_62 ,
V_197 [ V_200 ] [ V_70 ] ) ;
if ( ! V_13 -> V_76 [ V_70 ] ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_26 ,
V_197 [ V_200 ] [ V_70 ] ) ;
V_1 = - V_147 ;
goto V_213;
}
V_1 = F_106 ( & V_185 ,
V_13 -> V_76 [ V_70 ] , V_13 ) ;
if ( V_1 < 0 ) {
V_13 -> V_76 [ V_70 ] = NULL ;
V_1 = - V_214 ;
goto V_213;
}
}
F_107 ( V_187 , & V_126 -> V_62 ) ;
V_1 = F_72 ( V_13 ) ;
if ( V_1 < 0 )
goto V_213;
V_201 = V_189 -> V_203 == 0x0044 ? L_27 : L_28 ;
strcpy ( V_187 -> V_215 , L_28 ) ;
strcpy ( V_187 -> V_216 , V_201 ) ;
F_108 ( V_13 -> V_62 , V_202 , sizeof( V_202 ) ) ;
snprintf ( V_13 -> V_187 -> V_217 , sizeof( V_13 -> V_187 -> V_217 ) ,
L_29 , V_201 ,
V_13 -> V_62 -> V_218 ? V_13 -> V_62 -> V_218 : L_30 , V_13 -> V_99 , V_202 ,
V_13 -> V_62 -> V_153 == V_155 ? L_31 : L_32 ) ;
V_1 = F_80 ( V_13 , & V_13 -> V_64 ) ;
if ( V_1 < 0 )
goto V_213;
V_1 = F_80 ( V_13 , & V_13 -> V_32 ) ;
if ( V_1 < 0 )
goto V_213;
V_1 = F_87 ( V_13 , & V_13 -> V_64 , F_25 ) ;
if ( V_1 < 0 )
goto V_213;
V_1 = F_87 ( V_13 , & V_13 -> V_32 , F_6 ) ;
if ( V_1 < 0 )
goto V_213;
V_1 = F_109 ( V_187 , V_201 , 0 , 1 , 1 , & V_13 -> V_219 ) ;
if ( V_1 < 0 )
goto V_213;
V_13 -> V_219 -> V_112 = V_13 ;
strcpy ( V_13 -> V_219 -> V_201 , V_201 ) ;
F_110 ( V_13 -> V_219 , V_220 , & V_221 ) ;
F_110 ( V_13 -> V_219 , V_222 , & V_223 ) ;
V_1 = F_111 ( V_187 , V_13 -> V_76 [ V_198 ] ,
& V_13 -> V_212 , & V_195 ) ;
if ( V_1 < 0 )
goto V_213;
V_1 = F_112 ( V_187 ) ;
if ( V_1 < 0 )
goto V_213;
F_94 ( V_126 , V_13 ) ;
V_207 |= 1 << V_199 ;
F_53 ( & V_204 ) ;
return 0 ;
V_213:
F_93 ( V_13 , V_126 ) ;
F_113 ( V_187 ) ;
F_53 ( & V_204 ) ;
return V_1 ;
}
static void F_114 ( struct V_125 * V_126 )
{
struct V_12 * V_13 = F_115 ( V_126 ) ;
struct V_224 * V_225 ;
if ( ! V_13 )
return;
F_52 ( & V_204 ) ;
F_15 ( V_81 , & V_13 -> V_15 ) ;
F_4 ( & V_13 -> V_17 ) ;
F_116 ( V_13 -> V_187 ) ;
F_117 (midi, &ua->midi_list)
F_118 ( V_225 ) ;
F_8 ( V_13 ) ;
F_26 ( V_13 ) ;
F_52 ( & V_13 -> V_114 ) ;
F_38 ( V_13 ) ;
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_114 ) ;
F_93 ( V_13 , V_126 ) ;
V_207 &= ~ ( 1 << V_13 -> V_199 ) ;
F_119 ( V_13 -> V_187 ) ;
F_53 ( & V_204 ) ;
}
static int T_5 F_120 ( void )
{
return F_121 ( & V_185 ) ;
}
static void T_6 F_122 ( void )
{
F_123 ( & V_185 ) ;
F_97 ( & V_204 ) ;
}
