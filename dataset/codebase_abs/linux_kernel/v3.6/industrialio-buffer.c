T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 || ! V_10 -> V_12 -> V_13 )
return - V_14 ;
return V_10 -> V_12 -> V_13 ( V_10 , V_4 , V_3 ) ;
}
unsigned int F_2 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
F_3 ( V_2 , & V_10 -> V_17 , V_16 ) ;
if ( V_10 -> V_18 )
return V_19 | V_20 ;
return 0 ;
}
void F_4 ( struct V_9 * V_11 )
{
F_5 ( & V_11 -> V_21 ) ;
F_6 ( & V_11 -> V_17 ) ;
}
static T_1 F_7 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
return sprintf ( V_3 , L_1 , F_8 ( V_25 ) -> V_26 -> V_27 ) ;
}
static T_1 F_9 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
struct V_28 * V_29 = F_8 ( V_25 ) ;
T_5 type = V_29 -> V_26 -> V_30 . V_31 ;
if ( type == V_32 ) {
#ifdef F_10
type = V_33 ;
#else
type = V_34 ;
#endif
}
return sprintf ( V_3 , L_2 ,
V_35 [ type ] ,
V_29 -> V_26 -> V_30 . V_36 ,
V_29 -> V_26 -> V_30 . V_37 ,
V_29 -> V_26 -> V_30 . V_38 ,
V_29 -> V_26 -> V_30 . V_39 ) ;
}
static T_1 F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
int V_40 ;
struct V_6 * V_7 = F_12 ( V_23 ) ;
V_40 = F_13 ( F_8 ( V_25 ) -> V_41 ,
V_7 -> V_11 -> V_42 ) ;
return sprintf ( V_3 , L_3 , V_40 ) ;
}
static int F_14 ( struct V_9 * V_11 , int V_43 )
{
F_15 ( V_43 , V_11 -> V_42 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 ,
T_3 V_44 )
{
int V_40 ;
bool V_45 ;
struct V_6 * V_7 = F_12 ( V_23 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
struct V_28 * V_29 = F_8 ( V_25 ) ;
V_40 = F_17 ( V_3 , & V_45 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( & V_7 -> V_46 ) ;
if ( F_19 ( V_7 ) ) {
V_40 = - V_47 ;
goto V_48;
}
V_40 = F_20 ( V_7 , V_11 , V_29 -> V_41 ) ;
if ( V_40 < 0 )
goto V_48;
if ( ! V_45 && V_40 ) {
V_40 = F_14 ( V_11 , V_29 -> V_41 ) ;
if ( V_40 )
goto V_48;
} else if ( V_45 && ! V_40 ) {
V_40 = F_21 ( V_7 , V_11 , V_29 -> V_41 ) ;
if ( V_40 )
goto V_48;
}
V_48:
F_22 ( & V_7 -> V_46 ) ;
return V_40 < 0 ? V_40 : V_44 ;
}
static T_1 F_23 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
struct V_6 * V_7 = F_12 ( V_23 ) ;
return sprintf ( V_3 , L_3 , V_7 -> V_11 -> V_49 ) ;
}
static T_1 F_24 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 ,
T_3 V_44 )
{
int V_40 ;
struct V_6 * V_7 = F_12 ( V_23 ) ;
bool V_45 ;
V_40 = F_17 ( V_3 , & V_45 ) ;
if ( V_40 < 0 )
return V_40 ;
F_18 ( & V_7 -> V_46 ) ;
if ( F_19 ( V_7 ) ) {
V_40 = - V_47 ;
goto V_48;
}
V_7 -> V_11 -> V_49 = V_45 ;
V_7 -> V_49 = V_45 ;
V_48:
F_22 ( & V_7 -> V_46 ) ;
return V_40 ? V_40 : V_44 ;
}
static int F_25 ( struct V_6 * V_7 ,
const struct V_50 * V_51 )
{
int V_40 , V_52 = 0 ;
struct V_9 * V_11 = V_7 -> V_11 ;
V_40 = F_26 ( L_4 ,
V_51 ,
& F_7 ,
NULL ,
0 ,
0 ,
& V_7 -> V_23 ,
& V_11 -> V_53 ) ;
if ( V_40 )
goto V_48;
V_52 ++ ;
V_40 = F_26 ( L_5 ,
V_51 ,
& F_9 ,
NULL ,
0 ,
0 ,
& V_7 -> V_23 ,
& V_11 -> V_53 ) ;
if ( V_40 )
goto V_48;
V_52 ++ ;
if ( V_51 -> type != V_54 )
V_40 = F_26 ( L_6 ,
V_51 ,
& F_11 ,
& F_16 ,
V_51 -> V_27 ,
0 ,
& V_7 -> V_23 ,
& V_11 -> V_53 ) ;
else
V_40 = F_26 ( L_6 ,
V_51 ,
& F_23 ,
& F_24 ,
V_51 -> V_27 ,
0 ,
& V_7 -> V_23 ,
& V_11 -> V_53 ) ;
V_52 ++ ;
V_40 = V_52 ;
V_48:
return V_40 ;
}
static void F_27 ( struct V_6 * V_7 ,
struct V_28 * V_55 )
{
F_28 ( V_55 -> V_56 . V_25 . V_57 ) ;
F_28 ( V_55 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
struct V_28 * V_55 , * V_4 ;
struct V_9 * V_11 = V_7 -> V_11 ;
F_30 (p, n,
&buffer->scan_el_dev_attr_list, l)
F_27 ( V_7 , V_55 ) ;
}
int F_31 ( struct V_6 * V_7 ,
const struct V_50 * V_58 ,
int V_59 )
{
struct V_28 * V_55 ;
struct V_60 * * V_25 ;
struct V_9 * V_11 = V_7 -> V_11 ;
int V_40 , V_61 , V_62 , V_52 , V_63 = 0 ;
if ( V_11 -> V_64 )
V_7 -> V_65 [ V_7 -> V_66 ++ ] = V_11 -> V_64 ;
if ( V_11 -> V_67 != NULL ) {
V_25 = V_11 -> V_67 -> V_64 ;
while ( * V_25 ++ != NULL )
V_63 ++ ;
}
V_52 = V_63 ;
F_5 ( & V_11 -> V_53 ) ;
if ( V_58 ) {
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
if ( V_58 [ V_61 ] . V_27 < 0 )
continue;
if ( V_58 [ V_61 ] . V_27 >
( int ) V_7 -> V_68 - 1 )
V_7 -> V_68
= V_58 [ V_61 ] . V_27 + 1 ;
V_40 = F_25 ( V_7 ,
& V_58 [ V_61 ] ) ;
if ( V_40 < 0 )
goto V_69;
V_52 += V_40 ;
if ( V_58 [ V_61 ] . type == V_54 )
V_7 -> V_70 =
V_58 [ V_61 ] . V_27 ;
}
if ( V_7 -> V_68 && V_11 -> V_42 == NULL ) {
V_11 -> V_42 = F_32 ( F_33 ( V_7 -> V_68 ) ,
sizeof( * V_11 -> V_42 ) ,
V_71 ) ;
if ( V_11 -> V_42 == NULL ) {
V_40 = - V_72 ;
goto V_69;
}
}
}
V_11 -> V_73 . V_57 = V_74 ;
V_11 -> V_73 . V_64 = F_32 ( V_52 + 1 ,
sizeof( V_11 -> V_73 . V_64 [ 0 ] ) ,
V_71 ) ;
if ( V_11 -> V_73 . V_64 == NULL ) {
V_40 = - V_72 ;
goto V_75;
}
if ( V_11 -> V_67 )
memcpy ( V_11 -> V_73 . V_64 , V_11 -> V_67 ,
sizeof( V_11 -> V_73 . V_64 [ 0 ] ) * V_63 ) ;
V_62 = V_63 ;
F_34 (p, &buffer->scan_el_dev_attr_list, l)
V_11 -> V_73 . V_64 [ V_62 ++ ] = & V_55 -> V_56 . V_25 ;
V_7 -> V_65 [ V_7 -> V_66 ++ ] = & V_11 -> V_73 ;
return 0 ;
V_75:
F_28 ( V_11 -> V_42 ) ;
V_69:
F_29 ( V_7 ) ;
return V_40 ;
}
void F_35 ( struct V_6 * V_7 )
{
F_28 ( V_7 -> V_11 -> V_42 ) ;
F_28 ( V_7 -> V_11 -> V_73 . V_64 ) ;
F_29 ( V_7 ) ;
}
T_1 F_36 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
struct V_6 * V_7 = F_12 ( V_23 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
if ( V_11 -> V_12 -> V_76 )
return sprintf ( V_3 , L_3 ,
V_11 -> V_12 -> V_76 ( V_11 ) ) ;
return 0 ;
}
T_1 F_37 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 ,
T_3 V_44 )
{
int V_40 ;
T_6 V_77 ;
struct V_6 * V_7 = F_12 ( V_23 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
V_40 = F_38 ( V_3 , 10 , & V_77 ) ;
if ( V_40 )
return V_40 ;
if ( V_11 -> V_12 -> V_76 )
if ( V_77 == V_11 -> V_12 -> V_76 ( V_11 ) )
return V_44 ;
F_18 ( & V_7 -> V_46 ) ;
if ( F_19 ( V_7 ) ) {
V_40 = - V_47 ;
} else {
if ( V_11 -> V_12 -> V_78 )
V_11 -> V_12 -> V_78 ( V_11 , V_77 ) ;
V_40 = 0 ;
}
F_22 ( & V_7 -> V_46 ) ;
return V_40 ? V_40 : V_44 ;
}
T_1 F_39 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_3 ,
T_3 V_44 )
{
int V_40 ;
bool V_79 , V_80 ;
int V_81 ;
struct V_6 * V_7 = F_12 ( V_23 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
F_18 ( & V_7 -> V_46 ) ;
V_81 = V_7 -> V_82 ;
V_79 = ! ( V_3 [ 0 ] == '0' ) ;
V_80 = F_19 ( V_7 ) ;
if ( V_80 == V_79 ) {
F_40 ( V_83 L_7 ) ;
goto V_84;
}
if ( V_79 ) {
if ( V_7 -> V_85 -> V_86 ) {
V_40 = V_7 -> V_85 -> V_86 ( V_7 ) ;
if ( V_40 ) {
F_40 ( V_87
L_8
L_9 ) ;
goto V_48;
}
}
if ( V_11 -> V_12 -> V_88 ) {
V_40 = V_11 -> V_12 -> V_88 ( V_11 ) ;
if ( V_40 ) {
F_40 ( V_83
L_8
L_10 ) ;
goto V_48;
}
}
if ( V_7 -> V_89 & V_90 ) {
if ( ! V_7 -> V_91 ) {
F_40 ( V_83
L_11 ) ;
V_40 = - V_14 ;
goto V_48;
}
V_7 -> V_82 = V_90 ;
} else if ( V_7 -> V_89 & V_92 )
V_7 -> V_82 = V_92 ;
else {
V_40 = - V_14 ;
goto V_48;
}
if ( V_7 -> V_85 -> V_93 ) {
V_40 = V_7 -> V_85 -> V_93 ( V_7 ) ;
if ( V_40 ) {
F_40 ( V_83
L_8
L_12 ) ;
V_7 -> V_82 = V_81 ;
if ( V_7 -> V_85 -> V_94 )
V_7 -> V_85 ->
V_94 ( V_7 ) ;
goto V_48;
}
}
} else {
if ( V_7 -> V_85 -> V_95 ) {
V_40 = V_7 -> V_85 -> V_95 ( V_7 ) ;
if ( V_40 )
goto V_48;
}
V_7 -> V_82 = V_96 ;
if ( V_7 -> V_85 -> V_94 ) {
V_40 = V_7 -> V_85 -> V_94 ( V_7 ) ;
if ( V_40 )
goto V_48;
}
}
V_84:
F_22 ( & V_7 -> V_46 ) ;
return V_44 ;
V_48:
F_22 ( & V_7 -> V_46 ) ;
return V_40 ;
}
T_1 F_41 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_3 )
{
struct V_6 * V_7 = F_12 ( V_23 ) ;
return sprintf ( V_3 , L_3 , F_19 ( V_7 ) ) ;
}
static const unsigned long * F_42 ( const unsigned long * V_97 ,
unsigned int V_68 ,
const unsigned long * V_98 )
{
if ( F_43 ( V_98 , V_68 ) )
return NULL ;
while ( * V_97 ) {
if ( F_44 ( V_98 , V_97 , V_68 ) )
return V_97 ;
V_97 += F_33 ( V_68 ) ;
}
return NULL ;
}
static int F_45 ( struct V_6 * V_7 , const long * V_98 ,
bool V_99 )
{
const struct V_50 * V_100 ;
unsigned V_101 = 0 ;
int V_102 , V_61 ;
F_46 (i, mask,
indio_dev->masklength) {
V_100 = F_47 ( V_7 , V_61 ) ;
V_102 = V_100 -> V_30 . V_38 / 8 ;
V_101 = F_48 ( V_101 , V_102 ) ;
V_101 += V_102 ;
}
if ( V_99 ) {
V_100 = F_47 ( V_7 ,
V_7 -> V_70 ) ;
V_102 = V_100 -> V_30 . V_38 / 8 ;
V_101 = F_48 ( V_101 , V_102 ) ;
V_101 += V_102 ;
}
return V_101 ;
}
int F_49 ( struct V_6 * V_7 )
{
struct V_9 * V_11 = V_7 -> V_11 ;
F_50 ( & V_7 -> V_23 , L_13 , V_103 ) ;
V_7 -> V_104 =
F_45 ( V_7 , V_11 -> V_42 ,
V_11 -> V_49 ) ;
V_11 -> V_12 -> V_105 ( V_11 , V_7 -> V_104 ) ;
if ( V_7 -> V_106 )
V_7 -> V_107 =
F_42 ( V_7 -> V_106 ,
V_7 -> V_68 ,
V_11 -> V_42 ) ;
else
V_7 -> V_107 = V_11 -> V_42 ;
if ( V_7 -> V_107 == NULL )
return - V_14 ;
F_51 ( V_7 ) ;
if ( V_7 -> V_108 -> V_109 )
return V_7 -> V_108
-> V_109 ( V_7 ,
V_7 -> V_107 ) ;
return 0 ;
}
bool F_52 ( struct V_6 * V_7 ,
const unsigned long * V_98 )
{
return F_53 ( V_98 , V_7 -> V_68 ) == 1 ;
}
static bool F_54 ( struct V_6 * V_7 ,
const unsigned long * V_98 )
{
if ( ! V_7 -> V_85 -> V_110 )
return true ;
return V_7 -> V_85 -> V_110 ( V_7 , V_98 ) ;
}
int F_21 ( struct V_6 * V_7 ,
struct V_9 * V_11 , int V_43 )
{
const unsigned long * V_98 ;
unsigned long * V_111 ;
V_111 = F_55 ( sizeof( * V_111 ) *
F_33 ( V_7 -> V_68 ) ,
V_71 ) ;
if ( V_111 == NULL )
return - V_72 ;
if ( ! V_7 -> V_68 ) {
F_56 ( L_14 ) ;
goto V_112;
}
F_57 ( V_111 , V_11 -> V_42 , V_7 -> V_68 ) ;
F_58 ( V_43 , V_111 ) ;
if ( ! F_54 ( V_7 , V_111 ) )
goto V_112;
if ( V_7 -> V_106 ) {
V_98 = F_42 ( V_7 -> V_106 ,
V_7 -> V_68 ,
V_111 ) ;
if ( ! V_98 )
goto V_112;
}
F_57 ( V_11 -> V_42 , V_111 , V_7 -> V_68 ) ;
F_28 ( V_111 ) ;
return 0 ;
V_112:
F_28 ( V_111 ) ;
return - V_14 ;
}
int F_20 ( struct V_6 * V_7 ,
struct V_9 * V_11 , int V_43 )
{
if ( V_43 > V_7 -> V_68 )
return - V_14 ;
if ( ! V_11 -> V_42 )
return 0 ;
return F_13 ( V_43 , V_11 -> V_42 ) ;
}
static unsigned char * F_59 ( struct V_9 * V_11 ,
unsigned char * V_113 )
{
struct V_114 * V_115 ;
if ( F_60 ( & V_11 -> V_21 ) )
return V_113 ;
F_34 (t, &buffer->demux_list, l)
memcpy ( V_11 -> V_116 + V_115 -> V_117 ,
V_113 + V_115 -> V_118 , V_115 -> V_102 ) ;
return V_11 -> V_116 ;
}
int F_61 ( struct V_9 * V_11 , unsigned char * V_119 ,
T_7 V_99 )
{
unsigned char * V_120 = F_59 ( V_11 , V_119 ) ;
return V_11 -> V_12 -> V_121 ( V_11 , V_120 , V_99 ) ;
}
static void F_62 ( struct V_9 * V_11 )
{
struct V_114 * V_55 , * V_122 ;
F_30 (p, q, &buffer->demux_list, l) {
F_63 ( & V_55 -> V_123 ) ;
F_28 ( V_55 ) ;
}
}
int F_51 ( struct V_6 * V_7 )
{
const struct V_50 * V_100 ;
struct V_9 * V_11 = V_7 -> V_11 ;
int V_40 , V_124 = - 1 , V_125 , V_102 ;
unsigned V_126 = 0 , V_127 = 0 ;
struct V_114 * V_55 ;
F_62 ( V_11 ) ;
F_28 ( V_11 -> V_116 ) ;
V_11 -> V_116 = NULL ;
if ( F_64 ( V_7 -> V_107 ,
V_11 -> V_42 ,
V_7 -> V_68 ) )
return 0 ;
F_46 (out_ind,
indio_dev->active_scan_mask,
indio_dev->masklength) {
V_124 = F_65 ( V_7 -> V_107 ,
V_7 -> V_68 ,
V_124 + 1 ) ;
while ( V_124 != V_125 ) {
V_124 = F_65 ( V_7 -> V_107 ,
V_7 -> V_68 ,
V_124 + 1 ) ;
V_100 = F_47 ( V_7 , V_124 ) ;
V_102 = V_100 -> V_30 . V_38 / 8 ;
V_126 += V_102 ;
if ( V_126 % V_102 )
V_126 += V_102 - V_126 % V_102 ;
}
V_55 = F_55 ( sizeof( * V_55 ) , V_71 ) ;
if ( V_55 == NULL ) {
V_40 = - V_72 ;
goto V_128;
}
V_100 = F_47 ( V_7 , V_124 ) ;
V_102 = V_100 -> V_30 . V_38 / 8 ;
if ( V_127 % V_102 )
V_127 += V_102 - V_127 % V_102 ;
if ( V_126 % V_102 )
V_126 += V_102 - V_126 % V_102 ;
V_55 -> V_118 = V_126 ;
V_55 -> V_117 = V_127 ;
V_55 -> V_102 = V_102 ;
F_66 ( & V_55 -> V_123 , & V_11 -> V_21 ) ;
V_127 += V_102 ;
V_126 += V_102 ;
}
if ( V_11 -> V_49 ) {
V_55 = F_55 ( sizeof( * V_55 ) , V_71 ) ;
if ( V_55 == NULL ) {
V_40 = - V_72 ;
goto V_128;
}
V_100 = F_47 ( V_7 ,
V_7 -> V_70 ) ;
V_102 = V_100 -> V_30 . V_38 / 8 ;
if ( V_127 % V_102 )
V_127 += V_102 - V_127 % V_102 ;
if ( V_126 % V_102 )
V_126 += V_102 - V_126 % V_102 ;
V_55 -> V_118 = V_126 ;
V_55 -> V_117 = V_127 ;
V_55 -> V_102 = V_102 ;
F_66 ( & V_55 -> V_123 , & V_11 -> V_21 ) ;
V_127 += V_102 ;
V_126 += V_102 ;
}
V_11 -> V_116 = F_67 ( V_127 , V_71 ) ;
if ( V_11 -> V_116 == NULL ) {
V_40 = - V_72 ;
goto V_128;
}
return 0 ;
V_128:
F_62 ( V_11 ) ;
return V_40 ;
}
