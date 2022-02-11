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
static const unsigned long * F_21 ( const unsigned long * V_51 ,
unsigned int V_52 ,
const unsigned long * V_53 )
{
if ( F_22 ( V_53 , V_52 ) )
return NULL ;
while ( * V_51 ) {
if ( F_23 ( V_53 , V_51 , V_52 ) )
return V_51 ;
V_51 += F_24 ( V_52 ) ;
}
return NULL ;
}
static bool F_25 ( struct V_10 * V_11 ,
const unsigned long * V_53 )
{
if ( ! V_11 -> V_54 -> V_55 )
return true ;
return V_11 -> V_54 -> V_55 ( V_11 , V_53 ) ;
}
static int F_26 ( struct V_10 * V_11 ,
struct V_1 * V_14 , int V_56 )
{
const unsigned long * V_53 ;
unsigned long * V_57 ;
V_57 = F_27 ( sizeof( * V_57 ) *
F_24 ( V_11 -> V_52 ) ,
V_58 ) ;
if ( V_57 == NULL )
return - V_59 ;
if ( ! V_11 -> V_52 ) {
F_28 ( L_5 ) ;
goto V_60;
}
F_29 ( V_57 , V_14 -> V_50 , V_11 -> V_52 ) ;
F_30 ( V_56 , V_57 ) ;
if ( ! F_25 ( V_11 , V_57 ) )
goto V_60;
if ( V_11 -> V_61 ) {
V_53 = F_21 ( V_11 -> V_61 ,
V_11 -> V_52 ,
V_57 ) ;
if ( ! V_53 )
goto V_60;
}
F_29 ( V_14 -> V_50 , V_57 , V_11 -> V_52 ) ;
F_31 ( V_57 ) ;
return 0 ;
V_60:
F_31 ( V_57 ) ;
return - V_19 ;
}
static int F_32 ( struct V_1 * V_14 , int V_56 )
{
F_33 ( V_56 , V_14 -> V_50 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_62 )
{
int V_15 ;
bool V_63 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
struct V_36 * V_37 = F_15 ( V_33 ) ;
V_15 = F_35 ( V_2 , & V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
F_36 ( & V_11 -> V_64 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_65 ;
goto V_66;
}
V_15 = F_37 ( V_11 , V_14 , V_37 -> V_49 ) ;
if ( V_15 < 0 )
goto V_66;
if ( ! V_63 && V_15 ) {
V_15 = F_32 ( V_14 , V_37 -> V_49 ) ;
if ( V_15 )
goto V_66;
} else if ( V_63 && ! V_15 ) {
V_15 = F_26 ( V_11 , V_14 , V_37 -> V_49 ) ;
if ( V_15 )
goto V_66;
}
V_66:
F_38 ( & V_11 -> V_64 ) ;
return V_15 < 0 ? V_15 : V_62 ;
}
static T_1 F_39 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
return sprintf ( V_2 , L_4 , V_11 -> V_14 -> V_67 ) ;
}
static T_1 F_40 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_62 )
{
int V_15 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
bool V_63 ;
V_15 = F_35 ( V_2 , & V_63 ) ;
if ( V_15 < 0 )
return V_15 ;
F_36 ( & V_11 -> V_64 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_65 ;
goto V_66;
}
V_11 -> V_14 -> V_67 = V_63 ;
V_66:
F_38 ( & V_11 -> V_64 ) ;
return V_15 ? V_15 : V_62 ;
}
static int F_41 ( struct V_10 * V_11 ,
const struct V_68 * V_69 )
{
int V_15 , V_70 = 0 ;
struct V_1 * V_14 = V_11 -> V_14 ;
V_15 = F_42 ( L_6 ,
V_69 ,
& F_14 ,
NULL ,
0 ,
V_71 ,
& V_11 -> V_31 ,
& V_14 -> V_72 ) ;
if ( V_15 )
return V_15 ;
V_70 ++ ;
V_15 = F_42 ( L_7 ,
V_69 ,
& F_16 ,
NULL ,
0 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_72 ) ;
if ( V_15 )
return V_15 ;
V_70 ++ ;
if ( V_69 -> type != V_73 )
V_15 = F_42 ( L_8 ,
V_69 ,
& F_18 ,
& F_34 ,
V_69 -> V_35 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_72 ) ;
else
V_15 = F_42 ( L_8 ,
V_69 ,
& F_39 ,
& F_40 ,
V_69 -> V_35 ,
0 ,
& V_11 -> V_31 ,
& V_14 -> V_72 ) ;
if ( V_15 )
return V_15 ;
V_70 ++ ;
V_15 = V_70 ;
return V_15 ;
}
static T_1 F_43 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
return sprintf ( V_2 , L_4 , V_14 -> V_74 ) ;
}
static T_1 F_44 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 , T_3 V_62 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
struct V_1 * V_14 = V_11 -> V_14 ;
unsigned int V_75 ;
int V_15 ;
V_15 = F_45 ( V_2 , 10 , & V_75 ) ;
if ( V_15 )
return V_15 ;
if ( V_75 == V_14 -> V_74 )
return V_62 ;
F_36 ( & V_11 -> V_64 ) ;
if ( F_1 ( V_11 -> V_14 ) ) {
V_15 = - V_65 ;
} else {
V_14 -> V_4 -> V_76 ( V_14 , V_75 ) ;
V_15 = 0 ;
}
F_38 ( & V_11 -> V_64 ) ;
return V_15 ? V_15 : V_62 ;
}
static T_1 F_46 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
char * V_2 )
{
struct V_10 * V_11 = F_19 ( V_31 ) ;
return sprintf ( V_2 , L_4 , F_1 ( V_11 -> V_14 ) ) ;
}
static int F_47 ( struct V_10 * V_11 ,
const unsigned long * V_53 , bool V_77 )
{
const struct V_68 * V_78 ;
unsigned V_79 = 0 ;
int V_74 , V_80 ;
F_48 (i, mask,
indio_dev->masklength) {
V_78 = F_49 ( V_11 , V_80 ) ;
if ( V_78 -> V_38 . V_43 > 1 )
V_74 = V_78 -> V_38 . V_47 / 8 *
V_78 -> V_38 . V_43 ;
else
V_74 = V_78 -> V_38 . V_47 / 8 ;
V_79 = F_50 ( V_79 , V_74 ) ;
V_79 += V_74 ;
}
if ( V_77 ) {
V_78 = F_49 ( V_11 ,
V_11 -> V_81 ) ;
if ( V_78 -> V_38 . V_43 > 1 )
V_74 = V_78 -> V_38 . V_47 / 8 *
V_78 -> V_38 . V_43 ;
else
V_74 = V_78 -> V_38 . V_47 / 8 ;
V_79 = F_50 ( V_79 , V_74 ) ;
V_79 += V_74 ;
}
return V_79 ;
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
struct V_1 * V_14 , * V_82 ;
if ( F_2 ( & V_11 -> V_3 ) )
return;
if ( V_11 -> V_54 -> V_83 )
V_11 -> V_54 -> V_83 ( V_11 ) ;
F_58 (buffer, _buffer,
&indio_dev->buffer_list, buffer_list)
F_54 ( V_14 ) ;
V_11 -> V_84 = V_85 ;
if ( V_11 -> V_54 -> V_86 )
V_11 -> V_54 -> V_86 ( V_11 ) ;
if ( V_11 -> V_61 == NULL )
F_31 ( V_11 -> V_87 ) ;
}
static void F_59 ( struct V_10 * V_11 ,
struct V_1 * V_14 )
{
unsigned int V_79 ;
if ( ! V_14 -> V_4 -> V_88 )
return;
V_79 = F_47 ( V_11 , V_14 -> V_50 ,
V_14 -> V_67 ) ;
V_14 -> V_4 -> V_88 ( V_14 , V_79 ) ;
}
static int F_60 ( struct V_10 * V_11 ,
struct V_1 * V_89 ,
struct V_1 * V_90 )
{
int V_15 ;
int V_91 = 0 ;
struct V_1 * V_14 ;
unsigned long * V_92 ;
const unsigned long * V_93 ;
if ( ! F_2 ( & V_11 -> V_3 ) ) {
if ( V_11 -> V_54 -> V_83 ) {
V_15 = V_11 -> V_54 -> V_83 ( V_11 ) ;
if ( V_15 )
return V_15 ;
}
V_11 -> V_84 = V_85 ;
if ( V_11 -> V_54 -> V_86 ) {
V_15 = V_11 -> V_54 -> V_86 ( V_11 ) ;
if ( V_15 )
return V_15 ;
}
}
V_93 = V_11 -> V_87 ;
if ( ! V_11 -> V_61 )
V_11 -> V_87 = NULL ;
if ( V_90 )
F_54 ( V_90 ) ;
if ( V_89 )
F_51 ( V_11 , V_89 ) ;
if ( F_2 ( & V_11 -> V_3 ) ) {
V_11 -> V_84 = V_85 ;
if ( V_11 -> V_61 == NULL )
F_31 ( V_93 ) ;
return 0 ;
}
V_92 = F_61 ( F_24 ( V_11 -> V_52 ) ,
sizeof( long ) , V_58 ) ;
if ( V_92 == NULL ) {
if ( V_11 -> V_61 == NULL )
F_31 ( V_93 ) ;
return - V_59 ;
}
V_11 -> V_67 = 0 ;
F_62 (buffer, &indio_dev->buffer_list, buffer_list) {
F_63 ( V_92 , V_92 , V_14 -> V_50 ,
V_11 -> V_52 ) ;
V_11 -> V_67 |= V_14 -> V_67 ;
}
if ( V_11 -> V_61 ) {
V_11 -> V_87 =
F_21 ( V_11 -> V_61 ,
V_11 -> V_52 ,
V_92 ) ;
if ( V_11 -> V_87 == NULL ) {
F_54 ( V_89 ) ;
if ( V_93 ) {
V_11 -> V_87 = V_93 ;
V_91 = - V_19 ;
}
else {
F_31 ( V_92 ) ;
V_15 = - V_19 ;
return V_15 ;
}
}
} else {
V_11 -> V_87 = V_92 ;
}
F_64 ( V_11 ) ;
if ( V_11 -> V_54 -> V_94 ) {
V_15 = V_11 -> V_54 -> V_94 ( V_11 ) ;
if ( V_15 ) {
F_65 ( V_95
L_9 , V_15 ) ;
goto V_96;
}
}
V_11 -> V_97 =
F_47 ( V_11 ,
V_11 -> V_87 ,
V_11 -> V_67 ) ;
F_62 (buffer, &indio_dev->buffer_list, buffer_list) {
F_59 ( V_11 , V_14 ) ;
if ( V_14 -> V_4 -> V_98 ) {
V_15 = V_14 -> V_4 -> V_98 ( V_14 ) ;
if ( V_15 ) {
F_65 ( V_99
L_10 , V_15 ) ;
goto V_100;
}
}
}
if ( V_11 -> V_16 -> V_101 ) {
V_15 = V_11 -> V_16
-> V_101 ( V_11 ,
V_11 -> V_87 ) ;
if ( V_15 < 0 ) {
F_65 ( V_99 L_11 , V_15 ) ;
goto V_100;
}
}
if ( V_11 -> V_102 & V_103 ) {
if ( ! V_11 -> V_104 ) {
F_65 ( V_99 L_12 ) ;
V_15 = - V_19 ;
goto V_100;
}
V_11 -> V_84 = V_103 ;
} else if ( V_11 -> V_102 & V_105 ) {
V_11 -> V_84 = V_105 ;
} else if ( V_11 -> V_102 & V_106 ) {
V_11 -> V_84 = V_106 ;
} else {
V_15 = - V_19 ;
goto V_100;
}
if ( V_11 -> V_54 -> V_107 ) {
V_15 = V_11 -> V_54 -> V_107 ( V_11 ) ;
if ( V_15 ) {
F_65 ( V_99
L_13 , V_15 ) ;
V_11 -> V_84 = V_85 ;
if ( V_11 -> V_54 -> V_86 )
V_11 -> V_54 -> V_86 ( V_11 ) ;
goto V_108;
}
}
if ( V_11 -> V_61 )
F_31 ( V_92 ) ;
else
F_31 ( V_93 ) ;
return V_91 ;
V_108:
V_11 -> V_84 = V_85 ;
V_100:
if ( V_11 -> V_54 -> V_86 )
V_11 -> V_54 -> V_86 ( V_11 ) ;
V_96:
if ( V_89 )
F_54 ( V_89 ) ;
V_11 -> V_87 = V_93 ;
F_31 ( V_92 ) ;
return V_15 ;
}
int F_66 ( struct V_10 * V_11 ,
struct V_1 * V_89 ,
struct V_1 * V_90 )
{
int V_15 ;
if ( V_89 == V_90 )
return 0 ;
F_36 ( & V_11 -> V_109 ) ;
F_36 ( & V_11 -> V_64 ) ;
if ( V_89 && F_1 ( V_89 ) )
V_89 = NULL ;
if ( V_90 && ! F_1 ( V_90 ) )
V_90 = NULL ;
if ( ! V_89 && ! V_90 ) {
V_15 = 0 ;
goto V_110;
}
if ( V_11 -> V_16 == NULL ) {
V_15 = - V_17 ;
goto V_110;
}
V_15 = F_60 ( V_11 , V_89 , V_90 ) ;
V_110:
F_38 ( & V_11 -> V_64 ) ;
F_38 ( & V_11 -> V_109 ) ;
return V_15 ;
}
static T_1 F_67 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
const char * V_2 ,
T_3 V_62 )
{
int V_15 ;
bool V_111 ;
struct V_10 * V_11 = F_19 ( V_31 ) ;
bool V_112 ;
V_15 = F_35 ( V_2 , & V_111 ) ;
if ( V_15 < 0 )
return V_15 ;
F_36 ( & V_11 -> V_64 ) ;
V_112 = F_1 ( V_11 -> V_14 ) ;
if ( V_112 == V_111 )
goto V_113;
if ( V_111 )
V_15 = F_60 ( V_11 ,
V_11 -> V_14 , NULL ) ;
else
V_15 = F_60 ( V_11 ,
NULL , V_11 -> V_14 ) ;
if ( V_15 < 0 )
goto V_113;
V_113:
F_38 ( & V_11 -> V_64 ) ;
return ( V_15 < 0 ) ? V_15 : V_62 ;
}
int F_68 ( struct V_10 * V_11 )
{
struct V_36 * V_114 ;
struct V_115 * * V_33 ;
struct V_1 * V_14 = V_11 -> V_14 ;
int V_15 , V_80 , V_116 , V_70 , V_117 = 0 ;
const struct V_68 * V_118 ;
if ( ! V_14 )
return 0 ;
V_70 = 0 ;
if ( V_14 -> V_119 ) {
while ( V_14 -> V_119 [ V_70 ] != NULL )
V_70 ++ ;
}
V_14 -> V_120 . V_121 = L_14 ;
V_14 -> V_120 . V_119 = F_61 ( V_70 + 3 ,
sizeof( * V_14 -> V_120 . V_119 ) , V_58 ) ;
if ( ! V_14 -> V_120 . V_119 )
return - V_59 ;
if ( V_14 -> V_4 -> V_76 )
V_14 -> V_120 . V_119 [ 0 ] = & V_122 . V_33 ;
else
V_14 -> V_120 . V_119 [ 0 ] = & V_123 . V_33 ;
V_14 -> V_120 . V_119 [ 1 ] = & V_124 . V_33 ;
if ( V_14 -> V_119 )
memcpy ( & V_14 -> V_120 . V_119 [ 2 ] , V_14 -> V_119 ,
sizeof( * & V_14 -> V_120 . V_119 ) * V_70 ) ;
V_14 -> V_120 . V_119 [ V_70 + 2 ] = NULL ;
V_11 -> V_125 [ V_11 -> V_126 ++ ] = & V_14 -> V_120 ;
if ( V_14 -> V_127 != NULL ) {
V_33 = V_14 -> V_127 -> V_119 ;
while ( * V_33 ++ != NULL )
V_117 ++ ;
}
V_70 = V_117 ;
F_11 ( & V_14 -> V_72 ) ;
V_118 = V_11 -> V_118 ;
if ( V_118 ) {
for ( V_80 = 0 ; V_80 < V_11 -> V_128 ; V_80 ++ ) {
if ( V_118 [ V_80 ] . V_35 < 0 )
continue;
if ( V_118 [ V_80 ] . V_35 >
( int ) V_11 -> V_52 - 1 )
V_11 -> V_52
= V_118 [ V_80 ] . V_35 + 1 ;
V_15 = F_41 ( V_11 ,
& V_118 [ V_80 ] ) ;
if ( V_15 < 0 )
goto V_129;
V_70 += V_15 ;
if ( V_118 [ V_80 ] . type == V_73 )
V_11 -> V_81 =
V_118 [ V_80 ] . V_35 ;
}
if ( V_11 -> V_52 && V_14 -> V_50 == NULL ) {
V_14 -> V_50 = F_61 ( F_24 ( V_11 -> V_52 ) ,
sizeof( * V_14 -> V_50 ) ,
V_58 ) ;
if ( V_14 -> V_50 == NULL ) {
V_15 = - V_59 ;
goto V_129;
}
}
}
V_14 -> V_130 . V_121 = V_131 ;
V_14 -> V_130 . V_119 = F_61 ( V_70 + 1 ,
sizeof( V_14 -> V_130 . V_119 [ 0 ] ) ,
V_58 ) ;
if ( V_14 -> V_130 . V_119 == NULL ) {
V_15 = - V_59 ;
goto V_132;
}
if ( V_14 -> V_127 )
memcpy ( V_14 -> V_130 . V_119 , V_14 -> V_127 ,
sizeof( V_14 -> V_130 . V_119 [ 0 ] ) * V_117 ) ;
V_116 = V_117 ;
F_62 (p, &buffer->scan_el_dev_attr_list, l)
V_14 -> V_130 . V_119 [ V_116 ++ ] = & V_114 -> V_133 . V_33 ;
V_11 -> V_125 [ V_11 -> V_126 ++ ] = & V_14 -> V_130 ;
return 0 ;
V_132:
F_31 ( V_14 -> V_50 ) ;
V_129:
F_69 ( & V_14 -> V_72 ) ;
F_31 ( V_11 -> V_14 -> V_120 . V_119 ) ;
return V_15 ;
}
void F_70 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_14 )
return;
F_31 ( V_11 -> V_14 -> V_50 ) ;
F_31 ( V_11 -> V_14 -> V_120 . V_119 ) ;
F_31 ( V_11 -> V_14 -> V_130 . V_119 ) ;
F_69 ( & V_11 -> V_14 -> V_72 ) ;
}
bool F_71 ( struct V_10 * V_11 ,
const unsigned long * V_53 )
{
return F_72 ( V_53 , V_11 -> V_52 ) == 1 ;
}
int F_37 ( struct V_10 * V_11 ,
struct V_1 * V_14 , int V_56 )
{
if ( V_56 > V_11 -> V_52 )
return - V_19 ;
if ( ! V_14 -> V_50 )
return 0 ;
return ! ! F_20 ( V_56 , V_14 -> V_50 ) ;
}
static const void * F_73 ( struct V_1 * V_14 ,
const void * V_134 )
{
struct V_135 * V_136 ;
if ( F_2 ( & V_14 -> V_28 ) )
return V_134 ;
F_62 (t, &buffer->demux_list, l)
memcpy ( V_14 -> V_137 + V_136 -> V_138 ,
V_134 + V_136 -> V_139 , V_136 -> V_74 ) ;
return V_14 -> V_137 ;
}
static int F_74 ( struct V_1 * V_14 , const void * V_140 )
{
const void * V_141 = F_73 ( V_14 , V_140 ) ;
return V_14 -> V_4 -> V_142 ( V_14 , V_141 ) ;
}
static void F_75 ( struct V_1 * V_14 )
{
struct V_135 * V_114 , * V_143 ;
F_58 (p, q, &buffer->demux_list, l) {
F_76 ( & V_114 -> V_144 ) ;
F_31 ( V_114 ) ;
}
}
int F_77 ( struct V_10 * V_11 , const void * V_140 )
{
int V_15 ;
struct V_1 * V_2 ;
F_62 (buf, &indio_dev->buffer_list, buffer_list) {
V_15 = F_74 ( V_2 , V_140 ) ;
if ( V_15 < 0 )
return V_15 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_14 ,
struct V_135 * * V_114 , unsigned int V_145 , unsigned int V_146 ,
unsigned int V_74 )
{
if ( * V_114 && ( * V_114 ) -> V_139 + ( * V_114 ) -> V_74 == V_145 &&
( * V_114 ) -> V_138 + ( * V_114 ) -> V_74 == V_146 ) {
( * V_114 ) -> V_74 += V_74 ;
} else {
* V_114 = F_27 ( sizeof( * * V_114 ) , V_58 ) ;
if ( * V_114 == NULL )
return - V_59 ;
( * V_114 ) -> V_139 = V_145 ;
( * V_114 ) -> V_138 = V_146 ;
( * V_114 ) -> V_74 = V_74 ;
F_79 ( & ( * V_114 ) -> V_144 , & V_14 -> V_28 ) ;
}
return 0 ;
}
static int F_80 ( struct V_10 * V_11 ,
struct V_1 * V_14 )
{
const struct V_68 * V_78 ;
int V_15 , V_147 = - 1 , V_148 , V_74 ;
unsigned V_145 = 0 , V_146 = 0 ;
struct V_135 * V_114 = NULL ;
F_75 ( V_14 ) ;
F_31 ( V_14 -> V_137 ) ;
V_14 -> V_137 = NULL ;
if ( F_81 ( V_11 -> V_87 ,
V_14 -> V_50 ,
V_11 -> V_52 ) )
return 0 ;
F_48 (out_ind,
buffer->scan_mask,
indio_dev->masklength) {
V_147 = F_82 ( V_11 -> V_87 ,
V_11 -> V_52 ,
V_147 + 1 ) ;
while ( V_147 != V_148 ) {
V_147 = F_82 ( V_11 -> V_87 ,
V_11 -> V_52 ,
V_147 + 1 ) ;
V_78 = F_49 ( V_11 , V_147 ) ;
if ( V_78 -> V_38 . V_43 > 1 )
V_74 = V_78 -> V_38 . V_47 / 8 *
V_78 -> V_38 . V_43 ;
else
V_74 = V_78 -> V_38 . V_47 / 8 ;
V_145 = F_83 ( V_145 , V_74 ) + V_74 ;
}
V_78 = F_49 ( V_11 , V_147 ) ;
if ( V_78 -> V_38 . V_43 > 1 )
V_74 = V_78 -> V_38 . V_47 / 8 *
V_78 -> V_38 . V_43 ;
else
V_74 = V_78 -> V_38 . V_47 / 8 ;
V_146 = F_83 ( V_146 , V_74 ) ;
V_145 = F_83 ( V_145 , V_74 ) ;
V_15 = F_78 ( V_14 , & V_114 , V_145 , V_146 , V_74 ) ;
if ( V_15 )
goto V_149;
V_146 += V_74 ;
V_145 += V_74 ;
}
if ( V_14 -> V_67 ) {
V_78 = F_49 ( V_11 ,
V_11 -> V_81 ) ;
if ( V_78 -> V_38 . V_43 > 1 )
V_74 = V_78 -> V_38 . V_47 / 8 *
V_78 -> V_38 . V_43 ;
else
V_74 = V_78 -> V_38 . V_47 / 8 ;
V_146 = F_83 ( V_146 , V_74 ) ;
V_145 = F_83 ( V_145 , V_74 ) ;
V_15 = F_78 ( V_14 , & V_114 , V_145 , V_146 , V_74 ) ;
if ( V_15 )
goto V_149;
V_146 += V_74 ;
V_145 += V_74 ;
}
V_14 -> V_137 = F_84 ( V_146 , V_58 ) ;
if ( V_14 -> V_137 == NULL ) {
V_15 = - V_59 ;
goto V_149;
}
return 0 ;
V_149:
F_75 ( V_14 ) ;
return V_15 ;
}
int F_64 ( struct V_10 * V_11 )
{
struct V_1 * V_14 ;
int V_15 ;
F_62 (buffer, &indio_dev->buffer_list, buffer_list) {
V_15 = F_80 ( V_11 , V_14 ) ;
if ( V_15 < 0 )
goto V_149;
}
return 0 ;
V_149:
F_62 (buffer, &indio_dev->buffer_list, buffer_list)
F_75 ( V_14 ) ;
return V_15 ;
}
static void F_85 ( struct V_150 * V_29 )
{
struct V_1 * V_14 = F_86 ( V_29 , struct V_1 , V_29 ) ;
V_14 -> V_4 -> V_151 ( V_14 ) ;
}
struct V_1 * F_52 ( struct V_1 * V_14 )
{
if ( V_14 )
F_87 ( & V_14 -> V_29 ) ;
return V_14 ;
}
void F_56 ( struct V_1 * V_14 )
{
if ( V_14 )
F_88 ( & V_14 -> V_29 , F_85 ) ;
}
