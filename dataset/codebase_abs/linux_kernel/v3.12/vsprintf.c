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
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_76 , * V_70 ) ;
if ( V_61 -> V_76 != V_61 -> V_24 ) {
* V_51 ++ = '-' ;
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_24 , * V_70 ) ;
}
if ( V_69 ) {
if ( V_61 -> V_31 & V_77 )
V_51 = string ( V_51 , V_68 , L_10 , V_66 ) ;
if ( V_61 -> V_31 & V_78 )
V_51 = string ( V_51 , V_68 , L_11 , V_66 ) ;
if ( V_61 -> V_31 & V_79 )
V_51 = string ( V_51 , V_68 , L_12 , V_66 ) ;
if ( V_61 -> V_31 & V_80 )
V_51 = string ( V_51 , V_68 , L_13 , V_66 ) ;
} else {
V_51 = string ( V_51 , V_68 , L_14 , V_66 ) ;
V_51 = F_15 ( V_51 , V_68 , V_61 -> V_31 , V_67 ) ;
}
* V_51 ++ = ']' ;
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_58 , V_26 ) ;
}
static T_1
char * F_36 ( char * V_9 , char * V_24 , T_4 * V_81 , struct V_25 V_26 ,
const char * V_49 )
{
int V_8 , V_23 = 1 ;
char V_82 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_37 ( V_81 ) )
return string ( V_9 , V_24 , NULL , V_26 ) ;
switch ( V_49 [ 1 ] ) {
case 'C' :
V_82 = ':' ;
break;
case 'D' :
V_82 = '-' ;
break;
case 'N' :
V_82 = 0 ;
break;
default:
V_82 = ' ' ;
break;
}
if ( V_26 . V_38 > 0 )
V_23 = F_38 ( int , V_26 . V_38 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_23 && V_9 < V_24 - 1 ; V_8 ++ ) {
V_9 = F_39 ( V_9 , V_81 [ V_8 ] ) ;
if ( V_9 < V_24 && V_82 && V_8 != V_23 - 1 )
* V_9 ++ = V_82 ;
}
return V_9 ;
}
static T_1
char * F_40 ( char * V_9 , char * V_24 , T_4 * V_81 ,
struct V_25 V_26 , const char * V_49 )
{
char V_83 [ sizeof( L_15 ) ] ;
char * V_51 = V_83 ;
int V_8 ;
char V_82 ;
bool V_84 = false ;
switch ( V_49 [ 1 ] ) {
case 'F' :
V_82 = '-' ;
break;
case 'R' :
V_84 = true ;
default:
V_82 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_84 )
V_51 = F_39 ( V_51 , V_81 [ 5 - V_8 ] ) ;
else
V_51 = F_39 ( V_51 , V_81 [ V_8 ] ) ;
if ( V_49 [ 0 ] == 'M' && V_8 != 5 )
* V_51 ++ = V_82 ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_83 , V_26 ) ;
}
static T_1
char * F_41 ( char * V_51 , const T_4 * V_81 , const char * V_49 )
{
int V_8 ;
bool V_85 = ( V_49 [ 0 ] == 'i' ) ;
int V_86 ;
int V_87 ;
switch ( V_49 [ 2 ] ) {
case 'h' :
#ifdef F_42
V_86 = 0 ;
V_87 = 1 ;
#else
V_86 = 3 ;
V_87 = - 1 ;
#endif
break;
case 'l' :
V_86 = 3 ;
V_87 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_86 = 0 ;
V_87 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_88 [ 3 ] ;
int V_27 = F_9 ( V_88 , V_81 [ V_86 ] ) - V_88 ;
if ( V_85 ) {
if ( V_27 < 3 )
* V_51 ++ = '0' ;
if ( V_27 < 2 )
* V_51 ++ = '0' ;
}
while ( V_27 -- )
* V_51 ++ = V_88 [ V_27 ] ;
if ( V_8 < 3 )
* V_51 ++ = '.' ;
V_86 += V_87 ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_43 ( char * V_51 , const char * V_81 )
{
int V_8 , V_89 , V_90 ;
unsigned char V_91 [ 8 ] ;
int V_92 = 1 ;
int V_93 = - 1 ;
T_5 V_94 ;
T_4 V_95 , V_96 ;
bool V_97 = false ;
bool V_98 ;
struct V_99 V_100 ;
memcpy ( & V_100 , V_81 , sizeof( struct V_99 ) ) ;
V_98 = F_44 ( & V_100 ) || F_45 ( & V_100 ) ;
memset ( V_91 , 0 , sizeof( V_91 ) ) ;
if ( V_98 )
V_90 = 6 ;
else
V_90 = 8 ;
for ( V_8 = 0 ; V_8 < V_90 ; V_8 ++ ) {
for ( V_89 = V_8 ; V_89 < V_90 ; V_89 ++ ) {
if ( V_100 . V_101 [ V_89 ] != 0 )
break;
V_91 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_90 ; V_8 ++ ) {
if ( V_91 [ V_8 ] > V_92 ) {
V_92 = V_91 [ V_8 ] ;
V_93 = V_8 ;
}
}
if ( V_92 == 1 )
V_93 = - 1 ;
for ( V_8 = 0 ; V_8 < V_90 ; V_8 ++ ) {
if ( V_8 == V_93 ) {
if ( V_97 || V_8 == 0 )
* V_51 ++ = ':' ;
* V_51 ++ = ':' ;
V_97 = false ;
V_8 += V_92 - 1 ;
continue;
}
if ( V_97 ) {
* V_51 ++ = ':' ;
V_97 = false ;
}
V_94 = F_46 ( V_100 . V_101 [ V_8 ] ) ;
V_95 = V_94 >> 8 ;
V_96 = V_94 & 0xff ;
if ( V_95 ) {
if ( V_95 > 0x0f )
V_51 = F_39 ( V_51 , V_95 ) ;
else
* V_51 ++ = F_47 ( V_95 ) ;
V_51 = F_39 ( V_51 , V_96 ) ;
}
else if ( V_96 > 0x0f )
V_51 = F_39 ( V_51 , V_96 ) ;
else
* V_51 ++ = F_47 ( V_96 ) ;
V_97 = true ;
}
if ( V_98 ) {
if ( V_97 )
* V_51 ++ = ':' ;
V_51 = F_41 ( V_51 , & V_100 . V_102 [ 12 ] , L_16 ) ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_48 ( char * V_51 , const char * V_81 , const char * V_49 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_51 = F_39 ( V_51 , * V_81 ++ ) ;
V_51 = F_39 ( V_51 , * V_81 ++ ) ;
if ( V_49 [ 0 ] == 'I' && V_8 != 7 )
* V_51 ++ = ':' ;
}
* V_51 = '\0' ;
return V_51 ;
}
static T_1
char * F_49 ( char * V_9 , char * V_24 , const T_4 * V_81 ,
struct V_25 V_26 , const char * V_49 )
{
char V_103 [ sizeof( L_17 ) ] ;
if ( V_49 [ 0 ] == 'I' && V_49 [ 2 ] == 'c' )
F_43 ( V_103 , V_81 ) ;
else
F_48 ( V_103 , V_81 , V_49 ) ;
return string ( V_9 , V_24 , V_103 , V_26 ) ;
}
static T_1
char * F_50 ( char * V_9 , char * V_24 , const T_4 * V_81 ,
struct V_25 V_26 , const char * V_49 )
{
char V_104 [ sizeof( L_18 ) ] ;
F_41 ( V_104 , V_81 , V_49 ) ;
return string ( V_9 , V_24 , V_104 , V_26 ) ;
}
static T_1
char * F_51 ( char * V_9 , char * V_24 , const struct V_105 * V_106 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_107 = false , V_108 = false , V_109 = false , V_110 = false ;
char V_103 [ sizeof( L_19 ) +
sizeof( L_20 ) + sizeof( L_21 ) +
sizeof( L_22 ) ] ;
char * V_51 = V_103 , * V_68 = V_103 + sizeof( V_103 ) ;
const T_4 * V_81 = ( const T_4 * ) & V_106 -> V_111 ;
char V_112 [ 2 ] = { V_49 [ 0 ] , '6' } ;
T_4 V_113 = 0 ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_107 = true ;
break;
case 'f' :
V_109 = true ;
break;
case 's' :
V_108 = true ;
break;
case 'c' :
V_110 = true ;
break;
}
}
if ( V_107 || V_108 || V_109 ) {
* V_51 = '[' ;
V_113 = 1 ;
}
if ( V_112 [ 0 ] == 'I' && V_110 )
V_51 = F_43 ( V_103 + V_113 , V_81 ) ;
else
V_51 = F_48 ( V_103 + V_113 , V_81 , V_112 ) ;
if ( V_107 || V_108 || V_109 )
* V_51 ++ = ']' ;
if ( V_107 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_46 ( V_106 -> V_114 ) , V_26 ) ;
}
if ( V_109 ) {
* V_51 ++ = '/' ;
V_51 = F_15 ( V_51 , V_68 , F_52 ( V_106 -> V_115 &
V_116 ) , V_26 ) ;
}
if ( V_108 ) {
* V_51 ++ = '%' ;
V_51 = F_15 ( V_51 , V_68 , V_106 -> V_117 , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_103 , V_26 ) ;
}
static T_1
char * F_53 ( char * V_9 , char * V_24 , const struct V_118 * V_106 ,
struct V_25 V_26 , const char * V_49 )
{
bool V_107 = false ;
char * V_51 , V_104 [ sizeof( L_18 ) + sizeof( L_20 ) ] ;
char * V_68 = V_104 + sizeof( V_104 ) ;
const T_4 * V_81 = ( const T_4 * ) & V_106 -> V_119 . V_120 ;
char V_121 [ 3 ] = { V_49 [ 0 ] , '4' , 0 } ;
V_49 ++ ;
while ( isalpha ( * ++ V_49 ) ) {
switch ( * V_49 ) {
case 'p' :
V_107 = true ;
break;
case 'h' :
case 'l' :
case 'n' :
case 'b' :
V_121 [ 2 ] = * V_49 ;
break;
}
}
V_51 = F_41 ( V_104 , V_81 , V_121 ) ;
if ( V_107 ) {
* V_51 ++ = ':' ;
V_51 = F_15 ( V_51 , V_68 , F_46 ( V_106 -> V_122 ) , V_26 ) ;
}
* V_51 = '\0' ;
return string ( V_9 , V_24 , V_104 , V_26 ) ;
}
static T_1
char * F_54 ( char * V_9 , char * V_24 , const T_4 * V_81 ,
struct V_25 V_26 , const char * V_49 )
{
char V_123 [ sizeof( L_23 ) ] ;
char * V_51 = V_123 ;
int V_8 ;
static const T_4 V_124 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_4 V_125 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_4 * V_86 = V_124 ;
bool V_126 = false ;
switch ( * ( ++ V_49 ) ) {
case 'L' :
V_126 = true ;
case 'l' :
V_86 = V_125 ;
break;
case 'B' :
V_126 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_51 = F_39 ( V_51 , V_81 [ V_86 [ V_8 ] ] ) ;
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
if ( V_126 ) {
V_51 = V_123 ;
do {
* V_51 = toupper ( * V_51 ) ;
} while ( * ( ++ V_51 ) );
}
return string ( V_9 , V_24 , V_123 , V_26 ) ;
}
static
char * F_55 ( char * V_9 , char * V_24 , const T_4 * V_81 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_127 ) ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , * ( const V_127 * ) V_81 , V_26 ) ;
}
static T_1
char * F_56 ( const char * V_49 , char * V_9 , char * V_24 , void * V_56 ,
struct V_25 V_26 )
{
int V_128 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_56 && * V_49 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_128 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_49 ) {
case 'F' :
case 'f' :
V_56 = F_57 ( V_56 ) ;
case 'S' :
case 's' :
case 'B' :
return F_22 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'R' :
case 'r' :
return F_28 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'h' :
return F_36 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'M' :
case 'm' :
return F_40 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'I' :
case 'i' :
switch ( V_49 [ 1 ] ) {
case '6' :
return F_49 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case '4' :
return F_50 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'S' : {
const union {
struct V_129 V_130 ;
struct V_118 V_131 ;
struct V_105 V_132 ;
} * V_106 = V_56 ;
switch ( V_106 -> V_130 . V_133 ) {
case V_134 :
return F_53 ( V_9 , V_24 , & V_106 -> V_131 , V_26 , V_49 ) ;
case V_135 :
return F_51 ( V_9 , V_24 , & V_106 -> V_132 , V_26 , V_49 ) ;
default:
return string ( V_9 , V_24 , L_24 , V_26 ) ;
} }
}
break;
case 'U' :
return F_54 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'V' :
{
T_6 V_136 ;
F_58 ( V_136 , * ( (struct V_137 * ) V_56 ) -> V_136 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_137 * ) V_56 ) -> V_49 , V_136 ) ;
va_end ( V_136 ) ;
return V_9 ;
}
case 'K' :
if ( V_138 && ( F_59 () || F_60 () ||
F_61 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_128 ;
return string ( V_9 , V_24 , L_25 , V_26 ) ;
}
if ( ! ( ( V_138 == 0 ) ||
( V_138 == 1 &&
F_62 ( V_139 , V_140 ) ) ) )
V_56 = NULL ;
break;
case 'N' :
switch ( V_49 [ 1 ] ) {
case 'F' :
return F_55 ( V_9 , V_24 , V_56 , V_26 ) ;
}
break;
case 'a' :
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_38 = sizeof( V_141 ) * 2 + 2 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 ,
( unsigned long long ) * ( ( V_141 * ) V_56 ) , V_26 ) ;
case 'd' :
return F_18 ( V_9 , V_24 , V_56 , V_26 , V_49 ) ;
case 'D' :
return F_18 ( V_9 , V_24 ,
( ( const struct V_142 * ) V_56 ) -> V_143 . V_47 ,
V_26 , V_49 ) ;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_128 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , ( unsigned long ) V_56 , V_26 ) ;
}
static T_1
int F_63 ( const char * V_49 , struct V_25 * V_26 )
{
const char * V_76 = V_49 ;
if ( V_26 -> type == V_144 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_145 ;
goto V_43;
}
if ( V_26 -> type == V_146 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_145 ;
goto V_147;
}
V_26 -> type = V_145 ;
for (; * V_49 ; ++ V_49 ) {
if ( * V_49 == '%' )
break;
}
if ( V_49 != V_76 || ! * V_49 )
return V_49 - V_76 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_148 = true ;
++ V_49 ;
switch ( * V_49 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_148 = false ;
}
if ( ! V_148 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_49 ) )
V_26 -> V_38 = F_7 ( & V_49 ) ;
else if ( * V_49 == '*' ) {
V_26 -> type = V_144 ;
return ++ V_49 - V_76 ;
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
V_26 -> type = V_146 ;
return ++ V_49 - V_76 ;
}
}
V_147:
V_26 -> V_147 = - 1 ;
if ( * V_49 == 'h' || F_64 ( * V_49 ) == 'l' ||
F_64 ( * V_49 ) == 'z' || * V_49 == 't' ) {
V_26 -> V_147 = * V_49 ++ ;
if ( F_65 ( V_26 -> V_147 == * V_49 ) ) {
if ( V_26 -> V_147 == 'l' ) {
V_26 -> V_147 = 'L' ;
++ V_49 ;
} else if ( V_26 -> V_147 == 'h' ) {
V_26 -> V_147 = 'H' ;
++ V_49 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_49 ) {
case 'c' :
V_26 -> type = V_149 ;
return ++ V_49 - V_76 ;
case 's' :
V_26 -> type = V_150 ;
return ++ V_49 - V_76 ;
case 'p' :
V_26 -> type = V_151 ;
return V_49 - V_76 ;
case 'n' :
V_26 -> type = V_152 ;
return ++ V_49 - V_76 ;
case '%' :
V_26 -> type = V_153 ;
return ++ V_49 - V_76 ;
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
default:
V_26 -> type = V_154 ;
return V_49 - V_76 ;
}
if ( V_26 -> V_147 == 'L' )
V_26 -> type = V_155 ;
else if ( V_26 -> V_147 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_156 ;
else
V_26 -> type = V_157 ;
} else if ( F_64 ( V_26 -> V_147 ) == 'z' ) {
V_26 -> type = V_158 ;
} else if ( V_26 -> V_147 == 't' ) {
V_26 -> type = V_159 ;
} else if ( V_26 -> V_147 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_160 ;
else
V_26 -> type = V_161 ;
} else if ( V_26 -> V_147 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_162 ;
else
V_26 -> type = V_163 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_164 ;
else
V_26 -> type = V_165 ;
}
return ++ V_49 - V_76 ;
}
int vsnprintf ( char * V_9 , T_3 V_19 , const char * V_49 , T_6 args )
{
unsigned long long V_20 ;
char * V_166 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_66 ( ( int ) V_19 < 0 ) )
return 0 ;
V_166 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_49 ) {
const char * V_167 = V_49 ;
int V_168 = F_63 ( V_49 , & V_26 ) ;
V_49 += V_168 ;
switch ( V_26 . type ) {
case V_145 : {
int V_169 = V_168 ;
if ( V_166 < V_24 ) {
if ( V_169 > V_24 - V_166 )
V_169 = V_24 - V_166 ;
memcpy ( V_166 , V_167 , V_169 ) ;
}
V_166 += V_168 ;
break;
}
case V_144 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_146 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_149 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_166 < V_24 )
* V_166 = ' ' ;
++ V_166 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_166 < V_24 )
* V_166 = V_44 ;
++ V_166 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_166 < V_24 )
* V_166 = ' ' ;
++ V_166 ;
}
break;
}
case V_150 :
V_166 = string ( V_166 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_151 :
V_166 = F_56 ( V_49 + 1 , V_166 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_153 :
if ( V_166 < V_24 )
* V_166 = '%' ;
++ V_166 ;
break;
case V_154 :
if ( V_166 < V_24 )
* V_166 = '%' ;
++ V_166 ;
break;
case V_152 : {
T_4 V_147 = V_26 . V_147 ;
if ( V_147 == 'l' ) {
long * V_170 = va_arg ( args , long * ) ;
* V_170 = ( V_166 - V_9 ) ;
} else if ( F_64 ( V_147 ) == 'z' ) {
T_3 * V_170 = va_arg ( args , T_3 * ) ;
* V_170 = ( V_166 - V_9 ) ;
} else {
int * V_170 = va_arg ( args , int * ) ;
* V_170 = ( V_166 - V_9 ) ;
}
break;
}
default:
switch ( V_26 . type ) {
case V_155 :
V_20 = va_arg (args, long long) ;
break;
case V_157 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_156 :
V_20 = va_arg ( args , long ) ;
break;
case V_158 :
if ( V_26 . V_31 & V_37 )
V_20 = va_arg ( args , V_171 ) ;
else
V_20 = va_arg ( args , T_3 ) ;
break;
case V_159 :
V_20 = va_arg ( args , V_172 ) ;
break;
case V_161 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_160 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_163 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_162 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_164 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_166 = F_15 ( V_166 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_166 < V_24 )
* V_166 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_166 - V_9 ;
}
int F_67 ( char * V_9 , T_3 V_19 , const char * V_49 , T_6 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_49 , args ) ;
if ( F_68 ( V_8 < V_19 ) )
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
int F_69 ( char * V_9 , T_3 V_19 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = F_67 ( V_9 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_49 , T_6 args )
{
return vsnprintf ( V_9 , V_173 , V_49 , args ) ;
}
int sprintf ( char * V_9 , const char * V_49 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_173 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_70 ( T_7 * V_174 , T_3 V_19 , const char * V_49 , T_6 args )
{
struct V_25 V_26 = { 0 } ;
char * V_166 , * V_24 ;
V_166 = ( char * ) V_174 ;
V_24 = ( char * ) ( V_174 + V_19 ) ;
#define F_71 ( type ) \
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
int V_168 = F_63 ( V_49 , & V_26 ) ;
V_49 += V_168 ;
switch ( V_26 . type ) {
case V_145 :
case V_154 :
case V_153 :
break;
case V_144 :
case V_146 :
F_71 ( int ) ;
break;
case V_149 :
F_71 ( char ) ;
break;
case V_150 : {
const char * V_175 = va_arg ( args , char * ) ;
T_3 V_23 ;
if ( ( unsigned long ) V_175 > ( unsigned long ) - V_45
|| ( unsigned long ) V_175 < V_45 )
V_175 = L_2 ;
V_23 = strlen ( V_175 ) + 1 ;
if ( V_166 + V_23 < V_24 )
memcpy ( V_166 , V_175 , V_23 ) ;
V_166 += V_23 ;
break;
}
case V_151 :
F_71 ( void * ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_152 : {
T_4 V_147 = V_26 . V_147 ;
void * V_176 ;
if ( V_147 == 'l' )
V_176 = va_arg ( args , long * ) ;
else if ( F_64 ( V_147 ) == 'z' )
V_176 = va_arg ( args , T_3 * ) ;
else
V_176 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_26 . type ) {
case V_155 :
F_71 (long long) ;
break;
case V_157 :
case V_156 :
F_71 (unsigned long) ;
break;
case V_158 :
F_71 ( T_3 ) ;
break;
case V_159 :
F_71 ( V_172 ) ;
break;
case V_161 :
case V_160 :
F_71 ( char ) ;
break;
case V_163 :
case V_162 :
F_71 ( short ) ;
break;
default:
F_71 ( int ) ;
}
}
}
return ( T_7 * ) ( F_72 ( V_166 , sizeof( T_7 ) ) ) - V_174 ;
#undef F_71
}
int F_73 ( char * V_9 , T_3 V_19 , const char * V_49 , const T_7 * V_174 )
{
struct V_25 V_26 = { 0 } ;
char * V_166 , * V_24 ;
const char * args = ( const char * ) V_174 ;
if ( F_66 ( ( int ) V_19 < 0 ) )
return 0 ;
V_166 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_74 ( type ) \
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
const char * V_167 = V_49 ;
int V_168 = F_63 ( V_49 , & V_26 ) ;
V_49 += V_168 ;
switch ( V_26 . type ) {
case V_145 : {
int V_169 = V_168 ;
if ( V_166 < V_24 ) {
if ( V_169 > V_24 - V_166 )
V_169 = V_24 - V_166 ;
memcpy ( V_166 , V_167 , V_169 ) ;
}
V_166 += V_168 ;
break;
}
case V_144 :
V_26 . V_38 = F_74 ( int ) ;
break;
case V_146 :
V_26 . V_43 = F_74 ( int ) ;
break;
case V_149 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_166 < V_24 )
* V_166 = ' ' ;
++ V_166 ;
}
}
V_44 = ( unsigned char ) F_74 ( char ) ;
if ( V_166 < V_24 )
* V_166 = V_44 ;
++ V_166 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_166 < V_24 )
* V_166 = ' ' ;
++ V_166 ;
}
break;
}
case V_150 : {
const char * V_177 = args ;
args += strlen ( V_177 ) + 1 ;
V_166 = string ( V_166 , V_24 , ( char * ) V_177 , V_26 ) ;
break;
}
case V_151 :
V_166 = F_56 ( V_49 + 1 , V_166 , V_24 , F_74 ( void * ) , V_26 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_153 :
case V_154 :
if ( V_166 < V_24 )
* V_166 = '%' ;
++ V_166 ;
break;
case V_152 :
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_155 :
V_20 = F_74 (long long) ;
break;
case V_157 :
case V_156 :
V_20 = F_74 (unsigned long) ;
break;
case V_158 :
V_20 = F_74 ( T_3 ) ;
break;
case V_159 :
V_20 = F_74 ( V_172 ) ;
break;
case V_161 :
V_20 = F_74 (unsigned char) ;
break;
case V_160 :
V_20 = F_74 (signed char) ;
break;
case V_163 :
V_20 = F_74 (unsigned short) ;
break;
case V_162 :
V_20 = F_74 ( short ) ;
break;
case V_165 :
V_20 = F_74 (unsigned int) ;
break;
default:
V_20 = F_74 ( int ) ;
}
V_166 = F_15 ( V_166 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_166 < V_24 )
* V_166 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_74
return V_166 - V_9 ;
}
int F_75 ( T_7 * V_174 , T_3 V_19 , const char * V_49 , ... )
{
T_6 args ;
int V_178 ;
va_start ( args , V_49 ) ;
V_178 = F_70 ( V_174 , V_19 , V_49 , args ) ;
va_end ( args ) ;
return V_178 ;
}
int vsscanf ( const char * V_9 , const char * V_49 , T_6 args )
{
const char * V_166 = V_9 ;
char * V_179 ;
char V_180 ;
int V_20 = 0 ;
T_4 V_147 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_181 ;
} V_182 ;
T_8 V_38 ;
bool V_183 ;
while ( * V_49 ) {
if ( isspace ( * V_49 ) ) {
V_49 = F_76 ( ++ V_49 ) ;
V_166 = F_76 ( V_166 ) ;
}
if ( * V_49 != '%' && * V_49 ) {
if ( * V_49 ++ != * V_166 ++ )
break;
continue;
}
if ( ! * V_49 )
break;
++ V_49 ;
if ( * V_49 == '*' ) {
if ( ! * V_166 )
break;
while ( ! isspace ( * V_49 ) && * V_49 != '%' && * V_49 )
V_49 ++ ;
while ( ! isspace ( * V_166 ) && * V_166 )
V_166 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_49 ) ) {
V_38 = F_7 ( & V_49 ) ;
if ( V_38 <= 0 )
break;
}
V_147 = - 1 ;
if ( * V_49 == 'h' || F_64 ( * V_49 ) == 'l' ||
F_64 ( * V_49 ) == 'z' ) {
V_147 = * V_49 ++ ;
if ( F_65 ( V_147 == * V_49 ) ) {
if ( V_147 == 'h' ) {
V_147 = 'H' ;
V_49 ++ ;
} else if ( V_147 == 'l' ) {
V_147 = 'L' ;
V_49 ++ ;
}
}
}
if ( ! * V_49 )
break;
if ( * V_49 == 'n' ) {
* va_arg ( args , int * ) = V_166 - V_9 ;
++ V_49 ;
continue;
}
if ( ! * V_166 )
break;
V_3 = 10 ;
V_183 = 0 ;
switch ( * V_49 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_166 ++ ;
} while ( -- V_38 > 0 && * V_166 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_184 ;
V_166 = F_76 ( V_166 ) ;
while ( * V_166 && ! isspace ( * V_166 ) && V_38 -- )
* V_7 ++ = * V_166 ++ ;
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
V_183 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_166 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_166 = F_76 ( V_166 ) ;
V_180 = * V_166 ;
if ( V_183 && V_180 == '-' )
V_180 = * ( V_166 + 1 ) ;
if ( ! V_180
|| ( V_3 == 16 && ! isxdigit ( V_180 ) )
|| ( V_3 == 10 && ! isdigit ( V_180 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_180 ) || V_180 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_180 ) ) )
break;
if ( V_183 )
V_182 . V_7 = V_147 != 'L' ?
F_5 ( V_166 , & V_179 , V_3 ) :
F_6 ( V_166 , & V_179 , V_3 ) ;
else
V_182 . V_181 = V_147 != 'L' ?
F_4 ( V_166 , & V_179 , V_3 ) :
F_1 ( V_166 , & V_179 , V_3 ) ;
if ( V_38 > 0 && V_179 - V_166 > V_38 ) {
if ( V_3 == 0 )
F_2 ( V_166 , & V_3 ) ;
while ( V_179 - V_166 > V_38 ) {
if ( V_183 )
V_182 . V_7 = F_77 ( V_182 . V_7 , V_3 ) ;
else
V_182 . V_181 = F_78 ( V_182 . V_181 , V_3 ) ;
-- V_179 ;
}
}
switch ( V_147 ) {
case 'H' :
if ( V_183 )
* va_arg (args, signed char *) = V_182 . V_7 ;
else
* va_arg (args, unsigned char *) = V_182 . V_181 ;
break;
case 'h' :
if ( V_183 )
* va_arg ( args , short * ) = V_182 . V_7 ;
else
* va_arg (args, unsigned short *) = V_182 . V_181 ;
break;
case 'l' :
if ( V_183 )
* va_arg ( args , long * ) = V_182 . V_7 ;
else
* va_arg (args, unsigned long *) = V_182 . V_181 ;
break;
case 'L' :
if ( V_183 )
* va_arg (args, long long *) = V_182 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_182 . V_181 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_3 * ) = V_182 . V_181 ;
break;
default:
if ( V_183 )
* va_arg ( args , int * ) = V_182 . V_7 ;
else
* va_arg (args, unsigned int *) = V_182 . V_181 ;
break;
}
V_20 ++ ;
if ( ! V_179 )
break;
V_166 = V_179 ;
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
