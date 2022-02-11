static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( & V_5 ) ;
F_3 ( & V_6 ) ;
V_4 = V_7 [ F_4 ( V_1 ) ] ;
if ( V_4 && V_4 -> V_8 ) {
int V_9 = 0 ;
const struct V_10 * V_11 ;
V_11 = F_5 ( V_4 -> V_8 ) ;
if ( ! V_11 )
goto V_12;
V_2 -> V_13 = V_4 ;
F_6 ( V_2 , V_11 ) ;
if ( V_2 -> V_14 -> V_15 )
V_9 = V_2 -> V_14 -> V_15 ( V_1 , V_2 ) ;
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return V_9 ;
}
V_12:
F_7 ( & V_6 ) ;
F_8 ( & V_5 ) ;
return - V_16 ;
}
int F_9 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ! V_4 -> V_17 )
return - V_18 ;
if ( ( V_2 -> V_19 & V_20 ) == V_21 ) {
if ( ! V_4 -> V_22 )
return - V_18 ;
V_4 -> V_22 -- ;
} else {
if ( ! V_4 -> V_23 )
return - V_18 ;
V_4 -> V_23 -- ;
}
V_4 -> V_17 -- ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ( V_2 -> V_19 & V_20 ) == V_21 ) {
V_4 -> V_22 ++ ;
} else {
V_4 -> V_23 ++ ;
}
V_4 -> V_17 ++ ;
return 0 ;
}
long F_11 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 )
{
struct V_3 * V_4 = V_2 -> V_13 ;
if ( ! V_4 )
return - V_16 ;
if ( ! V_4 -> V_26 )
return - V_27 ;
return F_12 ( V_2 , V_24 , V_25 , V_4 -> V_26 ) ;
}
static int F_13 ( struct V_28 * V_29 , int type )
{
T_1 V_30 = 0 ;
while ( V_30 < V_31 ) {
struct V_3 * V_32 ;
F_14 (dev, &adap->device_list, list_head)
if ( V_32 -> type == type && V_32 -> V_30 == V_30 )
goto V_33;
return V_30 ;
V_33:
V_30 ++ ;
}
return - V_34 ;
}
static void F_15 ( struct V_3 * V_4 )
{
#if F_16 ( V_35 )
if ( V_4 -> V_36 ) {
F_17 ( V_4 -> V_36 ) ;
F_18 ( V_4 -> V_36 ) ;
F_18 ( V_4 -> V_37 ) ;
V_4 -> V_36 = NULL ;
V_4 -> V_37 = NULL ;
}
if ( V_4 -> V_38 ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_4 -> V_40 ; V_39 ++ ) {
F_17 ( & V_4 -> V_38 [ V_39 ] ) ;
F_18 ( V_4 -> V_38 [ V_39 ] . V_41 ) ;
}
F_18 ( V_4 -> V_38 ) ;
F_18 ( V_4 -> V_42 ) ;
V_4 -> V_38 = NULL ;
V_4 -> V_42 = NULL ;
V_4 -> V_40 = 0 ;
}
if ( V_4 -> V_43 ) {
F_19 ( V_4 -> V_43 ) ;
V_4 -> V_43 = NULL ;
}
if ( V_4 -> V_44 -> V_45 ) {
F_17 ( V_4 -> V_44 -> V_45 ) ;
V_4 -> V_44 -> V_45 = NULL ;
F_18 ( V_4 -> V_44 -> V_46 ) ;
V_4 -> V_44 -> V_46 = NULL ;
}
#endif
}
static int F_20 ( struct V_3 * V_4 ,
const char * V_41 , int V_47 )
{
int V_39 , V_48 = 0 ;
V_4 -> V_42 = F_21 ( V_47 , sizeof( * V_4 -> V_42 ) ,
V_49 ) ;
if ( ! V_4 -> V_42 )
return - V_50 ;
V_4 -> V_38 = F_21 ( V_47 , sizeof( * V_4 -> V_38 ) ,
V_49 ) ;
if ( ! V_4 -> V_38 )
return - V_50 ;
V_4 -> V_40 = V_47 ;
for ( V_39 = 0 ; V_39 < V_47 ; V_39 ++ ) {
struct V_51 * V_37 = & V_4 -> V_42 [ V_39 ] ;
struct V_52 * V_36 = & V_4 -> V_38 [ V_39 ] ;
V_36 -> V_41 = F_22 ( V_49 , L_1 , V_41 , V_39 ) ;
if ( ! V_36 -> V_41 )
return - V_50 ;
V_36 -> V_53 = V_54 ;
V_37 -> V_55 = V_56 ;
V_48 = F_23 ( V_36 , 1 , V_37 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_24 ( V_4 -> V_44 -> V_57 ,
V_36 ) ;
if ( V_48 < 0 )
return V_48 ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
int type , int V_58 )
{
int V_39 , V_48 , V_47 ;
switch ( type ) {
case V_59 :
V_47 = 2 ;
break;
case V_60 :
V_48 = F_20 ( V_4 , V_61 ,
V_58 ) ;
return V_48 ;
case V_62 :
V_47 = 1 + V_58 ;
V_48 = F_20 ( V_4 , V_63 ,
V_58 ) ;
if ( V_48 < 0 )
return V_48 ;
break;
case V_64 :
V_47 = 2 ;
break;
case V_65 :
return 0 ;
default:
return 0 ;
}
V_4 -> V_36 = F_26 ( sizeof( * V_4 -> V_36 ) , V_49 ) ;
if ( ! V_4 -> V_36 )
return - V_50 ;
V_4 -> V_36 -> V_41 = V_4 -> V_41 ;
if ( V_47 ) {
V_4 -> V_37 = F_21 ( V_47 , sizeof( * V_4 -> V_37 ) ,
V_49 ) ;
if ( ! V_4 -> V_37 )
return - V_50 ;
}
switch ( type ) {
case V_59 :
V_4 -> V_36 -> V_53 = V_66 ;
V_4 -> V_37 [ 0 ] . V_55 = V_56 ;
V_4 -> V_37 [ 1 ] . V_55 = V_67 ;
break;
case V_62 :
V_4 -> V_36 -> V_53 = V_68 ;
V_4 -> V_37 [ 0 ] . V_55 = V_56 ;
for ( V_39 = 1 ; V_39 < V_47 ; V_39 ++ )
V_4 -> V_37 [ V_39 ] . V_55 = V_67 ;
break;
case V_64 :
V_4 -> V_36 -> V_53 = V_69 ;
V_4 -> V_37 [ 0 ] . V_55 = V_56 ;
V_4 -> V_37 [ 1 ] . V_55 = V_67 ;
break;
default:
F_18 ( V_4 -> V_36 ) ;
F_18 ( V_4 -> V_37 ) ;
V_4 -> V_36 = NULL ;
V_4 -> V_37 = NULL ;
return 0 ;
}
if ( V_47 ) {
V_48 = F_23 ( V_4 -> V_36 , V_47 , V_4 -> V_37 ) ;
if ( V_48 )
return V_48 ;
}
V_48 = F_24 ( V_4 -> V_44 -> V_57 ,
V_4 -> V_36 ) ;
if ( V_48 )
return V_48 ;
F_27 ( V_70 L_2 ,
V_71 , V_4 -> V_36 -> V_41 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
int type , int V_72 ,
unsigned V_58 )
{
#if F_16 ( V_35 )
struct V_73 * V_74 ;
T_1 V_75 ;
int V_48 ;
if ( ! V_4 -> V_44 -> V_57 )
return 0 ;
V_48 = F_25 ( V_4 , type , V_58 ) ;
if ( V_48 )
return V_48 ;
switch ( type ) {
case V_59 :
V_75 = V_76 ;
break;
case V_62 :
V_75 = V_77 ;
break;
case V_60 :
V_75 = V_78 ;
break;
case V_64 :
V_75 = V_79 ;
break;
case V_65 :
V_75 = V_80 ;
break;
default:
return 0 ;
}
V_4 -> V_43 = F_29 ( V_4 -> V_44 -> V_57 ,
V_75 , 0 ,
V_81 , V_72 ) ;
if ( ! V_4 -> V_43 )
return - V_50 ;
if ( ! V_4 -> V_36 )
return 0 ;
V_74 = F_30 ( V_4 -> V_36 , & V_4 -> V_43 -> V_82 ,
V_83 ) ;
if ( ! V_74 )
return - V_50 ;
#endif
return 0 ;
}
int F_31 ( struct V_28 * V_29 , struct V_3 * * V_84 ,
const struct V_3 * V_85 , void * V_86 , int type ,
int V_58 )
{
struct V_3 * V_4 ;
struct V_10 * V_87 ;
struct V_88 * V_89 ;
int V_72 ;
int V_30 , V_48 ;
F_2 ( & V_90 ) ;
if ( ( V_30 = F_13 ( V_29 , type ) ) < 0 ) {
F_8 ( & V_90 ) ;
* V_84 = NULL ;
F_27 ( V_91 L_3 , V_71 ) ;
return - V_34 ;
}
* V_84 = V_4 = F_26 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 ) {
F_8 ( & V_90 ) ;
return - V_50 ;
}
V_87 = F_26 ( sizeof( struct V_10 ) , V_49 ) ;
if ( ! V_87 ) {
F_18 ( V_4 ) ;
F_8 ( & V_90 ) ;
return - V_50 ;
}
memcpy ( V_4 , V_85 , sizeof( struct V_3 ) ) ;
V_4 -> type = type ;
V_4 -> V_30 = V_30 ;
V_4 -> V_44 = V_29 ;
V_4 -> V_86 = V_86 ;
V_4 -> V_8 = V_87 ;
F_32 ( & V_4 -> V_92 ) ;
memcpy ( V_87 , V_85 -> V_8 , sizeof( struct V_10 ) ) ;
V_87 -> V_93 = V_29 -> V_94 ;
F_33 ( & V_4 -> V_95 , & V_29 -> V_96 ) ;
F_34 ( & V_6 ) ;
#ifdef F_35
for ( V_72 = 0 ; V_72 < V_97 ; V_72 ++ )
if ( V_7 [ V_72 ] == NULL )
break;
if ( V_72 == V_97 ) {
F_18 ( V_87 ) ;
F_18 ( V_4 ) ;
F_36 ( & V_6 ) ;
F_8 ( & V_90 ) ;
return - V_27 ;
}
#else
V_72 = F_37 ( V_29 -> V_98 , type , V_30 ) ;
#endif
V_4 -> V_72 = V_72 ;
V_7 [ V_72 ] = V_4 ;
F_36 ( & V_6 ) ;
V_48 = F_28 ( V_4 , type , V_72 , V_58 ) ;
if ( V_48 ) {
F_27 ( V_91
L_4 ,
V_71 ) ;
F_15 ( V_4 ) ;
F_18 ( V_87 ) ;
F_18 ( V_4 ) ;
F_36 ( & V_6 ) ;
F_8 ( & V_90 ) ;
return V_48 ;
}
F_8 ( & V_90 ) ;
V_89 = F_38 ( V_99 , V_29 -> V_88 ,
F_39 ( V_81 , V_72 ) ,
V_4 , L_5 , V_29 -> V_98 , V_100 [ type ] , V_30 ) ;
if ( F_40 ( V_89 ) ) {
F_27 ( V_91 L_6 ,
V_71 , V_29 -> V_98 , V_100 [ type ] , V_30 , F_41 ( V_89 ) ) ;
return F_41 ( V_89 ) ;
}
F_42 ( V_70 L_7 ,
V_29 -> V_98 , V_100 [ type ] , V_30 , V_72 , V_72 ) ;
return 0 ;
}
void F_43 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_34 ( & V_6 ) ;
V_7 [ V_4 -> V_72 ] = NULL ;
F_36 ( & V_6 ) ;
F_15 ( V_4 ) ;
F_44 ( V_99 , F_39 ( V_81 , V_4 -> V_72 ) ) ;
F_45 ( & V_4 -> V_95 ) ;
F_18 ( V_4 -> V_8 ) ;
F_18 ( V_4 ) ;
}
static int F_46 ( struct V_28 * V_29 ,
struct V_101 * V_82 ,
char * V_41 )
{
struct V_102 * V_57 = V_29 -> V_57 ;
struct V_52 * V_36 ;
struct V_73 * V_74 ;
F_47 (entity, mdev) {
if ( V_36 -> V_53 == V_54 ) {
if ( strncmp ( V_36 -> V_41 , V_41 , strlen ( V_41 ) ) )
continue;
V_74 = F_30 ( V_36 , V_82 ,
V_83 ) ;
if ( ! V_74 )
return - V_50 ;
}
}
return 0 ;
}
int F_48 ( struct V_28 * V_29 ,
bool V_103 )
{
struct V_102 * V_57 = V_29 -> V_57 ;
struct V_52 * V_36 , * V_104 = NULL , * V_105 = NULL , * V_45 ;
struct V_52 * V_106 = NULL , * V_107 = NULL ;
struct V_73 * V_74 ;
struct V_101 * V_82 ;
unsigned V_108 = 0 ;
unsigned V_109 = 0 ;
unsigned V_110 = 0 , V_111 = 0 ;
int V_48 ;
static const char * V_112 = L_8 ;
if ( ! V_57 )
return 0 ;
F_47 (entity, mdev) {
switch ( V_36 -> V_53 ) {
case V_113 :
V_104 = V_36 ;
V_110 ++ ;
break;
case V_66 :
V_105 = V_36 ;
V_111 ++ ;
break;
case V_68 :
V_106 = V_36 ;
break;
case V_69 :
V_107 = V_36 ;
break;
}
}
if ( V_110 > 1 )
V_104 = NULL ;
if ( V_111 > 1 )
V_105 = NULL ;
if ( V_103 ) {
V_45 = F_26 ( sizeof( * V_45 ) , V_49 ) ;
if ( ! V_45 )
return - V_50 ;
V_29 -> V_45 = V_45 ;
V_29 -> V_46 = F_26 ( sizeof( * V_29 -> V_46 ) , V_49 ) ;
if ( ! V_29 -> V_46 )
return - V_50 ;
V_45 -> V_55 = V_114 ;
V_45 -> V_53 = V_115 ;
V_45 -> V_41 = V_112 ;
V_29 -> V_46 -> V_55 = V_67 ;
V_48 = F_23 ( V_45 , 1 , V_29 -> V_46 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_24 ( V_57 , V_45 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_110 )
V_48 = F_49 ( V_57 ,
V_115 ,
V_45 , 0 ,
V_66 ,
V_105 , 0 ,
V_83 ,
false ) ;
else
V_48 = F_49 ( V_57 ,
V_115 ,
V_45 , 0 ,
V_113 ,
V_104 , V_116 ,
V_83 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_110 && V_111 ) {
V_48 = F_49 ( V_57 ,
V_113 ,
V_104 , V_117 ,
V_66 ,
V_105 , 0 , V_83 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_111 && V_106 ) {
V_48 = F_49 ( V_57 ,
V_66 ,
V_105 , 1 ,
V_68 ,
V_106 , 0 , V_83 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_106 && V_107 ) {
V_48 = F_50 ( V_106 , 1 , V_107 ,
0 , V_83 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_106 ) {
F_47 (entity, mdev) {
if ( V_36 -> V_53 == V_54 ) {
if ( ! strncmp ( V_36 -> V_41 , V_61 ,
strlen ( V_61 ) ) ) {
V_48 = F_50 ( V_106 ,
++ V_109 ,
V_36 , 0 , 0 ) ;
if ( V_48 )
return V_48 ;
}
if ( ! strncmp ( V_36 -> V_41 , V_63 ,
strlen ( V_63 ) ) ) {
V_48 = F_50 ( V_106 ,
++ V_108 ,
V_36 , 0 , 0 ) ;
if ( V_48 )
return V_48 ;
}
}
}
}
F_51 (intf, mdev) {
if ( V_82 -> type == V_79 && V_107 ) {
V_74 = F_30 ( V_107 , V_82 ,
V_83 ) ;
if ( ! V_74 )
return - V_50 ;
}
if ( V_82 -> type == V_76 && V_104 ) {
V_74 = F_30 ( V_104 , V_82 ,
V_83 ) ;
if ( ! V_74 )
return - V_50 ;
}
#if 0
if (intf->type == MEDIA_INTF_T_DVB_DVR && demux) {
link = media_create_intf_link(demux, intf,
MEDIA_LNK_FL_ENABLED);
if (!link)
return -ENOMEM;
}
#endif
if ( V_82 -> type == V_78 ) {
V_48 = F_46 ( V_29 , V_82 , V_61 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_82 -> type == V_77 ) {
V_48 = F_46 ( V_29 , V_82 , V_63 ) ;
if ( V_48 )
return V_48 ;
}
}
return 0 ;
}
static int F_52 ( int V_98 )
{
struct V_95 * V_118 ;
F_53 (entry, &dvb_adapter_list) {
struct V_28 * V_29 ;
V_29 = F_54 ( V_118 , struct V_28 , V_95 ) ;
if ( V_29 -> V_98 == V_98 )
return 0 ;
}
return 1 ;
}
static int F_55 ( void )
{
int V_98 = 0 ;
while ( V_98 < V_119 ) {
if ( F_52 ( V_98 ) )
return V_98 ;
V_98 ++ ;
}
return - V_34 ;
}
int F_56 ( struct V_28 * V_29 , const char * V_41 ,
struct V_94 * V_94 , struct V_88 * V_88 ,
short * V_120 )
{
int V_39 , V_98 ;
F_2 ( & V_90 ) ;
for ( V_39 = 0 ; V_39 < V_119 ; ++ V_39 ) {
V_98 = V_120 [ V_39 ] ;
if ( V_98 >= 0 && V_98 < V_119 ) {
if ( F_52 ( V_98 ) )
break;
} else {
V_98 = F_55 () ;
break;
}
V_98 = - 1 ;
}
if ( V_98 < 0 ) {
F_8 ( & V_90 ) ;
return - V_34 ;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_57 ( & V_29 -> V_96 ) ;
F_27 ( V_121 L_9 , V_41 ) ;
V_29 -> V_98 = V_98 ;
V_29 -> V_41 = V_41 ;
V_29 -> V_94 = V_94 ;
V_29 -> V_88 = V_88 ;
V_29 -> V_122 = 0 ;
V_29 -> V_123 = NULL ;
F_58 ( & V_29 -> V_124 ) ;
F_33 ( & V_29 -> V_95 , & V_125 ) ;
F_8 ( & V_90 ) ;
return V_98 ;
}
int F_59 ( struct V_28 * V_29 )
{
F_2 ( & V_90 ) ;
F_45 ( & V_29 -> V_95 ) ;
F_8 ( & V_90 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 ,
int (* F_60)( struct V_2 * V_2 ,
unsigned int V_24 , void * V_25 ) )
{
char V_126 [ 128 ] ;
void * V_127 = NULL ;
void * V_128 = NULL ;
int V_9 = - V_27 ;
switch ( F_61 ( V_24 ) ) {
case V_129 :
V_128 = ( void * ) V_25 ;
break;
case V_130 :
case V_131 :
case ( V_131 | V_130 ) :
if ( F_62 ( V_24 ) <= sizeof( V_126 ) ) {
V_128 = V_126 ;
} else {
V_127 = F_63 ( F_62 ( V_24 ) , V_49 ) ;
if ( NULL == V_127 )
return - V_50 ;
V_128 = V_127 ;
}
V_9 = - V_132 ;
if ( F_64 ( V_128 , ( void V_133 * ) V_25 , F_62 ( V_24 ) ) )
goto V_134;
break;
}
if ( ( V_9 = F_60 ( V_2 , V_24 , V_128 ) ) == - V_135 )
V_9 = - V_136 ;
if ( V_9 < 0 )
goto V_134;
switch ( F_61 ( V_24 ) )
{
case V_130 :
case ( V_131 | V_130 ) :
if ( F_65 ( ( void V_133 * ) V_25 , V_128 , F_62 ( V_24 ) ) )
V_9 = - V_132 ;
break;
}
V_134:
F_18 ( V_127 ) ;
return V_9 ;
}
static int F_66 ( struct V_88 * V_32 , struct V_137 * V_138 )
{
struct V_3 * V_4 = F_67 ( V_32 ) ;
F_68 ( V_138 , L_10 , V_4 -> V_44 -> V_98 ) ;
F_68 ( V_138 , L_11 , V_100 [ V_4 -> type ] ) ;
F_68 ( V_138 , L_12 , V_4 -> V_30 ) ;
return 0 ;
}
static char * F_69 ( struct V_88 * V_32 , T_2 * V_139 )
{
struct V_3 * V_4 = F_67 ( V_32 ) ;
return F_22 ( V_49 , L_13 ,
V_4 -> V_44 -> V_98 , V_100 [ V_4 -> type ] , V_4 -> V_30 ) ;
}
static int T_3 F_70 ( void )
{
int V_140 ;
T_4 V_32 = F_39 ( V_81 , 0 ) ;
if ( ( V_140 = F_71 ( V_32 , V_97 , L_14 ) ) != 0 ) {
F_27 ( V_91 L_15 , V_81 ) ;
return V_140 ;
}
F_72 ( & V_141 , & V_142 ) ;
if ( ( V_140 = F_73 ( & V_141 , V_32 , V_97 ) ) != 0 ) {
F_27 ( V_91 L_16 ) ;
goto error;
}
V_99 = F_74 ( V_143 , L_17 ) ;
if ( F_40 ( V_99 ) ) {
V_140 = F_41 ( V_99 ) ;
goto error;
}
V_99 -> V_144 = F_66 ;
V_99 -> V_145 = F_69 ;
return 0 ;
error:
F_75 ( & V_141 ) ;
F_76 ( V_32 , V_97 ) ;
return V_140 ;
}
static void T_5 F_77 ( void )
{
F_78 ( V_99 ) ;
F_75 ( & V_141 ) ;
F_76 ( F_39 ( V_81 , 0 ) , V_97 ) ;
}
