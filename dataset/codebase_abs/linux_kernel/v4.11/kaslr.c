static unsigned long F_1 ( unsigned long V_1 , const void * V_2 ,
T_1 V_3 )
{
T_1 V_4 ;
unsigned long * V_5 = ( unsigned long * ) V_2 ;
for ( V_4 = 0 ; V_4 < V_3 / sizeof( V_1 ) ; V_4 ++ ) {
V_1 = ( V_1 << ( ( sizeof( V_1 ) * 8 ) - 7 ) ) | ( V_1 >> 7 ) ;
V_1 ^= V_5 [ V_4 ] ;
}
return V_1 ;
}
static unsigned long F_2 ( void )
{
unsigned long V_1 = 0 ;
V_1 = F_1 ( V_1 , V_6 , sizeof( V_6 ) ) ;
V_1 = F_1 ( V_1 , V_7 , sizeof( * V_7 ) ) ;
return V_1 ;
}
static bool F_3 ( struct V_8 * V_9 , struct V_8 * V_10 )
{
if ( V_9 -> V_11 + V_9 -> V_3 <= V_10 -> V_11 )
return false ;
if ( V_9 -> V_11 >= V_10 -> V_11 + V_10 -> V_3 )
return false ;
return true ;
}
static unsigned long long F_4 ( const char * V_5 , char * * V_12 )
{
char * V_13 ;
unsigned long long V_14 = F_5 ( V_5 , & V_13 , 0 ) ;
switch ( * V_13 ) {
case 'E' :
case 'e' :
V_14 <<= 10 ;
case 'P' :
case 'p' :
V_14 <<= 10 ;
case 'T' :
case 't' :
V_14 <<= 10 ;
case 'G' :
case 'g' :
V_14 <<= 10 ;
case 'M' :
case 'm' :
V_14 <<= 10 ;
case 'K' :
case 'k' :
V_14 <<= 10 ;
V_13 ++ ;
default:
break;
}
if ( V_12 )
* V_12 = V_13 ;
return V_14 ;
}
static int
F_6 ( char * V_15 , unsigned long long * V_11 , unsigned long long * V_3 )
{
char * V_16 ;
if ( ! V_15 )
return - V_17 ;
if ( ! strncmp ( V_15 , L_1 , 8 ) )
return - V_17 ;
V_16 = V_15 ;
* V_3 = F_4 ( V_15 , & V_15 ) ;
if ( V_15 == V_16 )
return - V_17 ;
switch ( * V_15 ) {
case '@' :
* V_11 = 0 ;
* V_3 = 0 ;
return 0 ;
case '#' :
case '$' :
case '!' :
* V_11 = F_4 ( V_15 + 1 , & V_15 ) ;
return 0 ;
}
return - V_17 ;
}
static void F_7 ( void )
{
char V_18 [ 128 ] ;
int V_19 ;
int V_4 ;
char * V_20 ;
V_19 = F_8 ( L_2 , V_18 , sizeof( V_18 ) ) ;
if ( V_19 <= 0 )
return;
V_4 = 0 ;
V_20 = V_18 ;
while ( V_20 && ( V_4 < V_21 ) ) {
int V_19 ;
unsigned long long V_11 , V_3 ;
char * V_22 = strchr ( V_20 , ',' ) ;
if ( V_22 )
* V_22 ++ = 0 ;
V_19 = F_6 ( V_20 , & V_11 , & V_3 ) ;
if ( V_19 < 0 )
break;
V_20 = V_22 ;
if ( V_3 == 0 )
continue;
V_23 [ V_24 + V_4 ] . V_11 = V_11 ;
V_23 [ V_24 + V_4 ] . V_3 = V_3 ;
V_4 ++ ;
}
if ( ( V_4 >= V_21 ) && V_20 )
V_25 = true ;
}
static void F_9 ( unsigned long V_26 , unsigned long V_27 ,
unsigned long V_28 )
{
unsigned long V_29 = V_7 -> V_30 . V_29 ;
T_2 V_31 , V_32 ;
T_2 V_33 , V_34 ;
char * V_5 ;
V_23 [ V_35 ] . V_11 = V_26 ;
V_23 [ V_35 ] . V_3 = ( V_28 + V_29 ) - V_26 ;
F_10 ( V_23 [ V_35 ] . V_11 ,
V_23 [ V_35 ] . V_3 ) ;
V_31 = ( T_2 ) V_7 -> V_36 << 32 ;
V_31 |= V_7 -> V_30 . V_37 ;
V_32 = ( T_2 ) V_7 -> V_38 << 32 ;
V_32 |= V_7 -> V_30 . V_39 ;
V_23 [ V_40 ] . V_11 = V_31 ;
V_23 [ V_40 ] . V_3 = V_32 ;
V_33 = ( T_2 ) V_7 -> V_41 << 32 ;
V_33 |= V_7 -> V_30 . V_42 ;
V_5 = ( char * ) ( unsigned long ) V_33 ;
for ( V_34 = 0 ; V_5 [ V_34 ++ ] ; )
;
V_23 [ V_43 ] . V_11 = V_33 ;
V_23 [ V_43 ] . V_3 = V_34 ;
F_10 ( V_23 [ V_43 ] . V_11 ,
V_23 [ V_43 ] . V_3 ) ;
V_23 [ V_44 ] . V_11 = ( unsigned long ) V_7 ;
V_23 [ V_44 ] . V_3 = sizeof( * V_7 ) ;
F_10 ( V_23 [ V_44 ] . V_11 ,
V_23 [ V_44 ] . V_3 ) ;
F_7 () ;
#ifdef F_11
F_10 ( 0 , V_45 ) ;
#endif
}
static bool F_12 ( struct V_8 * V_46 ,
struct V_8 * V_47 )
{
int V_4 ;
struct V_48 * V_5 ;
unsigned long V_49 = V_46 -> V_11 + V_46 -> V_3 ;
bool V_50 = false ;
for ( V_4 = 0 ; V_4 < V_51 ; V_4 ++ ) {
if ( F_3 ( V_46 , & V_23 [ V_4 ] ) &&
V_23 [ V_4 ] . V_11 < V_49 ) {
* V_47 = V_23 [ V_4 ] ;
V_49 = V_47 -> V_11 ;
V_50 = true ;
}
}
V_5 = (struct V_48 * ) ( unsigned long ) V_7 -> V_30 . V_48 ;
while ( V_5 ) {
struct V_8 V_52 ;
V_52 . V_11 = ( unsigned long ) V_5 ;
V_52 . V_3 = sizeof( * V_5 ) + V_5 -> V_53 ;
if ( F_3 ( V_46 , & V_52 ) && ( V_52 . V_11 < V_49 ) ) {
* V_47 = V_52 ;
V_49 = V_47 -> V_11 ;
V_50 = true ;
}
V_5 = (struct V_48 * ) ( unsigned long ) V_5 -> V_54 ;
}
return V_50 ;
}
static void F_13 ( struct V_8 * V_55 , unsigned long V_56 )
{
struct V_57 V_57 ;
if ( V_58 == V_59 )
return;
V_57 . V_60 = V_55 -> V_11 ;
V_57 . V_61 = ( V_55 -> V_3 - V_56 ) /
V_62 + 1 ;
if ( V_57 . V_61 > 0 ) {
V_63 [ V_58 ++ ] = V_57 ;
V_64 += V_57 . V_61 ;
}
}
static unsigned long F_14 ( void )
{
unsigned long V_65 ;
int V_4 ;
if ( V_64 == 0 )
return 0 ;
V_65 = F_15 ( L_3 ) % V_64 ;
for ( V_4 = 0 ; V_4 < V_58 ; V_4 ++ ) {
if ( V_65 >= V_63 [ V_4 ] . V_61 ) {
V_65 -= V_63 [ V_4 ] . V_61 ;
continue;
}
return V_63 [ V_4 ] . V_60 + V_65 * V_62 ;
}
if ( V_4 == V_58 )
F_16 ( L_4 ) ;
return 0 ;
}
static void F_17 ( struct V_66 * V_67 ,
unsigned long V_68 ,
unsigned long V_56 )
{
struct V_8 V_55 , V_47 ;
struct V_57 V_57 ;
unsigned long V_69 ;
if ( V_67 -> type != V_70 )
return;
if ( F_18 ( V_71 ) && V_67 -> V_60 >= V_72 )
return;
if ( V_67 -> V_60 + V_67 -> V_3 < V_68 )
return;
V_55 . V_11 = V_67 -> V_60 ;
V_55 . V_3 = V_67 -> V_3 ;
while ( V_58 < V_59 ) {
V_69 = V_55 . V_11 ;
if ( V_55 . V_11 < V_68 )
V_55 . V_11 = V_68 ;
V_55 . V_11 = F_19 ( V_55 . V_11 , V_62 ) ;
if ( V_55 . V_11 > V_67 -> V_60 + V_67 -> V_3 )
return;
V_55 . V_3 -= V_55 . V_11 - V_69 ;
if ( F_18 ( V_71 ) &&
V_55 . V_11 + V_55 . V_3 > V_72 )
V_55 . V_3 = V_72 - V_55 . V_11 ;
if ( V_55 . V_3 < V_56 )
return;
if ( ! F_12 ( & V_55 , & V_47 ) ) {
F_13 ( & V_55 , V_56 ) ;
return;
}
if ( V_47 . V_11 > V_55 . V_11 + V_56 ) {
struct V_8 V_73 ;
V_73 . V_11 = V_55 . V_11 ;
V_73 . V_3 = V_47 . V_11 - V_55 . V_11 ;
F_13 ( & V_73 , V_56 ) ;
}
if ( V_47 . V_11 + V_47 . V_3 >= V_55 . V_11 + V_55 . V_3 )
return;
V_55 . V_3 -= V_47 . V_11 - V_55 . V_11 + V_47 . V_3 ;
V_55 . V_11 = V_47 . V_11 + V_47 . V_3 ;
}
}
static unsigned long F_20 ( unsigned long V_68 ,
unsigned long V_56 )
{
int V_4 ;
unsigned long V_60 ;
if ( V_25 ) {
F_16 ( L_5 ) ;
return 0 ;
}
V_68 = F_19 ( V_68 , V_62 ) ;
for ( V_4 = 0 ; V_4 < V_7 -> V_74 ; V_4 ++ ) {
F_17 ( & V_7 -> V_75 [ V_4 ] , V_68 ,
V_56 ) ;
if ( V_58 == V_59 ) {
F_16 ( L_6 ) ;
break;
}
}
return F_14 () ;
}
static unsigned long F_21 ( unsigned long V_68 ,
unsigned long V_56 )
{
unsigned long V_76 , V_77 ;
V_68 = F_19 ( V_68 , V_62 ) ;
V_56 = F_19 ( V_56 , V_62 ) ;
V_76 = ( V_72 - V_68 - V_56 ) /
V_62 + 1 ;
V_77 = F_15 ( L_7 ) % V_76 ;
return V_77 * V_62 + V_68 ;
}
void F_22 ( unsigned long V_26 ,
unsigned long V_27 ,
unsigned long * V_28 ,
unsigned long V_78 ,
unsigned long * V_79 )
{
unsigned long V_77 , V_80 ;
* V_79 = * V_28 ;
if ( F_23 ( L_8 ) ) {
F_24 ( L_9 ) ;
return;
}
V_7 -> V_30 . V_81 |= V_82 ;
F_25 () ;
F_9 ( V_26 , V_27 , * V_28 ) ;
V_80 = F_26 ( * V_28 , 512UL << 20 ) ;
V_77 = F_20 ( V_80 , V_78 ) ;
if ( ! V_77 ) {
F_24 ( L_10 ) ;
} else {
if ( * V_28 != V_77 ) {
F_10 ( V_77 , V_78 ) ;
* V_28 = V_77 ;
}
}
F_27 () ;
if ( F_18 ( V_83 ) )
V_77 = F_21 ( V_84 , V_78 ) ;
* V_79 = V_77 ;
}
