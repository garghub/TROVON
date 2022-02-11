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
sprintf ( V_1 , L_1 , V_2 ) ;
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
inline int
F_12 ( struct V_29 * V_40 , struct V_29 * V_41 )
{
return V_40 -> V_19 == V_41 -> V_19 &&
! memcmp ( & V_40 -> V_36 , & V_41 -> V_36 , sizeof( V_40 -> V_36 ) ) &&
! memcmp ( & V_40 -> V_42 , & V_41 -> V_42 , sizeof( V_40 -> V_42 ) ) ;
}
static struct V_29 *
F_13 ( struct V_27 * V_28 , struct V_29 * V_43 )
{
struct V_29 * V_2 ;
if ( V_43 -> V_44 ) {
F_14 (card->ip_mc_htable, addr,
hnode, qeth_l3_ipaddr_hash(tmp_addr))
if ( F_12 ( V_43 , V_2 ) )
return V_2 ;
} else {
F_14 (card->ip_htable, addr,
hnode, qeth_l3_ipaddr_hash(tmp_addr))
if ( F_12 ( V_43 , V_2 ) )
return V_2 ;
}
return NULL ;
}
int F_15 ( struct V_27 * V_28 , struct V_29 * V_43 )
{
int V_4 = 0 ;
struct V_29 * V_2 ;
F_16 ( V_28 , 4 , L_5 ) ;
if ( V_43 -> V_19 == V_20 )
F_17 ( V_28 , 4 , & V_43 -> V_36 . V_45 . V_2 , 4 ) ;
else {
F_17 ( V_28 , 4 , & V_43 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 4 , ( ( char * ) & V_43 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
}
V_2 = F_13 ( V_28 , V_43 ) ;
if ( ! V_2 )
return - V_47 ;
V_2 -> V_48 -- ;
if ( V_2 -> V_48 > 0 && ( V_2 -> type == V_49 ||
V_2 -> type == V_50 ) )
return V_4 ;
if ( V_2 -> V_51 )
return - V_52 ;
if ( ! F_18 ( V_28 ) ) {
V_2 -> V_53 = V_54 ;
return 0 ;
}
V_4 = F_19 ( V_28 , V_2 ) ;
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
return V_4 ;
}
int F_22 ( struct V_27 * V_28 , struct V_29 * V_43 )
{
int V_4 = 0 ;
struct V_29 * V_2 ;
F_16 ( V_28 , 4 , L_6 ) ;
if ( V_43 -> V_19 == V_20 )
F_17 ( V_28 , 4 , & V_43 -> V_36 . V_45 . V_2 , 4 ) ;
else {
F_17 ( V_28 , 4 , & V_43 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 4 , ( ( char * ) & V_43 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
}
V_2 = F_13 ( V_28 , V_43 ) ;
if ( ! V_2 ) {
V_2 = F_23 ( V_43 -> V_19 ) ;
if ( ! V_2 )
return - V_56 ;
memcpy ( V_2 , V_43 , sizeof( struct V_29 ) ) ;
V_2 -> V_48 = 1 ;
if ( V_2 -> type == V_49 &&
F_9 ( V_28 , V_2 ) ) {
F_16 ( V_28 , 2 , L_7 ) ;
V_2 -> V_57 |= V_58 ;
}
F_24 ( V_28 -> V_59 , & V_2 -> V_55 ,
F_25 ( V_2 ) ) ;
if ( ! F_18 ( V_28 ) ) {
V_2 -> V_53 = V_60 ;
return 0 ;
}
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_51 = 1 ;
F_26 ( & V_28 -> V_61 ) ;
V_4 = F_27 ( V_28 , V_2 ) ;
F_28 ( & V_28 -> V_61 ) ;
V_2 -> V_51 = 0 ;
} else
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_62 ) ||
( V_4 == V_63 ) ) {
V_2 -> V_53 = V_64 ;
if ( V_2 -> V_48 < 1 ) {
F_15 ( V_28 , V_2 ) ;
F_21 ( V_2 ) ;
}
} else {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
}
} else {
if ( V_2 -> type == V_49 ||
V_2 -> type == V_50 )
V_2 -> V_48 ++ ;
}
return V_4 ;
}
struct V_29 * F_23 (
enum V_18 V_65 )
{
struct V_29 * V_2 ;
V_2 = F_29 ( sizeof( struct V_29 ) , V_66 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type = V_49 ;
V_2 -> V_53 = V_64 ;
V_2 -> V_19 = V_65 ;
return V_2 ;
}
static void F_30 ( struct V_27 * V_28 , int V_67 )
{
struct V_29 * V_2 ;
struct V_68 * V_69 ;
int V_24 ;
F_16 ( V_28 , 4 , L_8 ) ;
if ( V_67 && V_28 -> V_70 . V_71 )
return;
F_28 ( & V_28 -> V_61 ) ;
F_31 (card->ip_htable, i, tmp, addr, hnode) {
if ( ! V_67 ) {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
continue;
}
V_2 -> V_53 = V_60 ;
}
F_26 ( & V_28 -> V_61 ) ;
F_28 ( & V_28 -> V_72 ) ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
}
F_26 ( & V_28 -> V_72 ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_68 * V_69 ;
int V_24 ;
int V_4 ;
F_16 ( V_28 , 4 , L_9 ) ;
F_28 ( & V_28 -> V_61 ) ;
F_31 (card->ip_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_53 == V_54 ) {
F_19 ( V_28 , V_2 ) ;
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
} else if ( V_2 -> V_53 == V_60 ) {
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_51 = 1 ;
F_26 ( & V_28 -> V_61 ) ;
V_4 = F_27 ( V_28 , V_2 ) ;
F_28 ( & V_28 -> V_61 ) ;
V_2 -> V_51 = 0 ;
} else
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 ) {
V_2 -> V_53 = V_64 ;
if ( V_2 -> V_48 < 1 )
F_15 ( V_28 , V_2 ) ;
} else {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
}
}
}
F_26 ( & V_28 -> V_61 ) ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_73 )
{
int V_4 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
F_16 ( V_28 , 4 , L_10 ) ;
V_75 = F_34 ( V_28 , V_73 , V_2 -> V_19 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
memcpy ( & V_77 -> V_78 . V_80 . V_42 , V_2 -> V_42 , V_81 ) ;
if ( V_2 -> V_19 == V_21 )
memcpy ( V_77 -> V_78 . V_80 . V_82 , & V_2 -> V_36 . V_46 . V_2 ,
sizeof( struct V_83 ) ) ;
else
memcpy ( & V_77 -> V_78 . V_80 . V_84 , & V_2 -> V_36 . V_45 . V_2 , 4 ) ;
V_4 = F_35 ( V_28 , V_75 , NULL , NULL ) ;
return V_4 ;
}
static void F_36 ( T_3 * V_85 , unsigned int V_23 )
{
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_25 = ( V_23 ) - ( V_24 * 8 ) ;
if ( V_25 >= 8 )
V_85 [ V_24 ] = 0xff ;
else if ( V_25 > 0 )
V_85 [ V_24 ] = ( T_3 ) ( 0xFF00 >> V_25 ) ;
else
V_85 [ V_24 ] = 0 ;
}
}
static int F_37 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_73 , unsigned int V_86 )
{
int V_4 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
T_1 V_85 [ 16 ] ;
F_16 ( V_28 , 4 , L_11 ) ;
F_38 ( V_28 , 4 , L_12 , V_86 ) ;
V_75 = F_34 ( V_28 , V_73 , V_2 -> V_19 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
if ( V_2 -> V_19 == V_21 ) {
memcpy ( V_77 -> V_78 . V_87 . V_88 , & V_2 -> V_36 . V_46 . V_2 ,
sizeof( struct V_83 ) ) ;
F_36 ( V_85 , V_2 -> V_36 . V_46 . V_89 ) ;
memcpy ( V_77 -> V_78 . V_87 . V_90 , V_85 ,
sizeof( struct V_83 ) ) ;
V_77 -> V_78 . V_87 . V_86 = V_86 ;
} else {
memcpy ( V_77 -> V_78 . V_91 . V_88 , & V_2 -> V_36 . V_45 . V_2 , 4 ) ;
memcpy ( V_77 -> V_78 . V_91 . V_90 , & V_2 -> V_36 . V_45 . V_90 , 4 ) ;
V_77 -> V_78 . V_91 . V_86 = V_86 ;
}
V_4 = F_35 ( V_28 , V_75 , NULL , NULL ) ;
return V_4 ;
}
static int F_39 ( struct V_27 * V_28 ,
enum V_92 type , enum V_18 V_65 )
{
int V_4 ;
struct V_76 * V_77 ;
struct V_74 * V_75 ;
F_16 ( V_28 , 4 , L_13 ) ;
V_75 = F_34 ( V_28 , V_93 , V_65 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
V_77 -> V_78 . V_94 . type = ( type ) ;
V_4 = F_35 ( V_28 , V_75 , NULL , NULL ) ;
return V_4 ;
}
static int F_40 ( struct V_27 * V_28 ,
enum V_92 * type , enum V_18 V_65 )
{
if ( V_28 -> V_95 . type == V_96 ) {
switch ( * type ) {
case V_97 :
case V_98 :
case V_99 :
case V_100 :
return 0 ;
default:
goto V_101;
}
} else {
switch ( * type ) {
case V_97 :
case V_102 :
case V_103 :
return 0 ;
case V_100 :
if ( F_41 ( V_28 , V_65 ,
V_104 ) )
return 0 ;
default:
goto V_101;
}
}
V_101:
* type = V_97 ;
return - V_7 ;
}
int F_42 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_14 ) ;
V_4 = F_40 ( V_28 , & V_28 -> V_70 . V_105 . type ,
V_20 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_39 ( V_28 , V_28 -> V_70 . V_105 . type ,
V_20 ) ;
if ( V_4 ) {
V_28 -> V_70 . V_105 . type = V_97 ;
F_43 ( 2 , L_15
L_16 , V_4 ,
F_44 ( V_28 ) ) ;
}
return V_4 ;
}
int F_45 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_17 ) ;
#ifdef F_46
if ( ! F_47 ( V_28 , V_106 ) )
return 0 ;
V_4 = F_40 ( V_28 , & V_28 -> V_70 . V_107 . type ,
V_21 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_39 ( V_28 , V_28 -> V_70 . V_107 . type ,
V_21 ) ;
if ( V_4 ) {
V_28 -> V_70 . V_107 . type = V_97 ;
F_43 ( 2 , L_15
L_16 , V_4 ,
F_44 ( V_28 ) ) ;
}
#endif
return V_4 ;
}
static void F_48 ( struct V_27 * V_28 )
{
struct V_30 * V_31 , * V_69 ;
F_28 ( & V_28 -> V_61 ) ;
F_49 (ipatoe, tmp, &card->ipato.entries, entry) {
F_50 ( & V_31 -> V_108 ) ;
F_21 ( V_31 ) ;
}
F_26 ( & V_28 -> V_61 ) ;
}
int F_51 ( struct V_27 * V_28 ,
struct V_30 * V_109 )
{
struct V_30 * V_31 ;
int V_4 = 0 ;
F_16 ( V_28 , 2 , L_18 ) ;
F_28 ( & V_28 -> V_61 ) ;
F_10 (ipatoe, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_109 -> V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_109 -> V_2 ,
( V_31 -> V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_109 -> V_37 ) ) {
V_4 = - V_110 ;
break;
}
}
if ( ! V_4 )
F_52 ( & V_109 -> V_108 , & V_28 -> V_34 . V_111 ) ;
F_26 ( & V_28 -> V_61 ) ;
return V_4 ;
}
void F_53 ( struct V_27 * V_28 ,
enum V_18 V_19 , T_3 * V_2 , int V_37 )
{
struct V_30 * V_31 , * V_69 ;
F_16 ( V_28 , 2 , L_19 ) ;
F_28 ( & V_28 -> V_61 ) ;
F_49 (ipatoe, tmp, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_2 ,
( V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_37 ) ) {
F_50 ( & V_31 -> V_108 ) ;
F_21 ( V_31 ) ;
}
}
F_26 ( & V_28 -> V_61 ) ;
}
int F_54 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_112 ;
int V_4 = 0 ;
V_112 = F_23 ( V_19 ) ;
if ( V_112 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_20 ) ;
memcpy ( & V_112 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_112 -> V_36 . V_45 . V_90 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_21 ) ;
memcpy ( & V_112 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_112 -> V_36 . V_46 . V_89 = 0 ;
}
V_112 -> type = V_113 ;
V_112 -> V_57 = V_114 ;
V_112 -> V_115 = V_116 ;
} else
return - V_56 ;
F_28 ( & V_28 -> V_61 ) ;
if ( F_13 ( V_28 , V_112 ) )
V_4 = - V_110 ;
else
F_22 ( V_28 , V_112 ) ;
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_112 ) ;
return V_4 ;
}
void F_55 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_112 ;
V_112 = F_23 ( V_19 ) ;
if ( V_112 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_22 ) ;
memcpy ( & V_112 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_112 -> V_36 . V_45 . V_90 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_23 ) ;
memcpy ( & V_112 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_112 -> V_36 . V_46 . V_89 = 0 ;
}
V_112 -> type = V_113 ;
} else
return;
F_28 ( & V_28 -> V_61 ) ;
F_15 ( V_28 , V_112 ) ;
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_112 ) ;
}
int F_56 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_112 ;
int V_4 = 0 ;
V_112 = F_23 ( V_19 ) ;
if ( V_112 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_24 ) ;
memcpy ( & V_112 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_112 -> V_36 . V_45 . V_90 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_25 ) ;
memcpy ( & V_112 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_112 -> V_36 . V_46 . V_89 = 0 ;
}
V_112 -> type = V_50 ;
V_112 -> V_57 = V_58 ;
V_112 -> V_115 = 0 ;
} else
return - V_56 ;
F_28 ( & V_28 -> V_61 ) ;
if ( F_13 ( V_28 , V_112 ) )
V_4 = - V_110 ;
else
F_22 ( V_28 , V_112 ) ;
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_112 ) ;
return V_4 ;
}
void F_57 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_112 ;
V_112 = F_23 ( V_19 ) ;
if ( V_112 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_26 ) ;
memcpy ( & V_112 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_112 -> V_36 . V_45 . V_90 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_27 ) ;
memcpy ( & V_112 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_112 -> V_36 . V_46 . V_89 = 0 ;
}
V_112 -> type = V_50 ;
} else
return;
F_28 ( & V_28 -> V_61 ) ;
F_15 ( V_28 , V_112 ) ;
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_112 ) ;
}
static int F_27 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
char V_1 [ 50 ] ;
int V_4 = 0 ;
int V_13 = 3 ;
if ( V_2 -> V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_28 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_45 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_29 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
} else {
F_16 ( V_28 , 2 , L_30 ) ;
F_17 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
do {
if ( V_2 -> V_44 )
V_4 = F_33 ( V_28 , V_2 , V_117 ) ;
else
V_4 = F_37 ( V_28 , V_2 , V_118 ,
V_2 -> V_57 ) ;
if ( V_4 )
F_16 ( V_28 , 2 , L_31 ) ;
} while ( ( -- V_13 > 0 ) && V_4 );
if ( V_4 ) {
F_16 ( V_28 , 2 , L_32 ) ;
F_6 ( V_2 -> V_19 , ( T_3 * ) & V_2 -> V_36 , V_1 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_33 , V_1 ) ;
}
return V_4 ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_34 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_45 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_35 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
} else {
F_16 ( V_28 , 2 , L_36 ) ;
F_17 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
if ( V_2 -> V_44 )
V_4 = F_33 ( V_28 , V_2 , V_121 ) ;
else
V_4 = F_37 ( V_28 , V_2 , V_122 ,
V_2 -> V_115 ) ;
if ( V_4 )
F_16 ( V_28 , 2 , L_31 ) ;
return V_4 ;
}
static T_3 F_59 ( int V_123 )
{
if ( V_123 == V_124 )
return V_125 ;
if ( V_123 == V_126 )
return V_127 ;
return V_128 ;
}
static T_3 F_60 ( int V_123 )
{
T_3 V_129 = V_130 | V_131 ;
if ( V_123 == V_124 )
return V_129 | V_125 ;
if ( V_123 == V_132 )
return V_129 | V_133 ;
if ( V_123 == V_126 )
return V_129 | V_127 ;
return V_129 | V_128 ;
}
static int F_61 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_62 ( V_134 , 2 , L_37 ) ;
if ( F_63 ( V_28 , V_135 ) ) {
V_4 = F_64 ( V_28 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_38
L_39 ) ;
}
return V_4 ;
}
static int F_65 ( struct V_27 * V_28 ,
enum V_136 V_137 , T_2 V_138 )
{
int V_4 ;
struct V_74 * V_75 ;
F_16 ( V_28 , 4 , L_40 ) ;
V_75 = F_66 ( V_28 , V_137 , V_138 ,
0 , V_21 ) ;
if ( ! V_75 )
return - V_56 ;
V_4 = F_67 ( V_28 , V_75 , 0 , 0 ,
V_139 , NULL ) ;
return V_4 ;
}
static int F_68 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_41 ) ;
if ( ! F_47 ( V_28 , V_140 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_42 ,
F_44 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_70 ( V_28 , V_140 ,
V_141 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_43 ,
F_44 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_71 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_44 ) ;
if ( ! F_47 ( V_28 , V_142 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_45 ,
F_44 ( V_28 ) ) ;
return - V_143 ;
}
V_4 = F_70 ( V_28 , V_142 ,
V_141 , 0 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 ,
L_46 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
static int F_72 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_47 ) ;
if ( ! F_47 ( V_28 , V_144 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_48 , F_44 ( V_28 ) ) ;
return - V_143 ;
}
V_4 = F_70 ( V_28 , V_145 ,
V_141 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_49 ,
F_44 ( V_28 ) ) ;
} else {
F_69 ( & V_28 -> V_119 -> V_120 , L_50 ) ;
}
return V_4 ;
}
static int F_73 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_51 ) ;
if ( ! F_47 ( V_28 , V_146 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_52 ,
F_44 ( V_28 ) ) ;
return - V_143 ;
}
V_4 = F_70 ( V_28 , V_146 ,
V_141 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_53 ,
F_44 ( V_28 ) ) ;
} else {
F_69 ( & V_28 -> V_119 -> V_120 , L_54 ) ;
V_28 -> V_120 -> V_86 |= V_147 ;
}
return V_4 ;
}
static int F_74 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_55 ) ;
V_4 = F_75 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_76 ( & V_28 -> V_119 -> V_120 ,
L_56 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
if ( V_28 -> V_95 . type == V_96 )
goto V_14;
V_4 = F_70 ( V_28 , V_106 ,
V_141 , 3 ) ;
if ( V_4 ) {
F_76 ( & V_28 -> V_119 -> V_120 ,
L_56 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_65 ( V_28 , V_106 ,
V_141 ) ;
if ( V_4 ) {
F_76 ( & V_28 -> V_119 -> V_120 ,
L_56 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_65 ( V_28 , V_148 ,
V_141 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_57 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_69 ( & V_28 -> V_119 -> V_120 , L_58 ) ;
return 0 ;
}
static int F_77 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_59 ) ;
if ( ! F_47 ( V_28 , V_106 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_60 , F_44 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_46
V_4 = F_74 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_78 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_61 ) ;
V_28 -> V_95 . V_149 = 0 ;
if ( ! F_47 ( V_28 , V_150 ) ) {
F_69 ( & V_28 -> V_119 -> V_120 ,
L_62 ,
F_44 ( V_28 ) ) ;
V_4 = - V_143 ;
goto V_14;
}
V_4 = F_70 ( V_28 , V_150 ,
V_141 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_63
L_64 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_70 ( V_28 , V_150 ,
V_151 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_65 ,
F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_95 . V_149 = V_152 ;
F_69 ( & V_28 -> V_119 -> V_120 , L_66 ) ;
V_4 = F_70 ( V_28 , V_150 ,
V_153 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_67
L_68 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_95 . V_149 = V_154 ;
V_14:
if ( V_28 -> V_95 . V_149 )
V_28 -> V_120 -> V_86 |= V_155 ;
else
V_28 -> V_120 -> V_86 &= ~ V_155 ;
return V_4 ;
}
static int F_79 ( struct V_27 * V_28 )
{
F_16 ( V_28 , 3 , L_69 ) ;
if ( F_80 ( V_28 , 0 ) )
return - V_156 ;
F_68 ( V_28 ) ;
F_71 ( V_28 ) ;
F_72 ( V_28 ) ;
F_73 ( V_28 ) ;
F_77 ( V_28 ) ;
F_78 ( V_28 ) ;
return 0 ;
}
static int F_81 ( struct V_27 * V_28 ,
struct V_157 * V_158 , unsigned long V_78 )
{
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) V_78 ;
if ( V_77 -> V_159 . V_160 == 0 )
memcpy ( V_28 -> V_120 -> V_161 ,
V_77 -> V_78 . V_162 . V_163 , V_164 ) ;
else
F_82 ( V_28 -> V_120 -> V_161 ) ;
return 0 ;
}
static int F_83 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
F_62 ( V_134 , 2 , L_70 ) ;
V_75 = F_34 ( V_28 , V_165 ,
V_21 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
* ( ( T_2 * ) & V_77 -> V_78 . V_162 . V_163 [ 6 ] ) =
V_28 -> V_95 . V_163 ;
V_4 = F_35 ( V_28 , V_75 , F_81 ,
NULL ) ;
return V_4 ;
}
static int F_84 ( struct V_27 * V_28 ,
struct V_157 * V_158 , unsigned long V_78 )
{
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) V_78 ;
if ( V_77 -> V_159 . V_160 == 0 )
V_28 -> V_95 . V_163 = * ( ( T_2 * )
& V_77 -> V_78 . V_162 . V_163 [ 6 ] ) ;
else {
V_28 -> V_95 . V_163 = V_166 |
V_167 ;
F_58 ( & V_28 -> V_119 -> V_120 , L_71
L_72 ) ;
}
return 0 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
F_62 ( V_134 , 2 , L_73 ) ;
if ( ! F_47 ( V_28 , V_106 ) ) {
V_28 -> V_95 . V_163 = V_166 |
V_167 ;
return 0 ;
}
V_75 = F_34 ( V_28 , V_165 ,
V_21 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
* ( ( T_2 * ) & V_77 -> V_78 . V_162 . V_163 [ 6 ] ) =
V_28 -> V_95 . V_163 ;
V_4 = F_35 ( V_28 , V_75 , F_84 , NULL ) ;
return V_4 ;
}
static int
F_86 ( struct V_27 * V_28 , struct V_157 * V_158 ,
unsigned long V_78 )
{
struct V_76 * V_77 ;
T_2 V_4 ;
F_62 ( V_134 , 2 , L_74 ) ;
V_77 = (struct V_76 * ) V_78 ;
V_4 = V_77 -> V_159 . V_160 ;
if ( V_4 )
F_38 ( V_28 , 2 , L_75 , V_4 ) ;
switch ( V_77 -> V_78 . V_168 . V_169 ) {
case V_170 :
break;
case V_171 :
switch ( V_4 ) {
case 0 :
case V_172 :
V_28 -> V_95 . V_173 = V_174 ;
F_69 ( & V_28 -> V_119 -> V_120 , L_76
L_77 ) ;
break;
default:
break;
}
break;
case V_175 :
switch ( V_4 ) {
case 0 :
V_28 -> V_95 . V_173 = V_176 ;
F_69 ( & V_28 -> V_119 -> V_120 , L_76
L_78 ) ;
break;
case V_177 :
F_58 ( & V_28 -> V_119 -> V_120 , L_79
L_80
L_81 ) ;
break;
case V_178 :
F_58 ( & V_28 -> V_119 -> V_120 , L_82
L_83
L_84 ) ;
break;
default:
break;
}
break;
default:
F_43 ( 2 , L_85 ,
V_77 -> V_78 . V_168 . V_169 , F_44 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_87 ( struct V_27 * V_28 , enum V_179 V_180 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
F_62 ( V_134 , 2 , L_86 ) ;
V_75 = F_34 ( V_28 , V_181 , 0 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
V_77 -> V_78 . V_168 . V_182 = 16 ;
V_77 -> V_78 . V_168 . V_183 = V_184 ;
V_77 -> V_78 . V_168 . type = V_185 ;
V_77 -> V_78 . V_168 . V_169 = V_180 ;
return F_35 ( V_28 , V_75 , F_86 , NULL ) ;
}
static void F_88 ( T_4 V_186 , char * V_42 )
{
F_89 ( V_186 , V_42 ) ;
}
static void F_90 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
int V_24 ;
F_91 (card->ip_mc_htable, i, addr, hnode)
V_2 -> V_53 = V_54 ;
}
static void F_92 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_68 * V_69 ;
int V_24 ;
int V_4 ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_53 == V_60 ) {
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_63 ) )
V_2 -> V_48 = 1 ;
else {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
}
}
}
}
static void F_93 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_68 * V_69 ;
int V_24 ;
int V_4 ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_53 == V_54 ) {
V_4 = F_19 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_187 ) ) {
F_20 ( & V_2 -> V_55 ) ;
F_21 ( V_2 ) ;
}
}
}
}
static void
F_94 ( struct V_27 * V_28 , struct V_188 * V_189 )
{
struct V_190 * V_191 ;
struct V_29 * V_69 , * V_186 ;
char V_1 [ V_192 ] ;
F_16 ( V_28 , 4 , L_87 ) ;
V_69 = F_23 ( V_20 ) ;
if ( ! V_69 )
return;
for ( V_191 = F_95 ( V_189 -> V_193 ) ; V_191 != NULL ;
V_191 = F_95 ( V_191 -> V_194 ) ) {
F_88 ( V_191 -> V_195 , V_1 ) ;
V_69 -> V_36 . V_45 . V_2 = F_96 ( V_191 -> V_195 ) ;
memcpy ( V_69 -> V_42 , V_1 , sizeof( V_69 -> V_42 ) ) ;
V_186 = F_13 ( V_28 , V_69 ) ;
if ( V_186 ) {
V_186 -> V_53 = V_64 ;
} else {
V_186 = F_23 ( V_20 ) ;
if ( ! V_186 )
continue;
memcpy ( V_186 -> V_42 , V_1 , sizeof( V_69 -> V_42 ) ) ;
V_186 -> V_36 . V_45 . V_2 = F_96 ( V_191 -> V_195 ) ;
V_186 -> V_44 = 1 ;
V_186 -> V_53 = V_60 ;
F_24 ( V_28 -> V_196 ,
& V_186 -> V_55 , F_25 ( V_186 ) ) ;
}
}
F_21 ( V_69 ) ;
}
static void F_97 ( struct V_27 * V_28 )
{
struct V_188 * V_197 ;
T_5 V_198 ;
F_16 ( V_28 , 4 , L_88 ) ;
if ( ! F_47 ( V_28 , V_144 ) )
return;
F_98 (vid, card->active_vlans, VLAN_N_VID) {
struct V_199 * V_200 ;
V_200 = F_99 ( V_28 -> V_120 , F_100 ( V_201 ) ,
V_198 ) ;
if ( V_200 == NULL ||
! ( V_200 -> V_86 & V_202 ) )
continue;
V_197 = F_101 ( V_200 ) ;
if ( ! V_197 )
continue;
F_94 ( V_28 , V_197 ) ;
}
}
static void F_102 ( struct V_27 * V_28 )
{
struct V_188 * V_189 ;
F_16 ( V_28 , 4 , L_89 ) ;
F_103 () ;
V_189 = F_101 ( V_28 -> V_120 ) ;
if ( V_189 == NULL )
goto V_203;
F_94 ( V_28 , V_189 ) ;
F_97 ( V_28 ) ;
V_203:
F_104 () ;
}
static void
F_105 ( struct V_27 * V_28 , struct V_204 * V_205 )
{
struct V_29 * V_186 ;
struct V_206 * V_207 ;
struct V_29 * V_69 ;
char V_1 [ V_192 ] ;
F_16 ( V_28 , 4 , L_90 ) ;
V_69 = F_23 ( V_21 ) ;
if ( ! V_69 )
return;
for ( V_207 = V_205 -> V_193 ; V_207 != NULL ; V_207 = V_207 -> V_208 ) {
F_106 ( & V_207 -> V_209 , V_1 , V_205 -> V_120 , 0 ) ;
memcpy ( V_69 -> V_42 , V_1 , sizeof( V_69 -> V_42 ) ) ;
memcpy ( & V_69 -> V_36 . V_46 . V_2 , & V_207 -> V_209 . V_210 ,
sizeof( struct V_83 ) ) ;
V_69 -> V_44 = 1 ;
V_186 = F_13 ( V_28 , V_69 ) ;
if ( V_186 ) {
V_186 -> V_53 = V_64 ;
continue;
}
V_186 = F_23 ( V_21 ) ;
if ( ! V_186 )
continue;
memcpy ( V_186 -> V_42 , V_1 , V_81 ) ;
memcpy ( & V_186 -> V_36 . V_46 . V_2 , & V_207 -> V_209 . V_210 ,
sizeof( struct V_83 ) ) ;
V_186 -> V_44 = 1 ;
V_186 -> V_53 = V_60 ;
F_24 ( V_28 -> V_196 ,
& V_186 -> V_55 , F_25 ( V_186 ) ) ;
}
F_21 ( V_69 ) ;
}
static void F_107 ( struct V_27 * V_28 )
{
struct V_204 * V_197 ;
T_5 V_198 ;
F_16 ( V_28 , 4 , L_91 ) ;
if ( ! F_47 ( V_28 , V_144 ) )
return;
F_98 (vid, card->active_vlans, VLAN_N_VID) {
struct V_199 * V_200 ;
V_200 = F_99 ( V_28 -> V_120 , F_100 ( V_201 ) ,
V_198 ) ;
if ( V_200 == NULL ||
! ( V_200 -> V_86 & V_202 ) )
continue;
V_197 = F_108 ( V_200 ) ;
if ( ! V_197 )
continue;
F_109 ( & V_197 -> V_211 ) ;
F_105 ( V_28 , V_197 ) ;
F_110 ( & V_197 -> V_211 ) ;
F_111 ( V_197 ) ;
}
}
static void F_112 ( struct V_27 * V_28 )
{
struct V_204 * V_205 ;
F_16 ( V_28 , 4 , L_92 ) ;
if ( ! F_47 ( V_28 , V_106 ) )
return ;
V_205 = F_108 ( V_28 -> V_120 ) ;
if ( ! V_205 )
return;
F_103 () ;
F_109 ( & V_205 -> V_211 ) ;
F_105 ( V_28 , V_205 ) ;
F_107 ( V_28 ) ;
F_110 ( & V_205 -> V_211 ) ;
F_104 () ;
F_111 ( V_205 ) ;
}
static void F_113 ( struct V_27 * V_28 ,
unsigned short V_198 )
{
struct V_188 * V_197 ;
struct V_212 * V_213 ;
struct V_29 * V_2 ;
struct V_199 * V_200 ;
F_16 ( V_28 , 4 , L_93 ) ;
V_200 = F_99 ( V_28 -> V_120 , F_100 ( V_201 ) , V_198 ) ;
if ( ! V_200 )
return;
V_197 = F_114 ( V_200 ) ;
if ( ! V_197 )
return;
V_2 = F_23 ( V_20 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_61 ) ;
for ( V_213 = V_197 -> V_214 ; V_213 ; V_213 = V_213 -> V_215 ) {
V_2 -> V_36 . V_45 . V_2 = F_96 ( V_213 -> V_216 ) ;
V_2 -> V_36 . V_45 . V_90 = F_96 ( V_213 -> V_217 ) ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_2 ) ;
F_115 ( V_197 ) ;
}
static void F_116 ( struct V_27 * V_28 ,
unsigned short V_198 )
{
#ifdef F_46
struct V_204 * V_205 ;
struct V_218 * V_213 ;
struct V_29 * V_2 ;
struct V_199 * V_200 ;
F_16 ( V_28 , 4 , L_94 ) ;
V_200 = F_99 ( V_28 -> V_120 , F_100 ( V_201 ) , V_198 ) ;
if ( ! V_200 )
return;
V_205 = F_108 ( V_200 ) ;
if ( ! V_205 )
return;
V_2 = F_23 ( V_21 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_61 ) ;
F_10 (ifa, &in6_dev->addr_list, if_list) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_213 -> V_2 ,
sizeof( struct V_83 ) ) ;
V_2 -> V_36 . V_46 . V_89 = V_213 -> V_219 ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_61 ) ;
F_21 ( V_2 ) ;
F_111 ( V_205 ) ;
#endif
}
static void F_117 ( struct V_27 * V_28 ,
unsigned short V_198 )
{
F_103 () ;
F_113 ( V_28 , V_198 ) ;
F_116 ( V_28 , V_198 ) ;
F_104 () ;
}
static int F_118 ( struct V_199 * V_120 ,
T_6 V_19 , T_5 V_198 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
F_119 ( V_198 , V_28 -> V_221 ) ;
return 0 ;
}
static int F_120 ( struct V_199 * V_120 ,
T_6 V_19 , T_5 V_198 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
F_38 ( V_28 , 4 , L_95 , V_198 ) ;
if ( F_121 ( V_28 , V_222 ) ) {
F_16 ( V_28 , 3 , L_96 ) ;
return 0 ;
}
F_117 ( V_28 , V_198 ) ;
F_122 ( V_198 , V_28 -> V_221 ) ;
F_123 ( V_28 -> V_120 ) ;
return 0 ;
}
static int F_124 ( struct V_27 * V_28 , struct V_223 * V_224 ,
struct V_225 * V_159 , unsigned short * V_226 )
{
T_2 V_65 ;
struct V_227 * V_228 ;
unsigned char V_229 [ V_192 ] ;
int V_230 = 0 ;
if ( ! ( V_159 -> V_159 . V_231 . V_86 & V_130 ) ) {
V_65 = ( V_159 -> V_159 . V_231 . V_86 & V_131 ) ? V_232 :
V_233 ;
switch ( V_159 -> V_159 . V_231 . V_86 & V_234 ) {
case V_125 :
switch ( V_65 ) {
#ifdef F_46
case V_232 :
F_106 ( (struct V_83 * )
V_224 -> V_78 + 24 ,
V_229 , V_28 -> V_120 , 0 ) ;
break;
#endif
case V_233 :
V_228 = (struct V_227 * ) V_224 -> V_78 ;
F_89 ( V_228 -> V_235 , V_229 ) ;
break;
default:
memcpy ( V_229 , V_28 -> V_120 -> V_236 ,
V_28 -> V_120 -> V_237 ) ;
}
V_28 -> V_238 . V_239 ++ ;
V_224 -> V_240 = V_241 ;
break;
case V_127 :
memcpy ( V_229 , V_28 -> V_120 -> V_236 ,
V_28 -> V_120 -> V_237 ) ;
V_28 -> V_238 . V_239 ++ ;
V_224 -> V_240 = V_242 ;
break;
case V_128 :
case V_133 :
case V_243 :
default:
if ( V_28 -> V_70 . V_71 )
V_224 -> V_240 = V_244 ;
else
V_224 -> V_240 = V_245 ;
memcpy ( V_229 , V_28 -> V_120 -> V_161 ,
V_28 -> V_120 -> V_237 ) ;
}
if ( V_159 -> V_159 . V_231 . V_246 & V_247 )
V_28 -> V_120 -> V_248 -> V_249 ( V_224 , V_28 -> V_120 , V_65 ,
V_229 , & V_159 -> V_159 . V_231 . V_250 [ 2 ] ,
V_28 -> V_120 -> V_237 ) ;
else
V_28 -> V_120 -> V_248 -> V_249 ( V_224 , V_28 -> V_120 , V_65 ,
V_229 , L_97 , V_28 -> V_120 -> V_237 ) ;
}
V_224 -> V_251 = F_125 ( V_224 , V_28 -> V_120 ) ;
if ( V_159 -> V_159 . V_231 . V_246 &
( V_252 | V_253 ) ) {
* V_226 = ( V_159 -> V_159 . V_231 . V_246 & V_252 ) ?
V_159 -> V_159 . V_231 . V_226 : * ( ( T_5 * ) & V_159 -> V_159 . V_231 . V_250 [ 12 ] ) ;
V_230 = 1 ;
}
if ( V_28 -> V_120 -> V_254 & V_255 ) {
if ( ( V_159 -> V_159 . V_231 . V_246 &
( V_256 |
V_257 ) ) ==
( V_256 |
V_257 ) )
V_224 -> V_258 = V_259 ;
else
V_224 -> V_258 = V_260 ;
} else
V_224 -> V_258 = V_260 ;
return V_230 ;
}
static int F_126 ( struct V_27 * V_28 ,
int V_261 , int * V_262 )
{
int V_263 = 0 ;
struct V_223 * V_224 ;
struct V_225 * V_159 ;
T_2 V_264 = 0 ;
int V_230 ;
unsigned int V_23 ;
T_2 V_265 ;
* V_262 = 0 ;
F_127 ( ! V_261 ) ;
while ( V_261 ) {
V_224 = F_128 ( V_28 ,
& V_28 -> V_266 . V_267 -> V_268 [ V_28 -> V_269 . V_270 ] ,
& V_28 -> V_269 . V_271 , & V_28 -> V_269 . V_272 , & V_159 ) ;
if ( ! V_224 ) {
* V_262 = 1 ;
break;
}
V_224 -> V_120 = V_28 -> V_120 ;
switch ( V_159 -> V_159 . V_231 . V_273 ) {
case V_274 :
V_265 = * ( T_2 * ) V_224 -> V_78 ;
if ( ( V_28 -> V_95 . type == V_96 ) &&
( V_265 == V_275 ) ) {
V_224 -> V_251 = F_129 ( V_275 ) ;
V_224 -> V_240 = V_245 ;
V_224 -> V_276 = V_277 ;
V_224 -> V_120 = V_28 -> V_120 ;
V_23 = V_224 -> V_23 ;
V_28 -> V_120 -> V_248 -> V_249 ( V_224 , V_28 -> V_120 , 0 ,
V_28 -> V_120 -> V_161 , L_97 ,
V_28 -> V_120 -> V_237 ) ;
F_130 ( V_224 ) ;
} else {
V_230 = F_124 ( V_28 , V_224 , V_159 ,
& V_264 ) ;
V_23 = V_224 -> V_23 ;
if ( V_230 && ! V_28 -> V_70 . V_71 )
F_131 ( V_224 ,
F_100 ( V_201 ) , V_264 ) ;
F_132 ( & V_28 -> V_278 , V_224 ) ;
}
break;
case V_279 :
V_224 -> V_240 = V_245 ;
V_224 -> V_251 = F_125 ( V_224 , V_224 -> V_120 ) ;
V_23 = V_224 -> V_23 ;
F_130 ( V_224 ) ;
break;
default:
F_133 ( V_224 ) ;
F_16 ( V_28 , 3 , L_98 ) ;
F_134 ( V_280 , 3 , V_159 , V_281 ) ;
continue;
}
V_263 ++ ;
V_261 -- ;
V_28 -> V_238 . V_282 ++ ;
V_28 -> V_238 . V_283 += V_23 ;
}
return V_263 ;
}
static int F_135 ( struct V_199 * V_120 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_198 ;
F_98 (vid, card->active_vlans, VLAN_N_VID) {
struct V_199 * V_200 ;
F_103 () ;
V_200 = F_99 ( V_28 -> V_120 , F_100 ( V_201 ) ,
V_198 ) ;
F_104 () ;
if ( V_200 == V_120 ) {
V_4 = V_284 ;
break;
}
}
if ( V_4 && ! ( F_136 ( V_120 ) -> V_220 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_137 ( struct V_199 * V_120 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
unsigned long V_86 ;
F_138 ( & V_285 . V_286 , V_86 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_120 == V_120 ) {
V_4 = V_287 ;
break;
}
V_4 = F_135 ( V_120 , V_28 ) ;
if ( V_4 )
break;
}
F_139 ( & V_285 . V_286 , V_86 ) ;
return V_4 ;
}
static struct V_27 * F_140 ( struct V_199 * V_120 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_137 ( V_120 ) ;
if ( V_4 == V_287 )
V_28 = V_120 -> V_220 ;
else if ( V_4 == V_284 )
V_28 = F_136 ( V_120 ) -> V_220 ;
if ( V_28 && V_28 -> V_70 . V_288 )
V_28 = NULL ;
if ( V_28 )
F_38 ( V_28 , 4 , L_99 , V_4 ) ;
return V_28 ;
}
static void F_141 ( struct V_27 * V_28 , int V_289 )
{
F_62 ( V_134 , 2 , L_100 ) ;
F_134 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
F_142 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_70 . V_71 &&
( V_28 -> V_95 . V_173 == V_176 ) )
F_87 ( V_28 , V_171 ) ;
if ( V_28 -> V_290 . V_291 == V_292 &&
V_28 -> V_293 . V_291 == V_292 &&
( V_28 -> V_291 == V_294 ) ) {
if ( V_289 )
F_143 ( V_28 -> V_120 ) ;
else {
F_144 () ;
F_145 ( V_28 -> V_120 ) ;
F_146 () ;
}
V_28 -> V_291 = V_295 ;
}
if ( V_28 -> V_291 == V_295 ) {
F_30 ( V_28 , 1 ) ;
F_147 ( V_28 ) ;
V_28 -> V_291 = V_296 ;
}
if ( V_28 -> V_291 == V_296 ) {
F_148 ( V_28 , 0 ) ;
F_149 ( V_28 ) ;
F_150 ( V_28 ) ;
V_28 -> V_291 = V_297 ;
}
if ( V_28 -> V_291 == V_297 ) {
F_151 ( & V_28 -> V_290 ) ;
F_151 ( & V_28 -> V_293 ) ;
}
}
static void
F_152 ( struct V_27 * V_28 )
{
struct V_199 * V_120 = V_28 -> V_120 ;
if ( ( ( V_120 -> V_86 & V_298 ) &&
( V_28 -> V_95 . V_173 == V_176 ) ) ||
( ! ( V_120 -> V_86 & V_298 ) &&
( V_28 -> V_95 . V_173 == V_174 ) ) )
return;
if ( V_28 -> V_95 . V_299 ) {
if ( F_63 ( V_28 , V_300 ) )
F_153 ( V_28 ) ;
} else if ( V_28 -> V_70 . V_71 &&
F_63 ( V_28 , V_301 ) ) {
if ( V_120 -> V_86 & V_298 ) {
F_16 ( V_28 , 3 , L_101 ) ;
F_87 ( V_28 , V_175 ) ;
} else {
F_16 ( V_28 , 3 , L_102 ) ;
F_87 ( V_28 , V_171 ) ;
}
}
}
static void F_123 ( struct V_199 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
F_16 ( V_28 , 3 , L_103 ) ;
if ( F_154 ( V_28 , V_222 ) &&
( V_28 -> V_291 != V_294 ) )
return;
if ( ! V_28 -> V_70 . V_71 ) {
F_28 ( & V_28 -> V_72 ) ;
F_90 ( V_28 ) ;
F_102 ( V_28 ) ;
#ifdef F_46
F_112 ( V_28 ) ;
#endif
F_93 ( V_28 ) ;
F_92 ( V_28 ) ;
F_26 ( & V_28 -> V_72 ) ;
if ( ! F_63 ( V_28 , V_300 ) )
return;
}
F_152 ( V_28 ) ;
}
static const char * F_155 ( int * V_4 )
{
switch ( * V_4 ) {
case V_302 :
* V_4 = - V_156 ;
return L_104 ;
case V_303 :
* V_4 = - V_143 ;
return L_105 ;
case V_304 :
* V_4 = - V_7 ;
return L_106 ;
case V_305 :
* V_4 = - V_143 ;
return L_107 ;
case V_306 :
* V_4 = - V_47 ;
return L_108 ;
default:
return L_109 ;
}
}
static int F_156 ( struct V_27 * V_28 , int V_307 )
{
int V_69 ;
int V_4 ;
F_16 ( V_28 , 3 , L_110 ) ;
if ( V_28 -> V_95 . V_299 )
return - V_143 ;
if ( ! F_47 ( V_28 , V_140 ) ) {
return - V_143 ;
}
V_4 = F_70 ( V_28 , V_140 ,
V_308 ,
V_307 ) ;
if ( V_4 ) {
V_69 = V_4 ;
F_43 ( 2 , L_111
L_112 , F_44 ( V_28 ) ,
F_155 ( & V_4 ) , V_69 , V_69 ) ;
}
return V_4 ;
}
static T_7 F_157 ( struct V_27 * V_28 ,
struct V_309 * V_310 ,
struct V_311 * type , T_1 V_312 )
{
T_7 V_4 ;
T_1 V_313 ;
V_313 = V_310 -> V_314 == 5 ;
if ( type -> V_315 == V_316 ) {
F_16 ( V_28 , 4 , L_113 ) ;
if ( V_312 ) {
V_4 = V_313 ? sizeof( struct V_317 ) :
sizeof( struct V_318 ) ;
} else {
V_4 = V_313 ? sizeof( struct V_319 ) :
sizeof( struct V_320 ) ;
}
} else if ( type -> V_315 == V_321 ) {
F_16 ( V_28 , 4 , L_114 ) ;
if ( V_312 ) {
V_4 = V_313 ?
sizeof( struct V_322 ) :
sizeof( struct V_323 ) ;
} else {
V_4 = V_313 ?
sizeof( struct V_324 ) :
sizeof( struct V_325 ) ;
}
} else {
F_16 ( V_28 , 4 , L_115 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_158 ( struct V_311 * type , T_2 V_65 )
{
return ( type -> V_315 == V_316 && V_65 == V_20 ) ||
( type -> V_315 == V_321 && V_65 == V_21 ) ;
}
static int F_159 ( struct V_27 * V_28 ,
struct V_157 * V_158 , unsigned long V_78 )
{
struct V_76 * V_77 ;
struct V_309 * V_310 ;
struct V_326 * V_327 ;
int V_24 ;
int V_328 ;
int V_329 ;
int V_330 ;
T_1 V_331 ;
F_16 ( V_28 , 3 , L_116 ) ;
V_327 = (struct V_326 * ) V_158 -> V_332 ;
V_77 = (struct V_76 * ) V_78 ;
F_38 ( V_28 , 4 , L_117 , V_77 -> V_159 . V_333 ) ;
if ( V_77 -> V_159 . V_160 ) {
F_16 ( V_28 , 4 , L_118 ) ;
F_38 ( V_28 , 4 , L_117 , V_77 -> V_159 . V_160 ) ;
return 0 ;
}
if ( V_77 -> V_78 . V_334 . V_159 . V_160 ) {
V_77 -> V_159 . V_160 = V_77 -> V_78 . V_334 . V_159 . V_160 ;
F_16 ( V_28 , 4 , L_119 ) ;
F_38 ( V_28 , 4 , L_117 , V_77 -> V_159 . V_160 ) ;
return 0 ;
}
V_310 = & V_77 -> V_78 . V_334 . V_78 . V_335 ;
F_38 ( V_28 , 4 , L_120 , V_310 -> V_307 ) ;
V_331 = ( V_327 -> V_37 & V_336 ) > 0 ;
V_330 = V_331 ? V_337 : 0 ;
V_329 = 0 ;
for ( V_328 = 0 ; V_328 < V_310 -> V_307 ; ++ V_328 ) {
char * V_338 ;
T_7 V_339 ;
struct V_311 * V_340 ;
V_338 = & V_310 -> V_78 + V_329 ;
V_340 = & ( (struct V_319 * ) V_338 ) -> type ;
if ( ! F_158 ( V_340 , V_77 -> V_159 . V_333 ) ) {
F_16 ( V_28 , 4 , L_121 ) ;
F_38 ( V_28 , 4 , L_117 , V_340 -> V_315 ) ;
break;
}
V_339 = F_157 ( V_28 , V_310 , V_340 ,
V_331 ) ;
F_38 ( V_28 , 5 , L_122 , V_339 ) ;
if ( ! V_339 )
break;
if ( ( V_327 -> V_341 - V_327 -> V_342 ) < V_339 ) {
F_38 ( V_28 , 4 , L_123 , - V_56 ) ;
V_77 -> V_159 . V_160 = V_343 ;
goto V_344;
}
memcpy ( V_327 -> V_345 + V_327 -> V_342 ,
& V_310 -> V_78 + V_329 + V_330 ,
V_339 ) ;
V_329 += V_339 + V_330 ;
V_327 -> V_342 += V_339 ;
++ V_327 -> V_307 ;
}
if ( V_77 -> V_78 . V_334 . V_159 . V_346 <
V_77 -> V_78 . V_334 . V_159 . V_347 )
return 1 ;
F_38 ( V_28 , 4 , L_124 , V_327 -> V_307 ) ;
memcpy ( V_327 -> V_345 , & V_327 -> V_307 , 4 ) ;
if ( V_327 -> V_37 & V_336 )
V_310 -> V_314 |= V_336 ;
memcpy ( V_327 -> V_345 + V_348 , & V_310 -> V_314 , 2 ) ;
F_38 ( V_28 , 4 , L_125 , 0 ) ;
return 0 ;
V_344:
V_24 = 0 ;
memcpy ( V_327 -> V_345 , & V_24 , 4 ) ;
return 0 ;
}
static int F_160 ( struct V_27 * V_28 ,
struct V_74 * V_75 , int V_23 ,
int (* F_161)( struct V_27 * , struct V_157 * ,
unsigned long ) ,
void * V_349 )
{
F_16 ( V_28 , 4 , L_126 ) ;
memcpy ( V_75 -> V_78 , V_350 , V_79 ) ;
memcpy ( F_162 ( V_75 -> V_78 ) ,
& V_28 -> V_351 . V_352 , V_353 ) ;
return F_163 ( V_28 , V_79 + V_23 , V_75 ,
F_161 , V_349 ) ;
}
static int F_164 ( struct V_27 * V_28 ,
enum V_18 V_65 ,
struct V_326 * V_327 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
int V_69 ;
int V_4 ;
F_38 ( V_28 , 3 , L_127 , V_65 ) ;
V_75 = F_66 ( V_28 , V_140 ,
V_354 ,
sizeof( struct V_309 )
- sizeof( char ) ,
V_65 ) ;
if ( ! V_75 )
return - V_56 ;
V_77 = (struct V_76 * ) ( V_75 -> V_78 + V_79 ) ;
V_77 -> V_78 . V_334 . V_78 . V_335 . V_355 = 0x000F ;
V_77 -> V_78 . V_334 . V_78 . V_335 . V_314 = 0 ;
V_77 -> V_78 . V_334 . V_78 . V_335 . V_307 = 0 ;
V_4 = F_160 ( V_28 , V_75 ,
V_356 + V_357 ,
F_159 , ( void * ) V_327 ) ;
if ( V_4 ) {
V_69 = V_4 ;
F_43 ( 2 ,
L_128
L_129 , F_44 ( V_28 ) ,
F_155 ( & V_4 ) , V_69 , V_69 ) ;
}
return V_4 ;
}
static int F_165 ( struct V_27 * V_28 , char T_8 * V_345 )
{
struct V_326 V_327 = { 0 , } ;
int V_4 ;
F_16 ( V_28 , 3 , L_130 ) ;
if ( ! F_47 ( V_28 ,
V_140 ) ) {
F_16 ( V_28 , 3 , L_131 ) ;
V_4 = - V_143 ;
goto V_14;
}
if ( F_166 ( & V_327 , V_345 , 6 ) ) {
V_4 = - V_358 ;
goto V_14;
}
V_327 . V_345 = F_29 ( V_327 . V_341 , V_359 ) ;
if ( ! V_327 . V_345 ) {
V_4 = - V_56 ;
goto V_14;
}
V_327 . V_342 = V_360 ;
V_4 = F_164 ( V_28 , V_20 , & V_327 ) ;
if ( V_4 ) {
if ( F_167 ( V_345 , V_327 . V_345 , 4 ) )
V_4 = - V_358 ;
goto V_361;
}
#ifdef F_46
if ( V_327 . V_37 & V_362 ) {
F_164 ( V_28 , V_21 , & V_327 ) ;
}
#endif
if ( F_167 ( V_345 , V_327 . V_345 , V_327 . V_341 ) ) {
F_16 ( V_28 , 4 , L_132 ) ;
V_4 = - V_358 ;
goto V_361;
}
F_16 ( V_28 , 4 , L_133 ) ;
V_361:
F_21 ( V_327 . V_345 ) ;
V_14:
return V_4 ;
}
static int F_168 ( struct V_27 * V_28 ,
struct V_363 * V_108 )
{
struct V_74 * V_75 ;
char V_1 [ 16 ] ;
int V_69 ;
int V_4 ;
F_16 ( V_28 , 3 , L_134 ) ;
if ( V_28 -> V_95 . V_299 )
return - V_143 ;
if ( ! F_47 ( V_28 , V_140 ) ) {
return - V_143 ;
}
V_75 = F_66 ( V_28 , V_140 ,
V_364 ,
sizeof( struct V_363 ) ,
V_20 ) ;
if ( ! V_75 )
return - V_56 ;
V_4 = F_67 ( V_28 , V_75 ,
sizeof( struct V_363 ) ,
( unsigned long ) V_108 ,
V_139 , NULL ) ;
if ( V_4 ) {
V_69 = V_4 ;
F_2 ( ( T_3 * ) V_108 -> V_112 , V_1 ) ;
F_43 ( 2 , L_135
L_136 , V_1 , F_44 ( V_28 ) ,
F_155 ( & V_4 ) , V_69 , V_69 ) ;
}
return V_4 ;
}
static int F_169 ( struct V_27 * V_28 ,
struct V_363 * V_108 )
{
struct V_74 * V_75 ;
char V_1 [ 16 ] = { 0 , } ;
int V_69 ;
int V_4 ;
F_16 ( V_28 , 3 , L_137 ) ;
if ( V_28 -> V_95 . V_299 )
return - V_143 ;
if ( ! F_47 ( V_28 , V_140 ) ) {
return - V_143 ;
}
memcpy ( V_1 , V_108 , 12 ) ;
V_75 = F_66 ( V_28 , V_140 ,
V_365 ,
12 ,
V_20 ) ;
if ( ! V_75 )
return - V_56 ;
V_4 = F_67 ( V_28 , V_75 ,
12 , ( unsigned long ) V_1 ,
V_139 , NULL ) ;
if ( V_4 ) {
V_69 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_108 -> V_112 , V_1 ) ;
F_43 ( 2 , L_138
L_139 , V_1 , F_44 ( V_28 ) ,
F_155 ( & V_4 ) , V_69 , V_69 ) ;
}
return V_4 ;
}
static int F_170 ( struct V_27 * V_28 )
{
int V_4 ;
int V_69 ;
F_16 ( V_28 , 3 , L_140 ) ;
if ( V_28 -> V_95 . V_299 || ( V_28 -> V_95 . type == V_96 ) )
return - V_143 ;
if ( ! F_47 ( V_28 , V_140 ) ) {
return - V_143 ;
}
V_4 = F_70 ( V_28 , V_140 ,
V_366 , 0 ) ;
if ( V_4 ) {
V_69 = V_4 ;
F_43 ( 2 , L_141
L_129 , F_44 ( V_28 ) ,
F_155 ( & V_4 ) , V_69 , V_69 ) ;
}
return V_4 ;
}
static int F_171 ( struct V_199 * V_120 , struct V_367 * V_368 , int V_77 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
struct V_363 V_369 ;
int V_4 = 0 ;
switch ( V_77 ) {
case V_370 :
if ( ! F_172 ( V_371 ) ) {
V_4 = - V_372 ;
break;
}
V_4 = F_156 ( V_28 , V_368 -> V_373 . V_374 ) ;
break;
case V_375 :
if ( ! F_172 ( V_371 ) ) {
V_4 = - V_372 ;
break;
}
V_4 = F_165 ( V_28 , V_368 -> V_373 . V_376 ) ;
break;
case V_377 :
if ( ! F_172 ( V_371 ) ) {
V_4 = - V_372 ;
break;
}
if ( F_166 ( & V_369 , V_368 -> V_373 . V_376 ,
sizeof( struct V_363 ) ) )
V_4 = - V_358 ;
else
V_4 = F_168 ( V_28 , & V_369 ) ;
break;
case V_378 :
if ( ! F_172 ( V_371 ) ) {
V_4 = - V_372 ;
break;
}
if ( F_166 ( & V_369 , V_368 -> V_373 . V_376 ,
sizeof( struct V_363 ) ) )
V_4 = - V_358 ;
else
V_4 = F_169 ( V_28 , & V_369 ) ;
break;
case V_379 :
if ( ! F_172 ( V_371 ) ) {
V_4 = - V_372 ;
break;
}
V_4 = F_170 ( V_28 ) ;
break;
default:
V_4 = - V_143 ;
}
return V_4 ;
}
static int F_173 ( struct V_27 * V_28 , struct V_223 * V_224 )
{
int V_123 = V_380 ;
struct V_381 * V_382 = NULL ;
struct V_383 * V_384 ;
F_103 () ;
V_384 = F_174 ( V_224 ) ;
if ( V_384 )
V_382 = F_175 ( V_384 , V_224 ) ;
if ( V_382 ) {
V_123 = V_382 -> type ;
F_104 () ;
F_176 ( V_382 ) ;
if ( ( V_123 == V_126 ) ||
( V_123 == V_124 ) ||
( V_123 == V_132 ) )
return V_123 ;
else
return V_380 ;
}
F_104 () ;
if ( F_177 ( V_224 -> V_251 ) == V_232 )
return ( F_178 ( V_224 ) [ 24 ] == 0xff ) ?
V_124 : 0 ;
else if ( F_177 ( V_224 -> V_251 ) == V_233 )
return ( ( F_178 ( V_224 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_124 : 0 ;
if ( ! memcmp ( V_224 -> V_78 , V_224 -> V_120 -> V_236 , 6 ) )
return V_126 ;
else {
T_5 V_385 ;
V_385 = * ( ( T_5 * ) V_224 -> V_78 ) ;
switch ( V_28 -> V_95 . V_386 ) {
case V_387 :
case V_388 :
if ( ( V_385 == V_389 ) ||
( V_385 == V_390 ) )
return V_124 ;
break;
default:
if ( ( V_385 == V_391 ) ||
( V_385 == V_392 ) )
return V_124 ;
}
}
return V_123 ;
}
static void F_179 ( struct V_27 * V_28 ,
struct V_225 * V_159 , struct V_223 * V_224 )
{
char V_235 [ 16 ] ;
struct V_393 * V_394 ;
memset ( V_159 , 0 , sizeof( struct V_225 ) ) ;
V_159 -> V_159 . V_231 . V_273 = V_274 ;
V_159 -> V_159 . V_231 . V_246 = 0 ;
V_159 -> V_159 . V_231 . V_395 = V_224 -> V_23 - V_396 ;
V_159 -> V_159 . V_231 . V_86 = V_131 | V_128 ;
V_394 = (struct V_393 * ) ( V_224 -> V_78 + V_396 ) ;
memset ( V_235 , 0 , sizeof( V_235 ) ) ;
V_235 [ 0 ] = 0xfe ;
V_235 [ 1 ] = 0x80 ;
memcpy ( & V_235 [ 8 ] , V_394 -> V_397 , 8 ) ;
memcpy ( V_159 -> V_159 . V_231 . V_250 , V_235 , 16 ) ;
}
static void F_180 ( struct V_27 * V_28 , struct V_225 * V_159 ,
struct V_223 * V_224 , int V_398 , int V_123 )
{
struct V_383 * V_384 ;
memset ( V_159 , 0 , sizeof( struct V_225 ) ) ;
V_159 -> V_159 . V_231 . V_273 = V_274 ;
V_159 -> V_159 . V_231 . V_246 = 0 ;
if ( F_181 ( V_224 ) ) {
if ( ( V_398 == 4 ) || ( V_28 -> V_95 . type == V_96 ) )
V_159 -> V_159 . V_231 . V_246 = V_252 ;
else
V_159 -> V_159 . V_231 . V_246 = V_253 ;
V_159 -> V_159 . V_231 . V_226 = F_182 ( V_224 ) ;
}
V_159 -> V_159 . V_231 . V_395 = V_224 -> V_23 - sizeof( struct V_225 ) ;
F_103 () ;
V_384 = F_174 ( V_224 ) ;
if ( V_398 == 4 ) {
struct V_399 * V_400 = (struct V_399 * ) V_384 ;
T_4 * V_401 = & V_228 ( V_224 ) -> V_235 ;
if ( V_400 && V_400 -> V_402 )
V_401 = & V_400 -> V_402 ;
V_159 -> V_159 . V_231 . V_86 = F_59 ( V_123 ) ;
memset ( V_159 -> V_159 . V_231 . V_250 , 0 , 12 ) ;
* ( ( T_4 * ) ( & V_159 -> V_159 . V_231 . V_250 [ 12 ] ) ) = * V_401 ;
} else if ( V_398 == 6 ) {
struct V_403 * V_400 = (struct V_403 * ) V_384 ;
struct V_83 * V_401 = & F_183 ( V_224 ) -> V_235 ;
if ( V_400 && ! F_184 ( & V_400 -> V_404 ) )
V_401 = & V_400 -> V_404 ;
V_159 -> V_159 . V_231 . V_86 = F_60 ( V_123 ) ;
if ( V_28 -> V_95 . type == V_96 )
V_159 -> V_159 . V_231 . V_86 &= ~ V_130 ;
memcpy ( V_159 -> V_159 . V_231 . V_250 , V_401 , 16 ) ;
} else {
if ( ! memcmp ( V_224 -> V_78 + sizeof( struct V_225 ) ,
V_224 -> V_120 -> V_236 , 6 ) ) {
V_159 -> V_159 . V_231 . V_86 = V_127 |
V_130 ;
} else {
V_159 -> V_159 . V_231 . V_86 = ( V_123 == V_124 ) ?
V_125 | V_130 :
V_128 | V_130 ;
}
}
F_104 () ;
}
static void F_185 ( struct V_27 * V_28 , struct V_225 * V_159 ,
struct V_223 * V_224 )
{
struct V_227 * V_405 = V_228 ( V_224 ) ;
if ( V_405 -> V_251 == V_406 )
V_159 -> V_159 . V_231 . V_246 |= V_407 ;
V_159 -> V_159 . V_231 . V_246 |= V_257 |
V_256 ;
V_405 -> V_408 = 0 ;
if ( V_28 -> V_70 . V_409 )
V_28 -> V_410 . V_411 ++ ;
}
static void F_186 ( struct V_27 * V_28 ,
struct V_225 * V_412 , struct V_223 * V_224 )
{
struct V_413 * V_159 = (struct V_413 * ) V_412 ;
struct V_414 * V_415 = F_187 ( V_224 ) ;
struct V_227 * V_405 = V_228 ( V_224 ) ;
struct V_416 * V_417 = F_183 ( V_224 ) ;
V_159 -> V_159 . V_159 . V_231 . V_273 = V_418 ;
V_159 -> V_159 . V_159 . V_231 . V_395 = V_224 -> V_23 - sizeof( struct V_413 ) ;
V_159 -> V_419 . V_420 = ( T_2 ) sizeof( struct V_421 ) ;
V_159 -> V_419 . V_422 = 1 ;
V_159 -> V_419 . V_423 = 1 ;
V_159 -> V_419 . V_424 = 1 ;
V_159 -> V_419 . V_425 = 28 ;
V_159 -> V_419 . V_426 = F_188 ( V_224 ) -> V_427 ;
V_159 -> V_419 . V_428 = ( T_2 ) ( F_189 ( V_224 ) + F_190 ( V_224 ) ) ;
V_159 -> V_419 . V_429 = ( T_2 ) ( V_224 -> V_23 - V_159 -> V_419 . V_428 -
sizeof( struct V_413 ) ) ;
V_415 -> V_408 = 0 ;
if ( F_177 ( V_224 -> V_251 ) == V_232 ) {
V_417 -> V_429 = 0 ;
V_415 -> V_408 = ~ F_191 ( & V_417 -> V_430 , & V_417 -> V_235 ,
0 , V_431 , 0 ) ;
} else {
V_415 -> V_408 = ~ F_192 ( V_405 -> V_430 , V_405 -> V_235 ,
0 , V_431 , 0 ) ;
V_405 -> V_432 = 0 ;
V_405 -> V_408 = 0 ;
}
}
static int F_193 ( struct V_27 * V_28 ,
struct V_223 * V_224 , int V_433 )
{
T_9 V_434 = ( T_9 ) F_187 ( V_224 ) + F_190 ( V_224 ) ;
int V_435 = F_194 (
V_434 ,
( T_9 ) V_224 -> V_78 + F_195 ( V_224 ) ) +
F_196 ( V_224 ) ;
if ( ( V_435 + V_433 ) > F_197 ( V_28 ) ) {
F_43 ( 2 ,
L_142 ,
V_435 + V_433 , V_224 -> V_23 ) ;
return 0 ;
}
return V_435 ;
}
static T_10 F_198 ( struct V_223 * V_224 ,
struct V_199 * V_120 )
{
int V_4 ;
T_6 * V_436 ;
struct V_225 * V_159 = NULL ;
int V_437 = 0 ;
int V_435 ;
struct V_27 * V_28 = V_120 -> V_220 ;
struct V_223 * V_438 = NULL ;
int V_398 = F_199 ( V_224 ) ;
int V_123 = F_173 ( V_28 , V_224 ) ;
struct V_439 * V_440 =
V_28 -> V_266 . V_441 [ V_28 -> V_266 . V_442
|| ( V_123 && V_28 -> V_95 . V_443 ) ?
F_200 ( V_28 , V_224 , V_398 , V_123 ) :
V_28 -> V_266 . V_444 ] ;
int V_445 = V_224 -> V_23 ;
unsigned int V_446 = 0 ;
bool V_447 ;
int V_448 = - 1 ;
unsigned int V_449 ;
if ( ( ( V_28 -> V_95 . type == V_96 ) &&
( ( ( V_28 -> V_70 . V_450 != V_451 ) && ! V_398 ) ||
( ( V_28 -> V_70 . V_450 == V_451 ) &&
( F_177 ( V_224 -> V_251 ) != V_275 ) ) ) ) ||
V_28 -> V_70 . V_71 )
goto V_452;
if ( ( V_28 -> V_291 != V_294 ) || ! V_28 -> V_453 ) {
V_28 -> V_238 . V_454 ++ ;
goto V_452;
}
if ( ( V_123 == V_126 ) &&
( V_28 -> V_95 . V_149 == 0 ) )
goto V_452;
if ( V_28 -> V_70 . V_409 ) {
V_28 -> V_410 . V_455 ++ ;
V_28 -> V_410 . V_456 = F_201 () ;
}
V_447 = F_202 ( V_224 ) &&
( F_188 ( V_224 ) -> V_457 & V_458 ) ;
if ( V_28 -> V_95 . type == V_96 ) {
V_438 = V_224 ;
V_448 = V_396 ;
V_446 = sizeof( * V_159 ) ;
V_159 = F_203 ( V_459 , V_66 ) ;
if ( ! V_159 )
goto V_452;
V_437 ++ ;
} else {
V_438 = F_204 ( V_224 , sizeof( struct V_413 )
+ V_460 ) ;
if ( ! V_438 )
goto V_452;
if ( V_398 == 4 ) {
F_205 ( V_438 , V_396 ) ;
}
if ( V_398 != 4 && F_181 ( V_438 ) ) {
F_206 ( V_438 , V_460 ) ;
F_207 ( V_438 , V_438 -> V_78 + 4 , 4 ) ;
F_208 ( V_438 , 4 ,
V_438 -> V_78 + 8 , 4 ) ;
F_208 ( V_438 , 8 ,
V_438 -> V_78 + 12 , 4 ) ;
V_436 = ( T_6 * ) ( V_438 -> V_78 + 12 ) ;
* V_436 = F_129 ( V_201 ) ;
* ( V_436 + 1 ) = F_129 ( F_182 ( V_438 ) ) ;
}
}
F_209 ( V_120 ) ;
if ( ( V_28 -> V_95 . type != V_96 ) &&
( ( V_447 && ! F_193 ( V_28 , V_438 , 1 ) ) ||
( ! V_447 && ! F_210 ( V_28 , V_438 , 0 , 0 ) ) ) ) {
int V_461 = F_211 ( V_438 ) ;
if ( V_28 -> V_70 . V_409 ) {
if ( V_461 )
V_28 -> V_410 . V_462 ++ ;
else
V_28 -> V_410 . V_463 ++ ;
}
if ( V_461 )
goto V_452;
}
V_449 = F_188 ( V_438 ) -> V_449 ;
if ( V_447 ) {
V_159 = F_206 ( V_438 , sizeof( struct V_413 ) ) ;
memset ( V_159 , 0 , sizeof( struct V_413 ) ) ;
F_180 ( V_28 , V_159 , V_438 , V_398 , V_123 ) ;
F_186 ( V_28 , V_159 , V_438 ) ;
V_437 ++ ;
} else {
if ( V_448 < 0 ) {
V_159 = F_206 ( V_438 , sizeof( struct V_225 ) ) ;
F_180 ( V_28 , V_159 , V_438 , V_398 ,
V_123 ) ;
} else {
if ( F_177 ( V_438 -> V_251 ) == V_275 )
F_179 ( V_28 , V_159 , V_438 ) ;
else {
F_180 ( V_28 , V_159 , V_438 , V_398 ,
V_123 ) ;
V_159 -> V_159 . V_231 . V_395 = V_438 -> V_23 - V_448 ;
}
}
if ( V_224 -> V_258 == V_464 )
F_185 ( V_28 , V_159 , V_438 ) ;
}
V_435 = V_447 ?
F_193 ( V_28 , V_438 , V_437 ) :
F_210 ( V_28 , V_438 , V_437 ,
( V_448 > 0 ) ? V_448 : 0 ) ;
if ( ! V_435 ) {
if ( V_448 >= 0 )
F_212 ( V_459 , V_159 ) ;
goto V_452;
}
V_435 += V_437 ;
if ( V_28 -> V_95 . type != V_96 ) {
int V_23 ;
if ( V_447 ) {
V_446 = sizeof( struct V_413 ) +
F_189 ( V_438 ) + F_190 ( V_438 ) ;
V_23 = V_446 ;
} else {
V_23 = sizeof( struct V_465 ) ;
}
if ( F_213 ( V_438 , & V_159 , V_23 ) )
goto V_452;
V_4 = F_214 ( V_28 , V_440 , V_438 , V_159 , V_446 ,
V_446 , V_435 ) ;
} else
V_4 = F_215 ( V_28 , V_440 , V_438 , V_159 ,
V_448 , V_446 ) ;
if ( ! V_4 ) {
V_28 -> V_238 . V_466 ++ ;
V_28 -> V_238 . V_445 += V_445 ;
if ( V_438 != V_224 )
F_133 ( V_224 ) ;
if ( V_28 -> V_70 . V_409 ) {
if ( V_447 ) {
V_28 -> V_410 . V_467 += V_445 ;
V_28 -> V_410 . V_468 ++ ;
}
if ( V_449 ) {
V_28 -> V_410 . V_469 ++ ;
V_28 -> V_410 . V_470 += V_449 + 1 ;
}
}
V_4 = V_471 ;
} else {
if ( V_448 >= 0 )
F_212 ( V_459 , V_159 ) ;
if ( V_4 == - V_472 ) {
if ( V_438 != V_224 )
F_133 ( V_438 ) ;
return V_473 ;
} else
goto V_452;
}
F_216 ( V_120 ) ;
if ( V_28 -> V_70 . V_409 )
V_28 -> V_410 . V_474 += F_201 () -
V_28 -> V_410 . V_456 ;
return V_4 ;
V_452:
V_28 -> V_238 . V_475 ++ ;
V_28 -> V_238 . V_476 ++ ;
if ( ( V_438 != V_224 ) && V_438 )
F_133 ( V_438 ) ;
F_133 ( V_224 ) ;
F_216 ( V_120 ) ;
return V_471 ;
}
static int F_217 ( struct V_199 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
int V_4 = 0 ;
F_16 ( V_28 , 4 , L_143 ) ;
if ( V_28 -> V_291 == V_294 )
return V_4 ;
if ( V_28 -> V_291 != V_295 )
return - V_477 ;
V_28 -> V_78 . V_291 = V_292 ;
V_28 -> V_291 = V_294 ;
F_218 ( V_120 ) ;
if ( F_219 ( V_28 -> V_78 . V_478 , 0 ) >= 0 ) {
F_220 ( & V_28 -> V_278 ) ;
F_221 ( & V_28 -> V_278 ) ;
} else
V_4 = - V_156 ;
return V_4 ;
}
static int F_222 ( struct V_199 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
F_16 ( V_28 , 5 , L_144 ) ;
if ( F_121 ( V_28 , V_222 ) ) {
F_16 ( V_28 , 3 , L_145 ) ;
return - V_479 ;
}
return F_217 ( V_120 ) ;
}
static int F_143 ( struct V_199 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_220 ;
F_16 ( V_28 , 4 , L_146 ) ;
F_223 ( V_120 ) ;
if ( V_28 -> V_291 == V_294 ) {
V_28 -> V_291 = V_295 ;
F_224 ( & V_28 -> V_278 ) ;
}
return 0 ;
}
static int F_225 ( struct V_381 * V_382 )
{
V_382 -> V_480 = V_481 ;
memcpy ( V_382 -> V_482 , L_97 , 6 ) ;
V_382 -> V_483 = V_382 -> V_484 -> V_485 ;
return 0 ;
}
static int
F_226 ( struct V_199 * V_120 , struct V_486 * V_487 )
{
if ( V_487 -> V_488 -> V_489 == V_490 )
V_487 -> V_491 = F_225 ;
return 0 ;
}
static int F_227 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_95 . type == V_492 ||
V_28 -> V_95 . type == V_493 ) {
if ( ( V_28 -> V_95 . V_386 == V_388 ) ||
( V_28 -> V_95 . V_386 == V_387 ) ) {
F_228 ( L_147 ) ;
return - V_477 ;
} else {
V_28 -> V_120 = F_229 ( 0 ) ;
if ( ! V_28 -> V_120 )
return - V_477 ;
V_28 -> V_120 -> V_494 = & V_495 ;
F_85 ( V_28 ) ;
if ( ! ( V_28 -> V_95 . V_163 & V_167 ) )
V_28 -> V_120 -> V_496 = V_28 -> V_95 . V_163 &
0xffff ;
if ( ! V_28 -> V_95 . V_299 ) {
V_28 -> V_120 -> V_497 = V_498 |
V_255 | V_499 |
V_500 ;
V_28 -> V_120 -> V_501 = V_498 |
V_255 | V_499 |
V_500 ;
}
}
} else if ( V_28 -> V_95 . type == V_96 ) {
V_28 -> V_120 = F_230 ( 0 , L_148 , V_502 ,
V_503 ) ;
if ( ! V_28 -> V_120 )
return - V_477 ;
V_28 -> V_120 -> V_86 |= V_504 ;
V_28 -> V_120 -> V_494 = & V_505 ;
V_4 = F_83 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_70 . V_506 [ 0 ] )
memcpy ( V_28 -> V_120 -> V_507 , V_28 -> V_70 . V_506 , 9 ) ;
} else
return - V_477 ;
V_28 -> V_120 -> V_220 = V_28 ;
V_28 -> V_120 -> V_508 = V_509 ;
V_28 -> V_120 -> V_510 = V_28 -> V_95 . V_511 ;
V_28 -> V_120 -> V_512 = 64 ;
V_28 -> V_120 -> V_513 = V_514 ;
V_28 -> V_120 -> V_515 = & V_516 ;
V_28 -> V_120 -> V_254 |= V_517 |
V_518 |
V_519 ;
F_231 ( V_28 -> V_120 ) ;
V_28 -> V_120 -> V_520 = ( F_197 ( V_28 ) - 1 ) *
V_521 ;
F_232 ( V_28 -> V_120 , & V_28 -> V_119 -> V_120 ) ;
F_233 ( V_28 -> V_120 , & V_28 -> V_278 , V_522 , V_523 ) ;
F_234 ( V_28 -> V_120 ) ;
return F_235 ( V_28 -> V_120 ) ;
}
static int F_236 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_237 ( & V_119 -> V_120 ) ;
int V_4 ;
if ( V_119 -> V_120 . type == & V_525 ) {
V_4 = F_238 ( & V_119 -> V_120 ) ;
if ( V_4 )
return V_4 ;
}
F_239 ( V_28 -> V_59 ) ;
F_239 ( V_28 -> V_196 ) ;
V_28 -> V_70 . V_288 = 0 ;
V_28 -> V_95 . V_526 = 0 ;
return 0 ;
}
static void F_240 ( struct V_524 * V_527 )
{
struct V_27 * V_28 = F_237 ( & V_527 -> V_120 ) ;
if ( V_527 -> V_120 . type == & V_525 )
F_241 ( & V_527 -> V_120 ) ;
F_142 ( V_28 , 0 , 1 ) ;
F_242 ( V_28 -> V_528 , F_154 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_527 -> V_291 == V_529 )
F_243 ( V_527 ) ;
if ( V_28 -> V_120 ) {
F_244 ( & V_28 -> V_278 ) ;
F_245 ( V_28 -> V_120 ) ;
V_28 -> V_120 = NULL ;
}
F_30 ( V_28 , 0 ) ;
F_48 ( V_28 ) ;
return;
}
static int F_246 ( struct V_524 * V_119 , int V_289 )
{
struct V_27 * V_28 = F_237 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
enum V_530 V_531 ;
F_247 ( & V_28 -> V_532 ) ;
F_247 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 2 , L_149 ) ;
F_134 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
V_531 = V_28 -> V_291 ;
V_4 = F_248 ( V_28 ) ;
if ( V_4 ) {
F_249 ( V_134 , 2 , L_150 , V_4 ) ;
V_4 = - V_477 ;
goto V_534;
}
if ( ! V_28 -> V_120 && F_227 ( V_28 ) ) {
V_4 = - V_477 ;
goto V_534;
}
if ( F_250 ( V_28 , V_535 ) ) {
if ( V_28 -> V_95 . V_526 &&
F_251 ( V_28 , V_536 ) )
V_28 -> V_95 . V_526 = 0 ;
} else
V_28 -> V_95 . V_526 = 0 ;
V_28 -> V_291 = V_296 ;
memset ( & V_28 -> V_269 , 0 , sizeof( struct V_537 ) ) ;
F_252 ( V_28 ) ;
F_62 ( V_134 , 2 , L_151 ) ;
V_4 = F_61 ( V_28 ) ;
if ( V_4 )
F_249 ( V_134 , 2 , L_150 , V_4 ) ;
if ( ! V_28 -> V_70 . V_71 ) {
V_4 = F_79 ( V_28 ) ;
if ( V_4 ) {
F_249 ( V_134 , 2 , L_152 , V_4 ) ;
goto V_534;
}
V_4 = F_42 ( V_28 ) ;
if ( V_4 )
F_249 ( V_134 , 2 , L_153 , V_4 ) ;
V_4 = F_45 ( V_28 ) ;
if ( V_4 )
F_249 ( V_134 , 2 , L_154 , V_4 ) ;
}
F_223 ( V_28 -> V_120 ) ;
V_4 = F_253 ( V_28 ) ;
if ( V_4 ) {
F_249 ( V_134 , 2 , L_155 , V_4 ) ;
V_4 = - V_477 ;
goto V_534;
}
V_28 -> V_291 = V_295 ;
F_142 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_453 )
F_254 ( V_28 -> V_120 ) ;
else
F_234 ( V_28 -> V_120 ) ;
if ( V_531 == V_538 ) {
F_144 () ;
if ( V_289 )
F_217 ( V_28 -> V_120 ) ;
else
F_255 ( V_28 -> V_120 ) ;
F_123 ( V_28 -> V_120 ) ;
F_256 ( V_28 -> V_120 ) ;
F_146 () ;
}
F_257 ( V_28 ) ;
F_258 ( & V_119 -> V_120 . V_539 , V_540 ) ;
F_259 ( & V_28 -> V_533 ) ;
F_259 ( & V_28 -> V_532 ) ;
return 0 ;
V_534:
F_141 ( V_28 , 0 ) ;
F_260 ( F_261 ( V_28 ) ) ;
F_260 ( F_262 ( V_28 ) ) ;
F_260 ( F_263 ( V_28 ) ) ;
F_264 ( F_261 ( V_28 ) ) ;
if ( V_531 == V_538 )
V_28 -> V_291 = V_538 ;
else
V_28 -> V_291 = V_297 ;
F_259 ( & V_28 -> V_533 ) ;
F_259 ( & V_28 -> V_532 ) ;
return V_4 ;
}
static int F_265 ( struct V_524 * V_119 )
{
return F_246 ( V_119 , 0 ) ;
}
static int F_266 ( struct V_524 * V_527 ,
int V_289 )
{
struct V_27 * V_28 = F_237 ( & V_527 -> V_120 ) ;
int V_4 = 0 , V_541 = 0 , V_542 = 0 ;
enum V_530 V_531 ;
F_247 ( & V_28 -> V_532 ) ;
F_247 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 3 , L_156 ) ;
F_134 ( V_134 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_120 && F_267 ( V_28 -> V_120 ) )
F_234 ( V_28 -> V_120 ) ;
V_531 = V_28 -> V_291 ;
if ( ( ! V_289 && V_28 -> V_95 . V_526 ) || V_28 -> V_95 . V_526 == 2 ) {
F_251 ( V_28 , V_543 ) ;
V_28 -> V_95 . V_526 = 1 ;
}
F_141 ( V_28 , V_289 ) ;
if ( ( V_28 -> V_70 . V_450 == V_451 ) && V_28 -> V_120 ) {
F_144 () ;
F_268 ( V_544 , V_28 -> V_120 ) ;
F_146 () ;
}
V_4 = F_260 ( F_261 ( V_28 ) ) ;
V_541 = F_260 ( F_262 ( V_28 ) ) ;
V_542 = F_260 ( F_263 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_541 ) ? V_541 : V_542 ;
if ( V_4 )
F_249 ( V_134 , 2 , L_157 , V_4 ) ;
F_264 ( F_261 ( V_28 ) ) ;
if ( V_531 == V_294 )
V_28 -> V_291 = V_538 ;
F_258 ( & V_527 -> V_120 . V_539 , V_540 ) ;
F_259 ( & V_28 -> V_533 ) ;
F_259 ( & V_28 -> V_532 ) ;
return 0 ;
}
static int F_243 ( struct V_524 * V_527 )
{
return F_266 ( V_527 , 0 ) ;
}
static int F_269 ( void * V_545 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_545 ;
F_16 ( V_28 , 2 , L_158 ) ;
F_17 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_270 ( V_28 , V_222 ) )
return 0 ;
F_16 ( V_28 , 2 , L_159 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_160 ) ;
F_271 ( V_28 ) ;
F_266 ( V_28 -> V_119 , 1 ) ;
V_4 = F_246 ( V_28 -> V_119 , 1 ) ;
if ( ! V_4 )
F_69 ( & V_28 -> V_119 -> V_120 ,
L_161 ) ;
else {
F_272 ( V_28 ) ;
F_58 ( & V_28 -> V_119 -> V_120 , L_162
L_163 ) ;
}
F_273 ( V_28 ) ;
F_274 ( V_28 , V_222 ) ;
F_275 ( V_28 , V_222 ) ;
return 0 ;
}
static int F_276 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_237 ( & V_119 -> V_120 ) ;
if ( V_28 -> V_120 )
F_277 ( V_28 -> V_120 ) ;
F_142 ( V_28 , 0 , 1 ) ;
F_242 ( V_28 -> V_528 , F_154 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_119 -> V_291 == V_546 )
return 0 ;
if ( V_28 -> V_291 == V_294 ) {
if ( V_28 -> V_95 . V_526 )
F_251 ( V_28 , V_543 ) ;
F_266 ( V_28 -> V_119 , 1 ) ;
} else
F_266 ( V_28 -> V_119 , 0 ) ;
return 0 ;
}
static int F_278 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_237 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
if ( V_119 -> V_291 == V_546 )
goto V_14;
if ( V_28 -> V_291 == V_538 ) {
V_4 = F_246 ( V_28 -> V_119 , 1 ) ;
if ( V_4 ) {
F_144 () ;
F_145 ( V_28 -> V_120 ) ;
F_146 () ;
}
} else
V_4 = F_246 ( V_28 -> V_119 , 0 ) ;
V_14:
F_142 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_120 )
F_279 ( V_28 -> V_120 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_162
L_163 ) ;
return V_4 ;
}
static int F_280 ( struct V_27 * V_28 ,
struct V_76 * V_77 )
{
return 1 ;
}
static int F_281 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_212 * V_213 = (struct V_212 * ) V_545 ;
struct V_199 * V_120 = (struct V_199 * ) V_213 -> V_550 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_282 ( V_120 ) != & V_551 )
return V_552 ;
V_28 = F_140 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_164 ) ;
V_2 = F_23 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_45 . V_2 = F_96 ( V_213 -> V_216 ) ;
V_2 -> V_36 . V_45 . V_90 = F_96 ( V_213 -> V_217 ) ;
V_2 -> type = V_49 ;
} else
return V_552 ;
switch ( V_549 ) {
case V_553 :
F_28 ( & V_28 -> V_61 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_61 ) ;
break;
case V_554 :
F_28 ( & V_28 -> V_61 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_61 ) ;
break;
}
F_21 ( V_2 ) ;
return V_552 ;
}
static int F_283 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_218 * V_213 = (struct V_218 * ) V_545 ;
struct V_199 * V_120 = (struct V_199 * ) V_213 -> V_555 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_140 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_165 ) ;
if ( ! F_47 ( V_28 , V_106 ) )
return V_552 ;
V_2 = F_23 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_213 -> V_2 , sizeof( struct V_83 ) ) ;
V_2 -> V_36 . V_46 . V_89 = V_213 -> V_219 ;
V_2 -> type = V_49 ;
} else
return V_552 ;
switch ( V_549 ) {
case V_553 :
F_28 ( & V_28 -> V_61 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_61 ) ;
break;
case V_554 :
F_28 ( & V_28 -> V_61 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_61 ) ;
break;
}
F_21 ( V_2 ) ;
return V_552 ;
}
static int F_284 ( void )
{
int V_4 ;
F_62 ( V_134 , 5 , L_166 ) ;
V_4 = F_285 ( & V_556 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_46
V_4 = F_286 ( & V_557 ) ;
if ( V_4 ) {
F_287 ( & V_556 ) ;
return V_4 ;
}
#else
F_288 ( L_167 ) ;
#endif
return 0 ;
}
static void F_289 ( void )
{
F_62 ( V_134 , 5 , L_168 ) ;
F_290 ( F_287 ( & V_556 ) ) ;
#ifdef F_46
F_290 ( F_291 ( & V_557 ) ) ;
#endif
}
static int T_11 F_292 ( void )
{
int V_4 = 0 ;
F_228 ( L_169 ) ;
V_4 = F_284 () ;
return V_4 ;
}
static void T_12 F_293 ( void )
{
F_289 () ;
F_228 ( L_170 ) ;
}
