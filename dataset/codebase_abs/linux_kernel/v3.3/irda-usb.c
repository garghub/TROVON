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
F_2 ( 2 , L_1 , V_12 ) ;
* V_3 = 0 ;
return;
}
F_2 ( 2 , L_2 , V_12 , V_2 -> V_7 ) ;
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
F_2 ( 2 , L_3 , V_12 , V_2 -> V_8 ) ;
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
F_2 ( 2 , L_4 , V_12 ,
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
F_2 ( 2 , L_7 , V_12 ) ;
F_10 (self != NULL, return;) ;
F_10 (urb == self->speed_urb, return;) ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( 0 , L_8 , V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
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
F_2 ( 4 , L_9 , V_12 , V_41 -> V_47 ) ;
F_14 ( V_41 ) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ! V_2 -> V_49 ) {
F_2 ( 0 , L_10 , V_12 ) ;
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
F_20 ( & V_2 -> V_61 ) ;
V_60 = V_2 -> V_61 . V_62 - V_2 -> V_63 . V_62 ;
#ifdef F_21
V_60 += F_21 ;
#endif
if ( V_60 < 0 )
V_60 += 1000000 ;
if ( V_46 > V_60 ) {
V_46 -= V_60 ;
if ( V_46 > 1000 )
F_22 ( V_46 / 1000 ) ;
else
F_23 ( V_46 ) ;
}
}
}
if ( ( V_45 = F_9 ( V_27 , V_39 ) ) ) {
F_6 ( L_11 , V_12 ) ;
V_41 -> V_64 . V_65 ++ ;
} else {
V_41 -> V_64 . V_66 ++ ;
V_41 -> V_64 . V_67 += V_24 -> V_51 ;
V_41 -> V_52 = V_53 ;
}
F_24 ( & V_2 -> V_48 , V_44 ) ;
return V_68 ;
V_50:
F_25 ( V_24 ) ;
F_24 ( & V_2 -> V_48 , V_44 ) ;
return V_68 ;
}
static void V_57 ( struct V_27 * V_27 )
{
unsigned long V_44 ;
struct V_23 * V_24 = V_27 -> V_40 ;
struct V_1 * V_2 = ( (struct V_55 * ) V_24 -> V_56 ) -> V_40 ;
F_2 ( 2 , L_7 , V_12 ) ;
F_10 (self != NULL, return;) ;
F_10 (urb == self->tx_urb, return;) ;
F_26 ( V_24 ) ;
V_27 -> V_40 = NULL ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( 0 , L_8 , V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
return;
}
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ( ! V_2 -> V_69 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( 0 , L_12 , V_12 ) ;
F_24 ( & V_2 -> V_48 , V_44 ) ;
return;
}
if ( ( V_2 -> V_7 != - 1 ) || ( V_2 -> V_8 != - 1 ) ) {
if ( ( V_2 -> V_7 != V_2 -> V_9 ) ||
( V_2 -> V_8 != V_2 -> V_10 ) ) {
F_2 ( 1 , L_13 , V_12 ) ;
F_5 ( V_2 ) ;
} else {
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
F_11 ( V_2 -> V_41 ) ;
}
} else {
F_11 ( V_2 -> V_41 ) ;
}
F_24 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_27 ( struct V_42 * V_41 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_13 ( V_41 ) ;
struct V_27 * V_27 ;
int V_70 = 0 ;
F_2 ( 0 , L_14 , V_12 ) ;
F_10 (self != NULL, return;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ! V_2 -> V_49 ) {
F_6 ( L_15 , V_12 ) ;
F_14 ( V_41 ) ;
F_24 ( & V_2 -> V_48 , V_44 ) ;
return;
}
V_27 = V_2 -> V_29 ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( 0 , L_16 , V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
switch ( V_27 -> V_30 ) {
case - V_71 :
F_28 ( V_27 ) ;
V_70 = 1 ;
break;
case - V_72 :
case - V_73 :
default:
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_70 = 1 ;
break;
}
}
V_27 = V_2 -> V_43 ;
if ( V_27 -> V_30 != 0 ) {
struct V_23 * V_24 = V_27 -> V_40 ;
F_2 ( 0 , L_17 , V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
V_41 -> V_64 . V_65 ++ ;
#ifdef F_29
if( V_2 -> V_7 == - 1 )
V_2 -> V_7 = V_2 -> V_9 ;
if( V_2 -> V_8 == - 1 )
V_2 -> V_8 = V_2 -> V_10 ;
F_5 ( V_2 ) ;
#endif
switch ( V_27 -> V_30 ) {
case - V_71 :
F_28 ( V_27 ) ;
V_70 = 1 ;
break;
case - V_72 :
case - V_73 :
default:
if( V_24 != NULL ) {
F_26 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_70 = 1 ;
break;
}
}
F_24 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_23 * V_24 , struct V_27 * V_27 )
{
struct V_55 * V_56 ;
int V_28 ;
F_2 ( 2 , L_7 , V_12 ) ;
F_10 (skb != NULL, return;) ;
F_10 (urb != NULL, return;) ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
V_56 -> V_40 = V_2 ;
F_7 ( V_27 , V_2 -> V_32 ,
F_31 ( V_2 -> V_32 , V_2 -> V_74 ) ,
V_24 -> V_75 , V_76 ,
V_77 , V_24 ) ;
V_27 -> V_30 = 0 ;
V_28 = F_9 ( V_27 , V_39 ) ;
if ( V_28 ) {
F_6 ( L_18 ,
V_12 , V_28 ) ;
}
}
static void V_77 ( struct V_27 * V_27 )
{
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_23 * V_78 ;
struct V_23 * V_79 ;
struct V_27 * V_80 ;
unsigned int V_51 , V_81 ;
F_2 ( 2 , L_19 , V_12 , V_27 -> V_82 ) ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_56 -> V_40 ;
F_10 (self != NULL, return;) ;
if ( ( ! V_2 -> V_69 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( 0 , L_20 , V_12 ) ;
return;
}
if ( V_27 -> V_30 != 0 ) {
switch ( V_27 -> V_30 ) {
case - V_83 :
V_2 -> V_41 -> V_64 . V_84 ++ ;
case - V_72 :
case - V_85 :
case - V_86 :
default:
V_2 -> V_41 -> V_64 . V_87 ++ ;
F_2 ( 0 , L_21 , V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
break;
}
V_2 -> V_88 . V_89 = V_90 ;
V_2 -> V_88 . V_75 = ( unsigned long ) V_27 ;
F_32 ( & V_2 -> V_88 , V_53 + ( 10 * V_91 / 1000 ) ) ;
return;
}
if ( V_27 -> V_82 <= V_2 -> V_37 ) {
F_6 ( L_22 , V_12 ) ;
goto V_70;
}
F_20 ( & V_2 -> V_63 ) ;
V_81 = ( V_27 -> V_82 < V_92 ) ;
if ( V_2 -> V_5 & V_6 )
V_78 = F_33 ( V_81 ? V_27 -> V_82 :
V_76 +
V_93 ) ;
else
V_78 = F_33 ( V_81 ? V_27 -> V_82 :
V_76 ) ;
if ( ! V_78 ) {
V_2 -> V_41 -> V_64 . V_94 ++ ;
goto V_70;
}
if( V_81 ) {
F_18 ( V_24 , V_78 -> V_75 , V_27 -> V_82 ) ;
V_79 = V_78 ;
} else {
V_79 = V_24 ;
V_24 = V_78 ;
}
F_19 ( V_79 , V_27 -> V_82 ) ;
F_34 ( V_79 , V_2 -> V_37 ) ;
V_79 -> V_95 = V_2 -> V_41 ;
F_35 ( V_79 ) ;
V_79 -> V_96 = F_36 ( V_97 ) ;
V_51 = V_79 -> V_51 ;
F_37 ( V_79 ) ;
V_2 -> V_41 -> V_64 . V_98 += V_51 ;
V_2 -> V_41 -> V_64 . V_99 ++ ;
V_70:
V_80 = V_2 -> V_100 ;
V_27 -> V_40 = NULL ;
V_2 -> V_100 = V_27 ;
F_30 ( V_2 , V_24 , V_80 ) ;
}
static void V_90 ( unsigned long V_75 )
{
struct V_27 * V_27 = (struct V_27 * ) V_75 ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_55 * V_56 ;
struct V_27 * V_80 ;
F_2 ( 2 , L_7 , V_12 ) ;
V_56 = (struct V_55 * ) V_24 -> V_56 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_56 -> V_40 ;
F_10 (self != NULL, return;) ;
V_80 = V_2 -> V_100 ;
V_27 -> V_40 = NULL ;
V_2 -> V_100 = V_27 ;
F_30 ( V_2 , V_24 , V_80 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
const unsigned char * V_101 ,
const unsigned int V_102 )
{
int V_28 = - V_103 ;
int V_104 = 0 ;
unsigned int V_105 ;
unsigned int V_106 = 0 ;
unsigned char * V_107 ;
V_107 = F_40 ( V_108 , V_109 ) ;
if ( V_107 == NULL )
return - V_103 ;
for ( V_105 = 0 ; V_105 < V_102 ; V_105 += V_106 ) {
V_106 = V_102 - V_105 ;
if ( V_106 > V_108 )
V_106 = V_108 ;
memcpy ( V_107 , V_101 + V_105 , V_106 ) ;
V_28 = F_41 ( V_2 -> V_32 ,
F_8 ( V_2 -> V_32 ,
V_2 -> V_33 ) ,
V_107 , V_106 ,
& V_104 , F_42 ( 500 ) ) ;
F_2 ( 3 , L_23 ,
V_12 , V_104 , V_28 ) ;
if ( V_28 < 0 )
break;
F_22 ( 10 ) ;
}
F_43 ( V_107 ) ;
return V_28 ;
}
static int F_44 ( struct V_1 * V_2 )
{
unsigned int V_105 ;
int V_28 ;
char V_110 [ 12 ] ;
const struct V_111 * V_112 ;
const unsigned char * V_113 ;
unsigned long V_114 = 0 ;
sprintf ( V_110 , L_24 ,
V_2 -> V_32 -> V_115 . V_116 ) ;
V_28 = F_45 ( & V_112 , V_110 , & V_2 -> V_32 -> V_95 ) ;
if ( V_28 < 0 )
return V_28 ;
F_46 ( L_25 ,
V_12 , V_110 , V_112 -> V_117 ) ;
V_28 = - V_118 ;
if ( ! memcmp ( V_112 -> V_75 , V_119 ,
sizeof( V_119 ) - 1 ) ) {
V_113 = V_112 -> V_75 +
sizeof( V_119 ) - 1 ;
if ( V_113 [ 3 ] == '.' &&
V_113 [ 7 ] == '.' ) {
unsigned long V_120 , V_121 , V_122 ;
V_120 = F_47 ( V_113 , NULL , 10 ) ;
V_121 = F_47 ( V_113 + 4 , NULL , 10 ) ;
V_122 = F_47 ( V_113 + 8 , NULL , 10 ) ;
V_114 = ( V_120 << 12 )
+ ( V_121 << 8 )
+ ( ( V_122 / 10 ) << 4 )
+ ( V_122 % 10 ) ;
F_2 ( 3 , L_26 ,
V_12 , V_114 ) ;
}
}
if ( V_2 -> V_32 -> V_115 . V_116 == F_48 ( V_114 ) ) {
for ( V_105 = 0 ; V_105 < V_112 -> V_117 && V_112 -> V_75 [ V_105 ] !=
V_123 ; V_105 ++ ) ;
if ( V_105 < V_124 && V_105 < V_112 -> V_117 &&
V_123 == V_112 -> V_75 [ V_105 ] ) {
if ( ! memcmp ( V_112 -> V_75 + V_105 + 1 , V_125 ,
sizeof( V_125 ) - 1 ) ) {
V_105 += sizeof( V_125 ) ;
V_28 = F_39 ( V_2 , & V_112 -> V_75 [ V_105 ] ,
V_112 -> V_117 - V_105 ) ;
}
}
}
F_49 ( V_112 ) ;
return V_28 ;
}
static int F_50 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
char V_126 [ 16 ] ;
int V_105 ;
F_2 ( 1 , L_7 , V_12 ) ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( ! V_2 -> V_49 ) {
F_24 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_15 , V_12 ) ;
return - 1 ;
}
if( V_2 -> V_127 ) {
F_24 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_27 , V_12 ) ;
return - V_128 ;
}
V_2 -> V_9 = - 1 ;
V_2 -> V_10 = - 1 ;
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
V_2 -> V_69 = 1 ;
F_24 ( & V_2 -> V_48 , V_44 ) ;
sprintf ( V_126 , L_28 , V_2 -> V_32 -> V_129 ) ;
V_2 -> V_130 = F_51 ( V_41 , & V_2 -> V_131 , V_126 ) ;
F_10 (self->irlap != NULL, return -1;) ;
F_52 ( V_41 ) ;
V_2 -> V_100 = V_2 -> V_132 [ V_133 ] ;
V_2 -> V_100 -> V_40 = NULL ;
for ( V_105 = 0 ; V_105 < V_133 ; V_105 ++ ) {
struct V_23 * V_24 = F_33 ( V_76 ) ;
if ( ! V_24 ) {
F_6 ( L_29 ,
V_12 ) ;
return - 1 ;
}
F_30 ( V_2 , V_24 , V_2 -> V_132 [ V_105 ] ) ;
}
return 0 ;
}
static int F_53 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
int V_105 ;
F_2 ( 1 , L_7 , V_12 ) ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
V_2 -> V_69 = 0 ;
F_14 ( V_41 ) ;
F_54 ( & V_2 -> V_88 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ ) {
struct V_27 * V_27 = V_2 -> V_132 [ V_105 ] ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
F_55 ( V_27 ) ;
if( V_24 ) {
F_25 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
}
F_55 ( V_2 -> V_43 ) ;
F_55 ( V_2 -> V_29 ) ;
if ( V_2 -> V_130 )
F_56 ( V_2 -> V_130 ) ;
V_2 -> V_130 = NULL ;
return 0 ;
}
static int F_57 ( struct V_42 * V_95 , struct V_135 * V_136 , int V_137 )
{
unsigned long V_44 ;
struct V_138 * V_139 = (struct V_138 * ) V_136 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
F_10 (dev != NULL, return -1;) ;
V_2 = F_13 ( V_95 ) ;
F_10 (self != NULL, return -1;) ;
F_2 ( 2 , L_30 , V_12 , V_95 -> V_47 , V_137 ) ;
switch ( V_137 ) {
case V_140 :
if ( ! F_58 ( V_141 ) )
return - V_142 ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( V_2 -> V_49 ) {
V_2 -> V_7 = V_139 -> V_143 ;
F_5 ( V_2 ) ;
}
F_24 ( & V_2 -> V_48 , V_44 ) ;
break;
case V_144 :
if ( ! F_58 ( V_141 ) )
return - V_142 ;
if( V_2 -> V_69 )
F_59 ( V_2 -> V_41 , TRUE ) ;
break;
case V_145 :
V_139 -> V_146 = F_38 ( V_2 ) ;
break;
default:
V_28 = - V_147 ;
}
return V_28 ;
}
static inline void F_60 ( struct V_1 * V_2 )
{
struct V_148 * V_149 ;
F_2 ( 3 , L_7 , V_12 ) ;
V_149 = V_2 -> V_150 ;
F_61 ( & V_2 -> V_131 ) ;
V_2 -> V_131 . V_151 . V_152 = F_62 ( V_149 -> V_153 ) ;
V_2 -> V_131 . V_154 . V_152 = V_149 -> V_155 ;
V_2 -> V_131 . V_156 . V_152 = V_149 -> V_157 ;
V_2 -> V_131 . V_158 . V_152 = V_149 -> V_159 ;
V_2 -> V_131 . V_160 . V_152 = V_149 -> V_161 ;
F_2 ( 0 , L_31 ,
V_12 , V_2 -> V_131 . V_151 . V_152 , V_2 -> V_131 . V_160 . V_152 , V_2 -> V_131 . V_158 . V_152 , V_2 -> V_131 . V_156 . V_152 , V_2 -> V_131 . V_154 . V_152 ) ;
if( V_2 -> V_5 & V_162 )
V_2 -> V_131 . V_151 . V_152 &= 0x00ff ;
if( V_2 -> V_5 & V_163 )
V_2 -> V_131 . V_160 . V_152 = 0x07 ;
if( V_2 -> V_5 & V_164 )
V_2 -> V_131 . V_158 . V_152 = 0x01 ;
if( V_2 -> V_5 & V_165 )
V_2 -> V_131 . V_158 . V_152 = 0x7f ;
if( V_2 -> V_5 & V_166 )
V_2 -> V_131 . V_156 . V_152 = 0x01 ;
#if 1
if ( V_167 )
V_2 -> V_131 . V_154 . V_152 = V_167 ;
#endif
F_63 ( & V_2 -> V_131 ) ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
struct V_42 * V_41 = V_2 -> V_41 ;
F_2 ( 1 , L_7 , V_12 ) ;
V_41 -> V_168 = & V_169 ;
F_60 ( V_2 ) ;
return F_65 ( V_41 ) ;
}
static inline void F_66 ( struct V_1 * V_2 )
{
F_2 ( 1 , L_7 , V_12 ) ;
F_67 ( V_2 -> V_41 ) ;
F_43 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_43 ( V_2 -> V_54 ) ;
V_2 -> V_54 = NULL ;
}
static inline int F_68 ( struct V_1 * V_2 , struct V_170 * V_171 , int V_172 )
{
int V_105 ;
V_2 -> V_74 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_173 = 0 ;
for( V_105 = 0 ; V_105 < V_172 ; V_105 ++ ) {
T_1 V_174 ;
T_1 V_175 ;
T_1 V_176 ;
T_5 V_177 ;
V_174 = V_171 [ V_105 ] . V_149 . V_178 & V_179 ;
V_175 = V_171 [ V_105 ] . V_149 . V_178 & V_180 ;
V_176 = V_171 [ V_105 ] . V_149 . V_181 ;
V_177 = F_62 ( V_171 [ V_105 ] . V_149 . V_182 ) ;
if( V_176 == V_183 ) {
if( V_175 == V_184 ) {
V_2 -> V_74 = V_174 ;
} else {
V_2 -> V_33 = V_174 ;
V_2 -> V_185 = V_177 ;
}
} else {
if( ( V_176 == V_186 ) &&
( V_175 == V_184 ) ) {
V_2 -> V_173 = V_174 ;
} else {
F_69 ( L_32 , V_12 , V_174 ) ;
}
}
}
F_2 ( 0 , L_33 ,
V_12 , V_2 -> V_74 , V_2 -> V_33 , V_2 -> V_185 , V_2 -> V_173 ) ;
return ( V_2 -> V_74 != 0 ) && ( V_2 -> V_33 != 0 ) ;
}
static inline void F_70 ( struct V_148 * V_149 )
{
F_71 ( L_34 , V_149 -> V_187 ) ;
F_71 ( L_35 , V_149 -> V_188 ) ;
F_71 ( L_36 , F_62 ( V_149 -> V_189 ) ) ;
F_71 ( L_37 , V_149 -> V_161 ) ;
F_71 ( L_38 , V_149 -> V_159 ) ;
F_71 ( L_39 , V_149 -> V_155 ) ;
F_71 ( L_40 , F_62 ( V_149 -> V_153 ) ) ;
F_71 ( L_41 , V_149 -> V_157 ) ;
F_71 ( L_42 , V_149 -> V_190 ) ;
F_71 ( L_43 , V_149 -> V_191 ) ;
}
static inline struct V_148 * F_72 ( struct V_192 * V_193 )
{
struct V_194 * V_95 = F_73 ( V_193 ) ;
struct V_148 * V_149 ;
int V_28 ;
V_149 = F_40 ( sizeof( * V_149 ) , V_109 ) ;
if ( ! V_149 )
return NULL ;
V_28 = F_74 ( V_95 , F_75 ( V_95 , 0 ) ,
V_195 ,
V_184 | V_196 | V_197 ,
0 , V_193 -> V_198 -> V_149 . V_199 , V_149 ,
sizeof( * V_149 ) , 500 ) ;
F_2 ( 1 , L_44 , V_12 , V_28 ) ;
if ( V_28 < sizeof( * V_149 ) ) {
F_6 ( L_45 ,
( V_28 < 0 ) ? L_46 : L_47 , V_28 ) ;
}
else if ( V_149 -> V_188 != V_200 ) {
F_6 ( L_48 ) ;
}
else {
#ifdef F_76
F_70 ( V_149 ) ;
#endif
return V_149 ;
}
F_43 ( V_149 ) ;
return NULL ;
}
static int F_77 ( struct V_192 * V_193 ,
const struct V_201 * V_202 )
{
struct V_42 * V_203 ;
struct V_194 * V_95 = F_73 ( V_193 ) ;
struct V_1 * V_2 ;
struct V_204 * V_205 ;
struct V_148 * V_150 ;
int V_28 = - V_103 ;
int V_105 ;
F_46 ( L_49 ,
V_95 -> V_129 , F_62 ( V_95 -> V_115 . V_206 ) ,
F_62 ( V_95 -> V_115 . V_207 ) ) ;
V_203 = F_78 ( sizeof( * V_2 ) ) ;
if ( ! V_203 )
goto V_208;
F_79 ( V_203 , & V_193 -> V_95 ) ;
V_2 = F_13 ( V_203 ) ;
V_2 -> V_41 = V_203 ;
F_80 ( & V_2 -> V_48 ) ;
F_81 ( & V_2 -> V_88 ) ;
V_2 -> V_5 = V_202 -> V_209 ;
V_2 -> V_127 = ( ( V_2 -> V_5 & V_6 ) != 0 ) ;
if ( V_2 -> V_5 & V_6 ) {
V_2 -> V_134 = V_210 ;
V_2 -> V_37 = V_93 ;
} else {
V_2 -> V_134 = V_211 ;
V_2 -> V_37 = V_212 ;
}
V_2 -> V_132 = F_82 ( V_2 -> V_134 , sizeof( struct V_27 * ) ,
V_109 ) ;
if ( ! V_2 -> V_132 )
goto V_213;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ ) {
V_2 -> V_132 [ V_105 ] = F_83 ( 0 , V_109 ) ;
if ( ! V_2 -> V_132 [ V_105 ] ) {
goto V_214;
}
}
V_2 -> V_43 = F_83 ( 0 , V_109 ) ;
if ( ! V_2 -> V_43 ) {
goto V_214;
}
V_2 -> V_29 = F_83 ( 0 , V_109 ) ;
if ( ! V_2 -> V_29 ) {
goto V_215;
}
if ( F_84 ( V_95 ) < 0 ) {
F_85 ( L_50 ) ;
V_28 = - V_128 ;
goto V_216;
}
V_28 = F_86 ( V_95 , V_193 -> V_198 -> V_149 . V_199 , 0 ) ;
F_2 ( 1 , L_51 , V_193 -> V_198 -> V_149 . V_199 , V_28 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_217 :
F_2 ( 0 , L_52 , V_12 ) ;
break;
default:
F_2 ( 0 , L_53 , V_12 , V_28 ) ;
V_28 = - V_128 ;
goto V_216;
}
V_205 = V_193 -> V_218 ;
if( ! F_68 ( V_2 , V_205 -> V_171 ,
V_205 -> V_149 . V_219 ) ) {
F_69 ( L_54 , V_12 ) ;
V_28 = - V_128 ;
goto V_216;
}
V_2 -> V_32 = V_95 ;
V_150 = F_72 ( V_193 ) ;
V_28 = - V_220 ;
if ( ! V_150 )
goto V_216;
if ( V_2 -> V_127 ) {
V_28 = F_74 ( V_2 -> V_32 , F_87 ( V_2 -> V_32 , 0 ) ,
0x02 , 0x40 , 0 , 0 , NULL , 0 , 500 ) ;
if ( V_28 < 0 ) {
F_2 ( 0 , L_55 , V_28 ) ;
goto V_216;
} else {
F_22 ( 10 ) ;
}
}
V_2 -> V_150 = V_150 ;
V_2 -> V_49 = 1 ;
V_2 -> V_69 = 0 ;
V_2 -> V_221 = V_193 ;
V_2 -> V_31 = F_40 ( V_34 , V_109 ) ;
if ( ! V_2 -> V_31 )
goto V_216;
V_2 -> V_54 = F_40 ( V_76 + V_2 -> V_37 ,
V_109 ) ;
if ( ! V_2 -> V_54 )
goto V_222;
V_28 = F_64 ( V_2 ) ;
if ( V_28 )
goto V_223;
F_46 ( L_56 , V_203 -> V_47 ) ;
F_88 ( V_193 , V_2 ) ;
if ( V_2 -> V_127 ) {
V_28 = F_44 ( V_2 ) ;
V_2 -> V_127 = ( V_28 < 0 ) ;
if ( V_2 -> V_127 ) {
F_69 ( L_57 ) ;
goto V_224;
}
V_150 = F_72 ( V_2 -> V_221 ) ;
if ( ! V_150 ) {
V_28 = - V_220 ;
goto V_224;
}
F_43 ( V_2 -> V_150 ) ;
V_2 -> V_150 = V_150 ;
F_60 ( V_2 ) ;
}
return 0 ;
V_224:
F_67 ( V_2 -> V_41 ) ;
V_223:
F_43 ( V_2 -> V_54 ) ;
V_222:
F_43 ( V_2 -> V_31 ) ;
V_216:
F_89 ( V_2 -> V_29 ) ;
V_215:
F_89 ( V_2 -> V_43 ) ;
V_214:
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ )
F_89 ( V_2 -> V_132 [ V_105 ] ) ;
F_43 ( V_2 -> V_132 ) ;
V_213:
F_90 ( V_203 ) ;
V_208:
return V_28 ;
}
static void F_91 ( struct V_192 * V_193 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_92 ( V_193 ) ;
int V_105 ;
F_2 ( 1 , L_7 , V_12 ) ;
F_88 ( V_193 , NULL ) ;
if ( ! V_2 )
return;
F_15 ( & V_2 -> V_48 , V_44 ) ;
V_2 -> V_49 = 0 ;
F_54 ( & V_2 -> V_88 ) ;
F_24 ( & V_2 -> V_48 , V_44 ) ;
if( ( V_2 -> V_69 ) || ( V_2 -> V_130 ) ) {
F_14 ( V_2 -> V_41 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ )
F_55 ( V_2 -> V_132 [ V_105 ] ) ;
F_55 ( V_2 -> V_43 ) ;
F_55 ( V_2 -> V_29 ) ;
}
F_66 ( V_2 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_221 = NULL ;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ )
F_89 ( V_2 -> V_132 [ V_105 ] ) ;
F_43 ( V_2 -> V_132 ) ;
F_89 ( V_2 -> V_43 ) ;
F_89 ( V_2 -> V_29 ) ;
F_90 ( V_2 -> V_41 ) ;
F_2 ( 0 , L_58 , V_12 ) ;
}
static int F_93 ( struct V_192 * V_193 , T_6 V_225 )
{
struct V_1 * V_2 = F_92 ( V_193 ) ;
int V_105 ;
F_94 ( V_2 -> V_41 ) ;
if ( V_2 -> V_43 != NULL )
F_55 ( V_2 -> V_43 ) ;
if ( V_2 -> V_29 != NULL )
F_55 ( V_2 -> V_29 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ ) {
if ( V_2 -> V_132 [ V_105 ] != NULL )
F_55 ( V_2 -> V_132 [ V_105 ] ) ;
}
return 0 ;
}
static int F_95 ( struct V_192 * V_193 )
{
struct V_1 * V_2 = F_92 ( V_193 ) ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_2 -> V_134 ; V_105 ++ ) {
if ( V_2 -> V_132 [ V_105 ] != NULL )
F_9 ( V_2 -> V_132 [ V_105 ] , V_109 ) ;
}
F_96 ( V_2 -> V_41 ) ;
return 0 ;
}
