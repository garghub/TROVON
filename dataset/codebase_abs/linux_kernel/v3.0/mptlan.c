static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_2 * V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
int V_7 = 0 ;
F_2 ( ( V_8 V_9 L_1 ,
F_3 ( V_5 ) ) ) ;
if ( V_2 == NULL ) {
T_3 V_10 = F_4 ( V_3 ) ;
F_2 ( ( V_8 V_9 L_2 ,
F_3 ( V_5 ) ,
V_10 ) ) ;
switch ( F_5 ( V_10 ) ) {
#if 0
case LAN_REPLY_FORM_MESSAGE_CONTEXT:
FreeReqFrame = 1;
break;
#endif
case V_11 :
( void ) F_6 ( V_5 , V_10 ) ;
V_7 = 0 ;
break;
case V_12 :
F_7 ( V_5 , V_10 ) ;
break;
default:
F_8 (KERN_ERR MYNAM L_3
L_4 ) ;
break;
}
return V_7 ;
}
switch ( V_3 -> V_13 . V_14 . V_15 ) {
case V_16 :
{
T_4 * V_17 ;
V_17 = ( T_4 * ) V_3 ;
V_7 = F_9 ( V_5 , V_17 ) ;
break;
}
case V_18 :
{
T_5 * V_19 ;
V_19 = ( T_5 * ) V_3 ;
if ( V_19 -> V_20 ) {
F_10 ( V_5 , V_19 ) ;
if ( ! ( V_19 -> V_21 & V_22 ) )
V_7 = 1 ;
} else
F_2 ( ( V_8 V_9 L_5
L_6 ) ) ;
break;
}
case V_23 :
V_7 = 1 ;
break;
case V_24 :
case V_25 :
V_7 = 1 ;
break;
default:
F_8 (KERN_ERR MYNAM L_7
L_8 ) ;
V_7 = 1 ;
break;
}
return V_7 ;
}
static int
F_11 ( T_1 * V_1 , int V_26 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
struct V_27 * V_28 ;
if ( V_5 == NULL )
return ( 1 ) ;
else
V_28 = F_12 ( V_5 ) ;
F_13 ( ( V_8 V_9 L_9 ,
V_26 == V_29 ? L_10 : (
V_26 == V_30 ? L_11 : L_12 ) ) ) ;
if ( V_28 -> V_31 == NULL )
return ( 1 ) ;
if ( V_26 == V_29 ) {
;
} else if ( V_26 == V_30 ) {
int V_32 ;
unsigned long V_33 ;
F_14 ( V_5 ) ;
F_13 ( ( V_8 L_13 , V_5 -> V_34 ) ) ;
F_15 ( & V_28 -> V_35 , 0 ) ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_37 = - 1 ;
for ( V_32 = 0 ; V_32 < V_28 -> V_38 ; V_32 ++ )
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_32 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
} else {
F_18 ( V_28 ) ;
F_19 ( V_5 ) ;
}
return 1 ;
}
static int
F_20 ( T_1 * V_1 , T_6 * V_39 )
{
F_13 ( ( V_8 V_9 L_14 ) ) ;
switch ( F_21 ( V_39 -> V_40 ) ) {
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
default:
break;
}
return 1 ;
}
static int
F_22 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
int V_32 ;
if ( F_23 ( V_5 ) != 0 ) {
T_1 * V_52 = V_28 -> V_52 ;
F_8 (KERN_WARNING MYNAM L_15 ) ;
if ( V_52 -> V_53 )
F_8 ( L_16
L_17 ) ;
else
F_8 ( L_18
L_19
L_20 ) ;
}
V_28 -> V_54 = F_24 ( V_28 -> V_55 * sizeof( int ) , V_56 ) ;
if ( V_28 -> V_54 == NULL )
goto V_57;
V_28 -> V_58 = - 1 ;
V_28 -> V_59 = F_25 ( V_28 -> V_55 , sizeof( struct V_60 ) ,
V_56 ) ;
if ( V_28 -> V_59 == NULL )
goto V_61;
for ( V_32 = 0 ; V_32 < V_28 -> V_55 ; V_32 ++ )
V_28 -> V_54 [ ++ V_28 -> V_58 ] = V_32 ;
F_13 ( ( V_8 V_9 L_21 ) ) ;
V_28 -> V_31 = F_24 ( V_28 -> V_38 * sizeof( int ) ,
V_56 ) ;
if ( V_28 -> V_31 == NULL )
goto V_62;
V_28 -> V_37 = - 1 ;
V_28 -> V_63 = F_25 ( V_28 -> V_38 ,
sizeof( struct V_60 ) ,
V_56 ) ;
if ( V_28 -> V_63 == NULL )
goto V_64;
for ( V_32 = 0 ; V_32 < V_28 -> V_38 ; V_32 ++ )
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_32 ;
F_13 ( ( V_8 V_9 L_22 ) ) ;
for ( V_32 = 0 ; V_32 < V_28 -> V_55 ; V_32 ++ )
F_13 ( ( L_23 , V_28 -> V_54 [ V_32 ] ) ) ;
F_13 ( ( L_24 ) ) ;
F_13 ( ( V_8 V_9 L_25 ) ) ;
F_18 ( V_28 ) ;
F_8 (KERN_INFO MYNAM L_26 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
if ( F_26 ( V_65 , F_20 ) != 0 ) {
F_8 (KERN_WARNING MYNAM L_27
L_28
L_29
L_30 ) ;
}
F_27 ( V_5 ) ;
F_13 ( ( V_8 V_9 L_31 ) ) ;
return 0 ;
V_64:
F_28 ( V_28 -> V_31 ) ;
V_28 -> V_31 = NULL ;
V_62:
F_28 ( V_28 -> V_59 ) ;
V_28 -> V_59 = NULL ;
V_61:
F_28 ( V_28 -> V_54 ) ;
V_28 -> V_54 = NULL ;
V_57: return - V_66 ;
}
static int
F_23 ( struct V_4 * V_5 )
{
T_2 * V_2 ;
T_7 * V_67 ;
struct V_27 * V_28 = F_12 ( V_5 ) ;
V_2 = F_29 ( V_65 , V_28 -> V_52 ) ;
if ( V_2 == NULL ) {
return - 1 ;
}
V_67 = ( T_7 * ) V_2 ;
V_67 -> V_15 = V_23 ;
V_67 -> V_68 = 0 ;
V_67 -> V_69 = 0 ;
V_67 -> V_70 = V_28 -> V_71 ;
V_67 -> V_21 = 0 ;
V_67 -> V_72 = 0 ;
F_30 ( V_65 , V_28 -> V_52 , V_2 ) ;
return 0 ;
}
static int
F_31 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
unsigned long V_73 ;
int V_32 ;
F_13 ( ( V_8 V_9 L_32 ) ) ;
F_32 ( V_65 ) ;
F_13 ( ( V_8 V_9 L_33
L_34 ,
V_28 -> V_74 , F_33 ( & V_28 -> V_35 ) ) ) ;
F_14 ( V_5 ) ;
F_23 ( V_5 ) ;
V_73 = V_75 + 2 * V_76 ;
while ( F_33 ( & V_28 -> V_35 ) && F_34 ( V_75 , V_73 ) )
F_35 ( 1 ) ;
for ( V_32 = 0 ; V_32 < V_28 -> V_38 ; V_32 ++ ) {
if ( V_28 -> V_63 [ V_32 ] . V_77 != NULL ) {
F_13 ( ( V_8 V_9 L_35
L_36 , V_32 ) ) ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_32 ] . V_79 ,
V_28 -> V_63 [ V_32 ] . V_80 ,
V_81 ) ;
F_37 ( V_28 -> V_63 [ V_32 ] . V_77 ) ;
}
}
F_28 ( V_28 -> V_63 ) ;
F_28 ( V_28 -> V_31 ) ;
for ( V_32 = 0 ; V_32 < V_28 -> V_55 ; V_32 ++ ) {
if ( V_28 -> V_59 [ V_32 ] . V_77 != NULL ) {
F_36 ( V_52 -> V_78 , V_28 -> V_59 [ V_32 ] . V_79 ,
V_28 -> V_59 [ V_32 ] . V_80 ,
V_82 ) ;
F_37 ( V_28 -> V_59 [ V_32 ] . V_77 ) ;
}
}
F_28 ( V_28 -> V_59 ) ;
F_28 ( V_28 -> V_54 ) ;
F_15 ( & V_28 -> V_35 , 0 ) ;
F_8 (KERN_INFO MYNAM L_37 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
return 0 ;
}
static int
F_38 ( struct V_4 * V_5 , int V_83 )
{
if ( ( V_83 < V_84 ) || ( V_83 > V_85 ) )
return - V_86 ;
V_5 -> V_87 = V_83 ;
return 0 ;
}
static void
F_39 ( struct V_4 * V_5 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
if ( V_52 -> V_53 ) {
F_13 ( ( L_38 , V_5 -> V_34 ) ) ;
F_19 ( V_5 ) ;
}
}
static int
F_6 ( struct V_4 * V_5 , T_3 V_10 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_88 * V_89 ;
unsigned long V_33 ;
T_3 V_90 ;
V_90 = F_40 ( V_10 ) ;
V_89 = V_28 -> V_59 [ V_90 ] . V_77 ;
V_5 -> V_91 . V_92 ++ ;
V_5 -> V_91 . V_93 += V_89 -> V_80 ;
F_2 ( ( V_8 V_9 L_39 ,
F_3 ( V_5 ) ,
V_94 , V_89 ) ) ;
V_28 -> V_59 [ V_90 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_59 [ V_90 ] . V_79 ,
V_28 -> V_59 [ V_90 ] . V_80 , V_82 ) ;
F_41 ( V_89 ) ;
F_16 ( & V_28 -> V_95 , V_33 ) ;
V_28 -> V_54 [ ++ V_28 -> V_58 ] = V_90 ;
F_17 ( & V_28 -> V_95 , V_33 ) ;
F_19 ( V_5 ) ;
return 0 ;
}
static int
F_9 ( struct V_4 * V_5 , T_4 * V_17 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_88 * V_89 ;
unsigned long V_33 ;
int V_7 = 0 ;
T_3 * V_96 ;
T_3 V_90 ;
T_8 V_97 ;
V_97 = V_17 -> V_20 ;
F_2 ( ( V_8 V_9 L_40 ,
F_42 ( V_17 -> V_98 ) ) ) ;
switch ( F_42 ( V_17 -> V_98 ) & V_99 ) {
case V_100 :
V_5 -> V_91 . V_92 += V_97 ;
break;
case V_101 :
case V_102 :
break;
case V_103 :
V_5 -> V_91 . V_104 += V_97 ;
F_8 (KERN_ERR MYNAM L_41 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
goto V_57;
default:
V_5 -> V_91 . V_104 += V_97 ;
break;
}
V_96 = & V_17 -> V_105 ;
F_16 ( & V_28 -> V_95 , V_33 ) ;
while ( V_97 > 0 ) {
V_90 = F_40 ( F_21 ( * V_96 ) ) ;
V_89 = V_28 -> V_59 [ V_90 ] . V_77 ;
V_5 -> V_91 . V_93 += V_89 -> V_80 ;
F_2 ( ( V_8 V_9 L_39 ,
F_3 ( V_5 ) ,
V_94 , V_89 ) ) ;
V_28 -> V_59 [ V_90 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_59 [ V_90 ] . V_79 ,
V_28 -> V_59 [ V_90 ] . V_80 , V_82 ) ;
F_41 ( V_89 ) ;
V_28 -> V_54 [ ++ V_28 -> V_58 ] = V_90 ;
V_96 ++ ;
V_97 -- ;
}
F_17 ( & V_28 -> V_95 , V_33 ) ;
V_57:
if ( ! ( V_17 -> V_21 & V_22 ) )
V_7 = 1 ;
F_19 ( V_5 ) ;
return V_7 ;
}
static int
F_43 ( struct V_88 * V_77 , struct V_4 * V_5 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
T_2 * V_2 ;
T_9 * V_106 ;
T_10 * V_107 ;
T_11 * V_108 ;
const unsigned char * V_109 ;
T_12 V_79 ;
unsigned long V_33 ;
int V_90 ;
T_13 V_110 = 0x1000 ;
F_2 ( ( V_8 V_9 L_42 ,
V_94 , V_77 ) ) ;
F_16 ( & V_28 -> V_95 , V_33 ) ;
if ( V_28 -> V_58 < 0 ) {
F_14 ( V_5 ) ;
F_17 ( & V_28 -> V_95 , V_33 ) ;
F_8 ( V_111 L_43 ,
V_94 , V_28 -> V_58 ) ;
return V_112 ;
}
V_2 = F_29 ( V_65 , V_52 ) ;
if ( V_2 == NULL ) {
F_14 ( V_5 ) ;
F_17 ( & V_28 -> V_95 , V_33 ) ;
F_8 ( V_111 L_44 ,
V_94 ) ;
return V_112 ;
}
V_90 = V_28 -> V_54 [ V_28 -> V_58 -- ] ;
F_17 ( & V_28 -> V_95 , V_33 ) ;
V_106 = ( T_9 * ) V_2 ;
F_44 ( V_77 ) ;
F_45 ( V_77 , 12 ) ;
V_79 = F_46 ( V_52 -> V_78 , V_77 -> V_113 , V_77 -> V_80 ,
V_82 ) ;
V_28 -> V_59 [ V_90 ] . V_77 = V_77 ;
V_28 -> V_59 [ V_90 ] . V_79 = V_79 ;
V_28 -> V_59 [ V_90 ] . V_80 = V_77 -> V_80 ;
V_106 -> V_69 = 0 ;
V_106 -> V_15 = V_16 ;
V_106 -> V_68 = 0 ;
V_106 -> V_72 = 0 ;
V_106 -> V_21 = 0 ;
V_106 -> V_70 = V_28 -> V_71 ;
V_107 = ( T_10 * ) V_106 -> V_114 ;
V_107 -> V_115 = sizeof( T_3 ) ;
V_107 -> V_116 = 2 * sizeof( T_3 ) ;
V_107 -> V_117 = 0 ;
V_107 -> V_118 [ 0 ] = F_47 ( V_90 ) ;
V_109 = F_48 ( V_77 ) ;
V_107 -> V_119 [ 0 ] = F_47 ( ( V_110 << 16 ) |
( V_109 [ 0 ] << 8 ) |
( V_109 [ 1 ] << 0 ) ) ;
V_107 -> V_119 [ 1 ] = F_47 ( ( V_109 [ 2 ] << 24 ) |
( V_109 [ 3 ] << 16 ) |
( V_109 [ 4 ] << 8 ) |
( V_109 [ 5 ] << 0 ) ) ;
V_108 = ( T_11 * ) & V_107 -> V_119 [ 2 ] ;
V_108 -> V_120 = F_47 (
( ( V_121 |
V_122 |
V_123 |
V_124 |
V_125 |
V_126 |
V_127 ) << V_128 ) |
V_77 -> V_80 ) ;
V_108 -> V_129 . V_130 = F_47 ( ( T_3 ) V_79 ) ;
if ( sizeof( T_12 ) > sizeof( T_3 ) )
V_108 -> V_129 . V_131 = F_47 ( ( T_3 ) ( ( V_132 ) V_79 >> 32 ) ) ;
else
V_108 -> V_129 . V_131 = 0 ;
F_30 ( V_65 , V_52 , V_2 ) ;
V_5 -> V_133 = V_75 ;
F_2 ( ( V_8 V_9 L_45 ,
F_3 ( V_5 ) ,
F_21 ( V_108 -> V_120 ) ) ) ;
return V_134 ;
}
static void
F_49 ( struct V_4 * V_5 , int V_135 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
if ( F_50 ( 0 , & V_28 -> V_136 ) == 0 ) {
if ( V_135 ) {
F_51 ( & V_28 -> V_137 , 0 ) ;
} else {
F_51 ( & V_28 -> V_137 , 1 ) ;
F_2 ( ( V_8 V_9 L_46
L_47 ) ) ;
}
F_2 ( ( V_8 V_9 L_48 ,
F_3 ( V_5 ) ) ) ;
}
}
static int
F_52 ( struct V_4 * V_5 , struct V_88 * V_77 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
V_77 -> V_138 = F_53 ( V_77 , V_5 ) ;
F_2 ( ( V_8 V_9 L_49
L_50 ,
F_3 ( V_5 ) , V_77 -> V_80 ) ) ;
V_5 -> V_91 . V_139 += V_77 -> V_80 ;
V_5 -> V_91 . V_140 ++ ;
V_77 -> V_5 = V_5 ;
F_54 ( V_77 ) ;
F_2 ( ( V_9 L_51 ,
F_33 ( & V_28 -> V_35 ) ) ) ;
if ( F_33 ( & V_28 -> V_35 ) < V_28 -> V_141 )
F_49 ( V_5 , 1 ) ;
F_2 ( ( V_8 V_9 L_52
L_53 ,
F_33 ( & V_28 -> V_35 ) , V_28 -> V_142 ) ) ;
return 0 ;
}
static int
F_7 ( struct V_4 * V_5 , T_3 V_10 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_88 * V_77 , * V_143 ;
unsigned long V_33 ;
T_3 V_90 , V_80 ;
V_90 = F_55 ( V_10 ) ;
V_77 = V_28 -> V_63 [ V_90 ] . V_77 ;
V_80 = F_56 ( V_10 ) ;
if ( V_80 < V_144 ) {
V_143 = V_77 ;
V_77 = (struct V_88 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_58 ( V_52 -> V_78 , V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 , V_81 ) ;
F_59 ( V_143 , F_60 ( V_77 , V_80 ) , V_80 ) ;
F_61 ( V_52 -> V_78 , V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 , V_81 ) ;
goto V_57;
}
F_60 ( V_77 , V_80 ) ;
V_28 -> V_63 [ V_90 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 , V_81 ) ;
V_57:
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_62 ( & V_28 -> V_35 ) ;
V_28 -> V_142 ++ ;
return F_52 ( V_5 , V_77 ) ;
}
static int
F_63 ( struct V_4 * V_5 ,
T_5 * V_19 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
unsigned long V_33 ;
struct V_88 * V_77 ;
T_3 V_90 ;
int V_97 ;
int V_32 ;
V_97 = V_19 -> V_20 ;
F_13 ( ( V_8 V_9 L_55
L_56 , V_97 ) ) ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_97 ; V_32 ++ ) {
V_90 = F_21 ( V_19 -> V_145 [ V_32 ] ) ;
V_77 = V_28 -> V_63 [ V_90 ] . V_77 ;
V_28 -> V_63 [ V_90 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 , V_81 ) ;
F_64 ( V_77 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_65 ( V_97 , & V_28 -> V_35 ) ;
F_13 ( ( V_8 V_9 L_57
L_58 ,
F_33 ( & V_28 -> V_35 ) , V_28 -> V_142 ) ) ;
return 0 ;
}
static int
F_10 ( struct V_4 * V_5 ,
T_5 * V_19 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_88 * V_77 , * V_143 ;
unsigned long V_33 ;
T_3 V_80 , V_90 , V_146 ;
T_3 V_147 = F_21 ( V_19 -> V_148 ) ;
int V_97 ;
int V_32 , V_149 ;
F_2 ( ( V_8 V_9 L_59 ) ) ;
F_2 ( ( V_8 V_9 L_60 ,
F_42 ( V_19 -> V_98 ) ) ) ;
if ( ( F_42 ( V_19 -> V_98 ) & V_99 ) ==
V_101 )
return F_63 ( V_5 , V_19 ) ;
V_80 = F_21 ( V_19 -> V_150 ) ;
if ( V_80 == 0 ) {
F_8 (KERN_ERR MYNAM L_61
L_62 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
F_8 (KERN_ERR MYNAM L_63 ,
pRecvRep->MsgFlags, le16_to_cpu(pRecvRep->IOCStatus)) ;
return - 1 ;
}
V_90 = F_21 ( V_19 -> V_145 [ 0 ] ) ;
V_97 = V_19 -> V_20 ;
V_77 = V_28 -> V_63 [ V_90 ] . V_77 ;
V_146 = F_21 ( V_19 -> V_151 ) ;
F_2 ( ( V_8 V_9 L_64 ,
F_3 ( V_5 ) ,
V_146 , V_80 ) ) ;
if ( V_97 > 1 ) {
int V_152 = V_80 ;
V_77 = (struct V_88 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_16 ( & V_28 -> V_36 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_97 ; V_32 ++ ) {
V_90 = F_21 ( V_19 -> V_145 [ V_32 ] ) ;
V_143 = V_28 -> V_63 [ V_90 ] . V_77 ;
V_149 = V_28 -> V_63 [ V_90 ] . V_80 ;
if ( V_152 < V_149 )
V_149 = V_152 ;
F_58 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 ,
V_81 ) ;
F_59 ( V_143 , F_60 ( V_77 , V_149 ) , V_149 ) ;
F_61 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 ,
V_81 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
V_152 -= V_149 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
} else if ( V_80 < V_144 ) {
V_143 = V_77 ;
V_77 = (struct V_88 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_58 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 ,
V_81 ) ;
F_59 ( V_143 , F_60 ( V_77 , V_80 ) , V_80 ) ;
F_61 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 ,
V_81 ) ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
} else {
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_63 [ V_90 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 , V_81 ) ;
V_28 -> V_63 [ V_90 ] . V_79 = 0 ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_60 ( V_77 , V_80 ) ;
}
F_65 ( V_97 , & V_28 -> V_35 ) ;
V_28 -> V_142 += V_97 ;
if ( V_28 -> V_37 >= V_153 ) {
F_8 (KERN_ERR MYNAM L_65
L_66 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
priv->mpt_rxfidx_tail,
MPT_LAN_MAX_BUCKETS_OUT) ;
return - 1 ;
}
if ( V_147 == 0 )
F_8 (KERN_WARNING MYNAM L_67
L_68 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
atomic_read(&priv->buckets_out)) ;
else if ( V_147 < 10 )
F_8 (KERN_INFO MYNAM L_69
L_68 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
remaining, atomic_read(&priv->buckets_out)) ;
if ( ( V_147 < V_28 -> V_141 ) &&
( ( F_33 ( & V_28 -> V_35 ) - V_147 ) >
V_154 ) ) {
F_8 (KERN_WARNING MYNAM L_70
L_71
L_72
L_73
L_74
L_75 ) ;
F_23 ( V_5 ) ;
F_49 ( V_5 , 0 ) ;
}
return F_52 ( V_5 , V_77 ) ;
}
static void
F_18 ( struct V_27 * V_28 )
{
struct V_4 * V_5 = V_28 -> V_5 ;
T_1 * V_52 = V_28 -> V_52 ;
T_2 * V_2 ;
T_14 * V_155 ;
T_10 * V_107 ;
T_11 * V_108 ;
struct V_88 * V_77 ;
T_12 V_79 ;
T_3 V_156 , V_157 , V_97 , V_158 ;
T_3 V_80 = ( V_5 -> V_87 + V_5 -> V_159 + 4 ) ;
unsigned long V_33 ;
int V_32 ;
V_156 = F_33 ( & V_28 -> V_35 ) ;
V_157 = ( V_28 -> V_38 - V_156 ) ;
F_2 ( ( V_8 V_9 L_76 ,
F_3 ( V_5 ) ,
V_94 , V_157 , V_156 ) ) ;
V_158 = ( V_52 -> V_160 - V_161 ) /
( V_162 + sizeof( T_11 ) ) ;
while ( V_157 ) {
V_2 = F_29 ( V_65 , V_52 ) ;
if ( V_2 == NULL ) {
F_8 ( V_111 L_44 ,
V_94 ) ;
F_2 ( ( V_111 L_77 ,
V_94 , V_157 ) ) ;
goto V_57;
}
V_155 = ( T_14 * ) V_2 ;
V_32 = F_42 ( V_2 -> V_13 . V_163 . V_164 . V_165 . V_166 . V_167 ) ;
V_52 -> V_168 [ V_32 ] = 0 ;
V_97 = V_157 ;
if ( V_97 > V_158 )
V_97 = V_158 ;
V_155 -> V_15 = V_18 ;
V_155 -> V_68 = 0 ;
V_155 -> V_21 = 0 ;
V_155 -> V_70 = V_28 -> V_71 ;
V_107 = ( T_10 * ) V_155 -> V_114 ;
V_108 = NULL ;
for ( V_32 = 0 ; V_32 < V_97 ; V_32 ++ ) {
int V_90 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
if ( V_28 -> V_37 < 0 ) {
F_8 ( V_111 L_78 ,
V_94 ) ;
F_17 ( & V_28 -> V_36 ,
V_33 ) ;
break;
}
V_90 = V_28 -> V_31 [ V_28 -> V_37 -- ] ;
V_77 = V_28 -> V_63 [ V_90 ] . V_77 ;
if ( V_77 && ( V_28 -> V_63 [ V_90 ] . V_80 != V_80 ) ) {
F_36 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_90 ] . V_79 ,
V_28 -> V_63 [ V_90 ] . V_80 ,
V_81 ) ;
F_37 ( V_28 -> V_63 [ V_90 ] . V_77 ) ;
V_77 = V_28 -> V_63 [ V_90 ] . V_77 = NULL ;
}
if ( V_77 == NULL ) {
V_77 = F_57 ( V_80 ) ;
if ( V_77 == NULL ) {
F_8 (KERN_WARNING
MYNAM L_79 ,
__func__) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_90 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
break;
}
V_79 = F_46 ( V_52 -> V_78 , V_77 -> V_113 ,
V_80 , V_81 ) ;
V_28 -> V_63 [ V_90 ] . V_77 = V_77 ;
V_28 -> V_63 [ V_90 ] . V_79 = V_79 ;
V_28 -> V_63 [ V_90 ] . V_80 = V_80 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
V_107 -> V_115 = sizeof( T_3 ) ;
V_107 -> V_116 = 0 ;
V_107 -> V_117 = 0 ;
V_107 -> V_118 [ 0 ] = F_47 ( V_90 ) ;
V_108 = ( T_11 * ) V_107 -> V_119 ;
V_108 -> V_120 = F_47 (
( ( V_122 |
V_123 |
V_126 ) << V_128 ) | V_80 ) ;
V_108 -> V_129 . V_130 = F_47 ( ( T_3 ) V_28 -> V_63 [ V_90 ] . V_79 ) ;
if ( sizeof( T_12 ) > sizeof( T_3 ) )
V_108 -> V_129 . V_131 = F_47 ( ( T_3 ) ( ( V_132 ) V_28 -> V_63 [ V_90 ] . V_79 >> 32 ) ) ;
else
V_108 -> V_129 . V_131 = 0 ;
V_107 = ( T_10 * ) ( V_108 + 1 ) ;
}
if ( V_108 == NULL ) {
F_8 (KERN_WARNING MYNAM L_80 ,
__func__) ;
F_66 ( V_52 , V_2 ) ;
goto V_57;
}
V_108 -> V_120 |= F_47 ( V_127 << V_128 ) ;
V_155 -> V_169 = F_47 ( V_32 ) ;
F_30 ( V_65 , V_52 , V_2 ) ;
V_28 -> V_74 += V_32 ;
V_157 -= V_32 ;
F_67 ( V_32 , & V_28 -> V_35 ) ;
}
V_57:
F_2 ( ( V_8 V_9 L_81 ,
V_94 , V_157 , F_33 ( & V_28 -> V_35 ) ) ) ;
F_2 ( ( V_8 V_9 L_82 ,
V_94 , V_28 -> V_74 , V_28 -> V_142 ) ) ;
F_68 ( 0 , & V_28 -> V_136 ) ;
}
static void
F_69 ( struct V_170 * V_171 )
{
F_18 ( F_70 ( V_171 , struct V_27 ,
V_137 . V_171 ) ) ;
}
static struct V_4 *
F_71 ( T_1 * V_52 , int V_71 )
{
struct V_4 * V_5 ;
struct V_27 * V_28 ;
T_8 V_172 [ V_173 ] , * V_174 ;
V_5 = F_72 ( sizeof( struct V_27 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_87 = V_175 ;
V_28 = F_12 ( V_5 ) ;
V_28 -> V_5 = V_5 ;
V_28 -> V_52 = V_52 ;
V_28 -> V_71 = V_71 ;
F_73 ( & V_28 -> V_137 ,
F_69 ) ;
V_28 -> V_136 = 0 ;
F_13 ( ( V_8 V_9 L_83 ,
__LINE__ , V_5 -> V_87 + V_5 -> V_159 + 4 ) ) ;
F_15 ( & V_28 -> V_35 , 0 ) ;
V_28 -> V_74 = 0 ;
V_28 -> V_142 = 0 ;
V_28 -> V_38 = V_38 ;
if ( V_52 -> V_176 [ 0 ] . V_177 < V_38 )
V_28 -> V_38 = V_52 -> V_176 [ 0 ] . V_177 ;
F_13 ( ( V_8 V_9 L_84 ,
__LINE__ ,
V_52 -> V_176 [ 0 ] . V_177 ,
V_38 ,
V_28 -> V_38 ) ) ;
V_28 -> V_141 = V_28 -> V_38 * 2 / 3 ;
F_74 ( & V_28 -> V_95 ) ;
F_74 ( & V_28 -> V_36 ) ;
V_174 = ( T_8 * ) & V_52 -> V_178 . V_179 ;
V_172 [ 0 ] = V_174 [ 5 ] ;
V_172 [ 1 ] = V_174 [ 4 ] ;
V_172 [ 2 ] = V_174 [ 3 ] ;
V_172 [ 3 ] = V_174 [ 2 ] ;
V_172 [ 4 ] = V_174 [ 1 ] ;
V_172 [ 5 ] = V_174 [ 0 ] ;
V_5 -> V_180 = V_173 ;
memcpy ( V_5 -> V_181 , V_172 , V_173 ) ;
memset ( V_5 -> V_182 , 0xff , V_173 ) ;
V_28 -> V_55 = ( V_183 <= V_184 ) ?
V_183 : V_184 ;
V_5 -> V_185 = & V_186 ;
V_5 -> V_187 = V_188 ;
F_13 ( ( V_8 V_9 L_85
L_86 ) ) ;
if ( F_75 ( V_5 ) != 0 ) {
F_76 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static int
F_77 ( struct V_189 * V_190 , const struct V_191 * V_192 )
{
T_1 * V_1 = F_78 ( V_190 ) ;
struct V_4 * V_5 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_1 -> V_193 . V_194 ; V_32 ++ ) {
F_8 (KERN_INFO MYNAM L_87
L_88 ,
ioc->name, ioc->pfacts[i].PortNumber,
ioc->pfacts[i].ProtocolFlags,
MPT_PROTOCOL_FLAGS_c_c_c_c(
ioc->pfacts[i].ProtocolFlags)) ;
if ( ! ( V_1 -> V_176 [ V_32 ] . V_195 &
V_196 ) ) {
F_8 (KERN_INFO MYNAM L_89
L_90 ,
ioc->name) ;
continue;
}
V_5 = F_71 ( V_1 , V_32 ) ;
if ( ! V_5 ) {
F_8 (KERN_ERR MYNAM L_91
L_92 , ioc->name,
ioc->pfacts[i].PortNumber) ;
continue;
}
F_8 (KERN_INFO MYNAM L_93
L_94 , ioc->name, dev->name) ;
F_8 (KERN_INFO MYNAM L_95
L_96 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
dev->dev_addr) ;
V_1 -> V_6 = V_5 ;
return 0 ;
}
return - V_197 ;
}
static void
F_79 ( struct V_189 * V_190 )
{
T_1 * V_1 = F_78 ( V_190 ) ;
struct V_4 * V_5 = V_1 -> V_6 ;
if( V_5 != NULL ) {
F_80 ( V_5 ) ;
F_76 ( V_5 ) ;
}
}
static int T_15 F_81 ( void )
{
F_82 ( V_198 , V_199 ) ;
V_65 = F_83 ( F_1 , V_200 ,
L_97 ) ;
if ( V_65 <= 0 ) {
F_8 (KERN_ERR MYNAM L_98 ) ;
return - V_201 ;
}
F_13 ( ( V_8 V_9 L_99 , V_65 ) ) ;
if ( F_84 ( V_65 , F_11 ) ) {
F_8 (KERN_ERR MYNAM L_100
L_101
L_102 ) ;
return - V_201 ;
}
F_13 ( ( V_8 V_9 L_103 ) ) ;
F_85 ( & V_202 , V_200 ) ;
return 0 ;
}
static void T_16 F_86 ( void )
{
F_87 ( V_200 ) ;
F_88 ( V_65 ) ;
if ( V_65 ) {
F_89 ( V_65 ) ;
V_65 = V_203 ;
}
}
static unsigned short
F_53 ( struct V_88 * V_77 , struct V_4 * V_5 )
{
struct V_204 * V_205 = (struct V_204 * ) V_77 -> V_113 ;
struct V_206 * V_206 ;
F_44 ( V_77 ) ;
F_45 ( V_77 , sizeof( struct V_204 ) ) ;
if ( V_205 -> V_207 == F_90 ( 0xffff ) ) {
T_3 * V_208 = ( T_3 * ) V_205 ;
F_91 ( V_208 + 0 ) ;
F_91 ( V_208 + 1 ) ;
F_91 ( V_208 + 2 ) ;
F_91 ( V_208 + 3 ) ;
F_8 (KERN_WARNING MYNAM L_104 ,
NETDEV_PTR_TO_IOC_NAME_s(dev)) ;
F_8 (KERN_WARNING MYNAM L_105 ,
fch->saddr) ;
}
if ( * V_205 -> V_209 & 1 ) {
if ( ! memcmp ( V_205 -> V_209 , V_5 -> V_182 , V_173 ) ) {
V_77 -> V_210 = V_211 ;
} else {
V_77 -> V_210 = V_212 ;
}
} else {
if ( memcmp ( V_205 -> V_209 , V_5 -> V_181 , V_173 ) ) {
V_77 -> V_210 = V_213 ;
} else {
V_77 -> V_210 = V_214 ;
}
}
V_206 = (struct V_206 * ) V_77 -> V_113 ;
if ( V_206 -> V_215 == V_216 &&
( V_206 -> V_217 == F_90 ( V_218 ) ||
V_206 -> V_217 == F_90 ( V_219 ) ) ) {
F_45 ( V_77 , sizeof( struct V_206 ) ) ;
return V_206 -> V_217 ;
}
return F_90 ( V_220 ) ;
}
