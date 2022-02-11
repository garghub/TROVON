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
enum V_66 V_25 = V_65 ;
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
void * V_102 = NULL ;
F_49 ( & V_101 ) ;
if ( V_89 & V_103 )
F_50 ( V_6 -> V_104 ) ;
if ( V_89 & V_105 )
V_102 = F_51 ( V_6 , V_106 ) ;
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
if ( V_89 & V_107 )
F_52 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
if ( F_53 ( F_47 ( V_6 ) , V_84 , V_85 ) ) {
V_62 = V_96 ;
if ( V_89 & V_107 )
F_52 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
F_54 ( V_6 -> V_75 ,
( V_62 = F_41 ( V_6 , V_84 , V_85 ) ) ) ;
if ( V_62 < V_97 ) {
if ( V_89 & V_107 )
F_52 ( V_6 , V_76 , V_77 , V_62 ) ;
goto abort;
}
F_36 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
V_77 = F_34 ( F_37 ( V_6 ) , V_84 , V_85 ) ;
V_62 = F_38 ( V_6 , V_77 , V_89 , & V_101 ) ;
} else {
V_62 = F_38 ( V_6 , V_77 , V_89 , & V_101 ) ;
}
F_39 ( & V_6 -> V_2 -> V_91 , V_90 ) ;
if ( V_89 & V_108 && V_62 == V_97 ) {
F_55 ( V_6 , V_109 != F_47 ( V_6 ) -> V_8 -> V_110 . V_111 ) ;
F_56 ( & V_101 ) ;
}
abort:
if ( V_102 )
F_57 ( V_6 ) ;
if ( V_89 & V_103 )
F_58 ( V_6 -> V_104 ) ;
return V_62 ;
}
enum V_87
F_59 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 , enum V_88 V_89 )
{
enum V_87 V_62 ;
F_54 ( V_6 -> V_75 ,
( V_62 = F_48 ( V_6 , V_84 , V_85 , V_89 ) ) != V_112 ) ;
return V_62 ;
}
static enum V_87
F_60 ( struct V_5 * V_6 )
{
return F_48 ( V_6 , F_61 ( V_34 , V_81 ) ,
V_107 | V_113 | V_105 ) ;
}
enum V_87
F_62 ( struct V_5 * V_6 )
{
enum V_87 V_62 ;
int V_114 ;
F_63 ( V_6 ) ;
F_64 ( V_6 -> V_75 ,
( V_62 = F_60 ( V_6 ) ) != V_112 ) ;
F_65 ( V_6 ) ;
V_114 = F_64 ( V_6 -> V_115 ,
V_6 -> V_33 . V_34 != V_81 ) ;
if ( V_62 == V_116 )
V_62 = V_117 ;
if ( V_114 )
V_62 = V_118 ;
return V_62 ;
}
enum V_87
F_66 ( struct V_5 * V_6 , union V_60 V_84 ,
union V_60 V_85 , enum V_88 V_89 )
{
enum V_87 V_62 ;
F_67 ( V_89 & V_103 ) ;
F_68 ( V_6 -> V_75 ,
( V_62 = F_48 ( V_6 , V_84 , V_85 , V_89 ) ) != V_112 ,
F_58 ( V_6 -> V_104 ) ,
F_50 ( V_6 -> V_104 ) ) ;
return V_62 ;
}
static void F_69 ( struct V_5 * V_6 , const char * V_119 , union V_60 V_77 )
{
F_70 ( V_6 , L_1 ,
V_119 ,
F_71 ( V_77 . V_41 ) ,
F_72 ( V_77 . V_25 ) ,
F_72 ( V_77 . V_71 ) ,
F_73 ( V_77 . V_34 ) ,
F_73 ( V_77 . V_37 ) ,
F_19 ( V_77 ) ? 's' : 'r' ,
V_77 . V_47 ? 'a' : '-' ,
V_77 . V_45 ? 'p' : '-' ,
V_77 . V_43 ? 'u' : '-' ,
V_77 . V_29 ? 'F' : '-' ,
V_77 . V_28 ? 'N' : '-'
) ;
}
void F_52 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_87 V_120 )
{
if ( V_120 == V_112 )
return;
F_70 ( V_6 , L_2 , F_74 ( V_120 ) ) ;
F_69 ( V_6 , L_3 , V_76 ) ;
F_69 ( V_6 , L_4 , V_77 ) ;
}
static long F_75 ( char * V_121 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char * V_122 ;
V_122 = V_121 ;
* V_122 = 0 ;
if ( V_77 . V_25 != V_76 . V_25 && V_90 & V_123 )
V_122 += sprintf ( V_122 , L_5 ,
F_72 ( V_76 . V_25 ) ,
F_72 ( V_77 . V_25 ) ) ;
if ( V_77 . V_71 != V_76 . V_71 && V_90 & V_124 )
V_122 += sprintf ( V_122 , L_6 ,
F_72 ( V_76 . V_71 ) ,
F_72 ( V_77 . V_71 ) ) ;
if ( V_77 . V_41 != V_76 . V_41 && V_90 & V_125 )
V_122 += sprintf ( V_122 , L_7 ,
F_71 ( V_76 . V_41 ) ,
F_71 ( V_77 . V_41 ) ) ;
if ( V_77 . V_34 != V_76 . V_34 && V_90 & V_126 )
V_122 += sprintf ( V_122 , L_8 ,
F_73 ( V_76 . V_34 ) ,
F_73 ( V_77 . V_34 ) ) ;
if ( V_77 . V_37 != V_76 . V_37 && V_90 & V_127 )
V_122 += sprintf ( V_122 , L_9 ,
F_73 ( V_76 . V_37 ) ,
F_73 ( V_77 . V_37 ) ) ;
return V_122 - V_121 ;
}
static void F_76 ( struct V_5 * V_6 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char V_121 [ 300 ] ;
char * V_122 = V_121 ;
V_122 += F_75 ( V_122 , V_76 , V_77 , V_90 ^ V_128 ) ;
if ( V_77 . V_47 != V_76 . V_47 )
V_122 += sprintf ( V_122 , L_10 ,
V_76 . V_47 ,
V_77 . V_47 ) ;
if ( V_77 . V_45 != V_76 . V_45 )
V_122 += sprintf ( V_122 , L_11 ,
V_76 . V_45 ,
V_77 . V_45 ) ;
if ( V_77 . V_43 != V_76 . V_43 )
V_122 += sprintf ( V_122 , L_12 ,
V_76 . V_43 ,
V_77 . V_43 ) ;
if ( V_122 != V_121 )
F_77 ( V_6 , L_13 , V_121 ) ;
}
static void F_78 ( struct V_7 * V_8 , union V_60 V_76 , union V_60 V_77 ,
enum V_88 V_90 )
{
char V_121 [ 300 ] ;
char * V_122 = V_121 ;
V_122 += F_75 ( V_122 , V_76 , V_77 , V_90 ) ;
if ( F_19 ( V_77 ) != F_19 ( V_76 ) && V_90 & V_129 )
V_122 += sprintf ( V_122 , L_14 ,
F_19 ( V_76 ) ,
F_19 ( V_77 ) ) ;
if ( V_122 != V_121 )
F_77 ( V_8 , L_13 , V_121 ) ;
}
static enum V_87
F_45 ( struct V_5 * V_6 , union V_60 V_77 )
{
enum V_130 V_131 ;
enum V_87 V_62 = V_97 ;
struct V_132 * V_133 ;
F_21 () ;
V_131 = V_134 ;
if ( F_79 ( V_6 ) ) {
V_131 = F_80 ( V_6 -> V_135 -> V_136 ) -> V_137 ;
F_81 ( V_6 ) ;
}
V_133 = F_80 ( F_47 ( V_6 ) -> V_8 -> V_132 ) ;
if ( V_133 ) {
if ( ! V_133 -> V_138 && V_77 . V_25 == V_69 ) {
if ( V_77 . V_71 == V_69 )
V_62 = V_139 ;
else if ( F_10 ( F_47 ( V_6 ) -> V_8 ) == V_69 )
V_62 = V_140 ;
}
}
if ( V_62 <= 0 )
goto V_141;
else if ( V_77 . V_25 == V_65 && V_6 -> V_142 )
V_62 = V_143 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_34 < V_144 )
V_62 = V_145 ;
else if ( V_131 >= V_146 &&
V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_37 >= V_147 )
V_62 = V_148 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_34 <= V_149 && V_77 . V_37 <= V_149 )
V_62 = V_145 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_34 < V_149 )
V_62 = V_150 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_37 < V_149 )
V_62 = V_151 ;
else if ( V_77 . V_41 > V_78 && V_77 . V_34 < V_144 && V_77 . V_37 < V_144 )
V_62 = V_145 ;
else if ( ( V_77 . V_41 == V_78 ||
V_77 . V_41 == V_152 ||
V_77 . V_41 == V_153 ||
V_77 . V_41 == V_154 ) &&
V_77 . V_34 == V_155 )
V_62 = V_156 ;
else if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ) &&
( V_133 -> V_158 [ 0 ] == 0 ) )
V_62 = V_159 ;
else if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ) &&
F_47 ( V_6 ) -> V_8 -> V_160 < 88 )
V_62 = V_161 ;
else if ( V_77 . V_25 == V_69 && V_77 . V_34 < V_144 && V_77 . V_37 < V_144 )
V_62 = V_145 ;
else if ( ( V_77 . V_41 == V_80 || V_77 . V_41 == V_79 ) &&
V_77 . V_37 == V_147 )
V_62 = V_162 ;
else if ( V_77 . V_41 >= V_78 && V_77 . V_37 == V_147 )
V_62 = V_156 ;
V_141:
F_22 () ;
return V_62 ;
}
static enum V_87
F_46 ( union V_60 V_76 , union V_60 V_77 , struct V_7 * V_8 )
{
enum V_87 V_62 = V_97 ;
if ( ( V_77 . V_41 == V_79 || V_77 . V_41 == V_80 ) &&
V_76 . V_41 > V_78 )
V_62 = V_163 ;
if ( V_77 . V_41 == V_82 && V_76 . V_41 == V_64 )
V_62 = V_164 ;
if ( V_77 . V_34 > V_165 && V_76 . V_34 == V_63 )
V_62 = V_116 ;
if ( V_77 . V_41 == V_166 && V_76 . V_41 < V_167 )
V_62 = V_168 ;
if ( V_77 . V_34 == V_155 && V_76 . V_34 < V_155 && V_76 . V_34 != V_165 )
V_62 = V_169 ;
if ( V_77 . V_41 == V_82 && V_76 . V_41 == V_167 )
V_62 = V_112 ;
if ( F_82 ( V_170 , & V_8 -> V_90 ) &&
! ( ( V_77 . V_41 == V_40 && V_76 . V_41 == V_166 ) ||
( V_77 . V_41 >= V_78 && V_76 . V_41 == V_40 ) ) )
V_62 = V_112 ;
if ( V_76 . V_25 != V_69 && V_77 . V_25 == V_69
&& V_77 . V_37 == V_144
&& V_77 . V_34 != V_144 && V_77 . V_34 != V_63
&& ( V_77 . V_41 <= V_171 || V_77 . V_41 != V_76 . V_41 ) )
V_62 = V_112 ;
if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ) && V_76 . V_41 < V_78 )
V_62 = V_162 ;
if ( ( V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ) &&
V_77 . V_41 != V_76 . V_41 && V_76 . V_41 > V_78 )
V_62 = V_163 ;
if ( ( V_77 . V_41 == V_80 || V_77 . V_41 == V_79 ) &&
V_76 . V_41 < V_78 )
V_62 = V_162 ;
if ( ( V_77 . V_41 == V_172 || V_77 . V_41 == V_153 )
&& V_76 . V_41 < V_40 )
V_62 = V_162 ;
if ( V_77 . V_41 == V_82 && V_77 . V_37 == V_155 &&
V_76 . V_41 < V_78 && V_76 . V_37 > V_155 )
V_62 = V_173 ;
return V_62 ;
}
static enum V_87
F_83 ( enum V_39 V_174 , enum V_39 V_133 )
{
if ( V_174 == V_133 )
return V_117 ;
if ( V_174 == V_64 && V_133 == V_82 )
return V_164 ;
if ( V_174 == V_64 && V_133 != V_167 )
return V_162 ;
if ( V_174 < V_40 && V_133 >= V_78 )
return V_162 ;
if ( V_174 >= V_175 && V_174 <= V_176 && V_133 != V_167 && V_133 != V_82 )
return V_112 ;
if ( V_174 == V_82 && V_133 != V_64 )
return V_112 ;
return V_97 ;
}
static enum V_87
F_44 ( union V_60 V_76 , union V_60 V_77 )
{
enum V_87 V_62 ;
V_62 = F_83 ( V_76 . V_41 , V_77 . V_41 ) ;
if ( V_77 . V_34 == V_81 && V_76 . V_34 == V_63 )
V_62 = V_116 ;
return V_62 ;
}
static void F_84 ( struct V_5 * V_6 , enum V_177 V_178 )
{
static const char * V_179 [] = {
[ V_180 ] = L_15 ,
[ V_181 ] = L_16 ,
[ V_182 ] = L_17 ,
[ V_183 ] = L_18 ,
[ V_184 ] = L_19 ,
[ V_185 ] = L_20 ,
} ;
if ( V_178 != V_180 )
F_85 ( V_6 , L_13 , V_179 [ V_178 ] ) ;
}
static union V_60 F_43 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_177 * V_178 )
{
enum V_130 V_131 ;
enum V_72 V_186 , V_187 , V_188 , V_189 ;
if ( V_178 )
* V_178 = V_180 ;
V_131 = V_134 ;
if ( F_79 ( V_6 ) ) {
F_21 () ;
V_131 = F_80 ( V_6 -> V_135 -> V_136 ) -> V_137 ;
F_22 () ;
F_81 ( V_6 ) ;
}
if ( V_77 . V_41 < V_78 ) {
V_77 . V_45 = 0 ;
V_77 . V_71 = V_70 ;
if ( V_77 . V_37 > V_147 || V_77 . V_37 < V_149 )
V_77 . V_37 = V_147 ;
}
if ( V_77 . V_41 == V_64 && V_77 . V_34 == V_63 && V_77 . V_25 == V_65 )
V_77 . V_47 = 0 ;
if ( V_77 . V_41 > V_78 && ( V_77 . V_34 <= V_81 || V_77 . V_37 <= V_81 ) ) {
if ( V_178 )
* V_178 = V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ?
V_181 : V_182 ;
V_77 . V_41 = V_78 ;
}
if ( V_77 . V_41 < V_78 && V_77 . V_34 == V_190 &&
F_86 ( V_6 , V_190 ) ) {
if ( V_6 -> V_191 == V_6 -> V_135 -> V_192 . V_193 [ V_194 ] ) {
V_77 . V_34 = V_6 -> V_195 . V_34 ;
V_77 . V_37 = V_6 -> V_195 . V_37 ;
} else {
if ( V_178 )
* V_178 = V_183 ;
V_77 . V_34 = V_63 ;
V_77 . V_37 = V_147 ;
}
F_81 ( V_6 ) ;
}
if ( V_77 . V_41 >= V_78 && V_77 . V_41 < V_196 ) {
if ( V_77 . V_34 == V_197 || V_77 . V_34 == V_155 )
V_77 . V_34 = V_144 ;
if ( V_77 . V_37 == V_197 || V_77 . V_37 == V_155 )
V_77 . V_37 = V_144 ;
}
V_186 = V_63 ;
V_187 = V_144 ;
V_188 = V_149 ;
V_189 = V_147 ;
switch ( (enum V_39 ) V_77 . V_41 ) {
case V_198 :
case V_199 :
case V_79 :
case V_171 :
case V_200 :
V_186 = V_149 ;
V_187 = V_155 ;
V_188 = V_144 ;
V_189 = V_144 ;
break;
case V_83 :
case V_157 :
V_186 = V_144 ;
V_187 = V_144 ;
V_188 = V_144 ;
V_189 = V_144 ;
break;
case V_78 :
V_186 = V_63 ;
V_187 = V_144 ;
V_188 = V_63 ;
V_189 = V_144 ;
break;
case V_152 :
case V_154 :
case V_80 :
case V_196 :
V_186 = V_144 ;
V_187 = V_144 ;
V_188 = V_149 ;
V_189 = V_197 ;
break;
case V_172 :
V_186 = V_149 ;
V_187 = V_149 ;
V_188 = V_144 ;
V_189 = V_144 ;
break;
case V_153 :
V_186 = V_144 ;
V_187 = V_144 ;
V_188 = V_149 ;
V_189 = V_149 ;
break;
case V_64 :
case V_82 :
case V_167 :
case V_175 :
case V_201 :
case V_202 :
case V_203 :
case V_176 :
case V_166 :
case V_40 :
case V_74 :
break;
}
if ( V_77 . V_34 > V_187 )
V_77 . V_34 = V_187 ;
if ( V_77 . V_34 < V_186 ) {
if ( V_178 )
* V_178 = V_184 ;
V_77 . V_34 = V_186 ;
}
if ( V_77 . V_37 > V_189 )
V_77 . V_37 = V_189 ;
if ( V_77 . V_37 < V_188 ) {
if ( V_178 )
* V_178 = V_185 ;
V_77 . V_37 = V_188 ;
}
if ( V_131 == V_204 &&
( V_77 . V_25 == V_69 && V_77 . V_41 < V_78 && V_77 . V_37 > V_155 ) &&
! ( V_76 . V_25 == V_69 && V_76 . V_41 < V_78 && V_76 . V_37 > V_155 ) )
V_77 . V_29 = 1 ;
if ( V_6 -> V_2 -> V_205 . V_206 == V_207 &&
( V_77 . V_25 == V_69 && V_77 . V_34 < V_144 && V_77 . V_37 < V_144 ) &&
! ( V_76 . V_25 == V_69 && V_76 . V_34 < V_144 && V_76 . V_37 < V_144 ) )
V_77 . V_28 = 1 ;
if ( V_77 . V_47 || V_77 . V_45 || V_77 . V_43 ) {
if ( V_77 . V_41 == V_153 )
V_77 . V_41 = V_154 ;
if ( V_77 . V_41 == V_172 )
V_77 . V_41 = V_199 ;
} else {
if ( V_77 . V_41 == V_154 )
V_77 . V_41 = V_153 ;
if ( V_77 . V_41 == V_199 )
V_77 . V_41 = V_172 ;
}
return V_77 ;
}
void F_87 ( struct V_5 * V_6 )
{
if ( F_42 ( V_208 , & V_6 -> V_90 ) )
F_77 ( V_6 , L_21 ) ;
}
static void F_88 ( struct V_5 * V_6 , enum V_39 V_209 )
{
if ( F_47 ( V_6 ) -> V_8 -> V_160 < 90 )
V_6 -> V_210 = 0 ;
V_6 -> V_211 = F_89 ( V_6 ) ;
V_6 -> V_212 = 0 ;
if ( V_209 == V_157 ) {
V_6 -> V_210 = ~ ( V_213 ) 0 ;
} else {
unsigned long V_214 = F_90 ( V_6 -> V_210 ) ;
if ( V_214 >= V_6 -> V_211 ) {
V_6 -> V_210 =
F_91 ( V_6 -> V_211 - 1 ) ;
V_6 -> V_211 = 1 ;
} else
V_6 -> V_211 -= V_214 ;
V_6 -> V_212 = V_6 -> V_210 ;
}
V_6 -> V_215 = V_6 -> V_211 ;
}
enum V_87
F_38 ( struct V_5 * V_6 , union V_60 V_77 ,
enum V_88 V_90 , struct V_100 * V_101 )
{
struct V_35 * V_36 = F_47 ( V_6 ) ;
struct V_7 * V_8 = V_36 ? V_36 -> V_8 : NULL ;
union V_60 V_76 ;
enum V_87 V_62 = V_97 ;
enum V_177 V_216 ;
struct V_217 * V_218 ;
struct V_11 * V_13 ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_43 ( V_6 , V_76 , V_77 , & V_216 ) ;
if ( V_77 . V_86 == V_76 . V_86 )
return V_117 ;
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
if ( V_90 & V_107 )
F_52 ( V_6 , V_76 , V_77 , V_62 ) ;
return V_62 ;
}
F_84 ( V_6 , V_216 ) ;
F_76 ( V_6 , V_76 , V_77 , V_90 ) ;
if ( ! ( V_90 & V_129 ) )
F_78 ( V_8 , V_76 , V_77 ,
( V_90 & ~ V_128 ) | V_129 ) ;
if ( ( V_76 . V_34 != V_81 && V_77 . V_34 == V_81 ) ||
( V_76 . V_34 != V_63 && V_77 . V_34 == V_63 ) )
F_92 ( & V_6 -> V_219 ) ;
if ( ! F_93 ( V_76 . V_41 ) && F_93 ( V_77 . V_41 ) )
F_94 ( V_220 , & V_6 -> V_90 ) ;
V_13 = F_6 ( V_6 -> V_2 , V_221 ) ;
F_95 () ;
V_6 -> V_33 . V_86 = V_77 . V_86 ;
V_6 -> V_2 -> V_27 = V_77 . V_27 ;
V_6 -> V_2 -> V_28 = V_77 . V_28 ;
V_6 -> V_2 -> V_29 = V_77 . V_29 ;
F_95 () ;
F_13 ( V_13 ) ;
if ( F_96 ( (union V_51 ) V_76 . V_86 ) !=
F_96 ( (union V_51 ) V_77 . V_86 ) )
F_97 ( V_8 ) ;
if ( V_76 . V_34 == V_165 && V_77 . V_34 >= V_190 )
F_98 ( V_6 , L_22 ) ;
if ( V_76 . V_41 == V_40 && V_77 . V_41 != V_40 &&
F_30 ( V_8 ) ) {
F_94 ( V_170 , & V_8 -> V_90 ) ;
F_31 ( V_8 ) ;
}
F_32 ( & V_6 -> V_115 ) ;
F_32 ( & V_6 -> V_75 ) ;
F_32 ( & V_8 -> V_222 ) ;
if ( ( V_76 . V_41 == V_83 || V_76 . V_41 == V_157 ) &&
V_77 . V_41 <= V_78 ) {
V_6 -> V_210 =
F_91 ( F_89 ( V_6 ) - V_6 -> V_215 ) ;
if ( V_6 -> V_215 )
F_77 ( V_6 , L_23 ,
( unsigned long long ) V_6 -> V_210 ) ;
}
if ( ( V_76 . V_41 == V_199 || V_76 . V_41 == V_154 ) &&
( V_77 . V_41 == V_172 || V_77 . V_41 == V_153 ) ) {
F_77 ( V_6 , L_24 ) ;
V_6 -> V_223 += ( long ) V_224
- ( long ) V_6 -> V_225 [ V_6 -> V_226 ] ;
if ( V_77 . V_41 == V_172 )
F_99 ( & V_6 -> V_227 , V_224 ) ;
}
if ( ( V_76 . V_41 == V_172 || V_76 . V_41 == V_153 ) &&
( V_77 . V_41 == V_199 || V_77 . V_41 == V_154 ) ) {
F_77 ( V_6 , L_25 ) ;
V_6 -> V_225 [ V_6 -> V_226 ] = V_224 ;
}
if ( V_76 . V_41 == V_78 &&
( V_77 . V_41 == V_83 || V_77 . V_41 == V_157 ) ) {
unsigned long V_228 = V_224 ;
int V_86 ;
F_88 ( V_6 , V_77 . V_41 ) ;
V_6 -> V_229 = V_228 ;
V_6 -> V_230 = 0 ;
V_6 -> V_231 = 0 ;
V_6 -> V_232 = 0 ;
for ( V_86 = 0 ; V_86 < V_233 ; V_86 ++ ) {
V_6 -> V_234 [ V_86 ] = V_6 -> V_215 ;
V_6 -> V_225 [ V_86 ] = V_228 ;
}
F_100 ( V_6 ) ;
if ( V_77 . V_41 == V_83 ) {
F_77 ( V_6 , L_26 ,
( unsigned long long ) V_6 -> V_212 ) ;
F_99 ( & V_6 -> V_227 , V_224 ) ;
}
}
if ( F_79 ( V_6 ) ) {
T_3 V_235 = V_6 -> V_135 -> V_192 . V_90 & ~ ( V_236 | V_237 |
V_238 | V_239 |
V_240 | V_241 ) ;
V_235 &= ~ V_242 ;
if ( F_82 ( V_243 , & V_6 -> V_90 ) )
V_235 |= V_241 ;
if ( V_6 -> V_33 . V_25 == V_69 ||
( V_6 -> V_33 . V_37 < V_149 && V_6 -> V_33 . V_71 == V_69 ) )
V_235 |= V_237 ;
if ( V_6 -> V_33 . V_41 > V_40 )
V_235 |= V_238 ;
if ( V_6 -> V_33 . V_34 > V_149 )
V_235 |= V_236 ;
if ( V_6 -> V_33 . V_34 > V_155 )
V_235 |= V_239 ;
if ( V_6 -> V_33 . V_37 <= V_155 && V_6 -> V_33 . V_37 >= V_149 )
V_235 |= V_240 ;
if ( V_235 != V_6 -> V_135 -> V_192 . V_90 ) {
V_6 -> V_135 -> V_192 . V_90 = V_235 ;
F_101 ( V_6 ) ;
}
if ( V_76 . V_34 < V_197 && V_77 . V_34 >= V_197 )
F_102 ( V_6 , V_6 -> V_135 -> V_192 . V_193 [ V_194 ] ) ;
F_81 ( V_6 ) ;
}
if ( V_76 . V_34 == V_149 && V_76 . V_37 == V_149 &&
V_76 . V_71 == V_65 && V_77 . V_71 == V_69 )
F_103 ( V_244 , & V_6 -> V_90 ) ;
if ( V_76 . V_41 != V_82 && V_77 . V_41 == V_82 )
F_104 ( & V_8 -> V_245 ) ;
if ( V_76 . V_41 != V_64 && V_77 . V_41 == V_64 )
F_104 ( & V_8 -> V_245 ) ;
if ( V_76 . V_41 > V_166 &&
V_77 . V_41 <= V_176 && V_77 . V_41 >= V_175 )
F_105 ( & V_8 -> V_245 ) ;
if ( V_76 . V_41 < V_78 && V_77 . V_41 >= V_78 ) {
F_87 ( V_6 ) ;
V_8 -> V_246 ++ ;
}
if ( ( V_76 . V_34 == V_165 || V_76 . V_34 == V_190 ) &&
V_77 . V_34 > V_190 )
V_6 -> V_247 = V_224 ;
V_218 = F_5 ( sizeof( * V_218 ) , V_221 ) ;
if ( V_218 ) {
V_218 -> V_76 = V_76 ;
V_218 -> V_77 = V_77 ;
V_218 -> V_90 = V_90 ;
V_218 -> V_248 . V_249 = V_250 ;
V_218 -> V_6 = V_6 ;
V_218 -> V_101 = V_101 ;
V_218 -> V_13 = V_13 ;
F_106 ( & V_8 -> V_251 ,
& V_218 -> V_248 ) ;
} else {
F_70 ( V_6 , L_27 ) ;
}
return V_62 ;
}
static int V_250 ( struct V_252 * V_248 , int V_253 )
{
struct V_217 * V_218 =
F_107 ( V_248 , struct V_217 , V_248 ) ;
struct V_5 * V_6 = V_218 -> V_6 ;
F_108 ( V_6 , V_218 -> V_76 , V_218 -> V_77 , V_218 -> V_90 , V_218 -> V_13 ) ;
F_16 ( V_218 -> V_13 ) ;
if ( V_218 -> V_90 & V_108 )
F_109 ( V_218 -> V_101 ) ;
F_18 ( V_218 ) ;
return 0 ;
}
static void F_110 ( struct V_5 * V_6 , int V_62 )
{
if ( V_62 ) {
F_70 ( V_6 , L_28 ) ;
F_59 ( V_6 , F_61 ( V_41 , V_78 ) , V_107 ) ;
return;
}
switch ( V_6 -> V_33 . V_41 ) {
case V_79 :
F_59 ( V_6 , F_61 ( V_41 , V_171 ) , V_107 ) ;
break;
case V_80 :
F_111 ( V_6 , V_153 ) ;
break;
}
}
int F_112 ( struct V_5 * V_6 ,
int (* F_113)( struct V_5 * ) ,
char * V_254 , enum V_255 V_90 )
{
int V_62 ;
F_55 ( V_6 , V_109 == F_47 ( V_6 ) -> V_8 -> V_110 . V_111 ) ;
F_92 ( & V_6 -> V_256 ) ;
F_114 ( V_6 , V_254 , V_90 ) ;
V_62 = F_113 ( V_6 ) ;
F_115 ( V_6 ) ;
F_65 ( V_6 ) ;
return V_62 ;
}
void F_116 ( struct V_257 * V_258 ,
unsigned int V_259 ,
struct V_48 * V_49 ,
enum V_260 type )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_261 V_261 = {
. V_262 = V_49 -> V_25 [ V_50 ] ,
. V_263 = V_49 -> V_27 [ V_50 ] ,
. V_264 = V_49 -> V_28 [ V_50 ] ,
. V_265 = V_49 -> V_29 [ V_50 ] ,
} ;
F_117 ( V_258 , V_259 , V_2 , & V_261 , type ) ;
}
void F_118 ( struct V_257 * V_258 ,
unsigned int V_259 ,
struct V_17 * V_23 ,
enum V_260 type )
{
struct V_7 * V_8 = V_23 -> V_8 ;
struct V_266 V_266 = {
. V_267 = V_23 -> V_30 [ V_50 ] ,
. V_268 = V_23 -> V_31 [ V_50 ] ,
} ;
F_119 ( V_258 , V_259 , V_8 , & V_266 , type ) ;
}
void F_120 ( struct V_257 * V_258 ,
unsigned int V_259 ,
struct V_16 * V_21 ,
enum V_260 type )
{
struct V_5 * V_6 = V_21 -> V_6 ;
struct V_269 V_269 = {
. V_270 = V_21 -> V_32 [ V_50 ] ,
} ;
F_121 ( V_258 , V_259 , V_6 , & V_269 , type ) ;
}
void F_122 ( struct V_257 * V_258 ,
unsigned int V_259 ,
struct V_18 * V_56 ,
enum V_260 type )
{
struct V_35 * V_36 = V_56 -> V_36 ;
struct V_271 V_271 = {
. V_272 = V_56 -> V_38 [ V_50 ] ,
. V_273 = V_56 -> V_32 [ V_50 ] ,
. V_274 = V_56 -> V_42 [ V_50 ] ,
. V_275 = V_56 -> V_44 [ V_50 ] ,
. V_276 = V_56 -> V_46 [ V_50 ] ,
} ;
F_123 ( V_258 , V_259 , V_36 , & V_271 , type ) ;
}
static void F_124 ( struct V_11 * V_13 )
{
struct V_48 * V_49 = & V_13 -> V_2 [ 0 ] ;
bool V_277 ;
unsigned int V_52 , V_53 , V_54 , V_55 ;
void (* F_125)( struct V_257 * , unsigned int , void * ,
enum V_260 ) = NULL ;
void * V_278 ( V_279 ) ;
#define F_126 ( V_33 ) ((state)[OLD] != (state)[NEW])
#define F_127 ( type ) \
({ if (last_func) \
last_func(NULL, 0, last_arg, type); \
})
#define F_128 ( T_4 , T_5 , type ) \
({ FINAL_STATE_CHANGE(type | NOTIFY_CONTINUES); \
last_func = (typeof(last_func))func; \
last_arg = arg; \
})
F_50 ( & V_280 ) ;
V_277 =
F_126 ( V_49 -> V_25 ) ||
F_126 ( V_49 -> V_27 ) ||
F_126 ( V_49 -> V_28 ) ||
F_126 ( V_49 -> V_29 ) ;
if ( V_277 )
F_128 ( F_116 ,
V_49 , V_281 ) ;
for ( V_53 = 0 ; V_53 < V_13 -> V_4 ; V_53 ++ ) {
struct V_17 * V_23 =
& V_13 -> V_19 [ V_53 ] ;
if ( F_126 ( V_23 -> V_31 ) ||
F_126 ( V_23 -> V_30 ) )
F_128 ( F_118 ,
V_23 , V_281 ) ;
}
for ( V_52 = 0 ; V_52 < V_13 -> V_3 ; V_52 ++ ) {
struct V_16 * V_21 =
& V_13 -> V_10 [ V_52 ] ;
if ( F_126 ( V_21 -> V_32 ) )
F_128 ( F_120 ,
V_21 , V_281 ) ;
}
V_55 = V_13 -> V_3 * V_13 -> V_4 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
struct V_18 * V_56 =
& V_13 -> V_20 [ V_54 ] ;
if ( F_126 ( V_56 -> V_32 ) ||
F_126 ( V_56 -> V_38 ) ||
F_126 ( V_56 -> V_42 ) ||
F_126 ( V_56 -> V_44 ) ||
F_126 ( V_56 -> V_46 ) )
F_128 ( F_122 ,
V_56 , V_281 ) ;
}
F_127 ( V_281 ) ;
F_58 ( & V_280 ) ;
#undef F_126
#undef F_127
#undef F_128
}
static bool F_129 ( enum V_72 V_76 , enum V_72 V_77 )
{
if ( ( V_76 >= V_149 && V_76 != V_147 && V_76 != V_155 )
&& ( V_77 < V_149 || V_77 == V_147 || V_77 == V_155 ) )
return true ;
if ( V_76 == V_147
&& ( V_77 == V_63 || V_77 == V_81 || V_77 == V_155 ) )
return true ;
return false ;
}
static void F_108 ( struct V_5 * V_6 , union V_60 V_76 ,
union V_60 V_77 , enum V_88 V_90 ,
struct V_11 * V_13 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
struct V_35 * V_36 = F_47 ( V_6 ) ;
struct V_7 * V_8 = V_36 ? V_36 -> V_8 : NULL ;
struct V_282 V_283 ;
F_124 ( V_13 ) ;
V_283 . V_284 = V_285 ;
V_283 . V_76 = V_76 ;
V_283 . V_77 = V_77 ;
if ( ( V_76 . V_34 != V_144 || V_76 . V_37 != V_144 )
&& ( V_77 . V_34 == V_144 && V_77 . V_37 == V_144 ) ) {
F_94 ( V_243 , & V_6 -> V_90 ) ;
if ( V_6 -> V_286 )
V_6 -> V_286 [ V_287 ] &= ~ ( ( V_288 ) 2 ) ;
}
F_130 ( V_6 , & V_283 ) ;
if ( ! ( V_76 . V_25 == V_69 && V_76 . V_34 < V_144 && V_76 . V_37 < V_144 ) &&
( V_77 . V_25 == V_69 && V_77 . V_34 < V_144 && V_77 . V_37 < V_144 ) )
F_131 ( V_6 , L_29 ) ;
if ( V_77 . V_28 ) {
enum V_289 V_290 = V_291 ;
F_132 ( & V_6 -> V_2 -> V_91 ) ;
if ( V_76 . V_41 < V_78 && F_29 ( V_8 ) >= V_78 )
V_290 = V_292 ;
if ( ( V_76 . V_34 == V_165 || V_76 . V_34 == V_190 ) &&
F_26 ( V_8 ) == V_144 )
V_290 = V_293 ;
if ( V_2 -> V_28 && V_290 != V_291 ) {
F_133 ( V_8 , V_290 ) ;
F_134 (connection,
(union drbd_state) { { .susp_nod = 1 } },
(union drbd_state) { { .susp_nod = 0 } },
CS_VERBOSE) ;
}
F_135 ( & V_6 -> V_2 -> V_91 ) ;
}
if ( V_77 . V_29 ) {
F_132 ( & V_6 -> V_2 -> V_91 ) ;
if ( V_2 -> V_29 && F_29 ( V_8 ) >= V_78 ) {
struct V_35 * V_36 ;
int V_9 ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr)
F_94 ( V_294 , & V_36 -> V_6 -> V_90 ) ;
F_22 () ;
F_133 ( V_8 , V_292 ) ;
F_134 (connection,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
}
F_135 ( & V_6 -> V_2 -> V_91 ) ;
}
if ( ( V_76 . V_41 != V_153 && V_76 . V_41 != V_154 ) &&
( V_77 . V_41 == V_153 || V_77 . V_41 == V_154 ) &&
V_8 -> V_160 >= 96 && F_79 ( V_6 ) ) {
F_136 ( V_36 ) ;
F_81 ( V_6 ) ;
}
if ( V_76 . V_37 == V_63 &&
V_77 . V_37 > V_63 && V_77 . V_37 != V_147 ) {
V_6 -> V_211 = 0 ;
V_6 -> V_295 = 0 ;
F_137 ( & V_6 -> V_296 , 0 ) ;
F_138 ( V_6 ) ;
F_139 ( V_36 ) ;
F_140 ( V_36 , V_77 ) ;
}
if ( V_76 . V_41 != V_152 && V_77 . V_41 == V_152 &&
V_6 -> V_33 . V_41 == V_152 )
F_141 ( V_6 , & V_297 , NULL ,
L_30 ,
V_298 ) ;
if ( F_129 ( V_76 . V_37 , V_77 . V_37 ) ) {
if ( F_79 ( V_6 ) ) {
if ( ( V_77 . V_25 == V_69 || V_77 . V_71 == V_69 ) &&
V_6 -> V_135 -> V_192 . V_193 [ V_299 ] == 0 && V_77 . V_34 >= V_144 ) {
if ( F_142 ( V_6 ) ) {
F_103 ( V_294 , & V_6 -> V_90 ) ;
} else {
F_143 ( V_6 ) ;
F_139 ( V_36 ) ;
}
}
F_81 ( V_6 ) ;
}
}
if ( V_77 . V_37 < V_149 && F_79 ( V_6 ) ) {
if ( V_76 . V_71 != V_69 && V_77 . V_71 == V_69 &&
V_6 -> V_135 -> V_192 . V_193 [ V_299 ] == 0 && V_77 . V_34 >= V_144 ) {
F_143 ( V_6 ) ;
F_139 ( V_36 ) ;
}
if ( V_76 . V_71 == V_69 && V_77 . V_71 == V_65 )
F_112 ( V_6 , & V_300 ,
L_31 , V_301 ) ;
F_81 ( V_6 ) ;
}
if ( V_76 . V_25 == V_69 && V_77 . V_25 == V_65 &&
V_6 -> V_33 . V_41 <= V_78 && F_79 ( V_6 ) ) {
F_112 ( V_6 , & V_300 ,
L_32 , V_298 ) ;
F_81 ( V_6 ) ;
}
if ( V_77 . V_41 >= V_78 &&
V_76 . V_34 == V_165 && V_77 . V_34 == V_190 ) {
F_144 ( V_36 , 0 , 0 ) ;
F_139 ( V_36 ) ;
F_140 ( V_36 , V_77 ) ;
}
if ( V_77 . V_41 >= V_78 &&
( ( V_76 . V_47 != V_77 . V_47 ) ||
( V_76 . V_43 != V_77 . V_43 ) ) )
F_140 ( V_36 , V_77 ) ;
if ( ( ! V_76 . V_47 && ! V_76 . V_45 && ! V_76 . V_43 ) &&
( V_77 . V_47 || V_77 . V_45 || V_77 . V_43 ) )
F_145 ( V_6 ) ;
if ( V_76 . V_41 == V_40 && V_77 . V_41 >= V_78 )
F_140 ( V_36 , V_77 ) ;
if ( V_76 . V_41 != V_196 && V_77 . V_41 == V_196 )
F_140 ( V_36 , V_77 ) ;
if ( ( V_76 . V_41 != V_79 && V_77 . V_41 == V_79 ) ||
( V_76 . V_41 != V_80 && V_77 . V_41 == V_80 ) )
F_141 ( V_6 ,
& V_302 , & F_110 ,
L_33 , V_298 ) ;
if ( V_76 . V_34 != V_81 && V_77 . V_34 == V_81 ) {
enum V_303 V_304 = V_305 ;
int V_306 = 0 ;
if ( V_6 -> V_135 ) {
F_21 () ;
V_304 = F_80 ( V_6 -> V_135 -> V_136 ) -> V_307 ;
F_22 () ;
V_306 = F_42 ( V_308 , & V_6 -> V_90 ) ;
if ( V_306 && V_304 == V_309 )
F_131 ( V_6 , L_34 ) ;
if ( F_42 ( V_310 , & V_6 -> V_90 ) )
F_146 ( V_6 ) ;
if ( V_6 -> V_33 . V_34 != V_81 )
F_70 ( V_6 ,
L_35 ,
F_73 ( V_6 -> V_33 . V_34 ) ) ;
if ( V_77 . V_41 >= V_78 )
F_140 ( V_36 , V_77 ) ;
F_138 ( V_6 ) ;
F_147 ( V_6 ) ;
}
F_81 ( V_6 ) ;
}
if ( V_76 . V_34 != V_63 && V_77 . V_34 == V_63 ) {
if ( V_6 -> V_33 . V_34 != V_63 )
F_70 ( V_6 ,
L_36 ,
F_73 ( V_6 -> V_33 . V_34 ) ) ;
if ( V_77 . V_41 >= V_78 )
F_140 ( V_36 , V_77 ) ;
F_81 ( V_6 ) ;
}
if ( V_76 . V_34 == V_144 && V_77 . V_34 == V_149 && V_77 . V_41 >= V_78 )
F_140 ( V_36 , V_77 ) ;
if ( V_77 . V_34 > V_190 && V_77 . V_37 > V_190 &&
F_42 ( V_311 , & V_6 -> V_90 ) ) {
if ( V_77 . V_41 == V_78 )
F_148 ( V_6 ) ;
}
if ( ( V_76 . V_41 > V_78 && V_77 . V_41 <= V_78 ) ||
( V_76 . V_45 && ! V_77 . V_45 ) ||
( V_76 . V_43 && ! V_77 . V_43 ) )
F_149 ( V_6 ) ;
if ( V_76 . V_34 < V_144 && V_76 . V_41 >= V_153 && V_77 . V_41 == V_78 )
F_140 ( V_36 , V_77 ) ;
if ( V_76 . V_41 == V_83 && V_77 . V_41 == V_78
&& F_150 ( V_6 ) )
F_140 ( V_36 , V_77 ) ;
if ( ( V_76 . V_41 > V_78 && V_76 . V_41 < V_196 ) &&
( V_77 . V_41 == V_78 || V_77 . V_41 >= V_196 ) && F_79 ( V_6 ) ) {
F_141 ( V_6 , & V_312 , NULL ,
L_37 , V_313 ) ;
F_81 ( V_6 ) ;
}
if ( V_77 . V_34 == V_63 &&
V_77 . V_41 == V_64 &&
V_77 . V_25 == V_65 ) {
if ( V_76 . V_47 != V_77 . V_47 )
F_149 ( V_6 ) ;
}
F_147 ( V_6 ) ;
}
static int F_151 ( struct V_252 * V_248 , int V_253 )
{
struct V_314 * V_315 =
F_107 ( V_248 , struct V_314 , V_248 ) ;
struct V_7 * V_8 = V_315 -> V_8 ;
enum V_39 V_174 = V_315 -> V_174 ;
union V_60 V_316 = V_315 -> V_316 ;
struct V_35 * V_36 ;
int V_9 ;
F_124 ( V_315 -> V_13 ) ;
F_16 ( V_315 -> V_13 ) ;
F_18 ( V_315 ) ;
if ( V_174 == V_64 && V_316 . V_41 == V_167 )
F_152 ( & V_8 -> V_245 ) ;
if ( V_174 == V_82 && V_316 . V_41 == V_64 ) {
struct V_132 * V_317 ;
F_50 ( & V_280 ) ;
F_2 (&connection->peer_devices, peer_device, vnr)
F_123 ( NULL , 0 , V_36 , NULL ,
V_318 | V_319 ) ;
F_119 ( NULL , 0 , V_8 , NULL , V_318 ) ;
F_58 ( & V_280 ) ;
F_50 ( & V_8 -> V_2 -> V_320 ) ;
V_317 = V_8 -> V_132 ;
V_8 -> V_321 = 0 ;
V_8 -> V_322 = 0 ;
F_153 ( V_8 -> V_132 , NULL ) ;
F_154 ( V_8 ) ;
F_58 ( & V_8 -> V_2 -> V_320 ) ;
F_155 () ;
F_18 ( V_317 ) ;
}
if ( V_316 . V_29 ) {
if ( V_316 . V_37 <= V_155 ) {
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
if ( F_82 ( V_294 , & V_6 -> V_90 ) ) {
F_143 ( V_6 ) ;
F_94 ( V_294 , & V_6 -> V_90 ) ;
}
}
F_22 () ;
F_132 ( & V_8 -> V_2 -> V_91 ) ;
F_133 ( V_8 , V_323 ) ;
F_134 (connection,
(union drbd_state) { { .susp_fen = 1 } },
(union drbd_state) { { .susp_fen = 0 } },
CS_VERBOSE) ;
F_135 ( & V_8 -> V_2 -> V_91 ) ;
}
}
F_17 ( & V_8 -> V_24 , V_59 ) ;
F_156 ( V_8 ) ;
return 0 ;
}
static void F_157 ( struct V_7 * V_8 , union V_60 * V_324 , enum V_88 * V_325 )
{
enum V_88 V_90 = ~ 0 ;
struct V_35 * V_36 ;
int V_9 , V_326 = 1 ;
union V_51 V_76 , V_209 = {
{ . V_25 = V_65 ,
. V_71 = V_70 ,
. V_41 = V_8 -> V_30 ,
. V_34 = V_63 ,
. V_37 = V_147 ,
} } ;
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_76 = V_6 -> V_33 ;
if ( V_326 ) {
V_209 = V_76 ;
V_326 = 0 ;
continue;
}
if ( V_209 . V_25 != V_76 . V_25 )
V_90 &= ~ V_123 ;
if ( V_209 . V_71 != V_76 . V_71 )
V_90 &= ~ V_124 ;
if ( V_209 . V_41 != V_76 . V_41 )
V_90 &= ~ V_125 ;
if ( V_209 . V_34 != V_76 . V_34 )
V_90 &= ~ V_126 ;
if ( V_209 . V_37 != V_76 . V_37 )
V_90 &= ~ V_127 ;
}
F_22 () ;
* V_325 |= V_128 ;
* V_325 &= V_90 ;
( * V_324 ) . V_86 = V_209 . V_86 ;
}
static enum V_87
F_158 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
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
if ( V_90 & V_327 && V_77 . V_34 == V_155 && V_76 . V_34 < V_155 )
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
if ( V_90 & V_107 )
F_52 ( V_6 , V_76 , V_77 , V_62 ) ;
break;
}
}
F_22 () ;
return V_62 ;
}
static void
F_159 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
union V_60 * V_328 , union V_60 * V_329 , enum V_88 V_90 )
{
union V_60 V_77 , V_76 , V_316 = { } ;
union V_60 V_330 = {
{ . V_25 = V_331 ,
. V_71 = V_331 ,
. V_41 = V_85 . V_41 ,
. V_34 = V_73 ,
. V_37 = V_73
} } ;
struct V_35 * V_36 ;
enum V_87 V_62 ;
int V_9 , V_332 = 0 ;
if ( V_84 . V_41 == V_74 ) {
if ( V_8 -> V_30 != V_40 && V_85 . V_41 == V_40 )
V_8 -> V_333 = V_224 ;
V_8 -> V_30 = V_85 . V_41 ;
}
F_21 () ;
F_2 (&connection->peer_devices, peer_device, vnr) {
struct V_5 * V_6 = V_36 -> V_6 ;
V_332 ++ ;
V_76 = F_37 ( V_6 ) ;
V_77 = F_34 ( V_76 , V_84 , V_85 ) ;
V_77 = F_43 ( V_6 , V_76 , V_77 , NULL ) ;
if ( V_90 & V_327 && V_77 . V_34 == V_155 && V_76 . V_34 < V_155 )
V_77 . V_34 = V_76 . V_34 ;
V_62 = F_38 ( V_6 , V_77 , V_90 , NULL ) ;
F_67 ( V_62 < V_97 ) ;
V_77 . V_86 = V_6 -> V_33 . V_86 ;
V_316 . V_25 = F_23 ( V_77 . V_25 , V_316 . V_25 ) ;
V_316 . V_71 = F_23 ( V_77 . V_71 , V_316 . V_71 ) ;
V_316 . V_41 = F_12 ( enum V_39 , V_77 . V_41 , V_316 . V_41 ) ;
V_316 . V_34 = F_12 ( enum V_72 , V_77 . V_34 , V_316 . V_34 ) ;
V_316 . V_37 = F_12 ( enum V_72 , V_77 . V_37 , V_316 . V_37 ) ;
V_330 . V_25 = F_24 ( V_77 . V_25 , V_330 . V_25 ) ;
V_330 . V_71 = F_24 ( V_77 . V_71 , V_330 . V_71 ) ;
V_330 . V_41 = F_27 ( enum V_39 , V_77 . V_41 , V_330 . V_41 ) ;
V_330 . V_34 = F_27 ( enum V_72 , V_77 . V_34 , V_330 . V_34 ) ;
V_330 . V_37 = F_27 ( enum V_72 , V_77 . V_37 , V_330 . V_37 ) ;
}
F_22 () ;
if ( V_332 == 0 ) {
V_330 = V_316 = (union V_60 ) { {
. V_25 = V_65 ,
. V_71 = V_70 ,
. V_41 = V_85 . V_41 ,
. V_34 = V_63 ,
. V_37 = V_147
} } ;
}
V_330 . V_27 = V_316 . V_27 = V_8 -> V_2 -> V_27 ;
V_330 . V_28 = V_316 . V_28 = V_8 -> V_2 -> V_28 ;
V_330 . V_29 = V_316 . V_29 = V_8 -> V_2 -> V_29 ;
* V_328 = V_330 ;
* V_329 = V_316 ;
}
static enum V_87
F_160 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 )
{
enum V_87 V_120 , V_62 = V_98 ; ;
if ( F_42 ( V_334 , & V_8 -> V_90 ) )
V_62 = V_94 ;
if ( F_42 ( V_335 , & V_8 -> V_90 ) )
V_62 = V_96 ;
V_120 = F_158 ( V_8 , V_84 , V_85 , 0 ) ;
if ( V_120 == V_97 && V_8 -> V_30 == V_40 )
return V_62 ;
return V_120 ;
}
enum V_87
F_134 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
enum V_88 V_90 )
{
enum V_87 V_62 = V_97 ;
struct V_314 * V_315 ;
enum V_39 V_174 = V_8 -> V_30 ;
union V_60 V_316 , V_330 , V_76 ;
bool V_336 = false ;
struct V_11 * V_13 ;
if ( V_84 . V_41 ) {
V_62 = F_83 ( V_174 , V_85 . V_41 ) ;
if ( V_62 < V_97 )
goto abort;
}
V_62 = F_158 ( V_8 , V_84 , V_85 , V_90 ) ;
if ( V_62 < V_97 )
goto abort;
if ( V_174 == V_40 && V_85 . V_41 == V_82 &&
! ( V_90 & ( V_337 | V_92 ) ) ) {
F_135 ( & V_8 -> V_2 -> V_91 ) ;
F_50 ( & V_8 -> V_338 ) ;
V_336 = true ;
F_103 ( V_339 , & V_8 -> V_90 ) ;
if ( F_161 ( V_8 , V_84 , V_85 ) ) {
F_94 ( V_339 , & V_8 -> V_90 ) ;
V_62 = V_96 ;
goto V_340;
}
if ( V_85 . V_41 == V_82 )
F_103 ( V_341 , & V_8 -> V_90 ) ;
F_132 ( & V_8 -> V_2 -> V_91 ) ;
F_162 ( V_8 -> V_222 ,
( V_62 = F_160 ( V_8 , V_84 , V_85 ) ) ,
V_8 -> V_2 -> V_91 ) ;
F_94 ( V_339 , & V_8 -> V_90 ) ;
if ( V_62 < V_97 )
goto abort;
}
V_13 = F_6 ( V_8 -> V_2 , V_221 ) ;
F_157 ( V_8 , & V_76 , & V_90 ) ;
V_90 |= V_129 ;
F_159 ( V_8 , V_84 , V_85 , & V_330 , & V_316 , V_90 ) ;
F_78 ( V_8 , V_76 , V_316 , V_90 ) ;
F_13 ( V_13 ) ;
V_315 = F_5 ( sizeof( * V_315 ) , V_221 ) ;
if ( V_315 ) {
V_315 -> V_174 = V_76 . V_41 ;
V_315 -> V_330 = V_330 ;
V_315 -> V_316 = V_316 ;
V_315 -> V_90 = V_90 ;
V_315 -> V_248 . V_249 = F_151 ;
F_7 ( & V_8 -> V_24 ) ;
V_315 -> V_8 = V_8 ;
V_315 -> V_13 = V_13 ;
F_106 ( & V_8 -> V_251 , & V_315 -> V_248 ) ;
} else {
F_70 ( V_8 , L_38 ) ;
}
abort:
if ( V_336 ) {
F_135 ( & V_8 -> V_2 -> V_91 ) ;
V_340:
F_58 ( & V_8 -> V_338 ) ;
F_132 ( & V_8 -> V_2 -> V_91 ) ;
}
if ( V_62 < V_97 && V_90 & V_107 ) {
F_70 ( V_8 , L_2 , F_74 ( V_62 ) ) ;
F_70 ( V_8 , L_39 , V_84 . V_86 , V_85 . V_86 ) ;
F_70 ( V_8 , L_40 , F_71 ( V_174 ) , F_71 ( V_85 . V_41 ) ) ;
}
return V_62 ;
}
enum V_87
F_163 ( struct V_7 * V_8 , union V_60 V_84 , union V_60 V_85 ,
enum V_88 V_90 )
{
enum V_87 V_62 ;
F_132 ( & V_8 -> V_2 -> V_91 ) ;
V_62 = F_134 ( V_8 , V_84 , V_85 , V_90 ) ;
F_135 ( & V_8 -> V_2 -> V_91 ) ;
return V_62 ;
}
