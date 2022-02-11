static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned char * V_4 ;
V_4 = ( unsigned char * ) ( V_2 -> V_5 . V_6 ) ;
V_4 += V_3 ;
return ( * ( ( int * ) V_4 ) ) ;
}
static inline unsigned long
F_2 ( struct V_1 * V_2 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) ( ( unsigned char * ) V_2 + V_11 ) - 1 ;
if ( ! F_3 ( V_2 ) ) {
if ( V_7 == F_4 ( struct V_12 , V_13 ) ) {
V_8 = V_14 ;
} else {
V_8 = 0xffffffffUL ;
}
return V_8 ;
}
if ( V_15 == V_2 ) {
F_5 () ;
F_6 ( V_2 ) ;
F_7 () ;
V_15 = 0 ;
V_10 -> V_16 |= V_17 ;
}
V_8 = ( ( long * ) V_2 -> V_5 . V_18 ) [ V_7 / sizeof( unsigned long )];
return V_8 ;
}
static inline int F_8 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_19 )
{
unsigned char * V_4 ;
V_4 = ( unsigned char * ) ( V_2 -> V_5 . V_6 ) ;
V_4 += V_3 ;
* ( unsigned long * ) V_4 = V_19 ;
return 0 ;
}
static inline int
F_9 ( struct V_1 * V_2 , unsigned long V_7 , unsigned long V_19 )
{
struct V_9 * V_10 ;
V_10 = (struct V_9 * ) ( ( unsigned char * ) V_2 + V_11 ) - 1 ;
if ( ! F_3 ( V_2 ) ) {
F_10 ( V_2 ) ;
} else if ( V_15 == V_2 ) {
F_5 () ;
F_6 ( V_2 ) ;
F_7 () ;
V_15 = 0 ;
V_10 -> V_16 |= V_17 ;
}
( ( long * ) V_2 -> V_5 . V_18 ) [ V_7 / sizeof( unsigned long )] = V_19 ;
return 0 ;
}
void F_11 ( struct V_1 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_5 . V_6 ;
V_10 -> V_16 |= V_21 ;
F_12 ( V_20 , V_22 ) ;
}
void F_13 ( struct V_1 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_5 . V_6 ;
V_10 -> V_16 &= ~ V_21 ;
F_14 ( V_20 , V_22 ) ;
}
static int F_15 ( struct V_1 * V_23 ,
const struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 ,
void * V_28 , void T_1 * V_29 )
{
const struct V_9 * V_10 = F_16 ( V_23 ) ;
int V_30 ;
V_30 = F_17 ( & V_26 , & V_27 , & V_28 , & V_29 ,
& V_10 -> V_31 ,
0 , 3 * sizeof( unsigned long long ) ) ;
if ( ! V_30 )
V_30 = F_17 ( & V_26 , & V_27 , & V_28 , & V_29 ,
V_10 -> V_10 ,
F_4 ( struct V_9 , V_10 [ 0 ] ) ,
63 * sizeof( unsigned long long ) ) ;
if ( ! V_30 )
V_30 = F_17 ( & V_26 , & V_27 , & V_28 , & V_29 ,
V_10 -> V_32 ,
F_4 ( struct V_9 , V_32 [ 0 ] ) ,
8 * sizeof( unsigned long long ) ) ;
if ( ! V_30 )
V_30 = F_18 ( & V_26 , & V_27 , & V_28 , & V_29 ,
sizeof( struct V_9 ) , - 1 ) ;
return V_30 ;
}
static int F_19 ( struct V_1 * V_23 ,
const struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 ,
const void * V_28 , const void T_1 * V_29 )
{
struct V_9 * V_10 = F_16 ( V_23 ) ;
int V_30 ;
V_30 = F_20 ( & V_26 , & V_27 , & V_28 , & V_29 ,
& V_10 -> V_31 ,
0 , 3 * sizeof( unsigned long long ) ) ;
if ( ! V_30 && V_27 > 0 )
V_30 = F_20 ( & V_26 , & V_27 , & V_28 , & V_29 ,
V_10 -> V_10 ,
F_4 ( struct V_9 , V_10 [ 0 ] ) ,
63 * sizeof( unsigned long long ) ) ;
if ( ! V_30 && V_27 > 0 )
V_30 = F_20 ( & V_26 , & V_27 , & V_28 , & V_29 ,
V_10 -> V_32 ,
F_4 ( struct V_9 , V_32 [ 0 ] ) ,
8 * sizeof( unsigned long long ) ) ;
if ( ! V_30 )
V_30 = F_21 ( & V_26 , & V_27 , & V_28 , & V_29 ,
sizeof( struct V_9 ) , - 1 ) ;
return V_30 ;
}
int F_22 ( struct V_1 * V_23 ,
const struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 ,
void * V_28 , void T_1 * V_29 )
{
int V_30 ;
V_30 = F_10 ( V_23 ) ;
if ( V_30 )
return V_30 ;
return F_17 ( & V_26 , & V_27 , & V_28 , & V_29 ,
& V_23 -> V_5 . V_18 -> V_33 , 0 , - 1 ) ;
}
static int F_23 ( struct V_1 * V_23 ,
const struct V_24 * V_25 ,
unsigned int V_26 , unsigned int V_27 ,
const void * V_28 , const void T_1 * V_29 )
{
int V_30 ;
V_30 = F_10 ( V_23 ) ;
if ( V_30 )
return V_30 ;
F_24 ( V_23 ) ;
return F_20 ( & V_26 , & V_27 , & V_28 , & V_29 ,
& V_23 -> V_5 . V_18 -> V_33 , 0 , - 1 ) ;
}
static int F_25 ( struct V_1 * V_23 ,
const struct V_24 * V_25 )
{
return F_3 ( V_23 ) ? V_25 -> V_34 : 0 ;
}
const struct V_35 * F_26 ( struct V_1 * V_2 )
{
return & V_36 ;
}
long F_27 ( struct V_1 * V_20 , long V_37 ,
unsigned long V_7 , unsigned long V_19 )
{
int V_30 ;
unsigned long T_1 * V_38 = ( unsigned long T_1 * ) V_19 ;
switch ( V_37 ) {
case V_39 : {
unsigned long V_8 ;
V_30 = - V_40 ;
if ( ( V_7 & 3 ) || V_7 < 0 )
break;
if ( V_7 < sizeof( struct V_9 ) )
V_8 = F_1 ( V_20 , V_7 ) ;
else if ( ( V_7 >= F_4 ( struct V_41 , V_42 ) ) &&
( V_7 < F_4 ( struct V_41 , V_43 ) ) ) {
unsigned long V_44 ;
V_30 = F_10 ( V_20 ) ;
if ( V_30 )
break;
V_44 = V_7 - F_4 ( struct V_41 , V_42 ) ;
V_8 = F_2 ( V_20 , V_44 ) ;
} else if ( V_7 == F_4 ( struct V_41 , V_43 ) ) {
V_8 = ! ! F_3 ( V_20 ) ;
} else {
break;
}
V_30 = F_28 ( V_8 , V_38 ) ;
break;
}
case V_45 :
V_30 = - V_40 ;
if ( ( V_7 & 3 ) || V_7 < 0 )
break;
if ( V_7 < sizeof( struct V_9 ) ) {
if ( V_7 == F_4 ( struct V_9 , V_16 ) + 4 )
{
V_30 = 0 ;
break;
}
if ( V_7 == F_4 ( struct V_9 , V_16 ) )
{
long V_46 = F_1 ( V_20 , V_7 ) ;
V_19 &= ~ ( V_47 ) ;
V_19 |= ( V_46 & V_47 ) ;
}
V_30 = F_8 ( V_20 , V_7 , V_19 ) ;
}
else if ( ( V_7 >= F_4 ( struct V_41 , V_42 ) ) &&
( V_7 < F_4 ( struct V_41 , V_43 ) ) ) {
unsigned long V_44 ;
V_30 = F_10 ( V_20 ) ;
if ( V_30 )
break;
V_44 = V_7 - F_4 ( struct V_41 , V_42 ) ;
V_30 = F_9 ( V_20 , V_44 , V_19 ) ;
}
break;
case V_48 :
return F_29 ( V_20 , & V_36 ,
V_49 ,
0 , sizeof( struct V_9 ) ,
V_38 ) ;
case V_50 :
return F_30 ( V_20 , & V_36 ,
V_49 ,
0 , sizeof( struct V_9 ) ,
V_38 ) ;
#ifdef F_31
case V_51 :
return F_29 ( V_20 , & V_36 ,
V_52 ,
0 , sizeof( struct V_12 ) ,
V_38 ) ;
case V_53 :
return F_30 ( V_20 , & V_36 ,
V_52 ,
0 , sizeof( struct V_12 ) ,
V_38 ) ;
#endif
default:
V_30 = F_32 ( V_20 , V_37 , V_7 , V_19 ) ;
break;
}
return V_30 ;
}
T_2 int F_33 ( long V_37 , long V_54 ,
unsigned long V_7 , unsigned long V_19 )
{
#define F_34 0x0d104008
static unsigned long V_55 ;
if ( ! F_35 ( 0 , & V_55 ) ) {
F_36 ( L_1 ) ;
F_37 ( F_34 , 0 ) ;
}
return F_38 ( V_37 , V_54 , V_7 , V_19 ) ;
}
T_2 long long F_39 ( struct V_9 * V_10 )
{
long long V_30 = 0 ;
F_40 ( V_10 -> V_10 [ 9 ] ) ;
if ( F_41 ( V_56 ) &&
F_42 ( V_10 ) )
V_30 = - 1LL ;
if ( F_43 ( F_41 ( V_57 ) ) )
F_44 ( V_10 , V_10 -> V_10 [ 9 ] ) ;
F_45 ( V_10 -> V_10 [ 1 ] , V_10 -> V_10 [ 2 ] , V_10 -> V_10 [ 3 ] ,
V_10 -> V_10 [ 4 ] , V_10 -> V_10 [ 5 ] ) ;
return V_30 ? : V_10 -> V_10 [ 9 ] ;
}
T_2 void F_46 ( struct V_9 * V_10 )
{
int V_58 ;
F_47 ( V_10 ) ;
if ( F_43 ( F_41 ( V_57 ) ) )
F_48 ( V_10 , V_10 -> V_10 [ 9 ] ) ;
V_58 = F_41 ( V_22 ) ;
if ( V_58 || F_41 ( V_56 ) )
F_49 ( V_10 , V_58 ) ;
}
T_2 void F_50 ( unsigned long long V_59 , struct V_9 * V_10 )
{
F_51 () ;
V_10 -> V_16 &= ~ V_21 ;
F_52 ( V_60 , V_61 ) ;
}
void F_53 ( struct V_1 * V_20 )
{
F_13 ( V_20 ) ;
}
