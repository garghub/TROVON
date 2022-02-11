static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_4 = V_4 & 0x00ff ;
F_2 ( & V_2 -> V_6 , L_1 , V_3 , V_4 ) ;
return F_3 ( V_6 , F_4 ( V_6 , 0 ) , V_8 ,
V_9 , V_4 , V_3 , NULL , 0 ,
V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_11 = 0 ;
T_2 * V_12 ;
V_12 = F_6 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
V_11 = F_3 ( V_6 , F_7 ( V_6 , 0 ) , V_16 ,
V_17 , 0 , V_3 , V_12 , V_13 ,
V_10 ) ;
if ( V_11 < V_13 ) {
if ( V_11 >= 0 )
V_11 = - V_18 ;
goto V_19;
}
* V_4 = V_12 [ 0 ] ;
F_2 ( & V_2 -> V_6 , L_2 , V_20 , V_3 , * V_4 ) ;
V_19:
F_8 ( V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_4 = V_4 & 0x00ff ;
if ( V_2 -> V_7 -> V_21 == 4 ) {
V_4 |= ( ( T_1 ) V_2 -> V_22 + 1 ) << 8 ;
} else {
if ( V_2 -> V_22 == 0 ) {
V_4 |= ( ( T_1 ) V_2 -> V_22 + 1 ) << 8 ;
} else {
V_4 |= ( ( T_1 ) V_2 -> V_22 + 2 ) << 8 ;
}
}
F_2 ( & V_2 -> V_6 , L_3 , V_20 , V_4 ) ;
return F_3 ( V_6 , F_4 ( V_6 , 0 ) , V_8 ,
V_9 , V_4 , V_3 , NULL , 0 ,
V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_11 = 0 ;
T_1 V_23 ;
T_2 * V_12 ;
V_12 = F_6 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
if ( V_2 -> V_7 -> V_21 == 4 ) {
V_23 = ( ( T_1 ) V_2 -> V_22 + 1 ) << 8 ;
} else {
if ( V_2 -> V_22 == 0 ) {
V_23 = ( ( T_1 ) V_2 -> V_22 + 1 ) << 8 ;
} else {
V_23 = ( ( T_1 ) V_2 -> V_22 + 2 ) << 8 ;
}
}
F_2 ( & V_2 -> V_6 , L_3 , V_20 , V_23 ) ;
V_11 = F_3 ( V_6 , F_7 ( V_6 , 0 ) , V_16 ,
V_17 , V_23 , V_3 , V_12 , V_13 ,
V_10 ) ;
if ( V_11 < V_13 ) {
if ( V_11 >= 0 )
V_11 = - V_18 ;
goto V_19;
}
* V_4 = V_12 [ 0 ] ;
V_19:
F_8 ( V_12 ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
F_2 ( & V_2 -> V_6 , L_4 , V_25 -> V_26 ) ;
F_2 ( & V_2 -> V_6 , L_5 , V_25 -> V_27 ) ;
F_2 ( & V_2 -> V_6 , L_6 , V_25 -> V_28 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_24 * V_29 )
{
F_13 ( V_2 , ( void * ) V_29 ) ;
}
static inline struct V_24 * F_14 ( struct
V_1
* V_2 )
{
return (struct V_24 * ) F_15 ( V_2 ) ;
}
static void F_16 ( struct V_24 * V_2 , T_3 V_30 )
{
struct V_24 * V_25 ;
struct V_31 * V_32 ;
V_25 = V_2 ;
if ( V_30 &
( V_33 | V_34 | V_35 |
V_36 ) ) {
V_32 = & V_25 -> V_2 -> V_32 ;
if ( V_30 & V_33 )
V_32 -> V_37 ++ ;
if ( V_30 & V_34 )
V_32 -> V_38 ++ ;
if ( V_30 & V_36 )
V_32 -> V_39 ++ ;
if ( V_30 & V_35 )
V_32 -> V_40 ++ ;
F_17 ( & V_2 -> V_2 -> V_2 . V_41 ) ;
}
}
static void F_18 ( struct V_24 * V_2 , T_3 V_42 )
{
struct V_31 * V_32 ;
if ( V_42 & V_43 ) {
V_42 &= ( T_3 ) ( V_44 | V_43 ) ;
}
V_32 = & V_2 -> V_2 -> V_32 ;
if ( V_42 & V_43 )
V_32 -> V_45 ++ ;
if ( V_42 & V_44 )
V_32 -> V_46 ++ ;
if ( V_42 & V_47 )
V_32 -> V_48 ++ ;
if ( V_42 & V_49 )
V_32 -> V_50 ++ ;
}
static void F_19 ( struct V_51 * V_51 )
{
unsigned char * V_29 ;
struct V_24 * V_25 ;
struct V_52 * V_6 = & V_51 -> V_6 -> V_6 ;
T_3 V_53 = 0x0 ;
int V_54 = V_51 -> V_54 ;
V_25 = V_51 -> V_55 ;
switch ( V_54 ) {
case 0 :
break;
case - V_56 :
case - V_57 :
case - V_58 :
F_2 ( V_6 , L_7 , V_20 , V_54 ) ;
goto V_19;
default:
F_2 ( V_6 , L_8 , V_20 , V_54 ) ;
goto V_19;
}
F_2 ( V_6 , L_9 , V_20 , V_51 -> V_59 ) ;
F_2 ( V_6 , L_10 , V_20 ,
V_25 -> V_60 , V_25 -> V_61 ) ;
V_29 = V_51 -> V_62 ;
V_53 = ( T_3 ) V_29 [ 0 ] ;
F_2 ( V_6 , L_11 , V_20 , V_53 ) ;
if ( V_25 -> V_60 == 0 )
F_16 ( V_25 , V_53 ) ;
else if ( V_25 -> V_60 == 1 )
F_18 ( V_25 , V_53 ) ;
V_19:
F_20 ( V_63 , & V_25 -> V_64 ) ;
}
static int F_21 ( struct V_24 * V_65 , T_1 V_23 , T_1 V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_65 -> V_2 -> V_7 -> V_6 ;
struct V_66 * V_67 = V_65 -> V_67 ;
unsigned char * V_68 = V_65 -> V_69 ;
int V_11 ;
if ( F_22 ( V_63 , & V_65 -> V_64 ) )
return - V_70 ;
V_67 -> V_71 = V_17 ;
V_67 -> V_72 = V_16 ;
V_67 -> V_73 = F_23 ( V_23 ) ;
V_67 -> V_74 = F_23 ( V_3 ) ;
V_67 -> V_75 = F_23 ( 2 ) ;
F_24 ( V_65 -> V_76 , V_6 , F_7 ( V_6 , 0 ) ,
( unsigned char * ) V_67 , V_68 , 2 ,
F_19 , V_65 ) ;
V_65 -> V_76 -> V_77 = 2 ;
V_11 = F_25 ( V_65 -> V_76 , V_78 ) ;
if ( V_11 )
F_20 ( V_63 , & V_65 -> V_64 ) ;
return V_11 ;
}
static void F_26 ( struct V_51 * V_51 )
{
switch ( V_51 -> V_54 ) {
case 0 :
break;
case - V_56 :
case - V_57 :
case - V_58 :
F_2 ( & V_51 -> V_6 -> V_6 , L_12 ,
V_20 , V_51 -> V_54 ) ;
break;
default:
F_2 ( & V_51 -> V_6 -> V_6 , L_13 ,
V_20 , V_51 -> V_54 ) ;
}
}
static void F_27 ( struct V_24 * V_65 , T_1 V_79 ,
T_1 V_3 )
{
struct V_5 * V_6 = V_65 -> V_2 -> V_7 -> V_6 ;
struct V_66 * V_67 = V_65 -> V_80 ;
V_67 -> V_71 = V_9 ;
V_67 -> V_72 = V_8 ;
V_67 -> V_73 = F_23 ( V_79 ) ;
V_67 -> V_74 = F_23 ( V_3 ) ;
V_67 -> V_75 = F_23 ( 0 ) ;
F_24 ( V_65 -> V_81 , V_6 , F_4 ( V_6 , 0 ) ,
( unsigned char * ) V_67 , NULL , 0 , F_26 , NULL ) ;
F_25 ( V_65 -> V_81 , V_78 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
F_3 ( V_6 , F_4 ( V_6 , 0 ) , V_8 , V_9 ,
V_4 , V_3 , NULL , 0 , V_10 ) ;
}
static void F_29 ( unsigned long V_82 )
{
struct V_24 * V_65 = (struct V_24 * ) V_82 ;
F_27 ( V_65 , 0x0300 , V_83 ) ;
F_30 ( & V_65 -> V_84 ,
V_85 + F_31 ( V_86 ) ) ;
}
static void F_32 ( unsigned long V_82 )
{
struct V_24 * V_65 = (struct V_24 * ) V_82 ;
F_20 ( V_87 , & V_65 -> V_64 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_15 ( V_2 ) ;
if ( F_22 ( V_87 , & V_25 -> V_64 ) )
return;
F_27 ( V_25 , 0x0301 , V_83 ) ;
F_30 ( & V_25 -> V_88 ,
V_85 + F_31 ( V_89 ) ) ;
}
static void F_34 ( struct V_51 * V_51 )
{
int V_90 ;
int V_91 ;
struct V_24 * V_25 ;
struct V_92 * V_7 ;
T_1 V_93 ;
unsigned char * V_29 ;
T_3 V_94 [ 5 ] , V_95 ;
int V_96 , V_97 = 0 ;
T_1 V_79 , V_98 = 0 ;
int V_54 = V_51 -> V_54 ;
switch ( V_54 ) {
case 0 :
break;
case - V_56 :
case - V_57 :
case - V_58 :
F_2 ( & V_51 -> V_6 -> V_6 , L_7 ,
V_20 , V_54 ) ;
return;
default:
F_2 ( & V_51 -> V_6 -> V_6 , L_8 ,
V_20 , V_54 ) ;
goto exit;
}
V_91 = V_51 -> V_59 ;
V_29 = V_51 -> V_62 ;
V_7 = V_51 -> V_55 ;
if ( V_91 > 5 ) {
F_2 ( & V_51 -> V_6 -> V_6 , L_14 , L_15 ) ;
return;
}
V_94 [ 0 ] = ( T_3 ) V_29 [ 0 ] ;
V_94 [ 1 ] = ( T_3 ) V_29 [ 1 ] ;
V_94 [ 2 ] = ( T_3 ) V_29 [ 2 ] ;
V_94 [ 3 ] = ( T_3 ) V_29 [ 3 ] ;
V_95 = ( T_3 ) V_29 [ 4 ] ;
for ( V_96 = 0 ; V_96 < V_7 -> V_21 ; V_96 ++ ) {
V_25 = F_14 ( V_7 -> V_2 [ V_96 ] ) ;
V_79 = ( ( T_1 ) V_7 -> V_2 [ V_96 ] -> V_22 + 1 ) << 8 ;
if ( V_25 -> V_99 ) {
if ( V_94 [ V_96 ] & 0x01 ) {
F_2 ( & V_51 -> V_6 -> V_6 , L_16 , V_96 ) ;
} else {
switch ( V_94 [ V_96 ] & 0x0f ) {
case V_100 :
F_2 ( & V_51 -> V_6 -> V_6 , L_17 , V_96 ) ;
F_2 ( & V_51 -> V_6 -> V_6 , L_18 ) ;
V_25 -> V_60 = 1 ;
V_98 = V_101 ;
break;
case V_102 :
F_2 ( & V_51 -> V_6 -> V_6 , L_19 , V_96 ) ;
V_25 -> V_60 = 0 ;
V_98 = V_103 ;
break;
}
V_97 = F_21 ( V_25 , V_79 , V_98 , & V_93 ) ;
}
}
}
if ( ! ( V_97 < 0 ) )
return;
exit:
V_90 = F_25 ( V_51 , V_78 ) ;
if ( V_90 ) {
F_35 ( & V_51 -> V_6 -> V_6 ,
L_20 ,
V_20 , V_90 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_104 )
{
if ( ! V_2 ) {
F_37 ( L_21 , V_104 ) ;
return - 1 ;
}
if ( ! V_2 -> V_7 ) {
F_37 ( L_22 , V_104 ) ;
return - 1 ;
}
return 0 ;
}
static int F_38 ( struct V_92 * V_7 ,
const char * V_104 )
{
if ( ! V_7 ) {
F_37 ( L_23 , V_104 ) ;
return - 1 ;
}
if ( ! V_7 -> type ) {
F_37 ( L_24 , V_104 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_92 * F_39 ( struct V_1 * V_2 ,
const char * V_104 )
{
if ( ! V_2 ||
F_36 ( V_2 , V_104 ) ||
F_38 ( V_2 -> V_7 , V_104 ) ) {
return NULL ;
}
return V_2 -> V_7 ;
}
static void F_40 ( struct V_51 * V_51 )
{
int V_105 ;
unsigned char * V_29 ;
struct V_92 * V_7 ;
struct V_1 * V_2 ;
struct V_24 * V_25 ;
int V_54 = V_51 -> V_54 ;
V_25 = V_51 -> V_55 ;
if ( ! V_25 )
return;
if ( V_54 ) {
F_2 ( & V_51 -> V_6 -> V_6 , L_25 , V_54 ) ;
V_25 -> V_106 = false ;
return;
}
V_2 = V_25 -> V_2 ;
if ( F_36 ( V_2 , V_20 ) ) {
V_25 -> V_106 = false ;
return;
}
V_7 = F_39 ( V_2 , V_20 ) ;
if ( ! V_7 ) {
V_25 -> V_106 = false ;
return;
}
V_29 = V_51 -> V_62 ;
F_41 ( & V_2 -> V_6 , V_20 , V_51 -> V_59 , V_29 ) ;
if ( V_51 -> V_59 ) {
struct V_107 * V_108 = & V_25 -> V_2 -> V_2 ;
F_42 ( V_108 , V_29 , V_51 -> V_59 ) ;
F_43 ( V_108 ) ;
V_2 -> V_32 . V_109 += V_51 -> V_59 ;
F_2 ( & V_2 -> V_6 , L_26 , V_2 -> V_32 . V_109 ) ;
}
if ( ! V_25 -> V_110 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_27 ) ;
V_25 -> V_106 = false ;
return;
}
if ( V_25 -> V_111 )
F_33 ( V_2 ) ;
V_25 -> V_106 = true ;
V_105 = F_25 ( V_25 -> V_110 , V_78 ) ;
if ( V_105 ) {
F_2 ( & V_2 -> V_6 , L_28 , V_105 ) ;
V_25 -> V_106 = false ;
}
}
static void F_44 ( struct V_51 * V_51 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_54 = V_51 -> V_54 ;
int V_96 ;
V_25 = V_51 -> V_55 ;
V_2 = V_25 -> V_2 ;
F_45 ( & V_25 -> V_112 ) ;
for ( V_96 = 0 ; V_96 < V_113 ; V_96 ++ ) {
if ( V_51 == V_25 -> V_114 [ V_96 ] ) {
V_25 -> V_115 [ V_96 ] = 0 ;
break;
}
}
F_46 ( & V_25 -> V_112 ) ;
if ( V_54 ) {
F_2 ( & V_2 -> V_6 , L_29 , V_54 ) ;
return;
}
if ( F_36 ( V_2 , V_20 ) )
return;
if ( V_25 -> V_99 )
F_47 ( & V_2 -> V_2 ) ;
}
static int F_48 ( struct V_116 * V_117 , struct V_1 * V_2 )
{
int V_118 ;
int V_119 ;
struct V_92 * V_7 ;
struct V_51 * V_51 ;
T_1 V_93 ;
int V_54 ;
struct V_24 * V_25 ;
struct V_24 * V_120 ;
if ( F_36 ( V_2 , V_20 ) )
return - V_121 ;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_20 ) )
return - V_121 ;
V_25 = F_14 ( V_2 ) ;
V_120 = F_14 ( V_7 -> V_2 [ 0 ] ) ;
if ( V_25 == NULL || V_120 == NULL )
return - V_121 ;
F_49 ( V_7 -> V_6 , V_2 -> V_122 -> V_123 ) ;
F_49 ( V_7 -> V_6 , V_2 -> V_110 -> V_123 ) ;
V_120 -> V_124 ++ ;
for ( V_119 = 0 ; V_119 < V_113 ; ++ V_119 ) {
V_51 = F_50 ( 0 , V_14 ) ;
V_25 -> V_114 [ V_119 ] = V_51 ;
if ( ! V_51 )
continue;
V_51 -> V_62 = F_6 ( V_125 ,
V_14 ) ;
if ( ! V_51 -> V_62 ) {
F_51 ( V_51 ) ;
V_25 -> V_114 [ V_119 ] = NULL ;
continue;
}
}
V_93 = 0x0 ;
V_54 = F_5 ( V_2 , V_25 -> V_26 , & V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_30 ) ;
goto V_126;
}
V_93 |= 0x80 ;
V_54 = F_1 ( V_2 , V_25 -> V_26 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_31 ) ;
goto V_126;
}
V_93 &= ~ 0x80 ;
V_54 = F_1 ( V_2 , V_25 -> V_26 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_31 ) ;
goto V_126;
}
V_93 = 0x0 ;
V_54 = F_5 ( V_2 , V_25 -> V_27 ,
& V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_32 ) ;
goto V_126;
}
V_93 |= 0x08 ;
V_93 |= 0x20 ;
V_54 = F_1 ( V_2 ,
V_25 -> V_27 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_33 ) ;
goto V_126;
}
V_93 = 0x00 ;
V_54 = F_9 ( V_2 , V_127 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_34 ) ;
goto V_126;
}
V_93 = 0x00 ;
V_54 = F_9 ( V_2 , V_128 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_35 ) ;
goto V_126;
}
V_93 = 0xcf ;
V_54 = F_9 ( V_2 , V_128 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_35 ) ;
goto V_126;
}
V_93 = 0x03 ;
V_54 = F_9 ( V_2 , V_129 , V_93 ) ;
V_25 -> V_130 = V_93 ;
V_93 = 0x0b ;
V_54 = F_9 ( V_2 , V_83 , V_93 ) ;
V_25 -> V_131 = V_93 ;
V_93 = 0x00 ;
V_54 = F_10 ( V_2 , V_129 , & V_93 ) ;
V_25 -> V_130 = V_93 ;
V_93 |= V_132 ;
V_54 = F_9 ( V_2 , V_129 , V_93 ) ;
V_93 = 0x0c ;
V_54 = F_9 ( V_2 , V_133 , V_93 ) ;
V_93 = 0x0 ;
V_54 = F_9 ( V_2 , V_134 , V_93 ) ;
V_93 = 0x00 ;
V_54 = F_10 ( V_2 , V_129 , & V_93 ) ;
V_93 = V_93 & ~ V_132 ;
V_54 = F_9 ( V_2 , V_129 , V_93 ) ;
V_25 -> V_130 = V_93 ;
V_93 = 0x0 ;
V_54 = F_5 ( V_2 , V_25 -> V_26 , & V_93 ) ;
V_93 = V_93 | 0x0c ;
V_54 = F_1 ( V_2 , V_25 -> V_26 , V_93 ) ;
V_93 = V_93 & ~ 0x0c ;
V_54 = F_1 ( V_2 , V_25 -> V_26 , V_93 ) ;
V_93 = 0x0c ;
V_54 = F_9 ( V_2 , V_127 , V_93 ) ;
V_93 = 0x0 ;
V_54 = F_5 ( V_2 , V_25 -> V_27 ,
& V_93 ) ;
V_93 = V_93 & ~ 0x20 ;
V_54 = F_1 ( V_2 , V_25 -> V_27 ,
V_93 ) ;
V_93 = 0x0 ;
V_54 = F_5 ( V_2 , V_25 -> V_27 ,
& V_93 ) ;
V_93 = V_93 | 0x10 ;
V_54 = F_1 ( V_2 , V_25 -> V_27 ,
V_93 ) ;
if ( V_120 -> V_124 == 1 ) {
if ( V_7 -> V_2 [ 0 ] -> V_135 == NULL ) {
F_52 ( V_7 -> V_2 [ 0 ] -> V_136 ,
V_7 -> V_6 ,
F_53 ( V_7 -> V_6 ,
V_7 -> V_2 [ 0 ] -> V_137 ) ,
V_7 -> V_2 [ 0 ] -> V_135 ,
V_7 -> V_2 [ 0 ] -> V_136 ->
V_77 ,
F_34 ,
V_7 ,
V_7 -> V_2 [ 0 ] -> V_136 -> V_138 ) ;
V_118 =
F_25 ( V_7 -> V_2 [ 0 ] -> V_136 ,
V_14 ) ;
if ( V_118 ) {
F_35 ( & V_2 -> V_6 , L_36
L_37 , V_20 , V_118 ) ;
}
}
}
F_2 ( & V_2 -> V_6 , L_38 , V_2 -> V_22 ) ;
F_2 ( & V_2 -> V_6 , L_39 , V_2 -> V_139 ) ;
F_2 ( & V_2 -> V_6 , L_40 , V_2 -> V_140 ) ;
F_2 ( & V_2 -> V_6 , L_41 , V_2 -> V_141 ) ;
F_2 ( & V_2 -> V_6 , L_42 , V_2 -> V_137 ) ;
F_2 ( & V_2 -> V_6 , L_43 , V_25 -> V_61 ) ;
V_25 -> V_110 = V_2 -> V_110 ;
if ( ( V_7 -> V_21 == 2 ) && ( ( ( T_1 ) V_2 -> V_22 % 2 ) != 0 ) ) {
F_54 ( V_25 -> V_110 ,
V_7 -> V_6 ,
F_55 ( V_7 -> V_6 ,
( V_2 -> V_140 ) + 2 ) ,
V_2 -> V_142 ,
V_25 -> V_110 -> V_77 ,
F_40 , V_25 ) ;
} else {
F_54 ( V_25 -> V_110 ,
V_7 -> V_6 ,
F_55 ( V_7 -> V_6 ,
V_2 -> V_140 ) ,
V_2 -> V_142 ,
V_25 -> V_110 -> V_77 ,
F_40 , V_25 ) ;
}
F_2 ( & V_2 -> V_6 , L_44 , V_20 , V_2 -> V_140 ) ;
V_25 -> V_106 = true ;
V_118 = F_25 ( V_25 -> V_110 , V_14 ) ;
if ( V_118 ) {
F_35 ( & V_2 -> V_6 , L_45 ,
V_20 , V_118 ) ;
V_25 -> V_106 = false ;
}
V_25 -> V_131 = V_143 ;
V_25 -> V_99 = 1 ;
return 0 ;
V_126:
for ( V_119 = 0 ; V_119 < V_113 ; ++ V_119 ) {
V_51 = V_25 -> V_114 [ V_119 ] ;
if ( ! V_51 )
continue;
F_8 ( V_51 -> V_62 ) ;
F_51 ( V_51 ) ;
}
return V_54 ;
}
static int F_56 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
int V_96 ;
int V_145 = 0 ;
unsigned long V_64 ;
struct V_24 * V_25 ;
if ( F_36 ( V_2 , V_20 ) )
return 0 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return 0 ;
F_57 ( & V_25 -> V_112 , V_64 ) ;
for ( V_96 = 0 ; V_96 < V_113 ; ++ V_96 ) {
if ( V_25 -> V_115 [ V_96 ] ) {
struct V_51 * V_51 = V_25 -> V_114 [ V_96 ] ;
V_145 += V_51 -> V_77 ;
}
}
F_58 ( & V_25 -> V_112 , V_64 ) ;
F_2 ( & V_2 -> V_6 , L_46 , V_20 , V_145 ) ;
return V_145 ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_92 * V_7 ;
struct V_24 * V_25 ;
struct V_24 * V_120 ;
int V_119 ;
T_1 V_93 ;
if ( F_36 ( V_2 , V_20 ) )
return;
V_7 = F_39 ( V_2 , V_20 ) ;
if ( ! V_7 )
return;
V_25 = F_14 ( V_2 ) ;
V_120 = F_14 ( V_7 -> V_2 [ 0 ] ) ;
if ( V_25 == NULL || V_120 == NULL )
return;
for ( V_119 = 0 ; V_119 < V_113 ; ++ V_119 )
F_60 ( V_25 -> V_114 [ V_119 ] ) ;
for ( V_119 = 0 ; V_119 < V_113 ; ++ V_119 ) {
if ( V_25 -> V_114 [ V_119 ] ) {
F_8 ( V_25 -> V_114 [ V_119 ] -> V_62 ) ;
F_51 ( V_25 -> V_114 [ V_119 ] ) ;
}
}
F_60 ( V_25 -> V_110 ) ;
V_25 -> V_106 = false ;
V_120 -> V_124 -- ;
F_2 ( & V_2 -> V_6 , L_47 , V_20 , V_120 -> V_124 ) ;
if ( V_120 -> V_124 == 0 ) {
if ( V_7 -> V_2 [ 0 ] -> V_136 ) {
F_2 ( & V_2 -> V_6 , L_48 ) ;
F_60 ( V_7 -> V_2 [ 0 ] -> V_136 ) ;
}
}
V_93 = 0x0 ;
F_9 ( V_2 , V_83 , V_93 ) ;
V_93 = 0x00 ;
F_9 ( V_2 , V_127 , V_93 ) ;
V_25 -> V_99 = 0 ;
}
static void F_61 ( struct V_116 * V_117 , int V_146 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
unsigned char V_29 ;
struct V_92 * V_7 ;
struct V_24 * V_25 ;
if ( F_36 ( V_2 , V_20 ) )
return;
V_7 = F_39 ( V_2 , V_20 ) ;
if ( ! V_7 )
return;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return;
if ( V_146 == - 1 )
V_29 = V_25 -> V_130 | V_147 ;
else
V_29 = V_25 -> V_130 & ~ V_147 ;
V_25 -> V_130 = V_29 ;
F_2 ( & V_2 -> V_6 , L_49 , V_20 , V_25 -> V_130 ) ;
F_9 ( V_2 , V_129 ,
V_25 -> V_130 ) ;
}
static int F_62 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
int V_96 ;
int V_148 = 0 ;
unsigned long V_64 ;
struct V_24 * V_25 ;
if ( F_36 ( V_2 , V_20 ) )
return - 1 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return - 1 ;
F_57 ( & V_25 -> V_112 , V_64 ) ;
for ( V_96 = 0 ; V_96 < V_113 ; ++ V_96 ) {
if ( ! V_25 -> V_115 [ V_96 ] )
V_148 += V_125 ;
}
F_58 ( & V_25 -> V_112 , V_64 ) ;
V_148 = ( V_148 == 0 ) ? 0 : V_148 - V_125 + 1 ;
F_2 ( & V_25 -> V_2 -> V_6 , L_46 , V_20 , V_148 ) ;
return V_148 ;
}
static int F_63 ( struct V_116 * V_117 , struct V_1 * V_2 ,
const unsigned char * V_29 , int V_149 )
{
int V_54 ;
int V_96 ;
int V_150 = 0 ;
int V_151 ;
unsigned long V_64 ;
struct V_24 * V_25 ;
struct V_92 * V_7 ;
struct V_51 * V_51 ;
const unsigned char * V_152 = V_29 ;
unsigned char * V_153 ;
if ( F_36 ( V_2 , V_20 ) )
return - 1 ;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_20 ) )
return - 1 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return - 1 ;
V_51 = NULL ;
F_57 ( & V_25 -> V_112 , V_64 ) ;
for ( V_96 = 0 ; V_96 < V_113 ; ++ V_96 ) {
if ( ! V_25 -> V_115 [ V_96 ] ) {
V_25 -> V_115 [ V_96 ] = 1 ;
V_51 = V_25 -> V_114 [ V_96 ] ;
F_2 ( & V_2 -> V_6 , L_50 , V_96 ) ;
break;
}
}
F_58 ( & V_25 -> V_112 , V_64 ) ;
if ( V_51 == NULL ) {
F_2 ( & V_2 -> V_6 , L_51 , V_20 ) ;
goto exit;
}
if ( V_51 -> V_62 == NULL ) {
V_51 -> V_62 = F_6 ( V_125 ,
V_78 ) ;
if ( ! V_51 -> V_62 )
goto exit;
}
V_151 = F_64 ( V_149 , V_125 ) ;
memcpy ( V_51 -> V_62 , V_152 , V_151 ) ;
if ( ( V_7 -> V_21 == 2 ) && ( ( ( T_1 ) V_2 -> V_22 % 2 ) != 0 ) ) {
F_54 ( V_51 ,
V_7 -> V_6 ,
F_65 ( V_7 -> V_6 ,
( V_2 -> V_141 ) + 2 ) ,
V_51 -> V_62 ,
V_151 ,
F_44 , V_25 ) ;
} else {
F_54 ( V_51 ,
V_7 -> V_6 ,
F_65 ( V_7 -> V_6 ,
V_2 -> V_141 ) ,
V_51 -> V_62 ,
V_151 ,
F_44 , V_25 ) ;
}
V_153 = V_51 -> V_62 ;
F_2 ( & V_2 -> V_6 , L_52 , V_2 -> V_141 ) ;
if ( V_25 -> V_111 )
F_33 ( V_2 ) ;
V_54 = F_25 ( V_51 , V_78 ) ;
if ( V_54 ) {
V_25 -> V_115 [ V_96 ] = 0 ;
F_66 ( V_2 , L_53
L_54 , V_20 , V_54 ) ;
V_150 = V_54 ;
goto exit;
}
V_150 = V_151 ;
V_2 -> V_32 . V_154 += V_151 ;
F_2 ( & V_2 -> V_6 , L_55 , V_2 -> V_32 . V_154 ) ;
exit:
return V_150 ;
}
static void F_67 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
struct V_24 * V_25 ;
int V_54 ;
if ( F_36 ( V_2 , V_20 ) )
return;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return;
if ( ! V_25 -> V_99 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_56 ) ;
return;
}
if ( F_68 ( V_117 ) ) {
unsigned char V_155 = F_69 ( V_117 ) ;
V_54 = F_63 ( V_117 , V_2 , & V_155 , 1 ) ;
if ( V_54 <= 0 )
return;
}
if ( F_70 ( V_117 ) ) {
V_25 -> V_131 &= ~ V_156 ;
V_54 = F_9 ( V_2 , V_83 ,
V_25 -> V_131 ) ;
if ( V_54 < 0 )
return;
}
}
static void F_71 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
int V_54 ;
struct V_24 * V_25 = F_14 ( V_2 ) ;
if ( F_36 ( V_2 , V_20 ) )
return;
if ( V_25 == NULL )
return;
if ( ! V_25 -> V_99 ) {
F_2 ( & V_2 -> V_6 , L_57 , V_20 ) ;
return;
}
if ( F_68 ( V_117 ) ) {
unsigned char V_157 = F_72 ( V_117 ) ;
V_54 = F_63 ( V_117 , V_2 , & V_157 , 1 ) ;
if ( V_54 <= 0 )
return;
}
if ( F_70 ( V_117 ) ) {
V_25 -> V_131 |= V_156 ;
V_54 = F_9 ( V_2 , V_83 ,
V_25 -> V_131 ) ;
if ( V_54 < 0 )
return;
}
}
static int F_73 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
struct V_24 * V_25 ;
unsigned int V_90 ;
T_1 V_158 ;
T_1 V_159 ;
int V_54 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return - V_121 ;
V_54 = F_10 ( V_2 , V_103 , & V_158 ) ;
if ( V_54 < 0 )
return - V_18 ;
V_54 = F_10 ( V_2 , V_83 , & V_159 ) ;
if ( V_54 < 0 )
return - V_18 ;
V_90 = ( ( V_159 & V_160 ) ? V_161 : 0 )
| ( ( V_159 & V_156 ) ? V_162 : 0 )
| ( ( V_159 & V_163 ) ? V_164 : 0 )
| ( ( V_158 & V_165 ) ? V_166 : 0 )
| ( ( V_158 & V_167 ) ? V_168 : 0 )
| ( ( V_158 & V_169 ) ? V_170 : 0 )
| ( ( V_158 & V_171 ) ? V_172 : 0 ) ;
F_2 ( & V_2 -> V_6 , L_58 , V_20 , V_90 ) ;
return V_90 ;
}
static int F_74 ( struct V_116 * V_117 ,
unsigned int V_173 , unsigned int V_174 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
struct V_24 * V_25 ;
unsigned int V_159 ;
int V_54 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return - V_121 ;
V_159 = V_25 -> V_131 ;
if ( V_174 & V_162 )
V_159 &= ~ V_156 ;
if ( V_174 & V_161 )
V_159 &= ~ V_160 ;
if ( V_174 & V_164 )
V_159 &= ~ V_163 ;
if ( V_173 & V_162 )
V_159 |= V_156 ;
if ( V_173 & V_161 )
V_159 |= V_160 ;
if ( V_173 & V_164 )
V_159 |= V_163 ;
V_25 -> V_131 = V_159 ;
V_54 = F_9 ( V_2 , V_83 , V_159 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_59 ) ;
return V_54 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
int V_175 , int * V_176 ,
T_1 * V_177 )
{
F_2 ( & V_2 -> V_6 , L_60 , V_20 , V_175 ) ;
if ( V_175 <= 115200 ) {
* V_176 = 115200 / V_175 ;
* V_177 = 0x0 ;
}
if ( ( V_175 > 115200 ) && ( V_175 <= 230400 ) ) {
* V_176 = 230400 / V_175 ;
* V_177 = 0x10 ;
} else if ( ( V_175 > 230400 ) && ( V_175 <= 403200 ) ) {
* V_176 = 403200 / V_175 ;
* V_177 = 0x20 ;
} else if ( ( V_175 > 403200 ) && ( V_175 <= 460800 ) ) {
* V_176 = 460800 / V_175 ;
* V_177 = 0x30 ;
} else if ( ( V_175 > 460800 ) && ( V_175 <= 806400 ) ) {
* V_176 = 806400 / V_175 ;
* V_177 = 0x40 ;
} else if ( ( V_175 > 806400 ) && ( V_175 <= 921600 ) ) {
* V_176 = 921600 / V_175 ;
* V_177 = 0x50 ;
} else if ( ( V_175 > 921600 ) && ( V_175 <= 1572864 ) ) {
* V_176 = 1572864 / V_175 ;
* V_177 = 0x60 ;
} else if ( ( V_175 > 1572864 ) && ( V_175 <= 3145728 ) ) {
* V_176 = 3145728 / V_175 ;
* V_177 = 0x70 ;
}
return 0 ;
}
static int F_76 ( struct V_24 * V_25 ,
int V_175 )
{
int V_176 = 0 ;
int V_54 ;
T_1 V_93 ;
unsigned char V_178 ;
T_1 V_177 ;
struct V_1 * V_2 ;
if ( V_25 == NULL )
return - 1 ;
V_2 = V_25 -> V_2 ;
if ( F_36 ( V_2 , V_20 ) )
return - 1 ;
if ( F_38 ( V_2 -> V_7 , V_20 ) )
return - 1 ;
V_178 = V_25 -> V_2 -> V_22 ;
F_2 ( & V_2 -> V_6 , L_61 , V_20 , V_175 ) ;
if ( V_175 > 115200 ) {
#ifdef F_77
V_93 = 0x2b ;
V_25 -> V_131 = V_93 ;
V_54 = F_9 ( V_2 , V_83 ,
V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_62 ) ;
return - 1 ;
}
#endif
} else {
#ifdef F_77
V_93 = 0xb ;
V_25 -> V_131 = V_93 ;
V_54 = F_9 ( V_2 , V_83 ,
V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_62 ) ;
return - 1 ;
}
#endif
}
if ( 1 ) {
V_177 = 0x0 ;
V_93 = 0x0 ;
V_54 = F_75 ( V_2 , V_175 , & V_176 ,
& V_177 ) ;
V_54 = F_5 ( V_2 , V_25 -> V_26 ,
& V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_63 ) ;
return - 1 ;
}
V_93 = ( V_93 & 0x8f ) | V_177 ;
V_54 = F_1 ( V_2 , V_25 -> V_26 ,
V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_62 ) ;
return - 1 ;
}
if ( V_54 ) {
F_35 ( & V_2 -> V_6 , L_64 , V_20 ) ;
return V_54 ;
}
V_93 = V_25 -> V_130 | V_132 ;
V_25 -> V_130 = V_93 ;
F_9 ( V_2 , V_129 , V_93 ) ;
V_93 = ( unsigned char ) ( V_176 & 0xff ) ;
F_2 ( & V_2 -> V_6 , L_65 , V_93 ) ;
F_9 ( V_2 , V_133 , V_93 ) ;
V_93 = ( unsigned char ) ( ( V_176 & 0xff00 ) >> 8 ) ;
F_2 ( & V_2 -> V_6 , L_66 , V_93 ) ;
F_9 ( V_2 , V_134 , V_93 ) ;
V_93 = V_25 -> V_130 & ~ V_132 ;
V_25 -> V_130 = V_93 ;
F_9 ( V_2 , V_129 , V_93 ) ;
}
return V_54 ;
}
static void F_78 ( struct V_116 * V_117 ,
struct V_24 * V_25 , struct V_179 * V_180 )
{
int V_181 ;
unsigned V_182 ;
unsigned V_183 ;
T_3 V_184 ;
T_3 V_185 ;
T_3 V_186 ;
int V_54 ;
T_1 V_93 ;
struct V_1 * V_2 ;
struct V_92 * V_7 ;
if ( V_25 == NULL )
return;
V_2 = V_25 -> V_2 ;
if ( F_36 ( V_2 , V_20 ) )
return;
if ( F_38 ( V_2 -> V_7 , V_20 ) )
return;
V_7 = V_2 -> V_7 ;
if ( ! V_25 -> V_99 ) {
F_2 ( & V_2 -> V_6 , L_57 , V_20 ) ;
return;
}
V_184 = V_187 ;
V_186 = V_188 ;
V_185 = V_189 ;
V_182 = V_117 -> V_190 . V_191 ;
V_183 = V_117 -> V_190 . V_192 ;
switch ( V_182 & V_193 ) {
case V_194 :
V_184 = V_195 ;
break;
case V_196 :
V_184 = V_197 ;
break;
case V_198 :
V_184 = V_199 ;
break;
default:
case V_200 :
V_184 = V_187 ;
break;
}
if ( V_182 & V_201 ) {
if ( V_182 & V_202 ) {
V_185 = V_203 ;
F_2 ( & V_2 -> V_6 , L_67 , V_20 ) ;
} else {
V_185 = V_204 ;
F_2 ( & V_2 -> V_6 , L_68 , V_20 ) ;
}
} else {
F_2 ( & V_2 -> V_6 , L_69 , V_20 ) ;
}
if ( V_182 & V_205 )
V_185 = V_185 | 0x20 ;
if ( V_182 & V_206 ) {
V_186 = V_207 ;
F_2 ( & V_2 -> V_6 , L_70 , V_20 ) ;
} else {
V_186 = V_188 ;
F_2 ( & V_2 -> V_6 , L_71 , V_20 ) ;
}
V_25 -> V_130 &=
~ ( V_208 | V_209 | V_210 ) ;
V_25 -> V_130 |= ( V_184 | V_185 | V_186 ) ;
F_2 ( & V_2 -> V_6 , L_72 , V_20 ,
V_25 -> V_130 ) ;
V_93 = 0x00 ;
F_9 ( V_2 , V_127 , V_93 ) ;
V_93 = 0x00 ;
F_9 ( V_2 , V_128 , V_93 ) ;
V_93 = 0xcf ;
F_9 ( V_2 , V_128 , V_93 ) ;
V_93 = V_25 -> V_130 ;
F_9 ( V_2 , V_129 , V_93 ) ;
V_93 = 0x00b ;
V_25 -> V_131 = V_93 ;
F_9 ( V_2 , V_83 , V_93 ) ;
V_93 = 0x00b ;
F_9 ( V_2 , V_83 , V_93 ) ;
V_25 -> V_131 = V_143 ;
if ( V_182 & V_211 )
V_25 -> V_131 |= ( V_160 | V_156 ) ;
if ( V_182 & V_212 )
V_25 -> V_131 |= ( V_213 ) ;
else
V_25 -> V_131 &= ~ ( V_213 ) ;
V_93 = V_25 -> V_131 ;
F_9 ( V_2 , V_83 , V_93 ) ;
V_181 = F_79 ( V_117 ) ;
if ( ! V_181 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_73 ) ;
V_181 = 9600 ;
}
F_2 ( & V_2 -> V_6 , L_74 , V_20 , V_181 ) ;
V_54 = F_76 ( V_25 , V_181 ) ;
V_93 = 0x0c ;
F_9 ( V_2 , V_127 , V_93 ) ;
if ( ! V_25 -> V_106 ) {
V_25 -> V_106 = true ;
V_54 = F_25 ( V_25 -> V_110 , V_14 ) ;
if ( V_54 ) {
F_2 ( & V_2 -> V_6 , L_75 ,
V_54 ) ;
V_25 -> V_106 = false ;
}
}
F_2 ( & V_2 -> V_6 , L_76 , V_20 ,
V_25 -> V_130 ) ;
}
static void F_80 ( struct V_116 * V_117 ,
struct V_1 * V_2 ,
struct V_179 * V_180 )
{
int V_54 ;
struct V_92 * V_7 ;
struct V_24 * V_25 ;
if ( F_36 ( V_2 , V_20 ) )
return;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_20 ) )
return;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return;
if ( ! V_25 -> V_99 ) {
F_2 ( & V_2 -> V_6 , L_57 , V_20 ) ;
return;
}
F_78 ( V_117 , V_25 , V_180 ) ;
if ( ! V_25 -> V_110 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_77 ) ;
return;
}
if ( ! V_25 -> V_106 ) {
V_25 -> V_106 = true ;
V_54 = F_25 ( V_25 -> V_110 , V_14 ) ;
if ( V_54 ) {
F_2 ( & V_2 -> V_6 , L_75 ,
V_54 ) ;
V_25 -> V_106 = false ;
}
}
}
static int F_81 ( struct V_116 * V_117 ,
unsigned int T_4 * V_214 )
{
int V_149 ;
unsigned int V_90 = 0 ;
V_149 = F_56 ( V_117 ) ;
if ( V_149 == 0 )
V_90 = V_215 ;
if ( F_82 ( V_214 , & V_90 , sizeof( int ) ) )
return - V_216 ;
return 0 ;
}
static int F_83 ( struct V_24 * V_25 ,
struct V_217 T_4 * V_218 )
{
struct V_217 V_219 ;
if ( V_25 == NULL )
return - 1 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
V_219 . type = V_220 ;
V_219 . line = V_25 -> V_2 -> V_139 ;
V_219 . V_2 = V_25 -> V_2 -> V_22 ;
V_219 . V_221 = 0 ;
V_219 . V_222 = V_113 * V_125 ;
V_219 . V_223 = 9600 ;
V_219 . V_224 = 5 * V_225 ;
V_219 . V_226 = 30 * V_225 ;
if ( F_82 ( V_218 , & V_219 , sizeof( * V_218 ) ) )
return - V_216 ;
return 0 ;
}
static int F_84 ( struct V_116 * V_117 ,
unsigned int V_227 , unsigned long V_82 )
{
struct V_1 * V_2 = V_117 -> V_144 ;
void T_4 * V_228 = ( void T_4 * ) V_82 ;
struct V_24 * V_25 ;
if ( F_36 ( V_2 , V_20 ) )
return - 1 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 == NULL )
return - 1 ;
switch ( V_227 ) {
case V_229 :
F_2 ( & V_2 -> V_6 , L_78 , V_20 ) ;
return F_81 ( V_117 , V_228 ) ;
case V_230 :
F_2 ( & V_2 -> V_6 , L_79 , V_20 ) ;
return F_83 ( V_25 , V_228 ) ;
case V_231 :
F_2 ( & V_2 -> V_6 , L_80 , V_20 ) ;
break;
default:
break;
}
return - V_232 ;
}
static int F_85 ( struct V_92 * V_7 )
{
int V_96 , V_233 = 0 ;
T_2 * V_12 ;
T_1 V_29 = 0 , V_234 = 0 ;
T_1 V_235 = 0x55AA ;
int V_236 ;
V_12 = F_6 ( V_13 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_236 = F_3 ( V_7 -> V_6 , F_7 ( V_7 -> V_6 , 0 ) ,
V_16 , V_17 , 0x0300 , V_83 ,
V_12 , V_13 , V_10 ) ;
if ( V_236 == V_13 )
V_234 = * V_12 ;
for ( V_96 = 0 ; V_96 < 16 ; V_96 ++ ) {
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) ,
V_8 , V_9 ,
( 0x0300 | ( ( ( V_235 >> V_96 ) & 0x0001 ) << 1 ) ) ,
V_83 , NULL , 0 , V_10 ) ;
V_236 = F_3 ( V_7 -> V_6 ,
F_7 ( V_7 -> V_6 , 0 ) , V_16 ,
V_17 , 0 , V_237 , V_12 ,
V_13 , V_10 ) ;
if ( V_236 == V_13 )
V_29 = * V_12 ;
if ( ( ( V_235 >> V_96 ) ^ ( ~ V_29 >> 1 ) ) & 0x0001 )
break;
V_233 ++ ;
}
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) , V_8 ,
V_9 , 0x0300 | V_234 , V_83 , NULL ,
0 , V_10 ) ;
F_8 ( V_12 ) ;
if ( V_233 == 16 )
return 1 ;
return 0 ;
}
static int F_86 ( struct V_92 * V_7 ,
const struct V_238 * V_239 )
{
T_5 V_240 = F_87 ( V_7 -> V_6 -> V_241 . V_242 ) ;
T_2 * V_12 ;
int V_243 ;
if ( V_240 == V_244 ||
V_240 == V_245 ) {
V_243 = V_240 ;
goto V_19;
}
V_12 = F_88 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
F_3 ( V_7 -> V_6 , F_7 ( V_7 -> V_6 , 0 ) ,
V_16 , V_17 , 0 , V_237 , V_12 ,
V_13 , V_10 ) ;
if ( V_12 [ 0 ] & 0x01 )
V_243 = V_246 ;
else if ( F_85 ( V_7 ) )
V_243 = V_244 ;
else
V_243 = V_245 ;
F_8 ( V_12 ) ;
V_19:
F_89 ( V_7 , ( void * ) ( unsigned long ) V_243 ) ;
return 0 ;
}
static int F_90 ( struct V_92 * V_7 ,
struct V_247 * V_248 )
{
int V_243 = ( unsigned long ) F_91 ( V_7 ) ;
int V_21 ;
V_21 = ( V_243 >> 4 ) & 0x000F ;
if ( V_21 == 0 )
return - V_121 ;
if ( V_248 -> V_249 < V_21 || V_248 -> V_250 < V_21 ) {
F_35 ( & V_7 -> V_251 -> V_6 , L_81 ) ;
return - V_121 ;
}
return V_21 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_92 * V_7 = V_2 -> V_7 ;
int V_243 = ( unsigned long ) F_91 ( V_7 ) ;
struct V_24 * V_25 ;
int V_54 ;
int V_252 ;
T_1 V_93 ;
V_252 = V_2 -> V_22 ;
F_2 ( & V_2 -> V_6 , L_82 , V_252 ) ;
V_25 = F_88 ( sizeof( struct V_24 ) , V_14 ) ;
if ( ! V_25 )
return - V_15 ;
V_25 -> V_2 = V_2 ;
F_12 ( V_2 , V_25 ) ;
F_93 ( & V_25 -> V_112 ) ;
V_25 -> V_61 = V_252 + 1 ;
F_2 ( & V_2 -> V_6 , L_83 , V_2 -> V_139 ) ;
F_2 ( & V_2 -> V_6 , L_84 , V_25 -> V_61 ) ;
if ( V_25 -> V_61 == 1 ) {
V_25 -> V_26 = 0x0 ;
V_25 -> V_27 = 0x1 ;
V_25 -> V_28 = 0x4 ;
} else if ( ( V_25 -> V_61 == 2 ) && ( V_7 -> V_21 == 4 ) ) {
V_25 -> V_26 = 0x8 ;
V_25 -> V_27 = 0x9 ;
V_25 -> V_28 = 0x16 ;
} else if ( ( V_25 -> V_61 == 2 ) && ( V_7 -> V_21 == 2 ) ) {
V_25 -> V_26 = 0xa ;
V_25 -> V_27 = 0xb ;
V_25 -> V_28 = 0x19 ;
} else if ( ( V_25 -> V_61 == 3 ) && ( V_7 -> V_21 == 4 ) ) {
V_25 -> V_26 = 0xa ;
V_25 -> V_27 = 0xb ;
V_25 -> V_28 = 0x19 ;
} else if ( ( V_25 -> V_61 == 4 ) && ( V_7 -> V_21 == 4 ) ) {
V_25 -> V_26 = 0xc ;
V_25 -> V_27 = 0xd ;
V_25 -> V_28 = 0x1c ;
}
F_11 ( V_2 , V_25 ) ;
F_12 ( V_2 , V_25 ) ;
V_54 = F_5 ( V_2 ,
V_25 -> V_27 , & V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_85 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_86 , V_93 , V_54 ) ;
V_93 |= 0x08 ;
V_93 |= 0x04 ;
V_54 = F_1 ( V_2 ,
V_25 -> V_27 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_87 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_88 , V_54 ) ;
V_93 = 0x01 ;
V_54 = F_1 ( V_2 ,
( T_1 ) ( V_25 -> V_28 + 0 ) , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_89 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_90 , V_54 ) ;
V_93 = 0x05 ;
V_54 = F_1 ( V_2 ,
( T_1 ) ( V_25 -> V_28 + 1 ) , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_91 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_92 , V_54 ) ;
V_93 = 0x24 ;
V_54 = F_1 ( V_2 ,
( T_1 ) ( V_25 -> V_28 + 2 ) , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_93 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_94 , V_54 ) ;
V_93 = 0x0 ;
V_54 = F_1 ( V_2 , V_253 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_95 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_96 , V_54 ) ;
V_93 = 0x20 ;
V_54 = F_1 ( V_2 , V_254 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_97 , V_54 ) ;
goto error;
} else
F_2 ( & V_2 -> V_6 , L_98 , V_54 ) ;
V_93 = 0x00 ;
V_54 = F_9 ( V_2 , V_255 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_99 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_100 , V_54 ) ;
if ( ( V_25 -> V_61 != 1 ) && ( V_7 -> V_21 == 2 ) ) {
V_93 = 0xff ;
V_54 = F_1 ( V_2 ,
( T_1 ) ( V_256 +
( ( T_1 ) V_25 -> V_61 ) ) , V_93 ) ;
F_2 ( & V_2 -> V_6 , L_101 ,
( T_1 ) ( V_256 + ( ( T_1 ) V_25 -> V_61 ) ) ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_102 , V_252 + 2 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_103 , V_252 + 2 , V_54 ) ;
} else {
V_93 = 0xff ;
V_54 = F_1 ( V_2 ,
( T_1 ) ( V_256 +
( ( T_1 ) V_25 -> V_61 ) - 0x1 ) , V_93 ) ;
F_2 ( & V_2 -> V_6 , L_101 ,
( T_1 ) ( V_256 + ( ( T_1 ) V_25 -> V_61 ) - 0x1 ) ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_102 , V_252 + 1 , V_54 ) ;
goto V_19;
} else
F_2 ( & V_2 -> V_6 , L_103 , V_252 + 1 , V_54 ) ;
}
V_25 -> V_76 = F_50 ( 0 , V_14 ) ;
V_25 -> V_69 = F_6 ( 16 , V_14 ) ;
V_25 -> V_67 = F_6 ( sizeof( struct V_66 ) ,
V_14 ) ;
if ( ! V_25 -> V_76 || ! V_25 -> V_69 ||
! V_25 -> V_67 ) {
V_54 = - V_15 ;
goto error;
}
V_25 -> V_111 = false ;
if ( V_243 == V_244 ) {
V_25 -> V_111 = true ;
V_25 -> V_81 = F_50 ( 0 , V_14 ) ;
V_25 -> V_80 = F_6 ( sizeof( * V_25 -> V_80 ) ,
V_14 ) ;
if ( ! V_25 -> V_81 || ! V_25 -> V_80 ) {
V_54 = - V_15 ;
goto error;
}
F_94 ( & V_25 -> V_88 , F_29 ,
( unsigned long ) V_25 ) ;
V_25 -> V_88 . V_257 =
V_85 + F_31 ( V_89 ) ;
F_94 ( & V_25 -> V_84 , F_32 ,
( unsigned long ) V_25 ) ;
V_25 -> V_84 . V_257 =
V_85 + F_31 ( V_86 ) ;
F_28 ( V_2 , V_83 , 0x0300 ) ;
}
V_19:
if ( V_252 == V_7 -> V_21 - 1 ) {
V_93 = 0x0f ;
V_54 = F_1 ( V_7 -> V_2 [ 0 ] , V_258 , V_93 ) ;
if ( V_54 < 0 ) {
F_2 ( & V_2 -> V_6 , L_104 , V_54 ) ;
goto error;
} else
F_2 ( & V_2 -> V_6 , L_105 , V_54 ) ;
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) ,
0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 ,
V_10 ) ;
}
return 0 ;
error:
F_8 ( V_25 -> V_80 ) ;
F_51 ( V_25 -> V_81 ) ;
F_8 ( V_25 -> V_67 ) ;
F_8 ( V_25 -> V_69 ) ;
F_51 ( V_25 -> V_76 ) ;
F_8 ( V_25 ) ;
return V_54 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
V_25 = F_14 ( V_2 ) ;
if ( V_25 -> V_111 ) {
F_28 ( V_2 , V_83 , 0x0300 ) ;
F_96 ( & V_25 -> V_88 ) ;
F_96 ( & V_25 -> V_84 ) ;
F_60 ( V_25 -> V_81 ) ;
F_51 ( V_25 -> V_81 ) ;
F_8 ( V_25 -> V_80 ) ;
}
F_60 ( V_25 -> V_76 ) ;
F_51 ( V_25 -> V_76 ) ;
F_8 ( V_25 -> V_69 ) ;
F_8 ( V_25 -> V_67 ) ;
F_8 ( V_25 ) ;
return 0 ;
}
