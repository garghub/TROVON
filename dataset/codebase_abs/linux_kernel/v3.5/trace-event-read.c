static void * F_1 ( int V_1 )
{
void * V_2 ;
V_2 = malloc ( V_1 ) ;
if ( ! V_2 )
F_2 ( L_1 ) ;
return V_2 ;
}
static int F_3 ( int V_3 , void * V_4 , int V_1 )
{
int V_5 = V_1 ;
while ( V_1 ) {
int V_2 = F_4 ( V_3 , V_4 , V_1 ) ;
if ( V_2 <= 0 )
return - 1 ;
if ( V_6 ) {
int V_7 = F_5 ( V_8 , V_4 , V_2 ) ;
if ( V_7 <= 0 || V_7 != V_2 )
F_2 ( L_2 ) ;
}
V_1 -= V_2 ;
V_4 += V_2 ;
}
return V_5 ;
}
static int F_6 ( void * V_9 , int V_1 )
{
int V_10 ;
V_10 = F_3 ( V_11 , V_9 , V_1 ) ;
if ( V_10 <= 0 )
F_2 ( L_3 ,
V_1 , V_10 ) ;
if ( V_12 )
V_12 += V_10 ;
return V_10 ;
}
static void F_7 ( int V_1 )
{
char V_4 [ V_13 ] ;
int V_10 ;
while ( V_1 ) {
V_10 = V_1 > V_13 ? V_13 : V_1 ;
F_6 ( V_4 , V_10 ) ;
V_1 -= V_10 ;
} ;
}
static unsigned int F_8 ( void )
{
unsigned int V_9 ;
F_6 ( & V_9 , 4 ) ;
return F_9 ( V_14 , V_9 ) ;
}
static unsigned long long F_10 ( void )
{
unsigned long long V_9 ;
F_6 ( & V_9 , 8 ) ;
return F_11 ( V_14 , V_9 ) ;
}
static char * F_12 ( void )
{
char V_4 [ V_13 ] ;
char * V_15 = NULL ;
int V_1 = 0 ;
T_1 V_10 ;
char V_16 ;
for (; ; ) {
V_10 = F_4 ( V_11 , & V_16 , 1 ) ;
if ( V_10 < 0 )
F_2 ( L_4 ) ;
if ( ! V_10 )
F_2 ( L_5 ) ;
if ( V_6 ) {
int V_7 = F_5 ( V_8 , & V_16 , 1 ) ;
if ( V_7 <= 0 || V_7 != V_10 )
F_2 ( L_6 ) ;
}
V_4 [ V_1 ++ ] = V_16 ;
if ( ! V_16 )
break;
}
if ( V_12 )
V_12 += V_1 ;
V_15 = F_1 ( V_1 ) ;
memcpy ( V_15 , V_4 , V_1 ) ;
return V_15 ;
}
static void F_13 ( void )
{
unsigned int V_1 ;
char * V_4 ;
V_1 = F_8 () ;
if ( ! V_1 )
return;
V_4 = F_1 ( V_1 + 1 ) ;
F_6 ( V_4 , V_1 ) ;
V_4 [ V_1 ] = '\0' ;
F_14 ( V_4 , V_1 ) ;
free ( V_4 ) ;
}
static void F_15 ( void )
{
unsigned int V_1 ;
char * V_4 ;
V_1 = F_8 () ;
if ( ! V_1 )
return;
V_4 = F_1 ( V_1 ) ;
F_6 ( V_4 , V_1 ) ;
F_16 ( V_4 , V_1 ) ;
free ( V_4 ) ;
}
static void F_17 ( void )
{
unsigned long long V_1 ;
char * V_17 ;
char V_4 [ V_13 ] ;
F_6 ( V_4 , 12 ) ;
if ( memcmp ( V_4 , L_7 , 12 ) != 0 )
F_2 ( L_8 ) ;
V_1 = F_10 () ;
F_7 ( V_1 ) ;
V_18 = V_19 ;
F_6 ( V_4 , 13 ) ;
if ( memcmp ( V_4 , L_9 , 13 ) != 0 )
F_2 ( L_10 ) ;
V_1 = F_10 () ;
V_17 = F_1 ( V_1 ) ;
F_6 ( V_17 , V_1 ) ;
free ( V_17 ) ;
}
static void F_18 ( unsigned long long V_1 )
{
char * V_4 ;
V_4 = F_1 ( V_1 ) ;
F_6 ( V_4 , V_1 ) ;
F_19 ( V_4 , V_1 ) ;
free ( V_4 ) ;
}
static void F_20 ( char * V_20 , unsigned long long V_1 )
{
char * V_4 ;
V_4 = F_1 ( V_1 ) ;
F_6 ( V_4 , V_1 ) ;
F_21 ( V_4 , V_1 , V_20 ) ;
free ( V_4 ) ;
}
static void F_22 ( void )
{
unsigned long long V_1 ;
int V_21 ;
int V_22 ;
V_21 = F_8 () ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
V_1 = F_10 () ;
F_18 ( V_1 ) ;
}
}
static void F_23 ( void )
{
unsigned long long V_1 ;
char * V_20 ;
int V_23 ;
int V_21 ;
int V_22 , V_24 ;
V_23 = F_8 () ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_20 = F_12 () ;
V_21 = F_8 () ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ ) {
V_1 = F_10 () ;
F_20 ( V_20 , V_1 ) ;
}
}
}
static void F_24 ( int V_25 )
{
V_26 [ V_25 ] . V_27 += V_28 ;
V_26 [ V_25 ] . V_1 -= V_28 ;
V_26 [ V_25 ] . V_29 = 0 ;
}
static void F_25 ( int V_25 )
{
T_1 V_30 ;
T_1 V_2 ;
if ( ! V_26 [ V_25 ] . V_31 )
return;
if ( V_32 ) {
if ( V_26 [ V_25 ] . V_1 <= V_28 ) {
free ( V_26 [ V_25 ] . V_31 ) ;
V_26 [ V_25 ] . V_31 = NULL ;
return;
}
F_24 ( V_25 ) ;
V_30 = F_26 ( V_11 , 0 , V_33 ) ;
V_2 = F_26 ( V_11 , V_26 [ V_25 ] . V_27 , V_34 ) ;
if ( V_2 == ( T_1 ) - 1 )
F_2 ( L_11 ) ;
V_2 = F_4 ( V_11 , V_26 [ V_25 ] . V_31 , V_28 ) ;
if ( V_2 < 0 )
F_2 ( L_12 ) ;
F_26 ( V_11 , V_30 , V_34 ) ;
return;
}
F_27 ( V_26 [ V_25 ] . V_31 , V_28 ) ;
V_26 [ V_25 ] . V_31 = NULL ;
if ( V_26 [ V_25 ] . V_1 <= V_28 )
return;
F_24 ( V_25 ) ;
V_26 [ V_25 ] . V_31 = F_28 ( NULL , V_28 , V_35 , V_36 ,
V_11 , V_26 [ V_25 ] . V_27 ) ;
if ( V_26 [ V_25 ] . V_31 == V_37 )
F_2 ( L_13 ,
V_25 , V_26 [ V_25 ] . V_27 ) ;
}
static unsigned int F_29 ( unsigned int V_38 )
{
if ( V_39 )
return ( V_38 >> 27 ) & ( ( 1 << 5 ) - 1 ) ;
else
return V_38 & ( ( 1 << 5 ) - 1 ) ;
}
static unsigned int F_30 ( unsigned int V_38 )
{
if ( V_39 )
return V_38 & ( ( 1 << 27 ) - 1 ) ;
else
return V_38 >> 5 ;
}
static int F_31 ( void * V_40 , int V_25 )
{
return ( unsigned long ) V_40 - ( unsigned long ) V_26 [ V_25 ] . V_31 ;
}
struct V_41 * F_32 ( int V_25 )
{
struct V_41 * V_9 ;
void * V_31 = V_26 [ V_25 ] . V_31 ;
int V_42 = V_26 [ V_25 ] . V_29 ;
void * V_40 = V_31 + V_42 ;
unsigned long long V_43 ;
unsigned int V_38 ;
unsigned int V_44 ;
unsigned int V_45 ;
unsigned int V_46 = 0 ;
if ( V_26 [ V_25 ] . V_47 )
return V_26 [ V_25 ] . V_47 ;
if ( ! V_31 )
return NULL ;
if ( ! V_42 ) {
if ( V_48 != 8 )
F_2 ( L_14 ) ;
V_26 [ V_25 ] . V_49 = F_33 ( V_14 , V_40 ) ;
V_40 += 8 ;
switch ( V_19 ) {
case 4 :
V_26 [ V_25 ] . V_28 = F_34 ( V_14 , V_40 ) ;
V_40 += 4 ;
break;
case 8 :
V_26 [ V_25 ] . V_28 = F_33 ( V_14 , V_40 ) ;
V_40 += 8 ;
break;
default:
F_2 ( L_15 ) ;
}
V_40 = V_26 [ V_25 ] . V_31 + V_50 ;
}
V_51:
V_42 = F_31 ( V_40 , V_25 ) ;
if ( V_42 >= V_26 [ V_25 ] . V_28 ) {
F_25 ( V_25 ) ;
return F_32 ( V_25 ) ;
}
V_38 = F_34 ( V_14 , V_40 ) ;
V_40 += 4 ;
V_44 = F_29 ( V_38 ) ;
V_45 = F_30 ( V_38 ) ;
switch ( V_44 ) {
case V_52 :
if ( ! V_45 )
F_2 ( L_16 ) ;
V_46 = F_34 ( V_14 , V_40 ) ;
V_40 += 4 ;
V_46 *= 4 ;
V_40 += V_46 ;
goto V_51;
case V_53 :
V_43 = F_34 ( V_14 , V_40 ) ;
V_40 += 4 ;
V_43 <<= V_54 ;
V_43 += V_45 ;
V_26 [ V_25 ] . V_49 += V_43 ;
goto V_51;
case V_55 :
V_40 += 12 ;
break;
case 0 :
V_46 = F_34 ( V_14 , V_40 ) ;
V_40 += 4 ;
F_2 ( L_17 , V_46 ) ;
break;
default:
V_46 = V_44 * 4 ;
break;
}
V_26 [ V_25 ] . V_49 += V_45 ;
V_9 = F_1 ( sizeof( * V_9 ) ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_56 = V_26 [ V_25 ] . V_49 ;
V_9 -> V_1 = V_46 ;
V_9 -> V_9 = V_40 ;
V_40 += V_46 ;
V_26 [ V_25 ] . V_29 = F_31 ( V_40 , V_25 ) ;
V_26 [ V_25 ] . V_47 = V_9 ;
return V_9 ;
}
struct V_41 * F_35 ( int V_25 )
{
struct V_41 * V_9 ;
V_9 = F_32 ( V_25 ) ;
V_26 [ V_25 ] . V_47 = NULL ;
return V_9 ;
}
T_2 F_36 ( int V_3 , bool V_57 )
{
char V_4 [ V_13 ] ;
char V_58 [] = { 23 , 8 , 68 } ;
char * V_59 ;
int V_60 = 0 ;
int V_61 = 0 ;
int V_62 = 0 ;
T_2 V_1 ;
V_12 = 1 ;
V_6 = V_57 ;
V_11 = V_3 ;
F_6 ( V_4 , 3 ) ;
if ( memcmp ( V_4 , V_58 , 3 ) != 0 )
F_2 ( L_18 ) ;
F_6 ( V_4 , 7 ) ;
if ( memcmp ( V_4 , L_19 , 7 ) != 0 )
F_2 ( L_20 ) ;
V_59 = F_12 () ;
if ( V_60 )
printf ( L_21 , V_59 ) ;
free ( V_59 ) ;
F_6 ( V_4 , 1 ) ;
V_39 = V_4 [ 0 ] ;
V_63 = F_37 () ;
F_38 ( V_39 , V_63 ) ;
F_6 ( V_4 , 1 ) ;
V_18 = V_4 [ 0 ] ;
V_28 = F_8 () ;
F_17 () ;
F_22 () ;
F_23 () ;
F_13 () ;
F_15 () ;
V_1 = V_12 - 1 ;
V_12 = 0 ;
V_6 = false ;
if ( V_61 ) {
F_39 ( V_14 ) ;
return V_1 ;
}
if ( V_62 ) {
F_40 ( V_14 ) ;
return V_1 ;
}
return V_1 ;
}
