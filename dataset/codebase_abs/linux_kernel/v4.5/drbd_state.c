static void F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
* V_3 = 0 ;
* V_4 = 0 ;
F_2 ( & V_2 -> V_10 , V_6 , V_9 )
( * V_3 ) ++ ;
F_3 ( V_8 , V_2 )
( * V_4 ) ++ ;
}
static struct V_11 * F_4 ( unsigned int V_3 , unsigned int V_4 , T_1 V_12 )
{
struct V_11 * V_13 ;
unsigned int V_14 , V_15 ;
V_14 = sizeof( struct V_11 ) +
V_3 * sizeof( struct V_16 ) +
V_4 * sizeof( struct V_17 ) +
V_3 * V_4 * sizeof( struct V_18 ) ;
V_13 = F_5 ( V_14 , V_12 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_3 = V_3 ;
V_13 -> V_4 = V_4 ;
V_13 -> V_10 = ( void * ) ( V_13 + 1 ) ;
V_13 -> V_19 = ( void * ) & V_13 -> V_10 [ V_3 ] ;
V_13 -> V_20 = ( void * ) & V_13 -> V_19 [ V_4 ] ;
V_13 -> V_2 -> V_2 = NULL ;
for ( V_15 = 0 ; V_15 < V_3 ; V_15 ++ )
V_13 -> V_10 [ V_15 ] . V_6 = NULL ;
for ( V_15 = 0 ; V_15 < V_4 ; V_15 ++ )
V_13 -> V_19 [ V_15 ] . V_8 = NULL ;
return V_13 ;
}
struct V_11 * F_6 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_11 * V_13 ;
struct V_5 * V_6 ;
unsigned int V_3 ;
struct V_7 * V_8 ;
unsigned int V_4 ;
int V_9 ;
struct V_16 * V_21 ;
struct V_18 * V_22 ;
struct V_17 * V_23 ;
F_1 ( V_2 , & V_3 , & V_4 ) ;
V_13 = F_4 ( V_3 , V_4 , V_12 ) ;
if ( ! V_13 )
return NULL ;
F_7 ( & V_2 -> V_24 ) ;
V_13 -> V_2 -> V_2 = V_2 ;
V_13 -> V_2 -> V_25 [ V_26 ] =
F_8 ( F_9 ( V_2 ) ) ;
V_13 -> V_2 -> V_27 [ V_26 ] = V_2 -> V_27 ;
V_13 -> V_2 -> V_28 [ V_26 ] = V_2 -> V_28 ;
V_13 -> V_2 -> V_29 [ V_26 ] = V_2 -> V_29 ;
V_23 = V_13 -> V_19 ;
F_3 (connection, resource) {
F_7 ( & V_8 -> V_24 ) ;
V_23 -> V_8 = V_8 ;
V_23 -> V_30 [ V_26 ] =
V_8 -> V_30 ;
V_23 -> V_31 [ V_26 ] =
F_10 ( V_8 ) ;
V_23 ++ ;
}
V_21 = V_13 -> V_10 ;
V_22 = V_13 -> V_20 ;
F_2 (&resource->devices, device, vnr) {
F_7 ( & V_6 -> V_24 ) ;
V_21 -> V_6 = V_6 ;
V_21 -> V_32 [ V_26 ] = V_6 -> V_33 . V_34 ;
F_3 (connection, resource) {
struct V_35 * V_36 ;
V_36 = F_11 ( V_8 , V_6 -> V_9 ) ;
V_22 -> V_36 = V_36 ;
V_22 -> V_32 [ V_26 ] =
V_6 -> V_33 . V_37 ;
V_22 -> V_38 [ V_26 ] =
F_12 ( enum V_39 ,
V_40 , V_6 -> V_33 . V_41 ) ;
V_22 -> V_42 [ V_26 ] =
V_6 -> V_33 . V_43 ;
V_22 -> V_44 [ V_26 ] =
V_6 -> V_33 . V_45 ;
V_22 -> V_46 [ V_26 ] =
V_6 -> V_33 . V_47 ;
V_22 ++ ;
}
V_21 ++ ;
}
return V_13 ;
}
static void F_13 ( struct V_11 * V_13 )
{
struct V_48 * V_49 ;
struct V_1 * V_2 ;
unsigned int V_15 ;
if ( ! V_13 )
return;
V_49 = & V_13 -> V_2 [ 0 ] ;
V_2 = V_49 -> V_2 ;
V_49 -> V_25 [ V_50 ] =
F_8 ( F_9 ( V_2 ) ) ;
V_49 -> V_27 [ V_50 ] = V_2 -> V_27 ;
V_49 -> V_28 [ V_50 ] = V_2 -> V_28 ;
V_49 -> V_29 [ V_50 ] = V_2 -> V_29 ;
for ( V_15 = 0 ; V_15 < V_13 -> V_3 ; V_15 ++ ) {
struct V_16 * V_21 =
& V_13 -> V_10 [ V_15 ] ;
struct V_5 * V_6 = V_21 -> V_6 ;
V_21 -> V_32 [ V_50 ] = V_6 -> V_33 . V_34 ;
}
for ( V_15 = 0 ; V_15 < V_13 -> V_4 ; V_15 ++ ) {
struct V_17 * V_23 =
& V_13 -> V_19 [ V_15 ] ;
struct V_7 * V_8 =
V_23 -> V_8 ;
V_23 -> V_30 [ V_50 ] = V_8 -> V_30 ;
V_23 -> V_31 [ V_50 ] =
F_10 ( V_8 ) ;
}
for ( V_15 = 0 ; V_15 < V_13 -> V_3 * V_13 -> V_4 ; V_15 ++ ) {
struct V_18 * V_22 =
& V_13 -> V_20 [ V_15 ] ;
struct V_5 * V_6 =
V_22 -> V_36 -> V_6 ;
union V_51 V_33 = V_6 -> V_33 ;
V_22 -> V_32 [ V_50 ] = V_33 . V_37 ;
V_22 -> V_38 [ V_50 ] =
F_12 ( enum V_39 , V_40 , V_33 . V_41 ) ;
V_22 -> V_42 [ V_50 ] =
V_33 . V_43 ;
V_22 -> V_44 [ V_50 ] =
V_33 . V_45 ;
V_22 -> V_46 [ V_50 ] =
V_33 . V_47 ;
}
}
void F_14 ( struct V_11 * V_13 )
{
struct V_48 * V_49 = & V_13 -> V_2 [ 0 ] ;
unsigned int V_52 , V_53 , V_54 , V_55 ;
#define F_15 ( T_2 ) \
(x[NEW] = x[OLD])
F_15 ( V_49 -> V_25 ) ;
F_15 ( V_49 -> V_27 ) ;
F_15 ( V_49 -> V_28 ) ;
F_15 ( V_49 -> V_29 ) ;
for ( V_53 = 0 ; V_53 < V_13 -> V_4 ; V_53 ++ ) {
struct V_17 * V_23 =
& V_13 -> V_19 [ V_53 ] ;
F_15 ( V_23 -> V_31 ) ;
F_15 ( V_23 -> V_30 ) ;
}
for ( V_52 = 0 ; V_52 < V_13 -> V_3 ; V_52 ++ ) {
struct V_16 * V_21 =
& V_13 -> V_10 [ V_52 ] ;
F_15 ( V_21 -> V_32 ) ;
}
V_55 = V_13 -> V_3 * V_13 -> V_4 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_18 * V_56 =
& V_13 -> V_20 [ V_54 ] ;
F_15 ( V_56 -> V_32 ) ;
F_15 ( V_56 -> V_38 ) ;
F_15 ( V_56 -> V_42 ) ;
F_15 ( V_56 -> V_44 ) ;
F_15 ( V_56 -> V_46 ) ;
}
#undef F_15
}
void F_16 ( struct V_11 * V_13 )
{
unsigned int V_15 ;
if ( ! V_13 )
return;
if ( V_13 -> V_2 -> V_2 )
F_17 ( & V_13 -> V_2 -> V_2 -> V_24 , V_57 ) ;
for ( V_15 = 0 ; V_15 < V_13 -> V_3 ; V_15 ++ ) {
struct V_5 * V_6 = V_13 -> V_10 [ V_15 ] . V_6 ;
if ( V_6 )
F_17 ( & V_6 -> V_24 , V_58 ) ;
}
for ( V_15 = 0 ; V_15 < V_13 -> V_4 ; V_15 ++ ) {
struct V_7 * V_8 =
V_13 -> V_19 [ V_15 ] . V_8 ;
if ( V_8 )
F_17 ( & V_8 -> V_24 , V_59 ) ;
}
F_18 ( V_13 ) ;
}
static inline bool F_19 ( union V_60 V_61 )
{
return V_61 . V_27 || V_61 . V_28 || V_61 . V_29 ;
}
bool F_20 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
bool V_62 = true ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
if ( V_6 -> V_33 . V_34 != V_63 ||
V_6 -> V_33 . V_41 != V_64 ||
V_6 -> V_33 . V_25 != V_65 ) {
V_62 = false ;
break;
}
}
F_22 () ;
return V_62 ;
}
static enum V_66 F_23 ( enum V_66 V_67 , enum V_66 V_68 )
{
if ( V_67 == V_69 || V_68 == V_69 )
return V_69 ;
if ( V_67 == V_65 || V_68 == V_65 )
return V_65 ;
return V_70 ;
}
static enum V_66 F_24 ( enum V_66 V_67 , enum V_66 V_68 )
{
if ( V_67 == V_70 || V_68 == V_70 )
return V_70 ;
if ( V_67 == V_65 || V_68 == V_65 )
return V_65 ;
return V_69 ;
}
enum V_66 F_8 ( struct V_7 * V_8 )
{
enum V_66 V_25 = V_70 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_25 = F_23 ( V_25 , V_6 -> V_33 . V_25 ) ;
}
F_22 () ;
return V_25 ;
}
enum V_66 F_10 ( struct V_7 * V_8 )
{
enum V_66 V_71 = V_70 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_71 = F_23 ( V_71 , V_6 -> V_33 . V_71 ) ;
}
F_22 () ;
return V_71 ;
}
enum V_72 F_25 ( struct V_7 * V_8 )
{
enum V_72 V_32 = V_63 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_32 = F_12 ( enum V_72 , V_32 , V_6 -> V_33 . V_34 ) ;
}
F_22 () ;
return V_32 ;
}
enum V_72 F_26 ( struct V_7 * V_8 )
{
enum V_72 V_32 = V_73 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_32 = F_27 ( enum V_72 , V_32 , V_6 -> V_33 . V_34 ) ;
}
F_22 () ;
return V_32 ;
}
enum V_72 F_28 ( struct V_7 * V_8 )
{
enum V_72 V_32 = V_63 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_32 = F_12 ( enum V_72 , V_32 , V_6 -> V_33 . V_37 ) ;
}
F_22 () ;
return V_32 ;
}
enum V_39 F_29 ( struct V_7 * V_8 )
{
enum V_39 V_41 = V_74 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_41 = F_27 ( enum V_39 , V_41 , V_6 -> V_33 . V_41 ) ;
}
F_22 () ;
return V_41 ;
}
static bool F_30 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
int V_9 ;
bool V_62 = true ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr)
if ( V_36 -> V_6 -> V_33 . V_41 == V_40 ) {
V_62 = false ;
break;
}
F_22 () ;
return V_62 ;
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr)
F_32 ( & V_36 -> V_6 -> V_75 ) ;
F_22 () ;
}
static int F_33 ( struct V_5 * V_6 ,
union V_60 V_76 , union V_60 V_77 )
{
return ( V_76 . V_41 >= V_78 && V_77 . V_41 >= V_78 &&
( ( V_76 . V_25 != V_69 && V_77 . V_25 == V_69 ) ||
( V_76 . V_41 != V_79 && V_77 . V_41 == V_79 ) ||
( V_76 . V_41 != V_80 && V_77 . V_41 == V_80 ) ||
( V_76 . V_34 != V_81 && V_77 . V_34 == V_81 ) ) ) ||
( V_76 . V_41 >= V_78 && V_77 . V_41 == V_82 ) ||
( V_76 . V_41 == V_78 && V_77 . V_41 == V_83 ) ||
( V_76 . V_41 == V_78 && V_77 . V_41 == V_40 ) ;
}
static union V_60
F_34 ( union V_60 V_76 , union V_60 V_84 , union V_60 V_85 )
{
union V_60 V_77 ;
V_77 . V_86 = ( V_76 . V_86 & ~ V_84 . V_86 ) | V_85 . V_86 ;
return V_77 ;
}
enum V_87
F_35 ( struct V_5 * V_6 , enum V_88 V_89 ,
union V_60 V_84 , union V_60 V_85 )
{
unsigned long V_90 ;
union V_60 V_77 ;
enum V_87 V_62 ;
F_36 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
V_77 = F_34 ( F_37 ( V_6 ) , V_84 , V_85 ) ;
V_62 = F_38 ( V_6 , V_77 , V_89 , NULL ) ;
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
return V_62 ;
}
void F_40 ( struct V_5 * V_6 ,
union V_60 V_84 , union V_60 V_85 )
{
F_35 ( V_6 , V_92 , V_84 , V_85 ) ;
}
static enum V_87
F_41 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 )
{
union V_60 V_76 , V_77 ;
unsigned long V_90 ;
enum V_87 V_62 ;
if ( F_42 ( V_93 , & V_6 -> V_90 ) )
return V_94 ;
if ( F_42 ( V_95 , & V_6 -> V_90 ) )
return V_96 ;
F_36 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_43 ( V_6 , V_76 , F_34 ( V_76 , V_84 , V_85 ) , NULL ) ;
V_62 = F_44 ( V_76 , V_77 ) ;
if ( V_62 >= V_97 )
V_62 = V_98 ;
if ( ! F_33 ( V_6 , V_76 , V_77 ) )
V_62 = V_99 ;
if ( V_62 == V_98 ) {
V_62 = F_45 ( V_6 , V_77 ) ;
if ( V_62 >= V_97 ) {
V_62 = F_46 ( V_76 , V_77 , F_47 ( V_6 ) -> V_8 ) ;
if ( V_62 >= V_97 )
V_62 = V_98 ;
}
}
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
return V_62 ;
}
static enum V_87
F_48 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 , enum V_88 V_89 )
{
struct V_100 V_101 ;
unsigned long V_90 ;
union V_60 V_76 , V_77 ;
enum V_87 V_62 ;
F_49 ( & V_101 ) ;
if ( V_89 & V_102 )
F_50 ( V_6 -> V_103 ) ;
F_36 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_43 ( V_6 , V_76 , F_34 ( V_76 , V_84 , V_85 ) , NULL ) ;
V_62 = F_44 ( V_76 , V_77 ) ;
if ( V_62 < V_97 ) {
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
goto abort;
}
if ( F_33 ( V_6 , V_76 , V_77 ) ) {
V_62 = F_45 ( V_6 , V_77 ) ;
if ( V_62 == V_97 )
V_62 = F_46 ( V_76 , V_77 , F_47 ( V_6 ) -> V_8 ) ;
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
if ( V_62 < V_97 ) {
if ( V_89 & V_104 )
F_51 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
if ( F_52 ( F_47 ( V_6 ) , V_84 , V_85 ) ) {
V_62 = V_96 ;
if ( V_89 & V_104 )
F_51 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
F_53 ( V_6 -> V_75 ,
( V_62 = F_41 ( V_6 , V_84 , V_85 ) ) ) ;
if ( V_62 < V_97 ) {
if ( V_89 & V_104 )
F_51 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
F_36 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
V_77 = F_34 ( F_37 ( V_6 ) , V_84 , V_85 ) ;
V_62 = F_38 ( V_6 , V_77 , V_89 , & V_101 ) ;
} else {
V_62 = F_38 ( V_6 , V_77 , V_89 , & V_101 ) ;
}
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
if ( V_89 & V_105 && V_62 == V_97 ) {
F_54 ( V_6 , V_106 != F_47 ( V_6 ) -> V_8 -> V_107 . V_108 ) ;
F_55 ( & V_101 ) ;
}
abort:
if ( V_89 & V_102 )
F_56 ( V_6 -> V_103 ) ;
return V_62 ;
}
enum V_87
F_57 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 , enum V_88 V_89 )
{
enum V_87 V_62 ;
F_53 ( V_6 -> V_75 ,
( V_62 = F_48 ( V_6 , V_84 , V_85 , V_89 ) ) != V_109 ) ;
return V_62 ;
}
enum V_87
F_58 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 , enum V_88 V_89 )
{
enum V_87 V_62 ;
F_59 ( V_89 & V_102 ) ;
F_60 ( V_6 -> V_75 ,
( V_62 = F_48 ( V_6 , V_84 , V_85 , V_89 ) ) != V_109 ,
F_56 ( V_6 -> V_103 ) ,
F_50 ( V_6 -> V_103 ) ) ;
return V_62 ;
}
static void F_61 ( struct V_5 * V_6 , const char * V_110 , union V_60 V_77 )
{
F_62 ( V_6 , L_1 ,
V_110 ,
F_63 ( V_77 . V_41 ) ,
F_64 ( V_77 . V_25 ) ,
F_64 ( V_77 . V_71 ) ,
F_65 ( V_77 . V_34 ) ,
F_65 ( V_77 . V_37 ) ,
F_19 ( V_77 ) ? 's' : 'r' ,
V_77 . V_47 ? 'a' : '-' ,
V_77 . V_45 ? 'p' : '-' ,
V_77 . V_43 ? 'u' : '-' ,
V_77 . V_29 ? 'F' : '-' ,
V_77 . V_28 ? 'N' : '-'
) ;
}
void F_51 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_87 V_111 )
{
if ( V_111 == V_109 )
return;
F_62 ( V_6 , L_2 , F_66 ( V_111 ) ) ;
F_61 ( V_6 , L_3 , V_76 ) ;
F_61 ( V_6 , L_4 , V_77 ) ;
}
static long F_67 ( char * V_112 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char * V_113 ;
V_113 = V_112 ;
* V_113 = 0 ;
if ( V_77 . V_25 != V_76 . V_25 && V_90 & V_114 )
V_113 += sprintf ( V_113 , L_5 ,
F_64 ( V_76 . V_25 ) ,
F_64 ( V_77 . V_25 ) ) ;
if ( V_77 . V_71 != V_76 . V_71 && V_90 & V_115 )
V_113 += sprintf ( V_113 , L_6 ,
F_64 ( V_76 . V_71 ) ,
F_64 ( V_77 . V_71 ) ) ;
if ( V_77 . V_41 != V_76 . V_41 && V_90 & V_116 )
V_113 += sprintf ( V_113 , L_7 ,
F_63 ( V_76 . V_41 ) ,
F_63 ( V_77 . V_41 ) ) ;
if ( V_77 . V_34 != V_76 . V_34 && V_90 & V_117 )
V_113 += sprintf ( V_113 , L_8 ,
F_65 ( V_76 . V_34 ) ,
F_65 ( V_77 . V_34 ) ) ;
if ( V_77 . V_37 != V_76 . V_37 && V_90 & V_118 )
V_113 += sprintf ( V_113 , L_9 ,
F_65 ( V_76 . V_37 ) ,
F_65 ( V_77 . V_37 ) ) ;
return V_113 - V_112 ;
}
static void F_68 ( struct V_5 * V_6 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char V_112 [ 300 ] ;
char * V_113 = V_112 ;
V_113 += F_67 ( V_113 , V_76 , V_77 , V_90 ^ V_119 ) ;
if ( V_77 . V_47 != V_76 . V_47 )
V_113 += sprintf ( V_113 , L_10 ,
V_76 . V_47 ,
V_77 . V_47 ) ;
if ( V_77 . V_45 != V_76 . V_45 )
V_113 += sprintf ( V_113 , L_11 ,
V_76 . V_45 ,
V_77 . V_45 ) ;
if ( V_77 . V_43 != V_76 . V_43 )
V_113 += sprintf ( V_113 , L_12 ,
V_76 . V_43 ,
V_77 . V_43 ) ;
if ( V_113 != V_112 )
F_69 ( V_6 , L_13 , V_112 ) ;
}
static void F_70 ( struct V_7 * V_8 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char V_112 [ 300 ] ;
char * V_113 = V_112 ;
V_113 += F_67 ( V_113 , V_76 , V_77 , V_90 ) ;
if ( F_19 ( V_77 ) != F_19 ( V_76 ) && V_90 & V_120 )
V_113 += sprintf ( V_113 , L_14 ,
F_19 ( V_76 ) ,
F_19 ( V_77 ) ) ;
if ( V_113 != V_112 )
F_69 ( V_8 , L_13 , V_112 ) ;
}
static enum V_87
F_45 ( struct V_5 * V_6 , union V_60 V_77 )
{
enum V_121 V_122 ;
enum V_87 V_62 = V_97 ;
struct V_123 * V_124 ;
F_21 () ;
V_122 = V_125 ;
if ( F_71 ( V_6 ) ) {
V_122 = F_72 ( V_6 -> V_126 -> V_127 ) -> V_128 ;
F_73 ( V_6 ) ;
}
V_124 = F_72 ( F_47 ( V_6 ) -> V_8 -> V_123 ) ;
if ( V_124 ) {
if ( ! V_124 -> V_129 && V_77 . V_25 == V_69 ) {
if ( V_77 . V_71 == V_69 )
V_62 = V_130 ;
else if ( F_10 ( F_47 ( V_6 ) -> V_8 ) == V_69 )
V_62 = V_131 ;
}
}
if ( V_62 <= 0 )
;
else if ( V_77 . V_25 == V_65 && V_6 -> V_132 )
V_62 = V_133 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_34 < V_134 )
V_62 = V_135 ;
else if ( V_122 >= V_136 &&
V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_37 >= V_137 )
V_62 = V_138 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_34 <= V_139 && V_77 . V_37 <= V_139 )
V_62 = V_135 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_34 < V_139 )
V_62 = V_140 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_37 < V_139 )
V_62 = V_141 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_34 < V_134 && V_77 . V_37 < V_134 )
V_62 = V_135 ;
else if ( ( V_77 . V_41 == V_78 ||
V_77 . V_41 == V_142 ||
V_77 . V_41 == V_143 ||
V_77 . V_41 == V_144 ) &&
V_77 . V_34 == V_145 )
V_62 = V_146 ;
else if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ) &&
( V_124 -> V_148 [ 0 ] == 0 ) )
V_62 = V_149 ;
else if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ) &&
F_47 ( V_6 ) -> V_8 -> V_150 < 88 )
V_62 = V_151 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_34 < V_134 && V_77 . V_37 < V_134 )
V_62 = V_135 ;
else if ( ( V_77 . V_41 == V_80 || V_77 . V_41 == V_79 ) &&
V_77 . V_37 == V_137 )
V_62 = V_152 ;
else if ( V_77 . V_41 >= V_78 && V_77 . V_37 == V_137 )
V_62 = V_146 ;
F_22 () ;
return V_62 ;
}
static enum V_87
F_46 ( union V_60 V_76 , union V_60 V_77 , struct V_7 * V_8 )
{
enum V_87 V_62 = V_97 ;
if ( ( V_77 . V_41 == V_79 || V_77 . V_41 == V_80 ) &&
V_76 . V_41 > V_78 )
V_62 = V_153 ;
if ( V_77 . V_41 == V_82 && V_76 . V_41 == V_64 )
V_62 = V_154 ;
if ( V_77 . V_34 > V_155 && V_76 . V_34 == V_63 )
V_62 = V_156 ;
if ( V_77 . V_41 == V_157 && V_76 . V_41 < V_158 )
V_62 = V_159 ;
if ( V_77 . V_34 == V_145 && V_76 . V_34 < V_145 && V_76 . V_34 != V_155 )
V_62 = V_160 ;
if ( V_77 . V_41 == V_82 && V_76 . V_41 == V_158 )
V_62 = V_109 ;
if ( F_74 ( V_161 , & V_8 -> V_90 ) &&
! ( ( V_77 . V_41 == V_40 && V_76 . V_41 == V_157 ) ||
( V_77 . V_41 >= V_78 && V_76 . V_41 == V_40 ) ) )
V_62 = V_109 ;
if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ) && V_76 . V_41 < V_78 )
V_62 = V_152 ;
if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ) &&
V_77 . V_41 != V_76 . V_41 && V_76 . V_41 > V_78 )
V_62 = V_153 ;
if ( ( V_77 . V_41 == V_80 || V_77 . V_41 == V_79 ) &&
V_76 . V_41 < V_78 )
V_62 = V_152 ;
if ( ( V_77 . V_41 == V_162 || V_77 . V_41 == V_143 )
&& V_76 . V_41 < V_40 )
V_62 = V_152 ;
if ( V_77 . V_41 == V_82 && V_77 . V_37 == V_145 &&
V_76 . V_41 < V_78 && V_76 . V_37 > V_145 )
V_62 = V_163 ;
return V_62 ;
}
static enum V_87
F_75 ( enum V_39 V_164 , enum V_39 V_124 )
{
if ( V_164 == V_124 )
return V_165 ;
if ( V_164 == V_64 && V_124 == V_82 )
return V_154 ;
if ( V_164 == V_64 && V_124 != V_158 )
return V_152 ;
if ( V_164 < V_40 && V_124 >= V_78 )
return V_152 ;
if ( V_164 >= V_166 && V_164 <= V_167 && V_124 != V_158 && V_124 != V_82 )
return V_109 ;
if ( V_164 == V_82 && V_124 != V_64 )
return V_109 ;
return V_97 ;
}
static enum V_87
F_44 ( union V_60 V_76 , union V_60 V_77 )
{
enum V_87 V_62 ;
V_62 = F_75 ( V_76 . V_41 , V_77 . V_41 ) ;
if ( V_77 . V_34 == V_81 && V_76 . V_34 == V_63 )
V_62 = V_156 ;
return V_62 ;
}
static void F_76 ( struct V_5 * V_6 , enum V_168 V_169 )
{
static const char * V_170 [] = {
[ V_171 ] = L_15 ,
[ V_172 ] = L_16 ,
[ V_173 ] = L_17 ,
[ V_174 ] = L_18 ,
[ V_175 ] = L_19 ,
[ V_176 ] = L_20 ,
} ;
if ( V_169 != V_171 )
F_77 ( V_6 , L_13 , V_170 [ V_169 ] ) ;
}
static union V_60 F_43 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_168 * V_169 )
{
enum V_121 V_122 ;
enum V_72 V_177 , V_178 , V_179 , V_180 ;
if ( V_169 )
* V_169 = V_171 ;
V_122 = V_125 ;
if ( F_71 ( V_6 ) ) {
F_21 () ;
V_122 = F_72 ( V_6 -> V_126 -> V_127 ) -> V_128 ;
F_22 () ;
F_73 ( V_6 ) ;
}
if ( V_77 . V_41 < V_78 ) {
V_77 . V_45 = 0 ;
V_77 . V_71 = V_70 ;
if ( V_77 . V_37 > V_137 || V_77 . V_37 < V_139 )
V_77 . V_37 = V_137 ;
}
if ( V_77 . V_41 == V_64 && V_77 . V_34 == V_63 && V_77 . V_25 == V_65 )
V_77 . V_47 = 0 ;
if ( V_77 . V_41 > V_78 && ( V_77 . V_34 <= V_81 || V_77 . V_37 <= V_81 ) ) {
if ( V_169 )
* V_169 = V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ?
V_172 : V_173 ;
V_77 . V_41 = V_78 ;
}
if ( V_77 . V_41 < V_78 && V_77 . V_34 == V_181 &&
F_78 ( V_6 , V_181 ) ) {
if ( V_6 -> V_182 == V_6 -> V_126 -> V_183 . V_184 [ V_185 ] ) {
V_77 . V_34 = V_6 -> V_186 . V_34 ;
V_77 . V_37 = V_6 -> V_186 . V_37 ;
} else {
if ( V_169 )
* V_169 = V_174 ;
V_77 . V_34 = V_63 ;
V_77 . V_37 = V_137 ;
}
F_73 ( V_6 ) ;
}
if ( V_77 . V_41 >= V_78 && V_77 . V_41 < V_187 ) {
if ( V_77 . V_34 == V_188 || V_77 . V_34 == V_145 )
V_77 . V_34 = V_134 ;
if ( V_77 . V_37 == V_188 || V_77 . V_37 == V_145 )
V_77 . V_37 = V_134 ;
}
V_177 = V_63 ;
V_178 = V_134 ;
V_179 = V_139 ;
V_180 = V_137 ;
switch ( (enum V_39 ) V_77 . V_41 ) {
case V_189 :
case V_190 :
case V_79 :
case V_191 :
case V_192 :
V_177 = V_139 ;
V_178 = V_145 ;
V_179 = V_134 ;
V_180 = V_134 ;
break;
case V_83 :
case V_147 :
V_177 = V_134 ;
V_178 = V_134 ;
V_179 = V_134 ;
V_180 = V_134 ;
break;
case V_78 :
V_177 = V_63 ;
V_178 = V_134 ;
V_179 = V_63 ;
V_180 = V_134 ;
break;
case V_142 :
case V_144 :
case V_80 :
case V_187 :
V_177 = V_134 ;
V_178 = V_134 ;
V_179 = V_139 ;
V_180 = V_188 ;
break;
case V_162 :
V_177 = V_139 ;
V_178 = V_139 ;
V_179 = V_134 ;
V_180 = V_134 ;
break;
case V_143 :
V_177 = V_134 ;
V_178 = V_134 ;
V_179 = V_139 ;
V_180 = V_139 ;
break;
case V_64 :
case V_82 :
case V_158 :
case V_166 :
case V_193 :
case V_194 :
case V_195 :
case V_167 :
case V_157 :
case V_40 :
case V_74 :
break;
}
if ( V_77 . V_34 > V_178 )
V_77 . V_34 = V_178 ;
if ( V_77 . V_34 < V_177 ) {
if ( V_169 )
* V_169 = V_175 ;
V_77 . V_34 = V_177 ;
}
if ( V_77 . V_37 > V_180 )
V_77 . V_37 = V_180 ;
if ( V_77 . V_37 < V_179 ) {
if ( V_169 )
* V_169 = V_176 ;
V_77 . V_37 = V_179 ;
}
if ( V_122 == V_196 &&
( V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_37 > V_145 ) &&
! ( V_76 . V_25 == V_69 && V_76 . V_41 < V_78 && V_76 . V_37 > V_145 ) )
V_77 . V_29 = 1 ;
if ( V_6 -> V_2 -> V_197 . V_198 == V_199 &&
( V_77 . V_25 == V_69 && V_77 . V_34 < V_134 && V_77 . V_37 < V_134 ) &&
! ( V_76 . V_25 == V_69 && V_76 . V_34 < V_134 && V_76 . V_37 < V_134 ) )
V_77 . V_28 = 1 ;
if ( V_77 . V_47 || V_77 . V_45 || V_77 . V_43 ) {
if ( V_77 . V_41 == V_143 )
V_77 . V_41 = V_144 ;
if ( V_77 . V_41 == V_162 )
V_77 . V_41 = V_190 ;
} else {
if ( V_77 . V_41 == V_144 )
V_77 . V_41 = V_143 ;
if ( V_77 . V_41 == V_190 )
V_77 . V_41 = V_162 ;
}
return V_77 ;
}
void F_79 ( struct V_5 * V_6 )
{
if ( F_42 ( V_200 , & V_6 -> V_90 ) )
F_69 ( V_6 , L_21 ) ;
}
static void F_80 ( struct V_5 * V_6 , enum V_39 V_201 )
{
if ( F_47 ( V_6 ) -> V_8 -> V_150 < 90 )
V_6 -> V_202 = 0 ;
V_6 -> V_203 = F_81 ( V_6 ) ;
V_6 -> V_204 = 0 ;
if ( V_201 == V_147 ) {
V_6 -> V_202 = ~ ( V_205 ) 0 ;
} else {
unsigned long V_206 = F_82 ( V_6 -> V_202 ) ;
if ( V_206 >= V_6 -> V_203 ) {
V_6 -> V_202 =
F_83 ( V_6 -> V_203 - 1 ) ;
V_6 -> V_203 = 1 ;
} else
V_6 -> V_203 -= V_206 ;
V_6 -> V_204 = V_6 -> V_202 ;
}
V_6 -> V_207 = V_6 -> V_203 ;
}
enum V_87
F_38 ( struct V_5 * V_6 , union V_60 V_77 ,
enum V_88 V_90 , struct V_100 * V_101 )
{
struct V_35 * V_36 = F_47 ( V_6 ) ;
struct V_7 * V_8 = V_36 ? V_36 -> V_8 : NULL ;
union V_60 V_76 ;
enum V_87 V_62 = V_97 ;
enum V_168 V_208 ;
struct V_209 * V_210 ;
struct V_11 * V_13 ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_43 ( V_6 , V_76 , V_77 , & V_208 ) ;
if ( V_77 . V_86 == V_76 . V_86 )
return V_165 ;
V_62 = F_44 ( V_76 , V_77 ) ;
if ( V_62 < V_97 )
return V_62 ;
if ( ! ( V_90 & V_92 ) ) {
V_62 = F_45 ( V_6 , V_77 ) ;
if ( V_62 < V_97 ) {
if ( F_45 ( V_6 , V_76 ) == V_62 )
V_62 = F_46 ( V_76 , V_77 , V_8 ) ;
} else
V_62 = F_46 ( V_76 , V_77 , V_8 ) ;
}
if ( V_62 < V_97 ) {
if ( V_90 & V_104 )
F_51 ( V_6 , V_76 , V_77 , V_62 ) ;
return V_62 ;
}
F_76 ( V_6 , V_208 ) ;
F_68 ( V_6 , V_76 , V_77 , V_90 ) ;
if ( ! ( V_90 & V_120 ) )
F_70 ( V_8 , V_76 , V_77 ,
( V_90 & ~ V_119 ) | V_120 ) ;
if ( ( V_76 . V_34 != V_81 && V_77 . V_34 == V_81 ) ||
( V_76 . V_34 != V_63 && V_77 . V_34 == V_63 ) )
F_84 ( & V_6 -> V_211 ) ;
if ( ! F_85 ( V_76 . V_41 ) && F_85 ( V_77 . V_41 ) )
F_86 ( V_212 , & V_6 -> V_90 ) ;
V_13 = F_6 ( V_6 -> V_2 , V_213 ) ;
F_87 () ;
V_6 -> V_33 . V_86 = V_77 . V_86 ;
V_6 -> V_2 -> V_27 = V_77 . V_27 ;
V_6 -> V_2 -> V_28 = V_77 . V_28 ;
V_6 -> V_2 -> V_29 = V_77 . V_29 ;
F_87 () ;
F_13 ( V_13 ) ;
if ( F_88 ( (union V_51 ) V_76 . V_86 ) !=
F_88 ( (union V_51 ) V_77 . V_86 ) )
F_89 ( V_8 ) ;
if ( V_76 . V_34 == V_155 && V_77 . V_34 >= V_181 )
F_90 ( V_6 , L_22 ) ;
if ( V_76 . V_41 == V_40 && V_77 . V_41 != V_40 &&
F_30 ( V_8 ) ) {
F_86 ( V_161 , & V_8 -> V_90 ) ;
F_31 ( V_8 ) ;
}
F_32 ( & V_6 -> V_214 ) ;
F_32 ( & V_6 -> V_75 ) ;
F_32 ( & V_8 -> V_215 ) ;
if ( ( V_76 . V_41 == V_83 || V_76 . V_41 == V_147 ) &&
V_77 . V_41 <= V_78 ) {
V_6 -> V_202 =
F_83 ( F_81 ( V_6 ) - V_6 -> V_207 ) ;
if ( V_6 -> V_207 )
F_69 ( V_6 , L_23 ,
( unsigned long long ) V_6 -> V_202 ) ;
}
if ( ( V_76 . V_41 == V_190 || V_76 . V_41 == V_144 ) &&
( V_77 . V_41 == V_162 || V_77 . V_41 == V_143 ) ) {
F_69 ( V_6 , L_24 ) ;
V_6 -> V_216 += ( long ) V_217
- ( long ) V_6 -> V_218 [ V_6 -> V_219 ] ;
if ( V_77 . V_41 == V_162 )
F_91 ( & V_6 -> V_220 , V_217 ) ;
}
if ( ( V_76 . V_41 == V_162 || V_76 . V_41 == V_143 ) &&
( V_77 . V_41 == V_190 || V_77 . V_41 == V_144 ) ) {
F_69 ( V_6 , L_25 ) ;
V_6 -> V_218 [ V_6 -> V_219 ] = V_217 ;
}
if ( V_76 . V_41 == V_78 &&
( V_77 . V_41 == V_83 || V_77 . V_41 == V_147 ) ) {
unsigned long V_221 = V_217 ;
int V_86 ;
F_80 ( V_6 , V_77 . V_41 ) ;
V_6 -> V_222 = V_221 ;
V_6 -> V_223 = 0 ;
V_6 -> V_224 = 0 ;
V_6 -> V_225 = 0 ;
for ( V_86 = 0 ; V_86 < V_226 ; V_86 ++ ) {
V_6 -> V_227 [ V_86 ] = V_6 -> V_207 ;
V_6 -> V_218 [ V_86 ] = V_221 ;
}
F_92 ( V_6 ) ;
if ( V_77 . V_41 == V_83 ) {
F_69 ( V_6 , L_26 ,
( unsigned long long ) V_6 -> V_204 ) ;
F_91 ( & V_6 -> V_220 , V_217 ) ;
}
}
if ( F_71 ( V_6 ) ) {
T_3 V_228 = V_6 -> V_126 -> V_183 . V_90 & ~ ( V_229 | V_230 |
V_231 | V_232 |
V_233 | V_234 ) ;
V_228 &= ~ V_235 ;
if ( F_74 ( V_236 , & V_6 -> V_90 ) )
V_228 |= V_234 ;
if ( V_6 -> V_33 . V_25 == V_69 ||
( V_6 -> V_33 . V_37 < V_139 && V_6 -> V_33 . V_71 == V_69 ) )
V_228 |= V_230 ;
if ( V_6 -> V_33 . V_41 > V_40 )
V_228 |= V_231 ;
if ( V_6 -> V_33 . V_34 > V_139 )
V_228 |= V_229 ;
if ( V_6 -> V_33 . V_34 > V_145 )
V_228 |= V_232 ;
if ( V_6 -> V_33 . V_37 <= V_145 && V_6 -> V_33 . V_37 >= V_139 )
V_228 |= V_233 ;
if ( V_228 != V_6 -> V_126 -> V_183 . V_90 ) {
V_6 -> V_126 -> V_183 . V_90 = V_228 ;
F_93 ( V_6 ) ;
}
if ( V_76 . V_34 < V_188 && V_77 . V_34 >= V_188 )
F_94 ( V_6 , V_6 -> V_126 -> V_183 . V_184 [ V_185 ] ) ;
F_73 ( V_6 ) ;
}
if ( V_76 . V_34 == V_139 && V_76 . V_37 == V_139 &&
V_76 . V_71 == V_65 && V_77 . V_71 == V_69 )
F_95 ( V_237 , & V_6 -> V_90 ) ;
if ( V_76 . V_41 != V_82 && V_77 . V_41 == V_82 )
F_96 ( & V_8 -> V_238 ) ;
if ( V_76 . V_41 != V_64 && V_77 . V_41 == V_64 )
F_96 ( & V_8 -> V_238 ) ;
if ( V_76 . V_41 > V_157 &&
V_77 . V_41 <= V_167 && V_77 . V_41 >= V_166 )
F_97 ( & V_8 -> V_238 ) ;
if ( V_76 . V_41 < V_78 && V_77 . V_41 >= V_78 ) {
F_79 ( V_6 ) ;
V_8 -> V_239 ++ ;
}
if ( ( V_76 . V_34 == V_155 || V_76 . V_34 == V_181 ) &&
V_77 . V_34 > V_181 )
V_6 -> V_240 = V_217 ;
V_210 = F_5 ( sizeof( * V_210 ) , V_213 ) ;
if ( V_210 ) {
V_210 -> V_76 = V_76 ;
V_210 -> V_77 = V_77 ;
V_210 -> V_90 = V_90 ;
V_210 -> V_241 . V_242 = V_243 ;
V_210 -> V_6 = V_6 ;
V_210 -> V_101 = V_101 ;
V_210 -> V_13 = V_13 ;
F_98 ( & V_8 -> V_244 ,
& V_210 -> V_241 ) ;
} else {
F_62 ( V_6 , L_27 ) ;
}
return V_62 ;
}
static int V_243 ( struct V_245 * V_241 , int V_246 )
{
struct V_209 * V_210 =
F_99 ( V_241 , struct V_209 , V_241 ) ;
struct V_5 * V_6 = V_210 -> V_6 ;
F_100 ( V_6 , V_210 -> V_76 , V_210 -> V_77 , V_210 -> V_90 , V_210 -> V_13 ) ;
F_16 ( V_210 -> V_13 ) ;
if ( V_210 -> V_90 & V_105 )
F_101 ( V_210 -> V_101 ) ;
F_18 ( V_210 ) ;
return 0 ;
}
static void F_102 ( struct V_5 * V_6 , int V_62 )
{
if ( V_62 ) {
F_62 ( V_6 , L_28 ) ;
F_57 ( V_6 , F_103 ( V_41 , V_78 ) , V_104 ) ;
return;
}
switch ( V_6 -> V_33 . V_41 ) {
case V_79 :
F_57 ( V_6 , F_103 ( V_41 , V_191 ) , V_104 ) ;
break;
case V_80 :
F_104 ( V_6 , V_143 ) ;
break;
}
}
int F_105 ( struct V_5 * V_6 ,
int (* F_106)( struct V_5 * ) ,
char * V_247 , enum V_248 V_90 )
{
int V_62 ;
F_54 ( V_6 , V_106 == F_47 ( V_6 ) -> V_8 -> V_107 . V_108 ) ;
F_84 ( & V_6 -> V_249 ) ;
F_107 ( V_6 , V_247 , V_90 ) ;
V_62 = F_106 ( V_6 ) ;
F_108 ( V_6 ) ;
F_109 ( V_6 ) ;
return V_62 ;
}
void F_110 ( struct V_250 * V_251 ,
unsigned int V_252 ,
struct V_48 * V_49 ,
enum V_253 type )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_254 V_254 = {
. V_255 = V_49 -> V_25 [ V_50 ] ,
. V_256 = V_49 -> V_27 [ V_50 ] ,
. V_257 = V_49 -> V_28 [ V_50 ] ,
. V_258 = V_49 -> V_29 [ V_50 ] ,
} ;
F_111 ( V_251 , V_252 , V_2 , & V_254 , type ) ;
}
void F_112 ( struct V_250 * V_251 ,
unsigned int V_252 ,
struct V_17 * V_23 ,
enum V_253 type )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_259 V_259 = {
. V_260 = V_23 -> V_30 [ V_50 ] ,
. V_261 = V_23 -> V_31 [ V_50 ] ,
} ;
F_113 ( V_251 , V_252 , V_8 , & V_259 , type ) ;
}
void F_114 ( struct V_250 * V_251 ,
unsigned int V_252 ,
struct V_16 * V_21 ,
enum V_253 type )
{
struct V_5 * V_6 = V_21 -> V_6 ;
struct V_262 V_262 = {
. V_263 = V_21 -> V_32 [ V_50 ] ,
} ;
F_115 ( V_251 , V_252 , V_6 , & V_262 , type ) ;
}
void F_116 ( struct V_250 * V_251 ,
unsigned int V_252 ,
struct V_18 * V_56 ,
enum V_253 type )
{
struct V_35 * V_36 = V_56 -> V_36 ;
struct V_264 V_264 = {
. V_265 = V_56 -> V_38 [ V_50 ] ,
. V_266 = V_56 -> V_32 [ V_50 ] ,
. V_267 = V_56 -> V_42 [ V_50 ] ,
. V_268 = V_56 -> V_44 [ V_50 ] ,
. V_269 = V_56 -> V_46 [ V_50 ] ,
} ;
F_117 ( V_251 , V_252 , V_36 , & V_264 , type ) ;
}
static void F_118 ( struct V_11 * V_13 )
{
struct V_48 * V_49 = & V_13 -> V_2 [ 0 ] ;
bool V_270 ;
unsigned int V_52 , V_53 , V_54 , V_55 ;
void (* F_119)( struct V_250 * , unsigned int , void * ,
enum V_253 ) = NULL ;
void * V_271 ( V_272 ) ;
#define F_120 ( V_33 ) ((state)[OLD] != (state)[NEW])
#define F_121 ( type ) \
({ if (last_func) \
last_func(NULL, 0, last_arg, type); \
})
#define F_122 ( T_4 , T_5 , type ) \
({ FINAL_STATE_CHANGE(type | NOTIFY_CONTINUES); \
last_func = (typeof(last_func))func; \
last_arg = arg; \
})
F_50 ( & V_273 ) ;
V_270 =
F_120 ( V_49 -> V_25 ) ||
F_120 ( V_49 -> V_27 ) ||
F_120 ( V_49 -> V_28 ) ||
F_120 ( V_49 -> V_29 ) ;
if ( V_270 )
F_122 ( F_110 ,
V_49 , V_274 ) ;
for ( V_53 = 0 ; V_53 < V_13 -> V_4 ; V_53 ++ ) {
struct V_17 * V_23 =
& V_13 -> V_19 [ V_53 ] ;
if ( F_120 ( V_23 -> V_31 ) ||
F_120 ( V_23 -> V_30 ) )
F_122 ( F_112 ,
V_23 , V_274 ) ;
}
for ( V_52 = 0 ; V_52 < V_13 -> V_3 ; V_52 ++ ) {
struct V_16 * V_21 =
& V_13 -> V_10 [ V_52 ] ;
if ( F_120 ( V_21 -> V_32 ) )
F_122 ( F_114 ,
V_21 , V_274 ) ;
}
V_55 = V_13 -> V_3 * V_13 -> V_4 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_18 * V_56 =
& V_13 -> V_20 [ V_54 ] ;
if ( F_120 ( V_56 -> V_32 ) ||
F_120 ( V_56 -> V_38 ) ||
F_120 ( V_56 -> V_42 ) ||
F_120 ( V_56 -> V_44 ) ||
F_120 ( V_56 -> V_46 ) )
F_122 ( F_116 ,
V_56 , V_274 ) ;
}
F_121 ( V_274 ) ;
F_56 ( & V_273 ) ;
#undef F_120
#undef F_121
#undef F_122
}
static void F_100 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_88 V_90 ,
struct V_11 * V_13 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_35 * V_36 = F_47 ( V_6 ) ;
struct V_7 * V_8 = V_36 ? V_36 -> V_8 : NULL ;
struct V_275 V_276 ;
F_118 ( V_13 ) ;
V_276 . V_277 = V_278 ;
V_276 . V_76 = V_76 ;
V_276 . V_77 = V_77 ;
if ( ( V_76 . V_34 != V_134 || V_76 . V_37 != V_134 )
&& ( V_77 . V_34 == V_134 && V_77 . V_37 == V_134 ) ) {
F_86 ( V_236 , & V_6 -> V_90 ) ;
if ( V_6 -> V_279 )
V_6 -> V_279 [ V_280 ] &= ~ ( ( V_281 ) 2 ) ;
}
F_123 ( V_6 , & V_276 ) ;
if ( ! ( V_76 . V_25 == V_69 && V_76 . V_34 < V_134 && V_76 . V_37 < V_134 ) &&
( V_77 . V_25 == V_69 && V_77 . V_34 < V_134 && V_77 . V_37 < V_134 ) )
F_124 ( V_6 , L_29 ) ;
if ( V_77 . V_28 ) {
enum V_282 V_283 = V_284 ;
F_125 ( & V_6 -> V_2 -> V_91 ) ;
if ( V_76 . V_41 < V_78 && F_29 ( V_8 ) >= V_78 )
V_283 = V_285 ;
if ( ( V_76 . V_34 == V_155 || V_76 . V_34 == V_181 ) &&
F_26 ( V_8 ) > V_181 )
V_283 = V_286 ;
if ( V_2 -> V_28 && V_283 != V_284 ) {
F_126 ( V_8 , V_283 ) ;
F_127 (connection,
(union drbd_state) { { .susp_nod = 1 } },
(union drbd_state) { { .susp_nod = 0 } },
CS_VERBOSE) ;
}
F_128 ( & V_6 -> V_2 -> V_91 ) ;
}
if ( V_77 . V_29 ) {
F_125 ( & V_6 -> V_2 -> V_91 ) ;
if ( V_2 -> V_29 && F_29 ( V_8 ) >= V_78 ) {
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr)
F_86 ( V_287 , & V_36 -> V_6 -> V_90 ) ;
F_22 () ;
F_126 ( V_8 , V_285 ) ;
F_127 (connection,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
}
F_128 ( & V_6 -> V_2 -> V_91 ) ;
}
if ( ( V_76 . V_41 != V_143 && V_76 . V_41 != V_144 ) &&
( V_77 . V_41 == V_143 || V_77 . V_41 == V_144 ) &&
V_8 -> V_150 >= 96 && F_71 ( V_6 ) ) {
F_129 ( V_36 ) ;
F_73 ( V_6 ) ;
}
if ( V_76 . V_37 == V_63 &&
V_77 . V_37 > V_63 && V_77 . V_37 != V_137 ) {
V_6 -> V_203 = 0 ;
V_6 -> V_288 = 0 ;
F_130 ( & V_6 -> V_289 , 0 ) ;
F_131 ( V_6 ) ;
F_132 ( V_36 ) ;
F_133 ( V_36 , V_77 ) ;
}
if ( V_76 . V_41 != V_142 && V_77 . V_41 == V_142 &&
V_6 -> V_33 . V_41 == V_142 )
F_134 ( V_6 , & V_290 , NULL ,
L_30 ,
V_291 ) ;
if ( ( V_76 . V_37 >= V_139 &&
V_76 . V_37 != V_137 &&
V_76 . V_37 != V_145 )
&& ( V_77 . V_37 < V_139 ||
V_77 . V_37 == V_137 ||
V_77 . V_37 == V_145 ) ) {
if ( F_71 ( V_6 ) ) {
if ( ( V_77 . V_25 == V_69 || V_77 . V_71 == V_69 ) &&
V_6 -> V_126 -> V_183 . V_184 [ V_292 ] == 0 && V_77 . V_34 >= V_134 ) {
if ( F_135 ( V_6 ) ) {
F_95 ( V_287 , & V_6 -> V_90 ) ;
} else {
F_136 ( V_6 ) ;
F_132 ( V_36 ) ;
}
}
F_73 ( V_6 ) ;
}
}
if ( V_77 . V_37 < V_139 && F_71 ( V_6 ) ) {
if ( V_76 . V_71 != V_69 && V_77 . V_71 == V_69 &&
V_6 -> V_126 -> V_183 . V_184 [ V_292 ] == 0 && V_77 . V_34 >= V_134 ) {
F_136 ( V_6 ) ;
F_132 ( V_36 ) ;
}
if ( V_76 . V_71 == V_69 && V_77 . V_71 == V_65 )
F_105 ( V_6 , & V_293 ,
L_31 , V_294 ) ;
F_73 ( V_6 ) ;
}
if ( V_76 . V_25 == V_69 && V_77 . V_25 == V_65 &&
V_6 -> V_33 . V_41 <= V_78 && F_71 ( V_6 ) ) {
F_105 ( V_6 , & V_293 ,
L_32 , V_291 ) ;
F_73 ( V_6 ) ;
}
if ( V_77 . V_41 >= V_78 &&
V_76 . V_34 == V_155 && V_77 . V_34 == V_181 ) {
F_137 ( V_36 , 0 , 0 ) ;
F_132 ( V_36 ) ;
F_133 ( V_36 , V_77 ) ;
}
if ( V_77 . V_41 >= V_78 &&
( ( V_76 . V_47 != V_77 . V_47 ) ||
( V_76 . V_43 != V_77 . V_43 ) ) )
F_133 ( V_36 , V_77 ) ;
if ( ( ! V_76 . V_47 && ! V_76 . V_45 && ! V_76 . V_43 ) &&
( V_77 . V_47 || V_77 . V_45 || V_77 . V_43 ) )
F_138 ( V_6 ) ;
if ( V_76 . V_41 == V_40 && V_77 . V_41 >= V_78 )
F_133 ( V_36 , V_77 ) ;
if ( V_76 . V_41 != V_187 && V_77 . V_41 == V_187 )
F_133 ( V_36 , V_77 ) ;
if ( ( V_76 . V_41 != V_79 && V_77 . V_41 == V_79 ) ||
( V_76 . V_41 != V_80 && V_77 . V_41 == V_80 ) )
F_134 ( V_6 ,
& V_295 , & F_102 ,
L_33 , V_291 ) ;
if ( V_76 . V_34 != V_81 && V_77 . V_34 == V_81 ) {
enum V_296 V_297 = V_298 ;
int V_299 = 0 ;
if ( V_6 -> V_126 ) {
F_21 () ;
V_297 = F_72 ( V_6 -> V_126 -> V_127 ) -> V_300 ;
F_22 () ;
V_299 = F_42 ( V_301 , & V_6 -> V_90 ) ;
if ( V_299 && V_297 == V_302 )
F_124 ( V_6 , L_34 ) ;
if ( F_42 ( V_303 , & V_6 -> V_90 ) )
F_139 ( V_6 ) ;
if ( V_6 -> V_33 . V_34 != V_81 )
F_62 ( V_6 ,
L_35 ,
F_65 ( V_6 -> V_33 . V_34 ) ) ;
if ( V_77 . V_41 >= V_78 )
F_133 ( V_36 , V_77 ) ;
F_131 ( V_6 ) ;
F_140 ( V_6 ) ;
}
F_73 ( V_6 ) ;
}
if ( V_76 . V_34 != V_63 && V_77 . V_34 == V_63 ) {
if ( V_6 -> V_33 . V_34 != V_63 )
F_62 ( V_6 ,
L_36 ,
F_65 ( V_6 -> V_33 . V_34 ) ) ;
if ( V_77 . V_41 >= V_78 )
F_133 ( V_36 , V_77 ) ;
F_73 ( V_6 ) ;
}
if ( V_76 . V_34 == V_134 && V_77 . V_34 == V_139 && V_77 . V_41 >= V_78 )
F_133 ( V_36 , V_77 ) ;
if ( V_77 . V_34 > V_181 && V_77 . V_37 > V_181 &&
F_42 ( V_304 , & V_6 -> V_90 ) ) {
if ( V_77 . V_41 == V_78 )
F_141 ( V_6 ) ;
}
if ( ( V_76 . V_41 > V_78 && V_77 . V_41 <= V_78 ) ||
( V_76 . V_45 && ! V_77 . V_45 ) ||
( V_76 . V_43 && ! V_77 . V_43 ) )
F_142 ( V_6 ) ;
if ( V_76 . V_34 < V_134 && V_76 . V_41 >= V_143 && V_77 . V_41 == V_78 )
F_133 ( V_36 , V_77 ) ;
if ( V_76 . V_41 == V_83 && V_77 . V_41 == V_78
&& F_143 ( V_6 ) )
F_133 ( V_36 , V_77 ) ;
if ( V_76 . V_41 > V_78 && V_77 . V_41 <= V_78 && F_71 ( V_6 ) ) {
F_134 ( V_6 , & V_305 , NULL ,
L_37 , V_306 ) ;
F_73 ( V_6 ) ;
}
if ( V_77 . V_34 == V_63 &&
V_77 . V_41 == V_64 &&
V_77 . V_25 == V_65 ) {
if ( V_76 . V_47 != V_77 . V_47 )
F_142 ( V_6 ) ;
}
F_140 ( V_6 ) ;
}
static int F_144 ( struct V_245 * V_241 , int V_246 )
{
struct V_307 * V_308 =
F_99 ( V_241 , struct V_307 , V_241 ) ;
struct V_7 * V_8 = V_308 -> V_8 ;
enum V_39 V_164 = V_308 -> V_164 ;
union V_60 V_309 = V_308 -> V_309 ;
struct V_35 * V_36 ;
int V_9 ;
F_118 ( V_308 -> V_13 ) ;
F_16 ( V_308 -> V_13 ) ;
F_18 ( V_308 ) ;
if ( V_164 == V_64 && V_309 . V_41 == V_158 )
F_145 ( & V_8 -> V_238 ) ;
if ( V_164 == V_82 && V_309 . V_41 == V_64 ) {
struct V_123 * V_310 ;
F_50 ( & V_273 ) ;
F_2 (&connection->peer_devices, peer_device, vnr)
F_117 ( NULL , 0 , V_36 , NULL ,
V_311 | V_312 ) ;
F_113 ( NULL , 0 , V_8 , NULL , V_311 ) ;
F_56 ( & V_273 ) ;
F_50 ( & V_8 -> V_2 -> V_313 ) ;
V_310 = V_8 -> V_123 ;
V_8 -> V_314 = 0 ;
V_8 -> V_315 = 0 ;
F_146 ( V_8 -> V_123 , NULL ) ;
F_147 ( V_8 ) ;
F_56 ( & V_8 -> V_2 -> V_313 ) ;
F_148 () ;
F_18 ( V_310 ) ;
}
if ( V_309 . V_29 ) {
if ( V_309 . V_37 <= V_145 ) {
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
if ( F_74 ( V_287 , & V_6 -> V_90 ) ) {
F_136 ( V_6 ) ;
F_86 ( V_287 , & V_6 -> V_90 ) ;
}
}
F_22 () ;
F_125 ( & V_8 -> V_2 -> V_91 ) ;
F_126 ( V_8 , V_316 ) ;
F_127 (connection,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
F_128 ( & V_8 -> V_2 -> V_91 ) ;
}
}
F_17 ( & V_8 -> V_24 , V_59 ) ;
F_149 ( V_8 ) ;
return 0 ;
}
static void F_150 ( struct V_7 * V_8 , union V_60 * V_317 , enum V_88 * V_318 )
{
enum V_88 V_90 = ~ 0 ;
struct V_35 * V_36 ;
int V_9 , V_319 = 1 ;
union V_51 V_76 , V_201 = {
{ . V_25 = V_65 ,
. V_71 = V_70 ,
. V_41 = V_8 -> V_30 ,
. V_34 = V_63 ,
. V_37 = V_137 ,
} } ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_76 = V_6 -> V_33 ;
if ( V_319 ) {
V_201 = V_76 ;
V_319 = 0 ;
continue;
}
if ( V_201 . V_25 != V_76 . V_25 )
V_90 &= ~ V_114 ;
if ( V_201 . V_71 != V_76 . V_71 )
V_90 &= ~ V_115 ;
if ( V_201 . V_41 != V_76 . V_41 )
V_90 &= ~ V_116 ;
if ( V_201 . V_34 != V_76 . V_34 )
V_90 &= ~ V_117 ;
if ( V_201 . V_37 != V_76 . V_37 )
V_90 &= ~ V_118 ;
}
F_22 () ;
* V_318 |= V_119 ;
* V_318 &= V_90 ;
( * V_317 ) . V_86 = V_201 . V_86 ;
}
static enum V_87
F_151 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
enum V_88 V_90 )
{
enum V_87 V_62 = V_97 ;
union V_60 V_77 , V_76 ;
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_43 ( V_6 , V_76 , F_34 ( V_76 , V_84 , V_85 ) , NULL ) ;
if ( V_90 & V_320 && V_77 . V_34 == V_145 && V_76 . V_34 < V_145 )
V_77 . V_34 = V_76 . V_34 ;
if ( V_77 . V_86 == V_76 . V_86 )
continue;
V_62 = F_44 ( V_76 , V_77 ) ;
if ( V_62 >= V_97 && ! ( V_90 & V_92 ) ) {
V_62 = F_45 ( V_6 , V_77 ) ;
if ( V_62 < V_97 ) {
if ( F_45 ( V_6 , V_76 ) == V_62 )
V_62 = F_46 ( V_76 , V_77 , V_8 ) ;
} else
V_62 = F_46 ( V_76 , V_77 , V_8 ) ;
}
if ( V_62 < V_97 ) {
if ( V_90 & V_104 )
F_51 ( V_6 , V_76 , V_77 , V_62 ) ;
break;
}
}
F_22 () ;
return V_62 ;
}
static void
F_152 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
union V_60 * V_321 , union V_60 * V_322 , enum V_88 V_90 )
{
union V_60 V_77 , V_76 , V_309 = { } ;
union V_60 V_323 = {
{ . V_25 = V_324 ,
. V_71 = V_324 ,
. V_41 = V_85 . V_41 ,
. V_34 = V_73 ,
. V_37 = V_73
} } ;
struct V_35 * V_36 ;
enum V_87 V_62 ;
int V_9 , V_325 = 0 ;
if ( V_84 . V_41 == V_74 ) {
if ( V_8 -> V_30 != V_40 && V_85 . V_41 == V_40 )
V_8 -> V_326 = V_217 ;
V_8 -> V_30 = V_85 . V_41 ;
}
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_325 ++ ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_34 ( V_76 , V_84 , V_85 ) ;
V_77 = F_43 ( V_6 , V_76 , V_77 , NULL ) ;
if ( V_90 & V_320 && V_77 . V_34 == V_145 && V_76 . V_34 < V_145 )
V_77 . V_34 = V_76 . V_34 ;
V_62 = F_38 ( V_6 , V_77 , V_90 , NULL ) ;
if ( V_62 < V_97 )
F_153 () ;
V_77 . V_86 = V_6 -> V_33 . V_86 ;
V_309 . V_25 = F_23 ( V_77 . V_25 , V_309 . V_25 ) ;
V_309 . V_71 = F_23 ( V_77 . V_71 , V_309 . V_71 ) ;
V_309 . V_41 = F_12 ( enum V_39 , V_77 . V_41 , V_309 . V_41 ) ;
V_309 . V_34 = F_12 ( enum V_72 , V_77 . V_34 , V_309 . V_34 ) ;
V_309 . V_37 = F_12 ( enum V_72 , V_77 . V_37 , V_309 . V_37 ) ;
V_323 . V_25 = F_24 ( V_77 . V_25 , V_323 . V_25 ) ;
V_323 . V_71 = F_24 ( V_77 . V_71 , V_323 . V_71 ) ;
V_323 . V_41 = F_27 ( enum V_39 , V_77 . V_41 , V_323 . V_41 ) ;
V_323 . V_34 = F_27 ( enum V_72 , V_77 . V_34 , V_323 . V_34 ) ;
V_323 . V_37 = F_27 ( enum V_72 , V_77 . V_37 , V_323 . V_37 ) ;
}
F_22 () ;
if ( V_325 == 0 ) {
V_323 = V_309 = (union V_60 ) { {
. V_25 = V_65 ,
. V_71 = V_70 ,
. V_41 = V_85 . V_41 ,
. V_34 = V_63 ,
. V_37 = V_137
} } ;
}
V_323 . V_27 = V_309 . V_27 = V_8 -> V_2 -> V_27 ;
V_323 . V_28 = V_309 . V_28 = V_8 -> V_2 -> V_28 ;
V_323 . V_29 = V_309 . V_29 = V_8 -> V_2 -> V_29 ;
* V_321 = V_323 ;
* V_322 = V_309 ;
}
static enum V_87
F_154 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 )
{
enum V_87 V_111 , V_62 = V_98 ; ;
if ( F_42 ( V_327 , & V_8 -> V_90 ) )
V_62 = V_94 ;
if ( F_42 ( V_328 , & V_8 -> V_90 ) )
V_62 = V_96 ;
V_111 = F_151 ( V_8 , V_84 , V_85 , 0 ) ;
if ( V_111 == V_97 && V_8 -> V_30 == V_40 )
return V_62 ;
return V_111 ;
}
enum V_87
F_127 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
enum V_88 V_90 )
{
enum V_87 V_62 = V_97 ;
struct V_307 * V_308 ;
enum V_39 V_164 = V_8 -> V_30 ;
union V_60 V_309 , V_323 , V_76 ;
bool V_329 = false ;
struct V_11 * V_13 ;
if ( V_84 . V_41 ) {
V_62 = F_75 ( V_164 , V_85 . V_41 ) ;
if ( V_62 < V_97 )
goto abort;
}
V_62 = F_151 ( V_8 , V_84 , V_85 , V_90 ) ;
if ( V_62 < V_97 )
goto abort;
if ( V_164 == V_40 && V_85 . V_41 == V_82 &&
! ( V_90 & ( V_330 | V_92 ) ) ) {
F_128 ( & V_8 -> V_2 -> V_91 ) ;
F_50 ( & V_8 -> V_331 ) ;
V_329 = true ;
F_95 ( V_332 , & V_8 -> V_90 ) ;
if ( F_155 ( V_8 , V_84 , V_85 ) ) {
F_86 ( V_332 , & V_8 -> V_90 ) ;
V_62 = V_96 ;
goto V_333;
}
if ( V_85 . V_41 == V_82 )
F_95 ( V_334 , & V_8 -> V_90 ) ;
F_125 ( & V_8 -> V_2 -> V_91 ) ;
F_156 ( V_8 -> V_215 ,
( V_62 = F_154 ( V_8 , V_84 , V_85 ) ) ,
V_8 -> V_2 -> V_91 ) ;
F_86 ( V_332 , & V_8 -> V_90 ) ;
if ( V_62 < V_97 )
goto abort;
}
V_13 = F_6 ( V_8 -> V_2 , V_213 ) ;
F_150 ( V_8 , & V_76 , & V_90 ) ;
V_90 |= V_120 ;
F_152 ( V_8 , V_84 , V_85 , & V_323 , & V_309 , V_90 ) ;
F_70 ( V_8 , V_76 , V_309 , V_90 ) ;
F_13 ( V_13 ) ;
V_308 = F_5 ( sizeof( * V_308 ) , V_213 ) ;
if ( V_308 ) {
V_308 -> V_164 = V_76 . V_41 ;
V_308 -> V_323 = V_323 ;
V_308 -> V_309 = V_309 ;
V_308 -> V_90 = V_90 ;
V_308 -> V_241 . V_242 = F_144 ;
F_7 ( & V_8 -> V_24 ) ;
V_308 -> V_8 = V_8 ;
V_308 -> V_13 = V_13 ;
F_98 ( & V_8 -> V_244 , & V_308 -> V_241 ) ;
} else {
F_62 ( V_8 , L_38 ) ;
}
abort:
if ( V_329 ) {
F_128 ( & V_8 -> V_2 -> V_91 ) ;
V_333:
F_56 ( & V_8 -> V_331 ) ;
F_125 ( & V_8 -> V_2 -> V_91 ) ;
}
if ( V_62 < V_97 && V_90 & V_104 ) {
F_62 ( V_8 , L_2 , F_66 ( V_62 ) ) ;
F_62 ( V_8 , L_39 , V_84 . V_86 , V_85 . V_86 ) ;
F_62 ( V_8 , L_40 , F_63 ( V_164 ) , F_63 ( V_85 . V_41 ) ) ;
}
return V_62 ;
}
enum V_87
F_157 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
enum V_88 V_90 )
{
enum V_87 V_62 ;
F_125 ( & V_8 -> V_2 -> V_91 ) ;
V_62 = F_127 ( V_8 , V_84 , V_85 , V_90 ) ;
F_128 ( & V_8 -> V_2 -> V_91 ) ;
return V_62 ;
}
