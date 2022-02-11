static bool F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 -> V_5 )
return V_2 -> V_4 -> V_5 ( V_2 ) ;
return V_2 -> V_6 ;
}
T_1 F_4 ( struct V_7 * V_8 , char T_2 * V_2 ,
T_3 V_9 , T_4 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_1 * V_14 = V_12 -> V_15 ;
int V_16 ;
if ( ! V_12 -> V_17 )
return - V_18 ;
if ( ! V_14 || ! V_14 -> V_4 -> V_19 )
return - V_20 ;
do {
if ( ! F_3 ( V_14 ) ) {
if ( V_8 -> V_21 & V_22 )
return - V_23 ;
V_16 = F_5 ( V_14 -> V_24 ,
F_3 ( V_14 ) ||
V_12 -> V_17 == NULL ) ;
if ( V_16 )
return V_16 ;
if ( V_12 -> V_17 == NULL )
return - V_18 ;
}
V_16 = V_14 -> V_4 -> V_19 ( V_14 , V_9 , V_2 ) ;
if ( V_16 == 0 && ( V_8 -> V_21 & V_22 ) )
V_16 = - V_23 ;
} while ( V_16 == 0 );
return V_16 ;
}
unsigned int F_6 ( struct V_7 * V_8 ,
struct V_25 * V_26 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_1 * V_14 = V_12 -> V_15 ;
if ( ! V_12 -> V_17 )
return - V_18 ;
F_7 ( V_8 , & V_14 -> V_24 , V_26 ) ;
if ( F_3 ( V_14 ) )
return V_27 | V_28 ;
return 0 ;
}
void F_8 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_15 )
return;
F_9 ( & V_12 -> V_15 -> V_24 ) ;
}
void F_10 ( struct V_1 * V_15 )
{
F_11 ( & V_15 -> V_29 ) ;
F_11 ( & V_15 -> V_3 ) ;
F_12 ( & V_15 -> V_24 ) ;
F_13 ( & V_15 -> V_30 ) ;
}
static T_1 F_14 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_15 ( V_34 ) -> V_35 -> V_36 ) ;
}
static T_1 F_16 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_37 * V_38 = F_15 ( V_34 ) ;
T_5 type = V_38 -> V_35 -> V_39 . V_40 ;
if ( type == V_41 ) {
#ifdef F_17
type = V_42 ;
#else
type = V_43 ;
#endif
}
if ( V_38 -> V_35 -> V_39 . V_44 > 1 )
return sprintf ( V_2 , L_2 ,
V_45 [ type ] ,
V_38 -> V_35 -> V_39 . V_46 ,
V_38 -> V_35 -> V_39 . V_47 ,
V_38 -> V_35 -> V_39 . V_48 ,
V_38 -> V_35 -> V_39 . V_44 ,
V_38 -> V_35 -> V_39 . V_49 ) ;
else
return sprintf ( V_2 , L_3 ,
V_45 [ type ] ,
V_38 -> V_35 -> V_39 . V_46 ,
V_38 -> V_35 -> V_39 . V_47 ,
V_38 -> V_35 -> V_39 . V_48 ,
V_38 -> V_35 -> V_39 . V_49 ) ;
}
static T_1 F_18 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
int V_16 ;
struct V_11 * V_12 = F_19 ( V_32 ) ;
V_16 = ! ! F_20 ( F_15 ( V_34 ) -> V_50 ,
V_12 -> V_15 -> V_51 ) ;
return sprintf ( V_2 , L_4 , V_16 ) ;
}
static int F_21 ( struct V_1 * V_15 , int V_52 )
{
F_22 ( V_52 , V_15 -> V_51 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 ,
T_3 V_53 )
{
int V_16 ;
bool V_54 ;
struct V_11 * V_12 = F_19 ( V_32 ) ;
struct V_1 * V_15 = V_12 -> V_15 ;
struct V_37 * V_38 = F_15 ( V_34 ) ;
V_16 = F_24 ( V_2 , & V_54 ) ;
if ( V_16 < 0 )
return V_16 ;
F_25 ( & V_12 -> V_55 ) ;
if ( F_1 ( V_12 -> V_15 ) ) {
V_16 = - V_56 ;
goto V_57;
}
V_16 = F_26 ( V_12 , V_15 , V_38 -> V_50 ) ;
if ( V_16 < 0 )
goto V_57;
if ( ! V_54 && V_16 ) {
V_16 = F_21 ( V_15 , V_38 -> V_50 ) ;
if ( V_16 )
goto V_57;
} else if ( V_54 && ! V_16 ) {
V_16 = F_27 ( V_12 , V_15 , V_38 -> V_50 ) ;
if ( V_16 )
goto V_57;
}
V_57:
F_28 ( & V_12 -> V_55 ) ;
return V_16 < 0 ? V_16 : V_53 ;
}
static T_1 F_29 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_11 * V_12 = F_19 ( V_32 ) ;
return sprintf ( V_2 , L_4 , V_12 -> V_15 -> V_58 ) ;
}
static T_1 F_30 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 ,
T_3 V_53 )
{
int V_16 ;
struct V_11 * V_12 = F_19 ( V_32 ) ;
bool V_54 ;
V_16 = F_24 ( V_2 , & V_54 ) ;
if ( V_16 < 0 )
return V_16 ;
F_25 ( & V_12 -> V_55 ) ;
if ( F_1 ( V_12 -> V_15 ) ) {
V_16 = - V_56 ;
goto V_57;
}
V_12 -> V_15 -> V_58 = V_54 ;
V_57:
F_28 ( & V_12 -> V_55 ) ;
return V_16 ? V_16 : V_53 ;
}
static int F_31 ( struct V_11 * V_12 ,
const struct V_59 * V_60 )
{
int V_16 , V_61 = 0 ;
struct V_1 * V_15 = V_12 -> V_15 ;
V_16 = F_32 ( L_5 ,
V_60 ,
& F_14 ,
NULL ,
0 ,
V_62 ,
& V_12 -> V_32 ,
& V_15 -> V_63 ) ;
if ( V_16 )
return V_16 ;
V_61 ++ ;
V_16 = F_32 ( L_6 ,
V_60 ,
& F_16 ,
NULL ,
0 ,
0 ,
& V_12 -> V_32 ,
& V_15 -> V_63 ) ;
if ( V_16 )
return V_16 ;
V_61 ++ ;
if ( V_60 -> type != V_64 )
V_16 = F_32 ( L_7 ,
V_60 ,
& F_18 ,
& F_23 ,
V_60 -> V_36 ,
0 ,
& V_12 -> V_32 ,
& V_15 -> V_63 ) ;
else
V_16 = F_32 ( L_7 ,
V_60 ,
& F_29 ,
& F_30 ,
V_60 -> V_36 ,
0 ,
& V_12 -> V_32 ,
& V_15 -> V_63 ) ;
if ( V_16 )
return V_16 ;
V_61 ++ ;
V_16 = V_61 ;
return V_16 ;
}
int F_33 ( struct V_11 * V_12 ,
const struct V_59 * V_65 ,
int V_66 )
{
struct V_37 * V_67 ;
struct V_68 * * V_34 ;
struct V_1 * V_15 = V_12 -> V_15 ;
int V_16 , V_69 , V_70 , V_61 , V_71 = 0 ;
if ( V_15 -> V_72 )
V_12 -> V_73 [ V_12 -> V_74 ++ ] = V_15 -> V_72 ;
if ( V_15 -> V_75 != NULL ) {
V_34 = V_15 -> V_75 -> V_72 ;
while ( * V_34 ++ != NULL )
V_71 ++ ;
}
V_61 = V_71 ;
F_11 ( & V_15 -> V_63 ) ;
if ( V_65 ) {
for ( V_69 = 0 ; V_69 < V_66 ; V_69 ++ ) {
if ( V_65 [ V_69 ] . V_36 < 0 )
continue;
if ( V_65 [ V_69 ] . V_36 >
( int ) V_12 -> V_76 - 1 )
V_12 -> V_76
= V_65 [ V_69 ] . V_36 + 1 ;
V_16 = F_31 ( V_12 ,
& V_65 [ V_69 ] ) ;
if ( V_16 < 0 )
goto V_77;
V_61 += V_16 ;
if ( V_65 [ V_69 ] . type == V_64 )
V_12 -> V_78 =
V_65 [ V_69 ] . V_36 ;
}
if ( V_12 -> V_76 && V_15 -> V_51 == NULL ) {
V_15 -> V_51 = F_34 ( F_35 ( V_12 -> V_76 ) ,
sizeof( * V_15 -> V_51 ) ,
V_79 ) ;
if ( V_15 -> V_51 == NULL ) {
V_16 = - V_80 ;
goto V_77;
}
}
}
V_15 -> V_81 . V_82 = V_83 ;
V_15 -> V_81 . V_72 = F_34 ( V_61 + 1 ,
sizeof( V_15 -> V_81 . V_72 [ 0 ] ) ,
V_79 ) ;
if ( V_15 -> V_81 . V_72 == NULL ) {
V_16 = - V_80 ;
goto V_84;
}
if ( V_15 -> V_75 )
memcpy ( V_15 -> V_81 . V_72 , V_15 -> V_75 ,
sizeof( V_15 -> V_81 . V_72 [ 0 ] ) * V_71 ) ;
V_70 = V_71 ;
F_36 (p, &buffer->scan_el_dev_attr_list, l)
V_15 -> V_81 . V_72 [ V_70 ++ ] = & V_67 -> V_85 . V_34 ;
V_12 -> V_73 [ V_12 -> V_74 ++ ] = & V_15 -> V_81 ;
return 0 ;
V_84:
F_37 ( V_15 -> V_51 ) ;
V_77:
F_38 ( & V_15 -> V_63 ) ;
return V_16 ;
}
void F_39 ( struct V_11 * V_12 )
{
F_37 ( V_12 -> V_15 -> V_51 ) ;
F_37 ( V_12 -> V_15 -> V_81 . V_72 ) ;
F_38 ( & V_12 -> V_15 -> V_63 ) ;
}
T_1 F_40 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_11 * V_12 = F_19 ( V_32 ) ;
struct V_1 * V_15 = V_12 -> V_15 ;
if ( V_15 -> V_4 -> V_86 )
return sprintf ( V_2 , L_4 ,
V_15 -> V_4 -> V_86 ( V_15 ) ) ;
return 0 ;
}
T_1 F_41 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 ,
T_3 V_53 )
{
struct V_11 * V_12 = F_19 ( V_32 ) ;
struct V_1 * V_15 = V_12 -> V_15 ;
unsigned int V_87 ;
int V_16 ;
V_16 = F_42 ( V_2 , 10 , & V_87 ) ;
if ( V_16 )
return V_16 ;
if ( V_15 -> V_4 -> V_86 )
if ( V_87 == V_15 -> V_4 -> V_86 ( V_15 ) )
return V_53 ;
F_25 ( & V_12 -> V_55 ) ;
if ( F_1 ( V_12 -> V_15 ) ) {
V_16 = - V_56 ;
} else {
if ( V_15 -> V_4 -> V_88 )
V_15 -> V_4 -> V_88 ( V_15 , V_87 ) ;
V_16 = 0 ;
}
F_28 ( & V_12 -> V_55 ) ;
return V_16 ? V_16 : V_53 ;
}
T_1 F_43 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
char * V_2 )
{
struct V_11 * V_12 = F_19 ( V_32 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_12 -> V_15 ) ) ;
}
static const unsigned long * F_44 ( const unsigned long * V_89 ,
unsigned int V_76 ,
const unsigned long * V_90 )
{
if ( F_45 ( V_90 , V_76 ) )
return NULL ;
while ( * V_89 ) {
if ( F_46 ( V_90 , V_89 , V_76 ) )
return V_89 ;
V_89 += F_35 ( V_76 ) ;
}
return NULL ;
}
static int F_47 ( struct V_11 * V_12 ,
const unsigned long * V_90 , bool V_91 )
{
const struct V_59 * V_92 ;
unsigned V_93 = 0 ;
int V_94 , V_69 ;
F_48 (i, mask,
indio_dev->masklength) {
V_92 = F_49 ( V_12 , V_69 ) ;
if ( V_92 -> V_39 . V_44 > 1 )
V_94 = V_92 -> V_39 . V_48 / 8 *
V_92 -> V_39 . V_44 ;
else
V_94 = V_92 -> V_39 . V_48 / 8 ;
V_93 = F_50 ( V_93 , V_94 ) ;
V_93 += V_94 ;
}
if ( V_91 ) {
V_92 = F_49 ( V_12 ,
V_12 -> V_78 ) ;
if ( V_92 -> V_39 . V_44 > 1 )
V_94 = V_92 -> V_39 . V_48 / 8 *
V_92 -> V_39 . V_44 ;
else
V_94 = V_92 -> V_39 . V_48 / 8 ;
V_93 = F_50 ( V_93 , V_94 ) ;
V_93 += V_94 ;
}
return V_93 ;
}
static void F_51 ( struct V_11 * V_12 ,
struct V_1 * V_15 )
{
F_52 ( V_15 ) ;
F_53 ( & V_15 -> V_3 , & V_12 -> V_3 ) ;
}
static void F_54 ( struct V_1 * V_15 )
{
F_55 ( & V_15 -> V_3 ) ;
F_56 ( V_15 ) ;
}
void F_57 ( struct V_11 * V_12 )
{
struct V_1 * V_15 , * V_95 ;
if ( F_2 ( & V_12 -> V_3 ) )
return;
if ( V_12 -> V_96 -> V_97 )
V_12 -> V_96 -> V_97 ( V_12 ) ;
F_58 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_54 ( V_15 ) ;
V_12 -> V_98 = V_99 ;
if ( V_12 -> V_96 -> V_100 )
V_12 -> V_96 -> V_100 ( V_12 ) ;
if ( V_12 -> V_101 == NULL )
F_37 ( V_12 -> V_102 ) ;
}
static void F_59 ( struct V_11 * V_12 ,
struct V_1 * V_15 )
{
unsigned int V_93 ;
if ( ! V_15 -> V_4 -> V_103 )
return;
V_93 = F_47 ( V_12 , V_15 -> V_51 ,
V_15 -> V_58 ) ;
V_15 -> V_4 -> V_103 ( V_15 , V_93 ) ;
}
static int F_60 ( struct V_11 * V_12 ,
struct V_1 * V_104 ,
struct V_1 * V_105 )
{
int V_16 ;
int V_106 = 0 ;
struct V_1 * V_15 ;
unsigned long * V_107 ;
const unsigned long * V_108 ;
if ( ! F_2 ( & V_12 -> V_3 ) ) {
if ( V_12 -> V_96 -> V_97 ) {
V_16 = V_12 -> V_96 -> V_97 ( V_12 ) ;
if ( V_16 )
return V_16 ;
}
V_12 -> V_98 = V_99 ;
if ( V_12 -> V_96 -> V_100 ) {
V_16 = V_12 -> V_96 -> V_100 ( V_12 ) ;
if ( V_16 )
return V_16 ;
}
}
V_108 = V_12 -> V_102 ;
if ( ! V_12 -> V_101 )
V_12 -> V_102 = NULL ;
if ( V_105 )
F_54 ( V_105 ) ;
if ( V_104 )
F_51 ( V_12 , V_104 ) ;
if ( F_2 ( & V_12 -> V_3 ) ) {
V_12 -> V_98 = V_99 ;
if ( V_12 -> V_101 == NULL )
F_37 ( V_108 ) ;
return 0 ;
}
V_107 = F_34 ( F_35 ( V_12 -> V_76 ) ,
sizeof( long ) , V_79 ) ;
if ( V_107 == NULL ) {
if ( V_12 -> V_101 == NULL )
F_37 ( V_108 ) ;
return - V_80 ;
}
V_12 -> V_58 = 0 ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
F_61 ( V_107 , V_107 , V_15 -> V_51 ,
V_12 -> V_76 ) ;
V_12 -> V_58 |= V_15 -> V_58 ;
}
if ( V_12 -> V_101 ) {
V_12 -> V_102 =
F_44 ( V_12 -> V_101 ,
V_12 -> V_76 ,
V_107 ) ;
if ( V_12 -> V_102 == NULL ) {
F_54 ( V_104 ) ;
if ( V_108 ) {
V_12 -> V_102 = V_108 ;
V_106 = - V_20 ;
}
else {
F_37 ( V_107 ) ;
V_16 = - V_20 ;
return V_16 ;
}
}
} else {
V_12 -> V_102 = V_107 ;
}
F_62 ( V_12 ) ;
if ( V_12 -> V_96 -> V_109 ) {
V_16 = V_12 -> V_96 -> V_109 ( V_12 ) ;
if ( V_16 ) {
F_63 ( V_110
L_8 , V_16 ) ;
goto V_111;
}
}
V_12 -> V_112 =
F_47 ( V_12 ,
V_12 -> V_102 ,
V_12 -> V_58 ) ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
F_59 ( V_12 , V_15 ) ;
if ( V_15 -> V_4 -> V_113 ) {
V_16 = V_15 -> V_4 -> V_113 ( V_15 ) ;
if ( V_16 ) {
F_63 ( V_114
L_9 , V_16 ) ;
goto V_115;
}
}
}
if ( V_12 -> V_17 -> V_116 ) {
V_16 = V_12 -> V_17
-> V_116 ( V_12 ,
V_12 -> V_102 ) ;
if ( V_16 < 0 ) {
F_63 ( V_114 L_10 , V_16 ) ;
goto V_115;
}
}
if ( V_12 -> V_117 & V_118 ) {
if ( ! V_12 -> V_119 ) {
F_63 ( V_114 L_11 ) ;
V_16 = - V_20 ;
goto V_115;
}
V_12 -> V_98 = V_118 ;
} else if ( V_12 -> V_117 & V_120 ) {
V_12 -> V_98 = V_120 ;
} else {
V_16 = - V_20 ;
goto V_115;
}
if ( V_12 -> V_96 -> V_121 ) {
V_16 = V_12 -> V_96 -> V_121 ( V_12 ) ;
if ( V_16 ) {
F_63 ( V_114
L_12 , V_16 ) ;
V_12 -> V_98 = V_99 ;
if ( V_12 -> V_96 -> V_100 )
V_12 -> V_96 -> V_100 ( V_12 ) ;
goto V_122;
}
}
if ( V_12 -> V_101 )
F_37 ( V_107 ) ;
else
F_37 ( V_108 ) ;
return V_106 ;
V_122:
V_12 -> V_98 = V_99 ;
V_115:
if ( V_12 -> V_96 -> V_100 )
V_12 -> V_96 -> V_100 ( V_12 ) ;
V_111:
if ( V_104 )
F_54 ( V_104 ) ;
V_12 -> V_102 = V_108 ;
F_37 ( V_107 ) ;
return V_16 ;
}
int F_64 ( struct V_11 * V_12 ,
struct V_1 * V_104 ,
struct V_1 * V_105 )
{
int V_16 ;
if ( V_104 == V_105 )
return 0 ;
F_25 ( & V_12 -> V_123 ) ;
F_25 ( & V_12 -> V_55 ) ;
if ( V_104 && F_1 ( V_104 ) )
V_104 = NULL ;
if ( V_105 && ! F_1 ( V_105 ) )
V_105 = NULL ;
if ( ! V_104 && ! V_105 ) {
V_16 = 0 ;
goto V_124;
}
if ( V_12 -> V_17 == NULL ) {
V_16 = - V_18 ;
goto V_124;
}
V_16 = F_60 ( V_12 , V_104 , V_105 ) ;
V_124:
F_28 ( & V_12 -> V_55 ) ;
F_28 ( & V_12 -> V_123 ) ;
return V_16 ;
}
T_1 F_65 ( struct V_31 * V_32 ,
struct V_33 * V_34 ,
const char * V_2 ,
T_3 V_53 )
{
int V_16 ;
bool V_125 ;
struct V_11 * V_12 = F_19 ( V_32 ) ;
bool V_126 ;
V_16 = F_24 ( V_2 , & V_125 ) ;
if ( V_16 < 0 )
return V_16 ;
F_25 ( & V_12 -> V_55 ) ;
V_126 = F_1 ( V_12 -> V_15 ) ;
if ( V_126 == V_125 )
goto V_127;
if ( V_125 )
V_16 = F_60 ( V_12 ,
V_12 -> V_15 , NULL ) ;
else
V_16 = F_60 ( V_12 ,
NULL , V_12 -> V_15 ) ;
if ( V_16 < 0 )
goto V_127;
V_127:
F_28 ( & V_12 -> V_55 ) ;
return ( V_16 < 0 ) ? V_16 : V_53 ;
}
bool F_66 ( struct V_11 * V_12 ,
const unsigned long * V_90 )
{
return F_67 ( V_90 , V_12 -> V_76 ) == 1 ;
}
static bool F_68 ( struct V_11 * V_12 ,
const unsigned long * V_90 )
{
if ( ! V_12 -> V_96 -> V_128 )
return true ;
return V_12 -> V_96 -> V_128 ( V_12 , V_90 ) ;
}
int F_27 ( struct V_11 * V_12 ,
struct V_1 * V_15 , int V_52 )
{
const unsigned long * V_90 ;
unsigned long * V_129 ;
V_129 = F_69 ( sizeof( * V_129 ) *
F_35 ( V_12 -> V_76 ) ,
V_79 ) ;
if ( V_129 == NULL )
return - V_80 ;
if ( ! V_12 -> V_76 ) {
F_70 ( L_13 ) ;
goto V_130;
}
F_71 ( V_129 , V_15 -> V_51 , V_12 -> V_76 ) ;
F_72 ( V_52 , V_129 ) ;
if ( ! F_68 ( V_12 , V_129 ) )
goto V_130;
if ( V_12 -> V_101 ) {
V_90 = F_44 ( V_12 -> V_101 ,
V_12 -> V_76 ,
V_129 ) ;
if ( ! V_90 )
goto V_130;
}
F_71 ( V_15 -> V_51 , V_129 , V_12 -> V_76 ) ;
F_37 ( V_129 ) ;
return 0 ;
V_130:
F_37 ( V_129 ) ;
return - V_20 ;
}
int F_26 ( struct V_11 * V_12 ,
struct V_1 * V_15 , int V_52 )
{
if ( V_52 > V_12 -> V_76 )
return - V_20 ;
if ( ! V_15 -> V_51 )
return 0 ;
return ! ! F_20 ( V_52 , V_15 -> V_51 ) ;
}
static const void * F_73 ( struct V_1 * V_15 ,
const void * V_131 )
{
struct V_132 * V_133 ;
if ( F_2 ( & V_15 -> V_29 ) )
return V_131 ;
F_36 (t, &buffer->demux_list, l)
memcpy ( V_15 -> V_134 + V_133 -> V_135 ,
V_131 + V_133 -> V_136 , V_133 -> V_94 ) ;
return V_15 -> V_134 ;
}
static int F_74 ( struct V_1 * V_15 , const void * V_137 )
{
const void * V_138 = F_73 ( V_15 , V_137 ) ;
return V_15 -> V_4 -> V_139 ( V_15 , V_138 ) ;
}
static void F_75 ( struct V_1 * V_15 )
{
struct V_132 * V_67 , * V_140 ;
F_58 (p, q, &buffer->demux_list, l) {
F_76 ( & V_67 -> V_141 ) ;
F_37 ( V_67 ) ;
}
}
int F_77 ( struct V_11 * V_12 , const void * V_137 )
{
int V_16 ;
struct V_1 * V_2 ;
F_36 (buf, &indio_dev->buffer_list, buffer_list) {
V_16 = F_74 ( V_2 , V_137 ) ;
if ( V_16 < 0 )
return V_16 ;
}
return 0 ;
}
static int F_78 ( struct V_11 * V_12 ,
struct V_1 * V_15 )
{
const struct V_59 * V_92 ;
int V_16 , V_142 = - 1 , V_143 , V_94 ;
unsigned V_144 = 0 , V_145 = 0 ;
struct V_132 * V_67 ;
F_75 ( V_15 ) ;
F_37 ( V_15 -> V_134 ) ;
V_15 -> V_134 = NULL ;
if ( F_79 ( V_12 -> V_102 ,
V_15 -> V_51 ,
V_12 -> V_76 ) )
return 0 ;
F_48 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_142 = F_80 ( V_12 -> V_102 ,
V_12 -> V_76 ,
V_142 + 1 ) ;
while ( V_142 != V_143 ) {
V_142 = F_80 ( V_12 -> V_102 ,
V_12 -> V_76 ,
V_142 + 1 ) ;
V_92 = F_49 ( V_12 , V_142 ) ;
if ( V_92 -> V_39 . V_44 > 1 )
V_94 = V_92 -> V_39 . V_48 / 8 *
V_92 -> V_39 . V_44 ;
else
V_94 = V_92 -> V_39 . V_48 / 8 ;
V_144 += V_94 ;
if ( V_144 % V_94 )
V_144 += V_94 - V_144 % V_94 ;
}
V_67 = F_69 ( sizeof( * V_67 ) , V_79 ) ;
if ( V_67 == NULL ) {
V_16 = - V_80 ;
goto V_146;
}
V_92 = F_49 ( V_12 , V_142 ) ;
if ( V_92 -> V_39 . V_44 > 1 )
V_94 = V_92 -> V_39 . V_48 / 8 *
V_92 -> V_39 . V_44 ;
else
V_94 = V_92 -> V_39 . V_48 / 8 ;
if ( V_145 % V_94 )
V_145 += V_94 - V_145 % V_94 ;
if ( V_144 % V_94 )
V_144 += V_94 - V_144 % V_94 ;
V_67 -> V_136 = V_144 ;
V_67 -> V_135 = V_145 ;
V_67 -> V_94 = V_94 ;
F_81 ( & V_67 -> V_141 , & V_15 -> V_29 ) ;
V_145 += V_94 ;
V_144 += V_94 ;
}
if ( V_15 -> V_58 ) {
V_67 = F_69 ( sizeof( * V_67 ) , V_79 ) ;
if ( V_67 == NULL ) {
V_16 = - V_80 ;
goto V_146;
}
V_92 = F_49 ( V_12 ,
V_12 -> V_78 ) ;
if ( V_92 -> V_39 . V_44 > 1 )
V_94 = V_92 -> V_39 . V_48 / 8 *
V_92 -> V_39 . V_44 ;
else
V_94 = V_92 -> V_39 . V_48 / 8 ;
if ( V_145 % V_94 )
V_145 += V_94 - V_145 % V_94 ;
if ( V_144 % V_94 )
V_144 += V_94 - V_144 % V_94 ;
V_67 -> V_136 = V_144 ;
V_67 -> V_135 = V_145 ;
V_67 -> V_94 = V_94 ;
F_81 ( & V_67 -> V_141 , & V_15 -> V_29 ) ;
V_145 += V_94 ;
V_144 += V_94 ;
}
V_15 -> V_134 = F_82 ( V_145 , V_79 ) ;
if ( V_15 -> V_134 == NULL ) {
V_16 = - V_80 ;
goto V_146;
}
return 0 ;
V_146:
F_75 ( V_15 ) ;
return V_16 ;
}
int F_62 ( struct V_11 * V_12 )
{
struct V_1 * V_15 ;
int V_16 ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
V_16 = F_78 ( V_12 , V_15 ) ;
if ( V_16 < 0 )
goto V_146;
}
return 0 ;
V_146:
F_36 (buffer, &indio_dev->buffer_list, buffer_list)
F_75 ( V_15 ) ;
return V_16 ;
}
static void F_83 ( struct V_147 * V_30 )
{
struct V_1 * V_15 = F_84 ( V_30 , struct V_1 , V_30 ) ;
V_15 -> V_4 -> V_148 ( V_15 ) ;
}
struct V_1 * F_52 ( struct V_1 * V_15 )
{
if ( V_15 )
F_85 ( & V_15 -> V_30 ) ;
return V_15 ;
}
void F_56 ( struct V_1 * V_15 )
{
if ( V_15 )
F_86 ( & V_15 -> V_30 , F_83 ) ;
}
