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
int F_22 ( void * V_59 )
{
struct V_1 * V_2 = V_59 ;
for (; ; ) {
unsigned int V_60 ;
struct V_44 * V_45 ;
bool V_61 = false ;
T_1 V_58 ;
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
V_58 = 2 ;
else
V_58 = 4 ;
if ( V_45 -> V_58 ) {
V_60 = V_71 ;
} else if ( V_45 -> V_72 ) {
V_60 = V_73 ;
} else {
V_60 = V_74 ;
}
if ( V_45 -> V_58 == 0 )
V_45 -> V_58 = V_58 ;
if ( V_2 -> V_75 -> V_76 ( V_2 , V_45 -> V_58 ,
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
V_24 -> V_57 += V_81 ;
V_2 -> V_50 = NULL ;
if ( V_45 -> V_58 > 1 &&
! ( V_77 & ( V_56 | V_52 ) ) ) {
V_45 -> V_58 -- ;
F_34 ( & V_45 -> V_30 , & V_2 -> V_66 ) ;
V_2 -> V_53 ++ ;
goto V_85;
}
V_45 -> V_58 = 0 ;
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
V_24 -> V_57 = 0 ;
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( ! V_24 -> V_93 )
V_24 -> V_93 = ++ V_2 -> V_93 ;
if ( V_24 -> V_94 && V_24 -> V_61 == 0 ) {
V_24 -> V_61 = 1000 ;
}
if ( V_24 -> V_61 )
V_24 -> V_26 &= V_95 ;
else
V_24 -> V_26 = 0 ;
if ( V_24 -> V_70 == 0 || V_24 -> V_70 > V_96 ) {
F_31 ( 1 , L_4 , V_24 -> V_70 ) ;
return - V_97 ;
}
if ( V_24 -> V_61 && V_24 -> V_70 == 1 ) {
F_31 ( 1 , L_5 ) ;
return - V_97 ;
}
memset ( V_24 -> V_24 + V_24 -> V_70 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_70 ) ;
if ( V_24 -> V_70 == 1 ) {
if ( F_39 ( V_24 ) == 0xf ) {
F_31 ( 1 , L_6 ) ;
return - V_97 ;
}
if ( F_40 ( V_2 , F_39 ( V_24 ) ) ) {
V_24 -> V_54 = F_4 () ;
V_24 -> V_51 = V_98 |
V_56 ;
V_24 -> V_83 = 1 ;
return 0 ;
}
}
if ( V_24 -> V_70 > 1 && ! F_41 ( V_24 ) &&
F_40 ( V_2 , F_39 ( V_24 ) ) ) {
F_31 ( 1 , L_7 ) ;
return - V_97 ;
}
if ( V_24 -> V_70 > 1 && V_2 -> V_64 &&
! F_40 ( V_2 , F_42 ( V_24 ) ) ) {
F_31 ( 1 , L_8 ,
F_42 ( V_24 ) ) ;
return - V_97 ;
}
if ( ! V_2 -> V_64 && ! V_2 -> V_65 )
return - V_99 ;
if ( V_2 -> V_53 >= V_100 )
return - V_101 ;
V_45 = F_43 ( sizeof( * V_45 ) , V_29 ) ;
if ( ! V_45 )
return - V_102 ;
if ( V_24 -> V_70 > 1 && V_24 -> V_24 [ 1 ] == V_103 ) {
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
const struct V_44 * V_104 ;
V_104 = F_44 ( & V_2 -> V_66 ,
const struct V_44 , V_30 ) ;
V_91 = F_42 ( & V_104 -> V_24 ) ;
} else if ( V_2 -> V_50 ) {
V_91 =
F_42 ( & V_2 -> V_50 -> V_24 ) ;
}
}
V_45 -> V_72 = V_91 != F_42 ( V_24 ) ;
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
int V_105 ;
F_5 ( & V_2 -> V_16 ) ;
V_105 = F_38 ( V_2 , V_24 , NULL , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_105 ;
}
void F_49 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_44 * V_45 ;
T_1 V_106 = F_42 ( V_24 ) ;
T_1 V_107 = F_39 ( V_24 ) ;
T_1 V_108 = V_24 -> V_24 [ 1 ] ;
bool V_109 = false ;
bool V_34 = true ;
T_1 V_110 = 0 ;
if ( F_33 ( ! V_24 -> V_70 || V_24 -> V_70 > V_96 ) )
return;
if ( V_106 != V_111 &&
F_40 ( V_2 , V_106 ) )
return;
V_24 -> V_87 = F_4 () ;
V_24 -> V_88 = V_112 ;
V_24 -> V_93 = V_24 -> V_94 = V_24 -> V_61 = 0 ;
V_24 -> V_51 = 0 ;
V_24 -> V_54 = 0 ;
V_24 -> V_82 = 0 ;
V_24 -> V_83 = 0 ;
V_24 -> V_84 = 0 ;
V_24 -> V_57 = 0 ;
V_24 -> V_26 = 0 ;
memset ( V_24 -> V_24 + V_24 -> V_70 , 0 , sizeof( V_24 -> V_24 ) - V_24 -> V_70 ) ;
F_5 ( & V_2 -> V_16 ) ;
F_31 ( 2 , L_14 , V_24 -> V_70 , V_24 -> V_24 ) ;
if ( ! F_41 ( V_24 ) )
V_34 = F_40 ( V_2 , V_107 ) ;
if ( V_34 && V_24 -> V_70 > 1 && V_113 [ V_108 ] ) {
T_1 V_114 = V_113 [ V_108 ] & V_115 ;
V_110 = V_113 [ V_108 ] & 0x1f ;
if ( V_24 -> V_70 < V_110 )
V_34 = false ;
else if ( ! F_41 ( V_24 ) && ! ( V_114 & V_116 ) )
V_34 = false ;
else if ( F_41 ( V_24 ) && ! ( V_114 & V_117 ) )
V_34 = false ;
else if ( F_41 ( V_24 ) &&
V_2 -> V_5 . V_118 >= V_119 &&
! ( V_114 & V_120 ) )
V_34 = false ;
}
if ( V_34 && V_110 ) {
switch ( V_108 ) {
case V_121 :
if ( V_24 -> V_24 [ 2 ] & 0x10 ) {
switch ( V_24 -> V_24 [ 2 ] & 0xf ) {
case V_122 :
case V_123 :
if ( V_24 -> V_70 < 5 )
V_34 = false ;
break;
}
} else if ( ( V_24 -> V_24 [ 2 ] & 0xf ) == V_124 ) {
if ( V_24 -> V_70 < 5 )
V_34 = false ;
}
break;
case V_125 :
switch ( V_24 -> V_24 [ 2 ] ) {
case V_126 :
break;
case V_127 :
if ( V_24 -> V_70 < 10 )
V_34 = false ;
break;
case V_128 :
if ( V_24 -> V_70 < 7 )
V_34 = false ;
break;
case V_129 :
if ( V_24 -> V_70 < 4 )
V_34 = false ;
break;
case V_130 :
if ( V_24 -> V_70 < 5 )
V_34 = false ;
break;
}
break;
}
}
if ( V_34 && V_24 -> V_70 > 1 && V_108 != V_103 ) {
bool abort = V_108 == V_131 ;
if ( abort )
V_108 = V_24 -> V_24 [ 2 ] ;
F_9 (data, &adap->wait_queue, list) {
struct V_23 * V_132 = & V_45 -> V_24 ;
if ( ! abort && V_132 -> V_24 [ 1 ] == V_133 &&
( V_108 == V_134 ||
V_108 == V_135 ) &&
( V_132 -> V_94 == V_134 ||
V_132 -> V_94 == V_135 ) )
V_132 -> V_94 = V_108 ;
if ( ( abort && V_108 != V_132 -> V_24 [ 1 ] ) ||
( ! abort && V_108 != V_132 -> V_94 ) )
continue;
if ( V_106 != F_39 ( V_132 ) &&
! F_41 ( V_132 ) )
continue;
memcpy ( V_132 -> V_24 , V_24 -> V_24 , V_24 -> V_70 ) ;
V_132 -> V_70 = V_24 -> V_70 ;
V_132 -> V_87 = V_24 -> V_87 ;
V_132 -> V_88 = V_24 -> V_88 ;
if ( abort )
V_132 -> V_88 |= V_136 ;
V_24 -> V_26 = V_132 -> V_26 ;
F_21 ( & V_45 -> V_30 ) ;
if ( ! F_29 ( & V_45 -> V_69 ) ) {
F_6 ( & V_2 -> V_16 ) ;
F_30 () ;
F_5 ( & V_2 -> V_16 ) ;
}
if ( V_45 -> V_9 )
V_109 = true ;
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
F_50 ( V_2 , V_24 , V_109 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned int V_137 ,
unsigned int V_3 )
{
struct V_138 * V_139 = & V_2 -> V_5 ;
struct V_23 V_24 = { } ;
int V_62 ;
if ( F_40 ( V_2 , V_3 ) )
return 0 ;
V_24 . V_70 = 1 ;
V_24 . V_24 [ 0 ] = ( V_3 << 4 ) | V_3 ;
V_62 = F_38 ( V_2 , & V_24 , NULL , true ) ;
if ( ! V_2 -> V_65 )
return - V_140 ;
if ( V_62 )
return V_62 ;
if ( V_24 . V_51 & V_52 )
return 0 ;
V_62 = V_2 -> V_75 -> V_141 ( V_2 , V_3 ) ;
if ( V_62 )
return V_62 ;
V_139 -> V_3 [ V_137 ] = V_3 ;
V_139 -> V_43 |= 1 << V_3 ;
V_2 -> V_142 [ V_3 ] = V_2 -> V_42 ;
F_31 ( 2 , L_15 , V_3 ,
V_139 -> V_7 [ V_137 ] ) ;
return 1 ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_75 -> V_141 ( V_2 , V_143 ) ) ;
V_2 -> V_5 . V_43 = 0 ;
V_2 -> V_65 = false ;
V_2 -> V_64 = false ;
memset ( V_2 -> V_142 , 0xff , sizeof( V_2 -> V_142 ) ) ;
F_7 ( & V_2 -> V_63 ) ;
F_16 ( V_2 ) ;
}
static int F_53 ( void * V_144 )
{
static const T_1 V_145 [] = {
V_146 , V_147 ,
V_143
} ;
static const T_1 V_148 [] = {
V_149 , V_150 ,
V_151 ,
V_152 , V_153 ,
V_143
} ;
static const T_1 V_154 [] = {
V_155 , V_156 ,
V_157 , V_158 ,
V_152 , V_153 ,
V_143
} ;
static const T_1 V_159 [] = {
V_160 , V_161 ,
V_162 ,
V_152 , V_153 ,
V_143
} ;
static const T_1 V_163 [] = {
V_164 ,
V_143
} ;
static const T_1 V_165 [] = {
V_147 ,
V_152 , V_153 ,
V_143
} ;
static const T_1 * V_166 [ 6 ] = {
[ V_167 ] = V_145 ,
[ V_168 ] = V_148 ,
[ V_169 ] = V_154 ,
[ V_170 ] = V_159 ,
[ V_171 ] = V_163 ,
[ V_172 ] = V_165 ,
} ;
static const T_4 V_173 [] = {
[ V_167 ] = V_174 ,
[ V_168 ] = V_175 ,
[ V_169 ] = V_176 ,
[ V_170 ] = V_177 ,
[ V_171 ] = V_178 ,
[ V_172 ] = V_179 ,
} ;
struct V_1 * V_2 = V_144 ;
struct V_138 * V_139 = & V_2 -> V_5 ;
int V_62 ;
int V_4 , V_180 ;
F_5 ( & V_2 -> V_16 ) ;
F_31 ( 1 , L_16 ,
F_54 ( V_2 -> V_42 ) , V_139 -> V_6 ) ;
V_139 -> V_43 = 0 ;
if ( V_139 -> V_181 [ 0 ] == V_182 )
goto V_183;
for ( V_4 = 0 ; V_4 < V_139 -> V_6 ; V_4 ++ ) {
unsigned int type = V_139 -> V_181 [ V_4 ] ;
const T_1 * V_184 ;
T_1 V_185 ;
if ( V_2 -> V_42 && type == V_167 )
type = V_172 ;
V_184 = V_166 [ type ] ;
V_185 = V_139 -> V_3 [ V_4 ] ;
V_139 -> V_3 [ V_4 ] = V_143 ;
if ( V_185 == V_143 ||
V_185 == V_111 ||
! ( ( 1 << V_185 ) & V_173 [ type ] ) )
V_185 = V_184 [ 0 ] ;
V_62 = F_51 ( V_2 , V_4 , V_185 ) ;
if ( V_62 > 0 )
continue;
if ( V_62 < 0 )
goto V_186;
for ( V_180 = 0 ; V_184 [ V_180 ] != V_143 ; V_180 ++ ) {
if ( V_184 [ V_180 ] == V_185 )
continue;
if ( ( V_184 [ V_180 ] == V_152 ||
V_184 [ V_180 ] == V_153 ) &&
V_139 -> V_118 < V_119 )
continue;
V_62 = F_51 ( V_2 , V_4 , V_184 [ V_180 ] ) ;
if ( V_62 == 0 )
continue;
if ( V_62 < 0 )
goto V_186;
break;
}
if ( V_184 [ V_180 ] == V_143 )
F_31 ( 1 , L_17 , V_4 ) ;
}
if ( V_2 -> V_5 . V_43 == 0 &&
! ( V_139 -> V_26 & V_187 ) )
goto V_186;
V_183:
if ( V_2 -> V_5 . V_43 == 0 ) {
V_139 -> V_3 [ 0 ] = V_111 ;
V_139 -> V_43 = 1 << V_139 -> V_3 [ 0 ] ;
for ( V_4 = 1 ; V_4 < V_139 -> V_6 ; V_4 ++ )
V_139 -> V_3 [ V_4 ] = V_143 ;
}
for ( V_4 = V_139 -> V_6 ; V_4 < V_188 ; V_4 ++ )
V_139 -> V_3 [ V_4 ] = V_143 ;
V_2 -> V_64 = true ;
V_2 -> V_65 = false ;
F_16 ( V_2 ) ;
for ( V_4 = 0 ; V_4 < V_139 -> V_6 ; V_4 ++ ) {
struct V_23 V_24 = {} ;
if ( V_139 -> V_3 [ V_4 ] == V_143 ||
( V_139 -> V_26 & V_189 ) )
continue;
V_24 . V_24 [ 0 ] = ( V_139 -> V_3 [ V_4 ] << 4 ) | 0x0f ;
if ( V_139 -> V_3 [ V_4 ] != V_111 &&
V_2 -> V_5 . V_118 >= V_119 ) {
F_55 ( V_2 , & V_24 , V_4 ) ;
F_38 ( V_2 , & V_24 , NULL , false ) ;
}
F_56 ( & V_24 , V_2 -> V_42 ,
V_139 -> V_7 [ V_4 ] ) ;
F_31 ( 2 , L_18 ,
V_139 -> V_3 [ V_4 ] ,
F_54 ( V_2 -> V_42 ) ) ;
F_38 ( V_2 , & V_24 , NULL , false ) ;
}
V_2 -> V_190 = NULL ;
F_18 ( & V_2 -> V_191 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
V_186:
for ( V_4 = 0 ; V_4 < V_139 -> V_6 ; V_4 ++ )
V_139 -> V_3 [ V_4 ] = V_143 ;
F_52 ( V_2 ) ;
V_2 -> V_190 = NULL ;
F_6 ( & V_2 -> V_16 ) ;
F_18 ( & V_2 -> V_191 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , bool V_90 )
{
if ( F_33 ( V_2 -> V_65 || V_2 -> V_64 ) )
return;
F_45 ( & V_2 -> V_191 ) ;
V_2 -> V_65 = true ;
V_2 -> V_190 = F_58 ( F_53 , V_2 ,
L_19 , V_2 -> V_192 ) ;
if ( F_59 ( V_2 -> V_190 ) ) {
V_2 -> V_190 = NULL ;
} else if ( V_90 ) {
F_6 ( & V_2 -> V_16 ) ;
F_60 ( & V_2 -> V_191 ) ;
F_5 ( & V_2 -> V_16 ) ;
}
}
void F_61 ( struct V_1 * V_2 , T_4 V_42 , bool V_90 )
{
if ( V_42 == V_2 -> V_42 || V_2 -> V_22 . V_193 )
return;
if ( V_42 == V_194 ||
V_2 -> V_42 != V_194 ) {
V_2 -> V_42 = V_194 ;
F_16 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_2 -> V_195 )
F_33 ( F_62 ( V_2 , V_196 , false ) ) ;
F_33 ( V_2 -> V_75 -> V_197 ( V_2 , false ) ) ;
if ( V_42 == V_194 )
return;
}
if ( V_2 -> V_75 -> V_197 ( V_2 , true ) )
return;
if ( V_2 -> V_195 &&
F_62 ( V_2 , V_196 , true ) ) {
F_33 ( V_2 -> V_75 -> V_197 ( V_2 , false ) ) ;
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
struct V_138 * V_5 , bool V_90 )
{
T_4 V_198 = 0 ;
int V_4 ;
if ( V_2 -> V_22 . V_193 )
return - V_199 ;
if ( ! V_5 || V_5 -> V_6 == 0 ) {
V_2 -> V_5 . V_6 = 0 ;
F_52 ( V_2 ) ;
return 0 ;
}
if ( V_5 -> V_26 & V_189 ) {
V_5 -> V_6 = 1 ;
V_5 -> V_200 [ 0 ] = '\0' ;
V_5 -> V_201 = V_202 ;
V_5 -> V_181 [ 0 ] = V_182 ;
V_5 -> V_7 [ 0 ] = V_203 ;
V_5 -> V_204 [ 0 ] = 0 ;
V_5 -> V_205 [ 0 ] [ 0 ] = 0 ;
V_5 -> V_205 [ 0 ] [ 1 ] = 0 ;
}
V_5 -> V_200 [ sizeof( V_5 -> V_200 ) - 1 ] = '\0' ;
if ( V_5 -> V_6 > V_2 -> V_206 ) {
F_31 ( 1 , L_20 , V_2 -> V_206 ) ;
return - V_97 ;
}
if ( V_5 -> V_201 != V_202 &&
( V_5 -> V_201 & 0xff000000 ) != 0 )
return - V_97 ;
if ( V_5 -> V_118 != V_207 &&
V_5 -> V_118 != V_119 )
return - V_97 ;
if ( V_5 -> V_6 > 1 )
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ )
if ( V_5 -> V_181 [ V_4 ] ==
V_182 ) {
F_31 ( 1 , L_21 ) ;
return - V_97 ;
}
for ( V_4 = 0 ; V_4 < V_5 -> V_6 ; V_4 ++ ) {
const T_1 V_208 = F_66 ( V_5 -> V_205 [ 0 ] ) ;
T_1 * V_205 = V_5 -> V_205 [ V_4 ] ;
bool V_209 = false ;
unsigned V_180 ;
V_5 -> V_3 [ V_4 ] = V_143 ;
if ( V_198 & ( 1 << V_5 -> V_181 [ V_4 ] ) ) {
F_31 ( 1 , L_22 ) ;
return - V_97 ;
}
V_198 |= 1 << V_5 -> V_181 [ V_4 ] ;
if ( ( V_198 & ( 1 << V_168 ) ) &&
( V_198 & ( 1 << V_170 ) ) ) {
F_31 ( 1 , L_23 ) ;
return - V_97 ;
}
if ( V_5 -> V_7 [ V_4 ] >
V_210 ) {
F_31 ( 1 , L_24 ) ;
return - V_97 ;
}
if ( V_5 -> V_7 [ V_4 ] == 2 ) {
F_31 ( 1 , L_25 ) ;
return - V_97 ;
}
if ( V_5 -> V_181 [ V_4 ] > V_182 ) {
F_31 ( 1 , L_26 ) ;
return - V_97 ;
}
for ( V_180 = 0 ; V_180 < V_208 ; V_180 ++ ) {
if ( ( V_205 [ V_180 ] & 0x80 ) == 0 ) {
if ( V_209 )
break;
V_209 = true ;
}
}
if ( ! V_209 || V_180 == V_208 ) {
F_31 ( 1 , L_27 ) ;
return - V_97 ;
}
memset ( V_205 + V_180 + 1 , 0 , V_208 - V_180 - 1 ) ;
}
if ( V_5 -> V_118 >= V_119 ) {
if ( V_5 -> V_6 > 2 ) {
F_31 ( 1 , L_28 ) ;
return - V_97 ;
}
if ( V_5 -> V_6 == 2 ) {
if ( ! ( V_198 & ( ( 1 << V_171 ) |
( 1 << V_167 ) ) ) ) {
F_31 ( 1 , L_29 ) ;
return - V_97 ;
}
if ( ! ( V_198 & ( ( 1 << V_170 ) |
( 1 << V_168 ) ) ) ) {
F_31 ( 1 , L_30 ) ;
return - V_97 ;
}
}
}
for ( V_4 = V_5 -> V_6 ; V_4 < V_188 ; V_4 ++ ) {
V_5 -> V_7 [ V_4 ] = 0 ;
V_5 -> V_181 [ V_4 ] = 0 ;
V_5 -> V_204 [ V_4 ] = 0 ;
memset ( V_5 -> V_205 [ V_4 ] , 0 ,
sizeof( V_5 -> V_205 [ V_4 ] ) ) ;
}
V_5 -> V_43 = V_2 -> V_5 . V_43 ;
V_2 -> V_5 = * V_5 ;
if ( V_2 -> V_42 != V_194 )
F_57 ( V_2 , V_90 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_138 * V_5 , bool V_90 )
{
int V_62 ;
F_5 ( & V_2 -> V_16 ) ;
V_62 = F_65 ( V_2 , V_5 , V_90 ) ;
F_6 ( & V_2 -> V_16 ) ;
return V_62 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
unsigned int V_211 )
{
const struct V_138 * V_139 = & V_2 -> V_5 ;
const T_1 * V_205 = V_139 -> V_205 [ V_211 ] ;
bool V_209 = false ;
unsigned int V_137 ;
V_24 -> V_24 [ 0 ] = ( V_139 -> V_3 [ V_211 ] << 4 ) | 0x0f ;
V_24 -> V_70 = 4 ;
V_24 -> V_24 [ 1 ] = V_212 ;
V_24 -> V_24 [ 2 ] = V_2 -> V_5 . V_118 ;
V_24 -> V_24 [ 3 ] = V_139 -> V_204 [ V_211 ] ;
for ( V_137 = 0 ; V_137 < F_66 ( V_139 -> V_205 [ 0 ] ) ; V_137 ++ ) {
V_24 -> V_24 [ V_24 -> V_70 ++ ] = V_205 [ V_137 ] ;
if ( ( V_205 [ V_137 ] & V_213 ) == 0 ) {
if ( V_209 )
break;
V_209 = true ;
}
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_1 V_214 )
{
struct V_23 V_215 = { } ;
if ( V_24 -> V_24 [ 1 ] == V_131 )
return 0 ;
F_69 ( & V_215 , V_24 ) ;
F_70 ( & V_215 , V_24 -> V_24 [ 1 ] , V_214 ) ;
return F_48 ( V_2 , & V_215 , false ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_68 ( V_2 , V_24 ,
V_216 ) ;
}
static int F_72 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
return F_68 ( V_2 , V_24 ,
V_217 ) ;
}
static int F_50 ( struct V_1 * V_2 , struct V_23 * V_24 ,
bool V_109 )
{
bool V_218 = F_41 ( V_24 ) ;
T_1 V_219 = F_39 ( V_24 ) ;
T_1 V_220 = F_42 ( V_24 ) ;
T_1 V_221 = F_2 ( V_2 , V_219 ) ;
int V_211 = F_1 ( V_2 , V_219 ) ;
bool V_222 = V_220 == 0xf ;
struct V_23 V_223 = { } ;
F_31 ( 1 , L_31 , V_24 -> V_70 , V_24 -> V_24 ) ;
if ( F_73 ( & V_2 -> V_5 ) &&
V_24 -> V_24 [ 1 ] != V_103 )
return 0 ;
if ( V_2 -> V_75 -> V_224 ) {
if ( V_2 -> V_75 -> V_224 ( V_2 , V_24 ) != - V_225 )
return 0 ;
}
switch ( V_24 -> V_24 [ 1 ] ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
if ( V_2 -> V_233 )
goto V_234;
if ( V_218 || V_222 )
return 0 ;
break;
case V_235 :
case V_236 :
if ( V_218 || V_222 )
goto V_234;
break;
case V_237 :
if ( ! V_218 )
goto V_234;
break;
default:
break;
}
F_69 ( & V_223 , V_24 ) ;
switch ( V_24 -> V_24 [ 1 ] ) {
case V_237 : {
T_4 V_238 = ( V_24 -> V_24 [ 2 ] << 8 ) | V_24 -> V_24 [ 3 ] ;
if ( ! V_222 )
V_2 -> V_142 [ V_220 ] = V_238 ;
F_31 ( 1 , L_32 ,
F_54 ( V_238 ) , V_220 ) ;
break;
}
case V_235 :
if ( ! ( V_2 -> V_239 & V_240 ) ||
! ( V_2 -> V_5 . V_26 & V_241 ) )
break;
#if F_74 ( V_242 )
switch ( V_24 -> V_24 [ 2 ] ) {
case 0x60 :
if ( V_24 -> V_70 == 2 )
F_75 ( V_2 -> V_243 , V_244 ,
V_24 -> V_24 [ 2 ] , 0 ) ;
else
F_75 ( V_2 -> V_243 , V_244 ,
V_24 -> V_24 [ 2 ] << 8 | V_24 -> V_24 [ 3 ] , 0 ) ;
break;
case 0x56 : case 0x57 :
case 0x67 : case 0x68 : case 0x69 : case 0x6a :
break;
default:
F_75 ( V_2 -> V_243 , V_244 , V_24 -> V_24 [ 2 ] , 0 ) ;
break;
}
#endif
break;
case V_236 :
if ( ! ( V_2 -> V_239 & V_240 ) ||
! ( V_2 -> V_5 . V_26 & V_241 ) )
break;
#if F_74 ( V_242 )
F_76 ( V_2 -> V_243 ) ;
#endif
break;
case V_226 :
F_77 ( & V_223 , V_2 -> V_5 . V_118 ) ;
return F_48 ( V_2 , & V_223 , false ) ;
case V_230 :
if ( V_221 == V_203 && V_219 == 15 )
return 0 ;
F_56 ( & V_223 , V_2 -> V_42 , V_221 ) ;
return F_48 ( V_2 , & V_223 , false ) ;
case V_227 :
if ( V_2 -> V_5 . V_201 == V_202 )
return F_71 ( V_2 , V_24 ) ;
F_78 ( & V_223 , V_2 -> V_5 . V_201 ) ;
return F_48 ( V_2 , & V_223 , false ) ;
case V_228 :
if ( V_221 == V_203 )
return 0 ;
return F_72 ( V_2 , V_24 ) ;
case V_231 : {
if ( V_2 -> V_5 . V_200 [ 0 ] == 0 )
return F_71 ( V_2 , V_24 ) ;
F_79 ( & V_223 , V_2 -> V_5 . V_200 ) ;
return F_48 ( V_2 , & V_223 , false ) ;
}
case V_232 :
if ( V_2 -> V_5 . V_118 < V_119 )
return F_71 ( V_2 , V_24 ) ;
F_55 ( V_2 , & V_223 , V_211 ) ;
return F_48 ( V_2 , & V_223 , false ) ;
default:
if ( ! V_218 && ! V_109 && ! V_2 -> V_245 &&
! V_2 -> V_246 && V_24 -> V_24 [ 1 ] != V_131 )
return F_71 ( V_2 , V_24 ) ;
break;
}
V_234:
if ( V_109 && ! ( V_24 -> V_26 & V_95 ) )
return 0 ;
if ( V_2 -> V_246 )
F_10 ( V_2 -> V_246 , V_24 ) ;
else
F_15 ( V_2 , V_24 ) ;
return 0 ;
}
int F_80 ( struct V_1 * V_2 )
{
int V_105 = 0 ;
if ( V_2 -> V_195 == 0 )
V_105 = F_62 ( V_2 , V_196 , 1 ) ;
if ( V_105 == 0 )
V_2 -> V_195 ++ ;
return V_105 ;
}
void F_81 ( struct V_1 * V_2 )
{
V_2 -> V_195 -- ;
if ( V_2 -> V_195 == 0 )
F_33 ( F_62 ( V_2 , V_196 , 0 ) ) ;
}
int F_82 ( struct V_247 * V_248 , void * V_249 )
{
struct V_1 * V_2 = F_83 ( V_248 -> V_250 ) ;
struct V_44 * V_45 ;
F_5 ( & V_2 -> V_16 ) ;
F_84 ( V_248 , L_33 , V_2 -> V_64 ) ;
F_84 ( V_248 , L_34 , V_2 -> V_65 ) ;
F_84 ( V_248 , L_35 ,
F_54 ( V_2 -> V_42 ) ) ;
F_84 ( V_248 , L_36 , V_2 -> V_5 . V_6 ) ;
F_84 ( V_248 , L_37 , V_2 -> V_5 . V_43 ) ;
if ( V_2 -> V_246 )
F_84 ( V_248 , L_38 ,
V_2 -> V_233 ? L_39 : L_11 ) ;
if ( V_2 -> V_251 )
F_85 ( V_248 , L_40 ) ;
if ( V_2 -> V_195 )
F_84 ( V_248 , L_41 ,
V_2 -> V_195 ) ;
V_45 = V_2 -> V_50 ;
if ( V_45 )
F_84 ( V_248 , L_42 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
F_84 ( V_248 , L_43 , V_2 -> V_53 ) ;
F_9 (data, &adap->transmit_queue, list) {
F_84 ( V_248 , L_44 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
}
F_9 (data, &adap->wait_queue, list) {
F_84 ( V_248 , L_45 ,
V_45 -> V_24 . V_70 , V_45 -> V_24 . V_24 , V_45 -> V_24 . V_94 ,
V_45 -> V_24 . V_61 ) ;
}
F_86 ( V_2 , V_252 , V_248 ) ;
F_6 ( & V_2 -> V_16 ) ;
return 0 ;
}
