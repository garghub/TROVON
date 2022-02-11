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
static void F_46 ( struct V_27 * V_28 ,
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
if ( F_47 ( V_28 , V_60 ,
V_108 ) )
return;
default:
goto V_105;
}
}
V_105:
* type = V_101 ;
}
int F_48 ( struct V_27 * V_28 )
{
int V_4 ;
F_17 ( V_28 , 3 , L_17 ) ;
F_46 ( V_28 , & V_28 -> V_43 . V_109 . type ,
V_20 ) ;
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
F_46 ( V_28 , & V_28 -> V_43 . V_111 . type ,
V_21 ) ;
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
F_96 ( V_28 ) ;
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
F_110 () ;
V_229 = F_111 ( V_28 -> V_125 , V_228 ) ;
F_112 () ;
if ( V_229 == NULL ||
! ( V_229 -> V_58 & V_230 ) )
continue;
V_227 = F_113 ( V_229 ) ;
if ( ! V_227 )
continue;
F_110 () ;
F_106 ( V_28 , V_227 ) ;
F_112 () ;
F_114 ( V_227 ) ;
}
}
static void F_115 ( struct V_27 * V_28 )
{
struct V_219 * V_220 ;
F_17 ( V_28 , 4 , L_117 ) ;
V_220 = F_113 ( V_28 -> V_125 ) ;
if ( V_220 == NULL )
return;
F_110 () ;
F_106 ( V_28 , V_220 ) ;
F_108 ( V_28 ) ;
F_112 () ;
F_114 ( V_220 ) ;
}
static void F_116 ( struct V_27 * V_28 , struct V_231 * V_232 )
{
struct V_29 * V_217 ;
struct V_233 * V_234 ;
char V_1 [ V_223 ] ;
F_17 ( V_28 , 4 , L_118 ) ;
for ( V_234 = V_232 -> V_224 ; V_234 != NULL ; V_234 = V_234 -> V_74 ) {
F_117 ( & V_234 -> V_235 , V_1 , V_232 -> V_125 , 0 ) ;
V_217 = F_24 ( V_21 ) ;
if ( ! V_217 )
continue;
V_217 -> V_46 = 1 ;
memcpy ( V_217 -> V_88 , V_1 , V_89 ) ;
memcpy ( & V_217 -> V_36 . V_49 . V_2 , & V_234 -> V_235 . V_236 ,
sizeof( struct V_51 ) ) ;
if ( ! F_23 ( V_28 , V_217 ) )
F_15 ( V_217 ) ;
}
}
static void F_118 ( struct V_27 * V_28 )
{
struct V_231 * V_227 ;
T_4 V_228 ;
F_17 ( V_28 , 4 , L_119 ) ;
if ( ! F_53 ( V_28 , V_172 ) )
return;
F_109 (vid, card->active_vlans, VLAN_N_VID) {
struct V_218 * V_229 ;
V_229 = F_111 ( V_28 -> V_125 , V_228 ) ;
if ( V_229 == NULL ||
! ( V_229 -> V_58 & V_230 ) )
continue;
V_227 = F_119 ( V_229 ) ;
if ( ! V_227 )
continue;
F_120 ( & V_227 -> V_237 ) ;
F_116 ( V_28 , V_227 ) ;
F_121 ( & V_227 -> V_237 ) ;
F_122 ( V_227 ) ;
}
}
static void F_123 ( struct V_27 * V_28 )
{
struct V_231 * V_232 ;
F_17 ( V_28 , 4 , L_120 ) ;
if ( ! F_53 ( V_28 , V_110 ) )
return ;
V_232 = F_119 ( V_28 -> V_125 ) ;
if ( V_232 == NULL )
return;
F_120 ( & V_232 -> V_237 ) ;
F_116 ( V_28 , V_232 ) ;
F_118 ( V_28 ) ;
F_121 ( & V_232 -> V_237 ) ;
F_122 ( V_232 ) ;
}
static void F_124 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
struct V_219 * V_227 ;
struct V_238 * V_239 ;
struct V_29 * V_2 ;
struct V_218 * V_229 ;
F_17 ( V_28 , 4 , L_121 ) ;
V_229 = F_111 ( V_28 -> V_125 , V_228 ) ;
V_227 = F_113 ( V_229 ) ;
if ( ! V_227 )
return;
for ( V_239 = V_227 -> V_240 ; V_239 ; V_239 = V_239 -> V_241 ) {
V_2 = F_24 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_47 . V_2 = V_239 -> V_242 ;
V_2 -> V_36 . V_47 . V_48 = V_239 -> V_243 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_114 ( V_227 ) ;
}
static void F_125 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
#ifdef F_52
struct V_231 * V_232 ;
struct V_244 * V_239 ;
struct V_29 * V_2 ;
struct V_218 * V_229 ;
F_17 ( V_28 , 4 , L_122 ) ;
V_229 = F_111 ( V_28 -> V_125 , V_228 ) ;
V_232 = F_119 ( V_229 ) ;
if ( ! V_232 )
return;
F_10 (ifa, &in6_dev->addr_list, if_list) {
V_2 = F_24 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_239 -> V_2 ,
sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_239 -> V_245 ;
V_2 -> type = V_55 ;
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
}
}
F_122 ( V_232 ) ;
#endif
}
static void F_126 ( struct V_27 * V_28 ,
unsigned short V_228 )
{
F_124 ( V_28 , V_228 ) ;
F_125 ( V_28 , V_228 ) ;
}
static int F_127 ( struct V_218 * V_125 , unsigned short V_228 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
F_128 ( V_228 , V_28 -> V_247 ) ;
return 0 ;
}
static int F_129 ( struct V_218 * V_125 , unsigned short V_228 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
unsigned long V_58 ;
F_44 ( V_28 , 4 , L_123 , V_228 ) ;
if ( F_130 ( V_28 , V_248 ) ) {
F_17 ( V_28 , 3 , L_124 ) ;
return 0 ;
}
F_21 ( & V_28 -> V_249 , V_58 ) ;
F_126 ( V_28 , V_228 ) ;
F_131 ( V_228 , V_28 -> V_247 ) ;
F_22 ( & V_28 -> V_249 , V_58 ) ;
F_132 ( V_28 -> V_125 ) ;
return 0 ;
}
static inline int F_133 ( struct V_27 * V_28 ,
struct V_250 * V_251 , struct V_252 * V_144 ,
unsigned short * V_253 )
{
T_5 V_60 ;
struct V_254 * V_255 ;
unsigned char V_256 [ V_223 ] ;
int V_257 = 0 ;
if ( ! ( V_144 -> V_144 . V_258 . V_58 & V_135 ) ) {
V_60 = F_134 ( ( V_144 -> V_144 . V_258 . V_58 & V_136 ) ? V_259 :
V_260 ) ;
switch ( V_144 -> V_144 . V_258 . V_58 & V_261 ) {
case V_130 :
switch ( V_60 ) {
#ifdef F_52
case F_135 ( V_259 ) :
F_117 ( (struct V_51 * )
V_251 -> V_85 + 24 ,
V_256 , V_28 -> V_125 , 0 ) ;
break;
#endif
case F_135 ( V_260 ) :
V_255 = (struct V_254 * ) V_251 -> V_85 ;
F_105 ( V_255 -> V_262 , V_256 ) ;
break;
default:
memcpy ( V_256 , V_28 -> V_125 -> V_263 ,
V_28 -> V_125 -> V_264 ) ;
}
V_28 -> V_265 . V_266 ++ ;
V_251 -> V_267 = V_268 ;
break;
case V_132 :
memcpy ( V_256 , V_28 -> V_125 -> V_263 ,
V_28 -> V_125 -> V_264 ) ;
V_28 -> V_265 . V_266 ++ ;
V_251 -> V_267 = V_269 ;
break;
case V_133 :
case V_138 :
case V_270 :
default:
if ( V_28 -> V_43 . V_44 )
V_251 -> V_267 = V_271 ;
else
V_251 -> V_267 = V_272 ;
memcpy ( V_256 , V_28 -> V_125 -> V_192 ,
V_28 -> V_125 -> V_264 ) ;
}
if ( V_144 -> V_144 . V_258 . V_273 & V_274 )
V_28 -> V_125 -> V_275 -> V_276 ( V_251 , V_28 -> V_125 , V_60 ,
V_256 , & V_144 -> V_144 . V_258 . V_277 [ 2 ] ,
V_28 -> V_125 -> V_264 ) ;
else
V_28 -> V_125 -> V_275 -> V_276 ( V_251 , V_28 -> V_125 , V_60 ,
V_256 , L_125 , V_28 -> V_125 -> V_264 ) ;
}
V_251 -> V_278 = F_136 ( V_251 , V_28 -> V_125 ) ;
if ( V_144 -> V_144 . V_258 . V_273 &
( V_279 | V_280 ) ) {
* V_253 = ( V_144 -> V_144 . V_258 . V_273 & V_279 ) ?
V_144 -> V_144 . V_258 . V_253 : * ( ( T_4 * ) & V_144 -> V_144 . V_258 . V_277 [ 12 ] ) ;
V_257 = 1 ;
}
if ( V_28 -> V_125 -> V_187 & V_188 ) {
if ( ( V_144 -> V_144 . V_258 . V_273 &
( V_281 |
V_282 ) ) ==
( V_281 |
V_282 ) )
V_251 -> V_283 = V_284 ;
else
V_251 -> V_283 = V_285 ;
} else
V_251 -> V_283 = V_285 ;
return V_257 ;
}
static int F_137 ( struct V_27 * V_28 ,
int V_286 , int * V_287 )
{
int V_288 = 0 ;
struct V_250 * V_251 ;
struct V_252 * V_144 ;
T_2 V_289 = 0 ;
int V_257 ;
unsigned int V_23 ;
T_2 V_290 ;
* V_287 = 0 ;
F_138 ( ! V_286 ) ;
while ( V_286 ) {
V_251 = F_139 ( V_28 ,
& V_28 -> V_291 . V_292 -> V_293 [ V_28 -> V_294 . V_295 ] ,
& V_28 -> V_294 . V_296 , & V_28 -> V_294 . V_297 , & V_144 ) ;
if ( ! V_251 ) {
* V_287 = 1 ;
break;
}
V_251 -> V_125 = V_28 -> V_125 ;
switch ( V_144 -> V_144 . V_258 . V_298 ) {
case V_299 :
V_290 = * ( T_2 * ) V_251 -> V_85 ;
if ( ( V_28 -> V_99 . type == V_100 ) &&
( V_290 == V_300 ) ) {
V_251 -> V_278 = V_300 ;
V_251 -> V_267 = V_272 ;
V_251 -> V_301 = V_302 ;
V_251 -> V_125 = V_28 -> V_125 ;
V_23 = V_251 -> V_23 ;
V_28 -> V_125 -> V_275 -> V_276 ( V_251 , V_28 -> V_125 , 0 ,
V_28 -> V_125 -> V_192 , L_125 ,
V_28 -> V_125 -> V_264 ) ;
F_140 ( V_251 ) ;
} else {
V_257 = F_133 ( V_28 , V_251 , V_144 ,
& V_289 ) ;
V_23 = V_251 -> V_23 ;
if ( V_257 && ! V_28 -> V_43 . V_44 )
F_141 ( V_251 , V_289 ) ;
F_142 ( & V_28 -> V_303 , V_251 ) ;
}
break;
case V_304 :
V_251 -> V_267 = V_272 ;
V_251 -> V_278 = F_136 ( V_251 , V_251 -> V_125 ) ;
V_23 = V_251 -> V_23 ;
F_140 ( V_251 ) ;
break;
default:
F_143 ( V_251 ) ;
F_17 ( V_28 , 3 , L_126 ) ;
F_144 ( V_305 , 3 , V_144 , V_306 ) ;
continue;
}
V_288 ++ ;
V_286 -- ;
V_28 -> V_265 . V_307 ++ ;
V_28 -> V_265 . V_308 += V_23 ;
}
return V_288 ;
}
static int F_145 ( struct V_309 * V_303 , int V_286 )
{
struct V_27 * V_28 = F_146 ( V_303 , struct V_27 , V_303 ) ;
int V_288 = 0 ;
struct V_310 * V_311 ;
int V_287 ;
int V_312 = V_286 ;
if ( V_28 -> V_43 . V_313 ) {
V_28 -> V_314 . V_315 ++ ;
V_28 -> V_314 . V_316 = F_147 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_294 . V_317 ) {
V_28 -> V_294 . V_318 = 0 ;
V_28 -> V_294 . V_317 = F_148 (
V_28 -> V_85 . V_319 , 0 , & V_28 -> V_294 . V_295 ,
& V_28 -> V_294 . V_318 ) ;
if ( V_28 -> V_294 . V_317 <= 0 ) {
V_28 -> V_294 . V_317 = 0 ;
break;
}
V_28 -> V_294 . V_296 =
& V_28 -> V_291 . V_292 -> V_293 [ V_28 -> V_294 . V_295 ]
. V_311 -> V_320 [ 0 ] ;
V_28 -> V_294 . V_297 = 0 ;
}
while ( V_28 -> V_294 . V_317 ) {
V_311 = & V_28 -> V_291 . V_292 -> V_293 [ V_28 -> V_294 . V_295 ] ;
if ( ! ( V_28 -> V_294 . V_318 &&
F_149 ( V_28 , V_311 -> V_311 ,
V_28 -> V_294 . V_318 , L_127 ) ) )
V_288 += F_137 (
V_28 , V_312 , & V_287 ) ;
else
V_287 = 1 ;
if ( V_287 ) {
if ( V_28 -> V_43 . V_313 )
V_28 -> V_314 . V_321 ++ ;
F_150 ( V_28 ,
V_311 -> V_322 ) ;
F_151 ( V_28 , V_28 -> V_294 . V_295 ) ;
V_28 -> V_294 . V_317 -- ;
if ( V_28 -> V_294 . V_317 ) {
V_28 -> V_294 . V_295 =
( V_28 -> V_294 . V_295 + 1 ) %
V_323 ;
V_28 -> V_294 . V_296 =
& V_28 -> V_291 . V_292
-> V_293 [ V_28 -> V_294 . V_295 ]
. V_311 -> V_320 [ 0 ] ;
V_28 -> V_294 . V_297 = 0 ;
}
}
if ( V_288 >= V_286 )
goto V_14;
else
V_312 = V_286 - V_288 ;
}
}
F_152 ( V_303 ) ;
if ( F_153 ( V_28 -> V_85 . V_319 , 0 ) )
F_154 ( & V_28 -> V_303 ) ;
V_14:
if ( V_28 -> V_43 . V_313 )
V_28 -> V_314 . V_324 += F_147 () -
V_28 -> V_314 . V_316 ;
return V_288 ;
}
static int F_155 ( struct V_218 * V_125 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_4 V_228 ;
F_109 (vid, card->active_vlans, VLAN_N_VID) {
struct V_218 * V_229 ;
F_110 () ;
V_229 = F_111 ( V_28 -> V_125 , V_228 ) ;
F_112 () ;
if ( V_229 == V_125 ) {
V_4 = V_325 ;
break;
}
}
if ( V_4 && ! ( F_156 ( V_125 ) -> V_246 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_157 ( struct V_218 * V_125 )
{
struct V_27 * V_28 ;
unsigned long V_58 ;
int V_4 = 0 ;
F_158 ( & V_326 . V_327 , V_58 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_125 == V_125 ) {
V_4 = V_328 ;
break;
}
V_4 = F_155 ( V_125 , V_28 ) ;
if ( V_4 )
break;
}
F_159 ( & V_326 . V_327 , V_58 ) ;
return V_4 ;
}
static struct V_27 * F_160 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_157 ( V_125 ) ;
if ( V_4 == V_328 )
V_28 = V_125 -> V_246 ;
else if ( V_4 == V_325 )
V_28 = F_156 ( V_125 ) -> V_246 ;
if ( V_28 && V_28 -> V_43 . V_329 )
V_28 = NULL ;
if ( V_28 )
F_44 ( V_28 , 4 , L_128 , V_4 ) ;
return V_28 ;
}
static int F_161 ( struct V_27 * V_28 , int V_330 )
{
int V_4 = 0 ;
F_65 ( V_139 , 2 , L_129 ) ;
F_144 ( V_139 , 2 , & V_28 , sizeof( void * ) ) ;
F_162 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_43 . V_44 &&
( V_28 -> V_99 . V_204 == V_207 ) )
F_103 ( V_28 , V_202 ) ;
if ( V_28 -> V_331 . V_71 == V_332 &&
V_28 -> V_333 . V_71 == V_332 &&
( V_28 -> V_71 == V_72 ) ) {
if ( V_330 )
F_163 ( V_28 -> V_125 ) ;
else {
F_90 () ;
F_164 ( V_28 -> V_125 ) ;
F_92 () ;
}
V_28 -> V_71 = V_73 ;
}
if ( V_28 -> V_71 == V_73 ) {
F_37 ( V_28 , 1 ) ;
F_165 ( V_28 ) ;
V_28 -> V_71 = V_334 ;
}
if ( V_28 -> V_71 == V_334 ) {
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
F_168 ( V_28 ) ;
V_28 -> V_71 = V_335 ;
}
if ( V_28 -> V_71 == V_335 ) {
F_169 ( & V_28 -> V_331 ) ;
F_169 ( & V_28 -> V_333 ) ;
}
return V_4 ;
}
static void
F_170 ( struct V_27 * V_28 )
{
struct V_218 * V_125 = V_28 -> V_125 ;
if ( ( ( V_125 -> V_58 & V_336 ) &&
( V_28 -> V_99 . V_204 == V_207 ) ) ||
( ! ( V_125 -> V_58 & V_336 ) &&
( V_28 -> V_99 . V_204 == V_205 ) ) )
return;
if ( V_28 -> V_99 . V_337 ) {
if ( F_69 ( V_28 , V_338 ) )
F_171 ( V_28 ) ;
} else if ( V_28 -> V_43 . V_44 &&
F_69 ( V_28 , V_339 ) ) {
if ( V_125 -> V_58 & V_336 ) {
F_17 ( V_28 , 3 , L_130 ) ;
F_103 ( V_28 , V_206 ) ;
} else {
F_17 ( V_28 , 3 , L_131 ) ;
F_103 ( V_28 , V_202 ) ;
}
}
}
static void F_132 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
F_17 ( V_28 , 3 , L_132 ) ;
if ( F_172 ( V_28 , V_248 ) &&
( V_28 -> V_71 != V_72 ) )
return;
if ( ! V_28 -> V_43 . V_44 ) {
F_26 ( V_28 ) ;
F_115 ( V_28 ) ;
#ifdef F_52
F_123 ( V_28 ) ;
#endif
F_32 ( V_28 ) ;
if ( ! F_69 ( V_28 , V_338 ) )
return;
}
F_170 ( V_28 ) ;
}
static const char * F_173 ( int * V_4 )
{
switch ( * V_4 ) {
case V_340 :
* V_4 = - V_185 ;
return L_133 ;
case V_341 :
* V_4 = - V_170 ;
return L_134 ;
case V_342 :
* V_4 = - V_7 ;
return L_135 ;
case V_343 :
* V_4 = - V_170 ;
return L_136 ;
case V_344 :
* V_4 = - V_345 ;
return L_137 ;
default:
return L_138 ;
}
}
static int F_174 ( struct V_27 * V_28 , int V_346 )
{
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_139 ) ;
if ( V_28 -> V_99 . V_337 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_168 ,
V_347 ,
V_346 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 , L_140
L_141 , F_50 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static V_167 F_175 ( struct V_27 * V_28 ,
struct V_348 * V_349 ,
struct V_350 * type , T_1 V_351 )
{
V_167 V_4 ;
T_1 V_352 ;
V_352 = V_349 -> V_353 == 5 ;
if ( type -> V_354 == V_355 ) {
F_17 ( V_28 , 4 , L_142 ) ;
if ( V_351 ) {
V_4 = V_352 ? sizeof( struct V_356 ) :
sizeof( struct V_357 ) ;
} else {
V_4 = V_352 ? sizeof( struct V_358 ) :
sizeof( struct V_359 ) ;
}
} else if ( type -> V_354 == V_360 ) {
F_17 ( V_28 , 4 , L_143 ) ;
if ( V_351 ) {
V_4 = V_352 ?
sizeof( struct V_361 ) :
sizeof( struct V_362 ) ;
} else {
V_4 = V_352 ?
sizeof( struct V_363 ) :
sizeof( struct V_364 ) ;
}
} else {
F_17 ( V_28 , 4 , L_144 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_176 ( struct V_350 * type , T_2 V_60 )
{
return ( type -> V_354 == V_355 && V_60 == V_20 ) ||
( type -> V_354 == V_360 && V_60 == V_21 ) ;
}
static int F_177 ( struct V_27 * V_28 ,
struct V_142 * V_143 , unsigned long V_85 )
{
struct V_83 * V_84 ;
struct V_348 * V_349 ;
struct V_365 * V_366 ;
int V_24 ;
int V_367 ;
int V_368 ;
int V_369 ;
T_1 V_370 ;
F_17 ( V_28 , 3 , L_145 ) ;
V_366 = (struct V_365 * ) V_143 -> V_371 ;
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
V_349 = & V_84 -> V_85 . V_146 . V_85 . V_372 ;
F_44 ( V_28 , 4 , L_149 , V_349 -> V_346 ) ;
V_370 = ( V_366 -> V_37 & V_373 ) > 0 ;
V_369 = V_370 ? V_374 : 0 ;
V_368 = 0 ;
for ( V_367 = 0 ; V_367 < V_349 -> V_346 ; ++ V_367 ) {
char * V_375 ;
V_167 V_376 ;
struct V_350 * V_377 ;
V_375 = & V_349 -> V_85 + V_368 ;
V_377 = & ( (struct V_358 * ) V_375 ) -> type ;
if ( ! F_176 ( V_377 , V_84 -> V_144 . V_147 ) ) {
F_17 ( V_28 , 4 , L_150 ) ;
F_44 ( V_28 , 4 , L_146 , V_377 -> V_354 ) ;
break;
}
V_376 = F_175 ( V_28 , V_349 , V_377 ,
V_370 ) ;
F_44 ( V_28 , 5 , L_151 , V_376 ) ;
if ( ! V_376 )
break;
if ( ( V_366 -> V_378 - V_366 -> V_379 ) < V_376 ) {
F_44 ( V_28 , 4 , L_152 , - V_120 ) ;
V_84 -> V_144 . V_145 = V_380 ;
goto V_381;
}
memcpy ( V_366 -> V_382 + V_366 -> V_379 ,
& V_349 -> V_85 + V_368 + V_369 ,
V_376 ) ;
V_368 += V_376 + V_369 ;
V_366 -> V_379 += V_376 ;
++ V_366 -> V_346 ;
}
if ( V_84 -> V_85 . V_146 . V_144 . V_165 <
V_84 -> V_85 . V_146 . V_144 . V_383 )
return 1 ;
F_44 ( V_28 , 4 , L_153 , V_366 -> V_346 ) ;
memcpy ( V_366 -> V_382 , & V_366 -> V_346 , 4 ) ;
if ( V_366 -> V_37 & V_373 )
V_349 -> V_353 |= V_373 ;
memcpy ( V_366 -> V_382 + V_384 , & V_349 -> V_353 , 2 ) ;
F_44 ( V_28 , 4 , L_154 , 0 ) ;
return 0 ;
V_381:
V_24 = 0 ;
memcpy ( V_366 -> V_382 , & V_24 , 4 ) ;
return 0 ;
}
static int F_178 ( struct V_27 * V_28 ,
struct V_81 * V_82 , int V_23 ,
int (* F_74)( struct V_27 * , struct V_142 * ,
unsigned long ) ,
void * V_166 )
{
F_17 ( V_28 , 4 , L_155 ) ;
memcpy ( V_82 -> V_85 , V_385 , V_86 ) ;
memcpy ( F_179 ( V_82 -> V_85 ) ,
& V_28 -> V_386 . V_387 , V_388 ) ;
return F_180 ( V_28 , V_86 + V_23 , V_82 ,
F_74 , V_166 ) ;
}
static int F_181 ( struct V_27 * V_28 ,
enum V_18 V_60 ,
struct V_365 * V_366 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
int V_41 ;
int V_4 ;
F_44 ( V_28 , 3 , L_156 , V_60 ) ;
V_82 = F_72 ( V_28 , V_168 ,
V_389 ,
sizeof( struct V_348 ) - sizeof( char ) ,
V_60 ) ;
V_84 = (struct V_83 * ) ( V_82 -> V_85 + V_86 ) ;
V_84 -> V_85 . V_146 . V_85 . V_372 . V_390 = 0x000F ;
V_84 -> V_85 . V_146 . V_85 . V_372 . V_353 = 0 ;
V_84 -> V_85 . V_146 . V_85 . V_372 . V_346 = 0 ;
V_4 = F_178 ( V_28 , V_82 ,
V_391 + V_392 ,
F_177 , ( void * ) V_366 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 ,
L_157
L_158 , F_50 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_182 ( struct V_27 * V_28 , char T_6 * V_382 )
{
struct V_365 V_366 = { 0 , } ;
int V_4 ;
F_17 ( V_28 , 3 , L_159 ) ;
if ( ! F_53 ( V_28 ,
V_168 ) ) {
F_17 ( V_28 , 3 , L_160 ) ;
V_4 = - V_170 ;
goto V_14;
}
if ( F_183 ( & V_366 , V_382 , 6 ) ) {
V_4 = - V_393 ;
goto V_14;
}
V_366 . V_382 = F_25 ( V_366 . V_378 , V_394 ) ;
if ( ! V_366 . V_382 ) {
V_4 = - V_120 ;
goto V_14;
}
V_366 . V_379 = V_395 ;
V_4 = F_181 ( V_28 , V_20 , & V_366 ) ;
if ( V_4 ) {
if ( F_184 ( V_382 , V_366 . V_382 , 4 ) )
V_4 = - V_393 ;
goto V_396;
} else {
#ifdef F_52
if ( V_366 . V_37 & V_397 ) {
F_181 ( V_28 , V_21 ,
& V_366 ) ;
}
#endif
if ( F_184 ( V_382 , V_366 . V_382 , V_366 . V_378 ) ) {
F_17 ( V_28 , 4 , L_161 ) ;
V_4 = - V_393 ;
goto V_396;
}
F_44 ( V_28 , 4 , L_162 ) ;
}
V_396:
F_15 ( V_366 . V_382 ) ;
V_14:
return V_4 ;
}
static int F_185 ( struct V_27 * V_28 ,
struct V_398 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_163 ) ;
if ( V_28 -> V_99 . V_337 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_82 = F_72 ( V_28 , V_168 ,
V_399 ,
sizeof( struct V_398 ) ,
V_20 ) ;
V_4 = F_73 ( V_28 , V_82 ,
sizeof( struct V_398 ) ,
( unsigned long ) V_53 ,
F_71 , NULL ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_2 ( ( T_3 * ) V_53 -> V_115 , V_1 ) ;
F_49 ( 2 , L_164
L_165 , V_1 , F_50 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_186 ( struct V_27 * V_28 ,
struct V_398 * V_53 )
{
struct V_81 * V_82 ;
char V_1 [ 16 ] = { 0 , } ;
int V_41 ;
int V_4 ;
F_17 ( V_28 , 3 , L_166 ) ;
if ( V_28 -> V_99 . V_337 )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
memcpy ( V_1 , V_53 , 12 ) ;
V_82 = F_72 ( V_28 , V_168 ,
V_400 ,
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
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_187 ( struct V_27 * V_28 )
{
int V_4 ;
int V_41 ;
F_17 ( V_28 , 3 , L_169 ) ;
if ( V_28 -> V_99 . V_337 || ( V_28 -> V_99 . type == V_100 ) )
return - V_170 ;
if ( ! F_53 ( V_28 , V_168 ) ) {
return - V_170 ;
}
V_4 = F_76 ( V_28 , V_168 ,
V_401 , 0 ) ;
if ( V_4 ) {
V_41 = V_4 ;
F_49 ( 2 , L_170
L_158 , F_50 ( V_28 ) ,
F_173 ( & V_4 ) , V_41 , V_41 ) ;
}
return V_4 ;
}
static int F_188 ( struct V_218 * V_125 , struct V_402 * V_403 , int V_84 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
struct V_398 V_404 ;
struct V_405 * V_406 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_407 ;
if ( ( V_28 -> V_71 != V_72 ) &&
( V_28 -> V_71 != V_73 ) )
return - V_407 ;
switch ( V_84 ) {
case V_408 :
if ( ! F_189 ( V_409 ) ) {
V_4 = - V_410 ;
break;
}
V_4 = F_174 ( V_28 , V_403 -> V_411 . V_412 ) ;
break;
case V_413 :
if ( ! F_189 ( V_409 ) ) {
V_4 = - V_410 ;
break;
}
V_4 = F_182 ( V_28 , V_403 -> V_411 . V_414 ) ;
break;
case V_415 :
if ( ! F_189 ( V_409 ) ) {
V_4 = - V_410 ;
break;
}
if ( F_183 ( & V_404 , V_403 -> V_411 . V_414 ,
sizeof( struct V_398 ) ) )
V_4 = - V_393 ;
else
V_4 = F_185 ( V_28 , & V_404 ) ;
break;
case V_416 :
if ( ! F_189 ( V_409 ) ) {
V_4 = - V_410 ;
break;
}
if ( F_183 ( & V_404 , V_403 -> V_411 . V_414 ,
sizeof( struct V_398 ) ) )
V_4 = - V_393 ;
else
V_4 = F_186 ( V_28 , & V_404 ) ;
break;
case V_417 :
if ( ! F_189 ( V_409 ) ) {
V_4 = - V_410 ;
break;
}
V_4 = F_187 ( V_28 ) ;
break;
case V_418 :
V_4 = F_190 ( V_28 , V_403 -> V_411 . V_414 ) ;
break;
case V_419 :
if ( ( V_28 -> V_99 . type == V_420 ||
V_28 -> V_99 . type == V_421 ) &&
! V_28 -> V_99 . V_337 )
return 1 ;
return 0 ;
break;
case V_422 :
V_406 = F_191 ( V_403 ) ;
V_406 -> V_423 = 0 ;
break;
case V_424 :
V_406 = F_191 ( V_403 ) ;
if ( V_406 -> V_423 != 0 )
V_4 = - V_7 ;
else
V_406 -> V_425 = F_192 ( V_125 ,
V_406 -> V_423 ,
V_406 -> V_426 ) ;
break;
case V_427 :
V_4 = F_193 ( V_28 , V_403 -> V_411 . V_414 ) ;
break;
default:
V_4 = - V_170 ;
}
if ( V_4 )
F_44 ( V_28 , 2 , L_171 , V_4 ) ;
return V_4 ;
}
int inline F_194 ( struct V_27 * V_28 , struct V_250 * V_251 )
{
int V_128 = V_428 ;
struct V_429 * V_430 = NULL ;
struct V_431 * V_432 ;
F_110 () ;
V_432 = F_195 ( V_251 ) ;
if ( V_432 )
V_430 = F_196 ( V_432 ) ;
if ( V_430 ) {
V_128 = V_430 -> type ;
F_112 () ;
if ( ( V_128 == V_131 ) ||
( V_128 == V_129 ) ||
( V_128 == V_137 ) )
return V_128 ;
else
return V_428 ;
}
F_112 () ;
if ( V_251 -> V_278 == V_259 )
return ( F_197 ( V_251 ) [ 24 ] == 0xff ) ?
V_129 : 0 ;
else if ( V_251 -> V_278 == V_260 )
return ( ( F_197 ( V_251 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_129 : 0 ;
if ( ! memcmp ( V_251 -> V_85 , V_251 -> V_125 -> V_263 , 6 ) )
return V_131 ;
else {
T_4 V_433 ;
V_433 = * ( ( T_4 * ) V_251 -> V_85 ) ;
switch ( V_28 -> V_99 . V_434 ) {
case V_435 :
case V_436 :
if ( ( V_433 == V_437 ) ||
( V_433 == V_438 ) )
return V_129 ;
break;
default:
if ( ( V_433 == V_439 ) ||
( V_433 == V_440 ) )
return V_129 ;
}
}
return V_128 ;
}
static void F_198 ( struct V_27 * V_28 ,
struct V_252 * V_144 , struct V_250 * V_251 )
{
char V_262 [ 16 ] ;
struct V_441 * V_442 ;
F_199 ( V_251 , 14 ) ;
V_28 -> V_125 -> V_275 -> V_276 ( V_251 , V_28 -> V_125 , 0 ,
V_28 -> V_125 -> V_192 , V_28 -> V_125 -> V_192 ,
V_28 -> V_125 -> V_264 ) ;
F_199 ( V_251 , 14 ) ;
V_442 = (struct V_441 * ) V_251 -> V_85 ;
memset ( V_144 , 0 , sizeof( struct V_252 ) ) ;
V_144 -> V_144 . V_258 . V_298 = V_299 ;
V_144 -> V_144 . V_258 . V_273 = 0 ;
V_144 -> V_144 . V_258 . V_164 = V_251 -> V_23 ;
V_144 -> V_144 . V_258 . V_58 = V_136 | V_133 ;
memset ( V_262 , 0 , sizeof( V_262 ) ) ;
V_262 [ 0 ] = 0xfe ;
V_262 [ 1 ] = 0x80 ;
memcpy ( & V_262 [ 8 ] , V_442 -> V_443 , 8 ) ;
memcpy ( V_144 -> V_144 . V_258 . V_277 , V_262 , 16 ) ;
}
static void F_200 ( struct V_27 * V_28 , struct V_252 * V_144 ,
struct V_250 * V_251 , int V_444 , int V_128 )
{
struct V_431 * V_432 ;
memset ( V_144 , 0 , sizeof( struct V_252 ) ) ;
V_144 -> V_144 . V_258 . V_298 = V_299 ;
V_144 -> V_144 . V_258 . V_273 = 0 ;
if ( F_201 ( V_251 ) ) {
if ( ( V_444 == 4 ) || ( V_28 -> V_99 . type == V_100 ) )
V_144 -> V_144 . V_258 . V_273 = V_279 ;
else
V_144 -> V_144 . V_258 . V_273 = V_280 ;
V_144 -> V_144 . V_258 . V_253 = F_202 ( V_251 ) ;
}
V_144 -> V_144 . V_258 . V_164 = V_251 -> V_23 - sizeof( struct V_252 ) ;
F_110 () ;
V_432 = F_195 ( V_251 ) ;
if ( V_444 == 4 ) {
struct V_445 * V_446 = (struct V_445 * ) V_432 ;
T_7 * V_447 = & V_255 ( V_251 ) -> V_262 ;
if ( V_446 -> V_448 )
V_447 = & V_446 -> V_448 ;
V_144 -> V_144 . V_258 . V_58 = F_62 ( V_128 ) ;
memset ( V_144 -> V_144 . V_258 . V_277 , 0 , 12 ) ;
* ( ( T_7 * ) ( & V_144 -> V_144 . V_258 . V_277 [ 12 ] ) ) = * V_447 ;
} else if ( V_444 == 6 ) {
struct V_449 * V_446 = (struct V_449 * ) V_432 ;
struct V_51 * V_447 = & F_203 ( V_251 ) -> V_262 ;
if ( ! F_204 ( & V_446 -> V_450 ) )
V_447 = & V_446 -> V_450 ;
V_144 -> V_144 . V_258 . V_58 = F_63 ( V_128 ) ;
if ( V_28 -> V_99 . type == V_100 )
V_144 -> V_144 . V_258 . V_58 &= ~ V_135 ;
memcpy ( V_144 -> V_144 . V_258 . V_277 , V_447 , 16 ) ;
} else {
if ( ! memcmp ( V_251 -> V_85 + sizeof( struct V_252 ) ,
V_251 -> V_125 -> V_263 , 6 ) ) {
V_144 -> V_144 . V_258 . V_58 = V_132 |
V_135 ;
} else {
V_144 -> V_144 . V_258 . V_58 = ( V_128 == V_129 ) ?
V_130 | V_135 :
V_133 | V_135 ;
}
}
F_112 () ;
}
static inline void F_205 ( struct V_27 * V_28 ,
struct V_252 * V_144 , struct V_250 * V_251 )
{
struct V_254 * V_451 = V_255 ( V_251 ) ;
if ( V_451 -> V_278 == V_452 )
V_144 -> V_144 . V_258 . V_273 |= V_453 ;
V_144 -> V_144 . V_258 . V_273 |= V_282 |
V_281 ;
V_451 -> V_454 = 0 ;
if ( V_28 -> V_43 . V_313 )
V_28 -> V_314 . V_455 ++ ;
}
static void F_206 ( struct V_27 * V_28 ,
struct V_252 * V_456 , struct V_250 * V_251 )
{
struct V_457 * V_144 = (struct V_457 * ) V_456 ;
struct V_458 * V_459 = F_207 ( V_251 ) ;
struct V_254 * V_451 = V_255 ( V_251 ) ;
struct V_460 * V_461 = F_203 ( V_251 ) ;
V_144 -> V_144 . V_144 . V_258 . V_298 = V_462 ;
V_144 -> V_144 . V_144 . V_258 . V_164 = V_251 -> V_23 - sizeof( struct V_457 ) ;
V_144 -> V_463 . V_464 = ( T_2 ) sizeof( struct V_465 ) ;
V_144 -> V_463 . V_466 = 1 ;
V_144 -> V_463 . V_467 = 1 ;
V_144 -> V_463 . V_468 = 1 ;
V_144 -> V_463 . V_469 = 28 ;
V_144 -> V_463 . V_470 = F_208 ( V_251 ) -> V_471 ;
V_144 -> V_463 . V_472 = ( T_2 ) ( V_451 -> V_473 * 4 + V_459 -> V_474 * 4 ) ;
V_144 -> V_463 . V_475 = ( T_2 ) ( V_251 -> V_23 - V_144 -> V_463 . V_472 -
sizeof( struct V_457 ) ) ;
V_459 -> V_454 = 0 ;
if ( V_251 -> V_278 == V_259 ) {
V_461 -> V_475 = 0 ;
V_459 -> V_454 = ~ F_209 ( & V_461 -> V_476 , & V_461 -> V_262 ,
0 , V_477 , 0 ) ;
} else {
V_459 -> V_454 = ~ F_210 ( V_451 -> V_476 , V_451 -> V_262 ,
0 , V_477 , 0 ) ;
V_451 -> V_478 = 0 ;
V_451 -> V_454 = 0 ;
}
}
static inline int F_211 ( struct V_250 * V_251 )
{
unsigned long V_479 = ( unsigned long ) F_207 ( V_251 ) +
F_207 ( V_251 ) -> V_474 * 4 ;
int V_480 = V_251 -> V_23 - ( V_479 - ( unsigned long ) V_251 -> V_85 ) ;
int V_481 = F_212 ( V_479 + V_480 - 1 ) - F_213 ( V_479 ) ;
V_481 += F_208 ( V_251 ) -> V_482 ;
return V_481 ;
}
static int F_214 ( struct V_250 * V_251 , struct V_218 * V_125 )
{
int V_4 ;
T_4 * V_483 ;
struct V_252 * V_144 = NULL ;
int V_484 = 0 ;
int V_485 ;
struct V_27 * V_28 = V_125 -> V_246 ;
struct V_250 * V_486 = NULL ;
int V_444 = F_215 ( V_251 ) ;
int V_128 = F_194 ( V_28 , V_251 ) ;
struct V_487 * V_488 = V_28 -> V_291 . V_489
[ F_216 ( V_28 , V_251 , V_444 , V_128 ) ] ;
int V_490 = V_251 -> V_23 ;
bool V_491 ;
int V_492 = - 1 ;
int V_482 ;
if ( ( ( V_28 -> V_99 . type == V_100 ) &&
( ( ( V_28 -> V_43 . V_493 != V_494 ) && ! V_444 ) ||
( ( V_28 -> V_43 . V_493 == V_494 ) &&
( V_251 -> V_278 != V_300 ) ) ) ) ||
V_28 -> V_43 . V_44 )
goto V_495;
if ( ( V_28 -> V_71 != V_72 ) || ! V_28 -> V_496 ) {
V_28 -> V_265 . V_497 ++ ;
goto V_495;
}
if ( ( V_128 == V_131 ) &&
( V_28 -> V_99 . V_177 == 0 ) )
goto V_495;
if ( V_28 -> V_43 . V_313 ) {
V_28 -> V_314 . V_498 ++ ;
V_28 -> V_314 . V_499 = F_147 () ;
}
V_491 = F_217 ( V_251 ) ;
if ( ( V_28 -> V_99 . type == V_100 ) && ( ! V_491 ) &&
( F_208 ( V_251 ) -> V_482 == 0 ) ) {
V_486 = V_251 ;
if ( V_486 -> V_278 == V_300 )
V_492 = 0 ;
else
V_492 = V_500 ;
V_144 = F_218 ( V_501 , V_61 ) ;
if ( ! V_144 )
goto V_495;
V_484 ++ ;
} else {
V_486 = F_219 ( V_251 , sizeof( struct V_457 )
+ V_502 ) ;
if ( ! V_486 )
goto V_495;
}
if ( V_28 -> V_99 . type == V_100 ) {
if ( V_492 < 0 )
F_199 ( V_486 , V_500 ) ;
} else {
if ( V_444 == 4 ) {
F_199 ( V_486 , V_500 ) ;
}
if ( V_444 != 4 && F_201 ( V_486 ) ) {
F_220 ( V_486 , V_502 ) ;
F_221 ( V_486 , V_486 -> V_85 + 4 , 4 ) ;
F_222 ( V_486 , 4 ,
V_486 -> V_85 + 8 , 4 ) ;
F_222 ( V_486 , 8 ,
V_486 -> V_85 + 12 , 4 ) ;
V_483 = ( T_4 * ) ( V_486 -> V_85 + 12 ) ;
* V_483 = F_135 ( V_503 ) ;
* ( V_483 + 1 ) = F_134 ( F_202 ( V_486 ) ) ;
}
}
F_223 ( V_125 ) ;
if ( V_491 ) {
if ( F_211 ( V_486 ) + 1 > 16 ) {
if ( F_224 ( V_486 ) )
goto V_495;
if ( V_28 -> V_43 . V_313 )
V_28 -> V_314 . V_504 ++ ;
}
}
if ( V_491 && ( V_128 == V_428 ) ) {
V_144 = (struct V_252 * ) F_220 ( V_486 ,
sizeof( struct V_457 ) ) ;
memset ( V_144 , 0 , sizeof( struct V_457 ) ) ;
F_200 ( V_28 , V_144 , V_486 , V_444 , V_128 ) ;
F_206 ( V_28 , V_144 , V_486 ) ;
V_484 ++ ;
} else {
if ( V_492 < 0 ) {
V_144 = (struct V_252 * ) F_220 ( V_486 ,
sizeof( struct V_252 ) ) ;
F_200 ( V_28 , V_144 , V_486 , V_444 ,
V_128 ) ;
} else {
if ( V_486 -> V_278 == V_300 )
F_198 ( V_28 , V_144 , V_486 ) ;
else {
F_200 ( V_28 , V_144 , V_486 , V_444 ,
V_128 ) ;
V_144 -> V_144 . V_258 . V_164 = V_486 -> V_23 - V_492 ;
}
}
if ( V_251 -> V_283 == V_505 )
F_205 ( V_28 , V_144 , V_486 ) ;
}
V_485 = F_225 ( V_28 , ( void * ) V_144 , V_486 ,
V_484 ) ;
if ( ! V_485 ) {
if ( V_492 >= 0 )
F_226 ( V_501 , V_144 ) ;
goto V_495;
}
V_484 += V_485 ;
V_482 = F_208 ( V_486 ) -> V_482 ;
if ( V_28 -> V_99 . type != V_100 ) {
int V_23 ;
if ( V_491 )
V_23 = ( ( unsigned long ) F_207 ( V_486 ) +
F_207 ( V_486 ) -> V_474 * 4 ) -
( unsigned long ) V_486 -> V_85 ;
else
V_23 = sizeof( struct V_506 ) ;
if ( F_227 ( V_486 , V_23 ) )
goto V_495;
V_4 = F_228 ( V_28 , V_488 , V_486 , V_144 ,
V_484 ) ;
} else
V_4 = F_229 ( V_28 , V_488 , V_486 , V_144 ,
V_484 , V_492 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_265 . V_507 ++ ;
V_28 -> V_265 . V_490 += V_490 ;
if ( V_486 != V_251 )
F_143 ( V_251 ) ;
if ( V_28 -> V_43 . V_313 ) {
if ( V_491 ) {
V_28 -> V_314 . V_508 += V_490 ;
V_28 -> V_314 . V_509 ++ ;
}
if ( V_482 ) {
V_28 -> V_314 . V_510 ++ ;
V_28 -> V_314 . V_511 += V_482 + 1 ;
}
}
V_4 = V_512 ;
} else {
if ( V_492 >= 0 )
F_226 ( V_501 , V_144 ) ;
if ( V_4 == - V_513 ) {
if ( V_486 != V_251 )
F_143 ( V_486 ) ;
return V_514 ;
} else
goto V_495;
}
F_230 ( V_125 ) ;
if ( V_28 -> V_43 . V_313 )
V_28 -> V_314 . V_515 += F_147 () -
V_28 -> V_314 . V_499 ;
return V_4 ;
V_495:
V_28 -> V_265 . V_516 ++ ;
V_28 -> V_265 . V_517 ++ ;
if ( ( V_486 != V_251 ) && V_486 )
F_143 ( V_486 ) ;
F_143 ( V_251 ) ;
F_230 ( V_125 ) ;
return V_512 ;
}
static int F_231 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
int V_4 = 0 ;
F_17 ( V_28 , 4 , L_172 ) ;
if ( V_28 -> V_71 == V_72 )
return V_4 ;
if ( V_28 -> V_71 != V_73 )
return - V_407 ;
V_28 -> V_85 . V_71 = V_332 ;
V_28 -> V_71 = V_72 ;
F_232 ( V_125 ) ;
if ( F_233 ( V_28 -> V_85 . V_319 , 0 ) >= 0 ) {
F_234 ( & V_28 -> V_303 ) ;
F_154 ( & V_28 -> V_303 ) ;
} else
V_4 = - V_185 ;
return V_4 ;
}
static int F_235 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
F_17 ( V_28 , 5 , L_173 ) ;
if ( F_130 ( V_28 , V_248 ) ) {
F_17 ( V_28 , 3 , L_174 ) ;
return - V_518 ;
}
return F_231 ( V_125 ) ;
}
static int F_163 ( struct V_218 * V_125 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
F_17 ( V_28 , 4 , L_175 ) ;
F_236 ( V_125 ) ;
if ( V_28 -> V_71 == V_72 ) {
V_28 -> V_71 = V_73 ;
F_237 ( & V_28 -> V_303 ) ;
}
return 0 ;
}
static T_8 F_238 ( struct V_218 * V_125 ,
T_8 V_187 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
if ( ! F_53 ( V_28 , V_158 ) )
V_187 &= ~ V_519 ;
if ( ! F_53 ( V_28 , V_190 ) )
V_187 &= ~ V_191 ;
if ( ! F_53 ( V_28 , V_153 ) )
V_187 &= ~ V_188 ;
return V_187 ;
}
static int F_239 ( struct V_218 * V_125 ,
T_8 V_187 )
{
struct V_27 * V_28 = V_125 -> V_246 ;
T_9 V_520 = V_125 -> V_187 ^ V_187 ;
int V_521 ;
if ( ! ( V_520 & V_188 ) )
return 0 ;
if ( V_28 -> V_71 == V_335 ||
V_28 -> V_71 == V_522 )
return 0 ;
V_521 = F_88 ( V_28 , V_187 & V_188 ) ;
if ( V_521 )
V_125 -> V_187 = V_187 ^ V_188 ;
return V_521 ;
}
static int F_240 ( struct V_429 * V_430 )
{
V_430 -> V_523 = V_524 ;
memcpy ( V_430 -> V_525 , L_125 , 6 ) ;
V_430 -> V_526 = V_430 -> V_527 -> V_528 ;
return 0 ;
}
static int
F_241 ( struct V_218 * V_125 , struct V_529 * V_530 )
{
if ( V_530 -> V_531 -> V_532 == V_533 )
V_530 -> V_534 = F_240 ;
return 0 ;
}
static int F_242 ( struct V_27 * V_28 )
{
if ( V_28 -> V_99 . type == V_420 ||
V_28 -> V_99 . type == V_421 ) {
if ( ( V_28 -> V_99 . V_434 == V_436 ) ||
( V_28 -> V_99 . V_434 == V_435 ) ) {
F_243 ( L_176 ) ;
return - V_407 ;
} else {
V_28 -> V_125 = F_244 ( 0 ) ;
if ( ! V_28 -> V_125 )
return - V_407 ;
V_28 -> V_125 -> V_535 = & V_536 ;
F_101 ( V_28 ) ;
if ( ! ( V_28 -> V_99 . V_194 & V_198 ) )
V_28 -> V_125 -> V_537 = V_28 -> V_99 . V_194 &
0xffff ;
if ( ! V_28 -> V_99 . V_337 ) {
V_28 -> V_125 -> V_538 = V_539 |
V_188 | V_519 |
V_191 ;
V_28 -> V_125 -> V_187 = V_188 ;
}
}
} else if ( V_28 -> V_99 . type == V_100 ) {
V_28 -> V_125 = F_245 ( 0 , L_177 , V_540 ) ;
if ( ! V_28 -> V_125 )
return - V_407 ;
V_28 -> V_125 -> V_58 |= V_541 ;
V_28 -> V_125 -> V_535 = & V_542 ;
F_99 ( V_28 ) ;
if ( V_28 -> V_43 . V_543 [ 0 ] )
memcpy ( V_28 -> V_125 -> V_544 , V_28 -> V_43 . V_543 , 9 ) ;
} else
return - V_407 ;
V_28 -> V_125 -> V_246 = V_28 ;
V_28 -> V_125 -> V_545 = V_546 ;
V_28 -> V_125 -> V_547 = V_28 -> V_99 . V_548 ;
F_246 ( V_28 -> V_125 , & V_549 ) ;
V_28 -> V_125 -> V_187 |= V_550 |
V_551 |
V_552 ;
V_28 -> V_125 -> V_553 &= ~ V_554 ;
V_28 -> V_125 -> V_555 = 15 * V_556 ;
F_247 ( V_28 -> V_125 , & V_28 -> V_124 -> V_125 ) ;
F_248 ( V_28 -> V_125 , & V_28 -> V_303 , F_145 , V_557 ) ;
return F_249 ( V_28 -> V_125 ) ;
}
static int F_250 ( struct V_558 * V_124 )
{
struct V_27 * V_28 = F_251 ( & V_124 -> V_125 ) ;
F_252 ( & V_124 -> V_125 ) ;
V_28 -> V_43 . V_329 = 0 ;
V_28 -> V_99 . V_559 = 0 ;
return 0 ;
}
static void F_253 ( struct V_558 * V_560 )
{
struct V_27 * V_28 = F_251 ( & V_560 -> V_125 ) ;
F_254 ( & V_560 -> V_125 ) ;
F_162 ( V_28 , 0 , 1 ) ;
F_255 ( V_28 -> V_561 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_560 -> V_71 == V_562 )
F_256 ( V_560 ) ;
if ( V_28 -> V_125 ) {
F_257 ( V_28 -> V_125 ) ;
V_28 -> V_125 = NULL ;
}
F_37 ( V_28 , 0 ) ;
F_54 ( V_28 ) ;
return;
}
static int F_258 ( struct V_558 * V_124 , int V_330 )
{
struct V_27 * V_28 = F_251 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
enum V_563 V_564 ;
F_138 ( ! V_28 ) ;
F_259 ( & V_28 -> V_565 ) ;
F_259 ( & V_28 -> V_566 ) ;
F_65 ( V_139 , 2 , L_178 ) ;
F_144 ( V_139 , 2 , & V_28 , sizeof( void * ) ) ;
V_564 = V_28 -> V_71 ;
V_4 = F_260 ( V_28 ) ;
if ( V_4 ) {
F_261 ( V_139 , 2 , L_179 , V_4 ) ;
V_4 = - V_407 ;
goto V_567;
}
if ( ! V_28 -> V_125 && F_242 ( V_28 ) ) {
V_4 = - V_407 ;
goto V_567;
}
if ( F_262 ( V_28 , V_568 ) ) {
if ( V_28 -> V_99 . V_559 &&
F_263 ( V_28 , V_569 ) )
V_28 -> V_99 . V_559 = 0 ;
} else
V_28 -> V_99 . V_559 = 0 ;
V_28 -> V_71 = V_334 ;
memset ( & V_28 -> V_294 , 0 , sizeof( struct V_570 ) ) ;
F_264 ( V_28 ) ;
F_65 ( V_139 , 2 , L_180 ) ;
V_4 = F_265 ( V_28 ) ;
if ( V_4 ) {
F_261 ( V_139 , 2 , L_181 , V_4 ) ;
if ( V_4 == 0xe080 ) {
F_61 ( & V_28 -> V_124 -> V_125 ,
L_182 ) ;
V_28 -> V_496 = 0 ;
goto V_571;
}
V_4 = - V_407 ;
goto V_567;
} else
V_28 -> V_496 = 1 ;
V_571:
V_4 = F_64 ( V_28 ) ;
if ( V_4 )
F_261 ( V_139 , 2 , L_179 , V_4 ) ;
if ( ! V_28 -> V_43 . V_44 ) {
V_4 = F_95 ( V_28 ) ;
if ( V_4 )
F_261 ( V_139 , 2 , L_183 , V_4 ) ;
V_4 = F_48 ( V_28 ) ;
if ( V_4 )
F_261 ( V_139 , 2 , L_184 , V_4 ) ;
V_4 = F_51 ( V_28 ) ;
if ( V_4 )
F_261 ( V_139 , 2 , L_185 , V_4 ) ;
}
F_236 ( V_28 -> V_125 ) ;
V_4 = F_266 ( V_28 ) ;
if ( V_4 ) {
F_261 ( V_139 , 2 , L_186 , V_4 ) ;
V_4 = - V_407 ;
goto V_567;
}
V_28 -> V_71 = V_73 ;
F_162 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_496 )
F_267 ( V_28 -> V_125 ) ;
else
F_268 ( V_28 -> V_125 ) ;
if ( V_564 == V_522 ) {
F_90 () ;
if ( V_330 )
F_231 ( V_28 -> V_125 ) ;
else
F_269 ( V_28 -> V_125 ) ;
F_132 ( V_28 -> V_125 ) ;
F_92 () ;
}
F_270 ( & V_124 -> V_125 . V_572 , V_573 ) ;
F_271 ( & V_28 -> V_566 ) ;
F_271 ( & V_28 -> V_565 ) ;
return 0 ;
V_567:
F_161 ( V_28 , 0 ) ;
F_272 ( F_273 ( V_28 ) ) ;
F_272 ( F_274 ( V_28 ) ) ;
F_272 ( F_275 ( V_28 ) ) ;
if ( V_564 == V_522 )
V_28 -> V_71 = V_522 ;
else
V_28 -> V_71 = V_335 ;
F_271 ( & V_28 -> V_566 ) ;
F_271 ( & V_28 -> V_565 ) ;
return V_4 ;
}
static int F_276 ( struct V_558 * V_124 )
{
return F_258 ( V_124 , 0 ) ;
}
static int F_277 ( struct V_558 * V_560 ,
int V_330 )
{
struct V_27 * V_28 = F_251 ( & V_560 -> V_125 ) ;
int V_4 = 0 , V_574 = 0 , V_575 = 0 ;
enum V_563 V_564 ;
F_259 ( & V_28 -> V_565 ) ;
F_259 ( & V_28 -> V_566 ) ;
F_65 ( V_139 , 3 , L_187 ) ;
F_144 ( V_139 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_125 && F_278 ( V_28 -> V_125 ) )
F_268 ( V_28 -> V_125 ) ;
V_564 = V_28 -> V_71 ;
if ( ( ! V_330 && V_28 -> V_99 . V_559 ) || V_28 -> V_99 . V_559 == 2 ) {
F_263 ( V_28 , V_576 ) ;
V_28 -> V_99 . V_559 = 1 ;
}
F_161 ( V_28 , V_330 ) ;
if ( ( V_28 -> V_43 . V_493 == V_494 ) && V_28 -> V_125 ) {
F_90 () ;
F_279 ( V_577 , V_28 -> V_125 ) ;
F_92 () ;
}
V_4 = F_272 ( F_273 ( V_28 ) ) ;
V_574 = F_272 ( F_274 ( V_28 ) ) ;
V_575 = F_272 ( F_275 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_574 ) ? V_574 : V_575 ;
if ( V_4 )
F_261 ( V_139 , 2 , L_181 , V_4 ) ;
if ( V_564 == V_72 )
V_28 -> V_71 = V_522 ;
F_270 ( & V_560 -> V_125 . V_572 , V_573 ) ;
F_271 ( & V_28 -> V_566 ) ;
F_271 ( & V_28 -> V_565 ) ;
return 0 ;
}
static int F_256 ( struct V_558 * V_560 )
{
return F_277 ( V_560 , 0 ) ;
}
static int F_280 ( void * V_578 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_578 ;
F_17 ( V_28 , 2 , L_188 ) ;
F_20 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_281 ( V_28 , V_248 ) )
return 0 ;
F_17 ( V_28 , 2 , L_189 ) ;
F_61 ( & V_28 -> V_124 -> V_125 ,
L_190 ) ;
F_277 ( V_28 -> V_124 , 1 ) ;
V_4 = F_258 ( V_28 -> V_124 , 1 ) ;
if ( ! V_4 )
F_66 ( & V_28 -> V_124 -> V_125 ,
L_191 ) ;
else {
F_90 () ;
F_164 ( V_28 -> V_125 ) ;
F_92 () ;
F_61 ( & V_28 -> V_124 -> V_125 , L_192
L_193 ) ;
}
F_282 ( V_28 , V_248 ) ;
F_283 ( V_28 , V_248 ) ;
return 0 ;
}
static void F_284 ( struct V_558 * V_124 )
{
struct V_27 * V_28 = F_251 ( & V_124 -> V_125 ) ;
F_162 ( V_28 , 0 , 1 ) ;
if ( ( V_124 -> V_71 == V_562 ) && V_28 -> V_99 . V_559 )
F_263 ( V_28 , V_576 ) ;
F_166 ( V_28 , 0 ) ;
F_167 ( V_28 ) ;
}
static int F_285 ( struct V_558 * V_124 )
{
struct V_27 * V_28 = F_251 ( & V_124 -> V_125 ) ;
if ( V_28 -> V_125 )
F_286 ( V_28 -> V_125 ) ;
F_162 ( V_28 , 0 , 1 ) ;
F_255 ( V_28 -> V_561 , F_172 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_124 -> V_71 == V_579 )
return 0 ;
if ( V_28 -> V_71 == V_72 ) {
if ( V_28 -> V_99 . V_559 )
F_263 ( V_28 , V_576 ) ;
F_277 ( V_28 -> V_124 , 1 ) ;
} else
F_277 ( V_28 -> V_124 , 0 ) ;
return 0 ;
}
static int F_287 ( struct V_558 * V_124 )
{
struct V_27 * V_28 = F_251 ( & V_124 -> V_125 ) ;
int V_4 = 0 ;
if ( V_124 -> V_71 == V_579 )
goto V_14;
if ( V_28 -> V_71 == V_522 ) {
V_4 = F_258 ( V_28 -> V_124 , 1 ) ;
if ( V_4 ) {
F_90 () ;
F_164 ( V_28 -> V_125 ) ;
F_92 () ;
}
} else
V_4 = F_258 ( V_28 -> V_124 , 0 ) ;
V_14:
F_162 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_125 )
F_288 ( V_28 -> V_125 ) ;
if ( V_4 )
F_61 ( & V_28 -> V_124 -> V_125 , L_192
L_193 ) ;
return V_4 ;
}
static int F_289 ( struct V_580 * V_581 ,
unsigned long V_582 , void * V_578 )
{
struct V_238 * V_239 = (struct V_238 * ) V_578 ;
struct V_218 * V_125 = (struct V_218 * ) V_239 -> V_583 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_290 ( V_125 ) != & V_584 )
return V_585 ;
V_28 = F_160 ( V_125 ) ;
if ( ! V_28 )
return V_585 ;
F_17 ( V_28 , 3 , L_194 ) ;
V_2 = F_24 ( V_20 ) ;
if ( V_2 != NULL ) {
V_2 -> V_36 . V_47 . V_2 = V_239 -> V_242 ;
V_2 -> V_36 . V_47 . V_48 = V_239 -> V_243 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_582 ) {
case V_586 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_587 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_585 ;
}
static int F_291 ( struct V_580 * V_581 ,
unsigned long V_582 , void * V_578 )
{
struct V_244 * V_239 = (struct V_244 * ) V_578 ;
struct V_218 * V_125 = (struct V_218 * ) V_239 -> V_588 -> V_125 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_160 ( V_125 ) ;
if ( ! V_28 )
return V_585 ;
F_17 ( V_28 , 3 , L_195 ) ;
if ( ! F_53 ( V_28 , V_110 ) )
return V_585 ;
V_2 = F_24 ( V_21 ) ;
if ( V_2 != NULL ) {
memcpy ( & V_2 -> V_36 . V_49 . V_2 , & V_239 -> V_2 , sizeof( struct V_51 ) ) ;
V_2 -> V_36 . V_49 . V_50 = V_239 -> V_245 ;
V_2 -> type = V_55 ;
} else
goto V_14;
switch ( V_582 ) {
case V_586 :
if ( ! F_23 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
case V_587 :
if ( ! F_19 ( V_28 , V_2 ) )
F_15 ( V_2 ) ;
break;
default:
break;
}
F_32 ( V_28 ) ;
V_14:
return V_585 ;
}
static int F_292 ( void )
{
int V_4 ;
F_65 ( V_139 , 5 , L_196 ) ;
V_4 = F_293 ( & V_589 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_52
V_4 = F_294 ( & V_590 ) ;
if ( V_4 ) {
F_295 ( & V_589 ) ;
return V_4 ;
}
#else
F_296 ( L_197 ) ;
#endif
return 0 ;
}
static void F_297 ( void )
{
F_65 ( V_139 , 5 , L_198 ) ;
F_138 ( F_295 ( & V_589 ) ) ;
#ifdef F_52
F_138 ( F_298 ( & V_590 ) ) ;
#endif
}
static int T_10 F_299 ( void )
{
int V_4 = 0 ;
F_243 ( L_199 ) ;
V_4 = F_292 () ;
return V_4 ;
}
static void T_11 F_300 ( void )
{
F_297 () ;
F_243 ( L_200 ) ;
}
