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
V_45 -> V_24 . V_51 |= V_55 |
V_56 ;
V_45 -> V_24 . V_57 ++ ;
V_45 -> V_58 = 0 ;
F_14 ( V_45 -> V_2 , & V_45 -> V_24 , 1 ) ;
F_17 ( V_45 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_44 * V_45 , * V_59 ;
while ( ! F_23 ( & V_2 -> V_60 ) ) {
V_45 = F_24 ( & V_2 -> V_60 ,
struct V_44 , V_30 ) ;
F_20 ( V_45 ) ;
}
if ( V_2 -> V_50 )
F_20 ( V_2 -> V_50 ) ;
F_25 (data, n, &adap->wait_queue, list) {
if ( F_26 ( & V_45 -> V_61 ) )
F_20 ( V_45 ) ;
}
}
int F_27 ( void * V_62 )
{
struct V_1 * V_2 = V_62 ;
for (; ; ) {
unsigned int V_63 ;
struct V_44 * V_45 ;
bool V_64 = false ;
T_1 V_58 ;
if ( V_2 -> V_50 ) {
int V_65 ;
V_65 = F_28 ( V_2 -> V_66 ,
F_29 () ||
( ! V_2 -> V_50 &&
! F_23 ( & V_2 -> V_60 ) ) ,
F_30 ( V_67 ) ) ;
V_64 = V_65 == 0 ;
} else {
F_31 ( V_2 -> V_66 ,
F_29 () ||
( ! V_2 -> V_50 &&
! F_23 ( & V_2 -> V_60 ) ) ) ;
}
F_5 ( & V_2 -> V_16 ) ;
if ( F_29 () ) {
F_22 ( V_2 ) ;
goto V_20;
}
if ( V_2 -> V_50 && V_64 ) {
F_32 ( 0 , L_1 ,
V_2 -> V_50 -> V_24 . V_68 ,
V_2 -> V_50 -> V_24 . V_24 ) ;
F_20 ( V_2 -> V_50 ) ;
goto V_20;
}
if ( V_2 -> V_50 || F_23 ( & V_2 -> V_60 ) )
goto V_20;
V_45 = F_24 ( & V_2 -> V_60 ,
struct V_44 , V_30 ) ;
F_21 ( & V_45 -> V_30 ) ;
V_2 -> V_53 -- ;
V_2 -> V_50 = V_45 ;
if ( V_45 -> V_24 . V_68 == 1 && V_2 -> V_69 )
V_58 = 2 ;
else
V_58 = 4 ;
if ( V_45 -> V_58 ) {
V_63 = V_70 ;
} else if ( V_45 -> V_71 ) {
V_63 = V_72 ;
} else {
V_63 = V_73 ;
}
if ( V_45 -> V_58 == 0 )
V_45 -> V_58 = V_58 ;
if ( V_2 -> V_74 -> V_75 ( V_2 , V_45 -> V_58 ,
V_63 , & V_45 -> V_24 ) )
F_20 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
if ( F_29 () )
break;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_76 , T_1 V_77 ,
T_1 V_78 , T_1 V_79 , T_1 V_80 )
{
struct V_44 * V_45 ;
struct V_23 * V_24 ;
T_2 V_12 = F_4 () ;
F_32 ( 2 , L_2 , V_76 ) ;
F_5 ( & V_2 -> V_16 ) ;
V_45 = V_2 -> V_50 ;
if ( ! V_45 ) {
F_32 ( 1 , L_3 ) ;
goto V_20;
}
V_24 = & V_45 -> V_24 ;
F_34 ( V_76 == 0 ) ;
V_24 -> V_54 = V_12 ;
V_24 -> V_51 |= V_76 ;
V_24 -> V_81 += V_77 ;
V_24 -> V_82 += V_78 ;
V_24 -> V_83 += V_79 ;
V_24 -> V_57 += V_80 ;
V_2 -> V_50 = NULL ;
if ( V_45 -> V_58 > 1 &&
! ( V_76 & ( V_56 | V_52 ) ) ) {
V_45 -> V_58 -- ;
F_35 ( & V_45 -> V_30 , & V_2 -> V_60 ) ;
V_2 -> V_53 ++ ;
goto V_84;
}
V_45 -> V_58 = 0 ;
if ( ! ( V_76 & V_52 ) )
V_24 -> V_51 |= V_56 ;
F_14 ( V_2 , V_24 , 1 ) ;
if ( ( V_76 & V_52 ) && V_2 -> V_69 &&
V_24 -> V_64 ) {
F_12 ( & V_45 -> V_30 , & V_2 -> V_85 ) ;
F_36 ( & V_45 -> V_61 ,
F_30 ( V_24 -> V_64 ) ) ;
} else {
F_17 ( V_45 ) ;
}
V_84:
F_7 ( & V_2 -> V_66 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
static void F_37 ( struct V_86 * V_61 )
{
struct V_44 * V_45 = F_38 ( V_61 , struct V_44 , V_61 . V_61 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
F_5 ( & V_2 -> V_16 ) ;
if ( F_23 ( & V_45 -> V_30 ) )
goto V_20;
F_21 ( & V_45 -> V_30 ) ;
V_45 -> V_24 . V_87 = F_4 () ;
V_45 -> V_24 . V_88 = V_89 ;
F_17 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_8 * V_9 , bool V_90 )
{
struct V_44 * V_45 ;
T_1 V_91 = 0xff ;
unsigned int V_64 ;
int V_92 = 0 ;
V_24 -> V_87 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_88 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_81 = 0 ;
V_24 -> V_82 = 0 ;
V_24 -> V_83 = 0 ;
V_24 -> V_57 = 0 ;
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( ! V_24 -> V_93 )
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( V_24 -> V_94 && V_24 -> V_64 == 0 ) {
V_24 -> V_64 = 1000 ;
}
if ( V_24 -> V_64 )
V_24 -> V_26 &= V_95 ;
else
V_24 -> V_26 = 0 ;
if ( V_24 -> V_68 == 0 || V_24 -> V_68 > V_96 ) {
F_32 ( 1 , L_4 , V_97 , V_24 -> V_68 ) ;
return - V_98 ;
}
if ( V_24 -> V_64 && V_24 -> V_68 == 1 ) {
F_32 ( 1 , L_5 , V_97 ) ;
return - V_98 ;
}
memset ( V_24 -> V_24 + V_24 -> V_68 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_68 ) ;
if ( V_24 -> V_68 == 1 ) {
if ( F_40 ( V_24 ) == 0xf ) {
F_32 ( 1 , L_6 , V_97 ) ;
return - V_98 ;
}
if ( F_41 ( V_2 , F_40 ( V_24 ) ) ) {
V_24 -> V_54 = F_4 () ;
V_24 -> V_51 = V_99 |
V_56 ;
V_24 -> V_82 = 1 ;
return 0 ;
}
}
if ( V_24 -> V_68 > 1 && ! F_42 ( V_24 ) &&
F_41 ( V_2 , F_40 ( V_24 ) ) ) {
F_32 ( 1 , L_7 , V_97 ) ;
return - V_98 ;
}
if ( V_24 -> V_68 > 1 && V_2 -> V_69 &&
! F_41 ( V_2 , F_43 ( V_24 ) ) ) {
F_32 ( 1 , L_8 ,
V_97 , F_43 ( V_24 ) ) ;
return - V_98 ;
}
if ( ! V_2 -> V_69 && ! V_2 -> V_100 ) {
if ( V_24 -> V_24 [ 0 ] != 0xf0 ) {
F_32 ( 1 , L_9 , V_97 ) ;
return - V_101 ;
}
if ( V_24 -> V_94 ) {
F_32 ( 1 , L_10 , V_97 ) ;
return - V_98 ;
}
}
if ( V_2 -> V_53 >= V_102 ) {
F_32 ( 1 , L_11 , V_97 ) ;
return - V_103 ;
}
V_45 = F_44 ( sizeof( * V_45 ) , V_29 ) ;
if ( ! V_45 )
return - V_104 ;
if ( V_24 -> V_68 > 1 && V_24 -> V_24 [ 1 ] == V_105 ) {
V_24 -> V_24 [ 2 ] = V_2 -> V_42 >> 8 ;
V_24 -> V_24 [ 3 ] = V_2 -> V_42 & 0xff ;
}
if ( V_24 -> V_64 )
F_32 ( 2 , L_12 ,
V_97 , V_24 -> V_68 , V_24 -> V_24 , V_24 -> V_94 , ! V_90 ? L_13 : L_14 ) ;
else
F_32 ( 2 , L_15 ,
V_97 , V_24 -> V_68 , V_24 -> V_24 , ! V_90 ? L_16 : L_14 ) ;
V_45 -> V_24 = * V_24 ;
V_45 -> V_9 = V_9 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_47 = V_90 ;
if ( V_24 -> V_68 > 1 ) {
if ( ! ( F_23 ( & V_2 -> V_60 ) ) ) {
const struct V_44 * V_106 ;
V_106 = F_45 ( & V_2 -> V_60 ,
const struct V_44 , V_30 ) ;
V_91 = F_43 ( & V_106 -> V_24 ) ;
} else if ( V_2 -> V_50 ) {
V_91 =
F_43 ( & V_2 -> V_50 -> V_24 ) ;
}
}
V_45 -> V_71 = V_91 != F_43 ( V_24 ) ;
F_46 ( & V_45 -> V_49 ) ;
F_47 ( & V_45 -> V_61 , F_37 ) ;
if ( V_9 )
F_12 ( & V_45 -> V_46 , & V_9 -> V_46 ) ;
F_12 ( & V_45 -> V_30 , & V_2 -> V_60 ) ;
V_2 -> V_53 ++ ;
if ( ! V_2 -> V_50 )
F_7 ( & V_2 -> V_66 ) ;
if ( ! V_90 )
return 0 ;
V_64 = V_67 ;
if ( V_24 -> V_64 )
V_64 += V_24 -> V_64 ;
F_6 ( & V_2 -> V_16 ) ;
V_92 = F_48 ( & V_45 -> V_49 ,
F_30 ( V_64 ) ) ;
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
if ( V_24 -> V_64 && ( V_24 -> V_51 & V_52 ) )
V_24 -> V_88 = V_89 ;
else
V_24 -> V_51 = V_56 ;
}
return V_92 > 0 ? 0 : V_92 ;
}
int F_49 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_90 )
{
int V_107 ;
F_5 ( & V_2 -> V_16 ) ;
V_107 = F_39 ( V_2 , V_24 , NULL , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_107 ;
}
void F_50 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_44 * V_45 ;
T_1 V_108 = F_43 ( V_24 ) ;
T_1 V_109 = F_40 ( V_24 ) ;
T_1 V_110 = V_24 -> V_24 [ 1 ] ;
bool V_111 = false ;
bool V_34 = true ;
T_1 V_112 = 0 ;
if ( F_34 ( ! V_24 -> V_68 || V_24 -> V_68 > V_96 ) )
return;
if ( V_108 != V_113 &&
F_41 ( V_2 , V_108 ) )
return;
V_24 -> V_87 = F_4 () ;
V_24 -> V_88 = V_114 ;
V_24 -> V_93 = V_24 -> V_94 = V_24 -> V_64 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_81 = 0 ;
V_24 -> V_82 = 0 ;
V_24 -> V_83 = 0 ;
V_24 -> V_57 = 0 ;
V_24 -> V_26 = 0 ;
memset ( V_24 -> V_24 + V_24 -> V_68 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_68 ) ;
F_5 ( & V_2 -> V_16 ) ;
F_32 ( 2 , L_17 , V_24 -> V_68 , V_24 -> V_24 ) ;
if ( ! F_42 ( V_24 ) )
V_34 = F_41 ( V_2 , V_109 ) ;
if ( V_34 && V_24 -> V_68 > 1 && V_115 [ V_110 ] ) {
T_1 V_116 = V_115 [ V_110 ] & V_117 ;
V_112 = V_115 [ V_110 ] & 0x1f ;
if ( V_24 -> V_68 < V_112 )
V_34 = false ;
else if ( ! F_42 ( V_24 ) && ! ( V_116 & V_118 ) )
V_34 = false ;
else if ( F_42 ( V_24 ) && ! ( V_116 & V_119 ) )
V_34 = false ;
else if ( F_42 ( V_24 ) &&
V_2 -> V_5 . V_120 >= V_121 &&
! ( V_116 & V_122 ) )
V_34 = false ;
}
if ( V_34 && V_112 ) {
switch ( V_110 ) {
case V_123 :
if ( V_24 -> V_24 [ 2 ] & 0x10 ) {
switch ( V_24 -> V_24 [ 2 ] & 0xf ) {
case V_124 :
case V_125 :
if ( V_24 -> V_68 < 5 )
V_34 = false ;
break;
}
} else if ( ( V_24 -> V_24 [ 2 ] & 0xf ) == V_126 ) {
if ( V_24 -> V_68 < 5 )
V_34 = false ;
}
break;
case V_127 :
switch ( V_24 -> V_24 [ 2 ] ) {
case V_128 :
break;
case V_129 :
if ( V_24 -> V_68 < 10 )
V_34 = false ;
break;
case V_130 :
if ( V_24 -> V_68 < 7 )
V_34 = false ;
break;
case V_131 :
if ( V_24 -> V_68 < 4 )
V_34 = false ;
break;
case V_132 :
if ( V_24 -> V_68 < 5 )
V_34 = false ;
break;
}
break;
}
}
if ( V_34 && V_24 -> V_68 > 1 && V_110 != V_105 ) {
bool abort = V_110 == V_133 ;
if ( abort )
V_110 = V_24 -> V_24 [ 2 ] ;
F_9 (data, &adap->wait_queue, list) {
struct V_23 * V_134 = & V_45 -> V_24 ;
if ( ! abort && V_134 -> V_24 [ 1 ] == V_135 &&
( V_110 == V_136 ||
V_110 == V_137 ) &&
( V_134 -> V_94 == V_136 ||
V_134 -> V_94 == V_137 ) )
V_134 -> V_94 = V_110 ;
if ( ( abort && V_110 != V_134 -> V_24 [ 1 ] ) ||
( ! abort && V_110 != V_134 -> V_94 ) )
continue;
if ( V_108 != F_40 ( V_134 ) &&
! F_42 ( V_134 ) )
continue;
memcpy ( V_134 -> V_24 , V_24 -> V_24 , V_24 -> V_68 ) ;
V_134 -> V_68 = V_24 -> V_68 ;
V_134 -> V_87 = V_24 -> V_87 ;
V_134 -> V_88 = V_24 -> V_88 ;
if ( abort )
V_134 -> V_88 |= V_138 ;
V_24 -> V_26 = V_134 -> V_26 ;
F_21 ( & V_45 -> V_30 ) ;
if ( ! F_26 ( & V_45 -> V_61 ) ) {
F_6 ( & V_2 -> V_16 ) ;
F_51 () ;
F_5 ( & V_2 -> V_16 ) ;
}
if ( V_45 -> V_9 )
V_111 = true ;
F_17 ( V_45 ) ;
break;
}
}
F_6 ( & V_2 -> V_16 ) ;
F_14 ( V_2 , V_24 , V_34 ) ;
if ( ! V_34 || V_24 -> V_68 <= 1 )
return;
if ( V_2 -> V_5 . V_43 == 0 )
return;
F_52 ( V_2 , V_24 , V_111 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
unsigned int V_139 ,
unsigned int V_3 )
{
struct V_140 * V_141 = & V_2 -> V_5 ;
struct V_23 V_24 = { } ;
int V_65 ;
if ( F_41 ( V_2 , V_3 ) )
return 0 ;
V_24 . V_68 = 1 ;
V_24 . V_24 [ 0 ] = ( V_3 << 4 ) | V_3 ;
V_65 = F_39 ( V_2 , & V_24 , NULL , true ) ;
if ( ! V_2 -> V_100 )
return - V_142 ;
if ( V_65 )
return V_65 ;
if ( V_24 . V_51 & V_52 )
return 0 ;
V_65 = V_2 -> V_74 -> V_143 ( V_2 , V_3 ) ;
if ( V_65 )
return V_65 ;
V_141 -> V_3 [ V_139 ] = V_3 ;
V_141 -> V_43 |= 1 << V_3 ;
V_2 -> V_144 [ V_3 ] = V_2 -> V_42 ;
F_32 ( 2 , L_18 , V_3 ,
V_141 -> V_7 [ V_139 ] ) ;
return 1 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_34 ( V_2 -> V_74 -> V_143 ( V_2 , V_145 ) ) ;
V_2 -> V_5 . V_43 = 0 ;
V_2 -> V_100 = false ;
V_2 -> V_69 = false ;
memset ( V_2 -> V_144 , 0xff , sizeof( V_2 -> V_144 ) ) ;
F_22 ( V_2 ) ;
F_7 ( & V_2 -> V_66 ) ;
F_16 ( V_2 ) ;
}
static int F_55 ( void * V_146 )
{
static const T_1 V_147 [] = {
V_148 , V_149 ,
V_145
} ;
static const T_1 V_150 [] = {
V_151 , V_152 ,
V_153 ,
V_154 , V_155 ,
V_145
} ;
static const T_1 V_156 [] = {
V_157 , V_158 ,
V_159 , V_160 ,
V_154 , V_155 ,
V_145
} ;
static const T_1 V_161 [] = {
V_162 , V_163 ,
V_164 ,
V_154 , V_155 ,
V_145
} ;
static const T_1 V_165 [] = {
V_166 ,
V_145
} ;
static const T_1 V_167 [] = {
V_149 ,
V_154 , V_155 ,
V_145
} ;
static const T_1 * V_168 [ 6 ] = {
[ V_169 ] = V_147 ,
[ V_170 ] = V_150 ,
[ V_171 ] = V_156 ,
[ V_172 ] = V_161 ,
[ V_173 ] = V_165 ,
[ V_174 ] = V_167 ,
} ;
static const T_4 V_175 [] = {
[ V_169 ] = V_176 ,
[ V_170 ] = V_177 ,
[ V_171 ] = V_178 ,
[ V_172 ] = V_179 ,
[ V_173 ] = V_180 ,
[ V_174 ] = V_181 ,
} ;
struct V_1 * V_2 = V_146 ;
struct V_140 * V_141 = & V_2 -> V_5 ;
int V_65 ;
int V_4 , V_182 ;
F_5 ( & V_2 -> V_16 ) ;
F_32 ( 1 , L_19 ,
F_56 ( V_2 -> V_42 ) , V_141 -> V_6 ) ;
V_141 -> V_43 = 0 ;
if ( V_141 -> V_183 [ 0 ] == V_184 )
goto V_185;
for ( V_4 = 0 ; V_4 < V_141 -> V_6 ; V_4 ++ ) {
unsigned int type = V_141 -> V_183 [ V_4 ] ;
const T_1 * V_186 ;
T_1 V_187 ;
if ( V_2 -> V_42 && type == V_169 )
type = V_174 ;
V_186 = V_168 [ type ] ;
V_187 = V_141 -> V_3 [ V_4 ] ;
V_141 -> V_3 [ V_4 ] = V_145 ;
if ( V_187 == V_145 ||
V_187 == V_113 ||
! ( ( 1 << V_187 ) & V_175 [ type ] ) )
V_187 = V_186 [ 0 ] ;
V_65 = F_53 ( V_2 , V_4 , V_187 ) ;
if ( V_65 > 0 )
continue;
if ( V_65 < 0 )
goto V_188;
for ( V_182 = 0 ; V_186 [ V_182 ] != V_145 ; V_182 ++ ) {
if ( V_186 [ V_182 ] == V_187 )
continue;
if ( ( V_186 [ V_182 ] == V_154 ||
V_186 [ V_182 ] == V_155 ) &&
V_141 -> V_120 < V_121 )
continue;
V_65 = F_53 ( V_2 , V_4 , V_186 [ V_182 ] ) ;
if ( V_65 == 0 )
continue;
if ( V_65 < 0 )
goto V_188;
break;
}
if ( V_186 [ V_182 ] == V_145 )
F_32 ( 1 , L_20 , V_4 ) ;
}
if ( V_2 -> V_5 . V_43 == 0 &&
! ( V_141 -> V_26 & V_189 ) )
goto V_188;
V_185:
if ( V_2 -> V_5 . V_43 == 0 ) {
V_141 -> V_3 [ 0 ] = V_113 ;
V_141 -> V_43 = 1 << V_141 -> V_3 [ 0 ] ;
for ( V_4 = 1 ; V_4 < V_141 -> V_6 ; V_4 ++ )
V_141 -> V_3 [ V_4 ] = V_145 ;
}
for ( V_4 = V_141 -> V_6 ; V_4 < V_190 ; V_4 ++ )
V_141 -> V_3 [ V_4 ] = V_145 ;
V_2 -> V_69 = true ;
V_2 -> V_100 = false ;
F_16 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_141 -> V_6 ; V_4 ++ ) {
struct V_23 V_24 = {} ;
if ( V_141 -> V_3 [ V_4 ] == V_145 ||
( V_141 -> V_26 & V_191 ) )
continue;
V_24 . V_24 [ 0 ] = ( V_141 -> V_3 [ V_4 ] << 4 ) | 0x0f ;
if ( V_141 -> V_3 [ V_4 ] != V_113 &&
V_2 -> V_5 . V_120 >= V_121 ) {
F_57 ( V_2 , & V_24 , V_4 ) ;
F_39 ( V_2 , & V_24 , NULL , false ) ;
}
F_58 ( & V_24 , V_2 -> V_42 ,
V_141 -> V_7 [ V_4 ] ) ;
F_32 ( 2 , L_21 ,
V_141 -> V_3 [ V_4 ] ,
F_56 ( V_2 -> V_42 ) ) ;
F_39 ( V_2 , & V_24 , NULL , false ) ;
}
V_2 -> V_192 = NULL ;
F_18 ( & V_2 -> V_193 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
V_188:
for ( V_4 = 0 ; V_4 < V_141 -> V_6 ; V_4 ++ )
V_141 -> V_3 [ V_4 ] = V_145 ;
F_54 ( V_2 ) ;
V_2 -> V_192 = NULL ;
F_6 ( & V_2 -> V_16 ) ;
F_18 ( & V_2 -> V_193 ) ;
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , bool V_90 )
{
if ( F_34 ( V_2 -> V_100 || V_2 -> V_69 ) )
return;
F_46 ( & V_2 -> V_193 ) ;
V_2 -> V_100 = true ;
V_2 -> V_192 = F_60 ( F_55 , V_2 ,
L_22 , V_2 -> V_194 ) ;
if ( F_61 ( V_2 -> V_192 ) ) {
V_2 -> V_192 = NULL ;
} else if ( V_90 ) {
F_6 ( & V_2 -> V_16 ) ;
F_62 ( & V_2 -> V_193 ) ;
F_5 ( & V_2 -> V_16 ) ;
}
}
void F_63 ( struct V_1 * V_2 , T_4 V_42 , bool V_90 )
{
if ( V_42 == V_2 -> V_42 || V_2 -> V_22 . V_195 )
return;
if ( V_42 == V_196 ||
V_2 -> V_42 != V_196 ) {
V_2 -> V_42 = V_196 ;
F_16 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_197 )
F_34 ( F_64 ( V_2 , V_198 , false ) ) ;
F_5 ( & V_2 -> V_22 . V_16 ) ;
if ( F_23 ( & V_2 -> V_22 . V_199 ) )
F_34 ( V_2 -> V_74 -> V_200 ( V_2 , false ) ) ;
F_6 ( & V_2 -> V_22 . V_16 ) ;
if ( V_42 == V_196 )
return;
}
F_5 ( & V_2 -> V_22 . V_16 ) ;
if ( F_23 ( & V_2 -> V_22 . V_199 ) &&
V_2 -> V_74 -> V_200 ( V_2 , true ) ) {
F_6 ( & V_2 -> V_22 . V_16 ) ;
return;
}
if ( V_2 -> V_197 &&
F_64 ( V_2 , V_198 , true ) ) {
if ( F_23 ( & V_2 -> V_22 . V_199 ) )
F_34 ( V_2 -> V_74 -> V_200 ( V_2 , false ) ) ;
F_6 ( & V_2 -> V_22 . V_16 ) ;
return;
}
F_6 ( & V_2 -> V_22 . V_16 ) ;
V_2 -> V_42 = V_42 ;
F_16 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 )
F_59 ( V_2 , V_90 ) ;
}
void F_65 ( struct V_1 * V_2 , T_4 V_42 , bool V_90 )
{
if ( F_66 ( V_2 ) )
return;
F_5 ( & V_2 -> V_16 ) ;
F_63 ( V_2 , V_42 , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_140 * V_5 , bool V_90 )
{
T_4 V_201 = 0 ;
int V_4 ;
if ( V_2 -> V_22 . V_195 )
return - V_202 ;
if ( ! V_5 || V_5 -> V_6 == 0 ) {
V_2 -> V_5 . V_6 = 0 ;
F_54 ( V_2 ) ;
return 0 ;
}
if ( V_5 -> V_26 & V_191 ) {
V_5 -> V_6 = 1 ;
V_5 -> V_203 [ 0 ] = '\0' ;
V_5 -> V_204 = V_205 ;
V_5 -> V_183 [ 0 ] = V_184 ;
V_5 -> V_7 [ 0 ] = V_206 ;
V_5 -> V_207 [ 0 ] = 0 ;
V_5 -> V_208 [ 0 ] [ 0 ] = 0 ;
V_5 -> V_208 [ 0 ] [ 1 ] = 0 ;
}
V_5 -> V_203 [ sizeof( V_5 -> V_203 ) - 1 ] = '\0' ;
if ( V_5 -> V_6 > V_2 -> V_209 ) {
F_32 ( 1 , L_23 , V_2 -> V_209 ) ;
return - V_98 ;
}
if ( V_5 -> V_204 != V_205 &&
( V_5 -> V_204 & 0xff000000 ) != 0 ) {
F_32 ( 1 , L_24 ) ;
return - V_98 ;
}
if ( V_5 -> V_120 != V_210 &&
V_5 -> V_120 != V_121 ) {
F_32 ( 1 , L_25 ) ;
return - V_98 ;
}
if ( V_5 -> V_6 > 1 )
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ )
if ( V_5 -> V_183 [ V_4 ] ==
V_184 ) {
F_32 ( 1 , L_26 ) ;
return - V_98 ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
const T_1 V_211 = F_68 ( V_5 -> V_208 [ 0 ] ) ;
T_1 * V_208 = V_5 -> V_208 [ V_4 ] ;
bool V_212 = false ;
unsigned V_182 ;
V_5 -> V_3 [ V_4 ] = V_145 ;
if ( V_201 & ( 1 << V_5 -> V_183 [ V_4 ] ) ) {
F_32 ( 1 , L_27 ) ;
return - V_98 ;
}
V_201 |= 1 << V_5 -> V_183 [ V_4 ] ;
if ( ( V_201 & ( 1 << V_170 ) ) &&
( V_201 & ( 1 << V_172 ) ) ) {
F_32 ( 1 , L_28 ) ;
return - V_98 ;
}
if ( V_5 -> V_7 [ V_4 ] >
V_213 ) {
F_32 ( 1 , L_29 ) ;
return - V_98 ;
}
if ( V_5 -> V_7 [ V_4 ] == 2 ) {
F_32 ( 1 , L_30 ) ;
return - V_98 ;
}
if ( V_5 -> V_183 [ V_4 ] > V_184 ) {
F_32 ( 1 , L_31 ) ;
return - V_98 ;
}
for ( V_182 = 0 ; V_182 < V_211 ; V_182 ++ ) {
if ( ( V_208 [ V_182 ] & 0x80 ) == 0 ) {
if ( V_212 )
break;
V_212 = true ;
}
}
if ( ! V_212 || V_182 == V_211 ) {
F_32 ( 1 , L_32 ) ;
return - V_98 ;
}
memset ( V_208 + V_182 + 1 , 0 , V_211 - V_182 - 1 ) ;
}
if ( V_5 -> V_120 >= V_121 ) {
if ( V_5 -> V_6 > 2 ) {
F_32 ( 1 , L_33 ) ;
return - V_98 ;
}
if ( V_5 -> V_6 == 2 ) {
if ( ! ( V_201 & ( ( 1 << V_173 ) |
( 1 << V_169 ) ) ) ) {
F_32 ( 1 , L_34 ) ;
return - V_98 ;
}
if ( ! ( V_201 & ( ( 1 << V_172 ) |
( 1 << V_170 ) ) ) ) {
F_32 ( 1 , L_35 ) ;
return - V_98 ;
}
}
}
for ( V_4 = V_5 -> V_6 ; V_4 < V_190 ; V_4 ++ ) {
V_5 -> V_7 [ V_4 ] = 0 ;
V_5 -> V_183 [ V_4 ] = 0 ;
V_5 -> V_207 [ V_4 ] = 0 ;
memset ( V_5 -> V_208 [ V_4 ] , 0 ,
sizeof( V_5 -> V_208 [ V_4 ] ) ) ;
}
V_5 -> V_43 = V_2 -> V_5 . V_43 ;
V_2 -> V_5 = * V_5 ;
if ( V_2 -> V_42 != V_196 )
F_59 ( V_2 , V_90 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_140 * V_5 , bool V_90 )
{
int V_65 ;
F_5 ( & V_2 -> V_16 ) ;
V_65 = F_67 ( V_2 , V_5 , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_65 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned int V_214 )
{
const struct V_140 * V_141 = & V_2 -> V_5 ;
const T_1 * V_208 = V_141 -> V_208 [ V_214 ] ;
bool V_212 = false ;
unsigned int V_139 ;
V_24 -> V_24 [ 0 ] = ( V_141 -> V_3 [ V_214 ] << 4 ) | 0x0f ;
V_24 -> V_68 = 4 ;
V_24 -> V_24 [ 1 ] = V_215 ;
V_24 -> V_24 [ 2 ] = V_2 -> V_5 . V_120 ;
V_24 -> V_24 [ 3 ] = V_141 -> V_207 [ V_214 ] ;
for ( V_139 = 0 ; V_139 < F_68 ( V_141 -> V_208 [ 0 ] ) ; V_139 ++ ) {
V_24 -> V_24 [ V_24 -> V_68 ++ ] = V_208 [ V_139 ] ;
if ( ( V_208 [ V_139 ] & V_216 ) == 0 ) {
if ( V_212 )
break;
V_212 = true ;
}
}
}
static int F_70 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_1 V_217 )
{
struct V_23 V_218 = { } ;
if ( V_24 -> V_24 [ 1 ] == V_133 )
return 0 ;
if ( F_43 ( V_24 ) == V_113 )
return 0 ;
F_71 ( & V_218 , V_24 ) ;
F_72 ( & V_218 , V_24 -> V_24 [ 1 ] , V_217 ) ;
return F_49 ( V_2 , & V_218 , false ) ;
}
static int F_73 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_70 ( V_2 , V_24 ,
V_219 ) ;
}
static int F_74 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_70 ( V_2 , V_24 ,
V_220 ) ;
}
static int F_52 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_111 )
{
bool V_221 = F_42 ( V_24 ) ;
T_1 V_222 = F_40 ( V_24 ) ;
T_1 V_223 = F_43 ( V_24 ) ;
T_1 V_224 = F_2 ( V_2 , V_222 ) ;
int V_214 = F_1 ( V_2 , V_222 ) ;
bool V_225 = V_223 == 0xf ;
struct V_23 V_226 = { } ;
F_32 ( 1 , L_36 , V_24 -> V_68 , V_24 -> V_24 ) ;
if ( F_75 ( & V_2 -> V_5 ) &&
V_24 -> V_24 [ 1 ] != V_105 )
return 0 ;
if ( V_2 -> V_74 -> V_227 ) {
if ( V_2 -> V_74 -> V_227 ( V_2 , V_24 ) != - V_228 )
return 0 ;
}
switch ( V_24 -> V_24 [ 1 ] ) {
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
if ( V_2 -> V_236 )
goto V_237;
if ( V_221 || V_225 )
return 0 ;
break;
case V_238 :
case V_239 :
if ( V_221 || V_225 )
goto V_237;
break;
case V_240 :
if ( ! V_221 )
goto V_237;
break;
default:
break;
}
F_71 ( & V_226 , V_24 ) ;
switch ( V_24 -> V_24 [ 1 ] ) {
case V_240 : {
T_4 V_241 = ( V_24 -> V_24 [ 2 ] << 8 ) | V_24 -> V_24 [ 3 ] ;
if ( ! V_225 )
V_2 -> V_144 [ V_223 ] = V_241 ;
F_32 ( 1 , L_37 ,
F_56 ( V_241 ) , V_223 ) ;
break;
}
case V_238 :
if ( ! ( V_2 -> V_242 & V_243 ) ||
! ( V_2 -> V_5 . V_26 & V_244 ) )
break;
#ifdef F_76
switch ( V_24 -> V_24 [ 2 ] ) {
case 0x60 :
if ( V_24 -> V_68 == 2 )
F_77 ( V_2 -> V_245 , V_246 ,
V_24 -> V_24 [ 2 ] , 0 ) ;
else
F_77 ( V_2 -> V_245 , V_246 ,
V_24 -> V_24 [ 2 ] << 8 | V_24 -> V_24 [ 3 ] , 0 ) ;
break;
case 0x56 : case 0x57 :
case 0x67 : case 0x68 : case 0x69 : case 0x6a :
break;
default:
F_77 ( V_2 -> V_245 , V_246 , V_24 -> V_24 [ 2 ] , 0 ) ;
break;
}
#endif
break;
case V_239 :
if ( ! ( V_2 -> V_242 & V_243 ) ||
! ( V_2 -> V_5 . V_26 & V_244 ) )
break;
#ifdef F_76
F_78 ( V_2 -> V_245 ) ;
#endif
break;
case V_229 :
F_79 ( & V_226 , V_2 -> V_5 . V_120 ) ;
return F_49 ( V_2 , & V_226 , false ) ;
case V_233 :
if ( V_224 == V_206 && V_222 == 15 )
return 0 ;
F_58 ( & V_226 , V_2 -> V_42 , V_224 ) ;
return F_49 ( V_2 , & V_226 , false ) ;
case V_230 :
if ( V_2 -> V_5 . V_204 == V_205 )
return F_73 ( V_2 , V_24 ) ;
F_80 ( & V_226 , V_2 -> V_5 . V_204 ) ;
return F_49 ( V_2 , & V_226 , false ) ;
case V_231 :
if ( V_224 == V_206 )
return 0 ;
return F_74 ( V_2 , V_24 ) ;
case V_234 : {
if ( V_2 -> V_5 . V_203 [ 0 ] == 0 )
return F_73 ( V_2 , V_24 ) ;
F_81 ( & V_226 , V_2 -> V_5 . V_203 ) ;
return F_49 ( V_2 , & V_226 , false ) ;
}
case V_235 :
if ( V_2 -> V_5 . V_120 < V_121 )
return F_73 ( V_2 , V_24 ) ;
F_57 ( V_2 , & V_226 , V_214 ) ;
return F_49 ( V_2 , & V_226 , false ) ;
default:
if ( ! V_221 && ! V_111 && ! V_2 -> V_247 &&
! V_2 -> V_248 && V_24 -> V_24 [ 1 ] != V_133 )
return F_73 ( V_2 , V_24 ) ;
break;
}
V_237:
if ( V_111 && ! ( V_24 -> V_26 & V_95 ) )
return 0 ;
if ( V_2 -> V_248 )
F_10 ( V_2 -> V_248 , V_24 ) ;
else
F_15 ( V_2 , V_24 ) ;
return 0 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_107 = 0 ;
if ( V_2 -> V_197 == 0 )
V_107 = F_64 ( V_2 , V_198 , 1 ) ;
if ( V_107 == 0 )
V_2 -> V_197 ++ ;
return V_107 ;
}
void F_83 ( struct V_1 * V_2 )
{
V_2 -> V_197 -- ;
if ( V_2 -> V_197 == 0 )
F_34 ( F_64 ( V_2 , V_198 , 0 ) ) ;
}
int F_84 ( struct V_249 * V_250 , void * V_251 )
{
struct V_1 * V_2 = F_85 ( V_250 -> V_252 ) ;
struct V_44 * V_45 ;
F_5 ( & V_2 -> V_16 ) ;
F_86 ( V_250 , L_38 , V_2 -> V_69 ) ;
F_86 ( V_250 , L_39 , V_2 -> V_100 ) ;
F_86 ( V_250 , L_40 ,
F_56 ( V_2 -> V_42 ) ) ;
F_86 ( V_250 , L_41 , V_2 -> V_5 . V_6 ) ;
F_86 ( V_250 , L_42 , V_2 -> V_5 . V_43 ) ;
if ( V_2 -> V_248 )
F_86 ( V_250 , L_43 ,
V_2 -> V_236 ? L_44 : L_14 ) ;
if ( V_2 -> V_253 )
F_87 ( V_250 , L_45 ) ;
if ( V_2 -> V_197 )
F_86 ( V_250 , L_46 ,
V_2 -> V_197 ) ;
V_45 = V_2 -> V_50 ;
if ( V_45 )
F_86 ( V_250 , L_47 ,
V_45 -> V_24 . V_68 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_64 ) ;
F_86 ( V_250 , L_48 , V_2 -> V_53 ) ;
F_9 (data, &adap->transmit_queue, list) {
F_86 ( V_250 , L_49 ,
V_45 -> V_24 . V_68 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_64 ) ;
}
F_9 (data, &adap->wait_queue, list) {
F_86 ( V_250 , L_50 ,
V_45 -> V_24 . V_68 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_64 ) ;
}
F_88 ( V_2 , V_254 , V_250 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
}
