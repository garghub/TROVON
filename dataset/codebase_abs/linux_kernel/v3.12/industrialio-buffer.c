static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 (p, &indio_dev->buffer_list)
if ( V_6 == & V_4 -> V_7 )
return true ;
return false ;
}
T_1 F_3 ( struct V_8 * V_9 , char T_2 * V_4 ,
T_3 V_10 , T_4 * V_11 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
struct V_3 * V_13 = V_2 -> V_14 ;
if ( ! V_13 || ! V_13 -> V_15 -> V_16 )
return - V_17 ;
return V_13 -> V_15 -> V_16 ( V_13 , V_10 , V_4 ) ;
}
unsigned int F_4 ( struct V_8 * V_9 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_9 -> V_12 ;
struct V_3 * V_13 = V_2 -> V_14 ;
F_5 ( V_9 , & V_13 -> V_20 , V_19 ) ;
if ( V_13 -> V_21 )
return V_22 | V_23 ;
return 0 ;
}
void F_6 ( struct V_3 * V_14 )
{
F_7 ( & V_14 -> V_24 ) ;
F_8 ( & V_14 -> V_20 ) ;
}
static T_1 F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
return sprintf ( V_4 , L_1 , F_10 ( V_28 ) -> V_29 -> V_30 ) ;
}
static T_1 F_11 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
struct V_31 * V_32 = F_10 ( V_28 ) ;
T_5 type = V_32 -> V_29 -> V_33 . V_34 ;
if ( type == V_35 ) {
#ifdef F_12
type = V_36 ;
#else
type = V_37 ;
#endif
}
return sprintf ( V_4 , L_2 ,
V_38 [ type ] ,
V_32 -> V_29 -> V_33 . V_39 ,
V_32 -> V_29 -> V_33 . V_40 ,
V_32 -> V_29 -> V_33 . V_41 ,
V_32 -> V_29 -> V_33 . V_42 ) ;
}
static T_1 F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
int V_43 ;
struct V_1 * V_2 = F_14 ( V_26 ) ;
V_43 = F_15 ( F_10 ( V_28 ) -> V_44 ,
V_2 -> V_14 -> V_45 ) ;
return sprintf ( V_4 , L_3 , V_43 ) ;
}
static int F_16 ( struct V_3 * V_14 , int V_46 )
{
F_17 ( V_46 , V_14 -> V_45 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_4 ,
T_3 V_47 )
{
int V_43 ;
bool V_48 ;
struct V_1 * V_2 = F_14 ( V_26 ) ;
struct V_3 * V_14 = V_2 -> V_14 ;
struct V_31 * V_32 = F_10 ( V_28 ) ;
V_43 = F_19 ( V_4 , & V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
F_20 ( & V_2 -> V_49 ) ;
if ( F_1 ( V_2 , V_2 -> V_14 ) ) {
V_43 = - V_50 ;
goto V_51;
}
V_43 = F_21 ( V_2 , V_14 , V_32 -> V_44 ) ;
if ( V_43 < 0 )
goto V_51;
if ( ! V_48 && V_43 ) {
V_43 = F_16 ( V_14 , V_32 -> V_44 ) ;
if ( V_43 )
goto V_51;
} else if ( V_48 && ! V_43 ) {
V_43 = F_22 ( V_2 , V_14 , V_32 -> V_44 ) ;
if ( V_43 )
goto V_51;
}
V_51:
F_23 ( & V_2 -> V_49 ) ;
return V_43 < 0 ? V_43 : V_47 ;
}
static T_1 F_24 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
struct V_1 * V_2 = F_14 ( V_26 ) ;
return sprintf ( V_4 , L_3 , V_2 -> V_14 -> V_52 ) ;
}
static T_1 F_25 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_4 ,
T_3 V_47 )
{
int V_43 ;
struct V_1 * V_2 = F_14 ( V_26 ) ;
bool V_48 ;
V_43 = F_19 ( V_4 , & V_48 ) ;
if ( V_43 < 0 )
return V_43 ;
F_20 ( & V_2 -> V_49 ) ;
if ( F_1 ( V_2 , V_2 -> V_14 ) ) {
V_43 = - V_50 ;
goto V_51;
}
V_2 -> V_14 -> V_52 = V_48 ;
V_51:
F_23 ( & V_2 -> V_49 ) ;
return V_43 ? V_43 : V_47 ;
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_53 * V_54 )
{
int V_43 , V_55 = 0 ;
struct V_3 * V_14 = V_2 -> V_14 ;
V_43 = F_27 ( L_4 ,
V_54 ,
& F_9 ,
NULL ,
0 ,
0 ,
& V_2 -> V_26 ,
& V_14 -> V_56 ) ;
if ( V_43 )
goto V_51;
V_55 ++ ;
V_43 = F_27 ( L_5 ,
V_54 ,
& F_11 ,
NULL ,
0 ,
0 ,
& V_2 -> V_26 ,
& V_14 -> V_56 ) ;
if ( V_43 )
goto V_51;
V_55 ++ ;
if ( V_54 -> type != V_57 )
V_43 = F_27 ( L_6 ,
V_54 ,
& F_13 ,
& F_18 ,
V_54 -> V_30 ,
0 ,
& V_2 -> V_26 ,
& V_14 -> V_56 ) ;
else
V_43 = F_27 ( L_6 ,
V_54 ,
& F_24 ,
& F_25 ,
V_54 -> V_30 ,
0 ,
& V_2 -> V_26 ,
& V_14 -> V_56 ) ;
V_55 ++ ;
V_43 = V_55 ;
V_51:
return V_43 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_31 * V_6 )
{
F_29 ( V_6 -> V_58 . V_28 . V_59 ) ;
F_29 ( V_6 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_31 * V_6 , * V_10 ;
struct V_3 * V_14 = V_2 -> V_14 ;
F_31 (p, n,
&buffer->scan_el_dev_attr_list, l)
F_28 ( V_2 , V_6 ) ;
}
int F_32 ( struct V_1 * V_2 ,
const struct V_53 * V_60 ,
int V_61 )
{
struct V_31 * V_6 ;
struct V_62 * * V_28 ;
struct V_3 * V_14 = V_2 -> V_14 ;
int V_43 , V_63 , V_64 , V_55 , V_65 = 0 ;
if ( V_14 -> V_66 )
V_2 -> V_67 [ V_2 -> V_68 ++ ] = V_14 -> V_66 ;
if ( V_14 -> V_69 != NULL ) {
V_28 = V_14 -> V_69 -> V_66 ;
while ( * V_28 ++ != NULL )
V_65 ++ ;
}
V_55 = V_65 ;
F_7 ( & V_14 -> V_56 ) ;
if ( V_60 ) {
for ( V_63 = 0 ; V_63 < V_61 ; V_63 ++ ) {
if ( V_60 [ V_63 ] . V_30 < 0 )
continue;
if ( V_60 [ V_63 ] . V_30 >
( int ) V_2 -> V_70 - 1 )
V_2 -> V_70
= V_60 [ V_63 ] . V_30 + 1 ;
V_43 = F_26 ( V_2 ,
& V_60 [ V_63 ] ) ;
if ( V_43 < 0 )
goto V_71;
V_55 += V_43 ;
if ( V_60 [ V_63 ] . type == V_57 )
V_2 -> V_72 =
V_60 [ V_63 ] . V_30 ;
}
if ( V_2 -> V_70 && V_14 -> V_45 == NULL ) {
V_14 -> V_45 = F_33 ( F_34 ( V_2 -> V_70 ) ,
sizeof( * V_14 -> V_45 ) ,
V_73 ) ;
if ( V_14 -> V_45 == NULL ) {
V_43 = - V_74 ;
goto V_71;
}
}
}
V_14 -> V_75 . V_59 = V_76 ;
V_14 -> V_75 . V_66 = F_33 ( V_55 + 1 ,
sizeof( V_14 -> V_75 . V_66 [ 0 ] ) ,
V_73 ) ;
if ( V_14 -> V_75 . V_66 == NULL ) {
V_43 = - V_74 ;
goto V_77;
}
if ( V_14 -> V_69 )
memcpy ( V_14 -> V_75 . V_66 , V_14 -> V_69 ,
sizeof( V_14 -> V_75 . V_66 [ 0 ] ) * V_65 ) ;
V_64 = V_65 ;
F_35 (p, &buffer->scan_el_dev_attr_list, l)
V_14 -> V_75 . V_66 [ V_64 ++ ] = & V_6 -> V_58 . V_28 ;
V_2 -> V_67 [ V_2 -> V_68 ++ ] = & V_14 -> V_75 ;
return 0 ;
V_77:
F_29 ( V_14 -> V_45 ) ;
V_71:
F_30 ( V_2 ) ;
return V_43 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_14 -> V_45 ) ;
F_29 ( V_2 -> V_14 -> V_75 . V_66 ) ;
F_30 ( V_2 ) ;
}
T_1 F_37 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
struct V_1 * V_2 = F_14 ( V_26 ) ;
struct V_3 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_15 -> V_78 )
return sprintf ( V_4 , L_3 ,
V_14 -> V_15 -> V_78 ( V_14 ) ) ;
return 0 ;
}
T_1 F_38 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_4 ,
T_3 V_47 )
{
struct V_1 * V_2 = F_14 ( V_26 ) ;
struct V_3 * V_14 = V_2 -> V_14 ;
unsigned int V_79 ;
int V_43 ;
V_43 = F_39 ( V_4 , 10 , & V_79 ) ;
if ( V_43 )
return V_43 ;
if ( V_14 -> V_15 -> V_78 )
if ( V_79 == V_14 -> V_15 -> V_78 ( V_14 ) )
return V_47 ;
F_20 ( & V_2 -> V_49 ) ;
if ( F_1 ( V_2 , V_2 -> V_14 ) ) {
V_43 = - V_50 ;
} else {
if ( V_14 -> V_15 -> V_80 )
V_14 -> V_15 -> V_80 ( V_14 , V_79 ) ;
V_43 = 0 ;
}
F_23 ( & V_2 -> V_49 ) ;
return V_43 ? V_43 : V_47 ;
}
T_1 F_40 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_4 )
{
struct V_1 * V_2 = F_14 ( V_26 ) ;
return sprintf ( V_4 , L_3 ,
F_1 ( V_2 ,
V_2 -> V_14 ) ) ;
}
static const unsigned long * F_41 ( const unsigned long * V_81 ,
unsigned int V_70 ,
const unsigned long * V_82 )
{
if ( F_42 ( V_82 , V_70 ) )
return NULL ;
while ( * V_81 ) {
if ( F_43 ( V_82 , V_81 , V_70 ) )
return V_81 ;
V_81 += F_34 ( V_70 ) ;
}
return NULL ;
}
static int F_44 ( struct V_1 * V_2 , const long * V_82 ,
bool V_83 )
{
const struct V_53 * V_84 ;
unsigned V_85 = 0 ;
int V_86 , V_63 ;
F_45 (i, mask,
indio_dev->masklength) {
V_84 = F_46 ( V_2 , V_63 ) ;
V_86 = V_84 -> V_33 . V_41 / 8 ;
V_85 = F_47 ( V_85 , V_86 ) ;
V_85 += V_86 ;
}
if ( V_83 ) {
V_84 = F_46 ( V_2 ,
V_2 -> V_72 ) ;
V_86 = V_84 -> V_33 . V_41 / 8 ;
V_85 = F_47 ( V_85 , V_86 ) ;
V_85 += V_86 ;
}
return V_85 ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_14 , * V_87 ;
if ( F_49 ( & V_2 -> V_7 ) )
return;
if ( V_2 -> V_88 -> V_89 )
V_2 -> V_88 -> V_89 ( V_2 ) ;
F_31 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_50 ( & V_14 -> V_7 ) ;
V_2 -> V_90 = V_91 ;
if ( V_2 -> V_88 -> V_92 )
V_2 -> V_88 -> V_92 ( V_2 ) ;
if ( V_2 -> V_93 == NULL )
F_29 ( V_2 -> V_94 ) ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_95 ,
struct V_3 * V_96 )
{
int V_43 ;
int V_97 = 0 ;
struct V_3 * V_14 ;
unsigned long * V_98 ;
const unsigned long * V_99 ;
if ( ! F_49 ( & V_2 -> V_7 ) ) {
if ( V_2 -> V_88 -> V_89 ) {
V_43 = V_2 -> V_88 -> V_89 ( V_2 ) ;
if ( V_43 )
goto V_51;
}
V_2 -> V_90 = V_91 ;
if ( V_2 -> V_88 -> V_92 ) {
V_43 = V_2 -> V_88 -> V_92 ( V_2 ) ;
if ( V_43 )
goto V_51;
}
}
V_99 = V_2 -> V_94 ;
if ( ! V_2 -> V_93 )
V_2 -> V_94 = NULL ;
if ( V_96 )
F_52 ( & V_96 -> V_7 ) ;
if ( V_95 )
F_53 ( & V_95 -> V_7 , & V_2 -> V_7 ) ;
if ( F_49 ( & V_2 -> V_7 ) ) {
V_2 -> V_90 = V_91 ;
if ( V_2 -> V_93 == NULL )
F_29 ( V_99 ) ;
return 0 ;
}
V_98 = F_33 ( F_34 ( V_2 -> V_70 ) ,
sizeof( long ) , V_73 ) ;
if ( V_98 == NULL ) {
if ( V_2 -> V_93 == NULL )
F_29 ( V_99 ) ;
return - V_74 ;
}
V_2 -> V_52 = 0 ;
F_35 (buffer, &indio_dev->buffer_list, buffer_list) {
F_54 ( V_98 , V_98 , V_14 -> V_45 ,
V_2 -> V_70 ) ;
V_2 -> V_52 |= V_14 -> V_52 ;
}
if ( V_2 -> V_93 ) {
V_2 -> V_94 =
F_41 ( V_2 -> V_93 ,
V_2 -> V_70 ,
V_98 ) ;
if ( V_2 -> V_94 == NULL ) {
F_52 ( & V_95 -> V_7 ) ;
if ( V_99 ) {
V_2 -> V_94 = V_99 ;
V_97 = - V_17 ;
}
else {
F_29 ( V_98 ) ;
V_43 = - V_17 ;
goto V_51;
}
}
} else {
V_2 -> V_94 = V_98 ;
}
F_55 ( V_2 ) ;
if ( V_2 -> V_88 -> V_100 ) {
V_43 = V_2 -> V_88 -> V_100 ( V_2 ) ;
if ( V_43 ) {
F_56 ( V_101
L_7 , V_43 ) ;
goto V_102;
}
}
V_2 -> V_103 =
F_44 ( V_2 ,
V_2 -> V_94 ,
V_2 -> V_52 ) ;
F_35 (buffer, &indio_dev->buffer_list, buffer_list)
if ( V_14 -> V_15 -> V_104 ) {
V_43 = V_14 -> V_15 -> V_104 ( V_14 ) ;
if ( V_43 ) {
F_56 ( V_105
L_8 , V_43 ) ;
goto V_106;
}
}
if ( V_2 -> V_107 -> V_108 ) {
V_43 = V_2 -> V_107
-> V_108 ( V_2 ,
V_2 -> V_94 ) ;
if ( V_43 < 0 ) {
F_56 ( V_105 L_9 , V_43 ) ;
goto V_106;
}
}
if ( V_2 -> V_109 & V_110 ) {
if ( ! V_2 -> V_111 ) {
F_56 ( V_105 L_10 ) ;
V_43 = - V_17 ;
goto V_106;
}
V_2 -> V_90 = V_110 ;
} else if ( V_2 -> V_109 & V_112 ) {
V_2 -> V_90 = V_112 ;
} else {
V_43 = - V_17 ;
goto V_106;
}
if ( V_2 -> V_88 -> V_113 ) {
V_43 = V_2 -> V_88 -> V_113 ( V_2 ) ;
if ( V_43 ) {
F_56 ( V_105
L_11 , V_43 ) ;
V_2 -> V_90 = V_91 ;
if ( V_2 -> V_88 -> V_92 )
V_2 -> V_88 -> V_92 ( V_2 ) ;
goto V_114;
}
}
if ( V_2 -> V_93 )
F_29 ( V_98 ) ;
else
F_29 ( V_99 ) ;
return V_97 ;
V_114:
V_2 -> V_90 = V_91 ;
V_106:
if ( V_2 -> V_88 -> V_92 )
V_2 -> V_88 -> V_92 ( V_2 ) ;
V_102:
if ( V_95 )
F_52 ( & V_95 -> V_7 ) ;
V_2 -> V_94 = V_99 ;
F_29 ( V_98 ) ;
V_51:
return V_43 ;
}
T_1 F_57 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_4 ,
T_3 V_47 )
{
int V_43 ;
bool V_115 ;
struct V_1 * V_2 = F_14 ( V_26 ) ;
struct V_3 * V_116 = V_2 -> V_14 ;
bool V_117 ;
V_43 = F_19 ( V_4 , & V_115 ) ;
if ( V_43 < 0 )
return V_43 ;
F_20 ( & V_2 -> V_49 ) ;
V_117 = F_1 ( V_2 , V_116 ) ;
if ( V_117 == V_115 )
goto V_118;
if ( V_115 )
V_43 = F_51 ( V_2 ,
V_2 -> V_14 , NULL ) ;
else
V_43 = F_51 ( V_2 ,
NULL , V_2 -> V_14 ) ;
if ( V_43 < 0 )
goto V_118;
V_118:
F_23 ( & V_2 -> V_49 ) ;
return ( V_43 < 0 ) ? V_43 : V_47 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_14 ;
unsigned V_85 ;
F_59 ( & V_2 -> V_26 , L_12 , V_119 ) ;
F_35 (buffer, &indio_dev->buffer_list, buffer_list)
if ( V_14 -> V_15 -> V_120 ) {
V_85 = F_44 ( V_2 ,
V_14 -> V_45 ,
V_14 -> V_52 ) ;
V_14 -> V_15 -> V_120 ( V_14 , V_85 ) ;
}
return 0 ;
}
bool F_60 ( struct V_1 * V_2 ,
const unsigned long * V_82 )
{
return F_61 ( V_82 , V_2 -> V_70 ) == 1 ;
}
static bool F_62 ( struct V_1 * V_2 ,
const unsigned long * V_82 )
{
if ( ! V_2 -> V_88 -> V_121 )
return true ;
return V_2 -> V_88 -> V_121 ( V_2 , V_82 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_14 , int V_46 )
{
const unsigned long * V_82 ;
unsigned long * V_122 ;
V_122 = F_63 ( sizeof( * V_122 ) *
F_34 ( V_2 -> V_70 ) ,
V_73 ) ;
if ( V_122 == NULL )
return - V_74 ;
if ( ! V_2 -> V_70 ) {
F_64 ( L_13 ) ;
goto V_123;
}
F_65 ( V_122 , V_14 -> V_45 , V_2 -> V_70 ) ;
F_66 ( V_46 , V_122 ) ;
if ( ! F_62 ( V_2 , V_122 ) )
goto V_123;
if ( V_2 -> V_93 ) {
V_82 = F_41 ( V_2 -> V_93 ,
V_2 -> V_70 ,
V_122 ) ;
if ( ! V_82 )
goto V_123;
}
F_65 ( V_14 -> V_45 , V_122 , V_2 -> V_70 ) ;
F_29 ( V_122 ) ;
return 0 ;
V_123:
F_29 ( V_122 ) ;
return - V_17 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_14 , int V_46 )
{
if ( V_46 > V_2 -> V_70 )
return - V_17 ;
if ( ! V_14 -> V_45 )
return 0 ;
return F_15 ( V_46 , V_14 -> V_45 ) ;
}
static unsigned char * F_67 ( struct V_3 * V_14 ,
unsigned char * V_124 )
{
struct V_125 * V_126 ;
if ( F_49 ( & V_14 -> V_24 ) )
return V_124 ;
F_35 (t, &buffer->demux_list, l)
memcpy ( V_14 -> V_127 + V_126 -> V_128 ,
V_124 + V_126 -> V_129 , V_126 -> V_86 ) ;
return V_14 -> V_127 ;
}
static int F_68 ( struct V_3 * V_14 , unsigned char * V_130 )
{
unsigned char * V_131 = F_67 ( V_14 , V_130 ) ;
return V_14 -> V_15 -> V_132 ( V_14 , V_131 ) ;
}
static void F_69 ( struct V_3 * V_14 )
{
struct V_125 * V_6 , * V_133 ;
F_31 (p, q, &buffer->demux_list, l) {
F_52 ( & V_6 -> V_134 ) ;
F_29 ( V_6 ) ;
}
}
int F_70 ( struct V_1 * V_2 , unsigned char * V_130 )
{
int V_43 ;
struct V_3 * V_4 ;
F_35 (buf, &indio_dev->buffer_list, buffer_list) {
V_43 = F_68 ( V_4 , V_130 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_3 * V_14 )
{
const struct V_53 * V_84 ;
int V_43 , V_135 = - 1 , V_136 , V_86 ;
unsigned V_137 = 0 , V_138 = 0 ;
struct V_125 * V_6 ;
F_69 ( V_14 ) ;
F_29 ( V_14 -> V_127 ) ;
V_14 -> V_127 = NULL ;
if ( F_72 ( V_2 -> V_94 ,
V_14 -> V_45 ,
V_2 -> V_70 ) )
return 0 ;
F_45 (out_ind,
indio_dev->active_scan_mask,
indio_dev->masklength) {
V_135 = F_73 ( V_2 -> V_94 ,
V_2 -> V_70 ,
V_135 + 1 ) ;
while ( V_135 != V_136 ) {
V_135 = F_73 ( V_2 -> V_94 ,
V_2 -> V_70 ,
V_135 + 1 ) ;
V_84 = F_46 ( V_2 , V_135 ) ;
V_86 = V_84 -> V_33 . V_41 / 8 ;
V_137 += V_86 ;
if ( V_137 % V_86 )
V_137 += V_86 - V_137 % V_86 ;
}
V_6 = F_63 ( sizeof( * V_6 ) , V_73 ) ;
if ( V_6 == NULL ) {
V_43 = - V_74 ;
goto V_139;
}
V_84 = F_46 ( V_2 , V_135 ) ;
V_86 = V_84 -> V_33 . V_41 / 8 ;
if ( V_138 % V_86 )
V_138 += V_86 - V_138 % V_86 ;
if ( V_137 % V_86 )
V_137 += V_86 - V_137 % V_86 ;
V_6 -> V_129 = V_137 ;
V_6 -> V_128 = V_138 ;
V_6 -> V_86 = V_86 ;
F_74 ( & V_6 -> V_134 , & V_14 -> V_24 ) ;
V_138 += V_86 ;
V_137 += V_86 ;
}
if ( V_14 -> V_52 ) {
V_6 = F_63 ( sizeof( * V_6 ) , V_73 ) ;
if ( V_6 == NULL ) {
V_43 = - V_74 ;
goto V_139;
}
V_84 = F_46 ( V_2 ,
V_2 -> V_72 ) ;
V_86 = V_84 -> V_33 . V_41 / 8 ;
if ( V_138 % V_86 )
V_138 += V_86 - V_138 % V_86 ;
if ( V_137 % V_86 )
V_137 += V_86 - V_137 % V_86 ;
V_6 -> V_129 = V_137 ;
V_6 -> V_128 = V_138 ;
V_6 -> V_86 = V_86 ;
F_74 ( & V_6 -> V_134 , & V_14 -> V_24 ) ;
V_138 += V_86 ;
V_137 += V_86 ;
}
V_14 -> V_127 = F_75 ( V_138 , V_73 ) ;
if ( V_14 -> V_127 == NULL ) {
V_43 = - V_74 ;
goto V_139;
}
return 0 ;
V_139:
F_69 ( V_14 ) ;
return V_43 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_14 ;
int V_43 ;
F_35 (buffer, &indio_dev->buffer_list, buffer_list) {
V_43 = F_71 ( V_2 , V_14 ) ;
if ( V_43 < 0 )
goto V_139;
}
return 0 ;
V_139:
F_35 (buffer, &indio_dev->buffer_list, buffer_list)
F_69 ( V_14 ) ;
return V_43 ;
}
