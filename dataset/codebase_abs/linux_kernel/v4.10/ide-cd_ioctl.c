int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( ! V_2 -> V_6 )
V_4 -> V_7 &= ~ V_8 ;
}
int F_3 ( struct V_1 * V_2 , int V_9 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
int V_14 ;
if ( V_9 != V_15 )
return - V_16 ;
V_14 = F_4 ( V_4 , & V_13 ) ;
if ( ! V_14 || V_13 . V_17 == V_18 )
return V_19 ;
if ( ! F_5 ( V_2 , & V_11 ) ) {
if ( V_11 . V_20 )
return V_19 ;
else if ( V_11 . V_21 )
return V_22 ;
else
return V_23 ;
}
if ( V_13 . V_17 == V_24 && V_13 . V_25 == 0x04
&& V_13 . V_26 == 0x04 )
return V_19 ;
if ( V_13 . V_17 == V_24 ) {
if ( V_13 . V_25 == 0x3a && V_13 . V_26 == 1 )
return V_23 ;
else
return V_22 ;
}
return V_27 ;
}
unsigned int F_6 ( struct V_1 * V_2 ,
unsigned int V_28 , int V_9 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_29 ;
if ( V_9 == V_15 ) {
( void ) F_4 ( V_4 , NULL ) ;
V_29 = ( V_4 -> V_30 & V_31 ) ? 1 : 0 ;
V_4 -> V_30 &= ~ V_31 ;
return V_29 ? V_32 : 0 ;
} else {
return 0 ;
}
}
static
int F_7 ( T_1 * V_4 , int V_33 ,
struct V_12 * V_13 )
{
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_1 * V_2 = & V_35 -> V_37 ;
char V_38 = 0x02 ;
unsigned char V_39 [ V_40 ] ;
if ( ( V_4 -> V_7 & V_41 ) && ! V_33 )
return - V_42 ;
if ( ( V_4 -> V_7 & V_43 ) && V_33 )
return 0 ;
if ( V_33 && ( V_2 -> V_44 & V_45 ) )
V_38 = 0 ;
memset ( V_39 , 0 , V_40 ) ;
V_39 [ 0 ] = V_46 ;
V_39 [ 4 ] = V_38 | ( V_33 != 0 ) ;
return F_8 ( V_4 , V_39 , 0 , NULL , NULL , V_13 , 0 , 0 ) ;
}
static
int F_9 ( T_1 * V_4 , int V_47 ,
struct V_12 * V_13 )
{
struct V_12 V_48 ;
int V_14 ;
if ( V_13 == NULL )
V_13 = & V_48 ;
if ( ( V_4 -> V_30 & V_49 ) == 0 ) {
V_14 = 0 ;
} else {
unsigned char V_39 [ V_40 ] ;
memset ( V_39 , 0 , V_40 ) ;
V_39 [ 0 ] = V_50 ;
V_39 [ 4 ] = V_47 ? 1 : 0 ;
V_14 = F_8 ( V_4 , V_39 , 0 , NULL , NULL ,
V_13 , 0 , 0 ) ;
}
if ( V_14 != 0 &&
V_13 -> V_17 == V_51 &&
( V_13 -> V_25 == 0x24 || V_13 -> V_25 == 0x20 ) ) {
F_10 ( V_52 L_1 ,
V_4 -> V_53 ) ;
V_4 -> V_30 &= ~ V_49 ;
V_14 = 0 ;
}
if ( V_14 != 0 && V_13 -> V_17 == V_24 && V_13 -> V_25 == 0x3a )
V_14 = 0 ;
if ( V_14 == 0 ) {
if ( V_47 )
V_4 -> V_7 |= V_43 ;
else
V_4 -> V_7 &= ~ V_43 ;
}
return V_14 ;
}
int F_11 ( struct V_1 * V_2 , int V_54 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_12 V_13 ;
if ( V_54 ) {
int V_14 = F_9 ( V_4 , 0 , & V_13 ) ;
if ( V_14 )
return V_14 ;
}
return F_7 ( V_4 , ! V_54 , & V_13 ) ;
}
int F_12 ( struct V_1 * V_2 , int V_55 )
{
T_1 * V_4 = V_2 -> V_5 ;
return F_9 ( V_4 , V_55 , NULL ) ;
}
int F_13 ( struct V_1 * V_2 , int V_56 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_12 V_13 ;
T_2 V_57 [ V_58 ] ;
int V_14 ;
unsigned char V_39 [ V_40 ] ;
if ( V_56 == 0 )
V_56 = 0xffff ;
else
V_56 *= 177 ;
memset ( V_39 , 0 , V_40 ) ;
V_39 [ 0 ] = V_59 ;
V_39 [ 2 ] = ( V_56 >> 8 ) & 0xff ;
V_39 [ 3 ] = V_56 & 0xff ;
if ( ( V_2 -> V_44 & ( V_60 | V_61 | V_62 ) ) !=
( V_60 | V_61 | V_62 ) ) {
V_39 [ 4 ] = ( V_56 >> 8 ) & 0xff ;
V_39 [ 5 ] = V_56 & 0xff ;
}
V_14 = F_8 ( V_4 , V_39 , 0 , NULL , NULL , & V_13 , 0 , 0 ) ;
if ( ! F_14 ( V_4 , V_57 ) ) {
F_15 ( V_4 , V_57 ) ;
V_2 -> V_56 = V_35 -> V_63 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 ;
T_1 * V_4 = V_2 -> V_5 ;
struct V_34 * V_68 = V_4 -> V_36 ;
struct V_12 V_13 ;
int V_69 ;
if ( ( V_4 -> V_7 & V_8 ) == 0 || ! V_68 -> V_67 ) {
V_69 = F_17 ( V_4 , & V_13 ) ;
if ( V_69 )
return V_69 ;
}
V_67 = V_68 -> V_67 ;
V_65 -> V_70 . V_71 = V_67 -> V_72 ;
V_65 -> V_73 = V_67 -> V_73 ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_14 , V_76 ;
char V_57 [ 24 ] ;
unsigned char V_39 [ V_40 ] ;
unsigned V_77 = sizeof( V_57 ) ;
memset ( V_39 , 0 , V_40 ) ;
V_39 [ 0 ] = V_78 ;
V_39 [ 1 ] = 2 ;
V_39 [ 2 ] = 0x40 ;
V_39 [ 3 ] = 2 ;
V_39 [ 8 ] = V_77 ;
V_14 = F_8 ( V_4 , V_39 , 0 , V_57 , & V_77 , NULL , 0 , 0 ) ;
if ( V_14 )
return V_14 ;
V_76 = sizeof( V_75 -> V_79 ) - 1 ;
memcpy ( V_75 -> V_79 , V_57 + 9 , V_76 ) ;
V_75 -> V_79 [ V_76 ] = '\0' ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_12 V_13 ;
struct V_80 * V_81 ;
int V_69 ;
V_81 = F_20 ( V_4 -> V_82 , V_83 , V_84 ) ;
V_81 -> V_85 = V_86 ;
V_81 -> V_87 = V_88 ;
V_69 = F_21 ( V_4 -> V_82 , V_35 -> V_89 , V_81 , 0 ) ;
F_22 ( V_81 ) ;
if ( V_4 -> V_7 & V_43 )
( void ) F_9 ( V_4 , 1 , & V_13 ) ;
return V_69 ;
}
static int F_23 ( T_1 * V_4 , int V_90 ,
struct V_91 * * V_92 )
{
struct V_34 * V_68 = V_4 -> V_36 ;
struct V_66 * V_67 = V_68 -> V_67 ;
int V_93 ;
if ( ( V_4 -> V_7 & V_8 ) == 0 )
return - V_16 ;
V_93 = V_67 -> V_94 . V_95 - V_67 -> V_94 . V_96 + 1 ;
if ( V_67 -> V_94 . V_96 == V_97 )
V_93 = 0 ;
if ( V_90 == V_97 )
* V_92 = & V_67 -> V_92 [ V_93 ] ;
else if ( V_90 < V_67 -> V_94 . V_96 || V_90 > V_67 -> V_94 . V_95 )
return - V_16 ;
else
* V_92 = & V_67 -> V_92 [ V_90 - V_67 -> V_94 . V_96 ] ;
return 0 ;
}
static int F_24 ( T_1 * V_4 , void * V_98 )
{
struct V_99 * V_100 = V_98 ;
struct V_91 * V_101 , * V_102 ;
unsigned long V_103 , V_104 ;
int V_14 ;
struct V_12 V_13 ;
unsigned char V_39 [ V_40 ] ;
V_14 = F_23 ( V_4 , V_100 -> V_105 , & V_101 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_23 ( V_4 , V_100 -> V_106 , & V_102 ) ;
if ( V_14 )
return V_14 ;
if ( V_100 -> V_106 != V_97 )
++ V_102 ;
V_103 = V_101 -> V_70 . V_71 ;
V_104 = V_102 -> V_70 . V_71 ;
if ( V_104 <= V_103 )
return - V_16 ;
memset ( V_39 , 0 , V_40 ) ;
V_39 [ 0 ] = V_107 ;
F_25 ( V_103 , & V_39 [ 3 ] , & V_39 [ 4 ] , & V_39 [ 5 ] ) ;
F_25 ( V_104 - 1 , & V_39 [ 6 ] , & V_39 [ 7 ] , & V_39 [ 8 ] ) ;
return F_8 ( V_4 , V_39 , 0 , NULL , NULL , & V_13 , 0 , 0 ) ;
}
static int F_26 ( T_1 * V_4 , void * V_98 )
{
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_108 * V_109 = V_98 ;
struct V_66 * V_67 ;
int V_14 ;
V_14 = F_17 ( V_4 , NULL ) ;
if ( V_14 )
return V_14 ;
V_67 = V_35 -> V_67 ;
V_109 -> V_110 = V_67 -> V_94 . V_96 ;
V_109 -> V_111 = V_67 -> V_94 . V_95 ;
return 0 ;
}
static int F_27 ( T_1 * V_4 , void * V_98 )
{
struct V_112 * V_113 = V_98 ;
struct V_91 * V_114 ;
int V_14 ;
V_14 = F_23 ( V_4 , V_113 -> V_115 , & V_114 ) ;
if ( V_14 )
return V_14 ;
V_113 -> V_116 = V_114 -> V_117 ;
V_113 -> V_118 = V_114 -> V_119 ;
if ( V_113 -> V_120 == V_121 ) {
F_25 ( V_114 -> V_70 . V_71 ,
& V_113 -> V_122 . V_123 . V_124 ,
& V_113 -> V_122 . V_123 . V_125 ,
& V_113 -> V_122 . V_123 . V_126 ) ;
} else
V_113 -> V_122 . V_71 = V_114 -> V_70 . V_71 ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 ,
unsigned int V_39 , void * V_98 )
{
T_1 * V_4 = V_2 -> V_5 ;
switch ( V_39 ) {
case V_127 :
return F_24 ( V_4 , V_98 ) ;
case V_128 :
return F_26 ( V_4 , V_98 ) ;
case V_129 :
return F_27 ( V_4 , V_98 ) ;
default:
return - V_16 ;
}
}
int F_29 ( struct V_1 * V_2 ,
struct V_130 * V_131 )
{
T_1 * V_4 = V_2 -> V_5 ;
T_3 V_132 = 0 ;
unsigned V_77 = V_131 -> V_133 ;
if ( V_131 -> V_134 <= 0 )
V_131 -> V_134 = V_135 ;
if ( V_131 -> V_13 )
memset ( V_131 -> V_13 , 0 , sizeof( struct V_12 ) ) ;
if ( V_131 -> V_136 )
V_132 |= V_88 ;
V_131 -> V_14 = F_8 ( V_4 , V_131 -> V_39 ,
V_131 -> V_137 == V_138 ,
V_131 -> V_139 , & V_77 ,
V_131 -> V_13 , V_131 -> V_134 , V_132 ) ;
if ( ! V_131 -> V_14 )
V_131 -> V_133 -= V_77 ;
return V_131 -> V_14 ;
}
