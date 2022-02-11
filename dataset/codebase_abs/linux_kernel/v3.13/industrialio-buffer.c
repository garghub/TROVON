static bool F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
T_1 F_3 ( struct V_4 * V_5 , char T_2 * V_2 ,
T_3 V_6 , T_4 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_1 * V_11 = V_9 -> V_12 ;
if ( ! V_9 -> V_13 )
return - V_14 ;
if ( ! V_11 || ! V_11 -> V_15 -> V_16 )
return - V_17 ;
return V_11 -> V_15 -> V_16 ( V_11 , V_6 , V_2 ) ;
}
unsigned int F_4 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
struct V_1 * V_11 = V_9 -> V_12 ;
if ( ! V_9 -> V_13 )
return - V_14 ;
F_5 ( V_5 , & V_11 -> V_20 , V_19 ) ;
if ( V_11 -> V_21 )
return V_22 | V_23 ;
return 0 ;
}
void F_6 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_12 )
return;
F_7 ( & V_9 -> V_12 -> V_20 ) ;
}
void F_8 ( struct V_1 * V_12 )
{
F_9 ( & V_12 -> V_24 ) ;
F_9 ( & V_12 -> V_3 ) ;
F_10 ( & V_12 -> V_20 ) ;
F_11 ( & V_12 -> V_25 ) ;
}
static T_1 F_12 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_13 ( V_29 ) -> V_30 -> V_31 ) ;
}
static T_1 F_14 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
struct V_32 * V_33 = F_13 ( V_29 ) ;
T_5 type = V_33 -> V_30 -> V_34 . V_35 ;
if ( type == V_36 ) {
#ifdef F_15
type = V_37 ;
#else
type = V_38 ;
#endif
}
return sprintf ( V_2 , L_2 ,
V_39 [ type ] ,
V_33 -> V_30 -> V_34 . V_40 ,
V_33 -> V_30 -> V_34 . V_41 ,
V_33 -> V_30 -> V_34 . V_42 ,
V_33 -> V_30 -> V_34 . V_43 ) ;
}
static T_1 F_16 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
int V_44 ;
struct V_8 * V_9 = F_17 ( V_27 ) ;
V_44 = F_18 ( F_13 ( V_29 ) -> V_45 ,
V_9 -> V_12 -> V_46 ) ;
return sprintf ( V_2 , L_3 , V_44 ) ;
}
static int F_19 ( struct V_1 * V_12 , int V_47 )
{
F_20 ( V_47 , V_12 -> V_46 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_2 ,
T_3 V_48 )
{
int V_44 ;
bool V_49 ;
struct V_8 * V_9 = F_17 ( V_27 ) ;
struct V_1 * V_12 = V_9 -> V_12 ;
struct V_32 * V_33 = F_13 ( V_29 ) ;
V_44 = F_22 ( V_2 , & V_49 ) ;
if ( V_44 < 0 )
return V_44 ;
F_23 ( & V_9 -> V_50 ) ;
if ( F_1 ( V_9 -> V_12 ) ) {
V_44 = - V_51 ;
goto V_52;
}
V_44 = F_24 ( V_9 , V_12 , V_33 -> V_45 ) ;
if ( V_44 < 0 )
goto V_52;
if ( ! V_49 && V_44 ) {
V_44 = F_19 ( V_12 , V_33 -> V_45 ) ;
if ( V_44 )
goto V_52;
} else if ( V_49 && ! V_44 ) {
V_44 = F_25 ( V_9 , V_12 , V_33 -> V_45 ) ;
if ( V_44 )
goto V_52;
}
V_52:
F_26 ( & V_9 -> V_50 ) ;
return V_44 < 0 ? V_44 : V_48 ;
}
static T_1 F_27 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
struct V_8 * V_9 = F_17 ( V_27 ) ;
return sprintf ( V_2 , L_3 , V_9 -> V_12 -> V_53 ) ;
}
static T_1 F_28 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_2 ,
T_3 V_48 )
{
int V_44 ;
struct V_8 * V_9 = F_17 ( V_27 ) ;
bool V_49 ;
V_44 = F_22 ( V_2 , & V_49 ) ;
if ( V_44 < 0 )
return V_44 ;
F_23 ( & V_9 -> V_50 ) ;
if ( F_1 ( V_9 -> V_12 ) ) {
V_44 = - V_51 ;
goto V_52;
}
V_9 -> V_12 -> V_53 = V_49 ;
V_52:
F_26 ( & V_9 -> V_50 ) ;
return V_44 ? V_44 : V_48 ;
}
static int F_29 ( struct V_8 * V_9 ,
const struct V_54 * V_55 )
{
int V_44 , V_56 = 0 ;
struct V_1 * V_12 = V_9 -> V_12 ;
V_44 = F_30 ( L_4 ,
V_55 ,
& F_12 ,
NULL ,
0 ,
V_57 ,
& V_9 -> V_27 ,
& V_12 -> V_58 ) ;
if ( V_44 )
goto V_52;
V_56 ++ ;
V_44 = F_30 ( L_5 ,
V_55 ,
& F_14 ,
NULL ,
0 ,
0 ,
& V_9 -> V_27 ,
& V_12 -> V_58 ) ;
if ( V_44 )
goto V_52;
V_56 ++ ;
if ( V_55 -> type != V_59 )
V_44 = F_30 ( L_6 ,
V_55 ,
& F_16 ,
& F_21 ,
V_55 -> V_31 ,
0 ,
& V_9 -> V_27 ,
& V_12 -> V_58 ) ;
else
V_44 = F_30 ( L_6 ,
V_55 ,
& F_27 ,
& F_28 ,
V_55 -> V_31 ,
0 ,
& V_9 -> V_27 ,
& V_12 -> V_58 ) ;
if ( V_44 )
goto V_52;
V_56 ++ ;
V_44 = V_56 ;
V_52:
return V_44 ;
}
int F_31 ( struct V_8 * V_9 ,
const struct V_54 * V_60 ,
int V_61 )
{
struct V_32 * V_62 ;
struct V_63 * * V_29 ;
struct V_1 * V_12 = V_9 -> V_12 ;
int V_44 , V_64 , V_65 , V_56 , V_66 = 0 ;
if ( V_12 -> V_67 )
V_9 -> V_68 [ V_9 -> V_69 ++ ] = V_12 -> V_67 ;
if ( V_12 -> V_70 != NULL ) {
V_29 = V_12 -> V_70 -> V_67 ;
while ( * V_29 ++ != NULL )
V_66 ++ ;
}
V_56 = V_66 ;
F_9 ( & V_12 -> V_58 ) ;
if ( V_60 ) {
for ( V_64 = 0 ; V_64 < V_61 ; V_64 ++ ) {
if ( V_60 [ V_64 ] . V_31 < 0 )
continue;
if ( V_60 [ V_64 ] . V_31 >
( int ) V_9 -> V_71 - 1 )
V_9 -> V_71
= V_60 [ V_64 ] . V_31 + 1 ;
V_44 = F_29 ( V_9 ,
& V_60 [ V_64 ] ) ;
if ( V_44 < 0 )
goto V_72;
V_56 += V_44 ;
if ( V_60 [ V_64 ] . type == V_59 )
V_9 -> V_73 =
V_60 [ V_64 ] . V_31 ;
}
if ( V_9 -> V_71 && V_12 -> V_46 == NULL ) {
V_12 -> V_46 = F_32 ( F_33 ( V_9 -> V_71 ) ,
sizeof( * V_12 -> V_46 ) ,
V_74 ) ;
if ( V_12 -> V_46 == NULL ) {
V_44 = - V_75 ;
goto V_72;
}
}
}
V_12 -> V_76 . V_77 = V_78 ;
V_12 -> V_76 . V_67 = F_32 ( V_56 + 1 ,
sizeof( V_12 -> V_76 . V_67 [ 0 ] ) ,
V_74 ) ;
if ( V_12 -> V_76 . V_67 == NULL ) {
V_44 = - V_75 ;
goto V_79;
}
if ( V_12 -> V_70 )
memcpy ( V_12 -> V_76 . V_67 , V_12 -> V_70 ,
sizeof( V_12 -> V_76 . V_67 [ 0 ] ) * V_66 ) ;
V_65 = V_66 ;
F_34 (p, &buffer->scan_el_dev_attr_list, l)
V_12 -> V_76 . V_67 [ V_65 ++ ] = & V_62 -> V_80 . V_29 ;
V_9 -> V_68 [ V_9 -> V_69 ++ ] = & V_12 -> V_76 ;
return 0 ;
V_79:
F_35 ( V_12 -> V_46 ) ;
V_72:
F_36 ( & V_12 -> V_58 ) ;
return V_44 ;
}
void F_37 ( struct V_8 * V_9 )
{
F_35 ( V_9 -> V_12 -> V_46 ) ;
F_35 ( V_9 -> V_12 -> V_76 . V_67 ) ;
F_36 ( & V_9 -> V_12 -> V_58 ) ;
}
T_1 F_38 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
struct V_8 * V_9 = F_17 ( V_27 ) ;
struct V_1 * V_12 = V_9 -> V_12 ;
if ( V_12 -> V_15 -> V_81 )
return sprintf ( V_2 , L_3 ,
V_12 -> V_15 -> V_81 ( V_12 ) ) ;
return 0 ;
}
T_1 F_39 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_2 ,
T_3 V_48 )
{
struct V_8 * V_9 = F_17 ( V_27 ) ;
struct V_1 * V_12 = V_9 -> V_12 ;
unsigned int V_82 ;
int V_44 ;
V_44 = F_40 ( V_2 , 10 , & V_82 ) ;
if ( V_44 )
return V_44 ;
if ( V_12 -> V_15 -> V_81 )
if ( V_82 == V_12 -> V_15 -> V_81 ( V_12 ) )
return V_48 ;
F_23 ( & V_9 -> V_50 ) ;
if ( F_1 ( V_9 -> V_12 ) ) {
V_44 = - V_51 ;
} else {
if ( V_12 -> V_15 -> V_83 )
V_12 -> V_15 -> V_83 ( V_12 , V_82 ) ;
V_44 = 0 ;
}
F_26 ( & V_9 -> V_50 ) ;
return V_44 ? V_44 : V_48 ;
}
T_1 F_41 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_2 )
{
struct V_8 * V_9 = F_17 ( V_27 ) ;
return sprintf ( V_2 , L_3 , F_1 ( V_9 -> V_12 ) ) ;
}
static const unsigned long * F_42 ( const unsigned long * V_84 ,
unsigned int V_71 ,
const unsigned long * V_85 )
{
if ( F_43 ( V_85 , V_71 ) )
return NULL ;
while ( * V_84 ) {
if ( F_44 ( V_85 , V_84 , V_71 ) )
return V_84 ;
V_84 += F_33 ( V_71 ) ;
}
return NULL ;
}
static int F_45 ( struct V_8 * V_9 ,
const unsigned long * V_85 , bool V_86 )
{
const struct V_54 * V_87 ;
unsigned V_88 = 0 ;
int V_89 , V_64 ;
F_46 (i, mask,
indio_dev->masklength) {
V_87 = F_47 ( V_9 , V_64 ) ;
V_89 = V_87 -> V_34 . V_42 / 8 ;
V_88 = F_48 ( V_88 , V_89 ) ;
V_88 += V_89 ;
}
if ( V_86 ) {
V_87 = F_47 ( V_9 ,
V_9 -> V_73 ) ;
V_89 = V_87 -> V_34 . V_42 / 8 ;
V_88 = F_48 ( V_88 , V_89 ) ;
V_88 += V_89 ;
}
return V_88 ;
}
static void F_49 ( struct V_8 * V_9 ,
struct V_1 * V_12 )
{
F_50 ( V_12 ) ;
F_51 ( & V_12 -> V_3 , & V_9 -> V_3 ) ;
}
static void F_52 ( struct V_1 * V_12 )
{
F_53 ( & V_12 -> V_3 ) ;
F_54 ( V_12 ) ;
}
void F_55 ( struct V_8 * V_9 )
{
struct V_1 * V_12 , * V_90 ;
if ( F_2 ( & V_9 -> V_3 ) )
return;
if ( V_9 -> V_91 -> V_92 )
V_9 -> V_91 -> V_92 ( V_9 ) ;
F_56 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_52 ( V_12 ) ;
V_9 -> V_93 = V_94 ;
if ( V_9 -> V_91 -> V_95 )
V_9 -> V_91 -> V_95 ( V_9 ) ;
if ( V_9 -> V_96 == NULL )
F_35 ( V_9 -> V_97 ) ;
}
static void F_57 ( struct V_8 * V_9 ,
struct V_1 * V_12 )
{
unsigned int V_88 ;
if ( ! V_12 -> V_15 -> V_98 )
return;
V_88 = F_45 ( V_9 , V_12 -> V_46 ,
V_12 -> V_53 ) ;
V_12 -> V_15 -> V_98 ( V_12 , V_88 ) ;
}
static int F_58 ( struct V_8 * V_9 ,
struct V_1 * V_99 ,
struct V_1 * V_100 )
{
int V_44 ;
int V_101 = 0 ;
struct V_1 * V_12 ;
unsigned long * V_102 ;
const unsigned long * V_103 ;
if ( ! F_2 ( & V_9 -> V_3 ) ) {
if ( V_9 -> V_91 -> V_92 ) {
V_44 = V_9 -> V_91 -> V_92 ( V_9 ) ;
if ( V_44 )
goto V_52;
}
V_9 -> V_93 = V_94 ;
if ( V_9 -> V_91 -> V_95 ) {
V_44 = V_9 -> V_91 -> V_95 ( V_9 ) ;
if ( V_44 )
goto V_52;
}
}
V_103 = V_9 -> V_97 ;
if ( ! V_9 -> V_96 )
V_9 -> V_97 = NULL ;
if ( V_100 )
F_52 ( V_100 ) ;
if ( V_99 )
F_49 ( V_9 , V_99 ) ;
if ( F_2 ( & V_9 -> V_3 ) ) {
V_9 -> V_93 = V_94 ;
if ( V_9 -> V_96 == NULL )
F_35 ( V_103 ) ;
return 0 ;
}
V_102 = F_32 ( F_33 ( V_9 -> V_71 ) ,
sizeof( long ) , V_74 ) ;
if ( V_102 == NULL ) {
if ( V_9 -> V_96 == NULL )
F_35 ( V_103 ) ;
return - V_75 ;
}
V_9 -> V_53 = 0 ;
F_34 (buffer, &indio_dev->buffer_list, buffer_list) {
F_59 ( V_102 , V_102 , V_12 -> V_46 ,
V_9 -> V_71 ) ;
V_9 -> V_53 |= V_12 -> V_53 ;
}
if ( V_9 -> V_96 ) {
V_9 -> V_97 =
F_42 ( V_9 -> V_96 ,
V_9 -> V_71 ,
V_102 ) ;
if ( V_9 -> V_97 == NULL ) {
F_52 ( V_99 ) ;
if ( V_103 ) {
V_9 -> V_97 = V_103 ;
V_101 = - V_17 ;
}
else {
F_35 ( V_102 ) ;
V_44 = - V_17 ;
goto V_52;
}
}
} else {
V_9 -> V_97 = V_102 ;
}
F_60 ( V_9 ) ;
if ( V_9 -> V_91 -> V_104 ) {
V_44 = V_9 -> V_91 -> V_104 ( V_9 ) ;
if ( V_44 ) {
F_61 ( V_105
L_7 , V_44 ) ;
goto V_106;
}
}
V_9 -> V_107 =
F_45 ( V_9 ,
V_9 -> V_97 ,
V_9 -> V_53 ) ;
F_34 (buffer, &indio_dev->buffer_list, buffer_list) {
F_57 ( V_9 , V_12 ) ;
if ( V_12 -> V_15 -> V_108 ) {
V_44 = V_12 -> V_15 -> V_108 ( V_12 ) ;
if ( V_44 ) {
F_61 ( V_109
L_8 , V_44 ) ;
goto V_110;
}
}
}
if ( V_9 -> V_13 -> V_111 ) {
V_44 = V_9 -> V_13
-> V_111 ( V_9 ,
V_9 -> V_97 ) ;
if ( V_44 < 0 ) {
F_61 ( V_109 L_9 , V_44 ) ;
goto V_110;
}
}
if ( V_9 -> V_112 & V_113 ) {
if ( ! V_9 -> V_114 ) {
F_61 ( V_109 L_10 ) ;
V_44 = - V_17 ;
goto V_110;
}
V_9 -> V_93 = V_113 ;
} else if ( V_9 -> V_112 & V_115 ) {
V_9 -> V_93 = V_115 ;
} else {
V_44 = - V_17 ;
goto V_110;
}
if ( V_9 -> V_91 -> V_116 ) {
V_44 = V_9 -> V_91 -> V_116 ( V_9 ) ;
if ( V_44 ) {
F_61 ( V_109
L_11 , V_44 ) ;
V_9 -> V_93 = V_94 ;
if ( V_9 -> V_91 -> V_95 )
V_9 -> V_91 -> V_95 ( V_9 ) ;
goto V_117;
}
}
if ( V_9 -> V_96 )
F_35 ( V_102 ) ;
else
F_35 ( V_103 ) ;
return V_101 ;
V_117:
V_9 -> V_93 = V_94 ;
V_110:
if ( V_9 -> V_91 -> V_95 )
V_9 -> V_91 -> V_95 ( V_9 ) ;
V_106:
if ( V_99 )
F_52 ( V_99 ) ;
V_9 -> V_97 = V_103 ;
F_35 ( V_102 ) ;
V_52:
return V_44 ;
}
int F_62 ( struct V_8 * V_9 ,
struct V_1 * V_99 ,
struct V_1 * V_100 )
{
int V_44 ;
if ( V_99 == V_100 )
return 0 ;
F_23 ( & V_9 -> V_118 ) ;
F_23 ( & V_9 -> V_50 ) ;
if ( V_99 && F_1 ( V_99 ) )
V_99 = NULL ;
if ( V_100 && ! F_1 ( V_100 ) )
V_100 = NULL ;
if ( ! V_99 && ! V_100 ) {
V_44 = 0 ;
goto V_119;
}
if ( V_9 -> V_13 == NULL ) {
V_44 = - V_14 ;
goto V_119;
}
V_44 = F_58 ( V_9 , V_99 , V_100 ) ;
V_119:
F_26 ( & V_9 -> V_50 ) ;
F_26 ( & V_9 -> V_118 ) ;
return V_44 ;
}
T_1 F_63 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
const char * V_2 ,
T_3 V_48 )
{
int V_44 ;
bool V_120 ;
struct V_8 * V_9 = F_17 ( V_27 ) ;
bool V_121 ;
V_44 = F_22 ( V_2 , & V_120 ) ;
if ( V_44 < 0 )
return V_44 ;
F_23 ( & V_9 -> V_50 ) ;
V_121 = F_1 ( V_9 -> V_12 ) ;
if ( V_121 == V_120 )
goto V_122;
if ( V_120 )
V_44 = F_58 ( V_9 ,
V_9 -> V_12 , NULL ) ;
else
V_44 = F_58 ( V_9 ,
NULL , V_9 -> V_12 ) ;
if ( V_44 < 0 )
goto V_122;
V_122:
F_26 ( & V_9 -> V_50 ) ;
return ( V_44 < 0 ) ? V_44 : V_48 ;
}
bool F_64 ( struct V_8 * V_9 ,
const unsigned long * V_85 )
{
return F_65 ( V_85 , V_9 -> V_71 ) == 1 ;
}
static bool F_66 ( struct V_8 * V_9 ,
const unsigned long * V_85 )
{
if ( ! V_9 -> V_91 -> V_123 )
return true ;
return V_9 -> V_91 -> V_123 ( V_9 , V_85 ) ;
}
int F_25 ( struct V_8 * V_9 ,
struct V_1 * V_12 , int V_47 )
{
const unsigned long * V_85 ;
unsigned long * V_124 ;
V_124 = F_67 ( sizeof( * V_124 ) *
F_33 ( V_9 -> V_71 ) ,
V_74 ) ;
if ( V_124 == NULL )
return - V_75 ;
if ( ! V_9 -> V_71 ) {
F_68 ( L_12 ) ;
goto V_125;
}
F_69 ( V_124 , V_12 -> V_46 , V_9 -> V_71 ) ;
F_70 ( V_47 , V_124 ) ;
if ( ! F_66 ( V_9 , V_124 ) )
goto V_125;
if ( V_9 -> V_96 ) {
V_85 = F_42 ( V_9 -> V_96 ,
V_9 -> V_71 ,
V_124 ) ;
if ( ! V_85 )
goto V_125;
}
F_69 ( V_12 -> V_46 , V_124 , V_9 -> V_71 ) ;
F_35 ( V_124 ) ;
return 0 ;
V_125:
F_35 ( V_124 ) ;
return - V_17 ;
}
int F_24 ( struct V_8 * V_9 ,
struct V_1 * V_12 , int V_47 )
{
if ( V_47 > V_9 -> V_71 )
return - V_17 ;
if ( ! V_12 -> V_46 )
return 0 ;
return F_18 ( V_47 , V_12 -> V_46 ) ;
}
static const void * F_71 ( struct V_1 * V_12 ,
const void * V_126 )
{
struct V_127 * V_128 ;
if ( F_2 ( & V_12 -> V_24 ) )
return V_126 ;
F_34 (t, &buffer->demux_list, l)
memcpy ( V_12 -> V_129 + V_128 -> V_130 ,
V_126 + V_128 -> V_131 , V_128 -> V_89 ) ;
return V_12 -> V_129 ;
}
static int F_72 ( struct V_1 * V_12 , const void * V_132 )
{
const void * V_133 = F_71 ( V_12 , V_132 ) ;
return V_12 -> V_15 -> V_134 ( V_12 , V_133 ) ;
}
static void F_73 ( struct V_1 * V_12 )
{
struct V_127 * V_62 , * V_135 ;
F_56 (p, q, &buffer->demux_list, l) {
F_74 ( & V_62 -> V_136 ) ;
F_35 ( V_62 ) ;
}
}
int F_75 ( struct V_8 * V_9 , const void * V_132 )
{
int V_44 ;
struct V_1 * V_2 ;
F_34 (buf, &indio_dev->buffer_list, buffer_list) {
V_44 = F_72 ( V_2 , V_132 ) ;
if ( V_44 < 0 )
return V_44 ;
}
return 0 ;
}
static int F_76 ( struct V_8 * V_9 ,
struct V_1 * V_12 )
{
const struct V_54 * V_87 ;
int V_44 , V_137 = - 1 , V_138 , V_89 ;
unsigned V_139 = 0 , V_140 = 0 ;
struct V_127 * V_62 ;
F_73 ( V_12 ) ;
F_35 ( V_12 -> V_129 ) ;
V_12 -> V_129 = NULL ;
if ( F_77 ( V_9 -> V_97 ,
V_12 -> V_46 ,
V_9 -> V_71 ) )
return 0 ;
F_46 (out_ind,
indio_dev->active_scan_mask,
indio_dev->masklength) {
V_137 = F_78 ( V_9 -> V_97 ,
V_9 -> V_71 ,
V_137 + 1 ) ;
while ( V_137 != V_138 ) {
V_137 = F_78 ( V_9 -> V_97 ,
V_9 -> V_71 ,
V_137 + 1 ) ;
V_87 = F_47 ( V_9 , V_137 ) ;
V_89 = V_87 -> V_34 . V_42 / 8 ;
V_139 += V_89 ;
if ( V_139 % V_89 )
V_139 += V_89 - V_139 % V_89 ;
}
V_62 = F_67 ( sizeof( * V_62 ) , V_74 ) ;
if ( V_62 == NULL ) {
V_44 = - V_75 ;
goto V_141;
}
V_87 = F_47 ( V_9 , V_137 ) ;
V_89 = V_87 -> V_34 . V_42 / 8 ;
if ( V_140 % V_89 )
V_140 += V_89 - V_140 % V_89 ;
if ( V_139 % V_89 )
V_139 += V_89 - V_139 % V_89 ;
V_62 -> V_131 = V_139 ;
V_62 -> V_130 = V_140 ;
V_62 -> V_89 = V_89 ;
F_79 ( & V_62 -> V_136 , & V_12 -> V_24 ) ;
V_140 += V_89 ;
V_139 += V_89 ;
}
if ( V_12 -> V_53 ) {
V_62 = F_67 ( sizeof( * V_62 ) , V_74 ) ;
if ( V_62 == NULL ) {
V_44 = - V_75 ;
goto V_141;
}
V_87 = F_47 ( V_9 ,
V_9 -> V_73 ) ;
V_89 = V_87 -> V_34 . V_42 / 8 ;
if ( V_140 % V_89 )
V_140 += V_89 - V_140 % V_89 ;
if ( V_139 % V_89 )
V_139 += V_89 - V_139 % V_89 ;
V_62 -> V_131 = V_139 ;
V_62 -> V_130 = V_140 ;
V_62 -> V_89 = V_89 ;
F_79 ( & V_62 -> V_136 , & V_12 -> V_24 ) ;
V_140 += V_89 ;
V_139 += V_89 ;
}
V_12 -> V_129 = F_80 ( V_140 , V_74 ) ;
if ( V_12 -> V_129 == NULL ) {
V_44 = - V_75 ;
goto V_141;
}
return 0 ;
V_141:
F_73 ( V_12 ) ;
return V_44 ;
}
int F_60 ( struct V_8 * V_9 )
{
struct V_1 * V_12 ;
int V_44 ;
F_34 (buffer, &indio_dev->buffer_list, buffer_list) {
V_44 = F_76 ( V_9 , V_12 ) ;
if ( V_44 < 0 )
goto V_141;
}
return 0 ;
V_141:
F_34 (buffer, &indio_dev->buffer_list, buffer_list)
F_73 ( V_12 ) ;
return V_44 ;
}
static void F_81 ( struct V_142 * V_25 )
{
struct V_1 * V_12 = F_82 ( V_25 , struct V_1 , V_25 ) ;
V_12 -> V_15 -> V_143 ( V_12 ) ;
}
struct V_1 * F_50 ( struct V_1 * V_12 )
{
if ( V_12 )
F_83 ( & V_12 -> V_25 ) ;
return V_12 ;
}
void F_54 ( struct V_1 * V_12 )
{
if ( V_12 )
F_84 ( & V_12 -> V_25 , F_81 ) ;
}
