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
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 ,
L_48 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
static int F_74 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_49 ) ;
if ( ! F_47 ( V_28 , V_145 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_50 , F_44 ( V_28 ) ) ;
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_146 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_51 ,
F_44 ( V_28 ) ) ;
} else {
F_63 ( & V_28 -> V_119 -> V_120 , L_52 ) ;
}
return V_4 ;
}
static int F_75 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_53 ) ;
if ( ! F_47 ( V_28 , V_147 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_54 ,
F_44 ( V_28 ) ) ;
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
V_28 -> V_120 -> V_85 |= V_148 ;
}
return V_4 ;
}
static int F_76 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_57 ) ;
V_4 = F_77 ( V_28 , V_21 ) ;
if ( V_4 ) {
F_78 ( & V_28 -> V_119 -> V_120 ,
L_58 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
if ( V_28 -> V_94 . type == V_95 )
goto V_14;
V_4 = F_72 ( V_28 , V_105 ,
V_142 , 3 ) ;
if ( V_4 ) {
F_78 ( & V_28 -> V_119 -> V_120 ,
L_58 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_68 ( V_28 , V_105 ,
V_142 ) ;
if ( V_4 ) {
F_78 ( & V_28 -> V_119 -> V_120 ,
L_58 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_4 = F_68 ( V_28 , V_149 ,
V_142 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_59 ,
F_44 ( V_28 ) ) ;
return V_4 ;
}
V_14:
F_63 ( & V_28 -> V_119 -> V_120 , L_60 ) ;
return 0 ;
}
static int F_79 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
F_16 ( V_28 , 3 , L_61 ) ;
if ( ! F_47 ( V_28 , V_105 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_62 , F_44 ( V_28 ) ) ;
return 0 ;
}
#ifdef F_46
V_4 = F_76 ( V_28 ) ;
#endif
return V_4 ;
}
static int F_80 ( struct V_27 * V_28 )
{
int V_4 ;
F_16 ( V_28 , 3 , L_63 ) ;
V_28 -> V_94 . V_150 = 0 ;
if ( ! F_47 ( V_28 , V_151 ) ) {
F_63 ( & V_28 -> V_119 -> V_120 ,
L_64 ,
F_44 ( V_28 ) ) ;
V_4 = - V_144 ;
goto V_14;
}
V_4 = F_72 ( V_28 , V_151 ,
V_142 , 0 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_65
L_66 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_4 = F_72 ( V_28 , V_151 ,
V_152 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 ,
L_67 ,
F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_94 . V_150 = V_153 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_68 ) ;
V_4 = F_72 ( V_28 , V_151 ,
V_154 , 1 ) ;
if ( V_4 ) {
F_58 ( & V_28 -> V_119 -> V_120 , L_69
L_70 , F_44 ( V_28 ) ) ;
goto V_14;
}
V_28 -> V_94 . V_150 = V_155 ;
V_14:
if ( V_28 -> V_94 . V_150 )
V_28 -> V_120 -> V_85 |= V_156 ;
else
V_28 -> V_120 -> V_85 &= ~ V_156 ;
return V_4 ;
}
static int F_81 ( struct V_27 * V_28 )
{
F_16 ( V_28 , 3 , L_71 ) ;
if ( F_82 ( V_28 , 0 ) )
return - V_157 ;
F_71 ( V_28 ) ;
F_73 ( V_28 ) ;
F_74 ( V_28 ) ;
F_75 ( V_28 ) ;
F_79 ( V_28 ) ;
F_80 ( V_28 ) ;
return 0 ;
}
static int F_83 ( struct V_27 * V_28 ,
struct V_158 * V_159 , unsigned long V_77 )
{
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) V_77 ;
if ( V_76 -> V_160 . V_161 == 0 )
memcpy ( V_28 -> V_120 -> V_162 ,
V_76 -> V_77 . V_163 . V_164 , V_165 ) ;
else
F_84 ( V_28 -> V_120 -> V_162 ) ;
return 0 ;
}
static int F_85 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_72 ) ;
V_74 = F_34 ( V_28 , V_166 ,
V_21 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
* ( ( T_2 * ) & V_76 -> V_77 . V_163 . V_164 [ 6 ] ) =
V_28 -> V_94 . V_164 ;
V_4 = F_35 ( V_28 , V_74 , F_83 ,
NULL ) ;
return V_4 ;
}
static int F_86 ( struct V_27 * V_28 ,
struct V_158 * V_159 , unsigned long V_77 )
{
struct V_75 * V_76 ;
V_76 = (struct V_75 * ) V_77 ;
if ( V_76 -> V_160 . V_161 == 0 )
V_28 -> V_94 . V_164 = * ( ( T_2 * )
& V_76 -> V_77 . V_163 . V_164 [ 6 ] ) ;
else {
V_28 -> V_94 . V_164 = V_167 |
V_168 ;
F_58 ( & V_28 -> V_119 -> V_120 , L_73
L_74 ) ;
}
return 0 ;
}
static int F_87 ( struct V_27 * V_28 )
{
int V_4 = 0 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_75 ) ;
if ( ! F_47 ( V_28 , V_105 ) ) {
V_28 -> V_94 . V_164 = V_167 |
V_168 ;
return 0 ;
}
V_74 = F_34 ( V_28 , V_166 ,
V_21 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
* ( ( T_2 * ) & V_76 -> V_77 . V_163 . V_164 [ 6 ] ) =
V_28 -> V_94 . V_164 ;
V_4 = F_35 ( V_28 , V_74 , F_86 , NULL ) ;
return V_4 ;
}
static int
F_88 ( struct V_27 * V_28 , struct V_158 * V_159 ,
unsigned long V_77 )
{
struct V_75 * V_76 ;
T_2 V_4 ;
F_62 ( V_134 , 2 , L_76 ) ;
V_76 = (struct V_75 * ) V_77 ;
V_4 = V_76 -> V_160 . V_161 ;
if ( V_4 )
F_38 ( V_28 , 2 , L_77 , V_4 ) ;
switch ( V_76 -> V_77 . V_169 . V_170 ) {
case V_171 :
break;
case V_172 :
switch ( V_4 ) {
case 0 :
case V_173 :
V_28 -> V_94 . V_174 = V_175 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_78
L_79 ) ;
break;
default:
break;
}
break;
case V_176 :
switch ( V_4 ) {
case 0 :
V_28 -> V_94 . V_174 = V_177 ;
F_63 ( & V_28 -> V_119 -> V_120 , L_78
L_80 ) ;
break;
case V_178 :
F_58 ( & V_28 -> V_119 -> V_120 , L_81
L_82
L_83 ) ;
break;
case V_179 :
F_58 ( & V_28 -> V_119 -> V_120 , L_84
L_85
L_86 ) ;
break;
default:
break;
}
break;
default:
F_43 ( 2 , L_87 ,
V_76 -> V_77 . V_169 . V_170 , F_44 ( V_28 ) ) ;
}
return 0 ;
}
static int
F_89 ( struct V_27 * V_28 , enum V_180 V_181 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_62 ( V_134 , 2 , L_88 ) ;
V_74 = F_34 ( V_28 , V_182 , 0 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_169 . V_183 = 16 ;
V_76 -> V_77 . V_169 . V_184 = V_185 ;
V_76 -> V_77 . V_169 . type = V_186 ;
V_76 -> V_77 . V_169 . V_170 = V_181 ;
return F_35 ( V_28 , V_74 , F_88 , NULL ) ;
}
static void F_90 ( T_4 V_187 , char * V_42 )
{
F_91 ( V_187 , V_42 ) ;
}
static void F_92 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
int V_24 ;
F_93 (card->ip_mc_htable, i, addr, hnode)
V_2 -> V_52 = V_53 ;
}
static void F_94 ( struct V_27 * V_28 )
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
static void F_95 ( struct V_27 * V_28 )
{
struct V_29 * V_2 ;
struct V_67 * V_68 ;
int V_24 ;
int V_4 ;
F_31 (card->ip_mc_htable, i, tmp, addr, hnode) {
if ( V_2 -> V_52 == V_53 ) {
V_4 = F_19 ( V_28 , V_2 ) ;
if ( ! V_4 || ( V_4 == V_188 ) ) {
F_20 ( & V_2 -> V_54 ) ;
F_21 ( V_2 ) ;
}
}
}
}
static void
F_96 ( struct V_27 * V_28 , struct V_189 * V_190 )
{
struct V_191 * V_192 ;
struct V_29 * V_68 , * V_187 ;
char V_1 [ V_193 ] ;
F_16 ( V_28 , 4 , L_89 ) ;
V_68 = F_23 ( V_20 ) ;
if ( ! V_68 )
return;
for ( V_192 = F_97 ( V_190 -> V_194 ) ; V_192 != NULL ;
V_192 = F_97 ( V_192 -> V_195 ) ) {
F_90 ( V_192 -> V_196 , V_1 ) ;
V_68 -> V_36 . V_45 . V_2 = F_98 ( V_192 -> V_196 ) ;
memcpy ( V_68 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_187 = F_13 ( V_28 , V_68 ) ;
if ( V_187 ) {
V_187 -> V_52 = V_63 ;
} else {
V_187 = F_23 ( V_20 ) ;
if ( ! V_187 )
continue;
memcpy ( V_187 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
V_187 -> V_36 . V_45 . V_2 = F_98 ( V_192 -> V_196 ) ;
V_187 -> V_44 = 1 ;
V_187 -> V_52 = V_59 ;
F_24 ( V_28 -> V_197 ,
& V_187 -> V_54 , F_25 ( V_187 ) ) ;
}
}
F_21 ( V_68 ) ;
}
static void F_99 ( struct V_27 * V_28 )
{
struct V_189 * V_198 ;
T_5 V_199 ;
F_16 ( V_28 , 4 , L_90 ) ;
if ( ! F_47 ( V_28 , V_145 ) )
return;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_200 * V_201 ;
V_201 = F_101 ( V_28 -> V_120 , F_102 ( V_202 ) ,
V_199 ) ;
if ( V_201 == NULL ||
! ( V_201 -> V_85 & V_203 ) )
continue;
V_198 = F_103 ( V_201 ) ;
if ( ! V_198 )
continue;
F_96 ( V_28 , V_198 ) ;
}
}
static void F_104 ( struct V_27 * V_28 )
{
struct V_189 * V_190 ;
F_16 ( V_28 , 4 , L_91 ) ;
F_105 () ;
V_190 = F_103 ( V_28 -> V_120 ) ;
if ( V_190 == NULL )
goto V_204;
F_96 ( V_28 , V_190 ) ;
F_99 ( V_28 ) ;
V_204:
F_106 () ;
}
static void
F_107 ( struct V_27 * V_28 , struct V_205 * V_206 )
{
struct V_29 * V_187 ;
struct V_207 * V_208 ;
struct V_29 * V_68 ;
char V_1 [ V_193 ] ;
F_16 ( V_28 , 4 , L_92 ) ;
V_68 = F_23 ( V_21 ) ;
if ( ! V_68 )
return;
for ( V_208 = V_206 -> V_194 ; V_208 != NULL ; V_208 = V_208 -> V_209 ) {
F_108 ( & V_208 -> V_210 , V_1 , V_206 -> V_120 , 0 ) ;
memcpy ( V_68 -> V_42 , V_1 , sizeof( V_68 -> V_42 ) ) ;
memcpy ( & V_68 -> V_36 . V_46 . V_2 , & V_208 -> V_210 . V_211 ,
sizeof( struct V_82 ) ) ;
V_68 -> V_44 = 1 ;
V_187 = F_13 ( V_28 , V_68 ) ;
if ( V_187 ) {
V_187 -> V_52 = V_63 ;
continue;
}
V_187 = F_23 ( V_21 ) ;
if ( ! V_187 )
continue;
memcpy ( V_187 -> V_42 , V_1 , V_80 ) ;
memcpy ( & V_187 -> V_36 . V_46 . V_2 , & V_208 -> V_210 . V_211 ,
sizeof( struct V_82 ) ) ;
V_187 -> V_44 = 1 ;
V_187 -> V_52 = V_59 ;
F_24 ( V_28 -> V_197 ,
& V_187 -> V_54 , F_25 ( V_187 ) ) ;
}
F_21 ( V_68 ) ;
}
static void F_109 ( struct V_27 * V_28 )
{
struct V_205 * V_198 ;
T_5 V_199 ;
F_16 ( V_28 , 4 , L_93 ) ;
if ( ! F_47 ( V_28 , V_145 ) )
return;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_200 * V_201 ;
V_201 = F_101 ( V_28 -> V_120 , F_102 ( V_202 ) ,
V_199 ) ;
if ( V_201 == NULL ||
! ( V_201 -> V_85 & V_203 ) )
continue;
V_198 = F_110 ( V_201 ) ;
if ( ! V_198 )
continue;
F_111 ( & V_198 -> V_212 ) ;
F_107 ( V_28 , V_198 ) ;
F_112 ( & V_198 -> V_212 ) ;
F_113 ( V_198 ) ;
}
}
static void F_114 ( struct V_27 * V_28 )
{
struct V_205 * V_206 ;
F_16 ( V_28 , 4 , L_94 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return ;
V_206 = F_110 ( V_28 -> V_120 ) ;
if ( ! V_206 )
return;
F_105 () ;
F_111 ( & V_206 -> V_212 ) ;
F_107 ( V_28 , V_206 ) ;
F_109 ( V_28 ) ;
F_112 ( & V_206 -> V_212 ) ;
F_106 () ;
F_113 ( V_206 ) ;
}
static void F_115 ( struct V_27 * V_28 ,
unsigned short V_199 )
{
struct V_189 * V_198 ;
struct V_213 * V_214 ;
struct V_29 * V_2 ;
struct V_200 * V_201 ;
F_16 ( V_28 , 4 , L_95 ) ;
V_201 = F_101 ( V_28 -> V_120 , F_102 ( V_202 ) , V_199 ) ;
if ( ! V_201 )
return;
V_198 = F_116 ( V_201 ) ;
if ( ! V_198 )
return;
V_2 = F_23 ( V_20 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_60 ) ;
for ( V_214 = V_198 -> V_215 ; V_214 ; V_214 = V_214 -> V_216 ) {
V_2 -> V_36 . V_45 . V_2 = F_98 ( V_214 -> V_217 ) ;
V_2 -> V_36 . V_45 . V_89 = F_98 ( V_214 -> V_218 ) ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_2 ) ;
F_117 ( V_198 ) ;
}
static void F_118 ( struct V_27 * V_28 ,
unsigned short V_199 )
{
#ifdef F_46
struct V_205 * V_206 ;
struct V_219 * V_214 ;
struct V_29 * V_2 ;
struct V_200 * V_201 ;
F_16 ( V_28 , 4 , L_96 ) ;
V_201 = F_101 ( V_28 -> V_120 , F_102 ( V_202 ) , V_199 ) ;
if ( ! V_201 )
return;
V_206 = F_110 ( V_201 ) ;
if ( ! V_206 )
return;
V_2 = F_23 ( V_21 ) ;
if ( ! V_2 )
return;
F_28 ( & V_28 -> V_60 ) ;
F_10 (ifa, &in6_dev->addr_list, if_list) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_214 -> V_2 ,
sizeof( struct V_82 ) ) ;
V_2 -> V_36 . V_46 . V_88 = V_214 -> V_220 ;
V_2 -> type = V_49 ;
F_15 ( V_28 , V_2 ) ;
}
F_26 ( & V_28 -> V_60 ) ;
F_21 ( V_2 ) ;
F_113 ( V_206 ) ;
#endif
}
static void F_119 ( struct V_27 * V_28 ,
unsigned short V_199 )
{
F_105 () ;
F_115 ( V_28 , V_199 ) ;
F_118 ( V_28 , V_199 ) ;
F_106 () ;
}
static int F_120 ( struct V_200 * V_120 ,
T_6 V_19 , T_5 V_199 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
F_121 ( V_199 , V_28 -> V_222 ) ;
return 0 ;
}
static int F_122 ( struct V_200 * V_120 ,
T_6 V_19 , T_5 V_199 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
F_38 ( V_28 , 4 , L_97 , V_199 ) ;
if ( F_123 ( V_28 , V_223 ) ) {
F_16 ( V_28 , 3 , L_98 ) ;
return 0 ;
}
F_119 ( V_28 , V_199 ) ;
F_124 ( V_199 , V_28 -> V_222 ) ;
F_125 ( V_28 -> V_120 ) ;
return 0 ;
}
static inline int F_126 ( struct V_27 * V_28 ,
struct V_224 * V_225 , struct V_226 * V_160 ,
unsigned short * V_227 )
{
T_2 V_64 ;
struct V_228 * V_229 ;
unsigned char V_230 [ V_193 ] ;
int V_231 = 0 ;
if ( ! ( V_160 -> V_160 . V_232 . V_85 & V_130 ) ) {
V_64 = ( V_160 -> V_160 . V_232 . V_85 & V_131 ) ? V_233 :
V_234 ;
switch ( V_160 -> V_160 . V_232 . V_85 & V_235 ) {
case V_125 :
switch ( V_64 ) {
#ifdef F_46
case V_233 :
F_108 ( (struct V_82 * )
V_225 -> V_77 + 24 ,
V_230 , V_28 -> V_120 , 0 ) ;
break;
#endif
case V_234 :
V_229 = (struct V_228 * ) V_225 -> V_77 ;
F_91 ( V_229 -> V_236 , V_230 ) ;
break;
default:
memcpy ( V_230 , V_28 -> V_120 -> V_237 ,
V_28 -> V_120 -> V_238 ) ;
}
V_28 -> V_239 . V_240 ++ ;
V_225 -> V_241 = V_242 ;
break;
case V_127 :
memcpy ( V_230 , V_28 -> V_120 -> V_237 ,
V_28 -> V_120 -> V_238 ) ;
V_28 -> V_239 . V_240 ++ ;
V_225 -> V_241 = V_243 ;
break;
case V_128 :
case V_133 :
case V_244 :
default:
if ( V_28 -> V_69 . V_70 )
V_225 -> V_241 = V_245 ;
else
V_225 -> V_241 = V_246 ;
memcpy ( V_230 , V_28 -> V_120 -> V_162 ,
V_28 -> V_120 -> V_238 ) ;
}
if ( V_160 -> V_160 . V_232 . V_247 & V_248 )
V_28 -> V_120 -> V_249 -> V_250 ( V_225 , V_28 -> V_120 , V_64 ,
V_230 , & V_160 -> V_160 . V_232 . V_251 [ 2 ] ,
V_28 -> V_120 -> V_238 ) ;
else
V_28 -> V_120 -> V_249 -> V_250 ( V_225 , V_28 -> V_120 , V_64 ,
V_230 , L_99 , V_28 -> V_120 -> V_238 ) ;
}
V_225 -> V_252 = F_127 ( V_225 , V_28 -> V_120 ) ;
if ( V_160 -> V_160 . V_232 . V_247 &
( V_253 | V_254 ) ) {
* V_227 = ( V_160 -> V_160 . V_232 . V_247 & V_253 ) ?
V_160 -> V_160 . V_232 . V_227 : * ( ( T_5 * ) & V_160 -> V_160 . V_232 . V_251 [ 12 ] ) ;
V_231 = 1 ;
}
if ( V_28 -> V_120 -> V_255 & V_256 ) {
if ( ( V_160 -> V_160 . V_232 . V_247 &
( V_257 |
V_258 ) ) ==
( V_257 |
V_258 ) )
V_225 -> V_259 = V_260 ;
else
V_225 -> V_259 = V_261 ;
} else
V_225 -> V_259 = V_261 ;
return V_231 ;
}
static int F_128 ( struct V_27 * V_28 ,
int V_262 , int * V_263 )
{
int V_264 = 0 ;
struct V_224 * V_225 ;
struct V_226 * V_160 ;
T_2 V_265 = 0 ;
int V_231 ;
unsigned int V_23 ;
T_2 V_266 ;
* V_263 = 0 ;
F_129 ( ! V_262 ) ;
while ( V_262 ) {
V_225 = F_130 ( V_28 ,
& V_28 -> V_267 . V_268 -> V_269 [ V_28 -> V_270 . V_271 ] ,
& V_28 -> V_270 . V_272 , & V_28 -> V_270 . V_273 , & V_160 ) ;
if ( ! V_225 ) {
* V_263 = 1 ;
break;
}
V_225 -> V_120 = V_28 -> V_120 ;
switch ( V_160 -> V_160 . V_232 . V_274 ) {
case V_275 :
V_266 = * ( T_2 * ) V_225 -> V_77 ;
if ( ( V_28 -> V_94 . type == V_95 ) &&
( V_266 == V_276 ) ) {
V_225 -> V_252 = F_131 ( V_276 ) ;
V_225 -> V_241 = V_246 ;
V_225 -> V_277 = V_278 ;
V_225 -> V_120 = V_28 -> V_120 ;
V_23 = V_225 -> V_23 ;
V_28 -> V_120 -> V_249 -> V_250 ( V_225 , V_28 -> V_120 , 0 ,
V_28 -> V_120 -> V_162 , L_99 ,
V_28 -> V_120 -> V_238 ) ;
F_132 ( V_225 ) ;
} else {
V_231 = F_126 ( V_28 , V_225 , V_160 ,
& V_265 ) ;
V_23 = V_225 -> V_23 ;
if ( V_231 && ! V_28 -> V_69 . V_70 )
F_133 ( V_225 ,
F_102 ( V_202 ) , V_265 ) ;
F_134 ( & V_28 -> V_279 , V_225 ) ;
}
break;
case V_280 :
V_225 -> V_241 = V_246 ;
V_225 -> V_252 = F_127 ( V_225 , V_225 -> V_120 ) ;
V_23 = V_225 -> V_23 ;
F_132 ( V_225 ) ;
break;
default:
F_135 ( V_225 ) ;
F_16 ( V_28 , 3 , L_100 ) ;
F_136 ( V_281 , 3 , V_160 , V_282 ) ;
continue;
}
V_264 ++ ;
V_262 -- ;
V_28 -> V_239 . V_283 ++ ;
V_28 -> V_239 . V_284 += V_23 ;
}
return V_264 ;
}
static int F_137 ( struct V_200 * V_120 ,
struct V_27 * V_28 )
{
int V_4 = 0 ;
T_5 V_199 ;
F_100 (vid, card->active_vlans, VLAN_N_VID) {
struct V_200 * V_201 ;
F_105 () ;
V_201 = F_101 ( V_28 -> V_120 , F_102 ( V_202 ) ,
V_199 ) ;
F_106 () ;
if ( V_201 == V_120 ) {
V_4 = V_285 ;
break;
}
}
if ( V_4 && ! ( F_138 ( V_120 ) -> V_221 == ( void * ) V_28 ) )
return 0 ;
return V_4 ;
}
static int F_139 ( struct V_200 * V_120 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
unsigned long V_85 ;
F_140 ( & V_286 . V_287 , V_85 ) ;
F_10 (card, &qeth_core_card_list.list, list) {
if ( V_28 -> V_120 == V_120 ) {
V_4 = V_288 ;
break;
}
V_4 = F_137 ( V_120 , V_28 ) ;
if ( V_4 )
break;
}
F_141 ( & V_286 . V_287 , V_85 ) ;
return V_4 ;
}
static struct V_27 * F_142 ( struct V_200 * V_120 )
{
struct V_27 * V_28 = NULL ;
int V_4 ;
V_4 = F_139 ( V_120 ) ;
if ( V_4 == V_288 )
V_28 = V_120 -> V_221 ;
else if ( V_4 == V_285 )
V_28 = F_138 ( V_120 ) -> V_221 ;
if ( V_28 && V_28 -> V_69 . V_289 )
V_28 = NULL ;
if ( V_28 )
F_38 ( V_28 , 4 , L_101 , V_4 ) ;
return V_28 ;
}
static void F_143 ( struct V_27 * V_28 , int V_290 )
{
F_62 ( V_134 , 2 , L_102 ) ;
F_136 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
F_144 ( V_28 , 0 , 1 ) ;
if ( V_28 -> V_69 . V_70 &&
( V_28 -> V_94 . V_174 == V_177 ) )
F_89 ( V_28 , V_172 ) ;
if ( V_28 -> V_291 . V_292 == V_293 &&
V_28 -> V_294 . V_292 == V_293 &&
( V_28 -> V_292 == V_295 ) ) {
if ( V_290 )
F_145 ( V_28 -> V_120 ) ;
else {
F_146 () ;
F_147 ( V_28 -> V_120 ) ;
F_148 () ;
}
V_28 -> V_292 = V_296 ;
}
if ( V_28 -> V_292 == V_296 ) {
F_30 ( V_28 , 1 ) ;
F_149 ( V_28 ) ;
V_28 -> V_292 = V_297 ;
}
if ( V_28 -> V_292 == V_297 ) {
F_150 ( V_28 , 0 ) ;
F_151 ( V_28 ) ;
F_152 ( V_28 ) ;
V_28 -> V_292 = V_298 ;
}
if ( V_28 -> V_292 == V_298 ) {
F_153 ( & V_28 -> V_291 ) ;
F_153 ( & V_28 -> V_294 ) ;
}
}
static void
F_154 ( struct V_27 * V_28 )
{
struct V_200 * V_120 = V_28 -> V_120 ;
if ( ( ( V_120 -> V_85 & V_299 ) &&
( V_28 -> V_94 . V_174 == V_177 ) ) ||
( ! ( V_120 -> V_85 & V_299 ) &&
( V_28 -> V_94 . V_174 == V_175 ) ) )
return;
if ( V_28 -> V_94 . V_300 ) {
if ( F_66 ( V_28 , V_301 ) )
F_155 ( V_28 ) ;
} else if ( V_28 -> V_69 . V_70 &&
F_66 ( V_28 , V_302 ) ) {
if ( V_120 -> V_85 & V_299 ) {
F_16 ( V_28 , 3 , L_103 ) ;
F_89 ( V_28 , V_176 ) ;
} else {
F_16 ( V_28 , 3 , L_104 ) ;
F_89 ( V_28 , V_172 ) ;
}
}
}
static void F_125 ( struct V_200 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
F_16 ( V_28 , 3 , L_105 ) ;
if ( F_156 ( V_28 , V_223 ) &&
( V_28 -> V_292 != V_295 ) )
return;
if ( ! V_28 -> V_69 . V_70 ) {
F_28 ( & V_28 -> V_71 ) ;
F_92 ( V_28 ) ;
F_104 ( V_28 ) ;
#ifdef F_46
F_114 ( V_28 ) ;
#endif
F_95 ( V_28 ) ;
F_94 ( V_28 ) ;
F_26 ( & V_28 -> V_71 ) ;
if ( ! F_66 ( V_28 , V_301 ) )
return;
}
F_154 ( V_28 ) ;
}
static const char * F_157 ( int * V_4 )
{
switch ( * V_4 ) {
case V_303 :
* V_4 = - V_157 ;
return L_106 ;
case V_304 :
* V_4 = - V_144 ;
return L_107 ;
case V_305 :
* V_4 = - V_7 ;
return L_108 ;
case V_306 :
* V_4 = - V_144 ;
return L_109 ;
case V_307 :
* V_4 = - V_47 ;
return L_110 ;
default:
return L_111 ;
}
}
static int F_158 ( struct V_27 * V_28 , int V_308 )
{
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_112 ) ;
if ( V_28 -> V_94 . V_300 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_309 ,
V_308 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_113
L_114 , F_44 ( V_28 ) ,
F_157 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static T_7 F_159 ( struct V_27 * V_28 ,
struct V_310 * V_311 ,
struct V_312 * type , T_1 V_313 )
{
T_7 V_4 ;
T_1 V_314 ;
V_314 = V_311 -> V_315 == 5 ;
if ( type -> V_316 == V_317 ) {
F_16 ( V_28 , 4 , L_115 ) ;
if ( V_313 ) {
V_4 = V_314 ? sizeof( struct V_318 ) :
sizeof( struct V_319 ) ;
} else {
V_4 = V_314 ? sizeof( struct V_320 ) :
sizeof( struct V_321 ) ;
}
} else if ( type -> V_316 == V_322 ) {
F_16 ( V_28 , 4 , L_116 ) ;
if ( V_313 ) {
V_4 = V_314 ?
sizeof( struct V_323 ) :
sizeof( struct V_324 ) ;
} else {
V_4 = V_314 ?
sizeof( struct V_325 ) :
sizeof( struct V_326 ) ;
}
} else {
F_16 ( V_28 , 4 , L_117 ) ;
V_4 = 0 ;
}
return V_4 ;
}
static int F_160 ( struct V_312 * type , T_2 V_64 )
{
return ( type -> V_316 == V_317 && V_64 == V_20 ) ||
( type -> V_316 == V_322 && V_64 == V_21 ) ;
}
static int F_161 ( struct V_27 * V_28 ,
struct V_158 * V_159 , unsigned long V_77 )
{
struct V_75 * V_76 ;
struct V_310 * V_311 ;
struct V_327 * V_328 ;
int V_24 ;
int V_329 ;
int V_330 ;
int V_331 ;
T_1 V_332 ;
F_16 ( V_28 , 3 , L_118 ) ;
V_328 = (struct V_327 * ) V_159 -> V_333 ;
V_76 = (struct V_75 * ) V_77 ;
F_38 ( V_28 , 4 , L_119 , V_76 -> V_160 . V_334 ) ;
if ( V_76 -> V_160 . V_161 ) {
F_16 ( V_28 , 4 , L_120 ) ;
F_38 ( V_28 , 4 , L_119 , V_76 -> V_160 . V_161 ) ;
return 0 ;
}
if ( V_76 -> V_77 . V_335 . V_160 . V_161 ) {
V_76 -> V_160 . V_161 = V_76 -> V_77 . V_335 . V_160 . V_161 ;
F_16 ( V_28 , 4 , L_121 ) ;
F_38 ( V_28 , 4 , L_119 , V_76 -> V_160 . V_161 ) ;
return 0 ;
}
V_311 = & V_76 -> V_77 . V_335 . V_77 . V_336 ;
F_38 ( V_28 , 4 , L_122 , V_311 -> V_308 ) ;
V_332 = ( V_328 -> V_37 & V_337 ) > 0 ;
V_331 = V_332 ? V_338 : 0 ;
V_330 = 0 ;
for ( V_329 = 0 ; V_329 < V_311 -> V_308 ; ++ V_329 ) {
char * V_339 ;
T_7 V_340 ;
struct V_312 * V_341 ;
V_339 = & V_311 -> V_77 + V_330 ;
V_341 = & ( (struct V_320 * ) V_339 ) -> type ;
if ( ! F_160 ( V_341 , V_76 -> V_160 . V_334 ) ) {
F_16 ( V_28 , 4 , L_123 ) ;
F_38 ( V_28 , 4 , L_119 , V_341 -> V_316 ) ;
break;
}
V_340 = F_159 ( V_28 , V_311 , V_341 ,
V_332 ) ;
F_38 ( V_28 , 5 , L_124 , V_340 ) ;
if ( ! V_340 )
break;
if ( ( V_328 -> V_342 - V_328 -> V_343 ) < V_340 ) {
F_38 ( V_28 , 4 , L_125 , - V_55 ) ;
V_76 -> V_160 . V_161 = V_344 ;
goto V_345;
}
memcpy ( V_328 -> V_346 + V_328 -> V_343 ,
& V_311 -> V_77 + V_330 + V_331 ,
V_340 ) ;
V_330 += V_340 + V_331 ;
V_328 -> V_343 += V_340 ;
++ V_328 -> V_308 ;
}
if ( V_76 -> V_77 . V_335 . V_160 . V_347 <
V_76 -> V_77 . V_335 . V_160 . V_348 )
return 1 ;
F_38 ( V_28 , 4 , L_126 , V_328 -> V_308 ) ;
memcpy ( V_328 -> V_346 , & V_328 -> V_308 , 4 ) ;
if ( V_328 -> V_37 & V_337 )
V_311 -> V_315 |= V_337 ;
memcpy ( V_328 -> V_346 + V_349 , & V_311 -> V_315 , 2 ) ;
F_38 ( V_28 , 4 , L_127 , 0 ) ;
return 0 ;
V_345:
V_24 = 0 ;
memcpy ( V_328 -> V_346 , & V_24 , 4 ) ;
return 0 ;
}
static int F_162 ( struct V_27 * V_28 ,
struct V_73 * V_74 , int V_23 ,
int (* F_163)( struct V_27 * , struct V_158 * ,
unsigned long ) ,
void * V_350 )
{
F_16 ( V_28 , 4 , L_128 ) ;
memcpy ( V_74 -> V_77 , V_351 , V_78 ) ;
memcpy ( F_164 ( V_74 -> V_77 ) ,
& V_28 -> V_352 . V_353 , V_354 ) ;
return F_165 ( V_28 , V_78 + V_23 , V_74 ,
F_163 , V_350 ) ;
}
static int F_166 ( struct V_27 * V_28 ,
enum V_18 V_64 ,
struct V_327 * V_328 )
{
struct V_73 * V_74 ;
struct V_75 * V_76 ;
int V_68 ;
int V_4 ;
F_38 ( V_28 , 3 , L_129 , V_64 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_355 ,
sizeof( struct V_310 )
- sizeof( char ) ,
V_64 ) ;
if ( ! V_74 )
return - V_55 ;
V_76 = (struct V_75 * ) ( V_74 -> V_77 + V_78 ) ;
V_76 -> V_77 . V_335 . V_77 . V_336 . V_356 = 0x000F ;
V_76 -> V_77 . V_335 . V_77 . V_336 . V_315 = 0 ;
V_76 -> V_77 . V_335 . V_77 . V_336 . V_308 = 0 ;
V_4 = F_162 ( V_28 , V_74 ,
V_357 + V_358 ,
F_161 , ( void * ) V_328 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 ,
L_130
L_131 , F_44 ( V_28 ) ,
F_157 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_167 ( struct V_27 * V_28 , char T_8 * V_346 )
{
struct V_327 V_328 = { 0 , } ;
int V_4 ;
F_16 ( V_28 , 3 , L_132 ) ;
if ( ! F_47 ( V_28 ,
V_141 ) ) {
F_16 ( V_28 , 3 , L_133 ) ;
V_4 = - V_144 ;
goto V_14;
}
if ( F_168 ( & V_328 , V_346 , 6 ) ) {
V_4 = - V_359 ;
goto V_14;
}
V_328 . V_346 = F_29 ( V_328 . V_342 , V_360 ) ;
if ( ! V_328 . V_346 ) {
V_4 = - V_55 ;
goto V_14;
}
V_328 . V_343 = V_361 ;
V_4 = F_166 ( V_28 , V_20 , & V_328 ) ;
if ( V_4 ) {
if ( F_169 ( V_346 , V_328 . V_346 , 4 ) )
V_4 = - V_359 ;
goto V_362;
}
#ifdef F_46
if ( V_328 . V_37 & V_363 ) {
F_166 ( V_28 , V_21 , & V_328 ) ;
}
#endif
if ( F_169 ( V_346 , V_328 . V_346 , V_328 . V_342 ) ) {
F_16 ( V_28 , 4 , L_134 ) ;
V_4 = - V_359 ;
goto V_362;
}
F_16 ( V_28 , 4 , L_135 ) ;
V_362:
F_21 ( V_328 . V_346 ) ;
V_14:
return V_4 ;
}
static int F_170 ( struct V_27 * V_28 ,
struct V_364 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_136 ) ;
if ( V_28 -> V_94 . V_300 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_74 = F_69 ( V_28 , V_141 ,
V_365 ,
sizeof( struct V_364 ) ,
V_20 ) ;
if ( ! V_74 )
return - V_55 ;
V_4 = F_70 ( V_28 , V_74 ,
sizeof( struct V_364 ) ,
( unsigned long ) V_107 ,
V_140 , NULL ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_2 ( ( T_3 * ) V_107 -> V_111 , V_1 ) ;
F_43 ( 2 , L_137
L_138 , V_1 , F_44 ( V_28 ) ,
F_157 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_171 ( struct V_27 * V_28 ,
struct V_364 * V_107 )
{
struct V_73 * V_74 ;
char V_1 [ 16 ] = { 0 , } ;
int V_68 ;
int V_4 ;
F_16 ( V_28 , 3 , L_139 ) ;
if ( V_28 -> V_94 . V_300 )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
memcpy ( V_1 , V_107 , 12 ) ;
V_74 = F_69 ( V_28 , V_141 ,
V_366 ,
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
F_43 ( 2 , L_140
L_141 , V_1 , F_44 ( V_28 ) ,
F_157 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_172 ( struct V_27 * V_28 )
{
int V_4 ;
int V_68 ;
F_16 ( V_28 , 3 , L_142 ) ;
if ( V_28 -> V_94 . V_300 || ( V_28 -> V_94 . type == V_95 ) )
return - V_144 ;
if ( ! F_47 ( V_28 , V_141 ) ) {
return - V_144 ;
}
V_4 = F_72 ( V_28 , V_141 ,
V_367 , 0 ) ;
if ( V_4 ) {
V_68 = V_4 ;
F_43 ( 2 , L_143
L_131 , F_44 ( V_28 ) ,
F_157 ( & V_4 ) , V_68 , V_68 ) ;
}
return V_4 ;
}
static int F_173 ( struct V_200 * V_120 , struct V_368 * V_369 , int V_76 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
struct V_364 V_370 ;
int V_4 = 0 ;
switch ( V_76 ) {
case V_371 :
if ( ! F_174 ( V_372 ) ) {
V_4 = - V_373 ;
break;
}
V_4 = F_158 ( V_28 , V_369 -> V_374 . V_375 ) ;
break;
case V_376 :
if ( ! F_174 ( V_372 ) ) {
V_4 = - V_373 ;
break;
}
V_4 = F_167 ( V_28 , V_369 -> V_374 . V_377 ) ;
break;
case V_378 :
if ( ! F_174 ( V_372 ) ) {
V_4 = - V_373 ;
break;
}
if ( F_168 ( & V_370 , V_369 -> V_374 . V_377 ,
sizeof( struct V_364 ) ) )
V_4 = - V_359 ;
else
V_4 = F_170 ( V_28 , & V_370 ) ;
break;
case V_379 :
if ( ! F_174 ( V_372 ) ) {
V_4 = - V_373 ;
break;
}
if ( F_168 ( & V_370 , V_369 -> V_374 . V_377 ,
sizeof( struct V_364 ) ) )
V_4 = - V_359 ;
else
V_4 = F_171 ( V_28 , & V_370 ) ;
break;
case V_380 :
if ( ! F_174 ( V_372 ) ) {
V_4 = - V_373 ;
break;
}
V_4 = F_172 ( V_28 ) ;
break;
default:
V_4 = - V_144 ;
}
return V_4 ;
}
inline int F_175 ( struct V_27 * V_28 , struct V_224 * V_225 )
{
int V_123 = V_381 ;
struct V_382 * V_383 = NULL ;
struct V_384 * V_385 ;
F_105 () ;
V_385 = F_176 ( V_225 ) ;
if ( V_385 )
V_383 = F_177 ( V_385 , V_225 ) ;
if ( V_383 ) {
V_123 = V_383 -> type ;
F_106 () ;
F_178 ( V_383 ) ;
if ( ( V_123 == V_126 ) ||
( V_123 == V_124 ) ||
( V_123 == V_132 ) )
return V_123 ;
else
return V_381 ;
}
F_106 () ;
if ( F_179 ( V_225 -> V_252 ) == V_233 )
return ( F_180 ( V_225 ) [ 24 ] == 0xff ) ?
V_124 : 0 ;
else if ( F_179 ( V_225 -> V_252 ) == V_234 )
return ( ( F_180 ( V_225 ) [ 16 ] & 0xf0 ) == 0xe0 ) ?
V_124 : 0 ;
if ( ! memcmp ( V_225 -> V_77 , V_225 -> V_120 -> V_237 , 6 ) )
return V_126 ;
else {
T_5 V_386 ;
V_386 = * ( ( T_5 * ) V_225 -> V_77 ) ;
switch ( V_28 -> V_94 . V_387 ) {
case V_388 :
case V_389 :
if ( ( V_386 == V_390 ) ||
( V_386 == V_391 ) )
return V_124 ;
break;
default:
if ( ( V_386 == V_392 ) ||
( V_386 == V_393 ) )
return V_124 ;
}
}
return V_123 ;
}
static void F_181 ( struct V_27 * V_28 ,
struct V_226 * V_160 , struct V_224 * V_225 )
{
char V_236 [ 16 ] ;
struct V_394 * V_395 ;
memset ( V_160 , 0 , sizeof( struct V_226 ) ) ;
V_160 -> V_160 . V_232 . V_274 = V_275 ;
V_160 -> V_160 . V_232 . V_247 = 0 ;
V_160 -> V_160 . V_232 . V_396 = V_225 -> V_23 - V_397 ;
V_160 -> V_160 . V_232 . V_85 = V_131 | V_128 ;
V_395 = (struct V_394 * ) ( V_225 -> V_77 + V_397 ) ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
V_236 [ 0 ] = 0xfe ;
V_236 [ 1 ] = 0x80 ;
memcpy ( & V_236 [ 8 ] , V_395 -> V_398 , 8 ) ;
memcpy ( V_160 -> V_160 . V_232 . V_251 , V_236 , 16 ) ;
}
static void F_182 ( struct V_27 * V_28 , struct V_226 * V_160 ,
struct V_224 * V_225 , int V_399 , int V_123 )
{
struct V_384 * V_385 ;
memset ( V_160 , 0 , sizeof( struct V_226 ) ) ;
V_160 -> V_160 . V_232 . V_274 = V_275 ;
V_160 -> V_160 . V_232 . V_247 = 0 ;
if ( F_183 ( V_225 ) ) {
if ( ( V_399 == 4 ) || ( V_28 -> V_94 . type == V_95 ) )
V_160 -> V_160 . V_232 . V_247 = V_253 ;
else
V_160 -> V_160 . V_232 . V_247 = V_254 ;
V_160 -> V_160 . V_232 . V_227 = F_184 ( V_225 ) ;
}
V_160 -> V_160 . V_232 . V_396 = V_225 -> V_23 - sizeof( struct V_226 ) ;
F_105 () ;
V_385 = F_176 ( V_225 ) ;
if ( V_399 == 4 ) {
struct V_400 * V_401 = (struct V_400 * ) V_385 ;
T_4 * V_402 = & V_229 ( V_225 ) -> V_236 ;
if ( V_401 && V_401 -> V_403 )
V_402 = & V_401 -> V_403 ;
V_160 -> V_160 . V_232 . V_85 = F_59 ( V_123 ) ;
memset ( V_160 -> V_160 . V_232 . V_251 , 0 , 12 ) ;
* ( ( T_4 * ) ( & V_160 -> V_160 . V_232 . V_251 [ 12 ] ) ) = * V_402 ;
} else if ( V_399 == 6 ) {
struct V_404 * V_401 = (struct V_404 * ) V_385 ;
struct V_82 * V_402 = & F_185 ( V_225 ) -> V_236 ;
if ( V_401 && ! F_186 ( & V_401 -> V_405 ) )
V_402 = & V_401 -> V_405 ;
V_160 -> V_160 . V_232 . V_85 = F_60 ( V_123 ) ;
if ( V_28 -> V_94 . type == V_95 )
V_160 -> V_160 . V_232 . V_85 &= ~ V_130 ;
memcpy ( V_160 -> V_160 . V_232 . V_251 , V_402 , 16 ) ;
} else {
if ( ! memcmp ( V_225 -> V_77 + sizeof( struct V_226 ) ,
V_225 -> V_120 -> V_237 , 6 ) ) {
V_160 -> V_160 . V_232 . V_85 = V_127 |
V_130 ;
} else {
V_160 -> V_160 . V_232 . V_85 = ( V_123 == V_124 ) ?
V_125 | V_130 :
V_128 | V_130 ;
}
}
F_106 () ;
}
static inline void F_187 ( struct V_27 * V_28 ,
struct V_226 * V_160 , struct V_224 * V_225 )
{
struct V_228 * V_406 = V_229 ( V_225 ) ;
if ( V_406 -> V_252 == V_407 )
V_160 -> V_160 . V_232 . V_247 |= V_408 ;
V_160 -> V_160 . V_232 . V_247 |= V_258 |
V_257 ;
V_406 -> V_409 = 0 ;
if ( V_28 -> V_69 . V_410 )
V_28 -> V_411 . V_412 ++ ;
}
static void F_188 ( struct V_27 * V_28 ,
struct V_226 * V_413 , struct V_224 * V_225 )
{
struct V_414 * V_160 = (struct V_414 * ) V_413 ;
struct V_415 * V_416 = F_189 ( V_225 ) ;
struct V_228 * V_406 = V_229 ( V_225 ) ;
struct V_417 * V_418 = F_185 ( V_225 ) ;
V_160 -> V_160 . V_160 . V_232 . V_274 = V_419 ;
V_160 -> V_160 . V_160 . V_232 . V_396 = V_225 -> V_23 - sizeof( struct V_414 ) ;
V_160 -> V_420 . V_421 = ( T_2 ) sizeof( struct V_422 ) ;
V_160 -> V_420 . V_423 = 1 ;
V_160 -> V_420 . V_424 = 1 ;
V_160 -> V_420 . V_425 = 1 ;
V_160 -> V_420 . V_426 = 28 ;
V_160 -> V_420 . V_427 = F_190 ( V_225 ) -> V_428 ;
V_160 -> V_420 . V_429 = ( T_2 ) ( V_406 -> V_430 * 4 + V_416 -> V_431 * 4 ) ;
V_160 -> V_420 . V_432 = ( T_2 ) ( V_225 -> V_23 - V_160 -> V_420 . V_429 -
sizeof( struct V_414 ) ) ;
V_416 -> V_409 = 0 ;
if ( F_179 ( V_225 -> V_252 ) == V_233 ) {
V_418 -> V_432 = 0 ;
V_416 -> V_409 = ~ F_191 ( & V_418 -> V_433 , & V_418 -> V_236 ,
0 , V_434 , 0 ) ;
} else {
V_416 -> V_409 = ~ F_192 ( V_406 -> V_433 , V_406 -> V_236 ,
0 , V_434 , 0 ) ;
V_406 -> V_435 = 0 ;
V_406 -> V_409 = 0 ;
}
}
static int F_193 ( struct V_27 * V_28 ,
struct V_224 * V_225 , int V_436 )
{
T_9 V_437 = ( T_9 ) F_189 ( V_225 ) + F_194 ( V_225 ) ;
int V_438 = F_195 (
V_437 ,
( T_9 ) V_225 -> V_77 + F_196 ( V_225 ) ) +
F_197 ( V_225 ) ;
if ( ( V_438 + V_436 ) > F_198 ( V_28 ) ) {
F_43 ( 2 ,
L_144 ,
V_438 + V_436 , V_225 -> V_23 ) ;
return 0 ;
}
return V_438 ;
}
static T_10 F_199 ( struct V_224 * V_225 ,
struct V_200 * V_120 )
{
int V_4 ;
T_6 * V_439 ;
struct V_226 * V_160 = NULL ;
int V_440 = 0 ;
int V_438 ;
struct V_27 * V_28 = V_120 -> V_221 ;
struct V_224 * V_441 = NULL ;
int V_399 = F_200 ( V_225 ) ;
int V_123 = F_175 ( V_28 , V_225 ) ;
struct V_442 * V_443 =
V_28 -> V_267 . V_444 [ V_28 -> V_267 . V_445
|| ( V_123 && V_28 -> V_94 . V_446 ) ?
F_201 ( V_28 , V_225 , V_399 , V_123 ) :
V_28 -> V_267 . V_447 ] ;
int V_448 = V_225 -> V_23 ;
bool V_449 ;
int V_450 = - 1 ;
int V_451 ;
if ( ( ( V_28 -> V_94 . type == V_95 ) &&
( ( ( V_28 -> V_69 . V_452 != V_453 ) && ! V_399 ) ||
( ( V_28 -> V_69 . V_452 == V_453 ) &&
( F_179 ( V_225 -> V_252 ) != V_276 ) ) ) ) ||
V_28 -> V_69 . V_70 )
goto V_454;
if ( ( V_28 -> V_292 != V_295 ) || ! V_28 -> V_455 ) {
V_28 -> V_239 . V_456 ++ ;
goto V_454;
}
if ( ( V_123 == V_126 ) &&
( V_28 -> V_94 . V_150 == 0 ) )
goto V_454;
if ( V_28 -> V_69 . V_410 ) {
V_28 -> V_411 . V_457 ++ ;
V_28 -> V_411 . V_458 = F_202 () ;
}
V_449 = F_203 ( V_225 ) &&
( F_204 ( V_225 ) == V_434 ) && ( V_399 == 4 ) ;
if ( V_28 -> V_94 . type == V_95 ) {
V_441 = V_225 ;
V_450 = V_397 ;
V_160 = F_205 ( V_459 , V_65 ) ;
if ( ! V_160 )
goto V_454;
V_440 ++ ;
} else {
V_441 = F_206 ( V_225 , sizeof( struct V_414 )
+ V_460 ) ;
if ( ! V_441 )
goto V_454;
if ( V_399 == 4 ) {
F_207 ( V_441 , V_397 ) ;
}
if ( V_399 != 4 && F_183 ( V_441 ) ) {
F_208 ( V_441 , V_460 ) ;
F_209 ( V_441 , V_441 -> V_77 + 4 , 4 ) ;
F_210 ( V_441 , 4 ,
V_441 -> V_77 + 8 , 4 ) ;
F_210 ( V_441 , 8 ,
V_441 -> V_77 + 12 , 4 ) ;
V_439 = ( T_6 * ) ( V_441 -> V_77 + 12 ) ;
* V_439 = F_131 ( V_202 ) ;
* ( V_439 + 1 ) = F_131 ( F_184 ( V_441 ) ) ;
}
}
F_211 ( V_120 ) ;
if ( ( V_28 -> V_94 . type != V_95 ) &&
( ( V_449 && ! F_193 ( V_28 , V_441 , 1 ) ) ||
( ! V_449 && ! F_212 ( V_28 , V_441 , 0 , 0 ) ) ) ) {
int V_461 = F_213 ( V_441 ) ;
if ( V_28 -> V_69 . V_410 ) {
if ( V_461 )
V_28 -> V_411 . V_462 ++ ;
else
V_28 -> V_411 . V_463 ++ ;
}
if ( V_461 )
goto V_454;
}
if ( V_449 ) {
V_160 = F_208 ( V_441 , sizeof( struct V_414 ) ) ;
memset ( V_160 , 0 , sizeof( struct V_414 ) ) ;
F_182 ( V_28 , V_160 , V_441 , V_399 , V_123 ) ;
F_188 ( V_28 , V_160 , V_441 ) ;
V_440 ++ ;
} else {
if ( V_450 < 0 ) {
V_160 = F_208 ( V_441 , sizeof( struct V_226 ) ) ;
F_182 ( V_28 , V_160 , V_441 , V_399 ,
V_123 ) ;
} else {
if ( F_179 ( V_441 -> V_252 ) == V_276 )
F_181 ( V_28 , V_160 , V_441 ) ;
else {
F_182 ( V_28 , V_160 , V_441 , V_399 ,
V_123 ) ;
V_160 -> V_160 . V_232 . V_396 = V_441 -> V_23 - V_450 ;
}
}
if ( V_225 -> V_259 == V_464 )
F_187 ( V_28 , V_160 , V_441 ) ;
}
V_438 = V_449 ?
F_193 ( V_28 , V_441 , V_440 ) :
F_212 ( V_28 , V_441 , V_440 ,
( V_450 > 0 ) ? V_450 : 0 ) ;
if ( ! V_438 ) {
if ( V_450 >= 0 )
F_214 ( V_459 , V_160 ) ;
goto V_454;
}
V_438 += V_440 ;
if ( V_28 -> V_94 . type != V_95 ) {
int V_23 ;
if ( V_449 )
V_23 = ( ( unsigned long ) F_189 ( V_441 ) +
F_194 ( V_441 ) ) -
( unsigned long ) V_441 -> V_77 ;
else
V_23 = sizeof( struct V_465 ) ;
if ( F_215 ( V_441 , & V_160 , V_23 ) )
goto V_454;
V_4 = F_216 ( V_28 , V_443 , V_441 , V_160 , V_438 ) ;
} else
V_4 = F_217 ( V_28 , V_443 , V_441 , V_160 ,
V_450 , 0 ) ;
if ( ! V_4 ) {
V_28 -> V_239 . V_466 ++ ;
V_28 -> V_239 . V_448 += V_448 ;
if ( V_441 != V_225 )
F_135 ( V_225 ) ;
if ( V_28 -> V_69 . V_410 ) {
V_451 = F_190 ( V_441 ) -> V_451 ;
if ( V_449 ) {
V_28 -> V_411 . V_467 += V_448 ;
V_28 -> V_411 . V_468 ++ ;
}
if ( V_451 ) {
V_28 -> V_411 . V_469 ++ ;
V_28 -> V_411 . V_470 += V_451 + 1 ;
}
}
V_4 = V_471 ;
} else {
if ( V_450 >= 0 )
F_214 ( V_459 , V_160 ) ;
if ( V_4 == - V_472 ) {
if ( V_441 != V_225 )
F_135 ( V_441 ) ;
return V_473 ;
} else
goto V_454;
}
F_218 ( V_120 ) ;
if ( V_28 -> V_69 . V_410 )
V_28 -> V_411 . V_474 += F_202 () -
V_28 -> V_411 . V_458 ;
return V_4 ;
V_454:
V_28 -> V_239 . V_475 ++ ;
V_28 -> V_239 . V_476 ++ ;
if ( ( V_441 != V_225 ) && V_441 )
F_135 ( V_441 ) ;
F_135 ( V_225 ) ;
F_218 ( V_120 ) ;
return V_471 ;
}
static int F_219 ( struct V_200 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
int V_4 = 0 ;
F_16 ( V_28 , 4 , L_145 ) ;
if ( V_28 -> V_292 == V_295 )
return V_4 ;
if ( V_28 -> V_292 != V_296 )
return - V_477 ;
V_28 -> V_77 . V_292 = V_293 ;
V_28 -> V_292 = V_295 ;
F_220 ( V_120 ) ;
if ( F_221 ( V_28 -> V_77 . V_478 , 0 ) >= 0 ) {
F_222 ( & V_28 -> V_279 ) ;
F_223 ( & V_28 -> V_279 ) ;
} else
V_4 = - V_157 ;
return V_4 ;
}
static int F_224 ( struct V_200 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
F_16 ( V_28 , 5 , L_146 ) ;
if ( F_123 ( V_28 , V_223 ) ) {
F_16 ( V_28 , 3 , L_147 ) ;
return - V_479 ;
}
return F_219 ( V_120 ) ;
}
static int F_145 ( struct V_200 * V_120 )
{
struct V_27 * V_28 = V_120 -> V_221 ;
F_16 ( V_28 , 4 , L_148 ) ;
F_225 ( V_120 ) ;
if ( V_28 -> V_292 == V_295 ) {
V_28 -> V_292 = V_296 ;
F_226 ( & V_28 -> V_279 ) ;
}
return 0 ;
}
static int F_227 ( struct V_382 * V_383 )
{
V_383 -> V_480 = V_481 ;
memcpy ( V_383 -> V_482 , L_99 , 6 ) ;
V_383 -> V_483 = V_383 -> V_484 -> V_485 ;
return 0 ;
}
static int
F_228 ( struct V_200 * V_120 , struct V_486 * V_487 )
{
if ( V_487 -> V_488 -> V_489 == V_490 )
V_487 -> V_491 = F_227 ;
return 0 ;
}
static int F_229 ( struct V_27 * V_28 )
{
int V_4 ;
if ( V_28 -> V_94 . type == V_492 ||
V_28 -> V_94 . type == V_493 ) {
if ( ( V_28 -> V_94 . V_387 == V_389 ) ||
( V_28 -> V_94 . V_387 == V_388 ) ) {
F_230 ( L_149 ) ;
return - V_477 ;
} else {
V_28 -> V_120 = F_231 ( 0 ) ;
if ( ! V_28 -> V_120 )
return - V_477 ;
V_28 -> V_120 -> V_494 = & V_495 ;
F_87 ( V_28 ) ;
if ( ! ( V_28 -> V_94 . V_164 & V_168 ) )
V_28 -> V_120 -> V_496 = V_28 -> V_94 . V_164 &
0xffff ;
if ( ! V_28 -> V_94 . V_300 ) {
V_28 -> V_120 -> V_497 = V_498 |
V_256 | V_499 |
V_500 ;
V_28 -> V_120 -> V_501 = V_498 |
V_256 | V_499 |
V_500 ;
}
}
} else if ( V_28 -> V_94 . type == V_95 ) {
V_28 -> V_120 = F_232 ( 0 , L_150 , V_502 ,
V_503 ) ;
if ( ! V_28 -> V_120 )
return - V_477 ;
V_28 -> V_120 -> V_85 |= V_504 ;
V_28 -> V_120 -> V_494 = & V_505 ;
V_4 = F_85 ( V_28 ) ;
if ( V_4 )
return V_4 ;
if ( V_28 -> V_69 . V_506 [ 0 ] )
memcpy ( V_28 -> V_120 -> V_507 , V_28 -> V_69 . V_506 , 9 ) ;
} else
return - V_477 ;
V_28 -> V_120 -> V_221 = V_28 ;
V_28 -> V_120 -> V_508 = V_509 ;
V_28 -> V_120 -> V_510 = V_28 -> V_94 . V_511 ;
V_28 -> V_120 -> V_512 = 64 ;
V_28 -> V_120 -> V_513 = V_514 ;
V_28 -> V_120 -> V_515 = & V_516 ;
V_28 -> V_120 -> V_255 |= V_517 |
V_518 |
V_519 ;
F_233 ( V_28 -> V_120 ) ;
V_28 -> V_120 -> V_520 = ( F_198 ( V_28 ) - 1 ) *
V_521 ;
F_234 ( V_28 -> V_120 , & V_28 -> V_119 -> V_120 ) ;
F_235 ( V_28 -> V_120 , & V_28 -> V_279 , V_522 , V_523 ) ;
F_236 ( V_28 -> V_120 ) ;
return F_237 ( V_28 -> V_120 ) ;
}
static int F_238 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_239 ( & V_119 -> V_120 ) ;
int V_4 ;
if ( V_119 -> V_120 . type == & V_525 ) {
V_4 = F_240 ( & V_119 -> V_120 ) ;
if ( V_4 )
return V_4 ;
}
F_241 ( V_28 -> V_58 ) ;
F_241 ( V_28 -> V_197 ) ;
V_28 -> V_69 . V_289 = 0 ;
V_28 -> V_94 . V_526 = 0 ;
return 0 ;
}
static void F_242 ( struct V_524 * V_527 )
{
struct V_27 * V_28 = F_239 ( & V_527 -> V_120 ) ;
if ( V_527 -> V_120 . type == & V_525 )
F_243 ( & V_527 -> V_120 ) ;
F_144 ( V_28 , 0 , 1 ) ;
F_244 ( V_28 -> V_528 , F_156 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_527 -> V_292 == V_529 )
F_245 ( V_527 ) ;
if ( V_28 -> V_120 ) {
F_246 ( & V_28 -> V_279 ) ;
F_247 ( V_28 -> V_120 ) ;
V_28 -> V_120 = NULL ;
}
F_30 ( V_28 , 0 ) ;
F_48 ( V_28 ) ;
return;
}
static int F_248 ( struct V_524 * V_119 , int V_290 )
{
struct V_27 * V_28 = F_239 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
enum V_530 V_531 ;
F_249 ( & V_28 -> V_532 ) ;
F_249 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 2 , L_151 ) ;
F_136 ( V_134 , 2 , & V_28 , sizeof( void * ) ) ;
V_531 = V_28 -> V_292 ;
V_4 = F_250 ( V_28 ) ;
if ( V_4 ) {
F_251 ( V_134 , 2 , L_152 , V_4 ) ;
V_4 = - V_477 ;
goto V_534;
}
if ( ! V_28 -> V_120 && F_229 ( V_28 ) ) {
V_4 = - V_477 ;
goto V_534;
}
if ( F_252 ( V_28 , V_535 ) ) {
if ( V_28 -> V_94 . V_526 &&
F_253 ( V_28 , V_536 ) )
V_28 -> V_94 . V_526 = 0 ;
} else
V_28 -> V_94 . V_526 = 0 ;
V_28 -> V_292 = V_297 ;
memset ( & V_28 -> V_270 , 0 , sizeof( struct V_537 ) ) ;
F_254 ( V_28 ) ;
F_62 ( V_134 , 2 , L_153 ) ;
V_4 = F_61 ( V_28 ) ;
if ( V_4 )
F_251 ( V_134 , 2 , L_152 , V_4 ) ;
if ( ! V_28 -> V_69 . V_70 ) {
V_4 = F_81 ( V_28 ) ;
if ( V_4 ) {
F_251 ( V_134 , 2 , L_154 , V_4 ) ;
goto V_534;
}
V_4 = F_42 ( V_28 ) ;
if ( V_4 )
F_251 ( V_134 , 2 , L_155 , V_4 ) ;
V_4 = F_45 ( V_28 ) ;
if ( V_4 )
F_251 ( V_134 , 2 , L_156 , V_4 ) ;
}
F_225 ( V_28 -> V_120 ) ;
V_4 = F_255 ( V_28 ) ;
if ( V_4 ) {
F_251 ( V_134 , 2 , L_157 , V_4 ) ;
V_4 = - V_477 ;
goto V_534;
}
V_28 -> V_292 = V_296 ;
F_144 ( V_28 , 0xffffffff , 0 ) ;
F_32 ( V_28 ) ;
if ( V_28 -> V_455 )
F_256 ( V_28 -> V_120 ) ;
else
F_236 ( V_28 -> V_120 ) ;
if ( V_531 == V_538 ) {
F_146 () ;
if ( V_290 )
F_219 ( V_28 -> V_120 ) ;
else
F_257 ( V_28 -> V_120 ) ;
F_125 ( V_28 -> V_120 ) ;
F_258 ( V_28 -> V_120 ) ;
F_148 () ;
}
F_259 ( V_28 ) ;
F_260 ( & V_119 -> V_120 . V_539 , V_540 ) ;
F_261 ( & V_28 -> V_533 ) ;
F_261 ( & V_28 -> V_532 ) ;
return 0 ;
V_534:
F_143 ( V_28 , 0 ) ;
F_262 ( F_263 ( V_28 ) ) ;
F_262 ( F_264 ( V_28 ) ) ;
F_262 ( F_265 ( V_28 ) ) ;
F_266 ( F_263 ( V_28 ) ) ;
if ( V_531 == V_538 )
V_28 -> V_292 = V_538 ;
else
V_28 -> V_292 = V_298 ;
F_261 ( & V_28 -> V_533 ) ;
F_261 ( & V_28 -> V_532 ) ;
return V_4 ;
}
static int F_267 ( struct V_524 * V_119 )
{
return F_248 ( V_119 , 0 ) ;
}
static int F_268 ( struct V_524 * V_527 ,
int V_290 )
{
struct V_27 * V_28 = F_239 ( & V_527 -> V_120 ) ;
int V_4 = 0 , V_541 = 0 , V_542 = 0 ;
enum V_530 V_531 ;
F_249 ( & V_28 -> V_532 ) ;
F_249 ( & V_28 -> V_533 ) ;
F_62 ( V_134 , 3 , L_158 ) ;
F_136 ( V_134 , 3 , & V_28 , sizeof( void * ) ) ;
if ( V_28 -> V_120 && F_269 ( V_28 -> V_120 ) )
F_236 ( V_28 -> V_120 ) ;
V_531 = V_28 -> V_292 ;
if ( ( ! V_290 && V_28 -> V_94 . V_526 ) || V_28 -> V_94 . V_526 == 2 ) {
F_253 ( V_28 , V_543 ) ;
V_28 -> V_94 . V_526 = 1 ;
}
F_143 ( V_28 , V_290 ) ;
if ( ( V_28 -> V_69 . V_452 == V_453 ) && V_28 -> V_120 ) {
F_146 () ;
F_270 ( V_544 , V_28 -> V_120 ) ;
F_148 () ;
}
V_4 = F_262 ( F_263 ( V_28 ) ) ;
V_541 = F_262 ( F_264 ( V_28 ) ) ;
V_542 = F_262 ( F_265 ( V_28 ) ) ;
if ( ! V_4 )
V_4 = ( V_541 ) ? V_541 : V_542 ;
if ( V_4 )
F_251 ( V_134 , 2 , L_159 , V_4 ) ;
F_266 ( F_263 ( V_28 ) ) ;
if ( V_531 == V_295 )
V_28 -> V_292 = V_538 ;
F_260 ( & V_527 -> V_120 . V_539 , V_540 ) ;
F_261 ( & V_28 -> V_533 ) ;
F_261 ( & V_28 -> V_532 ) ;
return 0 ;
}
static int F_245 ( struct V_524 * V_527 )
{
return F_268 ( V_527 , 0 ) ;
}
static int F_271 ( void * V_545 )
{
struct V_27 * V_28 ;
int V_4 = 0 ;
V_28 = (struct V_27 * ) V_545 ;
F_16 ( V_28 , 2 , L_160 ) ;
F_17 ( V_28 , 2 , & V_28 , sizeof( void * ) ) ;
if ( ! F_272 ( V_28 , V_223 ) )
return 0 ;
F_16 ( V_28 , 2 , L_161 ) ;
F_58 ( & V_28 -> V_119 -> V_120 ,
L_162 ) ;
F_273 ( V_28 ) ;
F_268 ( V_28 -> V_119 , 1 ) ;
V_4 = F_248 ( V_28 -> V_119 , 1 ) ;
if ( ! V_4 )
F_63 ( & V_28 -> V_119 -> V_120 ,
L_163 ) ;
else {
F_274 ( V_28 ) ;
F_58 ( & V_28 -> V_119 -> V_120 , L_164
L_165 ) ;
}
F_275 ( V_28 ) ;
F_276 ( V_28 , V_223 ) ;
F_277 ( V_28 , V_223 ) ;
return 0 ;
}
static int F_278 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_239 ( & V_119 -> V_120 ) ;
if ( V_28 -> V_120 )
F_279 ( V_28 -> V_120 ) ;
F_144 ( V_28 , 0 , 1 ) ;
F_244 ( V_28 -> V_528 , F_156 ( V_28 , 0xffffffff ) == 0 ) ;
if ( V_119 -> V_292 == V_546 )
return 0 ;
if ( V_28 -> V_292 == V_295 ) {
if ( V_28 -> V_94 . V_526 )
F_253 ( V_28 , V_543 ) ;
F_268 ( V_28 -> V_119 , 1 ) ;
} else
F_268 ( V_28 -> V_119 , 0 ) ;
return 0 ;
}
static int F_280 ( struct V_524 * V_119 )
{
struct V_27 * V_28 = F_239 ( & V_119 -> V_120 ) ;
int V_4 = 0 ;
if ( V_119 -> V_292 == V_546 )
goto V_14;
if ( V_28 -> V_292 == V_538 ) {
V_4 = F_248 ( V_28 -> V_119 , 1 ) ;
if ( V_4 ) {
F_146 () ;
F_147 ( V_28 -> V_120 ) ;
F_148 () ;
}
} else
V_4 = F_248 ( V_28 -> V_119 , 0 ) ;
V_14:
F_144 ( V_28 , 0xffffffff , 0 ) ;
if ( V_28 -> V_120 )
F_281 ( V_28 -> V_120 ) ;
if ( V_4 )
F_58 ( & V_28 -> V_119 -> V_120 , L_164
L_165 ) ;
return V_4 ;
}
static int F_282 ( struct V_27 * V_28 ,
struct V_75 * V_76 )
{
return 1 ;
}
static int F_283 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_213 * V_214 = (struct V_213 * ) V_545 ;
struct V_200 * V_120 = (struct V_200 * ) V_214 -> V_550 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
if ( F_284 ( V_120 ) != & V_551 )
return V_552 ;
V_28 = F_142 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_166 ) ;
V_2 = F_23 ( V_20 ) ;
if ( V_2 ) {
V_2 -> V_36 . V_45 . V_2 = F_98 ( V_214 -> V_217 ) ;
V_2 -> V_36 . V_45 . V_89 = F_98 ( V_214 -> V_218 ) ;
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
static int F_285 ( struct V_547 * V_548 ,
unsigned long V_549 , void * V_545 )
{
struct V_219 * V_214 = (struct V_219 * ) V_545 ;
struct V_200 * V_120 = (struct V_200 * ) V_214 -> V_555 -> V_120 ;
struct V_29 * V_2 ;
struct V_27 * V_28 ;
V_28 = F_142 ( V_120 ) ;
if ( ! V_28 )
return V_552 ;
F_16 ( V_28 , 3 , L_167 ) ;
if ( ! F_47 ( V_28 , V_105 ) )
return V_552 ;
V_2 = F_23 ( V_21 ) ;
if ( V_2 ) {
memcpy ( & V_2 -> V_36 . V_46 . V_2 , & V_214 -> V_2 , sizeof( struct V_82 ) ) ;
V_2 -> V_36 . V_46 . V_88 = V_214 -> V_220 ;
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
static int F_286 ( void )
{
int V_4 ;
F_62 ( V_134 , 5 , L_168 ) ;
V_4 = F_287 ( & V_556 ) ;
if ( V_4 )
return V_4 ;
#ifdef F_46
V_4 = F_288 ( & V_557 ) ;
if ( V_4 ) {
F_289 ( & V_556 ) ;
return V_4 ;
}
#else
F_290 ( L_169 ) ;
#endif
return 0 ;
}
static void F_291 ( void )
{
F_62 ( V_134 , 5 , L_170 ) ;
F_292 ( F_289 ( & V_556 ) ) ;
#ifdef F_46
F_292 ( F_293 ( & V_557 ) ) ;
#endif
}
static int T_11 F_294 ( void )
{
int V_4 = 0 ;
F_230 ( L_171 ) ;
V_4 = F_286 () ;
return V_4 ;
}
static void T_12 F_295 ( void )
{
F_291 () ;
F_230 ( L_172 ) ;
}
