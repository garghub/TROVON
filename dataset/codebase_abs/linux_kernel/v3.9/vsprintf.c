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
static T_1
char * F_17 ( char * V_9 , char * V_24 , void * V_46 ,
struct V_25 V_26 , char V_47 )
{
unsigned long V_48 = ( unsigned long ) V_46 ;
#ifdef F_18
char V_49 [ V_50 ] ;
if ( V_47 == 'B' )
F_19 ( V_49 , V_48 ) ;
else if ( V_47 != 'f' && V_47 != 's' )
F_20 ( V_49 , V_48 ) ;
else
F_21 ( V_49 , V_48 ) ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
#else
V_26 . V_38 = 2 * sizeof( void * ) ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , V_48 , V_26 ) ;
#endif
}
static T_1
char * F_22 ( char * V_9 , char * V_24 , struct V_51 * V_52 ,
struct V_25 V_26 , const char * V_53 )
{
#ifndef F_23
#define F_23 6
#endif
#ifndef F_24
#define F_24 10
#endif
static const struct V_25 V_54 = {
. V_3 = 16 ,
. V_38 = F_23 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_55 = {
. V_3 = 16 ,
. V_38 = F_24 ,
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
#define F_25 ((2 * sizeof(resource_size_t)) + 4)
#define F_26 (2 * sizeof(res->flags))
#define F_27 sizeof("[mem - 64bit pref window disabled]")
#define F_28 sizeof("[mem - flags 0x]")
char V_49 [ F_29 ( 2 * F_25 + F_27 ,
2 * F_25 + F_26 + F_28 ) ] ;
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
V_60 = F_15 ( V_60 , V_61 , V_52 -> V_69 , * V_63 ) ;
if ( V_52 -> V_69 != V_52 -> V_24 ) {
* V_60 ++ = '-' ;
V_60 = F_15 ( V_60 , V_61 , V_52 -> V_24 , * V_63 ) ;
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
V_60 = F_15 ( V_60 , V_61 , V_52 -> V_31 , V_59 ) ;
}
* V_60 ++ = ']' ;
* V_60 = '\0' ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
}
static T_1
char * F_30 ( char * V_9 , char * V_24 , T_3 * V_74 , struct V_25 V_26 ,
const char * V_53 )
{
int V_8 , V_23 = 1 ;
char V_75 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_31 ( V_74 ) )
return string ( V_9 , V_24 , NULL , V_26 ) ;
switch ( V_53 [ 1 ] ) {
case 'C' :
V_75 = ':' ;
break;
case 'D' :
V_75 = '-' ;
break;
case 'N' :
V_75 = 0 ;
break;
default:
V_75 = ' ' ;
break;
}
if ( V_26 . V_38 > 0 )
V_23 = F_32 ( int , V_26 . V_38 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_23 && V_9 < V_24 - 1 ; V_8 ++ ) {
V_9 = F_33 ( V_9 , V_74 [ V_8 ] ) ;
if ( V_9 < V_24 && V_75 && V_8 != V_23 - 1 )
* V_9 ++ = V_75 ;
}
return V_9 ;
}
static T_1
char * F_34 ( char * V_9 , char * V_24 , T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_76 [ sizeof( L_14 ) ] ;
char * V_60 = V_76 ;
int V_8 ;
char V_75 ;
bool V_77 = false ;
switch ( V_53 [ 1 ] ) {
case 'F' :
V_75 = '-' ;
break;
case 'R' :
V_77 = true ;
default:
V_75 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_77 )
V_60 = F_33 ( V_60 , V_74 [ 5 - V_8 ] ) ;
else
V_60 = F_33 ( V_60 , V_74 [ V_8 ] ) ;
if ( V_53 [ 0 ] == 'M' && V_8 != 5 )
* V_60 ++ = V_75 ;
}
* V_60 = '\0' ;
return string ( V_9 , V_24 , V_76 , V_26 ) ;
}
static T_1
char * F_35 ( char * V_60 , const T_3 * V_74 , const char * V_53 )
{
int V_8 ;
bool V_78 = ( V_53 [ 0 ] == 'i' ) ;
int V_79 ;
int V_80 ;
switch ( V_53 [ 2 ] ) {
case 'h' :
#ifdef F_36
V_79 = 0 ;
V_80 = 1 ;
#else
V_79 = 3 ;
V_80 = - 1 ;
#endif
break;
case 'l' :
V_79 = 3 ;
V_80 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_79 = 0 ;
V_80 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_81 [ 3 ] ;
int V_27 = F_9 ( V_81 , V_74 [ V_79 ] ) - V_81 ;
if ( V_78 ) {
if ( V_27 < 3 )
* V_60 ++ = '0' ;
if ( V_27 < 2 )
* V_60 ++ = '0' ;
}
while ( V_27 -- )
* V_60 ++ = V_81 [ V_27 ] ;
if ( V_8 < 3 )
* V_60 ++ = '.' ;
V_79 += V_80 ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_37 ( char * V_60 , const char * V_74 )
{
int V_8 , V_82 , V_83 ;
unsigned char V_84 [ 8 ] ;
int V_85 = 1 ;
int V_86 = - 1 ;
T_4 V_87 ;
T_3 V_88 , V_89 ;
bool V_90 = false ;
bool V_91 ;
struct V_92 V_93 ;
memcpy ( & V_93 , V_74 , sizeof( struct V_92 ) ) ;
V_91 = F_38 ( & V_93 ) || F_39 ( & V_93 ) ;
memset ( V_84 , 0 , sizeof( V_84 ) ) ;
if ( V_91 )
V_83 = 6 ;
else
V_83 = 8 ;
for ( V_8 = 0 ; V_8 < V_83 ; V_8 ++ ) {
for ( V_82 = V_8 ; V_82 < V_83 ; V_82 ++ ) {
if ( V_93 . V_94 [ V_82 ] != 0 )
break;
V_84 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_83 ; V_8 ++ ) {
if ( V_84 [ V_8 ] > V_85 ) {
V_85 = V_84 [ V_8 ] ;
V_86 = V_8 ;
}
}
if ( V_85 == 1 )
V_86 = - 1 ;
for ( V_8 = 0 ; V_8 < V_83 ; V_8 ++ ) {
if ( V_8 == V_86 ) {
if ( V_90 || V_8 == 0 )
* V_60 ++ = ':' ;
* V_60 ++ = ':' ;
V_90 = false ;
V_8 += V_85 - 1 ;
continue;
}
if ( V_90 ) {
* V_60 ++ = ':' ;
V_90 = false ;
}
V_87 = F_40 ( V_93 . V_94 [ V_8 ] ) ;
V_88 = V_87 >> 8 ;
V_89 = V_87 & 0xff ;
if ( V_88 ) {
if ( V_88 > 0x0f )
V_60 = F_33 ( V_60 , V_88 ) ;
else
* V_60 ++ = F_41 ( V_88 ) ;
V_60 = F_33 ( V_60 , V_89 ) ;
}
else if ( V_89 > 0x0f )
V_60 = F_33 ( V_60 , V_89 ) ;
else
* V_60 ++ = F_41 ( V_89 ) ;
V_90 = true ;
}
if ( V_91 ) {
if ( V_90 )
* V_60 ++ = ':' ;
V_60 = F_35 ( V_60 , & V_93 . V_95 [ 12 ] , L_15 ) ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_42 ( char * V_60 , const char * V_74 , const char * V_53 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_60 = F_33 ( V_60 , * V_74 ++ ) ;
V_60 = F_33 ( V_60 , * V_74 ++ ) ;
if ( V_53 [ 0 ] == 'I' && V_8 != 7 )
* V_60 ++ = ':' ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_43 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_96 [ sizeof( L_16 ) ] ;
if ( V_53 [ 0 ] == 'I' && V_53 [ 2 ] == 'c' )
F_37 ( V_96 , V_74 ) ;
else
F_42 ( V_96 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_96 , V_26 ) ;
}
static T_1
char * F_44 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_97 [ sizeof( L_17 ) ] ;
F_35 ( V_97 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_97 , V_26 ) ;
}
static T_1
char * F_45 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_98 [ sizeof( L_18 ) ] ;
char * V_60 = V_98 ;
int V_8 ;
static const T_3 V_99 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_3 V_100 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_3 * V_79 = V_99 ;
bool V_101 = false ;
switch ( * ( ++ V_53 ) ) {
case 'L' :
V_101 = true ;
case 'l' :
V_79 = V_100 ;
break;
case 'B' :
V_101 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_60 = F_33 ( V_60 , V_74 [ V_79 [ V_8 ] ] ) ;
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
if ( V_101 ) {
V_60 = V_98 ;
do {
* V_60 = toupper ( * V_60 ) ;
} while ( * ( ++ V_60 ) );
}
return string ( V_9 , V_24 , V_98 , V_26 ) ;
}
static
char * F_46 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_102 ) ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , * ( const V_102 * ) V_74 , V_26 ) ;
}
static T_1
char * F_47 ( const char * V_53 , char * V_9 , char * V_24 , void * V_46 ,
struct V_25 V_26 )
{
int V_103 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_46 && * V_53 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_103 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_53 ) {
case 'F' :
case 'f' :
V_46 = F_48 ( V_46 ) ;
case 'S' :
case 's' :
case 'B' :
return F_17 ( V_9 , V_24 , V_46 , V_26 , * V_53 ) ;
case 'R' :
case 'r' :
return F_22 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'h' :
return F_30 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'M' :
case 'm' :
return F_34 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'I' :
case 'i' :
switch ( V_53 [ 1 ] ) {
case '6' :
return F_43 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case '4' :
return F_44 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
}
break;
case 'U' :
return F_45 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'V' :
{
T_5 V_104 ;
F_49 ( V_104 , * ( (struct V_105 * ) V_46 ) -> V_104 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_105 * ) V_46 ) -> V_53 , V_104 ) ;
va_end ( V_104 ) ;
return V_9 ;
}
case 'K' :
if ( V_106 && ( F_50 () || F_51 () ||
F_52 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_103 ;
return string ( V_9 , V_24 , L_19 , V_26 ) ;
}
if ( ! ( ( V_106 == 0 ) ||
( V_106 == 1 &&
F_53 ( V_107 , V_108 ) ) ) )
V_46 = NULL ;
break;
case 'N' :
switch ( V_53 [ 1 ] ) {
case 'F' :
return F_46 ( V_9 , V_24 , V_46 , V_26 ) ;
}
break;
case 'a' :
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_38 = sizeof( V_109 ) * 2 + 2 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 ,
( unsigned long long ) * ( ( V_109 * ) V_46 ) , V_26 ) ;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_103 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , ( unsigned long ) V_46 , V_26 ) ;
}
static T_1
int F_54 ( const char * V_53 , struct V_25 * V_26 )
{
const char * V_69 = V_53 ;
if ( V_26 -> type == V_110 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_111 ;
goto V_43;
}
if ( V_26 -> type == V_112 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_111 ;
goto V_113;
}
V_26 -> type = V_111 ;
for (; * V_53 ; ++ V_53 ) {
if ( * V_53 == '%' )
break;
}
if ( V_53 != V_69 || ! * V_53 )
return V_53 - V_69 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_114 = true ;
++ V_53 ;
switch ( * V_53 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_114 = false ;
}
if ( ! V_114 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_53 ) )
V_26 -> V_38 = F_7 ( & V_53 ) ;
else if ( * V_53 == '*' ) {
V_26 -> type = V_110 ;
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
V_26 -> type = V_112 ;
return ++ V_53 - V_69 ;
}
}
V_113:
V_26 -> V_113 = - 1 ;
if ( * V_53 == 'h' || F_55 ( * V_53 ) == 'l' ||
F_55 ( * V_53 ) == 'z' || * V_53 == 't' ) {
V_26 -> V_113 = * V_53 ++ ;
if ( F_56 ( V_26 -> V_113 == * V_53 ) ) {
if ( V_26 -> V_113 == 'l' ) {
V_26 -> V_113 = 'L' ;
++ V_53 ;
} else if ( V_26 -> V_113 == 'h' ) {
V_26 -> V_113 = 'H' ;
++ V_53 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_53 ) {
case 'c' :
V_26 -> type = V_115 ;
return ++ V_53 - V_69 ;
case 's' :
V_26 -> type = V_116 ;
return ++ V_53 - V_69 ;
case 'p' :
V_26 -> type = V_117 ;
return V_53 - V_69 ;
case 'n' :
V_26 -> type = V_118 ;
return ++ V_53 - V_69 ;
case '%' :
V_26 -> type = V_119 ;
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
V_26 -> type = V_120 ;
return V_53 - V_69 ;
}
if ( V_26 -> V_113 == 'L' )
V_26 -> type = V_121 ;
else if ( V_26 -> V_113 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_122 ;
else
V_26 -> type = V_123 ;
} else if ( F_55 ( V_26 -> V_113 ) == 'z' ) {
V_26 -> type = V_124 ;
} else if ( V_26 -> V_113 == 't' ) {
V_26 -> type = V_125 ;
} else if ( V_26 -> V_113 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_126 ;
else
V_26 -> type = V_127 ;
} else if ( V_26 -> V_113 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_128 ;
else
V_26 -> type = V_129 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_130 ;
else
V_26 -> type = V_131 ;
}
return ++ V_53 - V_69 ;
}
int vsnprintf ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
unsigned long long V_20 ;
char * V_132 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_57 ( ( int ) V_19 < 0 ) )
return 0 ;
V_132 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_53 ) {
const char * V_133 = V_53 ;
int V_134 = F_54 ( V_53 , & V_26 ) ;
V_53 += V_134 ;
switch ( V_26 . type ) {
case V_111 : {
int V_135 = V_134 ;
if ( V_132 < V_24 ) {
if ( V_135 > V_24 - V_132 )
V_135 = V_24 - V_132 ;
memcpy ( V_132 , V_133 , V_135 ) ;
}
V_132 += V_134 ;
break;
}
case V_110 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_112 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_115 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_132 < V_24 )
* V_132 = ' ' ;
++ V_132 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_132 < V_24 )
* V_132 = V_44 ;
++ V_132 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_132 < V_24 )
* V_132 = ' ' ;
++ V_132 ;
}
break;
}
case V_116 :
V_132 = string ( V_132 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_117 :
V_132 = F_47 ( V_53 + 1 , V_132 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_119 :
if ( V_132 < V_24 )
* V_132 = '%' ;
++ V_132 ;
break;
case V_120 :
if ( V_132 < V_24 )
* V_132 = '%' ;
++ V_132 ;
break;
case V_118 : {
T_3 V_113 = V_26 . V_113 ;
if ( V_113 == 'l' ) {
long * V_136 = va_arg ( args , long * ) ;
* V_136 = ( V_132 - V_9 ) ;
} else if ( F_55 ( V_113 ) == 'z' ) {
T_6 * V_136 = va_arg ( args , T_6 * ) ;
* V_136 = ( V_132 - V_9 ) ;
} else {
int * V_136 = va_arg ( args , int * ) ;
* V_136 = ( V_132 - V_9 ) ;
}
break;
}
default:
switch ( V_26 . type ) {
case V_121 :
V_20 = va_arg (args, long long) ;
break;
case V_123 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_122 :
V_20 = va_arg ( args , long ) ;
break;
case V_124 :
if ( V_26 . V_31 & V_37 )
V_20 = va_arg ( args , V_137 ) ;
else
V_20 = va_arg ( args , T_6 ) ;
break;
case V_125 :
V_20 = va_arg ( args , V_138 ) ;
break;
case V_127 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_126 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_129 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_128 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_130 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_132 = F_15 ( V_132 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_132 < V_24 )
* V_132 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_132 - V_9 ;
}
int F_58 ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_53 , args ) ;
if ( F_59 ( V_8 < V_19 ) )
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
int F_60 ( char * V_9 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = F_58 ( V_9 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_53 , T_5 args )
{
return vsnprintf ( V_9 , V_139 , V_53 , args ) ;
}
int sprintf ( char * V_9 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = vsnprintf ( V_9 , V_139 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_61 ( T_7 * V_140 , T_6 V_19 , const char * V_53 , T_5 args )
{
struct V_25 V_26 = { 0 } ;
char * V_132 , * V_24 ;
V_132 = ( char * ) V_140 ;
V_24 = ( char * ) ( V_140 + V_19 ) ;
#define F_62 ( type ) \
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
int V_134 = F_54 ( V_53 , & V_26 ) ;
V_53 += V_134 ;
switch ( V_26 . type ) {
case V_111 :
case V_120 :
case V_119 :
break;
case V_110 :
case V_112 :
F_62 ( int ) ;
break;
case V_115 :
F_62 ( char ) ;
break;
case V_116 : {
const char * V_141 = va_arg ( args , char * ) ;
T_6 V_23 ;
if ( ( unsigned long ) V_141 > ( unsigned long ) - V_45
|| ( unsigned long ) V_141 < V_45 )
V_141 = L_2 ;
V_23 = strlen ( V_141 ) + 1 ;
if ( V_132 + V_23 < V_24 )
memcpy ( V_132 , V_141 , V_23 ) ;
V_132 += V_23 ;
break;
}
case V_117 :
F_62 ( void * ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_118 : {
T_3 V_113 = V_26 . V_113 ;
void * V_142 ;
if ( V_113 == 'l' )
V_142 = va_arg ( args , long * ) ;
else if ( F_55 ( V_113 ) == 'z' )
V_142 = va_arg ( args , T_6 * ) ;
else
V_142 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_26 . type ) {
case V_121 :
F_62 (long long) ;
break;
case V_123 :
case V_122 :
F_62 (unsigned long) ;
break;
case V_124 :
F_62 ( T_6 ) ;
break;
case V_125 :
F_62 ( V_138 ) ;
break;
case V_127 :
case V_126 :
F_62 ( char ) ;
break;
case V_129 :
case V_128 :
F_62 ( short ) ;
break;
default:
F_62 ( int ) ;
}
}
}
return ( T_7 * ) ( F_63 ( V_132 , sizeof( T_7 ) ) ) - V_140 ;
#undef F_62
}
int F_64 ( char * V_9 , T_6 V_19 , const char * V_53 , const T_7 * V_140 )
{
struct V_25 V_26 = { 0 } ;
char * V_132 , * V_24 ;
const char * args = ( const char * ) V_140 ;
if ( F_57 ( ( int ) V_19 < 0 ) )
return 0 ;
V_132 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_65 ( type ) \
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
const char * V_133 = V_53 ;
int V_134 = F_54 ( V_53 , & V_26 ) ;
V_53 += V_134 ;
switch ( V_26 . type ) {
case V_111 : {
int V_135 = V_134 ;
if ( V_132 < V_24 ) {
if ( V_135 > V_24 - V_132 )
V_135 = V_24 - V_132 ;
memcpy ( V_132 , V_133 , V_135 ) ;
}
V_132 += V_134 ;
break;
}
case V_110 :
V_26 . V_38 = F_65 ( int ) ;
break;
case V_112 :
V_26 . V_43 = F_65 ( int ) ;
break;
case V_115 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_132 < V_24 )
* V_132 = ' ' ;
++ V_132 ;
}
}
V_44 = ( unsigned char ) F_65 ( char ) ;
if ( V_132 < V_24 )
* V_132 = V_44 ;
++ V_132 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_132 < V_24 )
* V_132 = ' ' ;
++ V_132 ;
}
break;
}
case V_116 : {
const char * V_143 = args ;
args += strlen ( V_143 ) + 1 ;
V_132 = string ( V_132 , V_24 , ( char * ) V_143 , V_26 ) ;
break;
}
case V_117 :
V_132 = F_47 ( V_53 + 1 , V_132 , V_24 , F_65 ( void * ) , V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_119 :
case V_120 :
if ( V_132 < V_24 )
* V_132 = '%' ;
++ V_132 ;
break;
case V_118 :
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_121 :
V_20 = F_65 (long long) ;
break;
case V_123 :
case V_122 :
V_20 = F_65 (unsigned long) ;
break;
case V_124 :
V_20 = F_65 ( T_6 ) ;
break;
case V_125 :
V_20 = F_65 ( V_138 ) ;
break;
case V_127 :
V_20 = F_65 (unsigned char) ;
break;
case V_126 :
V_20 = F_65 (signed char) ;
break;
case V_129 :
V_20 = F_65 (unsigned short) ;
break;
case V_128 :
V_20 = F_65 ( short ) ;
break;
case V_131 :
V_20 = F_65 (unsigned int) ;
break;
default:
V_20 = F_65 ( int ) ;
}
V_132 = F_15 ( V_132 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_132 < V_24 )
* V_132 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_65
return V_132 - V_9 ;
}
int F_66 ( T_7 * V_140 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_144 ;
va_start ( args , V_53 ) ;
V_144 = F_61 ( V_140 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_144 ;
}
int vsscanf ( const char * V_9 , const char * V_53 , T_5 args )
{
const char * V_132 = V_9 ;
char * V_145 ;
char V_146 ;
int V_20 = 0 ;
T_3 V_113 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_147 ;
} V_148 ;
T_8 V_38 ;
bool V_149 ;
while ( * V_53 ) {
if ( isspace ( * V_53 ) ) {
V_53 = F_67 ( ++ V_53 ) ;
V_132 = F_67 ( V_132 ) ;
}
if ( * V_53 != '%' && * V_53 ) {
if ( * V_53 ++ != * V_132 ++ )
break;
continue;
}
if ( ! * V_53 )
break;
++ V_53 ;
if ( * V_53 == '*' ) {
if ( ! * V_132 )
break;
while ( ! isspace ( * V_53 ) && * V_53 != '%' && * V_53 )
V_53 ++ ;
while ( ! isspace ( * V_132 ) && * V_132 )
V_132 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_53 ) ) {
V_38 = F_7 ( & V_53 ) ;
if ( V_38 <= 0 )
break;
}
V_113 = - 1 ;
if ( * V_53 == 'h' || F_55 ( * V_53 ) == 'l' ||
F_55 ( * V_53 ) == 'z' ) {
V_113 = * V_53 ++ ;
if ( F_56 ( V_113 == * V_53 ) ) {
if ( V_113 == 'h' ) {
V_113 = 'H' ;
V_53 ++ ;
} else if ( V_113 == 'l' ) {
V_113 = 'L' ;
V_53 ++ ;
}
}
}
if ( ! * V_53 )
break;
if ( * V_53 == 'n' ) {
* va_arg ( args , int * ) = V_132 - V_9 ;
++ V_53 ;
continue;
}
if ( ! * V_132 )
break;
V_3 = 10 ;
V_149 = 0 ;
switch ( * V_53 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_132 ++ ;
} while ( -- V_38 > 0 && * V_132 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_150 ;
V_132 = F_67 ( V_132 ) ;
while ( * V_132 && ! isspace ( * V_132 ) && V_38 -- )
* V_7 ++ = * V_132 ++ ;
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
V_149 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_132 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_132 = F_67 ( V_132 ) ;
V_146 = * V_132 ;
if ( V_149 && V_146 == '-' )
V_146 = * ( V_132 + 1 ) ;
if ( ! V_146
|| ( V_3 == 16 && ! isxdigit ( V_146 ) )
|| ( V_3 == 10 && ! isdigit ( V_146 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_146 ) || V_146 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_146 ) ) )
break;
if ( V_149 )
V_148 . V_7 = V_113 != 'L' ?
F_5 ( V_132 , & V_145 , V_3 ) :
F_6 ( V_132 , & V_145 , V_3 ) ;
else
V_148 . V_147 = V_113 != 'L' ?
F_4 ( V_132 , & V_145 , V_3 ) :
F_1 ( V_132 , & V_145 , V_3 ) ;
if ( V_38 > 0 && V_145 - V_132 > V_38 ) {
if ( V_3 == 0 )
F_2 ( V_132 , & V_3 ) ;
while ( V_145 - V_132 > V_38 ) {
if ( V_149 )
V_148 . V_7 = F_68 ( V_148 . V_7 , V_3 ) ;
else
V_148 . V_147 = F_69 ( V_148 . V_147 , V_3 ) ;
-- V_145 ;
}
}
switch ( V_113 ) {
case 'H' :
if ( V_149 )
* va_arg (args, signed char *) = V_148 . V_7 ;
else
* va_arg (args, unsigned char *) = V_148 . V_147 ;
break;
case 'h' :
if ( V_149 )
* va_arg ( args , short * ) = V_148 . V_7 ;
else
* va_arg (args, unsigned short *) = V_148 . V_147 ;
break;
case 'l' :
if ( V_149 )
* va_arg ( args , long * ) = V_148 . V_7 ;
else
* va_arg (args, unsigned long *) = V_148 . V_147 ;
break;
case 'L' :
if ( V_149 )
* va_arg (args, long long *) = V_148 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_148 . V_147 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_6 * ) = V_148 . V_147 ;
break;
default:
if ( V_149 )
* va_arg ( args , int * ) = V_148 . V_7 ;
else
* va_arg (args, unsigned int *) = V_148 . V_147 ;
break;
}
V_20 ++ ;
if ( ! V_145 )
break;
V_132 = V_145 ;
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
