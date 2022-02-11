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
enum V_157 V_158 , T_2 V_159 )
{
int V_4 ;
struct V_78 * V_79 ;
F_17 ( V_28 , 4 , L_49 ) ;
V_79 = F_73 ( V_28 , V_158 , V_159 ,
0 , V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_75 ( V_28 , V_79 , 0 , 0 ,
F_72 , NULL ) ;
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_50 ) ;
if ( ! F_54 ( V_28 , V_163 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_51 ,
F_51 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_77 ( V_28 , V_163 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_52 ,
F_51 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_78 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_53 ) ;
if ( ! F_54 ( V_28 , V_164 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_54 ,
F_51 ( V_28 ) ) ;
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_164 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_55 ,
F_51 ( V_28 ) ) ;
} else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_56 ) ;
return V_4 ;
}
static int F_79 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_57 ) ;
if ( ! F_54 ( V_28 , V_166 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_58 ,
F_51 ( V_28 ) ) ;
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_166 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 ,
L_59 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_60 ) ;
if ( ! F_54 ( V_28 , V_167 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_61 , F_51 ( V_28 ) ) ;
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_168 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_62 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_63 ) ;
}
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_64 ) ;
if ( ! F_54 ( V_28 , V_169 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_65 ,
F_51 ( V_28 ) ) ;
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_169 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_66 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_67 ) ;
V_28 -> V_122 -> V_58 |= V_170 ;
}
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_68 ) ;
if ( V_28 -> V_97 . type == V_98 )
goto V_14;
V_4 = F_83 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_69 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_77 ( V_28 , V_108 ,
V_152 , 3 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_69 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_74 ( V_28 , V_108 ,
V_152 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_69 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_74 ( V_28 , V_171 ,
V_152 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_70 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_67 ( & V_28 -> V_121 -> V_122 , L_71 ) ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_72 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_73 , F_51 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_53
V_4 = F_82 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_86 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_74 ) ;
V_28 -> V_97 . V_172 = 0 ;
if ( ! F_54 ( V_28 , V_173 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_75 ,
F_51 ( V_28 ) ) ;
V_4 = - V_165 ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_173 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_76
L_77 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_173 ,
V_174 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_78 ,
F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_172 = V_175 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_79 ) ;
V_4 = F_77 ( V_28 , V_173 ,
V_176 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_80
L_81 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_172 = V_177 ;
V_14:
if ( V_28 -> V_97 . V_172 )
V_28 -> V_122 -> V_58 |= V_178 ;
else
V_28 -> V_122 -> V_58 &= ~ V_178 ;
return V_4 ;
}
static void F_87 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_82 ) ;
if ( F_54 ( V_28 , V_150 )
&& ( V_28 -> V_122 -> V_179 & V_180 ) )
F_88 ( V_28 , 1 ) ;
}
static void F_89 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_83 ) ;
F_90 ( V_28 ) ;
}
static int F_91 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_84 ) ;
if ( ! F_54 ( V_28 , V_181 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_85 ,
F_51 ( V_28 ) ) ;
V_4 = - V_165 ;
} else {
V_4 = F_77 ( V_28 , V_181 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_86
L_87 ,
F_51 ( V_28 ) ) ;
else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_88 ) ;
}
if ( V_4 )
V_28 -> V_122 -> V_179 &= ~ V_182 ;
return V_4 ;
}
static int F_92 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_89 ) ;
if ( F_93 ( V_28 , 0 ) )
return - V_183 ;
F_76 ( V_28 ) ;
F_78 ( V_28 ) ;
F_79 ( V_28 ) ;
F_80 ( V_28 ) ;
F_81 ( V_28 ) ;
F_85 ( V_28 ) ;
F_86 ( V_28 ) ;
F_87 ( V_28 ) ;
F_89 ( V_28 ) ;
F_91 ( V_28 ) ;
return 0 ;
}
static int F_94 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) V_83 ;
if ( V_81 -> V_141 . V_142 == 0 )
memcpy ( V_28 -> V_122 -> V_184 ,
V_81 -> V_83 . V_185 . V_186 , V_187 ) ;
else
F_95 ( V_28 -> V_122 -> V_184 ) ;
return 0 ;
}
static int F_96 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_90 ) ;
V_79 = F_41 ( V_28 , V_188 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_185 . V_186 [ 6 ] ) =
V_28 -> V_97 . V_186 ;
V_4 = F_42 ( V_28 , V_79 , F_94 ,
NULL ) ;
return V_4 ;
}
static int F_97 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) V_83 ;
if ( V_81 -> V_141 . V_142 == 0 )
V_28 -> V_97 . V_186 = * ( ( T_2 * )
& V_81 -> V_83 . V_185 . V_186 [ 6 ] ) ;
else {
V_28 -> V_97 . V_186 = V_189 |
V_190 ;
F_62 ( & V_28 -> V_121 -> V_122 , L_91
L_92 ) ;
}
return 0 ;
}
static int F_98 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_93 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
V_28 -> V_97 . V_186 = V_189 |
V_190 ;
return 0 ;
}
V_79 = F_41 ( V_28 , V_188 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_185 . V_186 [ 6 ] ) =
V_28 -> V_97 . V_186 ;
V_4 = F_42 ( V_28 , V_79 , F_97 , NULL ) ;
return V_4 ;
}
static int
F_99 ( struct V_27 * V_28 , struct V_139 * V_140 ,
unsigned long V_83 )
{
struct V_80 * V_81 ;
T_2 V_4 ;
F_66 ( V_136 , 2 , L_94 ) ;
V_81 = (struct V_80 * ) V_83 ;
V_4 = V_81 -> V_141 . V_142 ;
if ( V_4 )
F_45 ( V_28 , 2 , L_95 , V_4 ) ;
switch ( V_81 -> V_83 . V_191 . V_192 ) {
case V_193 :
break;
case V_194 :
switch ( V_4 ) {
case 0 :
case V_195 :
V_28 -> V_97 . V_196 = V_197 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_96
L_97 ) ;
break;
default:
break;
}
break;
case V_198 :
switch ( V_4 ) {
case 0 :
V_28 -> V_97 . V_196 = V_199 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_96
L_98 ) ;
break;
case V_200 :
F_62 ( & V_28 -> V_121 -> V_122 , L_99
L_100
L_101 ) ;
break;
case V_201 :
F_62 ( & V_28 -> V_121 -> V_122 , L_102
L_103
L_104 ) ;
break;
default:
break;
}
break;
default:
F_50 ( 2 , L_105 ,
V_81 -> V_83 . V_191 . V_192 , F_51 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_100 ( struct V_27 * V_28 , enum V_202 V_203 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_106 ) ;
V_79 = F_41 ( V_28 , V_204 , 0 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_191 . V_205 = 16 ;
V_81 -> V_83 . V_191 . V_206 = V_207 ;
V_81 -> V_83 . V_191 . type = V_208 ;
V_81 -> V_83 . V_191 . V_192 = V_203 ;
return F_42 ( V_28 , V_79 , F_99 , NULL ) ;
}
static void F_101 ( T_4 V_209 , char * V_86 ,
struct V_210 * V_122 )
{
F_102 ( V_209 , V_86 ) ;
}
static void F_103 ( struct V_27 * V_28 , struct V_211 * V_212 )
{
struct V_29 * V_209 ;
struct V_213 * V_214 ;
char V_1 [ V_215 ] ;
F_17 ( V_28 , 4 , L_107 ) ;
for ( V_214 = F_104 ( V_212 -> V_216 ) ; V_214 != NULL ;
V_214 = F_104 ( V_214 -> V_217 ) ) {
F_101 ( V_214 -> V_218 , V_1 , V_212 -> V_122 ) ;
V_209 = F_24 ( V_20 ) ;
if ( ! V_209 )
continue;
V_209 -> V_36 . V_47 . V_2 = V_214 -> V_218 ;
memcpy ( V_209 -> V_86 , V_1 , V_87 ) ;
V_209 -> V_46 = 1 ;
if ( ! F_23 ( V_28 , V_209 ) )
F_15 ( V_209 ) ;
}
}
static void F_105 ( struct V_27 * V_28 )
{
struct V_211 * V_219 ;
T_5 V_220 ;
F_17 ( V_28 , 4 , L_108 ) ;
if ( ! F_54 ( V_28 , V_167 ) )
return;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_210 * V_221 ;
V_221 = F_107 ( V_28 -> V_122 , F_108 ( V_222 ) ,
V_220 ) ;
if ( V_221 == NULL ||
! ( V_221 -> V_58 & V_223 ) )
continue;
V_219 = F_109 ( V_221 ) ;
if ( ! V_219 )
continue;
F_103 ( V_28 , V_219 ) ;
}
}
static void F_110 ( struct V_27 * V_28 )
{
struct V_211 * V_212 ;
F_17 ( V_28 , 4 , L_109 ) ;
F_111 () ;
V_212 = F_109 ( V_28 -> V_122 ) ;
if ( V_212 == NULL )
goto V_224;
F_103 ( V_28 , V_212 ) ;
F_105 ( V_28 ) ;
V_224:
F_112 () ;
}
static void F_113 ( struct V_27 * V_28 , struct V_225 * V_226 )
{
struct V_29 * V_209 ;
struct V_227 * V_228 ;
char V_1 [ V_215 ] ;
F_17 ( V_28 , 4 , L_110 ) ;
for ( V_228 = V_226 -> V_216 ; V_228 != NULL ; V_228 = V_228 -> V_71 ) {
F_114 ( & V_228 -> V_229 , V_1 , V_226 -> V_122 , 0 ) ;
V_209 = F_24 ( V_21 ) ;
if ( ! V_209 )
continue;
V_209 -> V_46 = 1 ;
memcpy ( V_209 -> V_86 , V_1 , V_87 ) ;
memcpy ( & V_209 -> V_36 . V_49 . V_2 , & V_228 -> V_229 . V_230 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_209 ) )
F_15 ( V_209 ) ;
}
}
static void F_115 ( struct V_27 * V_28 )
{
struct V_225 * V_219 ;
T_5 V_220 ;
F_17 ( V_28 , 4 , L_111 ) ;
if ( ! F_54 ( V_28 , V_167 ) )
return;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_210 * V_221 ;
V_221 = F_107 ( V_28 -> V_122 , F_108 ( V_222 ) ,
V_220 ) ;
if ( V_221 == NULL ||
! ( V_221 -> V_58 & V_223 ) )
continue;
V_219 = F_116 ( V_221 ) ;
if ( ! V_219 )
continue;
F_117 ( & V_219 -> V_231 ) ;
F_113 ( V_28 , V_219 ) ;
F_118 ( & V_219 -> V_231 ) ;
F_119 ( V_219 ) ;
}
}
static void F_120 ( struct V_27 * V_28 )
{
struct V_225 * V_226 ;
F_17 ( V_28 , 4 , L_112 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return ;
V_226 = F_116 ( V_28 -> V_122 ) ;
if ( V_226 == NULL )
return;
F_111 () ;
F_117 ( & V_226 -> V_231 ) ;
F_113 ( V_28 , V_226 ) ;
F_115 ( V_28 ) ;
F_118 ( & V_226 -> V_231 ) ;
F_112 () ;
F_119 ( V_226 ) ;
}
static void F_121 ( struct V_27 * V_28 ,
unsigned short V_220 )
{
struct V_211 * V_219 ;
struct V_232 * V_233 ;
struct V_29 * V_2 ;
struct V_210 * V_221 ;
F_17 ( V_28 , 4 , L_113 ) ;
V_221 = F_107 ( V_28 -> V_122 , F_108 ( V_222 ) , V_220 ) ;
if ( ! V_221 )
return;
V_219 = F_122 ( V_221 ) ;
if ( ! V_219 )
return;
for ( V_233 = V_219 -> V_234 ; V_233 ; V_233 = V_233 -> V_235 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_233 -> V_236 ;
V_2 -> V_36 . V_47 . V_48 = V_233 -> V_237 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_123 ( V_219 ) ;
}
static void F_124 ( struct V_27 * V_28 ,
unsigned short V_220 )
{
#ifdef F_53
struct V_225 * V_226 ;
struct V_238 * V_233 ;
struct V_29 * V_2 ;
struct V_210 * V_221 ;
F_17 ( V_28 , 4 , L_114 ) ;
V_221 = F_107 ( V_28 -> V_122 , F_108 ( V_222 ) , V_220 ) ;
if ( ! V_221 )
return;
V_226 = F_116 ( V_221 ) ;
if ( ! V_226 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_233 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_233 -> V_239 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_119 ( V_226 ) ;
#endif
}
static void F_125 ( struct V_27 * V_28 ,
unsigned short V_220 )
{
F_111 () ;
F_121 ( V_28 , V_220 ) ;
F_124 ( V_28 , V_220 ) ;
F_112 () ;
}
static int F_126 ( struct V_210 * V_122 ,
T_6 V_19 , T_5 V_220 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
F_127 ( V_220 , V_28 -> V_241 ) ;
return 0 ;
}
static int F_128 ( struct V_210 * V_122 ,
T_6 V_19 , T_5 V_220 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
unsigned long V_58 ;
F_45 ( V_28 , 4 , L_115 , V_220 ) ;
if ( F_129 ( V_28 , V_242 ) ) {
F_17 ( V_28 , 3 , L_116 ) ;
return 0 ;
}
F_21 ( & V_28 -> V_243 , V_58 ) ;
F_125 ( V_28 , V_220 ) ;
F_130 ( V_220 , V_28 -> V_241 ) ;
F_22 ( & V_28 -> V_243 , V_58 ) ;
F_131 ( V_28 -> V_122 ) ;
return 0 ;
}
static inline int F_132 ( struct V_27 * V_28 ,
struct V_244 * V_245 , struct V_246 * V_141 ,
unsigned short * V_247 )
{
T_6 V_60 ;
struct V_248 * V_249 ;
unsigned char V_250 [ V_215 ] ;
int V_251 = 0 ;
if ( ! ( V_141 -> V_141 . V_252 . V_58 & V_132 ) ) {
V_60 = F_108 ( ( V_141 -> V_141 . V_252 . V_58 & V_133 ) ? V_253 :
V_254 ) ;
switch ( V_141 -> V_141 . V_252 . V_58 & V_255 ) {
case V_127 :
switch ( V_60 ) {
#ifdef F_53
case F_133 ( V_253 ) :
F_114 ( (struct V_51 * )
V_245 -> V_83 + 24 ,
V_250 , V_28 -> V_122 , 0 ) ;
break;
#endif
case F_133 ( V_254 ) :
V_249 = (struct V_248 * ) V_245 -> V_83 ;
F_102 ( V_249 -> V_256 , V_250 ) ;
break;
default:
memcpy ( V_250 , V_28 -> V_122 -> V_257 ,
V_28 -> V_122 -> V_258 ) ;
}
V_28 -> V_259 . V_260 ++ ;
V_245 -> V_261 = V_262 ;
break;
case V_129 :
memcpy ( V_250 , V_28 -> V_122 -> V_257 ,
V_28 -> V_122 -> V_258 ) ;
V_28 -> V_259 . V_260 ++ ;
V_245 -> V_261 = V_263 ;
break;
case V_130 :
case V_135 :
case V_264 :
default:
if ( V_28 -> V_43 . V_44 )
V_245 -> V_261 = V_265 ;
else
V_245 -> V_261 = V_266 ;
memcpy ( V_250 , V_28 -> V_122 -> V_184 ,
V_28 -> V_122 -> V_258 ) ;
}
if ( V_141 -> V_141 . V_252 . V_267 & V_268 )
V_28 -> V_122 -> V_269 -> V_270 ( V_245 , V_28 -> V_122 , V_60 ,
V_250 , & V_141 -> V_141 . V_252 . V_271 [ 2 ] ,
V_28 -> V_122 -> V_258 ) ;
else
V_28 -> V_122 -> V_269 -> V_270 ( V_245 , V_28 -> V_122 , V_60 ,
V_250 , L_117 , V_28 -> V_122 -> V_258 ) ;
}
V_245 -> V_272 = F_134 ( V_245 , V_28 -> V_122 ) ;
if ( V_141 -> V_141 . V_252 . V_267 &
( V_273 | V_274 ) ) {
* V_247 = ( V_141 -> V_141 . V_252 . V_267 & V_273 ) ?
V_141 -> V_141 . V_252 . V_247 : * ( ( T_5 * ) & V_141 -> V_141 . V_252 . V_271 [ 12 ] ) ;
V_251 = 1 ;
}
if ( V_28 -> V_122 -> V_179 & V_180 ) {
if ( ( V_141 -> V_141 . V_252 . V_267 &
( V_275 |
V_276 ) ) ==
( V_275 |
V_276 ) )
V_245 -> V_277 = V_278 ;
else
V_245 -> V_277 = V_279 ;
} else
V_245 -> V_277 = V_279 ;
return V_251 ;
}
static int F_135 ( struct V_27 * V_28 ,
int V_280 , int * V_281 )
{
int V_282 = 0 ;
struct V_244 * V_245 ;
struct V_246 * V_141 ;
T_2 V_283 = 0 ;
int V_251 ;
unsigned int V_23 ;
T_2 V_284 ;
* V_281 = 0 ;
F_136 ( ! V_280 ) ;
while ( V_280 ) {
V_245 = F_137 ( V_28 ,
& V_28 -> V_285 . V_286 -> V_287 [ V_28 -> V_288 . V_289 ] ,
& V_28 -> V_288 . V_290 , & V_28 -> V_288 . V_291 , & V_141 ) ;
if ( ! V_245 ) {
* V_281 = 1 ;
break;
}
V_245 -> V_122 = V_28 -> V_122 ;
switch ( V_141 -> V_141 . V_252 . V_292 ) {
case V_293 :
V_284 = * ( T_2 * ) V_245 -> V_83 ;
if ( ( V_28 -> V_97 . type == V_98 ) &&
( V_284 == V_294 ) ) {
V_245 -> V_272 = V_294 ;
V_245 -> V_261 = V_266 ;
V_245 -> V_295 = V_296 ;
V_245 -> V_122 = V_28 -> V_122 ;
V_23 = V_245 -> V_23 ;
V_28 -> V_122 -> V_269 -> V_270 ( V_245 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_184 , L_117 ,
V_28 -> V_122 -> V_258 ) ;
F_138 ( V_245 ) ;
} else {
V_251 = F_132 ( V_28 , V_245 , V_141 ,
& V_283 ) ;
V_23 = V_245 -> V_23 ;
if ( V_251 && ! V_28 -> V_43 . V_44 )
F_139 ( V_245 ,
F_108 ( V_222 ) , V_283 ) ;
F_140 ( & V_28 -> V_297 , V_245 ) ;
}
break;
case V_298 :
V_245 -> V_261 = V_266 ;
V_245 -> V_272 = F_134 ( V_245 , V_245 -> V_122 ) ;
V_23 = V_245 -> V_23 ;
F_138 ( V_245 ) ;
break;
default:
F_141 ( V_245 ) ;
F_17 ( V_28 , 3 , L_118 ) ;
F_142 ( V_299 , 3 , V_141 , V_300 ) ;
continue;
}
V_282 ++ ;
V_280 -- ;
V_28 -> V_259 . V_301 ++ ;
V_28 -> V_259 . V_302 += V_23 ;
}
return V_282 ;
}
static int F_143 ( struct V_303 * V_297 , int V_280 )
{
struct V_27 * V_28 = F_144 ( V_297 , struct V_27 , V_297 ) ;
int V_282 = 0 ;
struct V_304 * V_305 ;
int V_281 ;
int V_306 = V_280 ;
if ( V_28 -> V_43 . V_307 ) {
V_28 -> V_308 . V_309 ++ ;
V_28 -> V_308 . V_310 = F_145 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_288 . V_311 ) {
V_28 -> V_288 . V_312 = 0 ;
V_28 -> V_288 . V_311 = F_146 (
V_28 -> V_83 . V_313 , 0 , & V_28 -> V_288 . V_289 ,
& V_28 -> V_288 . V_312 ) ;
if ( V_28 -> V_288 . V_311 <= 0 ) {
V_28 -> V_288 . V_311 = 0 ;
break;
}
V_28 -> V_288 . V_290 =
& V_28 -> V_285 . V_286 -> V_287 [ V_28 -> V_288 . V_289 ]
. V_305 -> V_314 [ 0 ] ;
V_28 -> V_288 . V_291 = 0 ;
}
while ( V_28 -> V_288 . V_311 ) {
V_305 = & V_28 -> V_285 . V_286 -> V_287 [ V_28 -> V_288 . V_289 ] ;
if ( ! ( V_28 -> V_288 . V_312 &&
F_147 ( V_28 , V_305 -> V_305 ,
V_28 -> V_288 . V_312 , L_119 ) ) )
V_282 += F_135 (
V_28 , V_306 , & V_281 ) ;
else
V_281 = 1 ;
if ( V_281 ) {
if ( V_28 -> V_43 . V_307 )
V_28 -> V_308 . V_315 ++ ;
F_148 ( V_28 ,
V_305 -> V_316 ) ;
F_149 ( V_28 , V_28 -> V_288 . V_289 ) ;
V_28 -> V_288 . V_311 -- ;
if ( V_28 -> V_288 . V_311 ) {
V_28 -> V_288 . V_289 =
( V_28 -> V_288 . V_289 + 1 ) %
V_317 ;
V_28 -> V_288 . V_290 =
& V_28 -> V_285 . V_286
-> V_287 [ V_28 -> V_288 . V_289 ]
. V_305 -> V_314 [ 0 ] ;
V_28 -> V_288 . V_291 = 0 ;
}
}
if ( V_282 >= V_280 )
goto V_14;
else
V_306 = V_280 - V_282 ;
}
}
F_150 ( V_297 ) ;
if ( F_151 ( V_28 -> V_83 . V_313 , 0 ) )
F_152 ( & V_28 -> V_297 ) ;
V_14:
if ( V_28 -> V_43 . V_307 )
V_28 -> V_308 . V_318 += F_145 () -
V_28 -> V_308 . V_310 ;
return V_282 ;
}
static int F_153 ( struct V_210 * V_122 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_220 ;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_210 * V_221 ;
F_111 () ;
V_221 = F_107 ( V_28 -> V_122 , F_108 ( V_222 ) ,
V_220 ) ;
F_112 () ;
if ( V_221 == V_122 ) {
V_4 = V_319 ;
break;
}
}
if ( V_4 && ! ( F_154 ( V_122 ) -> V_240 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_155 ( struct V_210 * V_122 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_156 ( & V_320 . V_321 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_122 == V_122 ) {
V_4 = V_322 ;
break;
}
V_4 = F_153 ( V_122 , V_28 ) ;
if ( V_4 )
break;
}
F_157 ( & V_320 . V_321 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_158 ( struct V_210 * V_122 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_155 ( V_122 ) ;
if ( V_4 == V_322 )
V_28 = V_122 -> V_240 ;
else if ( V_4 == V_319 )
V_28 = F_154 ( V_122 ) -> V_240 ;
if ( V_28 && V_28 -> V_43 . V_323 )
V_28 = NULL ;
if ( V_28 )
F_45 ( V_28 , 4 , L_120 , V_4 ) ;
return V_28 ;
}
static void F_159 ( struct V_27 * V_28 , int V_324 )
{
F_66 ( V_136 , 2 , L_121 ) ;
F_142 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
F_160 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_97 . V_196 == V_199 ) )
F_100 ( V_28 , V_194 ) ;
if ( V_28 -> V_325 . V_326 == V_327 &&
V_28 -> V_328 . V_326 == V_327 &&
( V_28 -> V_326 == V_329 ) ) {
if ( V_324 )
F_161 ( V_28 -> V_122 ) ;
else {
F_162 () ;
F_163 ( V_28 -> V_122 ) ;
F_164 () ;
}
V_28 -> V_326 = V_330 ;
}
if ( V_28 -> V_326 == V_330 ) {
F_38 ( V_28 , 1 ) ;
F_165 ( V_28 ) ;
V_28 -> V_326 = V_331 ;
}
if ( V_28 -> V_326 == V_331 ) {
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
F_168 ( V_28 ) ;
V_28 -> V_326 = V_332 ;
}
if ( V_28 -> V_326 == V_332 ) {
F_169 ( & V_28 -> V_325 ) ;
F_169 ( & V_28 -> V_328 ) ;
}
}
static void
F_170 ( struct V_27 * V_28 )
{
struct V_210 * V_122 = V_28 -> V_122 ;
if ( ( ( V_122 -> V_58 & V_333 ) &&
( V_28 -> V_97 . V_196 == V_199 ) ) ||
( ! ( V_122 -> V_58 & V_333 ) &&
( V_28 -> V_97 . V_196 == V_197 ) ) )
return;
if ( V_28 -> V_97 . V_334 ) {
if ( F_70 ( V_28 , V_335 ) )
F_171 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_70 ( V_28 , V_336 ) ) {
if ( V_122 -> V_58 & V_333 ) {
F_17 ( V_28 , 3 , L_122 ) ;
F_100 ( V_28 , V_198 ) ;
} else {
F_17 ( V_28 , 3 , L_123 ) ;
F_100 ( V_28 , V_194 ) ;
}
}
}
static void F_131 ( struct V_210 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
F_17 ( V_28 , 3 , L_124 ) ;
if ( F_172 ( V_28 , V_242 ) &&
( V_28 -> V_326 != V_329 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_110 ( V_28 ) ;
#ifdef F_53
F_120 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_70 ( V_28 , V_335 ) )
return;
}
F_170 ( V_28 ) ;
}
static const char * F_173 ( int * V_4 )
{
switch ( * V_4 ) {
case V_337 :
* V_4 = - V_183 ;
return L_125 ;
case V_338 :
* V_4 = - V_165 ;
return L_126 ;
case V_339 :
* V_4 = - V_7 ;
return L_127 ;
case V_340 :
* V_4 = - V_165 ;
return L_128 ;
case V_341 :
* V_4 = - V_342 ;
return L_129 ;
default:
return L_130 ;
}
}
static int F_174 ( struct V_27 * V_28 , int V_343 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_131 ) ;
if ( V_28 -> V_97 . V_334 )
return - V_165 ;
if ( ! F_54 ( V_28 , V_163 ) ) {
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_163 ,
V_344 ,
V_343 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_132
L_133 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static T_4 F_175 ( struct V_27 * V_28 ,
struct V_345 * V_346 ,
struct V_347 * type , T_1 V_348 )
{
T_4 V_4 ;
T_1 V_349 ;
V_349 = V_346 -> V_350 == 5 ;
if ( type -> V_351 == V_352 ) {
F_17 ( V_28 , 4 , L_134 ) ;
if ( V_348 ) {
V_4 = V_349 ? sizeof( struct V_353 ) :
sizeof( struct V_354 ) ;
} else {
V_4 = V_349 ? sizeof( struct V_355 ) :
sizeof( struct V_356 ) ;
}
} else if ( type -> V_351 == V_357 ) {
F_17 ( V_28 , 4 , L_135 ) ;
if ( V_348 ) {
V_4 = V_349 ?
sizeof( struct V_358 ) :
sizeof( struct V_359 ) ;
} else {
V_4 = V_349 ?
sizeof( struct V_360 ) :
sizeof( struct V_361 ) ;
}
} else {
F_17 ( V_28 , 4 , L_136 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_176 ( struct V_347 * type , T_2 V_60 )
{
return ( type -> V_351 == V_352 && V_60 == V_20 ) ||
( type -> V_351 == V_357 && V_60 == V_21 ) ;
}
static int F_177 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
struct V_345 * V_346 ;
struct V_362 * V_363 ;
int V_24 ;
int V_364 ;
int V_365 ;
int V_366 ;
T_1 V_367 ;
F_17 ( V_28 , 3 , L_137 ) ;
V_363 = (struct V_362 * ) V_140 -> V_368 ;
V_81 = (struct V_80 * ) V_83 ;
F_45 ( V_28 , 4 , L_138 , V_81 -> V_141 . V_144 ) ;
if ( V_81 -> V_141 . V_142 ) {
F_17 ( V_28 , 4 , L_139 ) ;
F_45 ( V_28 , 4 , L_138 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_142 ) {
V_81 -> V_141 . V_142 = V_81 -> V_83 . V_143 . V_141 . V_142 ;
F_17 ( V_28 , 4 , L_140 ) ;
F_45 ( V_28 , 4 , L_138 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
V_346 = & V_81 -> V_83 . V_143 . V_83 . V_369 ;
F_45 ( V_28 , 4 , L_141 , V_346 -> V_343 ) ;
V_367 = ( V_363 -> V_37 & V_370 ) > 0 ;
V_366 = V_367 ? V_371 : 0 ;
V_365 = 0 ;
for ( V_364 = 0 ; V_364 < V_346 -> V_343 ; ++ V_364 ) {
char * V_372 ;
T_4 V_373 ;
struct V_347 * V_374 ;
V_372 = & V_346 -> V_83 + V_365 ;
V_374 = & ( (struct V_355 * ) V_372 ) -> type ;
if ( ! F_176 ( V_374 , V_81 -> V_141 . V_144 ) ) {
F_17 ( V_28 , 4 , L_142 ) ;
F_45 ( V_28 , 4 , L_138 , V_374 -> V_351 ) ;
break;
}
V_373 = F_175 ( V_28 , V_346 , V_374 ,
V_367 ) ;
F_45 ( V_28 , 5 , L_143 , V_373 ) ;
if ( ! V_373 )
break;
if ( ( V_363 -> V_375 - V_363 -> V_376 ) < V_373 ) {
F_45 ( V_28 , 4 , L_144 , - V_82 ) ;
V_81 -> V_141 . V_142 = V_377 ;
goto V_378;
}
memcpy ( V_363 -> V_379 + V_363 -> V_376 ,
& V_346 -> V_83 + V_365 + V_366 ,
V_373 ) ;
V_365 += V_373 + V_366 ;
V_363 -> V_376 += V_373 ;
++ V_363 -> V_343 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_162 <
V_81 -> V_83 . V_143 . V_141 . V_380 )
return 1 ;
F_45 ( V_28 , 4 , L_145 , V_363 -> V_343 ) ;
memcpy ( V_363 -> V_379 , & V_363 -> V_343 , 4 ) ;
if ( V_363 -> V_37 & V_370 )
V_346 -> V_350 |= V_370 ;
memcpy ( V_363 -> V_379 + V_381 , & V_346 -> V_350 , 2 ) ;
F_45 ( V_28 , 4 , L_146 , 0 ) ;
return 0 ;
V_378:
V_24 = 0 ;
memcpy ( V_363 -> V_379 , & V_24 , 4 ) ;
return 0 ;
}
static int F_178 ( struct V_27 * V_28 ,
struct V_78 * V_79 , int V_23 ,
int (* F_179)( struct V_27 * , struct V_139 * ,
unsigned long ) ,
void * V_382 )
{
F_17 ( V_28 , 4 , L_147 ) ;
memcpy ( V_79 -> V_83 , V_383 , V_84 ) ;
memcpy ( F_180 ( V_79 -> V_83 ) ,
& V_28 -> V_384 . V_385 , V_386 ) ;
return F_181 ( V_28 , V_84 + V_23 , V_79 ,
F_179 , V_382 ) ;
}
static int F_182 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_362 * V_363 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_41 ;
int V_4 ;
F_45 ( V_28 , 3 , L_148 , V_60 ) ;
V_79 = F_73 ( V_28 , V_163 ,
V_387 ,
sizeof( struct V_345 ) - sizeof( char ) ,
V_60 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_143 . V_83 . V_369 . V_388 = 0x000F ;
V_81 -> V_83 . V_143 . V_83 . V_369 . V_350 = 0 ;
V_81 -> V_83 . V_143 . V_83 . V_369 . V_343 = 0 ;
V_4 = F_178 ( V_28 , V_79 ,
V_389 + V_390 ,
F_177 , ( void * ) V_363 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 ,
L_149
L_150 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_183 ( struct V_27 * V_28 , char T_7 * V_379 )
{
struct V_362 V_363 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_151 ) ;
if ( ! F_54 ( V_28 ,
V_163 ) ) {
F_17 ( V_28 , 3 , L_152 ) ;
V_4 = - V_165 ;
goto V_14;
}
if ( F_184 ( & V_363 , V_379 , 6 ) ) {
V_4 = - V_391 ;
goto V_14;
}
V_363 . V_379 = F_25 ( V_363 . V_375 , V_392 ) ;
if ( ! V_363 . V_379 ) {
V_4 = - V_82 ;
goto V_14;
}
V_363 . V_376 = V_393 ;
V_4 = F_182 ( V_28 , V_20 , & V_363 ) ;
if ( V_4 ) {
if ( F_185 ( V_379 , V_363 . V_379 , 4 ) )
V_4 = - V_391 ;
goto V_394;
} else {
#ifdef F_53
if ( V_363 . V_37 & V_395 ) {
F_182 ( V_28 , V_21 ,
& V_363 ) ;
}
#endif
if ( F_185 ( V_379 , V_363 . V_379 , V_363 . V_375 ) ) {
F_17 ( V_28 , 4 , L_153 ) ;
V_4 = - V_391 ;
goto V_394;
}
F_17 ( V_28 , 4 , L_154 ) ;
}
V_394:
F_15 ( V_363 . V_379 ) ;
V_14:
return V_4 ;
}
static int F_186 ( struct V_27 * V_28 ,
struct V_396 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_155 ) ;
if ( V_28 -> V_97 . V_334 )
return - V_165 ;
if ( ! F_54 ( V_28 , V_163 ) ) {
return - V_165 ;
}
V_79 = F_73 ( V_28 , V_163 ,
V_397 ,
sizeof( struct V_396 ) ,
V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_75 ( V_28 , V_79 ,
sizeof( struct V_396 ) ,
( unsigned long ) V_53 ,
F_72 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_113 , V_1 ) ;
F_50 ( 2 , L_156
L_157 , V_1 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_187 ( struct V_27 * V_28 ,
struct V_396 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_158 ) ;
if ( V_28 -> V_97 . V_334 )
return - V_165 ;
if ( ! F_54 ( V_28 , V_163 ) ) {
return - V_165 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_79 = F_73 ( V_28 , V_163 ,
V_398 ,
12 ,
V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_75 ( V_28 , V_79 ,
12 , ( unsigned long ) V_1 ,
F_72 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_53 -> V_113 , V_1 ) ;
F_50 ( 2 , L_159
L_160 , V_1 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_188 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_161 ) ;
if ( V_28 -> V_97 . V_334 || ( V_28 -> V_97 . type == V_98 ) )
return - V_165 ;
if ( ! F_54 ( V_28 , V_163 ) ) {
return - V_165 ;
}
V_4 = F_77 ( V_28 , V_163 ,
V_399 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_162
L_150 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_189 ( struct V_210 * V_122 , struct V_400 * V_401 , int V_81 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
struct V_396 V_402 ;
struct V_403 * V_404 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_405 ;
if ( ! F_33 ( V_28 ) )
return - V_405 ;
switch ( V_81 ) {
case V_406 :
if ( ! F_190 ( V_407 ) ) {
V_4 = - V_408 ;
break;
}
V_4 = F_174 ( V_28 , V_401 -> V_409 . V_410 ) ;
break;
case V_411 :
if ( ! F_190 ( V_407 ) ) {
V_4 = - V_408 ;
break;
}
V_4 = F_183 ( V_28 , V_401 -> V_409 . V_412 ) ;
break;
case V_413 :
if ( ! F_190 ( V_407 ) ) {
V_4 = - V_408 ;
break;
}
if ( F_184 ( & V_402 , V_401 -> V_409 . V_412 ,
sizeof( struct V_396 ) ) )
V_4 = - V_391 ;
else
V_4 = F_186 ( V_28 , & V_402 ) ;
break;
case V_414 :
if ( ! F_190 ( V_407 ) ) {
V_4 = - V_408 ;
break;
}
if ( F_184 ( & V_402 , V_401 -> V_409 . V_412 ,
sizeof( struct V_396 ) ) )
V_4 = - V_391 ;
else
V_4 = F_187 ( V_28 , & V_402 ) ;
break;
case V_415 :
if ( ! F_190 ( V_407 ) ) {
V_4 = - V_408 ;
break;
}
V_4 = F_188 ( V_28 ) ;
break;
case V_416 :
V_4 = F_191 ( V_28 , V_401 -> V_409 . V_412 ) ;
break;
case V_417 :
if ( ( V_28 -> V_97 . type == V_418 ||
V_28 -> V_97 . type == V_419 ) &&
! V_28 -> V_97 . V_334 )
return 1 ;
return 0 ;
break;
case V_420 :
V_404 = F_192 ( V_401 ) ;
V_404 -> V_421 = 0 ;
break;
case V_422 :
V_404 = F_192 ( V_401 ) ;
if ( V_404 -> V_421 != 0 )
V_4 = - V_7 ;
else
V_404 -> V_423 = F_193 ( V_122 ,
V_404 -> V_421 ,
V_404 -> V_424 ) ;
break;
case V_425 :
V_4 = F_194 ( V_28 , V_401 -> V_409 . V_412 ) ;
break;
default:
V_4 = - V_165 ;
}
if ( V_4 )
F_45 ( V_28 , 2 , L_163 , V_4 ) ;
return V_4 ;
}
int inline F_195 ( struct V_27 * V_28 , struct V_244 * V_245 )
{
int V_125 = V_426 ;
struct V_427 * V_428 = NULL ;
struct V_429 * V_430 ;
F_111 () ;
V_430 = F_196 ( V_245 ) ;
if ( V_430 )
V_428 = F_197 ( V_430 , V_245 ) ;
if ( V_428 ) {
V_125 = V_428 -> type ;
F_112 () ;
F_198 ( V_428 ) ;
if ( ( V_125 == V_128 ) ||
( V_125 == V_126 ) ||
( V_125 == V_134 ) )
return V_125 ;
else
return V_426 ;
}
F_112 () ;
if ( V_245 -> V_272 == V_253 )
return ( F_199 ( V_245 ) [ 24 ] == 0xff ) ?
V_126 : 0 ;
else if ( V_245 -> V_272 == V_254 )
return ( ( F_199 ( V_245 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_126 : 0 ;
if ( ! memcmp ( V_245 -> V_83 , V_245 -> V_122 -> V_257 , 6 ) )
return V_128 ;
else {
T_5 V_431 ;
V_431 = * ( ( T_5 * ) V_245 -> V_83 ) ;
switch ( V_28 -> V_97 . V_432 ) {
case V_433 :
case V_434 :
if ( ( V_431 == V_435 ) ||
( V_431 == V_436 ) )
return V_126 ;
break;
default:
if ( ( V_431 == V_437 ) ||
( V_431 == V_438 ) )
return V_126 ;
}
}
return V_125 ;
}
static void F_200 ( struct V_27 * V_28 ,
struct V_246 * V_141 , struct V_244 * V_245 )
{
char V_256 [ 16 ] ;
struct V_439 * V_440 ;
F_201 ( V_245 , 14 ) ;
V_28 -> V_122 -> V_269 -> V_270 ( V_245 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_184 , V_28 -> V_122 -> V_184 ,
V_28 -> V_122 -> V_258 ) ;
F_201 ( V_245 , 14 ) ;
V_440 = (struct V_439 * ) V_245 -> V_83 ;
memset ( V_141 , 0 , sizeof( struct V_246 ) ) ;
V_141 -> V_141 . V_252 . V_292 = V_293 ;
V_141 -> V_141 . V_252 . V_267 = 0 ;
V_141 -> V_141 . V_252 . V_161 = V_245 -> V_23 ;
V_141 -> V_141 . V_252 . V_58 = V_133 | V_130 ;
memset ( V_256 , 0 , sizeof( V_256 ) ) ;
V_256 [ 0 ] = 0xfe ;
V_256 [ 1 ] = 0x80 ;
memcpy ( & V_256 [ 8 ] , V_440 -> V_441 , 8 ) ;
memcpy ( V_141 -> V_141 . V_252 . V_271 , V_256 , 16 ) ;
}
static void F_202 ( struct V_27 * V_28 , struct V_246 * V_141 ,
struct V_244 * V_245 , int V_442 , int V_125 )
{
struct V_429 * V_430 ;
memset ( V_141 , 0 , sizeof( struct V_246 ) ) ;
V_141 -> V_141 . V_252 . V_292 = V_293 ;
V_141 -> V_141 . V_252 . V_267 = 0 ;
if ( F_203 ( V_245 ) ) {
if ( ( V_442 == 4 ) || ( V_28 -> V_97 . type == V_98 ) )
V_141 -> V_141 . V_252 . V_267 = V_273 ;
else
V_141 -> V_141 . V_252 . V_267 = V_274 ;
V_141 -> V_141 . V_252 . V_247 = F_204 ( V_245 ) ;
}
V_141 -> V_141 . V_252 . V_161 = V_245 -> V_23 - sizeof( struct V_246 ) ;
F_111 () ;
V_430 = F_196 ( V_245 ) ;
if ( V_442 == 4 ) {
struct V_443 * V_444 = (struct V_443 * ) V_430 ;
T_8 * V_445 = & V_249 ( V_245 ) -> V_256 ;
if ( V_444 -> V_446 )
V_445 = & V_444 -> V_446 ;
V_141 -> V_141 . V_252 . V_58 = F_63 ( V_125 ) ;
memset ( V_141 -> V_141 . V_252 . V_271 , 0 , 12 ) ;
* ( ( T_8 * ) ( & V_141 -> V_141 . V_252 . V_271 [ 12 ] ) ) = * V_445 ;
} else if ( V_442 == 6 ) {
struct V_447 * V_444 = (struct V_447 * ) V_430 ;
struct V_51 * V_445 = & F_205 ( V_245 ) -> V_256 ;
if ( ! F_206 ( & V_444 -> V_448 ) )
V_445 = & V_444 -> V_448 ;
V_141 -> V_141 . V_252 . V_58 = F_64 ( V_125 ) ;
if ( V_28 -> V_97 . type == V_98 )
V_141 -> V_141 . V_252 . V_58 &= ~ V_132 ;
memcpy ( V_141 -> V_141 . V_252 . V_271 , V_445 , 16 ) ;
} else {
if ( ! memcmp ( V_245 -> V_83 + sizeof( struct V_246 ) ,
V_245 -> V_122 -> V_257 , 6 ) ) {
V_141 -> V_141 . V_252 . V_58 = V_129 |
V_132 ;
} else {
V_141 -> V_141 . V_252 . V_58 = ( V_125 == V_126 ) ?
V_127 | V_132 :
V_130 | V_132 ;
}
}
F_112 () ;
}
static inline void F_207 ( struct V_27 * V_28 ,
struct V_246 * V_141 , struct V_244 * V_245 )
{
struct V_248 * V_449 = V_249 ( V_245 ) ;
if ( V_449 -> V_272 == V_450 )
V_141 -> V_141 . V_252 . V_267 |= V_451 ;
V_141 -> V_141 . V_252 . V_267 |= V_276 |
V_275 ;
V_449 -> V_452 = 0 ;
if ( V_28 -> V_43 . V_307 )
V_28 -> V_308 . V_453 ++ ;
}
static void F_208 ( struct V_27 * V_28 ,
struct V_246 * V_454 , struct V_244 * V_245 )
{
struct V_455 * V_141 = (struct V_455 * ) V_454 ;
struct V_456 * V_457 = F_209 ( V_245 ) ;
struct V_248 * V_449 = V_249 ( V_245 ) ;
struct V_458 * V_459 = F_205 ( V_245 ) ;
V_141 -> V_141 . V_141 . V_252 . V_292 = V_460 ;
V_141 -> V_141 . V_141 . V_252 . V_161 = V_245 -> V_23 - sizeof( struct V_455 ) ;
V_141 -> V_461 . V_462 = ( T_2 ) sizeof( struct V_463 ) ;
V_141 -> V_461 . V_464 = 1 ;
V_141 -> V_461 . V_465 = 1 ;
V_141 -> V_461 . V_466 = 1 ;
V_141 -> V_461 . V_467 = 28 ;
V_141 -> V_461 . V_468 = F_210 ( V_245 ) -> V_469 ;
V_141 -> V_461 . V_470 = ( T_2 ) ( V_449 -> V_471 * 4 + V_457 -> V_472 * 4 ) ;
V_141 -> V_461 . V_473 = ( T_2 ) ( V_245 -> V_23 - V_141 -> V_461 . V_470 -
sizeof( struct V_455 ) ) ;
V_457 -> V_452 = 0 ;
if ( V_245 -> V_272 == V_253 ) {
V_459 -> V_473 = 0 ;
V_457 -> V_452 = ~ F_211 ( & V_459 -> V_474 , & V_459 -> V_256 ,
0 , V_475 , 0 ) ;
} else {
V_457 -> V_452 = ~ F_212 ( V_449 -> V_474 , V_449 -> V_256 ,
0 , V_475 , 0 ) ;
V_449 -> V_476 = 0 ;
V_449 -> V_452 = 0 ;
}
}
static inline int F_213 ( struct V_244 * V_245 )
{
unsigned long V_477 = ( unsigned long ) F_209 ( V_245 ) +
F_209 ( V_245 ) -> V_472 * 4 ;
int V_478 = V_245 -> V_23 - ( V_477 - ( unsigned long ) V_245 -> V_83 ) ;
int V_479 = F_214 ( V_477 + V_478 - 1 ) - F_215 ( V_477 ) ;
V_479 += F_216 ( V_245 ) ;
return V_479 ;
}
static int F_217 ( struct V_244 * V_245 , struct V_210 * V_122 )
{
int V_4 ;
T_5 * V_480 ;
struct V_246 * V_141 = NULL ;
int V_481 = 0 ;
int V_482 ;
struct V_27 * V_28 = V_122 -> V_240 ;
struct V_244 * V_483 = NULL ;
int V_442 = F_218 ( V_245 ) ;
int V_125 = F_195 ( V_28 , V_245 ) ;
struct V_484 * V_485 =
V_28 -> V_285 . V_486 [ V_28 -> V_285 . V_487
|| ( V_125 && V_28 -> V_97 . V_488 ) ?
F_219 ( V_28 , V_245 , V_442 , V_125 ) :
V_28 -> V_285 . V_489 ] ;
int V_490 = V_245 -> V_23 ;
bool V_491 ;
int V_492 = - 1 ;
int V_493 ;
if ( ( ( V_28 -> V_97 . type == V_98 ) &&
( ( ( V_28 -> V_43 . V_494 != V_495 ) && ! V_442 ) ||
( ( V_28 -> V_43 . V_494 == V_495 ) &&
( V_245 -> V_272 != V_294 ) ) ) ) ||
V_28 -> V_43 . V_44 )
goto V_496;
if ( ( V_28 -> V_326 != V_329 ) || ! V_28 -> V_497 ) {
V_28 -> V_259 . V_498 ++ ;
goto V_496;
}
if ( ( V_125 == V_128 ) &&
( V_28 -> V_97 . V_172 == 0 ) )
goto V_496;
if ( V_28 -> V_43 . V_307 ) {
V_28 -> V_308 . V_499 ++ ;
V_28 -> V_308 . V_500 = F_145 () ;
}
V_491 = F_220 ( V_245 ) ;
if ( ( V_28 -> V_97 . type == V_98 ) && ( ! V_491 ) &&
( F_210 ( V_245 ) -> V_493 == 0 ) ) {
V_483 = V_245 ;
if ( V_483 -> V_272 == V_294 )
V_492 = 0 ;
else
V_492 = V_501 ;
V_141 = F_221 ( V_502 , V_61 ) ;
if ( ! V_141 )
goto V_496;
V_481 ++ ;
} else {
V_483 = F_222 ( V_245 , sizeof( struct V_455 )
+ V_503 ) ;
if ( ! V_483 )
goto V_496;
}
if ( V_28 -> V_97 . type == V_98 ) {
if ( V_492 < 0 )
F_201 ( V_483 , V_501 ) ;
} else {
if ( V_442 == 4 ) {
F_201 ( V_483 , V_501 ) ;
}
if ( V_442 != 4 && F_203 ( V_483 ) ) {
F_223 ( V_483 , V_503 ) ;
F_224 ( V_483 , V_483 -> V_83 + 4 , 4 ) ;
F_225 ( V_483 , 4 ,
V_483 -> V_83 + 8 , 4 ) ;
F_225 ( V_483 , 8 ,
V_483 -> V_83 + 12 , 4 ) ;
V_480 = ( T_5 * ) ( V_483 -> V_83 + 12 ) ;
* V_480 = F_133 ( V_222 ) ;
* ( V_480 + 1 ) = F_108 ( F_204 ( V_483 ) ) ;
}
}
F_226 ( V_122 ) ;
if ( V_491 ) {
if ( F_213 ( V_483 ) + 1 > 16 ) {
if ( F_227 ( V_483 ) )
goto V_496;
if ( V_28 -> V_43 . V_307 )
V_28 -> V_308 . V_504 ++ ;
}
}
if ( V_491 && ( V_125 == V_426 ) ) {
V_141 = (struct V_246 * ) F_223 ( V_483 ,
sizeof( struct V_455 ) ) ;
memset ( V_141 , 0 , sizeof( struct V_455 ) ) ;
F_202 ( V_28 , V_141 , V_483 , V_442 , V_125 ) ;
F_208 ( V_28 , V_141 , V_483 ) ;
V_481 ++ ;
} else {
if ( V_492 < 0 ) {
V_141 = (struct V_246 * ) F_223 ( V_483 ,
sizeof( struct V_246 ) ) ;
F_202 ( V_28 , V_141 , V_483 , V_442 ,
V_125 ) ;
} else {
if ( V_483 -> V_272 == V_294 )
F_200 ( V_28 , V_141 , V_483 ) ;
else {
F_202 ( V_28 , V_141 , V_483 , V_442 ,
V_125 ) ;
V_141 -> V_141 . V_252 . V_161 = V_483 -> V_23 - V_492 ;
}
}
if ( V_245 -> V_277 == V_505 )
F_207 ( V_28 , V_141 , V_483 ) ;
}
V_482 = F_228 ( V_28 , V_483 , V_481 ) ;
if ( ! V_482 ) {
if ( V_492 >= 0 )
F_229 ( V_502 , V_141 ) ;
goto V_496;
}
V_481 += V_482 ;
V_493 = F_210 ( V_483 ) -> V_493 ;
if ( V_28 -> V_97 . type != V_98 ) {
int V_23 ;
if ( V_491 )
V_23 = ( ( unsigned long ) F_209 ( V_483 ) +
F_209 ( V_483 ) -> V_472 * 4 ) -
( unsigned long ) V_483 -> V_83 ;
else
V_23 = sizeof( struct V_506 ) ;
if ( F_230 ( V_483 , & V_141 , V_23 ) )
goto V_496;
V_4 = F_231 ( V_28 , V_485 , V_483 , V_141 ,
V_481 ) ;
} else
V_4 = F_232 ( V_28 , V_485 , V_483 , V_141 ,
V_481 , V_492 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_259 . V_507 ++ ;
V_28 -> V_259 . V_490 += V_490 ;
if ( V_483 != V_245 )
F_141 ( V_245 ) ;
if ( V_28 -> V_43 . V_307 ) {
if ( V_491 ) {
V_28 -> V_308 . V_508 += V_490 ;
V_28 -> V_308 . V_509 ++ ;
}
if ( V_493 ) {
V_28 -> V_308 . V_510 ++ ;
V_28 -> V_308 . V_511 += V_493 + 1 ;
}
}
V_4 = V_512 ;
} else {
if ( V_492 >= 0 )
F_229 ( V_502 , V_141 ) ;
if ( V_4 == - V_513 ) {
if ( V_483 != V_245 )
F_141 ( V_483 ) ;
return V_514 ;
} else
goto V_496;
}
F_233 ( V_122 ) ;
if ( V_28 -> V_43 . V_307 )
V_28 -> V_308 . V_515 += F_145 () -
V_28 -> V_308 . V_500 ;
return V_4 ;
V_496:
V_28 -> V_259 . V_516 ++ ;
V_28 -> V_259 . V_517 ++ ;
if ( ( V_483 != V_245 ) && V_483 )
F_141 ( V_483 ) ;
F_141 ( V_245 ) ;
F_233 ( V_122 ) ;
return V_512 ;
}
static int F_234 ( struct V_210 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_164 ) ;
if ( V_28 -> V_326 == V_329 )
return V_4 ;
if ( V_28 -> V_326 != V_330 )
return - V_405 ;
V_28 -> V_83 . V_326 = V_327 ;
V_28 -> V_326 = V_329 ;
F_235 ( V_122 ) ;
if ( F_236 ( V_28 -> V_83 . V_313 , 0 ) >= 0 ) {
F_237 ( & V_28 -> V_297 ) ;
F_152 ( & V_28 -> V_297 ) ;
} else
V_4 = - V_183 ;
return V_4 ;
}
static int F_238 ( struct V_210 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
F_17 ( V_28 , 5 , L_165 ) ;
if ( F_129 ( V_28 , V_242 ) ) {
F_17 ( V_28 , 3 , L_166 ) ;
return - V_518 ;
}
return F_234 ( V_122 ) ;
}
static int F_161 ( struct V_210 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
F_17 ( V_28 , 4 , L_167 ) ;
F_239 ( V_122 ) ;
if ( V_28 -> V_326 == V_329 ) {
V_28 -> V_326 = V_330 ;
F_240 ( & V_28 -> V_297 ) ;
}
return 0 ;
}
static T_9 F_241 ( struct V_210 * V_122 ,
T_9 V_179 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
if ( ! F_54 ( V_28 , V_155 ) )
V_179 &= ~ V_519 ;
if ( ! F_54 ( V_28 , V_181 ) )
V_179 &= ~ V_182 ;
if ( ! F_54 ( V_28 , V_150 ) )
V_179 &= ~ V_180 ;
return V_179 ;
}
static int F_242 ( struct V_210 * V_122 ,
T_9 V_179 )
{
struct V_27 * V_28 = V_122 -> V_240 ;
T_9 V_520 = V_122 -> V_179 ^ V_179 ;
if ( ! ( V_520 & V_180 ) )
return 0 ;
if ( V_28 -> V_326 == V_332 ||
V_28 -> V_326 == V_521 )
return 0 ;
return F_88 ( V_28 , V_179 & V_180 ? 1 : 0 ) ;
}
static int F_243 ( struct V_427 * V_428 )
{
V_428 -> V_522 = V_523 ;
memcpy ( V_428 -> V_524 , L_117 , 6 ) ;
V_428 -> V_525 = V_428 -> V_526 -> V_527 ;
return 0 ;
}
static int
F_244 ( struct V_210 * V_122 , struct V_528 * V_529 )
{
if ( V_529 -> V_530 -> V_531 == V_532 )
V_529 -> V_533 = F_243 ;
return 0 ;
}
static int F_245 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_97 . type == V_418 ||
V_28 -> V_97 . type == V_419 ) {
if ( ( V_28 -> V_97 . V_432 == V_434 ) ||
( V_28 -> V_97 . V_432 == V_433 ) ) {
F_246 ( L_168 ) ;
return - V_405 ;
} else {
V_28 -> V_122 = F_247 ( 0 ) ;
if ( ! V_28 -> V_122 )
return - V_405 ;
V_28 -> V_122 -> V_534 = & V_535 ;
F_98 ( V_28 ) ;
if ( ! ( V_28 -> V_97 . V_186 & V_190 ) )
V_28 -> V_122 -> V_536 = V_28 -> V_97 . V_186 &
0xffff ;
if ( ! V_28 -> V_97 . V_334 ) {
V_28 -> V_122 -> V_537 = V_538 |
V_180 | V_519 |
V_182 ;
V_28 -> V_122 -> V_179 = V_180 ;
}
}
} else if ( V_28 -> V_97 . type == V_98 ) {
V_28 -> V_122 = F_248 ( 0 , L_169 , V_539 ,
V_540 ) ;
if ( ! V_28 -> V_122 )
return - V_405 ;
V_28 -> V_122 -> V_58 |= V_541 ;
V_28 -> V_122 -> V_534 = & V_542 ;
V_4 = F_96 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_43 . V_543 [ 0 ] )
memcpy ( V_28 -> V_122 -> V_544 , V_28 -> V_43 . V_543 , 9 ) ;
} else
return - V_405 ;
V_28 -> V_122 -> V_240 = V_28 ;
V_28 -> V_122 -> V_545 = V_546 ;
V_28 -> V_122 -> V_547 = V_28 -> V_97 . V_548 ;
V_28 -> V_122 -> V_549 = & V_550 ;
V_28 -> V_122 -> V_179 |= V_551 |
V_552 |
V_553 ;
F_249 ( V_28 -> V_122 ) ;
V_28 -> V_122 -> V_554 = 15 * V_555 ;
F_250 ( V_28 -> V_122 , & V_28 -> V_121 -> V_122 ) ;
F_251 ( V_28 -> V_122 , & V_28 -> V_297 , F_143 , V_556 ) ;
return F_252 ( V_28 -> V_122 ) ;
}
static int F_253 ( struct V_557 * V_121 )
{
struct V_27 * V_28 = F_254 ( & V_121 -> V_122 ) ;
F_255 ( & V_121 -> V_122 ) ;
V_28 -> V_43 . V_323 = 0 ;
V_28 -> V_97 . V_558 = 0 ;
return 0 ;
}
static void F_256 ( struct V_557 * V_559 )
{
struct V_27 * V_28 = F_254 ( & V_559 -> V_122 ) ;
F_257 ( & V_559 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_560 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_559 -> V_326 == V_561 )
F_259 ( V_559 ) ;
if ( V_28 -> V_122 ) {
F_260 ( V_28 -> V_122 ) ;
V_28 -> V_122 = NULL ;
}
F_38 ( V_28 , 0 ) ;
F_55 ( V_28 ) ;
return;
}
static int F_261 ( struct V_557 * V_121 , int V_324 )
{
struct V_27 * V_28 = F_254 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
enum V_562 V_563 ;
F_262 ( & V_28 -> V_564 ) ;
F_262 ( & V_28 -> V_565 ) ;
F_66 ( V_136 , 2 , L_170 ) ;
F_142 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
V_563 = V_28 -> V_326 ;
V_4 = F_263 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_136 , 2 , L_171 , V_4 ) ;
V_4 = - V_405 ;
goto V_566;
}
if ( ! V_28 -> V_122 && F_245 ( V_28 ) ) {
V_4 = - V_405 ;
goto V_566;
}
if ( F_265 ( V_28 , V_567 ) ) {
if ( V_28 -> V_97 . V_558 &&
F_266 ( V_28 , V_568 ) )
V_28 -> V_97 . V_558 = 0 ;
} else
V_28 -> V_97 . V_558 = 0 ;
V_28 -> V_326 = V_331 ;
memset ( & V_28 -> V_288 , 0 , sizeof( struct V_569 ) ) ;
F_267 ( V_28 ) ;
F_66 ( V_136 , 2 , L_172 ) ;
V_4 = F_268 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_136 , 2 , L_173 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_174 ) ;
V_28 -> V_497 = 0 ;
goto V_570;
}
V_4 = - V_405 ;
goto V_566;
} else
V_28 -> V_497 = 1 ;
V_570:
V_4 = F_65 ( V_28 ) ;
if ( V_4 )
F_264 ( V_136 , 2 , L_171 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_92 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_136 , 2 , L_175 , V_4 ) ;
goto V_566;
}
V_4 = F_49 ( V_28 ) ;
if ( V_4 )
F_264 ( V_136 , 2 , L_176 , V_4 ) ;
V_4 = F_52 ( V_28 ) ;
if ( V_4 )
F_264 ( V_136 , 2 , L_177 , V_4 ) ;
}
F_239 ( V_28 -> V_122 ) ;
V_4 = F_269 ( V_28 ) ;
if ( V_4 ) {
F_264 ( V_136 , 2 , L_178 , V_4 ) ;
V_4 = - V_405 ;
goto V_566;
}
V_28 -> V_326 = V_330 ;
F_160 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_497 )
F_270 ( V_28 -> V_122 ) ;
else
F_271 ( V_28 -> V_122 ) ;
if ( V_563 == V_521 ) {
F_162 () ;
if ( V_324 )
F_234 ( V_28 -> V_122 ) ;
else
F_272 ( V_28 -> V_122 ) ;
F_131 ( V_28 -> V_122 ) ;
F_164 () ;
}
F_273 ( V_28 ) ;
F_274 ( & V_121 -> V_122 . V_571 , V_572 ) ;
F_275 ( & V_28 -> V_565 ) ;
F_275 ( & V_28 -> V_564 ) ;
return 0 ;
V_566:
F_159 ( V_28 , 0 ) ;
F_276 ( F_277 ( V_28 ) ) ;
F_276 ( F_278 ( V_28 ) ) ;
F_276 ( F_279 ( V_28 ) ) ;
F_280 ( F_277 ( V_28 ) ) ;
if ( V_563 == V_521 )
V_28 -> V_326 = V_521 ;
else
V_28 -> V_326 = V_332 ;
F_275 ( & V_28 -> V_565 ) ;
F_275 ( & V_28 -> V_564 ) ;
return V_4 ;
}
static int F_281 ( struct V_557 * V_121 )
{
return F_261 ( V_121 , 0 ) ;
}
static int F_282 ( struct V_557 * V_559 ,
int V_324 )
{
struct V_27 * V_28 = F_254 ( & V_559 -> V_122 ) ;
int V_4 = 0 , V_573 = 0 , V_574 = 0 ;
enum V_562 V_563 ;
F_262 ( & V_28 -> V_564 ) ;
F_262 ( & V_28 -> V_565 ) ;
F_66 ( V_136 , 3 , L_179 ) ;
F_142 ( V_136 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_122 && F_283 ( V_28 -> V_122 ) )
F_271 ( V_28 -> V_122 ) ;
V_563 = V_28 -> V_326 ;
if ( ( ! V_324 && V_28 -> V_97 . V_558 ) || V_28 -> V_97 . V_558 == 2 ) {
F_266 ( V_28 , V_575 ) ;
V_28 -> V_97 . V_558 = 1 ;
}
F_159 ( V_28 , V_324 ) ;
if ( ( V_28 -> V_43 . V_494 == V_495 ) && V_28 -> V_122 ) {
F_162 () ;
F_284 ( V_576 , V_28 -> V_122 ) ;
F_164 () ;
}
V_4 = F_276 ( F_277 ( V_28 ) ) ;
V_573 = F_276 ( F_278 ( V_28 ) ) ;
V_574 = F_276 ( F_279 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_573 ) ? V_573 : V_574 ;
if ( V_4 )
F_264 ( V_136 , 2 , L_173 , V_4 ) ;
F_280 ( F_277 ( V_28 ) ) ;
if ( V_563 == V_329 )
V_28 -> V_326 = V_521 ;
F_274 ( & V_559 -> V_122 . V_571 , V_572 ) ;
F_275 ( & V_28 -> V_565 ) ;
F_275 ( & V_28 -> V_564 ) ;
return 0 ;
}
static int F_259 ( struct V_557 * V_559 )
{
return F_282 ( V_559 , 0 ) ;
}
static int F_285 ( void * V_577 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_577 ;
F_17 ( V_28 , 2 , L_180 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_286 ( V_28 , V_242 ) )
return 0 ;
F_17 ( V_28 , 2 , L_181 ) ;
F_62 ( & V_28 -> V_121 -> V_122 ,
L_182 ) ;
F_287 ( V_28 ) ;
F_282 ( V_28 -> V_121 , 1 ) ;
V_4 = F_261 ( V_28 -> V_121 , 1 ) ;
if ( ! V_4 )
F_67 ( & V_28 -> V_121 -> V_122 ,
L_183 ) ;
else {
F_288 ( V_28 ) ;
F_62 ( & V_28 -> V_121 -> V_122 , L_184
L_185 ) ;
}
F_289 ( V_28 ) ;
F_290 ( V_28 , V_242 ) ;
F_291 ( V_28 , V_242 ) ;
return 0 ;
}
static void F_292 ( struct V_557 * V_121 )
{
struct V_27 * V_28 = F_254 ( & V_121 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
if ( ( V_121 -> V_326 == V_561 ) && V_28 -> V_97 . V_558 )
F_266 ( V_28 , V_575 ) ;
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
F_280 ( F_277 ( V_28 ) ) ;
}
static int F_293 ( struct V_557 * V_121 )
{
struct V_27 * V_28 = F_254 ( & V_121 -> V_122 ) ;
if ( V_28 -> V_122 )
F_294 ( V_28 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
F_258 ( V_28 -> V_560 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_121 -> V_326 == V_578 )
return 0 ;
if ( V_28 -> V_326 == V_329 ) {
if ( V_28 -> V_97 . V_558 )
F_266 ( V_28 , V_575 ) ;
F_282 ( V_28 -> V_121 , 1 ) ;
} else
F_282 ( V_28 -> V_121 , 0 ) ;
return 0 ;
}
static int F_295 ( struct V_557 * V_121 )
{
struct V_27 * V_28 = F_254 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
if ( V_121 -> V_326 == V_578 )
goto V_14;
if ( V_28 -> V_326 == V_521 ) {
V_4 = F_261 ( V_28 -> V_121 , 1 ) ;
if ( V_4 ) {
F_162 () ;
F_163 ( V_28 -> V_122 ) ;
F_164 () ;
}
} else
V_4 = F_261 ( V_28 -> V_121 , 0 ) ;
V_14:
F_160 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_122 )
F_296 ( V_28 -> V_122 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_184
L_185 ) ;
return V_4 ;
}
static int F_297 ( struct V_27 * V_28 ,
struct V_80 * V_81 )
{
return 1 ;
}
static int F_298 ( struct V_579 * V_580 ,
unsigned long V_581 , void * V_577 )
{
struct V_232 * V_233 = (struct V_232 * ) V_577 ;
struct V_210 * V_122 = (struct V_210 * ) V_233 -> V_582 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_299 ( V_122 ) != & V_583 )
return V_584 ;
V_28 = F_158 ( V_122 ) ;
if ( ! V_28 )
return V_584 ;
F_17 ( V_28 , 3 , L_186 ) ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_233 -> V_236 ;
V_2 -> V_36 . V_47 . V_48 = V_233 -> V_237 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_581 ) {
case V_585 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_586 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_584 ;
}
static int F_300 ( struct V_579 * V_580 ,
unsigned long V_581 , void * V_577 )
{
struct V_238 * V_233 = (struct V_238 * ) V_577 ;
struct V_210 * V_122 = (struct V_210 * ) V_233 -> V_587 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_158 ( V_122 ) ;
if ( ! V_28 )
return V_584 ;
F_17 ( V_28 , 3 , L_187 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return V_584 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_233 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_233 -> V_239 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_581 ) {
case V_585 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_586 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_584 ;
}
static int F_301 ( void )
{
int V_4 ;
F_66 ( V_136 , 5 , L_188 ) ;
V_4 = F_302 ( & V_588 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_53
V_4 = F_303 ( & V_589 ) ;
if ( V_4 ) {
F_304 ( & V_588 ) ;
return V_4 ;
}
#else
F_305 ( L_189 ) ;
#endif
return 0 ;
}
static void F_306 ( void )
{
F_66 ( V_136 , 5 , L_190 ) ;
F_307 ( F_304 ( & V_588 ) ) ;
#ifdef F_53
F_307 ( F_308 ( & V_589 ) ) ;
#endif
}
static int T_10 F_309 ( void )
{
int V_4 = 0 ;
F_246 ( L_191 ) ;
V_4 = F_301 () ;
return V_4 ;
}
static void T_11 F_310 ( void )
{
F_306 () ;
F_246 ( L_192 ) ;
}
