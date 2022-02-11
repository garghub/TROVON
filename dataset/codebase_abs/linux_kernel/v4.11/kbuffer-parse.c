static void * F_1 ( T_1 V_1 )
{
return calloc ( 1 , V_1 ) ;
}
static int F_2 ( void )
{
unsigned char V_2 [] = { 0x1 , 0x2 , 0x3 , 0x4 } ;
unsigned int * V_3 ;
V_3 = ( unsigned int * ) V_2 ;
return * V_3 == 0x01020304 ;
}
static int F_3 ( struct V_4 * V_5 )
{
return ( ( V_5 -> V_6 & V_7 ) + V_5 -> V_6 ) &
V_8 ;
}
static unsigned long long F_4 ( void * V_3 )
{
unsigned long long V_9 = * ( unsigned long long * ) V_3 ;
return V_9 ;
}
static unsigned long long F_5 ( void * V_3 )
{
unsigned long long V_9 = * ( unsigned long long * ) V_3 ;
unsigned long long V_10 ;
V_10 = ( ( V_9 & 0xffULL ) << 56 ) |
( ( V_9 & ( 0xffULL << 8 ) ) << 40 ) |
( ( V_9 & ( 0xffULL << 16 ) ) << 24 ) |
( ( V_9 & ( 0xffULL << 24 ) ) << 8 ) |
( ( V_9 & ( 0xffULL << 32 ) ) >> 8 ) |
( ( V_9 & ( 0xffULL << 40 ) ) >> 24 ) |
( ( V_9 & ( 0xffULL << 48 ) ) >> 40 ) |
( ( V_9 & ( 0xffULL << 56 ) ) >> 56 ) ;
return V_10 ;
}
static unsigned int F_6 ( void * V_3 )
{
unsigned int V_9 = * ( unsigned int * ) V_3 ;
return V_9 ;
}
static unsigned int F_7 ( void * V_3 )
{
unsigned int V_9 = * ( unsigned int * ) V_3 ;
unsigned int V_10 ;
V_10 = ( ( V_9 & 0xffULL ) << 24 ) |
( ( V_9 & ( 0xffULL << 8 ) ) << 8 ) |
( ( V_9 & ( 0xffULL << 16 ) ) >> 8 ) |
( ( V_9 & ( 0xffULL << 24 ) ) >> 24 ) ;
return V_10 ;
}
static unsigned long long F_8 ( struct V_4 * V_5 , void * V_3 )
{
return V_5 -> F_8 ( V_3 ) ;
}
static unsigned int F_9 ( struct V_4 * V_5 , void * V_3 )
{
return V_5 -> F_9 ( V_3 ) ;
}
static unsigned long long F_10 ( struct V_4 * V_5 , void * V_3 )
{
return V_5 -> F_8 ( V_3 ) ;
}
static unsigned long long F_11 ( struct V_4 * V_5 , void * V_3 )
{
return V_5 -> F_9 ( V_3 ) ;
}
static unsigned long long F_12 ( struct V_4 * V_5 , void * V_3 )
{
return V_5 -> F_12 ( V_5 , V_3 ) ;
}
static int F_13 ( struct V_4 * V_5 , void * V_3 )
{
return ( unsigned long ) V_3 - ( unsigned long ) V_5 -> V_9 ;
}
struct V_4 *
F_14 ( enum V_11 V_1 , enum V_12 V_13 )
{
struct V_4 * V_5 ;
int V_6 = 0 ;
switch ( V_1 ) {
case V_14 :
break;
case V_15 :
V_6 |= V_16 ;
break;
default:
return NULL ;
}
switch ( V_13 ) {
case V_17 :
break;
case V_18 :
V_6 |= V_19 ;
break;
default:
return NULL ;
}
V_5 = F_1 ( sizeof( * V_5 ) ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_6 = V_6 ;
if ( F_2 () )
V_5 -> V_6 |= V_7 ;
if ( F_3 ( V_5 ) ) {
V_5 -> F_8 = F_5 ;
V_5 -> F_9 = F_7 ;
} else {
V_5 -> F_8 = F_4 ;
V_5 -> F_9 = F_6 ;
}
if ( V_5 -> V_6 & V_16 )
V_5 -> F_12 = F_10 ;
else
V_5 -> F_12 = F_11 ;
V_5 -> V_20 = V_21 ;
return V_5 ;
}
void F_15 ( struct V_4 * V_5 )
{
free ( V_5 ) ;
}
static unsigned int F_16 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
if ( V_5 -> V_6 & V_19 )
return ( V_22 >> 29 ) & 3 ;
else
return V_22 & 3 ;
}
static unsigned int F_17 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
if ( V_5 -> V_6 & V_19 )
return ( V_22 >> 27 ) & 7 ;
else
return ( V_22 >> 2 ) & 7 ;
}
static unsigned int F_18 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
if ( V_5 -> V_6 & V_19 )
return ( V_22 >> 27 ) & ( ( 1 << 5 ) - 1 ) ;
else
return V_22 & ( ( 1 << 5 ) - 1 ) ;
}
static unsigned int F_19 ( struct V_4 * V_5 ,
unsigned int V_22 )
{
if ( V_5 -> V_6 & V_19 )
return V_22 & ( ( 1 << 27 ) - 1 ) ;
else
return V_22 >> 5 ;
}
static unsigned int F_20 ( struct V_4 * V_5 )
{
unsigned long long V_23 ;
unsigned int V_22 ;
unsigned int type ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
void * V_3 = V_5 -> V_9 + V_5 -> V_27 ;
V_22 = F_9 ( V_5 , V_3 ) ;
V_3 += 4 ;
type = F_16 ( V_5 , V_22 ) ;
V_24 = F_17 ( V_5 , V_22 ) ;
V_25 = F_19 ( V_5 , V_22 ) ;
switch ( type ) {
case V_28 :
V_5 -> V_29 = V_5 -> V_1 ;
return 0 ;
case V_30 :
V_23 = F_9 ( V_5 , V_3 ) ;
V_23 <<= V_31 ;
V_23 += V_25 ;
V_25 = V_23 ;
V_3 += 4 ;
V_26 = 0 ;
break;
case V_32 :
V_5 -> V_27 = V_5 -> V_1 ;
V_5 -> V_29 = V_5 -> V_1 ;
V_5 -> V_33 = V_5 -> V_1 ;
return - 1 ;
default:
if ( V_24 )
V_26 = V_24 * 4 ;
else {
V_26 = F_9 ( V_5 , V_3 ) ;
V_26 -= 4 ;
V_3 += 4 ;
}
break;
}
V_5 -> V_34 += V_25 ;
V_5 -> V_33 = F_13 ( V_5 , V_3 ) ;
V_5 -> V_29 = V_5 -> V_33 + V_26 ;
return type ;
}
static int F_21 ( struct V_4 * V_5 )
{
int type ;
do {
V_5 -> V_27 = V_5 -> V_29 ;
if ( V_5 -> V_29 >= V_5 -> V_1 )
return - 1 ;
type = F_20 ( V_5 ) ;
} while ( type == V_30 || type == V_28 );
return 0 ;
}
static unsigned int
F_22 ( struct V_4 * V_5 , void * V_9 , void * * V_35 ,
unsigned long long * V_25 , int * V_26 )
{
unsigned long long V_23 ;
unsigned int V_22 ;
unsigned int V_36 ;
V_22 = F_9 ( V_5 , V_9 ) ;
V_9 += 4 ;
V_36 = F_18 ( V_5 , V_22 ) ;
* V_25 = F_19 ( V_5 , V_22 ) ;
switch ( V_36 ) {
case V_37 :
* V_26 = F_9 ( V_5 , V_9 ) ;
break;
case V_38 :
V_23 = F_9 ( V_5 , V_9 ) ;
V_9 += 4 ;
V_23 <<= V_31 ;
V_23 += * V_25 ;
* V_25 = V_23 ;
* V_26 = 0 ;
break;
case V_39 :
V_9 += 12 ;
* V_26 = 0 ;
break;
case 0 :
* V_26 = F_9 ( V_5 , V_9 ) - 4 ;
* V_26 = ( * V_26 + 3 ) & ~ 3 ;
V_9 += 4 ;
break;
default:
* V_26 = V_36 * 4 ;
break;
}
* V_35 = V_9 ;
return V_36 ;
}
static unsigned int F_23 ( struct V_4 * V_5 )
{
unsigned long long V_25 ;
unsigned int V_36 ;
int V_26 ;
void * V_3 = V_5 -> V_9 + V_5 -> V_27 ;
V_36 = F_22 ( V_5 , V_3 , & V_3 , & V_25 , & V_26 ) ;
V_5 -> V_34 += V_25 ;
V_5 -> V_33 = F_13 ( V_5 , V_3 ) ;
V_5 -> V_29 = V_5 -> V_33 + V_26 ;
return V_36 ;
}
void * F_24 ( int V_10 , void * V_9 , unsigned int * V_1 )
{
unsigned long long V_25 ;
struct V_4 V_5 ;
int V_36 ;
int V_26 ;
void * V_3 ;
if ( V_10 ) {
V_5 . F_8 = F_5 ;
V_5 . F_9 = F_7 ;
V_5 . V_6 = F_2 () ? 0 : V_19 ;
} else {
V_5 . F_8 = F_4 ;
V_5 . F_9 = F_6 ;
V_5 . V_6 = F_2 () ? V_19 : 0 ;
}
V_36 = F_22 ( & V_5 , V_9 , & V_3 , & V_25 , & V_26 ) ;
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
return NULL ;
} ;
* V_1 = V_26 ;
return V_3 ;
}
static int V_21 ( struct V_4 * V_5 )
{
int type ;
do {
V_5 -> V_27 = V_5 -> V_29 ;
if ( V_5 -> V_29 >= V_5 -> V_1 )
return - 1 ;
type = F_23 ( V_5 ) ;
} while ( type == V_38 || type == V_37 );
return 0 ;
}
static int V_20 ( struct V_4 * V_5 )
{
return V_5 -> V_20 ( V_5 ) ;
}
void * F_25 ( struct V_4 * V_5 , unsigned long long * V_40 )
{
int V_41 ;
if ( ! V_5 || ! V_5 -> V_42 )
return NULL ;
V_41 = V_20 ( V_5 ) ;
if ( V_41 < 0 )
return NULL ;
if ( V_40 )
* V_40 = V_5 -> V_34 ;
return V_5 -> V_9 + V_5 -> V_33 ;
}
int F_26 ( struct V_4 * V_5 , void * V_42 )
{
unsigned long long V_6 ;
void * V_3 = V_42 ;
if ( ! V_5 || ! V_42 )
return - 1 ;
V_5 -> V_42 = V_42 ;
V_5 -> V_34 = F_8 ( V_5 , V_3 ) ;
V_3 += 8 ;
V_5 -> V_27 = 0 ;
if ( V_5 -> V_6 & V_16 )
V_5 -> V_43 = 16 ;
else
V_5 -> V_43 = 12 ;
V_5 -> V_9 = V_42 + V_5 -> V_43 ;
V_6 = F_12 ( V_5 , V_3 ) ;
V_5 -> V_1 = ( unsigned int ) V_6 & V_44 ;
if ( V_6 & V_45 ) {
if ( V_6 & V_46 ) {
V_3 = V_5 -> V_9 + V_5 -> V_1 ;
V_5 -> V_47 = F_12 ( V_5 , V_3 ) ;
} else
V_5 -> V_47 = - 1 ;
} else
V_5 -> V_47 = 0 ;
V_5 -> V_33 = 0 ;
V_5 -> V_29 = 0 ;
V_20 ( V_5 ) ;
return 0 ;
}
void * F_27 ( struct V_4 * V_5 , unsigned long long * V_40 )
{
if ( ! V_5 || ! V_5 -> V_42 )
return NULL ;
if ( V_5 -> V_27 >= V_5 -> V_1 )
return NULL ;
if ( V_40 )
* V_40 = V_5 -> V_34 ;
return V_5 -> V_9 + V_5 -> V_33 ;
}
unsigned long long F_28 ( struct V_4 * V_5 )
{
return V_5 -> V_34 ;
}
void * F_29 ( struct V_4 * V_5 , int V_48 ,
unsigned long long * V_40 )
{
void * V_9 ;
if ( V_48 < V_5 -> V_43 )
V_48 = 0 ;
else
V_48 -= V_5 -> V_43 ;
F_26 ( V_5 , V_5 -> V_42 ) ;
V_9 = F_27 ( V_5 , V_40 ) ;
while ( V_5 -> V_27 < V_48 ) {
V_9 = F_25 ( V_5 , V_40 ) ;
if ( ! V_9 )
break;
}
return V_9 ;
}
int F_30 ( struct V_4 * V_5 )
{
return V_5 -> V_1 ;
}
int F_31 ( struct V_4 * V_5 )
{
return V_5 -> V_27 ;
}
int F_32 ( struct V_4 * V_5 )
{
return V_5 -> V_27 + V_5 -> V_43 ;
}
int F_33 ( struct V_4 * V_5 )
{
return V_5 -> V_29 - V_5 -> V_33 ;
}
int F_34 ( struct V_4 * V_5 )
{
return V_5 -> V_29 - V_5 -> V_27 ;
}
int F_35 ( struct V_4 * V_5 )
{
if ( V_5 -> V_27 )
return 0 ;
return V_5 -> V_47 ;
}
void F_36 ( struct V_4 * V_5 )
{
V_5 -> V_6 |= V_49 ;
V_5 -> V_20 = F_21 ;
}
int F_37 ( struct V_4 * V_5 )
{
return V_5 -> V_43 ;
}
