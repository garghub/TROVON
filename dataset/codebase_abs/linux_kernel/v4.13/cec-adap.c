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
( V_2 -> V_67 &&
( ! V_2 -> V_68 && ! V_2 -> V_69 ) ) ||
F_29 () ||
( ! V_2 -> V_50 &&
! F_23 ( & V_2 -> V_60 ) ) ,
F_30 ( V_70 ) ) ;
V_64 = V_65 == 0 ;
} else {
F_31 ( V_2 -> V_66 ,
F_29 () ||
( ! V_2 -> V_50 &&
! F_23 ( & V_2 -> V_60 ) ) ) ;
}
F_5 ( & V_2 -> V_16 ) ;
if ( ( V_2 -> V_67 &&
( ! V_2 -> V_68 && ! V_2 -> V_69 ) ) ||
F_29 () ) {
F_22 ( V_2 ) ;
goto V_20;
}
if ( V_2 -> V_50 && V_64 ) {
F_32 ( 0 , L_1 , V_71 ,
V_2 -> V_50 -> V_24 . V_72 ,
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
if ( V_45 -> V_24 . V_72 == 1 && V_2 -> V_68 )
V_58 = 2 ;
else
V_58 = 4 ;
if ( V_45 -> V_58 ) {
V_63 = V_73 ;
} else if ( V_45 -> V_74 ) {
V_63 = V_75 ;
} else {
V_63 = V_76 ;
}
if ( V_45 -> V_58 == 0 )
V_45 -> V_58 = V_58 ;
if ( V_2 -> V_77 -> V_78 ( V_2 , V_45 -> V_58 ,
V_63 , & V_45 -> V_24 ) )
F_20 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
if ( F_29 () )
break;
}
return 0 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_79 , T_1 V_80 ,
T_1 V_81 , T_1 V_82 , T_1 V_83 )
{
struct V_44 * V_45 ;
struct V_23 * V_24 ;
T_2 V_12 = F_4 () ;
F_32 ( 2 , L_2 , V_71 , V_79 ) ;
F_5 ( & V_2 -> V_16 ) ;
V_45 = V_2 -> V_50 ;
if ( ! V_45 ) {
F_32 ( 1 , L_3 ,
V_71 ) ;
goto V_20;
}
V_24 = & V_45 -> V_24 ;
F_34 ( V_79 == 0 ) ;
V_24 -> V_54 = V_12 ;
V_24 -> V_51 |= V_79 ;
V_24 -> V_84 += V_80 ;
V_24 -> V_85 += V_81 ;
V_24 -> V_86 += V_82 ;
V_24 -> V_57 += V_83 ;
V_2 -> V_50 = NULL ;
if ( V_45 -> V_58 > 1 &&
! ( V_79 & ( V_56 | V_52 ) ) ) {
V_45 -> V_58 -- ;
if ( V_24 -> V_64 )
F_32 ( 2 , L_4 ,
V_24 -> V_72 , V_24 -> V_24 , V_45 -> V_58 , V_24 -> V_87 ) ;
else
F_32 ( 2 , L_5 ,
V_24 -> V_72 , V_24 -> V_24 , V_45 -> V_58 ) ;
F_35 ( & V_45 -> V_30 , & V_2 -> V_60 ) ;
V_2 -> V_53 ++ ;
goto V_88;
}
V_45 -> V_58 = 0 ;
if ( ! ( V_79 & V_52 ) )
V_24 -> V_51 |= V_56 ;
F_14 ( V_2 , V_24 , 1 ) ;
if ( ( V_79 & V_52 ) && V_2 -> V_68 &&
V_24 -> V_64 ) {
F_12 ( & V_45 -> V_30 , & V_2 -> V_89 ) ;
F_36 ( & V_45 -> V_61 ,
F_30 ( V_24 -> V_64 ) ) ;
} else {
F_17 ( V_45 ) ;
}
V_88:
F_7 ( & V_2 -> V_66 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_79 )
{
switch ( V_79 & ~ V_56 ) {
case V_52 :
F_33 ( V_2 , V_79 , 0 , 0 , 0 , 0 ) ;
return;
case V_90 :
F_33 ( V_2 , V_79 , 1 , 0 , 0 , 0 ) ;
return;
case V_91 :
F_33 ( V_2 , V_79 , 0 , 1 , 0 , 0 ) ;
return;
case V_92 :
F_33 ( V_2 , V_79 , 0 , 0 , 1 , 0 ) ;
return;
case V_55 :
F_33 ( V_2 , V_79 , 0 , 0 , 0 , 1 ) ;
return;
default:
F_38 ( 1 , L_6 , V_2 -> V_93 , V_79 ) ;
return;
}
}
static void F_39 ( struct V_94 * V_61 )
{
struct V_44 * V_45 = F_40 ( V_61 , struct V_44 , V_61 . V_61 ) ;
struct V_1 * V_2 = V_45 -> V_2 ;
F_5 ( & V_2 -> V_16 ) ;
if ( F_23 ( & V_45 -> V_30 ) )
goto V_20;
F_21 ( & V_45 -> V_30 ) ;
V_45 -> V_24 . V_95 = F_4 () ;
V_45 -> V_24 . V_96 = V_97 ;
F_17 ( V_45 ) ;
V_20:
F_6 ( & V_2 -> V_16 ) ;
}
int F_41 ( struct V_1 * V_2 , struct V_23 * V_24 ,
struct V_8 * V_9 , bool V_98 )
{
struct V_44 * V_45 ;
T_1 V_99 = 0xff ;
unsigned int V_64 ;
int V_100 = 0 ;
V_24 -> V_95 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_96 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_84 = 0 ;
V_24 -> V_85 = 0 ;
V_24 -> V_86 = 0 ;
V_24 -> V_57 = 0 ;
V_24 -> V_101 = ++ V_2 -> V_101 ;
if ( ! V_24 -> V_101 )
V_24 -> V_101 = ++ V_2 -> V_101 ;
if ( V_24 -> V_87 && V_24 -> V_64 == 0 ) {
V_24 -> V_64 = 1000 ;
}
if ( V_24 -> V_64 )
V_24 -> V_26 &= V_102 ;
else
V_24 -> V_26 = 0 ;
if ( V_24 -> V_72 == 0 || V_24 -> V_72 > V_103 ) {
F_32 ( 1 , L_7 , V_71 , V_24 -> V_72 ) ;
return - V_104 ;
}
if ( V_24 -> V_64 && V_24 -> V_72 == 1 ) {
F_32 ( 1 , L_8 , V_71 ) ;
return - V_104 ;
}
memset ( V_24 -> V_24 + V_24 -> V_72 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_72 ) ;
if ( V_24 -> V_72 == 1 ) {
if ( F_42 ( V_24 ) == 0xf ) {
F_32 ( 1 , L_9 , V_71 ) ;
return - V_104 ;
}
if ( F_43 ( V_2 , F_42 ( V_24 ) ) ) {
V_24 -> V_54 = F_4 () ;
V_24 -> V_51 = V_91 |
V_56 ;
V_24 -> V_85 = 1 ;
return 0 ;
}
}
if ( V_24 -> V_72 > 1 && ! F_44 ( V_24 ) &&
F_43 ( V_2 , F_42 ( V_24 ) ) ) {
F_32 ( 1 , L_10 , V_71 ) ;
return - V_104 ;
}
if ( V_24 -> V_72 > 1 && V_2 -> V_68 &&
! F_43 ( V_2 , F_45 ( V_24 ) ) ) {
F_32 ( 1 , L_11 ,
V_71 , F_45 ( V_24 ) ) ;
return - V_104 ;
}
if ( ! V_2 -> V_68 && ! V_2 -> V_69 ) {
if ( V_2 -> V_67 || V_24 -> V_24 [ 0 ] != 0xf0 ) {
F_32 ( 1 , L_12 , V_71 ) ;
return - V_105 ;
}
if ( V_24 -> V_87 ) {
F_32 ( 1 , L_13 , V_71 ) ;
return - V_104 ;
}
}
if ( V_2 -> V_53 >= V_106 ) {
F_32 ( 1 , L_14 , V_71 ) ;
return - V_107 ;
}
V_45 = F_46 ( sizeof( * V_45 ) , V_29 ) ;
if ( ! V_45 )
return - V_108 ;
if ( V_24 -> V_72 > 1 && V_24 -> V_24 [ 1 ] == V_109 ) {
V_24 -> V_24 [ 2 ] = V_2 -> V_42 >> 8 ;
V_24 -> V_24 [ 3 ] = V_2 -> V_42 & 0xff ;
}
if ( V_24 -> V_64 )
F_32 ( 2 , L_15 ,
V_71 , V_24 -> V_72 , V_24 -> V_24 , V_24 -> V_87 , ! V_98 ? L_16 : L_17 ) ;
else
F_32 ( 2 , L_18 ,
V_71 , V_24 -> V_72 , V_24 -> V_24 , ! V_98 ? L_19 : L_17 ) ;
V_45 -> V_24 = * V_24 ;
V_45 -> V_9 = V_9 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_47 = V_98 ;
if ( V_24 -> V_72 > 1 ) {
if ( ! ( F_23 ( & V_2 -> V_60 ) ) ) {
const struct V_44 * V_110 ;
V_110 = F_47 ( & V_2 -> V_60 ,
const struct V_44 , V_30 ) ;
V_99 = F_45 ( & V_110 -> V_24 ) ;
} else if ( V_2 -> V_50 ) {
V_99 =
F_45 ( & V_2 -> V_50 -> V_24 ) ;
}
}
V_45 -> V_74 = V_99 != F_45 ( V_24 ) ;
F_48 ( & V_45 -> V_49 ) ;
F_49 ( & V_45 -> V_61 , F_39 ) ;
if ( V_9 )
F_12 ( & V_45 -> V_46 , & V_9 -> V_46 ) ;
F_12 ( & V_45 -> V_30 , & V_2 -> V_60 ) ;
V_2 -> V_53 ++ ;
if ( ! V_2 -> V_50 )
F_7 ( & V_2 -> V_66 ) ;
if ( ! V_98 )
return 0 ;
V_64 = V_70 ;
if ( V_24 -> V_64 )
V_64 += V_24 -> V_64 ;
F_6 ( & V_2 -> V_16 ) ;
V_100 = F_50 ( & V_45 -> V_49 ,
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
if ( V_100 == 0 ) {
if ( V_24 -> V_64 && ( V_24 -> V_51 & V_52 ) )
V_24 -> V_96 = V_97 ;
else
V_24 -> V_51 = V_56 ;
}
return V_100 > 0 ? 0 : V_100 ;
}
int F_51 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_98 )
{
int V_111 ;
F_5 ( & V_2 -> V_16 ) ;
V_111 = F_41 ( V_2 , V_24 , NULL , V_98 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_111 ;
}
void F_52 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_44 * V_45 ;
T_1 V_112 = F_45 ( V_24 ) ;
T_1 V_113 = F_42 ( V_24 ) ;
T_1 V_114 = V_24 -> V_24 [ 1 ] ;
bool V_115 = false ;
bool V_34 = true ;
T_1 V_116 = 0 ;
if ( F_34 ( ! V_24 -> V_72 || V_24 -> V_72 > V_103 ) )
return;
if ( V_112 != V_117 &&
F_43 ( V_2 , V_112 ) )
return;
V_24 -> V_95 = F_4 () ;
V_24 -> V_96 = V_118 ;
V_24 -> V_101 = V_24 -> V_87 = V_24 -> V_64 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_84 = 0 ;
V_24 -> V_85 = 0 ;
V_24 -> V_86 = 0 ;
V_24 -> V_57 = 0 ;
V_24 -> V_26 = 0 ;
memset ( V_24 -> V_24 + V_24 -> V_72 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_72 ) ;
F_5 ( & V_2 -> V_16 ) ;
F_32 ( 2 , L_20 , V_71 , V_24 -> V_72 , V_24 -> V_24 ) ;
if ( ! F_44 ( V_24 ) )
V_34 = F_43 ( V_2 , V_113 ) ;
if ( V_34 && V_24 -> V_72 > 1 && V_119 [ V_114 ] ) {
T_1 V_120 = V_119 [ V_114 ] & V_121 ;
V_116 = V_119 [ V_114 ] & 0x1f ;
if ( V_24 -> V_72 < V_116 )
V_34 = false ;
else if ( ! F_44 ( V_24 ) && ! ( V_120 & V_122 ) )
V_34 = false ;
else if ( F_44 ( V_24 ) && ! ( V_120 & V_123 ) )
V_34 = false ;
else if ( F_44 ( V_24 ) &&
V_2 -> V_5 . V_124 >= V_125 &&
! ( V_120 & V_126 ) )
V_34 = false ;
}
if ( V_34 && V_116 ) {
switch ( V_114 ) {
case V_127 :
if ( V_24 -> V_24 [ 2 ] & 0x10 ) {
switch ( V_24 -> V_24 [ 2 ] & 0xf ) {
case V_128 :
case V_129 :
if ( V_24 -> V_72 < 5 )
V_34 = false ;
break;
}
} else if ( ( V_24 -> V_24 [ 2 ] & 0xf ) == V_130 ) {
if ( V_24 -> V_72 < 5 )
V_34 = false ;
}
break;
case V_131 :
switch ( V_24 -> V_24 [ 2 ] ) {
case V_132 :
break;
case V_133 :
if ( V_24 -> V_72 < 10 )
V_34 = false ;
break;
case V_134 :
if ( V_24 -> V_72 < 7 )
V_34 = false ;
break;
case V_135 :
if ( V_24 -> V_72 < 4 )
V_34 = false ;
break;
case V_136 :
if ( V_24 -> V_72 < 5 )
V_34 = false ;
break;
}
break;
}
}
if ( V_34 && V_24 -> V_72 > 1 && V_114 != V_109 ) {
bool abort = V_114 == V_137 ;
if ( abort )
V_114 = V_24 -> V_24 [ 2 ] ;
F_9 (data, &adap->wait_queue, list) {
struct V_23 * V_138 = & V_45 -> V_24 ;
if ( ! abort && V_138 -> V_24 [ 1 ] == V_139 &&
( V_114 == V_140 ||
V_114 == V_141 ) &&
( V_138 -> V_87 == V_140 ||
V_138 -> V_87 == V_141 ) )
V_138 -> V_87 = V_114 ;
if ( ( abort && V_114 != V_138 -> V_24 [ 1 ] ) ||
( ! abort && V_114 != V_138 -> V_87 ) )
continue;
if ( V_112 != F_42 ( V_138 ) &&
! F_44 ( V_138 ) )
continue;
memcpy ( V_138 -> V_24 , V_24 -> V_24 , V_24 -> V_72 ) ;
V_138 -> V_72 = V_24 -> V_72 ;
V_138 -> V_95 = V_24 -> V_95 ;
V_138 -> V_96 = V_24 -> V_96 ;
if ( abort )
V_138 -> V_96 |= V_142 ;
V_24 -> V_26 = V_138 -> V_26 ;
F_21 ( & V_45 -> V_30 ) ;
if ( ! F_26 ( & V_45 -> V_61 ) ) {
F_6 ( & V_2 -> V_16 ) ;
F_53 () ;
F_5 ( & V_2 -> V_16 ) ;
}
if ( V_45 -> V_9 )
V_115 = true ;
F_17 ( V_45 ) ;
break;
}
}
F_6 ( & V_2 -> V_16 ) ;
F_14 ( V_2 , V_24 , V_34 ) ;
if ( ! V_34 || V_24 -> V_72 <= 1 )
return;
if ( V_2 -> V_5 . V_43 == 0 )
return;
F_54 ( V_2 , V_24 , V_115 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
unsigned int V_143 ,
unsigned int V_3 )
{
struct V_144 * V_145 = & V_2 -> V_5 ;
struct V_23 V_24 = { } ;
int V_65 ;
if ( F_43 ( V_2 , V_3 ) )
return 0 ;
V_24 . V_72 = 1 ;
V_24 . V_24 [ 0 ] = ( V_3 << 4 ) | V_3 ;
V_65 = F_41 ( V_2 , & V_24 , NULL , true ) ;
if ( ! V_2 -> V_69 )
return - V_146 ;
if ( V_65 )
return V_65 ;
if ( V_24 . V_51 & V_52 )
return 0 ;
V_65 = V_2 -> V_77 -> V_147 ( V_2 , V_3 ) ;
if ( V_65 )
return V_65 ;
V_145 -> V_3 [ V_143 ] = V_3 ;
V_145 -> V_43 |= 1 << V_3 ;
V_2 -> V_148 [ V_3 ] = V_2 -> V_42 ;
return 1 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_67 ||
V_2 -> V_42 != V_149 )
F_34 ( V_2 -> V_77 -> V_147 ( V_2 , V_150 ) ) ;
V_2 -> V_5 . V_43 = 0 ;
V_2 -> V_69 = false ;
V_2 -> V_68 = false ;
memset ( V_2 -> V_148 , 0xff , sizeof( V_2 -> V_148 ) ) ;
F_22 ( V_2 ) ;
F_7 ( & V_2 -> V_66 ) ;
F_16 ( V_2 ) ;
}
static int F_57 ( void * V_151 )
{
static const T_1 V_152 [] = {
V_153 , V_154 ,
V_150
} ;
static const T_1 V_155 [] = {
V_156 , V_157 ,
V_158 ,
V_159 , V_160 ,
V_150
} ;
static const T_1 V_161 [] = {
V_162 , V_163 ,
V_164 , V_165 ,
V_159 , V_160 ,
V_150
} ;
static const T_1 V_166 [] = {
V_167 , V_168 ,
V_169 ,
V_159 , V_160 ,
V_150
} ;
static const T_1 V_170 [] = {
V_171 ,
V_150
} ;
static const T_1 V_172 [] = {
V_154 ,
V_159 , V_160 ,
V_150
} ;
static const T_1 * V_173 [ 6 ] = {
[ V_174 ] = V_152 ,
[ V_175 ] = V_155 ,
[ V_176 ] = V_161 ,
[ V_177 ] = V_166 ,
[ V_178 ] = V_170 ,
[ V_179 ] = V_172 ,
} ;
static const T_4 V_180 [] = {
[ V_174 ] = V_181 ,
[ V_175 ] = V_182 ,
[ V_176 ] = V_183 ,
[ V_177 ] = V_184 ,
[ V_178 ] = V_185 ,
[ V_179 ] = V_186 ,
} ;
struct V_1 * V_2 = V_151 ;
struct V_144 * V_145 = & V_2 -> V_5 ;
int V_65 ;
int V_4 , V_187 ;
F_5 ( & V_2 -> V_16 ) ;
F_32 ( 1 , L_21 ,
F_58 ( V_2 -> V_42 ) , V_145 -> V_6 ) ;
V_145 -> V_43 = 0 ;
if ( V_145 -> V_188 [ 0 ] == V_189 )
goto V_190;
for ( V_4 = 0 ; V_4 < V_145 -> V_6 ; V_4 ++ ) {
unsigned int type = V_145 -> V_188 [ V_4 ] ;
const T_1 * V_191 ;
T_1 V_192 ;
if ( V_2 -> V_42 && type == V_174 )
type = V_179 ;
V_191 = V_173 [ type ] ;
V_192 = V_145 -> V_3 [ V_4 ] ;
V_145 -> V_3 [ V_4 ] = V_150 ;
if ( V_192 == V_150 ||
V_192 == V_117 ||
! ( ( 1 << V_192 ) & V_180 [ type ] ) )
V_192 = V_191 [ 0 ] ;
V_65 = F_55 ( V_2 , V_4 , V_192 ) ;
if ( V_65 > 0 )
continue;
if ( V_65 < 0 )
goto V_193;
for ( V_187 = 0 ; V_191 [ V_187 ] != V_150 ; V_187 ++ ) {
if ( V_191 [ V_187 ] == V_192 )
continue;
if ( ( V_191 [ V_187 ] == V_159 ||
V_191 [ V_187 ] == V_160 ) &&
V_145 -> V_124 < V_125 )
continue;
V_65 = F_55 ( V_2 , V_4 , V_191 [ V_187 ] ) ;
if ( V_65 == 0 )
continue;
if ( V_65 < 0 )
goto V_193;
break;
}
if ( V_191 [ V_187 ] == V_150 )
F_32 ( 1 , L_22 , V_4 ) ;
}
if ( V_2 -> V_5 . V_43 == 0 &&
! ( V_145 -> V_26 & V_194 ) )
goto V_193;
V_190:
if ( V_2 -> V_5 . V_43 == 0 ) {
V_145 -> V_3 [ 0 ] = V_117 ;
V_145 -> V_43 = 1 << V_145 -> V_3 [ 0 ] ;
for ( V_4 = 1 ; V_4 < V_145 -> V_6 ; V_4 ++ )
V_145 -> V_3 [ V_4 ] = V_150 ;
}
for ( V_4 = V_145 -> V_6 ; V_4 < V_195 ; V_4 ++ )
V_145 -> V_3 [ V_4 ] = V_150 ;
V_2 -> V_68 = true ;
V_2 -> V_69 = false ;
F_16 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_145 -> V_6 ; V_4 ++ ) {
struct V_23 V_24 = {} ;
if ( V_145 -> V_3 [ V_4 ] == V_150 ||
( V_145 -> V_26 & V_196 ) )
continue;
V_24 . V_24 [ 0 ] = ( V_145 -> V_3 [ V_4 ] << 4 ) | 0x0f ;
if ( V_145 -> V_3 [ V_4 ] != V_117 &&
V_2 -> V_5 . V_124 >= V_125 ) {
F_59 ( V_2 , & V_24 , V_4 ) ;
F_41 ( V_2 , & V_24 , NULL , false ) ;
}
F_60 ( & V_24 , V_2 -> V_42 ,
V_145 -> V_7 [ V_4 ] ) ;
F_32 ( 1 , L_23 ,
V_145 -> V_3 [ V_4 ] ,
F_58 ( V_2 -> V_42 ) ) ;
F_41 ( V_2 , & V_24 , NULL , false ) ;
}
V_2 -> V_197 = NULL ;
F_18 ( & V_2 -> V_198 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
V_193:
for ( V_4 = 0 ; V_4 < V_145 -> V_6 ; V_4 ++ )
V_145 -> V_3 [ V_4 ] = V_150 ;
F_56 ( V_2 ) ;
V_2 -> V_197 = NULL ;
F_6 ( & V_2 -> V_16 ) ;
F_18 ( & V_2 -> V_198 ) ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 , bool V_98 )
{
if ( F_34 ( V_2 -> V_69 || V_2 -> V_68 ) )
return;
F_48 ( & V_2 -> V_198 ) ;
V_2 -> V_69 = true ;
V_2 -> V_197 = F_62 ( F_57 , V_2 ,
L_24 , V_2 -> V_93 ) ;
if ( F_63 ( V_2 -> V_197 ) ) {
V_2 -> V_197 = NULL ;
} else if ( V_98 ) {
F_6 ( & V_2 -> V_16 ) ;
F_64 ( & V_2 -> V_198 ) ;
F_5 ( & V_2 -> V_16 ) ;
}
}
void F_65 ( struct V_1 * V_2 , T_4 V_42 , bool V_98 )
{
if ( V_42 == V_2 -> V_42 || V_2 -> V_22 . V_199 )
return;
F_32 ( 1 , L_25 ,
F_58 ( V_42 ) ) ;
if ( V_42 == V_149 ||
V_2 -> V_42 != V_149 ) {
V_2 -> V_42 = V_149 ;
F_16 ( V_2 ) ;
F_56 ( V_2 ) ;
if ( V_2 -> V_200 )
F_34 ( F_66 ( V_2 , V_201 , false ) ) ;
F_5 ( & V_2 -> V_22 . V_16 ) ;
if ( V_2 -> V_67 || F_23 ( & V_2 -> V_22 . V_202 ) )
F_34 ( V_2 -> V_77 -> V_203 ( V_2 , false ) ) ;
F_6 ( & V_2 -> V_22 . V_16 ) ;
if ( V_42 == V_149 )
return;
}
F_5 ( & V_2 -> V_22 . V_16 ) ;
if ( ( V_2 -> V_67 || F_23 ( & V_2 -> V_22 . V_202 ) ) &&
V_2 -> V_77 -> V_203 ( V_2 , true ) ) {
F_6 ( & V_2 -> V_22 . V_16 ) ;
return;
}
if ( V_2 -> V_200 &&
F_66 ( V_2 , V_201 , true ) ) {
if ( V_2 -> V_67 || F_23 ( & V_2 -> V_22 . V_202 ) )
F_34 ( V_2 -> V_77 -> V_203 ( V_2 , false ) ) ;
F_6 ( & V_2 -> V_22 . V_16 ) ;
return;
}
F_6 ( & V_2 -> V_22 . V_16 ) ;
V_2 -> V_42 = V_42 ;
F_16 ( V_2 ) ;
if ( V_2 -> V_5 . V_6 )
F_61 ( V_2 , V_98 ) ;
}
void F_67 ( struct V_1 * V_2 , T_4 V_42 , bool V_98 )
{
if ( F_68 ( V_2 ) )
return;
F_5 ( & V_2 -> V_16 ) ;
F_65 ( V_2 , V_42 , V_98 ) ;
F_6 ( & V_2 -> V_16 ) ;
}
void F_69 ( struct V_1 * V_2 ,
const struct V_204 * V_204 )
{
T_4 V_205 = V_149 ;
if ( V_204 && V_204 -> V_206 )
V_205 = F_70 ( ( const T_1 * ) V_204 ,
V_207 * ( V_204 -> V_206 + 1 ) , NULL ) ;
F_67 ( V_2 , V_205 , false ) ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_144 * V_5 , bool V_98 )
{
T_4 V_208 = 0 ;
int V_4 ;
if ( V_2 -> V_22 . V_199 )
return - V_209 ;
if ( ! V_5 || V_5 -> V_6 == 0 ) {
V_2 -> V_5 . V_6 = 0 ;
F_56 ( V_2 ) ;
return 0 ;
}
if ( V_5 -> V_26 & V_196 ) {
V_5 -> V_6 = 1 ;
V_5 -> V_210 [ 0 ] = '\0' ;
V_5 -> V_211 = V_212 ;
V_5 -> V_188 [ 0 ] = V_189 ;
V_5 -> V_7 [ 0 ] = V_213 ;
V_5 -> V_214 [ 0 ] = 0 ;
V_5 -> V_215 [ 0 ] [ 0 ] = 0 ;
V_5 -> V_215 [ 0 ] [ 1 ] = 0 ;
}
V_5 -> V_210 [ sizeof( V_5 -> V_210 ) - 1 ] = '\0' ;
if ( V_5 -> V_6 > V_2 -> V_216 ) {
F_32 ( 1 , L_26 , V_2 -> V_216 ) ;
return - V_104 ;
}
if ( V_5 -> V_211 != V_212 &&
( V_5 -> V_211 & 0xff000000 ) != 0 ) {
F_32 ( 1 , L_27 ) ;
return - V_104 ;
}
if ( V_5 -> V_124 != V_217 &&
V_5 -> V_124 != V_125 ) {
F_32 ( 1 , L_28 ) ;
return - V_104 ;
}
if ( V_5 -> V_6 > 1 )
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ )
if ( V_5 -> V_188 [ V_4 ] ==
V_189 ) {
F_32 ( 1 , L_29 ) ;
return - V_104 ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
const T_1 V_218 = F_72 ( V_5 -> V_215 [ 0 ] ) ;
T_1 * V_215 = V_5 -> V_215 [ V_4 ] ;
bool V_219 = false ;
unsigned V_187 ;
V_5 -> V_3 [ V_4 ] = V_150 ;
if ( V_208 & ( 1 << V_5 -> V_188 [ V_4 ] ) ) {
F_32 ( 1 , L_30 ) ;
return - V_104 ;
}
V_208 |= 1 << V_5 -> V_188 [ V_4 ] ;
if ( ( V_208 & ( 1 << V_175 ) ) &&
( V_208 & ( 1 << V_177 ) ) ) {
F_32 ( 1 , L_31 ) ;
return - V_104 ;
}
if ( V_5 -> V_7 [ V_4 ] >
V_220 ) {
F_32 ( 1 , L_32 ) ;
return - V_104 ;
}
if ( V_5 -> V_7 [ V_4 ] == 2 ) {
F_32 ( 1 , L_33 ) ;
return - V_104 ;
}
if ( V_5 -> V_188 [ V_4 ] > V_189 ) {
F_32 ( 1 , L_34 ) ;
return - V_104 ;
}
for ( V_187 = 0 ; V_187 < V_218 ; V_187 ++ ) {
if ( ( V_215 [ V_187 ] & 0x80 ) == 0 ) {
if ( V_219 )
break;
V_219 = true ;
}
}
if ( ! V_219 || V_187 == V_218 ) {
F_32 ( 1 , L_35 ) ;
return - V_104 ;
}
memset ( V_215 + V_187 + 1 , 0 , V_218 - V_187 - 1 ) ;
}
if ( V_5 -> V_124 >= V_125 ) {
if ( V_5 -> V_6 > 2 ) {
F_32 ( 1 , L_36 ) ;
return - V_104 ;
}
if ( V_5 -> V_6 == 2 ) {
if ( ! ( V_208 & ( ( 1 << V_178 ) |
( 1 << V_174 ) ) ) ) {
F_32 ( 1 , L_37 ) ;
return - V_104 ;
}
if ( ! ( V_208 & ( ( 1 << V_177 ) |
( 1 << V_175 ) ) ) ) {
F_32 ( 1 , L_38 ) ;
return - V_104 ;
}
}
}
for ( V_4 = V_5 -> V_6 ; V_4 < V_195 ; V_4 ++ ) {
V_5 -> V_7 [ V_4 ] = 0 ;
V_5 -> V_188 [ V_4 ] = 0 ;
V_5 -> V_214 [ V_4 ] = 0 ;
memset ( V_5 -> V_215 [ V_4 ] , 0 ,
sizeof( V_5 -> V_215 [ V_4 ] ) ) ;
}
V_5 -> V_43 = V_2 -> V_5 . V_43 ;
V_2 -> V_5 = * V_5 ;
if ( V_2 -> V_42 != V_149 )
F_61 ( V_2 , V_98 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_144 * V_5 , bool V_98 )
{
int V_65 ;
F_5 ( & V_2 -> V_16 ) ;
V_65 = F_71 ( V_2 , V_5 , V_98 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_65 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned int V_221 )
{
const struct V_144 * V_145 = & V_2 -> V_5 ;
const T_1 * V_215 = V_145 -> V_215 [ V_221 ] ;
bool V_219 = false ;
unsigned int V_143 ;
V_24 -> V_24 [ 0 ] = ( V_145 -> V_3 [ V_221 ] << 4 ) | 0x0f ;
V_24 -> V_72 = 4 ;
V_24 -> V_24 [ 1 ] = V_222 ;
V_24 -> V_24 [ 2 ] = V_2 -> V_5 . V_124 ;
V_24 -> V_24 [ 3 ] = V_145 -> V_214 [ V_221 ] ;
for ( V_143 = 0 ; V_143 < F_72 ( V_145 -> V_215 [ 0 ] ) ; V_143 ++ ) {
V_24 -> V_24 [ V_24 -> V_72 ++ ] = V_215 [ V_143 ] ;
if ( ( V_215 [ V_143 ] & V_223 ) == 0 ) {
if ( V_219 )
break;
V_219 = true ;
}
}
}
static int F_74 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_1 V_224 )
{
struct V_23 V_225 = { } ;
if ( V_24 -> V_24 [ 1 ] == V_137 )
return 0 ;
if ( F_45 ( V_24 ) == V_117 )
return 0 ;
F_75 ( & V_225 , V_24 ) ;
F_76 ( & V_225 , V_24 -> V_24 [ 1 ] , V_224 ) ;
return F_51 ( V_2 , & V_225 , false ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_74 ( V_2 , V_24 ,
V_226 ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_74 ( V_2 , V_24 ,
V_227 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_115 )
{
bool V_228 = F_44 ( V_24 ) ;
T_1 V_229 = F_42 ( V_24 ) ;
T_1 V_230 = F_45 ( V_24 ) ;
T_1 V_231 = F_2 ( V_2 , V_229 ) ;
int V_221 = F_1 ( V_2 , V_229 ) ;
bool V_232 = V_230 == 0xf ;
struct V_23 V_233 = { } ;
F_32 ( 2 , L_20 , V_71 , V_24 -> V_72 , V_24 -> V_24 ) ;
if ( F_79 ( & V_2 -> V_5 ) &&
V_24 -> V_24 [ 1 ] != V_109 )
return 0 ;
if ( V_2 -> V_77 -> V_234 ) {
if ( V_2 -> V_77 -> V_234 ( V_2 , V_24 ) != - V_235 )
return 0 ;
}
switch ( V_24 -> V_24 [ 1 ] ) {
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
if ( V_2 -> V_243 )
goto V_244;
if ( V_228 || V_232 )
return 0 ;
break;
case V_245 :
case V_246 :
if ( V_228 || V_232 )
goto V_244;
break;
case V_247 :
if ( ! V_228 )
goto V_244;
break;
default:
break;
}
F_75 ( & V_233 , V_24 ) ;
switch ( V_24 -> V_24 [ 1 ] ) {
case V_247 : {
T_4 V_205 = ( V_24 -> V_24 [ 2 ] << 8 ) | V_24 -> V_24 [ 3 ] ;
if ( ! V_232 )
V_2 -> V_148 [ V_230 ] = V_205 ;
F_32 ( 1 , L_39 ,
F_58 ( V_205 ) , V_230 ) ;
break;
}
case V_245 :
if ( ! ( V_2 -> V_248 & V_249 ) ||
! ( V_2 -> V_5 . V_26 & V_250 ) )
break;
#ifdef F_80
switch ( V_24 -> V_24 [ 2 ] ) {
case 0x60 :
if ( V_24 -> V_72 == 2 )
F_81 ( V_2 -> V_251 , V_252 ,
V_24 -> V_24 [ 2 ] , 0 ) ;
else
F_81 ( V_2 -> V_251 , V_252 ,
V_24 -> V_24 [ 2 ] << 8 | V_24 -> V_24 [ 3 ] , 0 ) ;
break;
case 0x56 : case 0x57 :
case 0x67 : case 0x68 : case 0x69 : case 0x6a :
break;
default:
F_81 ( V_2 -> V_251 , V_252 , V_24 -> V_24 [ 2 ] , 0 ) ;
break;
}
#endif
break;
case V_246 :
if ( ! ( V_2 -> V_248 & V_249 ) ||
! ( V_2 -> V_5 . V_26 & V_250 ) )
break;
#ifdef F_80
F_82 ( V_2 -> V_251 ) ;
#endif
break;
case V_236 :
F_83 ( & V_233 , V_2 -> V_5 . V_124 ) ;
return F_51 ( V_2 , & V_233 , false ) ;
case V_240 :
if ( V_231 == V_213 && V_229 == 15 )
return 0 ;
F_60 ( & V_233 , V_2 -> V_42 , V_231 ) ;
return F_51 ( V_2 , & V_233 , false ) ;
case V_237 :
if ( V_2 -> V_5 . V_211 == V_212 )
return F_77 ( V_2 , V_24 ) ;
F_84 ( & V_233 , V_2 -> V_5 . V_211 ) ;
return F_51 ( V_2 , & V_233 , false ) ;
case V_238 :
if ( V_231 == V_213 )
return 0 ;
return F_78 ( V_2 , V_24 ) ;
case V_241 : {
if ( V_2 -> V_5 . V_210 [ 0 ] == 0 )
return F_77 ( V_2 , V_24 ) ;
F_85 ( & V_233 , V_2 -> V_5 . V_210 ) ;
return F_51 ( V_2 , & V_233 , false ) ;
}
case V_242 :
if ( V_2 -> V_5 . V_124 < V_125 )
return F_77 ( V_2 , V_24 ) ;
F_59 ( V_2 , & V_233 , V_221 ) ;
return F_51 ( V_2 , & V_233 , false ) ;
default:
if ( ! V_228 && ! V_115 && ! V_2 -> V_253 &&
! V_2 -> V_254 && V_24 -> V_24 [ 1 ] != V_137 )
return F_77 ( V_2 , V_24 ) ;
break;
}
V_244:
if ( V_115 && ! ( V_24 -> V_26 & V_102 ) )
return 0 ;
if ( V_2 -> V_254 )
F_10 ( V_2 -> V_254 , V_24 ) ;
else
F_15 ( V_2 , V_24 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_2 )
{
int V_111 = 0 ;
if ( V_2 -> V_200 == 0 )
V_111 = F_66 ( V_2 , V_201 , 1 ) ;
if ( V_111 == 0 )
V_2 -> V_200 ++ ;
return V_111 ;
}
void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_200 -- ;
if ( V_2 -> V_200 == 0 )
F_34 ( F_66 ( V_2 , V_201 , 0 ) ) ;
}
int F_88 ( struct V_255 * V_256 , void * V_257 )
{
struct V_1 * V_2 = F_89 ( V_256 -> V_258 ) ;
struct V_44 * V_45 ;
F_5 ( & V_2 -> V_16 ) ;
F_90 ( V_256 , L_40 , V_2 -> V_68 ) ;
F_90 ( V_256 , L_41 , V_2 -> V_69 ) ;
F_90 ( V_256 , L_42 ,
F_58 ( V_2 -> V_42 ) ) ;
F_90 ( V_256 , L_43 , V_2 -> V_5 . V_6 ) ;
F_90 ( V_256 , L_44 , V_2 -> V_5 . V_43 ) ;
if ( V_2 -> V_254 )
F_90 ( V_256 , L_45 ,
V_2 -> V_243 ? L_46 : L_17 ) ;
if ( V_2 -> V_259 )
F_91 ( V_256 , L_47 ) ;
if ( V_2 -> V_200 )
F_90 ( V_256 , L_48 ,
V_2 -> V_200 ) ;
V_45 = V_2 -> V_50 ;
if ( V_45 )
F_90 ( V_256 , L_49 ,
V_45 -> V_24 . V_72 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_87 ,
V_45 -> V_24 . V_64 ) ;
F_90 ( V_256 , L_50 , V_2 -> V_53 ) ;
F_9 (data, &adap->transmit_queue, list) {
F_90 ( V_256 , L_51 ,
V_45 -> V_24 . V_72 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_87 ,
V_45 -> V_24 . V_64 ) ;
}
F_9 (data, &adap->wait_queue, list) {
F_90 ( V_256 , L_52 ,
V_45 -> V_24 . V_72 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_87 ,
V_45 -> V_24 . V_64 ) ;
}
F_92 ( V_2 , V_260 , V_256 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
}
