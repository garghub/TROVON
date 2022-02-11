static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_7 ;
return V_2 ;
}
static struct V_8 * F_5 ( struct V_1 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
struct V_8 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
V_12 = F_2 ( sizeof( struct V_8 ) , V_3 ) ;
if ( ! V_12 )
return NULL ;
F_6 ( & V_12 -> V_18 ) ;
V_14 = & V_12 -> V_19 ;
V_14 -> V_20 = V_10 ;
V_14 -> V_11 = V_11 ;
V_16 = & V_14 -> V_21 . V_22 ;
V_16 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_9 ( & V_12 -> V_25 , & V_9 -> V_5 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_12 ( & V_26 -> V_25 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
F_13 ( V_26 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_20 ) {
case V_27 :
F_15 ( V_28 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_29 . V_30 ,
V_14 -> V_21 . V_29 . V_31 ,
V_14 -> V_21 . V_29 . V_32 ,
V_14 -> V_21 . V_29 . V_33 ,
V_14 -> V_21 . V_29 . V_34 ,
V_14 -> V_21 . V_29 . V_35 ,
V_14 -> V_21 . V_29 . V_36 ) ;
break;
case V_37 :
F_15 ( V_28 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_38 . V_23 ,
V_14 -> V_21 . V_38 . V_39 ,
V_14 -> V_21 . V_38 . V_40 ,
V_14 -> V_21 . V_38 . V_41 ,
V_14 -> V_21 . V_38 . V_42 ,
V_14 -> V_21 . V_38 . V_43 ,
V_14 -> V_21 . V_38 .
V_44 ,
V_14 -> V_21 . V_38 .
V_45 ) ;
break;
case V_46 :
F_15 ( V_28 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_47 . V_23 ,
V_14 -> V_21 . V_47 . V_39 ,
V_14 -> V_21 . V_47 .
V_48 ,
V_14 -> V_21 . V_47 .
V_49 ) ;
break;
case V_50 :
F_15 ( V_28 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_51 . V_23 ,
V_14 -> V_21 . V_51 . V_39 ) ;
break;
case V_52 :
F_15 ( V_28 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_21 . V_53 . V_39 ,
V_14 -> V_21 . V_53 . V_54 ,
V_14 -> V_21 . V_53 . V_55 ) ;
break;
default:
F_15 ( V_28 , L_15 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
}
static int F_16 ( struct V_1 * V_9 ,
struct V_8 * V_26 )
{
int V_56 ;
struct V_57 * V_58 ;
V_58 = & V_26 -> V_29 ;
V_58 -> V_59 = false ;
V_58 -> V_60 = V_26 -> V_19 . V_11 ;
V_58 -> V_61 = 1 ;
V_58 -> V_62 [ 0 ] . V_63 = F_17 ( & V_26 -> V_19 ) >>
V_64 ;
V_58 -> V_62 [ 0 ] . V_65 = V_26 -> V_19 . V_11 ;
V_58 -> V_62 [ 0 ] . V_66 =
( unsigned long ) & V_26 -> V_19 & ( V_67 - 1 ) ;
V_58 -> V_68 . V_69 . V_70 = V_26 ;
V_58 -> V_68 . V_69 . V_71 =
V_72 ;
V_58 -> V_68 . V_69 . V_73 = ( unsigned long ) V_9 ;
V_56 = F_18 ( V_9 -> V_74 -> V_9 , V_58 ) ;
return V_56 ;
}
static void F_19 ( struct V_1 * V_9 ,
struct V_13 * V_75 )
{
struct V_8 * V_12 = NULL ;
bool V_76 = false ;
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_20 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_21 . V_77 . V_23
== V_75 -> V_21 . V_38 . V_23 ) {
V_76 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_76 ) {
if ( V_75 -> V_11 <= sizeof( struct V_13 ) ) {
memcpy ( & V_12 -> V_78 , V_75 ,
V_75 -> V_11 ) ;
} else {
F_21 ( & V_9 -> V_74 -> V_9 -> V_2 ,
L_16
L_17 ,
V_75 -> V_11 ,
sizeof( struct V_79 ) ) ;
if ( V_75 -> V_20 ==
V_80 ) {
V_12 -> V_78 . V_21 . V_81 .
V_39 = V_82 ;
} else {
V_12 -> V_78 . V_21 .
V_38 . V_39 =
V_82 ;
}
}
F_22 ( & V_12 -> V_18 ) ;
} else {
F_21 ( & V_9 -> V_74 -> V_9 -> V_2 ,
L_18
L_19 ,
V_75 -> V_21 . V_38 . V_23 ,
V_75 -> V_20 ) ;
}
}
static void F_23 ( struct V_1 * V_9 ,
struct V_13 * V_75 )
{
struct V_83 * V_84 =
& V_75 -> V_21 . V_53 ;
if ( V_84 -> V_39 == V_85 ) {
F_24 (
V_9 -> V_74 -> V_9 , 1 ) ;
} else if ( V_84 -> V_39 == V_86 ) {
F_24 (
V_9 -> V_74 -> V_9 , 0 ) ;
} else {
}
}
static void F_25 ( struct V_1 * V_9 ,
struct V_13 * V_21 ,
struct V_57 * V_29 )
{
struct V_87 * V_88 ;
T_1 V_30 ;
V_88 = & V_21 -> V_21 . V_29 ;
V_30 = V_89 + V_88 -> V_30 ;
V_29 -> V_60 -= V_30 ;
V_29 -> V_62 [ 0 ] . V_66 += V_30 ;
V_29 -> V_62 [ 0 ] . V_65 -= V_30 ;
V_29 -> V_59 = true ;
F_26 ( V_9 -> V_74 -> V_9 , V_29 ) ;
}
int F_27 ( struct V_90 * V_9 ,
struct V_57 * V_29 )
{
struct V_91 * V_74 = V_9 -> V_92 ;
struct V_1 * V_93 ;
struct V_13 V_14 ;
struct V_13 * V_94 ;
if ( ! V_74 )
return - V_95 ;
if ( ! V_74 -> V_96 ) {
F_21 ( & V_9 -> V_2 , L_20
L_21 ) ;
return - 1 ;
}
V_93 = (struct V_1 * ) V_74 -> V_96 ;
if ( V_93 -> V_6 == V_7 ) {
F_21 ( & V_9 -> V_2 , L_22
L_23 ) ;
return - 1 ;
}
V_94 = (struct V_13 * ) F_28 (
F_29 ( V_29 -> V_62 [ 0 ] . V_63 ) , V_97 ) ;
V_94 = ( void * ) ( ( unsigned long ) V_94 +
V_29 -> V_62 [ 0 ] . V_66 ) ;
#if 0
if (pkt->total_data_buflen != rndis_hdr->msg_len) {
kunmap_atomic(rndis_hdr - pkt->page_buf[0].offset,
KM_IRQ0);
dev_err(&dev->device, "invalid rndis message? (expected %u "
"bytes got %u)...dropping this message!\n",
rndis_hdr->msg_len,
pkt->total_data_buflen);
return -1;
}
#endif
if ( ( V_94 -> V_20 != V_27 ) &&
( V_94 -> V_11 > sizeof( struct V_13 ) ) ) {
F_21 ( & V_9 -> V_2 , L_24
L_25 ,
V_94 -> V_11 ,
sizeof( struct V_13 ) ) ;
}
memcpy ( & V_14 , V_94 ,
( V_94 -> V_11 > sizeof( struct V_13 ) ) ?
sizeof( struct V_13 ) :
V_94 -> V_11 ) ;
F_30 ( V_94 - V_29 -> V_62 [ 0 ] . V_66 , V_97 ) ;
F_14 ( & V_14 ) ;
switch ( V_14 . V_20 ) {
case V_27 :
F_25 ( V_93 , & V_14 , V_29 ) ;
break;
case V_37 :
case V_46 :
case V_50 :
F_19 ( V_93 , & V_14 ) ;
break;
case V_52 :
F_23 ( V_93 , & V_14 ) ;
break;
default:
F_21 ( & V_9 -> V_2 ,
L_26 ,
V_14 . V_20 ,
V_14 . V_11 ) ;
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_9 , T_1 V_98 ,
void * V_99 , T_1 * V_100 )
{
struct V_8 * V_12 ;
T_1 V_101 = * V_100 ;
struct V_102 * V_103 ;
struct V_104 * V_47 ;
int V_56 = 0 ;
int V_105 ;
if ( ! V_99 )
return - V_95 ;
* V_100 = 0 ;
V_12 = F_5 ( V_9 , V_106 ,
F_32 ( struct V_102 ) ) ;
if ( ! V_12 ) {
V_56 = - 1 ;
goto V_107;
}
V_103 = & V_12 -> V_19 . V_21 . V_108 ;
V_103 -> V_98 = V_98 ;
V_103 -> V_49 = sizeof( struct V_102 ) ;
V_103 -> V_48 = 0 ;
V_103 -> V_109 = 0 ;
V_56 = F_16 ( V_9 , V_12 ) ;
if ( V_56 != 0 )
goto V_107;
V_105 = F_33 ( & V_12 -> V_18 , V_110 ) ;
if ( V_105 == 0 ) {
V_56 = - V_111 ;
goto V_107;
}
V_47 = & V_12 -> V_78 . V_21 . V_47 ;
if ( V_47 -> V_48 > V_101 ) {
V_56 = - 1 ;
goto V_107;
}
memcpy ( V_99 ,
( void * ) ( ( unsigned long ) V_47 +
V_47 -> V_49 ) ,
V_47 -> V_48 ) ;
* V_100 = V_47 -> V_48 ;
V_107:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_56 ;
}
static int F_34 ( struct V_1 * V_9 )
{
T_1 V_112 = V_113 ;
return F_31 ( V_9 ,
V_114 ,
V_9 -> V_115 , & V_112 ) ;
}
static int F_35 ( struct V_1 * V_9 )
{
T_1 V_112 = sizeof( T_1 ) ;
return F_31 ( V_9 ,
V_116 ,
& V_9 -> V_117 , & V_112 ) ;
}
static int F_36 ( struct V_1 * V_9 ,
T_1 V_118 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_119 * V_51 ;
T_1 V_39 ;
int V_56 , V_105 ;
V_12 = F_5 ( V_9 , V_120 ,
F_32 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_56 = - 1 ;
goto V_107;
}
V_16 = & V_12 -> V_19 . V_21 . V_22 ;
V_16 -> V_98 = V_121 ;
V_16 -> V_48 = sizeof( T_1 ) ;
V_16 -> V_49 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_118 , sizeof( T_1 ) ) ;
V_56 = F_16 ( V_9 , V_12 ) ;
if ( V_56 != 0 )
goto V_107;
V_105 = F_33 ( & V_12 -> V_18 , V_110 ) ;
if ( V_105 == 0 ) {
V_56 = - 1 ;
F_21 ( & V_9 -> V_74 -> V_9 -> V_2 ,
L_27 ) ;
goto Exit;
} else {
if ( V_56 > 0 )
V_56 = 0 ;
V_51 = & V_12 -> V_78 . V_21 . V_51 ;
V_39 = V_51 -> V_39 ;
}
V_107:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
Exit:
return V_56 ;
}
static int F_37 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_122 * V_123 ;
struct V_124 * V_38 ;
T_1 V_39 ;
int V_56 , V_105 ;
V_12 = F_5 ( V_9 , V_125 ,
F_32 ( struct V_122 ) ) ;
if ( ! V_12 ) {
V_56 = - 1 ;
goto V_107;
}
V_123 = & V_12 -> V_19 . V_21 . V_77 ;
V_123 -> V_40 = V_126 ;
V_123 -> V_41 = V_127 ;
V_123 -> V_43 = 2048 ;
V_9 -> V_6 = V_128 ;
V_56 = F_16 ( V_9 , V_12 ) ;
if ( V_56 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_107;
}
V_105 = F_33 ( & V_12 -> V_18 , V_110 ) ;
if ( V_105 == 0 ) {
V_56 = - V_111 ;
goto V_107;
}
V_38 = & V_12 -> V_78 . V_21 . V_38 ;
V_39 = V_38 -> V_39 ;
if ( V_39 == V_129 ) {
V_9 -> V_6 = V_130 ;
V_56 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_56 = - 1 ;
}
V_107:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_56 ;
}
static void F_38 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_131 * V_132 ;
V_12 = F_5 ( V_9 , V_133 ,
F_32 ( struct V_131 ) ) ;
if ( ! V_12 )
goto V_107;
V_132 = & V_12 -> V_19 . V_21 . V_134 ;
V_132 -> V_23 = F_7 ( & V_9 -> V_24 ) ;
F_16 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_107:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_39 ( struct V_1 * V_9 )
{
int V_56 ;
if ( V_9 -> V_6 != V_130 )
return 0 ;
V_56 = F_36 ( V_9 ,
V_135 |
V_136 |
V_137 ) ;
if ( V_56 == 0 )
V_9 -> V_6 = V_138 ;
return V_56 ;
}
static int F_40 ( struct V_1 * V_9 )
{
int V_56 ;
if ( V_9 -> V_6 != V_138 )
return 0 ;
V_56 = F_36 ( V_9 , 0 ) ;
if ( V_56 == 0 )
V_9 -> V_6 = V_130 ;
return V_56 ;
}
int F_41 ( struct V_90 * V_9 ,
void * V_139 )
{
int V_56 ;
struct V_91 * V_140 ;
struct V_1 * V_141 ;
struct V_142 * V_143 = V_139 ;
V_141 = F_1 () ;
if ( ! V_141 )
return - 1 ;
V_56 = F_42 ( V_9 , V_139 ) ;
if ( V_56 != 0 ) {
F_13 ( V_141 ) ;
return V_56 ;
}
V_140 = V_9 -> V_92 ;
V_140 -> V_96 = V_141 ;
V_141 -> V_74 = V_140 ;
V_56 = F_37 ( V_141 ) ;
if ( V_56 != 0 ) {
}
V_56 = F_34 ( V_141 ) ;
if ( V_56 != 0 ) {
}
memcpy ( V_143 -> V_144 , V_141 -> V_115 , V_113 ) ;
F_35 ( V_141 ) ;
V_143 -> V_145 = V_141 -> V_117 ;
F_43 ( & V_9 -> V_2 , L_28 ,
V_141 -> V_115 ,
( ( V_143 -> V_145 ) ? ( L_29 ) : ( L_30 ) ) ) ;
return V_56 ;
}
int F_44 ( struct V_90 * V_9 )
{
struct V_91 * V_74 = V_9 -> V_92 ;
struct V_1 * V_93 = V_74 -> V_96 ;
F_38 ( V_93 ) ;
F_13 ( V_93 ) ;
V_74 -> V_96 = NULL ;
F_45 ( V_9 ) ;
return 0 ;
}
int F_46 ( struct V_90 * V_9 )
{
struct V_91 * V_140 = V_9 -> V_92 ;
if ( ! V_140 )
return - V_95 ;
return F_39 ( V_140 -> V_96 ) ;
}
int F_47 ( struct V_90 * V_9 )
{
struct V_91 * V_140 = V_9 -> V_92 ;
if ( ! V_140 )
return - V_95 ;
return F_40 ( V_140 -> V_96 ) ;
}
int F_48 ( struct V_90 * V_9 ,
struct V_57 * V_29 )
{
int V_56 ;
struct V_79 * V_146 ;
struct V_13 * V_147 ;
struct V_87 * V_148 ;
T_1 V_149 ;
V_146 = (struct V_79 * ) V_29 -> V_96 ;
memset ( V_146 , 0 , sizeof( struct V_79 ) ) ;
V_147 = & V_146 -> V_21 ;
V_149 = F_32 ( struct V_87 ) ;
V_147 -> V_20 = V_27 ;
V_147 -> V_11 = V_29 -> V_60 +
V_149 ;
V_148 = & V_147 -> V_21 . V_29 ;
V_148 -> V_30 = sizeof( struct V_87 ) ;
V_148 -> V_31 = V_29 -> V_60 ;
V_29 -> V_59 = true ;
V_29 -> V_62 [ 0 ] . V_63 = F_17 ( V_147 ) >> V_64 ;
V_29 -> V_62 [ 0 ] . V_66 =
( unsigned long ) V_147 & ( V_67 - 1 ) ;
V_29 -> V_62 [ 0 ] . V_65 = V_149 ;
V_146 -> V_68 = V_29 -> V_68 . V_69 . V_71 ;
V_146 -> V_150 =
V_29 -> V_68 . V_69 . V_70 ;
V_29 -> V_68 . V_69 . V_71 = V_151 ;
V_29 -> V_68 . V_69 . V_70 = V_146 ;
V_56 = F_18 ( V_9 , V_29 ) ;
if ( V_56 != 0 ) {
V_29 -> V_68 . V_69 . V_71 =
V_146 -> V_68 ;
V_29 -> V_68 . V_69 . V_70 =
V_146 -> V_150 ;
}
return V_56 ;
}
static void V_151 ( void * V_152 )
{
struct V_79 * V_146 = V_152 ;
V_146 -> V_68 ( V_146 -> V_150 ) ;
}
static void V_72 ( void * V_152 )
{
}
