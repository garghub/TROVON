static void F_1 ( void )
{
}
static int F_2 ( unsigned int V_1 , T_1 * V_2 , int V_3 )
{
unsigned long V_4 = 0 ;
int V_5 ;
if ( V_3 == 1 ) {
V_5 = 0 ;
while ( 1 == 1 ) {
F_3 ( F_4 ( V_1 ) , V_6 , 0 , V_6 ) ;
F_5 ( & V_7 , V_4 ) ;
if ( F_6 ( F_4 ( V_1 ) ) & V_6 ) {
F_7 ( & V_7 , V_4 ) ;
continue;
}
F_8 ( * V_2 , F_9 ( V_1 ) ) ;
F_7 ( & V_7 , V_4 ) ;
return 0 ;
}
} else {
F_5 ( & V_7 , V_4 ) ;
V_5 = 1 ;
while ( V_3 -- ) {
F_3 ( F_4 ( V_1 ) , V_6 , 0 , V_6 ) ;
F_8 ( * V_2 ++ , F_9 ( V_1 ) ) ;
}
F_7 ( & V_7 , V_4 ) ;
}
return 0 ;
V_8:
if ( V_5 )
F_7 ( & V_7 , V_4 ) ;
F_10 ( V_9 L_1 , V_3 + 1 ) ;
F_1 () ;
return 1 ;
}
static int T_2 F_11 ( unsigned int V_1 , T_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
F_5 ( & V_7 , V_4 ) ;
while ( V_3 -- ) {
F_3 ( F_4 ( V_1 ) , V_10 , V_10 , 0 ) ;
* V_2 ++ = F_6 ( F_9 ( V_1 ) ) ;
}
F_7 ( & V_7 , V_4 ) ;
return 0 ;
V_8:
F_7 ( & V_7 , V_4 ) ;
F_10 ( V_9 L_2 , V_3 + 1 ) ;
F_1 () ;
return 1 ;
}
static int T_2 F_12 ( unsigned int V_1 , T_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
F_5 ( & V_7 , V_4 ) ;
while ( V_3 -- ) {
F_13 ( F_4 ( V_1 ) , V_10 , V_10 , 0 , 100 ) ;
* V_2 ++ = F_6 ( F_9 ( V_1 ) ) ;
}
F_7 ( & V_7 , V_4 ) ;
return 0 ;
V_8:
F_7 ( & V_7 , V_4 ) ;
return 1 ;
}
static int F_14 ( unsigned V_11 , unsigned V_12 )
{
switch ( V_11 ) {
case 0x0 :
case 0xa :
case 0xb :
V_11 = 0 ;
break;
case 0x11 :
V_11 = V_13 ;
break;
case 0x12 :
case 0x13 :
case 0x15 :
case 0x16 :
case 0x17 :
case 0x18 :
case 0x19 :
case 0x1a :
F_15 ( F_10 ( L_3 , V_11 , V_12 ) ) ;
V_11 = V_14 ;
break;
case 0x14 :
V_11 = V_15 ;
break;
default:
F_10 ( V_9 L_4 , V_11 ) ;
break;
}
return V_12 | ( V_11 << 16 ) ;
}
static int T_2 F_16 ( int V_16 , struct V_17 * V_18 )
{
T_1 V_19 [] = { V_20 } ;
T_1 V_21 [ 4 ] ;
T_1 * V_2 ;
int V_3 ;
volatile int V_22 = 0 ;
if ( F_6 ( F_4 ( V_16 ) ) == 0xff )
return 0 ;
F_17 ( V_16 ) ;
F_8 ( V_23 | V_24 , F_18 ( V_16 ) ) ;
F_19 ( 20 ) ;
V_22 = 1 ;
F_3 ( F_4 ( V_16 ) , V_25 , V_26 | V_27 , V_28 | V_29 | V_30 | V_10 | V_6 ) ;
V_22 = 2 ;
if ( F_6 ( F_20 ( V_16 ) ) & V_31 )
goto V_8;
F_2 ( V_16 , V_19 , 1 ) ;
V_22 = 3 ;
V_3 = 4 ;
V_2 = & V_21 [ 0 ] ;
while ( V_3 -- ) {
F_3 ( F_4 ( V_16 ) , V_10 , V_10 , 0 ) ;
* V_2 ++ = F_6 ( F_9 ( V_16 ) ) ;
}
V_22 = 8 ;
if ( F_6 ( F_4 ( V_16 ) ) & V_10 )
goto V_8;
V_22 = 9 ;
F_3 ( F_20 ( V_16 ) , V_32 , V_32 , 0 ) ;
V_22 = 10 ;
F_8 ( V_24 , F_18 ( V_16 ) ) ;
V_22 = 11 ;
return V_22 ;
V_8:
return 0 ;
}
static T_3 F_21 ( int V_33 , void * V_34 )
{
unsigned long V_4 ;
struct V_17 * V_35 = V_34 ;
F_5 ( V_35 -> V_36 , V_4 ) ;
F_22 ( V_35 ) ;
F_7 ( V_35 -> V_36 , V_4 ) ;
return V_37 ;
}
static void F_22 ( struct V_17 * V_35 )
{
void (* F_23) ( T_4 * ) = NULL ;
int V_38 , V_39 , V_40 , V_41 ;
int V_42 ;
unsigned long V_4 ;
T_4 * V_43 ;
int V_44 ;
int V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
V_47 = F_24 ( V_35 ) -> V_47 ;
V_48 = F_24 ( V_35 ) -> V_48 ;
#ifdef F_25
{
V_44 = F_6 ( F_20 ( V_35 -> V_49 ) ) ;
F_10 ( V_50 L_5 ) ;
if ( ! ( V_44 & V_51 ) )
F_10 ( L_6 ) ;
if ( V_44 & V_52 )
F_10 ( L_7 ) ;
if ( V_44 & V_53 )
F_10 ( L_8 ) ;
if ( V_44 & V_32 )
F_10 ( L_9 ) ;
if ( V_44 & V_54 )
F_10 ( L_10 ) ;
F_10 ( L_11 , F_6 ( F_4 ( V_35 -> V_49 ) ) ) ;
} ;
#endif
V_42 = 0 ;
V_45 = 0 ;
while ( 1 == 1 ) {
V_44 = F_6 ( F_20 ( V_35 -> V_49 ) ) ;
if ( V_44 & ~ V_52 ) {
if ( V_44 & V_53 )
F_10 ( L_8 ) ;
if ( V_44 & V_32 )
F_10 ( L_9 ) ;
if ( V_44 & V_54 ) {
V_45 = 1 ;
F_10 ( L_10 ) ;
}
}
F_17 ( V_35 -> V_49 ) ;
F_5 ( & V_7 , V_4 ) ;
V_39 = F_24 ( V_35 ) -> V_55 + 1 ;
if ( V_39 >= 2 * V_56 )
V_39 = V_56 ;
do {
if ( V_47 [ V_39 ] . V_57 != 0 )
break;
V_39 ++ ;
if ( V_39 >= 2 * V_56 )
V_39 = V_56 ;
} while ( V_39 != F_24 ( V_35 ) -> V_55 );
if ( V_47 [ V_39 ] . V_57 == 0 ) {
F_7 ( & V_7 , V_4 ) ;
if ( ! V_42 && ! V_45 )
F_10 ( V_58 L_12 ) ;
if ( V_45 )
F_26 ( V_35 ) ;
return;
} ;
V_40 = ( F_27 ( V_47 [ V_39 ] . V_59 ) - ( F_28 ( & V_48 [ 0 ] ) ) ) / sizeof( struct V_48 ) ;
V_41 = V_47 [ V_39 ] . V_57 ;
V_47 [ V_39 ] . V_57 = 0 ;
F_24 ( V_35 ) -> V_55 = V_39 ;
F_7 ( & V_7 , V_4 ) ;
#ifdef F_25
{
if ( V_48 [ V_40 ] . V_60 | V_48 [ V_40 ] . V_61 )
F_10 ( V_50 L_13 ,
V_48 [ V_40 ] . V_60 + ( ( int ) V_48 [ V_40 ] . V_61 << 16 ) , V_47 [ V_39 ] . V_57 ) ;
} ;
#endif
if ( V_41 == 3 )
continue;
#ifdef F_25
F_10 ( V_50 L_14 , V_40 , V_39 ) ;
#endif
V_43 = F_24 ( V_35 ) -> V_62 [ V_40 ] ;
if ( ! V_43 || ! V_43 -> V_63 ) {
F_10 ( V_58 L_15 ) ;
F_10 ( V_58 L_16 , V_48 [ V_40 ] . V_60 ,
V_48 [ V_40 ] . V_61 , V_48 [ V_40 ] . V_64 , V_40 ) ;
return;
}
F_23 = V_43 -> V_63 ;
F_29 ( V_43 -> V_65 ) ;
V_43 -> V_65 = NULL ;
if ( V_48 [ V_40 ] . V_60 == 2 )
memcpy ( V_43 -> V_66 , & V_48 [ V_40 ] . V_67 [ V_48 [ V_40 ] . V_68 ] ,
V_69 ) ;
if ( V_41 != 1 )
V_38 = F_14 ( V_48 [ V_40 ] . V_61 , V_48 [ V_40 ] . V_60 ) ;
else
V_38 = 0 ;
#ifdef F_25
if ( V_38 )
F_10 ( V_50 L_17 , V_38 ,
V_48 [ V_40 ] . V_61 , V_48 [ V_40 ] . V_60 ) ;
#endif
if ( V_48 [ V_40 ] . V_60 == 2 ) {
#ifdef F_25
int V_70 ;
#endif
F_15 ( F_10 ( L_18 ) ) ;
#ifdef F_25
for ( V_70 = 0 ; V_70 < 12 ; V_70 ++ )
F_10 ( L_19 , V_48 [ V_40 ] . V_67 [ V_48 [ V_40 ] . V_68 + V_70 ] ) ;
F_10 ( L_20 ) ;
#endif
}
F_15 (if (errstatus) printk(L_21, errstatus)) ;
V_43 -> V_71 = V_38 ;
F_24 ( V_35 ) -> V_62 [ V_40 ] = NULL ;
F_23 ( V_43 ) ;
V_42 ++ ;
} ;
}
static int F_30 ( T_4 * V_72 , void (* F_31) ( T_4 * ) )
{
T_1 V_73 = V_74 ;
T_1 V_75 ;
T_1 * V_76 = ( T_1 * ) V_72 -> V_77 ;
T_1 V_78 = V_72 -> V_79 -> V_80 ;
T_1 V_81 = V_72 -> V_79 -> V_81 ;
unsigned long V_4 ;
int V_82 = F_32 ( V_72 ) ;
int V_40 ;
struct V_46 * V_47 ;
struct V_48 * V_48 ;
F_15 (int i) ;
V_47 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_47 ;
V_48 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_48 ;
F_15 (if (target > 1) {
SCpnt->result = DID_TIME_OUT << 16;
done(SCpnt); return 0;
}
) ;
if ( * V_76 == V_84 ) {
#if 0
if (bufflen != SCSI_SENSE_BUFFERSIZE)
printk(KERN_CRIT "aha1542: Wrong buffer length supplied "
"for request sense (%d)\n", bufflen);
#endif
V_72 -> V_71 = 0 ;
F_31 ( V_72 ) ;
return 0 ;
}
#ifdef F_25
if ( * V_76 == V_85 || * V_76 == V_86 )
V_70 = F_33 ( V_76 + 2 ) ;
else if ( * V_76 == V_87 || * V_76 == V_88 )
V_70 = F_27 ( V_76 + 2 ) ;
else
V_70 = - 1 ;
if ( F_31 )
F_10 ( V_50 L_22 , V_78 , * V_76 , V_70 , V_82 ) ;
else
F_10 ( V_50 L_23 , V_78 , * V_76 , V_70 , V_82 ) ;
F_1 () ;
F_10 ( V_50 L_24 ) ;
for ( V_70 = 0 ; V_70 < V_72 -> V_89 ; V_70 ++ )
F_10 ( L_19 , V_76 [ V_70 ] ) ;
F_10 ( L_20 ) ;
if ( * V_76 == V_86 || * V_76 == V_88 )
return 0 ;
#endif
F_5 ( & V_7 , V_4 ) ;
V_40 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 + 1 ;
if ( V_40 >= V_56 )
V_40 = 0 ;
do {
if ( V_47 [ V_40 ] . V_57 == 0 && F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] == NULL )
break;
V_40 ++ ;
if ( V_40 >= V_56 )
V_40 = 0 ;
} while ( V_40 != F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 );
if ( V_47 [ V_40 ] . V_57 || F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] )
F_34 ( L_25 ) ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] = V_72 ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 = V_40 ;
F_7 ( & V_7 , V_4 ) ;
#ifdef F_25
F_10 ( V_50 L_26 , V_40 , F_31 ) ;
#endif
F_35 ( V_47 [ V_40 ] . V_59 , F_28 ( & V_48 [ V_40 ] ) ) ;
memset ( & V_48 [ V_40 ] , 0 , sizeof( struct V_48 ) ) ;
V_48 [ V_40 ] . V_68 = V_72 -> V_89 ;
V_75 = 0 ;
if ( * V_76 == V_85 || * V_76 == V_87 )
V_75 = 8 ;
else if ( * V_76 == V_86 || * V_76 == V_88 )
V_75 = 16 ;
memcpy ( V_48 [ V_40 ] . V_67 , V_76 , V_48 [ V_40 ] . V_68 ) ;
if ( V_82 ) {
struct V_91 * V_92 ;
struct V_93 * V_94 ;
#ifdef F_25
unsigned char * V_95 ;
#endif
int V_70 , V_96 = F_36 ( V_72 ) ;
V_48 [ V_40 ] . V_97 = 2 ;
V_72 -> V_65 = F_37 ( sizeof( * V_94 ) * V_96 ,
V_98 | V_99 ) ;
V_94 = (struct V_93 * ) V_72 -> V_65 ;
if ( V_94 == NULL ) {
F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] = NULL ;
return V_100 ;
}
F_38 (SCpnt, sg, sg_count, i) {
F_35 ( V_94 [ V_70 ] . V_101 , F_39 ( V_92 ) ) ;
F_35 ( V_94 [ V_70 ] . V_102 , V_92 -> V_103 ) ;
} ;
F_35 ( V_48 [ V_40 ] . V_102 , V_96 * sizeof( struct V_93 ) ) ;
F_35 ( V_48 [ V_40 ] . V_101 , F_28 ( V_94 ) ) ;
#ifdef F_25
F_10 ( L_27 , V_94 ) ;
V_95 = ( unsigned char * ) V_94 ;
for ( V_70 = 0 ; V_70 < 18 ; V_70 ++ )
F_10 ( L_19 , V_95 [ V_70 ] ) ;
#endif
} else {
V_48 [ V_40 ] . V_97 = 0 ;
V_72 -> V_65 = NULL ;
F_35 ( V_48 [ V_40 ] . V_102 , 0 ) ;
F_35 ( V_48 [ V_40 ] . V_101 , 0 ) ;
} ;
V_48 [ V_40 ] . V_64 = ( V_78 & 7 ) << 5 | V_75 | ( V_81 & 7 ) ;
V_48 [ V_40 ] . V_104 = 16 ;
V_48 [ V_40 ] . V_105 [ 0 ] = V_48 [ V_40 ] . V_105 [ 1 ] = V_48 [ V_40 ] . V_105 [ 2 ] = 0 ;
V_48 [ V_40 ] . V_106 = 0 ;
#ifdef F_25
{
int V_70 ;
F_10 ( V_50 L_28 ) ;
for ( V_70 = 0 ; V_70 < sizeof( V_48 [ V_40 ] ) - 10 ; V_70 ++ )
F_10 ( L_19 , ( ( T_1 * ) & V_48 [ V_40 ] ) [ V_70 ] ) ;
} ;
#endif
if ( F_31 ) {
F_15 (printk(L_29);
aha1542_stat()) ;
V_72 -> V_63 = F_31 ;
V_47 [ V_40 ] . V_57 = 1 ;
F_2 ( V_72 -> V_79 -> V_83 -> V_49 , & V_73 , 1 ) ;
F_15 ( F_1 () ) ;
} else
F_10 ( L_30 ) ;
return 0 ;
}
int T_2 F_40 ( int V_107 , unsigned char * V_108 , unsigned char * V_109 , unsigned char * V_110 )
{
T_1 V_19 [] = { V_111 } ;
T_1 V_21 [ 3 ] ;
int V_70 ;
V_70 = F_6 ( F_4 ( V_107 ) ) ;
if ( V_70 & V_10 ) {
V_70 = F_6 ( F_9 ( V_107 ) ) ;
} ;
F_2 ( V_107 , V_19 , 1 ) ;
F_11 ( V_107 , V_21 , 3 ) ;
F_3 ( F_20 ( V_107 ) , V_31 , V_32 , 0 ) ;
while ( 0 ) {
V_8:
F_10 ( V_9 L_31 ) ;
}
F_17 ( V_107 ) ;
switch ( V_21 [ 0 ] ) {
case 0x80 :
* V_109 = 7 ;
break;
case 0x40 :
* V_109 = 6 ;
break;
case 0x20 :
* V_109 = 5 ;
break;
case 0x01 :
* V_109 = 0 ;
break;
case 0 :
* V_109 = 0xFF ;
break;
default:
F_10 ( V_9 L_32 ) ;
return - 1 ;
} ;
switch ( V_21 [ 1 ] ) {
case 0x40 :
* V_108 = 15 ;
break;
case 0x20 :
* V_108 = 14 ;
break;
case 0x8 :
* V_108 = 12 ;
break;
case 0x4 :
* V_108 = 11 ;
break;
case 0x2 :
* V_108 = 10 ;
break;
case 0x1 :
* V_108 = 9 ;
break;
default:
F_10 ( V_9 L_33 ) ;
return - 1 ;
} ;
* V_110 = V_21 [ 2 ] & 7 ;
return 0 ;
}
static int T_2 F_41 ( int V_1 )
{
static T_1 V_112 [ 3 ] ;
static T_1 V_113 [ 2 ] ;
int V_114 ;
V_114 = V_115 ;
V_112 [ 0 ] = V_116 ;
F_2 ( V_1 , V_112 , 1 ) ;
if ( F_12 ( V_1 , V_113 , 2 ) )
return V_114 ;
F_13 ( F_20 ( V_1 ) , V_31 , V_32 , 0 , 100 ) ;
F_17 ( V_1 ) ;
if ( ( V_113 [ 0 ] & 0x08 ) || V_113 [ 1 ] ) {
V_112 [ 0 ] = V_117 ;
V_112 [ 1 ] = 0 ;
V_112 [ 2 ] = V_113 [ 1 ] ;
if ( ( V_113 [ 0 ] & 0x08 ) && ( V_113 [ 1 ] & 0x03 ) )
V_114 = V_118 ;
F_2 ( V_1 , V_112 , 3 ) ;
F_3 ( F_20 ( V_1 ) , V_31 , V_32 , 0 ) ;
} ;
while ( 0 ) {
V_8:
F_10 ( V_9 L_34 ) ;
}
F_17 ( V_1 ) ;
return V_114 ;
}
static int T_2 F_42 ( int V_107 , int * V_119 )
{
T_1 V_19 [] = { V_20 } ;
T_1 V_21 [ 4 ] ;
int V_70 ;
V_70 = F_6 ( F_4 ( V_107 ) ) ;
if ( V_70 & V_10 ) {
V_70 = F_6 ( F_9 ( V_107 ) ) ;
} ;
F_2 ( V_107 , V_19 , 1 ) ;
F_11 ( V_107 , V_21 , 4 ) ;
F_3 ( F_20 ( V_107 ) , V_31 , V_32 , 0 ) ;
while ( 0 ) {
V_8:
F_10 ( V_9 L_35 ) ;
}
F_17 ( V_107 ) ;
* V_119 = V_115 ;
if ( V_21 [ 0 ] == 0x43 ) {
F_10 ( V_120 L_36 ) ;
return 1 ;
} ;
* V_119 = F_41 ( V_107 ) ;
return 0 ;
}
static void T_2 F_43 ( char * V_121 , int * V_122 )
{
const char * V_123 = L_37 ;
int V_124 ;
if ( V_125 >= V_126 ) {
F_10 ( V_9 L_38 ) ;
F_10 ( V_9 L_39 , V_127 [ 0 ] ) ;
F_10 ( V_9 L_40 , V_127 [ 1 ] ) ;
F_10 ( V_9 L_41 , V_121 ) ;
return;
}
if ( V_122 [ 0 ] < 1 || V_122 [ 0 ] > 4 ) {
F_10 ( V_9 L_42 , V_121 ) ;
F_10 ( V_123 ) ;
F_10 ( V_9 L_43 ) ;
}
V_128 [ V_125 ] = V_122 [ 0 ] ;
V_127 [ V_125 ] = V_121 ;
V_124 = V_122 [ 0 ] >= 1 ? V_122 [ 1 ] : 0 ;
V_129 [ V_125 ] = V_122 [ 0 ] >= 2 ? V_122 [ 2 ] : 7 ;
V_130 [ V_125 ] = V_122 [ 0 ] >= 3 ? V_122 [ 3 ] : 5 ;
if ( V_122 [ 0 ] >= 4 )
{
int V_131 = - 1 ;
switch ( V_122 [ 4 ] ) {
case 5 :
V_131 = 0x00 ;
break;
case 6 :
V_131 = 0x04 ;
break;
case 7 :
V_131 = 0x01 ;
break;
case 8 :
V_131 = 0x02 ;
break;
case 10 :
V_131 = 0x03 ;
break;
default:
F_10 ( V_9 L_42 , V_121 ) ;
F_10 ( V_123 ) ;
F_10 ( V_9 L_44 ) ;
break;
}
V_132 [ V_125 ] = V_131 ;
}
if ( V_124 != 0 )
V_133 [ V_125 ] = V_124 ;
++ V_125 ;
}
static int T_2 F_44 ( char * V_121 )
{
int V_122 [ 5 ] ;
int V_134 = V_125 ;
F_45 ( V_121 , F_46 ( V_122 ) , V_122 ) ;
F_43 ( V_121 , V_122 ) ;
return V_134 < V_125 ;
}
static int T_2 F_47 ( struct V_135 * V_136 )
{
unsigned char V_109 ;
unsigned char V_108 ;
unsigned char V_110 ;
unsigned long V_4 ;
unsigned int V_107 ;
int V_137 ;
struct V_17 * V_18 = NULL ;
int V_134 = 0 ;
int V_138 ;
F_15 ( F_10 ( L_45 ) ) ;
V_136 -> V_139 = L_46 ;
#ifdef F_48
V_133 [ 0 ] = V_140 [ 0 ] ;
V_129 [ 0 ] = V_140 [ 1 ] ;
V_130 [ 0 ] = V_140 [ 2 ] ;
{
int V_131 = - 1 ;
switch ( V_140 [ 3 ] ) {
case 5 :
V_131 = 0x00 ;
break;
case 6 :
V_131 = 0x04 ;
break;
case 7 :
V_131 = 0x01 ;
break;
case 8 :
V_131 = 0x02 ;
break;
case 10 :
V_131 = 0x03 ;
break;
} ;
V_132 [ 0 ] = V_131 ;
}
#endif
#ifdef F_49
if( V_141 ) {
int V_142 = 0 ;
int V_143 = 0 ;
for ( V_138 = 0 ; ( V_142 != V_144 ) && ( V_138 < F_46 ( V_133 ) ) ; V_138 ++ ) {
if ( V_133 [ V_138 ] )
continue;
V_142 = F_50 ( 0x0f1f , V_142 ) ;
if ( V_142 == V_144 )
break;
V_143 = F_51 ( V_142 , 3 ) ;
if ( V_143 & 0x80 ) {
if ( V_143 & 0x02 ) {
if ( V_143 & 0x01 )
V_133 [ V_138 ] = 0x334 ;
else
V_133 [ V_138 ] = 0x234 ;
} else {
if ( V_143 & 0x01 )
V_133 [ V_138 ] = 0x134 ;
}
} else {
if ( V_143 & 0x02 ) {
if ( V_143 & 0x01 )
V_133 [ V_138 ] = 0x330 ;
else
V_133 [ V_138 ] = 0x230 ;
} else {
if ( V_143 & 0x01 )
V_133 [ V_138 ] = 0x130 ;
}
}
F_10 ( V_120 L_47 , V_142 , V_133 [ V_138 ] ) ;
F_52 ( V_142 , L_48 ) ;
F_53 ( V_142 , NULL , NULL ) ;
F_54 ( V_142 ) ;
V_142 ++ ;
}
}
#endif
if( V_145 )
{
struct V_146 * V_147 = NULL ;
for( V_138 = 0 ; V_138 < F_46 ( V_133 ) ; V_138 ++ ) {
if( V_133 [ V_138 ] )
continue;
V_147 = F_55 ( NULL , F_56 ( 'A' , 'D' , 'P' ) ,
F_57 ( 0x1542 ) , V_147 ) ;
if( V_147 == NULL )
break;
if( F_58 ( V_147 ) < 0 )
continue;
if( F_59 ( V_147 ) < 0 ) {
F_60 ( V_147 ) ;
continue;
}
if( ! F_61 ( V_147 , 0 ) ) {
F_60 ( V_147 ) ;
continue;
}
V_133 [ V_138 ] = F_62 ( V_147 , 0 ) ;
F_10 ( V_120 L_49 , V_133 [ V_138 ] ) ;
}
}
for ( V_138 = 0 ; V_138 < F_46 ( V_133 ) ; V_138 ++ )
if ( V_133 [ V_138 ] != 0 && F_63 ( V_133 [ V_138 ] , 4 , L_46 ) ) {
V_18 = F_64 ( V_136 ,
sizeof( struct V_148 ) ) ;
if( V_18 == NULL ) {
F_65 ( V_133 [ V_138 ] , 4 ) ;
continue;
}
if ( ! F_16 ( V_133 [ V_138 ] , V_18 ) )
goto V_149;
V_107 = V_133 [ V_138 ] ;
{
T_1 V_150 [] = { V_151 , 7 } ;
T_1 V_152 [] = { V_153 , 5 } ;
if ( V_128 [ V_138 ] ) {
V_150 [ 1 ] = V_129 [ V_138 ] ;
V_152 [ 1 ] = V_130 [ V_138 ] ;
}
F_17 ( V_107 ) ;
F_2 ( V_107 , V_150 , 2 ) ;
F_3 ( F_20 ( V_107 ) , V_31 , V_32 , 0 ) ;
F_17 ( V_107 ) ;
F_2 ( V_107 , V_152 , 2 ) ;
F_3 ( F_20 ( V_107 ) , V_31 , V_32 , 0 ) ;
if ( V_132 [ V_138 ] >= 0 ) {
T_1 V_154 [] = { V_155 , 0 } ;
V_154 [ 1 ] = V_132 [ V_138 ] ;
F_17 ( V_107 ) ;
F_2 ( V_107 , V_154 , 2 ) ;
F_3 ( F_20 ( V_107 ) , V_31 , V_32 , 0 ) ;
}
while ( 0 ) {
V_8:
F_10 ( V_9 L_50 ) ;
}
F_17 ( V_107 ) ;
}
if ( F_42 ( V_107 , & V_137 ) )
goto V_149;
if ( F_40 ( V_107 , & V_108 , & V_109 , & V_110 ) == - 1 )
goto V_149;
F_10 ( V_120 L_51 , V_110 , V_107 , V_108 ) ;
if ( V_109 != 0xFF )
F_10 ( L_52 , V_109 ) ;
F_10 ( L_20 ) ;
F_15 ( F_1 () ) ;
F_66 ( V_107 , V_18 ) ;
F_15 ( F_1 () ) ;
F_15 ( F_10 ( L_53 , V_108 ) ) ;
F_5 ( & V_7 , V_4 ) ;
if ( F_67 ( V_108 , F_21 , 0 ,
L_46 , V_18 ) ) {
F_10 ( V_9 L_54 ) ;
F_7 ( & V_7 , V_4 ) ;
goto V_149;
}
if ( V_109 != 0xFF ) {
if ( F_68 ( V_109 , L_46 ) ) {
F_10 ( V_9 L_55 ) ;
F_69 ( V_108 , V_18 ) ;
F_7 ( & V_7 , V_4 ) ;
goto V_149;
}
if ( V_109 == 0 || V_109 >= 5 ) {
F_70 ( V_109 , V_156 ) ;
F_71 ( V_109 ) ;
}
}
V_18 -> V_157 = V_110 ;
V_18 -> V_158 = V_107 ;
V_18 -> V_49 = V_107 ;
V_18 -> V_159 = 4 ;
V_18 -> V_160 = V_109 ;
V_18 -> V_161 = V_108 ;
F_24 ( V_18 ) -> V_162 = V_137 ;
if ( V_137 == V_118 )
F_10 ( V_120 L_56 ) ;
F_24 ( V_18 ) -> V_55 = ( 2 * V_56 - 1 ) ;
F_24 ( V_18 ) -> V_90 = ( V_56 - 1 ) ;
memset ( F_24 ( V_18 ) -> V_62 , 0 , sizeof( F_24 ( V_18 ) -> V_62 ) ) ;
F_7 ( & V_7 , V_4 ) ;
#if 0
DEB(printk(" *** READ CAPACITY ***\n"));
{
unchar buf[8];
static unchar cmd[] = { READ_CAPACITY, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int i;
for (i = 0; i < sizeof(buf); ++i)
buf[i] = 0x87;
for (i = 0; i < 2; ++i)
if (!aha1542_command(i, cmd, buf, sizeof(buf))) {
printk(KERN_DEBUG "aha_detect: LU %d sector_size %d device_size %d\n",
i, xscsi2int(buf + 4), xscsi2int(buf));
}
}
DEB(printk(" *** NOW RUNNING MY OWN TEST *** \n"));
for (i = 0; i < 4; ++i) {
unsigned char cmd[10];
static buffer[512];
cmd[0] = READ_10;
cmd[1] = 0;
xany2scsi(cmd + 2, i);
cmd[6] = 0;
cmd[7] = 0;
cmd[8] = 1;
cmd[9] = 0;
aha1542_command(0, cmd, buffer, 512);
}
#endif
V_134 ++ ;
continue;
V_149:
F_65 ( V_133 [ V_138 ] , 4 ) ;
F_72 ( V_18 ) ;
continue;
} ;
return V_134 ;
}
static int F_73 ( struct V_17 * V_35 )
{
if ( V_35 -> V_161 )
F_69 ( V_35 -> V_161 , V_35 ) ;
if ( V_35 -> V_160 != 0xff )
F_74 ( V_35 -> V_160 ) ;
if ( V_35 -> V_49 && V_35 -> V_159 )
F_65 ( V_35 -> V_49 , V_35 -> V_159 ) ;
F_72 ( V_35 ) ;
return 0 ;
}
static int F_26 ( struct V_17 * V_35 )
{
int V_70 ;
int V_134 = 0 ;
#if 0
unchar ahacmd = CMD_START_SCSI;
#endif
for ( V_70 = 0 ; V_70 < V_56 ; V_70 ++ )
if ( F_24 ( V_35 ) -> V_62 [ V_70 ] &&
! ( F_24 ( V_35 ) -> V_62 [ V_70 ] -> V_79 -> V_163 ) ) {
#if 0
HOSTDATA(shost)->mb[i].status = 1;
#endif
V_134 ++ ;
}
F_10 ( V_50 L_57 , V_134 ) ;
#if 0
if (count)
aha1542_out(shost->io_port, &ahacmd, 1);
#endif
return 0 ;
}
static int F_75 ( T_4 * V_72 )
{
unsigned long V_4 ;
struct V_46 * V_47 ;
T_1 V_78 = V_72 -> V_79 -> V_80 ;
T_1 V_81 = V_72 -> V_79 -> V_81 ;
int V_40 ;
struct V_48 * V_48 ;
T_1 V_73 = V_74 ;
V_48 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_48 ;
V_47 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_47 ;
F_5 ( & V_7 , V_4 ) ;
V_40 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 + 1 ;
if ( V_40 >= V_56 )
V_40 = 0 ;
do {
if ( V_47 [ V_40 ] . V_57 == 0 && F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] == NULL )
break;
V_40 ++ ;
if ( V_40 >= V_56 )
V_40 = 0 ;
} while ( V_40 != F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 );
if ( V_47 [ V_40 ] . V_57 || F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] )
F_34 ( L_25 ) ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_40 ] = V_72 ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_90 = V_40 ;
F_7 ( & V_7 , V_4 ) ;
F_35 ( V_47 [ V_40 ] . V_59 , F_28 ( & V_48 [ V_40 ] ) ) ;
memset ( & V_48 [ V_40 ] , 0 , sizeof( struct V_48 ) ) ;
V_48 [ V_40 ] . V_97 = 0x81 ;
V_48 [ V_40 ] . V_64 = ( V_78 & 7 ) << 5 | ( V_81 & 7 ) ;
V_48 [ V_40 ] . V_105 [ 0 ] = V_48 [ V_40 ] . V_105 [ 1 ] = V_48 [ V_40 ] . V_105 [ 2 ] = 0 ;
V_48 [ V_40 ] . V_106 = 0 ;
F_2 ( V_72 -> V_79 -> V_83 -> V_49 , & V_73 , 1 ) ;
F_76 ( V_58 , V_72 ,
L_58 ) ;
return V_164 ;
#ifdef F_77
F_10 ( V_58 L_59 , V_72 -> V_78 ) ;
for ( V_70 = 0 ; V_70 < V_56 ; V_70 ++ ) {
if ( F_24 ( V_72 -> V_83 ) -> V_62 [ V_70 ] &&
F_24 ( V_72 -> V_83 ) -> V_62 [ V_70 ] -> V_78 == V_72 -> V_78 ) {
T_4 * V_43 ;
V_43 = F_24 ( V_72 -> V_83 ) -> V_62 [ V_70 ] ;
F_29 ( V_43 -> V_65 ) ;
V_43 -> V_65 = NULL ;
F_24 ( V_72 -> V_83 ) -> V_62 [ V_70 ] = NULL ;
F_24 ( V_72 -> V_83 ) -> V_47 [ V_70 ] . V_57 = 0 ;
}
}
return V_164 ;
return V_165 ;
#endif
}
static int F_78 ( T_4 * V_72 )
{
int V_70 ;
F_8 ( V_166 , F_18 ( V_72 -> V_79 -> V_83 -> V_49 ) ) ;
F_79 ( 4 ) ;
F_80 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
F_3 ( F_4 ( V_72 -> V_79 -> V_83 -> V_49 ) ,
V_25 , V_26 | V_27 , V_28 | V_29 | V_30 | V_10 | V_6 ) ;
F_10 ( V_58 L_60 , V_72 -> V_79 -> V_83 -> V_167 ) ;
for ( V_70 = 0 ; V_70 < V_56 ; V_70 ++ ) {
if ( F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] != NULL ) {
T_4 * V_43 ;
V_43 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] ;
if ( V_43 -> V_79 -> V_163 ) {
continue;
}
F_29 ( V_43 -> V_65 ) ;
V_43 -> V_65 = NULL ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] = NULL ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_47 [ V_70 ] . V_57 = 0 ;
}
}
F_81 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
return V_164 ;
V_8:
F_81 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
return V_165 ;
}
static int F_82 ( T_4 * V_72 )
{
int V_70 ;
F_8 ( V_168 | V_166 , F_18 ( V_72 -> V_79 -> V_83 -> V_49 ) ) ;
F_79 ( 4 ) ;
F_80 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
F_3 ( F_4 ( V_72 -> V_79 -> V_83 -> V_49 ) ,
V_25 , V_26 | V_27 , V_28 | V_29 | V_30 | V_10 | V_6 ) ;
F_66 ( V_72 -> V_79 -> V_83 -> V_49 , V_72 -> V_79 -> V_83 ) ;
F_10 ( V_58 L_60 , V_72 -> V_79 -> V_83 -> V_167 ) ;
for ( V_70 = 0 ; V_70 < V_56 ; V_70 ++ ) {
if ( F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] != NULL ) {
T_4 * V_43 ;
V_43 = F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] ;
if ( V_43 -> V_79 -> V_163 ) {
continue;
}
F_29 ( V_43 -> V_65 ) ;
V_43 -> V_65 = NULL ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_62 [ V_70 ] = NULL ;
F_24 ( V_72 -> V_79 -> V_83 ) -> V_47 [ V_70 ] . V_57 = 0 ;
}
}
F_81 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
return V_164 ;
V_8:
F_81 ( V_72 -> V_79 -> V_83 -> V_36 ) ;
return V_165 ;
}
static int F_83 ( struct V_169 * V_170 ,
struct V_171 * V_172 , T_5 V_173 , int * V_174 )
{
int V_175 ;
int V_176 = V_173 ;
V_175 = F_24 ( V_170 -> V_83 ) -> V_162 ;
if ( ( V_176 >> 11 ) > 1024 && V_175 == V_118 ) {
V_174 [ 0 ] = 255 ;
V_174 [ 1 ] = 63 ;
V_174 [ 2 ] = V_176 / 255 / 63 ;
} else {
V_174 [ 0 ] = 64 ;
V_174 [ 1 ] = 32 ;
V_174 [ 2 ] = V_176 >> 11 ;
}
return 0 ;
}
