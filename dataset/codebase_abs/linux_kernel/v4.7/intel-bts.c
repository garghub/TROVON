static T_1
F_1 ( struct V_1 * T_2 V_2 ,
struct V_3 * T_3 V_2 )
{
return V_4 ;
}
static int F_2 ( struct V_1 * T_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 = { . V_18 = 0 , } ;
bool V_19 = false ;
int V_20 ;
if ( V_9 != V_4 )
return - V_21 ;
if ( ! V_6 -> T_3 -> V_22 )
return - V_21 ;
V_15 = V_6 -> T_3 -> V_23 [ 0 ] . V_24 ;
if ( V_15 ) {
V_20 = F_4 ( V_15 , & V_17 ) ;
if ( V_20 ) {
if ( V_20 != - V_25 )
return V_20 ;
} else {
V_19 = V_17 . V_18 != 0 ;
}
if ( ! V_19 )
F_5 ( L_1 ) ;
}
V_8 -> type = V_26 ;
V_8 -> V_27 [ V_28 ] = V_13 -> type ;
V_8 -> V_27 [ V_29 ] = V_17 . V_30 ;
V_8 -> V_27 [ V_31 ] = V_17 . V_18 ;
V_8 -> V_27 [ V_32 ] = V_17 . V_33 ;
V_8 -> V_27 [ V_34 ] = V_19 ;
V_8 -> V_27 [ V_35 ] = V_11 -> V_36 ;
return 0 ;
}
static int F_6 ( struct V_1 * T_2 ,
struct V_3 * T_3 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
struct V_12 * V_13 = V_11 -> V_13 ;
struct V_39 * V_40 , * V_41 = NULL ;
const struct V_42 * V_43 = T_3 -> V_43 ;
bool V_44 = F_7 () == 0 || F_8 () < 0 ;
V_11 -> T_3 = T_3 ;
V_11 -> V_36 = V_38 -> V_45 ;
F_9 (evlist, evsel) {
if ( V_40 -> V_46 . type == V_13 -> type ) {
if ( V_41 ) {
F_10 ( L_2 V_47 L_3 ) ;
return - V_21 ;
}
V_40 -> V_46 . V_48 = 0 ;
V_40 -> V_46 . V_49 = 1 ;
V_41 = V_40 ;
V_38 -> V_50 = true ;
}
}
if ( V_38 -> V_45 && ! V_38 -> V_50 ) {
F_10 ( L_4 V_47 L_5 V_47 L_6 ) ;
return - V_21 ;
}
if ( ! V_38 -> V_50 )
return 0 ;
if ( V_38 -> V_50 && ! F_11 ( V_43 ) ) {
F_10 ( V_47 L_7 ) ;
return - V_21 ;
}
if ( V_38 -> V_45 ) {
if ( ! V_38 -> V_51 && ! V_38 -> V_52 ) {
if ( V_44 ) {
V_38 -> V_52 = F_12 ( 4 ) / V_53 ;
} else {
V_38 -> V_52 = F_13 ( 128 ) / V_53 ;
if ( V_38 -> V_54 == V_55 )
V_38 -> V_54 = F_13 ( 256 ) / V_53 ;
}
} else if ( ! V_38 -> V_52 && ! V_44 &&
V_38 -> V_54 == V_55 ) {
V_38 -> V_54 = F_13 ( 256 ) / V_53 ;
}
if ( ! V_38 -> V_51 )
V_38 -> V_51 =
V_38 -> V_52 * ( T_1 ) V_53 ;
if ( ! V_38 -> V_52 ) {
T_1 V_56 = V_38 -> V_51 ;
V_56 = F_14 ( V_56 , V_53 ) / V_53 ;
V_38 -> V_52 = F_15 ( V_56 ) ;
}
if ( V_38 -> V_51 >
V_38 -> V_52 * ( T_1 ) V_53 ) {
F_10 ( L_8 ,
V_38 -> V_51 ,
V_38 -> V_52 * ( T_1 ) V_53 ) ;
return - V_21 ;
}
if ( ! V_38 -> V_51 || ! V_38 -> V_52 ) {
F_10 ( L_9 ) ;
return - V_21 ;
}
F_16 ( L_10 ,
V_38 -> V_51 ) ;
}
if ( V_38 -> V_50 && ! V_38 -> V_52 ) {
if ( V_44 ) {
V_38 -> V_52 = F_12 ( 4 ) / V_53 ;
} else {
V_38 -> V_52 = F_13 ( 128 ) / V_53 ;
if ( V_38 -> V_54 == V_55 )
V_38 -> V_54 = F_13 ( 256 ) / V_53 ;
}
}
if ( V_38 -> V_52 ) {
T_1 V_56 = V_38 -> V_52 * ( T_1 ) V_53 ;
T_1 V_57 ;
if ( V_38 -> V_45 )
V_57 = F_13 ( 4 ) ;
else
V_57 = F_13 ( 8 ) ;
if ( V_56 < V_57 || ! F_17 ( V_56 ) ) {
F_10 ( L_11 ,
V_57 / 1024 ) ;
return - V_21 ;
}
}
if ( V_41 ) {
F_18 ( T_3 , V_41 ) ;
if ( ! F_11 ( V_43 ) )
F_19 ( V_41 , V_58 ) ;
}
if ( V_38 -> V_50 ) {
struct V_39 * V_59 ;
int V_20 ;
V_20 = F_20 ( T_3 , L_12 , NULL ) ;
if ( V_20 )
return V_20 ;
V_59 = F_21 ( T_3 ) ;
F_22 ( T_3 , V_59 ) ;
V_59 -> V_46 . V_48 = 0 ;
V_59 -> V_46 . V_49 = 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * T_2 ,
struct V_37 * V_38 ,
const char * V_60 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
unsigned long long V_61 = 0 ;
char * V_62 ;
if ( V_60 ) {
V_61 = F_24 ( V_60 , & V_62 , 0 ) ;
if ( * V_62 || V_61 > V_63 )
return - 1 ;
}
V_38 -> V_45 = true ;
V_38 -> V_51 = V_61 ;
V_11 -> V_61 = V_61 ;
return 0 ;
}
static T_4 F_25 ( struct V_1 * T_2 V_2 )
{
return F_26 () ;
}
static int F_27 ( struct V_10 * V_11 ,
int V_64 )
{
const T_1 V_56 = sizeof( struct V_65 ) ;
int V_66 = V_11 -> V_67 , V_68 = V_66 * 2 ;
struct V_65 * V_69 ;
if ( ! V_68 )
V_68 = 16 ;
while ( V_68 <= V_64 )
V_68 *= 2 ;
V_69 = calloc ( V_68 , V_56 ) ;
if ( ! V_69 )
return - V_70 ;
memcpy ( V_69 , V_11 -> V_71 , V_66 * V_56 ) ;
V_11 -> V_71 = V_69 ;
V_11 -> V_67 = V_68 ;
return 0 ;
}
static void F_28 ( struct V_10 * V_11 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_11 -> V_67 ; V_72 ++ )
F_29 ( & V_11 -> V_71 [ V_72 ] . V_73 ) ;
F_29 ( & V_11 -> V_71 ) ;
}
static void F_30 ( struct V_1 * T_2 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
F_28 ( V_11 ) ;
free ( V_11 ) ;
}
static int F_31 ( struct V_1 * T_2 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
struct V_39 * V_40 ;
F_9 (btsr->evlist, evsel) {
if ( V_40 -> V_46 . type == V_11 -> V_13 -> type )
return F_32 ( V_40 ) ;
}
return - V_21 ;
}
static int F_33 ( struct V_1 * T_2 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
struct V_39 * V_40 ;
F_9 (btsr->evlist, evsel) {
if ( V_40 -> V_46 . type == V_11 -> V_13 -> type )
return F_34 ( V_40 ) ;
}
return - V_21 ;
}
static bool F_35 ( T_4 * V_74 , T_1 V_75 )
{
int V_72 , V_76 , V_77 ;
V_77 = V_75 >> 3 ;
V_76 = V_77 - 512 ;
if ( V_76 < 0 )
V_76 = 0 ;
for ( V_72 = V_76 ; V_72 < V_77 ; V_72 ++ ) {
if ( V_74 [ V_72 ] )
return true ;
}
return false ;
}
static int F_36 ( struct V_1 * T_2 , int V_64 ,
struct V_78 * V_79 , unsigned char * V_74 ,
T_4 * V_80 , T_4 * V_81 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
bool V_82 ;
int V_20 ;
F_37 ( L_13 ,
V_83 , V_64 , ( T_1 ) * V_81 , ( T_1 ) * V_80 ) ;
if ( V_64 >= V_11 -> V_67 ) {
V_20 = F_27 ( V_11 , V_64 ) ;
if ( V_20 )
goto V_84;
}
V_82 = V_11 -> V_71 [ V_64 ] . V_82 ;
if ( ! V_82 && F_35 ( ( T_4 * ) V_74 , V_79 -> V_85 ) ) {
V_11 -> V_71 [ V_64 ] . V_82 = true ;
V_82 = true ;
}
if ( V_82 ) {
* V_81 = * V_80 ;
* V_80 += V_79 -> V_85 ;
} else {
if ( V_79 -> V_86 )
* V_81 &= V_79 -> V_86 ;
else
* V_81 %= V_79 -> V_85 ;
if ( * V_81 > * V_80 )
* V_80 += V_79 -> V_85 ;
}
F_37 ( L_14 ,
V_83 , V_82 ? L_15 : L_16 , ( T_1 ) * V_81 , ( T_1 ) * V_80 ) ;
return 0 ;
V_84:
F_10 ( L_17 , V_83 , V_20 ) ;
return V_20 ;
}
static int F_38 ( struct V_1 * T_2 , int V_64 )
{
struct V_10 * V_11 =
F_3 ( T_2 , struct V_10 , T_2 ) ;
struct V_39 * V_40 ;
F_9 (btsr->evlist, evsel) {
if ( V_40 -> V_46 . type == V_11 -> V_13 -> type )
return F_39 ( V_11 -> T_3 ,
V_40 , V_64 ) ;
}
return - V_21 ;
}
struct V_1 * F_40 ( int * V_20 )
{
struct V_12 * V_13 = F_41 ( V_47 ) ;
struct V_10 * V_11 ;
if ( ! V_13 )
return NULL ;
if ( F_42 ( L_18 , L_19 , 1 ) ) {
* V_20 = - V_87 ;
return NULL ;
}
V_11 = F_43 ( sizeof( struct V_10 ) ) ;
if ( ! V_11 ) {
* V_20 = - V_70 ;
return NULL ;
}
V_11 -> V_13 = V_13 ;
V_11 -> T_2 . V_88 = F_6 ;
V_11 -> T_2 . V_89 = F_1 ;
V_11 -> T_2 . V_90 = F_2 ;
V_11 -> T_2 . free = F_30 ;
V_11 -> T_2 . V_91 = F_31 ;
V_11 -> T_2 . V_92 = F_33 ;
V_11 -> T_2 . V_93 = F_36 ;
V_11 -> T_2 . V_94 = F_23 ;
V_11 -> T_2 . V_95 = F_25 ;
V_11 -> T_2 . V_96 = F_38 ;
V_11 -> T_2 . V_97 = sizeof( struct V_98 ) ;
return & V_11 -> T_2 ;
}
