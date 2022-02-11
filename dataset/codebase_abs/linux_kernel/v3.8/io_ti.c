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
F_4 ( & V_2 -> V_2 , L_1 ,
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
F_4 ( & V_2 -> V_2 , L_1 ,
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
F_4 ( & V_18 -> V_2 , L_2 , V_12 , V_20 , V_19 ) ;
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
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_26 , V_27 ) ;
while ( V_27 ) {
if ( V_27 > 64 )
V_30 = 64 ;
else
V_30 = ( T_1 ) V_27 ;
if ( V_30 > 1 ) {
F_4 ( & V_2 -> V_2 , L_3 , V_12 , V_26 , V_30 ) ;
}
V_31 = F_10 ( V_26 ) ;
V_8 = F_1 ( V_2 , V_32 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_30 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
if ( V_30 > 1 )
F_11 ( & V_2 -> V_2 , V_12 , V_30 , V_29 ) ;
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
V_34 , V_29 ) ;
}
static int F_13 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_27 ; V_36 ++ ) {
V_8 = F_1 ( V_22 -> V_22 -> V_2 ,
V_32 , V_22 -> V_37 ,
( T_2 ) ( V_26 + V_36 ) , & V_29 [ V_36 ] , 0x01 ) ;
if ( V_8 ) {
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_4 , V_12 , V_8 ) ;
return V_8 ;
}
}
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_5 ,
V_12 , V_26 , V_27 ) ;
F_11 ( & V_22 -> V_22 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
V_22 -> V_38 = 1 ;
return V_8 ;
}
static int F_14 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 = 0 ;
int V_36 ;
T_3 * V_39 ;
if ( ! V_22 -> V_38 ) {
V_39 = F_15 ( 1 , V_40 ) ;
if ( ! V_39 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 ,
L_6 , V_12 ) ;
return - V_41 ;
}
V_8 = F_13 ( V_22 , 0 , 1 , V_39 ) ;
F_17 ( V_39 ) ;
if ( V_8 )
return V_8 ;
}
for ( V_36 = 0 ; V_36 < V_27 ; ++ V_36 ) {
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_42 , V_29 [ V_36 ] ,
( T_2 ) ( V_36 + V_26 ) , NULL , 0 ) ;
if ( V_8 )
return V_8 ;
}
F_4 ( & V_22 -> V_22 -> V_2 -> V_2 , L_7 , V_12 , V_26 , V_27 ) ;
F_11 ( & V_22 -> V_22 -> V_2 -> V_2 , V_12 , V_27 , V_29 ) ;
return V_8 ;
}
static int F_18 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 V_28 , T_1 * V_29 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_44 ;
T_4 V_31 ;
V_44 = V_45 -
( V_26 & ( V_45 - 1 ) ) ;
if ( V_44 > V_27 )
V_44 = V_27 ;
F_4 ( V_2 , L_8 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_2 , V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_42 , ( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_9 , V_12 , V_8 ) ;
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
F_4 ( V_2 , L_10 ,
V_12 , V_26 , V_44 ) ;
F_11 ( V_2 , V_12 , V_44 , V_29 ) ;
V_31 = F_10 ( V_26 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 , V_42 ,
( T_2 ) V_28 ,
( V_33 T_2 ) V_31 ,
V_29 , V_44 ) ;
if ( V_8 ) {
F_16 ( V_2 , L_9 , V_12 , V_8 ) ;
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
V_48 = F_15 ( sizeof( * V_48 ) , V_40 ) ;
if ( ! V_48 ) {
F_16 ( & V_18 -> V_18 -> V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_49 = F_15 ( 1 , V_40 ) ;
if ( ! V_49 ) {
F_17 ( V_48 ) ;
return - V_41 ;
}
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 , V_18 -> V_51 ,
sizeof( * V_48 ) , ( void * ) V_48 ) ;
if ( V_8 )
goto V_52;
F_4 ( & V_18 -> V_18 -> V_2 , L_11 , V_12 , V_48 -> V_53 ) ;
V_8 = F_12 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_18 -> V_54 + V_55 , 1 , V_49 ) ;
if ( V_8 )
goto V_52;
F_4 ( & V_18 -> V_18 -> V_2 , L_12 , V_12 , * V_49 ) ;
if ( ( V_48 -> V_53 & 0x80 ) != 0 )
V_50 += 64 ;
if ( ( * V_49 & V_56 ) == 0 )
V_50 += 1 ;
V_52:
F_4 ( & V_18 -> V_18 -> V_2 , L_13 , V_12 , V_50 ) ;
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
if ( ! V_61 )
return;
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
F_4 ( & V_2 -> V_2 , L_14 ,
V_12 , V_2 -> V_75 -> V_76 . V_77 ) ;
F_4 ( & V_2 -> V_2 , L_15 ,
V_12 , V_2 -> V_75 -> V_76 . V_78 * 2 ) ;
if ( V_2 -> V_75 -> V_76 . V_77 != 1 ) {
F_16 ( & V_2 -> V_2 , L_16 , V_12 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_37 ( struct V_35 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 ;
if ( V_22 -> V_80 . V_81 == V_82 ) {
V_8 = F_9 ( V_22 -> V_22 -> V_2 ,
V_26 ,
V_27 ,
V_22 -> V_37 ,
V_29 ) ;
} else {
V_8 = F_13 ( V_22 , V_26 , V_27 ,
V_29 ) ;
}
return V_8 ;
}
static int F_38 ( struct V_35 * V_22 , int V_26 ,
int V_27 , T_1 * V_29 )
{
if ( V_22 -> V_80 . V_81 == V_83 )
return F_14 ( V_22 , V_26 , V_27 ,
V_29 ) ;
if ( V_22 -> V_80 . V_81 == V_82 )
return F_18 ( V_22 , V_26 , V_27 ,
V_22 -> V_37 , V_29 ) ;
return - V_84 ;
}
static int F_39 ( struct V_35 * V_22 ,
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
T_2 V_36 ;
T_1 V_90 = 0 ;
for ( V_36 = 0 ; V_36 < V_87 -> V_88 ; V_36 ++ )
V_90 = ( T_1 ) ( V_90 + V_29 [ V_36 ] ) ;
if ( V_90 != V_87 -> V_91 ) {
F_41 ( L_17 , V_12 , V_87 -> V_91 , V_90 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_42 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_86 * V_87 ;
int V_26 = 2 ;
T_1 * V_29 ;
T_2 V_92 ;
V_87 = F_15 ( sizeof( * V_87 ) , V_40 ) ;
if ( ! V_87 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_29 = F_15 ( V_89 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_18 ,
V_12 ) ;
F_17 ( V_87 ) ;
return - V_41 ;
}
V_8 = F_37 ( V_22 , 0 , 1 , V_29 ) ;
if ( V_8 )
goto V_93;
if ( * V_29 != V_94 && * V_29 != V_95 ) {
F_16 ( V_2 , L_19 , V_12 ) ;
V_8 = - V_79 ;
goto V_93;
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
F_4 ( V_2 , L_20 , V_12 ) ;
break;
}
F_4 ( V_2 , L_21 , V_12 , V_87 -> Type ) ;
V_92 = V_87 -> Type & 0x0f ;
if ( V_92 != V_96
&& V_92 != V_97 ) {
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
} while ( ( V_87 -> Type != V_98 ) &&
( V_26 < V_89 ) );
if ( ( V_87 -> Type != V_98 ) ||
( V_26 > V_89 ) )
V_8 = - V_79 ;
V_93:
F_17 ( V_29 ) ;
F_17 ( V_87 ) ;
return V_8 ;
}
static int F_43 ( struct V_35 * V_22 , T_1 * V_29 )
{
int V_8 ;
int V_26 ;
struct V_86 * V_87 ;
struct V_99 * V_76 ;
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
V_87 = F_15 ( sizeof( * V_87 ) , V_40 ) ;
if ( ! V_87 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_26 = F_39 ( V_22 , V_98 ,
V_87 ) ;
if ( ! V_26 ) {
F_4 ( V_2 , L_22 , V_12 ) ;
V_8 = - V_79 ;
goto exit;
}
V_8 = F_37 ( V_22 , V_26 + sizeof( struct V_86 ) ,
V_87 -> V_88 , V_29 ) ;
if ( V_8 )
goto exit;
V_8 = F_40 ( V_87 , V_29 ) ;
V_76 = (struct V_99 * ) V_29 ;
F_4 ( V_2 , L_23 , V_12 , V_76 -> V_100 ) ;
F_4 ( V_2 , L_24 , V_12 , V_76 -> V_101 ) ;
F_4 ( V_2 , L_25 , V_12 , V_76 -> V_102 ) ;
F_4 ( V_2 , L_26 , V_12 , V_76 -> V_103 ) ;
F_4 ( V_2 , L_27 , V_12 , V_76 -> V_104 ) ;
F_4 ( V_2 , L_28 , V_12 , V_76 -> V_105 ) ;
exit:
F_17 ( V_87 ) ;
return V_8 ;
}
static int F_44 ( T_1 * V_106 , struct V_43 * V_2 )
{
T_1 * V_29 ;
int V_107 ;
int V_36 ;
int V_108 ;
T_1 V_90 = 0 ;
struct V_86 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
const struct V_114 * V_115 ;
const char * V_116 = L_29 ;
V_107 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_112 ) ) ;
V_29 = F_15 ( V_107 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
memset ( V_29 , 0xff , V_107 ) ;
V_108 = F_45 ( & V_115 , V_116 , V_2 ) ;
if ( V_108 ) {
F_16 ( V_2 , L_30 ,
V_116 , V_108 ) ;
F_17 ( V_29 ) ;
return V_108 ;
}
V_117 = V_115 -> V_6 [ 0 ] ;
V_118 = V_115 -> V_6 [ 1 ] ;
V_119 = V_115 -> V_6 [ 2 ] | ( V_115 -> V_6 [ 3 ] << 8 ) ;
V_113 = (struct V_112 * ) V_29 ;
V_113 -> V_120 = V_117 ;
V_113 -> V_121 = V_118 ;
V_111 = (struct V_110 * ) & V_115 -> V_6 [ 4 ] ;
memcpy ( V_29 + sizeof( struct V_112 ) ,
& V_115 -> V_6 [ 4 + sizeof( struct V_110 ) ] ,
F_46 ( V_111 -> V_122 ) ) ;
F_47 ( V_115 ) ;
for ( V_36 = 0 ; V_36 < V_107 ; V_36 ++ ) {
V_90 = ( T_1 ) ( V_90 + V_29 [ V_36 ] ) ;
}
F_17 ( V_29 ) ;
V_109 = (struct V_86 * ) V_106 ;
V_113 = (struct V_112 * ) V_109 -> V_123 ;
V_109 -> Type = V_124 ;
V_109 -> V_88 = ( T_2 ) V_107 ;
V_109 -> V_91 = V_90 ;
V_113 -> V_120 = V_117 ;
V_113 -> V_121 = V_118 ;
return 0 ;
}
static int F_48 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 ;
T_3 * V_6 ;
V_6 = F_15 ( 1 , V_40 ) ;
if ( ! V_6 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_125 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_31 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_32 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_94 || * V_6 == V_95 ) ) {
F_4 ( V_2 , L_33 , V_12 ) ;
V_22 -> V_37 = V_125 ;
goto V_93;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_126 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( V_2 , L_34 , V_12 , V_8 ) ;
else
F_4 ( V_2 , L_32 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_94 || * V_6 == V_95 ) ) {
F_4 ( V_2 , L_35 , V_12 ) ;
V_22 -> V_37 = V_126 ;
goto V_93;
}
F_4 ( V_2 , L_36 , V_12 ) ;
V_22 -> V_37 = V_125 ;
V_8 = - V_79 ;
V_93:
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_49 ( struct V_62 * V_22 , void * V_29 ,
int V_27 , int * V_127 )
{
int V_8 ;
V_8 = F_50 ( V_22 -> V_2 ,
F_51 ( V_22 -> V_2 ,
V_22 -> V_18 [ 0 ] -> V_128 ) ,
V_29 , V_27 , V_127 , 1000 ) ;
return V_8 ;
}
static int F_52 ( struct V_35 * V_22 , T_1 * V_129 ,
int V_130 )
{
int V_8 = 0 ;
int V_131 ;
int V_132 ;
int V_133 ;
for ( V_131 = 0 ; V_131 < V_130 ; ) {
V_132 = V_130 - V_131 ;
if ( V_132 > V_134 )
V_132 = V_134 ;
V_8 = F_49 ( V_22 -> V_22 , & V_129 [ V_131 ] ,
V_132 , & V_133 ) ;
if ( V_8 )
break;
V_131 += V_133 ;
}
return V_8 ;
}
static int F_53 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_54 ( struct V_99 * V_76 )
{
return F_55 ( V_76 -> V_102 ) ;
}
static int F_56 ( struct V_35 * V_22 )
{
struct V_43 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_99 * V_135 ;
struct V_136 * V_137 ;
int V_138 ;
int V_139 ;
V_22 -> V_80 . V_140 = V_141 ;
V_22 -> V_37 = V_125 ;
V_8 = F_36 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_137 = & V_22 -> V_22 -> V_137 -> V_142 -> V_76 ;
if ( ! V_137 ) {
F_16 ( V_2 , L_37 , V_12 ) ;
return - V_79 ;
}
if ( V_137 -> V_143 > 1 )
V_22 -> V_80 . V_81 = V_82 ;
else
V_22 -> V_80 . V_81 = V_144 ;
if ( V_22 -> V_80 . V_81 == V_82 ) {
struct V_86 * V_87 ;
F_4 ( V_2 , L_38 , V_12 ) ;
V_8 = F_42 ( V_22 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_39 , V_12 ) ;
return V_8 ;
}
V_135 = F_15 ( sizeof( * V_135 ) , V_40 ) ;
if ( ! V_135 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
return - V_41 ;
}
V_8 = F_43 ( V_22 , ( T_1 * ) V_135 ) ;
if ( V_8 ) {
F_17 ( V_135 ) ;
return V_8 ;
}
if ( ! V_145 && F_54 ( V_135 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_54 ( V_135 ) ) ;
F_17 ( V_135 ) ;
return - V_84 ;
}
V_87 = F_15 ( sizeof( * V_87 ) , V_40 ) ;
if ( ! V_87 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_135 ) ;
return - V_41 ;
}
V_26 = F_39 ( V_22 ,
V_96 , V_87 ) ;
if ( V_26 != 0 ) {
struct V_112 * V_146 ;
T_3 * V_147 ;
F_4 ( V_2 , L_42 , V_12 ) ;
V_146 = F_15 ( sizeof( * V_146 ) ,
V_40 ) ;
if ( ! V_146 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_41 ;
}
V_8 = F_37 ( V_22 , V_26 +
sizeof( struct V_86 ) ,
sizeof( struct V_112 ) ,
( T_1 * ) V_146 ) ;
if ( V_8 ) {
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return V_8 ;
}
V_138 = ( V_146 -> V_120 << 8 ) +
( V_146 -> V_121 ) ;
V_139 = ( V_117 << 8 ) +
( V_118 ) ;
F_4 ( V_2 , L_43 ,
V_12 , V_146 -> V_120 ,
V_146 -> V_121 ,
V_117 ,
V_118 ) ;
if ( V_138 < V_139 ) {
F_4 ( V_2 , L_44 ,
V_12 ,
V_146 -> V_120 ,
V_146 -> V_121 ,
V_117 ,
V_118 ) ;
V_147 = F_15 ( 1 , V_40 ) ;
if ( ! V_147 ) {
F_16 ( V_2 , L_40 ,
V_12 ) ;
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_41 ;
}
* V_147 = V_124 ;
V_8 = F_38 ( V_22 , V_26 ,
sizeof( * V_147 ) , V_147 ) ;
if ( V_8 ) {
F_17 ( V_147 ) ;
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return V_8 ;
}
V_8 = F_37 ( V_22 ,
V_26 ,
sizeof( * V_147 ) ,
V_147 ) ;
if ( V_8 ) {
F_17 ( V_147 ) ;
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return V_8 ;
}
if ( * V_147 != V_124 ) {
F_16 ( V_2 , L_45 , V_12 ) ;
F_17 ( V_147 ) ;
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_79 ;
}
F_4 ( V_2 , L_46 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_148 ,
0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_47 , V_12 , V_8 ) ;
F_17 ( V_147 ) ;
F_17 ( V_146 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_79 ;
}
F_17 ( V_146 ) ;
}
else if ( ( V_26 = F_39 ( V_22 , V_124 , V_87 ) ) != 0 ) {
#define F_57 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_106 ;
T_1 * V_149 ;
V_106 = F_15 ( F_57 , V_40 ) ;
if ( ! V_106 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_41 ;
}
V_149 = F_15 ( F_57 , V_40 ) ;
if ( ! V_149 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
F_17 ( V_106 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_41 ;
}
F_4 ( V_2 , L_48 , V_12 ) ;
V_8 = F_44 ( V_106 , V_2 ) ;
if ( V_8 ) {
F_17 ( V_149 ) ;
F_17 ( V_106 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_84 ;
}
V_8 = F_38 ( V_22 ,
V_26 ,
F_57 ,
V_106 ) ;
if ( V_8 ) {
F_17 ( V_149 ) ;
F_17 ( V_106 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_84 ;
}
V_8 = F_37 ( V_22 , V_26 ,
F_57 , V_149 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_49 , V_12 ) ;
F_17 ( V_149 ) ;
F_17 ( V_106 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return V_8 ;
}
if ( memcmp ( V_149 , V_106 , F_57 ) ) {
F_4 ( V_2 , L_50 , V_12 ) ;
F_17 ( V_149 ) ;
F_17 ( V_106 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return - V_84 ;
}
F_17 ( V_149 ) ;
F_17 ( V_106 ) ;
F_4 ( V_2 , L_51 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_150 , 0 , 0 , NULL , 0 ) ;
F_4 ( V_2 , L_52 , V_12 , V_8 ) ;
if ( V_8 ) {
F_16 ( V_2 ,
L_53 ,
V_12 ) ;
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return V_8 ;
}
}
F_17 ( V_87 ) ;
F_17 ( V_135 ) ;
return 0 ;
}
F_4 ( V_2 , L_54 , V_12 ) ;
V_8 = F_53 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_46 ( V_22 -> V_22 -> V_2 -> V_151 . V_152 )
!= V_153 ) {
F_4 ( V_2 , L_55 , V_12 ,
F_46 ( V_22 -> V_22 -> V_2 -> V_151 . V_152 ) ) ;
V_22 -> V_37 = V_125 ;
goto V_154;
}
if ( F_48 ( V_22 ) )
goto V_154;
if ( ! F_42 ( V_22 ) ) {
struct V_110 * V_106 ;
int V_36 ;
T_1 V_90 = 0 ;
T_1 * V_29 ;
int V_107 ;
int V_108 ;
const struct V_114 * V_115 ;
const char * V_116 = L_29 ;
V_135 = F_15 ( sizeof( * V_135 ) , V_40 ) ;
if ( ! V_135 ) {
F_16 ( V_2 , L_40 , V_12 ) ;
return - V_41 ;
}
V_8 = F_43 ( V_22 , ( T_1 * ) V_135 ) ;
if ( V_8 ) {
F_17 ( V_135 ) ;
goto V_154;
}
if ( ! V_145 && F_54 ( V_135 ) < 2 ) {
F_4 ( V_2 , L_41 ,
V_12 , F_54 ( V_135 ) ) ;
F_17 ( V_135 ) ;
goto V_154;
}
F_17 ( V_135 ) ;
V_107 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_110 ) ) ;
V_29 = F_15 ( V_107 , V_40 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_41 ;
}
memset ( V_29 , 0xff , V_107 ) ;
V_108 = F_45 ( & V_115 , V_116 , V_2 ) ;
if ( V_108 ) {
F_16 ( V_2 , L_30 ,
V_116 , V_108 ) ;
F_17 ( V_29 ) ;
return V_108 ;
}
memcpy ( V_29 , & V_115 -> V_6 [ 4 ] , V_115 -> V_7 - 4 ) ;
F_47 ( V_115 ) ;
for ( V_36 = sizeof( struct V_110 ) ;
V_36 < V_107 ; V_36 ++ ) {
V_90 = ( T_1 ) ( V_90 + V_29 [ V_36 ] ) ;
}
V_106 = (struct V_110 * ) V_29 ;
V_106 -> V_122 = F_58 ( ( T_2 ) ( V_107 -
sizeof( struct V_110 ) ) ) ;
V_106 -> V_91 = V_90 ;
F_4 ( V_2 , L_56 , V_12 ) ;
V_8 = F_52 ( V_22 , V_29 , V_107 ) ;
F_17 ( V_29 ) ;
if ( V_8 ) {
F_4 ( V_2 , L_57 , V_12 ) ;
return V_8 ;
}
V_22 -> V_80 . V_81 = V_155 ;
F_4 ( V_2 , L_58 , V_12 ) ;
return - V_79 ;
}
V_154:
F_4 ( V_2 , L_59 , V_12 ) ;
V_22 -> V_80 . V_81 = V_83 ;
return 0 ;
}
static int F_59 ( struct V_46 * V_18 , int V_156 , int V_157 )
{
int V_20 = V_18 -> V_18 -> V_21 - V_18 -> V_18 -> V_22 -> V_23 ;
V_157 = ! ! V_157 ;
return F_7 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_156 , ( T_1 ) ( V_25 + V_20 ) ,
V_157 , NULL , 0 ) ;
}
static int F_60 ( struct V_46 * V_18 , T_1 V_158 )
{
int V_8 = 0 ;
F_4 ( & V_18 -> V_18 -> V_2 , L_60 , V_12 , V_158 ) ;
V_8 = F_59 ( V_18 , V_159 , V_158 & V_160 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_59 ( V_18 , V_161 , V_158 & V_162 ) ;
if ( V_8 )
return V_8 ;
return F_59 ( V_18 , V_163 , V_158 & V_164 ) ;
}
static T_1 F_61 ( T_1 V_165 )
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
static void F_63 ( struct V_46 * V_166 , T_1 V_167 )
{
struct V_168 * V_169 ;
struct V_60 * V_61 ;
F_4 ( & V_166 -> V_18 -> V_2 , L_61 , V_12 , V_167 ) ;
if ( V_167 & ( V_170 | V_171 |
V_172 | V_173 ) ) {
V_169 = & V_166 -> V_169 ;
if ( V_167 & V_170 )
V_169 -> V_174 ++ ;
if ( V_167 & V_171 )
V_169 -> V_175 ++ ;
if ( V_167 & V_173 )
V_169 -> V_176 ++ ;
if ( V_167 & V_172 )
V_169 -> V_177 ++ ;
F_64 ( & V_166 -> V_178 ) ;
}
V_166 -> V_179 = V_167 & 0xf0 ;
V_61 = F_21 ( & V_166 -> V_18 -> V_18 ) ;
if ( V_61 && F_65 ( V_61 ) ) {
if ( V_167 & V_180 ) {
V_61 -> V_181 = 0 ;
F_66 ( V_61 ) ;
} else {
V_61 -> V_181 = 1 ;
}
}
F_32 ( V_61 ) ;
}
static void F_67 ( struct V_46 * V_166 , int V_182 ,
T_1 V_49 , T_1 V_6 )
{
struct V_168 * V_169 ;
T_1 V_183 = ( T_1 ) ( V_49 & ( T_1 ) ( V_184 | V_185 |
V_186 | V_187 ) ) ;
struct V_60 * V_61 ;
F_4 ( & V_166 -> V_18 -> V_2 , L_61 , V_12 , V_183 ) ;
V_166 -> V_188 = V_49 ;
if ( V_183 & V_187 )
V_183 &= ( T_1 ) ( V_184 | V_187 ) ;
if ( V_182 ) {
V_61 = F_21 ( & V_166 -> V_18 -> V_18 ) ;
if ( V_61 ) {
F_68 ( & V_166 -> V_18 -> V_2 , V_61 , & V_6 , 1 ) ;
F_32 ( V_61 ) ;
}
}
V_169 = & V_166 -> V_169 ;
if ( V_183 & V_187 )
V_169 -> V_189 ++ ;
if ( V_183 & V_184 )
V_169 -> V_190 ++ ;
if ( V_183 & V_185 )
V_169 -> V_191 ++ ;
if ( V_183 & V_186 )
V_169 -> V_192 ++ ;
}
static void F_69 ( struct V_193 * V_193 )
{
struct V_35 * V_194 = V_193 -> V_195 ;
struct V_17 * V_18 ;
struct V_46 * V_166 ;
struct V_43 * V_2 ;
unsigned char * V_6 = V_193 -> V_196 ;
int V_27 = V_193 -> V_197 ;
int V_20 ;
int V_198 ;
int V_199 ;
T_1 V_49 ;
T_1 V_167 ;
int V_8 = V_193 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_200 :
case - V_201 :
case - V_202 :
F_4 ( & V_193 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_193 -> V_2 -> V_2 , L_63
L_64 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( & V_193 -> V_2 -> V_2 , L_65 , V_12 ) ;
goto exit;
}
V_2 = & V_194 -> V_22 -> V_2 -> V_2 ;
F_11 ( V_2 , V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( V_2 , L_66 , V_12 , V_27 ) ;
goto exit;
}
V_20 = F_70 ( V_6 [ 0 ] ) ;
V_198 = F_71 ( V_6 [ 0 ] ) ;
F_4 ( V_2 , L_67 , V_12 ,
V_20 , V_198 , V_6 [ 1 ] ) ;
V_18 = V_194 -> V_22 -> V_18 [ V_20 ] ;
V_166 = F_72 ( V_18 ) ;
if ( ! V_166 ) {
F_4 ( V_2 , L_68 , V_12 ) ;
return;
}
switch ( V_198 ) {
case V_203 :
V_49 = F_61 ( V_6 [ 1 ] ) ;
if ( V_49 & V_204 ) {
F_4 ( V_2 , L_69 ,
V_12 , V_20 , V_49 ) ;
V_166 -> V_205 = 1 ;
V_166 -> V_206 = V_49 ;
} else {
F_4 ( V_2 , L_70 ,
V_12 , V_20 , V_49 ) ;
F_67 ( V_166 , 0 , V_49 , 0 ) ;
}
break;
case V_207 :
V_167 = V_6 [ 1 ] ;
F_4 ( V_2 , L_71 ,
V_12 , V_20 , V_167 ) ;
F_63 ( V_166 , V_167 ) ;
break;
default:
F_16 ( & V_193 -> V_2 -> V_2 ,
L_72 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_199 = F_73 ( V_193 , V_208 ) ;
if ( V_199 )
F_16 ( & V_193 -> V_2 -> V_2 ,
L_73 ,
V_12 , V_199 ) ;
}
static void F_74 ( struct V_193 * V_193 )
{
struct V_46 * V_166 = V_193 -> V_195 ;
struct V_43 * V_2 = & V_166 -> V_18 -> V_2 ;
unsigned char * V_6 = V_193 -> V_196 ;
struct V_60 * V_61 ;
int V_199 = 0 ;
int V_20 ;
int V_8 = V_193 -> V_8 ;
switch ( V_8 ) {
case 0 :
break;
case - V_200 :
case - V_201 :
case - V_202 :
F_4 ( & V_193 -> V_2 -> V_2 , L_62 , V_12 , V_8 ) ;
return;
default:
F_16 ( & V_193 -> V_2 -> V_2 , L_74 , V_12 , V_8 ) ;
}
if ( V_8 == - V_209 )
goto exit;
if ( V_8 ) {
F_16 ( & V_193 -> V_2 -> V_2 , L_75 , V_12 ) ;
return;
}
V_20 = V_166 -> V_18 -> V_21 - V_166 -> V_18 -> V_22 -> V_23 ;
if ( V_166 -> V_205 ) {
V_166 -> V_205 = 0 ;
F_4 ( V_2 , L_76 ,
V_12 , V_20 , V_166 -> V_206 , * V_6 ) ;
F_67 ( V_166 , 1 , V_166 -> V_206 , * V_6 ) ;
-- V_193 -> V_197 ;
++ V_6 ;
}
V_61 = F_21 ( & V_166 -> V_18 -> V_18 ) ;
if ( V_61 && V_193 -> V_197 ) {
F_11 ( V_2 , V_12 , V_193 -> V_197 , V_6 ) ;
if ( V_166 -> V_210 )
F_4 ( V_2 , L_77 ,
V_12 ) ;
else
F_68 ( V_2 , V_61 , V_6 , V_193 -> V_197 ) ;
V_166 -> V_169 . V_211 += V_193 -> V_197 ;
}
F_32 ( V_61 ) ;
exit:
F_75 ( & V_166 -> V_67 ) ;
if ( V_166 -> V_212 == V_213 )
V_199 = F_73 ( V_193 , V_208 ) ;
else if ( V_166 -> V_212 == V_214 )
V_166 -> V_212 = V_215 ;
F_76 ( & V_166 -> V_67 ) ;
if ( V_199 )
F_16 ( V_2 , L_73 , V_12 , V_199 ) ;
}
static void F_68 ( struct V_43 * V_2 , struct V_60 * V_61 ,
unsigned char * V_6 , int V_27 )
{
int V_216 ;
V_216 = F_77 ( V_61 , V_6 , V_27 ) ;
if ( V_216 < V_27 )
F_16 ( V_2 , L_78 ,
V_12 , V_27 - V_216 ) ;
F_78 ( V_61 ) ;
}
static void F_79 ( struct V_193 * V_193 )
{
struct V_17 * V_18 = V_193 -> V_195 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_8 = V_193 -> V_8 ;
struct V_60 * V_61 ;
V_166 -> V_217 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_200 :
case - V_201 :
case - V_202 :
F_4 ( & V_193 -> V_2 -> V_2 , L_62 ,
V_12 , V_8 ) ;
return;
default:
F_80 ( V_18 , L_79
L_80 , V_12 , V_8 ) ;
}
V_61 = F_21 ( & V_18 -> V_18 ) ;
F_81 ( V_61 ) ;
F_32 ( V_61 ) ;
}
static int F_82 ( struct V_60 * V_61 , struct V_17 * V_18 )
{
struct V_46 * V_166 = F_72 ( V_18 ) ;
struct V_35 * V_194 ;
struct V_1 * V_2 ;
struct V_193 * V_193 ;
int V_20 ;
int V_8 ;
T_8 V_218 ;
T_3 V_219 ;
if ( V_166 == NULL )
return - V_79 ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
switch ( V_20 ) {
case 0 :
V_166 -> V_54 = V_220 ;
V_166 -> V_51 = V_221 ;
break;
case 1 :
V_166 -> V_54 = V_222 ;
V_166 -> V_51 = V_223 ;
break;
default:
F_16 ( & V_18 -> V_2 , L_81 ) ;
return - V_79 ;
}
F_4 ( & V_18 -> V_2 , L_82 ,
V_12 , V_20 , V_166 -> V_54 , V_166 -> V_51 ) ;
V_2 = V_18 -> V_22 -> V_2 ;
memset ( & ( V_166 -> V_169 ) , 0x00 , sizeof( V_166 -> V_169 ) ) ;
F_83 ( & V_166 -> V_178 ) ;
V_8 = F_59 ( V_166 , V_163 , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_83 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_61 )
F_84 ( V_61 , V_18 , & V_61 -> V_224 ) ;
V_219 = 2 ;
V_166 -> V_225 =
F_34 ( 20 , ( ( V_219 * 3 ) / 2 ) ) ;
V_218 = ( T_3 ) ( V_226 |
V_227 |
( V_219 << 2 ) ) ;
F_4 ( & V_18 -> V_2 , L_84 , V_12 ) ;
V_8 = F_7 ( V_2 , V_228 ,
( T_3 ) ( V_25 + V_20 ) , V_218 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_85 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_229 ,
( T_3 ) ( V_25 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_86 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_230 | V_231 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_87 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_232 , 0 ,
( T_2 ) ( V_25 + V_20 ) ,
& V_166 -> V_179 , 1 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_88 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( & V_18 -> V_2 , L_89 , V_166 -> V_179 ) ;
V_166 -> V_233 = V_162 | V_160 ;
F_4 ( & V_18 -> V_2 , L_90 , V_166 -> V_233 ) ;
V_194 = V_166 -> V_194 ;
if ( F_85 ( & V_194 -> V_234 ) )
return - V_235 ;
if ( V_194 -> V_236 == 0 ) {
V_193 = V_194 -> V_22 -> V_18 [ 0 ] -> V_237 ;
if ( ! V_193 ) {
F_16 ( & V_18 -> V_2 ,
L_91 ,
V_12 ) ;
V_8 = - V_84 ;
goto V_238;
}
V_193 -> V_195 = V_194 ;
V_8 = F_73 ( V_193 , V_40 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_92 ,
V_12 , V_8 ) ;
goto V_238;
}
}
F_86 ( V_2 , V_18 -> V_239 -> V_240 ) ;
F_86 ( V_2 , V_18 -> V_241 -> V_240 ) ;
V_193 = V_18 -> V_241 ;
if ( ! V_193 ) {
F_16 ( & V_18 -> V_2 , L_93 ,
V_12 ) ;
V_8 = - V_84 ;
goto V_242;
}
V_166 -> V_212 = V_213 ;
V_193 -> V_195 = V_166 ;
V_8 = F_73 ( V_193 , V_40 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_94 ,
V_12 , V_8 ) ;
goto V_242;
}
++ V_194 -> V_236 ;
goto V_238;
V_242:
if ( V_166 -> V_194 -> V_236 == 0 )
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_237 ) ;
V_238:
F_88 ( & V_194 -> V_234 ) ;
return V_8 ;
}
static void F_89 ( struct V_17 * V_18 )
{
struct V_35 * V_194 ;
struct V_46 * V_166 ;
struct V_62 * V_22 = V_18 -> V_22 ;
int V_20 ;
V_194 = F_90 ( V_18 -> V_22 ) ;
V_166 = F_72 ( V_18 ) ;
if ( V_194 == NULL || V_166 == NULL )
return;
V_166 -> V_210 = 1 ;
F_20 ( V_166 , ( V_65 * V_243 ) / 100 , 1 ) ;
F_87 ( V_18 -> V_241 ) ;
F_87 ( V_18 -> V_239 ) ;
V_166 -> V_217 = 0 ;
F_4 ( & V_18 -> V_2 , L_95 , V_12 ) ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
F_91 ( & V_22 -> V_244 ) ;
if ( ! V_22 -> V_72 ) {
F_7 ( V_22 -> V_2 ,
V_245 ,
( T_1 ) ( V_25 + V_20 ) ,
0 ,
NULL ,
0 ) ;
}
F_88 ( & V_22 -> V_244 ) ;
F_91 ( & V_194 -> V_234 ) ;
-- V_166 -> V_194 -> V_236 ;
if ( V_166 -> V_194 -> V_236 <= 0 ) {
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_237 ) ;
V_166 -> V_194 -> V_236 = 0 ;
}
F_88 ( & V_194 -> V_234 ) ;
V_166 -> V_210 = 0 ;
}
static int F_92 ( struct V_60 * V_61 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_246 )
{
struct V_46 * V_166 = F_72 ( V_18 ) ;
if ( V_246 == 0 ) {
F_4 ( & V_18 -> V_2 , L_96 , V_12 ) ;
return 0 ;
}
if ( V_166 == NULL )
return - V_79 ;
if ( V_166 -> V_210 == 1 )
return - V_79 ;
V_246 = F_93 ( & V_166 -> V_71 , V_6 , V_246 ,
& V_166 -> V_67 ) ;
F_81 ( V_61 ) ;
return V_246 ;
}
static void F_81 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
int V_246 , V_248 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
unsigned long V_64 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
if ( V_166 -> V_217 ) {
F_28 ( & V_166 -> V_67 , V_64 ) ;
return;
}
V_246 = F_94 ( & V_166 -> V_71 ,
V_18 -> V_239 -> V_196 ,
V_18 -> V_249 ) ;
if ( V_246 == 0 ) {
F_28 ( & V_166 -> V_67 , V_64 ) ;
return;
}
V_166 -> V_217 = 1 ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
F_11 ( & V_18 -> V_2 , V_12 , V_246 , V_18 -> V_239 -> V_196 ) ;
V_18 -> V_239 -> V_250 = V_246 ;
V_248 = F_73 ( V_18 -> V_239 , V_208 ) ;
if ( V_248 ) {
F_80 ( V_18 ,
L_97 ,
V_12 , V_248 ) ;
V_166 -> V_217 = 0 ;
} else
V_166 -> V_169 . V_251 += V_246 ;
if ( V_61 )
F_66 ( V_61 ) ;
}
static int F_95 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_252 = 0 ;
unsigned long V_64 ;
if ( V_166 == NULL )
return 0 ;
if ( V_166 -> V_210 == 1 )
return 0 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
V_252 = F_96 ( & V_166 -> V_71 ) ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
F_4 ( & V_18 -> V_2 , L_98 , V_12 , V_252 ) ;
return V_252 ;
}
static int F_97 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_253 = 0 ;
unsigned long V_64 ;
if ( V_166 == NULL )
return 0 ;
if ( V_166 -> V_210 == 1 )
return 0 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
V_253 = F_26 ( & V_166 -> V_71 ) ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
F_4 ( & V_18 -> V_2 , L_98 , V_12 , V_253 ) ;
return V_253 ;
}
static void F_98 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_8 ;
if ( V_166 == NULL )
return;
if ( F_99 ( V_61 ) ) {
unsigned char V_254 = F_100 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_254 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_99 , V_12 , V_8 ) ;
}
}
if ( F_65 ( V_61 ) )
F_101 ( V_166 ) ;
}
static void F_102 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_8 ;
if ( V_166 == NULL )
return;
if ( F_99 ( V_61 ) ) {
unsigned char V_255 = F_103 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_255 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_100 , V_12 , V_8 ) ;
}
}
if ( F_65 ( V_61 ) ) {
V_8 = F_104 ( V_166 ) ;
if ( V_8 )
F_16 ( & V_18 -> V_2 ,
L_101 ,
V_12 , V_8 ) ;
}
}
static void F_101 ( struct V_46 * V_166 )
{
unsigned long V_64 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
if ( V_166 -> V_212 == V_213 )
V_166 -> V_212 = V_214 ;
V_166 -> V_233 &= ~ V_162 ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
}
static int F_104 ( struct V_46 * V_166 )
{
struct V_193 * V_193 ;
int V_8 = 0 ;
unsigned long V_64 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
if ( V_166 -> V_212 == V_215 ) {
V_193 = V_166 -> V_18 -> V_241 ;
V_8 = F_73 ( V_193 , V_208 ) ;
}
V_166 -> V_212 = V_213 ;
V_166 -> V_233 |= V_162 ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
return V_8 ;
}
static void F_105 ( struct V_60 * V_61 ,
struct V_46 * V_166 , struct V_256 * V_257 )
{
struct V_43 * V_2 = & V_166 -> V_18 -> V_2 ;
struct V_258 * V_75 ;
int V_259 ;
unsigned V_260 ;
int V_8 ;
int V_20 = V_166 -> V_18 -> V_21 -
V_166 -> V_18 -> V_22 -> V_23 ;
F_4 ( V_2 , L_102 , V_12 , V_166 -> V_18 -> V_21 ) ;
V_75 = F_15 ( sizeof ( * V_75 ) , V_40 ) ;
if ( ! V_75 ) {
V_61 -> V_224 = * V_257 ;
F_16 ( V_2 , L_6 , V_12 ) ;
return;
}
V_260 = V_61 -> V_224 . V_261 ;
V_75 -> V_262 = 0 ;
V_75 -> V_262 |= V_263 ;
V_75 -> V_262 |= V_264 ;
V_75 -> V_265 = ( T_1 ) ( V_166 -> V_265 ) ;
switch ( V_260 & V_266 ) {
case V_267 :
V_75 -> V_268 = V_269 ;
F_4 ( V_2 , L_103 , V_12 ) ;
break;
case V_270 :
V_75 -> V_268 = V_271 ;
F_4 ( V_2 , L_104 , V_12 ) ;
break;
case V_272 :
V_75 -> V_268 = V_273 ;
F_4 ( V_2 , L_105 , V_12 ) ;
break;
default:
case V_274 :
V_75 -> V_268 = V_275 ;
F_4 ( V_2 , L_106 , V_12 ) ;
break;
}
if ( V_260 & V_276 ) {
if ( V_260 & V_277 ) {
V_75 -> V_262 |= V_278 ;
V_75 -> V_279 = V_280 ;
F_4 ( V_2 , L_107 , V_12 ) ;
} else {
V_75 -> V_262 |= V_278 ;
V_75 -> V_279 = V_281 ;
F_4 ( V_2 , L_108 , V_12 ) ;
}
} else {
V_75 -> V_279 = V_282 ;
F_4 ( V_2 , L_109 , V_12 ) ;
}
if ( V_260 & V_283 ) {
V_75 -> V_284 = V_285 ;
F_4 ( V_2 , L_110 , V_12 ) ;
} else {
V_75 -> V_284 = V_286 ;
F_4 ( V_2 , L_111 , V_12 ) ;
}
if ( V_260 & V_287 ) {
V_75 -> V_262 |= V_288 ;
V_75 -> V_262 |= V_289 ;
F_4 ( V_2 , L_112 , V_12 ) ;
} else {
F_4 ( V_2 , L_113 , V_12 ) ;
V_61 -> V_181 = 0 ;
F_104 ( V_166 ) ;
}
V_75 -> V_290 = F_103 ( V_61 ) ;
V_75 -> V_291 = F_100 ( V_61 ) ;
if ( F_99 ( V_61 ) ) {
V_75 -> V_262 |= V_292 ;
F_4 ( V_2 , L_114 ,
V_12 , V_75 -> V_290 , V_75 -> V_291 ) ;
} else
F_4 ( V_2 , L_115 , V_12 ) ;
if ( F_106 ( V_61 ) ) {
V_75 -> V_262 |= V_293 ;
F_4 ( V_2 , L_116 ,
V_12 , V_75 -> V_290 , V_75 -> V_291 ) ;
} else
F_4 ( V_2 , L_117 , V_12 ) ;
V_61 -> V_224 . V_261 &= ~ V_294 ;
V_259 = F_107 ( V_61 ) ;
if ( ! V_259 ) {
V_259 = 9600 ;
} else
F_108 ( V_61 , V_259 , V_259 ) ;
V_166 -> V_59 = V_259 ;
V_75 -> V_295 = ( T_2 ) ( ( 461550L + V_259 / 2 ) / V_259 ) ;
F_4 ( V_2 , L_118 , V_12 , V_259 , V_75 -> V_295 ) ;
F_4 ( V_2 , L_119 , ( int ) ( 461550L / V_75 -> V_295 ) ) ;
F_4 ( V_2 , L_120 , V_75 -> V_262 ) ;
F_4 ( V_2 , L_121 , V_75 -> V_268 ) ;
F_4 ( V_2 , L_122 , V_75 -> V_279 ) ;
F_4 ( V_2 , L_123 , V_75 -> V_284 ) ;
F_4 ( V_2 , L_124 , V_75 -> V_290 ) ;
F_4 ( V_2 , L_125 , V_75 -> V_291 ) ;
F_4 ( V_2 , L_126 , V_75 -> V_265 ) ;
F_109 ( & V_75 -> V_262 ) ;
F_109 ( & V_75 -> V_295 ) ;
V_8 = F_7 ( V_166 -> V_18 -> V_22 -> V_2 , V_296 ,
( T_1 ) ( V_25 + V_20 ) ,
0 , ( T_1 * ) V_75 , sizeof( * V_75 ) ) ;
if ( V_8 )
F_4 ( V_2 , L_127 ,
V_12 , V_8 ) ;
F_17 ( V_75 ) ;
}
static void F_84 ( struct V_60 * V_61 ,
struct V_17 * V_18 , struct V_256 * V_257 )
{
struct V_46 * V_166 = F_72 ( V_18 ) ;
unsigned int V_260 ;
V_260 = V_61 -> V_224 . V_261 ;
F_4 ( & V_18 -> V_2 , L_128 , V_12 ,
V_61 -> V_224 . V_261 , V_61 -> V_224 . V_297 ) ;
F_4 ( & V_18 -> V_2 , L_129 , V_12 ,
V_257 -> V_261 , V_257 -> V_297 ) ;
F_4 ( & V_18 -> V_2 , L_102 , V_12 , V_18 -> V_21 ) ;
if ( V_166 == NULL )
return;
F_105 ( V_61 , V_166 , V_257 ) ;
}
static int F_110 ( struct V_60 * V_61 ,
unsigned int V_298 , unsigned int V_299 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
unsigned int V_158 ;
unsigned long V_64 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
V_158 = V_166 -> V_233 ;
if ( V_298 & V_300 )
V_158 |= V_162 ;
if ( V_298 & V_301 )
V_158 |= V_160 ;
if ( V_298 & V_302 )
V_158 |= V_164 ;
if ( V_299 & V_300 )
V_158 &= ~ V_162 ;
if ( V_299 & V_301 )
V_158 &= ~ V_160 ;
if ( V_299 & V_302 )
V_158 &= ~ V_164 ;
V_166 -> V_233 = V_158 ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
F_60 ( V_166 , V_158 ) ;
return 0 ;
}
static int F_111 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
unsigned int V_248 = 0 ;
unsigned int V_167 ;
unsigned int V_158 ;
unsigned long V_64 ;
F_22 ( & V_166 -> V_67 , V_64 ) ;
V_167 = V_166 -> V_179 ;
V_158 = V_166 -> V_233 ;
V_248 = ( ( V_158 & V_160 ) ? V_301 : 0 )
| ( ( V_158 & V_162 ) ? V_300 : 0 )
| ( ( V_167 & V_180 ) ? V_303 : 0 )
| ( ( V_167 & V_304 ) ? V_305 : 0 )
| ( ( V_167 & V_306 ) ? V_307 : 0 )
| ( ( V_167 & V_308 ) ? V_309 : 0 ) ;
F_4 ( & V_18 -> V_2 , L_130 , V_12 , V_248 ) ;
F_28 ( & V_166 -> V_67 , V_64 ) ;
return V_248 ;
}
static int F_112 ( struct V_60 * V_61 ,
struct V_310 * V_169 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
struct V_168 * V_311 = & V_166 -> V_169 ;
V_169 -> V_174 = V_311 -> V_174 ;
V_169 -> V_175 = V_311 -> V_175 ;
V_169 -> V_177 = V_311 -> V_177 ;
V_169 -> V_176 = V_311 -> V_176 ;
V_169 -> V_251 = V_311 -> V_251 ;
V_169 -> V_211 = V_311 -> V_211 ;
V_169 -> V_192 = V_311 -> V_192 ;
V_169 -> V_191 = V_311 -> V_191 ;
V_169 -> V_190 = V_311 -> V_190 ;
V_169 -> V_189 = V_311 -> V_189 ;
V_169 -> V_312 = V_311 -> V_312 ;
return 0 ;
}
static int F_113 ( struct V_46 * V_166 ,
struct V_313 T_9 * V_314 )
{
struct V_313 V_315 ;
if ( ! V_314 )
return - V_316 ;
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
V_315 . type = V_317 ;
V_315 . line = V_166 -> V_18 -> V_22 -> V_23 ;
V_315 . V_18 = V_166 -> V_18 -> V_21 ;
V_315 . V_318 = 0 ;
V_315 . V_64 = V_319 | V_320 ;
V_315 . V_321 = V_166 -> V_18 -> V_249 ;
V_315 . V_322 = 9600 ;
V_315 . V_323 = 5 * V_65 ;
V_315 . V_243 = V_243 ;
if ( F_114 ( V_314 , & V_315 , sizeof( * V_314 ) ) )
return - V_316 ;
return 0 ;
}
static int F_115 ( struct V_60 * V_61 ,
unsigned int V_324 , unsigned long V_325 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
struct V_168 V_326 ;
struct V_168 V_327 ;
F_4 ( & V_18 -> V_2 , L_131 , V_12 , V_18 -> V_21 , V_324 ) ;
switch ( V_324 ) {
case V_328 :
F_4 ( & V_18 -> V_2 , L_132 , V_12 ) ;
return F_113 ( V_166 ,
(struct V_313 T_9 * ) V_325 ) ;
case V_329 :
F_4 ( & V_18 -> V_2 , L_133 , V_12 ) ;
V_327 = V_166 -> V_169 ;
while ( 1 ) {
F_116 ( & V_166 -> V_178 ) ;
if ( F_27 ( V_68 ) )
return - V_235 ;
V_326 = V_166 -> V_169 ;
if ( V_326 . V_177 == V_327 . V_177 && V_326 . V_175 == V_327 . V_175 &&
V_326 . V_176 == V_327 . V_176 && V_326 . V_174 == V_327 . V_174 )
return - V_330 ;
if ( ( ( V_325 & V_331 ) && ( V_326 . V_177 != V_327 . V_177 ) ) ||
( ( V_325 & V_309 ) && ( V_326 . V_175 != V_327 . V_175 ) ) ||
( ( V_325 & V_332 ) && ( V_326 . V_176 != V_327 . V_176 ) ) ||
( ( V_325 & V_303 ) && ( V_326 . V_174 != V_327 . V_174 ) ) ) {
return 0 ;
}
V_327 = V_326 ;
}
break;
}
return - V_333 ;
}
static void F_117 ( struct V_60 * V_61 , int V_334 )
{
struct V_17 * V_18 = V_61 -> V_247 ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
int V_8 ;
int V_335 = 0 ;
F_20 ( V_166 , 0 , 0 ) ;
if ( V_334 == - 1 )
V_335 = 1 ;
V_8 = F_59 ( V_166 , V_336 , V_335 ) ;
if ( V_8 )
F_4 ( & V_18 -> V_2 , L_134 ,
V_12 , V_8 ) ;
}
static int F_118 ( struct V_62 * V_22 )
{
struct V_35 * V_194 ;
int V_8 ;
V_194 = F_119 ( sizeof( struct V_35 ) , V_40 ) ;
if ( V_194 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_135 , V_12 ) ;
return - V_41 ;
}
F_120 ( & V_194 -> V_234 ) ;
V_194 -> V_22 = V_22 ;
F_121 ( V_22 , V_194 ) ;
V_8 = F_56 ( V_194 ) ;
if ( V_8 ) {
F_17 ( V_194 ) ;
return V_8 ;
}
return 0 ;
}
static void F_122 ( struct V_62 * V_22 )
{
}
static void F_123 ( struct V_62 * V_22 )
{
F_17 ( F_90 ( V_22 ) ) ;
}
static int F_124 ( struct V_17 * V_18 )
{
struct V_46 * V_166 ;
int V_337 ;
V_166 = F_119 ( sizeof( * V_166 ) , V_40 ) ;
if ( ! V_166 )
return - V_41 ;
V_337 = F_125 ( & V_166 -> V_71 , V_338 ,
V_40 ) ;
if ( V_337 ) {
F_17 ( V_166 ) ;
return - V_41 ;
}
F_126 ( & V_166 -> V_67 ) ;
V_166 -> V_18 = V_18 ;
V_166 -> V_194 = F_90 ( V_18 -> V_22 ) ;
V_166 -> V_265 = V_339 ;
F_127 ( V_18 , V_166 ) ;
V_337 = F_128 ( V_18 ) ;
if ( V_337 ) {
F_129 ( & V_166 -> V_71 ) ;
F_17 ( V_166 ) ;
return V_337 ;
}
return 0 ;
}
static int F_130 ( struct V_17 * V_18 )
{
struct V_46 * V_166 ;
V_166 = F_72 ( V_18 ) ;
F_131 ( V_18 ) ;
F_129 ( & V_166 -> V_71 ) ;
F_17 ( V_166 ) ;
return 0 ;
}
static T_10 F_132 ( struct V_43 * V_2 ,
struct V_340 * V_341 , char * V_342 )
{
struct V_17 * V_18 = F_133 ( V_2 ) ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
return sprintf ( V_342 , L_64 , V_166 -> V_265 ) ;
}
static T_10 F_134 ( struct V_43 * V_2 ,
struct V_340 * V_341 , const char * V_343 , T_11 V_246 )
{
struct V_17 * V_18 = F_133 ( V_2 ) ;
struct V_46 * V_166 = F_72 ( V_18 ) ;
unsigned int V_344 = F_135 ( V_343 , NULL , 0 ) ;
F_4 ( V_2 , L_136 , V_12 , V_344 ) ;
if ( V_344 < 256 )
V_166 -> V_265 = V_344 ;
else
F_16 ( V_2 , L_137 , V_12 , V_344 ) ;
return V_246 ;
}
static int F_128 ( struct V_17 * V_18 )
{
return F_136 ( & V_18 -> V_2 , & V_345 ) ;
}
static int F_131 ( struct V_17 * V_18 )
{
F_137 ( & V_18 -> V_2 , & V_345 ) ;
return 0 ;
}
