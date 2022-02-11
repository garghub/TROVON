static inline void F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( V_2 -> V_4 ) {
F_2 ( V_2 , (struct V_5 * ) V_3 ) ;
} else {
F_3 ( V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
F_7 ( V_2 ) ;
}
static struct V_6 * F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = NULL ;
F_5 ( V_2 ) ;
V_7 = F_9 ( & V_2 -> V_8 ) ;
F_7 ( V_2 ) ;
return V_7 ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 Type ,
int V_9 )
{
int V_10 , V_11 ;
void * V_12 = NULL ;
struct V_13 V_14 ;
struct V_6 * V_7 ;
F_11 ( & V_14 ) ;
if ( Type == V_15 ) {
if ( V_2 -> V_4 ) {
V_10 = V_16 ;
} else {
V_10 = V_17 ;
}
} else {
V_10 = V_18 ;
}
V_10 += V_2 -> V_19 . V_20 + V_2 -> V_19 . V_21 ;
V_10 = F_12 ( V_10 , V_2 -> V_19 . V_22 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
if ( V_2 -> V_4 ) {
V_12 = F_13 ( V_2 , V_10 ) ;
} else {
V_12 = F_14 ( V_10 ) ;
}
if ( NULL == V_12 ) {
break;
}
V_7 = F_8 ( V_2 ) ;
if ( NULL == V_7 ) {
F_1 ( V_2 , V_12 ) ;
F_15 ( V_23 , ( L_1 ) ) ;
break;
}
F_16 ( V_7 , V_12 , F_17 ( V_12 ) , V_10 , Type ) ;
F_6 ( & V_14 , V_7 ) ;
}
if ( V_11 > 0 ) {
F_18 ( V_2 -> V_24 , & V_14 ) ;
}
}
static int F_19 ( T_2 V_25 ,
struct V_26 * V_27 ,
void * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
int V_29 ;
T_3 V_30 , V_31 ;
V_2 -> V_24 = V_25 ;
memcpy ( & V_2 -> V_19 , V_27 , sizeof( * V_27 ) ) ;
F_15 ( V_32 , ( L_2 ,
( unsigned long ) V_25 ,
V_2 -> V_19 . V_20 ,
V_2 -> V_19 . V_21 ,
V_2 -> V_19 . V_22 ) ) ;
#ifdef F_20
F_21 ( ( V_27 -> V_20 + V_27 -> V_21 ) <= (struct V_33 * ) ( V_2 -> V_34 . V_35 ) -> V_36 ) ;
#else
F_21 ( ( V_27 -> V_20 + V_27 -> V_21 ) <= V_2 -> V_37 -> V_38 -> V_36 ) ;
#endif
F_10 ( V_2 , V_15 , V_39 ) ;
F_10 ( V_2 , V_40 , V_41 ) ;
do {
V_29 = F_22 ( V_2 -> V_24 ) ;
if ( V_29 ) {
break;
}
if ( ! V_2 -> V_4 ) {
break;
}
F_23 ( 100 ) ;
F_24 ( & V_42 , sizeof( V_42 ) ) ;
V_42 . V_24 = V_2 -> V_24 ;
V_42 . V_43 = & V_2 -> V_19 ;
#ifdef F_20
V_42 . V_44 = (struct V_45 * ) ( V_2 -> V_34 . V_46 ) ;
#else
V_42 . V_44 = V_2 -> V_37 -> V_47 ;
#endif
V_42 . V_48 = V_2 -> V_48 ;
if ( V_49 != 0 ) {
V_42 . V_50 |= V_51 ;
V_42 . V_50 |= V_52 ;
V_42 . V_53 = V_49 ;
}
if ( ( V_54 != 0 ) || ( V_55 != 0 ) ) {
V_42 . V_56 = ( V_57 ) V_54 ;
V_42 . V_58 = ( V_57 ) V_55 ;
V_42 . V_50 |= V_59 ;
}
V_30 = F_25 ( V_2 -> V_37 -> V_60 ,
F_26 ( V_2 -> V_37 , V_61 ) ) ;
V_29 = F_27 ( V_2 -> V_37 -> V_47 , & V_30 , & V_31 ) ;
if ( 0 == V_29 ) {
V_42 . V_62 = ( V_31 & 0x1 ) ;
V_42 . V_63 = ( V_31 & 0xFFFF0000 ) >> 16 ;
V_42 . V_64 = ( V_31 & 0xFF00 ) >> 8 ;
} else {
F_15 ( V_23 , ( L_3 ) ) ;
}
memcpy ( V_42 . V_65 , V_2 -> V_37 -> V_65 , 6 ) ;
V_29 = F_28 ( & V_42 ) ;
if ( V_29 ) {
break;
}
if ( V_42 . V_62 ) {
V_29 = F_29 ( V_2 -> V_24 , true ) ;
if ( V_29 ) {
F_15 ( V_23 , ( L_4 ) ) ;
}
}
V_29 = F_30 ( V_2 ) ;
} while ( false );
return V_29 ;
}
static void F_31 ( void * V_28 , int V_66 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
F_15 ( V_23 , ( L_5 ) ) ;
if ( V_2 -> V_4 ) {
}
}
static void F_32 ( void * V_28 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
F_15 ( V_32 , ( L_6 ) ) ;
F_21 ( V_2 -> V_24 != NULL ) ;
F_33 ( V_2 -> V_24 ) ;
F_34 ( V_2 ) ;
V_2 -> V_24 = NULL ;
}
static void F_35 ( void * V_28 , struct V_6 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
void * V_3 = V_7 -> V_67 ;
F_21 ( V_3 != NULL ) ;
F_21 ( V_2 != NULL ) ;
if ( V_7 -> V_66 ) {
if ( ( V_7 -> V_66 != V_68 ) && ( V_7 -> V_66 != V_69 ) ) {
F_15 ( V_23 , ( L_7 , V_7 -> V_66 ) ) ;
}
}
F_4 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_3 ) ;
}
static void F_36 ( void * V_28 , struct V_6 * V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
struct V_5 * V_70 ;
F_21 ( V_2 != NULL ) ;
V_70 = (struct V_5 * ) V_7 -> V_67 ;
F_21 ( V_70 != NULL ) ;
do {
if ( V_7 -> V_66 ) {
break;
}
F_15 ( V_71 ,
( L_8 ,
F_37 ( V_7 ) , V_7 -> V_72 ) ) ;
F_38 ( V_70 , V_7 -> V_72 + V_2 -> V_19 . V_20 ) ;
F_39 ( V_70 , V_2 -> V_19 . V_20 ) ;
if ( F_40 ( V_73 ) ) {
F_15 ( V_74 , ( L_9 ,
( F_37 ( V_7 ) == V_40 ) ? L_10 : L_11 ,
V_70 -> V_75 ) ) ;
F_41 ( V_70 -> V_76 , V_70 -> V_75 , L_12 ) ;
}
if ( V_2 -> V_4 ) {
if ( F_42 ( V_2 , F_37 ( V_7 ) , V_70 ) ) {
V_70 = NULL ;
}
break;
}
#ifdef F_20
V_70 -> V_77 = (struct V_33 * ) ( V_2 -> V_34 . V_35 ) ;
if ( ( ( (struct V_33 * ) V_2 -> V_34 . V_35 ) -> V_78 & V_79 ) == V_79 ) {
V_70 -> V_80 = F_43 ( V_70 , (struct V_33 * ) ( V_2 -> V_34 . V_35 ) ) ;
#else
V_70 -> V_77 = V_2 -> V_37 -> V_38 ;
if ( ( V_2 -> V_37 -> V_38 -> V_78 & V_79 ) == V_79 ) {
V_70 -> V_80 = F_43 ( V_70 , V_2 -> V_37 -> V_38 ) ;
#endif
F_44 ( V_70 ) ;
V_70 = NULL ;
}
} while ( false ) ;
F_4 ( V_2 , V_7 ) ;
if ( V_70 != NULL ) {
F_1 ( V_2 , V_70 ) ;
}
}
static void ar6000_hci_pkt_refill(void *pContext, HCI_TRANSPORT_PACKET_TYPE Type, int BuffersAvailable)
{
struct V_1 * V_2 = (struct V_1 * ) V_28 ;
int V_81 ;
if ( Type == V_15 ) {
V_81 = V_39 - V_82 ;
} else {
V_81 = V_41 - V_82 ;
}
if ( V_81 > 0 ) {
F_10 ( V_2 , Type , V_81 ) ;
}
}
static HCI_SEND_FULL_ACTION ar6000_hci_pkt_send_full(void *pContext , struct htc_packet *pPacket
void F_45 ( struct V_83 * V_37 , void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_84 ;
struct V_85 * V_86 = (struct V_85 * ) V_42 ;
V_86 -> V_24 = V_2 -> V_24 ;
V_86 -> V_43 = & V_2 -> V_19 ;
V_86 -> V_44 = V_37 -> V_47 ;
V_86 -> V_48 = V_2 -> V_48 ;
V_86 -> V_50 |= V_51 ;
V_86 -> V_53 = 115200 ;
}
static int F_46 ( struct V_87 * V_88 )
{
F_15 ( V_89 , ( L_13 ) ) ;
F_47 ( V_90 , & V_88 -> V_78 ) ;
F_47 ( V_91 , & V_88 -> V_78 ) ;
F_47 ( V_92 , & V_88 -> V_78 ) ;
return 0 ;
}
static int F_48 ( struct V_87 * V_88 )
{
F_15 ( V_89 , ( L_14 ) ) ;
F_49 ( V_90 , & V_88 -> V_78 ) ;
return 0 ;
}
static int F_50 ( struct V_5 * V_70 )
{
struct V_87 * V_88 = (struct V_87 * ) V_70 -> V_77 ;
T_1 type ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
int V_29 = 0 ;
struct V_5 * V_93 = NULL ;
if ( ! V_88 ) {
F_15 ( V_94 , ( L_15 ) ) ;
return - V_95 ;
}
if ( ! F_51 ( V_90 , & V_88 -> V_78 ) ) {
F_15 ( V_89 , ( L_16 ) ) ;
return - V_96 ;
}
V_2 = (struct V_1 * ) V_88 -> V_97 ;
F_21 ( V_2 != NULL ) ;
F_15 ( V_98 , ( L_17 , F_52 ( V_70 ) -> V_99 ) ) ;
type = V_100 ;
switch ( F_52 ( V_70 ) -> V_99 ) {
case V_101 :
type = V_100 ;
V_88 -> V_102 . V_103 ++ ;
break;
case V_104 :
type = V_15 ;
V_88 -> V_102 . V_105 ++ ;
break;
case V_106 :
F_53 ( V_70 ) ;
return 0 ;
default:
F_21 ( false ) ;
F_53 ( V_70 ) ;
return 0 ;
}
if ( F_40 ( V_73 ) ) {
F_15 ( V_74 , ( L_18 ,
( type == V_100 ) ? L_19 : L_11 ,
V_70 -> V_75 ) ) ;
if ( type == V_100 ) {
V_57 V_107 = F_54 ( V_70 -> V_76 ) ;
F_15 ( V_74 , ( L_20 ,
V_107 >> 10 , V_107 & 0x3FF ) ) ;
}
F_41 ( V_70 -> V_76 , V_70 -> V_75 , L_21 ) ;
}
do {
V_93 = F_55 ( V_108 + V_2 -> V_19 . V_20 +
V_2 -> V_19 . V_21 + V_70 -> V_75 ,
V_109 ) ;
if ( V_93 == NULL ) {
V_29 = V_110 ;
break;
}
F_52 ( V_93 ) -> V_99 = F_52 ( V_70 ) -> V_99 ;
V_93 -> V_77 = ( void * ) V_2 -> V_48 ;
F_56 ( V_93 , V_108 + V_2 -> V_19 . V_20 ) ;
memcpy ( V_93 -> V_76 , V_70 -> V_76 , V_70 -> V_75 ) ;
F_57 ( V_93 , V_70 -> V_75 ) ;
V_7 = F_8 ( V_2 ) ;
if ( NULL == V_7 ) {
V_29 = V_110 ;
break;
}
F_58 ( V_7 ,
V_93 ,
V_93 -> V_76 ,
V_93 -> V_75 ,
type ,
V_111 ) ;
F_15 ( V_98 , ( L_22 , ( unsigned long ) V_93 ) ) ;
F_15 ( V_98 , ( L_23 ,
type , V_93 -> V_75 ) ) ;
V_29 = F_59 ( V_2 -> V_24 , V_7 , false ) ;
V_7 = NULL ;
V_93 = NULL ;
} while ( false );
if ( V_93 != NULL ) {
F_53 ( V_93 ) ;
}
F_53 ( V_70 ) ;
F_15 ( V_98 , ( L_24 ) ) ;
return 0 ;
}
static int F_60 ( struct V_87 * V_88 , unsigned int V_112 , unsigned long V_113 )
{
F_15 ( V_89 , ( L_25 ) ) ;
return - V_114 ;
}
static int F_61 ( struct V_87 * V_88 )
{
struct V_1 * V_2 ;
F_15 ( V_89 , ( L_26 ) ) ;
V_2 = (struct V_1 * ) V_88 -> V_97 ;
return 0 ;
}
static void F_62 ( struct V_87 * V_88 )
{
F_15 ( V_89 , ( L_27 ) ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
struct V_87 * V_115 = NULL ;
struct V_116 V_117 ;
if ( ! V_118 ) {
return 0 ;
}
do {
F_24 ( & V_117 , sizeof( V_117 ) ) ;
#ifdef F_20
V_29 = F_64 ( (struct V_45 * ) ( V_2 -> V_34 . V_46 ) ,
& V_117 ) ;
#else
V_29 = F_65 ( V_2 -> V_37 -> V_47 ,
V_119 ,
& V_117 ,
sizeof( V_117 ) ) ;
#endif
if ( V_29 ) {
F_15 ( V_23 , ( L_28 ) ) ;
break;
}
V_115 = F_66 () ;
if ( NULL == V_115 ) {
F_15 ( V_23 , ( L_29 ) ) ;
V_29 = V_110 ;
break;
}
V_2 -> V_48 = V_115 ;
F_67 ( V_115 , V_117 . V_120 ) ;
F_68 ( V_115 , V_121 , V_122 ) ;
V_115 -> V_97 = V_2 ;
V_115 -> V_123 = F_46 ;
V_115 -> V_124 = F_48 ;
V_115 -> V_125 = F_50 ;
V_115 -> V_126 = F_60 ;
V_115 -> V_127 = F_61 ;
V_115 -> V_128 = F_62 ;
V_115 -> V_129 = V_130 ;
V_2 -> V_4 = true ;
} while ( false );
if ( V_29 ) {
F_34 ( V_2 ) ;
}
return V_29 ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_131 ;
if ( V_2 -> V_132 ) {
V_2 -> V_132 = false ;
F_49 ( V_90 , & V_2 -> V_48 -> V_78 ) ;
F_49 ( V_91 , & V_2 -> V_48 -> V_78 ) ;
F_49 ( V_92 , & V_2 -> V_48 -> V_78 ) ;
F_21 ( V_2 -> V_48 != NULL ) ;
if ( ( V_131 = F_69 ( V_2 -> V_48 ) ) < 0 ) {
F_15 ( V_23 , ( L_30 , V_131 ) ) ;
}
}
F_70 ( V_2 -> V_48 ) ;
V_2 -> V_48 = NULL ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_131 ;
int V_29 = 0 ;
do {
F_15 ( V_32 , ( L_31 ) ) ;
F_21 ( V_2 -> V_48 != NULL ) ;
V_2 -> V_132 = true ;
if ( ( V_131 = F_71 ( V_2 -> V_48 ) ) < 0 ) {
F_15 ( V_23 , ( L_32 , V_131 ) ) ;
V_2 -> V_132 = false ;
V_29 = V_133 ;
break;
}
F_15 ( V_32 , ( L_33 ) ) ;
} while ( false );
return V_29 ;
}
static bool F_42 ( struct V_1 * V_2 ,
T_1 Type ,
struct V_5 * V_70 )
{
T_4 V_134 ;
int V_75 ;
bool V_135 = false ;
T_5 * V_136 ;
do {
if ( ! F_51 ( V_90 , & V_2 -> V_48 -> V_78 ) ) {
F_15 ( V_94 , ( L_34 ) ) ;
break;
}
switch ( Type ) {
case V_15 :
V_134 = V_104 ;
break;
case V_40 :
V_134 = V_137 ;
break;
default:
V_134 = 0 ;
F_21 ( false ) ;
break;
}
if ( 0 == V_134 ) {
break;
}
F_52 ( V_70 ) -> V_99 = V_134 ;
V_70 -> V_77 = ( void * ) V_2 -> V_48 ;
V_75 = V_70 -> V_75 ;
if ( F_40 ( V_71 ) ) {
if ( F_52 ( V_70 ) -> V_99 == V_137 ) {
V_136 = ( T_5 * ) V_70 -> V_76 ;
F_15 ( V_71 , ( L_35 ,
V_136 -> V_138 , V_136 -> V_139 ) ) ;
}
}
if ( F_72 ( V_70 ) != 0 ) {
F_15 ( V_23 , ( L_36 ) ) ;
break;
} else {
F_15 ( V_71 ,
( L_37 , V_134 , V_75 ) ) ;
}
V_135 = true ;
} while ( false );
return V_135 ;
}
static struct V_5 * F_13 ( struct V_1 * V_2 , int V_140 )
{
struct V_5 * V_70 ;
V_70 = F_55 ( V_140 , V_109 ) ;
if ( NULL == V_70 ) {
F_15 ( V_23 , ( L_38 ) ) ;
}
return V_70 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_5 * V_70 )
{
F_53 ( V_70 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static int F_30 ( struct V_1 * V_2 )
{
F_21 ( false ) ;
return V_133 ;
}
static bool F_42 ( struct V_1 * V_2 ,
T_1 Type ,
struct V_5 * V_70 )
{
F_21 ( false ) ;
return false ;
}
static struct V_5 * F_13 ( struct V_1 * V_2 , int V_140 )
{
F_21 ( false ) ;
return NULL ;
}
static void F_2 ( struct V_1 * V_2 , struct V_5 * V_70 )
{
F_21 ( false ) ;
}
void F_45 ( struct V_83 * V_37 , void * V_42 )
{
return;
}
static int T_6
F_73 ( void )
{
int V_29 ;
struct V_141 V_142 ;
V_142 . V_143 = V_144 ;
V_142 . V_145 = V_146 ;
V_29 = F_74 ( & V_142 ) ;
if ( V_29 )
return - V_95 ;
return 0 ;
}
static void T_7
F_75 ( void )
{
}
