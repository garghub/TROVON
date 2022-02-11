static int F_1 ( int V_1 , void * V_2 , int V_3 )
{
int V_4 = V_3 ;
while ( V_3 ) {
int V_5 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_5 <= 0 )
return - 1 ;
if ( V_6 ) {
int V_7 = F_3 ( V_8 , V_2 , V_5 ) ;
if ( V_7 <= 0 || V_7 != V_5 )
F_4 ( L_1 ) ;
}
V_3 -= V_5 ;
V_2 += V_5 ;
}
return V_4 ;
}
static int F_5 ( void * V_9 , int V_3 )
{
int V_10 ;
V_10 = F_1 ( V_11 , V_9 , V_3 ) ;
if ( V_10 <= 0 )
F_4 ( L_2 ,
V_3 , V_10 ) ;
if ( V_12 )
V_12 += V_10 ;
return V_10 ;
}
static void F_6 ( int V_3 )
{
char V_2 [ V_13 ] ;
int V_10 ;
while ( V_3 ) {
V_10 = V_3 > V_13 ? V_13 : V_3 ;
F_5 ( V_2 , V_10 ) ;
V_3 -= V_10 ;
} ;
}
static unsigned int F_7 ( void )
{
unsigned int V_9 ;
F_5 ( & V_9 , 4 ) ;
return F_8 ( V_9 ) ;
}
static unsigned long long F_9 ( void )
{
unsigned long long V_9 ;
F_5 ( & V_9 , 8 ) ;
return F_10 ( V_9 ) ;
}
static char * F_11 ( void )
{
char V_2 [ V_13 ] ;
char * V_14 = NULL ;
int V_3 = 0 ;
T_1 V_10 ;
char V_15 ;
for (; ; ) {
V_10 = F_2 ( V_11 , & V_15 , 1 ) ;
if ( V_10 < 0 )
F_4 ( L_3 ) ;
if ( ! V_10 )
F_4 ( L_4 ) ;
if ( V_6 ) {
int V_7 = F_3 ( V_8 , & V_15 , 1 ) ;
if ( V_7 <= 0 || V_7 != V_10 )
F_4 ( L_5 ) ;
}
V_2 [ V_3 ++ ] = V_15 ;
if ( ! V_15 )
break;
}
if ( V_12 )
V_12 += V_3 ;
V_14 = F_12 ( V_3 ) ;
memcpy ( V_14 , V_2 , V_3 ) ;
return V_14 ;
}
static void F_13 ( void )
{
unsigned int V_3 ;
char * V_2 ;
V_3 = F_7 () ;
if ( ! V_3 )
return;
V_2 = F_12 ( V_3 + 1 ) ;
F_5 ( V_2 , V_3 ) ;
V_2 [ V_3 ] = '\0' ;
F_14 ( V_2 , V_3 ) ;
free ( V_2 ) ;
}
static void F_15 ( void )
{
unsigned int V_3 ;
char * V_2 ;
V_3 = F_7 () ;
if ( ! V_3 )
return;
V_2 = F_12 ( V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_16 ( V_2 , V_3 ) ;
free ( V_2 ) ;
}
static void F_17 ( void )
{
unsigned long long V_3 ;
char * V_16 ;
char V_2 [ V_13 ] ;
F_5 ( V_2 , 12 ) ;
if ( memcmp ( V_2 , L_6 , 12 ) != 0 )
F_4 ( L_7 ) ;
V_3 = F_9 () ;
F_6 ( V_3 ) ;
V_17 = V_18 ;
F_5 ( V_2 , 13 ) ;
if ( memcmp ( V_2 , L_8 , 13 ) != 0 )
F_4 ( L_9 ) ;
V_3 = F_9 () ;
V_16 = F_12 ( V_3 ) ;
F_5 ( V_16 , V_3 ) ;
free ( V_16 ) ;
}
static void F_18 ( unsigned long long V_3 )
{
char * V_2 ;
V_2 = F_12 ( V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_19 ( V_2 , V_3 ) ;
free ( V_2 ) ;
}
static void F_20 ( char * V_19 , unsigned long long V_3 )
{
char * V_2 ;
V_2 = F_12 ( V_3 ) ;
F_5 ( V_2 , V_3 ) ;
F_21 ( V_2 , V_3 , V_19 ) ;
free ( V_2 ) ;
}
static void F_22 ( void )
{
unsigned long long V_3 ;
int V_20 ;
int V_21 ;
V_20 = F_7 () ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_3 = F_9 () ;
F_18 ( V_3 ) ;
}
}
static void F_23 ( void )
{
unsigned long long V_3 ;
char * V_19 ;
int V_22 ;
int V_20 ;
int V_21 , V_23 ;
V_22 = F_7 () ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
V_19 = F_11 () ;
V_20 = F_7 () ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
V_3 = F_9 () ;
F_20 ( V_19 , V_3 ) ;
}
}
}
static void F_24 ( int V_24 )
{
V_25 [ V_24 ] . V_26 += V_27 ;
V_25 [ V_24 ] . V_3 -= V_27 ;
V_25 [ V_24 ] . V_28 = 0 ;
}
static void F_25 ( int V_24 )
{
T_1 V_29 ;
T_1 V_5 ;
if ( ! V_25 [ V_24 ] . V_30 )
return;
if ( V_31 ) {
if ( V_25 [ V_24 ] . V_3 <= V_27 ) {
free ( V_25 [ V_24 ] . V_30 ) ;
V_25 [ V_24 ] . V_30 = NULL ;
return;
}
F_24 ( V_24 ) ;
V_29 = F_26 ( V_11 , 0 , V_32 ) ;
V_5 = F_26 ( V_11 , V_25 [ V_24 ] . V_26 , V_33 ) ;
if ( V_5 == ( T_1 ) - 1 )
F_4 ( L_10 ) ;
V_5 = F_2 ( V_11 , V_25 [ V_24 ] . V_30 , V_27 ) ;
if ( V_5 < 0 )
F_4 ( L_11 ) ;
F_26 ( V_11 , V_29 , V_33 ) ;
return;
}
F_27 ( V_25 [ V_24 ] . V_30 , V_27 ) ;
V_25 [ V_24 ] . V_30 = NULL ;
if ( V_25 [ V_24 ] . V_3 <= V_27 )
return;
F_24 ( V_24 ) ;
V_25 [ V_24 ] . V_30 = F_28 ( NULL , V_27 , V_34 , V_35 ,
V_11 , V_25 [ V_24 ] . V_26 ) ;
if ( V_25 [ V_24 ] . V_30 == V_36 )
F_4 ( L_12 ,
V_24 , V_25 [ V_24 ] . V_26 ) ;
}
static unsigned int F_29 ( unsigned int V_37 )
{
if ( V_38 )
return ( V_37 >> 27 ) & ( ( 1 << 5 ) - 1 ) ;
else
return V_37 & ( ( 1 << 5 ) - 1 ) ;
}
static unsigned int F_30 ( unsigned int V_37 )
{
if ( V_38 )
return V_37 & ( ( 1 << 27 ) - 1 ) ;
else
return V_37 >> 5 ;
}
static int F_31 ( void * V_39 , int V_24 )
{
return ( unsigned long ) V_39 - ( unsigned long ) V_25 [ V_24 ] . V_30 ;
}
struct V_40 * F_32 ( int V_24 )
{
struct V_40 * V_9 ;
void * V_30 = V_25 [ V_24 ] . V_30 ;
int V_41 = V_25 [ V_24 ] . V_28 ;
void * V_39 = V_30 + V_41 ;
unsigned long long V_42 ;
unsigned int V_37 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned int V_45 = 0 ;
if ( V_25 [ V_24 ] . V_46 )
return V_25 [ V_24 ] . V_46 ;
if ( ! V_30 )
return NULL ;
if ( ! V_41 ) {
if ( V_47 != 8 )
F_4 ( L_13 ) ;
V_25 [ V_24 ] . V_48 = F_33 ( V_39 ) ;
V_39 += 8 ;
switch ( V_18 ) {
case 4 :
V_25 [ V_24 ] . V_27 = F_34 ( V_39 ) ;
V_39 += 4 ;
break;
case 8 :
V_25 [ V_24 ] . V_27 = F_33 ( V_39 ) ;
V_39 += 8 ;
break;
default:
F_4 ( L_14 ) ;
}
V_39 = V_25 [ V_24 ] . V_30 + V_49 ;
}
V_50:
V_41 = F_31 ( V_39 , V_24 ) ;
if ( V_41 >= V_25 [ V_24 ] . V_27 ) {
F_25 ( V_24 ) ;
return F_32 ( V_24 ) ;
}
V_37 = F_34 ( V_39 ) ;
V_39 += 4 ;
V_43 = F_29 ( V_37 ) ;
V_44 = F_30 ( V_37 ) ;
switch ( V_43 ) {
case V_51 :
if ( ! V_44 )
F_4 ( L_15 ) ;
V_45 = F_34 ( V_39 ) ;
V_39 += 4 ;
V_45 *= 4 ;
V_39 += V_45 ;
goto V_50;
case V_52 :
V_42 = F_34 ( V_39 ) ;
V_39 += 4 ;
V_42 <<= V_53 ;
V_42 += V_44 ;
V_25 [ V_24 ] . V_48 += V_42 ;
goto V_50;
case V_54 :
V_39 += 12 ;
break;
case 0 :
V_45 = F_34 ( V_39 ) ;
V_39 += 4 ;
F_4 ( L_16 , V_45 ) ;
break;
default:
V_45 = V_43 * 4 ;
break;
}
V_25 [ V_24 ] . V_48 += V_44 ;
V_9 = F_12 ( sizeof( * V_9 ) ) ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_55 = V_25 [ V_24 ] . V_48 ;
V_9 -> V_3 = V_45 ;
V_9 -> V_9 = V_39 ;
V_39 += V_45 ;
V_25 [ V_24 ] . V_28 = F_31 ( V_39 , V_24 ) ;
V_25 [ V_24 ] . V_46 = V_9 ;
return V_9 ;
}
struct V_40 * F_35 ( int V_24 )
{
struct V_40 * V_9 ;
V_9 = F_32 ( V_24 ) ;
V_25 [ V_24 ] . V_46 = NULL ;
return V_9 ;
}
T_2 F_36 ( int V_1 , bool V_56 )
{
char V_2 [ V_13 ] ;
char V_57 [] = { 23 , 8 , 68 } ;
char * V_58 ;
int V_59 = 0 ;
int V_60 = 0 ;
int V_61 = 0 ;
T_2 V_3 ;
V_12 = 1 ;
V_6 = V_56 ;
V_11 = V_1 ;
F_5 ( V_2 , 3 ) ;
if ( memcmp ( V_2 , V_57 , 3 ) != 0 )
F_4 ( L_17 ) ;
F_5 ( V_2 , 7 ) ;
if ( memcmp ( V_2 , L_18 , 7 ) != 0 )
F_4 ( L_19 ) ;
V_58 = F_11 () ;
if ( V_59 )
printf ( L_20 , V_58 ) ;
free ( V_58 ) ;
F_5 ( V_2 , 1 ) ;
V_38 = V_2 [ 0 ] ;
V_62 = F_37 () ;
F_5 ( V_2 , 1 ) ;
V_17 = V_2 [ 0 ] ;
V_27 = F_7 () ;
F_17 () ;
F_22 () ;
F_23 () ;
F_13 () ;
F_15 () ;
V_3 = V_12 - 1 ;
V_12 = 0 ;
V_6 = false ;
if ( V_60 ) {
F_38 () ;
return V_3 ;
}
if ( V_61 ) {
F_39 () ;
return V_3 ;
}
return V_3 ;
}
