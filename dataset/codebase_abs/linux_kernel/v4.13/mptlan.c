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
static void
F_38 ( struct V_4 * V_5 )
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
struct V_83 * V_84 ;
unsigned long V_33 ;
T_3 V_85 ;
V_85 = F_39 ( V_10 ) ;
V_84 = V_28 -> V_59 [ V_85 ] . V_77 ;
V_5 -> V_86 . V_87 ++ ;
V_5 -> V_86 . V_88 += V_84 -> V_80 ;
F_2 ( ( V_8 V_9 L_39 ,
F_3 ( V_5 ) ,
V_89 , V_84 ) ) ;
V_28 -> V_59 [ V_85 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_59 [ V_85 ] . V_79 ,
V_28 -> V_59 [ V_85 ] . V_80 , V_82 ) ;
F_40 ( V_84 ) ;
F_16 ( & V_28 -> V_90 , V_33 ) ;
V_28 -> V_54 [ ++ V_28 -> V_58 ] = V_85 ;
F_17 ( & V_28 -> V_90 , V_33 ) ;
F_19 ( V_5 ) ;
return 0 ;
}
static int
F_9 ( struct V_4 * V_5 , T_4 * V_17 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_83 * V_84 ;
unsigned long V_33 ;
int V_7 = 0 ;
T_3 * V_91 ;
T_3 V_85 ;
T_8 V_92 ;
V_92 = V_17 -> V_20 ;
F_2 ( ( V_8 V_9 L_40 ,
F_41 ( V_17 -> V_93 ) ) ) ;
switch ( F_41 ( V_17 -> V_93 ) & V_94 ) {
case V_95 :
V_5 -> V_86 . V_87 += V_92 ;
break;
case V_96 :
case V_97 :
break;
case V_98 :
V_5 -> V_86 . V_99 += V_92 ;
F_8 (KERN_ERR MYNAM L_41 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
goto V_57;
default:
V_5 -> V_86 . V_99 += V_92 ;
break;
}
V_91 = & V_17 -> V_100 ;
F_16 ( & V_28 -> V_90 , V_33 ) ;
while ( V_92 > 0 ) {
V_85 = F_39 ( F_21 ( * V_91 ) ) ;
V_84 = V_28 -> V_59 [ V_85 ] . V_77 ;
V_5 -> V_86 . V_88 += V_84 -> V_80 ;
F_2 ( ( V_8 V_9 L_39 ,
F_3 ( V_5 ) ,
V_89 , V_84 ) ) ;
V_28 -> V_59 [ V_85 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_59 [ V_85 ] . V_79 ,
V_28 -> V_59 [ V_85 ] . V_80 , V_82 ) ;
F_40 ( V_84 ) ;
V_28 -> V_54 [ ++ V_28 -> V_58 ] = V_85 ;
V_91 ++ ;
V_92 -- ;
}
F_17 ( & V_28 -> V_90 , V_33 ) ;
V_57:
if ( ! ( V_17 -> V_21 & V_22 ) )
V_7 = 1 ;
F_19 ( V_5 ) ;
return V_7 ;
}
static int
F_42 ( struct V_83 * V_77 , struct V_4 * V_5 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
T_2 * V_2 ;
T_9 * V_101 ;
T_10 * V_102 ;
T_11 * V_103 ;
const unsigned char * V_104 ;
T_12 V_79 ;
unsigned long V_33 ;
int V_85 ;
T_13 V_105 = 0x1000 ;
F_2 ( ( V_8 V_9 L_42 ,
V_89 , V_77 ) ) ;
F_16 ( & V_28 -> V_90 , V_33 ) ;
if ( V_28 -> V_58 < 0 ) {
F_14 ( V_5 ) ;
F_17 ( & V_28 -> V_90 , V_33 ) ;
F_8 ( V_106 L_43 ,
V_89 , V_28 -> V_58 ) ;
return V_107 ;
}
V_2 = F_29 ( V_65 , V_52 ) ;
if ( V_2 == NULL ) {
F_14 ( V_5 ) ;
F_17 ( & V_28 -> V_90 , V_33 ) ;
F_8 ( V_106 L_44 ,
V_89 ) ;
return V_107 ;
}
V_85 = V_28 -> V_54 [ V_28 -> V_58 -- ] ;
F_17 ( & V_28 -> V_90 , V_33 ) ;
V_101 = ( T_9 * ) V_2 ;
F_43 ( V_77 ) ;
F_44 ( V_77 , 12 ) ;
V_79 = F_45 ( V_52 -> V_78 , V_77 -> V_108 , V_77 -> V_80 ,
V_82 ) ;
V_28 -> V_59 [ V_85 ] . V_77 = V_77 ;
V_28 -> V_59 [ V_85 ] . V_79 = V_79 ;
V_28 -> V_59 [ V_85 ] . V_80 = V_77 -> V_80 ;
V_101 -> V_69 = 0 ;
V_101 -> V_15 = V_16 ;
V_101 -> V_68 = 0 ;
V_101 -> V_72 = 0 ;
V_101 -> V_21 = 0 ;
V_101 -> V_70 = V_28 -> V_71 ;
V_102 = ( T_10 * ) V_101 -> V_109 ;
V_102 -> V_110 = sizeof( T_3 ) ;
V_102 -> V_111 = 2 * sizeof( T_3 ) ;
V_102 -> V_112 = 0 ;
V_102 -> V_113 [ 0 ] = F_46 ( V_85 ) ;
V_104 = F_47 ( V_77 ) ;
V_102 -> V_114 [ 0 ] = F_46 ( ( V_105 << 16 ) |
( V_104 [ 0 ] << 8 ) |
( V_104 [ 1 ] << 0 ) ) ;
V_102 -> V_114 [ 1 ] = F_46 ( ( V_104 [ 2 ] << 24 ) |
( V_104 [ 3 ] << 16 ) |
( V_104 [ 4 ] << 8 ) |
( V_104 [ 5 ] << 0 ) ) ;
V_103 = ( T_11 * ) & V_102 -> V_114 [ 2 ] ;
V_103 -> V_115 = F_46 (
( ( V_116 |
V_117 |
V_118 |
V_119 |
V_120 |
V_121 |
V_122 ) << V_123 ) |
V_77 -> V_80 ) ;
V_103 -> V_124 . V_125 = F_46 ( ( T_3 ) V_79 ) ;
if ( sizeof( T_12 ) > sizeof( T_3 ) )
V_103 -> V_124 . V_126 = F_46 ( ( T_3 ) ( ( V_127 ) V_79 >> 32 ) ) ;
else
V_103 -> V_124 . V_126 = 0 ;
F_30 ( V_65 , V_52 , V_2 ) ;
F_48 ( V_5 ) ;
F_2 ( ( V_8 V_9 L_45 ,
F_3 ( V_5 ) ,
F_21 ( V_103 -> V_115 ) ) ) ;
return V_128 ;
}
static void
F_49 ( struct V_4 * V_5 , int V_129 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
if ( F_50 ( 0 , & V_28 -> V_130 ) == 0 ) {
if ( V_129 ) {
F_51 ( & V_28 -> V_131 , 0 ) ;
} else {
F_51 ( & V_28 -> V_131 , 1 ) ;
F_2 ( ( V_8 V_9 L_46
L_47 ) ) ;
}
F_2 ( ( V_8 V_9 L_48 ,
F_3 ( V_5 ) ) ) ;
}
}
static int
F_52 ( struct V_4 * V_5 , struct V_83 * V_77 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
V_77 -> V_132 = F_53 ( V_77 , V_5 ) ;
F_2 ( ( V_8 V_9 L_49
L_50 ,
F_3 ( V_5 ) , V_77 -> V_80 ) ) ;
V_5 -> V_86 . V_133 += V_77 -> V_80 ;
V_5 -> V_86 . V_134 ++ ;
V_77 -> V_5 = V_5 ;
F_54 ( V_77 ) ;
F_2 ( ( V_9 L_51 ,
F_33 ( & V_28 -> V_35 ) ) ) ;
if ( F_33 ( & V_28 -> V_35 ) < V_28 -> V_135 )
F_49 ( V_5 , 1 ) ;
F_2 ( ( V_8 V_9 L_52
L_53 ,
F_33 ( & V_28 -> V_35 ) , V_28 -> V_136 ) ) ;
return 0 ;
}
static int
F_7 ( struct V_4 * V_5 , T_3 V_10 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_83 * V_77 , * V_137 ;
unsigned long V_33 ;
T_3 V_85 , V_80 ;
V_85 = F_55 ( V_10 ) ;
V_77 = V_28 -> V_63 [ V_85 ] . V_77 ;
V_80 = F_56 ( V_10 ) ;
if ( V_80 < V_138 ) {
V_137 = V_77 ;
V_77 = (struct V_83 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_58 ( V_52 -> V_78 , V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 , V_81 ) ;
F_59 ( V_137 , F_60 ( V_77 , V_80 ) , V_80 ) ;
F_61 ( V_52 -> V_78 , V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 , V_81 ) ;
goto V_57;
}
F_60 ( V_77 , V_80 ) ;
V_28 -> V_63 [ V_85 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 , V_81 ) ;
V_57:
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_62 ( & V_28 -> V_35 ) ;
V_28 -> V_136 ++ ;
return F_52 ( V_5 , V_77 ) ;
}
static int
F_63 ( struct V_4 * V_5 ,
T_5 * V_19 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
unsigned long V_33 ;
struct V_83 * V_77 ;
T_3 V_85 ;
int V_92 ;
int V_32 ;
V_92 = V_19 -> V_20 ;
F_13 ( ( V_8 V_9 L_55
L_56 , V_92 ) ) ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_92 ; V_32 ++ ) {
V_85 = F_21 ( V_19 -> V_139 [ V_32 ] ) ;
V_77 = V_28 -> V_63 [ V_85 ] . V_77 ;
V_28 -> V_63 [ V_85 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 , V_81 ) ;
F_64 ( V_77 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_65 ( V_92 , & V_28 -> V_35 ) ;
F_13 ( ( V_8 V_9 L_57
L_58 ,
F_33 ( & V_28 -> V_35 ) , V_28 -> V_136 ) ) ;
return 0 ;
}
static int
F_10 ( struct V_4 * V_5 ,
T_5 * V_19 )
{
struct V_27 * V_28 = F_12 ( V_5 ) ;
T_1 * V_52 = V_28 -> V_52 ;
struct V_83 * V_77 , * V_137 ;
unsigned long V_33 ;
T_3 V_80 , V_85 , V_140 ;
T_3 V_141 = F_21 ( V_19 -> V_142 ) ;
int V_92 ;
int V_32 , V_143 ;
F_2 ( ( V_8 V_9 L_59 ) ) ;
F_2 ( ( V_8 V_9 L_60 ,
F_41 ( V_19 -> V_93 ) ) ) ;
if ( ( F_41 ( V_19 -> V_93 ) & V_94 ) ==
V_96 )
return F_63 ( V_5 , V_19 ) ;
V_80 = F_21 ( V_19 -> V_144 ) ;
if ( V_80 == 0 ) {
F_8 (KERN_ERR MYNAM L_61
L_62 ,
IOC_AND_NETDEV_NAMES_s_s(dev)) ;
F_8 (KERN_ERR MYNAM L_63 ,
pRecvRep->MsgFlags, le16_to_cpu(pRecvRep->IOCStatus)) ;
return - 1 ;
}
V_85 = F_21 ( V_19 -> V_139 [ 0 ] ) ;
V_92 = V_19 -> V_20 ;
V_77 = V_28 -> V_63 [ V_85 ] . V_77 ;
V_140 = F_21 ( V_19 -> V_145 ) ;
F_2 ( ( V_8 V_9 L_64 ,
F_3 ( V_5 ) ,
V_140 , V_80 ) ) ;
if ( V_92 > 1 ) {
int V_146 = V_80 ;
V_77 = (struct V_83 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_16 ( & V_28 -> V_36 , V_33 ) ;
for ( V_32 = 0 ; V_32 < V_92 ; V_32 ++ ) {
V_85 = F_21 ( V_19 -> V_139 [ V_32 ] ) ;
V_137 = V_28 -> V_63 [ V_85 ] . V_77 ;
V_143 = V_28 -> V_63 [ V_85 ] . V_80 ;
if ( V_146 < V_143 )
V_143 = V_146 ;
F_58 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 ,
V_81 ) ;
F_59 ( V_137 , F_60 ( V_77 , V_143 ) , V_143 ) ;
F_61 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 ,
V_81 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
V_146 -= V_143 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
} else if ( V_80 < V_138 ) {
V_137 = V_77 ;
V_77 = (struct V_83 * ) F_57 ( V_80 ) ;
if ( ! V_77 ) {
F_8 (KERN_ERR MYNAM L_54 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
__FILE__, __LINE__) ;
return - V_66 ;
}
F_58 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 ,
V_81 ) ;
F_59 ( V_137 , F_60 ( V_77 , V_80 ) , V_80 ) ;
F_61 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 ,
V_81 ) ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
} else {
F_16 ( & V_28 -> V_36 , V_33 ) ;
V_28 -> V_63 [ V_85 ] . V_77 = NULL ;
F_36 ( V_52 -> V_78 , V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 , V_81 ) ;
V_28 -> V_63 [ V_85 ] . V_79 = 0 ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
F_60 ( V_77 , V_80 ) ;
}
F_65 ( V_92 , & V_28 -> V_35 ) ;
V_28 -> V_136 += V_92 ;
if ( V_28 -> V_37 >= V_147 ) {
F_8 (KERN_ERR MYNAM L_65
L_66 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
priv->mpt_rxfidx_tail,
MPT_LAN_MAX_BUCKETS_OUT) ;
return - 1 ;
}
if ( V_141 == 0 )
F_8 (KERN_WARNING MYNAM L_67
L_68 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
atomic_read(&priv->buckets_out)) ;
else if ( V_141 < 10 )
F_8 (KERN_INFO MYNAM L_69
L_68 ,
IOC_AND_NETDEV_NAMES_s_s(dev),
remaining, atomic_read(&priv->buckets_out)) ;
if ( ( V_141 < V_28 -> V_135 ) &&
( ( F_33 ( & V_28 -> V_35 ) - V_141 ) >
V_148 ) ) {
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
T_14 * V_149 ;
T_10 * V_102 ;
T_11 * V_103 ;
struct V_83 * V_77 ;
T_12 V_79 ;
T_3 V_150 , V_151 , V_92 , V_152 ;
T_3 V_80 = ( V_5 -> V_153 + V_5 -> V_154 + 4 ) ;
unsigned long V_33 ;
int V_32 ;
V_150 = F_33 ( & V_28 -> V_35 ) ;
V_151 = ( V_28 -> V_38 - V_150 ) ;
F_2 ( ( V_8 V_9 L_76 ,
F_3 ( V_5 ) ,
V_89 , V_151 , V_150 ) ) ;
V_152 = ( V_52 -> V_155 - V_156 ) /
( V_157 + sizeof( T_11 ) ) ;
while ( V_151 ) {
V_2 = F_29 ( V_65 , V_52 ) ;
if ( V_2 == NULL ) {
F_8 ( V_106 L_44 ,
V_89 ) ;
F_2 ( ( V_106 L_77 ,
V_89 , V_151 ) ) ;
goto V_57;
}
V_149 = ( T_14 * ) V_2 ;
V_32 = F_41 ( V_2 -> V_13 . V_158 . V_159 . V_160 . V_161 . V_162 ) ;
V_52 -> V_163 [ V_32 ] = 0 ;
V_92 = V_151 ;
if ( V_92 > V_152 )
V_92 = V_152 ;
V_149 -> V_15 = V_18 ;
V_149 -> V_68 = 0 ;
V_149 -> V_21 = 0 ;
V_149 -> V_70 = V_28 -> V_71 ;
V_102 = ( T_10 * ) V_149 -> V_109 ;
V_103 = NULL ;
for ( V_32 = 0 ; V_32 < V_92 ; V_32 ++ ) {
int V_85 ;
F_16 ( & V_28 -> V_36 , V_33 ) ;
if ( V_28 -> V_37 < 0 ) {
F_8 ( V_106 L_78 ,
V_89 ) ;
F_17 ( & V_28 -> V_36 ,
V_33 ) ;
break;
}
V_85 = V_28 -> V_31 [ V_28 -> V_37 -- ] ;
V_77 = V_28 -> V_63 [ V_85 ] . V_77 ;
if ( V_77 && ( V_28 -> V_63 [ V_85 ] . V_80 != V_80 ) ) {
F_36 ( V_52 -> V_78 ,
V_28 -> V_63 [ V_85 ] . V_79 ,
V_28 -> V_63 [ V_85 ] . V_80 ,
V_81 ) ;
F_37 ( V_28 -> V_63 [ V_85 ] . V_77 ) ;
V_77 = V_28 -> V_63 [ V_85 ] . V_77 = NULL ;
}
if ( V_77 == NULL ) {
V_77 = F_57 ( V_80 ) ;
if ( V_77 == NULL ) {
F_8 (KERN_WARNING
MYNAM L_79 ,
__func__) ;
V_28 -> V_31 [ ++ V_28 -> V_37 ] = V_85 ;
F_17 ( & V_28 -> V_36 , V_33 ) ;
break;
}
V_79 = F_45 ( V_52 -> V_78 , V_77 -> V_108 ,
V_80 , V_81 ) ;
V_28 -> V_63 [ V_85 ] . V_77 = V_77 ;
V_28 -> V_63 [ V_85 ] . V_79 = V_79 ;
V_28 -> V_63 [ V_85 ] . V_80 = V_80 ;
}
F_17 ( & V_28 -> V_36 , V_33 ) ;
V_102 -> V_110 = sizeof( T_3 ) ;
V_102 -> V_111 = 0 ;
V_102 -> V_112 = 0 ;
V_102 -> V_113 [ 0 ] = F_46 ( V_85 ) ;
V_103 = ( T_11 * ) V_102 -> V_114 ;
V_103 -> V_115 = F_46 (
( ( V_117 |
V_118 |
V_121 ) << V_123 ) | V_80 ) ;
V_103 -> V_124 . V_125 = F_46 ( ( T_3 ) V_28 -> V_63 [ V_85 ] . V_79 ) ;
if ( sizeof( T_12 ) > sizeof( T_3 ) )
V_103 -> V_124 . V_126 = F_46 ( ( T_3 ) ( ( V_127 ) V_28 -> V_63 [ V_85 ] . V_79 >> 32 ) ) ;
else
V_103 -> V_124 . V_126 = 0 ;
V_102 = ( T_10 * ) ( V_103 + 1 ) ;
}
if ( V_103 == NULL ) {
F_8 (KERN_WARNING MYNAM L_80 ,
__func__) ;
F_66 ( V_52 , V_2 ) ;
goto V_57;
}
V_103 -> V_115 |= F_46 ( V_122 << V_123 ) ;
V_149 -> V_164 = F_46 ( V_32 ) ;
F_30 ( V_65 , V_52 , V_2 ) ;
V_28 -> V_74 += V_32 ;
V_151 -= V_32 ;
F_67 ( V_32 , & V_28 -> V_35 ) ;
}
V_57:
F_2 ( ( V_8 V_9 L_81 ,
V_89 , V_151 , F_33 ( & V_28 -> V_35 ) ) ) ;
F_2 ( ( V_8 V_9 L_82 ,
V_89 , V_28 -> V_74 , V_28 -> V_136 ) ) ;
F_68 ( 0 , & V_28 -> V_130 ) ;
}
static void
F_69 ( struct V_165 * V_166 )
{
F_18 ( F_70 ( V_166 , struct V_27 ,
V_131 . V_166 ) ) ;
}
static struct V_4 *
F_71 ( T_1 * V_52 , int V_71 )
{
struct V_4 * V_5 ;
struct V_27 * V_28 ;
T_8 V_167 [ V_168 ] , * V_169 ;
V_5 = F_72 ( sizeof( struct V_27 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_153 = V_170 ;
V_28 = F_12 ( V_5 ) ;
V_28 -> V_5 = V_5 ;
V_28 -> V_52 = V_52 ;
V_28 -> V_71 = V_71 ;
F_73 ( & V_28 -> V_131 ,
F_69 ) ;
V_28 -> V_130 = 0 ;
F_13 ( ( V_8 V_9 L_83 ,
__LINE__ , V_5 -> V_153 + V_5 -> V_154 + 4 ) ) ;
F_15 ( & V_28 -> V_35 , 0 ) ;
V_28 -> V_74 = 0 ;
V_28 -> V_136 = 0 ;
V_28 -> V_38 = V_38 ;
if ( V_52 -> V_171 [ 0 ] . V_172 < V_38 )
V_28 -> V_38 = V_52 -> V_171 [ 0 ] . V_172 ;
F_13 ( ( V_8 V_9 L_84 ,
__LINE__ ,
V_52 -> V_171 [ 0 ] . V_172 ,
V_38 ,
V_28 -> V_38 ) ) ;
V_28 -> V_135 = V_28 -> V_38 * 2 / 3 ;
F_74 ( & V_28 -> V_90 ) ;
F_74 ( & V_28 -> V_36 ) ;
V_169 = ( T_8 * ) & V_52 -> V_173 . V_174 ;
V_167 [ 0 ] = V_169 [ 5 ] ;
V_167 [ 1 ] = V_169 [ 4 ] ;
V_167 [ 2 ] = V_169 [ 3 ] ;
V_167 [ 3 ] = V_169 [ 2 ] ;
V_167 [ 4 ] = V_169 [ 1 ] ;
V_167 [ 5 ] = V_169 [ 0 ] ;
V_5 -> V_175 = V_168 ;
memcpy ( V_5 -> V_176 , V_167 , V_168 ) ;
memset ( V_5 -> V_177 , 0xff , V_168 ) ;
V_28 -> V_55 = ( V_178 <= V_179 ) ?
V_178 : V_179 ;
V_5 -> V_180 = & V_181 ;
V_5 -> V_182 = V_183 ;
V_5 -> V_184 = V_185 ;
V_5 -> V_186 = V_187 ;
F_13 ( ( V_8 V_9 L_85
L_86 ) ) ;
if ( F_75 ( V_5 ) != 0 ) {
F_76 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static int
F_77 ( struct V_188 * V_189 , const struct V_190 * V_191 )
{
T_1 * V_1 = F_78 ( V_189 ) ;
struct V_4 * V_5 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_1 -> V_192 . V_193 ; V_32 ++ ) {
F_8 (KERN_INFO MYNAM L_87
L_88 ,
ioc->name, ioc->pfacts[i].PortNumber,
ioc->pfacts[i].ProtocolFlags,
MPT_PROTOCOL_FLAGS_c_c_c_c(
ioc->pfacts[i].ProtocolFlags)) ;
if ( ! ( V_1 -> V_171 [ V_32 ] . V_194 &
V_195 ) ) {
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
return - V_196 ;
}
static void
F_79 ( struct V_188 * V_189 )
{
T_1 * V_1 = F_78 ( V_189 ) ;
struct V_4 * V_5 = V_1 -> V_6 ;
if( V_5 != NULL ) {
F_80 ( V_5 ) ;
F_76 ( V_5 ) ;
}
}
static int T_15 F_81 ( void )
{
F_82 ( V_197 , V_198 ) ;
V_65 = F_83 ( F_1 , V_199 ,
L_97 ) ;
if ( V_65 <= 0 ) {
F_8 (KERN_ERR MYNAM L_98 ) ;
return - V_200 ;
}
F_13 ( ( V_8 V_9 L_99 , V_65 ) ) ;
if ( F_84 ( V_65 , F_11 ) ) {
F_8 (KERN_ERR MYNAM L_100
L_101
L_102 ) ;
return - V_200 ;
}
F_13 ( ( V_8 V_9 L_103 ) ) ;
F_85 ( & V_201 , V_199 ) ;
return 0 ;
}
static void T_16 F_86 ( void )
{
F_87 ( V_199 ) ;
F_88 ( V_65 ) ;
if ( V_65 ) {
F_89 ( V_65 ) ;
V_65 = V_202 ;
}
}
static unsigned short
F_53 ( struct V_83 * V_77 , struct V_4 * V_5 )
{
struct V_203 * V_204 = (struct V_203 * ) V_77 -> V_108 ;
struct V_205 * V_205 ;
F_43 ( V_77 ) ;
F_44 ( V_77 , sizeof( struct V_203 ) ) ;
if ( V_204 -> V_206 == F_90 ( 0xffff ) ) {
T_3 * V_207 = ( T_3 * ) V_204 ;
F_91 ( V_207 + 0 ) ;
F_91 ( V_207 + 1 ) ;
F_91 ( V_207 + 2 ) ;
F_91 ( V_207 + 3 ) ;
F_8 (KERN_WARNING MYNAM L_104 ,
NETDEV_PTR_TO_IOC_NAME_s(dev)) ;
F_8 (KERN_WARNING MYNAM L_105 ,
fch->saddr) ;
}
if ( * V_204 -> V_208 & 1 ) {
if ( ! memcmp ( V_204 -> V_208 , V_5 -> V_177 , V_168 ) ) {
V_77 -> V_209 = V_210 ;
} else {
V_77 -> V_209 = V_211 ;
}
} else {
if ( memcmp ( V_204 -> V_208 , V_5 -> V_176 , V_168 ) ) {
V_77 -> V_209 = V_212 ;
} else {
V_77 -> V_209 = V_213 ;
}
}
V_205 = (struct V_205 * ) V_77 -> V_108 ;
if ( V_205 -> V_214 == V_215 &&
( V_205 -> V_216 == F_90 ( V_217 ) ||
V_205 -> V_216 == F_90 ( V_218 ) ) ) {
F_44 ( V_77 , sizeof( struct V_205 ) ) ;
return V_205 -> V_216 ;
}
return F_90 ( V_219 ) ;
}
