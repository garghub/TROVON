static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_2 ( V_2 , V_7 , V_8 , 0 , V_3 , V_5 ,
V_4 ) ;
if ( ( V_6 != V_4 ) && ( V_6 >= 0 ) )
V_6 = - V_9 ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_10 , V_11 , 0 , V_3 , V_5 ,
V_4 ) ;
if ( ( V_6 >= 0 ) && ( V_6 < V_4 ) )
V_6 = - V_9 ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_12 )
{
return F_1 ( V_2 , V_3 , 1 , V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
return F_4 ( V_2 , V_10 , V_11 ,
V_12 , V_3 , NULL , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , void * V_5 )
{
F_8 ( V_2 , V_10 , V_11 ,
0 , V_3 , V_5 , V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_12 )
{
F_8 ( V_2 , V_10 , V_11 ,
V_12 , V_3 , NULL , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
T_1 V_16 = 0 ;
int V_17 ;
F_11 ( 1 ) ;
V_17 = F_5 ( V_2 , V_18 , & V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! ( V_16 & V_19 ) )
return 0 ;
}
F_12 ( V_2 -> V_20 , L_1 , V_13 ? L_2 : L_3 ) ;
return - V_21 ;
}
static int F_13 ( struct V_1 * V_2 , int V_13 , T_1 V_3 ,
T_3 * V_12 )
{
int V_17 ;
F_14 ( & V_2 -> V_22 ) ;
F_6 ( V_2 , V_23 , V_13 ? ( V_3 | V_24 ) : V_3 ) ;
F_6 ( V_2 , V_18 , V_13 ? ( V_25 | V_26 ) : V_26 ) ;
V_17 = F_10 ( V_2 , V_13 ) ;
if ( V_17 < 0 )
goto V_27;
F_6 ( V_2 , V_18 , 0x0 ) ;
V_17 = F_1 ( V_2 , V_28 , 2 , V_12 ) ;
F_15 ( V_2 -> V_20 , L_4 ,
V_13 , V_3 , * V_12 , V_17 ) ;
V_27:
F_16 ( & V_2 -> V_22 ) ;
return V_17 ;
}
static int F_17 ( struct V_1 * V_2 , int V_13 , T_1 V_3 ,
T_3 V_12 )
{
int V_17 ;
F_14 ( & V_2 -> V_22 ) ;
V_17 = F_3 ( V_2 , V_28 , 2 , & V_12 ) ;
if ( V_17 < 0 )
goto V_27;
F_6 ( V_2 , V_23 , V_13 ? ( V_3 | V_24 ) : V_3 ) ;
F_6 ( V_2 , V_18 , V_13 ? ( V_29 | V_25 | V_30 ) :
( V_29 | V_30 ) ) ;
V_17 = F_10 ( V_2 , V_13 ) ;
if ( V_17 < 0 )
goto V_27;
F_6 ( V_2 , V_18 , 0x0 ) ;
V_27:
F_16 ( & V_2 -> V_22 ) ;
return V_17 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_31 , void * V_12 )
{
return F_13 ( V_2 , 0 , V_31 , V_12 ) ;
}
static int F_19 ( struct V_32 * V_33 )
{
return V_34 ;
}
static int F_20 ( struct V_32 * V_33 ,
struct V_35 * V_36 , T_1 * V_5 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
T_3 * V_37 = ( T_3 * ) V_5 ;
int V_17 = 0 ;
int V_14 ;
if ( ( V_36 -> V_31 & 0x01 ) || ( V_36 -> V_38 & 0x01 ) )
return - V_9 ;
for ( V_14 = 0 ; V_14 < V_36 -> V_38 / 2 ; V_14 ++ ) {
V_17 = F_18 ( V_2 , V_36 -> V_31 / 2 + V_14 , V_37 + V_14 ) ;
if ( V_17 < 0 )
break;
}
return V_17 ;
}
static int F_22 ( struct V_32 * V_33 , int V_39 , int V_40 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
T_3 V_41 ;
int V_42 = 0 ;
if ( V_39 ) {
F_15 ( V_33 , L_5 ) ;
return 0 ;
}
if ( V_40 == V_43 ) {
T_1 V_12 ;
F_5 ( V_2 , V_44 , & V_12 ) ;
if ( V_12 & V_45 )
V_42 = 1 ;
}
F_13 ( V_2 , 1 , V_40 , & V_41 ) ;
if ( V_42 == 1 )
V_41 = F_23 ( V_41 ) | V_46 ;
else
V_41 = F_23 ( V_41 ) & ~ V_46 ;
F_15 ( V_33 , L_6 ,
V_39 , V_40 , V_41 ) ;
return V_41 ;
}
static void F_24 ( struct V_32 * V_33 , int V_39 , int V_40 ,
int V_47 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
T_3 V_41 = F_25 ( V_47 ) ;
if ( V_39 ) {
F_15 ( V_33 , L_5 ) ;
return;
}
F_15 ( V_33 , L_7 ,
V_39 , V_40 , V_47 ) ;
F_17 ( V_2 , 1 , V_40 , V_41 ) ;
}
static T_4 F_26 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
T_1 V_12 = 0 ;
int V_42 = 0 ;
F_5 ( V_2 , V_44 , & V_12 ) ;
if ( V_12 & V_45 )
V_42 = 1 ;
return V_42 ;
}
static int F_27 ( struct V_32 * V_33 , struct V_48 * V_49 , int V_50 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
return F_28 ( & V_2 -> V_51 , F_29 ( V_49 ) , V_50 , NULL ) ;
}
static void F_30 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
T_1 * V_52 = ( T_1 * ) & V_2 -> V_5 ;
T_1 V_53 = V_54 | V_55 | V_56 ;
memset ( V_52 , 0x00 , V_57 ) ;
V_52 [ V_57 - 1 ] |= V_58 ;
if ( V_33 -> V_59 & V_60 ) {
V_53 |= V_61 ;
} else if ( V_33 -> V_59 & V_62 ||
F_31 ( V_33 ) > V_63 ) {
V_53 |= V_64 ;
} else if ( ! F_32 ( V_33 ) ) {
struct V_65 * V_66 ;
F_33 (ha, netdev) {
T_4 V_67 = F_34 ( V_68 , V_66 -> V_69 ) >> 26 ;
V_52 [ V_67 >> 3 ] |= 1 << ( V_67 & 0x7 ) ;
}
}
F_7 ( V_2 , V_70 , V_57 , V_52 ) ;
F_9 ( V_2 , V_71 , V_53 ) ;
}
static int F_35 ( struct V_32 * V_33 , void * V_72 )
{
struct V_1 * V_2 = F_21 ( V_33 ) ;
struct V_73 * V_69 = V_72 ;
if ( ! F_36 ( V_69 -> V_74 ) ) {
F_12 ( V_33 , L_8 ,
V_69 -> V_74 ) ;
return - V_9 ;
}
memcpy ( V_33 -> V_75 , V_69 -> V_74 , V_33 -> V_76 ) ;
F_7 ( V_2 , V_77 , 6 , V_33 -> V_75 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_32 * V_33 ;
struct V_80 * V_51 ;
int V_17 ;
V_17 = F_38 ( V_2 , V_79 ) ;
if ( V_17 )
goto V_81;
V_33 = V_2 -> V_20 ;
V_33 -> V_82 = & V_83 ;
V_33 -> V_84 = & V_85 ;
V_33 -> V_86 += V_87 ;
V_2 -> V_88 = V_33 -> V_89 + V_33 -> V_86 ;
V_2 -> V_90 = 3072 ;
V_51 = & V_2 -> V_51 ;
V_51 -> V_2 = V_33 ;
V_51 -> V_91 = F_22 ;
V_51 -> V_92 = F_24 ;
V_51 -> V_93 = 0x1f ;
V_51 -> V_94 = 0x1f ;
F_6 ( V_2 , V_95 , V_96 ) ;
F_11 ( 20 ) ;
if ( F_1 ( V_2 , V_77 , V_68 , V_33 -> V_75 ) < 0 ) {
F_12 ( V_33 , L_9 ) ;
V_17 = - V_97 ;
goto V_81;
}
F_6 ( V_2 , V_98 , V_99 ) ;
F_39 ( 20 ) ;
F_6 ( V_2 , V_98 , 0 ) ;
F_11 ( 2 * 1000 ) ;
F_30 ( V_33 ) ;
F_24 ( V_33 , V_51 -> V_39 , V_100 , V_101 ) ;
F_24 ( V_33 , V_51 -> V_39 , V_102 , V_103 |
V_104 | V_105 ) ;
F_40 ( V_51 ) ;
V_81:
return V_17 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
struct V_106 * V_108 ;
int V_38 ;
if ( F_42 ( V_107 -> V_38 < V_109 ) ) {
F_12 ( V_2 -> V_20 , L_10 ) ;
return 0 ;
}
while ( V_107 -> V_38 > V_109 ) {
if ( V_107 -> V_5 [ 0 ] != 0x40 )
return 0 ;
V_38 = ( V_107 -> V_5 [ 1 ] | ( V_107 -> V_5 [ 2 ] << 8 ) ) - 4 ;
if ( V_38 > V_110 )
return 0 ;
if ( V_107 -> V_38 == ( V_38 + V_109 ) ) {
F_43 ( V_107 , 3 ) ;
V_107 -> V_38 = V_38 ;
F_44 ( V_107 , V_38 ) ;
V_107 -> V_111 = V_38 + sizeof( struct V_106 ) ;
return 2 ;
}
V_108 = F_45 ( V_107 , V_112 ) ;
if ( ! V_108 )
return 0 ;
V_108 -> V_38 = V_38 ;
V_108 -> V_5 = V_107 -> V_5 + 3 ;
F_44 ( V_108 , V_38 ) ;
V_108 -> V_111 = V_38 + sizeof( struct V_106 ) ;
F_46 ( V_2 , V_108 ) ;
F_43 ( V_107 , V_38 + V_109 ) ;
} ;
return 0 ;
}
static struct V_106 * F_47 ( struct V_1 * V_2 , struct V_106 * V_107 ,
T_5 V_59 )
{
int V_38 ;
V_38 = V_107 -> V_38 ;
if ( F_48 ( V_107 , V_87 ) ) {
F_49 ( V_107 ) ;
return NULL ;
}
F_50 ( V_107 , V_87 ) ;
if ( ( V_107 -> V_38 % V_2 -> V_113 ) == 0 )
V_38 ++ ;
V_107 -> V_5 [ 0 ] = V_38 ;
V_107 -> V_5 [ 1 ] = V_38 >> 8 ;
return V_107 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_114 * V_114 )
{
int V_115 ;
T_1 * V_37 ;
if ( V_114 -> V_116 < 8 )
return;
V_37 = V_114 -> V_117 ;
V_115 = ! ! ( V_37 [ 0 ] & 0x40 ) ;
if ( F_52 ( V_2 -> V_20 ) != V_115 ) {
F_53 ( V_2 , V_115 , 1 ) ;
F_15 ( V_2 -> V_20 , L_11 , V_115 ) ;
}
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_118 V_119 ;
F_55 ( & V_2 -> V_51 , 1 , 1 ) ;
F_56 ( & V_2 -> V_51 , & V_119 ) ;
F_15 ( V_2 -> V_20 , L_12 ,
V_119 . V_120 , V_119 . V_121 ) ;
return 0 ;
}
