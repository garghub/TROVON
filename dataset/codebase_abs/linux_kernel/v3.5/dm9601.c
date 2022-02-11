static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
void * V_6 ;
int V_7 = - V_8 ;
F_2 ( V_2 -> V_9 , L_1 , V_3 , V_4 ) ;
V_6 = F_3 ( V_4 , V_10 ) ;
if ( ! V_6 )
goto V_11;
V_7 = F_4 ( V_2 -> V_12 ,
F_5 ( V_2 -> V_12 , 0 ) ,
V_13 ,
V_14 | V_15 | V_16 ,
0 , V_3 , V_6 , V_4 , V_17 ) ;
if ( V_7 == V_4 )
memcpy ( V_5 , V_6 , V_4 ) ;
else if ( V_7 >= 0 )
V_7 = - V_18 ;
F_6 ( V_6 ) ;
V_11:
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_19 )
{
return F_1 ( V_2 , V_3 , 1 , V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
void * V_6 = NULL ;
int V_7 = - V_8 ;
F_2 ( V_2 -> V_9 , L_2 , V_3 , V_4 ) ;
if ( V_5 ) {
V_6 = F_9 ( V_5 , V_4 , V_10 ) ;
if ( ! V_6 )
goto V_11;
}
V_7 = F_4 ( V_2 -> V_12 ,
F_10 ( V_2 -> V_12 , 0 ) ,
V_20 ,
V_21 | V_15 | V_16 ,
0 , V_3 , V_6 , V_4 , V_17 ) ;
F_6 ( V_6 ) ;
if ( V_7 >= 0 && V_7 < V_4 )
V_7 = - V_18 ;
V_11:
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 )
{
F_2 ( V_2 -> V_9 , L_3 ,
V_3 , V_19 ) ;
return F_4 ( V_2 -> V_12 ,
F_10 ( V_2 -> V_12 , 0 ) ,
V_22 ,
V_21 | V_15 | V_16 ,
V_19 , V_3 , NULL , 0 , V_17 ) ;
}
static void F_12 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 ;
int V_27 = V_23 -> V_27 ;
if ( V_27 < 0 )
F_13 ( V_28 L_4 ,
V_27 ) ;
F_6 ( V_25 ) ;
F_14 ( V_23 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 ,
T_2 V_4 , void * V_5 )
{
struct V_24 * V_25 ;
struct V_23 * V_23 ;
int V_27 ;
V_23 = F_16 ( 0 , V_29 ) ;
if ( ! V_23 ) {
F_17 ( V_2 -> V_9 , L_5 ) ;
return;
}
V_25 = F_3 ( sizeof( struct V_24 ) , V_29 ) ;
if ( ! V_25 ) {
F_17 ( V_2 -> V_9 , L_6 ) ;
F_14 ( V_23 ) ;
return;
}
V_25 -> V_30 = V_21 | V_15 | V_16 ;
V_25 -> V_31 = V_4 ? V_20 : V_22 ;
V_25 -> V_32 = F_18 ( V_19 ) ;
V_25 -> V_33 = F_18 ( V_3 ) ;
V_25 -> V_34 = F_18 ( V_4 ) ;
F_19 ( V_23 , V_2 -> V_12 ,
F_10 ( V_2 -> V_12 , 0 ) ,
( void * ) V_25 , V_5 , V_4 ,
F_12 , V_25 ) ;
V_27 = F_20 ( V_23 , V_29 ) ;
if ( V_27 < 0 ) {
F_17 ( V_2 -> V_9 , L_7 ,
V_27 ) ;
F_6 ( V_25 ) ;
F_14 ( V_23 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
F_2 ( V_2 -> V_9 , L_8 , V_3 , V_4 ) ;
F_15 ( V_2 , V_3 , 0 , V_4 , V_5 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_19 )
{
F_2 ( V_2 -> V_9 , L_9 ,
V_3 , V_19 ) ;
F_15 ( V_2 , V_3 , V_19 , 0 , NULL ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_35 , T_1 V_3 , T_3 * V_19 )
{
int V_36 , V_37 ;
F_24 ( & V_2 -> V_38 ) ;
F_11 ( V_2 , V_39 , V_35 ? ( V_3 | 0x40 ) : V_3 ) ;
F_11 ( V_2 , V_40 , V_35 ? 0xc : 0x4 ) ;
for ( V_37 = 0 ; V_37 < V_41 ; V_37 ++ ) {
T_1 V_42 ;
F_25 ( 1 ) ;
V_36 = F_7 ( V_2 , V_40 , & V_42 ) ;
if ( V_36 < 0 )
goto V_11;
if ( ( V_42 & 1 ) == 0 )
break;
}
if ( V_37 == V_41 ) {
F_17 ( V_2 -> V_9 , L_10 , V_35 ? L_11 : L_12 ) ;
V_36 = - V_43 ;
goto V_11;
}
F_11 ( V_2 , V_40 , 0x0 ) ;
V_36 = F_1 ( V_2 , V_44 , 2 , V_19 ) ;
F_2 ( V_2 -> V_9 , L_13 ,
V_35 , V_3 , * V_19 , V_36 ) ;
V_11:
F_26 ( & V_2 -> V_38 ) ;
return V_36 ;
}
static int F_27 ( struct V_1 * V_2 , int V_35 , T_1 V_3 , T_3 V_19 )
{
int V_36 , V_37 ;
F_24 ( & V_2 -> V_38 ) ;
V_36 = F_8 ( V_2 , V_44 , 2 , & V_19 ) ;
if ( V_36 < 0 )
goto V_11;
F_11 ( V_2 , V_39 , V_35 ? ( V_3 | 0x40 ) : V_3 ) ;
F_11 ( V_2 , V_40 , V_35 ? 0x1a : 0x12 ) ;
for ( V_37 = 0 ; V_37 < V_41 ; V_37 ++ ) {
T_1 V_42 ;
F_25 ( 1 ) ;
V_36 = F_7 ( V_2 , V_40 , & V_42 ) ;
if ( V_36 < 0 )
goto V_11;
if ( ( V_42 & 1 ) == 0 )
break;
}
if ( V_37 == V_41 ) {
F_17 ( V_2 -> V_9 , L_14 , V_35 ? L_11 : L_12 ) ;
V_36 = - V_43 ;
goto V_11;
}
F_11 ( V_2 , V_40 , 0x0 ) ;
V_11:
F_26 ( & V_2 -> V_38 ) ;
return V_36 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_45 , void * V_19 )
{
return F_23 ( V_2 , 0 , V_45 , V_19 ) ;
}
static int F_29 ( struct V_46 * V_2 )
{
return V_47 ;
}
static int F_30 ( struct V_46 * V_9 ,
struct V_48 * V_49 , T_1 * V_5 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
T_3 * V_50 = ( T_3 * ) V_5 ;
int V_37 ;
if ( ( V_49 -> V_45 % 2 ) || ( V_49 -> V_51 % 2 ) )
return - V_18 ;
for ( V_37 = 0 ; V_37 < V_49 -> V_51 / 2 ; V_37 ++ ) {
if ( F_28 ( V_2 , V_49 -> V_45 / 2 + V_37 ,
& V_50 [ V_37 ] ) < 0 )
return - V_18 ;
}
return 0 ;
}
static int F_32 ( struct V_46 * V_52 , int V_53 , int V_54 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
T_3 V_55 ;
if ( V_53 ) {
F_2 ( V_2 -> V_9 , L_15 ) ;
return 0 ;
}
F_23 ( V_2 , 1 , V_54 , & V_55 ) ;
F_2 ( V_2 -> V_9 ,
L_16 ,
V_53 , V_54 , F_33 ( V_55 ) ) ;
return F_33 ( V_55 ) ;
}
static void F_34 ( struct V_46 * V_52 , int V_53 , int V_54 ,
int V_56 )
{
struct V_1 * V_2 = F_31 ( V_52 ) ;
T_3 V_55 = F_18 ( V_56 ) ;
if ( V_53 ) {
F_2 ( V_2 -> V_9 , L_15 ) ;
return;
}
F_2 ( V_2 -> V_9 , L_17 ,
V_53 , V_54 , V_56 ) ;
F_27 ( V_2 , 1 , V_54 , V_55 ) ;
}
static void F_35 ( struct V_46 * V_9 ,
struct V_57 * V_58 )
{
F_36 ( V_9 , V_58 ) ;
V_58 -> V_59 = V_47 ;
}
static T_4 F_37 ( struct V_46 * V_9 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
return F_38 ( & V_2 -> V_60 ) ;
}
static int F_39 ( struct V_46 * V_9 , struct V_61 * V_62 , int V_63 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
return F_40 ( & V_2 -> V_60 , F_41 ( V_62 ) , V_63 , NULL ) ;
}
static void F_42 ( struct V_46 * V_9 )
{
struct V_1 * V_2 = F_31 ( V_9 ) ;
T_1 * V_64 = ( T_1 * ) & V_2 -> V_5 ;
T_1 V_65 = 0x31 ;
memset ( V_64 , 0x00 , V_66 ) ;
V_64 [ V_66 - 1 ] |= 0x80 ;
if ( V_9 -> V_67 & V_68 ) {
V_65 |= 0x02 ;
} else if ( V_9 -> V_67 & V_69 ||
F_43 ( V_9 ) > V_70 ) {
V_65 |= 0x04 ;
} else if ( ! F_44 ( V_9 ) ) {
struct V_71 * V_72 ;
F_45 (ha, net) {
T_4 V_73 = F_46 ( V_74 , V_72 -> V_75 ) >> 26 ;
V_64 [ V_73 >> 3 ] |= 1 << ( V_73 & 0x7 ) ;
}
}
F_21 ( V_2 , V_76 , V_66 , V_64 ) ;
F_22 ( V_2 , V_77 , V_65 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_78 , V_74 , V_2 -> V_9 -> V_79 ) ;
}
static int F_48 ( struct V_46 * V_9 , void * V_80 )
{
struct V_81 * V_75 = V_80 ;
struct V_1 * V_2 = F_31 ( V_9 ) ;
if ( ! F_49 ( V_75 -> V_82 ) ) {
F_50 ( & V_9 -> V_2 , L_18 ,
V_75 -> V_82 ) ;
return - V_18 ;
}
memcpy ( V_9 -> V_79 , V_75 -> V_82 , V_9 -> V_83 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_84 * V_85 )
{
int V_36 ;
T_1 V_86 [ V_74 ] ;
V_36 = F_52 ( V_2 , V_85 ) ;
if ( V_36 )
goto V_11;
V_2 -> V_9 -> V_87 = & V_88 ;
V_2 -> V_9 -> V_89 = & V_90 ;
V_2 -> V_9 -> V_91 += V_92 ;
V_2 -> V_93 = V_2 -> V_9 -> V_94 + V_2 -> V_9 -> V_91 ;
V_2 -> V_95 = V_2 -> V_9 -> V_94 + V_96 + V_97 ;
V_2 -> V_60 . V_2 = V_2 -> V_9 ;
V_2 -> V_60 . V_98 = F_32 ;
V_2 -> V_60 . V_99 = F_34 ;
V_2 -> V_60 . V_100 = 0x1f ;
V_2 -> V_60 . V_101 = 0x1f ;
F_11 ( V_2 , V_102 , 1 ) ;
F_25 ( 20 ) ;
if ( F_1 ( V_2 , V_78 , V_74 , V_86 ) < 0 ) {
F_13 ( V_103 L_19 ) ;
V_36 = - V_104 ;
goto V_11;
}
if ( F_49 ( V_86 ) )
memcpy ( V_2 -> V_9 -> V_79 , V_86 , V_74 ) ;
else {
F_13 ( V_105
L_20 ,
V_2 -> V_9 -> V_79 ) ;
F_47 ( V_2 ) ;
}
F_11 ( V_2 , V_106 , 1 ) ;
F_11 ( V_2 , V_107 , 0 ) ;
F_42 ( V_2 -> V_9 ) ;
F_34 ( V_2 -> V_9 , V_2 -> V_60 . V_53 , V_108 , V_109 ) ;
F_34 ( V_2 -> V_9 , V_2 -> V_60 . V_53 , V_110 ,
V_111 | V_112 | V_113 ) ;
F_53 ( & V_2 -> V_60 ) ;
V_11:
return V_36 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_114 * V_115 )
{
T_1 V_27 ;
int V_51 ;
if ( F_55 ( V_115 -> V_51 < V_97 ) ) {
F_50 ( & V_2 -> V_12 -> V_2 , L_21 ) ;
return 0 ;
}
V_27 = V_115 -> V_5 [ 0 ] ;
V_51 = ( V_115 -> V_5 [ 1 ] | ( V_115 -> V_5 [ 2 ] << 8 ) ) - 4 ;
if ( F_55 ( V_27 & 0xbf ) ) {
if ( V_27 & 0x01 ) V_2 -> V_9 -> V_116 . V_117 ++ ;
if ( V_27 & 0x02 ) V_2 -> V_9 -> V_116 . V_118 ++ ;
if ( V_27 & 0x04 ) V_2 -> V_9 -> V_116 . V_119 ++ ;
if ( V_27 & 0x20 ) V_2 -> V_9 -> V_116 . V_120 ++ ;
if ( V_27 & 0x90 ) V_2 -> V_9 -> V_116 . V_121 ++ ;
return 0 ;
}
F_56 ( V_115 , 3 ) ;
F_57 ( V_115 , V_51 ) ;
return 1 ;
}
static struct V_114 * F_58 ( struct V_1 * V_2 , struct V_114 * V_115 ,
T_5 V_67 )
{
int V_51 ;
V_51 = V_115 -> V_51 ;
if ( F_59 ( V_115 ) < V_92 ) {
struct V_114 * V_122 ;
V_122 = F_60 ( V_115 , V_92 , 0 , V_67 ) ;
F_61 ( V_115 ) ;
V_115 = V_122 ;
if ( ! V_115 )
return NULL ;
}
F_62 ( V_115 , V_92 ) ;
if ( ( V_115 -> V_51 % V_2 -> V_123 ) == 0 )
V_51 ++ ;
V_115 -> V_5 [ 0 ] = V_51 ;
V_115 -> V_5 [ 1 ] = V_51 >> 8 ;
return V_115 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_23 * V_23 )
{
int V_124 ;
T_1 * V_6 ;
if ( V_23 -> V_125 < 8 )
return;
V_6 = V_23 -> V_126 ;
V_124 = ! ! ( V_6 [ 0 ] & 0x40 ) ;
if ( F_64 ( V_2 -> V_9 ) != V_124 ) {
if ( V_124 ) {
F_65 ( V_2 -> V_9 ) ;
F_66 ( V_2 , V_127 ) ;
}
else
F_67 ( V_2 -> V_9 ) ;
F_2 ( V_2 -> V_9 , L_22 , V_124 ) ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_128 V_129 = { . V_63 = V_130 } ;
F_69 ( & V_2 -> V_60 , 1 , 1 ) ;
F_70 ( & V_2 -> V_60 , & V_129 ) ;
F_2 ( V_2 -> V_9 , L_23 ,
F_71 ( & V_129 ) , V_129 . V_131 ) ;
return 0 ;
}
