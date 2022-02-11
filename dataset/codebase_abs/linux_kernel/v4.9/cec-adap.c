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
struct V_10 * V_13 = & V_9 -> V_14 [ V_11 -> V_15 - 1 ] ;
if ( V_12 == 0 )
V_12 = F_4 () ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_11 -> V_15 == V_17 &&
V_9 -> V_18 & ( 1 << V_11 -> V_15 ) ) {
V_13 -> V_19 . V_19 += V_11 -> V_19 . V_19 ;
goto V_20;
}
* V_13 = * V_11 ;
V_13 -> V_12 = V_12 ;
V_9 -> V_18 |= 1 << V_11 -> V_15 ;
V_20:
F_6 ( & V_9 -> V_16 ) ;
F_7 ( & V_9 -> V_21 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
const struct V_10 * V_13 )
{
T_2 V_12 = F_4 () ;
struct V_8 * V_9 ;
F_5 ( & V_2 -> V_22 . V_16 ) ;
F_9 (fh, &adap->devnode.fhs, list)
F_3 ( V_9 , V_13 , V_12 ) ;
F_6 ( & V_2 -> V_22 . V_16 ) ;
}
static void F_10 ( struct V_8 * V_9 , const struct V_23 * V_24 )
{
static const struct V_10 V_25 = {
. V_12 = 0 ,
. V_15 = V_17 ,
. V_26 = 0 ,
{
. V_19 . V_19 = 1 ,
} ,
} ;
struct V_27 * V_28 ;
F_5 ( & V_9 -> V_16 ) ;
V_28 = F_11 ( sizeof( * V_28 ) , V_29 ) ;
if ( ! V_28 )
goto V_19;
V_28 -> V_24 = * V_24 ;
F_12 ( & V_28 -> V_30 , & V_9 -> V_31 ) ;
if ( V_9 -> V_32 == V_33 ) {
F_13 ( & V_28 -> V_30 ) ;
goto V_19;
}
V_9 -> V_32 ++ ;
F_6 ( & V_9 -> V_16 ) ;
F_7 ( & V_9 -> V_21 ) ;
return;
V_19:
F_6 ( & V_9 -> V_16 ) ;
F_3 ( V_9 , & V_25 , 0 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
const struct V_23 * V_24 ,
bool V_34 )
{
struct V_8 * V_9 ;
T_3 V_35 = V_34 ? V_36 :
V_37 ;
F_5 ( & V_2 -> V_22 . V_16 ) ;
F_9 (fh, &adap->devnode.fhs, list) {
if ( V_9 -> V_38 >= V_35 )
F_10 ( V_9 , V_24 ) ;
}
F_6 ( & V_2 -> V_22 . V_16 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_8 * V_9 ;
F_5 ( & V_2 -> V_22 . V_16 ) ;
F_9 (fh, &adap->devnode.fhs, list) {
if ( V_9 -> V_38 == V_39 )
F_10 ( V_9 , V_24 ) ;
}
F_6 ( & V_2 -> V_22 . V_16 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_10 V_13 = {
. V_15 = V_40 ,
} ;
V_13 . V_41 . V_42 = V_2 -> V_42 ;
V_13 . V_41 . V_43 = V_2 -> V_5 . V_43 ;
F_8 ( V_2 , & V_13 ) ;
}
static void F_17 ( struct V_44 * V_45 )
{
if ( V_45 -> V_9 )
F_13 ( & V_45 -> V_46 ) ;
if ( V_45 -> V_47 ) {
V_45 -> V_48 = true ;
F_18 ( & V_45 -> V_49 ) ;
} else {
if ( V_45 -> V_9 )
F_10 ( V_45 -> V_9 , & V_45 -> V_24 ) ;
F_19 ( V_45 ) ;
}
}
static void F_20 ( struct V_44 * V_45 )
{
if ( V_45 -> V_2 -> V_50 == V_45 ) {
V_45 -> V_2 -> V_50 = NULL ;
} else {
F_21 ( & V_45 -> V_30 ) ;
if ( ! ( V_45 -> V_24 . V_51 & V_52 ) )
V_45 -> V_2 -> V_53 -- ;
}
V_45 -> V_24 . V_54 = F_4 () ;
V_45 -> V_24 . V_51 = V_55 |
V_56 ;
V_45 -> V_57 = 0 ;
V_45 -> V_24 . V_58 = 1 ;
F_14 ( V_45 -> V_2 , & V_45 -> V_24 , 1 ) ;
F_17 ( V_45 ) ;
}
int F_22 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
for (; ; ) {
unsigned int V_60 ;
struct V_44 * V_45 ;
bool V_61 = false ;
T_1 V_57 ;
if ( V_2 -> V_50 ) {
int V_62 ;
V_62 = F_23 ( V_2 -> V_63 ,
F_24 () ||
( ! V_2 -> V_64 && ! V_2 -> V_65 ) ||
( ! V_2 -> V_50 &&
! F_25 ( & V_2 -> V_66 ) ) ,
F_26 ( V_67 ) ) ;
V_61 = V_62 == 0 ;
} else {
F_27 ( V_2 -> V_63 ,
F_24 () ||
( ! V_2 -> V_50 &&
! F_25 ( & V_2 -> V_66 ) ) ) ;
}
F_5 ( & V_2 -> V_16 ) ;
if ( ( ! V_2 -> V_64 && ! V_2 -> V_65 ) ||
F_24 () ) {
while ( ! F_25 ( & V_2 -> V_66 ) ) {
V_45 = F_28 ( & V_2 -> V_66 ,
struct V_44 , V_30 ) ;
F_20 ( V_45 ) ;
}
if ( V_2 -> V_50 )
F_20 ( V_2 -> V_50 ) ;
while ( ! F_25 ( & V_2 -> V_68 ) ) {
V_45 = F_28 ( & V_2 -> V_68 ,
struct V_44 , V_30 ) ;
if ( ! F_29 ( & V_45 -> V_69 ) ) {
F_6 ( & V_2 -> V_16 ) ;
F_30 () ;
F_5 ( & V_2 -> V_16 ) ;
}
F_20 ( V_45 ) ;
}
goto V_20;
}
if ( V_2 -> V_50 && V_61 ) {
F_31 ( 0 , L_1 ,
V_2 -> V_50 -> V_24 . V_70 ,
V_2 -> V_50 -> V_24 . V_24 ) ;
F_20 ( V_2 -> V_50 ) ;
goto V_20;
}
if ( V_2 -> V_50 || F_25 ( & V_2 -> V_66 ) )
goto V_20;
V_45 = F_28 ( & V_2 -> V_66 ,
struct V_44 , V_30 ) ;
F_21 ( & V_45 -> V_30 ) ;
V_2 -> V_53 -- ;
V_2 -> V_50 = V_45 ;
if ( V_45 -> V_24 . V_70 == 1 && V_2 -> V_64 )
V_57 = 2 ;
else
V_57 = 4 ;
if ( V_45 -> V_57 ) {
V_60 = V_71 ;
} else if ( V_45 -> V_72 ) {
V_60 = V_73 ;
} else {
V_60 = V_74 ;
}
if ( V_45 -> V_57 == 0 )
V_45 -> V_57 = V_57 ;
if ( V_2 -> V_75 -> V_76 ( V_2 , V_45 -> V_57 ,
V_60 , & V_45 -> V_24 ) )
F_20 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
if ( F_24 () )
break;
}
return 0 ;
}
void F_32 ( struct V_1 * V_2 , T_1 V_77 , T_1 V_78 ,
T_1 V_79 , T_1 V_80 , T_1 V_81 )
{
struct V_44 * V_45 ;
struct V_23 * V_24 ;
T_2 V_12 = F_4 () ;
F_31 ( 2 , L_2 , V_77 ) ;
F_5 ( & V_2 -> V_16 ) ;
V_45 = V_2 -> V_50 ;
if ( ! V_45 ) {
F_31 ( 1 , L_3 ) ;
goto V_20;
}
V_24 = & V_45 -> V_24 ;
F_33 ( V_77 == 0 ) ;
V_24 -> V_54 = V_12 ;
V_24 -> V_51 |= V_77 ;
V_24 -> V_82 += V_78 ;
V_24 -> V_83 += V_79 ;
V_24 -> V_84 += V_80 ;
V_24 -> V_58 += V_81 ;
V_2 -> V_50 = NULL ;
if ( V_45 -> V_57 > 1 &&
! ( V_77 & ( V_56 | V_52 ) ) ) {
V_45 -> V_57 -- ;
F_34 ( & V_45 -> V_30 , & V_2 -> V_66 ) ;
V_2 -> V_53 ++ ;
goto V_85;
}
V_45 -> V_57 = 0 ;
if ( ! ( V_77 & V_52 ) )
V_24 -> V_51 |= V_56 ;
F_14 ( V_2 , V_24 , 1 ) ;
if ( ( V_77 & V_52 ) && V_2 -> V_64 &&
V_24 -> V_61 ) {
F_12 ( & V_45 -> V_30 , & V_2 -> V_68 ) ;
F_35 ( & V_45 -> V_69 ,
F_26 ( V_24 -> V_61 ) ) ;
} else {
F_17 ( V_45 ) ;
}
V_85:
F_7 ( & V_2 -> V_63 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
static void F_36 ( struct V_86 * V_69 )
{
struct V_44 * V_45 = F_37 ( V_69 , struct V_44 , V_69 . V_69 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
F_5 ( & V_2 -> V_16 ) ;
if ( F_25 ( & V_45 -> V_30 ) )
goto V_20;
F_21 ( & V_45 -> V_30 ) ;
V_45 -> V_24 . V_87 = F_4 () ;
V_45 -> V_24 . V_88 = V_89 ;
F_17 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
int F_38 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_8 * V_9 , bool V_90 )
{
struct V_44 * V_45 ;
T_1 V_91 = 0xff ;
unsigned int V_61 ;
int V_92 = 0 ;
V_24 -> V_87 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_88 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_82 = 0 ;
V_24 -> V_83 = 0 ;
V_24 -> V_84 = 0 ;
V_24 -> V_58 = 0 ;
V_24 -> V_26 = 0 ;
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( ! V_24 -> V_93 )
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( V_24 -> V_94 && V_24 -> V_61 == 0 ) {
V_24 -> V_61 = 1000 ;
}
if ( V_24 -> V_70 == 0 || V_24 -> V_70 > V_95 ) {
F_31 ( 1 , L_4 , V_24 -> V_70 ) ;
return - V_96 ;
}
if ( V_24 -> V_61 && V_24 -> V_70 == 1 ) {
F_31 ( 1 , L_5 ) ;
return - V_96 ;
}
memset ( V_24 -> V_24 + V_24 -> V_70 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_70 ) ;
if ( V_24 -> V_70 == 1 ) {
if ( F_39 ( V_24 ) != 0xf ||
F_40 ( V_24 ) == 0xf ) {
F_31 ( 1 , L_6 ) ;
return - V_96 ;
}
if ( F_41 ( V_2 , F_40 ( V_24 ) ) ) {
V_24 -> V_54 = F_4 () ;
V_24 -> V_51 = V_97 |
V_56 ;
V_24 -> V_83 = 1 ;
return 0 ;
}
}
if ( V_24 -> V_70 > 1 && ! F_42 ( V_24 ) &&
F_41 ( V_2 , F_40 ( V_24 ) ) ) {
F_31 ( 1 , L_7 ) ;
return - V_96 ;
}
if ( F_39 ( V_24 ) != 0xf &&
! F_41 ( V_2 , F_39 ( V_24 ) ) ) {
F_31 ( 1 , L_8 ,
F_39 ( V_24 ) ) ;
return - V_96 ;
}
if ( ! V_2 -> V_64 && ! V_2 -> V_65 )
return - V_98 ;
if ( V_2 -> V_53 >= V_99 )
return - V_100 ;
V_45 = F_43 ( sizeof( * V_45 ) , V_29 ) ;
if ( ! V_45 )
return - V_101 ;
if ( V_24 -> V_70 > 1 && V_24 -> V_24 [ 1 ] == V_102 ) {
V_24 -> V_24 [ 2 ] = V_2 -> V_42 >> 8 ;
V_24 -> V_24 [ 3 ] = V_2 -> V_42 & 0xff ;
}
if ( V_24 -> V_61 )
F_31 ( 2 , L_9 ,
V_24 -> V_70 , V_24 -> V_24 , V_24 -> V_94 , ! V_90 ? L_10 : L_11 ) ;
else
F_31 ( 2 , L_12 ,
V_24 -> V_70 , V_24 -> V_24 , ! V_90 ? L_13 : L_11 ) ;
V_45 -> V_24 = * V_24 ;
V_45 -> V_9 = V_9 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_47 = V_90 ;
if ( V_24 -> V_70 > 1 ) {
if ( ! ( F_25 ( & V_2 -> V_66 ) ) ) {
const struct V_44 * V_103 ;
V_103 = F_44 ( & V_2 -> V_66 ,
const struct V_44 , V_30 ) ;
V_91 = F_39 ( & V_103 -> V_24 ) ;
} else if ( V_2 -> V_50 ) {
V_91 =
F_39 ( & V_2 -> V_50 -> V_24 ) ;
}
}
V_45 -> V_72 = V_91 != F_39 ( V_24 ) ;
F_45 ( & V_45 -> V_49 ) ;
F_46 ( & V_45 -> V_69 , F_36 ) ;
if ( V_9 )
F_12 ( & V_45 -> V_46 , & V_9 -> V_46 ) ;
F_12 ( & V_45 -> V_30 , & V_2 -> V_66 ) ;
V_2 -> V_53 ++ ;
if ( ! V_2 -> V_50 )
F_7 ( & V_2 -> V_63 ) ;
if ( ! V_90 )
return 0 ;
V_61 = V_67 ;
if ( V_24 -> V_61 )
V_61 += V_24 -> V_61 ;
F_6 ( & V_2 -> V_16 ) ;
V_92 = F_47 ( & V_45 -> V_49 ,
F_26 ( V_61 ) ) ;
F_5 ( & V_2 -> V_16 ) ;
if ( V_45 -> V_48 ) {
* V_24 = V_45 -> V_24 ;
F_19 ( V_45 ) ;
return 0 ;
}
V_45 -> V_47 = false ;
if ( V_45 -> V_9 )
F_13 ( & V_45 -> V_46 ) ;
V_45 -> V_9 = NULL ;
if ( V_92 == 0 ) {
if ( V_24 -> V_61 && ( V_24 -> V_51 & V_52 ) )
V_24 -> V_88 = V_89 ;
else
V_24 -> V_51 = V_56 ;
}
return V_92 > 0 ? 0 : V_92 ;
}
int F_48 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_90 )
{
int V_104 ;
F_5 ( & V_2 -> V_16 ) ;
V_104 = F_38 ( V_2 , V_24 , NULL , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_104 ;
}
void F_49 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_44 * V_45 ;
T_1 V_105 = F_39 ( V_24 ) ;
T_1 V_106 = F_40 ( V_24 ) ;
bool V_107 = false ;
bool V_34 = true ;
if ( F_33 ( ! V_24 -> V_70 || V_24 -> V_70 > V_95 ) )
return;
V_24 -> V_87 = F_4 () ;
V_24 -> V_88 = V_108 ;
V_24 -> V_93 = V_24 -> V_94 = V_24 -> V_61 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_26 = 0 ;
memset ( V_24 -> V_24 + V_24 -> V_70 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_70 ) ;
F_5 ( & V_2 -> V_16 ) ;
F_31 ( 2 , L_14 , V_24 -> V_70 , V_24 -> V_24 ) ;
if ( ! F_42 ( V_24 ) )
V_34 = F_41 ( V_2 , V_106 ) ;
if ( V_34 && V_24 -> V_70 > 1 && V_24 -> V_24 [ 1 ] != V_102 ) {
T_1 V_109 = V_24 -> V_24 [ 1 ] ;
bool abort = V_109 == V_110 ;
if ( abort )
V_109 = V_24 -> V_24 [ 2 ] ;
F_9 (data, &adap->wait_queue, list) {
struct V_23 * V_111 = & V_45 -> V_24 ;
if ( ( abort && V_109 != V_111 -> V_24 [ 1 ] ) ||
( ! abort && V_109 != V_111 -> V_94 ) )
continue;
if ( V_105 != F_40 ( V_111 ) &&
! F_42 ( V_111 ) )
continue;
memcpy ( V_111 -> V_24 , V_24 -> V_24 , V_24 -> V_70 ) ;
V_111 -> V_70 = V_24 -> V_70 ;
V_111 -> V_87 = V_24 -> V_87 ;
V_111 -> V_88 = V_24 -> V_88 ;
if ( abort )
V_111 -> V_88 |= V_112 ;
F_21 ( & V_45 -> V_30 ) ;
if ( ! F_29 ( & V_45 -> V_69 ) ) {
F_6 ( & V_2 -> V_16 ) ;
F_30 () ;
F_5 ( & V_2 -> V_16 ) ;
}
if ( V_45 -> V_9 )
V_107 = true ;
F_17 ( V_45 ) ;
break;
}
}
F_6 ( & V_2 -> V_16 ) ;
F_14 ( V_2 , V_24 , V_34 ) ;
if ( ! V_34 || V_24 -> V_70 <= 1 )
return;
if ( V_2 -> V_5 . V_43 == 0 )
return;
F_50 ( V_2 , V_24 , V_107 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_113 ,
unsigned int V_3 )
{
struct V_114 * V_115 = & V_2 -> V_5 ;
struct V_23 V_24 = { } ;
int V_62 ;
if ( F_41 ( V_2 , V_3 ) )
return 0 ;
V_24 . V_70 = 1 ;
V_24 . V_24 [ 0 ] = 0xf0 | V_3 ;
V_62 = F_38 ( V_2 , & V_24 , NULL , true ) ;
if ( ! V_2 -> V_65 )
return - V_116 ;
if ( V_62 )
return V_62 ;
if ( V_24 . V_51 & V_52 )
return 0 ;
V_62 = V_2 -> V_75 -> V_117 ( V_2 , V_3 ) ;
if ( V_62 )
return V_62 ;
V_115 -> V_3 [ V_113 ] = V_3 ;
V_115 -> V_43 |= 1 << V_3 ;
V_2 -> V_118 [ V_3 ] = V_2 -> V_42 ;
F_31 ( 2 , L_15 , V_3 ,
V_115 -> V_7 [ V_113 ] ) ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_75 -> V_117 ( V_2 , V_119 ) ) ;
V_2 -> V_5 . V_43 = 0 ;
V_2 -> V_65 = false ;
V_2 -> V_64 = false ;
memset ( V_2 -> V_118 , 0xff , sizeof( V_2 -> V_118 ) ) ;
F_7 ( & V_2 -> V_63 ) ;
F_16 ( V_2 ) ;
}
static int F_53 ( void * V_120 )
{
static const T_1 V_121 [] = {
V_122 , V_123 ,
V_119
} ;
static const T_1 V_124 [] = {
V_125 , V_126 ,
V_127 ,
V_128 , V_129 ,
V_119
} ;
static const T_1 V_130 [] = {
V_131 , V_132 ,
V_133 , V_134 ,
V_128 , V_129 ,
V_119
} ;
static const T_1 V_135 [] = {
V_136 , V_137 ,
V_138 ,
V_128 , V_129 ,
V_119
} ;
static const T_1 V_139 [] = {
V_140 ,
V_119
} ;
static const T_1 V_141 [] = {
V_123 ,
V_128 , V_129 ,
V_119
} ;
static const T_1 * V_142 [ 6 ] = {
[ V_143 ] = V_121 ,
[ V_144 ] = V_124 ,
[ V_145 ] = V_130 ,
[ V_146 ] = V_135 ,
[ V_147 ] = V_139 ,
[ V_148 ] = V_141 ,
} ;
static const T_4 V_149 [] = {
[ V_143 ] = V_150 ,
[ V_144 ] = V_151 ,
[ V_145 ] = V_152 ,
[ V_146 ] = V_153 ,
[ V_147 ] = V_154 ,
[ V_148 ] = V_155 ,
} ;
struct V_1 * V_2 = V_120 ;
struct V_114 * V_115 = & V_2 -> V_5 ;
int V_62 ;
int V_4 , V_156 ;
F_5 ( & V_2 -> V_16 ) ;
F_31 ( 1 , L_16 ,
F_54 ( V_2 -> V_42 ) , V_115 -> V_6 ) ;
V_115 -> V_43 = 0 ;
if ( V_115 -> V_157 [ 0 ] == V_158 )
goto V_159;
for ( V_4 = 0 ; V_4 < V_115 -> V_6 ; V_4 ++ ) {
unsigned int type = V_115 -> V_157 [ V_4 ] ;
const T_1 * V_160 ;
T_1 V_161 ;
if ( V_2 -> V_42 && type == V_143 )
type = V_148 ;
V_160 = V_142 [ type ] ;
V_161 = V_115 -> V_3 [ V_4 ] ;
V_115 -> V_3 [ V_4 ] = V_119 ;
if ( V_161 == V_119 ||
V_161 == V_162 ||
! ( V_161 & V_149 [ type ] ) )
V_161 = V_160 [ 0 ] ;
V_62 = F_51 ( V_2 , V_4 , V_161 ) ;
if ( V_62 > 0 )
continue;
if ( V_62 < 0 )
goto V_163;
for ( V_156 = 0 ; V_160 [ V_156 ] != V_119 ; V_156 ++ ) {
if ( V_160 [ V_156 ] == V_161 )
continue;
if ( ( V_160 [ V_156 ] == V_128 ||
V_160 [ V_156 ] == V_129 ) &&
V_115 -> V_164 < V_165 )
continue;
V_62 = F_51 ( V_2 , V_4 , V_160 [ V_156 ] ) ;
if ( V_62 == 0 )
continue;
if ( V_62 < 0 )
goto V_163;
break;
}
if ( V_160 [ V_156 ] == V_119 )
F_31 ( 1 , L_17 , V_4 ) ;
}
if ( V_2 -> V_5 . V_43 == 0 &&
! ( V_115 -> V_26 & V_166 ) )
goto V_163;
V_159:
if ( V_2 -> V_5 . V_43 == 0 ) {
V_115 -> V_3 [ 0 ] = V_162 ;
V_115 -> V_43 = 1 << V_115 -> V_3 [ 0 ] ;
for ( V_4 = 1 ; V_4 < V_115 -> V_6 ; V_4 ++ )
V_115 -> V_3 [ V_4 ] = V_119 ;
}
V_2 -> V_64 = true ;
V_2 -> V_65 = false ;
F_16 ( V_2 ) ;
F_6 ( & V_2 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_115 -> V_6 ; V_4 ++ ) {
if ( V_115 -> V_3 [ V_4 ] == V_119 )
continue;
if ( V_115 -> V_3 [ V_4 ] != V_162 )
F_55 ( V_2 , V_4 ) ;
F_56 ( V_2 , V_4 ) ;
}
for ( V_4 = V_115 -> V_6 ; V_4 < V_167 ; V_4 ++ )
V_115 -> V_3 [ V_4 ] = V_119 ;
F_5 ( & V_2 -> V_16 ) ;
V_2 -> V_168 = NULL ;
F_6 ( & V_2 -> V_16 ) ;
F_18 ( & V_2 -> V_169 ) ;
return 0 ;
V_163:
for ( V_4 = 0 ; V_4 < V_115 -> V_6 ; V_4 ++ )
V_115 -> V_3 [ V_4 ] = V_119 ;
F_52 ( V_2 ) ;
V_2 -> V_168 = NULL ;
F_6 ( & V_2 -> V_16 ) ;
F_18 ( & V_2 -> V_169 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , bool V_90 )
{
if ( F_33 ( V_2 -> V_65 || V_2 -> V_64 ) )
return;
F_45 ( & V_2 -> V_169 ) ;
V_2 -> V_65 = true ;
V_2 -> V_168 = F_58 ( F_53 , V_2 ,
L_18 , V_2 -> V_170 ) ;
if ( F_59 ( V_2 -> V_168 ) ) {
V_2 -> V_168 = NULL ;
} else if ( V_90 ) {
F_6 ( & V_2 -> V_16 ) ;
F_60 ( & V_2 -> V_169 ) ;
F_5 ( & V_2 -> V_16 ) ;
}
}
void F_61 ( struct V_1 * V_2 , T_4 V_42 , bool V_90 )
{
if ( V_42 == V_2 -> V_42 || V_2 -> V_22 . V_171 )
return;
if ( V_42 == V_172 ||
V_2 -> V_42 != V_172 ) {
V_2 -> V_42 = V_172 ;
F_16 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_173 )
F_33 ( F_62 ( V_2 , V_174 , false ) ) ;
F_33 ( V_2 -> V_75 -> V_175 ( V_2 , false ) ) ;
if ( V_42 == V_172 )
return;
}
if ( V_2 -> V_75 -> V_175 ( V_2 , true ) )
return;
if ( V_2 -> V_173 &&
F_62 ( V_2 , V_174 , true ) ) {
F_33 ( V_2 -> V_75 -> V_175 ( V_2 , false ) ) ;
return;
}
V_2 -> V_42 = V_42 ;
F_16 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 )
F_57 ( V_2 , V_90 ) ;
}
void F_63 ( struct V_1 * V_2 , T_4 V_42 , bool V_90 )
{
if ( F_64 ( V_2 ) )
return;
F_5 ( & V_2 -> V_16 ) ;
F_61 ( V_2 , V_42 , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_114 * V_5 , bool V_90 )
{
T_4 V_176 = 0 ;
int V_4 ;
if ( V_2 -> V_22 . V_171 )
return - V_177 ;
if ( ! V_5 || V_5 -> V_6 == 0 ) {
V_2 -> V_5 . V_6 = 0 ;
F_52 ( V_2 ) ;
return 0 ;
}
V_5 -> V_178 [ sizeof( V_5 -> V_178 ) - 1 ] = '\0' ;
if ( V_5 -> V_6 > V_2 -> V_179 ) {
F_31 ( 1 , L_19 , V_2 -> V_179 ) ;
return - V_96 ;
}
if ( V_5 -> V_180 != V_181 &&
( V_5 -> V_180 & 0xff000000 ) != 0 )
return - V_96 ;
if ( V_5 -> V_164 != V_182 &&
V_5 -> V_164 != V_165 )
return - V_96 ;
if ( V_5 -> V_6 > 1 )
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ )
if ( V_5 -> V_157 [ V_4 ] ==
V_158 ) {
F_31 ( 1 , L_20 ) ;
return - V_96 ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
const T_1 V_183 = F_66 ( V_5 -> V_184 [ 0 ] ) ;
T_1 * V_184 = V_5 -> V_184 [ V_4 ] ;
bool V_185 = false ;
V_5 -> V_3 [ V_4 ] = V_119 ;
if ( V_176 & ( 1 << V_5 -> V_157 [ V_4 ] ) ) {
F_31 ( 1 , L_21 ) ;
return - V_96 ;
}
V_176 |= 1 << V_5 -> V_157 [ V_4 ] ;
if ( ( V_176 & ( 1 << V_144 ) ) &&
( V_176 & ( 1 << V_146 ) ) ) {
F_31 ( 1 , L_22 ) ;
return - V_96 ;
}
if ( V_5 -> V_7 [ V_4 ] >
V_186 ) {
F_31 ( 1 , L_23 ) ;
return - V_96 ;
}
if ( V_5 -> V_7 [ V_4 ] == 2 ) {
F_31 ( 1 , L_24 ) ;
return - V_96 ;
}
if ( V_5 -> V_157 [ V_4 ] > V_158 ) {
F_31 ( 1 , L_25 ) ;
return - V_96 ;
}
for ( V_4 = 0 ; V_4 < V_183 ; V_4 ++ ) {
if ( ( V_184 [ V_4 ] & 0x80 ) == 0 ) {
if ( V_185 )
break;
V_185 = true ;
}
}
if ( ! V_185 || V_4 == V_183 ) {
F_31 ( 1 , L_26 ) ;
return - V_96 ;
}
memset ( V_184 + V_4 + 1 , 0 , V_183 - V_4 - 1 ) ;
}
if ( V_5 -> V_164 >= V_165 ) {
if ( V_5 -> V_6 > 2 ) {
F_31 ( 1 , L_27 ) ;
return - V_96 ;
}
if ( V_5 -> V_6 == 2 ) {
if ( ! ( V_176 & ( ( 1 << V_147 ) |
( 1 << V_143 ) ) ) ) {
F_31 ( 1 , L_28 ) ;
return - V_96 ;
}
if ( ! ( V_176 & ( ( 1 << V_146 ) |
( 1 << V_144 ) ) ) ) {
F_31 ( 1 , L_29 ) ;
return - V_96 ;
}
}
}
for ( V_4 = V_5 -> V_6 ; V_4 < V_167 ; V_4 ++ ) {
V_5 -> V_7 [ V_4 ] = 0 ;
V_5 -> V_157 [ V_4 ] = 0 ;
V_5 -> V_187 [ V_4 ] = 0 ;
memset ( V_5 -> V_184 [ V_4 ] , 0 ,
sizeof( V_5 -> V_184 [ V_4 ] ) ) ;
}
V_5 -> V_43 = V_2 -> V_5 . V_43 ;
V_2 -> V_5 = * V_5 ;
if ( V_2 -> V_42 != V_172 )
F_57 ( V_2 , V_90 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_114 * V_5 , bool V_90 )
{
int V_62 ;
F_5 ( & V_2 -> V_16 ) ;
V_62 = F_65 ( V_2 , V_5 , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_62 ;
}
static int F_55 ( struct V_1 * V_2 , unsigned int V_188 )
{
struct V_23 V_24 = { } ;
const struct V_114 * V_115 = & V_2 -> V_5 ;
const T_1 * V_184 = V_115 -> V_184 [ V_188 ] ;
bool V_185 = false ;
unsigned int V_113 ;
if ( V_2 -> V_5 . V_164 < V_165 )
return 0 ;
V_24 . V_24 [ 0 ] = ( V_115 -> V_3 [ V_188 ] << 4 ) | 0x0f ;
V_24 . V_70 = 4 ;
V_24 . V_24 [ 1 ] = V_189 ;
V_24 . V_24 [ 2 ] = V_2 -> V_5 . V_164 ;
V_24 . V_24 [ 3 ] = V_115 -> V_187 [ V_188 ] ;
for ( V_113 = 0 ; V_113 < F_66 ( V_115 -> V_184 [ 0 ] ) ; V_113 ++ ) {
V_24 . V_24 [ V_24 . V_70 ++ ] = V_184 [ V_113 ] ;
if ( ( V_184 [ V_113 ] & V_190 ) == 0 ) {
if ( V_185 )
break;
V_185 = true ;
}
}
return F_48 ( V_2 , & V_24 , false ) ;
}
static int F_56 ( struct V_1 * V_2 , unsigned int V_188 )
{
const struct V_114 * V_115 = & V_2 -> V_5 ;
struct V_23 V_24 = { } ;
V_24 . V_24 [ 0 ] = ( V_115 -> V_3 [ V_188 ] << 4 ) | 0x0f ;
F_68 ( & V_24 , V_2 -> V_42 ,
V_115 -> V_7 [ V_188 ] ) ;
F_31 ( 2 , L_30 ,
V_115 -> V_3 [ V_188 ] ,
F_54 ( V_2 -> V_42 ) ) ;
return F_48 ( V_2 , & V_24 , false ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_1 V_191 )
{
struct V_23 V_192 = { } ;
if ( V_24 -> V_24 [ 1 ] == V_110 )
return 0 ;
F_70 ( & V_192 , V_24 ) ;
F_71 ( & V_192 , V_24 -> V_24 [ 1 ] , V_191 ) ;
return F_48 ( V_2 , & V_192 , false ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_69 ( V_2 , V_24 ,
V_193 ) ;
}
static int F_73 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_69 ( V_2 , V_24 ,
V_194 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_107 )
{
bool V_195 = F_42 ( V_24 ) ;
T_1 V_196 = F_40 ( V_24 ) ;
T_1 V_197 = F_39 ( V_24 ) ;
T_1 V_198 = F_2 ( V_2 , V_196 ) ;
int V_188 = F_1 ( V_2 , V_196 ) ;
bool V_199 = V_197 == 0xf ;
struct V_23 V_200 = { } ;
F_31 ( 1 , L_31 , V_24 -> V_70 , V_24 -> V_24 ) ;
if ( V_2 -> V_75 -> V_201 ) {
if ( V_2 -> V_75 -> V_201 ( V_2 , V_24 ) != - V_202 )
return 0 ;
}
switch ( V_24 -> V_24 [ 1 ] ) {
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
if ( V_2 -> V_210 )
goto V_211;
if ( V_195 || V_199 )
return 0 ;
break;
case V_212 :
case V_213 :
if ( V_195 || V_199 )
goto V_211;
break;
case V_214 :
if ( ! V_195 )
goto V_211;
break;
default:
break;
}
F_70 ( & V_200 , V_24 ) ;
switch ( V_24 -> V_24 [ 1 ] ) {
case V_214 : {
T_4 V_215 = ( V_24 -> V_24 [ 2 ] << 8 ) | V_24 -> V_24 [ 3 ] ;
if ( ! V_199 )
V_2 -> V_118 [ V_197 ] = V_215 ;
F_31 ( 1 , L_32 ,
F_54 ( V_215 ) , V_197 ) ;
break;
}
case V_212 :
if ( ! ( V_2 -> V_216 & V_217 ) )
break;
#if F_74 ( V_218 )
switch ( V_24 -> V_24 [ 2 ] ) {
case 0x60 :
if ( V_24 -> V_70 == 2 )
F_75 ( V_2 -> V_219 , V_220 ,
V_24 -> V_24 [ 2 ] , 0 ) ;
else
F_75 ( V_2 -> V_219 , V_220 ,
V_24 -> V_24 [ 2 ] << 8 | V_24 -> V_24 [ 3 ] , 0 ) ;
break;
case 0x56 : case 0x57 :
case 0x67 : case 0x68 : case 0x69 : case 0x6a :
break;
default:
F_75 ( V_2 -> V_219 , V_220 , V_24 -> V_24 [ 2 ] , 0 ) ;
break;
}
#endif
break;
case V_213 :
if ( ! ( V_2 -> V_216 & V_217 ) )
break;
#if F_74 ( V_218 )
F_76 ( V_2 -> V_219 ) ;
#endif
break;
case V_203 :
F_77 ( & V_200 , V_2 -> V_5 . V_164 ) ;
return F_48 ( V_2 , & V_200 , false ) ;
case V_207 :
if ( V_198 == V_221 && V_196 == 15 )
return 0 ;
F_68 ( & V_200 , V_2 -> V_42 , V_198 ) ;
return F_48 ( V_2 , & V_200 , false ) ;
case V_204 :
if ( V_2 -> V_5 . V_180 == V_181 )
return F_72 ( V_2 , V_24 ) ;
F_78 ( & V_200 , V_2 -> V_5 . V_180 ) ;
return F_48 ( V_2 , & V_200 , false ) ;
case V_205 :
if ( V_198 == V_221 )
return 0 ;
return F_73 ( V_2 , V_24 ) ;
case V_208 : {
if ( V_2 -> V_5 . V_178 [ 0 ] == 0 )
return F_72 ( V_2 , V_24 ) ;
F_79 ( & V_200 , V_2 -> V_5 . V_178 ) ;
return F_48 ( V_2 , & V_200 , false ) ;
}
case V_209 :
if ( V_2 -> V_5 . V_164 >= V_165 )
return F_55 ( V_2 , V_188 ) ;
return 0 ;
default:
if ( ! V_195 && ! V_107 && ! V_2 -> V_222 &&
! V_2 -> V_223 && V_24 -> V_24 [ 1 ] != V_110 )
return F_72 ( V_2 , V_24 ) ;
break;
}
V_211:
if ( V_107 )
return 0 ;
if ( V_2 -> V_223 )
F_10 ( V_2 -> V_223 , V_24 ) ;
else
F_15 ( V_2 , V_24 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_104 = 0 ;
if ( V_2 -> V_173 == 0 )
V_104 = F_62 ( V_2 , V_174 , 1 ) ;
if ( V_104 == 0 )
V_2 -> V_173 ++ ;
return V_104 ;
}
void F_81 ( struct V_1 * V_2 )
{
V_2 -> V_173 -- ;
if ( V_2 -> V_173 == 0 )
F_33 ( F_62 ( V_2 , V_174 , 0 ) ) ;
}
int F_82 ( struct V_224 * V_225 , void * V_226 )
{
struct V_1 * V_2 = F_83 ( V_225 -> V_227 ) ;
struct V_44 * V_45 ;
F_5 ( & V_2 -> V_16 ) ;
F_84 ( V_225 , L_33 , V_2 -> V_64 ) ;
F_84 ( V_225 , L_34 , V_2 -> V_65 ) ;
F_84 ( V_225 , L_35 ,
F_54 ( V_2 -> V_42 ) ) ;
F_84 ( V_225 , L_36 , V_2 -> V_5 . V_6 ) ;
F_84 ( V_225 , L_37 , V_2 -> V_5 . V_43 ) ;
if ( V_2 -> V_223 )
F_84 ( V_225 , L_38 ,
V_2 -> V_210 ? L_39 : L_11 ) ;
if ( V_2 -> V_228 )
F_85 ( V_225 , L_40 ) ;
if ( V_2 -> V_173 )
F_84 ( V_225 , L_41 ,
V_2 -> V_173 ) ;
V_45 = V_2 -> V_50 ;
if ( V_45 )
F_84 ( V_225 , L_42 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
F_84 ( V_225 , L_43 , V_2 -> V_53 ) ;
F_9 (data, &adap->transmit_queue, list) {
F_84 ( V_225 , L_44 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
}
F_9 (data, &adap->wait_queue, list) {
F_84 ( V_225 , L_45 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
}
F_86 ( V_2 , V_229 , V_225 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
}
