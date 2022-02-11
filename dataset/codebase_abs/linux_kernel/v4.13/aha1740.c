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
static int F_4 ( struct V_10 * V_11 , struct V_2 * V_12 )
{
struct V_5 * V_3 = F_2 ( V_12 ) ;
F_5 ( V_11 , L_1
L_2 ,
V_12 -> V_13 , V_12 -> V_14 , V_3 -> V_15 -> V_16 ,
V_3 -> V_17 ? L_3 : L_4 ) ;
return 0 ;
}
static int F_6 ( T_2 * V_18 , T_2 * V_19 )
{
struct V_20
{
T_3 V_21 : 1 ,
V_22 : 1 ,
: 1 , V_23 : 1 ,
V_24 : 1 ,
V_25 : 1 ,
V_26 : 1 ,
V_27 : 1 ,
V_28 : 1 ,
V_29 : 1 ,
: 1 , V_30 : 1 ,
V_31 : 1 ,
: 1 , V_32 : 1 ,
: 1 ;
} V_33 ;
int V_34 = V_35 ;
V_33 = * (struct V_20 * ) V_19 ;
#ifdef F_7
F_8 ( L_5 ,
V_19 [ 0 ] , V_19 [ 1 ] , V_19 [ 2 ] , V_19 [ 3 ] ,
V_18 [ 0 ] , V_18 [ 1 ] , V_18 [ 2 ] , V_18 [ 3 ] ) ;
#endif
if ( ! V_33 . V_21 ) {
if ( ( V_19 [ 1 ] & 0x18 ) || V_33 . V_24 ) {
switch ( V_19 [ 2 ] ) {
case 0x12 :
if ( V_33 . V_25 )
V_34 = V_36 ;
case 0x00 :
break;
case 0x11 :
case 0x21 :
V_34 = V_37 ;
break;
case 0x0a :
V_34 = V_38 ;
break;
case 0x04 :
case 0x05 :
V_34 = V_39 ;
break;
default:
V_34 = V_36 ;
}
} else {
if ( V_33 . V_23 ) {
V_34 = V_37 ;
F_8 ( L_6 ) ;
} else
if ( V_19 [ 0 ] & 0x60 ) {
V_34 = V_36 ;
}
}
}
return V_19 [ 3 ] | V_34 << 16 ;
}
static int F_9 ( unsigned int V_40 )
{
if ( F_10 ( F_11 ( V_40 ) ) & V_41 )
return 1 ;
F_8 ( L_7 ) ;
return 0 ;
}
static T_4 F_12 ( int V_14 , void * V_42 )
{
struct V_2 * V_3 = (struct V_2 * ) V_42 ;
void (* F_13)( T_5 * );
int V_43 , V_44 ;
int V_45 ;
struct V_1 * V_46 ;
T_5 * V_47 ;
unsigned int V_40 ;
unsigned long V_48 ;
int V_49 = 0 ;
struct V_50 * V_51 ;
struct V_52 * V_15 ;
if ( ! V_3 )
F_14 ( L_8 ) ;
F_15 ( V_3 -> V_53 , V_48 ) ;
V_40 = V_3 -> V_13 ;
V_45 = 0 ;
V_15 = F_2 ( V_3 ) -> V_15 ;
while( F_10 ( F_16 ( V_40 ) ) & V_54 ) {
V_49 = 1 ;
F_17 ( F_8 ( L_9 ) ) ;
V_44 = F_10 ( F_18 ( V_40 ) ) ;
V_46 = F_1 ( V_3 , F_19 ( F_20 ( V_40 ) ) ) ;
F_21 ( V_55 , F_22 ( V_40 ) ) ;
switch ( V_44 & V_56 ) {
case V_57 :
case V_58 :
case V_59 :
F_21 ( V_60 , F_22 ( V_40 ) ) ;
if ( ! V_46 ) {
F_8 ( L_10 ,
F_10 ( F_16 ( V_40 ) ) , V_44 ,
F_10 ( F_18 ( V_40 ) ) , V_45 ++ ) ;
continue;
}
V_47 = V_46 -> V_61 ;
if ( ! V_47 ) {
F_8 ( L_11 ,
F_10 ( F_16 ( V_40 ) ) , V_44 ,
F_10 ( F_18 ( V_40 ) ) , V_45 ++ ) ;
continue;
}
V_51 = (struct V_50 * ) V_47 -> V_62 ;
F_23 ( V_47 ) ;
F_24 ( & V_15 -> V_63 ,
sizeof ( struct V_50 ) ,
V_47 -> V_62 ,
V_51 -> V_64 ) ;
if ( ( V_44 & V_56 ) == V_58 ) {
memcpy ( V_47 -> V_65 , V_46 -> V_18 ,
V_66 ) ;
V_43 = F_6 ( V_46 -> V_18 , V_46 -> V_19 ) ;
} else
V_43 = 0 ;
F_17 (if (errstatus)
printk(L_12,
errstatus)) ;
V_47 -> V_67 = V_43 ;
F_13 = V_46 -> V_68 ;
memset ( V_46 , 0 , sizeof( struct V_1 ) ) ;
if ( F_13 )
F_13 ( V_47 ) ;
break;
case V_69 :
F_8 ( V_70 L_13 ) ;
F_14 ( L_14 ) ;
case V_71 :
F_8 ( L_15 ,
V_44 ,
F_10 ( F_20 ( V_40 ) ) ,
F_10 ( F_25 ( V_40 ) ) ,
F_10 ( F_26 ( V_40 ) ) ,
F_10 ( F_27 ( V_40 ) ) ) ;
F_21 ( V_60 , F_22 ( V_40 ) ) ;
break;
case V_72 :
break;
case V_73 :
break;
}
V_45 ++ ;
}
F_28 ( V_3 -> V_53 , V_48 ) ;
return F_29 ( V_49 ) ;
}
static int F_30 ( T_5 * V_61 , void (* V_68)( T_5 * ) )
{
T_2 V_74 ;
T_2 * V_75 = ( T_2 * ) V_61 -> V_76 ;
T_2 V_77 = F_31 ( V_61 ) ;
struct V_5 * V_3 = F_2 ( V_61 -> V_78 -> V_3 ) ;
unsigned long V_48 ;
T_1 V_79 ;
struct V_50 * V_51 ;
int V_80 , V_81 ;
F_17 (int i) ;
if( * V_75 == V_82 ) {
V_61 -> V_67 = 0 ;
V_68 ( V_61 ) ;
return 0 ;
}
#ifdef F_7
if ( * V_75 == V_83 || * V_75 == V_84 )
V_85 = F_32 ( V_75 + 2 ) ;
else if ( * V_75 == V_86 || * V_75 == V_87 )
V_85 = F_33 ( V_75 + 2 ) ;
else
V_85 = - 1 ;
F_8 ( L_16 ,
V_77 , * V_75 , V_85 , V_88 ) ;
F_8 ( L_17 ) ;
for ( V_85 = 0 ; V_85 < V_61 -> V_89 ; V_85 ++ ) F_8 ( L_18 , V_75 [ V_85 ] ) ;
F_8 ( L_19 ) ;
#endif
F_15 ( V_61 -> V_78 -> V_3 -> V_53 , V_48 ) ;
V_80 = V_3 -> V_90 + 1 ;
if ( V_80 >= V_91 )
V_80 = 0 ;
do {
if ( ! V_3 -> V_1 [ V_80 ] . V_92 )
break;
V_80 ++ ;
if ( V_80 >= V_91 )
V_80 = 0 ;
} while ( V_80 != V_3 -> V_90 );
if ( V_3 -> V_1 [ V_80 ] . V_92 )
F_14 ( L_20 ) ;
V_3 -> V_1 [ V_80 ] . V_92 = V_93 ;
V_3 -> V_90 = V_80 ;
F_28 ( V_61 -> V_78 -> V_3 -> V_53 , V_48 ) ;
#ifdef F_7
F_8 ( L_21 , V_80 , V_68 ) ;
#endif
V_3 -> V_1 [ V_80 ] . V_94 = V_61 -> V_89 ;
V_74 = 0 ;
if ( * V_75 == V_83 || * V_75 == V_86 )
V_74 = 1 ;
else if ( * V_75 == V_84 || * V_75 == V_87 )
V_74 = 0 ;
memcpy ( V_3 -> V_1 [ V_80 ] . V_95 , V_75 , V_61 -> V_89 ) ;
V_61 -> V_62 = F_34 ( & V_3 -> V_15 -> V_63 ,
sizeof ( struct V_50 ) ,
& V_79 , V_96 ) ;
if( V_61 -> V_62 == NULL ) {
F_8 ( V_97 L_22 ) ;
return 1 ;
}
V_51 = (struct V_50 * ) V_61 -> V_62 ;
V_51 -> V_64 = V_79 ;
V_81 = F_35 ( V_61 ) ;
F_36 ( V_81 < 0 ) ;
if ( V_81 ) {
struct V_98 * V_99 ;
struct V_100 * V_101 ;
int V_85 ;
F_17 (unsigned char * ptr) ;
V_3 -> V_1 [ V_80 ] . V_99 = 1 ;
V_101 = V_51 -> V_102 ;
F_37 (SCpnt, sg, nseg, i) {
V_101 [ V_85 ] . V_103 = F_38 ( V_99 ) ;
V_101 [ V_85 ] . V_104 = F_39 ( V_99 ) ;
}
V_3 -> V_1 [ V_80 ] . V_103 = V_81 * sizeof( struct V_100 ) ;
V_3 -> V_1 [ V_80 ] . V_104 = V_79 ;
#ifdef F_7
F_8 ( L_23 , V_101 ) ;
V_105 = ( unsigned char * ) V_101 ;
for( V_85 = 0 ; V_85 < 24 ; V_85 ++ ) F_8 ( L_18 , V_105 [ V_85 ] ) ;
#endif
} else {
V_3 -> V_1 [ V_80 ] . V_103 = 0 ;
V_3 -> V_1 [ V_80 ] . V_104 = 0 ;
}
V_3 -> V_1 [ V_80 ] . V_106 = V_61 -> V_78 -> V_106 ;
V_3 -> V_1 [ V_80 ] . V_107 = 1 ;
V_3 -> V_1 [ V_80 ] . V_108 = V_74 ;
V_3 -> V_1 [ V_80 ] . V_109 = 1 ;
V_3 -> V_1 [ V_80 ] . V_110 = 12 ;
V_3 -> V_1 [ V_80 ] . V_111 = F_3 ( V_61 -> V_78 -> V_3 ,
V_3 -> V_1 [ V_80 ] . V_18 ) ;
V_3 -> V_1 [ V_80 ] . V_112 = F_3 ( V_61 -> V_78 -> V_3 ,
V_3 -> V_1 [ V_80 ] . V_19 ) ;
V_3 -> V_1 [ V_80 ] . V_68 = V_68 ;
V_3 -> V_1 [ V_80 ] . V_61 = V_61 ;
#ifdef F_7
{
int V_85 ;
F_8 ( L_24 ) ;
for ( V_85 = 0 ; V_85 < sizeof( V_3 -> V_1 [ V_80 ] ) - 10 ; V_85 ++ )
F_8 ( L_18 , ( ( T_2 * ) & V_3 -> V_1 [ V_80 ] ) [ V_85 ] ) ;
}
F_8 ( L_19 ) ;
#endif
if ( V_68 ) {
#define F_40 10
#define F_41 1000000
int V_113 ;
unsigned int V_40 = V_61 -> V_78 -> V_3 -> V_13 ;
F_17 ( F_8 ( L_25 , V_80 ) ) ;
F_15 ( V_61 -> V_78 -> V_3 -> V_53 , V_48 ) ;
for ( V_113 = 0 ; ; V_113 ++ ) {
if ( F_10 ( F_16 ( V_40 ) ) & V_114 ) break;
if ( V_113 == F_40 ) {
F_8 ( L_26 , V_80 ) ;
}
if ( V_113 == F_41 )
F_14 ( L_27 ) ;
}
F_42 ( F_3 ( V_61 -> V_78 -> V_3 , V_3 -> V_1 + V_80 ) ,
F_43 ( V_40 ) ) ;
for ( V_113 = 0 ; ; V_113 ++ ) {
if ( ! ( F_10 ( F_16 ( V_40 ) ) & V_115 ) ) break;
if ( V_113 == F_40 ) {
F_8 ( L_28 , V_80 ) ;
}
if ( V_113 == F_41 )
F_14 ( L_29 ) ;
}
F_21 ( V_116 | ( V_77 & 7 ) , F_44 ( V_40 ) ) ;
F_28 ( V_61 -> V_78 -> V_3 -> V_53 , V_48 ) ;
F_17 ( F_8 ( L_30 , V_80 ) ) ;
} else
F_8 ( V_70 L_31 ) ;
return 0 ;
}
int F_45 ( T_5 * V_117 )
{
return V_118 ;
}
static int F_46 ( struct V_78 * V_63 )
{
int V_119 , V_120 ;
unsigned int V_121 , V_122 , V_17 ;
struct V_2 * V_12 ;
struct V_5 * V_3 ;
struct V_52 * V_15 = F_47 ( V_63 ) ;
F_17 ( F_8 ( L_32 ) ) ;
V_119 = V_15 -> V_123 + V_124 ;
if ( ! F_48 ( V_119 , V_125 , L_33 ) )
return - V_126 ;
if ( ! F_9 ( V_119 ) )
goto V_127;
F_49 ( V_119 , & V_121 , & V_122 , & V_17 ) ;
if ( ( F_10 ( F_16 ( V_119 ) ) &
( V_114 | V_115 ) ) != V_114 ) {
F_21 ( V_128 , F_22 ( V_119 ) ) ;
F_21 ( 0 , F_22 ( V_119 ) ) ;
}
F_8 ( V_129 L_34 ,
V_15 -> V_16 , V_119 , V_121 , V_122 ? L_35 : L_36 ) ;
F_8 ( V_129 L_37 ,
V_17 ? L_3 : L_4 ) ;
V_12 = F_50 ( & V_130 ,
sizeof( struct V_5 ) ) ;
if( V_12 == NULL )
goto V_127;
V_12 -> V_40 = 0 ;
V_12 -> V_13 = V_119 ;
V_12 -> V_131 = V_125 ;
V_12 -> V_14 = V_121 ;
V_12 -> V_132 = 0xff ;
V_3 = F_2 ( V_12 ) ;
V_3 -> V_15 = V_15 ;
V_3 -> V_17 = V_17 ;
V_3 -> V_8 = F_51 ( & V_15 -> V_63 , V_3 -> V_1 ,
sizeof ( V_3 -> V_1 ) ,
V_133 ) ;
if ( ! V_3 -> V_8 ) {
F_8 ( V_134 L_38 ) ;
F_52 ( V_12 ) ;
goto V_135;
}
F_17 ( F_8 ( L_39 , V_121 ) ) ;
if ( F_53 ( V_121 , F_12 , V_122 ? 0 : V_136 ,
L_33 , V_12 ) ) {
F_8 ( V_134 L_40 ,
V_121 ) ;
goto V_137;
}
F_54 ( V_15 , V_12 ) ;
V_120 = F_55 ( V_12 , V_63 ) ;
if ( V_120 )
goto V_138;
F_56 ( V_12 ) ;
return 0 ;
V_138:
F_57 ( V_121 , V_12 ) ;
V_137:
F_58 ( & V_15 -> V_63 , V_3 -> V_8 ,
sizeof ( V_3 -> V_1 ) , V_133 ) ;
V_135:
F_59 ( V_12 ) ;
V_127:
F_60 ( V_119 , V_125 ) ;
return - V_139 ;
}
static int F_61 ( struct V_78 * V_63 )
{
struct V_2 * V_12 = F_62 ( V_63 ) ;
struct V_5 * V_3 = F_2 ( V_12 ) ;
F_63 ( V_12 ) ;
F_57 ( V_12 -> V_14 , V_12 ) ;
F_58 ( V_63 , V_3 -> V_8 ,
sizeof ( V_3 -> V_1 ) , V_133 ) ;
F_60 ( V_12 -> V_13 , V_125 ) ;
F_59 ( V_12 ) ;
return 0 ;
}
static T_6 int F_64 ( void )
{
return F_65 ( & V_140 ) ;
}
static T_7 void F_66 ( void )
{
F_67 ( & V_140 ) ;
}
