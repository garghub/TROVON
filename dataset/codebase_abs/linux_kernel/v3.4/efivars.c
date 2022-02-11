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
if ( V_9 -> V_36 & 0x1 )
V_44 += sprintf ( V_44 , L_3 ) ;
if ( V_9 -> V_36 & 0x2 )
V_44 += sprintf ( V_44 , L_4 ) ;
if ( V_9 -> V_36 & 0x4 )
V_44 += sprintf ( V_44 , L_5 ) ;
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
V_44 += sprintf ( V_44 , L_6 , V_9 -> V_32 ) ;
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
F_22 ( struct V_41 * V_42 , const char * V_43 , T_2 V_47 )
{
struct V_8 * V_48 , * V_9 = & V_42 -> V_9 ;
struct V_30 * V_30 = V_42 -> V_30 ;
T_5 V_31 = V_49 ;
if ( V_47 != sizeof( struct V_8 ) )
return - V_45 ;
V_48 = (struct V_8 * ) V_43 ;
if ( memcmp ( V_48 -> V_23 , V_9 -> V_23 , sizeof( V_9 -> V_23 ) ) ||
F_23 ( V_48 -> V_35 , V_9 -> V_35 ) ) {
F_16 ( V_50 L_7 ) ;
return - V_45 ;
}
if ( ( V_48 -> V_32 <= 0 ) || ( V_48 -> V_36 == 0 ) ) {
F_16 ( V_50 L_8 ) ;
return - V_45 ;
}
if ( ( V_48 -> V_36 & ~ V_51 ) != 0 ||
F_11 ( V_48 , V_48 -> V_37 , V_48 -> V_32 ) == false ) {
F_16 ( V_50 L_9 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
V_31 = V_30 -> V_33 -> V_52 ( V_48 -> V_23 ,
& V_48 -> V_35 ,
V_48 -> V_36 ,
V_48 -> V_32 ,
V_48 -> V_37 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_10 ,
V_31 ) ;
return - V_46 ;
}
memcpy ( & V_42 -> V_9 , V_48 , V_47 ) ;
return V_47 ;
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
static T_6 F_25 ( struct V_53 * V_54 , struct V_55 * V_56 ,
char * V_43 )
{
struct V_41 * V_9 = F_26 ( V_54 ) ;
struct V_57 * V_58 = F_27 ( V_56 ) ;
T_6 V_59 = - V_46 ;
if ( ! F_28 ( V_60 ) )
return - V_61 ;
if ( V_58 -> V_62 ) {
V_59 = V_58 -> V_62 ( V_9 , V_43 ) ;
}
return V_59 ;
}
static T_6 F_29 ( struct V_53 * V_54 , struct V_55 * V_56 ,
const char * V_43 , T_2 V_47 )
{
struct V_41 * V_9 = F_26 ( V_54 ) ;
struct V_57 * V_58 = F_27 ( V_56 ) ;
T_6 V_59 = - V_46 ;
if ( ! F_28 ( V_60 ) )
return - V_61 ;
if ( V_58 -> V_63 )
V_59 = V_58 -> V_63 ( V_9 , V_43 , V_47 ) ;
return V_59 ;
}
static void F_30 ( struct V_53 * V_54 )
{
struct V_41 * V_9 = F_31 ( V_54 , struct V_41 , V_54 ) ;
F_32 ( V_9 ) ;
}
static inline void
F_33 ( struct V_41 * V_9 )
{
F_34 ( & V_9 -> V_54 ) ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_30 * V_30 = V_65 -> V_4 ;
F_14 ( & V_30 -> V_38 ) ;
V_30 -> V_66 = F_36 ( & V_30 -> V_67 ,
struct V_41 , V_67 ) ;
return 0 ;
}
static int F_37 ( struct V_64 * V_65 )
{
struct V_30 * V_30 = V_65 -> V_4 ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static T_6 F_38 ( T_7 * V_68 , enum V_69 * type ,
struct V_70 * V_70 ,
char * * V_43 , struct V_64 * V_65 )
{
T_8 V_71 = V_72 ;
struct V_30 * V_30 = V_65 -> V_4 ;
char V_27 [ V_73 ] ;
int V_20 ;
unsigned int V_74 , V_75 ;
unsigned long time ;
while ( & V_30 -> V_66 -> V_67 != & V_30 -> V_67 ) {
if ( ! F_23 ( V_30 -> V_66 -> V_9 . V_35 ,
V_71 ) ) {
for ( V_20 = 0 ; V_20 < V_73 ; V_20 ++ ) {
V_27 [ V_20 ] = V_30 -> V_66 -> V_9 . V_23 [ V_20 ] ;
}
if ( sscanf ( V_27 , L_11 , type , & V_74 , & time ) == 3 ) {
* V_68 = V_74 ;
V_70 -> V_76 = time ;
V_70 -> V_77 = 0 ;
F_12 ( V_30 , & V_30 -> V_66 -> V_9 ) ;
V_75 = V_30 -> V_66 -> V_9 . V_32 ;
* V_43 = F_39 ( V_75 , V_78 ) ;
if ( * V_43 == NULL )
return - V_79 ;
memcpy ( * V_43 , V_30 -> V_66 -> V_9 . V_37 ,
V_75 ) ;
V_30 -> V_66 = F_40 ( V_30 -> V_66 -> V_67 . V_80 ,
struct V_41 , V_67 ) ;
return V_75 ;
}
}
V_30 -> V_66 = F_40 ( V_30 -> V_66 -> V_67 . V_80 ,
struct V_41 , V_67 ) ;
}
return 0 ;
}
static int F_41 ( enum V_69 type ,
enum V_81 V_82 , T_7 * V_68 ,
unsigned int V_74 , T_2 V_75 , struct V_64 * V_65 )
{
char V_27 [ V_73 ] ;
char V_83 [ V_73 ] ;
T_1 V_84 [ V_73 ] ;
T_8 V_71 = V_72 ;
struct V_30 * V_30 = V_65 -> V_4 ;
struct V_41 * V_42 , * V_85 = NULL ;
int V_20 , V_59 = 0 ;
sprintf ( V_83 , L_12 , type , V_74 ) ;
sprintf ( V_27 , L_13 , V_83 , F_42 () ) ;
F_14 ( & V_30 -> V_38 ) ;
for ( V_20 = 0 ; V_20 < V_73 ; V_20 ++ )
V_84 [ V_20 ] = V_83 [ V_20 ] ;
F_43 (entry, &efivars->list, list) {
F_12 ( V_30 , & V_42 -> V_9 ) ;
if ( F_23 ( V_42 -> V_9 . V_35 , V_71 ) )
continue;
if ( F_4 ( V_42 -> V_9 . V_23 , V_84 ,
F_2 ( V_84 ) ) )
continue;
if ( V_42 -> V_9 . V_23 [ F_2 ( V_84 ) ] == 0 )
continue;
V_85 = V_42 ;
V_30 -> V_33 -> V_52 ( V_42 -> V_9 . V_23 ,
& V_42 -> V_9 . V_35 ,
V_86 ,
0 , NULL ) ;
}
if ( V_85 )
F_44 ( & V_85 -> V_67 ) ;
for ( V_20 = 0 ; V_20 < V_73 ; V_20 ++ )
V_84 [ V_20 ] = V_27 [ V_20 ] ;
V_30 -> V_33 -> V_52 ( V_84 , & V_71 , V_86 ,
V_75 , V_65 -> V_43 ) ;
F_15 ( & V_30 -> V_38 ) ;
if ( V_85 )
F_33 ( V_85 ) ;
if ( V_75 )
V_59 = F_45 ( V_30 ,
F_3 ( V_84 ,
V_73 * 2 ) ,
V_84 , & V_71 ) ;
* V_68 = V_74 ;
return V_59 ;
}
static int F_46 ( enum V_69 type , T_7 V_68 ,
struct V_64 * V_65 )
{
F_41 ( type , 0 , & V_68 , ( unsigned int ) V_68 , 0 , V_65 ) ;
return 0 ;
}
static int F_35 ( struct V_64 * V_65 )
{
return 0 ;
}
static int F_37 ( struct V_64 * V_65 )
{
return 0 ;
}
static T_6 F_38 ( T_7 * V_68 , enum V_69 * type ,
struct V_70 * V_70 ,
char * * V_43 , struct V_64 * V_65 )
{
return - 1 ;
}
static int F_41 ( enum V_69 type ,
enum V_81 V_82 , T_7 * V_68 ,
unsigned int V_74 , T_2 V_75 , struct V_64 * V_65 )
{
return 0 ;
}
static int F_46 ( enum V_69 type , T_7 V_68 ,
struct V_64 * V_65 )
{
return 0 ;
}
static T_6 F_47 ( struct V_87 * V_88 , struct V_53 * V_54 ,
struct V_89 * V_90 ,
char * V_43 , T_9 V_91 , T_2 V_47 )
{
struct V_8 * V_48 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_90 -> V_92 ;
struct V_41 * V_93 , * V_94 ;
unsigned long V_95 , V_96 ;
T_5 V_31 = V_49 ;
int V_85 = 0 ;
if ( ! F_28 ( V_60 ) )
return - V_61 ;
if ( ( V_48 -> V_36 & ~ V_51 ) != 0 ||
F_11 ( V_48 , V_48 -> V_37 , V_48 -> V_32 ) == false ) {
F_16 ( V_50 L_9 ) ;
return - V_45 ;
}
F_14 ( & V_30 -> V_38 ) ;
F_48 (search_efivar, n, &efivars->list, list) {
V_95 = F_3 ( V_93 -> V_9 . V_23 , 1024 ) ;
V_96 = F_3 ( V_48 -> V_23 , 1024 ) ;
if ( V_95 == V_96 &&
! memcmp ( & ( V_93 -> V_9 . V_23 ) ,
V_48 -> V_23 , V_95 ) &&
! F_23 ( V_93 -> V_9 . V_35 ,
V_48 -> V_35 ) ) {
V_85 = 1 ;
break;
}
}
if ( V_85 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_31 = V_30 -> V_33 -> V_52 ( V_48 -> V_23 ,
& V_48 -> V_35 ,
V_48 -> V_36 ,
V_48 -> V_32 ,
V_48 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_10 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_15 ( & V_30 -> V_38 ) ;
V_31 = F_45 ( V_30 ,
F_3 ( V_48 -> V_23 ,
1024 ) ,
V_48 -> V_23 ,
& V_48 -> V_35 ) ;
if ( V_31 ) {
F_16 ( V_40 L_14 ) ;
}
return V_47 ;
}
static T_6 F_49 ( struct V_87 * V_88 , struct V_53 * V_54 ,
struct V_89 * V_90 ,
char * V_43 , T_9 V_91 , T_2 V_47 )
{
struct V_8 * V_97 = (struct V_8 * ) V_43 ;
struct V_30 * V_30 = V_90 -> V_92 ;
struct V_41 * V_93 , * V_94 ;
unsigned long V_95 , V_96 ;
T_5 V_31 = V_49 ;
int V_85 = 0 ;
if ( ! F_28 ( V_60 ) )
return - V_61 ;
F_14 ( & V_30 -> V_38 ) ;
F_48 (search_efivar, n, &efivars->list, list) {
V_95 = F_3 ( V_93 -> V_9 . V_23 , 1024 ) ;
V_96 = F_3 ( V_97 -> V_23 , 1024 ) ;
if ( V_95 == V_96 &&
! memcmp ( & ( V_93 -> V_9 . V_23 ) ,
V_97 -> V_23 , V_95 ) &&
! F_23 ( V_93 -> V_9 . V_35 ,
V_97 -> V_35 ) ) {
V_85 = 1 ;
break;
}
}
if ( ! V_85 ) {
F_15 ( & V_30 -> V_38 ) ;
return - V_45 ;
}
V_97 -> V_36 = 0 ;
V_97 -> V_32 = 0 ;
V_31 = V_30 -> V_33 -> V_52 ( V_97 -> V_23 ,
& V_97 -> V_35 ,
V_97 -> V_36 ,
V_97 -> V_32 ,
V_97 -> V_37 ) ;
if ( V_31 != V_39 ) {
F_16 ( V_40 L_10 ,
V_31 ) ;
F_15 ( & V_30 -> V_38 ) ;
return - V_46 ;
}
F_44 ( & V_93 -> V_67 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_93 ) ;
return V_47 ;
}
static T_6 F_50 ( struct V_53 * V_54 ,
struct V_98 * V_56 , char * V_43 )
{
char * V_44 = V_43 ;
if ( ! V_54 || ! V_43 )
return - V_45 ;
if ( V_99 . V_100 != V_101 )
V_44 += sprintf ( V_44 , L_15 , V_99 . V_100 ) ;
if ( V_99 . V_102 != V_101 )
V_44 += sprintf ( V_44 , L_16 , V_99 . V_102 ) ;
if ( V_99 . V_103 != V_101 )
V_44 += sprintf ( V_44 , L_17 , V_99 . V_103 ) ;
if ( V_99 . V_104 != V_101 )
V_44 += sprintf ( V_44 , L_18 , V_99 . V_104 ) ;
if ( V_99 . V_105 != V_101 )
V_44 += sprintf ( V_44 , L_19 , V_99 . V_105 ) ;
if ( V_99 . V_106 != V_101 )
V_44 += sprintf ( V_44 , L_20 , V_99 . V_106 ) ;
if ( V_99 . V_107 != V_101 )
V_44 += sprintf ( V_44 , L_21 , V_99 . V_107 ) ;
return V_44 - V_43 ;
}
static int
F_45 ( struct V_30 * V_30 ,
unsigned long V_108 ,
T_1 * V_109 ,
T_8 * V_110 )
{
int V_20 , V_111 = V_108 / sizeof( T_1 ) + 38 ;
char * V_112 ;
struct V_41 * V_113 ;
V_112 = F_51 ( V_111 + 1 , V_78 ) ;
V_113 = F_51 ( sizeof( struct V_41 ) , V_78 ) ;
if ( ! V_112 || ! V_113 ) {
F_32 ( V_112 ) ;
F_32 ( V_113 ) ;
return 1 ;
}
V_113 -> V_30 = V_30 ;
memcpy ( V_113 -> V_9 . V_23 , V_109 ,
V_108 ) ;
memcpy ( & ( V_113 -> V_9 . V_35 ) , V_110 , sizeof( T_8 ) ) ;
for ( V_20 = 0 ; V_20 < ( int ) ( V_108 / sizeof( T_1 ) ) ; V_20 ++ ) {
V_112 [ V_20 ] = V_109 [ V_20 ] & 0xFF ;
}
* ( V_112 + strlen ( V_112 ) ) = '-' ;
F_18 ( V_110 , V_112 + strlen ( V_112 ) ) ;
V_113 -> V_54 . V_114 = V_30 -> V_114 ;
V_20 = F_52 ( & V_113 -> V_54 , & V_115 , NULL ,
L_22 , V_112 ) ;
if ( V_20 ) {
F_32 ( V_112 ) ;
F_32 ( V_113 ) ;
return 1 ;
}
F_53 ( & V_113 -> V_54 , V_116 ) ;
F_32 ( V_112 ) ;
V_112 = NULL ;
F_14 ( & V_30 -> V_38 ) ;
F_54 ( & V_113 -> V_67 , & V_30 -> V_67 ) ;
F_15 ( & V_30 -> V_38 ) ;
return 0 ;
}
static int
F_55 ( struct V_30 * V_30 )
{
struct V_89 * V_56 ;
int error ;
V_56 = F_51 ( sizeof( * V_56 ) , V_78 ) ;
if ( ! V_56 )
return - V_79 ;
V_56 -> V_56 . V_27 = L_23 ;
V_56 -> V_56 . V_117 = 0200 ;
V_56 -> V_118 = F_47 ;
V_56 -> V_92 = V_30 ;
V_30 -> V_48 = V_56 ;
V_56 = F_51 ( sizeof( * V_56 ) , V_78 ) ;
if ( ! V_56 ) {
error = - V_79 ;
goto V_119;
}
V_56 -> V_56 . V_27 = L_24 ;
V_56 -> V_56 . V_117 = 0200 ;
V_56 -> V_118 = F_49 ;
V_56 -> V_92 = V_30 ;
V_30 -> V_97 = V_56 ;
F_56 ( V_30 -> V_48 ) ;
F_56 ( V_30 -> V_97 ) ;
error = F_57 ( & V_30 -> V_114 -> V_54 ,
V_30 -> V_48 ) ;
if ( error ) {
F_16 ( V_50 L_25
L_26 , error ) ;
goto V_119;
}
error = F_57 ( & V_30 -> V_114 -> V_54 ,
V_30 -> V_97 ) ;
if ( error ) {
F_16 ( V_50 L_27
L_26 , error ) ;
F_58 ( & V_30 -> V_114 -> V_54 ,
V_30 -> V_48 ) ;
goto V_119;
}
return 0 ;
V_119:
F_32 ( V_30 -> V_97 ) ;
V_30 -> V_97 = NULL ;
F_32 ( V_30 -> V_48 ) ;
V_30 -> V_48 = NULL ;
return error ;
}
void F_59 ( struct V_30 * V_30 )
{
struct V_41 * V_42 , * V_94 ;
F_48 (entry, n, &efivars->list, list) {
F_14 ( & V_30 -> V_38 ) ;
F_44 ( & V_42 -> V_67 ) ;
F_15 ( & V_30 -> V_38 ) ;
F_33 ( V_42 ) ;
}
if ( V_30 -> V_48 )
F_58 ( & V_30 -> V_114 -> V_54 , V_30 -> V_48 ) ;
if ( V_30 -> V_97 )
F_58 ( & V_30 -> V_114 -> V_54 , V_30 -> V_97 ) ;
F_32 ( V_30 -> V_48 ) ;
F_32 ( V_30 -> V_97 ) ;
F_60 ( V_30 -> V_114 ) ;
}
int F_61 ( struct V_30 * V_30 ,
const struct V_120 * V_33 ,
struct V_53 * V_121 )
{
T_5 V_31 = V_49 ;
T_8 V_110 ;
T_1 * V_109 ;
unsigned long V_108 = 1024 ;
int error = 0 ;
V_109 = F_51 ( V_108 , V_78 ) ;
if ( ! V_109 ) {
F_16 ( V_50 L_28 ) ;
return - V_79 ;
}
F_62 ( & V_30 -> V_38 ) ;
F_63 ( & V_30 -> V_67 ) ;
V_30 -> V_33 = V_33 ;
V_30 -> V_114 = F_64 ( L_29 , NULL , V_121 ) ;
if ( ! V_30 -> V_114 ) {
F_16 ( V_50 L_30 ) ;
error = - V_79 ;
goto V_122;
}
do {
V_108 = 1024 ;
V_31 = V_33 -> V_123 ( & V_108 ,
V_109 ,
& V_110 ) ;
switch ( V_31 ) {
case V_39 :
F_45 ( V_30 ,
V_108 ,
V_109 ,
& V_110 ) ;
break;
case V_49 :
break;
default:
F_16 ( V_40 L_31 ,
V_31 ) ;
V_31 = V_49 ;
break;
}
} while ( V_31 != V_49 );
error = F_55 ( V_30 ) ;
if ( error )
F_59 ( V_30 ) ;
V_30 -> V_124 = V_124 ;
V_30 -> V_124 . V_43 = F_39 ( 4096 , V_78 ) ;
if ( V_30 -> V_124 . V_43 ) {
V_30 -> V_124 . V_125 = 1024 ;
V_30 -> V_124 . V_4 = V_30 ;
F_62 ( & V_30 -> V_124 . V_126 ) ;
F_65 ( & V_30 -> V_124 ) ;
}
V_122:
F_32 ( V_109 ) ;
return error ;
}
static int T_10
F_66 ( void )
{
int error = 0 ;
F_16 ( V_127 L_32 , V_128 ,
V_129 ) ;
if ( ! V_130 )
return 0 ;
V_131 = F_67 ( L_33 , V_132 ) ;
if ( ! V_131 ) {
F_16 ( V_50 L_34 ) ;
return - V_79 ;
}
V_33 . V_34 = V_99 . V_34 ;
V_33 . V_52 = V_99 . V_52 ;
V_33 . V_123 = V_99 . V_123 ;
error = F_61 ( & V_133 , & V_33 , V_131 ) ;
if ( error )
goto V_134;
error = F_68 ( V_131 , & V_135 ) ;
if ( error ) {
F_16 ( V_50
L_35 ,
error ) ;
goto V_136;
}
return 0 ;
V_136:
F_59 ( & V_133 ) ;
V_134:
F_34 ( V_131 ) ;
return error ;
}
static void T_11
F_69 ( void )
{
if ( V_130 ) {
F_59 ( & V_133 ) ;
F_34 ( V_131 ) ;
}
}
