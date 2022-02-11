static void T_1 F_1 ( int V_1 , char * V_2 , int * V_3 )
{
static int V_4 ;
switch ( V_1 ) {
case V_5 :
if ( V_3 [ 0 ] != 2 && V_3 [ 0 ] != 3 ) {
F_2 ( V_6 L_1 F_3 ( V_7 ) L_2 ) ;
return;
}
break;
case V_8 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( V_6 L_3 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
case V_9 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( V_6 L_5 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
case V_10 :
if ( V_3 [ 0 ] != 2 ) {
F_2 ( L_6 F_3 ( V_7 ) L_4 ) ;
return;
}
break;
}
if ( V_4 < V_11 ) {
V_12 [ V_4 ] . V_7 = ( V_13 ) V_3 [ 1 ] ;
V_12 [ V_4 ] . V_14 = V_3 [ 2 ] ;
if ( V_3 [ 0 ] == 3 )
V_12 [ V_4 ] . V_15 = V_3 [ 3 ] ;
else
V_12 [ V_4 ] . V_15 = V_16 ;
V_12 [ V_4 ] . V_1 = V_1 ;
++ V_4 ;
}
}
static int T_1 F_4 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_7 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_8 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_8 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_9 , V_2 , V_3 ) ;
return 1 ;
}
static int T_1 F_9 ( char * V_2 )
{
int V_3 [ 10 ] ;
F_5 ( V_2 , F_6 ( V_3 ) , V_3 ) ;
F_1 ( V_10 , V_2 , V_3 ) ;
return 1 ;
}
static void F_10 ( int V_17 , T_2 V_14 , T_2 V_18 [] )
{
T_2 V_19 = 0 ;
F_11 ( V_18 [ 0 ] , 0x779 ) ;
F_11 ( V_18 [ 1 ] , 0x379 ) ;
F_11 ( V_18 [ 2 ] , 0x379 ) ;
F_11 ( V_18 [ 3 ] , 0x379 ) ;
F_11 ( V_18 [ 4 ] , 0x379 ) ;
if ( V_14 != 2 && V_14 != 3 && V_14 != 4 && V_14 != 5 && V_14 != 7 )
V_14 = 0 ;
if ( V_17 >= 0 && V_17 <= 7 )
V_19 = 0x80 | V_17 | ( V_14 << 4 ) ;
F_11 ( V_19 , 0x379 ) ;
}
static int T_1 F_12 ( struct V_20 * V_21 )
{
static int V_22 ;
int V_23 ;
unsigned int * V_24 ;
T_2 * V_18 = NULL ;
#ifndef F_13
int V_25 ;
int V_26 = - 1 ;
unsigned long V_27 ;
#endif
static unsigned int T_3 V_28 [] = {
0x280 , 0x290 , 0x300 , 0x310 , 0x330 , 0x340 , 0x348 , 0x350 , 0
} ;
static unsigned int T_3 V_29 [] = {
0x220 , 0x240 , 0x280 , 0x2a0 , 0x2c0 , 0x300 , 0x320 , 0x340 , 0
} ;
static T_2 V_30 [] T_3 = {
0x59 , 0xb9 , 0xc5 , 0xae , 0xa6
} ;
static T_2 V_31 [] T_3 = {
0x0f , 0x22 , 0xf0 , 0x20 , 0x80
} ;
int V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
#ifdef F_13
unsigned long V_37 ;
void T_4 * V_38 ;
T_5 V_39 ;
#endif
if ( V_40 )
V_12 [ 0 ] . V_14 = V_40 ;
if ( V_41 )
V_12 [ 0 ] . V_15 = V_41 ;
if ( V_42 )
V_12 [ 0 ] . V_7 = ( V_13 ) V_42 ;
if ( V_43 )
V_12 [ 0 ] . V_1 = V_5 ;
else if ( V_44 )
V_12 [ 0 ] . V_1 = V_8 ;
else if ( V_45 )
V_12 [ 0 ] . V_1 = V_9 ;
else if ( V_46 )
V_12 [ 0 ] . V_1 = V_10 ;
else if ( V_47 )
V_12 [ 0 ] . V_1 = V_48 ;
#ifndef F_13
if ( ! V_22 && F_14 () ) {
struct V_49 * V_50 = NULL ;
V_23 = 0 ;
while ( ( V_50 = F_15 ( NULL , F_16 ( 'D' , 'T' , 'C' ) , F_17 ( 0x436e ) , V_50 ) ) ) {
if ( V_23 >= V_11 )
break;
if ( F_18 ( V_50 ) < 0 )
continue;
if ( F_19 ( V_50 ) < 0 ) {
F_2 ( V_6 L_7 ) ;
F_20 ( V_50 ) ;
continue;
}
if ( ! F_21 ( V_50 , 0 ) ) {
F_2 ( V_6 L_8 ) ;
F_20 ( V_50 ) ;
continue;
}
if ( F_22 ( V_50 , 0 ) )
V_12 [ V_23 ] . V_14 = F_23 ( V_50 , 0 ) ;
else
V_12 [ V_23 ] . V_14 = V_51 ;
if ( F_24 ( V_50 , 0 ) )
V_12 [ V_23 ] . V_15 = F_25 ( V_50 , 0 ) ;
else
V_12 [ V_23 ] . V_15 = V_16 ;
V_12 [ V_23 ] . V_7 = ( V_13 ) F_26 ( V_50 , 0 ) ;
V_12 [ V_23 ] . V_1 = V_10 ;
V_23 ++ ;
}
}
#endif
for ( V_23 = 0 ; V_22 < V_11 ; ++ V_22 ) {
if ( ! ( V_12 [ V_22 ] . V_7 ) )
continue;
V_24 = NULL ;
V_32 = 0 ;
switch ( V_12 [ V_22 ] . V_1 ) {
case V_5 :
V_32 = V_52 | V_53 ;
break;
case V_9 :
V_24 = V_28 ;
V_18 = V_30 ;
break;
case V_48 :
V_24 = V_28 ;
V_18 = V_31 ;
break;
case V_10 :
V_24 = V_29 ;
V_18 = V_30 ;
break;
}
#ifndef F_13
if ( V_24 && V_18 ) {
F_10 ( - 1 , 0 , V_18 ) ;
V_27 = 16 ;
if ( V_12 [ V_22 ] . V_7 != V_54 )
for ( V_25 = 0 ; V_24 [ V_25 ] ; V_25 ++ ) {
if ( ! F_27 ( V_24 [ V_25 ] , V_27 , L_9 ) )
continue;
if ( V_12 [ V_22 ] . V_7 == V_24 [ V_25 ] )
break;
F_28 ( V_24 [ V_25 ] , V_27 ) ;
} else
for ( V_25 = 0 ; V_24 [ V_25 ] ; V_25 ++ ) {
if ( ! F_27 ( V_24 [ V_25 ] , V_27 , L_9 ) )
continue;
if ( F_29 ( V_24 [ V_25 ] ) == 0xff )
break;
F_28 ( V_24 [ V_25 ] , V_27 ) ;
}
if ( V_24 [ V_25 ] ) {
F_10 ( V_25 , 0 , V_18 ) ;
F_11 ( 0xc0 , V_24 [ V_25 ] + 9 ) ;
if ( F_29 ( V_24 [ V_25 ] + 9 ) != 0x80 )
continue;
V_12 [ V_22 ] . V_7 = V_24 [ V_25 ] ;
V_26 = V_25 ;
} else
continue;
}
else
{
V_27 = 8 ;
if ( ! F_27 ( V_12 [ V_22 ] . V_7 ,
V_27 , L_10 ) )
continue;
}
#else
V_37 = V_12 [ V_22 ] . V_7 ;
V_39 = V_55 ;
if ( ! F_30 ( V_37 , V_39 , L_10 ) )
continue;
V_38 = F_31 ( V_37 , V_39 ) ;
if ( ! V_38 ) {
F_32 ( V_37 , V_39 ) ;
continue;
}
#endif
V_34 = F_33 ( V_21 , sizeof( struct V_35 ) ) ;
if ( V_34 == NULL )
goto V_56;
V_36 = F_34 ( V_34 ) ;
#ifndef F_13
V_34 -> V_57 = V_12 [ V_22 ] . V_7 ;
V_34 -> V_58 = V_27 ;
V_36 -> V_59 = 1 ;
switch ( V_12 [ V_22 ] . V_1 ) {
case V_8 :
V_34 -> V_57 += 8 ;
V_36 -> V_60 = 0 ;
V_36 -> V_61 = 1 ;
V_36 -> V_62 = 4 ;
break;
case V_10 :
V_36 -> V_59 = 2 ;
case V_9 :
case V_48 :
V_36 -> V_60 = 9 ;
V_36 -> V_61 = 10 ;
V_36 -> V_62 = 8 ;
break;
}
#else
V_34 -> V_37 = V_12 [ V_22 ] . V_7 ;
V_36 -> V_38 = V_38 ;
V_36 -> V_39 = V_39 ;
switch ( V_12 [ V_22 ] . V_1 ) {
case V_8 :
V_36 -> V_60 = 0x100 ;
V_36 -> V_61 = 0x101 ;
V_36 -> V_62 = 0x104 ;
break;
case V_10 :
case V_9 :
case V_48 :
F_35 ( V_63 L_11 ) ;
goto V_64;
}
#endif
if ( F_36 ( V_34 , V_32 | V_65 ) )
goto V_64;
switch ( V_12 [ V_22 ] . V_1 ) {
case V_8 :
case V_10 :
case V_9 :
case V_48 :
F_37 ( V_36 -> V_60 , V_66 ) ;
}
F_38 ( V_34 ) ;
if ( V_12 [ V_22 ] . V_14 != V_67 )
V_34 -> V_14 = V_12 [ V_22 ] . V_14 ;
else
V_34 -> V_14 = F_39 ( V_34 , 0xffff ) ;
if ( V_34 -> V_14 == 255 )
V_34 -> V_14 = V_51 ;
if ( V_34 -> V_14 != V_51 ) {
#ifndef F_13
if ( V_12 [ V_22 ] . V_1 == V_48 )
F_10 ( V_26 , V_34 -> V_14 , V_18 ) ;
#endif
if ( F_40 ( V_34 -> V_14 , V_68 ,
0 , L_12 , V_34 ) ) {
F_2 ( V_69 L_13 , V_34 -> V_70 , V_34 -> V_14 ) ;
V_34 -> V_14 = V_51 ;
}
}
if ( V_34 -> V_14 == V_51 ) {
F_2 ( V_71 L_14 , V_34 -> V_70 ) ;
F_2 ( V_71 L_15 , V_34 -> V_70 ) ;
}
++ V_22 ;
++ V_23 ;
}
return V_23 ;
V_64:
F_41 ( V_34 ) ;
V_56:
#ifndef F_13
F_28 ( V_12 [ V_22 ] . V_7 , V_27 ) ;
#else
F_42 ( V_38 ) ;
F_32 ( V_37 , V_39 ) ;
#endif
return V_23 ;
}
static int F_43 ( struct V_33 * V_34 )
{
if ( V_34 -> V_14 != V_51 )
F_44 ( V_34 -> V_14 , V_34 ) ;
F_45 ( V_34 ) ;
#ifndef F_13
F_28 ( V_34 -> V_57 , V_34 -> V_58 ) ;
#else
{
struct V_35 * V_36 = F_34 ( V_34 ) ;
F_42 ( V_36 -> V_38 ) ;
F_32 ( V_34 -> V_37 , V_36 -> V_39 ) ;
}
#endif
return 0 ;
}
static inline int F_46 ( struct V_33 * V_34 ,
unsigned char * V_72 , int V_73 )
{
struct V_35 * V_36 = F_34 ( V_34 ) ;
int V_74 = V_73 / 128 ;
int V_75 = 0 ;
F_37 ( V_36 -> V_60 , V_66 | V_76 ) ;
F_37 ( V_36 -> V_61 , V_74 ) ;
while ( 1 ) {
if ( F_47 ( V_36 -> V_61 ) == 0 )
break;
if ( F_47 ( V_36 -> V_60 ) & V_77 ) {
F_2 ( V_6 L_16 , V_75 , V_74 ) ;
return - 1 ;
}
while ( F_47 ( V_36 -> V_60 ) & V_78 )
;
#ifndef F_13
if ( V_36 -> V_59 == 2 )
F_48 ( V_34 -> V_57 + V_36 -> V_62 ,
V_72 + V_75 , 64 ) ;
else
F_49 ( V_34 -> V_57 + V_36 -> V_62 ,
V_72 + V_75 , 128 ) ;
#else
F_50 ( V_72 + V_75 ,
V_36 -> V_38 + V_79 , 128 ) ;
#endif
V_75 += 128 ;
V_74 -- ;
}
if ( V_74 ) {
while ( F_47 ( V_36 -> V_60 ) & V_78 )
;
#ifndef F_13
if ( V_36 -> V_59 == 2 )
F_48 ( V_34 -> V_57 + V_36 -> V_62 ,
V_72 + V_75 , 64 ) ;
else
F_49 ( V_34 -> V_57 + V_36 -> V_62 ,
V_72 + V_75 , 128 ) ;
#else
F_50 ( V_72 + V_75 ,
V_36 -> V_38 + V_79 , 128 ) ;
#endif
V_75 += 128 ;
V_74 -- ;
}
if ( ! ( F_47 ( V_36 -> V_60 ) & V_77 ) )
F_2 ( L_17 ) ;
while ( ! ( F_47 ( V_36 -> V_60 ) & V_80 ) )
;
if ( ! ( F_47 ( V_81 ) & V_82 ) )
F_2 ( V_6 L_18 ) ;
return 0 ;
}
static inline int F_51 ( struct V_33 * V_34 ,
unsigned char * V_83 , int V_73 )
{
struct V_35 * V_36 = F_34 ( V_34 ) ;
int V_74 = V_73 / 128 ;
int V_75 = 0 ;
F_37 ( V_36 -> V_60 , V_66 ) ;
F_37 ( V_36 -> V_61 , V_74 ) ;
while ( 1 ) {
if ( F_47 ( V_36 -> V_60 ) & V_77 ) {
F_2 ( V_6 L_19 , V_75 , V_74 ) ;
return - 1 ;
}
if ( F_47 ( V_36 -> V_61 ) == 0 )
break;
while ( F_47 ( V_36 -> V_60 ) & V_78 )
;
#ifndef F_13
if ( V_36 -> V_59 == 2 )
F_52 ( V_34 -> V_57 + V_36 -> V_62 ,
V_83 + V_75 , 64 ) ;
else
F_53 ( V_34 -> V_57 + V_36 -> V_62 ,
V_83 + V_75 , 128 ) ;
#else
F_54 ( V_36 -> V_38 + V_79 ,
V_83 + V_75 , 128 ) ;
#endif
V_75 += 128 ;
V_74 -- ;
}
if ( V_74 ) {
while ( F_47 ( V_36 -> V_60 ) & V_78 )
;
#ifndef F_13
if ( V_36 -> V_59 == 2 )
F_52 ( V_34 -> V_57 + V_36 -> V_62 ,
V_83 + V_75 , 64 ) ;
else
F_53 ( V_34 -> V_57 + V_36 -> V_62 ,
V_83 + V_75 , 128 ) ;
#else
F_54 ( V_36 -> V_38 + V_79 ,
V_83 + V_75 , 128 ) ;
#endif
V_75 += 128 ;
V_74 -- ;
}
while ( ! ( F_47 ( V_36 -> V_60 ) & V_80 ) ) {
F_55 ( 4 ) ;
}
if ( ! ( F_47 ( V_81 ) & V_82 ) ) {
F_2 ( V_6 L_20 ) ;
}
while ( ! ( F_47 ( V_84 ) & V_85 ) )
;
return 0 ;
}
static int F_56 ( struct V_33 * V_34 ,
struct V_86 * V_87 )
{
struct V_35 * V_36 = F_34 ( V_34 ) ;
int V_88 = V_87 -> V_88 ;
if ( V_36 -> V_32 & V_52 )
return 0 ;
if ( V_88 > 32 * 1024 && V_87 -> V_89 . V_90 &&
! ( V_87 -> V_89 . V_90 % V_88 ) )
V_88 = 32 * 1024 ;
if ( V_88 % 128 )
V_88 = 0 ;
return V_88 ;
}
