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
V_20 -> type = V_39 | V_43 |
V_44 ;
V_20 -> V_34 = V_11 -> V_40 ;
break;
case V_45 :
V_20 -> V_46 = F_1 ;
V_20 -> V_34 = V_11 -> V_40 ;
V_20 -> V_29 = V_47 ;
V_20 -> type = V_48 ;
break;
}
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 . V_49 = V_20 ;
F_5 ( V_15 . type , type , V_26 ) ;
return F_6 ( V_17 , & V_15 , V_22 , NULL ) == NULL ?
- 1 : 0 ;
}
struct V_50 * F_7 ( struct V_10 * V_11 )
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
int F_8 ( struct V_10 * V_11 , unsigned V_51 )
{
struct V_52 * V_53 ;
struct V_16 * V_17 = & V_11 -> V_18 ;
const char * type = V_54 [ V_51 ] ;
T_1 V_12 = 1 << V_51 ;
if ( V_12 == V_55 ) {
V_53 = F_9 ( & V_11 -> V_56 , V_17 , type , 0 ,
V_11 -> V_57 -> V_58 ) ;
if ( V_53 )
V_53 -> V_59 = 1 << V_51 ;
V_53 = F_9 ( & V_11 -> V_56 , V_17 , type , 0 ,
V_11 -> V_57 -> V_60 ) ;
if ( V_53 )
V_53 -> V_59 = 1 << V_51 ;
V_53 = F_9 ( & V_11 -> V_56 , V_17 , type , 0 ,
V_11 -> V_57 -> V_61 ) ;
if ( V_53 )
V_53 -> V_59 = 1 << V_51 ;
return V_53 ? 0 : - 1 ;
}
if ( V_12 & V_62 )
return F_4 ( V_11 , V_12 , type , V_63 [ V_51 ] ) ;
if ( ! V_63 [ V_51 ] )
return - 1 ;
if ( V_12 == V_64 || V_12 == V_65 ) {
V_53 = F_9 ( & V_11 -> V_56 ,
V_17 , type , 0 , F_10 ( V_63 [ V_51 ] ) ) ;
} else if ( V_12 == V_66 ) {
struct V_67 V_68 ;
struct V_14 V_69 = {
. type = L_3 ,
. V_13 = V_63 [ V_51 ] ,
. V_49 = & V_68 ,
} ;
V_68 . V_70 = V_11 -> V_70 ;
V_53 = F_11 ( & V_11 -> V_56 , V_17 ,
& V_69 , NULL ) ;
} else {
V_53 = F_9 ( & V_11 -> V_56 ,
V_17 , type , V_63 [ V_51 ] , NULL ) ;
}
if ( V_53 )
V_53 -> V_59 = 1 << V_51 ;
return V_53 ? 0 : - 1 ;
}
struct V_52 * F_12 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_52 * V_71 = NULL ;
struct V_52 * V_53 ;
F_13 ( & V_11 -> V_56 . V_72 ) ;
F_14 (sd, &itv->v4l2_dev) {
if ( V_53 -> V_59 == V_12 ) {
V_71 = V_53 ;
break;
}
}
F_15 ( & V_11 -> V_56 . V_72 ) ;
return V_71 ;
}
static void F_16 ( struct V_10 * V_11 , int V_73 )
{
F_17 ( ~ V_73 , V_74 ) ;
}
static void F_18 ( struct V_10 * V_11 , int V_73 )
{
F_17 ( ~ V_73 & 1 , V_75 ) ;
}
static int F_19 ( struct V_10 * V_11 )
{
return F_20 ( V_76 ) & 1 ;
}
static int F_21 ( struct V_10 * V_11 )
{
return F_20 ( V_77 ) & 1 ;
}
static void F_22 ( struct V_10 * V_11 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < 5 ; ++ V_78 )
F_19 ( V_11 ) ;
}
static int F_23 ( struct V_10 * V_11 , int V_79 )
{
int V_78 ;
F_22 ( V_11 ) ;
for ( V_78 = 0 ; V_78 < 1000 ; ++ V_78 ) {
if ( F_19 ( V_11 ) == V_79 )
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 , int V_79 )
{
int V_78 ;
F_22 ( V_11 ) ;
for ( V_78 = 0 ; V_78 < 1000 ; ++ V_78 ) {
if ( F_21 ( V_11 ) == V_79 )
return 1 ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_11 )
{
int V_80 = 0 ;
if ( F_19 ( V_11 ) == 1 ) {
F_26 ( L_4 ) ;
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_5 ) ;
return - V_81 ;
}
}
F_18 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 0 ) ) {
F_27 ( L_6 ) ;
V_80 = - V_81 ;
}
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_7 ) ;
V_80 = - V_81 ;
}
return V_80 ;
}
static int F_28 ( struct V_10 * V_11 , unsigned char V_82 )
{
int V_78 , V_83 ;
F_26 ( L_8 , V_82 ) ;
for ( V_78 = 0 ; V_78 < 8 ; ++ V_78 , V_82 <<= 1 ) {
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_9 ) ;
return - V_81 ;
}
V_83 = ( V_82 >> 7 ) & 1 ;
F_18 ( V_11 , V_83 ) ;
if ( ! F_24 ( V_11 , V_83 ) ) {
F_27 ( L_10 ) ;
return - V_81 ;
}
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_11 ) ;
return - V_81 ;
}
}
F_16 ( V_11 , 0 ) ;
if ( ! F_23 ( V_11 , 0 ) ) {
F_27 ( L_9 ) ;
return - V_81 ;
}
return F_25 ( V_11 ) ;
}
static int F_29 ( struct V_10 * V_11 , unsigned char * V_82 , int V_84 )
{
int V_78 ;
* V_82 = 0 ;
F_18 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
for ( V_78 = 0 ; V_78 < 8 ; ++ V_78 ) {
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_12 ) ;
return - V_81 ;
}
* V_82 = ( ( * V_82 ) << 1 ) | F_21 ( V_11 ) ;
}
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_18 ( V_11 , V_84 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_26 ( L_13 , * V_82 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 )
{
int V_85 ;
V_85 = F_21 ( V_11 ) ;
if ( V_85 != 1 ) {
F_26 ( L_14 ) ;
F_18 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 1 ) ) {
F_27 ( L_15 ) ;
return - V_81 ;
}
}
if ( F_19 ( V_11 ) != 1 ) {
F_16 ( V_11 , 1 ) ;
if ( ! F_23 ( V_11 , 1 ) ) {
F_27 ( L_16 ) ;
return - V_81 ;
}
}
F_18 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_10 * V_11 )
{
int V_78 ;
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
return - V_81 ;
}
F_22 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
if ( ! F_24 ( V_11 , 1 ) ) {
F_27 ( L_20 ) ;
for ( V_78 = 0 ; V_78 < 16 ; ++ V_78 ) {
F_16 ( V_11 , 0 ) ;
F_22 ( V_11 ) ;
F_16 ( V_11 , 1 ) ;
F_22 ( V_11 ) ;
F_18 ( V_11 , 1 ) ;
}
F_24 ( V_11 , 1 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_32 ( struct V_10 * V_11 , unsigned char V_13 , unsigned char * V_86 , T_1 V_87 , int V_88 )
{
int V_89 , V_80 = - V_81 ;
T_1 V_78 ;
for ( V_89 = 0 ; V_80 != 0 && V_89 < 8 ; ++ V_89 ) {
V_80 = F_30 ( V_11 ) ;
if ( V_80 == 0 ) {
V_80 = F_28 ( V_11 , V_13 << 1 ) ;
for ( V_78 = 0 ; V_80 == 0 && V_78 < V_87 ; ++ V_78 )
V_80 = F_28 ( V_11 , V_86 [ V_78 ] ) ;
}
if ( V_80 != 0 || V_88 ) {
F_31 ( V_11 ) ;
}
}
if ( V_80 )
F_27 ( L_21 , V_13 ) ;
return V_80 ;
}
static int F_33 ( struct V_10 * V_11 , unsigned char V_13 , unsigned char * V_86 , T_1 V_87 )
{
int V_89 , V_80 = - V_81 ;
T_1 V_78 ;
for ( V_89 = 0 ; V_80 != 0 && V_89 < 8 ; ++ V_89 ) {
V_80 = F_30 ( V_11 ) ;
if ( V_80 == 0 )
V_80 = F_28 ( V_11 , ( V_13 << 1 ) | 1 ) ;
for ( V_78 = 0 ; V_80 == 0 && V_78 < V_87 ; ++ V_78 ) {
V_80 = F_29 ( V_11 , & V_86 [ V_78 ] , V_78 == V_87 - 1 ) ;
}
F_31 ( V_11 ) ;
}
if ( V_80 )
F_27 ( L_22 , V_13 ) ;
return V_80 ;
}
static int F_34 ( struct V_16 * V_18 , struct V_90 * V_91 , int V_92 )
{
struct V_93 * V_56 = F_35 ( V_18 ) ;
struct V_10 * V_11 = F_36 ( V_56 ) ;
int V_94 ;
int V_78 ;
F_37 ( & V_11 -> V_95 ) ;
for ( V_78 = V_94 = 0 ; V_94 == 0 && V_78 < V_92 ; V_78 ++ ) {
if ( V_91 [ V_78 ] . V_96 & V_97 )
V_94 = F_33 ( V_11 , V_91 [ V_78 ] . V_13 , V_91 [ V_78 ] . V_98 , V_91 [ V_78 ] . V_87 ) ;
else {
int V_99 = ! ( V_78 + 1 < V_92 && V_91 [ V_78 + 1 ] . V_96 == V_97 ) ;
V_94 = F_32 ( V_11 , V_91 [ V_78 ] . V_13 , V_91 [ V_78 ] . V_98 , V_91 [ V_78 ] . V_87 , V_99 ) ;
}
}
F_38 ( & V_11 -> V_95 ) ;
return V_94 ? V_94 : V_92 ;
}
static T_1 F_39 ( struct V_16 * V_17 )
{
return V_100 | V_101 ;
}
static void F_40 ( void * V_86 , int V_73 )
{
struct V_10 * V_11 = (struct V_10 * ) V_86 ;
if ( V_73 )
V_11 -> V_102 |= 0x01 ;
else
V_11 -> V_102 &= ~ 0x01 ;
F_17 ( ~ V_11 -> V_102 , V_74 ) ;
}
static void F_41 ( void * V_86 , int V_73 )
{
struct V_10 * V_11 = (struct V_10 * ) V_86 ;
if ( V_73 )
V_11 -> V_102 |= 0x01 ;
else
V_11 -> V_102 &= ~ 0x01 ;
F_17 ( ~ V_11 -> V_102 , V_75 ) ;
}
static int F_42 ( void * V_86 )
{
struct V_10 * V_11 = (struct V_10 * ) V_86 ;
return F_20 ( V_76 ) & 1 ;
}
static int F_43 ( void * V_86 )
{
struct V_10 * V_11 = (struct V_10 * ) V_86 ;
return F_20 ( V_77 ) & 1 ;
}
int F_44 ( struct V_10 * V_11 )
{
int V_94 ;
F_27 ( L_23 ) ;
if ( F_45 ( V_54 ) != F_45 ( V_63 ) ) {
F_46 ( L_24 ) ;
return - V_103 ;
}
if ( V_11 -> V_104 . V_105 > 0 ) {
V_11 -> V_18 = V_106 ;
} else {
V_11 -> V_18 = V_107 ;
V_11 -> V_108 = V_109 ;
}
V_11 -> V_108 . V_110 = V_11 -> V_104 . V_111 / 2 ;
V_11 -> V_108 . V_86 = V_11 ;
V_11 -> V_18 . V_112 = & V_11 -> V_108 ;
sprintf ( V_11 -> V_18 . V_34 + strlen ( V_11 -> V_18 . V_34 ) , L_25 ,
V_11 -> V_113 ) ;
F_47 ( & V_11 -> V_18 , & V_11 -> V_56 ) ;
V_11 -> V_50 = V_114 ;
V_11 -> V_50 . V_115 = & V_11 -> V_18 ;
V_11 -> V_18 . V_116 . V_117 = & V_11 -> V_118 -> V_116 ;
F_27 ( L_26 ) ;
F_16 ( V_11 , 1 ) ;
F_18 ( V_11 , 1 ) ;
if ( V_11 -> V_104 . V_105 > 0 )
V_94 = F_48 ( & V_11 -> V_18 ) ;
else
V_94 = F_49 ( & V_11 -> V_18 ) ;
return V_94 ;
}
void F_50 ( struct V_10 * V_11 )
{
F_27 ( L_27 ) ;
F_51 ( & V_11 -> V_18 ) ;
}
