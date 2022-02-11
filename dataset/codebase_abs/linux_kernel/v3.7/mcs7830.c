static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
void * V_10 ;
V_10 = F_2 ( V_4 , V_11 ) ;
if ( V_10 == NULL )
return - V_12 ;
V_9 = F_3 ( V_7 , F_4 ( V_7 , 0 ) , V_13 ,
V_14 , 0x0000 , V_3 , V_10 ,
V_4 , V_15 ) ;
memcpy ( V_5 , V_10 , V_4 ) ;
F_5 ( V_10 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , const void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
void * V_10 ;
V_10 = F_7 ( V_5 , V_4 , V_11 ) ;
if ( V_10 == NULL )
return - V_12 ;
V_9 = F_3 ( V_7 , F_8 ( V_7 , 0 ) , V_16 ,
V_17 , 0x0000 , V_3 , V_10 ,
V_4 , V_15 ) ;
F_5 ( V_10 ) ;
return V_9 ;
}
static void F_9 ( struct V_18 * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 -> V_21 ;
int V_22 = V_18 -> V_22 ;
if ( V_22 < 0 )
F_10 ( V_23 L_1 ,
V_24 , V_22 ) ;
F_5 ( V_20 ) ;
F_11 ( V_18 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
struct V_19 * V_20 ;
int V_9 ;
struct V_18 * V_18 ;
V_18 = F_13 ( 0 , V_25 ) ;
if ( ! V_18 ) {
F_14 ( & V_2 -> V_8 -> V_2 ,
L_2 ) ;
return;
}
V_20 = F_2 ( sizeof *V_20 , V_25 ) ;
if ( ! V_20 ) {
F_15 ( & V_2 -> V_8 -> V_2 ,
L_3 ) ;
goto V_26;
}
V_20 -> V_27 = V_17 ;
V_20 -> V_28 = V_16 ;
V_20 -> V_29 = 0 ;
V_20 -> V_30 = F_16 ( V_3 ) ;
V_20 -> V_31 = F_16 ( V_4 ) ;
F_17 ( V_18 , V_2 -> V_8 ,
F_8 ( V_2 -> V_8 , 0 ) ,
( void * ) V_20 , V_5 , V_4 ,
F_9 , V_20 ) ;
V_9 = F_18 ( V_18 , V_25 ) ;
if ( V_9 < 0 ) {
F_15 ( & V_2 -> V_8 -> V_2 ,
L_4 , V_9 ) ;
goto V_26;
}
return;
V_26:
F_5 ( V_20 ) ;
F_11 ( V_18 ) ;
}
static int F_19 ( struct V_1 * V_2 , unsigned char * V_32 )
{
int V_9 = F_1 ( V_2 , V_33 , V_34 , V_32 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned char * V_32 )
{
int V_9 = F_6 ( V_2 , V_33 , V_34 , V_32 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , void * V_37 )
{
int V_9 ;
struct V_1 * V_2 = F_22 ( V_36 ) ;
struct V_38 * V_32 = V_37 ;
if ( F_23 ( V_36 ) )
return - V_39 ;
if ( ! F_24 ( V_32 -> V_40 ) )
return - V_41 ;
V_9 = F_20 ( V_2 , V_32 -> V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
memcpy ( V_36 -> V_42 , V_32 -> V_40 , V_36 -> V_43 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_9 ;
int V_44 ;
T_3 V_45 ;
T_2 V_46 [ 2 ] = {
V_47 | V_48 ,
V_49 | V_3 ,
} ;
F_26 ( & V_2 -> V_50 ) ;
V_9 = F_6 ( V_2 , V_51 , 2 , V_46 ) ;
if ( V_9 < 0 )
goto V_26;
for ( V_44 = 0 ; V_44 < 10 ; V_44 ++ ) {
V_9 = F_1 ( V_2 , V_51 , 2 , V_46 ) ;
if ( ( V_9 < 0 ) || ( V_46 [ 1 ] & V_52 ) )
break;
V_9 = - V_53 ;
F_27 ( 1 ) ;
}
if ( V_9 < 0 )
goto V_26;
V_9 = F_1 ( V_2 , V_54 , 2 , & V_45 ) ;
if ( V_9 < 0 )
goto V_26;
V_9 = F_28 ( V_45 ) ;
F_14 ( & V_2 -> V_8 -> V_2 , L_5 ,
V_3 , V_45 , V_44 ) ;
V_26:
F_29 ( & V_2 -> V_50 ) ;
return V_9 ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_45 )
{
int V_9 ;
int V_44 ;
T_3 V_55 ;
T_2 V_46 [ 2 ] = {
V_56 | V_48 ,
V_49 | ( V_3 & 0x1F ) ,
} ;
F_26 ( & V_2 -> V_50 ) ;
V_55 = F_16 ( V_45 ) ;
V_9 = F_6 ( V_2 , V_54 , 2 , & V_55 ) ;
if ( V_9 < 0 )
goto V_26;
V_9 = F_6 ( V_2 , V_51 , 2 , V_46 ) ;
if ( V_9 < 0 )
goto V_26;
for ( V_44 = 0 ; V_44 < 10 ; V_44 ++ ) {
V_9 = F_1 ( V_2 , V_51 , 2 , V_46 ) ;
if ( ( V_9 < 0 ) || ( V_46 [ 1 ] & V_52 ) )
break;
V_9 = - V_53 ;
F_27 ( 1 ) ;
}
if ( V_9 < 0 )
goto V_26;
V_9 = 0 ;
F_14 ( & V_2 -> V_8 -> V_2 , L_6 ,
V_3 , V_45 , V_44 ) ;
V_26:
F_29 ( & V_2 -> V_50 ) ;
return V_9 ;
}
static int F_31 ( struct V_1 * V_2 , int V_57 )
{
int V_9 ;
V_9 = F_30 ( V_2 , V_58 , V_59 ) ;
if ( ! V_9 )
V_9 = F_30 ( V_2 , V_60 , 0x0000 ) ;
if ( ! V_9 )
V_9 = F_30 ( V_2 , V_60 , V_61 ) ;
if ( ! V_9 )
V_9 = F_30 ( V_2 , V_60 ,
V_61 | V_62 ) ;
return V_9 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_2 V_63 [ 2 ] ;
int V_9 ;
V_9 = F_1 ( V_2 , V_64 , 2 , V_63 ) ;
if ( V_9 > 0 )
return 2 ;
return 1 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_2 V_65 = V_66 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < 2 ; V_67 ++ ) {
if ( F_32 ( V_2 ) == 2 ) {
F_34 ( & V_2 -> V_8 -> V_2 , L_7 ) ;
F_6 ( V_2 , V_68 ,
1 , & V_65 ) ;
}
F_27 ( 1 ) ;
}
}
static int F_35 ( struct V_35 * V_36 , int V_69 ,
int V_70 )
{
struct V_1 * V_2 = F_22 ( V_36 ) ;
return F_25 ( V_2 , V_70 ) ;
}
static void F_36 ( struct V_35 * V_36 , int V_69 ,
int V_70 , int V_45 )
{
struct V_1 * V_2 = F_22 ( V_36 ) ;
F_30 ( V_2 , V_70 , V_45 ) ;
}
static int F_37 ( struct V_35 * V_71 , struct V_72 * V_73 , int V_46 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
return F_38 ( & V_2 -> V_74 , F_39 ( V_73 ) , V_46 , NULL ) ;
}
static inline struct V_75 * F_40 ( struct V_1 * V_2 )
{
return (struct V_75 * ) & V_2 -> V_5 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_75 * V_5 = F_40 ( V_2 ) ;
F_12 ( V_2 , V_76 ,
sizeof V_5 -> V_77 ,
V_5 -> V_77 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_75 * V_5 = F_40 ( V_2 ) ;
F_12 ( V_2 , V_78 , 1 , & V_5 -> V_79 ) ;
}
static void F_43 ( struct V_35 * V_71 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
struct V_75 * V_5 = F_40 ( V_2 ) ;
memset ( V_5 -> V_77 , 0 , sizeof V_5 -> V_77 ) ;
V_5 -> V_79 = V_80 ;
V_5 -> V_79 |= V_81 ;
if ( V_71 -> V_82 & V_83 ) {
V_5 -> V_79 |= V_84 ;
} else if ( V_71 -> V_82 & V_85 ||
F_44 ( V_71 ) > V_86 ) {
V_5 -> V_79 |= V_81 ;
} else if ( F_45 ( V_71 ) ) {
} else {
struct V_87 * V_88 ;
T_4 V_89 ;
F_46 (ha, net) {
V_89 = F_47 ( V_34 , V_88 -> V_32 ) >> 26 ;
V_5 -> V_77 [ V_89 >> 3 ] |= 1 << ( V_89 & 7 ) ;
}
}
}
static int F_48 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_20 ( V_2 , V_2 -> V_71 -> V_42 ) ;
if ( V_9 ) {
F_34 ( & V_2 -> V_8 -> V_2 , L_8 ) ;
goto V_26;
}
V_9 = F_31 ( V_2 , 0 ) ;
if ( V_9 ) {
F_34 ( & V_2 -> V_8 -> V_2 , L_9 ) ;
goto V_26;
}
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
F_33 ( V_2 ) ;
V_9 = 0 ;
V_26:
return V_9 ;
}
static void F_49 ( struct V_35 * V_71 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
F_43 ( V_71 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static int F_50 ( struct V_35 * V_71 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
switch ( F_32 ( V_2 ) ) {
case 1 :
return 21 ;
case 2 :
return 32 ;
}
return 0 ;
}
static void F_51 ( struct V_35 * V_71 , struct V_90 * V_91 )
{
F_52 ( V_71 , V_91 ) ;
V_91 -> V_92 = F_50 ( V_71 ) ;
}
static void F_53 ( struct V_35 * V_71 , struct V_93 * V_94 , void * V_5 )
{
struct V_1 * V_2 = F_22 ( V_71 ) ;
V_94 -> V_95 = F_32 ( V_2 ) ;
F_1 ( V_2 , 0 , V_94 -> V_96 , V_5 ) ;
}
static int F_54 ( struct V_1 * V_2 , struct V_97 * V_8 )
{
struct V_35 * V_71 = V_2 -> V_71 ;
int V_9 ;
int V_67 ;
V_9 = - V_98 ;
for ( V_67 = 0 ; V_67 < 5 && V_9 ; V_67 ++ )
V_9 = F_19 ( V_2 , V_71 -> V_42 ) ;
if ( V_9 ) {
F_55 ( & V_2 -> V_8 -> V_2 , L_10 ) ;
goto V_26;
}
F_43 ( V_71 ) ;
V_9 = F_48 ( V_2 ) ;
if ( V_9 )
goto V_26;
V_71 -> V_99 = & V_100 ;
V_71 -> V_101 = & V_102 ;
V_2 -> V_103 = V_104 + 1 ;
V_2 -> V_74 . V_105 = F_35 ;
V_2 -> V_74 . V_106 = F_36 ;
V_2 -> V_74 . V_2 = V_71 ;
V_2 -> V_74 . V_107 = 0x3f ;
V_2 -> V_74 . V_108 = 0x1f ;
V_2 -> V_74 . V_69 = * ( ( T_2 * ) V_71 -> V_42 + 1 ) ;
V_9 = F_56 ( V_2 , V_8 ) ;
V_26:
return V_9 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_109 * V_110 )
{
T_2 V_22 ;
if ( V_110 -> V_96 == 0 ) {
F_15 ( & V_2 -> V_8 -> V_2 , L_11 ) ;
return 0 ;
}
F_58 ( V_110 , V_110 -> V_96 - 1 ) ;
V_22 = V_110 -> V_5 [ V_110 -> V_96 ] ;
if ( V_22 != V_111 ) {
F_14 ( & V_2 -> V_8 -> V_2 , L_12 , V_22 ) ;
V_2 -> V_71 -> V_112 . V_113 ++ ;
if ( V_22 & ( V_114
| V_115
| V_116 ) )
V_2 -> V_71 -> V_112 . V_117 ++ ;
if ( V_22 & V_118 )
V_2 -> V_71 -> V_112 . V_119 ++ ;
if ( V_22 & V_120 )
V_2 -> V_71 -> V_112 . V_121 ++ ;
}
return V_110 -> V_96 > 0 ;
}
static void F_59 ( struct V_1 * V_2 , struct V_18 * V_18 )
{
T_2 * V_122 = V_18 -> V_123 ;
bool V_124 , V_125 ;
struct V_75 * V_5 = F_40 ( V_2 ) ;
if ( V_18 -> V_126 < 16 )
return;
V_124 = ! ( V_122 [ 1 ] & 0x20 ) ;
V_125 = F_60 ( V_2 -> V_71 ) != V_124 ;
if ( V_125 ) {
V_5 -> V_127 ++ ;
if ( V_5 -> V_127 > 20 ) {
V_5 -> V_127 = 0 ;
if ( V_124 ) {
F_61 ( V_2 -> V_71 ) ;
F_62 ( V_2 , V_128 ) ;
} else
F_63 ( V_2 -> V_71 ) ;
F_64 ( V_2 -> V_71 , L_13 , V_124 ) ;
}
} else
V_5 -> V_127 = 0 ;
}
static int F_65 ( struct V_97 * V_129 )
{
struct V_1 * V_2 = F_66 ( V_129 ) ;
F_48 ( V_2 ) ;
F_67 ( V_129 ) ;
return 0 ;
}
