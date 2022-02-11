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
if ( V_19 ) {
F_15 ( V_14 , V_19 ) ;
if ( ! F_16 ( V_21 ) )
F_17 ( V_19 , V_38 ) ;
}
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
static V_35
F_22 ( struct V_1 * V_2 V_42 ,
struct V_13 * V_14 V_42 )
{
int V_43 ;
int V_44 = 0 , V_45 = 0 ;
const struct V_20 * V_21 = V_14 -> V_21 ;
if ( ! F_16 ( V_21 ) ) {
for ( V_43 = 0 ; V_43 < F_23 ( V_21 ) ; V_43 ++ ) {
if ( F_24 ( V_2 , V_21 -> V_46 [ V_43 ] ) )
V_45 ++ ;
else
V_44 ++ ;
}
} else {
for ( V_43 = 0 ; V_43 < F_25 () ; V_43 ++ ) {
if ( F_24 ( V_2 , V_43 ) )
V_45 ++ ;
else
V_44 ++ ;
}
}
return ( V_47 +
( V_45 * V_48 ) +
( V_44 * V_49 ) ) ;
}
static bool F_24 ( struct V_1 * V_2 , int V_50 )
{
bool V_51 = false ;
char V_52 [ V_53 ] ;
int V_54 ;
unsigned int V_55 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
snprintf ( V_52 , V_53 , L_9 ,
V_50 , V_56 [ V_57 ] ) ;
V_54 = F_26 ( V_16 , V_52 , L_10 , & V_55 ) ;
if ( V_54 == 1 )
V_51 = true ;
return V_51 ;
}
static int F_27 ( struct V_15 * V_58 , int V_50 , const char * V_52 )
{
char V_59 [ V_53 ] ;
int V_54 ;
unsigned int V_55 = 0 ;
snprintf ( V_59 , V_53 , L_9 , V_50 , V_52 ) ;
V_54 = F_26 ( V_58 , V_59 , L_10 , & V_55 ) ;
if ( V_54 != 1 )
F_8 ( L_11 , V_60 , V_59 ) ;
return V_55 ;
}
static void F_28 ( int V_50 , T_2 * V_61 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
T_2 V_64 ;
T_1 V_65 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
if ( F_24 ( V_2 , V_50 ) ) {
V_65 = V_66 ;
V_63 -> V_67 [ * V_61 + V_68 ] =
F_21 ( V_2 ) ;
V_63 -> V_67 [ * V_61 + V_69 ] =
F_29 ( V_50 ) ;
V_63 -> V_67 [ * V_61 + V_57 ] =
F_27 ( V_16 , V_50 ,
V_56 [ V_57 ] ) ;
V_63 -> V_67 [ * V_61 + V_70 ] =
F_27 ( V_16 , V_50 ,
V_56 [ V_70 ] ) ;
V_63 -> V_67 [ * V_61 + V_71 ] =
F_27 ( V_16 , V_50 ,
V_56 [ V_71 ] ) ;
V_63 -> V_67 [ * V_61 + V_72 ] =
F_27 ( V_16 , V_50 ,
V_56 [ V_72 ] ) ;
V_63 -> V_67 [ * V_61 + V_73 ] =
F_27 ( V_16 , V_50 ,
V_56
[ V_73 ] ) ;
V_64 = V_74 ;
} else {
V_65 = V_75 ;
V_63 -> V_67 [ * V_61 + V_76 ] = F_21 ( V_2 ) ;
V_63 -> V_67 [ * V_61 + V_77 ] =
F_29 ( V_50 ) ;
V_63 -> V_67 [ * V_61 + V_78 ] =
F_27 ( V_16 , V_50 ,
V_79 [ V_78 ] ) ;
V_63 -> V_67 [ * V_61 + V_80 ] =
F_27 ( V_16 , V_50 ,
V_79 [ V_80 ] ) ;
V_64 = V_81 ;
}
V_63 -> V_67 [ * V_61 + V_82 ] = V_65 ;
V_63 -> V_67 [ * V_61 + V_83 ] = V_50 ;
* V_61 += V_64 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
struct V_62 * V_63 ,
V_35 V_86 )
{
int V_43 ;
T_2 V_61 ;
T_1 V_87 , type ;
const struct V_20 * V_21 = V_85 -> V_14 -> V_21 ;
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_15 * V_16 = V_7 -> V_16 ;
if ( V_86 != F_22 ( V_2 , V_85 -> V_14 ) )
return - V_26 ;
if ( ! V_85 -> V_14 -> V_88 )
return - V_26 ;
V_87 = F_16 ( V_21 ) ? F_25 () : F_23 ( V_21 ) ;
type = V_16 -> type ;
V_63 -> type = V_89 ;
V_63 -> V_67 [ V_90 ] = 0 ;
V_63 -> V_67 [ V_91 ] = type << 32 ;
V_63 -> V_67 [ V_91 ] |= V_87 ;
V_63 -> V_67 [ V_92 ] = V_7 -> V_23 ;
V_61 = V_92 + 1 ;
if ( ! F_16 ( V_21 ) ) {
for ( V_43 = 0 ; V_43 < F_23 ( V_21 ) && V_61 < V_86 ; V_43 ++ )
F_28 ( V_21 -> V_46 [ V_43 ] , & V_61 , V_2 , V_63 ) ;
} else {
for ( V_43 = 0 ; V_43 < F_25 () ; V_43 ++ )
F_28 ( V_43 , & V_61 , V_2 , V_63 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 V_42 ,
int V_93 , struct V_94 * V_95 ,
unsigned char * T_3 V_42 ,
T_1 * V_96 , T_1 * V_97 )
{
F_32 ( L_12 ,
V_60 , V_93 , ( V_35 ) * V_97 , ( V_35 ) * V_96 , V_95 -> V_98 ) ;
* V_97 = * V_96 ;
* V_96 += V_95 -> V_98 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_17 * V_18 ;
F_7 (ptr->evlist, evsel) {
if ( V_18 -> V_24 . type == V_7 -> V_16 -> type )
return F_34 ( V_18 ) ;
}
return - V_26 ;
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
static T_1 F_37 ( struct V_1 * V_2 V_42 )
{
return ( ( ( T_1 ) rand () << 0 ) & 0x00000000FFFFFFFFull ) |
( ( ( T_1 ) rand () << 32 ) & 0xFFFFFFFF00000000ull ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
free ( V_7 ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_93 )
{
struct V_6 * V_7 =
F_2 ( V_2 , struct V_6 , V_2 ) ;
struct V_17 * V_18 ;
F_7 (ptr->evlist, evsel) {
if ( V_18 -> V_24 . type == V_7 -> V_16 -> type )
return F_40 ( V_7 -> V_14 ,
V_18 , V_93 ) ;
}
return - V_26 ;
}
struct V_1 * F_41 ( int * V_40 )
{
struct V_15 * V_16 ;
struct V_6 * V_7 ;
V_16 = F_42 ( V_25 ) ;
if ( ! V_16 ) {
* V_40 = - V_26 ;
goto V_99;
}
V_7 = F_43 ( sizeof( struct V_6 ) ) ;
if ( ! V_7 ) {
* V_40 = - V_100 ;
goto V_99;
}
V_7 -> V_16 = V_16 ;
V_7 -> V_2 . V_101 = F_1 ;
V_7 -> V_2 . V_102 = F_4 ;
V_7 -> V_2 . V_103 = F_22 ;
V_7 -> V_2 . V_104 = F_30 ;
V_7 -> V_2 . V_105 = F_31 ;
V_7 -> V_2 . V_106 = F_33 ;
V_7 -> V_2 . V_107 = F_35 ;
V_7 -> V_2 . V_108 = F_37 ;
V_7 -> V_2 . free = F_38 ;
V_7 -> V_2 . V_109 = F_39 ;
* V_40 = 0 ;
return & V_7 -> V_2 ;
V_99:
return NULL ;
}
static T_4 * F_44 ( const char * V_110 )
{
struct V_111 V_112 ;
char V_52 [ V_53 ] ;
const char * V_113 ;
V_113 = F_45 () ;
if ( ! V_113 )
return NULL ;
snprintf ( V_52 , V_53 ,
L_13 V_114 L_13 , V_113 , V_110 ) ;
if ( V_111 ( V_52 , & V_112 ) < 0 )
return NULL ;
return fopen ( V_52 , L_14 ) ;
}
