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
int F_19 ( struct V_27 * V_28 , struct V_29 * V_2 )
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
int F_23 ( struct V_27 * V_28 , struct V_29 * V_2 )
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
struct V_29 * F_24 (
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
void F_32 ( struct V_27 * V_28 )
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
V_28 -> V_54 = F_25 ( sizeof( struct V_65 ) , V_61 ) ;
if ( ! V_28 -> V_54 ) {
F_17 ( V_28 , 0 , L_11 ) ;
V_28 -> V_54 = V_70 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
return;
} else
F_29 ( V_28 -> V_54 ) ;
while ( ! F_33 ( V_70 ) ) {
V_63 = F_34 ( V_70 -> V_74 , struct V_29 , V_53 ) ;
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
V_4 = F_35 ( V_28 , V_63 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( ! V_4 || ( V_4 == V_75 ) )
F_18 ( & V_63 -> V_53 , & V_28 -> V_69 ) ;
else
F_15 ( V_63 ) ;
} else if ( V_4 == - 1 ) {
F_36 ( & V_2 -> V_53 ) ;
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
static void F_37 ( struct V_27 * V_28 , int V_77 )
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
while ( ! F_33 ( & V_28 -> V_69 ) ) {
V_2 = F_34 ( V_28 -> V_69 . V_74 ,
struct V_29 , V_53 ) ;
F_36 ( & V_2 -> V_53 ) ;
if ( ! V_77 || V_2 -> V_46 ) {
F_15 ( V_2 ) ;
continue;
}
F_18 ( & V_2 -> V_53 , V_28 -> V_54 ) ;
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
static int F_38 ( struct V_65 * V_78 ,
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
static int F_39 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_80 )
{
int V_4 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_13 ) ;
V_82 = F_40 ( V_28 , V_80 , V_2 -> V_19 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
memcpy ( & V_84 -> V_85 . V_87 . V_88 , V_2 -> V_88 , V_89 ) ;
if ( V_2 -> V_19 == V_21 )
memcpy ( V_84 -> V_85 . V_87 . V_90 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
else
memcpy ( & V_84 -> V_85 . V_87 . V_91 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
V_4 = F_41 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static void F_42 ( T_3 * V_92 , unsigned int V_23 )
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
static int F_43 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_80 , unsigned int V_58 )
{
int V_4 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_1 V_92 [ 16 ] ;
F_17 ( V_28 , 4 , L_14 ) ;
F_44 ( V_28 , 4 , L_15 , V_58 ) ;
V_82 = F_40 ( V_28 , V_80 , V_2 -> V_19 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
if ( V_2 -> V_19 == V_21 ) {
memcpy ( V_84 -> V_85 . V_93 . V_94 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
F_42 ( V_92 , V_2 -> V_36 . V_49 . V_50 ) ;
memcpy ( V_84 -> V_85 . V_93 . V_48 , V_92 ,
sizeof( struct V_51 ) ) ;
V_84 -> V_85 . V_93 . V_58 = V_58 ;
} else {
memcpy ( V_84 -> V_85 . V_95 . V_94 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
memcpy ( V_84 -> V_85 . V_95 . V_48 , & V_2 -> V_36 . V_47 . V_48 , 4 ) ;
V_84 -> V_85 . V_95 . V_58 = V_58 ;
}
V_4 = F_41 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static int F_45 ( struct V_27 * V_28 ,
enum V_96 type , enum V_18 V_60 )
{
int V_4 ;
struct V_83 * V_84 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_16 ) ;
V_82 = F_40 ( V_28 , V_97 , V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_98 . type = ( type ) ;
V_4 = F_41 ( V_28 , V_82 , NULL , NULL ) ;
return V_4 ;
}
static int F_46 ( struct V_27 * V_28 ,
enum V_96 * type , enum V_18 V_60 )
{
if ( V_28 -> V_99 . type == V_100 ) {
switch ( * type ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
return 0 ;
default:
goto V_105;
}
} else {
switch ( * type ) {
case V_101 :
case V_106 :
case V_107 :
return 0 ;
case V_104 :
if ( F_47 ( V_28 , V_60 ,
V_108 ) )
return 0 ;
default:
goto V_105;
}
}
V_105:
* type = V_101 ;
return - V_7 ;
}
int F_48 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_17 ) ;
V_4 = F_46 ( V_28 , & V_28 -> V_43 . V_109 . type ,
V_20 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_45 ( V_28 , V_28 -> V_43 . V_109 . type ,
V_20 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_109 . type = V_101 ;
F_49 ( 2 , L_18
L_19 , V_4 ,
F_50 ( V_28 ) ) ;
}
return V_4 ;
}
int F_51 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_20 ) ;
#ifdef F_52
if ( ! F_53 ( V_28 , V_110 ) )
return 0 ;
V_4 = F_46 ( V_28 , & V_28 -> V_43 . V_111 . type ,
V_21 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_45 ( V_28 , V_28 -> V_43 . V_111 . type ,
V_21 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_111 . type = V_101 ;
F_49 ( 2 , L_18
L_19 , V_4 ,
F_50 ( V_28 ) ) ;
}
#endif
return V_4 ;
}
static void F_54 ( struct V_27 * V_28 )
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
int F_55 ( struct V_27 * V_28 ,
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
void F_56 ( struct V_27 * V_28 ,
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
int F_57 ( struct V_27 * V_28 , enum V_18 V_19 ,
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
if ( F_38 ( & V_28 -> V_69 , V_115 , 0 ) ||
F_38 ( V_28 -> V_54 , V_115 , 0 ) )
V_4 = - V_113 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
F_15 ( V_115 ) ;
return V_4 ;
}
if ( ! F_23 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
return V_4 ;
}
void F_58 ( struct V_27 * V_28 , enum V_18 V_19 ,
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
int F_59 ( struct V_27 * V_28 , enum V_18 V_19 ,
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
if ( F_38 ( & V_28 -> V_69 , V_115 , 0 ) ||
F_38 ( V_28 -> V_54 , V_115 , 0 ) )
V_4 = - V_113 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
F_15 ( V_115 ) ;
return V_4 ;
}
if ( ! F_23 ( V_28 , V_115 ) )
F_15 ( V_115 ) ;
F_32 ( V_28 ) ;
return 0 ;
}
void F_60 ( struct V_27 * V_28 , enum V_18 V_19 ,
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
static int F_35 ( struct V_27 * V_28 ,
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
V_4 = F_39 ( V_28 , V_2 , V_122 ) ;
else
V_4 = F_43 ( V_28 , V_2 , V_123 ,
V_2 -> V_56 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
} while ( ( -- V_13 > 0 ) && V_4 );
if ( V_4 ) {
F_17 ( V_28 , 2 , L_33 ) ;
F_6 ( V_2 -> V_19 , ( T_3 * ) & V_2 -> V_36 , V_1 ) ;
F_61 ( & V_28 -> V_124 -> V_125 ,
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
V_4 = F_39 ( V_28 , V_2 , V_126 ) ;
else
V_4 = F_43 ( V_28 , V_2 , V_127 ,
V_2 -> V_118 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
return V_4 ;
}
static inline T_3 F_62 ( int V_128 )
{
if ( V_128 == V_129 )
return V_130 ;
if ( V_128 == V_131 )
return V_132 ;
return V_133 ;
}
static inline T_3 F_63 ( int V_128 )
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
static int F_64 ( struct V_27 * V_28 )
{
int V_4 ;
F_65 ( V_139 , 2 , L_38 ) ;
if ( ! F_53 ( V_28 , V_140 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_39 ) ;
F_65 ( V_139 , 2 , L_40 ) ;
return 0 ;
}
V_4 = F_67 ( V_28 ) ;
if ( V_4 ) {
F_49 ( 2 , L_41
L_42 , F_68 ( & V_28 -> V_124 -> V_125 ) , V_4 ) ;
return V_4 ;
}
if ( F_69 ( V_28 , V_141 ) ) {
V_4 = F_70 ( V_28 ) ;
if ( V_4 )
F_61 ( & V_28 -> V_124 -> V_125 , L_43
L_44 ) ;
}
return V_4 ;
}
static int F_71 ( struct V_27 * V_28 ,
struct V_142 * V_143 , unsigned long V_85 )
{
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_45 ) ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_144 . V_145 == 0 ) {
V_84 -> V_144 . V_145 = V_84 -> V_85 . V_146 . V_144 . V_145 ;
if ( V_84 -> V_144 . V_147 == V_20 )
V_28 -> V_43 . V_148 . V_149 = V_84 -> V_144 . V_150 ;
if ( V_84 -> V_144 . V_147 == V_21 )
V_28 -> V_43 . V_151 . V_149 = V_84 -> V_144 . V_150 ;
}
if ( V_84 -> V_85 . V_146 . V_144 . V_152 == V_153 &&
V_84 -> V_85 . V_146 . V_144 . V_154 == V_155 ) {
V_28 -> V_99 . V_156 = V_84 -> V_85 . V_146 . V_85 . V_157 ;
F_44 ( V_28 , 3 , L_46 , V_28 -> V_99 . V_156 ) ;
}
if ( V_84 -> V_85 . V_146 . V_144 . V_152 == V_158 &&
V_84 -> V_85 . V_146 . V_144 . V_154 == V_155 ) {
V_28 -> V_99 . V_159 =
V_84 -> V_85 . V_146 . V_85 . V_157 ;
F_44 ( V_28 , 3 , L_47 , V_28 -> V_99 . V_159 ) ;
}
return 0 ;
}
static struct V_81 * F_72 (
struct V_27 * V_28 , enum V_160 V_161 , T_2 V_162 ,
T_2 V_23 , enum V_18 V_60 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_48 ) ;
V_82 = F_40 ( V_28 , V_163 , V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_146 . V_144 . V_152 = V_161 ;
V_84 -> V_85 . V_146 . V_144 . V_164 = 8 + V_23 ;
V_84 -> V_85 . V_146 . V_144 . V_154 = V_162 ;
V_84 -> V_85 . V_146 . V_144 . V_145 = 0 ;
V_84 -> V_85 . V_146 . V_144 . V_165 = 0 ;
return V_82 ;
}
static int F_73 ( struct V_27 * V_28 ,
struct V_81 * V_82 , T_2 V_23 , long V_85 ,
int (* F_74)( struct V_27 * , struct V_142 * ,
unsigned long ) ,
void * V_166 )
{
int V_4 ;
struct V_83 * V_84 ;
F_17 ( V_28 , 4 , L_49 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
if ( V_23 <= sizeof( V_167 ) )
V_84 -> V_85 . V_146 . V_85 . V_157 = ( V_167 ) V_85 ;
else
memcpy ( & V_84 -> V_85 . V_146 . V_85 , ( void * ) V_85 , V_23 ) ;
V_4 = F_41 ( V_28 , V_82 , F_74 , V_166 ) ;
return V_4 ;
}
static int F_75 ( struct V_27 * V_28 ,
enum V_160 V_161 , T_2 V_162 )
{
int V_4 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_50 ) ;
V_82 = F_72 ( V_28 , V_161 , V_162 ,
0 , V_21 ) ;
V_4 = F_73 ( V_28 , V_82 , 0 , 0 ,
F_71 , NULL ) ;
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 ,
enum V_160 V_161 , T_2 V_162 , long V_85 )
{
int V_4 ;
int V_164 = 0 ;
struct V_81 * V_82 ;
F_17 ( V_28 , 4 , L_51 ) ;
if ( V_85 )
V_164 = sizeof( V_167 ) ;
V_82 = F_72 ( V_28 , V_161 , V_162 ,
V_164 , V_20 ) ;
V_4 = F_73 ( V_28 , V_82 , V_164 , V_85 ,
F_71 , NULL ) ;
return V_4 ;
}
static int F_77 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_52 ) ;
if ( ! F_53 ( V_28 , V_168 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_53 ,
F_50 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_76 ( V_28 , V_168 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_54 ,
F_50 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_78 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_55 ) ;
if ( ! F_53 ( V_28 , V_169 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_56 ,
F_50 ( V_28 ) ) ;
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_169 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_57 ,
F_50 ( V_28 ) ) ;
} else
F_66 ( & V_28 -> V_124 -> V_125 ,
L_58 ) ;
return V_4 ;
}
static int F_79 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_59 ) ;
if ( ! F_53 ( V_28 , V_171 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_60 ,
F_50 ( V_28 ) ) ;
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_171 ,
V_155 , 0 ) ;
if ( V_4 )
F_61 ( & V_28 -> V_124 -> V_125 ,
L_61 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_62 ) ;
if ( ! F_53 ( V_28 , V_172 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_63 , F_50 ( V_28 ) ) ;
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_173 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_64 ,
F_50 ( V_28 ) ) ;
} else {
F_66 ( & V_28 -> V_124 -> V_125 , L_65 ) ;
}
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_66 ) ;
if ( ! F_53 ( V_28 , V_174 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_67 ,
F_50 ( V_28 ) ) ;
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_174 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_68 ,
F_50 ( V_28 ) ) ;
} else {
F_66 ( & V_28 -> V_124 -> V_125 , L_69 ) ;
V_28 -> V_125 -> V_58 |= V_175 ;
}
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_70 ) ;
if ( V_28 -> V_99 . type == V_100 )
goto V_14;
V_4 = F_83 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_124 -> V_125 ,
L_71 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_76 ( V_28 , V_110 ,
V_155 , 3 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_124 -> V_125 ,
L_71 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_75 ( V_28 , V_110 ,
V_155 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_124 -> V_125 ,
L_71 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_75 ( V_28 , V_176 ,
V_155 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_72 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_66 ( & V_28 -> V_124 -> V_125 , L_73 ) ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_74 ) ;
if ( ! F_53 ( V_28 , V_110 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_75 , F_50 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_52
V_4 = F_82 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_86 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_76 ) ;
V_28 -> V_99 . V_177 = 0 ;
if ( ! F_53 ( V_28 , V_178 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_77 ,
F_50 ( V_28 ) ) ;
V_4 = - V_170 ;
goto V_14;
}
V_4 = F_76 ( V_28 , V_178 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 , L_78
L_79 , F_50 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_76 ( V_28 , V_178 ,
V_179 , 1 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_80 ,
F_50 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_99 . V_177 = V_180 ;
F_66 ( & V_28 -> V_124 -> V_125 , L_81 ) ;
V_4 = F_76 ( V_28 , V_178 ,
V_181 , 1 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 , L_82
L_83 , F_50 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_99 . V_177 = V_182 ;
V_14:
if ( V_28 -> V_99 . V_177 )
V_28 -> V_125 -> V_58 |= V_183 ;
else
V_28 -> V_125 -> V_58 &= ~ V_183 ;
return V_4 ;
}
static int F_87 ( struct V_27 * V_28 )
{
int V_4 ;
V_4 = F_76 ( V_28 , V_153 ,
V_155 , 0 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 , L_84
L_85 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_76 ( V_28 , V_153 ,
V_181 ,
V_28 -> V_99 . V_156 ) ;
if ( V_4 ) {
F_61 ( & V_28 -> V_124 -> V_125 , L_86
L_85 ,
F_50 ( V_28 ) ) ;
return V_4 ;
}
return 0 ;
}
static int F_88 ( struct V_27 * V_28 , int V_184 )
{
int V_4 = 0 ;
if ( V_184 ) {
V_4 = F_87 ( V_28 ) ;
if ( V_4 )
return - V_185 ;
F_66 ( & V_28 -> V_124 -> V_125 ,
L_87 ) ;
} else {
V_4 = F_76 ( V_28 ,
V_153 , V_186 , 0 ) ;
if ( V_4 )
return - V_185 ;
}
return 0 ;
}
static int F_89 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_88 ) ;
if ( V_28 -> V_125 -> V_187 & V_188 ) {
F_90 () ;
V_28 -> V_125 -> V_187 &= ~ V_188 ;
F_91 ( V_28 -> V_125 ) ;
F_92 () ;
}
return 0 ;
}
static int F_93 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
if ( ! F_53 ( V_28 , V_158 ) )
return V_4 ;
V_4 = F_76 ( V_28 , V_158 ,
V_155 , 0 ) ;
if ( V_4 )
goto V_189;
V_4 = F_76 ( V_28 , V_158 ,
V_181 , V_28 -> V_99 . V_159 ) ;
if ( V_4 )
goto V_189;
F_66 ( & V_28 -> V_124 -> V_125 , L_89 ) ;
return V_4 ;
V_189:
F_61 ( & V_28 -> V_124 -> V_125 , L_90
L_91 , F_50 ( V_28 ) ) ;
return V_4 ;
}
static int F_94 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_92 ) ;
if ( ! F_53 ( V_28 , V_190 ) ) {
F_66 ( & V_28 -> V_124 -> V_125 ,
L_93 ,
F_50 ( V_28 ) ) ;
V_4 = - V_170 ;
} else {
V_4 = F_76 ( V_28 , V_190 ,
V_155 , 0 ) ;
if ( V_4 )
F_61 ( & V_28 -> V_124 -> V_125 , L_94
L_95 ,
F_50 ( V_28 ) ) ;
else
F_66 ( & V_28 -> V_124 -> V_125 ,
L_96 ) ;
}
if ( V_4 )
V_28 -> V_125 -> V_187 &= ~ V_191 ;
return V_4 ;
}
static int F_95 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_97 ) ;
if ( F_96 ( V_28 , 0 ) )
return - V_185 ;
F_77 ( V_28 ) ;
F_78 ( V_28 ) ;
F_79 ( V_28 ) ;
F_80 ( V_28 ) ;
F_81 ( V_28 ) ;
F_85 ( V_28 ) ;
F_86 ( V_28 ) ;
F_89 ( V_28 ) ;
F_93 ( V_28 ) ;
F_94 ( V_28 ) ;
return 0 ;
}
static int F_97 ( struct V_27 * V_28 ,
struct V_142 * V_143 , unsigned long V_85 )
{
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_144 . V_145 == 0 )
memcpy ( V_28 -> V_125 -> V_192 ,
V_84 -> V_85 . V_193 . V_194 , V_195 ) ;
else
F_98 ( V_28 -> V_125 -> V_192 ) ;
return 0 ;
}
static int F_99 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_65 ( V_139 , 2 , L_98 ) ;
V_82 = F_40 ( V_28 , V_196 ,
V_21 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
* ( ( T_2 * ) & V_84 -> V_85 . V_193 . V_194 [ 6 ] ) =
V_28 -> V_99 . V_194 ;
V_4 = F_41 ( V_28 , V_82 , F_97 ,
NULL ) ;
return V_4 ;
}
static int F_100 ( struct V_27 * V_28 ,
struct V_142 * V_143 , unsigned long V_85 )
{
struct V_83 * V_84 ;
V_84 = (struct V_83 * ) V_85 ;
if ( V_84 -> V_144 . V_145 == 0 )
V_28 -> V_99 . V_194 = * ( ( T_2 * )
& V_84 -> V_85 . V_193 . V_194 [ 6 ] ) ;
else {
V_28 -> V_99 . V_194 = V_197 |
V_198 ;
F_61 ( & V_28 -> V_124 -> V_125 , L_99
L_100 ) ;
}
return 0 ;
}
static int F_101 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_65 ( V_139 , 2 , L_101 ) ;
if ( ! F_53 ( V_28 , V_110 ) ) {
V_28 -> V_99 . V_194 = V_197 |
V_198 ;
return 0 ;
}
V_82 = F_40 ( V_28 , V_196 ,
V_21 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
* ( ( T_2 * ) & V_84 -> V_85 . V_193 . V_194 [ 6 ] ) =
V_28 -> V_99 . V_194 ;
V_4 = F_41 ( V_28 , V_82 , F_100 , NULL ) ;
return V_4 ;
}
static int
F_102 ( struct V_27 * V_28 , struct V_142 * V_143 ,
unsigned long V_85 )
{
struct V_83 * V_84 ;
T_2 V_4 ;
F_65 ( V_139 , 2 , L_102 ) ;
V_84 = (struct V_83 * ) V_85 ;
V_4 = V_84 -> V_144 . V_145 ;
if ( V_4 )
F_44 ( V_28 , 2 , L_103 , V_4 ) ;
switch ( V_84 -> V_85 . V_199 . V_200 ) {
case V_201 :
break;
case V_202 :
switch ( V_4 ) {
case 0 :
case V_203 :
V_28 -> V_99 . V_204 = V_205 ;
F_66 ( & V_28 -> V_124 -> V_125 , L_104
L_105 ) ;
break;
default:
break;
}
break;
case V_206 :
switch ( V_4 ) {
case 0 :
V_28 -> V_99 . V_204 = V_207 ;
F_66 ( & V_28 -> V_124 -> V_125 , L_104
L_106 ) ;
break;
case V_208 :
F_61 ( & V_28 -> V_124 -> V_125 , L_107
L_108
L_109 ) ;
break;
case V_209 :
F_61 ( & V_28 -> V_124 -> V_125 , L_110
L_111
L_112 ) ;
break;
default:
break;
}
break;
default:
F_49 ( 2 , L_113 ,
V_84 -> V_85 . V_199 . V_200 , F_50 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_103 ( struct V_27 * V_28 , enum V_210 V_211 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
F_65 ( V_139 , 2 , L_114 ) ;
V_82 = F_40 ( V_28 , V_212 , 0 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_199 . V_213 = 16 ;
V_84 -> V_85 . V_199 . V_214 = V_215 ;
V_84 -> V_85 . V_199 . type = V_216 ;
V_84 -> V_85 . V_199 . V_200 = V_211 ;
return F_41 ( V_28 , V_82 , F_102 , NULL ) ;
}
static void F_104 ( V_167 V_217 , char * V_88 ,
struct V_218 * V_125 )
{
F_105 ( V_217 , V_88 ) ;
}
static void F_106 ( struct V_27 * V_28 , struct V_219 * V_220 )
{
struct V_29 * V_217 ;
struct V_221 * V_222 ;
char V_1 [ V_223 ] ;
F_17 ( V_28 , 4 , L_115 ) ;
for ( V_222 = F_107 ( V_220 -> V_224 ) ; V_222 != NULL ;
V_222 = F_107 ( V_222 -> V_225 ) ) {
F_104 ( V_222 -> V_226 , V_1 , V_220 -> V_125 ) ;
V_217 = F_24 ( V_20 ) ;
if ( ! V_217 )
continue;
V_217 -> V_36 . V_47 . V_2 = V_222 -> V_226 ;
memcpy ( V_217 -> V_88 , V_1 , V_89 ) ;
V_217 -> V_46 = 1 ;
if ( ! F_23 ( V_28 , V_217 ) )
F_15 ( V_217 ) ;
}
}
static void F_108 ( struct V_27 * V_28 )
{
struct V_219 * V_227 ;
T_4 V_228 ;
F_17 ( V_28 , 4 , L_116 ) ;
if ( ! F_53 ( V_28 , V_172 ) )
return;
F_109 (vid, card->active_vlans, VLAN_N_VID) {
struct V_218 * V_229 ;
V_229 = F_110 ( V_28 -> V_125 , F_111 ( V_230 ) ,
V_228 ) ;
if ( V_229 == NULL ||
! ( V_229 -> V_58 & V_231 ) )
continue;
V_227 = F_112 ( V_229 ) ;
if ( ! V_227 )
continue;
F_106 ( V_28 , V_227 ) ;
}
}
static void F_113 ( struct V_27 * V_28 )
{
struct V_219 * V_220 ;
F_17 ( V_28 , 4 , L_117 ) ;
F_114 () ;
V_220 = F_112 ( V_28 -> V_125 ) ;
if ( V_220 == NULL )
goto V_232;
F_106 ( V_28 , V_220 ) ;
F_108 ( V_28 ) ;
V_232:
F_115 () ;
}
static void F_116 ( struct V_27 * V_28 , struct V_233 * V_234 )
{
struct V_29 * V_217 ;
struct V_235 * V_236 ;
char V_1 [ V_223 ] ;
F_17 ( V_28 , 4 , L_118 ) ;
for ( V_236 = V_234 -> V_224 ; V_236 != NULL ; V_236 = V_236 -> V_74 ) {
F_117 ( & V_236 -> V_237 , V_1 , V_234 -> V_125 , 0 ) ;
V_217 = F_24 ( V_21 ) ;
if ( ! V_217 )
continue;
V_217 -> V_46 = 1 ;
memcpy ( V_217 -> V_88 , V_1 , V_89 ) ;
memcpy ( & V_217 -> V_36 . V_49 . V_2 , & V_236 -> V_237 . V_238 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_217 ) )
F_15 ( V_217 ) ;
}
}
static void F_118 ( struct V_27 * V_28 )
{
struct V_233 * V_227 ;
T_4 V_228 ;
F_17 ( V_28 , 4 , L_119 ) ;
if ( ! F_53 ( V_28 , V_172 ) )
return;
F_109 (vid, card->active_vlans, VLAN_N_VID) {
struct V_218 * V_229 ;
V_229 = F_110 ( V_28 -> V_125 , F_111 ( V_230 ) ,
V_228 ) ;
if ( V_229 == NULL ||
! ( V_229 -> V_58 & V_231 ) )
continue;
V_227 = F_119 ( V_229 ) ;
if ( ! V_227 )
continue;
F_120 ( & V_227 -> V_239 ) ;
F_116 ( V_28 , V_227 ) ;
F_121 ( & V_227 -> V_239 ) ;
F_122 ( V_227 ) ;
}
}
static void F_123 ( struct V_27 * V_28 )
{
struct V_233 * V_234 ;
F_17 ( V_28 , 4 , L_120 ) ;
if ( ! F_53 ( V_28 , V_110 ) )
return ;
V_234 = F_119 ( V_28 -> V_125 ) ;
if ( V_234 == NULL )
return;
F_114 () ;
F_120 ( & V_234 -> V_239 ) ;
F_116 ( V_28 , V_234 ) ;
F_118 ( V_28 ) ;
F_121 ( & V_234 -> V_239 ) ;
F_115 () ;
F_122 ( V_234 ) ;
}
static void F_124 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
struct V_219 * V_227 ;
struct V_240 * V_241 ;
struct V_29 * V_2 ;
struct V_218 * V_229 ;
F_17 ( V_28 , 4 , L_121 ) ;
V_229 = F_110 ( V_28 -> V_125 , F_111 ( V_230 ) , V_228 ) ;
if ( ! V_229 )
return;
V_227 = F_125 ( V_229 ) ;
if ( ! V_227 )
return;
for ( V_241 = V_227 -> V_242 ; V_241 ; V_241 = V_241 -> V_243 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_241 -> V_244 ;
V_2 -> V_36 . V_47 . V_48 = V_241 -> V_245 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_126 ( V_227 ) ;
}
static void F_127 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
#ifdef F_52
struct V_233 * V_234 ;
struct V_246 * V_241 ;
struct V_29 * V_2 ;
struct V_218 * V_229 ;
F_17 ( V_28 , 4 , L_122 ) ;
V_229 = F_110 ( V_28 -> V_125 , F_111 ( V_230 ) , V_228 ) ;
if ( ! V_229 )
return;
V_234 = F_119 ( V_229 ) ;
if ( ! V_234 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_241 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_241 -> V_247 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_122 ( V_234 ) ;
#endif
}
static void F_128 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
F_114 () ;
F_124 ( V_28 , V_228 ) ;
F_127 ( V_28 , V_228 ) ;
F_115 () ;
}
static int F_129 ( struct V_218 * V_125 ,
T_5 V_19 , T_4 V_228 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
F_130 ( V_228 , V_28 -> V_249 ) ;
return 0 ;
}
static int F_131 ( struct V_218 * V_125 ,
T_5 V_19 , T_4 V_228 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
unsigned long V_58 ;
F_44 ( V_28 , 4 , L_123 , V_228 ) ;
if ( F_132 ( V_28 , V_250 ) ) {
F_17 ( V_28 , 3 , L_124 ) ;
return 0 ;
}
F_21 ( & V_28 -> V_251 , V_58 ) ;
F_128 ( V_28 , V_228 ) ;
F_133 ( V_228 , V_28 -> V_249 ) ;
F_22 ( & V_28 -> V_251 , V_58 ) ;
F_134 ( V_28 -> V_125 ) ;
return 0 ;
}
static inline int F_135 ( struct V_27 * V_28 ,
struct V_252 * V_253 , struct V_254 * V_144 ,
unsigned short * V_255 )
{
T_5 V_60 ;
struct V_256 * V_257 ;
unsigned char V_258 [ V_223 ] ;
int V_259 = 0 ;
if ( ! ( V_144 -> V_144 . V_260 . V_58 & V_135 ) ) {
V_60 = F_111 ( ( V_144 -> V_144 . V_260 . V_58 & V_136 ) ? V_261 :
V_262 ) ;
switch ( V_144 -> V_144 . V_260 . V_58 & V_263 ) {
case V_130 :
switch ( V_60 ) {
#ifdef F_52
case F_136 ( V_261 ) :
F_117 ( (struct V_51 * )
V_253 -> V_85 + 24 ,
V_258 , V_28 -> V_125 , 0 ) ;
break;
#endif
case F_136 ( V_262 ) :
V_257 = (struct V_256 * ) V_253 -> V_85 ;
F_105 ( V_257 -> V_264 , V_258 ) ;
break;
default:
memcpy ( V_258 , V_28 -> V_125 -> V_265 ,
V_28 -> V_125 -> V_266 ) ;
}
V_28 -> V_267 . V_268 ++ ;
V_253 -> V_269 = V_270 ;
break;
case V_132 :
memcpy ( V_258 , V_28 -> V_125 -> V_265 ,
V_28 -> V_125 -> V_266 ) ;
V_28 -> V_267 . V_268 ++ ;
V_253 -> V_269 = V_271 ;
break;
case V_133 :
case V_138 :
case V_272 :
default:
if ( V_28 -> V_43 . V_44 )
V_253 -> V_269 = V_273 ;
else
V_253 -> V_269 = V_274 ;
memcpy ( V_258 , V_28 -> V_125 -> V_192 ,
V_28 -> V_125 -> V_266 ) ;
}
if ( V_144 -> V_144 . V_260 . V_275 & V_276 )
V_28 -> V_125 -> V_277 -> V_278 ( V_253 , V_28 -> V_125 , V_60 ,
V_258 , & V_144 -> V_144 . V_260 . V_279 [ 2 ] ,
V_28 -> V_125 -> V_266 ) ;
else
V_28 -> V_125 -> V_277 -> V_278 ( V_253 , V_28 -> V_125 , V_60 ,
V_258 , L_125 , V_28 -> V_125 -> V_266 ) ;
}
V_253 -> V_280 = F_137 ( V_253 , V_28 -> V_125 ) ;
if ( V_144 -> V_144 . V_260 . V_275 &
( V_281 | V_282 ) ) {
* V_255 = ( V_144 -> V_144 . V_260 . V_275 & V_281 ) ?
V_144 -> V_144 . V_260 . V_255 : * ( ( T_4 * ) & V_144 -> V_144 . V_260 . V_279 [ 12 ] ) ;
V_259 = 1 ;
}
if ( V_28 -> V_125 -> V_187 & V_188 ) {
if ( ( V_144 -> V_144 . V_260 . V_275 &
( V_283 |
V_284 ) ) ==
( V_283 |
V_284 ) )
V_253 -> V_285 = V_286 ;
else
V_253 -> V_285 = V_287 ;
} else
V_253 -> V_285 = V_287 ;
return V_259 ;
}
static int F_138 ( struct V_27 * V_28 ,
int V_288 , int * V_289 )
{
int V_290 = 0 ;
struct V_252 * V_253 ;
struct V_254 * V_144 ;
T_2 V_291 = 0 ;
int V_259 ;
unsigned int V_23 ;
T_2 V_292 ;
* V_289 = 0 ;
F_139 ( ! V_288 ) ;
while ( V_288 ) {
V_253 = F_140 ( V_28 ,
& V_28 -> V_293 . V_294 -> V_295 [ V_28 -> V_296 . V_297 ] ,
& V_28 -> V_296 . V_298 , & V_28 -> V_296 . V_299 , & V_144 ) ;
if ( ! V_253 ) {
* V_289 = 1 ;
break;
}
V_253 -> V_125 = V_28 -> V_125 ;
switch ( V_144 -> V_144 . V_260 . V_300 ) {
case V_301 :
V_292 = * ( T_2 * ) V_253 -> V_85 ;
if ( ( V_28 -> V_99 . type == V_100 ) &&
( V_292 == V_302 ) ) {
V_253 -> V_280 = V_302 ;
V_253 -> V_269 = V_274 ;
V_253 -> V_303 = V_304 ;
V_253 -> V_125 = V_28 -> V_125 ;
V_23 = V_253 -> V_23 ;
V_28 -> V_125 -> V_277 -> V_278 ( V_253 , V_28 -> V_125 , 0 ,
V_28 -> V_125 -> V_192 , L_125 ,
V_28 -> V_125 -> V_266 ) ;
F_141 ( V_253 ) ;
} else {
V_259 = F_135 ( V_28 , V_253 , V_144 ,
& V_291 ) ;
V_23 = V_253 -> V_23 ;
if ( V_259 && ! V_28 -> V_43 . V_44 )
F_142 ( V_253 ,
F_111 ( V_230 ) , V_291 ) ;
F_143 ( & V_28 -> V_305 , V_253 ) ;
}
break;
case V_306 :
V_253 -> V_269 = V_274 ;
V_253 -> V_280 = F_137 ( V_253 , V_253 -> V_125 ) ;
V_23 = V_253 -> V_23 ;
F_141 ( V_253 ) ;
break;
default:
F_144 ( V_253 ) ;
F_17 ( V_28 , 3 , L_126 ) ;
F_145 ( V_307 , 3 , V_144 , V_308 ) ;
continue;
}
V_290 ++ ;
V_288 -- ;
V_28 -> V_267 . V_309 ++ ;
V_28 -> V_267 . V_310 += V_23 ;
}
return V_290 ;
}
static int F_146 ( struct V_311 * V_305 , int V_288 )
{
struct V_27 * V_28 = F_147 ( V_305 , struct V_27 , V_305 ) ;
int V_290 = 0 ;
struct V_312 * V_313 ;
int V_289 ;
int V_314 = V_288 ;
if ( V_28 -> V_43 . V_315 ) {
V_28 -> V_316 . V_317 ++ ;
V_28 -> V_316 . V_318 = F_148 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_296 . V_319 ) {
V_28 -> V_296 . V_320 = 0 ;
V_28 -> V_296 . V_319 = F_149 (
V_28 -> V_85 . V_321 , 0 , & V_28 -> V_296 . V_297 ,
& V_28 -> V_296 . V_320 ) ;
if ( V_28 -> V_296 . V_319 <= 0 ) {
V_28 -> V_296 . V_319 = 0 ;
break;
}
V_28 -> V_296 . V_298 =
& V_28 -> V_293 . V_294 -> V_295 [ V_28 -> V_296 . V_297 ]
. V_313 -> V_322 [ 0 ] ;
V_28 -> V_296 . V_299 = 0 ;
}
while ( V_28 -> V_296 . V_319 ) {
V_313 = & V_28 -> V_293 . V_294 -> V_295 [ V_28 -> V_296 . V_297 ] ;
if ( ! ( V_28 -> V_296 . V_320 &&
F_150 ( V_28 , V_313 -> V_313 ,
V_28 -> V_296 . V_320 , L_127 ) ) )
V_290 += F_138 (
V_28 , V_314 , & V_289 ) ;
else
V_289 = 1 ;
if ( V_289 ) {
if ( V_28 -> V_43 . V_315 )
V_28 -> V_316 . V_323 ++ ;
F_151 ( V_28 ,
V_313 -> V_324 ) ;
F_152 ( V_28 , V_28 -> V_296 . V_297 ) ;
V_28 -> V_296 . V_319 -- ;
if ( V_28 -> V_296 . V_319 ) {
V_28 -> V_296 . V_297 =
( V_28 -> V_296 . V_297 + 1 ) %
V_325 ;
V_28 -> V_296 . V_298 =
& V_28 -> V_293 . V_294
-> V_295 [ V_28 -> V_296 . V_297 ]
. V_313 -> V_322 [ 0 ] ;
V_28 -> V_296 . V_299 = 0 ;
}
}
if ( V_290 >= V_288 )
goto V_14;
else
V_314 = V_288 - V_290 ;
}
}
F_153 ( V_305 ) ;
if ( F_154 ( V_28 -> V_85 . V_321 , 0 ) )
F_155 ( & V_28 -> V_305 ) ;
V_14:
if ( V_28 -> V_43 . V_315 )
V_28 -> V_316 . V_326 += F_148 () -
V_28 -> V_316 . V_318 ;
return V_290 ;
}
static int F_156 ( struct V_218 * V_125 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_4 V_228 ;
F_109 (vid, card->active_vlans, VLAN_N_VID) {
struct V_218 * V_229 ;
F_114 () ;
V_229 = F_110 ( V_28 -> V_125 , F_111 ( V_230 ) ,
V_228 ) ;
F_115 () ;
if ( V_229 == V_125 ) {
V_4 = V_327 ;
break;
}
}
if ( V_4 && ! ( F_157 ( V_125 ) -> V_248 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_158 ( struct V_218 * V_125 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_159 ( & V_328 . V_329 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_125 == V_125 ) {
V_4 = V_330 ;
break;
}
V_4 = F_156 ( V_125 , V_28 ) ;
if ( V_4 )
break;
}
F_160 ( & V_328 . V_329 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_161 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_158 ( V_125 ) ;
if ( V_4 == V_330 )
V_28 = V_125 -> V_248 ;
else if ( V_4 == V_327 )
V_28 = F_157 ( V_125 ) -> V_248 ;
if ( V_28 && V_28 -> V_43 . V_331 )
V_28 = NULL ;
if ( V_28 )
F_44 ( V_28 , 4 , L_128 , V_4 ) ;
return V_28 ;
}
static int F_162 ( struct V_27 * V_28 , int V_332 )
{
int V_4 = 0 ;
F_65 ( V_139 , 2 , L_129 ) ;
F_145 ( V_139 , 2 , & V_28 , sizeof( void * ) ) ;
F_163 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_99 . V_204 == V_207 ) )
F_103 ( V_28 , V_202 ) ;
if ( V_28 -> V_333 . V_71 == V_334 &&
V_28 -> V_335 . V_71 == V_334 &&
( V_28 -> V_71 == V_72 ) ) {
if ( V_332 )
F_164 ( V_28 -> V_125 ) ;
else {
F_90 () ;
F_165 ( V_28 -> V_125 ) ;
F_92 () ;
}
V_28 -> V_71 = V_73 ;
}
if ( V_28 -> V_71 == V_73 ) {
F_37 ( V_28 , 1 ) ;
F_166 ( V_28 ) ;
V_28 -> V_71 = V_336 ;
}
if ( V_28 -> V_71 == V_336 ) {
F_167 ( V_28 , 0 ) ;
F_168 ( V_28 ) ;
F_169 ( V_28 ) ;
V_28 -> V_71 = V_337 ;
}
if ( V_28 -> V_71 == V_337 ) {
F_170 ( & V_28 -> V_333 ) ;
F_170 ( & V_28 -> V_335 ) ;
}
return V_4 ;
}
static void
F_171 ( struct V_27 * V_28 )
{
struct V_218 * V_125 = V_28 -> V_125 ;
if ( ( ( V_125 -> V_58 & V_338 ) &&
( V_28 -> V_99 . V_204 == V_207 ) ) ||
( ! ( V_125 -> V_58 & V_338 ) &&
( V_28 -> V_99 . V_204 == V_205 ) ) )
return;
if ( V_28 -> V_99 . V_339 ) {
if ( F_69 ( V_28 , V_340 ) )
F_172 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_69 ( V_28 , V_341 ) ) {
if ( V_125 -> V_58 & V_338 ) {
F_17 ( V_28 , 3 , L_130 ) ;
F_103 ( V_28 , V_206 ) ;
} else {
F_17 ( V_28 , 3 , L_131 ) ;
F_103 ( V_28 , V_202 ) ;
}
}
}
static void F_134 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
F_17 ( V_28 , 3 , L_132 ) ;
if ( F_173 ( V_28 , V_250 ) &&
( V_28 -> V_71 != V_72 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_113 ( V_28 ) ;
#ifdef F_52
F_123 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_69 ( V_28 , V_340 ) )
return;
}
F_171 ( V_28 ) ;
}
static const char * F_174 ( int * V_4 )
{
switch ( * V_4 ) {
case V_342 :
* V_4 = - V_185 ;
return L_133 ;
case V_343 :
* V_4 = - V_170 ;
return L_134 ;
case V_344 :
* V_4 = - V_7 ;
return L_135 ;
case V_345 :
* V_4 = - V_170 ;
return L_136 ;
case V_346 :
* V_4 = - V_347 ;
return L_137 ;
default:
return L_138 ;
}
}
static int F_175 ( struct V_27 * V_28 , int V_348 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_139 ) ;
if ( V_28 -> V_99 . V_339 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_168 ,
V_349 ,
V_348 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 , L_140
L_141 , F_50 ( V_28 ) ,
F_174 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static V_167 F_176 ( struct V_27 * V_28 ,
struct V_350 * V_351 ,
struct V_352 * type , T_1 V_353 )
{
V_167 V_4 ;
T_1 V_354 ;
V_354 = V_351 -> V_355 == 5 ;
if ( type -> V_356 == V_357 ) {
F_17 ( V_28 , 4 , L_142 ) ;
if ( V_353 ) {
V_4 = V_354 ? sizeof( struct V_358 ) :
sizeof( struct V_359 ) ;
} else {
V_4 = V_354 ? sizeof( struct V_360 ) :
sizeof( struct V_361 ) ;
}
} else if ( type -> V_356 == V_362 ) {
F_17 ( V_28 , 4 , L_143 ) ;
if ( V_353 ) {
V_4 = V_354 ?
sizeof( struct V_363 ) :
sizeof( struct V_364 ) ;
} else {
V_4 = V_354 ?
sizeof( struct V_365 ) :
sizeof( struct V_366 ) ;
}
} else {
F_17 ( V_28 , 4 , L_144 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_177 ( struct V_352 * type , T_2 V_60 )
{
return ( type -> V_356 == V_357 && V_60 == V_20 ) ||
( type -> V_356 == V_362 && V_60 == V_21 ) ;
}
static int F_178 ( struct V_27 * V_28 ,
struct V_142 * V_143 , unsigned long V_85 )
{
struct V_83 * V_84 ;
struct V_350 * V_351 ;
struct V_367 * V_368 ;
int V_24 ;
int V_369 ;
int V_370 ;
int V_371 ;
T_1 V_372 ;
F_17 ( V_28 , 3 , L_145 ) ;
V_368 = (struct V_367 * ) V_143 -> V_373 ;
V_84 = (struct V_83 * ) V_85 ;
F_44 ( V_28 , 4 , L_146 , V_84 -> V_144 . V_147 ) ;
if ( V_84 -> V_144 . V_145 ) {
F_17 ( V_28 , 4 , L_147 ) ;
F_44 ( V_28 , 4 , L_146 , V_84 -> V_144 . V_145 ) ;
return 0 ;
}
if ( V_84 -> V_85 . V_146 . V_144 . V_145 ) {
V_84 -> V_144 . V_145 = V_84 -> V_85 . V_146 . V_144 . V_145 ;
F_17 ( V_28 , 4 , L_148 ) ;
F_44 ( V_28 , 4 , L_146 , V_84 -> V_144 . V_145 ) ;
return 0 ;
}
V_351 = & V_84 -> V_85 . V_146 . V_85 . V_374 ;
F_44 ( V_28 , 4 , L_149 , V_351 -> V_348 ) ;
V_372 = ( V_368 -> V_37 & V_375 ) > 0 ;
V_371 = V_372 ? V_376 : 0 ;
V_370 = 0 ;
for ( V_369 = 0 ; V_369 < V_351 -> V_348 ; ++ V_369 ) {
char * V_377 ;
V_167 V_378 ;
struct V_352 * V_379 ;
V_377 = & V_351 -> V_85 + V_370 ;
V_379 = & ( (struct V_360 * ) V_377 ) -> type ;
if ( ! F_177 ( V_379 , V_84 -> V_144 . V_147 ) ) {
F_17 ( V_28 , 4 , L_150 ) ;
F_44 ( V_28 , 4 , L_146 , V_379 -> V_356 ) ;
break;
}
V_378 = F_176 ( V_28 , V_351 , V_379 ,
V_372 ) ;
F_44 ( V_28 , 5 , L_151 , V_378 ) ;
if ( ! V_378 )
break;
if ( ( V_368 -> V_380 - V_368 -> V_381 ) < V_378 ) {
F_44 ( V_28 , 4 , L_152 , - V_120 ) ;
V_84 -> V_144 . V_145 = V_382 ;
goto V_383;
}
memcpy ( V_368 -> V_384 + V_368 -> V_381 ,
& V_351 -> V_85 + V_370 + V_371 ,
V_378 ) ;
V_370 += V_378 + V_371 ;
V_368 -> V_381 += V_378 ;
++ V_368 -> V_348 ;
}
if ( V_84 -> V_85 . V_146 . V_144 . V_165 <
V_84 -> V_85 . V_146 . V_144 . V_385 )
return 1 ;
F_44 ( V_28 , 4 , L_153 , V_368 -> V_348 ) ;
memcpy ( V_368 -> V_384 , & V_368 -> V_348 , 4 ) ;
if ( V_368 -> V_37 & V_375 )
V_351 -> V_355 |= V_375 ;
memcpy ( V_368 -> V_384 + V_386 , & V_351 -> V_355 , 2 ) ;
F_44 ( V_28 , 4 , L_154 , 0 ) ;
return 0 ;
V_383:
V_24 = 0 ;
memcpy ( V_368 -> V_384 , & V_24 , 4 ) ;
return 0 ;
}
static int F_179 ( struct V_27 * V_28 ,
struct V_81 * V_82 , int V_23 ,
int (* F_74)( struct V_27 * , struct V_142 * ,
unsigned long ) ,
void * V_166 )
{
F_17 ( V_28 , 4 , L_155 ) ;
memcpy ( V_82 -> V_85 , V_387 , V_86 ) ;
memcpy ( F_180 ( V_82 -> V_85 ) ,
& V_28 -> V_388 . V_389 , V_390 ) ;
return F_181 ( V_28 , V_86 + V_23 , V_82 ,
F_74 , V_166 ) ;
}
static int F_182 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_367 * V_368 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_41 ;
int V_4 ;
F_44 ( V_28 , 3 , L_156 , V_60 ) ;
V_82 = F_72 ( V_28 , V_168 ,
V_391 ,
sizeof( struct V_350 ) - sizeof( char ) ,
V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_146 . V_85 . V_374 . V_392 = 0x000F ;
V_84 -> V_85 . V_146 . V_85 . V_374 . V_355 = 0 ;
V_84 -> V_85 . V_146 . V_85 . V_374 . V_348 = 0 ;
V_4 = F_179 ( V_28 , V_82 ,
V_393 + V_394 ,
F_178 , ( void * ) V_368 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 ,
L_157
L_158 , F_50 ( V_28 ) ,
F_174 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_183 ( struct V_27 * V_28 , char T_6 * V_384 )
{
struct V_367 V_368 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_159 ) ;
if ( ! F_53 ( V_28 ,
V_168 ) ) {
F_17 ( V_28 , 3 , L_160 ) ;
V_4 = - V_170 ;
goto V_14;
}
if ( F_184 ( & V_368 , V_384 , 6 ) ) {
V_4 = - V_395 ;
goto V_14;
}
V_368 . V_384 = F_25 ( V_368 . V_380 , V_396 ) ;
if ( ! V_368 . V_384 ) {
V_4 = - V_120 ;
goto V_14;
}
V_368 . V_381 = V_397 ;
V_4 = F_182 ( V_28 , V_20 , & V_368 ) ;
if ( V_4 ) {
if ( F_185 ( V_384 , V_368 . V_384 , 4 ) )
V_4 = - V_395 ;
goto V_398;
} else {
#ifdef F_52
if ( V_368 . V_37 & V_399 ) {
F_182 ( V_28 , V_21 ,
& V_368 ) ;
}
#endif
if ( F_185 ( V_384 , V_368 . V_384 , V_368 . V_380 ) ) {
F_17 ( V_28 , 4 , L_161 ) ;
V_4 = - V_395 ;
goto V_398;
}
F_44 ( V_28 , 4 , L_162 ) ;
}
V_398:
F_15 ( V_368 . V_384 ) ;
V_14:
return V_4 ;
}
static int F_186 ( struct V_27 * V_28 ,
struct V_400 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_163 ) ;
if ( V_28 -> V_99 . V_339 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_82 = F_72 ( V_28 , V_168 ,
V_401 ,
sizeof( struct V_400 ) ,
V_20 ) ;
V_4 = F_73 ( V_28 , V_82 ,
sizeof( struct V_400 ) ,
( unsigned long ) V_53 ,
F_71 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_49 ( 2 , L_164
L_165 , V_1 , F_50 ( V_28 ) ,
F_174 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_187 ( struct V_27 * V_28 ,
struct V_400 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_166 ) ;
if ( V_28 -> V_99 . V_339 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_82 = F_72 ( V_28 , V_168 ,
V_402 ,
12 ,
V_20 ) ;
V_4 = F_73 ( V_28 , V_82 ,
12 , ( unsigned long ) V_1 ,
F_71 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_49 ( 2 , L_167
L_168 , V_1 , F_50 ( V_28 ) ,
F_174 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_188 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_169 ) ;
if ( V_28 -> V_99 . V_339 || ( V_28 -> V_99 . type == V_100 ) )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_168 ,
V_403 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 , L_170
L_158 , F_50 ( V_28 ) ,
F_174 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_189 ( struct V_218 * V_125 , struct V_404 * V_405 , int V_84 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
struct V_400 V_406 ;
struct V_407 * V_408 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_409 ;
if ( ( V_28 -> V_71 != V_72 ) &&
( V_28 -> V_71 != V_73 ) )
return - V_409 ;
switch ( V_84 ) {
case V_410 :
if ( ! F_190 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_175 ( V_28 , V_405 -> V_413 . V_414 ) ;
break;
case V_415 :
if ( ! F_190 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_183 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
case V_417 :
if ( ! F_190 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
if ( F_184 ( & V_406 , V_405 -> V_413 . V_416 ,
sizeof( struct V_400 ) ) )
V_4 = - V_395 ;
else
V_4 = F_186 ( V_28 , & V_406 ) ;
break;
case V_418 :
if ( ! F_190 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
if ( F_184 ( & V_406 , V_405 -> V_413 . V_416 ,
sizeof( struct V_400 ) ) )
V_4 = - V_395 ;
else
V_4 = F_187 ( V_28 , & V_406 ) ;
break;
case V_419 :
if ( ! F_190 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_188 ( V_28 ) ;
break;
case V_420 :
V_4 = F_191 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
case V_421 :
if ( ( V_28 -> V_99 . type == V_422 ||
V_28 -> V_99 . type == V_423 ) &&
! V_28 -> V_99 . V_339 )
return 1 ;
return 0 ;
break;
case V_424 :
V_408 = F_192 ( V_405 ) ;
V_408 -> V_425 = 0 ;
break;
case V_426 :
V_408 = F_192 ( V_405 ) ;
if ( V_408 -> V_425 != 0 )
V_4 = - V_7 ;
else
V_408 -> V_427 = F_193 ( V_125 ,
V_408 -> V_425 ,
V_408 -> V_428 ) ;
break;
case V_429 :
V_4 = F_194 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
default:
V_4 = - V_170 ;
}
if ( V_4 )
F_44 ( V_28 , 2 , L_171 , V_4 ) ;
return V_4 ;
}
int inline F_195 ( struct V_27 * V_28 , struct V_252 * V_253 )
{
int V_128 = V_430 ;
struct V_431 * V_432 = NULL ;
struct V_433 * V_434 ;
F_114 () ;
V_434 = F_196 ( V_253 ) ;
if ( V_434 )
V_432 = F_197 ( V_434 , V_253 ) ;
if ( V_432 ) {
V_128 = V_432 -> type ;
F_115 () ;
F_198 ( V_432 ) ;
if ( ( V_128 == V_131 ) ||
( V_128 == V_129 ) ||
( V_128 == V_137 ) )
return V_128 ;
else
return V_430 ;
}
F_115 () ;
if ( V_253 -> V_280 == V_261 )
return ( F_199 ( V_253 ) [ 24 ] == 0xff ) ?
V_129 : 0 ;
else if ( V_253 -> V_280 == V_262 )
return ( ( F_199 ( V_253 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_129 : 0 ;
if ( ! memcmp ( V_253 -> V_85 , V_253 -> V_125 -> V_265 , 6 ) )
return V_131 ;
else {
T_4 V_435 ;
V_435 = * ( ( T_4 * ) V_253 -> V_85 ) ;
switch ( V_28 -> V_99 . V_436 ) {
case V_437 :
case V_438 :
if ( ( V_435 == V_439 ) ||
( V_435 == V_440 ) )
return V_129 ;
break;
default:
if ( ( V_435 == V_441 ) ||
( V_435 == V_442 ) )
return V_129 ;
}
}
return V_128 ;
}
static void F_200 ( struct V_27 * V_28 ,
struct V_254 * V_144 , struct V_252 * V_253 )
{
char V_264 [ 16 ] ;
struct V_443 * V_444 ;
F_201 ( V_253 , 14 ) ;
V_28 -> V_125 -> V_277 -> V_278 ( V_253 , V_28 -> V_125 , 0 ,
V_28 -> V_125 -> V_192 , V_28 -> V_125 -> V_192 ,
V_28 -> V_125 -> V_266 ) ;
F_201 ( V_253 , 14 ) ;
V_444 = (struct V_443 * ) V_253 -> V_85 ;
memset ( V_144 , 0 , sizeof( struct V_254 ) ) ;
V_144 -> V_144 . V_260 . V_300 = V_301 ;
V_144 -> V_144 . V_260 . V_275 = 0 ;
V_144 -> V_144 . V_260 . V_164 = V_253 -> V_23 ;
V_144 -> V_144 . V_260 . V_58 = V_136 | V_133 ;
memset ( V_264 , 0 , sizeof( V_264 ) ) ;
V_264 [ 0 ] = 0xfe ;
V_264 [ 1 ] = 0x80 ;
memcpy ( & V_264 [ 8 ] , V_444 -> V_445 , 8 ) ;
memcpy ( V_144 -> V_144 . V_260 . V_279 , V_264 , 16 ) ;
}
static void F_202 ( struct V_27 * V_28 , struct V_254 * V_144 ,
struct V_252 * V_253 , int V_446 , int V_128 )
{
struct V_433 * V_434 ;
memset ( V_144 , 0 , sizeof( struct V_254 ) ) ;
V_144 -> V_144 . V_260 . V_300 = V_301 ;
V_144 -> V_144 . V_260 . V_275 = 0 ;
if ( F_203 ( V_253 ) ) {
if ( ( V_446 == 4 ) || ( V_28 -> V_99 . type == V_100 ) )
V_144 -> V_144 . V_260 . V_275 = V_281 ;
else
V_144 -> V_144 . V_260 . V_275 = V_282 ;
V_144 -> V_144 . V_260 . V_255 = F_204 ( V_253 ) ;
}
V_144 -> V_144 . V_260 . V_164 = V_253 -> V_23 - sizeof( struct V_254 ) ;
F_114 () ;
V_434 = F_196 ( V_253 ) ;
if ( V_446 == 4 ) {
struct V_447 * V_448 = (struct V_447 * ) V_434 ;
T_7 * V_449 = & V_257 ( V_253 ) -> V_264 ;
if ( V_448 -> V_450 )
V_449 = & V_448 -> V_450 ;
V_144 -> V_144 . V_260 . V_58 = F_62 ( V_128 ) ;
memset ( V_144 -> V_144 . V_260 . V_279 , 0 , 12 ) ;
* ( ( T_7 * ) ( & V_144 -> V_144 . V_260 . V_279 [ 12 ] ) ) = * V_449 ;
} else if ( V_446 == 6 ) {
struct V_451 * V_448 = (struct V_451 * ) V_434 ;
struct V_51 * V_449 = & F_205 ( V_253 ) -> V_264 ;
if ( ! F_206 ( & V_448 -> V_452 ) )
V_449 = & V_448 -> V_452 ;
V_144 -> V_144 . V_260 . V_58 = F_63 ( V_128 ) ;
if ( V_28 -> V_99 . type == V_100 )
V_144 -> V_144 . V_260 . V_58 &= ~ V_135 ;
memcpy ( V_144 -> V_144 . V_260 . V_279 , V_449 , 16 ) ;
} else {
if ( ! memcmp ( V_253 -> V_85 + sizeof( struct V_254 ) ,
V_253 -> V_125 -> V_265 , 6 ) ) {
V_144 -> V_144 . V_260 . V_58 = V_132 |
V_135 ;
} else {
V_144 -> V_144 . V_260 . V_58 = ( V_128 == V_129 ) ?
V_130 | V_135 :
V_133 | V_135 ;
}
}
F_115 () ;
}
static inline void F_207 ( struct V_27 * V_28 ,
struct V_254 * V_144 , struct V_252 * V_253 )
{
struct V_256 * V_453 = V_257 ( V_253 ) ;
if ( V_453 -> V_280 == V_454 )
V_144 -> V_144 . V_260 . V_275 |= V_455 ;
V_144 -> V_144 . V_260 . V_275 |= V_284 |
V_283 ;
V_453 -> V_456 = 0 ;
if ( V_28 -> V_43 . V_315 )
V_28 -> V_316 . V_457 ++ ;
}
static void F_208 ( struct V_27 * V_28 ,
struct V_254 * V_458 , struct V_252 * V_253 )
{
struct V_459 * V_144 = (struct V_459 * ) V_458 ;
struct V_460 * V_461 = F_209 ( V_253 ) ;
struct V_256 * V_453 = V_257 ( V_253 ) ;
struct V_462 * V_463 = F_205 ( V_253 ) ;
V_144 -> V_144 . V_144 . V_260 . V_300 = V_464 ;
V_144 -> V_144 . V_144 . V_260 . V_164 = V_253 -> V_23 - sizeof( struct V_459 ) ;
V_144 -> V_465 . V_466 = ( T_2 ) sizeof( struct V_467 ) ;
V_144 -> V_465 . V_468 = 1 ;
V_144 -> V_465 . V_469 = 1 ;
V_144 -> V_465 . V_470 = 1 ;
V_144 -> V_465 . V_471 = 28 ;
V_144 -> V_465 . V_472 = F_210 ( V_253 ) -> V_473 ;
V_144 -> V_465 . V_474 = ( T_2 ) ( V_453 -> V_475 * 4 + V_461 -> V_476 * 4 ) ;
V_144 -> V_465 . V_477 = ( T_2 ) ( V_253 -> V_23 - V_144 -> V_465 . V_474 -
sizeof( struct V_459 ) ) ;
V_461 -> V_456 = 0 ;
if ( V_253 -> V_280 == V_261 ) {
V_463 -> V_477 = 0 ;
V_461 -> V_456 = ~ F_211 ( & V_463 -> V_478 , & V_463 -> V_264 ,
0 , V_479 , 0 ) ;
} else {
V_461 -> V_456 = ~ F_212 ( V_453 -> V_478 , V_453 -> V_264 ,
0 , V_479 , 0 ) ;
V_453 -> V_480 = 0 ;
V_453 -> V_456 = 0 ;
}
}
static inline int F_213 ( struct V_252 * V_253 )
{
unsigned long V_481 = ( unsigned long ) F_209 ( V_253 ) +
F_209 ( V_253 ) -> V_476 * 4 ;
int V_482 = V_253 -> V_23 - ( V_481 - ( unsigned long ) V_253 -> V_85 ) ;
int V_483 = F_214 ( V_481 + V_482 - 1 ) - F_215 ( V_481 ) ;
V_483 += F_216 ( V_253 ) ;
return V_483 ;
}
static int F_217 ( struct V_252 * V_253 , struct V_218 * V_125 )
{
int V_4 ;
T_4 * V_484 ;
struct V_254 * V_144 = NULL ;
int V_485 = 0 ;
int V_486 ;
struct V_27 * V_28 = V_125 -> V_248 ;
struct V_252 * V_487 = NULL ;
int V_446 = F_218 ( V_253 ) ;
int V_128 = F_195 ( V_28 , V_253 ) ;
struct V_488 * V_489 = V_28 -> V_293 . V_490
[ F_219 ( V_28 , V_253 , V_446 , V_128 ) ] ;
int V_491 = V_253 -> V_23 ;
bool V_492 ;
int V_493 = - 1 ;
int V_494 ;
if ( ( ( V_28 -> V_99 . type == V_100 ) &&
( ( ( V_28 -> V_43 . V_495 != V_496 ) && ! V_446 ) ||
( ( V_28 -> V_43 . V_495 == V_496 ) &&
( V_253 -> V_280 != V_302 ) ) ) ) ||
V_28 -> V_43 . V_44 )
goto V_497;
if ( ( V_28 -> V_71 != V_72 ) || ! V_28 -> V_498 ) {
V_28 -> V_267 . V_499 ++ ;
goto V_497;
}
if ( ( V_128 == V_131 ) &&
( V_28 -> V_99 . V_177 == 0 ) )
goto V_497;
if ( V_28 -> V_43 . V_315 ) {
V_28 -> V_316 . V_500 ++ ;
V_28 -> V_316 . V_501 = F_148 () ;
}
V_492 = F_220 ( V_253 ) ;
if ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_492 ) &&
( F_210 ( V_253 ) -> V_494 == 0 ) ) {
V_487 = V_253 ;
if ( V_487 -> V_280 == V_302 )
V_493 = 0 ;
else
V_493 = V_502 ;
V_144 = F_221 ( V_503 , V_61 ) ;
if ( ! V_144 )
goto V_497;
V_485 ++ ;
} else {
V_487 = F_222 ( V_253 , sizeof( struct V_459 )
+ V_504 ) ;
if ( ! V_487 )
goto V_497;
}
if ( V_28 -> V_99 . type == V_100 ) {
if ( V_493 < 0 )
F_201 ( V_487 , V_502 ) ;
} else {
if ( V_446 == 4 ) {
F_201 ( V_487 , V_502 ) ;
}
if ( V_446 != 4 && F_203 ( V_487 ) ) {
F_223 ( V_487 , V_504 ) ;
F_224 ( V_487 , V_487 -> V_85 + 4 , 4 ) ;
F_225 ( V_487 , 4 ,
V_487 -> V_85 + 8 , 4 ) ;
F_225 ( V_487 , 8 ,
V_487 -> V_85 + 12 , 4 ) ;
V_484 = ( T_4 * ) ( V_487 -> V_85 + 12 ) ;
* V_484 = F_136 ( V_230 ) ;
* ( V_484 + 1 ) = F_111 ( F_204 ( V_487 ) ) ;
}
}
F_226 ( V_125 ) ;
if ( V_492 ) {
if ( F_213 ( V_487 ) + 1 > 16 ) {
if ( F_227 ( V_487 ) )
goto V_497;
if ( V_28 -> V_43 . V_315 )
V_28 -> V_316 . V_505 ++ ;
}
}
if ( V_492 && ( V_128 == V_430 ) ) {
V_144 = (struct V_254 * ) F_223 ( V_487 ,
sizeof( struct V_459 ) ) ;
memset ( V_144 , 0 , sizeof( struct V_459 ) ) ;
F_202 ( V_28 , V_144 , V_487 , V_446 , V_128 ) ;
F_208 ( V_28 , V_144 , V_487 ) ;
V_485 ++ ;
} else {
if ( V_493 < 0 ) {
V_144 = (struct V_254 * ) F_223 ( V_487 ,
sizeof( struct V_254 ) ) ;
F_202 ( V_28 , V_144 , V_487 , V_446 ,
V_128 ) ;
} else {
if ( V_487 -> V_280 == V_302 )
F_200 ( V_28 , V_144 , V_487 ) ;
else {
F_202 ( V_28 , V_144 , V_487 , V_446 ,
V_128 ) ;
V_144 -> V_144 . V_260 . V_164 = V_487 -> V_23 - V_493 ;
}
}
if ( V_253 -> V_285 == V_506 )
F_207 ( V_28 , V_144 , V_487 ) ;
}
V_486 = F_228 ( V_28 , V_487 , V_485 ) ;
if ( ! V_486 ) {
if ( V_493 >= 0 )
F_229 ( V_503 , V_144 ) ;
goto V_497;
}
V_485 += V_486 ;
V_494 = F_210 ( V_487 ) -> V_494 ;
if ( V_28 -> V_99 . type != V_100 ) {
int V_23 ;
if ( V_492 )
V_23 = ( ( unsigned long ) F_209 ( V_487 ) +
F_209 ( V_487 ) -> V_476 * 4 ) -
( unsigned long ) V_487 -> V_85 ;
else
V_23 = sizeof( struct V_507 ) ;
if ( F_230 ( V_487 , & V_144 , V_23 ) )
goto V_497;
V_4 = F_231 ( V_28 , V_489 , V_487 , V_144 ,
V_485 ) ;
} else
V_4 = F_232 ( V_28 , V_489 , V_487 , V_144 ,
V_485 , V_493 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_267 . V_508 ++ ;
V_28 -> V_267 . V_491 += V_491 ;
if ( V_487 != V_253 )
F_144 ( V_253 ) ;
if ( V_28 -> V_43 . V_315 ) {
if ( V_492 ) {
V_28 -> V_316 . V_509 += V_491 ;
V_28 -> V_316 . V_510 ++ ;
}
if ( V_494 ) {
V_28 -> V_316 . V_511 ++ ;
V_28 -> V_316 . V_512 += V_494 + 1 ;
}
}
V_4 = V_513 ;
} else {
if ( V_493 >= 0 )
F_229 ( V_503 , V_144 ) ;
if ( V_4 == - V_514 ) {
if ( V_487 != V_253 )
F_144 ( V_487 ) ;
return V_515 ;
} else
goto V_497;
}
F_233 ( V_125 ) ;
if ( V_28 -> V_43 . V_315 )
V_28 -> V_316 . V_516 += F_148 () -
V_28 -> V_316 . V_501 ;
return V_4 ;
V_497:
V_28 -> V_267 . V_517 ++ ;
V_28 -> V_267 . V_518 ++ ;
if ( ( V_487 != V_253 ) && V_487 )
F_144 ( V_487 ) ;
F_144 ( V_253 ) ;
F_233 ( V_125 ) ;
return V_513 ;
}
static int F_234 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_172 ) ;
if ( V_28 -> V_71 == V_72 )
return V_4 ;
if ( V_28 -> V_71 != V_73 )
return - V_409 ;
V_28 -> V_85 . V_71 = V_334 ;
V_28 -> V_71 = V_72 ;
F_235 ( V_125 ) ;
if ( F_236 ( V_28 -> V_85 . V_321 , 0 ) >= 0 ) {
F_237 ( & V_28 -> V_305 ) ;
F_155 ( & V_28 -> V_305 ) ;
} else
V_4 = - V_185 ;
return V_4 ;
}
static int F_238 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
F_17 ( V_28 , 5 , L_173 ) ;
if ( F_132 ( V_28 , V_250 ) ) {
F_17 ( V_28 , 3 , L_174 ) ;
return - V_519 ;
}
return F_234 ( V_125 ) ;
}
static int F_164 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
F_17 ( V_28 , 4 , L_175 ) ;
F_239 ( V_125 ) ;
if ( V_28 -> V_71 == V_72 ) {
V_28 -> V_71 = V_73 ;
F_240 ( & V_28 -> V_305 ) ;
}
return 0 ;
}
static T_8 F_241 ( struct V_218 * V_125 ,
T_8 V_187 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
if ( ! F_53 ( V_28 , V_158 ) )
V_187 &= ~ V_520 ;
if ( ! F_53 ( V_28 , V_190 ) )
V_187 &= ~ V_191 ;
if ( ! F_53 ( V_28 , V_153 ) )
V_187 &= ~ V_188 ;
return V_187 ;
}
static int F_242 ( struct V_218 * V_125 ,
T_8 V_187 )
{
struct V_27 * V_28 = V_125 -> V_248 ;
T_9 V_521 = V_125 -> V_187 ^ V_187 ;
int V_522 ;
if ( ! ( V_521 & V_188 ) )
return 0 ;
if ( V_28 -> V_71 == V_337 ||
V_28 -> V_71 == V_523 )
return 0 ;
V_522 = F_88 ( V_28 , V_187 & V_188 ) ;
if ( V_522 )
V_125 -> V_187 = V_187 ^ V_188 ;
return V_522 ;
}
static int F_243 ( struct V_431 * V_432 )
{
V_432 -> V_524 = V_525 ;
memcpy ( V_432 -> V_526 , L_125 , 6 ) ;
V_432 -> V_527 = V_432 -> V_528 -> V_529 ;
return 0 ;
}
static int
F_244 ( struct V_218 * V_125 , struct V_530 * V_531 )
{
if ( V_531 -> V_532 -> V_533 == V_534 )
V_531 -> V_535 = F_243 ;
return 0 ;
}
static int F_245 ( struct V_27 * V_28 )
{
if ( V_28 -> V_99 . type == V_422 ||
V_28 -> V_99 . type == V_423 ) {
if ( ( V_28 -> V_99 . V_436 == V_438 ) ||
( V_28 -> V_99 . V_436 == V_437 ) ) {
F_246 ( L_176 ) ;
return - V_409 ;
} else {
V_28 -> V_125 = F_247 ( 0 ) ;
if ( ! V_28 -> V_125 )
return - V_409 ;
V_28 -> V_125 -> V_536 = & V_537 ;
F_101 ( V_28 ) ;
if ( ! ( V_28 -> V_99 . V_194 & V_198 ) )
V_28 -> V_125 -> V_538 = V_28 -> V_99 . V_194 &
0xffff ;
if ( ! V_28 -> V_99 . V_339 ) {
V_28 -> V_125 -> V_539 = V_540 |
V_188 | V_520 |
V_191 ;
V_28 -> V_125 -> V_187 = V_188 ;
}
}
} else if ( V_28 -> V_99 . type == V_100 ) {
V_28 -> V_125 = F_248 ( 0 , L_177 , V_541 ) ;
if ( ! V_28 -> V_125 )
return - V_409 ;
V_28 -> V_125 -> V_58 |= V_542 ;
V_28 -> V_125 -> V_536 = & V_543 ;
F_99 ( V_28 ) ;
if ( V_28 -> V_43 . V_544 [ 0 ] )
memcpy ( V_28 -> V_125 -> V_545 , V_28 -> V_43 . V_544 , 9 ) ;
} else
return - V_409 ;
V_28 -> V_125 -> V_248 = V_28 ;
V_28 -> V_125 -> V_546 = V_547 ;
V_28 -> V_125 -> V_548 = V_28 -> V_99 . V_549 ;
F_249 ( V_28 -> V_125 , & V_550 ) ;
V_28 -> V_125 -> V_187 |= V_551 |
V_552 |
V_553 ;
V_28 -> V_125 -> V_554 &= ~ V_555 ;
V_28 -> V_125 -> V_556 = 15 * V_557 ;
F_250 ( V_28 -> V_125 , & V_28 -> V_124 -> V_125 ) ;
F_251 ( V_28 -> V_125 , & V_28 -> V_305 , F_146 , V_558 ) ;
return F_252 ( V_28 -> V_125 ) ;
}
static int F_253 ( struct V_559 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
F_255 ( & V_124 -> V_125 ) ;
V_28 -> V_43 . V_331 = 0 ;
V_28 -> V_99 . V_560 = 0 ;
return 0 ;
}
static void F_256 ( struct V_559 * V_561 )
{
struct V_27 * V_28 = F_254 ( & V_561 -> V_125 ) ;
F_257 ( & V_561 -> V_125 ) ;
F_163 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_562 , F_173 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_561 -> V_71 == V_563 )
F_259 ( V_561 ) ;
if ( V_28 -> V_125 ) {
F_260 ( V_28 -> V_125 ) ;
V_28 -> V_125 = NULL ;
}
F_37 ( V_28 , 0 ) ;
F_54 ( V_28 ) ;
return;
}
static int F_261 ( struct V_559 * V_124 , int V_332 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
enum V_564 V_565 ;
F_262 ( & V_28 -> V_566 ) ;
F_262 ( & V_28 -> V_567 ) ;
F_65 ( V_139 , 2 , L_178 ) ;
F_145 ( V_139 , 2 , & V_28 , sizeof( void * ) ) ;
V_565 = V_28 -> V_71 ;
V_4 = F_263 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_139 , 2 , L_179 , V_4 ) ;
V_4 = - V_409 ;
goto V_568;
}
if ( ! V_28 -> V_125 && F_245 ( V_28 ) ) {
V_4 = - V_409 ;
goto V_568;
}
if ( F_265 ( V_28 , V_569 ) ) {
if ( V_28 -> V_99 . V_560 &&
F_266 ( V_28 , V_570 ) )
V_28 -> V_99 . V_560 = 0 ;
} else
V_28 -> V_99 . V_560 = 0 ;
V_28 -> V_71 = V_336 ;
memset ( & V_28 -> V_296 , 0 , sizeof( struct V_571 ) ) ;
F_267 ( V_28 ) ;
F_65 ( V_139 , 2 , L_180 ) ;
V_4 = F_268 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_139 , 2 , L_181 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_182 ) ;
V_28 -> V_498 = 0 ;
goto V_572;
}
V_4 = - V_409 ;
goto V_568;
} else
V_28 -> V_498 = 1 ;
V_572:
V_4 = F_64 ( V_28 ) ;
if ( V_4 )
F_264 ( V_139 , 2 , L_179 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_95 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_139 , 2 , L_183 , V_4 ) ;
goto V_568;
}
V_4 = F_48 ( V_28 ) ;
if ( V_4 )
F_264 ( V_139 , 2 , L_184 , V_4 ) ;
V_4 = F_51 ( V_28 ) ;
if ( V_4 )
F_264 ( V_139 , 2 , L_185 , V_4 ) ;
}
F_239 ( V_28 -> V_125 ) ;
V_4 = F_269 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_139 , 2 , L_186 , V_4 ) ;
V_4 = - V_409 ;
goto V_568;
}
V_28 -> V_71 = V_73 ;
F_163 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_498 )
F_270 ( V_28 -> V_125 ) ;
else
F_271 ( V_28 -> V_125 ) ;
if ( V_565 == V_523 ) {
F_90 () ;
if ( V_332 )
F_234 ( V_28 -> V_125 ) ;
else
F_272 ( V_28 -> V_125 ) ;
F_134 ( V_28 -> V_125 ) ;
F_92 () ;
}
F_273 ( V_28 ) ;
F_274 ( & V_124 -> V_125 . V_573 , V_574 ) ;
F_275 ( & V_28 -> V_567 ) ;
F_275 ( & V_28 -> V_566 ) ;
return 0 ;
V_568:
F_162 ( V_28 , 0 ) ;
F_276 ( F_277 ( V_28 ) ) ;
F_276 ( F_278 ( V_28 ) ) ;
F_276 ( F_279 ( V_28 ) ) ;
F_280 ( F_277 ( V_28 ) ) ;
if ( V_565 == V_523 )
V_28 -> V_71 = V_523 ;
else
V_28 -> V_71 = V_337 ;
F_275 ( & V_28 -> V_567 ) ;
F_275 ( & V_28 -> V_566 ) ;
return V_4 ;
}
static int F_281 ( struct V_559 * V_124 )
{
return F_261 ( V_124 , 0 ) ;
}
static int F_282 ( struct V_559 * V_561 ,
int V_332 )
{
struct V_27 * V_28 = F_254 ( & V_561 -> V_125 ) ;
int V_4 = 0 , V_575 = 0 , V_576 = 0 ;
enum V_564 V_565 ;
F_262 ( & V_28 -> V_566 ) ;
F_262 ( & V_28 -> V_567 ) ;
F_65 ( V_139 , 3 , L_187 ) ;
F_145 ( V_139 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_125 && F_283 ( V_28 -> V_125 ) )
F_271 ( V_28 -> V_125 ) ;
V_565 = V_28 -> V_71 ;
if ( ( ! V_332 && V_28 -> V_99 . V_560 ) || V_28 -> V_99 . V_560 == 2 ) {
F_266 ( V_28 , V_577 ) ;
V_28 -> V_99 . V_560 = 1 ;
}
F_162 ( V_28 , V_332 ) ;
if ( ( V_28 -> V_43 . V_495 == V_496 ) && V_28 -> V_125 ) {
F_90 () ;
F_284 ( V_578 , V_28 -> V_125 ) ;
F_92 () ;
}
V_4 = F_276 ( F_277 ( V_28 ) ) ;
V_575 = F_276 ( F_278 ( V_28 ) ) ;
V_576 = F_276 ( F_279 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_575 ) ? V_575 : V_576 ;
if ( V_4 )
F_264 ( V_139 , 2 , L_181 , V_4 ) ;
F_280 ( F_277 ( V_28 ) ) ;
if ( V_565 == V_72 )
V_28 -> V_71 = V_523 ;
F_274 ( & V_561 -> V_125 . V_573 , V_574 ) ;
F_275 ( & V_28 -> V_567 ) ;
F_275 ( & V_28 -> V_566 ) ;
return 0 ;
}
static int F_259 ( struct V_559 * V_561 )
{
return F_282 ( V_561 , 0 ) ;
}
static int F_285 ( void * V_579 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_579 ;
F_17 ( V_28 , 2 , L_188 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_286 ( V_28 , V_250 ) )
return 0 ;
F_17 ( V_28 , 2 , L_189 ) ;
F_61 ( & V_28 -> V_124 -> V_125 ,
L_190 ) ;
F_287 ( V_28 ) ;
F_282 ( V_28 -> V_124 , 1 ) ;
V_4 = F_261 ( V_28 -> V_124 , 1 ) ;
if ( ! V_4 )
F_66 ( & V_28 -> V_124 -> V_125 ,
L_191 ) ;
else {
F_288 ( V_28 ) ;
F_61 ( & V_28 -> V_124 -> V_125 , L_192
L_193 ) ;
}
F_289 ( V_28 ) ;
F_290 ( V_28 , V_250 ) ;
F_291 ( V_28 , V_250 ) ;
return 0 ;
}
static void F_292 ( struct V_559 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
F_163 ( V_28 , 0 , 1 ) ;
if ( ( V_124 -> V_71 == V_563 ) && V_28 -> V_99 . V_560 )
F_266 ( V_28 , V_577 ) ;
F_167 ( V_28 , 0 ) ;
F_168 ( V_28 ) ;
F_280 ( F_277 ( V_28 ) ) ;
}
static int F_293 ( struct V_559 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
if ( V_28 -> V_125 )
F_294 ( V_28 -> V_125 ) ;
F_163 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_562 , F_173 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_124 -> V_71 == V_580 )
return 0 ;
if ( V_28 -> V_71 == V_72 ) {
if ( V_28 -> V_99 . V_560 )
F_266 ( V_28 , V_577 ) ;
F_282 ( V_28 -> V_124 , 1 ) ;
} else
F_282 ( V_28 -> V_124 , 0 ) ;
return 0 ;
}
static int F_295 ( struct V_559 * V_124 )
{
struct V_27 * V_28 = F_254 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
if ( V_124 -> V_71 == V_580 )
goto V_14;
if ( V_28 -> V_71 == V_523 ) {
V_4 = F_261 ( V_28 -> V_124 , 1 ) ;
if ( V_4 ) {
F_90 () ;
F_165 ( V_28 -> V_125 ) ;
F_92 () ;
}
} else
V_4 = F_261 ( V_28 -> V_124 , 0 ) ;
V_14:
F_163 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_125 )
F_296 ( V_28 -> V_125 ) ;
if ( V_4 )
F_61 ( & V_28 -> V_124 -> V_125 , L_192
L_193 ) ;
return V_4 ;
}
static int F_297 ( struct V_27 * V_28 ,
struct V_83 * V_84 )
{
return 1 ;
}
static int F_298 ( struct V_581 * V_582 ,
unsigned long V_583 , void * V_579 )
{
struct V_240 * V_241 = (struct V_240 * ) V_579 ;
struct V_218 * V_125 = (struct V_218 * ) V_241 -> V_584 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_299 ( V_125 ) != & V_585 )
return V_586 ;
V_28 = F_161 ( V_125 ) ;
if ( ! V_28 )
return V_586 ;
F_17 ( V_28 , 3 , L_194 ) ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_241 -> V_244 ;
V_2 -> V_36 . V_47 . V_48 = V_241 -> V_245 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_583 ) {
case V_587 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_588 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_586 ;
}
static int F_300 ( struct V_581 * V_582 ,
unsigned long V_583 , void * V_579 )
{
struct V_246 * V_241 = (struct V_246 * ) V_579 ;
struct V_218 * V_125 = (struct V_218 * ) V_241 -> V_589 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_161 ( V_125 ) ;
if ( ! V_28 )
return V_586 ;
F_17 ( V_28 , 3 , L_195 ) ;
if ( ! F_53 ( V_28 , V_110 ) )
return V_586 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_241 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_241 -> V_247 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_583 ) {
case V_587 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_588 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_586 ;
}
static int F_301 ( void )
{
int V_4 ;
F_65 ( V_139 , 5 , L_196 ) ;
V_4 = F_302 ( & V_590 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_52
V_4 = F_303 ( & V_591 ) ;
if ( V_4 ) {
F_304 ( & V_590 ) ;
return V_4 ;
}
#else
F_305 ( L_197 ) ;
#endif
return 0 ;
}
static void F_306 ( void )
{
F_65 ( V_139 , 5 , L_198 ) ;
F_307 ( F_304 ( & V_590 ) ) ;
#ifdef F_52
F_307 ( F_308 ( & V_591 ) ) ;
#endif
}
static int T_10 F_309 ( void )
{
int V_4 = 0 ;
F_246 ( L_199 ) ;
V_4 = F_301 () ;
return V_4 ;
}
static void T_11 F_310 ( void )
{
F_306 () ;
F_246 ( L_200 ) ;
}
