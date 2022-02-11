unsigned long long F_1 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
unsigned long long V_4 ;
unsigned int V_5 ;
V_1 = F_2 ( V_1 , & V_3 ) ;
V_5 = F_3 ( V_1 , V_3 , & V_4 ) ;
V_1 += ( V_5 & ~ V_6 ) ;
if ( V_2 )
* V_2 = ( char * ) V_1 ;
return V_4 ;
}
unsigned long F_4 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
return F_1 ( V_1 , V_2 , V_3 ) ;
}
long F_5 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
if ( * V_1 == '-' )
return - F_4 ( V_1 + 1 , V_2 , V_3 ) ;
return F_4 ( V_1 , V_2 , V_3 ) ;
}
long long F_6 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
if ( * V_1 == '-' )
return - F_1 ( V_1 + 1 , V_2 , V_3 ) ;
return F_1 ( V_1 , V_2 , V_3 ) ;
}
static T_1
int F_7 ( const char * * V_7 )
{
int V_8 = 0 ;
while ( isdigit ( * * V_7 ) )
V_8 = V_8 * 10 + * ( ( * V_7 ) ++ ) - '0' ;
return V_8 ;
}
static T_1
char * F_8 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 ;
V_11 = ( V_10 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
V_11 = ( V_10 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
V_11 = ( V_10 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * 0x199a ) >> 16 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
V_11 = ( V_10 * 0xcd ) >> 11 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * 0xcd ) >> 11 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
* V_9 ++ = V_10 + '0' ;
return V_9 ;
}
static T_1
char * F_9 ( char * V_9 , unsigned V_11 )
{
unsigned V_10 ;
while ( V_11 >= 10000 ) {
V_10 = V_11 + '0' ;
V_11 = ( V_11 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = V_10 - 10 * V_11 ;
}
V_10 = ( V_11 * 0x199a ) >> 16 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
if ( V_10 == 0 )
return V_9 ;
V_11 = ( V_10 * 0xcd ) >> 11 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
if ( V_11 == 0 )
return V_9 ;
V_10 = ( V_11 * 0xcd ) >> 11 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
if ( V_10 == 0 )
return V_9 ;
* V_9 ++ = V_10 + '0' ;
return V_9 ;
}
static
char * F_10 ( char * V_9 , unsigned long long V_13 )
{
if ( V_13 >= 100 * 1000 * 1000 ) {
while ( V_13 >= 1000 * 1000 * 1000 )
V_9 = F_8 ( V_9 , F_11 ( V_13 , 1000 * 1000 * 1000 ) ) ;
if ( V_13 >= 100 * 1000 * 1000 )
return F_8 ( V_9 , V_13 ) ;
}
return F_9 ( V_9 , V_13 ) ;
}
static T_1
void F_12 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 ;
V_11 = ( V_10 * 0xccd ) >> 15 ;
V_9 [ 0 ] = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * 0xcd ) >> 11 ;
V_9 [ 1 ] = ( V_11 - 10 * V_10 ) + '0' ;
V_11 = ( V_10 * 0xcd ) >> 11 ;
V_9 [ 2 ] = ( V_10 - 10 * V_11 ) + '0' ;
V_9 [ 3 ] = V_11 + '0' ;
}
static
unsigned F_13 ( char * V_9 , unsigned V_14 )
{
T_2 V_10 = ( V_14 * ( V_12 ) 0x346DC5D7 ) >> 43 ;
F_12 ( V_9 , V_14 - V_10 * 10000 ) ;
return V_10 ;
}
static
char * F_10 ( char * V_9 , unsigned long long V_13 )
{
T_2 V_15 , V_16 , V_17 , V_10 , V_18 ;
if ( V_13 < 100 * 1000 * 1000 )
return F_9 ( V_9 , V_13 ) ;
V_17 = ( ( T_2 ) V_13 >> 16 ) ;
V_18 = ( V_13 >> 32 ) ;
V_16 = ( V_18 ) & 0xffff ;
V_15 = ( V_18 >> 16 ) ;
V_10 = 656 * V_15 + 7296 * V_16 + 5536 * V_17 + ( ( T_2 ) V_13 & 0xffff ) ;
V_10 = F_13 ( V_9 , V_10 ) ;
V_10 += 7671 * V_15 + 9496 * V_16 + 6 * V_17 ;
V_10 = F_13 ( V_9 + 4 , V_10 ) ;
V_10 += 4749 * V_15 + 42 * V_16 ;
V_10 = F_13 ( V_9 + 8 , V_10 ) ;
V_10 += 281 * V_15 ;
V_9 += 12 ;
if ( V_10 )
V_9 = F_9 ( V_9 , V_10 ) ;
else while ( V_9 [ - 1 ] == '0' )
-- V_9 ;
return V_9 ;
}
int F_14 ( char * V_9 , int V_19 , unsigned long long V_20 )
{
char V_21 [ sizeof( V_20 ) * 3 ] ;
int V_22 , V_23 ;
if ( V_20 <= 9 ) {
V_21 [ 0 ] = '0' + V_20 ;
V_23 = 1 ;
} else {
V_23 = F_10 ( V_21 , V_20 ) - V_21 ;
}
if ( V_23 > V_19 )
return 0 ;
for ( V_22 = 0 ; V_22 < V_23 ; ++ V_22 )
V_9 [ V_22 ] = V_21 [ V_23 - V_22 - 1 ] ;
return V_23 ;
}
static T_1
char * F_15 ( char * V_9 , char * V_24 , unsigned long long V_20 ,
struct V_25 V_26 )
{
static const char V_27 [ 16 ] = L_1 ;
char V_21 [ 66 ] ;
char V_28 ;
char V_29 ;
int V_30 = ( ( V_26 . V_31 & V_32 ) && V_26 . V_3 != 10 ) ;
int V_8 ;
bool V_33 = V_20 == 0LL ;
V_29 = ( V_26 . V_31 & V_34 ) ;
if ( V_26 . V_31 & V_35 )
V_26 . V_31 &= ~ V_36 ;
V_28 = 0 ;
if ( V_26 . V_31 & V_37 ) {
if ( ( signed long long ) V_20 < 0 ) {
V_28 = '-' ;
V_20 = - ( signed long long ) V_20 ;
V_26 . V_38 -- ;
} else if ( V_26 . V_31 & V_39 ) {
V_28 = '+' ;
V_26 . V_38 -- ;
} else if ( V_26 . V_31 & V_40 ) {
V_28 = ' ' ;
V_26 . V_38 -- ;
}
}
if ( V_30 ) {
if ( V_26 . V_3 == 16 )
V_26 . V_38 -= 2 ;
else if ( ! V_33 )
V_26 . V_38 -- ;
}
V_8 = 0 ;
if ( V_20 < V_26 . V_3 )
V_21 [ V_8 ++ ] = V_27 [ V_20 ] | V_29 ;
else if ( V_26 . V_3 != 10 ) {
int V_41 = V_26 . V_3 - 1 ;
int V_42 = 3 ;
if ( V_26 . V_3 == 16 )
V_42 = 4 ;
do {
V_21 [ V_8 ++ ] = ( V_27 [ ( ( unsigned char ) V_20 ) & V_41 ] | V_29 ) ;
V_20 >>= V_42 ;
} while ( V_20 );
} else {
V_8 = F_10 ( V_21 , V_20 ) - V_21 ;
}
if ( V_8 > V_26 . V_43 )
V_26 . V_43 = V_8 ;
V_26 . V_38 -= V_26 . V_43 ;
if ( ! ( V_26 . V_31 & ( V_36 + V_35 ) ) ) {
while ( -- V_26 . V_38 >= 0 ) {
if ( V_9 < V_24 )
* V_9 = ' ' ;
++ V_9 ;
}
}
if ( V_28 ) {
if ( V_9 < V_24 )
* V_9 = V_28 ;
++ V_9 ;
}
if ( V_30 ) {
if ( V_26 . V_3 == 16 || ! V_33 ) {
if ( V_9 < V_24 )
* V_9 = '0' ;
++ V_9 ;
}
if ( V_26 . V_3 == 16 ) {
if ( V_9 < V_24 )
* V_9 = ( 'X' | V_29 ) ;
++ V_9 ;
}
}
if ( ! ( V_26 . V_31 & V_35 ) ) {
char V_44 = ( V_26 . V_31 & V_36 ) ? '0' : ' ' ;
while ( -- V_26 . V_38 >= 0 ) {
if ( V_9 < V_24 )
* V_9 = V_44 ;
++ V_9 ;
}
}
while ( V_8 <= -- V_26 . V_43 ) {
if ( V_9 < V_24 )
* V_9 = '0' ;
++ V_9 ;
}
while ( -- V_8 >= 0 ) {
if ( V_9 < V_24 )
* V_9 = V_21 [ V_8 ] ;
++ V_9 ;
}
while ( -- V_26 . V_38 >= 0 ) {
if ( V_9 < V_24 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * string ( char * V_9 , char * V_24 , const char * V_7 , struct V_25 V_26 )
{
int V_23 , V_8 ;
if ( ( unsigned long ) V_7 < V_45 )
V_7 = L_2 ;
V_23 = F_16 ( V_7 , V_26 . V_43 ) ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( V_23 < V_26 . V_38 -- ) {
if ( V_9 < V_24 )
* V_9 = ' ' ;
++ V_9 ;
}
}
for ( V_8 = 0 ; V_8 < V_23 ; ++ V_8 ) {
if ( V_9 < V_24 )
* V_9 = * V_7 ;
++ V_9 ; ++ V_7 ;
}
while ( V_23 < V_26 . V_38 -- ) {
if ( V_9 < V_24 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static void F_17 ( char * V_9 , char * V_24 , unsigned V_23 , unsigned V_46 )
{
T_3 V_19 ;
if ( V_9 >= V_24 )
return;
V_19 = V_24 - V_9 ;
if ( V_19 <= V_46 ) {
memset ( V_9 , ' ' , V_19 ) ;
return;
}
if ( V_23 ) {
if ( V_23 > V_19 - V_46 )
V_23 = V_19 - V_46 ;
memmove ( V_9 + V_46 , V_9 , V_23 ) ;
}
memset ( V_9 , ' ' , V_46 ) ;
}
static T_1
char * F_18 ( char * V_9 , char * V_24 , const struct V_47 * V_48 , struct V_25 V_26 ,
const char * V_49 )
{
const char * V_50 [ 4 ] , * V_7 ;
const struct V_47 * V_51 ;
int V_52 ;
int V_8 , V_13 ;
switch ( V_49 [ 1 ] ) {
case '2' : case '3' : case '4' :
V_52 = V_49 [ 1 ] - '0' ;
break;
default:
V_52 = 1 ;
}
F_19 () ;
for ( V_8 = 0 ; V_8 < V_52 ; V_8 ++ , V_48 = V_51 ) {
V_51 = F_20 ( V_48 -> V_53 ) ;
V_50 [ V_8 ] = F_20 ( V_48 -> V_54 . V_55 ) ;
if ( V_51 == V_48 ) {
if ( V_8 )
V_50 [ V_8 ] = L_3 ;
V_8 ++ ;
break;
}
}
V_7 = V_50 [ -- V_8 ] ;
for ( V_13 = 0 ; V_13 != V_26 . V_43 ; V_13 ++ , V_9 ++ ) {
char V_44 = * V_7 ++ ;
if ( ! V_44 ) {
if ( ! V_8 )
break;
V_44 = '/' ;
V_7 = V_50 [ -- V_8 ] ;
}
if ( V_9 < V_24 )
* V_9 = V_44 ;
}
F_21 () ;
if ( V_13 < V_26 . V_38 ) {
unsigned V_46 = V_26 . V_38 - V_13 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
F_17 ( V_9 - V_13 , V_24 , V_13 , V_46 ) ;
return V_9 + V_46 ;
}
while ( V_46 -- ) {
if ( V_9 < V_24 )
* V_9 = ' ' ;
++ V_9 ;
}
}
return V_9 ;
}
static T_1
char * F_22 ( char * V_9 , char * V_24 , void * V_56 ,
struct V_25 V_26 , const char * V_49 )
{
unsigned long V_57 ;
#ifdef F_23
char V_58 [ V_59 ] ;
#endif
if ( V_49 [ 1 ] == 'R' )
V_56 = F_24 ( V_56 ) ;
V_57 = ( unsigned long ) V_56 ;
#ifdef F_23
if ( * V_49 == 'B' )
F_25 ( V_58 , V_57 ) ;
else if ( * V_49 != 'f' && * V_49 != 's' )
F_26 ( V_58 , V_57 ) ;
else
F_27 ( V_58 , V_57 ) ;
return string ( V_9 , V_24 , V_58 , V_26 ) ;
#else
V_26 . V_38 = 2 * sizeof( void * ) ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , V_57 , V_26 ) ;
#endif
}
static T_1
char * F_28 ( char * V_9 , char * V_24 , struct V_60 * V_61 ,
struct V_25 V_26 , const char * V_49 )
{
#ifndef F_29
#define F_29 6
#endif
#ifndef F_30
#define F_30 10
#endif
static const struct V_25 V_62 = {
. V_3 = 16 ,
. V_38 = F_29 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_63 = {
. V_3 = 16 ,
. V_38 = F_30 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_64 = {
. V_3 = 16 ,
. V_38 = 2 ,
. V_43 = - 1 ,
. V_31 = V_34 | V_36 ,
} ;
static const struct V_25 V_65 = {
. V_3 = 10 ,
. V_43 = - 1 ,
. V_31 = 0 ,
} ;
static const struct V_25 V_66 = {
. V_38 = - 1 ,
. V_43 = 10 ,
. V_31 = V_35 ,
} ;
static const struct V_25 V_67 = {
. V_3 = 16 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 ,
} ;
#define F_31 ((2 * sizeof(resource_size_t)) + 4)
#define F_32 (2 * sizeof(res->flags))
#define F_33 sizeof("[mem - 64bit pref window disabled]")
#define F_34 sizeof("[mem - flags 0x]")
char V_58 [ F_35 ( 2 * F_31 + F_33 ,
2 * F_31 + F_32 + F_34 ) ] ;
char * V_51 = V_58 , * V_68 = V_58 + sizeof( V_58 ) ;
int V_69 = ( V_49 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_25 * V_70 ;
* V_51 ++ = '[' ;
if ( V_61 -> V_31 & V_71 ) {
V_51 = string ( V_51 , V_68 , L_4 , V_66 ) ;
V_70 = & V_62 ;
} else if ( V_61 -> V_31 & V_72 ) {
V_51 = string ( V_51 , V_68 , L_5 , V_66 ) ;
V_70 = & V_63 ;
} else if ( V_61 -> V_31 & V_73 ) {
V_51 = string ( V_51 , V_68 , L_6 , V_66 ) ;
V_70 = & V_65 ;
} else if ( V_61 -> V_31 & V_74 ) {
V_51 = string ( V_51 , V_68 , L_7 , V_66 ) ;
V_70 = & V_65 ;
} else if ( V_61 -> V_31 & V_75 ) {
V_51 = string ( V_51 , V_68 , L_8 , V_66 ) ;
V_70 = & V_64 ;
} else {
V_51 = string ( V_51 , V_68 , L_9 , V_66 ) ;
V_70 = & V_63 ;
V_69 = 0 ;
}
if ( V_69 && V_61 -> V_31 & V_76 ) {
V_51 = string ( V_51 , V_68 , L_10 , V_66 ) ;
V_51 = F_15 ( V_51 , V_68 , F_36 ( V_61 ) , * V_70 ) ;
} else {
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_77 , * V_70 ) ;
if ( V_61 -> V_77 != V_61 -> V_24 ) {
* V_51 ++ = '-' ;
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_24 , * V_70 ) ;
}
}
if ( V_69 ) {
if ( V_61 -> V_31 & V_78 )
V_51 = string ( V_51 , V_68 , L_11 , V_66 ) ;
if ( V_61 -> V_31 & V_79 )
V_51 = string ( V_51 , V_68 , L_12 , V_66 ) ;
if ( V_61 -> V_31 & V_80 )
V_51 = string ( V_51 , V_68 , L_13 , V_66 ) ;
if ( V_61 -> V_31 & V_81 )
V_51 = string ( V_51 , V_68 , L_14 , V_66 ) ;
} else {
V_51 = string ( V_51 , V_68 , L_15 , V_66 ) ;
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_31 , V_67 ) ;
}
* V_51 ++ = ']' ;
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_58 , V_26 ) ;
}
static T_1
char * F_37 ( char * V_9 , char * V_24 , T_4 * V_82 , struct V_25 V_26 ,
const char * V_49 )
{
int V_8 , V_23 = 1 ;
char V_83 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_38 ( V_82 ) )
return string ( V_9 , V_24 , NULL , V_26 ) ;
switch ( V_49 [ 1 ] ) {
case 'C' :
V_83 = ':' ;
break;
case 'D' :
V_83 = '-' ;
break;
case 'N' :
V_83 = 0 ;
break;
default:
V_83 = ' ' ;
break;
}
if ( V_26 . V_38 > 0 )
V_23 = F_39 ( int , V_26 . V_38 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_23 && V_9 < V_24 - 1 ; V_8 ++ ) {
V_9 = F_40 ( V_9 , V_82 [ V_8 ] ) ;
if ( V_9 < V_24 && V_83 && V_8 != V_23 - 1 )
* V_9 ++ = V_83 ;
}
return V_9 ;
}
static T_1
char * F_41 ( char * V_9 , char * V_24 , T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_84 [ sizeof( L_16 ) ] ;
char * V_51 = V_84 ;
int V_8 ;
char V_83 ;
bool V_85 = false ;
switch ( V_49 [ 1 ] ) {
case 'F' :
V_83 = '-' ;
break;
case 'R' :
V_85 = true ;
default:
V_83 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_85 )
V_51 = F_40 ( V_51 , V_82 [ 5 - V_8 ] ) ;
else
V_51 = F_40 ( V_51 , V_82 [ V_8 ] ) ;
if ( V_49 [ 0 ] == 'M' && V_8 != 5 )
* V_51 ++ = V_83 ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_84 , V_26 ) ;
}
static T_1
char * F_42 ( char * V_51 , const T_4 * V_82 , const char * V_49 )
{
int V_8 ;
bool V_86 = ( V_49 [ 0 ] == 'i' ) ;
int V_87 ;
int V_88 ;
switch ( V_49 [ 2 ] ) {
case 'h' :
#ifdef F_43
V_87 = 0 ;
V_88 = 1 ;
#else
V_87 = 3 ;
V_88 = - 1 ;
#endif
break;
case 'l' :
V_87 = 3 ;
V_88 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_87 = 0 ;
V_88 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_89 [ 3 ] ;
int V_27 = F_9 ( V_89 , V_82 [ V_87 ] ) - V_89 ;
if ( V_86 ) {
if ( V_27 < 3 )
* V_51 ++ = '0' ;
if ( V_27 < 2 )
* V_51 ++ = '0' ;
}
while ( V_27 -- )
* V_51 ++ = V_89 [ V_27 ] ;
if ( V_8 < 3 )
* V_51 ++ = '.' ;
V_87 += V_88 ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_44 ( char * V_51 , const char * V_82 )
{
int V_8 , V_90 , V_91 ;
unsigned char V_92 [ 8 ] ;
int V_93 = 1 ;
int V_94 = - 1 ;
T_5 V_95 ;
T_4 V_96 , V_97 ;
bool V_98 = false ;
bool V_99 ;
struct V_100 V_101 ;
memcpy ( & V_101 , V_82 , sizeof( struct V_100 ) ) ;
V_99 = F_45 ( & V_101 ) || F_46 ( & V_101 ) ;
memset ( V_92 , 0 , sizeof( V_92 ) ) ;
if ( V_99 )
V_91 = 6 ;
else
V_91 = 8 ;
for ( V_8 = 0 ; V_8 < V_91 ; V_8 ++ ) {
for ( V_90 = V_8 ; V_90 < V_91 ; V_90 ++ ) {
if ( V_101 . V_102 [ V_90 ] != 0 )
break;
V_92 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_91 ; V_8 ++ ) {
if ( V_92 [ V_8 ] > V_93 ) {
V_93 = V_92 [ V_8 ] ;
V_94 = V_8 ;
}
}
if ( V_93 == 1 )
V_94 = - 1 ;
for ( V_8 = 0 ; V_8 < V_91 ; V_8 ++ ) {
if ( V_8 == V_94 ) {
if ( V_98 || V_8 == 0 )
* V_51 ++ = ':' ;
* V_51 ++ = ':' ;
V_98 = false ;
V_8 += V_93 - 1 ;
continue;
}
if ( V_98 ) {
* V_51 ++ = ':' ;
V_98 = false ;
}
V_95 = F_47 ( V_101 . V_102 [ V_8 ] ) ;
V_96 = V_95 >> 8 ;
V_97 = V_95 & 0xff ;
if ( V_96 ) {
if ( V_96 > 0x0f )
V_51 = F_40 ( V_51 , V_96 ) ;
else
* V_51 ++ = F_48 ( V_96 ) ;
V_51 = F_40 ( V_51 , V_97 ) ;
}
else if ( V_97 > 0x0f )
V_51 = F_40 ( V_51 , V_97 ) ;
else
* V_51 ++ = F_48 ( V_97 ) ;
V_98 = true ;
}
if ( V_99 ) {
if ( V_98 )
* V_51 ++ = ':' ;
V_51 = F_42 ( V_51 , & V_101 . V_103 [ 12 ] , L_17 ) ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_49 ( char * V_51 , const char * V_82 , const char * V_49 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_51 = F_40 ( V_51 , * V_82 ++ ) ;
V_51 = F_40 ( V_51 , * V_82 ++ ) ;
if ( V_49 [ 0 ] == 'I' && V_8 != 7 )
* V_51 ++ = ':' ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_50 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_104 [ sizeof( L_18 ) ] ;
if ( V_49 [ 0 ] == 'I' && V_49 [ 2 ] == 'c' )
F_44 ( V_104 , V_82 ) ;
else
F_49 ( V_104 , V_82 , V_49 ) ;
return string ( V_9 , V_24 , V_104 , V_26 ) ;
}
static T_1
char * F_51 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_105 [ sizeof( L_19 ) ] ;
F_42 ( V_105 , V_82 , V_49 ) ;
return string ( V_9 , V_24 , V_105 , V_26 ) ;
}
static T_1
char * F_52 ( char * V_9 , char * V_24 , const struct V_106 * V_107 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_108 = false , V_109 = false , V_110 = false , V_111 = false ;
char V_104 [ sizeof( L_20 ) +
sizeof( L_21 ) + sizeof( L_22 ) +
sizeof( L_23 ) ] ;
char * V_51 = V_104 , * V_68 = V_104 + sizeof( V_104 ) ;
const T_4 * V_82 = ( const T_4 * ) & V_107 -> V_112 ;
char V_113 [ 2 ] = { V_49 [ 0 ] , '6' } ;
T_4 V_114 = 0 ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_108 = true ;
break;
case 'f' :
V_110 = true ;
break;
case 's' :
V_109 = true ;
break;
case 'c' :
V_111 = true ;
break;
}
}
if ( V_108 || V_109 || V_110 ) {
* V_51 = '[' ;
V_114 = 1 ;
}
if ( V_113 [ 0 ] == 'I' && V_111 )
V_51 = F_44 ( V_104 + V_114 , V_82 ) ;
else
V_51 = F_49 ( V_104 + V_114 , V_82 , V_113 ) ;
if ( V_108 || V_109 || V_110 )
* V_51 ++ = ']' ;
if ( V_108 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_47 ( V_107 -> V_115 ) , V_26 ) ;
}
if ( V_110 ) {
* V_51 ++ = '/' ;
V_51 = F_15 ( V_51 , V_68 , F_53 ( V_107 -> V_116 &
V_117 ) , V_26 ) ;
}
if ( V_109 ) {
* V_51 ++ = '%' ;
V_51 = F_15 ( V_51 , V_68 , V_107 -> V_118 , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_104 , V_26 ) ;
}
static T_1
char * F_54 ( char * V_9 , char * V_24 , const struct V_119 * V_107 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_108 = false ;
char * V_51 , V_105 [ sizeof( L_19 ) + sizeof( L_21 ) ] ;
char * V_68 = V_105 + sizeof( V_105 ) ;
const T_4 * V_82 = ( const T_4 * ) & V_107 -> V_120 . V_121 ;
char V_122 [ 3 ] = { V_49 [ 0 ] , '4' , 0 } ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_108 = true ;
break;
case 'h' :
case 'l' :
case 'n' :
case 'b' :
V_122 [ 2 ] = * V_49 ;
break;
}
}
V_51 = F_42 ( V_105 , V_82 , V_122 ) ;
if ( V_108 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_47 ( V_107 -> V_123 ) , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_105 , V_26 ) ;
}
static T_1
char * F_55 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_124 [ sizeof( L_24 ) ] ;
char * V_51 = V_124 ;
int V_8 ;
static const T_4 V_125 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_4 V_126 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_4 * V_87 = V_125 ;
bool V_127 = false ;
switch ( * ( ++ V_49 ) ) {
case 'L' :
V_127 = true ;
case 'l' :
V_87 = V_126 ;
break;
case 'B' :
V_127 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_51 = F_40 ( V_51 , V_82 [ V_87 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_51 ++ = '-' ;
break;
}
}
* V_51 = 0 ;
if ( V_127 ) {
V_51 = V_124 ;
do {
* V_51 = toupper ( * V_51 ) ;
} while ( * ( ++ V_51 ) );
}
return string ( V_9 , V_24 , V_124 , V_26 ) ;
}
static
char * F_56 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_128 ) ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , * ( const V_128 * ) V_82 , V_26 ) ;
}
static T_1
char * F_57 ( char * V_9 , char * V_24 , const void * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
unsigned long long V_20 ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
switch ( V_49 [ 1 ] ) {
case 'd' :
V_20 = * ( const V_129 * ) V_82 ;
V_26 . V_38 = sizeof( V_129 ) * 2 + 2 ;
break;
case 'p' :
default:
V_20 = * ( const V_130 * ) V_82 ;
V_26 . V_38 = sizeof( V_130 ) * 2 + 2 ;
break;
}
return F_15 ( V_9 , V_24 , V_20 , V_26 ) ;
}
static T_1
char * F_58 ( const char * V_49 , char * V_9 , char * V_24 , void * V_56 ,
struct V_25 V_26 )
{
int V_131 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_56 && * V_49 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_131 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_49 ) {
case 'F' :
case 'f' :
V_56 = F_59 ( V_56 ) ;
case 'S' :
case 's' :
case 'B' :
return F_22 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'R' :
case 'r' :
return F_28 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'h' :
return F_37 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'M' :
case 'm' :
return F_41 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'I' :
case 'i' :
switch ( V_49 [ 1 ] ) {
case '6' :
return F_50 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case '4' :
return F_51 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'S' : {
const union {
struct V_132 V_133 ;
struct V_119 V_134 ;
struct V_106 V_135 ;
} * V_107 = V_56 ;
switch ( V_107 -> V_133 . V_136 ) {
case V_137 :
return F_54 ( V_9 , V_24 , & V_107 -> V_134 , V_26 , V_49 ) ;
case V_138 :
return F_52 ( V_9 , V_24 , & V_107 -> V_135 , V_26 , V_49 ) ;
default:
return string ( V_9 , V_24 , L_25 , V_26 ) ;
} }
}
break;
case 'U' :
return F_55 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'V' :
{
T_6 V_139 ;
F_60 ( V_139 , * ( (struct V_140 * ) V_56 ) -> V_139 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_140 * ) V_56 ) -> V_49 , V_139 ) ;
va_end ( V_139 ) ;
return V_9 ;
}
case 'K' :
if ( V_141 && ( F_61 () || F_62 () ||
F_63 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_131 ;
return string ( V_9 , V_24 , L_26 , V_26 ) ;
}
switch ( V_141 ) {
case 0 :
break;
case 1 : {
const struct V_142 * V_142 = F_64 () ;
if ( ! F_65 ( V_143 , V_144 ) ||
! F_66 ( V_142 -> V_145 , V_142 -> V_146 ) ||
! F_67 ( V_142 -> V_147 , V_142 -> V_148 ) )
V_56 = NULL ;
break;
}
case 2 :
default:
V_56 = NULL ;
break;
}
break;
case 'N' :
switch ( V_49 [ 1 ] ) {
case 'F' :
return F_56 ( V_9 , V_24 , V_56 , V_26 ) ;
}
break;
case 'a' :
return F_57 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'd' :
return F_18 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'D' :
return F_18 ( V_9 , V_24 ,
( ( const struct V_149 * ) V_56 ) -> V_150 . V_47 ,
V_26 , V_49 ) ;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_131 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , ( unsigned long ) V_56 , V_26 ) ;
}
static T_1
int F_68 ( const char * V_49 , struct V_25 * V_26 )
{
const char * V_77 = V_49 ;
if ( V_26 -> type == V_151 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_152 ;
goto V_43;
}
if ( V_26 -> type == V_153 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_152 ;
goto V_154;
}
V_26 -> type = V_152 ;
for (; * V_49 ; ++ V_49 ) {
if ( * V_49 == '%' )
break;
}
if ( V_49 != V_77 || ! * V_49 )
return V_49 - V_77 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_155 = true ;
++ V_49 ;
switch ( * V_49 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_155 = false ;
}
if ( ! V_155 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_49 ) )
V_26 -> V_38 = F_7 ( & V_49 ) ;
else if ( * V_49 == '*' ) {
V_26 -> type = V_151 ;
return ++ V_49 - V_77 ;
}
V_43:
V_26 -> V_43 = - 1 ;
if ( * V_49 == '.' ) {
++ V_49 ;
if ( isdigit ( * V_49 ) ) {
V_26 -> V_43 = F_7 ( & V_49 ) ;
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
} else if ( * V_49 == '*' ) {
V_26 -> type = V_153 ;
return ++ V_49 - V_77 ;
}
}
V_154:
V_26 -> V_154 = - 1 ;
if ( * V_49 == 'h' || F_69 ( * V_49 ) == 'l' ||
F_69 ( * V_49 ) == 'z' || * V_49 == 't' ) {
V_26 -> V_154 = * V_49 ++ ;
if ( F_70 ( V_26 -> V_154 == * V_49 ) ) {
if ( V_26 -> V_154 == 'l' ) {
V_26 -> V_154 = 'L' ;
++ V_49 ;
} else if ( V_26 -> V_154 == 'h' ) {
V_26 -> V_154 = 'H' ;
++ V_49 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_49 ) {
case 'c' :
V_26 -> type = V_156 ;
return ++ V_49 - V_77 ;
case 's' :
V_26 -> type = V_157 ;
return ++ V_49 - V_77 ;
case 'p' :
V_26 -> type = V_158 ;
return V_49 - V_77 ;
case '%' :
V_26 -> type = V_159 ;
return ++ V_49 - V_77 ;
case 'o' :
V_26 -> V_3 = 8 ;
break;
case 'x' :
V_26 -> V_31 |= V_34 ;
case 'X' :
V_26 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_26 -> V_31 |= V_37 ;
case 'u' :
break;
case 'n' :
F_71 ( 1 , L_27 , V_49 ) ;
default:
V_26 -> type = V_160 ;
return V_49 - V_77 ;
}
if ( V_26 -> V_154 == 'L' )
V_26 -> type = V_161 ;
else if ( V_26 -> V_154 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_162 ;
else
V_26 -> type = V_163 ;
} else if ( F_69 ( V_26 -> V_154 ) == 'z' ) {
V_26 -> type = V_164 ;
} else if ( V_26 -> V_154 == 't' ) {
V_26 -> type = V_165 ;
} else if ( V_26 -> V_154 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_166 ;
else
V_26 -> type = V_167 ;
} else if ( V_26 -> V_154 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_168 ;
else
V_26 -> type = V_169 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_170 ;
else
V_26 -> type = V_171 ;
}
return ++ V_49 - V_77 ;
}
int vsnprintf ( char * V_9 , T_3 V_19 , const char * V_49 , T_6 args )
{
unsigned long long V_20 ;
char * V_172 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_72 ( ( int ) V_19 < 0 ) )
return 0 ;
V_172 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_49 ) {
const char * V_173 = V_49 ;
int V_174 = F_68 ( V_49 , & V_26 ) ;
V_49 += V_174 ;
switch ( V_26 . type ) {
case V_152 : {
int V_175 = V_174 ;
if ( V_172 < V_24 ) {
if ( V_175 > V_24 - V_172 )
V_175 = V_24 - V_172 ;
memcpy ( V_172 , V_173 , V_175 ) ;
}
V_172 += V_174 ;
break;
}
case V_151 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_153 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_156 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_172 < V_24 )
* V_172 = ' ' ;
++ V_172 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_172 < V_24 )
* V_172 = V_44 ;
++ V_172 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_172 < V_24 )
* V_172 = ' ' ;
++ V_172 ;
}
break;
}
case V_157 :
V_172 = string ( V_172 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_158 :
V_172 = F_58 ( V_49 + 1 , V_172 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_159 :
if ( V_172 < V_24 )
* V_172 = '%' ;
++ V_172 ;
break;
case V_160 :
if ( V_172 < V_24 )
* V_172 = '%' ;
++ V_172 ;
break;
default:
switch ( V_26 . type ) {
case V_161 :
V_20 = va_arg (args, long long) ;
break;
case V_163 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_162 :
V_20 = va_arg ( args , long ) ;
break;
case V_164 :
if ( V_26 . V_31 & V_37 )
V_20 = va_arg ( args , V_176 ) ;
else
V_20 = va_arg ( args , T_3 ) ;
break;
case V_165 :
V_20 = va_arg ( args , V_177 ) ;
break;
case V_167 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_166 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_169 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_168 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_170 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_172 = F_15 ( V_172 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_172 < V_24 )
* V_172 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_172 - V_9 ;
}
int F_73 ( char * V_9 , T_3 V_19 , const char * V_49 , T_6 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_49 , args ) ;
if ( F_74 ( V_8 < V_19 ) )
return V_8 ;
if ( V_19 != 0 )
return V_19 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_3 V_19 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_75 ( char * V_9 , T_3 V_19 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = F_73 ( V_9 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_49 , T_6 args )
{
return vsnprintf ( V_9 , V_178 , V_49 , args ) ;
}
int sprintf ( char * V_9 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_178 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_76 ( T_7 * V_179 , T_3 V_19 , const char * V_49 , T_6 args )
{
struct V_25 V_26 = { 0 } ;
char * V_172 , * V_24 ;
V_172 = ( char * ) V_179 ;
V_24 = ( char * ) ( V_179 + V_19 ) ;
#define F_77 ( type ) \
do { \
if (sizeof(type) == 8) { \
unsigned long long value; \
str = PTR_ALIGN(str, sizeof(u32)); \
value = va_arg(args, unsigned long long); \
if (str + sizeof(type) <= end) { \
*(u32 *)str = *(u32 *)&value; \
*(u32 *)(str + 4) = *((u32 *)&value + 1); \
} \
} else { \
unsigned long value; \
str = PTR_ALIGN(str, sizeof(type)); \
value = va_arg(args, int); \
if (str + sizeof(type) <= end) \
*(typeof(type) *)str = (type)value; \
} \
str += sizeof(type); \
} while (0)
while ( * V_49 ) {
int V_174 = F_68 ( V_49 , & V_26 ) ;
V_49 += V_174 ;
switch ( V_26 . type ) {
case V_152 :
case V_160 :
case V_159 :
break;
case V_151 :
case V_153 :
F_77 ( int ) ;
break;
case V_156 :
F_77 ( char ) ;
break;
case V_157 : {
const char * V_180 = va_arg ( args , char * ) ;
T_3 V_23 ;
if ( ( unsigned long ) V_180 > ( unsigned long ) - V_45
|| ( unsigned long ) V_180 < V_45 )
V_180 = L_2 ;
V_23 = strlen ( V_180 ) + 1 ;
if ( V_172 + V_23 < V_24 )
memcpy ( V_172 , V_180 , V_23 ) ;
V_172 += V_23 ;
break;
}
case V_158 :
F_77 ( void * ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
default:
switch ( V_26 . type ) {
case V_161 :
F_77 (long long) ;
break;
case V_163 :
case V_162 :
F_77 (unsigned long) ;
break;
case V_164 :
F_77 ( T_3 ) ;
break;
case V_165 :
F_77 ( V_177 ) ;
break;
case V_167 :
case V_166 :
F_77 ( char ) ;
break;
case V_169 :
case V_168 :
F_77 ( short ) ;
break;
default:
F_77 ( int ) ;
}
}
}
return ( T_7 * ) ( F_78 ( V_172 , sizeof( T_7 ) ) ) - V_179 ;
#undef F_77
}
int F_79 ( char * V_9 , T_3 V_19 , const char * V_49 , const T_7 * V_179 )
{
struct V_25 V_26 = { 0 } ;
char * V_172 , * V_24 ;
const char * args = ( const char * ) V_179 ;
if ( F_72 ( ( int ) V_19 < 0 ) )
return 0 ;
V_172 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_80 ( type ) \
({ \
typeof(type) value; \
if (sizeof(type) == 8) { \
args = PTR_ALIGN(args, sizeof(u32)); \
*(u32 *)&value = *(u32 *)args; \
*((u32 *)&value + 1) = *(u32 *)(args + 4); \
} else { \
args = PTR_ALIGN(args, sizeof(type)); \
value = *(typeof(type) *)args; \
} \
args += sizeof(type); \
value; \
})
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_49 ) {
const char * V_173 = V_49 ;
int V_174 = F_68 ( V_49 , & V_26 ) ;
V_49 += V_174 ;
switch ( V_26 . type ) {
case V_152 : {
int V_175 = V_174 ;
if ( V_172 < V_24 ) {
if ( V_175 > V_24 - V_172 )
V_175 = V_24 - V_172 ;
memcpy ( V_172 , V_173 , V_175 ) ;
}
V_172 += V_174 ;
break;
}
case V_151 :
V_26 . V_38 = F_80 ( int ) ;
break;
case V_153 :
V_26 . V_43 = F_80 ( int ) ;
break;
case V_156 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_172 < V_24 )
* V_172 = ' ' ;
++ V_172 ;
}
}
V_44 = ( unsigned char ) F_80 ( char ) ;
if ( V_172 < V_24 )
* V_172 = V_44 ;
++ V_172 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_172 < V_24 )
* V_172 = ' ' ;
++ V_172 ;
}
break;
}
case V_157 : {
const char * V_181 = args ;
args += strlen ( V_181 ) + 1 ;
V_172 = string ( V_172 , V_24 , ( char * ) V_181 , V_26 ) ;
break;
}
case V_158 :
V_172 = F_58 ( V_49 + 1 , V_172 , V_24 , F_80 ( void * ) , V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_159 :
case V_160 :
if ( V_172 < V_24 )
* V_172 = '%' ;
++ V_172 ;
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_161 :
V_20 = F_80 (long long) ;
break;
case V_163 :
case V_162 :
V_20 = F_80 (unsigned long) ;
break;
case V_164 :
V_20 = F_80 ( T_3 ) ;
break;
case V_165 :
V_20 = F_80 ( V_177 ) ;
break;
case V_167 :
V_20 = F_80 (unsigned char) ;
break;
case V_166 :
V_20 = F_80 (signed char) ;
break;
case V_169 :
V_20 = F_80 (unsigned short) ;
break;
case V_168 :
V_20 = F_80 ( short ) ;
break;
case V_171 :
V_20 = F_80 (unsigned int) ;
break;
default:
V_20 = F_80 ( int ) ;
}
V_172 = F_15 ( V_172 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_172 < V_24 )
* V_172 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_80
return V_172 - V_9 ;
}
int F_81 ( T_7 * V_179 , T_3 V_19 , const char * V_49 , ... )
{
T_6 args ;
int V_182 ;
va_start ( args , V_49 ) ;
V_182 = F_76 ( V_179 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_182 ;
}
int vsscanf ( const char * V_9 , const char * V_49 , T_6 args )
{
const char * V_172 = V_9 ;
char * V_183 ;
char V_184 ;
int V_20 = 0 ;
T_4 V_154 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_185 ;
} V_186 ;
T_8 V_38 ;
bool V_187 ;
while ( * V_49 ) {
if ( isspace ( * V_49 ) ) {
V_49 = F_82 ( ++ V_49 ) ;
V_172 = F_82 ( V_172 ) ;
}
if ( * V_49 != '%' && * V_49 ) {
if ( * V_49 ++ != * V_172 ++ )
break;
continue;
}
if ( ! * V_49 )
break;
++ V_49 ;
if ( * V_49 == '*' ) {
if ( ! * V_172 )
break;
while ( ! isspace ( * V_49 ) && * V_49 != '%' && * V_49 )
V_49 ++ ;
while ( ! isspace ( * V_172 ) && * V_172 )
V_172 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_49 ) ) {
V_38 = F_7 ( & V_49 ) ;
if ( V_38 <= 0 )
break;
}
V_154 = - 1 ;
if ( * V_49 == 'h' || F_69 ( * V_49 ) == 'l' ||
F_69 ( * V_49 ) == 'z' ) {
V_154 = * V_49 ++ ;
if ( F_70 ( V_154 == * V_49 ) ) {
if ( V_154 == 'h' ) {
V_154 = 'H' ;
V_49 ++ ;
} else if ( V_154 == 'l' ) {
V_154 = 'L' ;
V_49 ++ ;
}
}
}
if ( ! * V_49 )
break;
if ( * V_49 == 'n' ) {
* va_arg ( args , int * ) = V_172 - V_9 ;
++ V_49 ;
continue;
}
if ( ! * V_172 )
break;
V_3 = 10 ;
V_187 = 0 ;
switch ( * V_49 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_172 ++ ;
} while ( -- V_38 > 0 && * V_172 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_188 ;
V_172 = F_82 ( V_172 ) ;
while ( * V_172 && ! isspace ( * V_172 ) && V_38 -- )
* V_7 ++ = * V_172 ++ ;
* V_7 = '\0' ;
V_20 ++ ;
}
continue;
case 'o' :
V_3 = 8 ;
break;
case 'x' :
case 'X' :
V_3 = 16 ;
break;
case 'i' :
V_3 = 0 ;
case 'd' :
V_187 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_172 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_172 = F_82 ( V_172 ) ;
V_184 = * V_172 ;
if ( V_187 && V_184 == '-' )
V_184 = * ( V_172 + 1 ) ;
if ( ! V_184
|| ( V_3 == 16 && ! isxdigit ( V_184 ) )
|| ( V_3 == 10 && ! isdigit ( V_184 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_184 ) || V_184 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_184 ) ) )
break;
if ( V_187 )
V_186 . V_7 = V_154 != 'L' ?
F_5 ( V_172 , & V_183 , V_3 ) :
F_6 ( V_172 , & V_183 , V_3 ) ;
else
V_186 . V_185 = V_154 != 'L' ?
F_4 ( V_172 , & V_183 , V_3 ) :
F_1 ( V_172 , & V_183 , V_3 ) ;
if ( V_38 > 0 && V_183 - V_172 > V_38 ) {
if ( V_3 == 0 )
F_2 ( V_172 , & V_3 ) ;
while ( V_183 - V_172 > V_38 ) {
if ( V_187 )
V_186 . V_7 = F_83 ( V_186 . V_7 , V_3 ) ;
else
V_186 . V_185 = F_84 ( V_186 . V_185 , V_3 ) ;
-- V_183 ;
}
}
switch ( V_154 ) {
case 'H' :
if ( V_187 )
* va_arg (args, signed char *) = V_186 . V_7 ;
else
* va_arg (args, unsigned char *) = V_186 . V_185 ;
break;
case 'h' :
if ( V_187 )
* va_arg ( args , short * ) = V_186 . V_7 ;
else
* va_arg (args, unsigned short *) = V_186 . V_185 ;
break;
case 'l' :
if ( V_187 )
* va_arg ( args , long * ) = V_186 . V_7 ;
else
* va_arg (args, unsigned long *) = V_186 . V_185 ;
break;
case 'L' :
if ( V_187 )
* va_arg (args, long long *) = V_186 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_186 . V_185 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_3 * ) = V_186 . V_185 ;
break;
default:
if ( V_187 )
* va_arg ( args , int * ) = V_186 . V_7 ;
else
* va_arg (args, unsigned int *) = V_186 . V_185 ;
break;
}
V_20 ++ ;
if ( ! V_183 )
break;
V_172 = V_183 ;
}
return V_20 ;
}
int sscanf ( const char * V_9 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsscanf ( V_9 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
