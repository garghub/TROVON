struct V_1 * T_1 F_1 ( int V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 ;
#ifndef F_2
char V_6 [ 8 ] ;
#endif
int V_7 ;
if ( ! V_8 )
return F_3 ( - V_9 ) ;
if ( V_10 )
return F_3 ( - V_9 ) ;
if ( ! ( F_4 ( V_11 ) ) )
return F_3 ( - V_9 ) ;
F_5 ( L_1 ) ;
if ( ! ( V_12 ) ) {
F_6 ( L_2 ) ;
return F_3 ( - V_9 ) ;
}
V_3 = F_7 () ;
if ( ! V_3 )
return F_3 ( - V_13 ) ;
if ( V_2 >= 0 ) {
sprintf ( V_3 -> V_14 , L_3 , V_2 ) ;
F_8 ( V_3 ) ;
}
V_5 = F_9 ( V_3 ) ;
V_5 -> V_15 = V_16 ;
F_10 () ;
#ifndef F_2
if ( ( F_11 ( V_17 , V_6 , 8 ) < 3 ) ||
( V_6 [ 2 ] != V_18 ) ) {
F_6 ( L_4 ) ;
F_12 ( V_3 ) ;
return F_3 ( - V_9 ) ;
}
#endif
F_6 ( L_5 ) ;
if ( ! F_13 () ) {
F_12 ( V_3 ) ;
return F_3 ( - V_9 ) ;
}
if ( ! F_14 ( V_19 , 0x20 , V_20 ) ) {
F_12 ( V_3 ) ;
return F_3 ( - V_21 ) ;
}
V_7 = F_15 ( V_3 , V_19 ) ;
if ( V_7 ) {
F_16 ( V_19 , 0x20 ) ;
F_12 ( V_3 ) ;
return F_3 ( V_7 ) ;
}
V_7 = F_17 ( V_3 ) ;
if ( ! V_7 )
return V_3 ;
F_10 () ;
F_18 ( V_22 , V_3 ) ;
F_19 () ;
F_16 ( V_19 , 0x20 ) ;
F_12 ( V_3 ) ;
return F_3 ( V_7 ) ;
}
static int T_1 F_15 ( struct V_1 * V_3 , int V_23 )
{
int V_24 ;
unsigned char V_25 [ 32 ] ;
int V_26 = 2 ;
const char * V_14 = NULL ;
int V_27 , V_28 ;
#ifndef F_20
int V_29 , V_30 ;
#endif
static unsigned V_31 ;
if ( ( V_16 & V_32 ) && ( V_31 ++ == 0 ) )
F_21 ( V_3 , V_33 ) ;
F_21 ( V_3 , L_6 ) ;
{ unsigned long V_34 = V_35 ;
F_22 ( F_23 ( V_23 + V_36 ) , V_23 + V_36 ) ;
while ( ( F_23 ( V_23 + V_37 ) & V_38 ) == 0 )
if ( F_24 ( V_35 , V_34 + 2 * V_39 / 100 ) ) {
F_6 ( L_7 ) ;
return - V_9 ;
}
F_22 ( 0xff , V_23 + V_37 ) ;
}
#ifndef F_20
{
struct { unsigned long V_40 , V_41 ; } V_42 [] = {
{ V_43 + V_44 + V_45 , V_46 } ,
{ 0x48 , V_47 } ,
{ 0x00 , V_48 } ,
{ 0x00 , V_49 } ,
{ 0x00 , V_50 } ,
{ 0xFF , V_37 } ,
{ V_51 , V_52 } ,
{ V_53 , V_54 } ,
{ 32 , V_48 } ,
{ 0x00 , V_49 } ,
{ 0x00 , V_55 } ,
{ 0x00 , V_56 } ,
{ V_57 + V_58 , V_46 } ,
} ;
for ( V_24 = 0 ; V_24 < F_25 ( V_42 ) ; V_24 ++ ) {
F_22 ( V_42 [ V_24 ] . V_40 , V_23 + V_42 [ V_24 ] . V_41 ) ;
}
}
for( V_24 = 0 ; V_24 < 32 ; V_24 += 2 ) {
V_25 [ V_24 ] = F_23 ( V_23 + V_59 ) ;
V_25 [ V_24 + 1 ] = F_23 ( V_23 + V_59 ) ;
if ( V_25 [ V_24 ] != V_25 [ V_24 + 1 ] )
V_26 = 1 ;
}
if ( V_26 == 2 )
for ( V_24 = 0 ; V_24 < 16 ; V_24 ++ )
V_25 [ V_24 ] = V_25 [ V_24 + V_24 ] ;
if ( V_26 == 2 ) {
F_22 ( 0x49 , V_23 + V_47 ) ;
V_27 = V_60 ;
V_28 = V_61 ;
} else {
V_27 = V_62 ;
V_28 = V_63 ;
}
V_29 = ( V_25 [ 14 ] == 0x57 && V_25 [ 15 ] == 0x57 ) ;
V_30 = ( V_25 [ 0 ] == 0x00 && V_25 [ 1 ] == 0x00 && V_25 [ 2 ] == 0x1d ) ;
if ( V_29 ) {
V_14 = ( V_26 == 2 ) ? L_8 : L_9 ;
} else if ( V_30 ) {
V_14 = ( V_26 == 2 ) ? L_10 : L_11 ;
V_27 = 0x01 ;
V_28 = ( V_26 == 2 ) ? 0x40 : 0x20 ;
} else {
F_6 ( L_12 ) ;
return - V_64 ;
}
#else
V_26 = 2 ;
F_22 ( 0x49 , V_23 + V_47 ) ;
V_27 = V_60 ;
V_28 = V_61 ;
V_25 [ 0 ] = F_20 ;
V_25 [ 1 ] = V_65 ;
V_25 [ 2 ] = V_66 ;
V_25 [ 3 ] = V_67 ;
V_25 [ 4 ] = V_68 ;
V_25 [ 5 ] = V_69 ;
V_14 = L_8 ;
#endif
V_3 -> V_70 = V_23 ;
V_3 -> V_71 = V_22 ;
V_3 -> V_72 = & V_73 ;
V_24 = F_26 ( V_3 -> V_71 , V_74 , V_75 , V_20 , V_3 ) ;
if ( V_24 ) return V_24 ;
for ( V_24 = 0 ; V_24 < V_76 ; V_24 ++ )
V_3 -> V_77 [ V_24 ] = V_25 [ V_24 ] ;
F_6 ( L_13 , V_3 -> V_77 ) ;
F_21 ( V_3 , L_14 , V_14 ) ;
V_78 . V_14 = V_14 ;
V_78 . V_79 = V_27 ;
V_78 . V_28 = V_28 ;
V_78 . V_80 = ( V_26 == 2 ) ;
V_78 . V_81 = V_27 + V_82 ;
V_78 . V_83 = & V_84 ;
V_78 . V_85 = & V_86 ;
V_78 . V_87 = & V_88 ;
V_78 . V_89 = & V_90 ;
F_27 ( V_3 , 0 ) ;
F_28 ( F_29 () ) ;
F_30 () ;
V_10 = 1 ;
return 0 ;
}
static void
V_84 ( struct V_1 * V_3 )
{
unsigned long V_34 = V_35 ;
struct V_4 * V_5 = F_9 ( V_3 ) ;
F_13 () ;
F_31 ( V_5 , V_91 , V_3 , L_15 , V_35 ) ;
F_22 ( F_23 ( V_92 + V_36 ) , V_92 + V_36 ) ;
V_78 . V_93 = 0 ;
V_78 . V_94 = 0 ;
while ( ( F_23 ( V_92 + V_37 ) & V_38 ) == 0 )
if ( F_24 ( V_35 , V_34 + 2 * V_39 / 100 ) ) {
F_32 ( V_3 , L_16 ) ;
break;
}
F_22 ( V_38 , V_92 + V_37 ) ;
}
static void
V_90 ( struct V_1 * V_3 , struct V_95 * V_96 , int V_97 )
{
int V_98 = V_3 -> V_70 ;
int V_99 ;
char * V_100 ;
short * V_101 ;
if ( V_78 . V_94 ) {
F_32 ( V_3 , L_17
L_18 ,
V_78 . V_94 , V_78 . V_102 , V_3 -> V_71 ) ;
return;
}
V_78 . V_94 |= 0x01 ;
F_22 ( V_43 + V_44 + V_58 , V_98 + V_46 ) ;
F_22 ( V_103 , V_98 + V_37 ) ;
F_22 ( sizeof( struct V_95 ) , V_98 + V_48 ) ;
F_22 ( 0 , V_98 + V_49 ) ;
F_22 ( 0 , V_98 + V_55 ) ;
F_22 ( V_97 , V_98 + V_56 ) ;
F_22 ( V_57 + V_58 , V_98 + V_46 ) ;
if ( V_78 . V_80 ) {
V_101 = ( short * ) V_96 ;
for( V_99 = 0 ; V_99 < ( sizeof( struct V_95 ) >> 1 ) ; V_99 ++ )
* V_101 ++ = F_33 ( V_92 + V_59 ) ;
} else {
V_100 = ( char * ) V_96 ;
for( V_99 = 0 ; V_99 < sizeof( struct V_95 ) ; V_99 ++ )
* V_100 ++ = F_23 ( V_92 + V_59 ) ;
}
F_22 ( V_103 , V_98 + V_37 ) ;
V_78 . V_94 &= ~ 0x01 ;
F_34 ( & V_96 -> V_104 ) ;
}
static void
V_86 ( struct V_1 * V_3 , int V_104 , struct V_105 * V_106 , int V_107 )
{
int V_98 = V_3 -> V_70 ;
char * V_108 = V_106 -> V_109 ;
char * V_100 ;
short * V_101 ;
int V_99 ;
if ( V_78 . V_94 ) {
F_32 ( V_3 , L_19
L_18 ,
V_78 . V_94 , V_78 . V_102 , V_3 -> V_71 ) ;
return;
}
V_78 . V_94 |= 0x01 ;
F_22 ( V_43 + V_44 + V_58 , V_98 + V_46 ) ;
F_22 ( V_103 , V_98 + V_37 ) ;
F_22 ( V_104 & 0xff , V_98 + V_48 ) ;
F_22 ( V_104 >> 8 , V_98 + V_49 ) ;
F_22 ( V_107 & 0xff , V_98 + V_55 ) ;
F_22 ( V_107 >> 8 , V_98 + V_56 ) ;
F_22 ( V_57 + V_58 , V_98 + V_46 ) ;
if ( V_78 . V_80 ) {
V_101 = ( short * ) V_108 ;
for ( V_99 = 0 ; V_99 < ( V_104 >> 1 ) ; V_99 ++ )
* V_101 ++ = F_33 ( V_92 + V_59 ) ;
if ( V_104 & 0x01 ) {
V_108 [ V_104 - 1 ] = F_23 ( V_92 + V_59 ) ;
}
} else {
V_100 = V_108 ;
for ( V_99 = 0 ; V_99 < V_104 ; V_99 ++ )
* V_100 ++ = F_23 ( V_92 + V_59 ) ;
}
F_22 ( V_103 , V_98 + V_37 ) ;
V_78 . V_94 &= ~ 0x01 ;
}
static void
V_88 ( struct V_1 * V_3 , int V_104 ,
const unsigned char * V_108 , const int V_27 )
{
int V_98 = V_92 ;
unsigned long V_110 ;
char * V_100 ;
short * V_101 ;
int V_99 ;
if ( V_78 . V_80 && ( V_104 & 0x01 ) )
V_104 ++ ;
if ( V_78 . V_94 ) {
F_32 ( V_3 , L_20
L_21 ,
V_78 . V_94 , V_78 . V_102 , V_3 -> V_71 ) ;
return;
}
V_78 . V_94 |= 0x01 ;
F_22 ( V_44 + V_58 + V_43 , V_98 + V_46 ) ;
F_22 ( V_103 , V_98 + V_37 ) ;
F_22 ( V_104 & 0xff , V_98 + V_48 ) ;
F_22 ( V_104 >> 8 , V_98 + V_49 ) ;
F_22 ( 0x00 , V_98 + V_55 ) ;
F_22 ( V_27 , V_98 + V_56 ) ;
F_22 ( V_111 + V_58 , V_98 + V_46 ) ;
if ( V_78 . V_80 ) {
V_101 = ( short * ) V_108 ;
for ( V_99 = 0 ; V_99 < V_104 > > 1 ; V_99 ++ )
F_35 ( * V_101 ++ , V_92 + V_59 ) ;
} else {
V_100 = ( char * ) V_108 ;
for ( V_99 = 0 ; V_99 < V_104 ; V_99 ++ )
F_22 ( * V_100 ++ , V_92 + V_59 ) ;
}
V_110 = V_35 ;
while ( ( F_23 ( V_92 + V_37 ) & V_103 ) == 0 )
if ( F_24 ( V_35 , V_110 + 2 * V_39 / 100 ) ) {
F_36 ( V_3 , L_22 ) ;
V_84 ( V_3 ) ;
F_27 ( V_3 , 1 ) ;
break;
}
F_22 ( V_103 , V_98 + V_37 ) ;
V_78 . V_94 &= ~ 0x01 ;
}
static T_2 V_74 ( int V_71 , void * V_112 )
{
unsigned char V_113 ;
if ( ! ( V_114 . V_115 & V_116 ) )
return V_117 ;
V_113 = F_29 () ;
if ( ! ( V_113 & V_116 ) ) {
F_28 ( V_113 ) ;
return V_117 ;
}
if ( V_16 & V_118 )
F_37 ( L_23 , V_113 ) ;
F_10 () ;
F_38 ( V_71 , V_112 ) ;
F_28 ( F_29 () ) ;
F_30 () ;
return V_119 ;
}
static int T_1 F_39 ( void )
{
V_120 = F_1 ( - 1 ) ;
return F_40 ( V_120 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( V_120 ) ;
F_10 () ;
F_18 ( V_22 , V_120 ) ;
F_19 () ;
F_16 ( V_19 , 0x20 ) ;
F_12 ( V_120 ) ;
}
static int F_13 ( void )
{
T_4 V_121 ;
#ifndef F_2
T_4 V_6 [ 32 ] ;
int V_122 ;
#endif
T_5 V_41 ;
F_19 () ;
F_43 ( V_123 ) ;
F_44 ( V_124 ) ;
F_45 () ;
#ifdef F_2
V_121 = F_2 ;
#else
if ( F_11 ( V_125 , V_6 , 32 ) < 3 )
return 0 ;
V_121 = V_6 [ 2 ] & 0x3f ;
#endif
#ifdef F_46
V_41 = F_46 ;
#else
if ( F_11 ( V_126 , V_6 , 32 ) < 6 )
return 0 ;
V_122 = ( V_6 [ 2 ] & 0x3 ) + 1 ;
V_41 = 0 ;
while( V_122 -- ) {
V_41 = ( V_41 << 8 ) | V_6 [ 4 + V_122 ] ;
}
#endif
F_47 ( V_127 + V_41 , V_121 ) ;
return 1 ;
}
