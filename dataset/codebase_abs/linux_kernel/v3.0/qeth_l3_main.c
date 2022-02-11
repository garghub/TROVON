static int F_1 ( char * V_1 )
{
while ( * V_1 ) {
if ( ! isxdigit ( * V_1 ++ ) )
return 0 ;
}
return 1 ;
}
void F_2 ( const T_1 * V_2 , char * V_1 )
{
sprintf ( V_1 , L_1 , V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] ) ;
}
int F_3 ( const char * V_1 , T_1 * V_2 )
{
int V_3 = 0 , V_4 = 0 ;
int V_5 [ 4 ] ;
char V_6 ;
V_4 = sscanf ( V_1 , L_2 ,
& V_5 [ 0 ] , & V_5 [ 1 ] , & V_5 [ 2 ] , & V_5 [ 3 ] , & V_6 ) ;
if ( V_4 != 4 && ( V_4 != 5 || V_6 != '\n' ) )
return - V_7 ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_5 [ V_3 ] > 255 )
return - V_7 ;
V_2 [ V_3 ] = V_5 [ V_3 ] ;
}
return 0 ;
}
void F_4 ( const T_1 * V_2 , char * V_1 )
{
sprintf ( V_1 , L_3 , V_2 ) ;
}
int F_5 ( const char * V_1 , T_1 * V_2 )
{
const char * V_8 , * V_9 , * V_10 ;
T_2 * V_5 ;
char V_11 [ 5 ] ;
int V_12 , V_13 , V_14 , V_15 , V_16 ;
unsigned short V_17 [ 8 ] = { 0 , } ;
V_13 = V_14 = V_15 = V_16 = V_12 = 0 ;
V_8 = V_10 = V_1 ;
V_5 = ( T_2 * ) V_2 ;
memset ( V_5 , 0 , 16 ) ;
while ( * V_8 ) {
V_8 = strchr ( V_10 , ':' ) ;
if ( V_8 == NULL ) {
V_8 = V_1 + strlen ( V_1 ) ;
V_9 = strchr ( V_10 , '\n' ) ;
if ( V_9 != NULL )
V_8 = V_9 ;
V_14 = 1 ;
}
if ( ( V_8 - V_10 ) ) {
memset ( V_11 , 0 , 5 ) ;
if ( ( V_8 - V_10 ) > 4 )
return - V_7 ;
memcpy ( V_11 , V_10 , V_8 - V_10 ) ;
if ( ! F_1 ( V_11 ) )
return - V_7 ;
sscanf ( V_10 , L_4 , & V_12 ) ;
if ( V_15 )
V_17 [ V_16 ++ ] = V_12 ;
else
V_5 [ V_13 ++ ] = V_12 ;
if ( V_14 )
break;
} else {
if ( V_15 )
return - V_7 ;
V_15 = 1 ;
}
V_10 = ++ V_8 ;
}
if ( V_13 + V_16 > 8 )
return - V_7 ;
V_13 = 7 ;
while ( V_16 )
V_5 [ V_13 -- ] = V_17 [ -- V_16 ] ;
return 0 ;
}
void F_6 ( enum V_18 V_19 , const T_1 * V_2 ,
char * V_1 )
{
if ( V_19 == V_20 )
F_2 ( V_2 , V_1 ) ;
else if ( V_19 == V_21 )
F_4 ( V_2 , V_1 ) ;
}
int F_7 ( const char * V_1 , enum V_18 V_19 ,
T_1 * V_2 )
{
if ( V_19 == V_20 )
return F_3 ( V_1 , V_2 ) ;
else if ( V_19 == V_21 )
return F_5 ( V_1 , V_2 ) ;
else
return - V_7 ;
}
static void F_8 ( T_3 * V_2 , T_3 * V_22 , int V_23 )
{
int V_24 , V_25 ;
T_3 V_26 ;
for ( V_24 = 0 ; V_24 < V_23 ; ++ V_24 ) {
V_26 = V_2 [ V_24 ] ;
for ( V_25 = 7 ; V_25 >= 0 ; -- V_25 ) {
V_22 [ V_24 * 8 + V_25 ] = V_26 & 1 ;
V_26 >>= 1 ;
}
}
}
int F_9 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
struct V_30 * V_31 ;
T_3 V_32 [ 128 ] = { 0 , } ;
T_3 V_33 [ 128 ] = { 0 , } ;
int V_4 = 0 ;
if ( ! V_28 -> V_34 . V_35 )
return 0 ;
F_8 ( ( T_3 * ) & V_2 -> V_36 , V_32 ,
( V_2 -> V_19 == V_20 ) ? 4 : 16 ) ;
F_10 (ipatoe, &card->ipato.entries, entry) {
if ( V_2 -> V_19 != V_31 -> V_19 )
continue;
F_8 ( V_31 -> V_2 , V_33 ,
( V_31 -> V_19 == V_20 ) ?
4 : 16 ) ;
if ( V_2 -> V_19 == V_20 )
V_4 = ! memcmp ( V_32 , V_33 ,
F_11 ( 32 , V_31 -> V_37 ) ) ;
else
V_4 = ! memcmp ( V_32 , V_33 ,
F_11 ( 128 , V_31 -> V_37 ) ) ;
if ( V_4 )
break;
}
if ( ( V_2 -> V_19 == V_20 ) && V_28 -> V_34 . V_38 )
V_4 = ! V_4 ;
else if ( ( V_2 -> V_19 == V_21 ) && V_28 -> V_34 . V_39 )
V_4 = ! V_4 ;
return V_4 ;
}
static int F_12 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_40 )
{
struct V_29 * V_41 , * V_42 ;
int V_15 = 0 ;
if ( V_28 -> V_43 . V_44 )
return 0 ;
F_13 (tmp, t, card->ip_tbd_list, entry) {
if ( ( V_2 -> type == V_45 ) &&
( V_41 -> type == V_45 ) )
return 0 ;
if ( ( V_41 -> V_19 == V_20 ) &&
( V_2 -> V_19 == V_20 ) &&
( V_41 -> type == V_2 -> type ) &&
( V_41 -> V_46 == V_2 -> V_46 ) &&
( V_41 -> V_36 . V_47 . V_2 == V_2 -> V_36 . V_47 . V_2 ) &&
( V_41 -> V_36 . V_47 . V_48 == V_2 -> V_36 . V_47 . V_48 ) ) {
V_15 = 1 ;
break;
}
if ( ( V_41 -> V_19 == V_21 ) &&
( V_2 -> V_19 == V_21 ) &&
( V_41 -> type == V_2 -> type ) &&
( V_41 -> V_46 == V_2 -> V_46 ) &&
( V_41 -> V_36 . V_49 . V_50 == V_2 -> V_36 . V_49 . V_50 ) &&
( memcmp ( & V_41 -> V_36 . V_49 . V_2 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) == 0 ) ) {
V_15 = 1 ;
break;
}
}
if ( V_15 ) {
if ( V_2 -> V_52 != 0 )
V_41 -> V_52 += V_2 -> V_52 ;
else
V_41 -> V_52 += V_40 ? 1 : - 1 ;
if ( V_41 -> V_52 == 0 ) {
F_14 ( & V_41 -> V_53 ) ;
F_15 ( V_41 ) ;
}
return 0 ;
} else {
if ( V_2 -> type == V_45 )
F_16 ( & V_2 -> V_53 , V_28 -> V_54 ) ;
else {
if ( V_2 -> V_52 == 0 )
V_2 -> V_52 += V_40 ? 1 : - 1 ;
if ( V_40 && ( V_2 -> type == V_55 ) &&
F_9 ( V_28 , V_2 ) ) {
F_17 ( V_28 , 2 , L_5 ) ;
V_2 -> V_56 |= V_57 ;
}
F_18 ( & V_2 -> V_53 , V_28 -> V_54 ) ;
}
return 1 ;
}
}
static int F_19 ( struct V_27 * V_28 , struct V_29 * V_2 )
{
unsigned long V_58 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_6 ) ;
if ( V_2 -> V_19 == V_20 )
F_20 ( V_28 , 4 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
else {
F_20 ( V_28 , 4 , & V_2 -> V_36 . V_49 . V_2 , 8 ) ;
F_20 ( V_28 , 4 , ( ( char * ) & V_2 -> V_36 . V_49 . V_2 ) + 8 , 8 ) ;
}
F_21 ( & V_28 -> V_59 , V_58 ) ;
V_4 = F_12 ( V_28 , V_2 , 0 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
return V_4 ;
}
static int F_23 ( struct V_27 * V_28 , struct V_29 * V_2 )
{
unsigned long V_58 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_7 ) ;
if ( V_2 -> V_19 == V_20 )
F_20 ( V_28 , 4 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
else {
F_20 ( V_28 , 4 , & V_2 -> V_36 . V_49 . V_2 , 8 ) ;
F_20 ( V_28 , 4 , ( ( char * ) & V_2 -> V_36 . V_49 . V_2 ) + 8 , 8 ) ;
}
F_21 ( & V_28 -> V_59 , V_58 ) ;
V_4 = F_12 ( V_28 , V_2 , 1 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
return V_4 ;
}
static struct V_29 * F_24 (
enum V_18 V_60 )
{
struct V_29 * V_2 ;
V_2 = F_25 ( sizeof( struct V_29 ) , V_61 ) ;
if ( V_2 == NULL ) {
return NULL ;
}
V_2 -> type = V_55 ;
V_2 -> V_19 = V_60 ;
return V_2 ;
}
static void F_26 ( struct V_27 * V_28 )
{
struct V_29 * V_62 ;
unsigned long V_58 ;
F_17 ( V_28 , 4 , L_8 ) ;
V_62 = F_24 ( V_20 ) ;
if ( ! V_62 ) {
F_17 ( V_28 , 2 , L_9 ) ;
return;
}
V_62 -> type = V_45 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( ! F_12 ( V_28 , V_62 , 0 ) )
F_15 ( V_62 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
static int F_27 ( struct V_27 * V_28 ,
struct V_29 * V_63 , struct V_29 * * V_64 )
{
struct V_29 * V_2 ;
int V_15 = 0 ;
F_10 (addr, &card->ip_list, entry) {
if ( ( V_2 -> V_19 == V_20 ) &&
( V_63 -> V_19 == V_20 ) &&
( V_2 -> type == V_63 -> type ) &&
( V_2 -> V_36 . V_47 . V_2 == V_63 -> V_36 . V_47 . V_2 ) &&
( V_2 -> V_36 . V_47 . V_48 == V_63 -> V_36 . V_47 . V_48 ) ) {
V_15 = 1 ;
break;
}
if ( ( V_2 -> V_19 == V_21 ) &&
( V_63 -> V_19 == V_21 ) &&
( V_2 -> type == V_63 -> type ) &&
( V_2 -> V_36 . V_49 . V_50 == V_63 -> V_36 . V_49 . V_50 ) &&
( memcmp ( & V_2 -> V_36 . V_49 . V_2 , & V_63 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) == 0 ) ) {
V_15 = 1 ;
break;
}
}
if ( V_15 ) {
V_2 -> V_52 += V_63 -> V_52 ;
if ( V_2 -> V_52 <= 0 ) {
* V_64 = V_2 ;
return - 1 ;
} else {
if ( V_2 -> type != V_55 )
V_2 -> V_52 = 1 ;
return 0 ;
}
}
if ( V_63 -> V_52 > 0 ) {
if ( V_63 -> type != V_55 )
V_63 -> V_52 = 1 ;
return 1 ;
} else
return 0 ;
}
static void F_28 ( struct V_27 * V_28 ,
unsigned long * V_58 )
{
struct V_65 V_66 ;
struct V_29 * V_2 , * V_41 ;
int V_4 ;
F_29 ( & V_66 ) ;
V_67:
F_13 (addr, tmp, &card->ip_list, entry) {
if ( V_2 -> V_46 ) {
F_14 ( & V_2 -> V_53 ) ;
F_22 ( & V_28 -> V_59 , * V_58 ) ;
V_4 = F_30 ( V_28 , V_2 ) ;
F_21 ( & V_28 -> V_59 , * V_58 ) ;
if ( ! V_4 || ( V_4 == V_68 ) )
F_15 ( V_2 ) ;
else
F_18 ( & V_2 -> V_53 , & V_66 ) ;
goto V_67;
}
}
F_31 ( & V_66 , & V_28 -> V_69 ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
struct V_65 * V_70 ;
struct V_29 * V_63 , * V_2 ;
unsigned long V_58 ;
int V_4 ;
F_17 ( V_28 , 2 , L_10 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ( V_28 -> V_71 != V_72 &&
V_28 -> V_71 != V_73 ) || V_28 -> V_43 . V_44 ) {
return;
}
F_21 ( & V_28 -> V_59 , V_58 ) ;
V_70 = V_28 -> V_54 ;
V_28 -> V_54 = F_33 ( sizeof( struct V_65 ) , V_61 ) ;
if ( ! V_28 -> V_54 ) {
F_17 ( V_28 , 0 , L_11 ) ;
V_28 -> V_54 = V_70 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
return;
} else
F_29 ( V_28 -> V_54 ) ;
while ( ! F_34 ( V_70 ) ) {
V_63 = F_35 ( V_70 -> V_74 , struct V_29 , V_53 ) ;
F_14 ( & V_63 -> V_53 ) ;
if ( V_63 -> type == V_45 ) {
F_28 ( V_28 , & V_58 ) ;
F_15 ( V_63 ) ;
continue;
}
V_4 = F_27 ( V_28 , V_63 , & V_2 ) ;
if ( V_4 == 0 ) {
F_15 ( V_63 ) ;
} else if ( V_4 == 1 ) {
F_22 ( & V_28 -> V_59 , V_58 ) ;
V_4 = F_36 ( V_28 , V_63 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( ! V_4 || ( V_4 == V_75 ) )
F_18 ( & V_63 -> V_53 , & V_28 -> V_69 ) ;
else
F_15 ( V_63 ) ;
} else if ( V_4 == - 1 ) {
F_37 ( & V_2 -> V_53 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
V_4 = F_30 ( V_28 , V_2 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( ! V_4 || ( V_4 == V_76 ) )
F_15 ( V_2 ) ;
else
F_18 ( & V_2 -> V_53 , & V_28 -> V_69 ) ;
F_15 ( V_63 ) ;
}
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
F_15 ( V_70 ) ;
}
static void F_38 ( struct V_27 * V_28 , int V_77 )
{
struct V_29 * V_2 , * V_41 ;
unsigned long V_58 ;
F_17 ( V_28 , 4 , L_12 ) ;
if ( V_77 && V_28 -> V_43 . V_44 )
return;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_13 (addr, tmp, card->ip_tbd_list, entry) {
F_14 ( & V_2 -> V_53 ) ;
F_15 ( V_2 ) ;
}
while ( ! F_34 ( & V_28 -> V_69 ) ) {
V_2 = F_35 ( V_28 -> V_69 . V_74 ,
struct V_29 , V_53 ) ;
F_37 ( & V_2 -> V_53 ) ;
if ( ! V_77 || V_2 -> V_46 ) {
F_15 ( V_2 ) ;
continue;
}
F_18 ( & V_2 -> V_53 , V_28 -> V_54 ) ;
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
static int F_39 ( struct V_65 * V_78 ,
struct V_29 * V_2 , int V_79 )
{
struct V_29 * V_41 ;
F_10 (tmp, list, entry) {
if ( ( V_41 -> V_19 == V_20 ) &&
( V_2 -> V_19 == V_20 ) &&
( ( V_79 && ( V_41 -> type == V_2 -> type ) ) ||
( ! V_79 && ( V_41 -> type != V_2 -> type ) ) ) &&
( V_41 -> V_36 . V_47 . V_2 == V_2 -> V_36 . V_47 . V_2 ) )
return 1 ;
if ( ( V_41 -> V_19 == V_21 ) &&
( V_2 -> V_19 == V_21 ) &&
( ( V_79 && ( V_41 -> type == V_2 -> type ) ) ||
( ! V_79 && ( V_41 -> type != V_2 -> type ) ) ) &&
( memcmp ( & V_41 -> V_36 . V_49 . V_2 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) == 0 ) )
return 1 ;
}
return 0 ;
}
static int F_40 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_80 )
{
int V_4 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_13 ) ;
V_82 = F_41 ( V_28 , V_80 , V_2 -> V_19 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
memcpy ( & V_84 -> V_85 . V_87 . V_88 , V_2 -> V_88 , V_89 ) ;
if ( V_2 -> V_19 == V_21 )
memcpy ( V_84 -> V_85 . V_87 . V_90 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
else
memcpy ( & V_84 -> V_85 . V_87 . V_91 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
V_4 = F_42 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static void F_43 ( T_3 * V_92 , unsigned int V_23 )
{
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_25 = ( V_23 ) - ( V_24 * 8 ) ;
if ( V_25 >= 8 )
V_92 [ V_24 ] = 0xff ;
else if ( V_25 > 0 )
V_92 [ V_24 ] = ( T_3 ) ( 0xFF00 >> V_25 ) ;
else
V_92 [ V_24 ] = 0 ;
}
}
static int F_44 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_80 , unsigned int V_58 )
{
int V_4 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_1 V_92 [ 16 ] ;
F_17 ( V_28 , 4 , L_14 ) ;
F_45 ( V_28 , 4 , L_15 , V_58 ) ;
V_82 = F_41 ( V_28 , V_80 , V_2 -> V_19 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
if ( V_2 -> V_19 == V_21 ) {
memcpy ( V_84 -> V_85 . V_93 . V_94 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
F_43 ( V_92 , V_2 -> V_36 . V_49 . V_50 ) ;
memcpy ( V_84 -> V_85 . V_93 . V_48 , V_92 ,
sizeof( struct V_51 ) ) ;
V_84 -> V_85 . V_93 . V_58 = V_58 ;
} else {
memcpy ( V_84 -> V_85 . V_95 . V_94 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
memcpy ( V_84 -> V_85 . V_95 . V_48 , & V_2 -> V_36 . V_47 . V_48 , 4 ) ;
V_84 -> V_85 . V_95 . V_58 = V_58 ;
}
V_4 = F_42 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static int F_46 ( struct V_27 * V_28 ,
enum V_96 type , enum V_18 V_60 )
{
int V_4 ;
struct V_83 * V_84 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_16 ) ;
V_82 = F_41 ( V_28 , V_97 , V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_98 . type = ( type ) ;
V_4 = F_42 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static void F_47 ( struct V_27 * V_28 ,
enum V_96 * type , enum V_18 V_60 )
{
if ( V_28 -> V_99 . type == V_100 ) {
switch ( * type ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return;
default:
goto V_105;
}
} else {
switch ( * type ) {
case V_101 :
case V_106 :
case V_107 :
return;
case V_104 :
if ( F_48 ( V_28 , V_60 ,
V_108 ) )
return;
default:
goto V_105;
}
}
V_105:
* type = V_101 ;
}
int F_49 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_17 ) ;
F_47 ( V_28 , & V_28 -> V_43 . V_109 . type ,
V_20 ) ;
V_4 = F_46 ( V_28 , V_28 -> V_43 . V_109 . type ,
V_20 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_109 . type = V_101 ;
F_50 ( 2 , L_18
L_19 , V_4 ,
F_51 ( V_28 ) ) ;
}
return V_4 ;
}
int F_52 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_20 ) ;
#ifdef F_53
if ( ! F_54 ( V_28 , V_110 ) )
return 0 ;
F_47 ( V_28 , & V_28 -> V_43 . V_111 . type ,
V_21 ) ;
V_4 = F_46 ( V_28 , V_28 -> V_43 . V_111 . type ,
V_21 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_111 . type = V_101 ;
F_50 ( 2 , L_18
L_19 , V_4 ,
F_51 ( V_28 ) ) ;
}
#endif
return V_4 ;
}
static void F_55 ( struct V_27 * V_28 )
{
struct V_30 * V_31 , * V_41 ;
unsigned long V_58 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_13 (ipatoe, tmp, &card->ipato.entries, entry) {
F_14 ( & V_31 -> V_53 ) ;
F_15 ( V_31 ) ;
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
int F_56 ( struct V_27 * V_28 ,
struct V_30 * V_112 )
{
struct V_30 * V_31 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_17 ( V_28 , 2 , L_21 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_10 (ipatoe, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_112 -> V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_112 -> V_2 ,
( V_31 -> V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_112 -> V_37 ) ) {
V_4 = - V_113 ;
break;
}
}
if ( ! V_4 )
F_18 ( & V_112 -> V_53 , & V_28 -> V_34 . V_114 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
return V_4 ;
}
void F_57 ( struct V_27 * V_28 ,
enum V_18 V_19 , T_3 * V_2 , int V_37 )
{
struct V_30 * V_31 , * V_41 ;
unsigned long V_58 ;
F_17 ( V_28 , 2 , L_22 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_13 (ipatoe, tmp, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_2 ,
( V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_37 ) ) {
F_14 ( & V_31 -> V_53 ) ;
F_15 ( V_31 ) ;
}
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
int F_58 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_115 ;
unsigned long V_58 ;
int V_4 = 0 ;
V_115 = F_24 ( V_19 ) ;
if ( V_115 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_23 ) ;
memcpy ( & V_115 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_115 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_24 ) ;
memcpy ( & V_115 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_115 -> V_36 . V_49 . V_50 = 0 ;
}
V_115 -> type = V_116 ;
V_115 -> V_56 = V_117 ;
V_115 -> V_118 = V_119 ;
} else
return - V_120 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( F_39 ( & V_28 -> V_69 , V_115 , 0 ) ||
F_39 ( V_28 -> V_54 , V_115 , 0 ) )
V_4 = - V_113 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
return V_4 ;
}
if ( ! F_23 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
return V_4 ;
}
void F_59 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_115 ;
V_115 = F_24 ( V_19 ) ;
if ( V_115 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_25 ) ;
memcpy ( & V_115 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_115 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_26 ) ;
memcpy ( & V_115 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_115 -> V_36 . V_49 . V_50 = 0 ;
}
V_115 -> type = V_116 ;
} else
return;
if ( ! F_19 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
}
int F_60 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_115 ;
unsigned long V_58 ;
int V_4 = 0 ;
V_115 = F_24 ( V_19 ) ;
if ( V_115 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_27 ) ;
memcpy ( & V_115 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_115 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_28 ) ;
memcpy ( & V_115 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_115 -> V_36 . V_49 . V_50 = 0 ;
}
V_115 -> type = V_121 ;
V_115 -> V_56 = V_57 ;
V_115 -> V_118 = 0 ;
} else
return - V_120 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( F_39 ( & V_28 -> V_69 , V_115 , 0 ) ||
F_39 ( V_28 -> V_54 , V_115 , 0 ) )
V_4 = - V_113 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
return V_4 ;
}
if ( ! F_23 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
return 0 ;
}
void F_61 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_115 ;
V_115 = F_24 ( V_19 ) ;
if ( V_115 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_27 ) ;
memcpy ( & V_115 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_115 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_28 ) ;
memcpy ( & V_115 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_115 -> V_36 . V_49 . V_50 = 0 ;
}
V_115 -> type = V_121 ;
} else
return;
if ( ! F_19 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
}
static int F_36 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
char V_1 [ 50 ] ;
int V_4 = 0 ;
int V_13 = 3 ;
if ( V_2 -> V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_29 ) ;
F_20 ( V_28 , 3 , & V_2 -> V_36 . V_47 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_30 ) ;
F_20 ( V_28 , 3 , & V_2 -> V_36 . V_49 . V_2 , 8 ) ;
F_20 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_49 . V_2 ) + 8 , 8 ) ;
} else {
F_17 ( V_28 , 2 , L_31 ) ;
F_20 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
do {
if ( V_2 -> V_46 )
V_4 = F_40 ( V_28 , V_2 , V_122 ) ;
else
V_4 = F_44 ( V_28 , V_2 , V_123 ,
V_2 -> V_56 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
} while ( ( -- V_13 > 0 ) && V_4 );
if ( V_4 ) {
F_17 ( V_28 , 2 , L_33 ) ;
F_6 ( V_2 -> V_19 , ( T_3 * ) & V_2 -> V_36 , V_1 ) ;
F_62 ( & V_28 -> V_124 -> V_125 ,
L_34 , V_1 ) ;
}
return V_4 ;
}
static int F_30 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_35 ) ;
F_20 ( V_28 , 3 , & V_2 -> V_36 . V_47 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_36 ) ;
F_20 ( V_28 , 3 , & V_2 -> V_36 . V_49 . V_2 , 8 ) ;
F_20 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_49 . V_2 ) + 8 , 8 ) ;
} else {
F_17 ( V_28 , 2 , L_37 ) ;
F_20 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
if ( V_2 -> V_46 )
V_4 = F_40 ( V_28 , V_2 , V_126 ) ;
else
V_4 = F_44 ( V_28 , V_2 , V_127 ,
V_2 -> V_118 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
return V_4 ;
}
static inline T_3 F_63 ( int V_128 )
{
if ( V_128 == V_129 )
return V_130 ;
if ( V_128 == V_131 )
return V_132 ;
return V_133 ;
}
static inline T_3 F_64 ( int V_128 )
{
T_3 V_134 = V_135 | V_136 ;
if ( V_128 == V_129 )
return V_134 | V_130 ;
if ( V_128 == V_137 )
return V_134 | V_138 ;
if ( V_128 == V_131 )
return V_134 | V_132 ;
return V_134 | V_133 ;
}
static int F_65 ( struct V_27 * V_28 , T_4 V_139 ,
T_4 V_140 )
{
int V_4 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_38 ) ;
V_82 = F_66 ( V_28 , V_139 ,
sizeof( struct V_141 ) ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_142 . V_85 . V_140 = V_140 ;
V_4 = F_42 ( V_28 , V_82 , V_143 ,
NULL ) ;
return V_4 ;
}
static int F_67 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 4 , L_39 ) ;
if ( F_68 ( V_28 , V_144 ) ) {
V_4 = F_65 ( V_28 ,
V_144 ,
V_28 -> V_43 . V_145 ) ;
if ( V_4 )
F_50 ( 2 , L_40
L_41 ,
F_69 ( V_28 ) , V_4 ) ;
V_4 = F_65 ( V_28 ,
V_146 ,
V_28 -> V_43 . V_147 ) ;
if ( V_4 )
F_50 ( 2 , L_42
L_41 , F_69 ( V_28 ) , V_4 ) ;
return V_4 ;
}
if ( V_28 -> V_43 . V_145 == V_148 )
F_50 ( 2 , L_43
L_44
L_45 , F_69 ( V_28 ) ) ;
if ( V_28 -> V_43 . V_147 == V_149 )
F_50 ( 2 , L_43
L_46
L_45 , F_69 ( V_28 ) ) ;
return 0 ;
}
static int F_70 ( struct V_27 * V_28 )
{
int V_4 ;
F_71 ( V_150 , 2 , L_47 ) ;
if ( ! F_54 ( V_28 , V_151 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_48 ) ;
F_71 ( V_150 , 2 , L_49 ) ;
return 0 ;
}
V_4 = F_73 ( V_28 ) ;
if ( V_4 ) {
F_50 ( 2 , L_50
L_51 , F_74 ( & V_28 -> V_124 -> V_125 ) , V_4 ) ;
return V_4 ;
}
if ( F_68 ( V_28 , V_146 ) ) {
V_4 = F_75 ( V_28 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_124 -> V_125 , L_52
L_53 ) ;
}
if ( ( V_28 -> V_99 . V_152 == V_153 ) ||
( V_28 -> V_99 . V_152 == V_154 ) )
V_4 = F_67 ( V_28 ) ;
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 ,
struct V_155 * V_156 , unsigned long V_85 )
{
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_54 ) ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_157 . V_158 == 0 ) {
V_84 -> V_157 . V_158 = V_84 -> V_85 . V_159 . V_157 . V_158 ;
if ( V_84 -> V_157 . V_160 == V_20 )
V_28 -> V_43 . V_161 . V_162 = V_84 -> V_157 . V_163 ;
if ( V_84 -> V_157 . V_160 == V_21 )
V_28 -> V_43 . V_164 . V_162 = V_84 -> V_157 . V_163 ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_165 == V_166 &&
V_84 -> V_85 . V_159 . V_157 . V_167 == V_168 ) {
V_28 -> V_99 . V_169 = V_84 -> V_85 . V_159 . V_85 . V_170 ;
F_45 ( V_28 , 3 , L_55 , V_28 -> V_99 . V_169 ) ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_165 == V_171 &&
V_84 -> V_85 . V_159 . V_157 . V_167 == V_168 ) {
V_28 -> V_99 . V_172 =
V_84 -> V_85 . V_159 . V_85 . V_170 ;
F_45 ( V_28 , 3 , L_56 , V_28 -> V_99 . V_172 ) ;
}
return 0 ;
}
static struct V_81 * F_77 (
struct V_27 * V_28 , enum V_173 V_174 , T_2 V_175 ,
T_2 V_23 , enum V_18 V_60 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_57 ) ;
V_82 = F_41 ( V_28 , V_176 , V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_159 . V_157 . V_165 = V_174 ;
V_84 -> V_85 . V_159 . V_157 . V_177 = 8 + V_23 ;
V_84 -> V_85 . V_159 . V_157 . V_167 = V_175 ;
V_84 -> V_85 . V_159 . V_157 . V_158 = 0 ;
V_84 -> V_85 . V_159 . V_157 . V_178 = 0 ;
return V_82 ;
}
static int F_78 ( struct V_27 * V_28 ,
struct V_81 * V_82 , T_2 V_23 , long V_85 ,
int (* F_79)( struct V_27 * , struct V_155 * ,
unsigned long ) ,
void * V_179 )
{
int V_4 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_58 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
if ( V_23 <= sizeof( T_4 ) )
V_84 -> V_85 . V_159 . V_85 . V_170 = ( T_4 ) V_85 ;
else
memcpy ( & V_84 -> V_85 . V_159 . V_85 , ( void * ) V_85 , V_23 ) ;
V_4 = F_42 ( V_28 , V_82 , F_79 , V_179 ) ;
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 ,
enum V_173 V_174 , T_2 V_175 )
{
int V_4 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_59 ) ;
V_82 = F_77 ( V_28 , V_174 , V_175 ,
0 , V_21 ) ;
V_4 = F_78 ( V_28 , V_82 , 0 , 0 ,
F_76 , NULL ) ;
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 ,
enum V_173 V_174 , T_2 V_175 , long V_85 )
{
int V_4 ;
int V_177 = 0 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_60 ) ;
if ( V_85 )
V_177 = sizeof( T_4 ) ;
V_82 = F_77 ( V_28 , V_174 , V_175 ,
V_177 , V_20 ) ;
V_4 = F_78 ( V_28 , V_82 , V_177 , V_85 ,
F_76 , NULL ) ;
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_61 ) ;
if ( ! F_54 ( V_28 , V_180 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_62 ,
F_51 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_81 ( V_28 , V_180 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_63 ,
F_51 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_83 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_64 ) ;
if ( ! F_54 ( V_28 , V_181 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_65 ,
F_51 ( V_28 ) ) ;
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_181 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_66 ,
F_51 ( V_28 ) ) ;
} else
F_72 ( & V_28 -> V_124 -> V_125 ,
L_67 ) ;
return V_4 ;
}
static int F_84 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_68 ) ;
if ( ! F_54 ( V_28 , V_183 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_69 ,
F_51 ( V_28 ) ) ;
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_183 ,
V_168 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_124 -> V_125 ,
L_70 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_71 ) ;
if ( ! F_54 ( V_28 , V_184 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_72 , F_51 ( V_28 ) ) ;
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_185 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_73 ,
F_51 ( V_28 ) ) ;
} else {
F_72 ( & V_28 -> V_124 -> V_125 , L_74 ) ;
}
return V_4 ;
}
static int F_86 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_75 ) ;
if ( ! F_54 ( V_28 , V_186 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_76 ,
F_51 ( V_28 ) ) ;
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_186 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_77 ,
F_51 ( V_28 ) ) ;
} else {
F_72 ( & V_28 -> V_124 -> V_125 , L_78 ) ;
V_28 -> V_125 -> V_58 |= V_187 ;
}
return V_4 ;
}
static int F_87 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_79 ) ;
if ( V_28 -> V_99 . type == V_100 )
goto V_14;
V_4 = F_88 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_89 ( & V_28 -> V_124 -> V_125 ,
L_80 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_81 ( V_28 , V_110 ,
V_168 , 3 ) ;
if ( V_4 ) {
F_89 ( & V_28 -> V_124 -> V_125 ,
L_80 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_80 ( V_28 , V_110 ,
V_168 ) ;
if ( V_4 ) {
F_89 ( & V_28 -> V_124 -> V_125 ,
L_80 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_80 ( V_28 , V_188 ,
V_168 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_81 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_72 ( & V_28 -> V_124 -> V_125 , L_82 ) ;
return 0 ;
}
static int F_90 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_83 ) ;
if ( ! F_54 ( V_28 , V_110 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_84 , F_51 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_53
V_4 = F_87 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_91 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_85 ) ;
V_28 -> V_99 . V_189 = 0 ;
if ( ! F_54 ( V_28 , V_190 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_86 ,
F_51 ( V_28 ) ) ;
V_4 = - V_182 ;
goto V_14;
}
V_4 = F_81 ( V_28 , V_190 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 , L_87
L_88 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_81 ( V_28 , V_190 ,
V_191 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_89 ,
F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_99 . V_189 = V_192 ;
F_72 ( & V_28 -> V_124 -> V_125 , L_90 ) ;
V_4 = F_81 ( V_28 , V_190 ,
V_193 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 , L_91
L_92 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_99 . V_189 = V_194 ;
V_14:
if ( V_28 -> V_99 . V_189 )
V_28 -> V_125 -> V_58 |= V_195 ;
else
V_28 -> V_125 -> V_58 &= ~ V_195 ;
return V_4 ;
}
static int F_92 ( struct V_27 * V_28 )
{
int V_4 ;
V_4 = F_81 ( V_28 , V_166 ,
V_168 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 , L_93
L_94 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_81 ( V_28 , V_166 ,
V_193 ,
V_28 -> V_99 . V_169 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_124 -> V_125 , L_95
L_94 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
return 0 ;
}
int F_93 ( struct V_27 * V_28 , int V_196 )
{
int V_4 = 0 ;
if ( V_196 ) {
V_4 = F_92 ( V_28 ) ;
if ( V_4 )
return - V_197 ;
F_72 ( & V_28 -> V_124 -> V_125 ,
L_96 ) ;
} else {
V_4 = F_81 ( V_28 ,
V_166 , V_198 , 0 ) ;
if ( V_4 )
return - V_197 ;
}
return 0 ;
}
static int F_94 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_97 ) ;
if ( V_28 -> V_125 -> V_199 & V_200 ) {
F_95 () ;
V_28 -> V_125 -> V_199 &= ~ V_200 ;
F_96 ( V_28 -> V_125 ) ;
F_97 () ;
}
return 0 ;
}
static int F_98 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
if ( ! F_54 ( V_28 , V_171 ) )
return V_4 ;
V_4 = F_81 ( V_28 , V_171 ,
V_168 , 0 ) ;
if ( V_4 )
goto V_201;
V_4 = F_81 ( V_28 , V_171 ,
V_193 , V_28 -> V_99 . V_172 ) ;
if ( V_4 )
goto V_201;
F_72 ( & V_28 -> V_124 -> V_125 , L_98 ) ;
return V_4 ;
V_201:
F_62 ( & V_28 -> V_124 -> V_125 , L_99
L_100 , F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_99 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_101 ) ;
if ( ! F_54 ( V_28 , V_202 ) ) {
F_72 ( & V_28 -> V_124 -> V_125 ,
L_102 ,
F_51 ( V_28 ) ) ;
V_4 = - V_182 ;
} else {
V_4 = F_81 ( V_28 , V_202 ,
V_168 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_124 -> V_125 , L_103
L_104 ,
F_51 ( V_28 ) ) ;
else
F_72 ( & V_28 -> V_124 -> V_125 ,
L_105 ) ;
}
if ( V_4 )
V_28 -> V_125 -> V_199 &= ~ V_203 ;
return V_4 ;
}
static int F_100 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_106 ) ;
F_101 ( V_28 ) ;
F_82 ( V_28 ) ;
F_83 ( V_28 ) ;
F_84 ( V_28 ) ;
F_85 ( V_28 ) ;
F_86 ( V_28 ) ;
F_90 ( V_28 ) ;
F_91 ( V_28 ) ;
F_94 ( V_28 ) ;
F_98 ( V_28 ) ;
F_99 ( V_28 ) ;
return 0 ;
}
static int F_102 ( struct V_27 * V_28 ,
struct V_155 * V_156 , unsigned long V_85 )
{
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_157 . V_158 == 0 )
memcpy ( V_28 -> V_125 -> V_204 ,
V_84 -> V_85 . V_205 . V_206 , V_207 ) ;
else
F_103 ( V_28 -> V_125 -> V_204 ) ;
return 0 ;
}
static int F_104 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_71 ( V_150 , 2 , L_107 ) ;
V_82 = F_41 ( V_28 , V_208 ,
V_21 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
* ( ( T_2 * ) & V_84 -> V_85 . V_205 . V_206 [ 6 ] ) =
V_28 -> V_99 . V_206 ;
V_4 = F_42 ( V_28 , V_82 , F_102 ,
NULL ) ;
return V_4 ;
}
static int F_105 ( struct V_27 * V_28 ,
struct V_155 * V_156 , unsigned long V_85 )
{
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_157 . V_158 == 0 )
V_28 -> V_99 . V_206 = * ( ( T_2 * )
& V_84 -> V_85 . V_205 . V_206 [ 6 ] ) ;
else {
V_28 -> V_99 . V_206 = V_209 |
V_210 ;
F_62 ( & V_28 -> V_124 -> V_125 , L_108
L_109 ) ;
}
return 0 ;
}
static int F_106 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_71 ( V_150 , 2 , L_110 ) ;
if ( ! F_54 ( V_28 , V_110 ) ) {
V_28 -> V_99 . V_206 = V_209 |
V_210 ;
return 0 ;
}
V_82 = F_41 ( V_28 , V_208 ,
V_21 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
* ( ( T_2 * ) & V_84 -> V_85 . V_205 . V_206 [ 6 ] ) =
V_28 -> V_99 . V_206 ;
V_4 = F_42 ( V_28 , V_82 , F_105 , NULL ) ;
return V_4 ;
}
static int
F_107 ( struct V_27 * V_28 , struct V_155 * V_156 ,
unsigned long V_85 )
{
struct V_83 * V_84 ;
T_2 V_4 ;
F_71 ( V_150 , 2 , L_111 ) ;
V_84 = (struct V_83 * ) V_85 ;
V_4 = V_84 -> V_157 . V_158 ;
if ( V_4 )
F_45 ( V_28 , 2 , L_112 , V_4 ) ;
switch ( V_84 -> V_85 . V_211 . V_212 ) {
case V_213 :
break;
case V_214 :
switch ( V_4 ) {
case 0 :
case V_215 :
V_28 -> V_99 . V_216 = V_217 ;
F_72 ( & V_28 -> V_124 -> V_125 , L_113
L_114 ) ;
break;
default:
break;
}
break;
case V_218 :
switch ( V_4 ) {
case 0 :
V_28 -> V_99 . V_216 = V_219 ;
F_72 ( & V_28 -> V_124 -> V_125 , L_113
L_115 ) ;
break;
case V_220 :
F_62 ( & V_28 -> V_124 -> V_125 , L_116
L_117
L_118 ) ;
break;
case V_221 :
F_62 ( & V_28 -> V_124 -> V_125 , L_119
L_120
L_121 ) ;
break;
default:
break;
}
break;
default:
F_50 ( 2 , L_122 ,
V_84 -> V_85 . V_211 . V_212 , F_51 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_108 ( struct V_27 * V_28 , enum V_222 V_223 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_71 ( V_150 , 2 , L_123 ) ;
V_82 = F_41 ( V_28 , V_224 , 0 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_211 . V_225 = 16 ;
V_84 -> V_85 . V_211 . V_226 = V_227 ;
V_84 -> V_85 . V_211 . type = V_228 ;
V_84 -> V_85 . V_211 . V_212 = V_223 ;
return F_42 ( V_28 , V_82 , F_107 , NULL ) ;
}
static void F_109 ( T_4 V_229 , char * V_88 ,
struct V_230 * V_125 )
{
if ( V_125 -> type == V_231 )
F_110 ( V_229 , V_88 ) ;
else
F_111 ( V_229 , V_88 ) ;
}
static void F_112 ( struct V_27 * V_28 , struct V_232 * V_233 )
{
struct V_29 * V_229 ;
struct V_234 * V_235 ;
char V_1 [ V_236 ] ;
F_17 ( V_28 , 4 , L_124 ) ;
for ( V_235 = F_113 ( V_233 -> V_237 ) ; V_235 != NULL ;
V_235 = F_113 ( V_235 -> V_238 ) ) {
F_109 ( V_235 -> V_239 , V_1 , V_233 -> V_125 ) ;
V_229 = F_24 ( V_20 ) ;
if ( ! V_229 )
continue;
V_229 -> V_36 . V_47 . V_2 = V_235 -> V_239 ;
memcpy ( V_229 -> V_88 , V_1 , V_89 ) ;
V_229 -> V_46 = 1 ;
if ( ! F_23 ( V_28 , V_229 ) )
F_15 ( V_229 ) ;
}
}
static void F_114 ( struct V_27 * V_28 )
{
struct V_232 * V_240 ;
struct V_241 * V_242 ;
int V_24 ;
F_17 ( V_28 , 4 , L_125 ) ;
if ( ! F_54 ( V_28 , V_184 ) || ( V_28 -> V_243 == NULL ) )
return;
V_242 = V_28 -> V_243 ;
for ( V_24 = 0 ; V_24 < V_244 ; V_24 ++ ) {
struct V_230 * V_245 = F_115 ( V_242 , V_24 ) ;
if ( V_245 == NULL ||
! ( V_245 -> V_58 & V_246 ) )
continue;
V_240 = F_116 ( V_245 ) ;
if ( ! V_240 )
continue;
F_117 () ;
F_112 ( V_28 , V_240 ) ;
F_118 () ;
F_119 ( V_240 ) ;
}
}
static void F_120 ( struct V_27 * V_28 )
{
struct V_232 * V_233 ;
F_17 ( V_28 , 4 , L_126 ) ;
V_233 = F_116 ( V_28 -> V_125 ) ;
if ( V_233 == NULL )
return;
F_117 () ;
F_112 ( V_28 , V_233 ) ;
F_114 ( V_28 ) ;
F_118 () ;
F_119 ( V_233 ) ;
}
static void F_121 ( struct V_27 * V_28 , struct V_247 * V_248 )
{
struct V_29 * V_229 ;
struct V_249 * V_250 ;
char V_1 [ V_236 ] ;
F_17 ( V_28 , 4 , L_127 ) ;
for ( V_250 = V_248 -> V_237 ; V_250 != NULL ; V_250 = V_250 -> V_74 ) {
F_122 ( & V_250 -> V_251 , V_1 , V_248 -> V_125 , 0 ) ;
V_229 = F_24 ( V_21 ) ;
if ( ! V_229 )
continue;
V_229 -> V_46 = 1 ;
memcpy ( V_229 -> V_88 , V_1 , V_89 ) ;
memcpy ( & V_229 -> V_36 . V_49 . V_2 , & V_250 -> V_251 . V_252 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_229 ) )
F_15 ( V_229 ) ;
}
}
static void F_123 ( struct V_27 * V_28 )
{
struct V_247 * V_240 ;
struct V_241 * V_242 ;
int V_24 ;
F_17 ( V_28 , 4 , L_128 ) ;
if ( ! F_54 ( V_28 , V_184 ) || ( V_28 -> V_243 == NULL ) )
return;
V_242 = V_28 -> V_243 ;
for ( V_24 = 0 ; V_24 < V_244 ; V_24 ++ ) {
struct V_230 * V_245 = F_115 ( V_242 , V_24 ) ;
if ( V_245 == NULL ||
! ( V_245 -> V_58 & V_246 ) )
continue;
V_240 = F_124 ( V_245 ) ;
if ( ! V_240 )
continue;
F_125 ( & V_240 -> V_253 ) ;
F_121 ( V_28 , V_240 ) ;
F_126 ( & V_240 -> V_253 ) ;
F_127 ( V_240 ) ;
}
}
static void F_128 ( struct V_27 * V_28 )
{
struct V_247 * V_248 ;
F_17 ( V_28 , 4 , L_129 ) ;
if ( ! F_54 ( V_28 , V_110 ) )
return ;
V_248 = F_124 ( V_28 -> V_125 ) ;
if ( V_248 == NULL )
return;
F_125 ( & V_248 -> V_253 ) ;
F_121 ( V_28 , V_248 ) ;
F_123 ( V_28 ) ;
F_126 ( & V_248 -> V_253 ) ;
F_127 ( V_248 ) ;
}
static void F_129 ( struct V_27 * V_28 ,
unsigned short V_254 )
{
struct V_232 * V_240 ;
struct V_255 * V_256 ;
struct V_29 * V_2 ;
F_17 ( V_28 , 4 , L_130 ) ;
V_240 = F_116 ( F_115 ( V_28 -> V_243 , V_254 ) ) ;
if ( ! V_240 )
return;
for ( V_256 = V_240 -> V_257 ; V_256 ; V_256 = V_256 -> V_258 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_256 -> V_259 ;
V_2 -> V_36 . V_47 . V_48 = V_256 -> V_260 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_119 ( V_240 ) ;
}
static void F_130 ( struct V_27 * V_28 ,
unsigned short V_254 )
{
#ifdef F_53
struct V_247 * V_248 ;
struct V_261 * V_256 ;
struct V_29 * V_2 ;
F_17 ( V_28 , 4 , L_131 ) ;
V_248 = F_124 ( F_115 ( V_28 -> V_243 , V_254 ) ) ;
if ( ! V_248 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_256 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_256 -> V_262 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_127 ( V_248 ) ;
#endif
}
static void F_131 ( struct V_27 * V_28 ,
unsigned short V_254 )
{
if ( ! V_28 -> V_243 )
return;
F_129 ( V_28 , V_254 ) ;
F_130 ( V_28 , V_254 ) ;
}
static void F_132 ( struct V_230 * V_125 ,
struct V_241 * V_263 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
unsigned long V_58 ;
F_17 ( V_28 , 4 , L_132 ) ;
F_21 ( & V_28 -> V_265 , V_58 ) ;
V_28 -> V_243 = V_263 ;
F_22 ( & V_28 -> V_265 , V_58 ) ;
}
static void F_133 ( struct V_230 * V_125 , unsigned short V_254 )
{
return;
}
static void F_134 ( struct V_230 * V_125 , unsigned short V_254 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
unsigned long V_58 ;
F_45 ( V_28 , 4 , L_133 , V_254 ) ;
if ( F_135 ( V_28 , V_266 ) ) {
F_17 ( V_28 , 3 , L_134 ) ;
return;
}
F_21 ( & V_28 -> V_265 , V_58 ) ;
F_131 ( V_28 , V_254 ) ;
F_136 ( V_28 -> V_243 , V_254 , NULL ) ;
F_22 ( & V_28 -> V_265 , V_58 ) ;
F_137 ( V_28 -> V_125 ) ;
}
static inline int F_138 ( struct V_27 * V_28 ,
struct V_267 * V_268 , struct V_269 * V_157 ,
unsigned short * V_270 )
{
T_5 V_60 ;
struct V_271 * V_272 ;
unsigned char V_273 [ V_236 ] ;
int V_274 = 0 ;
if ( ! ( V_157 -> V_157 . V_275 . V_58 & V_135 ) ) {
V_60 = F_139 ( ( V_157 -> V_157 . V_275 . V_58 & V_136 ) ? V_276 :
V_277 ) ;
switch ( V_157 -> V_157 . V_275 . V_58 & V_278 ) {
case V_130 :
switch ( V_60 ) {
#ifdef F_53
case F_140 ( V_276 ) :
F_122 ( (struct V_51 * )
V_268 -> V_85 + 24 ,
V_273 , V_28 -> V_125 , 0 ) ;
break;
#endif
case F_140 ( V_277 ) :
V_272 = (struct V_271 * ) V_268 -> V_85 ;
( V_28 -> V_125 -> type == V_231 ) ?
F_110 ( V_272 -> V_279 , V_273 ) :
F_111 ( V_272 -> V_279 , V_273 ) ;
break;
default:
memcpy ( V_273 , V_28 -> V_125 -> V_280 ,
V_28 -> V_125 -> V_281 ) ;
}
V_28 -> V_282 . V_283 ++ ;
V_268 -> V_284 = V_285 ;
break;
case V_132 :
memcpy ( V_273 , V_28 -> V_125 -> V_280 ,
V_28 -> V_125 -> V_281 ) ;
V_28 -> V_282 . V_283 ++ ;
V_268 -> V_284 = V_286 ;
break;
case V_133 :
case V_138 :
case V_287 :
default:
if ( V_28 -> V_43 . V_44 )
V_268 -> V_284 = V_288 ;
else
V_268 -> V_284 = V_289 ;
memcpy ( V_273 , V_28 -> V_125 -> V_204 ,
V_28 -> V_125 -> V_281 ) ;
}
if ( V_157 -> V_157 . V_275 . V_290 & V_291 )
V_28 -> V_125 -> V_292 -> V_293 ( V_268 , V_28 -> V_125 , V_60 ,
V_273 , & V_157 -> V_157 . V_275 . V_294 [ 2 ] ,
V_28 -> V_125 -> V_281 ) ;
else
V_28 -> V_125 -> V_292 -> V_293 ( V_268 , V_28 -> V_125 , V_60 ,
V_273 , L_135 , V_28 -> V_125 -> V_281 ) ;
}
#ifdef F_141
if ( V_28 -> V_125 -> type == V_231 )
V_268 -> V_295 = F_142 ( V_268 , V_28 -> V_125 ) ;
else
#endif
V_268 -> V_295 = F_143 ( V_268 , V_28 -> V_125 ) ;
if ( V_157 -> V_157 . V_275 . V_290 &
( V_296 | V_297 ) ) {
* V_270 = ( V_157 -> V_157 . V_275 . V_290 & V_296 ) ?
V_157 -> V_157 . V_275 . V_270 : * ( ( V_298 * ) & V_157 -> V_157 . V_275 . V_294 [ 12 ] ) ;
V_274 = 1 ;
}
if ( V_28 -> V_125 -> V_199 & V_200 ) {
if ( ( V_157 -> V_157 . V_275 . V_290 &
( V_299 |
V_300 ) ) ==
( V_299 |
V_300 ) )
V_268 -> V_301 = V_302 ;
else
V_268 -> V_301 = V_303 ;
} else
V_268 -> V_301 = V_303 ;
return V_274 ;
}
static int F_144 ( struct V_27 * V_28 ,
int V_304 , int * V_305 )
{
int V_306 = 0 ;
struct V_267 * V_268 ;
struct V_269 * V_157 ;
T_2 V_307 = 0 ;
int V_274 ;
unsigned int V_23 ;
* V_305 = 0 ;
F_145 ( ! V_304 ) ;
while ( V_304 ) {
V_268 = F_146 ( V_28 ,
V_28 -> V_308 . V_309 -> V_310 [ V_28 -> V_311 . V_312 ] . V_313 ,
& V_28 -> V_311 . V_314 , & V_28 -> V_311 . V_315 , & V_157 ) ;
if ( ! V_268 ) {
* V_305 = 1 ;
break;
}
V_268 -> V_125 = V_28 -> V_125 ;
switch ( V_157 -> V_157 . V_275 . V_316 ) {
case V_317 :
V_274 = F_138 ( V_28 , V_268 , V_157 ,
& V_307 ) ;
V_23 = V_268 -> V_23 ;
if ( V_274 && ! V_28 -> V_43 . V_44 )
F_147 ( & V_28 -> V_318 , V_28 -> V_243 ,
V_307 , V_268 ) ;
else
F_148 ( & V_28 -> V_318 , V_268 ) ;
break;
case V_319 :
V_268 -> V_284 = V_289 ;
V_268 -> V_295 = F_143 ( V_268 , V_268 -> V_125 ) ;
V_23 = V_268 -> V_23 ;
F_149 ( V_268 ) ;
break;
default:
F_150 ( V_268 ) ;
F_17 ( V_28 , 3 , L_136 ) ;
F_151 ( V_320 , 3 , V_157 , V_321 ) ;
continue;
}
V_306 ++ ;
V_304 -- ;
V_28 -> V_282 . V_322 ++ ;
V_28 -> V_282 . V_323 += V_23 ;
}
return V_306 ;
}
static int F_152 ( struct V_324 * V_318 , int V_304 )
{
struct V_27 * V_28 = F_153 ( V_318 , struct V_27 , V_318 ) ;
int V_306 = 0 ;
struct V_325 * V_313 ;
int V_305 ;
int V_326 = V_304 ;
if ( V_28 -> V_43 . V_327 ) {
V_28 -> V_328 . V_329 ++ ;
V_28 -> V_328 . V_330 = F_154 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_311 . V_331 ) {
V_28 -> V_311 . V_332 = 0 ;
V_28 -> V_311 . V_331 = F_155 (
V_28 -> V_85 . V_333 , 0 , & V_28 -> V_311 . V_312 ,
& V_28 -> V_311 . V_332 ) ;
if ( V_28 -> V_311 . V_331 <= 0 ) {
V_28 -> V_311 . V_331 = 0 ;
break;
}
V_28 -> V_311 . V_314 =
& V_28 -> V_308 . V_309 -> V_310 [ V_28 -> V_311 . V_312 ]
. V_313 -> V_334 [ 0 ] ;
V_28 -> V_311 . V_315 = 0 ;
}
while ( V_28 -> V_311 . V_331 ) {
V_313 = & V_28 -> V_308 . V_309 -> V_310 [ V_28 -> V_311 . V_312 ] ;
if ( ! ( V_28 -> V_311 . V_332 &&
F_156 ( V_28 , V_313 -> V_313 ,
V_28 -> V_311 . V_332 , L_137 ) ) )
V_306 += F_144 (
V_28 , V_326 , & V_305 ) ;
else
V_305 = 1 ;
if ( V_305 ) {
if ( V_28 -> V_43 . V_327 )
V_28 -> V_328 . V_335 ++ ;
F_157 ( V_28 ,
V_313 -> V_336 ) ;
F_158 ( V_28 , V_28 -> V_311 . V_312 ) ;
V_28 -> V_311 . V_331 -- ;
if ( V_28 -> V_311 . V_331 ) {
V_28 -> V_311 . V_312 =
( V_28 -> V_311 . V_312 + 1 ) %
V_337 ;
V_28 -> V_311 . V_314 =
& V_28 -> V_308 . V_309
-> V_310 [ V_28 -> V_311 . V_312 ]
. V_313 -> V_334 [ 0 ] ;
V_28 -> V_311 . V_315 = 0 ;
}
}
if ( V_306 >= V_304 )
goto V_14;
else
V_326 = V_304 - V_306 ;
}
}
F_159 ( V_318 ) ;
if ( F_160 ( V_28 -> V_85 . V_333 , 0 ) )
F_161 ( & V_28 -> V_318 ) ;
V_14:
if ( V_28 -> V_43 . V_327 )
V_28 -> V_328 . V_338 += F_154 () -
V_28 -> V_328 . V_330 ;
return V_306 ;
}
static int F_162 ( struct V_230 * V_125 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_241 * V_242 ;
int V_24 ;
V_242 = V_28 -> V_243 ;
if ( ! V_242 )
return V_4 ;
for ( V_24 = 0 ; V_24 < V_244 ; V_24 ++ ) {
if ( F_115 ( V_242 , V_24 ) == V_125 ) {
V_4 = V_339 ;
break;
}
}
if ( V_4 && ! ( F_163 ( V_125 ) -> V_264 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_164 ( struct V_230 * V_125 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_165 ( & V_340 . V_341 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_125 == V_125 ) {
V_4 = V_342 ;
break;
}
V_4 = F_162 ( V_125 , V_28 ) ;
if ( V_4 )
break;
}
F_166 ( & V_340 . V_341 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_167 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_164 ( V_125 ) ;
if ( V_4 == V_342 )
V_28 = V_125 -> V_264 ;
else if ( V_4 == V_339 )
V_28 = F_163 ( V_125 ) -> V_264 ;
if ( V_28 && V_28 -> V_43 . V_343 )
V_28 = NULL ;
if ( V_28 )
F_45 ( V_28 , 4 , L_138 , V_4 ) ;
return V_28 ;
}
static int F_168 ( struct V_27 * V_28 , int V_344 )
{
int V_4 = 0 ;
F_71 ( V_150 , 2 , L_139 ) ;
F_151 ( V_150 , 2 , & V_28 , sizeof( void * ) ) ;
F_169 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_99 . V_216 == V_219 ) )
F_108 ( V_28 , V_214 ) ;
if ( V_28 -> V_345 . V_71 == V_346 &&
V_28 -> V_347 . V_71 == V_346 &&
( V_28 -> V_71 == V_72 ) ) {
if ( V_344 )
F_170 ( V_28 -> V_125 ) ;
else {
F_95 () ;
F_171 ( V_28 -> V_125 ) ;
F_97 () ;
}
V_28 -> V_71 = V_73 ;
}
if ( V_28 -> V_71 == V_73 ) {
F_38 ( V_28 , 1 ) ;
F_172 ( V_28 ) ;
V_28 -> V_71 = V_348 ;
}
if ( V_28 -> V_71 == V_348 ) {
F_173 ( V_28 , 0 ) ;
F_174 ( V_28 ) ;
F_175 ( V_28 ) ;
V_28 -> V_71 = V_349 ;
}
if ( V_28 -> V_71 == V_349 ) {
F_176 ( & V_28 -> V_345 ) ;
F_176 ( & V_28 -> V_347 ) ;
}
return V_4 ;
}
static void
F_177 ( struct V_27 * V_28 )
{
struct V_230 * V_125 = V_28 -> V_125 ;
if ( ( ( V_125 -> V_58 & V_350 ) &&
( V_28 -> V_99 . V_216 == V_219 ) ) ||
( ! ( V_125 -> V_58 & V_350 ) &&
( V_28 -> V_99 . V_216 == V_217 ) ) )
return;
if ( V_28 -> V_99 . V_351 ) {
if ( F_68 ( V_28 , V_352 ) )
F_178 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_68 ( V_28 , V_353 ) ) {
if ( V_125 -> V_58 & V_350 ) {
F_17 ( V_28 , 3 , L_140 ) ;
F_108 ( V_28 , V_218 ) ;
} else {
F_17 ( V_28 , 3 , L_141 ) ;
F_108 ( V_28 , V_214 ) ;
}
}
}
static void F_137 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
F_17 ( V_28 , 3 , L_142 ) ;
if ( F_179 ( V_28 , V_266 ) &&
( V_28 -> V_71 != V_72 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_120 ( V_28 ) ;
#ifdef F_53
F_128 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_68 ( V_28 , V_352 ) )
return;
}
F_177 ( V_28 ) ;
}
static const char * F_180 ( int * V_4 )
{
switch ( * V_4 ) {
case V_354 :
* V_4 = - V_197 ;
return L_143 ;
case V_355 :
* V_4 = - V_182 ;
return L_144 ;
case V_356 :
* V_4 = - V_7 ;
return L_145 ;
case V_357 :
* V_4 = - V_182 ;
return L_146 ;
case V_358 :
* V_4 = - V_359 ;
return L_147 ;
default:
return L_148 ;
}
}
static int F_181 ( struct V_27 * V_28 , int V_360 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_149 ) ;
if ( V_28 -> V_99 . V_351 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_180 ,
V_361 ,
V_360 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_150
L_151 , F_51 ( V_28 ) ,
F_180 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static T_4 F_182 ( struct V_27 * V_28 ,
struct V_362 * V_363 ,
struct V_364 * type , T_1 V_365 )
{
T_4 V_4 ;
T_1 V_366 ;
V_366 = V_363 -> V_367 == 5 ;
if ( type -> V_368 == V_369 ) {
F_17 ( V_28 , 4 , L_152 ) ;
if ( V_365 ) {
V_4 = V_366 ? sizeof( struct V_370 ) :
sizeof( struct V_371 ) ;
} else {
V_4 = V_366 ? sizeof( struct V_372 ) :
sizeof( struct V_373 ) ;
}
} else if ( type -> V_368 == V_374 ) {
F_17 ( V_28 , 4 , L_153 ) ;
if ( V_365 ) {
V_4 = V_366 ?
sizeof( struct V_375 ) :
sizeof( struct V_376 ) ;
} else {
V_4 = V_366 ?
sizeof( struct V_377 ) :
sizeof( struct V_378 ) ;
}
} else {
F_17 ( V_28 , 4 , L_154 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_183 ( struct V_364 * type , T_2 V_60 )
{
return ( type -> V_368 == V_369 && V_60 == V_20 ) ||
( type -> V_368 == V_374 && V_60 == V_21 ) ;
}
static int F_184 ( struct V_27 * V_28 ,
struct V_155 * V_156 , unsigned long V_85 )
{
struct V_83 * V_84 ;
struct V_362 * V_363 ;
struct V_379 * V_380 ;
int V_24 ;
int V_381 ;
int V_382 ;
int V_383 ;
T_1 V_384 ;
F_17 ( V_28 , 3 , L_155 ) ;
V_380 = (struct V_379 * ) V_156 -> V_385 ;
V_84 = (struct V_83 * ) V_85 ;
F_45 ( V_28 , 4 , L_156 , V_84 -> V_157 . V_160 ) ;
if ( V_84 -> V_157 . V_158 ) {
F_17 ( V_28 , 4 , L_157 ) ;
F_45 ( V_28 , 4 , L_156 , V_84 -> V_157 . V_158 ) ;
return 0 ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_158 ) {
V_84 -> V_157 . V_158 = V_84 -> V_85 . V_159 . V_157 . V_158 ;
F_17 ( V_28 , 4 , L_158 ) ;
F_45 ( V_28 , 4 , L_156 , V_84 -> V_157 . V_158 ) ;
return 0 ;
}
V_363 = & V_84 -> V_85 . V_159 . V_85 . V_386 ;
F_45 ( V_28 , 4 , L_159 , V_363 -> V_360 ) ;
V_384 = ( V_380 -> V_37 & V_387 ) > 0 ;
V_383 = V_384 ? V_388 : 0 ;
V_382 = 0 ;
for ( V_381 = 0 ; V_381 < V_363 -> V_360 ; ++ V_381 ) {
char * V_389 ;
T_4 V_390 ;
struct V_364 * V_391 ;
V_389 = & V_363 -> V_85 + V_382 ;
V_391 = & ( (struct V_372 * ) V_389 ) -> type ;
if ( ! F_183 ( V_391 , V_84 -> V_157 . V_160 ) ) {
F_17 ( V_28 , 4 , L_160 ) ;
F_45 ( V_28 , 4 , L_156 , V_391 -> V_368 ) ;
break;
}
V_390 = F_182 ( V_28 , V_363 , V_391 ,
V_384 ) ;
F_45 ( V_28 , 5 , L_161 , V_390 ) ;
if ( ! V_390 )
break;
if ( ( V_380 -> V_392 - V_380 -> V_393 ) < V_390 ) {
F_45 ( V_28 , 4 , L_162 , - V_120 ) ;
V_84 -> V_157 . V_158 = - V_120 ;
goto V_394;
}
memcpy ( V_380 -> V_395 + V_380 -> V_393 ,
& V_363 -> V_85 + V_382 + V_383 ,
V_390 ) ;
V_382 += V_390 + V_383 ;
V_380 -> V_393 += V_390 ;
++ V_380 -> V_360 ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_178 <
V_84 -> V_85 . V_159 . V_157 . V_396 )
return 1 ;
F_45 ( V_28 , 4 , L_163 , V_380 -> V_360 ) ;
memcpy ( V_380 -> V_395 , & V_380 -> V_360 , 4 ) ;
if ( V_380 -> V_37 & V_387 )
V_363 -> V_367 |= V_387 ;
memcpy ( V_380 -> V_395 + V_397 , & V_363 -> V_367 , 2 ) ;
F_45 ( V_28 , 4 , L_164 , 0 ) ;
return 0 ;
V_394:
V_24 = 0 ;
memcpy ( V_380 -> V_395 , & V_24 , 4 ) ;
return 0 ;
}
static int F_185 ( struct V_27 * V_28 ,
struct V_81 * V_82 , int V_23 ,
int (* F_79)( struct V_27 * , struct V_155 * ,
unsigned long ) ,
void * V_179 )
{
F_17 ( V_28 , 4 , L_165 ) ;
memcpy ( V_82 -> V_85 , V_398 , V_86 ) ;
memcpy ( F_186 ( V_82 -> V_85 ) ,
& V_28 -> V_399 . V_400 , V_401 ) ;
return F_187 ( V_28 , V_86 + V_23 , V_82 ,
F_79 , V_179 ) ;
}
static int F_188 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_379 * V_380 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_41 ;
int V_4 ;
F_45 ( V_28 , 3 , L_166 , V_60 ) ;
V_82 = F_77 ( V_28 , V_180 ,
V_402 ,
sizeof( struct V_362 ) - sizeof( char ) ,
V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_159 . V_85 . V_386 . V_403 = 0x000F ;
V_84 -> V_85 . V_159 . V_85 . V_386 . V_367 = 0 ;
V_84 -> V_85 . V_159 . V_85 . V_386 . V_360 = 0 ;
V_4 = F_185 ( V_28 , V_82 ,
V_404 + V_405 ,
F_184 , ( void * ) V_380 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 ,
L_167
L_168 , F_51 ( V_28 ) ,
F_180 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_189 ( struct V_27 * V_28 , char T_6 * V_395 )
{
struct V_379 V_380 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_169 ) ;
if ( ! F_54 ( V_28 ,
V_180 ) ) {
F_17 ( V_28 , 3 , L_170 ) ;
V_4 = - V_182 ;
goto V_14;
}
if ( F_190 ( & V_380 , V_395 , 6 ) ) {
V_4 = - V_406 ;
goto V_14;
}
V_380 . V_395 = F_25 ( V_380 . V_392 , V_407 ) ;
if ( ! V_380 . V_395 ) {
V_4 = - V_120 ;
goto V_14;
}
V_380 . V_393 = V_408 ;
V_4 = F_188 ( V_28 , V_20 , & V_380 ) ;
if ( V_4 ) {
if ( F_191 ( V_395 , V_380 . V_395 , 4 ) )
V_4 = - V_406 ;
goto V_409;
} else {
#ifdef F_53
if ( V_380 . V_37 & V_410 ) {
F_188 ( V_28 , V_21 ,
& V_380 ) ;
}
#endif
if ( F_191 ( V_395 , V_380 . V_395 , V_380 . V_392 ) ) {
F_17 ( V_28 , 4 , L_171 ) ;
V_4 = - V_406 ;
goto V_409;
}
F_45 ( V_28 , 4 , L_172 ) ;
}
V_409:
F_15 ( V_380 . V_395 ) ;
V_14:
return V_4 ;
}
static int F_192 ( struct V_27 * V_28 ,
struct V_411 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_173 ) ;
if ( V_28 -> V_99 . V_351 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_82 = F_77 ( V_28 , V_180 ,
V_412 ,
sizeof( struct V_411 ) ,
V_20 ) ;
V_4 = F_78 ( V_28 , V_82 ,
sizeof( struct V_411 ) ,
( unsigned long ) V_53 ,
F_76 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_50 ( 2 , L_174
L_175 , V_1 , F_51 ( V_28 ) ,
F_180 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_193 ( struct V_27 * V_28 ,
struct V_411 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_176 ) ;
if ( V_28 -> V_99 . V_351 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_82 = F_77 ( V_28 , V_180 ,
V_413 ,
12 ,
V_20 ) ;
V_4 = F_78 ( V_28 , V_82 ,
12 , ( unsigned long ) V_1 ,
F_76 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_50 ( 2 , L_177
L_178 , V_1 , F_51 ( V_28 ) ,
F_180 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_194 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_179 ) ;
if ( V_28 -> V_99 . V_351 || ( V_28 -> V_99 . type == V_100 ) )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_180 ,
V_414 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_180
L_168 , F_51 ( V_28 ) ,
F_180 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_195 ( struct V_230 * V_125 , struct V_415 * V_416 , int V_84 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
struct V_411 V_417 ;
struct V_418 * V_419 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_420 ;
if ( ( V_28 -> V_71 != V_72 ) &&
( V_28 -> V_71 != V_73 ) )
return - V_420 ;
switch ( V_84 ) {
case V_421 :
if ( ! F_196 ( V_422 ) ) {
V_4 = - V_423 ;
break;
}
V_4 = F_181 ( V_28 , V_416 -> V_424 . V_425 ) ;
break;
case V_426 :
if ( ! F_196 ( V_422 ) ) {
V_4 = - V_423 ;
break;
}
V_4 = F_189 ( V_28 , V_416 -> V_424 . V_427 ) ;
break;
case V_428 :
if ( ! F_196 ( V_422 ) ) {
V_4 = - V_423 ;
break;
}
if ( F_190 ( & V_417 , V_416 -> V_424 . V_427 ,
sizeof( struct V_411 ) ) )
V_4 = - V_406 ;
else
V_4 = F_192 ( V_28 , & V_417 ) ;
break;
case V_429 :
if ( ! F_196 ( V_422 ) ) {
V_4 = - V_423 ;
break;
}
if ( F_190 ( & V_417 , V_416 -> V_424 . V_427 ,
sizeof( struct V_411 ) ) )
V_4 = - V_406 ;
else
V_4 = F_193 ( V_28 , & V_417 ) ;
break;
case V_430 :
if ( ! F_196 ( V_422 ) ) {
V_4 = - V_423 ;
break;
}
V_4 = F_194 ( V_28 ) ;
break;
case V_431 :
V_4 = F_197 ( V_28 , V_416 -> V_424 . V_427 ) ;
break;
case V_432 :
if ( ( V_28 -> V_99 . type == V_433 ||
V_28 -> V_99 . type == V_434 ) &&
! V_28 -> V_99 . V_351 )
return 1 ;
return 0 ;
break;
case V_435 :
V_419 = F_198 ( V_416 ) ;
V_419 -> V_436 = 0 ;
break;
case V_437 :
V_419 = F_198 ( V_416 ) ;
if ( V_419 -> V_436 != 0 )
V_4 = - V_7 ;
else
V_419 -> V_438 = F_199 ( V_125 ,
V_419 -> V_436 ,
V_419 -> V_439 ) ;
break;
default:
V_4 = - V_182 ;
}
if ( V_4 )
F_45 ( V_28 , 2 , L_181 , V_4 ) ;
return V_4 ;
}
int inline F_200 ( struct V_27 * V_28 , struct V_267 * V_268 )
{
int V_128 = V_440 ;
if ( F_201 ( V_268 ) && F_201 ( V_268 ) -> V_441 ) {
V_128 = F_201 ( V_268 ) -> V_441 -> type ;
if ( ( V_128 == V_131 ) ||
( V_128 == V_129 ) ||
( V_128 == V_137 ) )
return V_128 ;
else
return V_440 ;
}
if ( V_268 -> V_295 == V_276 )
return ( F_202 ( V_268 ) [ 24 ] == 0xff ) ?
V_129 : 0 ;
else if ( V_268 -> V_295 == V_277 )
return ( ( F_202 ( V_268 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_129 : 0 ;
if ( ! memcmp ( V_268 -> V_85 , V_268 -> V_125 -> V_280 , 6 ) )
return V_131 ;
else {
V_298 V_442 ;
V_442 = * ( ( V_298 * ) V_268 -> V_85 ) ;
switch ( V_28 -> V_99 . V_152 ) {
case V_153 :
case V_154 :
if ( ( V_442 == V_443 ) ||
( V_442 == V_444 ) )
return V_129 ;
break;
default:
if ( ( V_442 == V_445 ) ||
( V_442 == V_446 ) )
return V_129 ;
}
}
return V_128 ;
}
static void F_203 ( struct V_27 * V_28 , struct V_269 * V_157 ,
struct V_267 * V_268 , int V_447 , int V_128 )
{
memset ( V_157 , 0 , sizeof( struct V_269 ) ) ;
V_157 -> V_157 . V_275 . V_316 = V_317 ;
V_157 -> V_157 . V_275 . V_290 = 0 ;
if ( V_28 -> V_243 && F_204 ( V_268 ) ) {
if ( ( V_447 == 4 ) || ( V_28 -> V_99 . type == V_100 ) )
V_157 -> V_157 . V_275 . V_290 = V_296 ;
else
V_157 -> V_157 . V_275 . V_290 = V_297 ;
V_157 -> V_157 . V_275 . V_270 = F_205 ( V_268 ) ;
}
V_157 -> V_157 . V_275 . V_177 = V_268 -> V_23 - sizeof( struct V_269 ) ;
if ( V_447 == 4 ) {
V_157 -> V_157 . V_275 . V_58 = F_63 ( V_128 ) ;
memset ( V_157 -> V_157 . V_275 . V_294 , 0 , 12 ) ;
if ( ( F_201 ( V_268 ) ) && ( F_201 ( V_268 ) -> V_441 ) ) {
* ( ( V_448 * ) ( & V_157 -> V_157 . V_275 . V_294 [ 12 ] ) ) =
* ( ( V_448 * ) F_201 ( V_268 ) -> V_441 -> V_449 ) ;
} else {
* ( ( V_448 * ) ( & V_157 -> V_157 . V_275 . V_294 [ 12 ] ) ) =
V_272 ( V_268 ) -> V_279 ;
}
} else if ( V_447 == 6 ) {
V_157 -> V_157 . V_275 . V_58 = F_64 ( V_128 ) ;
if ( V_28 -> V_99 . type == V_100 )
V_157 -> V_157 . V_275 . V_58 &= ~ V_135 ;
if ( ( F_201 ( V_268 ) ) && ( F_201 ( V_268 ) -> V_441 ) ) {
memcpy ( V_157 -> V_157 . V_275 . V_294 ,
F_201 ( V_268 ) -> V_441 -> V_449 , 16 ) ;
} else {
memcpy ( V_157 -> V_157 . V_275 . V_294 ,
& F_206 ( V_268 ) -> V_279 , 16 ) ;
}
} else {
if ( ( V_268 -> V_125 -> type == V_231 ) &&
! memcmp ( V_268 -> V_85 + sizeof( struct V_269 ) +
sizeof( T_2 ) , V_268 -> V_125 -> V_280 , 6 ) ) {
V_157 -> V_157 . V_275 . V_58 = V_132 |
V_135 ;
} else if ( ! memcmp ( V_268 -> V_85 + sizeof( struct V_269 ) ,
V_268 -> V_125 -> V_280 , 6 ) ) {
V_157 -> V_157 . V_275 . V_58 = V_132 |
V_135 ;
} else {
V_157 -> V_157 . V_275 . V_58 = ( V_128 == V_129 ) ?
V_130 | V_135 :
V_133 | V_135 ;
}
}
}
static inline void F_207 ( struct V_27 * V_28 ,
struct V_269 * V_157 , struct V_267 * V_268 )
{
struct V_271 * V_450 = V_272 ( V_268 ) ;
if ( V_450 -> V_295 == V_451 )
V_157 -> V_157 . V_275 . V_290 |= V_452 ;
V_157 -> V_157 . V_275 . V_290 |= V_300 |
V_299 ;
V_450 -> V_453 = 0 ;
if ( V_28 -> V_43 . V_327 )
V_28 -> V_328 . V_454 ++ ;
}
static void F_208 ( struct V_27 * V_28 ,
struct V_269 * V_455 , struct V_267 * V_268 )
{
struct V_456 * V_157 = (struct V_456 * ) V_455 ;
struct V_457 * V_458 = F_209 ( V_268 ) ;
struct V_271 * V_450 = V_272 ( V_268 ) ;
struct V_459 * V_460 = F_206 ( V_268 ) ;
V_157 -> V_157 . V_157 . V_275 . V_316 = V_461 ;
V_157 -> V_157 . V_157 . V_275 . V_177 = V_268 -> V_23 - sizeof( struct V_456 ) ;
V_157 -> V_462 . V_463 = ( T_2 ) sizeof( struct V_464 ) ;
V_157 -> V_462 . V_465 = 1 ;
V_157 -> V_462 . V_466 = 1 ;
V_157 -> V_462 . V_467 = 1 ;
V_157 -> V_462 . V_468 = 28 ;
V_157 -> V_462 . V_469 = F_210 ( V_268 ) -> V_470 ;
V_157 -> V_462 . V_471 = ( T_2 ) ( V_450 -> V_472 * 4 + V_458 -> V_473 * 4 ) ;
V_157 -> V_462 . V_474 = ( T_2 ) ( V_268 -> V_23 - V_157 -> V_462 . V_471 -
sizeof( struct V_456 ) ) ;
V_458 -> V_453 = 0 ;
if ( V_268 -> V_295 == V_276 ) {
V_460 -> V_474 = 0 ;
V_458 -> V_453 = ~ F_211 ( & V_460 -> V_475 , & V_460 -> V_279 ,
0 , V_476 , 0 ) ;
} else {
V_458 -> V_453 = ~ F_212 ( V_450 -> V_475 , V_450 -> V_279 ,
0 , V_476 , 0 ) ;
V_450 -> V_477 = 0 ;
V_450 -> V_453 = 0 ;
}
}
static inline int F_213 ( struct V_267 * V_268 )
{
unsigned long V_478 = ( unsigned long ) F_209 ( V_268 ) +
F_209 ( V_268 ) -> V_473 * 4 ;
int V_479 = V_268 -> V_23 - ( V_478 - ( unsigned long ) V_268 -> V_85 ) ;
int V_480 = F_214 ( V_478 + V_479 - 1 ) - F_215 ( V_478 ) ;
V_480 += F_210 ( V_268 ) -> V_481 ;
return V_480 ;
}
static int F_216 ( struct V_267 * V_268 , struct V_230 * V_125 )
{
int V_4 ;
V_298 * V_482 ;
struct V_269 * V_157 = NULL ;
int V_483 = 0 ;
int V_484 ;
struct V_27 * V_28 = V_125 -> V_264 ;
struct V_267 * V_485 = NULL ;
int V_447 = F_217 ( V_268 ) ;
int V_128 = F_200 ( V_28 , V_268 ) ;
struct V_486 * V_487 = V_28 -> V_308 . V_488
[ F_218 ( V_28 , V_268 , V_447 , V_128 ) ] ;
int V_489 = V_268 -> V_23 ;
bool V_490 ;
int V_491 = - 1 ;
int V_481 ;
if ( ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_447 ) ) ||
V_28 -> V_43 . V_44 )
goto V_492;
if ( ( V_28 -> V_71 != V_72 ) || ! V_28 -> V_493 ) {
V_28 -> V_282 . V_494 ++ ;
goto V_492;
}
if ( ( V_128 == V_131 ) &&
( V_28 -> V_99 . V_189 == 0 ) )
goto V_492;
if ( V_28 -> V_43 . V_327 ) {
V_28 -> V_328 . V_495 ++ ;
V_28 -> V_328 . V_496 = F_154 () ;
}
V_490 = F_219 ( V_268 ) ;
if ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_490 ) &&
( F_210 ( V_268 ) -> V_481 == 0 ) ) {
V_485 = V_268 ;
V_491 = V_497 ;
V_157 = F_220 ( V_498 , V_61 ) ;
if ( ! V_157 )
goto V_492;
V_483 ++ ;
} else {
V_485 = F_221 ( V_268 , sizeof( struct V_456 )
+ V_499 ) ;
if ( ! V_485 )
goto V_492;
}
if ( V_28 -> V_99 . type == V_100 ) {
if ( V_491 < 0 )
F_222 ( V_485 , V_497 ) ;
} else {
if ( V_447 == 4 ) {
if ( V_28 -> V_125 -> type == V_231 )
F_222 ( V_485 , V_500 ) ;
else
F_222 ( V_485 , V_497 ) ;
}
if ( V_447 != 4 && V_28 -> V_243 &&
F_204 ( V_485 ) ) {
F_223 ( V_485 , V_499 ) ;
F_224 ( V_485 , V_485 -> V_85 + 4 , 4 ) ;
F_225 ( V_485 , 4 ,
V_485 -> V_85 + 8 , 4 ) ;
F_225 ( V_485 , 8 ,
V_485 -> V_85 + 12 , 4 ) ;
V_482 = ( V_298 * ) ( V_485 -> V_85 + 12 ) ;
* V_482 = F_140 ( V_501 ) ;
* ( V_482 + 1 ) = F_139 ( F_205 ( V_485 ) ) ;
V_485 -> V_502 = 0 ;
}
}
F_226 ( V_125 ) ;
if ( V_490 ) {
if ( F_213 ( V_485 ) + 1 > 16 ) {
if ( F_227 ( V_485 ) )
goto V_492;
if ( V_28 -> V_43 . V_327 )
V_28 -> V_328 . V_503 ++ ;
}
}
if ( V_490 && ( V_128 == V_440 ) ) {
V_157 = (struct V_269 * ) F_223 ( V_485 ,
sizeof( struct V_456 ) ) ;
memset ( V_157 , 0 , sizeof( struct V_456 ) ) ;
F_203 ( V_28 , V_157 , V_485 , V_447 , V_128 ) ;
F_208 ( V_28 , V_157 , V_485 ) ;
V_483 ++ ;
} else {
if ( V_491 < 0 ) {
V_157 = (struct V_269 * ) F_223 ( V_485 ,
sizeof( struct V_269 ) ) ;
F_203 ( V_28 , V_157 , V_485 , V_447 ,
V_128 ) ;
} else {
F_203 ( V_28 , V_157 , V_485 , V_447 ,
V_128 ) ;
V_157 -> V_157 . V_275 . V_177 = V_485 -> V_23 - V_491 ;
}
if ( V_268 -> V_301 == V_504 )
F_207 ( V_28 , V_157 , V_485 ) ;
}
V_484 = F_228 ( V_28 , ( void * ) V_157 , V_485 ,
V_483 ) ;
if ( ! V_484 ) {
if ( V_491 >= 0 )
F_229 ( V_498 , V_157 ) ;
goto V_492;
}
V_483 += V_484 ;
V_481 = F_210 ( V_485 ) -> V_481 ;
if ( V_28 -> V_99 . type != V_100 ) {
int V_23 ;
if ( V_490 )
V_23 = ( ( unsigned long ) F_209 ( V_485 ) +
F_209 ( V_485 ) -> V_473 * 4 ) -
( unsigned long ) V_485 -> V_85 ;
else
V_23 = sizeof( struct V_505 ) ;
if ( F_230 ( V_485 , V_23 ) )
goto V_492;
V_4 = F_231 ( V_28 , V_487 , V_485 , V_157 ,
V_483 ) ;
} else
V_4 = F_232 ( V_28 , V_487 , V_485 , V_157 ,
V_483 , V_491 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_282 . V_506 ++ ;
V_28 -> V_282 . V_489 += V_489 ;
if ( V_485 != V_268 )
F_150 ( V_268 ) ;
if ( V_28 -> V_43 . V_327 ) {
if ( V_490 ) {
V_28 -> V_328 . V_507 += V_489 ;
V_28 -> V_328 . V_508 ++ ;
}
if ( V_481 ) {
V_28 -> V_328 . V_509 ++ ;
V_28 -> V_328 . V_510 += V_481 + 1 ;
}
}
V_4 = V_511 ;
} else {
if ( V_491 >= 0 )
F_229 ( V_498 , V_157 ) ;
if ( V_4 == - V_512 ) {
if ( V_485 != V_268 )
F_150 ( V_485 ) ;
return V_513 ;
} else
goto V_492;
}
F_233 ( V_125 ) ;
if ( V_28 -> V_43 . V_327 )
V_28 -> V_328 . V_514 += F_154 () -
V_28 -> V_328 . V_496 ;
return V_4 ;
V_492:
V_28 -> V_282 . V_515 ++ ;
V_28 -> V_282 . V_516 ++ ;
if ( ( V_485 != V_268 ) && V_485 )
F_150 ( V_485 ) ;
F_150 ( V_268 ) ;
F_233 ( V_125 ) ;
return V_511 ;
}
static int F_234 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_182 ) ;
if ( V_28 -> V_71 == V_72 )
return V_4 ;
if ( V_28 -> V_71 != V_73 )
return - V_420 ;
V_28 -> V_85 . V_71 = V_346 ;
V_28 -> V_71 = V_72 ;
F_235 ( V_125 ) ;
if ( F_236 ( V_28 -> V_85 . V_333 , 0 ) >= 0 ) {
F_237 ( & V_28 -> V_318 ) ;
F_161 ( & V_28 -> V_318 ) ;
} else
V_4 = - V_197 ;
return V_4 ;
}
static int F_238 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
F_17 ( V_28 , 5 , L_183 ) ;
if ( F_135 ( V_28 , V_266 ) ) {
F_17 ( V_28 , 3 , L_184 ) ;
return - V_517 ;
}
return F_234 ( V_125 ) ;
}
static int F_170 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
F_17 ( V_28 , 4 , L_185 ) ;
F_239 ( V_125 ) ;
if ( V_28 -> V_71 == V_72 ) {
V_28 -> V_71 = V_73 ;
F_240 ( & V_28 -> V_318 ) ;
}
return 0 ;
}
static V_448 F_241 ( struct V_230 * V_125 , V_448 V_199 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
if ( ! F_54 ( V_28 , V_171 ) )
V_199 &= ~ V_518 ;
if ( ! F_54 ( V_28 , V_202 ) )
V_199 &= ~ V_203 ;
if ( ! F_54 ( V_28 , V_166 ) )
V_199 &= ~ V_200 ;
return V_199 ;
}
static int F_242 ( struct V_230 * V_125 , V_448 V_199 )
{
struct V_27 * V_28 = V_125 -> V_264 ;
V_448 V_519 = V_125 -> V_199 ^ V_199 ;
int V_520 ;
if ( ! ( V_519 & V_200 ) )
return 0 ;
if ( V_28 -> V_71 == V_349 ||
V_28 -> V_71 == V_521 )
return 0 ;
V_520 = F_93 ( V_28 , V_199 & V_200 ) ;
if ( V_520 )
V_125 -> V_199 = V_199 ^ V_200 ;
return V_520 ;
}
static int F_243 ( struct V_441 * V_522 )
{
V_522 -> V_523 = V_524 ;
memcpy ( V_522 -> V_525 , L_135 , 6 ) ;
V_522 -> V_526 = V_522 -> V_527 -> V_528 ;
return 0 ;
}
static int
F_244 ( struct V_230 * V_125 , struct V_529 * V_530 )
{
if ( V_530 -> V_531 -> V_532 == V_533 )
V_530 -> V_534 = F_243 ;
return 0 ;
}
static int F_245 ( struct V_27 * V_28 )
{
if ( V_28 -> V_99 . type == V_433 ||
V_28 -> V_99 . type == V_434 ) {
if ( ( V_28 -> V_99 . V_152 == V_154 ) ||
( V_28 -> V_99 . V_152 == V_153 ) ) {
#ifdef F_141
V_28 -> V_125 = F_246 ( 0 ) ;
#endif
if ( ! V_28 -> V_125 )
return - V_420 ;
V_28 -> V_125 -> V_535 = & V_536 ;
} else {
V_28 -> V_125 = F_247 ( 0 ) ;
if ( ! V_28 -> V_125 )
return - V_420 ;
V_28 -> V_125 -> V_535 = & V_537 ;
F_106 ( V_28 ) ;
if ( ! ( V_28 -> V_99 . V_206 & V_210 ) )
V_28 -> V_125 -> V_538 = V_28 -> V_99 . V_206 &
0xffff ;
if ( ! V_28 -> V_99 . V_351 ) {
V_28 -> V_125 -> V_539 = V_540 |
V_200 | V_518 |
V_203 ;
V_28 -> V_125 -> V_199 = V_200 ;
}
}
} else if ( V_28 -> V_99 . type == V_100 ) {
V_28 -> V_125 = F_248 ( 0 , L_186 , V_541 ) ;
if ( ! V_28 -> V_125 )
return - V_420 ;
V_28 -> V_125 -> V_58 |= V_542 ;
V_28 -> V_125 -> V_535 = & V_536 ;
F_104 ( V_28 ) ;
} else
return - V_420 ;
V_28 -> V_125 -> V_264 = V_28 ;
V_28 -> V_125 -> V_543 = V_544 ;
V_28 -> V_125 -> V_545 = V_28 -> V_99 . V_546 ;
F_249 ( V_28 -> V_125 , & V_547 ) ;
V_28 -> V_125 -> V_199 |= V_548 |
V_549 |
V_550 ;
V_28 -> V_125 -> V_551 &= ~ V_552 ;
V_28 -> V_125 -> V_553 = 15 * V_554 ;
F_250 ( V_28 -> V_125 , & V_28 -> V_124 -> V_125 ) ;
F_251 ( V_28 -> V_125 , & V_28 -> V_318 , F_152 , V_555 ) ;
return F_252 ( V_28 -> V_125 ) ;
}
static int F_253 ( struct V_556 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
F_255 ( & V_124 -> V_125 ) ;
V_28 -> V_43 . V_343 = 0 ;
V_28 -> V_99 . V_557 = 0 ;
V_28 -> V_558 . V_559 = V_560 ;
V_28 -> V_558 . V_561 = ( V_562 * )
V_563 ;
V_28 -> V_558 . V_564 = ( V_562 * )
V_565 ;
V_28 -> V_558 . V_77 = V_566 ;
return 0 ;
}
static void F_256 ( struct V_556 * V_567 )
{
struct V_27 * V_28 = F_254 ( & V_567 -> V_125 ) ;
F_257 ( & V_567 -> V_125 ) ;
F_169 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_568 , F_179 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_567 -> V_71 == V_569 )
F_259 ( V_567 ) ;
if ( V_28 -> V_125 ) {
F_260 ( V_28 -> V_125 ) ;
V_28 -> V_125 = NULL ;
}
F_38 ( V_28 , 0 ) ;
F_55 ( V_28 ) ;
return;
}
static int F_261 ( struct V_556 * V_124 , int V_344 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
enum V_570 V_571 ;
F_145 ( ! V_28 ) ;
F_262 ( & V_28 -> V_572 ) ;
F_262 ( & V_28 -> V_573 ) ;
F_71 ( V_150 , 2 , L_187 ) ;
F_151 ( V_150 , 2 , & V_28 , sizeof( void * ) ) ;
V_571 = V_28 -> V_71 ;
V_4 = F_263 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_150 , 2 , L_188 , V_4 ) ;
V_4 = - V_420 ;
goto V_574;
}
if ( ! V_28 -> V_125 && F_245 ( V_28 ) ) {
V_4 = - V_420 ;
goto V_574;
}
if ( F_265 ( V_28 , V_575 ) ) {
if ( V_28 -> V_99 . V_557 &&
F_266 ( V_28 , V_576 ) )
V_28 -> V_99 . V_557 = 0 ;
} else
V_28 -> V_99 . V_557 = 0 ;
V_28 -> V_71 = V_348 ;
memset ( & V_28 -> V_311 , 0 , sizeof( struct V_577 ) ) ;
F_267 ( V_28 ) ;
F_71 ( V_150 , 2 , L_189 ) ;
V_4 = F_268 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_150 , 2 , L_190 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_191 ) ;
V_28 -> V_493 = 0 ;
goto V_578;
}
V_4 = - V_420 ;
goto V_574;
} else
V_28 -> V_493 = 1 ;
V_578:
V_4 = F_70 ( V_28 ) ;
if ( V_4 )
F_264 ( V_150 , 2 , L_188 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_100 ( V_28 ) ;
if ( V_4 )
F_264 ( V_150 , 2 , L_192 , V_4 ) ;
V_4 = F_49 ( V_28 ) ;
if ( V_4 )
F_264 ( V_150 , 2 , L_193 , V_4 ) ;
V_4 = F_52 ( V_28 ) ;
if ( V_4 )
F_264 ( V_150 , 2 , L_194 , V_4 ) ;
}
F_239 ( V_28 -> V_125 ) ;
V_4 = F_269 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_150 , 2 , L_195 , V_4 ) ;
V_4 = - V_420 ;
goto V_574;
}
V_28 -> V_71 = V_73 ;
F_169 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_493 )
F_270 ( V_28 -> V_125 ) ;
else
F_271 ( V_28 -> V_125 ) ;
if ( V_571 == V_521 ) {
if ( V_344 )
F_234 ( V_28 -> V_125 ) ;
else {
F_95 () ;
F_272 ( V_28 -> V_125 ) ;
F_97 () ;
}
F_137 ( V_28 -> V_125 ) ;
}
F_273 ( & V_124 -> V_125 . V_579 , V_580 ) ;
F_274 ( & V_28 -> V_573 ) ;
F_274 ( & V_28 -> V_572 ) ;
return 0 ;
V_574:
F_168 ( V_28 , 0 ) ;
F_275 ( F_276 ( V_28 ) ) ;
F_275 ( F_277 ( V_28 ) ) ;
F_275 ( F_278 ( V_28 ) ) ;
if ( V_571 == V_521 )
V_28 -> V_71 = V_521 ;
else
V_28 -> V_71 = V_349 ;
F_274 ( & V_28 -> V_573 ) ;
F_274 ( & V_28 -> V_572 ) ;
return V_4 ;
}
static int F_279 ( struct V_556 * V_124 )
{
return F_261 ( V_124 , 0 ) ;
}
static int F_280 ( struct V_556 * V_567 ,
int V_344 )
{
struct V_27 * V_28 = F_254 ( & V_567 -> V_125 ) ;
int V_4 = 0 , V_581 = 0 , V_582 = 0 ;
enum V_570 V_571 ;
F_262 ( & V_28 -> V_572 ) ;
F_262 ( & V_28 -> V_573 ) ;
F_71 ( V_150 , 3 , L_196 ) ;
F_151 ( V_150 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_125 && F_281 ( V_28 -> V_125 ) )
F_271 ( V_28 -> V_125 ) ;
V_571 = V_28 -> V_71 ;
if ( ( ! V_344 && V_28 -> V_99 . V_557 ) || V_28 -> V_99 . V_557 == 2 ) {
F_266 ( V_28 , V_583 ) ;
V_28 -> V_99 . V_557 = 1 ;
}
F_168 ( V_28 , V_344 ) ;
V_4 = F_275 ( F_276 ( V_28 ) ) ;
V_581 = F_275 ( F_277 ( V_28 ) ) ;
V_582 = F_275 ( F_278 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_581 ) ? V_581 : V_582 ;
if ( V_4 )
F_264 ( V_150 , 2 , L_190 , V_4 ) ;
if ( V_571 == V_72 )
V_28 -> V_71 = V_521 ;
F_273 ( & V_567 -> V_125 . V_579 , V_580 ) ;
F_274 ( & V_28 -> V_573 ) ;
F_274 ( & V_28 -> V_572 ) ;
return 0 ;
}
static int F_259 ( struct V_556 * V_567 )
{
return F_280 ( V_567 , 0 ) ;
}
static int V_566 ( void * V_584 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_584 ;
F_17 ( V_28 , 2 , L_197 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_282 ( V_28 , V_266 ) )
return 0 ;
F_17 ( V_28 , 2 , L_198 ) ;
F_62 ( & V_28 -> V_124 -> V_125 ,
L_199 ) ;
F_280 ( V_28 -> V_124 , 1 ) ;
V_4 = F_261 ( V_28 -> V_124 , 1 ) ;
if ( ! V_4 )
F_72 ( & V_28 -> V_124 -> V_125 ,
L_200 ) ;
else {
F_95 () ;
F_171 ( V_28 -> V_125 ) ;
F_97 () ;
F_62 ( & V_28 -> V_124 -> V_125 , L_201
L_202 ) ;
}
F_283 ( V_28 , V_266 ) ;
F_284 ( V_28 , V_266 ) ;
return 0 ;
}
static void F_285 ( struct V_556 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
if ( ( V_124 -> V_71 == V_569 ) && V_28 -> V_99 . V_557 )
F_266 ( V_28 , V_583 ) ;
F_173 ( V_28 , 0 ) ;
F_174 ( V_28 ) ;
}
static int F_286 ( struct V_556 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
if ( V_28 -> V_125 )
F_287 ( V_28 -> V_125 ) ;
F_169 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_568 , F_179 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_124 -> V_71 == V_585 )
return 0 ;
if ( V_28 -> V_71 == V_72 ) {
if ( V_28 -> V_99 . V_557 )
F_266 ( V_28 , V_583 ) ;
F_280 ( V_28 -> V_124 , 1 ) ;
} else
F_280 ( V_28 -> V_124 , 0 ) ;
return 0 ;
}
static int F_288 ( struct V_556 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
if ( V_124 -> V_71 == V_585 )
goto V_14;
if ( V_28 -> V_71 == V_521 ) {
V_4 = F_261 ( V_28 -> V_124 , 1 ) ;
if ( V_4 ) {
F_95 () ;
F_171 ( V_28 -> V_125 ) ;
F_97 () ;
}
} else
V_4 = F_261 ( V_28 -> V_124 , 0 ) ;
V_14:
F_169 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_125 )
F_289 ( V_28 -> V_125 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_124 -> V_125 , L_201
L_202 ) ;
return V_4 ;
}
static int F_290 ( struct V_586 * V_587 ,
unsigned long V_588 , void * V_584 )
{
struct V_255 * V_256 = (struct V_255 * ) V_584 ;
struct V_230 * V_125 = (struct V_230 * ) V_256 -> V_589 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_291 ( V_125 ) != & V_590 )
return V_591 ;
V_28 = F_167 ( V_125 ) ;
F_17 ( V_28 , 3 , L_203 ) ;
if ( ! V_28 )
return V_591 ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_256 -> V_259 ;
V_2 -> V_36 . V_47 . V_48 = V_256 -> V_260 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_588 ) {
case V_592 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_593 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_591 ;
}
static int F_292 ( struct V_586 * V_587 ,
unsigned long V_588 , void * V_584 )
{
struct V_261 * V_256 = (struct V_261 * ) V_584 ;
struct V_230 * V_125 = (struct V_230 * ) V_256 -> V_594 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_167 ( V_125 ) ;
if ( ! V_28 )
return V_591 ;
F_17 ( V_28 , 3 , L_204 ) ;
if ( ! F_54 ( V_28 , V_110 ) )
return V_591 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_256 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_256 -> V_262 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_588 ) {
case V_592 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_593 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_591 ;
}
static int F_293 ( void )
{
int V_4 ;
F_71 ( V_150 , 5 , L_205 ) ;
V_4 = F_294 ( & V_595 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_53
V_4 = F_295 ( & V_596 ) ;
if ( V_4 ) {
F_296 ( & V_595 ) ;
return V_4 ;
}
#else
F_297 ( L_206 ) ;
#endif
return 0 ;
}
static void F_298 ( void )
{
F_71 ( V_150 , 5 , L_207 ) ;
F_145 ( F_296 ( & V_595 ) ) ;
#ifdef F_53
F_145 ( F_299 ( & V_596 ) ) ;
#endif
}
static int T_7 F_300 ( void )
{
int V_4 = 0 ;
F_301 ( L_208 ) ;
V_4 = F_293 () ;
return V_4 ;
}
static void T_8 F_302 ( void )
{
F_298 () ;
F_301 ( L_209 ) ;
}
