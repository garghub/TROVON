static bool F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_5 ( V_2 ) ;
}
T_1 F_4 ( struct V_6 * V_7 , char T_2 * V_2 ,
T_3 V_8 , T_4 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_1 * V_13 = V_11 -> V_14 ;
int V_15 ;
if ( ! V_11 -> V_16 )
return - V_17 ;
if ( ! V_13 || ! V_13 -> V_4 -> V_18 )
return - V_19 ;
do {
if ( ! F_3 ( V_13 ) ) {
if ( V_7 -> V_20 & V_21 )
return - V_22 ;
V_15 = F_5 ( V_13 -> V_23 ,
F_3 ( V_13 ) ||
V_11 -> V_16 == NULL ) ;
if ( V_15 )
return V_15 ;
if ( V_11 -> V_16 == NULL )
return - V_17 ;
}
V_15 = V_13 -> V_4 -> V_18 ( V_13 , V_8 , V_2 ) ;
if ( V_15 == 0 && ( V_7 -> V_20 & V_21 ) )
V_15 = - V_22 ;
} while ( V_15 == 0 );
return V_15 ;
}
unsigned int F_6 ( struct V_6 * V_7 ,
struct V_24 * V_25 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_1 * V_13 = V_11 -> V_14 ;
if ( ! V_11 -> V_16 )
return - V_17 ;
F_7 ( V_7 , & V_13 -> V_23 , V_25 ) ;
if ( F_3 ( V_13 ) )
return V_26 | V_27 ;
return 0 ;
}
void F_8 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_14 )
return;
F_9 ( & V_11 -> V_14 -> V_23 ) ;
}
void F_10 ( struct V_1 * V_14 )
{
F_11 ( & V_14 -> V_28 ) ;
F_11 ( & V_14 -> V_3 ) ;
F_12 ( & V_14 -> V_23 ) ;
F_13 ( & V_14 -> V_29 ) ;
}
static T_1 F_14 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
return sprintf ( V_2 , L_1 , F_15 ( V_33 ) -> V_34 -> V_35 ) ;
}
static T_1 F_16 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_36 * V_37 = F_15 ( V_33 ) ;
T_5 type = V_37 -> V_34 -> V_38 . V_39 ;
if ( type == V_40 ) {
#ifdef F_17
type = V_41 ;
#else
type = V_42 ;
#endif
}
if ( V_37 -> V_34 -> V_38 . V_43 > 1 )
return sprintf ( V_2 , L_2 ,
V_44 [ type ] ,
V_37 -> V_34 -> V_38 . V_45 ,
V_37 -> V_34 -> V_38 . V_46 ,
V_37 -> V_34 -> V_38 . V_47 ,
V_37 -> V_34 -> V_38 . V_43 ,
V_37 -> V_34 -> V_38 . V_48 ) ;
else
return sprintf ( V_2 , L_3 ,
V_44 [ type ] ,
V_37 -> V_34 -> V_38 . V_45 ,
V_37 -> V_34 -> V_38 . V_46 ,
V_37 -> V_34 -> V_38 . V_47 ,
V_37 -> V_34 -> V_38 . V_48 ) ;
}
static T_1 F_18 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
int V_15 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
V_15 = ! ! F_20 ( F_15 ( V_33 ) -> V_49 ,
V_11 -> V_14 -> V_50 ) ;
return sprintf ( V_2 , L_4 , V_15 ) ;
}
static int F_21 ( struct V_1 * V_14 , int V_51 )
{
F_22 ( V_51 , V_14 -> V_50 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_52 )
{
int V_15 ;
bool V_53 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
struct V_36 * V_37 = F_15 ( V_33 ) ;
V_15 = F_24 ( V_2 , & V_53 ) ;
if ( V_15 < 0 )
return V_15 ;
F_25 ( & V_11 -> V_54 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_55 ;
goto V_56;
}
V_15 = F_26 ( V_11 , V_14 , V_37 -> V_49 ) ;
if ( V_15 < 0 )
goto V_56;
if ( ! V_53 && V_15 ) {
V_15 = F_21 ( V_14 , V_37 -> V_49 ) ;
if ( V_15 )
goto V_56;
} else if ( V_53 && ! V_15 ) {
V_15 = F_27 ( V_11 , V_14 , V_37 -> V_49 ) ;
if ( V_15 )
goto V_56;
}
V_56:
F_28 ( & V_11 -> V_54 ) ;
return V_15 < 0 ? V_15 : V_52 ;
}
static T_1 F_29 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
return sprintf ( V_2 , L_4 , V_11 -> V_14 -> V_57 ) ;
}
static T_1 F_30 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_52 )
{
int V_15 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
bool V_53 ;
V_15 = F_24 ( V_2 , & V_53 ) ;
if ( V_15 < 0 )
return V_15 ;
F_25 ( & V_11 -> V_54 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_55 ;
goto V_56;
}
V_11 -> V_14 -> V_57 = V_53 ;
V_56:
F_28 ( & V_11 -> V_54 ) ;
return V_15 ? V_15 : V_52 ;
}
static int F_31 ( struct V_10 * V_11 ,
const struct V_58 * V_59 )
{
int V_15 , V_60 = 0 ;
struct V_1 * V_14 = V_11 -> V_14 ;
V_15 = F_32 ( L_5 ,
V_59 ,
& F_14 ,
NULL ,
0 ,
V_61 ,
& V_11 -> V_31 ,
& V_14 -> V_62 ) ;
if ( V_15 )
return V_15 ;
V_60 ++ ;
V_15 = F_32 ( L_6 ,
V_59 ,
& F_16 ,
NULL ,
0 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_62 ) ;
if ( V_15 )
return V_15 ;
V_60 ++ ;
if ( V_59 -> type != V_63 )
V_15 = F_32 ( L_7 ,
V_59 ,
& F_18 ,
& F_23 ,
V_59 -> V_35 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_62 ) ;
else
V_15 = F_32 ( L_7 ,
V_59 ,
& F_29 ,
& F_30 ,
V_59 -> V_35 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_62 ) ;
if ( V_15 )
return V_15 ;
V_60 ++ ;
V_15 = V_60 ;
return V_15 ;
}
int F_33 ( struct V_10 * V_11 ,
const struct V_58 * V_64 ,
int V_65 )
{
struct V_36 * V_66 ;
struct V_67 * * V_33 ;
struct V_1 * V_14 = V_11 -> V_14 ;
int V_15 , V_68 , V_69 , V_60 , V_70 = 0 ;
if ( V_14 -> V_71 )
V_11 -> V_72 [ V_11 -> V_73 ++ ] = V_14 -> V_71 ;
if ( V_14 -> V_74 != NULL ) {
V_33 = V_14 -> V_74 -> V_71 ;
while ( * V_33 ++ != NULL )
V_70 ++ ;
}
V_60 = V_70 ;
F_11 ( & V_14 -> V_62 ) ;
if ( V_64 ) {
for ( V_68 = 0 ; V_68 < V_65 ; V_68 ++ ) {
if ( V_64 [ V_68 ] . V_35 < 0 )
continue;
if ( V_64 [ V_68 ] . V_35 >
( int ) V_11 -> V_75 - 1 )
V_11 -> V_75
= V_64 [ V_68 ] . V_35 + 1 ;
V_15 = F_31 ( V_11 ,
& V_64 [ V_68 ] ) ;
if ( V_15 < 0 )
goto V_76;
V_60 += V_15 ;
if ( V_64 [ V_68 ] . type == V_63 )
V_11 -> V_77 =
V_64 [ V_68 ] . V_35 ;
}
if ( V_11 -> V_75 && V_14 -> V_50 == NULL ) {
V_14 -> V_50 = F_34 ( F_35 ( V_11 -> V_75 ) ,
sizeof( * V_14 -> V_50 ) ,
V_78 ) ;
if ( V_14 -> V_50 == NULL ) {
V_15 = - V_79 ;
goto V_76;
}
}
}
V_14 -> V_80 . V_81 = V_82 ;
V_14 -> V_80 . V_71 = F_34 ( V_60 + 1 ,
sizeof( V_14 -> V_80 . V_71 [ 0 ] ) ,
V_78 ) ;
if ( V_14 -> V_80 . V_71 == NULL ) {
V_15 = - V_79 ;
goto V_83;
}
if ( V_14 -> V_74 )
memcpy ( V_14 -> V_80 . V_71 , V_14 -> V_74 ,
sizeof( V_14 -> V_80 . V_71 [ 0 ] ) * V_70 ) ;
V_69 = V_70 ;
F_36 (p, &buffer->scan_el_dev_attr_list, l)
V_14 -> V_80 . V_71 [ V_69 ++ ] = & V_66 -> V_84 . V_33 ;
V_11 -> V_72 [ V_11 -> V_73 ++ ] = & V_14 -> V_80 ;
return 0 ;
V_83:
F_37 ( V_14 -> V_50 ) ;
V_76:
F_38 ( & V_14 -> V_62 ) ;
return V_15 ;
}
void F_39 ( struct V_10 * V_11 )
{
F_37 ( V_11 -> V_14 -> V_50 ) ;
F_37 ( V_11 -> V_14 -> V_80 . V_71 ) ;
F_38 ( & V_11 -> V_14 -> V_62 ) ;
}
T_1 F_40 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
if ( V_14 -> V_4 -> V_85 )
return sprintf ( V_2 , L_4 ,
V_14 -> V_4 -> V_85 ( V_14 ) ) ;
return 0 ;
}
T_1 F_41 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_52 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
unsigned int V_86 ;
int V_15 ;
V_15 = F_42 ( V_2 , 10 , & V_86 ) ;
if ( V_15 )
return V_15 ;
if ( V_14 -> V_4 -> V_85 )
if ( V_86 == V_14 -> V_4 -> V_85 ( V_14 ) )
return V_52 ;
F_25 ( & V_11 -> V_54 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_55 ;
} else {
if ( V_14 -> V_4 -> V_87 )
V_14 -> V_4 -> V_87 ( V_14 , V_86 ) ;
V_15 = 0 ;
}
F_28 ( & V_11 -> V_54 ) ;
return V_15 ? V_15 : V_52 ;
}
T_1 F_43 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_11 -> V_14 ) ) ;
}
static const unsigned long * F_44 ( const unsigned long * V_88 ,
unsigned int V_75 ,
const unsigned long * V_89 )
{
if ( F_45 ( V_89 , V_75 ) )
return NULL ;
while ( * V_88 ) {
if ( F_46 ( V_89 , V_88 , V_75 ) )
return V_88 ;
V_88 += F_35 ( V_75 ) ;
}
return NULL ;
}
static int F_47 ( struct V_10 * V_11 ,
const unsigned long * V_89 , bool V_90 )
{
const struct V_58 * V_91 ;
unsigned V_92 = 0 ;
int V_93 , V_68 ;
F_48 (i, mask,
indio_dev->masklength) {
V_91 = F_49 ( V_11 , V_68 ) ;
if ( V_91 -> V_38 . V_43 > 1 )
V_93 = V_91 -> V_38 . V_47 / 8 *
V_91 -> V_38 . V_43 ;
else
V_93 = V_91 -> V_38 . V_47 / 8 ;
V_92 = F_50 ( V_92 , V_93 ) ;
V_92 += V_93 ;
}
if ( V_90 ) {
V_91 = F_49 ( V_11 ,
V_11 -> V_77 ) ;
if ( V_91 -> V_38 . V_43 > 1 )
V_93 = V_91 -> V_38 . V_47 / 8 *
V_91 -> V_38 . V_43 ;
else
V_93 = V_91 -> V_38 . V_47 / 8 ;
V_92 = F_50 ( V_92 , V_93 ) ;
V_92 += V_93 ;
}
return V_92 ;
}
static void F_51 ( struct V_10 * V_11 ,
struct V_1 * V_14 )
{
F_52 ( V_14 ) ;
F_53 ( & V_14 -> V_3 , & V_11 -> V_3 ) ;
}
static void F_54 ( struct V_1 * V_14 )
{
F_55 ( & V_14 -> V_3 ) ;
F_56 ( V_14 ) ;
}
void F_57 ( struct V_10 * V_11 )
{
struct V_1 * V_14 , * V_94 ;
if ( F_2 ( & V_11 -> V_3 ) )
return;
if ( V_11 -> V_95 -> V_96 )
V_11 -> V_95 -> V_96 ( V_11 ) ;
F_58 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_54 ( V_14 ) ;
V_11 -> V_97 = V_98 ;
if ( V_11 -> V_95 -> V_99 )
V_11 -> V_95 -> V_99 ( V_11 ) ;
if ( V_11 -> V_100 == NULL )
F_37 ( V_11 -> V_101 ) ;
}
static void F_59 ( struct V_10 * V_11 ,
struct V_1 * V_14 )
{
unsigned int V_92 ;
if ( ! V_14 -> V_4 -> V_102 )
return;
V_92 = F_47 ( V_11 , V_14 -> V_50 ,
V_14 -> V_57 ) ;
V_14 -> V_4 -> V_102 ( V_14 , V_92 ) ;
}
static int F_60 ( struct V_10 * V_11 ,
struct V_1 * V_103 ,
struct V_1 * V_104 )
{
int V_15 ;
int V_105 = 0 ;
struct V_1 * V_14 ;
unsigned long * V_106 ;
const unsigned long * V_107 ;
if ( ! F_2 ( & V_11 -> V_3 ) ) {
if ( V_11 -> V_95 -> V_96 ) {
V_15 = V_11 -> V_95 -> V_96 ( V_11 ) ;
if ( V_15 )
return V_15 ;
}
V_11 -> V_97 = V_98 ;
if ( V_11 -> V_95 -> V_99 ) {
V_15 = V_11 -> V_95 -> V_99 ( V_11 ) ;
if ( V_15 )
return V_15 ;
}
}
V_107 = V_11 -> V_101 ;
if ( ! V_11 -> V_100 )
V_11 -> V_101 = NULL ;
if ( V_104 )
F_54 ( V_104 ) ;
if ( V_103 )
F_51 ( V_11 , V_103 ) ;
if ( F_2 ( & V_11 -> V_3 ) ) {
V_11 -> V_97 = V_98 ;
if ( V_11 -> V_100 == NULL )
F_37 ( V_107 ) ;
return 0 ;
}
V_106 = F_34 ( F_35 ( V_11 -> V_75 ) ,
sizeof( long ) , V_78 ) ;
if ( V_106 == NULL ) {
if ( V_11 -> V_100 == NULL )
F_37 ( V_107 ) ;
return - V_79 ;
}
V_11 -> V_57 = 0 ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
F_61 ( V_106 , V_106 , V_14 -> V_50 ,
V_11 -> V_75 ) ;
V_11 -> V_57 |= V_14 -> V_57 ;
}
if ( V_11 -> V_100 ) {
V_11 -> V_101 =
F_44 ( V_11 -> V_100 ,
V_11 -> V_75 ,
V_106 ) ;
if ( V_11 -> V_101 == NULL ) {
F_54 ( V_103 ) ;
if ( V_107 ) {
V_11 -> V_101 = V_107 ;
V_105 = - V_19 ;
}
else {
F_37 ( V_106 ) ;
V_15 = - V_19 ;
return V_15 ;
}
}
} else {
V_11 -> V_101 = V_106 ;
}
F_62 ( V_11 ) ;
if ( V_11 -> V_95 -> V_108 ) {
V_15 = V_11 -> V_95 -> V_108 ( V_11 ) ;
if ( V_15 ) {
F_63 ( V_109
L_8 , V_15 ) ;
goto V_110;
}
}
V_11 -> V_111 =
F_47 ( V_11 ,
V_11 -> V_101 ,
V_11 -> V_57 ) ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
F_59 ( V_11 , V_14 ) ;
if ( V_14 -> V_4 -> V_112 ) {
V_15 = V_14 -> V_4 -> V_112 ( V_14 ) ;
if ( V_15 ) {
F_63 ( V_113
L_9 , V_15 ) ;
goto V_114;
}
}
}
if ( V_11 -> V_16 -> V_115 ) {
V_15 = V_11 -> V_16
-> V_115 ( V_11 ,
V_11 -> V_101 ) ;
if ( V_15 < 0 ) {
F_63 ( V_113 L_10 , V_15 ) ;
goto V_114;
}
}
if ( V_11 -> V_116 & V_117 ) {
if ( ! V_11 -> V_118 ) {
F_63 ( V_113 L_11 ) ;
V_15 = - V_19 ;
goto V_114;
}
V_11 -> V_97 = V_117 ;
} else if ( V_11 -> V_116 & V_119 ) {
V_11 -> V_97 = V_119 ;
} else {
V_15 = - V_19 ;
goto V_114;
}
if ( V_11 -> V_95 -> V_120 ) {
V_15 = V_11 -> V_95 -> V_120 ( V_11 ) ;
if ( V_15 ) {
F_63 ( V_113
L_12 , V_15 ) ;
V_11 -> V_97 = V_98 ;
if ( V_11 -> V_95 -> V_99 )
V_11 -> V_95 -> V_99 ( V_11 ) ;
goto V_121;
}
}
if ( V_11 -> V_100 )
F_37 ( V_106 ) ;
else
F_37 ( V_107 ) ;
return V_105 ;
V_121:
V_11 -> V_97 = V_98 ;
V_114:
if ( V_11 -> V_95 -> V_99 )
V_11 -> V_95 -> V_99 ( V_11 ) ;
V_110:
if ( V_103 )
F_54 ( V_103 ) ;
V_11 -> V_101 = V_107 ;
F_37 ( V_106 ) ;
return V_15 ;
}
int F_64 ( struct V_10 * V_11 ,
struct V_1 * V_103 ,
struct V_1 * V_104 )
{
int V_15 ;
if ( V_103 == V_104 )
return 0 ;
F_25 ( & V_11 -> V_122 ) ;
F_25 ( & V_11 -> V_54 ) ;
if ( V_103 && F_1 ( V_103 ) )
V_103 = NULL ;
if ( V_104 && ! F_1 ( V_104 ) )
V_104 = NULL ;
if ( ! V_103 && ! V_104 ) {
V_15 = 0 ;
goto V_123;
}
if ( V_11 -> V_16 == NULL ) {
V_15 = - V_17 ;
goto V_123;
}
V_15 = F_60 ( V_11 , V_103 , V_104 ) ;
V_123:
F_28 ( & V_11 -> V_54 ) ;
F_28 ( & V_11 -> V_122 ) ;
return V_15 ;
}
T_1 F_65 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_52 )
{
int V_15 ;
bool V_124 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
bool V_125 ;
V_15 = F_24 ( V_2 , & V_124 ) ;
if ( V_15 < 0 )
return V_15 ;
F_25 ( & V_11 -> V_54 ) ;
V_125 = F_1 ( V_11 -> V_14 ) ;
if ( V_125 == V_124 )
goto V_126;
if ( V_124 )
V_15 = F_60 ( V_11 ,
V_11 -> V_14 , NULL ) ;
else
V_15 = F_60 ( V_11 ,
NULL , V_11 -> V_14 ) ;
if ( V_15 < 0 )
goto V_126;
V_126:
F_28 ( & V_11 -> V_54 ) ;
return ( V_15 < 0 ) ? V_15 : V_52 ;
}
bool F_66 ( struct V_10 * V_11 ,
const unsigned long * V_89 )
{
return F_67 ( V_89 , V_11 -> V_75 ) == 1 ;
}
static bool F_68 ( struct V_10 * V_11 ,
const unsigned long * V_89 )
{
if ( ! V_11 -> V_95 -> V_127 )
return true ;
return V_11 -> V_95 -> V_127 ( V_11 , V_89 ) ;
}
int F_27 ( struct V_10 * V_11 ,
struct V_1 * V_14 , int V_51 )
{
const unsigned long * V_89 ;
unsigned long * V_128 ;
V_128 = F_69 ( sizeof( * V_128 ) *
F_35 ( V_11 -> V_75 ) ,
V_78 ) ;
if ( V_128 == NULL )
return - V_79 ;
if ( ! V_11 -> V_75 ) {
F_70 ( L_13 ) ;
goto V_129;
}
F_71 ( V_128 , V_14 -> V_50 , V_11 -> V_75 ) ;
F_72 ( V_51 , V_128 ) ;
if ( ! F_68 ( V_11 , V_128 ) )
goto V_129;
if ( V_11 -> V_100 ) {
V_89 = F_44 ( V_11 -> V_100 ,
V_11 -> V_75 ,
V_128 ) ;
if ( ! V_89 )
goto V_129;
}
F_71 ( V_14 -> V_50 , V_128 , V_11 -> V_75 ) ;
F_37 ( V_128 ) ;
return 0 ;
V_129:
F_37 ( V_128 ) ;
return - V_19 ;
}
int F_26 ( struct V_10 * V_11 ,
struct V_1 * V_14 , int V_51 )
{
if ( V_51 > V_11 -> V_75 )
return - V_19 ;
if ( ! V_14 -> V_50 )
return 0 ;
return ! ! F_20 ( V_51 , V_14 -> V_50 ) ;
}
static const void * F_73 ( struct V_1 * V_14 ,
const void * V_130 )
{
struct V_131 * V_132 ;
if ( F_2 ( & V_14 -> V_28 ) )
return V_130 ;
F_36 (t, &buffer->demux_list, l)
memcpy ( V_14 -> V_133 + V_132 -> V_134 ,
V_130 + V_132 -> V_135 , V_132 -> V_93 ) ;
return V_14 -> V_133 ;
}
static int F_74 ( struct V_1 * V_14 , const void * V_136 )
{
const void * V_137 = F_73 ( V_14 , V_136 ) ;
return V_14 -> V_4 -> V_138 ( V_14 , V_137 ) ;
}
static void F_75 ( struct V_1 * V_14 )
{
struct V_131 * V_66 , * V_139 ;
F_58 (p, q, &buffer->demux_list, l) {
F_76 ( & V_66 -> V_140 ) ;
F_37 ( V_66 ) ;
}
}
int F_77 ( struct V_10 * V_11 , const void * V_136 )
{
int V_15 ;
struct V_1 * V_2 ;
F_36 (buf, &indio_dev->buffer_list, buffer_list) {
V_15 = F_74 ( V_2 , V_136 ) ;
if ( V_15 < 0 )
return V_15 ;
}
return 0 ;
}
static int F_78 ( struct V_10 * V_11 ,
struct V_1 * V_14 )
{
const struct V_58 * V_91 ;
int V_15 , V_141 = - 1 , V_142 , V_93 ;
unsigned V_143 = 0 , V_144 = 0 ;
struct V_131 * V_66 ;
F_75 ( V_14 ) ;
F_37 ( V_14 -> V_133 ) ;
V_14 -> V_133 = NULL ;
if ( F_79 ( V_11 -> V_101 ,
V_14 -> V_50 ,
V_11 -> V_75 ) )
return 0 ;
F_48 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_141 = F_80 ( V_11 -> V_101 ,
V_11 -> V_75 ,
V_141 + 1 ) ;
while ( V_141 != V_142 ) {
V_141 = F_80 ( V_11 -> V_101 ,
V_11 -> V_75 ,
V_141 + 1 ) ;
V_91 = F_49 ( V_11 , V_141 ) ;
if ( V_91 -> V_38 . V_43 > 1 )
V_93 = V_91 -> V_38 . V_47 / 8 *
V_91 -> V_38 . V_43 ;
else
V_93 = V_91 -> V_38 . V_47 / 8 ;
V_143 += V_93 ;
if ( V_143 % V_93 )
V_143 += V_93 - V_143 % V_93 ;
}
V_66 = F_69 ( sizeof( * V_66 ) , V_78 ) ;
if ( V_66 == NULL ) {
V_15 = - V_79 ;
goto V_145;
}
V_91 = F_49 ( V_11 , V_141 ) ;
if ( V_91 -> V_38 . V_43 > 1 )
V_93 = V_91 -> V_38 . V_47 / 8 *
V_91 -> V_38 . V_43 ;
else
V_93 = V_91 -> V_38 . V_47 / 8 ;
if ( V_144 % V_93 )
V_144 += V_93 - V_144 % V_93 ;
if ( V_143 % V_93 )
V_143 += V_93 - V_143 % V_93 ;
V_66 -> V_135 = V_143 ;
V_66 -> V_134 = V_144 ;
V_66 -> V_93 = V_93 ;
F_81 ( & V_66 -> V_140 , & V_14 -> V_28 ) ;
V_144 += V_93 ;
V_143 += V_93 ;
}
if ( V_14 -> V_57 ) {
V_66 = F_69 ( sizeof( * V_66 ) , V_78 ) ;
if ( V_66 == NULL ) {
V_15 = - V_79 ;
goto V_145;
}
V_91 = F_49 ( V_11 ,
V_11 -> V_77 ) ;
if ( V_91 -> V_38 . V_43 > 1 )
V_93 = V_91 -> V_38 . V_47 / 8 *
V_91 -> V_38 . V_43 ;
else
V_93 = V_91 -> V_38 . V_47 / 8 ;
if ( V_144 % V_93 )
V_144 += V_93 - V_144 % V_93 ;
if ( V_143 % V_93 )
V_143 += V_93 - V_143 % V_93 ;
V_66 -> V_135 = V_143 ;
V_66 -> V_134 = V_144 ;
V_66 -> V_93 = V_93 ;
F_81 ( & V_66 -> V_140 , & V_14 -> V_28 ) ;
V_144 += V_93 ;
V_143 += V_93 ;
}
V_14 -> V_133 = F_82 ( V_144 , V_78 ) ;
if ( V_14 -> V_133 == NULL ) {
V_15 = - V_79 ;
goto V_145;
}
return 0 ;
V_145:
F_75 ( V_14 ) ;
return V_15 ;
}
int F_62 ( struct V_10 * V_11 )
{
struct V_1 * V_14 ;
int V_15 ;
F_36 (buffer, &indio_dev->buffer_list, buffer_list) {
V_15 = F_78 ( V_11 , V_14 ) ;
if ( V_15 < 0 )
goto V_145;
}
return 0 ;
V_145:
F_36 (buffer, &indio_dev->buffer_list, buffer_list)
F_75 ( V_14 ) ;
return V_15 ;
}
static void F_83 ( struct V_146 * V_29 )
{
struct V_1 * V_14 = F_84 ( V_29 , struct V_1 , V_29 ) ;
V_14 -> V_4 -> V_147 ( V_14 ) ;
}
struct V_1 * F_52 ( struct V_1 * V_14 )
{
if ( V_14 )
F_85 ( & V_14 -> V_29 ) ;
return V_14 ;
}
void F_56 ( struct V_1 * V_14 )
{
if ( V_14 )
F_86 ( & V_14 -> V_29 , F_83 ) ;
}
