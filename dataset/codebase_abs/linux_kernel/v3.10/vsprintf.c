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
struct V_25 V_26 , const char * V_47 )
{
unsigned long V_48 ;
#ifdef F_18
char V_49 [ V_50 ] ;
#endif
if ( V_47 [ 1 ] == 'R' )
V_46 = F_19 ( V_46 ) ;
V_48 = ( unsigned long ) V_46 ;
#ifdef F_18
if ( * V_47 == 'B' )
F_20 ( V_49 , V_48 ) ;
else if ( * V_47 != 'f' && * V_47 != 's' )
F_21 ( V_49 , V_48 ) ;
else
F_22 ( V_49 , V_48 ) ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
#else
V_26 . V_38 = 2 * sizeof( void * ) ;
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , V_48 , V_26 ) ;
#endif
}
static T_1
char * F_23 ( char * V_9 , char * V_24 , struct V_51 * V_52 ,
struct V_25 V_26 , const char * V_47 )
{
#ifndef F_24
#define F_24 6
#endif
#ifndef F_25
#define F_25 10
#endif
static const struct V_25 V_53 = {
. V_3 = 16 ,
. V_38 = F_24 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_54 = {
. V_3 = 16 ,
. V_38 = F_25 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 | V_36 ,
} ;
static const struct V_25 V_55 = {
. V_3 = 16 ,
. V_38 = 2 ,
. V_43 = - 1 ,
. V_31 = V_34 | V_36 ,
} ;
static const struct V_25 V_56 = {
. V_3 = 10 ,
. V_43 = - 1 ,
. V_31 = 0 ,
} ;
static const struct V_25 V_57 = {
. V_38 = - 1 ,
. V_43 = 10 ,
. V_31 = V_35 ,
} ;
static const struct V_25 V_58 = {
. V_3 = 16 ,
. V_43 = - 1 ,
. V_31 = V_32 | V_34 ,
} ;
#define F_26 ((2 * sizeof(resource_size_t)) + 4)
#define F_27 (2 * sizeof(res->flags))
#define F_28 sizeof("[mem - 64bit pref window disabled]")
#define F_29 sizeof("[mem - flags 0x]")
char V_49 [ F_30 ( 2 * F_26 + F_28 ,
2 * F_26 + F_27 + F_29 ) ] ;
char * V_59 = V_49 , * V_60 = V_49 + sizeof( V_49 ) ;
int V_61 = ( V_47 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_25 * V_62 ;
* V_59 ++ = '[' ;
if ( V_52 -> V_31 & V_63 ) {
V_59 = string ( V_59 , V_60 , L_3 , V_57 ) ;
V_62 = & V_53 ;
} else if ( V_52 -> V_31 & V_64 ) {
V_59 = string ( V_59 , V_60 , L_4 , V_57 ) ;
V_62 = & V_54 ;
} else if ( V_52 -> V_31 & V_65 ) {
V_59 = string ( V_59 , V_60 , L_5 , V_57 ) ;
V_62 = & V_56 ;
} else if ( V_52 -> V_31 & V_66 ) {
V_59 = string ( V_59 , V_60 , L_6 , V_57 ) ;
V_62 = & V_56 ;
} else if ( V_52 -> V_31 & V_67 ) {
V_59 = string ( V_59 , V_60 , L_7 , V_57 ) ;
V_62 = & V_55 ;
} else {
V_59 = string ( V_59 , V_60 , L_8 , V_57 ) ;
V_62 = & V_54 ;
V_61 = 0 ;
}
V_59 = F_15 ( V_59 , V_60 , V_52 -> V_68 , * V_62 ) ;
if ( V_52 -> V_68 != V_52 -> V_24 ) {
* V_59 ++ = '-' ;
V_59 = F_15 ( V_59 , V_60 , V_52 -> V_24 , * V_62 ) ;
}
if ( V_61 ) {
if ( V_52 -> V_31 & V_69 )
V_59 = string ( V_59 , V_60 , L_9 , V_57 ) ;
if ( V_52 -> V_31 & V_70 )
V_59 = string ( V_59 , V_60 , L_10 , V_57 ) ;
if ( V_52 -> V_31 & V_71 )
V_59 = string ( V_59 , V_60 , L_11 , V_57 ) ;
if ( V_52 -> V_31 & V_72 )
V_59 = string ( V_59 , V_60 , L_12 , V_57 ) ;
} else {
V_59 = string ( V_59 , V_60 , L_13 , V_57 ) ;
V_59 = F_15 ( V_59 , V_60 , V_52 -> V_31 , V_58 ) ;
}
* V_59 ++ = ']' ;
* V_59 = '\0' ;
return string ( V_9 , V_24 , V_49 , V_26 ) ;
}
static T_1
char * F_31 ( char * V_9 , char * V_24 , T_3 * V_73 , struct V_25 V_26 ,
const char * V_47 )
{
int V_8 , V_23 = 1 ;
char V_74 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_32 ( V_73 ) )
return string ( V_9 , V_24 , NULL , V_26 ) ;
switch ( V_47 [ 1 ] ) {
case 'C' :
V_74 = ':' ;
break;
case 'D' :
V_74 = '-' ;
break;
case 'N' :
V_74 = 0 ;
break;
default:
V_74 = ' ' ;
break;
}
if ( V_26 . V_38 > 0 )
V_23 = F_33 ( int , V_26 . V_38 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_23 && V_9 < V_24 - 1 ; V_8 ++ ) {
V_9 = F_34 ( V_9 , V_73 [ V_8 ] ) ;
if ( V_9 < V_24 && V_74 && V_8 != V_23 - 1 )
* V_9 ++ = V_74 ;
}
return V_9 ;
}
static T_1
char * F_35 ( char * V_9 , char * V_24 , T_3 * V_73 ,
struct V_25 V_26 , const char * V_47 )
{
char V_75 [ sizeof( L_14 ) ] ;
char * V_59 = V_75 ;
int V_8 ;
char V_74 ;
bool V_76 = false ;
switch ( V_47 [ 1 ] ) {
case 'F' :
V_74 = '-' ;
break;
case 'R' :
V_76 = true ;
default:
V_74 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_76 )
V_59 = F_34 ( V_59 , V_73 [ 5 - V_8 ] ) ;
else
V_59 = F_34 ( V_59 , V_73 [ V_8 ] ) ;
if ( V_47 [ 0 ] == 'M' && V_8 != 5 )
* V_59 ++ = V_74 ;
}
* V_59 = '\0' ;
return string ( V_9 , V_24 , V_75 , V_26 ) ;
}
static T_1
char * F_36 ( char * V_59 , const T_3 * V_73 , const char * V_47 )
{
int V_8 ;
bool V_77 = ( V_47 [ 0 ] == 'i' ) ;
int V_78 ;
int V_79 ;
switch ( V_47 [ 2 ] ) {
case 'h' :
#ifdef F_37
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
int V_27 = F_9 ( V_80 , V_73 [ V_78 ] ) - V_80 ;
if ( V_77 ) {
if ( V_27 < 3 )
* V_59 ++ = '0' ;
if ( V_27 < 2 )
* V_59 ++ = '0' ;
}
while ( V_27 -- )
* V_59 ++ = V_80 [ V_27 ] ;
if ( V_8 < 3 )
* V_59 ++ = '.' ;
V_78 += V_79 ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_38 ( char * V_59 , const char * V_73 )
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
memcpy ( & V_92 , V_73 , sizeof( struct V_91 ) ) ;
V_90 = F_39 ( & V_92 ) || F_40 ( & V_92 ) ;
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
* V_59 ++ = ':' ;
* V_59 ++ = ':' ;
V_89 = false ;
V_8 += V_84 - 1 ;
continue;
}
if ( V_89 ) {
* V_59 ++ = ':' ;
V_89 = false ;
}
V_86 = F_41 ( V_92 . V_93 [ V_8 ] ) ;
V_87 = V_86 >> 8 ;
V_88 = V_86 & 0xff ;
if ( V_87 ) {
if ( V_87 > 0x0f )
V_59 = F_34 ( V_59 , V_87 ) ;
else
* V_59 ++ = F_42 ( V_87 ) ;
V_59 = F_34 ( V_59 , V_88 ) ;
}
else if ( V_88 > 0x0f )
V_59 = F_34 ( V_59 , V_88 ) ;
else
* V_59 ++ = F_42 ( V_88 ) ;
V_89 = true ;
}
if ( V_90 ) {
if ( V_89 )
* V_59 ++ = ':' ;
V_59 = F_36 ( V_59 , & V_92 . V_94 [ 12 ] , L_15 ) ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_43 ( char * V_59 , const char * V_73 , const char * V_47 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_59 = F_34 ( V_59 , * V_73 ++ ) ;
V_59 = F_34 ( V_59 , * V_73 ++ ) ;
if ( V_47 [ 0 ] == 'I' && V_8 != 7 )
* V_59 ++ = ':' ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_44 ( char * V_9 , char * V_24 , const T_3 * V_73 ,
struct V_25 V_26 , const char * V_47 )
{
char V_95 [ sizeof( L_16 ) ] ;
if ( V_47 [ 0 ] == 'I' && V_47 [ 2 ] == 'c' )
F_38 ( V_95 , V_73 ) ;
else
F_43 ( V_95 , V_73 , V_47 ) ;
return string ( V_9 , V_24 , V_95 , V_26 ) ;
}
static T_1
char * F_45 ( char * V_9 , char * V_24 , const T_3 * V_73 ,
struct V_25 V_26 , const char * V_47 )
{
char V_96 [ sizeof( L_17 ) ] ;
F_36 ( V_96 , V_73 , V_47 ) ;
return string ( V_9 , V_24 , V_96 , V_26 ) ;
}
static T_1
char * F_46 ( char * V_9 , char * V_24 , const T_3 * V_73 ,
struct V_25 V_26 , const char * V_47 )
{
char V_97 [ sizeof( L_18 ) ] ;
char * V_59 = V_97 ;
int V_8 ;
static const T_3 V_98 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_3 V_99 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_3 * V_78 = V_98 ;
bool V_100 = false ;
switch ( * ( ++ V_47 ) ) {
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
V_59 = F_34 ( V_59 , V_73 [ V_78 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_59 ++ = '-' ;
break;
}
}
* V_59 = 0 ;
if ( V_100 ) {
V_59 = V_97 ;
do {
* V_59 = toupper ( * V_59 ) ;
} while ( * ( ++ V_59 ) );
}
return string ( V_9 , V_24 , V_97 , V_26 ) ;
}
static
char * F_47 ( char * V_9 , char * V_24 , const T_3 * V_73 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_101 ) ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , * ( const V_101 * ) V_73 , V_26 ) ;
}
static T_1
char * F_48 ( const char * V_47 , char * V_9 , char * V_24 , void * V_46 ,
struct V_25 V_26 )
{
int V_102 = 2 * sizeof( void * ) + ( V_26 . V_31 & V_32 ? 2 : 0 ) ;
if ( ! V_46 && * V_47 != 'K' ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_102 ;
return string ( V_9 , V_24 , L_2 , V_26 ) ;
}
switch ( * V_47 ) {
case 'F' :
case 'f' :
V_46 = F_49 ( V_46 ) ;
case 'S' :
case 's' :
case 'B' :
return F_17 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case 'R' :
case 'r' :
return F_23 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case 'h' :
return F_31 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case 'M' :
case 'm' :
return F_35 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case 'I' :
case 'i' :
switch ( V_47 [ 1 ] ) {
case '6' :
return F_44 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case '4' :
return F_45 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
}
break;
case 'U' :
return F_46 ( V_9 , V_24 , V_46 , V_26 , V_47 ) ;
case 'V' :
{
T_5 V_103 ;
F_50 ( V_103 , * ( (struct V_104 * ) V_46 ) -> V_103 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_104 * ) V_46 ) -> V_47 , V_103 ) ;
va_end ( V_103 ) ;
return V_9 ;
}
case 'K' :
if ( V_105 && ( F_51 () || F_52 () ||
F_53 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_102 ;
return string ( V_9 , V_24 , L_19 , V_26 ) ;
}
if ( ! ( ( V_105 == 0 ) ||
( V_105 == 1 &&
F_54 ( V_106 , V_107 ) ) ) )
V_46 = NULL ;
break;
case 'N' :
switch ( V_47 [ 1 ] ) {
case 'F' :
return F_47 ( V_9 , V_24 , V_46 , V_26 ) ;
}
break;
case 'a' :
V_26 . V_31 |= V_32 | V_34 | V_36 ;
V_26 . V_38 = sizeof( V_108 ) * 2 + 2 ;
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 ,
( unsigned long long ) * ( ( V_108 * ) V_46 ) , V_26 ) ;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_102 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_15 ( V_9 , V_24 , ( unsigned long ) V_46 , V_26 ) ;
}
static T_1
int F_55 ( const char * V_47 , struct V_25 * V_26 )
{
const char * V_68 = V_47 ;
if ( V_26 -> type == V_109 ) {
if ( V_26 -> V_38 < 0 ) {
V_26 -> V_38 = - V_26 -> V_38 ;
V_26 -> V_31 |= V_35 ;
}
V_26 -> type = V_110 ;
goto V_43;
}
if ( V_26 -> type == V_111 ) {
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
V_26 -> type = V_110 ;
goto V_112;
}
V_26 -> type = V_110 ;
for (; * V_47 ; ++ V_47 ) {
if ( * V_47 == '%' )
break;
}
if ( V_47 != V_68 || ! * V_47 )
return V_47 - V_68 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_113 = true ;
++ V_47 ;
switch ( * V_47 ) {
case '-' : V_26 -> V_31 |= V_35 ; break;
case '+' : V_26 -> V_31 |= V_39 ; break;
case ' ' : V_26 -> V_31 |= V_40 ; break;
case '#' : V_26 -> V_31 |= V_32 ; break;
case '0' : V_26 -> V_31 |= V_36 ; break;
default: V_113 = false ;
}
if ( ! V_113 )
break;
}
V_26 -> V_38 = - 1 ;
if ( isdigit ( * V_47 ) )
V_26 -> V_38 = F_7 ( & V_47 ) ;
else if ( * V_47 == '*' ) {
V_26 -> type = V_109 ;
return ++ V_47 - V_68 ;
}
V_43:
V_26 -> V_43 = - 1 ;
if ( * V_47 == '.' ) {
++ V_47 ;
if ( isdigit ( * V_47 ) ) {
V_26 -> V_43 = F_7 ( & V_47 ) ;
if ( V_26 -> V_43 < 0 )
V_26 -> V_43 = 0 ;
} else if ( * V_47 == '*' ) {
V_26 -> type = V_111 ;
return ++ V_47 - V_68 ;
}
}
V_112:
V_26 -> V_112 = - 1 ;
if ( * V_47 == 'h' || F_56 ( * V_47 ) == 'l' ||
F_56 ( * V_47 ) == 'z' || * V_47 == 't' ) {
V_26 -> V_112 = * V_47 ++ ;
if ( F_57 ( V_26 -> V_112 == * V_47 ) ) {
if ( V_26 -> V_112 == 'l' ) {
V_26 -> V_112 = 'L' ;
++ V_47 ;
} else if ( V_26 -> V_112 == 'h' ) {
V_26 -> V_112 = 'H' ;
++ V_47 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_47 ) {
case 'c' :
V_26 -> type = V_114 ;
return ++ V_47 - V_68 ;
case 's' :
V_26 -> type = V_115 ;
return ++ V_47 - V_68 ;
case 'p' :
V_26 -> type = V_116 ;
return V_47 - V_68 ;
case 'n' :
V_26 -> type = V_117 ;
return ++ V_47 - V_68 ;
case '%' :
V_26 -> type = V_118 ;
return ++ V_47 - V_68 ;
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
V_26 -> type = V_119 ;
return V_47 - V_68 ;
}
if ( V_26 -> V_112 == 'L' )
V_26 -> type = V_120 ;
else if ( V_26 -> V_112 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_121 ;
else
V_26 -> type = V_122 ;
} else if ( F_56 ( V_26 -> V_112 ) == 'z' ) {
V_26 -> type = V_123 ;
} else if ( V_26 -> V_112 == 't' ) {
V_26 -> type = V_124 ;
} else if ( V_26 -> V_112 == 'H' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_125 ;
else
V_26 -> type = V_126 ;
} else if ( V_26 -> V_112 == 'h' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_127 ;
else
V_26 -> type = V_128 ;
} else {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_129 ;
else
V_26 -> type = V_130 ;
}
return ++ V_47 - V_68 ;
}
int vsnprintf ( char * V_9 , T_6 V_19 , const char * V_47 , T_5 args )
{
unsigned long long V_20 ;
char * V_131 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_58 ( ( int ) V_19 < 0 ) )
return 0 ;
V_131 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_47 ) {
const char * V_132 = V_47 ;
int V_133 = F_55 ( V_47 , & V_26 ) ;
V_47 += V_133 ;
switch ( V_26 . type ) {
case V_110 : {
int V_134 = V_133 ;
if ( V_131 < V_24 ) {
if ( V_134 > V_24 - V_131 )
V_134 = V_24 - V_131 ;
memcpy ( V_131 , V_132 , V_134 ) ;
}
V_131 += V_133 ;
break;
}
case V_109 :
V_26 . V_38 = va_arg ( args , int ) ;
break;
case V_111 :
V_26 . V_43 = va_arg ( args , int ) ;
break;
case V_114 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_131 < V_24 )
* V_131 = ' ' ;
++ V_131 ;
}
}
V_44 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_131 < V_24 )
* V_131 = V_44 ;
++ V_131 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_131 < V_24 )
* V_131 = ' ' ;
++ V_131 ;
}
break;
}
case V_115 :
V_131 = string ( V_131 , V_24 , va_arg ( args , char * ) , V_26 ) ;
break;
case V_116 :
V_131 = F_48 ( V_47 + 1 , V_131 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_118 :
if ( V_131 < V_24 )
* V_131 = '%' ;
++ V_131 ;
break;
case V_119 :
if ( V_131 < V_24 )
* V_131 = '%' ;
++ V_131 ;
break;
case V_117 : {
T_3 V_112 = V_26 . V_112 ;
if ( V_112 == 'l' ) {
long * V_135 = va_arg ( args , long * ) ;
* V_135 = ( V_131 - V_9 ) ;
} else if ( F_56 ( V_112 ) == 'z' ) {
T_6 * V_135 = va_arg ( args , T_6 * ) ;
* V_135 = ( V_131 - V_9 ) ;
} else {
int * V_135 = va_arg ( args , int * ) ;
* V_135 = ( V_131 - V_9 ) ;
}
break;
}
default:
switch ( V_26 . type ) {
case V_120 :
V_20 = va_arg (args, long long) ;
break;
case V_122 :
V_20 = va_arg (args, unsigned long) ;
break;
case V_121 :
V_20 = va_arg ( args , long ) ;
break;
case V_123 :
if ( V_26 . V_31 & V_37 )
V_20 = va_arg ( args , V_136 ) ;
else
V_20 = va_arg ( args , T_6 ) ;
break;
case V_124 :
V_20 = va_arg ( args , V_137 ) ;
break;
case V_126 :
V_20 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_125 :
V_20 = ( signed char ) va_arg ( args , int ) ;
break;
case V_128 :
V_20 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_127 :
V_20 = ( short ) va_arg ( args , int ) ;
break;
case V_129 :
V_20 = ( int ) va_arg ( args , int ) ;
break;
default:
V_20 = va_arg (args, unsigned int) ;
}
V_131 = F_15 ( V_131 , V_24 , V_20 , V_26 ) ;
}
}
if ( V_19 > 0 ) {
if ( V_131 < V_24 )
* V_131 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
return V_131 - V_9 ;
}
int F_59 ( char * V_9 , T_6 V_19 , const char * V_47 , T_5 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_47 , args ) ;
if ( F_60 ( V_8 < V_19 ) )
return V_8 ;
if ( V_19 != 0 )
return V_19 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_6 V_19 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = vsnprintf ( V_9 , V_19 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_61 ( char * V_9 , T_6 V_19 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = F_59 ( V_9 , V_19 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_47 , T_5 args )
{
return vsnprintf ( V_9 , V_138 , V_47 , args ) ;
}
int sprintf ( char * V_9 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = vsnprintf ( V_9 , V_138 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_62 ( T_7 * V_139 , T_6 V_19 , const char * V_47 , T_5 args )
{
struct V_25 V_26 = { 0 } ;
char * V_131 , * V_24 ;
V_131 = ( char * ) V_139 ;
V_24 = ( char * ) ( V_139 + V_19 ) ;
#define F_63 ( type ) \
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
while ( * V_47 ) {
int V_133 = F_55 ( V_47 , & V_26 ) ;
V_47 += V_133 ;
switch ( V_26 . type ) {
case V_110 :
case V_119 :
case V_118 :
break;
case V_109 :
case V_111 :
F_63 ( int ) ;
break;
case V_114 :
F_63 ( char ) ;
break;
case V_115 : {
const char * V_140 = va_arg ( args , char * ) ;
T_6 V_23 ;
if ( ( unsigned long ) V_140 > ( unsigned long ) - V_45
|| ( unsigned long ) V_140 < V_45 )
V_140 = L_2 ;
V_23 = strlen ( V_140 ) + 1 ;
if ( V_131 + V_23 < V_24 )
memcpy ( V_131 , V_140 , V_23 ) ;
V_131 += V_23 ;
break;
}
case V_116 :
F_63 ( void * ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_117 : {
T_3 V_112 = V_26 . V_112 ;
void * V_141 ;
if ( V_112 == 'l' )
V_141 = va_arg ( args , long * ) ;
else if ( F_56 ( V_112 ) == 'z' )
V_141 = va_arg ( args , T_6 * ) ;
else
V_141 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_26 . type ) {
case V_120 :
F_63 (long long) ;
break;
case V_122 :
case V_121 :
F_63 (unsigned long) ;
break;
case V_123 :
F_63 ( T_6 ) ;
break;
case V_124 :
F_63 ( V_137 ) ;
break;
case V_126 :
case V_125 :
F_63 ( char ) ;
break;
case V_128 :
case V_127 :
F_63 ( short ) ;
break;
default:
F_63 ( int ) ;
}
}
}
return ( T_7 * ) ( F_64 ( V_131 , sizeof( T_7 ) ) ) - V_139 ;
#undef F_63
}
int F_65 ( char * V_9 , T_6 V_19 , const char * V_47 , const T_7 * V_139 )
{
struct V_25 V_26 = { 0 } ;
char * V_131 , * V_24 ;
const char * args = ( const char * ) V_139 ;
if ( F_58 ( ( int ) V_19 < 0 ) )
return 0 ;
V_131 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_66 ( type ) \
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
while ( * V_47 ) {
const char * V_132 = V_47 ;
int V_133 = F_55 ( V_47 , & V_26 ) ;
V_47 += V_133 ;
switch ( V_26 . type ) {
case V_110 : {
int V_134 = V_133 ;
if ( V_131 < V_24 ) {
if ( V_134 > V_24 - V_131 )
V_134 = V_24 - V_131 ;
memcpy ( V_131 , V_132 , V_134 ) ;
}
V_131 += V_133 ;
break;
}
case V_109 :
V_26 . V_38 = F_66 ( int ) ;
break;
case V_111 :
V_26 . V_43 = F_66 ( int ) ;
break;
case V_114 : {
char V_44 ;
if ( ! ( V_26 . V_31 & V_35 ) ) {
while ( -- V_26 . V_38 > 0 ) {
if ( V_131 < V_24 )
* V_131 = ' ' ;
++ V_131 ;
}
}
V_44 = ( unsigned char ) F_66 ( char ) ;
if ( V_131 < V_24 )
* V_131 = V_44 ;
++ V_131 ;
while ( -- V_26 . V_38 > 0 ) {
if ( V_131 < V_24 )
* V_131 = ' ' ;
++ V_131 ;
}
break;
}
case V_115 : {
const char * V_142 = args ;
args += strlen ( V_142 ) + 1 ;
V_131 = string ( V_131 , V_24 , ( char * ) V_142 , V_26 ) ;
break;
}
case V_116 :
V_131 = F_48 ( V_47 + 1 , V_131 , V_24 , F_66 ( void * ) , V_26 ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_118 :
case V_119 :
if ( V_131 < V_24 )
* V_131 = '%' ;
++ V_131 ;
break;
case V_117 :
break;
default: {
unsigned long long V_20 ;
switch ( V_26 . type ) {
case V_120 :
V_20 = F_66 (long long) ;
break;
case V_122 :
case V_121 :
V_20 = F_66 (unsigned long) ;
break;
case V_123 :
V_20 = F_66 ( T_6 ) ;
break;
case V_124 :
V_20 = F_66 ( V_137 ) ;
break;
case V_126 :
V_20 = F_66 (unsigned char) ;
break;
case V_125 :
V_20 = F_66 (signed char) ;
break;
case V_128 :
V_20 = F_66 (unsigned short) ;
break;
case V_127 :
V_20 = F_66 ( short ) ;
break;
case V_130 :
V_20 = F_66 (unsigned int) ;
break;
default:
V_20 = F_66 ( int ) ;
}
V_131 = F_15 ( V_131 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_131 < V_24 )
* V_131 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_66
return V_131 - V_9 ;
}
int F_67 ( T_7 * V_139 , T_6 V_19 , const char * V_47 , ... )
{
T_5 args ;
int V_143 ;
va_start ( args , V_47 ) ;
V_143 = F_62 ( V_139 , V_19 , V_47 , args ) ;
va_end ( args ) ;
return V_143 ;
}
int vsscanf ( const char * V_9 , const char * V_47 , T_5 args )
{
const char * V_131 = V_9 ;
char * V_144 ;
char V_145 ;
int V_20 = 0 ;
T_3 V_112 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_146 ;
} V_147 ;
T_8 V_38 ;
bool V_148 ;
while ( * V_47 ) {
if ( isspace ( * V_47 ) ) {
V_47 = F_68 ( ++ V_47 ) ;
V_131 = F_68 ( V_131 ) ;
}
if ( * V_47 != '%' && * V_47 ) {
if ( * V_47 ++ != * V_131 ++ )
break;
continue;
}
if ( ! * V_47 )
break;
++ V_47 ;
if ( * V_47 == '*' ) {
if ( ! * V_131 )
break;
while ( ! isspace ( * V_47 ) && * V_47 != '%' && * V_47 )
V_47 ++ ;
while ( ! isspace ( * V_131 ) && * V_131 )
V_131 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_47 ) ) {
V_38 = F_7 ( & V_47 ) ;
if ( V_38 <= 0 )
break;
}
V_112 = - 1 ;
if ( * V_47 == 'h' || F_56 ( * V_47 ) == 'l' ||
F_56 ( * V_47 ) == 'z' ) {
V_112 = * V_47 ++ ;
if ( F_57 ( V_112 == * V_47 ) ) {
if ( V_112 == 'h' ) {
V_112 = 'H' ;
V_47 ++ ;
} else if ( V_112 == 'l' ) {
V_112 = 'L' ;
V_47 ++ ;
}
}
}
if ( ! * V_47 )
break;
if ( * V_47 == 'n' ) {
* va_arg ( args , int * ) = V_131 - V_9 ;
++ V_47 ;
continue;
}
if ( ! * V_131 )
break;
V_3 = 10 ;
V_148 = 0 ;
switch ( * V_47 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = 1 ;
do {
* V_7 ++ = * V_131 ++ ;
} while ( -- V_38 > 0 && * V_131 );
V_20 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_38 == - 1 )
V_38 = V_149 ;
V_131 = F_68 ( V_131 ) ;
while ( * V_131 && ! isspace ( * V_131 ) && V_38 -- )
* V_7 ++ = * V_131 ++ ;
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
V_148 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_131 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_131 = F_68 ( V_131 ) ;
V_145 = * V_131 ;
if ( V_148 && V_145 == '-' )
V_145 = * ( V_131 + 1 ) ;
if ( ! V_145
|| ( V_3 == 16 && ! isxdigit ( V_145 ) )
|| ( V_3 == 10 && ! isdigit ( V_145 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_145 ) || V_145 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_145 ) ) )
break;
if ( V_148 )
V_147 . V_7 = V_112 != 'L' ?
F_5 ( V_131 , & V_144 , V_3 ) :
F_6 ( V_131 , & V_144 , V_3 ) ;
else
V_147 . V_146 = V_112 != 'L' ?
F_4 ( V_131 , & V_144 , V_3 ) :
F_1 ( V_131 , & V_144 , V_3 ) ;
if ( V_38 > 0 && V_144 - V_131 > V_38 ) {
if ( V_3 == 0 )
F_2 ( V_131 , & V_3 ) ;
while ( V_144 - V_131 > V_38 ) {
if ( V_148 )
V_147 . V_7 = F_69 ( V_147 . V_7 , V_3 ) ;
else
V_147 . V_146 = F_70 ( V_147 . V_146 , V_3 ) ;
-- V_144 ;
}
}
switch ( V_112 ) {
case 'H' :
if ( V_148 )
* va_arg (args, signed char *) = V_147 . V_7 ;
else
* va_arg (args, unsigned char *) = V_147 . V_146 ;
break;
case 'h' :
if ( V_148 )
* va_arg ( args , short * ) = V_147 . V_7 ;
else
* va_arg (args, unsigned short *) = V_147 . V_146 ;
break;
case 'l' :
if ( V_148 )
* va_arg ( args , long * ) = V_147 . V_7 ;
else
* va_arg (args, unsigned long *) = V_147 . V_146 ;
break;
case 'L' :
if ( V_148 )
* va_arg (args, long long *) = V_147 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_147 . V_146 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_6 * ) = V_147 . V_146 ;
break;
default:
if ( V_148 )
* va_arg ( args , int * ) = V_147 . V_7 ;
else
* va_arg (args, unsigned int *) = V_147 . V_146 ;
break;
}
V_20 ++ ;
if ( ! V_144 )
break;
V_131 = V_144 ;
}
return V_20 ;
}
int sscanf ( const char * V_9 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = vsscanf ( V_9 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
