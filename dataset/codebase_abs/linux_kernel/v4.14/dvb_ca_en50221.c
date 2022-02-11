static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
F_2 ( V_2 -> V_4 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_3 ( V_2 -> V_6 [ V_3 ] . V_7 . V_8 ) ;
F_4 ( V_2 -> V_6 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( V_10 , struct V_1 , V_11 ) ;
F_1 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_11 , F_5 ) ;
}
static char * F_11 ( char * V_12 , int V_13 , char * V_14 , int V_15 )
{
int V_3 ;
if ( V_13 < V_15 )
return NULL ;
for ( V_3 = 0 ; V_3 <= V_13 - V_15 ; V_3 ++ ) {
if ( ! strncmp ( V_12 + V_3 , V_14 , V_15 ) )
return V_12 + V_3 ;
}
return NULL ;
}
static int F_12 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_19 ;
int V_20 ;
int V_21 ;
if ( V_2 -> V_22 & V_23 )
return ( F_13 ( & V_18 -> V_24 ) != 0 ) ;
V_19 = V_2 -> V_25 -> V_26 ( V_2 -> V_25 , V_16 , V_2 -> V_27 ) ;
V_20 = ( V_19 & V_28 ) ? 1 : 0 ;
V_21 = ( V_19 & V_29 ) ? 1 : 0 ;
if ( ! V_21 ) {
int V_30 = ( V_18 -> V_31 != V_32 ) ;
V_21 = ( V_20 != V_30 ) ;
}
if ( V_21 ) {
if ( ! V_20 )
V_18 -> V_33 = V_34 ;
else
V_18 -> V_33 = V_35 ;
F_14 ( & V_18 -> V_24 , 1 ) ;
} else {
if ( ( V_18 -> V_31 == V_36 ) &&
( V_19 & V_37 ) ) {
V_18 -> V_31 = V_38 ;
}
}
return V_21 ;
}
static int F_15 ( struct V_1 * V_2 , int V_16 ,
T_1 V_39 , int V_40 )
{
unsigned long V_41 ;
unsigned long V_42 ;
F_16 ( L_1 , V_43 ) ;
V_42 = V_44 ;
V_41 = V_44 + V_40 ;
while ( 1 ) {
int V_45 ;
V_45 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_45 < 0 )
return - V_48 ;
if ( V_45 & V_39 ) {
F_16 ( L_2 ,
V_43 , V_44 - V_42 ) ;
return 0 ;
}
if ( F_17 ( V_44 , V_41 ) )
break;
F_18 ( 1000 , 1100 ) ;
}
F_16 ( L_3 , V_43 , V_44 - V_42 ) ;
return - V_49 ;
}
static int F_19 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_50 ;
int V_51 ;
T_1 V_52 [ 2 ] ;
F_16 ( L_1 , V_43 ) ;
V_18 -> V_53 = 0 ;
V_18 -> V_54 = 2 ;
V_50 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 ,
V_57 | V_58 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_15 ( V_2 , V_16 , V_59 , V_60 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_20 ( V_2 , V_16 , V_52 , 2 ) ;
if ( V_50 != 2 )
return - V_48 ;
V_50 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 , V_57 ) ;
if ( V_50 )
return V_50 ;
V_51 = ( V_52 [ 0 ] << 8 ) | V_52 [ 1 ] ;
if ( V_51 > V_61 )
V_51 = V_61 ;
V_18 -> V_54 = V_51 ;
V_52 [ 0 ] = V_51 >> 8 ;
V_52 [ 1 ] = V_51 & 0xff ;
F_16 ( L_4 , V_51 ) ;
V_50 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 ,
V_57 | V_62 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_15 ( V_2 , V_16 , V_63 , V_60 / 10 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_21 ( V_2 , V_16 , V_52 , 2 ) ;
if ( V_50 != 2 )
return - V_48 ;
V_50 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 , V_57 ) ;
if ( V_50 )
return V_50 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_16 ,
int * V_64 , int * V_65 ,
int * V_66 , T_1 * V_67 )
{
int V_3 ;
int V_68 ;
int V_69 ;
int V_70 = * V_64 ;
V_68 = V_2 -> V_25 -> V_71 ( V_2 -> V_25 , V_16 , V_70 ) ;
if ( V_68 < 0 )
return V_68 ;
if ( V_68 == 0xff ) {
F_16 ( L_5 , V_68 ) ;
* V_64 += 2 ;
* V_65 = V_68 ;
* V_66 = 0 ;
return 0 ;
}
V_69 = V_2 -> V_25 -> V_71 ( V_2 -> V_25 , V_16 ,
V_70 + 2 ) ;
if ( V_69 < 0 )
return V_69 ;
V_70 += 4 ;
F_16 ( L_6 , V_68 , V_69 ) ;
for ( V_3 = 0 ; V_3 < V_69 ; V_3 ++ ) {
V_67 [ V_3 ] = V_2 -> V_25 -> V_71 ( V_2 -> V_25 , V_16 ,
V_70 + ( V_3 * 2 ) ) ;
F_16 ( L_7 ,
V_3 , V_67 [ V_3 ] & 0xff ,
( ( V_67 [ V_3 ] > 31 ) && ( V_67 [ V_3 ] < 127 ) ) ? V_67 [ V_3 ] : '.' ) ;
}
V_70 += ( V_69 * 2 ) ;
* V_65 = V_68 ;
* V_66 = V_69 ;
* V_64 = V_70 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 ;
int V_64 = 0 ;
int V_66 ;
int V_65 ;
T_1 V_67 [ 257 ] ;
char * V_72 ;
int V_73 ;
int V_74 ;
int V_75 = 0 ;
int V_76 = 0 ;
int V_3 ;
T_2 V_77 = 0 ;
T_2 V_78 = 0 ;
V_74 = F_22 ( V_2 , V_16 , & V_64 , & V_65 ,
& V_66 , V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_65 != 0x1D )
return - V_79 ;
V_74 = F_22 ( V_2 , V_16 , & V_64 , & V_65 ,
& V_66 , V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_65 != 0x1C )
return - V_79 ;
V_74 = F_22 ( V_2 , V_16 , & V_64 , & V_65 ,
& V_66 , V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_65 != 0x15 )
return - V_79 ;
V_74 = F_22 ( V_2 , V_16 , & V_64 , & V_65 ,
& V_66 , V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_65 != 0x20 )
return - V_79 ;
if ( V_66 != 4 )
return - V_79 ;
V_77 = ( V_67 [ 1 ] << 8 ) | V_67 [ 0 ] ;
V_78 = ( V_67 [ 3 ] << 8 ) | V_67 [ 2 ] ;
V_74 = F_22 ( V_2 , V_16 , & V_64 , & V_65 ,
& V_66 , V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_65 != 0x1A )
return - V_79 ;
if ( V_66 < 3 )
return - V_79 ;
V_73 = V_67 [ 0 ] & 3 ;
if ( V_66 < ( 3 + V_73 + 14 ) )
return - V_79 ;
V_18 = & V_2 -> V_6 [ V_16 ] ;
V_18 -> V_80 = 0 ;
for ( V_3 = 0 ; V_3 < V_73 + 1 ; V_3 ++ )
V_18 -> V_80 |= ( V_67 [ 2 + V_3 ] << ( 8 * V_3 ) ) ;
V_72 = F_11 ( ( char * ) V_67 , V_66 , L_8 , 8 ) ;
if ( ! V_72 )
return - V_79 ;
if ( V_66 < ( ( V_72 - ( char * ) V_67 ) + 12 ) )
return - V_79 ;
if ( strncmp ( V_72 + 8 , L_9 , 4 ) ) {
F_24 ( L_10 ,
V_2 -> V_4 -> V_81 -> V_82 , V_72 [ 8 ] , V_72 [ 9 ] ,
V_72 [ 10 ] , V_72 [ 11 ] ) ;
return - V_79 ;
}
while ( ( ! V_76 ) && ( V_64 < 0x1000 ) ) {
V_74 = F_22 ( V_2 , V_16 , & V_64 ,
& V_65 , & V_66 ,
V_67 ) ;
if ( V_74 < 0 )
return V_74 ;
switch ( V_65 ) {
case 0x1B :
if ( V_66 < ( 2 + 11 + 17 ) )
break;
if ( V_75 )
break;
V_18 -> V_83 = V_67 [ 0 ] & 0x3f ;
if ( ! F_11 ( ( char * ) V_67 , V_66 ,
L_11 , 8 ) ||
! F_11 ( ( char * ) V_67 , V_66 ,
L_12 , 13 ) )
break;
V_75 = 1 ;
break;
case 0x14 :
break;
case 0xFF :
V_76 = 1 ;
break;
default:
F_16 ( L_13 ,
V_65 , V_66 ) ;
break;
}
}
if ( ( V_64 > 0x1000 ) || ( ! V_75 ) )
return - V_79 ;
F_16 ( L_14 ,
V_77 , V_78 , V_18 -> V_80 , V_18 -> V_83 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_84 ;
F_16 ( L_1 , V_43 ) ;
V_2 -> V_25 -> V_85 ( V_2 -> V_25 , V_16 , V_18 -> V_80 ,
V_18 -> V_83 ) ;
V_84 = V_2 -> V_25 -> V_71 ( V_2 -> V_25 , V_16 ,
V_18 -> V_80 ) ;
F_16 ( L_15 ,
V_18 -> V_83 , V_84 & 0x3f ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_16 ,
T_1 * V_86 , int V_87 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_88 ;
int V_74 ;
T_1 V_52 [ V_61 ] ;
int V_3 ;
F_16 ( L_1 , V_43 ) ;
if ( ! V_86 ) {
int V_89 ;
if ( ! V_18 -> V_7 . V_8 ) {
V_74 = - V_48 ;
goto exit;
}
V_89 = F_26 ( & V_18 -> V_7 ) ;
if ( V_89 < ( V_18 -> V_54 +
V_90 ) ) {
V_74 = - V_91 ;
goto exit;
}
}
if ( V_2 -> V_25 -> V_92 &&
( V_18 -> V_31 != V_93 ) ) {
if ( ! V_86 )
V_74 = V_2 -> V_25 -> V_92 ( V_2 -> V_25 , V_16 , V_52 ,
sizeof( V_52 ) ) ;
else
V_74 = V_2 -> V_25 -> V_92 ( V_2 -> V_25 , V_16 , V_52 , V_87 ) ;
if ( V_74 < 0 )
return V_74 ;
V_88 = V_74 ;
if ( V_74 == 0 )
goto exit;
} else {
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 ,
V_47 ) ;
if ( V_74 < 0 )
goto exit;
if ( ! ( V_74 & V_59 ) ) {
V_74 = 0 ;
goto exit;
}
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 ,
V_94 ) ;
if ( V_74 < 0 )
goto exit;
V_88 = V_74 << 8 ;
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 ,
V_95 ) ;
if ( V_74 < 0 )
goto exit;
V_88 |= V_74 ;
if ( ! V_86 ) {
if ( V_88 > V_18 -> V_54 ) {
F_24 ( L_16 ,
V_2 -> V_4 -> V_81 -> V_82 , V_88 ,
V_18 -> V_54 ) ;
V_18 -> V_31 = V_93 ;
V_74 = - V_48 ;
goto exit;
}
if ( V_88 < 2 ) {
F_24 ( L_17 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_93 ;
V_74 = - V_48 ;
goto exit;
}
} else {
if ( V_88 > V_87 ) {
F_24 ( L_18 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_74 = - V_48 ;
goto exit;
}
}
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) {
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 ,
V_96 ) ;
if ( V_74 < 0 )
goto exit;
V_52 [ V_3 ] = V_74 ;
}
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 ,
V_47 ) ;
if ( V_74 < 0 )
goto exit;
if ( V_74 & V_97 ) {
V_18 -> V_31 = V_93 ;
V_74 = - V_48 ;
goto exit;
}
}
if ( ! V_86 ) {
if ( ! V_18 -> V_7 . V_8 ) {
V_74 = - V_48 ;
goto exit;
}
F_27 ( & V_18 -> V_7 , V_52 , V_88 ) ;
} else {
memcpy ( V_86 , V_52 , V_88 ) ;
}
F_16 ( L_19 , V_16 ,
V_52 [ 0 ] , ( V_52 [ 1 ] & 0x80 ) == 0 , V_88 ) ;
if ( ( V_52 [ 1 ] & 0x80 ) == 0x00 )
F_28 ( & V_2 -> V_98 ) ;
V_74 = V_88 ;
exit:
return V_74 ;
}
static int F_21 ( struct V_1 * V_2 , int V_16 ,
T_1 * V_52 , int V_99 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_74 ;
int V_3 ;
F_16 ( L_1 , V_43 ) ;
if ( V_99 > V_18 -> V_54 )
return - V_79 ;
if ( V_2 -> V_25 -> V_100 &&
( V_18 -> V_31 != V_93 ) )
return V_2 -> V_25 -> V_100 ( V_2 -> V_25 , V_16 , V_52 , V_99 ) ;
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_74 < 0 )
goto V_101;
if ( V_74 & ( V_59 | V_97 ) ) {
if ( V_74 & V_59 )
F_29 ( V_2 ) ;
V_74 = - V_91 ;
goto V_101;
}
V_74 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 ,
V_57 | V_102 ) ;
if ( V_74 )
goto exit;
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_74 < 0 )
goto exit;
if ( ! ( V_74 & V_63 ) ) {
V_74 = - V_91 ;
goto exit;
}
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_74 < 0 )
goto exit;
if ( V_74 & ( V_59 | V_97 ) ) {
if ( V_74 & V_59 )
F_29 ( V_2 ) ;
V_74 = - V_91 ;
goto exit;
}
V_74 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_94 ,
V_99 >> 8 ) ;
if ( V_74 )
goto exit;
V_74 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_95 ,
V_99 & 0xff ) ;
if ( V_74 )
goto exit;
for ( V_3 = 0 ; V_3 < V_99 ; V_3 ++ ) {
V_74 = V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_96 ,
V_52 [ V_3 ] ) ;
if ( V_74 )
goto exit;
}
V_74 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_74 < 0 )
goto exit;
if ( V_74 & V_103 ) {
V_18 -> V_31 = V_93 ;
V_74 = - V_48 ;
goto exit;
}
V_74 = V_99 ;
F_16 ( L_20 , V_16 ,
V_52 [ 0 ] , ( V_52 [ 1 ] & 0x80 ) == 0 , V_99 ) ;
exit:
V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 , V_56 , V_57 ) ;
V_101:
return V_74 ;
}
static int F_30 ( struct V_1 * V_2 , int V_16 )
{
F_16 ( L_1 , V_43 ) ;
V_2 -> V_25 -> V_104 ( V_2 -> V_25 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_31 = V_32 ;
F_28 ( & V_2 -> V_98 ) ;
F_16 ( L_21 , V_16 ) ;
return 0 ;
}
void F_31 ( struct V_105 * V_106 , int V_16 ,
int V_107 )
{
struct V_1 * V_2 = V_106 -> V_108 ;
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
F_16 ( L_22 , V_16 , V_107 ) ;
switch ( V_107 ) {
case V_34 :
case V_35 :
break;
default:
return;
}
V_18 -> V_33 = V_107 ;
F_32 ( & V_18 -> V_24 ) ;
F_29 ( V_2 ) ;
}
void F_33 ( struct V_105 * V_106 , int V_16 )
{
struct V_1 * V_2 = V_106 -> V_108 ;
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
F_16 ( L_23 , V_16 ) ;
if ( V_18 -> V_31 == V_36 ) {
V_18 -> V_31 = V_38 ;
F_29 ( V_2 ) ;
}
}
void F_34 ( struct V_105 * V_106 , int V_16 )
{
struct V_1 * V_2 = V_106 -> V_108 ;
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_22 ;
F_16 ( L_24 , V_16 ) ;
switch ( V_18 -> V_31 ) {
case V_93 :
V_22 = V_2 -> V_25 -> V_46 ( V_106 , V_16 , V_47 ) ;
if ( V_22 & V_59 ) {
F_16 ( L_25 ) ;
V_18 -> V_53 = 1 ;
}
break;
case V_109 :
if ( V_2 -> V_27 )
F_29 ( V_2 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 )
{
F_16 ( L_1 , V_43 ) ;
V_2 -> V_110 = 1 ;
F_35 () ;
F_36 ( V_2 -> V_111 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_112 ;
int V_113 = 100000000 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
switch ( V_18 -> V_31 ) {
default:
case V_32 :
V_112 = V_60 * 60 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
V_112 = V_60 * 5 ;
break;
case V_114 :
V_112 = V_60 * 60 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
V_112 = V_60 / 10 ;
break;
case V_115 :
case V_36 :
case V_38 :
case V_116 :
case V_93 :
V_112 = V_60 / 10 ;
break;
case V_109 :
V_112 = V_60 * 60 ;
if ( ! ( V_2 -> V_22 & V_23 ) )
V_112 = V_60 / 10 ;
if ( V_2 -> V_27 ) {
if ( ( ! V_18 -> V_53 ) ||
( ! ( V_2 -> V_22 & V_117 ) ) )
V_112 = V_60 / 10 ;
}
break;
}
if ( V_112 < V_113 )
V_113 = V_112 ;
}
V_2 -> V_112 = V_113 ;
}
static int F_38 ( struct V_1 * V_2 , int V_16 )
{
int V_118 = 0 ;
int V_74 ;
if ( ( ! ( V_2 -> V_22 & V_23 ) ) &&
( V_2 -> V_25 -> V_26 ) ) {
V_74 = V_2 -> V_25 -> V_26 ( V_2 -> V_25 , V_16 , 0 ) ;
if ( ! ( V_74 &
V_28 ) ) {
V_2 -> V_6 [ V_16 ] . V_31 = V_32 ;
F_37 ( V_2 ) ;
V_118 = 1 ;
}
}
return V_118 ;
}
static void F_39 ( struct V_1 * V_2 ,
int V_16 )
{
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
int V_22 ;
int V_119 ;
void * V_120 ;
F_40 ( & V_18 -> V_121 ) ;
while ( F_12 ( V_2 , V_16 ) ) {
if ( V_18 -> V_31 != V_32 )
F_30 ( V_2 , V_16 ) ;
if ( V_18 -> V_33 == V_35 )
V_18 -> V_31 = V_115 ;
F_37 ( V_2 ) ;
F_41 ( & V_18 -> V_24 ) ;
}
switch ( V_18 -> V_31 ) {
case V_32 :
case V_114 :
break;
case V_115 :
V_18 -> V_31 = V_36 ;
V_2 -> V_25 -> V_122 ( V_2 -> V_25 , V_16 ) ;
V_18 -> V_41 = V_44 + ( V_123 * V_60 ) ;
break;
case V_36 :
if ( F_17 ( V_44 , V_18 -> V_41 ) ) {
F_24 ( L_26 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
break;
case V_38 :
if ( F_23 ( V_2 , V_16 ) != 0 ) {
if ( F_38 ( V_2 , V_16 ) )
break;
F_24 ( L_27 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
if ( F_25 ( V_2 , V_16 ) != 0 ) {
F_24 ( L_28 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
if ( V_2 -> V_25 -> V_55 ( V_2 -> V_25 , V_16 ,
V_56 ,
V_124 ) != 0 ) {
F_24 ( L_29 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
F_16 ( L_30 ) ;
V_18 -> V_41 = V_44 + ( V_123 * V_60 ) ;
V_18 -> V_31 = V_116 ;
V_2 -> V_110 = 1 ;
break;
case V_116 :
if ( F_17 ( V_44 , V_18 -> V_41 ) ) {
F_24 ( L_31 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
V_22 = V_2 -> V_25 -> V_46 ( V_2 -> V_25 , V_16 , V_47 ) ;
if ( V_22 & V_63 ) {
V_18 -> V_31 = V_93 ;
V_2 -> V_110 = 1 ;
}
break;
case V_93 :
if ( F_19 ( V_2 , V_16 ) != 0 ) {
if ( F_38 ( V_2 , V_16 ) )
break;
F_24 ( L_32 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_115 ;
F_37 ( V_2 ) ;
break;
}
if ( ! V_18 -> V_7 . V_8 ) {
V_120 = F_42 ( V_125 ) ;
if ( ! V_120 ) {
F_24 ( L_33 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_18 -> V_31 = V_114 ;
F_37 ( V_2 ) ;
break;
}
F_43 ( & V_18 -> V_7 , V_120 ,
V_125 ) ;
}
V_2 -> V_25 -> V_126 ( V_2 -> V_25 , V_16 ) ;
V_18 -> V_31 = V_109 ;
F_37 ( V_2 ) ;
F_24 ( L_34 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
break;
case V_109 :
if ( ! V_2 -> V_27 )
break;
V_119 = 0 ;
while ( F_20 ( V_2 , V_16 , NULL , 0 ) > 0 ) {
if ( ! V_2 -> V_27 )
break;
if ( F_12 ( V_2 , V_16 ) ) {
V_2 -> V_110 = 1 ;
break;
}
if ( ++ V_119 >= V_127 ) {
V_2 -> V_110 = 1 ;
break;
}
}
break;
}
F_44 ( & V_18 -> V_121 ) ;
}
static int F_45 ( void * V_8 )
{
struct V_1 * V_2 = V_8 ;
int V_16 ;
F_16 ( L_1 , V_43 ) ;
F_37 ( V_2 ) ;
while ( ! F_46 () ) {
if ( ! V_2 -> V_110 ) {
F_47 ( V_128 ) ;
F_48 ( V_2 -> V_112 ) ;
if ( F_46 () )
return 0 ;
}
V_2 -> V_110 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ )
F_39 ( V_2 , V_16 ) ;
}
return 0 ;
}
static int F_49 ( struct V_129 * V_129 ,
unsigned int V_130 , void * V_131 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
int V_135 = 0 ;
int V_16 ;
F_16 ( L_1 , V_43 ) ;
if ( F_50 ( & V_2 -> V_136 ) )
return - V_137 ;
switch ( V_130 ) {
case V_138 :
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
F_40 ( & V_18 -> V_121 ) ;
if ( V_18 -> V_31 != V_32 ) {
F_30 ( V_2 , V_16 ) ;
if ( V_2 -> V_22 & V_23 )
F_31 ( V_2 -> V_25 ,
V_16 ,
V_35 ) ;
}
F_44 ( & V_18 -> V_121 ) ;
}
V_2 -> V_139 = 0 ;
F_29 ( V_2 ) ;
break;
case V_140 : {
struct V_141 * V_142 = V_131 ;
V_142 -> V_143 = V_2 -> V_5 ;
V_142 -> V_144 = V_145 ;
V_142 -> V_146 = 0 ;
V_142 -> V_147 = 0 ;
break;
}
case V_148 : {
struct V_149 * V_150 = V_131 ;
struct V_17 * V_18 ;
V_16 = V_150 -> V_82 ;
if ( ( V_16 > V_2 -> V_5 ) || ( V_16 < 0 ) ) {
V_135 = - V_79 ;
goto V_151;
}
V_150 -> type = V_145 ;
V_150 -> V_22 = 0 ;
V_18 = & V_2 -> V_6 [ V_16 ] ;
if ( ( V_18 -> V_31 != V_32 ) &&
( V_18 -> V_31 != V_114 ) ) {
V_150 -> V_22 = V_152 ;
}
if ( V_18 -> V_31 == V_109 )
V_150 -> V_22 |= V_153 ;
break;
}
default:
V_135 = - V_79 ;
break;
}
V_151:
F_44 ( & V_2 -> V_136 ) ;
return V_135 ;
}
static long F_51 ( struct V_129 * V_129 ,
unsigned int V_130 , unsigned long V_154 )
{
return F_52 ( V_129 , V_130 , V_154 , F_49 ) ;
}
static T_3 F_53 ( struct V_129 * V_129 ,
const char T_4 * V_52 , T_5 V_155 ,
T_6 * V_156 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
struct V_17 * V_18 ;
T_1 V_16 , V_157 ;
int V_74 ;
T_1 V_158 [ V_61 ] ;
int V_159 = 0 ;
int V_160 ;
unsigned long V_41 ;
int V_161 ;
F_16 ( L_1 , V_43 ) ;
if ( V_155 < 2 )
return - V_79 ;
if ( F_54 ( & V_16 , V_52 , 1 ) )
return - V_162 ;
if ( F_54 ( & V_157 , V_52 + 1 , 1 ) )
return - V_162 ;
V_52 += 2 ;
V_155 -= 2 ;
V_18 = & V_2 -> V_6 [ V_16 ] ;
if ( V_18 -> V_31 != V_109 )
return - V_79 ;
while ( V_159 < V_155 ) {
V_160 = V_18 -> V_54 - 2 ;
if ( V_160 < 0 )
break;
if ( V_160 > V_61 - 2 )
V_160 = V_61 - 2 ;
if ( ( V_155 - V_159 ) < V_160 )
V_160 = V_155 - V_159 ;
V_158 [ 0 ] = V_157 ;
V_158 [ 1 ] = ( ( V_159 + V_160 ) < V_155 ) ? 0x80 : 0x00 ;
V_74 = F_54 ( V_158 + 2 , V_52 + V_159 , V_160 ) ;
if ( V_74 ) {
V_74 = - V_162 ;
goto exit;
}
V_41 = V_44 + V_60 / 2 ;
V_161 = 0 ;
while ( ! F_17 ( V_44 , V_41 ) ) {
if ( V_18 -> V_31 != V_109 ) {
V_74 = - V_48 ;
goto exit;
}
F_40 ( & V_18 -> V_121 ) ;
V_74 = F_21 ( V_2 , V_16 , V_158 ,
V_160 + 2 ) ;
F_44 ( & V_18 -> V_121 ) ;
if ( V_74 == ( V_160 + 2 ) ) {
V_161 = 1 ;
break;
}
if ( V_74 != - V_91 )
goto exit;
F_18 ( 1000 , 1100 ) ;
}
if ( ! V_161 ) {
V_74 = - V_48 ;
goto exit;
}
V_159 += V_160 ;
}
V_74 = V_155 + 2 ;
exit:
return V_74 ;
}
static int F_55 ( struct V_1 * V_2 ,
int * V_163 , int * V_164 )
{
int V_16 ;
int V_5 = 0 ;
int V_165 ;
T_5 V_160 ;
int V_157 = - 1 ;
int V_166 = 0 ;
T_1 V_167 [ 2 ] ;
V_16 = V_2 -> V_139 ;
while ( ( V_5 < V_2 -> V_5 ) && ( ! V_166 ) ) {
struct V_17 * V_18 = & V_2 -> V_6 [ V_16 ] ;
if ( V_18 -> V_31 != V_109 )
goto V_168;
if ( ! V_18 -> V_7 . V_8 )
return 0 ;
V_165 = F_56 ( & V_18 -> V_7 , - 1 , & V_160 ) ;
while ( V_165 != - 1 ) {
F_57 ( & V_18 -> V_7 , V_165 , 0 , V_167 , 2 ) ;
if ( V_157 == - 1 )
V_157 = V_167 [ 0 ] ;
if ( ( V_167 [ 0 ] == V_157 ) &&
( ( V_167 [ 1 ] & 0x80 ) == 0 ) ) {
* V_164 = V_16 ;
V_166 = 1 ;
break;
}
V_165 = F_56 ( & V_18 -> V_7 , V_165 ,
& V_160 ) ;
}
V_168:
V_16 = ( V_16 + 1 ) % V_2 -> V_5 ;
V_5 ++ ;
}
V_2 -> V_139 = V_16 ;
return V_166 ;
}
static T_3 F_58 ( struct V_129 * V_129 , char T_4 * V_52 ,
T_5 V_155 , T_6 * V_156 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
struct V_17 * V_18 ;
int V_74 ;
int V_163 = 0 ;
T_1 V_167 [ 2 ] ;
int V_16 ;
int V_157 = - 1 ;
T_5 V_165 , V_169 ;
int V_170 = 0 ;
T_5 V_160 ;
int V_171 ;
int V_172 = 0 ;
F_16 ( L_1 , V_43 ) ;
if ( V_155 < 2 )
return - V_79 ;
V_74 = F_55 ( V_2 , & V_163 , & V_16 ) ;
if ( V_74 == 0 ) {
if ( V_129 -> V_173 & V_174 )
return - V_175 ;
V_74 = F_59 ( V_2 -> V_98 ,
F_55
( V_2 , & V_163 , & V_16 ) ) ;
}
if ( ( V_74 < 0 ) || ( V_163 < 0 ) ) {
if ( V_163 )
return V_163 ;
return V_74 ;
}
V_18 = & V_2 -> V_6 [ V_16 ] ;
V_165 = F_56 ( & V_18 -> V_7 , - 1 , & V_160 ) ;
V_171 = 2 ;
do {
if ( V_165 == - 1 ) {
F_24 ( L_35 ,
V_2 -> V_4 -> V_81 -> V_82 ) ;
V_74 = - V_48 ;
goto exit;
}
F_57 ( & V_18 -> V_7 , V_165 , 0 , V_167 , 2 ) ;
if ( V_157 == - 1 )
V_157 = V_167 [ 0 ] ;
if ( V_167 [ 0 ] == V_157 ) {
if ( V_171 < V_155 ) {
if ( ( V_171 + V_160 - 2 ) > V_155 )
V_160 = V_155 - V_171 ;
else
V_160 -= 2 ;
V_74 =
F_60 ( & V_18 -> V_7 ,
V_165 , 2 ,
V_52 + V_171 ,
V_160 ) ;
if ( V_74 < 0 )
goto exit;
V_171 += V_160 ;
}
if ( ( V_167 [ 1 ] & 0x80 ) == 0 )
V_170 = 1 ;
V_172 = 1 ;
}
V_169 = F_56 ( & V_18 -> V_7 , V_165 , & V_160 ) ;
if ( V_172 )
F_61 ( & V_18 -> V_7 , V_165 ) ;
V_165 = V_169 ;
V_172 = 0 ;
} while ( ! V_170 );
V_167 [ 0 ] = V_16 ;
V_167 [ 1 ] = V_157 ;
V_74 = F_62 ( V_52 , V_167 , 2 ) ;
if ( V_74 ) {
V_74 = - V_162 ;
goto exit;
}
V_74 = V_171 ;
exit:
return V_74 ;
}
static int F_63 ( struct V_176 * V_176 , struct V_129 * V_129 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
int V_135 ;
int V_3 ;
F_16 ( L_1 , V_43 ) ;
if ( ! F_64 ( V_2 -> V_25 -> V_177 ) )
return - V_48 ;
V_135 = F_65 ( V_176 , V_129 ) ;
if ( V_135 < 0 ) {
F_66 ( V_2 -> V_25 -> V_177 ) ;
return V_135 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
struct V_17 * V_18 = & V_2 -> V_6 [ V_3 ] ;
if ( V_18 -> V_31 == V_109 ) {
if ( ! V_18 -> V_7 . V_8 ) {
F_67 ( & V_18 -> V_7 ) ;
}
}
}
V_2 -> V_27 = 1 ;
F_37 ( V_2 ) ;
F_29 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_176 * V_176 , struct V_129 * V_129 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
int V_135 ;
F_16 ( L_1 , V_43 ) ;
V_2 -> V_27 = 0 ;
F_37 ( V_2 ) ;
V_135 = F_69 ( V_176 , V_129 ) ;
F_66 ( V_2 -> V_25 -> V_177 ) ;
F_9 ( V_2 ) ;
return V_135 ;
}
static unsigned int F_70 ( struct V_129 * V_129 , T_7 * V_178 )
{
struct V_132 * V_4 = V_129 -> V_133 ;
struct V_1 * V_2 = V_4 -> V_134 ;
unsigned int V_179 = 0 ;
int V_16 ;
int V_163 = 0 ;
F_16 ( L_1 , V_43 ) ;
if ( F_55 ( V_2 , & V_163 , & V_16 ) == 1 )
V_179 |= V_180 ;
if ( V_179 )
return V_179 ;
F_71 ( V_129 , & V_2 -> V_98 , V_178 ) ;
if ( F_55 ( V_2 , & V_163 , & V_16 ) == 1 )
V_179 |= V_180 ;
return V_179 ;
}
int F_72 ( struct V_181 * V_181 ,
struct V_105 * V_106 , int V_22 , int V_5 )
{
int V_50 ;
struct V_1 * V_2 = NULL ;
int V_3 ;
F_16 ( L_1 , V_43 ) ;
if ( V_5 < 1 )
return - V_79 ;
V_2 = F_73 ( sizeof( * V_2 ) , V_182 ) ;
if ( ! V_2 ) {
V_50 = - V_183 ;
goto exit;
}
F_74 ( & V_2 -> V_11 ) ;
V_2 -> V_25 = V_106 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = F_75 ( V_5 , sizeof( struct V_17 ) ,
V_182 ) ;
if ( ! V_2 -> V_6 ) {
V_50 = - V_183 ;
goto V_184;
}
F_76 ( & V_2 -> V_98 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_139 = 0 ;
V_106 -> V_108 = V_2 ;
V_50 = F_77 ( V_181 , & V_2 -> V_4 , & V_185 , V_2 ,
V_186 , 0 ) ;
if ( V_50 )
goto V_187;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
struct V_17 * V_18 = & V_2 -> V_6 [ V_3 ] ;
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 -> V_31 = V_32 ;
F_14 ( & V_18 -> V_24 , 0 ) ;
V_18 -> V_33 = V_34 ;
F_78 ( & V_18 -> V_121 ) ;
}
F_78 ( & V_2 -> V_136 ) ;
if ( F_79 ( V_188 ) ) {
V_50 = - V_189 ;
goto V_190;
}
F_35 () ;
V_2 -> V_111 = F_80 ( F_45 , V_2 , L_36 ,
V_2 -> V_4 -> V_81 -> V_82 , V_2 -> V_4 -> V_191 ) ;
if ( F_81 ( V_2 -> V_111 ) ) {
V_50 = F_82 ( V_2 -> V_111 ) ;
F_24 ( L_37 ,
V_50 ) ;
goto V_190;
}
return 0 ;
V_190:
F_83 ( V_2 -> V_4 ) ;
V_187:
F_4 ( V_2 -> V_6 ) ;
V_184:
F_4 ( V_2 ) ;
exit:
V_106 -> V_108 = NULL ;
return V_50 ;
}
void F_84 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_108 ;
int V_3 ;
F_16 ( L_1 , V_43 ) ;
F_85 ( V_2 -> V_111 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_30 ( V_2 , V_3 ) ;
F_86 ( V_2 -> V_4 ) ;
F_9 ( V_2 ) ;
V_106 -> V_108 = NULL ;
}
