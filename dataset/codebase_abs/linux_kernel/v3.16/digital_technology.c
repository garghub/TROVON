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
* F_19 ( V_4 , 1 ) = V_24 ;
* F_19 ( V_4 , 1 ) = V_25 ;
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
if ( ! V_15 -> V_7 ) {
V_19 = - V_8 ;
goto exit;
}
V_26 = V_15 -> V_9 [ 0 ] ;
if ( ! F_26 ( V_26 ) ) {
V_19 = F_27 ( V_2 , V_17 ) ;
if ( V_19 )
goto exit;
goto V_28;
}
V_17 -> V_26 = V_26 ;
if ( F_28 ( V_26 ) ) {
V_27 = V_29 ;
} else if ( F_29 ( V_26 ) ) {
V_19 = F_17 ( V_2 , V_17 ) ;
if ( V_19 )
goto exit;
goto V_28;
} else if ( F_30 ( V_26 ) ) {
V_27 = V_30 ;
} else {
V_19 = - V_31 ;
goto exit;
}
V_19 = F_13 ( V_2 , V_17 , V_27 ) ;
exit:
F_15 ( V_17 ) ;
V_28:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 ;
struct V_34 * V_35 ;
T_1 V_36 ;
int V_19 ;
V_4 = F_18 ( V_2 , sizeof( struct V_34 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , sizeof( struct V_34 ) ) ;
V_35 = (struct V_34 * ) V_4 -> V_9 ;
if ( V_17 -> V_37 <= 4 )
V_36 = V_38 ;
else if ( V_17 -> V_37 < 10 )
V_36 = V_39 ;
else
V_36 = V_40 ;
V_35 -> V_36 = V_36 ;
V_35 -> V_41 = 0x70 ;
memcpy ( V_35 -> V_42 , V_33 -> V_42 , 4 ) ;
V_35 -> V_43 = V_33 -> V_43 ;
if ( F_23 ( V_2 ) ) {
V_19 = F_32 ( V_2 , V_44 ,
V_45 ) ;
if ( V_19 )
goto exit;
} else {
F_33 ( V_4 ) ;
}
V_19 = F_20 ( V_2 , V_4 , 30 , F_22 ,
V_17 ) ;
exit:
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_34 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
struct V_32 * V_33 ;
int V_19 ;
T_1 V_46 , V_47 ;
T_1 V_48 , V_43 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < V_49 ) {
F_25 ( L_4 ) ;
V_19 = - V_50 ;
goto exit;
}
V_33 = (struct V_32 * ) V_15 -> V_9 ;
for ( V_48 = 0 , V_43 = 0 ; V_48 < 4 ; V_48 ++ )
V_43 ^= V_33 -> V_42 [ V_48 ] ;
if ( V_43 != V_33 -> V_43 ) {
F_25 ( L_5 ) ;
V_19 = - V_50 ;
goto exit;
}
if ( V_33 -> V_42 [ 0 ] == V_51 ) {
V_46 = 1 ;
V_47 = 3 ;
} else {
V_46 = 0 ;
V_47 = 4 ;
}
memcpy ( V_17 -> V_42 + V_17 -> V_37 , V_33 -> V_42 + V_46 ,
V_47 ) ;
V_17 -> V_37 += V_47 ;
V_19 = F_31 ( V_2 , V_17 , V_33 ) ;
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
T_1 V_36 ;
V_19 = F_32 ( V_2 , V_44 ,
V_52 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , 2 ) ;
if ( ! V_4 )
return - V_23 ;
if ( V_17 -> V_37 == 0 )
V_36 = V_38 ;
else if ( V_17 -> V_37 == 3 )
V_36 = V_39 ;
else
V_36 = V_40 ;
* F_19 ( V_4 , sizeof( T_1 ) ) = V_36 ;
* F_19 ( V_4 , sizeof( T_1 ) ) = V_53 ;
return F_20 ( V_2 , V_4 , 30 , F_34 ,
V_17 ) ;
}
static void F_35 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = NULL ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < sizeof( V_54 ) ) {
V_19 = - V_8 ;
goto exit;
}
V_17 = F_36 ( sizeof( struct V_16 ) , V_55 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto exit;
}
V_17 -> V_56 = F_37 ( * ( V_57 * ) V_15 -> V_9 ) ;
if ( ! F_38 ( V_17 -> V_56 ) ) {
F_25 ( L_6 ) ;
V_19 = - V_50 ;
goto exit;
}
if ( F_39 ( V_17 -> V_56 ) )
V_19 = F_13 ( V_2 , V_17 , V_58 ) ;
else
V_19 = F_27 ( V_2 , V_17 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 ) {
F_15 ( V_17 ) ;
F_16 ( V_2 ) ;
}
}
int F_40 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_32 ( V_2 , V_60 ,
V_61 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( V_2 , V_44 ,
V_62 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_23 ;
* F_19 ( V_4 , sizeof( T_1 ) ) = V_63 ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_35 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
int F_41 ( struct V_3 * V_15 )
{
if ( V_15 -> V_7 == V_64 + V_65 ) {
if ( F_24 ( V_15 ) ) {
F_25 ( L_7 ) ;
return - V_8 ;
}
return 0 ;
}
if ( V_15 -> V_7 == 1 && V_15 -> V_9 [ 0 ] == V_66 ) {
V_15 -> V_9 [ 0 ] = 0 ;
return 0 ;
}
return - V_8 ;
}
static void F_42 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = V_14 ;
struct V_67 * V_68 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < sizeof( * V_68 ) ) {
F_25 ( L_8 ) ;
V_19 = - V_8 ;
goto exit;
}
V_68 = (struct V_67 * ) V_15 -> V_9 ;
if ( V_68 -> V_69 & 0x0f ) {
F_25 ( L_9 ) ;
V_19 = - V_8 ;
goto exit;
}
V_19 = F_13 ( V_2 , V_17 , V_70 ) ;
exit:
F_14 ( V_15 ) ;
F_15 ( V_17 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 ;
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_74 ) ) ;
if ( ! V_4 )
return - V_23 ;
V_74 = (struct V_73 * ) F_19 ( V_4 ,
sizeof( * V_74 ) ) ;
V_74 -> V_75 = V_76 ;
memcpy ( V_74 -> V_77 , V_72 -> V_77 ,
sizeof( V_74 -> V_77 ) ) ;
V_74 -> V_78 = V_79 |
V_80 ;
V_74 -> V_81 = V_82 |
V_83 |
V_84 ;
V_74 -> V_85 = V_72 -> V_86 [ 1 ] & 0x07 ;
V_74 -> V_87 = F_44 ( 0 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_42 ,
V_17 ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_45 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_16 * V_17 = NULL ;
struct V_71 * V_72 ;
T_1 V_88 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 != sizeof( * V_72 ) ) {
F_25 ( L_10 ) ;
V_19 = - V_8 ;
goto exit;
}
V_72 = (struct V_71 * ) V_15 -> V_9 ;
if ( V_72 -> V_75 != V_89 ) {
F_25 ( L_11 ) ;
V_19 = - V_8 ;
goto exit;
}
if ( ! ( V_72 -> V_86 [ 1 ] & F_46 ( 0 ) ) ) {
F_25 ( L_12 ) ;
V_19 = - V_8 ;
goto exit;
}
if ( V_72 -> V_86 [ 1 ] & F_46 ( 3 ) ) {
F_25 ( L_13 ) ;
V_19 = - V_8 ;
goto exit;
}
V_88 = F_47 ( V_72 -> V_86 [ 1 ] ) ;
if ( V_88 >= 8 )
V_2 -> V_11 = V_20 ;
else
V_2 -> V_11 = V_21 [ V_88 ] ;
V_17 = F_36 ( sizeof( struct V_16 ) , V_55 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto exit;
}
V_19 = F_43 ( V_2 , V_17 , V_72 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 ) {
F_15 ( V_17 ) ;
F_16 ( V_2 ) ;
}
}
int F_48 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_90 * V_91 ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_32 ( V_2 , V_60 ,
V_92 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( V_2 , V_44 ,
V_93 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_91 ) ) ;
if ( ! V_4 )
return - V_23 ;
V_91 = (struct V_90 * ) F_19 ( V_4 ,
sizeof( * V_91 ) ) ;
V_91 -> V_75 = V_94 ;
V_91 -> V_95 = 0x00 ;
V_91 -> V_96 = F_49 ( 0 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_45 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_50 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
int V_19 ;
T_1 V_97 ;
struct V_16 V_17 ;
struct V_98 * V_99 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( V_15 -> V_7 < V_100 ) {
V_19 = - V_8 ;
goto exit;
}
if ( ! F_23 ( V_2 ) ) {
V_19 = F_51 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_14 ) ;
goto exit;
}
}
F_5 ( V_15 , 1 ) ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_99 = (struct V_98 * ) V_15 -> V_9 ;
memcpy ( V_17 . V_99 , V_99 , V_15 -> V_7 ) ;
V_17 . V_101 = V_15 -> V_7 ;
memcpy ( V_17 . V_102 , V_99 -> V_102 , V_103 ) ;
V_17 . V_104 = V_103 ;
if ( V_17 . V_102 [ 0 ] == V_105 &&
V_17 . V_102 [ 1 ] == V_106 )
V_97 = V_30 ;
else
V_97 = V_107 ;
V_19 = F_13 ( V_2 , & V_17 , V_97 ) ;
exit:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_108 * V_109 ;
struct V_3 * V_4 ;
int V_19 ;
T_1 V_47 ;
V_19 = F_32 ( V_2 , V_60 , V_59 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( V_2 , V_44 ,
V_110 ) ;
if ( V_19 )
return V_19 ;
V_47 = sizeof( struct V_108 ) ;
V_4 = F_18 ( V_2 , V_47 ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , V_47 ) ;
V_109 = (struct V_108 * ) V_4 -> V_9 ;
V_109 -> V_75 = V_111 ;
V_109 -> V_112 = 0xFF ;
V_109 -> V_113 = 0xFF ;
V_109 -> V_19 = 0 ;
V_109 -> V_114 = 0 ;
* F_7 ( V_4 , 1 ) = V_47 + 1 ;
if ( ! F_23 ( V_2 ) )
F_53 ( V_4 ) ;
V_19 = F_20 ( V_2 , V_4 , 30 , F_50 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_54 ( struct V_1 * V_2 ,
void * V_14 , struct V_3 * V_15 )
{
struct V_115 * V_116 ;
struct V_16 * V_17 = NULL ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto V_117;
}
if ( V_15 -> V_7 != sizeof( * V_116 ) ) {
V_19 = - V_8 ;
goto V_117;
}
V_116 = (struct V_115 * ) V_15 -> V_9 ;
if ( ! F_55 ( V_116 -> V_118 ) ) {
F_25 ( L_15 ) ;
V_19 = - V_50 ;
goto V_117;
}
V_17 = F_36 ( sizeof( * V_17 ) , V_55 ) ;
if ( ! V_17 ) {
V_19 = - V_23 ;
goto V_117;
}
V_17 -> V_119 = 1 ;
V_17 -> V_120 = V_116 -> V_121 ;
memcpy ( V_17 -> V_122 , & V_116 -> V_123 , sizeof( V_17 -> V_122 ) ) ;
V_19 = F_13 ( V_2 , V_17 , V_124 ) ;
F_15 ( V_17 ) ;
V_117:
F_14 ( V_15 ) ;
if ( V_19 )
F_16 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_125 * V_126 ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_32 ( V_2 , V_60 ,
V_127 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( V_2 , V_44 ,
V_128 ) ;
if ( V_19 )
return V_19 ;
V_4 = F_18 ( V_2 , sizeof( * V_126 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , sizeof( * V_126 ) - sizeof( V_126 -> V_129 ) ) ;
V_126 = (struct V_125 * ) V_4 -> V_9 ;
V_126 -> V_118 = V_130 |
V_131 |
V_132 ;
V_126 -> V_75 = V_133 ;
V_126 -> V_134 = 0 ;
V_19 = F_20 ( V_2 , V_4 , 30 ,
F_54 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_18 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_23 ;
* F_19 ( V_4 , 1 ) = V_135 ;
if ( ! F_58 ( V_2 ) )
F_33 ( V_4 ) ;
V_19 = F_59 ( V_2 , V_4 , 300 , V_136 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_60 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( ! F_58 ( V_2 ) ) {
V_19 = F_24 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_3 ) ;
goto exit;
}
}
V_19 = F_57 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_32 * V_33 ;
int V_19 , V_48 ;
V_4 = F_18 ( V_2 , sizeof( struct V_32 ) ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , sizeof( struct V_32 ) ) ;
V_33 = (struct V_32 * ) V_4 -> V_9 ;
V_33 -> V_42 [ 0 ] = 0x08 ;
F_62 ( V_33 -> V_42 + 1 , 3 ) ;
V_33 -> V_43 = 0 ;
for ( V_48 = 0 ; V_48 < 4 ; V_48 ++ )
V_33 -> V_43 ^= V_33 -> V_42 [ V_48 ] ;
V_19 = F_59 ( V_2 , V_4 , 300 , F_60 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
static void F_63 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
T_1 * V_137 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
V_137 = V_15 -> V_9 ;
if ( V_15 -> V_7 < 2 || V_137 [ 0 ] != V_38 ||
V_137 [ 1 ] != V_53 ) {
V_19 = - V_50 ;
goto exit;
}
V_19 = F_61 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 * V_56 ;
int V_19 ;
V_4 = F_18 ( V_2 , 2 ) ;
if ( ! V_4 )
return - V_23 ;
V_56 = F_19 ( V_4 , 2 ) ;
V_56 [ 0 ] = ( V_138 >> 8 ) & 0xFF ;
V_56 [ 1 ] = V_138 & 0xFF ;
V_19 = F_59 ( V_2 , V_4 , 300 , F_63 ,
NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
void F_65 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
T_1 V_139 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
V_139 = V_15 -> V_9 [ 0 ] ;
if ( ! V_15 -> V_7 || ( V_139 != V_63 &&
V_139 != V_140 ) ) {
V_19 = - V_50 ;
goto exit;
}
V_19 = F_64 ( V_2 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
void * V_14 , struct V_3 * V_15 )
{
if ( ! F_10 ( V_15 ) && ( V_15 -> V_7 >= 2 ) &&
( V_15 -> V_9 [ 1 ] == V_111 ) )
F_67 ( V_2 , V_14 , V_15 ) ;
else
V_136 ( V_2 , V_14 , V_15 ) ;
return;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_108 * V_109 )
{
struct V_3 * V_4 ;
T_1 V_47 ;
int V_19 ;
struct V_98 * V_99 ;
V_47 = sizeof( struct V_98 ) ;
if ( V_109 -> V_19 == V_141 )
V_47 -= sizeof( V_99 -> V_142 ) ;
V_4 = F_18 ( V_2 , V_47 ) ;
if ( ! V_4 )
return - V_23 ;
F_19 ( V_4 , V_47 ) ;
V_99 = (struct V_98 * ) V_4 -> V_9 ;
memset ( V_99 , 0 , V_47 ) ;
V_99 -> V_75 = V_143 ;
V_99 -> V_102 [ 0 ] = V_105 ;
V_99 -> V_102 [ 1 ] = V_106 ;
F_62 ( & V_99 -> V_102 [ 2 ] , 6 ) ;
switch ( V_109 -> V_19 ) {
case V_144 :
V_99 -> V_142 [ 0 ] = V_109 -> V_112 ;
V_99 -> V_142 [ 1 ] = V_109 -> V_113 ;
break;
case V_145 :
V_99 -> V_142 [ 0 ] = V_146 ;
V_99 -> V_142 [ 1 ] = V_147 ;
break;
}
* F_7 ( V_4 , sizeof( T_1 ) ) = V_47 + 1 ;
if ( ! F_58 ( V_2 ) )
F_53 ( V_4 ) ;
V_19 = F_59 ( V_2 , V_4 , 300 ,
F_66 , NULL ) ;
if ( V_19 )
F_21 ( V_4 ) ;
return V_19 ;
}
void F_67 ( struct V_1 * V_2 , void * V_14 ,
struct V_3 * V_15 )
{
struct V_108 * V_109 ;
int V_19 ;
if ( F_10 ( V_15 ) ) {
V_19 = F_11 ( V_15 ) ;
V_15 = NULL ;
goto exit;
}
if ( ! F_58 ( V_2 ) ) {
V_19 = F_51 ( V_15 ) ;
if ( V_19 ) {
F_25 ( L_14 ) ;
goto exit;
}
}
if ( V_15 -> V_7 != sizeof( struct V_108 ) + 1 ) {
V_19 = - V_50 ;
goto exit;
}
F_5 ( V_15 , 1 ) ;
V_109 = (struct V_108 * ) V_15 -> V_9 ;
if ( V_109 -> V_75 != V_111 ) {
V_19 = - V_50 ;
goto exit;
}
V_19 = F_68 ( V_2 , V_109 ) ;
exit:
if ( V_19 )
F_16 ( V_2 ) ;
F_14 ( V_15 ) ;
}
int F_69 ( struct V_1 * V_2 , T_1 V_59 )
{
int V_19 ;
V_19 = F_70 ( V_2 , V_60 , V_59 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_70 ( V_2 , V_44 ,
V_148 ) ;
if ( V_19 )
return V_19 ;
return F_71 ( V_2 , 300 , F_65 , NULL ) ;
}
int F_72 ( struct V_1 * V_2 , T_1 V_59 )
{
int V_19 ;
T_1 * V_102 ;
V_19 = F_70 ( V_2 , V_60 , V_59 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_70 ( V_2 , V_44 ,
V_149 ) ;
if ( V_19 )
return V_19 ;
V_102 = F_36 ( V_103 , V_55 ) ;
if ( ! V_102 )
return - V_23 ;
V_102 [ 0 ] = V_105 ;
V_102 [ 1 ] = V_106 ;
F_62 ( V_102 + 2 , V_103 - 2 ) ;
return F_71 ( V_2 , 300 , F_67 , V_102 ) ;
}
