static unsigned long F_1 ( int V_1 )
{
int V_2 = F_2 ( V_1 ) ;
return F_3 ( V_3 , V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
unsigned long V_6 ;
V_5 -> V_7 = NULL ;
F_5 ( & V_8 , V_6 ) ;
if ( V_9 ) {
V_9 -> V_7 = V_5 ;
} else {
V_10 = V_5 ;
}
V_9 = V_5 ;
F_6 ( & V_8 , V_6 ) ;
if ( V_11 & V_12 )
F_7 ( L_1 , V_5 -> V_13 [ 0 ] ) ;
}
static struct V_4 * F_8 ( void )
{
unsigned long V_6 ;
int V_14 ;
struct V_4 * V_5 = NULL ;
F_5 ( & V_8 , V_6 ) ;
if ( V_10 ) {
V_5 = V_10 ;
V_10 = V_5 -> V_7 ;
if( ! V_10 ) V_9 = NULL ;
}
F_6 ( & V_8 , V_6 ) ;
if ( ( V_11 & V_12 ) && V_5 ) {
int V_15 ;
F_7 ( V_16 L_2 ) ;
V_15 = V_5 -> V_17 ;
if ( V_15 > 100 ) V_15 = 100 ;
for( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) F_7 ( L_3 , V_5 -> V_13 [ V_14 ] ) ;
F_7 ( L_4 ) ;
}
return V_5 ;
}
static int F_9 ( struct V_18 * V_19 , int V_20 )
{
int V_14 ;
for( V_14 = 0 ; V_14 < 200000 ; V_14 ++ ) {
if ( V_20 != F_10 ( V_19 -> V_21 + 6 ) ) return 0 ;
F_11 ( 100 ) ;
}
return 1 ;
}
static int F_12 ( void )
{
unsigned long V_6 ;
int V_14 ;
F_5 ( & V_22 , V_6 ) ;
for( V_14 = 1 ; V_14 < 16 ; V_14 ++ ) if( ! V_23 [ V_14 ] ) {
V_23 [ V_14 ] = 1 ;
F_6 ( & V_22 , V_6 ) ;
return V_14 ;
}
F_6 ( & V_22 , V_6 ) ;
return 0 ;
}
static void F_13 ( struct V_18 * V_19 )
{
int V_24 = V_19 -> V_24 ;
int V_25 = V_19 -> V_21 ;
unsigned long V_6 ;
V_6 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_26 ) ;
F_18 ( V_24 , F_19 ( V_27 ) ) ;
F_20 ( V_24 , 50 ) ;
F_21 ( V_24 ) ;
F_22 ( V_6 ) ;
F_10 ( V_25 + 3 ) ;
F_10 ( V_25 + 2 ) ;
if ( F_9 ( V_19 , 0xfc ) ) F_7 ( L_5 ) ;
}
static void F_23 ( struct V_18 * V_19 )
{
int V_24 = V_19 -> V_24 ;
int V_25 = V_19 -> V_21 ;
unsigned long V_6 ;
V_6 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_26 ) ;
F_18 ( V_24 , F_19 ( V_28 ) ) ;
F_20 ( V_24 , 800 ) ;
F_21 ( V_24 ) ;
F_22 ( V_6 ) ;
F_10 ( V_25 + 3 ) ;
F_10 ( V_25 + 2 ) ;
if ( F_9 ( V_19 , 0xfd ) ) F_7 ( L_6 ) ;
F_24 ( V_19 ) ;
}
static void F_25 ( struct V_18 * V_19 )
{
int V_24 = V_19 -> V_24 ;
int V_25 = V_19 -> V_21 ;
unsigned long V_6 ;
V_6 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_29 ) ;
F_18 ( V_24 , F_19 ( V_28 ) ) ;
F_20 ( V_24 , 800 ) ;
F_21 ( V_24 ) ;
F_22 ( V_6 ) ;
F_10 ( V_25 + 3 ) ;
F_10 ( V_25 + 2 ) ;
if ( F_9 ( V_19 , 0xfb ) ) {
V_6 = F_14 () ;
F_7 ( L_7 ,
F_26 ( V_19 -> V_24 ) ) ;
F_22 ( V_6 ) ;
}
}
static void F_27 ( struct V_18 * V_19 )
{
int V_24 = V_19 -> V_24 ;
int V_25 = V_19 -> V_21 ;
unsigned long V_6 ;
V_6 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_26 ) ;
F_18 ( V_24 , F_19 ( V_28 ) ) ;
F_20 ( V_24 , 800 ) ;
F_21 ( V_24 ) ;
F_22 ( V_6 ) ;
F_10 ( V_25 + 3 ) ;
F_10 ( V_25 + 2 ) ;
if ( F_9 ( V_19 , 0xfb ) ) F_7 ( L_8 ) ;
}
static void F_28 ( struct V_18 * V_19 )
{
int V_24 = V_19 -> V_24 ;
int V_25 = V_19 -> V_21 ;
unsigned long V_6 ;
V_6 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_29 ) ;
F_18 ( V_24 , F_19 ( V_27 ) ) ;
F_20 ( V_24 , 50 ) ;
F_21 ( V_24 ) ;
F_22 ( V_6 ) ;
F_10 ( V_25 + 3 ) ;
F_10 ( V_25 + 2 ) ;
if ( F_9 ( V_19 , 0xfa ) ) F_7 ( L_9 ) ;
}
static void F_29 ( struct V_18 * V_19 )
{
unsigned long V_6 ;
int V_30 ;
struct V_4 * V_31 = NULL ;
int V_32 ;
int V_14 ;
int V_25 = V_19 -> V_21 ;
F_5 ( & V_8 , V_6 ) ;
if( V_33 ) {
F_6 ( & V_8 , V_6 ) ;
return;
}
V_33 = 1 ;
F_6 ( & V_8 , V_6 ) ;
( void ) F_10 ( V_25 + 6 ) ;
V_32 = 100 ;
V_34:
if ( 0 > V_32 -- ) {
F_7 ( L_10 ) ;
goto V_35;
}
V_30 = F_10 ( V_25 + 6 ) ;
if ( V_30 != F_10 ( V_25 + 6 ) ) goto V_34;
switch( V_30 ) {
case 0xfc :
if ( V_11 & V_12 ) F_7 ( L_11 ) ;
F_13 ( V_19 ) ;
break;
case 0xfd :
if( V_11 & V_12 ) F_7 ( L_12 ) ;
F_23 ( V_19 ) ;
break;
case 0xf9 :
if ( V_11 & V_12 ) F_7 ( L_13 ) ;
if( ! V_23 [ 0 ] ) {
V_23 [ 0 ] = 1 ;
V_36 [ 0 ] . V_13 = V_37 ;
V_36 [ 0 ] . V_17 = 2 ;
V_36 [ 0 ] . V_38 = V_39 ;
V_36 [ 0 ] . V_40 = 2 ;
V_36 [ 0 ] . V_41 = 0 ;
V_36 [ 0 ] . V_42 = 0 ;
F_4 ( & V_36 [ 0 ] ) ;
}
F_10 ( V_19 -> V_21 + 1 ) ;
F_10 ( V_19 -> V_21 + 0 ) ;
if( F_9 ( V_19 , 0xf9 ) )
F_7 ( L_14 ) ;
break;
case 0xf8 :
if ( V_10 ) {
F_10 ( V_19 -> V_21 + 1 ) ;
F_10 ( V_19 -> V_21 + 0 ) ;
if( F_9 ( V_19 , 0xf8 ) )
F_7 ( L_15 ) ;
} else {
goto V_35;
}
break;
case 0xfa :
if( V_11 & V_12 ) F_7 ( L_16 ) ;
if ( V_10 ) {
V_31 = F_8 () ;
memcpy ( V_27 , V_31 -> V_13 , V_31 -> V_17 ) ;
V_27 [ 1 ] = V_31 -> V_42 ;
if ( V_11 > 1 ) {
int V_15 ;
F_7 ( L_17 ) ;
V_15 = V_31 -> V_17 ;
if ( V_15 > 100 ) V_15 = 100 ;
for( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_7 ( L_3 , V_27 [ V_14 ] ) ;
F_7 ( L_4 ) ;
}
F_28 ( V_19 ) ;
if( 0xfa == F_10 ( V_25 + 6 ) ) {
goto V_35;
}
} else {
if ( ! V_23 [ 0 ] ) {
V_23 [ 0 ] = 1 ;
V_36 [ 0 ] . V_13 = V_37 ;
V_36 [ 0 ] . V_17 = 2 ;
V_36 [ 0 ] . V_38 = V_39 ;
V_36 [ 0 ] . V_40 = 2 ;
V_36 [ 0 ] . V_41 = 0 ;
V_36 [ 0 ] . V_42 = 0 ;
F_4 ( & V_36 [ 0 ] ) ;
} else {
F_7 ( L_18 ) ;
goto V_35;
}
}
break;
case 0Xfb :
if( V_11 & V_12 ) F_7 ( L_19 ) ;
if( V_31 -> V_41 ) {
memcpy ( V_28 , V_31 -> V_38 , V_31 -> V_40 ) ;
F_25 ( V_19 ) ;
} else {
F_27 ( V_19 ) ;
if( V_31 -> V_42 ) {
memcpy ( V_31 -> V_38 , V_28 , V_31 -> V_40 ) ;
} else {
V_42 [ 0x0f & V_28 [ 0 ] ] = V_28 [ 1 ] ;
V_23 [ 0 ] = 0 ;
}
}
break;
}
goto V_34;
V_35:
V_33 = 0 ;
if ( V_19 -> V_43 ) {
F_10 ( V_25 + 7 ) ;
F_10 ( V_25 + 7 ) ;
}
}
static int F_30 ( struct V_18 * V_19 , void * V_13 , int V_17 ,
void * V_38 , int V_40 )
{
int V_14 = F_12 () ;
int V_44 ;
if( V_14 ) {
V_36 [ V_14 ] . V_13 = ( unsigned char * ) V_13 ;
V_36 [ V_14 ] . V_17 = V_17 ;
V_36 [ V_14 ] . V_38 = ( unsigned char * ) V_38 ;
V_36 [ V_14 ] . V_40 = V_40 ;
V_36 [ V_14 ] . V_41 = 1 ;
V_36 [ V_14 ] . V_42 = V_14 ;
F_4 ( & V_36 [ V_14 ] ) ;
F_29 ( V_19 ) ;
V_44 = V_42 [ V_14 ] ;
V_23 [ V_14 ] = 0 ;
return V_44 ;
}
F_7 ( L_20 ) ;
return - 1 ;
}
static int F_31 ( struct V_18 * V_19 , void * V_13 , int V_17 ,
void * V_38 , int V_40 )
{
int V_14 = F_12 () ;
int V_44 ;
if( V_14 ) {
V_36 [ V_14 ] . V_13 = ( unsigned char * ) V_13 ;
V_36 [ V_14 ] . V_17 = V_17 ;
V_36 [ V_14 ] . V_38 = ( unsigned char * ) V_38 ;
V_36 [ V_14 ] . V_40 = V_40 ;
V_36 [ V_14 ] . V_41 = 0 ;
V_36 [ V_14 ] . V_42 = V_14 ;
F_4 ( & V_36 [ V_14 ] ) ;
F_29 ( V_19 ) ;
V_44 = V_42 [ V_14 ] ;
V_23 [ V_14 ] = 0 ;
return V_44 ;
}
F_7 ( L_20 ) ;
return - 1 ;
}
static int F_32 ( struct V_18 * V_19 )
{
T_1 V_20 ;
V_20 . V_45 . V_46 = V_47 ;
return F_31 ( V_19 , & V_20 , sizeof( V_20 . V_45 ) , & V_20 , 0 ) ;
}
static int F_33 ( struct V_18 * V_19 , int V_48 )
{
T_1 V_20 ;
V_20 . V_49 . V_46 = V_50 ;
V_20 . V_49 . V_6 = V_48 ;
return F_30 ( V_19 , & V_20 , sizeof( V_20 . V_49 ) , & V_20 , 0 ) ;
}
static int F_24 ( struct V_18 * V_19 )
{
int V_51 , V_52 , V_53 , V_54 ;
int V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = (struct V_58 * ) V_27 ;
if ( V_59 -> V_46 != V_60 ) {
F_7 ( L_21 , V_59 -> V_46 ) ;
return - 1 ;
}
V_51 = V_59 -> V_51 ;
V_52 = V_59 -> V_52 ;
V_53 = V_59 -> V_61 ;
V_54 = V_59 -> V_62 ;
V_55 = V_54 ;
if ( V_53 == 1 )
V_55 += 8 ;
if( V_55 > 800 ) {
F_7 ( V_63 L_22 ,
V_19 -> V_64 , V_55 ) ;
return - 1 ;
}
if ( ( V_53 == 0 ) || ( V_53 > 2 ) ) {
F_7 ( V_63 L_23 , V_19 -> V_64 , V_53 ) ;
return - 1 ;
}
V_57 = F_34 ( 3 + V_55 ) ;
if ( V_57 == NULL )
{
F_7 ( L_24 ,
V_19 -> V_64 ) ;
return - 1 ;
}
V_57 -> V_19 = V_19 ;
if ( V_55 > V_54 )
F_35 ( V_57 , 8 ) ;
F_36 ( V_57 , V_54 + 3 ) ;
V_57 -> V_65 = F_37 ( V_66 ) ;
V_57 -> V_67 [ 0 ] = V_51 ;
V_57 -> V_67 [ 1 ] = V_52 ;
V_57 -> V_67 [ 2 ] = V_53 ;
F_38 ( V_57 ) ;
F_39 ( V_57 , 3 ) ;
F_40 ( V_57 , V_28 , V_54 ) ;
F_41 ( V_57 ) ;
V_19 -> V_68 . V_69 ++ ;
V_19 -> V_68 . V_70 += V_57 -> V_54 ;
F_42 ( V_57 ) ;
return 0 ;
}
static T_2
F_43 ( int V_43 , void * V_71 )
{
struct V_18 * V_19 = V_71 ;
if ( V_19 == NULL ) {
F_7 ( L_25 ) ;
return V_72 ;
}
F_10 ( V_19 -> V_21 + 6 ) ;
F_29 ( V_19 ) ;
return V_73 ;
}
static int F_44 ( struct V_18 * V_19 , struct V_74 * V_75 , int V_76 )
{
struct V_77 * V_78 = (struct V_77 * ) & V_75 -> V_79 ;
struct V_80 * V_81 = F_45 ( V_19 ) ;
struct V_82 * V_83 = & V_81 -> V_84 ;
struct V_85 V_20 ;
int V_86 ;
if( V_11 & V_87 ) F_7 ( L_26 ) ;
switch( V_76 ) {
case V_88 :
V_83 -> V_89 = V_78 -> V_90 . V_89 ;
V_20 . V_46 = V_91 ;
V_20 . V_92 = V_78 -> V_90 . V_93 ;
V_83 -> V_93 = F_31 ( V_19 , & V_20 , sizeof( V_20 ) , & V_20 , 0 ) ;
V_86 = F_32 ( V_19 ) ;
V_86 |= V_94 ;
F_33 ( V_19 , V_86 ) ;
V_19 -> V_95 [ 0 ] = 0xFF ;
V_19 -> V_96 [ 0 ] = V_83 -> V_93 ;
V_19 -> V_97 = 1 ;
return 0 ;
case V_98 :
V_78 -> V_90 . V_89 = V_83 -> V_89 ;
V_78 -> V_90 . V_93 = V_83 -> V_93 ;
return 0 ;
default:
return - V_99 ;
}
}
static void F_46 ( struct V_18 * V_19 )
{
}
static void F_47 ( unsigned long V_100 )
{
struct V_18 * V_19 = (struct V_18 * ) V_100 ;
F_48 ( & V_101 ) ;
if( V_11 & V_87 ) {
if ( ! V_102 ) {
V_102 = 50 ;
F_7 ( L_27 ) ;
}
V_102 -- ;
}
if ( ! V_19 )
return;
F_29 ( V_19 ) ;
V_101 . V_103 = V_104 + V_105 / 20 ;
F_49 ( & V_101 ) ;
}
static T_3 F_50 ( struct V_56 * V_57 , struct V_18 * V_19 )
{
int V_14 ;
struct V_106 V_13 ;
unsigned char * V_107 ;
V_13 . V_46 = V_108 ;
V_13 . V_51 = V_57 -> V_67 [ 0 ] ;
V_13 . V_61 = V_57 -> V_67 [ 2 ] ;
F_39 ( V_57 , 3 ) ;
V_13 . V_62 = V_57 -> V_54 ;
F_41 ( V_57 ) ;
if( V_11 & V_109 ) {
F_7 ( L_28 ) ;
for( V_14 = 0 ; V_14 < 6 ; V_14 ++ )
F_7 ( L_3 , ( ( unsigned char * ) & V_13 ) [ V_14 ] ) ;
F_7 ( L_4 ) ;
}
V_107 = F_51 ( V_57 ) ;
F_30 ( V_19 , & V_13 , sizeof( V_13 ) , V_107 , V_57 -> V_54 ) ;
if( V_11 & V_109 ) {
F_7 ( L_29 , V_57 -> V_54 ) ;
for ( V_14 = 0 ; V_14 < V_57 -> V_54 ; V_14 ++ )
F_7 ( L_3 , V_107 [ V_14 ] ) ;
F_7 ( L_4 ) ;
}
V_19 -> V_68 . V_110 ++ ;
V_19 -> V_68 . V_111 += V_57 -> V_54 ;
F_52 ( V_57 ) ;
return V_112 ;
}
static int T_4 F_53 ( int V_25 , int V_24 )
{
int V_113 = ( V_24 == 3 ) ? 2 : ( V_24 == 1 ) ? 1 : 3 ;
unsigned long V_114 ;
unsigned long V_115 ;
if ( V_113 & 1 ) {
if ( F_54 ( 1 , L_30 ) ) {
V_113 &= ~ 1 ;
} else {
V_115 = F_14 () ;
F_15 ( 1 ) ;
F_16 ( 1 ) ;
F_17 ( 1 , V_29 ) ;
F_18 ( 1 , F_19 ( V_28 ) ) ;
F_20 ( 1 , sizeof( struct V_116 ) ) ;
F_21 ( 1 ) ;
F_22 ( V_115 ) ;
}
}
if ( V_113 & 2 ) {
if ( F_54 ( 3 , L_30 ) ) {
V_113 &= ~ 2 ;
} else {
V_115 = F_14 () ;
F_15 ( 3 ) ;
F_16 ( 3 ) ;
F_17 ( 3 , V_29 ) ;
F_18 ( 3 , F_19 ( V_28 ) ) ;
F_20 ( 3 , sizeof( struct V_116 ) ) ;
F_21 ( 3 ) ;
F_22 ( V_115 ) ;
}
}
V_28 [ 0 ] = V_117 ;
V_28 [ 1 ] = 1 ;
V_28 [ 2 ] = 0 ; V_28 [ 3 ] = 0 ;
V_28 [ 4 ] = 0 ; V_28 [ 5 ] = 1 ;
V_28 [ 6 ] = 0 ;
F_10 ( V_118 + 1 ) ;
F_10 ( V_118 + 0 ) ;
V_114 = V_104 + 100 * V_105 / 100 ;
while( F_55 ( V_104 , V_114 ) ) {
if ( 0xfa == F_10 ( V_118 + 6 ) ) break;
}
F_10 ( V_118 + 3 ) ;
F_10 ( V_118 + 2 ) ;
while( F_55 ( V_104 , V_114 ) ) {
if ( 0xfb == F_10 ( V_118 + 6 ) ) break;
}
if ( ( V_113 & 2 ) && ( F_26 ( 3 ) == sizeof( struct V_116 ) ) ) {
V_113 &= ~ 2 ;
F_56 ( 3 ) ;
}
if ( ( V_113 & 1 ) && ( F_26 ( 1 ) == sizeof( struct V_116 ) ) ) {
V_113 &= ~ 1 ;
F_56 ( 1 ) ;
}
if ( ! V_113 )
return 0 ;
return ( V_113 & 2 ) ? 3 : 1 ;
}
struct V_18 * T_4 F_57 ( void )
{
struct V_18 * V_19 ;
int V_119 = - V_120 ;
int V_48 = 0 , V_121 = 0 ;
int V_122 ;
unsigned long V_115 ;
unsigned long V_114 ;
V_19 = F_58 ( sizeof( struct V_80 ) ) ;
if ( ! V_19 )
goto V_123;
if ( V_118 != 0x240 && F_59 ( 0x220 , 8 , L_30 ) ) {
V_48 = F_10 ( 0x220 + 6 ) ;
if ( ( V_48 != 0xff ) && ( V_48 >= 0xf0 ) ) {
V_118 = 0x220 ;
goto V_124;
}
F_60 ( 0x220 , 8 ) ;
}
if ( V_118 != 0x220 && F_59 ( 0x240 , 8 , L_30 ) ) {
V_121 = F_10 ( 0x240 + 6 ) ;
if ( ( V_121 != 0xff ) && ( V_121 >= 0xf0 ) ) {
V_118 = 0x240 ;
goto V_124;
}
F_60 ( 0x240 , 8 ) ;
}
F_7 ( V_125 L_31 , V_48 , V_121 ) ;
V_119 = - V_126 ;
goto V_127;
V_124:
if ( V_43 < 2 ) {
unsigned long V_128 ;
V_128 = F_61 () ;
F_10 ( V_118 + 7 ) ;
F_10 ( V_118 + 7 ) ;
F_10 ( V_118 + 6 ) ;
F_62 ( 2 ) ;
V_122 = F_63 ( V_128 ) ;
if ( V_122 == 0 ) {
F_7 ( V_125 L_32 , V_118 ) ;
} else {
V_43 = V_122 ;
}
}
V_28 = ( unsigned char * ) F_1 ( 1000 ) ;
if ( ! V_28 ) {
F_7 ( V_125 L_33 ) ;
V_119 = - V_120 ;
goto V_129;
}
V_27 = & V_28 [ 800 ] ;
if( V_11 & V_87 ) {
F_7 ( L_34 , ( unsigned long ) V_28 ) ;
}
F_10 ( V_118 + 1 ) ;
F_10 ( V_118 + 3 ) ;
F_64 ( 20 ) ;
F_10 ( V_118 + 0 ) ;
F_10 ( V_118 + 2 ) ;
F_10 ( V_118 + 7 ) ;
F_10 ( V_118 + 4 ) ;
F_10 ( V_118 + 5 ) ;
F_10 ( V_118 + 5 ) ;
F_10 ( V_118 + 6 ) ;
F_65 ( 1 ) ;
V_24 = F_53 ( V_118 , V_24 ) ;
if ( ! V_24 ) {
F_7 ( V_125 L_35 ) ;
V_119 = - V_126 ;
goto V_130;
}
if( V_43 )
F_7 ( V_63 L_36 , V_118 , V_43 , V_24 ) ;
else
F_7 ( V_63 L_37 , V_118 , V_24 ) ;
V_19 -> V_131 = & V_132 ;
V_19 -> V_21 = V_118 ;
V_19 -> V_43 = V_43 ;
V_19 -> V_24 = V_24 ;
V_115 = F_14 () ;
F_15 ( V_24 ) ;
F_16 ( V_24 ) ;
F_17 ( V_24 , V_26 ) ;
F_18 ( V_24 , F_19 ( V_28 ) ) ;
F_20 ( V_24 , 0x100 ) ;
F_21 ( V_24 ) ;
F_22 ( V_115 ) ;
( void ) F_10 ( V_118 + 3 ) ;
( void ) F_10 ( V_118 + 2 ) ;
V_114 = V_104 + 100 * V_105 / 100 ;
while( F_55 ( V_104 , V_114 ) ) {
if( 0xf9 == F_10 ( V_118 + 6 ) )
break;
F_66 () ;
}
if( V_11 & V_87 ) {
F_7 ( L_38 ) ;
}
if ( V_43 && F_67 ( V_43 , F_43 , 0 , L_30 , V_19 ) >= 0 )
{
( void ) F_10 ( V_118 + 7 ) ;
( void ) F_10 ( V_118 + 7 ) ;
} else {
if( V_43 )
F_7 ( V_125 L_39 ) ;
V_19 -> V_43 = 0 ;
F_68 ( & V_101 ) ;
V_101 . V_133 = F_47 ;
V_101 . V_67 = ( unsigned long ) V_19 ;
V_101 . V_103 = V_104 + V_105 / 20 ;
F_49 ( & V_101 ) ;
}
V_119 = F_69 ( V_19 ) ;
if ( V_119 )
goto V_134;
return NULL ;
V_134:
F_70 ( & V_101 ) ;
if ( V_19 -> V_43 )
F_71 ( V_19 -> V_43 , V_19 ) ;
V_130:
F_72 ( ( unsigned long ) V_28 , F_2 ( 1000 ) ) ;
V_129:
F_60 ( V_118 , 8 ) ;
V_127:
F_73 ( V_19 ) ;
V_123:
return F_74 ( V_119 ) ;
}
static int T_4 F_75 ( char * V_135 )
{
int V_136 [ 5 ] ;
V_135 = F_76 ( V_135 , F_77 ( V_136 ) , V_136 ) ;
if ( V_136 [ 0 ] == 0 ) {
if ( V_135 && ! strncmp ( V_135 , L_40 , 4 ) ) {
}
else {
F_7 ( V_125
L_41 ) ;
return 0 ;
}
} else {
V_118 = V_136 [ 1 ] ;
if ( V_136 [ 0 ] > 1 ) {
V_43 = V_136 [ 2 ] ;
}
if ( V_136 [ 0 ] > 2 ) {
V_24 = V_136 [ 3 ] ;
}
}
return 1 ;
}
static int T_4 F_78 ( void )
{
if( V_118 == 0 )
F_7 ( V_137
L_42 ) ;
V_138 = F_57 () ;
if ( F_79 ( V_138 ) )
return F_80 ( V_138 ) ;
return 0 ;
}
static void T_5 F_81 ( void )
{
if( V_11 & V_87 ) F_7 ( L_43 ) ;
F_82 ( V_138 ) ;
V_101 . V_67 = 0 ;
F_70 ( & V_101 ) ;
if( V_11 & V_87 ) F_7 ( L_44 ) ;
if ( V_138 -> V_43 )
F_71 ( V_138 -> V_43 , V_138 ) ;
if( V_11 & V_87 ) F_7 ( L_45 ) ;
if ( V_138 -> V_24 )
F_56 ( V_138 -> V_24 ) ;
if( V_11 & V_87 ) F_7 ( L_46 ) ;
if ( V_138 -> V_21 )
F_60 ( V_138 -> V_21 , 8 ) ;
F_73 ( V_138 ) ;
if( V_11 & V_87 ) F_7 ( L_47 ) ;
F_72 ( ( unsigned long ) V_28 , F_2 ( 1000 ) ) ;
if( V_11 & V_87 ) F_7 ( L_48 ) ;
}
