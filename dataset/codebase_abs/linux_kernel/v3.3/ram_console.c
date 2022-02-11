static void F_1 ( T_1 * V_1 , T_2 V_2 , T_1 * V_3 )
{
int V_4 ;
T_3 V_5 [ V_6 ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_2 ( V_7 , V_1 , V_2 , V_5 , 0 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
V_3 [ V_4 ] = V_5 [ V_4 ] ;
}
static int F_3 ( void * V_1 , T_2 V_2 , T_1 * V_3 )
{
int V_4 ;
T_3 V_5 [ V_6 ] ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
V_5 [ V_4 ] = V_3 [ V_4 ] ;
return F_4 ( V_7 , V_1 , V_5 , V_2 ,
NULL , 0 , NULL , 0 , NULL ) ;
}
static void F_5 ( const char * V_8 , unsigned int V_9 )
{
struct V_10 * V_11 = V_10 ;
#ifdef F_6
T_1 * V_12 = V_11 -> V_1 + V_13 ;
T_1 * V_14 ;
T_1 * V_5 ;
int V_15 = V_16 ;
#endif
memcpy ( V_11 -> V_1 + V_11 -> V_17 , V_8 , V_9 ) ;
#ifdef F_6
V_14 = V_11 -> V_1 + ( V_11 -> V_17 & ~ ( V_16 - 1 ) ) ;
V_5 = V_18 +
( V_11 -> V_17 / V_16 ) * V_6 ;
do {
if ( V_14 + V_16 > V_12 )
V_15 = V_12 - V_14 ;
F_1 ( V_14 , V_15 , V_5 ) ;
V_14 += V_16 ;
V_5 += V_6 ;
} while ( V_14 < V_11 -> V_1 + V_11 -> V_17 + V_9 );
#endif
}
static void F_7 ( void )
{
#ifdef F_6
struct V_10 * V_11 = V_10 ;
T_1 * V_5 ;
V_5 = V_18 +
F_8 ( V_13 , V_16 ) * V_6 ;
F_1 ( ( T_1 * ) V_11 , sizeof( * V_11 ) , V_5 ) ;
#endif
}
static void
F_9 ( struct V_19 * V_19 , const char * V_8 , unsigned int V_9 )
{
int V_20 ;
struct V_10 * V_11 = V_10 ;
if ( V_9 > V_13 ) {
V_8 += V_9 - V_13 ;
V_9 = V_13 ;
}
V_20 = V_13 - V_11 -> V_17 ;
if ( V_20 < V_9 ) {
F_5 ( V_8 , V_20 ) ;
V_8 += V_20 ;
V_9 -= V_20 ;
V_11 -> V_17 = 0 ;
V_11 -> V_15 = V_13 ;
}
F_5 ( V_8 , V_9 ) ;
V_11 -> V_17 += V_9 ;
if ( V_11 -> V_15 < V_13 )
V_11 -> V_15 += V_9 ;
F_7 () ;
}
void F_10 ( int V_21 )
{
if ( V_21 )
V_22 . V_23 |= V_24 ;
else
V_22 . V_23 &= ~ V_24 ;
}
static void T_4
F_11 ( struct V_10 * V_11 , const char * V_25 ,
char * V_26 )
{
T_2 V_27 = V_11 -> V_15 ;
T_2 V_28 = 0 ;
T_2 V_29 = V_27 ;
char * V_30 ;
const char * V_31 = L_1 ;
#ifdef F_6
T_1 * V_14 ;
T_1 * V_5 ;
char V_32 [ 80 ] ;
int V_33 = 0 ;
V_14 = V_11 -> V_1 ;
V_5 = V_18 ;
while ( V_14 < V_11 -> V_1 + V_11 -> V_15 ) {
int V_34 ;
int V_15 = V_16 ;
if ( V_14 + V_15 > V_11 -> V_1 + V_13 )
V_15 = V_11 -> V_1 + V_13 - V_14 ;
V_34 = F_3 ( V_14 , V_15 , V_5 ) ;
if ( V_34 > 0 ) {
#if 0
printk(KERN_INFO "ram_console: error in block %p, %d\n",
block, numerr);
#endif
V_35 += V_34 ;
} else if ( V_34 < 0 ) {
#if 0
printk(KERN_INFO "ram_console: uncorrectable error in "
"block %p\n", block);
#endif
V_36 ++ ;
}
V_14 += V_16 ;
V_5 += V_6 ;
}
if ( V_35 || V_36 )
V_33 = snprintf ( V_32 , sizeof( V_32 ) ,
L_2 ,
V_35 , V_36 ) ;
else
V_33 = snprintf ( V_32 , sizeof( V_32 ) ,
L_3 ) ;
if ( V_33 >= sizeof( V_32 ) )
V_33 = sizeof( V_32 ) - 1 ;
V_29 += V_33 ;
#endif
if ( V_25 )
V_28 = strlen ( V_25 ) + strlen ( V_31 ) ;
V_29 += V_28 ;
if ( V_26 == NULL ) {
V_26 = F_12 ( V_29 , V_37 ) ;
if ( V_26 == NULL ) {
F_13 ( V_38
L_4 ) ;
return;
}
}
V_39 = V_26 ;
V_40 = V_29 ;
memcpy ( V_39 ,
& V_11 -> V_1 [ V_11 -> V_17 ] , V_11 -> V_15 - V_11 -> V_17 ) ;
memcpy ( V_39 + V_11 -> V_15 - V_11 -> V_17 ,
& V_11 -> V_1 [ 0 ] , V_11 -> V_17 ) ;
V_30 = V_39 + V_27 ;
#ifdef F_6
memcpy ( V_30 , V_32 , V_33 ) ;
V_30 += V_33 ;
#endif
if ( V_25 ) {
memcpy ( V_30 , V_31 , strlen ( V_31 ) ) ;
V_30 += strlen ( V_31 ) ;
memcpy ( V_30 , V_25 , V_28 ) ;
V_30 += V_28 ;
}
}
static int T_4 F_14 ( struct V_10 * V_11 ,
T_2 V_41 , const char * V_25 ,
char * V_42 )
{
#ifdef F_6
int V_34 ;
T_1 * V_5 ;
#endif
V_10 = V_11 ;
V_13 =
V_41 - sizeof( struct V_10 ) ;
if ( V_13 > V_41 ) {
F_15 ( L_5
L_6 , V_11 , V_41 ,
V_13 ) ;
return 0 ;
}
#ifdef F_6
V_13 -= ( F_8 ( V_13 ,
V_16 ) + 1 ) * V_6 ;
if ( V_13 > V_41 ) {
F_15 ( L_5
L_7 ,
V_11 , V_41 , V_13 ) ;
return 0 ;
}
V_18 = V_11 -> V_1 + V_13 ;
V_7 = F_16 ( V_43 , V_44 , 0 , 1 , V_6 ) ;
if ( V_7 == NULL ) {
F_13 ( V_45 L_8 ) ;
return 0 ;
}
V_35 = 0 ;
V_36 = 0 ;
V_5 = V_18 +
F_8 ( V_13 , V_16 ) * V_6 ;
V_34 = F_3 ( V_11 , sizeof( * V_11 ) , V_5 ) ;
if ( V_34 > 0 ) {
F_13 ( V_45 L_9 , V_34 ) ;
V_35 += V_34 ;
} else if ( V_34 < 0 ) {
F_13 ( V_45
L_10 ) ;
V_36 ++ ;
}
#endif
if ( V_11 -> V_46 == V_47 ) {
if ( V_11 -> V_15 > V_13
|| V_11 -> V_17 > V_11 -> V_15 )
F_13 ( V_45 L_11
L_12 ,
V_11 -> V_15 , V_11 -> V_17 ) ;
else {
F_13 ( V_45 L_13
L_14 ,
V_11 -> V_15 , V_11 -> V_17 ) ;
F_11 ( V_11 , V_25 , V_42 ) ;
}
} else {
F_13 ( V_45 L_15
L_16 , V_11 -> V_46 ) ;
}
V_11 -> V_46 = V_47 ;
V_11 -> V_17 = 0 ;
V_11 -> V_15 = 0 ;
F_17 ( & V_22 ) ;
#ifdef F_18
F_19 () ;
#endif
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_14 ( (struct V_10 * )
V_48 ,
V_49 ,
NULL ,
V_50 ) ;
}
static int F_21 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_53 ;
T_2 V_17 ;
T_2 V_41 ;
void * V_11 ;
const char * V_25 = NULL ;
struct V_55 * V_56 = V_52 -> V_57 . V_58 ;
if ( V_54 == NULL || V_52 -> V_59 != 1 ||
! ( V_54 -> V_23 & V_60 ) ) {
F_13 ( V_38 L_17
L_18 , V_54 , V_52 -> V_59 , V_54 ? V_54 -> V_23 : 0 ) ;
return - V_61 ;
}
V_41 = V_54 -> V_62 - V_54 -> V_17 + 1 ;
V_17 = V_54 -> V_17 ;
F_13 ( V_45 L_19 ,
V_17 , V_41 ) ;
V_11 = F_22 ( V_54 -> V_17 , V_41 ) ;
if ( V_11 == NULL ) {
F_13 ( V_38 L_20 ) ;
return - V_63 ;
}
if ( V_56 )
V_25 = V_56 -> V_25 ;
return F_14 ( V_11 , V_41 , V_25 , NULL ) ;
}
static int T_4 F_23 ( void )
{
int V_64 ;
V_64 = F_24 ( & V_65 ) ;
return V_64 ;
}
static T_5 F_25 ( struct V_66 * V_66 , char T_6 * V_67 ,
T_2 V_2 , T_7 * V_68 )
{
T_7 V_69 = * V_68 ;
T_5 V_9 ;
if ( V_69 >= V_40 )
return 0 ;
V_9 = F_26 ( V_2 , ( T_2 ) ( V_40 - V_69 ) ) ;
if ( F_27 ( V_67 , V_39 + V_69 , V_9 ) )
return - V_70 ;
* V_68 += V_9 ;
return V_9 ;
}
static int T_4 F_28 ( void )
{
struct V_71 * V_72 ;
if ( V_39 == NULL )
return 0 ;
#ifdef F_29
V_39 = F_12 ( V_40 , V_37 ) ;
if ( V_39 == NULL ) {
F_13 ( V_38
L_21 ) ;
V_40 = 0 ;
return 0 ;
}
memcpy ( V_39 ,
V_50 , V_40 ) ;
#endif
V_72 = F_30 ( L_22 , V_73 | V_74 , NULL ) ;
if ( ! V_72 ) {
F_13 ( V_38 L_23 ) ;
F_31 ( V_39 ) ;
V_39 = NULL ;
return 0 ;
}
V_72 -> V_75 = & V_76 ;
V_72 -> V_15 = V_40 ;
return 0 ;
}
