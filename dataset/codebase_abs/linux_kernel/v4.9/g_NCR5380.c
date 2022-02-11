static void F_1 ( int V_1 , T_1 V_2 , T_1 V_3 [] )
{
T_1 V_4 = 0 ;
F_2 ( V_3 [ 0 ] , 0x779 ) ;
F_2 ( V_3 [ 1 ] , 0x379 ) ;
F_2 ( V_3 [ 2 ] , 0x379 ) ;
F_2 ( V_3 [ 3 ] , 0x379 ) ;
F_2 ( V_3 [ 4 ] , 0x379 ) ;
if ( V_2 != 2 && V_2 != 3 && V_2 != 4 && V_2 != 5 && V_2 != 7 )
V_2 = 0 ;
if ( V_1 >= 0 && V_1 <= 7 )
V_4 = 0x80 | V_1 | ( V_2 << 4 ) ;
F_2 ( V_4 , 0x379 ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , int V_9 , int V_2 , int V_10 )
{
unsigned int * V_11 ;
T_1 * V_3 = NULL ;
#ifndef F_4
int V_12 ;
int V_13 = - 1 ;
unsigned long V_14 ;
#endif
static unsigned int V_15 [] = {
0x280 , 0x290 , 0x300 , 0x310 , 0x330 , 0x340 , 0x348 , 0x350 , 0
} ;
static unsigned int V_16 [] = {
0x220 , 0x240 , 0x280 , 0x2a0 , 0x2c0 , 0x300 , 0x320 , 0x340 , 0
} ;
static T_1 V_17 [] = {
0x59 , 0xb9 , 0xc5 , 0xae , 0xa6
} ;
static T_1 V_18 [] = {
0x0f , 0x22 , 0xf0 , 0x20 , 0x80
} ;
int V_19 , V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
#ifdef F_4
void T_2 * V_25 ;
T_3 V_26 ;
#endif
V_11 = NULL ;
V_19 = 0 ;
switch ( V_10 ) {
case V_27 :
V_19 = V_28 | V_29 ;
break;
case V_30 :
V_11 = V_15 ;
V_3 = V_17 ;
break;
case V_31 :
V_11 = V_15 ;
V_3 = V_18 ;
break;
case V_32 :
V_11 = V_16 ;
V_3 = V_17 ;
break;
}
#ifndef F_4
if ( V_11 && V_3 ) {
F_1 ( - 1 , 0 , V_3 ) ;
V_14 = 16 ;
if ( V_9 )
for ( V_12 = 0 ; V_11 [ V_12 ] ; V_12 ++ ) {
if ( V_9 == V_11 [ V_12 ] ) {
if ( ! F_5 ( V_11 [ V_12 ] ,
V_14 ,
L_1 ) )
return - V_33 ;
break;
}
}
else
for ( V_12 = 0 ; V_11 [ V_12 ] ; V_12 ++ ) {
if ( ! F_5 ( V_11 [ V_12 ] , V_14 ,
L_1 ) )
continue;
if ( F_6 ( V_11 [ V_12 ] ) == 0xff )
break;
F_7 ( V_11 [ V_12 ] , V_14 ) ;
}
if ( V_11 [ V_12 ] ) {
F_1 ( V_12 , 0 , V_3 ) ;
F_2 ( 0xc0 , V_11 [ V_12 ] + 9 ) ;
if ( F_6 ( V_11 [ V_12 ] + 9 ) != 0x80 ) {
V_20 = - V_34 ;
goto V_35;
}
V_9 = V_11 [ V_12 ] ;
V_13 = V_12 ;
} else
return - V_36 ;
}
else
{
V_14 = 8 ;
if ( ! V_9 || ! F_5 ( V_9 , V_14 , L_2 ) )
return - V_33 ;
}
#else
V_26 = V_37 ;
if ( ! F_8 ( V_9 , V_26 , L_2 ) )
return - V_33 ;
V_25 = F_9 ( V_9 , V_26 ) ;
if ( ! V_25 ) {
F_10 ( V_9 , V_26 ) ;
return - V_38 ;
}
#endif
V_22 = F_11 ( V_6 , sizeof( struct V_23 ) ) ;
if ( V_22 == NULL ) {
V_20 = - V_38 ;
goto V_35;
}
V_24 = F_12 ( V_22 ) ;
#ifndef F_4
V_22 -> V_39 = V_9 ;
V_22 -> V_40 = V_14 ;
V_24 -> V_41 = 1 ;
switch ( V_10 ) {
case V_42 :
V_22 -> V_39 += 8 ;
V_24 -> V_43 = 0 ;
V_24 -> V_44 = 1 ;
V_24 -> V_45 = 4 ;
break;
case V_32 :
V_24 -> V_41 = 2 ;
case V_30 :
case V_31 :
V_24 -> V_43 = 9 ;
V_24 -> V_44 = 10 ;
V_24 -> V_45 = 8 ;
break;
}
#else
V_22 -> V_9 = V_9 ;
V_24 -> V_25 = V_25 ;
V_24 -> V_26 = V_26 ;
switch ( V_10 ) {
case V_42 :
V_24 -> V_43 = 0x100 ;
V_24 -> V_44 = 0x101 ;
V_24 -> V_45 = 0x104 ;
break;
case V_32 :
case V_30 :
case V_31 :
F_13 ( V_46 L_3 ) ;
V_20 = - V_36 ;
goto V_47;
}
#endif
V_20 = F_14 ( V_22 , V_19 | V_48 ) ;
if ( V_20 )
goto V_47;
switch ( V_10 ) {
case V_42 :
case V_32 :
case V_30 :
case V_31 :
F_15 ( V_24 -> V_43 , V_49 ) ;
}
F_16 ( V_22 ) ;
if ( V_2 != V_50 )
V_22 -> V_2 = V_2 ;
else
V_22 -> V_2 = F_17 ( V_22 , 0xffff ) ;
if ( V_22 -> V_2 == 255 )
V_22 -> V_2 = V_51 ;
if ( V_22 -> V_2 != V_51 ) {
#ifndef F_4
if ( V_10 == V_31 )
F_1 ( V_13 , V_22 -> V_2 , V_3 ) ;
#endif
if ( F_18 ( V_22 -> V_2 , V_52 ,
0 , L_4 , V_22 ) ) {
F_19 ( V_53 L_5 , V_22 -> V_54 , V_22 -> V_2 ) ;
V_22 -> V_2 = V_51 ;
}
}
if ( V_22 -> V_2 == V_51 ) {
F_19 ( V_55 L_6 , V_22 -> V_54 ) ;
F_19 ( V_55 L_7 , V_22 -> V_54 ) ;
}
V_20 = F_20 ( V_22 , V_8 ) ;
if ( V_20 )
goto V_56;
F_21 ( V_22 ) ;
F_22 ( V_8 , V_22 ) ;
return 0 ;
V_56:
if ( V_22 -> V_2 != V_51 )
F_23 ( V_22 -> V_2 , V_22 ) ;
F_24 ( V_22 ) ;
V_47:
F_25 ( V_22 ) ;
V_35:
#ifndef F_4
F_7 ( V_9 , V_14 ) ;
#else
F_26 ( V_25 ) ;
F_10 ( V_9 , V_26 ) ;
#endif
return V_20 ;
}
static void F_27 ( struct V_21 * V_22 )
{
F_28 ( V_22 ) ;
if ( V_22 -> V_2 != V_51 )
F_23 ( V_22 -> V_2 , V_22 ) ;
F_24 ( V_22 ) ;
#ifndef F_4
F_7 ( V_22 -> V_39 , V_22 -> V_40 ) ;
#else
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
F_26 ( V_24 -> V_25 ) ;
F_10 ( V_22 -> V_9 , V_24 -> V_26 ) ;
}
#endif
F_25 ( V_22 ) ;
}
static inline int F_29 ( struct V_21 * V_22 ,
unsigned char * V_57 , int V_58 )
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
int V_59 = V_58 / 128 ;
int V_60 = 0 ;
F_15 ( V_24 -> V_43 , V_49 | V_61 ) ;
F_15 ( V_24 -> V_44 , V_59 ) ;
while ( 1 ) {
if ( F_30 ( V_24 -> V_44 ) == 0 )
break;
if ( F_30 ( V_24 -> V_43 ) & V_62 ) {
F_19 ( V_63 L_8 , V_60 , V_59 ) ;
return - 1 ;
}
while ( F_30 ( V_24 -> V_43 ) & V_64 )
;
#ifndef F_4
if ( V_24 -> V_41 == 2 )
F_31 ( V_22 -> V_39 + V_24 -> V_45 ,
V_57 + V_60 , 64 ) ;
else
F_32 ( V_22 -> V_39 + V_24 -> V_45 ,
V_57 + V_60 , 128 ) ;
#else
F_33 ( V_57 + V_60 ,
V_24 -> V_25 + V_65 , 128 ) ;
#endif
V_60 += 128 ;
V_59 -- ;
}
if ( V_59 ) {
while ( F_30 ( V_24 -> V_43 ) & V_64 )
;
#ifndef F_4
if ( V_24 -> V_41 == 2 )
F_31 ( V_22 -> V_39 + V_24 -> V_45 ,
V_57 + V_60 , 64 ) ;
else
F_32 ( V_22 -> V_39 + V_24 -> V_45 ,
V_57 + V_60 , 128 ) ;
#else
F_33 ( V_57 + V_60 ,
V_24 -> V_25 + V_65 , 128 ) ;
#endif
V_60 += 128 ;
V_59 -- ;
}
if ( ! ( F_30 ( V_24 -> V_43 ) & V_62 ) )
F_19 ( L_9 ) ;
while ( ! ( F_30 ( V_24 -> V_43 ) & V_66 ) )
;
if ( ! ( F_30 ( V_67 ) & V_68 ) )
F_19 ( V_63 L_10 ) ;
return 0 ;
}
static inline int F_34 ( struct V_21 * V_22 ,
unsigned char * V_69 , int V_58 )
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
int V_59 = V_58 / 128 ;
int V_60 = 0 ;
F_15 ( V_24 -> V_43 , V_49 ) ;
F_15 ( V_24 -> V_44 , V_59 ) ;
while ( 1 ) {
if ( F_30 ( V_24 -> V_43 ) & V_62 ) {
F_19 ( V_63 L_11 , V_60 , V_59 ) ;
return - 1 ;
}
if ( F_30 ( V_24 -> V_44 ) == 0 )
break;
while ( F_30 ( V_24 -> V_43 ) & V_64 )
;
#ifndef F_4
if ( V_24 -> V_41 == 2 )
F_35 ( V_22 -> V_39 + V_24 -> V_45 ,
V_69 + V_60 , 64 ) ;
else
F_36 ( V_22 -> V_39 + V_24 -> V_45 ,
V_69 + V_60 , 128 ) ;
#else
F_37 ( V_24 -> V_25 + V_65 ,
V_69 + V_60 , 128 ) ;
#endif
V_60 += 128 ;
V_59 -- ;
}
if ( V_59 ) {
while ( F_30 ( V_24 -> V_43 ) & V_64 )
;
#ifndef F_4
if ( V_24 -> V_41 == 2 )
F_35 ( V_22 -> V_39 + V_24 -> V_45 ,
V_69 + V_60 , 64 ) ;
else
F_36 ( V_22 -> V_39 + V_24 -> V_45 ,
V_69 + V_60 , 128 ) ;
#else
F_37 ( V_24 -> V_25 + V_65 ,
V_69 + V_60 , 128 ) ;
#endif
V_60 += 128 ;
V_59 -- ;
}
while ( ! ( F_30 ( V_24 -> V_43 ) & V_66 ) ) {
F_38 ( 4 ) ;
}
if ( ! ( F_30 ( V_67 ) & V_68 ) ) {
F_19 ( V_63 L_12 ) ;
}
while ( ! ( F_30 ( V_70 ) & V_71 ) )
;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 ,
struct V_72 * V_73 )
{
struct V_23 * V_24 = F_12 ( V_22 ) ;
int V_74 = V_73 -> V_74 ;
if ( V_24 -> V_19 & V_28 )
return 0 ;
if ( V_74 > 32 * 1024 && V_73 -> V_75 . V_76 &&
! ( V_73 -> V_75 . V_76 % V_74 ) )
V_74 = 32 * 1024 ;
if ( V_74 % 128 )
V_74 = 0 ;
return V_74 ;
}
static int F_40 ( struct V_7 * V_8 , unsigned int V_77 )
{
int V_20 = F_3 ( & V_78 , V_8 , V_9 [ V_77 ] ,
V_2 [ V_77 ] , V_79 [ V_77 ] ) ;
if ( V_20 ) {
if ( V_9 [ V_77 ] )
F_19 ( V_53 L_13 ,
V_9 [ V_77 ] ) ;
return 0 ;
}
return 1 ;
}
static int F_41 ( struct V_7 * V_8 ,
unsigned int V_77 )
{
F_27 ( F_42 ( V_8 ) ) ;
F_22 ( V_8 , NULL ) ;
return 0 ;
}
static int F_43 ( struct V_80 * V_8 ,
const struct V_81 * V_82 )
{
int V_9 , V_2 ;
if ( F_44 ( V_8 ) < 0 )
return - V_33 ;
V_9 = F_45 ( V_8 , 0 ) ;
V_2 = F_46 ( V_8 , 0 ) ;
return F_3 ( & V_78 , & V_8 -> V_83 , V_9 , V_2 ,
V_82 -> V_84 ) ;
}
static void F_47 ( struct V_80 * V_8 )
{
F_27 ( F_48 ( V_8 ) ) ;
F_49 ( V_8 , NULL ) ;
}
static int T_4 F_50 ( void )
{
int V_20 = 0 ;
if ( V_2 [ 0 ] == 0 && V_9 [ 0 ] == 0 && V_79 [ 0 ] == - 1 ) {
V_2 [ 0 ] = V_85 ;
V_9 [ 0 ] = V_86 ;
if ( V_87 )
V_79 [ 0 ] = V_27 ;
if ( V_88 )
V_79 [ 0 ] = V_42 ;
if ( V_89 )
V_79 [ 0 ] = V_30 ;
if ( V_90 )
V_79 [ 0 ] = V_32 ;
if ( V_91 )
V_79 [ 0 ] = V_31 ;
}
#if ! F_51 ( F_4 ) && F_51 ( V_92 )
if ( ! F_52 ( & V_93 ) )
V_94 = 1 ;
#endif
V_20 = F_53 ( & V_95 , V_96 ) ;
if ( ! V_20 )
V_97 = 1 ;
return ( V_94 || V_97 ) ? 0 : V_20 ;
}
static void T_5 F_54 ( void )
{
#if ! F_51 ( F_4 ) && F_51 ( V_92 )
if ( V_94 )
F_55 ( & V_93 ) ;
#endif
if ( V_97 )
F_56 ( & V_95 ) ;
}
