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
if ( ! V_10 ) {
V_8 = - V_14 ;
goto exit;
}
while ( V_7 > 0 ) {
int V_15 = ( V_7 > 1024 ) ? 1024 : V_7 ;
memcpy ( V_10 , V_6 , V_15 ) ;
V_8 = F_5 ( V_2 , F_6 ( V_2 , 0 ) , 0 ,
V_16 | 0x40 , 0 , 0 , V_10 , V_15 ,
V_17 ) ;
if ( V_8 < 0 )
goto exit;
V_7 -= V_15 ;
V_6 += V_15 ;
}
V_8 = F_5 ( V_2 , F_6 ( V_2 , 0 ) , 0x2 ,
V_16 | 0x40 , 0 , 0 , NULL , 0 , V_17 ) ;
if ( V_8 < 0 )
goto exit;
V_8 = F_5 ( V_2 , F_7 ( V_2 , 0 ) , 0x4 ,
V_18 | 0x40 , 0 , 0 , V_10 , sizeof( V_9 ) , V_17 ) ;
if ( V_8 < 0 )
goto exit;
memcpy ( & V_9 , V_10 , sizeof( V_9 ) ) ;
if ( V_9 & 0x80 ) {
V_8 = - V_19 ;
goto exit;
}
V_8 = 0 ;
exit:
F_8 ( V_10 ) ;
F_9 ( V_5 ) ;
return V_8 ;
}
static void F_10 ( struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
switch( V_20 -> V_24 ) {
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
F_11 ( & V_22 -> V_32 -> V_2 , L_6 ,
V_22 -> V_2 -> V_33 , V_20 -> V_24 ) ;
}
F_8 ( V_20 -> V_34 ) ;
F_12 ( V_20 ) ;
}
static int F_13 ( struct V_21 * V_22 , int V_35 , int V_36 ,
int V_37 , int V_38 )
{
unsigned char * V_39 ;
int V_9 ;
struct V_20 * V_20 ;
V_39 = F_4 ( 16 , V_13 ) ;
if ( ! V_39 )
return - V_14 ;
* ( ( V_40 * ) V_39 ) = F_14 ( V_41 ) ;
* ( ( V_42 * ) & V_39 [ 4 ] ) = F_15 ( V_35 ) ;
* ( ( V_42 * ) & V_39 [ 6 ] ) = F_15 ( V_36 ) ;
* ( ( V_42 * ) & V_39 [ 8 ] ) = F_15 ( V_37 ) ;
* ( ( V_42 * ) & V_39 [ 10 ] ) = F_15 ( V_38 ) ;
V_20 = F_16 ( 0 , V_13 ) ;
if ( ! V_20 ) {
F_8 ( V_39 ) ;
return - V_14 ;
}
F_17 ( V_20 , V_22 -> V_32 , F_18 ( V_22 -> V_32 , V_22 -> V_43 ) ,
V_39 , 16 , F_10 , V_22 ) ;
V_9 = F_19 ( V_20 , V_13 ) ;
if ( V_9 ) {
F_8 ( V_39 ) ;
F_12 ( V_20 ) ;
}
return V_9 ;
}
static void F_20 ( struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
F_21 ( V_22 -> V_2 ) ;
}
static void F_22 ( struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
int free = 0 ;
unsigned char * V_6 = V_20 -> V_34 ;
struct V_44 * V_45 ;
unsigned char type ;
if ( ! V_22 )
return;
switch( V_20 -> V_24 ) {
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
F_11 ( & V_22 -> V_32 -> V_2 , L_7 ,
V_22 -> V_2 -> V_33 , V_20 -> V_24 ) ;
free = 1 ;
goto exit;
}
if ( V_20 -> V_24 != 0 || V_20 -> V_46 == 0 )
goto V_47;
type = V_6 [ 0 ] ;
if ( type == V_48 || type == V_49 ) {
memcpy ( V_22 -> V_50 , V_6 , V_20 -> V_46 ) ;
V_22 -> V_51 = V_20 -> V_46 ;
V_22 -> V_52 = 1 ;
F_23 ( & V_22 -> V_53 ) ;
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
F_25 ( V_22 -> V_2 ) ;
break;
case 2 :
F_26 ( V_22 -> V_2 ) ;
break;
case 3 :
F_26 ( V_22 -> V_2 ) ;
break;
case 4 :
F_25 ( V_22 -> V_2 ) ;
break;
default:
F_26 ( V_22 -> V_2 ) ;
}
goto V_47;
}
if ( V_56 == V_61 ) {
short V_24 = F_24 ( * ( V_42 * ) ( V_6 + 8 ) ) ;
int V_62 ;
union V_63 V_64 ;
switch ( V_24 ) {
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
F_27 ( V_22 -> V_2 , V_62 , & V_64 , NULL ) ;
goto V_47;
}
if ( V_56 == V_77 ) {
union V_63 V_64 ;
memcpy ( V_64 . V_72 . V_73 , V_6 + 8 , V_74 ) ;
V_64 . V_72 . V_75 = V_76 ;
F_27 ( V_22 -> V_2 , V_71 , & V_64 , NULL ) ;
goto V_47;
}
V_22 -> V_51 = 0 ;
while ( V_55 < V_20 -> V_46 ) {
V_58 = F_24 ( * ( V_42 * ) & V_6 [ V_55 + 2 ] ) ;
if ( V_58 + V_22 -> V_51 > sizeof( V_22 -> V_50 ) )
break;
memcpy ( V_22 -> V_50 + V_22 -> V_51 , V_6 + V_55 + 4 , V_58 ) ;
V_22 -> V_51 += V_58 ;
V_55 += 64 ;
}
if ( V_55 >= V_20 -> V_46 ) {
V_22 -> V_52 = 1 ;
F_23 ( & V_22 -> V_53 ) ;
}
goto V_47;
}
if ( V_6 [ V_20 -> V_46 - 1 ] == V_78 ) {
int V_79 = V_20 -> V_46 - 1 ;
unsigned short V_7 , V_80 , V_81 ;
V_7 = F_28 ( * ( V_82 * ) & V_6 [ V_79 - 2 ] ) ;
if ( V_7 > V_79 )
V_7 = V_79 ;
V_80 = F_24 ( * ( V_42 * ) & V_6 [ V_79 - 16 ] ) ;
V_81 = F_24 ( * ( V_42 * ) & V_6 [ V_79 - 24 ] ) ;
if ( V_22 -> V_83 ) {
if ( V_79 < 24 )
goto V_47;
if ( ! ( V_45 = F_29 ( V_79 + 24 ) ) )
goto V_47;
F_30 ( V_45 , & V_6 [ V_79 - 16 ] , 2 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 2 ] , 2 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 14 ] , 6 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 22 ] , 6 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 8 ] , 6 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 24 ] , 2 ) ;
F_30 ( V_45 , V_6 , V_7 ) ;
V_45 -> V_84 = F_31 ( V_45 , V_22 -> V_2 ) ;
V_22 -> V_2 -> V_85 . V_86 ++ ;
V_22 -> V_2 -> V_85 . V_87 += V_45 -> V_7 ;
F_32 ( V_45 ) ;
goto V_47;
}
if ( ( V_81 & V_88 ) ||
( V_80 & V_89 ) ) {
struct V_90 * V_91 = NULL ;
char * V_92 ;
if ( V_79 < 14 )
goto V_47;
if ( ( V_81 & V_88 ) == 0 ) {
V_91 = F_4 ( sizeof( * V_91 ) , V_13 ) ;
if ( ! V_91 )
goto V_47;
V_45 = F_29 ( V_93 + 14 + 2 ) ;
if ( ! V_45 ) {
F_8 ( V_91 ) ;
goto V_47;
}
V_91 -> V_45 = V_45 ;
V_91 -> V_81 = V_81 & V_94 ;
F_33 ( V_45 , 2 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 14 ] , 12 ) ;
F_30 ( V_45 , & V_6 [ 6 ] , 2 ) ;
F_30 ( V_45 , V_6 + 8 , V_7 ) ;
F_34 ( & V_91 -> V_95 , & V_22 -> V_96 ) ;
goto V_47;
}
F_35 (frag, &zd->fraglist, fnode)
if ( V_91 -> V_81 == ( V_81 & V_94 ) )
break;
if ( ! V_91 )
goto V_47;
V_45 = V_91 -> V_45 ;
V_92 = F_36 ( V_45 , V_7 ) ;
if ( V_92 )
memcpy ( V_92 , V_6 + 8 , V_7 ) ;
if ( V_80 & V_89 )
goto V_47;
F_37 ( & V_91 -> V_95 ) ;
F_8 ( V_91 ) ;
} else {
if ( V_79 < 14 )
goto V_47;
V_45 = F_29 ( V_7 + 14 + 2 ) ;
if ( ! V_45 )
goto V_47;
F_33 ( V_45 , 2 ) ;
F_30 ( V_45 , & V_6 [ V_79 - 14 ] , 12 ) ;
F_30 ( V_45 , & V_6 [ 6 ] , 2 ) ;
F_30 ( V_45 , V_6 + 8 , V_7 ) ;
}
V_45 -> V_84 = F_31 ( V_45 , V_22 -> V_2 ) ;
V_22 -> V_2 -> V_85 . V_86 ++ ;
V_22 -> V_2 -> V_85 . V_87 += V_45 -> V_7 ;
F_32 ( V_45 ) ;
}
V_47:
memset ( V_6 , 0 , V_97 ) ;
V_20 -> V_24 = 0 ;
V_20 -> V_2 = V_22 -> V_32 ;
if( F_19 ( V_20 , V_13 ) )
free = 1 ;
exit:
if ( free ) {
V_22 -> V_51 = 0 ;
V_22 -> V_52 = 1 ;
F_23 ( & V_22 -> V_53 ) ;
F_8 ( V_20 -> V_34 ) ;
}
}
static int F_38 ( struct V_21 * V_22 , int V_98 , void * V_99 ,
unsigned int V_100 )
{
int V_8 ;
int V_55 = 0 ;
int V_101 ;
int V_102 ;
int V_103 ;
unsigned char * V_104 ;
V_22 -> V_52 = 0 ;
V_8 = F_13 ( V_22 , V_105 , V_98 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
F_39 ( V_22 -> V_53 , V_22 -> V_52 ) ;
if ( ! V_22 -> V_51 )
return - V_19 ;
V_101 = F_24 ( * ( V_42 * ) ( & V_22 -> V_50 [ 4 ] ) ) ;
V_102 = F_24 ( * ( V_42 * ) ( & V_22 -> V_50 [ 6 ] ) ) ;
V_103 = F_24 ( * ( V_42 * ) ( & V_22 -> V_50 [ 8 ] ) ) ;
if ( V_103 > V_22 -> V_51 )
V_103 = V_22 -> V_51 - 6 ;
if ( ( V_101 & V_106 ) != V_106 || V_102 != V_98 )
return - V_107 ;
if ( V_100 != ( V_103 - 4 ) ) {
F_40 ( & V_22 -> V_32 -> V_2 , L_8 ,
V_100 , V_22 -> V_51 , V_103 , V_98 , V_102 ) ;
return - V_108 ;
}
V_22 -> V_52 = 0 ;
V_8 = F_13 ( V_22 , V_109 , V_98 , 0 , V_103 ) ;
if ( V_8 )
return V_8 ;
F_39 ( V_22 -> V_53 , V_22 -> V_52 ) ;
if ( ! V_22 -> V_51 )
return - V_19 ;
if ( V_22 -> V_50 [ V_22 -> V_51 - 1 ] != V_49 ) {
F_40 ( & V_22 -> V_32 -> V_2 , L_9 ,
V_22 -> V_50 [ V_22 -> V_51 - 1 ] ) ;
return - V_107 ;
}
V_104 = V_22 -> V_50 ;
V_103 = V_22 -> V_51 ;
do {
int V_46 ;
V_46 = ( V_103 > 64 ) ? 64 : V_103 ;
if ( V_104 [ 0 ] != 0x3 ) {
F_40 ( & V_22 -> V_32 -> V_2 , L_10 ,
V_104 [ 0 ] ) ;
return - V_107 ;
}
if ( V_46 != 64 ) {
V_46 -- ;
}
if ( V_55 == 0 ) {
V_104 += 8 ;
V_46 -= 8 ;
} else {
V_104 += 4 ;
V_46 -= 4 ;
}
memcpy ( V_99 , V_104 , V_46 ) ;
V_99 += V_46 ;
V_104 += V_46 ;
V_103 -= 64 ;
V_55 ++ ;
} while ( V_103 > 0 );
return 0 ;
}
static int F_41 ( struct V_21 * V_22 , int V_98 , void * V_10 , int V_7 , int V_110 )
{
int V_8 ;
unsigned char * V_111 ;
int V_112 ;
char V_81 = 0 ;
struct V_20 * V_20 ;
T_1 V_113 = V_110 ? V_114 : V_13 ;
V_7 += 4 ;
V_22 -> V_52 = 0 ;
V_22 -> V_51 = 0 ;
for ( V_81 = 0 ; V_7 > 0 ; V_81 ++ ) {
V_111 = F_4 ( 16 , V_113 ) ;
if ( ! V_111 )
return - V_14 ;
V_20 = F_16 ( 0 , V_113 ) ;
if ( ! V_20 ) {
F_8 ( V_111 ) ;
return - V_14 ;
}
memset ( V_111 , 0 , 16 ) ;
V_112 = V_7 > 12 ? 12 : V_7 ;
V_111 [ 0 ] = V_115 ;
V_111 [ 1 ] = V_81 ;
V_111 [ 2 ] = 0 ;
V_111 [ 3 ] = 0 ;
if ( V_111 [ 1 ] == 0 ) {
* ( V_42 * ) & V_111 [ 4 ] = F_15 ( ( V_7 - 2 + 1 ) / 2 ) ;
* ( V_42 * ) & V_111 [ 6 ] = F_15 ( V_98 ) ;
memcpy ( V_111 + 8 , V_10 , V_112 - 4 ) ;
V_10 += V_112 - 4 ;
} else {
memcpy ( V_111 + 4 , V_10 , V_112 ) ;
V_10 += V_112 ;
}
V_7 -= V_112 ;
F_17 ( V_20 , V_22 -> V_32 , F_18 ( V_22 -> V_32 ,
V_22 -> V_43 ) , V_111 , 16 , F_10 , V_22 ) ;
V_8 = F_19 ( V_20 , V_113 ) ;
if ( V_8 )
goto V_8;
}
V_111 = F_4 ( 16 , V_113 ) ;
if ( ! V_111 )
return - V_14 ;
V_20 = F_16 ( 0 , V_113 ) ;
if ( ! V_20 ) {
F_8 ( V_111 ) ;
return - V_14 ;
}
* ( ( V_40 * ) V_111 ) = F_14 ( V_41 ) ;
* ( ( V_42 * ) & V_111 [ 4 ] ) =
F_15 ( V_105 | V_106 ) ;
* ( ( V_42 * ) & V_111 [ 6 ] ) = F_15 ( V_98 ) ;
* ( ( V_42 * ) & V_111 [ 8 ] ) = F_15 ( 0 ) ;
* ( ( V_42 * ) & V_111 [ 10 ] ) = F_15 ( 0 ) ;
F_17 ( V_20 , V_22 -> V_32 , F_18 ( V_22 -> V_32 , V_22 -> V_43 ) ,
V_111 , 16 , F_10 , V_22 ) ;
V_8 = F_19 ( V_20 , V_113 ) ;
if ( V_8 )
goto V_8;
if ( V_110 ) {
F_39 ( V_22 -> V_53 , V_22 -> V_52 ) ;
if ( ! V_22 -> V_51 || F_24 ( * ( V_42 * ) & V_22 -> V_50 [ 6 ] ) != V_98 ) {
F_40 ( & V_22 -> V_32 -> V_2 , L_11 ) ;
}
}
return 0 ;
V_8:
F_8 ( V_111 ) ;
F_12 ( V_20 ) ;
return V_8 ;
}
static inline int F_42 ( struct V_21 * V_22 , int V_98 , short * V_116 )
{
int V_8 ;
V_42 V_117 ;
V_8 = F_38 ( V_22 , V_98 , & V_117 , sizeof( V_42 ) ) ;
if ( V_8 )
return V_8 ;
* V_116 = F_24 ( V_117 ) ;
return 0 ;
}
static inline int F_43 ( struct V_21 * V_22 , int V_98 , short V_116 )
{
V_42 V_117 = F_15 ( V_116 ) ;
return ( F_41 ( V_22 , V_98 , & V_117 , sizeof( V_42 ) , 1 ) ) ;
}
static int F_44 ( struct V_21 * V_22 )
{
int V_8 , V_55 ;
short V_118 ;
V_42 V_119 ;
unsigned char * V_120 ;
V_120 = F_45 ( V_97 , V_121 ) ;
if ( ! V_120 )
return - V_14 ;
F_17 ( V_22 -> V_122 , V_22 -> V_32 ,
F_46 ( V_22 -> V_32 , V_22 -> V_123 ) , V_120 , V_97 ,
F_22 , V_22 ) ;
V_8 = F_19 ( V_22 -> V_122 , V_121 ) ;
if ( V_8 )
goto V_124;
V_8 = F_13 ( V_22 , V_125 , 0 , 0 , 0 ) ;
if ( V_8 )
goto V_126;
V_8 = F_38 ( V_22 , V_127 , & V_119 ,
sizeof( V_42 ) ) ;
if ( V_8 )
goto V_126;
V_118 = F_24 ( V_119 ) ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ ) {
V_8 = F_13 ( V_22 , V_128 , 1514 , 0 , 0 ) ;
if ( V_8 )
goto V_126;
}
return 0 ;
V_126:
F_47 ( V_22 -> V_122 ) ;
return V_8 ;
V_124:
F_8 ( V_120 ) ;
return V_8 ;
}
static int F_48 ( struct V_21 * V_22 )
{
int V_8 ;
if ( V_22 -> V_129 )
return 0 ;
V_8 = F_13 ( V_22 , V_130 , 0 , 0 , 0 ) ;
if ( ! V_8 )
V_22 -> V_129 = 1 ;
if ( V_22 -> V_83 )
V_8 = F_43 ( V_22 , V_131 , 1 ) ;
return V_8 ;
}
static int F_49 ( struct V_21 * V_22 )
{
int V_8 ;
if ( ! V_22 -> V_129 )
return 0 ;
if ( V_22 -> V_83 ) {
V_8 = F_43 ( V_22 , V_131 , 0 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_13 ( V_22 , V_132 , 0 , 0 , 0 ) ;
if ( ! V_8 )
V_22 -> V_129 = 0 ;
return V_8 ;
}
static int F_50 ( struct V_21 * V_22 )
{
if ( ! V_22 -> V_129 )
return 0 ;
F_49 ( V_22 ) ;
return F_48 ( V_22 ) ;
}
static int F_51 ( struct V_21 * V_22 , char * V_133 , int V_134 )
{
int V_8 , V_116 ;
char V_10 [ V_135 + 2 ] ;
V_8 = F_49 ( V_22 ) ;
if ( V_8 )
return V_8 ;
V_116 = V_136 ;
V_116 |= V_137 ;
V_8 = F_43 ( V_22 , V_138 , V_116 ) ;
if ( V_8 )
return V_8 ;
* ( V_42 * ) V_10 = F_15 ( V_134 ) ;
memcpy ( V_10 + 2 , V_133 , V_134 ) ;
if ( ! V_22 -> V_139 ) {
V_8 = F_41 ( V_22 , V_140 , V_10 ,
V_135 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
} else {
V_8 = F_41 ( V_22 , V_141 , V_10 ,
V_135 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_41 ( V_22 , V_142 ,
V_22 -> V_2 -> V_143 , V_22 -> V_2 -> V_144 , 1 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_48 ( V_22 ) ;
if ( V_8 )
return V_8 ;
F_52 ( 100 ) ;
return 0 ;
}
static int F_53 ( struct V_145 * V_2 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
if ( ! V_22 -> V_129 )
F_51 ( V_22 , V_22 -> V_133 , V_22 -> V_134 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_145 * V_2 )
{
F_57 ( V_2 ) ;
return 0 ;
}
static T_2 F_58 ( struct V_44 * V_45 ,
struct V_145 * V_2 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
unsigned char * V_146 = V_22 -> V_147 ;
int V_148 , V_149 = 0 , V_8 ;
struct V_20 * V_20 = V_22 -> V_150 ;
if ( ! V_22 -> V_129 || V_22 -> V_83 ) {
V_2 -> V_85 . V_151 ++ ;
F_59 ( V_45 ) ;
return V_152 ;
}
F_57 ( V_2 ) ;
V_148 = V_45 -> V_7 + 8 + 1 ;
if ( V_148 % 64 == 0 ) {
V_149 = 1 ;
V_148 ++ ;
}
V_146 [ 0 ] = 0xAA ;
V_146 [ 1 ] = 0xAA ;
V_146 [ 2 ] = 0x03 ;
V_146 [ 3 ] = 0x00 ;
V_146 [ 4 ] = 0x00 ;
V_146 [ 5 ] = 0x00 ;
F_60 ( V_45 , 12 , V_146 + 6 , V_45 -> V_7 - 12 ) ;
if ( V_149 )
V_146 [ V_45 -> V_7 - 12 + 6 ] = 0 ;
F_61 ( V_45 , V_146 + V_45 -> V_7 - 12 + 6 + V_149 , 12 ) ;
* ( V_82 * ) & V_146 [ V_45 -> V_7 + 6 + V_149 ] = F_62 ( V_45 -> V_7 - 12 + 6 ) ;
V_146 [ V_148 - 1 ] = 0 ;
F_17 ( V_20 , V_22 -> V_32 , F_18 ( V_22 -> V_32 , V_22 -> V_153 ) ,
V_146 , V_148 , F_20 , V_22 ) ;
V_8 = F_19 ( V_22 -> V_150 , V_13 ) ;
if ( V_8 ) {
V_2 -> V_85 . V_154 ++ ;
F_55 ( V_2 ) ;
} else {
V_2 -> V_85 . V_155 ++ ;
V_2 -> V_85 . V_156 += V_45 -> V_7 ;
}
F_59 ( V_45 ) ;
return V_152 ;
}
static void F_63 ( struct V_145 * V_2 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
if ( ! V_22 )
return;
F_11 ( & V_22 -> V_32 -> V_2 , L_12 ,
V_2 -> V_33 ) ;
F_64 ( V_22 -> V_150 ) ;
V_2 -> V_85 . V_154 ++ ;
F_65 ( V_2 ) ;
}
static int F_66 ( struct V_145 * V_2 , void * V_157 )
{
struct V_158 * V_72 = V_157 ;
struct V_21 * V_22 = F_54 ( V_2 ) ;
int V_8 ;
if ( ! V_22 )
return - V_26 ;
V_8 = F_41 ( V_22 , V_142 ,
V_72 -> V_73 , V_2 -> V_144 , 1 ) ;
if ( V_8 )
return V_8 ;
memcpy ( V_2 -> V_143 , V_72 -> V_73 , V_2 -> V_144 ) ;
return F_50 ( V_22 ) ;
}
static struct V_159 * F_67 ( struct V_145 * V_2 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
return & V_22 -> V_160 ;
}
static void F_68 ( struct V_145 * V_2 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
struct V_161 * V_162 ;
unsigned char V_163 [ V_74 * V_164 ] ;
int V_55 ;
if ( F_69 ( V_2 ) > V_164 )
return;
V_55 = 0 ;
F_70 (ha, dev)
memcpy ( V_163 + V_55 ++ * V_74 , V_162 -> V_72 , V_74 ) ;
F_41 ( V_22 , V_165 , V_163 ,
F_69 ( V_2 ) * V_74 , 0 ) ;
}
static int F_71 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_6 , char * V_133 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
return F_50 ( V_22 ) ;
}
static int F_72 ( struct V_145 * V_2 ,
struct V_166 * V_167 , char * V_33 , char * V_169 )
{
strcpy ( V_33 , L_13 ) ;
return 0 ;
}
static int F_73 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_170 * V_171 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_172 = 0 ;
int V_8 ;
if ( V_171 -> V_173 == 0 )
V_172 = V_171 -> V_174 ;
else
V_172 = F_74 ( V_171 -> V_174 ) ;
V_8 = F_43 ( V_22 , V_175 , V_172 ) ;
if ( V_8 )
return V_8 ;
F_50 ( V_22 ) ;
return 0 ;
}
static int F_75 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_170 * V_171 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_172 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_175 , & V_172 ) ;
if ( V_8 )
return V_8 ;
V_171 -> V_173 = 0 ;
V_171 -> V_174 = V_172 ;
return 0 ;
}
static int F_76 ( struct V_145 * V_2 ,
struct V_166 * V_167 , T_3 * V_176 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_177 , V_83 = 0 ;
unsigned char V_120 [ V_135 + 2 ] ;
int V_8 ;
if ( V_22 -> V_139 ) {
if ( * V_176 != V_178 )
return - V_107 ;
return 0 ;
}
V_8 = F_43 ( V_22 , V_131 , 0 ) ;
if ( V_8 )
return V_8 ;
V_22 -> V_2 -> type = V_76 ;
switch( * V_176 ) {
case V_179 :
V_83 = 1 ;
V_22 -> V_2 -> type = V_180 ;
F_51 ( V_22 , L_14 , 5 ) ;
case 8 :
V_177 = V_181 ;
break;
case V_182 :
V_177 = V_183 ;
break;
case V_184 :
V_177 = V_185 ;
break;
default:
return - V_107 ;
}
V_8 = F_43 ( V_22 , V_186 , V_177 ) ;
if ( V_8 )
return V_8 ;
if ( V_22 -> V_83 && ! V_83 ) {
F_49 ( V_22 ) ;
* ( V_42 * ) V_120 = F_15 ( V_22 -> V_134 ) ;
memcpy ( V_120 + 2 , V_22 -> V_133 , V_22 -> V_134 ) ;
V_8 = F_41 ( V_22 , V_140 ,
V_120 , V_135 + 2 , 1 ) ;
if ( V_8 )
return V_8 ;
}
V_22 -> V_83 = V_83 ;
F_50 ( V_22 ) ;
return 0 ;
}
static int F_77 ( struct V_145 * V_2 ,
struct V_166 * V_167 , T_3 * V_176 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_177 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_186 , & V_177 ) ;
if ( V_8 )
return V_8 ;
switch( V_177 ) {
case V_183 :
* V_176 = V_182 ;
break;
case V_185 :
* V_176 = V_184 ;
break;
case V_187 :
* V_176 = V_188 ;
break;
case V_181 :
* V_176 = 8 ;
break;
case V_189 :
* V_176 = V_178 ;
break;
default:
F_40 ( & V_22 -> V_32 -> V_2 , L_15 ,
V_177 ) ;
* V_176 = V_190 ;
}
if ( V_22 -> V_83 )
* V_176 = V_179 ;
return 0 ;
}
static int F_78 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_191 , char * V_169 )
{
struct V_192 * V_193 = (struct V_192 * ) V_169 ;
V_191 -> V_103 = sizeof( struct V_192 ) ;
memset ( V_193 , 0 , sizeof( struct V_192 ) ) ;
V_193 -> V_194 = V_195 ;
V_193 -> V_196 = V_195 ;
V_193 -> V_197 . V_198 = 128 ;
V_193 -> V_197 . V_199 = 128 ;
V_193 -> V_197 . V_200 = 128 ;
V_193 -> V_197 . V_201 = 7 ;
V_193 -> V_202 [ 0 ] = 5 ;
V_193 -> V_202 [ 1 ] = 13 ;
V_193 -> V_203 = 2 ;
V_193 -> V_204 = V_205 ;
V_193 -> V_206 = 4 ;
V_193 -> V_207 [ 0 ] = 1000000 ;
V_193 -> V_207 [ 1 ] = 2000000 ;
V_193 -> V_207 [ 2 ] = 5500000 ;
V_193 -> V_207 [ 3 ] = 11000000 ;
V_193 -> V_208 = 0 ;
V_193 -> V_209 = V_210 ;
V_193 -> V_211 = V_212 ;
V_193 -> V_209 = V_213 ;
return 0 ;
}
static int F_79 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_158 * V_214 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
unsigned char V_120 [ 6 ] ;
if ( ! F_38 ( V_22 , V_215 , V_120 , 6 ) ) {
V_22 -> V_160 . V_198 . V_199 = F_24 ( ( ( V_42 * ) V_120 ) [ 1 ] ) ;
V_22 -> V_160 . V_198 . V_201 = 2 ;
}
return F_38 ( V_22 , V_216 , V_214 -> V_73 , 6 ) ;
}
static int F_80 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_217 , char * V_169 )
{
return 0 ;
}
static int F_81 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_217 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
int V_8 , V_55 , V_218 , V_219 ;
struct V_220 V_221 ;
char * V_222 = V_169 ;
char * V_223 = V_169 + V_224 ;
if ( V_22 -> V_139 )
return - V_225 ;
V_219 = V_22 -> V_129 ;
F_48 ( V_22 ) ;
V_22 -> V_52 = 0 ;
V_8 = F_13 ( V_22 , V_226 ,
V_227 , 0 , 0 ) ;
if ( V_8 )
return V_8 ;
F_39 ( V_22 -> V_53 , V_22 -> V_52 ) ;
if ( ! V_22 -> V_51 )
return - V_19 ;
if ( F_24 ( * ( V_42 * ) & V_22 -> V_50 [ 2 ] ) != V_227 )
return - V_19 ;
for( V_55 = 8 ; V_55 < V_22 -> V_51 ; V_55 += 62 ) {
V_221 . V_35 = V_228 ;
V_221 . V_229 . V_214 . V_75 = V_76 ;
memcpy ( V_221 . V_229 . V_214 . V_73 , V_22 -> V_50 + V_55 + 6 , 6 ) ;
V_222 = F_82 ( V_167 , V_222 , V_223 ,
& V_221 , V_230 ) ;
V_221 . V_35 = V_231 ;
V_221 . V_229 . V_6 . V_103 = V_22 -> V_50 [ V_55 + 16 ] ;
V_221 . V_229 . V_6 . V_232 = 1 ;
V_222 = F_83 ( V_167 , V_222 , V_223 ,
& V_221 , V_22 -> V_50 + V_55 + 18 ) ;
V_221 . V_35 = V_233 ;
if ( V_22 -> V_50 [ V_55 + 14 ] & 0x01 )
V_221 . V_229 . V_176 = V_178 ;
else
V_221 . V_229 . V_176 = V_182 ;
V_222 = F_82 ( V_167 , V_222 , V_223 ,
& V_221 , V_234 ) ;
V_221 . V_35 = V_235 ;
V_221 . V_229 . V_171 . V_174 = V_22 -> V_50 [ V_55 + 0 ] ;
V_221 . V_229 . V_171 . V_173 = 0 ;
V_222 = F_82 ( V_167 , V_222 , V_223 ,
& V_221 , V_236 ) ;
V_221 . V_35 = V_237 ;
V_221 . V_229 . V_207 . V_238 = 0 ;
V_221 . V_229 . V_207 . V_239 = 0 ;
for ( V_218 = 0 ; V_218 < 10 ; V_218 ++ ) if ( V_22 -> V_50 [ V_55 + 50 + V_218 ] ) {
V_221 . V_229 . V_207 . V_240 = ( V_22 -> V_50 [ V_55 + 50 + V_218 ] & 0x7f ) * 500000 ;
V_222 = F_82 ( V_167 , V_222 , V_223 ,
& V_221 , V_241 ) ;
}
V_221 . V_35 = V_242 ;
V_221 . V_229 . V_6 . V_103 = 0 ;
if ( V_22 -> V_50 [ V_55 + 14 ] & 0x10 )
V_221 . V_229 . V_6 . V_232 = V_243 ;
else
V_221 . V_229 . V_6 . V_232 = V_244 ;
V_222 = F_83 ( V_167 , V_222 , V_223 , & V_221 , NULL ) ;
V_221 . V_35 = V_245 ;
V_221 . V_229 . V_198 . V_198 = V_22 -> V_50 [ V_55 + 4 ] ;
V_221 . V_229 . V_198 . V_200 = V_22 -> V_50 [ V_55 + 2 ] / 10 - 100 ;
V_221 . V_229 . V_198 . V_199 = ( 256 + V_22 -> V_50 [ V_55 + 4 ] * 100 ) / 255 - 100 ;
V_221 . V_229 . V_198 . V_201 = 7 ;
V_222 = F_82 ( V_167 , V_222 , V_223 ,
& V_221 , V_246 ) ;
}
if ( ! V_219 )
F_49 ( V_22 ) ;
V_217 -> V_103 = V_222 - V_169 ;
V_217 -> V_232 = 0 ;
return 0 ;
}
static int F_84 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_6 , char * V_133 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
if ( V_6 -> V_103 > V_135 )
return - V_107 ;
if ( V_6 -> V_103 < 1 )
V_6 -> V_103 = 1 ;
V_22 -> V_134 = V_6 -> V_103 ;
memset ( V_22 -> V_133 , 0 , V_135 + 1 ) ;
memcpy ( V_22 -> V_133 , V_133 , V_6 -> V_103 ) ;
return F_51 ( V_22 , V_22 -> V_133 , V_22 -> V_134 ) ;
}
static int F_85 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_6 , char * V_133 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
memcpy ( V_133 , V_22 -> V_133 , V_22 -> V_134 ) ;
V_6 -> V_232 = 1 ;
V_6 -> V_103 = V_22 -> V_134 ;
return 0 ;
}
static int F_86 ( struct V_145 * V_2 , struct V_166 * V_167 ,
struct V_168 * V_6 , char * V_247 )
{
strcpy ( V_247 , L_16 ) ;
V_6 -> V_232 = 1 ;
V_6 -> V_103 = strlen ( V_247 ) ;
return 0 ;
}
static int F_87 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_250 ;
int V_8 ;
switch ( V_249 -> V_240 ) {
case 1000000 :
V_250 = V_251 ;
break;
case 2000000 :
V_250 = V_252 ;
break;
case 5500000 :
V_250 = V_253 ;
break;
case 11000000 :
default:
V_250 = V_254 ;
break;
}
if ( ! V_249 -> V_238 ) {
V_250 |= V_250 - 1 ;
}
V_8 = F_43 ( V_22 , V_255 , V_250 ) ;
if ( V_8 )
return V_8 ;
return F_50 ( V_22 ) ;
}
static int F_88 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_250 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_256 , & V_250 ) ;
if ( V_8 )
return V_8 ;
switch( V_250 ) {
case 1 :
V_249 -> V_240 = 1000000 ;
break;
case 2 :
V_249 -> V_240 = 2000000 ;
break;
case 5 :
V_249 -> V_240 = 5500000 ;
break;
case 11 :
V_249 -> V_240 = 11000000 ;
break;
default:
V_249 -> V_240 = 0 ;
}
V_249 -> V_238 = 0 ;
V_249 -> V_239 = 0 ;
return 0 ;
}
static int F_89 ( struct V_145 * V_2 , struct V_166 * V_167 ,
struct V_248 * V_257 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
int V_8 ;
short V_116 = V_257 -> V_240 ;
if ( V_257 -> V_239 || ! V_257 -> V_238 )
V_116 = V_212 ;
if ( V_116 > V_212 )
return - V_107 ;
if ( V_116 < 0 )
return - V_107 ;
V_8 = F_43 ( V_22 , V_258 , V_116 ) ;
if ( V_8 )
return V_8 ;
return F_50 ( V_22 ) ;
}
static int F_90 ( struct V_145 * V_2 , struct V_166 * V_167 ,
struct V_248 * V_257 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_259 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_258 , & V_259 ) ;
if ( V_8 )
return V_8 ;
V_257 -> V_240 = V_259 ;
V_257 -> V_239 = ( V_257 -> V_240 == V_212 ) ;
V_257 -> V_238 = 1 ;
return 0 ;
}
static int F_91 ( struct V_145 * V_2 , struct V_166 * V_167 ,
struct V_248 * V_91 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
int V_8 ;
short V_116 = V_91 -> V_240 ;
if ( V_91 -> V_239 || ! V_91 -> V_238 )
V_116 = V_213 ;
if ( V_116 > V_213 )
return - V_107 ;
if ( V_116 < V_210 )
return - V_107 ;
if ( V_116 & 1 )
return - V_107 ;
V_8 = F_43 ( V_22 , V_260 , V_116 ) ;
if ( V_8 )
return V_8 ;
return F_50 ( V_22 ) ;
}
static int F_92 ( struct V_145 * V_2 , struct V_166 * V_167 ,
struct V_248 * V_91 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_261 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_260 , & V_261 ) ;
if ( V_8 )
return V_8 ;
V_91 -> V_240 = V_261 ;
V_91 -> V_239 = ( V_91 -> V_240 == V_213 ) ;
V_91 -> V_238 = 1 ;
return 0 ;
}
static int F_93 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
return 0 ;
}
static int F_94 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
return 0 ;
}
static int F_95 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_262 , char * V_263 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_55 ;
int V_8 , V_98 ;
if ( V_262 -> V_103 > V_264 )
return - V_107 ;
V_55 = ( V_262 -> V_232 & V_265 ) - 1 ;
if ( V_55 == - 1 ) {
V_8 = F_42 ( V_22 , V_266 , & V_55 ) ;
if ( V_8 )
return V_8 ;
} else {
V_8 = F_43 ( V_22 , V_266 , V_55 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_55 < 0 || V_55 >= V_205 )
return - V_107 ;
V_98 = V_267 + V_55 ;
V_8 = F_41 ( V_22 , V_98 , V_263 , V_262 -> V_103 , 1 ) ;
if ( V_8 )
return V_8 ;
V_22 -> V_268 [ V_55 ] = V_262 -> V_103 ;
memcpy ( V_22 -> V_269 [ V_55 ] , V_263 , V_262 -> V_103 ) ;
V_55 = 0 ;
if ( ! ( V_262 -> V_232 & V_244 & V_270 ) ) {
V_55 |= 0x01 ;
V_22 -> V_271 = 1 ;
} else
V_22 -> V_271 = 0 ;
if ( V_262 -> V_232 & V_272 & V_270 ) {
V_55 |= 0x02 ;
V_22 -> V_273 = 1 ;
} else
V_22 -> V_273 = 0 ;
V_8 = F_43 ( V_22 , V_274 , V_55 ) ;
if ( V_8 )
return V_8 ;
if ( V_22 -> V_271 )
V_55 = V_137 ;
else
V_55 = V_136 ;
V_8 = F_43 ( V_22 , V_138 , V_55 ) ;
if ( V_8 )
return V_8 ;
return F_50 ( V_22 ) ;
}
static int F_96 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_168 * V_262 , char * V_263 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_55 ;
int V_8 ;
if ( V_22 -> V_271 )
V_262 -> V_232 = V_243 ;
else
V_262 -> V_232 = V_244 ;
if ( V_22 -> V_273 )
V_262 -> V_232 |= V_272 ;
else
V_262 -> V_232 |= V_275 ;
V_55 = ( V_262 -> V_232 & V_265 ) - 1 ;
if ( V_55 == - 1 ) {
V_8 = F_42 ( V_22 , V_266 , & V_55 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_55 < 0 || V_55 >= V_205 )
return - V_107 ;
V_262 -> V_232 |= V_55 + 1 ;
V_262 -> V_103 = V_22 -> V_268 [ V_55 ] ;
memcpy ( V_263 , V_22 -> V_269 [ V_55 ] , V_262 -> V_103 ) ;
return 0 ;
}
static int F_97 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_276 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_277 , V_278 , V_199 ;
int V_8 ;
V_277 = V_276 -> V_239 ? 0 : 1 ;
if ( V_277 ) {
if ( V_276 -> V_232 & V_279 ) {
V_278 = V_276 -> V_240 ;
V_8 = F_43 ( V_22 ,
V_280 , V_278 ) ;
if ( V_8 )
return V_8 ;
goto V_281;
}
if ( V_276 -> V_232 & V_282 ) {
V_8 = F_42 ( V_22 ,
V_280 , & V_278 ) ;
if ( V_8 )
return V_8 ;
V_199 = V_276 -> V_240 * 4 / V_278 ;
if ( V_199 > 4 )
V_199 = 4 ;
if ( V_199 < 0 )
V_199 = 0 ;
V_8 = F_43 ( V_22 , V_283 ,
V_199 ) ;
if ( V_8 )
return V_8 ;
goto V_281;
}
return - V_107 ;
}
V_281:
return F_43 ( V_22 , V_284 , V_277 ) ;
}
static int F_98 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_276 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_277 , V_199 , V_278 ;
int V_8 ;
V_8 = F_42 ( V_22 , V_284 , & V_277 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_42 ( V_22 , V_283 , & V_199 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_42 ( V_22 , V_280 , & V_278 ) ;
if ( V_8 )
return V_8 ;
V_276 -> V_239 = V_277 ? 0 : 1 ;
if ( V_276 -> V_232 & V_285 ) {
if ( V_276 -> V_232 & V_279 ) {
V_276 -> V_240 = V_278 ;
V_276 -> V_232 = V_279 ;
} else {
V_276 -> V_240 = V_278 * V_199 / 4 ;
V_276 -> V_232 = V_282 ;
}
}
if ( V_276 -> V_232 & V_286 ) {
if ( V_277 && V_199 )
V_276 -> V_232 = V_287 ;
else
V_276 -> V_232 = V_288 ;
}
return 0 ;
}
static int F_99 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
if ( ! V_22 -> V_139 )
return - V_225 ;
return F_43 ( V_22 , V_289 , V_249 -> V_240 ) ;
}
static int F_100 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_290 ;
int V_8 ;
if ( ! V_22 -> V_139 )
return - V_225 ;
V_8 = F_42 ( V_22 , V_289 , & V_290 ) ;
if ( V_8 )
return V_8 ;
V_249 -> V_240 = V_290 ;
V_249 -> V_238 = 1 ;
return 0 ;
}
static int F_101 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_158 * V_291 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
unsigned char V_120 [ 10 ] ;
if ( ! V_22 -> V_139 )
return - V_225 ;
memcpy ( V_120 , V_291 -> V_73 , V_74 ) ;
* ( short * ) ( V_120 + 6 ) = 0 ;
* ( short * ) ( V_120 + 8 ) = 0 ;
return F_41 ( V_22 , V_292 , V_120 , 10 , 1 ) ;
}
static int F_102 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
int V_8 ;
if ( ! V_22 -> V_139 )
return - V_225 ;
V_8 = F_43 ( V_22 , V_293 , V_249 -> V_240 ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_103 ( struct V_145 * V_2 ,
struct V_166 * V_167 , struct V_248 * V_249 , char * V_169 )
{
struct V_21 * V_22 = F_54 ( V_2 ) ;
short V_294 ;
int V_8 ;
if ( ! V_22 -> V_139 )
return - V_225 ;
V_8 = F_42 ( V_22 , V_293 , & V_294 ) ;
if ( V_8 )
return V_8 ;
V_249 -> V_240 = V_294 ;
V_249 -> V_238 = 1 ;
return 0 ;
}
static int F_104 ( struct V_295 * V_296 ,
const struct V_297 * V_298 )
{
struct V_21 * V_22 ;
struct V_145 * V_2 ;
struct V_1 * V_32 ;
int V_8 ;
short V_177 ;
char V_10 [ V_135 + 2 ] ;
V_32 = F_105 ( V_296 ) ;
V_2 = F_106 ( sizeof( * V_22 ) ) ;
if ( ! V_2 )
return - V_14 ;
V_22 = F_54 ( V_2 ) ;
V_22 -> V_2 = V_2 ;
V_22 -> V_139 = V_139 ;
V_22 -> V_32 = V_32 ;
V_22 -> V_299 = 0 ;
F_107 ( & V_22 -> V_53 ) ;
F_108 ( & V_22 -> V_96 ) ;
V_8 = F_1 ( V_32 , V_22 -> V_139 ) ;
if ( V_8 ) {
F_3 ( & V_32 -> V_2 , L_17 , V_8 ) ;
goto V_300;
}
V_22 -> V_123 = 1 ;
V_22 -> V_153 = 1 ;
V_22 -> V_43 = 2 ;
V_22 -> V_122 = F_16 ( 0 , V_121 ) ;
V_22 -> V_150 = F_16 ( 0 , V_121 ) ;
if ( ! V_22 -> V_122 || ! V_22 -> V_150 ) {
V_8 = - V_14 ;
goto V_300;
}
F_109 ( 100 ) ;
V_8 = F_44 ( V_22 ) ;
if ( V_8 )
goto V_300;
V_8 = F_43 ( V_22 , V_301 , 2312 ) ;
if ( V_8 )
goto V_302;
V_8 = F_43 ( V_22 , V_255 ,
V_251 | V_252 | V_253 | V_254 ) ;
if ( V_8 )
goto V_302;
V_2 -> V_303 = & V_304 ;
V_2 -> V_305 = & V_306 ;
V_2 -> V_307 = V_308 ;
strcpy ( V_2 -> V_33 , L_18 ) ;
V_8 = F_38 ( V_22 , V_142 ,
V_2 -> V_143 , V_2 -> V_144 ) ;
if ( V_8 )
goto V_302;
* ( V_42 * ) V_10 = F_15 ( 0 ) ;
V_8 = F_41 ( V_22 , V_140 , V_10 ,
V_135 + 2 , 1 ) ;
if ( V_8 )
goto V_302;
if ( V_22 -> V_139 )
V_177 = V_189 ;
else
V_177 = V_185 ;
V_8 = F_43 ( V_22 , V_186 , V_177 ) ;
if ( V_8 )
goto V_302;
F_110 ( V_2 , & V_32 -> V_2 ) ;
V_8 = F_111 ( V_2 ) ;
if ( V_8 )
goto V_302;
F_112 ( & V_32 -> V_2 , L_19 ,
V_2 -> V_33 ) ;
F_113 ( V_296 , V_22 ) ;
F_48 ( V_22 ) ;
F_49 ( V_22 ) ;
return 0 ;
V_302:
F_13 ( V_22 , V_125 , 0 , 0 , 0 ) ;
V_300:
F_12 ( V_22 -> V_150 ) ;
F_12 ( V_22 -> V_122 ) ;
F_114 ( V_2 ) ;
return V_8 ;
}
static void F_115 ( struct V_295 * V_296 )
{
struct V_21 * V_22 = F_116 ( V_296 ) ;
struct V_309 * V_310 ;
struct V_90 * V_91 ;
if ( ! V_22 )
return;
F_113 ( V_296 , NULL ) ;
F_117 (frag, node2, &zd->fraglist, fnode) {
F_37 ( & V_91 -> V_95 ) ;
F_59 ( V_91 -> V_45 ) ;
F_8 ( V_91 ) ;
}
if ( V_22 -> V_150 ) {
F_47 ( V_22 -> V_150 ) ;
F_12 ( V_22 -> V_150 ) ;
}
if ( V_22 -> V_122 ) {
F_47 ( V_22 -> V_122 ) ;
F_12 ( V_22 -> V_122 ) ;
}
if ( V_22 -> V_2 ) {
F_118 ( V_22 -> V_2 ) ;
F_114 ( V_22 -> V_2 ) ;
}
}
static int F_119 ( struct V_295 * V_296 ,
T_4 V_311 )
{
struct V_21 * V_22 = F_116 ( V_296 ) ;
F_120 ( V_22 -> V_2 ) ;
V_22 -> V_312 = V_22 -> V_129 ;
if ( V_22 -> V_312 )
return F_49 ( V_22 ) ;
else
return 0 ;
}
static int F_121 ( struct V_295 * V_296 )
{
struct V_21 * V_22 = F_116 ( V_296 ) ;
if ( ! V_22 || ! V_22 -> V_2 )
return - V_26 ;
F_122 ( V_22 -> V_2 ) ;
if ( V_22 -> V_312 )
return F_48 ( V_22 ) ;
else
return 0 ;
}
