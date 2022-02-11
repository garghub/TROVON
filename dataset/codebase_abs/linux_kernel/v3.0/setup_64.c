static void
F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned V_4 )
{
F_2 ( V_3 , V_4 ) ;
}
static void T_1 F_3 ( char V_5 )
{
switch ( V_5 ) {
case 'd' :
case 's' :
break;
case 'h' :
F_4 ( L_1 ) ;
F_5 () ;
break;
case 'p' :
break;
case 'P' :
if ( V_6 != V_7 ) {
F_6 ( L_2 ) ;
break;
}
V_8 = 1 ;
F_7 ( V_9 ) ;
F_8 () ;
break;
default:
F_6 ( L_3 , V_5 ) ;
break;
}
}
static void T_1 F_9 ( char * V_10 )
{
while ( * V_10 ) {
while ( * V_10 && * V_10 == ' ' )
V_10 ++ ;
if ( * V_10 == '\0' )
break;
if ( * V_10 == '-' ) {
V_10 ++ ;
while ( * V_10 && * V_10 != ' ' )
F_3 ( * V_10 ++ ) ;
continue;
}
if ( ! strncmp ( V_10 , L_4 , 4 ) ) {
V_11 = F_10 ( V_10 + 4 ,
& V_10 , 0 ) ;
if ( * V_10 == 'K' || * V_10 == 'k' ) {
V_11 <<= 10 ;
V_10 ++ ;
} else if ( * V_10 == 'M' || * V_10 == 'm' ) {
V_11 <<= 20 ;
V_10 ++ ;
}
}
while ( * V_10 && * V_10 != ' ' )
V_10 ++ ;
}
}
void T_1 F_11 ( void )
{
struct V_12 * V_13 ;
unsigned long V_14 ;
int V_15 ;
if ( V_6 == V_16 && ! V_17 )
return;
V_15 = 0 ;
if ( V_6 != V_18 ) {
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_15 = ( ( V_14 >> 32UL ) == V_19 ||
( V_14 >> 32UL ) == V_20 ) ;
}
V_13 = & V_21 ;
while ( V_13 < & V_22 ) {
unsigned long V_23 = V_13 -> V_23 ;
unsigned int * V_24 ;
switch ( V_6 ) {
case V_16 :
V_24 = & V_13 -> V_25 [ 0 ] ;
break;
case V_7 :
case V_26 :
if ( V_15 )
V_24 = & V_13 -> V_27 [ 0 ] ;
else
V_24 = & V_13 -> V_28 [ 0 ] ;
break;
case V_18 :
V_24 = & V_13 -> V_29 [ 0 ] ;
break;
default:
F_4 ( L_5 ) ;
F_5 () ;
}
* ( unsigned int * ) ( V_23 + 0 ) = V_24 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_23 + 4 ) = V_24 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
* ( unsigned int * ) ( V_23 + 8 ) = V_24 [ 2 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 8));
* ( unsigned int * ) ( V_23 + 12 ) = V_24 [ 3 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 12));
V_13 ++ ;
}
}
void T_1 F_13 ( void )
{
extern void V_30 ( void ) ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
if ( V_6 != V_18 )
return;
V_32 = & V_35 ;
while ( V_32 < & V_36 ) {
unsigned long V_23 = V_32 -> V_23 ;
* ( unsigned int * ) ( V_23 + 0 ) = V_32 -> V_37 ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
V_32 ++ ;
}
V_34 = & V_38 ;
while ( V_34 < & V_39 ) {
unsigned long V_23 = V_34 -> V_23 ;
* ( unsigned int * ) ( V_23 + 0 ) = V_34 -> V_24 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_23 + 4 ) = V_34 -> V_24 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
V_34 ++ ;
}
V_30 () ;
}
void T_1 F_14 ( int V_40 )
{
F_4 ( L_6 ,
V_40 , V_41 ) ;
F_5 () ;
}
void T_1 F_15 ( char * * V_42 )
{
* V_42 = F_16 () ;
strcpy ( V_43 , * V_42 ) ;
F_17 () ;
F_9 ( * V_42 ) ;
#ifdef F_18
if ( F_19 () )
#endif
F_20 ( & V_44 ) ;
if ( V_6 == V_18 )
F_6 ( L_7 ) ;
else
F_6 ( L_8 ) ;
#ifdef F_21
V_45 = & V_46 ;
#endif
F_22 () ;
if ( ! V_47 )
V_48 &= ~ V_49 ;
V_50 = F_23 ( V_51 ) ;
#ifdef F_24
V_52 = V_53 & V_54 ;
V_55 = ( ( V_53 & V_56 ) != 0 ) ;
V_57 = ( ( V_53 & V_58 ) != 0 ) ;
#endif
F_25 ( & V_59 ) -> V_60 = & V_61 ;
#ifdef F_26
if ( ! V_62 ) {
T_2 V_63 = F_27 ( L_9 ) ;
T_3 V_64 , V_65 , V_66 ;
V_64 = F_28 ( V_63 , L_10 , 0 ) ;
V_65 = F_28 ( V_63 , L_11 , 0 ) ;
V_66 = F_28 ( V_63 , L_12 , 0 ) ;
if ( V_64 && V_65 ) {
V_67 = V_64 ;
V_68 = V_65 ;
if ( V_66 )
V_69 = V_66 ;
#if F_29 ( V_70 ) || F_29 ( V_71 )
V_72 = 0 ;
#endif
}
}
#endif
F_30 ( F_31 () ) ;
F_32 () ;
}
void F_33 ( void )
{
if ( ! V_73 )
return;
F_4 ( L_13 ) ;
F_34 () ;
F_35 () ;
}
