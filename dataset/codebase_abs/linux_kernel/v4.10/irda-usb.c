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
F_18 ( V_41 ) ;
goto V_50;
}
}
if ( V_27 -> V_30 != 0 ) {
F_6 ( L_5 , V_12 ) ;
goto V_50;
}
F_19 ( V_24 , V_2 -> V_52 + V_2 -> V_37 , V_24 -> V_51 ) ;
if ( V_2 -> V_5 & V_6 ) {
T_1 V_25 ;
T_1 * V_26 = V_2 -> V_52 ;
V_25 = F_3 ( V_24 ) ;
F_1 ( V_2 , V_26 , 0 ) ;
V_26 [ 2 ] = V_25 ;
if ( ( V_24 -> V_51 != 0 ) &&
( ( V_24 -> V_51 % 128 ) == 0 ) &&
( ( V_24 -> V_51 % 512 ) != 0 ) ) {
V_26 [ 1 ] = 1 ;
F_20 ( V_24 , 1 ) ;
} else {
V_26 [ 1 ] = 0 ;
}
} else {
F_1 ( V_2 , V_2 -> V_52 , 0 ) ;
}
( (struct V_53 * ) V_24 -> V_54 ) -> V_40 = V_2 ;
F_7 ( V_27 , V_2 -> V_32 ,
F_8 ( V_2 -> V_32 , V_2 -> V_33 ) ,
V_2 -> V_52 , V_24 -> V_51 + V_2 -> V_37 ,
V_55 , V_24 ) ;
V_27 -> V_38 = V_56 ;
if ( V_2 -> V_5 & V_57 ) {
V_46 = F_4 ( V_24 ) ;
if ( V_46 ) {
int V_58 ;
V_58 = F_21 ( F_22 () , V_2 -> V_59 ) ;
#ifdef F_23
V_58 += F_23 ;
#endif
if ( V_46 > V_58 ) {
V_46 -= V_58 ;
if ( V_46 > 1000 )
F_24 ( V_46 / 1000 ) ;
else
F_25 ( V_46 ) ;
}
}
}
if ( ( V_45 = F_9 ( V_27 , V_39 ) ) ) {
F_6 ( L_10 , V_12 ) ;
V_41 -> V_60 . V_61 ++ ;
} else {
V_41 -> V_60 . V_62 ++ ;
V_41 -> V_60 . V_63 += V_24 -> V_51 ;
F_18 ( V_41 ) ;
}
F_26 ( & V_2 -> V_48 , V_44 ) ;
return V_64 ;
V_50:
F_27 ( V_24 ) ;
F_26 ( & V_2 -> V_48 , V_44 ) ;
return V_64 ;
}
static void V_55 ( struct V_27 * V_27 )
{
unsigned long V_44 ;
struct V_23 * V_24 = V_27 -> V_40 ;
struct V_1 * V_2 = ( (struct V_53 * ) V_24 -> V_54 ) -> V_40 ;
F_10 (self != NULL, return;) ;
F_10 (urb == self->tx_urb, return;) ;
F_28 ( V_24 ) ;
V_27 -> V_40 = NULL ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( L_7 ,
V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
return;
}
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ( ! V_2 -> V_65 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( L_11 , V_12 ) ;
F_26 ( & V_2 -> V_48 , V_44 ) ;
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
F_26 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_29 ( struct V_42 * V_41 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_13 ( V_41 ) ;
struct V_27 * V_27 ;
int V_66 = 0 ;
F_2 ( L_13 , V_12 ) ;
F_10 (self != NULL, return;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if ( ! V_2 -> V_49 ) {
F_6 ( L_14 , V_12 ) ;
F_14 ( V_41 ) ;
F_26 ( & V_2 -> V_48 , V_44 ) ;
return;
}
V_27 = V_2 -> V_29 ;
if ( V_27 -> V_30 != 0 ) {
F_2 ( L_15 ,
V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
switch ( V_27 -> V_30 ) {
case - V_67 :
F_30 ( V_27 ) ;
V_66 = 1 ;
break;
case - V_68 :
case - V_69 :
default:
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_66 = 1 ;
break;
}
}
V_27 = V_2 -> V_43 ;
if ( V_27 -> V_30 != 0 ) {
struct V_23 * V_24 = V_27 -> V_40 ;
F_2 ( L_16 ,
V_41 -> V_47 , V_27 -> V_30 , V_27 -> V_38 ) ;
V_41 -> V_60 . V_61 ++ ;
#ifdef F_31
if( V_2 -> V_7 == - 1 )
V_2 -> V_7 = V_2 -> V_9 ;
if( V_2 -> V_8 == - 1 )
V_2 -> V_8 = V_2 -> V_10 ;
F_5 ( V_2 ) ;
#endif
switch ( V_27 -> V_30 ) {
case - V_67 :
F_30 ( V_27 ) ;
V_66 = 1 ;
break;
case - V_68 :
case - V_69 :
default:
if( V_24 != NULL ) {
F_28 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
V_27 -> V_30 = 0 ;
F_11 ( V_2 -> V_41 ) ;
V_66 = 1 ;
break;
}
}
F_26 ( & V_2 -> V_48 , V_44 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_23 * V_24 , struct V_27 * V_27 )
{
struct V_53 * V_54 ;
int V_28 ;
F_10 (skb != NULL, return;) ;
F_10 (urb != NULL, return;) ;
V_54 = (struct V_53 * ) V_24 -> V_54 ;
V_54 -> V_40 = V_2 ;
F_7 ( V_27 , V_2 -> V_32 ,
F_33 ( V_2 -> V_32 , V_2 -> V_70 ) ,
V_24 -> V_71 , V_72 ,
V_73 , V_24 ) ;
V_27 -> V_30 = 0 ;
V_28 = F_9 ( V_27 , V_39 ) ;
if ( V_28 ) {
F_6 ( L_17 ,
V_12 , V_28 ) ;
}
}
static void V_73 ( struct V_27 * V_27 )
{
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_23 * V_74 ;
struct V_23 * V_75 ;
struct V_27 * V_76 ;
unsigned int V_51 , V_77 ;
F_2 ( L_18 , V_12 , V_27 -> V_78 ) ;
V_54 = (struct V_53 * ) V_24 -> V_54 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_54 -> V_40 ;
F_10 (self != NULL, return;) ;
if ( ( ! V_2 -> V_65 ) || ( ! V_2 -> V_49 ) ) {
F_2 ( L_19 , V_12 ) ;
return;
}
if ( V_27 -> V_30 != 0 ) {
switch ( V_27 -> V_30 ) {
case - V_79 :
V_2 -> V_41 -> V_60 . V_80 ++ ;
case - V_68 :
case - V_81 :
case - V_82 :
default:
V_2 -> V_41 -> V_60 . V_83 ++ ;
F_2 ( L_20 ,
V_12 , V_27 -> V_30 , V_27 -> V_38 ) ;
break;
}
V_2 -> V_84 . V_85 = V_86 ;
V_2 -> V_84 . V_71 = ( unsigned long ) V_27 ;
F_34 ( & V_2 -> V_84 ,
V_87 + F_35 ( 10 ) ) ;
return;
}
if ( V_27 -> V_78 <= V_2 -> V_37 ) {
F_6 ( L_21 , V_12 ) ;
goto V_66;
}
V_2 -> V_59 = F_22 () ;
V_77 = ( V_27 -> V_78 < V_88 ) ;
if ( V_2 -> V_5 & V_6 )
V_74 = F_36 ( V_77 ? V_27 -> V_78 :
V_72 +
V_89 ) ;
else
V_74 = F_36 ( V_77 ? V_27 -> V_78 :
V_72 ) ;
if ( ! V_74 ) {
V_2 -> V_41 -> V_60 . V_90 ++ ;
goto V_66;
}
if( V_77 ) {
F_19 ( V_24 , V_74 -> V_71 , V_27 -> V_78 ) ;
V_75 = V_74 ;
} else {
V_75 = V_24 ;
V_24 = V_74 ;
}
F_20 ( V_75 , V_27 -> V_78 ) ;
F_37 ( V_75 , V_2 -> V_37 ) ;
V_75 -> V_91 = V_2 -> V_41 ;
F_38 ( V_75 ) ;
V_75 -> V_92 = F_39 ( V_93 ) ;
V_51 = V_75 -> V_51 ;
F_40 ( V_75 ) ;
V_2 -> V_41 -> V_60 . V_94 += V_51 ;
V_2 -> V_41 -> V_60 . V_95 ++ ;
V_66:
V_76 = V_2 -> V_96 ;
V_27 -> V_40 = NULL ;
V_2 -> V_96 = V_27 ;
F_32 ( V_2 , V_24 , V_76 ) ;
}
static void V_86 ( unsigned long V_71 )
{
struct V_27 * V_27 = (struct V_27 * ) V_71 ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_27 * V_76 ;
V_54 = (struct V_53 * ) V_24 -> V_54 ;
F_10 (cb != NULL, return;) ;
V_2 = (struct V_1 * ) V_54 -> V_40 ;
F_10 (self != NULL, return;) ;
V_76 = V_2 -> V_96 ;
V_27 -> V_40 = NULL ;
V_2 -> V_96 = V_27 ;
F_32 ( V_2 , V_24 , V_76 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const unsigned char * V_97 ,
const unsigned int V_98 )
{
int V_28 = - V_99 ;
int V_100 = 0 ;
unsigned int V_101 ;
unsigned int V_102 = 0 ;
unsigned char * V_103 ;
V_103 = F_43 ( V_104 , V_105 ) ;
if ( V_103 == NULL )
return - V_99 ;
for ( V_101 = 0 ; V_101 < V_98 ; V_101 += V_102 ) {
V_102 = V_98 - V_101 ;
if ( V_102 > V_104 )
V_102 = V_104 ;
memcpy ( V_103 , V_97 + V_101 , V_102 ) ;
V_28 = F_44 ( V_2 -> V_32 ,
F_8 ( V_2 -> V_32 ,
V_2 -> V_33 ) ,
V_103 , V_102 ,
& V_100 , F_35 ( 500 ) ) ;
F_2 ( L_22 ,
V_12 , V_100 , V_28 ) ;
if ( V_28 < 0 )
break;
F_24 ( 10 ) ;
}
F_45 ( V_103 ) ;
return V_28 ;
}
static int F_46 ( struct V_1 * V_2 )
{
unsigned int V_101 ;
int V_28 ;
char V_106 [ 12 ] ;
const struct V_107 * V_108 ;
const unsigned char * V_109 ;
unsigned long V_110 = 0 ;
sprintf ( V_106 , L_23 ,
V_2 -> V_32 -> V_111 . V_112 ) ;
V_28 = F_47 ( & V_108 , V_106 , & V_2 -> V_32 -> V_91 ) ;
if ( V_28 < 0 )
return V_28 ;
F_48 ( L_24 ,
V_12 , V_106 , V_108 -> V_113 ) ;
V_28 = - V_114 ;
if ( ! memcmp ( V_108 -> V_71 , V_115 ,
sizeof( V_115 ) - 1 ) ) {
V_109 = V_108 -> V_71 +
sizeof( V_115 ) - 1 ;
if ( V_109 [ 3 ] == '.' &&
V_109 [ 7 ] == '.' ) {
unsigned long V_116 , V_117 , V_118 ;
V_116 = F_49 ( V_109 , NULL , 10 ) ;
V_117 = F_49 ( V_109 + 4 , NULL , 10 ) ;
V_118 = F_49 ( V_109 + 8 , NULL , 10 ) ;
V_110 = ( V_116 << 12 )
+ ( V_117 << 8 )
+ ( ( V_118 / 10 ) << 4 )
+ ( V_118 % 10 ) ;
F_2 ( L_25 ,
V_12 , V_110 ) ;
}
}
if ( V_2 -> V_32 -> V_111 . V_112 == F_50 ( V_110 ) ) {
for ( V_101 = 0 ; V_101 < V_108 -> V_113 && V_108 -> V_71 [ V_101 ] !=
V_119 ; V_101 ++ ) ;
if ( V_101 < V_120 && V_101 < V_108 -> V_113 &&
V_119 == V_108 -> V_71 [ V_101 ] ) {
if ( ! memcmp ( V_108 -> V_71 + V_101 + 1 , V_121 ,
sizeof( V_121 ) - 1 ) ) {
V_101 += sizeof( V_121 ) ;
V_28 = F_42 ( V_2 , & V_108 -> V_71 [ V_101 ] ,
V_108 -> V_113 - V_101 ) ;
}
}
}
F_51 ( V_108 ) ;
return V_28 ;
}
static int F_52 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
char V_122 [ 16 ] ;
int V_101 ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( ! V_2 -> V_49 ) {
F_26 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_14 , V_12 ) ;
return - 1 ;
}
if( V_2 -> V_123 ) {
F_26 ( & V_2 -> V_48 , V_44 ) ;
F_6 ( L_26 , V_12 ) ;
return - V_124 ;
}
V_2 -> V_9 = - 1 ;
V_2 -> V_10 = - 1 ;
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
V_2 -> V_65 = 1 ;
F_26 ( & V_2 -> V_48 , V_44 ) ;
sprintf ( V_122 , L_27 , V_2 -> V_32 -> V_125 ) ;
V_2 -> V_126 = F_53 ( V_41 , & V_2 -> V_127 , V_122 ) ;
F_10 (self->irlap != NULL, return -1;) ;
F_54 ( V_41 ) ;
V_2 -> V_96 = V_2 -> V_128 [ V_129 ] ;
V_2 -> V_96 -> V_40 = NULL ;
for ( V_101 = 0 ; V_101 < V_129 ; V_101 ++ ) {
struct V_23 * V_24 = F_36 ( V_72 ) ;
if ( ! V_24 ) {
return - 1 ;
}
F_32 ( V_2 , V_24 , V_2 -> V_128 [ V_101 ] ) ;
}
return 0 ;
}
static int F_55 ( struct V_42 * V_41 )
{
struct V_1 * V_2 ;
int V_101 ;
F_10 (netdev != NULL, return -1;) ;
V_2 = F_13 ( V_41 ) ;
F_10 (self != NULL, return -1;) ;
V_2 -> V_65 = 0 ;
F_14 ( V_41 ) ;
F_56 ( & V_2 -> V_84 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ ) {
struct V_27 * V_27 = V_2 -> V_128 [ V_101 ] ;
struct V_23 * V_24 = (struct V_23 * ) V_27 -> V_40 ;
F_57 ( V_27 ) ;
if( V_24 ) {
F_27 ( V_24 ) ;
V_27 -> V_40 = NULL ;
}
}
F_57 ( V_2 -> V_43 ) ;
F_57 ( V_2 -> V_29 ) ;
if ( V_2 -> V_126 )
F_58 ( V_2 -> V_126 ) ;
V_2 -> V_126 = NULL ;
return 0 ;
}
static int F_59 ( struct V_42 * V_91 , struct V_131 * V_132 , int V_133 )
{
unsigned long V_44 ;
struct V_134 * V_135 = (struct V_134 * ) V_132 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
F_10 (dev != NULL, return -1;) ;
V_2 = F_13 ( V_91 ) ;
F_10 (self != NULL, return -1;) ;
F_2 ( L_28 , V_12 , V_91 -> V_47 , V_133 ) ;
switch ( V_133 ) {
case V_136 :
if ( ! F_60 ( V_137 ) )
return - V_138 ;
F_15 ( & V_2 -> V_48 , V_44 ) ;
if( V_2 -> V_49 ) {
V_2 -> V_7 = V_135 -> V_139 ;
F_5 ( V_2 ) ;
}
F_26 ( & V_2 -> V_48 , V_44 ) ;
break;
case V_140 :
if ( ! F_60 ( V_137 ) )
return - V_138 ;
if( V_2 -> V_65 )
F_61 ( V_2 -> V_41 , TRUE ) ;
break;
case V_141 :
V_135 -> V_142 = F_41 ( V_2 ) ;
break;
default:
V_28 = - V_143 ;
}
return V_28 ;
}
static inline void F_62 ( struct V_1 * V_2 )
{
struct V_144 * V_145 ;
V_145 = V_2 -> V_146 ;
F_63 ( & V_2 -> V_127 ) ;
V_2 -> V_127 . V_147 . V_148 = F_64 ( V_145 -> V_149 ) ;
V_2 -> V_127 . V_150 . V_148 = V_145 -> V_151 ;
V_2 -> V_127 . V_152 . V_148 = V_145 -> V_153 ;
V_2 -> V_127 . V_154 . V_148 = V_145 -> V_155 ;
V_2 -> V_127 . V_156 . V_148 = V_145 -> V_157 ;
F_2 ( L_29 ,
V_12 , V_2 -> V_127 . V_147 . V_148 , V_2 -> V_127 . V_156 . V_148 ,
V_2 -> V_127 . V_154 . V_148 , V_2 -> V_127 . V_152 . V_148 ,
V_2 -> V_127 . V_150 . V_148 ) ;
if( V_2 -> V_5 & V_158 )
V_2 -> V_127 . V_147 . V_148 &= 0x00ff ;
if( V_2 -> V_5 & V_159 )
V_2 -> V_127 . V_156 . V_148 = 0x07 ;
if( V_2 -> V_5 & V_160 )
V_2 -> V_127 . V_154 . V_148 = 0x01 ;
if( V_2 -> V_5 & V_161 )
V_2 -> V_127 . V_154 . V_148 = 0x7f ;
if( V_2 -> V_5 & V_162 )
V_2 -> V_127 . V_152 . V_148 = 0x01 ;
#if 1
if ( V_163 )
V_2 -> V_127 . V_150 . V_148 = V_163 ;
#endif
F_65 ( & V_2 -> V_127 ) ;
}
static inline int F_66 ( struct V_1 * V_2 )
{
struct V_42 * V_41 = V_2 -> V_41 ;
V_41 -> V_164 = & V_165 ;
F_62 ( V_2 ) ;
return F_67 ( V_41 ) ;
}
static inline void F_68 ( struct V_1 * V_2 )
{
F_69 ( V_2 -> V_41 ) ;
F_45 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_45 ( V_2 -> V_52 ) ;
V_2 -> V_52 = NULL ;
}
static inline int F_70 ( struct V_1 * V_2 , struct V_166 * V_167 , int V_168 )
{
int V_101 ;
V_2 -> V_70 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_169 = 0 ;
for( V_101 = 0 ; V_101 < V_168 ; V_101 ++ ) {
T_1 V_170 ;
T_1 V_171 ;
T_1 V_172 ;
T_5 V_173 ;
V_170 = V_167 [ V_101 ] . V_145 . V_174 & V_175 ;
V_171 = V_167 [ V_101 ] . V_145 . V_174 & V_176 ;
V_172 = V_167 [ V_101 ] . V_145 . V_177 ;
V_173 = F_64 ( V_167 [ V_101 ] . V_145 . V_178 ) ;
if( V_172 == V_179 ) {
if( V_171 == V_180 ) {
V_2 -> V_70 = V_170 ;
} else {
V_2 -> V_33 = V_170 ;
V_2 -> V_181 = V_173 ;
}
} else {
if( ( V_172 == V_182 ) &&
( V_171 == V_180 ) ) {
V_2 -> V_169 = V_170 ;
} else {
F_71 ( L_30 ,
V_12 , V_170 ) ;
}
}
}
F_2 ( L_31 ,
V_12 , V_2 -> V_70 , V_2 -> V_33 ,
V_2 -> V_181 , V_2 -> V_169 ) ;
return ( V_2 -> V_70 != 0 ) && ( V_2 -> V_33 != 0 ) ;
}
static inline void F_72 ( struct V_144 * V_145 )
{
F_73 ( L_32 , V_145 -> V_183 ) ;
F_73 ( L_33 , V_145 -> V_184 ) ;
F_73 ( L_34 , F_64 ( V_145 -> V_185 ) ) ;
F_73 ( L_35 , V_145 -> V_157 ) ;
F_73 ( L_36 , V_145 -> V_155 ) ;
F_73 ( L_37 , V_145 -> V_151 ) ;
F_73 ( L_38 , F_64 ( V_145 -> V_149 ) ) ;
F_73 ( L_39 , V_145 -> V_153 ) ;
F_73 ( L_40 , V_145 -> V_186 ) ;
F_73 ( L_41 , V_145 -> V_187 ) ;
}
static inline struct V_144 * F_74 ( struct V_188 * V_189 )
{
struct V_190 * V_91 = F_75 ( V_189 ) ;
struct V_144 * V_145 ;
int V_28 ;
V_145 = F_43 ( sizeof( * V_145 ) , V_105 ) ;
if ( ! V_145 )
return NULL ;
V_28 = F_76 ( V_91 , F_77 ( V_91 , 0 ) ,
V_191 ,
V_180 | V_192 | V_193 ,
0 , V_189 -> V_194 -> V_145 . V_195 , V_145 ,
sizeof( * V_145 ) , 500 ) ;
F_2 ( L_42 , V_12 , V_28 ) ;
if ( V_28 < sizeof( * V_145 ) ) {
F_6 ( L_43 ,
V_28 < 0 ? L_44 : L_45 , V_28 ) ;
}
else if ( V_145 -> V_184 != V_196 ) {
F_6 ( L_46 ) ;
}
else {
#ifdef F_78
F_72 ( V_145 ) ;
#endif
return V_145 ;
}
F_45 ( V_145 ) ;
return NULL ;
}
static int F_79 ( struct V_188 * V_189 ,
const struct V_197 * V_198 )
{
struct V_42 * V_199 ;
struct V_190 * V_91 = F_75 ( V_189 ) ;
struct V_1 * V_2 ;
struct V_200 * V_201 ;
struct V_144 * V_146 ;
int V_28 = - V_99 ;
int V_101 ;
F_48 ( L_47 ,
V_91 -> V_125 , F_64 ( V_91 -> V_111 . V_202 ) ,
F_64 ( V_91 -> V_111 . V_203 ) ) ;
V_199 = F_80 ( sizeof( * V_2 ) ) ;
if ( ! V_199 )
goto V_204;
F_81 ( V_199 , & V_189 -> V_91 ) ;
V_2 = F_13 ( V_199 ) ;
V_2 -> V_41 = V_199 ;
F_82 ( & V_2 -> V_48 ) ;
F_83 ( & V_2 -> V_84 ) ;
V_2 -> V_5 = V_198 -> V_205 ;
V_2 -> V_123 = ( ( V_2 -> V_5 & V_6 ) != 0 ) ;
if ( V_2 -> V_5 & V_6 ) {
V_2 -> V_130 = V_206 ;
V_2 -> V_37 = V_89 ;
} else {
V_2 -> V_130 = V_207 ;
V_2 -> V_37 = V_208 ;
}
V_2 -> V_128 = F_84 ( V_2 -> V_130 , sizeof( struct V_27 * ) ,
V_105 ) ;
if ( ! V_2 -> V_128 )
goto V_209;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ ) {
V_2 -> V_128 [ V_101 ] = F_85 ( 0 , V_105 ) ;
if ( ! V_2 -> V_128 [ V_101 ] ) {
goto V_210;
}
}
V_2 -> V_43 = F_85 ( 0 , V_105 ) ;
if ( ! V_2 -> V_43 ) {
goto V_210;
}
V_2 -> V_29 = F_85 ( 0 , V_105 ) ;
if ( ! V_2 -> V_29 ) {
goto V_211;
}
if ( F_86 ( V_91 ) < 0 ) {
F_87 ( & V_189 -> V_91 , L_48 ) ;
V_28 = - V_124 ;
goto V_212;
}
V_28 = F_88 ( V_91 , V_189 -> V_194 -> V_145 . V_195 , 0 ) ;
F_2 ( L_49 ,
V_189 -> V_194 -> V_145 . V_195 , V_28 ) ;
switch ( V_28 ) {
case 0 :
break;
case - V_213 :
F_2 ( L_50 ,
V_12 ) ;
break;
default:
F_2 ( L_51 , V_12 , V_28 ) ;
V_28 = - V_124 ;
goto V_212;
}
V_201 = V_189 -> V_214 ;
if( ! F_70 ( V_2 , V_201 -> V_167 ,
V_201 -> V_145 . V_215 ) ) {
F_71 ( L_52 , V_12 ) ;
V_28 = - V_124 ;
goto V_212;
}
V_2 -> V_32 = V_91 ;
V_146 = F_74 ( V_189 ) ;
V_28 = - V_216 ;
if ( ! V_146 )
goto V_212;
if ( V_2 -> V_123 ) {
V_28 = F_76 ( V_2 -> V_32 , F_89 ( V_2 -> V_32 , 0 ) ,
0x02 , 0x40 , 0 , 0 , NULL , 0 , 500 ) ;
if ( V_28 < 0 ) {
F_2 ( L_53 , V_28 ) ;
goto V_212;
} else {
F_24 ( 10 ) ;
}
}
V_2 -> V_146 = V_146 ;
V_2 -> V_49 = 1 ;
V_2 -> V_65 = 0 ;
V_2 -> V_217 = V_189 ;
V_28 = - V_99 ;
V_2 -> V_31 = F_43 ( V_34 , V_105 ) ;
if ( ! V_2 -> V_31 )
goto V_212;
V_2 -> V_52 = F_43 ( V_72 + V_2 -> V_37 ,
V_105 ) ;
if ( ! V_2 -> V_52 )
goto V_218;
V_28 = F_66 ( V_2 ) ;
if ( V_28 )
goto V_219;
F_48 ( L_54 , V_199 -> V_47 ) ;
F_90 ( V_189 , V_2 ) ;
if ( V_2 -> V_123 ) {
V_28 = F_46 ( V_2 ) ;
V_2 -> V_123 = ( V_28 < 0 ) ;
if ( V_2 -> V_123 ) {
F_71 ( L_55 ) ;
goto V_220;
}
V_146 = F_74 ( V_2 -> V_217 ) ;
if ( ! V_146 ) {
V_28 = - V_216 ;
goto V_220;
}
F_45 ( V_2 -> V_146 ) ;
V_2 -> V_146 = V_146 ;
F_62 ( V_2 ) ;
}
return 0 ;
V_220:
F_69 ( V_2 -> V_41 ) ;
V_219:
F_45 ( V_2 -> V_52 ) ;
V_218:
F_45 ( V_2 -> V_31 ) ;
V_212:
F_91 ( V_2 -> V_29 ) ;
V_211:
F_91 ( V_2 -> V_43 ) ;
V_210:
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ )
F_91 ( V_2 -> V_128 [ V_101 ] ) ;
F_45 ( V_2 -> V_128 ) ;
V_209:
F_92 ( V_199 ) ;
V_204:
return V_28 ;
}
static void F_93 ( struct V_188 * V_189 )
{
unsigned long V_44 ;
struct V_1 * V_2 = F_94 ( V_189 ) ;
int V_101 ;
F_90 ( V_189 , NULL ) ;
if ( ! V_2 )
return;
F_15 ( & V_2 -> V_48 , V_44 ) ;
V_2 -> V_49 = 0 ;
F_56 ( & V_2 -> V_84 ) ;
F_26 ( & V_2 -> V_48 , V_44 ) ;
if( ( V_2 -> V_65 ) || ( V_2 -> V_126 ) ) {
F_14 ( V_2 -> V_41 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ )
F_57 ( V_2 -> V_128 [ V_101 ] ) ;
F_57 ( V_2 -> V_43 ) ;
F_57 ( V_2 -> V_29 ) ;
}
F_68 ( V_2 ) ;
V_2 -> V_32 = NULL ;
V_2 -> V_217 = NULL ;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ )
F_91 ( V_2 -> V_128 [ V_101 ] ) ;
F_45 ( V_2 -> V_128 ) ;
F_91 ( V_2 -> V_43 ) ;
F_91 ( V_2 -> V_29 ) ;
F_92 ( V_2 -> V_41 ) ;
F_2 ( L_56 , V_12 ) ;
}
static int F_95 ( struct V_188 * V_189 , T_6 V_221 )
{
struct V_1 * V_2 = F_94 ( V_189 ) ;
int V_101 ;
F_96 ( V_2 -> V_41 ) ;
if ( V_2 -> V_43 != NULL )
F_57 ( V_2 -> V_43 ) ;
if ( V_2 -> V_29 != NULL )
F_57 ( V_2 -> V_29 ) ;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ ) {
if ( V_2 -> V_128 [ V_101 ] != NULL )
F_57 ( V_2 -> V_128 [ V_101 ] ) ;
}
return 0 ;
}
static int F_97 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = F_94 ( V_189 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_130 ; V_101 ++ ) {
if ( V_2 -> V_128 [ V_101 ] != NULL )
F_9 ( V_2 -> V_128 [ V_101 ] , V_105 ) ;
}
F_98 ( V_2 -> V_41 ) ;
return 0 ;
}
