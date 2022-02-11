static T_1 F_1 ( struct V_1 * T_2 V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_1 * T_2 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 ;
struct V_15 V_16 = { . V_17 = 0 , } ;
bool V_18 = false ;
int V_19 ;
if ( V_8 != V_3 )
return - V_20 ;
if ( ! V_5 -> V_21 -> V_22 )
return - V_20 ;
V_14 = V_5 -> V_21 -> V_23 [ 0 ] . V_24 ;
if ( V_14 ) {
V_19 = F_4 ( V_14 , & V_16 ) ;
if ( V_19 ) {
if ( V_19 != - V_25 )
return V_19 ;
} else {
V_18 = V_16 . V_17 != 0 ;
}
if ( ! V_18 )
F_5 ( L_1 ) ;
}
V_7 -> type = V_26 ;
V_7 -> V_27 [ V_28 ] = V_12 -> type ;
V_7 -> V_27 [ V_29 ] = V_16 . V_30 ;
V_7 -> V_27 [ V_31 ] = V_16 . V_17 ;
V_7 -> V_27 [ V_32 ] = V_16 . V_33 ;
V_7 -> V_27 [ V_34 ] = V_18 ;
V_7 -> V_27 [ V_35 ] = V_10 -> V_36 ;
return 0 ;
}
static int F_6 ( struct V_1 * T_2 ,
struct V_37 * V_21 ,
struct V_38 * V_39 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
struct V_40 * V_41 , * V_42 = NULL ;
const struct V_43 * V_44 = V_21 -> V_44 ;
bool V_45 = F_7 () == 0 || F_8 () < 0 ;
V_10 -> V_21 = V_21 ;
V_10 -> V_36 = V_39 -> V_46 ;
F_9 (evlist, evsel) {
if ( V_41 -> V_47 . type == V_12 -> type ) {
if ( V_42 ) {
F_10 ( L_2 V_48 L_3 ) ;
return - V_20 ;
}
V_41 -> V_47 . V_49 = 0 ;
V_41 -> V_47 . V_50 = 1 ;
V_42 = V_41 ;
V_39 -> V_51 = true ;
}
}
if ( V_39 -> V_46 && ! V_39 -> V_51 ) {
F_10 ( L_4 V_48 L_5 V_48 L_6 ) ;
return - V_20 ;
}
if ( ! V_39 -> V_51 )
return 0 ;
if ( V_39 -> V_51 && ! F_11 ( V_44 ) ) {
F_10 ( V_48 L_7 ) ;
return - V_20 ;
}
if ( V_39 -> V_46 ) {
if ( ! V_39 -> V_52 && ! V_39 -> V_53 ) {
if ( V_45 ) {
V_39 -> V_53 = F_12 ( 4 ) / V_54 ;
} else {
V_39 -> V_53 = F_13 ( 128 ) / V_54 ;
if ( V_39 -> V_55 == V_56 )
V_39 -> V_55 = F_13 ( 256 ) / V_54 ;
}
} else if ( ! V_39 -> V_53 && ! V_45 &&
V_39 -> V_55 == V_56 ) {
V_39 -> V_55 = F_13 ( 256 ) / V_54 ;
}
if ( ! V_39 -> V_52 )
V_39 -> V_52 =
V_39 -> V_53 * ( T_1 ) V_54 ;
if ( ! V_39 -> V_53 ) {
T_1 V_57 = V_39 -> V_52 ;
V_57 = F_14 ( V_57 , V_54 ) / V_54 ;
V_39 -> V_53 = F_15 ( V_57 ) ;
}
if ( V_39 -> V_52 >
V_39 -> V_53 * ( T_1 ) V_54 ) {
F_10 ( L_8 ,
V_39 -> V_52 ,
V_39 -> V_53 * ( T_1 ) V_54 ) ;
return - V_20 ;
}
if ( ! V_39 -> V_52 || ! V_39 -> V_53 ) {
F_10 ( L_9 ) ;
return - V_20 ;
}
F_16 ( L_10 ,
V_39 -> V_52 ) ;
}
if ( V_39 -> V_51 && ! V_39 -> V_53 ) {
if ( V_45 ) {
V_39 -> V_53 = F_12 ( 4 ) / V_54 ;
} else {
V_39 -> V_53 = F_13 ( 128 ) / V_54 ;
if ( V_39 -> V_55 == V_56 )
V_39 -> V_55 = F_13 ( 256 ) / V_54 ;
}
}
if ( V_39 -> V_53 ) {
T_1 V_57 = V_39 -> V_53 * ( T_1 ) V_54 ;
T_1 V_58 ;
if ( V_39 -> V_46 )
V_58 = F_13 ( 4 ) ;
else
V_58 = F_13 ( 8 ) ;
if ( V_57 < V_58 || ! F_17 ( V_57 ) ) {
F_10 ( L_11 ,
V_58 / 1024 ) ;
return - V_20 ;
}
}
if ( V_42 ) {
F_18 ( V_21 , V_42 ) ;
if ( ! F_11 ( V_44 ) )
F_19 ( V_42 , V_59 ) ;
}
if ( V_39 -> V_51 ) {
struct V_40 * V_60 ;
int V_19 ;
V_19 = F_20 ( V_21 , L_12 , NULL ) ;
if ( V_19 )
return V_19 ;
V_60 = F_21 ( V_21 ) ;
F_22 ( V_21 , V_60 ) ;
V_60 -> V_47 . V_49 = 0 ;
V_60 -> V_47 . V_50 = 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * T_2 ,
struct V_38 * V_39 ,
const char * V_61 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
unsigned long long V_62 = 0 ;
char * V_63 ;
if ( V_61 ) {
V_62 = F_24 ( V_61 , & V_63 , 0 ) ;
if ( * V_63 || V_62 > V_64 )
return - 1 ;
}
V_39 -> V_46 = true ;
V_39 -> V_52 = V_62 ;
V_10 -> V_62 = V_62 ;
return 0 ;
}
static T_3 F_25 ( struct V_1 * T_2 V_2 )
{
return F_26 () ;
}
static int F_27 ( struct V_9 * V_10 ,
int V_65 )
{
const T_1 V_57 = sizeof( struct V_66 ) ;
int V_67 = V_10 -> V_68 , V_69 = V_67 * 2 ;
struct V_66 * V_70 ;
if ( ! V_69 )
V_69 = 16 ;
while ( V_69 <= V_65 )
V_69 *= 2 ;
V_70 = calloc ( V_69 , V_57 ) ;
if ( ! V_70 )
return - V_71 ;
memcpy ( V_70 , V_10 -> V_72 , V_67 * V_57 ) ;
V_10 -> V_72 = V_70 ;
V_10 -> V_68 = V_69 ;
return 0 ;
}
static void F_28 ( struct V_9 * V_10 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < V_10 -> V_68 ; V_73 ++ )
F_29 ( & V_10 -> V_72 [ V_73 ] . V_74 ) ;
F_29 ( & V_10 -> V_72 ) ;
}
static void F_30 ( struct V_1 * T_2 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
F_28 ( V_10 ) ;
free ( V_10 ) ;
}
static int F_31 ( struct V_1 * T_2 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
struct V_40 * V_41 ;
F_9 (btsr->evlist, evsel) {
if ( V_41 -> V_47 . type == V_10 -> V_12 -> type )
return F_32 ( V_10 -> V_21 , V_41 ) ;
}
return - V_20 ;
}
static int F_33 ( struct V_1 * T_2 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
struct V_40 * V_41 ;
F_9 (btsr->evlist, evsel) {
if ( V_41 -> V_47 . type == V_10 -> V_12 -> type )
return F_34 ( V_10 -> V_21 , V_41 ) ;
}
return - V_20 ;
}
static bool F_35 ( T_3 * V_75 , T_1 V_76 )
{
int V_73 , V_77 , V_78 ;
V_78 = V_76 >> 3 ;
V_77 = V_78 - 512 ;
if ( V_77 < 0 )
V_77 = 0 ;
for ( V_73 = V_77 ; V_73 < V_78 ; V_73 ++ ) {
if ( V_75 [ V_73 ] )
return true ;
}
return false ;
}
static int F_36 ( struct V_1 * T_2 , int V_65 ,
struct V_79 * V_80 , unsigned char * V_75 ,
T_3 * V_81 , T_3 * V_82 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
bool V_83 ;
int V_19 ;
F_37 ( L_13 ,
V_84 , V_65 , ( T_1 ) * V_82 , ( T_1 ) * V_81 ) ;
if ( V_65 >= V_10 -> V_68 ) {
V_19 = F_27 ( V_10 , V_65 ) ;
if ( V_19 )
goto V_85;
}
V_83 = V_10 -> V_72 [ V_65 ] . V_83 ;
if ( ! V_83 && F_35 ( ( T_3 * ) V_75 , V_80 -> V_86 ) ) {
V_10 -> V_72 [ V_65 ] . V_83 = true ;
V_83 = true ;
}
if ( V_83 ) {
* V_82 = * V_81 ;
* V_81 += V_80 -> V_86 ;
} else {
if ( V_80 -> V_87 )
* V_82 &= V_80 -> V_87 ;
else
* V_82 %= V_80 -> V_86 ;
if ( * V_82 > * V_81 )
* V_81 += V_80 -> V_86 ;
}
F_37 ( L_14 ,
V_84 , V_83 ? L_15 : L_16 , ( T_1 ) * V_82 , ( T_1 ) * V_81 ) ;
return 0 ;
V_85:
F_10 ( L_17 , V_84 , V_19 ) ;
return V_19 ;
}
static int F_38 ( struct V_1 * T_2 , int V_65 )
{
struct V_9 * V_10 =
F_3 ( T_2 , struct V_9 , T_2 ) ;
struct V_40 * V_41 ;
F_9 (btsr->evlist, evsel) {
if ( V_41 -> V_47 . type == V_10 -> V_12 -> type )
return F_39 ( V_10 -> V_21 ,
V_41 , V_65 ) ;
}
return - V_20 ;
}
struct V_1 * F_40 ( int * V_19 )
{
struct V_11 * V_12 = F_41 ( V_48 ) ;
struct V_9 * V_10 ;
if ( ! V_12 )
return NULL ;
V_10 = F_42 ( sizeof( struct V_9 ) ) ;
if ( ! V_10 ) {
* V_19 = - V_71 ;
return NULL ;
}
V_10 -> V_12 = V_12 ;
V_10 -> T_2 . V_88 = F_6 ;
V_10 -> T_2 . V_89 = F_1 ;
V_10 -> T_2 . V_90 = F_2 ;
V_10 -> T_2 . free = F_30 ;
V_10 -> T_2 . V_91 = F_31 ;
V_10 -> T_2 . V_92 = F_33 ;
V_10 -> T_2 . V_93 = F_36 ;
V_10 -> T_2 . V_94 = F_23 ;
V_10 -> T_2 . V_95 = F_25 ;
V_10 -> T_2 . V_96 = F_38 ;
V_10 -> T_2 . V_97 = sizeof( struct V_98 ) ;
return & V_10 -> T_2 ;
}
