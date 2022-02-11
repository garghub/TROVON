static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
V_4 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_4 != V_10 )
break;
F_3 ( 1 ) ;
}
if ( V_4 != V_10 ) {
F_4 ( V_4 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
return 0 ;
}
return - 1 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 , V_13 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 , V_13 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
if ( V_14 & V_15 )
F_9 ( V_2 ,
V_14 & ~ V_15 ) ;
else
F_10 ( V_2 , V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 ;
while ( ( V_4 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ) !=
V_10 ) {
if ( V_4 & V_16 )
F_8 ( V_2 , V_4 ) ;
else {
struct V_17 T_2 * V_18 ;
V_18 = (struct V_17 T_2 * )
( ( char T_2 * ) V_2 -> V_6 . V_7 . V_8 + V_4 ) ;
if ( F_2 ( & V_18 -> V_19 ) & V_20 ) {
if ( F_2 ( & V_18 -> V_21 ) )
F_8 ( V_2 , V_4 ) ;
else
F_4 ( 1 , & V_18 -> V_21 ) ;
}
else
F_8 ( V_2 , V_4 ) ;
}
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_22 T_2 * V_8 = V_2 -> V_6 . V_7 . V_8 ;
void T_2 * V_23 = V_2 -> V_6 . V_7 . V_23 ;
T_1 V_24 ;
int V_25 = 0 ;
if ( V_23 && F_2 ( V_23 + 0x11C5C ) & 0xf )
F_4 ( 1 , V_23 + 0x11C60 ) ;
V_24 = F_2 ( & V_8 -> V_12 ) ;
if ( V_24 & V_26 ) {
T_1 V_27 = F_2 ( & V_8 -> V_28 ) ;
F_13 ( L_1 , V_27 ) ;
F_4 ( V_26 , & V_8 -> V_12 ) ;
F_14 ( V_2 , V_27 ) ;
V_25 = 1 ;
}
if ( V_24 & V_29 ) {
F_11 ( V_2 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static T_3 F_15 ( struct V_30 T_2 * V_31 )
{
T_1 V_32 = F_2 ( & V_31 -> V_32 ) ;
T_1 V_33 = F_2 ( & V_31 -> V_33 ) ;
if ( V_32 != V_33 ) {
T_3 V_18 ;
F_16 ( & V_18 , & V_31 -> V_34 [ V_31 -> V_32 ] , 8 ) ;
V_32 ++ ;
if ( V_32 == V_35 )
V_32 = 0 ;
F_4 ( V_32 , & V_31 -> V_32 ) ;
return V_18 ;
} else
return 0 ;
}
static void F_17 ( T_3 V_18 , struct V_1 * V_2 )
{
T_1 V_36 = F_2 ( & V_2 -> V_6 . V_37 . V_31 -> V_36 ) ;
T_1 V_38 = V_36 + 1 ;
if ( V_38 == V_35 )
V_38 = 0 ;
F_18 ( & V_2 -> V_6 . V_37 . V_31 -> V_39 [ V_36 ] , & V_18 , 8 ) ;
F_4 ( V_38 , & V_2 -> V_6 . V_37 . V_31 -> V_36 ) ;
F_4 ( V_40 ,
& V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 V_14 )
{
T_1 V_43 = ( V_14 >> 5 ) & 0x7 ;
struct V_44 * V_4 ;
F_13 ( L_2 , V_14 ) ;
F_20 ( ( V_14 & V_45 ) == 0 ) ;
switch ( V_43 ) {
case V_46 :
case V_47 :
V_2 -> V_48 = 1 ;
break;
case V_49 :
V_4 = V_2 -> V_50 [ V_14 >> 8 ] . V_51 ;
if ( F_21 ( V_14 & V_52 ) )
V_4 -> V_53 . V_54 = F_22 ( V_55 ) ;
F_23 ( V_2 , V_14 >> 8 , V_4 ) ;
break;
default:
break;
}
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_24 ;
int V_25 = 0 ;
V_24 = F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_56 ) ;
F_4 ( ~ V_24 , & V_2 -> V_6 . V_37 . V_41 -> V_56 ) ;
if ( V_24 & V_57 ) {
T_1 V_27 ;
V_27 = F_2 ( & V_2 -> V_6 . V_37 . V_31 -> V_58 ) ;
F_13 ( L_1 , V_27 ) ;
F_14 ( V_2 , V_27 ) ;
V_25 = 1 ;
}
if ( V_24 & V_59 ) {
T_3 V_14 ;
while ( ( V_14 = F_15 ( V_2 -> V_6 . V_37 . V_31 ) ) )
F_19 ( V_2 , V_14 ) ;
V_25 = 1 ;
}
return V_25 ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_60 )
{
T_1 V_43 = V_60 & 0xf ;
struct V_44 * V_4 ;
switch ( V_43 ) {
case V_46 :
case V_47 :
V_2 -> V_48 = 1 ;
break;
case V_49 :
V_4 = V_2 -> V_50 [ ( V_60 >> 4 ) & 0xff ] . V_51 ;
if ( F_21 ( V_60 & V_61 ) )
V_4 -> V_53 . V_54 = V_55 ;
F_23 ( V_2 , ( V_60 >> 4 ) & 0xff , V_4 ) ;
break;
default:
break;
}
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_60 , V_24 , V_62 , V_63 ;
int V_25 = 0 ;
if ( V_2 -> V_64 )
F_4 ( 0 , & ( V_2 -> V_6 . V_65 . V_31 -> V_66 ) ) ;
V_24 = F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_67 ) ) ;
if ( V_24 ) {
F_4 ( V_24 , & ( V_2 -> V_6 . V_65 . V_31 -> V_67 ) ) ;
if ( V_24 & V_68 ) {
T_1 V_27 = F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_69 ) ) ;
F_13 ( L_1 , V_27 ) ;
F_14 ( V_2 , V_27 ) ;
}
V_25 = 1 ;
}
V_24 = F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_70 ) ) ;
if ( V_24 ) {
F_4 ( V_24 , & ( V_2 -> V_6 . V_65 . V_31 -> V_70 ) ) ;
do {
V_62 = * V_2 -> V_6 . V_65 . V_71 & 0xff ;
V_63 = V_2 -> V_6 . V_65 . V_72 ;
while ( V_63 != V_62 ) {
V_63 ++ ;
if ( V_63 == V_2 -> V_6 . V_65 . V_73 )
V_63 = 0 ;
V_60 = V_2 -> V_6 . V_65 . V_74 [ V_63 ] . V_75 ;
F_20 ( ! ( V_60 & V_16 ) ) ;
F_25 ( V_2 , V_60 ) ;
V_25 = 1 ;
}
V_2 -> V_6 . V_65 . V_72 = V_63 ;
} while ( V_62 != ( * V_2 -> V_6 . V_65 . V_71 & 0xff ) );
}
if ( V_2 -> V_64 )
F_4 ( 0x1010 , & ( V_2 -> V_6 . V_65 . V_31 -> V_66 ) ) ;
return V_25 ;
}
static int F_27 ( struct V_1 * V_2 ,
void T_2 * V_76 , T_1 V_3 )
{
struct V_17 T_2 * V_4 = V_76 ;
T_1 V_5 ;
F_4 ( F_2 ( & V_4 -> V_19 ) | V_20 , & V_4 -> V_19 ) ;
F_4 ( 0 , & V_4 -> V_21 ) ;
F_4 ( ( unsigned long ) V_4 - ( unsigned long ) V_2 -> V_6 . V_7 . V_8 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_12 ( V_2 ) ;
if ( F_2 ( & V_4 -> V_21 ) )
return 0 ;
F_3 ( 1 ) ;
}
return - 1 ;
}
static int F_28 ( struct V_1 * V_2 ,
T_1 V_77 , T_1 V_3 )
{
struct V_17 * V_78 = V_2 -> V_6 . V_37 . V_79 ;
T_1 V_5 ;
V_2 -> V_48 = 0 ;
V_78 -> V_19 |= F_22 ( V_20 ) ;
F_17 ( V_2 -> V_6 . V_37 . V_80 |
V_81 | V_77 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_24 ( V_2 ) ;
if ( V_2 -> V_48 )
return 0 ;
F_3 ( 1 ) ;
}
return - 1 ;
}
static int F_29 ( struct V_1 * V_2 ,
T_1 V_77 , T_1 V_3 )
{
struct V_17 * V_78 =
V_2 -> V_6 . V_65 . V_79 . V_51 ;
T_1 V_5 ;
V_2 -> V_48 = 0 ;
V_78 -> V_19 |= F_22 ( V_20 ) ;
V_2 -> V_82 -> V_83 ( V_2 , & ( V_2 -> V_6 . V_65 . V_79 ) ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_26 ( V_2 ) ;
if ( V_2 -> V_48 )
break;
F_3 ( 1 ) ;
}
return V_2 -> V_48 ? 0 : - 1 ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_27 )
{
F_4 ( V_27 , & V_2 -> V_6 . V_7 . V_8 -> V_84 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_12 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_27 )
{
F_4 ( V_27 , & V_2 -> V_6 . V_37 . V_31 -> V_85 ) ;
F_4 ( V_86 , & V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_42 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_1 V_27 )
{
F_4 ( V_27 , & ( V_2 -> V_6 . V_65 . V_31 -> V_87 ) ) ;
F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_87 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_3 )
{
T_1 V_5 ;
V_2 -> V_48 = 0 ;
V_2 -> V_82 -> V_88 ( V_2 ) ;
V_2 -> V_82 -> V_89 ( V_2 , V_27 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
F_33 ( V_2 -> V_90 -> V_91 ) ;
V_2 -> V_82 -> V_92 ( V_2 ) ;
F_34 ( V_2 -> V_90 -> V_91 ) ;
if ( V_2 -> V_48 )
break;
F_3 ( 1 ) ;
}
V_2 -> V_82 -> V_93 ( V_2 ) ;
return V_2 -> V_48 ? 0 : - 1 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
T_1 V_96 ;
struct V_94 T_2 * V_4 ;
V_96 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_96 == V_10 )
return - 1 ;
V_4 = (struct V_94 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_96 ) ;
F_4 ( 0 , & V_4 -> V_53 . V_19 ) ;
F_4 ( V_46 , & V_4 -> V_53 . type ) ;
F_4 ( sizeof( struct V_94 ) , & V_4 -> V_53 . V_97 ) ;
F_4 ( V_98 , & V_4 -> V_53 . V_54 ) ;
if ( F_27 ( V_2 , V_4 , 20000 ) ) {
F_13 ( L_3 ) ;
return - 1 ;
}
F_16 ( V_95 , V_4 , sizeof( * V_95 ) ) ;
F_4 ( V_96 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_94 * V_4 = V_2 -> V_6 . V_37 . V_79 ;
V_4 -> V_53 . V_19 = F_22 ( V_99 ) ;
V_4 -> V_53 . type = F_22 ( V_46 ) ;
V_4 -> V_53 . V_97 =
F_22 ( sizeof( struct V_94 ) ) ;
V_4 -> V_53 . V_54 = F_22 ( V_98 ) ;
V_4 -> V_53 . V_21 = F_22 ( V_46 << 5 ) ;
V_4 -> V_53 . V_100 = 0 ;
if ( F_28 ( V_2 , 0 , 20000 ) ) {
F_13 ( L_3 ) ;
return - 1 ;
}
memcpy ( V_95 , V_4 , sizeof( struct V_94 ) ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_94 * V_101 = V_2 -> V_6 . V_65 . V_95 ;
if ( V_101 -> V_53 . V_97 != sizeof( struct V_94 ) ||
V_101 -> V_53 . type != V_46 )
return - 1 ;
V_95 -> V_102 = V_101 -> V_102 ;
V_95 -> V_103 = V_101 -> V_103 ;
V_95 -> V_104 = V_101 -> V_104 ;
V_95 -> V_105 = V_101 -> V_105 ;
V_95 -> V_106 = V_101 -> V_106 ;
V_95 -> V_107 = V_101 -> V_107 ;
V_95 -> V_108 = V_101 -> V_108 ;
V_95 -> V_109 = V_101 -> V_109 ;
V_95 -> V_110 = V_101 -> V_110 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_111 * V_95 )
{
T_1 V_96 ;
struct V_111 T_2 * V_4 ;
V_96 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
if ( V_96 == V_10 )
return - 1 ;
V_4 = (struct V_111 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_96 ) ;
F_18 ( ( V_112 T_2 * ) V_4 + sizeof( struct V_17 ) ,
( V_112 * ) V_95 + sizeof( struct V_17 ) ,
sizeof( struct V_111 ) -
sizeof( struct V_17 ) ) ;
F_4 ( 0 , & V_4 -> V_53 . V_19 ) ;
F_4 ( V_47 , & V_4 -> V_53 . type ) ;
F_4 ( sizeof( struct V_111 ) , & V_4 -> V_53 . V_97 ) ;
F_4 ( V_98 , & V_4 -> V_53 . V_54 ) ;
if ( F_27 ( V_2 , V_4 , 20000 ) ) {
F_13 ( L_4 ) ;
return - 1 ;
}
F_4 ( V_96 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_111 * V_95 )
{
struct V_111 * V_4 = V_2 -> V_6 . V_37 . V_79 ;
memcpy ( V_4 , V_95 , sizeof( struct V_111 ) ) ;
V_4 -> V_53 . V_19 = F_22 ( V_99 ) ;
V_4 -> V_53 . type = F_22 ( V_47 ) ;
V_4 -> V_53 . V_97 =
F_22 ( sizeof( struct V_111 ) ) ;
V_4 -> V_53 . V_54 = F_22 ( V_98 ) ;
V_4 -> V_53 . V_21 = F_22 ( V_47 << 5 ) ;
V_4 -> V_53 . V_100 = 0 ;
if ( F_28 ( V_2 , 0 , 20000 ) ) {
F_13 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_111 * V_95 )
{
struct V_111 * V_4 =
V_2 -> V_6 . V_65 . V_79 . V_51 ;
memcpy ( V_4 , V_95 , sizeof( struct V_111 ) ) ;
V_4 -> V_53 . V_19 = F_22 ( V_99 ) ;
V_4 -> V_53 . type = F_22 ( V_47 ) ;
V_4 -> V_53 . V_97 =
F_22 ( sizeof( struct V_111 ) ) ;
V_4 -> V_53 . V_54 = F_22 ( V_98 ) ;
V_4 -> V_53 . V_21 = F_22 ( V_47 << 5 ) ;
V_4 -> V_53 . V_100 = 0 ;
if ( F_29 ( V_2 , 0 , 20000 ) ) {
F_13 ( L_4 ) ;
return - 1 ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_4 ( ~ ( V_29 | V_26 ) ,
& V_2 -> V_6 . V_7 . V_8 -> V_113 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_4 ( V_59 | V_57 ,
& V_2 -> V_6 . V_37 . V_41 -> V_113 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_4 ( V_68 , & ( V_2 -> V_6 . V_65 . V_31 -> V_114 ) ) ;
F_4 ( 0x1 , & ( V_2 -> V_6 . V_65 . V_31 -> V_115 ) ) ;
F_4 ( 0x1010 , & ( V_2 -> V_6 . V_65 . V_31 -> V_66 ) ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
V_2 -> V_82 -> V_93 ( V_2 ) ;
V_2 -> V_64 = 1 ;
if ( F_6 ( V_2 ,
V_116 , 5000 ) ) {
F_45 ( V_117 L_5 ,
V_2 -> V_90 -> V_118 ) ;
return - 1 ;
}
return 0 ;
}
static void T_2 * F_46 ( struct V_1 * V_2 , int V_119 )
{
T_1 V_120 , V_121 ;
void T_2 * V_122 ;
struct V_123 * V_124 = V_2 -> V_124 ;
if ( ! ( F_47 ( V_124 , V_119 ) & V_125 ) ) {
F_45 ( V_117 L_6 ,
V_2 -> V_90 -> V_118 ) ;
return NULL ;
}
V_120 = F_48 ( V_124 , V_119 ) ;
V_121 = F_49 ( V_124 , V_119 ) ;
V_122 = F_50 ( V_120 , V_121 ) ;
if ( ! V_122 ) {
F_45 ( V_117 L_7 ,
V_2 -> V_90 -> V_118 ) ;
return NULL ;
}
return V_122 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = V_2 -> V_124 ;
V_2 -> V_6 . V_7 . V_8 = F_46 ( V_2 , 0 ) ;
if ( V_2 -> V_6 . V_7 . V_8 == NULL )
return - 1 ;
if ( ( V_124 -> V_126 & 0xff00 ) == 0x4400 ) {
V_2 -> V_6 . V_7 . V_23 = V_2 -> V_6 . V_7 . V_8 ;
V_2 -> V_6 . V_7 . V_8 = F_46 ( V_2 , 2 ) ;
if ( V_2 -> V_6 . V_7 . V_8 == NULL ) {
F_52 ( V_2 -> V_6 . V_7 . V_23 ) ;
return - 1 ;
}
}
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_7 . V_23 )
F_52 ( V_2 -> V_6 . V_7 . V_23 ) ;
F_52 ( V_2 -> V_6 . V_7 . V_8 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_37 . V_41 = F_46 ( V_2 , 0 ) ;
if ( V_2 -> V_6 . V_37 . V_41 == NULL )
return - 1 ;
V_2 -> V_6 . V_37 . V_31 = F_46 ( V_2 , 2 ) ;
if ( V_2 -> V_6 . V_37 . V_31 == NULL ) {
F_52 ( V_2 -> V_6 . V_37 . V_41 ) ;
return - 1 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_65 . V_95 = F_46 ( V_2 , 0 ) ;
if ( V_2 -> V_6 . V_65 . V_95 == NULL )
return - 1 ;
V_2 -> V_6 . V_65 . V_31 = F_46 ( V_2 , 2 ) ;
if ( V_2 -> V_6 . V_65 . V_31 == NULL ) {
F_52 ( V_2 -> V_6 . V_65 . V_95 ) ;
return - 1 ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_6 . V_37 . V_41 ) ;
F_52 ( V_2 -> V_6 . V_37 . V_31 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_52 ( V_2 -> V_6 . V_65 . V_95 ) ;
F_52 ( V_2 -> V_6 . V_65 . V_31 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_27 )
{
F_13 ( L_8 , V_27 ) ;
if ( V_27 == V_13 ||
V_27 == V_127 )
V_2 -> V_48 = 1 ;
if ( ! V_2 -> V_64 )
return;
if ( V_27 == V_128 ) {
F_58 ( & V_2 -> V_129 , 0 ) ;
F_59 ( & V_2 -> V_130 ) ;
}
else if ( V_27 <= V_131 )
V_2 -> V_48 = 1 ;
}
static struct V_132 * F_60 ( struct V_1 * V_2 )
{
struct V_132 * V_25 ;
F_13 ( L_9 , V_2 -> V_133 ) ;
V_25 = V_2 -> V_133 ;
if ( V_25 )
V_2 -> V_133 = V_25 -> V_134 ;
return V_25 ;
}
static void F_61 ( struct V_1 * V_2 , struct V_132 * V_4 )
{
F_13 ( L_10 , V_4 -> V_119 , V_4 ) ;
V_4 -> V_134 = V_2 -> V_133 ;
V_2 -> V_133 = V_4 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_14 ,
struct V_44 * V_4 )
{
struct V_135 * V_136 ;
F_13 ( L_11
L_12 ,
V_4 , V_4 -> V_53 . type , V_4 -> V_53 . V_54 ,
V_4 -> V_53 . V_21 , V_14 ) ;
F_20 ( ! V_4 -> V_53 . V_54 ) ;
F_20 ( V_4 -> V_53 . type != F_22 ( V_49 ) ) ;
V_136 = V_2 -> V_50 [ V_14 ] . V_136 ;
if ( F_62 ( V_136 ) -> V_137 )
F_63 ( V_136 ) ;
switch ( F_64 ( V_4 -> V_53 . V_54 ) ) {
case V_55 :
F_65 ( V_136 ,
F_66 ( V_136 ) - F_64 ( V_4 -> V_138 ) ) ;
V_136 -> V_54 = ( V_139 << 16 ) ;
break;
case V_140 :
V_136 -> V_54 = ( V_141 << 16 ) ;
break;
case V_142 :
V_136 -> V_54 = ( V_143 << 16 ) ;
break;
case V_144 :
V_136 -> V_54 = ( V_145 << 16 ) ;
break;
case V_146 :
V_136 -> V_54 = ( V_147 << 16 ) ;
break;
case V_148 :
V_136 -> V_54 = ( V_149 << 16 ) ;
break;
case V_150 :
F_65 ( V_136 ,
F_66 ( V_136 ) - F_64 ( V_4 -> V_138 ) ) ;
V_136 -> V_54 = V_151 ;
memcpy ( V_136 -> V_152 , & V_4 -> V_153 ,
F_67 ( V_154 , V_155 ,
F_64 ( V_4 -> V_138 ) ) ) ;
goto V_156;
break;
default:
V_136 -> V_54 = V_157 << 24 | V_149 << 16 ;
break;
}
F_65 ( V_136 ,
F_66 ( V_136 ) - F_64 ( V_4 -> V_138 ) ) ;
V_156:
F_13 ( L_13 , V_136 ) ;
V_136 -> V_158 ( V_136 ) ;
F_61 ( V_2 , & V_2 -> V_50 [ V_14 ] ) ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_60 )
{
struct V_44 * V_4 ;
T_1 V_14 ;
if ( V_2 -> V_159 ) {
V_14 = V_60 & ~ V_61 ;
V_4 = V_2 -> V_50 [ V_14 ] . V_51 ;
if ( F_21 ( V_60 & V_61 ) )
V_4 -> V_53 . V_54 = F_22 ( V_55 ) ;
} else {
V_14 = V_60 ;
V_4 = V_2 -> V_50 [ V_14 ] . V_51 ;
}
F_23 ( V_2 , V_14 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_17 T_2 * V_4 ;
struct V_160 T_2 * V_18 ;
struct V_161 * V_162 ;
V_4 = (struct V_17 T_2 * )
( ( unsigned long ) V_2 -> V_6 . V_7 . V_8 + V_14 ) ;
F_13 ( L_14
L_12 ,
V_4 , F_2 ( & V_4 -> type ) , F_2 ( & V_4 -> V_54 ) ,
F_2 ( & V_4 -> V_21 ) , V_14 ) ;
F_20 ( ! F_2 ( & V_4 -> V_54 ) ) ;
F_20 ( F_2 ( & V_4 -> type ) != V_163 ) ;
V_18 = (struct V_160 T_2 * ) V_4 ;
V_162 = (struct V_161 * ) ( unsigned long )
( F_2 ( & V_4 -> V_21 ) |
( ( T_3 ) F_2 ( & V_4 -> V_100 ) << 32 ) ) ;
if ( F_2 ( & V_4 -> V_54 ) == V_55 ) {
V_162 -> V_54 = V_164 ;
if ( V_162 -> V_165 )
F_16 ( V_162 -> V_166 ,
& V_18 -> V_167 [ ( F_2 ( & V_18 -> V_168 ) + 3 ) & ~ 3 ] ,
V_162 -> V_165 ) ;
if ( V_162 -> V_169 )
* V_162 -> V_169 = V_162 -> V_165 ;
}
else
V_162 -> V_54 = V_170 ;
V_162 -> V_171 ( V_162 ) ;
F_4 ( V_14 , & V_2 -> V_6 . V_7 . V_8 -> V_11 ) ;
}
static T_4 F_68 ( int V_172 , void * V_173 )
{
struct V_1 * V_2 = V_173 ;
int V_174 ;
unsigned long V_19 ;
F_69 ( V_2 -> V_90 -> V_91 , V_19 ) ;
V_174 = V_2 -> V_82 -> V_92 ( V_2 ) ;
F_70 ( V_2 -> V_90 -> V_91 , V_19 ) ;
return V_174 ;
}
static int F_71 ( struct V_135 * V_136 , struct V_175 * V_176 )
{
struct V_177 * V_90 = V_136 -> V_126 -> V_90 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
struct V_179 * V_180 ;
int V_181 , V_182 ;
V_182 = F_72 ( V_136 ) ;
F_20 ( V_182 < 0 ) ;
if ( ! V_182 )
return 0 ;
F_62 ( V_136 ) -> V_183 = V_182 ;
F_62 ( V_136 ) -> V_137 = 1 ;
F_20 ( F_62 ( V_136 ) -> V_183 > V_2 -> V_184 ) ;
F_73 (scp, sg, HPT_SCP(scp)->sgcnt, idx) {
V_176 [ V_181 ] . V_185 = F_74 ( F_75 ( V_180 ) ) |
V_2 -> V_82 -> V_186 ;
V_176 [ V_181 ] . V_97 = F_22 ( F_76 ( V_180 ) ) ;
V_176 [ V_181 ] . V_187 = ( V_181 == F_62 ( V_136 ) -> V_183 - 1 ) ?
F_22 ( 1 ) : 0 ;
}
return F_62 ( V_136 ) -> V_183 ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_132 * V_76 )
{
struct V_17 * V_78 = V_76 -> V_51 ;
V_78 -> V_21 = F_22 ( V_15 |
( T_1 ) V_76 -> V_119 ) ;
V_78 -> V_100 = 0 ;
if ( V_2 -> V_159 ) {
T_1 V_97 , V_77 ;
V_97 = F_64 ( V_78 -> V_97 ) ;
if ( V_97 < 256 )
V_77 = V_188 ;
else if ( V_97 < 512 )
V_77 = V_15 ;
else
V_77 = V_188 |
V_15 ;
F_4 ( V_76 -> V_189 | V_77 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
} else
F_4 ( V_76 -> V_189 | V_15 ,
& V_2 -> V_6 . V_7 . V_8 -> V_9 ) ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_132 * V_76 )
{
struct V_17 * V_78 = V_76 -> V_51 ;
T_1 V_97 , V_190 ;
V_78 -> V_21 = F_22 ( V_76 -> V_119 << 8 |
V_49 << 5 ) ;
V_78 -> V_100 = 0 ;
V_97 = F_64 ( V_78 -> V_97 ) ;
if ( V_97 <= 256 )
V_190 = 0 ;
else if ( V_97 <= 256 * 2 )
V_190 = 1 ;
else if ( V_97 <= 256 * 3 )
V_190 = 2 ;
else
V_190 = 3 ;
F_17 ( ( V_76 -> V_189 << 5 ) |
V_81 | V_190 , V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_132 * V_76 )
{
struct V_17 * V_78 = V_76 -> V_51 ;
T_1 V_119 ;
V_78 -> V_19 |= F_22 ( V_99 |
V_191 |
( ( V_76 -> V_189 >> 11 ) & 0xffff0000 ) ) ;
V_78 -> V_21 = F_22 ( V_15 |
( V_76 -> V_119 << 4 ) | V_78 -> type ) ;
V_78 -> V_100 = F_22 ( ( V_76 -> V_189 << 5 ) &
0xffffffff ) ;
V_2 -> V_6 . V_65 . V_192 ++ ;
V_119 = V_2 -> V_6 . V_65 . V_192 & 0x3fff ;
if ( V_119 == V_2 -> V_6 . V_65 . V_73 ) {
V_119 = 0 ;
V_2 -> V_6 . V_65 . V_192 &= ~ 0x3fff ;
V_2 -> V_6 . V_65 . V_192 ^= V_193 ;
}
V_2 -> V_6 . V_65 . V_194 [ V_119 ] . V_195 =
( V_196 ) V_76 -> V_189 << 5 ;
V_2 -> V_6 . V_65 . V_194 [ V_119 ] . V_197 = ( V_78 -> V_97 + 3 ) / 4 ;
F_4 ( V_2 -> V_6 . V_65 . V_192 ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_198 ) ) ;
F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_198 ) ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_1 V_73 = V_2 -> V_6 . V_65 . V_73 ;
if ( F_6 ( V_2 , V_127 , 3000 ) )
return - 1 ;
F_3 ( 100 ) ;
F_4 ( F_22 ( V_2 -> V_6 . V_65 . V_199 & 0xffffffff ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_200 ) ) ;
F_4 ( F_22 ( ( V_2 -> V_6 . V_65 . V_199 >> 16 ) >> 16 ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_201 ) ) ;
F_4 ( F_22 ( V_2 -> V_6 . V_65 . V_202 & 0xffffffff ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_203 ) ) ;
F_4 ( F_22 ( ( V_2 -> V_6 . V_65 . V_202 >> 16 ) >> 16 ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_204 ) ) ;
F_4 ( F_22 ( V_2 -> V_6 . V_65 . V_205 & 0xffffffff ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_206 ) ) ;
F_4 ( F_22 ( ( V_2 -> V_6 . V_65 . V_205 >> 16 ) >> 16 ) ,
& ( V_2 -> V_6 . V_65 . V_31 -> V_207 ) ) ;
V_2 -> V_6 . V_65 . V_192 = ( V_73 - 1 ) | V_193 ;
* V_2 -> V_6 . V_65 . V_71 = ( V_73 - 1 ) | V_193 ;
V_2 -> V_6 . V_65 . V_72 = V_73 - 1 ;
return 0 ;
}
static int F_83 ( struct V_135 * V_136 ,
void (* V_171)( struct V_135 * ) )
{
struct V_177 * V_90 = V_136 -> V_126 -> V_90 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
struct V_44 * V_4 ;
int V_208 = 0 ;
struct V_132 * V_76 ;
F_20 ( ! V_171 ) ;
V_136 -> V_158 = V_171 ;
V_76 = F_60 ( V_2 ) ;
if ( V_76 == NULL ) {
F_13 ( L_15 ) ;
return V_209 ;
}
V_76 -> V_136 = V_136 ;
F_13 ( L_16
L_17 ,
V_136 ,
V_90 -> V_118 , V_136 -> V_126 -> V_210 ,
V_136 -> V_126 -> V_211 , V_136 -> V_126 -> V_212 ,
F_84 ( ( ( T_1 * ) V_136 -> V_213 ) [ 0 ] ) ,
F_84 ( ( ( T_1 * ) V_136 -> V_213 ) [ 1 ] ) ,
F_84 ( ( ( T_1 * ) V_136 -> V_213 ) [ 2 ] ) ,
F_84 ( ( ( T_1 * ) V_136 -> V_213 ) [ 3 ] ) ,
V_76 -> V_119 , V_76 -> V_51 ) ;
V_136 -> V_54 = 0 ;
if ( V_136 -> V_126 -> V_210 || V_136 -> V_126 -> V_212 ||
V_136 -> V_126 -> V_211 > V_2 -> V_109 ) {
V_136 -> V_54 = V_141 << 16 ;
F_61 ( V_2 , V_76 ) ;
goto V_214;
}
V_4 = V_76 -> V_51 ;
V_208 = F_71 ( V_136 , V_4 -> V_153 ) ;
if ( ! V_208 )
F_62 ( V_136 ) -> V_137 = 0 ;
V_4 -> V_53 . V_19 = F_22 ( V_99 ) ;
V_4 -> V_53 . type = F_22 ( V_49 ) ;
V_4 -> V_53 . V_54 = F_22 ( V_98 ) ;
V_4 -> V_138 = F_22 ( F_66 ( V_136 ) ) ;
V_4 -> V_210 = V_136 -> V_126 -> V_210 ;
V_4 -> V_215 = V_136 -> V_126 -> V_211 ;
V_4 -> V_212 = V_136 -> V_126 -> V_212 ;
V_4 -> V_53 . V_97 = F_22 (
sizeof( struct V_44 )
- sizeof( struct V_175 )
+ V_208 * sizeof( struct V_175 ) ) ;
memcpy ( V_4 -> V_216 , V_136 -> V_213 , sizeof( V_4 -> V_216 ) ) ;
V_2 -> V_82 -> V_83 ( V_2 , V_76 ) ;
return 0 ;
V_214:
F_13 ( L_18 , V_136 ) ;
V_136 -> V_158 ( V_136 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
if ( F_86 ( & V_2 -> V_129 , 1 ) == 0 ) {
F_87 ( & V_2 -> V_217 ) ;
V_2 -> V_82 -> V_89 ( V_2 , V_128 ) ;
}
F_88 ( V_2 -> V_130 ,
F_89 ( & V_2 -> V_129 ) == 0 , 60 * V_218 ) ;
if ( F_89 ( & V_2 -> V_129 ) ) {
F_45 ( V_117 L_19 , V_2 -> V_90 -> V_118 ) ;
return - 1 ;
}
if ( F_6 ( V_2 ,
V_116 , 5000 ) ) {
F_13 ( L_5 ,
V_2 -> V_90 -> V_118 ) ;
}
return 0 ;
}
static int F_90 ( struct V_135 * V_136 )
{
struct V_177 * V_90 = V_136 -> V_126 -> V_90 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
F_45 ( V_219 L_20 ,
V_136 -> V_126 -> V_90 -> V_118 , V_136 -> V_126 -> V_210 ,
V_136 -> V_126 -> V_211 , V_136 ) ;
return F_85 ( V_2 ) ? V_220 : V_221 ;
}
static int F_91 ( struct V_222 * V_223 ,
int V_224 , int V_225 )
{
struct V_1 * V_2 = (struct V_1 * ) V_223 -> V_90 -> V_178 ;
if ( V_225 != V_226 )
return - V_227 ;
if ( V_224 > V_2 -> V_104 )
V_224 = V_2 -> V_104 ;
F_92 ( V_223 , V_228 , V_224 ) ;
return V_224 ;
}
static T_5 F_93 ( struct V_126 * V_229 ,
struct V_230 * V_231 , char * V_167 )
{
return snprintf ( V_167 , V_232 , L_21 , V_233 ) ;
}
static T_5 F_94 ( struct V_126 * V_229 ,
struct V_230 * V_231 , char * V_167 )
{
struct V_177 * V_90 = F_95 ( V_229 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
return snprintf ( V_167 , V_232 , L_22 ,
V_2 -> V_103 >> 24 ,
( V_2 -> V_103 >> 16 ) & 0xff ,
( V_2 -> V_103 >> 8 ) & 0xff ,
V_2 -> V_103 & 0xff ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_97 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_37 . V_79 = F_98 ( & V_2 -> V_124 -> V_229 ,
0x800 , & V_2 -> V_6 . V_37 . V_80 , V_234 ) ;
if ( V_2 -> V_6 . V_37 . V_79 )
return 0 ;
else
return - 1 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_1 V_73 = F_2 ( & V_2 -> V_6 . V_65 . V_31 -> V_235 ) ;
char * V_18 ;
V_196 V_236 ;
F_20 ( V_2 -> V_237 == 0 ) ;
if ( V_73 == 0 ) {
F_20 ( 1 ) ;
return - 1 ;
}
V_73 >>= 16 ;
V_2 -> V_6 . V_65 . V_73 = V_73 ;
V_2 -> V_6 . V_65 . V_238 = 0x800 +
V_73 * sizeof( struct V_239 ) +
V_73 * sizeof( struct V_240 ) +
sizeof( int ) ;
V_18 = F_98 ( & V_2 -> V_124 -> V_229 ,
V_2 -> V_6 . V_65 . V_238 , & V_236 , V_234 ) ;
if ( ! V_18 )
return - 1 ;
V_2 -> V_6 . V_65 . V_79 . V_51 = V_18 ;
V_2 -> V_6 . V_65 . V_79 . V_189 = V_236 >> 5 ;
V_2 -> V_6 . V_65 . V_79 . V_136 = NULL ;
V_2 -> V_6 . V_65 . V_79 . V_134 = NULL ;
V_18 += 0x800 ;
V_236 += 0x800 ;
V_2 -> V_6 . V_65 . V_194 = (struct V_239 * ) V_18 ;
V_2 -> V_6 . V_65 . V_199 = V_236 ;
V_18 += V_73 * sizeof( struct V_239 ) ;
V_236 += V_73 * sizeof( struct V_239 ) ;
V_2 -> V_6 . V_65 . V_74 = (struct V_240 * ) V_18 ;
V_2 -> V_6 . V_65 . V_202 = V_236 ;
V_18 += V_73 * sizeof( struct V_240 ) ;
V_236 += V_73 * sizeof( struct V_240 ) ;
V_2 -> V_6 . V_65 . V_71 = ( V_241 * ) V_18 ;
V_2 -> V_6 . V_65 . V_205 = V_236 ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_37 . V_79 ) {
F_102 ( & V_2 -> V_124 -> V_229 , 0x800 ,
V_2 -> V_6 . V_37 . V_79 , V_2 -> V_6 . V_37 . V_80 ) ;
return 0 ;
} else
return - 1 ;
}
static int F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_65 . V_79 . V_51 ) {
F_102 ( & V_2 -> V_124 -> V_229 ,
V_2 -> V_6 . V_65 . V_238 ,
V_2 -> V_6 . V_65 . V_79 . V_51 ,
( V_196 )
V_2 -> V_6 . V_65 . V_79 . V_189 << 5 ) ;
return 0 ;
} else
return - 1 ;
}
static int F_104 ( struct V_123 * V_124 , const struct V_242 * V_211 )
{
struct V_177 * V_90 = NULL ;
struct V_1 * V_2 ;
struct V_243 * V_244 ;
struct V_94 V_245 ;
struct V_111 V_246 ;
V_196 V_247 ;
void * V_248 ;
T_1 V_249 , V_5 , V_250 ;
F_13 ( L_23 , V_124 ) ;
if ( F_105 ( V_124 ) ) {
F_45 ( V_117 L_24 ) ;
return - V_251 ;
}
F_45 ( V_252 L_25 ,
V_124 -> V_253 -> V_254 , V_124 -> V_255 >> 3 , V_124 -> V_255 & 7 ,
V_124 -> V_172 ) ;
F_106 ( V_124 ) ;
V_244 = (struct V_243 * ) V_211 -> V_256 ;
if ( F_107 ( V_124 , F_108 ( V_244 -> V_257 ) ) ) {
if ( F_107 ( V_124 , F_108 ( 32 ) ) ) {
F_45 ( V_117 L_26 ) ;
goto V_258;
}
}
if ( F_109 ( V_124 , V_259 ) ) {
F_45 ( V_117 L_27 ) ;
goto V_258;
}
V_90 = F_110 ( & V_260 , sizeof( struct V_1 ) ) ;
if ( ! V_90 ) {
F_45 ( V_117 L_28 ) ;
goto V_261;
}
V_2 = (struct V_1 * ) V_90 -> V_178 ;
V_2 -> V_82 = V_244 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_90 = V_90 ;
V_2 -> V_64 = 0 ;
V_2 -> V_159 = 0 ;
F_58 ( & V_2 -> V_129 , 0 ) ;
F_58 ( & V_2 -> V_217 , 0 ) ;
F_111 ( & V_2 -> V_130 ) ;
F_111 ( & V_2 -> V_262 ) ;
V_90 -> V_263 = 1 ;
V_90 -> V_264 = 0 ;
V_90 -> V_265 = 0 ;
V_90 -> V_266 = 0 ;
V_90 -> V_172 = V_124 -> V_172 ;
if ( V_2 -> V_82 -> V_267 ( V_2 ) )
goto V_268;
if ( V_2 -> V_82 -> V_269 ( V_2 , 20000 ) ) {
F_45 ( V_117 L_29 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
if ( V_2 -> V_82 -> V_271 == V_272 ) {
if ( V_2 -> V_82 -> V_273 ( V_2 ) ) {
F_45 ( V_117 L_30 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
}
if ( V_2 -> V_82 -> V_274 ( V_2 , & V_245 ) ) {
F_45 ( V_117 L_31 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
V_2 -> V_104 = F_112 ( F_64 ( V_245 . V_104 ) ,
V_275 ) ;
V_2 -> V_109 = F_64 ( V_245 . V_109 ) ;
V_2 -> V_237 = F_64 ( V_245 . V_105 ) ;
V_2 -> V_184 = F_64 ( V_245 . V_106 ) ;
V_2 -> V_103 = F_64 ( V_245 . V_103 ) ;
V_2 -> V_102 = F_64 ( V_245 . V_102 ) ;
V_2 -> V_110 = F_64 ( V_245 . V_110 ) ;
if ( V_2 -> V_82 -> V_271 == V_276 ) {
if ( V_2 -> V_82 -> V_273 ( V_2 ) ) {
F_45 ( V_117 L_30 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
if ( V_2 -> V_82 -> V_277 ( V_2 ) ) {
F_45 ( V_117 L_32 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
}
if ( V_2 -> V_103 > 0x01020000 ||
V_2 -> V_102 > 0x01020000 )
V_2 -> V_159 = 1 ;
V_90 -> V_278 = F_64 ( V_245 . V_107 ) >> 9 ;
V_90 -> V_279 = F_64 ( V_245 . V_109 ) ;
V_90 -> V_280 = F_64 ( V_245 . V_106 ) ;
V_90 -> V_281 = F_64 ( V_245 . V_104 ) ;
V_90 -> V_282 = F_64 ( V_245 . V_104 ) ;
V_90 -> V_283 = 16 ;
V_250 = sizeof( struct V_44 )
+ sizeof( struct V_175 ) * ( V_2 -> V_184 - 1 ) ;
if ( ( V_250 & 0x1f ) != 0 )
V_250 = ( V_250 + 0x1f ) & ~ 0x1f ;
memset ( & V_246 , 0 , sizeof( struct V_111 ) ) ;
V_246 . V_284 = F_22 ( V_90 -> V_118 ) ;
V_246 . V_285 = F_113 ( V_90 -> V_118 ) ;
V_246 . V_286 = F_113 ( V_250 ) ;
if ( V_2 -> V_82 -> V_246 ( V_2 , & V_246 ) ) {
F_45 ( V_117 L_33 ,
V_2 -> V_90 -> V_118 ) ;
goto V_270;
}
F_114 ( V_124 , V_90 ) ;
if ( F_115 ( V_124 -> V_172 , F_68 , V_287 ,
V_259 , V_2 ) ) {
F_45 ( V_117 L_34 ,
V_2 -> V_90 -> V_118 , V_124 -> V_172 ) ;
goto V_270;
}
F_13 ( L_35 , V_250 , V_2 -> V_104 ) ;
V_2 -> V_250 = V_250 ;
V_248 = F_98 ( & V_124 -> V_229 ,
V_2 -> V_250 * V_2 -> V_104 + 0x20 ,
& V_247 , V_234 ) ;
if ( ! V_248 ) {
F_45 ( V_117 L_36 ,
V_2 -> V_90 -> V_118 ) ;
goto V_288;
}
V_2 -> V_289 = V_248 ;
V_2 -> V_290 = V_247 ;
if ( ( V_247 & 0x1f ) != 0 ) {
V_249 = ( ( V_247 + 0x1f ) & ~ 0x1f ) - V_247 ;
V_247 += V_249 ;
V_248 += V_249 ;
}
V_2 -> V_133 = NULL ;
for ( V_5 = 0 ; V_5 < V_2 -> V_104 ; V_5 ++ ) {
V_2 -> V_50 [ V_5 ] . V_134 = NULL ;
V_2 -> V_50 [ V_5 ] . V_51 = V_248 ;
V_2 -> V_50 [ V_5 ] . V_189 = V_247 >> 5 ;
V_2 -> V_50 [ V_5 ] . V_119 = V_5 ;
F_61 ( V_2 , & V_2 -> V_50 [ V_5 ] ) ;
V_248 = ( char * ) V_248 + V_2 -> V_250 ;
V_247 = V_247 + V_2 -> V_250 ;
}
if ( F_44 ( V_2 ) )
goto V_291;
if ( F_116 ( V_90 , & V_124 -> V_229 ) ) {
F_45 ( V_117 L_37 ,
V_2 -> V_90 -> V_118 ) ;
goto V_291;
}
F_117 ( V_90 ) ;
F_13 ( L_38 , V_2 -> V_90 -> V_118 ) ;
return 0 ;
V_291:
F_102 ( & V_2 -> V_124 -> V_229 ,
V_2 -> V_250 * V_2 -> V_104 + 0x20 ,
V_2 -> V_289 , V_2 -> V_290 ) ;
V_288:
F_118 ( V_2 -> V_124 -> V_172 , V_2 ) ;
V_270:
V_2 -> V_82 -> V_292 ( V_2 ) ;
V_2 -> V_82 -> V_270 ( V_2 ) ;
V_268:
F_119 ( V_90 ) ;
V_261:
F_120 ( V_124 ) ;
V_258:
F_121 ( V_124 ) ;
F_13 ( L_39 , V_90 ? V_90 -> V_118 : 0 ) ;
return - V_251 ;
}
static void F_122 ( struct V_123 * V_124 )
{
struct V_177 * V_90 = F_123 ( V_124 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
F_13 ( L_40 , V_2 ) ;
if ( F_6 ( V_2 , V_293 , 60000 ) )
F_45 ( V_117 L_41 ,
V_2 -> V_90 -> V_118 ) ;
V_2 -> V_82 -> V_88 ( V_2 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_1 V_294 ;
V_294 = F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_113 ) ;
F_4 ( V_294 |
V_26 | V_29 ,
& V_2 -> V_6 . V_7 . V_8 -> V_113 ) ;
F_2 ( & V_2 -> V_6 . V_7 . V_8 -> V_113 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
F_4 ( 0 , & V_2 -> V_6 . V_37 . V_41 -> V_113 ) ;
F_2 ( & V_2 -> V_6 . V_37 . V_41 -> V_113 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_4 ( 0 , & ( V_2 -> V_6 . V_65 . V_31 -> V_114 ) ) ;
F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_114 ) ) ;
F_4 ( 0 , & ( V_2 -> V_6 . V_65 . V_31 -> V_115 ) ) ;
F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_115 ) ) ;
F_4 ( 0 , & ( V_2 -> V_6 . V_65 . V_31 -> V_66 ) ) ;
F_2 ( & ( V_2 -> V_6 . V_65 . V_31 -> V_66 ) ) ;
}
static void F_127 ( struct V_123 * V_124 )
{
struct V_177 * V_90 = F_123 ( V_124 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_178 ;
F_13 ( L_42 , V_2 -> V_90 -> V_118 ) ;
F_128 ( V_90 ) ;
F_122 ( V_124 ) ;
F_118 ( V_2 -> V_124 -> V_172 , V_2 ) ;
F_102 ( & V_2 -> V_124 -> V_229 ,
V_2 -> V_250 * V_2 -> V_104 + 0x20 ,
V_2 -> V_289 ,
V_2 -> V_290 ) ;
V_2 -> V_82 -> V_292 ( V_2 ) ;
V_2 -> V_82 -> V_270 ( V_2 ) ;
F_120 ( V_2 -> V_124 ) ;
F_114 ( V_2 -> V_124 , NULL ) ;
F_121 ( V_2 -> V_124 ) ;
F_119 ( V_90 ) ;
}
static int T_6 F_129 ( void )
{
F_45 ( V_252 L_43 , V_295 , V_233 ) ;
return F_130 ( & V_296 ) ;
}
static void T_7 F_131 ( void )
{
F_132 ( & V_296 ) ;
}
