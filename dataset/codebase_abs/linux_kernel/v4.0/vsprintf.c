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
do {
V_8 = V_8 * 10 + * ( ( * V_7 ) ++ ) - '0' ;
} while ( isdigit ( * * V_7 ) );
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
char * F_41 ( char * V_9 , char * V_24 , unsigned long * V_84 ,
struct V_25 V_26 , const char * V_49 )
{
const int V_85 = 32 ;
int V_86 = F_42 ( int , V_26 . V_38 , 0 ) ;
int V_8 , V_87 ;
bool V_88 = true ;
V_26 = (struct V_25 ) { . V_31 = V_34 | V_36 , . V_3 = 16 } ;
V_87 = V_86 & ( V_85 - 1 ) ;
if ( V_87 == 0 )
V_87 = V_85 ;
V_8 = F_43 ( V_86 , V_85 ) - V_85 ;
for (; V_8 >= 0 ; V_8 -= V_85 ) {
T_5 V_89 , V_90 ;
int V_91 , V_92 ;
V_89 = ( ( 1ULL << V_87 ) - 1 ) ;
V_91 = V_8 / V_93 ;
V_92 = V_8 % V_93 ;
V_90 = ( V_84 [ V_91 ] >> V_92 ) & V_89 ;
if ( ! V_88 ) {
if ( V_9 < V_24 )
* V_9 = ',' ;
V_9 ++ ;
}
V_88 = false ;
V_26 . V_38 = F_44 ( V_87 , 4 ) ;
V_9 = F_15 ( V_9 , V_24 , V_90 , V_26 ) ;
V_87 = V_85 ;
}
return V_9 ;
}
static T_1
char * F_45 ( char * V_9 , char * V_24 , unsigned long * V_84 ,
struct V_25 V_26 , const char * V_49 )
{
int V_86 = F_42 ( int , V_26 . V_38 , 0 ) ;
int V_94 , V_95 , V_96 ;
bool V_88 = true ;
V_26 = (struct V_25 ) { . V_3 = 10 } ;
V_95 = V_94 = F_46 ( V_84 , V_86 ) ;
while ( V_94 < V_86 ) {
V_96 = V_94 ;
V_94 = F_47 ( V_84 , V_86 , V_94 + 1 ) ;
if ( V_94 < V_86 && V_94 <= V_96 + 1 )
continue;
if ( ! V_88 ) {
if ( V_9 < V_24 )
* V_9 = ',' ;
V_9 ++ ;
}
V_88 = false ;
V_9 = F_15 ( V_9 , V_24 , V_95 , V_26 ) ;
if ( V_95 < V_96 ) {
if ( V_9 < V_24 )
* V_9 = '-' ;
V_9 ++ ;
V_9 = F_15 ( V_9 , V_24 , V_96 , V_26 ) ;
}
V_95 = V_94 ;
}
return V_9 ;
}
static T_1
char * F_48 ( char * V_9 , char * V_24 , T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_97 [ sizeof( L_16 ) ] ;
char * V_51 = V_97 ;
int V_8 ;
char V_83 ;
bool V_98 = false ;
switch ( V_49 [ 1 ] ) {
case 'F' :
V_83 = '-' ;
break;
case 'R' :
V_98 = true ;
default:
V_83 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_98 )
V_51 = F_40 ( V_51 , V_82 [ 5 - V_8 ] ) ;
else
V_51 = F_40 ( V_51 , V_82 [ V_8 ] ) ;
if ( V_49 [ 0 ] == 'M' && V_8 != 5 )
* V_51 ++ = V_83 ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_97 , V_26 ) ;
}
static T_1
char * F_49 ( char * V_51 , const T_4 * V_82 , const char * V_49 )
{
int V_8 ;
bool V_99 = ( V_49 [ 0 ] == 'i' ) ;
int V_100 ;
int V_101 ;
switch ( V_49 [ 2 ] ) {
case 'h' :
#ifdef F_50
V_100 = 0 ;
V_101 = 1 ;
#else
V_100 = 3 ;
V_101 = - 1 ;
#endif
break;
case 'l' :
V_100 = 3 ;
V_101 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_100 = 0 ;
V_101 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_102 [ 3 ] ;
int V_27 = F_9 ( V_102 , V_82 [ V_100 ] ) - V_102 ;
if ( V_99 ) {
if ( V_27 < 3 )
* V_51 ++ = '0' ;
if ( V_27 < 2 )
* V_51 ++ = '0' ;
}
while ( V_27 -- )
* V_51 ++ = V_102 [ V_27 ] ;
if ( V_8 < 3 )
* V_51 ++ = '.' ;
V_100 += V_101 ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_51 ( char * V_51 , const char * V_82 )
{
int V_8 , V_103 , V_104 ;
unsigned char V_105 [ 8 ] ;
int V_106 = 1 ;
int V_107 = - 1 ;
T_6 V_91 ;
T_4 V_108 , V_109 ;
bool V_110 = false ;
bool V_111 ;
struct V_112 V_113 ;
memcpy ( & V_113 , V_82 , sizeof( struct V_112 ) ) ;
V_111 = F_52 ( & V_113 ) || F_53 ( & V_113 ) ;
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
if ( V_111 )
V_104 = 6 ;
else
V_104 = 8 ;
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
for ( V_103 = V_8 ; V_103 < V_104 ; V_103 ++ ) {
if ( V_113 . V_114 [ V_103 ] != 0 )
break;
V_105 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
if ( V_105 [ V_8 ] > V_106 ) {
V_106 = V_105 [ V_8 ] ;
V_107 = V_8 ;
}
}
if ( V_106 == 1 )
V_107 = - 1 ;
for ( V_8 = 0 ; V_8 < V_104 ; V_8 ++ ) {
if ( V_8 == V_107 ) {
if ( V_110 || V_8 == 0 )
* V_51 ++ = ':' ;
* V_51 ++ = ':' ;
V_110 = false ;
V_8 += V_106 - 1 ;
continue;
}
if ( V_110 ) {
* V_51 ++ = ':' ;
V_110 = false ;
}
V_91 = F_54 ( V_113 . V_114 [ V_8 ] ) ;
V_108 = V_91 >> 8 ;
V_109 = V_91 & 0xff ;
if ( V_108 ) {
if ( V_108 > 0x0f )
V_51 = F_40 ( V_51 , V_108 ) ;
else
* V_51 ++ = F_55 ( V_108 ) ;
V_51 = F_40 ( V_51 , V_109 ) ;
}
else if ( V_109 > 0x0f )
V_51 = F_40 ( V_51 , V_109 ) ;
else
* V_51 ++ = F_55 ( V_109 ) ;
V_110 = true ;
}
if ( V_111 ) {
if ( V_110 )
* V_51 ++ = ':' ;
V_51 = F_49 ( V_51 , & V_113 . V_115 [ 12 ] , L_17 ) ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_56 ( char * V_51 , const char * V_82 , const char * V_49 )
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
char * F_57 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_116 [ sizeof( L_18 ) ] ;
if ( V_49 [ 0 ] == 'I' && V_49 [ 2 ] == 'c' )
F_51 ( V_116 , V_82 ) ;
else
F_56 ( V_116 , V_82 , V_49 ) ;
return string ( V_9 , V_24 , V_116 , V_26 ) ;
}
static T_1
char * F_58 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_117 [ sizeof( L_19 ) ] ;
F_49 ( V_117 , V_82 , V_49 ) ;
return string ( V_9 , V_24 , V_117 , V_26 ) ;
}
static T_1
char * F_59 ( char * V_9 , char * V_24 , const struct V_118 * V_119 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_120 = false , V_121 = false , V_122 = false , V_123 = false ;
char V_116 [ sizeof( L_20 ) +
sizeof( L_21 ) + sizeof( L_22 ) +
sizeof( L_23 ) ] ;
char * V_51 = V_116 , * V_68 = V_116 + sizeof( V_116 ) ;
const T_4 * V_82 = ( const T_4 * ) & V_119 -> V_124 ;
char V_125 [ 2 ] = { V_49 [ 0 ] , '6' } ;
T_4 V_126 = 0 ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_120 = true ;
break;
case 'f' :
V_122 = true ;
break;
case 's' :
V_121 = true ;
break;
case 'c' :
V_123 = true ;
break;
}
}
if ( V_120 || V_121 || V_122 ) {
* V_51 = '[' ;
V_126 = 1 ;
}
if ( V_125 [ 0 ] == 'I' && V_123 )
V_51 = F_51 ( V_116 + V_126 , V_82 ) ;
else
V_51 = F_56 ( V_116 + V_126 , V_82 , V_125 ) ;
if ( V_120 || V_121 || V_122 )
* V_51 ++ = ']' ;
if ( V_120 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_54 ( V_119 -> V_127 ) , V_26 ) ;
}
if ( V_122 ) {
* V_51 ++ = '/' ;
V_51 = F_15 ( V_51 , V_68 , F_60 ( V_119 -> V_128 &
V_129 ) , V_26 ) ;
}
if ( V_121 ) {
* V_51 ++ = '%' ;
V_51 = F_15 ( V_51 , V_68 , V_119 -> V_130 , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_116 , V_26 ) ;
}
static T_1
char * F_61 ( char * V_9 , char * V_24 , const struct V_131 * V_119 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_120 = false ;
char * V_51 , V_117 [ sizeof( L_19 ) + sizeof( L_21 ) ] ;
char * V_68 = V_117 + sizeof( V_117 ) ;
const T_4 * V_82 = ( const T_4 * ) & V_119 -> V_132 . V_133 ;
char V_134 [ 3 ] = { V_49 [ 0 ] , '4' , 0 } ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_120 = true ;
break;
case 'h' :
case 'l' :
case 'n' :
case 'b' :
V_134 [ 2 ] = * V_49 ;
break;
}
}
V_51 = F_49 ( V_117 , V_82 , V_134 ) ;
if ( V_120 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_54 ( V_119 -> V_135 ) , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_117 , V_26 ) ;
}
static T_1
char * F_62 ( char * V_9 , char * V_24 , T_4 * V_82 , struct V_25 V_26 ,
const char * V_49 )
{
bool V_136 = true ;
int V_137 = 1 ;
unsigned int V_31 = 0 ;
int V_23 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_38 ( V_82 ) )
return string ( V_9 , V_24 , NULL , V_26 ) ;
do {
switch ( V_49 [ V_137 ++ ] ) {
case 'a' :
V_31 |= V_138 ;
break;
case 'c' :
V_31 |= V_139 ;
break;
case 'h' :
V_31 |= V_140 ;
break;
case 'n' :
V_31 |= V_141 ;
break;
case 'o' :
V_31 |= V_142 ;
break;
case 'p' :
V_31 |= V_143 ;
break;
case 's' :
V_31 |= V_144 ;
break;
default:
V_136 = false ;
break;
}
} while ( V_136 );
if ( ! V_31 )
V_31 = V_145 ;
V_23 = V_26 . V_38 < 0 ? 1 : V_26 . V_38 ;
F_63 ( V_82 , V_23 , & V_9 , V_24 - V_9 , V_31 , NULL ) ;
return V_9 ;
}
static T_1
char * F_64 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
char V_146 [ sizeof( L_24 ) ] ;
char * V_51 = V_146 ;
int V_8 ;
static const T_4 V_147 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_4 V_148 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_4 * V_100 = V_147 ;
bool V_149 = false ;
switch ( * ( ++ V_49 ) ) {
case 'L' :
V_149 = true ;
case 'l' :
V_100 = V_148 ;
break;
case 'B' :
V_149 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_51 = F_40 ( V_51 , V_82 [ V_100 [ V_8 ] ] ) ;
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
if ( V_149 ) {
V_51 = V_146 ;
do {
* V_51 = toupper ( * V_51 ) ;
} while ( * ( ++ V_51 ) );
}
return string ( V_9 , V_24 , V_146 , V_26 ) ;
}
static
char * F_65 ( char * V_9 , char * V_24 , const T_4 * V_82 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_150 ) ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , * ( const V_150 * ) V_82 , V_26 ) ;
}
static T_1
char * F_66 ( char * V_9 , char * V_24 , const void * V_82 ,
struct V_25 V_26 , const char * V_49 )
{
unsigned long long V_20 ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
switch ( V_49 [ 1 ] ) {
case 'd' :
V_20 = * ( const V_151 * ) V_82 ;
V_26 . V_38 = sizeof( V_151 ) * 2 + 2 ;
break;
case 'p' :
default:
V_20 = * ( const V_152 * ) V_82 ;
V_26 . V_38 = sizeof( V_152 ) * 2 + 2 ;
break;
}
return F_15 ( V_9 , V_24 , V_20 , V_26 ) ;
}
static T_1
char * F_67 ( const char * V_49 , char * V_9 , char * V_24 , void * V_56 ,
struct V_25 V_26 )
{
int V_153 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_56 && * V_49 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_153 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_49 ) {
case 'F' :
case 'f' :
V_56 = F_68 ( V_56 ) ;
case 'S' :
case 's' :
case 'B' :
return F_22 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'R' :
case 'r' :
return F_28 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'h' :
return F_37 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'b' :
switch ( V_49 [ 1 ] ) {
case 'l' :
return F_45 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
default:
return F_41 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
}
case 'M' :
case 'm' :
return F_48 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'I' :
case 'i' :
switch ( V_49 [ 1 ] ) {
case '6' :
return F_57 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case '4' :
return F_58 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'S' : {
const union {
struct V_154 V_155 ;
struct V_131 V_156 ;
struct V_118 V_157 ;
} * V_119 = V_56 ;
switch ( V_119 -> V_155 . V_158 ) {
case V_159 :
return F_61 ( V_9 , V_24 , & V_119 -> V_156 , V_26 , V_49 ) ;
case V_160 :
return F_59 ( V_9 , V_24 , & V_119 -> V_157 , V_26 , V_49 ) ;
default:
return string ( V_9 , V_24 , L_25 , V_26 ) ;
} }
}
break;
case 'E' :
return F_62 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'U' :
return F_64 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'V' :
{
T_7 V_161 ;
F_69 ( V_161 , * ( (struct V_162 * ) V_56 ) -> V_161 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_162 * ) V_56 ) -> V_49 , V_161 ) ;
va_end ( V_161 ) ;
return V_9 ;
}
case 'K' :
if ( V_163 && ( F_70 () || F_71 () ||
F_72 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_153 ;
return string ( V_9 , V_24 , L_26 , V_26 ) ;
}
switch ( V_163 ) {
case 0 :
break;
case 1 : {
const struct V_164 * V_164 = F_73 () ;
if ( ! F_74 ( V_165 , V_166 ) ||
! F_75 ( V_164 -> V_167 , V_164 -> V_168 ) ||
! F_76 ( V_164 -> V_169 , V_164 -> V_170 ) )
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
return F_65 ( V_9 , V_24 , V_56 , V_26 ) ;
}
break;
case 'a' :
return F_66 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'd' :
return F_18 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'D' :
return F_18 ( V_9 , V_24 ,
( ( const struct V_171 * ) V_56 ) -> V_172 . V_47 ,
V_26 , V_49 ) ;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_153 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , ( unsigned long ) V_56 , V_26 ) ;
}
static T_1
int F_77 ( const char * V_49 , struct V_25 * V_26 )
{
const char * V_77 = V_49 ;
if ( V_26 -> type == V_173 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_174 ;
goto V_43;
}
if ( V_26 -> type == V_175 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_174 ;
goto V_176;
}
V_26 -> type = V_174 ;
for (; * V_49 ; ++ V_49 ) {
if ( * V_49 == '%' )
break;
}
if ( V_49 != V_77 || ! * V_49 )
return V_49 - V_77 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_136 = true ;
++ V_49 ;
switch ( * V_49 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_136 = false ;
}
if ( ! V_136 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_49 ) )
V_26 -> V_38 = F_7 ( & V_49 ) ;
else if ( * V_49 == '*' ) {
V_26 -> type = V_173 ;
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
V_26 -> type = V_175 ;
return ++ V_49 - V_77 ;
}
}
V_176:
V_26 -> V_176 = - 1 ;
if ( * V_49 == 'h' || F_78 ( * V_49 ) == 'l' ||
F_78 ( * V_49 ) == 'z' || * V_49 == 't' ) {
V_26 -> V_176 = * V_49 ++ ;
if ( F_79 ( V_26 -> V_176 == * V_49 ) ) {
if ( V_26 -> V_176 == 'l' ) {
V_26 -> V_176 = 'L' ;
++ V_49 ;
} else if ( V_26 -> V_176 == 'h' ) {
V_26 -> V_176 = 'H' ;
++ V_49 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_49 ) {
case 'c' :
V_26 -> type = V_177 ;
return ++ V_49 - V_77 ;
case 's' :
V_26 -> type = V_178 ;
return ++ V_49 - V_77 ;
case 'p' :
V_26 -> type = V_179 ;
return ++ V_49 - V_77 ;
case '%' :
V_26 -> type = V_180 ;
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
F_80 ( 1 , L_27 , V_49 ) ;
default:
V_26 -> type = V_181 ;
return V_49 - V_77 ;
}
if ( V_26 -> V_176 == 'L' )
V_26 -> type = V_182 ;
else if ( V_26 -> V_176 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_183 ;
else
V_26 -> type = V_184 ;
} else if ( F_78 ( V_26 -> V_176 ) == 'z' ) {
V_26 -> type = V_185 ;
} else if ( V_26 -> V_176 == 't' ) {
V_26 -> type = V_186 ;
} else if ( V_26 -> V_176 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_187 ;
else
V_26 -> type = V_188 ;
} else if ( V_26 -> V_176 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_189 ;
else
V_26 -> type = V_190 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_191 ;
else
V_26 -> type = V_192 ;
}
return ++ V_49 - V_77 ;
}
int vsnprintf ( char * V_9 , T_3 V_19 , const char * V_49 , T_7 args )
{
unsigned long long V_20 ;
char * V_193 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_81 ( V_19 > V_194 ) )
return 0 ;
V_193 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_49 ) {
const char * V_195 = V_49 ;
int V_196 = F_77 ( V_49 , & V_26 ) ;
V_49 += V_196 ;
switch ( V_26 . type ) {
case V_174 : {
int V_197 = V_196 ;
if ( V_193 < V_24 ) {
if ( V_197 > V_24 - V_193 )
V_197 = V_24 - V_193 ;
memcpy ( V_193 , V_195 , V_197 ) ;
}
V_193 += V_196 ;
break;
}
case V_173 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_175 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_177 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_193 < V_24 )
* V_193 = ' ' ;
++ V_193 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_193 < V_24 )
* V_193 = V_44 ;
++ V_193 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_193 < V_24 )
* V_193 = ' ' ;
++ V_193 ;
}
break;
}
case V_178 :
V_193 = string ( V_193 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_179 :
V_193 = F_67 ( V_49 , V_193 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_180 :
if ( V_193 < V_24 )
* V_193 = '%' ;
++ V_193 ;
break;
case V_181 :
if ( V_193 < V_24 )
* V_193 = '%' ;
++ V_193 ;
break;
default:
switch ( V_26 . type ) {
case V_182 :
V_20 = va_arg (args, long long) ;
break;
case V_184 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_183 :
V_20 = va_arg ( args , long ) ;
break;
case V_185 :
if ( V_26 . V_31 & V_37 )
V_20 = va_arg ( args , V_198 ) ;
else
V_20 = va_arg ( args , T_3 ) ;
break;
case V_186 :
V_20 = va_arg ( args , V_199 ) ;
break;
case V_188 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_187 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_190 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_189 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_191 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_193 = F_15 ( V_193 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_193 < V_24 )
* V_193 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_193 - V_9 ;
}
int F_82 ( char * V_9 , T_3 V_19 , const char * V_49 , T_7 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_49 , args ) ;
if ( F_83 ( V_8 < V_19 ) )
return V_8 ;
if ( V_19 != 0 )
return V_19 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_3 V_19 , const char * V_49 , ... )
{
T_7 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_84 ( char * V_9 , T_3 V_19 , const char * V_49 , ... )
{
T_7 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = F_82 ( V_9 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_49 , T_7 args )
{
return vsnprintf ( V_9 , V_194 , V_49 , args ) ;
}
int sprintf ( char * V_9 , const char * V_49 , ... )
{
T_7 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_194 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_85 ( T_5 * V_200 , T_3 V_19 , const char * V_49 , T_7 args )
{
struct V_25 V_26 = { 0 } ;
char * V_193 , * V_24 ;
V_193 = ( char * ) V_200 ;
V_24 = ( char * ) ( V_200 + V_19 ) ;
#define F_86 ( type ) \
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
int V_196 = F_77 ( V_49 , & V_26 ) ;
V_49 += V_196 ;
switch ( V_26 . type ) {
case V_174 :
case V_181 :
case V_180 :
break;
case V_173 :
case V_175 :
F_86 ( int ) ;
break;
case V_177 :
F_86 ( char ) ;
break;
case V_178 : {
const char * V_201 = va_arg ( args , char * ) ;
T_3 V_23 ;
if ( ( unsigned long ) V_201 > ( unsigned long ) - V_45
|| ( unsigned long ) V_201 < V_45 )
V_201 = L_2 ;
V_23 = strlen ( V_201 ) + 1 ;
if ( V_193 + V_23 < V_24 )
memcpy ( V_193 , V_201 , V_23 ) ;
V_193 += V_23 ;
break;
}
case V_179 :
F_86 ( void * ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
default:
switch ( V_26 . type ) {
case V_182 :
F_86 (long long) ;
break;
case V_184 :
case V_183 :
F_86 (unsigned long) ;
break;
case V_185 :
F_86 ( T_3 ) ;
break;
case V_186 :
F_86 ( V_199 ) ;
break;
case V_188 :
case V_187 :
F_86 ( char ) ;
break;
case V_190 :
case V_189 :
F_86 ( short ) ;
break;
default:
F_86 ( int ) ;
}
}
}
return ( T_5 * ) ( F_87 ( V_193 , sizeof( T_5 ) ) ) - V_200 ;
#undef F_86
}
int F_88 ( char * V_9 , T_3 V_19 , const char * V_49 , const T_5 * V_200 )
{
struct V_25 V_26 = { 0 } ;
char * V_193 , * V_24 ;
const char * args = ( const char * ) V_200 ;
if ( F_81 ( ( int ) V_19 < 0 ) )
return 0 ;
V_193 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_89 ( type ) \
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
const char * V_195 = V_49 ;
int V_196 = F_77 ( V_49 , & V_26 ) ;
V_49 += V_196 ;
switch ( V_26 . type ) {
case V_174 : {
int V_197 = V_196 ;
if ( V_193 < V_24 ) {
if ( V_197 > V_24 - V_193 )
V_197 = V_24 - V_193 ;
memcpy ( V_193 , V_195 , V_197 ) ;
}
V_193 += V_196 ;
break;
}
case V_173 :
V_26 . V_38 = F_89 ( int ) ;
break;
case V_175 :
V_26 . V_43 = F_89 ( int ) ;
break;
case V_177 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_193 < V_24 )
* V_193 = ' ' ;
++ V_193 ;
}
}
V_44 = ( unsigned char ) F_89 ( char ) ;
if ( V_193 < V_24 )
* V_193 = V_44 ;
++ V_193 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_193 < V_24 )
* V_193 = ' ' ;
++ V_193 ;
}
break;
}
case V_178 : {
const char * V_202 = args ;
args += strlen ( V_202 ) + 1 ;
V_193 = string ( V_193 , V_24 , ( char * ) V_202 , V_26 ) ;
break;
}
case V_179 :
V_193 = F_67 ( V_49 , V_193 , V_24 , F_89 ( void * ) , V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_180 :
case V_181 :
if ( V_193 < V_24 )
* V_193 = '%' ;
++ V_193 ;
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_182 :
V_20 = F_89 (long long) ;
break;
case V_184 :
case V_183 :
V_20 = F_89 (unsigned long) ;
break;
case V_185 :
V_20 = F_89 ( T_3 ) ;
break;
case V_186 :
V_20 = F_89 ( V_199 ) ;
break;
case V_188 :
V_20 = F_89 (unsigned char) ;
break;
case V_187 :
V_20 = F_89 (signed char) ;
break;
case V_190 :
V_20 = F_89 (unsigned short) ;
break;
case V_189 :
V_20 = F_89 ( short ) ;
break;
case V_192 :
V_20 = F_89 (unsigned int) ;
break;
default:
V_20 = F_89 ( int ) ;
}
V_193 = F_15 ( V_193 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_193 < V_24 )
* V_193 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_89
return V_193 - V_9 ;
}
int F_90 ( T_5 * V_200 , T_3 V_19 , const char * V_49 , ... )
{
T_7 args ;
int V_203 ;
va_start ( args , V_49 ) ;
V_203 = F_85 ( V_200 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_203 ;
}
int vsscanf ( const char * V_9 , const char * V_49 , T_7 args )
{
const char * V_193 = V_9 ;
char * V_204 ;
char V_205 ;
int V_20 = 0 ;
T_4 V_176 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_206 ;
} V_90 ;
T_8 V_38 ;
bool V_207 ;
while ( * V_49 ) {
if ( isspace ( * V_49 ) ) {
V_49 = F_91 ( ++ V_49 ) ;
V_193 = F_91 ( V_193 ) ;
}
if ( * V_49 != '%' && * V_49 ) {
if ( * V_49 ++ != * V_193 ++ )
break;
continue;
}
if ( ! * V_49 )
break;
++ V_49 ;
if ( * V_49 == '*' ) {
if ( ! * V_193 )
break;
while ( ! isspace ( * V_49 ) && * V_49 != '%' && * V_49 )
V_49 ++ ;
while ( ! isspace ( * V_193 ) && * V_193 )
V_193 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_49 ) ) {
V_38 = F_7 ( & V_49 ) ;
if ( V_38 <= 0 )
break;
}
V_176 = - 1 ;
if ( * V_49 == 'h' || F_78 ( * V_49 ) == 'l' ||
F_78 ( * V_49 ) == 'z' ) {
V_176 = * V_49 ++ ;
if ( F_79 ( V_176 == * V_49 ) ) {
if ( V_176 == 'h' ) {
V_176 = 'H' ;
V_49 ++ ;
} else if ( V_176 == 'l' ) {
V_176 = 'L' ;
V_49 ++ ;
}
}
}
if ( ! * V_49 )
break;
if ( * V_49 == 'n' ) {
* va_arg ( args , int * ) = V_193 - V_9 ;
++ V_49 ;
continue;
}
if ( ! * V_193 )
break;
V_3 = 10 ;
V_207 = false ;
switch ( * V_49 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_193 ++ ;
} while ( -- V_38 > 0 && * V_193 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_208 ;
V_193 = F_91 ( V_193 ) ;
while ( * V_193 && ! isspace ( * V_193 ) && V_38 -- )
* V_7 ++ = * V_193 ++ ;
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
V_207 = true ;
case 'u' :
break;
case '%' :
if ( * V_193 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_193 = F_91 ( V_193 ) ;
V_205 = * V_193 ;
if ( V_207 && V_205 == '-' )
V_205 = * ( V_193 + 1 ) ;
if ( ! V_205
|| ( V_3 == 16 && ! isxdigit ( V_205 ) )
|| ( V_3 == 10 && ! isdigit ( V_205 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_205 ) || V_205 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_205 ) ) )
break;
if ( V_207 )
V_90 . V_7 = V_176 != 'L' ?
F_5 ( V_193 , & V_204 , V_3 ) :
F_6 ( V_193 , & V_204 , V_3 ) ;
else
V_90 . V_206 = V_176 != 'L' ?
F_4 ( V_193 , & V_204 , V_3 ) :
F_1 ( V_193 , & V_204 , V_3 ) ;
if ( V_38 > 0 && V_204 - V_193 > V_38 ) {
if ( V_3 == 0 )
F_2 ( V_193 , & V_3 ) ;
while ( V_204 - V_193 > V_38 ) {
if ( V_207 )
V_90 . V_7 = F_92 ( V_90 . V_7 , V_3 ) ;
else
V_90 . V_206 = F_93 ( V_90 . V_206 , V_3 ) ;
-- V_204 ;
}
}
switch ( V_176 ) {
case 'H' :
if ( V_207 )
* va_arg (args, signed char *) = V_90 . V_7 ;
else
* va_arg (args, unsigned char *) = V_90 . V_206 ;
break;
case 'h' :
if ( V_207 )
* va_arg ( args , short * ) = V_90 . V_7 ;
else
* va_arg (args, unsigned short *) = V_90 . V_206 ;
break;
case 'l' :
if ( V_207 )
* va_arg ( args , long * ) = V_90 . V_7 ;
else
* va_arg (args, unsigned long *) = V_90 . V_206 ;
break;
case 'L' :
if ( V_207 )
* va_arg (args, long long *) = V_90 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_90 . V_206 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_3 * ) = V_90 . V_206 ;
break;
default:
if ( V_207 )
* va_arg ( args , int * ) = V_90 . V_7 ;
else
* va_arg (args, unsigned int *) = V_90 . V_206 ;
break;
}
V_20 ++ ;
if ( ! V_204 )
break;
V_193 = V_204 ;
}
return V_20 ;
}
int sscanf ( const char * V_9 , const char * V_49 , ... )
{
T_7 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsscanf ( V_9 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
