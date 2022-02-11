static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 , V_7 ,
V_8 | V_9 | V_10 ,
0 , V_3 , V_5 , V_4 ) ;
if( V_6 != V_4 && V_6 >= 0 )
V_6 = - V_11 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_12 )
{
return F_1 ( V_2 , V_3 , 1 , V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_5 ( V_2 , V_13 ,
V_14 | V_9 | V_10 ,
0 , V_3 , V_5 , V_4 ) ;
if ( V_6 >= 0 && V_6 < V_4 )
V_6 = - V_11 ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
return F_5 ( V_2 , V_15 ,
V_14 | V_9 | V_10 ,
V_12 , V_3 , NULL , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
F_8 ( V_2 , V_13 ,
V_14 | V_9 | V_10 ,
0 , V_3 , V_5 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
F_8 ( V_2 , V_15 ,
V_14 | V_9 | V_10 ,
V_12 , V_3 , NULL , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_16 , T_1 V_3 , T_3 * V_12 )
{
int V_17 , V_18 ;
F_11 ( & V_2 -> V_19 ) ;
F_6 ( V_2 , V_20 , V_16 ? ( V_3 | 0x40 ) : V_3 ) ;
F_6 ( V_2 , V_21 , V_16 ? 0xc : 0x4 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
T_1 V_23 = 0 ;
F_12 ( 1 ) ;
V_17 = F_3 ( V_2 , V_21 , & V_23 ) ;
if ( V_17 < 0 )
goto V_24;
if ( ( V_23 & 1 ) == 0 )
break;
}
if ( V_18 == V_22 ) {
F_13 ( V_2 -> V_25 , L_1 , V_16 ? L_2 : L_3 ) ;
V_17 = - V_26 ;
goto V_24;
}
F_6 ( V_2 , V_21 , 0x0 ) ;
V_17 = F_1 ( V_2 , V_27 , 2 , V_12 ) ;
F_14 ( V_2 -> V_25 , L_4 ,
V_16 , V_3 , * V_12 , V_17 ) ;
V_24:
F_15 ( & V_2 -> V_19 ) ;
return V_17 ;
}
static int F_16 ( struct V_1 * V_2 , int V_16 , T_1 V_3 , T_3 V_12 )
{
int V_17 , V_18 ;
F_11 ( & V_2 -> V_19 ) ;
V_17 = F_4 ( V_2 , V_27 , 2 , & V_12 ) ;
if ( V_17 < 0 )
goto V_24;
F_6 ( V_2 , V_20 , V_16 ? ( V_3 | 0x40 ) : V_3 ) ;
F_6 ( V_2 , V_21 , V_16 ? 0x1a : 0x12 ) ;
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
T_1 V_23 = 0 ;
F_12 ( 1 ) ;
V_17 = F_3 ( V_2 , V_21 , & V_23 ) ;
if ( V_17 < 0 )
goto V_24;
if ( ( V_23 & 1 ) == 0 )
break;
}
if ( V_18 == V_22 ) {
F_13 ( V_2 -> V_25 , L_5 , V_16 ? L_2 : L_3 ) ;
V_17 = - V_26 ;
goto V_24;
}
F_6 ( V_2 , V_21 , 0x0 ) ;
V_24:
F_15 ( & V_2 -> V_19 ) ;
return V_17 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_28 , void * V_12 )
{
return F_10 ( V_2 , 0 , V_28 , V_12 ) ;
}
static int F_18 ( struct V_29 * V_2 )
{
return V_30 ;
}
static int F_19 ( struct V_29 * V_25 ,
struct V_31 * V_32 , T_1 * V_5 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
T_3 * V_33 = ( T_3 * ) V_5 ;
int V_18 ;
if ( ( V_32 -> V_28 % 2 ) || ( V_32 -> V_34 % 2 ) )
return - V_11 ;
for ( V_18 = 0 ; V_18 < V_32 -> V_34 / 2 ; V_18 ++ ) {
if ( F_17 ( V_2 , V_32 -> V_28 / 2 + V_18 ,
& V_33 [ V_18 ] ) < 0 )
return - V_11 ;
}
return 0 ;
}
static int F_21 ( struct V_29 * V_35 , int V_36 , int V_37 )
{
struct V_1 * V_2 = F_20 ( V_35 ) ;
T_3 V_38 ;
if ( V_36 ) {
F_14 ( V_2 -> V_25 , L_6 ) ;
return 0 ;
}
F_10 ( V_2 , 1 , V_37 , & V_38 ) ;
F_14 ( V_2 -> V_25 ,
L_7 ,
V_36 , V_37 , F_22 ( V_38 ) ) ;
return F_22 ( V_38 ) ;
}
static void F_23 ( struct V_29 * V_35 , int V_36 , int V_37 ,
int V_39 )
{
struct V_1 * V_2 = F_20 ( V_35 ) ;
T_3 V_38 = F_24 ( V_39 ) ;
if ( V_36 ) {
F_14 ( V_2 -> V_25 , L_6 ) ;
return;
}
F_14 ( V_2 -> V_25 , L_8 ,
V_36 , V_37 , V_39 ) ;
F_16 ( V_2 , 1 , V_37 , V_38 ) ;
}
static void F_25 ( struct V_29 * V_25 ,
struct V_40 * V_41 )
{
F_26 ( V_25 , V_41 ) ;
}
static T_4 F_27 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
return F_28 ( & V_2 -> V_42 ) ;
}
static int F_29 ( struct V_29 * V_25 , struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
return F_30 ( & V_2 -> V_42 , F_31 ( V_44 ) , V_45 , NULL ) ;
}
static void F_32 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
T_1 * V_46 = ( T_1 * ) & V_2 -> V_5 ;
T_1 V_47 = 0x31 ;
memset ( V_46 , 0x00 , V_48 ) ;
V_46 [ V_48 - 1 ] |= 0x80 ;
if ( V_25 -> V_49 & V_50 ) {
V_47 |= 0x02 ;
} else if ( V_25 -> V_49 & V_51 ||
F_33 ( V_25 ) > V_52 ) {
V_47 |= 0x08 ;
} else if ( ! F_34 ( V_25 ) ) {
struct V_53 * V_54 ;
F_35 (ha, net) {
T_4 V_55 = F_36 ( V_56 , V_54 -> V_57 ) >> 26 ;
V_46 [ V_55 >> 3 ] |= 1 << ( V_55 & 0x7 ) ;
}
}
F_7 ( V_2 , V_58 , V_48 , V_46 ) ;
F_9 ( V_2 , V_59 , V_47 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_60 , V_56 , V_2 -> V_25 -> V_61 ) ;
}
static int F_38 ( struct V_29 * V_25 , void * V_62 )
{
struct V_63 * V_57 = V_62 ;
struct V_1 * V_2 = F_20 ( V_25 ) ;
if ( ! F_39 ( V_57 -> V_64 ) ) {
F_40 ( & V_25 -> V_2 , L_9 ,
V_57 -> V_64 ) ;
return - V_11 ;
}
memcpy ( V_25 -> V_61 , V_57 -> V_64 , V_25 -> V_65 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
int V_17 ;
T_1 V_68 [ V_56 ] , V_69 ;
V_17 = F_42 ( V_2 , V_67 ) ;
if ( V_17 )
goto V_24;
V_2 -> V_25 -> V_70 = & V_71 ;
V_2 -> V_25 -> V_72 = & V_73 ;
V_2 -> V_25 -> V_74 += V_75 ;
V_2 -> V_76 = V_2 -> V_25 -> V_77 + V_2 -> V_25 -> V_74 ;
V_2 -> V_78 = V_2 -> V_25 -> V_77 + V_79 + V_80 + 1 ;
V_2 -> V_42 . V_2 = V_2 -> V_25 ;
V_2 -> V_42 . V_81 = F_21 ;
V_2 -> V_42 . V_82 = F_23 ;
V_2 -> V_42 . V_83 = 0x1f ;
V_2 -> V_42 . V_84 = 0x1f ;
F_6 ( V_2 , V_85 , 1 ) ;
F_12 ( 20 ) ;
if ( F_1 ( V_2 , V_60 , V_56 , V_68 ) < 0 ) {
F_43 ( V_86 L_10 ) ;
V_17 = - V_87 ;
goto V_24;
}
if ( F_39 ( V_68 ) )
memcpy ( V_2 -> V_25 -> V_61 , V_68 , V_56 ) ;
else {
F_43 ( V_88
L_11 ,
V_2 -> V_25 -> V_61 ) ;
F_37 ( V_2 ) ;
}
if ( F_3 ( V_2 , V_89 , & V_69 ) < 0 ) {
F_13 ( V_2 -> V_25 , L_12 ) ;
V_17 = - V_87 ;
goto V_24;
}
if ( V_69 == V_90 ) {
T_1 V_91 ;
if ( F_3 ( V_2 , V_92 , & V_91 ) < 0 ) {
F_13 ( V_2 -> V_25 , L_13 ) ;
V_17 = - V_87 ;
goto V_24;
}
F_6 ( V_2 , V_92 , V_91 & 0x7f ) ;
}
F_6 ( V_2 , V_93 , 1 ) ;
F_6 ( V_2 , V_94 , 0 ) ;
F_32 ( V_2 -> V_25 ) ;
F_23 ( V_2 -> V_25 , V_2 -> V_42 . V_36 , V_95 , V_96 ) ;
F_23 ( V_2 -> V_25 , V_2 -> V_42 . V_36 , V_97 ,
V_98 | V_99 | V_100 ) ;
F_44 ( & V_2 -> V_42 ) ;
V_24:
return V_17 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
T_1 V_103 ;
int V_34 ;
if ( F_46 ( V_102 -> V_34 < V_80 ) ) {
F_40 ( & V_2 -> V_104 -> V_2 , L_14 ) ;
return 0 ;
}
V_103 = V_102 -> V_5 [ 0 ] ;
V_34 = ( V_102 -> V_5 [ 1 ] | ( V_102 -> V_5 [ 2 ] << 8 ) ) - 4 ;
if ( F_46 ( V_103 & 0xbf ) ) {
if ( V_103 & 0x01 ) V_2 -> V_25 -> V_105 . V_106 ++ ;
if ( V_103 & 0x02 ) V_2 -> V_25 -> V_105 . V_107 ++ ;
if ( V_103 & 0x04 ) V_2 -> V_25 -> V_105 . V_108 ++ ;
if ( V_103 & 0x20 ) V_2 -> V_25 -> V_105 . V_109 ++ ;
if ( V_103 & 0x90 ) V_2 -> V_25 -> V_105 . V_110 ++ ;
return 0 ;
}
F_47 ( V_102 , 3 ) ;
F_48 ( V_102 , V_34 ) ;
return 1 ;
}
static struct V_101 * F_49 ( struct V_1 * V_2 , struct V_101 * V_102 ,
T_5 V_49 )
{
int V_34 , V_111 ;
V_34 = V_102 -> V_34 + V_75 ;
while ( ( V_34 & 1 ) || ! ( V_34 % V_2 -> V_112 ) )
V_34 ++ ;
V_34 -= V_75 ;
V_111 = V_34 - V_102 -> V_34 ;
if ( F_50 ( V_102 ) < V_75 || F_51 ( V_102 ) < V_111 ) {
struct V_101 * V_113 ;
V_113 = F_52 ( V_102 , V_75 , V_111 , V_49 ) ;
F_53 ( V_102 ) ;
V_102 = V_113 ;
if ( ! V_102 )
return NULL ;
}
F_54 ( V_102 , V_75 ) ;
if ( V_111 ) {
memset ( V_102 -> V_5 + V_102 -> V_34 , 0 , V_111 ) ;
F_55 ( V_102 , V_111 ) ;
}
V_102 -> V_5 [ 0 ] = V_34 ;
V_102 -> V_5 [ 1 ] = V_34 >> 8 ;
return V_102 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_114 * V_114 )
{
int V_115 ;
T_1 * V_116 ;
if ( V_114 -> V_117 < 8 )
return;
V_116 = V_114 -> V_118 ;
V_115 = ! ! ( V_116 [ 0 ] & 0x40 ) ;
if ( F_57 ( V_2 -> V_25 ) != V_115 ) {
F_58 ( V_2 , V_115 , 1 ) ;
F_14 ( V_2 -> V_25 , L_15 , V_115 ) ;
}
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_119 V_120 = { . V_45 = V_121 } ;
F_60 ( & V_2 -> V_42 , 1 , 1 ) ;
F_61 ( & V_2 -> V_42 , & V_120 ) ;
F_14 ( V_2 -> V_25 , L_16 ,
F_62 ( & V_120 ) , V_120 . V_122 ) ;
return 0 ;
}
