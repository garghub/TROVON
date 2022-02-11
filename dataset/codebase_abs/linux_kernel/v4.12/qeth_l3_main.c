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
V_68 -> V_36 . V_45 . V_2 = F_99 ( V_193 -> V_197 ) ;
memcpy ( V_68 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_188 = F_13 ( V_28 , V_68 ) ;
if ( V_188 ) {
V_188 -> V_52 = V_63 ;
} else {
V_188 = F_23 ( V_20 ) ;
if ( ! V_188 )
continue;
memcpy ( V_188 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_188 -> V_36 . V_45 . V_2 = F_99 ( V_193 -> V_197 ) ;
V_188 -> V_44 = 1 ;
V_188 -> V_52 = V_59 ;
F_24 ( V_28 -> V_198 ,
& V_188 -> V_54 , F_25 ( V_188 ) ) ;
}
}
F_21 ( V_68 ) ;
}
static void F_100 ( struct V_27 * V_28 )
{
struct V_190 * V_199 ;
T_5 V_200 ;
F_16 ( V_28 , 4 , L_94 ) ;
if ( ! F_47 ( V_28 , V_146 ) )
return;
F_101 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
V_202 = F_102 ( V_28 -> V_120 , F_103 ( V_203 ) ,
V_200 ) ;
if ( V_202 == NULL ||
! ( V_202 -> V_85 & V_204 ) )
continue;
V_199 = F_104 ( V_202 ) ;
if ( ! V_199 )
continue;
F_97 ( V_28 , V_199 ) ;
}
}
static void F_105 ( struct V_27 * V_28 )
{
struct V_190 * V_191 ;
F_16 ( V_28 , 4 , L_95 ) ;
F_106 () ;
V_191 = F_104 ( V_28 -> V_120 ) ;
if ( V_191 == NULL )
goto V_205;
F_97 ( V_28 , V_191 ) ;
F_100 ( V_28 ) ;
V_205:
F_107 () ;
}
static void
F_108 ( struct V_27 * V_28 , struct V_206 * V_207 )
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
F_109 ( & V_209 -> V_211 , V_1 , V_207 -> V_120 , 0 ) ;
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
static void F_110 ( struct V_27 * V_28 )
{
struct V_206 * V_199 ;
T_5 V_200 ;
F_16 ( V_28 , 4 , L_97 ) ;
if ( ! F_47 ( V_28 , V_146 ) )
return;
F_101 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
V_202 = F_102 ( V_28 -> V_120 , F_103 ( V_203 ) ,
V_200 ) ;
if ( V_202 == NULL ||
! ( V_202 -> V_85 & V_204 ) )
continue;
V_199 = F_111 ( V_202 ) ;
if ( ! V_199 )
continue;
F_112 ( & V_199 -> V_213 ) ;
F_108 ( V_28 , V_199 ) ;
F_113 ( & V_199 -> V_213 ) ;
F_114 ( V_199 ) ;
}
}
static void F_115 ( struct V_27 * V_28 )
{
struct V_206 * V_207 ;
F_16 ( V_28 , 4 , L_98 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return ;
V_207 = F_111 ( V_28 -> V_120 ) ;
if ( ! V_207 )
return;
F_106 () ;
F_112 ( & V_207 -> V_213 ) ;
F_108 ( V_28 , V_207 ) ;
F_110 ( V_28 ) ;
F_113 ( & V_207 -> V_213 ) ;
F_107 () ;
F_114 ( V_207 ) ;
}
static void F_116 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
struct V_190 * V_199 ;
struct V_214 * V_215 ;
struct V_29 * V_2 ;
struct V_201 * V_202 ;
F_16 ( V_28 , 4 , L_99 ) ;
V_202 = F_102 ( V_28 -> V_120 , F_103 ( V_203 ) , V_200 ) ;
if ( ! V_202 )
return;
V_199 = F_117 ( V_202 ) ;
if ( ! V_199 )
return;
V_2 = F_23 ( V_20 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_60 ) ;
for ( V_215 = V_199 -> V_216 ; V_215 ; V_215 = V_215 -> V_217 ) {
V_2 -> V_36 . V_45 . V_2 = F_99 ( V_215 -> V_218 ) ;
V_2 -> V_36 . V_45 . V_89 = F_99 ( V_215 -> V_219 ) ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_2 ) ;
F_118 ( V_199 ) ;
}
static void F_119 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
#ifdef F_46
struct V_206 * V_207 ;
struct V_220 * V_215 ;
struct V_29 * V_2 ;
struct V_201 * V_202 ;
F_16 ( V_28 , 4 , L_100 ) ;
V_202 = F_102 ( V_28 -> V_120 , F_103 ( V_203 ) , V_200 ) ;
if ( ! V_202 )
return;
V_207 = F_111 ( V_202 ) ;
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
F_114 ( V_207 ) ;
#endif
}
static void F_120 ( struct V_27 * V_28 ,
unsigned short V_200 )
{
F_106 () ;
F_116 ( V_28 , V_200 ) ;
F_119 ( V_28 , V_200 ) ;
F_107 () ;
}
static int F_121 ( struct V_201 * V_120 ,
T_6 V_19 , T_5 V_200 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_122 ( V_200 , V_28 -> V_223 ) ;
return 0 ;
}
static int F_123 ( struct V_201 * V_120 ,
T_6 V_19 , T_5 V_200 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_38 ( V_28 , 4 , L_101 , V_200 ) ;
if ( F_124 ( V_28 , V_224 ) ) {
F_16 ( V_28 , 3 , L_102 ) ;
return 0 ;
}
F_120 ( V_28 , V_200 ) ;
F_125 ( V_200 , V_28 -> V_223 ) ;
F_126 ( V_28 -> V_120 ) ;
return 0 ;
}
static inline int F_127 ( struct V_27 * V_28 ,
struct V_225 * V_226 , struct V_227 * V_161 ,
unsigned short * V_228 )
{
T_2 V_64 ;
struct V_229 * V_230 ;
unsigned char V_231 [ V_194 ] ;
int V_232 = 0 ;
if ( ! ( V_161 -> V_161 . V_233 . V_85 & V_130 ) ) {
V_64 = ( V_161 -> V_161 . V_233 . V_85 & V_131 ) ? V_234 :
V_235 ;
switch ( V_161 -> V_161 . V_233 . V_85 & V_236 ) {
case V_125 :
switch ( V_64 ) {
#ifdef F_46
case V_234 :
F_109 ( (struct V_82 * )
V_226 -> V_77 + 24 ,
V_231 , V_28 -> V_120 , 0 ) ;
break;
#endif
case V_235 :
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
V_226 -> V_253 = F_132 ( V_277 ) ;
V_226 -> V_242 = V_247 ;
V_226 -> V_278 = V_279 ;
V_226 -> V_120 = V_28 -> V_120 ;
V_23 = V_226 -> V_23 ;
V_28 -> V_120 -> V_250 -> V_251 ( V_226 , V_28 -> V_120 , 0 ,
V_28 -> V_120 -> V_163 , L_103 ,
V_28 -> V_120 -> V_239 ) ;
F_133 ( V_226 ) ;
} else {
V_232 = F_127 ( V_28 , V_226 , V_161 ,
& V_266 ) ;
V_23 = V_226 -> V_23 ;
if ( V_232 && ! V_28 -> V_69 . V_70 )
F_134 ( V_226 ,
F_103 ( V_203 ) , V_266 ) ;
F_135 ( & V_28 -> V_280 , V_226 ) ;
}
break;
case V_281 :
V_226 -> V_242 = V_247 ;
V_226 -> V_253 = F_128 ( V_226 , V_226 -> V_120 ) ;
V_23 = V_226 -> V_23 ;
F_133 ( V_226 ) ;
break;
default:
F_136 ( V_226 ) ;
F_16 ( V_28 , 3 , L_104 ) ;
F_137 ( V_282 , 3 , V_161 , V_283 ) ;
continue;
}
V_265 ++ ;
V_263 -- ;
V_28 -> V_240 . V_284 ++ ;
V_28 -> V_240 . V_285 += V_23 ;
}
return V_265 ;
}
static int F_138 ( struct V_201 * V_120 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_200 ;
F_101 (vid, card->active_vlans, VLAN_N_VID) {
struct V_201 * V_202 ;
F_106 () ;
V_202 = F_102 ( V_28 -> V_120 , F_103 ( V_203 ) ,
V_200 ) ;
F_107 () ;
if ( V_202 == V_120 ) {
V_4 = V_286 ;
break;
}
}
if ( V_4 && ! ( F_139 ( V_120 ) -> V_222 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_140 ( struct V_201 * V_120 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
unsigned long V_85 ;
F_141 ( & V_287 . V_288 , V_85 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_120 == V_120 ) {
V_4 = V_289 ;
break;
}
V_4 = F_138 ( V_120 , V_28 ) ;
if ( V_4 )
break;
}
F_142 ( & V_287 . V_288 , V_85 ) ;
return V_4 ;
}
static struct V_27 * F_143 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_140 ( V_120 ) ;
if ( V_4 == V_289 )
V_28 = V_120 -> V_222 ;
else if ( V_4 == V_286 )
V_28 = F_139 ( V_120 ) -> V_222 ;
if ( V_28 && V_28 -> V_69 . V_290 )
V_28 = NULL ;
if ( V_28 )
F_38 ( V_28 , 4 , L_105 , V_4 ) ;
return V_28 ;
}
static void F_144 ( struct V_27 * V_28 , int V_291 )
{
F_62 ( V_134 , 2 , L_106 ) ;
F_137 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
F_145 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_69 . V_70 &&
( V_28 -> V_94 . V_175 == V_178 ) )
F_90 ( V_28 , V_173 ) ;
if ( V_28 -> V_292 . V_293 == V_294 &&
V_28 -> V_295 . V_293 == V_294 &&
( V_28 -> V_293 == V_296 ) ) {
if ( V_291 )
F_146 ( V_28 -> V_120 ) ;
else {
F_147 () ;
F_148 ( V_28 -> V_120 ) ;
F_149 () ;
}
V_28 -> V_293 = V_297 ;
}
if ( V_28 -> V_293 == V_297 ) {
F_30 ( V_28 , 1 ) ;
F_150 ( V_28 ) ;
V_28 -> V_293 = V_298 ;
}
if ( V_28 -> V_293 == V_298 ) {
F_151 ( V_28 , 0 ) ;
F_152 ( V_28 ) ;
F_153 ( V_28 ) ;
V_28 -> V_293 = V_299 ;
}
if ( V_28 -> V_293 == V_299 ) {
F_154 ( & V_28 -> V_292 ) ;
F_154 ( & V_28 -> V_295 ) ;
}
}
static void
F_155 ( struct V_27 * V_28 )
{
struct V_201 * V_120 = V_28 -> V_120 ;
if ( ( ( V_120 -> V_85 & V_300 ) &&
( V_28 -> V_94 . V_175 == V_178 ) ) ||
( ! ( V_120 -> V_85 & V_300 ) &&
( V_28 -> V_94 . V_175 == V_176 ) ) )
return;
if ( V_28 -> V_94 . V_301 ) {
if ( F_66 ( V_28 , V_302 ) )
F_156 ( V_28 ) ;
} else if ( V_28 -> V_69 . V_70 &&
F_66 ( V_28 , V_303 ) ) {
if ( V_120 -> V_85 & V_300 ) {
F_16 ( V_28 , 3 , L_107 ) ;
F_90 ( V_28 , V_177 ) ;
} else {
F_16 ( V_28 , 3 , L_108 ) ;
F_90 ( V_28 , V_173 ) ;
}
}
}
static void F_126 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 3 , L_109 ) ;
if ( F_157 ( V_28 , V_224 ) &&
( V_28 -> V_293 != V_296 ) )
return;
if ( ! V_28 -> V_69 . V_70 ) {
F_28 ( & V_28 -> V_71 ) ;
F_93 ( V_28 ) ;
F_105 ( V_28 ) ;
#ifdef F_46
F_115 ( V_28 ) ;
#endif
F_96 ( V_28 ) ;
F_95 ( V_28 ) ;
F_26 ( & V_28 -> V_71 ) ;
if ( ! F_66 ( V_28 , V_302 ) )
return;
}
F_155 ( V_28 ) ;
}
static const char * F_158 ( int * V_4 )
{
switch ( * V_4 ) {
case V_304 :
* V_4 = - V_158 ;
return L_110 ;
case V_305 :
* V_4 = - V_144 ;
return L_111 ;
case V_306 :
* V_4 = - V_7 ;
return L_112 ;
case V_307 :
* V_4 = - V_144 ;
return L_113 ;
case V_308 :
* V_4 = - V_47 ;
return L_114 ;
default:
return L_115 ;
}
}
static int F_159 ( struct V_27 * V_28 , int V_309 )
{
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_116 ) ;
if ( V_28 -> V_94 . V_301 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_310 ,
V_309 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_117
L_118 , F_44 ( V_28 ) ,
F_158 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static T_7 F_160 ( struct V_27 * V_28 ,
struct V_311 * V_312 ,
struct V_313 * type , T_1 V_314 )
{
T_7 V_4 ;
T_1 V_315 ;
V_315 = V_312 -> V_316 == 5 ;
if ( type -> V_317 == V_318 ) {
F_16 ( V_28 , 4 , L_119 ) ;
if ( V_314 ) {
V_4 = V_315 ? sizeof( struct V_319 ) :
sizeof( struct V_320 ) ;
} else {
V_4 = V_315 ? sizeof( struct V_321 ) :
sizeof( struct V_322 ) ;
}
} else if ( type -> V_317 == V_323 ) {
F_16 ( V_28 , 4 , L_120 ) ;
if ( V_314 ) {
V_4 = V_315 ?
sizeof( struct V_324 ) :
sizeof( struct V_325 ) ;
} else {
V_4 = V_315 ?
sizeof( struct V_326 ) :
sizeof( struct V_327 ) ;
}
} else {
F_16 ( V_28 , 4 , L_121 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_161 ( struct V_313 * type , T_2 V_64 )
{
return ( type -> V_317 == V_318 && V_64 == V_20 ) ||
( type -> V_317 == V_323 && V_64 == V_21 ) ;
}
static int F_162 ( struct V_27 * V_28 ,
struct V_159 * V_160 , unsigned long V_77 )
{
struct V_75 * V_76 ;
struct V_311 * V_312 ;
struct V_328 * V_329 ;
int V_24 ;
int V_330 ;
int V_331 ;
int V_332 ;
T_1 V_333 ;
F_16 ( V_28 , 3 , L_122 ) ;
V_329 = (struct V_328 * ) V_160 -> V_334 ;
V_76 = (struct V_75 * ) V_77 ;
F_38 ( V_28 , 4 , L_123 , V_76 -> V_161 . V_335 ) ;
if ( V_76 -> V_161 . V_162 ) {
F_16 ( V_28 , 4 , L_124 ) ;
F_38 ( V_28 , 4 , L_123 , V_76 -> V_161 . V_162 ) ;
return 0 ;
}
if ( V_76 -> V_77 . V_336 . V_161 . V_162 ) {
V_76 -> V_161 . V_162 = V_76 -> V_77 . V_336 . V_161 . V_162 ;
F_16 ( V_28 , 4 , L_125 ) ;
F_38 ( V_28 , 4 , L_123 , V_76 -> V_161 . V_162 ) ;
return 0 ;
}
V_312 = & V_76 -> V_77 . V_336 . V_77 . V_337 ;
F_38 ( V_28 , 4 , L_126 , V_312 -> V_309 ) ;
V_333 = ( V_329 -> V_37 & V_338 ) > 0 ;
V_332 = V_333 ? V_339 : 0 ;
V_331 = 0 ;
for ( V_330 = 0 ; V_330 < V_312 -> V_309 ; ++ V_330 ) {
char * V_340 ;
T_7 V_341 ;
struct V_313 * V_342 ;
V_340 = & V_312 -> V_77 + V_331 ;
V_342 = & ( (struct V_321 * ) V_340 ) -> type ;
if ( ! F_161 ( V_342 , V_76 -> V_161 . V_335 ) ) {
F_16 ( V_28 , 4 , L_127 ) ;
F_38 ( V_28 , 4 , L_123 , V_342 -> V_317 ) ;
break;
}
V_341 = F_160 ( V_28 , V_312 , V_342 ,
V_333 ) ;
F_38 ( V_28 , 5 , L_128 , V_341 ) ;
if ( ! V_341 )
break;
if ( ( V_329 -> V_343 - V_329 -> V_344 ) < V_341 ) {
F_38 ( V_28 , 4 , L_129 , - V_55 ) ;
V_76 -> V_161 . V_162 = V_345 ;
goto V_346;
}
memcpy ( V_329 -> V_347 + V_329 -> V_344 ,
& V_312 -> V_77 + V_331 + V_332 ,
V_341 ) ;
V_331 += V_341 + V_332 ;
V_329 -> V_344 += V_341 ;
++ V_329 -> V_309 ;
}
if ( V_76 -> V_77 . V_336 . V_161 . V_348 <
V_76 -> V_77 . V_336 . V_161 . V_349 )
return 1 ;
F_38 ( V_28 , 4 , L_130 , V_329 -> V_309 ) ;
memcpy ( V_329 -> V_347 , & V_329 -> V_309 , 4 ) ;
if ( V_329 -> V_37 & V_338 )
V_312 -> V_316 |= V_338 ;
memcpy ( V_329 -> V_347 + V_350 , & V_312 -> V_316 , 2 ) ;
F_38 ( V_28 , 4 , L_131 , 0 ) ;
return 0 ;
V_346:
V_24 = 0 ;
memcpy ( V_329 -> V_347 , & V_24 , 4 ) ;
return 0 ;
}
static int F_163 ( struct V_27 * V_28 ,
struct V_73 * V_74 , int V_23 ,
int (* F_164)( struct V_27 * , struct V_159 * ,
unsigned long ) ,
void * V_351 )
{
F_16 ( V_28 , 4 , L_132 ) ;
memcpy ( V_74 -> V_77 , V_352 , V_78 ) ;
memcpy ( F_165 ( V_74 -> V_77 ) ,
& V_28 -> V_353 . V_354 , V_355 ) ;
return F_166 ( V_28 , V_78 + V_23 , V_74 ,
F_164 , V_351 ) ;
}
static int F_167 ( struct V_27 * V_28 ,
enum V_18 V_64 ,
struct V_328 * V_329 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_68 ;
int V_4 ;
F_38 ( V_28 , 3 , L_133 , V_64 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_356 ,
sizeof( struct V_311 )
- sizeof( char ) ,
V_64 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_336 . V_77 . V_337 . V_357 = 0x000F ;
V_76 -> V_77 . V_336 . V_77 . V_337 . V_316 = 0 ;
V_76 -> V_77 . V_336 . V_77 . V_337 . V_309 = 0 ;
V_4 = F_163 ( V_28 , V_74 ,
V_358 + V_359 ,
F_162 , ( void * ) V_329 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 ,
L_134
L_135 , F_44 ( V_28 ) ,
F_158 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_168 ( struct V_27 * V_28 , char T_8 * V_347 )
{
struct V_328 V_329 = { 0 , } ;
int V_4 ;
F_16 ( V_28 , 3 , L_136 ) ;
if ( ! F_47 ( V_28 ,
V_141 ) ) {
F_16 ( V_28 , 3 , L_137 ) ;
V_4 = - V_144 ;
goto V_14;
}
if ( F_169 ( & V_329 , V_347 , 6 ) ) {
V_4 = - V_360 ;
goto V_14;
}
V_329 . V_347 = F_29 ( V_329 . V_343 , V_361 ) ;
if ( ! V_329 . V_347 ) {
V_4 = - V_55 ;
goto V_14;
}
V_329 . V_344 = V_362 ;
V_4 = F_167 ( V_28 , V_20 , & V_329 ) ;
if ( V_4 ) {
if ( F_170 ( V_347 , V_329 . V_347 , 4 ) )
V_4 = - V_360 ;
goto V_363;
}
#ifdef F_46
if ( V_329 . V_37 & V_364 ) {
F_167 ( V_28 , V_21 , & V_329 ) ;
}
#endif
if ( F_170 ( V_347 , V_329 . V_347 , V_329 . V_343 ) ) {
F_16 ( V_28 , 4 , L_138 ) ;
V_4 = - V_360 ;
goto V_363;
}
F_16 ( V_28 , 4 , L_139 ) ;
V_363:
F_21 ( V_329 . V_347 ) ;
V_14:
return V_4 ;
}
static int F_171 ( struct V_27 * V_28 ,
struct V_365 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_140 ) ;
if ( V_28 -> V_94 . V_301 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_74 = F_69 ( V_28 , V_141 ,
V_366 ,
sizeof( struct V_365 ) ,
V_20 ) ;
if ( ! V_74 )
return - V_55 ;
V_4 = F_70 ( V_28 , V_74 ,
sizeof( struct V_365 ) ,
( unsigned long ) V_107 ,
V_140 , NULL ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_2 ( ( T_3 * ) V_107 -> V_111 , V_1 ) ;
F_43 ( 2 , L_141
L_142 , V_1 , F_44 ( V_28 ) ,
F_158 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_172 ( struct V_27 * V_28 ,
struct V_365 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] = { 0 , } ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_143 ) ;
if ( V_28 -> V_94 . V_301 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
memcpy ( V_1 , V_107 , 12 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_367 ,
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
F_43 ( 2 , L_144
L_145 , V_1 , F_44 ( V_28 ) ,
F_158 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_173 ( struct V_27 * V_28 )
{
int V_4 ;
int V_68 ;
F_16 ( V_28 , 3 , L_146 ) ;
if ( V_28 -> V_94 . V_301 || ( V_28 -> V_94 . type == V_95 ) )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_368 , 0 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_147
L_135 , F_44 ( V_28 ) ,
F_158 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_174 ( struct V_201 * V_120 , struct V_369 * V_370 , int V_76 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
struct V_365 V_371 ;
int V_4 = 0 ;
switch ( V_76 ) {
case V_372 :
if ( ! F_175 ( V_373 ) ) {
V_4 = - V_374 ;
break;
}
V_4 = F_159 ( V_28 , V_370 -> V_375 . V_376 ) ;
break;
case V_377 :
if ( ! F_175 ( V_373 ) ) {
V_4 = - V_374 ;
break;
}
V_4 = F_168 ( V_28 , V_370 -> V_375 . V_378 ) ;
break;
case V_379 :
if ( ! F_175 ( V_373 ) ) {
V_4 = - V_374 ;
break;
}
if ( F_169 ( & V_371 , V_370 -> V_375 . V_378 ,
sizeof( struct V_365 ) ) )
V_4 = - V_360 ;
else
V_4 = F_171 ( V_28 , & V_371 ) ;
break;
case V_380 :
if ( ! F_175 ( V_373 ) ) {
V_4 = - V_374 ;
break;
}
if ( F_169 ( & V_371 , V_370 -> V_375 . V_378 ,
sizeof( struct V_365 ) ) )
V_4 = - V_360 ;
else
V_4 = F_172 ( V_28 , & V_371 ) ;
break;
case V_381 :
if ( ! F_175 ( V_373 ) ) {
V_4 = - V_374 ;
break;
}
V_4 = F_173 ( V_28 ) ;
break;
default:
V_4 = - V_144 ;
}
return V_4 ;
}
int inline F_176 ( struct V_27 * V_28 , struct V_225 * V_226 )
{
int V_123 = V_382 ;
struct V_383 * V_384 = NULL ;
struct V_385 * V_386 ;
F_106 () ;
V_386 = F_177 ( V_226 ) ;
if ( V_386 )
V_384 = F_178 ( V_386 , V_226 ) ;
if ( V_384 ) {
V_123 = V_384 -> type ;
F_107 () ;
F_179 ( V_384 ) ;
if ( ( V_123 == V_126 ) ||
( V_123 == V_124 ) ||
( V_123 == V_132 ) )
return V_123 ;
else
return V_382 ;
}
F_107 () ;
if ( F_180 ( V_226 -> V_253 ) == V_234 )
return ( F_181 ( V_226 ) [ 24 ] == 0xff ) ?
V_124 : 0 ;
else if ( F_180 ( V_226 -> V_253 ) == V_235 )
return ( ( F_181 ( V_226 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_124 : 0 ;
if ( ! memcmp ( V_226 -> V_77 , V_226 -> V_120 -> V_238 , 6 ) )
return V_126 ;
else {
T_5 V_387 ;
V_387 = * ( ( T_5 * ) V_226 -> V_77 ) ;
switch ( V_28 -> V_94 . V_388 ) {
case V_389 :
case V_390 :
if ( ( V_387 == V_391 ) ||
( V_387 == V_392 ) )
return V_124 ;
break;
default:
if ( ( V_387 == V_393 ) ||
( V_387 == V_394 ) )
return V_124 ;
}
}
return V_123 ;
}
static void F_182 ( struct V_27 * V_28 ,
struct V_227 * V_161 , struct V_225 * V_226 )
{
char V_237 [ 16 ] ;
struct V_395 * V_396 ;
memset ( V_161 , 0 , sizeof( struct V_227 ) ) ;
V_161 -> V_161 . V_233 . V_275 = V_276 ;
V_161 -> V_161 . V_233 . V_248 = 0 ;
V_161 -> V_161 . V_233 . V_397 = V_226 -> V_23 - V_398 ;
V_161 -> V_161 . V_233 . V_85 = V_131 | V_128 ;
V_396 = (struct V_395 * ) ( V_226 -> V_77 + V_398 ) ;
memset ( V_237 , 0 , sizeof( V_237 ) ) ;
V_237 [ 0 ] = 0xfe ;
V_237 [ 1 ] = 0x80 ;
memcpy ( & V_237 [ 8 ] , V_396 -> V_399 , 8 ) ;
memcpy ( V_161 -> V_161 . V_233 . V_252 , V_237 , 16 ) ;
}
static void F_183 ( struct V_27 * V_28 , struct V_227 * V_161 ,
struct V_225 * V_226 , int V_400 , int V_123 )
{
struct V_385 * V_386 ;
memset ( V_161 , 0 , sizeof( struct V_227 ) ) ;
V_161 -> V_161 . V_233 . V_275 = V_276 ;
V_161 -> V_161 . V_233 . V_248 = 0 ;
if ( F_184 ( V_226 ) ) {
if ( ( V_400 == 4 ) || ( V_28 -> V_94 . type == V_95 ) )
V_161 -> V_161 . V_233 . V_248 = V_254 ;
else
V_161 -> V_161 . V_233 . V_248 = V_255 ;
V_161 -> V_161 . V_233 . V_228 = F_185 ( V_226 ) ;
}
V_161 -> V_161 . V_233 . V_397 = V_226 -> V_23 - sizeof( struct V_227 ) ;
F_106 () ;
V_386 = F_177 ( V_226 ) ;
if ( V_400 == 4 ) {
struct V_401 * V_402 = (struct V_401 * ) V_386 ;
T_4 * V_403 = & V_230 ( V_226 ) -> V_237 ;
if ( V_402 -> V_404 )
V_403 = & V_402 -> V_404 ;
V_161 -> V_161 . V_233 . V_85 = F_59 ( V_123 ) ;
memset ( V_161 -> V_161 . V_233 . V_252 , 0 , 12 ) ;
* ( ( T_4 * ) ( & V_161 -> V_161 . V_233 . V_252 [ 12 ] ) ) = * V_403 ;
} else if ( V_400 == 6 ) {
struct V_405 * V_402 = (struct V_405 * ) V_386 ;
struct V_82 * V_403 = & F_186 ( V_226 ) -> V_237 ;
if ( ! F_187 ( & V_402 -> V_406 ) )
V_403 = & V_402 -> V_406 ;
V_161 -> V_161 . V_233 . V_85 = F_60 ( V_123 ) ;
if ( V_28 -> V_94 . type == V_95 )
V_161 -> V_161 . V_233 . V_85 &= ~ V_130 ;
memcpy ( V_161 -> V_161 . V_233 . V_252 , V_403 , 16 ) ;
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
F_107 () ;
}
static inline void F_188 ( struct V_27 * V_28 ,
struct V_227 * V_161 , struct V_225 * V_226 )
{
struct V_229 * V_407 = V_230 ( V_226 ) ;
if ( V_407 -> V_253 == V_408 )
V_161 -> V_161 . V_233 . V_248 |= V_409 ;
V_161 -> V_161 . V_233 . V_248 |= V_259 |
V_258 ;
V_407 -> V_410 = 0 ;
if ( V_28 -> V_69 . V_411 )
V_28 -> V_412 . V_413 ++ ;
}
static void F_189 ( struct V_27 * V_28 ,
struct V_227 * V_414 , struct V_225 * V_226 )
{
struct V_415 * V_161 = (struct V_415 * ) V_414 ;
struct V_416 * V_417 = F_190 ( V_226 ) ;
struct V_229 * V_407 = V_230 ( V_226 ) ;
struct V_418 * V_419 = F_186 ( V_226 ) ;
V_161 -> V_161 . V_161 . V_233 . V_275 = V_420 ;
V_161 -> V_161 . V_161 . V_233 . V_397 = V_226 -> V_23 - sizeof( struct V_415 ) ;
V_161 -> V_421 . V_422 = ( T_2 ) sizeof( struct V_423 ) ;
V_161 -> V_421 . V_424 = 1 ;
V_161 -> V_421 . V_425 = 1 ;
V_161 -> V_421 . V_426 = 1 ;
V_161 -> V_421 . V_427 = 28 ;
V_161 -> V_421 . V_428 = F_191 ( V_226 ) -> V_429 ;
V_161 -> V_421 . V_430 = ( T_2 ) ( V_407 -> V_431 * 4 + V_417 -> V_432 * 4 ) ;
V_161 -> V_421 . V_433 = ( T_2 ) ( V_226 -> V_23 - V_161 -> V_421 . V_430 -
sizeof( struct V_415 ) ) ;
V_417 -> V_410 = 0 ;
if ( F_180 ( V_226 -> V_253 ) == V_234 ) {
V_419 -> V_433 = 0 ;
V_417 -> V_410 = ~ F_192 ( & V_419 -> V_434 , & V_419 -> V_237 ,
0 , V_435 , 0 ) ;
} else {
V_417 -> V_410 = ~ F_193 ( V_407 -> V_434 , V_407 -> V_237 ,
0 , V_435 , 0 ) ;
V_407 -> V_436 = 0 ;
V_407 -> V_410 = 0 ;
}
}
static int F_194 ( struct V_27 * V_28 ,
struct V_225 * V_226 , int V_437 )
{
T_9 V_438 = ( T_9 ) F_190 ( V_226 ) + F_195 ( V_226 ) ;
int V_439 = F_196 (
V_438 ,
( T_9 ) V_226 -> V_77 + F_197 ( V_226 ) ) +
F_198 ( V_226 ) ;
if ( ( V_439 + V_437 ) > F_199 ( V_28 ) ) {
F_43 ( 2 ,
L_148 ,
V_439 + V_437 , V_226 -> V_23 ) ;
return 0 ;
}
return V_439 ;
}
static T_10 F_200 ( struct V_225 * V_226 ,
struct V_201 * V_120 )
{
int V_4 ;
T_6 * V_440 ;
struct V_227 * V_161 = NULL ;
int V_441 = 0 ;
int V_439 ;
struct V_27 * V_28 = V_120 -> V_222 ;
struct V_225 * V_442 = NULL ;
int V_400 = F_201 ( V_226 ) ;
int V_123 = F_176 ( V_28 , V_226 ) ;
struct V_443 * V_444 =
V_28 -> V_268 . V_445 [ V_28 -> V_268 . V_446
|| ( V_123 && V_28 -> V_94 . V_447 ) ?
F_202 ( V_28 , V_226 , V_400 , V_123 ) :
V_28 -> V_268 . V_448 ] ;
int V_449 = V_226 -> V_23 ;
bool V_450 ;
int V_451 = - 1 ;
int V_452 ;
if ( ( ( V_28 -> V_94 . type == V_95 ) &&
( ( ( V_28 -> V_69 . V_453 != V_454 ) && ! V_400 ) ||
( ( V_28 -> V_69 . V_453 == V_454 ) &&
( F_180 ( V_226 -> V_253 ) != V_277 ) ) ) ) ||
V_28 -> V_69 . V_70 )
goto V_455;
if ( ( V_28 -> V_293 != V_296 ) || ! V_28 -> V_456 ) {
V_28 -> V_240 . V_457 ++ ;
goto V_455;
}
if ( ( V_123 == V_126 ) &&
( V_28 -> V_94 . V_151 == 0 ) )
goto V_455;
if ( V_28 -> V_69 . V_411 ) {
V_28 -> V_412 . V_458 ++ ;
V_28 -> V_412 . V_459 = F_203 () ;
}
V_450 = F_204 ( V_226 ) &&
( F_205 ( V_226 ) == V_435 ) && ( V_400 == 4 ) ;
if ( ( V_28 -> V_94 . type == V_95 ) &&
! F_206 ( V_226 ) ) {
V_442 = V_226 ;
V_451 = V_398 ;
V_161 = F_207 ( V_460 , V_65 ) ;
if ( ! V_161 )
goto V_455;
V_441 ++ ;
} else {
V_442 = F_208 ( V_226 , sizeof( struct V_415 )
+ V_461 ) ;
if ( ! V_442 )
goto V_455;
}
if ( V_28 -> V_94 . type == V_95 ) {
if ( V_451 < 0 )
F_209 ( V_442 , V_398 ) ;
} else {
if ( V_400 == 4 ) {
F_209 ( V_442 , V_398 ) ;
}
if ( V_400 != 4 && F_184 ( V_442 ) ) {
F_210 ( V_442 , V_461 ) ;
F_211 ( V_442 , V_442 -> V_77 + 4 , 4 ) ;
F_212 ( V_442 , 4 ,
V_442 -> V_77 + 8 , 4 ) ;
F_212 ( V_442 , 8 ,
V_442 -> V_77 + 12 , 4 ) ;
V_440 = ( T_6 * ) ( V_442 -> V_77 + 12 ) ;
* V_440 = F_132 ( V_203 ) ;
* ( V_440 + 1 ) = F_132 ( F_185 ( V_442 ) ) ;
}
}
F_213 ( V_120 ) ;
if ( ( V_28 -> V_94 . type != V_95 ) &&
( ( V_450 && ! F_194 ( V_28 , V_442 , 1 ) ) ||
( ! V_450 && ! F_214 ( V_28 , V_442 , 0 , 0 ) ) ) ) {
int V_462 = F_215 ( V_442 ) ;
if ( V_28 -> V_69 . V_411 ) {
if ( V_462 )
V_28 -> V_412 . V_463 ++ ;
else
V_28 -> V_412 . V_464 ++ ;
}
if ( V_462 )
goto V_455;
}
if ( V_450 ) {
V_161 = (struct V_227 * ) F_210 ( V_442 ,
sizeof( struct V_415 ) ) ;
memset ( V_161 , 0 , sizeof( struct V_415 ) ) ;
F_183 ( V_28 , V_161 , V_442 , V_400 , V_123 ) ;
F_189 ( V_28 , V_161 , V_442 ) ;
V_441 ++ ;
} else {
if ( V_451 < 0 ) {
V_161 = (struct V_227 * ) F_210 ( V_442 ,
sizeof( struct V_227 ) ) ;
F_183 ( V_28 , V_161 , V_442 , V_400 ,
V_123 ) ;
} else {
if ( F_180 ( V_442 -> V_253 ) == V_277 )
F_182 ( V_28 , V_161 , V_442 ) ;
else {
F_183 ( V_28 , V_161 , V_442 , V_400 ,
V_123 ) ;
V_161 -> V_161 . V_233 . V_397 = V_442 -> V_23 - V_451 ;
}
}
if ( V_226 -> V_260 == V_465 )
F_188 ( V_28 , V_161 , V_442 ) ;
}
V_439 = V_450 ?
F_194 ( V_28 , V_442 , V_441 ) :
F_214 ( V_28 , V_442 , V_441 ,
( V_451 > 0 ) ? V_451 : 0 ) ;
if ( ! V_439 ) {
if ( V_451 >= 0 )
F_216 ( V_460 , V_161 ) ;
goto V_455;
}
V_439 += V_441 ;
if ( V_28 -> V_94 . type != V_95 ) {
int V_23 ;
if ( V_450 )
V_23 = ( ( unsigned long ) F_190 ( V_442 ) +
F_195 ( V_442 ) ) -
( unsigned long ) V_442 -> V_77 ;
else
V_23 = sizeof( struct V_466 ) ;
if ( F_217 ( V_442 , & V_161 , V_23 ) )
goto V_455;
V_4 = F_218 ( V_28 , V_444 , V_442 , V_161 , V_439 ) ;
} else
V_4 = F_219 ( V_28 , V_444 , V_442 , V_161 ,
V_451 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_240 . V_467 ++ ;
V_28 -> V_240 . V_449 += V_449 ;
if ( V_442 != V_226 )
F_136 ( V_226 ) ;
if ( V_28 -> V_69 . V_411 ) {
V_452 = F_191 ( V_442 ) -> V_452 ;
if ( V_450 ) {
V_28 -> V_412 . V_468 += V_449 ;
V_28 -> V_412 . V_469 ++ ;
}
if ( V_452 ) {
V_28 -> V_412 . V_470 ++ ;
V_28 -> V_412 . V_471 += V_452 + 1 ;
}
}
V_4 = V_472 ;
} else {
if ( V_451 >= 0 )
F_216 ( V_460 , V_161 ) ;
if ( V_4 == - V_473 ) {
if ( V_442 != V_226 )
F_136 ( V_442 ) ;
return V_474 ;
} else
goto V_455;
}
F_220 ( V_120 ) ;
if ( V_28 -> V_69 . V_411 )
V_28 -> V_412 . V_475 += F_203 () -
V_28 -> V_412 . V_459 ;
return V_4 ;
V_455:
V_28 -> V_240 . V_476 ++ ;
V_28 -> V_240 . V_477 ++ ;
if ( ( V_442 != V_226 ) && V_442 )
F_136 ( V_442 ) ;
F_136 ( V_226 ) ;
F_220 ( V_120 ) ;
return V_472 ;
}
static int F_221 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
int V_4 = 0 ;
F_16 ( V_28 , 4 , L_149 ) ;
if ( V_28 -> V_293 == V_296 )
return V_4 ;
if ( V_28 -> V_293 != V_297 )
return - V_478 ;
V_28 -> V_77 . V_293 = V_294 ;
V_28 -> V_293 = V_296 ;
F_222 ( V_120 ) ;
if ( F_223 ( V_28 -> V_77 . V_479 , 0 ) >= 0 ) {
F_224 ( & V_28 -> V_280 ) ;
F_225 ( & V_28 -> V_280 ) ;
} else
V_4 = - V_158 ;
return V_4 ;
}
static int F_226 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 5 , L_150 ) ;
if ( F_124 ( V_28 , V_224 ) ) {
F_16 ( V_28 , 3 , L_151 ) ;
return - V_480 ;
}
return F_221 ( V_120 ) ;
}
static int F_146 ( struct V_201 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_222 ;
F_16 ( V_28 , 4 , L_152 ) ;
F_227 ( V_120 ) ;
if ( V_28 -> V_293 == V_296 ) {
V_28 -> V_293 = V_297 ;
F_228 ( & V_28 -> V_280 ) ;
}
return 0 ;
}
static int F_229 ( struct V_383 * V_384 )
{
V_384 -> V_481 = V_482 ;
memcpy ( V_384 -> V_483 , L_103 , 6 ) ;
V_384 -> V_484 = V_384 -> V_485 -> V_486 ;
return 0 ;
}
static int
F_230 ( struct V_201 * V_120 , struct V_487 * V_488 )
{
if ( V_488 -> V_489 -> V_490 == V_491 )
V_488 -> V_492 = F_229 ;
return 0 ;
}
static int F_231 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_94 . type == V_493 ||
V_28 -> V_94 . type == V_494 ) {
if ( ( V_28 -> V_94 . V_388 == V_390 ) ||
( V_28 -> V_94 . V_388 == V_389 ) ) {
F_232 ( L_153 ) ;
return - V_478 ;
} else {
V_28 -> V_120 = F_233 ( 0 ) ;
if ( ! V_28 -> V_120 )
return - V_478 ;
V_28 -> V_120 -> V_495 = & V_496 ;
F_88 ( V_28 ) ;
if ( ! ( V_28 -> V_94 . V_165 & V_169 ) )
V_28 -> V_120 -> V_497 = V_28 -> V_94 . V_165 &
0xffff ;
if ( ! V_28 -> V_94 . V_301 ) {
V_28 -> V_120 -> V_498 = V_499 |
V_257 | V_500 |
V_501 ;
V_28 -> V_120 -> V_502 = V_499 |
V_257 | V_500 |
V_501 ;
}
}
} else if ( V_28 -> V_94 . type == V_95 ) {
V_28 -> V_120 = F_234 ( 0 , L_154 , V_503 ,
V_504 ) ;
if ( ! V_28 -> V_120 )
return - V_478 ;
V_28 -> V_120 -> V_85 |= V_505 ;
V_28 -> V_120 -> V_495 = & V_506 ;
V_4 = F_86 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_69 . V_507 [ 0 ] )
memcpy ( V_28 -> V_120 -> V_508 , V_28 -> V_69 . V_507 , 9 ) ;
} else
return - V_478 ;
V_28 -> V_120 -> V_222 = V_28 ;
V_28 -> V_120 -> V_509 = V_510 ;
V_28 -> V_120 -> V_511 = V_28 -> V_94 . V_512 ;
V_28 -> V_120 -> V_513 = 64 ;
V_28 -> V_120 -> V_514 = V_515 ;
V_28 -> V_120 -> V_516 = & V_517 ;
V_28 -> V_120 -> V_256 |= V_518 |
V_519 |
V_520 ;
F_235 ( V_28 -> V_120 ) ;
V_28 -> V_120 -> V_521 = ( F_199 ( V_28 ) - 1 ) *
V_522 ;
F_236 ( V_28 -> V_120 , & V_28 -> V_119 -> V_120 ) ;
F_237 ( V_28 -> V_120 , & V_28 -> V_280 , V_523 , V_524 ) ;
F_238 ( V_28 -> V_120 ) ;
return F_239 ( V_28 -> V_120 ) ;
}
static int F_240 ( struct V_525 * V_119 )
{
struct V_27 * V_28 = F_241 ( & V_119 -> V_120 ) ;
int V_4 ;
V_4 = F_242 ( & V_119 -> V_120 ) ;
if ( V_4 )
return V_4 ;
F_243 ( V_28 -> V_58 ) ;
F_243 ( V_28 -> V_198 ) ;
V_28 -> V_69 . V_290 = 0 ;
V_28 -> V_94 . V_526 = 0 ;
return 0 ;
}
static void F_244 ( struct V_525 * V_527 )
{
struct V_27 * V_28 = F_241 ( & V_527 -> V_120 ) ;
F_245 ( & V_527 -> V_120 ) ;
F_145 ( V_28 , 0 , 1 ) ;
F_246 ( V_28 -> V_528 , F_157 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_527 -> V_293 == V_529 )
F_247 ( V_527 ) ;
if ( V_28 -> V_120 ) {
F_248 ( & V_28 -> V_280 ) ;
F_249 ( V_28 -> V_120 ) ;
V_28 -> V_120 = NULL ;
}
F_30 ( V_28 , 0 ) ;
F_48 ( V_28 ) ;
return;
}
static int F_250 ( struct V_525 * V_119 , int V_291 )
{
struct V_27 * V_28 = F_241 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
enum V_530 V_531 ;
F_251 ( & V_28 -> V_532 ) ;
F_251 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 2 , L_155 ) ;
F_137 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
V_531 = V_28 -> V_293 ;
V_4 = F_252 ( V_28 ) ;
if ( V_4 ) {
F_253 ( V_134 , 2 , L_156 , V_4 ) ;
V_4 = - V_478 ;
goto V_534;
}
if ( ! V_28 -> V_120 && F_231 ( V_28 ) ) {
V_4 = - V_478 ;
goto V_534;
}
if ( F_254 ( V_28 , V_535 ) ) {
if ( V_28 -> V_94 . V_526 &&
F_255 ( V_28 , V_536 ) )
V_28 -> V_94 . V_526 = 0 ;
} else
V_28 -> V_94 . V_526 = 0 ;
V_28 -> V_293 = V_298 ;
memset ( & V_28 -> V_271 , 0 , sizeof( struct V_537 ) ) ;
F_256 ( V_28 ) ;
F_62 ( V_134 , 2 , L_157 ) ;
V_4 = F_61 ( V_28 ) ;
if ( V_4 )
F_253 ( V_134 , 2 , L_156 , V_4 ) ;
if ( ! V_28 -> V_69 . V_70 ) {
V_4 = F_82 ( V_28 ) ;
if ( V_4 ) {
F_253 ( V_134 , 2 , L_158 , V_4 ) ;
goto V_534;
}
V_4 = F_42 ( V_28 ) ;
if ( V_4 )
F_253 ( V_134 , 2 , L_159 , V_4 ) ;
V_4 = F_45 ( V_28 ) ;
if ( V_4 )
F_253 ( V_134 , 2 , L_160 , V_4 ) ;
}
F_227 ( V_28 -> V_120 ) ;
V_4 = F_257 ( V_28 ) ;
if ( V_4 ) {
F_253 ( V_134 , 2 , L_161 , V_4 ) ;
V_4 = - V_478 ;
goto V_534;
}
V_28 -> V_293 = V_297 ;
F_145 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_456 )
F_258 ( V_28 -> V_120 ) ;
else
F_238 ( V_28 -> V_120 ) ;
if ( V_531 == V_538 ) {
F_147 () ;
if ( V_291 )
F_221 ( V_28 -> V_120 ) ;
else
F_259 ( V_28 -> V_120 ) ;
F_126 ( V_28 -> V_120 ) ;
F_260 ( V_28 -> V_120 ) ;
F_149 () ;
}
F_261 ( V_28 ) ;
F_262 ( & V_119 -> V_120 . V_539 , V_540 ) ;
F_263 ( & V_28 -> V_533 ) ;
F_263 ( & V_28 -> V_532 ) ;
return 0 ;
V_534:
F_144 ( V_28 , 0 ) ;
F_264 ( F_265 ( V_28 ) ) ;
F_264 ( F_266 ( V_28 ) ) ;
F_264 ( F_267 ( V_28 ) ) ;
F_268 ( F_265 ( V_28 ) ) ;
if ( V_531 == V_538 )
V_28 -> V_293 = V_538 ;
else
V_28 -> V_293 = V_299 ;
F_263 ( & V_28 -> V_533 ) ;
F_263 ( & V_28 -> V_532 ) ;
return V_4 ;
}
static int F_269 ( struct V_525 * V_119 )
{
return F_250 ( V_119 , 0 ) ;
}
static int F_270 ( struct V_525 * V_527 ,
int V_291 )
{
struct V_27 * V_28 = F_241 ( & V_527 -> V_120 ) ;
int V_4 = 0 , V_541 = 0 , V_542 = 0 ;
enum V_530 V_531 ;
F_251 ( & V_28 -> V_532 ) ;
F_251 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 3 , L_162 ) ;
F_137 ( V_134 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_120 && F_271 ( V_28 -> V_120 ) )
F_238 ( V_28 -> V_120 ) ;
V_531 = V_28 -> V_293 ;
if ( ( ! V_291 && V_28 -> V_94 . V_526 ) || V_28 -> V_94 . V_526 == 2 ) {
F_255 ( V_28 , V_543 ) ;
V_28 -> V_94 . V_526 = 1 ;
}
F_144 ( V_28 , V_291 ) ;
if ( ( V_28 -> V_69 . V_453 == V_454 ) && V_28 -> V_120 ) {
F_147 () ;
F_272 ( V_544 , V_28 -> V_120 ) ;
F_149 () ;
}
V_4 = F_264 ( F_265 ( V_28 ) ) ;
V_541 = F_264 ( F_266 ( V_28 ) ) ;
V_542 = F_264 ( F_267 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_541 ) ? V_541 : V_542 ;
if ( V_4 )
F_253 ( V_134 , 2 , L_163 , V_4 ) ;
F_268 ( F_265 ( V_28 ) ) ;
if ( V_531 == V_296 )
V_28 -> V_293 = V_538 ;
F_262 ( & V_527 -> V_120 . V_539 , V_540 ) ;
F_263 ( & V_28 -> V_533 ) ;
F_263 ( & V_28 -> V_532 ) ;
return 0 ;
}
static int F_247 ( struct V_525 * V_527 )
{
return F_270 ( V_527 , 0 ) ;
}
static int F_273 ( void * V_545 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_545 ;
F_16 ( V_28 , 2 , L_164 ) ;
F_17 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_274 ( V_28 , V_224 ) )
return 0 ;
F_16 ( V_28 , 2 , L_165 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_166 ) ;
F_275 ( V_28 ) ;
F_270 ( V_28 -> V_119 , 1 ) ;
V_4 = F_250 ( V_28 -> V_119 , 1 ) ;
if ( ! V_4 )
F_63 ( & V_28 -> V_119 -> V_120 ,
L_167 ) ;
else {
F_276 ( V_28 ) ;
F_58 ( & V_28 -> V_119 -> V_120 , L_168
L_169 ) ;
}
F_277 ( V_28 ) ;
F_278 ( V_28 , V_224 ) ;
F_279 ( V_28 , V_224 ) ;
return 0 ;
}
static int F_280 ( struct V_525 * V_119 )
{
struct V_27 * V_28 = F_241 ( & V_119 -> V_120 ) ;
if ( V_28 -> V_120 )
F_281 ( V_28 -> V_120 ) ;
F_145 ( V_28 , 0 , 1 ) ;
F_246 ( V_28 -> V_528 , F_157 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_119 -> V_293 == V_546 )
return 0 ;
if ( V_28 -> V_293 == V_296 ) {
if ( V_28 -> V_94 . V_526 )
F_255 ( V_28 , V_543 ) ;
F_270 ( V_28 -> V_119 , 1 ) ;
} else
F_270 ( V_28 -> V_119 , 0 ) ;
return 0 ;
}
static int F_282 ( struct V_525 * V_119 )
{
struct V_27 * V_28 = F_241 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
if ( V_119 -> V_293 == V_546 )
goto V_14;
if ( V_28 -> V_293 == V_538 ) {
V_4 = F_250 ( V_28 -> V_119 , 1 ) ;
if ( V_4 ) {
F_147 () ;
F_148 ( V_28 -> V_120 ) ;
F_149 () ;
}
} else
V_4 = F_250 ( V_28 -> V_119 , 0 ) ;
V_14:
F_145 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_120 )
F_283 ( V_28 -> V_120 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_168
L_169 ) ;
return V_4 ;
}
static int F_284 ( struct V_27 * V_28 ,
struct V_75 * V_76 )
{
return 1 ;
}
static int F_285 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_214 * V_215 = (struct V_214 * ) V_545 ;
struct V_201 * V_120 = (struct V_201 * ) V_215 -> V_550 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_286 ( V_120 ) != & V_551 )
return V_552 ;
V_28 = F_143 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_170 ) ;
V_2 = F_23 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_45 . V_2 = F_99 ( V_215 -> V_218 ) ;
V_2 -> V_36 . V_45 . V_89 = F_99 ( V_215 -> V_219 ) ;
V_2 -> type = V_49 ;
} else
return V_552 ;
switch ( V_549 ) {
case V_553 :
F_28 ( & V_28 -> V_60 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
case V_554 :
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
}
F_21 ( V_2 ) ;
return V_552 ;
}
static int F_287 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_220 * V_215 = (struct V_220 * ) V_545 ;
struct V_201 * V_120 = (struct V_201 * ) V_215 -> V_555 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_143 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_171 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return V_552 ;
V_2 = F_23 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_215 -> V_2 , sizeof( struct V_82 ) ) ;
V_2 -> V_36 . V_46 . V_88 = V_215 -> V_221 ;
V_2 -> type = V_49 ;
} else
return V_552 ;
switch ( V_549 ) {
case V_553 :
F_28 ( & V_28 -> V_60 ) ;
F_22 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
case V_554 :
F_28 ( & V_28 -> V_60 ) ;
F_15 ( V_28 , V_2 ) ;
F_26 ( & V_28 -> V_60 ) ;
break;
}
F_21 ( V_2 ) ;
return V_552 ;
}
static int F_288 ( void )
{
int V_4 ;
F_62 ( V_134 , 5 , L_172 ) ;
V_4 = F_289 ( & V_556 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_46
V_4 = F_290 ( & V_557 ) ;
if ( V_4 ) {
F_291 ( & V_556 ) ;
return V_4 ;
}
#else
F_292 ( L_173 ) ;
#endif
return 0 ;
}
static void F_293 ( void )
{
F_62 ( V_134 , 5 , L_174 ) ;
F_294 ( F_291 ( & V_556 ) ) ;
#ifdef F_46
F_294 ( F_295 ( & V_557 ) ) ;
#endif
}
static int T_11 F_296 ( void )
{
int V_4 = 0 ;
F_232 ( L_175 ) ;
V_4 = F_288 () ;
return V_4 ;
}
static void T_12 F_297 ( void )
{
F_293 () ;
F_232 ( L_176 ) ;
}
