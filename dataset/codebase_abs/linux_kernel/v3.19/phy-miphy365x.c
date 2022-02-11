static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
bool V_5 = ( V_2 -> type == V_6 ) ;
return F_2 ( V_4 -> V_7 ,
( unsigned int ) V_2 -> V_8 ,
V_9 ,
V_5 << V_10 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_11 ;
if ( V_2 -> V_12 ) {
V_11 = V_13 | V_14 | V_15 | V_16 ;
F_4 ( V_11 , V_2 -> V_17 + V_18 ) ;
F_4 ( 0x00 , V_2 -> V_17 + V_19 ) ;
}
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_20 = V_21 + F_6 ( V_22 ) ;
T_1 V_23 = V_24 | V_25 ;
T_1 V_26 ;
do {
V_26 = F_7 ( V_2 -> V_17 + V_27 ) ;
if ( ! ( V_26 & V_23 ) )
return 0 ;
F_8 ( 2000 , 2500 ) ;
} while ( F_9 ( V_21 , V_20 ) );
F_10 ( V_4 -> V_28 , L_1 ) ;
return - V_29 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_20 = V_21 + F_6 ( V_22 ) ;
T_1 V_23 = V_24 | V_25 ;
T_1 V_26 ;
do {
V_26 = F_7 ( V_2 -> V_17 + V_27 ) ;
if ( ( V_26 & V_23 ) == V_23 )
return 0 ;
F_8 ( 2000 , 2500 ) ;
} while ( F_9 ( V_21 , V_20 ) );
F_10 ( V_4 -> V_28 , L_2 ) ;
return - V_29 ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_11 , V_23 ;
if ( V_2 -> V_30 == V_31 )
F_4 ( V_32 ,
V_2 -> V_17 + V_33 ) ;
else
F_4 ( V_34 ,
V_2 -> V_17 + V_33 ) ;
if ( V_2 -> V_30 != V_35 ) {
F_4 ( V_36 ,
V_2 -> V_17 + V_37 ) ;
F_4 ( V_38 , V_2 -> V_17 + V_39 ) ;
F_4 ( V_40 , V_2 -> V_17 + V_41 ) ;
}
V_11 = V_42 | V_43 | V_44 ;
F_4 ( V_11 , V_2 -> V_17 + V_45 ) ;
V_23 = V_46 | V_47 ;
while ( ( F_7 ( V_2 -> V_17 + V_45 ) & V_23 ) != V_23 )
F_13 () ;
}
static inline void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_11 ;
F_4 ( V_48 ,
V_2 -> V_17 + V_49 ) ;
F_4 ( V_50 ,
V_2 -> V_17 + V_51 ) ;
F_4 ( V_52 ,
V_2 -> V_17 + V_53 ) ;
F_4 ( V_54 ,
V_2 -> V_17 + V_55 ) ;
if ( V_2 -> V_30 == V_31 ) {
V_11 = V_56 | V_57 | V_58 | V_59 ;
F_4 ( V_11 , V_2 -> V_17 + V_60 ) ;
} else {
V_11 = V_61 | V_56 | V_57 | V_58 | V_59 ;
F_4 ( V_11 , V_2 -> V_17 + V_60 ) ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_62 ;
T_1 V_11 ;
V_11 = V_63 | V_64 | V_65 | V_66 ;
F_4 ( V_11 , V_2 -> V_17 + V_67 ) ;
if ( V_2 -> V_68 )
F_4 ( V_16 , V_2 -> V_17 + V_18 ) ;
F_4 ( V_69 , V_2 -> V_17 + V_70 ) ;
F_4 ( V_71 , V_2 -> V_17 + V_72 ) ;
V_11 = V_73 [ V_2 -> V_30 ] ;
F_4 ( V_11 , V_2 -> V_17 + V_74 ) ;
V_62 = F_5 ( V_2 , V_4 ) ;
if ( V_62 )
return V_62 ;
F_12 ( V_2 , V_4 ) ;
switch ( V_2 -> V_30 ) {
case V_35 :
V_11 = V_75 | V_76 ;
F_4 ( V_11 , V_2 -> V_17 + V_77 ) ;
V_11 = V_78 | V_79 ;
F_4 ( V_11 , V_2 -> V_17 + V_80 ) ;
F_4 ( V_81 , V_2 -> V_17 + V_82 ) ;
F_4 ( 0x00 , V_2 -> V_17 + V_83 ) ;
V_11 = V_84 | V_85 ;
F_4 ( V_11 , V_2 -> V_17 + V_86 ) ;
break;
case V_87 :
F_4 ( V_88 ,
V_2 -> V_17 + V_77 ) ;
F_4 ( V_78 , V_2 -> V_17 + V_80 ) ;
F_4 ( V_81 , V_2 -> V_17 + V_82 ) ;
V_11 = V_84 | V_89 ;
F_4 ( V_11 , V_2 -> V_17 + V_86 ) ;
break;
case V_31 :
F_4 ( V_75 , V_2 -> V_17 + V_77 ) ;
F_4 ( V_90 , V_2 -> V_17 + V_80 ) ;
F_4 ( V_91 , V_2 -> V_17 + V_82 ) ;
break;
default:
break;
}
F_4 ( V_65 , V_2 -> V_17 + V_67 ) ;
F_8 ( 100 , 150 ) ;
F_14 ( V_2 , V_4 ) ;
V_62 = F_11 ( V_2 , V_4 ) ;
if ( V_62 )
return V_62 ;
F_4 ( 0x00 , V_2 -> V_17 + V_70 ) ;
F_4 ( 0x00 , V_2 -> V_17 + V_72 ) ;
F_4 ( V_65 , V_2 -> V_17 + V_67 ) ;
V_11 = V_2 -> V_68 ?
( V_16 | V_15 ) : V_15 ;
F_4 ( V_11 , V_2 -> V_17 + V_18 ) ;
V_11 = V_92 | V_93 ;
F_4 ( V_11 , V_2 -> V_17 + V_94 ) ;
F_4 ( 0x00 , V_2 -> V_17 + V_67 ) ;
return 0 ;
}
static int F_16 ( struct V_95 * V_95 )
{
struct V_1 * V_2 = F_17 ( V_95 ) ;
struct V_3 * V_4 = F_18 ( V_95 -> V_28 . V_96 ) ;
int V_62 = 0 ;
F_19 ( & V_4 -> V_97 ) ;
V_62 = F_1 ( V_2 , V_4 ) ;
if ( V_62 ) {
F_20 ( & V_4 -> V_97 ) ;
return V_62 ;
}
if ( V_2 -> type == V_98 )
V_62 = F_3 ( V_2 , V_4 ) ;
else
V_62 = F_15 ( V_2 , V_4 ) ;
F_20 ( & V_4 -> V_97 ) ;
return V_62 ;
}
int F_21 ( struct V_99 * V_28 , struct V_1 * V_2 ,
int V_100 )
{
struct V_101 * V_102 = V_2 -> V_95 -> V_28 . V_103 ;
const char * V_104 ;
const T_2 * V_105 ;
int type = V_2 -> type ;
int V_62 ;
V_62 = F_22 ( V_102 , L_3 , V_100 , & V_104 ) ;
if ( V_62 ) {
F_10 ( V_28 , L_4 ) ;
return V_62 ;
}
if ( ! strncmp ( V_104 , L_5 , 6 ) ) {
V_105 = F_23 ( V_102 , V_100 , NULL , NULL ) ;
if ( ! V_105 ) {
F_10 ( V_28 , L_6 ) ;
return - V_106 ;
}
V_2 -> V_8 = F_24 ( V_102 , V_105 ) ;
if ( V_2 -> V_8 == V_107 ) {
F_10 ( V_28 , L_7 ) ;
return - V_106 ;
}
return 0 ;
}
if ( ! ( ( ! strncmp ( V_104 , L_8 , 4 ) && type == V_6 ) ||
( ! strncmp ( V_104 , L_9 , 4 ) && type == V_98 ) ) )
return 0 ;
V_2 -> V_17 = F_25 ( V_102 , V_100 ) ;
if ( ! V_2 -> V_17 ) {
F_10 ( V_28 , L_10 , V_102 -> V_108 ) ;
return - V_106 ;
}
return 0 ;
}
static struct V_95 * F_26 ( struct V_99 * V_28 ,
struct V_109 * args )
{
struct V_3 * V_4 = F_18 ( V_28 ) ;
struct V_1 * V_2 = NULL ;
struct V_101 * V_102 = args -> V_110 ;
int V_62 , V_100 ;
if ( ! F_27 ( V_102 ) ) {
F_28 ( V_28 , L_11 ) ;
return F_29 ( - V_111 ) ;
}
if ( args -> V_112 != 1 ) {
F_10 ( V_28 , L_12 ) ;
return F_29 ( - V_106 ) ;
}
for ( V_100 = 0 ; V_100 < F_30 ( V_28 -> V_103 ) ; V_100 ++ )
if ( V_102 == V_4 -> V_113 [ V_100 ] -> V_95 -> V_28 . V_103 ) {
V_2 = V_4 -> V_113 [ V_100 ] ;
break;
}
if ( ! V_2 ) {
F_10 ( V_28 , L_13 ) ;
return F_29 ( - V_106 ) ;
}
V_2 -> type = args -> args [ 0 ] ;
if ( ! ( V_2 -> type == V_6 ||
V_2 -> type == V_98 ) ) {
F_10 ( V_28 , L_14 , V_2 -> type ) ;
return F_29 ( - V_106 ) ;
}
for ( V_100 = 0 ; V_100 < 3 ; V_100 ++ ) {
V_62 = F_21 ( V_28 , V_2 , V_100 ) ;
if ( V_62 < 0 )
return F_29 ( V_62 ) ;
}
return V_2 -> V_95 ;
}
static int F_31 ( struct V_101 * V_102 ,
struct V_1 * V_2 )
{
F_32 ( V_102 , L_15 , & V_2 -> V_30 ) ;
if ( ! V_2 -> V_30 )
V_2 -> V_30 = V_31 ;
V_2 -> V_12 =
F_33 ( V_102 , L_16 ) ;
V_2 -> V_68 =
F_33 ( V_102 , L_17 ) ;
return 0 ;
}
static int F_34 ( struct V_114 * V_115 )
{
struct V_101 * V_116 , * V_110 = V_115 -> V_28 . V_103 ;
struct V_3 * V_4 ;
struct V_117 * V_118 ;
struct V_95 * V_95 ;
int V_119 , V_120 = 0 ;
int V_62 ;
V_4 = F_35 ( & V_115 -> V_28 , sizeof( * V_4 ) , V_121 ) ;
if ( ! V_4 )
return - V_122 ;
V_119 = F_30 ( V_110 ) ;
V_4 -> V_113 = F_35 ( & V_115 -> V_28 , sizeof( V_95 ) * V_119 ,
V_121 ) ;
if ( ! V_4 -> V_113 )
return - V_122 ;
V_4 -> V_7 = F_36 ( V_110 , L_18 ) ;
if ( F_37 ( V_4 -> V_7 ) ) {
F_10 ( V_4 -> V_28 , L_19 ) ;
return F_38 ( V_4 -> V_7 ) ;
}
V_4 -> V_28 = & V_115 -> V_28 ;
F_39 ( & V_115 -> V_28 , V_4 ) ;
F_40 ( & V_4 -> V_97 ) ;
F_41 (np, child) {
struct V_1 * V_2 ;
V_2 = F_35 ( & V_115 -> V_28 , sizeof( * V_2 ) ,
V_121 ) ;
if ( ! V_2 )
return - V_122 ;
V_4 -> V_113 [ V_120 ] = V_2 ;
V_95 = F_42 ( & V_115 -> V_28 , V_116 , & V_123 ) ;
if ( F_37 ( V_95 ) ) {
F_10 ( & V_115 -> V_28 , L_20 ) ;
return F_38 ( V_95 ) ;
}
V_4 -> V_113 [ V_120 ] -> V_95 = V_95 ;
V_62 = F_31 ( V_116 , V_2 ) ;
if ( V_62 )
return V_62 ;
F_43 ( V_95 , V_4 -> V_113 [ V_120 ] ) ;
V_120 ++ ;
}
V_118 = F_44 ( & V_115 -> V_28 , F_26 ) ;
return F_45 ( V_118 ) ;
}
