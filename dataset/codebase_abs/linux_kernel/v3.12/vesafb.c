static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
#ifdef F_2
int V_5 ;
V_5 = ( V_2 -> V_6 * V_4 -> V_7 . V_8 + V_2 -> V_9 ) / 4 ;
__asm__ __volatile__(
"call *(%%edi)"
:
: "a" (0x4f07),
"b" (0),
"c" (offset),
"d" (offset >> 16),
"D" (&pmi_start));
#endif
return 0 ;
}
static int F_3 ( int V_10 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 )
{
int V_14 = 16 - V_15 ;
int V_16 = - V_17 ;
if ( V_18 ) {
F_4 ( V_10 , V_19 ) ;
F_4 ( V_11 >> V_14 , V_20 ) ;
F_4 ( V_12 >> V_14 , V_20 ) ;
F_4 ( V_13 >> V_14 , V_20 ) ;
V_16 = 0 ;
}
#ifdef F_2
if ( V_16 && V_21 ) {
struct { T_1 V_13 , V_12 , V_11 , V_22 ; } V_23 ;
V_23 . V_11 = V_11 >> V_14 ;
V_23 . V_12 = V_12 >> V_14 ;
V_23 . V_13 = V_13 >> V_14 ;
V_23 . V_22 = 0 ;
__asm__ __volatile__(
"call *(%%esi)"
:
: "a" (0x4f09),
"b" (0),
"c" (1),
"d" (regno),
"D" (&entry),
"S" (&pmi_pal));
V_16 = 0 ;
}
#endif
return V_16 ;
}
static int F_5 ( unsigned V_10 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 , unsigned V_24 ,
struct V_3 * V_4 )
{
int V_16 = 0 ;
if ( V_10 >= V_4 -> V_25 . V_26 )
return 1 ;
if ( V_4 -> V_2 . V_27 == 8 )
V_16 = F_3 ( V_10 , V_11 , V_12 , V_13 ) ;
else if ( V_10 < 16 ) {
switch ( V_4 -> V_2 . V_27 ) {
case 16 :
if ( V_4 -> V_2 . V_11 . V_5 == 10 ) {
( ( V_28 * ) ( V_4 -> V_29 ) ) [ V_10 ] =
( ( V_11 & 0xf800 ) >> 1 ) |
( ( V_12 & 0xf800 ) >> 6 ) |
( ( V_13 & 0xf800 ) >> 11 ) ;
} else {
( ( V_28 * ) ( V_4 -> V_29 ) ) [ V_10 ] =
( ( V_11 & 0xf800 ) ) |
( ( V_12 & 0xfc00 ) >> 5 ) |
( ( V_13 & 0xf800 ) >> 11 ) ;
}
break;
case 24 :
case 32 :
V_11 >>= 8 ;
V_12 >>= 8 ;
V_13 >>= 8 ;
( ( V_28 * ) ( V_4 -> V_29 ) ) [ V_10 ] =
( V_11 << V_4 -> V_2 . V_11 . V_5 ) |
( V_12 << V_4 -> V_2 . V_12 . V_5 ) |
( V_13 << V_4 -> V_2 . V_13 . V_5 ) ;
break;
}
}
return V_16 ;
}
static void F_6 ( struct V_3 * V_4 )
{
F_7 ( & V_4 -> V_25 ) ;
if ( V_4 -> V_30 )
F_8 ( V_4 -> V_30 ) ;
F_9 ( V_4 -> V_31 -> V_32 [ 0 ] . V_33 , V_4 -> V_31 -> V_32 [ 0 ] . V_34 ) ;
F_10 ( V_4 ) ;
}
static int F_11 ( char * V_35 )
{
char * V_36 ;
if ( ! V_35 || ! * V_35 )
return 0 ;
while ( ( V_36 = F_12 ( & V_35 , L_1 ) ) != NULL ) {
if ( ! * V_36 ) continue;
if ( ! strcmp ( V_36 , L_2 ) )
V_37 = 1 ;
else if ( ! strcmp ( V_36 , L_3 ) )
V_38 = 0 ;
else if ( ! strcmp ( V_36 , L_4 ) )
V_38 = 1 ;
else if ( ! strcmp ( V_36 , L_5 ) )
V_38 = 2 ;
else if ( ! strcmp ( V_36 , L_6 ) )
V_21 = 0 ;
else if ( ! strcmp ( V_36 , L_7 ) )
V_21 = 1 ;
else if ( ! strncmp ( V_36 , L_8 , 5 ) )
V_39 = F_13 ( V_36 + 5 , NULL , 0 ) ;
else if ( ! strcmp ( V_36 , L_9 ) )
V_39 = 0 ;
else if ( ! strncmp ( V_36 , L_10 , 7 ) )
V_40 = F_13 ( V_36 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_36 , L_11 , 7 ) )
V_41 = F_13 ( V_36 + 7 , NULL , 0 ) ;
}
return 0 ;
}
static int F_14 ( struct V_42 * V_43 )
{
struct V_3 * V_4 ;
int V_44 , V_16 ;
unsigned int V_45 ;
unsigned int V_46 ;
unsigned int V_47 ;
char * V_48 = NULL ;
F_15 ( L_12 , & V_48 ) ;
F_11 ( V_48 ) ;
if ( V_49 . V_50 != V_51 )
return - V_52 ;
V_18 = ( V_49 . V_53 & 2 ) ? 0 : 1 ;
V_54 . V_55 = V_49 . V_56 ;
V_57 . V_27 = V_49 . V_58 ;
if ( 15 == V_57 . V_27 )
V_57 . V_27 = 16 ;
V_57 . V_59 = V_49 . V_60 ;
V_57 . V_61 = V_49 . V_62 ;
V_54 . V_8 = V_49 . V_63 ;
V_54 . V_64 = ( V_57 . V_27 == 8 ) ?
V_65 : V_66 ;
V_45 = V_57 . V_61 * V_54 . V_8 ;
V_47 = V_49 . V_67 * 65536 ;
if ( V_40 )
V_47 = V_40 * 1024 * 1024 ;
if ( V_47 < V_45 )
V_47 = V_45 ;
V_46 = V_45 * 2 ;
if ( V_41 )
V_46 = V_41 * 1024 * 1024 ;
if ( V_46 < V_45 )
V_46 = V_45 ;
if ( V_46 > V_47 )
V_46 = V_47 ;
V_54 . V_68 = V_46 ;
#ifndef F_2
V_49 . V_69 = 0 ;
#endif
if ( ! F_16 ( V_54 . V_55 , V_47 , L_12 ) ) {
F_17 ( V_70
L_13 ,
V_54 . V_55 ) ;
}
V_4 = F_18 ( sizeof( V_28 ) * 256 , & V_43 -> V_43 ) ;
if ( ! V_4 ) {
F_9 ( V_54 . V_55 , V_47 ) ;
return - V_71 ;
}
V_4 -> V_29 = V_4 -> V_72 ;
V_4 -> V_72 = NULL ;
V_4 -> V_31 = F_19 ( 1 ) ;
if ( ! V_4 -> V_31 ) {
V_16 = - V_71 ;
goto V_16;
}
V_4 -> V_31 -> V_32 [ 0 ] . V_33 = V_49 . V_56 ;
V_4 -> V_31 -> V_32 [ 0 ] . V_34 = V_47 ;
F_17 ( V_73 L_14 ,
V_57 . V_59 , V_57 . V_61 , V_57 . V_27 , V_54 . V_8 , V_49 . V_74 ) ;
if ( V_49 . V_69 ) {
F_17 ( V_73 L_15 ,
V_49 . V_69 , V_49 . V_75 ) ;
}
if ( V_49 . V_69 < 0xc000 )
V_38 = V_21 = 0 ;
if ( V_38 || V_21 ) {
unsigned short * V_76 ;
V_76 = ( unsigned short * ) F_20 ( ( ( unsigned long ) V_49 . V_69 << 4 ) + V_49 . V_75 ) ;
V_77 = ( void * ) ( ( char * ) V_76 + V_76 [ 1 ] ) ;
V_78 = ( void * ) ( ( char * ) V_76 + V_76 [ 2 ] ) ;
F_17 ( V_73 L_16 , V_77 , V_78 ) ;
if ( V_76 [ 3 ] ) {
F_17 ( V_73 L_17 ) ;
for ( V_44 = V_76 [ 3 ] / 2 ; V_76 [ V_44 ] != 0xffff ; V_44 ++ )
F_17 ( L_18 , V_76 [ V_44 ] ) ;
F_17 ( L_19 ) ;
if ( V_76 [ V_44 ] != 0xffff ) {
F_17 ( V_73 L_20 ) ;
V_38 = V_21 = 0 ;
}
}
}
if ( V_57 . V_27 == 8 && ! V_21 && ! V_18 ) {
F_17 ( V_70 L_21
L_22 ) ;
V_54 . V_64 = V_79 ;
}
V_57 . V_80 = V_57 . V_59 ;
V_57 . V_81 = V_54 . V_68 / V_54 . V_8 ;
if ( V_38 && V_57 . V_81 > V_57 . V_61 ) {
F_17 ( V_73 L_23 ,
( V_38 > 1 ) ? L_5 : L_4 , V_57 . V_81 ) ;
} else {
F_17 ( V_73 L_24 ) ;
V_57 . V_81 = V_57 . V_61 ;
V_38 = 0 ;
}
V_57 . V_82 = 10000000 / V_57 . V_59 * 1000 / V_57 . V_61 ;
V_57 . V_83 = ( V_57 . V_59 / 8 ) & 0xf8 ;
V_57 . V_84 = ( V_57 . V_59 / 8 ) & 0xf8 ;
V_57 . V_11 . V_5 = V_49 . V_85 ;
V_57 . V_11 . V_86 = V_49 . V_87 ;
V_57 . V_12 . V_5 = V_49 . V_88 ;
V_57 . V_12 . V_86 = V_49 . V_89 ;
V_57 . V_13 . V_5 = V_49 . V_90 ;
V_57 . V_13 . V_86 = V_49 . V_91 ;
V_57 . V_24 . V_5 = V_49 . V_92 ;
V_57 . V_24 . V_86 = V_49 . V_93 ;
if ( V_57 . V_27 <= 8 ) {
V_15 = V_57 . V_12 . V_86 ;
V_57 . V_11 . V_86 =
V_57 . V_12 . V_86 =
V_57 . V_13 . V_86 =
V_57 . V_27 ;
}
F_17 ( V_73 L_25
L_26 ,
( V_57 . V_27 > 8 ) ?
L_27 : ( V_18 || V_21 ) ?
L_28 : L_29 ,
V_49 . V_93 ,
V_49 . V_87 ,
V_49 . V_89 ,
V_49 . V_91 ,
V_49 . V_92 ,
V_49 . V_85 ,
V_49 . V_88 ,
V_49 . V_90 ) ;
V_54 . V_94 = V_38 ? 1 : 0 ;
V_54 . V_95 = ( V_38 > 1 ) ? 1 : 0 ;
F_21 ( 0x3c0 , 32 , L_12 ) ;
#ifdef F_22
if ( V_39 ) {
unsigned int V_96 = V_47 ;
unsigned int type = 0 ;
switch ( V_39 ) {
case 1 :
type = V_97 ;
break;
case 2 :
type = V_98 ;
break;
case 3 :
type = V_99 ;
break;
case 4 :
type = V_100 ;
break;
default:
type = 0 ;
break;
}
if ( type ) {
int V_101 ;
V_96 = F_23 ( V_96 ) ;
do {
V_101 = F_24 ( V_54 . V_55 , V_96 ,
type , 1 ) ;
V_96 >>= 1 ;
} while ( V_96 >= V_102 && V_101 == - V_17 );
}
}
#endif
switch ( V_39 ) {
case 1 :
V_4 -> V_30 = F_25 ( V_54 . V_55 , V_54 . V_68 ) ;
break;
case 2 :
V_4 -> V_30 = F_26 ( V_54 . V_55 , V_54 . V_68 ) ;
break;
case 3 :
V_4 -> V_30 = F_27 ( V_54 . V_55 , V_54 . V_68 ) ;
break;
case 4 :
default:
V_4 -> V_30 = F_28 ( V_54 . V_55 , V_54 . V_68 ) ;
break;
}
if ( ! V_4 -> V_30 ) {
F_17 ( V_103
L_30 ,
V_54 . V_68 , V_54 . V_55 ) ;
V_16 = - V_104 ;
goto V_16;
}
F_17 ( V_73 L_31
L_32 ,
V_54 . V_55 , V_4 -> V_30 ,
V_46 / 1024 , V_47 / 1024 ) ;
V_4 -> V_105 = & V_106 ;
V_4 -> V_2 = V_57 ;
V_4 -> V_7 = V_54 ;
V_4 -> V_107 = V_108 | V_109 |
( V_38 ? V_110 : 0 ) ;
if ( ! V_38 )
V_4 -> V_105 -> V_111 = NULL ;
if ( F_29 ( & V_4 -> V_25 , 256 , 0 ) < 0 ) {
V_16 = - V_71 ;
goto V_16;
}
if ( F_30 ( V_4 ) < 0 ) {
V_16 = - V_17 ;
F_7 ( & V_4 -> V_25 ) ;
goto V_16;
}
F_17 ( V_73 L_33 ,
V_4 -> V_112 , V_4 -> V_7 . V_113 ) ;
return 0 ;
V_16:
if ( V_4 -> V_30 )
F_8 ( V_4 -> V_30 ) ;
F_10 ( V_4 ) ;
F_9 ( V_54 . V_55 , V_47 ) ;
return V_16 ;
}
