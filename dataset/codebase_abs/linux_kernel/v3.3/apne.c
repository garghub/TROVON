struct V_1 * T_1 F_1 ( int V_2 )
{
struct V_1 * V_3 ;
#ifndef F_2
char V_4 [ 8 ] ;
#endif
int V_5 ;
if ( ! V_6 )
return F_3 ( - V_7 ) ;
if ( V_8 )
return F_3 ( - V_7 ) ;
if ( ! ( F_4 ( V_9 ) ) )
return F_3 ( - V_7 ) ;
F_5 ( L_1 ) ;
if ( ! ( V_10 ) ) {
F_5 ( L_2 ) ;
return F_3 ( - V_7 ) ;
}
V_3 = F_6 () ;
if ( ! V_3 )
return F_3 ( - V_11 ) ;
if ( V_2 >= 0 ) {
sprintf ( V_3 -> V_12 , L_3 , V_2 ) ;
F_7 ( V_3 ) ;
}
F_8 () ;
#ifndef F_2
if ( ( F_9 ( V_13 , V_4 , 8 ) < 3 ) ||
( V_4 [ 2 ] != V_14 ) ) {
F_5 ( L_4 ) ;
F_10 ( V_3 ) ;
return F_3 ( - V_7 ) ;
}
#endif
F_5 ( L_5 ) ;
if ( ! F_11 () ) {
F_10 ( V_3 ) ;
return F_3 ( - V_7 ) ;
}
if ( ! F_12 ( V_15 , 0x20 , V_16 ) ) {
F_10 ( V_3 ) ;
return F_3 ( - V_17 ) ;
}
V_5 = F_13 ( V_3 , V_15 ) ;
if ( V_5 ) {
F_14 ( V_15 , 0x20 ) ;
F_10 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
V_5 = F_15 ( V_3 ) ;
if ( ! V_5 )
return V_3 ;
F_8 () ;
F_16 ( V_18 , V_3 ) ;
F_17 () ;
F_14 ( V_15 , 0x20 ) ;
F_10 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static int T_1 F_13 ( struct V_1 * V_3 , int V_19 )
{
int V_20 ;
unsigned char V_21 [ 32 ] ;
int V_22 = 2 ;
const char * V_12 = NULL ;
int V_23 , V_24 ;
#ifndef F_18
int V_25 , V_26 ;
#endif
static unsigned V_27 ;
if ( V_28 && V_27 ++ == 0 )
F_5 ( V_29 ) ;
F_5 ( L_6 ) ;
{ unsigned long V_30 = V_31 ;
F_19 ( F_20 ( V_19 + V_32 ) , V_19 + V_32 ) ;
while ( ( F_20 ( V_19 + V_33 ) & V_34 ) == 0 )
if ( F_21 ( V_31 , V_30 + 2 * V_35 / 100 ) ) {
F_5 ( L_7 ) ;
return - V_7 ;
}
F_19 ( 0xff , V_19 + V_33 ) ;
}
#ifndef F_18
{
struct { unsigned long V_36 , V_37 ; } V_38 [] = {
{ V_39 + V_40 + V_41 , V_42 } ,
{ 0x48 , V_43 } ,
{ 0x00 , V_44 } ,
{ 0x00 , V_45 } ,
{ 0x00 , V_46 } ,
{ 0xFF , V_33 } ,
{ V_47 , V_48 } ,
{ V_49 , V_50 } ,
{ 32 , V_44 } ,
{ 0x00 , V_45 } ,
{ 0x00 , V_51 } ,
{ 0x00 , V_52 } ,
{ V_53 + V_54 , V_42 } ,
} ;
for ( V_20 = 0 ; V_20 < F_22 ( V_38 ) ; V_20 ++ ) {
F_19 ( V_38 [ V_20 ] . V_36 , V_19 + V_38 [ V_20 ] . V_37 ) ;
}
}
for( V_20 = 0 ; V_20 < 32 ; V_20 += 2 ) {
V_21 [ V_20 ] = F_20 ( V_19 + V_55 ) ;
V_21 [ V_20 + 1 ] = F_20 ( V_19 + V_55 ) ;
if ( V_21 [ V_20 ] != V_21 [ V_20 + 1 ] )
V_22 = 1 ;
}
if ( V_22 == 2 )
for ( V_20 = 0 ; V_20 < 16 ; V_20 ++ )
V_21 [ V_20 ] = V_21 [ V_20 + V_20 ] ;
if ( V_22 == 2 ) {
F_19 ( 0x49 , V_19 + V_43 ) ;
V_23 = V_56 ;
V_24 = V_57 ;
} else {
V_23 = V_58 ;
V_24 = V_59 ;
}
V_25 = ( V_21 [ 14 ] == 0x57 && V_21 [ 15 ] == 0x57 ) ;
V_26 = ( V_21 [ 0 ] == 0x00 && V_21 [ 1 ] == 0x00 && V_21 [ 2 ] == 0x1d ) ;
if ( V_25 ) {
V_12 = ( V_22 == 2 ) ? L_8 : L_9 ;
} else if ( V_26 ) {
V_12 = ( V_22 == 2 ) ? L_10 : L_11 ;
V_23 = 0x01 ;
V_24 = ( V_22 == 2 ) ? 0x40 : 0x20 ;
} else {
F_5 ( L_12 ) ;
return - V_60 ;
}
#else
V_22 = 2 ;
F_19 ( 0x49 , V_19 + V_43 ) ;
V_23 = V_56 ;
V_24 = V_57 ;
V_21 [ 0 ] = F_18 ;
V_21 [ 1 ] = V_61 ;
V_21 [ 2 ] = V_62 ;
V_21 [ 3 ] = V_63 ;
V_21 [ 4 ] = V_64 ;
V_21 [ 5 ] = V_65 ;
V_12 = L_8 ;
#endif
V_3 -> V_66 = V_19 ;
V_3 -> V_67 = V_18 ;
V_3 -> V_68 = & V_69 ;
V_20 = F_23 ( V_3 -> V_67 , V_70 , V_71 , V_16 , V_3 ) ;
if ( V_20 ) return V_20 ;
for ( V_20 = 0 ; V_20 < V_72 ; V_20 ++ )
V_3 -> V_73 [ V_20 ] = V_21 [ V_20 ] ;
F_5 ( L_13 , V_3 -> V_73 ) ;
F_5 ( L_14 , V_3 -> V_12 , V_12 ) ;
V_74 . V_12 = V_12 ;
V_74 . V_75 = V_23 ;
V_74 . V_24 = V_24 ;
V_74 . V_76 = ( V_22 == 2 ) ;
V_74 . V_77 = V_23 + V_78 ;
V_74 . V_79 = & V_80 ;
V_74 . V_81 = & V_82 ;
V_74 . V_83 = & V_84 ;
V_74 . V_85 = & V_86 ;
F_24 ( V_3 , 0 ) ;
F_25 ( F_26 () ) ;
F_27 () ;
V_8 = 1 ;
return 0 ;
}
static void
V_80 ( struct V_1 * V_3 )
{
unsigned long V_30 = V_31 ;
F_11 () ;
if ( V_28 > 1 ) F_5 ( L_15 , V_31 ) ;
F_19 ( F_20 ( V_87 + V_32 ) , V_87 + V_32 ) ;
V_74 . V_88 = 0 ;
V_74 . V_89 = 0 ;
while ( ( F_20 ( V_87 + V_33 ) & V_34 ) == 0 )
if ( F_21 ( V_31 , V_30 + 2 * V_35 / 100 ) ) {
F_5 ( L_16 , V_3 -> V_12 ) ;
break;
}
F_19 ( V_34 , V_87 + V_33 ) ;
}
static void
V_86 ( struct V_1 * V_3 , struct V_90 * V_91 , int V_92 )
{
int V_93 = V_3 -> V_66 ;
int V_94 ;
char * V_95 ;
short * V_96 ;
if ( V_74 . V_89 ) {
F_5 ( L_17
L_18 ,
V_3 -> V_12 , V_74 . V_89 , V_74 . V_97 , V_3 -> V_67 ) ;
return;
}
V_74 . V_89 |= 0x01 ;
F_19 ( V_39 + V_40 + V_54 , V_93 + V_42 ) ;
F_19 ( V_98 , V_93 + V_33 ) ;
F_19 ( sizeof( struct V_90 ) , V_93 + V_44 ) ;
F_19 ( 0 , V_93 + V_45 ) ;
F_19 ( 0 , V_93 + V_51 ) ;
F_19 ( V_92 , V_93 + V_52 ) ;
F_19 ( V_53 + V_54 , V_93 + V_42 ) ;
if ( V_74 . V_76 ) {
V_96 = ( short * ) V_91 ;
for( V_94 = 0 ; V_94 < ( sizeof( struct V_90 ) >> 1 ) ; V_94 ++ )
* V_96 ++ = F_28 ( V_87 + V_55 ) ;
} else {
V_95 = ( char * ) V_91 ;
for( V_94 = 0 ; V_94 < sizeof( struct V_90 ) ; V_94 ++ )
* V_95 ++ = F_20 ( V_87 + V_55 ) ;
}
F_19 ( V_98 , V_93 + V_33 ) ;
V_74 . V_89 &= ~ 0x01 ;
F_29 ( & V_91 -> V_99 ) ;
}
static void
V_82 ( struct V_1 * V_3 , int V_99 , struct V_100 * V_101 , int V_102 )
{
int V_93 = V_3 -> V_66 ;
char * V_103 = V_101 -> V_104 ;
char * V_95 ;
short * V_96 ;
int V_94 ;
if ( V_74 . V_89 ) {
F_5 ( L_19
L_18 ,
V_3 -> V_12 , V_74 . V_89 , V_74 . V_97 , V_3 -> V_67 ) ;
return;
}
V_74 . V_89 |= 0x01 ;
F_19 ( V_39 + V_40 + V_54 , V_93 + V_42 ) ;
F_19 ( V_98 , V_93 + V_33 ) ;
F_19 ( V_99 & 0xff , V_93 + V_44 ) ;
F_19 ( V_99 >> 8 , V_93 + V_45 ) ;
F_19 ( V_102 & 0xff , V_93 + V_51 ) ;
F_19 ( V_102 >> 8 , V_93 + V_52 ) ;
F_19 ( V_53 + V_54 , V_93 + V_42 ) ;
if ( V_74 . V_76 ) {
V_96 = ( short * ) V_103 ;
for ( V_94 = 0 ; V_94 < ( V_99 >> 1 ) ; V_94 ++ )
* V_96 ++ = F_28 ( V_87 + V_55 ) ;
if ( V_99 & 0x01 ) {
V_103 [ V_99 - 1 ] = F_20 ( V_87 + V_55 ) ;
}
} else {
V_95 = ( char * ) V_103 ;
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ )
* V_95 ++ = F_20 ( V_87 + V_55 ) ;
}
F_19 ( V_98 , V_93 + V_33 ) ;
V_74 . V_89 &= ~ 0x01 ;
}
static void
V_84 ( struct V_1 * V_3 , int V_99 ,
const unsigned char * V_103 , const int V_23 )
{
int V_93 = V_87 ;
unsigned long V_105 ;
char * V_95 ;
short * V_96 ;
int V_94 ;
if ( V_74 . V_76 && ( V_99 & 0x01 ) )
V_99 ++ ;
if ( V_74 . V_89 ) {
F_5 ( L_20
L_21 ,
V_3 -> V_12 , V_74 . V_89 , V_74 . V_97 , V_3 -> V_67 ) ;
return;
}
V_74 . V_89 |= 0x01 ;
F_19 ( V_40 + V_54 + V_39 , V_93 + V_42 ) ;
F_19 ( V_98 , V_93 + V_33 ) ;
F_19 ( V_99 & 0xff , V_93 + V_44 ) ;
F_19 ( V_99 >> 8 , V_93 + V_45 ) ;
F_19 ( 0x00 , V_93 + V_51 ) ;
F_19 ( V_23 , V_93 + V_52 ) ;
F_19 ( V_106 + V_54 , V_93 + V_42 ) ;
if ( V_74 . V_76 ) {
V_96 = ( short * ) V_103 ;
for ( V_94 = 0 ; V_94 < V_99 > > 1 ; V_94 ++ )
F_30 ( * V_96 ++ , V_87 + V_55 ) ;
} else {
V_95 = ( char * ) V_103 ;
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ )
F_19 ( * V_95 ++ , V_87 + V_55 ) ;
}
V_105 = V_31 ;
while ( ( F_20 ( V_87 + V_33 ) & V_98 ) == 0 )
if ( F_21 ( V_31 , V_105 + 2 * V_35 / 100 ) ) {
F_5 ( L_22 , V_3 -> V_12 ) ;
V_80 ( V_3 ) ;
F_24 ( V_3 , 1 ) ;
break;
}
F_19 ( V_98 , V_93 + V_33 ) ;
V_74 . V_89 &= ~ 0x01 ;
}
static T_2 V_70 ( int V_67 , void * V_107 )
{
unsigned char V_108 ;
if ( ! ( V_109 . V_110 & V_111 ) )
return V_112 ;
V_108 = F_26 () ;
if ( ! ( V_108 & V_111 ) ) {
F_25 ( V_108 ) ;
return V_112 ;
}
if ( V_28 > 3 )
F_5 ( L_23 , V_108 ) ;
F_8 () ;
F_31 ( V_67 , V_107 ) ;
F_25 ( F_26 () ) ;
F_27 () ;
return V_113 ;
}
static int T_1 F_32 ( void )
{
V_114 = F_1 ( - 1 ) ;
if ( F_33 ( V_114 ) )
return F_34 ( V_114 ) ;
return 0 ;
}
static void T_3 F_35 ( void )
{
F_36 ( V_114 ) ;
F_8 () ;
F_16 ( V_18 , V_114 ) ;
F_17 () ;
F_14 ( V_15 , 0x20 ) ;
F_10 ( V_114 ) ;
}
static int F_11 ( void )
{
T_4 V_115 ;
#ifndef F_2
T_4 V_4 [ 32 ] ;
int V_116 ;
#endif
T_5 V_37 ;
F_17 () ;
F_37 ( V_117 ) ;
F_38 ( V_118 ) ;
F_39 () ;
#ifdef F_2
V_115 = F_2 ;
#else
if ( F_9 ( V_119 , V_4 , 32 ) < 3 )
return 0 ;
V_115 = V_4 [ 2 ] & 0x3f ;
#endif
#ifdef F_40
V_37 = F_40 ;
#else
if ( F_9 ( V_120 , V_4 , 32 ) < 6 )
return 0 ;
V_116 = ( V_4 [ 2 ] & 0x3 ) + 1 ;
V_37 = 0 ;
while( V_116 -- ) {
V_37 = ( V_37 << 8 ) | V_4 [ 4 + V_116 ] ;
}
#endif
F_41 ( V_121 + V_37 , V_115 ) ;
return 1 ;
}
