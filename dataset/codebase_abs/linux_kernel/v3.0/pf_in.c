static int F_1 ( unsigned char * V_1 , struct V_2 * V_3 )
{
int V_4 ;
unsigned char * V_5 = V_1 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 0 ;
V_10:
for ( V_4 = 0 ; V_4 < F_2 ( V_11 ) ; V_4 ++ ) {
if ( * V_5 == V_11 [ V_4 ] ) {
if ( * V_5 == 0x66 )
V_3 -> V_6 = 1 ;
#ifdef F_3
if ( ( * V_5 & 0xf8 ) == 0x48 )
V_3 -> V_7 = 1 ;
if ( ( * V_5 & 0xf4 ) == 0x44 )
V_3 -> V_8 = 1 ;
if ( ( * V_5 & 0xf0 ) == 0x40 )
V_3 -> V_9 = 1 ;
#endif
V_5 ++ ;
goto V_10;
}
}
return ( V_5 - V_1 ) ;
}
static int F_4 ( unsigned char * V_1 , unsigned int * V_12 )
{
int V_13 ;
if ( * V_1 == 0x0F ) {
* V_12 = * ( unsigned short * ) V_1 ;
V_13 = 2 ;
} else {
* V_12 = * V_1 ;
V_13 = 1 ;
}
return V_13 ;
}
enum V_14 F_5 ( unsigned long V_15 )
{
unsigned int V_12 ;
unsigned char * V_5 ;
struct V_2 V_3 ;
int V_4 ;
enum V_14 V_16 = V_17 ;
V_5 = ( unsigned char * ) V_15 ;
V_5 += F_1 ( V_5 , & V_3 ) ;
V_5 += F_4 ( V_5 , & V_12 ) ;
F_6 ( V_12 , V_18 , V_19 ) ;
F_6 ( V_12 , V_20 , V_21 ) ;
F_6 ( V_12 , V_22 , V_23 ) ;
exit:
return V_16 ;
}
static unsigned int F_7 ( unsigned long V_15 )
{
unsigned int V_12 ;
unsigned char * V_5 ;
struct V_2 V_3 ;
int V_4 ;
V_5 = ( unsigned char * ) V_15 ;
V_5 += F_1 ( V_5 , & V_3 ) ;
V_5 += F_4 ( V_5 , & V_12 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_24 ) ; V_4 ++ )
if ( V_24 [ V_4 ] == V_12 )
return 1 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_25 ) ; V_4 ++ )
if ( V_25 [ V_4 ] == V_12 )
return V_3 . V_6 ? 2 : ( V_3 . V_7 ? 8 : 4 ) ;
F_8 ( V_26 L_1 , V_12 ) ;
return 0 ;
}
unsigned int F_9 ( unsigned long V_15 )
{
unsigned int V_12 ;
unsigned char * V_5 ;
struct V_2 V_3 ;
int V_4 ;
V_5 = ( unsigned char * ) V_15 ;
V_5 += F_1 ( V_5 , & V_3 ) ;
V_5 += F_4 ( V_5 , & V_12 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_27 ) ; V_4 ++ )
if ( V_27 [ V_4 ] == V_12 )
return 1 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_28 ) ; V_4 ++ )
if ( V_28 [ V_4 ] == V_12 )
return 2 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_29 ) ; V_4 ++ )
if ( V_29 [ V_4 ] == V_12 )
return V_3 . V_6 ? 2 : 4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_30 ) ; V_4 ++ )
if ( V_30 [ V_4 ] == V_12 )
return V_3 . V_6 ? 2 : ( V_3 . V_7 ? 8 : 4 ) ;
F_8 ( V_26 L_1 , V_12 ) ;
return 0 ;
}
static unsigned char * F_10 ( int V_31 , int V_9 , struct V_32 * V_33 )
{
unsigned char * V_16 = NULL ;
switch ( V_31 ) {
case V_34 :
V_16 = ( unsigned char * ) & V_33 -> V_35 ;
break;
case V_36 :
V_16 = ( unsigned char * ) & V_33 -> V_37 ;
break;
case V_38 :
V_16 = ( unsigned char * ) & V_33 -> V_39 ;
break;
case V_40 :
V_16 = ( unsigned char * ) & V_33 -> V_41 ;
break;
#ifdef F_3
case V_42 :
V_16 = ( unsigned char * ) & V_33 -> V_43 ;
break;
case V_44 :
V_16 = ( unsigned char * ) & V_33 -> V_45 ;
break;
case V_46 :
V_16 = ( unsigned char * ) & V_33 -> V_47 ;
break;
case V_48 :
V_16 = ( unsigned char * ) & V_33 -> V_49 ;
break;
case V_50 :
V_16 = ( unsigned char * ) & V_33 -> V_51 ;
break;
case V_52 :
V_16 = ( unsigned char * ) & V_33 -> V_53 ;
break;
case V_54 :
V_16 = ( unsigned char * ) & V_33 -> V_55 ;
break;
case V_56 :
V_16 = ( unsigned char * ) & V_33 -> V_57 ;
break;
#endif
default:
break;
}
if ( V_16 )
return V_16 ;
if ( V_9 ) {
switch ( V_31 ) {
case V_58 :
V_16 = ( unsigned char * ) & V_33 -> V_59 ;
break;
case V_60 :
V_16 = ( unsigned char * ) & V_33 -> V_61 ;
break;
case V_62 :
V_16 = ( unsigned char * ) & V_33 -> V_63 ;
break;
case V_64 :
V_16 = ( unsigned char * ) & V_33 -> V_65 ;
break;
default:
break;
}
} else {
switch ( V_31 ) {
case V_66 :
V_16 = 1 + ( unsigned char * ) & V_33 -> V_35 ;
break;
case V_67 :
V_16 = 1 + ( unsigned char * ) & V_33 -> V_37 ;
break;
case V_68 :
V_16 = 1 + ( unsigned char * ) & V_33 -> V_39 ;
break;
case V_69 :
V_16 = 1 + ( unsigned char * ) & V_33 -> V_41 ;
break;
default:
break;
}
}
if ( ! V_16 )
F_8 ( V_26 L_2 , V_31 ) ;
return V_16 ;
}
static unsigned long * F_11 ( int V_31 , struct V_32 * V_33 )
{
unsigned long * V_16 = NULL ;
switch ( V_31 ) {
case V_70 :
V_16 = & V_33 -> V_35 ;
break;
case V_71 :
V_16 = & V_33 -> V_37 ;
break;
case V_72 :
V_16 = & V_33 -> V_39 ;
break;
case V_73 :
V_16 = & V_33 -> V_41 ;
break;
case V_64 :
V_16 = & V_33 -> V_65 ;
break;
case V_62 :
V_16 = & V_33 -> V_63 ;
break;
case V_58 :
V_16 = & V_33 -> V_59 ;
break;
case V_60 :
V_16 = & V_33 -> V_61 ;
break;
#ifdef F_3
case V_42 :
V_16 = & V_33 -> V_43 ;
break;
case V_44 :
V_16 = & V_33 -> V_45 ;
break;
case V_46 :
V_16 = & V_33 -> V_47 ;
break;
case V_48 :
V_16 = & V_33 -> V_49 ;
break;
case V_50 :
V_16 = & V_33 -> V_51 ;
break;
case V_52 :
V_16 = & V_33 -> V_53 ;
break;
case V_54 :
V_16 = & V_33 -> V_55 ;
break;
case V_56 :
V_16 = & V_33 -> V_57 ;
break;
#endif
default:
F_8 ( V_26 L_2 , V_31 ) ;
}
return V_16 ;
}
unsigned long F_12 ( unsigned long V_15 , struct V_32 * V_33 )
{
unsigned int V_12 ;
int V_74 ;
unsigned char * V_5 ;
struct V_2 V_3 ;
int V_4 ;
V_5 = ( unsigned char * ) V_15 ;
V_5 += F_1 ( V_5 , & V_3 ) ;
V_5 += F_4 ( V_5 , & V_12 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_18 ) ; V_4 ++ )
if ( V_18 [ V_4 ] == V_12 )
goto V_75;
for ( V_4 = 0 ; V_4 < F_2 ( V_20 ) ; V_4 ++ )
if ( V_20 [ V_4 ] == V_12 )
goto V_75;
F_8 ( V_26 L_3
L_4 , V_12 ) ;
goto V_76;
V_75:
if ( V_12 == 0xAA || V_12 == 0xAB ) {
V_74 = V_70 ;
} else {
unsigned char V_77 = * V_5 ;
V_74 = ( ( V_77 >> 3 ) & 0x7 ) | ( V_3 . V_8 << 3 ) ;
}
switch ( F_7 ( V_15 ) ) {
case 1 :
return * F_10 ( V_74 , V_3 . V_9 , V_33 ) ;
case 2 :
return * ( unsigned short * ) F_11 ( V_74 , V_33 ) ;
case 4 :
return * ( unsigned int * ) F_11 ( V_74 , V_33 ) ;
#ifdef F_3
case 8 :
return * ( unsigned long * ) F_11 ( V_74 , V_33 ) ;
#endif
default:
F_8 ( V_26 L_5 , V_74 ) ;
}
V_76:
return 0 ;
}
unsigned long F_13 ( unsigned long V_15 )
{
unsigned int V_12 ;
unsigned char V_77 ;
unsigned char V_78 ;
unsigned char * V_5 ;
struct V_2 V_3 ;
int V_4 ;
V_5 = ( unsigned char * ) V_15 ;
V_5 += F_1 ( V_5 , & V_3 ) ;
V_5 += F_4 ( V_5 , & V_12 ) ;
for ( V_4 = 0 ; V_4 < F_2 ( V_22 ) ; V_4 ++ )
if ( V_22 [ V_4 ] == V_12 )
goto V_75;
F_8 ( V_26 L_6
L_4 , V_12 ) ;
goto V_76;
V_75:
V_77 = * V_5 ;
V_78 = V_77 >> 6 ;
V_5 ++ ;
switch ( V_78 ) {
case 0 :
if ( ( V_77 & 0x7 ) == 0x5 )
V_5 += 4 ;
break;
case 1 :
V_5 += 1 ;
break;
case 2 :
V_5 += 4 ;
break;
case 3 :
default:
F_8 ( V_26 L_7
L_8 ,
V_15 , V_77 ) ;
}
switch ( F_7 ( V_15 ) ) {
case 1 :
return * ( unsigned char * ) V_5 ;
case 2 :
return * ( unsigned short * ) V_5 ;
case 4 :
return * ( unsigned int * ) V_5 ;
#ifdef F_3
case 8 :
return * ( unsigned long * ) V_5 ;
#endif
default:
F_8 ( V_26 L_9 ) ;
}
V_76:
return 0 ;
}
