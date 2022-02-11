static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
struct V_11 * V_12 = (struct V_11 * )
V_2 -> V_7 -> V_8 -> V_13 [ V_2 -> V_10 ] ;
struct V_14 * V_15 ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_15 = F_2 ( V_17 , V_2 -> V_18 , V_12 , V_4 ) ;
if ( V_15 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_1 ) ;
return - V_19 ;
}
V_6 -> V_20 = V_15 -> V_20 ;
V_6 -> V_21 = V_15 -> V_21 ;
V_6 -> V_22 = V_15 -> V_22 ;
V_6 -> V_23 = V_15 -> V_23 ;
V_6 -> V_24 = V_15 -> V_24 ;
V_6 -> V_25 = V_15 -> V_25 ;
V_6 -> V_26 = V_15 -> V_26 ;
V_6 -> V_27 = V_15 -> V_27 ;
V_6 -> V_28 = V_15 -> V_28 ;
V_6 -> V_29 = V_15 -> V_29 ;
V_6 -> V_30 = V_15 -> V_30 ;
return 0 ;
}
static int F_4 ( struct V_31 * V_18 , int V_32 )
{
struct V_1 * V_2 = V_18 -> V_33 ;
int V_34 ;
if ( V_32 ) {
F_5 ( & V_2 -> V_7 -> V_35 ) ;
V_34 = V_2 -> V_36 ( V_18 , 1 ) ;
} else {
V_34 = V_2 -> V_36 ( V_18 , 0 ) ;
F_6 ( & V_2 -> V_7 -> V_35 ) ;
}
return V_34 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_31 * V_18 ;
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
if ( V_2 -> V_18 -> V_37 . V_38 )
V_2 -> V_18 -> V_37 . V_38 ( V_2 -> V_18 , 1 ) ;
V_18 = F_2 ( V_39 , V_2 -> V_18 , V_4 , 0x60 ) ;
if ( V_2 -> V_18 -> V_37 . V_38 )
V_2 -> V_18 -> V_37 . V_38 ( V_2 -> V_18 , 0 ) ;
if ( ! V_18 ) {
F_3 ( V_40 L_2 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 == 0 )
return F_1 ( V_2 ) ;
if ( V_2 -> V_41 == 1 )
return F_7 ( V_2 ) ;
return - V_42 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
V_2 -> V_18 = F_2 ( V_43 , V_6 , V_4 ,
( V_2 -> V_10 & 1 ) == 0 ? V_44
: V_45 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_3 ) ;
return - V_19 ;
}
if ( V_6 -> V_46 )
V_2 -> V_18 -> V_47 = V_2 ;
if ( ! F_2 ( V_48 , V_2 -> V_18 , V_4 , 0 ,
0 , V_2 -> V_7 -> V_8 -> V_49 [ V_2 -> V_10 ] ) ) {
F_3 (KERN_ERR DEVICE_NAME L_4 ) ;
F_10 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
return - V_19 ;
}
return 0 ;
}
static void F_11 ( struct V_31 * V_18 , int V_50 )
{
struct V_1 * V_2 = V_18 -> V_47 ;
if ( V_50 )
F_5 ( & V_2 -> V_7 -> V_35 ) ;
else
F_6 ( & V_2 -> V_7 -> V_35 ) ;
}
static int F_12 ( struct V_3 * V_51 , T_1 V_52 , T_1 * V_53 )
{
struct V_54 V_55 [ 1 ] = { { . V_56 = V_52 , . V_57 = V_58 ,
. V_59 = V_53 , . V_60 = 1 } } ;
return ( F_13 ( V_51 , V_55 , 1 ) == 1 ) ? 0 : - 1 ;
}
static int F_14 ( struct V_3 * V_51 , T_1 V_52 ,
T_2 V_61 , T_1 * V_53 )
{
T_1 V_62 [ 2 ] = { V_61 >> 8 , V_61 & 0xff } ;
struct V_54 V_55 [ 2 ] = { { . V_56 = V_52 , . V_57 = 0 ,
. V_59 = V_62 , . V_60 = 2 } ,
{ . V_56 = V_52 , . V_57 = V_58 ,
. V_59 = V_53 , . V_60 = 1 } } ;
return ( F_13 ( V_51 , V_55 , 2 ) == 2 ) ? 0 : - 1 ;
}
static int F_15 ( struct V_3 * V_4 , int V_63 )
{
T_1 V_53 ;
if ( F_14 ( V_4 , 0x68 + V_63 / 2 , 0xf100 , & V_53 ) < 0 )
return 0 ;
return 1 ;
}
static int F_16 ( struct V_3 * V_4 , int V_63 )
{
T_1 V_53 ;
if ( F_12 ( V_4 , 0x29 + V_63 , & V_53 ) < 0 )
return 0 ;
return 1 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_64 V_65 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_66 = L_5 ;
V_65 . V_67 = 4 ;
V_65 . V_52 = 0x29 + ( V_2 -> V_10 ^ 2 ) ;
V_2 -> V_18 = F_2 ( V_68 , & V_65 , V_4 ) ;
if ( ! V_2 -> V_18 ) {
F_3 ( V_40 L_6 ) ;
return - V_19 ;
}
V_2 -> V_18 -> V_33 = V_2 ;
V_2 -> V_36 = V_2 -> V_18 -> V_37 . V_38 ;
V_2 -> V_18 -> V_37 . V_38 = F_4 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_69 ;
T_1 V_59 [ 3 ] ;
struct V_54 V_54 = { . V_57 = 0 , . V_59 = V_59 } ;
int V_70 ;
if ( V_2 -> V_10 < 2 )
V_4 = & V_2 -> V_7 -> V_16 [ 0 ] . V_3 ;
else
V_4 = & V_2 -> V_7 -> V_16 [ 1 ] . V_3 ;
if ( F_15 ( V_4 , V_2 -> V_10 ) ) {
V_2 -> V_41 = 0 ;
V_69 = V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
V_70 = F_9 ( V_2 ) ;
if ( V_70 < 0 || V_2 -> V_10 < 2 )
return V_70 ;
V_54 . V_56 = V_69 -> V_71 ;
V_54 . V_60 = 3 ;
V_59 [ 0 ] = 0xf1 ;
switch ( V_2 -> V_10 ) {
case 2 :
V_59 [ 1 ] = 0x5c ;
V_59 [ 2 ] = 0xc2 ;
break;
case 3 :
V_59 [ 1 ] = 0x61 ;
V_59 [ 2 ] = 0xcc ;
break;
default:
return - V_19 ;
}
V_70 = F_13 ( V_4 , & V_54 , 1 ) ;
if ( V_70 != 1 ) {
F_3 (KERN_ERR DEVICE_NAME L_7 ) ;
return - V_72 ;
}
} else if ( F_16 ( V_4 , V_2 -> V_10 ^ 2 ) ) {
V_2 -> V_41 = 1 ;
F_17 ( V_2 , V_4 ) ;
} else {
F_3 ( V_40 L_8 , V_2 -> V_10 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
V_2 -> V_18 = F_2 ( V_73 , & V_74 , & V_2 -> V_3 ) ;
if ( V_2 -> V_18 == NULL ) {
F_3 (KERN_ERR DEVICE_NAME L_9 ) ;
return - V_19 ;
}
F_2 ( V_75 , V_2 -> V_18 , & V_2 -> V_3 ,
& V_76 , 0 ) ;
return ( V_2 -> V_18 ) ? 0 : - V_19 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_77 * V_6 ;
V_6 = V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
V_2 -> V_18 = F_2 ( V_78 , V_6 , V_2 ,
& V_2 -> V_3 , & V_2 -> V_7 -> V_79 -> V_7 ) ;
if ( ! V_2 -> V_18 ) {
F_21 ( L_10 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_77 * V_6 ;
V_6 = V_2 -> V_7 -> V_8 -> V_9 [ V_2 -> V_10 ] ;
if ( ! F_2 ( V_80 , V_2 -> V_18 , V_6 -> V_81 ,
& V_2 -> V_3 ,
V_6 -> V_82 ) ) {
F_21 ( L_11 , V_6 -> V_82 ) ;
return - V_19 ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_51 ,
T_1 V_52 , T_2 V_61 , T_1 V_83 )
{
T_1 V_84 [ 3 ] = { ( V_61 >> 8 ) , ( V_61 & 0xff ) , V_83 } ;
struct V_54 V_62 = { . V_56 = V_52 , . V_57 = 0 , . V_59 = V_84 ,
. V_60 = sizeof( V_84 ) } ;
if ( F_13 ( V_51 , & V_62 , 1 ) != 1 ) {
F_21 ( V_85 L_12 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_51 ,
T_1 V_52 , T_2 V_61 , T_1 * V_83 , int V_60 )
{
T_1 V_62 [ 2 ] = { ( V_61 >> 8 ) , ( V_61 & 0xff ) } ;
struct V_54 V_55 [ 2 ] = { { . V_56 = V_52 , . V_57 = 0 ,
. V_59 = V_62 , . V_60 = 2 } ,
{ . V_56 = V_52 , . V_57 = V_58 ,
. V_59 = V_83 , . V_60 = V_60 } } ;
if ( F_13 ( V_51 , V_55 , 2 ) != 2 ) {
F_21 ( V_85 L_13 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_51 ,
T_2 V_86 , T_3 V_87 , T_1 * V_83 , T_3 * V_88 )
{
int V_34 = 0 ;
T_2 V_89 = V_90 , V_91 , V_92 = 0 ;
T_1 V_93 [ 3 ] ;
while ( V_89 + sizeof( T_2 ) + 1 < V_94 ) {
if ( F_24 ( V_51 , 0x50 , V_89 , V_93 , sizeof( V_93 ) ) )
return - 1 ;
V_92 = ( V_93 [ 0 ] << 8 ) | V_93 [ 1 ] ;
if ( V_92 == V_95 || V_92 == V_96 )
return - 1 ;
if ( V_92 == V_86 )
break;
V_89 += sizeof( T_2 ) + 1 + V_93 [ 2 ] ;
}
if ( V_89 + sizeof( T_2 ) + 1 + V_93 [ 2 ] > V_94 ) {
F_21 ( V_85
L_14 ,
V_92 , V_93 [ 2 ] ) ;
return - 1 ;
}
V_91 = V_93 [ 2 ] ;
if ( V_91 > V_87 )
V_91 = ( T_2 ) V_87 ;
if ( V_91 > 0 ) {
V_89 += sizeof( T_2 ) + 1 ;
V_34 = F_24 ( V_51 , 0x50 , V_89 , V_83 , V_91 ) ;
if ( ! V_34 ) {
* V_88 = V_93 [ 2 ] ;
#if 0
if (Length < EETag[2])
status = STATUS_BUFFER_OVERFLOW;
#endif
}
}
return V_34 ;
}
static int F_26 ( struct V_3 * V_51 ,
T_2 V_86 , T_3 V_91 , T_1 * V_83 )
{
int V_34 = 0 ;
T_2 V_89 = V_90 ;
T_1 V_93 [ 3 ] ;
T_2 V_92 = 0 ;
int V_97 , V_98 ;
while ( V_89 + sizeof( T_2 ) + 1 < V_94 ) {
if ( F_24 ( V_51 , 0x50 , V_89 , V_93 , sizeof( V_93 ) ) )
return - 1 ;
V_92 = ( V_93 [ 0 ] << 8 ) | V_93 [ 1 ] ;
if ( V_92 == V_95 || V_92 == V_96 )
return - 1 ;
if ( V_92 == V_86 )
break;
V_89 += sizeof( T_2 ) + 1 + V_93 [ 2 ] ;
}
if ( V_89 + sizeof( T_2 ) + 1 + V_93 [ 2 ] > V_94 ) {
F_21 ( V_85
L_14 ,
V_92 , V_93 [ 2 ] ) ;
return - 1 ;
}
if ( V_91 > V_93 [ 2 ] )
return - V_42 ;
V_89 += sizeof( T_2 ) + 1 ;
for ( V_98 = 0 ; V_98 < V_91 ; V_98 ++ , V_89 ++ ) {
V_34 = F_23 ( V_51 , 0x50 , V_89 , V_83 [ V_98 ] ) ;
if ( V_34 )
break;
V_97 = 10 ;
while ( V_97 ) {
T_1 V_99 ;
F_27 ( 50 ) ;
V_34 = F_24 ( V_51 , 0x50 , V_89 , & V_99 , 1 ) ;
if ( V_34 )
break;
if ( V_99 != V_83 [ V_98 ] )
F_21 ( V_85
L_15 ) ;
V_97 -= 1 ;
}
if ( V_34 ) {
F_21 ( V_85
L_16 ) ;
break;
}
}
return V_34 ;
}
static int F_28 ( struct V_3 * V_51 , T_2 V_92 , T_2 * V_83 )
{
int V_100 ;
T_1 V_59 [ 2 ] ;
T_3 V_60 = 0 ;
V_100 = F_25 ( V_51 , V_92 , 2 , V_59 , & V_60 ) ;
if ( V_100 )
return V_100 ;
if ( V_60 != 2 )
return - V_42 ;
* V_83 = ( V_59 [ 0 ] << 8 ) | V_59 [ 1 ] ;
return 0 ;
}
static int F_29 ( struct V_3 * V_51 , T_2 V_92 , T_2 V_83 )
{
int V_100 ;
T_1 V_59 [ 2 ] ;
V_59 [ 0 ] = V_83 >> 8 ;
V_59 [ 1 ] = V_83 & 0xff ;
V_100 = F_26 ( V_51 , V_92 , 2 , V_59 ) ;
if ( V_100 )
return V_100 ;
return 0 ;
}
static T_4 F_30 ( void * V_101 , T_4 V_102 , int V_103 )
{
struct V_1 * V_2 = V_101 ;
struct V_3 * V_104 = & V_2 -> V_3 ;
T_2 V_83 = 0 ;
if ( V_103 ) {
V_83 = ( T_2 ) V_102 ;
F_31 ( V_85 L_17 ,
V_102 ) ;
F_29 ( V_104 , 0x1000 + V_2 -> V_10 , V_83 ) ;
} else {
if ( F_28 ( V_104 , 0x1000 + V_2 -> V_10 , & V_83 ) )
V_83 = 0 ;
F_31 ( V_85 L_18 ,
( T_4 ) V_83 ) ;
}
return ( T_4 ) V_83 ;
}
static T_5 F_32 ( struct V_79 * V_7 ,
enum V_105 V_106 )
{
F_3 (KERN_ERR DEVICE_NAME L_19 ) ;
if ( V_106 == V_107 )
return V_108 ;
if ( V_106 == V_109 )
return V_110 ;
return V_111 ;
}
static T_5 F_33 ( struct V_79 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_20 ) ;
return 0 ;
}
static T_5 F_34 ( struct V_79 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_21 ) ;
return 0 ;
}
static void F_35 ( struct V_79 * V_7 )
{
F_3 (KERN_INFO DEVICE_NAME L_22 ) ;
}
static T_6 int F_36 ( void )
{
F_3 ( V_112
L_23 ) ;
return F_37 ( & V_113 ) ;
}
static T_7 void F_38 ( void )
{
F_39 ( & V_113 ) ;
}
