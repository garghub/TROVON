static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
int V_10 , V_11 ;
T_2 * V_12 = V_7 -> V_13 ;
V_11 = V_7 -> V_14 . V_15 ;
if ( V_11 == 16 )
V_11 = ( V_7 -> V_14 . V_3 . V_16 == 5 ) ? 15 : 16 ;
if ( V_1 > 255 ||
( V_11 == 16 && V_1 > 63 ) ||
( V_11 == 15 && V_1 > 31 ) )
return 1 ;
if ( V_1 < 16 ) {
switch ( V_11 ) {
case 15 :
V_12 [ V_1 ] = ( V_1 << 10 ) | ( V_1 << 5 ) | V_1 ;
break;
case 16 :
V_12 [ V_1 ] = ( V_1 << 11 ) | ( V_1 << 5 ) | V_1 ;
break;
case 24 :
V_12 [ V_1 ] = ( V_1 << 16 ) | ( V_1 << 8 ) | V_1 ;
break;
case 32 :
V_10 = ( V_1 << 8 ) | V_1 ;
V_12 [ V_1 ] = ( V_10 << 16 ) | V_10 ;
break;
}
}
V_2 >>= 8 ;
V_3 >>= 8 ;
V_4 >>= 8 ;
if ( ! V_9 -> V_17 )
return 0 ;
switch ( V_9 -> V_18 ) {
case V_19 :
F_2 ( V_1 , V_9 -> V_17 ) ;
F_2 ( V_2 , V_9 -> V_20 ) ;
F_2 ( V_3 , V_9 -> V_20 ) ;
F_2 ( V_4 , V_9 -> V_20 ) ;
break;
case V_21 :
F_3 ( V_9 -> V_17 + 0x58 ,
F_4 ( V_9 -> V_17 + 0x58 ) & ~ 0x20 ) ;
case V_22 :
F_5 ( V_9 -> V_17 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_17 + 0xb4 ,
( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_23 :
F_3 ( V_9 -> V_17 + 0x58 ,
F_4 ( V_9 -> V_17 + 0x58 ) | 0x20 ) ;
F_5 ( V_9 -> V_17 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_17 + 0xb4 , ( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_24 :
F_5 ( V_9 -> V_17 + 0xb0 , V_1 ) ;
F_3 ( V_9 -> V_17 + 0xb4 , ( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_25 :
F_3 ( ( ( unsigned V_26 * ) V_9 -> V_17 ) + V_1 ,
( V_2 << 16 | V_3 << 8 | V_4 ) ) ;
break;
case V_27 :
F_6 ( 1 , V_9 -> V_17 + V_28 ) ;
F_2 ( V_1 , V_9 -> V_17 + V_29 ) ;
F_6 ( ( ( V_2 ) << 22 ) | ( ( V_3 ) << 12 ) | ( ( V_4 ) << 2 ) ,
V_9 -> V_17 + V_30 ) ;
F_6 ( 0 , V_9 -> V_17 + V_28 ) ;
F_2 ( V_1 , V_9 -> V_17 + V_29 ) ;
F_6 ( ( ( V_2 ) << 22 ) | ( ( V_3 ) << 12 ) | ( ( V_4 ) << 2 ) ,
V_9 -> V_17 + V_30 ) ;
break;
}
return 0 ;
}
static int F_7 ( int V_31 , struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
int V_10 , V_32 ;
if ( ! V_9 -> V_17 )
return 0 ;
if ( ! V_9 -> V_33 )
if ( ! V_31 )
return 0 ;
V_9 -> V_33 = V_31 ;
if ( V_31 )
for ( V_10 = 0 ; V_10 < 256 ; V_10 ++ ) {
switch ( V_9 -> V_18 ) {
case V_19 :
F_2 ( V_10 , V_9 -> V_17 ) ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ )
F_2 ( 0 , V_9 -> V_20 ) ;
break;
case V_21 :
F_3 ( V_9 -> V_17 + 0x58 ,
F_4 ( V_9 -> V_17 + 0x58 ) & ~ 0x20 ) ;
case V_22 :
F_5 ( V_9 -> V_17 + 0xb0 , V_10 ) ;
F_3 ( V_9 -> V_17 + 0xb4 , 0 ) ;
break;
case V_23 :
F_3 ( V_9 -> V_17 + 0x58 ,
F_4 ( V_9 -> V_17 + 0x58 ) | 0x20 ) ;
F_5 ( V_9 -> V_17 + 0xb0 , V_10 ) ;
F_3 ( V_9 -> V_17 + 0xb4 , 0 ) ;
break;
case V_24 :
F_5 ( V_9 -> V_17 + 0xb0 , V_10 ) ;
F_3 ( V_9 -> V_17 + 0xb4 , 0 ) ;
break;
case V_25 :
F_3 ( ( ( unsigned V_26 * ) V_9 -> V_17 ) + V_10 ,
0 ) ;
break;
case V_27 :
F_6 ( 1 , V_9 -> V_17 + V_28 ) ;
F_2 ( V_10 , V_9 -> V_17 + V_29 ) ;
F_6 ( 0 , V_9 -> V_17 + V_30 ) ;
F_6 ( 0 , V_9 -> V_17 + V_28 ) ;
F_2 ( V_10 , V_9 -> V_17 + V_29 ) ;
F_6 ( 0 , V_9 -> V_17 + V_30 ) ;
break;
}
} else
F_8 ( & V_7 -> V_34 , V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
if ( V_9 -> V_18 == V_27 ) {
F_6 ( 0 , V_9 -> V_17 + V_35 ) ;
F_6 ( 0 , V_9 -> V_17 + V_36 ) ;
F_6 ( 0 , V_9 -> V_17 + V_37 ) ;
F_6 ( 0 , V_9 -> V_17 + V_38 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_39 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_40 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_41 ) ;
F_6 ( 0 , V_9 -> V_17 + V_42 ) ;
F_6 ( 0 , V_9 -> V_17 + V_43 ) ;
F_6 ( 0 , V_9 -> V_17 + V_44 ) ;
F_6 ( 0 , V_9 -> V_17 + V_45 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_46 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_47 ) ;
F_6 ( 0x0000ffff , V_9 -> V_17 + V_48 ) ;
F_6 ( 1 , V_9 -> V_17 + V_28 ) ;
F_6 ( 0 , V_9 -> V_17 + V_49 ) ;
F_6 ( 0x0000003f , V_9 -> V_17 + V_50 ) ;
F_6 ( 0 , V_9 -> V_17 + V_28 ) ;
F_6 ( 0 , V_9 -> V_17 + V_49 ) ;
F_6 ( 0x0000003f , V_9 -> V_17 + V_50 ) ;
}
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
if ( V_7 -> V_51 )
F_11 ( V_7 -> V_51 ) ;
F_12 ( V_7 -> V_52 -> V_53 [ 0 ] . V_54 , V_7 -> V_52 -> V_53 [ 0 ] . V_55 ) ;
F_13 ( V_7 ) ;
}
static void V_26 * F_14 ( struct V_56 * V_57 , int V_58 ,
unsigned long V_59 , unsigned long V_55 )
{
const T_2 * V_60 ;
T_3 V_61 , V_62 ;
unsigned int V_63 ;
V_60 = F_15 ( V_57 , V_58 , & V_61 , & V_63 ) ;
if ( V_60 == NULL )
V_60 = F_16 ( V_57 , V_58 , & V_61 , & V_63 ) ;
if ( V_60 == NULL )
return NULL ;
if ( ( V_63 & ( V_64 | V_65 ) ) == 0 )
return NULL ;
if ( ( V_59 + V_55 ) > V_61 )
return NULL ;
V_62 = F_17 ( V_57 , V_60 ) ;
if ( V_62 == V_66 )
return NULL ;
return F_18 ( V_62 + V_59 , V_55 ) ;
}
static void F_19 ( struct V_6 * V_7 , struct V_56 * V_67 ,
const char * V_68 , unsigned long V_69 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 -> V_9 ;
if ( V_67 && ! strncmp ( V_68 , L_1 , 11 ) ) {
V_9 -> V_17 = F_14 ( V_67 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_22 ;
} else if ( V_67 && ( ! strncmp ( V_68 , L_2 , 12 )
|| ! strncmp ( V_68 , L_3 , 14 ) ) ) {
V_9 -> V_17 = F_14 ( V_67 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_21 ;
} else if ( V_67 && ! strncmp ( V_68 , L_4 , 12 ) ) {
V_9 -> V_17 = F_14 ( V_67 , 2 , 0 , 0x1fff ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_23 ;
} else if ( V_67 && ! strncmp ( V_68 , L_5 , 9 ) ) {
V_9 -> V_17 = F_14 ( V_67 , 1 , 0 , 0x1fff ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_24 ;
} else if ( ! strncmp ( V_68 , L_6 , 4 ) ) {
unsigned long V_54 = V_69 & 0xff000000UL ;
V_9 -> V_17 =
F_18 ( V_54 + 0x7ff000 , 0x1000 ) + 0xcc0 ;
V_9 -> V_20 = V_9 -> V_17 + 1 ;
V_9 -> V_18 = V_19 ;
} else if ( V_67 && ( F_20 ( V_67 , L_7 ) ||
F_20 ( V_67 , L_8 ) ) ) {
V_9 -> V_17 = F_14 ( V_67 , 0 , 0x6000 , 0x1000 ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_25 ;
} else if ( V_67 && ! strncmp ( V_68 , L_9 , 12 ) ) {
struct V_56 * V_70 = F_21 ( V_67 ) ;
const T_2 * V_71 , * V_72 ;
V_71 = F_22 ( V_70 , L_10 , NULL ) ;
V_72 = F_22 ( V_70 , L_11 , NULL ) ;
if ( V_71 && V_72 && * V_71 == 0x1002 &&
( ( * V_72 >= 0x7100 && * V_72 < 0x7800 ) ||
( * V_72 >= 0x9400 ) ) ) {
V_9 -> V_17 = F_14 ( V_70 , 2 , 0 , 0x10000 ) ;
if ( V_9 -> V_17 )
V_9 -> V_18 = V_27 ;
}
F_23 ( V_70 ) ;
}
V_7 -> V_73 . V_74 = ( V_9 -> V_18 != V_75 ) ?
V_76 : V_77 ;
}
static void T_4 F_24 ( const char * V_68 , const char * V_78 ,
int V_79 , int V_80 , int V_11 ,
int V_81 , unsigned long V_69 ,
int V_82 , struct V_56 * V_67 )
{
unsigned long V_83 = V_81 * V_80 * ( V_11 + 7 ) / 8 ;
struct V_8 * V_9 = & V_84 ;
unsigned long V_85 = V_69 ;
struct V_86 * V_73 ;
struct V_87 * V_14 ;
struct V_6 * V_7 ;
if ( ! F_25 ( V_85 , V_83 , L_12 ) )
return;
F_26 ( V_88
L_13 ,
V_79 , V_80 , V_68 , V_69 , V_11 , V_81 ) ;
if ( V_11 != 8 && V_11 != 15 && V_11 != 16 && V_11 != 32 ) {
F_26 ( V_89 L_14 , V_78 ,
V_11 ) ;
F_12 ( V_85 , V_83 ) ;
return;
}
V_7 = F_27 ( sizeof( T_2 ) * 16 , NULL ) ;
if ( V_7 == 0 ) {
F_12 ( V_85 , V_83 ) ;
return;
}
V_73 = & V_7 -> V_73 ;
V_14 = & V_7 -> V_14 ;
V_7 -> V_9 = V_9 ;
strcpy ( V_73 -> V_90 , L_15 ) ;
strncat ( V_73 -> V_90 , V_68 , sizeof( V_73 -> V_90 ) - sizeof( L_15 ) ) ;
V_73 -> V_90 [ sizeof( V_73 -> V_90 ) - 1 ] = '\0' ;
V_14 -> V_91 = V_14 -> V_92 = V_79 ;
V_14 -> V_93 = V_14 -> V_94 = V_80 ;
V_73 -> V_95 = V_81 ;
V_73 -> V_96 = V_69 ;
V_73 -> V_97 = V_81 * V_80 ;
V_73 -> type = V_98 ;
V_73 -> V_99 = 0 ;
V_9 -> V_18 = V_75 ;
if ( V_11 == 8 )
F_19 ( V_7 , V_67 , V_68 , V_69 ) ;
else
V_73 -> V_74 = V_100 ;
V_14 -> V_101 = V_14 -> V_102 = 0 ;
switch ( V_11 ) {
case 8 :
V_14 -> V_15 = 8 ;
V_14 -> V_2 . V_59 = 0 ;
V_14 -> V_2 . V_16 = 8 ;
V_14 -> V_3 . V_59 = 0 ;
V_14 -> V_3 . V_16 = 8 ;
V_14 -> V_4 . V_59 = 0 ;
V_14 -> V_4 . V_16 = 8 ;
V_14 -> V_5 . V_59 = 0 ;
V_14 -> V_5 . V_16 = 0 ;
break;
case 15 :
V_14 -> V_15 = 16 ;
V_14 -> V_2 . V_59 = 10 ;
V_14 -> V_2 . V_16 = 5 ;
V_14 -> V_3 . V_59 = 5 ;
V_14 -> V_3 . V_16 = 5 ;
V_14 -> V_4 . V_59 = 0 ;
V_14 -> V_4 . V_16 = 5 ;
V_14 -> V_5 . V_59 = 0 ;
V_14 -> V_5 . V_16 = 0 ;
break;
case 16 :
V_14 -> V_15 = 16 ;
V_14 -> V_2 . V_59 = 11 ;
V_14 -> V_2 . V_16 = 5 ;
V_14 -> V_3 . V_59 = 5 ;
V_14 -> V_3 . V_16 = 6 ;
V_14 -> V_4 . V_59 = 0 ;
V_14 -> V_4 . V_16 = 5 ;
V_14 -> V_5 . V_59 = 0 ;
V_14 -> V_5 . V_16 = 0 ;
break;
case 32 :
V_14 -> V_15 = 32 ;
V_14 -> V_2 . V_59 = 16 ;
V_14 -> V_2 . V_16 = 8 ;
V_14 -> V_3 . V_59 = 8 ;
V_14 -> V_3 . V_16 = 8 ;
V_14 -> V_4 . V_59 = 0 ;
V_14 -> V_4 . V_16 = 8 ;
V_14 -> V_5 . V_59 = 24 ;
V_14 -> V_5 . V_16 = 8 ;
break;
}
V_14 -> V_2 . V_103 = V_14 -> V_3 . V_103 = V_14 -> V_4 . V_103 =
V_14 -> V_5 . V_103 = 0 ;
V_14 -> V_104 = 0 ;
V_14 -> V_105 = 0 ;
V_14 -> V_106 = 0 ;
V_14 -> V_80 = V_14 -> V_79 = - 1 ;
V_14 -> V_107 = 10000 ;
V_14 -> V_108 = V_14 -> V_109 = 16 ;
V_14 -> V_110 = V_14 -> V_111 = 16 ;
V_14 -> V_112 = V_14 -> V_113 = 8 ;
V_14 -> V_114 = 0 ;
V_14 -> V_115 = V_116 ;
V_7 -> V_52 = F_28 ( 1 ) ;
if ( ! V_7 -> V_52 )
goto V_117;
V_7 -> V_52 -> V_53 [ 0 ] . V_54 = V_69 ;
V_7 -> V_52 -> V_53 [ 0 ] . V_55 = V_73 -> V_97 ;
V_7 -> V_118 = & V_119 ;
V_7 -> V_51 = F_18 ( V_69 , V_73 -> V_97 ) ;
V_7 -> V_13 = ( void * ) ( V_7 + 1 ) ;
V_7 -> V_63 = V_120 | V_121 | V_82 ;
F_29 ( & V_7 -> V_34 , 256 , 0 ) ;
if ( F_30 ( V_7 ) < 0 )
goto V_122;
F_26 ( V_88 L_16 ,
V_7 -> V_123 , V_78 ) ;
return;
V_122:
F_11 ( V_7 -> V_51 ) ;
V_117:
F_11 ( V_9 -> V_17 ) ;
V_9 -> V_17 = NULL ;
F_13 ( V_7 ) ;
F_12 ( V_85 , V_83 ) ;
}
static void T_4 F_31 ( struct V_56 * V_67 , int V_124 )
{
unsigned int V_125 ;
int V_10 , V_79 = 640 , V_80 = 480 , V_11 = 8 , V_81 = 640 ;
unsigned int V_63 , V_126 , V_127 = 0 ;
unsigned long V_128 = 0 ;
T_3 V_129 , V_69 = V_66 ;
const T_2 * V_130 , * V_60 , * V_131 ;
T_3 V_61 ;
int V_82 = 0 ;
#ifdef F_32
if ( F_22 ( V_67 , L_17 , NULL ) )
V_82 = V_132 ;
#else
if ( F_22 ( V_67 , L_18 , NULL ) )
V_82 = V_132 ;
#endif
V_130 = F_22 ( V_67 , L_19 , & V_125 ) ;
if ( V_130 == NULL )
V_130 = F_22 ( V_67 , L_20 , & V_125 ) ;
if ( V_130 && V_125 == sizeof( T_2 ) )
V_11 = * V_130 ;
V_130 = F_22 ( V_67 , L_21 , & V_125 ) ;
if ( V_130 == NULL )
V_130 = F_22 ( V_67 , L_22 , & V_125 ) ;
if ( V_130 && V_125 == sizeof( T_2 ) )
V_79 = * V_130 ;
V_130 = F_22 ( V_67 , L_23 , & V_125 ) ;
if ( V_130 == NULL )
V_130 = F_22 ( V_67 , L_24 , & V_125 ) ;
if ( V_130 && V_125 == sizeof( T_2 ) )
V_80 = * V_130 ;
V_130 = F_22 ( V_67 , L_25 , & V_125 ) ;
if ( V_130 == NULL )
V_130 = F_22 ( V_67 , L_26 , & V_125 ) ;
if ( V_130 && V_125 == sizeof( T_2 ) && ( * V_130 != 0xffffffffu ) )
V_81 = * V_130 ;
else
V_81 = V_79 * ( ( V_11 + 7 ) / 8 ) ;
V_126 = ( unsigned long ) V_81 * ( unsigned long ) V_80 ;
V_131 = F_22 ( V_67 , L_27 , & V_125 ) ;
if ( V_131 == NULL )
V_131 = F_22 ( V_67 , L_28 , & V_125 ) ;
if ( V_131 && V_125 == sizeof( T_2 ) )
V_127 = * V_131 ;
if ( V_124 )
goto V_133;
for ( V_10 = 0 ; ( V_60 = F_16 ( V_67 , V_10 , & V_61 , & V_63 ) )
!= NULL ; V_10 ++ ) {
int V_134 = 0 ;
if ( ! ( V_63 & V_65 ) )
continue;
if ( V_61 < V_126 )
continue;
V_129 = F_17 ( V_67 , V_60 ) ;
if ( V_129 == V_66 )
continue;
if ( V_127 && ( V_129 <= V_127 ) &&
( ( V_129 + V_61 ) >= ( V_127 + V_126 ) ) )
V_134 = 1 ;
if ( V_134 ) {
V_69 = V_127 ;
break;
}
if ( V_126 > V_128 ) {
V_128 = V_126 ;
V_69 = V_66 ;
}
if ( V_69 == V_66 )
V_69 = V_129 ;
}
V_133:
if ( V_69 == V_66 && V_127 )
V_69 = ( T_3 ) V_127 ;
if ( V_69 != V_66 ) {
if ( strcmp ( V_67 -> V_68 , L_29 ) == 0 )
V_69 += 0x1000 ;
F_24 ( V_124 ? L_30 : V_67 -> V_68 ,
V_124 ? L_31 : V_67 -> V_78 ,
V_79 , V_80 , V_11 , V_81 , V_69 ,
V_82 , V_124 ? NULL : V_67 ) ;
}
}
static int T_4 F_33 ( void )
{
struct V_56 * V_67 = NULL , * V_135 = NULL ;
if ( F_34 ( L_12 , NULL ) )
return - V_136 ;
if ( F_22 ( V_137 , L_32 , NULL ) != NULL ) {
F_31 ( V_137 , 1 ) ;
}
for ( V_67 = NULL ; ( V_67 = F_35 ( V_67 , L_31 ) ) ; ) {
if ( F_22 ( V_67 , L_33 , NULL ) &&
F_22 ( V_67 , L_34 , NULL ) ) {
V_135 = V_67 ;
F_31 ( V_67 , 0 ) ;
}
}
for ( V_67 = NULL ; ( V_67 = F_35 ( V_67 , L_31 ) ) ; ) {
if ( F_22 ( V_67 , L_33 , NULL ) &&
V_67 != V_135 )
F_31 ( V_67 , 0 ) ;
}
return 0 ;
}
