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
static int F_73 ( struct V_27 * V_28 ,
enum V_157 V_158 , T_2 V_159 )
{
int V_4 ;
struct V_78 * V_79 ;
F_17 ( V_28 , 4 , L_48 ) ;
V_79 = F_74 ( V_28 , V_158 , V_159 ,
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
F_17 ( V_28 , 3 , L_49 ) ;
if ( ! F_54 ( V_28 , V_160 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_50 ,
F_51 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_77 ( V_28 , V_160 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_51 ,
F_51 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_78 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_52 ) ;
if ( ! F_54 ( V_28 , V_161 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_53 ,
F_51 ( V_28 ) ) ;
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_161 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_54 ,
F_51 ( V_28 ) ) ;
} else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_55 ) ;
return V_4 ;
}
static int F_79 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_56 ) ;
if ( ! F_54 ( V_28 , V_163 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_57 ,
F_51 ( V_28 ) ) ;
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_163 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 ,
L_58 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_59 ) ;
if ( ! F_54 ( V_28 , V_164 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_60 , F_51 ( V_28 ) ) ;
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_165 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_61 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_62 ) ;
}
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_63 ) ;
if ( ! F_54 ( V_28 , V_166 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_64 ,
F_51 ( V_28 ) ) ;
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_166 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_65 ,
F_51 ( V_28 ) ) ;
} else {
F_67 ( & V_28 -> V_121 -> V_122 , L_66 ) ;
V_28 -> V_122 -> V_58 |= V_167 ;
}
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_67 ) ;
if ( V_28 -> V_97 . type == V_98 )
goto V_14;
V_4 = F_83 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_68 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_77 ( V_28 , V_108 ,
V_152 , 3 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_68 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_73 ( V_28 , V_108 ,
V_152 ) ;
if ( V_4 ) {
F_84 ( & V_28 -> V_121 -> V_122 ,
L_68 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_73 ( V_28 , V_168 ,
V_152 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_69 ,
F_51 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_67 ( & V_28 -> V_121 -> V_122 , L_70 ) ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_17 ( V_28 , 3 , L_71 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_72 , F_51 ( V_28 ) ) ;
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
F_17 ( V_28 , 3 , L_73 ) ;
V_28 -> V_97 . V_169 = 0 ;
if ( ! F_54 ( V_28 , V_170 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_74 ,
F_51 ( V_28 ) ) ;
V_4 = - V_162 ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_170 ,
V_152 , 0 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_75
L_76 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_77 ( V_28 , V_170 ,
V_171 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_77 ,
F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_169 = V_172 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_78 ) ;
V_4 = F_77 ( V_28 , V_170 ,
V_173 , 1 ) ;
if ( V_4 ) {
F_62 ( & V_28 -> V_121 -> V_122 , L_79
L_80 , F_51 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_97 . V_169 = V_174 ;
V_14:
if ( V_28 -> V_97 . V_169 )
V_28 -> V_122 -> V_58 |= V_175 ;
else
V_28 -> V_122 -> V_58 &= ~ V_175 ;
return V_4 ;
}
static void F_87 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_81 ) ;
if ( F_54 ( V_28 , V_150 )
&& ( V_28 -> V_122 -> V_176 & V_177 ) )
F_88 ( V_28 , 1 ) ;
}
static void F_89 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_82 ) ;
F_90 ( V_28 ) ;
}
static int F_91 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_83 ) ;
if ( ! F_54 ( V_28 , V_178 ) ) {
F_67 ( & V_28 -> V_121 -> V_122 ,
L_84 ,
F_51 ( V_28 ) ) ;
V_4 = - V_162 ;
} else {
V_4 = F_77 ( V_28 , V_178 ,
V_152 , 0 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_85
L_86 ,
F_51 ( V_28 ) ) ;
else
F_67 ( & V_28 -> V_121 -> V_122 ,
L_87 ) ;
}
if ( V_4 )
V_28 -> V_122 -> V_176 &= ~ V_179 ;
return V_4 ;
}
static int F_92 ( struct V_27 * V_28 )
{
F_17 ( V_28 , 3 , L_88 ) ;
if ( F_93 ( V_28 , 0 ) )
return - V_180 ;
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
memcpy ( V_28 -> V_122 -> V_181 ,
V_81 -> V_83 . V_182 . V_183 , V_184 ) ;
else
F_95 ( V_28 -> V_122 -> V_181 ) ;
return 0 ;
}
static int F_96 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_89 ) ;
V_79 = F_41 ( V_28 , V_185 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_182 . V_183 [ 6 ] ) =
V_28 -> V_97 . V_183 ;
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
V_28 -> V_97 . V_183 = * ( ( T_2 * )
& V_81 -> V_83 . V_182 . V_183 [ 6 ] ) ;
else {
V_28 -> V_97 . V_183 = V_186 |
V_187 ;
F_62 ( & V_28 -> V_121 -> V_122 , L_90
L_91 ) ;
}
return 0 ;
}
static int F_98 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_92 ) ;
if ( ! F_54 ( V_28 , V_108 ) ) {
V_28 -> V_97 . V_183 = V_186 |
V_187 ;
return 0 ;
}
V_79 = F_41 ( V_28 , V_185 ,
V_21 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
* ( ( T_2 * ) & V_81 -> V_83 . V_182 . V_183 [ 6 ] ) =
V_28 -> V_97 . V_183 ;
V_4 = F_42 ( V_28 , V_79 , F_97 , NULL ) ;
return V_4 ;
}
static int
F_99 ( struct V_27 * V_28 , struct V_139 * V_140 ,
unsigned long V_83 )
{
struct V_80 * V_81 ;
T_2 V_4 ;
F_66 ( V_136 , 2 , L_93 ) ;
V_81 = (struct V_80 * ) V_83 ;
V_4 = V_81 -> V_141 . V_142 ;
if ( V_4 )
F_45 ( V_28 , 2 , L_94 , V_4 ) ;
switch ( V_81 -> V_83 . V_188 . V_189 ) {
case V_190 :
break;
case V_191 :
switch ( V_4 ) {
case 0 :
case V_192 :
V_28 -> V_97 . V_193 = V_194 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_95
L_96 ) ;
break;
default:
break;
}
break;
case V_195 :
switch ( V_4 ) {
case 0 :
V_28 -> V_97 . V_193 = V_196 ;
F_67 ( & V_28 -> V_121 -> V_122 , L_95
L_97 ) ;
break;
case V_197 :
F_62 ( & V_28 -> V_121 -> V_122 , L_98
L_99
L_100 ) ;
break;
case V_198 :
F_62 ( & V_28 -> V_121 -> V_122 , L_101
L_102
L_103 ) ;
break;
default:
break;
}
break;
default:
F_50 ( 2 , L_104 ,
V_81 -> V_83 . V_188 . V_189 , F_51 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_100 ( struct V_27 * V_28 , enum V_199 V_200 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
F_66 ( V_136 , 2 , L_105 ) ;
V_79 = F_41 ( V_28 , V_201 , 0 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_188 . V_202 = 16 ;
V_81 -> V_83 . V_188 . V_203 = V_204 ;
V_81 -> V_83 . V_188 . type = V_205 ;
V_81 -> V_83 . V_188 . V_189 = V_200 ;
return F_42 ( V_28 , V_79 , F_99 , NULL ) ;
}
static void F_101 ( T_4 V_206 , char * V_86 ,
struct V_207 * V_122 )
{
F_102 ( V_206 , V_86 ) ;
}
static void F_103 ( struct V_27 * V_28 , struct V_208 * V_209 )
{
struct V_29 * V_206 ;
struct V_210 * V_211 ;
char V_1 [ V_212 ] ;
F_17 ( V_28 , 4 , L_106 ) ;
for ( V_211 = F_104 ( V_209 -> V_213 ) ; V_211 != NULL ;
V_211 = F_104 ( V_211 -> V_214 ) ) {
F_101 ( V_211 -> V_215 , V_1 , V_209 -> V_122 ) ;
V_206 = F_24 ( V_20 ) ;
if ( ! V_206 )
continue;
V_206 -> V_36 . V_47 . V_2 = V_211 -> V_215 ;
memcpy ( V_206 -> V_86 , V_1 , V_87 ) ;
V_206 -> V_46 = 1 ;
if ( ! F_23 ( V_28 , V_206 ) )
F_15 ( V_206 ) ;
}
}
static void F_105 ( struct V_27 * V_28 )
{
struct V_208 * V_216 ;
T_5 V_217 ;
F_17 ( V_28 , 4 , L_107 ) ;
if ( ! F_54 ( V_28 , V_164 ) )
return;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_207 * V_218 ;
V_218 = F_107 ( V_28 -> V_122 , F_108 ( V_219 ) ,
V_217 ) ;
if ( V_218 == NULL ||
! ( V_218 -> V_58 & V_220 ) )
continue;
V_216 = F_109 ( V_218 ) ;
if ( ! V_216 )
continue;
F_103 ( V_28 , V_216 ) ;
}
}
static void F_110 ( struct V_27 * V_28 )
{
struct V_208 * V_209 ;
F_17 ( V_28 , 4 , L_108 ) ;
F_111 () ;
V_209 = F_109 ( V_28 -> V_122 ) ;
if ( V_209 == NULL )
goto V_221;
F_103 ( V_28 , V_209 ) ;
F_105 ( V_28 ) ;
V_221:
F_112 () ;
}
static void F_113 ( struct V_27 * V_28 , struct V_222 * V_223 )
{
struct V_29 * V_206 ;
struct V_224 * V_225 ;
char V_1 [ V_212 ] ;
F_17 ( V_28 , 4 , L_109 ) ;
for ( V_225 = V_223 -> V_213 ; V_225 != NULL ; V_225 = V_225 -> V_71 ) {
F_114 ( & V_225 -> V_226 , V_1 , V_223 -> V_122 , 0 ) ;
V_206 = F_24 ( V_21 ) ;
if ( ! V_206 )
continue;
V_206 -> V_46 = 1 ;
memcpy ( V_206 -> V_86 , V_1 , V_87 ) ;
memcpy ( & V_206 -> V_36 . V_49 . V_2 , & V_225 -> V_226 . V_227 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_206 ) )
F_15 ( V_206 ) ;
}
}
static void F_115 ( struct V_27 * V_28 )
{
struct V_222 * V_216 ;
T_5 V_217 ;
F_17 ( V_28 , 4 , L_110 ) ;
if ( ! F_54 ( V_28 , V_164 ) )
return;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_207 * V_218 ;
V_218 = F_107 ( V_28 -> V_122 , F_108 ( V_219 ) ,
V_217 ) ;
if ( V_218 == NULL ||
! ( V_218 -> V_58 & V_220 ) )
continue;
V_216 = F_116 ( V_218 ) ;
if ( ! V_216 )
continue;
F_117 ( & V_216 -> V_228 ) ;
F_113 ( V_28 , V_216 ) ;
F_118 ( & V_216 -> V_228 ) ;
F_119 ( V_216 ) ;
}
}
static void F_120 ( struct V_27 * V_28 )
{
struct V_222 * V_223 ;
F_17 ( V_28 , 4 , L_111 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return ;
V_223 = F_116 ( V_28 -> V_122 ) ;
if ( V_223 == NULL )
return;
F_111 () ;
F_117 ( & V_223 -> V_228 ) ;
F_113 ( V_28 , V_223 ) ;
F_115 ( V_28 ) ;
F_118 ( & V_223 -> V_228 ) ;
F_112 () ;
F_119 ( V_223 ) ;
}
static void F_121 ( struct V_27 * V_28 ,
unsigned short V_217 )
{
struct V_208 * V_216 ;
struct V_229 * V_230 ;
struct V_29 * V_2 ;
struct V_207 * V_218 ;
F_17 ( V_28 , 4 , L_112 ) ;
V_218 = F_107 ( V_28 -> V_122 , F_108 ( V_219 ) , V_217 ) ;
if ( ! V_218 )
return;
V_216 = F_122 ( V_218 ) ;
if ( ! V_216 )
return;
for ( V_230 = V_216 -> V_231 ; V_230 ; V_230 = V_230 -> V_232 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_230 -> V_233 ;
V_2 -> V_36 . V_47 . V_48 = V_230 -> V_234 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_123 ( V_216 ) ;
}
static void F_124 ( struct V_27 * V_28 ,
unsigned short V_217 )
{
#ifdef F_53
struct V_222 * V_223 ;
struct V_235 * V_230 ;
struct V_29 * V_2 ;
struct V_207 * V_218 ;
F_17 ( V_28 , 4 , L_113 ) ;
V_218 = F_107 ( V_28 -> V_122 , F_108 ( V_219 ) , V_217 ) ;
if ( ! V_218 )
return;
V_223 = F_116 ( V_218 ) ;
if ( ! V_223 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_230 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_230 -> V_236 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_119 ( V_223 ) ;
#endif
}
static void F_125 ( struct V_27 * V_28 ,
unsigned short V_217 )
{
F_111 () ;
F_121 ( V_28 , V_217 ) ;
F_124 ( V_28 , V_217 ) ;
F_112 () ;
}
static int F_126 ( struct V_207 * V_122 ,
T_6 V_19 , T_5 V_217 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
F_127 ( V_217 , V_28 -> V_238 ) ;
return 0 ;
}
static int F_128 ( struct V_207 * V_122 ,
T_6 V_19 , T_5 V_217 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
unsigned long V_58 ;
F_45 ( V_28 , 4 , L_114 , V_217 ) ;
if ( F_129 ( V_28 , V_239 ) ) {
F_17 ( V_28 , 3 , L_115 ) ;
return 0 ;
}
F_21 ( & V_28 -> V_240 , V_58 ) ;
F_125 ( V_28 , V_217 ) ;
F_130 ( V_217 , V_28 -> V_238 ) ;
F_22 ( & V_28 -> V_240 , V_58 ) ;
F_131 ( V_28 -> V_122 ) ;
return 0 ;
}
static inline int F_132 ( struct V_27 * V_28 ,
struct V_241 * V_242 , struct V_243 * V_141 ,
unsigned short * V_244 )
{
T_6 V_60 ;
struct V_245 * V_246 ;
unsigned char V_247 [ V_212 ] ;
int V_248 = 0 ;
if ( ! ( V_141 -> V_141 . V_249 . V_58 & V_132 ) ) {
V_60 = F_108 ( ( V_141 -> V_141 . V_249 . V_58 & V_133 ) ? V_250 :
V_251 ) ;
switch ( V_141 -> V_141 . V_249 . V_58 & V_252 ) {
case V_127 :
switch ( V_60 ) {
#ifdef F_53
case F_133 ( V_250 ) :
F_114 ( (struct V_51 * )
V_242 -> V_83 + 24 ,
V_247 , V_28 -> V_122 , 0 ) ;
break;
#endif
case F_133 ( V_251 ) :
V_246 = (struct V_245 * ) V_242 -> V_83 ;
F_102 ( V_246 -> V_253 , V_247 ) ;
break;
default:
memcpy ( V_247 , V_28 -> V_122 -> V_254 ,
V_28 -> V_122 -> V_255 ) ;
}
V_28 -> V_256 . V_257 ++ ;
V_242 -> V_258 = V_259 ;
break;
case V_129 :
memcpy ( V_247 , V_28 -> V_122 -> V_254 ,
V_28 -> V_122 -> V_255 ) ;
V_28 -> V_256 . V_257 ++ ;
V_242 -> V_258 = V_260 ;
break;
case V_130 :
case V_135 :
case V_261 :
default:
if ( V_28 -> V_43 . V_44 )
V_242 -> V_258 = V_262 ;
else
V_242 -> V_258 = V_263 ;
memcpy ( V_247 , V_28 -> V_122 -> V_181 ,
V_28 -> V_122 -> V_255 ) ;
}
if ( V_141 -> V_141 . V_249 . V_264 & V_265 )
V_28 -> V_122 -> V_266 -> V_267 ( V_242 , V_28 -> V_122 , V_60 ,
V_247 , & V_141 -> V_141 . V_249 . V_268 [ 2 ] ,
V_28 -> V_122 -> V_255 ) ;
else
V_28 -> V_122 -> V_266 -> V_267 ( V_242 , V_28 -> V_122 , V_60 ,
V_247 , L_116 , V_28 -> V_122 -> V_255 ) ;
}
V_242 -> V_269 = F_134 ( V_242 , V_28 -> V_122 ) ;
if ( V_141 -> V_141 . V_249 . V_264 &
( V_270 | V_271 ) ) {
* V_244 = ( V_141 -> V_141 . V_249 . V_264 & V_270 ) ?
V_141 -> V_141 . V_249 . V_244 : * ( ( T_5 * ) & V_141 -> V_141 . V_249 . V_268 [ 12 ] ) ;
V_248 = 1 ;
}
if ( V_28 -> V_122 -> V_176 & V_177 ) {
if ( ( V_141 -> V_141 . V_249 . V_264 &
( V_272 |
V_273 ) ) ==
( V_272 |
V_273 ) )
V_242 -> V_274 = V_275 ;
else
V_242 -> V_274 = V_276 ;
} else
V_242 -> V_274 = V_276 ;
return V_248 ;
}
static int F_135 ( struct V_27 * V_28 ,
int V_277 , int * V_278 )
{
int V_279 = 0 ;
struct V_241 * V_242 ;
struct V_243 * V_141 ;
T_2 V_280 = 0 ;
int V_248 ;
unsigned int V_23 ;
T_2 V_281 ;
* V_278 = 0 ;
F_136 ( ! V_277 ) ;
while ( V_277 ) {
V_242 = F_137 ( V_28 ,
& V_28 -> V_282 . V_283 -> V_284 [ V_28 -> V_285 . V_286 ] ,
& V_28 -> V_285 . V_287 , & V_28 -> V_285 . V_288 , & V_141 ) ;
if ( ! V_242 ) {
* V_278 = 1 ;
break;
}
V_242 -> V_122 = V_28 -> V_122 ;
switch ( V_141 -> V_141 . V_249 . V_289 ) {
case V_290 :
V_281 = * ( T_2 * ) V_242 -> V_83 ;
if ( ( V_28 -> V_97 . type == V_98 ) &&
( V_281 == V_291 ) ) {
V_242 -> V_269 = V_291 ;
V_242 -> V_258 = V_263 ;
V_242 -> V_292 = V_293 ;
V_242 -> V_122 = V_28 -> V_122 ;
V_23 = V_242 -> V_23 ;
V_28 -> V_122 -> V_266 -> V_267 ( V_242 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_181 , L_116 ,
V_28 -> V_122 -> V_255 ) ;
F_138 ( V_242 ) ;
} else {
V_248 = F_132 ( V_28 , V_242 , V_141 ,
& V_280 ) ;
V_23 = V_242 -> V_23 ;
if ( V_248 && ! V_28 -> V_43 . V_44 )
F_139 ( V_242 ,
F_108 ( V_219 ) , V_280 ) ;
F_140 ( & V_28 -> V_294 , V_242 ) ;
}
break;
case V_295 :
V_242 -> V_258 = V_263 ;
V_242 -> V_269 = F_134 ( V_242 , V_242 -> V_122 ) ;
V_23 = V_242 -> V_23 ;
F_138 ( V_242 ) ;
break;
default:
F_141 ( V_242 ) ;
F_17 ( V_28 , 3 , L_117 ) ;
F_142 ( V_296 , 3 , V_141 , V_297 ) ;
continue;
}
V_279 ++ ;
V_277 -- ;
V_28 -> V_256 . V_298 ++ ;
V_28 -> V_256 . V_299 += V_23 ;
}
return V_279 ;
}
static int F_143 ( struct V_300 * V_294 , int V_277 )
{
struct V_27 * V_28 = F_144 ( V_294 , struct V_27 , V_294 ) ;
int V_279 = 0 ;
struct V_301 * V_302 ;
int V_278 ;
int V_303 = V_277 ;
if ( V_28 -> V_43 . V_304 ) {
V_28 -> V_305 . V_306 ++ ;
V_28 -> V_305 . V_307 = F_145 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_285 . V_308 ) {
V_28 -> V_285 . V_309 = 0 ;
V_28 -> V_285 . V_308 = F_146 (
V_28 -> V_83 . V_310 , 0 , & V_28 -> V_285 . V_286 ,
& V_28 -> V_285 . V_309 ) ;
if ( V_28 -> V_285 . V_308 <= 0 ) {
V_28 -> V_285 . V_308 = 0 ;
break;
}
V_28 -> V_285 . V_287 =
& V_28 -> V_282 . V_283 -> V_284 [ V_28 -> V_285 . V_286 ]
. V_302 -> V_311 [ 0 ] ;
V_28 -> V_285 . V_288 = 0 ;
}
while ( V_28 -> V_285 . V_308 ) {
V_302 = & V_28 -> V_282 . V_283 -> V_284 [ V_28 -> V_285 . V_286 ] ;
if ( ! ( V_28 -> V_285 . V_309 &&
F_147 ( V_28 , V_302 -> V_302 ,
V_28 -> V_285 . V_309 , L_118 ) ) )
V_279 += F_135 (
V_28 , V_303 , & V_278 ) ;
else
V_278 = 1 ;
if ( V_278 ) {
if ( V_28 -> V_43 . V_304 )
V_28 -> V_305 . V_312 ++ ;
F_148 ( V_28 ,
V_302 -> V_313 ) ;
F_149 ( V_28 , V_28 -> V_285 . V_286 ) ;
V_28 -> V_285 . V_308 -- ;
if ( V_28 -> V_285 . V_308 ) {
V_28 -> V_285 . V_286 =
( V_28 -> V_285 . V_286 + 1 ) %
V_314 ;
V_28 -> V_285 . V_287 =
& V_28 -> V_282 . V_283
-> V_284 [ V_28 -> V_285 . V_286 ]
. V_302 -> V_311 [ 0 ] ;
V_28 -> V_285 . V_288 = 0 ;
}
}
if ( V_279 >= V_277 )
goto V_14;
else
V_303 = V_277 - V_279 ;
}
}
F_150 ( V_294 ) ;
if ( F_151 ( V_28 -> V_83 . V_310 , 0 ) )
F_152 ( & V_28 -> V_294 ) ;
V_14:
if ( V_28 -> V_43 . V_304 )
V_28 -> V_305 . V_315 += F_145 () -
V_28 -> V_305 . V_307 ;
return V_279 ;
}
static int F_153 ( struct V_207 * V_122 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_217 ;
F_106 (vid, card->active_vlans, VLAN_N_VID) {
struct V_207 * V_218 ;
F_111 () ;
V_218 = F_107 ( V_28 -> V_122 , F_108 ( V_219 ) ,
V_217 ) ;
F_112 () ;
if ( V_218 == V_122 ) {
V_4 = V_316 ;
break;
}
}
if ( V_4 && ! ( F_154 ( V_122 ) -> V_237 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_155 ( struct V_207 * V_122 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_156 ( & V_317 . V_318 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_122 == V_122 ) {
V_4 = V_319 ;
break;
}
V_4 = F_153 ( V_122 , V_28 ) ;
if ( V_4 )
break;
}
F_157 ( & V_317 . V_318 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_158 ( struct V_207 * V_122 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_155 ( V_122 ) ;
if ( V_4 == V_319 )
V_28 = V_122 -> V_237 ;
else if ( V_4 == V_316 )
V_28 = F_154 ( V_122 ) -> V_237 ;
if ( V_28 && V_28 -> V_43 . V_320 )
V_28 = NULL ;
if ( V_28 )
F_45 ( V_28 , 4 , L_119 , V_4 ) ;
return V_28 ;
}
static void F_159 ( struct V_27 * V_28 , int V_321 )
{
F_66 ( V_136 , 2 , L_120 ) ;
F_142 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
F_160 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_97 . V_193 == V_196 ) )
F_100 ( V_28 , V_191 ) ;
if ( V_28 -> V_322 . V_323 == V_324 &&
V_28 -> V_325 . V_323 == V_324 &&
( V_28 -> V_323 == V_326 ) ) {
if ( V_321 )
F_161 ( V_28 -> V_122 ) ;
else {
F_162 () ;
F_163 ( V_28 -> V_122 ) ;
F_164 () ;
}
V_28 -> V_323 = V_327 ;
}
if ( V_28 -> V_323 == V_327 ) {
F_38 ( V_28 , 1 ) ;
F_165 ( V_28 ) ;
V_28 -> V_323 = V_328 ;
}
if ( V_28 -> V_323 == V_328 ) {
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
F_168 ( V_28 ) ;
V_28 -> V_323 = V_329 ;
}
if ( V_28 -> V_323 == V_329 ) {
F_169 ( & V_28 -> V_322 ) ;
F_169 ( & V_28 -> V_325 ) ;
}
}
static void
F_170 ( struct V_27 * V_28 )
{
struct V_207 * V_122 = V_28 -> V_122 ;
if ( ( ( V_122 -> V_58 & V_330 ) &&
( V_28 -> V_97 . V_193 == V_196 ) ) ||
( ! ( V_122 -> V_58 & V_330 ) &&
( V_28 -> V_97 . V_193 == V_194 ) ) )
return;
if ( V_28 -> V_97 . V_331 ) {
if ( F_70 ( V_28 , V_332 ) )
F_171 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_70 ( V_28 , V_333 ) ) {
if ( V_122 -> V_58 & V_330 ) {
F_17 ( V_28 , 3 , L_121 ) ;
F_100 ( V_28 , V_195 ) ;
} else {
F_17 ( V_28 , 3 , L_122 ) ;
F_100 ( V_28 , V_191 ) ;
}
}
}
static void F_131 ( struct V_207 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
F_17 ( V_28 , 3 , L_123 ) ;
if ( F_172 ( V_28 , V_239 ) &&
( V_28 -> V_323 != V_326 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_110 ( V_28 ) ;
#ifdef F_53
F_120 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_70 ( V_28 , V_332 ) )
return;
}
F_170 ( V_28 ) ;
}
static const char * F_173 ( int * V_4 )
{
switch ( * V_4 ) {
case V_334 :
* V_4 = - V_180 ;
return L_124 ;
case V_335 :
* V_4 = - V_162 ;
return L_125 ;
case V_336 :
* V_4 = - V_7 ;
return L_126 ;
case V_337 :
* V_4 = - V_162 ;
return L_127 ;
case V_338 :
* V_4 = - V_339 ;
return L_128 ;
default:
return L_129 ;
}
}
static int F_174 ( struct V_27 * V_28 , int V_340 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_130 ) ;
if ( V_28 -> V_97 . V_331 )
return - V_162 ;
if ( ! F_54 ( V_28 , V_160 ) ) {
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_160 ,
V_341 ,
V_340 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_131
L_132 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static T_4 F_175 ( struct V_27 * V_28 ,
struct V_342 * V_343 ,
struct V_344 * type , T_1 V_345 )
{
T_4 V_4 ;
T_1 V_346 ;
V_346 = V_343 -> V_347 == 5 ;
if ( type -> V_348 == V_349 ) {
F_17 ( V_28 , 4 , L_133 ) ;
if ( V_345 ) {
V_4 = V_346 ? sizeof( struct V_350 ) :
sizeof( struct V_351 ) ;
} else {
V_4 = V_346 ? sizeof( struct V_352 ) :
sizeof( struct V_353 ) ;
}
} else if ( type -> V_348 == V_354 ) {
F_17 ( V_28 , 4 , L_134 ) ;
if ( V_345 ) {
V_4 = V_346 ?
sizeof( struct V_355 ) :
sizeof( struct V_356 ) ;
} else {
V_4 = V_346 ?
sizeof( struct V_357 ) :
sizeof( struct V_358 ) ;
}
} else {
F_17 ( V_28 , 4 , L_135 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_176 ( struct V_344 * type , T_2 V_60 )
{
return ( type -> V_348 == V_349 && V_60 == V_20 ) ||
( type -> V_348 == V_354 && V_60 == V_21 ) ;
}
static int F_177 ( struct V_27 * V_28 ,
struct V_139 * V_140 , unsigned long V_83 )
{
struct V_80 * V_81 ;
struct V_342 * V_343 ;
struct V_359 * V_360 ;
int V_24 ;
int V_361 ;
int V_362 ;
int V_363 ;
T_1 V_364 ;
F_17 ( V_28 , 3 , L_136 ) ;
V_360 = (struct V_359 * ) V_140 -> V_365 ;
V_81 = (struct V_80 * ) V_83 ;
F_45 ( V_28 , 4 , L_137 , V_81 -> V_141 . V_144 ) ;
if ( V_81 -> V_141 . V_142 ) {
F_17 ( V_28 , 4 , L_138 ) ;
F_45 ( V_28 , 4 , L_137 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_142 ) {
V_81 -> V_141 . V_142 = V_81 -> V_83 . V_143 . V_141 . V_142 ;
F_17 ( V_28 , 4 , L_139 ) ;
F_45 ( V_28 , 4 , L_137 , V_81 -> V_141 . V_142 ) ;
return 0 ;
}
V_343 = & V_81 -> V_83 . V_143 . V_83 . V_366 ;
F_45 ( V_28 , 4 , L_140 , V_343 -> V_340 ) ;
V_364 = ( V_360 -> V_37 & V_367 ) > 0 ;
V_363 = V_364 ? V_368 : 0 ;
V_362 = 0 ;
for ( V_361 = 0 ; V_361 < V_343 -> V_340 ; ++ V_361 ) {
char * V_369 ;
T_4 V_370 ;
struct V_344 * V_371 ;
V_369 = & V_343 -> V_83 + V_362 ;
V_371 = & ( (struct V_352 * ) V_369 ) -> type ;
if ( ! F_176 ( V_371 , V_81 -> V_141 . V_144 ) ) {
F_17 ( V_28 , 4 , L_141 ) ;
F_45 ( V_28 , 4 , L_137 , V_371 -> V_348 ) ;
break;
}
V_370 = F_175 ( V_28 , V_343 , V_371 ,
V_364 ) ;
F_45 ( V_28 , 5 , L_142 , V_370 ) ;
if ( ! V_370 )
break;
if ( ( V_360 -> V_372 - V_360 -> V_373 ) < V_370 ) {
F_45 ( V_28 , 4 , L_143 , - V_82 ) ;
V_81 -> V_141 . V_142 = V_374 ;
goto V_375;
}
memcpy ( V_360 -> V_376 + V_360 -> V_373 ,
& V_343 -> V_83 + V_362 + V_363 ,
V_370 ) ;
V_362 += V_370 + V_363 ;
V_360 -> V_373 += V_370 ;
++ V_360 -> V_340 ;
}
if ( V_81 -> V_83 . V_143 . V_141 . V_377 <
V_81 -> V_83 . V_143 . V_141 . V_378 )
return 1 ;
F_45 ( V_28 , 4 , L_144 , V_360 -> V_340 ) ;
memcpy ( V_360 -> V_376 , & V_360 -> V_340 , 4 ) ;
if ( V_360 -> V_37 & V_367 )
V_343 -> V_347 |= V_367 ;
memcpy ( V_360 -> V_376 + V_379 , & V_343 -> V_347 , 2 ) ;
F_45 ( V_28 , 4 , L_145 , 0 ) ;
return 0 ;
V_375:
V_24 = 0 ;
memcpy ( V_360 -> V_376 , & V_24 , 4 ) ;
return 0 ;
}
static int F_178 ( struct V_27 * V_28 ,
struct V_78 * V_79 , int V_23 ,
int (* F_179)( struct V_27 * , struct V_139 * ,
unsigned long ) ,
void * V_380 )
{
F_17 ( V_28 , 4 , L_146 ) ;
memcpy ( V_79 -> V_83 , V_381 , V_84 ) ;
memcpy ( F_180 ( V_79 -> V_83 ) ,
& V_28 -> V_382 . V_383 , V_384 ) ;
return F_181 ( V_28 , V_84 + V_23 , V_79 ,
F_179 , V_380 ) ;
}
static int F_182 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_359 * V_360 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
int V_41 ;
int V_4 ;
F_45 ( V_28 , 3 , L_147 , V_60 ) ;
V_79 = F_74 ( V_28 , V_160 ,
V_385 ,
sizeof( struct V_342 )
- sizeof( char ) ,
V_60 ) ;
if ( ! V_79 )
return - V_82 ;
V_81 = (struct V_80 * ) ( V_79 -> V_83 + V_84 ) ;
V_81 -> V_83 . V_143 . V_83 . V_366 . V_386 = 0x000F ;
V_81 -> V_83 . V_143 . V_83 . V_366 . V_347 = 0 ;
V_81 -> V_83 . V_143 . V_83 . V_366 . V_340 = 0 ;
V_4 = F_178 ( V_28 , V_79 ,
V_387 + V_388 ,
F_177 , ( void * ) V_360 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 ,
L_148
L_149 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_183 ( struct V_27 * V_28 , char T_7 * V_376 )
{
struct V_359 V_360 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_150 ) ;
if ( ! F_54 ( V_28 ,
V_160 ) ) {
F_17 ( V_28 , 3 , L_151 ) ;
V_4 = - V_162 ;
goto V_14;
}
if ( F_184 ( & V_360 , V_376 , 6 ) ) {
V_4 = - V_389 ;
goto V_14;
}
V_360 . V_376 = F_25 ( V_360 . V_372 , V_390 ) ;
if ( ! V_360 . V_376 ) {
V_4 = - V_82 ;
goto V_14;
}
V_360 . V_373 = V_391 ;
V_4 = F_182 ( V_28 , V_20 , & V_360 ) ;
if ( V_4 ) {
if ( F_185 ( V_376 , V_360 . V_376 , 4 ) )
V_4 = - V_389 ;
goto V_392;
} else {
#ifdef F_53
if ( V_360 . V_37 & V_393 ) {
F_182 ( V_28 , V_21 ,
& V_360 ) ;
}
#endif
if ( F_185 ( V_376 , V_360 . V_376 , V_360 . V_372 ) ) {
F_17 ( V_28 , 4 , L_152 ) ;
V_4 = - V_389 ;
goto V_392;
}
F_17 ( V_28 , 4 , L_153 ) ;
}
V_392:
F_15 ( V_360 . V_376 ) ;
V_14:
return V_4 ;
}
static int F_186 ( struct V_27 * V_28 ,
struct V_394 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_154 ) ;
if ( V_28 -> V_97 . V_331 )
return - V_162 ;
if ( ! F_54 ( V_28 , V_160 ) ) {
return - V_162 ;
}
V_79 = F_74 ( V_28 , V_160 ,
V_395 ,
sizeof( struct V_394 ) ,
V_20 ) ;
if ( ! V_79 )
return - V_82 ;
V_4 = F_75 ( V_28 , V_79 ,
sizeof( struct V_394 ) ,
( unsigned long ) V_53 ,
F_72 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_113 , V_1 ) ;
F_50 ( 2 , L_155
L_156 , V_1 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_187 ( struct V_27 * V_28 ,
struct V_394 * V_53 )
{
struct V_78 * V_79 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_157 ) ;
if ( V_28 -> V_97 . V_331 )
return - V_162 ;
if ( ! F_54 ( V_28 , V_160 ) ) {
return - V_162 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_79 = F_74 ( V_28 , V_160 ,
V_396 ,
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
F_50 ( 2 , L_158
L_159 , V_1 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_188 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_160 ) ;
if ( V_28 -> V_97 . V_331 || ( V_28 -> V_97 . type == V_98 ) )
return - V_162 ;
if ( ! F_54 ( V_28 , V_160 ) ) {
return - V_162 ;
}
V_4 = F_77 ( V_28 , V_160 ,
V_397 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_50 ( 2 , L_161
L_149 , F_51 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_189 ( struct V_207 * V_122 , struct V_398 * V_399 , int V_81 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
struct V_394 V_400 ;
struct V_401 * V_402 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_403 ;
if ( ! F_33 ( V_28 ) )
return - V_403 ;
switch ( V_81 ) {
case V_404 :
if ( ! F_190 ( V_405 ) ) {
V_4 = - V_406 ;
break;
}
V_4 = F_174 ( V_28 , V_399 -> V_407 . V_408 ) ;
break;
case V_409 :
if ( ! F_190 ( V_405 ) ) {
V_4 = - V_406 ;
break;
}
V_4 = F_183 ( V_28 , V_399 -> V_407 . V_410 ) ;
break;
case V_411 :
if ( ! F_190 ( V_405 ) ) {
V_4 = - V_406 ;
break;
}
if ( F_184 ( & V_400 , V_399 -> V_407 . V_410 ,
sizeof( struct V_394 ) ) )
V_4 = - V_389 ;
else
V_4 = F_186 ( V_28 , & V_400 ) ;
break;
case V_412 :
if ( ! F_190 ( V_405 ) ) {
V_4 = - V_406 ;
break;
}
if ( F_184 ( & V_400 , V_399 -> V_407 . V_410 ,
sizeof( struct V_394 ) ) )
V_4 = - V_389 ;
else
V_4 = F_187 ( V_28 , & V_400 ) ;
break;
case V_413 :
if ( ! F_190 ( V_405 ) ) {
V_4 = - V_406 ;
break;
}
V_4 = F_188 ( V_28 ) ;
break;
case V_414 :
V_4 = F_191 ( V_28 , V_399 -> V_407 . V_410 ) ;
break;
case V_415 :
if ( ( V_28 -> V_97 . type == V_416 ||
V_28 -> V_97 . type == V_417 ) &&
! V_28 -> V_97 . V_331 )
return 1 ;
return 0 ;
break;
case V_418 :
V_402 = F_192 ( V_399 ) ;
V_402 -> V_419 = 0 ;
break;
case V_420 :
V_402 = F_192 ( V_399 ) ;
if ( V_402 -> V_419 != 0 )
V_4 = - V_7 ;
else
V_402 -> V_421 = F_193 ( V_122 ,
V_402 -> V_419 ,
V_402 -> V_422 ) ;
break;
case V_423 :
V_4 = F_194 ( V_28 , V_399 -> V_407 . V_410 ) ;
break;
default:
V_4 = - V_162 ;
}
if ( V_4 )
F_45 ( V_28 , 2 , L_162 , V_4 ) ;
return V_4 ;
}
int inline F_195 ( struct V_27 * V_28 , struct V_241 * V_242 )
{
int V_125 = V_424 ;
struct V_425 * V_426 = NULL ;
struct V_427 * V_428 ;
F_111 () ;
V_428 = F_196 ( V_242 ) ;
if ( V_428 )
V_426 = F_197 ( V_428 , V_242 ) ;
if ( V_426 ) {
V_125 = V_426 -> type ;
F_112 () ;
F_198 ( V_426 ) ;
if ( ( V_125 == V_128 ) ||
( V_125 == V_126 ) ||
( V_125 == V_134 ) )
return V_125 ;
else
return V_424 ;
}
F_112 () ;
if ( V_242 -> V_269 == V_250 )
return ( F_199 ( V_242 ) [ 24 ] == 0xff ) ?
V_126 : 0 ;
else if ( V_242 -> V_269 == V_251 )
return ( ( F_199 ( V_242 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_126 : 0 ;
if ( ! memcmp ( V_242 -> V_83 , V_242 -> V_122 -> V_254 , 6 ) )
return V_128 ;
else {
T_5 V_429 ;
V_429 = * ( ( T_5 * ) V_242 -> V_83 ) ;
switch ( V_28 -> V_97 . V_430 ) {
case V_431 :
case V_432 :
if ( ( V_429 == V_433 ) ||
( V_429 == V_434 ) )
return V_126 ;
break;
default:
if ( ( V_429 == V_435 ) ||
( V_429 == V_436 ) )
return V_126 ;
}
}
return V_125 ;
}
static void F_200 ( struct V_27 * V_28 ,
struct V_243 * V_141 , struct V_241 * V_242 )
{
char V_253 [ 16 ] ;
struct V_437 * V_438 ;
F_201 ( V_242 , 14 ) ;
V_28 -> V_122 -> V_266 -> V_267 ( V_242 , V_28 -> V_122 , 0 ,
V_28 -> V_122 -> V_181 , V_28 -> V_122 -> V_181 ,
V_28 -> V_122 -> V_255 ) ;
F_201 ( V_242 , 14 ) ;
V_438 = (struct V_437 * ) V_242 -> V_83 ;
memset ( V_141 , 0 , sizeof( struct V_243 ) ) ;
V_141 -> V_141 . V_249 . V_289 = V_290 ;
V_141 -> V_141 . V_249 . V_264 = 0 ;
V_141 -> V_141 . V_249 . V_439 = V_242 -> V_23 ;
V_141 -> V_141 . V_249 . V_58 = V_133 | V_130 ;
memset ( V_253 , 0 , sizeof( V_253 ) ) ;
V_253 [ 0 ] = 0xfe ;
V_253 [ 1 ] = 0x80 ;
memcpy ( & V_253 [ 8 ] , V_438 -> V_440 , 8 ) ;
memcpy ( V_141 -> V_141 . V_249 . V_268 , V_253 , 16 ) ;
}
static void F_202 ( struct V_27 * V_28 , struct V_243 * V_141 ,
struct V_241 * V_242 , int V_441 , int V_125 )
{
struct V_427 * V_428 ;
memset ( V_141 , 0 , sizeof( struct V_243 ) ) ;
V_141 -> V_141 . V_249 . V_289 = V_290 ;
V_141 -> V_141 . V_249 . V_264 = 0 ;
if ( F_203 ( V_242 ) ) {
if ( ( V_441 == 4 ) || ( V_28 -> V_97 . type == V_98 ) )
V_141 -> V_141 . V_249 . V_264 = V_270 ;
else
V_141 -> V_141 . V_249 . V_264 = V_271 ;
V_141 -> V_141 . V_249 . V_244 = F_204 ( V_242 ) ;
}
V_141 -> V_141 . V_249 . V_439 = V_242 -> V_23 - sizeof( struct V_243 ) ;
F_111 () ;
V_428 = F_196 ( V_242 ) ;
if ( V_441 == 4 ) {
struct V_442 * V_443 = (struct V_442 * ) V_428 ;
T_8 * V_444 = & V_246 ( V_242 ) -> V_253 ;
if ( V_443 -> V_445 )
V_444 = & V_443 -> V_445 ;
V_141 -> V_141 . V_249 . V_58 = F_63 ( V_125 ) ;
memset ( V_141 -> V_141 . V_249 . V_268 , 0 , 12 ) ;
* ( ( T_8 * ) ( & V_141 -> V_141 . V_249 . V_268 [ 12 ] ) ) = * V_444 ;
} else if ( V_441 == 6 ) {
struct V_446 * V_443 = (struct V_446 * ) V_428 ;
struct V_51 * V_444 = & F_205 ( V_242 ) -> V_253 ;
if ( ! F_206 ( & V_443 -> V_447 ) )
V_444 = & V_443 -> V_447 ;
V_141 -> V_141 . V_249 . V_58 = F_64 ( V_125 ) ;
if ( V_28 -> V_97 . type == V_98 )
V_141 -> V_141 . V_249 . V_58 &= ~ V_132 ;
memcpy ( V_141 -> V_141 . V_249 . V_268 , V_444 , 16 ) ;
} else {
if ( ! memcmp ( V_242 -> V_83 + sizeof( struct V_243 ) ,
V_242 -> V_122 -> V_254 , 6 ) ) {
V_141 -> V_141 . V_249 . V_58 = V_129 |
V_132 ;
} else {
V_141 -> V_141 . V_249 . V_58 = ( V_125 == V_126 ) ?
V_127 | V_132 :
V_130 | V_132 ;
}
}
F_112 () ;
}
static inline void F_207 ( struct V_27 * V_28 ,
struct V_243 * V_141 , struct V_241 * V_242 )
{
struct V_245 * V_448 = V_246 ( V_242 ) ;
if ( V_448 -> V_269 == V_449 )
V_141 -> V_141 . V_249 . V_264 |= V_450 ;
V_141 -> V_141 . V_249 . V_264 |= V_273 |
V_272 ;
V_448 -> V_451 = 0 ;
if ( V_28 -> V_43 . V_304 )
V_28 -> V_305 . V_452 ++ ;
}
static void F_208 ( struct V_27 * V_28 ,
struct V_243 * V_453 , struct V_241 * V_242 )
{
struct V_454 * V_141 = (struct V_454 * ) V_453 ;
struct V_455 * V_456 = F_209 ( V_242 ) ;
struct V_245 * V_448 = V_246 ( V_242 ) ;
struct V_457 * V_458 = F_205 ( V_242 ) ;
V_141 -> V_141 . V_141 . V_249 . V_289 = V_459 ;
V_141 -> V_141 . V_141 . V_249 . V_439 = V_242 -> V_23 - sizeof( struct V_454 ) ;
V_141 -> V_460 . V_461 = ( T_2 ) sizeof( struct V_462 ) ;
V_141 -> V_460 . V_463 = 1 ;
V_141 -> V_460 . V_464 = 1 ;
V_141 -> V_460 . V_465 = 1 ;
V_141 -> V_460 . V_466 = 28 ;
V_141 -> V_460 . V_467 = F_210 ( V_242 ) -> V_468 ;
V_141 -> V_460 . V_469 = ( T_2 ) ( V_448 -> V_470 * 4 + V_456 -> V_471 * 4 ) ;
V_141 -> V_460 . V_472 = ( T_2 ) ( V_242 -> V_23 - V_141 -> V_460 . V_469 -
sizeof( struct V_454 ) ) ;
V_456 -> V_451 = 0 ;
if ( V_242 -> V_269 == V_250 ) {
V_458 -> V_472 = 0 ;
V_456 -> V_451 = ~ F_211 ( & V_458 -> V_473 , & V_458 -> V_253 ,
0 , V_474 , 0 ) ;
} else {
V_456 -> V_451 = ~ F_212 ( V_448 -> V_473 , V_448 -> V_253 ,
0 , V_474 , 0 ) ;
V_448 -> V_475 = 0 ;
V_448 -> V_451 = 0 ;
}
}
static inline int F_213 ( struct V_241 * V_242 )
{
unsigned long V_476 = ( unsigned long ) F_209 ( V_242 ) +
F_209 ( V_242 ) -> V_471 * 4 ;
int V_477 = F_214 ( V_242 ) - ( V_476 - ( unsigned long ) V_242 -> V_83 ) ;
int V_478 = F_215 ( V_476 + V_477 - 1 ) - F_216 ( V_476 ) ;
V_478 += F_217 ( V_242 ) ;
return V_478 ;
}
static int F_218 ( struct V_241 * V_242 , struct V_207 * V_122 )
{
int V_4 ;
T_5 * V_479 ;
struct V_243 * V_141 = NULL ;
int V_480 = 0 ;
int V_481 ;
struct V_27 * V_28 = V_122 -> V_237 ;
struct V_241 * V_482 = NULL ;
int V_441 = F_219 ( V_242 ) ;
int V_125 = F_195 ( V_28 , V_242 ) ;
struct V_483 * V_484 =
V_28 -> V_282 . V_485 [ V_28 -> V_282 . V_486
|| ( V_125 && V_28 -> V_97 . V_487 ) ?
F_220 ( V_28 , V_242 , V_441 , V_125 ) :
V_28 -> V_282 . V_488 ] ;
int V_489 = V_242 -> V_23 ;
bool V_490 ;
int V_491 = - 1 ;
int V_492 ;
if ( ( ( V_28 -> V_97 . type == V_98 ) &&
( ( ( V_28 -> V_43 . V_493 != V_494 ) && ! V_441 ) ||
( ( V_28 -> V_43 . V_493 == V_494 ) &&
( V_242 -> V_269 != V_291 ) ) ) ) ||
V_28 -> V_43 . V_44 )
goto V_495;
if ( ( V_28 -> V_323 != V_326 ) || ! V_28 -> V_496 ) {
V_28 -> V_256 . V_497 ++ ;
goto V_495;
}
if ( ( V_125 == V_128 ) &&
( V_28 -> V_97 . V_169 == 0 ) )
goto V_495;
if ( V_28 -> V_43 . V_304 ) {
V_28 -> V_305 . V_498 ++ ;
V_28 -> V_305 . V_499 = F_145 () ;
}
V_490 = F_221 ( V_242 ) ;
if ( ( V_28 -> V_97 . type == V_98 ) && ( ! V_490 ) &&
( F_210 ( V_242 ) -> V_492 == 0 ) ) {
V_482 = V_242 ;
if ( V_482 -> V_269 == V_291 )
V_491 = 0 ;
else
V_491 = V_500 ;
V_141 = F_222 ( V_501 , V_61 ) ;
if ( ! V_141 )
goto V_495;
V_480 ++ ;
} else {
V_482 = F_223 ( V_242 , sizeof( struct V_454 )
+ V_502 ) ;
if ( ! V_482 )
goto V_495;
}
if ( V_28 -> V_97 . type == V_98 ) {
if ( V_491 < 0 )
F_201 ( V_482 , V_500 ) ;
} else {
if ( V_441 == 4 ) {
F_201 ( V_482 , V_500 ) ;
}
if ( V_441 != 4 && F_203 ( V_482 ) ) {
F_224 ( V_482 , V_502 ) ;
F_225 ( V_482 , V_482 -> V_83 + 4 , 4 ) ;
F_226 ( V_482 , 4 ,
V_482 -> V_83 + 8 , 4 ) ;
F_226 ( V_482 , 8 ,
V_482 -> V_83 + 12 , 4 ) ;
V_479 = ( T_5 * ) ( V_482 -> V_83 + 12 ) ;
* V_479 = F_133 ( V_219 ) ;
* ( V_479 + 1 ) = F_108 ( F_204 ( V_482 ) ) ;
}
}
F_227 ( V_122 ) ;
if ( V_490 ) {
if ( F_213 ( V_482 ) + 1 > 16 ) {
if ( F_228 ( V_482 ) )
goto V_495;
if ( V_28 -> V_43 . V_304 )
V_28 -> V_305 . V_503 ++ ;
}
}
if ( V_490 && ( V_125 == V_424 ) ) {
V_141 = (struct V_243 * ) F_224 ( V_482 ,
sizeof( struct V_454 ) ) ;
memset ( V_141 , 0 , sizeof( struct V_454 ) ) ;
F_202 ( V_28 , V_141 , V_482 , V_441 , V_125 ) ;
F_208 ( V_28 , V_141 , V_482 ) ;
V_480 ++ ;
} else {
if ( V_491 < 0 ) {
V_141 = (struct V_243 * ) F_224 ( V_482 ,
sizeof( struct V_243 ) ) ;
F_202 ( V_28 , V_141 , V_482 , V_441 ,
V_125 ) ;
} else {
if ( V_482 -> V_269 == V_291 )
F_200 ( V_28 , V_141 , V_482 ) ;
else {
F_202 ( V_28 , V_141 , V_482 , V_441 ,
V_125 ) ;
V_141 -> V_141 . V_249 . V_439 = V_482 -> V_23 - V_491 ;
}
}
if ( V_242 -> V_274 == V_504 )
F_207 ( V_28 , V_141 , V_482 ) ;
}
V_481 = F_229 ( V_28 , V_482 , V_480 ) ;
if ( ! V_481 ) {
if ( V_491 >= 0 )
F_230 ( V_501 , V_141 ) ;
goto V_495;
}
V_480 += V_481 ;
V_492 = F_210 ( V_482 ) -> V_492 ;
if ( V_28 -> V_97 . type != V_98 ) {
int V_23 ;
if ( V_490 )
V_23 = ( ( unsigned long ) F_209 ( V_482 ) +
F_209 ( V_482 ) -> V_471 * 4 ) -
( unsigned long ) V_482 -> V_83 ;
else
V_23 = sizeof( struct V_505 ) ;
if ( F_231 ( V_482 , & V_141 , V_23 ) )
goto V_495;
V_4 = F_232 ( V_28 , V_484 , V_482 , V_141 ,
V_480 ) ;
} else
V_4 = F_233 ( V_28 , V_484 , V_482 , V_141 ,
V_480 , V_491 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_256 . V_506 ++ ;
V_28 -> V_256 . V_489 += V_489 ;
if ( V_482 != V_242 )
F_141 ( V_242 ) ;
if ( V_28 -> V_43 . V_304 ) {
if ( V_490 ) {
V_28 -> V_305 . V_507 += V_489 ;
V_28 -> V_305 . V_508 ++ ;
}
if ( V_492 ) {
V_28 -> V_305 . V_509 ++ ;
V_28 -> V_305 . V_510 += V_492 + 1 ;
}
}
V_4 = V_511 ;
} else {
if ( V_491 >= 0 )
F_230 ( V_501 , V_141 ) ;
if ( V_4 == - V_512 ) {
if ( V_482 != V_242 )
F_141 ( V_482 ) ;
return V_513 ;
} else
goto V_495;
}
F_234 ( V_122 ) ;
if ( V_28 -> V_43 . V_304 )
V_28 -> V_305 . V_514 += F_145 () -
V_28 -> V_305 . V_499 ;
return V_4 ;
V_495:
V_28 -> V_256 . V_515 ++ ;
V_28 -> V_256 . V_516 ++ ;
if ( ( V_482 != V_242 ) && V_482 )
F_141 ( V_482 ) ;
F_141 ( V_242 ) ;
F_234 ( V_122 ) ;
return V_511 ;
}
static int F_235 ( struct V_207 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_163 ) ;
if ( V_28 -> V_323 == V_326 )
return V_4 ;
if ( V_28 -> V_323 != V_327 )
return - V_403 ;
V_28 -> V_83 . V_323 = V_324 ;
V_28 -> V_323 = V_326 ;
F_236 ( V_122 ) ;
if ( F_237 ( V_28 -> V_83 . V_310 , 0 ) >= 0 ) {
F_238 ( & V_28 -> V_294 ) ;
F_152 ( & V_28 -> V_294 ) ;
} else
V_4 = - V_180 ;
return V_4 ;
}
static int F_239 ( struct V_207 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
F_17 ( V_28 , 5 , L_164 ) ;
if ( F_129 ( V_28 , V_239 ) ) {
F_17 ( V_28 , 3 , L_165 ) ;
return - V_517 ;
}
return F_235 ( V_122 ) ;
}
static int F_161 ( struct V_207 * V_122 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
F_17 ( V_28 , 4 , L_166 ) ;
F_240 ( V_122 ) ;
if ( V_28 -> V_323 == V_326 ) {
V_28 -> V_323 = V_327 ;
F_241 ( & V_28 -> V_294 ) ;
}
return 0 ;
}
static T_9 F_242 ( struct V_207 * V_122 ,
T_9 V_176 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
if ( ! F_54 ( V_28 , V_155 ) )
V_176 &= ~ V_518 ;
if ( ! F_54 ( V_28 , V_178 ) )
V_176 &= ~ V_179 ;
if ( ! F_54 ( V_28 , V_150 ) )
V_176 &= ~ V_177 ;
return V_176 ;
}
static int F_243 ( struct V_207 * V_122 ,
T_9 V_176 )
{
struct V_27 * V_28 = V_122 -> V_237 ;
T_9 V_519 = V_122 -> V_176 ^ V_176 ;
if ( ! ( V_519 & V_177 ) )
return 0 ;
if ( V_28 -> V_323 == V_329 ||
V_28 -> V_323 == V_520 )
return 0 ;
return F_88 ( V_28 , V_176 & V_177 ? 1 : 0 ) ;
}
static int F_244 ( struct V_425 * V_426 )
{
V_426 -> V_521 = V_522 ;
memcpy ( V_426 -> V_523 , L_116 , 6 ) ;
V_426 -> V_524 = V_426 -> V_525 -> V_526 ;
return 0 ;
}
static int
F_245 ( struct V_207 * V_122 , struct V_527 * V_528 )
{
if ( V_528 -> V_529 -> V_530 == V_531 )
V_528 -> V_532 = F_244 ;
return 0 ;
}
static int F_246 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_97 . type == V_416 ||
V_28 -> V_97 . type == V_417 ) {
if ( ( V_28 -> V_97 . V_430 == V_432 ) ||
( V_28 -> V_97 . V_430 == V_431 ) ) {
F_247 ( L_167 ) ;
return - V_403 ;
} else {
V_28 -> V_122 = F_248 ( 0 ) ;
if ( ! V_28 -> V_122 )
return - V_403 ;
V_28 -> V_122 -> V_533 = & V_534 ;
F_98 ( V_28 ) ;
if ( ! ( V_28 -> V_97 . V_183 & V_187 ) )
V_28 -> V_122 -> V_535 = V_28 -> V_97 . V_183 &
0xffff ;
if ( ! V_28 -> V_97 . V_331 ) {
V_28 -> V_122 -> V_536 = V_537 |
V_177 | V_518 |
V_179 ;
V_28 -> V_122 -> V_176 = V_177 ;
}
}
} else if ( V_28 -> V_97 . type == V_98 ) {
V_28 -> V_122 = F_249 ( 0 , L_168 , V_538 ,
V_539 ) ;
if ( ! V_28 -> V_122 )
return - V_403 ;
V_28 -> V_122 -> V_58 |= V_540 ;
V_28 -> V_122 -> V_533 = & V_541 ;
V_4 = F_96 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_43 . V_542 [ 0 ] )
memcpy ( V_28 -> V_122 -> V_543 , V_28 -> V_43 . V_542 , 9 ) ;
} else
return - V_403 ;
V_28 -> V_122 -> V_237 = V_28 ;
V_28 -> V_122 -> V_544 = V_545 ;
V_28 -> V_122 -> V_546 = V_28 -> V_97 . V_547 ;
V_28 -> V_122 -> V_548 = & V_549 ;
V_28 -> V_122 -> V_176 |= V_550 |
V_551 |
V_552 ;
F_250 ( V_28 -> V_122 ) ;
V_28 -> V_122 -> V_553 = 15 * V_554 ;
F_251 ( V_28 -> V_122 , & V_28 -> V_121 -> V_122 ) ;
F_252 ( V_28 -> V_122 , & V_28 -> V_294 , F_143 , V_555 ) ;
F_253 ( V_28 -> V_122 ) ;
return F_254 ( V_28 -> V_122 ) ;
}
static int F_255 ( struct V_556 * V_121 )
{
struct V_27 * V_28 = F_256 ( & V_121 -> V_122 ) ;
F_257 ( & V_121 -> V_122 ) ;
V_28 -> V_43 . V_320 = 0 ;
V_28 -> V_97 . V_557 = 0 ;
return 0 ;
}
static void F_258 ( struct V_556 * V_558 )
{
struct V_27 * V_28 = F_256 ( & V_558 -> V_122 ) ;
F_259 ( & V_558 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
F_260 ( V_28 -> V_559 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_558 -> V_323 == V_560 )
F_261 ( V_558 ) ;
if ( V_28 -> V_122 ) {
F_262 ( V_28 -> V_122 ) ;
V_28 -> V_122 = NULL ;
}
F_38 ( V_28 , 0 ) ;
F_55 ( V_28 ) ;
return;
}
static int F_263 ( struct V_556 * V_121 , int V_321 )
{
struct V_27 * V_28 = F_256 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
enum V_561 V_562 ;
F_264 ( & V_28 -> V_563 ) ;
F_264 ( & V_28 -> V_564 ) ;
F_66 ( V_136 , 2 , L_169 ) ;
F_142 ( V_136 , 2 , & V_28 , sizeof( void * ) ) ;
V_562 = V_28 -> V_323 ;
V_4 = F_265 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_136 , 2 , L_170 , V_4 ) ;
V_4 = - V_403 ;
goto V_565;
}
if ( ! V_28 -> V_122 && F_246 ( V_28 ) ) {
V_4 = - V_403 ;
goto V_565;
}
if ( F_267 ( V_28 , V_566 ) ) {
if ( V_28 -> V_97 . V_557 &&
F_268 ( V_28 , V_567 ) )
V_28 -> V_97 . V_557 = 0 ;
} else
V_28 -> V_97 . V_557 = 0 ;
V_28 -> V_323 = V_328 ;
memset ( & V_28 -> V_285 , 0 , sizeof( struct V_568 ) ) ;
F_269 ( V_28 ) ;
F_66 ( V_136 , 2 , L_171 ) ;
V_4 = F_270 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_136 , 2 , L_172 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_62 ( & V_28 -> V_121 -> V_122 ,
L_173 ) ;
V_28 -> V_496 = 0 ;
goto V_569;
}
V_4 = - V_403 ;
goto V_565;
} else
V_28 -> V_496 = 1 ;
V_569:
V_4 = F_65 ( V_28 ) ;
if ( V_4 )
F_266 ( V_136 , 2 , L_170 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_92 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_136 , 2 , L_174 , V_4 ) ;
goto V_565;
}
V_4 = F_49 ( V_28 ) ;
if ( V_4 )
F_266 ( V_136 , 2 , L_175 , V_4 ) ;
V_4 = F_52 ( V_28 ) ;
if ( V_4 )
F_266 ( V_136 , 2 , L_176 , V_4 ) ;
}
F_240 ( V_28 -> V_122 ) ;
V_4 = F_271 ( V_28 ) ;
if ( V_4 ) {
F_266 ( V_136 , 2 , L_177 , V_4 ) ;
V_4 = - V_403 ;
goto V_565;
}
V_28 -> V_323 = V_327 ;
F_160 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_496 )
F_272 ( V_28 -> V_122 ) ;
else
F_253 ( V_28 -> V_122 ) ;
if ( V_562 == V_520 ) {
F_162 () ;
if ( V_321 )
F_235 ( V_28 -> V_122 ) ;
else
F_273 ( V_28 -> V_122 ) ;
F_131 ( V_28 -> V_122 ) ;
F_164 () ;
}
F_274 ( V_28 ) ;
F_275 ( & V_121 -> V_122 . V_570 , V_571 ) ;
F_276 ( & V_28 -> V_564 ) ;
F_276 ( & V_28 -> V_563 ) ;
return 0 ;
V_565:
F_159 ( V_28 , 0 ) ;
F_277 ( F_278 ( V_28 ) ) ;
F_277 ( F_279 ( V_28 ) ) ;
F_277 ( F_280 ( V_28 ) ) ;
F_281 ( F_278 ( V_28 ) ) ;
if ( V_562 == V_520 )
V_28 -> V_323 = V_520 ;
else
V_28 -> V_323 = V_329 ;
F_276 ( & V_28 -> V_564 ) ;
F_276 ( & V_28 -> V_563 ) ;
return V_4 ;
}
static int F_282 ( struct V_556 * V_121 )
{
return F_263 ( V_121 , 0 ) ;
}
static int F_283 ( struct V_556 * V_558 ,
int V_321 )
{
struct V_27 * V_28 = F_256 ( & V_558 -> V_122 ) ;
int V_4 = 0 , V_572 = 0 , V_573 = 0 ;
enum V_561 V_562 ;
F_264 ( & V_28 -> V_563 ) ;
F_264 ( & V_28 -> V_564 ) ;
F_66 ( V_136 , 3 , L_178 ) ;
F_142 ( V_136 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_122 && F_284 ( V_28 -> V_122 ) )
F_253 ( V_28 -> V_122 ) ;
V_562 = V_28 -> V_323 ;
if ( ( ! V_321 && V_28 -> V_97 . V_557 ) || V_28 -> V_97 . V_557 == 2 ) {
F_268 ( V_28 , V_574 ) ;
V_28 -> V_97 . V_557 = 1 ;
}
F_159 ( V_28 , V_321 ) ;
if ( ( V_28 -> V_43 . V_493 == V_494 ) && V_28 -> V_122 ) {
F_162 () ;
F_285 ( V_575 , V_28 -> V_122 ) ;
F_164 () ;
}
V_4 = F_277 ( F_278 ( V_28 ) ) ;
V_572 = F_277 ( F_279 ( V_28 ) ) ;
V_573 = F_277 ( F_280 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_572 ) ? V_572 : V_573 ;
if ( V_4 )
F_266 ( V_136 , 2 , L_172 , V_4 ) ;
F_281 ( F_278 ( V_28 ) ) ;
if ( V_562 == V_326 )
V_28 -> V_323 = V_520 ;
F_275 ( & V_558 -> V_122 . V_570 , V_571 ) ;
F_276 ( & V_28 -> V_564 ) ;
F_276 ( & V_28 -> V_563 ) ;
return 0 ;
}
static int F_261 ( struct V_556 * V_558 )
{
return F_283 ( V_558 , 0 ) ;
}
static int F_286 ( void * V_576 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_576 ;
F_17 ( V_28 , 2 , L_179 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_287 ( V_28 , V_239 ) )
return 0 ;
F_17 ( V_28 , 2 , L_180 ) ;
F_62 ( & V_28 -> V_121 -> V_122 ,
L_181 ) ;
F_288 ( V_28 ) ;
F_283 ( V_28 -> V_121 , 1 ) ;
V_4 = F_263 ( V_28 -> V_121 , 1 ) ;
if ( ! V_4 )
F_67 ( & V_28 -> V_121 -> V_122 ,
L_182 ) ;
else {
F_289 ( V_28 ) ;
F_62 ( & V_28 -> V_121 -> V_122 , L_183
L_184 ) ;
}
F_290 ( V_28 ) ;
F_291 ( V_28 , V_239 ) ;
F_292 ( V_28 , V_239 ) ;
return 0 ;
}
static void F_293 ( struct V_556 * V_121 )
{
struct V_27 * V_28 = F_256 ( & V_121 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
if ( ( V_121 -> V_323 == V_560 ) && V_28 -> V_97 . V_557 )
F_268 ( V_28 , V_574 ) ;
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
F_281 ( F_278 ( V_28 ) ) ;
}
static int F_294 ( struct V_556 * V_121 )
{
struct V_27 * V_28 = F_256 ( & V_121 -> V_122 ) ;
if ( V_28 -> V_122 )
F_295 ( V_28 -> V_122 ) ;
F_160 ( V_28 , 0 , 1 ) ;
F_260 ( V_28 -> V_559 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_121 -> V_323 == V_577 )
return 0 ;
if ( V_28 -> V_323 == V_326 ) {
if ( V_28 -> V_97 . V_557 )
F_268 ( V_28 , V_574 ) ;
F_283 ( V_28 -> V_121 , 1 ) ;
} else
F_283 ( V_28 -> V_121 , 0 ) ;
return 0 ;
}
static int F_296 ( struct V_556 * V_121 )
{
struct V_27 * V_28 = F_256 ( & V_121 -> V_122 ) ;
int V_4 = 0 ;
if ( V_121 -> V_323 == V_577 )
goto V_14;
if ( V_28 -> V_323 == V_520 ) {
V_4 = F_263 ( V_28 -> V_121 , 1 ) ;
if ( V_4 ) {
F_162 () ;
F_163 ( V_28 -> V_122 ) ;
F_164 () ;
}
} else
V_4 = F_263 ( V_28 -> V_121 , 0 ) ;
V_14:
F_160 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_122 )
F_297 ( V_28 -> V_122 ) ;
if ( V_4 )
F_62 ( & V_28 -> V_121 -> V_122 , L_183
L_184 ) ;
return V_4 ;
}
static int F_298 ( struct V_27 * V_28 ,
struct V_80 * V_81 )
{
return 1 ;
}
static int F_299 ( struct V_578 * V_579 ,
unsigned long V_580 , void * V_576 )
{
struct V_229 * V_230 = (struct V_229 * ) V_576 ;
struct V_207 * V_122 = (struct V_207 * ) V_230 -> V_581 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_300 ( V_122 ) != & V_582 )
return V_583 ;
V_28 = F_158 ( V_122 ) ;
if ( ! V_28 )
return V_583 ;
F_17 ( V_28 , 3 , L_185 ) ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_230 -> V_233 ;
V_2 -> V_36 . V_47 . V_48 = V_230 -> V_234 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_580 ) {
case V_584 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_585 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_583 ;
}
static int F_301 ( struct V_578 * V_579 ,
unsigned long V_580 , void * V_576 )
{
struct V_235 * V_230 = (struct V_235 * ) V_576 ;
struct V_207 * V_122 = (struct V_207 * ) V_230 -> V_586 -> V_122 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_158 ( V_122 ) ;
if ( ! V_28 )
return V_583 ;
F_17 ( V_28 , 3 , L_186 ) ;
if ( ! F_54 ( V_28 , V_108 ) )
return V_583 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_230 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_230 -> V_236 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_580 ) {
case V_584 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_585 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_583 ;
}
static int F_302 ( void )
{
int V_4 ;
F_66 ( V_136 , 5 , L_187 ) ;
V_4 = F_303 ( & V_587 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_53
V_4 = F_304 ( & V_588 ) ;
if ( V_4 ) {
F_305 ( & V_587 ) ;
return V_4 ;
}
#else
F_306 ( L_188 ) ;
#endif
return 0 ;
}
static void F_307 ( void )
{
F_66 ( V_136 , 5 , L_189 ) ;
F_308 ( F_305 ( & V_587 ) ) ;
#ifdef F_53
F_308 ( F_309 ( & V_588 ) ) ;
#endif
}
static int T_10 F_310 ( void )
{
int V_4 = 0 ;
F_247 ( L_190 ) ;
V_4 = F_302 () ;
return V_4 ;
}
static void T_11 F_311 ( void )
{
F_307 () ;
F_247 ( L_191 ) ;
}
