static void F_1 ( void )
{
struct V_1 V_2 , V_3 ;
F_2 ( & V_2 ) ;
V_2 . V_4 = 0x03 ;
F_3 ( 0x10 , & V_2 , & V_3 ) ;
V_5 . V_6 . V_7 = V_3 . V_8 ;
V_5 . V_6 . V_9 = V_3 . V_10 ;
if ( V_3 . V_11 & 0x20 )
V_5 . V_6 . V_12 |= V_13 ;
if ( ( V_3 . V_11 & 0x1f ) > ( V_3 . V_14 & 0x1f ) )
V_5 . V_6 . V_12 |= V_13 ;
}
static void F_4 ( void )
{
struct V_1 V_2 , V_3 ;
F_2 ( & V_2 ) ;
V_2 . V_4 = 0x0f ;
F_3 ( 0x10 , & V_2 , & V_3 ) ;
V_5 . V_6 . V_15 = V_3 . V_16 & 0x7f ;
V_5 . V_6 . V_17 = V_3 . V_18 ;
}
static void F_5 ( void )
{
T_1 V_19 ;
int V_20 , V_21 ;
if ( V_22 )
return;
F_1 () ;
F_4 () ;
if ( V_5 . V_6 . V_15 == 0x07 ) {
V_23 = 0xb000 ;
} else {
V_23 = 0xb800 ;
}
F_6 ( 0 ) ;
V_19 = F_7 ( 0x485 ) ;
V_5 . V_6 . V_24 = V_19 ;
V_20 = F_7 ( 0x44a ) ;
V_21 = ( V_25 == V_26 ) ? 25 : F_8 ( 0x484 ) + 1 ;
if ( V_27 )
V_20 = V_27 ;
if ( V_28 )
V_21 = V_28 ;
V_5 . V_6 . V_29 = V_20 ;
V_5 . V_6 . V_30 = V_21 ;
}
static unsigned int F_9 ( void )
{
char V_31 [ 4 ] ;
int V_32 , V_33 = 0 ;
int V_34 ;
unsigned int V_35 ;
do {
V_34 = getchar () ;
if ( V_34 == '\b' ) {
if ( V_33 > 0 ) {
puts ( L_1 ) ;
V_33 -- ;
}
} else if ( ( V_34 >= '0' && V_34 <= '9' ) ||
( V_34 >= 'A' && V_34 <= 'Z' ) ||
( V_34 >= 'a' && V_34 <= 'z' ) ) {
if ( V_33 < sizeof V_31 ) {
V_31 [ V_33 ++ ] = V_34 ;
putchar ( V_34 ) ;
}
}
} while ( V_34 != '\r' );
putchar ( '\n' ) ;
if ( V_33 == 0 )
return V_36 ;
V_35 = 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
V_35 <<= 4 ;
V_34 = V_31 [ V_32 ] | 0x20 ;
V_35 += ( V_34 > '9' ) ? V_34 - 'a' + 10 : V_34 - '0' ;
}
return V_35 ;
}
static void F_10 ( void )
{
struct V_37 * V_38 ;
struct V_39 * V_40 ;
char V_11 ;
int V_32 ;
int V_41 ;
int V_42 ;
int V_43 ;
V_41 = 0 ;
for ( V_38 = V_44 ; V_38 < V_45 ; V_38 ++ )
V_41 += V_38 -> V_41 ;
V_42 = 1 ;
if ( V_41 >= 20 )
V_42 = 3 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
puts ( L_2 ) ;
putchar ( '\n' ) ;
V_43 = 0 ;
V_11 = '0' ;
for ( V_38 = V_44 ; V_38 < V_45 ; V_38 ++ ) {
V_40 = V_38 -> V_46 ;
for ( V_32 = 0 ; V_32 < V_38 -> V_41 ; V_32 ++ , V_40 ++ ) {
char V_47 [ 32 ] ;
int V_48 = V_40 -> V_20 && V_40 -> V_21 ;
T_1 V_49 = V_40 -> V_50 ? V_40 -> V_50 :
( V_40 -> V_21 << 8 ) + V_40 -> V_20 ;
if ( ! V_48 )
continue;
if ( V_40 -> V_51 )
sprintf ( V_47 , L_3 , V_40 -> V_21 , V_40 -> V_51 ) ;
else
sprintf ( V_47 , L_4 , V_40 -> V_21 ) ;
printf ( L_5 ,
V_11 , V_49 , V_40 -> V_20 , V_47 , V_38 -> V_52 ) ;
V_43 ++ ;
if ( V_43 >= V_42 ) {
putchar ( '\n' ) ;
V_43 = 0 ;
}
if ( V_11 == '9' )
V_11 = 'a' ;
else if ( V_11 == 'z' || V_11 == ' ' )
V_11 = ' ' ;
else
V_11 ++ ;
}
}
if ( V_43 )
putchar ( '\n' ) ;
}
static unsigned int F_11 ( void )
{
int V_34 ;
unsigned int V_53 ;
puts ( L_6
L_7 ) ;
F_12 () ;
while ( 1 ) {
V_34 = F_13 () ;
if ( V_34 == ' ' || V_34 == 0 )
return V_36 ;
if ( V_34 == '\r' )
break;
putchar ( '\a' ) ;
}
for (; ; ) {
F_10 () ;
puts ( L_8
L_9 ) ;
V_53 = F_9 () ;
if ( V_53 != V_54 )
return V_53 ;
F_14 ( 1 ) ;
}
}
static void F_15 ( void )
{
V_55 . V_20 = V_5 . V_6 . V_29 ;
V_55 . V_21 = V_5 . V_6 . V_30 ;
V_55 . V_56 = V_5 . V_6 . V_7 ;
V_55 . V_57 = V_5 . V_6 . V_9 ;
if ( ! F_16 ( V_55 . V_20 * V_55 . V_21 * sizeof( T_1 ) + 512 ) )
return;
V_55 . V_58 = F_17 ( T_1 , V_55 . V_20 * V_55 . V_21 ) ;
F_6 ( V_23 ) ;
F_18 ( V_55 . V_58 , 0 , V_55 . V_20 * V_55 . V_21 * sizeof( T_1 ) ) ;
}
static void F_19 ( void )
{
int V_59 = V_5 . V_6 . V_29 ;
int V_60 = V_5 . V_6 . V_30 ;
int V_21 ;
T_2 V_61 = 0 ;
T_1 * V_62 = V_55 . V_58 ;
struct V_1 V_2 ;
if ( V_22 )
return;
if ( ! V_62 )
return;
F_6 ( V_23 ) ;
for ( V_21 = 0 ; V_21 < V_60 ; V_21 ++ ) {
int V_63 ;
if ( V_21 < V_55 . V_21 ) {
int V_64 = ( V_59 < V_55 . V_20 ) ? V_59 : V_55 . V_20 ;
F_20 ( V_61 , V_62 , V_64 * sizeof( T_1 ) ) ;
V_61 += V_64 * sizeof( T_1 ) ;
V_62 += V_55 . V_20 ;
V_63 = ( V_59 < V_55 . V_20 ) ? 0 : V_59 - V_55 . V_20 ;
} else {
V_63 = V_59 ;
}
asm volatile("pushw %%es ; "
"movw %2,%%es ; "
"shrw %%cx ; "
"jnc 1f ; "
"stosw \n\t"
"1: rep;stosl ; "
"popw %%es"
: "+D" (dst), "+c" (npad)
: "bdS" (video_segment),
"a" (0x07200720));
}
if ( V_55 . V_56 >= V_59 )
V_55 . V_56 = V_59 - 1 ;
if ( V_55 . V_57 >= V_60 )
V_55 . V_57 = V_60 - 1 ;
F_2 ( & V_2 ) ;
V_2 . V_4 = 0x02 ;
V_2 . V_10 = V_55 . V_57 ;
V_2 . V_8 = V_55 . V_56 ;
F_3 ( 0x10 , & V_2 , NULL ) ;
F_1 () ;
}
void F_21 ( void )
{
T_1 V_50 = V_5 . V_65 . V_66 ;
F_22 () ;
F_5 () ;
F_15 () ;
F_14 ( 0 ) ;
for (; ; ) {
if ( V_50 == V_67 )
V_50 = F_11 () ;
if ( ! F_23 ( V_50 ) )
break;
printf ( L_10 , V_50 ) ;
V_50 = V_67 ;
}
V_5 . V_65 . V_66 = V_50 ;
F_24 () ;
F_5 () ;
if ( V_68 )
F_19 () ;
}
