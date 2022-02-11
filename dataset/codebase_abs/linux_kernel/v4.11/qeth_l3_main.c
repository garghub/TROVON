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
if ( V_2 -> type == V_49 && V_2 -> V_48 > 0 )
return V_4 ;
if ( V_2 -> V_50 )
return - V_51 ;
if ( ! F_18 ( V_28 ) ) {
V_2 -> V_52 = V_53 ;
return 0 ;
}
V_4 = F_19 ( V_28 , V_2 ) ;
F_20 ( & V_2 -> V_54 ) ;
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
return - V_55 ;
memcpy ( V_2 , V_43 , sizeof( struct V_29 ) ) ;
V_2 -> V_48 = 1 ;
if ( V_2 -> type == V_49 &&
F_9 ( V_28 , V_2 ) ) {
F_16 ( V_28 , 2 , L_7 ) ;
V_2 -> V_56 |= V_57 ;
}
F_24 ( V_28 -> V_58 , & V_2 -> V_54 ,
F_25 ( V_2 ) ) ;
if ( ! F_18 ( V_28 ) ) {
V_2 -> V_52 = V_59 ;
return 0 ;
}
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_50 = 1 ;
F_26 ( & V_28 -> V_60 ) ;
V_4 = F_27 ( V_28 , V_2 ) ;
F_28 ( & V_28 -> V_60 ) ;
V_2 -> V_50 = 0 ;
} else
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_61 ) ||
( V_4 == V_62 ) ) {
V_2 -> V_52 = V_63 ;
if ( V_2 -> V_48 < 1 ) {
F_15 ( V_28 , V_2 ) ;
F_21 ( V_2 ) ;
}
} else {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
} else {
if ( V_2 -> type == V_49 )
V_2 -> V_48 ++ ;
}
return V_4 ;
}
struct V_29 * F_23 (
enum V_18 V_64 )
{
struct V_29 * V_2 ;
V_2 = F_29 ( sizeof( struct V_29 ) , V_65 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> type = V_49 ;
V_2 -> V_52 = V_63 ;
V_2 -> V_19 = V_64 ;
return V_2 ;
}
static void F_30 ( struct V_27 * V_28 , int V_66 )
{
struct V_29 * V_2 ;
struct V_67 * V_68 ;
int V_24 ;
F_16 ( V_28 , 4 , L_8 ) ;
if ( V_66 && V_28 -> V_69 . V_70 )
return;
F_28 ( & V_28 -> V_60 ) ;
F_31 (card->ip_htable, i, tmp, addr, hnode) {
if ( ! V_66 ) {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
continue;
}
V_2 -> V_52 = V_59 ;
}
F_26 ( & V_28 -> V_60 ) ;
F_28 ( & V_28 -> V_71 ) ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
F_26 ( & V_28 -> V_71 ) ;
}
static void F_32 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_67 * V_68 ;
int V_24 ;
int V_4 ;
F_16 ( V_28 , 4 , L_9 ) ;
F_28 ( & V_28 -> V_60 ) ;
F_31 (card->ip_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_52 == V_53 ) {
F_19 ( V_28 , V_2 ) ;
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
} else if ( V_2 -> V_52 == V_59 ) {
if ( V_2 -> V_19 == V_20 ) {
V_2 -> V_50 = 1 ;
F_26 ( & V_28 -> V_60 ) ;
V_4 = F_27 ( V_28 , V_2 ) ;
F_28 ( & V_28 -> V_60 ) ;
V_2 -> V_50 = 0 ;
} else
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 ) {
V_2 -> V_52 = V_63 ;
if ( V_2 -> V_48 < 1 )
F_15 ( V_28 , V_2 ) ;
} else {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
}
}
F_26 ( & V_28 -> V_60 ) ;
}
static int F_33 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_72 )
{
int V_4 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_16 ( V_28 , 4 , L_10 ) ;
V_74 = F_34 ( V_28 , V_72 , V_2 -> V_19 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
memcpy ( & V_76 -> V_77 . V_79 . V_42 , V_2 -> V_42 , V_80 ) ;
if ( V_2 -> V_19 == V_21 )
memcpy ( V_76 -> V_77 . V_79 . V_81 , & V_2 -> V_36 . V_46 . V_2 ,
sizeof( struct V_82 ) ) ;
else
memcpy ( & V_76 -> V_77 . V_79 . V_83 , & V_2 -> V_36 . V_45 . V_2 , 4 ) ;
V_4 = F_35 ( V_28 , V_74 , NULL , NULL ) ;
return V_4 ;
}
static void F_36 ( T_3 * V_84 , unsigned int V_23 )
{
int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ ) {
V_25 = ( V_23 ) - ( V_24 * 8 ) ;
if ( V_25 >= 8 )
V_84 [ V_24 ] = 0xff ;
else if ( V_25 > 0 )
V_84 [ V_24 ] = ( T_3 ) ( 0xFF00 >> V_25 ) ;
else
V_84 [ V_24 ] = 0 ;
}
}
static int F_37 ( struct V_27 * V_28 ,
struct V_29 * V_2 , int V_72 , unsigned int V_85 )
{
int V_4 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
T_1 V_84 [ 16 ] ;
F_16 ( V_28 , 4 , L_11 ) ;
F_38 ( V_28 , 4 , L_12 , V_85 ) ;
V_74 = F_34 ( V_28 , V_72 , V_2 -> V_19 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
if ( V_2 -> V_19 == V_21 ) {
memcpy ( V_76 -> V_77 . V_86 . V_87 , & V_2 -> V_36 . V_46 . V_2 ,
sizeof( struct V_82 ) ) ;
F_36 ( V_84 , V_2 -> V_36 . V_46 . V_88 ) ;
memcpy ( V_76 -> V_77 . V_86 . V_89 , V_84 ,
sizeof( struct V_82 ) ) ;
V_76 -> V_77 . V_86 . V_85 = V_85 ;
} else {
memcpy ( V_76 -> V_77 . V_90 . V_87 , & V_2 -> V_36 . V_45 . V_2 , 4 ) ;
memcpy ( V_76 -> V_77 . V_90 . V_89 , & V_2 -> V_36 . V_45 . V_89 , 4 ) ;
V_76 -> V_77 . V_90 . V_85 = V_85 ;
}
V_4 = F_35 ( V_28 , V_74 , NULL , NULL ) ;
return V_4 ;
}
static int F_39 ( struct V_27 * V_28 ,
enum V_91 type , enum V_18 V_64 )
{
int V_4 ;
struct V_75 * V_76 ;
struct V_73 * V_74 ;
F_16 ( V_28 , 4 , L_13 ) ;
V_74 = F_34 ( V_28 , V_92 , V_64 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_93 . type = ( type ) ;
V_4 = F_35 ( V_28 , V_74 , NULL , NULL ) ;
return V_4 ;
}
static int F_40 ( struct V_27 * V_28 ,
enum V_91 * type , enum V_18 V_64 )
{
if ( V_28 -> V_94 . type == V_95 ) {
switch ( * type ) {
case V_96 :
case V_97 :
case V_98 :
case V_99 :
return 0 ;
default:
goto V_100;
}
} else {
switch ( * type ) {
case V_96 :
case V_101 :
case V_102 :
return 0 ;
case V_99 :
if ( F_41 ( V_28 , V_64 ,
V_103 ) )
return 0 ;
default:
goto V_100;
}
}
V_100:
* type = V_96 ;
return - V_7 ;
}
int F_42 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_14 ) ;
V_4 = F_40 ( V_28 , & V_28 -> V_69 . V_104 . type ,
V_20 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_39 ( V_28 , V_28 -> V_69 . V_104 . type ,
V_20 ) ;
if ( V_4 ) {
V_28 -> V_69 . V_104 . type = V_96 ;
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
if ( ! F_47 ( V_28 , V_105 ) )
return 0 ;
V_4 = F_40 ( V_28 , & V_28 -> V_69 . V_106 . type ,
V_21 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_39 ( V_28 , V_28 -> V_69 . V_106 . type ,
V_21 ) ;
if ( V_4 ) {
V_28 -> V_69 . V_106 . type = V_96 ;
F_43 ( 2 , L_15
L_16 , V_4 ,
F_44 ( V_28 ) ) ;
}
#endif
return V_4 ;
}
static void F_48 ( struct V_27 * V_28 )
{
struct V_30 * V_31 , * V_68 ;
F_28 ( & V_28 -> V_60 ) ;
F_49 (ipatoe, tmp, &card->ipato.entries, entry) {
F_50 ( & V_31 -> V_107 ) ;
F_21 ( V_31 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
}
int F_51 ( struct V_27 * V_28 ,
struct V_30 * V_108 )
{
struct V_30 * V_31 ;
int V_4 = 0 ;
F_16 ( V_28 , 2 , L_18 ) ;
F_28 ( & V_28 -> V_60 ) ;
F_10 (ipatoe, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_108 -> V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_108 -> V_2 ,
( V_31 -> V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_108 -> V_37 ) ) {
V_4 = - V_109 ;
break;
}
}
if ( ! V_4 )
F_52 ( & V_108 -> V_107 , & V_28 -> V_34 . V_110 ) ;
F_26 ( & V_28 -> V_60 ) ;
return V_4 ;
}
void F_53 ( struct V_27 * V_28 ,
enum V_18 V_19 , T_3 * V_2 , int V_37 )
{
struct V_30 * V_31 , * V_68 ;
F_16 ( V_28 , 2 , L_19 ) ;
F_28 ( & V_28 -> V_60 ) ;
F_49 (ipatoe, tmp, &card->ipato.entries, entry) {
if ( V_31 -> V_19 != V_19 )
continue;
if ( ! memcmp ( V_31 -> V_2 , V_2 ,
( V_19 == V_20 ) ? 4 : 16 ) &&
( V_31 -> V_37 == V_37 ) ) {
F_50 ( & V_31 -> V_107 ) ;
F_21 ( V_31 ) ;
}
}
F_26 ( & V_28 -> V_60 ) ;
}
int F_54 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_111 ;
int V_4 = 0 ;
V_111 = F_23 ( V_19 ) ;
if ( V_111 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_20 ) ;
memcpy ( & V_111 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_111 -> V_36 . V_45 . V_89 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_21 ) ;
memcpy ( & V_111 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_111 -> V_36 . V_46 . V_88 = 0 ;
}
V_111 -> type = V_112 ;
V_111 -> V_56 = V_113 ;
V_111 -> V_114 = V_115 ;
} else
return - V_55 ;
F_28 ( & V_28 -> V_60 ) ;
if ( F_13 ( V_28 , V_111 ) )
V_4 = - V_109 ;
else
F_22 ( V_28 , V_111 ) ;
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_111 ) ;
return V_4 ;
}
void F_55 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_111 ;
V_111 = F_23 ( V_19 ) ;
if ( V_111 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_22 ) ;
memcpy ( & V_111 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_111 -> V_36 . V_45 . V_89 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_23 ) ;
memcpy ( & V_111 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_111 -> V_36 . V_46 . V_88 = 0 ;
}
V_111 -> type = V_112 ;
} else
return;
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_111 ) ;
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_111 ) ;
}
int F_56 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_111 ;
int V_4 = 0 ;
V_111 = F_23 ( V_19 ) ;
if ( V_111 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_24 ) ;
memcpy ( & V_111 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_111 -> V_36 . V_45 . V_89 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_25 ) ;
memcpy ( & V_111 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_111 -> V_36 . V_46 . V_88 = 0 ;
}
V_111 -> type = V_116 ;
V_111 -> V_56 = V_57 ;
V_111 -> V_114 = 0 ;
} else
return - V_55 ;
F_28 ( & V_28 -> V_60 ) ;
if ( F_13 ( V_28 , V_111 ) )
V_4 = - V_109 ;
else
F_22 ( V_28 , V_111 ) ;
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_111 ) ;
return V_4 ;
}
void F_57 ( struct V_27 * V_28 , enum V_18 V_19 ,
const T_3 * V_2 )
{
struct V_29 * V_111 ;
V_111 = F_23 ( V_19 ) ;
if ( V_111 ) {
if ( V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_24 ) ;
memcpy ( & V_111 -> V_36 . V_45 . V_2 , V_2 , 4 ) ;
V_111 -> V_36 . V_45 . V_89 = 0 ;
} else if ( V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_25 ) ;
memcpy ( & V_111 -> V_36 . V_46 . V_2 , V_2 , 16 ) ;
V_111 -> V_36 . V_46 . V_88 = 0 ;
}
V_111 -> type = V_116 ;
} else
return;
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_111 ) ;
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_111 ) ;
}
static int F_27 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
char V_1 [ 50 ] ;
int V_4 = 0 ;
int V_13 = 3 ;
if ( V_2 -> V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_26 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_45 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_27 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
} else {
F_16 ( V_28 , 2 , L_28 ) ;
F_17 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
do {
if ( V_2 -> V_44 )
V_4 = F_33 ( V_28 , V_2 , V_117 ) ;
else
V_4 = F_37 ( V_28 , V_2 , V_118 ,
V_2 -> V_56 ) ;
if ( V_4 )
F_16 ( V_28 , 2 , L_29 ) ;
} while ( ( -- V_13 > 0 ) && V_4 );
if ( V_4 ) {
F_16 ( V_28 , 2 , L_30 ) ;
F_6 ( V_2 -> V_19 , ( T_3 * ) & V_2 -> V_36 , V_1 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_31 , V_1 ) ;
}
return V_4 ;
}
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_2 )
{
int V_4 = 0 ;
if ( V_2 -> V_19 == V_20 ) {
F_16 ( V_28 , 2 , L_32 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_45 . V_2 , sizeof( int ) ) ;
} else if ( V_2 -> V_19 == V_21 ) {
F_16 ( V_28 , 2 , L_33 ) ;
F_17 ( V_28 , 3 , & V_2 -> V_36 . V_46 . V_2 , 8 ) ;
F_17 ( V_28 , 3 , ( ( char * ) & V_2 -> V_36 . V_46 . V_2 ) + 8 , 8 ) ;
} else {
F_16 ( V_28 , 2 , L_34 ) ;
F_17 ( V_28 , 3 , V_2 , sizeof( struct V_29 ) ) ;
}
if ( V_2 -> V_44 )
V_4 = F_33 ( V_28 , V_2 , V_121 ) ;
else
V_4 = F_37 ( V_28 , V_2 , V_122 ,
V_2 -> V_114 ) ;
if ( V_4 )
F_16 ( V_28 , 2 , L_29 ) ;
return V_4 ;
}
static inline T_3 F_59 ( int V_123 )
{
if ( V_123 == V_124 )
return V_125 ;
if ( V_123 == V_126 )
return V_127 ;
return V_128 ;
}
static inline T_3 F_60 ( int V_123 )
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
int V_4 ;
F_62 ( V_134 , 2 , L_35 ) ;
if ( ! F_47 ( V_28 , V_135 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_36 ) ;
F_62 ( V_134 , 2 , L_37 ) ;
return 0 ;
}
V_4 = F_64 ( V_28 ) ;
if ( V_4 ) {
F_43 ( 2 , L_38
L_39 , F_65 ( & V_28 -> V_119 -> V_120 ) , V_4 ) ;
return V_4 ;
}
if ( F_66 ( V_28 , V_136 ) ) {
V_4 = F_67 ( V_28 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_40
L_41 ) ;
}
return V_4 ;
}
static int F_68 ( struct V_27 * V_28 ,
enum V_137 V_138 , T_2 V_139 )
{
int V_4 ;
struct V_73 * V_74 ;
F_16 ( V_28 , 4 , L_42 ) ;
V_74 = F_69 ( V_28 , V_138 , V_139 ,
0 , V_21 ) ;
if ( ! V_74 )
return - V_55 ;
V_4 = F_70 ( V_28 , V_74 , 0 , 0 ,
V_140 , NULL ) ;
return V_4 ;
}
static int F_71 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_43 ) ;
if ( ! F_47 ( V_28 , V_141 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_44 ,
F_44 ( V_28 ) ) ;
return 0 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_45 ,
F_44 ( V_28 ) ) ;
}
return V_4 ;
}
static int F_73 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_46 ) ;
if ( ! F_47 ( V_28 , V_143 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_47 ,
F_44 ( V_28 ) ) ;
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_143 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_48 ,
F_44 ( V_28 ) ) ;
} else
F_63 ( & V_28 -> V_119 -> V_120 ,
L_49 ) ;
return V_4 ;
}
static int F_74 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_50 ) ;
if ( ! F_47 ( V_28 , V_145 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_51 ,
F_44 ( V_28 ) ) ;
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_145 ,
V_142 , 0 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 ,
L_52 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
static int F_75 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_53 ) ;
if ( ! F_47 ( V_28 , V_146 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_54 , F_44 ( V_28 ) ) ;
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_147 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_55 ,
F_44 ( V_28 ) ) ;
} else {
F_63 ( & V_28 -> V_119 -> V_120 , L_56 ) ;
}
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_57 ) ;
if ( ! F_47 ( V_28 , V_148 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_58 ,
F_44 ( V_28 ) ) ;
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_148 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_59 ,
F_44 ( V_28 ) ) ;
} else {
F_63 ( & V_28 -> V_119 -> V_120 , L_60 ) ;
V_28 -> V_120 -> V_85 |= V_149 ;
}
return V_4 ;
}
static int F_77 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_61 ) ;
if ( V_28 -> V_94 . type == V_95 )
goto V_14;
V_4 = F_78 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_79 ( & V_28 -> V_119 -> V_120 ,
L_62 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_72 ( V_28 , V_105 ,
V_142 , 3 ) ;
if ( V_4 ) {
F_79 ( & V_28 -> V_119 -> V_120 ,
L_62 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_68 ( V_28 , V_105 ,
V_142 ) ;
if ( V_4 ) {
F_79 ( & V_28 -> V_119 -> V_120 ,
L_62 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_68 ( V_28 , V_150 ,
V_142 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_63 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_63 ( & V_28 -> V_119 -> V_120 , L_64 ) ;
return 0 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_65 ) ;
if ( ! F_47 ( V_28 , V_105 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_66 , F_44 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_46
V_4 = F_77 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_67 ) ;
V_28 -> V_94 . V_151 = 0 ;
if ( ! F_47 ( V_28 , V_152 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_68 ,
F_44 ( V_28 ) ) ;
V_4 = - V_144 ;
goto V_14;
}
V_4 = F_72 ( V_28 , V_152 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_69
L_70 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_72 ( V_28 , V_152 ,
V_153 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_71 ,
F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_94 . V_151 = V_154 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_72 ) ;
V_4 = F_72 ( V_28 , V_152 ,
V_155 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_73
L_74 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_94 . V_151 = V_156 ;
V_14:
if ( V_28 -> V_94 . V_151 )
V_28 -> V_120 -> V_85 |= V_157 ;
else
V_28 -> V_120 -> V_85 &= ~ V_157 ;
return V_4 ;
}
static int F_82 ( struct V_27 * V_28 )
{
F_16 ( V_28 , 3 , L_75 ) ;
if ( F_83 ( V_28 , 0 ) )
return - V_158 ;
F_71 ( V_28 ) ;
F_73 ( V_28 ) ;
F_74 ( V_28 ) ;
F_75 ( V_28 ) ;
F_76 ( V_28 ) ;
F_80 ( V_28 ) ;
F_81 ( V_28 ) ;
return 0 ;
}
static int F_84 ( struct V_27 * V_28 ,
struct V_159 * V_160 , unsigned long V_77 )
{
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) V_77 ;
if ( V_76 -> V_161 . V_162 == 0 )
memcpy ( V_28 -> V_120 -> V_163 ,
V_76 -> V_77 . V_164 . V_165 , V_166 ) ;
else
F_85 ( V_28 -> V_120 -> V_163 ) ;
return 0 ;
}
static int F_86 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_76 ) ;
V_74 = F_34 ( V_28 , V_167 ,
V_21 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
* ( ( T_2 * ) & V_76 -> V_77 . V_164 . V_165 [ 6 ] ) =
V_28 -> V_94 . V_165 ;
V_4 = F_35 ( V_28 , V_74 , F_84 ,
NULL ) ;
return V_4 ;
}
static int F_87 ( struct V_27 * V_28 ,
struct V_159 * V_160 , unsigned long V_77 )
{
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) V_77 ;
if ( V_76 -> V_161 . V_162 == 0 )
V_28 -> V_94 . V_165 = * ( ( T_2 * )
& V_76 -> V_77 . V_164 . V_165 [ 6 ] ) ;
else {
V_28 -> V_94 . V_165 = V_168 |
V_169 ;
F_58 ( & V_28 -> V_119 -> V_120 , L_77
L_78 ) ;
}
return 0 ;
}
static int F_88 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_79 ) ;
if ( ! F_47 ( V_28 , V_105 ) ) {
V_28 -> V_94 . V_165 = V_168 |
V_169 ;
return 0 ;
}
V_74 = F_34 ( V_28 , V_167 ,
V_21 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
* ( ( T_2 * ) & V_76 -> V_77 . V_164 . V_165 [ 6 ] ) =
V_28 -> V_94 . V_165 ;
V_4 = F_35 ( V_28 , V_74 , F_87 , NULL ) ;
return V_4 ;
}
static int
F_89 ( struct V_27 * V_28 , struct V_159 * V_160 ,
unsigned long V_77 )
{
struct V_75 * V_76 ;
T_2 V_4 ;
F_62 ( V_134 , 2 , L_80 ) ;
V_76 = (struct V_75 * ) V_77 ;
V_4 = V_76 -> V_161 . V_162 ;
if ( V_4 )
F_38 ( V_28 , 2 , L_81 , V_4 ) ;
switch ( V_76 -> V_77 . V_170 . V_171 ) {
case V_172 :
break;
case V_173 :
switch ( V_4 ) {
case 0 :
case V_174 :
V_28 -> V_94 . V_175 = V_176 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_82
L_83 ) ;
break;
default:
break;
}
break;
case V_177 :
switch ( V_4 ) {
case 0 :
V_28 -> V_94 . V_175 = V_178 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_82
L_84 ) ;
break;
case V_179 :
F_58 ( & V_28 -> V_119 -> V_120 , L_85
L_86
L_87 ) ;
break;
case V_180 :
F_58 ( & V_28 -> V_119 -> V_120 , L_88
L_89
L_90 ) ;
break;
default:
break;
}
break;
default:
F_43 ( 2 , L_91 ,
V_76 -> V_77 . V_170 . V_171 , F_44 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_90 ( struct V_27 * V_28 , enum V_181 V_182 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_92 ) ;
V_74 = F_34 ( V_28 , V_183 , 0 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_170 . V_184 = 16 ;
V_76 -> V_77 . V_170 . V_185 = V_186 ;
V_76 -> V_77 . V_170 . type = V_187 ;
V_76 -> V_77 . V_170 . V_171 = V_182 ;
return F_35 ( V_28 , V_74 , F_89 , NULL ) ;
}
static void F_91 ( T_4 V_188 , char * V_42 )
{
F_92 ( V_188 , V_42 ) ;
}
static void F_93 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
int V_24 ;
F_94 (card->ip_mc_htable, i, addr, hnode)
V_2 -> V_52 = V_53 ;
}
static void F_95 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_67 * V_68 ;
int V_24 ;
int V_4 ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_52 == V_59 ) {
V_4 = F_27 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_62 ) )
V_2 -> V_48 = 1 ;
else {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
}
}
}
static void F_96 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_67 * V_68 ;
int V_24 ;
int V_4 ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_52 == V_53 ) {
V_4 = F_19 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_189 ) ) {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
}
}
}
static void
F_97 ( struct V_27 * V_28 , struct V_190 * V_191 )
{
struct V_192 * V_193 ;
struct V_29 * V_68 , * V_188 ;
char V_1 [ V_194 ] ;
F_16 ( V_28 , 4 , L_93 ) ;
V_68 = F_23 ( V_20 ) ;
if ( ! V_68 )
return;
for ( V_193 = F_98 ( V_191 -> V_195 ) ; V_193 != NULL ;
V_193 = F_98 ( V_193 -> V_196 ) ) {
F_91 ( V_193 -> V_197 , V_1 ) ;
V_68 -> V_36 . V_45 . V_2 = V_193 -> V_197 ;
memcpy ( V_68 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_188 = F_13 ( V_28 , V_68 ) ;
if ( V_188 ) {
V_188 -> V_52 = V_63 ;
} else {
V_188 = F_23 ( V_20 ) ;
if ( ! V_188 )
continue;
memcpy ( V_188 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_188 -> V_36 . V_45 . V_2 = V_193 -> V_197 ;
V_188 -> V_44 = 1 ;
V_188 -> V_52 = V_59 ;
F_24 ( V_28 -> V_198 ,
& V_188 -> V_54 , F_25 ( V_188 ) ) ;
}
}
F_21 ( V_68 ) ;
}
static void F_99 ( struct V_27 * V_28 )
{
struct V_190 * V_199 ;
T_5 V_200 ;
F_16 ( V_28 , 4 , L_94 ) ;
if ( ! F_47 ( V_28 , V_146 ) )
return;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
V_202 = F_101 ( V_28 -> V_120 , F_102 ( V_203 ) ,
V_200 ) ;
if ( V_202 == NULL ||
! ( V_202 -> V_85 & V_204 ) )
continue;
V_199 = F_103 ( V_202 ) ;
if ( ! V_199 )
continue;
F_97 ( V_28 , V_199 ) ;
}
}
static void F_104 ( struct V_27 * V_28 )
{
struct V_190 * V_191 ;
F_16 ( V_28 , 4 , L_95 ) ;
F_105 () ;
V_191 = F_103 ( V_28 -> V_120 ) ;
if ( V_191 == NULL )
goto V_205;
F_97 ( V_28 , V_191 ) ;
F_99 ( V_28 ) ;
V_205:
F_106 () ;
}
static void
F_107 ( struct V_27 * V_28 , struct V_206 * V_207 )
{
struct V_29 * V_188 ;
struct V_208 * V_209 ;
struct V_29 * V_68 ;
char V_1 [ V_194 ] ;
F_16 ( V_28 , 4 , L_96 ) ;
V_68 = F_23 ( V_21 ) ;
if ( ! V_68 )
return;
for ( V_209 = V_207 -> V_195 ; V_209 != NULL ; V_209 = V_209 -> V_210 ) {
F_108 ( & V_209 -> V_211 , V_1 , V_207 -> V_120 , 0 ) ;
memcpy ( V_68 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
memcpy ( & V_68 -> V_36 . V_46 . V_2 , & V_209 -> V_211 . V_212 ,
sizeof( struct V_82 ) ) ;
V_68 -> V_44 = 1 ;
V_188 = F_13 ( V_28 , V_68 ) ;
if ( V_188 ) {
V_188 -> V_52 = V_63 ;
continue;
}
V_188 = F_23 ( V_21 ) ;
if ( ! V_188 )
continue;
memcpy ( V_188 -> V_42 , V_1 , V_80 ) ;
memcpy ( & V_188 -> V_36 . V_46 . V_2 , & V_209 -> V_211 . V_212 ,
sizeof( struct V_82 ) ) ;
V_188 -> V_44 = 1 ;
V_188 -> V_52 = V_59 ;
F_24 ( V_28 -> V_198 ,
& V_188 -> V_54 , F_25 ( V_188 ) ) ;
}
F_21 ( V_68 ) ;
}
static void F_109 ( struct V_27 * V_28 )
{
struct V_206 * V_199 ;
T_5 V_200 ;
F_16 ( V_28 , 4 , L_97 ) ;
if ( ! F_47 ( V_28 , V_146 ) )
return;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
V_202 = F_101 ( V_28 -> V_120 , F_102 ( V_203 ) ,
V_200 ) ;
if ( V_202 == NULL ||
! ( V_202 -> V_85 & V_204 ) )
continue;
V_199 = F_110 ( V_202 ) ;
if ( ! V_199 )
continue;
F_111 ( & V_199 -> V_213 ) ;
F_107 ( V_28 , V_199 ) ;
F_112 ( & V_199 -> V_213 ) ;
F_113 ( V_199 ) ;
}
}
static void F_114 ( struct V_27 * V_28 )
{
struct V_206 * V_207 ;
F_16 ( V_28 , 4 , L_98 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return ;
V_207 = F_110 ( V_28 -> V_120 ) ;
if ( ! V_207 )
return;
F_105 () ;
F_111 ( & V_207 -> V_213 ) ;
F_107 ( V_28 , V_207 ) ;
F_109 ( V_28 ) ;
F_112 ( & V_207 -> V_213 ) ;
F_106 () ;
F_113 ( V_207 ) ;
}
static void F_115 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
struct V_190 * V_199 ;
struct V_214 * V_215 ;
struct V_29 * V_2 ;
struct V_201 * V_202 ;
F_16 ( V_28 , 4 , L_99 ) ;
V_202 = F_101 ( V_28 -> V_120 , F_102 ( V_203 ) , V_200 ) ;
if ( ! V_202 )
return;
V_199 = F_116 ( V_202 ) ;
if ( ! V_199 )
return;
V_2 = F_23 ( V_20 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_60 ) ;
for ( V_215 = V_199 -> V_216 ; V_215 ; V_215 = V_215 -> V_217 ) {
V_2 -> V_36 . V_45 . V_2 = V_215 -> V_218 ;
V_2 -> V_36 . V_45 . V_89 = V_215 -> V_219 ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_2 ) ;
F_117 ( V_199 ) ;
}
static void F_118 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
#ifdef F_46
struct V_206 * V_207 ;
struct V_220 * V_215 ;
struct V_29 * V_2 ;
struct V_201 * V_202 ;
F_16 ( V_28 , 4 , L_100 ) ;
V_202 = F_101 ( V_28 -> V_120 , F_102 ( V_203 ) , V_200 ) ;
if ( ! V_202 )
return;
V_207 = F_110 ( V_202 ) ;
if ( ! V_207 )
return;
V_2 = F_23 ( V_21 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_60 ) ;
F_10 (ifa, &in6_dev->addr_list, if_list) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_215 -> V_2 ,
sizeof( struct V_82 ) ) ;
V_2 -> V_36 . V_46 . V_88 = V_215 -> V_221 ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_2 ) ;
F_113 ( V_207 ) ;
#endif
}
static void F_119 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
F_105 () ;
F_115 ( V_28 , V_200 ) ;
F_118 ( V_28 , V_200 ) ;
F_106 () ;
}
static int F_120 ( struct V_201 * V_120 ,
T_6 V_19 , T_5 V_200 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_121 ( V_200 , V_28 -> V_223 ) ;
return 0 ;
}
static int F_122 ( struct V_201 * V_120 ,
T_6 V_19 , T_5 V_200 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_38 ( V_28 , 4 , L_101 , V_200 ) ;
if ( F_123 ( V_28 , V_224 ) ) {
F_16 ( V_28 , 3 , L_102 ) ;
return 0 ;
}
F_119 ( V_28 , V_200 ) ;
F_124 ( V_200 , V_28 -> V_223 ) ;
F_125 ( V_28 -> V_120 ) ;
return 0 ;
}
static inline int F_126 ( struct V_27 * V_28 ,
struct V_225 * V_226 , struct V_227 * V_161 ,
unsigned short * V_228 )
{
T_6 V_64 ;
struct V_229 * V_230 ;
unsigned char V_231 [ V_194 ] ;
int V_232 = 0 ;
if ( ! ( V_161 -> V_161 . V_233 . V_85 & V_130 ) ) {
V_64 = F_102 ( ( V_161 -> V_161 . V_233 . V_85 & V_131 ) ? V_234 :
V_235 ) ;
switch ( V_161 -> V_161 . V_233 . V_85 & V_236 ) {
case V_125 :
switch ( V_64 ) {
#ifdef F_46
case F_127 ( V_234 ) :
F_108 ( (struct V_82 * )
V_226 -> V_77 + 24 ,
V_231 , V_28 -> V_120 , 0 ) ;
break;
#endif
case F_127 ( V_235 ) :
V_230 = (struct V_229 * ) V_226 -> V_77 ;
F_92 ( V_230 -> V_237 , V_231 ) ;
break;
default:
memcpy ( V_231 , V_28 -> V_120 -> V_238 ,
V_28 -> V_120 -> V_239 ) ;
}
V_28 -> V_240 . V_241 ++ ;
V_226 -> V_242 = V_243 ;
break;
case V_127 :
memcpy ( V_231 , V_28 -> V_120 -> V_238 ,
V_28 -> V_120 -> V_239 ) ;
V_28 -> V_240 . V_241 ++ ;
V_226 -> V_242 = V_244 ;
break;
case V_128 :
case V_133 :
case V_245 :
default:
if ( V_28 -> V_69 . V_70 )
V_226 -> V_242 = V_246 ;
else
V_226 -> V_242 = V_247 ;
memcpy ( V_231 , V_28 -> V_120 -> V_163 ,
V_28 -> V_120 -> V_239 ) ;
}
if ( V_161 -> V_161 . V_233 . V_248 & V_249 )
V_28 -> V_120 -> V_250 -> V_251 ( V_226 , V_28 -> V_120 , V_64 ,
V_231 , & V_161 -> V_161 . V_233 . V_252 [ 2 ] ,
V_28 -> V_120 -> V_239 ) ;
else
V_28 -> V_120 -> V_250 -> V_251 ( V_226 , V_28 -> V_120 , V_64 ,
V_231 , L_103 , V_28 -> V_120 -> V_239 ) ;
}
V_226 -> V_253 = F_128 ( V_226 , V_28 -> V_120 ) ;
if ( V_161 -> V_161 . V_233 . V_248 &
( V_254 | V_255 ) ) {
* V_228 = ( V_161 -> V_161 . V_233 . V_248 & V_254 ) ?
V_161 -> V_161 . V_233 . V_228 : * ( ( T_5 * ) & V_161 -> V_161 . V_233 . V_252 [ 12 ] ) ;
V_232 = 1 ;
}
if ( V_28 -> V_120 -> V_256 & V_257 ) {
if ( ( V_161 -> V_161 . V_233 . V_248 &
( V_258 |
V_259 ) ) ==
( V_258 |
V_259 ) )
V_226 -> V_260 = V_261 ;
else
V_226 -> V_260 = V_262 ;
} else
V_226 -> V_260 = V_262 ;
return V_232 ;
}
static int F_129 ( struct V_27 * V_28 ,
int V_263 , int * V_264 )
{
int V_265 = 0 ;
struct V_225 * V_226 ;
struct V_227 * V_161 ;
T_2 V_266 = 0 ;
int V_232 ;
unsigned int V_23 ;
T_2 V_267 ;
* V_264 = 0 ;
F_130 ( ! V_263 ) ;
while ( V_263 ) {
V_226 = F_131 ( V_28 ,
& V_28 -> V_268 . V_269 -> V_270 [ V_28 -> V_271 . V_272 ] ,
& V_28 -> V_271 . V_273 , & V_28 -> V_271 . V_274 , & V_161 ) ;
if ( ! V_226 ) {
* V_264 = 1 ;
break;
}
V_226 -> V_120 = V_28 -> V_120 ;
switch ( V_161 -> V_161 . V_233 . V_275 ) {
case V_276 :
V_267 = * ( T_2 * ) V_226 -> V_77 ;
if ( ( V_28 -> V_94 . type == V_95 ) &&
( V_267 == V_277 ) ) {
V_226 -> V_253 = V_277 ;
V_226 -> V_242 = V_247 ;
V_226 -> V_278 = V_279 ;
V_226 -> V_120 = V_28 -> V_120 ;
V_23 = V_226 -> V_23 ;
V_28 -> V_120 -> V_250 -> V_251 ( V_226 , V_28 -> V_120 , 0 ,
V_28 -> V_120 -> V_163 , L_103 ,
V_28 -> V_120 -> V_239 ) ;
F_132 ( V_226 ) ;
} else {
V_232 = F_126 ( V_28 , V_226 , V_161 ,
& V_266 ) ;
V_23 = V_226 -> V_23 ;
if ( V_232 && ! V_28 -> V_69 . V_70 )
F_133 ( V_226 ,
F_102 ( V_203 ) , V_266 ) ;
F_134 ( & V_28 -> V_280 , V_226 ) ;
}
break;
case V_281 :
V_226 -> V_242 = V_247 ;
V_226 -> V_253 = F_128 ( V_226 , V_226 -> V_120 ) ;
V_23 = V_226 -> V_23 ;
F_132 ( V_226 ) ;
break;
default:
F_135 ( V_226 ) ;
F_16 ( V_28 , 3 , L_104 ) ;
F_136 ( V_282 , 3 , V_161 , V_283 ) ;
continue;
}
V_265 ++ ;
V_263 -- ;
V_28 -> V_240 . V_284 ++ ;
V_28 -> V_240 . V_285 += V_23 ;
}
return V_265 ;
}
static int F_137 ( struct V_286 * V_280 , int V_263 )
{
struct V_27 * V_28 = F_138 ( V_280 , struct V_27 , V_280 ) ;
int V_265 = 0 ;
struct V_287 * V_288 ;
int V_264 ;
int V_289 = V_263 ;
if ( V_28 -> V_69 . V_290 ) {
V_28 -> V_291 . V_292 ++ ;
V_28 -> V_291 . V_293 = F_139 () ;
}
while ( 1 ) {
if ( ! V_28 -> V_271 . V_294 ) {
V_28 -> V_271 . V_295 = 0 ;
V_28 -> V_271 . V_294 = F_140 (
V_28 -> V_77 . V_296 , 0 , & V_28 -> V_271 . V_272 ,
& V_28 -> V_271 . V_295 ) ;
if ( V_28 -> V_271 . V_294 <= 0 ) {
V_28 -> V_271 . V_294 = 0 ;
break;
}
V_28 -> V_271 . V_273 =
& V_28 -> V_268 . V_269 -> V_270 [ V_28 -> V_271 . V_272 ]
. V_288 -> V_297 [ 0 ] ;
V_28 -> V_271 . V_274 = 0 ;
}
while ( V_28 -> V_271 . V_294 ) {
V_288 = & V_28 -> V_268 . V_269 -> V_270 [ V_28 -> V_271 . V_272 ] ;
if ( ! ( V_28 -> V_271 . V_295 &&
F_141 ( V_28 , V_288 -> V_288 ,
V_28 -> V_271 . V_295 , L_105 ) ) )
V_265 += F_129 (
V_28 , V_289 , & V_264 ) ;
else
V_264 = 1 ;
if ( V_264 ) {
if ( V_28 -> V_69 . V_290 )
V_28 -> V_291 . V_298 ++ ;
F_142 ( V_28 ,
V_288 -> V_299 ) ;
F_143 ( V_28 , V_28 -> V_271 . V_272 ) ;
V_28 -> V_271 . V_294 -- ;
if ( V_28 -> V_271 . V_294 ) {
V_28 -> V_271 . V_272 =
( V_28 -> V_271 . V_272 + 1 ) %
V_300 ;
V_28 -> V_271 . V_273 =
& V_28 -> V_268 . V_269
-> V_270 [ V_28 -> V_271 . V_272 ]
. V_288 -> V_297 [ 0 ] ;
V_28 -> V_271 . V_274 = 0 ;
}
}
if ( V_265 >= V_263 )
goto V_14;
else
V_289 = V_263 - V_265 ;
}
}
F_144 ( V_280 ) ;
if ( F_145 ( V_28 -> V_77 . V_296 , 0 ) )
F_146 ( & V_28 -> V_280 ) ;
V_14:
if ( V_28 -> V_69 . V_290 )
V_28 -> V_291 . V_301 += F_139 () -
V_28 -> V_291 . V_293 ;
return V_265 ;
}
static int F_147 ( struct V_201 * V_120 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_200 ;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
F_105 () ;
V_202 = F_101 ( V_28 -> V_120 , F_102 ( V_203 ) ,
V_200 ) ;
F_106 () ;
if ( V_202 == V_120 ) {
V_4 = V_302 ;
break;
}
}
if ( V_4 && ! ( F_148 ( V_120 ) -> V_222 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_149 ( struct V_201 * V_120 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
unsigned long V_85 ;
F_150 ( & V_303 . V_304 , V_85 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_120 == V_120 ) {
V_4 = V_305 ;
break;
}
V_4 = F_147 ( V_120 , V_28 ) ;
if ( V_4 )
break;
}
F_151 ( & V_303 . V_304 , V_85 ) ;
return V_4 ;
}
static struct V_27 * F_152 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_149 ( V_120 ) ;
if ( V_4 == V_305 )
V_28 = V_120 -> V_222 ;
else if ( V_4 == V_302 )
V_28 = F_148 ( V_120 ) -> V_222 ;
if ( V_28 && V_28 -> V_69 . V_306 )
V_28 = NULL ;
if ( V_28 )
F_38 ( V_28 , 4 , L_106 , V_4 ) ;
return V_28 ;
}
static void F_153 ( struct V_27 * V_28 , int V_307 )
{
F_62 ( V_134 , 2 , L_107 ) ;
F_136 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
F_154 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_69 . V_70 &&
( V_28 -> V_94 . V_175 == V_178 ) )
F_90 ( V_28 , V_173 ) ;
if ( V_28 -> V_308 . V_309 == V_310 &&
V_28 -> V_311 . V_309 == V_310 &&
( V_28 -> V_309 == V_312 ) ) {
if ( V_307 )
F_155 ( V_28 -> V_120 ) ;
else {
F_156 () ;
F_157 ( V_28 -> V_120 ) ;
F_158 () ;
}
V_28 -> V_309 = V_313 ;
}
if ( V_28 -> V_309 == V_313 ) {
F_30 ( V_28 , 1 ) ;
F_159 ( V_28 ) ;
V_28 -> V_309 = V_314 ;
}
if ( V_28 -> V_309 == V_314 ) {
F_160 ( V_28 , 0 ) ;
F_161 ( V_28 ) ;
F_162 ( V_28 ) ;
V_28 -> V_309 = V_315 ;
}
if ( V_28 -> V_309 == V_315 ) {
F_163 ( & V_28 -> V_308 ) ;
F_163 ( & V_28 -> V_311 ) ;
}
}
static void
F_164 ( struct V_27 * V_28 )
{
struct V_201 * V_120 = V_28 -> V_120 ;
if ( ( ( V_120 -> V_85 & V_316 ) &&
( V_28 -> V_94 . V_175 == V_178 ) ) ||
( ! ( V_120 -> V_85 & V_316 ) &&
( V_28 -> V_94 . V_175 == V_176 ) ) )
return;
if ( V_28 -> V_94 . V_317 ) {
if ( F_66 ( V_28 , V_318 ) )
F_165 ( V_28 ) ;
} else if ( V_28 -> V_69 . V_70 &&
F_66 ( V_28 , V_319 ) ) {
if ( V_120 -> V_85 & V_316 ) {
F_16 ( V_28 , 3 , L_108 ) ;
F_90 ( V_28 , V_177 ) ;
} else {
F_16 ( V_28 , 3 , L_109 ) ;
F_90 ( V_28 , V_173 ) ;
}
}
}
static void F_125 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 3 , L_110 ) ;
if ( F_166 ( V_28 , V_224 ) &&
( V_28 -> V_309 != V_312 ) )
return;
if ( ! V_28 -> V_69 . V_70 ) {
F_28 ( & V_28 -> V_71 ) ;
F_93 ( V_28 ) ;
F_104 ( V_28 ) ;
#ifdef F_46
F_114 ( V_28 ) ;
#endif
F_96 ( V_28 ) ;
F_95 ( V_28 ) ;
F_26 ( & V_28 -> V_71 ) ;
if ( ! F_66 ( V_28 , V_318 ) )
return;
}
F_164 ( V_28 ) ;
}
static const char * F_167 ( int * V_4 )
{
switch ( * V_4 ) {
case V_320 :
* V_4 = - V_158 ;
return L_111 ;
case V_321 :
* V_4 = - V_144 ;
return L_112 ;
case V_322 :
* V_4 = - V_7 ;
return L_113 ;
case V_323 :
* V_4 = - V_144 ;
return L_114 ;
case V_324 :
* V_4 = - V_47 ;
return L_115 ;
default:
return L_116 ;
}
}
static int F_168 ( struct V_27 * V_28 , int V_325 )
{
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_117 ) ;
if ( V_28 -> V_94 . V_317 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_326 ,
V_325 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_118
L_119 , F_44 ( V_28 ) ,
F_167 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static T_4 F_169 ( struct V_27 * V_28 ,
struct V_327 * V_328 ,
struct V_329 * type , T_1 V_330 )
{
T_4 V_4 ;
T_1 V_331 ;
V_331 = V_328 -> V_332 == 5 ;
if ( type -> V_333 == V_334 ) {
F_16 ( V_28 , 4 , L_120 ) ;
if ( V_330 ) {
V_4 = V_331 ? sizeof( struct V_335 ) :
sizeof( struct V_336 ) ;
} else {
V_4 = V_331 ? sizeof( struct V_337 ) :
sizeof( struct V_338 ) ;
}
} else if ( type -> V_333 == V_339 ) {
F_16 ( V_28 , 4 , L_121 ) ;
if ( V_330 ) {
V_4 = V_331 ?
sizeof( struct V_340 ) :
sizeof( struct V_341 ) ;
} else {
V_4 = V_331 ?
sizeof( struct V_342 ) :
sizeof( struct V_343 ) ;
}
} else {
F_16 ( V_28 , 4 , L_122 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_170 ( struct V_329 * type , T_2 V_64 )
{
return ( type -> V_333 == V_334 && V_64 == V_20 ) ||
( type -> V_333 == V_339 && V_64 == V_21 ) ;
}
static int F_171 ( struct V_27 * V_28 ,
struct V_159 * V_160 , unsigned long V_77 )
{
struct V_75 * V_76 ;
struct V_327 * V_328 ;
struct V_344 * V_345 ;
int V_24 ;
int V_346 ;
int V_347 ;
int V_348 ;
T_1 V_349 ;
F_16 ( V_28 , 3 , L_123 ) ;
V_345 = (struct V_344 * ) V_160 -> V_350 ;
V_76 = (struct V_75 * ) V_77 ;
F_38 ( V_28 , 4 , L_124 , V_76 -> V_161 . V_351 ) ;
if ( V_76 -> V_161 . V_162 ) {
F_16 ( V_28 , 4 , L_125 ) ;
F_38 ( V_28 , 4 , L_124 , V_76 -> V_161 . V_162 ) ;
return 0 ;
}
if ( V_76 -> V_77 . V_352 . V_161 . V_162 ) {
V_76 -> V_161 . V_162 = V_76 -> V_77 . V_352 . V_161 . V_162 ;
F_16 ( V_28 , 4 , L_126 ) ;
F_38 ( V_28 , 4 , L_124 , V_76 -> V_161 . V_162 ) ;
return 0 ;
}
V_328 = & V_76 -> V_77 . V_352 . V_77 . V_353 ;
F_38 ( V_28 , 4 , L_127 , V_328 -> V_325 ) ;
V_349 = ( V_345 -> V_37 & V_354 ) > 0 ;
V_348 = V_349 ? V_355 : 0 ;
V_347 = 0 ;
for ( V_346 = 0 ; V_346 < V_328 -> V_325 ; ++ V_346 ) {
char * V_356 ;
T_4 V_357 ;
struct V_329 * V_358 ;
V_356 = & V_328 -> V_77 + V_347 ;
V_358 = & ( (struct V_337 * ) V_356 ) -> type ;
if ( ! F_170 ( V_358 , V_76 -> V_161 . V_351 ) ) {
F_16 ( V_28 , 4 , L_128 ) ;
F_38 ( V_28 , 4 , L_124 , V_358 -> V_333 ) ;
break;
}
V_357 = F_169 ( V_28 , V_328 , V_358 ,
V_349 ) ;
F_38 ( V_28 , 5 , L_129 , V_357 ) ;
if ( ! V_357 )
break;
if ( ( V_345 -> V_359 - V_345 -> V_360 ) < V_357 ) {
F_38 ( V_28 , 4 , L_130 , - V_55 ) ;
V_76 -> V_161 . V_162 = V_361 ;
goto V_362;
}
memcpy ( V_345 -> V_363 + V_345 -> V_360 ,
& V_328 -> V_77 + V_347 + V_348 ,
V_357 ) ;
V_347 += V_357 + V_348 ;
V_345 -> V_360 += V_357 ;
++ V_345 -> V_325 ;
}
if ( V_76 -> V_77 . V_352 . V_161 . V_364 <
V_76 -> V_77 . V_352 . V_161 . V_365 )
return 1 ;
F_38 ( V_28 , 4 , L_131 , V_345 -> V_325 ) ;
memcpy ( V_345 -> V_363 , & V_345 -> V_325 , 4 ) ;
if ( V_345 -> V_37 & V_354 )
V_328 -> V_332 |= V_354 ;
memcpy ( V_345 -> V_363 + V_366 , & V_328 -> V_332 , 2 ) ;
F_38 ( V_28 , 4 , L_132 , 0 ) ;
return 0 ;
V_362:
V_24 = 0 ;
memcpy ( V_345 -> V_363 , & V_24 , 4 ) ;
return 0 ;
}
static int F_172 ( struct V_27 * V_28 ,
struct V_73 * V_74 , int V_23 ,
int (* F_173)( struct V_27 * , struct V_159 * ,
unsigned long ) ,
void * V_367 )
{
F_16 ( V_28 , 4 , L_133 ) ;
memcpy ( V_74 -> V_77 , V_368 , V_78 ) ;
memcpy ( F_174 ( V_74 -> V_77 ) ,
& V_28 -> V_369 . V_370 , V_371 ) ;
return F_175 ( V_28 , V_78 + V_23 , V_74 ,
F_173 , V_367 ) ;
}
static int F_176 ( struct V_27 * V_28 ,
enum V_18 V_64 ,
struct V_344 * V_345 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_68 ;
int V_4 ;
F_38 ( V_28 , 3 , L_134 , V_64 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_372 ,
sizeof( struct V_327 )
- sizeof( char ) ,
V_64 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_352 . V_77 . V_353 . V_373 = 0x000F ;
V_76 -> V_77 . V_352 . V_77 . V_353 . V_332 = 0 ;
V_76 -> V_77 . V_352 . V_77 . V_353 . V_325 = 0 ;
V_4 = F_172 ( V_28 , V_74 ,
V_374 + V_375 ,
F_171 , ( void * ) V_345 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 ,
L_135
L_136 , F_44 ( V_28 ) ,
F_167 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_177 ( struct V_27 * V_28 , char T_7 * V_363 )
{
struct V_344 V_345 = { 0 , } ;
int V_4 ;
F_16 ( V_28 , 3 , L_137 ) ;
if ( ! F_47 ( V_28 ,
V_141 ) ) {
F_16 ( V_28 , 3 , L_138 ) ;
V_4 = - V_144 ;
goto V_14;
}
if ( F_178 ( & V_345 , V_363 , 6 ) ) {
V_4 = - V_376 ;
goto V_14;
}
V_345 . V_363 = F_29 ( V_345 . V_359 , V_377 ) ;
if ( ! V_345 . V_363 ) {
V_4 = - V_55 ;
goto V_14;
}
V_345 . V_360 = V_378 ;
V_4 = F_176 ( V_28 , V_20 , & V_345 ) ;
if ( V_4 ) {
if ( F_179 ( V_363 , V_345 . V_363 , 4 ) )
V_4 = - V_376 ;
goto V_379;
}
#ifdef F_46
if ( V_345 . V_37 & V_380 ) {
F_176 ( V_28 , V_21 , & V_345 ) ;
}
#endif
if ( F_179 ( V_363 , V_345 . V_363 , V_345 . V_359 ) ) {
F_16 ( V_28 , 4 , L_139 ) ;
V_4 = - V_376 ;
goto V_379;
}
F_16 ( V_28 , 4 , L_140 ) ;
V_379:
F_21 ( V_345 . V_363 ) ;
V_14:
return V_4 ;
}
static int F_180 ( struct V_27 * V_28 ,
struct V_381 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_141 ) ;
if ( V_28 -> V_94 . V_317 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_74 = F_69 ( V_28 , V_141 ,
V_382 ,
sizeof( struct V_381 ) ,
V_20 ) ;
if ( ! V_74 )
return - V_55 ;
V_4 = F_70 ( V_28 , V_74 ,
sizeof( struct V_381 ) ,
( unsigned long ) V_107 ,
V_140 , NULL ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_2 ( ( T_3 * ) V_107 -> V_111 , V_1 ) ;
F_43 ( 2 , L_142
L_143 , V_1 , F_44 ( V_28 ) ,
F_167 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_181 ( struct V_27 * V_28 ,
struct V_381 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] = { 0 , } ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_144 ) ;
if ( V_28 -> V_94 . V_317 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
memcpy ( V_1 , V_107 , 12 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_383 ,
12 ,
V_20 ) ;
if ( ! V_74 )
return - V_55 ;
V_4 = F_70 ( V_28 , V_74 ,
12 , ( unsigned long ) V_1 ,
V_140 , NULL ) ;
if ( V_4 ) {
V_68 = V_4 ;
memset ( V_1 , 0 , 16 ) ;
F_2 ( ( T_3 * ) V_107 -> V_111 , V_1 ) ;
F_43 ( 2 , L_145
L_146 , V_1 , F_44 ( V_28 ) ,
F_167 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_182 ( struct V_27 * V_28 )
{
int V_4 ;
int V_68 ;
F_16 ( V_28 , 3 , L_147 ) ;
if ( V_28 -> V_94 . V_317 || ( V_28 -> V_94 . type == V_95 ) )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_384 , 0 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_148
L_136 , F_44 ( V_28 ) ,
F_167 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_183 ( struct V_201 * V_120 , struct V_385 * V_386 , int V_76 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
struct V_381 V_387 ;
struct V_388 * V_389 ;
int V_4 = 0 ;
if ( ! V_28 )
return - V_390 ;
if ( ! F_18 ( V_28 ) )
return - V_390 ;
switch ( V_76 ) {
case V_391 :
if ( ! F_184 ( V_392 ) ) {
V_4 = - V_393 ;
break;
}
V_4 = F_168 ( V_28 , V_386 -> V_394 . V_395 ) ;
break;
case V_396 :
if ( ! F_184 ( V_392 ) ) {
V_4 = - V_393 ;
break;
}
V_4 = F_177 ( V_28 , V_386 -> V_394 . V_397 ) ;
break;
case V_398 :
if ( ! F_184 ( V_392 ) ) {
V_4 = - V_393 ;
break;
}
if ( F_178 ( & V_387 , V_386 -> V_394 . V_397 ,
sizeof( struct V_381 ) ) )
V_4 = - V_376 ;
else
V_4 = F_180 ( V_28 , & V_387 ) ;
break;
case V_399 :
if ( ! F_184 ( V_392 ) ) {
V_4 = - V_393 ;
break;
}
if ( F_178 ( & V_387 , V_386 -> V_394 . V_397 ,
sizeof( struct V_381 ) ) )
V_4 = - V_376 ;
else
V_4 = F_181 ( V_28 , & V_387 ) ;
break;
case V_400 :
if ( ! F_184 ( V_392 ) ) {
V_4 = - V_393 ;
break;
}
V_4 = F_182 ( V_28 ) ;
break;
case V_401 :
V_4 = F_185 ( V_28 , V_386 -> V_394 . V_397 ) ;
break;
case V_402 :
if ( ( V_28 -> V_94 . type == V_403 ||
V_28 -> V_94 . type == V_404 ) &&
! V_28 -> V_94 . V_317 )
return 1 ;
return 0 ;
break;
case V_405 :
V_389 = F_186 ( V_386 ) ;
V_389 -> V_406 = 0 ;
break;
case V_407 :
V_389 = F_186 ( V_386 ) ;
if ( V_389 -> V_406 != 0 )
V_4 = - V_7 ;
else
V_389 -> V_408 = F_187 ( V_120 ,
V_389 -> V_406 ,
V_389 -> V_409 ) ;
break;
case V_410 :
V_4 = F_188 ( V_28 , V_386 -> V_394 . V_397 ) ;
break;
default:
V_4 = - V_144 ;
}
if ( V_4 )
F_38 ( V_28 , 2 , L_149 , V_4 ) ;
return V_4 ;
}
int inline F_189 ( struct V_27 * V_28 , struct V_225 * V_226 )
{
int V_123 = V_411 ;
struct V_412 * V_413 = NULL ;
struct V_414 * V_415 ;
F_105 () ;
V_415 = F_190 ( V_226 ) ;
if ( V_415 )
V_413 = F_191 ( V_415 , V_226 ) ;
if ( V_413 ) {
V_123 = V_413 -> type ;
F_106 () ;
F_192 ( V_413 ) ;
if ( ( V_123 == V_126 ) ||
( V_123 == V_124 ) ||
( V_123 == V_132 ) )
return V_123 ;
else
return V_411 ;
}
F_106 () ;
if ( V_226 -> V_253 == V_234 )
return ( F_193 ( V_226 ) [ 24 ] == 0xff ) ?
V_124 : 0 ;
else if ( V_226 -> V_253 == V_235 )
return ( ( F_193 ( V_226 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_124 : 0 ;
if ( ! memcmp ( V_226 -> V_77 , V_226 -> V_120 -> V_238 , 6 ) )
return V_126 ;
else {
T_5 V_416 ;
V_416 = * ( ( T_5 * ) V_226 -> V_77 ) ;
switch ( V_28 -> V_94 . V_417 ) {
case V_418 :
case V_419 :
if ( ( V_416 == V_420 ) ||
( V_416 == V_421 ) )
return V_124 ;
break;
default:
if ( ( V_416 == V_422 ) ||
( V_416 == V_423 ) )
return V_124 ;
}
}
return V_123 ;
}
static void F_194 ( struct V_27 * V_28 ,
struct V_227 * V_161 , struct V_225 * V_226 )
{
char V_237 [ 16 ] ;
struct V_424 * V_425 ;
memset ( V_161 , 0 , sizeof( struct V_227 ) ) ;
V_161 -> V_161 . V_233 . V_275 = V_276 ;
V_161 -> V_161 . V_233 . V_248 = 0 ;
V_161 -> V_161 . V_233 . V_426 = V_226 -> V_23 - V_427 ;
V_161 -> V_161 . V_233 . V_85 = V_131 | V_128 ;
V_425 = (struct V_424 * ) ( V_226 -> V_77 + V_427 ) ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
V_237 [ 0 ] = 0xfe ;
V_237 [ 1 ] = 0x80 ;
memcpy ( & V_237 [ 8 ] , V_425 -> V_428 , 8 ) ;
memcpy ( V_161 -> V_161 . V_233 . V_252 , V_237 , 16 ) ;
}
static void F_195 ( struct V_27 * V_28 , struct V_227 * V_161 ,
struct V_225 * V_226 , int V_429 , int V_123 )
{
struct V_414 * V_415 ;
memset ( V_161 , 0 , sizeof( struct V_227 ) ) ;
V_161 -> V_161 . V_233 . V_275 = V_276 ;
V_161 -> V_161 . V_233 . V_248 = 0 ;
if ( F_196 ( V_226 ) ) {
if ( ( V_429 == 4 ) || ( V_28 -> V_94 . type == V_95 ) )
V_161 -> V_161 . V_233 . V_248 = V_254 ;
else
V_161 -> V_161 . V_233 . V_248 = V_255 ;
V_161 -> V_161 . V_233 . V_228 = F_197 ( V_226 ) ;
}
V_161 -> V_161 . V_233 . V_426 = V_226 -> V_23 - sizeof( struct V_227 ) ;
F_105 () ;
V_415 = F_190 ( V_226 ) ;
if ( V_429 == 4 ) {
struct V_430 * V_431 = (struct V_430 * ) V_415 ;
T_8 * V_432 = & V_230 ( V_226 ) -> V_237 ;
if ( V_431 -> V_433 )
V_432 = & V_431 -> V_433 ;
V_161 -> V_161 . V_233 . V_85 = F_59 ( V_123 ) ;
memset ( V_161 -> V_161 . V_233 . V_252 , 0 , 12 ) ;
* ( ( T_8 * ) ( & V_161 -> V_161 . V_233 . V_252 [ 12 ] ) ) = * V_432 ;
} else if ( V_429 == 6 ) {
struct V_434 * V_431 = (struct V_434 * ) V_415 ;
struct V_82 * V_432 = & F_198 ( V_226 ) -> V_237 ;
if ( ! F_199 ( & V_431 -> V_435 ) )
V_432 = & V_431 -> V_435 ;
V_161 -> V_161 . V_233 . V_85 = F_60 ( V_123 ) ;
if ( V_28 -> V_94 . type == V_95 )
V_161 -> V_161 . V_233 . V_85 &= ~ V_130 ;
memcpy ( V_161 -> V_161 . V_233 . V_252 , V_432 , 16 ) ;
} else {
if ( ! memcmp ( V_226 -> V_77 + sizeof( struct V_227 ) ,
V_226 -> V_120 -> V_238 , 6 ) ) {
V_161 -> V_161 . V_233 . V_85 = V_127 |
V_130 ;
} else {
V_161 -> V_161 . V_233 . V_85 = ( V_123 == V_124 ) ?
V_125 | V_130 :
V_128 | V_130 ;
}
}
F_106 () ;
}
static inline void F_200 ( struct V_27 * V_28 ,
struct V_227 * V_161 , struct V_225 * V_226 )
{
struct V_229 * V_436 = V_230 ( V_226 ) ;
if ( V_436 -> V_253 == V_437 )
V_161 -> V_161 . V_233 . V_248 |= V_438 ;
V_161 -> V_161 . V_233 . V_248 |= V_259 |
V_258 ;
V_436 -> V_439 = 0 ;
if ( V_28 -> V_69 . V_290 )
V_28 -> V_291 . V_440 ++ ;
}
static void F_201 ( struct V_27 * V_28 ,
struct V_227 * V_441 , struct V_225 * V_226 )
{
struct V_442 * V_161 = (struct V_442 * ) V_441 ;
struct V_443 * V_444 = F_202 ( V_226 ) ;
struct V_229 * V_436 = V_230 ( V_226 ) ;
struct V_445 * V_446 = F_198 ( V_226 ) ;
V_161 -> V_161 . V_161 . V_233 . V_275 = V_447 ;
V_161 -> V_161 . V_161 . V_233 . V_426 = V_226 -> V_23 - sizeof( struct V_442 ) ;
V_161 -> V_448 . V_449 = ( T_2 ) sizeof( struct V_450 ) ;
V_161 -> V_448 . V_451 = 1 ;
V_161 -> V_448 . V_452 = 1 ;
V_161 -> V_448 . V_453 = 1 ;
V_161 -> V_448 . V_454 = 28 ;
V_161 -> V_448 . V_455 = F_203 ( V_226 ) -> V_456 ;
V_161 -> V_448 . V_457 = ( T_2 ) ( V_436 -> V_458 * 4 + V_444 -> V_459 * 4 ) ;
V_161 -> V_448 . V_460 = ( T_2 ) ( V_226 -> V_23 - V_161 -> V_448 . V_457 -
sizeof( struct V_442 ) ) ;
V_444 -> V_439 = 0 ;
if ( V_226 -> V_253 == V_234 ) {
V_446 -> V_460 = 0 ;
V_444 -> V_439 = ~ F_204 ( & V_446 -> V_461 , & V_446 -> V_237 ,
0 , V_462 , 0 ) ;
} else {
V_444 -> V_439 = ~ F_205 ( V_436 -> V_461 , V_436 -> V_237 ,
0 , V_462 , 0 ) ;
V_436 -> V_463 = 0 ;
V_436 -> V_439 = 0 ;
}
}
static int F_206 ( struct V_27 * V_28 ,
struct V_225 * V_226 , int V_464 )
{
T_9 V_465 = ( T_9 ) F_202 ( V_226 ) + F_207 ( V_226 ) ;
int V_466 = F_208 (
V_465 ,
( T_9 ) V_226 -> V_77 + F_209 ( V_226 ) ) +
F_210 ( V_226 ) ;
if ( ( V_466 + V_464 ) > F_211 ( V_28 ) ) {
F_43 ( 2 ,
L_150 ,
V_466 + V_464 , V_226 -> V_23 ) ;
return 0 ;
}
return V_466 ;
}
static int F_212 ( struct V_225 * V_226 , struct V_201 * V_120 )
{
int V_4 ;
T_5 * V_467 ;
struct V_227 * V_161 = NULL ;
int V_468 = 0 ;
int V_466 ;
struct V_27 * V_28 = V_120 -> V_222 ;
struct V_225 * V_469 = NULL ;
int V_429 = F_213 ( V_226 ) ;
int V_123 = F_189 ( V_28 , V_226 ) ;
struct V_470 * V_471 =
V_28 -> V_268 . V_472 [ V_28 -> V_268 . V_473
|| ( V_123 && V_28 -> V_94 . V_474 ) ?
F_214 ( V_28 , V_226 , V_429 , V_123 ) :
V_28 -> V_268 . V_475 ] ;
int V_476 = V_226 -> V_23 ;
bool V_477 ;
int V_478 = - 1 ;
int V_479 ;
if ( ( ( V_28 -> V_94 . type == V_95 ) &&
( ( ( V_28 -> V_69 . V_480 != V_481 ) && ! V_429 ) ||
( ( V_28 -> V_69 . V_480 == V_481 ) &&
( V_226 -> V_253 != V_277 ) ) ) ) ||
V_28 -> V_69 . V_70 )
goto V_482;
if ( ( V_28 -> V_309 != V_312 ) || ! V_28 -> V_483 ) {
V_28 -> V_240 . V_484 ++ ;
goto V_482;
}
if ( ( V_123 == V_126 ) &&
( V_28 -> V_94 . V_151 == 0 ) )
goto V_482;
if ( V_28 -> V_69 . V_290 ) {
V_28 -> V_291 . V_485 ++ ;
V_28 -> V_291 . V_486 = F_139 () ;
}
V_477 = F_215 ( V_226 ) &&
( F_216 ( V_226 ) == V_462 ) && ( V_429 == 4 ) ;
if ( ( V_28 -> V_94 . type == V_95 ) &&
! F_217 ( V_226 ) ) {
V_469 = V_226 ;
V_478 = V_427 ;
V_161 = F_218 ( V_487 , V_65 ) ;
if ( ! V_161 )
goto V_482;
V_468 ++ ;
} else {
V_469 = F_219 ( V_226 , sizeof( struct V_442 )
+ V_488 ) ;
if ( ! V_469 )
goto V_482;
}
if ( V_28 -> V_94 . type == V_95 ) {
if ( V_478 < 0 )
F_220 ( V_469 , V_427 ) ;
} else {
if ( V_429 == 4 ) {
F_220 ( V_469 , V_427 ) ;
}
if ( V_429 != 4 && F_196 ( V_469 ) ) {
F_221 ( V_469 , V_488 ) ;
F_222 ( V_469 , V_469 -> V_77 + 4 , 4 ) ;
F_223 ( V_469 , 4 ,
V_469 -> V_77 + 8 , 4 ) ;
F_223 ( V_469 , 8 ,
V_469 -> V_77 + 12 , 4 ) ;
V_467 = ( T_5 * ) ( V_469 -> V_77 + 12 ) ;
* V_467 = F_127 ( V_203 ) ;
* ( V_467 + 1 ) = F_102 ( F_197 ( V_469 ) ) ;
}
}
F_224 ( V_120 ) ;
if ( ( V_28 -> V_94 . type != V_95 ) &&
( ( V_477 && ! F_206 ( V_28 , V_469 , 1 ) ) ||
( ! V_477 && ! F_225 ( V_28 , V_469 , 0 , 0 ) ) ) ) {
int V_489 = F_226 ( V_469 ) ;
if ( V_28 -> V_69 . V_290 ) {
if ( V_489 )
V_28 -> V_291 . V_490 ++ ;
else
V_28 -> V_291 . V_491 ++ ;
}
if ( V_489 )
goto V_482;
}
if ( V_477 ) {
V_161 = (struct V_227 * ) F_221 ( V_469 ,
sizeof( struct V_442 ) ) ;
memset ( V_161 , 0 , sizeof( struct V_442 ) ) ;
F_195 ( V_28 , V_161 , V_469 , V_429 , V_123 ) ;
F_201 ( V_28 , V_161 , V_469 ) ;
V_468 ++ ;
} else {
if ( V_478 < 0 ) {
V_161 = (struct V_227 * ) F_221 ( V_469 ,
sizeof( struct V_227 ) ) ;
F_195 ( V_28 , V_161 , V_469 , V_429 ,
V_123 ) ;
} else {
if ( V_469 -> V_253 == V_277 )
F_194 ( V_28 , V_161 , V_469 ) ;
else {
F_195 ( V_28 , V_161 , V_469 , V_429 ,
V_123 ) ;
V_161 -> V_161 . V_233 . V_426 = V_469 -> V_23 - V_478 ;
}
}
if ( V_226 -> V_260 == V_492 )
F_200 ( V_28 , V_161 , V_469 ) ;
}
V_466 = V_477 ?
F_206 ( V_28 , V_469 , V_468 ) :
F_225 ( V_28 , V_469 , V_468 ,
( V_478 > 0 ) ? V_478 : 0 ) ;
if ( ! V_466 ) {
if ( V_478 >= 0 )
F_227 ( V_487 , V_161 ) ;
goto V_482;
}
V_466 += V_468 ;
if ( V_28 -> V_94 . type != V_95 ) {
int V_23 ;
if ( V_477 )
V_23 = ( ( unsigned long ) F_202 ( V_469 ) +
F_207 ( V_469 ) ) -
( unsigned long ) V_469 -> V_77 ;
else
V_23 = sizeof( struct V_493 ) ;
if ( F_228 ( V_469 , & V_161 , V_23 ) )
goto V_482;
V_4 = F_229 ( V_28 , V_471 , V_469 , V_161 , V_466 ) ;
} else
V_4 = F_230 ( V_28 , V_471 , V_469 , V_161 ,
V_466 , V_478 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_240 . V_494 ++ ;
V_28 -> V_240 . V_476 += V_476 ;
if ( V_469 != V_226 )
F_135 ( V_226 ) ;
if ( V_28 -> V_69 . V_290 ) {
V_479 = F_203 ( V_469 ) -> V_479 ;
if ( V_477 ) {
V_28 -> V_291 . V_495 += V_476 ;
V_28 -> V_291 . V_496 ++ ;
}
if ( V_479 ) {
V_28 -> V_291 . V_497 ++ ;
V_28 -> V_291 . V_498 += V_479 + 1 ;
}
}
V_4 = V_499 ;
} else {
if ( V_478 >= 0 )
F_227 ( V_487 , V_161 ) ;
if ( V_4 == - V_500 ) {
if ( V_469 != V_226 )
F_135 ( V_469 ) ;
return V_501 ;
} else
goto V_482;
}
F_231 ( V_120 ) ;
if ( V_28 -> V_69 . V_290 )
V_28 -> V_291 . V_502 += F_139 () -
V_28 -> V_291 . V_486 ;
return V_4 ;
V_482:
V_28 -> V_240 . V_503 ++ ;
V_28 -> V_240 . V_504 ++ ;
if ( ( V_469 != V_226 ) && V_469 )
F_135 ( V_469 ) ;
F_135 ( V_226 ) ;
F_231 ( V_120 ) ;
return V_499 ;
}
static int F_232 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
int V_4 = 0 ;
F_16 ( V_28 , 4 , L_151 ) ;
if ( V_28 -> V_309 == V_312 )
return V_4 ;
if ( V_28 -> V_309 != V_313 )
return - V_390 ;
V_28 -> V_77 . V_309 = V_310 ;
V_28 -> V_309 = V_312 ;
F_233 ( V_120 ) ;
if ( F_234 ( V_28 -> V_77 . V_296 , 0 ) >= 0 ) {
F_235 ( & V_28 -> V_280 ) ;
F_146 ( & V_28 -> V_280 ) ;
} else
V_4 = - V_158 ;
return V_4 ;
}
static int F_236 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 5 , L_152 ) ;
if ( F_123 ( V_28 , V_224 ) ) {
F_16 ( V_28 , 3 , L_153 ) ;
return - V_505 ;
}
return F_232 ( V_120 ) ;
}
static int F_155 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 4 , L_154 ) ;
F_237 ( V_120 ) ;
if ( V_28 -> V_309 == V_312 ) {
V_28 -> V_309 = V_313 ;
F_238 ( & V_28 -> V_280 ) ;
}
return 0 ;
}
static int F_239 ( struct V_412 * V_413 )
{
V_413 -> V_506 = V_507 ;
memcpy ( V_413 -> V_508 , L_103 , 6 ) ;
V_413 -> V_509 = V_413 -> V_510 -> V_511 ;
return 0 ;
}
static int
F_240 ( struct V_201 * V_120 , struct V_512 * V_513 )
{
if ( V_513 -> V_514 -> V_515 == V_516 )
V_513 -> V_517 = F_239 ;
return 0 ;
}
static int F_241 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_94 . type == V_403 ||
V_28 -> V_94 . type == V_404 ) {
if ( ( V_28 -> V_94 . V_417 == V_419 ) ||
( V_28 -> V_94 . V_417 == V_418 ) ) {
F_242 ( L_155 ) ;
return - V_390 ;
} else {
V_28 -> V_120 = F_243 ( 0 ) ;
if ( ! V_28 -> V_120 )
return - V_390 ;
V_28 -> V_120 -> V_518 = & V_519 ;
F_88 ( V_28 ) ;
if ( ! ( V_28 -> V_94 . V_165 & V_169 ) )
V_28 -> V_120 -> V_520 = V_28 -> V_94 . V_165 &
0xffff ;
if ( ! V_28 -> V_94 . V_317 ) {
V_28 -> V_120 -> V_521 = V_522 |
V_257 | V_523 |
V_524 ;
V_28 -> V_120 -> V_525 = V_522 |
V_257 | V_523 |
V_524 ;
}
}
} else if ( V_28 -> V_94 . type == V_95 ) {
V_28 -> V_120 = F_244 ( 0 , L_156 , V_526 ,
V_527 ) ;
if ( ! V_28 -> V_120 )
return - V_390 ;
V_28 -> V_120 -> V_85 |= V_528 ;
V_28 -> V_120 -> V_518 = & V_529 ;
V_4 = F_86 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_69 . V_530 [ 0 ] )
memcpy ( V_28 -> V_120 -> V_531 , V_28 -> V_69 . V_530 , 9 ) ;
} else
return - V_390 ;
V_28 -> V_120 -> V_222 = V_28 ;
V_28 -> V_120 -> V_532 = V_533 ;
V_28 -> V_120 -> V_534 = V_28 -> V_94 . V_535 ;
V_28 -> V_120 -> V_536 = 64 ;
V_28 -> V_120 -> V_537 = V_538 ;
V_28 -> V_120 -> V_539 = & V_540 ;
V_28 -> V_120 -> V_256 |= V_541 |
V_542 |
V_543 ;
F_245 ( V_28 -> V_120 ) ;
V_28 -> V_120 -> V_544 = ( F_211 ( V_28 ) - 1 ) *
V_545 ;
F_246 ( V_28 -> V_120 , & V_28 -> V_119 -> V_120 ) ;
F_247 ( V_28 -> V_120 , & V_28 -> V_280 , F_137 , V_546 ) ;
F_248 ( V_28 -> V_120 ) ;
return F_249 ( V_28 -> V_120 ) ;
}
static int F_250 ( struct V_547 * V_119 )
{
struct V_27 * V_28 = F_251 ( & V_119 -> V_120 ) ;
F_252 ( & V_119 -> V_120 ) ;
V_28 -> V_69 . V_306 = 0 ;
V_28 -> V_94 . V_548 = 0 ;
return 0 ;
}
static void F_253 ( struct V_547 * V_549 )
{
struct V_27 * V_28 = F_251 ( & V_549 -> V_120 ) ;
F_254 ( & V_549 -> V_120 ) ;
F_154 ( V_28 , 0 , 1 ) ;
F_255 ( V_28 -> V_550 , F_166 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_549 -> V_309 == V_551 )
F_256 ( V_549 ) ;
if ( V_28 -> V_120 ) {
F_257 ( & V_28 -> V_280 ) ;
F_258 ( V_28 -> V_120 ) ;
V_28 -> V_120 = NULL ;
}
F_30 ( V_28 , 0 ) ;
F_48 ( V_28 ) ;
return;
}
static int F_259 ( struct V_547 * V_119 , int V_307 )
{
struct V_27 * V_28 = F_251 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
enum V_552 V_553 ;
F_260 ( & V_28 -> V_554 ) ;
F_260 ( & V_28 -> V_555 ) ;
F_62 ( V_134 , 2 , L_157 ) ;
F_136 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
V_553 = V_28 -> V_309 ;
V_4 = F_261 ( V_28 ) ;
if ( V_4 ) {
F_262 ( V_134 , 2 , L_158 , V_4 ) ;
V_4 = - V_390 ;
goto V_556;
}
if ( ! V_28 -> V_120 && F_241 ( V_28 ) ) {
V_4 = - V_390 ;
goto V_556;
}
if ( F_263 ( V_28 , V_557 ) ) {
if ( V_28 -> V_94 . V_548 &&
F_264 ( V_28 , V_558 ) )
V_28 -> V_94 . V_548 = 0 ;
} else
V_28 -> V_94 . V_548 = 0 ;
V_28 -> V_309 = V_314 ;
memset ( & V_28 -> V_271 , 0 , sizeof( struct V_559 ) ) ;
F_265 ( V_28 ) ;
F_62 ( V_134 , 2 , L_159 ) ;
V_4 = F_61 ( V_28 ) ;
if ( V_4 )
F_262 ( V_134 , 2 , L_158 , V_4 ) ;
if ( ! V_28 -> V_69 . V_70 ) {
V_4 = F_82 ( V_28 ) ;
if ( V_4 ) {
F_262 ( V_134 , 2 , L_160 , V_4 ) ;
goto V_556;
}
V_4 = F_42 ( V_28 ) ;
if ( V_4 )
F_262 ( V_134 , 2 , L_161 , V_4 ) ;
V_4 = F_45 ( V_28 ) ;
if ( V_4 )
F_262 ( V_134 , 2 , L_162 , V_4 ) ;
}
F_237 ( V_28 -> V_120 ) ;
V_4 = F_266 ( V_28 ) ;
if ( V_4 ) {
F_262 ( V_134 , 2 , L_163 , V_4 ) ;
V_4 = - V_390 ;
goto V_556;
}
V_28 -> V_309 = V_313 ;
F_154 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_483 )
F_267 ( V_28 -> V_120 ) ;
else
F_248 ( V_28 -> V_120 ) ;
if ( V_553 == V_560 ) {
F_156 () ;
if ( V_307 )
F_232 ( V_28 -> V_120 ) ;
else
F_268 ( V_28 -> V_120 ) ;
F_125 ( V_28 -> V_120 ) ;
F_269 ( V_28 -> V_120 ) ;
F_158 () ;
}
F_270 ( V_28 ) ;
F_271 ( & V_119 -> V_120 . V_561 , V_562 ) ;
F_272 ( & V_28 -> V_555 ) ;
F_272 ( & V_28 -> V_554 ) ;
return 0 ;
V_556:
F_153 ( V_28 , 0 ) ;
F_273 ( F_274 ( V_28 ) ) ;
F_273 ( F_275 ( V_28 ) ) ;
F_273 ( F_276 ( V_28 ) ) ;
F_277 ( F_274 ( V_28 ) ) ;
if ( V_553 == V_560 )
V_28 -> V_309 = V_560 ;
else
V_28 -> V_309 = V_315 ;
F_272 ( & V_28 -> V_555 ) ;
F_272 ( & V_28 -> V_554 ) ;
return V_4 ;
}
static int F_278 ( struct V_547 * V_119 )
{
return F_259 ( V_119 , 0 ) ;
}
static int F_279 ( struct V_547 * V_549 ,
int V_307 )
{
struct V_27 * V_28 = F_251 ( & V_549 -> V_120 ) ;
int V_4 = 0 , V_563 = 0 , V_564 = 0 ;
enum V_552 V_553 ;
F_260 ( & V_28 -> V_554 ) ;
F_260 ( & V_28 -> V_555 ) ;
F_62 ( V_134 , 3 , L_164 ) ;
F_136 ( V_134 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_120 && F_280 ( V_28 -> V_120 ) )
F_248 ( V_28 -> V_120 ) ;
V_553 = V_28 -> V_309 ;
if ( ( ! V_307 && V_28 -> V_94 . V_548 ) || V_28 -> V_94 . V_548 == 2 ) {
F_264 ( V_28 , V_565 ) ;
V_28 -> V_94 . V_548 = 1 ;
}
F_153 ( V_28 , V_307 ) ;
if ( ( V_28 -> V_69 . V_480 == V_481 ) && V_28 -> V_120 ) {
F_156 () ;
F_281 ( V_566 , V_28 -> V_120 ) ;
F_158 () ;
}
V_4 = F_273 ( F_274 ( V_28 ) ) ;
V_563 = F_273 ( F_275 ( V_28 ) ) ;
V_564 = F_273 ( F_276 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_563 ) ? V_563 : V_564 ;
if ( V_4 )
F_262 ( V_134 , 2 , L_165 , V_4 ) ;
F_277 ( F_274 ( V_28 ) ) ;
if ( V_553 == V_312 )
V_28 -> V_309 = V_560 ;
F_271 ( & V_549 -> V_120 . V_561 , V_562 ) ;
F_272 ( & V_28 -> V_555 ) ;
F_272 ( & V_28 -> V_554 ) ;
return 0 ;
}
static int F_256 ( struct V_547 * V_549 )
{
return F_279 ( V_549 , 0 ) ;
}
static int F_282 ( void * V_567 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_567 ;
F_16 ( V_28 , 2 , L_166 ) ;
F_17 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_283 ( V_28 , V_224 ) )
return 0 ;
F_16 ( V_28 , 2 , L_167 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_168 ) ;
F_284 ( V_28 ) ;
F_279 ( V_28 -> V_119 , 1 ) ;
V_4 = F_259 ( V_28 -> V_119 , 1 ) ;
if ( ! V_4 )
F_63 ( & V_28 -> V_119 -> V_120 ,
L_169 ) ;
else {
F_285 ( V_28 ) ;
F_58 ( & V_28 -> V_119 -> V_120 , L_170
L_171 ) ;
}
F_286 ( V_28 ) ;
F_287 ( V_28 , V_224 ) ;
F_288 ( V_28 , V_224 ) ;
return 0 ;
}
static void F_289 ( struct V_547 * V_119 )
{
struct V_27 * V_28 = F_251 ( & V_119 -> V_120 ) ;
F_154 ( V_28 , 0 , 1 ) ;
if ( ( V_119 -> V_309 == V_551 ) && V_28 -> V_94 . V_548 )
F_264 ( V_28 , V_565 ) ;
F_160 ( V_28 , 0 ) ;
F_161 ( V_28 ) ;
F_277 ( F_274 ( V_28 ) ) ;
}
static int F_290 ( struct V_547 * V_119 )
{
struct V_27 * V_28 = F_251 ( & V_119 -> V_120 ) ;
if ( V_28 -> V_120 )
F_291 ( V_28 -> V_120 ) ;
F_154 ( V_28 , 0 , 1 ) ;
F_255 ( V_28 -> V_550 , F_166 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_119 -> V_309 == V_568 )
return 0 ;
if ( V_28 -> V_309 == V_312 ) {
if ( V_28 -> V_94 . V_548 )
F_264 ( V_28 , V_565 ) ;
F_279 ( V_28 -> V_119 , 1 ) ;
} else
F_279 ( V_28 -> V_119 , 0 ) ;
return 0 ;
}
static int F_292 ( struct V_547 * V_119 )
{
struct V_27 * V_28 = F_251 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
if ( V_119 -> V_309 == V_568 )
goto V_14;
if ( V_28 -> V_309 == V_560 ) {
V_4 = F_259 ( V_28 -> V_119 , 1 ) ;
if ( V_4 ) {
F_156 () ;
F_157 ( V_28 -> V_120 ) ;
F_158 () ;
}
} else
V_4 = F_259 ( V_28 -> V_119 , 0 ) ;
V_14:
F_154 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_120 )
F_293 ( V_28 -> V_120 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_170
L_171 ) ;
return V_4 ;
}
static int F_294 ( struct V_27 * V_28 ,
struct V_75 * V_76 )
{
return 1 ;
}
static int F_295 ( struct V_569 * V_570 ,
unsigned long V_571 , void * V_567 )
{
struct V_214 * V_215 = (struct V_214 * ) V_567 ;
struct V_201 * V_120 = (struct V_201 * ) V_215 -> V_572 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_296 ( V_120 ) != & V_573 )
return V_574 ;
V_28 = F_152 ( V_120 ) ;
if ( ! V_28 )
return V_574 ;
F_16 ( V_28 , 3 , L_172 ) ;
V_2 = F_23 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_45 . V_2 = V_215 -> V_218 ;
V_2 -> V_36 . V_45 . V_89 = V_215 -> V_219 ;
V_2 -> type = V_49 ;
} else
return V_574 ;
switch ( V_571 ) {
case V_575 :
F_28 ( & V_28 -> V_60 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
case V_576 :
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
}
F_21 ( V_2 ) ;
return V_574 ;
}
static int F_297 ( struct V_569 * V_570 ,
unsigned long V_571 , void * V_567 )
{
struct V_220 * V_215 = (struct V_220 * ) V_567 ;
struct V_201 * V_120 = (struct V_201 * ) V_215 -> V_577 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_152 ( V_120 ) ;
if ( ! V_28 )
return V_574 ;
F_16 ( V_28 , 3 , L_173 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return V_574 ;
V_2 = F_23 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_215 -> V_2 , sizeof( struct V_82 ) ) ;
V_2 -> V_36 . V_46 . V_88 = V_215 -> V_221 ;
V_2 -> type = V_49 ;
} else
return V_574 ;
switch ( V_571 ) {
case V_575 :
F_28 ( & V_28 -> V_60 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
case V_576 :
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
}
F_21 ( V_2 ) ;
return V_574 ;
}
static int F_298 ( void )
{
int V_4 ;
F_62 ( V_134 , 5 , L_174 ) ;
V_4 = F_299 ( & V_578 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_46
V_4 = F_300 ( & V_579 ) ;
if ( V_4 ) {
F_301 ( & V_578 ) ;
return V_4 ;
}
#else
F_302 ( L_175 ) ;
#endif
return 0 ;
}
static void F_303 ( void )
{
F_62 ( V_134 , 5 , L_176 ) ;
F_304 ( F_301 ( & V_578 ) ) ;
#ifdef F_46
F_304 ( F_305 ( & V_579 ) ) ;
#endif
}
static int T_10 F_306 ( void )
{
int V_4 = 0 ;
F_242 ( L_177 ) ;
V_4 = F_298 () ;
return V_4 ;
}
static void T_11 F_307 ( void )
{
F_303 () ;
F_242 ( L_178 ) ;
}
