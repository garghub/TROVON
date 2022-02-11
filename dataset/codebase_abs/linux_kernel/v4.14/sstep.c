static T_1 unsigned long F_1 ( unsigned long V_1 ,
unsigned long V_2 )
{
#ifdef F_2
if ( ( V_1 & V_3 ) == 0 )
V_2 &= 0xffffffffUL ;
#endif
return V_2 ;
}
static T_1 int F_3 ( unsigned int V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
unsigned int V_9 = ( V_4 >> 21 ) & 0x1f ;
unsigned int V_10 ;
if ( ( V_9 & 4 ) == 0 ) {
V_8 -> type |= V_11 ;
if ( ( ( V_9 >> 1 ) & 1 ) ^ ( V_6 -> V_12 == 1 ) )
return 0 ;
}
if ( ( V_9 & 0x10 ) == 0 ) {
V_10 = ( V_4 >> 16 ) & 0x1f ;
if ( ( ( V_6 -> V_13 >> ( 31 - V_10 ) ) & 1 ) != ( ( V_9 >> 3 ) & 1 ) )
return 0 ;
}
return 1 ;
}
static T_1 long F_4 ( struct V_5 * V_6 ,
unsigned long V_14 , int V_15 )
{
if ( ! F_5 ( V_6 ) )
return 1 ;
if ( F_6 ( V_14 , V_15 , V_16 ) )
return 1 ;
if ( F_6 ( V_14 , 1 , V_16 ) )
V_6 -> V_17 = V_16 . V_18 ;
else
V_6 -> V_17 = V_14 ;
return 0 ;
}
static T_1 unsigned long F_7 ( unsigned int V_4 ,
const struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_14 ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_14 = ( signed short ) V_4 ;
if ( V_19 )
V_14 += V_6 -> V_20 [ V_19 ] ;
return V_14 ;
}
static T_1 unsigned long F_8 ( unsigned int V_4 ,
const struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_14 ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_14 = ( signed short ) ( V_4 & ~ 3 ) ;
if ( V_19 )
V_14 += V_6 -> V_20 [ V_19 ] ;
return V_14 ;
}
static T_1 unsigned long F_9 ( unsigned int V_4 ,
const struct V_5 * V_6 )
{
int V_19 ;
unsigned long V_14 ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_14 = ( signed short ) ( V_4 & ~ 0xf ) ;
if ( V_19 )
V_14 += V_6 -> V_20 [ V_19 ] ;
return V_14 ;
}
static T_1 unsigned long F_10 ( unsigned int V_4 ,
const struct V_5 * V_6 )
{
int V_19 , V_21 ;
unsigned long V_14 ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_21 = ( V_4 >> 11 ) & 0x1f ;
V_14 = V_6 -> V_20 [ V_21 ] ;
if ( V_19 )
V_14 += V_6 -> V_20 [ V_19 ] ;
return V_14 ;
}
static T_1 unsigned long F_11 ( unsigned long V_22 )
{
V_22 |= sizeof( unsigned long ) ;
return V_22 & - V_22 ;
}
static T_1 unsigned long F_12 ( unsigned long V_22 )
{
return ( ( V_22 >> 8 ) & 0xff ) | ( ( V_22 & 0xff ) << 8 ) ;
}
static T_1 unsigned long F_13 ( unsigned long V_22 )
{
return ( ( V_22 >> 24 ) & 0xff ) | ( ( V_22 >> 8 ) & 0xff00 ) |
( ( V_22 & 0xff00 ) << 8 ) | ( ( V_22 & 0xff ) << 24 ) ;
}
static T_1 unsigned long F_14 ( unsigned long V_22 )
{
return ( F_13 ( V_22 ) << 32 ) | F_13 ( V_22 >> 32 ) ;
}
static T_1 void F_15 ( void * V_23 , int V_15 )
{
switch ( V_15 ) {
case 2 :
* ( V_24 * ) V_23 = F_12 ( * ( V_24 * ) V_23 ) ;
break;
case 4 :
* ( V_25 * ) V_23 = F_13 ( * ( V_25 * ) V_23 ) ;
break;
#ifdef F_2
case 8 :
* ( unsigned long * ) V_23 = F_14 ( * ( unsigned long * ) V_23 ) ;
break;
case 16 : {
unsigned long * V_26 = ( unsigned long * ) V_23 ;
unsigned long V_27 ;
V_27 = F_14 ( V_26 [ 0 ] ) ;
V_26 [ 0 ] = F_14 ( V_26 [ 1 ] ) ;
V_26 [ 1 ] = V_27 ;
break;
}
#endif
default:
F_16 ( 1 ) ;
}
}
static T_1 int F_17 ( unsigned long * V_28 ,
unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
int V_29 = 0 ;
unsigned long V_22 = 0 ;
switch ( V_15 ) {
case 1 :
V_29 = F_18 ( V_22 , ( unsigned char V_30 * ) V_14 ) ;
break;
case 2 :
V_29 = F_18 ( V_22 , ( unsigned short V_30 * ) V_14 ) ;
break;
case 4 :
V_29 = F_18 ( V_22 , ( unsigned int V_30 * ) V_14 ) ;
break;
#ifdef F_2
case 8 :
V_29 = F_18 ( V_22 , ( unsigned long V_30 * ) V_14 ) ;
break;
#endif
}
if ( ! V_29 )
* V_28 = V_22 ;
else
V_6 -> V_17 = V_14 ;
return V_29 ;
}
static int T_1 F_19 ( T_2 * V_28 , unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
int V_29 = 0 ;
int V_31 ;
for (; V_15 > 0 ; V_15 -= V_31 ) {
V_31 = F_11 ( V_14 ) ;
if ( V_31 > V_15 )
V_31 = F_11 ( V_15 ) ;
switch ( V_31 ) {
case 1 :
V_29 = F_18 ( * V_28 , ( unsigned char V_30 * ) V_14 ) ;
break;
case 2 :
V_29 = F_18 ( * ( V_24 * ) V_28 ,
( unsigned short V_30 * ) V_14 ) ;
break;
case 4 :
V_29 = F_18 ( * ( V_25 * ) V_28 ,
( unsigned int V_30 * ) V_14 ) ;
break;
#ifdef F_2
case 8 :
V_29 = F_18 ( * ( unsigned long * ) V_28 ,
( unsigned long V_30 * ) V_14 ) ;
break;
#endif
}
if ( V_29 ) {
V_6 -> V_17 = V_14 ;
return V_29 ;
}
V_28 += V_31 ;
V_14 += V_31 ;
}
return 0 ;
}
static T_1 int F_20 ( unsigned long * V_28 ,
unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
union {
unsigned long V_32 ;
T_2 V_33 [ sizeof( unsigned long )];
} V_34 ;
int V_35 ;
int V_29 ;
V_34 . V_32 = 0 ;
V_35 = V_36 ? sizeof( unsigned long ) - V_15 : 0 ;
V_29 = F_19 ( & V_34 . V_33 [ V_35 ] , V_14 , V_15 , V_6 ) ;
if ( ! V_29 )
* V_28 = V_34 . V_32 ;
return V_29 ;
}
static int F_21 ( unsigned long * V_28 , unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_14 , V_15 ) )
return - V_37 ;
if ( ( V_14 & ( V_15 - 1 ) ) == 0 )
return F_17 ( V_28 , V_14 , V_15 , V_6 ) ;
return F_20 ( V_28 , V_14 , V_15 , V_6 ) ;
}
static T_1 int F_22 ( unsigned long V_2 ,
unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
int V_29 = 0 ;
switch ( V_15 ) {
case 1 :
V_29 = F_23 ( V_2 , ( unsigned char V_30 * ) V_14 ) ;
break;
case 2 :
V_29 = F_23 ( V_2 , ( unsigned short V_30 * ) V_14 ) ;
break;
case 4 :
V_29 = F_23 ( V_2 , ( unsigned int V_30 * ) V_14 ) ;
break;
#ifdef F_2
case 8 :
V_29 = F_23 ( V_2 , ( unsigned long V_30 * ) V_14 ) ;
break;
#endif
}
if ( V_29 )
V_6 -> V_17 = V_14 ;
return V_29 ;
}
static int T_1 F_24 ( T_2 * V_28 , unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
int V_29 = 0 ;
int V_31 ;
for (; V_15 > 0 ; V_15 -= V_31 ) {
V_31 = F_11 ( V_14 ) ;
if ( V_31 > V_15 )
V_31 = F_11 ( V_15 ) ;
switch ( V_31 ) {
case 1 :
V_29 = F_23 ( * V_28 , ( unsigned char V_30 * ) V_14 ) ;
break;
case 2 :
V_29 = F_23 ( * ( V_24 * ) V_28 ,
( unsigned short V_30 * ) V_14 ) ;
break;
case 4 :
V_29 = F_23 ( * ( V_25 * ) V_28 ,
( unsigned int V_30 * ) V_14 ) ;
break;
#ifdef F_2
case 8 :
V_29 = F_23 ( * ( unsigned long * ) V_28 ,
( unsigned long V_30 * ) V_14 ) ;
break;
#endif
}
if ( V_29 ) {
V_6 -> V_17 = V_14 ;
return V_29 ;
}
V_28 += V_31 ;
V_14 += V_31 ;
}
return 0 ;
}
static T_1 int F_25 ( unsigned long V_2 ,
unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
union {
unsigned long V_32 ;
T_2 V_33 [ sizeof( unsigned long )];
} V_34 ;
int V_35 ;
V_34 . V_32 = V_2 ;
V_35 = V_36 ? sizeof( unsigned long ) - V_15 : 0 ;
return F_24 ( & V_34 . V_33 [ V_35 ] , V_14 , V_15 , V_6 ) ;
}
static int F_26 ( unsigned long V_2 , unsigned long V_14 , int V_15 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_6 , V_14 , V_15 ) )
return - V_37 ;
if ( ( V_14 & ( V_15 - 1 ) ) == 0 )
return F_22 ( V_2 , V_14 , V_15 , V_6 ) ;
return F_25 ( V_2 , V_14 , V_15 , V_6 ) ;
}
static int F_27 ( struct V_7 * V_8 , unsigned long V_14 ,
struct V_5 * V_6 , bool V_38 )
{
int V_29 , V_39 , V_15 ;
union {
int V_35 ;
unsigned int V_34 ;
float V_40 ;
double V_41 [ 2 ] ;
unsigned long V_42 [ 2 ] ;
T_2 V_33 [ 2 * sizeof( double ) ] ;
} V_34 ;
V_15 = F_28 ( V_8 -> type ) ;
if ( ! F_4 ( V_6 , V_14 , V_15 ) )
return - V_37 ;
V_39 = V_8 -> V_43 ;
V_29 = F_19 ( V_34 . V_33 , V_14 , V_15 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( F_29 ( V_38 ) ) {
F_15 ( V_34 . V_33 , F_30 ( V_15 , 8 ) ) ;
if ( V_15 == 16 )
F_15 ( & V_34 . V_33 [ 8 ] , 8 ) ;
}
F_31 () ;
if ( V_15 == 4 ) {
if ( V_8 -> type & V_44 )
F_32 ( & V_34 . V_40 , & V_34 . V_41 [ 0 ] ) ;
else if ( V_8 -> type & V_45 )
V_34 . V_42 [ 0 ] = V_34 . V_35 ;
else
V_34 . V_42 [ 0 ] = V_34 . V_34 ;
}
if ( V_6 -> V_1 & V_46 )
F_33 ( V_39 , & V_34 . V_41 [ 0 ] ) ;
else
V_47 -> V_48 . V_49 ( V_39 ) = V_34 . V_42 [ 0 ] ;
if ( V_15 == 16 ) {
V_39 |= 1 ;
if ( V_6 -> V_1 & V_46 )
F_33 ( V_39 , & V_34 . V_41 [ 1 ] ) ;
else
V_47 -> V_48 . V_49 ( V_39 ) = V_34 . V_42 [ 1 ] ;
}
F_34 () ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 , unsigned long V_14 ,
struct V_5 * V_6 , bool V_38 )
{
int V_39 , V_15 ;
union {
unsigned int V_34 ;
float V_40 ;
double V_41 [ 2 ] ;
unsigned long V_42 [ 2 ] ;
T_2 V_33 [ 2 * sizeof( double ) ] ;
} V_34 ;
V_15 = F_28 ( V_8 -> type ) ;
if ( ! F_4 ( V_6 , V_14 , V_15 ) )
return - V_37 ;
V_39 = V_8 -> V_43 ;
F_31 () ;
if ( V_6 -> V_1 & V_46 )
F_36 ( V_39 , & V_34 . V_41 [ 0 ] ) ;
else
V_34 . V_42 [ 0 ] = V_47 -> V_48 . V_49 ( V_39 ) ;
if ( V_15 == 4 ) {
if ( V_8 -> type & V_44 )
F_37 ( & V_34 . V_41 [ 0 ] , & V_34 . V_40 ) ;
else
V_34 . V_34 = V_34 . V_42 [ 0 ] ;
}
if ( V_15 == 16 ) {
V_39 |= 1 ;
if ( V_6 -> V_1 & V_46 )
F_36 ( V_39 , & V_34 . V_41 [ 1 ] ) ;
else
V_34 . V_42 [ 1 ] = V_47 -> V_48 . V_49 ( V_39 ) ;
}
F_34 () ;
if ( F_29 ( V_38 ) ) {
F_15 ( V_34 . V_33 , F_30 ( V_15 , 8 ) ) ;
if ( V_15 == 16 )
F_15 ( & V_34 . V_33 [ 8 ] , 8 ) ;
}
return F_24 ( V_34 . V_33 , V_14 , V_15 , V_6 ) ;
}
static T_1 int F_38 ( int V_39 , unsigned long V_14 ,
int V_50 , struct V_5 * V_6 ,
bool V_38 )
{
int V_29 ;
union {
T_3 V_51 ;
T_2 V_33 [ sizeof( T_3 ) ] ;
} V_34 = {} ;
if ( ! F_4 ( V_6 , V_14 & ~ 0xfUL , 16 ) )
return - V_37 ;
V_14 &= ~ ( V_50 - 1 ) ;
V_29 = F_19 ( & V_34 . V_33 [ V_14 & 0xf ] , V_14 , V_50 , V_6 ) ;
if ( V_29 )
return V_29 ;
if ( F_29 ( V_38 ) )
F_15 ( & V_34 . V_33 [ V_14 & 0xf ] , V_50 ) ;
F_31 () ;
if ( V_6 -> V_1 & V_52 )
F_39 ( V_39 , & V_34 . V_51 ) ;
else
V_47 -> V_48 . V_53 . V_54 [ V_39 ] = V_34 . V_51 ;
F_34 () ;
return 0 ;
}
static T_1 int F_40 ( int V_39 , unsigned long V_14 ,
int V_50 , struct V_5 * V_6 ,
bool V_38 )
{
union {
T_3 V_51 ;
T_2 V_33 [ sizeof( T_3 ) ] ;
} V_34 ;
if ( ! F_4 ( V_6 , V_14 & ~ 0xfUL , 16 ) )
return - V_37 ;
V_14 &= ~ ( V_50 - 1 ) ;
F_31 () ;
if ( V_6 -> V_1 & V_52 )
F_41 ( V_39 , & V_34 . V_51 ) ;
else
V_34 . V_51 = V_47 -> V_48 . V_53 . V_54 [ V_39 ] ;
F_34 () ;
if ( F_29 ( V_38 ) )
F_15 ( & V_34 . V_33 [ V_14 & 0xf ] , V_50 ) ;
return F_24 ( & V_34 . V_33 [ V_14 & 0xf ] , V_14 , V_50 , V_6 ) ;
}
static T_1 int F_42 ( struct V_5 * V_6 , unsigned long V_14 ,
int V_43 , bool V_38 )
{
int V_29 ;
if ( ! F_4 ( V_6 , V_14 , 16 ) )
return - V_37 ;
if ( ( V_14 & 0xf ) == 0 ) {
V_29 = F_43 ( V_14 , & V_6 -> V_20 [ V_43 ] ) ;
} else {
V_29 = F_21 ( & V_6 -> V_20 [ V_43 + V_55 ] , V_14 , 8 , V_6 ) ;
if ( ! V_29 )
V_29 = F_21 ( & V_6 -> V_20 [ V_43 + V_36 ] , V_14 + 8 , 8 , V_6 ) ;
}
if ( ! V_29 && F_29 ( V_38 ) )
F_15 ( & V_6 -> V_20 [ V_43 ] , 16 ) ;
return V_29 ;
}
static T_1 int F_44 ( struct V_5 * V_6 , unsigned long V_14 ,
int V_43 , bool V_38 )
{
int V_29 ;
unsigned long V_56 [ 2 ] ;
if ( ! F_4 ( V_6 , V_14 , 16 ) )
return - V_37 ;
V_56 [ 0 ] = V_6 -> V_20 [ V_43 ] ;
V_56 [ 1 ] = V_6 -> V_20 [ V_43 + 1 ] ;
if ( F_29 ( V_38 ) )
F_15 ( V_56 , 16 ) ;
if ( ( V_14 & 0xf ) == 0 )
return F_45 ( V_14 , V_56 [ 0 ] , V_56 [ 1 ] ) ;
V_29 = F_26 ( V_56 [ V_55 ] , V_14 , 8 , V_6 ) ;
if ( ! V_29 )
V_29 = F_26 ( V_56 [ V_36 ] , V_14 + 8 , 8 , V_6 ) ;
return V_29 ;
}
void F_46 ( struct V_7 * V_8 , union V_57 * V_43 ,
const void * V_58 , bool V_59 )
{
int V_50 , V_60 ;
int V_35 , V_61 ;
const unsigned int * V_62 ;
const unsigned short * V_63 ;
const unsigned char * V_64 ;
V_50 = F_28 ( V_8 -> type ) ;
V_43 -> V_41 [ 0 ] = V_43 -> V_41 [ 1 ] = 0 ;
switch ( V_8 -> V_65 ) {
case 16 :
if ( V_50 == 0 )
break;
memcpy ( V_43 , V_58 , V_50 ) ;
if ( V_55 && ( V_8 -> V_66 & V_67 ) )
V_59 = ! V_59 ;
if ( V_59 )
F_15 ( V_43 , 16 ) ;
break;
case 8 :
V_60 = ( V_50 >= 8 ) ? 8 : V_50 ;
V_35 = V_55 ? 8 : 8 - V_60 ;
memcpy ( & V_43 -> V_33 [ V_35 ] , V_58 , V_60 ) ;
if ( V_59 )
F_15 ( & V_43 -> V_33 [ V_35 ] , 8 ) ;
if ( V_50 < 8 ) {
if ( V_8 -> type & V_45 ) {
V_43 -> V_41 [ V_55 ] = ( signed int ) V_43 -> V_41 [ V_55 ] ;
} else if ( V_8 -> V_66 & V_68 ) {
F_31 () ;
F_32 ( & V_43 -> V_69 [ 1 + V_55 ] ,
& V_43 -> V_70 [ V_55 ] ) ;
F_34 () ;
}
} else {
if ( V_50 == 16 ) {
unsigned long V_51 = * ( unsigned long * ) ( V_58 + 8 ) ;
V_43 -> V_41 [ V_36 ] = ! V_59 ? V_51 : F_14 ( V_51 ) ;
} else if ( V_8 -> V_66 & V_71 )
V_43 -> V_41 [ V_36 ] = V_43 -> V_41 [ V_55 ] ;
}
break;
case 4 :
V_62 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 / 4 ; ++ V_61 ) {
V_35 = V_55 ? 3 - V_61 : V_61 ;
V_43 -> V_72 [ V_35 ] = ! V_59 ? * V_62 ++ : F_13 ( * V_62 ++ ) ;
}
if ( V_8 -> V_66 & V_71 ) {
V_25 V_2 = V_43 -> V_72 [ V_55 ? 3 : 0 ] ;
for (; V_61 < 4 ; ++ V_61 ) {
V_35 = V_55 ? 3 - V_61 : V_61 ;
V_43 -> V_72 [ V_35 ] = V_2 ;
}
}
break;
case 2 :
V_63 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 / 2 ; ++ V_61 ) {
V_35 = V_55 ? 7 - V_61 : V_61 ;
V_43 -> V_73 [ V_35 ] = ! V_59 ? * V_63 ++ : F_12 ( * V_63 ++ ) ;
}
break;
case 1 :
V_64 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 ; ++ V_61 ) {
V_35 = V_55 ? 15 - V_61 : V_61 ;
V_43 -> V_33 [ V_35 ] = * V_64 ++ ;
}
break;
}
}
void F_47 ( struct V_7 * V_8 , const union V_57 * V_43 ,
void * V_58 , bool V_59 )
{
int V_50 , V_74 ;
int V_35 , V_61 ;
union V_57 V_75 ;
unsigned int * V_62 ;
unsigned short * V_63 ;
unsigned char * V_64 ;
V_50 = F_28 ( V_8 -> type ) ;
switch ( V_8 -> V_65 ) {
case 16 :
if ( V_50 == 0 )
break;
if ( V_55 && ( V_8 -> V_66 & V_67 ) )
V_59 = ! V_59 ;
if ( V_59 ) {
V_75 . V_41 [ 0 ] = F_14 ( V_43 -> V_41 [ 1 ] ) ;
V_75 . V_41 [ 1 ] = F_14 ( V_43 -> V_41 [ 0 ] ) ;
V_43 = & V_75 ;
}
memcpy ( V_58 , V_43 , V_50 ) ;
break;
case 8 :
V_74 = ( V_50 >= 8 ) ? 8 : V_50 ;
V_35 = V_55 ? 8 : 8 - V_74 ;
if ( V_50 < 8 && V_8 -> V_66 & V_68 ) {
V_75 . V_41 [ 0 ] = V_75 . V_41 [ 1 ] = 0 ;
F_31 () ;
F_37 ( & V_43 -> V_70 [ V_55 ] , & V_75 . V_69 [ 1 + V_55 ] ) ;
F_34 () ;
V_43 = & V_75 ;
}
memcpy ( V_58 , & V_43 -> V_33 [ V_35 ] , V_74 ) ;
if ( V_50 == 16 )
memcpy ( V_58 + 8 , & V_43 -> V_41 [ V_36 ] , 8 ) ;
if ( F_29 ( V_59 ) ) {
F_15 ( V_58 , V_74 ) ;
if ( V_50 == 16 )
F_15 ( V_58 + 8 , 8 ) ;
}
break;
case 4 :
V_62 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 / 4 ; ++ V_61 ) {
V_35 = V_55 ? 3 - V_61 : V_61 ;
* V_62 ++ = ! V_59 ? V_43 -> V_72 [ V_35 ] : F_13 ( V_43 -> V_72 [ V_35 ] ) ;
}
break;
case 2 :
V_63 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 / 2 ; ++ V_61 ) {
V_35 = V_55 ? 7 - V_61 : V_61 ;
* V_63 ++ = ! V_59 ? V_43 -> V_73 [ V_35 ] : F_12 ( V_43 -> V_73 [ V_35 ] ) ;
}
break;
case 1 :
V_64 = V_58 ;
for ( V_61 = 0 ; V_61 < V_50 ; ++ V_61 ) {
V_35 = V_55 ? 15 - V_61 : V_61 ;
* V_64 ++ = V_43 -> V_33 [ V_35 ] ;
}
break;
}
}
static T_1 int F_48 ( struct V_7 * V_8 ,
unsigned long V_14 , struct V_5 * V_6 ,
bool V_38 )
{
int V_43 = V_8 -> V_43 ;
T_2 V_58 [ 16 ] ;
union V_57 V_75 ;
int V_50 = F_28 ( V_8 -> type ) ;
if ( ! F_4 ( V_6 , V_14 , V_50 ) || F_19 ( V_58 , V_14 , V_50 , V_6 ) )
return - V_37 ;
F_46 ( V_8 , & V_75 , V_58 , V_38 ) ;
F_31 () ;
if ( V_43 < 32 ) {
if ( V_6 -> V_1 & V_46 ) {
F_49 ( V_43 , & V_75 ) ;
} else {
V_47 -> V_48 . V_76 . V_77 [ V_43 ] [ 0 ] = V_75 . V_41 [ 0 ] ;
V_47 -> V_48 . V_76 . V_77 [ V_43 ] [ 1 ] = V_75 . V_41 [ 1 ] ;
}
} else {
if ( V_6 -> V_1 & V_52 )
F_49 ( V_43 , & V_75 ) ;
else
V_47 -> V_48 . V_53 . V_54 [ V_43 - 32 ] = V_75 . V_51 ;
}
F_34 () ;
return 0 ;
}
static T_1 int F_50 ( struct V_7 * V_8 ,
unsigned long V_14 , struct V_5 * V_6 ,
bool V_38 )
{
int V_43 = V_8 -> V_43 ;
T_2 V_58 [ 16 ] ;
union V_57 V_75 ;
int V_50 = F_28 ( V_8 -> type ) ;
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
F_31 () ;
if ( V_43 < 32 ) {
if ( V_6 -> V_1 & V_46 ) {
F_51 ( V_43 , & V_75 ) ;
} else {
V_75 . V_41 [ 0 ] = V_47 -> V_48 . V_76 . V_77 [ V_43 ] [ 0 ] ;
V_75 . V_41 [ 1 ] = V_47 -> V_48 . V_76 . V_77 [ V_43 ] [ 1 ] ;
}
} else {
if ( V_6 -> V_1 & V_52 )
F_51 ( V_43 , & V_75 ) ;
else
V_75 . V_51 = V_47 -> V_48 . V_53 . V_54 [ V_43 - 32 ] ;
}
F_34 () ;
F_47 ( V_8 , & V_75 , V_58 , V_38 ) ;
return F_24 ( V_58 , V_14 , V_50 , V_6 ) ;
}
int F_52 ( unsigned long V_14 , struct V_5 * V_6 )
{
int V_29 ;
unsigned long V_35 , V_50 ;
#ifdef F_2
V_50 = V_78 . V_79 . V_80 ;
if ( ! ( V_6 -> V_1 & V_3 ) )
V_14 &= 0xffffffffUL ;
#else
V_50 = V_81 ;
#endif
V_14 &= ~ ( V_50 - 1 ) ;
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
for ( V_35 = 0 ; V_35 < V_50 ; V_35 += sizeof( long ) ) {
V_29 = F_23 ( 0 , ( unsigned long V_30 * ) ( V_14 + V_35 ) ) ;
if ( V_29 ) {
V_6 -> V_17 = V_14 ;
return V_29 ;
}
}
return 0 ;
}
static T_1 void F_53 ( const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
long V_2 = V_8 -> V_2 ;
V_8 -> type |= V_82 ;
V_8 -> V_83 = ( V_6 -> V_13 & 0x0fffffff ) | ( ( V_6 -> V_84 >> 3 ) & 0x10000000 ) ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) )
V_2 = ( int ) V_2 ;
#endif
if ( V_2 < 0 )
V_8 -> V_83 |= 0x80000000 ;
else if ( V_2 > 0 )
V_8 -> V_83 |= 0x40000000 ;
else
V_8 -> V_83 |= 0x20000000 ;
}
static T_1 void F_54 ( const struct V_5 * V_6 ,
struct V_7 * V_8 , int V_85 ,
unsigned long V_86 , unsigned long V_87 ,
unsigned long V_88 )
{
unsigned long V_2 = V_86 + V_87 ;
if ( V_88 )
++ V_2 ;
V_8 -> type = V_89 + V_90 + V_91 ;
V_8 -> V_43 = V_85 ;
V_8 -> V_2 = V_2 ;
#ifdef F_2
if ( ! ( V_6 -> V_1 & V_3 ) ) {
V_2 = ( unsigned int ) V_2 ;
V_86 = ( unsigned int ) V_86 ;
}
#endif
V_8 -> V_92 = V_6 -> V_84 ;
if ( V_2 < V_86 || ( V_88 && V_2 == V_86 ) )
V_8 -> V_92 |= V_93 ;
else
V_8 -> V_92 &= ~ V_93 ;
}
static T_1 void F_55 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
long V_94 , long V_95 , int V_96 )
{
unsigned int V_97 , V_98 ;
V_8 -> type = V_89 + V_82 ;
V_97 = ( V_6 -> V_84 >> 31 ) & 1 ;
if ( V_94 < V_95 )
V_97 |= 8 ;
else if ( V_94 > V_95 )
V_97 |= 4 ;
else
V_97 |= 2 ;
V_98 = ( 7 - V_96 ) * 4 ;
V_8 -> V_83 = ( V_6 -> V_13 & ~ ( 0xf << V_98 ) ) | ( V_97 << V_98 ) ;
}
static T_1 void F_56 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_94 ,
unsigned long V_95 , int V_96 )
{
unsigned int V_97 , V_98 ;
V_8 -> type = V_89 + V_82 ;
V_97 = ( V_6 -> V_84 >> 31 ) & 1 ;
if ( V_94 < V_95 )
V_97 |= 8 ;
else if ( V_94 > V_95 )
V_97 |= 4 ;
else
V_97 |= 2 ;
V_98 = ( 7 - V_96 ) * 4 ;
V_8 -> V_83 = ( V_6 -> V_13 & ~ ( 0xf << V_98 ) ) | ( V_97 << V_98 ) ;
}
static T_1 void F_57 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_94 , unsigned long V_95 )
{
unsigned long long V_99 , V_100 ;
int V_35 ;
V_99 = 0 ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_100 = 0xffUL << ( V_35 * 8 ) ;
if ( ( V_94 & V_100 ) == ( V_95 & V_100 ) )
V_99 |= V_100 ;
}
V_8 -> V_2 = V_99 ;
}
static T_1 void F_58 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_94 , int V_50 )
{
unsigned long long V_101 = V_94 ;
V_101 -= ( V_101 >> 1 ) & 0x5555555555555555 ;
V_101 = ( 0x3333333333333333 & V_101 ) + ( 0x3333333333333333 & ( V_101 >> 2 ) ) ;
V_101 = ( V_101 + ( V_101 >> 4 ) ) & 0x0f0f0f0f0f0f0f0f ;
if ( V_50 == 8 ) {
V_8 -> V_2 = V_101 ;
return;
}
V_101 += V_101 >> 8 ;
V_101 += V_101 >> 16 ;
if ( V_50 == 32 ) {
V_8 -> V_2 = V_101 & 0x0000003f0000003f ;
return;
}
V_101 = ( V_101 + ( V_101 >> 32 ) ) & 0x7f ;
V_8 -> V_2 = V_101 ;
}
static T_1 void F_59 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_94 , unsigned long V_95 )
{
unsigned char V_102 , V_103 ;
unsigned int V_35 ;
V_102 = 0 ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ ) {
V_103 = ( V_94 >> ( V_35 * 8 ) ) & 0xff ;
if ( V_103 < 64 )
if ( V_95 & F_60 ( V_103 ) )
V_102 |= 1 << V_35 ;
}
V_8 -> V_2 = V_102 ;
}
static T_1 void F_61 ( const struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned long V_51 , int V_50 )
{
unsigned long long V_104 = V_51 ^ ( V_51 >> 8 ) ;
V_104 ^= V_104 >> 16 ;
if ( V_50 == 32 ) {
V_8 -> V_2 = V_104 & 0x0000000100000001 ;
return;
}
V_104 ^= V_104 >> 32 ;
V_8 -> V_2 = V_104 & 1 ;
}
static T_1 int F_62 ( long V_94 , long V_95 )
{
int V_105 = 0 ;
if ( V_94 < V_95 )
V_105 |= 0x10 ;
else if ( V_94 > V_95 )
V_105 |= 0x08 ;
else
V_105 |= 0x04 ;
if ( ( unsigned long ) V_94 < ( unsigned long ) V_95 )
V_105 |= 0x02 ;
else if ( ( unsigned long ) V_94 > ( unsigned long ) V_95 )
V_105 |= 0x01 ;
return V_105 ;
}
int F_63 ( struct V_7 * V_8 , const struct V_5 * V_6 ,
unsigned int V_4 )
{
unsigned int V_106 , V_19 , V_21 , V_85 , V_107 , V_34 ;
unsigned long int V_108 ;
unsigned long int V_2 , V_87 ;
unsigned int V_109 , V_110 , V_111 ;
long V_112 ;
V_8 -> type = V_89 ;
V_106 = V_4 >> 26 ;
switch ( V_106 ) {
case 16 :
V_8 -> type = V_113 ;
V_108 = ( signed short ) ( V_4 & 0xfffc ) ;
if ( ( V_4 & 2 ) == 0 )
V_108 += V_6 -> V_114 ;
V_8 -> V_2 = F_1 ( V_6 -> V_1 , V_108 ) ;
if ( V_4 & 1 )
V_8 -> type |= V_115 ;
if ( F_3 ( V_4 , V_6 , V_8 ) )
V_8 -> type |= V_116 ;
return 1 ;
#ifdef F_64
case 17 :
if ( ( V_4 & 0xfe2 ) == 2 )
V_8 -> type = V_117 ;
else
V_8 -> type = V_118 ;
return 0 ;
#endif
case 18 :
V_8 -> type = V_113 | V_116 ;
V_108 = V_4 & 0x03fffffc ;
if ( V_108 & 0x02000000 )
V_108 -= 0x04000000 ;
if ( ( V_4 & 2 ) == 0 )
V_108 += V_6 -> V_114 ;
V_8 -> V_2 = F_1 ( V_6 -> V_1 , V_108 ) ;
if ( V_4 & 1 )
V_8 -> type |= V_115 ;
return 1 ;
case 19 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 0 :
V_8 -> type = V_89 + V_82 ;
V_85 = 7 - ( ( V_4 >> 23 ) & 0x7 ) ;
V_19 = 7 - ( ( V_4 >> 18 ) & 0x7 ) ;
V_85 *= 4 ;
V_19 *= 4 ;
V_2 = ( V_6 -> V_13 >> V_19 ) & 0xf ;
V_8 -> V_83 = ( V_6 -> V_13 & ~ ( 0xfUL << V_85 ) ) | ( V_2 << V_85 ) ;
return 1 ;
case 16 :
case 528 :
V_8 -> type = V_113 ;
V_108 = ( V_4 & 0x400 ) ? V_6 -> V_12 : V_6 -> V_119 ;
V_8 -> V_2 = F_1 ( V_6 -> V_1 , V_108 ) ;
if ( V_4 & 1 )
V_8 -> type |= V_115 ;
if ( F_3 ( V_4 , V_6 , V_8 ) )
V_8 -> type |= V_116 ;
return 1 ;
case 18 :
if ( V_6 -> V_1 & V_120 )
goto V_121;
V_8 -> type = V_122 ;
return 0 ;
case 150 :
V_8 -> type = V_123 | V_124 ;
return 1 ;
case 33 :
case 129 :
case 193 :
case 225 :
case 257 :
case 289 :
case 417 :
case 449 :
V_8 -> type = V_89 + V_82 ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_21 = ( V_4 >> 11 ) & 0x1f ;
V_85 = ( V_4 >> 21 ) & 0x1f ;
V_19 = ( V_6 -> V_13 >> ( 31 - V_19 ) ) & 1 ;
V_21 = ( V_6 -> V_13 >> ( 31 - V_21 ) ) & 1 ;
V_2 = ( V_4 >> ( 6 + V_19 * 2 + V_21 ) ) & 1 ;
V_8 -> V_83 = ( V_6 -> V_13 & ~ ( 1UL << ( 31 - V_85 ) ) ) |
( V_2 << ( 31 - V_85 ) ) ;
return 1 ;
}
break;
case 31 :
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 598 :
V_8 -> type = V_123 + V_125 ;
#ifdef F_2
switch ( ( V_4 >> 21 ) & 3 ) {
case 1 :
V_8 -> type = V_123 + V_126 ;
break;
case 2 :
V_8 -> type = V_123 + V_127 ;
break;
}
#endif
return 1 ;
case 854 :
V_8 -> type = V_123 + V_128 ;
return 1 ;
}
break;
}
if ( ! F_65 ( V_6 ) )
return - 1 ;
V_85 = ( V_4 >> 21 ) & 0x1f ;
V_19 = ( V_4 >> 16 ) & 0x1f ;
V_21 = ( V_4 >> 11 ) & 0x1f ;
switch ( V_106 ) {
#ifdef F_2
case 2 :
if ( V_85 & F_62 ( V_6 -> V_20 [ V_19 ] , ( short ) V_4 ) )
goto V_129;
return 1 ;
#endif
case 3 :
if ( V_85 & F_62 ( ( int ) V_6 -> V_20 [ V_19 ] , ( short ) V_4 ) )
goto V_129;
return 1 ;
case 7 :
V_8 -> V_2 = V_6 -> V_20 [ V_19 ] * ( short ) V_4 ;
goto V_130;
case 8 :
V_108 = ( short ) V_4 ;
F_54 ( V_6 , V_8 , V_85 , ~ V_6 -> V_20 [ V_19 ] , V_108 , 1 ) ;
return 1 ;
case 10 :
V_108 = ( unsigned short ) V_4 ;
V_2 = V_6 -> V_20 [ V_19 ] ;
#ifdef F_2
if ( ( V_85 & 1 ) == 0 )
V_2 = ( unsigned int ) V_2 ;
#endif
F_56 ( V_6 , V_8 , V_2 , V_108 , V_85 >> 2 ) ;
return 1 ;
case 11 :
V_108 = ( short ) V_4 ;
V_2 = V_6 -> V_20 [ V_19 ] ;
#ifdef F_2
if ( ( V_85 & 1 ) == 0 )
V_2 = ( int ) V_2 ;
#endif
F_55 ( V_6 , V_8 , V_2 , V_108 , V_85 >> 2 ) ;
return 1 ;
case 12 :
V_108 = ( short ) V_4 ;
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] , V_108 , 0 ) ;
return 1 ;
case 13 :
V_108 = ( short ) V_4 ;
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] , V_108 , 0 ) ;
F_53 ( V_6 , V_8 ) ;
return 1 ;
case 14 :
V_108 = ( short ) V_4 ;
if ( V_19 )
V_108 += V_6 -> V_20 [ V_19 ] ;
V_8 -> V_2 = V_108 ;
goto V_130;
case 15 :
V_108 = ( ( short ) V_4 ) << 16 ;
if ( V_19 )
V_108 += V_6 -> V_20 [ V_19 ] ;
V_8 -> V_2 = V_108 ;
goto V_130;
case 19 :
if ( ( ( V_4 >> 1 ) & 0x1f ) == 2 ) {
V_108 = ( short ) ( V_4 & 0xffc1 ) ;
V_108 |= ( V_4 >> 15 ) & 0x3e ;
V_8 -> V_2 = V_6 -> V_114 + ( V_108 << 16 ) + 4 ;
goto V_130;
}
V_8 -> type = V_118 ;
return 0 ;
case 20 :
V_109 = ( V_4 >> 6 ) & 0x1f ;
V_110 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_66 ( V_6 -> V_20 [ V_85 ] ) ;
V_108 = F_67 ( V_109 , V_110 ) ;
V_8 -> V_2 = ( V_6 -> V_20 [ V_19 ] & ~ V_108 ) | ( F_68 ( V_2 , V_21 ) & V_108 ) ;
goto V_131;
case 21 :
V_109 = ( V_4 >> 6 ) & 0x1f ;
V_110 = ( V_4 >> 1 ) & 0x1f ;
V_2 = F_66 ( V_6 -> V_20 [ V_85 ] ) ;
V_8 -> V_2 = F_68 ( V_2 , V_21 ) & F_67 ( V_109 , V_110 ) ;
goto V_131;
case 23 :
V_109 = ( V_4 >> 6 ) & 0x1f ;
V_110 = ( V_4 >> 1 ) & 0x1f ;
V_21 = V_6 -> V_20 [ V_21 ] & 0x1f ;
V_2 = F_66 ( V_6 -> V_20 [ V_85 ] ) ;
V_8 -> V_2 = F_68 ( V_2 , V_21 ) & F_67 ( V_109 , V_110 ) ;
goto V_131;
case 24 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] | ( unsigned short ) V_4 ;
goto V_132;
case 25 :
V_108 = ( unsigned short ) V_4 ;
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] | ( V_108 << 16 ) ;
goto V_132;
case 26 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] ^ ( unsigned short ) V_4 ;
goto V_132;
case 27 :
V_108 = ( unsigned short ) V_4 ;
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] ^ ( V_108 << 16 ) ;
goto V_132;
case 28 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] & ( unsigned short ) V_4 ;
F_53 ( V_6 , V_8 ) ;
goto V_132;
case 29 :
V_108 = ( unsigned short ) V_4 ;
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] & ( V_108 << 16 ) ;
F_53 ( V_6 , V_8 ) ;
goto V_132;
#ifdef F_2
case 30 :
V_109 = ( ( V_4 >> 6 ) & 0x1f ) | ( V_4 & 0x20 ) ;
V_2 = V_6 -> V_20 [ V_85 ] ;
if ( ( V_4 & 0x10 ) == 0 ) {
V_111 = V_21 | ( ( V_4 & 2 ) << 4 ) ;
V_2 = F_68 ( V_2 , V_111 ) ;
switch ( ( V_4 >> 2 ) & 3 ) {
case 0 :
V_2 &= F_69 ( V_109 ) ;
break;
case 1 :
V_2 &= F_70 ( V_109 ) ;
break;
case 2 :
V_2 &= F_71 ( V_109 , 63 - V_111 ) ;
break;
case 3 :
V_108 = F_71 ( V_109 , 63 - V_111 ) ;
V_2 = ( V_6 -> V_20 [ V_19 ] & ~ V_108 ) |
( V_2 & V_108 ) ;
}
V_8 -> V_2 = V_2 ;
goto V_131;
} else {
V_111 = V_6 -> V_20 [ V_21 ] & 0x3f ;
V_2 = F_68 ( V_2 , V_111 ) ;
switch ( ( V_4 >> 1 ) & 7 ) {
case 0 :
V_8 -> V_2 = V_2 & F_69 ( V_109 ) ;
goto V_131;
case 1 :
V_8 -> V_2 = V_2 & F_70 ( V_109 ) ;
goto V_131;
}
}
#endif
V_8 -> type = V_118 ;
return 0 ;
case 31 :
if ( ( ( V_4 >> 1 ) & 0x1f ) == 15 ) {
V_109 = ( V_4 >> 6 ) & 0x1f ;
V_2 = ( V_6 -> V_13 >> ( 31 - V_109 ) ) & 1 ;
V_87 = ( V_19 ) ? V_6 -> V_20 [ V_19 ] : 0 ;
V_8 -> V_2 = ( V_2 ) ? V_87 : V_6 -> V_20 [ V_21 ] ;
goto V_130;
}
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 4 :
if ( V_85 == 0x1f ||
( V_85 & F_62 ( ( int ) V_6 -> V_20 [ V_19 ] ,
( int ) V_6 -> V_20 [ V_21 ] ) ) )
goto V_129;
return 1 ;
#ifdef F_2
case 68 :
if ( V_85 & F_62 ( V_6 -> V_20 [ V_19 ] , V_6 -> V_20 [ V_21 ] ) )
goto V_129;
return 1 ;
#endif
case 83 :
if ( V_6 -> V_1 & V_120 )
goto V_121;
V_8 -> type = V_133 ;
V_8 -> V_43 = V_85 ;
return 0 ;
case 146 :
if ( V_6 -> V_1 & V_120 )
goto V_121;
V_8 -> type = V_134 ;
V_8 -> V_43 = V_85 ;
V_8 -> V_2 = 0xffffffff & ~ ( V_135 | V_136 ) ;
return 0 ;
#ifdef F_64
case 178 :
if ( V_6 -> V_1 & V_120 )
goto V_121;
V_8 -> type = V_134 ;
V_8 -> V_43 = V_85 ;
V_108 = ( V_4 & 0x10000 ) ? 0x8002 : 0xefffffffffffeffeUL ;
V_8 -> V_2 = V_108 ;
return 0 ;
#endif
case 19 :
V_108 = 0xffffffffUL ;
if ( ( V_4 >> 20 ) & 1 ) {
V_108 = 0xf0000000UL ;
for ( V_111 = 0 ; V_111 < 8 ; ++ V_111 ) {
if ( V_4 & ( 0x80000 >> V_111 ) )
break;
V_108 >>= 4 ;
}
}
V_8 -> V_2 = V_6 -> V_13 & V_108 ;
goto V_130;
case 144 :
V_8 -> type = V_89 + V_82 ;
V_108 = 0xf0000000UL ;
V_2 = V_6 -> V_20 [ V_85 ] ;
V_8 -> V_83 = V_6 -> V_13 ;
for ( V_111 = 0 ; V_111 < 8 ; ++ V_111 ) {
if ( V_4 & ( 0x80000 >> V_111 ) )
V_8 -> V_83 = ( V_8 -> V_83 & ~ V_108 ) |
( V_2 & V_108 ) ;
V_108 >>= 4 ;
}
return 1 ;
case 339 :
V_107 = ( ( V_4 >> 16 ) & 0x1f ) | ( ( V_4 >> 6 ) & 0x3e0 ) ;
V_8 -> type = V_137 ;
V_8 -> V_43 = V_85 ;
V_8 -> V_107 = V_107 ;
if ( V_107 == V_138 || V_107 == V_139 ||
V_107 == V_140 )
return 1 ;
return 0 ;
case 467 :
V_107 = ( ( V_4 >> 16 ) & 0x1f ) | ( ( V_4 >> 6 ) & 0x3e0 ) ;
V_8 -> type = V_141 ;
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] ;
V_8 -> V_107 = V_107 ;
if ( V_107 == V_138 || V_107 == V_139 ||
V_107 == V_140 )
return 1 ;
return 0 ;
case 0 :
V_2 = V_6 -> V_20 [ V_19 ] ;
V_87 = V_6 -> V_20 [ V_21 ] ;
#ifdef F_2
if ( ( V_85 & 1 ) == 0 ) {
V_2 = ( int ) V_2 ;
V_87 = ( int ) V_87 ;
}
#endif
F_55 ( V_6 , V_8 , V_2 , V_87 , V_85 >> 2 ) ;
return 1 ;
case 32 :
V_2 = V_6 -> V_20 [ V_19 ] ;
V_87 = V_6 -> V_20 [ V_21 ] ;
#ifdef F_2
if ( ( V_85 & 1 ) == 0 ) {
V_2 = ( unsigned int ) V_2 ;
V_87 = ( unsigned int ) V_87 ;
}
#endif
F_56 ( V_6 , V_8 , V_2 , V_87 , V_85 >> 2 ) ;
return 1 ;
case 508 :
F_57 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , V_6 -> V_20 [ V_21 ] ) ;
goto V_132;
case 8 :
F_54 ( V_6 , V_8 , V_85 , ~ V_6 -> V_20 [ V_19 ] ,
V_6 -> V_20 [ V_21 ] , 1 ) ;
goto V_142;
#ifdef F_2
case 9 :
asm("mulhdu %0,%1,%2" : "=r" (op->val) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_142;
#endif
case 10 :
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] ,
V_6 -> V_20 [ V_21 ] , 0 ) ;
goto V_142;
case 11 :
asm("mulhwu %0,%1,%2" : "=r" (op->val) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_142;
case 40 :
V_8 -> V_2 = V_6 -> V_20 [ V_21 ] - V_6 -> V_20 [ V_19 ] ;
goto V_142;
#ifdef F_2
case 73 :
asm("mulhd %0,%1,%2" : "=r" (op->val) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_142;
#endif
case 75 :
asm("mulhw %0,%1,%2" : "=r" (op->val) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto V_142;
case 104 :
V_8 -> V_2 = - V_6 -> V_20 [ V_19 ] ;
goto V_142;
case 136 :
F_54 ( V_6 , V_8 , V_85 , ~ V_6 -> V_20 [ V_19 ] ,
V_6 -> V_20 [ V_21 ] , V_6 -> V_84 & V_93 ) ;
goto V_142;
case 138 :
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] ,
V_6 -> V_20 [ V_21 ] , V_6 -> V_84 & V_93 ) ;
goto V_142;
case 200 :
F_54 ( V_6 , V_8 , V_85 , ~ V_6 -> V_20 [ V_19 ] , 0L ,
V_6 -> V_84 & V_93 ) ;
goto V_142;
case 202 :
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] , 0L ,
V_6 -> V_84 & V_93 ) ;
goto V_142;
case 232 :
F_54 ( V_6 , V_8 , V_85 , ~ V_6 -> V_20 [ V_19 ] , - 1L ,
V_6 -> V_84 & V_93 ) ;
goto V_142;
#ifdef F_2
case 233 :
V_8 -> V_2 = V_6 -> V_20 [ V_19 ] * V_6 -> V_20 [ V_21 ] ;
goto V_142;
#endif
case 234 :
F_54 ( V_6 , V_8 , V_85 , V_6 -> V_20 [ V_19 ] , - 1L ,
V_6 -> V_84 & V_93 ) ;
goto V_142;
case 235 :
V_8 -> V_2 = ( long ) ( int ) V_6 -> V_20 [ V_19 ] *
( int ) V_6 -> V_20 [ V_21 ] ;
goto V_142;
case 266 :
V_8 -> V_2 = V_6 -> V_20 [ V_19 ] + V_6 -> V_20 [ V_21 ] ;
goto V_142;
#ifdef F_2
case 457 :
V_8 -> V_2 = V_6 -> V_20 [ V_19 ] / V_6 -> V_20 [ V_21 ] ;
goto V_142;
#endif
case 459 :
V_8 -> V_2 = ( unsigned int ) V_6 -> V_20 [ V_19 ] /
( unsigned int ) V_6 -> V_20 [ V_21 ] ;
goto V_142;
#ifdef F_2
case 489 :
V_8 -> V_2 = ( long int ) V_6 -> V_20 [ V_19 ] /
( long int ) V_6 -> V_20 [ V_21 ] ;
goto V_142;
#endif
case 491 :
V_8 -> V_2 = ( int ) V_6 -> V_20 [ V_19 ] /
( int ) V_6 -> V_20 [ V_21 ] ;
goto V_142;
case 26 :
V_2 = ( unsigned int ) V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = ( V_2 ? F_72 ( V_2 ) : 32 ) ;
goto V_131;
#ifdef F_2
case 58 :
V_2 = V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = ( V_2 ? F_73 ( V_2 ) : 64 ) ;
goto V_131;
#endif
case 28 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] & V_6 -> V_20 [ V_21 ] ;
goto V_131;
case 60 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] & ~ V_6 -> V_20 [ V_21 ] ;
goto V_131;
case 122 :
F_58 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , 8 ) ;
goto V_132;
case 124 :
V_8 -> V_2 = ~ ( V_6 -> V_20 [ V_85 ] | V_6 -> V_20 [ V_21 ] ) ;
goto V_131;
case 154 :
F_61 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , 32 ) ;
goto V_132;
case 186 :
F_61 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , 64 ) ;
goto V_132;
#ifdef F_64
case 252 :
F_59 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , V_6 -> V_20 [ V_21 ] ) ;
goto V_132;
#endif
case 284 :
V_8 -> V_2 = ~ ( V_6 -> V_20 [ V_85 ] ^ V_6 -> V_20 [ V_21 ] ) ;
goto V_131;
case 316 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] ^ V_6 -> V_20 [ V_21 ] ;
goto V_131;
case 378 :
F_58 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , 32 ) ;
goto V_132;
case 412 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] | ~ V_6 -> V_20 [ V_21 ] ;
goto V_131;
case 444 :
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] | V_6 -> V_20 [ V_21 ] ;
goto V_131;
case 476 :
V_8 -> V_2 = ~ ( V_6 -> V_20 [ V_85 ] & V_6 -> V_20 [ V_21 ] ) ;
goto V_131;
#ifdef F_64
case 506 :
F_58 ( V_6 , V_8 , V_6 -> V_20 [ V_85 ] , 64 ) ;
goto V_132;
#endif
case 922 :
V_8 -> V_2 = ( signed short ) V_6 -> V_20 [ V_85 ] ;
goto V_131;
case 954 :
V_8 -> V_2 = ( signed char ) V_6 -> V_20 [ V_85 ] ;
goto V_131;
#ifdef F_2
case 986 :
V_8 -> V_2 = ( signed int ) V_6 -> V_20 [ V_85 ] ;
goto V_131;
#endif
case 24 :
V_111 = V_6 -> V_20 [ V_21 ] & 0x3f ;
if ( V_111 < 32 )
V_8 -> V_2 = ( V_6 -> V_20 [ V_85 ] << V_111 ) & 0xffffffffUL ;
else
V_8 -> V_2 = 0 ;
goto V_131;
case 536 :
V_111 = V_6 -> V_20 [ V_21 ] & 0x3f ;
if ( V_111 < 32 )
V_8 -> V_2 = ( V_6 -> V_20 [ V_85 ] & 0xffffffffUL ) >> V_111 ;
else
V_8 -> V_2 = 0 ;
goto V_131;
case 792 :
V_8 -> type = V_89 + V_90 + V_91 ;
V_111 = V_6 -> V_20 [ V_21 ] & 0x3f ;
V_112 = ( signed int ) V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = V_112 >> ( V_111 < 32 ? V_111 : 31 ) ;
V_8 -> V_92 = V_6 -> V_84 ;
if ( V_112 < 0 && ( V_111 >= 32 || ( V_112 & ( ( 1ul << V_111 ) - 1 ) ) != 0 ) )
V_8 -> V_92 |= V_93 ;
else
V_8 -> V_92 &= ~ V_93 ;
goto V_131;
case 824 :
V_8 -> type = V_89 + V_90 + V_91 ;
V_111 = V_21 ;
V_112 = ( signed int ) V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = V_112 >> V_111 ;
V_8 -> V_92 = V_6 -> V_84 ;
if ( V_112 < 0 && ( V_112 & ( ( 1ul << V_111 ) - 1 ) ) != 0 )
V_8 -> V_92 |= V_93 ;
else
V_8 -> V_92 &= ~ V_93 ;
goto V_131;
#ifdef F_2
case 27 :
V_111 = V_6 -> V_20 [ V_21 ] & 0x7f ;
if ( V_111 < 64 )
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] << V_111 ;
else
V_8 -> V_2 = 0 ;
goto V_131;
case 539 :
V_111 = V_6 -> V_20 [ V_21 ] & 0x7f ;
if ( V_111 < 64 )
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] >> V_111 ;
else
V_8 -> V_2 = 0 ;
goto V_131;
case 794 :
V_8 -> type = V_89 + V_90 + V_91 ;
V_111 = V_6 -> V_20 [ V_21 ] & 0x7f ;
V_112 = ( signed long int ) V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = V_112 >> ( V_111 < 64 ? V_111 : 63 ) ;
V_8 -> V_92 = V_6 -> V_84 ;
if ( V_112 < 0 && ( V_111 >= 64 || ( V_112 & ( ( 1ul << V_111 ) - 1 ) ) != 0 ) )
V_8 -> V_92 |= V_93 ;
else
V_8 -> V_92 &= ~ V_93 ;
goto V_131;
case 826 :
case 827 :
V_8 -> type = V_89 + V_90 + V_91 ;
V_111 = V_21 | ( ( V_4 & 2 ) << 4 ) ;
V_112 = ( signed long int ) V_6 -> V_20 [ V_85 ] ;
V_8 -> V_2 = V_112 >> V_111 ;
V_8 -> V_92 = V_6 -> V_84 ;
if ( V_112 < 0 && ( V_112 & ( ( 1ul << V_111 ) - 1 ) ) != 0 )
V_8 -> V_92 |= V_93 ;
else
V_8 -> V_92 &= ~ V_93 ;
goto V_131;
#endif
case 54 :
V_8 -> type = F_74 ( V_143 , V_144 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
return 0 ;
case 86 :
V_8 -> type = F_74 ( V_143 , V_145 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
return 0 ;
case 246 :
V_8 -> type = F_74 ( V_143 , V_146 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
V_8 -> V_43 = V_85 ;
return 0 ;
case 278 :
V_8 -> type = F_74 ( V_143 , V_146 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
V_8 -> V_43 = V_85 ;
return 0 ;
case 982 :
V_8 -> type = F_74 ( V_143 , V_147 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
return 0 ;
case 1014 :
V_8 -> type = F_74 ( V_143 , V_148 , 0 ) ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
return 0 ;
}
break;
}
V_8 -> type = V_118 ;
V_8 -> V_149 = V_19 ;
V_8 -> V_43 = V_85 ;
V_8 -> V_2 = V_6 -> V_20 [ V_85 ] ;
V_34 = ( V_4 >> 20 ) & V_150 ;
V_8 -> V_66 = 0 ;
switch ( V_106 ) {
case 31 :
V_34 = V_4 & V_150 ;
V_8 -> V_14 = F_10 ( V_4 , V_6 ) ;
switch ( ( V_4 >> 1 ) & 0x3ff ) {
case 20 :
V_8 -> type = F_74 ( V_151 , 0 , 4 ) ;
break;
case 150 :
V_8 -> type = F_74 ( V_152 , 0 , 4 ) ;
break;
#ifdef F_2
case 84 :
V_8 -> type = F_74 ( V_151 , 0 , 8 ) ;
break;
case 214 :
V_8 -> type = F_74 ( V_152 , 0 , 8 ) ;
break;
case 52 :
V_8 -> type = F_74 ( V_151 , 0 , 1 ) ;
break;
case 694 :
V_8 -> type = F_74 ( V_152 , 0 , 1 ) ;
break;
case 116 :
V_8 -> type = F_74 ( V_151 , 0 , 2 ) ;
break;
case 726 :
V_8 -> type = F_74 ( V_152 , 0 , 2 ) ;
break;
case 276 :
if ( ! ( ( V_85 & 1 ) || V_85 == V_19 || V_85 == V_21 ) )
V_8 -> type = F_74 ( V_151 , 0 , 16 ) ;
break;
case 182 :
if ( ! ( V_85 & 1 ) )
V_8 -> type = F_74 ( V_152 , 0 , 16 ) ;
break;
#endif
case 23 :
case 55 :
V_8 -> type = F_74 ( V_153 , V_34 , 4 ) ;
break;
case 87 :
case 119 :
V_8 -> type = F_74 ( V_153 , V_34 , 1 ) ;
break;
#ifdef F_75
case 7 :
V_8 -> type = F_74 ( V_154 , 0 , 1 ) ;
V_8 -> V_65 = 1 ;
break;
case 39 :
V_8 -> type = F_74 ( V_154 , 0 , 2 ) ;
V_8 -> V_65 = 2 ;
break;
case 71 :
V_8 -> type = F_74 ( V_154 , 0 , 4 ) ;
V_8 -> V_65 = 4 ;
break;
case 103 :
case 359 :
V_8 -> type = F_74 ( V_154 , 0 , 16 ) ;
V_8 -> V_65 = 16 ;
break;
case 135 :
V_8 -> type = F_74 ( V_155 , 0 , 1 ) ;
V_8 -> V_65 = 1 ;
break;
case 167 :
V_8 -> type = F_74 ( V_155 , 0 , 2 ) ;
V_8 -> V_65 = 2 ;
break;
case 199 :
V_8 -> type = F_74 ( V_155 , 0 , 4 ) ;
V_8 -> V_65 = 4 ;
break;
case 231 :
case 487 :
V_8 -> type = F_74 ( V_155 , 0 , 16 ) ;
break;
#endif
#ifdef F_2
case 21 :
case 53 :
V_8 -> type = F_74 ( V_153 , V_34 , 8 ) ;
break;
case 149 :
case 181 :
V_8 -> type = F_74 ( V_156 , V_34 , 8 ) ;
break;
#endif
case 151 :
case 183 :
V_8 -> type = F_74 ( V_156 , V_34 , 4 ) ;
break;
case 215 :
case 247 :
V_8 -> type = F_74 ( V_156 , V_34 , 1 ) ;
break;
case 279 :
case 311 :
V_8 -> type = F_74 ( V_153 , V_34 , 2 ) ;
break;
#ifdef F_2
case 341 :
case 373 :
V_8 -> type = F_74 ( V_153 , V_45 | V_34 , 4 ) ;
break;
#endif
case 343 :
case 375 :
V_8 -> type = F_74 ( V_153 , V_45 | V_34 , 2 ) ;
break;
case 407 :
case 439 :
V_8 -> type = F_74 ( V_156 , V_34 , 2 ) ;
break;
#ifdef F_2
case 532 :
V_8 -> type = F_74 ( V_153 , V_157 , 8 ) ;
break;
#endif
case 533 :
V_8 -> type = F_74 ( V_158 , 0 , V_6 -> V_84 & 0x7f ) ;
break;
case 534 :
V_8 -> type = F_74 ( V_153 , V_157 , 4 ) ;
break;
case 597 :
if ( V_21 == 0 )
V_21 = 32 ;
V_8 -> type = F_74 ( V_158 , 0 , V_21 ) ;
V_8 -> V_14 = V_19 ? V_6 -> V_20 [ V_19 ] : 0 ;
break;
#ifdef F_76
case 535 :
case 567 :
V_8 -> type = F_74 ( V_159 , V_34 | V_44 , 4 ) ;
break;
case 599 :
case 631 :
V_8 -> type = F_74 ( V_159 , V_34 , 8 ) ;
break;
case 663 :
case 695 :
V_8 -> type = F_74 ( V_160 , V_34 | V_44 , 4 ) ;
break;
case 727 :
case 759 :
V_8 -> type = F_74 ( V_160 , V_34 , 8 ) ;
break;
#ifdef F_2
case 791 :
V_8 -> type = F_74 ( V_159 , 0 , 16 ) ;
break;
case 855 :
V_8 -> type = F_74 ( V_159 , V_45 , 4 ) ;
break;
case 887 :
V_8 -> type = F_74 ( V_159 , 0 , 4 ) ;
break;
case 919 :
V_8 -> type = F_74 ( V_160 , 0 , 16 ) ;
break;
case 983 :
V_8 -> type = F_74 ( V_160 , 0 , 4 ) ;
break;
#endif
#endif
#ifdef F_2
case 660 :
V_8 -> type = F_74 ( V_156 , V_157 , 8 ) ;
V_8 -> V_2 = F_14 ( V_6 -> V_20 [ V_85 ] ) ;
break;
#endif
case 661 :
V_8 -> type = F_74 ( V_161 , 0 , V_6 -> V_84 & 0x7f ) ;
break;
case 662 :
V_8 -> type = F_74 ( V_156 , V_157 , 4 ) ;
V_8 -> V_2 = F_13 ( V_6 -> V_20 [ V_85 ] ) ;
break;
case 725 :
if ( V_21 == 0 )
V_21 = 32 ;
V_8 -> type = F_74 ( V_161 , 0 , V_21 ) ;
V_8 -> V_14 = V_19 ? V_6 -> V_20 [ V_19 ] : 0 ;
break;
case 790 :
V_8 -> type = F_74 ( V_153 , V_157 , 2 ) ;
break;
case 918 :
V_8 -> type = F_74 ( V_156 , V_157 , 2 ) ;
V_8 -> V_2 = F_12 ( V_6 -> V_20 [ V_85 ] ) ;
break;
#ifdef F_77
case 12 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
break;
case 76 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , V_45 , 4 ) ;
V_8 -> V_65 = 8 ;
break;
case 140 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
break;
case 268 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = V_164 ;
break;
case 269 :
case 301 : {
int V_15 ;
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> V_14 = V_19 ? V_6 -> V_20 [ V_19 ] : 0 ;
V_15 = V_6 -> V_20 [ V_21 ] & 0xff ;
if ( V_15 > 16 )
V_15 = 16 ;
V_8 -> type = F_74 ( V_162 , 0 , V_15 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = ( ( V_4 & 0x20 ) ? V_67 : 0 ) |
V_164 ;
break;
}
case 332 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 8 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_71 ;
break;
case 364 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 4 ) ;
V_8 -> V_65 = 4 ;
V_8 -> V_66 = V_71 | V_164 ;
break;
case 396 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = V_164 ;
break;
case 397 :
case 429 : {
int V_15 ;
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> V_14 = V_19 ? V_6 -> V_20 [ V_19 ] : 0 ;
V_15 = V_6 -> V_20 [ V_21 ] & 0xff ;
if ( V_15 > 16 )
V_15 = 16 ;
V_8 -> type = F_74 ( V_163 , 0 , V_15 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = ( ( V_4 & 0x20 ) ? V_67 : 0 ) |
V_164 ;
break;
}
case 524 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_68 ;
break;
case 588 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 8 ) ;
V_8 -> V_65 = 8 ;
break;
case 652 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_68 ;
break;
case 716 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 8 ) ;
V_8 -> V_65 = 8 ;
break;
case 780 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 4 ;
break;
case 781 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 1 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 812 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 2 ;
V_8 -> V_66 = V_164 ;
break;
case 813 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 2 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 844 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 8 ;
break;
case 876 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 1 ;
V_8 -> V_66 = V_164 ;
break;
case 908 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 4 ;
break;
case 909 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 1 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 940 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 2 ;
V_8 -> V_66 = V_164 ;
break;
case 941 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 2 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 972 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 8 ;
break;
case 1004 :
V_8 -> V_43 = V_85 | ( ( V_4 & 1 ) << 5 ) ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 1 ;
V_8 -> V_66 = V_164 ;
break;
#endif
}
break;
case 32 :
case 33 :
V_8 -> type = F_74 ( V_153 , V_34 , 4 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 34 :
case 35 :
V_8 -> type = F_74 ( V_153 , V_34 , 1 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 36 :
case 37 :
V_8 -> type = F_74 ( V_156 , V_34 , 4 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 38 :
case 39 :
V_8 -> type = F_74 ( V_156 , V_34 , 1 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 40 :
case 41 :
V_8 -> type = F_74 ( V_153 , V_34 , 2 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 42 :
case 43 :
V_8 -> type = F_74 ( V_153 , V_45 | V_34 , 2 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 44 :
case 45 :
V_8 -> type = F_74 ( V_156 , V_34 , 2 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 46 :
if ( V_19 >= V_85 )
break;
V_8 -> type = F_74 ( V_158 , 0 , 4 * ( 32 - V_85 ) ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 47 :
V_8 -> type = F_74 ( V_161 , 0 , 4 * ( 32 - V_85 ) ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
#ifdef F_76
case 48 :
case 49 :
V_8 -> type = F_74 ( V_159 , V_34 | V_44 , 4 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 50 :
case 51 :
V_8 -> type = F_74 ( V_159 , V_34 , 8 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 52 :
case 53 :
V_8 -> type = F_74 ( V_160 , V_34 | V_44 , 4 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
case 54 :
case 55 :
V_8 -> type = F_74 ( V_160 , V_34 , 8 ) ;
V_8 -> V_14 = F_7 ( V_4 , V_6 ) ;
break;
#endif
#ifdef F_2
case 56 :
if ( ! ( ( V_85 & 1 ) || ( V_85 == V_19 ) ) )
V_8 -> type = F_74 ( V_153 , 0 , 16 ) ;
V_8 -> V_14 = F_9 ( V_4 , V_6 ) ;
break;
#endif
#ifdef F_77
case 57 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
switch ( V_4 & 3 ) {
case 0 :
if ( V_85 & 1 )
break;
V_8 -> type = F_74 ( V_159 , 0 , 16 ) ;
break;
case 2 :
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_162 , 0 , 8 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 3 :
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_162 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_68 | V_164 ;
break;
}
break;
#endif
#ifdef F_2
case 58 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
switch ( V_4 & 3 ) {
case 0 :
V_8 -> type = F_74 ( V_153 , 0 , 8 ) ;
break;
case 1 :
V_8 -> type = F_74 ( V_153 , V_150 , 8 ) ;
break;
case 2 :
V_8 -> type = F_74 ( V_153 , V_45 , 4 ) ;
break;
}
break;
#endif
#ifdef F_77
case 61 :
switch ( V_4 & 7 ) {
case 0 :
case 4 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
V_8 -> type = F_74 ( V_160 , 0 , 16 ) ;
break;
case 1 :
V_8 -> V_14 = F_9 ( V_4 , V_6 ) ;
if ( V_4 & 8 )
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_162 , 0 , 16 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = V_164 ;
break;
case 2 :
case 6 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_163 , 0 , 8 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_164 ;
break;
case 3 :
case 7 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_163 , 0 , 4 ) ;
V_8 -> V_65 = 8 ;
V_8 -> V_66 = V_68 | V_164 ;
break;
case 5 :
V_8 -> V_14 = F_9 ( V_4 , V_6 ) ;
if ( V_4 & 8 )
V_8 -> V_43 = V_85 + 32 ;
V_8 -> type = F_74 ( V_163 , 0 , 16 ) ;
V_8 -> V_65 = 16 ;
V_8 -> V_66 = V_164 ;
break;
}
break;
#endif
#ifdef F_2
case 62 :
V_8 -> V_14 = F_8 ( V_4 , V_6 ) ;
switch ( V_4 & 3 ) {
case 0 :
V_8 -> type = F_74 ( V_156 , 0 , 8 ) ;
break;
case 1 :
V_8 -> type = F_74 ( V_156 , V_150 , 8 ) ;
break;
case 2 :
if ( ! ( V_85 & 1 ) )
V_8 -> type = F_74 ( V_156 , 0 , 16 ) ;
break;
}
break;
#endif
}
return 0 ;
V_131:
if ( V_4 & 1 )
F_53 ( V_6 , V_8 ) ;
V_132:
V_8 -> V_43 = V_19 ;
V_8 -> type |= V_90 ;
return 1 ;
V_142:
if ( V_4 & 1 )
F_53 ( V_6 , V_8 ) ;
V_130:
V_8 -> V_43 = V_85 ;
V_8 -> type |= V_90 ;
return 1 ;
V_121:
V_8 -> type = V_165 | 0x700 ;
V_8 -> V_2 = V_166 ;
return 0 ;
V_129:
V_8 -> type = V_165 | 0x700 ;
V_8 -> V_2 = V_167 ;
return 0 ;
}
static T_1 int F_78 ( unsigned long V_14 , struct V_5 * V_6 )
{
#ifdef F_79
if ( V_14 - V_168 <= V_47 -> V_48 . V_169 ) {
F_80 ( V_170 L_1 ) ;
return - V_171 ;
}
#endif
F_81 ( F_82 ( V_172 ) ) ;
F_83 ( V_172 ) ;
return 0 ;
}
static T_1 void F_84 ( unsigned long * V_173 , int V_50 )
{
switch ( V_50 ) {
case 2 :
* V_173 = ( signed short ) * V_173 ;
break;
case 4 :
* V_173 = ( signed int ) * V_173 ;
break;
}
}
static T_1 void F_85 ( unsigned long * V_173 , int V_50 )
{
switch ( V_50 ) {
case 2 :
* V_173 = F_12 ( * V_173 ) ;
break;
case 4 :
* V_173 = F_13 ( * V_173 ) ;
break;
#ifdef F_2
case 8 :
* V_173 = F_14 ( * V_173 ) ;
break;
#endif
}
}
void F_86 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_174 ;
V_174 = F_1 ( V_6 -> V_1 , V_6 -> V_114 + 4 ) ;
switch ( V_8 -> type & V_175 ) {
case V_89 :
if ( V_8 -> type & V_90 )
V_6 -> V_20 [ V_8 -> V_43 ] = V_8 -> V_2 ;
if ( V_8 -> type & V_82 )
V_6 -> V_13 = V_8 -> V_83 ;
if ( V_8 -> type & V_91 )
V_6 -> V_84 = V_8 -> V_92 ;
break;
case V_113 :
if ( V_8 -> type & V_115 )
V_6 -> V_119 = V_174 ;
if ( V_8 -> type & V_116 )
V_174 = V_8 -> V_2 ;
if ( V_8 -> type & V_11 )
-- V_6 -> V_12 ;
break;
case V_123 :
switch ( V_8 -> type & V_176 ) {
case V_125 :
V_109 () ;
break;
case V_124 :
F_87 () ;
break;
case V_128 :
F_88 () ;
break;
case V_126 :
asm volatile("lwsync" : : : "memory");
break;
case V_127 :
asm volatile("ptesync" : : : "memory");
break;
}
break;
case V_137 :
switch ( V_8 -> V_107 ) {
case V_138 :
V_6 -> V_20 [ V_8 -> V_43 ] = V_6 -> V_84 & 0xffffffffUL ;
break;
case V_139 :
V_6 -> V_20 [ V_8 -> V_43 ] = V_6 -> V_119 ;
break;
case V_140 :
V_6 -> V_20 [ V_8 -> V_43 ] = V_6 -> V_12 ;
break;
default:
F_16 ( 1 ) ;
}
break;
case V_141 :
switch ( V_8 -> V_107 ) {
case V_138 :
V_6 -> V_84 = V_8 -> V_2 & 0xffffffffUL ;
break;
case V_139 :
V_6 -> V_119 = V_8 -> V_2 ;
break;
case V_140 :
V_6 -> V_12 = V_8 -> V_2 ;
break;
default:
F_16 ( 1 ) ;
}
break;
default:
F_16 ( 1 ) ;
}
V_6 -> V_114 = V_174 ;
}
int F_89 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
int V_29 , V_50 , type ;
int V_35 , V_85 , V_15 ;
unsigned int V_177 ;
unsigned long V_2 ;
unsigned long V_14 ;
bool V_38 ;
V_29 = 0 ;
V_50 = F_28 ( V_8 -> type ) ;
type = V_8 -> type & V_175 ;
V_38 = ( V_6 -> V_1 & V_136 ) != ( V_178 & V_136 ) ;
V_14 = F_1 ( V_6 -> V_1 , V_8 -> V_14 ) ;
switch ( type ) {
case V_151 :
if ( V_14 & ( V_50 - 1 ) )
return - V_179 ;
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
V_29 = 0 ;
V_2 = 0 ;
switch ( V_50 ) {
#ifdef F_2
case 1 :
F_90 ( V_2 , V_14 , V_29 , L_2 ) ;
break;
case 2 :
F_90 ( V_2 , V_14 , V_29 , L_3 ) ;
break;
#endif
case 4 :
F_90 ( V_2 , V_14 , V_29 , L_4 ) ;
break;
#ifdef F_2
case 8 :
F_90 ( V_2 , V_14 , V_29 , L_5 ) ;
break;
case 16 :
V_29 = F_91 ( V_14 , & V_6 -> V_20 [ V_8 -> V_43 ] ) ;
break;
#endif
default:
return - V_171 ;
}
if ( V_29 ) {
V_6 -> V_17 = V_14 ;
break;
}
if ( V_50 < 16 )
V_6 -> V_20 [ V_8 -> V_43 ] = V_2 ;
break;
case V_152 :
if ( V_14 & ( V_50 - 1 ) )
return - V_179 ;
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
V_29 = 0 ;
switch ( V_50 ) {
#ifdef F_2
case 1 :
F_92 ( V_8 -> V_2 , V_14 , V_29 , L_6 , V_177 ) ;
break;
case 2 :
F_92 ( V_8 -> V_2 , V_14 , V_29 , L_6 , V_177 ) ;
break;
#endif
case 4 :
F_92 ( V_8 -> V_2 , V_14 , V_29 , L_7 , V_177 ) ;
break;
#ifdef F_2
case 8 :
F_92 ( V_8 -> V_2 , V_14 , V_29 , L_8 , V_177 ) ;
break;
case 16 :
V_29 = F_93 ( V_14 , V_6 -> V_20 [ V_8 -> V_43 ] ,
V_6 -> V_20 [ V_8 -> V_43 + 1 ] , & V_177 ) ;
break;
#endif
default:
return - V_171 ;
}
if ( ! V_29 )
V_6 -> V_13 = ( V_6 -> V_13 & 0x0fffffff ) |
( V_177 & 0xe0000000 ) |
( ( V_6 -> V_84 >> 3 ) & 0x10000000 ) ;
else
V_6 -> V_17 = V_14 ;
break;
case V_153 :
#ifdef F_2
if ( V_50 == 16 ) {
V_29 = F_42 ( V_6 , V_14 , V_8 -> V_43 , V_38 ) ;
break;
}
#endif
V_29 = F_21 ( & V_6 -> V_20 [ V_8 -> V_43 ] , V_14 , V_50 , V_6 ) ;
if ( ! V_29 ) {
if ( V_8 -> type & V_45 )
F_84 ( & V_6 -> V_20 [ V_8 -> V_43 ] , V_50 ) ;
if ( ( V_8 -> type & V_157 ) == ( V_38 ? 0 : V_157 ) )
F_85 ( & V_6 -> V_20 [ V_8 -> V_43 ] , V_50 ) ;
}
break;
#ifdef F_76
case V_159 :
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_46 ) )
return 0 ;
V_29 = F_27 ( V_8 , V_14 , V_6 , V_38 ) ;
break;
#endif
#ifdef F_75
case V_154 :
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_52 ) )
return 0 ;
V_29 = F_38 ( V_8 -> V_43 , V_14 , V_50 , V_6 , V_38 ) ;
break;
#endif
#ifdef F_77
case V_162 : {
unsigned long V_180 = V_181 ;
if ( V_8 -> V_43 >= 32 && ( V_8 -> V_66 & V_164 ) )
V_180 = V_52 ;
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_180 ) )
return 0 ;
V_29 = F_48 ( V_8 , V_14 , V_6 , V_38 ) ;
break;
}
#endif
case V_158 :
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
V_85 = V_8 -> V_43 ;
for ( V_35 = 0 ; V_35 < V_50 ; V_35 += 4 ) {
unsigned int V_182 = 0 ;
V_15 = V_50 - V_35 ;
if ( V_15 > 4 )
V_15 = 4 ;
V_29 = F_19 ( ( T_2 * ) & V_182 , V_14 , V_15 , V_6 ) ;
if ( V_29 )
break;
if ( F_29 ( V_38 ) )
V_182 = F_13 ( V_182 ) ;
V_6 -> V_20 [ V_85 ] = V_182 ;
V_14 += 4 ;
V_85 = ( V_85 + 1 ) & 0x1f ;
}
break;
case V_156 :
#ifdef F_2
if ( V_50 == 16 ) {
V_29 = F_44 ( V_6 , V_14 , V_8 -> V_43 , V_38 ) ;
break;
}
#endif
if ( ( V_8 -> type & V_150 ) && V_50 == sizeof( long ) &&
V_8 -> V_43 == 1 && V_8 -> V_149 == 1 &&
! ( V_6 -> V_1 & V_120 ) &&
V_14 >= V_6 -> V_20 [ 1 ] - V_168 ) {
V_29 = F_78 ( V_14 , V_6 ) ;
break;
}
if ( F_29 ( V_38 ) )
F_85 ( & V_8 -> V_2 , V_50 ) ;
V_29 = F_26 ( V_8 -> V_2 , V_14 , V_50 , V_6 ) ;
break;
#ifdef F_76
case V_160 :
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_46 ) )
return 0 ;
V_29 = F_35 ( V_8 , V_14 , V_6 , V_38 ) ;
break;
#endif
#ifdef F_75
case V_155 :
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_52 ) )
return 0 ;
V_29 = F_40 ( V_8 -> V_43 , V_14 , V_50 , V_6 , V_38 ) ;
break;
#endif
#ifdef F_77
case V_163 : {
unsigned long V_180 = V_181 ;
if ( V_8 -> V_43 >= 32 && ( V_8 -> V_66 & V_164 ) )
V_180 = V_52 ;
if ( ! ( V_6 -> V_1 & V_120 ) && ! ( V_6 -> V_1 & V_180 ) )
return 0 ;
V_29 = F_50 ( V_8 , V_14 , V_6 , V_38 ) ;
break;
}
#endif
case V_161 :
if ( ! F_4 ( V_6 , V_14 , V_50 ) )
return - V_37 ;
V_85 = V_8 -> V_43 ;
for ( V_35 = 0 ; V_35 < V_50 ; V_35 += 4 ) {
unsigned int V_182 = V_6 -> V_20 [ V_85 ] ;
V_15 = V_50 - V_35 ;
if ( V_15 > 4 )
V_15 = 4 ;
if ( F_29 ( V_38 ) )
V_182 = F_13 ( V_182 ) ;
V_29 = F_24 ( ( T_2 * ) & V_182 , V_14 , V_15 , V_6 ) ;
if ( V_29 )
break;
V_14 += 4 ;
V_85 = ( V_85 + 1 ) & 0x1f ;
}
break;
default:
return - V_171 ;
}
if ( V_29 )
return V_29 ;
if ( V_8 -> type & V_150 )
V_6 -> V_20 [ V_8 -> V_149 ] = V_8 -> V_14 ;
return 0 ;
}
int F_94 ( struct V_5 * V_6 , unsigned int V_4 )
{
struct V_7 V_8 ;
int V_183 , V_29 , type ;
unsigned long V_2 ;
unsigned long V_14 ;
V_183 = F_63 ( & V_8 , V_6 , V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
if ( V_183 > 0 ) {
F_86 ( V_6 , & V_8 ) ;
return 1 ;
}
V_29 = 0 ;
type = V_8 . type & V_175 ;
if ( F_95 ( type ) ) {
V_29 = F_89 ( V_6 , & V_8 ) ;
if ( V_29 )
return 0 ;
goto V_184;
}
switch ( type ) {
case V_143 :
V_14 = F_1 ( V_6 -> V_1 , V_8 . V_14 ) ;
if ( ! F_4 ( V_6 , V_14 , 8 ) )
return 0 ;
switch ( V_8 . type & V_185 ) {
case V_144 :
F_96 ( V_14 , V_29 , L_9 ) ;
break;
case V_145 :
F_96 ( V_14 , V_29 , L_10 ) ;
break;
case V_146 :
if ( V_8 . V_43 == 0 )
F_97 ( ( void * ) V_14 ) ;
break;
case V_186 :
if ( V_8 . V_43 == 0 )
F_98 ( ( void * ) V_14 ) ;
break;
case V_147 :
F_96 ( V_14 , V_29 , L_11 ) ;
break;
case V_148 :
V_29 = F_52 ( V_14 , V_6 ) ;
break;
}
if ( V_29 ) {
V_6 -> V_17 = V_14 ;
return 0 ;
}
goto V_184;
case V_133 :
V_6 -> V_20 [ V_8 . V_43 ] = V_6 -> V_1 & V_187 ;
goto V_184;
case V_134 :
V_2 = V_6 -> V_20 [ V_8 . V_43 ] ;
if ( ( V_2 & V_188 ) == 0 )
return - 1 ;
V_6 -> V_1 = ( V_6 -> V_1 & ~ V_8 . V_2 ) | ( V_2 & V_8 . V_2 ) ;
goto V_184;
#ifdef F_64
case V_117 :
if ( V_6 -> V_20 [ 0 ] == 0x1ebe &&
F_99 ( V_189 ) ) {
V_6 -> V_1 ^= V_136 ;
goto V_184;
}
V_6 -> V_20 [ 9 ] = V_6 -> V_20 [ 13 ] ;
V_6 -> V_20 [ 10 ] = V_178 ;
V_6 -> V_20 [ 11 ] = V_6 -> V_114 + 4 ;
V_6 -> V_20 [ 12 ] = V_6 -> V_1 & V_187 ;
V_6 -> V_20 [ 13 ] = ( unsigned long ) F_100 () ;
V_6 -> V_114 = ( unsigned long ) & V_190 ;
V_6 -> V_1 = V_178 ;
return 1 ;
case V_122 :
return - 1 ;
#endif
}
return 0 ;
V_184:
V_6 -> V_114 = F_1 ( V_6 -> V_1 , V_6 -> V_114 + 4 ) ;
return 1 ;
}
