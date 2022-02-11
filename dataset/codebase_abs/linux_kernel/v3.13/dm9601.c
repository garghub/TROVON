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
V_41 -> V_42 = V_30 ;
}
static T_4 F_27 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
return F_28 ( & V_2 -> V_43 ) ;
}
static int F_29 ( struct V_29 * V_25 , struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
return F_30 ( & V_2 -> V_43 , F_31 ( V_45 ) , V_46 , NULL ) ;
}
static void F_32 ( struct V_29 * V_25 )
{
struct V_1 * V_2 = F_20 ( V_25 ) ;
T_1 * V_47 = ( T_1 * ) & V_2 -> V_5 ;
T_1 V_48 = 0x31 ;
memset ( V_47 , 0x00 , V_49 ) ;
V_47 [ V_49 - 1 ] |= 0x80 ;
if ( V_25 -> V_50 & V_51 ) {
V_48 |= 0x02 ;
} else if ( V_25 -> V_50 & V_52 ||
F_33 ( V_25 ) > V_53 ) {
V_48 |= 0x08 ;
} else if ( ! F_34 ( V_25 ) ) {
struct V_54 * V_55 ;
F_35 (ha, net) {
T_4 V_56 = F_36 ( V_57 , V_55 -> V_58 ) >> 26 ;
V_47 [ V_56 >> 3 ] |= 1 << ( V_56 & 0x7 ) ;
}
}
F_7 ( V_2 , V_59 , V_49 , V_47 ) ;
F_9 ( V_2 , V_60 , V_48 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_61 , V_57 , V_2 -> V_25 -> V_62 ) ;
}
static int F_38 ( struct V_29 * V_25 , void * V_63 )
{
struct V_64 * V_58 = V_63 ;
struct V_1 * V_2 = F_20 ( V_25 ) ;
if ( ! F_39 ( V_58 -> V_65 ) ) {
F_40 ( & V_25 -> V_2 , L_9 ,
V_58 -> V_65 ) ;
return - V_11 ;
}
memcpy ( V_25 -> V_62 , V_58 -> V_65 , V_25 -> V_66 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_67 * V_68 )
{
int V_17 ;
T_1 V_69 [ V_57 ] , V_70 ;
V_17 = F_42 ( V_2 , V_68 ) ;
if ( V_17 )
goto V_24;
V_2 -> V_25 -> V_71 = & V_72 ;
V_2 -> V_25 -> V_73 = & V_74 ;
V_2 -> V_25 -> V_75 += V_76 ;
V_2 -> V_77 = V_2 -> V_25 -> V_78 + V_2 -> V_25 -> V_75 ;
V_2 -> V_79 = V_2 -> V_25 -> V_78 + V_80 + V_81 + 1 ;
V_2 -> V_43 . V_2 = V_2 -> V_25 ;
V_2 -> V_43 . V_82 = F_21 ;
V_2 -> V_43 . V_83 = F_23 ;
V_2 -> V_43 . V_84 = 0x1f ;
V_2 -> V_43 . V_85 = 0x1f ;
F_6 ( V_2 , V_86 , 1 ) ;
F_12 ( 20 ) ;
if ( F_1 ( V_2 , V_61 , V_57 , V_69 ) < 0 ) {
F_43 ( V_87 L_10 ) ;
V_17 = - V_88 ;
goto V_24;
}
if ( F_39 ( V_69 ) )
memcpy ( V_2 -> V_25 -> V_62 , V_69 , V_57 ) ;
else {
F_43 ( V_89
L_11 ,
V_2 -> V_25 -> V_62 ) ;
F_37 ( V_2 ) ;
}
if ( F_3 ( V_2 , V_90 , & V_70 ) < 0 ) {
F_13 ( V_2 -> V_25 , L_12 ) ;
V_17 = - V_88 ;
goto V_24;
}
if ( V_70 == V_91 ) {
T_1 V_92 ;
if ( F_3 ( V_2 , V_93 , & V_92 ) < 0 ) {
F_13 ( V_2 -> V_25 , L_13 ) ;
V_17 = - V_88 ;
goto V_24;
}
F_6 ( V_2 , V_93 , V_92 & 0x7f ) ;
}
F_6 ( V_2 , V_94 , 1 ) ;
F_6 ( V_2 , V_95 , 0 ) ;
F_32 ( V_2 -> V_25 ) ;
F_23 ( V_2 -> V_25 , V_2 -> V_43 . V_36 , V_96 , V_97 ) ;
F_23 ( V_2 -> V_25 , V_2 -> V_43 . V_36 , V_98 ,
V_99 | V_100 | V_101 ) ;
F_44 ( & V_2 -> V_43 ) ;
V_24:
return V_17 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_102 * V_103 )
{
T_1 V_104 ;
int V_34 ;
if ( F_46 ( V_103 -> V_34 < V_81 ) ) {
F_40 ( & V_2 -> V_105 -> V_2 , L_14 ) ;
return 0 ;
}
V_104 = V_103 -> V_5 [ 0 ] ;
V_34 = ( V_103 -> V_5 [ 1 ] | ( V_103 -> V_5 [ 2 ] << 8 ) ) - 4 ;
if ( F_46 ( V_104 & 0xbf ) ) {
if ( V_104 & 0x01 ) V_2 -> V_25 -> V_106 . V_107 ++ ;
if ( V_104 & 0x02 ) V_2 -> V_25 -> V_106 . V_108 ++ ;
if ( V_104 & 0x04 ) V_2 -> V_25 -> V_106 . V_109 ++ ;
if ( V_104 & 0x20 ) V_2 -> V_25 -> V_106 . V_110 ++ ;
if ( V_104 & 0x90 ) V_2 -> V_25 -> V_106 . V_111 ++ ;
return 0 ;
}
F_47 ( V_103 , 3 ) ;
F_48 ( V_103 , V_34 ) ;
return 1 ;
}
static struct V_102 * F_49 ( struct V_1 * V_2 , struct V_102 * V_103 ,
T_5 V_50 )
{
int V_34 , V_112 ;
V_34 = V_103 -> V_34 + V_76 ;
while ( ( V_34 & 1 ) || ! ( V_34 % V_2 -> V_113 ) )
V_34 ++ ;
V_34 -= V_76 ;
V_112 = V_34 - V_103 -> V_34 ;
if ( F_50 ( V_103 ) < V_76 || F_51 ( V_103 ) < V_112 ) {
struct V_102 * V_114 ;
V_114 = F_52 ( V_103 , V_76 , V_112 , V_50 ) ;
F_53 ( V_103 ) ;
V_103 = V_114 ;
if ( ! V_103 )
return NULL ;
}
F_54 ( V_103 , V_76 ) ;
if ( V_112 ) {
memset ( V_103 -> V_5 + V_103 -> V_34 , 0 , V_112 ) ;
F_55 ( V_103 , V_112 ) ;
}
V_103 -> V_5 [ 0 ] = V_34 ;
V_103 -> V_5 [ 1 ] = V_34 >> 8 ;
return V_103 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_115 * V_115 )
{
int V_116 ;
T_1 * V_117 ;
if ( V_115 -> V_118 < 8 )
return;
V_117 = V_115 -> V_119 ;
V_116 = ! ! ( V_117 [ 0 ] & 0x40 ) ;
if ( F_57 ( V_2 -> V_25 ) != V_116 ) {
F_58 ( V_2 , V_116 , 1 ) ;
F_14 ( V_2 -> V_25 , L_15 , V_116 ) ;
}
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_120 V_121 = { . V_46 = V_122 } ;
F_60 ( & V_2 -> V_43 , 1 , 1 ) ;
F_61 ( & V_2 -> V_43 , & V_121 ) ;
F_14 ( V_2 -> V_25 , L_16 ,
F_62 ( & V_121 ) , V_121 . V_123 ) ;
return 0 ;
}
