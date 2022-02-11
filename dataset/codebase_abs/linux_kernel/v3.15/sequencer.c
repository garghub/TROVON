int F_1 ( int V_1 , struct V_2 * V_2 , char T_1 * V_3 , int V_4 )
{
int V_5 = V_4 , V_6 = 0 ;
int V_7 ;
unsigned long V_8 ;
V_1 = V_1 >> 4 ;
V_7 = V_9 == V_10 ? 4 : 8 ;
F_2 ( & V_11 , V_8 ) ;
if ( ! V_12 )
{
F_3 ( & V_11 , V_8 ) ;
if ( V_2 -> V_13 & V_14 ) {
return - V_15 ;
}
F_4 ( & V_16 , V_17 ) ;
F_2 ( & V_11 , V_8 ) ;
if ( ! V_12 )
{
F_3 ( & V_11 , V_8 ) ;
return 0 ;
}
}
while ( V_12 && V_5 >= V_7 )
{
char * V_18 = ( char * ) & V_19 [ V_20 * V_21 ] ;
F_3 ( & V_11 , V_8 ) ;
if ( F_5 ( & ( V_3 ) [ V_6 ] , V_18 , V_7 ) )
return V_4 - V_5 ;
V_6 += V_7 ;
V_5 -= V_7 ;
F_2 ( & V_11 , V_8 ) ;
V_20 = ( V_20 + 1 ) % V_22 ;
V_12 -- ;
}
F_3 ( & V_11 , V_8 ) ;
return V_4 - V_5 ;
}
static void F_6 ( int V_1 )
{
}
void F_7 ( unsigned char * V_23 , int V_24 )
{
unsigned long V_8 ;
if ( V_24 != 4 && V_24 != 8 )
return;
if ( ( V_9 == V_10 ) != ( V_24 == 4 ) )
return;
if ( V_12 >= ( V_22 - 1 ) )
return;
F_2 ( & V_11 , V_8 ) ;
memcpy ( & V_19 [ V_25 * V_21 ] , V_23 , V_24 ) ;
V_12 ++ ;
V_25 = ( V_25 + 1 ) % V_22 ;
F_8 ( & V_16 ) ;
F_3 ( & V_11 , V_8 ) ;
}
static void F_9 ( int V_1 , unsigned char V_26 )
{
unsigned int V_27 ;
unsigned char V_23 [ 4 ] ;
if ( V_26 == 0xfe )
return;
V_27 = V_28 - V_29 ;
if ( V_27 != V_30 )
{
V_27 = ( V_27 << 8 ) | V_31 ;
F_7 ( ( unsigned char * ) & V_27 , 4 ) ;
V_30 = V_27 ;
}
V_23 [ 0 ] = V_32 ;
V_23 [ 1 ] = V_26 ;
V_23 [ 2 ] = V_1 ;
V_23 [ 3 ] = 0 ;
F_7 ( V_23 , 4 ) ;
}
void F_10 ( unsigned char * V_23 , int V_24 )
{
unsigned long V_33 ;
if ( V_9 == V_34 )
V_33 = V_35 -> V_36 ( V_37 ) ;
else
V_33 = V_28 - V_29 ;
if ( V_33 != V_30 )
{
unsigned char V_38 [ 8 ] ;
V_38 [ 0 ] = V_39 ;
V_38 [ 1 ] = V_40 ;
V_38 [ 2 ] = 0 ;
V_38 [ 3 ] = 0 ;
* ( unsigned int * ) & V_38 [ 4 ] = V_33 ;
F_7 ( V_38 , 8 ) ;
V_30 = V_33 ;
}
F_7 ( V_23 , V_24 ) ;
}
int F_11 ( int V_1 , struct V_2 * V_2 , const char T_1 * V_3 , int V_4 )
{
unsigned char V_23 [ V_41 ] , V_42 ;
int V_6 = 0 , V_5 , V_43 ;
int V_44 = F_12 ( V_2 ) ;
V_1 = V_1 >> 4 ;
if ( V_44 == V_45 )
return - V_46 ;
V_5 = V_4 ;
while ( V_5 >= 4 )
{
if ( F_13 ( ( char * ) V_23 , & ( V_3 ) [ V_6 ] , 4 ) )
goto V_47;
V_42 = V_23 [ 0 ] ;
if ( V_42 == V_48 )
{
int V_49 , V_50 ;
V_1 = * ( unsigned short * ) & V_23 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_51 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return - V_53 ;
V_50 = ( * ( short * ) & V_23 [ 0 ] ) & 0xffff ;
V_49 = V_52 [ V_1 ] -> F_14 ( V_1 , V_50 , V_3 + V_6 , V_5 , 0 ) ;
if ( V_49 < 0 )
return V_49 ;
return V_49 ;
}
if ( V_42 >= 128 )
{
if ( V_9 == V_34 && V_42 == V_55 )
{
F_15 ( V_56 L_1 , V_42 ) ;
return - V_57 ;
}
V_43 = 8 ;
if ( V_5 < V_43 )
{
if ( ! V_58 )
F_16 () ;
return V_4 - V_5 ;
}
if ( F_13 ( ( char * ) & V_23 [ 4 ] ,
& ( V_3 ) [ V_6 + 4 ] , 4 ) )
goto V_47;
}
else
{
if ( V_9 == V_34 )
{
F_15 ( V_56 L_2 ) ;
return - V_57 ;
}
V_43 = 4 ;
if ( V_23 [ 0 ] != V_32 )
V_59 = 1 ;
}
if ( V_23 [ 0 ] == V_32 )
{
if ( ! V_60 [ V_23 [ 2 ] ] )
{
int V_49 , V_44 ;
int V_1 = V_23 [ 2 ] ;
if ( V_1 >= V_61 || V_62 [ V_1 ] == NULL )
{
return - V_53 ;
}
V_44 = F_12 ( V_2 ) ;
if ( ( V_49 = V_62 [ V_1 ] -> F_17 ( V_1 , V_44 ,
F_9 , F_6 ) ) < 0 )
{
F_18 () ;
F_15 ( V_56 L_3 , V_1 ) ;
return V_49 ;
}
V_60 [ V_1 ] = 1 ;
}
}
if ( ! F_19 ( V_23 , ( V_2 -> V_13 & ( V_14 ) ? 1 : 0 ) ) )
{
int V_63 = V_4 - V_5 ;
if ( ! V_58 )
F_16 () ;
if ( ! V_63 && ( V_2 -> V_13 & V_14 ) )
return - V_15 ;
else
return V_63 ;
}
V_6 += V_43 ;
V_5 -= V_43 ;
}
if ( ! V_58 )
F_16 () ;
V_47:
return V_4 ;
}
static int F_19 ( unsigned char * V_64 , char V_65 )
{
if ( V_66 >= V_22 )
if ( ! V_58 )
F_16 () ;
if ( ! V_65 && V_66 >= V_22 && ! F_20 ( & V_67 ) ) {
F_4 ( & V_67 , V_68 ) ;
}
if ( V_66 >= V_22 )
{
return 0 ;
}
memcpy ( & V_69 [ V_70 * V_41 ] , V_64 , V_41 ) ;
V_70 = ( V_70 + 1 ) % V_22 ;
V_66 ++ ;
return 1 ;
}
static int F_21 ( unsigned char * V_71 )
{
int V_1 = V_71 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return - V_53 ;
switch ( V_71 [ 1 ] )
{
case V_72 :
V_52 [ V_1 ] -> F_22 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] , V_71 [ 5 ] ) ;
break;
case V_73 :
if ( V_71 [ 4 ] > 127 && V_71 [ 4 ] != 255 )
return 0 ;
if ( V_71 [ 5 ] == 0 )
{
V_52 [ V_1 ] -> F_22 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] , V_71 [ 5 ] ) ;
break;
}
V_52 [ V_1 ] -> F_23 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] , V_71 [ 5 ] ) ;
break;
case V_74 :
V_52 [ V_1 ] -> F_24 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] ) ;
break;
case V_75 :
V_52 [ V_1 ] -> F_25 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] ) ;
break;
case V_76 :
V_52 [ V_1 ] -> F_26 ( V_1 , V_71 [ 3 ] , ( char ) V_71 [ 4 ] ) ;
break;
case V_77 :
V_52 [ V_1 ] -> F_27 ( V_1 , V_71 [ 3 ] , V_71 [ 4 ] , ( short ) ( V_71 [ 5 ] | ( V_71 [ 6 ] << 8 ) ) ) ;
break;
case V_78 :
if ( V_52 [ V_1 ] -> V_79 != NULL )
V_52 [ V_1 ] -> V_79 ( V_1 , V_71 [ 3 ] ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_28 ( int V_1 , int V_80 , int V_64 )
{
unsigned short V_81 ;
int V_82 ;
V_81 = ( V_80 << 8 ) | ( V_64 + 1 ) ;
for ( V_82 = 0 ; V_82 < V_52 [ V_1 ] -> V_83 . V_84 ; V_82 ++ )
if ( V_52 [ V_1 ] -> V_83 . V_85 [ V_82 ] == V_81 )
return V_82 ;
return - 1 ;
}
static int F_29 ( int V_1 , int V_80 , int V_64 )
{
unsigned short V_81 ;
int V_86 ;
V_81 = ( V_80 << 8 ) | ( V_64 + 1 ) ;
V_86 = V_52 [ V_1 ] -> F_29 ( V_1 , V_80 , V_64 ,
& V_52 [ V_1 ] -> V_83 ) ;
V_52 [ V_1 ] -> V_83 . V_85 [ V_86 ] = V_81 ;
V_52 [ V_1 ] -> V_83 . V_87 [ V_86 ] =
V_52 [ V_1 ] -> V_83 . V_88 ++ ;
return V_86 ;
}
static void F_30 ( unsigned char * V_23 )
{
#define V_1 event_rec[1]
#define F_31 event_rec[2]
#define V_80 event_rec[3]
#define V_64 event_rec[4]
#define F_32 event_rec[5]
int V_86 = - 1 ;
if ( ( int ) V_1 > V_51 || V_52 [ V_1 ] == NULL )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
if ( V_9 == V_34 )
{
if ( V_52 [ V_1 ] -> F_29 )
V_86 = F_28 ( V_1 , V_80 , V_64 ) ;
if ( F_31 == V_89 && F_32 == 0 )
{
F_31 = V_90 ;
F_32 = 64 ;
}
}
switch ( F_31 )
{
case V_89 :
if ( V_64 > 127 && V_64 != 255 )
return;
if ( V_86 == - 1 && V_9 == V_34 && V_52 [ V_1 ] -> F_29 )
{
V_86 = F_29 ( V_1 , V_80 , V_64 ) ;
}
if ( V_86 == - 1 )
V_86 = V_80 ;
if ( V_9 == V_34 && ( int ) V_1 < V_91 )
{
if ( V_80 == 9 )
{
V_52 [ V_1 ] -> F_24 ( V_1 , V_86 , 128 + V_64 ) ;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_93 = 128 + V_64 ;
}
V_52 [ V_1 ] -> F_33 ( V_1 , V_86 , V_80 ) ;
}
V_52 [ V_1 ] -> F_23 ( V_1 , V_86 , V_64 , F_32 ) ;
break;
case V_90 :
if ( V_86 == - 1 )
V_86 = V_80 ;
V_52 [ V_1 ] -> F_22 ( V_1 , V_86 , V_64 , F_32 ) ;
break;
case V_94 :
if ( V_86 == - 1 )
V_86 = V_80 ;
V_52 [ V_1 ] -> F_25 ( V_1 , V_86 , F_32 ) ;
break;
default: ;
}
#undef V_1
#undef F_31
#undef V_80
#undef V_64
#undef F_32
}
static void F_34 ( unsigned char * V_23 )
{
unsigned char V_1 = V_23 [ 1 ] ;
unsigned char F_31 = V_23 [ 2 ] ;
unsigned char V_80 = V_23 [ 3 ] ;
unsigned char V_95 = V_23 [ 4 ] ;
unsigned short V_96 = * ( short * ) & V_23 [ 6 ] ;
if ( ( int ) V_1 > V_51 || V_52 [ V_1 ] == NULL )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
switch ( F_31 )
{
case V_97 :
if ( V_9 == V_34 )
{
if ( V_80 > 15 )
break;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_93 = V_95 ;
if ( ( int ) V_1 >= V_91 )
V_52 [ V_1 ] -> F_24 ( V_1 , V_80 , V_95 ) ;
}
else
V_52 [ V_1 ] -> F_24 ( V_1 , V_80 , V_95 ) ;
break;
case V_98 :
if ( V_9 == V_34 )
{
if ( V_80 > 15 || V_95 > 127 )
break;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_99 [ V_95 ] = V_96 & 0x7f ;
if ( V_95 < 32 )
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_99 [ V_95 + 32 ] = 0 ;
if ( ( int ) V_1 < V_91 )
{
int V_100 = V_96 & 0x7f ;
int V_82 , V_81 ;
if ( V_95 < 64 )
{
V_100 = ( ( V_52 [ V_1 ] ->
V_92 [ V_80 ] . V_99 [ V_95 & ~ 32 ] & 0x7f ) << 7 )
| ( V_52 [ V_1 ] ->
V_92 [ V_80 ] . V_99 [ V_95 | 32 ] & 0x7f ) ;
V_95 &= ~ 32 ;
}
V_81 = ( ( int ) V_80 << 8 ) ;
for ( V_82 = 0 ; V_82 < V_52 [ V_1 ] -> V_83 . V_84 ; V_82 ++ )
if ( ( V_52 [ V_1 ] -> V_83 . V_85 [ V_82 ] & 0xff00 ) == V_81 )
V_52 [ V_1 ] -> F_27 ( V_1 , V_82 , V_95 , V_100 ) ;
}
else
V_52 [ V_1 ] -> F_27 ( V_1 , V_80 , V_95 , V_96 ) ;
}
else
V_52 [ V_1 ] -> F_27 ( V_1 , V_80 , V_95 , V_96 ) ;
break;
case V_101 :
if ( V_9 == V_34 )
{
if ( V_80 > 15 )
break;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_102 = V_96 ;
if ( ( int ) V_1 < V_91 )
{
int V_82 , V_81 ;
V_81 = ( V_80 << 8 ) ;
for ( V_82 = 0 ; V_82 < V_52 [ V_1 ] -> V_83 . V_84 ; V_82 ++ )
if ( ( V_52 [ V_1 ] -> V_83 . V_85 [ V_82 ] & 0xff00 ) == V_81 )
V_52 [ V_1 ] -> F_35 ( V_1 , V_82 , V_96 ) ;
}
else
V_52 [ V_1 ] -> F_35 ( V_1 , V_80 , V_96 ) ;
}
else
V_52 [ V_1 ] -> F_35 ( V_1 , V_80 , V_96 ) ;
break;
default: ;
}
}
static int F_36 ( unsigned char * V_23 )
{
unsigned char F_31 = V_23 [ 1 ] ;
unsigned int F_32 = * ( int * ) & V_23 [ 4 ] ;
if ( V_9 == V_34 )
{
int V_103 ;
if ( ( V_103 = V_35 -> V_104 ( V_37 , V_23 ) ) == V_105 )
if ( ( V_22 - V_66 ) >= V_106 )
F_8 ( & V_67 ) ;
return V_103 ;
}
switch ( F_31 )
{
case V_107 :
F_32 += V_108 ;
case V_40 :
if ( F_32 > 0 )
{
long time ;
time = F_32 ;
V_108 = time ;
V_58 = 1 ;
F_37 ( time ) ;
if ( ( V_22 - V_66 ) >= V_106 )
F_8 ( & V_67 ) ;
return V_105 ;
}
break;
case V_109 :
V_29 = V_28 ;
V_30 = 0 ;
V_108 = 0 ;
break;
case V_110 :
break;
case V_111 :
break;
case V_112 :
break;
case V_113 :
if ( V_9 == V_34 )
F_7 ( V_23 , 8 ) ;
else
{
F_32 = ( F_32 << 8 | V_114 ) ;
F_7 ( ( unsigned char * ) & F_32 , 4 ) ;
}
break;
default: ;
}
return V_115 ;
}
static void F_38 ( unsigned char * V_23 )
{
unsigned char F_31 = V_23 [ 1 ] ;
unsigned int F_32 = * ( ( unsigned int * ) & V_23 [ 4 ] ) ;
switch ( F_31 )
{
case V_116 :
F_39 ( F_32 ) ;
break;
default: ;
}
}
static void F_40 ( unsigned char * V_23 )
{
unsigned int V_1 = V_23 [ 1 ] ;
int V_82 , V_117 = 0 ;
unsigned char * V_3 = & V_23 [ 2 ] ;
if ( V_1 > V_51 )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
V_117 = 0 ;
for ( V_82 = 0 ; V_82 < 6 && V_3 [ V_82 ] != 0xff ; V_82 ++ )
V_117 = V_82 + 1 ;
if ( ! V_52 [ V_1 ] -> V_118 )
return;
if ( V_117 > 0 )
V_52 [ V_1 ] -> V_118 ( V_1 , V_3 , V_117 ) ;
}
static int F_41 ( unsigned char * V_71 )
{
unsigned int * V_119 ;
switch ( V_71 [ 0 ] )
{
case V_72 :
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_22 ( 0 , V_71 [ 1 ] , 255 , V_71 [ 3 ] ) ;
break;
case V_73 :
if ( V_71 [ 4 ] < 128 || V_71 [ 4 ] == 255 )
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_23 ( 0 , V_71 [ 1 ] , V_71 [ 2 ] , V_71 [ 3 ] ) ;
break;
case V_31 :
V_119 = ( unsigned int * ) V_71 ;
* V_119 = ( * V_119 >> 8 ) & 0xffffff ;
if ( * V_119 > 0 )
{
long time ;
V_58 = 1 ;
time = * V_119 ;
V_108 = time ;
F_37 ( time ) ;
if ( ( V_22 - V_66 ) >= V_106 )
F_8 ( & V_67 ) ;
return 1 ;
}
break;
case V_74 :
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_24 ( 0 , V_71 [ 1 ] , V_71 [ 2 ] ) ;
break;
case V_120 :
V_29 = V_28 ;
V_30 = 0 ;
V_108 = 0 ;
break;
case V_32 :
if ( V_60 [ V_71 [ 2 ] ] )
{
int V_1 ;
V_1 = V_71 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_121 || V_62 [ V_1 ] == NULL )
break;
if ( ! V_62 [ V_1 ] -> F_42 ( V_1 , V_71 [ 1 ] ) )
{
V_58 = 1 ;
F_37 ( - 1 ) ;
return 2 ;
}
else
V_122 [ V_1 ] = 1 ;
}
break;
case V_114 :
F_7 ( V_71 , 4 ) ;
break;
case V_123 :
if ( ( int ) V_71 [ 1 ] < V_51 )
V_52 [ V_71 [ 1 ] ] -> F_43 ( V_71 [ 1 ] , V_71 ) ;
break;
case V_55 :
F_21 ( V_71 ) ;
break;
case V_124 :
F_30 ( V_71 ) ;
break;
case V_125 :
F_34 ( V_71 ) ;
break;
case V_39 :
if ( F_36 ( V_71 ) == V_105 )
{
return 1 ;
}
break;
case V_126 :
F_38 ( V_71 ) ;
break;
case V_127 :
F_40 ( V_71 ) ;
break;
default: ;
}
return 0 ;
}
static void F_16 ( void )
{
int V_128 , V_129 ;
unsigned long V_8 ;
while ( V_66 > 0 )
{
F_2 ( & V_11 , V_8 ) ;
V_130 = ( ( V_128 = V_130 ) + 1 ) % V_22 ;
V_66 -- ;
F_3 ( & V_11 , V_8 ) ;
V_58 = 1 ;
if ( ( V_129 = F_41 ( & V_69 [ V_128 * V_41 ] ) ) )
{
if ( V_129 == 2 )
{
V_66 ++ ;
V_130 = V_128 ;
}
return;
}
}
V_58 = 0 ;
if ( ( V_22 - V_66 ) >= V_106 )
F_8 ( & V_67 ) ;
}
static void F_44 ( int V_1 , unsigned char * F_27 , int V_131 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < 128 ; V_82 ++ )
F_27 [ V_82 ] = V_132 [ V_82 ] ;
}
static void F_45 ( void )
{
int V_1 ;
V_51 = V_91 ;
for ( V_1 = 0 ; V_1 < V_121 ; V_1 ++ )
{
if ( V_62 [ V_1 ] && V_62 [ V_1 ] -> V_133 != NULL )
{
V_52 [ V_51 ++ ] = V_62 [ V_1 ] -> V_133 ;
}
}
for ( V_1 = 0 ; V_1 < V_51 ; V_1 ++ )
{
int V_80 ;
V_52 [ V_1 ] -> V_134 = 0 ;
V_52 [ V_1 ] -> V_135 = 0 ;
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ )
{
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_93 = 0 ;
F_44 ( V_1 ,
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_99 , 0 ) ;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_102 = ( 1 << 7 ) ;
V_52 [ V_1 ] -> V_92 [ V_80 ] . V_136 = 200 ;
}
}
V_61 = 0 ;
V_9 = V_34 ;
}
int F_46 ( int V_1 , struct V_2 * V_2 )
{
int V_137 , V_44 , V_82 ;
int V_138 , V_139 ;
if ( ! V_140 )
F_47 () ;
V_138 = ( ( V_1 & 0x0f ) == V_141 ) ? 2 : 1 ;
V_1 = V_1 >> 4 ;
V_44 = F_12 ( V_2 ) ;
if ( ! V_140 )
{
return - V_53 ;
}
if ( V_1 )
return - V_53 ;
if( V_52 [ V_1 ] == NULL )
F_48 ( L_4 ) ;
if ( V_44 == V_45 )
{
if ( ! V_121 )
{
V_142 = 0 ;
return - V_53 ;
}
}
if ( V_142 )
{
return - V_143 ;
}
V_142 = 1 ;
V_59 = 0 ;
V_61 = V_121 ;
V_51 = V_91 ;
V_17 = V_68 ;
V_9 = V_10 ;
if ( V_144 != - 1 )
{
V_37 = V_144 ;
V_144 = - 1 ;
}
if ( V_37 == - 1 )
{
int V_82 , V_145 ;
V_145 = - 1 ;
for ( V_82 = 0 ; V_82 < V_146 ; V_82 ++ )
if ( V_147 [ V_82 ] && V_147 [ V_82 ] -> V_148 > V_145 )
{
V_37 = V_82 ;
V_145 = V_147 [ V_82 ] -> V_148 ;
}
if ( V_37 == - 1 )
V_37 = 0 ;
}
V_35 = V_147 [ V_37 ] ;
if ( V_138 == 2 )
{
if ( V_35 == NULL )
{
V_142 = 0 ;
return - V_53 ;
}
F_45 () ;
}
if ( ! V_51 && ! V_61 )
{
V_142 = 0 ;
return - V_53 ;
}
V_54 = 0 ;
for ( V_82 = 0 ; V_82 < V_61 ; V_82 ++ )
{
V_60 [ V_82 ] = 0 ;
V_122 [ V_82 ] = 0 ;
}
for ( V_82 = 0 ; V_82 < V_51 ; V_82 ++ )
{
if ( V_52 [ V_82 ] == NULL )
continue;
if ( ! F_49 ( V_52 [ V_82 ] -> V_149 ) )
continue;
if ( ( V_139 = V_52 [ V_82 ] -> F_17 ( V_82 , V_44 ) ) < 0 )
{
F_15 ( V_56 L_5 , V_82 , V_139 ) ;
if ( V_52 [ V_82 ] -> V_150 )
F_15 ( V_56 L_6 , V_52 [ V_82 ] -> V_150 ) ;
}
else
{
V_54 |= ( 1 << V_82 ) ;
if ( V_52 [ V_82 ] -> V_150 )
V_60 [ V_52 [ V_82 ] -> V_150 ] = 1 ;
}
}
V_29 = V_28 ;
V_30 = 0 ;
V_108 = 0 ;
if ( V_9 == V_10 && ( V_44 == V_45 || V_44 == V_151 ) )
{
for ( V_82 = 0 ; V_82 < V_61 ; V_82 ++ )
if ( ! V_60 [ V_82 ] && V_62 [ V_82 ] )
{
if ( ! F_49 ( V_62 [ V_82 ] -> V_149 ) )
continue;
if ( ( V_137 = V_62 [ V_82 ] -> F_17 ( V_82 , V_44 ,
F_9 , F_6 ) ) >= 0 )
{
V_60 [ V_82 ] = 1 ;
}
}
}
if ( V_9 == V_34 ) {
if ( F_49 ( V_35 -> V_149 ) )
V_35 -> F_17 ( V_37 , V_9 ) ;
}
F_50 ( & V_67 ) ;
F_50 ( & V_16 ) ;
V_106 = V_22 / 2 ;
return 0 ;
}
static void F_51 ( void )
{
int V_82 , V_152 ;
V_152 = 1 ;
while ( ! F_52 ( V_153 ) && V_152 )
{
V_152 = 0 ;
for ( V_82 = 0 ; V_82 < V_61 ; V_82 ++ )
if ( V_60 [ V_82 ] && V_122 [ V_82 ] )
if ( V_62 [ V_82 ] -> V_154 != NULL )
if ( V_62 [ V_82 ] -> V_154 ( V_82 ) )
V_152 ++ ;
if ( V_152 )
F_4 ( & V_67 , V_155 / 10 ) ;
}
}
void F_53 ( int V_1 , struct V_2 * V_2 )
{
int V_82 ;
int V_44 = F_12 ( V_2 ) ;
V_1 = V_1 >> 4 ;
if ( V_44 != V_45 && ! ( V_2 -> V_13 & V_14 ) )
{
while ( ! F_52 ( V_153 ) && V_66 > 0 )
{
F_54 () ;
F_4 ( & V_67 , 3 * V_155 ) ;
}
}
if ( V_44 != V_45 )
F_51 () ;
F_18 () ;
if ( V_44 != V_45 )
F_51 () ;
for ( V_82 = 0 ; V_82 < V_51 ; V_82 ++ )
{
if ( V_54 & ( 1 << V_82 ) )
if ( V_52 [ V_82 ] )
{
V_52 [ V_82 ] -> F_55 ( V_82 ) ;
F_56 ( V_52 [ V_82 ] -> V_149 ) ;
if ( V_52 [ V_82 ] -> V_150 )
V_60 [ V_52 [ V_82 ] -> V_150 ] = 0 ;
}
}
for ( V_82 = 0 ; V_82 < V_61 ; V_82 ++ )
{
if ( V_60 [ V_82 ] ) {
V_62 [ V_82 ] -> F_55 ( V_82 ) ;
F_56 ( V_62 [ V_82 ] -> V_149 ) ;
}
}
if ( V_9 == V_34 ) {
V_35 -> F_55 ( V_37 ) ;
F_56 ( V_35 -> V_149 ) ;
}
if ( V_59 )
F_15 ( V_56 L_7 , V_153 -> V_156 ) ;
V_142 = 0 ;
}
static int F_54 ( void )
{
if ( V_66 && ! V_58 && ! F_52 ( V_153 ) )
F_16 () ;
if ( V_66 > 0 )
F_4 ( & V_67 , V_155 ) ;
return V_66 ;
}
static void F_57 ( int V_1 , unsigned char V_26 )
{
int V_152 ;
unsigned long V_8 ;
V_152 = 3 * V_155 ;
F_2 ( & V_11 , V_8 ) ;
while ( V_152 && ! V_62 [ V_1 ] -> F_42 ( V_1 , V_26 ) ) {
F_4 ( & V_67 , V_155 / 25 ) ;
V_152 -- ;
}
F_3 ( & V_11 , V_8 ) ;
}
static void F_18 ( void )
{
int V_82 ;
int V_80 ;
unsigned long V_8 ;
F_58 () ;
V_29 = V_28 ;
V_30 = 0 ;
V_108 = 0 ;
V_66 = V_130 = V_70 = 0 ;
V_12 = V_20 = V_25 = 0 ;
for ( V_82 = 0 ; V_82 < V_51 ; V_82 ++ )
if ( V_54 & ( 1 << V_82 ) )
if ( V_52 [ V_82 ] )
V_52 [ V_82 ] -> F_59 ( V_82 ) ;
if ( V_9 == V_34 )
{
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ )
for ( V_82 = 0 ; V_82 < V_51 ; V_82 ++ )
if ( V_54 & ( 1 << V_82 ) )
if ( V_52 [ V_82 ] )
{
V_52 [ V_82 ] -> F_27 ( V_82 , V_80 , 123 , 0 ) ;
V_52 [ V_82 ] -> F_27 ( V_82 , V_80 , 121 , 0 ) ;
V_52 [ V_82 ] -> F_35 ( V_82 , V_80 , 1 << 13 ) ;
}
}
else
{
for ( V_82 = 0 ; V_82 < V_61 ; V_82 ++ )
if ( V_122 [ V_82 ] )
{
F_57 ( V_82 , 0xfe ) ;
for ( V_80 = 0 ; V_80 < 16 ; V_80 ++ )
{
F_57 ( V_82 , ( unsigned char ) ( 0xb0 + ( V_80 & 0x0f ) ) ) ;
F_57 ( V_82 , 0x7b ) ;
F_57 ( V_82 , 0 ) ;
}
V_62 [ V_82 ] -> F_55 ( V_82 ) ;
V_122 [ V_82 ] = 0 ;
V_60 [ V_82 ] = 0 ;
}
}
V_58 = 0 ;
F_2 ( & V_11 , V_8 ) ;
if ( F_20 ( & V_67 ) ) {
F_8 ( & V_67 ) ;
}
F_3 ( & V_11 , V_8 ) ;
}
static void F_60 ( void )
{
F_18 () ;
}
int F_61 ( int V_1 , struct V_2 * V_2 , unsigned int F_31 , void T_1 * V_157 )
{
int V_150 , V_158 , V_100 , V_49 ;
int V_44 = F_12 ( V_2 ) ;
struct V_159 V_160 ;
struct V_161 V_23 ;
unsigned long V_8 ;
int T_1 * V_6 = V_157 ;
V_158 = V_1 = V_1 >> 4 ;
switch ( F_31 )
{
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
if ( V_9 != V_34 )
return - V_57 ;
return V_35 -> V_169 ( V_37 , F_31 , V_157 ) ;
case V_170 :
if ( V_9 != V_34 )
return - V_57 ;
if ( F_62 ( V_144 , V_6 ) )
return - V_171 ;
if ( V_144 < 0 || V_144 >= V_146 || V_147 [ V_144 ] == NULL )
{
V_144 = - 1 ;
return - V_57 ;
}
V_100 = V_144 ;
break;
case V_172 :
F_60 () ;
return - V_57 ;
case V_173 :
if ( V_44 == V_45 )
return 0 ;
while ( V_66 > 0 && ! F_52 ( V_153 ) )
F_54 () ;
return V_66 ? - V_174 : 0 ;
case V_175 :
F_18 () ;
return 0 ;
case V_176 :
if ( F_63 ( V_150 , V_6 ) )
return - V_171 ;
if ( V_150 < 0 || V_150 >= V_61 || ! V_62 [ V_150 ] )
return - V_53 ;
if ( ! V_60 [ V_150 ] &&
( V_49 = V_62 [ V_150 ] -> F_17 ( V_150 , V_44 , F_9 ,
F_6 ) ) < 0 )
return V_49 ;
V_60 [ V_150 ] = 1 ;
return 0 ;
case V_177 :
if ( V_44 == V_178 )
return 0 ;
V_100 = V_12 ;
break;
case V_179 :
if ( V_44 == V_45 )
return 0 ;
V_100 = V_22 - V_66 ;
break;
case V_180 :
if ( V_9 == V_34 )
return V_35 -> V_169 ( V_37 , F_31 , V_157 ) ;
V_100 = V_28 - V_29 ;
break;
case V_181 :
if ( V_9 == V_34 )
return V_35 -> V_169 ( V_37 , F_31 , V_157 ) ;
if ( F_62 ( V_100 , V_6 ) )
return - V_171 ;
if ( V_100 != 0 )
return - V_57 ;
V_100 = V_155 ;
break;
case V_182 :
case V_183 :
case V_184 :
if ( F_62 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_91 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_143 ;
return V_52 [ V_1 ] -> V_169 ( V_1 , F_31 , V_157 ) ;
case V_185 :
V_100 = V_51 ;
break;
case V_186 :
V_100 = V_61 ;
break;
case V_187 :
if ( F_62 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_91 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_143 ;
V_100 = V_52 [ V_1 ] -> V_169 ( V_1 , F_31 , V_157 ) ;
break;
case V_188 :
if ( F_62 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_91 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return - V_53 ;
V_52 [ V_1 ] -> V_169 ( V_1 , F_31 , V_157 ) ;
return 0 ;
case V_189 :
if ( F_62 ( V_1 , & ( (struct V_159 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_143 ;
return V_52 [ V_1 ] -> V_169 ( V_1 , F_31 , V_157 ) ;
case V_191 :
if ( F_62 ( V_1 , & ( (struct V_159 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_143 ;
memcpy ( & V_160 , V_52 [ V_1 ] -> V_192 , sizeof( V_160 ) ) ;
F_64 ( V_160 . V_193 , V_52 [ V_1 ] -> V_194 , sizeof( V_160 . V_193 ) ) ;
V_160 . V_190 = V_1 ;
return F_5 ( V_157 , & V_160 , sizeof( V_160 ) ) ? - V_171 : 0 ;
case V_195 :
if ( F_13 ( & V_23 , V_157 , sizeof( V_23 ) ) )
return - V_171 ;
F_2 ( & V_11 , V_8 ) ;
F_41 ( V_23 . V_196 ) ;
F_3 ( & V_11 , V_8 ) ;
return 0 ;
case V_197 :
if ( F_62 ( V_1 , & ( (struct V_198 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_61 || ! V_62 [ V_1 ] )
return - V_53 ;
V_62 [ V_1 ] -> V_192 . V_190 = V_1 ;
return F_5 ( V_157 , & V_62 [ V_1 ] -> V_192 , sizeof( struct V_198 ) ) ? - V_171 : 0 ;
case V_199 :
if ( F_62 ( V_100 , V_6 ) )
return - V_171 ;
if ( V_100 < 1 )
V_100 = 1 ;
if ( V_100 >= V_22 )
V_100 = V_22 - 1 ;
V_106 = V_100 ;
return 0 ;
case V_200 :
if ( F_62 ( V_100 , V_6 ) )
return - V_171 ;
if ( V_100 < 0 )
V_100 = 0 ;
V_100 = ( V_155 * V_100 ) / 10 ;
V_17 = V_100 ;
break;
default:
if ( V_44 == V_45 )
return - V_46 ;
if ( ! V_52 [ 0 ] )
return - V_53 ;
if ( ! ( V_54 & ( 1 << 0 ) ) )
return - V_53 ;
if ( ! V_52 [ 0 ] -> V_169 )
return - V_57 ;
return V_52 [ 0 ] -> V_169 ( 0 , F_31 , V_157 ) ;
}
return F_65 ( V_100 , V_6 ) ;
}
unsigned int F_66 ( int V_1 , struct V_2 * V_2 , T_2 * V_201 )
{
unsigned long V_8 ;
unsigned int V_202 = 0 ;
V_1 = V_1 >> 4 ;
F_2 ( & V_11 , V_8 ) ;
F_67 ( V_2 , & V_16 , V_201 ) ;
if ( V_12 )
V_202 |= V_203 | V_204 ;
F_67 ( V_2 , & V_67 , V_201 ) ;
if ( ( V_22 - V_66 ) >= V_106 )
V_202 |= V_205 | V_206 ;
F_3 ( & V_11 , V_8 ) ;
return V_202 ;
}
void F_68 ( unsigned long V_207 )
{
F_16 () ;
}
int F_69 ( int V_208 )
{
int V_64 , V_209 , V_210 ;
static int V_211 [] =
{
261632 , 277189 , 293671 , 311132 , 329632 , 349232 ,
369998 , 391998 , 415306 , 440000 , 466162 , 493880
} ;
#define F_70 5
V_209 = V_208 / 12 ;
V_64 = V_208 % 12 ;
V_210 = V_211 [ V_64 ] ;
if ( V_209 < F_70 )
V_210 >>= ( F_70 - V_209 ) ;
else if ( V_209 > F_70 )
V_210 <<= ( V_209 - F_70 ) ;
return V_210 ;
}
unsigned long F_71 ( unsigned long V_212 , int V_213 , int V_214 ,
int V_215 )
{
unsigned long V_216 ;
int V_217 , V_218 , V_219 , V_220 = 1 ;
if ( ! V_213 )
return V_212 ;
if ( ! V_214 )
return V_212 ;
if ( ! V_212 )
return V_212 ;
if ( V_214 >= 8192 )
V_214 = 8192 ;
V_213 = V_213 * V_214 / 8192 ;
V_213 += V_215 ;
if ( ! V_213 )
return V_212 ;
V_217 = V_213 < 0 ? 1 : 0 ;
if ( V_213 < 0 )
V_213 *= - 1 ;
if ( V_213 > V_214 )
V_213 = V_214 ;
while ( V_213 > 2399 )
{
V_220 *= 4 ;
V_213 -= 2400 ;
}
V_218 = V_213 / 100 ;
V_219 = V_213 % 100 ;
V_216 = ( int ) ( V_221 [ V_218 ] * V_220 * V_222 [ V_219 ] ) / 10000 ;
if ( V_217 )
return ( V_212 * 10000 ) / V_216 ;
else
return ( V_212 * V_216 ) / 10000 ;
}
void F_47 ( void )
{
if ( V_140 )
return;
V_69 = F_72 ( V_22 * V_41 ) ;
if ( V_69 == NULL )
{
F_15 ( V_223 L_8 ) ;
return;
}
V_19 = F_72 ( V_22 * V_21 ) ;
if ( V_19 == NULL )
{
F_15 ( V_223 L_9 ) ;
F_73 ( V_69 ) ;
return;
}
V_140 = 1 ;
}
void F_74 ( void )
{
F_73 ( V_69 ) ;
F_73 ( V_19 ) ;
V_69 = V_19 = NULL ;
}
