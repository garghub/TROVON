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
F_45 ( V_13 -> V_64 . V_33 ) ;
}
static void F_8 ( struct V_12 * V_13 )
{
if ( F_9 ( V_60 , & V_13 -> V_15 ) )
F_45 ( V_13 -> V_32 . V_33 ) ;
}
static int F_46 ( struct V_12 * V_13 , struct V_85 * V_33 ,
unsigned int V_86 )
{
int V_1 ;
V_33 -> V_34 -> V_87 . V_88 =
V_89 |
V_90 |
V_91 |
V_92 |
V_93 |
V_94 ;
V_33 -> V_34 -> V_87 . V_95 = V_13 -> V_96 ;
V_33 -> V_34 -> V_87 . V_97 = F_47 ( V_13 -> V_98 ) ;
V_33 -> V_34 -> V_87 . V_99 = V_13 -> V_98 ;
V_33 -> V_34 -> V_87 . V_100 = V_13 -> V_98 ;
V_33 -> V_34 -> V_87 . V_101 = V_86 ;
V_33 -> V_34 -> V_87 . V_102 = V_86 ;
V_33 -> V_34 -> V_87 . V_103 = 45000 * 1024 ;
V_33 -> V_34 -> V_87 . V_104 = 1 ;
V_33 -> V_34 -> V_87 . V_105 = V_106 ;
V_33 -> V_34 -> V_87 . V_107 = 2 ;
V_33 -> V_34 -> V_87 . V_108 = V_106 ;
V_1 = F_48 ( V_33 -> V_34 ,
V_109 ,
1500000 / V_13 -> V_110 ,
V_106 ) ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_49 ( V_33 -> V_34 , 0 , 32 , 24 ) ;
return V_1 ;
}
static int F_50 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
V_13 -> V_64 . V_33 = V_33 ;
V_1 = F_46 ( V_13 , V_33 , V_13 -> V_64 . V_86 ) ;
if ( V_1 < 0 )
return V_1 ;
V_33 -> V_34 -> V_87 . V_112 =
F_51 ( V_13 -> V_98 , V_13 -> V_110 ) ;
V_33 -> V_34 -> V_35 = V_33 -> V_34 -> V_87 . V_112 ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
F_15 ( V_114 , & V_13 -> V_15 ) ;
F_53 ( & V_13 -> V_113 ) ;
return V_1 ;
}
static int F_54 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
V_13 -> V_32 . V_33 = V_33 ;
V_1 = F_46 ( V_13 , V_33 , V_13 -> V_32 . V_86 ) ;
if ( V_1 < 0 )
return V_1 ;
V_33 -> V_34 -> V_87 . V_112 =
F_51 ( V_13 -> V_98 * V_13 -> V_32 . V_55 ,
V_13 -> V_110 ) ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 < 0 )
goto error;
V_1 = F_40 ( V_13 ) ;
if ( V_1 < 0 ) {
if ( ! F_9 ( V_114 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
goto error;
}
F_15 ( V_115 , & V_13 -> V_15 ) ;
error:
F_53 ( & V_13 -> V_113 ) ;
return V_1 ;
}
static int F_55 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
F_52 ( & V_13 -> V_113 ) ;
F_36 ( V_114 , & V_13 -> V_15 ) ;
if ( ! F_9 ( V_115 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
return 0 ;
}
static int F_56 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
F_52 ( & V_13 -> V_113 ) ;
F_38 ( V_13 ) ;
F_36 ( V_115 , & V_13 -> V_15 ) ;
if ( ! F_9 ( V_114 , & V_13 -> V_15 ) )
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
return 0 ;
}
static int F_57 ( struct V_85 * V_33 ,
struct V_116 * V_117 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_58 ( V_33 ,
F_59 ( V_117 ) ) ;
}
static int F_60 ( struct V_85 * V_33 ,
struct V_116 * V_117 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
V_1 = F_40 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_58 ( V_33 ,
F_59 ( V_117 ) ) ;
}
static int F_61 ( struct V_85 * V_33 )
{
return F_62 ( V_33 ) ;
}
static int F_63 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
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
static int F_64 ( struct V_85 * V_33 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
int V_1 ;
F_52 ( & V_13 -> V_113 ) ;
V_1 = F_37 ( V_13 ) ;
if ( V_1 >= 0 )
V_1 = F_40 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
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
static int F_65 ( struct V_85 * V_33 , int V_118 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
switch ( V_118 ) {
case V_119 :
if ( ! F_9 ( V_14 , & V_13 -> V_15 ) )
return - V_84 ;
F_15 ( V_68 , & V_13 -> V_15 ) ;
return 0 ;
case V_120 :
F_36 ( V_68 , & V_13 -> V_15 ) ;
return 0 ;
default:
return - V_8 ;
}
}
static int F_66 ( struct V_85 * V_33 , int V_118 )
{
struct V_12 * V_13 = V_33 -> V_111 ;
switch ( V_118 ) {
case V_119 :
if ( ! F_9 ( V_18 , & V_13 -> V_15 ) )
return - V_84 ;
F_15 ( V_60 , & V_13 -> V_15 ) ;
return 0 ;
case V_120 :
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
unsigned int V_121 ;
F_10 ( & V_13 -> V_27 , V_24 ) ;
V_121 = V_42 -> V_48 ;
F_13 ( & V_13 -> V_27 , V_24 ) ;
return V_121 ;
}
static T_2 F_68 ( struct V_85 * V_122 )
{
struct V_12 * V_13 = V_122 -> V_111 ;
return F_67 ( V_13 , & V_13 -> V_64 ) ;
}
static T_2 F_69 ( struct V_85 * V_122 )
{
struct V_12 * V_13 = V_122 -> V_111 ;
return F_67 ( V_13 , & V_13 -> V_32 ) ;
}
static const struct V_123 *
F_70 ( struct V_124 * V_125 )
{
struct V_74 * V_126 ;
T_1 * V_127 ;
int V_128 ;
if ( V_125 -> V_129 != 2 ) {
F_22 ( & V_125 -> V_62 , L_12 ) ;
return NULL ;
}
V_126 = & V_125 -> V_130 [ 0 ] ;
if ( V_126 -> V_78 . V_131 != 0 ) {
F_22 ( & V_125 -> V_62 , L_13 ) ;
return NULL ;
}
V_126 = & V_125 -> V_130 [ 1 ] ;
if ( V_126 -> V_78 . V_131 != 1 ) {
F_22 ( & V_125 -> V_62 , L_13 ) ;
return NULL ;
}
V_127 = V_126 -> V_127 ;
V_128 = V_126 -> V_128 ;
while ( V_128 >= sizeof( struct V_132 ) ) {
struct V_123 * V_78 ;
V_78 = (struct V_123 * ) V_127 ;
if ( V_78 -> V_133 > V_128 ) {
F_22 ( & V_125 -> V_62 , L_14 ) ;
return NULL ;
}
if ( V_78 -> V_133 == F_71 ( 1 ) &&
V_78 -> V_134 == V_135 &&
V_78 -> V_136 == V_137 ) {
if ( V_78 -> V_138 != V_139 ||
V_78 -> V_140 != 1 ) {
F_22 ( & V_125 -> V_62 ,
L_15 ) ;
return NULL ;
}
return V_78 ;
}
V_128 -= V_78 -> V_133 ;
V_127 += V_78 -> V_133 ;
}
F_22 ( & V_125 -> V_62 , L_16 ) ;
return NULL ;
}
static int F_72 ( struct V_12 * V_13 )
{
const struct V_123 * V_141 ;
const struct V_123 * V_142 ;
const struct V_143 * V_144 ;
unsigned int V_145 ;
V_141 = F_70 ( V_13 -> V_76 [ V_82 ] ) ;
V_142 = F_70 ( V_13 -> V_76 [ V_83 ] ) ;
if ( ! V_141 || ! V_142 )
return - V_146 ;
switch ( V_141 -> V_147 ) {
case 3 :
V_13 -> V_96 = V_148 ;
break;
case 4 :
V_13 -> V_96 = V_149 ;
break;
default:
F_22 ( & V_13 -> V_62 -> V_62 , L_17 ) ;
return - V_146 ;
}
if ( V_141 -> V_147 != V_142 -> V_147 ) {
F_22 ( & V_13 -> V_62 -> V_62 ,
L_18 ) ;
return - V_146 ;
}
if ( V_141 -> V_150 != 24 ||
V_142 -> V_150 != 24 ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_19 ) ;
return - V_146 ;
}
V_13 -> V_98 = F_73 ( V_141 -> V_151 [ 0 ] ) ;
V_145 = F_73 ( V_142 -> V_151 [ 0 ] ) ;
if ( V_13 -> V_98 != V_145 ) {
F_22 ( & V_13 -> V_62 -> V_62 ,
L_20 ,
V_145 , V_13 -> V_98 ) ;
return - V_146 ;
}
switch ( V_13 -> V_62 -> V_152 ) {
case V_153 :
V_13 -> V_110 = 1000 ;
break;
case V_154 :
V_13 -> V_110 = 8000 ;
break;
default:
F_22 ( & V_13 -> V_62 -> V_62 , L_21 ) ;
return - V_146 ;
}
V_13 -> V_64 . V_86 = V_141 -> V_155 ;
V_13 -> V_32 . V_86 = V_142 -> V_155 ;
V_13 -> V_64 . V_38 =
V_141 -> V_147 * V_13 -> V_64 . V_86 ;
V_13 -> V_32 . V_38 =
V_142 -> V_147 * V_13 -> V_32 . V_86 ;
V_144 = & V_13 -> V_76 [ V_82 ] -> V_130 [ 1 ] . V_156 [ 0 ] . V_78 ;
if ( ! F_74 ( V_144 ) ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_22 ) ;
return - V_146 ;
}
V_13 -> V_64 . V_157 = F_75 ( V_13 -> V_62 , F_76 ( V_144 ) ) ;
V_13 -> V_64 . V_158 = F_77 ( V_144 -> V_159 ) ;
V_144 = & V_13 -> V_76 [ V_83 ] -> V_130 [ 1 ] . V_156 [ 0 ] . V_78 ;
if ( ! F_78 ( V_144 ) ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_23 ) ;
return - V_146 ;
}
V_13 -> V_32 . V_157 = F_79 ( V_13 -> V_62 , F_76 ( V_144 ) ) ;
V_13 -> V_32 . V_158 = F_77 ( V_144 -> V_159 ) ;
return 0 ;
}
static int F_80 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
unsigned int V_160 , V_161 , V_162 , V_70 ;
T_3 V_163 ;
V_42 -> V_55 = V_55 ;
V_42 -> V_55 = F_81 ( V_42 -> V_55 ,
( unsigned int ) V_164 ) ;
V_42 -> V_55 = F_82 ( V_42 -> V_55 ,
( unsigned int ) V_165 ) ;
V_160 = V_42 -> V_55 ;
V_162 = V_166 / V_42 -> V_158 ;
for ( V_70 = 0 ; V_70 < F_83 ( V_42 -> V_167 ) ; ++ V_70 ) {
V_161 = F_82 ( V_160 , V_162 ) ;
V_163 = V_161 * V_42 -> V_158 ;
V_42 -> V_167 [ V_70 ] . V_168 =
F_84 ( V_13 -> V_62 , V_163 , V_72 ,
& V_42 -> V_167 [ V_70 ] . V_169 ) ;
if ( ! V_42 -> V_167 [ V_70 ] . V_168 )
return - V_170 ;
V_42 -> V_167 [ V_70 ] . V_163 = V_163 ;
V_160 -= V_161 ;
if ( ! V_160 )
break;
}
if ( V_160 ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_24 ) ;
return - V_146 ;
}
return 0 ;
}
static void F_85 ( struct V_12 * V_13 , struct V_41 * V_42 )
{
unsigned int V_70 ;
for ( V_70 = 0 ; V_70 < F_83 ( V_42 -> V_167 ) ; ++ V_70 )
F_86 ( V_13 -> V_62 ,
V_42 -> V_167 [ V_70 ] . V_163 ,
V_42 -> V_167 [ V_70 ] . V_168 ,
V_42 -> V_167 [ V_70 ] . V_169 ) ;
}
static int F_87 ( struct V_12 * V_13 , struct V_41 * V_42 ,
void (* F_88)( struct V_20 * ) )
{
unsigned V_171 = V_42 -> V_158 ;
struct V_22 * V_20 ;
unsigned int V_172 , V_173 = 0 ;
for ( V_172 = 0 ; V_172 < F_83 ( V_42 -> V_167 ) ; ++ V_172 ) {
unsigned int V_163 = V_42 -> V_167 [ V_172 ] . V_163 ;
T_1 * V_168 = V_42 -> V_167 [ V_172 ] . V_168 ;
T_4 V_169 = V_42 -> V_167 [ V_172 ] . V_169 ;
while ( V_163 >= V_171 ) {
if ( V_173 >= V_42 -> V_55 )
goto V_174;
V_20 = F_89 ( sizeof( * V_20 ) , V_72 ) ;
if ( ! V_20 )
return - V_170 ;
F_90 ( & V_20 -> V_20 ) ;
V_20 -> V_20 . V_62 = V_13 -> V_62 ;
V_20 -> V_20 . V_175 = V_42 -> V_157 ;
V_20 -> V_20 . V_176 = V_177 ;
V_20 -> V_20 . V_50 = V_168 ;
V_20 -> V_20 . V_178 = V_169 ;
V_20 -> V_20 . V_179 = V_171 ;
V_20 -> V_20 . V_180 = 1 ;
V_20 -> V_20 . V_181 = 1 ;
V_20 -> V_20 . V_23 = V_13 ;
V_20 -> V_20 . V_39 = F_88 ;
V_20 -> V_20 . V_36 [ 0 ] . V_182 = 0 ;
V_20 -> V_20 . V_36 [ 0 ] . V_37 = V_171 ;
V_42 -> V_71 [ V_173 ++ ] = V_20 ;
V_163 -= V_171 ;
V_168 += V_171 ;
V_169 += V_171 ;
}
}
if ( V_173 == V_42 -> V_55 )
return 0 ;
V_174:
F_22 ( & V_13 -> V_62 -> V_62 , L_25 ) ;
return - V_146 ;
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
struct V_124 * V_125 )
{
unsigned int V_70 ;
struct V_124 * V_76 ;
F_52 ( & V_13 -> V_113 ) ;
F_91 ( & V_13 -> V_64 ) ;
F_91 ( & V_13 -> V_32 ) ;
F_53 ( & V_13 -> V_113 ) ;
F_85 ( V_13 , & V_13 -> V_64 ) ;
F_85 ( V_13 , & V_13 -> V_32 ) ;
for ( V_70 = 0 ; V_70 < F_83 ( V_13 -> V_76 ) ; ++ V_70 ) {
F_52 ( & V_13 -> V_113 ) ;
V_76 = V_13 -> V_76 [ V_70 ] ;
V_13 -> V_76 [ V_70 ] = NULL ;
F_53 ( & V_13 -> V_113 ) ;
if ( V_76 ) {
F_94 ( V_76 , NULL ) ;
if ( V_76 != V_125 )
F_95 ( & V_183 ,
V_76 ) ;
}
}
}
static void F_96 ( struct V_184 * V_185 )
{
struct V_12 * V_13 = V_185 -> V_111 ;
F_97 ( & V_13 -> V_113 ) ;
}
static int F_98 ( struct V_124 * V_125 ,
const struct V_186 * V_187 )
{
static const struct V_188 V_189 = {
. V_190 = 0x0001 ,
. V_191 = 0x0001
} ;
static const struct V_192 V_193 = {
. type = V_194 ,
. V_56 = & V_189
} ;
static const int V_195 [ 2 ] [ 3 ] = {
{
[ V_83 ] = 0 ,
[ V_82 ] = 1 ,
[ V_196 ] = 2 ,
} ,
{
[ V_82 ] = 1 ,
[ V_83 ] = 2 ,
[ V_196 ] = 3 ,
} ,
} ;
struct V_184 * V_185 ;
struct V_12 * V_13 ;
unsigned int V_197 , V_70 ;
int V_198 ;
const char * V_199 ;
char V_200 [ 32 ] ;
int V_1 ;
V_198 = V_187 -> V_201 == 0x0044 ;
if ( V_125 -> V_130 -> V_78 . V_80 !=
V_195 [ V_198 ] [ 0 ] )
return - V_2 ;
F_52 ( & V_202 ) ;
for ( V_197 = 0 ; V_197 < V_203 ; ++ V_197 )
if ( V_204 [ V_197 ] && ! ( V_205 & ( 1 << V_197 ) ) )
break;
if ( V_197 >= V_203 ) {
F_53 ( & V_202 ) ;
return - V_3 ;
}
V_1 = F_99 ( & V_125 -> V_62 ,
V_206 [ V_197 ] , V_207 [ V_197 ] , V_208 ,
sizeof( * V_13 ) , & V_185 ) ;
if ( V_1 < 0 ) {
F_53 ( & V_202 ) ;
return V_1 ;
}
V_185 -> V_209 = F_96 ;
V_13 = V_185 -> V_111 ;
V_13 -> V_62 = F_100 ( V_125 ) ;
V_13 -> V_185 = V_185 ;
V_13 -> V_197 = V_197 ;
F_42 ( & V_13 -> V_210 ) ;
F_101 ( & V_13 -> V_27 ) ;
F_102 ( & V_13 -> V_113 ) ;
F_42 ( & V_13 -> V_29 ) ;
F_103 ( & V_13 -> V_31 ,
V_31 , ( unsigned long ) V_13 ) ;
F_104 ( & V_13 -> V_16 ) ;
F_104 ( & V_13 -> V_17 ) ;
F_104 ( & V_13 -> V_19 ) ;
V_13 -> V_76 [ 0 ] = V_125 ;
for ( V_70 = 1 ; V_70 < F_83 ( V_13 -> V_76 ) ; ++ V_70 ) {
V_13 -> V_76 [ V_70 ] = F_105 ( V_13 -> V_62 ,
V_195 [ V_198 ] [ V_70 ] ) ;
if ( ! V_13 -> V_76 [ V_70 ] ) {
F_22 ( & V_13 -> V_62 -> V_62 , L_26 ,
V_195 [ V_198 ] [ V_70 ] ) ;
V_1 = - V_146 ;
goto V_211;
}
V_1 = F_106 ( & V_183 ,
V_13 -> V_76 [ V_70 ] , V_13 ) ;
if ( V_1 < 0 ) {
V_13 -> V_76 [ V_70 ] = NULL ;
V_1 = - V_212 ;
goto V_211;
}
}
V_1 = F_72 ( V_13 ) ;
if ( V_1 < 0 )
goto V_211;
V_199 = V_187 -> V_201 == 0x0044 ? L_27 : L_28 ;
strcpy ( V_185 -> V_213 , L_28 ) ;
strcpy ( V_185 -> V_214 , V_199 ) ;
F_107 ( V_13 -> V_62 , V_200 , sizeof( V_200 ) ) ;
snprintf ( V_13 -> V_185 -> V_215 , sizeof( V_13 -> V_185 -> V_215 ) ,
L_29 , V_199 ,
V_13 -> V_62 -> V_216 ? V_13 -> V_62 -> V_216 : L_30 , V_13 -> V_98 , V_200 ,
V_13 -> V_62 -> V_152 == V_154 ? L_31 : L_32 ) ;
V_1 = F_80 ( V_13 , & V_13 -> V_64 ) ;
if ( V_1 < 0 )
goto V_211;
V_1 = F_80 ( V_13 , & V_13 -> V_32 ) ;
if ( V_1 < 0 )
goto V_211;
V_1 = F_87 ( V_13 , & V_13 -> V_64 , F_25 ) ;
if ( V_1 < 0 )
goto V_211;
V_1 = F_87 ( V_13 , & V_13 -> V_32 , F_6 ) ;
if ( V_1 < 0 )
goto V_211;
V_1 = F_108 ( V_185 , V_199 , 0 , 1 , 1 , & V_13 -> V_217 ) ;
if ( V_1 < 0 )
goto V_211;
V_13 -> V_217 -> V_111 = V_13 ;
strcpy ( V_13 -> V_217 -> V_199 , V_199 ) ;
F_109 ( V_13 -> V_217 , V_218 , & V_219 ) ;
F_109 ( V_13 -> V_217 , V_220 , & V_221 ) ;
V_1 = F_110 ( V_185 , V_13 -> V_76 [ V_196 ] ,
& V_13 -> V_210 , & V_193 ) ;
if ( V_1 < 0 )
goto V_211;
V_1 = F_111 ( V_185 ) ;
if ( V_1 < 0 )
goto V_211;
F_94 ( V_125 , V_13 ) ;
V_205 |= 1 << V_197 ;
F_53 ( & V_202 ) ;
return 0 ;
V_211:
F_93 ( V_13 , V_125 ) ;
F_112 ( V_185 ) ;
F_53 ( & V_202 ) ;
return V_1 ;
}
static void F_113 ( struct V_124 * V_125 )
{
struct V_12 * V_13 = F_114 ( V_125 ) ;
struct V_222 * V_223 ;
if ( ! V_13 )
return;
F_52 ( & V_202 ) ;
F_15 ( V_81 , & V_13 -> V_15 ) ;
F_4 ( & V_13 -> V_17 ) ;
F_115 ( V_13 -> V_185 ) ;
F_116 (midi, &ua->midi_list)
F_117 ( V_223 ) ;
F_8 ( V_13 ) ;
F_26 ( V_13 ) ;
F_52 ( & V_13 -> V_113 ) ;
F_38 ( V_13 ) ;
F_35 ( V_13 ) ;
F_53 ( & V_13 -> V_113 ) ;
F_93 ( V_13 , V_125 ) ;
V_205 &= ~ ( 1 << V_13 -> V_197 ) ;
F_118 ( V_13 -> V_185 ) ;
F_53 ( & V_202 ) ;
}
