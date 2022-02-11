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
memcpy ( F_12 ( V_17 , V_18 ) , V_15 -> V_20 , V_18 ) ;
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
V_18 = F_5 ( V_58 , ( unsigned char * ) V_15 -> V_49 , V_7 ) ;
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
V_18 = F_6 ( V_58 , ( unsigned char * ) V_15 -> V_49 , V_3 , V_7 + 2 ) ;
break;
case V_63 :
V_15 -> V_25 = V_61 ;
F_10 ( V_28 L_11 , V_15 -> V_22 -> V_29 ) ;
case V_30 :
* V_58 |= 0x20 ;
V_3 = F_1 ( V_58 , V_7 ) ;
V_18 = F_6 ( V_58 , ( unsigned char * ) V_15 -> V_49 , V_3 , V_7 + 2 ) ;
break;
default:
V_18 = F_5 ( V_58 , ( unsigned char * ) V_15 -> V_49 , V_7 ) ;
}
}
F_9 ( & V_15 -> V_19 ) ;
F_19 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
V_59 = V_15 -> V_65 -> V_66 -> V_67 ( V_15 -> V_65 , V_15 -> V_49 , V_18 ) ;
V_22 -> V_23 . V_68 ++ ;
V_22 -> V_23 . V_69 += V_59 ;
V_15 -> V_22 -> V_70 = V_71 ;
V_15 -> V_54 = V_18 - V_59 ;
V_15 -> V_55 = V_15 -> V_49 + V_59 ;
}
static T_1 F_32 ( struct V_16 * V_17 , struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( ! F_33 ( V_22 ) ) {
F_10 ( V_31 L_12 , V_22 -> V_29 ) ;
return V_72 ;
}
if ( F_34 ( V_22 ) ) {
if ( F_35 ( V_71 , V_22 -> V_70 + 20 * V_73 ) ) {
return V_72 ;
}
F_10 ( V_31 L_13 , V_22 -> V_29 ,
( F_36 ( V_15 -> V_65 ) || V_15 -> V_54 ) ?
L_14 : L_15 ) ;
V_15 -> V_54 = 0 ;
F_17 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
F_30 ( V_22 ) ;
}
if ( V_17 != NULL ) {
F_37 ( V_22 ) ;
F_28 ( V_22 , V_17 -> V_74 , V_17 -> V_7 ) ;
F_38 ( V_17 ) ;
}
return V_75 ;
}
static int F_39 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( V_15 -> V_65 == NULL )
return - V_76 ;
return 0 ;
}
static int F_40 ( struct V_16 * V_17 , struct V_42 * V_22 ,
unsigned short type , const void * V_77 ,
const void * V_78 , unsigned V_7 )
{
#ifdef F_41
if ( type != V_79 )
return F_42 ( V_17 , V_22 , type , V_77 , V_78 , V_7 ) ;
#endif
return 0 ;
}
static int F_43 ( struct V_16 * V_17 )
{
#ifdef F_41
return F_44 ( V_17 ) ;
#else
return 0 ;
#endif
}
static int F_45 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
unsigned long V_7 ;
if ( V_15 -> V_65 == NULL )
return - V_76 ;
V_7 = V_22 -> V_52 * 2 ;
if ( V_7 < 576 * 2 )
V_7 = 576 * 2 ;
if ( ( V_15 -> V_20 = F_26 ( V_7 + 4 , V_80 ) ) == NULL )
goto V_81;
if ( ( V_15 -> V_49 = F_26 ( V_7 + 4 , V_80 ) ) == NULL )
goto V_82;
V_15 -> V_52 = V_22 -> V_52 + 73 ;
V_15 -> V_40 = V_7 ;
V_15 -> V_21 = 0 ;
V_15 -> V_54 = 0 ;
V_15 -> V_37 &= ( 1 << V_83 ) ;
F_46 ( & V_15 -> V_19 ) ;
return 0 ;
V_82:
F_27 ( V_15 -> V_20 ) ;
V_81:
return - V_84 ;
}
static int F_47 ( struct V_42 * V_22 )
{
struct V_14 * V_15 = F_29 ( V_22 ) ;
if ( V_15 -> V_65 )
F_17 ( V_64 , & V_15 -> V_65 -> V_37 ) ;
F_37 ( V_22 ) ;
return 0 ;
}
static void F_48 ( struct V_42 * V_22 )
{
V_22 -> V_52 = V_85 ;
V_22 -> V_86 = 0 ;
V_22 -> V_87 = 0 ;
V_22 -> type = V_88 ;
V_22 -> V_89 = 10 ;
V_22 -> V_90 = & V_91 ;
V_22 -> V_92 = & V_93 ;
memcpy ( V_22 -> V_94 , & V_95 , V_48 ) ;
memcpy ( V_22 -> V_46 , & V_96 , V_48 ) ;
V_22 -> V_37 = V_97 | V_98 ;
}
static struct V_14 * F_49 ( struct V_99 * V_65 )
{
struct V_14 * V_15 ;
F_50 ( & V_100 ) ;
V_15 = V_65 -> V_101 ;
if ( V_15 )
F_51 ( & V_15 -> V_102 ) ;
F_52 ( & V_100 ) ;
return V_15 ;
}
static void F_53 ( struct V_14 * V_15 )
{
if ( F_54 ( & V_15 -> V_102 ) )
F_55 ( & V_15 -> V_103 ) ;
}
static int F_56 ( struct V_99 * V_65 )
{
struct V_42 * V_22 ;
struct V_14 * V_15 ;
int V_104 ;
if ( ! F_57 ( V_105 ) )
return - V_106 ;
if ( V_65 -> V_66 -> V_67 == NULL )
return - V_107 ;
V_22 = F_58 ( sizeof( struct V_14 ) , L_16 , F_48 ) ;
if ( ! V_22 ) {
V_104 = - V_84 ;
goto V_108;
}
V_15 = F_29 ( V_22 ) ;
V_15 -> V_22 = V_22 ;
F_46 ( & V_15 -> V_19 ) ;
F_59 ( & V_15 -> V_102 , 1 ) ;
F_60 ( & V_15 -> V_103 , 0 ) ;
V_15 -> V_65 = V_65 ;
V_65 -> V_101 = V_15 ;
V_65 -> V_109 = 65535 ;
F_61 ( V_65 ) ;
V_22 -> type = V_88 ;
if ( ( V_104 = F_45 ( V_15 -> V_22 ) ) ) {
goto V_110;
}
if ( F_62 ( V_22 ) )
goto V_111;
switch ( V_112 ) {
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
V_112 = 0 ;
F_10 ( V_28 L_20 ,
V_15 -> V_22 -> V_29 ) ;
V_15 -> V_25 = V_62 ;
}
V_15 -> V_27 = ( V_112 ? 0 : 1 ) ;
F_30 ( V_22 ) ;
return 0 ;
V_111:
F_27 ( V_15 -> V_20 ) ;
F_27 ( V_15 -> V_49 ) ;
V_110:
F_63 ( V_22 ) ;
V_108:
return V_104 ;
}
static void F_64 ( struct V_99 * V_65 )
{
struct V_14 * V_15 ;
F_65 ( & V_100 ) ;
V_15 = V_65 -> V_101 ;
V_65 -> V_101 = NULL ;
F_66 ( & V_100 ) ;
if ( ! V_15 )
return;
if ( ! F_54 ( & V_15 -> V_102 ) )
F_67 ( & V_15 -> V_103 ) ;
F_68 ( V_15 -> V_22 ) ;
F_27 ( V_15 -> V_20 ) ;
F_27 ( V_15 -> V_49 ) ;
V_15 -> V_65 = NULL ;
}
static int F_69 ( struct V_99 * V_65 , struct V_113 * V_113 ,
unsigned int V_60 , unsigned long V_114 )
{
struct V_14 * V_15 = F_49 ( V_65 ) ;
struct V_42 * V_22 ;
unsigned int V_115 , V_104 ;
if ( V_15 == NULL )
return - V_116 ;
V_22 = V_15 -> V_22 ;
switch ( V_60 ) {
case V_117 :
V_104 = F_70 ( ( void V_118 * ) V_114 , V_15 -> V_22 -> V_29 ,
strlen ( V_15 -> V_22 -> V_29 ) + 1 ) ? - V_119 : 0 ;
break;
case V_120 :
V_104 = F_71 ( 4 , ( int V_118 * ) V_114 ) ;
break;
case V_121 :
if ( F_72 ( V_115 , ( int V_118 * ) V_114 ) ) {
V_104 = - V_119 ;
break;
}
V_15 -> V_122 = V_115 ;
V_22 -> V_87 = V_48 ;
V_22 -> V_86 = V_123 +
V_124 + 3 ;
V_22 -> type = V_88 ;
V_104 = 0 ;
break;
case V_125 : {
char V_43 [ V_48 ] ;
if ( F_73 ( & V_43 ,
( void V_118 * ) V_114 , V_48 ) ) {
V_104 = - V_119 ;
break;
}
F_21 ( V_22 ) ;
memcpy ( V_22 -> V_46 , V_43 , V_48 ) ;
F_24 ( V_22 ) ;
V_104 = 0 ;
break;
}
default:
V_104 = - V_126 ;
}
F_53 ( V_15 ) ;
return V_104 ;
}
static long F_74 ( struct V_99 * V_65 , struct V_113 * V_113 ,
unsigned int V_60 , unsigned long V_114 )
{
switch ( V_60 ) {
case V_117 :
case V_120 :
case V_121 :
case V_125 :
return F_69 ( V_65 , V_113 , V_60 ,
( unsigned long ) F_75 ( V_114 ) ) ;
}
return - V_126 ;
}
static void F_76 ( struct V_99 * V_65 , const unsigned char * V_1 ,
char * V_127 , int V_18 )
{
struct V_14 * V_15 = F_49 ( V_65 ) ;
if ( ! V_15 )
return;
if ( V_15 -> V_52 != V_15 -> V_22 -> V_52 + 73 )
F_25 ( V_15 ) ;
while ( V_18 -- ) {
if ( V_127 != NULL && * V_127 ++ ) {
if ( ! F_77 ( V_38 , & V_15 -> V_37 ) )
V_15 -> V_22 -> V_23 . V_24 ++ ;
V_1 ++ ;
continue;
}
F_15 ( V_15 , * V_1 ++ ) ;
}
F_53 ( V_15 ) ;
F_78 ( V_65 ) ;
}
static void F_79 ( struct V_99 * V_65 )
{
struct V_14 * V_15 = F_49 ( V_65 ) ;
int V_59 ;
if ( ! V_15 )
return;
if ( V_15 -> V_54 <= 0 ) {
F_17 ( V_64 , & V_65 -> V_37 ) ;
F_80 ( V_15 -> V_22 ) ;
goto V_108;
}
V_59 = V_65 -> V_66 -> V_67 ( V_65 , V_15 -> V_55 , V_15 -> V_54 ) ;
V_15 -> V_54 -= V_59 ;
V_15 -> V_55 += V_59 ;
V_108:
F_53 ( V_15 ) ;
}
static int T_2 F_81 ( void )
{
int V_128 ;
F_10 ( V_129 ) ;
V_128 = F_82 ( V_130 , & V_131 ) ;
if ( V_128 != 0 )
F_10 ( V_132 , V_128 ) ;
return V_128 ;
}
static void T_3 F_83 ( void )
{
int V_133 ;
if ( ( V_133 = F_84 ( V_130 ) ) )
F_10 ( V_134 , V_133 ) ;
}
