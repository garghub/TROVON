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
T_5 V_62 ;
unsigned long V_63 ;
if ( ! V_57 )
V_57 = ( V_64 * V_65 ) / 100 ;
F_22 ( & V_18 -> V_66 , V_63 ) ;
F_23 ( & V_62 , V_67 ) ;
F_24 ( & V_61 -> V_68 , & V_62 ) ;
for (; ; ) {
F_25 ( V_69 ) ;
if ( F_26 ( & V_18 -> V_70 ) == 0
|| V_57 == 0 || F_27 ( V_67 )
|| ! F_28 ( V_18 -> V_18 -> V_22 -> V_71 ) )
break;
F_29 ( & V_18 -> V_66 , V_63 ) ;
V_57 = F_30 ( V_57 ) ;
F_22 ( & V_18 -> V_66 , V_63 ) ;
}
F_25 ( V_72 ) ;
F_31 ( & V_61 -> V_68 , & V_62 ) ;
if ( V_58 )
F_32 ( & V_18 -> V_70 ) ;
F_29 ( & V_18 -> V_66 , V_63 ) ;
F_33 ( V_61 ) ;
V_57 += V_73 ;
while ( ( long ) ( V_73 - V_57 ) < 0 && ! F_27 ( V_67 )
&& F_28 ( V_18 -> V_18 -> V_22 -> V_71 ) ) {
if ( ! F_19 ( V_18 ) )
break;
F_34 ( 10 ) ;
}
if ( ! F_28 ( V_18 -> V_18 -> V_22 -> V_71 ) )
return;
V_59 = V_18 -> V_59 ;
if ( V_59 == 0 )
V_59 = 50 ;
F_34 ( F_35 ( 1 , F_36 ( 10000 , V_59 ) ) ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_4 ( L_15 ,
V_12 , V_2 -> V_74 -> V_75 . V_76 ) ;
F_4 ( L_16 ,
V_12 , V_2 -> V_74 -> V_75 . V_77 * 2 ) ;
if ( V_2 -> V_74 -> V_75 . V_76 != 1 ) {
F_16 ( & V_2 -> V_2 , L_17 ,
V_12 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_38 ( struct V_36 * V_22 ,
int V_26 , int V_27 , T_1 * V_29 )
{
int V_8 ;
if ( V_22 -> V_79 . V_80 == V_81 ) {
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
static int F_39 ( struct V_36 * V_22 , int V_26 ,
int V_27 , T_1 * V_29 )
{
if ( V_22 -> V_79 . V_80 == V_82 )
return F_14 ( V_22 , V_26 , V_27 ,
V_29 ) ;
if ( V_22 -> V_79 . V_80 == V_81 )
return F_18 ( V_22 , V_26 , V_27 ,
V_22 -> V_38 , V_29 ) ;
return - V_83 ;
}
static int F_40 ( struct V_36 * V_22 ,
int V_84 , struct V_85 * V_86 )
{
int V_26 ;
int V_8 ;
V_26 = 2 ;
do {
V_8 = F_38 ( V_22 ,
V_26 ,
sizeof( struct V_85 ) ,
( T_1 * ) V_86 ) ;
if ( V_8 )
return 0 ;
if ( V_86 -> Type == V_84 )
return V_26 ;
V_26 = V_26 + sizeof( struct V_85 )
+ V_86 -> V_87 ;
} while ( ( V_26 < V_88 ) && V_86 -> Type );
return 0 ;
}
static int F_41 ( struct V_85 * V_86 , T_1 * V_29 )
{
T_2 V_37 ;
T_1 V_89 = 0 ;
for ( V_37 = 0 ; V_37 < V_86 -> V_87 ; V_37 ++ )
V_89 = ( T_1 ) ( V_89 + V_29 [ V_37 ] ) ;
if ( V_89 != V_86 -> V_90 ) {
F_4 ( L_18 , V_12 , V_86 -> V_90 , V_89 ) ;
return - V_83 ;
}
return 0 ;
}
static int F_42 ( struct V_36 * V_22 )
{
struct V_91 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
struct V_85 * V_86 ;
int V_26 = 2 ;
T_1 * V_29 ;
T_2 V_92 ;
V_86 = F_15 ( sizeof( * V_86 ) , V_41 ) ;
if ( ! V_86 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
V_29 = F_15 ( V_88 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_19 ,
V_12 ) ;
F_17 ( V_86 ) ;
return - V_42 ;
}
V_8 = F_38 ( V_22 , 0 , 1 , V_29 ) ;
if ( V_8 )
goto V_93;
if ( * V_29 != V_94 && * V_29 != V_95 ) {
F_16 ( V_2 , L_20 , V_12 ) ;
V_8 = - V_78 ;
goto V_93;
}
do {
V_8 = F_38 ( V_22 ,
V_26 ,
sizeof( struct V_85 ) ,
( T_1 * ) V_86 ) ;
if ( V_8 )
break;
if ( ( V_26 + sizeof( struct V_85 ) +
V_86 -> V_87 ) > V_88 ) {
V_8 = - V_78 ;
F_4 ( L_21 , V_12 ) ;
break;
}
F_4 ( L_22 , V_12 , V_86 -> Type ) ;
V_92 = V_86 -> Type & 0x0f ;
if ( V_92 != V_96
&& V_92 != V_97 ) {
V_8 = F_38 ( V_22 , V_26 +
sizeof( struct V_85 ) ,
V_86 -> V_87 , V_29 ) ;
if ( V_8 )
break;
V_8 = F_41 ( V_86 , V_29 ) ;
if ( V_8 )
break;
}
V_26 = V_26 + sizeof( struct V_85 ) +
V_86 -> V_87 ;
} while ( ( V_86 -> Type != V_98 ) &&
( V_26 < V_88 ) );
if ( ( V_86 -> Type != V_98 ) ||
( V_26 > V_88 ) )
V_8 = - V_78 ;
V_93:
F_17 ( V_29 ) ;
F_17 ( V_86 ) ;
return V_8 ;
}
static int F_43 ( struct V_36 * V_22 , T_1 * V_29 )
{
int V_8 ;
int V_26 ;
struct V_85 * V_86 ;
struct V_99 * V_75 ;
V_86 = F_15 ( sizeof( * V_86 ) , V_41 ) ;
if ( ! V_86 ) {
F_16 ( & V_22 -> V_22 -> V_2 -> V_2 , L_6 ,
V_12 ) ;
return - V_42 ;
}
V_26 = F_40 ( V_22 , V_98 ,
V_86 ) ;
if ( ! V_26 ) {
F_4 ( L_23 , V_12 ) ;
V_8 = - V_78 ;
goto exit;
}
V_8 = F_38 ( V_22 , V_26 + sizeof( struct V_85 ) ,
V_86 -> V_87 , V_29 ) ;
if ( V_8 )
goto exit;
V_8 = F_41 ( V_86 , V_29 ) ;
V_75 = (struct V_99 * ) V_29 ;
F_4 ( L_24 , V_12 , V_75 -> V_100 ) ;
F_4 ( L_25 , V_12 , V_75 -> V_101 ) ;
F_4 ( L_26 , V_12 , V_75 -> V_102 ) ;
F_4 ( L_27 , V_12 , V_75 -> V_103 ) ;
F_4 ( L_28 , V_12 , V_75 -> V_104 ) ;
F_4 ( L_29 , V_12 , V_75 -> V_105 ) ;
exit:
F_17 ( V_86 ) ;
return V_8 ;
}
static int F_44 ( T_1 * V_106 , struct V_91 * V_2 )
{
T_1 * V_29 ;
int V_107 ;
int V_37 ;
int V_108 ;
T_1 V_89 = 0 ;
struct V_85 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
const struct V_114 * V_115 ;
const char * V_116 = L_30 ;
V_107 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_112 ) ) ;
V_29 = F_15 ( V_107 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
memset ( V_29 , 0xff , V_107 ) ;
V_108 = F_45 ( & V_115 , V_116 , V_2 ) ;
if ( V_108 ) {
F_46 ( V_117 L_31 ,
V_116 , V_108 ) ;
F_17 ( V_29 ) ;
return V_108 ;
}
V_118 = V_115 -> V_6 [ 0 ] ;
V_119 = V_115 -> V_6 [ 1 ] ;
V_120 = V_115 -> V_6 [ 2 ] | ( V_115 -> V_6 [ 3 ] << 8 ) ;
V_113 = (struct V_112 * ) V_29 ;
V_113 -> V_121 = V_118 ;
V_113 -> V_122 = V_119 ;
V_111 = (struct V_110 * ) & V_115 -> V_6 [ 4 ] ;
memcpy ( V_29 + sizeof( struct V_112 ) ,
& V_115 -> V_6 [ 4 + sizeof( struct V_110 ) ] ,
F_47 ( V_111 -> V_123 ) ) ;
F_48 ( V_115 ) ;
for ( V_37 = 0 ; V_37 < V_107 ; V_37 ++ ) {
V_89 = ( T_1 ) ( V_89 + V_29 [ V_37 ] ) ;
}
F_17 ( V_29 ) ;
V_109 = (struct V_85 * ) V_106 ;
V_113 = (struct V_112 * ) V_109 -> V_124 ;
V_109 -> Type = V_125 ;
V_109 -> V_87 = ( T_2 ) V_107 ;
V_109 -> V_90 = V_89 ;
V_113 -> V_121 = V_118 ;
V_113 -> V_122 = V_119 ;
return 0 ;
}
static int F_49 ( struct V_36 * V_22 )
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
V_126 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( L_32 , V_12 , V_8 ) ;
else
F_4 ( L_33 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_94 || * V_6 == V_95 ) ) {
F_4 ( L_34 , V_12 ) ;
V_22 -> V_38 = V_126 ;
goto V_93;
}
V_8 = F_1 ( V_22 -> V_22 -> V_2 , V_32 ,
V_127 , 0 , V_6 , 0x01 ) ;
if ( V_8 )
F_4 ( L_35 , V_12 , V_8 ) ;
else
F_4 ( L_33 , V_12 , * V_6 ) ;
if ( ( ! V_8 ) && ( * V_6 == V_94 || * V_6 == V_95 ) ) {
F_4 ( L_36 , V_12 ) ;
V_22 -> V_38 = V_127 ;
goto V_93;
}
F_4 ( L_37 , V_12 ) ;
V_22 -> V_38 = V_126 ;
V_8 = - V_78 ;
V_93:
F_17 ( V_6 ) ;
return V_8 ;
}
static int F_50 ( struct V_128 * V_22 , void * V_29 ,
int V_27 , int * V_129 )
{
int V_8 ;
V_8 = F_51 ( V_22 -> V_2 ,
F_52 ( V_22 -> V_2 ,
V_22 -> V_18 [ 0 ] -> V_130 ) ,
V_29 , V_27 , V_129 , 1000 ) ;
return V_8 ;
}
static int F_53 ( struct V_36 * V_22 , T_1 * V_131 ,
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
V_8 = F_50 ( V_22 -> V_22 , & V_131 [ V_133 ] ,
V_134 , & V_135 ) ;
if ( V_8 )
break;
V_133 += V_135 ;
}
return V_8 ;
}
static int F_54 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_55 ( struct V_99 * V_75 )
{
return F_56 ( V_75 -> V_102 ) ;
}
static int F_57 ( struct V_36 * V_22 )
{
struct V_91 * V_2 = & V_22 -> V_22 -> V_2 -> V_2 ;
int V_8 = 0 ;
int V_26 ;
struct V_99 * V_137 ;
struct V_138 * V_71 ;
int V_139 ;
int V_140 ;
V_22 -> V_79 . V_141 = V_142 ;
V_22 -> V_38 = V_126 ;
V_8 = F_37 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_71 = & V_22 -> V_22 -> V_71 -> V_143 -> V_75 ;
if ( ! V_71 ) {
F_16 ( V_2 , L_38 , V_12 ) ;
return - V_78 ;
}
if ( V_71 -> V_144 > 1 )
V_22 -> V_79 . V_80 = V_81 ;
else
V_22 -> V_79 . V_80 = V_145 ;
if ( V_22 -> V_79 . V_80 == V_81 ) {
struct V_85 * V_86 ;
F_4 ( L_39 , V_12 ) ;
V_8 = F_42 ( V_22 ) ;
if ( V_8 ) {
F_4 ( L_40 , V_12 ) ;
return V_8 ;
}
V_137 = F_15 ( sizeof( * V_137 ) , V_41 ) ;
if ( ! V_137 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
return - V_42 ;
}
V_8 = F_43 ( V_22 , ( T_1 * ) V_137 ) ;
if ( V_8 ) {
F_17 ( V_137 ) ;
return V_8 ;
}
if ( ! V_146 && F_55 ( V_137 ) < 2 ) {
F_4 ( L_42 ,
V_12 , F_55 ( V_137 ) ) ;
F_17 ( V_137 ) ;
return - V_83 ;
}
V_86 = F_15 ( sizeof( * V_86 ) , V_41 ) ;
if ( ! V_86 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_26 = F_40 ( V_22 ,
V_96 , V_86 ) ;
if ( V_26 != 0 ) {
struct V_112 * V_147 ;
T_3 * V_148 ;
F_4 ( L_43 ,
V_12 ) ;
V_147 = F_15 ( sizeof( * V_147 ) ,
V_41 ) ;
if ( ! V_147 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_8 = F_38 ( V_22 , V_26 +
sizeof( struct V_85 ) ,
sizeof( struct V_112 ) ,
( T_1 * ) V_147 ) ;
if ( V_8 ) {
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
V_139 = ( V_147 -> V_121 << 8 ) +
( V_147 -> V_122 ) ;
V_140 = ( V_118 << 8 ) +
( V_119 ) ;
F_4 ( L_44 ,
V_12 ,
V_147 -> V_121 ,
V_147 -> V_122 ,
V_118 ,
V_119 ) ;
if ( V_139 < V_140 ) {
F_4 ( L_45 ,
V_12 ,
V_147 -> V_121 ,
V_147 -> V_122 ,
V_118 ,
V_119 ) ;
V_148 = F_15 ( 1 , V_41 ) ;
if ( ! V_148 ) {
F_16 ( V_2 , L_41 ,
V_12 ) ;
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
* V_148 = V_125 ;
V_8 = F_39 ( V_22 , V_26 ,
sizeof( * V_148 ) , V_148 ) ;
if ( V_8 ) {
F_17 ( V_148 ) ;
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
V_8 = F_38 ( V_22 ,
V_26 ,
sizeof( * V_148 ) ,
V_148 ) ;
if ( V_8 ) {
F_17 ( V_148 ) ;
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
if ( * V_148 != V_125 ) {
F_16 ( V_2 ,
L_46 ,
V_12 ) ;
F_17 ( V_148 ) ;
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_78 ;
}
F_4 ( L_47 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_149 ,
0 , 0 , NULL , 0 ) ;
F_4 ( L_48 ,
V_12 , V_8 ) ;
F_17 ( V_148 ) ;
F_17 ( V_147 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_78 ;
}
F_17 ( V_147 ) ;
}
else if ( ( V_26 = F_40 ( V_22 , V_125 , V_86 ) ) != 0 ) {
#define F_58 (sizeof(struct ti_i2c_desc) + \
sizeof(struct ti_i2c_firmware_rec))
T_1 * V_106 ;
T_1 * V_150 ;
V_106 = F_15 ( F_58 , V_41 ) ;
if ( ! V_106 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
V_150 = F_15 ( F_58 , V_41 ) ;
if ( ! V_150 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
F_17 ( V_106 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_42 ;
}
F_4 ( L_49 ,
V_12 ) ;
V_8 = F_44 ( V_106 , V_2 ) ;
if ( V_8 ) {
F_17 ( V_150 ) ;
F_17 ( V_106 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_83 ;
}
V_8 = F_39 ( V_22 ,
V_26 ,
F_58 ,
V_106 ) ;
if ( V_8 ) {
F_17 ( V_150 ) ;
F_17 ( V_106 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_83 ;
}
V_8 = F_38 ( V_22 , V_26 ,
F_58 , V_150 ) ;
if ( V_8 ) {
F_4 ( L_50 , V_12 ) ;
F_17 ( V_150 ) ;
F_17 ( V_106 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
if ( memcmp ( V_150 , V_106 , F_58 ) ) {
F_4 ( L_51 ,
V_12 ) ;
F_17 ( V_150 ) ;
F_17 ( V_106 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return - V_83 ;
}
F_17 ( V_150 ) ;
F_17 ( V_106 ) ;
F_4 ( L_52 , V_12 ) ;
V_8 = F_5 ( V_22 -> V_22 -> V_2 ,
V_151 , 0 , 0 , NULL , 0 ) ;
F_4 ( L_53 , V_12 , V_8 ) ;
if ( V_8 ) {
F_16 ( V_2 ,
L_54 ,
V_12 ) ;
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return V_8 ;
}
}
F_17 ( V_86 ) ;
F_17 ( V_137 ) ;
return 0 ;
}
F_4 ( L_55 , V_12 ) ;
V_8 = F_54 ( V_22 -> V_22 -> V_2 ) ;
if ( V_8 )
return V_8 ;
if ( F_47 ( V_22 -> V_22 -> V_2 -> V_152 . V_153 )
!= V_154 ) {
F_4 ( L_56 , V_12 ,
F_47 ( V_22 -> V_22 -> V_2 -> V_152 . V_153 ) ) ;
V_22 -> V_38 = V_126 ;
goto V_155;
}
if ( F_49 ( V_22 ) )
goto V_155;
if ( ! F_42 ( V_22 ) ) {
struct V_110 * V_106 ;
int V_37 ;
T_1 V_89 = 0 ;
T_1 * V_29 ;
int V_107 ;
int V_108 ;
const struct V_114 * V_115 ;
const char * V_116 = L_30 ;
V_137 = F_15 ( sizeof( * V_137 ) , V_41 ) ;
if ( ! V_137 ) {
F_16 ( V_2 , L_41 , V_12 ) ;
return - V_42 ;
}
V_8 = F_43 ( V_22 , ( T_1 * ) V_137 ) ;
if ( V_8 ) {
F_17 ( V_137 ) ;
goto V_155;
}
if ( ! V_146 && F_55 ( V_137 ) < 2 ) {
F_4 ( L_42 ,
V_12 , F_55 ( V_137 ) ) ;
F_17 ( V_137 ) ;
goto V_155;
}
F_17 ( V_137 ) ;
V_107 = ( ( ( 1024 * 16 ) - 512 ) +
sizeof( struct V_110 ) ) ;
V_29 = F_15 ( V_107 , V_41 ) ;
if ( ! V_29 ) {
F_16 ( V_2 , L_6 , V_12 ) ;
return - V_42 ;
}
memset ( V_29 , 0xff , V_107 ) ;
V_108 = F_45 ( & V_115 , V_116 , V_2 ) ;
if ( V_108 ) {
F_46 ( V_117 L_31 ,
V_116 , V_108 ) ;
F_17 ( V_29 ) ;
return V_108 ;
}
memcpy ( V_29 , & V_115 -> V_6 [ 4 ] , V_115 -> V_7 - 4 ) ;
F_48 ( V_115 ) ;
for ( V_37 = sizeof( struct V_110 ) ;
V_37 < V_107 ; V_37 ++ ) {
V_89 = ( T_1 ) ( V_89 + V_29 [ V_37 ] ) ;
}
V_106 = (struct V_110 * ) V_29 ;
V_106 -> V_123 = F_59 ( ( T_2 ) ( V_107 -
sizeof( struct V_110 ) ) ) ;
V_106 -> V_90 = V_89 ;
F_4 ( L_57 ,
V_12 ) ;
V_8 = F_53 ( V_22 , V_29 , V_107 ) ;
F_17 ( V_29 ) ;
if ( V_8 ) {
F_4 ( L_58 ,
V_12 ) ;
return V_8 ;
}
V_22 -> V_79 . V_80 = V_156 ;
F_4 ( L_59 ,
V_12 ) ;
return - V_78 ;
}
V_155:
F_4 ( L_60 , V_12 ) ;
V_22 -> V_79 . V_80 = V_82 ;
return 0 ;
}
static int F_60 ( struct V_46 * V_18 , int V_157 , int V_158 )
{
int V_20 = V_18 -> V_18 -> V_21 - V_18 -> V_18 -> V_22 -> V_23 ;
V_158 = ! ! V_158 ;
return F_7 ( V_18 -> V_18 -> V_22 -> V_2 ,
V_157 , ( T_1 ) ( V_25 + V_20 ) ,
V_158 , NULL , 0 ) ;
}
static int F_61 ( struct V_46 * V_18 , T_1 V_159 )
{
int V_8 = 0 ;
F_4 ( L_61 , V_12 , V_159 ) ;
V_8 = F_60 ( V_18 , V_160 , V_159 & V_161 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_60 ( V_18 , V_162 , V_159 & V_163 ) ;
if ( V_8 )
return V_8 ;
return F_60 ( V_18 , V_164 , V_159 & V_165 ) ;
}
static T_1 F_62 ( T_1 V_166 )
{
T_1 V_49 = 0 ;
#define F_63 ( T_6 , T_7 ) \
if (ti_lsr & flagUmp) \
lsr |= flagUart;
F_63 (UMP_UART_LSR_OV_MASK, LSR_OVER_ERR)
F_63 (UMP_UART_LSR_PE_MASK, LSR_PAR_ERR)
F_63 (UMP_UART_LSR_FE_MASK, LSR_FRM_ERR)
F_63 (UMP_UART_LSR_BR_MASK, LSR_BREAK)
F_63 (UMP_UART_LSR_RX_MASK, LSR_RX_AVAIL)
F_63 (UMP_UART_LSR_TX_MASK, LSR_TX_EMPTY)
#undef F_63
return V_49 ;
}
static void F_64 ( struct V_46 * V_167 , T_1 V_168 )
{
struct V_169 * V_170 ;
struct V_60 * V_61 ;
F_4 ( L_62 , V_12 , V_168 ) ;
if ( V_168 & ( V_171 | V_172 |
V_173 | V_174 ) ) {
V_170 = & V_167 -> V_170 ;
if ( V_168 & V_171 )
V_170 -> V_175 ++ ;
if ( V_168 & V_172 )
V_170 -> V_176 ++ ;
if ( V_168 & V_174 )
V_170 -> V_177 ++ ;
if ( V_168 & V_173 )
V_170 -> V_178 ++ ;
F_65 ( & V_167 -> V_179 ) ;
}
V_167 -> V_180 = V_168 & 0xf0 ;
V_61 = F_21 ( & V_167 -> V_18 -> V_18 ) ;
if ( V_61 && F_66 ( V_61 ) ) {
if ( V_168 & V_181 ) {
V_61 -> V_182 = 0 ;
F_67 ( V_61 ) ;
} else {
V_61 -> V_182 = 1 ;
}
}
F_33 ( V_61 ) ;
}
static void F_68 ( struct V_46 * V_167 , int V_183 ,
T_1 V_49 , T_1 V_6 )
{
struct V_169 * V_170 ;
T_1 V_184 = ( T_1 ) ( V_49 & ( T_1 ) ( V_185 | V_186 |
V_187 | V_188 ) ) ;
struct V_60 * V_61 ;
F_4 ( L_62 , V_12 , V_184 ) ;
V_167 -> V_189 = V_49 ;
if ( V_184 & V_188 )
V_184 &= ( T_1 ) ( V_185 | V_188 ) ;
if ( V_183 ) {
V_61 = F_21 ( & V_167 -> V_18 -> V_18 ) ;
if ( V_61 ) {
F_69 ( & V_167 -> V_18 -> V_2 , V_61 , & V_6 , 1 ) ;
F_33 ( V_61 ) ;
}
}
V_170 = & V_167 -> V_170 ;
if ( V_184 & V_188 )
V_170 -> V_190 ++ ;
if ( V_184 & V_185 )
V_170 -> V_191 ++ ;
if ( V_184 & V_186 )
V_170 -> V_192 ++ ;
if ( V_184 & V_187 )
V_170 -> V_193 ++ ;
}
static void F_70 ( struct V_194 * V_194 )
{
struct V_36 * V_195 = V_194 -> V_196 ;
struct V_17 * V_18 ;
struct V_46 * V_167 ;
unsigned char * V_6 = V_194 -> V_197 ;
int V_27 = V_194 -> V_198 ;
int V_20 ;
int V_199 ;
int V_200 ;
T_1 V_49 ;
T_1 V_168 ;
int V_8 = V_194 -> V_8 ;
F_4 ( L_63 , V_12 ) ;
switch ( V_8 ) {
case 0 :
break;
case - V_201 :
case - V_202 :
case - V_203 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_194 -> V_2 -> V_2 , L_65
L_66 , V_12 , V_8 ) ;
goto exit;
}
if ( ! V_27 ) {
F_4 ( L_67 , V_12 ) ;
goto exit;
}
F_11 ( V_34 , & V_195 -> V_22 -> V_2 -> V_2 ,
V_12 , V_27 , V_6 ) ;
if ( V_27 != 2 ) {
F_4 ( L_68 ,
V_12 , V_27 ) ;
goto exit;
}
V_20 = F_71 ( V_6 [ 0 ] ) ;
V_199 = F_72 ( V_6 [ 0 ] ) ;
F_4 ( L_69 ,
V_12 , V_20 , V_199 , V_6 [ 1 ] ) ;
V_18 = V_195 -> V_22 -> V_18 [ V_20 ] ;
V_167 = F_73 ( V_18 ) ;
if ( ! V_167 ) {
F_4 ( L_70 , V_12 ) ;
return;
}
switch ( V_199 ) {
case V_204 :
V_49 = F_62 ( V_6 [ 1 ] ) ;
if ( V_49 & V_205 ) {
F_4 ( L_71 ,
V_12 , V_20 , V_49 ) ;
V_167 -> V_206 = 1 ;
V_167 -> V_207 = V_49 ;
} else {
F_4 ( L_72 ,
V_12 , V_20 , V_49 ) ;
F_68 ( V_167 , 0 , V_49 , 0 ) ;
}
break;
case V_208 :
V_168 = V_6 [ 1 ] ;
F_4 ( L_73 ,
V_12 , V_20 , V_168 ) ;
F_64 ( V_167 , V_168 ) ;
break;
default:
F_16 ( & V_194 -> V_2 -> V_2 ,
L_74 ,
V_12 , V_6 [ 1 ] ) ;
break;
}
exit:
V_200 = F_74 ( V_194 , V_209 ) ;
if ( V_200 )
F_16 ( & V_194 -> V_2 -> V_2 ,
L_75 ,
V_12 , V_200 ) ;
}
static void F_75 ( struct V_194 * V_194 )
{
struct V_46 * V_167 = V_194 -> V_196 ;
unsigned char * V_6 = V_194 -> V_197 ;
struct V_60 * V_61 ;
int V_200 = 0 ;
int V_20 ;
int V_8 = V_194 -> V_8 ;
F_4 ( L_63 , V_12 ) ;
switch ( V_8 ) {
case 0 :
break;
case - V_201 :
case - V_202 :
case - V_203 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_194 -> V_2 -> V_2 ,
L_76 ,
V_12 , V_8 ) ;
}
if ( V_8 == - V_210 )
goto exit;
if ( V_8 ) {
F_16 ( & V_194 -> V_2 -> V_2 , L_77 , V_12 ) ;
return;
}
V_20 = V_167 -> V_18 -> V_21 - V_167 -> V_18 -> V_22 -> V_23 ;
if ( V_167 -> V_206 ) {
V_167 -> V_206 = 0 ;
F_4 ( L_78 ,
V_12 , V_20 , V_167 -> V_207 , * V_6 ) ;
F_68 ( V_167 , 1 , V_167 -> V_207 , * V_6 ) ;
-- V_194 -> V_198 ;
++ V_6 ;
}
V_61 = F_21 ( & V_167 -> V_18 -> V_18 ) ;
if ( V_61 && V_194 -> V_198 ) {
F_11 ( V_34 , & V_167 -> V_18 -> V_2 ,
V_12 , V_194 -> V_198 , V_6 ) ;
if ( V_167 -> V_211 )
F_4 ( L_79 ,
V_12 ) ;
else
F_69 ( & V_167 -> V_18 -> V_2 , V_61 , V_6 ,
V_194 -> V_198 ) ;
V_167 -> V_170 . V_212 += V_194 -> V_198 ;
}
F_33 ( V_61 ) ;
exit:
F_76 ( & V_167 -> V_66 ) ;
if ( V_167 -> V_213 == V_214 ) {
V_194 -> V_2 = V_167 -> V_18 -> V_22 -> V_2 ;
V_200 = F_74 ( V_194 , V_209 ) ;
} else if ( V_167 -> V_213 == V_215 ) {
V_167 -> V_213 = V_216 ;
}
F_77 ( & V_167 -> V_66 ) ;
if ( V_200 )
F_16 ( & V_194 -> V_2 -> V_2 ,
L_75 ,
V_12 , V_200 ) ;
}
static void F_69 ( struct V_91 * V_2 , struct V_60 * V_61 ,
unsigned char * V_6 , int V_27 )
{
int V_217 ;
V_217 = F_78 ( V_61 , V_6 , V_27 ) ;
if ( V_217 < V_27 )
F_16 ( V_2 , L_80 ,
V_12 , V_27 - V_217 ) ;
F_79 ( V_61 ) ;
}
static void F_80 ( struct V_194 * V_194 )
{
struct V_17 * V_18 = V_194 -> V_196 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_8 = V_194 -> V_8 ;
struct V_60 * V_61 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
V_167 -> V_218 = 0 ;
switch ( V_8 ) {
case 0 :
break;
case - V_201 :
case - V_202 :
case - V_203 :
F_4 ( L_64 ,
V_12 , V_8 ) ;
return;
default:
F_16 ( & V_194 -> V_2 -> V_2 , L_82
L_83 , V_12 , V_8 ) ;
}
V_61 = F_21 ( & V_18 -> V_18 ) ;
F_81 ( V_61 ) ;
F_33 ( V_61 ) ;
}
static int F_82 ( struct V_60 * V_61 , struct V_17 * V_18 )
{
struct V_46 * V_167 = F_73 ( V_18 ) ;
struct V_36 * V_195 ;
struct V_1 * V_2 ;
struct V_194 * V_194 ;
int V_20 ;
int V_8 ;
T_8 V_219 ;
T_3 V_220 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return - V_78 ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
switch ( V_20 ) {
case 0 :
V_167 -> V_54 = V_221 ;
V_167 -> V_51 = V_222 ;
break;
case 1 :
V_167 -> V_54 = V_223 ;
V_167 -> V_51 = V_224 ;
break;
default:
F_16 ( & V_18 -> V_2 , L_84 ) ;
return - V_78 ;
}
F_4 ( L_85 ,
V_12 , V_20 , V_167 -> V_54 ,
V_167 -> V_51 ) ;
V_2 = V_18 -> V_22 -> V_2 ;
memset ( & ( V_167 -> V_170 ) , 0x00 , sizeof( V_167 -> V_170 ) ) ;
F_83 ( & V_167 -> V_179 ) ;
V_8 = F_60 ( V_167 , V_164 , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_86 ,
V_12 , V_8 ) ;
return V_8 ;
}
if ( V_61 )
F_84 ( V_61 , V_18 , V_61 -> V_225 ) ;
V_220 = 2 ;
V_167 -> V_226 =
F_35 ( 20 , ( ( V_220 * 3 ) / 2 ) ) ;
V_219 = ( T_3 ) ( V_227 |
V_228 |
( V_220 << 2 ) ) ;
F_4 ( L_87 , V_12 ) ;
V_8 = F_7 ( V_2 , V_229 ,
( T_3 ) ( V_25 + V_20 ) , V_219 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_88 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_7 ( V_2 , V_230 ,
( T_3 ) ( V_25 + V_20 ) , 0 , NULL , 0 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_89 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_18 , V_231 | V_232 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_90 ,
V_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_1 ( V_2 , V_233 , 0 ,
( T_2 ) ( V_25 + V_20 ) ,
& V_167 -> V_180 , 1 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 , L_91 ,
V_12 , V_8 ) ;
return V_8 ;
}
F_4 ( L_92 , V_167 -> V_180 ) ;
V_167 -> V_234 = V_163 | V_161 ;
F_4 ( L_93 , V_167 -> V_234 ) ;
V_195 = V_167 -> V_195 ;
if ( F_85 ( & V_195 -> V_235 ) )
return - V_236 ;
if ( V_195 -> V_237 == 0 ) {
V_194 = V_195 -> V_22 -> V_18 [ 0 ] -> V_238 ;
if ( ! V_194 ) {
F_16 ( & V_18 -> V_2 ,
L_94 ,
V_12 ) ;
V_8 = - V_83 ;
goto V_239;
}
V_194 -> V_240 = F_70 ;
V_194 -> V_196 = V_195 ;
V_194 -> V_2 = V_2 ;
V_8 = F_74 ( V_194 , V_41 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_95 ,
V_12 , V_8 ) ;
goto V_239;
}
}
F_86 ( V_2 , V_18 -> V_241 -> V_242 ) ;
F_86 ( V_2 , V_18 -> V_243 -> V_242 ) ;
V_194 = V_18 -> V_243 ;
if ( ! V_194 ) {
F_16 ( & V_18 -> V_2 , L_96 ,
V_12 ) ;
V_8 = - V_83 ;
goto V_244;
}
V_167 -> V_213 = V_214 ;
V_194 -> V_240 = F_75 ;
V_194 -> V_196 = V_167 ;
V_194 -> V_2 = V_2 ;
V_8 = F_74 ( V_194 , V_41 ) ;
if ( V_8 ) {
F_16 ( & V_18 -> V_2 ,
L_97 ,
V_12 , V_8 ) ;
goto V_244;
}
++ V_195 -> V_237 ;
F_4 ( L_98 , V_12 ) ;
goto V_239;
V_244:
if ( V_167 -> V_195 -> V_237 == 0 )
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_238 ) ;
V_239:
F_88 ( & V_195 -> V_235 ) ;
return V_8 ;
}
static void F_89 ( struct V_17 * V_18 )
{
struct V_36 * V_195 ;
struct V_46 * V_167 ;
int V_20 ;
int V_8 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
V_195 = F_90 ( V_18 -> V_22 ) ;
V_167 = F_73 ( V_18 ) ;
if ( V_195 == NULL || V_167 == NULL )
return;
V_167 -> V_211 = 1 ;
F_20 ( V_167 , ( V_64 * V_245 ) / 100 , 1 ) ;
F_87 ( V_18 -> V_243 ) ;
F_87 ( V_18 -> V_241 ) ;
V_167 -> V_218 = 0 ;
F_4 ( L_99 , V_12 ) ;
V_20 = V_18 -> V_21 - V_18 -> V_22 -> V_23 ;
V_8 = F_7 ( V_18 -> V_22 -> V_2 ,
V_246 ,
( T_1 ) ( V_25 + V_20 ) ,
0 ,
NULL ,
0 ) ;
F_91 ( & V_195 -> V_235 ) ;
-- V_167 -> V_195 -> V_237 ;
if ( V_167 -> V_195 -> V_237 <= 0 ) {
F_87 ( V_18 -> V_22 -> V_18 [ 0 ] -> V_238 ) ;
V_167 -> V_195 -> V_237 = 0 ;
}
F_88 ( & V_195 -> V_235 ) ;
V_167 -> V_211 = 0 ;
F_4 ( L_98 , V_12 ) ;
}
static int F_92 ( struct V_60 * V_61 , struct V_17 * V_18 ,
const unsigned char * V_6 , int V_247 )
{
struct V_46 * V_167 = F_73 ( V_18 ) ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_247 == 0 ) {
F_4 ( L_100 , V_12 ) ;
return 0 ;
}
if ( V_167 == NULL )
return - V_78 ;
if ( V_167 -> V_211 == 1 )
return - V_78 ;
V_247 = F_93 ( & V_167 -> V_70 , V_6 , V_247 ,
& V_167 -> V_66 ) ;
F_81 ( V_61 ) ;
return V_247 ;
}
static void F_81 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
int V_247 , V_249 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
unsigned long V_63 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
if ( V_167 -> V_218 ) {
F_29 ( & V_167 -> V_66 , V_63 ) ;
return;
}
V_247 = F_94 ( & V_167 -> V_70 ,
V_18 -> V_241 -> V_197 ,
V_18 -> V_250 ) ;
if ( V_247 == 0 ) {
F_29 ( & V_167 -> V_66 , V_63 ) ;
return;
}
V_167 -> V_218 = 1 ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
F_11 ( V_34 , & V_18 -> V_2 , V_12 , V_247 ,
V_18 -> V_241 -> V_197 ) ;
F_95 ( V_18 -> V_241 , V_18 -> V_22 -> V_2 ,
F_52 ( V_18 -> V_22 -> V_2 ,
V_18 -> V_130 ) ,
V_18 -> V_241 -> V_197 , V_247 ,
F_80 ,
V_18 ) ;
V_249 = F_74 ( V_18 -> V_241 , V_209 ) ;
if ( V_249 ) {
F_16 ( & V_18 -> V_2 ,
L_101 ,
V_12 , V_249 ) ;
V_167 -> V_218 = 0 ;
} else
V_167 -> V_170 . V_251 += V_247 ;
if ( V_61 )
F_67 ( V_61 ) ;
}
static int F_96 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_252 = 0 ;
unsigned long V_63 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return 0 ;
if ( V_167 -> V_211 == 1 )
return 0 ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
V_252 = F_97 ( & V_167 -> V_70 ) ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
F_4 ( L_102 , V_12 , V_252 ) ;
return V_252 ;
}
static int F_98 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_253 = 0 ;
unsigned long V_63 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return 0 ;
if ( V_167 -> V_211 == 1 )
return 0 ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
V_253 = F_26 ( & V_167 -> V_70 ) ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
F_4 ( L_102 , V_12 , V_253 ) ;
return V_253 ;
}
static void F_99 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_8 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return;
if ( F_100 ( V_61 ) ) {
unsigned char V_254 = F_101 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_254 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_103 , V_12 , V_8 ) ;
}
}
if ( F_66 ( V_61 ) )
F_102 ( V_167 ) ;
}
static void F_103 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_8 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return;
if ( F_100 ( V_61 ) ) {
unsigned char V_255 = F_104 ( V_61 ) ;
V_8 = F_92 ( V_61 , V_18 , & V_255 , 1 ) ;
if ( V_8 <= 0 ) {
F_16 ( & V_18 -> V_2 , L_104 , V_12 , V_8 ) ;
}
}
if ( F_66 ( V_61 ) ) {
V_8 = F_105 ( V_167 ) ;
if ( V_8 )
F_16 ( & V_18 -> V_2 ,
L_105 ,
V_12 , V_8 ) ;
}
}
static void F_102 ( struct V_46 * V_167 )
{
unsigned long V_63 ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
if ( V_167 -> V_213 == V_214 )
V_167 -> V_213 = V_215 ;
V_167 -> V_234 &= ~ V_163 ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
}
static int F_105 ( struct V_46 * V_167 )
{
struct V_194 * V_194 ;
int V_8 = 0 ;
unsigned long V_63 ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
if ( V_167 -> V_213 == V_216 ) {
V_194 = V_167 -> V_18 -> V_243 ;
V_194 -> V_240 = F_75 ;
V_194 -> V_196 = V_167 ;
V_194 -> V_2 = V_167 -> V_18 -> V_22 -> V_2 ;
V_8 = F_74 ( V_194 , V_209 ) ;
}
V_167 -> V_213 = V_214 ;
V_167 -> V_234 |= V_163 ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
return V_8 ;
}
static void F_106 ( struct V_60 * V_61 ,
struct V_46 * V_167 , struct V_256 * V_257 )
{
struct V_258 * V_74 ;
int V_259 ;
unsigned V_260 ;
int V_8 ;
int V_20 = V_167 -> V_18 -> V_21 -
V_167 -> V_18 -> V_22 -> V_23 ;
F_4 ( L_81 , V_12 , V_167 -> V_18 -> V_21 ) ;
V_74 = F_15 ( sizeof ( * V_74 ) , V_41 ) ;
if ( ! V_74 ) {
* V_61 -> V_225 = * V_257 ;
F_16 ( & V_167 -> V_18 -> V_2 , L_6 ,
V_12 ) ;
return;
}
V_260 = V_61 -> V_225 -> V_261 ;
V_74 -> V_262 = 0 ;
V_74 -> V_262 |= V_263 ;
V_74 -> V_262 |= V_264 ;
V_74 -> V_265 = ( T_1 ) ( V_167 -> V_265 ) ;
switch ( V_260 & V_266 ) {
case V_267 :
V_74 -> V_268 = V_269 ;
F_4 ( L_106 , V_12 ) ;
break;
case V_270 :
V_74 -> V_268 = V_271 ;
F_4 ( L_107 , V_12 ) ;
break;
case V_272 :
V_74 -> V_268 = V_273 ;
F_4 ( L_108 , V_12 ) ;
break;
default:
case V_274 :
V_74 -> V_268 = V_275 ;
F_4 ( L_109 , V_12 ) ;
break;
}
if ( V_260 & V_276 ) {
if ( V_260 & V_277 ) {
V_74 -> V_262 |= V_278 ;
V_74 -> V_279 = V_280 ;
F_4 ( L_110 , V_12 ) ;
} else {
V_74 -> V_262 |= V_278 ;
V_74 -> V_279 = V_281 ;
F_4 ( L_111 , V_12 ) ;
}
} else {
V_74 -> V_279 = V_282 ;
F_4 ( L_112 , V_12 ) ;
}
if ( V_260 & V_283 ) {
V_74 -> V_284 = V_285 ;
F_4 ( L_113 , V_12 ) ;
} else {
V_74 -> V_284 = V_286 ;
F_4 ( L_114 , V_12 ) ;
}
if ( V_260 & V_287 ) {
V_74 -> V_262 |= V_288 ;
V_74 -> V_262 |= V_289 ;
F_4 ( L_115 , V_12 ) ;
} else {
F_4 ( L_116 , V_12 ) ;
V_61 -> V_182 = 0 ;
F_105 ( V_167 ) ;
}
V_74 -> V_290 = F_104 ( V_61 ) ;
V_74 -> V_291 = F_101 ( V_61 ) ;
if ( F_100 ( V_61 ) ) {
V_74 -> V_262 |= V_292 ;
F_4 ( L_117 ,
V_12 , V_74 -> V_290 , V_74 -> V_291 ) ;
} else
F_4 ( L_118 , V_12 ) ;
if ( F_107 ( V_61 ) ) {
V_74 -> V_262 |= V_293 ;
F_4 ( L_119 ,
V_12 , V_74 -> V_290 , V_74 -> V_291 ) ;
} else
F_4 ( L_120 , V_12 ) ;
V_61 -> V_225 -> V_261 &= ~ V_294 ;
V_259 = F_108 ( V_61 ) ;
if ( ! V_259 ) {
V_259 = 9600 ;
} else
F_109 ( V_61 , V_259 , V_259 ) ;
V_167 -> V_59 = V_259 ;
V_74 -> V_295 = ( T_2 ) ( ( 461550L + V_259 / 2 ) / V_259 ) ;
F_4 ( L_121 , V_12 , V_259 ,
V_74 -> V_295 ) ;
F_4 ( L_122 , ( int ) ( 461550L / V_74 -> V_295 ) ) ;
F_4 ( L_123 , V_74 -> V_262 ) ;
F_4 ( L_124 , V_74 -> V_268 ) ;
F_4 ( L_125 , V_74 -> V_279 ) ;
F_4 ( L_126 , V_74 -> V_284 ) ;
F_4 ( L_127 , V_74 -> V_290 ) ;
F_4 ( L_128 , V_74 -> V_291 ) ;
F_4 ( L_129 , V_74 -> V_265 ) ;
F_110 ( & V_74 -> V_262 ) ;
F_110 ( & V_74 -> V_295 ) ;
V_8 = F_7 ( V_167 -> V_18 -> V_22 -> V_2 , V_296 ,
( T_1 ) ( V_25 + V_20 ) ,
0 , ( T_1 * ) V_74 , sizeof( * V_74 ) ) ;
if ( V_8 )
F_4 ( L_130 ,
V_12 , V_8 ) ;
F_17 ( V_74 ) ;
}
static void F_84 ( struct V_60 * V_61 ,
struct V_17 * V_18 , struct V_256 * V_257 )
{
struct V_46 * V_167 = F_73 ( V_18 ) ;
unsigned int V_260 ;
V_260 = V_61 -> V_225 -> V_261 ;
F_4 ( L_131 , V_12 ,
V_61 -> V_225 -> V_261 , V_61 -> V_225 -> V_297 ) ;
F_4 ( L_132 , V_12 ,
V_257 -> V_261 , V_257 -> V_297 ) ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
if ( V_167 == NULL )
return;
F_106 ( V_61 , V_167 , V_257 ) ;
}
static int F_111 ( struct V_60 * V_61 ,
unsigned int V_298 , unsigned int V_299 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
unsigned int V_159 ;
unsigned long V_63 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
V_159 = V_167 -> V_234 ;
if ( V_298 & V_300 )
V_159 |= V_163 ;
if ( V_298 & V_301 )
V_159 |= V_161 ;
if ( V_298 & V_302 )
V_159 |= V_165 ;
if ( V_299 & V_300 )
V_159 &= ~ V_163 ;
if ( V_299 & V_301 )
V_159 &= ~ V_161 ;
if ( V_299 & V_302 )
V_159 &= ~ V_165 ;
V_167 -> V_234 = V_159 ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
F_61 ( V_167 , V_159 ) ;
return 0 ;
}
static int F_112 ( struct V_60 * V_61 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
unsigned int V_249 = 0 ;
unsigned int V_168 ;
unsigned int V_159 ;
unsigned long V_63 ;
F_4 ( L_81 , V_12 , V_18 -> V_21 ) ;
F_22 ( & V_167 -> V_66 , V_63 ) ;
V_168 = V_167 -> V_180 ;
V_159 = V_167 -> V_234 ;
V_249 = ( ( V_159 & V_161 ) ? V_301 : 0 )
| ( ( V_159 & V_163 ) ? V_300 : 0 )
| ( ( V_168 & V_181 ) ? V_303 : 0 )
| ( ( V_168 & V_304 ) ? V_305 : 0 )
| ( ( V_168 & V_306 ) ? V_307 : 0 )
| ( ( V_168 & V_308 ) ? V_309 : 0 ) ;
F_4 ( L_133 , V_12 , V_249 ) ;
F_29 ( & V_167 -> V_66 , V_63 ) ;
return V_249 ;
}
static int F_113 ( struct V_60 * V_61 ,
struct V_310 * V_170 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
struct V_169 * V_311 = & V_167 -> V_170 ;
V_170 -> V_175 = V_311 -> V_175 ;
V_170 -> V_176 = V_311 -> V_176 ;
V_170 -> V_178 = V_311 -> V_178 ;
V_170 -> V_177 = V_311 -> V_177 ;
V_170 -> V_251 = V_311 -> V_251 ;
V_170 -> V_212 = V_311 -> V_212 ;
V_170 -> V_193 = V_311 -> V_193 ;
V_170 -> V_192 = V_311 -> V_192 ;
V_170 -> V_191 = V_311 -> V_191 ;
V_170 -> V_190 = V_311 -> V_190 ;
V_170 -> V_312 = V_311 -> V_312 ;
return 0 ;
}
static int F_114 ( struct V_46 * V_167 ,
struct V_313 T_9 * V_314 )
{
struct V_313 V_315 ;
if ( ! V_314 )
return - V_316 ;
memset ( & V_315 , 0 , sizeof( V_315 ) ) ;
V_315 . type = V_317 ;
V_315 . line = V_167 -> V_18 -> V_22 -> V_23 ;
V_315 . V_18 = V_167 -> V_18 -> V_21 ;
V_315 . V_318 = 0 ;
V_315 . V_63 = V_319 | V_320 ;
V_315 . V_321 = V_167 -> V_18 -> V_250 ;
V_315 . V_322 = 9600 ;
V_315 . V_323 = 5 * V_64 ;
V_315 . V_245 = V_245 ;
if ( F_115 ( V_314 , & V_315 , sizeof( * V_314 ) ) )
return - V_316 ;
return 0 ;
}
static int F_116 ( struct V_60 * V_61 ,
unsigned int V_324 , unsigned long V_325 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
struct V_169 V_326 ;
struct V_169 V_327 ;
F_4 ( L_134 , V_12 , V_18 -> V_21 , V_324 ) ;
switch ( V_324 ) {
case V_328 :
F_4 ( L_135 , V_12 , V_18 -> V_21 ) ;
return F_114 ( V_167 ,
(struct V_313 T_9 * ) V_325 ) ;
case V_329 :
F_4 ( L_136 , V_12 , V_18 -> V_21 ) ;
V_327 = V_167 -> V_170 ;
while ( 1 ) {
F_117 ( & V_167 -> V_179 ) ;
if ( F_27 ( V_67 ) )
return - V_236 ;
V_326 = V_167 -> V_170 ;
if ( V_326 . V_178 == V_327 . V_178 && V_326 . V_176 == V_327 . V_176 &&
V_326 . V_177 == V_327 . V_177 && V_326 . V_175 == V_327 . V_175 )
return - V_330 ;
if ( ( ( V_325 & V_331 ) && ( V_326 . V_178 != V_327 . V_178 ) ) ||
( ( V_325 & V_309 ) && ( V_326 . V_176 != V_327 . V_176 ) ) ||
( ( V_325 & V_332 ) && ( V_326 . V_177 != V_327 . V_177 ) ) ||
( ( V_325 & V_303 ) && ( V_326 . V_175 != V_327 . V_175 ) ) ) {
return 0 ;
}
V_327 = V_326 ;
}
break;
}
return - V_333 ;
}
static void F_118 ( struct V_60 * V_61 , int V_334 )
{
struct V_17 * V_18 = V_61 -> V_248 ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
int V_8 ;
int V_335 = 0 ;
F_4 ( L_137 , V_12 , V_334 ) ;
F_20 ( V_167 , 0 , 0 ) ;
if ( V_334 == - 1 )
V_335 = 1 ;
V_8 = F_60 ( V_167 , V_336 , V_335 ) ;
if ( V_8 )
F_4 ( L_138 ,
V_12 , V_8 ) ;
}
static int F_119 ( struct V_128 * V_22 )
{
struct V_36 * V_195 ;
struct V_46 * V_167 ;
struct V_1 * V_2 ;
int V_8 ;
int V_37 ;
V_2 = V_22 -> V_2 ;
V_195 = F_120 ( sizeof( struct V_36 ) , V_41 ) ;
if ( V_195 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 , V_12 ) ;
return - V_42 ;
}
F_121 ( & V_195 -> V_235 ) ;
V_195 -> V_22 = V_22 ;
F_122 ( V_22 , V_195 ) ;
V_8 = F_57 ( V_195 ) ;
if ( V_8 ) {
F_17 ( V_195 ) ;
return V_8 ;
}
for ( V_37 = 0 ; V_37 < V_22 -> V_337 ; ++ V_37 ) {
V_167 = F_120 ( sizeof( struct V_46 ) , V_41 ) ;
if ( V_167 == NULL ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 ,
V_12 ) ;
goto V_338;
}
F_123 ( & V_167 -> V_66 ) ;
if ( F_124 ( & V_167 -> V_70 , V_339 ,
V_41 ) ) {
F_16 ( & V_22 -> V_2 -> V_2 , L_139 ,
V_12 ) ;
F_17 ( V_167 ) ;
goto V_338;
}
V_167 -> V_18 = V_22 -> V_18 [ V_37 ] ;
V_167 -> V_195 = V_195 ;
F_125 ( V_22 -> V_18 [ V_37 ] , V_167 ) ;
V_167 -> V_265 = V_340 ;
}
return 0 ;
V_338:
for ( -- V_37 ; V_37 >= 0 ; -- V_37 ) {
V_167 = F_73 ( V_22 -> V_18 [ V_37 ] ) ;
F_126 ( & V_167 -> V_70 ) ;
F_17 ( V_167 ) ;
F_125 ( V_22 -> V_18 [ V_37 ] , NULL ) ;
}
F_17 ( V_195 ) ;
F_122 ( V_22 , NULL ) ;
return - V_42 ;
}
static void F_127 ( struct V_128 * V_22 )
{
int V_37 ;
struct V_46 * V_167 ;
F_4 ( L_63 , V_12 ) ;
for ( V_37 = 0 ; V_37 < V_22 -> V_337 ; ++ V_37 ) {
V_167 = F_73 ( V_22 -> V_18 [ V_37 ] ) ;
F_128 ( V_167 -> V_18 ) ;
}
}
static void F_129 ( struct V_128 * V_22 )
{
int V_37 ;
struct V_46 * V_167 ;
F_4 ( L_63 , V_12 ) ;
for ( V_37 = 0 ; V_37 < V_22 -> V_337 ; ++ V_37 ) {
V_167 = F_73 ( V_22 -> V_18 [ V_37 ] ) ;
F_126 ( & V_167 -> V_70 ) ;
F_17 ( V_167 ) ;
}
F_17 ( F_90 ( V_22 ) ) ;
}
static T_10 F_130 ( struct V_91 * V_2 ,
struct V_341 * V_342 , char * V_343 )
{
struct V_17 * V_18 = F_131 ( V_2 ) ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
return sprintf ( V_343 , L_66 , V_167 -> V_265 ) ;
}
static T_10 F_132 ( struct V_91 * V_2 ,
struct V_341 * V_342 , const char * V_344 , T_11 V_247 )
{
struct V_17 * V_18 = F_131 ( V_2 ) ;
struct V_46 * V_167 = F_73 ( V_18 ) ;
unsigned int V_345 = F_133 ( V_344 , NULL , 0 ) ;
F_4 ( L_140 , V_12 , V_345 ) ;
if ( V_345 < 256 )
V_167 -> V_265 = V_345 ;
else
F_16 ( V_2 , L_141 , V_12 , V_345 ) ;
return V_247 ;
}
static int F_134 ( struct V_17 * V_18 )
{
return F_135 ( & V_18 -> V_2 , & V_346 ) ;
}
static int F_128 ( struct V_17 * V_18 )
{
F_136 ( & V_18 -> V_2 , & V_346 ) ;
return 0 ;
}
static int T_12 F_137 ( void )
{
int V_200 ;
V_200 = F_138 ( & V_347 ) ;
if ( V_200 )
goto V_348;
V_200 = F_138 ( & V_349 ) ;
if ( V_200 )
goto V_350;
V_200 = F_139 ( & V_351 ) ;
if ( V_200 )
goto V_352;
F_46 (KERN_INFO KBUILD_MODNAME L_142 DRIVER_VERSION L_143
DRIVER_DESC L_144 ) ;
return 0 ;
V_352:
F_140 ( & V_349 ) ;
V_350:
F_140 ( & V_347 ) ;
V_348:
return V_200 ;
}
static void T_13 F_141 ( void )
{
F_142 ( & V_351 ) ;
F_140 ( & V_347 ) ;
F_140 ( & V_349 ) ;
}
