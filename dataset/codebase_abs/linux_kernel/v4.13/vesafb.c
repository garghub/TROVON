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
struct V_30 * V_31 = V_4 -> V_31 ;
F_7 ( & V_4 -> V_25 ) ;
F_8 ( V_31 -> V_32 ) ;
if ( V_4 -> V_33 )
F_9 ( V_4 -> V_33 ) ;
F_10 ( V_4 -> V_34 -> V_35 [ 0 ] . V_36 , V_4 -> V_34 -> V_35 [ 0 ] . V_37 ) ;
}
static int F_11 ( char * V_38 )
{
char * V_39 ;
if ( ! V_38 || ! * V_38 )
return 0 ;
while ( ( V_39 = F_12 ( & V_38 , L_1 ) ) != NULL ) {
if ( ! * V_39 ) continue;
if ( ! strcmp ( V_39 , L_2 ) )
V_40 = 1 ;
else if ( ! strcmp ( V_39 , L_3 ) )
V_41 = 0 ;
else if ( ! strcmp ( V_39 , L_4 ) )
V_41 = 1 ;
else if ( ! strcmp ( V_39 , L_5 ) )
V_41 = 2 ;
else if ( ! strcmp ( V_39 , L_6 ) )
V_21 = 0 ;
else if ( ! strcmp ( V_39 , L_7 ) )
V_21 = 1 ;
else if ( ! strncmp ( V_39 , L_8 , 5 ) )
V_42 = F_13 ( V_39 + 5 , NULL , 0 ) ;
else if ( ! strcmp ( V_39 , L_9 ) )
V_42 = 0 ;
else if ( ! strncmp ( V_39 , L_10 , 7 ) )
V_43 = F_13 ( V_39 + 7 , NULL , 0 ) ;
else if ( ! strncmp ( V_39 , L_11 , 7 ) )
V_44 = F_13 ( V_39 + 7 , NULL , 0 ) ;
}
return 0 ;
}
static int F_14 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
struct V_30 * V_31 ;
int V_47 , V_16 ;
unsigned int V_48 ;
unsigned int V_49 ;
unsigned int V_50 ;
char * V_51 = NULL ;
F_15 ( L_12 , & V_51 ) ;
F_11 ( V_51 ) ;
if ( V_52 . V_53 != V_54 )
return - V_55 ;
V_18 = ( V_52 . V_56 & 2 ) ? 0 : 1 ;
V_57 . V_58 = V_52 . V_59 ;
V_60 . V_27 = V_52 . V_61 ;
if ( 15 == V_60 . V_27 )
V_60 . V_27 = 16 ;
V_60 . V_62 = V_52 . V_63 ;
V_60 . V_64 = V_52 . V_65 ;
V_57 . V_8 = V_52 . V_66 ;
V_57 . V_67 = ( V_60 . V_27 == 8 ) ?
V_68 : V_69 ;
V_48 = V_60 . V_64 * V_57 . V_8 ;
V_50 = V_52 . V_70 * 65536 ;
if ( V_43 )
V_50 = V_43 * 1024 * 1024 ;
if ( V_50 < V_48 )
V_50 = V_48 ;
V_49 = V_48 * 2 ;
if ( V_44 )
V_49 = V_44 * 1024 * 1024 ;
if ( V_49 < V_48 )
V_49 = V_48 ;
if ( V_49 > V_50 )
V_49 = V_50 ;
V_57 . V_71 = V_49 ;
#ifndef F_2
V_52 . V_72 = 0 ;
#endif
if ( ! F_16 ( V_57 . V_58 , V_50 , L_12 ) ) {
F_17 ( V_73
L_13 ,
V_57 . V_58 ) ;
}
V_4 = F_18 ( sizeof( struct V_30 ) , & V_46 -> V_46 ) ;
if ( ! V_4 ) {
F_10 ( V_57 . V_58 , V_50 ) ;
return - V_74 ;
}
F_19 ( V_46 , V_4 ) ;
V_31 = V_4 -> V_31 ;
V_4 -> V_29 = V_31 -> V_29 ;
V_4 -> V_34 = F_20 ( 1 ) ;
if ( ! V_4 -> V_34 ) {
V_16 = - V_74 ;
goto V_16;
}
V_4 -> V_34 -> V_35 [ 0 ] . V_36 = V_52 . V_59 ;
V_4 -> V_34 -> V_35 [ 0 ] . V_37 = V_50 ;
F_17 ( V_75 L_14 ,
V_60 . V_62 , V_60 . V_64 , V_60 . V_27 , V_57 . V_8 , V_52 . V_76 ) ;
if ( V_52 . V_72 ) {
F_17 ( V_75 L_15 ,
V_52 . V_72 , V_52 . V_77 ) ;
}
if ( V_52 . V_72 < 0xc000 )
V_41 = V_21 = 0 ;
if ( V_41 || V_21 ) {
unsigned short * V_78 ;
V_78 = ( unsigned short * ) F_21 ( ( ( unsigned long ) V_52 . V_72 << 4 ) + V_52 . V_77 ) ;
V_79 = ( void * ) ( ( char * ) V_78 + V_78 [ 1 ] ) ;
V_80 = ( void * ) ( ( char * ) V_78 + V_78 [ 2 ] ) ;
F_17 ( V_75 L_16 , V_79 , V_80 ) ;
if ( V_78 [ 3 ] ) {
F_17 ( V_75 L_17 ) ;
for ( V_47 = V_78 [ 3 ] / 2 ; V_78 [ V_47 ] != 0xffff ; V_47 ++ )
F_17 ( L_18 , V_78 [ V_47 ] ) ;
F_17 ( L_19 ) ;
if ( V_78 [ V_47 ] != 0xffff ) {
F_17 ( V_75 L_20 ) ;
V_41 = V_21 = 0 ;
}
}
}
if ( V_60 . V_27 == 8 && ! V_21 && ! V_18 ) {
F_17 ( V_73 L_21
L_22 ) ;
V_57 . V_67 = V_81 ;
}
V_60 . V_82 = V_60 . V_62 ;
V_60 . V_83 = V_57 . V_71 / V_57 . V_8 ;
if ( V_41 && V_60 . V_83 > V_60 . V_64 ) {
F_17 ( V_75 L_23 ,
( V_41 > 1 ) ? L_5 : L_4 , V_60 . V_83 ) ;
} else {
F_17 ( V_75 L_24 ) ;
V_60 . V_83 = V_60 . V_64 ;
V_41 = 0 ;
}
V_60 . V_84 = 10000000 / V_60 . V_62 * 1000 / V_60 . V_64 ;
V_60 . V_85 = ( V_60 . V_62 / 8 ) & 0xf8 ;
V_60 . V_86 = ( V_60 . V_62 / 8 ) & 0xf8 ;
V_60 . V_11 . V_5 = V_52 . V_87 ;
V_60 . V_11 . V_88 = V_52 . V_89 ;
V_60 . V_12 . V_5 = V_52 . V_90 ;
V_60 . V_12 . V_88 = V_52 . V_91 ;
V_60 . V_13 . V_5 = V_52 . V_92 ;
V_60 . V_13 . V_88 = V_52 . V_93 ;
V_60 . V_24 . V_5 = V_52 . V_94 ;
V_60 . V_24 . V_88 = V_52 . V_95 ;
if ( V_60 . V_27 <= 8 ) {
V_15 = V_60 . V_12 . V_88 ;
V_60 . V_11 . V_88 =
V_60 . V_12 . V_88 =
V_60 . V_13 . V_88 =
V_60 . V_27 ;
}
F_17 ( V_75 L_25
L_26 ,
( V_60 . V_27 > 8 ) ?
L_27 : ( V_18 || V_21 ) ?
L_28 : L_29 ,
V_52 . V_95 ,
V_52 . V_89 ,
V_52 . V_91 ,
V_52 . V_93 ,
V_52 . V_94 ,
V_52 . V_87 ,
V_52 . V_90 ,
V_52 . V_92 ) ;
V_57 . V_96 = V_41 ? 1 : 0 ;
V_57 . V_97 = ( V_41 > 1 ) ? 1 : 0 ;
F_22 ( 0x3c0 , 32 , L_12 ) ;
if ( V_42 == 3 ) {
unsigned int V_98 = V_50 ;
V_98 = F_23 ( V_98 ) ;
do {
V_31 -> V_32 =
F_24 ( V_57 . V_58 ,
V_98 ) ;
V_98 >>= 1 ;
} while ( V_98 >= V_99 && V_31 -> V_32 < 0 );
V_4 -> V_33 = F_25 ( V_57 . V_58 , V_57 . V_71 ) ;
} else {
if ( V_42 && V_42 != 3 )
F_26 ( 1 , L_30 ) ;
V_4 -> V_33 = F_27 ( V_57 . V_58 , V_57 . V_71 ) ;
}
if ( ! V_4 -> V_33 ) {
F_17 ( V_100
L_31 ,
V_57 . V_71 , V_57 . V_58 ) ;
V_16 = - V_101 ;
goto V_16;
}
F_17 ( V_75 L_32
L_33 ,
V_57 . V_58 , V_4 -> V_33 ,
V_49 / 1024 , V_50 / 1024 ) ;
V_4 -> V_102 = & V_103 ;
V_4 -> V_2 = V_60 ;
V_4 -> V_7 = V_57 ;
V_4 -> V_104 = V_105 | V_106 |
( V_41 ? V_107 : 0 ) ;
if ( ! V_41 )
V_4 -> V_102 -> V_108 = NULL ;
if ( F_28 ( & V_4 -> V_25 , 256 , 0 ) < 0 ) {
V_16 = - V_74 ;
goto V_16;
}
if ( F_29 ( V_4 ) < 0 ) {
V_16 = - V_17 ;
F_7 ( & V_4 -> V_25 ) ;
goto V_16;
}
V_3 ( V_4 , L_34 , V_4 -> V_7 . V_109 ) ;
return 0 ;
V_16:
F_8 ( V_31 -> V_32 ) ;
if ( V_4 -> V_33 )
F_9 ( V_4 -> V_33 ) ;
F_30 ( V_4 ) ;
F_10 ( V_57 . V_58 , V_50 ) ;
return V_16 ;
}
static int F_31 ( struct V_45 * V_110 )
{
struct V_3 * V_4 = F_32 ( V_110 ) ;
F_33 ( V_4 ) ;
F_30 ( V_4 ) ;
return 0 ;
}
