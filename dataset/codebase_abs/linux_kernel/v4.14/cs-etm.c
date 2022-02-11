static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
unsigned long long V_8 = 0 ;
char * V_9 ;
if ( V_5 ) {
V_8 = F_3 ( V_5 , & V_9 , 0 ) ;
if ( * V_9 || V_8 > V_10 )
return - 1 ;
}
V_4 -> V_11 = true ;
V_4 -> V_12 = V_8 ;
V_7 -> V_8 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_17 * V_18 , * V_19 = NULL ;
const struct V_20 * V_21 = V_14 -> V_21 ;
bool V_22 = ( F_5 () == 0 || F_6 () < 0 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_23 = V_4 -> V_11 ;
F_7 (evlist, evsel) {
if ( V_18 -> V_24 . type == V_16 -> type ) {
if ( V_19 ) {
F_8 ( L_1 ,
V_25 ) ;
return - V_26 ;
}
V_18 -> V_24 . V_27 = 0 ;
V_18 -> V_24 . V_28 = 1 ;
V_19 = V_18 ;
V_4 -> V_29 = true ;
}
}
if ( ! V_19 )
return 0 ;
if ( V_4 -> V_30 ) {
F_8 ( L_2 ,
V_25 ) ;
return - V_26 ;
}
if ( V_4 -> V_11 ) {
if ( ! V_4 -> V_12 &&
! V_4 -> V_31 ) {
if ( V_22 ) {
V_4 -> V_31 = F_9 ( 4 ) / V_32 ;
} else {
V_4 -> V_31 =
F_10 ( 128 ) / V_32 ;
if ( V_4 -> V_33 == V_34 )
V_4 -> V_33 = F_10 ( 256 ) / V_32 ;
}
} else if ( ! V_4 -> V_31 && ! V_22 &&
V_4 -> V_33 == V_34 ) {
V_4 -> V_33 = F_10 ( 256 ) / V_32 ;
}
if ( ! V_4 -> V_12 ) {
V_4 -> V_12 =
V_4 -> V_31 * ( V_35 ) V_32 ;
}
if ( ! V_4 -> V_31 ) {
V_35 V_36 = V_4 -> V_12 ;
V_36 = F_11 ( V_36 , V_32 ) / V_32 ;
V_4 -> V_31 = F_12 ( V_36 ) ;
}
if ( V_4 -> V_12 >
V_4 -> V_31 * ( V_35 ) V_32 ) {
F_8 ( L_3 ,
V_4 -> V_12 ,
V_4 -> V_31 * ( V_35 ) V_32 ) ;
return - V_26 ;
}
if ( ! V_4 -> V_12 ||
! V_4 -> V_31 ) {
F_8 ( L_4 ) ;
return - V_26 ;
}
}
if ( V_4 -> V_29 && ! V_4 -> V_31 ) {
if ( V_22 ) {
V_4 -> V_31 = F_9 ( 4 ) / V_32 ;
} else {
V_4 -> V_31 = F_10 ( 128 ) / V_32 ;
if ( V_4 -> V_33 == V_34 )
V_4 -> V_33 = F_10 ( 256 ) / V_32 ;
}
}
if ( V_4 -> V_31 ) {
unsigned int V_37 = ( F_10 ( 128 ) / V_32 ) ;
V_35 V_36 = V_4 -> V_31 * ( V_35 ) V_32 ;
if ( ! V_22 &&
V_4 -> V_31 > V_37 ) {
V_4 -> V_31 = V_37 ;
F_8 ( L_5 ,
V_37 ) ;
}
if ( ! F_13 ( V_36 ) ) {
F_8 ( L_6 ,
V_25 ) ;
return - V_26 ;
}
}
if ( V_4 -> V_11 )
F_14 ( L_7 , V_25 ,
V_4 -> V_12 ) ;
F_15 ( V_14 , V_19 ) ;
if ( ! F_16 ( V_21 ) )
F_17 ( V_19 , V_38 ) ;
if ( V_4 -> V_29 ) {
struct V_17 * V_39 ;
int V_40 ;
V_40 = F_18 ( V_14 , L_8 , NULL ) ;
if ( V_40 )
return V_40 ;
V_39 = F_19 ( V_14 ) ;
F_20 ( V_14 , V_39 ) ;
V_39 -> V_24 . V_27 = 0 ;
V_39 -> V_24 . V_28 = 1 ;
if ( ! F_16 ( V_21 ) )
F_17 ( V_39 , TIME ) ;
}
return 0 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
T_1 V_41 = 0 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_17 * V_18 ;
F_7 (evlist, evsel) {
if ( V_18 -> V_24 . type == V_16 -> type ) {
V_41 = V_18 -> V_24 . V_41 ;
break;
}
}
return V_41 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
T_1 V_41 = 0 ;
T_1 V_42 = 0 ;
V_42 = F_21 ( V_2 ) ;
if ( V_42 & F_23 ( V_43 ) )
V_41 |= F_23 ( V_44 ) ;
if ( V_42 & F_23 ( V_45 ) )
V_41 |= F_23 ( V_46 ) ;
if ( V_42 & F_23 ( V_47 ) )
V_41 |= F_23 ( V_48 ) ;
return V_41 ;
}
static V_35
F_24 ( struct V_1 * V_2 V_49 ,
struct V_13 * V_14 V_49 )
{
int V_50 ;
int V_51 = 0 , V_52 = 0 ;
const struct V_20 * V_21 = V_14 -> V_21 ;
if ( ! F_16 ( V_21 ) ) {
for ( V_50 = 0 ; V_50 < F_25 ( V_21 ) ; V_50 ++ ) {
if ( F_26 ( V_2 , V_21 -> V_53 [ V_50 ] ) )
V_52 ++ ;
else
V_51 ++ ;
}
} else {
for ( V_50 = 0 ; V_50 < F_27 () ; V_50 ++ ) {
if ( F_26 ( V_2 , V_50 ) )
V_52 ++ ;
else
V_51 ++ ;
}
}
return ( V_54 +
( V_52 * V_55 ) +
( V_51 * V_56 ) ) ;
}
static bool F_26 ( struct V_1 * V_2 , int V_57 )
{
bool V_58 = false ;
char V_59 [ V_60 ] ;
int V_61 ;
unsigned int V_62 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
snprintf ( V_59 , V_60 , L_9 ,
V_57 , V_63 [ V_64 ] ) ;
V_61 = F_28 ( V_16 , V_59 , L_10 , & V_62 ) ;
if ( V_61 == 1 )
V_58 = true ;
return V_58 ;
}
static int F_29 ( struct V_15 * V_65 , int V_57 , const char * V_59 )
{
char V_66 [ V_60 ] ;
int V_61 ;
unsigned int V_62 = 0 ;
snprintf ( V_66 , V_60 , L_9 , V_57 , V_59 ) ;
V_61 = F_28 ( V_65 , V_66 , L_10 , & V_62 ) ;
if ( V_61 != 1 )
F_8 ( L_11 , V_67 , V_66 ) ;
return V_62 ;
}
static void F_30 ( int V_57 , T_2 * V_68 ,
struct V_1 * V_2 ,
struct V_69 * V_70 )
{
T_2 V_71 ;
T_1 V_72 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
if ( F_26 ( V_2 , V_57 ) ) {
V_72 = V_73 ;
V_70 -> V_74 [ * V_68 + V_75 ] =
F_22 ( V_2 ) ;
V_70 -> V_74 [ * V_68 + V_76 ] =
F_31 ( V_57 ) ;
V_70 -> V_74 [ * V_68 + V_64 ] =
F_29 ( V_16 , V_57 ,
V_63 [ V_64 ] ) ;
V_70 -> V_74 [ * V_68 + V_77 ] =
F_29 ( V_16 , V_57 ,
V_63 [ V_77 ] ) ;
V_70 -> V_74 [ * V_68 + V_78 ] =
F_29 ( V_16 , V_57 ,
V_63 [ V_78 ] ) ;
V_70 -> V_74 [ * V_68 + V_79 ] =
F_29 ( V_16 , V_57 ,
V_63 [ V_79 ] ) ;
V_70 -> V_74 [ * V_68 + V_80 ] =
F_29 ( V_16 , V_57 ,
V_63
[ V_80 ] ) ;
V_71 = V_81 ;
} else {
V_72 = V_82 ;
V_70 -> V_74 [ * V_68 + V_83 ] = F_21 ( V_2 ) ;
V_70 -> V_74 [ * V_68 + V_84 ] =
F_31 ( V_57 ) ;
V_70 -> V_74 [ * V_68 + V_85 ] =
F_29 ( V_16 , V_57 ,
V_86 [ V_85 ] ) ;
V_70 -> V_74 [ * V_68 + V_87 ] =
F_29 ( V_16 , V_57 ,
V_86 [ V_87 ] ) ;
V_71 = V_88 ;
}
V_70 -> V_74 [ * V_68 + V_89 ] = V_72 ;
V_70 -> V_74 [ * V_68 + V_90 ] = V_57 ;
* V_68 += V_71 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_69 * V_70 ,
V_35 V_93 )
{
int V_50 ;
T_2 V_68 ;
T_1 V_94 , type ;
const struct V_20 * V_21 = V_92 -> V_14 -> V_21 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
if ( V_93 != F_24 ( V_2 , V_92 -> V_14 ) )
return - V_26 ;
if ( ! V_92 -> V_14 -> V_95 )
return - V_26 ;
V_94 = F_16 ( V_21 ) ? F_27 () : F_25 ( V_21 ) ;
type = V_16 -> type ;
V_70 -> type = V_96 ;
V_70 -> V_74 [ V_97 ] = 0 ;
V_70 -> V_74 [ V_98 ] = type << 32 ;
V_70 -> V_74 [ V_98 ] |= V_94 ;
V_70 -> V_74 [ V_99 ] = V_7 -> V_23 ;
V_68 = V_99 + 1 ;
if ( ! F_16 ( V_21 ) ) {
for ( V_50 = 0 ; V_50 < F_25 ( V_21 ) && V_68 < V_93 ; V_50 ++ )
F_30 ( V_21 -> V_53 [ V_50 ] , & V_68 , V_2 , V_70 ) ;
} else {
for ( V_50 = 0 ; V_50 < F_27 () ; V_50 ++ )
F_30 ( V_50 , & V_68 , V_2 , V_70 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 V_49 ,
int V_100 , struct V_101 * V_102 ,
unsigned char * T_3 V_49 ,
T_1 * V_103 , T_1 * V_104 )
{
F_34 ( L_12 ,
V_67 , V_100 , ( V_35 ) * V_104 , ( V_35 ) * V_103 , V_102 -> V_105 ) ;
* V_104 = * V_103 ;
* V_103 += V_102 -> V_105 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_17 * V_18 ;
F_7 (ptr->evlist, evsel) {
if ( V_18 -> V_24 . type == V_7 -> V_16 -> type )
return F_36 ( V_18 ) ;
}
return - V_26 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_17 * V_18 ;
F_7 (ptr->evlist, evsel) {
if ( V_18 -> V_24 . type == V_7 -> V_16 -> type )
return F_38 ( V_18 ) ;
}
return - V_26 ;
}
static T_1 F_39 ( struct V_1 * V_2 V_49 )
{
return ( ( ( T_1 ) rand () << 0 ) & 0x00000000FFFFFFFFull ) |
( ( ( T_1 ) rand () << 32 ) & 0xFFFFFFFF00000000ull ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
free ( V_7 ) ;
}
static int F_41 ( struct V_1 * V_2 , int V_100 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_17 * V_18 ;
F_7 (ptr->evlist, evsel) {
if ( V_18 -> V_24 . type == V_7 -> V_16 -> type )
return F_42 ( V_7 -> V_14 ,
V_18 , V_100 ) ;
}
return - V_26 ;
}
struct V_1 * F_43 ( int * V_40 )
{
struct V_15 * V_16 ;
struct V_6 * V_7 ;
V_16 = F_44 ( V_25 ) ;
if ( ! V_16 ) {
* V_40 = - V_26 ;
goto V_106;
}
V_7 = F_45 ( sizeof( struct V_6 ) ) ;
if ( ! V_7 ) {
* V_40 = - V_107 ;
goto V_106;
}
V_7 -> V_16 = V_16 ;
V_7 -> V_2 . V_108 = F_1 ;
V_7 -> V_2 . V_109 = F_4 ;
V_7 -> V_2 . V_110 = F_24 ;
V_7 -> V_2 . V_111 = F_32 ;
V_7 -> V_2 . V_112 = F_33 ;
V_7 -> V_2 . V_113 = F_35 ;
V_7 -> V_2 . V_114 = F_37 ;
V_7 -> V_2 . V_115 = F_39 ;
V_7 -> V_2 . free = F_40 ;
V_7 -> V_2 . V_116 = F_41 ;
* V_40 = 0 ;
return & V_7 -> V_2 ;
V_106:
return NULL ;
}
static T_4 * F_46 ( const char * V_117 )
{
struct V_118 V_119 ;
char V_59 [ V_60 ] ;
const char * V_120 ;
V_120 = F_47 () ;
if ( ! V_120 )
return NULL ;
snprintf ( V_59 , V_60 ,
L_13 V_121 L_13 , V_120 , V_117 ) ;
if ( V_118 ( V_59 , & V_119 ) < 0 )
return NULL ;
return fopen ( V_59 , L_14 ) ;
}
int F_48 ( struct V_122 * V_123 )
{
int V_58 ;
char V_124 [ V_125 ] ;
snprintf ( V_124 , V_125 , L_15 ,
V_123 -> V_62 . V_126 , L_16 ) ;
V_58 = F_49 ( V_124 , L_17 , 1 ) ;
if ( V_58 < 0 )
return V_58 ;
return 0 ;
}
