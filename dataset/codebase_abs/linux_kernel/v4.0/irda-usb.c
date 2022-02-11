static void F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
int V_4 )
{
if ( V_2 -> V_5 & V_6 &&
( ( V_2 -> V_7 != - 1 ) || ( V_2 -> V_8 != - 1 ) ) ) {
if ( V_2 -> V_7 == - 1 )
V_2 -> V_7 = V_2 -> V_9 ;
if ( V_2 -> V_8 == - 1 )
V_2 -> V_8 = V_2 -> V_10 ;
}
if ( V_2 -> V_7 != - 1 ) {
if ( ( V_2 -> V_5 & V_11 ) &&
( ! V_4 ) && ( V_2 -> V_9 != - 1 ) ) {
F_2 ( L_1 , V_12 ) ;
* V_3 = 0 ;
return;
}
F_2 ( L_2 ,
V_12 , V_2 -> V_7 ) ;
V_2 -> V_9 = V_2 -> V_7 ;
switch ( V_2 -> V_9 ) {
case 2400 :
* V_3 = V_13 ;
break;
default:
case 9600 :
* V_3 = V_14 ;
break;
case 19200 :
* V_3 = V_15 ;
break;
case 38400 :
* V_3 = V_16 ;
break;
case 57600 :
* V_3 = V_17 ;
break;
case 115200 :
* V_3 = V_18 ;
break;
case 576000 :
* V_3 = V_19 ;
break;
case 1152000 :
* V_3 = V_20 ;
break;
case 4000000 :
* V_3 = V_21 ;
V_2 -> V_8 = 0 ;
break;
case 16000000 :
* V_3 = V_22 ;
V_2 -> V_8 = 0 ;
break;
}
} else
* V_3 = 0 ;
if ( V_2 -> V_8 != - 1 ) {
F_2 ( L_3 ,
V_12 , V_2 -> V_8 ) ;
V_2 -> V_10 = V_2 -> V_8 ;
switch ( V_2 -> V_10 ) {
case 48 :
* V_3 |= 0x10 ;
break;
case 28 :
case 24 :
* V_3 |= 0x20 ;
break;
default:
case 12 :
* V_3 |= 0x30 ;
break;
case 5 :
case 6 :
* V_3 |= 0x40 ;
break;
case 3 :
* V_3 |= 0x50 ;
break;
case 2 :
* V_3 |= 0x60 ;
break;
case 1 :
* V_3 |= 0x70 ;
break;
case 0 :
* V_3 |= 0x80 ;
break;
}
}
}
static T_1 F_3 ( struct V_23 * V_24 )
{
int V_25 = F_4 ( V_24 ) ;
if ( V_25 == 0 )
return 0 ;
else if ( V_25 <= 10 )
return 1 ;
else if ( V_25 <= 50 )
return 2 ;
else if ( V_25 <= 100 )
return 3 ;
else if ( V_25 <= 500 )
return 4 ;
else if ( V_25 <= 1000 )
return 5 ;
else if ( V_25 <= 5000 )
return 6 ;
else
return 7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 * V_26 ;
struct V_27 * V_27 ;
int V_28 ;
F_2 ( L_4 , V_12 ,
V_2 -> V_7 , V_2 -> V_8 ) ;
V_27 = V_2 -> V_29 ;
if ( V_27 -> V_30 != 0 ) {
F_6 ( L_5 , V_12 ) ;
return;
}
V_26 = V_2 -> V_31 ;
F_1 ( V_2 , V_26 , 1 ) ;
if ( V_2 -> V_5 & V_6 ) {
if ( V_26 [ 0 ] == 0 ) return ;
V_26 [ 1 ] = 0 ;
V_26 [ 2 ] = 0 ;
}
F_7 ( V_27 , V_2 -> V_32 ,
F_8 ( V_2 -> V_32 , V_2 -> V_33 ) ,
V_26 , V_34 ,
V_35 , V_2 ) ;
V_27 -> V_36 = V_2 -> V_37 ;
V_27 -> V_38 = 0 ;
if ( ( V_28 = F_9 ( V_27 , V_39 ) ) ) {
F_6 ( L_6 , V_12 ) ;
}
}
static void V_35 ( struct V_27 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_40 ;
F_10 (self != NULL, return;) ;
F_10 (urb == self->speed_urb, return;) ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( L_7 ,
V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
return;
}
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
F_11 ( V_2 -> V_41 ) ;
}
static T_2 F_12 ( struct V_23 * V_24 ,
struct V_42 * V_41 )
{
struct V_1 * V_2 = F_13 ( V_41 ) ;
struct V_27 * V_27 = V_2 -> V_43 ;
unsigned long V_44 ;
T_3 V_9 ;
T_4 V_10 ;
int V_45 , V_46 ;
F_2 ( L_8 , V_12 , V_41 -> V_47 ) ;
F_14 ( V_41 ) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ! V_2 -> V_49 ) {
F_2 ( L_9 , V_12 ) ;
goto V_50;
}
V_10 = F_16 ( V_24 ) ;
if ( ( V_10 != V_2 -> V_10 ) && ( V_10 != - 1 ) ) {
V_2 -> V_8 = V_10 ;
}
V_9 = F_17 ( V_24 ) ;
if ( ( V_9 != V_2 -> V_9 ) && ( V_9 != - 1 ) ) {
V_2 -> V_7 = V_9 ;
if ( ! V_24 -> V_51 ) {
F_5 ( V_2 ) ;
V_41 -> V_52 = V_53 ;
goto V_50;
}
}
if ( V_27 -> V_30 != 0 ) {
F_6 ( L_5 , V_12 ) ;
goto V_50;
}
F_18 ( V_24 , V_2 -> V_54 + V_2 -> V_37 , V_24 -> V_51 ) ;
if ( V_2 -> V_5 & V_6 ) {
T_1 V_25 ;
T_1 * V_26 = V_2 -> V_54 ;
V_25 = F_3 ( V_24 ) ;
F_1 ( V_2 , V_26 , 0 ) ;
V_26 [ 2 ] = V_25 ;
if ( ( V_24 -> V_51 != 0 ) &&
( ( V_24 -> V_51 % 128 ) == 0 ) &&
( ( V_24 -> V_51 % 512 ) != 0 ) ) {
V_26 [ 1 ] = 1 ;
F_19 ( V_24 , 1 ) ;
} else {
V_26 [ 1 ] = 0 ;
}
} else {
F_1 ( V_2 , V_2 -> V_54 , 0 ) ;
}
( (struct V_55 * ) V_24 -> V_56 ) -> V_40 = V_2 ;
F_7 ( V_27 , V_2 -> V_32 ,
F_8 ( V_2 -> V_32 , V_2 -> V_33 ) ,
V_2 -> V_54 , V_24 -> V_51 + V_2 -> V_37 ,
V_57 , V_24 ) ;
V_27 -> V_38 = V_58 ;
if ( V_2 -> V_5 & V_59 ) {
V_46 = F_4 ( V_24 ) ;
if ( V_46 ) {
int V_60 ;
V_60 = F_20 ( F_21 () , V_2 -> V_61 ) ;
#ifdef F_22
V_60 += F_22 ;
#endif
if ( V_46 > V_60 ) {
V_46 -= V_60 ;
if ( V_46 > 1000 )
F_23 ( V_46 / 1000 ) ;
else
F_24 ( V_46 ) ;
}
}
}
if ( ( V_45 = F_9 ( V_27 , V_39 ) ) ) {
F_6 ( L_10 , V_12 ) ;
V_41 -> V_62 . V_63 ++ ;
} else {
V_41 -> V_62 . V_64 ++ ;
V_41 -> V_62 . V_65 += V_24 -> V_51 ;
V_41 -> V_52 = V_53 ;
}
F_25 ( & V_2 -> V_48 , V_44 ) ;
return V_66 ;
V_50:
F_26 ( V_24 ) ;
F_25 ( & V_2 -> V_48 , V_44 ) ;
return V_66 ;
}
static void V_57 ( struct V_27 * V_27 )
{
unsigned long V_44 ;
struct V_23 * V_24 = V_27 -> V_40 ;
struct V_1 * V_2 = ( (struct V_55 * ) V_24 -> V_56 ) -> V_40 ;
F_10 (self != NULL, return;) ;
F_10 (urb == self->tx_urb, return;) ;
F_27 ( V_24 ) ;
V_27 -> V_40 = NULL ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( L_7 ,
V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
return;
}
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ( ! V_2 -> V_67 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( L_11 , V_12 ) ;
F_25 ( & V_2 -> V_48 , V_44 ) ;
return;
}
if ( ( V_2 -> V_7 != - 1 ) || ( V_2 -> V_8 != - 1 ) ) {
if ( ( V_2 -> V_7 != V_2 -> V_9 ) ||
( V_2 -> V_8 != V_2 -> V_10 ) ) {
F_2 ( L_12 , V_12 ) ;
F_5 ( V_2 ) ;
} else {
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
F_11 ( V_2 -> V_41 ) ;
}
} else {
F_11 ( V_2 -> V_41 ) ;
}
F_25 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_28 ( struct V_42 * V_41 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_13 ( V_41 ) ;
struct V_27 * V_27 ;
int V_68 = 0 ;
F_2 ( L_13 , V_12 ) ;
F_10 (self != NULL, return;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ! V_2 -> V_49 ) {
F_6 ( L_14 , V_12 ) ;
F_14 ( V_41 ) ;
F_25 ( & V_2 -> V_48 , V_44 ) ;
return;
}
V_27 = V_2 -> V_29 ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( L_15 ,
V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
switch ( V_27 -> V_30 ) {
case - V_69 :
F_29 ( V_27 ) ;
V_68 = 1 ;
break;
case - V_70 :
case - V_71 :
default:
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_68 = 1 ;
break;
}
}
V_27 = V_2 -> V_43 ;
if ( V_27 -> V_30 != 0 ) {
struct V_23 * V_24 = V_27 -> V_40 ;
F_2 ( L_16 ,
V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
V_41 -> V_62 . V_63 ++ ;
#ifdef F_30
if( V_2 -> V_7 == - 1 )
V_2 -> V_7 = V_2 -> V_9 ;
if( V_2 -> V_8 == - 1 )
V_2 -> V_8 = V_2 -> V_10 ;
F_5 ( V_2 ) ;
#endif
switch ( V_27 -> V_30 ) {
case - V_69 :
F_29 ( V_27 ) ;
V_68 = 1 ;
break;
case - V_70 :
case - V_71 :
default:
if( V_24 != NULL ) {
F_27 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_68 = 1 ;
break;
}
}
F_25 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_23 * V_24 , struct V_27 * V_27 )
{
struct V_55 * V_56 ;
int V_28 ;
F_10 (skb != NULL, return;) ;
F_10 (urb != NULL, return;) ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
V_56 -> V_40 = V_2 ;
F_7 ( V_27 , V_2 -> V_32 ,
F_32 ( V_2 -> V_32 , V_2 -> V_72 ) ,
V_24 -> V_73 , V_74 ,
V_75 , V_24 ) ;
V_27 -> V_30 = 0 ;
V_28 = F_9 ( V_27 , V_39 ) ;
if ( V_28 ) {
F_6 ( L_17 ,
V_12 , V_28 ) ;
}
}
static void V_75 ( struct V_27 * V_27 )
{
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_23 * V_76 ;
struct V_23 * V_77 ;
struct V_27 * V_78 ;
unsigned int V_51 , V_79 ;
F_2 ( L_18 , V_12 , V_27 -> V_80 ) ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_56 -> V_40 ;
F_10 (self != NULL, return;) ;
if ( ( ! V_2 -> V_67 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( L_19 , V_12 ) ;
return;
}
if ( V_27 -> V_30 != 0 ) {
switch ( V_27 -> V_30 ) {
case - V_81 :
V_2 -> V_41 -> V_62 . V_82 ++ ;
case - V_70 :
case - V_83 :
case - V_84 :
default:
V_2 -> V_41 -> V_62 . V_85 ++ ;
F_2 ( L_20 ,
V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
break;
}
V_2 -> V_86 . V_87 = V_88 ;
V_2 -> V_86 . V_73 = ( unsigned long ) V_27 ;
F_33 ( & V_2 -> V_86 , V_53 + ( 10 * V_89 / 1000 ) ) ;
return;
}
if ( V_27 -> V_80 <= V_2 -> V_37 ) {
F_6 ( L_21 , V_12 ) ;
goto V_68;
}
V_2 -> V_61 = F_21 () ;
V_79 = ( V_27 -> V_80 < V_90 ) ;
if ( V_2 -> V_5 & V_6 )
V_76 = F_34 ( V_79 ? V_27 -> V_80 :
V_74 +
V_91 ) ;
else
V_76 = F_34 ( V_79 ? V_27 -> V_80 :
V_74 ) ;
if ( ! V_76 ) {
V_2 -> V_41 -> V_62 . V_92 ++ ;
goto V_68;
}
if( V_79 ) {
F_18 ( V_24 , V_76 -> V_73 , V_27 -> V_80 ) ;
V_77 = V_76 ;
} else {
V_77 = V_24 ;
V_24 = V_76 ;
}
F_19 ( V_77 , V_27 -> V_80 ) ;
F_35 ( V_77 , V_2 -> V_37 ) ;
V_77 -> V_93 = V_2 -> V_41 ;
F_36 ( V_77 ) ;
V_77 -> V_94 = F_37 ( V_95 ) ;
V_51 = V_77 -> V_51 ;
F_38 ( V_77 ) ;
V_2 -> V_41 -> V_62 . V_96 += V_51 ;
V_2 -> V_41 -> V_62 . V_97 ++ ;
V_68:
V_78 = V_2 -> V_98 ;
V_27 -> V_40 = NULL ;
V_2 -> V_98 = V_27 ;
F_31 ( V_2 , V_24 , V_78 ) ;
}
static void V_88 ( unsigned long V_73 )
{
struct V_27 * V_27 = (struct V_27 * ) V_73 ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_27 * V_78 ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_56 -> V_40 ;
F_10 (self != NULL, return;) ;
V_78 = V_2 -> V_98 ;
V_27 -> V_40 = NULL ;
V_2 -> V_98 = V_27 ;
F_31 ( V_2 , V_24 , V_78 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
const unsigned char * V_99 ,
const unsigned int V_100 )
{
int V_28 = - V_101 ;
int V_102 = 0 ;
unsigned int V_103 ;
unsigned int V_104 = 0 ;
unsigned char * V_105 ;
V_105 = F_41 ( V_106 , V_107 ) ;
if ( V_105 == NULL )
return - V_101 ;
for ( V_103 = 0 ; V_103 < V_100 ; V_103 += V_104 ) {
V_104 = V_100 - V_103 ;
if ( V_104 > V_106 )
V_104 = V_106 ;
memcpy ( V_105 , V_99 + V_103 , V_104 ) ;
V_28 = F_42 ( V_2 -> V_32 ,
F_8 ( V_2 -> V_32 ,
V_2 -> V_33 ) ,
V_105 , V_104 ,
& V_102 , F_43 ( 500 ) ) ;
F_2 ( L_22 ,
V_12 , V_102 , V_28 ) ;
if ( V_28 < 0 )
break;
F_23 ( 10 ) ;
}
F_44 ( V_105 ) ;
return V_28 ;
}
static int F_45 ( struct V_1 * V_2 )
{
unsigned int V_103 ;
int V_28 ;
char V_108 [ 12 ] ;
const struct V_109 * V_110 ;
const unsigned char * V_111 ;
unsigned long V_112 = 0 ;
sprintf ( V_108 , L_23 ,
V_2 -> V_32 -> V_113 . V_114 ) ;
V_28 = F_46 ( & V_110 , V_108 , & V_2 -> V_32 -> V_93 ) ;
if ( V_28 < 0 )
return V_28 ;
F_47 ( L_24 ,
V_12 , V_108 , V_110 -> V_115 ) ;
V_28 = - V_116 ;
if ( ! memcmp ( V_110 -> V_73 , V_117 ,
sizeof( V_117 ) - 1 ) ) {
V_111 = V_110 -> V_73 +
sizeof( V_117 ) - 1 ;
if ( V_111 [ 3 ] == '.' &&
V_111 [ 7 ] == '.' ) {
unsigned long V_118 , V_119 , V_120 ;
V_118 = F_48 ( V_111 , NULL , 10 ) ;
V_119 = F_48 ( V_111 + 4 , NULL , 10 ) ;
V_120 = F_48 ( V_111 + 8 , NULL , 10 ) ;
V_112 = ( V_118 << 12 )
+ ( V_119 << 8 )
+ ( ( V_120 / 10 ) << 4 )
+ ( V_120 % 10 ) ;
F_2 ( L_25 ,
V_12 , V_112 ) ;
}
}
if ( V_2 -> V_32 -> V_113 . V_114 == F_49 ( V_112 ) ) {
for ( V_103 = 0 ; V_103 < V_110 -> V_115 && V_110 -> V_73 [ V_103 ] !=
V_121 ; V_103 ++ ) ;
if ( V_103 < V_122 && V_103 < V_110 -> V_115 &&
V_121 == V_110 -> V_73 [ V_103 ] ) {
if ( ! memcmp ( V_110 -> V_73 + V_103 + 1 , V_123 ,
sizeof( V_123 ) - 1 ) ) {
V_103 += sizeof( V_123 ) ;
V_28 = F_40 ( V_2 , & V_110 -> V_73 [ V_103 ] ,
V_110 -> V_115 - V_103 ) ;
}
}
}
F_50 ( V_110 ) ;
return V_28 ;
}
static int F_51 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
char V_124 [ 16 ] ;
int V_103 ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( ! V_2 -> V_49 ) {
F_25 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_14 , V_12 ) ;
return - 1 ;
}
if( V_2 -> V_125 ) {
F_25 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_26 , V_12 ) ;
return - V_126 ;
}
V_2 -> V_9 = - 1 ;
V_2 -> V_10 = - 1 ;
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
V_2 -> V_67 = 1 ;
F_25 ( & V_2 -> V_48 , V_44 ) ;
sprintf ( V_124 , L_27 , V_2 -> V_32 -> V_127 ) ;
V_2 -> V_128 = F_52 ( V_41 , & V_2 -> V_129 , V_124 ) ;
F_10 (self->irlap != NULL, return -1;) ;
F_53 ( V_41 ) ;
V_2 -> V_98 = V_2 -> V_130 [ V_131 ] ;
V_2 -> V_98 -> V_40 = NULL ;
for ( V_103 = 0 ; V_103 < V_131 ; V_103 ++ ) {
struct V_23 * V_24 = F_34 ( V_74 ) ;
if ( ! V_24 ) {
return - 1 ;
}
F_31 ( V_2 , V_24 , V_2 -> V_130 [ V_103 ] ) ;
}
return 0 ;
}
static int F_54 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
int V_103 ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
V_2 -> V_67 = 0 ;
F_14 ( V_41 ) ;
F_55 ( & V_2 -> V_86 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ ) {
struct V_27 * V_27 = V_2 -> V_130 [ V_103 ] ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
F_56 ( V_27 ) ;
if( V_24 ) {
F_26 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
}
F_56 ( V_2 -> V_43 ) ;
F_56 ( V_2 -> V_29 ) ;
if ( V_2 -> V_128 )
F_57 ( V_2 -> V_128 ) ;
V_2 -> V_128 = NULL ;
return 0 ;
}
static int F_58 ( struct V_42 * V_93 , struct V_133 * V_134 , int V_135 )
{
unsigned long V_44 ;
struct V_136 * V_137 = (struct V_136 * ) V_134 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
F_10 (dev != NULL, return -1;) ;
V_2 = F_13 ( V_93 ) ;
F_10 (self != NULL, return -1;) ;
F_2 ( L_28 , V_12 , V_93 -> V_47 , V_135 ) ;
switch ( V_135 ) {
case V_138 :
if ( ! F_59 ( V_139 ) )
return - V_140 ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( V_2 -> V_49 ) {
V_2 -> V_7 = V_137 -> V_141 ;
F_5 ( V_2 ) ;
}
F_25 ( & V_2 -> V_48 , V_44 ) ;
break;
case V_142 :
if ( ! F_59 ( V_139 ) )
return - V_140 ;
if( V_2 -> V_67 )
F_60 ( V_2 -> V_41 , TRUE ) ;
break;
case V_143 :
V_137 -> V_144 = F_39 ( V_2 ) ;
break;
default:
V_28 = - V_145 ;
}
return V_28 ;
}
static inline void F_61 ( struct V_1 * V_2 )
{
struct V_146 * V_147 ;
V_147 = V_2 -> V_148 ;
F_62 ( & V_2 -> V_129 ) ;
V_2 -> V_129 . V_149 . V_150 = F_63 ( V_147 -> V_151 ) ;
V_2 -> V_129 . V_152 . V_150 = V_147 -> V_153 ;
V_2 -> V_129 . V_154 . V_150 = V_147 -> V_155 ;
V_2 -> V_129 . V_156 . V_150 = V_147 -> V_157 ;
V_2 -> V_129 . V_158 . V_150 = V_147 -> V_159 ;
F_2 ( L_29 ,
V_12 , V_2 -> V_129 . V_149 . V_150 , V_2 -> V_129 . V_158 . V_150 ,
V_2 -> V_129 . V_156 . V_150 , V_2 -> V_129 . V_154 . V_150 ,
V_2 -> V_129 . V_152 . V_150 ) ;
if( V_2 -> V_5 & V_160 )
V_2 -> V_129 . V_149 . V_150 &= 0x00ff ;
if( V_2 -> V_5 & V_161 )
V_2 -> V_129 . V_158 . V_150 = 0x07 ;
if( V_2 -> V_5 & V_162 )
V_2 -> V_129 . V_156 . V_150 = 0x01 ;
if( V_2 -> V_5 & V_163 )
V_2 -> V_129 . V_156 . V_150 = 0x7f ;
if( V_2 -> V_5 & V_164 )
V_2 -> V_129 . V_154 . V_150 = 0x01 ;
#if 1
if ( V_165 )
V_2 -> V_129 . V_152 . V_150 = V_165 ;
#endif
F_64 ( & V_2 -> V_129 ) ;
}
static inline int F_65 ( struct V_1 * V_2 )
{
struct V_42 * V_41 = V_2 -> V_41 ;
V_41 -> V_166 = & V_167 ;
F_61 ( V_2 ) ;
return F_66 ( V_41 ) ;
}
static inline void F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_41 ) ;
F_44 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_44 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
static inline int F_69 ( struct V_1 * V_2 , struct V_168 * V_169 , int V_170 )
{
int V_103 ;
V_2 -> V_72 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_171 = 0 ;
for( V_103 = 0 ; V_103 < V_170 ; V_103 ++ ) {
T_1 V_172 ;
T_1 V_173 ;
T_1 V_174 ;
T_5 V_175 ;
V_172 = V_169 [ V_103 ] . V_147 . V_176 & V_177 ;
V_173 = V_169 [ V_103 ] . V_147 . V_176 & V_178 ;
V_174 = V_169 [ V_103 ] . V_147 . V_179 ;
V_175 = F_63 ( V_169 [ V_103 ] . V_147 . V_180 ) ;
if( V_174 == V_181 ) {
if( V_173 == V_182 ) {
V_2 -> V_72 = V_172 ;
} else {
V_2 -> V_33 = V_172 ;
V_2 -> V_183 = V_175 ;
}
} else {
if( ( V_174 == V_184 ) &&
( V_173 == V_182 ) ) {
V_2 -> V_171 = V_172 ;
} else {
F_70 ( L_30 ,
V_12 , V_172 ) ;
}
}
}
F_2 ( L_31 ,
V_12 , V_2 -> V_72 , V_2 -> V_33 ,
V_2 -> V_183 , V_2 -> V_171 ) ;
return ( V_2 -> V_72 != 0 ) && ( V_2 -> V_33 != 0 ) ;
}
static inline void F_71 ( struct V_146 * V_147 )
{
F_72 ( L_32 , V_147 -> V_185 ) ;
F_72 ( L_33 , V_147 -> V_186 ) ;
F_72 ( L_34 , F_63 ( V_147 -> V_187 ) ) ;
F_72 ( L_35 , V_147 -> V_159 ) ;
F_72 ( L_36 , V_147 -> V_157 ) ;
F_72 ( L_37 , V_147 -> V_153 ) ;
F_72 ( L_38 , F_63 ( V_147 -> V_151 ) ) ;
F_72 ( L_39 , V_147 -> V_155 ) ;
F_72 ( L_40 , V_147 -> V_188 ) ;
F_72 ( L_41 , V_147 -> V_189 ) ;
}
static inline struct V_146 * F_73 ( struct V_190 * V_191 )
{
struct V_192 * V_93 = F_74 ( V_191 ) ;
struct V_146 * V_147 ;
int V_28 ;
V_147 = F_41 ( sizeof( * V_147 ) , V_107 ) ;
if ( ! V_147 )
return NULL ;
V_28 = F_75 ( V_93 , F_76 ( V_93 , 0 ) ,
V_193 ,
V_182 | V_194 | V_195 ,
0 , V_191 -> V_196 -> V_147 . V_197 , V_147 ,
sizeof( * V_147 ) , 500 ) ;
F_2 ( L_42 , V_12 , V_28 ) ;
if ( V_28 < sizeof( * V_147 ) ) {
F_6 ( L_43 ,
V_28 < 0 ? L_44 : L_45 , V_28 ) ;
}
else if ( V_147 -> V_186 != V_198 ) {
F_6 ( L_46 ) ;
}
else {
#ifdef F_77
F_71 ( V_147 ) ;
#endif
return V_147 ;
}
F_44 ( V_147 ) ;
return NULL ;
}
static int F_78 ( struct V_190 * V_191 ,
const struct V_199 * V_200 )
{
struct V_42 * V_201 ;
struct V_192 * V_93 = F_74 ( V_191 ) ;
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_146 * V_148 ;
int V_28 = - V_101 ;
int V_103 ;
F_47 ( L_47 ,
V_93 -> V_127 , F_63 ( V_93 -> V_113 . V_204 ) ,
F_63 ( V_93 -> V_113 . V_205 ) ) ;
V_201 = F_79 ( sizeof( * V_2 ) ) ;
if ( ! V_201 )
goto V_206;
F_80 ( V_201 , & V_191 -> V_93 ) ;
V_2 = F_13 ( V_201 ) ;
V_2 -> V_41 = V_201 ;
F_81 ( & V_2 -> V_48 ) ;
F_82 ( & V_2 -> V_86 ) ;
V_2 -> V_5 = V_200 -> V_207 ;
V_2 -> V_125 = ( ( V_2 -> V_5 & V_6 ) != 0 ) ;
if ( V_2 -> V_5 & V_6 ) {
V_2 -> V_132 = V_208 ;
V_2 -> V_37 = V_91 ;
} else {
V_2 -> V_132 = V_209 ;
V_2 -> V_37 = V_210 ;
}
V_2 -> V_130 = F_83 ( V_2 -> V_132 , sizeof( struct V_27 * ) ,
V_107 ) ;
if ( ! V_2 -> V_130 )
goto V_211;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ ) {
V_2 -> V_130 [ V_103 ] = F_84 ( 0 , V_107 ) ;
if ( ! V_2 -> V_130 [ V_103 ] ) {
goto V_212;
}
}
V_2 -> V_43 = F_84 ( 0 , V_107 ) ;
if ( ! V_2 -> V_43 ) {
goto V_212;
}
V_2 -> V_29 = F_84 ( 0 , V_107 ) ;
if ( ! V_2 -> V_29 ) {
goto V_213;
}
if ( F_85 ( V_93 ) < 0 ) {
F_86 ( & V_191 -> V_93 , L_48 ) ;
V_28 = - V_126 ;
goto V_214;
}
V_28 = F_87 ( V_93 , V_191 -> V_196 -> V_147 . V_197 , 0 ) ;
F_2 ( L_49 ,
V_191 -> V_196 -> V_147 . V_197 , V_28 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_215 :
F_2 ( L_50 ,
V_12 ) ;
break;
default:
F_2 ( L_51 , V_12 , V_28 ) ;
V_28 = - V_126 ;
goto V_214;
}
V_203 = V_191 -> V_216 ;
if( ! F_69 ( V_2 , V_203 -> V_169 ,
V_203 -> V_147 . V_217 ) ) {
F_70 ( L_52 , V_12 ) ;
V_28 = - V_126 ;
goto V_214;
}
V_2 -> V_32 = V_93 ;
V_148 = F_73 ( V_191 ) ;
V_28 = - V_218 ;
if ( ! V_148 )
goto V_214;
if ( V_2 -> V_125 ) {
V_28 = F_75 ( V_2 -> V_32 , F_88 ( V_2 -> V_32 , 0 ) ,
0x02 , 0x40 , 0 , 0 , NULL , 0 , 500 ) ;
if ( V_28 < 0 ) {
F_2 ( L_53 , V_28 ) ;
goto V_214;
} else {
F_23 ( 10 ) ;
}
}
V_2 -> V_148 = V_148 ;
V_2 -> V_49 = 1 ;
V_2 -> V_67 = 0 ;
V_2 -> V_219 = V_191 ;
V_2 -> V_31 = F_41 ( V_34 , V_107 ) ;
if ( ! V_2 -> V_31 )
goto V_214;
V_2 -> V_54 = F_41 ( V_74 + V_2 -> V_37 ,
V_107 ) ;
if ( ! V_2 -> V_54 )
goto V_220;
V_28 = F_65 ( V_2 ) ;
if ( V_28 )
goto V_221;
F_47 ( L_54 , V_201 -> V_47 ) ;
F_89 ( V_191 , V_2 ) ;
if ( V_2 -> V_125 ) {
V_28 = F_45 ( V_2 ) ;
V_2 -> V_125 = ( V_28 < 0 ) ;
if ( V_2 -> V_125 ) {
F_70 ( L_55 ) ;
goto V_222;
}
V_148 = F_73 ( V_2 -> V_219 ) ;
if ( ! V_148 ) {
V_28 = - V_218 ;
goto V_222;
}
F_44 ( V_2 -> V_148 ) ;
V_2 -> V_148 = V_148 ;
F_61 ( V_2 ) ;
}
return 0 ;
V_222:
F_68 ( V_2 -> V_41 ) ;
V_221:
F_44 ( V_2 -> V_54 ) ;
V_220:
F_44 ( V_2 -> V_31 ) ;
V_214:
F_90 ( V_2 -> V_29 ) ;
V_213:
F_90 ( V_2 -> V_43 ) ;
V_212:
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ )
F_90 ( V_2 -> V_130 [ V_103 ] ) ;
F_44 ( V_2 -> V_130 ) ;
V_211:
F_91 ( V_201 ) ;
V_206:
return V_28 ;
}
static void F_92 ( struct V_190 * V_191 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_93 ( V_191 ) ;
int V_103 ;
F_89 ( V_191 , NULL ) ;
if ( ! V_2 )
return;
F_15 ( & V_2 -> V_48 , V_44 ) ;
V_2 -> V_49 = 0 ;
F_55 ( & V_2 -> V_86 ) ;
F_25 ( & V_2 -> V_48 , V_44 ) ;
if( ( V_2 -> V_67 ) || ( V_2 -> V_128 ) ) {
F_14 ( V_2 -> V_41 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ )
F_56 ( V_2 -> V_130 [ V_103 ] ) ;
F_56 ( V_2 -> V_43 ) ;
F_56 ( V_2 -> V_29 ) ;
}
F_67 ( V_2 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_219 = NULL ;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ )
F_90 ( V_2 -> V_130 [ V_103 ] ) ;
F_44 ( V_2 -> V_130 ) ;
F_90 ( V_2 -> V_43 ) ;
F_90 ( V_2 -> V_29 ) ;
F_91 ( V_2 -> V_41 ) ;
F_2 ( L_56 , V_12 ) ;
}
static int F_94 ( struct V_190 * V_191 , T_6 V_223 )
{
struct V_1 * V_2 = F_93 ( V_191 ) ;
int V_103 ;
F_95 ( V_2 -> V_41 ) ;
if ( V_2 -> V_43 != NULL )
F_56 ( V_2 -> V_43 ) ;
if ( V_2 -> V_29 != NULL )
F_56 ( V_2 -> V_29 ) ;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ ) {
if ( V_2 -> V_130 [ V_103 ] != NULL )
F_56 ( V_2 -> V_130 [ V_103 ] ) ;
}
return 0 ;
}
static int F_96 ( struct V_190 * V_191 )
{
struct V_1 * V_2 = F_93 ( V_191 ) ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_2 -> V_132 ; V_103 ++ ) {
if ( V_2 -> V_130 [ V_103 ] != NULL )
F_9 ( V_2 -> V_130 [ V_103 ] , V_107 ) ;
}
F_97 ( V_2 -> V_41 ) ;
return 0 ;
}
