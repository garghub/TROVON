int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
T_1 V_6 ;
if ( V_4 -> V_7 < 1 )
return - V_8 ;
V_5 = * V_4 -> V_9 ;
V_6 = F_2 ( V_5 ) ;
if ( V_6 != V_10 ) {
F_3 ( L_1 ) ;
return - V_8 ;
}
if ( F_4 ( V_5 ) ) {
F_3 ( L_2 ) ;
return - V_8 ;
}
F_5 ( V_4 , 1 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_7 + 3 > V_2 -> V_11 )
return - V_8 ;
F_7 ( V_4 , 1 ) ;
* V_4 -> V_9 = V_12 | V_2 -> V_13 ;
V_2 -> V_13 =
F_8 ( V_2 -> V_13 + 1 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
T_1 V_18 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < 2 ) {
V_19 = - V_8 ;
goto exit;
}
V_18 = F_12 ( V_15 -> V_9 [ 1 ] ) ;
if ( V_18 >= 8 )
V_2 -> V_11 = V_20 ;
else
V_2 -> V_11 = V_21 [ V_18 ] ;
V_2 -> V_13 = 0 ;
V_19 = F_13 ( V_2 , V_17 , V_22 ) ;
exit:
F_14 ( V_15 ) ;
F_15 ( V_17 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_19 ;
struct V_3 * V_4 ;
V_4 = F_18 ( V_2 , 2 ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , V_24 ) ;
F_19 ( V_4 , V_25 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_9 ,
V_17 ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_22 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
int V_19 ;
T_1 V_26 ;
T_1 V_27 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( ! F_23 ( V_2 ) ) {
V_19 = F_24 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_3 ) ;
goto exit;
}
}
if ( V_15 -> V_7 != V_28 ) {
V_19 = - V_8 ;
goto exit;
}
V_26 = V_15 -> V_9 [ 0 ] ;
if ( ! F_26 ( V_26 ) ) {
V_19 = F_27 ( V_2 , V_17 ) ;
if ( V_19 )
goto exit;
goto V_29;
}
V_17 -> V_26 = V_26 ;
if ( F_28 ( V_26 ) ) {
V_27 = V_30 ;
} else if ( F_29 ( V_26 ) ) {
V_27 = V_31 ;
} else if ( F_30 ( V_26 ) ) {
V_19 = F_17 ( V_2 , V_17 ) ;
if ( V_19 )
goto exit;
goto V_29;
} else {
V_19 = - V_32 ;
goto exit;
}
V_19 = F_13 ( V_2 , V_17 , V_27 ) ;
exit:
F_15 ( V_17 ) ;
V_29:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_33 * V_34 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
T_1 V_37 ;
int V_19 ;
V_4 = F_18 ( V_2 , sizeof( struct V_35 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_32 ( V_4 , sizeof( struct V_35 ) ) ;
V_36 = (struct V_35 * ) V_4 -> V_9 ;
if ( V_17 -> V_38 <= 4 )
V_37 = V_39 ;
else if ( V_17 -> V_38 < 10 )
V_37 = V_40 ;
else
V_37 = V_41 ;
V_36 -> V_37 = V_37 ;
V_36 -> V_42 = 0x70 ;
memcpy ( V_36 -> V_43 , V_34 -> V_43 , 4 ) ;
V_36 -> V_44 = V_34 -> V_44 ;
if ( F_23 ( V_2 ) ) {
V_19 = F_33 ( V_2 , V_45 ,
V_46 ) ;
if ( V_19 )
goto exit;
} else {
F_34 ( V_4 ) ;
}
V_19 = F_20 ( V_2 , V_4 , 30 , F_22 ,
V_17 ) ;
exit:
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_35 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
struct V_33 * V_34 ;
int V_19 ;
T_1 V_47 , V_48 ;
T_1 V_49 , V_44 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < V_50 ) {
F_25 ( L_4 ) ;
V_19 = - V_51 ;
goto exit;
}
V_34 = (struct V_33 * ) V_15 -> V_9 ;
for ( V_49 = 0 , V_44 = 0 ; V_49 < 4 ; V_49 ++ )
V_44 ^= V_34 -> V_43 [ V_49 ] ;
if ( V_44 != V_34 -> V_44 ) {
F_25 ( L_5 ) ;
V_19 = - V_51 ;
goto exit;
}
if ( V_34 -> V_43 [ 0 ] == V_52 ) {
V_47 = 1 ;
V_48 = 3 ;
} else {
V_47 = 0 ;
V_48 = 4 ;
}
memcpy ( V_17 -> V_43 + V_17 -> V_38 , V_34 -> V_43 + V_47 ,
V_48 ) ;
V_17 -> V_38 += V_48 ;
V_19 = F_31 ( V_2 , V_17 , V_34 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 ) {
F_15 ( V_17 ) ;
F_16 ( V_2 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
int V_19 ;
struct V_3 * V_4 ;
T_1 V_37 ;
V_19 = F_33 ( V_2 , V_45 ,
V_53 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , 2 ) ;
if ( ! V_4 )
return - V_23 ;
if ( V_17 -> V_38 == 0 )
V_37 = V_39 ;
else if ( V_17 -> V_38 == 3 )
V_37 = V_40 ;
else
V_37 = V_41 ;
F_19 ( V_4 , V_37 ) ;
F_19 ( V_4 , V_54 ) ;
return F_20 ( V_2 , V_4 , 30 , F_35 ,
V_17 ) ;
}
static void F_36 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = NULL ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < sizeof( V_55 ) ) {
V_19 = - V_8 ;
goto exit;
}
V_17 = F_37 ( sizeof( struct V_16 ) , V_56 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto exit;
}
V_17 -> V_57 = F_38 ( * ( V_58 * ) V_15 -> V_9 ) ;
if ( ! F_39 ( V_17 -> V_57 ) ) {
F_25 ( L_6 ) ;
V_19 = - V_51 ;
goto exit;
}
if ( F_40 ( V_17 -> V_57 ) )
V_19 = F_13 ( V_2 , V_17 , V_59 ) ;
else
V_19 = F_27 ( V_2 , V_17 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 ) {
F_15 ( V_17 ) ;
F_16 ( V_2 ) ;
}
}
int F_41 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_33 ( V_2 , V_61 ,
V_62 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_33 ( V_2 , V_45 ,
V_63 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , V_64 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_36 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
int F_42 ( struct V_3 * V_15 )
{
if ( V_15 -> V_7 == V_65 + V_66 ) {
if ( F_24 ( V_15 ) ) {
F_25 ( L_7 ) ;
return - V_8 ;
}
return 0 ;
}
if ( V_15 -> V_7 == 1 && V_15 -> V_9 [ 0 ] == V_67 ) {
V_15 -> V_9 [ 0 ] = 0 ;
return 0 ;
}
return - V_8 ;
}
static void F_43 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
struct V_68 * V_69 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < sizeof( * V_69 ) ) {
F_25 ( L_8 ) ;
V_19 = - V_8 ;
goto exit;
}
V_69 = (struct V_68 * ) V_15 -> V_9 ;
if ( V_69 -> V_70 & 0x0f ) {
F_25 ( L_9 ) ;
V_19 = - V_8 ;
goto exit;
}
V_19 = F_13 ( V_2 , V_17 , V_71 ) ;
exit:
F_14 ( V_15 ) ;
F_15 ( V_17 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 ;
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_75 ) ) ;
if ( ! V_4 )
return - V_23 ;
V_75 = F_32 ( V_4 , sizeof( * V_75 ) ) ;
V_75 -> V_76 = V_77 ;
memcpy ( V_75 -> V_78 , V_73 -> V_78 ,
sizeof( V_75 -> V_78 ) ) ;
V_75 -> V_79 = V_80 |
V_81 ;
V_75 -> V_82 = V_83 |
V_84 |
V_85 ;
V_75 -> V_86 = V_73 -> V_87 [ 1 ] & 0x07 ;
V_75 -> V_88 = F_45 ( 0 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_43 ,
V_17 ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_46 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = NULL ;
struct V_72 * V_73 ;
T_1 V_89 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 != sizeof( * V_73 ) ) {
F_25 ( L_10 ) ;
V_19 = - V_8 ;
goto exit;
}
V_73 = (struct V_72 * ) V_15 -> V_9 ;
if ( V_73 -> V_76 != V_90 ) {
F_25 ( L_11 ) ;
V_19 = - V_8 ;
goto exit;
}
if ( ! ( V_73 -> V_87 [ 1 ] & F_47 ( 0 ) ) ) {
F_25 ( L_12 ) ;
V_19 = - V_8 ;
goto exit;
}
if ( V_73 -> V_87 [ 1 ] & F_47 ( 3 ) ) {
F_25 ( L_13 ) ;
V_19 = - V_8 ;
goto exit;
}
V_89 = F_48 ( V_73 -> V_87 [ 1 ] ) ;
if ( V_89 >= 8 )
V_2 -> V_11 = V_20 ;
else
V_2 -> V_11 = V_21 [ V_89 ] ;
V_17 = F_37 ( sizeof( struct V_16 ) , V_56 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto exit;
}
V_19 = F_44 ( V_2 , V_17 , V_73 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 ) {
F_15 ( V_17 ) ;
F_16 ( V_2 ) ;
}
}
int F_49 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_91 * V_92 ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_33 ( V_2 , V_61 ,
V_93 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_33 ( V_2 , V_45 ,
V_94 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_92 ) ) ;
if ( ! V_4 )
return - V_23 ;
V_92 = F_32 ( V_4 , sizeof( * V_92 ) ) ;
V_92 -> V_76 = V_95 ;
V_92 -> V_96 = 0x00 ;
V_92 -> V_97 = F_50 ( 0 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_46 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_51 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
int V_19 ;
T_1 V_98 ;
struct V_16 V_17 ;
struct V_99 * V_100 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < V_101 ) {
V_19 = - V_8 ;
goto exit;
}
if ( ! F_23 ( V_2 ) ) {
V_19 = F_52 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_14 ) ;
goto exit;
}
}
F_5 ( V_15 , 1 ) ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_100 = (struct V_99 * ) V_15 -> V_9 ;
memcpy ( V_17 . V_100 , V_100 , V_15 -> V_7 ) ;
V_17 . V_102 = V_15 -> V_7 ;
memcpy ( V_17 . V_103 , V_100 -> V_103 , V_104 ) ;
V_17 . V_105 = V_104 ;
if ( V_17 . V_103 [ 0 ] == V_106 &&
V_17 . V_103 [ 1 ] == V_107 )
V_98 = V_31 ;
else
V_98 = V_108 ;
V_19 = F_13 ( V_2 , & V_17 , V_98 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
int F_53 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_109 * V_110 ;
struct V_3 * V_4 ;
int V_19 ;
T_1 V_48 ;
V_19 = F_33 ( V_2 , V_61 , V_60 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_33 ( V_2 , V_45 ,
V_111 ) ;
if ( V_19 )
return V_19 ;
V_48 = sizeof( struct V_109 ) ;
V_4 = F_18 ( V_2 , V_48 ) ;
if ( ! V_4 )
return - V_23 ;
F_32 ( V_4 , V_48 ) ;
V_110 = (struct V_109 * ) V_4 -> V_9 ;
V_110 -> V_76 = V_112 ;
V_110 -> V_113 = 0xFF ;
V_110 -> V_114 = 0xFF ;
V_110 -> V_19 = 0 ;
V_110 -> V_115 = 0 ;
* ( T_1 * ) F_7 ( V_4 , 1 ) = V_48 + 1 ;
if ( ! F_23 ( V_2 ) )
F_54 ( V_4 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_51 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_55 ( struct V_1 * V_2 ,
void * V_14 , struct V_3 * V_15 )
{
struct V_116 * V_117 ;
struct V_16 * V_17 = NULL ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto V_118;
}
if ( V_15 -> V_7 != sizeof( * V_117 ) ) {
V_19 = - V_8 ;
goto V_118;
}
V_117 = (struct V_116 * ) V_15 -> V_9 ;
if ( ! F_56 ( V_117 -> V_119 ) ) {
F_25 ( L_15 ) ;
V_19 = - V_51 ;
goto V_118;
}
V_17 = F_37 ( sizeof( * V_17 ) , V_56 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_118;
}
V_17 -> V_120 = 1 ;
V_17 -> V_121 = V_117 -> V_122 ;
memcpy ( V_17 -> V_123 , & V_117 -> V_124 , sizeof( V_17 -> V_123 ) ) ;
V_19 = F_13 ( V_2 , V_17 , V_125 ) ;
F_15 ( V_17 ) ;
V_118:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
int F_57 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_126 * V_127 ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_33 ( V_2 , V_61 ,
V_128 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_33 ( V_2 , V_45 ,
V_129 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_127 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_32 ( V_4 , sizeof( * V_127 ) - sizeof( V_127 -> V_130 ) ) ;
V_127 = (struct V_126 * ) V_4 -> V_9 ;
V_127 -> V_119 = V_131 |
V_132 |
V_133 ;
V_127 -> V_76 = V_134 ;
V_127 -> V_135 = 0 ;
V_19 = F_20 ( V_2 , V_4 , 30 ,
F_55 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_18 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , V_136 ) ;
if ( ! F_59 ( V_2 ) )
F_34 ( V_4 ) ;
V_19 = F_60 ( V_2 , V_45 ,
V_137 ) ;
if ( V_19 ) {
F_21 ( V_4 ) ;
return V_19 ;
}
V_19 = F_61 ( V_2 , V_4 , 300 , V_138 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_62 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( ! F_59 ( V_2 ) ) {
V_19 = F_24 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_3 ) ;
goto exit;
}
}
V_19 = F_58 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_33 * V_34 ;
int V_19 , V_49 ;
V_4 = F_18 ( V_2 , sizeof( struct V_33 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_32 ( V_4 , sizeof( struct V_33 ) ) ;
V_34 = (struct V_33 * ) V_4 -> V_9 ;
V_34 -> V_43 [ 0 ] = 0x08 ;
F_64 ( V_34 -> V_43 + 1 , 3 ) ;
V_34 -> V_44 = 0 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ )
V_34 -> V_44 ^= V_34 -> V_43 [ V_49 ] ;
V_19 = F_60 ( V_2 , V_45 ,
V_46 ) ;
if ( V_19 ) {
F_21 ( V_4 ) ;
return V_19 ;
}
V_19 = F_61 ( V_2 , V_4 , 300 , F_62 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_65 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
T_1 * V_139 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
V_139 = V_15 -> V_9 ;
if ( V_15 -> V_7 < 2 || V_139 [ 0 ] != V_39 ||
V_139 [ 1 ] != V_54 ) {
V_19 = - V_51 ;
goto exit;
}
V_19 = F_63 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_57 ;
int V_19 ;
V_4 = F_18 ( V_2 , 2 ) ;
if ( ! V_4 )
return - V_23 ;
V_57 = F_32 ( V_4 , 2 ) ;
V_57 [ 0 ] = ( V_140 >> 8 ) & 0xFF ;
V_57 [ 1 ] = V_140 & 0xFF ;
V_19 = F_60 ( V_2 , V_45 ,
V_53 ) ;
if ( V_19 ) {
F_21 ( V_4 ) ;
return V_19 ;
}
V_19 = F_61 ( V_2 , V_4 , 300 , F_65 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
void F_67 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
T_1 V_141 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
V_141 = V_15 -> V_9 [ 0 ] ;
if ( ! V_15 -> V_7 || ( V_141 != V_64 &&
V_141 != V_142 ) ) {
V_19 = - V_51 ;
goto exit;
}
V_19 = F_66 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
void * V_14 , struct V_3 * V_15 )
{
if ( ! F_10 ( V_15 ) && ( V_15 -> V_7 >= 2 ) &&
( V_15 -> V_9 [ 1 ] == V_112 ) )
F_69 ( V_2 , V_14 , V_15 ) ;
else
V_138 ( V_2 , V_14 , V_15 ) ;
return;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
struct V_3 * V_4 ;
T_1 V_48 ;
int V_19 ;
struct V_99 * V_100 ;
V_48 = sizeof( struct V_99 ) ;
if ( V_110 -> V_19 == V_143 )
V_48 -= sizeof( V_100 -> V_144 ) ;
V_4 = F_18 ( V_2 , V_48 ) ;
if ( ! V_4 )
return - V_23 ;
F_32 ( V_4 , V_48 ) ;
V_100 = (struct V_99 * ) V_4 -> V_9 ;
memset ( V_100 , 0 , V_48 ) ;
V_100 -> V_76 = V_145 ;
V_100 -> V_103 [ 0 ] = V_106 ;
V_100 -> V_103 [ 1 ] = V_107 ;
F_64 ( & V_100 -> V_103 [ 2 ] , 6 ) ;
switch ( V_110 -> V_19 ) {
case V_146 :
V_100 -> V_144 [ 0 ] = V_110 -> V_113 ;
V_100 -> V_144 [ 1 ] = V_110 -> V_114 ;
break;
case V_147 :
V_100 -> V_144 [ 0 ] = V_148 ;
V_100 -> V_144 [ 1 ] = V_149 ;
break;
}
* ( T_1 * ) F_7 ( V_4 , sizeof( T_1 ) ) = V_48 + 1 ;
if ( ! F_59 ( V_2 ) )
F_54 ( V_4 ) ;
V_19 = F_61 ( V_2 , V_4 , 300 ,
F_68 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
void F_69 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_109 * V_110 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( ! F_59 ( V_2 ) ) {
V_19 = F_52 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_14 ) ;
goto exit;
}
}
if ( V_15 -> V_7 != sizeof( struct V_109 ) + 1 ) {
V_19 = - V_51 ;
goto exit;
}
F_5 ( V_15 , 1 ) ;
V_110 = (struct V_109 * ) V_15 -> V_9 ;
if ( V_110 -> V_76 != V_112 ) {
V_19 = - V_51 ;
goto exit;
}
V_19 = F_70 ( V_2 , V_110 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_60 ( V_2 , V_61 ,
V_62 ) ;
if ( V_19 )
return V_19 ;
return F_60 ( V_2 , V_45 ,
V_150 ) ;
}
int F_72 ( struct V_1 * V_2 , T_1 V_60 )
{
int V_19 ;
V_19 = F_71 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return F_73 ( V_2 , 300 , F_67 , NULL ) ;
}
static int F_74 ( struct V_1 * V_2 , T_1 V_60 )
{
int V_19 ;
V_19 = F_60 ( V_2 , V_61 , V_60 ) ;
if ( V_19 )
return V_19 ;
return F_60 ( V_2 , V_45 ,
V_151 ) ;
}
int F_75 ( struct V_1 * V_2 , T_1 V_60 )
{
int V_19 ;
V_19 = F_74 ( V_2 , V_60 ) ;
if ( V_19 )
return V_19 ;
return F_73 ( V_2 , 300 , F_69 , NULL ) ;
}
void F_76 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
T_1 V_60 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_15 = NULL ;
goto V_29;
}
V_19 = V_2 -> V_152 -> V_153 ( V_2 , & V_60 ) ;
if ( V_19 )
goto V_29;
switch ( V_60 ) {
case V_62 :
V_19 = F_71 ( V_2 ) ;
if ( V_19 )
goto V_29;
F_67 ( V_2 , V_14 , V_15 ) ;
break;
case V_154 :
case V_155 :
V_19 = F_74 ( V_2 , V_60 ) ;
if ( V_19 )
goto V_29;
F_69 ( V_2 , V_14 , V_15 ) ;
break;
default:
goto V_29;
}
return;
V_29:
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
