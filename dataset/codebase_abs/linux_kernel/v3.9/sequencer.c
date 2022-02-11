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
F_4 ( & V_16 ,
V_17 ) ;
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
F_13 ( F_14 ( L_1 , V_1 , V_4 ) ) ;
if ( V_44 == V_45 )
return - V_46 ;
V_5 = V_4 ;
while ( V_5 >= 4 )
{
if ( F_15 ( ( char * ) V_23 , & ( V_3 ) [ V_6 ] , 4 ) )
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
V_49 = V_52 [ V_1 ] -> F_16 ( V_1 , V_50 , V_3 + V_6 , V_5 , 0 ) ;
if ( V_49 < 0 )
return V_49 ;
return V_49 ;
}
if ( V_42 >= 128 )
{
if ( V_9 == V_34 && V_42 == V_55 )
{
F_14 ( V_56 L_2 , V_42 ) ;
return - V_57 ;
}
V_43 = 8 ;
if ( V_5 < V_43 )
{
if ( ! V_58 )
F_17 () ;
return V_4 - V_5 ;
}
if ( F_15 ( ( char * ) & V_23 [ 4 ] ,
& ( V_3 ) [ V_6 + 4 ] , 4 ) )
goto V_47;
}
else
{
if ( V_9 == V_34 )
{
F_14 ( V_56 L_3 ) ;
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
if ( ( V_49 = V_62 [ V_1 ] -> F_18 ( V_1 , V_44 ,
F_9 , F_6 ) ) < 0 )
{
F_19 () ;
F_14 ( V_56 L_4 , V_1 ) ;
return V_49 ;
}
V_60 [ V_1 ] = 1 ;
}
}
if ( ! F_20 ( V_23 , ( V_2 -> V_13 & ( V_14 ) ? 1 : 0 ) ) )
{
int V_63 = V_4 - V_5 ;
if ( ! V_58 )
F_17 () ;
if ( ! V_63 && ( V_2 -> V_13 & V_14 ) )
return - V_15 ;
else
return V_63 ;
}
V_6 += V_43 ;
V_5 -= V_43 ;
}
if ( ! V_58 )
F_17 () ;
V_47:
return V_4 ;
}
static int F_20 ( unsigned char * V_64 , char V_65 )
{
if ( V_66 >= V_22 )
if ( ! V_58 )
F_17 () ;
if ( ! V_65 && V_66 >= V_22 && ! F_21 ( & V_67 ) ) {
F_22 ( & V_67 ) ;
}
if ( V_66 >= V_22 )
{
return 0 ;
}
memcpy ( & V_68 [ V_69 * V_41 ] , V_64 , V_41 ) ;
V_69 = ( V_69 + 1 ) % V_22 ;
V_66 ++ ;
return 1 ;
}
static int F_23 ( unsigned char * V_70 )
{
int V_1 = V_70 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return - V_53 ;
switch ( V_70 [ 1 ] )
{
case V_71 :
V_52 [ V_1 ] -> F_24 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] , V_70 [ 5 ] ) ;
break;
case V_72 :
if ( V_70 [ 4 ] > 127 && V_70 [ 4 ] != 255 )
return 0 ;
if ( V_70 [ 5 ] == 0 )
{
V_52 [ V_1 ] -> F_24 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] , V_70 [ 5 ] ) ;
break;
}
V_52 [ V_1 ] -> F_25 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] , V_70 [ 5 ] ) ;
break;
case V_73 :
V_52 [ V_1 ] -> F_26 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] ) ;
break;
case V_74 :
V_52 [ V_1 ] -> F_27 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] ) ;
break;
case V_75 :
V_52 [ V_1 ] -> F_28 ( V_1 , V_70 [ 3 ] , ( char ) V_70 [ 4 ] ) ;
break;
case V_76 :
V_52 [ V_1 ] -> F_29 ( V_1 , V_70 [ 3 ] , V_70 [ 4 ] , ( short ) ( V_70 [ 5 ] | ( V_70 [ 6 ] << 8 ) ) ) ;
break;
case V_77 :
if ( V_52 [ V_1 ] -> V_78 != NULL )
V_52 [ V_1 ] -> V_78 ( V_1 , V_70 [ 3 ] ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_30 ( int V_1 , int V_79 , int V_64 )
{
unsigned short V_80 ;
int V_81 ;
V_80 = ( V_79 << 8 ) | ( V_64 + 1 ) ;
for ( V_81 = 0 ; V_81 < V_52 [ V_1 ] -> V_82 . V_83 ; V_81 ++ )
if ( V_52 [ V_1 ] -> V_82 . V_84 [ V_81 ] == V_80 )
return V_81 ;
return - 1 ;
}
static int F_31 ( int V_1 , int V_79 , int V_64 )
{
unsigned short V_80 ;
int V_85 ;
V_80 = ( V_79 << 8 ) | ( V_64 + 1 ) ;
V_85 = V_52 [ V_1 ] -> F_31 ( V_1 , V_79 , V_64 ,
& V_52 [ V_1 ] -> V_82 ) ;
V_52 [ V_1 ] -> V_82 . V_84 [ V_85 ] = V_80 ;
V_52 [ V_1 ] -> V_82 . V_86 [ V_85 ] =
V_52 [ V_1 ] -> V_82 . V_87 ++ ;
return V_85 ;
}
static void F_32 ( unsigned char * V_23 )
{
#define V_1 event_rec[1]
#define F_33 event_rec[2]
#define V_79 event_rec[3]
#define V_64 event_rec[4]
#define F_34 event_rec[5]
int V_85 = - 1 ;
if ( ( int ) V_1 > V_51 || V_52 [ V_1 ] == NULL )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
if ( V_9 == V_34 )
{
if ( V_52 [ V_1 ] -> F_31 )
V_85 = F_30 ( V_1 , V_79 , V_64 ) ;
if ( F_33 == V_88 && F_34 == 0 )
{
F_33 = V_89 ;
F_34 = 64 ;
}
}
switch ( F_33 )
{
case V_88 :
if ( V_64 > 127 && V_64 != 255 )
return;
if ( V_85 == - 1 && V_9 == V_34 && V_52 [ V_1 ] -> F_31 )
{
V_85 = F_31 ( V_1 , V_79 , V_64 ) ;
}
if ( V_85 == - 1 )
V_85 = V_79 ;
if ( V_9 == V_34 && ( int ) V_1 < V_90 )
{
if ( V_79 == 9 )
{
V_52 [ V_1 ] -> F_26 ( V_1 , V_85 , 128 + V_64 ) ;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_92 = 128 + V_64 ;
}
V_52 [ V_1 ] -> F_35 ( V_1 , V_85 , V_79 ) ;
}
V_52 [ V_1 ] -> F_25 ( V_1 , V_85 , V_64 , F_34 ) ;
break;
case V_89 :
if ( V_85 == - 1 )
V_85 = V_79 ;
V_52 [ V_1 ] -> F_24 ( V_1 , V_85 , V_64 , F_34 ) ;
break;
case V_93 :
if ( V_85 == - 1 )
V_85 = V_79 ;
V_52 [ V_1 ] -> F_27 ( V_1 , V_85 , F_34 ) ;
break;
default: ;
}
#undef V_1
#undef F_33
#undef V_79
#undef V_64
#undef F_34
}
static void F_36 ( unsigned char * V_23 )
{
unsigned char V_1 = V_23 [ 1 ] ;
unsigned char F_33 = V_23 [ 2 ] ;
unsigned char V_79 = V_23 [ 3 ] ;
unsigned char V_94 = V_23 [ 4 ] ;
unsigned short V_95 = * ( short * ) & V_23 [ 6 ] ;
if ( ( int ) V_1 > V_51 || V_52 [ V_1 ] == NULL )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
switch ( F_33 )
{
case V_96 :
if ( V_9 == V_34 )
{
if ( V_79 > 15 )
break;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_92 = V_94 ;
if ( ( int ) V_1 >= V_90 )
V_52 [ V_1 ] -> F_26 ( V_1 , V_79 , V_94 ) ;
}
else
V_52 [ V_1 ] -> F_26 ( V_1 , V_79 , V_94 ) ;
break;
case V_97 :
if ( V_9 == V_34 )
{
if ( V_79 > 15 || V_94 > 127 )
break;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_98 [ V_94 ] = V_95 & 0x7f ;
if ( V_94 < 32 )
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_98 [ V_94 + 32 ] = 0 ;
if ( ( int ) V_1 < V_90 )
{
int V_99 = V_95 & 0x7f ;
int V_81 , V_80 ;
if ( V_94 < 64 )
{
V_99 = ( ( V_52 [ V_1 ] ->
V_91 [ V_79 ] . V_98 [ V_94 & ~ 32 ] & 0x7f ) << 7 )
| ( V_52 [ V_1 ] ->
V_91 [ V_79 ] . V_98 [ V_94 | 32 ] & 0x7f ) ;
V_94 &= ~ 32 ;
}
V_80 = ( ( int ) V_79 << 8 ) ;
for ( V_81 = 0 ; V_81 < V_52 [ V_1 ] -> V_82 . V_83 ; V_81 ++ )
if ( ( V_52 [ V_1 ] -> V_82 . V_84 [ V_81 ] & 0xff00 ) == V_80 )
V_52 [ V_1 ] -> F_29 ( V_1 , V_81 , V_94 , V_99 ) ;
}
else
V_52 [ V_1 ] -> F_29 ( V_1 , V_79 , V_94 , V_95 ) ;
}
else
V_52 [ V_1 ] -> F_29 ( V_1 , V_79 , V_94 , V_95 ) ;
break;
case V_100 :
if ( V_9 == V_34 )
{
if ( V_79 > 15 )
break;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_101 = V_95 ;
if ( ( int ) V_1 < V_90 )
{
int V_81 , V_80 ;
V_80 = ( V_79 << 8 ) ;
for ( V_81 = 0 ; V_81 < V_52 [ V_1 ] -> V_82 . V_83 ; V_81 ++ )
if ( ( V_52 [ V_1 ] -> V_82 . V_84 [ V_81 ] & 0xff00 ) == V_80 )
V_52 [ V_1 ] -> F_37 ( V_1 , V_81 , V_95 ) ;
}
else
V_52 [ V_1 ] -> F_37 ( V_1 , V_79 , V_95 ) ;
}
else
V_52 [ V_1 ] -> F_37 ( V_1 , V_79 , V_95 ) ;
break;
default: ;
}
}
static int F_38 ( unsigned char * V_23 )
{
unsigned char F_33 = V_23 [ 1 ] ;
unsigned int F_34 = * ( int * ) & V_23 [ 4 ] ;
if ( V_9 == V_34 )
{
int V_102 ;
if ( ( V_102 = V_35 -> V_103 ( V_37 , V_23 ) ) == V_104 )
if ( ( V_22 - V_66 ) >= V_105 )
F_8 ( & V_67 ) ;
return V_102 ;
}
switch ( F_33 )
{
case V_106 :
F_34 += V_107 ;
case V_40 :
if ( F_34 > 0 )
{
long time ;
time = F_34 ;
V_107 = time ;
V_58 = 1 ;
F_39 ( time ) ;
if ( ( V_22 - V_66 ) >= V_105 )
F_8 ( & V_67 ) ;
return V_104 ;
}
break;
case V_108 :
V_29 = V_28 ;
V_30 = 0 ;
V_107 = 0 ;
break;
case V_109 :
break;
case V_110 :
break;
case V_111 :
break;
case V_112 :
if ( V_9 == V_34 )
F_7 ( V_23 , 8 ) ;
else
{
F_34 = ( F_34 << 8 | V_113 ) ;
F_7 ( ( unsigned char * ) & F_34 , 4 ) ;
}
break;
default: ;
}
return V_114 ;
}
static void F_40 ( unsigned char * V_23 )
{
unsigned char F_33 = V_23 [ 1 ] ;
unsigned int F_34 = * ( ( unsigned int * ) & V_23 [ 4 ] ) ;
switch ( F_33 )
{
case V_115 :
F_41 ( F_34 ) ;
break;
default: ;
}
}
static void F_42 ( unsigned char * V_23 )
{
unsigned int V_1 = V_23 [ 1 ] ;
int V_81 , V_116 = 0 ;
unsigned char * V_3 = & V_23 [ 2 ] ;
if ( V_1 > V_51 )
return;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return;
if ( ! V_52 [ V_1 ] )
return;
V_116 = 0 ;
for ( V_81 = 0 ; V_81 < 6 && V_3 [ V_81 ] != 0xff ; V_81 ++ )
V_116 = V_81 + 1 ;
if ( ! V_52 [ V_1 ] -> V_117 )
return;
if ( V_116 > 0 )
V_52 [ V_1 ] -> V_117 ( V_1 , V_3 , V_116 ) ;
}
static int F_43 ( unsigned char * V_70 )
{
unsigned int * V_118 ;
switch ( V_70 [ 0 ] )
{
case V_71 :
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_24 ( 0 , V_70 [ 1 ] , 255 , V_70 [ 3 ] ) ;
break;
case V_72 :
if ( V_70 [ 4 ] < 128 || V_70 [ 4 ] == 255 )
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_25 ( 0 , V_70 [ 1 ] , V_70 [ 2 ] , V_70 [ 3 ] ) ;
break;
case V_31 :
V_118 = ( unsigned int * ) V_70 ;
* V_118 = ( * V_118 >> 8 ) & 0xffffff ;
if ( * V_118 > 0 )
{
long time ;
V_58 = 1 ;
time = * V_118 ;
V_107 = time ;
F_39 ( time ) ;
if ( ( V_22 - V_66 ) >= V_105 )
F_8 ( & V_67 ) ;
return 1 ;
}
break;
case V_73 :
if ( V_54 & ( 1 << 0 ) )
if ( V_52 [ 0 ] )
V_52 [ 0 ] -> F_26 ( 0 , V_70 [ 1 ] , V_70 [ 2 ] ) ;
break;
case V_119 :
V_29 = V_28 ;
V_30 = 0 ;
V_107 = 0 ;
break;
case V_32 :
if ( V_60 [ V_70 [ 2 ] ] )
{
int V_1 ;
V_1 = V_70 [ 2 ] ;
if ( V_1 < 0 || V_1 >= V_120 || V_62 [ V_1 ] == NULL )
break;
if ( ! V_62 [ V_1 ] -> F_44 ( V_1 , V_70 [ 1 ] ) )
{
V_58 = 1 ;
F_39 ( - 1 ) ;
return 2 ;
}
else
V_121 [ V_1 ] = 1 ;
}
break;
case V_113 :
F_7 ( V_70 , 4 ) ;
break;
case V_122 :
if ( ( int ) V_70 [ 1 ] < V_51 )
V_52 [ V_70 [ 1 ] ] -> F_45 ( V_70 [ 1 ] , V_70 ) ;
break;
case V_55 :
F_23 ( V_70 ) ;
break;
case V_123 :
F_32 ( V_70 ) ;
break;
case V_124 :
F_36 ( V_70 ) ;
break;
case V_39 :
if ( F_38 ( V_70 ) == V_104 )
{
return 1 ;
}
break;
case V_125 :
F_40 ( V_70 ) ;
break;
case V_126 :
F_42 ( V_70 ) ;
break;
default: ;
}
return 0 ;
}
static void F_17 ( void )
{
int V_127 , V_128 ;
unsigned long V_8 ;
while ( V_66 > 0 )
{
F_2 ( & V_11 , V_8 ) ;
V_129 = ( ( V_127 = V_129 ) + 1 ) % V_22 ;
V_66 -- ;
F_3 ( & V_11 , V_8 ) ;
V_58 = 1 ;
if ( ( V_128 = F_43 ( & V_68 [ V_127 * V_41 ] ) ) )
{
if ( V_128 == 2 )
{
V_66 ++ ;
V_129 = V_127 ;
}
return;
}
}
V_58 = 0 ;
if ( ( V_22 - V_66 ) >= V_105 )
F_8 ( & V_67 ) ;
}
static void F_46 ( int V_1 , unsigned char * F_29 , int V_130 )
{
int V_81 ;
for ( V_81 = 0 ; V_81 < 128 ; V_81 ++ )
F_29 [ V_81 ] = V_131 [ V_81 ] ;
}
static void F_47 ( void )
{
int V_1 ;
V_51 = V_90 ;
for ( V_1 = 0 ; V_1 < V_120 ; V_1 ++ )
{
if ( V_62 [ V_1 ] && V_62 [ V_1 ] -> V_132 != NULL )
{
V_52 [ V_51 ++ ] = V_62 [ V_1 ] -> V_132 ;
}
}
for ( V_1 = 0 ; V_1 < V_51 ; V_1 ++ )
{
int V_79 ;
V_52 [ V_1 ] -> V_133 = 0 ;
V_52 [ V_1 ] -> V_134 = 0 ;
for ( V_79 = 0 ; V_79 < 16 ; V_79 ++ )
{
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_92 = 0 ;
F_46 ( V_1 ,
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_98 , 0 ) ;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_101 = ( 1 << 7 ) ;
V_52 [ V_1 ] -> V_91 [ V_79 ] . V_135 = 200 ;
}
}
V_61 = 0 ;
V_9 = V_34 ;
}
int F_48 ( int V_1 , struct V_2 * V_2 )
{
int V_136 , V_44 , V_81 ;
int V_137 , V_138 ;
if ( ! V_139 )
F_49 () ;
V_137 = ( ( V_1 & 0x0f ) == V_140 ) ? 2 : 1 ;
V_1 = V_1 >> 4 ;
V_44 = F_12 ( V_2 ) ;
F_13 ( F_14 ( L_5 , V_1 ) ) ;
if ( ! V_139 )
{
return - V_53 ;
}
if ( V_1 )
return - V_53 ;
if( V_52 [ V_1 ] == NULL )
F_50 ( L_6 ) ;
if ( V_44 == V_45 )
{
if ( ! V_120 )
{
V_141 = 0 ;
return - V_53 ;
}
}
if ( V_141 )
{
return - V_142 ;
}
V_141 = 1 ;
V_59 = 0 ;
V_61 = V_120 ;
V_51 = V_90 ;
V_17 = V_143 ;
V_9 = V_10 ;
if ( V_144 != - 1 )
{
V_37 = V_144 ;
V_144 = - 1 ;
}
if ( V_37 == - 1 )
{
int V_81 , V_145 ;
V_145 = - 1 ;
for ( V_81 = 0 ; V_81 < V_146 ; V_81 ++ )
if ( V_147 [ V_81 ] && V_147 [ V_81 ] -> V_148 > V_145 )
{
V_37 = V_81 ;
V_145 = V_147 [ V_81 ] -> V_148 ;
}
if ( V_37 == - 1 )
V_37 = 0 ;
}
V_35 = V_147 [ V_37 ] ;
if ( V_137 == 2 )
{
if ( V_35 == NULL )
{
V_141 = 0 ;
return - V_53 ;
}
F_47 () ;
}
if ( ! V_51 && ! V_61 )
{
V_141 = 0 ;
return - V_53 ;
}
V_54 = 0 ;
for ( V_81 = 0 ; V_81 < V_61 ; V_81 ++ )
{
V_60 [ V_81 ] = 0 ;
V_121 [ V_81 ] = 0 ;
}
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ )
{
if ( V_52 [ V_81 ] == NULL )
continue;
if ( ! F_51 ( V_52 [ V_81 ] -> V_149 ) )
continue;
if ( ( V_138 = V_52 [ V_81 ] -> F_18 ( V_81 , V_44 ) ) < 0 )
{
F_14 ( V_56 L_7 , V_81 , V_138 ) ;
if ( V_52 [ V_81 ] -> V_150 )
F_14 ( V_56 L_8 , V_52 [ V_81 ] -> V_150 ) ;
}
else
{
V_54 |= ( 1 << V_81 ) ;
if ( V_52 [ V_81 ] -> V_150 )
V_60 [ V_52 [ V_81 ] -> V_150 ] = 1 ;
}
}
V_29 = V_28 ;
V_30 = 0 ;
V_107 = 0 ;
if ( V_9 == V_10 && ( V_44 == V_45 || V_44 == V_151 ) )
{
for ( V_81 = 0 ; V_81 < V_61 ; V_81 ++ )
if ( ! V_60 [ V_81 ] && V_62 [ V_81 ] )
{
if ( ! F_51 ( V_62 [ V_81 ] -> V_149 ) )
continue;
if ( ( V_136 = V_62 [ V_81 ] -> F_18 ( V_81 , V_44 ,
F_9 , F_6 ) ) >= 0 )
{
V_60 [ V_81 ] = 1 ;
}
}
}
if ( V_9 == V_34 ) {
if ( F_51 ( V_35 -> V_149 ) )
V_35 -> F_18 ( V_37 , V_9 ) ;
}
F_52 ( & V_67 ) ;
F_52 ( & V_16 ) ;
V_105 = V_22 / 2 ;
return 0 ;
}
static void F_53 ( void )
{
int V_81 , V_152 ;
V_152 = 1 ;
while ( ! F_54 ( V_153 ) && V_152 )
{
V_152 = 0 ;
for ( V_81 = 0 ; V_81 < V_61 ; V_81 ++ )
if ( V_60 [ V_81 ] && V_121 [ V_81 ] )
if ( V_62 [ V_81 ] -> V_154 != NULL )
if ( V_62 [ V_81 ] -> V_154 ( V_81 ) )
V_152 ++ ;
if ( V_152 )
F_4 ( & V_67 ,
V_155 / 10 ) ;
}
}
void F_55 ( int V_1 , struct V_2 * V_2 )
{
int V_81 ;
int V_44 = F_12 ( V_2 ) ;
V_1 = V_1 >> 4 ;
F_13 ( F_14 ( L_9 , V_1 ) ) ;
if ( V_44 != V_45 && ! ( V_2 -> V_13 & V_14 ) )
{
while ( ! F_54 ( V_153 ) && V_66 > 0 )
{
F_56 () ;
F_4 ( & V_67 ,
3 * V_155 ) ;
}
}
if ( V_44 != V_45 )
F_53 () ;
F_19 () ;
if ( V_44 != V_45 )
F_53 () ;
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ )
{
if ( V_54 & ( 1 << V_81 ) )
if ( V_52 [ V_81 ] )
{
V_52 [ V_81 ] -> F_57 ( V_81 ) ;
F_58 ( V_52 [ V_81 ] -> V_149 ) ;
if ( V_52 [ V_81 ] -> V_150 )
V_60 [ V_52 [ V_81 ] -> V_150 ] = 0 ;
}
}
for ( V_81 = 0 ; V_81 < V_61 ; V_81 ++ )
{
if ( V_60 [ V_81 ] ) {
V_62 [ V_81 ] -> F_57 ( V_81 ) ;
F_58 ( V_62 [ V_81 ] -> V_149 ) ;
}
}
if ( V_9 == V_34 ) {
V_35 -> F_57 ( V_37 ) ;
F_58 ( V_35 -> V_149 ) ;
}
if ( V_59 )
F_14 ( V_56 L_10 , V_153 -> V_156 ) ;
V_141 = 0 ;
}
static int F_56 ( void )
{
if ( V_66 && ! V_58 && ! F_54 ( V_153 ) )
F_17 () ;
if ( V_66 > 0 )
F_4 ( & V_67 , V_155 ) ;
return V_66 ;
}
static void F_59 ( int V_1 , unsigned char V_26 )
{
int V_152 ;
unsigned long V_8 ;
V_152 = 3 * V_155 ;
F_2 ( & V_11 , V_8 ) ;
while ( V_152 && ! V_62 [ V_1 ] -> F_44 ( V_1 , V_26 ) ) {
F_4 ( & V_67 , V_155 / 25 ) ;
V_152 -- ;
}
F_3 ( & V_11 , V_8 ) ;
}
static void F_19 ( void )
{
int V_81 ;
int V_79 ;
unsigned long V_8 ;
F_60 () ;
V_29 = V_28 ;
V_30 = 0 ;
V_107 = 0 ;
V_66 = V_129 = V_69 = 0 ;
V_12 = V_20 = V_25 = 0 ;
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ )
if ( V_54 & ( 1 << V_81 ) )
if ( V_52 [ V_81 ] )
V_52 [ V_81 ] -> F_61 ( V_81 ) ;
if ( V_9 == V_34 )
{
for ( V_79 = 0 ; V_79 < 16 ; V_79 ++ )
for ( V_81 = 0 ; V_81 < V_51 ; V_81 ++ )
if ( V_54 & ( 1 << V_81 ) )
if ( V_52 [ V_81 ] )
{
V_52 [ V_81 ] -> F_29 ( V_81 , V_79 , 123 , 0 ) ;
V_52 [ V_81 ] -> F_29 ( V_81 , V_79 , 121 , 0 ) ;
V_52 [ V_81 ] -> F_37 ( V_81 , V_79 , 1 << 13 ) ;
}
}
else
{
for ( V_81 = 0 ; V_81 < V_61 ; V_81 ++ )
if ( V_121 [ V_81 ] )
{
F_59 ( V_81 , 0xfe ) ;
for ( V_79 = 0 ; V_79 < 16 ; V_79 ++ )
{
F_59 ( V_81 , ( unsigned char ) ( 0xb0 + ( V_79 & 0x0f ) ) ) ;
F_59 ( V_81 , 0x7b ) ;
F_59 ( V_81 , 0 ) ;
}
V_62 [ V_81 ] -> F_57 ( V_81 ) ;
V_121 [ V_81 ] = 0 ;
V_60 [ V_81 ] = 0 ;
}
}
V_58 = 0 ;
F_2 ( & V_11 , V_8 ) ;
if ( F_21 ( & V_67 ) ) {
F_8 ( & V_67 ) ;
}
F_3 ( & V_11 , V_8 ) ;
}
static void F_62 ( void )
{
F_19 () ;
}
int F_63 ( int V_1 , struct V_2 * V_2 , unsigned int F_33 , void T_1 * V_157 )
{
int V_150 , V_158 , V_99 , V_49 ;
int V_44 = F_12 ( V_2 ) ;
struct V_159 V_160 ;
struct V_161 V_23 ;
unsigned long V_8 ;
int T_1 * V_6 = V_157 ;
V_158 = V_1 = V_1 >> 4 ;
switch ( F_33 )
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
return V_35 -> V_169 ( V_37 , F_33 , V_157 ) ;
case V_170 :
if ( V_9 != V_34 )
return - V_57 ;
if ( F_64 ( V_144 , V_6 ) )
return - V_171 ;
if ( V_144 < 0 || V_144 >= V_146 || V_147 [ V_144 ] == NULL )
{
V_144 = - 1 ;
return - V_57 ;
}
V_99 = V_144 ;
break;
case V_172 :
F_62 () ;
return - V_57 ;
case V_173 :
if ( V_44 == V_45 )
return 0 ;
while ( V_66 > 0 && ! F_54 ( V_153 ) )
F_56 () ;
return V_66 ? - V_174 : 0 ;
case V_175 :
F_19 () ;
return 0 ;
case V_176 :
if ( F_65 ( V_150 , V_6 ) )
return - V_171 ;
if ( V_150 < 0 || V_150 >= V_61 || ! V_62 [ V_150 ] )
return - V_53 ;
if ( ! V_60 [ V_150 ] &&
( V_49 = V_62 [ V_150 ] -> F_18 ( V_150 , V_44 , F_9 ,
F_6 ) ) < 0 )
return V_49 ;
V_60 [ V_150 ] = 1 ;
return 0 ;
case V_177 :
if ( V_44 == V_178 )
return 0 ;
V_99 = V_12 ;
break;
case V_179 :
if ( V_44 == V_45 )
return 0 ;
V_99 = V_22 - V_66 ;
break;
case V_180 :
if ( V_9 == V_34 )
return V_35 -> V_169 ( V_37 , F_33 , V_157 ) ;
V_99 = V_28 - V_29 ;
break;
case V_181 :
if ( V_9 == V_34 )
return V_35 -> V_169 ( V_37 , F_33 , V_157 ) ;
if ( F_64 ( V_99 , V_6 ) )
return - V_171 ;
if ( V_99 != 0 )
return - V_57 ;
V_99 = V_155 ;
break;
case V_182 :
case V_183 :
case V_184 :
if ( F_64 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_90 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_142 ;
return V_52 [ V_1 ] -> V_169 ( V_1 , F_33 , V_157 ) ;
case V_185 :
V_99 = V_51 ;
break;
case V_186 :
V_99 = V_61 ;
break;
case V_187 :
if ( F_64 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_90 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_142 ;
V_99 = V_52 [ V_1 ] -> V_169 ( V_1 , F_33 , V_157 ) ;
break;
case V_188 :
if ( F_64 ( V_1 , V_6 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_90 || V_52 [ V_1 ] == NULL )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) )
return - V_53 ;
V_52 [ V_1 ] -> V_169 ( V_1 , F_33 , V_157 ) ;
return 0 ;
case V_189 :
if ( F_64 ( V_1 , & ( (struct V_159 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_142 ;
return V_52 [ V_1 ] -> V_169 ( V_1 , F_33 , V_157 ) ;
case V_191 :
if ( F_64 ( V_1 , & ( (struct V_159 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_51 )
return - V_53 ;
if ( ! ( V_54 & ( 1 << V_1 ) ) && ! V_158 )
return - V_142 ;
memcpy ( & V_160 , V_52 [ V_1 ] -> V_192 , sizeof( V_160 ) ) ;
F_66 ( V_160 . V_193 , V_52 [ V_1 ] -> V_194 , sizeof( V_160 . V_193 ) ) ;
V_160 . V_190 = V_1 ;
return F_5 ( V_157 , & V_160 , sizeof( V_160 ) ) ? - V_171 : 0 ;
case V_195 :
if ( F_15 ( & V_23 , V_157 , sizeof( V_23 ) ) )
return - V_171 ;
F_2 ( & V_11 , V_8 ) ;
F_43 ( V_23 . V_196 ) ;
F_3 ( & V_11 , V_8 ) ;
return 0 ;
case V_197 :
if ( F_64 ( V_1 , & ( (struct V_198 T_1 * ) V_157 ) -> V_190 ) )
return - V_171 ;
if ( V_1 < 0 || V_1 >= V_61 || ! V_62 [ V_1 ] )
return - V_53 ;
V_62 [ V_1 ] -> V_192 . V_190 = V_1 ;
return F_5 ( V_157 , & V_62 [ V_1 ] -> V_192 , sizeof( struct V_198 ) ) ? - V_171 : 0 ;
case V_199 :
if ( F_64 ( V_99 , V_6 ) )
return - V_171 ;
if ( V_99 < 1 )
V_99 = 1 ;
if ( V_99 >= V_22 )
V_99 = V_22 - 1 ;
V_105 = V_99 ;
return 0 ;
case V_200 :
if ( F_64 ( V_99 , V_6 ) )
return - V_171 ;
if ( V_99 < 0 )
V_99 = 0 ;
V_99 = ( V_155 * V_99 ) / 10 ;
V_17 = V_99 ;
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
return V_52 [ 0 ] -> V_169 ( 0 , F_33 , V_157 ) ;
}
return F_67 ( V_99 , V_6 ) ;
}
unsigned int F_68 ( int V_1 , struct V_2 * V_2 , T_2 * V_201 )
{
unsigned long V_8 ;
unsigned int V_202 = 0 ;
V_1 = V_1 >> 4 ;
F_2 ( & V_11 , V_8 ) ;
F_69 ( V_2 , & V_16 , V_201 ) ;
if ( V_12 )
V_202 |= V_203 | V_204 ;
F_69 ( V_2 , & V_67 , V_201 ) ;
if ( ( V_22 - V_66 ) >= V_105 )
V_202 |= V_205 | V_206 ;
F_3 ( & V_11 , V_8 ) ;
return V_202 ;
}
void F_70 ( unsigned long V_207 )
{
F_17 () ;
}
int F_71 ( int V_208 )
{
int V_64 , V_209 , V_210 ;
static int V_211 [] =
{
261632 , 277189 , 293671 , 311132 , 329632 , 349232 ,
369998 , 391998 , 415306 , 440000 , 466162 , 493880
} ;
#define F_72 5
V_209 = V_208 / 12 ;
V_64 = V_208 % 12 ;
V_210 = V_211 [ V_64 ] ;
if ( V_209 < F_72 )
V_210 >>= ( F_72 - V_209 ) ;
else if ( V_209 > F_72 )
V_210 <<= ( V_209 - F_72 ) ;
return V_210 ;
}
unsigned long F_73 ( unsigned long V_212 , int V_213 , int V_214 ,
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
void F_49 ( void )
{
if ( V_139 )
return;
V_68 = F_74 ( V_22 * V_41 ) ;
if ( V_68 == NULL )
{
F_14 ( V_223 L_11 ) ;
return;
}
V_19 = F_74 ( V_22 * V_21 ) ;
if ( V_19 == NULL )
{
F_14 ( V_223 L_12 ) ;
F_75 ( V_68 ) ;
return;
}
V_139 = 1 ;
}
void F_76 ( void )
{
F_75 ( V_68 ) ;
F_75 ( V_19 ) ;
V_68 = V_19 = NULL ;
}
