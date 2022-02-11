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
char * F_29 ( char * V_9 , char * V_24 , T_3 * V_74 , struct V_25 V_26 ,
const char * V_53 )
{
int V_8 , V_23 = 1 ;
char V_75 ;
if ( V_26 . V_38 == 0 )
return V_9 ;
if ( F_30 ( V_74 ) )
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
V_23 = F_31 ( int , V_26 . V_38 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_23 && V_9 < V_24 - 1 ; V_8 ++ ) {
V_9 = F_32 ( V_9 , V_74 [ V_8 ] ) ;
if ( V_9 < V_24 && V_75 && V_8 != V_23 - 1 )
* V_9 ++ = V_75 ;
}
return V_9 ;
}
static T_1
char * F_33 ( char * V_9 , char * V_24 , T_3 * V_74 ,
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
V_60 = F_32 ( V_60 , V_74 [ 5 - V_8 ] ) ;
else
V_60 = F_32 ( V_60 , V_74 [ V_8 ] ) ;
if ( V_53 [ 0 ] == 'M' && V_8 != 5 )
* V_60 ++ = V_75 ;
}
* V_60 = '\0' ;
return string ( V_9 , V_24 , V_76 , V_26 ) ;
}
static T_1
char * F_34 ( char * V_60 , const T_3 * V_74 , const char * V_53 )
{
int V_8 ;
bool V_78 = ( V_53 [ 0 ] == 'i' ) ;
int V_79 ;
int V_80 ;
switch ( V_53 [ 2 ] ) {
case 'h' :
#ifdef F_35
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
char * F_36 ( char * V_60 , const char * V_74 )
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
V_91 = F_37 ( & V_93 ) || F_38 ( & V_93 ) ;
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
V_87 = F_39 ( V_93 . V_94 [ V_8 ] ) ;
V_88 = V_87 >> 8 ;
V_89 = V_87 & 0xff ;
if ( V_88 ) {
if ( V_88 > 0x0f )
V_60 = F_32 ( V_60 , V_88 ) ;
else
* V_60 ++ = F_40 ( V_88 ) ;
V_60 = F_32 ( V_60 , V_89 ) ;
}
else if ( V_89 > 0x0f )
V_60 = F_32 ( V_60 , V_89 ) ;
else
* V_60 ++ = F_40 ( V_89 ) ;
V_90 = true ;
}
if ( V_91 ) {
if ( V_90 )
* V_60 ++ = ':' ;
V_60 = F_34 ( V_60 , & V_93 . V_95 [ 12 ] , L_15 ) ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_41 ( char * V_60 , const char * V_74 , const char * V_53 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_60 = F_32 ( V_60 , * V_74 ++ ) ;
V_60 = F_32 ( V_60 , * V_74 ++ ) ;
if ( V_53 [ 0 ] == 'I' && V_8 != 7 )
* V_60 ++ = ':' ;
}
* V_60 = '\0' ;
return V_60 ;
}
static T_1
char * F_42 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_96 [ sizeof( L_16 ) ] ;
if ( V_53 [ 0 ] == 'I' && V_53 [ 2 ] == 'c' )
F_36 ( V_96 , V_74 ) ;
else
F_41 ( V_96 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_96 , V_26 ) ;
}
static T_1
char * F_43 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 , const char * V_53 )
{
char V_97 [ sizeof( L_17 ) ] ;
F_34 ( V_97 , V_74 , V_53 ) ;
return string ( V_9 , V_24 , V_97 , V_26 ) ;
}
static T_1
char * F_44 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
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
V_60 = F_32 ( V_60 , V_74 [ V_79 [ V_8 ] ] ) ;
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
char * F_45 ( char * V_9 , char * V_24 , const T_3 * V_74 ,
struct V_25 V_26 )
{
V_26 . V_31 |= V_32 | V_34 | V_36 ;
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = 2 + 2 * sizeof( V_102 ) ;
V_26 . V_3 = 16 ;
return F_14 ( V_9 , V_24 , * ( const V_102 * ) V_74 , V_26 ) ;
}
static T_1
char * F_46 ( const char * V_53 , char * V_9 , char * V_24 , void * V_46 ,
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
V_46 = F_47 ( V_46 ) ;
case 'S' :
case 's' :
case 'B' :
return F_16 ( V_9 , V_24 , V_46 , V_26 , * V_53 ) ;
case 'R' :
case 'r' :
return F_21 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'h' :
return F_29 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'M' :
case 'm' :
return F_33 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'I' :
case 'i' :
switch ( V_53 [ 1 ] ) {
case '6' :
return F_42 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case '4' :
return F_43 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
}
break;
case 'U' :
return F_44 ( V_9 , V_24 , V_46 , V_26 , V_53 ) ;
case 'V' :
{
T_5 V_104 ;
F_48 ( V_104 , * ( (struct V_105 * ) V_46 ) -> V_104 ) ;
V_9 += vsnprintf ( V_9 , V_24 > V_9 ? V_24 - V_9 : 0 ,
( (struct V_105 * ) V_46 ) -> V_53 , V_104 ) ;
va_end ( V_104 ) ;
return V_9 ;
}
case 'K' :
if ( V_106 && ( F_49 () || F_50 () ||
F_51 () ) ) {
if ( V_26 . V_38 == - 1 )
V_26 . V_38 = V_103 ;
return string ( V_9 , V_24 , L_19 , V_26 ) ;
}
if ( ! ( ( V_106 == 0 ) ||
( V_106 == 1 &&
F_52 ( V_107 , V_108 ) ) ) )
V_46 = NULL ;
break;
case 'N' :
switch ( V_53 [ 1 ] ) {
case 'F' :
return F_45 ( V_9 , V_24 , V_46 , V_26 ) ;
}
break;
}
V_26 . V_31 |= V_34 ;
if ( V_26 . V_38 == - 1 ) {
V_26 . V_38 = V_103 ;
V_26 . V_31 |= V_36 ;
}
V_26 . V_3 = 16 ;
return F_14 ( V_9 , V_24 , ( unsigned long ) V_46 , V_26 ) ;
}
static T_1
int F_53 ( const char * V_53 , struct V_25 * V_26 )
{
const char * V_69 = V_53 ;
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
for (; * V_53 ; ++ V_53 ) {
if ( * V_53 == '%' )
break;
}
if ( V_53 != V_69 || ! * V_53 )
return V_53 - V_69 ;
V_26 -> V_31 = 0 ;
while ( 1 ) {
bool V_113 = true ;
++ V_53 ;
switch ( * V_53 ) {
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
if ( isdigit ( * V_53 ) )
V_26 -> V_38 = F_7 ( & V_53 ) ;
else if ( * V_53 == '*' ) {
V_26 -> type = V_109 ;
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
V_26 -> type = V_111 ;
return ++ V_53 - V_69 ;
}
}
V_112:
V_26 -> V_112 = - 1 ;
if ( * V_53 == 'h' || F_54 ( * V_53 ) == 'l' ||
F_54 ( * V_53 ) == 'z' || * V_53 == 't' ) {
V_26 -> V_112 = * V_53 ++ ;
if ( F_55 ( V_26 -> V_112 == * V_53 ) ) {
if ( V_26 -> V_112 == 'l' ) {
V_26 -> V_112 = 'L' ;
++ V_53 ;
} else if ( V_26 -> V_112 == 'h' ) {
V_26 -> V_112 = 'H' ;
++ V_53 ;
}
}
}
V_26 -> V_3 = 10 ;
switch ( * V_53 ) {
case 'c' :
V_26 -> type = V_114 ;
return ++ V_53 - V_69 ;
case 's' :
V_26 -> type = V_115 ;
return ++ V_53 - V_69 ;
case 'p' :
V_26 -> type = V_116 ;
return V_53 - V_69 ;
case 'n' :
V_26 -> type = V_117 ;
return ++ V_53 - V_69 ;
case '%' :
V_26 -> type = V_118 ;
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
V_26 -> type = V_119 ;
return V_53 - V_69 ;
}
if ( V_26 -> V_112 == 'L' )
V_26 -> type = V_120 ;
else if ( V_26 -> V_112 == 'l' ) {
if ( V_26 -> V_31 & V_37 )
V_26 -> type = V_121 ;
else
V_26 -> type = V_122 ;
} else if ( F_54 ( V_26 -> V_112 ) == 'z' ) {
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
return ++ V_53 - V_69 ;
}
int vsnprintf ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
unsigned long long V_20 ;
char * V_131 , * V_24 ;
struct V_25 V_26 = { 0 } ;
if ( F_56 ( ( int ) V_19 < 0 ) )
return 0 ;
V_131 = V_9 ;
V_24 = V_9 + V_19 ;
if ( V_24 < V_9 ) {
V_24 = ( ( void * ) - 1 ) ;
V_19 = V_24 - V_9 ;
}
while ( * V_53 ) {
const char * V_132 = V_53 ;
int V_133 = F_53 ( V_53 , & V_26 ) ;
V_53 += V_133 ;
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
V_131 = F_46 ( V_53 + 1 , V_131 , V_24 , va_arg ( args , void * ) ,
V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
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
} else if ( F_54 ( V_112 ) == 'z' ) {
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
V_20 = va_arg ( args , T_6 ) ;
break;
case V_124 :
V_20 = va_arg ( args , V_136 ) ;
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
V_131 = F_14 ( V_131 , V_24 , V_20 , V_26 ) ;
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
int F_57 ( char * V_9 , T_6 V_19 , const char * V_53 , T_5 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_19 , V_53 , args ) ;
if ( F_58 ( V_8 < V_19 ) )
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
int F_59 ( char * V_9 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = F_57 ( V_9 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_53 , T_5 args )
{
return vsnprintf ( V_9 , V_137 , V_53 , args ) ;
}
int sprintf ( char * V_9 , const char * V_53 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_53 ) ;
V_8 = vsnprintf ( V_9 , V_137 , V_53 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_60 ( T_7 * V_138 , T_6 V_19 , const char * V_53 , T_5 args )
{
struct V_25 V_26 = { 0 } ;
char * V_131 , * V_24 ;
V_131 = ( char * ) V_138 ;
V_24 = ( char * ) ( V_138 + V_19 ) ;
#define F_61 ( type ) \
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
int V_133 = F_53 ( V_53 , & V_26 ) ;
V_53 += V_133 ;
switch ( V_26 . type ) {
case V_110 :
case V_119 :
case V_118 :
break;
case V_109 :
case V_111 :
F_61 ( int ) ;
break;
case V_114 :
F_61 ( char ) ;
break;
case V_115 : {
const char * V_139 = va_arg ( args , char * ) ;
T_6 V_23 ;
if ( ( unsigned long ) V_139 > ( unsigned long ) - V_45
|| ( unsigned long ) V_139 < V_45 )
V_139 = L_2 ;
V_23 = strlen ( V_139 ) + 1 ;
if ( V_131 + V_23 < V_24 )
memcpy ( V_131 , V_139 , V_23 ) ;
V_131 += V_23 ;
break;
}
case V_116 :
F_61 ( void * ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
break;
case V_117 : {
T_3 V_112 = V_26 . V_112 ;
void * V_140 ;
if ( V_112 == 'l' )
V_140 = va_arg ( args , long * ) ;
else if ( F_54 ( V_112 ) == 'z' )
V_140 = va_arg ( args , T_6 * ) ;
else
V_140 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_26 . type ) {
case V_120 :
F_61 (long long) ;
break;
case V_122 :
case V_121 :
F_61 (unsigned long) ;
break;
case V_123 :
F_61 ( T_6 ) ;
break;
case V_124 :
F_61 ( V_136 ) ;
break;
case V_126 :
case V_125 :
F_61 ( char ) ;
break;
case V_128 :
case V_127 :
F_61 ( short ) ;
break;
default:
F_61 ( int ) ;
}
}
}
return ( T_7 * ) ( F_62 ( V_131 , sizeof( T_7 ) ) ) - V_138 ;
#undef F_61
}
int F_63 ( char * V_9 , T_6 V_19 , const char * V_53 , const T_7 * V_138 )
{
struct V_25 V_26 = { 0 } ;
char * V_131 , * V_24 ;
const char * args = ( const char * ) V_138 ;
if ( F_56 ( ( int ) V_19 < 0 ) )
return 0 ;
V_131 = V_9 ;
V_24 = V_9 + V_19 ;
#define F_64 ( type ) \
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
const char * V_132 = V_53 ;
int V_133 = F_53 ( V_53 , & V_26 ) ;
V_53 += V_133 ;
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
V_26 . V_38 = F_64 ( int ) ;
break;
case V_111 :
V_26 . V_43 = F_64 ( int ) ;
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
V_44 = ( unsigned char ) F_64 ( char ) ;
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
const char * V_141 = args ;
args += strlen ( V_141 ) + 1 ;
V_131 = string ( V_131 , V_24 , ( char * ) V_141 , V_26 ) ;
break;
}
case V_116 :
V_131 = F_46 ( V_53 + 1 , V_131 , V_24 , F_64 ( void * ) , V_26 ) ;
while ( isalnum ( * V_53 ) )
V_53 ++ ;
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
V_20 = F_64 (long long) ;
break;
case V_122 :
case V_121 :
V_20 = F_64 (unsigned long) ;
break;
case V_123 :
V_20 = F_64 ( T_6 ) ;
break;
case V_124 :
V_20 = F_64 ( V_136 ) ;
break;
case V_126 :
V_20 = F_64 (unsigned char) ;
break;
case V_125 :
V_20 = F_64 (signed char) ;
break;
case V_128 :
V_20 = F_64 (unsigned short) ;
break;
case V_127 :
V_20 = F_64 ( short ) ;
break;
case V_130 :
V_20 = F_64 (unsigned int) ;
break;
default:
V_20 = F_64 ( int ) ;
}
V_131 = F_14 ( V_131 , V_24 , V_20 , V_26 ) ;
}
}
}
if ( V_19 > 0 ) {
if ( V_131 < V_24 )
* V_131 = '\0' ;
else
V_24 [ - 1 ] = '\0' ;
}
#undef F_64
return V_131 - V_9 ;
}
int F_65 ( T_7 * V_138 , T_6 V_19 , const char * V_53 , ... )
{
T_5 args ;
int V_142 ;
va_start ( args , V_53 ) ;
V_142 = F_60 ( V_138 , V_19 , V_53 , args ) ;
va_end ( args ) ;
return V_142 ;
}
int vsscanf ( const char * V_9 , const char * V_53 , T_5 args )
{
const char * V_131 = V_9 ;
char * V_143 ;
char V_144 ;
int V_20 = 0 ;
T_3 V_112 ;
T_3 V_3 ;
T_8 V_38 ;
bool V_145 ;
while ( * V_53 && * V_131 ) {
if ( isspace ( * V_53 ) ) {
V_53 = F_66 ( ++ V_53 ) ;
V_131 = F_66 ( V_131 ) ;
}
if ( * V_53 != '%' && * V_53 ) {
if ( * V_53 ++ != * V_131 ++ )
break;
continue;
}
if ( ! * V_53 )
break;
++ V_53 ;
if ( * V_53 == '*' ) {
while ( ! isspace ( * V_53 ) && * V_53 != '%' && * V_53 )
V_53 ++ ;
while ( ! isspace ( * V_131 ) && * V_131 )
V_131 ++ ;
continue;
}
V_38 = - 1 ;
if ( isdigit ( * V_53 ) )
V_38 = F_7 ( & V_53 ) ;
V_112 = - 1 ;
if ( * V_53 == 'h' || F_54 ( * V_53 ) == 'l' ||
F_54 ( * V_53 ) == 'z' ) {
V_112 = * V_53 ++ ;
if ( F_55 ( V_112 == * V_53 ) ) {
if ( V_112 == 'h' ) {
V_112 = 'H' ;
V_53 ++ ;
} else if ( V_112 == 'l' ) {
V_112 = 'L' ;
V_53 ++ ;
}
}
}
if ( ! * V_53 || ! * V_131 )
break;
V_3 = 10 ;
V_145 = 0 ;
switch ( * V_53 ++ ) {
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
V_38 = V_146 ;
V_131 = F_66 ( V_131 ) ;
while ( * V_131 && ! isspace ( * V_131 ) && V_38 -- )
* V_7 ++ = * V_131 ++ ;
* V_7 = '\0' ;
V_20 ++ ;
}
continue;
case 'n' :
{
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = V_131 - V_9 ;
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
V_145 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_131 ++ != '%' )
return V_20 ;
continue;
default:
return V_20 ;
}
V_131 = F_66 ( V_131 ) ;
V_144 = * V_131 ;
if ( V_145 && V_144 == '-' )
V_144 = * ( V_131 + 1 ) ;
if ( ! V_144
|| ( V_3 == 16 && ! isxdigit ( V_144 ) )
|| ( V_3 == 10 && ! isdigit ( V_144 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_144 ) || V_144 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_144 ) ) )
break;
switch ( V_112 ) {
case 'H' :
if ( V_145 ) {
signed char * V_7 = ( signed char * ) va_arg (args, signed char *) ;
* V_7 = ( signed char ) F_5 ( V_131 , & V_143 , V_3 ) ;
} else {
unsigned char * V_7 = ( unsigned char * ) va_arg (args, unsigned char *) ;
* V_7 = ( unsigned char ) F_4 ( V_131 , & V_143 , V_3 ) ;
}
break;
case 'h' :
if ( V_145 ) {
short * V_7 = ( short * ) va_arg ( args , short * ) ;
* V_7 = ( short ) F_5 ( V_131 , & V_143 , V_3 ) ;
} else {
unsigned short * V_7 = ( unsigned short * ) va_arg (args, unsigned short *) ;
* V_7 = ( unsigned short ) F_4 ( V_131 , & V_143 , V_3 ) ;
}
break;
case 'l' :
if ( V_145 ) {
long * V_147 = ( long * ) va_arg ( args , long * ) ;
* V_147 = F_5 ( V_131 , & V_143 , V_3 ) ;
} else {
unsigned long * V_147 = ( unsigned long * ) va_arg (args, unsigned long *) ;
* V_147 = F_4 ( V_131 , & V_143 , V_3 ) ;
}
break;
case 'L' :
if ( V_145 ) {
long long * V_147 = ( long long * ) va_arg (args, long long *) ;
* V_147 = F_6 ( V_131 , & V_143 , V_3 ) ;
} else {
unsigned long long * V_147 = ( unsigned long long * ) va_arg (args, unsigned long long *) ;
* V_147 = F_1 ( V_131 , & V_143 , V_3 ) ;
}
break;
case 'Z' :
case 'z' :
{
T_6 * V_7 = ( T_6 * ) va_arg ( args , T_6 * ) ;
* V_7 = ( T_6 ) F_4 ( V_131 , & V_143 , V_3 ) ;
}
break;
default:
if ( V_145 ) {
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = ( int ) F_5 ( V_131 , & V_143 , V_3 ) ;
} else {
unsigned int * V_8 = ( unsigned int * ) va_arg (args, unsigned int*) ;
* V_8 = ( unsigned int ) F_4 ( V_131 , & V_143 , V_3 ) ;
}
break;
}
V_20 ++ ;
if ( ! V_143 )
break;
V_131 = V_143 ;
}
if ( * V_53 == '%' && * ( V_53 + 1 ) == 'n' ) {
int * V_60 = ( int * ) va_arg ( args , int * ) ;
* V_60 = V_131 - V_9 ;
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
