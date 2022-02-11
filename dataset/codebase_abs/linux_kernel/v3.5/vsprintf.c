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
V_10 = ( V_11 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
if ( V_10 == 0 )
return V_9 ;
V_11 = ( V_10 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
if ( V_11 == 0 )
return V_9 ;
V_10 = ( V_11 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
if ( V_10 == 0 )
return V_9 ;
V_11 = ( V_10 * ( V_12 ) 0x1999999a ) >> 32 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
if ( V_11 == 0 )
return V_9 ;
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
char * F_12 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 ;
V_11 = ( V_10 * 0xcccd ) >> 19 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
V_10 = ( V_11 * 0x199a ) >> 16 ;
* V_9 ++ = ( V_11 - 10 * V_10 ) + '0' ;
V_11 = ( V_10 * 0xcd ) >> 11 ;
* V_9 ++ = ( V_10 - 10 * V_11 ) + '0' ;
* V_9 ++ = V_11 + '0' ;
return V_9 ;
}
static
char * F_10 ( char * V_9 , unsigned long long V_13 )
{
T_2 V_14 , V_15 , V_16 , V_10 , V_17 ;
if ( V_13 < 100 * 1000 * 1000 )
return F_9 ( V_9 , V_13 ) ;
V_16 = ( ( T_2 ) V_13 >> 16 ) ;
V_17 = ( V_13 >> 32 ) ;
V_15 = ( V_17 ) & 0xffff ;
V_14 = ( V_17 >> 16 ) ;
V_10 = 656 * V_14 + 7296 * V_15 + 5536 * V_16 + ( ( T_2 ) V_13 & 0xffff ) ;
V_9 = F_12 ( V_9 , V_10 % 10000 ) ;
V_10 = V_10 / 10000 ;
V_16 = V_10 + 7671 * V_14 + 9496 * V_15 + 6 * V_16 ;
V_9 = F_12 ( V_9 , V_16 % 10000 ) ;
V_10 = V_16 / 10000 ;
V_15 = V_10 + 4749 * V_14 + 42 * V_15 ;
V_9 = F_12 ( V_9 , V_15 % 10000 ) ;
V_10 = V_15 / 10000 ;
V_14 = V_10 + 281 * V_14 ;
if ( ! V_14 )
goto V_18;
V_9 = F_12 ( V_9 , V_14 % 10000 ) ;
V_10 = V_14 / 10000 ;
if ( ! V_10 )
goto V_18;
V_9 = F_12 ( V_9 , V_10 ) ;
V_18:
while ( V_9 [ - 1 ] == '0' )
-- V_9 ;
return V_9 ;
}
int F_13 ( char * V_9 , int V_19 , unsigned long long V_20 )
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
char * F_14 ( char * V_9 , char * V_24 , unsigned long long V_20 ,
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
V_23 = F_15 ( V_7 , V_26 . V_43 ) ;
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
static T_1
char * F_16 ( char * V_9 , char * V_24 , void * V_46 ,
struct V_25 V_26 , char V_47 )
{
unsigned long V_48 = ( unsigned long ) V_46 ;
#ifdef F_17
char V_49 [ V_50 ] ;
if ( V_47 == 'B' )
F_18 ( V_49 , V_48 ) ;
else if ( V_47 != 'f' && V_47 != 's' )
F_19 ( V_49 , V_48 ) ;
else
F_20 ( V_49 , V_48 ) ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
#else
V_26 . V_38 = 2 * sizeof( void * ) ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
return F_14 ( V_9 , V_24 , V_48 , V_26 ) ;
#endif
}
static T_1
char * F_21 ( char * V_9 , char * V_24 , struct V_51 * V_52 ,
struct V_25 V_26 , const char * V_53 )
{
#ifndef F_22
#define F_22 6
#endif
#ifndef F_23
#define F_23 10
#endif
static const struct V_25 V_54 = {
. V_3 = 16 ,
. V_38 = F_22 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_55 = {
. V_3 = 16 ,
. V_38 = F_23 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_56 = {
. V_3 = 16 ,
. V_38 = 2 ,
. V_43 = - 1 ,
. V_31 = V_34 | V_36 ,
} ;
static const struct V_25 V_57 = {
. V_3 = 10 ,
. V_43 = - 1 ,
. V_31 = 0 ,
} ;
static const struct V_25 V_58 = {
. V_38 = - 1 ,
. V_43 = 10 ,
. V_31 = V_35 ,
} ;
static const struct V_25 V_59 = {
. V_3 = 16 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 ,
} ;
#define F_24 ((2 * sizeof(resource_size_t)) + 4)
#define F_25 (2 * sizeof(res->flags))
#define F_26 sizeof("[mem - 64bit pref window disabled]")
#define F_27 sizeof("[mem - flags 0x]")
char V_49 [ F_28 ( 2 * F_24 + F_26 ,
2 * F_24 + F_25 + F_27 ) ] ;
char * V_60 = V_49 , * V_61 = V_49 + sizeof( V_49 ) ;
int V_62 = ( V_53 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_25 * V_63 ;
* V_60 ++ = '[' ;
if ( V_52 -> V_31 & V_64 ) {
V_60 = string ( V_60 , V_61 , L_3 , V_58 ) ;
V_63 = & V_54 ;
} else if ( V_52 -> V_31 & V_65 ) {
V_60 = string ( V_60 , V_61 , L_4 , V_58 ) ;
V_63 = & V_55 ;
} else if ( V_52 -> V_31 & V_66 ) {
V_60 = string ( V_60 , V_61 , L_5 , V_58 ) ;
V_63 = & V_57 ;
} else if ( V_52 -> V_31 & V_67 ) {
V_60 = string ( V_60 , V_61 , L_6 , V_58 ) ;
V_63 = & V_57 ;
} else if ( V_52 -> V_31 & V_68 ) {
V_60 = string ( V_60 , V_61 , L_7 , V_58 ) ;
V_63 = & V_56 ;
} else {
V_60 = string ( V_60 , V_61 , L_8 , V_58 ) ;
V_63 = & V_55 ;
V_62 = 0 ;
}
V_60 = F_14 ( V_60 , V_61 , V_52 -> V_69 , * V_63 ) ;
if ( V_52 -> V_69 != V_52 -> V_24 ) {
* V_60 ++ = '-' ;
V_60 = F_14 ( V_60 , V_61 , V_52 -> V_24 , * V_63 ) ;
}
if ( V_62 ) {
if ( V_52 -> V_31 & V_70 )
V_60 = string ( V_60 , V_61 , L_9 , V_58 ) ;
if ( V_52 -> V_31 & V_71 )
V_60 = string ( V_60 , V_61 , L_10 , V_58 ) ;
if ( V_52 -> V_31 & V_72 )
V_60 = string ( V_60 , V_61 , L_11 , V_58 ) ;
if ( V_52 -> V_31 & V_73 )
V_60 = string ( V_60 , V_61 , L_12 , V_58 ) ;
} else {
V_60 = string ( V_60 , V_61 , L_13 , V_58 ) ;
V_60 = F_14 ( V_60 , V_61 , V_52 -> V_31 , V_59 ) ;
}
* V_60 ++ = ']' ;
* V_60 = '\0' ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
}
static T_1
char * F_29 ( char * V_9 , char * V_24 , T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_75 [ sizeof( L_14 ) ] ;
char * V_60 = V_75 ;
int V_8 ;
char V_76 ;
if ( V_53 [ 1 ] == 'F' ) {
V_76 = '-' ;
} else {
V_76 = ':' ;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_60 = F_30 ( V_60 , V_74 [ V_8 ] ) ;
if ( V_53 [ 0 ] == 'M' && V_8 != 5 )
* V_60 ++ = V_76 ;
}
* V_60 = '\0' ;
return string ( V_9 , V_24 , V_75 , V_26 ) ;
}
static T_1
char * F_31 ( char * V_60 , const T_3 * V_74 , const char * V_53 )
{
int V_8 ;
bool V_77 = ( V_53 [ 0 ] == 'i' ) ;
int V_78 ;
int V_79 ;
switch ( V_53 [ 2 ] ) {
case 'h' :
#ifdef F_32
V_78 = 0 ;
V_79 = 1 ;
#else
V_78 = 3 ;
V_79 = - 1 ;
#endif
break;
case 'l' :
V_78 = 3 ;
V_79 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_78 = 0 ;
V_79 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_80 [ 3 ] ;
int V_27 = F_9 ( V_80 , V_74 [ V_78 ] ) - V_80 ;
if ( V_77 ) {
if ( V_27 < 3 )
* V_60 ++ = '0' ;
if ( V_27 < 2 )
* V_60 ++ = '0' ;
}
while ( V_27 -- )
* V_60 ++ = V_80 [ V_27 ] ;
if ( V_8 < 3 )
* V_60 ++ = '.' ;
V_78 += V_79 ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_33 ( char * V_60 , const char * V_74 )
{
int V_8 , V_81 , V_82 ;
unsigned char V_83 [ 8 ] ;
int V_84 = 1 ;
int V_85 = - 1 ;
T_4 V_86 ;
T_3 V_87 , V_88 ;
bool V_89 = false ;
bool V_90 ;
struct V_91 V_92 ;
memcpy ( & V_92 , V_74 , sizeof( struct V_91 ) ) ;
V_90 = F_34 ( & V_92 ) || F_35 ( & V_92 ) ;
memset ( V_83 , 0 , sizeof( V_83 ) ) ;
if ( V_90 )
V_82 = 6 ;
else
V_82 = 8 ;
for ( V_8 = 0 ; V_8 < V_82 ; V_8 ++ ) {
for ( V_81 = V_8 ; V_81 < V_82 ; V_81 ++ ) {
if ( V_92 . V_93 [ V_81 ] != 0 )
break;
V_83 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_82 ; V_8 ++ ) {
if ( V_83 [ V_8 ] > V_84 ) {
V_84 = V_83 [ V_8 ] ;
V_85 = V_8 ;
}
}
if ( V_84 == 1 )
V_85 = - 1 ;
for ( V_8 = 0 ; V_8 < V_82 ; V_8 ++ ) {
if ( V_8 == V_85 ) {
if ( V_89 || V_8 == 0 )
* V_60 ++ = ':' ;
* V_60 ++ = ':' ;
V_89 = false ;
V_8 += V_84 - 1 ;
continue;
}
if ( V_89 ) {
* V_60 ++ = ':' ;
V_89 = false ;
}
V_86 = F_36 ( V_92 . V_93 [ V_8 ] ) ;
V_87 = V_86 >> 8 ;
V_88 = V_86 & 0xff ;
if ( V_87 ) {
if ( V_87 > 0x0f )
V_60 = F_30 ( V_60 , V_87 ) ;
else
* V_60 ++ = F_37 ( V_87 ) ;
V_60 = F_30 ( V_60 , V_88 ) ;
}
else if ( V_88 > 0x0f )
V_60 = F_30 ( V_60 , V_88 ) ;
else
* V_60 ++ = F_37 ( V_88 ) ;
V_89 = true ;
}
if ( V_90 ) {
if ( V_89 )
* V_60 ++ = ':' ;
V_60 = F_31 ( V_60 , & V_92 . V_94 [ 12 ] , L_15 ) ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_38 ( char * V_60 , const char * V_74 , const char * V_53 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_60 = F_30 ( V_60 , * V_74 ++ ) ;
V_60 = F_30 ( V_60 , * V_74 ++ ) ;
if ( V_53 [ 0 ] == 'I' && V_8 != 7 )
* V_60 ++ = ':' ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_39 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_95 [ sizeof( L_16 ) ] ;
if ( V_53 [ 0 ] == 'I' && V_53 [ 2 ] == 'c' )
F_33 ( V_95 , V_74 ) ;
else
F_38 ( V_95 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_95 , V_26 ) ;
}
static T_1
char * F_40 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_96 [ sizeof( L_17 ) ] ;
F_31 ( V_96 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_96 , V_26 ) ;
}
static T_1
char * F_41 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_97 [ sizeof( L_18 ) ] ;
char * V_60 = V_97 ;
int V_8 ;
static const T_3 V_98 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_3 V_99 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_3 * V_78 = V_98 ;
bool V_100 = false ;
switch ( * ( ++ V_53 ) ) {
case 'L' :
V_100 = true ;
case 'l' :
V_78 = V_99 ;
break;
case 'B' :
V_100 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_60 = F_30 ( V_60 , V_74 [ V_78 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_60 ++ = '-' ;
break;
}
}
* V_60 = 0 ;
if ( V_100 ) {
V_60 = V_97 ;
do {
* V_60 = toupper ( * V_60 ) ;
} while ( * ( ++ V_60 ) );
}
return string ( V_9 , V_24 , V_97 , V_26 ) ;
}
static
char * F_42 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_101 ) ;
V_26 . V_3 = 16 ;
return F_14 ( V_9 , V_24 , * ( const V_101 * ) V_74 , V_26 ) ;
}
static T_1
char * F_43 ( const char * V_53 , char * V_9 , char * V_24 , void * V_46 ,
struct V_25 V_26 )
{
int V_102 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_46 && * V_53 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_102 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_53 ) {
case 'F' :
case 'f' :
V_46 = F_44 ( V_46 ) ;
case 'S' :
case 's' :
case 'B' :
return F_16 ( V_9 , V_24 , V_46 , V_26 , * V_53 ) ;
case 'R' :
case 'r' :
return F_21 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'M' :
case 'm' :
return F_29 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'I' :
case 'i' :
switch ( V_53 [ 1 ] ) {
case '6' :
return F_39 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case '4' :
return F_40 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
}
break;
case 'U' :
return F_41 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'V' :
{
T_5 V_103 ;
F_45 ( V_103 , * ( (struct V_104 * ) V_46 ) -> V_103 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_104 * ) V_46 ) -> V_53 , V_103 ) ;
va_end ( V_103 ) ;
return V_9 ;
}
case 'K' :
if ( F_46 () || F_47 () || F_48 () ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_102 ;
return string ( V_9 , V_24 , L_19 , V_26 ) ;
}
if ( ! ( ( V_105 == 0 ) ||
( V_105 == 1 &&
F_49 ( V_106 , V_107 ) ) ) )
V_46 = NULL ;
break;
case 'N' :
switch ( V_53 [ 1 ] ) {
case 'F' :
return F_42 ( V_9 , V_24 , V_46 , V_26 ) ;
}
break;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_102 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_14 ( V_9 , V_24 , ( unsigned long ) V_46 , V_26 ) ;
}
static T_1
int F_50 ( const char * V_53 , struct V_25 * V_26 )
{
const char * V_69 = V_53 ;
if ( V_26 -> type == V_108 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_109 ;
goto V_43;
}
if ( V_26 -> type == V_110 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_109 ;
goto V_111;
}
V_26 -> type = V_109 ;
for (; * V_53 ; ++ V_53 ) {
if ( * V_53 == '%' )
break;
}
if ( V_53 != V_69 || ! * V_53 )
return V_53 - V_69 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_112 = true ;
++ V_53 ;
switch ( * V_53 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_112 = false ;
}
if ( ! V_112 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_53 ) )
V_26 -> V_38 = F_7 ( & V_53 ) ;
else if ( * V_53 == '*' ) {
V_26 -> type = V_108 ;
return ++ V_53 - V_69 ;
}
V_43:
V_26 -> V_43 = - 1 ;
if ( * V_53 == '.' ) {
++ V_53 ;
if ( isdigit ( * V_53 ) ) {
V_26 -> V_43 = F_7 ( & V_53 ) ;
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
} else if ( * V_53 == '*' ) {
V_26 -> type = V_110 ;
return ++ V_53 - V_69 ;
}
}
V_111:
V_26 -> V_111 = - 1 ;
if ( * V_53 == 'h' || F_51 ( * V_53 ) == 'l' ||
F_51 ( * V_53 ) == 'z' || * V_53 == 't' ) {
V_26 -> V_111 = * V_53 ++ ;
if ( F_52 ( V_26 -> V_111 == * V_53 ) ) {
if ( V_26 -> V_111 == 'l' ) {
V_26 -> V_111 = 'L' ;
++ V_53 ;
} else if ( V_26 -> V_111 == 'h' ) {
V_26 -> V_111 = 'H' ;
++ V_53 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_53 ) {
case 'c' :
V_26 -> type = V_113 ;
return ++ V_53 - V_69 ;
case 's' :
V_26 -> type = V_114 ;
return ++ V_53 - V_69 ;
case 'p' :
V_26 -> type = V_115 ;
return V_53 - V_69 ;
case 'n' :
V_26 -> type = V_116 ;
return ++ V_53 - V_69 ;
case '%' :
V_26 -> type = V_117 ;
return ++ V_53 - V_69 ;
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
V_26 -> type = V_118 ;
return V_53 - V_69 ;
}
if ( V_26 -> V_111 == 'L' )
V_26 -> type = V_119 ;
else if ( V_26 -> V_111 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_120 ;
else
V_26 -> type = V_121 ;
} else if ( F_51 ( V_26 -> V_111 ) == 'z' ) {
V_26 -> type = V_122 ;
} else if ( V_26 -> V_111 == 't' ) {
V_26 -> type = V_123 ;
} else if ( V_26 -> V_111 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_124 ;
else
V_26 -> type = V_125 ;
} else if ( V_26 -> V_111 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_126 ;
else
V_26 -> type = V_127 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_128 ;
else
V_26 -> type = V_129 ;
}
return ++ V_53 - V_69 ;
}
int vsnprintf ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
unsigned long long V_20 ;
char * V_130 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_53 ( ( int ) V_19 < 0 ) )
return 0 ;
V_130 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_53 ) {
const char * V_131 = V_53 ;
int V_132 = F_50 ( V_53 , & V_26 ) ;
V_53 += V_132 ;
switch ( V_26 . type ) {
case V_109 : {
int V_133 = V_132 ;
if ( V_130 < V_24 ) {
if ( V_133 > V_24 - V_130 )
V_133 = V_24 - V_130 ;
memcpy ( V_130 , V_131 , V_133 ) ;
}
V_130 += V_132 ;
break;
}
case V_108 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_110 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_113 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_130 < V_24 )
* V_130 = ' ' ;
++ V_130 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_130 < V_24 )
* V_130 = V_44 ;
++ V_130 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_130 < V_24 )
* V_130 = ' ' ;
++ V_130 ;
}
break;
}
case V_114 :
V_130 = string ( V_130 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_115 :
V_130 = F_43 ( V_53 + 1 , V_130 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_117 :
if ( V_130 < V_24 )
* V_130 = '%' ;
++ V_130 ;
break;
case V_118 :
if ( V_130 < V_24 )
* V_130 = '%' ;
++ V_130 ;
break;
case V_116 : {
T_3 V_111 = V_26 . V_111 ;
if ( V_111 == 'l' ) {
long * V_134 = va_arg ( args , long * ) ;
* V_134 = ( V_130 - V_9 ) ;
} else if ( F_51 ( V_111 ) == 'z' ) {
T_6 * V_134 = va_arg ( args , T_6 * ) ;
* V_134 = ( V_130 - V_9 ) ;
} else {
int * V_134 = va_arg ( args , int * ) ;
* V_134 = ( V_130 - V_9 ) ;
}
break;
}
default:
switch ( V_26 . type ) {
case V_119 :
V_20 = va_arg (args, long long) ;
break;
case V_121 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_120 :
V_20 = va_arg ( args , long ) ;
break;
case V_122 :
V_20 = va_arg ( args , T_6 ) ;
break;
case V_123 :
V_20 = va_arg ( args , V_135 ) ;
break;
case V_125 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_124 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_127 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_126 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_128 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_130 = F_14 ( V_130 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_130 < V_24 )
* V_130 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_130 - V_9 ;
}
int F_54 ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_53 , args ) ;
if ( F_55 ( V_8 < V_19 ) )
return V_8 ;
if ( V_19 != 0 )
return V_19 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = vsnprintf ( V_9 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_56 ( char * V_9 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = F_54 ( V_9 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_53 , T_5 args )
{
return vsnprintf ( V_9 , V_136 , V_53 , args ) ;
}
int sprintf ( char * V_9 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = vsnprintf ( V_9 , V_136 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_57 ( T_7 * V_137 , T_6 V_19 , const char * V_53 , T_5 args )
{
struct V_25 V_26 = { 0 } ;
char * V_130 , * V_24 ;
V_130 = ( char * ) V_137 ;
V_24 = ( char * ) ( V_137 + V_19 ) ;
#define F_58 ( type ) \
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
while ( * V_53 ) {
int V_132 = F_50 ( V_53 , & V_26 ) ;
V_53 += V_132 ;
switch ( V_26 . type ) {
case V_109 :
case V_118 :
case V_117 :
break;
case V_108 :
case V_110 :
F_58 ( int ) ;
break;
case V_113 :
F_58 ( char ) ;
break;
case V_114 : {
const char * V_138 = va_arg ( args , char * ) ;
T_6 V_23 ;
if ( ( unsigned long ) V_138 > ( unsigned long ) - V_45
|| ( unsigned long ) V_138 < V_45 )
V_138 = L_2 ;
V_23 = strlen ( V_138 ) + 1 ;
if ( V_130 + V_23 < V_24 )
memcpy ( V_130 , V_138 , V_23 ) ;
V_130 += V_23 ;
break;
}
case V_115 :
F_58 ( void * ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_116 : {
T_3 V_111 = V_26 . V_111 ;
void * V_139 ;
if ( V_111 == 'l' )
V_139 = va_arg ( args , long * ) ;
else if ( F_51 ( V_111 ) == 'z' )
V_139 = va_arg ( args , T_6 * ) ;
else
V_139 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_26 . type ) {
case V_119 :
F_58 (long long) ;
break;
case V_121 :
case V_120 :
F_58 (unsigned long) ;
break;
case V_122 :
F_58 ( T_6 ) ;
break;
case V_123 :
F_58 ( V_135 ) ;
break;
case V_125 :
case V_124 :
F_58 ( char ) ;
break;
case V_127 :
case V_126 :
F_58 ( short ) ;
break;
default:
F_58 ( int ) ;
}
}
}
return ( T_7 * ) ( F_59 ( V_130 , sizeof( T_7 ) ) ) - V_137 ;
#undef F_58
}
int F_60 ( char * V_9 , T_6 V_19 , const char * V_53 , const T_7 * V_137 )
{
struct V_25 V_26 = { 0 } ;
char * V_130 , * V_24 ;
const char * args = ( const char * ) V_137 ;
if ( F_53 ( ( int ) V_19 < 0 ) )
return 0 ;
V_130 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_61 ( type ) \
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
while ( * V_53 ) {
const char * V_131 = V_53 ;
int V_132 = F_50 ( V_53 , & V_26 ) ;
V_53 += V_132 ;
switch ( V_26 . type ) {
case V_109 : {
int V_133 = V_132 ;
if ( V_130 < V_24 ) {
if ( V_133 > V_24 - V_130 )
V_133 = V_24 - V_130 ;
memcpy ( V_130 , V_131 , V_133 ) ;
}
V_130 += V_132 ;
break;
}
case V_108 :
V_26 . V_38 = F_61 ( int ) ;
break;
case V_110 :
V_26 . V_43 = F_61 ( int ) ;
break;
case V_113 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_130 < V_24 )
* V_130 = ' ' ;
++ V_130 ;
}
}
V_44 = ( unsigned char ) F_61 ( char ) ;
if ( V_130 < V_24 )
* V_130 = V_44 ;
++ V_130 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_130 < V_24 )
* V_130 = ' ' ;
++ V_130 ;
}
break;
}
case V_114 : {
const char * V_140 = args ;
args += strlen ( V_140 ) + 1 ;
V_130 = string ( V_130 , V_24 , ( char * ) V_140 , V_26 ) ;
break;
}
case V_115 :
V_130 = F_43 ( V_53 + 1 , V_130 , V_24 , F_61 ( void * ) , V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_117 :
case V_118 :
if ( V_130 < V_24 )
* V_130 = '%' ;
++ V_130 ;
break;
case V_116 :
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_119 :
V_20 = F_61 (long long) ;
break;
case V_121 :
case V_120 :
V_20 = F_61 (unsigned long) ;
break;
case V_122 :
V_20 = F_61 ( T_6 ) ;
break;
case V_123 :
V_20 = F_61 ( V_135 ) ;
break;
case V_125 :
V_20 = F_61 (unsigned char) ;
break;
case V_124 :
V_20 = F_61 (signed char) ;
break;
case V_127 :
V_20 = F_61 (unsigned short) ;
break;
case V_126 :
V_20 = F_61 ( short ) ;
break;
case V_129 :
V_20 = F_61 (unsigned int) ;
break;
default:
V_20 = F_61 ( int ) ;
}
V_130 = F_14 ( V_130 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_130 < V_24 )
* V_130 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_61
return V_130 - V_9 ;
}
int F_62 ( T_7 * V_137 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_141 ;
va_start ( args , V_53 ) ;
V_141 = F_57 ( V_137 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_141 ;
}
int vsscanf ( const char * V_9 , const char * V_53 , T_5 args )
{
const char * V_130 = V_9 ;
char * V_142 ;
char V_143 ;
int V_20 = 0 ;
T_3 V_111 ;
T_3 V_3 ;
T_8 V_38 ;
bool V_144 ;
while ( * V_53 && * V_130 ) {
if ( isspace ( * V_53 ) ) {
V_53 = F_63 ( ++ V_53 ) ;
V_130 = F_63 ( V_130 ) ;
}
if ( * V_53 != '%' && * V_53 ) {
if ( * V_53 ++ != * V_130 ++ )
break;
continue;
}
if ( ! * V_53 )
break;
++ V_53 ;
if ( * V_53 == '*' ) {
while ( ! isspace ( * V_53 ) && * V_53 != '%' && * V_53 )
V_53 ++ ;
while ( ! isspace ( * V_130 ) && * V_130 )
V_130 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_53 ) )
V_38 = F_7 ( & V_53 ) ;
V_111 = - 1 ;
if ( * V_53 == 'h' || F_51 ( * V_53 ) == 'l' ||
F_51 ( * V_53 ) == 'z' ) {
V_111 = * V_53 ++ ;
if ( F_52 ( V_111 == * V_53 ) ) {
if ( V_111 == 'h' ) {
V_111 = 'H' ;
V_53 ++ ;
} else if ( V_111 == 'l' ) {
V_111 = 'L' ;
V_53 ++ ;
}
}
}
if ( ! * V_53 || ! * V_130 )
break;
V_3 = 10 ;
V_144 = 0 ;
switch ( * V_53 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_130 ++ ;
} while ( -- V_38 > 0 && * V_130 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_145 ;
V_130 = F_63 ( V_130 ) ;
while ( * V_130 && ! isspace ( * V_130 ) && V_38 -- )
* V_7 ++ = * V_130 ++ ;
* V_7 = '\0' ;
V_20 ++ ;
}
continue;
case 'n' :
{
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = V_130 - V_9 ;
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
V_144 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_130 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_130 = F_63 ( V_130 ) ;
V_143 = * V_130 ;
if ( V_144 && V_143 == '-' )
V_143 = * ( V_130 + 1 ) ;
if ( ! V_143
|| ( V_3 == 16 && ! isxdigit ( V_143 ) )
|| ( V_3 == 10 && ! isdigit ( V_143 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_143 ) || V_143 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_143 ) ) )
break;
switch ( V_111 ) {
case 'H' :
if ( V_144 ) {
signed char * V_7 = ( signed char * ) va_arg (args, signed char *) ;
* V_7 = ( signed char ) F_5 ( V_130 , & V_142 , V_3 ) ;
} else {
unsigned char * V_7 = ( unsigned char * ) va_arg (args, unsigned char *) ;
* V_7 = ( unsigned char ) F_4 ( V_130 , & V_142 , V_3 ) ;
}
break;
case 'h' :
if ( V_144 ) {
short * V_7 = ( short * ) va_arg ( args , short * ) ;
* V_7 = ( short ) F_5 ( V_130 , & V_142 , V_3 ) ;
} else {
unsigned short * V_7 = ( unsigned short * ) va_arg (args, unsigned short *) ;
* V_7 = ( unsigned short ) F_4 ( V_130 , & V_142 , V_3 ) ;
}
break;
case 'l' :
if ( V_144 ) {
long * V_146 = ( long * ) va_arg ( args , long * ) ;
* V_146 = F_5 ( V_130 , & V_142 , V_3 ) ;
} else {
unsigned long * V_146 = ( unsigned long * ) va_arg (args, unsigned long *) ;
* V_146 = F_4 ( V_130 , & V_142 , V_3 ) ;
}
break;
case 'L' :
if ( V_144 ) {
long long * V_146 = ( long long * ) va_arg (args, long long *) ;
* V_146 = F_6 ( V_130 , & V_142 , V_3 ) ;
} else {
unsigned long long * V_146 = ( unsigned long long * ) va_arg (args, unsigned long long *) ;
* V_146 = F_1 ( V_130 , & V_142 , V_3 ) ;
}
break;
case 'Z' :
case 'z' :
{
T_6 * V_7 = ( T_6 * ) va_arg ( args , T_6 * ) ;
* V_7 = ( T_6 ) F_4 ( V_130 , & V_142 , V_3 ) ;
}
break;
default:
if ( V_144 ) {
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = ( int ) F_5 ( V_130 , & V_142 , V_3 ) ;
} else {
unsigned int * V_8 = ( unsigned int * ) va_arg (args, unsigned int*) ;
* V_8 = ( unsigned int ) F_4 ( V_130 , & V_142 , V_3 ) ;
}
break;
}
V_20 ++ ;
if ( ! V_142 )
break;
V_130 = V_142 ;
}
if ( * V_53 == '%' && * ( V_53 + 1 ) == 'n' ) {
int * V_60 = ( int * ) va_arg ( args , int * ) ;
* V_60 = V_130 - V_9 ;
}
return V_20 ;
}
int sscanf ( const char * V_9 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = vsscanf ( V_9 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
