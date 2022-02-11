static inline struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_1 V_7 ;
V_7 = V_4 - V_6 -> V_8 ;
return (struct V_1 * ) ( ( ( char * ) V_6 -> V_1 ) + ( unsigned int ) V_7 ) ;
}
static inline T_1 F_3 ( struct V_2 * V_3 , void * V_9 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_1 V_7 ;
V_7 = ( char * ) V_9 - ( char * ) V_6 -> V_1 ;
return V_6 -> V_8 + V_7 ;
}
static int F_4 ( struct V_2 * V_10 , char * V_11 ,
char * * V_12 , T_2 V_7 ,
int V_13 , int V_14 )
{
int V_15 ;
struct V_5 * V_3 ;
if ( V_14 )
return - V_16 ;
V_3 = F_2 ( V_10 ) ;
V_15 = sprintf ( V_11 , L_1
L_2 ,
V_10 -> V_17 , V_10 -> V_18 , V_3 -> V_19 -> V_20 ,
V_3 -> V_21 ? L_3 : L_4 ) ;
if ( V_7 > V_15 ) {
* V_12 = V_11 ;
return 0 ;
}
* V_12 = V_11 + V_7 ;
V_15 -= V_7 ;
if ( V_15 > V_13 )
V_15 = V_13 ;
return V_15 ;
}
static int F_5 ( T_3 * V_22 , T_3 * V_23 )
{
struct V_24
{
T_4 V_25 : 1 ,
V_26 : 1 ,
: 1 , V_27 : 1 ,
V_28 : 1 ,
V_29 : 1 ,
V_30 : 1 ,
V_31 : 1 ,
V_32 : 1 ,
V_33 : 1 ,
: 1 , V_34 : 1 ,
V_35 : 1 ,
: 1 , V_36 : 1 ,
: 1 ;
} V_37 ;
int V_38 = V_39 ;
V_37 = * (struct V_24 * ) V_23 ;
#ifdef F_6
F_7 ( L_5 ,
V_23 [ 0 ] , V_23 [ 1 ] , V_23 [ 2 ] , V_23 [ 3 ] ,
V_22 [ 0 ] , V_22 [ 1 ] , V_22 [ 2 ] , V_22 [ 3 ] ) ;
#endif
if ( ! V_37 . V_25 ) {
if ( ( V_23 [ 1 ] & 0x18 ) || V_37 . V_28 ) {
switch ( V_23 [ 2 ] ) {
case 0x12 :
if ( V_37 . V_29 )
V_38 = V_40 ;
case 0x00 :
break;
case 0x11 :
case 0x21 :
V_38 = V_41 ;
break;
case 0x0a :
V_38 = V_42 ;
break;
case 0x04 :
case 0x05 :
V_38 = V_43 ;
break;
default:
V_38 = V_40 ;
}
} else {
if ( V_37 . V_27 ) {
V_38 = V_41 ;
F_7 ( L_6 ) ;
} else
if ( V_23 [ 0 ] & 0x60 ) {
V_38 = V_40 ;
}
}
}
return V_23 [ 3 ] | V_38 << 16 ;
}
static int F_8 ( unsigned int V_44 )
{
if ( F_9 ( F_10 ( V_44 ) ) & V_45 )
return 1 ;
F_7 ( L_7 ) ;
return 0 ;
}
static T_5 F_11 ( int V_18 , void * V_46 )
{
struct V_2 * V_3 = (struct V_2 * ) V_46 ;
void (* F_12)( T_6 * );
int V_47 , V_48 ;
int V_49 ;
struct V_1 * V_50 ;
T_6 * V_51 ;
unsigned int V_44 ;
unsigned long V_52 ;
int V_53 = 0 ;
struct V_54 * V_55 ;
struct V_56 * V_19 ;
if ( ! V_3 )
F_13 ( L_8 ) ;
F_14 ( V_3 -> V_57 , V_52 ) ;
V_44 = V_3 -> V_17 ;
V_49 = 0 ;
V_19 = F_2 ( V_3 ) -> V_19 ;
while( F_9 ( F_15 ( V_44 ) ) & V_58 ) {
V_53 = 1 ;
F_16 ( F_7 ( L_9 ) ) ;
V_48 = F_9 ( F_17 ( V_44 ) ) ;
V_50 = F_1 ( V_3 , F_18 ( F_19 ( V_44 ) ) ) ;
F_20 ( V_59 , F_21 ( V_44 ) ) ;
switch ( V_48 & V_60 ) {
case V_61 :
case V_62 :
case V_63 :
F_20 ( V_64 , F_21 ( V_44 ) ) ;
if ( ! V_50 ) {
F_7 ( L_10 ,
F_9 ( F_15 ( V_44 ) ) , V_48 ,
F_9 ( F_17 ( V_44 ) ) , V_49 ++ ) ;
continue;
}
V_51 = V_50 -> V_65 ;
if ( ! V_51 ) {
F_7 ( L_11 ,
F_9 ( F_15 ( V_44 ) ) , V_48 ,
F_9 ( F_17 ( V_44 ) ) , V_49 ++ ) ;
continue;
}
V_55 = (struct V_54 * ) V_51 -> V_66 ;
F_22 ( V_51 ) ;
F_23 ( & V_19 -> V_67 ,
sizeof ( struct V_54 ) ,
V_51 -> V_66 ,
V_55 -> V_68 ) ;
if ( ( V_48 & V_60 ) == V_62 ) {
memcpy ( V_51 -> V_69 , V_50 -> V_22 ,
V_70 ) ;
V_47 = F_5 ( V_50 -> V_22 , V_50 -> V_23 ) ;
} else
V_47 = 0 ;
F_16 (if (errstatus)
printk(L_12,
errstatus)) ;
V_51 -> V_71 = V_47 ;
F_12 = V_50 -> V_72 ;
memset ( V_50 , 0 , sizeof( struct V_1 ) ) ;
if ( F_12 )
F_12 ( V_51 ) ;
break;
case V_73 :
F_7 ( V_74 L_13 ) ;
F_13 ( L_14 ) ;
case V_75 :
F_7 ( L_15 ,
V_48 ,
F_9 ( F_19 ( V_44 ) ) ,
F_9 ( F_24 ( V_44 ) ) ,
F_9 ( F_25 ( V_44 ) ) ,
F_9 ( F_26 ( V_44 ) ) ) ;
F_20 ( V_64 , F_21 ( V_44 ) ) ;
break;
case V_76 :
break;
case V_77 :
break;
}
V_49 ++ ;
}
F_27 ( V_3 -> V_57 , V_52 ) ;
return F_28 ( V_53 ) ;
}
static int F_29 ( T_6 * V_65 , void (* V_72)( T_6 * ) )
{
T_3 V_78 ;
T_3 * V_79 = ( T_3 * ) V_65 -> V_80 ;
T_3 V_81 = F_30 ( V_65 ) ;
struct V_5 * V_3 = F_2 ( V_65 -> V_82 -> V_3 ) ;
unsigned long V_52 ;
T_1 V_83 ;
struct V_54 * V_55 ;
int V_84 , V_85 ;
F_16 (int i) ;
if( * V_79 == V_86 ) {
V_65 -> V_71 = 0 ;
V_72 ( V_65 ) ;
return 0 ;
}
#ifdef F_6
if ( * V_79 == V_87 || * V_79 == V_88 )
V_89 = F_31 ( V_79 + 2 ) ;
else if ( * V_79 == V_90 || * V_79 == V_91 )
V_89 = F_32 ( V_79 + 2 ) ;
else
V_89 = - 1 ;
F_7 ( L_16 ,
V_81 , * V_79 , V_89 , V_92 ) ;
F_7 ( L_17 ) ;
for ( V_89 = 0 ; V_89 < V_65 -> V_93 ; V_89 ++ ) F_7 ( L_18 , V_79 [ V_89 ] ) ;
F_7 ( L_19 ) ;
#endif
F_14 ( V_65 -> V_82 -> V_3 -> V_57 , V_52 ) ;
V_84 = V_3 -> V_94 + 1 ;
if ( V_84 >= V_95 )
V_84 = 0 ;
do {
if ( ! V_3 -> V_1 [ V_84 ] . V_96 )
break;
V_84 ++ ;
if ( V_84 >= V_95 )
V_84 = 0 ;
} while ( V_84 != V_3 -> V_94 );
if ( V_3 -> V_1 [ V_84 ] . V_96 )
F_13 ( L_20 ) ;
V_3 -> V_1 [ V_84 ] . V_96 = V_97 ;
V_3 -> V_94 = V_84 ;
F_27 ( V_65 -> V_82 -> V_3 -> V_57 , V_52 ) ;
#ifdef F_6
F_7 ( L_21 , V_84 , V_72 ) ;
#endif
V_3 -> V_1 [ V_84 ] . V_98 = V_65 -> V_93 ;
V_78 = 0 ;
if ( * V_79 == V_87 || * V_79 == V_90 )
V_78 = 1 ;
else if ( * V_79 == V_88 || * V_79 == V_91 )
V_78 = 0 ;
memcpy ( V_3 -> V_1 [ V_84 ] . V_99 , V_79 , V_65 -> V_93 ) ;
V_65 -> V_66 = F_33 ( & V_3 -> V_19 -> V_67 ,
sizeof ( struct V_54 ) ,
& V_83 , V_100 ) ;
if( V_65 -> V_66 == NULL ) {
F_7 ( V_101 L_22 ) ;
return 1 ;
}
V_55 = (struct V_54 * ) V_65 -> V_66 ;
V_55 -> V_68 = V_83 ;
V_85 = F_34 ( V_65 ) ;
F_35 ( V_85 < 0 ) ;
if ( V_85 ) {
struct V_102 * V_103 ;
struct V_104 * V_105 ;
int V_89 ;
F_16 (unsigned char * ptr) ;
V_3 -> V_1 [ V_84 ] . V_103 = 1 ;
V_105 = V_55 -> V_106 ;
F_36 (SCpnt, sg, nseg, i) {
V_105 [ V_89 ] . V_107 = F_37 ( V_103 ) ;
V_105 [ V_89 ] . V_108 = F_38 ( V_103 ) ;
}
V_3 -> V_1 [ V_84 ] . V_107 = V_85 * sizeof( struct V_104 ) ;
V_3 -> V_1 [ V_84 ] . V_108 = V_83 ;
#ifdef F_6
F_7 ( L_23 , V_105 ) ;
V_109 = ( unsigned char * ) V_105 ;
for( V_89 = 0 ; V_89 < 24 ; V_89 ++ ) F_7 ( L_18 , V_109 [ V_89 ] ) ;
#endif
} else {
V_3 -> V_1 [ V_84 ] . V_107 = 0 ;
V_3 -> V_1 [ V_84 ] . V_108 = 0 ;
}
V_3 -> V_1 [ V_84 ] . V_110 = V_65 -> V_82 -> V_110 ;
V_3 -> V_1 [ V_84 ] . V_111 = 1 ;
V_3 -> V_1 [ V_84 ] . V_112 = V_78 ;
V_3 -> V_1 [ V_84 ] . V_113 = 1 ;
V_3 -> V_1 [ V_84 ] . V_114 = 12 ;
V_3 -> V_1 [ V_84 ] . V_115 = F_3 ( V_65 -> V_82 -> V_3 ,
V_3 -> V_1 [ V_84 ] . V_22 ) ;
V_3 -> V_1 [ V_84 ] . V_116 = F_3 ( V_65 -> V_82 -> V_3 ,
V_3 -> V_1 [ V_84 ] . V_23 ) ;
V_3 -> V_1 [ V_84 ] . V_72 = V_72 ;
V_3 -> V_1 [ V_84 ] . V_65 = V_65 ;
#ifdef F_6
{
int V_89 ;
F_7 ( L_24 ) ;
for ( V_89 = 0 ; V_89 < sizeof( V_3 -> V_1 [ V_84 ] ) - 10 ; V_89 ++ )
F_7 ( L_18 , ( ( T_3 * ) & V_3 -> V_1 [ V_84 ] ) [ V_89 ] ) ;
}
F_7 ( L_19 ) ;
#endif
if ( V_72 ) {
#define F_39 10
#define F_40 1000000
int V_117 ;
unsigned int V_44 = V_65 -> V_82 -> V_3 -> V_17 ;
F_16 ( F_7 ( L_25 , V_84 ) ) ;
F_14 ( V_65 -> V_82 -> V_3 -> V_57 , V_52 ) ;
for ( V_117 = 0 ; ; V_117 ++ ) {
if ( F_9 ( F_15 ( V_44 ) ) & V_118 ) break;
if ( V_117 == F_39 ) {
F_7 ( L_26 , V_84 ) ;
}
if ( V_117 == F_40 )
F_13 ( L_27 ) ;
}
F_41 ( F_3 ( V_65 -> V_82 -> V_3 , V_3 -> V_1 + V_84 ) ,
F_42 ( V_44 ) ) ;
for ( V_117 = 0 ; ; V_117 ++ ) {
if ( ! ( F_9 ( F_15 ( V_44 ) ) & V_119 ) ) break;
if ( V_117 == F_39 ) {
F_7 ( L_28 , V_84 ) ;
}
if ( V_117 == F_40 )
F_13 ( L_29 ) ;
}
F_20 ( V_120 | ( V_81 & 7 ) , F_43 ( V_44 ) ) ;
F_27 ( V_65 -> V_82 -> V_3 -> V_57 , V_52 ) ;
F_16 ( F_7 ( L_30 , V_84 ) ) ;
} else
F_7 ( V_74 L_31 ) ;
return 0 ;
}
int F_44 ( T_6 * V_121 )
{
return 0 ;
}
static int F_45 ( struct V_82 * V_67 )
{
int V_122 , V_123 ;
unsigned int V_124 , V_125 , V_21 ;
struct V_2 * V_10 ;
struct V_5 * V_3 ;
struct V_56 * V_19 = F_46 ( V_67 ) ;
F_16 ( F_7 ( L_32 ) ) ;
V_122 = V_19 -> V_126 + V_127 ;
if ( ! F_47 ( V_122 , V_128 , L_33 ) )
return - V_129 ;
if ( ! F_8 ( V_122 ) )
goto V_130;
F_48 ( V_122 , & V_124 , & V_125 , & V_21 ) ;
if ( ( F_9 ( F_15 ( V_122 ) ) &
( V_118 | V_119 ) ) != V_118 ) {
F_20 ( V_131 , F_21 ( V_122 ) ) ;
F_20 ( 0 , F_21 ( V_122 ) ) ;
}
F_7 ( V_132 L_34 ,
V_19 -> V_20 , V_122 , V_124 , V_125 ? L_35 : L_36 ) ;
F_7 ( V_132 L_37 ,
V_21 ? L_3 : L_4 ) ;
V_10 = F_49 ( & V_133 ,
sizeof( struct V_5 ) ) ;
if( V_10 == NULL )
goto V_130;
V_10 -> V_44 = 0 ;
V_10 -> V_17 = V_122 ;
V_10 -> V_134 = V_128 ;
V_10 -> V_18 = V_124 ;
V_10 -> V_135 = 0xff ;
V_3 = F_2 ( V_10 ) ;
V_3 -> V_19 = V_19 ;
V_3 -> V_21 = V_21 ;
V_3 -> V_8 = F_50 ( & V_19 -> V_67 , V_3 -> V_1 ,
sizeof ( V_3 -> V_1 ) ,
V_136 ) ;
if ( ! V_3 -> V_8 ) {
F_7 ( V_137 L_38 ) ;
F_51 ( V_10 ) ;
goto V_138;
}
F_16 ( F_7 ( L_39 , V_124 ) ) ;
if ( F_52 ( V_124 , F_11 , V_125 ? 0 : V_139 ,
L_33 , V_10 ) ) {
F_7 ( V_137 L_40 ,
V_124 ) ;
goto V_140;
}
F_53 ( V_19 , V_10 ) ;
V_123 = F_54 ( V_10 , V_67 ) ;
if ( V_123 )
goto V_141;
F_55 ( V_10 ) ;
return 0 ;
V_141:
F_56 ( V_124 , V_10 ) ;
V_140:
F_57 ( & V_19 -> V_67 , V_3 -> V_8 ,
sizeof ( V_3 -> V_1 ) , V_136 ) ;
V_138:
F_58 ( V_10 ) ;
V_130:
F_59 ( V_122 , V_128 ) ;
return - V_142 ;
}
static int F_60 ( struct V_82 * V_67 )
{
struct V_2 * V_10 = F_61 ( V_67 ) ;
struct V_5 * V_3 = F_2 ( V_10 ) ;
F_62 ( V_10 ) ;
F_56 ( V_10 -> V_18 , V_10 ) ;
F_57 ( V_67 , V_3 -> V_8 ,
sizeof ( V_3 -> V_1 ) , V_136 ) ;
F_59 ( V_10 -> V_17 , V_128 ) ;
F_58 ( V_10 ) ;
return 0 ;
}
static T_7 int F_63 ( void )
{
return F_64 ( & V_143 ) ;
}
static T_8 void F_65 ( void )
{
F_66 ( & V_143 ) ;
}
