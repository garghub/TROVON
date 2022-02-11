static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_3 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_3 ( V_2 , 0 ) , V_3 ,
( V_9 | V_10 | V_11 ) ,
V_4 , V_5 , V_6 , V_7 , 1000 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != V_7 ) {
F_4 ( L_1 ,
V_12 , V_7 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_2 V_5 , T_3 * V_6 , int V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , F_6 ( V_2 , 0 ) , V_3 ,
( V_9 | V_10 | V_14 ) ,
V_4 , V_5 , V_6 , V_7 , 1000 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_8 != V_7 ) {
F_4 ( L_1 ,
V_12 , V_7 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_15 ,
T_1 V_16 , T_2 V_4 , T_3 * V_6 ,
int V_7 )
{
return F_5 ( V_2 , V_15 , V_4 , V_16 , V_6 , V_7 ) ;
}
static int F_8 ( struct V_17 * V_18 , T_2 V_19 )
{
int V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
F_4 ( L_2 , V_12 , V_20 , V_19 ) ;
return F_7 ( V_18 -> V_22 -> V_2 ,
V_24 ,
( T_1 ) ( V_25 + V_20 ) ,
V_19 ,
NULL ,
0 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_26 ,
int V_27 , T_1 V_28 , T_1 * V_29 )
{
int V_8 = 0 ;
T_1 V_30 ;
T_4 V_31 ;
F_4 ( L_3 , V_12 , V_26 , V_27 ) ;
while ( V_27 ) {
if ( V_27 > 64 )
V_30 = 64 ;
else
V_30 = ( T_1 ) V_27 ;
if ( V_30 > 1 ) {
F_4 ( L_3 , V_12 ,
V_26 , V_30 ) ;
}
V_31 = F_10 ( V_26 ) ;
V_8 = F_1 ( V_2 , V_32 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_30 ) ;
if ( V_8 ) {
F_4 ( L_4 , V_12 , V_8 ) ;
return V_8 ;
}
if ( V_30 > 1 )
F_11 ( V_34 , & V_2 -> V_2 , V_12 ,
V_30 , V_29 ) ;
V_26 += V_30 ;
V_29 += V_30 ;
V_27 -= V_30 ;
}
return V_8 ;
}
static int F_12 ( struct V_1 * V_2 , int V_26 ,
int V_27 , T_1 * V_29 )
{
return F_9 ( V_2 , V_26 , V_27 ,
V_35 , V_29 ) ;
}
static int F_13 ( struct V_36 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_27 ; V_37 ++ ) {
V_8 = F_1 ( V_22 -> V_22 -> V_2 ,
V_32 , V_22 -> V_38 ,
( T_2 ) ( V_26 + V_37 ) , & V_29 [ V_37 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( L_5 ,
V_12 , V_26 , V_27 ) ;
F_11 ( V_34 , & V_22 -> V_22 -> V_2 -> V_2 ,
V_12 , V_27 , V_29 ) ;
V_22 -> V_39 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_36 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_37 ;
T_3 * V_40 ;
if ( ! V_22 -> V_39 ) {
V_40 = F_15 ( 1 , V_41 ) ;
if ( ! V_40 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 ,
L_6 , V_12 ) ;
return - V_42 ;
}
V_8 = F_13 ( V_22 , 0 , 1 , V_40 ) ;
F_17 ( V_40 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_37 = 0 ; V_37 < V_27 ; ++ V_37 ) {
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_43 , V_29 [ V_37 ] ,
( T_2 ) ( V_37 + V_26 ) , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( L_7 ,
V_12 , V_26 , V_27 ) ;
F_11 ( V_34 , & V_22 -> V_22 -> V_2 -> V_2 ,
V_12 , V_27 , V_29 ) ;
return V_8 ;
}
static int F_18 ( struct V_36 * V_22 ,
int V_26 , int V_27 , T_1 V_28 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_44 ;
T_4 V_31 ;
V_44 = V_45 -
( V_26 & ( V_45 - 1 ) ) ;
if ( V_44 > V_27 )
V_44 = V_27 ;
F_4 ( L_8 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_34 , & V_22 -> V_22 -> V_2 -> V_2 ,
V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_43 , ( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_4 ( L_9 , V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_44 ;
V_26 += V_44 ;
V_29 += V_44 ;
while ( V_27 ) {
if ( V_27 > V_45 )
V_44 = V_45 ;
else
V_44 = V_27 ;
F_4 ( L_10 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_34 , & V_22 -> V_22 -> V_2 -> V_2 ,
V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 , V_43 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 , L_11 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_27 -= V_44 ;
V_26 += V_44 ;
V_29 += V_44 ;
}
return V_8 ;
}
static int F_19 ( struct V_46 * V_18 )
{
int V_8 ;
struct V_47 * V_48 ;
T_1 * V_49 ;
int V_50 = 0 ;
V_48 = F_15 ( sizeof( * V_48 ) , V_41 ) ;
if ( ! V_48 ) {
F_16 ( & V_18 -> V_18 -> V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
V_49 = F_15 ( 1 , V_41 ) ;
if ( ! V_49 ) {
F_17 ( V_48 ) ;
return - V_42 ;
}
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 , V_18 -> V_51 ,
sizeof( * V_48 ) , ( void * ) V_48 ) ;
if ( V_8 )
goto V_52;
F_4 ( L_12 , V_12 , V_48 -> V_53 ) ;
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_18 -> V_54 + V_55 , 1 , V_49 ) ;
if ( V_8 )
goto V_52;
F_4 ( L_13 , V_12 , * V_49 ) ;
if ( ( V_48 -> V_53 & 0x80 ) != 0 )
V_50 += 64 ;
if ( ( * V_49 & V_56 ) == 0 )
V_50 += 1 ;
V_52:
F_4 ( L_14 , V_12 , V_50 ) ;
F_17 ( V_49 ) ;
F_17 ( V_48 ) ;
return V_50 ;
}
static void F_20 ( struct V_46 * V_18 , unsigned long V_57 ,
int V_58 )
{
int V_59 ;
struct V_60 * V_61 = F_21 ( & V_18 -> V_18 -> V_18 ) ;
struct V_62 * V_22 = V_18 -> V_18 -> V_22 ;
T_5 V_63 ;
unsigned long V_64 ;
if ( ! V_57 )
V_57 = ( V_65 * V_66 ) / 100 ;
F_22 ( & V_18 -> V_67 , V_64 ) ;
F_23 ( & V_63 , V_68 ) ;
F_24 ( & V_61 -> V_69 , & V_63 ) ;
for (; ; ) {
F_25 ( V_70 ) ;
if ( F_26 ( & V_18 -> V_71 ) == 0
|| V_57 == 0 || F_27 ( V_68 )
|| V_22 -> V_72 )
break;
F_28 ( & V_18 -> V_67 , V_64 ) ;
V_57 = F_29 ( V_57 ) ;
F_22 ( & V_18 -> V_67 , V_64 ) ;
}
F_25 ( V_73 ) ;
F_30 ( & V_61 -> V_69 , & V_63 ) ;
if ( V_58 )
F_31 ( & V_18 -> V_71 ) ;
F_28 ( & V_18 -> V_67 , V_64 ) ;
F_32 ( V_61 ) ;
V_57 += V_74 ;
while ( ( long ) ( V_74 - V_57 ) < 0 && ! F_27 ( V_68 )
&& ! V_22 -> V_72 ) {
if ( ! F_19 ( V_18 ) )
break;
F_33 ( 10 ) ;
}
if ( V_22 -> V_72 )
return;
V_59 = V_18 -> V_59 ;
if ( V_59 == 0 )
V_59 = 50 ;
F_33 ( F_34 ( 1 , F_35 ( 10000 , V_59 ) ) ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_4 ( L_15 ,
V_12 , V_2 -> V_75 -> V_76 . V_77 ) ;
F_4 ( L_16 ,
V_12 , V_2 -> V_75 -> V_76 . V_78 * 2 ) ;
if ( V_2 -> V_75 -> V_76 . V_77 != 1 ) {
F_16 ( & V_2 -> V_2 , L_17 ,
V_12 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_37 ( struct V_36 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 ;
if ( V_22 -> V_80 . V_81 == V_82 ) {
V_8 = F_9 ( V_22 -> V_22 -> V_2 ,
V_26 ,
V_27 ,
V_22 -> V_38 ,
V_29 ) ;
} else {
V_8 = F_13 ( V_22 , V_26 , V_27 ,
V_29 ) ;
}
return V_8 ;
}
static int F_38 ( struct V_36 * V_22 , int V_26 ,
int V_27 , T_1 * V_29 )
{
if ( V_22 -> V_80 . V_81 == V_83 )
return F_14 ( V_22 , V_26 , V_27 ,
V_29 ) ;
if ( V_22 -> V_80 . V_81 == V_82 )
return F_18 ( V_22 , V_26 , V_27 ,
V_22 -> V_38 , V_29 ) ;
return - V_84 ;
}
static int F_39 ( struct V_36 * V_22 ,
int V_85 , struct V_86 * V_87 )
{
int V_26 ;
int V_8 ;
V_26 = 2 ;
do {
V_8 = F_37 ( V_22 ,
V_26 ,
sizeof( struct V_86 ) ,
( T_1 * ) V_87 ) ;
if ( V_8 )
return 0 ;
if ( V_87 -> Type == V_85 )
return V_26 ;
V_26 = V_26 + sizeof( struct V_86 )
+ V_87 -> V_88 ;
} while ( ( V_26 < V_89 ) && V_87 -> Type );
return 0 ;
}
static int F_40 ( struct V_86 * V_87 , T_1 * V_29 )
{
T_2 V_37 ;
T_1 V_90 = 0 ;
for ( V_37 = 0 ; V_37 < V_87 -> V_88 ; V_37 ++ )
V_90 = ( T_1 ) ( V_90 + V_29 [ V_37 ] ) ;
if ( V_90 != V_87 -> V_91 ) {
F_4 ( L_18 , V_12 , V_87 -> V_91 , V_90 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_41 ( struct V_36 * V_22 )
{
struct V_92 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_86 * V_87 ;
int V_26 = 2 ;
T_1 * V_29 ;
T_2 V_93 ;
V_87 = F_15 ( sizeof( * V_87 ) , V_41 ) ;
if ( ! V_87 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
V_29 = F_15 ( V_89 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_19 ,
V_12 ) ;
F_17 ( V_87 ) ;
return - V_42 ;
}
V_8 = F_37 ( V_22 , 0 , 1 , V_29 ) ;
if ( V_8 )
goto V_94;
if ( * V_29 != V_95 && * V_29 != V_96 ) {
F_16 ( V_2 , L_20 , V_12 ) ;
V_8 = - V_79 ;
goto V_94;
}
do {
V_8 = F_37 ( V_22 ,
V_26 ,
sizeof( struct V_86 ) ,
( T_1 * ) V_87 ) ;
if ( V_8 )
break;
if ( ( V_26 + sizeof( struct V_86 ) +
V_87 -> V_88 ) > V_89 ) {
V_8 = - V_79 ;
F_4 ( L_21 , V_12 ) ;
break;
}
F_4 ( L_22 , V_12 , V_87 -> Type ) ;
V_93 = V_87 -> Type & 0x0f ;
if ( V_93 != V_97
&& V_93 != V_98 ) {
V_8 = F_37 ( V_22 , V_26 +
sizeof( struct V_86 ) ,
V_87 -> V_88 , V_29 ) ;
if ( V_8 )
break;
V_8 = F_40 ( V_87 , V_29 ) ;
if ( V_8 )
break;
}
V_26 = V_26 + sizeof( struct V_86 ) +
V_87 -> V_88 ;
} while ( ( V_87 -> Type != V_99 ) &&
( V_26 < V_89 ) );
if ( ( V_87 -> Type != V_99 ) ||
( V_26 > V_89 ) )
V_8 = - V_79 ;
V_94:
F_17 ( V_29 ) ;
F_17 ( V_87 ) ;
return V_8 ;
}
static int F_42 ( struct V_36 * V_22 , T_1 * V_29 )
{
int V_8 ;
int V_26 ;
struct V_86 * V_87 ;
struct V_100 * V_76 ;
V_87 = F_15 ( sizeof( * V_87 ) , V_41 ) ;
if ( ! V_87 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 , L_6 ,
V_12 ) ;
return - V_42 ;
}
V_26 = F_39 ( V_22 , V_99 ,
V_87 ) ;
if ( ! V_26 ) {
F_4 ( L_23 , V_12 ) ;
V_8 = - V_79 ;
goto exit;
}
V_8 = F_37 ( V_22 , V_26 + sizeof( struct V_86 ) ,
V_87 -> V_88 , V_29 ) ;
if ( V_8 )
goto exit;
V_8 = F_40 ( V_87 , V_29 ) ;
V_76 = (struct V_100 * ) V_29 ;
F_4 ( L_24 , V_12 , V_76 -> V_101 ) ;
F_4 ( L_25 , V_12 , V_76 -> V_102 ) ;
F_4 ( L_26 , V_12 , V_76 -> V_103 ) ;
F_4 ( L_27 , V_12 , V_76 -> V_104 ) ;
F_4 ( L_28 , V_12 , V_76 -> V_105 ) ;
F_4 ( L_29 , V_12 , V_76 -> V_106 ) ;
exit:
F_17 ( V_87 ) ;
return V_8 ;
}
static int F_43 ( T_1 * V_107 , struct V_92 * V_2 )
{
T_1 * V_29 ;
int V_108 ;
int V_37 ;
int V_109 ;
T_1 V_90 = 0 ;
struct V_86 * V_110 ;
struct V_111 * V_112 ;
struct V_113 * V_114 ;
const struct V_115 * V_116 ;
const char * V_117 = L_30 ;
V_108 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_113 ) ) ;
V_29 = F_15 ( V_108 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
memset ( V_29 , 0xff , V_108 ) ;
V_109 = F_44 ( & V_116 , V_117 , V_2 ) ;
if ( V_109 ) {
F_45 ( V_118 L_31 ,
V_117 , V_109 ) ;
F_17 ( V_29 ) ;
return V_109 ;
}
V_119 = V_116 -> V_6 [ 0 ] ;
V_120 = V_116 -> V_6 [ 1 ] ;
V_121 = V_116 -> V_6 [ 2 ] | ( V_116 -> V_6 [ 3 ] << 8 ) ;
V_114 = (struct V_113 * ) V_29 ;
V_114 -> V_122 = V_119 ;
V_114 -> V_123 = V_120 ;
V_112 = (struct V_111 * ) & V_116 -> V_6 [ 4 ] ;
memcpy ( V_29 + sizeof( struct V_113 ) ,
& V_116 -> V_6 [ 4 + sizeof( struct V_111 ) ] ,
F_46 ( V_112 -> V_124 ) ) ;
F_47 ( V_116 ) ;
for ( V_37 = 0 ; V_37 < V_108 ; V_37 ++ ) {
V_90 = ( T_1 ) ( V_90 + V_29 [ V_37 ] ) ;
}
F_17 ( V_29 ) ;
V_110 = (struct V_86 * ) V_107 ;
V_114 = (struct V_113 * ) V_110 -> V_125 ;
V_110 -> Type = V_126 ;
V_110 -> V_88 = ( T_2 ) V_108 ;
V_110 -> V_91 = V_90 ;
V_114 -> V_122 = V_119 ;
V_114 -> V_123 = V_120 ;
return 0 ;
}
static int F_48 ( struct V_36 * V_22 )
{
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_41 ) ;
if ( ! V_6 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 ,
L_6 , V_12 ) ;
return - V_42 ;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_127 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( L_32 , V_12 , V_8 ) ;
else
F_4 ( L_33 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_95 || * V_6 == V_96 ) ) {
F_4 ( L_34 , V_12 ) ;
V_22 -> V_38 = V_127 ;
goto V_94;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_128 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( L_35 , V_12 , V_8 ) ;
else
F_4 ( L_33 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_95 || * V_6 == V_96 ) ) {
F_4 ( L_36 , V_12 ) ;
V_22 -> V_38 = V_128 ;
goto V_94;
}
F_4 ( L_37 , V_12 ) ;
V_22 -> V_38 = V_127 ;
V_8 = - V_79 ;
V_94:
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_49 ( struct V_62 * V_22 , void * V_29 ,
int V_27 , int * V_129 )
{
int V_8 ;
V_8 = F_50 ( V_22 -> V_2 ,
F_51 ( V_22 -> V_2 ,
V_22 -> V_18 [ 0 ] -> V_130 ) ,
V_29 , V_27 , V_129 , 1000 ) ;
return V_8 ;
}
static int F_52 ( struct V_36 * V_22 , T_1 * V_131 ,
int V_132 )
{
int V_8 = 0 ;
int V_133 ;
int V_134 ;
int V_135 ;
for ( V_133 = 0 ; V_133 < V_132 ; ) {
V_134 = V_132 - V_133 ;
if ( V_134 > V_136 )
V_134 = V_136 ;
V_8 = F_49 ( V_22 -> V_22 , & V_131 [ V_133 ] ,
V_134 , & V_135 ) ;
if ( V_8 )
break;
V_133 += V_135 ;
}
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_54 ( struct V_100 * V_76 )
{
return F_55 ( V_76 -> V_103 ) ;
}
static int F_56 ( struct V_36 * V_22 )
{
struct V_92 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_100 * V_137 ;
struct V_138 * V_139 ;
int V_140 ;
int V_141 ;
V_22 -> V_80 . V_142 = V_143 ;
V_22 -> V_38 = V_127 ;
V_8 = F_36 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_139 = & V_22 -> V_22 -> V_139 -> V_144 -> V_76 ;
if ( ! V_139 ) {
F_16 ( V_2 , L_38 , V_12 ) ;
return - V_79 ;
}
if ( V_139 -> V_145 > 1 )
V_22 -> V_80 . V_81 = V_82 ;
else
V_22 -> V_80 . V_81 = V_146 ;
if ( V_22 -> V_80 . V_81 == V_82 ) {
struct V_86 * V_87 ;
F_4 ( L_39 , V_12 ) ;
V_8 = F_41 ( V_22 ) ;
if ( V_8 ) {
F_4 ( L_40 , V_12 ) ;
return V_8 ;
}
V_137 = F_15 ( sizeof( * V_137 ) , V_41 ) ;
if ( ! V_137 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
return - V_42 ;
}
V_8 = F_42 ( V_22 , ( T_1 * ) V_137 ) ;
if ( V_8 ) {
F_17 ( V_137 ) ;
return V_8 ;
}
if ( ! V_147 && F_54 ( V_137 ) < 2 ) {
F_4 ( L_42 ,
V_12 , F_54 ( V_137 ) ) ;
F_17 ( V_137 ) ;
return - V_84 ;
}
V_87 = F_15 ( sizeof( * V_87 ) , V_41 ) ;
if ( ! V_87 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_26 = F_39 ( V_22 ,
V_97 , V_87 ) ;
if ( V_26 != 0 ) {
struct V_113 * V_148 ;
T_3 * V_149 ;
F_4 ( L_43 ,
V_12 ) ;
V_148 = F_15 ( sizeof( * V_148 ) ,
V_41 ) ;
if ( ! V_148 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_8 = F_37 ( V_22 , V_26 +
sizeof( struct V_86 ) ,
sizeof( struct V_113 ) ,
( T_1 * ) V_148 ) ;
if ( V_8 ) {
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
V_140 = ( V_148 -> V_122 << 8 ) +
( V_148 -> V_123 ) ;
V_141 = ( V_119 << 8 ) +
( V_120 ) ;
F_4 ( L_44 ,
V_12 ,
V_148 -> V_122 ,
V_148 -> V_123 ,
V_119 ,
V_120 ) ;
if ( V_140 < V_141 ) {
F_4 ( L_45 ,
V_12 ,
V_148 -> V_122 ,
V_148 -> V_123 ,
V_119 ,
V_120 ) ;
V_149 = F_15 ( 1 , V_41 ) ;
if ( ! V_149 ) {
F_16 ( V_2 , L_41 ,
V_12 ) ;
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
* V_149 = V_126 ;
V_8 = F_38 ( V_22 , V_26 ,
sizeof( * V_149 ) , V_149 ) ;
if ( V_8 ) {
F_17 ( V_149 ) ;
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
V_8 = F_37 ( V_22 ,
V_26 ,
sizeof( * V_149 ) ,
V_149 ) ;
if ( V_8 ) {
F_17 ( V_149 ) ;
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
if ( * V_149 != V_126 ) {
F_16 ( V_2 ,
L_46 ,
V_12 ) ;
F_17 ( V_149 ) ;
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_79 ;
}
F_4 ( L_47 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_150 ,
0 , 0 , NULL , 0 ) ;
F_4 ( L_48 ,
V_12 , V_8 ) ;
F_17 ( V_149 ) ;
F_17 ( V_148 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_79 ;
}
F_17 ( V_148 ) ;
}
else if ( ( V_26 = F_39 ( V_22 , V_126 , V_87 ) ) != 0 ) {
#define F_57 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_107 ;
T_1 * V_151 ;
V_107 = F_15 ( F_57 , V_41 ) ;
if ( ! V_107 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_151 = F_15 ( F_57 , V_41 ) ;
if ( ! V_151 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_107 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
F_4 ( L_49 ,
V_12 ) ;
V_8 = F_43 ( V_107 , V_2 ) ;
if ( V_8 ) {
F_17 ( V_151 ) ;
F_17 ( V_107 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_84 ;
}
V_8 = F_38 ( V_22 ,
V_26 ,
F_57 ,
V_107 ) ;
if ( V_8 ) {
F_17 ( V_151 ) ;
F_17 ( V_107 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_84 ;
}
V_8 = F_37 ( V_22 , V_26 ,
F_57 , V_151 ) ;
if ( V_8 ) {
F_4 ( L_50 , V_12 ) ;
F_17 ( V_151 ) ;
F_17 ( V_107 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
if ( memcmp ( V_151 , V_107 , F_57 ) ) {
F_4 ( L_51 ,
V_12 ) ;
F_17 ( V_151 ) ;
F_17 ( V_107 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return - V_84 ;
}
F_17 ( V_151 ) ;
F_17 ( V_107 ) ;
F_4 ( L_52 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_152 , 0 , 0 , NULL , 0 ) ;
F_4 ( L_53 , V_12 , V_8 ) ;
if ( V_8 ) {
F_16 ( V_2 ,
L_54 ,
V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
}
F_17 ( V_87 ) ;
F_17 ( V_137 ) ;
return 0 ;
}
F_4 ( L_55 , V_12 ) ;
V_8 = F_53 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_46 ( V_22 -> V_22 -> V_2 -> V_153 . V_154 )
!= V_155 ) {
F_4 ( L_56 , V_12 ,
F_46 ( V_22 -> V_22 -> V_2 -> V_153 . V_154 ) ) ;
V_22 -> V_38 = V_127 ;
goto V_156;
}
if ( F_48 ( V_22 ) )
goto V_156;
if ( ! F_41 ( V_22 ) ) {
struct V_111 * V_107 ;
int V_37 ;
T_1 V_90 = 0 ;
T_1 * V_29 ;
int V_108 ;
int V_109 ;
const struct V_115 * V_116 ;
const char * V_117 = L_30 ;
V_137 = F_15 ( sizeof( * V_137 ) , V_41 ) ;
if ( ! V_137 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
return - V_42 ;
}
V_8 = F_42 ( V_22 , ( T_1 * ) V_137 ) ;
if ( V_8 ) {
F_17 ( V_137 ) ;
goto V_156;
}
if ( ! V_147 && F_54 ( V_137 ) < 2 ) {
F_4 ( L_42 ,
V_12 , F_54 ( V_137 ) ) ;
F_17 ( V_137 ) ;
goto V_156;
}
F_17 ( V_137 ) ;
V_108 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_111 ) ) ;
V_29 = F_15 ( V_108 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
memset ( V_29 , 0xff , V_108 ) ;
V_109 = F_44 ( & V_116 , V_117 , V_2 ) ;
if ( V_109 ) {
F_45 ( V_118 L_31 ,
V_117 , V_109 ) ;
F_17 ( V_29 ) ;
return V_109 ;
}
memcpy ( V_29 , & V_116 -> V_6 [ 4 ] , V_116 -> V_7 - 4 ) ;
F_47 ( V_116 ) ;
for ( V_37 = sizeof( struct V_111 ) ;
V_37 < V_108 ; V_37 ++ ) {
V_90 = ( T_1 ) ( V_90 + V_29 [ V_37 ] ) ;
}
V_107 = (struct V_111 * ) V_29 ;
V_107 -> V_124 = F_58 ( ( T_2 ) ( V_108 -
sizeof( struct V_111 ) ) ) ;
V_107 -> V_91 = V_90 ;
F_4 ( L_57 ,
V_12 ) ;
V_8 = F_52 ( V_22 , V_29 , V_108 ) ;
F_17 ( V_29 ) ;
if ( V_8 ) {
F_4 ( L_58 ,
V_12 ) ;
return V_8 ;
}
V_22 -> V_80 . V_81 = V_157 ;
F_4 ( L_59 ,
V_12 ) ;
return - V_79 ;
}
V_156:
F_4 ( L_60 , V_12 ) ;
V_22 -> V_80 . V_81 = V_83 ;
return 0 ;
}
static int F_59 ( struct V_46 * V_18 , int V_158 , int V_159 )
{
int V_20 = V_18 -> V_18 -> V_21 - V_18 -> V_18 -> V_22 -> V_23 ;
V_159 = ! ! V_159 ;
return F_7 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_158 , ( T_1 ) ( V_25 + V_20 ) ,
V_159 , NULL , 0 ) ;
}
static int F_60 ( struct V_46 * V_18 , T_1 V_160 )
{
int V_8 = 0 ;
F_4 ( L_61 , V_12 , V_160 ) ;
V_8 = F_59 ( V_18 , V_161 , V_160 & V_162 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_59 ( V_18 , V_163 , V_160 & V_164 ) ;
if ( V_8 )
return V_8 ;
return F_59 ( V_18 , V_165 , V_160 & V_166 ) ;
}
static T_1 F_61 ( T_1 V_167 )
{
T_1 V_49 = 0 ;
#define F_62 ( T_6 , T_7 ) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
F_62 (UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
F_62 (UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
F_62 (UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
F_62 (UMP_UART_LSR_BR_MASK, LSR_BREAK)
F_62 (UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
F_62 (UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef F_62
return V_49 ;
}
static void F_63 ( struct V_46 * V_168 , T_1 V_169 )
{
struct V_170 * V_171 ;
struct V_60 * V_61 ;
F_4 ( L_62 , V_12 , V_169 ) ;
if ( V_169 & ( V_172 | V_173 |
V_174 | V_175 ) ) {
V_171 = & V_168 -> V_171 ;
if ( V_169 & V_172 )
V_171 -> V_176 ++ ;
if ( V_169 & V_173 )
V_171 -> V_177 ++ ;
if ( V_169 & V_175 )
V_171 -> V_178 ++ ;
if ( V_169 & V_174 )
V_171 -> V_179 ++ ;
F_64 ( & V_168 -> V_180 ) ;
}
V_168 -> V_181 = V_169 & 0xf0 ;
V_61 = F_21 ( & V_168 -> V_18 -> V_18 ) ;
if ( V_61 && F_65 ( V_61 ) ) {
if ( V_169 & V_182 ) {
V_61 -> V_183 = 0 ;
F_66 ( V_61 ) ;
} else {
V_61 -> V_183 = 1 ;
}
}
F_32 ( V_61 ) ;
}
static void F_67 ( struct V_46 * V_168 , int V_184 ,
T_1 V_49 , T_1 V_6 )
{
struct V_170 * V_171 ;
T_1 V_185 = ( T_1 ) ( V_49 & ( T_1 ) ( V_186 | V_187 |
V_188 | V_189 ) ) ;
struct V_60 * V_61 ;
F_4 ( L_62 , V_12 , V_185 ) ;
V_168 -> V_190 = V_49 ;
if ( V_185 & V_189 )
V_185 &= ( T_1 ) ( V_186 | V_189 ) ;
if ( V_184 ) {
V_61 = F_21 ( & V_168 -> V_18 -> V_18 ) ;
if ( V_61 ) {
F_68 ( & V_168 -> V_18 -> V_2 , V_61 , & V_6 , 1 ) ;
F_32 ( V_61 ) ;
}
}
V_171 = & V_168 -> V_171 ;
if ( V_185 & V_189 )
V_171 -> V_191 ++ ;
if ( V_185 & V_186 )
V_171 -> V_192 ++ ;
if ( V_185 & V_187 )
V_171 -> V_193 ++ ;
if ( V_185 & V_188 )
V_171 -> V_194 ++ ;
}
static void F_69 ( struct V_195 * V_195 )
{
struct V_36 * V_196 = V_195 -> V_197 ;
struct V_17 * V_18 ;
struct V_46 * V_168 ;
unsigned char * V_6 = V_195 -> V_198 ;
int V_27 = V_195 -> V_199 ;
int V_20 ;
int V_200 ;
int V_201 ;
T_1 V_49 ;
T_1 V_169 ;
int V_8 = V_195 -> V_8 ;
F_4 ( L_63 , V_12 ) ;
switch ( V_8 ) {
case 0 :
break;
case - V_202 :
case - V_203 :
case - V_204 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_195 -> V_2 -> V_2 , L_65
L_66 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( L_67 , V_12 ) ;
goto exit;
}
F_11 ( V_34 , & V_196 -> V_22 -> V_2 -> V_2 ,
V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( L_68 ,
V_12 , V_27 ) ;
goto exit;
}
V_20 = F_70 ( V_6 [ 0 ] ) ;
V_200 = F_71 ( V_6 [ 0 ] ) ;
F_4 ( L_69 ,
V_12 , V_20 , V_200 , V_6 [ 1 ] ) ;
V_18 = V_196 -> V_22 -> V_18 [ V_20 ] ;
V_168 = F_72 ( V_18 ) ;
if ( ! V_168 ) {
F_4 ( L_70 , V_12 ) ;
return;
}
switch ( V_200 ) {
case V_205 :
V_49 = F_61 ( V_6 [ 1 ] ) ;
if ( V_49 & V_206 ) {
F_4 ( L_71 ,
V_12 , V_20 , V_49 ) ;
V_168 -> V_207 = 1 ;
V_168 -> V_208 = V_49 ;
} else {
F_4 ( L_72 ,
V_12 , V_20 , V_49 ) ;
F_67 ( V_168 , 0 , V_49 , 0 ) ;
}
break;
case V_209 :
V_169 = V_6 [ 1 ] ;
F_4 ( L_73 ,
V_12 , V_20 , V_169 ) ;
F_63 ( V_168 , V_169 ) ;
break;
default:
F_16 ( & V_195 -> V_2 -> V_2 ,
L_74 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_201 = F_73 ( V_195 , V_210 ) ;
if ( V_201 )
F_16 ( & V_195 -> V_2 -> V_2 ,
L_75 ,
V_12 , V_201 ) ;
}
static void F_74 ( struct V_195 * V_195 )
{
struct V_46 * V_168 = V_195 -> V_197 ;
unsigned char * V_6 = V_195 -> V_198 ;
struct V_60 * V_61 ;
int V_201 = 0 ;
int V_20 ;
int V_8 = V_195 -> V_8 ;
F_4 ( L_63 , V_12 ) ;
switch ( V_8 ) {
case 0 :
break;
case - V_202 :
case - V_203 :
case - V_204 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_195 -> V_2 -> V_2 ,
L_76 ,
V_12 , V_8 ) ;
}
if ( V_8 == - V_211 )
goto exit;
if ( V_8 ) {
F_16 ( & V_195 -> V_2 -> V_2 , L_77 , V_12 ) ;
return;
}
V_20 = V_168 -> V_18 -> V_21 - V_168 -> V_18 -> V_22 -> V_23 ;
if ( V_168 -> V_207 ) {
V_168 -> V_207 = 0 ;
F_4 ( L_78 ,
V_12 , V_20 , V_168 -> V_208 , * V_6 ) ;
F_67 ( V_168 , 1 , V_168 -> V_208 , * V_6 ) ;
-- V_195 -> V_199 ;
++ V_6 ;
}
V_61 = F_21 ( & V_168 -> V_18 -> V_18 ) ;
if ( V_61 && V_195 -> V_199 ) {
F_11 ( V_34 , & V_168 -> V_18 -> V_2 ,
V_12 , V_195 -> V_199 , V_6 ) ;
if ( V_168 -> V_212 )
F_4 ( L_79 ,
V_12 ) ;
else
F_68 ( & V_168 -> V_18 -> V_2 , V_61 , V_6 ,
V_195 -> V_199 ) ;
V_168 -> V_171 . V_213 += V_195 -> V_199 ;
}
F_32 ( V_61 ) ;
exit:
F_75 ( & V_168 -> V_67 ) ;
if ( V_168 -> V_214 == V_215 )
V_201 = F_73 ( V_195 , V_210 ) ;
else if ( V_168 -> V_214 == V_216 )
V_168 -> V_214 = V_217 ;
F_76 ( & V_168 -> V_67 ) ;
if ( V_201 )
F_16 ( & V_195 -> V_2 -> V_2 ,
L_75 ,
V_12 , V_201 ) ;
}
static void F_68 ( struct V_92 * V_2 , struct V_60 * V_61 ,
unsigned char * V_6 , int V_27 )
{
int V_218 ;
V_218 = F_77 ( V_61 , V_6 , V_27 ) ;
if ( V_218 < V_27 )
F_16 ( V_2 , L_80 ,
V_12 , V_27 - V_218 ) ;
F_78 ( V_61 ) ;
}
static void F_79 ( struct V_195 * V_195 )
{
struct V_17 * V_18 = V_195 -> V_197 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_8 = V_195 -> V_8 ;
struct V_60 * V_61 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
V_168 -> V_219 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_202 :
case - V_203 :
case - V_204 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_80 ( V_18 , L_82
L_83 , V_12 , V_8 ) ;
}
V_61 = F_21 ( & V_18 -> V_18 ) ;
F_81 ( V_61 ) ;
F_32 ( V_61 ) ;
}
static int F_82 ( struct V_60 * V_61 , struct V_17 * V_18 )
{
struct V_46 * V_168 = F_72 ( V_18 ) ;
struct V_36 * V_196 ;
struct V_1 * V_2 ;
struct V_195 * V_195 ;
int V_20 ;
int V_8 ;
T_8 V_220 ;
T_3 V_221 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return - V_79 ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
switch ( V_20 ) {
case 0 :
V_168 -> V_54 = V_222 ;
V_168 -> V_51 = V_223 ;
break;
case 1 :
V_168 -> V_54 = V_224 ;
V_168 -> V_51 = V_225 ;
break;
default:
F_16 ( & V_18 -> V_2 , L_84 ) ;
return - V_79 ;
}
F_4 ( L_85 ,
V_12 , V_20 , V_168 -> V_54 ,
V_168 -> V_51 ) ;
V_2 = V_18 -> V_22 -> V_2 ;
memset ( & ( V_168 -> V_171 ) , 0x00 , sizeof( V_168 -> V_171 ) ) ;
F_83 ( & V_168 -> V_180 ) ;
V_8 = F_59 ( V_168 , V_165 , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_86 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_61 )
F_84 ( V_61 , V_18 , V_61 -> V_226 ) ;
V_221 = 2 ;
V_168 -> V_227 =
F_34 ( 20 , ( ( V_221 * 3 ) / 2 ) ) ;
V_220 = ( T_3 ) ( V_228 |
V_229 |
( V_221 << 2 ) ) ;
F_4 ( L_87 , V_12 ) ;
V_8 = F_7 ( V_2 , V_230 ,
( T_3 ) ( V_25 + V_20 ) , V_220 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_88 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_231 ,
( T_3 ) ( V_25 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_89 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_232 | V_233 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_90 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_234 , 0 ,
( T_2 ) ( V_25 + V_20 ) ,
& V_168 -> V_181 , 1 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_91 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( L_92 , V_168 -> V_181 ) ;
V_168 -> V_235 = V_164 | V_162 ;
F_4 ( L_93 , V_168 -> V_235 ) ;
V_196 = V_168 -> V_196 ;
if ( F_85 ( & V_196 -> V_236 ) )
return - V_237 ;
if ( V_196 -> V_238 == 0 ) {
V_195 = V_196 -> V_22 -> V_18 [ 0 ] -> V_239 ;
if ( ! V_195 ) {
F_16 ( & V_18 -> V_2 ,
L_94 ,
V_12 ) ;
V_8 = - V_84 ;
goto V_240;
}
V_195 -> V_197 = V_196 ;
V_8 = F_73 ( V_195 , V_41 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_95 ,
V_12 , V_8 ) ;
goto V_240;
}
}
F_86 ( V_2 , V_18 -> V_241 -> V_242 ) ;
F_86 ( V_2 , V_18 -> V_243 -> V_242 ) ;
V_195 = V_18 -> V_243 ;
if ( ! V_195 ) {
F_16 ( & V_18 -> V_2 , L_96 ,
V_12 ) ;
V_8 = - V_84 ;
goto V_244;
}
V_168 -> V_214 = V_215 ;
V_195 -> V_197 = V_168 ;
V_8 = F_73 ( V_195 , V_41 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_97 ,
V_12 , V_8 ) ;
goto V_244;
}
++ V_196 -> V_238 ;
F_4 ( L_98 , V_12 ) ;
goto V_240;
V_244:
if ( V_168 -> V_196 -> V_238 == 0 )
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_239 ) ;
V_240:
F_88 ( & V_196 -> V_236 ) ;
return V_8 ;
}
static void F_89 ( struct V_17 * V_18 )
{
struct V_36 * V_196 ;
struct V_46 * V_168 ;
struct V_62 * V_22 = V_18 -> V_22 ;
int V_20 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
V_196 = F_90 ( V_18 -> V_22 ) ;
V_168 = F_72 ( V_18 ) ;
if ( V_196 == NULL || V_168 == NULL )
return;
V_168 -> V_212 = 1 ;
F_20 ( V_168 , ( V_65 * V_245 ) / 100 , 1 ) ;
F_87 ( V_18 -> V_243 ) ;
F_87 ( V_18 -> V_241 ) ;
V_168 -> V_219 = 0 ;
F_4 ( L_99 , V_12 ) ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
F_91 ( & V_22 -> V_246 ) ;
if ( ! V_22 -> V_72 ) {
F_7 ( V_22 -> V_2 ,
V_247 ,
( T_1 ) ( V_25 + V_20 ) ,
0 ,
NULL ,
0 ) ;
}
F_88 ( & V_22 -> V_246 ) ;
F_91 ( & V_196 -> V_236 ) ;
-- V_168 -> V_196 -> V_238 ;
if ( V_168 -> V_196 -> V_238 <= 0 ) {
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_239 ) ;
V_168 -> V_196 -> V_238 = 0 ;
}
F_88 ( & V_196 -> V_236 ) ;
V_168 -> V_212 = 0 ;
F_4 ( L_98 , V_12 ) ;
}
static int F_92 ( struct V_60 * V_61 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_248 )
{
struct V_46 * V_168 = F_72 ( V_18 ) ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_248 == 0 ) {
F_4 ( L_100 , V_12 ) ;
return 0 ;
}
if ( V_168 == NULL )
return - V_79 ;
if ( V_168 -> V_212 == 1 )
return - V_79 ;
V_248 = F_93 ( & V_168 -> V_71 , V_6 , V_248 ,
& V_168 -> V_67 ) ;
F_81 ( V_61 ) ;
return V_248 ;
}
static void F_81 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
int V_248 , V_250 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
unsigned long V_64 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
if ( V_168 -> V_219 ) {
F_28 ( & V_168 -> V_67 , V_64 ) ;
return;
}
V_248 = F_94 ( & V_168 -> V_71 ,
V_18 -> V_241 -> V_198 ,
V_18 -> V_251 ) ;
if ( V_248 == 0 ) {
F_28 ( & V_168 -> V_67 , V_64 ) ;
return;
}
V_168 -> V_219 = 1 ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
F_11 ( V_34 , & V_18 -> V_2 , V_12 , V_248 ,
V_18 -> V_241 -> V_198 ) ;
V_18 -> V_241 -> V_252 = V_248 ;
V_250 = F_73 ( V_18 -> V_241 , V_210 ) ;
if ( V_250 ) {
F_80 ( V_18 ,
L_101 ,
V_12 , V_250 ) ;
V_168 -> V_219 = 0 ;
} else
V_168 -> V_171 . V_253 += V_248 ;
if ( V_61 )
F_66 ( V_61 ) ;
}
static int F_95 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_254 = 0 ;
unsigned long V_64 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return 0 ;
if ( V_168 -> V_212 == 1 )
return 0 ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
V_254 = F_96 ( & V_168 -> V_71 ) ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
F_4 ( L_102 , V_12 , V_254 ) ;
return V_254 ;
}
static int F_97 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_255 = 0 ;
unsigned long V_64 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return 0 ;
if ( V_168 -> V_212 == 1 )
return 0 ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
V_255 = F_26 ( & V_168 -> V_71 ) ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
F_4 ( L_102 , V_12 , V_255 ) ;
return V_255 ;
}
static void F_98 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_8 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return;
if ( F_99 ( V_61 ) ) {
unsigned char V_256 = F_100 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_256 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_103 , V_12 , V_8 ) ;
}
}
if ( F_65 ( V_61 ) )
F_101 ( V_168 ) ;
}
static void F_102 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_8 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return;
if ( F_99 ( V_61 ) ) {
unsigned char V_257 = F_103 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_257 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_104 , V_12 , V_8 ) ;
}
}
if ( F_65 ( V_61 ) ) {
V_8 = F_104 ( V_168 ) ;
if ( V_8 )
F_16 ( & V_18 -> V_2 ,
L_105 ,
V_12 , V_8 ) ;
}
}
static void F_101 ( struct V_46 * V_168 )
{
unsigned long V_64 ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
if ( V_168 -> V_214 == V_215 )
V_168 -> V_214 = V_216 ;
V_168 -> V_235 &= ~ V_164 ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
}
static int F_104 ( struct V_46 * V_168 )
{
struct V_195 * V_195 ;
int V_8 = 0 ;
unsigned long V_64 ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
if ( V_168 -> V_214 == V_217 ) {
V_195 = V_168 -> V_18 -> V_243 ;
V_8 = F_73 ( V_195 , V_210 ) ;
}
V_168 -> V_214 = V_215 ;
V_168 -> V_235 |= V_164 ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
return V_8 ;
}
static void F_105 ( struct V_60 * V_61 ,
struct V_46 * V_168 , struct V_258 * V_259 )
{
struct V_260 * V_75 ;
int V_261 ;
unsigned V_262 ;
int V_8 ;
int V_20 = V_168 -> V_18 -> V_21 -
V_168 -> V_18 -> V_22 -> V_23 ;
F_4 ( L_81 , V_12 , V_168 -> V_18 -> V_21 ) ;
V_75 = F_15 ( sizeof ( * V_75 ) , V_41 ) ;
if ( ! V_75 ) {
* V_61 -> V_226 = * V_259 ;
F_16 ( & V_168 -> V_18 -> V_2 , L_6 ,
V_12 ) ;
return;
}
V_262 = V_61 -> V_226 -> V_263 ;
V_75 -> V_264 = 0 ;
V_75 -> V_264 |= V_265 ;
V_75 -> V_264 |= V_266 ;
V_75 -> V_267 = ( T_1 ) ( V_168 -> V_267 ) ;
switch ( V_262 & V_268 ) {
case V_269 :
V_75 -> V_270 = V_271 ;
F_4 ( L_106 , V_12 ) ;
break;
case V_272 :
V_75 -> V_270 = V_273 ;
F_4 ( L_107 , V_12 ) ;
break;
case V_274 :
V_75 -> V_270 = V_275 ;
F_4 ( L_108 , V_12 ) ;
break;
default:
case V_276 :
V_75 -> V_270 = V_277 ;
F_4 ( L_109 , V_12 ) ;
break;
}
if ( V_262 & V_278 ) {
if ( V_262 & V_279 ) {
V_75 -> V_264 |= V_280 ;
V_75 -> V_281 = V_282 ;
F_4 ( L_110 , V_12 ) ;
} else {
V_75 -> V_264 |= V_280 ;
V_75 -> V_281 = V_283 ;
F_4 ( L_111 , V_12 ) ;
}
} else {
V_75 -> V_281 = V_284 ;
F_4 ( L_112 , V_12 ) ;
}
if ( V_262 & V_285 ) {
V_75 -> V_286 = V_287 ;
F_4 ( L_113 , V_12 ) ;
} else {
V_75 -> V_286 = V_288 ;
F_4 ( L_114 , V_12 ) ;
}
if ( V_262 & V_289 ) {
V_75 -> V_264 |= V_290 ;
V_75 -> V_264 |= V_291 ;
F_4 ( L_115 , V_12 ) ;
} else {
F_4 ( L_116 , V_12 ) ;
V_61 -> V_183 = 0 ;
F_104 ( V_168 ) ;
}
V_75 -> V_292 = F_103 ( V_61 ) ;
V_75 -> V_293 = F_100 ( V_61 ) ;
if ( F_99 ( V_61 ) ) {
V_75 -> V_264 |= V_294 ;
F_4 ( L_117 ,
V_12 , V_75 -> V_292 , V_75 -> V_293 ) ;
} else
F_4 ( L_118 , V_12 ) ;
if ( F_106 ( V_61 ) ) {
V_75 -> V_264 |= V_295 ;
F_4 ( L_119 ,
V_12 , V_75 -> V_292 , V_75 -> V_293 ) ;
} else
F_4 ( L_120 , V_12 ) ;
V_61 -> V_226 -> V_263 &= ~ V_296 ;
V_261 = F_107 ( V_61 ) ;
if ( ! V_261 ) {
V_261 = 9600 ;
} else
F_108 ( V_61 , V_261 , V_261 ) ;
V_168 -> V_59 = V_261 ;
V_75 -> V_297 = ( T_2 ) ( ( 461550L + V_261 / 2 ) / V_261 ) ;
F_4 ( L_121 , V_12 , V_261 ,
V_75 -> V_297 ) ;
F_4 ( L_122 , ( int ) ( 461550L / V_75 -> V_297 ) ) ;
F_4 ( L_123 , V_75 -> V_264 ) ;
F_4 ( L_124 , V_75 -> V_270 ) ;
F_4 ( L_125 , V_75 -> V_281 ) ;
F_4 ( L_126 , V_75 -> V_286 ) ;
F_4 ( L_127 , V_75 -> V_292 ) ;
F_4 ( L_128 , V_75 -> V_293 ) ;
F_4 ( L_129 , V_75 -> V_267 ) ;
F_109 ( & V_75 -> V_264 ) ;
F_109 ( & V_75 -> V_297 ) ;
V_8 = F_7 ( V_168 -> V_18 -> V_22 -> V_2 , V_298 ,
( T_1 ) ( V_25 + V_20 ) ,
0 , ( T_1 * ) V_75 , sizeof( * V_75 ) ) ;
if ( V_8 )
F_4 ( L_130 ,
V_12 , V_8 ) ;
F_17 ( V_75 ) ;
}
static void F_84 ( struct V_60 * V_61 ,
struct V_17 * V_18 , struct V_258 * V_259 )
{
struct V_46 * V_168 = F_72 ( V_18 ) ;
unsigned int V_262 ;
V_262 = V_61 -> V_226 -> V_263 ;
F_4 ( L_131 , V_12 ,
V_61 -> V_226 -> V_263 , V_61 -> V_226 -> V_299 ) ;
F_4 ( L_132 , V_12 ,
V_259 -> V_263 , V_259 -> V_299 ) ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_168 == NULL )
return;
F_105 ( V_61 , V_168 , V_259 ) ;
}
static int F_110 ( struct V_60 * V_61 ,
unsigned int V_300 , unsigned int V_301 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
unsigned int V_160 ;
unsigned long V_64 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
V_160 = V_168 -> V_235 ;
if ( V_300 & V_302 )
V_160 |= V_164 ;
if ( V_300 & V_303 )
V_160 |= V_162 ;
if ( V_300 & V_304 )
V_160 |= V_166 ;
if ( V_301 & V_302 )
V_160 &= ~ V_164 ;
if ( V_301 & V_303 )
V_160 &= ~ V_162 ;
if ( V_301 & V_304 )
V_160 &= ~ V_166 ;
V_168 -> V_235 = V_160 ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
F_60 ( V_168 , V_160 ) ;
return 0 ;
}
static int F_111 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
unsigned int V_250 = 0 ;
unsigned int V_169 ;
unsigned int V_160 ;
unsigned long V_64 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_168 -> V_67 , V_64 ) ;
V_169 = V_168 -> V_181 ;
V_160 = V_168 -> V_235 ;
V_250 = ( ( V_160 & V_162 ) ? V_303 : 0 )
| ( ( V_160 & V_164 ) ? V_302 : 0 )
| ( ( V_169 & V_182 ) ? V_305 : 0 )
| ( ( V_169 & V_306 ) ? V_307 : 0 )
| ( ( V_169 & V_308 ) ? V_309 : 0 )
| ( ( V_169 & V_310 ) ? V_311 : 0 ) ;
F_4 ( L_133 , V_12 , V_250 ) ;
F_28 ( & V_168 -> V_67 , V_64 ) ;
return V_250 ;
}
static int F_112 ( struct V_60 * V_61 ,
struct V_312 * V_171 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
struct V_170 * V_313 = & V_168 -> V_171 ;
V_171 -> V_176 = V_313 -> V_176 ;
V_171 -> V_177 = V_313 -> V_177 ;
V_171 -> V_179 = V_313 -> V_179 ;
V_171 -> V_178 = V_313 -> V_178 ;
V_171 -> V_253 = V_313 -> V_253 ;
V_171 -> V_213 = V_313 -> V_213 ;
V_171 -> V_194 = V_313 -> V_194 ;
V_171 -> V_193 = V_313 -> V_193 ;
V_171 -> V_192 = V_313 -> V_192 ;
V_171 -> V_191 = V_313 -> V_191 ;
V_171 -> V_314 = V_313 -> V_314 ;
return 0 ;
}
static int F_113 ( struct V_46 * V_168 ,
struct V_315 T_9 * V_316 )
{
struct V_315 V_317 ;
if ( ! V_316 )
return - V_318 ;
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
V_317 . type = V_319 ;
V_317 . line = V_168 -> V_18 -> V_22 -> V_23 ;
V_317 . V_18 = V_168 -> V_18 -> V_21 ;
V_317 . V_320 = 0 ;
V_317 . V_64 = V_321 | V_322 ;
V_317 . V_323 = V_168 -> V_18 -> V_251 ;
V_317 . V_324 = 9600 ;
V_317 . V_325 = 5 * V_65 ;
V_317 . V_245 = V_245 ;
if ( F_114 ( V_316 , & V_317 , sizeof( * V_316 ) ) )
return - V_318 ;
return 0 ;
}
static int F_115 ( struct V_60 * V_61 ,
unsigned int V_326 , unsigned long V_327 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
struct V_170 V_328 ;
struct V_170 V_329 ;
F_4 ( L_134 , V_12 , V_18 -> V_21 , V_326 ) ;
switch ( V_326 ) {
case V_330 :
F_4 ( L_135 , V_12 , V_18 -> V_21 ) ;
return F_113 ( V_168 ,
(struct V_315 T_9 * ) V_327 ) ;
case V_331 :
F_4 ( L_136 , V_12 , V_18 -> V_21 ) ;
V_329 = V_168 -> V_171 ;
while ( 1 ) {
F_116 ( & V_168 -> V_180 ) ;
if ( F_27 ( V_68 ) )
return - V_237 ;
V_328 = V_168 -> V_171 ;
if ( V_328 . V_179 == V_329 . V_179 && V_328 . V_177 == V_329 . V_177 &&
V_328 . V_178 == V_329 . V_178 && V_328 . V_176 == V_329 . V_176 )
return - V_332 ;
if ( ( ( V_327 & V_333 ) && ( V_328 . V_179 != V_329 . V_179 ) ) ||
( ( V_327 & V_311 ) && ( V_328 . V_177 != V_329 . V_177 ) ) ||
( ( V_327 & V_334 ) && ( V_328 . V_178 != V_329 . V_178 ) ) ||
( ( V_327 & V_305 ) && ( V_328 . V_176 != V_329 . V_176 ) ) ) {
return 0 ;
}
V_329 = V_328 ;
}
break;
}
return - V_335 ;
}
static void F_117 ( struct V_60 * V_61 , int V_336 )
{
struct V_17 * V_18 = V_61 -> V_249 ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
int V_8 ;
int V_337 = 0 ;
F_4 ( L_137 , V_12 , V_336 ) ;
F_20 ( V_168 , 0 , 0 ) ;
if ( V_336 == - 1 )
V_337 = 1 ;
V_8 = F_59 ( V_168 , V_338 , V_337 ) ;
if ( V_8 )
F_4 ( L_138 ,
V_12 , V_8 ) ;
}
static int F_118 ( struct V_62 * V_22 )
{
struct V_36 * V_196 ;
struct V_46 * V_168 ;
struct V_1 * V_2 ;
int V_8 ;
int V_37 ;
V_2 = V_22 -> V_2 ;
V_196 = F_119 ( sizeof( struct V_36 ) , V_41 ) ;
if ( V_196 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 , V_12 ) ;
return - V_42 ;
}
F_120 ( & V_196 -> V_236 ) ;
V_196 -> V_22 = V_22 ;
F_121 ( V_22 , V_196 ) ;
V_8 = F_56 ( V_196 ) ;
if ( V_8 ) {
F_17 ( V_196 ) ;
return V_8 ;
}
for ( V_37 = 0 ; V_37 < V_22 -> V_339 ; ++ V_37 ) {
V_168 = F_119 ( sizeof( struct V_46 ) , V_41 ) ;
if ( V_168 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 ,
V_12 ) ;
goto V_340;
}
F_122 ( & V_168 -> V_67 ) ;
if ( F_123 ( & V_168 -> V_71 , V_341 ,
V_41 ) ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 ,
V_12 ) ;
F_17 ( V_168 ) ;
goto V_340;
}
V_168 -> V_18 = V_22 -> V_18 [ V_37 ] ;
V_168 -> V_196 = V_196 ;
F_124 ( V_22 -> V_18 [ V_37 ] , V_168 ) ;
V_168 -> V_267 = V_342 ;
}
return 0 ;
V_340:
for ( -- V_37 ; V_37 >= 0 ; -- V_37 ) {
V_168 = F_72 ( V_22 -> V_18 [ V_37 ] ) ;
F_125 ( & V_168 -> V_71 ) ;
F_17 ( V_168 ) ;
F_124 ( V_22 -> V_18 [ V_37 ] , NULL ) ;
}
F_17 ( V_196 ) ;
F_121 ( V_22 , NULL ) ;
return - V_42 ;
}
static void F_126 ( struct V_62 * V_22 )
{
F_4 ( L_63 , V_12 ) ;
}
static void F_127 ( struct V_62 * V_22 )
{
int V_37 ;
struct V_46 * V_168 ;
F_4 ( L_63 , V_12 ) ;
for ( V_37 = 0 ; V_37 < V_22 -> V_339 ; ++ V_37 ) {
V_168 = F_72 ( V_22 -> V_18 [ V_37 ] ) ;
F_125 ( & V_168 -> V_71 ) ;
F_17 ( V_168 ) ;
}
F_17 ( F_90 ( V_22 ) ) ;
}
static T_10 F_128 ( struct V_92 * V_2 ,
struct V_343 * V_344 , char * V_345 )
{
struct V_17 * V_18 = F_129 ( V_2 ) ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
return sprintf ( V_345 , L_66 , V_168 -> V_267 ) ;
}
static T_10 F_130 ( struct V_92 * V_2 ,
struct V_343 * V_344 , const char * V_346 , T_11 V_248 )
{
struct V_17 * V_18 = F_129 ( V_2 ) ;
struct V_46 * V_168 = F_72 ( V_18 ) ;
unsigned int V_347 = F_131 ( V_346 , NULL , 0 ) ;
F_4 ( L_140 , V_12 , V_347 ) ;
if ( V_347 < 256 )
V_168 -> V_267 = V_347 ;
else
F_16 ( V_2 , L_141 , V_12 , V_347 ) ;
return V_248 ;
}
static int F_132 ( struct V_17 * V_18 )
{
return F_133 ( & V_18 -> V_2 , & V_348 ) ;
}
static int F_134 ( struct V_17 * V_18 )
{
F_135 ( & V_18 -> V_2 , & V_348 ) ;
return 0 ;
}
