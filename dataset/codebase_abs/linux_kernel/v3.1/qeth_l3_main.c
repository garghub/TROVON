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
T_5 V_241 ;
F_17 ( V_28 , 4 , L_125 ) ;
if ( ! F_54 ( V_28 , V_184 ) )
return;
F_115 (vid, card->active_vlans, VLAN_N_VID) {
struct V_230 * V_242 ;
F_116 () ;
V_242 = F_117 ( V_28 -> V_125 , V_241 ) ;
F_118 () ;
if ( V_242 == NULL ||
! ( V_242 -> V_58 & V_243 ) )
continue;
V_240 = F_119 ( V_242 ) ;
if ( ! V_240 )
continue;
F_116 () ;
F_112 ( V_28 , V_240 ) ;
F_118 () ;
F_120 ( V_240 ) ;
}
}
static void F_121 ( struct V_27 * V_28 )
{
struct V_232 * V_233 ;
F_17 ( V_28 , 4 , L_126 ) ;
V_233 = F_119 ( V_28 -> V_125 ) ;
if ( V_233 == NULL )
return;
F_116 () ;
F_112 ( V_28 , V_233 ) ;
F_114 ( V_28 ) ;
F_118 () ;
F_120 ( V_233 ) ;
}
static void F_122 ( struct V_27 * V_28 , struct V_244 * V_245 )
{
struct V_29 * V_229 ;
struct V_246 * V_247 ;
char V_1 [ V_236 ] ;
F_17 ( V_28 , 4 , L_127 ) ;
for ( V_247 = V_245 -> V_237 ; V_247 != NULL ; V_247 = V_247 -> V_74 ) {
F_123 ( & V_247 -> V_248 , V_1 , V_245 -> V_125 , 0 ) ;
V_229 = F_24 ( V_21 ) ;
if ( ! V_229 )
continue;
V_229 -> V_46 = 1 ;
memcpy ( V_229 -> V_88 , V_1 , V_89 ) ;
memcpy ( & V_229 -> V_36 . V_49 . V_2 , & V_247 -> V_248 . V_249 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_229 ) )
F_15 ( V_229 ) ;
}
}
static void F_124 ( struct V_27 * V_28 )
{
struct V_244 * V_240 ;
T_5 V_241 ;
F_17 ( V_28 , 4 , L_128 ) ;
if ( ! F_54 ( V_28 , V_184 ) )
return;
F_115 (vid, card->active_vlans, VLAN_N_VID) {
struct V_230 * V_242 ;
V_242 = F_117 ( V_28 -> V_125 , V_241 ) ;
if ( V_242 == NULL ||
! ( V_242 -> V_58 & V_243 ) )
continue;
V_240 = F_125 ( V_242 ) ;
if ( ! V_240 )
continue;
F_126 ( & V_240 -> V_250 ) ;
F_122 ( V_28 , V_240 ) ;
F_127 ( & V_240 -> V_250 ) ;
F_128 ( V_240 ) ;
}
}
static void F_129 ( struct V_27 * V_28 )
{
struct V_244 * V_245 ;
F_17 ( V_28 , 4 , L_129 ) ;
if ( ! F_54 ( V_28 , V_110 ) )
return ;
V_245 = F_125 ( V_28 -> V_125 ) ;
if ( V_245 == NULL )
return;
F_126 ( & V_245 -> V_250 ) ;
F_122 ( V_28 , V_245 ) ;
F_124 ( V_28 ) ;
F_127 ( & V_245 -> V_250 ) ;
F_128 ( V_245 ) ;
}
static void F_130 ( struct V_27 * V_28 ,
unsigned short V_241 )
{
struct V_232 * V_240 ;
struct V_251 * V_252 ;
struct V_29 * V_2 ;
struct V_230 * V_242 ;
F_17 ( V_28 , 4 , L_130 ) ;
V_242 = F_117 ( V_28 -> V_125 , V_241 ) ;
V_240 = F_119 ( V_242 ) ;
if ( ! V_240 )
return;
for ( V_252 = V_240 -> V_253 ; V_252 ; V_252 = V_252 -> V_254 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_252 -> V_255 ;
V_2 -> V_36 . V_47 . V_48 = V_252 -> V_256 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_120 ( V_240 ) ;
}
static void F_131 ( struct V_27 * V_28 ,
unsigned short V_241 )
{
#ifdef F_53
struct V_244 * V_245 ;
struct V_257 * V_252 ;
struct V_29 * V_2 ;
struct V_230 * V_242 ;
F_17 ( V_28 , 4 , L_131 ) ;
V_242 = F_117 ( V_28 -> V_125 , V_241 ) ;
V_245 = F_125 ( V_242 ) ;
if ( ! V_245 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_252 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_252 -> V_258 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_128 ( V_245 ) ;
#endif
}
static void F_132 ( struct V_27 * V_28 ,
unsigned short V_241 )
{
F_130 ( V_28 , V_241 ) ;
F_131 ( V_28 , V_241 ) ;
}
static void F_133 ( struct V_230 * V_125 , unsigned short V_241 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
F_134 ( V_241 , V_28 -> V_260 ) ;
return;
}
static void F_135 ( struct V_230 * V_125 , unsigned short V_241 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
unsigned long V_58 ;
F_45 ( V_28 , 4 , L_132 , V_241 ) ;
if ( F_136 ( V_28 , V_261 ) ) {
F_17 ( V_28 , 3 , L_133 ) ;
return;
}
F_21 ( & V_28 -> V_262 , V_58 ) ;
F_132 ( V_28 , V_241 ) ;
F_137 ( V_241 , V_28 -> V_260 ) ;
F_22 ( & V_28 -> V_262 , V_58 ) ;
F_138 ( V_28 -> V_125 ) ;
}
static inline int F_139 ( struct V_27 * V_28 ,
struct V_263 * V_264 , struct V_265 * V_157 ,
unsigned short * V_266 )
{
T_6 V_60 ;
struct V_267 * V_268 ;
unsigned char V_269 [ V_236 ] ;
int V_270 = 0 ;
if ( ! ( V_157 -> V_157 . V_271 . V_58 & V_135 ) ) {
V_60 = F_140 ( ( V_157 -> V_157 . V_271 . V_58 & V_136 ) ? V_272 :
V_273 ) ;
switch ( V_157 -> V_157 . V_271 . V_58 & V_274 ) {
case V_130 :
switch ( V_60 ) {
#ifdef F_53
case F_141 ( V_272 ) :
F_123 ( (struct V_51 * )
V_264 -> V_85 + 24 ,
V_269 , V_28 -> V_125 , 0 ) ;
break;
#endif
case F_141 ( V_273 ) :
V_268 = (struct V_267 * ) V_264 -> V_85 ;
( V_28 -> V_125 -> type == V_231 ) ?
F_110 ( V_268 -> V_275 , V_269 ) :
F_111 ( V_268 -> V_275 , V_269 ) ;
break;
default:
memcpy ( V_269 , V_28 -> V_125 -> V_276 ,
V_28 -> V_125 -> V_277 ) ;
}
V_28 -> V_278 . V_279 ++ ;
V_264 -> V_280 = V_281 ;
break;
case V_132 :
memcpy ( V_269 , V_28 -> V_125 -> V_276 ,
V_28 -> V_125 -> V_277 ) ;
V_28 -> V_278 . V_279 ++ ;
V_264 -> V_280 = V_282 ;
break;
case V_133 :
case V_138 :
case V_283 :
default:
if ( V_28 -> V_43 . V_44 )
V_264 -> V_280 = V_284 ;
else
V_264 -> V_280 = V_285 ;
memcpy ( V_269 , V_28 -> V_125 -> V_204 ,
V_28 -> V_125 -> V_277 ) ;
}
if ( V_157 -> V_157 . V_271 . V_286 & V_287 )
V_28 -> V_125 -> V_288 -> V_289 ( V_264 , V_28 -> V_125 , V_60 ,
V_269 , & V_157 -> V_157 . V_271 . V_290 [ 2 ] ,
V_28 -> V_125 -> V_277 ) ;
else
V_28 -> V_125 -> V_288 -> V_289 ( V_264 , V_28 -> V_125 , V_60 ,
V_269 , L_134 , V_28 -> V_125 -> V_277 ) ;
}
#ifdef F_142
if ( V_28 -> V_125 -> type == V_231 )
V_264 -> V_291 = F_143 ( V_264 , V_28 -> V_125 ) ;
else
#endif
V_264 -> V_291 = F_144 ( V_264 , V_28 -> V_125 ) ;
if ( V_157 -> V_157 . V_271 . V_286 &
( V_292 | V_293 ) ) {
* V_266 = ( V_157 -> V_157 . V_271 . V_286 & V_292 ) ?
V_157 -> V_157 . V_271 . V_266 : * ( ( T_5 * ) & V_157 -> V_157 . V_271 . V_290 [ 12 ] ) ;
V_270 = 1 ;
}
if ( V_28 -> V_125 -> V_199 & V_200 ) {
if ( ( V_157 -> V_157 . V_271 . V_286 &
( V_294 |
V_295 ) ) ==
( V_294 |
V_295 ) )
V_264 -> V_296 = V_297 ;
else
V_264 -> V_296 = V_298 ;
} else
V_264 -> V_296 = V_298 ;
return V_270 ;
}
static int F_145 ( struct V_27 * V_28 ,
int V_299 , int * V_300 )
{
int V_301 = 0 ;
struct V_263 * V_264 ;
struct V_265 * V_157 ;
T_2 V_302 = 0 ;
int V_270 ;
unsigned int V_23 ;
* V_300 = 0 ;
F_146 ( ! V_299 ) ;
while ( V_299 ) {
V_264 = F_147 ( V_28 ,
V_28 -> V_303 . V_304 -> V_305 [ V_28 -> V_306 . V_307 ] . V_308 ,
& V_28 -> V_306 . V_309 , & V_28 -> V_306 . V_310 , & V_157 ) ;
if ( ! V_264 ) {
* V_300 = 1 ;
break;
}
V_264 -> V_125 = V_28 -> V_125 ;
switch ( V_157 -> V_157 . V_271 . V_311 ) {
case V_312 :
V_270 = F_139 ( V_28 , V_264 , V_157 ,
& V_302 ) ;
V_23 = V_264 -> V_23 ;
if ( V_270 && ! V_28 -> V_43 . V_44 )
F_148 ( V_264 , V_302 ) ;
F_149 ( & V_28 -> V_313 , V_264 ) ;
break;
case V_314 :
V_264 -> V_280 = V_285 ;
V_264 -> V_291 = F_144 ( V_264 , V_264 -> V_125 ) ;
V_23 = V_264 -> V_23 ;
F_150 ( V_264 ) ;
break;
default:
F_151 ( V_264 ) ;
F_17 ( V_28 , 3 , L_135 ) ;
F_152 ( V_315 , 3 , V_157 , V_316 ) ;
continue;
}
V_301 ++ ;
V_299 -- ;
V_28 -> V_278 . V_317 ++ ;
V_28 -> V_278 . V_318 += V_23 ;
}
return V_301 ;
}
static int F_153 ( struct V_319 * V_313 , int V_299 )
{
struct V_27 * V_28 = F_154 ( V_313 , struct V_27 , V_313 ) ;
int V_301 = 0 ;
struct V_320 * V_308 ;
int V_300 ;
int V_321 = V_299 ;
if ( V_28 -> V_43 . V_322 ) {
V_28 -> V_323 . V_324 ++ ;
V_28 -> V_323 . V_325 = F_155 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_306 . V_326 ) {
V_28 -> V_306 . V_327 = 0 ;
V_28 -> V_306 . V_326 = F_156 (
V_28 -> V_85 . V_328 , 0 , & V_28 -> V_306 . V_307 ,
& V_28 -> V_306 . V_327 ) ;
if ( V_28 -> V_306 . V_326 <= 0 ) {
V_28 -> V_306 . V_326 = 0 ;
break;
}
V_28 -> V_306 . V_309 =
& V_28 -> V_303 . V_304 -> V_305 [ V_28 -> V_306 . V_307 ]
. V_308 -> V_329 [ 0 ] ;
V_28 -> V_306 . V_310 = 0 ;
}
while ( V_28 -> V_306 . V_326 ) {
V_308 = & V_28 -> V_303 . V_304 -> V_305 [ V_28 -> V_306 . V_307 ] ;
if ( ! ( V_28 -> V_306 . V_327 &&
F_157 ( V_28 , V_308 -> V_308 ,
V_28 -> V_306 . V_327 , L_136 ) ) )
V_301 += F_145 (
V_28 , V_321 , & V_300 ) ;
else
V_300 = 1 ;
if ( V_300 ) {
if ( V_28 -> V_43 . V_322 )
V_28 -> V_323 . V_330 ++ ;
F_158 ( V_28 ,
V_308 -> V_331 ) ;
F_159 ( V_28 , V_28 -> V_306 . V_307 ) ;
V_28 -> V_306 . V_326 -- ;
if ( V_28 -> V_306 . V_326 ) {
V_28 -> V_306 . V_307 =
( V_28 -> V_306 . V_307 + 1 ) %
V_332 ;
V_28 -> V_306 . V_309 =
& V_28 -> V_303 . V_304
-> V_305 [ V_28 -> V_306 . V_307 ]
. V_308 -> V_329 [ 0 ] ;
V_28 -> V_306 . V_310 = 0 ;
}
}
if ( V_301 >= V_299 )
goto V_14;
else
V_321 = V_299 - V_301 ;
}
}
F_160 ( V_313 ) ;
if ( F_161 ( V_28 -> V_85 . V_328 , 0 ) )
F_162 ( & V_28 -> V_313 ) ;
V_14:
if ( V_28 -> V_43 . V_322 )
V_28 -> V_323 . V_333 += F_155 () -
V_28 -> V_323 . V_325 ;
return V_301 ;
}
static int F_163 ( struct V_230 * V_125 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_241 ;
F_115 (vid, card->active_vlans, VLAN_N_VID) {
struct V_230 * V_242 ;
F_116 () ;
V_242 = F_117 ( V_125 , V_241 ) ;
F_118 () ;
if ( V_242 == V_125 ) {
V_4 = V_334 ;
break;
}
}
if ( V_4 && ! ( F_164 ( V_125 ) -> V_259 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_165 ( struct V_230 * V_125 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_166 ( & V_335 . V_336 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_125 == V_125 ) {
V_4 = V_337 ;
break;
}
V_4 = F_163 ( V_125 , V_28 ) ;
if ( V_4 )
break;
}
F_167 ( & V_335 . V_336 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_168 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_165 ( V_125 ) ;
if ( V_4 == V_337 )
V_28 = V_125 -> V_259 ;
else if ( V_4 == V_334 )
V_28 = F_164 ( V_125 ) -> V_259 ;
if ( V_28 && V_28 -> V_43 . V_338 )
V_28 = NULL ;
if ( V_28 )
F_45 ( V_28 , 4 , L_137 , V_4 ) ;
return V_28 ;
}
static int F_169 ( struct V_27 * V_28 , int V_339 )
{
int V_4 = 0 ;
F_71 ( V_150 , 2 , L_138 ) ;
F_152 ( V_150 , 2 , & V_28 , sizeof( void * ) ) ;
F_170 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_99 . V_216 == V_219 ) )
F_108 ( V_28 , V_214 ) ;
if ( V_28 -> V_340 . V_71 == V_341 &&
V_28 -> V_342 . V_71 == V_341 &&
( V_28 -> V_71 == V_72 ) ) {
if ( V_339 )
F_171 ( V_28 -> V_125 ) ;
else {
F_95 () ;
F_172 ( V_28 -> V_125 ) ;
F_97 () ;
}
V_28 -> V_71 = V_73 ;
}
if ( V_28 -> V_71 == V_73 ) {
F_38 ( V_28 , 1 ) ;
F_173 ( V_28 ) ;
V_28 -> V_71 = V_343 ;
}
if ( V_28 -> V_71 == V_343 ) {
F_174 ( V_28 , 0 ) ;
F_175 ( V_28 ) ;
F_176 ( V_28 ) ;
V_28 -> V_71 = V_344 ;
}
if ( V_28 -> V_71 == V_344 ) {
F_177 ( & V_28 -> V_340 ) ;
F_177 ( & V_28 -> V_342 ) ;
}
return V_4 ;
}
static void
F_178 ( struct V_27 * V_28 )
{
struct V_230 * V_125 = V_28 -> V_125 ;
if ( ( ( V_125 -> V_58 & V_345 ) &&
( V_28 -> V_99 . V_216 == V_219 ) ) ||
( ! ( V_125 -> V_58 & V_345 ) &&
( V_28 -> V_99 . V_216 == V_217 ) ) )
return;
if ( V_28 -> V_99 . V_346 ) {
if ( F_68 ( V_28 , V_347 ) )
F_179 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_68 ( V_28 , V_348 ) ) {
if ( V_125 -> V_58 & V_345 ) {
F_17 ( V_28 , 3 , L_139 ) ;
F_108 ( V_28 , V_218 ) ;
} else {
F_17 ( V_28 , 3 , L_140 ) ;
F_108 ( V_28 , V_214 ) ;
}
}
}
static void F_138 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
F_17 ( V_28 , 3 , L_141 ) ;
if ( F_180 ( V_28 , V_261 ) &&
( V_28 -> V_71 != V_72 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_121 ( V_28 ) ;
#ifdef F_53
F_129 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_68 ( V_28 , V_347 ) )
return;
}
F_178 ( V_28 ) ;
}
static const char * F_181 ( int * V_4 )
{
switch ( * V_4 ) {
case V_349 :
* V_4 = - V_197 ;
return L_142 ;
case V_350 :
* V_4 = - V_182 ;
return L_143 ;
case V_351 :
* V_4 = - V_7 ;
return L_144 ;
case V_352 :
* V_4 = - V_182 ;
return L_145 ;
case V_353 :
* V_4 = - V_354 ;
return L_146 ;
default:
return L_147 ;
}
}
static int F_182 ( struct V_27 * V_28 , int V_355 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_148 ) ;
if ( V_28 -> V_99 . V_346 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_180 ,
V_356 ,
V_355 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_149
L_150 , F_51 ( V_28 ) ,
F_181 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static T_4 F_183 ( struct V_27 * V_28 ,
struct V_357 * V_358 ,
struct V_359 * type , T_1 V_360 )
{
T_4 V_4 ;
T_1 V_361 ;
V_361 = V_358 -> V_362 == 5 ;
if ( type -> V_363 == V_364 ) {
F_17 ( V_28 , 4 , L_151 ) ;
if ( V_360 ) {
V_4 = V_361 ? sizeof( struct V_365 ) :
sizeof( struct V_366 ) ;
} else {
V_4 = V_361 ? sizeof( struct V_367 ) :
sizeof( struct V_368 ) ;
}
} else if ( type -> V_363 == V_369 ) {
F_17 ( V_28 , 4 , L_152 ) ;
if ( V_360 ) {
V_4 = V_361 ?
sizeof( struct V_370 ) :
sizeof( struct V_371 ) ;
} else {
V_4 = V_361 ?
sizeof( struct V_372 ) :
sizeof( struct V_373 ) ;
}
} else {
F_17 ( V_28 , 4 , L_153 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_184 ( struct V_359 * type , T_2 V_60 )
{
return ( type -> V_363 == V_364 && V_60 == V_20 ) ||
( type -> V_363 == V_369 && V_60 == V_21 ) ;
}
static int F_185 ( struct V_27 * V_28 ,
struct V_155 * V_156 , unsigned long V_85 )
{
struct V_83 * V_84 ;
struct V_357 * V_358 ;
struct V_374 * V_375 ;
int V_24 ;
int V_376 ;
int V_377 ;
int V_378 ;
T_1 V_379 ;
F_17 ( V_28 , 3 , L_154 ) ;
V_375 = (struct V_374 * ) V_156 -> V_380 ;
V_84 = (struct V_83 * ) V_85 ;
F_45 ( V_28 , 4 , L_155 , V_84 -> V_157 . V_160 ) ;
if ( V_84 -> V_157 . V_158 ) {
F_17 ( V_28 , 4 , L_156 ) ;
F_45 ( V_28 , 4 , L_155 , V_84 -> V_157 . V_158 ) ;
return 0 ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_158 ) {
V_84 -> V_157 . V_158 = V_84 -> V_85 . V_159 . V_157 . V_158 ;
F_17 ( V_28 , 4 , L_157 ) ;
F_45 ( V_28 , 4 , L_155 , V_84 -> V_157 . V_158 ) ;
return 0 ;
}
V_358 = & V_84 -> V_85 . V_159 . V_85 . V_381 ;
F_45 ( V_28 , 4 , L_158 , V_358 -> V_355 ) ;
V_379 = ( V_375 -> V_37 & V_382 ) > 0 ;
V_378 = V_379 ? V_383 : 0 ;
V_377 = 0 ;
for ( V_376 = 0 ; V_376 < V_358 -> V_355 ; ++ V_376 ) {
char * V_384 ;
T_4 V_385 ;
struct V_359 * V_386 ;
V_384 = & V_358 -> V_85 + V_377 ;
V_386 = & ( (struct V_367 * ) V_384 ) -> type ;
if ( ! F_184 ( V_386 , V_84 -> V_157 . V_160 ) ) {
F_17 ( V_28 , 4 , L_159 ) ;
F_45 ( V_28 , 4 , L_155 , V_386 -> V_363 ) ;
break;
}
V_385 = F_183 ( V_28 , V_358 , V_386 ,
V_379 ) ;
F_45 ( V_28 , 5 , L_160 , V_385 ) ;
if ( ! V_385 )
break;
if ( ( V_375 -> V_387 - V_375 -> V_388 ) < V_385 ) {
F_45 ( V_28 , 4 , L_161 , - V_120 ) ;
V_84 -> V_157 . V_158 = - V_120 ;
goto V_389;
}
memcpy ( V_375 -> V_390 + V_375 -> V_388 ,
& V_358 -> V_85 + V_377 + V_378 ,
V_385 ) ;
V_377 += V_385 + V_378 ;
V_375 -> V_388 += V_385 ;
++ V_375 -> V_355 ;
}
if ( V_84 -> V_85 . V_159 . V_157 . V_178 <
V_84 -> V_85 . V_159 . V_157 . V_391 )
return 1 ;
F_45 ( V_28 , 4 , L_162 , V_375 -> V_355 ) ;
memcpy ( V_375 -> V_390 , & V_375 -> V_355 , 4 ) ;
if ( V_375 -> V_37 & V_382 )
V_358 -> V_362 |= V_382 ;
memcpy ( V_375 -> V_390 + V_392 , & V_358 -> V_362 , 2 ) ;
F_45 ( V_28 , 4 , L_163 , 0 ) ;
return 0 ;
V_389:
V_24 = 0 ;
memcpy ( V_375 -> V_390 , & V_24 , 4 ) ;
return 0 ;
}
static int F_186 ( struct V_27 * V_28 ,
struct V_81 * V_82 , int V_23 ,
int (* F_79)( struct V_27 * , struct V_155 * ,
unsigned long ) ,
void * V_179 )
{
F_17 ( V_28 , 4 , L_164 ) ;
memcpy ( V_82 -> V_85 , V_393 , V_86 ) ;
memcpy ( F_187 ( V_82 -> V_85 ) ,
& V_28 -> V_394 . V_395 , V_396 ) ;
return F_188 ( V_28 , V_86 + V_23 , V_82 ,
F_79 , V_179 ) ;
}
static int F_189 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_374 * V_375 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_41 ;
int V_4 ;
F_45 ( V_28 , 3 , L_165 , V_60 ) ;
V_82 = F_77 ( V_28 , V_180 ,
V_397 ,
sizeof( struct V_357 ) - sizeof( char ) ,
V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_159 . V_85 . V_381 . V_398 = 0x000F ;
V_84 -> V_85 . V_159 . V_85 . V_381 . V_362 = 0 ;
V_84 -> V_85 . V_159 . V_85 . V_381 . V_355 = 0 ;
V_4 = F_186 ( V_28 , V_82 ,
V_399 + V_400 ,
F_185 , ( void * ) V_375 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 ,
L_166
L_167 , F_51 ( V_28 ) ,
F_181 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_190 ( struct V_27 * V_28 , char T_7 * V_390 )
{
struct V_374 V_375 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_168 ) ;
if ( ! F_54 ( V_28 ,
V_180 ) ) {
F_17 ( V_28 , 3 , L_169 ) ;
V_4 = - V_182 ;
goto V_14;
}
if ( F_191 ( & V_375 , V_390 , 6 ) ) {
V_4 = - V_401 ;
goto V_14;
}
V_375 . V_390 = F_25 ( V_375 . V_387 , V_402 ) ;
if ( ! V_375 . V_390 ) {
V_4 = - V_120 ;
goto V_14;
}
V_375 . V_388 = V_403 ;
V_4 = F_189 ( V_28 , V_20 , & V_375 ) ;
if ( V_4 ) {
if ( F_192 ( V_390 , V_375 . V_390 , 4 ) )
V_4 = - V_401 ;
goto V_404;
} else {
#ifdef F_53
if ( V_375 . V_37 & V_405 ) {
F_189 ( V_28 , V_21 ,
& V_375 ) ;
}
#endif
if ( F_192 ( V_390 , V_375 . V_390 , V_375 . V_387 ) ) {
F_17 ( V_28 , 4 , L_170 ) ;
V_4 = - V_401 ;
goto V_404;
}
F_45 ( V_28 , 4 , L_171 ) ;
}
V_404:
F_15 ( V_375 . V_390 ) ;
V_14:
return V_4 ;
}
static int F_193 ( struct V_27 * V_28 ,
struct V_406 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_172 ) ;
if ( V_28 -> V_99 . V_346 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_82 = F_77 ( V_28 , V_180 ,
V_407 ,
sizeof( struct V_406 ) ,
V_20 ) ;
V_4 = F_78 ( V_28 , V_82 ,
sizeof( struct V_406 ) ,
( unsigned long ) V_53 ,
F_76 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_50 ( 2 , L_173
L_174 , V_1 , F_51 ( V_28 ) ,
F_181 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_194 ( struct V_27 * V_28 ,
struct V_406 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_175 ) ;
if ( V_28 -> V_99 . V_346 )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_82 = F_77 ( V_28 , V_180 ,
V_408 ,
12 ,
V_20 ) ;
V_4 = F_78 ( V_28 , V_82 ,
12 , ( unsigned long ) V_1 ,
F_76 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_50 ( 2 , L_176
L_177 , V_1 , F_51 ( V_28 ) ,
F_181 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_195 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_178 ) ;
if ( V_28 -> V_99 . V_346 || ( V_28 -> V_99 . type == V_100 ) )
return - V_182 ;
if ( ! F_54 ( V_28 , V_180 ) ) {
return - V_182 ;
}
V_4 = F_81 ( V_28 , V_180 ,
V_409 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_179
L_167 , F_51 ( V_28 ) ,
F_181 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_196 ( struct V_230 * V_125 , struct V_410 * V_411 , int V_84 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
struct V_406 V_412 ;
struct V_413 * V_414 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_415 ;
if ( ( V_28 -> V_71 != V_72 ) &&
( V_28 -> V_71 != V_73 ) )
return - V_415 ;
switch ( V_84 ) {
case V_416 :
if ( ! F_197 ( V_417 ) ) {
V_4 = - V_418 ;
break;
}
V_4 = F_182 ( V_28 , V_411 -> V_419 . V_420 ) ;
break;
case V_421 :
if ( ! F_197 ( V_417 ) ) {
V_4 = - V_418 ;
break;
}
V_4 = F_190 ( V_28 , V_411 -> V_419 . V_422 ) ;
break;
case V_423 :
if ( ! F_197 ( V_417 ) ) {
V_4 = - V_418 ;
break;
}
if ( F_191 ( & V_412 , V_411 -> V_419 . V_422 ,
sizeof( struct V_406 ) ) )
V_4 = - V_401 ;
else
V_4 = F_193 ( V_28 , & V_412 ) ;
break;
case V_424 :
if ( ! F_197 ( V_417 ) ) {
V_4 = - V_418 ;
break;
}
if ( F_191 ( & V_412 , V_411 -> V_419 . V_422 ,
sizeof( struct V_406 ) ) )
V_4 = - V_401 ;
else
V_4 = F_194 ( V_28 , & V_412 ) ;
break;
case V_425 :
if ( ! F_197 ( V_417 ) ) {
V_4 = - V_418 ;
break;
}
V_4 = F_195 ( V_28 ) ;
break;
case V_426 :
V_4 = F_198 ( V_28 , V_411 -> V_419 . V_422 ) ;
break;
case V_427 :
if ( ( V_28 -> V_99 . type == V_428 ||
V_28 -> V_99 . type == V_429 ) &&
! V_28 -> V_99 . V_346 )
return 1 ;
return 0 ;
break;
case V_430 :
V_414 = F_199 ( V_411 ) ;
V_414 -> V_431 = 0 ;
break;
case V_432 :
V_414 = F_199 ( V_411 ) ;
if ( V_414 -> V_431 != 0 )
V_4 = - V_7 ;
else
V_414 -> V_433 = F_200 ( V_125 ,
V_414 -> V_431 ,
V_414 -> V_434 ) ;
break;
default:
V_4 = - V_182 ;
}
if ( V_4 )
F_45 ( V_28 , 2 , L_180 , V_4 ) ;
return V_4 ;
}
int inline F_201 ( struct V_27 * V_28 , struct V_263 * V_264 )
{
int V_128 = V_435 ;
struct V_436 * V_437 = NULL ;
struct V_438 * V_439 ;
V_439 = F_202 ( V_264 ) ;
if ( V_439 )
V_437 = F_203 ( V_439 ) ;
if ( V_437 ) {
V_128 = V_437 -> type ;
if ( ( V_128 == V_131 ) ||
( V_128 == V_129 ) ||
( V_128 == V_137 ) )
return V_128 ;
else
return V_435 ;
}
if ( V_264 -> V_291 == V_272 )
return ( F_204 ( V_264 ) [ 24 ] == 0xff ) ?
V_129 : 0 ;
else if ( V_264 -> V_291 == V_273 )
return ( ( F_204 ( V_264 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_129 : 0 ;
if ( ! memcmp ( V_264 -> V_85 , V_264 -> V_125 -> V_276 , 6 ) )
return V_131 ;
else {
T_5 V_440 ;
V_440 = * ( ( T_5 * ) V_264 -> V_85 ) ;
switch ( V_28 -> V_99 . V_152 ) {
case V_153 :
case V_154 :
if ( ( V_440 == V_441 ) ||
( V_440 == V_442 ) )
return V_129 ;
break;
default:
if ( ( V_440 == V_443 ) ||
( V_440 == V_444 ) )
return V_129 ;
}
}
return V_128 ;
}
static void F_205 ( struct V_27 * V_28 , struct V_265 * V_157 ,
struct V_263 * V_264 , int V_445 , int V_128 )
{
struct V_436 * V_437 = NULL ;
struct V_438 * V_439 ;
memset ( V_157 , 0 , sizeof( struct V_265 ) ) ;
V_157 -> V_157 . V_271 . V_311 = V_312 ;
V_157 -> V_157 . V_271 . V_286 = 0 ;
if ( F_206 ( V_264 ) ) {
if ( ( V_445 == 4 ) || ( V_28 -> V_99 . type == V_100 ) )
V_157 -> V_157 . V_271 . V_286 = V_292 ;
else
V_157 -> V_157 . V_271 . V_286 = V_293 ;
V_157 -> V_157 . V_271 . V_266 = F_207 ( V_264 ) ;
}
V_157 -> V_157 . V_271 . V_177 = V_264 -> V_23 - sizeof( struct V_265 ) ;
V_439 = F_202 ( V_264 ) ;
if ( V_439 )
V_437 = F_203 ( V_439 ) ;
if ( V_445 == 4 ) {
V_157 -> V_157 . V_271 . V_58 = F_63 ( V_128 ) ;
memset ( V_157 -> V_157 . V_271 . V_290 , 0 , 12 ) ;
if ( V_437 ) {
* ( ( V_446 * ) ( & V_157 -> V_157 . V_271 . V_290 [ 12 ] ) ) =
* ( ( V_446 * ) V_437 -> V_447 ) ;
} else {
* ( ( V_446 * ) ( & V_157 -> V_157 . V_271 . V_290 [ 12 ] ) ) =
V_268 ( V_264 ) -> V_275 ;
}
} else if ( V_445 == 6 ) {
V_157 -> V_157 . V_271 . V_58 = F_64 ( V_128 ) ;
if ( V_28 -> V_99 . type == V_100 )
V_157 -> V_157 . V_271 . V_58 &= ~ V_135 ;
if ( V_437 ) {
memcpy ( V_157 -> V_157 . V_271 . V_290 ,
V_437 -> V_447 , 16 ) ;
} else {
memcpy ( V_157 -> V_157 . V_271 . V_290 ,
& F_208 ( V_264 ) -> V_275 , 16 ) ;
}
} else {
if ( ( V_264 -> V_125 -> type == V_231 ) &&
! memcmp ( V_264 -> V_85 + sizeof( struct V_265 ) +
sizeof( T_2 ) , V_264 -> V_125 -> V_276 , 6 ) ) {
V_157 -> V_157 . V_271 . V_58 = V_132 |
V_135 ;
} else if ( ! memcmp ( V_264 -> V_85 + sizeof( struct V_265 ) ,
V_264 -> V_125 -> V_276 , 6 ) ) {
V_157 -> V_157 . V_271 . V_58 = V_132 |
V_135 ;
} else {
V_157 -> V_157 . V_271 . V_58 = ( V_128 == V_129 ) ?
V_130 | V_135 :
V_133 | V_135 ;
}
}
}
static inline void F_209 ( struct V_27 * V_28 ,
struct V_265 * V_157 , struct V_263 * V_264 )
{
struct V_267 * V_448 = V_268 ( V_264 ) ;
if ( V_448 -> V_291 == V_449 )
V_157 -> V_157 . V_271 . V_286 |= V_450 ;
V_157 -> V_157 . V_271 . V_286 |= V_295 |
V_294 ;
V_448 -> V_451 = 0 ;
if ( V_28 -> V_43 . V_322 )
V_28 -> V_323 . V_452 ++ ;
}
static void F_210 ( struct V_27 * V_28 ,
struct V_265 * V_453 , struct V_263 * V_264 )
{
struct V_454 * V_157 = (struct V_454 * ) V_453 ;
struct V_455 * V_456 = F_211 ( V_264 ) ;
struct V_267 * V_448 = V_268 ( V_264 ) ;
struct V_457 * V_458 = F_208 ( V_264 ) ;
V_157 -> V_157 . V_157 . V_271 . V_311 = V_459 ;
V_157 -> V_157 . V_157 . V_271 . V_177 = V_264 -> V_23 - sizeof( struct V_454 ) ;
V_157 -> V_460 . V_461 = ( T_2 ) sizeof( struct V_462 ) ;
V_157 -> V_460 . V_463 = 1 ;
V_157 -> V_460 . V_464 = 1 ;
V_157 -> V_460 . V_465 = 1 ;
V_157 -> V_460 . V_466 = 28 ;
V_157 -> V_460 . V_467 = F_212 ( V_264 ) -> V_468 ;
V_157 -> V_460 . V_469 = ( T_2 ) ( V_448 -> V_470 * 4 + V_456 -> V_471 * 4 ) ;
V_157 -> V_460 . V_472 = ( T_2 ) ( V_264 -> V_23 - V_157 -> V_460 . V_469 -
sizeof( struct V_454 ) ) ;
V_456 -> V_451 = 0 ;
if ( V_264 -> V_291 == V_272 ) {
V_458 -> V_472 = 0 ;
V_456 -> V_451 = ~ F_213 ( & V_458 -> V_473 , & V_458 -> V_275 ,
0 , V_474 , 0 ) ;
} else {
V_456 -> V_451 = ~ F_214 ( V_448 -> V_473 , V_448 -> V_275 ,
0 , V_474 , 0 ) ;
V_448 -> V_475 = 0 ;
V_448 -> V_451 = 0 ;
}
}
static inline int F_215 ( struct V_263 * V_264 )
{
unsigned long V_476 = ( unsigned long ) F_211 ( V_264 ) +
F_211 ( V_264 ) -> V_471 * 4 ;
int V_477 = V_264 -> V_23 - ( V_476 - ( unsigned long ) V_264 -> V_85 ) ;
int V_478 = F_216 ( V_476 + V_477 - 1 ) - F_217 ( V_476 ) ;
V_478 += F_212 ( V_264 ) -> V_479 ;
return V_478 ;
}
static int F_218 ( struct V_263 * V_264 , struct V_230 * V_125 )
{
int V_4 ;
T_5 * V_480 ;
struct V_265 * V_157 = NULL ;
int V_481 = 0 ;
int V_482 ;
struct V_27 * V_28 = V_125 -> V_259 ;
struct V_263 * V_483 = NULL ;
int V_445 = F_219 ( V_264 ) ;
int V_128 = F_201 ( V_28 , V_264 ) ;
struct V_484 * V_485 = V_28 -> V_303 . V_486
[ F_220 ( V_28 , V_264 , V_445 , V_128 ) ] ;
int V_487 = V_264 -> V_23 ;
bool V_488 ;
int V_489 = - 1 ;
int V_479 ;
if ( ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_445 ) ) ||
V_28 -> V_43 . V_44 )
goto V_490;
if ( ( V_28 -> V_71 != V_72 ) || ! V_28 -> V_491 ) {
V_28 -> V_278 . V_492 ++ ;
goto V_490;
}
if ( ( V_128 == V_131 ) &&
( V_28 -> V_99 . V_189 == 0 ) )
goto V_490;
if ( V_28 -> V_43 . V_322 ) {
V_28 -> V_323 . V_493 ++ ;
V_28 -> V_323 . V_494 = F_155 () ;
}
V_488 = F_221 ( V_264 ) ;
if ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_488 ) &&
( F_212 ( V_264 ) -> V_479 == 0 ) ) {
V_483 = V_264 ;
V_489 = V_495 ;
V_157 = F_222 ( V_496 , V_61 ) ;
if ( ! V_157 )
goto V_490;
V_481 ++ ;
} else {
V_483 = F_223 ( V_264 , sizeof( struct V_454 )
+ V_497 ) ;
if ( ! V_483 )
goto V_490;
}
if ( V_28 -> V_99 . type == V_100 ) {
if ( V_489 < 0 )
F_224 ( V_483 , V_495 ) ;
} else {
if ( V_445 == 4 ) {
if ( V_28 -> V_125 -> type == V_231 )
F_224 ( V_483 , V_498 ) ;
else
F_224 ( V_483 , V_495 ) ;
}
if ( V_445 != 4 && F_206 ( V_483 ) ) {
F_225 ( V_483 , V_497 ) ;
F_226 ( V_483 , V_483 -> V_85 + 4 , 4 ) ;
F_227 ( V_483 , 4 ,
V_483 -> V_85 + 8 , 4 ) ;
F_227 ( V_483 , 8 ,
V_483 -> V_85 + 12 , 4 ) ;
V_480 = ( T_5 * ) ( V_483 -> V_85 + 12 ) ;
* V_480 = F_141 ( V_499 ) ;
* ( V_480 + 1 ) = F_140 ( F_207 ( V_483 ) ) ;
V_483 -> V_500 = 0 ;
}
}
F_228 ( V_125 ) ;
if ( V_488 ) {
if ( F_215 ( V_483 ) + 1 > 16 ) {
if ( F_229 ( V_483 ) )
goto V_490;
if ( V_28 -> V_43 . V_322 )
V_28 -> V_323 . V_501 ++ ;
}
}
if ( V_488 && ( V_128 == V_435 ) ) {
V_157 = (struct V_265 * ) F_225 ( V_483 ,
sizeof( struct V_454 ) ) ;
memset ( V_157 , 0 , sizeof( struct V_454 ) ) ;
F_205 ( V_28 , V_157 , V_483 , V_445 , V_128 ) ;
F_210 ( V_28 , V_157 , V_483 ) ;
V_481 ++ ;
} else {
if ( V_489 < 0 ) {
V_157 = (struct V_265 * ) F_225 ( V_483 ,
sizeof( struct V_265 ) ) ;
F_205 ( V_28 , V_157 , V_483 , V_445 ,
V_128 ) ;
} else {
F_205 ( V_28 , V_157 , V_483 , V_445 ,
V_128 ) ;
V_157 -> V_157 . V_271 . V_177 = V_483 -> V_23 - V_489 ;
}
if ( V_264 -> V_296 == V_502 )
F_209 ( V_28 , V_157 , V_483 ) ;
}
V_482 = F_230 ( V_28 , ( void * ) V_157 , V_483 ,
V_481 ) ;
if ( ! V_482 ) {
if ( V_489 >= 0 )
F_231 ( V_496 , V_157 ) ;
goto V_490;
}
V_481 += V_482 ;
V_479 = F_212 ( V_483 ) -> V_479 ;
if ( V_28 -> V_99 . type != V_100 ) {
int V_23 ;
if ( V_488 )
V_23 = ( ( unsigned long ) F_211 ( V_483 ) +
F_211 ( V_483 ) -> V_471 * 4 ) -
( unsigned long ) V_483 -> V_85 ;
else
V_23 = sizeof( struct V_503 ) ;
if ( F_232 ( V_483 , V_23 ) )
goto V_490;
V_4 = F_233 ( V_28 , V_485 , V_483 , V_157 ,
V_481 ) ;
} else
V_4 = F_234 ( V_28 , V_485 , V_483 , V_157 ,
V_481 , V_489 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_278 . V_504 ++ ;
V_28 -> V_278 . V_487 += V_487 ;
if ( V_483 != V_264 )
F_151 ( V_264 ) ;
if ( V_28 -> V_43 . V_322 ) {
if ( V_488 ) {
V_28 -> V_323 . V_505 += V_487 ;
V_28 -> V_323 . V_506 ++ ;
}
if ( V_479 ) {
V_28 -> V_323 . V_507 ++ ;
V_28 -> V_323 . V_508 += V_479 + 1 ;
}
}
V_4 = V_509 ;
} else {
if ( V_489 >= 0 )
F_231 ( V_496 , V_157 ) ;
if ( V_4 == - V_510 ) {
if ( V_483 != V_264 )
F_151 ( V_483 ) ;
return V_511 ;
} else
goto V_490;
}
F_235 ( V_125 ) ;
if ( V_28 -> V_43 . V_322 )
V_28 -> V_323 . V_512 += F_155 () -
V_28 -> V_323 . V_494 ;
return V_4 ;
V_490:
V_28 -> V_278 . V_513 ++ ;
V_28 -> V_278 . V_514 ++ ;
if ( ( V_483 != V_264 ) && V_483 )
F_151 ( V_483 ) ;
F_151 ( V_264 ) ;
F_235 ( V_125 ) ;
return V_509 ;
}
static int F_236 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_181 ) ;
if ( V_28 -> V_71 == V_72 )
return V_4 ;
if ( V_28 -> V_71 != V_73 )
return - V_415 ;
V_28 -> V_85 . V_71 = V_341 ;
V_28 -> V_71 = V_72 ;
F_237 ( V_125 ) ;
if ( F_238 ( V_28 -> V_85 . V_328 , 0 ) >= 0 ) {
F_239 ( & V_28 -> V_313 ) ;
F_162 ( & V_28 -> V_313 ) ;
} else
V_4 = - V_197 ;
return V_4 ;
}
static int F_240 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
F_17 ( V_28 , 5 , L_182 ) ;
if ( F_136 ( V_28 , V_261 ) ) {
F_17 ( V_28 , 3 , L_183 ) ;
return - V_515 ;
}
return F_236 ( V_125 ) ;
}
static int F_171 ( struct V_230 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
F_17 ( V_28 , 4 , L_184 ) ;
F_241 ( V_125 ) ;
if ( V_28 -> V_71 == V_72 ) {
V_28 -> V_71 = V_73 ;
F_242 ( & V_28 -> V_313 ) ;
}
return 0 ;
}
static V_446 F_243 ( struct V_230 * V_125 , V_446 V_199 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
if ( ! F_54 ( V_28 , V_171 ) )
V_199 &= ~ V_516 ;
if ( ! F_54 ( V_28 , V_202 ) )
V_199 &= ~ V_203 ;
if ( ! F_54 ( V_28 , V_166 ) )
V_199 &= ~ V_200 ;
return V_199 ;
}
static int F_244 ( struct V_230 * V_125 , V_446 V_199 )
{
struct V_27 * V_28 = V_125 -> V_259 ;
V_446 V_517 = V_125 -> V_199 ^ V_199 ;
int V_518 ;
if ( ! ( V_517 & V_200 ) )
return 0 ;
if ( V_28 -> V_71 == V_344 ||
V_28 -> V_71 == V_519 )
return 0 ;
V_518 = F_93 ( V_28 , V_199 & V_200 ) ;
if ( V_518 )
V_125 -> V_199 = V_199 ^ V_200 ;
return V_518 ;
}
static int F_245 ( struct V_436 * V_437 )
{
V_437 -> V_520 = V_521 ;
memcpy ( V_437 -> V_522 , L_134 , 6 ) ;
V_437 -> V_523 = V_437 -> V_524 -> V_525 ;
return 0 ;
}
static int
F_246 ( struct V_230 * V_125 , struct V_526 * V_527 )
{
if ( V_527 -> V_528 -> V_529 == V_530 )
V_527 -> V_531 = F_245 ;
return 0 ;
}
static int F_247 ( struct V_27 * V_28 )
{
if ( V_28 -> V_99 . type == V_428 ||
V_28 -> V_99 . type == V_429 ) {
if ( ( V_28 -> V_99 . V_152 == V_154 ) ||
( V_28 -> V_99 . V_152 == V_153 ) ) {
#ifdef F_142
V_28 -> V_125 = F_248 ( 0 ) ;
#endif
if ( ! V_28 -> V_125 )
return - V_415 ;
V_28 -> V_125 -> V_532 = & V_533 ;
} else {
V_28 -> V_125 = F_249 ( 0 ) ;
if ( ! V_28 -> V_125 )
return - V_415 ;
V_28 -> V_125 -> V_532 = & V_534 ;
F_106 ( V_28 ) ;
if ( ! ( V_28 -> V_99 . V_206 & V_210 ) )
V_28 -> V_125 -> V_535 = V_28 -> V_99 . V_206 &
0xffff ;
if ( ! V_28 -> V_99 . V_346 ) {
V_28 -> V_125 -> V_536 = V_537 |
V_200 | V_516 |
V_203 ;
V_28 -> V_125 -> V_199 = V_200 ;
}
}
} else if ( V_28 -> V_99 . type == V_100 ) {
V_28 -> V_125 = F_250 ( 0 , L_185 , V_538 ) ;
if ( ! V_28 -> V_125 )
return - V_415 ;
V_28 -> V_125 -> V_58 |= V_539 ;
V_28 -> V_125 -> V_532 = & V_533 ;
F_104 ( V_28 ) ;
} else
return - V_415 ;
V_28 -> V_125 -> V_259 = V_28 ;
V_28 -> V_125 -> V_540 = V_541 ;
V_28 -> V_125 -> V_542 = V_28 -> V_99 . V_543 ;
F_251 ( V_28 -> V_125 , & V_544 ) ;
V_28 -> V_125 -> V_199 |= V_545 |
V_546 |
V_547 ;
V_28 -> V_125 -> V_548 &= ~ V_549 ;
V_28 -> V_125 -> V_550 = 15 * V_551 ;
F_252 ( V_28 -> V_125 , & V_28 -> V_124 -> V_125 ) ;
F_253 ( V_28 -> V_125 , & V_28 -> V_313 , F_153 , V_552 ) ;
return F_254 ( V_28 -> V_125 ) ;
}
static int F_255 ( struct V_553 * V_124 )
{
struct V_27 * V_28 = F_256 ( & V_124 -> V_125 ) ;
F_257 ( & V_124 -> V_125 ) ;
V_28 -> V_43 . V_338 = 0 ;
V_28 -> V_99 . V_554 = 0 ;
V_28 -> V_555 . V_556 = V_557 ;
V_28 -> V_555 . V_558 = ( V_559 * )
V_560 ;
V_28 -> V_555 . V_561 = ( V_559 * )
V_562 ;
V_28 -> V_555 . V_77 = V_563 ;
return 0 ;
}
static void F_258 ( struct V_553 * V_564 )
{
struct V_27 * V_28 = F_256 ( & V_564 -> V_125 ) ;
F_259 ( & V_564 -> V_125 ) ;
F_170 ( V_28 , 0 , 1 ) ;
F_260 ( V_28 -> V_565 , F_180 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_564 -> V_71 == V_566 )
F_261 ( V_564 ) ;
if ( V_28 -> V_125 ) {
F_262 ( V_28 -> V_125 ) ;
V_28 -> V_125 = NULL ;
}
F_38 ( V_28 , 0 ) ;
F_55 ( V_28 ) ;
return;
}
static int F_263 ( struct V_553 * V_124 , int V_339 )
{
struct V_27 * V_28 = F_256 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
enum V_567 V_568 ;
F_146 ( ! V_28 ) ;
F_264 ( & V_28 -> V_569 ) ;
F_264 ( & V_28 -> V_570 ) ;
F_71 ( V_150 , 2 , L_186 ) ;
F_152 ( V_150 , 2 , & V_28 , sizeof( void * ) ) ;
V_568 = V_28 -> V_71 ;
V_4 = F_265 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_150 , 2 , L_187 , V_4 ) ;
V_4 = - V_415 ;
goto V_571;
}
if ( ! V_28 -> V_125 && F_247 ( V_28 ) ) {
V_4 = - V_415 ;
goto V_571;
}
if ( F_267 ( V_28 , V_572 ) ) {
if ( V_28 -> V_99 . V_554 &&
F_268 ( V_28 , V_573 ) )
V_28 -> V_99 . V_554 = 0 ;
} else
V_28 -> V_99 . V_554 = 0 ;
V_28 -> V_71 = V_343 ;
memset ( & V_28 -> V_306 , 0 , sizeof( struct V_574 ) ) ;
F_269 ( V_28 ) ;
F_71 ( V_150 , 2 , L_188 ) ;
V_4 = F_270 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_150 , 2 , L_189 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_62 ( & V_28 -> V_124 -> V_125 ,
L_190 ) ;
V_28 -> V_491 = 0 ;
goto V_575;
}
V_4 = - V_415 ;
goto V_571;
} else
V_28 -> V_491 = 1 ;
V_575:
V_4 = F_70 ( V_28 ) ;
if ( V_4 )
F_266 ( V_150 , 2 , L_187 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_100 ( V_28 ) ;
if ( V_4 )
F_266 ( V_150 , 2 , L_191 , V_4 ) ;
V_4 = F_49 ( V_28 ) ;
if ( V_4 )
F_266 ( V_150 , 2 , L_192 , V_4 ) ;
V_4 = F_52 ( V_28 ) ;
if ( V_4 )
F_266 ( V_150 , 2 , L_193 , V_4 ) ;
}
F_241 ( V_28 -> V_125 ) ;
V_4 = F_271 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_150 , 2 , L_194 , V_4 ) ;
V_4 = - V_415 ;
goto V_571;
}
V_28 -> V_71 = V_73 ;
F_170 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_491 )
F_272 ( V_28 -> V_125 ) ;
else
F_273 ( V_28 -> V_125 ) ;
if ( V_568 == V_519 ) {
if ( V_339 )
F_236 ( V_28 -> V_125 ) ;
else {
F_95 () ;
F_274 ( V_28 -> V_125 ) ;
F_97 () ;
}
F_138 ( V_28 -> V_125 ) ;
}
F_275 ( & V_124 -> V_125 . V_576 , V_577 ) ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return 0 ;
V_571:
F_169 ( V_28 , 0 ) ;
F_277 ( F_278 ( V_28 ) ) ;
F_277 ( F_279 ( V_28 ) ) ;
F_277 ( F_280 ( V_28 ) ) ;
if ( V_568 == V_519 )
V_28 -> V_71 = V_519 ;
else
V_28 -> V_71 = V_344 ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return V_4 ;
}
static int F_281 ( struct V_553 * V_124 )
{
return F_263 ( V_124 , 0 ) ;
}
static int F_282 ( struct V_553 * V_564 ,
int V_339 )
{
struct V_27 * V_28 = F_256 ( & V_564 -> V_125 ) ;
int V_4 = 0 , V_578 = 0 , V_579 = 0 ;
enum V_567 V_568 ;
F_264 ( & V_28 -> V_569 ) ;
F_264 ( & V_28 -> V_570 ) ;
F_71 ( V_150 , 3 , L_195 ) ;
F_152 ( V_150 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_125 && F_283 ( V_28 -> V_125 ) )
F_273 ( V_28 -> V_125 ) ;
V_568 = V_28 -> V_71 ;
if ( ( ! V_339 && V_28 -> V_99 . V_554 ) || V_28 -> V_99 . V_554 == 2 ) {
F_268 ( V_28 , V_580 ) ;
V_28 -> V_99 . V_554 = 1 ;
}
F_169 ( V_28 , V_339 ) ;
V_4 = F_277 ( F_278 ( V_28 ) ) ;
V_578 = F_277 ( F_279 ( V_28 ) ) ;
V_579 = F_277 ( F_280 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_578 ) ? V_578 : V_579 ;
if ( V_4 )
F_266 ( V_150 , 2 , L_189 , V_4 ) ;
if ( V_568 == V_72 )
V_28 -> V_71 = V_519 ;
F_275 ( & V_564 -> V_125 . V_576 , V_577 ) ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return 0 ;
}
static int F_261 ( struct V_553 * V_564 )
{
return F_282 ( V_564 , 0 ) ;
}
static int V_563 ( void * V_581 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_581 ;
F_17 ( V_28 , 2 , L_196 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_284 ( V_28 , V_261 ) )
return 0 ;
F_17 ( V_28 , 2 , L_197 ) ;
F_62 ( & V_28 -> V_124 -> V_125 ,
L_198 ) ;
F_282 ( V_28 -> V_124 , 1 ) ;
V_4 = F_263 ( V_28 -> V_124 , 1 ) ;
if ( ! V_4 )
F_72 ( & V_28 -> V_124 -> V_125 ,
L_199 ) ;
else {
F_95 () ;
F_172 ( V_28 -> V_125 ) ;
F_97 () ;
F_62 ( & V_28 -> V_124 -> V_125 , L_200
L_201 ) ;
}
F_285 ( V_28 , V_261 ) ;
F_286 ( V_28 , V_261 ) ;
return 0 ;
}
static void F_287 ( struct V_553 * V_124 )
{
struct V_27 * V_28 = F_256 ( & V_124 -> V_125 ) ;
if ( ( V_124 -> V_71 == V_566 ) && V_28 -> V_99 . V_554 )
F_268 ( V_28 , V_580 ) ;
F_174 ( V_28 , 0 ) ;
F_175 ( V_28 ) ;
}
static int F_288 ( struct V_553 * V_124 )
{
struct V_27 * V_28 = F_256 ( & V_124 -> V_125 ) ;
if ( V_28 -> V_125 )
F_289 ( V_28 -> V_125 ) ;
F_170 ( V_28 , 0 , 1 ) ;
F_260 ( V_28 -> V_565 , F_180 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_124 -> V_71 == V_582 )
return 0 ;
if ( V_28 -> V_71 == V_72 ) {
if ( V_28 -> V_99 . V_554 )
F_268 ( V_28 , V_580 ) ;
F_282 ( V_28 -> V_124 , 1 ) ;
} else
F_282 ( V_28 -> V_124 , 0 ) ;
return 0 ;
}
static int F_290 ( struct V_553 * V_124 )
{
struct V_27 * V_28 = F_256 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
if ( V_124 -> V_71 == V_582 )
goto V_14;
if ( V_28 -> V_71 == V_519 ) {
V_4 = F_263 ( V_28 -> V_124 , 1 ) ;
if ( V_4 ) {
F_95 () ;
F_172 ( V_28 -> V_125 ) ;
F_97 () ;
}
} else
V_4 = F_263 ( V_28 -> V_124 , 0 ) ;
V_14:
F_170 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_125 )
F_291 ( V_28 -> V_125 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_124 -> V_125 , L_200
L_201 ) ;
return V_4 ;
}
static int F_292 ( struct V_583 * V_584 ,
unsigned long V_585 , void * V_581 )
{
struct V_251 * V_252 = (struct V_251 * ) V_581 ;
struct V_230 * V_125 = (struct V_230 * ) V_252 -> V_586 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_293 ( V_125 ) != & V_587 )
return V_588 ;
V_28 = F_168 ( V_125 ) ;
F_17 ( V_28 , 3 , L_202 ) ;
if ( ! V_28 )
return V_588 ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_252 -> V_255 ;
V_2 -> V_36 . V_47 . V_48 = V_252 -> V_256 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_585 ) {
case V_589 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_590 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_588 ;
}
static int F_294 ( struct V_583 * V_584 ,
unsigned long V_585 , void * V_581 )
{
struct V_257 * V_252 = (struct V_257 * ) V_581 ;
struct V_230 * V_125 = (struct V_230 * ) V_252 -> V_591 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_168 ( V_125 ) ;
if ( ! V_28 )
return V_588 ;
F_17 ( V_28 , 3 , L_203 ) ;
if ( ! F_54 ( V_28 , V_110 ) )
return V_588 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_252 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_252 -> V_258 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_585 ) {
case V_589 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_590 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_588 ;
}
static int F_295 ( void )
{
int V_4 ;
F_71 ( V_150 , 5 , L_204 ) ;
V_4 = F_296 ( & V_592 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_53
V_4 = F_297 ( & V_593 ) ;
if ( V_4 ) {
F_298 ( & V_592 ) ;
return V_4 ;
}
#else
F_299 ( L_205 ) ;
#endif
return 0 ;
}
static void F_300 ( void )
{
F_71 ( V_150 , 5 , L_206 ) ;
F_146 ( F_298 ( & V_592 ) ) ;
#ifdef F_53
F_146 ( F_301 ( & V_593 ) ) ;
#endif
}
static int T_8 F_302 ( void )
{
int V_4 = 0 ;
F_303 ( L_207 ) ;
V_4 = F_295 () ;
return V_4 ;
}
static void T_9 F_304 ( void )
{
F_300 () ;
F_303 ( L_208 ) ;
}
