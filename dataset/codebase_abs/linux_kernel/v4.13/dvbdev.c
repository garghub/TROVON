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
F_27 ( L_2 ,
V_70 , V_4 -> V_36 -> V_41 ) ;
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
int type , int V_71 ,
unsigned V_58 )
{
#if F_16 ( V_35 )
struct V_72 * V_73 ;
T_1 V_74 ;
int V_48 ;
if ( ! V_4 -> V_44 -> V_57 )
return 0 ;
V_48 = F_25 ( V_4 , type , V_58 ) ;
if ( V_48 )
return V_48 ;
switch ( type ) {
case V_59 :
V_74 = V_75 ;
break;
case V_62 :
V_74 = V_76 ;
break;
case V_60 :
V_74 = V_77 ;
break;
case V_64 :
V_74 = V_78 ;
break;
case V_65 :
V_74 = V_79 ;
break;
default:
return 0 ;
}
V_4 -> V_43 = F_29 ( V_4 -> V_44 -> V_57 ,
V_74 , 0 ,
V_80 , V_71 ) ;
if ( ! V_4 -> V_43 )
return - V_50 ;
if ( ! V_4 -> V_36 )
return 0 ;
V_73 = F_30 ( V_4 -> V_36 , & V_4 -> V_43 -> V_81 ,
V_82 ) ;
if ( ! V_73 )
return - V_50 ;
#endif
return 0 ;
}
int F_31 ( struct V_28 * V_29 , struct V_3 * * V_83 ,
const struct V_3 * V_84 , void * V_85 , int type ,
int V_58 )
{
struct V_3 * V_4 ;
struct V_10 * V_86 ;
struct V_87 * V_88 ;
int V_71 ;
int V_30 , V_48 ;
F_2 ( & V_89 ) ;
if ( ( V_30 = F_13 ( V_29 , type ) ) < 0 ) {
F_8 ( & V_89 ) ;
* V_83 = NULL ;
F_32 ( L_3 , V_70 ) ;
return - V_34 ;
}
* V_83 = V_4 = F_26 ( sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 ) {
F_8 ( & V_89 ) ;
return - V_50 ;
}
V_86 = F_26 ( sizeof( struct V_10 ) , V_49 ) ;
if ( ! V_86 ) {
F_18 ( V_4 ) ;
F_8 ( & V_89 ) ;
return - V_50 ;
}
memcpy ( V_4 , V_84 , sizeof( struct V_3 ) ) ;
V_4 -> type = type ;
V_4 -> V_30 = V_30 ;
V_4 -> V_44 = V_29 ;
V_4 -> V_85 = V_85 ;
V_4 -> V_8 = V_86 ;
F_33 ( & V_4 -> V_90 ) ;
memcpy ( V_86 , V_84 -> V_8 , sizeof( struct V_10 ) ) ;
V_86 -> V_91 = V_29 -> V_92 ;
F_34 ( & V_4 -> V_93 , & V_29 -> V_94 ) ;
F_35 ( & V_6 ) ;
#ifdef F_36
for ( V_71 = 0 ; V_71 < V_95 ; V_71 ++ )
if ( V_7 [ V_71 ] == NULL )
break;
if ( V_71 == V_95 ) {
F_18 ( V_86 ) ;
F_18 ( V_4 ) ;
F_37 ( & V_6 ) ;
F_8 ( & V_89 ) ;
return - V_27 ;
}
#else
V_71 = F_38 ( V_29 -> V_96 , type , V_30 ) ;
#endif
V_4 -> V_71 = V_71 ;
V_7 [ V_71 ] = V_4 ;
F_37 ( & V_6 ) ;
V_48 = F_28 ( V_4 , type , V_71 , V_58 ) ;
if ( V_48 ) {
F_32 ( L_4 ,
V_70 ) ;
F_15 ( V_4 ) ;
F_18 ( V_86 ) ;
F_18 ( V_4 ) ;
F_37 ( & V_6 ) ;
F_8 ( & V_89 ) ;
return V_48 ;
}
F_8 ( & V_89 ) ;
V_88 = F_39 ( V_97 , V_29 -> V_87 ,
F_40 ( V_80 , V_71 ) ,
V_4 , L_5 , V_29 -> V_96 , V_98 [ type ] , V_30 ) ;
if ( F_41 ( V_88 ) ) {
F_32 ( L_6 ,
V_70 , V_29 -> V_96 , V_98 [ type ] , V_30 , F_42 ( V_88 ) ) ;
return F_42 ( V_88 ) ;
}
F_43 ( L_7 ,
V_29 -> V_96 , V_98 [ type ] , V_30 , V_71 , V_71 ) ;
return 0 ;
}
void F_44 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_35 ( & V_6 ) ;
V_7 [ V_4 -> V_71 ] = NULL ;
F_37 ( & V_6 ) ;
F_15 ( V_4 ) ;
F_45 ( V_97 , F_40 ( V_80 , V_4 -> V_71 ) ) ;
F_46 ( & V_4 -> V_93 ) ;
}
void F_47 ( struct V_3 * V_4 )
{
if ( ! V_4 )
return;
F_18 ( V_4 -> V_8 ) ;
F_18 ( V_4 ) ;
}
void F_48 ( struct V_3 * V_4 )
{
F_44 ( V_4 ) ;
F_47 ( V_4 ) ;
}
static int F_49 ( struct V_28 * V_29 ,
struct V_99 * V_81 ,
char * V_41 )
{
struct V_100 * V_57 = V_29 -> V_57 ;
struct V_52 * V_36 ;
struct V_72 * V_73 ;
F_50 (entity, mdev) {
if ( V_36 -> V_53 == V_54 ) {
if ( strncmp ( V_36 -> V_41 , V_41 , strlen ( V_41 ) ) )
continue;
V_73 = F_30 ( V_36 , V_81 ,
V_82 ) ;
if ( ! V_73 )
return - V_50 ;
}
}
return 0 ;
}
int F_51 ( struct V_28 * V_29 ,
bool V_101 )
{
struct V_100 * V_57 = V_29 -> V_57 ;
struct V_52 * V_36 , * V_102 = NULL , * V_103 = NULL , * V_45 ;
struct V_52 * V_104 = NULL , * V_105 = NULL ;
struct V_72 * V_73 ;
struct V_99 * V_81 ;
unsigned V_106 = 0 ;
unsigned V_107 = 0 ;
unsigned V_108 = 0 , V_109 = 0 ;
int V_48 ;
static const char * V_110 = L_8 ;
if ( ! V_57 )
return 0 ;
F_50 (entity, mdev) {
switch ( V_36 -> V_53 ) {
case V_111 :
V_102 = V_36 ;
V_108 ++ ;
break;
case V_66 :
V_103 = V_36 ;
V_109 ++ ;
break;
case V_68 :
V_104 = V_36 ;
break;
case V_69 :
V_105 = V_36 ;
break;
}
}
if ( V_108 > 1 )
V_102 = NULL ;
if ( V_109 > 1 )
V_103 = NULL ;
if ( V_101 ) {
V_45 = F_26 ( sizeof( * V_45 ) , V_49 ) ;
if ( ! V_45 )
return - V_50 ;
V_29 -> V_45 = V_45 ;
V_29 -> V_46 = F_26 ( sizeof( * V_29 -> V_46 ) , V_49 ) ;
if ( ! V_29 -> V_46 )
return - V_50 ;
V_45 -> V_55 = V_112 ;
V_45 -> V_53 = V_113 ;
V_45 -> V_41 = V_110 ;
V_29 -> V_46 -> V_55 = V_67 ;
V_48 = F_23 ( V_45 , 1 , V_29 -> V_46 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_24 ( V_57 , V_45 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_108 )
V_48 = F_52 ( V_57 ,
V_113 ,
V_45 , 0 ,
V_66 ,
V_103 , 0 ,
V_82 ,
false ) ;
else
V_48 = F_52 ( V_57 ,
V_113 ,
V_45 , 0 ,
V_111 ,
V_102 , V_114 ,
V_82 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_108 && V_109 ) {
V_48 = F_52 ( V_57 ,
V_111 ,
V_102 , V_115 ,
V_66 ,
V_103 , 0 , V_82 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_109 && V_104 ) {
V_48 = F_52 ( V_57 ,
V_66 ,
V_103 , 1 ,
V_68 ,
V_104 , 0 , V_82 ,
false ) ;
if ( V_48 )
return V_48 ;
}
if ( V_104 && V_105 ) {
V_48 = F_53 ( V_104 , 1 , V_105 ,
0 , V_82 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_104 ) {
F_50 (entity, mdev) {
if ( V_36 -> V_53 == V_54 ) {
if ( ! strncmp ( V_36 -> V_41 , V_61 ,
strlen ( V_61 ) ) ) {
V_48 = F_53 ( V_104 ,
++ V_107 ,
V_36 , 0 , 0 ) ;
if ( V_48 )
return V_48 ;
}
if ( ! strncmp ( V_36 -> V_41 , V_63 ,
strlen ( V_63 ) ) ) {
V_48 = F_53 ( V_104 ,
++ V_106 ,
V_36 , 0 , 0 ) ;
if ( V_48 )
return V_48 ;
}
}
}
}
F_54 (intf, mdev) {
if ( V_81 -> type == V_78 && V_105 ) {
V_73 = F_30 ( V_105 , V_81 ,
V_82 ) ;
if ( ! V_73 )
return - V_50 ;
}
if ( V_81 -> type == V_75 && V_102 ) {
V_73 = F_30 ( V_102 , V_81 ,
V_82 ) ;
if ( ! V_73 )
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
if ( V_81 -> type == V_77 ) {
V_48 = F_49 ( V_29 , V_81 , V_61 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_81 -> type == V_76 ) {
V_48 = F_49 ( V_29 , V_81 , V_63 ) ;
if ( V_48 )
return V_48 ;
}
}
return 0 ;
}
static int F_55 ( int V_96 )
{
struct V_93 * V_116 ;
F_56 (entry, &dvb_adapter_list) {
struct V_28 * V_29 ;
V_29 = F_57 ( V_116 , struct V_28 , V_93 ) ;
if ( V_29 -> V_96 == V_96 )
return 0 ;
}
return 1 ;
}
static int F_58 ( void )
{
int V_96 = 0 ;
while ( V_96 < V_117 ) {
if ( F_55 ( V_96 ) )
return V_96 ;
V_96 ++ ;
}
return - V_34 ;
}
int F_59 ( struct V_28 * V_29 , const char * V_41 ,
struct V_92 * V_92 , struct V_87 * V_87 ,
short * V_118 )
{
int V_39 , V_96 ;
F_2 ( & V_89 ) ;
for ( V_39 = 0 ; V_39 < V_117 ; ++ V_39 ) {
V_96 = V_118 [ V_39 ] ;
if ( V_96 >= 0 && V_96 < V_117 ) {
if ( F_55 ( V_96 ) )
break;
} else {
V_96 = F_58 () ;
break;
}
V_96 = - 1 ;
}
if ( V_96 < 0 ) {
F_8 ( & V_89 ) ;
return - V_34 ;
}
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
F_60 ( & V_29 -> V_94 ) ;
F_27 ( L_9 , V_41 ) ;
V_29 -> V_96 = V_96 ;
V_29 -> V_41 = V_41 ;
V_29 -> V_92 = V_92 ;
V_29 -> V_87 = V_87 ;
V_29 -> V_119 = 0 ;
V_29 -> V_120 = NULL ;
F_61 ( & V_29 -> V_121 ) ;
F_34 ( & V_29 -> V_93 , & V_122 ) ;
F_8 ( & V_89 ) ;
return V_96 ;
}
int F_62 ( struct V_28 * V_29 )
{
F_2 ( & V_89 ) ;
F_46 ( & V_29 -> V_93 ) ;
F_8 ( & V_89 ) ;
return 0 ;
}
int F_12 ( struct V_2 * V_2 ,
unsigned int V_24 , unsigned long V_25 ,
int (* F_63)( struct V_2 * V_2 ,
unsigned int V_24 , void * V_25 ) )
{
char V_123 [ 128 ] ;
void * V_124 = NULL ;
void * V_125 = NULL ;
int V_9 = - V_27 ;
switch ( F_64 ( V_24 ) ) {
case V_126 :
V_125 = ( void * ) V_25 ;
break;
case V_127 :
case V_128 :
case ( V_128 | V_127 ) :
if ( F_65 ( V_24 ) <= sizeof( V_123 ) ) {
V_125 = V_123 ;
} else {
V_124 = F_66 ( F_65 ( V_24 ) , V_49 ) ;
if ( NULL == V_124 )
return - V_50 ;
V_125 = V_124 ;
}
V_9 = - V_129 ;
if ( F_67 ( V_125 , ( void V_130 * ) V_25 , F_65 ( V_24 ) ) )
goto V_131;
break;
}
if ( ( V_9 = F_63 ( V_2 , V_24 , V_125 ) ) == - V_132 )
V_9 = - V_133 ;
if ( V_9 < 0 )
goto V_131;
switch ( F_64 ( V_24 ) )
{
case V_127 :
case ( V_128 | V_127 ) :
if ( F_68 ( ( void V_130 * ) V_25 , V_125 , F_65 ( V_24 ) ) )
V_9 = - V_129 ;
break;
}
V_131:
F_18 ( V_124 ) ;
return V_9 ;
}
static int F_69 ( struct V_87 * V_32 , struct V_134 * V_135 )
{
struct V_3 * V_4 = F_70 ( V_32 ) ;
F_71 ( V_135 , L_10 , V_4 -> V_44 -> V_96 ) ;
F_71 ( V_135 , L_11 , V_98 [ V_4 -> type ] ) ;
F_71 ( V_135 , L_12 , V_4 -> V_30 ) ;
return 0 ;
}
static char * F_72 ( struct V_87 * V_32 , T_2 * V_136 )
{
struct V_3 * V_4 = F_70 ( V_32 ) ;
return F_22 ( V_49 , L_13 ,
V_4 -> V_44 -> V_96 , V_98 [ V_4 -> type ] , V_4 -> V_30 ) ;
}
static int T_3 F_73 ( void )
{
int V_137 ;
T_4 V_32 = F_40 ( V_80 , 0 ) ;
if ( ( V_137 = F_74 ( V_32 , V_95 , L_14 ) ) != 0 ) {
F_32 ( L_15 , V_80 ) ;
return V_137 ;
}
F_75 ( & V_138 , & V_139 ) ;
if ( ( V_137 = F_76 ( & V_138 , V_32 , V_95 ) ) != 0 ) {
F_32 ( L_16 ) ;
goto error;
}
V_97 = F_77 ( V_140 , L_17 ) ;
if ( F_41 ( V_97 ) ) {
V_137 = F_42 ( V_97 ) ;
goto error;
}
V_97 -> V_141 = F_69 ;
V_97 -> V_142 = F_72 ;
return 0 ;
error:
F_78 ( & V_138 ) ;
F_79 ( V_32 , V_95 ) ;
return V_137 ;
}
static void T_5 F_80 ( void )
{
F_81 ( V_97 ) ;
F_78 ( & V_138 ) ;
F_79 ( F_40 ( V_80 , 0 ) , V_95 ) ;
}
