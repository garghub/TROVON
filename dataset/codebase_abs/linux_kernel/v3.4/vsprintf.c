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
unsigned V_11 , V_12 , V_13 , V_14 ;
V_13 = ( V_10 >> 4 ) & 0xf ;
V_12 = ( V_10 >> 8 ) & 0xf ;
V_11 = ( V_10 >> 12 ) ;
V_14 = 6 * ( V_11 + V_12 + V_13 ) + ( V_10 & 0xf ) ;
V_10 = ( V_14 * 0xcd ) >> 11 ;
V_14 = V_14 - 10 * V_10 ;
* V_9 ++ = V_14 + '0' ;
V_13 = V_10 + 9 * V_11 + 5 * V_12 + V_13 ;
if ( V_13 != 0 ) {
V_10 = ( V_13 * 0xcd ) >> 11 ;
V_13 = V_13 - 10 * V_10 ;
* V_9 ++ = V_13 + '0' ;
V_12 = V_10 + 2 * V_12 ;
if ( ( V_12 != 0 ) || ( V_11 != 0 ) ) {
V_10 = ( V_12 * 0xd ) >> 7 ;
V_12 = V_12 - 10 * V_10 ;
* V_9 ++ = V_12 + '0' ;
V_11 = V_10 + 4 * V_11 ;
if ( V_11 != 0 ) {
V_10 = ( V_11 * 0xcd ) >> 11 ;
V_11 = V_11 - 10 * V_10 ;
* V_9 ++ = V_11 + '0' ;
if ( V_10 != 0 )
* V_9 ++ = V_10 + '0' ;
}
}
}
return V_9 ;
}
static T_1
char * F_9 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 , V_12 , V_13 , V_14 ;
V_13 = ( V_10 >> 4 ) & 0xf ;
V_12 = ( V_10 >> 8 ) & 0xf ;
V_11 = ( V_10 >> 12 ) ;
V_14 = 6 * ( V_11 + V_12 + V_13 ) + ( V_10 & 0xf ) ;
V_10 = ( V_14 * 0xcd ) >> 11 ;
V_14 = V_14 - 10 * V_10 ;
* V_9 ++ = V_14 + '0' ;
V_13 = V_10 + 9 * V_11 + 5 * V_12 + V_13 ;
V_10 = ( V_13 * 0xcd ) >> 11 ;
V_13 = V_13 - 10 * V_10 ;
* V_9 ++ = V_13 + '0' ;
V_12 = V_10 + 2 * V_12 ;
V_10 = ( V_12 * 0xd ) >> 7 ;
V_12 = V_12 - 10 * V_10 ;
* V_9 ++ = V_12 + '0' ;
V_11 = V_10 + 4 * V_11 ;
V_10 = ( V_11 * 0xcd ) >> 11 ;
V_11 = V_11 - 10 * V_10 ;
* V_9 ++ = V_11 + '0' ;
* V_9 ++ = V_10 + '0' ;
return V_9 ;
}
static T_1
char * F_10 ( char * V_9 , unsigned long long V_15 )
{
while ( 1 ) {
unsigned V_16 ;
if ( V_15 < 100000 )
return F_8 ( V_9 , V_15 ) ;
V_16 = F_11 ( V_15 , 100000 ) ;
V_9 = F_9 ( V_9 , V_16 ) ;
}
}
int F_12 ( char * V_9 , int V_17 , unsigned long long V_15 )
{
char V_18 [ 21 ] ;
int V_19 , V_20 ;
V_20 = F_10 ( V_18 , V_15 ) - V_18 ;
if ( V_20 > V_17 )
return 0 ;
for ( V_19 = 0 ; V_19 < V_20 ; ++ V_19 )
V_9 [ V_19 ] = V_18 [ V_20 - V_19 - 1 ] ;
return V_20 ;
}
static T_1
char * F_13 ( char * V_9 , char * V_21 , unsigned long long V_15 ,
struct V_22 V_23 )
{
static const char V_24 [ 16 ] = L_1 ;
char V_18 [ 66 ] ;
char V_25 ;
char V_26 ;
int V_27 = ( ( V_23 . V_28 & V_29 ) && V_23 . V_3 != 10 ) ;
int V_8 ;
V_26 = ( V_23 . V_28 & V_30 ) ;
if ( V_23 . V_28 & V_31 )
V_23 . V_28 &= ~ V_32 ;
V_25 = 0 ;
if ( V_23 . V_28 & V_33 ) {
if ( ( signed long long ) V_15 < 0 ) {
V_25 = '-' ;
V_15 = - ( signed long long ) V_15 ;
V_23 . V_34 -- ;
} else if ( V_23 . V_28 & V_35 ) {
V_25 = '+' ;
V_23 . V_34 -- ;
} else if ( V_23 . V_28 & V_36 ) {
V_25 = ' ' ;
V_23 . V_34 -- ;
}
}
if ( V_27 ) {
V_23 . V_34 -- ;
if ( V_23 . V_3 == 16 )
V_23 . V_34 -- ;
}
V_8 = 0 ;
if ( V_15 == 0 )
V_18 [ V_8 ++ ] = '0' ;
else if ( V_23 . V_3 != 10 ) {
int V_37 = V_23 . V_3 - 1 ;
int V_38 = 3 ;
if ( V_23 . V_3 == 16 )
V_38 = 4 ;
do {
V_18 [ V_8 ++ ] = ( V_24 [ ( ( unsigned char ) V_15 ) & V_37 ] | V_26 ) ;
V_15 >>= V_38 ;
} while ( V_15 );
} else {
V_8 = F_10 ( V_18 , V_15 ) - V_18 ;
}
if ( V_8 > V_23 . V_39 )
V_23 . V_39 = V_8 ;
V_23 . V_34 -= V_23 . V_39 ;
if ( ! ( V_23 . V_28 & ( V_32 + V_31 ) ) ) {
while ( -- V_23 . V_34 >= 0 ) {
if ( V_9 < V_21 )
* V_9 = ' ' ;
++ V_9 ;
}
}
if ( V_25 ) {
if ( V_9 < V_21 )
* V_9 = V_25 ;
++ V_9 ;
}
if ( V_27 ) {
if ( V_9 < V_21 )
* V_9 = '0' ;
++ V_9 ;
if ( V_23 . V_3 == 16 ) {
if ( V_9 < V_21 )
* V_9 = ( 'X' | V_26 ) ;
++ V_9 ;
}
}
if ( ! ( V_23 . V_28 & V_31 ) ) {
char V_40 = ( V_23 . V_28 & V_32 ) ? '0' : ' ' ;
while ( -- V_23 . V_34 >= 0 ) {
if ( V_9 < V_21 )
* V_9 = V_40 ;
++ V_9 ;
}
}
while ( V_8 <= -- V_23 . V_39 ) {
if ( V_9 < V_21 )
* V_9 = '0' ;
++ V_9 ;
}
while ( -- V_8 >= 0 ) {
if ( V_9 < V_21 )
* V_9 = V_18 [ V_8 ] ;
++ V_9 ;
}
while ( -- V_23 . V_34 >= 0 ) {
if ( V_9 < V_21 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * string ( char * V_9 , char * V_21 , const char * V_7 , struct V_22 V_23 )
{
int V_20 , V_8 ;
if ( ( unsigned long ) V_7 < V_41 )
V_7 = L_2 ;
V_20 = F_14 ( V_7 , V_23 . V_39 ) ;
if ( ! ( V_23 . V_28 & V_31 ) ) {
while ( V_20 < V_23 . V_34 -- ) {
if ( V_9 < V_21 )
* V_9 = ' ' ;
++ V_9 ;
}
}
for ( V_8 = 0 ; V_8 < V_20 ; ++ V_8 ) {
if ( V_9 < V_21 )
* V_9 = * V_7 ;
++ V_9 ; ++ V_7 ;
}
while ( V_20 < V_23 . V_34 -- ) {
if ( V_9 < V_21 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * F_15 ( char * V_9 , char * V_21 , void * V_42 ,
struct V_22 V_23 , char V_43 )
{
unsigned long V_44 = ( unsigned long ) V_42 ;
#ifdef F_16
char V_45 [ V_46 ] ;
if ( V_43 == 'B' )
F_17 ( V_45 , V_44 ) ;
else if ( V_43 != 'f' && V_43 != 's' )
F_18 ( V_45 , V_44 ) ;
else
F_19 ( V_44 , NULL , NULL , NULL , V_45 ) ;
return string ( V_9 , V_21 , V_45 , V_23 ) ;
#else
V_23 . V_34 = 2 * sizeof( void * ) ;
V_23 . V_28 |= V_29 | V_30 | V_32 ;
V_23 . V_3 = 16 ;
return F_13 ( V_9 , V_21 , V_44 , V_23 ) ;
#endif
}
static T_1
char * F_20 ( char * V_9 , char * V_21 , struct V_47 * V_48 ,
struct V_22 V_23 , const char * V_49 )
{
#ifndef F_21
#define F_21 6
#endif
#ifndef F_22
#define F_22 10
#endif
static const struct V_22 V_50 = {
. V_3 = 16 ,
. V_34 = F_21 ,
. V_39 = - 1 ,
. V_28 = V_29 | V_30 | V_32 ,
} ;
static const struct V_22 V_51 = {
. V_3 = 16 ,
. V_34 = F_22 ,
. V_39 = - 1 ,
. V_28 = V_29 | V_30 | V_32 ,
} ;
static const struct V_22 V_52 = {
. V_3 = 16 ,
. V_34 = 2 ,
. V_39 = - 1 ,
. V_28 = V_30 | V_32 ,
} ;
static const struct V_22 V_53 = {
. V_3 = 10 ,
. V_39 = - 1 ,
. V_28 = 0 ,
} ;
static const struct V_22 V_54 = {
. V_34 = - 1 ,
. V_39 = 10 ,
. V_28 = V_31 ,
} ;
static const struct V_22 V_55 = {
. V_3 = 16 ,
. V_39 = - 1 ,
. V_28 = V_29 | V_30 ,
} ;
#define F_23 ((2 * sizeof(resource_size_t)) + 4)
#define F_24 (2 * sizeof(res->flags))
#define F_25 sizeof("[mem - 64bit pref window disabled]")
#define F_26 sizeof("[mem - flags 0x]")
char V_45 [ F_27 ( 2 * F_23 + F_25 ,
2 * F_23 + F_24 + F_26 ) ] ;
char * V_56 = V_45 , * V_57 = V_45 + sizeof( V_45 ) ;
int V_58 = ( V_49 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_22 * V_59 ;
* V_56 ++ = '[' ;
if ( V_48 -> V_28 & V_60 ) {
V_56 = string ( V_56 , V_57 , L_3 , V_54 ) ;
V_59 = & V_50 ;
} else if ( V_48 -> V_28 & V_61 ) {
V_56 = string ( V_56 , V_57 , L_4 , V_54 ) ;
V_59 = & V_51 ;
} else if ( V_48 -> V_28 & V_62 ) {
V_56 = string ( V_56 , V_57 , L_5 , V_54 ) ;
V_59 = & V_53 ;
} else if ( V_48 -> V_28 & V_63 ) {
V_56 = string ( V_56 , V_57 , L_6 , V_54 ) ;
V_59 = & V_53 ;
} else if ( V_48 -> V_28 & V_64 ) {
V_56 = string ( V_56 , V_57 , L_7 , V_54 ) ;
V_59 = & V_52 ;
} else {
V_56 = string ( V_56 , V_57 , L_8 , V_54 ) ;
V_59 = & V_51 ;
V_58 = 0 ;
}
V_56 = F_13 ( V_56 , V_57 , V_48 -> V_65 , * V_59 ) ;
if ( V_48 -> V_65 != V_48 -> V_21 ) {
* V_56 ++ = '-' ;
V_56 = F_13 ( V_56 , V_57 , V_48 -> V_21 , * V_59 ) ;
}
if ( V_58 ) {
if ( V_48 -> V_28 & V_66 )
V_56 = string ( V_56 , V_57 , L_9 , V_54 ) ;
if ( V_48 -> V_28 & V_67 )
V_56 = string ( V_56 , V_57 , L_10 , V_54 ) ;
if ( V_48 -> V_28 & V_68 )
V_56 = string ( V_56 , V_57 , L_11 , V_54 ) ;
if ( V_48 -> V_28 & V_69 )
V_56 = string ( V_56 , V_57 , L_12 , V_54 ) ;
} else {
V_56 = string ( V_56 , V_57 , L_13 , V_54 ) ;
V_56 = F_13 ( V_56 , V_57 , V_48 -> V_28 , V_55 ) ;
}
* V_56 ++ = ']' ;
* V_56 = '\0' ;
return string ( V_9 , V_21 , V_45 , V_23 ) ;
}
static T_1
char * F_28 ( char * V_9 , char * V_21 , T_2 * V_70 ,
struct V_22 V_23 , const char * V_49 )
{
char V_71 [ sizeof( L_14 ) ] ;
char * V_56 = V_71 ;
int V_8 ;
char V_72 ;
if ( V_49 [ 1 ] == 'F' ) {
V_72 = '-' ;
} else {
V_72 = ':' ;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_56 = F_29 ( V_56 , V_70 [ V_8 ] ) ;
if ( V_49 [ 0 ] == 'M' && V_8 != 5 )
* V_56 ++ = V_72 ;
}
* V_56 = '\0' ;
return string ( V_9 , V_21 , V_71 , V_23 ) ;
}
static T_1
char * F_30 ( char * V_56 , const T_2 * V_70 , const char * V_49 )
{
int V_8 ;
bool V_73 = ( V_49 [ 0 ] == 'i' ) ;
int V_74 ;
int V_75 ;
switch ( V_49 [ 2 ] ) {
case 'h' :
#ifdef F_31
V_74 = 0 ;
V_75 = 1 ;
#else
V_74 = 3 ;
V_75 = - 1 ;
#endif
break;
case 'l' :
V_74 = 3 ;
V_75 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_74 = 0 ;
V_75 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_76 [ 3 ] ;
int V_24 = F_8 ( V_76 , V_70 [ V_74 ] ) - V_76 ;
if ( V_73 ) {
if ( V_24 < 3 )
* V_56 ++ = '0' ;
if ( V_24 < 2 )
* V_56 ++ = '0' ;
}
while ( V_24 -- )
* V_56 ++ = V_76 [ V_24 ] ;
if ( V_8 < 3 )
* V_56 ++ = '.' ;
V_74 += V_75 ;
}
* V_56 = '\0' ;
return V_56 ;
}
static T_1
char * F_32 ( char * V_56 , const char * V_70 )
{
int V_8 , V_77 , V_78 ;
unsigned char V_79 [ 8 ] ;
int V_80 = 1 ;
int V_81 = - 1 ;
T_3 V_82 ;
T_2 V_83 , V_84 ;
bool V_85 = false ;
bool V_86 ;
struct V_87 V_88 ;
memcpy ( & V_88 , V_70 , sizeof( struct V_87 ) ) ;
V_86 = F_33 ( & V_88 ) || F_34 ( & V_88 ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
if ( V_86 )
V_78 = 6 ;
else
V_78 = 8 ;
for ( V_8 = 0 ; V_8 < V_78 ; V_8 ++ ) {
for ( V_77 = V_8 ; V_77 < V_78 ; V_77 ++ ) {
if ( V_88 . V_89 [ V_77 ] != 0 )
break;
V_79 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_78 ; V_8 ++ ) {
if ( V_79 [ V_8 ] > V_80 ) {
V_80 = V_79 [ V_8 ] ;
V_81 = V_8 ;
}
}
if ( V_80 == 1 )
V_81 = - 1 ;
for ( V_8 = 0 ; V_8 < V_78 ; V_8 ++ ) {
if ( V_8 == V_81 ) {
if ( V_85 || V_8 == 0 )
* V_56 ++ = ':' ;
* V_56 ++ = ':' ;
V_85 = false ;
V_8 += V_80 - 1 ;
continue;
}
if ( V_85 ) {
* V_56 ++ = ':' ;
V_85 = false ;
}
V_82 = F_35 ( V_88 . V_89 [ V_8 ] ) ;
V_83 = V_82 >> 8 ;
V_84 = V_82 & 0xff ;
if ( V_83 ) {
if ( V_83 > 0x0f )
V_56 = F_29 ( V_56 , V_83 ) ;
else
* V_56 ++ = F_36 ( V_83 ) ;
V_56 = F_29 ( V_56 , V_84 ) ;
}
else if ( V_84 > 0x0f )
V_56 = F_29 ( V_56 , V_84 ) ;
else
* V_56 ++ = F_36 ( V_84 ) ;
V_85 = true ;
}
if ( V_86 ) {
if ( V_85 )
* V_56 ++ = ':' ;
V_56 = F_30 ( V_56 , & V_88 . V_90 [ 12 ] , L_15 ) ;
}
* V_56 = '\0' ;
return V_56 ;
}
static T_1
char * F_37 ( char * V_56 , const char * V_70 , const char * V_49 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_56 = F_29 ( V_56 , * V_70 ++ ) ;
V_56 = F_29 ( V_56 , * V_70 ++ ) ;
if ( V_49 [ 0 ] == 'I' && V_8 != 7 )
* V_56 ++ = ':' ;
}
* V_56 = '\0' ;
return V_56 ;
}
static T_1
char * F_38 ( char * V_9 , char * V_21 , const T_2 * V_70 ,
struct V_22 V_23 , const char * V_49 )
{
char V_91 [ sizeof( L_16 ) ] ;
if ( V_49 [ 0 ] == 'I' && V_49 [ 2 ] == 'c' )
F_32 ( V_91 , V_70 ) ;
else
F_37 ( V_91 , V_70 , V_49 ) ;
return string ( V_9 , V_21 , V_91 , V_23 ) ;
}
static T_1
char * F_39 ( char * V_9 , char * V_21 , const T_2 * V_70 ,
struct V_22 V_23 , const char * V_49 )
{
char V_92 [ sizeof( L_17 ) ] ;
F_30 ( V_92 , V_70 , V_49 ) ;
return string ( V_9 , V_21 , V_92 , V_23 ) ;
}
static T_1
char * F_40 ( char * V_9 , char * V_21 , const T_2 * V_70 ,
struct V_22 V_23 , const char * V_49 )
{
char V_93 [ sizeof( L_18 ) ] ;
char * V_56 = V_93 ;
int V_8 ;
static const T_2 V_94 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_2 V_95 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_2 * V_74 = V_94 ;
bool V_96 = false ;
switch ( * ( ++ V_49 ) ) {
case 'L' :
V_96 = true ;
case 'l' :
V_74 = V_95 ;
break;
case 'B' :
V_96 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_56 = F_29 ( V_56 , V_70 [ V_74 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_56 ++ = '-' ;
break;
}
}
* V_56 = 0 ;
if ( V_96 ) {
V_56 = V_93 ;
do {
* V_56 = toupper ( * V_56 ) ;
} while ( * ( ++ V_56 ) );
}
return string ( V_9 , V_21 , V_93 , V_23 ) ;
}
static
char * F_41 ( char * V_9 , char * V_21 , const T_2 * V_70 ,
struct V_22 V_23 )
{
V_23 . V_28 |= V_29 | V_30 | V_32 ;
if ( V_23 . V_34 == - 1 )
V_23 . V_34 = 2 + 2 * sizeof( V_97 ) ;
V_23 . V_3 = 16 ;
return F_13 ( V_9 , V_21 , * ( const V_97 * ) V_70 , V_23 ) ;
}
static T_1
char * F_42 ( const char * V_49 , char * V_9 , char * V_21 , void * V_42 ,
struct V_22 V_23 )
{
if ( ! V_42 && * V_49 != 'K' ) {
if ( V_23 . V_34 == - 1 )
V_23 . V_34 = 2 * sizeof( void * ) ;
return string ( V_9 , V_21 , L_2 , V_23 ) ;
}
switch ( * V_49 ) {
case 'F' :
case 'f' :
V_42 = F_43 ( V_42 ) ;
case 'S' :
case 's' :
case 'B' :
return F_15 ( V_9 , V_21 , V_42 , V_23 , * V_49 ) ;
case 'R' :
case 'r' :
return F_20 ( V_9 , V_21 , V_42 , V_23 , V_49 ) ;
case 'M' :
case 'm' :
return F_28 ( V_9 , V_21 , V_42 , V_23 , V_49 ) ;
case 'I' :
case 'i' :
switch ( V_49 [ 1 ] ) {
case '6' :
return F_38 ( V_9 , V_21 , V_42 , V_23 , V_49 ) ;
case '4' :
return F_39 ( V_9 , V_21 , V_42 , V_23 , V_49 ) ;
}
break;
case 'U' :
return F_40 ( V_9 , V_21 , V_42 , V_23 , V_49 ) ;
case 'V' :
{
T_4 V_98 ;
F_44 ( V_98 , * ( (struct V_99 * ) V_42 ) -> V_98 ) ;
V_9 += vsnprintf ( V_9 , V_21 > V_9 ? V_21 - V_9 : 0 ,
( (struct V_99 * ) V_42 ) -> V_49 , V_98 ) ;
va_end ( V_98 ) ;
return V_9 ;
}
case 'K' :
if ( F_45 () || F_46 () || F_47 () ) {
if ( V_23 . V_34 == - 1 )
V_23 . V_34 = 2 * sizeof( void * ) ;
return string ( V_9 , V_21 , L_19 , V_23 ) ;
}
if ( ! ( ( V_100 == 0 ) ||
( V_100 == 1 &&
F_48 ( V_101 , V_102 ) ) ) )
V_42 = NULL ;
break;
case 'N' :
switch ( V_49 [ 1 ] ) {
case 'F' :
return F_41 ( V_9 , V_21 , V_42 , V_23 ) ;
}
break;
}
V_23 . V_28 |= V_30 ;
if ( V_23 . V_34 == - 1 ) {
V_23 . V_34 = 2 * sizeof( void * ) ;
V_23 . V_28 |= V_32 ;
}
V_23 . V_3 = 16 ;
return F_13 ( V_9 , V_21 , ( unsigned long ) V_42 , V_23 ) ;
}
static T_1
int F_49 ( const char * V_49 , struct V_22 * V_23 )
{
const char * V_65 = V_49 ;
if ( V_23 -> type == V_103 ) {
if ( V_23 -> V_34 < 0 ) {
V_23 -> V_34 = - V_23 -> V_34 ;
V_23 -> V_28 |= V_31 ;
}
V_23 -> type = V_104 ;
goto V_39;
}
if ( V_23 -> type == V_105 ) {
if ( V_23 -> V_39 < 0 )
V_23 -> V_39 = 0 ;
V_23 -> type = V_104 ;
goto V_106;
}
V_23 -> type = V_104 ;
for (; * V_49 ; ++ V_49 ) {
if ( * V_49 == '%' )
break;
}
if ( V_49 != V_65 || ! * V_49 )
return V_49 - V_65 ;
V_23 -> V_28 = 0 ;
while ( 1 ) {
bool V_107 = true ;
++ V_49 ;
switch ( * V_49 ) {
case '-' : V_23 -> V_28 |= V_31 ; break;
case '+' : V_23 -> V_28 |= V_35 ; break;
case ' ' : V_23 -> V_28 |= V_36 ; break;
case '#' : V_23 -> V_28 |= V_29 ; break;
case '0' : V_23 -> V_28 |= V_32 ; break;
default: V_107 = false ;
}
if ( ! V_107 )
break;
}
V_23 -> V_34 = - 1 ;
if ( isdigit ( * V_49 ) )
V_23 -> V_34 = F_7 ( & V_49 ) ;
else if ( * V_49 == '*' ) {
V_23 -> type = V_103 ;
return ++ V_49 - V_65 ;
}
V_39:
V_23 -> V_39 = - 1 ;
if ( * V_49 == '.' ) {
++ V_49 ;
if ( isdigit ( * V_49 ) ) {
V_23 -> V_39 = F_7 ( & V_49 ) ;
if ( V_23 -> V_39 < 0 )
V_23 -> V_39 = 0 ;
} else if ( * V_49 == '*' ) {
V_23 -> type = V_105 ;
return ++ V_49 - V_65 ;
}
}
V_106:
V_23 -> V_106 = - 1 ;
if ( * V_49 == 'h' || F_50 ( * V_49 ) == 'l' ||
F_50 ( * V_49 ) == 'z' || * V_49 == 't' ) {
V_23 -> V_106 = * V_49 ++ ;
if ( F_51 ( V_23 -> V_106 == * V_49 ) ) {
if ( V_23 -> V_106 == 'l' ) {
V_23 -> V_106 = 'L' ;
++ V_49 ;
} else if ( V_23 -> V_106 == 'h' ) {
V_23 -> V_106 = 'H' ;
++ V_49 ;
}
}
}
V_23 -> V_3 = 10 ;
switch ( * V_49 ) {
case 'c' :
V_23 -> type = V_108 ;
return ++ V_49 - V_65 ;
case 's' :
V_23 -> type = V_109 ;
return ++ V_49 - V_65 ;
case 'p' :
V_23 -> type = V_110 ;
return V_49 - V_65 ;
case 'n' :
V_23 -> type = V_111 ;
return ++ V_49 - V_65 ;
case '%' :
V_23 -> type = V_112 ;
return ++ V_49 - V_65 ;
case 'o' :
V_23 -> V_3 = 8 ;
break;
case 'x' :
V_23 -> V_28 |= V_30 ;
case 'X' :
V_23 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_23 -> V_28 |= V_33 ;
case 'u' :
break;
default:
V_23 -> type = V_113 ;
return V_49 - V_65 ;
}
if ( V_23 -> V_106 == 'L' )
V_23 -> type = V_114 ;
else if ( V_23 -> V_106 == 'l' ) {
if ( V_23 -> V_28 & V_33 )
V_23 -> type = V_115 ;
else
V_23 -> type = V_116 ;
} else if ( F_50 ( V_23 -> V_106 ) == 'z' ) {
V_23 -> type = V_117 ;
} else if ( V_23 -> V_106 == 't' ) {
V_23 -> type = V_118 ;
} else if ( V_23 -> V_106 == 'H' ) {
if ( V_23 -> V_28 & V_33 )
V_23 -> type = V_119 ;
else
V_23 -> type = V_120 ;
} else if ( V_23 -> V_106 == 'h' ) {
if ( V_23 -> V_28 & V_33 )
V_23 -> type = V_121 ;
else
V_23 -> type = V_122 ;
} else {
if ( V_23 -> V_28 & V_33 )
V_23 -> type = V_123 ;
else
V_23 -> type = V_124 ;
}
return ++ V_49 - V_65 ;
}
int vsnprintf ( char * V_9 , T_5 V_17 , const char * V_49 , T_4 args )
{
unsigned long long V_15 ;
char * V_125 , * V_21 ;
struct V_22 V_23 = { 0 } ;
if ( F_52 ( ( int ) V_17 < 0 ) )
return 0 ;
V_125 = V_9 ;
V_21 = V_9 + V_17 ;
if ( V_21 < V_9 ) {
V_21 = ( ( void * ) - 1 ) ;
V_17 = V_21 - V_9 ;
}
while ( * V_49 ) {
const char * V_126 = V_49 ;
int V_127 = F_49 ( V_49 , & V_23 ) ;
V_49 += V_127 ;
switch ( V_23 . type ) {
case V_104 : {
int V_128 = V_127 ;
if ( V_125 < V_21 ) {
if ( V_128 > V_21 - V_125 )
V_128 = V_21 - V_125 ;
memcpy ( V_125 , V_126 , V_128 ) ;
}
V_125 += V_127 ;
break;
}
case V_103 :
V_23 . V_34 = va_arg ( args , int ) ;
break;
case V_105 :
V_23 . V_39 = va_arg ( args , int ) ;
break;
case V_108 : {
char V_40 ;
if ( ! ( V_23 . V_28 & V_31 ) ) {
while ( -- V_23 . V_34 > 0 ) {
if ( V_125 < V_21 )
* V_125 = ' ' ;
++ V_125 ;
}
}
V_40 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_125 < V_21 )
* V_125 = V_40 ;
++ V_125 ;
while ( -- V_23 . V_34 > 0 ) {
if ( V_125 < V_21 )
* V_125 = ' ' ;
++ V_125 ;
}
break;
}
case V_109 :
V_125 = string ( V_125 , V_21 , va_arg ( args , char * ) , V_23 ) ;
break;
case V_110 :
V_125 = F_42 ( V_49 + 1 , V_125 , V_21 , va_arg ( args , void * ) ,
V_23 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_112 :
if ( V_125 < V_21 )
* V_125 = '%' ;
++ V_125 ;
break;
case V_113 :
if ( V_125 < V_21 )
* V_125 = '%' ;
++ V_125 ;
break;
case V_111 : {
T_2 V_106 = V_23 . V_106 ;
if ( V_106 == 'l' ) {
long * V_129 = va_arg ( args , long * ) ;
* V_129 = ( V_125 - V_9 ) ;
} else if ( F_50 ( V_106 ) == 'z' ) {
T_5 * V_129 = va_arg ( args , T_5 * ) ;
* V_129 = ( V_125 - V_9 ) ;
} else {
int * V_129 = va_arg ( args , int * ) ;
* V_129 = ( V_125 - V_9 ) ;
}
break;
}
default:
switch ( V_23 . type ) {
case V_114 :
V_15 = va_arg (args, long long) ;
break;
case V_116 :
V_15 = va_arg (args, unsigned long) ;
break;
case V_115 :
V_15 = va_arg ( args , long ) ;
break;
case V_117 :
V_15 = va_arg ( args , T_5 ) ;
break;
case V_118 :
V_15 = va_arg ( args , V_130 ) ;
break;
case V_120 :
V_15 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_119 :
V_15 = ( signed char ) va_arg ( args , int ) ;
break;
case V_122 :
V_15 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_121 :
V_15 = ( short ) va_arg ( args , int ) ;
break;
case V_123 :
V_15 = ( int ) va_arg ( args , int ) ;
break;
default:
V_15 = va_arg (args, unsigned int) ;
}
V_125 = F_13 ( V_125 , V_21 , V_15 , V_23 ) ;
}
}
if ( V_17 > 0 ) {
if ( V_125 < V_21 )
* V_125 = '\0' ;
else
V_21 [ - 1 ] = '\0' ;
}
return V_125 - V_9 ;
}
int F_53 ( char * V_9 , T_5 V_17 , const char * V_49 , T_4 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_17 , V_49 , args ) ;
if ( F_54 ( V_8 < V_17 ) )
return V_8 ;
if ( V_17 != 0 )
return V_17 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_5 V_17 , const char * V_49 , ... )
{
T_4 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_17 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_55 ( char * V_9 , T_5 V_17 , const char * V_49 , ... )
{
T_4 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = F_53 ( V_9 , V_17 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_49 , T_4 args )
{
return vsnprintf ( V_9 , V_131 , V_49 , args ) ;
}
int sprintf ( char * V_9 , const char * V_49 , ... )
{
T_4 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsnprintf ( V_9 , V_131 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_56 ( T_6 * V_132 , T_5 V_17 , const char * V_49 , T_4 args )
{
struct V_22 V_23 = { 0 } ;
char * V_125 , * V_21 ;
V_125 = ( char * ) V_132 ;
V_21 = ( char * ) ( V_132 + V_17 ) ;
#define F_57 ( type ) \
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
int V_127 = F_49 ( V_49 , & V_23 ) ;
V_49 += V_127 ;
switch ( V_23 . type ) {
case V_104 :
case V_113 :
case V_112 :
break;
case V_103 :
case V_105 :
F_57 ( int ) ;
break;
case V_108 :
F_57 ( char ) ;
break;
case V_109 : {
const char * V_133 = va_arg ( args , char * ) ;
T_5 V_20 ;
if ( ( unsigned long ) V_133 > ( unsigned long ) - V_41
|| ( unsigned long ) V_133 < V_41 )
V_133 = L_2 ;
V_20 = strlen ( V_133 ) + 1 ;
if ( V_125 + V_20 < V_21 )
memcpy ( V_125 , V_133 , V_20 ) ;
V_125 += V_20 ;
break;
}
case V_110 :
F_57 ( void * ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_111 : {
T_2 V_106 = V_23 . V_106 ;
void * V_134 ;
if ( V_106 == 'l' )
V_134 = va_arg ( args , long * ) ;
else if ( F_50 ( V_106 ) == 'z' )
V_134 = va_arg ( args , T_5 * ) ;
else
V_134 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_23 . type ) {
case V_114 :
F_57 (long long) ;
break;
case V_116 :
case V_115 :
F_57 (unsigned long) ;
break;
case V_117 :
F_57 ( T_5 ) ;
break;
case V_118 :
F_57 ( V_130 ) ;
break;
case V_120 :
case V_119 :
F_57 ( char ) ;
break;
case V_122 :
case V_121 :
F_57 ( short ) ;
break;
default:
F_57 ( int ) ;
}
}
}
return ( T_6 * ) ( F_58 ( V_125 , sizeof( T_6 ) ) ) - V_132 ;
#undef F_57
}
int F_59 ( char * V_9 , T_5 V_17 , const char * V_49 , const T_6 * V_132 )
{
struct V_22 V_23 = { 0 } ;
char * V_125 , * V_21 ;
const char * args = ( const char * ) V_132 ;
if ( F_52 ( ( int ) V_17 < 0 ) )
return 0 ;
V_125 = V_9 ;
V_21 = V_9 + V_17 ;
#define F_60 ( type ) \
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
if ( V_21 < V_9 ) {
V_21 = ( ( void * ) - 1 ) ;
V_17 = V_21 - V_9 ;
}
while ( * V_49 ) {
const char * V_126 = V_49 ;
int V_127 = F_49 ( V_49 , & V_23 ) ;
V_49 += V_127 ;
switch ( V_23 . type ) {
case V_104 : {
int V_128 = V_127 ;
if ( V_125 < V_21 ) {
if ( V_128 > V_21 - V_125 )
V_128 = V_21 - V_125 ;
memcpy ( V_125 , V_126 , V_128 ) ;
}
V_125 += V_127 ;
break;
}
case V_103 :
V_23 . V_34 = F_60 ( int ) ;
break;
case V_105 :
V_23 . V_39 = F_60 ( int ) ;
break;
case V_108 : {
char V_40 ;
if ( ! ( V_23 . V_28 & V_31 ) ) {
while ( -- V_23 . V_34 > 0 ) {
if ( V_125 < V_21 )
* V_125 = ' ' ;
++ V_125 ;
}
}
V_40 = ( unsigned char ) F_60 ( char ) ;
if ( V_125 < V_21 )
* V_125 = V_40 ;
++ V_125 ;
while ( -- V_23 . V_34 > 0 ) {
if ( V_125 < V_21 )
* V_125 = ' ' ;
++ V_125 ;
}
break;
}
case V_109 : {
const char * V_135 = args ;
args += strlen ( V_135 ) + 1 ;
V_125 = string ( V_125 , V_21 , ( char * ) V_135 , V_23 ) ;
break;
}
case V_110 :
V_125 = F_42 ( V_49 + 1 , V_125 , V_21 , F_60 ( void * ) , V_23 ) ;
while ( isalnum ( * V_49 ) )
V_49 ++ ;
break;
case V_112 :
case V_113 :
if ( V_125 < V_21 )
* V_125 = '%' ;
++ V_125 ;
break;
case V_111 :
break;
default: {
unsigned long long V_15 ;
switch ( V_23 . type ) {
case V_114 :
V_15 = F_60 (long long) ;
break;
case V_116 :
case V_115 :
V_15 = F_60 (unsigned long) ;
break;
case V_117 :
V_15 = F_60 ( T_5 ) ;
break;
case V_118 :
V_15 = F_60 ( V_130 ) ;
break;
case V_120 :
V_15 = F_60 (unsigned char) ;
break;
case V_119 :
V_15 = F_60 (signed char) ;
break;
case V_122 :
V_15 = F_60 (unsigned short) ;
break;
case V_121 :
V_15 = F_60 ( short ) ;
break;
case V_124 :
V_15 = F_60 (unsigned int) ;
break;
default:
V_15 = F_60 ( int ) ;
}
V_125 = F_13 ( V_125 , V_21 , V_15 , V_23 ) ;
}
}
}
if ( V_17 > 0 ) {
if ( V_125 < V_21 )
* V_125 = '\0' ;
else
V_21 [ - 1 ] = '\0' ;
}
#undef F_60
return V_125 - V_9 ;
}
int F_61 ( T_6 * V_132 , T_5 V_17 , const char * V_49 , ... )
{
T_4 args ;
int V_136 ;
va_start ( args , V_49 ) ;
V_136 = F_56 ( V_132 , V_17 , V_49 , args ) ;
va_end ( args ) ;
return V_136 ;
}
int vsscanf ( const char * V_9 , const char * V_49 , T_4 args )
{
const char * V_125 = V_9 ;
char * V_137 ;
char V_138 ;
int V_15 = 0 ;
T_2 V_106 ;
T_2 V_3 ;
T_7 V_34 ;
bool V_139 ;
while ( * V_49 && * V_125 ) {
if ( isspace ( * V_49 ) ) {
V_49 = F_62 ( ++ V_49 ) ;
V_125 = F_62 ( V_125 ) ;
}
if ( * V_49 != '%' && * V_49 ) {
if ( * V_49 ++ != * V_125 ++ )
break;
continue;
}
if ( ! * V_49 )
break;
++ V_49 ;
if ( * V_49 == '*' ) {
while ( ! isspace ( * V_49 ) && * V_49 != '%' && * V_49 )
V_49 ++ ;
while ( ! isspace ( * V_125 ) && * V_125 )
V_125 ++ ;
continue;
}
V_34 = - 1 ;
if ( isdigit ( * V_49 ) )
V_34 = F_7 ( & V_49 ) ;
V_106 = - 1 ;
if ( * V_49 == 'h' || F_50 ( * V_49 ) == 'l' ||
F_50 ( * V_49 ) == 'z' ) {
V_106 = * V_49 ++ ;
if ( F_51 ( V_106 == * V_49 ) ) {
if ( V_106 == 'h' ) {
V_106 = 'H' ;
V_49 ++ ;
} else if ( V_106 == 'l' ) {
V_106 = 'L' ;
V_49 ++ ;
}
}
}
if ( ! * V_49 || ! * V_125 )
break;
V_3 = 10 ;
V_139 = 0 ;
switch ( * V_49 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_34 == - 1 )
V_34 = 1 ;
do {
* V_7 ++ = * V_125 ++ ;
} while ( -- V_34 > 0 && * V_125 );
V_15 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_34 == - 1 )
V_34 = V_140 ;
V_125 = F_62 ( V_125 ) ;
while ( * V_125 && ! isspace ( * V_125 ) && V_34 -- )
* V_7 ++ = * V_125 ++ ;
* V_7 = '\0' ;
V_15 ++ ;
}
continue;
case 'n' :
{
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = V_125 - V_9 ;
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
V_139 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_125 ++ != '%' )
return V_15 ;
continue;
default:
return V_15 ;
}
V_125 = F_62 ( V_125 ) ;
V_138 = * V_125 ;
if ( V_139 && V_138 == '-' )
V_138 = * ( V_125 + 1 ) ;
if ( ! V_138
|| ( V_3 == 16 && ! isxdigit ( V_138 ) )
|| ( V_3 == 10 && ! isdigit ( V_138 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_138 ) || V_138 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_138 ) ) )
break;
switch ( V_106 ) {
case 'H' :
if ( V_139 ) {
signed char * V_7 = ( signed char * ) va_arg (args, signed char *) ;
* V_7 = ( signed char ) F_5 ( V_125 , & V_137 , V_3 ) ;
} else {
unsigned char * V_7 = ( unsigned char * ) va_arg (args, unsigned char *) ;
* V_7 = ( unsigned char ) F_4 ( V_125 , & V_137 , V_3 ) ;
}
break;
case 'h' :
if ( V_139 ) {
short * V_7 = ( short * ) va_arg ( args , short * ) ;
* V_7 = ( short ) F_5 ( V_125 , & V_137 , V_3 ) ;
} else {
unsigned short * V_7 = ( unsigned short * ) va_arg (args, unsigned short *) ;
* V_7 = ( unsigned short ) F_4 ( V_125 , & V_137 , V_3 ) ;
}
break;
case 'l' :
if ( V_139 ) {
long * V_141 = ( long * ) va_arg ( args , long * ) ;
* V_141 = F_5 ( V_125 , & V_137 , V_3 ) ;
} else {
unsigned long * V_141 = ( unsigned long * ) va_arg (args, unsigned long *) ;
* V_141 = F_4 ( V_125 , & V_137 , V_3 ) ;
}
break;
case 'L' :
if ( V_139 ) {
long long * V_141 = ( long long * ) va_arg (args, long long *) ;
* V_141 = F_6 ( V_125 , & V_137 , V_3 ) ;
} else {
unsigned long long * V_141 = ( unsigned long long * ) va_arg (args, unsigned long long *) ;
* V_141 = F_1 ( V_125 , & V_137 , V_3 ) ;
}
break;
case 'Z' :
case 'z' :
{
T_5 * V_7 = ( T_5 * ) va_arg ( args , T_5 * ) ;
* V_7 = ( T_5 ) F_4 ( V_125 , & V_137 , V_3 ) ;
}
break;
default:
if ( V_139 ) {
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = ( int ) F_5 ( V_125 , & V_137 , V_3 ) ;
} else {
unsigned int * V_8 = ( unsigned int * ) va_arg (args, unsigned int*) ;
* V_8 = ( unsigned int ) F_4 ( V_125 , & V_137 , V_3 ) ;
}
break;
}
V_15 ++ ;
if ( ! V_137 )
break;
V_125 = V_137 ;
}
if ( * V_49 == '%' && * ( V_49 + 1 ) == 'n' ) {
int * V_56 = ( int * ) va_arg ( args , int * ) ;
* V_56 = V_125 - V_9 ;
}
return V_15 ;
}
int sscanf ( const char * V_9 , const char * V_49 , ... )
{
T_4 args ;
int V_8 ;
va_start ( args , V_49 ) ;
V_8 = vsscanf ( V_9 , V_49 , args ) ;
va_end ( args ) ;
return V_8 ;
}
