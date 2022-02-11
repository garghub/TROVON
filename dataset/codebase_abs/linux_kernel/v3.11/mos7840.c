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
* V_4 = V_12 [ 0 ] ;
F_2 ( & V_2 -> V_6 , L_2 , V_18 , V_3 , * V_4 ) ;
F_8 ( V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_4 = V_4 & 0x00ff ;
if ( V_2 -> V_7 -> V_19 == 4 ) {
V_4 |= ( ( T_1 ) V_2 -> V_20 + 1 ) << 8 ;
} else {
if ( V_2 -> V_20 == 0 ) {
V_4 |= ( ( T_1 ) V_2 -> V_20 + 1 ) << 8 ;
} else {
V_4 |= ( ( T_1 ) V_2 -> V_20 + 2 ) << 8 ;
}
}
F_2 ( & V_2 -> V_6 , L_3 , V_18 , V_4 ) ;
return F_3 ( V_6 , F_4 ( V_6 , 0 ) , V_8 ,
V_9 , V_4 , V_3 , NULL , 0 ,
V_10 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_11 = 0 ;
T_1 V_21 ;
T_2 * V_12 ;
V_12 = F_6 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
if ( V_2 -> V_7 -> V_19 == 4 ) {
V_21 = ( ( T_1 ) V_2 -> V_20 + 1 ) << 8 ;
} else {
if ( V_2 -> V_20 == 0 ) {
V_21 = ( ( T_1 ) V_2 -> V_20 + 1 ) << 8 ;
} else {
V_21 = ( ( T_1 ) V_2 -> V_20 + 2 ) << 8 ;
}
}
F_2 ( & V_2 -> V_6 , L_3 , V_18 , V_21 ) ;
V_11 = F_3 ( V_6 , F_7 ( V_6 , 0 ) , V_16 ,
V_17 , V_21 , V_3 , V_12 , V_13 ,
V_10 ) ;
* V_4 = V_12 [ 0 ] ;
F_8 ( V_12 ) ;
return V_11 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
F_2 ( & V_2 -> V_6 , L_4 , V_23 -> V_24 ) ;
F_2 ( & V_2 -> V_6 , L_5 , V_23 -> V_25 ) ;
F_2 ( & V_2 -> V_6 , L_6 , V_23 -> V_26 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_22 * V_27 )
{
F_13 ( V_2 , ( void * ) V_27 ) ;
}
static inline struct V_22 * F_14 ( struct
V_1
* V_2 )
{
return (struct V_22 * ) F_15 ( V_2 ) ;
}
static void F_16 ( struct V_22 * V_2 , T_3 V_28 )
{
struct V_22 * V_23 ;
struct V_29 * V_30 ;
V_23 = V_2 ;
if ( V_28 &
( V_31 | V_32 | V_33 |
V_34 ) ) {
V_30 = & V_23 -> V_2 -> V_30 ;
if ( V_28 & V_31 )
V_30 -> V_35 ++ ;
if ( V_28 & V_32 )
V_30 -> V_36 ++ ;
if ( V_28 & V_34 )
V_30 -> V_37 ++ ;
if ( V_28 & V_33 )
V_30 -> V_38 ++ ;
F_17 ( & V_2 -> V_2 -> V_2 . V_39 ) ;
}
}
static void F_18 ( struct V_22 * V_2 , T_3 V_40 )
{
struct V_29 * V_30 ;
if ( V_40 & V_41 ) {
V_40 &= ( T_3 ) ( V_42 | V_41 ) ;
}
V_30 = & V_2 -> V_2 -> V_30 ;
if ( V_40 & V_41 )
V_30 -> V_43 ++ ;
if ( V_40 & V_42 )
V_30 -> V_44 ++ ;
if ( V_40 & V_45 )
V_30 -> V_46 ++ ;
if ( V_40 & V_47 )
V_30 -> V_48 ++ ;
}
static void F_19 ( struct V_49 * V_49 )
{
unsigned char * V_27 ;
struct V_22 * V_23 ;
struct V_50 * V_6 = & V_49 -> V_6 -> V_6 ;
T_3 V_51 = 0x0 ;
int V_52 = V_49 -> V_52 ;
V_23 = V_49 -> V_53 ;
switch ( V_52 ) {
case 0 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_2 ( V_6 , L_7 , V_18 , V_52 ) ;
goto V_57;
default:
F_2 ( V_6 , L_8 , V_18 , V_52 ) ;
goto V_57;
}
F_2 ( V_6 , L_9 , V_18 , V_49 -> V_58 ) ;
F_2 ( V_6 , L_10 , V_18 ,
V_23 -> V_59 , V_23 -> V_60 ) ;
V_27 = V_49 -> V_61 ;
V_51 = ( T_3 ) V_27 [ 0 ] ;
F_2 ( V_6 , L_11 , V_18 , V_51 ) ;
if ( V_23 -> V_59 == 0 )
F_16 ( V_23 , V_51 ) ;
else if ( V_23 -> V_59 == 1 )
F_18 ( V_23 , V_51 ) ;
V_57:
F_20 ( V_62 , & V_23 -> V_63 ) ;
}
static int F_21 ( struct V_22 * V_64 , T_1 V_21 , T_1 V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 = V_64 -> V_2 -> V_7 -> V_6 ;
struct V_65 * V_66 = V_64 -> V_66 ;
unsigned char * V_67 = V_64 -> V_68 ;
int V_11 ;
if ( F_22 ( V_62 , & V_64 -> V_63 ) )
return - V_69 ;
V_66 -> V_70 = V_17 ;
V_66 -> V_71 = V_16 ;
V_66 -> V_72 = F_23 ( V_21 ) ;
V_66 -> V_73 = F_23 ( V_3 ) ;
V_66 -> V_74 = F_23 ( 2 ) ;
F_24 ( V_64 -> V_75 , V_6 , F_7 ( V_6 , 0 ) ,
( unsigned char * ) V_66 , V_67 , 2 ,
F_19 , V_64 ) ;
V_64 -> V_75 -> V_76 = 2 ;
V_11 = F_25 ( V_64 -> V_75 , V_77 ) ;
if ( V_11 )
F_20 ( V_62 , & V_64 -> V_63 ) ;
return V_11 ;
}
static void F_26 ( struct V_49 * V_49 )
{
switch ( V_49 -> V_52 ) {
case 0 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_2 ( & V_49 -> V_6 -> V_6 , L_12 ,
V_18 , V_49 -> V_52 ) ;
break;
default:
F_2 ( & V_49 -> V_6 -> V_6 , L_13 ,
V_18 , V_49 -> V_52 ) ;
}
}
static void F_27 ( struct V_22 * V_64 , T_1 V_78 ,
T_1 V_3 )
{
struct V_5 * V_6 = V_64 -> V_2 -> V_7 -> V_6 ;
struct V_65 * V_66 = V_64 -> V_79 ;
V_66 -> V_70 = V_9 ;
V_66 -> V_71 = V_8 ;
V_66 -> V_72 = F_23 ( V_78 ) ;
V_66 -> V_73 = F_23 ( V_3 ) ;
V_66 -> V_74 = F_23 ( 0 ) ;
F_24 ( V_64 -> V_80 , V_6 , F_4 ( V_6 , 0 ) ,
( unsigned char * ) V_66 , NULL , 0 , F_26 , NULL ) ;
F_25 ( V_64 -> V_80 , V_77 ) ;
}
static void F_28 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
F_3 ( V_6 , F_4 ( V_6 , 0 ) , V_8 , V_9 ,
V_4 , V_3 , NULL , 0 , V_10 ) ;
}
static void F_29 ( unsigned long V_81 )
{
struct V_22 * V_64 = (struct V_22 * ) V_81 ;
F_27 ( V_64 , 0x0300 , V_82 ) ;
F_30 ( & V_64 -> V_83 ,
V_84 + F_31 ( V_85 ) ) ;
}
static void F_32 ( unsigned long V_81 )
{
struct V_22 * V_64 = (struct V_22 * ) V_81 ;
F_20 ( V_86 , & V_64 -> V_63 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_15 ( V_2 ) ;
if ( F_22 ( V_86 , & V_23 -> V_63 ) )
return;
F_27 ( V_23 , 0x0301 , V_82 ) ;
F_30 ( & V_23 -> V_87 ,
V_84 + F_31 ( V_88 ) ) ;
}
static void F_34 ( struct V_49 * V_49 )
{
int V_89 ;
int V_90 ;
struct V_22 * V_23 ;
struct V_91 * V_7 ;
T_1 V_92 ;
unsigned char * V_27 ;
T_3 V_93 [ 5 ] , V_94 ;
int V_95 , V_96 = 0 ;
T_1 V_78 , V_97 = 0 ;
int V_52 = V_49 -> V_52 ;
switch ( V_52 ) {
case 0 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_2 ( & V_49 -> V_6 -> V_6 , L_7 ,
V_18 , V_52 ) ;
return;
default:
F_2 ( & V_49 -> V_6 -> V_6 , L_8 ,
V_18 , V_52 ) ;
goto exit;
}
V_90 = V_49 -> V_58 ;
V_27 = V_49 -> V_61 ;
V_7 = V_49 -> V_53 ;
if ( V_90 && V_90 > 5 ) {
F_2 ( & V_49 -> V_6 -> V_6 , L_14 , L_15 ) ;
return;
}
V_93 [ 0 ] = ( T_3 ) V_27 [ 0 ] ;
V_93 [ 1 ] = ( T_3 ) V_27 [ 1 ] ;
V_93 [ 2 ] = ( T_3 ) V_27 [ 2 ] ;
V_93 [ 3 ] = ( T_3 ) V_27 [ 3 ] ;
V_94 = ( T_3 ) V_27 [ 4 ] ;
for ( V_95 = 0 ; V_95 < V_7 -> V_19 ; V_95 ++ ) {
V_23 = F_14 ( V_7 -> V_2 [ V_95 ] ) ;
V_78 = ( ( T_1 ) V_7 -> V_2 [ V_95 ] -> V_20 + 1 ) << 8 ;
if ( V_23 -> V_98 ) {
if ( V_93 [ V_95 ] & 0x01 ) {
F_2 ( & V_49 -> V_6 -> V_6 , L_16 , V_95 ) ;
} else {
switch ( V_93 [ V_95 ] & 0x0f ) {
case V_99 :
F_2 ( & V_49 -> V_6 -> V_6 , L_17 , V_95 ) ;
F_2 ( & V_49 -> V_6 -> V_6 , L_18 ) ;
V_23 -> V_59 = 1 ;
V_97 = V_100 ;
break;
case V_101 :
F_2 ( & V_49 -> V_6 -> V_6 , L_19 , V_95 ) ;
V_23 -> V_59 = 0 ;
V_97 = V_102 ;
break;
}
V_96 = F_21 ( V_23 , V_78 , V_97 , & V_92 ) ;
}
}
}
if ( ! ( V_96 < 0 ) )
return;
exit:
V_89 = F_25 ( V_49 , V_77 ) ;
if ( V_89 ) {
F_35 ( & V_49 -> V_6 -> V_6 ,
L_20 ,
V_18 , V_89 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_103 )
{
if ( ! V_2 ) {
F_37 ( L_21 , V_103 ) ;
return - 1 ;
}
if ( ! V_2 -> V_7 ) {
F_37 ( L_22 , V_103 ) ;
return - 1 ;
}
return 0 ;
}
static int F_38 ( struct V_91 * V_7 ,
const char * V_103 )
{
if ( ! V_7 ) {
F_37 ( L_23 , V_103 ) ;
return - 1 ;
}
if ( ! V_7 -> type ) {
F_37 ( L_24 , V_103 ) ;
return - 1 ;
}
return 0 ;
}
static struct V_91 * F_39 ( struct V_1 * V_2 ,
const char * V_103 )
{
if ( ! V_2 ||
F_36 ( V_2 , V_103 ) ||
F_38 ( V_2 -> V_7 , V_103 ) ) {
return NULL ;
}
return V_2 -> V_7 ;
}
static void F_40 ( struct V_49 * V_49 )
{
int V_104 ;
unsigned char * V_27 ;
struct V_91 * V_7 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_52 = V_49 -> V_52 ;
V_23 = V_49 -> V_53 ;
if ( ! V_23 )
return;
if ( V_52 ) {
F_2 ( & V_49 -> V_6 -> V_6 , L_25 , V_52 ) ;
V_23 -> V_105 = false ;
return;
}
V_2 = V_23 -> V_2 ;
if ( F_36 ( V_2 , V_18 ) ) {
V_23 -> V_105 = false ;
return;
}
V_7 = F_39 ( V_2 , V_18 ) ;
if ( ! V_7 ) {
V_23 -> V_105 = false ;
return;
}
V_27 = V_49 -> V_61 ;
F_41 ( & V_2 -> V_6 , V_18 , V_49 -> V_58 , V_27 ) ;
if ( V_49 -> V_58 ) {
struct V_106 * V_107 = & V_23 -> V_2 -> V_2 ;
F_42 ( V_107 , V_27 , V_49 -> V_58 ) ;
F_43 ( V_107 ) ;
V_2 -> V_30 . V_108 += V_49 -> V_58 ;
F_2 ( & V_2 -> V_6 , L_26 , V_2 -> V_30 . V_108 ) ;
}
if ( ! V_23 -> V_109 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_27 ) ;
V_23 -> V_105 = false ;
return;
}
if ( V_23 -> V_110 )
F_33 ( V_2 ) ;
V_23 -> V_105 = true ;
V_104 = F_25 ( V_23 -> V_109 , V_77 ) ;
if ( V_104 ) {
F_2 ( & V_2 -> V_6 , L_28 , V_104 ) ;
V_23 -> V_105 = false ;
}
}
static void F_44 ( struct V_49 * V_49 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 ;
int V_52 = V_49 -> V_52 ;
int V_95 ;
V_23 = V_49 -> V_53 ;
V_2 = V_23 -> V_2 ;
F_45 ( & V_23 -> V_111 ) ;
for ( V_95 = 0 ; V_95 < V_112 ; V_95 ++ ) {
if ( V_49 == V_23 -> V_113 [ V_95 ] ) {
V_23 -> V_114 [ V_95 ] = 0 ;
break;
}
}
F_46 ( & V_23 -> V_111 ) ;
if ( V_52 ) {
F_2 ( & V_2 -> V_6 , L_29 , V_52 ) ;
return;
}
if ( F_36 ( V_2 , V_18 ) )
return;
if ( V_23 -> V_98 )
F_47 ( & V_2 -> V_2 ) ;
}
static int F_48 ( struct V_115 * V_116 , struct V_1 * V_2 )
{
int V_117 ;
int V_118 ;
struct V_91 * V_7 ;
struct V_49 * V_49 ;
T_1 V_92 ;
int V_52 ;
struct V_22 * V_23 ;
struct V_22 * V_119 ;
if ( F_36 ( V_2 , V_18 ) )
return - V_120 ;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_18 ) )
return - V_120 ;
V_23 = F_14 ( V_2 ) ;
V_119 = F_14 ( V_7 -> V_2 [ 0 ] ) ;
if ( V_23 == NULL || V_119 == NULL )
return - V_120 ;
F_49 ( V_7 -> V_6 , V_2 -> V_121 -> V_122 ) ;
F_49 ( V_7 -> V_6 , V_2 -> V_109 -> V_122 ) ;
V_119 -> V_123 ++ ;
for ( V_118 = 0 ; V_118 < V_112 ; ++ V_118 ) {
V_49 = F_50 ( 0 , V_14 ) ;
V_23 -> V_113 [ V_118 ] = V_49 ;
if ( V_49 == NULL ) {
F_35 ( & V_2 -> V_6 , L_30 ) ;
continue;
}
V_49 -> V_61 = F_6 ( V_124 ,
V_14 ) ;
if ( ! V_49 -> V_61 ) {
F_51 ( V_49 ) ;
V_23 -> V_113 [ V_118 ] = NULL ;
F_35 ( & V_2 -> V_6 ,
L_31 ,
V_18 ) ;
continue;
}
}
V_92 = 0x0 ;
V_52 = F_5 ( V_2 , V_23 -> V_24 , & V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_32 ) ;
goto V_125;
}
V_92 |= 0x80 ;
V_52 = F_1 ( V_2 , V_23 -> V_24 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_33 ) ;
goto V_125;
}
V_92 &= ~ 0x80 ;
V_52 = F_1 ( V_2 , V_23 -> V_24 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_33 ) ;
goto V_125;
}
V_92 = 0x0 ;
V_52 = F_5 ( V_2 , V_23 -> V_25 ,
& V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_34 ) ;
goto V_125;
}
V_92 |= 0x08 ;
V_92 |= 0x20 ;
V_52 = F_1 ( V_2 ,
V_23 -> V_25 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_35 ) ;
goto V_125;
}
V_92 = 0x00 ;
V_52 = F_9 ( V_2 , V_126 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_36 ) ;
goto V_125;
}
V_92 = 0x00 ;
V_52 = F_9 ( V_2 , V_127 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_37 ) ;
goto V_125;
}
V_92 = 0xcf ;
V_52 = F_9 ( V_2 , V_127 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_37 ) ;
goto V_125;
}
V_92 = 0x03 ;
V_52 = F_9 ( V_2 , V_128 , V_92 ) ;
V_23 -> V_129 = V_92 ;
V_92 = 0x0b ;
V_52 = F_9 ( V_2 , V_82 , V_92 ) ;
V_23 -> V_130 = V_92 ;
V_92 = 0x00 ;
V_52 = F_10 ( V_2 , V_128 , & V_92 ) ;
V_23 -> V_129 = V_92 ;
V_92 |= V_131 ;
V_52 = F_9 ( V_2 , V_128 , V_92 ) ;
V_92 = 0x0c ;
V_52 = F_9 ( V_2 , V_132 , V_92 ) ;
V_92 = 0x0 ;
V_52 = F_9 ( V_2 , V_133 , V_92 ) ;
V_92 = 0x00 ;
V_52 = F_10 ( V_2 , V_128 , & V_92 ) ;
V_92 = V_92 & ~ V_131 ;
V_52 = F_9 ( V_2 , V_128 , V_92 ) ;
V_23 -> V_129 = V_92 ;
V_92 = 0x0 ;
V_52 = F_5 ( V_2 , V_23 -> V_24 , & V_92 ) ;
V_92 = V_92 | 0x0c ;
V_52 = F_1 ( V_2 , V_23 -> V_24 , V_92 ) ;
V_92 = V_92 & ~ 0x0c ;
V_52 = F_1 ( V_2 , V_23 -> V_24 , V_92 ) ;
V_92 = 0x0c ;
V_52 = F_9 ( V_2 , V_126 , V_92 ) ;
V_92 = 0x0 ;
V_52 = F_5 ( V_2 , V_23 -> V_25 ,
& V_92 ) ;
V_92 = V_92 & ~ 0x20 ;
V_52 = F_1 ( V_2 , V_23 -> V_25 ,
V_92 ) ;
V_92 = 0x0 ;
V_52 = F_5 ( V_2 , V_23 -> V_25 ,
& V_92 ) ;
V_92 = V_92 | 0x10 ;
V_52 = F_1 ( V_2 , V_23 -> V_25 ,
V_92 ) ;
if ( V_119 -> V_123 == 1 ) {
if ( V_7 -> V_2 [ 0 ] -> V_134 == NULL ) {
F_52 ( V_7 -> V_2 [ 0 ] -> V_135 ,
V_7 -> V_6 ,
F_53 ( V_7 -> V_6 ,
V_7 -> V_2 [ 0 ] -> V_136 ) ,
V_7 -> V_2 [ 0 ] -> V_134 ,
V_7 -> V_2 [ 0 ] -> V_135 ->
V_76 ,
F_34 ,
V_7 ,
V_7 -> V_2 [ 0 ] -> V_135 -> V_137 ) ;
V_117 =
F_25 ( V_7 -> V_2 [ 0 ] -> V_135 ,
V_14 ) ;
if ( V_117 ) {
F_35 ( & V_2 -> V_6 , L_38
L_39 , V_18 , V_117 ) ;
}
}
}
F_2 ( & V_2 -> V_6 , L_40 , V_2 -> V_20 ) ;
F_2 ( & V_2 -> V_6 , L_41 , V_2 -> V_138 ) ;
F_2 ( & V_2 -> V_6 , L_42 , V_2 -> V_139 ) ;
F_2 ( & V_2 -> V_6 , L_43 , V_2 -> V_140 ) ;
F_2 ( & V_2 -> V_6 , L_44 , V_2 -> V_136 ) ;
F_2 ( & V_2 -> V_6 , L_45 , V_23 -> V_60 ) ;
V_23 -> V_109 = V_2 -> V_109 ;
if ( ( V_7 -> V_19 == 2 ) && ( ( ( T_1 ) V_2 -> V_20 % 2 ) != 0 ) ) {
F_54 ( V_23 -> V_109 ,
V_7 -> V_6 ,
F_55 ( V_7 -> V_6 ,
( V_2 -> V_139 ) + 2 ) ,
V_2 -> V_141 ,
V_23 -> V_109 -> V_76 ,
F_40 , V_23 ) ;
} else {
F_54 ( V_23 -> V_109 ,
V_7 -> V_6 ,
F_55 ( V_7 -> V_6 ,
V_2 -> V_139 ) ,
V_2 -> V_141 ,
V_23 -> V_109 -> V_76 ,
F_40 , V_23 ) ;
}
F_2 ( & V_2 -> V_6 , L_46 , V_18 , V_2 -> V_139 ) ;
V_23 -> V_105 = true ;
V_117 = F_25 ( V_23 -> V_109 , V_14 ) ;
if ( V_117 ) {
F_35 ( & V_2 -> V_6 , L_47 ,
V_18 , V_117 ) ;
V_23 -> V_105 = false ;
}
F_56 ( & V_23 -> V_142 ) ;
V_23 -> V_130 = V_143 ;
V_23 -> V_98 = 1 ;
return 0 ;
V_125:
for ( V_118 = 0 ; V_118 < V_112 ; ++ V_118 ) {
V_49 = V_23 -> V_113 [ V_118 ] ;
if ( ! V_49 )
continue;
F_8 ( V_49 -> V_61 ) ;
F_51 ( V_49 ) ;
}
return V_52 ;
}
static int F_57 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
int V_95 ;
int V_145 = 0 ;
unsigned long V_63 ;
struct V_22 * V_23 ;
if ( F_36 ( V_2 , V_18 ) )
return 0 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return 0 ;
F_58 ( & V_23 -> V_111 , V_63 ) ;
for ( V_95 = 0 ; V_95 < V_112 ; ++ V_95 ) {
if ( V_23 -> V_114 [ V_95 ] ) {
struct V_49 * V_49 = V_23 -> V_113 [ V_95 ] ;
V_145 += V_49 -> V_76 ;
}
}
F_59 ( & V_23 -> V_111 , V_63 ) ;
F_2 ( & V_2 -> V_6 , L_48 , V_18 , V_145 ) ;
return V_145 ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_91 * V_7 ;
struct V_22 * V_23 ;
struct V_22 * V_119 ;
int V_118 ;
T_1 V_92 ;
if ( F_36 ( V_2 , V_18 ) )
return;
V_7 = F_39 ( V_2 , V_18 ) ;
if ( ! V_7 )
return;
V_23 = F_14 ( V_2 ) ;
V_119 = F_14 ( V_7 -> V_2 [ 0 ] ) ;
if ( V_23 == NULL || V_119 == NULL )
return;
for ( V_118 = 0 ; V_118 < V_112 ; ++ V_118 )
F_61 ( V_23 -> V_113 [ V_118 ] ) ;
for ( V_118 = 0 ; V_118 < V_112 ; ++ V_118 ) {
if ( V_23 -> V_113 [ V_118 ] ) {
if ( V_23 -> V_113 [ V_118 ] -> V_61 )
F_8 ( V_23 -> V_113 [ V_118 ] ->
V_61 ) ;
F_51 ( V_23 -> V_113 [ V_118 ] ) ;
}
}
F_61 ( V_23 -> V_121 ) ;
F_61 ( V_23 -> V_109 ) ;
V_23 -> V_105 = false ;
V_119 -> V_123 -- ;
F_2 ( & V_2 -> V_6 , L_49 , V_18 , V_119 -> V_123 ) ;
if ( V_119 -> V_123 == 0 ) {
if ( V_7 -> V_2 [ 0 ] -> V_135 ) {
F_2 ( & V_2 -> V_6 , L_50 ) ;
F_61 ( V_7 -> V_2 [ 0 ] -> V_135 ) ;
}
}
if ( V_23 -> V_121 ) {
F_8 ( V_23 -> V_121 -> V_61 ) ;
F_51 ( V_23 -> V_121 ) ;
}
V_92 = 0x0 ;
F_9 ( V_2 , V_82 , V_92 ) ;
V_92 = 0x00 ;
F_9 ( V_2 , V_126 , V_92 ) ;
V_23 -> V_98 = 0 ;
}
static void F_62 ( struct V_115 * V_116 ,
struct V_22 * V_23 )
{
int V_146 = F_31 ( 1000 ) ;
int V_147 = 10 ;
int V_148 ;
while ( 1 ) {
V_148 = F_57 ( V_116 ) ;
if ( V_148 <= 0 )
return;
F_63 ( & V_23 -> V_142 ,
V_146 ) ;
V_147 -- ;
if ( V_147 == 0 ) {
F_2 ( & V_23 -> V_2 -> V_6 , L_51 , V_18 ) ;
return;
} else {
V_147 = 10 ;
}
}
}
static void F_64 ( struct V_115 * V_116 , int V_149 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
unsigned char V_27 ;
struct V_91 * V_7 ;
struct V_22 * V_23 ;
if ( F_36 ( V_2 , V_18 ) )
return;
V_7 = F_39 ( V_2 , V_18 ) ;
if ( ! V_7 )
return;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return;
F_62 ( V_116 , V_23 ) ;
if ( V_149 == - 1 )
V_27 = V_23 -> V_129 | V_150 ;
else
V_27 = V_23 -> V_129 & ~ V_150 ;
V_23 -> V_129 = V_27 ;
F_2 ( & V_2 -> V_6 , L_52 , V_18 , V_23 -> V_129 ) ;
F_9 ( V_2 , V_128 ,
V_23 -> V_129 ) ;
}
static int F_65 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
int V_95 ;
int V_151 = 0 ;
unsigned long V_63 ;
struct V_22 * V_23 ;
if ( F_36 ( V_2 , V_18 ) )
return - 1 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return - 1 ;
F_58 ( & V_23 -> V_111 , V_63 ) ;
for ( V_95 = 0 ; V_95 < V_112 ; ++ V_95 ) {
if ( ! V_23 -> V_114 [ V_95 ] )
V_151 += V_124 ;
}
F_59 ( & V_23 -> V_111 , V_63 ) ;
V_151 = ( V_151 == 0 ) ? 0 : V_151 - V_124 + 1 ;
F_2 ( & V_23 -> V_2 -> V_6 , L_48 , V_18 , V_151 ) ;
return V_151 ;
}
static int F_66 ( struct V_115 * V_116 , struct V_1 * V_2 ,
const unsigned char * V_27 , int V_148 )
{
int V_52 ;
int V_95 ;
int V_152 = 0 ;
int V_153 ;
unsigned long V_63 ;
struct V_22 * V_23 ;
struct V_91 * V_7 ;
struct V_49 * V_49 ;
const unsigned char * V_154 = V_27 ;
unsigned char * V_155 ;
#ifdef F_67
V_92 = 0x00 ;
V_52 = F_10 ( V_2 , V_128 , & V_92 ) ;
V_23 -> V_129 = V_92 ;
F_2 ( & V_2 -> V_6 , L_53 , V_18 , V_92 ) ;
F_2 ( & V_2 -> V_6 , L_54 , V_18 , V_23 -> V_129 ) ;
V_92 |= V_131 ;
V_52 = F_9 ( V_2 , V_128 , V_92 ) ;
V_92 = 0x00 ;
V_52 = F_10 ( V_2 , V_132 , & V_92 ) ;
F_2 ( & V_2 -> V_6 , L_55 , V_18 , V_92 ) ;
V_92 = 0x0 ;
V_52 = F_10 ( V_2 , V_133 , & V_92 ) ;
F_2 ( & V_2 -> V_6 , L_56 , V_18 , V_92 ) ;
V_92 = V_92 & ~ V_131 ;
F_2 ( & V_2 -> V_6 , L_54 , V_18 , V_23 -> V_129 ) ;
V_52 = F_9 ( V_2 , V_128 , V_92 ) ;
#endif
if ( F_36 ( V_2 , V_18 ) )
return - 1 ;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_18 ) )
return - 1 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return - 1 ;
V_49 = NULL ;
F_58 ( & V_23 -> V_111 , V_63 ) ;
for ( V_95 = 0 ; V_95 < V_112 ; ++ V_95 ) {
if ( ! V_23 -> V_114 [ V_95 ] ) {
V_23 -> V_114 [ V_95 ] = 1 ;
V_49 = V_23 -> V_113 [ V_95 ] ;
F_2 ( & V_2 -> V_6 , L_57 , V_95 ) ;
break;
}
}
F_59 ( & V_23 -> V_111 , V_63 ) ;
if ( V_49 == NULL ) {
F_2 ( & V_2 -> V_6 , L_58 , V_18 ) ;
goto exit;
}
if ( V_49 -> V_61 == NULL ) {
V_49 -> V_61 =
F_6 ( V_124 , V_14 ) ;
if ( V_49 -> V_61 == NULL ) {
F_68 ( V_2 , L_59 ,
V_18 ) ;
goto exit;
}
}
V_153 = F_69 ( V_148 , V_124 ) ;
memcpy ( V_49 -> V_61 , V_154 , V_153 ) ;
if ( ( V_7 -> V_19 == 2 ) && ( ( ( T_1 ) V_2 -> V_20 % 2 ) != 0 ) ) {
F_54 ( V_49 ,
V_7 -> V_6 ,
F_70 ( V_7 -> V_6 ,
( V_2 -> V_140 ) + 2 ) ,
V_49 -> V_61 ,
V_153 ,
F_44 , V_23 ) ;
} else {
F_54 ( V_49 ,
V_7 -> V_6 ,
F_70 ( V_7 -> V_6 ,
V_2 -> V_140 ) ,
V_49 -> V_61 ,
V_153 ,
F_44 , V_23 ) ;
}
V_155 = V_49 -> V_61 ;
F_2 ( & V_2 -> V_6 , L_60 , V_2 -> V_140 ) ;
if ( V_23 -> V_110 )
F_33 ( V_2 ) ;
V_52 = F_25 ( V_49 , V_77 ) ;
if ( V_52 ) {
V_23 -> V_114 [ V_95 ] = 0 ;
F_68 ( V_2 , L_61
L_62 , V_18 , V_52 ) ;
V_152 = V_52 ;
goto exit;
}
V_152 = V_153 ;
V_2 -> V_30 . V_156 += V_153 ;
F_2 ( & V_2 -> V_6 , L_63 , V_2 -> V_30 . V_156 ) ;
exit:
return V_152 ;
}
static void F_71 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
struct V_22 * V_23 ;
int V_52 ;
if ( F_36 ( V_2 , V_18 ) )
return;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return;
if ( ! V_23 -> V_98 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_64 ) ;
return;
}
if ( F_72 ( V_116 ) ) {
unsigned char V_157 = F_73 ( V_116 ) ;
V_52 = F_66 ( V_116 , V_2 , & V_157 , 1 ) ;
if ( V_52 <= 0 )
return;
}
if ( V_116 -> V_158 . V_159 & V_160 ) {
V_23 -> V_130 &= ~ V_161 ;
V_52 = F_9 ( V_2 , V_82 ,
V_23 -> V_130 ) ;
if ( V_52 < 0 )
return;
}
}
static void F_74 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
int V_52 ;
struct V_22 * V_23 = F_14 ( V_2 ) ;
if ( F_36 ( V_2 , V_18 ) )
return;
if ( V_23 == NULL )
return;
if ( ! V_23 -> V_98 ) {
F_2 ( & V_2 -> V_6 , L_65 , V_18 ) ;
return;
}
if ( F_72 ( V_116 ) ) {
unsigned char V_162 = F_75 ( V_116 ) ;
V_52 = F_66 ( V_116 , V_2 , & V_162 , 1 ) ;
if ( V_52 <= 0 )
return;
}
if ( V_116 -> V_158 . V_159 & V_160 ) {
V_23 -> V_130 |= V_161 ;
V_52 = F_9 ( V_2 , V_82 ,
V_23 -> V_130 ) ;
if ( V_52 < 0 )
return;
}
}
static int F_76 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
struct V_22 * V_23 ;
unsigned int V_89 ;
T_1 V_163 ;
T_1 V_164 ;
int V_52 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return - V_120 ;
V_52 = F_10 ( V_2 , V_102 , & V_163 ) ;
V_52 = F_10 ( V_2 , V_82 , & V_164 ) ;
V_89 = ( ( V_164 & V_165 ) ? V_166 : 0 )
| ( ( V_164 & V_161 ) ? V_167 : 0 )
| ( ( V_164 & V_168 ) ? V_169 : 0 )
| ( ( V_163 & V_170 ) ? V_171 : 0 )
| ( ( V_163 & V_172 ) ? V_173 : 0 )
| ( ( V_163 & V_174 ) ? V_175 : 0 )
| ( ( V_163 & V_176 ) ? V_177 : 0 ) ;
F_2 ( & V_2 -> V_6 , L_66 , V_18 , V_89 ) ;
return V_89 ;
}
static int F_77 ( struct V_115 * V_116 ,
unsigned int V_178 , unsigned int V_179 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
struct V_22 * V_23 ;
unsigned int V_164 ;
int V_52 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return - V_120 ;
V_164 = V_23 -> V_130 ;
if ( V_179 & V_167 )
V_164 &= ~ V_161 ;
if ( V_179 & V_166 )
V_164 &= ~ V_165 ;
if ( V_179 & V_169 )
V_164 &= ~ V_168 ;
if ( V_178 & V_167 )
V_164 |= V_161 ;
if ( V_178 & V_166 )
V_164 |= V_165 ;
if ( V_178 & V_169 )
V_164 |= V_168 ;
V_23 -> V_130 = V_164 ;
V_52 = F_9 ( V_2 , V_82 , V_164 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_67 ) ;
return V_52 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
int V_180 , int * V_181 ,
T_1 * V_182 )
{
F_2 ( & V_2 -> V_6 , L_68 , V_18 , V_180 ) ;
if ( V_180 <= 115200 ) {
* V_181 = 115200 / V_180 ;
* V_182 = 0x0 ;
}
if ( ( V_180 > 115200 ) && ( V_180 <= 230400 ) ) {
* V_181 = 230400 / V_180 ;
* V_182 = 0x10 ;
} else if ( ( V_180 > 230400 ) && ( V_180 <= 403200 ) ) {
* V_181 = 403200 / V_180 ;
* V_182 = 0x20 ;
} else if ( ( V_180 > 403200 ) && ( V_180 <= 460800 ) ) {
* V_181 = 460800 / V_180 ;
* V_182 = 0x30 ;
} else if ( ( V_180 > 460800 ) && ( V_180 <= 806400 ) ) {
* V_181 = 806400 / V_180 ;
* V_182 = 0x40 ;
} else if ( ( V_180 > 806400 ) && ( V_180 <= 921600 ) ) {
* V_181 = 921600 / V_180 ;
* V_182 = 0x50 ;
} else if ( ( V_180 > 921600 ) && ( V_180 <= 1572864 ) ) {
* V_181 = 1572864 / V_180 ;
* V_182 = 0x60 ;
} else if ( ( V_180 > 1572864 ) && ( V_180 <= 3145728 ) ) {
* V_181 = 3145728 / V_180 ;
* V_182 = 0x70 ;
}
return 0 ;
#ifdef F_79
for ( V_95 = 0 ; V_95 < F_80 ( V_183 ) ; V_95 ++ ) {
if ( V_183 [ V_95 ] . V_184 == V_185 ) {
* V_181 = V_183 [ V_95 ] . V_186 ;
return 0 ;
}
}
if ( V_185 > 75 && V_185 < 230400 ) {
V_187 = ( T_1 ) ( 230400L / V_185 ) ;
V_188 = ( T_1 ) ( 2304000L / V_185 ) ;
V_189 = ( T_1 ) ( V_188 - ( V_187 * 10 ) ) ;
if ( V_189 > 4 )
V_187 ++ ;
* V_181 = V_187 ;
F_2 ( & V_2 -> V_6 , L_69 , V_185 , V_187 ) ;
return 0 ;
}
F_2 ( & V_2 -> V_6 , L_14 , L_70 ) ;
return - 1 ;
#endif
}
static int F_81 ( struct V_22 * V_23 ,
int V_180 )
{
int V_181 = 0 ;
int V_52 ;
T_1 V_92 ;
unsigned char V_190 ;
T_1 V_182 ;
struct V_1 * V_2 ;
if ( V_23 == NULL )
return - 1 ;
V_2 = V_23 -> V_2 ;
if ( F_36 ( V_2 , V_18 ) )
return - 1 ;
if ( F_38 ( V_2 -> V_7 , V_18 ) )
return - 1 ;
V_190 = V_23 -> V_2 -> V_20 ;
F_2 ( & V_2 -> V_6 , L_71 , V_18 , V_180 ) ;
if ( V_180 > 115200 ) {
#ifdef F_82
V_92 = 0x2b ;
V_23 -> V_130 = V_92 ;
V_52 = F_9 ( V_2 , V_82 ,
V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_72 ) ;
return - 1 ;
}
#endif
} else {
#ifdef F_82
V_92 = 0xb ;
V_23 -> V_130 = V_92 ;
V_52 = F_9 ( V_2 , V_82 ,
V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_72 ) ;
return - 1 ;
}
#endif
}
if ( 1 ) {
V_182 = 0x0 ;
V_92 = 0x0 ;
V_52 = F_78 ( V_2 , V_180 , & V_181 ,
& V_182 ) ;
V_52 = F_5 ( V_2 , V_23 -> V_24 ,
& V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_73 ) ;
return - 1 ;
}
V_92 = ( V_92 & 0x8f ) | V_182 ;
V_52 = F_1 ( V_2 , V_23 -> V_24 ,
V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_72 ) ;
return - 1 ;
}
if ( V_52 ) {
F_35 ( & V_2 -> V_6 , L_74 , V_18 ) ;
return V_52 ;
}
V_92 = V_23 -> V_129 | V_131 ;
V_23 -> V_129 = V_92 ;
F_9 ( V_2 , V_128 , V_92 ) ;
V_92 = ( unsigned char ) ( V_181 & 0xff ) ;
F_2 ( & V_2 -> V_6 , L_75 , V_92 ) ;
F_9 ( V_2 , V_132 , V_92 ) ;
V_92 = ( unsigned char ) ( ( V_181 & 0xff00 ) >> 8 ) ;
F_2 ( & V_2 -> V_6 , L_76 , V_92 ) ;
F_9 ( V_2 , V_133 , V_92 ) ;
V_92 = V_23 -> V_129 & ~ V_131 ;
V_23 -> V_129 = V_92 ;
F_9 ( V_2 , V_128 , V_92 ) ;
}
return V_52 ;
}
static void F_83 ( struct V_115 * V_116 ,
struct V_22 * V_23 , struct V_191 * V_192 )
{
int V_193 ;
unsigned V_194 ;
unsigned V_195 ;
T_3 V_196 ;
T_3 V_197 ;
T_3 V_198 ;
int V_52 ;
T_1 V_92 ;
struct V_1 * V_2 ;
struct V_91 * V_7 ;
if ( V_23 == NULL )
return;
V_2 = V_23 -> V_2 ;
if ( F_36 ( V_2 , V_18 ) )
return;
if ( F_38 ( V_2 -> V_7 , V_18 ) )
return;
V_7 = V_2 -> V_7 ;
if ( ! V_23 -> V_98 ) {
F_2 ( & V_2 -> V_6 , L_65 , V_18 ) ;
return;
}
V_196 = V_199 ;
V_198 = V_200 ;
V_197 = V_201 ;
V_194 = V_116 -> V_158 . V_159 ;
V_195 = V_116 -> V_158 . V_202 ;
if ( V_194 & V_203 ) {
switch ( V_194 & V_203 ) {
case V_204 :
V_196 = V_205 ;
break;
case V_206 :
V_196 = V_207 ;
break;
case V_208 :
V_196 = V_209 ;
break;
default:
case V_210 :
V_196 = V_199 ;
break;
}
}
if ( V_194 & V_211 ) {
if ( V_194 & V_212 ) {
V_197 = V_213 ;
F_2 ( & V_2 -> V_6 , L_77 , V_18 ) ;
} else {
V_197 = V_214 ;
F_2 ( & V_2 -> V_6 , L_78 , V_18 ) ;
}
} else {
F_2 ( & V_2 -> V_6 , L_79 , V_18 ) ;
}
if ( V_194 & V_215 )
V_197 = V_197 | 0x20 ;
if ( V_194 & V_216 ) {
V_198 = V_217 ;
F_2 ( & V_2 -> V_6 , L_80 , V_18 ) ;
} else {
V_198 = V_200 ;
F_2 ( & V_2 -> V_6 , L_81 , V_18 ) ;
}
V_23 -> V_129 &=
~ ( V_218 | V_219 | V_220 ) ;
V_23 -> V_129 |= ( V_196 | V_197 | V_198 ) ;
F_2 ( & V_2 -> V_6 , L_82 , V_18 ,
V_23 -> V_129 ) ;
V_92 = 0x00 ;
F_9 ( V_2 , V_126 , V_92 ) ;
V_92 = 0x00 ;
F_9 ( V_2 , V_127 , V_92 ) ;
V_92 = 0xcf ;
F_9 ( V_2 , V_127 , V_92 ) ;
V_92 = V_23 -> V_129 ;
F_9 ( V_2 , V_128 , V_92 ) ;
V_92 = 0x00b ;
V_23 -> V_130 = V_92 ;
F_9 ( V_2 , V_82 , V_92 ) ;
V_92 = 0x00b ;
F_9 ( V_2 , V_82 , V_92 ) ;
V_23 -> V_130 = V_143 ;
if ( V_194 & V_221 )
V_23 -> V_130 |= ( V_165 | V_161 ) ;
if ( V_194 & V_160 )
V_23 -> V_130 |= ( V_222 ) ;
else
V_23 -> V_130 &= ~ ( V_222 ) ;
V_92 = V_23 -> V_130 ;
F_9 ( V_2 , V_82 , V_92 ) ;
V_193 = F_84 ( V_116 ) ;
if ( ! V_193 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_83 ) ;
V_193 = 9600 ;
}
F_2 ( & V_2 -> V_6 , L_84 , V_18 , V_193 ) ;
V_52 = F_81 ( V_23 , V_193 ) ;
V_92 = 0x0c ;
F_9 ( V_2 , V_126 , V_92 ) ;
if ( V_23 -> V_105 == false ) {
V_23 -> V_105 = true ;
V_52 = F_25 ( V_23 -> V_109 , V_77 ) ;
if ( V_52 ) {
F_2 ( & V_2 -> V_6 , L_85 ,
V_52 ) ;
V_23 -> V_105 = false ;
}
}
F_2 ( & V_2 -> V_6 , L_86 , V_18 ,
V_23 -> V_129 ) ;
}
static void F_85 ( struct V_115 * V_116 ,
struct V_1 * V_2 ,
struct V_191 * V_192 )
{
int V_52 ;
unsigned int V_194 ;
struct V_91 * V_7 ;
struct V_22 * V_23 ;
if ( F_36 ( V_2 , V_18 ) )
return;
V_7 = V_2 -> V_7 ;
if ( F_38 ( V_7 , V_18 ) )
return;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return;
if ( ! V_23 -> V_98 ) {
F_2 ( & V_2 -> V_6 , L_65 , V_18 ) ;
return;
}
F_2 ( & V_2 -> V_6 , L_14 , L_87 ) ;
V_194 = V_116 -> V_158 . V_159 ;
F_2 ( & V_2 -> V_6 , L_88 , V_18 ,
V_116 -> V_158 . V_159 , F_86 ( V_116 -> V_158 . V_202 ) ) ;
F_2 ( & V_2 -> V_6 , L_89 , V_18 ,
V_192 -> V_159 , F_86 ( V_192 -> V_202 ) ) ;
F_83 ( V_116 , V_23 , V_192 ) ;
if ( ! V_23 -> V_109 ) {
F_2 ( & V_2 -> V_6 , L_14 , L_90 ) ;
return;
}
if ( V_23 -> V_105 == false ) {
V_23 -> V_105 = true ;
V_52 = F_25 ( V_23 -> V_109 , V_77 ) ;
if ( V_52 ) {
F_2 ( & V_2 -> V_6 , L_85 ,
V_52 ) ;
V_23 -> V_105 = false ;
}
}
}
static int F_87 ( struct V_115 * V_116 ,
unsigned int T_4 * V_223 )
{
int V_148 ;
unsigned int V_89 = 0 ;
V_148 = F_57 ( V_116 ) ;
if ( V_148 == 0 )
V_89 = V_224 ;
if ( F_88 ( V_223 , & V_89 , sizeof( int ) ) )
return - V_225 ;
return 0 ;
}
static int F_89 ( struct V_22 * V_23 ,
struct V_226 T_4 * V_227 )
{
struct V_226 V_228 ;
if ( V_23 == NULL )
return - 1 ;
if ( ! V_227 )
return - V_225 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . type = V_229 ;
V_228 . line = V_23 -> V_2 -> V_138 ;
V_228 . V_2 = V_23 -> V_2 -> V_20 ;
V_228 . V_230 = 0 ;
V_228 . V_63 = V_231 | V_232 ;
V_228 . V_233 = V_112 * V_124 ;
V_228 . V_234 = 9600 ;
V_228 . V_235 = 5 * V_236 ;
V_228 . V_237 = 30 * V_236 ;
if ( F_88 ( V_227 , & V_228 , sizeof( * V_227 ) ) )
return - V_225 ;
return 0 ;
}
static int F_90 ( struct V_115 * V_116 ,
unsigned int V_238 , unsigned long V_81 )
{
struct V_1 * V_2 = V_116 -> V_144 ;
void T_4 * V_239 = ( void T_4 * ) V_81 ;
struct V_22 * V_23 ;
if ( F_36 ( V_2 , V_18 ) )
return - 1 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == NULL )
return - 1 ;
F_2 ( & V_2 -> V_6 , L_91 , V_18 , V_238 ) ;
switch ( V_238 ) {
case V_240 :
F_2 ( & V_2 -> V_6 , L_92 , V_18 ) ;
return F_87 ( V_116 , V_239 ) ;
case V_241 :
F_2 ( & V_2 -> V_6 , L_93 , V_18 ) ;
return F_89 ( V_23 , V_239 ) ;
case V_242 :
F_2 ( & V_2 -> V_6 , L_94 , V_18 ) ;
break;
default:
break;
}
return - V_243 ;
}
static int F_91 ( struct V_91 * V_7 )
{
int V_95 , V_244 = 0 ;
T_2 * V_12 ;
T_1 V_27 = 0 , V_245 = 0 ;
T_1 V_246 = 0x55AA ;
int V_247 ;
V_12 = F_6 ( V_13 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_247 = F_3 ( V_7 -> V_6 , F_7 ( V_7 -> V_6 , 0 ) ,
V_16 , V_17 , 0x0300 , V_82 ,
V_12 , V_13 , V_10 ) ;
if ( V_247 == V_13 )
V_245 = * V_12 ;
for ( V_95 = 0 ; V_95 < 16 ; V_95 ++ ) {
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) ,
V_8 , V_9 ,
( 0x0300 | ( ( ( V_246 >> V_95 ) & 0x0001 ) << 1 ) ) ,
V_82 , NULL , 0 , V_10 ) ;
V_247 = F_3 ( V_7 -> V_6 ,
F_7 ( V_7 -> V_6 , 0 ) , V_16 ,
V_17 , 0 , V_248 , V_12 ,
V_13 , V_10 ) ;
if ( V_247 == V_13 )
V_27 = * V_12 ;
if ( ( ( V_246 >> V_95 ) ^ ( ~ V_27 >> 1 ) ) & 0x0001 )
break;
V_244 ++ ;
}
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) , V_8 ,
V_9 , 0x0300 | V_245 , V_82 , NULL ,
0 , V_10 ) ;
F_8 ( V_12 ) ;
if ( V_244 == 16 )
return 1 ;
return 0 ;
}
static int F_92 ( struct V_91 * V_7 ,
const struct V_249 * V_250 )
{
T_5 V_251 = F_93 ( V_7 -> V_6 -> V_252 . V_253 ) ;
T_2 * V_12 ;
int V_254 ;
if ( V_251 == V_255 ||
V_251 == V_256 ) {
V_254 = V_251 ;
goto V_57;
}
V_12 = F_94 ( V_13 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
F_3 ( V_7 -> V_6 , F_7 ( V_7 -> V_6 , 0 ) ,
V_16 , V_17 , 0 , V_248 , V_12 ,
V_13 , V_10 ) ;
if ( V_12 [ 0 ] & 0x01 )
V_254 = V_257 ;
else if ( F_91 ( V_7 ) )
V_254 = V_255 ;
else
V_254 = V_256 ;
F_8 ( V_12 ) ;
V_57:
F_95 ( V_7 , ( void * ) ( unsigned long ) V_254 ) ;
return 0 ;
}
static int F_96 ( struct V_91 * V_7 )
{
int V_254 = ( unsigned long ) F_97 ( V_7 ) ;
int V_258 ;
V_258 = ( V_254 >> 4 ) & 0x000F ;
return V_258 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_91 * V_7 = V_2 -> V_7 ;
int V_254 = ( unsigned long ) F_97 ( V_7 ) ;
struct V_22 * V_23 ;
int V_52 ;
int V_259 ;
T_1 V_92 ;
V_259 = V_2 -> V_20 ;
F_2 ( & V_2 -> V_6 , L_95 , V_259 ) ;
V_23 = F_94 ( sizeof( struct V_22 ) , V_14 ) ;
if ( V_23 == NULL ) {
F_35 ( & V_2 -> V_6 , L_96 , V_18 ) ;
return - V_15 ;
}
V_23 -> V_2 = V_2 ;
F_12 ( V_2 , V_23 ) ;
F_99 ( & V_23 -> V_111 ) ;
V_23 -> V_60 = V_259 + 1 ;
F_2 ( & V_2 -> V_6 , L_97 , V_2 -> V_138 ) ;
F_2 ( & V_2 -> V_6 , L_98 , V_23 -> V_60 ) ;
if ( V_23 -> V_60 == 1 ) {
V_23 -> V_24 = 0x0 ;
V_23 -> V_25 = 0x1 ;
V_23 -> V_26 = 0x4 ;
} else if ( ( V_23 -> V_60 == 2 ) && ( V_7 -> V_19 == 4 ) ) {
V_23 -> V_24 = 0x8 ;
V_23 -> V_25 = 0x9 ;
V_23 -> V_26 = 0x16 ;
} else if ( ( V_23 -> V_60 == 2 ) && ( V_7 -> V_19 == 2 ) ) {
V_23 -> V_24 = 0xa ;
V_23 -> V_25 = 0xb ;
V_23 -> V_26 = 0x19 ;
} else if ( ( V_23 -> V_60 == 3 ) && ( V_7 -> V_19 == 4 ) ) {
V_23 -> V_24 = 0xa ;
V_23 -> V_25 = 0xb ;
V_23 -> V_26 = 0x19 ;
} else if ( ( V_23 -> V_60 == 4 ) && ( V_7 -> V_19 == 4 ) ) {
V_23 -> V_24 = 0xc ;
V_23 -> V_25 = 0xd ;
V_23 -> V_26 = 0x1c ;
}
F_11 ( V_2 , V_23 ) ;
F_12 ( V_2 , V_23 ) ;
V_52 = F_5 ( V_2 ,
V_23 -> V_25 , & V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_99 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_100 , V_92 , V_52 ) ;
V_92 |= 0x08 ;
V_92 |= 0x04 ;
V_52 = F_1 ( V_2 ,
V_23 -> V_25 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_101 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_102 , V_52 ) ;
V_92 = 0x01 ;
V_52 = F_1 ( V_2 ,
( T_1 ) ( V_23 -> V_26 + 0 ) , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_103 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_104 , V_52 ) ;
V_92 = 0x05 ;
V_52 = F_1 ( V_2 ,
( T_1 ) ( V_23 -> V_26 + 1 ) , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_105 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_106 , V_52 ) ;
V_92 = 0x24 ;
V_52 = F_1 ( V_2 ,
( T_1 ) ( V_23 -> V_26 + 2 ) , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_107 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_108 , V_52 ) ;
V_92 = 0x0 ;
V_52 = F_1 ( V_2 , V_260 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_109 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_110 , V_52 ) ;
V_92 = 0x20 ;
V_52 = F_1 ( V_2 , V_261 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_111 , V_52 ) ;
goto error;
} else
F_2 ( & V_2 -> V_6 , L_112 , V_52 ) ;
V_92 = 0x00 ;
V_52 = F_9 ( V_2 , V_262 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_113 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_114 , V_52 ) ;
if ( ( V_23 -> V_60 != 1 ) && ( V_7 -> V_19 == 2 ) ) {
V_92 = 0xff ;
V_52 = F_1 ( V_2 ,
( T_1 ) ( V_263 +
( ( T_1 ) V_23 -> V_60 ) ) , V_92 ) ;
F_2 ( & V_2 -> V_6 , L_115 ,
( T_1 ) ( V_263 + ( ( T_1 ) V_23 -> V_60 ) ) ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_116 , V_259 + 2 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_117 , V_259 + 2 , V_52 ) ;
} else {
V_92 = 0xff ;
V_52 = F_1 ( V_2 ,
( T_1 ) ( V_263 +
( ( T_1 ) V_23 -> V_60 ) - 0x1 ) , V_92 ) ;
F_2 ( & V_2 -> V_6 , L_115 ,
( T_1 ) ( V_263 + ( ( T_1 ) V_23 -> V_60 ) - 0x1 ) ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_116 , V_259 + 1 , V_52 ) ;
goto V_57;
} else
F_2 ( & V_2 -> V_6 , L_117 , V_259 + 1 , V_52 ) ;
}
V_23 -> V_75 = F_50 ( 0 , V_14 ) ;
V_23 -> V_68 = F_6 ( 16 , V_14 ) ;
V_23 -> V_66 = F_6 ( sizeof( struct V_65 ) ,
V_14 ) ;
if ( ! V_23 -> V_75 || ! V_23 -> V_68 ||
! V_23 -> V_66 ) {
V_52 = - V_15 ;
goto error;
}
V_23 -> V_110 = false ;
if ( V_254 == V_255 ) {
V_23 -> V_110 = true ;
V_23 -> V_80 = F_50 ( 0 , V_14 ) ;
V_23 -> V_79 = F_6 ( sizeof( * V_23 -> V_79 ) ,
V_14 ) ;
if ( ! V_23 -> V_80 || ! V_23 -> V_79 ) {
V_52 = - V_15 ;
goto error;
}
F_100 ( & V_23 -> V_87 ) ;
V_23 -> V_87 . V_103 = F_29 ;
V_23 -> V_87 . V_264 =
V_84 + F_31 ( V_88 ) ;
V_23 -> V_87 . V_27 = ( unsigned long ) V_23 ;
F_100 ( & V_23 -> V_83 ) ;
V_23 -> V_83 . V_103 = F_32 ;
V_23 -> V_83 . V_264 =
V_84 + F_31 ( V_85 ) ;
V_23 -> V_83 . V_27 = ( unsigned long ) V_23 ;
F_28 ( V_2 , V_82 , 0x0300 ) ;
}
V_57:
if ( V_259 == V_7 -> V_19 - 1 ) {
V_92 = 0x0f ;
V_52 = F_1 ( V_7 -> V_2 [ 0 ] , V_265 , V_92 ) ;
if ( V_52 < 0 ) {
F_2 ( & V_2 -> V_6 , L_118 , V_52 ) ;
goto error;
} else
F_2 ( & V_2 -> V_6 , L_119 , V_52 ) ;
F_3 ( V_7 -> V_6 , F_4 ( V_7 -> V_6 , 0 ) ,
0x03 , 0x00 , 0x01 , 0x00 , NULL , 0x00 ,
V_10 ) ;
}
return 0 ;
error:
F_8 ( V_23 -> V_79 ) ;
F_51 ( V_23 -> V_80 ) ;
F_8 ( V_23 -> V_66 ) ;
F_8 ( V_23 -> V_68 ) ;
F_51 ( V_23 -> V_75 ) ;
F_8 ( V_23 ) ;
return V_52 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 -> V_110 ) {
F_28 ( V_2 , V_82 , 0x0300 ) ;
F_102 ( & V_23 -> V_87 ) ;
F_102 ( & V_23 -> V_83 ) ;
F_61 ( V_23 -> V_80 ) ;
F_51 ( V_23 -> V_80 ) ;
F_8 ( V_23 -> V_79 ) ;
}
F_61 ( V_23 -> V_75 ) ;
F_51 ( V_23 -> V_75 ) ;
F_8 ( V_23 -> V_68 ) ;
F_8 ( V_23 -> V_66 ) ;
F_8 ( V_23 ) ;
return 0 ;
}
