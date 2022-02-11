static char * F_1 ( char * V_1 , int V_2 , char * V_3 , int V_4 )
{
int V_5 ;
if ( V_2 < V_4 )
return NULL ;
for ( V_5 = 0 ; V_5 <= V_2 - V_4 ; V_5 ++ ) {
if ( ! strncmp ( V_1 + V_5 , V_3 , V_4 ) )
return V_1 + V_5 ;
}
return NULL ;
}
static int F_2 ( struct V_6 * V_7 , int V_8 )
{
int V_9 ;
int V_10 ;
int V_11 ;
if ( V_7 -> V_12 & V_13 ) {
return ( F_3 ( & V_7 -> V_14 [ V_8 ] . V_15 ) != 0 ) ;
}
V_9 = V_7 -> V_16 -> V_17 ( V_7 -> V_16 , V_8 , V_7 -> V_18 ) ;
V_10 = ( V_9 & V_19 ) ? 1 : 0 ;
V_11 = ( V_9 & V_20 ) ? 1 : 0 ;
if ( ! V_11 ) {
int V_21 = ( V_7 -> V_14 [ V_8 ] . V_22 != V_23 ) ;
V_11 = ( V_10 != V_21 ) ;
}
if ( V_11 ) {
if ( ! V_10 ) {
V_7 -> V_14 [ V_8 ] . V_24 = V_25 ;
} else {
V_7 -> V_14 [ V_8 ] . V_24 = V_26 ;
}
F_4 ( & V_7 -> V_14 [ V_8 ] . V_15 , 1 ) ;
} else {
if ( ( V_7 -> V_14 [ V_8 ] . V_22 == V_27 ) &&
( V_9 & V_28 ) ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_29 ;
}
}
return V_11 ;
}
static int F_5 ( struct V_6 * V_7 , int V_8 ,
T_1 V_30 , int V_31 )
{
unsigned long V_32 ;
unsigned long V_33 ;
F_6 ( L_1 , V_34 ) ;
V_33 = V_35 ;
V_32 = V_35 + V_31 ;
while ( 1 ) {
int V_36 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ;
if ( V_36 < 0 )
return - V_39 ;
if ( V_36 & V_30 ) {
F_6 ( L_2 , V_34 , V_35 - V_33 ) ;
return 0 ;
}
if ( F_7 ( V_35 , V_32 ) ) {
break;
}
F_8 ( 1 ) ;
}
F_6 ( L_3 , V_34 , V_35 - V_33 ) ;
return - V_40 ;
}
static int F_9 ( struct V_6 * V_7 , int V_8 )
{
int V_41 ;
int V_42 ;
T_1 V_43 [ 2 ] ;
F_6 ( L_1 , V_34 ) ;
V_7 -> V_14 [ V_8 ] . V_44 = 0 ;
V_7 -> V_14 [ V_8 ] . V_45 = 2 ;
if ( ( V_41 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 , V_48 | V_49 ) ) != 0 )
return V_41 ;
if ( ( V_41 = F_5 ( V_7 , V_8 , V_50 , V_51 / 10 ) ) != 0 )
return V_41 ;
if ( ( V_41 = F_10 ( V_7 , V_8 , V_43 , 2 ) ) != 2 )
return - V_39 ;
if ( ( V_41 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 , V_48 ) ) != 0 )
return V_41 ;
V_42 = ( V_43 [ 0 ] << 8 ) | V_43 [ 1 ] ;
if ( V_42 > V_52 )
V_42 = V_52 ;
V_7 -> V_14 [ V_8 ] . V_45 = V_42 ;
V_43 [ 0 ] = V_42 >> 8 ;
V_43 [ 1 ] = V_42 & 0xff ;
F_6 ( L_4 , V_42 ) ;
if ( ( V_41 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 , V_48 | V_53 ) ) != 0 )
return V_41 ;
if ( ( V_41 = F_5 ( V_7 , V_8 , V_54 , V_51 / 10 ) ) != 0 )
return V_41 ;
if ( ( V_41 = F_11 ( V_7 , V_8 , V_43 , 2 ) ) != 2 )
return - V_39 ;
if ( ( V_41 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 , V_48 ) ) != 0 )
return V_41 ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , int V_8 ,
int * V_55 , int * V_56 , int * V_57 , T_1 * V_58 )
{
int V_5 ;
int V_59 ;
int V_60 ;
int V_61 = * V_55 ;
if ( ( V_59 = V_7 -> V_16 -> V_62 ( V_7 -> V_16 , V_8 , V_61 ) ) < 0 )
return V_59 ;
if ( V_59 == 0xff ) {
F_6 ( L_5 , V_59 ) ;
* V_55 += 2 ;
* V_56 = V_59 ;
* V_57 = 0 ;
return 0 ;
}
if ( ( V_60 = V_7 -> V_16 -> V_62 ( V_7 -> V_16 , V_8 , V_61 + 2 ) ) < 0 )
return V_60 ;
V_61 += 4 ;
F_6 ( L_6 , V_59 , V_60 ) ;
for ( V_5 = 0 ; V_5 < V_60 ; V_5 ++ ) {
V_58 [ V_5 ] = V_7 -> V_16 -> V_62 ( V_7 -> V_16 , V_8 , V_61 + ( V_5 * 2 ) ) ;
F_6 ( L_7 ,
V_5 , V_58 [ V_5 ] & 0xff ,
( ( V_58 [ V_5 ] > 31 ) && ( V_58 [ V_5 ] < 127 ) ) ? V_58 [ V_5 ] : '.' ) ;
}
V_61 += ( V_60 * 2 ) ;
* V_56 = V_59 ;
* V_57 = V_60 ;
* V_55 = V_61 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , int V_8 )
{
int V_55 = 0 ;
int V_57 ;
int V_56 ;
T_1 V_58 [ 257 ] ;
char * V_63 ;
int V_64 ;
int V_65 ;
int V_66 = 0 ;
int V_67 = 0 ;
int V_5 ;
T_2 V_68 = 0 ;
T_2 V_69 = 0 ;
if ( ( V_65 =
F_12 ( V_7 , V_8 , & V_55 , & V_56 , & V_57 , V_58 ) ) < 0 )
return V_65 ;
if ( V_56 != 0x1D )
return - V_70 ;
if ( ( V_65 =
F_12 ( V_7 , V_8 , & V_55 , & V_56 , & V_57 , V_58 ) ) < 0 )
return V_65 ;
if ( V_56 != 0x1C )
return - V_70 ;
if ( ( V_65 =
F_12 ( V_7 , V_8 , & V_55 , & V_56 , & V_57 , V_58 ) ) < 0 )
return V_65 ;
if ( V_56 != 0x15 )
return - V_70 ;
if ( ( V_65 = F_12 ( V_7 , V_8 , & V_55 , & V_56 ,
& V_57 , V_58 ) ) < 0 )
return V_65 ;
if ( V_56 != 0x20 )
return - V_70 ;
if ( V_57 != 4 )
return - V_70 ;
V_68 = ( V_58 [ 1 ] << 8 ) | V_58 [ 0 ] ;
V_69 = ( V_58 [ 3 ] << 8 ) | V_58 [ 2 ] ;
if ( ( V_65 = F_12 ( V_7 , V_8 , & V_55 , & V_56 ,
& V_57 , V_58 ) ) < 0 )
return V_65 ;
if ( V_56 != 0x1A )
return - V_70 ;
if ( V_57 < 3 )
return - V_70 ;
V_64 = V_58 [ 0 ] & 3 ;
if ( V_57 < ( 3 + V_64 + 14 ) )
return - V_70 ;
V_7 -> V_14 [ V_8 ] . V_71 = 0 ;
for ( V_5 = 0 ; V_5 < V_64 + 1 ; V_5 ++ ) {
V_7 -> V_14 [ V_8 ] . V_71 |= ( V_58 [ 2 + V_5 ] << ( 8 * V_5 ) ) ;
}
V_63 = F_1 ( ( char * ) V_58 , V_57 , L_8 , 8 ) ;
if ( V_63 == NULL )
return - V_70 ;
if ( V_57 < ( ( V_63 - ( char * ) V_58 ) + 12 ) )
return - V_70 ;
if ( strncmp ( V_63 + 8 , L_9 , 4 ) ) {
F_14 ( L_10 ,
V_7 -> V_72 -> V_73 -> V_74 , V_63 [ 8 ] , V_63 [ 9 ] , V_63 [ 10 ] , V_63 [ 11 ] ) ;
return - V_70 ;
}
while ( ( ! V_67 ) && ( V_55 < 0x1000 ) ) {
if ( ( V_65 = F_12 ( V_7 , V_8 , & V_55 , & V_56 ,
& V_57 , V_58 ) ) < 0 )
return V_65 ;
switch ( V_56 ) {
case 0x1B :
if ( V_57 < ( 2 + 11 + 17 ) )
break;
if ( V_66 )
break;
V_7 -> V_14 [ V_8 ] . V_75 = V_58 [ 0 ] & 0x3f ;
if ( ( F_1 ( ( char * ) V_58 , V_57 , L_11 , 8 ) == NULL ) ||
( F_1 ( ( char * ) V_58 , V_57 , L_12 , 13 ) == NULL ) )
break;
V_66 = 1 ;
break;
case 0x14 :
break;
case 0xFF :
V_67 = 1 ;
break;
default:
F_6 ( L_13 , V_56 ,
V_57 ) ;
break;
}
}
if ( ( V_55 > 0x1000 ) || ( ! V_66 ) )
return - V_70 ;
F_6 ( L_14 ,
V_68 , V_69 , V_7 -> V_14 [ V_8 ] . V_71 , V_7 -> V_14 [ V_8 ] . V_75 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , int V_8 )
{
int V_76 ;
F_6 ( L_1 , V_34 ) ;
V_7 -> V_16 -> V_77 ( V_7 -> V_16 , V_8 ,
V_7 -> V_14 [ V_8 ] . V_71 ,
V_7 -> V_14 [ V_8 ] . V_75 ) ;
V_76 = V_7 -> V_16 -> V_62 ( V_7 -> V_16 , V_8 , V_7 -> V_14 [ V_8 ] . V_71 ) ;
F_6 ( L_15 ,
V_7 -> V_14 [ V_8 ] . V_75 , V_76 & 0x3f ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , int V_8 , T_1 * V_78 , int V_79 )
{
int V_80 ;
int V_65 ;
T_1 V_43 [ V_52 ] ;
int V_5 ;
F_6 ( L_1 , V_34 ) ;
if ( V_78 == NULL ) {
int V_81 ;
if ( V_7 -> V_14 [ V_8 ] . V_82 . V_83 == NULL ) {
V_65 = - V_39 ;
goto exit;
}
V_81 = F_16 ( & V_7 -> V_14 [ V_8 ] . V_82 ) ;
if ( V_81 < ( V_7 -> V_14 [ V_8 ] . V_45 + V_84 ) ) {
V_65 = - V_85 ;
goto exit;
}
}
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ) < 0 )
goto exit;
if ( ! ( V_65 & V_50 ) ) {
V_65 = 0 ;
goto exit;
}
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_86 ) ) < 0 )
goto exit;
V_80 = V_65 << 8 ;
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_87 ) ) < 0 )
goto exit;
V_80 |= V_65 ;
if ( V_78 == NULL ) {
if ( V_80 > V_7 -> V_14 [ V_8 ] . V_45 ) {
F_14 ( L_16 ,
V_7 -> V_72 -> V_73 -> V_74 , V_80 , V_7 -> V_14 [ V_8 ] . V_45 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_88 ;
V_65 = - V_39 ;
goto exit;
}
if ( V_80 < 2 ) {
F_14 ( L_17 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_88 ;
V_65 = - V_39 ;
goto exit;
}
} else {
if ( V_80 > V_79 ) {
F_14 ( L_18 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_65 = - V_39 ;
goto exit;
}
}
for ( V_5 = 0 ; V_5 < V_80 ; V_5 ++ ) {
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_89 ) ) < 0 )
goto exit;
V_43 [ V_5 ] = V_65 ;
}
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ) < 0 )
goto exit;
if ( V_65 & V_90 ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_88 ;
V_65 = - V_39 ;
goto exit;
}
if ( V_78 == NULL ) {
if ( V_7 -> V_14 [ V_8 ] . V_82 . V_83 == NULL ) {
V_65 = - V_39 ;
goto exit;
}
F_17 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_43 , V_80 ) ;
} else {
memcpy ( V_78 , V_43 , V_80 ) ;
}
F_6 ( L_19 , V_8 ,
V_43 [ 0 ] , ( V_43 [ 1 ] & 0x80 ) == 0 , V_80 ) ;
if ( ( V_43 [ 1 ] & 0x80 ) == 0x00 ) {
F_18 ( & V_7 -> V_91 ) ;
}
V_65 = V_80 ;
exit:
return V_65 ;
}
static int F_11 ( struct V_6 * V_7 , int V_8 , T_1 * V_43 , int V_92 )
{
int V_65 ;
int V_5 ;
F_6 ( L_1 , V_34 ) ;
if ( V_92 > V_7 -> V_14 [ V_8 ] . V_45 )
return - V_70 ;
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ) < 0 )
goto V_93;
if ( V_65 & ( V_50 | V_90 ) ) {
if ( V_65 & V_50 )
F_19 ( V_7 ) ;
V_65 = - V_85 ;
goto V_93;
}
if ( ( V_65 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 ,
V_48 | V_94 ) ) != 0 )
goto exit;
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ) < 0 )
goto exit;
if ( ! ( V_65 & V_54 ) ) {
V_65 = - V_85 ;
goto exit;
}
if ( ( V_65 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_86 , V_92 >> 8 ) ) != 0 )
goto exit;
if ( ( V_65 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_87 ,
V_92 & 0xff ) ) != 0 )
goto exit;
for ( V_5 = 0 ; V_5 < V_92 ; V_5 ++ ) {
if ( ( V_65 = V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_89 , V_43 [ V_5 ] ) ) != 0 )
goto exit;
}
if ( ( V_65 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ) < 0 )
goto exit;
if ( V_65 & V_95 ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_88 ;
V_65 = - V_39 ;
goto exit;
}
V_65 = V_92 ;
F_6 ( L_20 , V_8 ,
V_43 [ 0 ] , ( V_43 [ 1 ] & 0x80 ) == 0 , V_92 ) ;
exit:
V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 , V_47 , V_48 ) ;
V_93:
return V_65 ;
}
static int F_20 ( struct V_6 * V_7 , int V_8 )
{
F_6 ( L_1 , V_34 ) ;
V_7 -> V_16 -> V_96 ( V_7 -> V_16 , V_8 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_23 ;
F_18 ( & V_7 -> V_91 ) ;
F_6 ( L_21 , V_8 ) ;
return 0 ;
}
void F_21 ( struct V_97 * V_98 , int V_8 , int V_99 )
{
struct V_6 * V_7 = V_98 -> V_100 ;
F_6 ( L_22 , V_8 , V_99 ) ;
switch ( V_99 ) {
case V_25 :
case V_26 :
break;
default:
return;
}
V_7 -> V_14 [ V_8 ] . V_24 = V_99 ;
F_22 ( & V_7 -> V_14 [ V_8 ] . V_15 ) ;
F_19 ( V_7 ) ;
}
void F_23 ( struct V_97 * V_98 , int V_8 )
{
struct V_6 * V_7 = V_98 -> V_100 ;
F_6 ( L_23 , V_8 ) ;
if ( V_7 -> V_14 [ V_8 ] . V_22 == V_27 ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_29 ;
F_19 ( V_7 ) ;
}
}
void F_24 ( struct V_97 * V_98 , int V_8 )
{
struct V_6 * V_7 = V_98 -> V_100 ;
int V_12 ;
F_6 ( L_24 , V_8 ) ;
switch ( V_7 -> V_14 [ V_8 ] . V_22 ) {
case V_88 :
V_12 = V_7 -> V_16 -> V_37 ( V_98 , V_8 , V_38 ) ;
if ( V_12 & V_50 ) {
F_6 ( L_25 ) ;
V_7 -> V_14 [ V_8 ] . V_44 = 1 ;
}
break;
case V_101 :
if ( V_7 -> V_18 )
F_19 ( V_7 ) ;
break;
}
}
static void F_19 ( struct V_6 * V_7 )
{
F_6 ( L_1 , V_34 ) ;
V_7 -> V_102 = 1 ;
F_25 () ;
F_26 ( V_7 -> V_103 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
int V_104 ;
int V_105 = 100000000 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_106 ; V_8 ++ ) {
switch ( V_7 -> V_14 [ V_8 ] . V_22 ) {
default:
case V_23 :
V_104 = V_51 * 60 ;
if ( ! ( V_7 -> V_12 & V_13 ) )
V_104 = V_51 * 5 ;
break;
case V_107 :
V_104 = V_51 * 60 ;
if ( ! ( V_7 -> V_12 & V_13 ) )
V_104 = V_51 / 10 ;
break;
case V_108 :
case V_27 :
case V_29 :
case V_109 :
case V_88 :
V_104 = V_51 / 10 ;
break;
case V_101 :
V_104 = V_51 * 60 ;
if ( ! ( V_7 -> V_12 & V_13 ) )
V_104 = V_51 / 10 ;
if ( V_7 -> V_18 ) {
if ( ( ! V_7 -> V_14 [ V_8 ] . V_44 ) ||
( ! ( V_7 -> V_12 & V_110 ) ) )
V_104 = V_51 / 10 ;
}
break;
}
if ( V_104 < V_105 )
V_105 = V_104 ;
}
V_7 -> V_104 = V_105 ;
}
static int F_28 ( void * V_83 )
{
struct V_6 * V_7 = V_83 ;
int V_8 ;
int V_12 ;
int V_65 ;
int V_111 ;
void * V_112 ;
F_6 ( L_1 , V_34 ) ;
F_27 ( V_7 ) ;
while ( ! F_29 () ) {
if ( ! V_7 -> V_102 ) {
F_30 ( V_113 ) ;
F_31 ( V_7 -> V_104 ) ;
if ( F_29 () )
return 0 ;
}
V_7 -> V_102 = 0 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_106 ; V_8 ++ ) {
F_32 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
while ( F_2 ( V_7 , V_8 ) ) {
if ( V_7 -> V_14 [ V_8 ] . V_22 != V_23 )
F_20 ( V_7 , V_8 ) ;
if ( V_7 -> V_14 [ V_8 ] . V_24 == V_26 ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_108 ;
}
F_27 ( V_7 ) ;
F_33 ( & V_7 -> V_14 [ V_8 ] . V_15 ) ;
}
switch ( V_7 -> V_14 [ V_8 ] . V_22 ) {
case V_23 :
case V_107 :
break;
case V_108 :
V_7 -> V_14 [ V_8 ] . V_22 = V_27 ;
V_7 -> V_16 -> V_115 ( V_7 -> V_16 , V_8 ) ;
V_7 -> V_14 [ V_8 ] . V_32 = V_35 + ( V_116 * V_51 ) ;
break;
case V_27 :
if ( F_7 ( V_35 , V_7 -> V_14 [ V_8 ] . V_32 ) ) {
F_14 ( L_26 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
break;
case V_29 :
if ( F_13 ( V_7 , V_8 ) != 0 ) {
if ( ( ! ( V_7 -> V_12 & V_13 ) ) &&
( V_7 -> V_16 -> V_17 ) ) {
V_65 = V_7 -> V_16 -> V_17 ( V_7 -> V_16 , V_8 , 0 ) ;
if ( ! ( V_65 & V_19 ) ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_23 ;
F_27 ( V_7 ) ;
break;
}
}
F_14 ( L_27 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
if ( F_15 ( V_7 , V_8 ) != 0 ) {
F_14 ( L_28 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
if ( V_7 -> V_16 -> V_46 ( V_7 -> V_16 , V_8 ,
V_47 , V_117 ) != 0 ) {
F_14 ( L_29 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
F_6 ( L_30 ) ;
V_7 -> V_14 [ V_8 ] . V_32 = V_35 + ( V_116 * V_51 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_109 ;
V_7 -> V_102 = 1 ;
break;
case V_109 :
if ( F_7 ( V_35 , V_7 -> V_14 [ V_8 ] . V_32 ) ) {
F_14 ( L_31 ,
V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
V_12 = V_7 -> V_16 -> V_37 ( V_7 -> V_16 , V_8 , V_38 ) ;
if ( V_12 & V_54 ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_88 ;
V_7 -> V_102 = 1 ;
}
break;
case V_88 :
if ( F_9 ( V_7 , V_8 ) != 0 ) {
if ( ( ! ( V_7 -> V_12 & V_13 ) ) &&
( V_7 -> V_16 -> V_17 ) ) {
V_65 = V_7 -> V_16 -> V_17 ( V_7 -> V_16 , V_8 , 0 ) ;
if ( ! ( V_65 & V_19 ) ) {
V_7 -> V_14 [ V_8 ] . V_22 = V_23 ;
F_27 ( V_7 ) ;
break;
}
}
F_14 ( L_32 , V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
if ( V_7 -> V_14 [ V_8 ] . V_82 . V_83 == NULL ) {
V_112 = F_34 ( V_118 ) ;
if ( V_112 == NULL ) {
F_14 ( L_33 , V_7 -> V_72 -> V_73 -> V_74 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_107 ;
F_27 ( V_7 ) ;
break;
}
F_35 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_112 , V_118 ) ;
}
V_7 -> V_16 -> V_119 ( V_7 -> V_16 , V_8 ) ;
V_7 -> V_14 [ V_8 ] . V_22 = V_101 ;
F_27 ( V_7 ) ;
F_14 ( L_34 , V_7 -> V_72 -> V_73 -> V_74 ) ;
break;
case V_101 :
if ( ! V_7 -> V_18 )
break;
V_111 = 0 ;
while ( ( V_65 = F_10 ( V_7 , V_8 , NULL , 0 ) ) > 0 ) {
if ( ! V_7 -> V_18 )
break;
if ( F_2 ( V_7 , V_8 ) ) {
V_7 -> V_102 = 1 ;
break;
}
if ( ++ V_111 >= V_120 ) {
V_7 -> V_102 = 1 ;
break;
}
}
break;
}
F_36 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
}
}
return 0 ;
}
static int F_37 ( struct V_121 * V_121 ,
unsigned int V_122 , void * V_123 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
int V_127 = 0 ;
int V_8 ;
F_6 ( L_1 , V_34 ) ;
if ( F_38 ( & V_7 -> V_128 ) )
return - V_129 ;
switch ( V_122 ) {
case V_130 :
for ( V_8 = 0 ; V_8 < V_7 -> V_106 ; V_8 ++ ) {
F_32 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
if ( V_7 -> V_14 [ V_8 ] . V_22 != V_23 ) {
F_20 ( V_7 , V_8 ) ;
if ( V_7 -> V_12 & V_13 )
F_21 ( V_7 -> V_16 ,
V_8 ,
V_26 ) ;
}
F_36 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
}
V_7 -> V_131 = 0 ;
F_19 ( V_7 ) ;
break;
case V_132 : {
struct V_133 * V_134 = V_123 ;
V_134 -> V_135 = V_7 -> V_106 ;
V_134 -> V_136 = V_137 ;
V_134 -> V_138 = 0 ;
V_134 -> V_139 = 0 ;
break;
}
case V_140 : {
struct V_141 * V_142 = V_123 ;
if ( ( V_142 -> V_74 > V_7 -> V_106 ) || ( V_142 -> V_74 < 0 ) ) {
V_127 = - V_70 ;
goto V_143;
}
V_142 -> type = V_137 ;
V_142 -> V_12 = 0 ;
if ( ( V_7 -> V_14 [ V_142 -> V_74 ] . V_22 != V_23 )
&& ( V_7 -> V_14 [ V_142 -> V_74 ] . V_22 != V_107 ) ) {
V_142 -> V_12 = V_144 ;
}
if ( V_7 -> V_14 [ V_142 -> V_74 ] . V_22 == V_101 ) {
V_142 -> V_12 |= V_145 ;
}
break;
}
default:
V_127 = - V_70 ;
break;
}
V_143:
F_36 ( & V_7 -> V_128 ) ;
return V_127 ;
}
static long F_39 ( struct V_121 * V_121 ,
unsigned int V_122 , unsigned long V_146 )
{
return F_40 ( V_121 , V_122 , V_146 , F_37 ) ;
}
static T_3 F_41 ( struct V_121 * V_121 ,
const char T_4 * V_43 , T_5 V_147 , T_6 * V_148 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
T_1 V_8 , V_149 ;
int V_65 ;
T_1 V_150 [ V_52 ] ;
int V_151 = 0 ;
int V_152 ;
unsigned long V_32 ;
int V_153 ;
F_6 ( L_1 , V_34 ) ;
if ( V_147 < 2 )
return - V_70 ;
if ( F_42 ( & V_8 , V_43 , 1 ) )
return - V_154 ;
if ( F_42 ( & V_149 , V_43 + 1 , 1 ) )
return - V_154 ;
V_43 += 2 ;
V_147 -= 2 ;
if ( V_7 -> V_14 [ V_8 ] . V_22 != V_101 )
return - V_70 ;
while ( V_151 < V_147 ) {
V_152 = V_7 -> V_14 [ V_8 ] . V_45 - 2 ;
if ( V_152 < 0 )
break;
if ( V_152 > V_52 - 2 )
V_152 = V_52 - 2 ;
if ( ( V_147 - V_151 ) < V_152 )
V_152 = V_147 - V_151 ;
V_150 [ 0 ] = V_149 ;
V_150 [ 1 ] = ( ( V_151 + V_152 ) < V_147 ) ? 0x80 : 0x00 ;
V_65 = F_42 ( V_150 + 2 , V_43 + V_151 , V_152 ) ;
if ( V_65 ) {
V_65 = - V_154 ;
goto exit;
}
V_32 = V_35 + V_51 / 2 ;
V_153 = 0 ;
while ( ! F_7 ( V_35 , V_32 ) ) {
if ( V_7 -> V_14 [ V_8 ] . V_22 != V_101 ) {
V_65 = - V_39 ;
goto exit;
}
F_32 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
V_65 = F_11 ( V_7 , V_8 , V_150 , V_152 + 2 ) ;
F_36 ( & V_7 -> V_14 [ V_8 ] . V_114 ) ;
if ( V_65 == ( V_152 + 2 ) ) {
V_153 = 1 ;
break;
}
if ( V_65 != - V_85 )
goto exit;
F_8 ( 1 ) ;
}
if ( ! V_153 ) {
V_65 = - V_39 ;
goto exit;
}
V_151 += V_152 ;
}
V_65 = V_147 + 2 ;
exit:
return V_65 ;
}
static int F_43 ( struct V_6 * V_7 ,
int * V_155 , int * V_156 )
{
int V_8 ;
int V_106 = 0 ;
int V_157 ;
T_5 V_152 ;
int V_149 = - 1 ;
int V_158 = 0 ;
T_1 V_159 [ 2 ] ;
V_8 = V_7 -> V_131 ;
while ( ( V_106 < V_7 -> V_106 ) && ( ! V_158 ) ) {
if ( V_7 -> V_14 [ V_8 ] . V_22 != V_101 )
goto V_160;
if ( V_7 -> V_14 [ V_8 ] . V_82 . V_83 == NULL ) {
return 0 ;
}
V_157 = F_44 ( & V_7 -> V_14 [ V_8 ] . V_82 , - 1 , & V_152 ) ;
while ( V_157 != - 1 ) {
F_45 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 , 0 , V_159 , 2 ) ;
if ( V_149 == - 1 )
V_149 = V_159 [ 0 ] ;
if ( ( V_159 [ 0 ] == V_149 ) && ( ( V_159 [ 1 ] & 0x80 ) == 0 ) ) {
* V_156 = V_8 ;
V_158 = 1 ;
break;
}
V_157 = F_44 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 , & V_152 ) ;
}
V_160:
V_8 = ( V_8 + 1 ) % V_7 -> V_106 ;
V_106 ++ ;
}
V_7 -> V_131 = V_8 ;
return V_158 ;
}
static T_3 F_46 ( struct V_121 * V_121 , char T_4 * V_43 ,
T_5 V_147 , T_6 * V_148 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
int V_65 ;
int V_155 = 0 ;
T_1 V_159 [ 2 ] ;
int V_8 ;
int V_149 = - 1 ;
T_5 V_157 , V_161 ;
int V_162 = 0 ;
T_5 V_152 ;
int V_163 ;
int V_164 = 0 ;
F_6 ( L_1 , V_34 ) ;
if ( V_147 < 2 )
return - V_70 ;
if ( ( V_65 = F_43 ( V_7 , & V_155 , & V_8 ) ) == 0 ) {
if ( V_121 -> V_165 & V_166 )
return - V_167 ;
V_65 = F_47 ( V_7 -> V_91 ,
F_43
( V_7 , & V_155 , & V_8 ) ) ;
}
if ( ( V_65 < 0 ) || ( V_155 < 0 ) ) {
if ( V_155 )
return V_155 ;
return V_65 ;
}
V_157 = F_44 ( & V_7 -> V_14 [ V_8 ] . V_82 , - 1 , & V_152 ) ;
V_163 = 2 ;
do {
if ( V_157 == - 1 ) {
F_14 ( L_35 , V_7 -> V_72 -> V_73 -> V_74 ) ;
V_65 = - V_39 ;
goto exit;
}
F_45 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 , 0 , V_159 , 2 ) ;
if ( V_149 == - 1 )
V_149 = V_159 [ 0 ] ;
if ( V_159 [ 0 ] == V_149 ) {
if ( V_163 < V_147 ) {
if ( ( V_163 + V_152 - 2 ) > V_147 ) {
V_152 = V_147 - V_163 ;
} else {
V_152 -= 2 ;
}
if ( ( V_65 = F_48 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 , 2 ,
V_43 + V_163 , V_152 ) ) < 0 ) {
goto exit;
}
V_163 += V_152 ;
}
if ( ( V_159 [ 1 ] & 0x80 ) == 0 )
V_162 = 1 ;
V_164 = 1 ;
}
V_161 = F_44 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 , & V_152 ) ;
if ( V_164 )
F_49 ( & V_7 -> V_14 [ V_8 ] . V_82 , V_157 ) ;
V_157 = V_161 ;
V_164 = 0 ;
} while ( ! V_162 );
V_159 [ 0 ] = V_8 ;
V_159 [ 1 ] = V_149 ;
V_65 = F_50 ( V_43 , V_159 , 2 ) ;
if ( V_65 ) {
V_65 = - V_154 ;
goto exit;
}
V_65 = V_163 ;
exit:
return V_65 ;
}
static int F_51 ( struct V_168 * V_168 , struct V_121 * V_121 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
int V_127 ;
int V_5 ;
F_6 ( L_1 , V_34 ) ;
if ( ! F_52 ( V_7 -> V_16 -> V_169 ) )
return - V_39 ;
V_127 = F_53 ( V_168 , V_121 ) ;
if ( V_127 < 0 ) {
F_54 ( V_7 -> V_16 -> V_169 ) ;
return V_127 ;
}
for ( V_5 = 0 ; V_5 < V_7 -> V_106 ; V_5 ++ ) {
if ( V_7 -> V_14 [ V_5 ] . V_22 == V_101 ) {
if ( V_7 -> V_14 [ V_5 ] . V_82 . V_83 != NULL ) {
F_55 ( & V_7 -> V_14 [ V_5 ] . V_82 ) ;
}
}
}
V_7 -> V_18 = 1 ;
F_27 ( V_7 ) ;
F_19 ( V_7 ) ;
return 0 ;
}
static int F_56 ( struct V_168 * V_168 , struct V_121 * V_121 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
int V_127 ;
F_6 ( L_1 , V_34 ) ;
V_7 -> V_18 = 0 ;
F_27 ( V_7 ) ;
V_127 = F_57 ( V_168 , V_121 ) ;
F_54 ( V_7 -> V_16 -> V_169 ) ;
return V_127 ;
}
static unsigned int F_58 ( struct V_121 * V_121 , T_7 * V_170 )
{
struct V_124 * V_72 = V_121 -> V_125 ;
struct V_6 * V_7 = V_72 -> V_126 ;
unsigned int V_171 = 0 ;
int V_8 ;
int V_155 = 0 ;
F_6 ( L_1 , V_34 ) ;
if ( F_43 ( V_7 , & V_155 , & V_8 ) == 1 ) {
V_171 |= V_172 ;
}
if ( V_171 )
return V_171 ;
F_59 ( V_121 , & V_7 -> V_91 , V_170 ) ;
if ( F_43 ( V_7 , & V_155 , & V_8 ) == 1 ) {
V_171 |= V_172 ;
}
return V_171 ;
}
int F_60 ( struct V_173 * V_173 ,
struct V_97 * V_98 , int V_12 , int V_106 )
{
int V_41 ;
struct V_6 * V_7 = NULL ;
int V_5 ;
F_6 ( L_1 , V_34 ) ;
if ( V_106 < 1 )
return - V_70 ;
if ( ( V_7 = F_61 ( sizeof( struct V_6 ) , V_174 ) ) == NULL ) {
V_41 = - V_175 ;
goto exit;
}
V_7 -> V_16 = V_98 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_106 = V_106 ;
if ( ( V_7 -> V_14 = F_62 ( V_106 , sizeof( struct V_176 ) , V_174 ) ) == NULL ) {
V_41 = - V_175 ;
goto V_177;
}
F_63 ( & V_7 -> V_91 ) ;
V_7 -> V_18 = 0 ;
V_7 -> V_102 = 0 ;
V_7 -> V_131 = 0 ;
V_98 -> V_100 = V_7 ;
V_41 = F_64 ( V_173 , & V_7 -> V_72 , & V_178 , V_7 , V_179 , 0 ) ;
if ( V_41 )
goto V_180;
for ( V_5 = 0 ; V_5 < V_106 ; V_5 ++ ) {
memset ( & V_7 -> V_14 [ V_5 ] , 0 , sizeof( struct V_176 ) ) ;
V_7 -> V_14 [ V_5 ] . V_22 = V_23 ;
F_4 ( & V_7 -> V_14 [ V_5 ] . V_15 , 0 ) ;
V_7 -> V_14 [ V_5 ] . V_24 = V_25 ;
F_65 ( & V_7 -> V_14 [ V_5 ] . V_114 ) ;
}
F_65 ( & V_7 -> V_128 ) ;
if ( F_66 ( V_181 ) ) {
V_41 = - V_182 ;
goto V_183;
}
F_25 () ;
V_7 -> V_103 = F_67 ( F_28 , V_7 , L_36 ,
V_7 -> V_72 -> V_73 -> V_74 , V_7 -> V_72 -> V_184 ) ;
if ( F_68 ( V_7 -> V_103 ) ) {
V_41 = F_69 ( V_7 -> V_103 ) ;
F_14 ( L_37 ,
V_41 ) ;
goto V_183;
}
return 0 ;
V_183:
F_70 ( V_7 -> V_72 ) ;
V_180:
F_71 ( V_7 -> V_14 ) ;
V_177:
F_71 ( V_7 ) ;
exit:
V_98 -> V_100 = NULL ;
return V_41 ;
}
void F_72 ( struct V_97 * V_98 )
{
struct V_6 * V_7 = V_98 -> V_100 ;
int V_5 ;
F_6 ( L_1 , V_34 ) ;
F_73 ( V_7 -> V_103 ) ;
for ( V_5 = 0 ; V_5 < V_7 -> V_106 ; V_5 ++ ) {
F_20 ( V_7 , V_5 ) ;
F_74 ( V_7 -> V_14 [ V_5 ] . V_82 . V_83 ) ;
}
F_71 ( V_7 -> V_14 ) ;
F_70 ( V_7 -> V_72 ) ;
F_71 ( V_7 ) ;
V_98 -> V_100 = NULL ;
}
