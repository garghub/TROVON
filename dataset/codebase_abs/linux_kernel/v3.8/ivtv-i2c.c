static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_5 [ 4 ] ;
V_5 [ 0 ] = 0x00 ;
F_2 ( V_2 -> V_6 , V_5 , 1 ) ;
if ( F_3 ( V_2 -> V_6 , V_5 , sizeof( V_5 ) ) != sizeof( V_5 ) ) {
return 0 ;
}
if ( V_5 [ 2 ] == 0xff )
return 0 ;
V_5 [ 2 ] &= 0x7f ;
V_5 [ 3 ] |= 0x80 ;
* V_3 = V_5 [ 3 ] | V_5 [ 2 ] << 8 | V_5 [ 1 ] << 16 | V_5 [ 0 ] << 24 ;
* V_4 = * V_3 ;
return 1 ;
}
static int F_4 ( struct V_7 * V_8 , T_1 V_9 , const char * type , T_2 V_10 )
{
struct V_11 V_12 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_16 * V_17 = & V_8 -> V_18 ;
unsigned short V_19 [ 2 ] = { V_10 , V_20 } ;
if ( V_9 & V_21 ) {
if ( V_8 -> V_22 & V_21 )
return - 1 ;
memset ( & V_12 , 0 , sizeof( struct V_11 ) ) ;
F_5 ( V_12 . type , type , V_23 ) ;
return F_6 ( V_14 , & V_12 , V_19 , NULL )
== NULL ? - 1 : 0 ;
}
if ( V_8 -> V_22 & V_24 )
return - 1 ;
switch ( V_9 ) {
case V_25 :
V_17 -> V_26 = V_27 ;
V_17 -> V_28 =
V_29 ;
V_17 -> type = V_30 ;
V_17 -> V_31 = L_1 ;
break;
case V_32 :
case V_33 :
V_17 -> V_26 = V_34 ;
V_17 -> V_28 = V_35 ;
V_17 -> type = V_36 ;
V_17 -> V_31 = V_8 -> V_37 ;
break;
case V_38 :
V_17 -> V_26 = V_34 ;
V_17 -> V_28 = V_39 ;
V_17 -> type = V_36 ;
V_17 -> V_31 = V_8 -> V_37 ;
break;
case V_40 :
V_17 -> V_41 = F_1 ;
V_17 -> V_31 = V_8 -> V_37 ;
V_17 -> V_26 = V_42 ;
V_17 -> type = V_43 ;
break;
}
memset ( & V_12 , 0 , sizeof( struct V_11 ) ) ;
V_12 . V_44 = V_17 ;
F_5 ( V_12 . type , type , V_23 ) ;
return F_6 ( V_14 , & V_12 , V_19 , NULL ) == NULL ?
- 1 : 0 ;
}
struct V_45 * F_7 ( struct V_7 * V_8 )
{
struct V_11 V_12 ;
const unsigned short V_19 [] = {
0x1a ,
0x18 ,
V_20
} ;
memset ( & V_12 , 0 , sizeof( struct V_11 ) ) ;
F_5 ( V_12 . type , L_2 , V_23 ) ;
return F_6 ( & V_8 -> V_15 , & V_12 , V_19 , NULL ) ;
}
int F_8 ( struct V_7 * V_8 , unsigned V_46 )
{
struct V_47 * V_48 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
const char * type = V_49 [ V_46 ] ;
T_1 V_9 = 1 << V_46 ;
if ( V_46 >= F_9 ( V_50 ) )
return - 1 ;
if ( V_9 == V_51 ) {
V_48 = F_10 ( & V_8 -> V_52 , V_14 , type , 0 ,
V_8 -> V_53 -> V_54 ) ;
if ( V_48 )
V_48 -> V_55 = 1 << V_46 ;
V_48 = F_10 ( & V_8 -> V_52 , V_14 , type , 0 ,
V_8 -> V_53 -> V_56 ) ;
if ( V_48 )
V_48 -> V_55 = 1 << V_46 ;
V_48 = F_10 ( & V_8 -> V_52 , V_14 , type , 0 ,
V_8 -> V_53 -> V_57 ) ;
if ( V_48 )
V_48 -> V_55 = 1 << V_46 ;
return V_48 ? 0 : - 1 ;
}
if ( V_9 & V_58 )
return F_4 ( V_8 , V_9 , type , V_50 [ V_46 ] ) ;
if ( ! V_50 [ V_46 ] )
return - 1 ;
if ( V_9 == V_59 || V_9 == V_60 ) {
V_48 = F_10 ( & V_8 -> V_52 ,
V_14 , type , 0 , F_11 ( V_50 [ V_46 ] ) ) ;
} else if ( V_9 == V_61 ) {
struct V_62 V_63 ;
struct V_11 V_64 = {
. type = L_3 ,
. V_10 = V_50 [ V_46 ] ,
. V_44 = & V_63 ,
} ;
V_63 . V_65 = V_8 -> V_65 ;
V_48 = F_12 ( & V_8 -> V_52 , V_14 ,
& V_64 , NULL ) ;
} else {
V_48 = F_10 ( & V_8 -> V_52 ,
V_14 , type , V_50 [ V_46 ] , NULL ) ;
}
if ( V_48 )
V_48 -> V_55 = 1 << V_46 ;
return V_48 ? 0 : - 1 ;
}
struct V_47 * F_13 ( struct V_7 * V_8 , T_1 V_9 )
{
struct V_47 * V_66 = NULL ;
struct V_47 * V_48 ;
F_14 ( & V_8 -> V_52 . V_67 ) ;
F_15 (sd, &itv->v4l2_dev) {
if ( V_48 -> V_55 == V_9 ) {
V_66 = V_48 ;
break;
}
}
F_16 ( & V_8 -> V_52 . V_67 ) ;
return V_66 ;
}
static void F_17 ( struct V_7 * V_8 , int V_68 )
{
F_18 ( ~ V_68 , V_69 ) ;
}
static void F_19 ( struct V_7 * V_8 , int V_68 )
{
F_18 ( ~ V_68 & 1 , V_70 ) ;
}
static int F_20 ( struct V_7 * V_8 )
{
return F_21 ( V_71 ) & 1 ;
}
static int F_22 ( struct V_7 * V_8 )
{
return F_21 ( V_72 ) & 1 ;
}
static void F_23 ( struct V_7 * V_8 )
{
int V_73 ;
for ( V_73 = 0 ; V_73 < 5 ; ++ V_73 )
F_20 ( V_8 ) ;
}
static int F_24 ( struct V_7 * V_8 , int V_74 )
{
int V_73 ;
F_23 ( V_8 ) ;
for ( V_73 = 0 ; V_73 < 1000 ; ++ V_73 ) {
if ( F_20 ( V_8 ) == V_74 )
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_7 * V_8 , int V_74 )
{
int V_73 ;
F_23 ( V_8 ) ;
for ( V_73 = 0 ; V_73 < 1000 ; ++ V_73 ) {
if ( F_22 ( V_8 ) == V_74 )
return 1 ;
}
return 0 ;
}
static int F_26 ( struct V_7 * V_8 )
{
int V_75 = 0 ;
if ( F_20 ( V_8 ) == 1 ) {
F_27 ( L_4 ) ;
F_17 ( V_8 , 0 ) ;
if ( ! F_24 ( V_8 , 0 ) ) {
F_28 ( L_5 ) ;
return - V_76 ;
}
}
F_19 ( V_8 , 1 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 1 ) ;
if ( ! F_25 ( V_8 , 0 ) ) {
F_28 ( L_6 ) ;
V_75 = - V_76 ;
}
F_17 ( V_8 , 0 ) ;
if ( ! F_24 ( V_8 , 0 ) ) {
F_28 ( L_7 ) ;
V_75 = - V_76 ;
}
return V_75 ;
}
static int F_29 ( struct V_7 * V_8 , unsigned char V_77 )
{
int V_73 , V_78 ;
F_27 ( L_8 , V_77 ) ;
for ( V_73 = 0 ; V_73 < 8 ; ++ V_73 , V_77 <<= 1 ) {
F_17 ( V_8 , 0 ) ;
if ( ! F_24 ( V_8 , 0 ) ) {
F_28 ( L_9 ) ;
return - V_76 ;
}
V_78 = ( V_77 >> 7 ) & 1 ;
F_19 ( V_8 , V_78 ) ;
if ( ! F_25 ( V_8 , V_78 ) ) {
F_28 ( L_10 ) ;
return - V_76 ;
}
F_17 ( V_8 , 1 ) ;
if ( ! F_24 ( V_8 , 1 ) ) {
F_28 ( L_11 ) ;
return - V_76 ;
}
}
F_17 ( V_8 , 0 ) ;
if ( ! F_24 ( V_8 , 0 ) ) {
F_28 ( L_9 ) ;
return - V_76 ;
}
return F_26 ( V_8 ) ;
}
static int F_30 ( struct V_7 * V_8 , unsigned char * V_77 , int V_79 )
{
int V_73 ;
* V_77 = 0 ;
F_19 ( V_8 , 1 ) ;
F_23 ( V_8 ) ;
for ( V_73 = 0 ; V_73 < 8 ; ++ V_73 ) {
F_17 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 1 ) ;
if ( ! F_24 ( V_8 , 1 ) ) {
F_28 ( L_12 ) ;
return - V_76 ;
}
* V_77 = ( ( * V_77 ) << 1 ) | F_22 ( V_8 ) ;
}
F_17 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
F_19 ( V_8 , V_79 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 1 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
F_27 ( L_13 , * V_77 ) ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 )
{
int V_80 ;
V_80 = F_22 ( V_8 ) ;
if ( V_80 != 1 ) {
F_27 ( L_14 ) ;
F_19 ( V_8 , 1 ) ;
if ( ! F_25 ( V_8 , 1 ) ) {
F_28 ( L_15 ) ;
return - V_76 ;
}
}
if ( F_20 ( V_8 ) != 1 ) {
F_17 ( V_8 , 1 ) ;
if ( ! F_24 ( V_8 , 1 ) ) {
F_28 ( L_16 ) ;
return - V_76 ;
}
}
F_19 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 )
{
int V_73 ;
if ( F_20 ( V_8 ) != 0 ) {
F_27 ( L_17 ) ;
F_17 ( V_8 , 0 ) ;
if ( ! F_24 ( V_8 , 0 ) ) {
F_28 ( L_18 ) ;
}
}
F_19 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 1 ) ;
if ( ! F_24 ( V_8 , 1 ) ) {
F_28 ( L_19 ) ;
return - V_76 ;
}
F_23 ( V_8 ) ;
F_19 ( V_8 , 1 ) ;
if ( ! F_25 ( V_8 , 1 ) ) {
F_28 ( L_20 ) ;
for ( V_73 = 0 ; V_73 < 16 ; ++ V_73 ) {
F_17 ( V_8 , 0 ) ;
F_23 ( V_8 ) ;
F_17 ( V_8 , 1 ) ;
F_23 ( V_8 ) ;
F_19 ( V_8 , 1 ) ;
}
F_25 ( V_8 , 1 ) ;
return - V_76 ;
}
return 0 ;
}
static int F_33 ( struct V_7 * V_8 , unsigned char V_10 , unsigned char * V_81 , T_1 V_82 , int V_83 )
{
int V_84 , V_75 = - V_76 ;
T_1 V_73 ;
for ( V_84 = 0 ; V_75 != 0 && V_84 < 8 ; ++ V_84 ) {
V_75 = F_31 ( V_8 ) ;
if ( V_75 == 0 ) {
V_75 = F_29 ( V_8 , V_10 << 1 ) ;
for ( V_73 = 0 ; V_75 == 0 && V_73 < V_82 ; ++ V_73 )
V_75 = F_29 ( V_8 , V_81 [ V_73 ] ) ;
}
if ( V_75 != 0 || V_83 ) {
F_32 ( V_8 ) ;
}
}
if ( V_75 )
F_28 ( L_21 , V_10 ) ;
return V_75 ;
}
static int F_34 ( struct V_7 * V_8 , unsigned char V_10 , unsigned char * V_81 , T_1 V_82 )
{
int V_84 , V_75 = - V_76 ;
T_1 V_73 ;
for ( V_84 = 0 ; V_75 != 0 && V_84 < 8 ; ++ V_84 ) {
V_75 = F_31 ( V_8 ) ;
if ( V_75 == 0 )
V_75 = F_29 ( V_8 , ( V_10 << 1 ) | 1 ) ;
for ( V_73 = 0 ; V_75 == 0 && V_73 < V_82 ; ++ V_73 ) {
V_75 = F_30 ( V_8 , & V_81 [ V_73 ] , V_73 == V_82 - 1 ) ;
}
F_32 ( V_8 ) ;
}
if ( V_75 )
F_28 ( L_22 , V_10 ) ;
return V_75 ;
}
static int F_35 ( struct V_13 * V_15 , struct V_85 * V_86 , int V_87 )
{
struct V_88 * V_52 = F_36 ( V_15 ) ;
struct V_7 * V_8 = F_37 ( V_52 ) ;
int V_89 ;
int V_73 ;
F_38 ( & V_8 -> V_90 ) ;
for ( V_73 = V_89 = 0 ; V_89 == 0 && V_73 < V_87 ; V_73 ++ ) {
if ( V_86 [ V_73 ] . V_91 & V_92 )
V_89 = F_34 ( V_8 , V_86 [ V_73 ] . V_10 , V_86 [ V_73 ] . V_93 , V_86 [ V_73 ] . V_82 ) ;
else {
int V_94 = ! ( V_73 + 1 < V_87 && V_86 [ V_73 + 1 ] . V_91 == V_92 ) ;
V_89 = F_33 ( V_8 , V_86 [ V_73 ] . V_10 , V_86 [ V_73 ] . V_93 , V_86 [ V_73 ] . V_82 , V_94 ) ;
}
}
F_39 ( & V_8 -> V_90 ) ;
return V_89 ? V_89 : V_87 ;
}
static T_1 F_40 ( struct V_13 * V_14 )
{
return V_95 | V_96 ;
}
static void F_41 ( void * V_81 , int V_68 )
{
struct V_7 * V_8 = (struct V_7 * ) V_81 ;
if ( V_68 )
V_8 -> V_97 |= 0x01 ;
else
V_8 -> V_97 &= ~ 0x01 ;
F_18 ( ~ V_8 -> V_97 , V_69 ) ;
}
static void F_42 ( void * V_81 , int V_68 )
{
struct V_7 * V_8 = (struct V_7 * ) V_81 ;
if ( V_68 )
V_8 -> V_97 |= 0x01 ;
else
V_8 -> V_97 &= ~ 0x01 ;
F_18 ( ~ V_8 -> V_97 , V_70 ) ;
}
static int F_43 ( void * V_81 )
{
struct V_7 * V_8 = (struct V_7 * ) V_81 ;
return F_21 ( V_71 ) & 1 ;
}
static int F_44 ( void * V_81 )
{
struct V_7 * V_8 = (struct V_7 * ) V_81 ;
return F_21 ( V_72 ) & 1 ;
}
int F_45 ( struct V_7 * V_8 )
{
int V_89 ;
F_28 ( L_23 ) ;
if ( F_9 ( V_49 ) != F_9 ( V_50 ) ) {
F_46 ( L_24 ) ;
return - V_98 ;
}
if ( V_8 -> V_99 . V_100 > 0 ) {
memcpy ( & V_8 -> V_15 , & V_101 ,
sizeof( struct V_13 ) ) ;
} else {
memcpy ( & V_8 -> V_15 , & V_102 ,
sizeof( struct V_13 ) ) ;
memcpy ( & V_8 -> V_103 , & V_104 ,
sizeof( struct V_105 ) ) ;
}
V_8 -> V_103 . V_106 = V_8 -> V_99 . V_107 / 2 ;
V_8 -> V_103 . V_81 = V_8 ;
V_8 -> V_15 . V_108 = & V_8 -> V_103 ;
sprintf ( V_8 -> V_15 . V_31 + strlen ( V_8 -> V_15 . V_31 ) , L_25 ,
V_8 -> V_109 ) ;
F_47 ( & V_8 -> V_15 , & V_8 -> V_52 ) ;
memcpy ( & V_8 -> V_45 , & V_110 ,
sizeof( struct V_45 ) ) ;
V_8 -> V_45 . V_111 = & V_8 -> V_15 ;
V_8 -> V_15 . V_112 . V_113 = & V_8 -> V_114 -> V_112 ;
F_28 ( L_26 ) ;
F_17 ( V_8 , 1 ) ;
F_19 ( V_8 , 1 ) ;
if ( V_8 -> V_99 . V_100 > 0 )
V_89 = F_48 ( & V_8 -> V_15 ) ;
else
V_89 = F_49 ( & V_8 -> V_15 ) ;
return V_89 ;
}
void F_50 ( struct V_7 * V_8 )
{
F_28 ( L_27 ) ;
F_51 ( & V_8 -> V_15 ) ;
}
