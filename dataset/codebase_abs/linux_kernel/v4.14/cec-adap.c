static int F_1 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 . V_6 ; V_4 ++ )
if ( V_2 -> V_5 . V_3 [ V_4 ] == V_3 )
return V_4 ;
return - 1 ;
}
static unsigned int F_2 ( const struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_1 ( V_2 , V_3 ) ;
return V_2 -> V_5 . V_7 [ V_4 < 0 ? 0 : V_4 ] ;
}
void F_3 ( struct V_8 * V_9 ,
const struct V_10 * V_11 , T_2 V_12 )
{
static const T_1 V_13 [ V_14 ] = {
1 , 1 , 64 , 64 ,
} ;
struct V_15 * V_16 ;
unsigned int V_17 = V_11 -> V_18 - 1 ;
if ( F_4 ( V_17 >= F_5 ( V_9 -> V_19 ) ) )
return;
if ( V_12 == 0 )
V_12 = F_6 () ;
F_7 ( & V_9 -> V_20 ) ;
if ( V_17 < V_21 )
V_16 = & V_9 -> V_22 [ V_17 ] ;
else
V_16 = F_8 ( sizeof( * V_16 ) , V_23 ) ;
if ( V_16 ) {
if ( V_11 -> V_18 == V_24 &&
V_9 -> V_25 [ V_17 ] ) {
V_16 -> V_26 . V_27 . V_27 +=
V_11 -> V_27 . V_27 ;
goto V_28;
}
V_16 -> V_26 = * V_11 ;
V_16 -> V_26 . V_12 = V_12 ;
if ( V_9 -> V_25 [ V_17 ] < V_13 [ V_17 ] ) {
F_9 ( & V_16 -> V_29 , & V_9 -> V_19 [ V_17 ] ) ;
V_9 -> V_25 [ V_17 ] ++ ;
V_9 -> V_30 ++ ;
goto V_28;
}
if ( V_17 >= V_21 ) {
F_9 ( & V_16 -> V_29 , & V_9 -> V_19 [ V_17 ] ) ;
V_16 = F_10 ( & V_9 -> V_19 [ V_17 ] ,
struct V_15 , V_29 ) ;
F_11 ( & V_16 -> V_29 ) ;
F_12 ( V_16 ) ;
}
}
V_16 = F_13 ( & V_9 -> V_19 [ V_17 ] ,
struct V_15 , V_29 ) ;
if ( V_16 )
V_16 -> V_26 . V_31 |= V_32 ;
V_28:
F_14 ( & V_9 -> V_20 ) ;
F_15 ( & V_9 -> V_33 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
const struct V_10 * V_26 )
{
T_2 V_12 = F_6 () ;
struct V_8 * V_9 ;
F_7 ( & V_2 -> V_34 . V_20 ) ;
F_17 (fh, &adap->devnode.fhs, list)
F_3 ( V_9 , V_26 , V_12 ) ;
F_14 ( & V_2 -> V_34 . V_20 ) ;
}
void F_18 ( struct V_1 * V_2 , bool V_35 , T_3 V_12 )
{
struct V_10 V_26 = {
. V_18 = V_35 ? V_36 :
V_37 ,
} ;
struct V_8 * V_9 ;
F_7 ( & V_2 -> V_34 . V_20 ) ;
F_17 (fh, &adap->devnode.fhs, list)
if ( V_9 -> V_38 == V_39 )
F_3 ( V_9 , & V_26 , F_19 ( V_12 ) ) ;
F_14 ( & V_2 -> V_34 . V_20 ) ;
}
static void F_20 ( struct V_8 * V_9 , const struct V_40 * V_41 )
{
static const struct V_10 V_42 = {
. V_18 = V_24 ,
. V_31 = 0 ,
{
. V_27 = { 1 } ,
} ,
} ;
struct V_43 * V_16 ;
F_7 ( & V_9 -> V_20 ) ;
V_16 = F_8 ( sizeof( * V_16 ) , V_23 ) ;
if ( V_16 ) {
V_16 -> V_41 = * V_41 ;
F_9 ( & V_16 -> V_29 , & V_9 -> V_44 ) ;
if ( V_9 -> V_45 < V_46 ) {
V_9 -> V_45 ++ ;
F_14 ( & V_9 -> V_20 ) ;
F_15 ( & V_9 -> V_33 ) ;
return;
}
V_16 = F_10 ( & V_9 -> V_44 , struct V_43 , V_29 ) ;
F_11 ( & V_16 -> V_29 ) ;
F_12 ( V_16 ) ;
}
F_14 ( & V_9 -> V_20 ) ;
F_3 ( V_9 , & V_42 , F_6 () ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_40 * V_41 ,
bool V_47 )
{
struct V_8 * V_9 ;
T_4 V_48 = V_47 ? V_49 :
V_50 ;
F_7 ( & V_2 -> V_34 . V_20 ) ;
F_17 (fh, &adap->devnode.fhs, list) {
if ( V_9 -> V_38 >= V_48 )
F_20 ( V_9 , V_41 ) ;
}
F_14 ( & V_2 -> V_34 . V_20 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_8 * V_9 ;
F_7 ( & V_2 -> V_34 . V_20 ) ;
F_17 (fh, &adap->devnode.fhs, list) {
if ( V_9 -> V_38 == V_51 )
F_20 ( V_9 , V_41 ) ;
}
F_14 ( & V_2 -> V_34 . V_20 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_10 V_26 = {
. V_18 = V_52 ,
} ;
V_26 . V_53 . V_54 = V_2 -> V_54 ;
V_26 . V_53 . V_55 = V_2 -> V_5 . V_55 ;
F_16 ( V_2 , & V_26 ) ;
}
static void F_24 ( struct V_56 * V_57 )
{
if ( V_57 -> V_9 )
F_11 ( & V_57 -> V_58 ) ;
if ( V_57 -> V_59 ) {
V_57 -> V_60 = true ;
F_25 ( & V_57 -> V_61 ) ;
} else {
if ( V_57 -> V_9 )
F_20 ( V_57 -> V_9 , & V_57 -> V_41 ) ;
F_12 ( V_57 ) ;
}
}
static void F_26 ( struct V_56 * V_57 )
{
if ( V_57 -> V_2 -> V_62 == V_57 ) {
V_57 -> V_2 -> V_62 = NULL ;
} else {
F_27 ( & V_57 -> V_29 ) ;
if ( ! ( V_57 -> V_41 . V_63 & V_64 ) )
V_57 -> V_2 -> V_65 -- ;
}
V_57 -> V_41 . V_66 = F_6 () ;
V_57 -> V_41 . V_63 |= V_67 |
V_68 ;
V_57 -> V_41 . V_69 ++ ;
V_57 -> V_70 = 0 ;
F_21 ( V_57 -> V_2 , & V_57 -> V_41 , 1 ) ;
F_24 ( V_57 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_56 * V_57 , * V_71 ;
while ( ! F_29 ( & V_2 -> V_72 ) ) {
V_57 = F_10 ( & V_2 -> V_72 ,
struct V_56 , V_29 ) ;
F_26 ( V_57 ) ;
}
if ( V_2 -> V_62 )
F_26 ( V_2 -> V_62 ) ;
F_30 (data, n, &adap->wait_queue, list) {
if ( F_31 ( & V_57 -> V_73 ) )
F_26 ( V_57 ) ;
}
}
int F_32 ( void * V_74 )
{
struct V_1 * V_2 = V_74 ;
for (; ; ) {
unsigned int V_75 ;
struct V_56 * V_57 ;
bool V_76 = false ;
T_1 V_70 ;
if ( V_2 -> V_62 ) {
int V_77 ;
V_77 = F_33 ( V_2 -> V_78 ,
( V_2 -> V_79 &&
( ! V_2 -> V_80 && ! V_2 -> V_81 ) ) ||
F_34 () ||
( ! V_2 -> V_62 &&
! F_29 ( & V_2 -> V_72 ) ) ,
F_35 ( V_82 ) ) ;
V_76 = V_77 == 0 ;
} else {
F_36 ( V_2 -> V_78 ,
F_34 () ||
( ! V_2 -> V_62 &&
! F_29 ( & V_2 -> V_72 ) ) ) ;
}
F_7 ( & V_2 -> V_20 ) ;
if ( ( V_2 -> V_79 &&
( ! V_2 -> V_80 && ! V_2 -> V_81 ) ) ||
F_34 () ) {
F_28 ( V_2 ) ;
goto V_28;
}
if ( V_2 -> V_62 && V_76 ) {
F_37 ( 1 , L_1 , V_83 ,
V_2 -> V_62 -> V_41 . V_84 ,
V_2 -> V_62 -> V_41 . V_41 ) ;
V_2 -> V_85 ++ ;
F_26 ( V_2 -> V_62 ) ;
goto V_28;
}
if ( V_2 -> V_62 || F_29 ( & V_2 -> V_72 ) )
goto V_28;
V_57 = F_10 ( & V_2 -> V_72 ,
struct V_56 , V_29 ) ;
F_27 ( & V_57 -> V_29 ) ;
V_2 -> V_65 -- ;
V_2 -> V_62 = V_57 ;
if ( V_57 -> V_41 . V_84 == 1 && V_2 -> V_80 )
V_70 = 2 ;
else
V_70 = 4 ;
if ( V_57 -> V_70 ) {
V_75 = V_86 ;
} else if ( V_57 -> V_87 ) {
V_75 = V_88 ;
} else {
V_75 = V_89 ;
}
if ( V_57 -> V_70 == 0 )
V_57 -> V_70 = V_70 ;
if ( V_2 -> V_90 -> V_91 ( V_2 , V_57 -> V_70 ,
V_75 , & V_57 -> V_41 ) )
F_26 ( V_57 ) ;
V_28:
F_14 ( & V_2 -> V_20 ) ;
if ( F_34 () )
break;
}
return 0 ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_92 ,
T_1 V_93 , T_1 V_94 , T_1 V_95 ,
T_1 V_96 , T_3 V_12 )
{
struct V_56 * V_57 ;
struct V_40 * V_41 ;
unsigned int V_97 = V_93 + V_94 +
V_95 + V_96 ;
F_37 ( 2 , L_2 , V_83 , V_92 ) ;
if ( V_97 < 1 )
V_97 = 1 ;
F_7 ( & V_2 -> V_20 ) ;
V_57 = V_2 -> V_62 ;
if ( ! V_57 ) {
F_37 ( 1 , L_3 ,
V_83 ) ;
goto V_28;
}
V_41 = & V_57 -> V_41 ;
F_4 ( V_92 == 0 ) ;
V_41 -> V_66 = F_19 ( V_12 ) ;
V_41 -> V_63 |= V_92 ;
V_41 -> V_98 += V_93 ;
V_41 -> V_99 += V_94 ;
V_41 -> V_100 += V_95 ;
V_41 -> V_69 += V_96 ;
V_2 -> V_62 = NULL ;
if ( V_57 -> V_70 > V_97 &&
! ( V_92 & ( V_68 | V_64 ) ) ) {
V_57 -> V_70 -= V_97 ;
if ( V_41 -> V_76 )
F_37 ( 2 , L_4 ,
V_41 -> V_84 , V_41 -> V_41 , V_57 -> V_70 , V_41 -> V_101 ) ;
else
F_37 ( 2 , L_5 ,
V_41 -> V_84 , V_41 -> V_41 , V_57 -> V_70 ) ;
F_39 ( & V_57 -> V_29 , & V_2 -> V_72 ) ;
V_2 -> V_65 ++ ;
goto V_102;
}
V_57 -> V_70 = 0 ;
if ( ! ( V_92 & V_64 ) )
V_41 -> V_63 |= V_68 ;
F_21 ( V_2 , V_41 , 1 ) ;
if ( ( V_92 & V_64 ) && V_2 -> V_80 &&
V_41 -> V_76 ) {
F_9 ( & V_57 -> V_29 , & V_2 -> V_103 ) ;
F_40 ( & V_57 -> V_73 ,
F_35 ( V_41 -> V_76 ) ) ;
} else {
F_24 ( V_57 ) ;
}
V_102:
F_15 ( & V_2 -> V_78 ) ;
V_28:
F_14 ( & V_2 -> V_20 ) ;
}
void F_41 ( struct V_1 * V_2 ,
T_1 V_92 , T_3 V_12 )
{
switch ( V_92 & ~ V_68 ) {
case V_64 :
F_38 ( V_2 , V_92 , 0 , 0 , 0 , 0 , V_12 ) ;
return;
case V_104 :
F_38 ( V_2 , V_92 , 1 , 0 , 0 , 0 , V_12 ) ;
return;
case V_105 :
F_38 ( V_2 , V_92 , 0 , 1 , 0 , 0 , V_12 ) ;
return;
case V_106 :
F_38 ( V_2 , V_92 , 0 , 0 , 1 , 0 , V_12 ) ;
return;
case V_67 :
F_38 ( V_2 , V_92 , 0 , 0 , 0 , 1 , V_12 ) ;
return;
default:
F_42 ( 1 , L_6 , V_2 -> V_107 , V_92 ) ;
return;
}
}
static void F_43 ( struct V_108 * V_73 )
{
struct V_56 * V_57 = F_44 ( V_73 , struct V_56 , V_73 . V_73 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
F_7 ( & V_2 -> V_20 ) ;
if ( F_29 ( & V_57 -> V_29 ) )
goto V_28;
F_27 ( & V_57 -> V_29 ) ;
V_57 -> V_41 . V_109 = F_6 () ;
V_57 -> V_41 . V_110 = V_111 ;
F_24 ( V_57 ) ;
V_28:
F_14 ( & V_2 -> V_20 ) ;
}
int F_45 ( struct V_1 * V_2 , struct V_40 * V_41 ,
struct V_8 * V_9 , bool V_112 )
{
struct V_56 * V_57 ;
T_1 V_113 = 0xff ;
unsigned int V_76 ;
int V_114 = 0 ;
V_41 -> V_109 = 0 ;
V_41 -> V_66 = 0 ;
V_41 -> V_110 = 0 ;
V_41 -> V_63 = 0 ;
V_41 -> V_98 = 0 ;
V_41 -> V_99 = 0 ;
V_41 -> V_100 = 0 ;
V_41 -> V_69 = 0 ;
V_41 -> V_115 = 0 ;
if ( V_41 -> V_101 && V_41 -> V_76 == 0 ) {
V_41 -> V_76 = 1000 ;
}
if ( V_41 -> V_76 )
V_41 -> V_31 &= V_116 ;
else
V_41 -> V_31 = 0 ;
if ( V_41 -> V_84 == 0 || V_41 -> V_84 > V_117 ) {
F_37 ( 1 , L_7 , V_83 , V_41 -> V_84 ) ;
return - V_118 ;
}
if ( V_41 -> V_76 && V_41 -> V_84 == 1 ) {
F_37 ( 1 , L_8 , V_83 ) ;
return - V_118 ;
}
memset ( V_41 -> V_41 + V_41 -> V_84 , 0 , sizeof( V_41 -> V_41 ) - V_41 -> V_84 ) ;
if ( V_41 -> V_84 == 1 ) {
if ( F_46 ( V_41 ) == 0xf ) {
F_37 ( 1 , L_9 , V_83 ) ;
return - V_118 ;
}
if ( F_47 ( V_2 , F_46 ( V_41 ) ) ) {
V_41 -> V_66 = F_6 () ;
V_41 -> V_63 = V_105 |
V_68 ;
V_41 -> V_99 = 1 ;
V_41 -> V_115 = ++ V_2 -> V_115 ;
if ( ! V_41 -> V_115 )
V_41 -> V_115 = ++ V_2 -> V_115 ;
return 0 ;
}
}
if ( V_41 -> V_84 > 1 && ! F_48 ( V_41 ) &&
F_47 ( V_2 , F_46 ( V_41 ) ) ) {
F_37 ( 1 , L_10 , V_83 ) ;
return - V_118 ;
}
if ( V_41 -> V_84 > 1 && V_2 -> V_80 &&
! F_47 ( V_2 , F_49 ( V_41 ) ) ) {
F_37 ( 1 , L_11 ,
V_83 , F_49 ( V_41 ) ) ;
return - V_118 ;
}
if ( ! V_2 -> V_80 && ! V_2 -> V_81 ) {
if ( V_2 -> V_79 || V_41 -> V_41 [ 0 ] != 0xf0 ) {
F_37 ( 1 , L_12 , V_83 ) ;
return - V_119 ;
}
if ( V_41 -> V_101 ) {
F_37 ( 1 , L_13 , V_83 ) ;
return - V_118 ;
}
}
if ( V_2 -> V_65 >= V_120 ) {
F_37 ( 1 , L_14 , V_83 ) ;
return - V_121 ;
}
V_57 = F_50 ( sizeof( * V_57 ) , V_23 ) ;
if ( ! V_57 )
return - V_122 ;
V_41 -> V_115 = ++ V_2 -> V_115 ;
if ( ! V_41 -> V_115 )
V_41 -> V_115 = ++ V_2 -> V_115 ;
if ( V_41 -> V_84 > 1 && V_41 -> V_41 [ 1 ] == V_123 ) {
V_41 -> V_41 [ 2 ] = V_2 -> V_54 >> 8 ;
V_41 -> V_41 [ 3 ] = V_2 -> V_54 & 0xff ;
}
if ( V_41 -> V_76 )
F_37 ( 2 , L_15 ,
V_83 , V_41 -> V_84 , V_41 -> V_41 , V_41 -> V_101 ,
! V_112 ? L_16 : L_17 ) ;
else
F_37 ( 2 , L_18 ,
V_83 , V_41 -> V_84 , V_41 -> V_41 , ! V_112 ? L_19 : L_17 ) ;
V_57 -> V_41 = * V_41 ;
V_57 -> V_9 = V_9 ;
V_57 -> V_2 = V_2 ;
V_57 -> V_59 = V_112 ;
if ( V_41 -> V_84 > 1 ) {
if ( ! ( F_29 ( & V_2 -> V_72 ) ) ) {
const struct V_56 * V_124 ;
V_124 = F_51 ( & V_2 -> V_72 ,
const struct V_56 , V_29 ) ;
V_113 = F_49 ( & V_124 -> V_41 ) ;
} else if ( V_2 -> V_62 ) {
V_113 =
F_49 ( & V_2 -> V_62 -> V_41 ) ;
}
}
V_57 -> V_87 = V_113 != F_49 ( V_41 ) ;
F_52 ( & V_57 -> V_61 ) ;
F_53 ( & V_57 -> V_73 , F_43 ) ;
if ( V_9 )
F_9 ( & V_57 -> V_58 , & V_9 -> V_58 ) ;
F_9 ( & V_57 -> V_29 , & V_2 -> V_72 ) ;
V_2 -> V_65 ++ ;
if ( ! V_2 -> V_62 )
F_15 ( & V_2 -> V_78 ) ;
if ( ! V_112 )
return 0 ;
V_76 = V_82 ;
if ( V_41 -> V_76 )
V_76 += V_41 -> V_76 ;
F_14 ( & V_2 -> V_20 ) ;
V_114 = F_54 ( & V_57 -> V_61 ,
F_35 ( V_76 ) ) ;
F_7 ( & V_2 -> V_20 ) ;
if ( V_57 -> V_60 ) {
* V_41 = V_57 -> V_41 ;
F_12 ( V_57 ) ;
return 0 ;
}
V_57 -> V_59 = false ;
if ( V_57 -> V_9 )
F_11 ( & V_57 -> V_58 ) ;
V_57 -> V_9 = NULL ;
if ( V_114 == 0 ) {
if ( V_41 -> V_76 && ( V_41 -> V_63 & V_64 ) )
V_41 -> V_110 = V_111 ;
else
V_41 -> V_63 = V_68 ;
}
return V_114 > 0 ? 0 : V_114 ;
}
int F_55 ( struct V_1 * V_2 , struct V_40 * V_41 ,
bool V_112 )
{
int V_125 ;
F_7 ( & V_2 -> V_20 ) ;
V_125 = F_45 ( V_2 , V_41 , NULL , V_112 ) ;
F_14 ( & V_2 -> V_20 ) ;
return V_125 ;
}
void F_56 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_3 V_12 )
{
struct V_56 * V_57 ;
T_1 V_126 = F_49 ( V_41 ) ;
T_1 V_127 = F_46 ( V_41 ) ;
T_1 V_128 = V_41 -> V_41 [ 1 ] ;
bool V_129 = false ;
bool V_47 = true ;
T_1 V_130 = 0 ;
if ( F_4 ( ! V_41 -> V_84 || V_41 -> V_84 > V_117 ) )
return;
if ( V_126 != V_131 &&
F_47 ( V_2 , V_126 ) )
return;
V_41 -> V_109 = F_19 ( V_12 ) ;
V_41 -> V_110 = V_132 ;
V_41 -> V_115 = V_41 -> V_101 = V_41 -> V_76 = 0 ;
V_41 -> V_63 = 0 ;
V_41 -> V_66 = 0 ;
V_41 -> V_98 = 0 ;
V_41 -> V_99 = 0 ;
V_41 -> V_100 = 0 ;
V_41 -> V_69 = 0 ;
V_41 -> V_31 = 0 ;
memset ( V_41 -> V_41 + V_41 -> V_84 , 0 , sizeof( V_41 -> V_41 ) - V_41 -> V_84 ) ;
F_7 ( & V_2 -> V_20 ) ;
F_37 ( 2 , L_20 , V_83 , V_41 -> V_84 , V_41 -> V_41 ) ;
if ( ! F_48 ( V_41 ) )
V_47 = F_47 ( V_2 , V_127 ) ;
if ( V_47 && V_41 -> V_84 > 1 && V_133 [ V_128 ] ) {
T_1 V_134 = V_133 [ V_128 ] & V_135 ;
V_130 = V_133 [ V_128 ] & 0x1f ;
if ( V_41 -> V_84 < V_130 )
V_47 = false ;
else if ( ! F_48 ( V_41 ) && ! ( V_134 & V_136 ) )
V_47 = false ;
else if ( F_48 ( V_41 ) && ! ( V_134 & V_137 ) )
V_47 = false ;
else if ( F_48 ( V_41 ) &&
V_2 -> V_5 . V_138 >= V_139 &&
! ( V_134 & V_140 ) )
V_47 = false ;
}
if ( V_47 && V_130 ) {
switch ( V_128 ) {
case V_141 :
if ( V_41 -> V_41 [ 2 ] & 0x10 ) {
switch ( V_41 -> V_41 [ 2 ] & 0xf ) {
case V_142 :
case V_143 :
if ( V_41 -> V_84 < 5 )
V_47 = false ;
break;
}
} else if ( ( V_41 -> V_41 [ 2 ] & 0xf ) == V_144 ) {
if ( V_41 -> V_84 < 5 )
V_47 = false ;
}
break;
case V_145 :
switch ( V_41 -> V_41 [ 2 ] ) {
case V_146 :
break;
case V_147 :
if ( V_41 -> V_84 < 10 )
V_47 = false ;
break;
case V_148 :
if ( V_41 -> V_84 < 7 )
V_47 = false ;
break;
case V_149 :
if ( V_41 -> V_84 < 4 )
V_47 = false ;
break;
case V_150 :
if ( V_41 -> V_84 < 5 )
V_47 = false ;
break;
}
break;
}
}
if ( V_47 && V_41 -> V_84 > 1 && V_128 != V_123 ) {
bool abort = V_128 == V_151 ;
if ( abort )
V_128 = V_41 -> V_41 [ 2 ] ;
F_17 (data, &adap->wait_queue, list) {
struct V_40 * V_152 = & V_57 -> V_41 ;
if ( ! abort && V_152 -> V_41 [ 1 ] == V_153 &&
( V_128 == V_154 ||
V_128 == V_155 ) &&
( V_152 -> V_101 == V_154 ||
V_152 -> V_101 == V_155 ) )
V_152 -> V_101 = V_128 ;
if ( ( abort && V_128 != V_152 -> V_41 [ 1 ] ) ||
( ! abort && V_128 != V_152 -> V_101 ) )
continue;
if ( V_126 != F_46 ( V_152 ) &&
! F_48 ( V_152 ) )
continue;
memcpy ( V_152 -> V_41 , V_41 -> V_41 , V_41 -> V_84 ) ;
V_152 -> V_84 = V_41 -> V_84 ;
V_152 -> V_109 = V_41 -> V_109 ;
V_152 -> V_110 = V_41 -> V_110 ;
if ( abort )
V_152 -> V_110 |= V_156 ;
V_41 -> V_31 = V_152 -> V_31 ;
F_27 ( & V_57 -> V_29 ) ;
if ( ! F_31 ( & V_57 -> V_73 ) ) {
F_14 ( & V_2 -> V_20 ) ;
F_57 () ;
F_7 ( & V_2 -> V_20 ) ;
}
if ( V_57 -> V_9 )
V_129 = true ;
F_24 ( V_57 ) ;
break;
}
}
F_14 ( & V_2 -> V_20 ) ;
F_21 ( V_2 , V_41 , V_47 ) ;
if ( ! V_47 || V_41 -> V_84 <= 1 )
return;
if ( V_2 -> V_5 . V_55 == 0 )
return;
F_58 ( V_2 , V_41 , V_129 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
unsigned int V_157 ,
unsigned int V_3 )
{
struct V_158 * V_159 = & V_2 -> V_5 ;
struct V_40 V_41 = { } ;
int V_77 ;
if ( F_47 ( V_2 , V_3 ) )
return 0 ;
V_41 . V_84 = 1 ;
V_41 . V_41 [ 0 ] = ( V_3 << 4 ) | V_3 ;
V_77 = F_45 ( V_2 , & V_41 , NULL , true ) ;
if ( ! V_2 -> V_81 )
return - V_160 ;
if ( V_77 )
return V_77 ;
if ( V_41 . V_63 & V_64 )
return 0 ;
V_77 = V_2 -> V_90 -> V_161 ( V_2 , V_3 ) ;
if ( V_77 )
return V_77 ;
V_159 -> V_3 [ V_157 ] = V_3 ;
V_159 -> V_55 |= 1 << V_3 ;
V_2 -> V_162 [ V_3 ] = V_2 -> V_54 ;
return 1 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_79 ||
V_2 -> V_54 != V_163 )
F_4 ( V_2 -> V_90 -> V_161 ( V_2 , V_164 ) ) ;
V_2 -> V_5 . V_55 = 0 ;
V_2 -> V_81 = false ;
V_2 -> V_80 = false ;
memset ( V_2 -> V_162 , 0xff , sizeof( V_2 -> V_162 ) ) ;
F_28 ( V_2 ) ;
F_15 ( & V_2 -> V_78 ) ;
F_23 ( V_2 ) ;
}
static int F_61 ( void * V_165 )
{
static const T_1 V_166 [] = {
V_167 , V_168 ,
V_164
} ;
static const T_1 V_169 [] = {
V_170 , V_171 ,
V_172 ,
V_173 , V_174 ,
V_164
} ;
static const T_1 V_175 [] = {
V_176 , V_177 ,
V_178 , V_179 ,
V_173 , V_174 ,
V_164
} ;
static const T_1 V_180 [] = {
V_181 , V_182 ,
V_183 ,
V_173 , V_174 ,
V_164
} ;
static const T_1 V_184 [] = {
V_185 ,
V_164
} ;
static const T_1 V_186 [] = {
V_168 ,
V_173 , V_174 ,
V_164
} ;
static const T_1 * V_187 [ 6 ] = {
[ V_188 ] = V_166 ,
[ V_189 ] = V_169 ,
[ V_190 ] = V_175 ,
[ V_191 ] = V_180 ,
[ V_192 ] = V_184 ,
[ V_193 ] = V_186 ,
} ;
static const T_5 V_194 [] = {
[ V_188 ] = V_195 ,
[ V_189 ] = V_196 ,
[ V_190 ] = V_197 ,
[ V_191 ] = V_198 ,
[ V_192 ] = V_199 ,
[ V_193 ] = V_200 ,
} ;
struct V_1 * V_2 = V_165 ;
struct V_158 * V_159 = & V_2 -> V_5 ;
int V_77 ;
int V_4 , V_201 ;
F_7 ( & V_2 -> V_20 ) ;
F_37 ( 1 , L_21 ,
F_62 ( V_2 -> V_54 ) , V_159 -> V_6 ) ;
V_159 -> V_55 = 0 ;
if ( V_159 -> V_202 [ 0 ] == V_203 )
goto V_204;
for ( V_4 = 0 ; V_4 < V_159 -> V_6 ; V_4 ++ ) {
unsigned int type = V_159 -> V_202 [ V_4 ] ;
const T_1 * V_205 ;
T_1 V_206 ;
if ( V_2 -> V_54 && type == V_188 )
type = V_193 ;
V_205 = V_187 [ type ] ;
V_206 = V_159 -> V_3 [ V_4 ] ;
V_159 -> V_3 [ V_4 ] = V_164 ;
if ( V_206 == V_164 ||
V_206 == V_131 ||
! ( ( 1 << V_206 ) & V_194 [ type ] ) )
V_206 = V_205 [ 0 ] ;
V_77 = F_59 ( V_2 , V_4 , V_206 ) ;
if ( V_77 > 0 )
continue;
if ( V_77 < 0 )
goto V_207;
for ( V_201 = 0 ; V_205 [ V_201 ] != V_164 ; V_201 ++ ) {
if ( V_205 [ V_201 ] == V_206 )
continue;
if ( ( V_205 [ V_201 ] == V_173 ||
V_205 [ V_201 ] == V_174 ) &&
V_159 -> V_138 < V_139 )
continue;
V_77 = F_59 ( V_2 , V_4 , V_205 [ V_201 ] ) ;
if ( V_77 == 0 )
continue;
if ( V_77 < 0 )
goto V_207;
break;
}
if ( V_205 [ V_201 ] == V_164 )
F_37 ( 1 , L_22 , V_4 ) ;
}
if ( V_2 -> V_5 . V_55 == 0 &&
! ( V_159 -> V_31 & V_208 ) )
goto V_207;
V_204:
if ( V_2 -> V_5 . V_55 == 0 ) {
V_159 -> V_3 [ 0 ] = V_131 ;
V_159 -> V_55 = 1 << V_159 -> V_3 [ 0 ] ;
for ( V_4 = 1 ; V_4 < V_159 -> V_6 ; V_4 ++ )
V_159 -> V_3 [ V_4 ] = V_164 ;
}
for ( V_4 = V_159 -> V_6 ; V_4 < V_209 ; V_4 ++ )
V_159 -> V_3 [ V_4 ] = V_164 ;
V_2 -> V_80 = true ;
V_2 -> V_81 = false ;
F_23 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_159 -> V_6 ; V_4 ++ ) {
struct V_40 V_41 = {} ;
if ( V_159 -> V_3 [ V_4 ] == V_164 ||
( V_159 -> V_31 & V_210 ) )
continue;
V_41 . V_41 [ 0 ] = ( V_159 -> V_3 [ V_4 ] << 4 ) | 0x0f ;
if ( V_159 -> V_3 [ V_4 ] != V_131 &&
V_2 -> V_5 . V_138 >= V_139 ) {
F_63 ( V_2 , & V_41 , V_4 ) ;
F_45 ( V_2 , & V_41 , NULL , false ) ;
}
F_64 ( & V_41 , V_2 -> V_54 ,
V_159 -> V_7 [ V_4 ] ) ;
F_37 ( 1 , L_23 ,
V_159 -> V_3 [ V_4 ] ,
F_62 ( V_2 -> V_54 ) ) ;
F_45 ( V_2 , & V_41 , NULL , false ) ;
}
V_2 -> V_211 = NULL ;
F_25 ( & V_2 -> V_212 ) ;
F_14 ( & V_2 -> V_20 ) ;
return 0 ;
V_207:
for ( V_4 = 0 ; V_4 < V_159 -> V_6 ; V_4 ++ )
V_159 -> V_3 [ V_4 ] = V_164 ;
F_60 ( V_2 ) ;
V_2 -> V_211 = NULL ;
F_14 ( & V_2 -> V_20 ) ;
F_25 ( & V_2 -> V_212 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , bool V_112 )
{
if ( F_4 ( V_2 -> V_81 || V_2 -> V_80 ) )
return;
F_52 ( & V_2 -> V_212 ) ;
V_2 -> V_81 = true ;
V_2 -> V_211 = F_66 ( F_61 , V_2 ,
L_24 , V_2 -> V_107 ) ;
if ( F_67 ( V_2 -> V_211 ) ) {
V_2 -> V_211 = NULL ;
} else if ( V_112 ) {
F_14 ( & V_2 -> V_20 ) ;
F_68 ( & V_2 -> V_212 ) ;
F_7 ( & V_2 -> V_20 ) ;
}
}
void F_69 ( struct V_1 * V_2 , T_5 V_54 , bool V_112 )
{
if ( V_54 == V_2 -> V_54 )
return;
if ( V_54 != V_163 && V_2 -> V_34 . V_213 )
return;
F_37 ( 1 , L_25 ,
F_62 ( V_54 ) ) ;
if ( V_54 == V_163 ||
V_2 -> V_54 != V_163 ) {
V_2 -> V_54 = V_163 ;
F_23 ( V_2 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_214 )
F_4 ( F_70 ( V_2 , V_215 , false ) ) ;
F_7 ( & V_2 -> V_34 . V_20 ) ;
if ( V_2 -> V_79 || F_29 ( & V_2 -> V_34 . V_216 ) )
F_4 ( V_2 -> V_90 -> V_217 ( V_2 , false ) ) ;
F_14 ( & V_2 -> V_34 . V_20 ) ;
if ( V_54 == V_163 )
return;
}
F_7 ( & V_2 -> V_34 . V_20 ) ;
if ( ( V_2 -> V_79 || F_29 ( & V_2 -> V_34 . V_216 ) ) &&
V_2 -> V_90 -> V_217 ( V_2 , true ) ) {
F_14 ( & V_2 -> V_34 . V_20 ) ;
return;
}
if ( V_2 -> V_214 &&
F_70 ( V_2 , V_215 , true ) ) {
if ( V_2 -> V_79 || F_29 ( & V_2 -> V_34 . V_216 ) )
F_4 ( V_2 -> V_90 -> V_217 ( V_2 , false ) ) ;
F_14 ( & V_2 -> V_34 . V_20 ) ;
return;
}
F_14 ( & V_2 -> V_34 . V_20 ) ;
V_2 -> V_54 = V_54 ;
F_23 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 )
F_65 ( V_2 , V_112 ) ;
}
void F_71 ( struct V_1 * V_2 , T_5 V_54 , bool V_112 )
{
if ( F_72 ( V_2 ) )
return;
F_7 ( & V_2 -> V_20 ) ;
F_69 ( V_2 , V_54 , V_112 ) ;
F_14 ( & V_2 -> V_20 ) ;
}
void F_73 ( struct V_1 * V_2 ,
const struct V_218 * V_218 )
{
T_5 V_219 = V_163 ;
if ( V_218 && V_218 -> V_220 )
V_219 = F_74 ( ( const T_1 * ) V_218 ,
V_221 * ( V_218 -> V_220 + 1 ) , NULL ) ;
F_71 ( V_2 , V_219 , false ) ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_158 * V_5 , bool V_112 )
{
T_5 V_222 = 0 ;
int V_4 ;
if ( V_2 -> V_34 . V_213 )
return - V_223 ;
if ( ! V_5 || V_5 -> V_6 == 0 ) {
F_60 ( V_2 ) ;
V_2 -> V_5 . V_6 = 0 ;
for ( V_4 = 0 ; V_4 < V_209 ; V_4 ++ )
V_2 -> V_5 . V_3 [ V_4 ] = V_164 ;
V_2 -> V_5 . V_224 [ 0 ] = '\0' ;
V_2 -> V_5 . V_225 = V_226 ;
V_2 -> V_5 . V_138 = V_139 ;
return 0 ;
}
if ( V_5 -> V_31 & V_210 ) {
V_5 -> V_6 = 1 ;
V_5 -> V_224 [ 0 ] = '\0' ;
V_5 -> V_225 = V_226 ;
V_5 -> V_202 [ 0 ] = V_203 ;
V_5 -> V_7 [ 0 ] = V_227 ;
V_5 -> V_228 [ 0 ] = 0 ;
V_5 -> V_229 [ 0 ] [ 0 ] = 0 ;
V_5 -> V_229 [ 0 ] [ 1 ] = 0 ;
}
V_5 -> V_224 [ sizeof( V_5 -> V_224 ) - 1 ] = '\0' ;
if ( V_5 -> V_6 > V_2 -> V_230 ) {
F_37 ( 1 , L_26 , V_2 -> V_230 ) ;
return - V_118 ;
}
if ( V_5 -> V_225 != V_226 &&
( V_5 -> V_225 & 0xff000000 ) != 0 ) {
F_37 ( 1 , L_27 ) ;
return - V_118 ;
}
if ( V_5 -> V_138 != V_231 &&
V_5 -> V_138 != V_139 ) {
F_37 ( 1 , L_28 ) ;
return - V_118 ;
}
if ( V_5 -> V_6 > 1 )
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ )
if ( V_5 -> V_202 [ V_4 ] ==
V_203 ) {
F_37 ( 1 , L_29 ) ;
return - V_118 ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
const T_1 V_232 = F_5 ( V_5 -> V_229 [ 0 ] ) ;
T_1 * V_229 = V_5 -> V_229 [ V_4 ] ;
bool V_233 = false ;
unsigned V_201 ;
V_5 -> V_3 [ V_4 ] = V_164 ;
if ( V_222 & ( 1 << V_5 -> V_202 [ V_4 ] ) ) {
F_37 ( 1 , L_30 ) ;
return - V_118 ;
}
V_222 |= 1 << V_5 -> V_202 [ V_4 ] ;
if ( ( V_222 & ( 1 << V_189 ) ) &&
( V_222 & ( 1 << V_191 ) ) ) {
F_37 ( 1 , L_31 ) ;
return - V_118 ;
}
if ( V_5 -> V_7 [ V_4 ] >
V_234 ) {
F_37 ( 1 , L_32 ) ;
return - V_118 ;
}
if ( V_5 -> V_7 [ V_4 ] == 2 ) {
F_37 ( 1 , L_33 ) ;
return - V_118 ;
}
if ( V_5 -> V_202 [ V_4 ] > V_203 ) {
F_37 ( 1 , L_34 ) ;
return - V_118 ;
}
for ( V_201 = 0 ; V_201 < V_232 ; V_201 ++ ) {
if ( ( V_229 [ V_201 ] & 0x80 ) == 0 ) {
if ( V_233 )
break;
V_233 = true ;
}
}
if ( ! V_233 || V_201 == V_232 ) {
F_37 ( 1 , L_35 ) ;
return - V_118 ;
}
memset ( V_229 + V_201 + 1 , 0 , V_232 - V_201 - 1 ) ;
}
if ( V_5 -> V_138 >= V_139 ) {
if ( V_5 -> V_6 > 2 ) {
F_37 ( 1 , L_36 ) ;
return - V_118 ;
}
if ( V_5 -> V_6 == 2 ) {
if ( ! ( V_222 & ( ( 1 << V_192 ) |
( 1 << V_188 ) ) ) ) {
F_37 ( 1 , L_37 ) ;
return - V_118 ;
}
if ( ! ( V_222 & ( ( 1 << V_191 ) |
( 1 << V_189 ) ) ) ) {
F_37 ( 1 , L_38 ) ;
return - V_118 ;
}
}
}
for ( V_4 = V_5 -> V_6 ; V_4 < V_209 ; V_4 ++ ) {
V_5 -> V_7 [ V_4 ] = 0 ;
V_5 -> V_202 [ V_4 ] = 0 ;
V_5 -> V_228 [ V_4 ] = 0 ;
memset ( V_5 -> V_229 [ V_4 ] , 0 ,
sizeof( V_5 -> V_229 [ V_4 ] ) ) ;
}
V_5 -> V_55 = V_2 -> V_5 . V_55 ;
V_2 -> V_5 = * V_5 ;
if ( V_2 -> V_54 != V_163 )
F_65 ( V_2 , V_112 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_158 * V_5 , bool V_112 )
{
int V_77 ;
F_7 ( & V_2 -> V_20 ) ;
V_77 = F_75 ( V_2 , V_5 , V_112 ) ;
F_14 ( & V_2 -> V_20 ) ;
return V_77 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
unsigned int V_235 )
{
const struct V_158 * V_159 = & V_2 -> V_5 ;
const T_1 * V_229 = V_159 -> V_229 [ V_235 ] ;
bool V_233 = false ;
unsigned int V_157 ;
V_41 -> V_41 [ 0 ] = ( V_159 -> V_3 [ V_235 ] << 4 ) | 0x0f ;
V_41 -> V_84 = 4 ;
V_41 -> V_41 [ 1 ] = V_236 ;
V_41 -> V_41 [ 2 ] = V_2 -> V_5 . V_138 ;
V_41 -> V_41 [ 3 ] = V_159 -> V_228 [ V_235 ] ;
for ( V_157 = 0 ; V_157 < F_5 ( V_159 -> V_229 [ 0 ] ) ; V_157 ++ ) {
V_41 -> V_41 [ V_41 -> V_84 ++ ] = V_229 [ V_157 ] ;
if ( ( V_229 [ V_157 ] & V_237 ) == 0 ) {
if ( V_233 )
break;
V_233 = true ;
}
}
}
static int F_77 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_1 V_238 )
{
struct V_40 V_239 = { } ;
if ( V_41 -> V_41 [ 1 ] == V_151 )
return 0 ;
if ( F_49 ( V_41 ) == V_131 )
return 0 ;
F_78 ( & V_239 , V_41 ) ;
F_79 ( & V_239 , V_41 -> V_41 [ 1 ] , V_238 ) ;
return F_55 ( V_2 , & V_239 , false ) ;
}
static int F_80 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
return F_77 ( V_2 , V_41 ,
V_240 ) ;
}
static int F_81 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
return F_77 ( V_2 , V_41 ,
V_241 ) ;
}
static int F_58 ( struct V_1 * V_2 , struct V_40 * V_41 ,
bool V_129 )
{
bool V_242 = F_48 ( V_41 ) ;
T_1 V_243 = F_46 ( V_41 ) ;
T_1 V_244 = F_49 ( V_41 ) ;
T_1 V_245 = F_2 ( V_2 , V_243 ) ;
int V_235 = F_1 ( V_2 , V_243 ) ;
bool V_246 = V_244 == 0xf ;
struct V_40 V_247 = { } ;
#ifdef F_82
int V_248 ;
#endif
F_37 ( 2 , L_20 , V_83 , V_41 -> V_84 , V_41 -> V_41 ) ;
if ( F_83 ( & V_2 -> V_5 ) &&
V_41 -> V_41 [ 1 ] != V_123 )
return 0 ;
if ( V_2 -> V_90 -> V_249 ) {
if ( V_2 -> V_90 -> V_249 ( V_2 , V_41 ) != - V_250 )
return 0 ;
}
switch ( V_41 -> V_41 [ 1 ] ) {
case V_251 :
case V_252 :
case V_253 :
case V_254 :
if ( ! V_2 -> V_255 && V_246 )
return 0 ;
case V_256 :
case V_257 :
case V_258 :
if ( V_2 -> V_255 )
goto V_259;
if ( V_242 )
return 0 ;
break;
case V_260 :
case V_261 :
if ( V_242 || V_246 )
goto V_259;
break;
case V_262 :
if ( ! V_242 )
goto V_259;
break;
default:
break;
}
F_78 ( & V_247 , V_41 ) ;
switch ( V_41 -> V_41 [ 1 ] ) {
case V_262 : {
T_5 V_219 = ( V_41 -> V_41 [ 2 ] << 8 ) | V_41 -> V_41 [ 3 ] ;
if ( ! V_246 )
V_2 -> V_162 [ V_244 ] = V_219 ;
F_37 ( 1 , L_39 ,
F_62 ( V_219 ) , V_244 ) ;
break;
}
case V_260 :
if ( ! ( V_2 -> V_263 & V_264 ) ||
! ( V_2 -> V_5 . V_31 & V_265 ) )
break;
#ifdef F_82
switch ( V_41 -> V_41 [ 2 ] ) {
case 0x60 :
if ( V_41 -> V_84 == 2 )
V_248 = V_41 -> V_41 [ 2 ] ;
else
V_248 = V_41 -> V_41 [ 2 ] << 8 | V_41 -> V_41 [ 3 ] ;
break;
case 0x56 : case 0x57 :
case 0x67 : case 0x68 : case 0x69 : case 0x6a :
V_248 = - 1 ;
break;
default:
V_248 = V_41 -> V_41 [ 2 ] ;
break;
}
if ( V_2 -> V_266 && ! V_2 -> V_267 -> V_268 ) {
V_2 -> V_266 = false ;
V_2 -> V_269 = - 1 ;
}
if ( V_2 -> V_269 != V_248 ) {
F_84 ( V_2 -> V_267 ) ;
V_2 -> V_266 = false ;
}
if ( V_248 < 0 ) {
V_2 -> V_269 = V_248 ;
break;
}
F_85 ( V_2 -> V_267 , V_270 , V_248 , 0 ) ;
if ( V_2 -> V_266 )
break;
if ( V_2 -> V_269 == V_248 &&
V_41 -> V_109 - V_2 -> V_271 < 550 * V_272 ) {
V_2 -> V_266 = true ;
break;
}
F_84 ( V_2 -> V_267 ) ;
V_2 -> V_269 = V_248 ;
V_2 -> V_271 = V_41 -> V_109 ;
#endif
break;
case V_261 :
if ( ! ( V_2 -> V_263 & V_264 ) ||
! ( V_2 -> V_5 . V_31 & V_265 ) )
break;
#ifdef F_82
F_84 ( V_2 -> V_267 ) ;
V_2 -> V_266 = false ;
V_2 -> V_269 = - 1 ;
#endif
break;
case V_251 :
F_86 ( & V_247 , V_2 -> V_5 . V_138 ) ;
return F_55 ( V_2 , & V_247 , false ) ;
case V_258 :
if ( V_245 == V_227 && V_243 == 15 )
return 0 ;
F_64 ( & V_247 , V_2 -> V_54 , V_245 ) ;
return F_55 ( V_2 , & V_247 , false ) ;
case V_256 :
if ( V_2 -> V_5 . V_225 == V_226 )
return F_80 ( V_2 , V_41 ) ;
F_87 ( & V_247 , V_2 -> V_5 . V_225 ) ;
return F_55 ( V_2 , & V_247 , false ) ;
case V_252 :
if ( V_245 == V_227 )
return 0 ;
return F_81 ( V_2 , V_41 ) ;
case V_254 : {
if ( V_2 -> V_5 . V_224 [ 0 ] == 0 )
return F_80 ( V_2 , V_41 ) ;
F_88 ( & V_247 , V_2 -> V_5 . V_224 ) ;
return F_55 ( V_2 , & V_247 , false ) ;
}
case V_257 :
if ( V_2 -> V_5 . V_138 < V_139 )
return F_80 ( V_2 , V_41 ) ;
F_63 ( V_2 , & V_247 , V_235 ) ;
return F_55 ( V_2 , & V_247 , false ) ;
default:
if ( ! V_242 && ! V_129 && ! V_2 -> V_273 &&
! V_2 -> V_274 && V_41 -> V_41 [ 1 ] != V_151 )
return F_80 ( V_2 , V_41 ) ;
break;
}
V_259:
if ( V_129 && ! ( V_41 -> V_31 & V_116 ) )
return 0 ;
if ( V_2 -> V_274 )
F_20 ( V_2 -> V_274 , V_41 ) ;
else
F_22 ( V_2 , V_41 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_125 = 0 ;
if ( V_2 -> V_214 == 0 )
V_125 = F_70 ( V_2 , V_215 , 1 ) ;
if ( V_125 == 0 )
V_2 -> V_214 ++ ;
return V_125 ;
}
void F_90 ( struct V_1 * V_2 )
{
V_2 -> V_214 -- ;
if ( V_2 -> V_214 == 0 )
F_4 ( F_70 ( V_2 , V_215 , 0 ) ) ;
}
int F_91 ( struct V_275 * V_276 , void * V_277 )
{
struct V_1 * V_2 = F_92 ( V_276 -> V_278 ) ;
struct V_56 * V_57 ;
F_7 ( & V_2 -> V_20 ) ;
F_93 ( V_276 , L_40 , V_2 -> V_80 ) ;
F_93 ( V_276 , L_41 , V_2 -> V_81 ) ;
F_93 ( V_276 , L_42 ,
F_62 ( V_2 -> V_54 ) ) ;
F_93 ( V_276 , L_43 , V_2 -> V_5 . V_6 ) ;
F_93 ( V_276 , L_44 , V_2 -> V_5 . V_55 ) ;
if ( V_2 -> V_274 )
F_93 ( V_276 , L_45 ,
V_2 -> V_255 ? L_46 : L_17 ) ;
if ( V_2 -> V_279 )
F_94 ( V_276 , L_47 ) ;
if ( V_2 -> V_214 )
F_93 ( V_276 , L_48 ,
V_2 -> V_214 ) ;
if ( V_2 -> V_85 ) {
F_93 ( V_276 , L_49 ,
V_2 -> V_85 ) ;
V_2 -> V_85 = 0 ;
}
V_57 = V_2 -> V_62 ;
if ( V_57 )
F_93 ( V_276 , L_50 ,
V_57 -> V_41 . V_84 , V_57 -> V_41 . V_41 , V_57 -> V_41 . V_101 ,
V_57 -> V_41 . V_76 ) ;
F_93 ( V_276 , L_51 , V_2 -> V_65 ) ;
F_17 (data, &adap->transmit_queue, list) {
F_93 ( V_276 , L_52 ,
V_57 -> V_41 . V_84 , V_57 -> V_41 . V_41 , V_57 -> V_41 . V_101 ,
V_57 -> V_41 . V_76 ) ;
}
F_17 (data, &adap->wait_queue, list) {
F_93 ( V_276 , L_53 ,
V_57 -> V_41 . V_84 , V_57 -> V_41 . V_41 , V_57 -> V_41 . V_101 ,
V_57 -> V_41 . V_76 ) ;
}
F_95 ( V_2 , V_280 , V_276 ) ;
F_14 ( & V_2 -> V_20 ) ;
return 0 ;
}
