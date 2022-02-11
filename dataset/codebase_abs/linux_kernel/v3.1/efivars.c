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
static T_3
F_5 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
T_3 V_11 ;
V_10 -> V_12 = 1024 ;
V_11 = V_8 -> V_13 -> V_14 ( V_10 -> V_15 ,
& V_10 -> V_16 ,
& V_10 -> V_17 ,
& V_10 -> V_12 ,
V_10 -> V_18 ) ;
return V_11 ;
}
static T_3
F_6 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
T_3 V_11 ;
F_7 ( & V_8 -> V_19 ) ;
V_11 = F_5 ( V_8 , V_10 ) ;
F_8 ( & V_8 -> V_19 ) ;
if ( V_11 != V_20 ) {
F_9 ( V_21 L_1 ,
V_11 ) ;
}
return V_11 ;
}
static T_4
F_10 ( struct V_22 * V_23 , char * V_24 )
{
struct V_9 * V_10 = & V_23 -> V_10 ;
char * V_25 = V_24 ;
if ( ! V_23 || ! V_24 )
return 0 ;
F_11 ( & V_10 -> V_16 , V_25 ) ;
V_25 += strlen ( V_25 ) ;
V_25 += sprintf ( V_25 , L_2 ) ;
return V_25 - V_24 ;
}
static T_4
F_12 ( struct V_22 * V_23 , char * V_24 )
{
struct V_9 * V_10 = & V_23 -> V_10 ;
char * V_25 = V_24 ;
T_3 V_11 ;
if ( ! V_23 || ! V_24 )
return - V_26 ;
V_11 = F_6 ( V_23 -> V_8 , V_10 ) ;
if ( V_11 != V_20 )
return - V_27 ;
if ( V_10 -> V_17 & 0x1 )
V_25 += sprintf ( V_25 , L_3 ) ;
if ( V_10 -> V_17 & 0x2 )
V_25 += sprintf ( V_25 , L_4 ) ;
if ( V_10 -> V_17 & 0x4 )
V_25 += sprintf ( V_25 , L_5 ) ;
return V_25 - V_24 ;
}
static T_4
F_13 ( struct V_22 * V_23 , char * V_24 )
{
struct V_9 * V_10 = & V_23 -> V_10 ;
char * V_25 = V_24 ;
T_3 V_11 ;
if ( ! V_23 || ! V_24 )
return - V_26 ;
V_11 = F_6 ( V_23 -> V_8 , V_10 ) ;
if ( V_11 != V_20 )
return - V_27 ;
V_25 += sprintf ( V_25 , L_6 , V_10 -> V_12 ) ;
return V_25 - V_24 ;
}
static T_4
F_14 ( struct V_22 * V_23 , char * V_24 )
{
struct V_9 * V_10 = & V_23 -> V_10 ;
T_3 V_11 ;
if ( ! V_23 || ! V_24 )
return - V_26 ;
V_11 = F_6 ( V_23 -> V_8 , V_10 ) ;
if ( V_11 != V_20 )
return - V_27 ;
memcpy ( V_24 , V_10 -> V_18 , V_10 -> V_12 ) ;
return V_10 -> V_12 ;
}
static T_4
F_15 ( struct V_22 * V_23 , const char * V_24 , T_2 V_28 )
{
struct V_9 * V_29 , * V_10 = & V_23 -> V_10 ;
struct V_8 * V_8 = V_23 -> V_8 ;
T_3 V_11 = V_30 ;
if ( V_28 != sizeof( struct V_9 ) )
return - V_26 ;
V_29 = (struct V_9 * ) V_24 ;
if ( memcmp ( V_29 -> V_15 , V_10 -> V_15 , sizeof( V_10 -> V_15 ) ) ||
F_16 ( V_29 -> V_16 , V_10 -> V_16 ) ) {
F_9 ( V_31 L_7 ) ;
return - V_26 ;
}
if ( ( V_29 -> V_12 <= 0 ) || ( V_29 -> V_17 == 0 ) ) {
F_9 ( V_31 L_8 ) ;
return - V_26 ;
}
F_7 ( & V_8 -> V_19 ) ;
V_11 = V_8 -> V_13 -> V_32 ( V_29 -> V_15 ,
& V_29 -> V_16 ,
V_29 -> V_17 ,
V_29 -> V_12 ,
V_29 -> V_18 ) ;
F_8 ( & V_8 -> V_19 ) ;
if ( V_11 != V_20 ) {
F_9 ( V_21 L_9 ,
V_11 ) ;
return - V_27 ;
}
memcpy ( & V_23 -> V_10 , V_29 , V_28 ) ;
return V_28 ;
}
static T_4
F_17 ( struct V_22 * V_23 , char * V_24 )
{
struct V_9 * V_10 = & V_23 -> V_10 ;
T_3 V_11 ;
if ( ! V_23 || ! V_24 )
return 0 ;
V_11 = F_6 ( V_23 -> V_8 , V_10 ) ;
if ( V_11 != V_20 )
return - V_27 ;
memcpy ( V_24 , V_10 , sizeof( * V_10 ) ) ;
return sizeof( * V_10 ) ;
}
static T_4 F_18 ( struct V_33 * V_34 , struct V_35 * V_36 ,
char * V_24 )
{
struct V_22 * V_10 = F_19 ( V_34 ) ;
struct V_37 * V_38 = F_20 ( V_36 ) ;
T_4 V_39 = - V_27 ;
if ( ! F_21 ( V_40 ) )
return - V_41 ;
if ( V_38 -> V_42 ) {
V_39 = V_38 -> V_42 ( V_10 , V_24 ) ;
}
return V_39 ;
}
static T_4 F_22 ( struct V_33 * V_34 , struct V_35 * V_36 ,
const char * V_24 , T_2 V_28 )
{
struct V_22 * V_10 = F_19 ( V_34 ) ;
struct V_37 * V_38 = F_20 ( V_36 ) ;
T_4 V_39 = - V_27 ;
if ( ! F_21 ( V_40 ) )
return - V_41 ;
if ( V_38 -> V_43 )
V_39 = V_38 -> V_43 ( V_10 , V_24 , V_28 ) ;
return V_39 ;
}
static void F_23 ( struct V_33 * V_34 )
{
struct V_22 * V_10 = F_24 ( V_34 , struct V_22 , V_34 ) ;
F_25 ( V_10 ) ;
}
static inline void
F_26 ( struct V_22 * V_10 )
{
F_27 ( & V_10 -> V_34 ) ;
}
static int F_28 ( struct V_44 * V_45 )
{
struct V_8 * V_8 = V_45 -> V_4 ;
F_7 ( & V_8 -> V_19 ) ;
V_8 -> V_46 = F_29 ( & V_8 -> V_47 ,
struct V_22 , V_47 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_45 )
{
struct V_8 * V_8 = V_45 -> V_4 ;
F_8 ( & V_8 -> V_19 ) ;
return 0 ;
}
static T_4 F_31 ( T_5 * V_48 , enum V_49 * type ,
struct V_50 * V_50 , struct V_44 * V_45 )
{
T_6 V_51 = V_52 ;
struct V_8 * V_8 = V_45 -> V_4 ;
char V_53 [ V_54 ] ;
int V_55 ;
unsigned int V_56 , V_57 ;
unsigned long time ;
while ( & V_8 -> V_46 -> V_47 != & V_8 -> V_47 ) {
if ( ! F_16 ( V_8 -> V_46 -> V_10 . V_16 ,
V_51 ) ) {
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ ) {
V_53 [ V_55 ] = V_8 -> V_46 -> V_10 . V_15 [ V_55 ] ;
}
if ( sscanf ( V_53 , L_10 , type , & V_56 , & time ) == 3 ) {
* V_48 = V_56 ;
V_50 -> V_58 = time ;
V_50 -> V_59 = 0 ;
F_5 ( V_8 , & V_8 -> V_46 -> V_10 ) ;
V_57 = V_8 -> V_46 -> V_10 . V_12 ;
memcpy ( V_45 -> V_24 , V_8 -> V_46 -> V_10 . V_18 , V_57 ) ;
V_8 -> V_46 = F_32 ( V_8 -> V_46 -> V_47 . V_60 ,
struct V_22 , V_47 ) ;
return V_57 ;
}
}
V_8 -> V_46 = F_32 ( V_8 -> V_46 -> V_47 . V_60 ,
struct V_22 , V_47 ) ;
}
return 0 ;
}
static T_5 F_33 ( enum V_49 type , unsigned int V_56 ,
T_2 V_57 , struct V_44 * V_45 )
{
char V_53 [ V_54 ] ;
char V_61 [ V_54 ] ;
T_1 V_62 [ V_54 ] ;
T_6 V_51 = V_52 ;
struct V_8 * V_8 = V_45 -> V_4 ;
struct V_22 * V_23 , * V_63 = NULL ;
int V_55 ;
sprintf ( V_61 , L_11 , type , V_56 ) ;
sprintf ( V_53 , L_12 , V_61 , F_34 () ) ;
F_7 ( & V_8 -> V_19 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
V_62 [ V_55 ] = V_61 [ V_55 ] ;
F_35 (entry, &efivars->list, list) {
F_5 ( V_8 , & V_23 -> V_10 ) ;
if ( F_16 ( V_23 -> V_10 . V_16 , V_51 ) )
continue;
if ( F_4 ( V_23 -> V_10 . V_15 , V_62 ,
F_2 ( V_62 ) ) )
continue;
if ( V_23 -> V_10 . V_15 [ F_2 ( V_62 ) ] == 0 )
continue;
V_63 = V_23 ;
V_8 -> V_13 -> V_32 ( V_23 -> V_10 . V_15 ,
& V_23 -> V_10 . V_16 ,
V_64 ,
0 , NULL ) ;
}
if ( V_63 )
F_36 ( & V_63 -> V_47 ) ;
for ( V_55 = 0 ; V_55 < V_54 ; V_55 ++ )
V_62 [ V_55 ] = V_53 [ V_55 ] ;
V_8 -> V_13 -> V_32 ( V_62 , & V_51 , V_64 ,
V_57 , V_45 -> V_24 ) ;
F_8 ( & V_8 -> V_19 ) ;
if ( V_63 )
F_26 ( V_63 ) ;
if ( V_57 )
F_37 ( V_8 ,
F_3 ( V_62 ,
V_54 * 2 ) ,
V_62 , & V_51 ) ;
return V_56 ;
}
static int F_38 ( enum V_49 type , T_5 V_48 ,
struct V_44 * V_45 )
{
F_33 ( type , V_48 , 0 , V_45 ) ;
return 0 ;
}
static int F_28 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_30 ( struct V_44 * V_45 )
{
return 0 ;
}
static T_4 F_31 ( T_5 * V_48 , enum V_49 * type ,
struct V_50 * time , struct V_44 * V_45 )
{
return - 1 ;
}
static T_5 F_33 ( enum V_49 type , unsigned int V_56 ,
T_2 V_57 , struct V_44 * V_45 )
{
return 0 ;
}
static int F_38 ( enum V_49 type , T_5 V_48 ,
struct V_44 * V_45 )
{
return 0 ;
}
static T_4 F_39 ( struct V_65 * V_66 , struct V_33 * V_34 ,
struct V_67 * V_68 ,
char * V_24 , T_7 V_69 , T_2 V_28 )
{
struct V_9 * V_29 = (struct V_9 * ) V_24 ;
struct V_8 * V_8 = V_68 -> V_70 ;
struct V_22 * V_71 , * V_72 ;
unsigned long V_73 , V_74 ;
T_3 V_11 = V_30 ;
int V_63 = 0 ;
if ( ! F_21 ( V_40 ) )
return - V_41 ;
F_7 ( & V_8 -> V_19 ) ;
F_40 (search_efivar, n, &efivars->list, list) {
V_73 = F_3 ( V_71 -> V_10 . V_15 , 1024 ) ;
V_74 = F_3 ( V_29 -> V_15 , 1024 ) ;
if ( V_73 == V_74 &&
! memcmp ( & ( V_71 -> V_10 . V_15 ) ,
V_29 -> V_15 , V_73 ) &&
! F_16 ( V_71 -> V_10 . V_16 ,
V_29 -> V_16 ) ) {
V_63 = 1 ;
break;
}
}
if ( V_63 ) {
F_8 ( & V_8 -> V_19 ) ;
return - V_26 ;
}
V_11 = V_8 -> V_13 -> V_32 ( V_29 -> V_15 ,
& V_29 -> V_16 ,
V_29 -> V_17 ,
V_29 -> V_12 ,
V_29 -> V_18 ) ;
if ( V_11 != V_20 ) {
F_9 ( V_21 L_9 ,
V_11 ) ;
F_8 ( & V_8 -> V_19 ) ;
return - V_27 ;
}
F_8 ( & V_8 -> V_19 ) ;
V_11 = F_37 ( V_8 ,
F_3 ( V_29 -> V_15 ,
1024 ) ,
V_29 -> V_15 ,
& V_29 -> V_16 ) ;
if ( V_11 ) {
F_9 ( V_21 L_13 ) ;
}
return V_28 ;
}
static T_4 F_41 ( struct V_65 * V_66 , struct V_33 * V_34 ,
struct V_67 * V_68 ,
char * V_24 , T_7 V_69 , T_2 V_28 )
{
struct V_9 * V_75 = (struct V_9 * ) V_24 ;
struct V_8 * V_8 = V_68 -> V_70 ;
struct V_22 * V_71 , * V_72 ;
unsigned long V_73 , V_74 ;
T_3 V_11 = V_30 ;
int V_63 = 0 ;
if ( ! F_21 ( V_40 ) )
return - V_41 ;
F_7 ( & V_8 -> V_19 ) ;
F_40 (search_efivar, n, &efivars->list, list) {
V_73 = F_3 ( V_71 -> V_10 . V_15 , 1024 ) ;
V_74 = F_3 ( V_75 -> V_15 , 1024 ) ;
if ( V_73 == V_74 &&
! memcmp ( & ( V_71 -> V_10 . V_15 ) ,
V_75 -> V_15 , V_73 ) &&
! F_16 ( V_71 -> V_10 . V_16 ,
V_75 -> V_16 ) ) {
V_63 = 1 ;
break;
}
}
if ( ! V_63 ) {
F_8 ( & V_8 -> V_19 ) ;
return - V_26 ;
}
V_75 -> V_17 = 0 ;
V_75 -> V_12 = 0 ;
V_11 = V_8 -> V_13 -> V_32 ( V_75 -> V_15 ,
& V_75 -> V_16 ,
V_75 -> V_17 ,
V_75 -> V_12 ,
V_75 -> V_18 ) ;
if ( V_11 != V_20 ) {
F_9 ( V_21 L_9 ,
V_11 ) ;
F_8 ( & V_8 -> V_19 ) ;
return - V_27 ;
}
F_36 ( & V_71 -> V_47 ) ;
F_8 ( & V_8 -> V_19 ) ;
F_26 ( V_71 ) ;
return V_28 ;
}
static T_4 F_42 ( struct V_33 * V_34 ,
struct V_76 * V_36 , char * V_24 )
{
char * V_25 = V_24 ;
if ( ! V_34 || ! V_24 )
return - V_26 ;
if ( V_77 . V_78 != V_79 )
V_25 += sprintf ( V_25 , L_14 , V_77 . V_78 ) ;
if ( V_77 . V_80 != V_79 )
V_25 += sprintf ( V_25 , L_15 , V_77 . V_80 ) ;
if ( V_77 . V_81 != V_79 )
V_25 += sprintf ( V_25 , L_16 , V_77 . V_81 ) ;
if ( V_77 . V_82 != V_79 )
V_25 += sprintf ( V_25 , L_17 , V_77 . V_82 ) ;
if ( V_77 . V_83 != V_79 )
V_25 += sprintf ( V_25 , L_18 , V_77 . V_83 ) ;
if ( V_77 . V_84 != V_79 )
V_25 += sprintf ( V_25 , L_19 , V_77 . V_84 ) ;
if ( V_77 . V_85 != V_79 )
V_25 += sprintf ( V_25 , L_20 , V_77 . V_85 ) ;
return V_25 - V_24 ;
}
static int
F_37 ( struct V_8 * V_8 ,
unsigned long V_86 ,
T_1 * V_87 ,
T_6 * V_88 )
{
int V_55 , V_89 = V_86 / sizeof( T_1 ) + 38 ;
char * V_90 ;
struct V_22 * V_91 ;
V_90 = F_43 ( V_89 + 1 , V_92 ) ;
V_91 = F_43 ( sizeof( struct V_22 ) , V_92 ) ;
if ( ! V_90 || ! V_91 ) {
F_25 ( V_90 ) ;
F_25 ( V_91 ) ;
return 1 ;
}
V_91 -> V_8 = V_8 ;
memcpy ( V_91 -> V_10 . V_15 , V_87 ,
V_86 ) ;
memcpy ( & ( V_91 -> V_10 . V_16 ) , V_88 , sizeof( T_6 ) ) ;
for ( V_55 = 0 ; V_55 < ( int ) ( V_86 / sizeof( T_1 ) ) ; V_55 ++ ) {
V_90 [ V_55 ] = V_87 [ V_55 ] & 0xFF ;
}
* ( V_90 + strlen ( V_90 ) ) = '-' ;
F_11 ( V_88 , V_90 + strlen ( V_90 ) ) ;
V_91 -> V_34 . V_93 = V_8 -> V_93 ;
V_55 = F_44 ( & V_91 -> V_34 , & V_94 , NULL ,
L_21 , V_90 ) ;
if ( V_55 ) {
F_25 ( V_90 ) ;
F_25 ( V_91 ) ;
return 1 ;
}
F_45 ( & V_91 -> V_34 , V_95 ) ;
F_25 ( V_90 ) ;
V_90 = NULL ;
F_7 ( & V_8 -> V_19 ) ;
F_46 ( & V_91 -> V_47 , & V_8 -> V_47 ) ;
F_8 ( & V_8 -> V_19 ) ;
return 0 ;
}
static int
F_47 ( struct V_8 * V_8 )
{
struct V_67 * V_36 ;
int error ;
V_36 = F_43 ( sizeof( * V_36 ) , V_92 ) ;
if ( ! V_36 )
return - V_96 ;
V_36 -> V_36 . V_53 = L_22 ;
V_36 -> V_36 . V_97 = 0200 ;
V_36 -> V_98 = F_39 ;
V_36 -> V_70 = V_8 ;
V_8 -> V_29 = V_36 ;
V_36 = F_43 ( sizeof( * V_36 ) , V_92 ) ;
if ( ! V_36 ) {
error = - V_96 ;
goto V_99;
}
V_36 -> V_36 . V_53 = L_23 ;
V_36 -> V_36 . V_97 = 0200 ;
V_36 -> V_98 = F_41 ;
V_36 -> V_70 = V_8 ;
V_8 -> V_75 = V_36 ;
F_48 ( V_8 -> V_29 ) ;
F_48 ( V_8 -> V_75 ) ;
error = F_49 ( & V_8 -> V_93 -> V_34 ,
V_8 -> V_29 ) ;
if ( error ) {
F_9 ( V_31 L_24
L_25 , error ) ;
goto V_99;
}
error = F_49 ( & V_8 -> V_93 -> V_34 ,
V_8 -> V_75 ) ;
if ( error ) {
F_9 ( V_31 L_26
L_25 , error ) ;
F_50 ( & V_8 -> V_93 -> V_34 ,
V_8 -> V_29 ) ;
goto V_99;
}
return 0 ;
V_99:
F_25 ( V_8 -> V_75 ) ;
V_8 -> V_75 = NULL ;
F_25 ( V_8 -> V_29 ) ;
V_8 -> V_29 = NULL ;
return error ;
}
void F_51 ( struct V_8 * V_8 )
{
struct V_22 * V_23 , * V_72 ;
F_40 (entry, n, &efivars->list, list) {
F_7 ( & V_8 -> V_19 ) ;
F_36 ( & V_23 -> V_47 ) ;
F_8 ( & V_8 -> V_19 ) ;
F_26 ( V_23 ) ;
}
if ( V_8 -> V_29 )
F_50 ( & V_8 -> V_93 -> V_34 , V_8 -> V_29 ) ;
if ( V_8 -> V_75 )
F_50 ( & V_8 -> V_93 -> V_34 , V_8 -> V_75 ) ;
F_25 ( V_8 -> V_29 ) ;
F_25 ( V_8 -> V_75 ) ;
F_52 ( V_8 -> V_93 ) ;
}
int F_53 ( struct V_8 * V_8 ,
const struct V_100 * V_13 ,
struct V_33 * V_101 )
{
T_3 V_11 = V_30 ;
T_6 V_88 ;
T_1 * V_87 ;
unsigned long V_86 = 1024 ;
int error = 0 ;
V_87 = F_43 ( V_86 , V_92 ) ;
if ( ! V_87 ) {
F_9 ( V_31 L_27 ) ;
return - V_96 ;
}
F_54 ( & V_8 -> V_19 ) ;
F_55 ( & V_8 -> V_47 ) ;
V_8 -> V_13 = V_13 ;
V_8 -> V_93 = F_56 ( L_28 , NULL , V_101 ) ;
if ( ! V_8 -> V_93 ) {
F_9 ( V_31 L_29 ) ;
error = - V_96 ;
goto V_102;
}
do {
V_86 = 1024 ;
V_11 = V_13 -> V_103 ( & V_86 ,
V_87 ,
& V_88 ) ;
switch ( V_11 ) {
case V_20 :
F_37 ( V_8 ,
V_86 ,
V_87 ,
& V_88 ) ;
break;
case V_30 :
break;
default:
F_9 ( V_21 L_30 ,
V_11 ) ;
V_11 = V_30 ;
break;
}
} while ( V_11 != V_30 );
error = F_47 ( V_8 ) ;
if ( error )
F_51 ( V_8 ) ;
V_8 -> V_104 = V_104 ;
V_8 -> V_104 . V_24 = F_57 ( 4096 , V_92 ) ;
if ( V_8 -> V_104 . V_24 ) {
V_8 -> V_104 . V_105 = 1024 ;
V_8 -> V_104 . V_4 = V_8 ;
F_58 ( & V_8 -> V_104 . V_106 ) ;
F_59 ( & V_8 -> V_104 ) ;
}
V_102:
F_25 ( V_87 ) ;
return error ;
}
static int T_8
F_60 ( void )
{
int error = 0 ;
F_9 ( V_107 L_31 , V_108 ,
V_109 ) ;
if ( ! V_110 )
return 0 ;
V_111 = F_61 ( L_32 , V_112 ) ;
if ( ! V_111 ) {
F_9 ( V_31 L_33 ) ;
return - V_96 ;
}
V_13 . V_14 = V_77 . V_14 ;
V_13 . V_32 = V_77 . V_32 ;
V_13 . V_103 = V_77 . V_103 ;
error = F_53 ( & V_113 , & V_13 , V_111 ) ;
if ( error )
goto V_114;
error = F_62 ( V_111 , & V_115 ) ;
if ( error ) {
F_9 ( V_31
L_34 ,
error ) ;
goto V_116;
}
return 0 ;
V_116:
F_51 ( & V_113 ) ;
V_114:
F_27 ( V_111 ) ;
return error ;
}
static void T_9
F_63 ( void )
{
if ( V_110 ) {
F_51 ( & V_113 ) ;
F_27 ( V_111 ) ;
}
}
