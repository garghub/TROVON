static int F_1 ( char * V_1 )
{
while ( * V_1 ) {
if ( ! isxdigit ( * V_1 ++ ) )
return 0 ;
}
return 1 ;
}
static void F_2 ( const T_1 * V_2 , char * V_1 )
{
sprintf ( V_1 , L_1 , V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] ) ;
}
static int F_3 ( const char * V_1 , T_1 * V_2 )
{
int V_3 = 0 , V_4 = 0 ;
unsigned int V_5 [ 4 ] ;
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
static void F_4 ( const T_1 * V_2 , char * V_1 )
{
sprintf ( V_1 , L_3 , V_2 ) ;
}
static int F_5 ( const char * V_1 , T_1 * V_2 )
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
if ( ! F_33 ( V_28 ) || V_28 -> V_43 . V_44 )
return;
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
while ( ! F_34 ( V_70 ) ) {
V_63 = F_35 ( V_70 -> V_71 , struct V_29 , V_53 ) ;
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
if ( ! V_4 || ( V_4 == V_72 ) )
F_18 ( & V_63 -> V_53 , & V_28 -> V_69 ) ;
else
F_15 ( V_63 ) ;
} else if ( V_4 == - 1 ) {
F_37 ( & V_2 -> V_53 ) ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
V_4 = F_30 ( V_28 , V_2 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( ! V_4 || ( V_4 == V_73 ) )
F_15 ( V_2 ) ;
else
F_18 ( & V_2 -> V_53 , & V_28 -> V_69 ) ;
F_15 ( V_63 ) ;
}
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
F_15 ( V_70 ) ;
}
static void F_38 ( struct V_27 * V_28 , int V_74 )
{
struct V_29 * V_2 , * V_41 ;
unsigned long V_58 ;
F_17 ( V_28 , 4 , L_12 ) ;
if ( V_74 && V_28 -> V_43 . V_44 )
return;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_13 (addr, tmp, card->ip_tbd_list, entry) {
F_14 ( & V_2 -> V_53 ) ;
F_15 ( V_2 ) ;
}
while ( ! F_34 ( & V_28 -> V_69 ) ) {
V_2 = F_35 ( V_28 -> V_69 . V_71 ,
struct V_29 , V_53 ) ;
F_37 ( & V_2 -> V_53 ) ;
if ( ! V_74 || V_2 -> V_46 ) {
F_15 ( V_2 ) ;
continue;
}
F_18 ( & V_2 -> V_53 , V_28 -> V_54 ) ;
}
F_22 ( & V_28 -> V_59 , V_58 ) ;
}
static int F_39 ( struct V_65 * V_75 ,
struct V_29 * V_2 , int V_76 )
{
struct V_29 * V_41 ;
F_10 (tmp, list, entry) {
if ( ( V_41 -> V_19 == V_20 ) &&
( V_2 -> V_19 == V_20 ) &&
( ( V_76 && ( V_41 -> type == V_2 -> type ) ) ||
( ! V_76 && ( V_41 -> type != V_2 -> type ) ) ) &&
( V_41 -> V_36 . V_47 . V_2 == V_2 -> V_36 . V_47 . V_2 ) )
return 1 ;
if ( ( V_41 -> V_19 == V_21 ) &&
( V_2 -> V_19 == V_21 ) &&
( ( V_76 && ( V_41 -> type == V_2 -> type ) ) ||
( ! V_76 && ( V_41 -> type != V_2 -> type ) ) ) &&
( memcmp ( & V_41 -> V_36 . V_49 . V_2 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) == 0 ) )
return 1 ;
}
return 0 ;
}
static int F_40 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_77 )
{
int V_4 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_17 ( V_28 , 4 , L_13 ) ;
V_79 = F_41 ( V_28 , V_77 , V_2 -> V_19 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
memcpy ( & V_81 -> V_83 . V_85 . V_86 , V_2 -> V_86 , V_87 ) ;
if ( V_2 -> V_19 == V_21 )
memcpy ( V_81 -> V_83 . V_85 . V_88 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
else
memcpy ( & V_81 -> V_83 . V_85 . V_89 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
V_4 = F_42 ( V_28 , V_79 , NULL , NULL ) ;
return V_4 ;
}
static void F_43 ( T_3 * V_90 , unsigned int V_23 )
{
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_25 = ( V_23 ) - ( V_24 * 8 ) ;
if ( V_25 >= 8 )
V_90 [ V_24 ] = 0xff ;
else if ( V_25 > 0 )
V_90 [ V_24 ] = ( T_3 ) ( 0xFF00 >> V_25 ) ;
else
V_90 [ V_24 ] = 0 ;
}
}
static int F_44 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_77 , unsigned int V_58 )
{
int V_4 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
T_1 V_90 [ 16 ] ;
F_17 ( V_28 , 4 , L_14 ) ;
F_45 ( V_28 , 4 , L_15 , V_58 ) ;
V_79 = F_41 ( V_28 , V_77 , V_2 -> V_19 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
if ( V_2 -> V_19 == V_21 ) {
memcpy ( V_81 -> V_83 . V_91 . V_92 , & V_2 -> V_36 . V_49 . V_2 ,
sizeof( struct V_51 ) ) ;
F_43 ( V_90 , V_2 -> V_36 . V_49 . V_50 ) ;
memcpy ( V_81 -> V_83 . V_91 . V_48 , V_90 ,
sizeof( struct V_51 ) ) ;
V_81 -> V_83 . V_91 . V_58 = V_58 ;
} else {
memcpy ( V_81 -> V_83 . V_93 . V_92 , & V_2 -> V_36 . V_47 . V_2 , 4 ) ;
memcpy ( V_81 -> V_83 . V_93 . V_48 , & V_2 -> V_36 . V_47 . V_48 , 4 ) ;
V_81 -> V_83 . V_93 . V_58 = V_58 ;
}
V_4 = F_42 ( V_28 , V_79 , NULL , NULL ) ;
return V_4 ;
}
static int F_46 ( struct V_27 * V_28 ,
enum V_94 type , enum V_18 V_60 )
{
int V_4 ;
struct V_80 * V_81 ;
struct V_78 * V_79 ;
F_17 ( V_28 , 4 , L_16 ) ;
V_79 = F_41 ( V_28 , V_95 , V_60 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_96 . type = ( type ) ;
V_4 = F_42 ( V_28 , V_79 , NULL , NULL ) ;
return V_4 ;
}
static int F_47 ( struct V_27 * V_28 ,
enum V_94 * type , enum V_18 V_60 )
{
if ( V_28 -> V_97 . type == V_98 ) {
switch ( * type ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
return 0 ;
default:
goto V_103;
}
} else {
switch ( * type ) {
case V_99 :
case V_104 :
case V_105 :
return 0 ;
case V_102 :
if ( F_48 ( V_28 , V_60 ,
V_106 ) )
return 0 ;
default:
goto V_103;
}
}
V_103:
* type = V_99 ;
return - V_7 ;
}
int F_49 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_17 ) ;
V_4 = F_47 ( V_28 , & V_28 -> V_43 . V_107 . type ,
V_20 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_46 ( V_28 , V_28 -> V_43 . V_107 . type ,
V_20 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_107 . type = V_99 ;
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
if ( ! F_54 ( V_28 , V_108 ) )
return 0 ;
V_4 = F_47 ( V_28 , & V_28 -> V_43 . V_109 . type ,
V_21 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_46 ( V_28 , V_28 -> V_43 . V_109 . type ,
V_21 ) ;
if ( V_4 ) {
V_28 -> V_43 . V_109 . type = V_99 ;
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
struct V_30 * V_110 )
{
struct V_30 * V_31 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_17 ( V_28 , 2 , L_21 ) ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
F_10 (ipatoe, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_110 -> V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_110 -> V_2 ,
( V_31 -> V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_110 -> V_37 ) ) {
V_4 = - V_111 ;
break;
}
}
if ( ! V_4 )
F_18 ( & V_110 -> V_53 , & V_28 -> V_34 . V_112 ) ;
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
struct V_29 * V_113 ;
unsigned long V_58 ;
int V_4 = 0 ;
V_113 = F_24 ( V_19 ) ;
if ( V_113 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_23 ) ;
memcpy ( & V_113 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_113 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_24 ) ;
memcpy ( & V_113 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_113 -> V_36 . V_49 . V_50 = 0 ;
}
V_113 -> type = V_114 ;
V_113 -> V_56 = V_115 ;
V_113 -> V_116 = V_117 ;
} else
return - V_82 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( F_39 ( & V_28 -> V_69 , V_113 , 0 ) ||
F_39 ( V_28 -> V_54 , V_113 , 0 ) )
V_4 = - V_111 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
F_15 ( V_113 ) ;
return V_4 ;
}
if ( ! F_23 ( V_28 , V_113 ) )
F_15 ( V_113 ) ;
F_32 ( V_28 ) ;
return V_4 ;
}
void F_59 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_113 ;
V_113 = F_24 ( V_19 ) ;
if ( V_113 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_25 ) ;
memcpy ( & V_113 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_113 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_26 ) ;
memcpy ( & V_113 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_113 -> V_36 . V_49 . V_50 = 0 ;
}
V_113 -> type = V_114 ;
} else
return;
if ( ! F_19 ( V_28 , V_113 ) )
F_15 ( V_113 ) ;
F_32 ( V_28 ) ;
}
int F_60 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_113 ;
unsigned long V_58 ;
int V_4 = 0 ;
V_113 = F_24 ( V_19 ) ;
if ( V_113 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_27 ) ;
memcpy ( & V_113 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_113 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_28 ) ;
memcpy ( & V_113 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_113 -> V_36 . V_49 . V_50 = 0 ;
}
V_113 -> type = V_118 ;
V_113 -> V_56 = V_57 ;
V_113 -> V_116 = 0 ;
} else
return - V_82 ;
F_21 ( & V_28 -> V_59 , V_58 ) ;
if ( F_39 ( & V_28 -> V_69 , V_113 , 0 ) ||
F_39 ( V_28 -> V_54 , V_113 , 0 ) )
V_4 = - V_111 ;
F_22 ( & V_28 -> V_59 , V_58 ) ;
if ( V_4 ) {
F_15 ( V_113 ) ;
return V_4 ;
}
if ( ! F_23 ( V_28 , V_113 ) )
F_15 ( V_113 ) ;
F_32 ( V_28 ) ;
return 0 ;
}
void F_61 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_113 ;
V_113 = F_24 ( V_19 ) ;
if ( V_113 ) {
if ( V_19 == V_20 ) {
F_17 ( V_28 , 2 , L_27 ) ;
memcpy ( & V_113 -> V_36 . V_47 . V_2 , V_2 , 4 ) ;
V_113 -> V_36 . V_47 . V_48 = 0 ;
} else if ( V_19 == V_21 ) {
F_17 ( V_28 , 2 , L_28 ) ;
memcpy ( & V_113 -> V_36 . V_49 . V_2 , V_2 , 16 ) ;
V_113 -> V_36 . V_49 . V_50 = 0 ;
}
V_113 -> type = V_118 ;
} else
return;
if ( ! F_19 ( V_28 , V_113 ) )
F_15 ( V_113 ) ;
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
V_4 = F_40 ( V_28 , V_2 , V_119 ) ;
else
V_4 = F_44 ( V_28 , V_2 , V_120 ,
V_2 -> V_56 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
} while ( ( -- V_13 > 0 ) && V_4 );
if ( V_4 ) {
F_17 ( V_28 , 2 , L_33 ) ;
F_6 ( V_2 -> V_19 , ( T_3 * ) & V_2 -> V_36 , V_1 ) ;
F_62 ( & V_28 -> V_121 -> V_122 ,
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
V_4 = F_40 ( V_28 , V_2 , V_123 ) ;
else
V_4 = F_44 ( V_28 , V_2 , V_124 ,
V_2 -> V_116 ) ;
if ( V_4 )
F_17 ( V_28 , 2 , L_32 ) ;
return V_4 ;
}
static inline T_3 F_63 ( int V_125 )
{
if ( V_125 == V_126 )
return V_127 ;
if ( V_125 == V_128 )
return V_129 ;
return V_130 ;
}
static inline T_3 F_64 ( int V_125 )
{
T_3 V_131 = V_132 | V_133 ;
if ( V_125 == V_126 )
return V_131 | V_127 ;
if ( V_125 == V_134 )
return V_131 | V_135 ;
if ( V_125 == V_128 )
return V_131 | V_129 ;
return V_131 | V_130 ;
}
static int F_65 ( struct V_27 * V_28 )
{
int V_4 ;
F_66 ( V_136 , 2 , L_38 ) ;
if ( ! F_54 ( V_28 , V_137 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_39 ) ;
F_66 ( V_136 , 2 , L_40 ) ;
return 0 ;
}
V_4 = F_68 ( V_28 ) ;
if ( V_4 ) {
F_50 ( 2 , L_41
L_42 , F_69 ( & V_28 -> V_121 -> V_122 ) , V_4 ) ;
return V_4 ;
}
if ( F_70 ( V_28 , V_138 ) ) {
V_4 = F_71 ( V_28 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_43
L_44 ) ;
}
return V_4 ;
}
static int F_72 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
F_17 ( V_28 , 4 , L_45 ) ;
V_81 = (struct V_80 * ) V_83 ;
if ( V_81 -> V_141 . V_142 == 0 ) {
V_81 -> V_141 . V_142 = V_81 -> V_83 . V_143 . V_141 . V_142 ;
if ( V_81 -> V_141 . V_144 == V_20 )
V_28 -> V_43 . V_145 . V_146 = V_81 -> V_141 . V_147 ;
if ( V_81 -> V_141 . V_144 == V_21 )
V_28 -> V_43 . V_148 . V_146 = V_81 -> V_141 . V_147 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_149 == V_150 &&
V_81 -> V_83 . V_143 . V_141 . V_151 == V_152 ) {
V_28 -> V_97 . V_153 = V_81 -> V_83 . V_143 . V_83 . V_154 ;
F_45 ( V_28 , 3 , L_46 , V_28 -> V_97 . V_153 ) ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_149 == V_155 &&
V_81 -> V_83 . V_143 . V_141 . V_151 == V_152 ) {
V_28 -> V_97 . V_156 =
V_81 -> V_83 . V_143 . V_83 . V_154 ;
F_45 ( V_28 , 3 , L_47 , V_28 -> V_97 . V_156 ) ;
}
return 0 ;
}
static struct V_78 * F_73 (
struct V_27 * V_28 , enum V_157 V_158 , T_2 V_159 ,
T_2 V_23 , enum V_18 V_60 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_17 ( V_28 , 4 , L_48 ) ;
V_79 = F_41 ( V_28 , V_160 , V_60 ) ;
if ( V_79 ) {
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_143 . V_141 . V_149 = V_158 ;
V_81 -> V_83 . V_143 . V_141 . V_161 = 8 + V_23 ;
V_81 -> V_83 . V_143 . V_141 . V_151 = V_159 ;
V_81 -> V_83 . V_143 . V_141 . V_142 = 0 ;
V_81 -> V_83 . V_143 . V_141 . V_162 = 0 ;
}
return V_79 ;
}
static int F_74 ( struct V_27 * V_28 ,
struct V_78 * V_79 , T_2 V_23 , long V_83 ,
int (* F_75)( struct V_27 * , struct V_139 * ,
unsigned long ) ,
void * V_163 )
{
int V_4 ;
struct V_80 * V_81 ;
F_17 ( V_28 , 4 , L_49 ) ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
if ( V_23 <= sizeof( V_164 ) )
V_81 -> V_83 . V_143 . V_83 . V_154 = ( V_164 ) V_83 ;
else
memcpy ( & V_81 -> V_83 . V_143 . V_83 , ( void * ) V_83 , V_23 ) ;
V_4 = F_42 ( V_28 , V_79 , F_75 , V_163 ) ;
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 ,
enum V_157 V_158 , T_2 V_159 )
{
int V_4 ;
struct V_78 * V_79 ;
F_17 ( V_28 , 4 , L_50 ) ;
V_79 = F_73 ( V_28 , V_158 , V_159 ,
0 , V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_74 ( V_28 , V_79 , 0 , 0 ,
F_72 , NULL ) ;
return V_4 ;
}
static int F_77 ( struct V_27 * V_28 ,
enum V_157 V_158 , T_2 V_159 , long V_83 )
{
int V_4 ;
int V_161 = 0 ;
struct V_78 * V_79 ;
F_17 ( V_28 , 4 , L_51 ) ;
if ( V_83 )
V_161 = sizeof( V_164 ) ;
V_79 = F_73 ( V_28 , V_158 , V_159 ,
V_161 , V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_74 ( V_28 , V_79 , V_161 , V_83 ,
F_72 , NULL ) ;
return V_4 ;
}
static int F_78 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_52 ) ;
if ( ! F_54 ( V_28 , V_165 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_53 ,
F_51 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_77 ( V_28 , V_165 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_54 ,
F_51 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_79 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_55 ) ;
if ( ! F_54 ( V_28 , V_166 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_56 ,
F_51 ( V_28 ) ) ;
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_166 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_57 ,
F_51 ( V_28 ) ) ;
} else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_58 ) ;
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_59 ) ;
if ( ! F_54 ( V_28 , V_168 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_60 ,
F_51 ( V_28 ) ) ;
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_168 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 ,
L_61 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_62 ) ;
if ( ! F_54 ( V_28 , V_169 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_63 , F_51 ( V_28 ) ) ;
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_170 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_64 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_65 ) ;
}
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_66 ) ;
if ( ! F_54 ( V_28 , V_171 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_67 ,
F_51 ( V_28 ) ) ;
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_171 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_68 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_69 ) ;
V_28 -> V_122 -> V_58 |= V_172 ;
}
return V_4 ;
}
static int F_83 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_70 ) ;
if ( V_28 -> V_97 . type == V_98 )
goto V_14;
V_4 = F_84 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_85 ( & V_28 -> V_121 -> V_122 ,
L_71 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_77 ( V_28 , V_108 ,
V_152 , 3 ) ;
if ( V_4 ) {
F_85 ( & V_28 -> V_121 -> V_122 ,
L_71 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_76 ( V_28 , V_108 ,
V_152 ) ;
if ( V_4 ) {
F_85 ( & V_28 -> V_121 -> V_122 ,
L_71 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_76 ( V_28 , V_173 ,
V_152 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_72 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_67 ( & V_28 -> V_121 -> V_122 , L_73 ) ;
return 0 ;
}
static int F_86 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_74 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_75 , F_51 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_53
V_4 = F_83 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_87 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_76 ) ;
V_28 -> V_97 . V_174 = 0 ;
if ( ! F_54 ( V_28 , V_175 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_77 ,
F_51 ( V_28 ) ) ;
V_4 = - V_167 ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_175 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_78
L_79 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_175 ,
V_176 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_80 ,
F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_174 = V_177 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_81 ) ;
V_4 = F_77 ( V_28 , V_175 ,
V_178 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_82
L_83 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_174 = V_179 ;
V_14:
if ( V_28 -> V_97 . V_174 )
V_28 -> V_122 -> V_58 |= V_180 ;
else
V_28 -> V_122 -> V_58 &= ~ V_180 ;
return V_4 ;
}
static int F_88 ( struct V_27 * V_28 )
{
int V_4 ;
V_4 = F_77 ( V_28 , V_150 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_84
L_85 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_77 ( V_28 , V_150 ,
V_178 ,
V_28 -> V_97 . V_153 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_86
L_85 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
return 0 ;
}
static int F_89 ( struct V_27 * V_28 , int V_181 )
{
int V_4 = 0 ;
if ( V_181 ) {
V_4 = F_88 ( V_28 ) ;
if ( V_4 )
return - V_182 ;
F_67 ( & V_28 -> V_121 -> V_122 ,
L_87 ) ;
} else {
V_4 = F_77 ( V_28 ,
V_150 , V_183 , 0 ) ;
if ( V_4 )
return - V_182 ;
}
return 0 ;
}
static int F_90 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_88 ) ;
if ( V_28 -> V_122 -> V_184 & V_185 ) {
F_91 () ;
V_28 -> V_122 -> V_184 &= ~ V_185 ;
F_92 ( V_28 -> V_122 ) ;
F_93 () ;
}
return 0 ;
}
static int F_94 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
if ( ! F_54 ( V_28 , V_155 ) )
return V_4 ;
V_4 = F_77 ( V_28 , V_155 ,
V_152 , 0 ) ;
if ( V_4 )
goto V_186;
V_4 = F_77 ( V_28 , V_155 ,
V_178 , V_28 -> V_97 . V_156 ) ;
if ( V_4 )
goto V_186;
F_67 ( & V_28 -> V_121 -> V_122 , L_89 ) ;
return V_4 ;
V_186:
F_62 ( & V_28 -> V_121 -> V_122 , L_90
L_91 , F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_95 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_92 ) ;
if ( ! F_54 ( V_28 , V_187 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_93 ,
F_51 ( V_28 ) ) ;
V_4 = - V_167 ;
} else {
V_4 = F_77 ( V_28 , V_187 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_94
L_95 ,
F_51 ( V_28 ) ) ;
else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_96 ) ;
}
if ( V_4 )
V_28 -> V_122 -> V_184 &= ~ V_188 ;
return V_4 ;
}
static int F_96 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_97 ) ;
if ( F_97 ( V_28 , 0 ) )
return - V_182 ;
F_78 ( V_28 ) ;
F_79 ( V_28 ) ;
F_80 ( V_28 ) ;
F_81 ( V_28 ) ;
F_82 ( V_28 ) ;
F_86 ( V_28 ) ;
F_87 ( V_28 ) ;
F_90 ( V_28 ) ;
F_94 ( V_28 ) ;
F_95 ( V_28 ) ;
return 0 ;
}
static int F_98 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) V_83 ;
if ( V_81 -> V_141 . V_142 == 0 )
memcpy ( V_28 -> V_122 -> V_189 ,
V_81 -> V_83 . V_190 . V_191 , V_192 ) ;
else
F_99 ( V_28 -> V_122 -> V_189 ) ;
return 0 ;
}
static int F_100 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_98 ) ;
V_79 = F_41 ( V_28 , V_193 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_190 . V_191 [ 6 ] ) =
V_28 -> V_97 . V_191 ;
V_4 = F_42 ( V_28 , V_79 , F_98 ,
NULL ) ;
return V_4 ;
}
static int F_101 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) V_83 ;
if ( V_81 -> V_141 . V_142 == 0 )
V_28 -> V_97 . V_191 = * ( ( T_2 * )
& V_81 -> V_83 . V_190 . V_191 [ 6 ] ) ;
else {
V_28 -> V_97 . V_191 = V_194 |
V_195 ;
F_62 ( & V_28 -> V_121 -> V_122 , L_99
L_100 ) ;
}
return 0 ;
}
static int F_102 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_101 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
V_28 -> V_97 . V_191 = V_194 |
V_195 ;
return 0 ;
}
V_79 = F_41 ( V_28 , V_193 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_190 . V_191 [ 6 ] ) =
V_28 -> V_97 . V_191 ;
V_4 = F_42 ( V_28 , V_79 , F_101 , NULL ) ;
return V_4 ;
}
static int
F_103 ( struct V_27 * V_28 , struct V_139 * V_140 ,
unsigned long V_83 )
{
struct V_80 * V_81 ;
T_2 V_4 ;
F_66 ( V_136 , 2 , L_102 ) ;
V_81 = (struct V_80 * ) V_83 ;
V_4 = V_81 -> V_141 . V_142 ;
if ( V_4 )
F_45 ( V_28 , 2 , L_103 , V_4 ) ;
switch ( V_81 -> V_83 . V_196 . V_197 ) {
case V_198 :
break;
case V_199 :
switch ( V_4 ) {
case 0 :
case V_200 :
V_28 -> V_97 . V_201 = V_202 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_104
L_105 ) ;
break;
default:
break;
}
break;
case V_203 :
switch ( V_4 ) {
case 0 :
V_28 -> V_97 . V_201 = V_204 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_104
L_106 ) ;
break;
case V_205 :
F_62 ( & V_28 -> V_121 -> V_122 , L_107
L_108
L_109 ) ;
break;
case V_206 :
F_62 ( & V_28 -> V_121 -> V_122 , L_110
L_111
L_112 ) ;
break;
default:
break;
}
break;
default:
F_50 ( 2 , L_113 ,
V_81 -> V_83 . V_196 . V_197 , F_51 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_104 ( struct V_27 * V_28 , enum V_207 V_208 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_114 ) ;
V_79 = F_41 ( V_28 , V_209 , 0 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_196 . V_210 = 16 ;
V_81 -> V_83 . V_196 . V_211 = V_212 ;
V_81 -> V_83 . V_196 . type = V_213 ;
V_81 -> V_83 . V_196 . V_197 = V_208 ;
return F_42 ( V_28 , V_79 , F_103 , NULL ) ;
}
static void F_105 ( V_164 V_214 , char * V_86 ,
struct V_215 * V_122 )
{
F_106 ( V_214 , V_86 ) ;
}
static void F_107 ( struct V_27 * V_28 , struct V_216 * V_217 )
{
struct V_29 * V_214 ;
struct V_218 * V_219 ;
char V_1 [ V_220 ] ;
F_17 ( V_28 , 4 , L_115 ) ;
for ( V_219 = F_108 ( V_217 -> V_221 ) ; V_219 != NULL ;
V_219 = F_108 ( V_219 -> V_222 ) ) {
F_105 ( V_219 -> V_223 , V_1 , V_217 -> V_122 ) ;
V_214 = F_24 ( V_20 ) ;
if ( ! V_214 )
continue;
V_214 -> V_36 . V_47 . V_2 = V_219 -> V_223 ;
memcpy ( V_214 -> V_86 , V_1 , V_87 ) ;
V_214 -> V_46 = 1 ;
if ( ! F_23 ( V_28 , V_214 ) )
F_15 ( V_214 ) ;
}
}
static void F_109 ( struct V_27 * V_28 )
{
struct V_216 * V_224 ;
T_4 V_225 ;
F_17 ( V_28 , 4 , L_116 ) ;
if ( ! F_54 ( V_28 , V_169 ) )
return;
F_110 (vid, card->active_vlans, VLAN_N_VID) {
struct V_215 * V_226 ;
V_226 = F_111 ( V_28 -> V_122 , F_112 ( V_227 ) ,
V_225 ) ;
if ( V_226 == NULL ||
! ( V_226 -> V_58 & V_228 ) )
continue;
V_224 = F_113 ( V_226 ) ;
if ( ! V_224 )
continue;
F_107 ( V_28 , V_224 ) ;
}
}
static void F_114 ( struct V_27 * V_28 )
{
struct V_216 * V_217 ;
F_17 ( V_28 , 4 , L_117 ) ;
F_115 () ;
V_217 = F_113 ( V_28 -> V_122 ) ;
if ( V_217 == NULL )
goto V_229;
F_107 ( V_28 , V_217 ) ;
F_109 ( V_28 ) ;
V_229:
F_116 () ;
}
static void F_117 ( struct V_27 * V_28 , struct V_230 * V_231 )
{
struct V_29 * V_214 ;
struct V_232 * V_233 ;
char V_1 [ V_220 ] ;
F_17 ( V_28 , 4 , L_118 ) ;
for ( V_233 = V_231 -> V_221 ; V_233 != NULL ; V_233 = V_233 -> V_71 ) {
F_118 ( & V_233 -> V_234 , V_1 , V_231 -> V_122 , 0 ) ;
V_214 = F_24 ( V_21 ) ;
if ( ! V_214 )
continue;
V_214 -> V_46 = 1 ;
memcpy ( V_214 -> V_86 , V_1 , V_87 ) ;
memcpy ( & V_214 -> V_36 . V_49 . V_2 , & V_233 -> V_234 . V_235 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_214 ) )
F_15 ( V_214 ) ;
}
}
static void F_119 ( struct V_27 * V_28 )
{
struct V_230 * V_224 ;
T_4 V_225 ;
F_17 ( V_28 , 4 , L_119 ) ;
if ( ! F_54 ( V_28 , V_169 ) )
return;
F_110 (vid, card->active_vlans, VLAN_N_VID) {
struct V_215 * V_226 ;
V_226 = F_111 ( V_28 -> V_122 , F_112 ( V_227 ) ,
V_225 ) ;
if ( V_226 == NULL ||
! ( V_226 -> V_58 & V_228 ) )
continue;
V_224 = F_120 ( V_226 ) ;
if ( ! V_224 )
continue;
F_121 ( & V_224 -> V_236 ) ;
F_117 ( V_28 , V_224 ) ;
F_122 ( & V_224 -> V_236 ) ;
F_123 ( V_224 ) ;
}
}
static void F_124 ( struct V_27 * V_28 )
{
struct V_230 * V_231 ;
F_17 ( V_28 , 4 , L_120 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return ;
V_231 = F_120 ( V_28 -> V_122 ) ;
if ( V_231 == NULL )
return;
F_115 () ;
F_121 ( & V_231 -> V_236 ) ;
F_117 ( V_28 , V_231 ) ;
F_119 ( V_28 ) ;
F_122 ( & V_231 -> V_236 ) ;
F_116 () ;
F_123 ( V_231 ) ;
}
static void F_125 ( struct V_27 * V_28 ,
unsigned short V_225 )
{
struct V_216 * V_224 ;
struct V_237 * V_238 ;
struct V_29 * V_2 ;
struct V_215 * V_226 ;
F_17 ( V_28 , 4 , L_121 ) ;
V_226 = F_111 ( V_28 -> V_122 , F_112 ( V_227 ) , V_225 ) ;
if ( ! V_226 )
return;
V_224 = F_126 ( V_226 ) ;
if ( ! V_224 )
return;
for ( V_238 = V_224 -> V_239 ; V_238 ; V_238 = V_238 -> V_240 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_238 -> V_241 ;
V_2 -> V_36 . V_47 . V_48 = V_238 -> V_242 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_127 ( V_224 ) ;
}
static void F_128 ( struct V_27 * V_28 ,
unsigned short V_225 )
{
#ifdef F_53
struct V_230 * V_231 ;
struct V_243 * V_238 ;
struct V_29 * V_2 ;
struct V_215 * V_226 ;
F_17 ( V_28 , 4 , L_122 ) ;
V_226 = F_111 ( V_28 -> V_122 , F_112 ( V_227 ) , V_225 ) ;
if ( ! V_226 )
return;
V_231 = F_120 ( V_226 ) ;
if ( ! V_231 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_238 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_238 -> V_244 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_123 ( V_231 ) ;
#endif
}
static void F_129 ( struct V_27 * V_28 ,
unsigned short V_225 )
{
F_115 () ;
F_125 ( V_28 , V_225 ) ;
F_128 ( V_28 , V_225 ) ;
F_116 () ;
}
static int F_130 ( struct V_215 * V_122 ,
T_5 V_19 , T_4 V_225 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
F_131 ( V_225 , V_28 -> V_246 ) ;
return 0 ;
}
static int F_132 ( struct V_215 * V_122 ,
T_5 V_19 , T_4 V_225 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
unsigned long V_58 ;
F_45 ( V_28 , 4 , L_123 , V_225 ) ;
if ( F_133 ( V_28 , V_247 ) ) {
F_17 ( V_28 , 3 , L_124 ) ;
return 0 ;
}
F_21 ( & V_28 -> V_248 , V_58 ) ;
F_129 ( V_28 , V_225 ) ;
F_134 ( V_225 , V_28 -> V_246 ) ;
F_22 ( & V_28 -> V_248 , V_58 ) ;
F_135 ( V_28 -> V_122 ) ;
return 0 ;
}
static inline int F_136 ( struct V_27 * V_28 ,
struct V_249 * V_250 , struct V_251 * V_141 ,
unsigned short * V_252 )
{
T_5 V_60 ;
struct V_253 * V_254 ;
unsigned char V_255 [ V_220 ] ;
int V_256 = 0 ;
if ( ! ( V_141 -> V_141 . V_257 . V_58 & V_132 ) ) {
V_60 = F_112 ( ( V_141 -> V_141 . V_257 . V_58 & V_133 ) ? V_258 :
V_259 ) ;
switch ( V_141 -> V_141 . V_257 . V_58 & V_260 ) {
case V_127 :
switch ( V_60 ) {
#ifdef F_53
case F_137 ( V_258 ) :
F_118 ( (struct V_51 * )
V_250 -> V_83 + 24 ,
V_255 , V_28 -> V_122 , 0 ) ;
break;
#endif
case F_137 ( V_259 ) :
V_254 = (struct V_253 * ) V_250 -> V_83 ;
F_106 ( V_254 -> V_261 , V_255 ) ;
break;
default:
memcpy ( V_255 , V_28 -> V_122 -> V_262 ,
V_28 -> V_122 -> V_263 ) ;
}
V_28 -> V_264 . V_265 ++ ;
V_250 -> V_266 = V_267 ;
break;
case V_129 :
memcpy ( V_255 , V_28 -> V_122 -> V_262 ,
V_28 -> V_122 -> V_263 ) ;
V_28 -> V_264 . V_265 ++ ;
V_250 -> V_266 = V_268 ;
break;
case V_130 :
case V_135 :
case V_269 :
default:
if ( V_28 -> V_43 . V_44 )
V_250 -> V_266 = V_270 ;
else
V_250 -> V_266 = V_271 ;
memcpy ( V_255 , V_28 -> V_122 -> V_189 ,
V_28 -> V_122 -> V_263 ) ;
}
if ( V_141 -> V_141 . V_257 . V_272 & V_273 )
V_28 -> V_122 -> V_274 -> V_275 ( V_250 , V_28 -> V_122 , V_60 ,
V_255 , & V_141 -> V_141 . V_257 . V_276 [ 2 ] ,
V_28 -> V_122 -> V_263 ) ;
else
V_28 -> V_122 -> V_274 -> V_275 ( V_250 , V_28 -> V_122 , V_60 ,
V_255 , L_125 , V_28 -> V_122 -> V_263 ) ;
}
V_250 -> V_277 = F_138 ( V_250 , V_28 -> V_122 ) ;
if ( V_141 -> V_141 . V_257 . V_272 &
( V_278 | V_279 ) ) {
* V_252 = ( V_141 -> V_141 . V_257 . V_272 & V_278 ) ?
V_141 -> V_141 . V_257 . V_252 : * ( ( T_4 * ) & V_141 -> V_141 . V_257 . V_276 [ 12 ] ) ;
V_256 = 1 ;
}
if ( V_28 -> V_122 -> V_184 & V_185 ) {
if ( ( V_141 -> V_141 . V_257 . V_272 &
( V_280 |
V_281 ) ) ==
( V_280 |
V_281 ) )
V_250 -> V_282 = V_283 ;
else
V_250 -> V_282 = V_284 ;
} else
V_250 -> V_282 = V_284 ;
return V_256 ;
}
static int F_139 ( struct V_27 * V_28 ,
int V_285 , int * V_286 )
{
int V_287 = 0 ;
struct V_249 * V_250 ;
struct V_251 * V_141 ;
T_2 V_288 = 0 ;
int V_256 ;
unsigned int V_23 ;
T_2 V_289 ;
* V_286 = 0 ;
F_140 ( ! V_285 ) ;
while ( V_285 ) {
V_250 = F_141 ( V_28 ,
& V_28 -> V_290 . V_291 -> V_292 [ V_28 -> V_293 . V_294 ] ,
& V_28 -> V_293 . V_295 , & V_28 -> V_293 . V_296 , & V_141 ) ;
if ( ! V_250 ) {
* V_286 = 1 ;
break;
}
V_250 -> V_122 = V_28 -> V_122 ;
switch ( V_141 -> V_141 . V_257 . V_297 ) {
case V_298 :
V_289 = * ( T_2 * ) V_250 -> V_83 ;
if ( ( V_28 -> V_97 . type == V_98 ) &&
( V_289 == V_299 ) ) {
V_250 -> V_277 = V_299 ;
V_250 -> V_266 = V_271 ;
V_250 -> V_300 = V_301 ;
V_250 -> V_122 = V_28 -> V_122 ;
V_23 = V_250 -> V_23 ;
V_28 -> V_122 -> V_274 -> V_275 ( V_250 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_189 , L_125 ,
V_28 -> V_122 -> V_263 ) ;
F_142 ( V_250 ) ;
} else {
V_256 = F_136 ( V_28 , V_250 , V_141 ,
& V_288 ) ;
V_23 = V_250 -> V_23 ;
if ( V_256 && ! V_28 -> V_43 . V_44 )
F_143 ( V_250 ,
F_112 ( V_227 ) , V_288 ) ;
F_144 ( & V_28 -> V_302 , V_250 ) ;
}
break;
case V_303 :
V_250 -> V_266 = V_271 ;
V_250 -> V_277 = F_138 ( V_250 , V_250 -> V_122 ) ;
V_23 = V_250 -> V_23 ;
F_142 ( V_250 ) ;
break;
default:
F_145 ( V_250 ) ;
F_17 ( V_28 , 3 , L_126 ) ;
F_146 ( V_304 , 3 , V_141 , V_305 ) ;
continue;
}
V_287 ++ ;
V_285 -- ;
V_28 -> V_264 . V_306 ++ ;
V_28 -> V_264 . V_307 += V_23 ;
}
return V_287 ;
}
static int F_147 ( struct V_308 * V_302 , int V_285 )
{
struct V_27 * V_28 = F_148 ( V_302 , struct V_27 , V_302 ) ;
int V_287 = 0 ;
struct V_309 * V_310 ;
int V_286 ;
int V_311 = V_285 ;
if ( V_28 -> V_43 . V_312 ) {
V_28 -> V_313 . V_314 ++ ;
V_28 -> V_313 . V_315 = F_149 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_293 . V_316 ) {
V_28 -> V_293 . V_317 = 0 ;
V_28 -> V_293 . V_316 = F_150 (
V_28 -> V_83 . V_318 , 0 , & V_28 -> V_293 . V_294 ,
& V_28 -> V_293 . V_317 ) ;
if ( V_28 -> V_293 . V_316 <= 0 ) {
V_28 -> V_293 . V_316 = 0 ;
break;
}
V_28 -> V_293 . V_295 =
& V_28 -> V_290 . V_291 -> V_292 [ V_28 -> V_293 . V_294 ]
. V_310 -> V_319 [ 0 ] ;
V_28 -> V_293 . V_296 = 0 ;
}
while ( V_28 -> V_293 . V_316 ) {
V_310 = & V_28 -> V_290 . V_291 -> V_292 [ V_28 -> V_293 . V_294 ] ;
if ( ! ( V_28 -> V_293 . V_317 &&
F_151 ( V_28 , V_310 -> V_310 ,
V_28 -> V_293 . V_317 , L_127 ) ) )
V_287 += F_139 (
V_28 , V_311 , & V_286 ) ;
else
V_286 = 1 ;
if ( V_286 ) {
if ( V_28 -> V_43 . V_312 )
V_28 -> V_313 . V_320 ++ ;
F_152 ( V_28 ,
V_310 -> V_321 ) ;
F_153 ( V_28 , V_28 -> V_293 . V_294 ) ;
V_28 -> V_293 . V_316 -- ;
if ( V_28 -> V_293 . V_316 ) {
V_28 -> V_293 . V_294 =
( V_28 -> V_293 . V_294 + 1 ) %
V_322 ;
V_28 -> V_293 . V_295 =
& V_28 -> V_290 . V_291
-> V_292 [ V_28 -> V_293 . V_294 ]
. V_310 -> V_319 [ 0 ] ;
V_28 -> V_293 . V_296 = 0 ;
}
}
if ( V_287 >= V_285 )
goto V_14;
else
V_311 = V_285 - V_287 ;
}
}
F_154 ( V_302 ) ;
if ( F_155 ( V_28 -> V_83 . V_318 , 0 ) )
F_156 ( & V_28 -> V_302 ) ;
V_14:
if ( V_28 -> V_43 . V_312 )
V_28 -> V_313 . V_323 += F_149 () -
V_28 -> V_313 . V_315 ;
return V_287 ;
}
static int F_157 ( struct V_215 * V_122 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_4 V_225 ;
F_110 (vid, card->active_vlans, VLAN_N_VID) {
struct V_215 * V_226 ;
F_115 () ;
V_226 = F_111 ( V_28 -> V_122 , F_112 ( V_227 ) ,
V_225 ) ;
F_116 () ;
if ( V_226 == V_122 ) {
V_4 = V_324 ;
break;
}
}
if ( V_4 && ! ( F_158 ( V_122 ) -> V_245 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_159 ( struct V_215 * V_122 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_160 ( & V_325 . V_326 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_122 == V_122 ) {
V_4 = V_327 ;
break;
}
V_4 = F_157 ( V_122 , V_28 ) ;
if ( V_4 )
break;
}
F_161 ( & V_325 . V_326 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_162 ( struct V_215 * V_122 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_159 ( V_122 ) ;
if ( V_4 == V_327 )
V_28 = V_122 -> V_245 ;
else if ( V_4 == V_324 )
V_28 = F_158 ( V_122 ) -> V_245 ;
if ( V_28 && V_28 -> V_43 . V_328 )
V_28 = NULL ;
if ( V_28 )
F_45 ( V_28 , 4 , L_128 , V_4 ) ;
return V_28 ;
}
static int F_163 ( struct V_27 * V_28 , int V_329 )
{
int V_4 = 0 ;
F_66 ( V_136 , 2 , L_129 ) ;
F_146 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
F_164 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_97 . V_201 == V_204 ) )
F_104 ( V_28 , V_199 ) ;
if ( V_28 -> V_330 . V_331 == V_332 &&
V_28 -> V_333 . V_331 == V_332 &&
( V_28 -> V_331 == V_334 ) ) {
if ( V_329 )
F_165 ( V_28 -> V_122 ) ;
else {
F_91 () ;
F_166 ( V_28 -> V_122 ) ;
F_93 () ;
}
V_28 -> V_331 = V_335 ;
}
if ( V_28 -> V_331 == V_335 ) {
F_38 ( V_28 , 1 ) ;
F_167 ( V_28 ) ;
V_28 -> V_331 = V_336 ;
}
if ( V_28 -> V_331 == V_336 ) {
F_168 ( V_28 , 0 ) ;
F_169 ( V_28 ) ;
F_170 ( V_28 ) ;
V_28 -> V_331 = V_337 ;
}
if ( V_28 -> V_331 == V_337 ) {
F_171 ( & V_28 -> V_330 ) ;
F_171 ( & V_28 -> V_333 ) ;
}
return V_4 ;
}
static void
F_172 ( struct V_27 * V_28 )
{
struct V_215 * V_122 = V_28 -> V_122 ;
if ( ( ( V_122 -> V_58 & V_338 ) &&
( V_28 -> V_97 . V_201 == V_204 ) ) ||
( ! ( V_122 -> V_58 & V_338 ) &&
( V_28 -> V_97 . V_201 == V_202 ) ) )
return;
if ( V_28 -> V_97 . V_339 ) {
if ( F_70 ( V_28 , V_340 ) )
F_173 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_70 ( V_28 , V_341 ) ) {
if ( V_122 -> V_58 & V_338 ) {
F_17 ( V_28 , 3 , L_130 ) ;
F_104 ( V_28 , V_203 ) ;
} else {
F_17 ( V_28 , 3 , L_131 ) ;
F_104 ( V_28 , V_199 ) ;
}
}
}
static void F_135 ( struct V_215 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
F_17 ( V_28 , 3 , L_132 ) ;
if ( F_174 ( V_28 , V_247 ) &&
( V_28 -> V_331 != V_334 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_114 ( V_28 ) ;
#ifdef F_53
F_124 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_70 ( V_28 , V_340 ) )
return;
}
F_172 ( V_28 ) ;
}
static const char * F_175 ( int * V_4 )
{
switch ( * V_4 ) {
case V_342 :
* V_4 = - V_182 ;
return L_133 ;
case V_343 :
* V_4 = - V_167 ;
return L_134 ;
case V_344 :
* V_4 = - V_7 ;
return L_135 ;
case V_345 :
* V_4 = - V_167 ;
return L_136 ;
case V_346 :
* V_4 = - V_347 ;
return L_137 ;
default:
return L_138 ;
}
}
static int F_176 ( struct V_27 * V_28 , int V_348 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_139 ) ;
if ( V_28 -> V_97 . V_339 )
return - V_167 ;
if ( ! F_54 ( V_28 , V_165 ) ) {
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_165 ,
V_349 ,
V_348 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_140
L_141 , F_51 ( V_28 ) ,
F_175 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static V_164 F_177 ( struct V_27 * V_28 ,
struct V_350 * V_351 ,
struct V_352 * type , T_1 V_353 )
{
V_164 V_4 ;
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
static int F_178 ( struct V_352 * type , T_2 V_60 )
{
return ( type -> V_356 == V_357 && V_60 == V_20 ) ||
( type -> V_356 == V_362 && V_60 == V_21 ) ;
}
static int F_179 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
struct V_350 * V_351 ;
struct V_367 * V_368 ;
int V_24 ;
int V_369 ;
int V_370 ;
int V_371 ;
T_1 V_372 ;
F_17 ( V_28 , 3 , L_145 ) ;
V_368 = (struct V_367 * ) V_140 -> V_373 ;
V_81 = (struct V_80 * ) V_83 ;
F_45 ( V_28 , 4 , L_146 , V_81 -> V_141 . V_144 ) ;
if ( V_81 -> V_141 . V_142 ) {
F_17 ( V_28 , 4 , L_147 ) ;
F_45 ( V_28 , 4 , L_146 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_142 ) {
V_81 -> V_141 . V_142 = V_81 -> V_83 . V_143 . V_141 . V_142 ;
F_17 ( V_28 , 4 , L_148 ) ;
F_45 ( V_28 , 4 , L_146 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
V_351 = & V_81 -> V_83 . V_143 . V_83 . V_374 ;
F_45 ( V_28 , 4 , L_149 , V_351 -> V_348 ) ;
V_372 = ( V_368 -> V_37 & V_375 ) > 0 ;
V_371 = V_372 ? V_376 : 0 ;
V_370 = 0 ;
for ( V_369 = 0 ; V_369 < V_351 -> V_348 ; ++ V_369 ) {
char * V_377 ;
V_164 V_378 ;
struct V_352 * V_379 ;
V_377 = & V_351 -> V_83 + V_370 ;
V_379 = & ( (struct V_360 * ) V_377 ) -> type ;
if ( ! F_178 ( V_379 , V_81 -> V_141 . V_144 ) ) {
F_17 ( V_28 , 4 , L_150 ) ;
F_45 ( V_28 , 4 , L_146 , V_379 -> V_356 ) ;
break;
}
V_378 = F_177 ( V_28 , V_351 , V_379 ,
V_372 ) ;
F_45 ( V_28 , 5 , L_151 , V_378 ) ;
if ( ! V_378 )
break;
if ( ( V_368 -> V_380 - V_368 -> V_381 ) < V_378 ) {
F_45 ( V_28 , 4 , L_152 , - V_82 ) ;
V_81 -> V_141 . V_142 = V_382 ;
goto V_383;
}
memcpy ( V_368 -> V_384 + V_368 -> V_381 ,
& V_351 -> V_83 + V_370 + V_371 ,
V_378 ) ;
V_370 += V_378 + V_371 ;
V_368 -> V_381 += V_378 ;
++ V_368 -> V_348 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_162 <
V_81 -> V_83 . V_143 . V_141 . V_385 )
return 1 ;
F_45 ( V_28 , 4 , L_153 , V_368 -> V_348 ) ;
memcpy ( V_368 -> V_384 , & V_368 -> V_348 , 4 ) ;
if ( V_368 -> V_37 & V_375 )
V_351 -> V_355 |= V_375 ;
memcpy ( V_368 -> V_384 + V_386 , & V_351 -> V_355 , 2 ) ;
F_45 ( V_28 , 4 , L_154 , 0 ) ;
return 0 ;
V_383:
V_24 = 0 ;
memcpy ( V_368 -> V_384 , & V_24 , 4 ) ;
return 0 ;
}
static int F_180 ( struct V_27 * V_28 ,
struct V_78 * V_79 , int V_23 ,
int (* F_75)( struct V_27 * , struct V_139 * ,
unsigned long ) ,
void * V_163 )
{
F_17 ( V_28 , 4 , L_155 ) ;
memcpy ( V_79 -> V_83 , V_387 , V_84 ) ;
memcpy ( F_181 ( V_79 -> V_83 ) ,
& V_28 -> V_388 . V_389 , V_390 ) ;
return F_182 ( V_28 , V_84 + V_23 , V_79 ,
F_75 , V_163 ) ;
}
static int F_183 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_367 * V_368 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_41 ;
int V_4 ;
F_45 ( V_28 , 3 , L_156 , V_60 ) ;
V_79 = F_73 ( V_28 , V_165 ,
V_391 ,
sizeof( struct V_350 ) - sizeof( char ) ,
V_60 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_143 . V_83 . V_374 . V_392 = 0x000F ;
V_81 -> V_83 . V_143 . V_83 . V_374 . V_355 = 0 ;
V_81 -> V_83 . V_143 . V_83 . V_374 . V_348 = 0 ;
V_4 = F_180 ( V_28 , V_79 ,
V_393 + V_394 ,
F_179 , ( void * ) V_368 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 ,
L_157
L_158 , F_51 ( V_28 ) ,
F_175 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_184 ( struct V_27 * V_28 , char T_6 * V_384 )
{
struct V_367 V_368 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_159 ) ;
if ( ! F_54 ( V_28 ,
V_165 ) ) {
F_17 ( V_28 , 3 , L_160 ) ;
V_4 = - V_167 ;
goto V_14;
}
if ( F_185 ( & V_368 , V_384 , 6 ) ) {
V_4 = - V_395 ;
goto V_14;
}
V_368 . V_384 = F_25 ( V_368 . V_380 , V_396 ) ;
if ( ! V_368 . V_384 ) {
V_4 = - V_82 ;
goto V_14;
}
V_368 . V_381 = V_397 ;
V_4 = F_183 ( V_28 , V_20 , & V_368 ) ;
if ( V_4 ) {
if ( F_186 ( V_384 , V_368 . V_384 , 4 ) )
V_4 = - V_395 ;
goto V_398;
} else {
#ifdef F_53
if ( V_368 . V_37 & V_399 ) {
F_183 ( V_28 , V_21 ,
& V_368 ) ;
}
#endif
if ( F_186 ( V_384 , V_368 . V_384 , V_368 . V_380 ) ) {
F_17 ( V_28 , 4 , L_161 ) ;
V_4 = - V_395 ;
goto V_398;
}
F_17 ( V_28 , 4 , L_162 ) ;
}
V_398:
F_15 ( V_368 . V_384 ) ;
V_14:
return V_4 ;
}
static int F_187 ( struct V_27 * V_28 ,
struct V_400 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_163 ) ;
if ( V_28 -> V_97 . V_339 )
return - V_167 ;
if ( ! F_54 ( V_28 , V_165 ) ) {
return - V_167 ;
}
V_79 = F_73 ( V_28 , V_165 ,
V_401 ,
sizeof( struct V_400 ) ,
V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_74 ( V_28 , V_79 ,
sizeof( struct V_400 ) ,
( unsigned long ) V_53 ,
F_72 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_113 , V_1 ) ;
F_50 ( 2 , L_164
L_165 , V_1 , F_51 ( V_28 ) ,
F_175 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_188 ( struct V_27 * V_28 ,
struct V_400 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_166 ) ;
if ( V_28 -> V_97 . V_339 )
return - V_167 ;
if ( ! F_54 ( V_28 , V_165 ) ) {
return - V_167 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_79 = F_73 ( V_28 , V_165 ,
V_402 ,
12 ,
V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_74 ( V_28 , V_79 ,
12 , ( unsigned long ) V_1 ,
F_72 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_53 -> V_113 , V_1 ) ;
F_50 ( 2 , L_167
L_168 , V_1 , F_51 ( V_28 ) ,
F_175 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_189 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_169 ) ;
if ( V_28 -> V_97 . V_339 || ( V_28 -> V_97 . type == V_98 ) )
return - V_167 ;
if ( ! F_54 ( V_28 , V_165 ) ) {
return - V_167 ;
}
V_4 = F_77 ( V_28 , V_165 ,
V_403 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_170
L_158 , F_51 ( V_28 ) ,
F_175 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_190 ( struct V_215 * V_122 , struct V_404 * V_405 , int V_81 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
struct V_400 V_406 ;
struct V_407 * V_408 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_409 ;
if ( ! F_33 ( V_28 ) )
return - V_409 ;
switch ( V_81 ) {
case V_410 :
if ( ! F_191 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_176 ( V_28 , V_405 -> V_413 . V_414 ) ;
break;
case V_415 :
if ( ! F_191 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_184 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
case V_417 :
if ( ! F_191 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
if ( F_185 ( & V_406 , V_405 -> V_413 . V_416 ,
sizeof( struct V_400 ) ) )
V_4 = - V_395 ;
else
V_4 = F_187 ( V_28 , & V_406 ) ;
break;
case V_418 :
if ( ! F_191 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
if ( F_185 ( & V_406 , V_405 -> V_413 . V_416 ,
sizeof( struct V_400 ) ) )
V_4 = - V_395 ;
else
V_4 = F_188 ( V_28 , & V_406 ) ;
break;
case V_419 :
if ( ! F_191 ( V_411 ) ) {
V_4 = - V_412 ;
break;
}
V_4 = F_189 ( V_28 ) ;
break;
case V_420 :
V_4 = F_192 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
case V_421 :
if ( ( V_28 -> V_97 . type == V_422 ||
V_28 -> V_97 . type == V_423 ) &&
! V_28 -> V_97 . V_339 )
return 1 ;
return 0 ;
break;
case V_424 :
V_408 = F_193 ( V_405 ) ;
V_408 -> V_425 = 0 ;
break;
case V_426 :
V_408 = F_193 ( V_405 ) ;
if ( V_408 -> V_425 != 0 )
V_4 = - V_7 ;
else
V_408 -> V_427 = F_194 ( V_122 ,
V_408 -> V_425 ,
V_408 -> V_428 ) ;
break;
case V_429 :
V_4 = F_195 ( V_28 , V_405 -> V_413 . V_416 ) ;
break;
default:
V_4 = - V_167 ;
}
if ( V_4 )
F_45 ( V_28 , 2 , L_171 , V_4 ) ;
return V_4 ;
}
int inline F_196 ( struct V_27 * V_28 , struct V_249 * V_250 )
{
int V_125 = V_430 ;
struct V_431 * V_432 = NULL ;
struct V_433 * V_434 ;
F_115 () ;
V_434 = F_197 ( V_250 ) ;
if ( V_434 )
V_432 = F_198 ( V_434 , V_250 ) ;
if ( V_432 ) {
V_125 = V_432 -> type ;
F_116 () ;
F_199 ( V_432 ) ;
if ( ( V_125 == V_128 ) ||
( V_125 == V_126 ) ||
( V_125 == V_134 ) )
return V_125 ;
else
return V_430 ;
}
F_116 () ;
if ( V_250 -> V_277 == V_258 )
return ( F_200 ( V_250 ) [ 24 ] == 0xff ) ?
V_126 : 0 ;
else if ( V_250 -> V_277 == V_259 )
return ( ( F_200 ( V_250 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_126 : 0 ;
if ( ! memcmp ( V_250 -> V_83 , V_250 -> V_122 -> V_262 , 6 ) )
return V_128 ;
else {
T_4 V_435 ;
V_435 = * ( ( T_4 * ) V_250 -> V_83 ) ;
switch ( V_28 -> V_97 . V_436 ) {
case V_437 :
case V_438 :
if ( ( V_435 == V_439 ) ||
( V_435 == V_440 ) )
return V_126 ;
break;
default:
if ( ( V_435 == V_441 ) ||
( V_435 == V_442 ) )
return V_126 ;
}
}
return V_125 ;
}
static void F_201 ( struct V_27 * V_28 ,
struct V_251 * V_141 , struct V_249 * V_250 )
{
char V_261 [ 16 ] ;
struct V_443 * V_444 ;
F_202 ( V_250 , 14 ) ;
V_28 -> V_122 -> V_274 -> V_275 ( V_250 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_189 , V_28 -> V_122 -> V_189 ,
V_28 -> V_122 -> V_263 ) ;
F_202 ( V_250 , 14 ) ;
V_444 = (struct V_443 * ) V_250 -> V_83 ;
memset ( V_141 , 0 , sizeof( struct V_251 ) ) ;
V_141 -> V_141 . V_257 . V_297 = V_298 ;
V_141 -> V_141 . V_257 . V_272 = 0 ;
V_141 -> V_141 . V_257 . V_161 = V_250 -> V_23 ;
V_141 -> V_141 . V_257 . V_58 = V_133 | V_130 ;
memset ( V_261 , 0 , sizeof( V_261 ) ) ;
V_261 [ 0 ] = 0xfe ;
V_261 [ 1 ] = 0x80 ;
memcpy ( & V_261 [ 8 ] , V_444 -> V_445 , 8 ) ;
memcpy ( V_141 -> V_141 . V_257 . V_276 , V_261 , 16 ) ;
}
static void F_203 ( struct V_27 * V_28 , struct V_251 * V_141 ,
struct V_249 * V_250 , int V_446 , int V_125 )
{
struct V_433 * V_434 ;
memset ( V_141 , 0 , sizeof( struct V_251 ) ) ;
V_141 -> V_141 . V_257 . V_297 = V_298 ;
V_141 -> V_141 . V_257 . V_272 = 0 ;
if ( F_204 ( V_250 ) ) {
if ( ( V_446 == 4 ) || ( V_28 -> V_97 . type == V_98 ) )
V_141 -> V_141 . V_257 . V_272 = V_278 ;
else
V_141 -> V_141 . V_257 . V_272 = V_279 ;
V_141 -> V_141 . V_257 . V_252 = F_205 ( V_250 ) ;
}
V_141 -> V_141 . V_257 . V_161 = V_250 -> V_23 - sizeof( struct V_251 ) ;
F_115 () ;
V_434 = F_197 ( V_250 ) ;
if ( V_446 == 4 ) {
struct V_447 * V_448 = (struct V_447 * ) V_434 ;
T_7 * V_449 = & V_254 ( V_250 ) -> V_261 ;
if ( V_448 -> V_450 )
V_449 = & V_448 -> V_450 ;
V_141 -> V_141 . V_257 . V_58 = F_63 ( V_125 ) ;
memset ( V_141 -> V_141 . V_257 . V_276 , 0 , 12 ) ;
* ( ( T_7 * ) ( & V_141 -> V_141 . V_257 . V_276 [ 12 ] ) ) = * V_449 ;
} else if ( V_446 == 6 ) {
struct V_451 * V_448 = (struct V_451 * ) V_434 ;
struct V_51 * V_449 = & F_206 ( V_250 ) -> V_261 ;
if ( ! F_207 ( & V_448 -> V_452 ) )
V_449 = & V_448 -> V_452 ;
V_141 -> V_141 . V_257 . V_58 = F_64 ( V_125 ) ;
if ( V_28 -> V_97 . type == V_98 )
V_141 -> V_141 . V_257 . V_58 &= ~ V_132 ;
memcpy ( V_141 -> V_141 . V_257 . V_276 , V_449 , 16 ) ;
} else {
if ( ! memcmp ( V_250 -> V_83 + sizeof( struct V_251 ) ,
V_250 -> V_122 -> V_262 , 6 ) ) {
V_141 -> V_141 . V_257 . V_58 = V_129 |
V_132 ;
} else {
V_141 -> V_141 . V_257 . V_58 = ( V_125 == V_126 ) ?
V_127 | V_132 :
V_130 | V_132 ;
}
}
F_116 () ;
}
static inline void F_208 ( struct V_27 * V_28 ,
struct V_251 * V_141 , struct V_249 * V_250 )
{
struct V_253 * V_453 = V_254 ( V_250 ) ;
if ( V_453 -> V_277 == V_454 )
V_141 -> V_141 . V_257 . V_272 |= V_455 ;
V_141 -> V_141 . V_257 . V_272 |= V_281 |
V_280 ;
V_453 -> V_456 = 0 ;
if ( V_28 -> V_43 . V_312 )
V_28 -> V_313 . V_457 ++ ;
}
static void F_209 ( struct V_27 * V_28 ,
struct V_251 * V_458 , struct V_249 * V_250 )
{
struct V_459 * V_141 = (struct V_459 * ) V_458 ;
struct V_460 * V_461 = F_210 ( V_250 ) ;
struct V_253 * V_453 = V_254 ( V_250 ) ;
struct V_462 * V_463 = F_206 ( V_250 ) ;
V_141 -> V_141 . V_141 . V_257 . V_297 = V_464 ;
V_141 -> V_141 . V_141 . V_257 . V_161 = V_250 -> V_23 - sizeof( struct V_459 ) ;
V_141 -> V_465 . V_466 = ( T_2 ) sizeof( struct V_467 ) ;
V_141 -> V_465 . V_468 = 1 ;
V_141 -> V_465 . V_469 = 1 ;
V_141 -> V_465 . V_470 = 1 ;
V_141 -> V_465 . V_471 = 28 ;
V_141 -> V_465 . V_472 = F_211 ( V_250 ) -> V_473 ;
V_141 -> V_465 . V_474 = ( T_2 ) ( V_453 -> V_475 * 4 + V_461 -> V_476 * 4 ) ;
V_141 -> V_465 . V_477 = ( T_2 ) ( V_250 -> V_23 - V_141 -> V_465 . V_474 -
sizeof( struct V_459 ) ) ;
V_461 -> V_456 = 0 ;
if ( V_250 -> V_277 == V_258 ) {
V_463 -> V_477 = 0 ;
V_461 -> V_456 = ~ F_212 ( & V_463 -> V_478 , & V_463 -> V_261 ,
0 , V_479 , 0 ) ;
} else {
V_461 -> V_456 = ~ F_213 ( V_453 -> V_478 , V_453 -> V_261 ,
0 , V_479 , 0 ) ;
V_453 -> V_480 = 0 ;
V_453 -> V_456 = 0 ;
}
}
static inline int F_214 ( struct V_249 * V_250 )
{
unsigned long V_481 = ( unsigned long ) F_210 ( V_250 ) +
F_210 ( V_250 ) -> V_476 * 4 ;
int V_482 = V_250 -> V_23 - ( V_481 - ( unsigned long ) V_250 -> V_83 ) ;
int V_483 = F_215 ( V_481 + V_482 - 1 ) - F_216 ( V_481 ) ;
V_483 += F_217 ( V_250 ) ;
return V_483 ;
}
static int F_218 ( struct V_249 * V_250 , struct V_215 * V_122 )
{
int V_4 ;
T_4 * V_484 ;
struct V_251 * V_141 = NULL ;
int V_485 = 0 ;
int V_486 ;
struct V_27 * V_28 = V_122 -> V_245 ;
struct V_249 * V_487 = NULL ;
int V_446 = F_219 ( V_250 ) ;
int V_125 = F_196 ( V_28 , V_250 ) ;
struct V_488 * V_489 =
V_28 -> V_290 . V_490 [ V_28 -> V_290 . V_491
|| ( V_125 && V_28 -> V_97 . V_492 ) ?
F_220 ( V_28 , V_250 , V_446 , V_125 ) :
V_28 -> V_290 . V_493 ] ;
int V_494 = V_250 -> V_23 ;
bool V_495 ;
int V_496 = - 1 ;
int V_497 ;
if ( ( ( V_28 -> V_97 . type == V_98 ) &&
( ( ( V_28 -> V_43 . V_498 != V_499 ) && ! V_446 ) ||
( ( V_28 -> V_43 . V_498 == V_499 ) &&
( V_250 -> V_277 != V_299 ) ) ) ) ||
V_28 -> V_43 . V_44 )
goto V_500;
if ( ( V_28 -> V_331 != V_334 ) || ! V_28 -> V_501 ) {
V_28 -> V_264 . V_502 ++ ;
goto V_500;
}
if ( ( V_125 == V_128 ) &&
( V_28 -> V_97 . V_174 == 0 ) )
goto V_500;
if ( V_28 -> V_43 . V_312 ) {
V_28 -> V_313 . V_503 ++ ;
V_28 -> V_313 . V_504 = F_149 () ;
}
V_495 = F_221 ( V_250 ) ;
if ( ( V_28 -> V_97 . type == V_98 ) && ( ! V_495 ) &&
( F_211 ( V_250 ) -> V_497 == 0 ) ) {
V_487 = V_250 ;
if ( V_487 -> V_277 == V_299 )
V_496 = 0 ;
else
V_496 = V_505 ;
V_141 = F_222 ( V_506 , V_61 ) ;
if ( ! V_141 )
goto V_500;
V_485 ++ ;
} else {
V_487 = F_223 ( V_250 , sizeof( struct V_459 )
+ V_507 ) ;
if ( ! V_487 )
goto V_500;
}
if ( V_28 -> V_97 . type == V_98 ) {
if ( V_496 < 0 )
F_202 ( V_487 , V_505 ) ;
} else {
if ( V_446 == 4 ) {
F_202 ( V_487 , V_505 ) ;
}
if ( V_446 != 4 && F_204 ( V_487 ) ) {
F_224 ( V_487 , V_507 ) ;
F_225 ( V_487 , V_487 -> V_83 + 4 , 4 ) ;
F_226 ( V_487 , 4 ,
V_487 -> V_83 + 8 , 4 ) ;
F_226 ( V_487 , 8 ,
V_487 -> V_83 + 12 , 4 ) ;
V_484 = ( T_4 * ) ( V_487 -> V_83 + 12 ) ;
* V_484 = F_137 ( V_227 ) ;
* ( V_484 + 1 ) = F_112 ( F_205 ( V_487 ) ) ;
}
}
F_227 ( V_122 ) ;
if ( V_495 ) {
if ( F_214 ( V_487 ) + 1 > 16 ) {
if ( F_228 ( V_487 ) )
goto V_500;
if ( V_28 -> V_43 . V_312 )
V_28 -> V_313 . V_508 ++ ;
}
}
if ( V_495 && ( V_125 == V_430 ) ) {
V_141 = (struct V_251 * ) F_224 ( V_487 ,
sizeof( struct V_459 ) ) ;
memset ( V_141 , 0 , sizeof( struct V_459 ) ) ;
F_203 ( V_28 , V_141 , V_487 , V_446 , V_125 ) ;
F_209 ( V_28 , V_141 , V_487 ) ;
V_485 ++ ;
} else {
if ( V_496 < 0 ) {
V_141 = (struct V_251 * ) F_224 ( V_487 ,
sizeof( struct V_251 ) ) ;
F_203 ( V_28 , V_141 , V_487 , V_446 ,
V_125 ) ;
} else {
if ( V_487 -> V_277 == V_299 )
F_201 ( V_28 , V_141 , V_487 ) ;
else {
F_203 ( V_28 , V_141 , V_487 , V_446 ,
V_125 ) ;
V_141 -> V_141 . V_257 . V_161 = V_487 -> V_23 - V_496 ;
}
}
if ( V_250 -> V_282 == V_509 )
F_208 ( V_28 , V_141 , V_487 ) ;
}
V_486 = F_229 ( V_28 , V_487 , V_485 ) ;
if ( ! V_486 ) {
if ( V_496 >= 0 )
F_230 ( V_506 , V_141 ) ;
goto V_500;
}
V_485 += V_486 ;
V_497 = F_211 ( V_487 ) -> V_497 ;
if ( V_28 -> V_97 . type != V_98 ) {
int V_23 ;
if ( V_495 )
V_23 = ( ( unsigned long ) F_210 ( V_487 ) +
F_210 ( V_487 ) -> V_476 * 4 ) -
( unsigned long ) V_487 -> V_83 ;
else
V_23 = sizeof( struct V_510 ) ;
if ( F_231 ( V_487 , & V_141 , V_23 ) )
goto V_500;
V_4 = F_232 ( V_28 , V_489 , V_487 , V_141 ,
V_485 ) ;
} else
V_4 = F_233 ( V_28 , V_489 , V_487 , V_141 ,
V_485 , V_496 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_264 . V_511 ++ ;
V_28 -> V_264 . V_494 += V_494 ;
if ( V_487 != V_250 )
F_145 ( V_250 ) ;
if ( V_28 -> V_43 . V_312 ) {
if ( V_495 ) {
V_28 -> V_313 . V_512 += V_494 ;
V_28 -> V_313 . V_513 ++ ;
}
if ( V_497 ) {
V_28 -> V_313 . V_514 ++ ;
V_28 -> V_313 . V_515 += V_497 + 1 ;
}
}
V_4 = V_516 ;
} else {
if ( V_496 >= 0 )
F_230 ( V_506 , V_141 ) ;
if ( V_4 == - V_517 ) {
if ( V_487 != V_250 )
F_145 ( V_487 ) ;
return V_518 ;
} else
goto V_500;
}
F_234 ( V_122 ) ;
if ( V_28 -> V_43 . V_312 )
V_28 -> V_313 . V_519 += F_149 () -
V_28 -> V_313 . V_504 ;
return V_4 ;
V_500:
V_28 -> V_264 . V_520 ++ ;
V_28 -> V_264 . V_521 ++ ;
if ( ( V_487 != V_250 ) && V_487 )
F_145 ( V_487 ) ;
F_145 ( V_250 ) ;
F_234 ( V_122 ) ;
return V_516 ;
}
static int F_235 ( struct V_215 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_172 ) ;
if ( V_28 -> V_331 == V_334 )
return V_4 ;
if ( V_28 -> V_331 != V_335 )
return - V_409 ;
V_28 -> V_83 . V_331 = V_332 ;
V_28 -> V_331 = V_334 ;
F_236 ( V_122 ) ;
if ( F_237 ( V_28 -> V_83 . V_318 , 0 ) >= 0 ) {
F_238 ( & V_28 -> V_302 ) ;
F_156 ( & V_28 -> V_302 ) ;
} else
V_4 = - V_182 ;
return V_4 ;
}
static int F_239 ( struct V_215 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
F_17 ( V_28 , 5 , L_173 ) ;
if ( F_133 ( V_28 , V_247 ) ) {
F_17 ( V_28 , 3 , L_174 ) ;
return - V_522 ;
}
return F_235 ( V_122 ) ;
}
static int F_165 ( struct V_215 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
F_17 ( V_28 , 4 , L_175 ) ;
F_240 ( V_122 ) ;
if ( V_28 -> V_331 == V_334 ) {
V_28 -> V_331 = V_335 ;
F_241 ( & V_28 -> V_302 ) ;
}
return 0 ;
}
static T_8 F_242 ( struct V_215 * V_122 ,
T_8 V_184 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
if ( ! F_54 ( V_28 , V_155 ) )
V_184 &= ~ V_523 ;
if ( ! F_54 ( V_28 , V_187 ) )
V_184 &= ~ V_188 ;
if ( ! F_54 ( V_28 , V_150 ) )
V_184 &= ~ V_185 ;
return V_184 ;
}
static int F_243 ( struct V_215 * V_122 ,
T_8 V_184 )
{
struct V_27 * V_28 = V_122 -> V_245 ;
T_9 V_524 = V_122 -> V_184 ^ V_184 ;
int V_525 ;
if ( ! ( V_524 & V_185 ) )
return 0 ;
if ( V_28 -> V_331 == V_337 ||
V_28 -> V_331 == V_526 )
return 0 ;
V_525 = F_89 ( V_28 , V_184 & V_185 ) ;
if ( V_525 )
V_122 -> V_184 = V_184 ^ V_185 ;
return V_525 ;
}
static int F_244 ( struct V_431 * V_432 )
{
V_432 -> V_527 = V_528 ;
memcpy ( V_432 -> V_529 , L_125 , 6 ) ;
V_432 -> V_530 = V_432 -> V_531 -> V_532 ;
return 0 ;
}
static int
F_245 ( struct V_215 * V_122 , struct V_533 * V_534 )
{
if ( V_534 -> V_535 -> V_536 == V_537 )
V_534 -> V_538 = F_244 ;
return 0 ;
}
static int F_246 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_97 . type == V_422 ||
V_28 -> V_97 . type == V_423 ) {
if ( ( V_28 -> V_97 . V_436 == V_438 ) ||
( V_28 -> V_97 . V_436 == V_437 ) ) {
F_247 ( L_176 ) ;
return - V_409 ;
} else {
V_28 -> V_122 = F_248 ( 0 ) ;
if ( ! V_28 -> V_122 )
return - V_409 ;
V_28 -> V_122 -> V_539 = & V_540 ;
F_102 ( V_28 ) ;
if ( ! ( V_28 -> V_97 . V_191 & V_195 ) )
V_28 -> V_122 -> V_541 = V_28 -> V_97 . V_191 &
0xffff ;
if ( ! V_28 -> V_97 . V_339 ) {
V_28 -> V_122 -> V_542 = V_543 |
V_185 | V_523 |
V_188 ;
V_28 -> V_122 -> V_184 = V_185 ;
}
}
} else if ( V_28 -> V_97 . type == V_98 ) {
V_28 -> V_122 = F_249 ( 0 , L_177 , V_544 ,
V_545 ) ;
if ( ! V_28 -> V_122 )
return - V_409 ;
V_28 -> V_122 -> V_58 |= V_546 ;
V_28 -> V_122 -> V_539 = & V_547 ;
V_4 = F_100 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_43 . V_548 [ 0 ] )
memcpy ( V_28 -> V_122 -> V_549 , V_28 -> V_43 . V_548 , 9 ) ;
} else
return - V_409 ;
V_28 -> V_122 -> V_245 = V_28 ;
V_28 -> V_122 -> V_550 = V_551 ;
V_28 -> V_122 -> V_552 = V_28 -> V_97 . V_553 ;
V_28 -> V_122 -> V_554 = & V_555 ;
V_28 -> V_122 -> V_184 |= V_556 |
V_557 |
V_558 ;
F_250 ( V_28 -> V_122 ) ;
V_28 -> V_122 -> V_559 = 15 * V_560 ;
F_251 ( V_28 -> V_122 , & V_28 -> V_121 -> V_122 ) ;
F_252 ( V_28 -> V_122 , & V_28 -> V_302 , F_147 , V_561 ) ;
return F_253 ( V_28 -> V_122 ) ;
}
static int F_254 ( struct V_562 * V_121 )
{
struct V_27 * V_28 = F_255 ( & V_121 -> V_122 ) ;
F_256 ( & V_121 -> V_122 ) ;
V_28 -> V_43 . V_328 = 0 ;
V_28 -> V_97 . V_563 = 0 ;
return 0 ;
}
static void F_257 ( struct V_562 * V_564 )
{
struct V_27 * V_28 = F_255 ( & V_564 -> V_122 ) ;
F_258 ( & V_564 -> V_122 ) ;
F_164 ( V_28 , 0 , 1 ) ;
F_259 ( V_28 -> V_565 , F_174 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_564 -> V_331 == V_566 )
F_260 ( V_564 ) ;
if ( V_28 -> V_122 ) {
F_261 ( V_28 -> V_122 ) ;
V_28 -> V_122 = NULL ;
}
F_38 ( V_28 , 0 ) ;
F_55 ( V_28 ) ;
return;
}
static int F_262 ( struct V_562 * V_121 , int V_329 )
{
struct V_27 * V_28 = F_255 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
enum V_567 V_568 ;
F_263 ( & V_28 -> V_569 ) ;
F_263 ( & V_28 -> V_570 ) ;
F_66 ( V_136 , 2 , L_178 ) ;
F_146 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
V_568 = V_28 -> V_331 ;
V_4 = F_264 ( V_28 ) ;
if ( V_4 ) {
F_265 ( V_136 , 2 , L_179 , V_4 ) ;
V_4 = - V_409 ;
goto V_571;
}
if ( ! V_28 -> V_122 && F_246 ( V_28 ) ) {
V_4 = - V_409 ;
goto V_571;
}
if ( F_266 ( V_28 , V_572 ) ) {
if ( V_28 -> V_97 . V_563 &&
F_267 ( V_28 , V_573 ) )
V_28 -> V_97 . V_563 = 0 ;
} else
V_28 -> V_97 . V_563 = 0 ;
V_28 -> V_331 = V_336 ;
memset ( & V_28 -> V_293 , 0 , sizeof( struct V_574 ) ) ;
F_268 ( V_28 ) ;
F_66 ( V_136 , 2 , L_180 ) ;
V_4 = F_269 ( V_28 ) ;
if ( V_4 ) {
F_265 ( V_136 , 2 , L_181 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_182 ) ;
V_28 -> V_501 = 0 ;
goto V_575;
}
V_4 = - V_409 ;
goto V_571;
} else
V_28 -> V_501 = 1 ;
V_575:
V_4 = F_65 ( V_28 ) ;
if ( V_4 )
F_265 ( V_136 , 2 , L_179 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_96 ( V_28 ) ;
if ( V_4 ) {
F_265 ( V_136 , 2 , L_183 , V_4 ) ;
goto V_571;
}
V_4 = F_49 ( V_28 ) ;
if ( V_4 )
F_265 ( V_136 , 2 , L_184 , V_4 ) ;
V_4 = F_52 ( V_28 ) ;
if ( V_4 )
F_265 ( V_136 , 2 , L_185 , V_4 ) ;
}
F_240 ( V_28 -> V_122 ) ;
V_4 = F_270 ( V_28 ) ;
if ( V_4 ) {
F_265 ( V_136 , 2 , L_186 , V_4 ) ;
V_4 = - V_409 ;
goto V_571;
}
V_28 -> V_331 = V_335 ;
F_164 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_501 )
F_271 ( V_28 -> V_122 ) ;
else
F_272 ( V_28 -> V_122 ) ;
if ( V_568 == V_526 ) {
F_91 () ;
if ( V_329 )
F_235 ( V_28 -> V_122 ) ;
else
F_273 ( V_28 -> V_122 ) ;
F_135 ( V_28 -> V_122 ) ;
F_93 () ;
}
F_274 ( V_28 ) ;
F_275 ( & V_121 -> V_122 . V_576 , V_577 ) ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return 0 ;
V_571:
F_163 ( V_28 , 0 ) ;
F_277 ( F_278 ( V_28 ) ) ;
F_277 ( F_279 ( V_28 ) ) ;
F_277 ( F_280 ( V_28 ) ) ;
F_281 ( F_278 ( V_28 ) ) ;
if ( V_568 == V_526 )
V_28 -> V_331 = V_526 ;
else
V_28 -> V_331 = V_337 ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return V_4 ;
}
static int F_282 ( struct V_562 * V_121 )
{
return F_262 ( V_121 , 0 ) ;
}
static int F_283 ( struct V_562 * V_564 ,
int V_329 )
{
struct V_27 * V_28 = F_255 ( & V_564 -> V_122 ) ;
int V_4 = 0 , V_578 = 0 , V_579 = 0 ;
enum V_567 V_568 ;
F_263 ( & V_28 -> V_569 ) ;
F_263 ( & V_28 -> V_570 ) ;
F_66 ( V_136 , 3 , L_187 ) ;
F_146 ( V_136 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_122 && F_284 ( V_28 -> V_122 ) )
F_272 ( V_28 -> V_122 ) ;
V_568 = V_28 -> V_331 ;
if ( ( ! V_329 && V_28 -> V_97 . V_563 ) || V_28 -> V_97 . V_563 == 2 ) {
F_267 ( V_28 , V_580 ) ;
V_28 -> V_97 . V_563 = 1 ;
}
F_163 ( V_28 , V_329 ) ;
if ( ( V_28 -> V_43 . V_498 == V_499 ) && V_28 -> V_122 ) {
F_91 () ;
F_285 ( V_581 , V_28 -> V_122 ) ;
F_93 () ;
}
V_4 = F_277 ( F_278 ( V_28 ) ) ;
V_578 = F_277 ( F_279 ( V_28 ) ) ;
V_579 = F_277 ( F_280 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_578 ) ? V_578 : V_579 ;
if ( V_4 )
F_265 ( V_136 , 2 , L_181 , V_4 ) ;
F_281 ( F_278 ( V_28 ) ) ;
if ( V_568 == V_334 )
V_28 -> V_331 = V_526 ;
F_275 ( & V_564 -> V_122 . V_576 , V_577 ) ;
F_276 ( & V_28 -> V_570 ) ;
F_276 ( & V_28 -> V_569 ) ;
return 0 ;
}
static int F_260 ( struct V_562 * V_564 )
{
return F_283 ( V_564 , 0 ) ;
}
static int F_286 ( void * V_582 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_582 ;
F_17 ( V_28 , 2 , L_188 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_287 ( V_28 , V_247 ) )
return 0 ;
F_17 ( V_28 , 2 , L_189 ) ;
F_62 ( & V_28 -> V_121 -> V_122 ,
L_190 ) ;
F_288 ( V_28 ) ;
F_283 ( V_28 -> V_121 , 1 ) ;
V_4 = F_262 ( V_28 -> V_121 , 1 ) ;
if ( ! V_4 )
F_67 ( & V_28 -> V_121 -> V_122 ,
L_191 ) ;
else {
F_289 ( V_28 ) ;
F_62 ( & V_28 -> V_121 -> V_122 , L_192
L_193 ) ;
}
F_290 ( V_28 ) ;
F_291 ( V_28 , V_247 ) ;
F_292 ( V_28 , V_247 ) ;
return 0 ;
}
static void F_293 ( struct V_562 * V_121 )
{
struct V_27 * V_28 = F_255 ( & V_121 -> V_122 ) ;
F_164 ( V_28 , 0 , 1 ) ;
if ( ( V_121 -> V_331 == V_566 ) && V_28 -> V_97 . V_563 )
F_267 ( V_28 , V_580 ) ;
F_168 ( V_28 , 0 ) ;
F_169 ( V_28 ) ;
F_281 ( F_278 ( V_28 ) ) ;
}
static int F_294 ( struct V_562 * V_121 )
{
struct V_27 * V_28 = F_255 ( & V_121 -> V_122 ) ;
if ( V_28 -> V_122 )
F_295 ( V_28 -> V_122 ) ;
F_164 ( V_28 , 0 , 1 ) ;
F_259 ( V_28 -> V_565 , F_174 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_121 -> V_331 == V_583 )
return 0 ;
if ( V_28 -> V_331 == V_334 ) {
if ( V_28 -> V_97 . V_563 )
F_267 ( V_28 , V_580 ) ;
F_283 ( V_28 -> V_121 , 1 ) ;
} else
F_283 ( V_28 -> V_121 , 0 ) ;
return 0 ;
}
static int F_296 ( struct V_562 * V_121 )
{
struct V_27 * V_28 = F_255 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
if ( V_121 -> V_331 == V_583 )
goto V_14;
if ( V_28 -> V_331 == V_526 ) {
V_4 = F_262 ( V_28 -> V_121 , 1 ) ;
if ( V_4 ) {
F_91 () ;
F_166 ( V_28 -> V_122 ) ;
F_93 () ;
}
} else
V_4 = F_262 ( V_28 -> V_121 , 0 ) ;
V_14:
F_164 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_122 )
F_297 ( V_28 -> V_122 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_192
L_193 ) ;
return V_4 ;
}
static int F_298 ( struct V_27 * V_28 ,
struct V_80 * V_81 )
{
return 1 ;
}
static int F_299 ( struct V_584 * V_585 ,
unsigned long V_586 , void * V_582 )
{
struct V_237 * V_238 = (struct V_237 * ) V_582 ;
struct V_215 * V_122 = (struct V_215 * ) V_238 -> V_587 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_300 ( V_122 ) != & V_588 )
return V_589 ;
V_28 = F_162 ( V_122 ) ;
if ( ! V_28 )
return V_589 ;
F_17 ( V_28 , 3 , L_194 ) ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_238 -> V_241 ;
V_2 -> V_36 . V_47 . V_48 = V_238 -> V_242 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_586 ) {
case V_590 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_591 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_589 ;
}
static int F_301 ( struct V_584 * V_585 ,
unsigned long V_586 , void * V_582 )
{
struct V_243 * V_238 = (struct V_243 * ) V_582 ;
struct V_215 * V_122 = (struct V_215 * ) V_238 -> V_592 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_162 ( V_122 ) ;
if ( ! V_28 )
return V_589 ;
F_17 ( V_28 , 3 , L_195 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return V_589 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_238 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_238 -> V_244 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_586 ) {
case V_590 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_591 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_589 ;
}
static int F_302 ( void )
{
int V_4 ;
F_66 ( V_136 , 5 , L_196 ) ;
V_4 = F_303 ( & V_593 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_53
V_4 = F_304 ( & V_594 ) ;
if ( V_4 ) {
F_305 ( & V_593 ) ;
return V_4 ;
}
#else
F_306 ( L_197 ) ;
#endif
return 0 ;
}
static void F_307 ( void )
{
F_66 ( V_136 , 5 , L_198 ) ;
F_308 ( F_305 ( & V_593 ) ) ;
#ifdef F_53
F_308 ( F_309 ( & V_594 ) ) ;
#endif
}
static int T_10 F_310 ( void )
{
int V_4 = 0 ;
F_247 ( L_199 ) ;
V_4 = F_302 () ;
return V_4 ;
}
static void T_11 F_311 ( void )
{
F_307 () ;
F_247 ( L_200 ) ;
}
