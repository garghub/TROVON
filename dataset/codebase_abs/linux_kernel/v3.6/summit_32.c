static unsigned F_1 ( unsigned long V_1 )
{
return ( V_1 >> 24 ) & 0xFF ;
}
static inline void F_2 ( const struct V_2 * V_3 , int V_4 )
{
F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( int V_4 )
{
F_5 ( V_5 , V_4 ) ;
}
static void F_6 ( int V_4 )
{
F_2 ( V_5 , V_4 ) ;
}
static inline void F_7 ( void ) {}
static int F_8 ( struct V_6 * V_7 , char * V_8 ,
char * V_9 )
{
if ( ! strncmp ( V_8 , L_1 , 8 ) &&
( ! strncmp ( V_9 , L_2 , 9 )
|| ! strncmp ( V_9 , L_3 , 3 )
|| ! strncmp ( V_9 , L_4 , 12 ) ) ) {
F_9 ( L_5 ) ;
V_10 = 1 ;
F_7 () ;
return 1 ;
}
return 0 ;
}
static int F_10 ( char * V_11 , char * V_12 )
{
if ( ! strncmp ( V_11 , L_6 , 3 ) &&
( ! strncmp ( V_12 , L_7 , 8 )
|| ! strncmp ( V_12 , L_3 , 3 ) ) ) {
F_9 ( L_5 ) ;
V_10 = 1 ;
F_7 () ;
return 1 ;
}
return 0 ;
}
static inline int F_11 ( struct V_13 * V_14 ) {
return ( V_14 -> type == V_15 || V_14 -> type == V_16 ||
V_14 -> type == V_17 || V_14 -> type == V_18 ) ;
}
static const struct V_2 * F_12 ( void )
{
return F_13 ( 0 ) ;
}
static unsigned long F_14 ( T_1 * V_19 , int V_20 )
{
return 0 ;
}
static unsigned long F_15 ( int V_21 )
{
return 1 ;
}
static int F_16 ( int V_22 )
{
int V_23 = 0 ;
T_2 V_24 = F_17 ( V_25 , V_22 ) ;
T_2 V_26 = F_18 ( V_24 ) ;
#ifdef F_19
T_2 V_27 ;
int V_28 ;
for ( V_23 = 0 , V_28 = V_29 ; -- V_28 >= 0 ; ) {
V_27 = F_17 ( V_30 , V_28 ) ;
if ( V_27 != V_31 && F_18 ( V_27 ) == V_26 )
++ V_23 ;
}
#endif
F_20 ( V_23 >= V_32 ) ;
return V_26 | ( 1UL << V_23 ) ;
}
static void F_21 ( void )
{
int V_22 = F_22 () ;
unsigned long V_33 = F_17 ( V_30 , V_22 ) ;
unsigned long V_34 ;
F_23 ( V_35 , V_36 ) ;
V_34 = F_24 ( V_37 ) & ~ V_38 ;
V_34 |= F_25 ( V_33 ) ;
F_23 ( V_37 , V_34 ) ;
}
static int F_26 ( void )
{
return 1 ;
}
static void F_27 ( void )
{
F_28 ( L_8 ,
V_39 ) ;
}
static int F_29 ( int V_40 )
{
if ( V_40 < V_29 )
return ( int ) F_30 ( V_41 , V_40 ) ;
else
return V_31 ;
}
static void F_31 ( T_1 * V_42 , T_1 * V_43 )
{
F_32 ( 0x0FL , V_43 ) ;
}
static void F_33 ( int V_20 , T_1 * V_43 )
{
F_34 ( 0 , V_43 ) ;
}
static int F_35 ( int V_44 )
{
return 1 ;
}
static inline int
F_36 ( const struct V_2 * V_2 , unsigned int * V_45 )
{
unsigned int V_46 = 0 ;
unsigned int V_22 , V_20 = 0 ;
F_37 (cpu, cpumask, cpu_online_mask) {
int V_47 = F_17 ( V_30 , V_22 ) ;
if ( V_46 && F_18 ( V_20 ) != F_18 ( V_47 ) ) {
F_38 ( L_9 ) ;
return - V_48 ;
}
V_20 |= V_47 ;
V_46 ++ ;
}
if ( ! V_46 )
return - V_48 ;
* V_45 = V_20 ;
return 0 ;
}
static int
F_39 ( const struct V_2 * V_49 ,
const struct V_2 * V_50 ,
unsigned int * V_20 )
{
T_3 V_2 ;
* V_20 = F_17 ( V_30 , 0 ) ;
if ( ! F_40 ( & V_2 , V_51 ) )
return 0 ;
F_41 ( V_2 , V_49 , V_50 ) ;
F_36 ( V_2 , V_20 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_43 ( int V_52 , int V_53 )
{
return F_44 () >> V_53 ;
}
static int F_45 ( void )
{
return 0 ;
}
static int F_46 ( int V_54 , int V_55 )
{
int V_56 = 0 , V_57 = 0 ;
int V_28 , V_58 , V_59 ;
for ( V_28 = 0 ; V_28 < V_60 -> V_61 ; V_28 ++ ) {
if ( V_62 [ V_28 ] -> V_63 == V_62 [ V_54 ] -> V_64 ) {
V_56 = V_62 [ V_28 ] -> V_64 ;
break;
}
}
if ( V_28 == V_60 -> V_61 ) {
F_38 ( L_10 ) ;
return V_55 ;
}
for ( V_28 = 0 ; V_28 < V_60 -> V_65 ; V_28 ++ ) {
if ( V_66 [ V_28 ] -> V_63 == V_56 ) {
V_57 = V_66 [ V_28 ] -> V_63 ;
break;
}
}
if ( V_28 == V_60 -> V_65 ) {
F_38 ( L_11 ) ;
return V_55 ;
}
switch ( V_62 [ V_54 ] -> type ) {
case V_15 :
V_59 = 5 ;
break;
case V_16 :
V_59 = 7 ;
break;
case V_17 :
case V_18 :
V_59 = 9 ;
break;
default:
F_28 ( L_12 ) ;
return V_55 ;
}
for ( V_58 = V_55 ; V_58 < V_55 + V_59 ; V_58 ++ )
V_67 [ V_58 ] = V_57 ;
return V_58 ;
}
static int F_47 ( void )
{
unsigned long V_68 ;
int V_28 , V_69 , V_70 ;
if ( V_60 -> V_65 > V_71 ) {
F_48 ( L_13 ,
V_71 , V_60 -> V_65 ) ;
return 0 ;
}
switch ( V_60 -> V_72 ) {
default:
F_48 ( L_14 ,
V_60 -> V_72 ) ;
return 0 ;
case 2 :
V_69 = 11 ;
V_70 = 13 ;
break;
case 3 :
V_69 = 12 ;
V_70 = 15 ;
break;
}
V_68 = ( unsigned long ) V_60 + 3 ;
for ( V_28 = 0 ; V_28 < V_60 -> V_65 ; V_28 ++ , V_68 += V_69 )
V_66 [ V_28 ] = (struct V_73 * ) V_68 ;
for ( V_28 = 0 ; V_28 < V_60 -> V_61 ; V_28 ++ , V_68 += V_70 )
V_62 [ V_28 ] = (struct V_13 * ) V_68 ;
return 1 ;
}
void F_7 ( void )
{
unsigned long V_68 ;
unsigned short V_74 ;
int V_28 , V_75 , V_76 = 0 ;
V_68 = F_49 () ;
V_68 = ( unsigned long ) F_50 ( V_68 ) ;
V_60 = NULL ;
V_74 = 0x180 ;
while ( V_74 ) {
if ( * ( ( unsigned short * ) ( V_68 + V_74 + 2 ) ) == 0x4752 ) {
V_60 = (struct V_60 * ) ( V_68 + V_74 + 4 ) ;
break;
}
V_74 = * ( ( unsigned short * ) ( V_68 + V_74 ) ) ;
}
if ( ! V_60 ) {
F_38 ( L_15 ) ;
return;
}
if ( ! F_47 () )
return;
V_75 = 0 ;
do {
for ( V_28 = 0 ; V_28 < V_60 -> V_61 ; V_28 ++ ) {
if ( F_11 ( V_62 [ V_28 ] ) && V_62 [ V_28 ] -> V_77 == V_75 ) {
V_76 = F_46 ( V_28 , V_76 ) ;
V_75 ++ ;
break;
}
}
if ( V_28 == V_60 -> V_61 )
V_75 = 0 ;
} while ( V_75 != 0 );
}
