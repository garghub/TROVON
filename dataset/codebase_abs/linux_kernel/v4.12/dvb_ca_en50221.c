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
if ( ( V_48 = F_15 ( V_2 , V_16 , V_57 , V_58 / 10 ) ) != 0 )
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
int * V_62 , int * V_63 , int * V_64 , T_1 * V_65 )
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
static int F_20 ( struct V_1 * V_2 , int V_16 , T_1 * V_84 , int V_85 )
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
if ( V_87 < ( V_2 -> V_6 [ V_16 ] . V_52 + V_88 ) ) {
V_72 = - V_89 ;
goto exit;
}
}
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto exit;
if ( ! ( V_72 & V_57 ) ) {
V_72 = 0 ;
goto exit;
}
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_90 ) ) < 0 )
goto exit;
V_86 = V_72 << 8 ;
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_91 ) ) < 0 )
goto exit;
V_86 |= V_72 ;
if ( V_84 == NULL ) {
if ( V_86 > V_2 -> V_6 [ V_16 ] . V_52 ) {
F_24 ( L_16 ,
V_2 -> V_4 -> V_79 -> V_80 , V_86 ,
V_2 -> V_6 [ V_16 ] . V_52 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_92 ;
V_72 = - V_46 ;
goto exit;
}
if ( V_86 < 2 ) {
F_24 ( L_17 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_92 ;
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
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_93 ) ) < 0 )
goto exit;
V_50 [ V_3 ] = V_72 ;
}
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto exit;
if ( V_72 & V_94 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_92 ;
V_72 = - V_46 ;
goto exit;
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
F_28 ( & V_2 -> V_95 ) ;
}
V_72 = V_86 ;
exit:
return V_72 ;
}
static int F_21 ( struct V_1 * V_2 , int V_16 , T_1 * V_50 , int V_96 )
{
int V_72 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( V_96 > V_2 -> V_6 [ V_16 ] . V_52 )
return - V_77 ;
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto V_97;
if ( V_72 & ( V_57 | V_94 ) ) {
if ( V_72 & V_57 )
F_29 ( V_2 ) ;
V_72 = - V_89 ;
goto V_97;
}
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 ,
V_55 | V_98 ) ) != 0 )
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
if ( V_72 & ( V_57 | V_94 ) ) {
if ( V_72 & V_57 )
F_29 ( V_2 ) ;
V_72 = - V_89 ;
goto exit;
}
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_90 , V_96 >> 8 ) ) != 0 )
goto exit;
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_91 ,
V_96 & 0xff ) ) != 0 )
goto exit;
for ( V_3 = 0 ; V_3 < V_96 ; V_3 ++ ) {
if ( ( V_72 = V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_93 , V_50 [ V_3 ] ) ) != 0 )
goto exit;
}
if ( ( V_72 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ) < 0 )
goto exit;
if ( V_72 & V_99 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_92 ;
V_72 = - V_46 ;
goto exit;
}
V_72 = V_96 ;
F_16 ( L_20 , V_16 ,
V_50 [ 0 ] , ( V_50 [ 1 ] & 0x80 ) == 0 , V_96 ) ;
exit:
V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 , V_54 , V_55 ) ;
V_97:
return V_72 ;
}
static int F_30 ( struct V_1 * V_2 , int V_16 )
{
F_16 ( L_1 , V_41 ) ;
V_2 -> V_23 -> V_100 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_30 ;
F_28 ( & V_2 -> V_95 ) ;
F_16 ( L_21 , V_16 ) ;
return 0 ;
}
void F_31 ( struct V_101 * V_102 , int V_16 , int V_103 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
F_16 ( L_22 , V_16 , V_103 ) ;
switch ( V_103 ) {
case V_32 :
case V_33 :
break;
default:
return;
}
V_2 -> V_6 [ V_16 ] . V_31 = V_103 ;
F_32 ( & V_2 -> V_6 [ V_16 ] . V_22 ) ;
F_29 ( V_2 ) ;
}
void F_33 ( struct V_101 * V_102 , int V_16 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
F_16 ( L_23 , V_16 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_29 == V_34 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_36 ;
F_29 ( V_2 ) ;
}
}
void F_34 ( struct V_101 * V_102 , int V_16 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
int V_20 ;
F_16 ( L_24 , V_16 ) ;
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
case V_92 :
V_20 = V_2 -> V_23 -> V_44 ( V_102 , V_16 , V_45 ) ;
if ( V_20 & V_57 ) {
F_16 ( L_25 ) ;
V_2 -> V_6 [ V_16 ] . V_51 = 1 ;
}
break;
case V_105 :
if ( V_2 -> V_25 )
F_29 ( V_2 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 )
{
F_16 ( L_1 , V_41 ) ;
V_2 -> V_106 = 1 ;
F_35 () ;
F_36 ( V_2 -> V_107 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
int V_108 ;
int V_109 = 100000000 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
default:
case V_30 :
V_108 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_108 = V_58 * 5 ;
break;
case V_110 :
V_108 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_108 = V_58 / 10 ;
break;
case V_111 :
case V_34 :
case V_36 :
case V_112 :
case V_92 :
V_108 = V_58 / 10 ;
break;
case V_105 :
V_108 = V_58 * 60 ;
if ( ! ( V_2 -> V_20 & V_21 ) )
V_108 = V_58 / 10 ;
if ( V_2 -> V_25 ) {
if ( ( ! V_2 -> V_6 [ V_16 ] . V_51 ) ||
( ! ( V_2 -> V_20 & V_113 ) ) )
V_108 = V_58 / 10 ;
}
break;
}
if ( V_108 < V_109 )
V_109 = V_108 ;
}
V_2 -> V_108 = V_109 ;
}
static int F_38 ( void * V_8 )
{
struct V_1 * V_2 = V_8 ;
int V_16 ;
int V_20 ;
int V_72 ;
int V_114 ;
void * V_115 ;
F_16 ( L_1 , V_41 ) ;
F_37 ( V_2 ) ;
while ( ! F_39 () ) {
if ( ! V_2 -> V_106 ) {
F_40 ( V_116 ) ;
F_41 ( V_2 -> V_108 ) ;
if ( F_39 () )
return 0 ;
}
V_2 -> V_106 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
F_42 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
while ( F_12 ( V_2 , V_16 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_30 )
F_30 ( V_2 , V_16 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_31 == V_33 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_111 ;
}
F_37 ( V_2 ) ;
F_43 ( & V_2 -> V_6 [ V_16 ] . V_22 ) ;
}
switch ( V_2 -> V_6 [ V_16 ] . V_29 ) {
case V_30 :
case V_110 :
break;
case V_111 :
V_2 -> V_6 [ V_16 ] . V_29 = V_34 ;
V_2 -> V_23 -> V_118 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_39 = V_42 + ( V_119 * V_58 ) ;
break;
case V_34 :
if ( F_17 ( V_42 , V_2 -> V_6 [ V_16 ] . V_39 ) ) {
F_24 ( L_26 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
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
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
if ( F_25 ( V_2 , V_16 ) != 0 ) {
F_24 ( L_28 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
if ( V_2 -> V_23 -> V_53 ( V_2 -> V_23 , V_16 ,
V_54 , V_120 ) != 0 ) {
F_24 ( L_29 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
F_16 ( L_30 ) ;
V_2 -> V_6 [ V_16 ] . V_39 = V_42 + ( V_119 * V_58 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_112 ;
V_2 -> V_106 = 1 ;
break;
case V_112 :
if ( F_17 ( V_42 , V_2 -> V_6 [ V_16 ] . V_39 ) ) {
F_24 ( L_31 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
V_20 = V_2 -> V_23 -> V_44 ( V_2 -> V_23 , V_16 , V_45 ) ;
if ( V_20 & V_61 ) {
V_2 -> V_6 [ V_16 ] . V_29 = V_92 ;
V_2 -> V_106 = 1 ;
}
break;
case V_92 :
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
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
V_115 = F_44 ( V_121 ) ;
if ( V_115 == NULL ) {
F_24 ( L_33 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_110 ;
F_37 ( V_2 ) ;
break;
}
F_45 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_115 , V_121 ) ;
}
V_2 -> V_23 -> V_122 ( V_2 -> V_23 , V_16 ) ;
V_2 -> V_6 [ V_16 ] . V_29 = V_105 ;
F_37 ( V_2 ) ;
F_24 ( L_34 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
break;
case V_105 :
if ( ! V_2 -> V_25 )
break;
V_114 = 0 ;
while ( ( V_72 = F_20 ( V_2 , V_16 , NULL , 0 ) ) > 0 ) {
if ( ! V_2 -> V_25 )
break;
if ( F_12 ( V_2 , V_16 ) ) {
V_2 -> V_106 = 1 ;
break;
}
if ( ++ V_114 >= V_123 ) {
V_2 -> V_106 = 1 ;
break;
}
}
break;
}
F_46 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_124 * V_124 ,
unsigned int V_125 , void * V_126 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
int V_130 = 0 ;
int V_16 ;
F_16 ( L_1 , V_41 ) ;
if ( F_48 ( & V_2 -> V_131 ) )
return - V_132 ;
switch ( V_125 ) {
case V_133 :
for ( V_16 = 0 ; V_16 < V_2 -> V_5 ; V_16 ++ ) {
F_42 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_30 ) {
F_30 ( V_2 , V_16 ) ;
if ( V_2 -> V_20 & V_21 )
F_31 ( V_2 -> V_23 ,
V_16 ,
V_33 ) ;
}
F_46 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
}
V_2 -> V_134 = 0 ;
F_29 ( V_2 ) ;
break;
case V_135 : {
struct V_136 * V_137 = V_126 ;
V_137 -> V_138 = V_2 -> V_5 ;
V_137 -> V_139 = V_140 ;
V_137 -> V_141 = 0 ;
V_137 -> V_142 = 0 ;
break;
}
case V_143 : {
struct V_144 * V_145 = V_126 ;
if ( ( V_145 -> V_80 > V_2 -> V_5 ) || ( V_145 -> V_80 < 0 ) ) {
V_130 = - V_77 ;
goto V_146;
}
V_145 -> type = V_140 ;
V_145 -> V_20 = 0 ;
if ( ( V_2 -> V_6 [ V_145 -> V_80 ] . V_29 != V_30 )
&& ( V_2 -> V_6 [ V_145 -> V_80 ] . V_29 != V_110 ) ) {
V_145 -> V_20 = V_147 ;
}
if ( V_2 -> V_6 [ V_145 -> V_80 ] . V_29 == V_105 ) {
V_145 -> V_20 |= V_148 ;
}
break;
}
default:
V_130 = - V_77 ;
break;
}
V_146:
F_46 ( & V_2 -> V_131 ) ;
return V_130 ;
}
static long F_49 ( struct V_124 * V_124 ,
unsigned int V_125 , unsigned long V_149 )
{
return F_50 ( V_124 , V_125 , V_149 , F_47 ) ;
}
static T_3 F_51 ( struct V_124 * V_124 ,
const char T_4 * V_50 , T_5 V_150 , T_6 * V_151 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
T_1 V_16 , V_152 ;
int V_72 ;
T_1 V_153 [ V_59 ] ;
int V_154 = 0 ;
int V_155 ;
unsigned long V_39 ;
int V_156 ;
F_16 ( L_1 , V_41 ) ;
if ( V_150 < 2 )
return - V_77 ;
if ( F_52 ( & V_16 , V_50 , 1 ) )
return - V_157 ;
if ( F_52 ( & V_152 , V_50 + 1 , 1 ) )
return - V_157 ;
V_50 += 2 ;
V_150 -= 2 ;
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_105 )
return - V_77 ;
while ( V_154 < V_150 ) {
V_155 = V_2 -> V_6 [ V_16 ] . V_52 - 2 ;
if ( V_155 < 0 )
break;
if ( V_155 > V_59 - 2 )
V_155 = V_59 - 2 ;
if ( ( V_150 - V_154 ) < V_155 )
V_155 = V_150 - V_154 ;
V_153 [ 0 ] = V_152 ;
V_153 [ 1 ] = ( ( V_154 + V_155 ) < V_150 ) ? 0x80 : 0x00 ;
V_72 = F_52 ( V_153 + 2 , V_50 + V_154 , V_155 ) ;
if ( V_72 ) {
V_72 = - V_157 ;
goto exit;
}
V_39 = V_42 + V_58 / 2 ;
V_156 = 0 ;
while ( ! F_17 ( V_42 , V_39 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_105 ) {
V_72 = - V_46 ;
goto exit;
}
F_42 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
V_72 = F_21 ( V_2 , V_16 , V_153 , V_155 + 2 ) ;
F_46 ( & V_2 -> V_6 [ V_16 ] . V_117 ) ;
if ( V_72 == ( V_155 + 2 ) ) {
V_156 = 1 ;
break;
}
if ( V_72 != - V_89 )
goto exit;
F_18 ( 1 ) ;
}
if ( ! V_156 ) {
V_72 = - V_46 ;
goto exit;
}
V_154 += V_155 ;
}
V_72 = V_150 + 2 ;
exit:
return V_72 ;
}
static int F_53 ( struct V_1 * V_2 ,
int * V_158 , int * V_159 )
{
int V_16 ;
int V_5 = 0 ;
int V_160 ;
T_5 V_155 ;
int V_152 = - 1 ;
int V_161 = 0 ;
T_1 V_162 [ 2 ] ;
V_16 = V_2 -> V_134 ;
while ( ( V_5 < V_2 -> V_5 ) && ( ! V_161 ) ) {
if ( V_2 -> V_6 [ V_16 ] . V_29 != V_105 )
goto V_163;
if ( V_2 -> V_6 [ V_16 ] . V_7 . V_8 == NULL ) {
return 0 ;
}
V_160 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , - 1 , & V_155 ) ;
while ( V_160 != - 1 ) {
F_55 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 , 0 , V_162 , 2 ) ;
if ( V_152 == - 1 )
V_152 = V_162 [ 0 ] ;
if ( ( V_162 [ 0 ] == V_152 ) && ( ( V_162 [ 1 ] & 0x80 ) == 0 ) ) {
* V_159 = V_16 ;
V_161 = 1 ;
break;
}
V_160 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 , & V_155 ) ;
}
V_163:
V_16 = ( V_16 + 1 ) % V_2 -> V_5 ;
V_5 ++ ;
}
V_2 -> V_134 = V_16 ;
return V_161 ;
}
static T_3 F_56 ( struct V_124 * V_124 , char T_4 * V_50 ,
T_5 V_150 , T_6 * V_151 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
int V_72 ;
int V_158 = 0 ;
T_1 V_162 [ 2 ] ;
int V_16 ;
int V_152 = - 1 ;
T_5 V_160 , V_164 ;
int V_165 = 0 ;
T_5 V_155 ;
int V_166 ;
int V_167 = 0 ;
F_16 ( L_1 , V_41 ) ;
if ( V_150 < 2 )
return - V_77 ;
if ( ( V_72 = F_53 ( V_2 , & V_158 , & V_16 ) ) == 0 ) {
if ( V_124 -> V_168 & V_169 )
return - V_170 ;
V_72 = F_57 ( V_2 -> V_95 ,
F_53
( V_2 , & V_158 , & V_16 ) ) ;
}
if ( ( V_72 < 0 ) || ( V_158 < 0 ) ) {
if ( V_158 )
return V_158 ;
return V_72 ;
}
V_160 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , - 1 , & V_155 ) ;
V_166 = 2 ;
do {
if ( V_160 == - 1 ) {
F_24 ( L_35 ,
V_2 -> V_4 -> V_79 -> V_80 ) ;
V_72 = - V_46 ;
goto exit;
}
F_55 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 , 0 , V_162 , 2 ) ;
if ( V_152 == - 1 )
V_152 = V_162 [ 0 ] ;
if ( V_162 [ 0 ] == V_152 ) {
if ( V_166 < V_150 ) {
if ( ( V_166 + V_155 - 2 ) > V_150 ) {
V_155 = V_150 - V_166 ;
} else {
V_155 -= 2 ;
}
if ( ( V_72 = F_58 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 , 2 ,
V_50 + V_166 , V_155 ) ) < 0 ) {
goto exit;
}
V_166 += V_155 ;
}
if ( ( V_162 [ 1 ] & 0x80 ) == 0 )
V_165 = 1 ;
V_167 = 1 ;
}
V_164 = F_54 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 , & V_155 ) ;
if ( V_167 )
F_59 ( & V_2 -> V_6 [ V_16 ] . V_7 , V_160 ) ;
V_160 = V_164 ;
V_167 = 0 ;
} while ( ! V_165 );
V_162 [ 0 ] = V_16 ;
V_162 [ 1 ] = V_152 ;
V_72 = F_60 ( V_50 , V_162 , 2 ) ;
if ( V_72 ) {
V_72 = - V_157 ;
goto exit;
}
V_72 = V_166 ;
exit:
return V_72 ;
}
static int F_61 ( struct V_171 * V_171 , struct V_124 * V_124 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
int V_130 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( ! F_62 ( V_2 -> V_23 -> V_172 ) )
return - V_46 ;
V_130 = F_63 ( V_171 , V_124 ) ;
if ( V_130 < 0 ) {
F_64 ( V_2 -> V_23 -> V_172 ) ;
return V_130 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
if ( V_2 -> V_6 [ V_3 ] . V_29 == V_105 ) {
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
static int F_66 ( struct V_171 * V_171 , struct V_124 * V_124 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
int V_130 ;
F_16 ( L_1 , V_41 ) ;
V_2 -> V_25 = 0 ;
F_37 ( V_2 ) ;
V_130 = F_67 ( V_171 , V_124 ) ;
F_64 ( V_2 -> V_23 -> V_172 ) ;
F_9 ( V_2 ) ;
return V_130 ;
}
static unsigned int F_68 ( struct V_124 * V_124 , T_7 * V_173 )
{
struct V_127 * V_4 = V_124 -> V_128 ;
struct V_1 * V_2 = V_4 -> V_129 ;
unsigned int V_174 = 0 ;
int V_16 ;
int V_158 = 0 ;
F_16 ( L_1 , V_41 ) ;
if ( F_53 ( V_2 , & V_158 , & V_16 ) == 1 ) {
V_174 |= V_175 ;
}
if ( V_174 )
return V_174 ;
F_69 ( V_124 , & V_2 -> V_95 , V_173 ) ;
if ( F_53 ( V_2 , & V_158 , & V_16 ) == 1 ) {
V_174 |= V_175 ;
}
return V_174 ;
}
int F_70 ( struct V_176 * V_176 ,
struct V_101 * V_102 , int V_20 , int V_5 )
{
int V_48 ;
struct V_1 * V_2 = NULL ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
if ( V_5 < 1 )
return - V_77 ;
if ( ( V_2 = F_71 ( sizeof( struct V_1 ) , V_177 ) ) == NULL ) {
V_48 = - V_178 ;
goto exit;
}
F_72 ( & V_2 -> V_11 ) ;
V_2 -> V_23 = V_102 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_5 = V_5 ;
if ( ( V_2 -> V_6 = F_73 ( V_5 , sizeof( struct V_179 ) , V_177 ) ) == NULL ) {
V_48 = - V_178 ;
goto V_180;
}
F_74 ( & V_2 -> V_95 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_134 = 0 ;
V_102 -> V_104 = V_2 ;
V_48 = F_75 ( V_176 , & V_2 -> V_4 , & V_181 , V_2 , V_182 , 0 ) ;
if ( V_48 )
goto V_183;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
memset ( & V_2 -> V_6 [ V_3 ] , 0 , sizeof( struct V_179 ) ) ;
V_2 -> V_6 [ V_3 ] . V_29 = V_30 ;
F_14 ( & V_2 -> V_6 [ V_3 ] . V_22 , 0 ) ;
V_2 -> V_6 [ V_3 ] . V_31 = V_32 ;
F_76 ( & V_2 -> V_6 [ V_3 ] . V_117 ) ;
}
F_76 ( & V_2 -> V_131 ) ;
if ( F_77 ( V_184 ) ) {
V_48 = - V_185 ;
goto V_186;
}
F_35 () ;
V_2 -> V_107 = F_78 ( F_38 , V_2 , L_36 ,
V_2 -> V_4 -> V_79 -> V_80 , V_2 -> V_4 -> V_187 ) ;
if ( F_79 ( V_2 -> V_107 ) ) {
V_48 = F_80 ( V_2 -> V_107 ) ;
F_24 ( L_37 ,
V_48 ) ;
goto V_186;
}
return 0 ;
V_186:
F_81 ( V_2 -> V_4 ) ;
V_183:
F_4 ( V_2 -> V_6 ) ;
V_180:
F_4 ( V_2 ) ;
exit:
V_102 -> V_104 = NULL ;
return V_48 ;
}
void F_82 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_104 ;
int V_3 ;
F_16 ( L_1 , V_41 ) ;
F_83 ( V_2 -> V_107 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
F_30 ( V_2 , V_3 ) ;
}
F_84 ( V_2 -> V_4 ) ;
F_9 ( V_2 ) ;
V_102 -> V_104 = NULL ;
}
