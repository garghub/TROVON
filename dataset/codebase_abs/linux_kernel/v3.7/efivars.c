static unsigned long
F_1 ( T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = 0 ;
while ( * V_1 ++ != 0 && V_3 < V_2 )
V_3 ++ ;
return V_3 ;
}
static inline unsigned long
F_2 ( T_1 * V_1 )
{
return F_1 ( V_1 , ~ 0UL ) ;
}
static inline unsigned long
F_3 ( T_1 * V_4 , unsigned long V_2 )
{
return F_1 ( V_4 , V_2 / sizeof( T_1 ) ) * sizeof( T_1 ) ;
}
static inline int
F_4 ( const T_1 * V_5 , const T_1 * V_6 , T_2 V_7 )
{
while ( 1 ) {
if ( V_7 == 0 )
return 0 ;
if ( * V_5 < * V_6 )
return - 1 ;
if ( * V_5 > * V_6 )
return 1 ;
if ( * V_5 == 0 )
return 0 ;
V_5 ++ ;
V_6 ++ ;
V_7 -- ;
}
}
static bool
F_5 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
struct V_12 * V_13 ;
int V_14 = 0 ;
V_13 = (struct V_12 * ) V_11 ;
if ( V_7 < sizeof( * V_13 ) )
return false ;
while ( V_14 <= V_7 - sizeof( * V_13 ) &&
V_13 -> V_3 >= sizeof( * V_13 ) &&
V_13 -> V_3 <= V_7 - V_14 ) {
V_14 += V_13 -> V_3 ;
if ( ( V_13 -> type == V_15 ||
V_13 -> type == V_16 ) &&
V_13 -> V_17 == V_18 )
return true ;
V_13 = (struct V_12 * ) ( V_11 + V_14 ) ;
}
return false ;
}
static bool
F_6 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
if ( ( V_7 % 2 ) != 0 )
return false ;
return true ;
}
static bool
F_7 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
T_4 V_19 ;
int V_20 , V_21 = 0 , V_22 ;
V_22 = F_1 ( V_9 -> V_23 , sizeof( V_9 -> V_23 ) ) ;
for ( V_20 = V_10 ; V_20 < V_10 + 4 ; V_20 ++ ) {
if ( V_9 -> V_23 [ V_20 ] > 127 ||
F_8 ( V_9 -> V_23 [ V_20 ] & 0xff ) < 0 )
return true ;
}
if ( V_22 > V_10 + 4 )
return false ;
if ( V_7 < 8 )
return false ;
V_19 = V_11 [ 4 ] | V_11 [ 5 ] << 8 ;
V_21 = F_3 ( ( T_1 * ) ( V_11 + 6 ) , V_7 - 6 ) + 2 ;
if ( ! V_21 )
return false ;
if ( ( V_21 + V_19 + 6 ) > V_7 )
return false ;
return F_5 ( V_9 , V_10 , V_11 + V_21 + 6 ,
V_19 ) ;
}
static bool
F_9 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
if ( V_7 != 2 )
return false ;
return true ;
}
static bool
F_10 ( struct V_8 * V_9 , int V_10 , T_3 * V_11 ,
unsigned long V_7 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_7 ; V_20 ++ ) {
if ( V_11 [ V_20 ] > 127 )
return false ;
if ( V_11 [ V_20 ] == 0 )
return true ;
}
return false ;
}
static bool
F_11 ( struct V_8 * V_9 , T_3 * V_4 , unsigned long V_7 )
{
int V_20 ;
T_4 * V_24 = V_9 -> V_23 ;
for ( V_20 = 0 ; V_25 [ V_20 ] . V_26 != NULL ; V_20 ++ ) {
const char * V_27 = V_25 [ V_20 ] . V_27 ;
int V_10 ;
for ( V_10 = 0 ; ; V_10 ++ ) {
char V_28 = V_27 [ V_10 ] ;
T_4 V_29 = V_24 [ V_10 ] ;
if ( V_29 > 127 )
return true ;
if ( V_28 == '*' )
return V_25 [ V_20 ] . V_26 ( V_9 ,
V_10 , V_4 , V_7 ) ;
if ( V_28 != V_29 )
break;
if ( ! V_28 )
return V_25 [ V_20 ] . V_26 ( V_9 ,
V_10 , V_4 , V_7 ) ;
}
}
return true ;
}
static T_5
F_12 ( struct V_30 * V_30 , struct V_8 * V_9 )
{
T_5 V_31 ;
V_9 -> V_32 = 1024 ;
V_31 = V_30 -> V_33 -> V_34 ( V_9 -> V_23 ,
& V_9 -> V_35 ,
& V_9 -> V_36 ,
& V_9 -> V_32 ,
V_9 -> V_37 ) ;
return V_31 ;
}
static T_5
F_13 ( struct V_30 * V_30 , struct V_8 * V_9 )
{
T_5 V_31 ;
F_14 ( & V_30 -> V_38 ) ;
V_31 = F_12 ( V_30 , V_9 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_1 ,
V_31 ) ;
}
return V_31 ;
}
static T_6
F_17 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
if ( ! V_42 || ! V_43 )
return 0 ;
F_18 ( & V_9 -> V_35 , V_44 ) ;
V_44 += strlen ( V_44 ) ;
V_44 += sprintf ( V_44 , L_2 ) ;
return V_44 - V_43 ;
}
static T_6
F_19 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
if ( V_9 -> V_36 & V_47 )
V_44 += sprintf ( V_44 , L_3 ) ;
if ( V_9 -> V_36 & V_48 )
V_44 += sprintf ( V_44 , L_4 ) ;
if ( V_9 -> V_36 & V_49 )
V_44 += sprintf ( V_44 , L_5 ) ;
if ( V_9 -> V_36 & V_50 )
V_44 += sprintf ( V_44 , L_6 ) ;
if ( V_9 -> V_36 & V_51 )
V_44 += sprintf ( V_44 ,
L_7 ) ;
if ( V_9 -> V_36 &
V_52 )
V_44 += sprintf ( V_44 ,
L_8 ) ;
if ( V_9 -> V_36 & V_53 )
V_44 += sprintf ( V_44 , L_9 ) ;
return V_44 - V_43 ;
}
static T_6
F_20 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
char * V_44 = V_43 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
V_44 += sprintf ( V_44 , L_10 , V_9 -> V_32 ) ;
return V_44 - V_43 ;
}
static T_6
F_21 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return - V_45 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
memcpy ( V_43 , V_9 -> V_37 , V_9 -> V_32 ) ;
return V_9 -> V_32 ;
}
static T_6
F_22 ( struct V_41 * V_42 , const char * V_43 , T_2 V_54 )
{
struct V_8 * V_55 , * V_9 = & V_42 -> V_9 ;
struct V_30 * V_30 = V_42 -> V_30 ;
T_5 V_31 = V_56 ;
if ( V_54 != sizeof( struct V_8 ) )
return - V_45 ;
V_55 = (struct V_8 * ) V_43 ;
if ( memcmp ( V_55 -> V_23 , V_9 -> V_23 , sizeof( V_9 -> V_23 ) ) ||
F_23 ( V_55 -> V_35 , V_9 -> V_35 ) ) {
F_16 ( V_57 L_11 ) ;
return - V_45 ;
}
if ( ( V_55 -> V_32 <= 0 ) || ( V_55 -> V_36 == 0 ) ) {
F_16 ( V_57 L_12 ) ;
return - V_45 ;
}
if ( ( V_55 -> V_36 & ~ V_58 ) != 0 ||
F_11 ( V_55 , V_55 -> V_37 , V_55 -> V_32 ) == false ) {
F_16 ( V_57 L_13 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_59 ( V_55 -> V_23 ,
& V_55 -> V_35 ,
V_55 -> V_36 ,
V_55 -> V_32 ,
V_55 -> V_37 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
return - V_46 ;
}
memcpy ( & V_42 -> V_9 , V_55 , V_54 ) ;
return V_54 ;
}
static T_6
F_24 ( struct V_41 * V_42 , char * V_43 )
{
struct V_8 * V_9 = & V_42 -> V_9 ;
T_5 V_31 ;
if ( ! V_42 || ! V_43 )
return 0 ;
V_31 = F_13 ( V_42 -> V_30 , V_9 ) ;
if ( V_31 != V_39 )
return - V_46 ;
memcpy ( V_43 , V_9 , sizeof( * V_9 ) ) ;
return sizeof( * V_9 ) ;
}
static T_6 F_25 ( struct V_60 * V_61 , struct V_62 * V_63 ,
char * V_43 )
{
struct V_41 * V_9 = F_26 ( V_61 ) ;
struct V_64 * V_65 = F_27 ( V_63 ) ;
T_6 V_66 = - V_46 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( V_65 -> V_69 ) {
V_66 = V_65 -> V_69 ( V_9 , V_43 ) ;
}
return V_66 ;
}
static T_6 F_29 ( struct V_60 * V_61 , struct V_62 * V_63 ,
const char * V_43 , T_2 V_54 )
{
struct V_41 * V_9 = F_26 ( V_61 ) ;
struct V_64 * V_65 = F_27 ( V_63 ) ;
T_6 V_66 = - V_46 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( V_65 -> V_70 )
V_66 = V_65 -> V_70 ( V_9 , V_43 , V_54 ) ;
return V_66 ;
}
static void F_30 ( struct V_60 * V_61 )
{
struct V_41 * V_9 = F_31 ( V_61 , struct V_41 , V_61 ) ;
F_32 ( V_9 ) ;
}
static inline void
F_33 ( struct V_41 * V_9 )
{
F_34 ( & V_9 -> V_61 ) ;
}
static int F_35 ( struct V_71 * V_72 )
{
struct V_30 * V_30 = V_72 -> V_4 ;
F_14 ( & V_30 -> V_38 ) ;
V_30 -> V_73 = F_36 ( & V_30 -> V_74 ,
struct V_41 , V_74 ) ;
return 0 ;
}
static int F_37 ( struct V_71 * V_72 )
{
struct V_30 * V_30 = V_72 -> V_4 ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static T_6 F_38 ( T_7 * V_75 , enum V_76 * type ,
struct V_77 * V_77 ,
char * * V_43 , struct V_71 * V_72 )
{
T_8 V_78 = V_79 ;
struct V_30 * V_30 = V_72 -> V_4 ;
char V_27 [ V_80 ] ;
int V_20 ;
unsigned int V_81 , V_82 ;
unsigned long time ;
while ( & V_30 -> V_73 -> V_74 != & V_30 -> V_74 ) {
if ( ! F_23 ( V_30 -> V_73 -> V_9 . V_35 ,
V_78 ) ) {
for ( V_20 = 0 ; V_20 < V_80 ; V_20 ++ ) {
V_27 [ V_20 ] = V_30 -> V_73 -> V_9 . V_23 [ V_20 ] ;
}
if ( sscanf ( V_27 , L_15 , type , & V_81 , & time ) == 3 ) {
* V_75 = V_81 ;
V_77 -> V_83 = time ;
V_77 -> V_84 = 0 ;
F_12 ( V_30 , & V_30 -> V_73 -> V_9 ) ;
V_82 = V_30 -> V_73 -> V_9 . V_32 ;
* V_43 = F_39 ( V_82 , V_85 ) ;
if ( * V_43 == NULL )
return - V_86 ;
memcpy ( * V_43 , V_30 -> V_73 -> V_9 . V_37 ,
V_82 ) ;
V_30 -> V_73 = F_40 ( V_30 -> V_73 -> V_74 . V_87 ,
struct V_41 , V_74 ) ;
return V_82 ;
}
}
V_30 -> V_73 = F_40 ( V_30 -> V_73 -> V_74 . V_87 ,
struct V_41 , V_74 ) ;
}
return 0 ;
}
static int F_41 ( enum V_76 type ,
enum V_88 V_89 , T_7 * V_75 ,
unsigned int V_81 , T_2 V_82 , struct V_71 * V_72 )
{
char V_27 [ V_80 ] ;
char V_90 [ V_80 ] ;
T_1 V_91 [ V_80 ] ;
T_8 V_78 = V_79 ;
struct V_30 * V_30 = V_72 -> V_4 ;
struct V_41 * V_42 , * V_92 = NULL ;
int V_20 , V_66 = 0 ;
sprintf ( V_90 , L_16 , type , V_81 ) ;
sprintf ( V_27 , L_17 , V_90 , F_42 () ) ;
F_14 ( & V_30 -> V_38 ) ;
for ( V_20 = 0 ; V_20 < V_80 ; V_20 ++ )
V_91 [ V_20 ] = V_90 [ V_20 ] ;
F_43 (entry, &efivars->list, list) {
F_12 ( V_30 , & V_42 -> V_9 ) ;
if ( F_23 ( V_42 -> V_9 . V_35 , V_78 ) )
continue;
if ( F_4 ( V_42 -> V_9 . V_23 , V_91 ,
F_2 ( V_91 ) ) )
continue;
if ( V_42 -> V_9 . V_23 [ F_2 ( V_91 ) ] == 0 )
continue;
V_92 = V_42 ;
V_30 -> V_33 -> V_59 ( V_42 -> V_9 . V_23 ,
& V_42 -> V_9 . V_35 ,
V_93 ,
0 , NULL ) ;
}
if ( V_92 )
F_44 ( & V_92 -> V_74 ) ;
for ( V_20 = 0 ; V_20 < V_80 ; V_20 ++ )
V_91 [ V_20 ] = V_27 [ V_20 ] ;
V_30 -> V_33 -> V_59 ( V_91 , & V_78 , V_93 ,
V_82 , V_72 -> V_43 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_92 )
F_33 ( V_92 ) ;
if ( V_82 )
V_66 = F_45 ( V_30 ,
F_3 ( V_91 ,
V_80 * 2 ) ,
V_91 , & V_78 ) ;
* V_75 = V_81 ;
return V_66 ;
}
static int F_46 ( enum V_76 type , T_7 V_75 ,
struct V_71 * V_72 )
{
F_41 ( type , 0 , & V_75 , ( unsigned int ) V_75 , 0 , V_72 ) ;
return 0 ;
}
static int F_35 ( struct V_71 * V_72 )
{
return 0 ;
}
static int F_37 ( struct V_71 * V_72 )
{
return 0 ;
}
static T_6 F_38 ( T_7 * V_75 , enum V_76 * type ,
struct V_77 * V_77 ,
char * * V_43 , struct V_71 * V_72 )
{
return - 1 ;
}
static int F_41 ( enum V_76 type ,
enum V_88 V_89 , T_7 * V_75 ,
unsigned int V_81 , T_2 V_82 , struct V_71 * V_72 )
{
return 0 ;
}
static int F_46 ( enum V_76 type , T_7 V_75 ,
struct V_71 * V_72 )
{
return 0 ;
}
static T_6 F_47 ( struct V_94 * V_95 , struct V_60 * V_61 ,
struct V_96 * V_97 ,
char * V_43 , T_9 V_98 , T_2 V_54 )
{
struct V_8 * V_55 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_97 -> V_99 ;
struct V_41 * V_100 , * V_101 ;
unsigned long V_102 , V_103 ;
T_5 V_31 = V_56 ;
int V_92 = 0 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
if ( ( V_55 -> V_36 & ~ V_58 ) != 0 ||
F_11 ( V_55 , V_55 -> V_37 , V_55 -> V_32 ) == false ) {
F_16 ( V_57 L_13 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
F_48 (search_efivar, n, &efivars->list, list) {
V_102 = F_3 ( V_100 -> V_9 . V_23 , 1024 ) ;
V_103 = F_3 ( V_55 -> V_23 , 1024 ) ;
if ( V_102 == V_103 &&
! memcmp ( & ( V_100 -> V_9 . V_23 ) ,
V_55 -> V_23 , V_102 ) &&
! F_23 ( V_100 -> V_9 . V_35 ,
V_55 -> V_35 ) ) {
V_92 = 1 ;
break;
}
}
if ( V_92 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_31 = V_30 -> V_33 -> V_59 ( V_55 -> V_23 ,
& V_55 -> V_35 ,
V_55 -> V_36 ,
V_55 -> V_32 ,
V_55 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_15 ( & V_30 -> V_38 ) ;
V_31 = F_45 ( V_30 ,
F_3 ( V_55 -> V_23 ,
1024 ) ,
V_55 -> V_23 ,
& V_55 -> V_35 ) ;
if ( V_31 ) {
F_16 ( V_40 L_18 ) ;
}
return V_54 ;
}
static T_6 F_49 ( struct V_94 * V_95 , struct V_60 * V_61 ,
struct V_96 * V_97 ,
char * V_43 , T_9 V_98 , T_2 V_54 )
{
struct V_8 * V_104 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_97 -> V_99 ;
struct V_41 * V_100 , * V_101 ;
unsigned long V_102 , V_103 ;
T_5 V_31 = V_56 ;
int V_92 = 0 ;
if ( ! F_28 ( V_67 ) )
return - V_68 ;
F_14 ( & V_30 -> V_38 ) ;
F_48 (search_efivar, n, &efivars->list, list) {
V_102 = F_3 ( V_100 -> V_9 . V_23 , 1024 ) ;
V_103 = F_3 ( V_104 -> V_23 , 1024 ) ;
if ( V_102 == V_103 &&
! memcmp ( & ( V_100 -> V_9 . V_23 ) ,
V_104 -> V_23 , V_102 ) &&
! F_23 ( V_100 -> V_9 . V_35 ,
V_104 -> V_35 ) ) {
V_92 = 1 ;
break;
}
}
if ( ! V_92 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_104 -> V_36 = 0 ;
V_104 -> V_32 = 0 ;
V_31 = V_30 -> V_33 -> V_59 ( V_104 -> V_23 ,
& V_104 -> V_35 ,
V_104 -> V_36 ,
V_104 -> V_32 ,
V_104 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_14 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_44 ( & V_100 -> V_74 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_100 ) ;
return V_54 ;
}
static T_6 F_50 ( struct V_60 * V_61 ,
struct V_105 * V_63 , char * V_43 )
{
char * V_44 = V_43 ;
if ( ! V_61 || ! V_43 )
return - V_45 ;
if ( V_106 . V_107 != V_108 )
V_44 += sprintf ( V_44 , L_19 , V_106 . V_107 ) ;
if ( V_106 . V_109 != V_108 )
V_44 += sprintf ( V_44 , L_20 , V_106 . V_109 ) ;
if ( V_106 . V_110 != V_108 )
V_44 += sprintf ( V_44 , L_21 , V_106 . V_110 ) ;
if ( V_106 . V_111 != V_108 )
V_44 += sprintf ( V_44 , L_22 , V_106 . V_111 ) ;
if ( V_106 . V_112 != V_108 )
V_44 += sprintf ( V_44 , L_23 , V_106 . V_112 ) ;
if ( V_106 . V_113 != V_108 )
V_44 += sprintf ( V_44 , L_24 , V_106 . V_113 ) ;
if ( V_106 . V_114 != V_108 )
V_44 += sprintf ( V_44 , L_25 , V_106 . V_114 ) ;
return V_44 - V_43 ;
}
static int
F_45 ( struct V_30 * V_30 ,
unsigned long V_115 ,
T_1 * V_116 ,
T_8 * V_117 )
{
int V_20 , V_118 = V_115 / sizeof( T_1 ) + 38 ;
char * V_119 ;
struct V_41 * V_120 ;
V_119 = F_51 ( V_118 + 1 , V_85 ) ;
V_120 = F_51 ( sizeof( struct V_41 ) , V_85 ) ;
if ( ! V_119 || ! V_120 ) {
F_32 ( V_119 ) ;
F_32 ( V_120 ) ;
return 1 ;
}
V_120 -> V_30 = V_30 ;
memcpy ( V_120 -> V_9 . V_23 , V_116 ,
V_115 ) ;
memcpy ( & ( V_120 -> V_9 . V_35 ) , V_117 , sizeof( T_8 ) ) ;
for ( V_20 = 0 ; V_20 < ( int ) ( V_115 / sizeof( T_1 ) ) ; V_20 ++ ) {
V_119 [ V_20 ] = V_116 [ V_20 ] & 0xFF ;
}
* ( V_119 + strlen ( V_119 ) ) = '-' ;
F_18 ( V_117 , V_119 + strlen ( V_119 ) ) ;
V_120 -> V_61 . V_121 = V_30 -> V_121 ;
V_20 = F_52 ( & V_120 -> V_61 , & V_122 , NULL ,
L_26 , V_119 ) ;
if ( V_20 ) {
F_32 ( V_119 ) ;
F_32 ( V_120 ) ;
return 1 ;
}
F_53 ( & V_120 -> V_61 , V_123 ) ;
F_32 ( V_119 ) ;
V_119 = NULL ;
F_14 ( & V_30 -> V_38 ) ;
F_54 ( & V_120 -> V_74 , & V_30 -> V_74 ) ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static int
F_55 ( struct V_30 * V_30 )
{
struct V_96 * V_63 ;
int error ;
V_63 = F_51 ( sizeof( * V_63 ) , V_85 ) ;
if ( ! V_63 )
return - V_86 ;
V_63 -> V_63 . V_27 = L_27 ;
V_63 -> V_63 . V_124 = 0200 ;
V_63 -> V_125 = F_47 ;
V_63 -> V_99 = V_30 ;
V_30 -> V_55 = V_63 ;
V_63 = F_51 ( sizeof( * V_63 ) , V_85 ) ;
if ( ! V_63 ) {
error = - V_86 ;
goto V_126;
}
V_63 -> V_63 . V_27 = L_28 ;
V_63 -> V_63 . V_124 = 0200 ;
V_63 -> V_125 = F_49 ;
V_63 -> V_99 = V_30 ;
V_30 -> V_104 = V_63 ;
F_56 ( V_30 -> V_55 ) ;
F_56 ( V_30 -> V_104 ) ;
error = F_57 ( & V_30 -> V_121 -> V_61 ,
V_30 -> V_55 ) ;
if ( error ) {
F_16 ( V_57 L_29
L_30 , error ) ;
goto V_126;
}
error = F_57 ( & V_30 -> V_121 -> V_61 ,
V_30 -> V_104 ) ;
if ( error ) {
F_16 ( V_57 L_31
L_30 , error ) ;
F_58 ( & V_30 -> V_121 -> V_61 ,
V_30 -> V_55 ) ;
goto V_126;
}
return 0 ;
V_126:
F_32 ( V_30 -> V_104 ) ;
V_30 -> V_104 = NULL ;
F_32 ( V_30 -> V_55 ) ;
V_30 -> V_55 = NULL ;
return error ;
}
void F_59 ( struct V_30 * V_30 )
{
struct V_41 * V_42 , * V_101 ;
F_48 (entry, n, &efivars->list, list) {
F_14 ( & V_30 -> V_38 ) ;
F_44 ( & V_42 -> V_74 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_42 ) ;
}
if ( V_30 -> V_55 )
F_58 ( & V_30 -> V_121 -> V_61 , V_30 -> V_55 ) ;
if ( V_30 -> V_104 )
F_58 ( & V_30 -> V_121 -> V_61 , V_30 -> V_104 ) ;
F_32 ( V_30 -> V_55 ) ;
F_32 ( V_30 -> V_104 ) ;
F_60 ( V_30 -> V_121 ) ;
}
int F_61 ( struct V_30 * V_30 ,
const struct V_127 * V_33 ,
struct V_60 * V_128 )
{
T_5 V_31 = V_56 ;
T_8 V_117 ;
T_1 * V_116 ;
unsigned long V_115 = 1024 ;
int error = 0 ;
V_116 = F_51 ( V_115 , V_85 ) ;
if ( ! V_116 ) {
F_16 ( V_57 L_32 ) ;
return - V_86 ;
}
F_62 ( & V_30 -> V_38 ) ;
F_63 ( & V_30 -> V_74 ) ;
V_30 -> V_33 = V_33 ;
V_30 -> V_121 = F_64 ( L_33 , NULL , V_128 ) ;
if ( ! V_30 -> V_121 ) {
F_16 ( V_57 L_34 ) ;
error = - V_86 ;
goto V_129;
}
do {
V_115 = 1024 ;
V_31 = V_33 -> V_130 ( & V_115 ,
V_116 ,
& V_117 ) ;
switch ( V_31 ) {
case V_39 :
F_45 ( V_30 ,
V_115 ,
V_116 ,
& V_117 ) ;
break;
case V_56 :
break;
default:
F_16 ( V_40 L_35 ,
V_31 ) ;
V_31 = V_56 ;
break;
}
} while ( V_31 != V_56 );
error = F_55 ( V_30 ) ;
if ( error )
F_59 ( V_30 ) ;
V_30 -> V_131 = V_131 ;
V_30 -> V_131 . V_43 = F_39 ( 4096 , V_85 ) ;
if ( V_30 -> V_131 . V_43 ) {
V_30 -> V_131 . V_132 = 1024 ;
V_30 -> V_131 . V_4 = V_30 ;
F_62 ( & V_30 -> V_131 . V_133 ) ;
F_65 ( & V_30 -> V_131 ) ;
}
V_129:
F_32 ( V_116 ) ;
return error ;
}
static int T_10
F_66 ( void )
{
int error = 0 ;
F_16 ( V_134 L_36 , V_135 ,
V_136 ) ;
if ( ! V_137 )
return 0 ;
V_138 = F_67 ( L_37 , V_139 ) ;
if ( ! V_138 ) {
F_16 ( V_57 L_38 ) ;
return - V_86 ;
}
V_33 . V_34 = V_106 . V_34 ;
V_33 . V_59 = V_106 . V_59 ;
V_33 . V_130 = V_106 . V_130 ;
error = F_61 ( & V_140 , & V_33 , V_138 ) ;
if ( error )
goto V_141;
error = F_68 ( V_138 , & V_142 ) ;
if ( error ) {
F_16 ( V_57
L_39 ,
error ) ;
goto V_143;
}
return 0 ;
V_143:
F_59 ( & V_140 ) ;
V_141:
F_34 ( V_138 ) ;
return error ;
}
static void T_11
F_69 ( void )
{
if ( V_137 ) {
F_59 ( & V_140 ) ;
F_34 ( V_138 ) ;
}
}
