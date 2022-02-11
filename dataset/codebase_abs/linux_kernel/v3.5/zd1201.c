static int F_1 ( struct V_1 * V_2 , int V_3 )
{
const struct V_4 * V_5 ;
const char * V_6 ;
unsigned long V_7 ;
int V_8 ;
unsigned char V_9 ;
char * V_10 ;
char * V_11 ;
if ( V_3 )
V_11 = L_1 ;
else
V_11 = L_2 ;
V_8 = F_2 ( & V_5 , V_11 , & V_2 -> V_2 ) ;
if ( V_8 ) {
F_3 ( & V_2 -> V_2 , L_3 , V_11 ) ;
F_3 ( & V_2 -> V_2 , L_4 ) ;
F_3 ( & V_2 -> V_2 , L_5 ) ;
return V_8 ;
}
V_6 = V_5 -> V_6 ;
V_7 = V_5 -> V_12 ;
V_10 = F_4 ( 1024 , V_13 ) ;
if ( ! V_10 )
goto exit;
while ( V_7 > 0 ) {
int V_14 = ( V_7 > 1024 ) ? 1024 : V_7 ;
memcpy ( V_10 , V_6 , V_14 ) ;
V_8 = F_5 ( V_2 , F_6 ( V_2 , 0 ) , 0 ,
V_15 | 0x40 , 0 , 0 , V_10 , V_14 ,
V_16 ) ;
if ( V_8 < 0 )
goto exit;
V_7 -= V_14 ;
V_6 += V_14 ;
}
V_8 = F_5 ( V_2 , F_6 ( V_2 , 0 ) , 0x2 ,
V_15 | 0x40 , 0 , 0 , NULL , 0 , V_16 ) ;
if ( V_8 < 0 )
goto exit;
V_8 = F_5 ( V_2 , F_7 ( V_2 , 0 ) , 0x4 ,
V_17 | 0x40 , 0 , 0 , & V_9 , sizeof( V_9 ) , V_16 ) ;
if ( V_8 < 0 )
goto exit;
if ( V_9 & 0x80 ) {
V_8 = - V_18 ;
goto exit;
}
V_8 = 0 ;
exit:
F_8 ( V_10 ) ;
F_9 ( V_5 ) ;
return V_8 ;
}
static void F_10 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
switch( V_19 -> V_23 ) {
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
F_11 ( & V_21 -> V_31 -> V_2 , L_6 ,
V_21 -> V_2 -> V_32 , V_19 -> V_23 ) ;
}
F_8 ( V_19 -> V_33 ) ;
F_12 ( V_19 ) ;
}
static int F_13 ( struct V_20 * V_21 , int V_34 , int V_35 ,
int V_36 , int V_37 )
{
unsigned char * V_38 ;
int V_9 ;
struct V_19 * V_19 ;
V_38 = F_4 ( 16 , V_13 ) ;
if ( ! V_38 )
return - V_39 ;
* ( ( V_40 * ) V_38 ) = F_14 ( V_41 ) ;
* ( ( V_42 * ) & V_38 [ 4 ] ) = F_15 ( V_34 ) ;
* ( ( V_42 * ) & V_38 [ 6 ] ) = F_15 ( V_35 ) ;
* ( ( V_42 * ) & V_38 [ 8 ] ) = F_15 ( V_36 ) ;
* ( ( V_42 * ) & V_38 [ 10 ] ) = F_15 ( V_37 ) ;
V_19 = F_16 ( 0 , V_13 ) ;
if ( ! V_19 ) {
F_8 ( V_38 ) ;
return - V_39 ;
}
F_17 ( V_19 , V_21 -> V_31 , F_18 ( V_21 -> V_31 , V_21 -> V_43 ) ,
V_38 , 16 , F_10 , V_21 ) ;
V_9 = F_19 ( V_19 , V_13 ) ;
if ( V_9 ) {
F_8 ( V_38 ) ;
F_12 ( V_19 ) ;
}
return V_9 ;
}
static void F_20 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
F_21 ( V_21 -> V_2 ) ;
}
static void F_22 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 ;
int free = 0 ;
unsigned char * V_6 = V_19 -> V_33 ;
struct V_44 * V_45 ;
unsigned char type ;
if ( ! V_21 )
return;
switch( V_19 -> V_23 ) {
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
F_11 ( & V_21 -> V_31 -> V_2 , L_7 ,
V_21 -> V_2 -> V_32 , V_19 -> V_23 ) ;
free = 1 ;
goto exit;
}
if ( V_19 -> V_23 != 0 || V_19 -> V_46 == 0 )
goto V_47;
type = V_6 [ 0 ] ;
if ( type == V_48 || type == V_49 ) {
memcpy ( V_21 -> V_50 , V_6 , V_19 -> V_46 ) ;
V_21 -> V_51 = V_19 -> V_46 ;
V_21 -> V_52 = 1 ;
F_23 ( & V_21 -> V_53 ) ;
}
if ( type == V_54 ) {
int V_55 = 0 ;
unsigned short V_56 , V_57 , V_58 ;
V_57 = F_24 ( * ( V_42 * ) & V_6 [ 4 ] ) ;
V_56 = F_24 ( * ( V_42 * ) & V_6 [ 6 ] ) ;
if ( V_56 == V_59 ) {
short V_60 ;
V_60 = F_24 ( * ( V_42 * ) & V_6 [ 8 ] ) ;
switch( V_60 ) {
case 1 :
F_25 ( V_21 -> V_2 ) ;
break;
case 2 :
F_26 ( V_21 -> V_2 ) ;
break;
case 3 :
F_26 ( V_21 -> V_2 ) ;
break;
case 4 :
F_25 ( V_21 -> V_2 ) ;
break;
default:
F_26 ( V_21 -> V_2 ) ;
}
goto V_47;
}
if ( V_56 == V_61 ) {
short V_23 = F_24 ( * ( V_42 * ) ( V_6 + 8 ) ) ;
int V_62 ;
union V_63 V_64 ;
switch ( V_23 ) {
case V_65 :
case V_66 :
V_62 = V_67 ;
break;
case V_68 :
case V_69 :
case V_70 :
default:
V_62 = V_71 ;
}
memcpy ( V_64 . V_72 . V_73 , V_6 + 10 , V_74 ) ;
V_64 . V_72 . V_75 = V_76 ;
F_27 ( V_21 -> V_2 , V_62 , & V_64 , NULL ) ;
goto V_47;
}
if ( V_56 == V_77 ) {
union V_63 V_64 ;
memcpy ( V_64 . V_72 . V_73 , V_6 + 8 , V_74 ) ;
V_64 . V_72 . V_75 = V_76 ;
F_27 ( V_21 -> V_2 , V_71 , & V_64 , NULL ) ;
goto V_47;
}
V_21 -> V_51 = 0 ;
while ( V_55 < V_19 -> V_46 ) {
V_58 = F_24 ( * ( V_42 * ) & V_6 [ V_55 + 2 ] ) ;
if ( V_58 + V_21 -> V_51 > sizeof( V_21 -> V_50 ) )
break;
memcpy ( V_21 -> V_50 + V_21 -> V_51 , V_6 + V_55 + 4 , V_58 ) ;
V_21 -> V_51 += V_58 ;
V_55 += 64 ;
}
if ( V_55 >= V_19 -> V_46 ) {
V_21 -> V_52 = 1 ;
F_23 ( & V_21 -> V_53 ) ;
}
goto V_47;
}
if ( V_6 [ V_19 -> V_46 - 1 ] == V_78 ) {
int V_79 = V_19 -> V_46 - 1 ;
unsigned short V_7 , V_80 , V_81 ;
struct V_82 * V_83 ;
V_7 = F_28 ( * ( V_84 * ) & V_6 [ V_79 - 2 ] ) ;
if ( V_7 > V_79 )
V_7 = V_79 ;
V_80 = F_24 ( * ( V_42 * ) & V_6 [ V_79 - 16 ] ) ;
V_81 = F_24 ( * ( V_42 * ) & V_6 [ V_79 - 24 ] ) ;
if ( V_21 -> V_85 ) {
if ( V_79 < 24 )
goto V_47;
if ( ! ( V_45 = F_29 ( V_79 + 24 ) ) )
goto V_47;
memcpy ( F_30 ( V_45 , 2 ) , & V_6 [ V_79 - 16 ] , 2 ) ;
memcpy ( F_30 ( V_45 , 2 ) , & V_6 [ V_79 - 2 ] , 2 ) ;
memcpy ( F_30 ( V_45 , 6 ) , & V_6 [ V_79 - 14 ] , 6 ) ;
memcpy ( F_30 ( V_45 , 6 ) , & V_6 [ V_79 - 22 ] , 6 ) ;
memcpy ( F_30 ( V_45 , 6 ) , & V_6 [ V_79 - 8 ] , 6 ) ;
memcpy ( F_30 ( V_45 , 2 ) , & V_6 [ V_79 - 24 ] , 2 ) ;
memcpy ( F_30 ( V_45 , V_7 ) , V_6 , V_7 ) ;
V_45 -> V_86 = F_31 ( V_45 , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_87 . V_88 ++ ;
V_21 -> V_2 -> V_87 . V_89 += V_45 -> V_7 ;
F_32 ( V_45 ) ;
goto V_47;
}
if ( ( V_81 & V_90 ) ||
( V_80 & V_91 ) ) {
struct V_92 * V_93 = NULL ;
char * V_94 ;
if ( V_79 < 14 )
goto V_47;
if ( ( V_81 & V_90 ) == 0 ) {
V_93 = F_4 ( sizeof( * V_93 ) , V_13 ) ;
if ( ! V_93 )
goto V_47;
V_45 = F_29 ( V_95 + 14 + 2 ) ;
if ( ! V_45 ) {
F_8 ( V_93 ) ;
goto V_47;
}
V_93 -> V_45 = V_45 ;
V_93 -> V_81 = V_81 & V_96 ;
F_33 ( V_45 , 2 ) ;
memcpy ( F_30 ( V_45 , 12 ) , & V_6 [ V_79 - 14 ] , 12 ) ;
memcpy ( F_30 ( V_45 , 2 ) , & V_6 [ 6 ] , 2 ) ;
memcpy ( F_30 ( V_45 , V_7 ) , V_6 + 8 , V_7 ) ;
F_34 ( & V_93 -> V_97 , & V_21 -> V_98 ) ;
goto V_47;
}
F_35 (frag, node, &zd->fraglist, fnode)
if ( V_93 -> V_81 == ( V_81 & V_96 ) )
break;
if ( ! V_93 )
goto V_47;
V_45 = V_93 -> V_45 ;
V_94 = F_30 ( V_45 , V_7 ) ;
if ( V_94 )
memcpy ( V_94 , V_6 + 8 , V_7 ) ;
if ( V_80 & V_91 )
goto V_47;
F_36 ( & V_93 -> V_97 ) ;
F_8 ( V_93 ) ;
} else {
if ( V_79 < 14 )
goto V_47;
V_45 = F_29 ( V_7 + 14 + 2 ) ;
if ( ! V_45 )
goto V_47;
F_33 ( V_45 , 2 ) ;
memcpy ( F_30 ( V_45 , 12 ) , & V_6 [ V_79 - 14 ] , 12 ) ;
memcpy ( F_30 ( V_45 , 2 ) , & V_6 [ 6 ] , 2 ) ;
memcpy ( F_30 ( V_45 , V_7 ) , V_6 + 8 , V_7 ) ;
}
V_45 -> V_86 = F_31 ( V_45 , V_21 -> V_2 ) ;
V_21 -> V_2 -> V_87 . V_88 ++ ;
V_21 -> V_2 -> V_87 . V_89 += V_45 -> V_7 ;
F_32 ( V_45 ) ;
}
V_47:
memset ( V_6 , 0 , V_99 ) ;
V_19 -> V_23 = 0 ;
V_19 -> V_2 = V_21 -> V_31 ;
if( F_19 ( V_19 , V_13 ) )
free = 1 ;
exit:
if ( free ) {
V_21 -> V_51 = 0 ;
V_21 -> V_52 = 1 ;
F_23 ( & V_21 -> V_53 ) ;
F_8 ( V_19 -> V_33 ) ;
}
}
static int F_37 ( struct V_20 * V_21 , int V_100 , void * V_101 ,
unsigned int V_102 )
{
int V_8 ;
int V_55 = 0 ;
int V_103 ;
int V_104 ;
int V_105 ;
unsigned char * V_106 ;
V_21 -> V_52 = 0 ;
V_8 = F_13 ( V_21 , V_107 , V_100 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
F_38 ( V_21 -> V_53 , V_21 -> V_52 ) ;
if ( ! V_21 -> V_51 )
return - V_18 ;
V_103 = F_24 ( * ( V_42 * ) ( & V_21 -> V_50 [ 4 ] ) ) ;
V_104 = F_24 ( * ( V_42 * ) ( & V_21 -> V_50 [ 6 ] ) ) ;
V_105 = F_24 ( * ( V_42 * ) ( & V_21 -> V_50 [ 8 ] ) ) ;
if ( V_105 > V_21 -> V_51 )
V_105 = V_21 -> V_51 - 6 ;
if ( ( V_103 & V_108 ) != V_108 || V_104 != V_100 )
return - V_109 ;
if ( V_102 != ( V_105 - 4 ) ) {
F_39 ( & V_21 -> V_31 -> V_2 , L_8 ,
V_102 , V_21 -> V_51 , V_105 , V_100 , V_104 ) ;
return - V_110 ;
}
V_21 -> V_52 = 0 ;
V_8 = F_13 ( V_21 , V_111 , V_100 , 0 , V_105 ) ;
if ( V_8 )
return V_8 ;
F_38 ( V_21 -> V_53 , V_21 -> V_52 ) ;
if ( ! V_21 -> V_51 )
return - V_18 ;
if ( V_21 -> V_50 [ V_21 -> V_51 - 1 ] != V_49 ) {
F_39 ( & V_21 -> V_31 -> V_2 , L_9 ,
V_21 -> V_50 [ V_21 -> V_51 - 1 ] ) ;
return - V_109 ;
}
V_106 = V_21 -> V_50 ;
V_105 = V_21 -> V_51 ;
do {
int V_46 ;
V_46 = ( V_105 > 64 ) ? 64 : V_105 ;
if ( V_106 [ 0 ] != 0x3 ) {
F_39 ( & V_21 -> V_31 -> V_2 , L_10 ,
V_106 [ 0 ] ) ;
return - V_109 ;
}
if ( V_46 != 64 ) {
V_46 -- ;
}
if ( V_55 == 0 ) {
V_106 += 8 ;
V_46 -= 8 ;
} else {
V_106 += 4 ;
V_46 -= 4 ;
}
memcpy ( V_101 , V_106 , V_46 ) ;
V_101 += V_46 ;
V_106 += V_46 ;
V_105 -= 64 ;
V_55 ++ ;
} while ( V_105 > 0 );
return 0 ;
}
static int F_40 ( struct V_20 * V_21 , int V_100 , void * V_10 , int V_7 , int V_112 )
{
int V_8 ;
unsigned char * V_113 ;
int V_114 ;
char V_81 = 0 ;
struct V_19 * V_19 ;
T_1 V_115 = V_112 ? V_116 : V_13 ;
V_7 += 4 ;
V_21 -> V_52 = 0 ;
V_21 -> V_51 = 0 ;
for ( V_81 = 0 ; V_7 > 0 ; V_81 ++ ) {
V_113 = F_4 ( 16 , V_115 ) ;
if ( ! V_113 )
return - V_39 ;
V_19 = F_16 ( 0 , V_115 ) ;
if ( ! V_19 ) {
F_8 ( V_113 ) ;
return - V_39 ;
}
memset ( V_113 , 0 , 16 ) ;
V_114 = V_7 > 12 ? 12 : V_7 ;
V_113 [ 0 ] = V_117 ;
V_113 [ 1 ] = V_81 ;
V_113 [ 2 ] = 0 ;
V_113 [ 3 ] = 0 ;
if ( V_113 [ 1 ] == 0 ) {
* ( V_42 * ) & V_113 [ 4 ] = F_15 ( ( V_7 - 2 + 1 ) / 2 ) ;
* ( V_42 * ) & V_113 [ 6 ] = F_15 ( V_100 ) ;
memcpy ( V_113 + 8 , V_10 , V_114 - 4 ) ;
V_10 += V_114 - 4 ;
} else {
memcpy ( V_113 + 4 , V_10 , V_114 ) ;
V_10 += V_114 ;
}
V_7 -= V_114 ;
F_17 ( V_19 , V_21 -> V_31 , F_18 ( V_21 -> V_31 ,
V_21 -> V_43 ) , V_113 , 16 , F_10 , V_21 ) ;
V_8 = F_19 ( V_19 , V_115 ) ;
if ( V_8 )
goto V_8;
}
V_113 = F_4 ( 16 , V_115 ) ;
if ( ! V_113 )
return - V_39 ;
V_19 = F_16 ( 0 , V_115 ) ;
if ( ! V_19 ) {
F_8 ( V_113 ) ;
return - V_39 ;
}
* ( ( V_40 * ) V_113 ) = F_14 ( V_41 ) ;
* ( ( V_42 * ) & V_113 [ 4 ] ) =
F_15 ( V_107 | V_108 ) ;
* ( ( V_42 * ) & V_113 [ 6 ] ) = F_15 ( V_100 ) ;
* ( ( V_42 * ) & V_113 [ 8 ] ) = F_15 ( 0 ) ;
* ( ( V_42 * ) & V_113 [ 10 ] ) = F_15 ( 0 ) ;
F_17 ( V_19 , V_21 -> V_31 , F_18 ( V_21 -> V_31 , V_21 -> V_43 ) ,
V_113 , 16 , F_10 , V_21 ) ;
V_8 = F_19 ( V_19 , V_115 ) ;
if ( V_8 )
goto V_8;
if ( V_112 ) {
F_38 ( V_21 -> V_53 , V_21 -> V_52 ) ;
if ( ! V_21 -> V_51 || F_24 ( * ( V_42 * ) & V_21 -> V_50 [ 6 ] ) != V_100 ) {
F_39 ( & V_21 -> V_31 -> V_2 , L_11 ) ;
}
}
return 0 ;
V_8:
F_8 ( V_113 ) ;
F_12 ( V_19 ) ;
return V_8 ;
}
static inline int F_41 ( struct V_20 * V_21 , int V_100 , short * V_118 )
{
int V_8 ;
V_42 V_119 ;
V_8 = F_37 ( V_21 , V_100 , & V_119 , sizeof( V_42 ) ) ;
if ( V_8 )
return V_8 ;
* V_118 = F_24 ( V_119 ) ;
return 0 ;
}
static inline int F_42 ( struct V_20 * V_21 , int V_100 , short V_118 )
{
V_42 V_119 = F_15 ( V_118 ) ;
return ( F_40 ( V_21 , V_100 , & V_119 , sizeof( V_42 ) , 1 ) ) ;
}
static int F_43 ( struct V_20 * V_21 )
{
int V_8 , V_55 ;
short V_120 ;
V_42 V_121 ;
unsigned char * V_122 ;
V_122 = F_44 ( V_99 , V_123 ) ;
if ( ! V_122 )
return - V_39 ;
F_17 ( V_21 -> V_124 , V_21 -> V_31 ,
F_45 ( V_21 -> V_31 , V_21 -> V_125 ) , V_122 , V_99 ,
F_22 , V_21 ) ;
V_8 = F_19 ( V_21 -> V_124 , V_123 ) ;
if ( V_8 )
goto V_126;
V_8 = F_13 ( V_21 , V_127 , 0 , 0 , 0 ) ;
if ( V_8 )
goto V_128;
V_8 = F_37 ( V_21 , V_129 , & V_121 ,
sizeof( V_42 ) ) ;
if ( V_8 )
goto V_128;
V_120 = F_24 ( V_121 ) ;
for ( V_55 = 0 ; V_55 < V_120 ; V_55 ++ ) {
V_8 = F_13 ( V_21 , V_130 , 1514 , 0 , 0 ) ;
if ( V_8 )
goto V_128;
}
return 0 ;
V_128:
F_46 ( V_21 -> V_124 ) ;
return V_8 ;
V_126:
F_8 ( V_122 ) ;
return V_8 ;
}
static int F_47 ( struct V_20 * V_21 )
{
int V_8 ;
if ( V_21 -> V_131 )
return 0 ;
V_8 = F_13 ( V_21 , V_132 , 0 , 0 , 0 ) ;
if ( ! V_8 )
V_21 -> V_131 = 1 ;
if ( V_21 -> V_85 )
V_8 = F_42 ( V_21 , V_133 , 1 ) ;
return V_8 ;
}
static int F_48 ( struct V_20 * V_21 )
{
int V_8 ;
if ( ! V_21 -> V_131 )
return 0 ;
if ( V_21 -> V_85 ) {
V_8 = F_42 ( V_21 , V_133 , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_13 ( V_21 , V_134 , 0 , 0 , 0 ) ;
if ( ! V_8 )
V_21 -> V_131 = 0 ;
return V_8 ;
}
static int F_49 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_131 )
return 0 ;
F_48 ( V_21 ) ;
return F_47 ( V_21 ) ;
}
static int F_50 ( struct V_20 * V_21 , char * V_135 , int V_136 )
{
int V_8 , V_118 ;
char V_10 [ V_137 + 2 ] ;
V_8 = F_48 ( V_21 ) ;
if ( V_8 )
return V_8 ;
V_118 = V_138 ;
V_118 |= V_139 ;
V_8 = F_42 ( V_21 , V_140 , V_118 ) ;
if ( V_8 )
return V_8 ;
* ( V_42 * ) V_10 = F_15 ( V_136 ) ;
memcpy ( V_10 + 2 , V_135 , V_136 ) ;
if ( ! V_21 -> V_141 ) {
V_8 = F_40 ( V_21 , V_142 , V_10 ,
V_137 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
} else {
V_8 = F_40 ( V_21 , V_143 , V_10 ,
V_137 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_40 ( V_21 , V_144 ,
V_21 -> V_2 -> V_145 , V_21 -> V_2 -> V_146 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_47 ( V_21 ) ;
if ( V_8 )
return V_8 ;
F_51 ( 100 ) ;
return 0 ;
}
static int F_52 ( struct V_147 * V_2 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
if ( ! V_21 -> V_131 )
F_50 ( V_21 , V_21 -> V_135 , V_21 -> V_136 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_147 * V_2 )
{
F_56 ( V_2 ) ;
return 0 ;
}
static T_2 F_57 ( struct V_44 * V_45 ,
struct V_147 * V_2 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
unsigned char * V_148 = V_21 -> V_149 ;
int V_150 , V_151 = 0 , V_8 ;
struct V_19 * V_19 = V_21 -> V_152 ;
if ( ! V_21 -> V_131 || V_21 -> V_85 ) {
V_2 -> V_87 . V_153 ++ ;
F_58 ( V_45 ) ;
return V_154 ;
}
F_56 ( V_2 ) ;
V_150 = V_45 -> V_7 + 8 + 1 ;
if ( V_150 % 64 == 0 ) {
V_151 = 1 ;
V_150 ++ ;
}
V_148 [ 0 ] = 0xAA ;
V_148 [ 1 ] = 0xAA ;
V_148 [ 2 ] = 0x03 ;
V_148 [ 3 ] = 0x00 ;
V_148 [ 4 ] = 0x00 ;
V_148 [ 5 ] = 0x00 ;
F_59 ( V_45 , 12 , V_148 + 6 , V_45 -> V_7 - 12 ) ;
if ( V_151 )
V_148 [ V_45 -> V_7 - 12 + 6 ] = 0 ;
F_60 ( V_45 , V_148 + V_45 -> V_7 - 12 + 6 + V_151 , 12 ) ;
* ( V_84 * ) & V_148 [ V_45 -> V_7 + 6 + V_151 ] = F_61 ( V_45 -> V_7 - 12 + 6 ) ;
V_148 [ V_150 - 1 ] = 0 ;
F_17 ( V_19 , V_21 -> V_31 , F_18 ( V_21 -> V_31 , V_21 -> V_155 ) ,
V_148 , V_150 , F_20 , V_21 ) ;
V_8 = F_19 ( V_21 -> V_152 , V_13 ) ;
if ( V_8 ) {
V_2 -> V_87 . V_156 ++ ;
F_54 ( V_2 ) ;
} else {
V_2 -> V_87 . V_157 ++ ;
V_2 -> V_87 . V_158 += V_45 -> V_7 ;
}
F_58 ( V_45 ) ;
return V_154 ;
}
static void F_62 ( struct V_147 * V_2 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
if ( ! V_21 )
return;
F_11 ( & V_21 -> V_31 -> V_2 , L_12 ,
V_2 -> V_32 ) ;
F_63 ( V_21 -> V_152 ) ;
V_2 -> V_87 . V_156 ++ ;
V_2 -> V_159 = V_160 ;
}
static int F_64 ( struct V_147 * V_2 , void * V_161 )
{
struct V_162 * V_72 = V_161 ;
struct V_20 * V_21 = F_53 ( V_2 ) ;
int V_8 ;
if ( ! V_21 )
return - V_25 ;
V_8 = F_40 ( V_21 , V_144 ,
V_72 -> V_73 , V_2 -> V_146 , 1 ) ;
if ( V_8 )
return V_8 ;
memcpy ( V_2 -> V_145 , V_72 -> V_73 , V_2 -> V_146 ) ;
return F_49 ( V_21 ) ;
}
static struct V_163 * F_65 ( struct V_147 * V_2 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
return & V_21 -> V_164 ;
}
static void F_66 ( struct V_147 * V_2 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
struct V_165 * V_166 ;
unsigned char V_167 [ V_74 * V_168 ] ;
int V_55 ;
if ( F_67 ( V_2 ) > V_168 )
return;
V_55 = 0 ;
F_68 (ha, dev)
memcpy ( V_167 + V_55 ++ * V_74 , V_166 -> V_72 , V_74 ) ;
F_40 ( V_21 , V_169 , V_167 ,
F_67 ( V_2 ) * V_74 , 0 ) ;
}
static int F_69 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_6 , char * V_135 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
return F_49 ( V_21 ) ;
}
static int F_70 ( struct V_147 * V_2 ,
struct V_170 * V_171 , char * V_32 , char * V_173 )
{
strcpy ( V_32 , L_13 ) ;
return 0 ;
}
static int F_71 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_174 * V_175 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_176 = 0 ;
int V_8 ;
if ( V_175 -> V_177 == 0 )
V_176 = V_175 -> V_178 ;
else {
V_176 = F_72 ( V_175 -> V_178 ) ;
if ( V_176 < 0 )
V_176 = 0 ;
}
V_8 = F_42 ( V_21 , V_179 , V_176 ) ;
if ( V_8 )
return V_8 ;
F_49 ( V_21 ) ;
return 0 ;
}
static int F_73 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_174 * V_175 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_176 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_179 , & V_176 ) ;
if ( V_8 )
return V_8 ;
V_175 -> V_177 = 0 ;
V_175 -> V_178 = V_176 ;
return 0 ;
}
static int F_74 ( struct V_147 * V_2 ,
struct V_170 * V_171 , T_3 * V_180 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_181 , V_85 = 0 ;
unsigned char V_122 [ V_137 + 2 ] ;
int V_8 ;
if ( V_21 -> V_141 ) {
if ( * V_180 != V_182 )
return - V_109 ;
return 0 ;
}
V_8 = F_42 ( V_21 , V_133 , 0 ) ;
if ( V_8 )
return V_8 ;
V_21 -> V_2 -> type = V_76 ;
switch( * V_180 ) {
case V_183 :
V_85 = 1 ;
V_21 -> V_2 -> type = V_184 ;
F_50 ( V_21 , L_14 , 5 ) ;
case 8 :
V_181 = V_185 ;
break;
case V_186 :
V_181 = V_187 ;
break;
case V_188 :
V_181 = V_189 ;
break;
default:
return - V_109 ;
}
V_8 = F_42 ( V_21 , V_190 , V_181 ) ;
if ( V_8 )
return V_8 ;
if ( V_21 -> V_85 && ! V_85 ) {
F_48 ( V_21 ) ;
* ( V_42 * ) V_122 = F_15 ( V_21 -> V_136 ) ;
memcpy ( V_122 + 2 , V_21 -> V_135 , V_21 -> V_136 ) ;
V_8 = F_40 ( V_21 , V_142 ,
V_122 , V_137 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_21 -> V_85 = V_85 ;
F_49 ( V_21 ) ;
return 0 ;
}
static int F_75 ( struct V_147 * V_2 ,
struct V_170 * V_171 , T_3 * V_180 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_181 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_190 , & V_181 ) ;
if ( V_8 )
return V_8 ;
switch( V_181 ) {
case V_187 :
* V_180 = V_186 ;
break;
case V_189 :
* V_180 = V_188 ;
break;
case V_191 :
* V_180 = V_192 ;
break;
case V_185 :
* V_180 = 8 ;
break;
case V_193 :
* V_180 = V_182 ;
break;
default:
F_39 ( & V_21 -> V_31 -> V_2 , L_15 ,
V_181 ) ;
* V_180 = V_194 ;
}
if ( V_21 -> V_85 )
* V_180 = V_183 ;
return 0 ;
}
static int F_76 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_195 , char * V_173 )
{
struct V_196 * V_197 = (struct V_196 * ) V_173 ;
V_195 -> V_105 = sizeof( struct V_196 ) ;
memset ( V_197 , 0 , sizeof( struct V_196 ) ) ;
V_197 -> V_198 = V_199 ;
V_197 -> V_200 = V_199 ;
V_197 -> V_201 . V_202 = 128 ;
V_197 -> V_201 . V_203 = 128 ;
V_197 -> V_201 . V_204 = 128 ;
V_197 -> V_201 . V_205 = 7 ;
V_197 -> V_206 [ 0 ] = 5 ;
V_197 -> V_206 [ 1 ] = 13 ;
V_197 -> V_207 = 2 ;
V_197 -> V_208 = V_209 ;
V_197 -> V_210 = 4 ;
V_197 -> V_211 [ 0 ] = 1000000 ;
V_197 -> V_211 [ 1 ] = 2000000 ;
V_197 -> V_211 [ 2 ] = 5500000 ;
V_197 -> V_211 [ 3 ] = 11000000 ;
V_197 -> V_212 = 0 ;
V_197 -> V_213 = V_214 ;
V_197 -> V_215 = V_216 ;
V_197 -> V_213 = V_217 ;
return 0 ;
}
static int F_77 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_162 * V_218 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
unsigned char V_122 [ 6 ] ;
if ( ! F_37 ( V_21 , V_219 , V_122 , 6 ) ) {
V_21 -> V_164 . V_202 . V_203 = F_24 ( ( ( V_42 * ) V_122 ) [ 1 ] ) ;
V_21 -> V_164 . V_202 . V_205 = 2 ;
}
return F_37 ( V_21 , V_220 , V_218 -> V_73 , 6 ) ;
}
static int F_78 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_221 , char * V_173 )
{
return 0 ;
}
static int F_79 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_221 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
int V_8 , V_55 , V_222 , V_223 ;
struct V_224 V_225 ;
char * V_226 = V_173 ;
char * V_227 = V_173 + V_228 ;
if ( V_21 -> V_141 )
return - V_229 ;
V_223 = V_21 -> V_131 ;
F_47 ( V_21 ) ;
V_21 -> V_52 = 0 ;
V_8 = F_13 ( V_21 , V_230 ,
V_231 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
F_38 ( V_21 -> V_53 , V_21 -> V_52 ) ;
if ( ! V_21 -> V_51 )
return - V_18 ;
if ( F_24 ( * ( V_42 * ) & V_21 -> V_50 [ 2 ] ) != V_231 )
return - V_18 ;
for( V_55 = 8 ; V_55 < V_21 -> V_51 ; V_55 += 62 ) {
V_225 . V_34 = V_232 ;
V_225 . V_233 . V_218 . V_75 = V_76 ;
memcpy ( V_225 . V_233 . V_218 . V_73 , V_21 -> V_50 + V_55 + 6 , 6 ) ;
V_226 = F_80 ( V_171 , V_226 , V_227 ,
& V_225 , V_234 ) ;
V_225 . V_34 = V_235 ;
V_225 . V_233 . V_6 . V_105 = V_21 -> V_50 [ V_55 + 16 ] ;
V_225 . V_233 . V_6 . V_236 = 1 ;
V_226 = F_81 ( V_171 , V_226 , V_227 ,
& V_225 , V_21 -> V_50 + V_55 + 18 ) ;
V_225 . V_34 = V_237 ;
if ( V_21 -> V_50 [ V_55 + 14 ] & 0x01 )
V_225 . V_233 . V_180 = V_182 ;
else
V_225 . V_233 . V_180 = V_186 ;
V_226 = F_80 ( V_171 , V_226 , V_227 ,
& V_225 , V_238 ) ;
V_225 . V_34 = V_239 ;
V_225 . V_233 . V_175 . V_178 = V_21 -> V_50 [ V_55 + 0 ] ;
V_225 . V_233 . V_175 . V_177 = 0 ;
V_226 = F_80 ( V_171 , V_226 , V_227 ,
& V_225 , V_240 ) ;
V_225 . V_34 = V_241 ;
V_225 . V_233 . V_211 . V_242 = 0 ;
V_225 . V_233 . V_211 . V_243 = 0 ;
for ( V_222 = 0 ; V_222 < 10 ; V_222 ++ ) if ( V_21 -> V_50 [ V_55 + 50 + V_222 ] ) {
V_225 . V_233 . V_211 . V_244 = ( V_21 -> V_50 [ V_55 + 50 + V_222 ] & 0x7f ) * 500000 ;
V_226 = F_80 ( V_171 , V_226 , V_227 ,
& V_225 , V_245 ) ;
}
V_225 . V_34 = V_246 ;
V_225 . V_233 . V_6 . V_105 = 0 ;
if ( V_21 -> V_50 [ V_55 + 14 ] & 0x10 )
V_225 . V_233 . V_6 . V_236 = V_247 ;
else
V_225 . V_233 . V_6 . V_236 = V_248 ;
V_226 = F_81 ( V_171 , V_226 , V_227 , & V_225 , NULL ) ;
V_225 . V_34 = V_249 ;
V_225 . V_233 . V_202 . V_202 = V_21 -> V_50 [ V_55 + 4 ] ;
V_225 . V_233 . V_202 . V_204 = V_21 -> V_50 [ V_55 + 2 ] / 10 - 100 ;
V_225 . V_233 . V_202 . V_203 = ( 256 + V_21 -> V_50 [ V_55 + 4 ] * 100 ) / 255 - 100 ;
V_225 . V_233 . V_202 . V_205 = 7 ;
V_226 = F_80 ( V_171 , V_226 , V_227 ,
& V_225 , V_250 ) ;
}
if ( ! V_223 )
F_48 ( V_21 ) ;
V_221 -> V_105 = V_226 - V_173 ;
V_221 -> V_236 = 0 ;
return 0 ;
}
static int F_82 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_6 , char * V_135 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
if ( V_6 -> V_105 > V_137 )
return - V_109 ;
if ( V_6 -> V_105 < 1 )
V_6 -> V_105 = 1 ;
V_21 -> V_136 = V_6 -> V_105 ;
memset ( V_21 -> V_135 , 0 , V_137 + 1 ) ;
memcpy ( V_21 -> V_135 , V_135 , V_6 -> V_105 ) ;
return F_50 ( V_21 , V_21 -> V_135 , V_21 -> V_136 ) ;
}
static int F_83 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_6 , char * V_135 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
memcpy ( V_135 , V_21 -> V_135 , V_21 -> V_136 ) ;
V_6 -> V_236 = 1 ;
V_6 -> V_105 = V_21 -> V_136 ;
return 0 ;
}
static int F_84 ( struct V_147 * V_2 , struct V_170 * V_171 ,
struct V_172 * V_6 , char * V_251 )
{
strcpy ( V_251 , L_16 ) ;
V_6 -> V_236 = 1 ;
V_6 -> V_105 = strlen ( V_251 ) ;
return 0 ;
}
static int F_85 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_254 ;
int V_8 ;
switch ( V_253 -> V_244 ) {
case 1000000 :
V_254 = V_255 ;
break;
case 2000000 :
V_254 = V_256 ;
break;
case 5500000 :
V_254 = V_257 ;
break;
case 11000000 :
default:
V_254 = V_258 ;
break;
}
if ( ! V_253 -> V_242 ) {
V_254 |= V_254 - 1 ;
}
V_8 = F_42 ( V_21 , V_259 , V_254 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_21 ) ;
}
static int F_86 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_254 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_260 , & V_254 ) ;
if ( V_8 )
return V_8 ;
switch( V_254 ) {
case 1 :
V_253 -> V_244 = 1000000 ;
break;
case 2 :
V_253 -> V_244 = 2000000 ;
break;
case 5 :
V_253 -> V_244 = 5500000 ;
break;
case 11 :
V_253 -> V_244 = 11000000 ;
break;
default:
V_253 -> V_244 = 0 ;
}
V_253 -> V_242 = 0 ;
V_253 -> V_243 = 0 ;
return 0 ;
}
static int F_87 ( struct V_147 * V_2 , struct V_170 * V_171 ,
struct V_252 * V_261 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
int V_8 ;
short V_118 = V_261 -> V_244 ;
if ( V_261 -> V_243 || ! V_261 -> V_242 )
V_118 = V_216 ;
if ( V_118 > V_216 )
return - V_109 ;
if ( V_118 < 0 )
return - V_109 ;
V_8 = F_42 ( V_21 , V_262 , V_118 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_21 ) ;
}
static int F_88 ( struct V_147 * V_2 , struct V_170 * V_171 ,
struct V_252 * V_261 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_263 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_262 , & V_263 ) ;
if ( V_8 )
return V_8 ;
V_261 -> V_244 = V_263 ;
V_261 -> V_243 = ( V_261 -> V_244 == V_216 ) ;
V_261 -> V_242 = 1 ;
return 0 ;
}
static int F_89 ( struct V_147 * V_2 , struct V_170 * V_171 ,
struct V_252 * V_93 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
int V_8 ;
short V_118 = V_93 -> V_244 ;
if ( V_93 -> V_243 || ! V_93 -> V_242 )
V_118 = V_217 ;
if ( V_118 > V_217 )
return - V_109 ;
if ( V_118 < V_214 )
return - V_109 ;
if ( V_118 & 1 )
return - V_109 ;
V_8 = F_42 ( V_21 , V_264 , V_118 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_21 ) ;
}
static int F_90 ( struct V_147 * V_2 , struct V_170 * V_171 ,
struct V_252 * V_93 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_265 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_264 , & V_265 ) ;
if ( V_8 )
return V_8 ;
V_93 -> V_244 = V_265 ;
V_93 -> V_243 = ( V_93 -> V_244 == V_217 ) ;
V_93 -> V_242 = 1 ;
return 0 ;
}
static int F_91 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
return 0 ;
}
static int F_92 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
return 0 ;
}
static int F_93 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_266 , char * V_267 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_55 ;
int V_8 , V_100 ;
if ( V_266 -> V_105 > V_268 )
return - V_109 ;
V_55 = ( V_266 -> V_236 & V_269 ) - 1 ;
if ( V_55 == - 1 ) {
V_8 = F_41 ( V_21 , V_270 , & V_55 ) ;
if ( V_8 )
return V_8 ;
} else {
V_8 = F_42 ( V_21 , V_270 , V_55 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_55 < 0 || V_55 >= V_209 )
return - V_109 ;
V_100 = V_271 + V_55 ;
V_8 = F_40 ( V_21 , V_100 , V_267 , V_266 -> V_105 , 1 ) ;
if ( V_8 )
return V_8 ;
V_21 -> V_272 [ V_55 ] = V_266 -> V_105 ;
memcpy ( V_21 -> V_273 [ V_55 ] , V_267 , V_266 -> V_105 ) ;
V_55 = 0 ;
if ( ! ( V_266 -> V_236 & V_248 & V_274 ) ) {
V_55 |= 0x01 ;
V_21 -> V_275 = 1 ;
} else
V_21 -> V_275 = 0 ;
if ( V_266 -> V_236 & V_276 & V_274 ) {
V_55 |= 0x02 ;
V_21 -> V_277 = 1 ;
} else
V_21 -> V_277 = 0 ;
V_8 = F_42 ( V_21 , V_278 , V_55 ) ;
if ( V_8 )
return V_8 ;
if ( V_21 -> V_275 )
V_55 = V_139 ;
else
V_55 = V_138 ;
V_8 = F_42 ( V_21 , V_140 , V_55 ) ;
if ( V_8 )
return V_8 ;
return F_49 ( V_21 ) ;
}
static int F_94 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_172 * V_266 , char * V_267 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_55 ;
int V_8 ;
if ( V_21 -> V_275 )
V_266 -> V_236 = V_247 ;
else
V_266 -> V_236 = V_248 ;
if ( V_21 -> V_277 )
V_266 -> V_236 |= V_276 ;
else
V_266 -> V_236 |= V_279 ;
V_55 = ( V_266 -> V_236 & V_269 ) - 1 ;
if ( V_55 == - 1 ) {
V_8 = F_41 ( V_21 , V_270 , & V_55 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_55 < 0 || V_55 >= V_209 )
return - V_109 ;
V_266 -> V_236 |= V_55 + 1 ;
V_266 -> V_105 = V_21 -> V_272 [ V_55 ] ;
memcpy ( V_267 , V_21 -> V_273 [ V_55 ] , V_266 -> V_105 ) ;
return 0 ;
}
static int F_95 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_280 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_281 , V_282 , V_203 ;
int V_8 ;
V_281 = V_280 -> V_243 ? 0 : 1 ;
if ( V_281 ) {
if ( V_280 -> V_236 & V_283 ) {
V_282 = V_280 -> V_244 ;
V_8 = F_42 ( V_21 ,
V_284 , V_282 ) ;
if ( V_8 )
return V_8 ;
goto V_285;
}
if ( V_280 -> V_236 & V_286 ) {
V_8 = F_41 ( V_21 ,
V_284 , & V_282 ) ;
if ( V_8 )
return V_8 ;
V_203 = V_280 -> V_244 * 4 / V_282 ;
if ( V_203 > 4 )
V_203 = 4 ;
if ( V_203 < 0 )
V_203 = 0 ;
V_8 = F_42 ( V_21 , V_287 ,
V_203 ) ;
if ( V_8 )
return V_8 ;
goto V_285;
}
return - V_109 ;
}
V_285:
return F_42 ( V_21 , V_288 , V_281 ) ;
}
static int F_96 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_280 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_281 , V_203 , V_282 ;
int V_8 ;
V_8 = F_41 ( V_21 , V_288 , & V_281 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_41 ( V_21 , V_287 , & V_203 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_41 ( V_21 , V_284 , & V_282 ) ;
if ( V_8 )
return V_8 ;
V_280 -> V_243 = V_281 ? 0 : 1 ;
if ( V_280 -> V_236 & V_289 ) {
if ( V_280 -> V_236 & V_283 ) {
V_280 -> V_244 = V_282 ;
V_280 -> V_236 = V_283 ;
} else {
V_280 -> V_244 = V_282 * V_203 / 4 ;
V_280 -> V_236 = V_286 ;
}
}
if ( V_280 -> V_236 & V_290 ) {
if ( V_281 && V_203 )
V_280 -> V_236 = V_291 ;
else
V_280 -> V_236 = V_292 ;
}
return 0 ;
}
static int F_97 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
if ( ! V_21 -> V_141 )
return - V_229 ;
return F_42 ( V_21 , V_293 , V_253 -> V_244 ) ;
}
static int F_98 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_294 ;
int V_8 ;
if ( ! V_21 -> V_141 )
return - V_229 ;
V_8 = F_41 ( V_21 , V_293 , & V_294 ) ;
if ( V_8 )
return V_8 ;
V_253 -> V_244 = V_294 ;
V_253 -> V_242 = 1 ;
return 0 ;
}
static int F_99 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_162 * V_295 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
unsigned char V_122 [ 10 ] ;
if ( ! V_21 -> V_141 )
return - V_229 ;
memcpy ( V_122 , V_295 -> V_73 , V_74 ) ;
* ( short * ) ( V_122 + 6 ) = 0 ;
* ( short * ) ( V_122 + 8 ) = 0 ;
return F_40 ( V_21 , V_296 , V_122 , 10 , 1 ) ;
}
static int F_100 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
int V_8 ;
if ( ! V_21 -> V_141 )
return - V_229 ;
V_8 = F_42 ( V_21 , V_297 , V_253 -> V_244 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_101 ( struct V_147 * V_2 ,
struct V_170 * V_171 , struct V_252 * V_253 , char * V_173 )
{
struct V_20 * V_21 = F_53 ( V_2 ) ;
short V_298 ;
int V_8 ;
if ( ! V_21 -> V_141 )
return - V_229 ;
V_8 = F_41 ( V_21 , V_297 , & V_298 ) ;
if ( V_8 )
return V_8 ;
V_253 -> V_244 = V_298 ;
V_253 -> V_242 = 1 ;
return 0 ;
}
static int F_102 ( struct V_299 * V_300 ,
const struct V_301 * V_302 )
{
struct V_20 * V_21 ;
struct V_147 * V_2 ;
struct V_1 * V_31 ;
int V_8 ;
short V_181 ;
char V_10 [ V_137 + 2 ] ;
V_31 = F_103 ( V_300 ) ;
V_2 = F_104 ( sizeof( * V_21 ) ) ;
if ( ! V_2 )
return - V_39 ;
V_21 = F_53 ( V_2 ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_141 = V_141 ;
V_21 -> V_31 = V_31 ;
V_21 -> V_303 = 0 ;
F_105 ( & V_21 -> V_53 ) ;
F_106 ( & V_21 -> V_98 ) ;
V_8 = F_1 ( V_31 , V_21 -> V_141 ) ;
if ( V_8 ) {
F_3 ( & V_31 -> V_2 , L_17 , V_8 ) ;
goto V_304;
}
V_21 -> V_125 = 1 ;
V_21 -> V_155 = 1 ;
V_21 -> V_43 = 2 ;
V_21 -> V_124 = F_16 ( 0 , V_123 ) ;
V_21 -> V_152 = F_16 ( 0 , V_123 ) ;
if ( ! V_21 -> V_124 || ! V_21 -> V_152 )
goto V_304;
F_107 ( 100 ) ;
V_8 = F_43 ( V_21 ) ;
if ( V_8 )
goto V_304;
V_8 = F_42 ( V_21 , V_305 , 2312 ) ;
if ( V_8 )
goto V_306;
V_8 = F_42 ( V_21 , V_259 ,
V_255 | V_256 | V_257 | V_258 ) ;
if ( V_8 )
goto V_306;
V_2 -> V_307 = & V_308 ;
V_2 -> V_309 = & V_310 ;
V_2 -> V_311 = V_312 ;
strcpy ( V_2 -> V_32 , L_18 ) ;
V_8 = F_37 ( V_21 , V_144 ,
V_2 -> V_145 , V_2 -> V_146 ) ;
if ( V_8 )
goto V_306;
* ( V_42 * ) V_10 = F_15 ( 0 ) ;
V_8 = F_40 ( V_21 , V_142 , V_10 ,
V_137 + 2 , 1 ) ;
if ( V_8 )
goto V_306;
if ( V_21 -> V_141 )
V_181 = V_193 ;
else
V_181 = V_189 ;
V_8 = F_42 ( V_21 , V_190 , V_181 ) ;
if ( V_8 )
goto V_306;
F_108 ( V_2 , & V_31 -> V_2 ) ;
V_8 = F_109 ( V_2 ) ;
if ( V_8 )
goto V_306;
F_110 ( & V_31 -> V_2 , L_19 ,
V_2 -> V_32 ) ;
F_111 ( V_300 , V_21 ) ;
F_47 ( V_21 ) ;
F_48 ( V_21 ) ;
return 0 ;
V_306:
F_13 ( V_21 , V_127 , 0 , 0 , 0 ) ;
V_304:
F_12 ( V_21 -> V_152 ) ;
F_12 ( V_21 -> V_124 ) ;
F_112 ( V_2 ) ;
return V_8 ;
}
static void F_113 ( struct V_299 * V_300 )
{
struct V_20 * V_21 = F_114 ( V_300 ) ;
struct V_82 * V_83 , * V_313 ;
struct V_92 * V_93 ;
if ( ! V_21 )
return;
F_111 ( V_300 , NULL ) ;
F_115 (frag, node, node2, &zd->fraglist, fnode) {
F_36 ( & V_93 -> V_97 ) ;
F_58 ( V_93 -> V_45 ) ;
F_8 ( V_93 ) ;
}
if ( V_21 -> V_152 ) {
F_46 ( V_21 -> V_152 ) ;
F_12 ( V_21 -> V_152 ) ;
}
if ( V_21 -> V_124 ) {
F_46 ( V_21 -> V_124 ) ;
F_12 ( V_21 -> V_124 ) ;
}
if ( V_21 -> V_2 ) {
F_116 ( V_21 -> V_2 ) ;
F_112 ( V_21 -> V_2 ) ;
}
}
static int F_117 ( struct V_299 * V_300 ,
T_4 V_314 )
{
struct V_20 * V_21 = F_114 ( V_300 ) ;
F_118 ( V_21 -> V_2 ) ;
V_21 -> V_315 = V_21 -> V_131 ;
if ( V_21 -> V_315 )
return F_48 ( V_21 ) ;
else
return 0 ;
}
static int F_119 ( struct V_299 * V_300 )
{
struct V_20 * V_21 = F_114 ( V_300 ) ;
if ( ! V_21 || ! V_21 -> V_2 )
return - V_25 ;
F_120 ( V_21 -> V_2 ) ;
if ( V_21 -> V_315 )
return F_47 ( V_21 ) ;
else
return 0 ;
}
