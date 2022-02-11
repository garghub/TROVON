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
struct V_1 * V_2 = F_6 ( V_10 , struct V_1 , V_11 ) ;
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
int V_17 ;
int V_18 ;
int V_19 ;
if ( V_2 -> V_20 & V_21 ) {
return ( F_13 ( & V_2 -> V_6 [ V_16 ] . V_22 ) != 0 ) ;
}
V_17 = V_2 -> V_23 -> V_24 ( V_2 -> V_23 , V_16 , V_2 -> V_25 ) ;
V_18 = ( V_17 & V_26 ) ? 1 : 0 ;
V_19 = ( V_17 & V_27 ) ? 1 : 0 ;
if ( ! V_19 ) {
int V_28 = ( V_2 -> V_6 [ V_16 ] . V_29 != V_30 ) ;
V_19 = ( V_18 != V_28 ) ;
}
if ( V_19 ) {
if ( ! V_18 ) {
V_2 -> V_6 [ V_16 ] . V_31 = V_32 ;
} else {
V_2 -> V_6 [ V_16 ] . V_31 = V_33 ;
}
F_14 ( & V_2 -> V_6 [ V_16 ] . V_22 , 1 ) ;
} else {
if ( ( V_2 -> V_6 [ V_16 ] . V_29 == V_34 ) &&
( V_17 & V_35 ) ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_36 ;
}
}
return V_19 ;
}
static int F_15 ( struct V_1 * V_2 , int V_16 ,
T_1 V_37 , int V_38 )
{
unsigned long V_39 ;
unsigned long V_40 ;
F_16 ( L_1 , V_41 ) ;
V_40 = V_42 ;
V_39 = V_42 + V_38 ;
while ( 1 ) {
int V_43 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ;
if ( V_43 < 0 )
return - V_46 ;
if ( V_43 & V_37 ) {
F_16 ( L_2 ,
V_41 , V_42 - V_40 ) ;
return 0 ;
}
if ( F_17 ( V_42 , V_39 ) ) {
break;
}
F_18 ( 1 ) ;
}
F_16 ( L_3 , V_41 , V_42 - V_40 ) ;
return - V_47 ;
}
static int F_19 ( struct V_1 * V_2 , int V_16 )
{
int V_48 ;
int V_49 ;
T_1 V_50 [ 2 ] ;
F_16 ( L_1 , V_41 ) ;
V_2 -> V_6 [ V_16 ] . V_51 = 0 ;
V_2 -> V_6 [ V_16 ] . V_52 = 2 ;
if ( ( V_48 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 | V_56 ) ) != 0 )
return V_48 ;
V_48 = F_15 ( V_2 , V_16 , V_57 , V_58 ) ;
if ( V_48 != 0 )
return V_48 ;
if ( ( V_48 = F_20 ( V_2 , V_16 , V_50 , 2 ) ) != 2 )
return - V_46 ;
if ( ( V_48 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 ) ) != 0 )
return V_48 ;
V_49 = ( V_50 [ 0 ] << 8 ) | V_50 [ 1 ] ;
if ( V_49 > V_59 )
V_49 = V_59 ;
V_2 -> V_6 [ V_16 ] . V_52 = V_49 ;
V_50 [ 0 ] = V_49 >> 8 ;
V_50 [ 1 ] = V_49 & 0xff ;
F_16 ( L_4 , V_49 ) ;
if ( ( V_48 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 | V_60 ) ) != 0 )
return V_48 ;
if ( ( V_48 = F_15 ( V_2 , V_16 , V_61 , V_58 / 10 ) ) != 0 )
return V_48 ;
if ( ( V_48 = F_21 ( V_2 , V_16 , V_50 , 2 ) ) != 2 )
return - V_46 ;
if ( ( V_48 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 ) ) != 0 )
return V_48 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , int V_16 ,
int * V_62 , int * V_63 ,
int * V_64 , T_1 * V_65 )
{
int V_3 ;
int V_66 ;
int V_67 ;
int V_68 = * V_62 ;
if ( ( V_66 = V_2 -> V_23 -> V_69 ( V_2 -> V_23 , V_16 , V_68 ) ) < 0 )
return V_66 ;
if ( V_66 == 0xff ) {
F_16 ( L_5 , V_66 ) ;
* V_62 += 2 ;
* V_63 = V_66 ;
* V_64 = 0 ;
return 0 ;
}
if ( ( V_67 = V_2 -> V_23 -> V_69 ( V_2 -> V_23 , V_16 , V_68 + 2 ) ) < 0 )
return V_67 ;
V_68 += 4 ;
F_16 ( L_6 , V_66 , V_67 ) ;
for ( V_3 = 0 ; V_3 < V_67 ; V_3 ++ ) {
V_65 [ V_3 ] = V_2 -> V_23 -> V_69 ( V_2 -> V_23 , V_16 , V_68 + ( V_3 * 2 ) ) ;
F_16 ( L_7 ,
V_3 , V_65 [ V_3 ] & 0xff ,
( ( V_65 [ V_3 ] > 31 ) && ( V_65 [ V_3 ] < 127 ) ) ? V_65 [ V_3 ] : '.' ) ;
}
V_68 += ( V_67 * 2 ) ;
* V_63 = V_66 ;
* V_64 = V_67 ;
* V_62 = V_68 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_16 )
{
int V_62 = 0 ;
int V_64 ;
int V_63 ;
T_1 V_65 [ 257 ] ;
char * V_70 ;
int V_71 ;
int V_72 ;
int V_73 = 0 ;
int V_74 = 0 ;
int V_3 ;
T_2 V_75 = 0 ;
T_2 V_76 = 0 ;
if ( ( V_72 =
F_22 ( V_2 , V_16 , & V_62 , & V_63 , & V_64 , V_65 ) ) < 0 )
return V_72 ;
if ( V_63 != 0x1D )
return - V_77 ;
if ( ( V_72 =
F_22 ( V_2 , V_16 , & V_62 , & V_63 , & V_64 , V_65 ) ) < 0 )
return V_72 ;
if ( V_63 != 0x1C )
return - V_77 ;
if ( ( V_72 =
F_22 ( V_2 , V_16 , & V_62 , & V_63 , & V_64 , V_65 ) ) < 0 )
return V_72 ;
if ( V_63 != 0x15 )
return - V_77 ;
if ( ( V_72 = F_22 ( V_2 , V_16 , & V_62 , & V_63 ,
& V_64 , V_65 ) ) < 0 )
return V_72 ;
if ( V_63 != 0x20 )
return - V_77 ;
if ( V_64 != 4 )
return - V_77 ;
V_75 = ( V_65 [ 1 ] << 8 ) | V_65 [ 0 ] ;
V_76 = ( V_65 [ 3 ] << 8 ) | V_65 [ 2 ] ;
if ( ( V_72 = F_22 ( V_2 , V_16 , & V_62 , & V_63 ,
& V_64 , V_65 ) ) < 0 )
return V_72 ;
if ( V_63 != 0x1A )
return - V_77 ;
if ( V_64 < 3 )
return - V_77 ;
V_71 = V_65 [ 0 ] & 3 ;
if ( V_64 < ( 3 + V_71 + 14 ) )
return - V_77 ;
V_2 -> V_6 [ V_16 ] . V_78 = 0 ;
for ( V_3 = 0 ; V_3 < V_71 + 1 ; V_3 ++ ) {
V_2 -> V_6 [ V_16 ] . V_78 |= ( V_65 [ 2 + V_3 ] << ( 8 * V_3 ) ) ;
}
V_70 = F_11 ( ( char * ) V_65 , V_64 , L_8 , 8 ) ;
if ( V_70 == NULL )
return - V_77 ;
if ( V_64 < ( ( V_70 - ( char * ) V_65 ) + 12 ) )
return - V_77 ;
if ( strncmp ( V_70 + 8 , L_9 , 4 ) ) {
F_24 ( L_10 ,
V_2 -> V_4 -> V_79 -> V_80 , V_70 [ 8 ] , V_70 [ 9 ] ,
V_70 [ 10 ] , V_70 [ 11 ] ) ;
return - V_77 ;
}
while ( ( ! V_74 ) && ( V_62 < 0x1000 ) ) {
if ( ( V_72 = F_22 ( V_2 , V_16 , & V_62 , & V_63 ,
& V_64 , V_65 ) ) < 0 )
return V_72 ;
switch ( V_63 ) {
case 0x1B :
if ( V_64 < ( 2 + 11 + 17 ) )
break;
if ( V_73 )
break;
V_2 -> V_6 [ V_16 ] . V_81 = V_65 [ 0 ] & 0x3f ;
if ( ( F_11 ( ( char * ) V_65 , V_64 , L_11 , 8 ) == NULL ) ||
( F_11 ( ( char * ) V_65 , V_64 , L_12 , 13 ) == NULL ) )
break;
V_73 = 1 ;
break;
case 0x14 :
break;
case 0xFF :
V_74 = 1 ;
break;
default:
F_16 ( L_13 ,
V_63 , V_64 ) ;
break;
}
}
if ( ( V_62 > 0x1000 ) || ( ! V_73 ) )
return - V_77 ;
F_16 ( L_14 ,
V_75 , V_76 , V_2 -> V_6 [ V_16 ] . V_78 ,
V_2 -> V_6 [ V_16 ] . V_81 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , int V_16 )
{
int V_82 ;
F_16 ( L_1 , V_41 ) ;
V_2 -> V_23 -> V_83 ( V_2 -> V_23 , V_16 ,
V_2 -> V_6 [ V_16 ] . V_78 ,
V_2 -> V_6 [ V_16 ] . V_81 ) ;
V_82 = V_2 -> V_23 -> V_69 ( V_2 -> V_23 , V_16 , V_2 -> V_6 [ V_16 ] . V_78 ) ;
F_16 ( L_15 ,
V_2 -> V_6 [ V_16 ] . V_81 , V_82 & 0x3f ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_16 ,
T_1 * V_84 , int V_85 )
{
int V_86 ;
int V_72 ;
T_1 V_50 [ V_59 ] ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( V_84 == NULL ) {
int V_87 ;
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
V_72 = - V_46 ;
goto exit;
}
V_87 = F_26 ( & V_2 -> V_6 [ V_16 ] . V_7 ) ;
if ( V_87 < ( V_2 -> V_6 [ V_16 ] . V_52 +
V_88 ) ) {
V_72 = - V_89 ;
goto exit;
}
}
if ( V_2 -> V_23 -> V_90 &&
( V_2 -> V_6 [ V_16 ] . V_29 != V_91 ) ) {
if ( V_84 == NULL )
V_72 = V_2 -> V_23 -> V_90 ( V_2 -> V_23 , V_16 , V_50 ,
sizeof( V_50 ) ) ;
else
V_72 = V_2 -> V_23 -> V_90 ( V_2 -> V_23 , V_16 , V_50 , V_85 ) ;
if ( V_72 < 0 )
return V_72 ;
V_86 = V_72 ;
if ( V_72 == 0 )
goto exit;
} else {
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 ,
V_45 ) ;
if ( V_72 < 0 )
goto exit;
if ( ! ( V_72 & V_57 ) ) {
V_72 = 0 ;
goto exit;
}
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 ,
V_92 ) ;
if ( V_72 < 0 )
goto exit;
V_86 = V_72 << 8 ;
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 ,
V_93 ) ;
if ( V_72 < 0 )
goto exit;
V_86 |= V_72 ;
if ( V_84 == NULL ) {
if ( V_86 > V_2 -> V_6 [ V_16 ] . V_52 ) {
F_24 ( L_16 ,
V_2 -> V_4 -> V_79 -> V_80 , V_86 ,
V_2 -> V_6 [ V_16 ] . V_52 ) ;
V_2 -> V_6 [ V_16 ] . V_29 =
V_91 ;
V_72 = - V_46 ;
goto exit;
}
if ( V_86 < 2 ) {
F_24 ( L_17 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 =
V_91 ;
V_72 = - V_46 ;
goto exit;
}
} else {
if ( V_86 > V_85 ) {
F_24 ( L_18 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_72 = - V_46 ;
goto exit;
}
}
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 ,
V_94 ) ;
if ( V_72 < 0 )
goto exit;
V_50 [ V_3 ] = V_72 ;
}
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 ,
V_45 ) ;
if ( V_72 < 0 )
goto exit;
if ( V_72 & V_95 ) {
V_2 -> V_6 [ V_16 ] . V_29 =
V_91 ;
V_72 = - V_46 ;
goto exit;
}
}
if ( V_84 == NULL ) {
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
V_72 = - V_46 ;
goto exit;
}
F_27 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_50 , V_86 ) ;
} else {
memcpy ( V_84 , V_50 , V_86 ) ;
}
F_16 ( L_19 , V_16 ,
V_50 [ 0 ] , ( V_50 [ 1 ] & 0x80 ) == 0 , V_86 ) ;
if ( ( V_50 [ 1 ] & 0x80 ) == 0x00 ) {
F_28 ( & V_2 -> V_96 ) ;
}
V_72 = V_86 ;
exit:
return V_72 ;
}
static int F_21 ( struct V_1 * V_2 , int V_16 ,
T_1 * V_50 , int V_97 )
{
int V_72 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( V_97 > V_2 -> V_6 [ V_16 ] . V_52 )
return - V_77 ;
if ( V_2 -> V_23 -> V_98 &&
( V_2 -> V_6 [ V_16 ] . V_29 != V_91 ) )
return V_2 -> V_23 -> V_98 ( V_2 -> V_23 , V_16 , V_50 , V_97 ) ;
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto V_99;
if ( V_72 & ( V_57 | V_95 ) ) {
if ( V_72 & V_57 )
F_29 ( V_2 ) ;
V_72 = - V_89 ;
goto V_99;
}
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 ,
V_55 | V_100 ) ) != 0 )
goto exit;
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto exit;
if ( ! ( V_72 & V_61 ) ) {
V_72 = - V_89 ;
goto exit;
}
V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ;
if ( V_72 < 0 )
goto exit;
if ( V_72 & ( V_57 | V_95 ) ) {
if ( V_72 & V_57 )
F_29 ( V_2 ) ;
V_72 = - V_89 ;
goto exit;
}
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_92 , V_97 >> 8 ) ) != 0 )
goto exit;
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_93 ,
V_97 & 0xff ) ) != 0 )
goto exit;
for ( V_3 = 0 ; V_3 < V_97 ; V_3 ++ ) {
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_94 , V_50 [ V_3 ] ) ) != 0 )
goto exit;
}
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto exit;
if ( V_72 & V_101 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_91 ;
V_72 = - V_46 ;
goto exit;
}
V_72 = V_97 ;
F_16 ( L_20 , V_16 ,
V_50 [ 0 ] , ( V_50 [ 1 ] & 0x80 ) == 0 , V_97 ) ;
exit:
V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 ) ;
V_99:
return V_72 ;
}
static int F_30 ( struct V_1 * V_2 , int V_16 )
{
F_16 ( L_1 , V_41 ) ;
V_2 -> V_23 -> V_102 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_30 ;
F_28 ( & V_2 -> V_96 ) ;
F_16 ( L_21 , V_16 ) ;
return 0 ;
}
void F_31 ( struct V_103 * V_104 , int V_16 , int V_105 )
{
struct V_1 * V_2 = V_104 -> V_106 ;
F_16 ( L_22 , V_16 , V_105 ) ;
switch ( V_105 ) {
case V_32 :
case V_33 :
break;
default:
return;
}
V_2 -> V_6 [ V_16 ] . V_31 = V_105 ;
F_32 ( & V_2 -> V_6 [ V_16 ] . V_22 ) ;
F_29 ( V_2 ) ;
}
void F_33 ( struct V_103 * V_104 , int V_16 )
{
struct V_1 * V_2 = V_104 -> V_106 ;
F_16 ( L_23 , V_16 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_29 == V_34 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_36 ;
F_29 ( V_2 ) ;
}
}
void F_34 ( struct V_103 * V_104 , int V_16 )
{
struct V_1 * V_2 = V_104 -> V_106 ;
int V_20 ;
F_16 ( L_24 , V_16 ) ;
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
case V_91 :
V_20 = V_2 -> V_23 -> V_44 ( V_104 , V_16 , V_45 ) ;
if ( V_20 & V_57 ) {
F_16 ( L_25 ) ;
V_2 -> V_6 [ V_16 ] . V_51 = 1 ;
}
break;
case V_107 :
if ( V_2 -> V_25 )
F_29 ( V_2 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 )
{
F_16 ( L_1 , V_41 ) ;
V_2 -> V_108 = 1 ;
F_35 () ;
F_36 ( V_2 -> V_109 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_110 ;
int V_111 = 100000000 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
default:
case V_30 :
V_110 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_110 = V_58 * 5 ;
break;
case V_112 :
V_110 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_110 = V_58 / 10 ;
break;
case V_113 :
case V_34 :
case V_36 :
case V_114 :
case V_91 :
V_110 = V_58 / 10 ;
break;
case V_107 :
V_110 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_110 = V_58 / 10 ;
if ( V_2 -> V_25 ) {
if ( ( ! V_2 -> V_6 [ V_16 ] . V_51 ) ||
( ! ( V_2 -> V_20 & V_115 ) ) )
V_110 = V_58 / 10 ;
}
break;
}
if ( V_110 < V_111 )
V_111 = V_110 ;
}
V_2 -> V_110 = V_111 ;
}
static int F_38 ( void * V_8 )
{
struct V_1 * V_2 = V_8 ;
int V_16 ;
int V_20 ;
int V_72 ;
int V_116 ;
void * V_117 ;
F_16 ( L_1 , V_41 ) ;
F_37 ( V_2 ) ;
while ( ! F_39 () ) {
if ( ! V_2 -> V_108 ) {
F_40 ( V_118 ) ;
F_41 ( V_2 -> V_110 ) ;
if ( F_39 () )
return 0 ;
}
V_2 -> V_108 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
F_42 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
while ( F_12 ( V_2 , V_16 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_30 )
F_30 ( V_2 , V_16 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_31 == V_33 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_113 ;
}
F_37 ( V_2 ) ;
F_43 ( & V_2 -> V_6 [ V_16 ] . V_22 ) ;
}
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
case V_30 :
case V_112 :
break;
case V_113 :
V_2 -> V_6 [ V_16 ] . V_29 = V_34 ;
V_2 -> V_23 -> V_120 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_39 = V_42 + ( V_121 * V_58 ) ;
break;
case V_34 :
if ( F_17 ( V_42 , V_2 -> V_6 [ V_16 ] . V_39 ) ) {
F_24 ( L_26 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
break;
case V_36 :
if ( F_23 ( V_2 , V_16 ) != 0 ) {
if ( ( ! ( V_2 -> V_20 & V_21 ) ) &&
( V_2 -> V_23 -> V_24 ) ) {
V_72 = V_2 -> V_23 -> V_24 ( V_2 -> V_23 , V_16 , 0 ) ;
if ( ! ( V_72 & V_26 ) ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_30 ;
F_37 ( V_2 ) ;
break;
}
}
F_24 ( L_27 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
if ( F_25 ( V_2 , V_16 ) != 0 ) {
F_24 ( L_28 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
if ( V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 ,
V_54 , V_122 ) != 0 ) {
F_24 ( L_29 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
F_16 ( L_30 ) ;
V_2 -> V_6 [ V_16 ] . V_39 = V_42 + ( V_121 * V_58 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_114 ;
V_2 -> V_108 = 1 ;
break;
case V_114 :
if ( F_17 ( V_42 , V_2 -> V_6 [ V_16 ] . V_39 ) ) {
F_24 ( L_31 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
V_20 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ;
if ( V_20 & V_61 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_91 ;
V_2 -> V_108 = 1 ;
}
break;
case V_91 :
if ( F_19 ( V_2 , V_16 ) != 0 ) {
if ( ( ! ( V_2 -> V_20 & V_21 ) ) &&
( V_2 -> V_23 -> V_24 ) ) {
V_72 = V_2 -> V_23 -> V_24 ( V_2 -> V_23 , V_16 , 0 ) ;
if ( ! ( V_72 & V_26 ) ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_30 ;
F_37 ( V_2 ) ;
break;
}
}
F_24 ( L_32 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 =
V_113 ;
F_37 ( V_2 ) ;
break;
}
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
V_117 = F_44 ( V_123 ) ;
if ( V_117 == NULL ) {
F_24 ( L_33 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
F_37 ( V_2 ) ;
break;
}
F_45 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_117 , V_123 ) ;
}
V_2 -> V_23 -> V_124 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_107 ;
F_37 ( V_2 ) ;
F_24 ( L_34 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
break;
case V_107 :
if ( ! V_2 -> V_25 )
break;
V_116 = 0 ;
while ( ( V_72 = F_20 ( V_2 , V_16 , NULL , 0 ) ) > 0 ) {
if ( ! V_2 -> V_25 )
break;
if ( F_12 ( V_2 , V_16 ) ) {
V_2 -> V_108 = 1 ;
break;
}
if ( ++ V_116 >= V_125 ) {
V_2 -> V_108 = 1 ;
break;
}
}
break;
}
F_46 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_126 * V_126 ,
unsigned int V_127 , void * V_128 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
int V_132 = 0 ;
int V_16 ;
F_16 ( L_1 , V_41 ) ;
if ( F_48 ( & V_2 -> V_133 ) )
return - V_134 ;
switch ( V_127 ) {
case V_135 :
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
F_42 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_30 ) {
F_30 ( V_2 , V_16 ) ;
if ( V_2 -> V_20 & V_21 )
F_31 ( V_2 -> V_23 ,
V_16 ,
V_33 ) ;
}
F_46 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
}
V_2 -> V_136 = 0 ;
F_29 ( V_2 ) ;
break;
case V_137 : {
struct V_138 * V_139 = V_128 ;
V_139 -> V_140 = V_2 -> V_5 ;
V_139 -> V_141 = V_142 ;
V_139 -> V_143 = 0 ;
V_139 -> V_144 = 0 ;
break;
}
case V_145 : {
struct V_146 * V_147 = V_128 ;
if ( ( V_147 -> V_80 > V_2 -> V_5 ) || ( V_147 -> V_80 < 0 ) ) {
V_132 = - V_77 ;
goto V_148;
}
V_147 -> type = V_142 ;
V_147 -> V_20 = 0 ;
if ( ( V_2 -> V_6 [ V_147 -> V_80 ] . V_29 != V_30 )
&& ( V_2 -> V_6 [ V_147 -> V_80 ] . V_29 != V_112 ) ) {
V_147 -> V_20 = V_149 ;
}
if ( V_2 -> V_6 [ V_147 -> V_80 ] . V_29 == V_107 ) {
V_147 -> V_20 |= V_150 ;
}
break;
}
default:
V_132 = - V_77 ;
break;
}
V_148:
F_46 ( & V_2 -> V_133 ) ;
return V_132 ;
}
static long F_49 ( struct V_126 * V_126 ,
unsigned int V_127 , unsigned long V_151 )
{
return F_50 ( V_126 , V_127 , V_151 , F_47 ) ;
}
static T_3 F_51 ( struct V_126 * V_126 ,
const char T_4 * V_50 , T_5 V_152 ,
T_6 * V_153 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
T_1 V_16 , V_154 ;
int V_72 ;
T_1 V_155 [ V_59 ] ;
int V_156 = 0 ;
int V_157 ;
unsigned long V_39 ;
int V_158 ;
F_16 ( L_1 , V_41 ) ;
if ( V_152 < 2 )
return - V_77 ;
if ( F_52 ( & V_16 , V_50 , 1 ) )
return - V_159 ;
if ( F_52 ( & V_154 , V_50 + 1 , 1 ) )
return - V_159 ;
V_50 += 2 ;
V_152 -= 2 ;
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_107 )
return - V_77 ;
while ( V_156 < V_152 ) {
V_157 = V_2 -> V_6 [ V_16 ] . V_52 - 2 ;
if ( V_157 < 0 )
break;
if ( V_157 > V_59 - 2 )
V_157 = V_59 - 2 ;
if ( ( V_152 - V_156 ) < V_157 )
V_157 = V_152 - V_156 ;
V_155 [ 0 ] = V_154 ;
V_155 [ 1 ] = ( ( V_156 + V_157 ) < V_152 ) ? 0x80 : 0x00 ;
V_72 = F_52 ( V_155 + 2 , V_50 + V_156 , V_157 ) ;
if ( V_72 ) {
V_72 = - V_159 ;
goto exit;
}
V_39 = V_42 + V_58 / 2 ;
V_158 = 0 ;
while ( ! F_17 ( V_42 , V_39 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_107 ) {
V_72 = - V_46 ;
goto exit;
}
F_42 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
V_72 = F_21 ( V_2 , V_16 , V_155 , V_157 + 2 ) ;
F_46 ( & V_2 -> V_6 [ V_16 ] . V_119 ) ;
if ( V_72 == ( V_157 + 2 ) ) {
V_158 = 1 ;
break;
}
if ( V_72 != - V_89 )
goto exit;
F_18 ( 1 ) ;
}
if ( ! V_158 ) {
V_72 = - V_46 ;
goto exit;
}
V_156 += V_157 ;
}
V_72 = V_152 + 2 ;
exit:
return V_72 ;
}
static int F_53 ( struct V_1 * V_2 ,
int * V_160 , int * V_161 )
{
int V_16 ;
int V_5 = 0 ;
int V_162 ;
T_5 V_157 ;
int V_154 = - 1 ;
int V_163 = 0 ;
T_1 V_164 [ 2 ] ;
V_16 = V_2 -> V_136 ;
while ( ( V_5 < V_2 -> V_5 ) && ( ! V_163 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_107 )
goto V_165;
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
return 0 ;
}
V_162 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , - 1 , & V_157 ) ;
while ( V_162 != - 1 ) {
F_55 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 , 0 , V_164 , 2 ) ;
if ( V_154 == - 1 )
V_154 = V_164 [ 0 ] ;
if ( ( V_164 [ 0 ] == V_154 ) && ( ( V_164 [ 1 ] & 0x80 ) == 0 ) ) {
* V_161 = V_16 ;
V_163 = 1 ;
break;
}
V_162 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 , & V_157 ) ;
}
V_165:
V_16 = ( V_16 + 1 ) % V_2 -> V_5 ;
V_5 ++ ;
}
V_2 -> V_136 = V_16 ;
return V_163 ;
}
static T_3 F_56 ( struct V_126 * V_126 , char T_4 * V_50 ,
T_5 V_152 , T_6 * V_153 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
int V_72 ;
int V_160 = 0 ;
T_1 V_164 [ 2 ] ;
int V_16 ;
int V_154 = - 1 ;
T_5 V_162 , V_166 ;
int V_167 = 0 ;
T_5 V_157 ;
int V_168 ;
int V_169 = 0 ;
F_16 ( L_1 , V_41 ) ;
if ( V_152 < 2 )
return - V_77 ;
if ( ( V_72 = F_53 ( V_2 , & V_160 , & V_16 ) ) == 0 ) {
if ( V_126 -> V_170 & V_171 )
return - V_172 ;
V_72 = F_57 ( V_2 -> V_96 ,
F_53
( V_2 , & V_160 , & V_16 ) ) ;
}
if ( ( V_72 < 0 ) || ( V_160 < 0 ) ) {
if ( V_160 )
return V_160 ;
return V_72 ;
}
V_162 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , - 1 , & V_157 ) ;
V_168 = 2 ;
do {
if ( V_162 == - 1 ) {
F_24 ( L_35 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_72 = - V_46 ;
goto exit;
}
F_55 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 , 0 , V_164 , 2 ) ;
if ( V_154 == - 1 )
V_154 = V_164 [ 0 ] ;
if ( V_164 [ 0 ] == V_154 ) {
if ( V_168 < V_152 ) {
if ( ( V_168 + V_157 - 2 ) > V_152 ) {
V_157 = V_152 - V_168 ;
} else {
V_157 -= 2 ;
}
if ( ( V_72 = F_58 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 , 2 ,
V_50 + V_168 , V_157 ) ) < 0 ) {
goto exit;
}
V_168 += V_157 ;
}
if ( ( V_164 [ 1 ] & 0x80 ) == 0 )
V_167 = 1 ;
V_169 = 1 ;
}
V_166 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 , & V_157 ) ;
if ( V_169 )
F_59 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_162 ) ;
V_162 = V_166 ;
V_169 = 0 ;
} while ( ! V_167 );
V_164 [ 0 ] = V_16 ;
V_164 [ 1 ] = V_154 ;
V_72 = F_60 ( V_50 , V_164 , 2 ) ;
if ( V_72 ) {
V_72 = - V_159 ;
goto exit;
}
V_72 = V_168 ;
exit:
return V_72 ;
}
static int F_61 ( struct V_173 * V_173 , struct V_126 * V_126 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
int V_132 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( ! F_62 ( V_2 -> V_23 -> V_174 ) )
return - V_46 ;
V_132 = F_63 ( V_173 , V_126 ) ;
if ( V_132 < 0 ) {
F_64 ( V_2 -> V_23 -> V_174 ) ;
return V_132 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
if ( V_2 -> V_6 [ V_3 ] . V_29 == V_107 ) {
if ( V_2 -> V_6 [ V_3 ] . V_7 . V_8 != NULL ) {
F_65 ( & V_2 -> V_6 [ V_3 ] . V_7 ) ;
}
}
}
V_2 -> V_25 = 1 ;
F_37 ( V_2 ) ;
F_29 ( V_2 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_66 ( struct V_173 * V_173 , struct V_126 * V_126 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
int V_132 ;
F_16 ( L_1 , V_41 ) ;
V_2 -> V_25 = 0 ;
F_37 ( V_2 ) ;
V_132 = F_67 ( V_173 , V_126 ) ;
F_64 ( V_2 -> V_23 -> V_174 ) ;
F_9 ( V_2 ) ;
return V_132 ;
}
static unsigned int F_68 ( struct V_126 * V_126 , T_7 * V_175 )
{
struct V_129 * V_4 = V_126 -> V_130 ;
struct V_1 * V_2 = V_4 -> V_131 ;
unsigned int V_176 = 0 ;
int V_16 ;
int V_160 = 0 ;
F_16 ( L_1 , V_41 ) ;
if ( F_53 ( V_2 , & V_160 , & V_16 ) == 1 ) {
V_176 |= V_177 ;
}
if ( V_176 )
return V_176 ;
F_69 ( V_126 , & V_2 -> V_96 , V_175 ) ;
if ( F_53 ( V_2 , & V_160 , & V_16 ) == 1 ) {
V_176 |= V_177 ;
}
return V_176 ;
}
int F_70 ( struct V_178 * V_178 ,
struct V_103 * V_104 , int V_20 , int V_5 )
{
int V_48 ;
struct V_1 * V_2 = NULL ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( V_5 < 1 )
return - V_77 ;
if ( ( V_2 = F_71 ( sizeof( struct V_1 ) , V_179 ) ) == NULL ) {
V_48 = - V_180 ;
goto exit;
}
F_72 ( & V_2 -> V_11 ) ;
V_2 -> V_23 = V_104 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_5 = V_5 ;
if ( ( V_2 -> V_6 = F_73 ( V_5 , sizeof( struct V_181 ) , V_179 ) ) == NULL ) {
V_48 = - V_180 ;
goto V_182;
}
F_74 ( & V_2 -> V_96 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_136 = 0 ;
V_104 -> V_106 = V_2 ;
V_48 = F_75 ( V_178 , & V_2 -> V_4 , & V_183 , V_2 , V_184 , 0 ) ;
if ( V_48 )
goto V_185;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
memset ( & V_2 -> V_6 [ V_3 ] , 0 , sizeof( struct V_181 ) ) ;
V_2 -> V_6 [ V_3 ] . V_29 = V_30 ;
F_14 ( & V_2 -> V_6 [ V_3 ] . V_22 , 0 ) ;
V_2 -> V_6 [ V_3 ] . V_31 = V_32 ;
F_76 ( & V_2 -> V_6 [ V_3 ] . V_119 ) ;
}
F_76 ( & V_2 -> V_133 ) ;
if ( F_77 ( V_186 ) ) {
V_48 = - V_187 ;
goto V_188;
}
F_35 () ;
V_2 -> V_109 = F_78 ( F_38 , V_2 , L_36 ,
V_2 -> V_4 -> V_79 -> V_80 , V_2 -> V_4 -> V_189 ) ;
if ( F_79 ( V_2 -> V_109 ) ) {
V_48 = F_80 ( V_2 -> V_109 ) ;
F_24 ( L_37 ,
V_48 ) ;
goto V_188;
}
return 0 ;
V_188:
F_81 ( V_2 -> V_4 ) ;
V_185:
F_4 ( V_2 -> V_6 ) ;
V_182:
F_4 ( V_2 ) ;
exit:
V_104 -> V_106 = NULL ;
return V_48 ;
}
void F_82 ( struct V_103 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_106 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
F_83 ( V_2 -> V_109 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
F_30 ( V_2 , V_3 ) ;
}
F_84 ( V_2 -> V_4 ) ;
F_9 ( V_2 ) ;
V_104 -> V_106 = NULL ;
}
