static unsigned short F_1 ( unsigned char * V_1 , int V_2 )
{
unsigned short V_3 = 0xffff ;
while ( V_2 -- )
V_3 = ( V_3 << 8 ) ^ V_4 [ ( ( V_3 >> 8 ) ^ * V_1 ++ ) & 0xff ] ;
return V_3 ;
}
static int F_2 ( unsigned char * V_1 , int V_2 )
{
unsigned short V_3 = 0xffff ;
if ( V_2 < 3 )
return - 1 ;
while ( V_2 -- )
V_3 = ( V_3 << 8 ) ^ V_4 [ ( ( V_3 >> 8 ) ^ * V_1 ++ ) & 0xff ] ;
if ( ( V_3 & 0xffff ) != 0x7070 )
return - 1 ;
return 0 ;
}
static int F_3 ( unsigned char * V_1 , int V_2 )
{
unsigned short V_3 = 0x0000 ;
if ( V_2 < 3 )
return - 1 ;
V_3 = F_4 ( 0 , V_1 , V_2 ) ;
if ( V_3 != 0x0000 )
return - 1 ;
return 0 ;
}
static int F_5 ( unsigned char * V_5 , unsigned char * V_6 , int V_7 )
{
unsigned char * V_8 = V_6 ;
unsigned char V_9 ;
* V_8 ++ = V_10 ;
while ( V_7 -- > 0 ) {
switch ( V_9 = * V_5 ++ ) {
case V_10 :
* V_8 ++ = V_11 ;
* V_8 ++ = V_12 ;
break;
case V_11 :
* V_8 ++ = V_11 ;
* V_8 ++ = V_13 ;
break;
default:
* V_8 ++ = V_9 ;
break;
}
}
* V_8 ++ = V_10 ;
return V_8 - V_6 ;
}
static int F_6 ( unsigned char * V_5 , unsigned char * V_6 , unsigned short V_3 ,
int V_7 )
{
unsigned char * V_8 = V_6 ;
unsigned char V_9 = 0 ;
* V_8 ++ = V_10 ;
while ( V_7 > 0 ) {
if ( V_7 > 2 )
V_9 = * V_5 ++ ;
else if ( V_7 > 1 )
V_9 = V_3 >> 8 ;
else if ( V_7 > 0 )
V_9 = V_3 & 0xff ;
V_7 -- ;
switch ( V_9 ) {
case V_10 :
* V_8 ++ = V_11 ;
* V_8 ++ = V_12 ;
break;
case V_11 :
* V_8 ++ = V_11 ;
* V_8 ++ = V_13 ;
break;
default:
* V_8 ++ = V_9 ;
break;
}
}
* V_8 ++ = V_10 ;
return V_8 - V_6 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 ;
F_8 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_20 [ 0 ] > 0x0f ) {
if ( V_15 -> V_20 [ 0 ] & 0x80 ) {
if ( F_3 ( V_15 -> V_20 , V_15 -> V_21 ) < 0 ) {
V_15 -> V_22 -> V_23 . V_24 ++ ;
F_9 ( & V_15 -> V_19 ) ;
return;
}
if ( V_15 -> V_25 != V_26 && V_15 -> V_27 ) {
F_10 ( V_28
L_1 ,
V_15 -> V_22 -> V_29 ) ;
V_15 -> V_25 = V_26 ;
}
V_15 -> V_21 -= 2 ;
* V_15 -> V_20 &= ~ 0x80 ;
} else if ( V_15 -> V_20 [ 0 ] & 0x20 ) {
if ( F_2 ( V_15 -> V_20 , V_15 -> V_21 ) < 0 ) {
V_15 -> V_22 -> V_23 . V_24 ++ ;
F_9 ( & V_15 -> V_19 ) ;
return;
}
if ( V_15 -> V_25 != V_30 && V_15 -> V_27 ) {
F_10 ( V_28
L_2 ,
V_15 -> V_22 -> V_29 ) ;
V_15 -> V_25 = V_30 ;
}
V_15 -> V_21 -= 2 ;
* V_15 -> V_20 &= ~ 0x20 ;
}
}
V_18 = V_15 -> V_21 ;
if ( ( V_17 = F_11 ( V_18 ) ) == NULL ) {
F_10 ( V_31 L_3 ,
V_15 -> V_22 -> V_29 ) ;
V_15 -> V_22 -> V_23 . V_32 ++ ;
F_9 ( & V_15 -> V_19 ) ;
return;
}
F_12 ( V_17 , V_15 -> V_20 , V_18 ) ;
V_17 -> V_33 = F_13 ( V_17 , V_15 -> V_22 ) ;
F_14 ( V_17 ) ;
V_15 -> V_22 -> V_23 . V_34 ++ ;
V_15 -> V_22 -> V_23 . V_35 += V_18 ;
F_9 ( & V_15 -> V_19 ) ;
}
static void F_15 ( struct V_14 * V_15 , unsigned char V_5 )
{
switch ( V_5 ) {
case V_10 :
if ( F_16 ( V_36 , & V_15 -> V_37 ) )
F_17 ( V_36 , & V_15 -> V_37 ) ;
if ( ! F_18 ( V_38 , & V_15 -> V_37 ) && ( V_15 -> V_21 > 2 ) )
F_7 ( V_15 ) ;
F_17 ( V_39 , & V_15 -> V_37 ) ;
V_15 -> V_21 = 0 ;
return;
case V_11 :
F_19 ( V_39 , & V_15 -> V_37 ) ;
return;
case V_13 :
if ( F_18 ( V_39 , & V_15 -> V_37 ) )
V_5 = V_11 ;
break;
case V_12 :
if ( F_18 ( V_39 , & V_15 -> V_37 ) )
V_5 = V_10 ;
break;
}
F_8 ( & V_15 -> V_19 ) ;
if ( ! F_16 ( V_38 , & V_15 -> V_37 ) ) {
if ( V_15 -> V_21 < V_15 -> V_40 ) {
V_15 -> V_20 [ V_15 -> V_21 ++ ] = V_5 ;
F_9 ( & V_15 -> V_19 ) ;
return;
}
V_15 -> V_22 -> V_23 . V_41 ++ ;
F_19 ( V_38 , & V_15 -> V_37 ) ;
}
F_9 ( & V_15 -> V_19 ) ;
}
static int F_20 ( struct V_42 * V_22 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
F_21 ( V_22 ) ;
F_22 ( V_22 ) ;
memcpy ( V_22 -> V_46 , & V_45 -> V_47 , V_48 ) ;
F_23 ( V_22 ) ;
F_24 ( V_22 ) ;
return 0 ;
}
static void F_25 ( struct V_14 * V_15 )
{
struct V_42 * V_22 = V_15 -> V_22 ;
unsigned char * V_49 , * V_20 , * V_50 , * V_51 ;
int V_7 ;
V_7 = V_22 -> V_52 * 2 ;
if ( V_7 < 576 * 2 )
V_7 = 576 * 2 ;
V_49 = F_26 ( V_7 + 4 , V_53 ) ;
V_20 = F_26 ( V_7 + 4 , V_53 ) ;
if ( V_49 == NULL || V_20 == NULL ) {
F_10 ( V_31 L_4
L_5 ,
V_15 -> V_22 -> V_29 ) ;
V_22 -> V_52 = V_15 -> V_52 ;
F_27 ( V_49 ) ;
F_27 ( V_20 ) ;
return;
}
F_8 ( & V_15 -> V_19 ) ;
V_50 = V_15 -> V_49 ;
V_15 -> V_49 = V_49 ;
V_51 = V_15 -> V_20 ;
V_15 -> V_20 = V_20 ;
if ( V_15 -> V_54 ) {
if ( V_15 -> V_54 <= V_7 ) {
memcpy ( V_15 -> V_49 , V_15 -> V_55 , V_15 -> V_54 ) ;
} else {
V_15 -> V_54 = 0 ;
V_22 -> V_23 . V_56 ++ ;
}
}
V_15 -> V_55 = V_15 -> V_49 ;
if ( V_15 -> V_21 ) {
if ( V_15 -> V_21 <= V_7 ) {
memcpy ( V_15 -> V_20 , V_51 , V_15 -> V_21 ) ;
} else {
V_15 -> V_21 = 0 ;
V_22 -> V_23 . V_41 ++ ;
F_19 ( V_38 , & V_15 -> V_37 ) ;
}
}
V_15 -> V_52 = V_22 -> V_52 + 73 ;
V_15 -> V_40 = V_7 ;
F_9 ( & V_15 -> V_19 ) ;
F_27 ( V_50 ) ;
F_27 ( V_51 ) ;
}
static void F_28 ( struct V_42 * V_22 , unsigned char * V_57 , int V_7 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
unsigned char * V_58 ;
int V_59 , V_18 ;
if ( V_15 -> V_52 != V_15 -> V_22 -> V_52 + 73 )
F_25 ( V_15 ) ;
if ( V_7 > V_15 -> V_52 ) {
V_7 = V_15 -> V_52 ;
F_10 ( V_31 L_6 , V_15 -> V_22 -> V_29 ) ;
V_22 -> V_23 . V_56 ++ ;
F_30 ( V_22 ) ;
return;
}
V_58 = V_57 ;
F_8 ( & V_15 -> V_19 ) ;
if ( ( * V_58 & 0x0f ) != 0 ) {
switch ( * V_58 & 0xff ) {
case 0x85 :
if ( V_7 > 1 ) {
int V_60 = ( V_58 [ 1 ] & 0xff ) ;
switch( V_60 ) {
case 3 :
V_15 -> V_25 = V_26 ;
break;
case 2 :
V_15 -> V_25 = V_30 ;
break;
case 1 :
V_15 -> V_25 = V_61 ;
break;
case 0 :
default:
V_15 -> V_25 = V_62 ;
V_60 = 0 ;
}
V_15 -> V_27 = ( V_60 ? 0 : 1 ) ;
F_10 ( V_28 L_7 , V_15 -> V_22 -> V_29 , ( V_7 ) ? L_8 : L_9 , V_60 ) ;
}
F_9 ( & V_15 -> V_19 ) ;
F_30 ( V_22 ) ;
return;
default:
V_18 = F_5 ( V_58 , V_15 -> V_49 , V_7 ) ;
}
} else {
unsigned short V_3 ;
switch ( V_15 -> V_25 ) {
case V_62 :
V_15 -> V_25 = V_63 ;
F_10 ( V_28 L_10 , V_15 -> V_22 -> V_29 ) ;
case V_26 :
* V_58 |= 0x80 ;
V_3 = F_31 ( F_4 ( 0 , V_58 , V_7 ) ) ;
V_18 = F_6 ( V_58 , V_15 -> V_49 , V_3 , V_7 + 2 ) ;
break;
case V_63 :
V_15 -> V_25 = V_61 ;
F_10 ( V_28 L_11 , V_15 -> V_22 -> V_29 ) ;
case V_30 :
* V_58 |= 0x20 ;
V_3 = F_1 ( V_58 , V_7 ) ;
V_18 = F_6 ( V_58 , V_15 -> V_49 , V_3 , V_7 + 2 ) ;
break;
default:
V_18 = F_5 ( V_58 , V_15 -> V_49 , V_7 ) ;
}
}
F_9 ( & V_15 -> V_19 ) ;
F_19 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
V_59 = V_15 -> V_65 -> V_66 -> V_67 ( V_15 -> V_65 , V_15 -> V_49 , V_18 ) ;
V_22 -> V_23 . V_68 ++ ;
V_22 -> V_23 . V_69 += V_59 ;
F_32 ( V_15 -> V_22 ) ;
V_15 -> V_54 = V_18 - V_59 ;
V_15 -> V_55 = V_15 -> V_49 + V_59 ;
}
static T_1 F_33 ( struct V_16 * V_17 , struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( V_17 -> V_33 == F_34 ( V_70 ) )
return F_35 ( V_17 ) ;
if ( ! F_36 ( V_22 ) ) {
F_10 ( V_31 L_12 , V_22 -> V_29 ) ;
return V_71 ;
}
if ( F_37 ( V_22 ) ) {
if ( F_38 ( V_72 , F_39 ( V_22 ) + 20 * V_73 ) ) {
return V_71 ;
}
F_10 ( V_31 L_13 , V_22 -> V_29 ,
( F_40 ( V_15 -> V_65 ) || V_15 -> V_54 ) ?
L_14 : L_15 ) ;
V_15 -> V_54 = 0 ;
F_17 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
F_30 ( V_22 ) ;
}
F_41 ( V_22 ) ;
F_28 ( V_22 , V_17 -> V_74 , V_17 -> V_7 ) ;
F_42 ( V_17 ) ;
return V_75 ;
}
static int F_43 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( V_15 -> V_65 == NULL )
return - V_76 ;
return 0 ;
}
static int F_44 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
unsigned long V_7 ;
if ( V_15 -> V_65 == NULL )
return - V_76 ;
V_7 = V_22 -> V_52 * 2 ;
if ( V_7 < 576 * 2 )
V_7 = 576 * 2 ;
if ( ( V_15 -> V_20 = F_26 ( V_7 + 4 , V_77 ) ) == NULL )
goto V_78;
if ( ( V_15 -> V_49 = F_26 ( V_7 + 4 , V_77 ) ) == NULL )
goto V_79;
V_15 -> V_52 = V_22 -> V_52 + 73 ;
V_15 -> V_40 = V_7 ;
V_15 -> V_21 = 0 ;
V_15 -> V_54 = 0 ;
V_15 -> V_37 &= ( 1 << V_80 ) ;
F_45 ( & V_15 -> V_19 ) ;
return 0 ;
V_79:
F_27 ( V_15 -> V_20 ) ;
V_78:
return - V_81 ;
}
static int F_46 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( V_15 -> V_65 )
F_17 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
F_41 ( V_22 ) ;
return 0 ;
}
static void F_47 ( struct V_42 * V_22 )
{
V_22 -> V_52 = V_82 ;
V_22 -> V_83 = V_84 ;
V_22 -> V_85 = V_48 ;
V_22 -> type = V_86 ;
V_22 -> V_87 = 10 ;
V_22 -> V_88 = & V_89 ;
V_22 -> V_90 = & V_91 ;
memcpy ( V_22 -> V_92 , & V_93 , V_48 ) ;
memcpy ( V_22 -> V_46 , & V_94 , V_48 ) ;
V_22 -> V_37 = V_95 | V_96 ;
}
static struct V_14 * F_48 ( struct V_97 * V_65 )
{
struct V_14 * V_15 ;
F_49 ( & V_98 ) ;
V_15 = V_65 -> V_99 ;
if ( V_15 )
F_50 ( & V_15 -> V_100 ) ;
F_51 ( & V_98 ) ;
return V_15 ;
}
static void F_52 ( struct V_14 * V_15 )
{
if ( F_53 ( & V_15 -> V_100 ) )
F_54 ( & V_15 -> V_101 ) ;
}
static int F_55 ( struct V_97 * V_65 )
{
struct V_42 * V_22 ;
struct V_14 * V_15 ;
int V_102 ;
if ( ! F_56 ( V_103 ) )
return - V_104 ;
if ( V_65 -> V_66 -> V_67 == NULL )
return - V_105 ;
V_22 = F_57 ( sizeof( struct V_14 ) , L_16 , V_106 ,
F_47 ) ;
if ( ! V_22 ) {
V_102 = - V_81 ;
goto V_107;
}
V_15 = F_29 ( V_22 ) ;
V_15 -> V_22 = V_22 ;
F_45 ( & V_15 -> V_19 ) ;
F_58 ( & V_15 -> V_100 , 1 ) ;
F_59 ( & V_15 -> V_101 , 0 ) ;
V_15 -> V_65 = V_65 ;
V_65 -> V_99 = V_15 ;
V_65 -> V_108 = 65535 ;
F_60 ( V_65 ) ;
V_22 -> type = V_86 ;
V_102 = F_44 ( V_15 -> V_22 ) ;
if ( V_102 )
goto V_109;
V_102 = F_61 ( V_22 ) ;
if ( V_102 )
goto V_110;
switch ( V_111 ) {
case 3 :
V_15 -> V_25 = V_26 ;
F_10 ( V_28 L_17 ,
V_15 -> V_22 -> V_29 ) ;
break;
case 2 :
V_15 -> V_25 = V_30 ;
F_10 ( V_28 L_18 ,
V_15 -> V_22 -> V_29 ) ;
break;
case 1 :
V_15 -> V_25 = V_61 ;
F_10 ( V_28 L_19 ,
V_15 -> V_22 -> V_29 ) ;
break;
case 0 :
default:
V_111 = 0 ;
F_10 ( V_28 L_20 ,
V_15 -> V_22 -> V_29 ) ;
V_15 -> V_25 = V_62 ;
}
V_15 -> V_27 = ( V_111 ? 0 : 1 ) ;
F_30 ( V_22 ) ;
return 0 ;
V_110:
F_27 ( V_15 -> V_20 ) ;
F_27 ( V_15 -> V_49 ) ;
V_109:
F_62 ( V_22 ) ;
V_107:
return V_102 ;
}
static void F_63 ( struct V_97 * V_65 )
{
struct V_14 * V_15 ;
F_64 ( & V_98 ) ;
V_15 = V_65 -> V_99 ;
V_65 -> V_99 = NULL ;
F_65 ( & V_98 ) ;
if ( ! V_15 )
return;
if ( ! F_53 ( & V_15 -> V_100 ) )
F_66 ( & V_15 -> V_101 ) ;
F_41 ( V_15 -> V_22 ) ;
F_27 ( V_15 -> V_20 ) ;
F_27 ( V_15 -> V_49 ) ;
V_15 -> V_65 = NULL ;
F_67 ( V_15 -> V_22 ) ;
}
static int F_68 ( struct V_97 * V_65 , struct V_112 * V_112 ,
unsigned int V_60 , unsigned long V_113 )
{
struct V_14 * V_15 = F_48 ( V_65 ) ;
struct V_42 * V_22 ;
unsigned int V_114 , V_102 ;
if ( V_15 == NULL )
return - V_115 ;
V_22 = V_15 -> V_22 ;
switch ( V_60 ) {
case V_116 :
V_102 = F_69 ( ( void V_117 * ) V_113 , V_15 -> V_22 -> V_29 ,
strlen ( V_15 -> V_22 -> V_29 ) + 1 ) ? - V_118 : 0 ;
break;
case V_119 :
V_102 = F_70 ( 4 , ( int V_117 * ) V_113 ) ;
break;
case V_120 :
if ( F_71 ( V_114 , ( int V_117 * ) V_113 ) ) {
V_102 = - V_118 ;
break;
}
V_15 -> V_121 = V_114 ;
V_22 -> V_85 = V_48 ;
V_22 -> V_83 = V_122 +
V_84 + 3 ;
V_22 -> type = V_86 ;
V_102 = 0 ;
break;
case V_123 : {
char V_43 [ V_48 ] ;
if ( F_72 ( & V_43 ,
( void V_117 * ) V_113 , V_48 ) ) {
V_102 = - V_118 ;
break;
}
F_21 ( V_22 ) ;
memcpy ( V_22 -> V_46 , V_43 , V_48 ) ;
F_24 ( V_22 ) ;
V_102 = 0 ;
break;
}
default:
V_102 = - V_124 ;
}
F_52 ( V_15 ) ;
return V_102 ;
}
static long F_73 ( struct V_97 * V_65 , struct V_112 * V_112 ,
unsigned int V_60 , unsigned long V_113 )
{
switch ( V_60 ) {
case V_116 :
case V_119 :
case V_120 :
case V_123 :
return F_68 ( V_65 , V_112 , V_60 ,
( unsigned long ) F_74 ( V_113 ) ) ;
}
return - V_124 ;
}
static void F_75 ( struct V_97 * V_65 , const unsigned char * V_1 ,
char * V_125 , int V_18 )
{
struct V_14 * V_15 = F_48 ( V_65 ) ;
if ( ! V_15 )
return;
if ( V_15 -> V_52 != V_15 -> V_22 -> V_52 + 73 )
F_25 ( V_15 ) ;
while ( V_18 -- ) {
if ( V_125 != NULL && * V_125 ++ ) {
if ( ! F_76 ( V_38 , & V_15 -> V_37 ) )
V_15 -> V_22 -> V_23 . V_24 ++ ;
V_1 ++ ;
continue;
}
F_15 ( V_15 , * V_1 ++ ) ;
}
F_52 ( V_15 ) ;
F_77 ( V_65 ) ;
}
static void F_78 ( struct V_97 * V_65 )
{
struct V_14 * V_15 = F_48 ( V_65 ) ;
int V_59 ;
if ( ! V_15 )
return;
if ( V_15 -> V_54 <= 0 ) {
F_17 ( V_64 , & V_65 -> V_37 ) ;
F_79 ( V_15 -> V_22 ) ;
goto V_107;
}
V_59 = V_65 -> V_66 -> V_67 ( V_65 , V_15 -> V_55 , V_15 -> V_54 ) ;
V_15 -> V_54 -= V_59 ;
V_15 -> V_55 += V_59 ;
V_107:
F_52 ( V_15 ) ;
}
static int T_2 F_80 ( void )
{
int V_126 ;
F_10 ( V_127 ) ;
V_126 = F_81 ( V_128 , & V_129 ) ;
if ( V_126 != 0 )
F_10 ( V_130 , V_126 ) ;
return V_126 ;
}
static void T_3 F_82 ( void )
{
int V_131 ;
if ( ( V_131 = F_83 ( V_128 ) ) )
F_10 ( V_132 , V_131 ) ;
}
