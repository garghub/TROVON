static int F_1 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_6 )
{
unsigned char V_7 [ 4 ] ;
V_7 [ 0 ] = 0x00 ;
F_2 ( V_2 -> V_8 , V_7 , 1 ) ;
if ( F_3 ( V_2 -> V_8 , V_7 , sizeof( V_7 ) ) != sizeof( V_7 ) ) {
return 0 ;
}
if ( V_7 [ 2 ] == 0xff )
return 0 ;
V_7 [ 2 ] &= 0x7f ;
V_7 [ 3 ] |= 0x80 ;
* V_4 = V_9 ;
* V_5 = V_7 [ 3 ] | V_7 [ 2 ] << 8 | V_7 [ 1 ] << 16 | V_7 [ 0 ] << 24 ;
* V_6 = 0 ;
return 1 ;
}
static int F_4 ( struct V_10 * V_11 , T_1 V_12 , const char * type , T_2 V_13 )
{
struct V_14 V_15 ;
struct V_16 * V_17 = & V_11 -> V_18 ;
struct V_19 * V_20 = & V_11 -> V_21 ;
unsigned short V_22 [ 2 ] = { V_13 , V_23 } ;
if ( V_12 & V_24 ) {
if ( V_11 -> V_25 & V_24 )
return - 1 ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
F_5 ( V_15 . type , type , V_26 ) ;
return F_6 ( V_17 , & V_15 , V_22 , NULL )
== NULL ? - 1 : 0 ;
}
if ( V_11 -> V_25 & V_27 )
return - 1 ;
switch ( V_12 ) {
case V_28 :
V_20 -> V_29 = V_30 ;
V_20 -> V_31 =
V_32 ;
V_20 -> type = V_33 ;
V_20 -> V_34 = L_1 ;
break;
case V_35 :
case V_36 :
V_20 -> V_29 = V_37 ;
V_20 -> V_31 = V_38 ;
V_20 -> type = V_39 ;
V_20 -> V_34 = V_11 -> V_40 ;
break;
case V_41 :
V_20 -> V_29 = V_37 ;
V_20 -> V_31 = V_42 ;
V_20 -> type = V_39 ;
V_20 -> V_34 = V_11 -> V_40 ;
break;
case V_43 :
V_20 -> V_44 = F_1 ;
V_20 -> V_34 = V_11 -> V_40 ;
V_20 -> V_29 = V_45 ;
V_20 -> type = V_46 ;
break;
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_47 = V_20 ;
F_5 ( V_15 . type , type , V_26 ) ;
return F_6 ( V_17 , & V_15 , V_22 , NULL ) == NULL ?
- 1 : 0 ;
}
struct V_48 * F_7 ( struct V_10 * V_11 )
{
struct V_14 V_15 ;
const unsigned short V_22 [] = {
0x1a ,
0x18 ,
V_23
} ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
F_5 ( V_15 . type , L_2 , V_26 ) ;
return F_6 ( & V_11 -> V_18 , & V_15 , V_22 , NULL ) ;
}
int F_8 ( struct V_10 * V_11 , unsigned V_49 )
{
struct V_50 * V_51 ;
struct V_16 * V_17 = & V_11 -> V_18 ;
const char * type = V_52 [ V_49 ] ;
T_1 V_12 = 1 << V_49 ;
if ( V_12 == V_53 ) {
V_51 = F_9 ( & V_11 -> V_54 , V_17 , type , 0 ,
V_11 -> V_55 -> V_56 ) ;
if ( V_51 )
V_51 -> V_57 = 1 << V_49 ;
V_51 = F_9 ( & V_11 -> V_54 , V_17 , type , 0 ,
V_11 -> V_55 -> V_58 ) ;
if ( V_51 )
V_51 -> V_57 = 1 << V_49 ;
V_51 = F_9 ( & V_11 -> V_54 , V_17 , type , 0 ,
V_11 -> V_55 -> V_59 ) ;
if ( V_51 )
V_51 -> V_57 = 1 << V_49 ;
return V_51 ? 0 : - 1 ;
}
if ( V_12 & V_60 )
return F_4 ( V_11 , V_12 , type , V_61 [ V_49 ] ) ;
if ( ! V_61 [ V_49 ] )
return - 1 ;
if ( V_12 == V_62 || V_12 == V_63 ) {
V_51 = F_9 ( & V_11 -> V_54 ,
V_17 , type , 0 , F_10 ( V_61 [ V_49 ] ) ) ;
} else if ( V_12 == V_64 ) {
struct V_65 V_66 ;
struct V_14 V_67 = {
. type = L_3 ,
. V_13 = V_61 [ V_49 ] ,
. V_47 = & V_66 ,
} ;
V_66 . V_68 = V_11 -> V_68 ;
V_51 = F_11 ( & V_11 -> V_54 , V_17 ,
& V_67 , NULL ) ;
} else {
V_51 = F_9 ( & V_11 -> V_54 ,
V_17 , type , V_61 [ V_49 ] , NULL ) ;
}
if ( V_51 )
V_51 -> V_57 = 1 << V_49 ;
return V_51 ? 0 : - 1 ;
}
struct V_50 * F_12 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_50 * V_69 = NULL ;
struct V_50 * V_51 ;
F_13 ( & V_11 -> V_54 . V_70 ) ;
F_14 (sd, &itv->v4l2_dev) {
if ( V_51 -> V_57 == V_12 ) {
V_69 = V_51 ;
break;
}
}
F_15 ( & V_11 -> V_54 . V_70 ) ;
return V_69 ;
}
static void F_16 ( struct V_10 * V_11 , int V_71 )
{
F_17 ( ~ V_71 , V_72 ) ;
}
static void F_18 ( struct V_10 * V_11 , int V_71 )
{
F_17 ( ~ V_71 & 1 , V_73 ) ;
}
static int F_19 ( struct V_10 * V_11 )
{
return F_20 ( V_74 ) & 1 ;
}
static int F_21 ( struct V_10 * V_11 )
{
return F_20 ( V_75 ) & 1 ;
}
static void F_22 ( struct V_10 * V_11 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < 5 ; ++ V_76 )
F_19 ( V_11 ) ;
}
static int F_23 ( struct V_10 * V_11 , int V_77 )
{
int V_76 ;
F_22 ( V_11 ) ;
for ( V_76 = 0 ; V_76 < 1000 ; ++ V_76 ) {
if ( F_19 ( V_11 ) == V_77 )
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 , int V_77 )
{
int V_76 ;
F_22 ( V_11 ) ;
for ( V_76 = 0 ; V_76 < 1000 ; ++ V_76 ) {
if ( F_21 ( V_11 ) == V_77 )
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
int V_78 = 0 ;
if ( F_19 ( V_11 ) == 1 ) {
F_26 ( L_4 ) ;
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_5 ) ;
return - V_79 ;
}
}
F_18 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 0 ) ) {
F_27 ( L_6 ) ;
V_78 = - V_79 ;
}
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_7 ) ;
V_78 = - V_79 ;
}
return V_78 ;
}
static int F_28 ( struct V_10 * V_11 , unsigned char V_80 )
{
int V_76 , V_81 ;
F_26 ( L_8 , V_80 ) ;
for ( V_76 = 0 ; V_76 < 8 ; ++ V_76 , V_80 <<= 1 ) {
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_9 ) ;
return - V_79 ;
}
V_81 = ( V_80 >> 7 ) & 1 ;
F_18 ( V_11 , V_81 ) ;
if ( ! F_24 ( V_11 , V_81 ) ) {
F_27 ( L_10 ) ;
return - V_79 ;
}
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_11 ) ;
return - V_79 ;
}
}
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_9 ) ;
return - V_79 ;
}
return F_25 ( V_11 ) ;
}
static int F_29 ( struct V_10 * V_11 , unsigned char * V_80 , int V_82 )
{
int V_76 ;
* V_80 = 0 ;
F_18 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
for ( V_76 = 0 ; V_76 < 8 ; ++ V_76 ) {
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_12 ) ;
return - V_79 ;
}
* V_80 = ( ( * V_80 ) << 1 ) | F_21 ( V_11 ) ;
}
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_18 ( V_11 , V_82 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_26 ( L_13 , * V_80 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_83 ;
V_83 = F_21 ( V_11 ) ;
if ( V_83 != 1 ) {
F_26 ( L_14 ) ;
F_18 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 1 ) ) {
F_27 ( L_15 ) ;
return - V_79 ;
}
}
if ( F_19 ( V_11 ) != 1 ) {
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_16 ) ;
return - V_79 ;
}
}
F_18 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 )
{
int V_76 ;
if ( F_19 ( V_11 ) != 0 ) {
F_26 ( L_17 ) ;
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_18 ) ;
}
}
F_18 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_19 ) ;
return - V_79 ;
}
F_22 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 1 ) ) {
F_27 ( L_20 ) ;
for ( V_76 = 0 ; V_76 < 16 ; ++ V_76 ) {
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
}
F_24 ( V_11 , 1 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_11 , unsigned char V_13 , unsigned char * V_84 , T_1 V_85 , int V_86 )
{
int V_87 , V_78 = - V_79 ;
T_1 V_76 ;
for ( V_87 = 0 ; V_78 != 0 && V_87 < 8 ; ++ V_87 ) {
V_78 = F_30 ( V_11 ) ;
if ( V_78 == 0 ) {
V_78 = F_28 ( V_11 , V_13 << 1 ) ;
for ( V_76 = 0 ; V_78 == 0 && V_76 < V_85 ; ++ V_76 )
V_78 = F_28 ( V_11 , V_84 [ V_76 ] ) ;
}
if ( V_78 != 0 || V_86 ) {
F_31 ( V_11 ) ;
}
}
if ( V_78 )
F_27 ( L_21 , V_13 ) ;
return V_78 ;
}
static int F_33 ( struct V_10 * V_11 , unsigned char V_13 , unsigned char * V_84 , T_1 V_85 )
{
int V_87 , V_78 = - V_79 ;
T_1 V_76 ;
for ( V_87 = 0 ; V_78 != 0 && V_87 < 8 ; ++ V_87 ) {
V_78 = F_30 ( V_11 ) ;
if ( V_78 == 0 )
V_78 = F_28 ( V_11 , ( V_13 << 1 ) | 1 ) ;
for ( V_76 = 0 ; V_78 == 0 && V_76 < V_85 ; ++ V_76 ) {
V_78 = F_29 ( V_11 , & V_84 [ V_76 ] , V_76 == V_85 - 1 ) ;
}
F_31 ( V_11 ) ;
}
if ( V_78 )
F_27 ( L_22 , V_13 ) ;
return V_78 ;
}
static int F_34 ( struct V_16 * V_18 , struct V_88 * V_89 , int V_90 )
{
struct V_91 * V_54 = F_35 ( V_18 ) ;
struct V_10 * V_11 = F_36 ( V_54 ) ;
int V_92 ;
int V_76 ;
F_37 ( & V_11 -> V_93 ) ;
for ( V_76 = V_92 = 0 ; V_92 == 0 && V_76 < V_90 ; V_76 ++ ) {
if ( V_89 [ V_76 ] . V_94 & V_95 )
V_92 = F_33 ( V_11 , V_89 [ V_76 ] . V_13 , V_89 [ V_76 ] . V_96 , V_89 [ V_76 ] . V_85 ) ;
else {
int V_97 = ! ( V_76 + 1 < V_90 && V_89 [ V_76 + 1 ] . V_94 == V_95 ) ;
V_92 = F_32 ( V_11 , V_89 [ V_76 ] . V_13 , V_89 [ V_76 ] . V_96 , V_89 [ V_76 ] . V_85 , V_97 ) ;
}
}
F_38 ( & V_11 -> V_93 ) ;
return V_92 ? V_92 : V_90 ;
}
static T_1 F_39 ( struct V_16 * V_17 )
{
return V_98 | V_99 ;
}
static void F_40 ( void * V_84 , int V_71 )
{
struct V_10 * V_11 = (struct V_10 * ) V_84 ;
if ( V_71 )
V_11 -> V_100 |= 0x01 ;
else
V_11 -> V_100 &= ~ 0x01 ;
F_17 ( ~ V_11 -> V_100 , V_72 ) ;
}
static void F_41 ( void * V_84 , int V_71 )
{
struct V_10 * V_11 = (struct V_10 * ) V_84 ;
if ( V_71 )
V_11 -> V_100 |= 0x01 ;
else
V_11 -> V_100 &= ~ 0x01 ;
F_17 ( ~ V_11 -> V_100 , V_73 ) ;
}
static int F_42 ( void * V_84 )
{
struct V_10 * V_11 = (struct V_10 * ) V_84 ;
return F_20 ( V_74 ) & 1 ;
}
static int F_43 ( void * V_84 )
{
struct V_10 * V_11 = (struct V_10 * ) V_84 ;
return F_20 ( V_75 ) & 1 ;
}
int F_44 ( struct V_10 * V_11 )
{
int V_92 ;
F_27 ( L_23 ) ;
if ( F_45 ( V_52 ) != F_45 ( V_61 ) ) {
F_46 ( L_24 ) ;
return - V_101 ;
}
if ( V_11 -> V_102 . V_103 > 0 ) {
V_11 -> V_18 = V_104 ;
} else {
V_11 -> V_18 = V_105 ;
V_11 -> V_106 = V_107 ;
}
V_11 -> V_106 . V_108 = V_11 -> V_102 . V_109 / 2 ;
V_11 -> V_106 . V_84 = V_11 ;
V_11 -> V_18 . V_110 = & V_11 -> V_106 ;
sprintf ( V_11 -> V_18 . V_34 + strlen ( V_11 -> V_18 . V_34 ) , L_25 ,
V_11 -> V_111 ) ;
F_47 ( & V_11 -> V_18 , & V_11 -> V_54 ) ;
V_11 -> V_48 = V_112 ;
V_11 -> V_48 . V_113 = & V_11 -> V_18 ;
V_11 -> V_18 . V_114 . V_115 = & V_11 -> V_116 -> V_114 ;
F_27 ( L_26 ) ;
F_16 ( V_11 , 1 ) ;
F_18 ( V_11 , 1 ) ;
if ( V_11 -> V_102 . V_103 > 0 )
V_92 = F_48 ( & V_11 -> V_18 ) ;
else
V_92 = F_49 ( & V_11 -> V_18 ) ;
return V_92 ;
}
void F_50 ( struct V_10 * V_11 )
{
F_27 ( L_27 ) ;
F_51 ( & V_11 -> V_18 ) ;
}
