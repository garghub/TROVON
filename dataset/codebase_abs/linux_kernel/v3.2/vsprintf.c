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
static T_1
char * F_12 ( char * V_9 , char * V_17 , unsigned long long V_15 ,
struct V_18 V_19 )
{
static const char V_20 [ 16 ] = L_1 ;
char V_21 [ 66 ] ;
char V_22 ;
char V_23 ;
int V_24 = ( ( V_19 . V_25 & V_26 ) && V_19 . V_3 != 10 ) ;
int V_8 ;
V_23 = ( V_19 . V_25 & V_27 ) ;
if ( V_19 . V_25 & V_28 )
V_19 . V_25 &= ~ V_29 ;
V_22 = 0 ;
if ( V_19 . V_25 & V_30 ) {
if ( ( signed long long ) V_15 < 0 ) {
V_22 = '-' ;
V_15 = - ( signed long long ) V_15 ;
V_19 . V_31 -- ;
} else if ( V_19 . V_25 & V_32 ) {
V_22 = '+' ;
V_19 . V_31 -- ;
} else if ( V_19 . V_25 & V_33 ) {
V_22 = ' ' ;
V_19 . V_31 -- ;
}
}
if ( V_24 ) {
V_19 . V_31 -- ;
if ( V_19 . V_3 == 16 )
V_19 . V_31 -- ;
}
V_8 = 0 ;
if ( V_15 == 0 )
V_21 [ V_8 ++ ] = '0' ;
else if ( V_19 . V_3 != 10 ) {
int V_34 = V_19 . V_3 - 1 ;
int V_35 = 3 ;
if ( V_19 . V_3 == 16 )
V_35 = 4 ;
do {
V_21 [ V_8 ++ ] = ( V_20 [ ( ( unsigned char ) V_15 ) & V_34 ] | V_23 ) ;
V_15 >>= V_35 ;
} while ( V_15 );
} else {
V_8 = F_10 ( V_21 , V_15 ) - V_21 ;
}
if ( V_8 > V_19 . V_36 )
V_19 . V_36 = V_8 ;
V_19 . V_31 -= V_19 . V_36 ;
if ( ! ( V_19 . V_25 & ( V_29 + V_28 ) ) ) {
while ( -- V_19 . V_31 >= 0 ) {
if ( V_9 < V_17 )
* V_9 = ' ' ;
++ V_9 ;
}
}
if ( V_22 ) {
if ( V_9 < V_17 )
* V_9 = V_22 ;
++ V_9 ;
}
if ( V_24 ) {
if ( V_9 < V_17 )
* V_9 = '0' ;
++ V_9 ;
if ( V_19 . V_3 == 16 ) {
if ( V_9 < V_17 )
* V_9 = ( 'X' | V_23 ) ;
++ V_9 ;
}
}
if ( ! ( V_19 . V_25 & V_28 ) ) {
char V_37 = ( V_19 . V_25 & V_29 ) ? '0' : ' ' ;
while ( -- V_19 . V_31 >= 0 ) {
if ( V_9 < V_17 )
* V_9 = V_37 ;
++ V_9 ;
}
}
while ( V_8 <= -- V_19 . V_36 ) {
if ( V_9 < V_17 )
* V_9 = '0' ;
++ V_9 ;
}
while ( -- V_8 >= 0 ) {
if ( V_9 < V_17 )
* V_9 = V_21 [ V_8 ] ;
++ V_9 ;
}
while ( -- V_19 . V_31 >= 0 ) {
if ( V_9 < V_17 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * string ( char * V_9 , char * V_17 , const char * V_7 , struct V_18 V_19 )
{
int V_38 , V_8 ;
if ( ( unsigned long ) V_7 < V_39 )
V_7 = L_2 ;
V_38 = F_13 ( V_7 , V_19 . V_36 ) ;
if ( ! ( V_19 . V_25 & V_28 ) ) {
while ( V_38 < V_19 . V_31 -- ) {
if ( V_9 < V_17 )
* V_9 = ' ' ;
++ V_9 ;
}
}
for ( V_8 = 0 ; V_8 < V_38 ; ++ V_8 ) {
if ( V_9 < V_17 )
* V_9 = * V_7 ;
++ V_9 ; ++ V_7 ;
}
while ( V_38 < V_19 . V_31 -- ) {
if ( V_9 < V_17 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * F_14 ( char * V_9 , char * V_17 , void * V_40 ,
struct V_18 V_19 , char V_41 )
{
unsigned long V_42 = ( unsigned long ) V_40 ;
#ifdef F_15
char V_43 [ V_44 ] ;
if ( V_41 == 'B' )
F_16 ( V_43 , V_42 ) ;
else if ( V_41 != 'f' && V_41 != 's' )
F_17 ( V_43 , V_42 ) ;
else
F_18 ( V_42 , NULL , NULL , NULL , V_43 ) ;
return string ( V_9 , V_17 , V_43 , V_19 ) ;
#else
V_19 . V_31 = 2 * sizeof( void * ) ;
V_19 . V_25 |= V_26 | V_27 | V_29 ;
V_19 . V_3 = 16 ;
return F_12 ( V_9 , V_17 , V_42 , V_19 ) ;
#endif
}
static T_1
char * F_19 ( char * V_9 , char * V_17 , struct V_45 * V_46 ,
struct V_18 V_19 , const char * V_47 )
{
#ifndef F_20
#define F_20 6
#endif
#ifndef F_21
#define F_21 10
#endif
static const struct V_18 V_48 = {
. V_3 = 16 ,
. V_31 = F_20 ,
. V_36 = - 1 ,
. V_25 = V_26 | V_27 | V_29 ,
} ;
static const struct V_18 V_49 = {
. V_3 = 16 ,
. V_31 = F_21 ,
. V_36 = - 1 ,
. V_25 = V_26 | V_27 | V_29 ,
} ;
static const struct V_18 V_50 = {
. V_3 = 16 ,
. V_31 = 2 ,
. V_36 = - 1 ,
. V_25 = V_27 | V_29 ,
} ;
static const struct V_18 V_51 = {
. V_3 = 10 ,
. V_36 = - 1 ,
. V_25 = 0 ,
} ;
static const struct V_18 V_52 = {
. V_31 = - 1 ,
. V_36 = 10 ,
. V_25 = V_28 ,
} ;
static const struct V_18 V_53 = {
. V_3 = 16 ,
. V_36 = - 1 ,
. V_25 = V_26 | V_27 ,
} ;
#define F_22 ((2 * sizeof(resource_size_t)) + 4)
#define F_23 (2 * sizeof(res->flags))
#define F_24 sizeof("[mem - 64bit pref window disabled]")
#define F_25 sizeof("[mem - flags 0x]")
char V_43 [ F_26 ( 2 * F_22 + F_24 ,
2 * F_22 + F_23 + F_25 ) ] ;
char * V_54 = V_43 , * V_55 = V_43 + sizeof( V_43 ) ;
int V_56 = ( V_47 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_18 * V_57 ;
* V_54 ++ = '[' ;
if ( V_46 -> V_25 & V_58 ) {
V_54 = string ( V_54 , V_55 , L_3 , V_52 ) ;
V_57 = & V_48 ;
} else if ( V_46 -> V_25 & V_59 ) {
V_54 = string ( V_54 , V_55 , L_4 , V_52 ) ;
V_57 = & V_49 ;
} else if ( V_46 -> V_25 & V_60 ) {
V_54 = string ( V_54 , V_55 , L_5 , V_52 ) ;
V_57 = & V_51 ;
} else if ( V_46 -> V_25 & V_61 ) {
V_54 = string ( V_54 , V_55 , L_6 , V_52 ) ;
V_57 = & V_51 ;
} else if ( V_46 -> V_25 & V_62 ) {
V_54 = string ( V_54 , V_55 , L_7 , V_52 ) ;
V_57 = & V_50 ;
} else {
V_54 = string ( V_54 , V_55 , L_8 , V_52 ) ;
V_57 = & V_49 ;
V_56 = 0 ;
}
V_54 = F_12 ( V_54 , V_55 , V_46 -> V_63 , * V_57 ) ;
if ( V_46 -> V_63 != V_46 -> V_17 ) {
* V_54 ++ = '-' ;
V_54 = F_12 ( V_54 , V_55 , V_46 -> V_17 , * V_57 ) ;
}
if ( V_56 ) {
if ( V_46 -> V_25 & V_64 )
V_54 = string ( V_54 , V_55 , L_9 , V_52 ) ;
if ( V_46 -> V_25 & V_65 )
V_54 = string ( V_54 , V_55 , L_10 , V_52 ) ;
if ( V_46 -> V_25 & V_66 )
V_54 = string ( V_54 , V_55 , L_11 , V_52 ) ;
if ( V_46 -> V_25 & V_67 )
V_54 = string ( V_54 , V_55 , L_12 , V_52 ) ;
} else {
V_54 = string ( V_54 , V_55 , L_13 , V_52 ) ;
V_54 = F_12 ( V_54 , V_55 , V_46 -> V_25 , V_53 ) ;
}
* V_54 ++ = ']' ;
* V_54 = '\0' ;
return string ( V_9 , V_17 , V_43 , V_19 ) ;
}
static T_1
char * F_27 ( char * V_9 , char * V_17 , T_2 * V_68 ,
struct V_18 V_19 , const char * V_47 )
{
char V_69 [ sizeof( L_14 ) ] ;
char * V_54 = V_69 ;
int V_8 ;
char V_70 ;
if ( V_47 [ 1 ] == 'F' ) {
V_70 = '-' ;
} else {
V_70 = ':' ;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
V_54 = F_28 ( V_54 , V_68 [ V_8 ] ) ;
if ( V_47 [ 0 ] == 'M' && V_8 != 5 )
* V_54 ++ = V_70 ;
}
* V_54 = '\0' ;
return string ( V_9 , V_17 , V_69 , V_19 ) ;
}
static T_1
char * F_29 ( char * V_54 , const T_2 * V_68 , const char * V_47 )
{
int V_8 ;
bool V_71 = ( V_47 [ 0 ] == 'i' ) ;
int V_72 ;
int V_73 ;
switch ( V_47 [ 2 ] ) {
case 'h' :
#ifdef F_30
V_72 = 0 ;
V_73 = 1 ;
#else
V_72 = 3 ;
V_73 = - 1 ;
#endif
break;
case 'l' :
V_72 = 3 ;
V_73 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_72 = 0 ;
V_73 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_74 [ 3 ] ;
int V_20 = F_8 ( V_74 , V_68 [ V_72 ] ) - V_74 ;
if ( V_71 ) {
if ( V_20 < 3 )
* V_54 ++ = '0' ;
if ( V_20 < 2 )
* V_54 ++ = '0' ;
}
while ( V_20 -- )
* V_54 ++ = V_74 [ V_20 ] ;
if ( V_8 < 3 )
* V_54 ++ = '.' ;
V_72 += V_73 ;
}
* V_54 = '\0' ;
return V_54 ;
}
static T_1
char * F_31 ( char * V_54 , const char * V_68 )
{
int V_8 , V_75 , V_76 ;
unsigned char V_77 [ 8 ] ;
int V_78 = 1 ;
int V_79 = - 1 ;
T_3 V_80 ;
T_2 V_81 , V_82 ;
bool V_83 = false ;
bool V_84 ;
struct V_85 V_86 ;
memcpy ( & V_86 , V_68 , sizeof( struct V_85 ) ) ;
V_84 = F_32 ( & V_86 ) || F_33 ( & V_86 ) ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_84 )
V_76 = 6 ;
else
V_76 = 8 ;
for ( V_8 = 0 ; V_8 < V_76 ; V_8 ++ ) {
for ( V_75 = V_8 ; V_75 < V_76 ; V_75 ++ ) {
if ( V_86 . V_87 [ V_75 ] != 0 )
break;
V_77 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_76 ; V_8 ++ ) {
if ( V_77 [ V_8 ] > V_78 ) {
V_78 = V_77 [ V_8 ] ;
V_79 = V_8 ;
}
}
if ( V_78 == 1 )
V_79 = - 1 ;
for ( V_8 = 0 ; V_8 < V_76 ; V_8 ++ ) {
if ( V_8 == V_79 ) {
if ( V_83 || V_8 == 0 )
* V_54 ++ = ':' ;
* V_54 ++ = ':' ;
V_83 = false ;
V_8 += V_78 - 1 ;
continue;
}
if ( V_83 ) {
* V_54 ++ = ':' ;
V_83 = false ;
}
V_80 = F_34 ( V_86 . V_87 [ V_8 ] ) ;
V_81 = V_80 >> 8 ;
V_82 = V_80 & 0xff ;
if ( V_81 ) {
if ( V_81 > 0x0f )
V_54 = F_28 ( V_54 , V_81 ) ;
else
* V_54 ++ = F_35 ( V_81 ) ;
V_54 = F_28 ( V_54 , V_82 ) ;
}
else if ( V_82 > 0x0f )
V_54 = F_28 ( V_54 , V_82 ) ;
else
* V_54 ++ = F_35 ( V_82 ) ;
V_83 = true ;
}
if ( V_84 ) {
if ( V_83 )
* V_54 ++ = ':' ;
V_54 = F_29 ( V_54 , & V_86 . V_88 [ 12 ] , L_15 ) ;
}
* V_54 = '\0' ;
return V_54 ;
}
static T_1
char * F_36 ( char * V_54 , const char * V_68 , const char * V_47 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_54 = F_28 ( V_54 , * V_68 ++ ) ;
V_54 = F_28 ( V_54 , * V_68 ++ ) ;
if ( V_47 [ 0 ] == 'I' && V_8 != 7 )
* V_54 ++ = ':' ;
}
* V_54 = '\0' ;
return V_54 ;
}
static T_1
char * F_37 ( char * V_9 , char * V_17 , const T_2 * V_68 ,
struct V_18 V_19 , const char * V_47 )
{
char V_89 [ sizeof( L_16 ) ] ;
if ( V_47 [ 0 ] == 'I' && V_47 [ 2 ] == 'c' )
F_31 ( V_89 , V_68 ) ;
else
F_36 ( V_89 , V_68 , V_47 ) ;
return string ( V_9 , V_17 , V_89 , V_19 ) ;
}
static T_1
char * F_38 ( char * V_9 , char * V_17 , const T_2 * V_68 ,
struct V_18 V_19 , const char * V_47 )
{
char V_90 [ sizeof( L_17 ) ] ;
F_29 ( V_90 , V_68 , V_47 ) ;
return string ( V_9 , V_17 , V_90 , V_19 ) ;
}
static T_1
char * F_39 ( char * V_9 , char * V_17 , const T_2 * V_68 ,
struct V_18 V_19 , const char * V_47 )
{
char V_91 [ sizeof( L_18 ) ] ;
char * V_54 = V_91 ;
int V_8 ;
static const T_2 V_92 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_2 V_93 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_2 * V_72 = V_92 ;
bool V_94 = false ;
switch ( * ( ++ V_47 ) ) {
case 'L' :
V_94 = true ;
case 'l' :
V_72 = V_93 ;
break;
case 'B' :
V_94 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_54 = F_28 ( V_54 , V_68 [ V_72 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_54 ++ = '-' ;
break;
}
}
* V_54 = 0 ;
if ( V_94 ) {
V_54 = V_91 ;
do {
* V_54 = toupper ( * V_54 ) ;
} while ( * ( ++ V_54 ) );
}
return string ( V_9 , V_17 , V_91 , V_19 ) ;
}
static T_1
char * F_40 ( const char * V_47 , char * V_9 , char * V_17 , void * V_40 ,
struct V_18 V_19 )
{
if ( ! V_40 && * V_47 != 'K' ) {
if ( V_19 . V_31 == - 1 )
V_19 . V_31 = 2 * sizeof( void * ) ;
return string ( V_9 , V_17 , L_2 , V_19 ) ;
}
switch ( * V_47 ) {
case 'F' :
case 'f' :
V_40 = F_41 ( V_40 ) ;
case 'S' :
case 's' :
case 'B' :
return F_14 ( V_9 , V_17 , V_40 , V_19 , * V_47 ) ;
case 'R' :
case 'r' :
return F_19 ( V_9 , V_17 , V_40 , V_19 , V_47 ) ;
case 'M' :
case 'm' :
return F_27 ( V_9 , V_17 , V_40 , V_19 , V_47 ) ;
case 'I' :
case 'i' :
switch ( V_47 [ 1 ] ) {
case '6' :
return F_37 ( V_9 , V_17 , V_40 , V_19 , V_47 ) ;
case '4' :
return F_38 ( V_9 , V_17 , V_40 , V_19 , V_47 ) ;
}
break;
case 'U' :
return F_39 ( V_9 , V_17 , V_40 , V_19 , V_47 ) ;
case 'V' :
return V_9 + vsnprintf ( V_9 , V_17 > V_9 ? V_17 - V_9 : 0 ,
( (struct V_95 * ) V_40 ) -> V_47 ,
* ( ( (struct V_95 * ) V_40 ) -> V_96 ) ) ;
case 'K' :
if ( F_42 () || F_43 () || F_44 () ) {
if ( V_19 . V_31 == - 1 )
V_19 . V_31 = 2 * sizeof( void * ) ;
return string ( V_9 , V_17 , L_19 , V_19 ) ;
}
if ( ! ( ( V_97 == 0 ) ||
( V_97 == 1 &&
F_45 ( V_98 , V_99 ) ) ) )
V_40 = NULL ;
break;
}
V_19 . V_25 |= V_27 ;
if ( V_19 . V_31 == - 1 ) {
V_19 . V_31 = 2 * sizeof( void * ) ;
V_19 . V_25 |= V_29 ;
}
V_19 . V_3 = 16 ;
return F_12 ( V_9 , V_17 , ( unsigned long ) V_40 , V_19 ) ;
}
static T_1
int F_46 ( const char * V_47 , struct V_18 * V_19 )
{
const char * V_63 = V_47 ;
if ( V_19 -> type == V_100 ) {
if ( V_19 -> V_31 < 0 ) {
V_19 -> V_31 = - V_19 -> V_31 ;
V_19 -> V_25 |= V_28 ;
}
V_19 -> type = V_101 ;
goto V_36;
}
if ( V_19 -> type == V_102 ) {
if ( V_19 -> V_36 < 0 )
V_19 -> V_36 = 0 ;
V_19 -> type = V_101 ;
goto V_103;
}
V_19 -> type = V_101 ;
for (; * V_47 ; ++ V_47 ) {
if ( * V_47 == '%' )
break;
}
if ( V_47 != V_63 || ! * V_47 )
return V_47 - V_63 ;
V_19 -> V_25 = 0 ;
while ( 1 ) {
bool V_104 = true ;
++ V_47 ;
switch ( * V_47 ) {
case '-' : V_19 -> V_25 |= V_28 ; break;
case '+' : V_19 -> V_25 |= V_32 ; break;
case ' ' : V_19 -> V_25 |= V_33 ; break;
case '#' : V_19 -> V_25 |= V_26 ; break;
case '0' : V_19 -> V_25 |= V_29 ; break;
default: V_104 = false ;
}
if ( ! V_104 )
break;
}
V_19 -> V_31 = - 1 ;
if ( isdigit ( * V_47 ) )
V_19 -> V_31 = F_7 ( & V_47 ) ;
else if ( * V_47 == '*' ) {
V_19 -> type = V_100 ;
return ++ V_47 - V_63 ;
}
V_36:
V_19 -> V_36 = - 1 ;
if ( * V_47 == '.' ) {
++ V_47 ;
if ( isdigit ( * V_47 ) ) {
V_19 -> V_36 = F_7 ( & V_47 ) ;
if ( V_19 -> V_36 < 0 )
V_19 -> V_36 = 0 ;
} else if ( * V_47 == '*' ) {
V_19 -> type = V_102 ;
return ++ V_47 - V_63 ;
}
}
V_103:
V_19 -> V_103 = - 1 ;
if ( * V_47 == 'h' || F_47 ( * V_47 ) == 'l' ||
F_47 ( * V_47 ) == 'z' || * V_47 == 't' ) {
V_19 -> V_103 = * V_47 ++ ;
if ( F_48 ( V_19 -> V_103 == * V_47 ) ) {
if ( V_19 -> V_103 == 'l' ) {
V_19 -> V_103 = 'L' ;
++ V_47 ;
} else if ( V_19 -> V_103 == 'h' ) {
V_19 -> V_103 = 'H' ;
++ V_47 ;
}
}
}
V_19 -> V_3 = 10 ;
switch ( * V_47 ) {
case 'c' :
V_19 -> type = V_105 ;
return ++ V_47 - V_63 ;
case 's' :
V_19 -> type = V_106 ;
return ++ V_47 - V_63 ;
case 'p' :
V_19 -> type = V_107 ;
return V_47 - V_63 ;
case 'n' :
V_19 -> type = V_108 ;
return ++ V_47 - V_63 ;
case '%' :
V_19 -> type = V_109 ;
return ++ V_47 - V_63 ;
case 'o' :
V_19 -> V_3 = 8 ;
break;
case 'x' :
V_19 -> V_25 |= V_27 ;
case 'X' :
V_19 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_19 -> V_25 |= V_30 ;
case 'u' :
break;
default:
V_19 -> type = V_110 ;
return V_47 - V_63 ;
}
if ( V_19 -> V_103 == 'L' )
V_19 -> type = V_111 ;
else if ( V_19 -> V_103 == 'l' ) {
if ( V_19 -> V_25 & V_30 )
V_19 -> type = V_112 ;
else
V_19 -> type = V_113 ;
} else if ( F_47 ( V_19 -> V_103 ) == 'z' ) {
V_19 -> type = V_114 ;
} else if ( V_19 -> V_103 == 't' ) {
V_19 -> type = V_115 ;
} else if ( V_19 -> V_103 == 'H' ) {
if ( V_19 -> V_25 & V_30 )
V_19 -> type = V_116 ;
else
V_19 -> type = V_117 ;
} else if ( V_19 -> V_103 == 'h' ) {
if ( V_19 -> V_25 & V_30 )
V_19 -> type = V_118 ;
else
V_19 -> type = V_119 ;
} else {
if ( V_19 -> V_25 & V_30 )
V_19 -> type = V_120 ;
else
V_19 -> type = V_121 ;
}
return ++ V_47 - V_63 ;
}
int vsnprintf ( char * V_9 , T_4 V_122 , const char * V_47 , T_5 args )
{
unsigned long long V_15 ;
char * V_123 , * V_17 ;
struct V_18 V_19 = { 0 } ;
if ( F_49 ( ( int ) V_122 < 0 ) )
return 0 ;
V_123 = V_9 ;
V_17 = V_9 + V_122 ;
if ( V_17 < V_9 ) {
V_17 = ( ( void * ) - 1 ) ;
V_122 = V_17 - V_9 ;
}
while ( * V_47 ) {
const char * V_124 = V_47 ;
int V_125 = F_46 ( V_47 , & V_19 ) ;
V_47 += V_125 ;
switch ( V_19 . type ) {
case V_101 : {
int V_126 = V_125 ;
if ( V_123 < V_17 ) {
if ( V_126 > V_17 - V_123 )
V_126 = V_17 - V_123 ;
memcpy ( V_123 , V_124 , V_126 ) ;
}
V_123 += V_125 ;
break;
}
case V_100 :
V_19 . V_31 = va_arg ( args , int ) ;
break;
case V_102 :
V_19 . V_36 = va_arg ( args , int ) ;
break;
case V_105 : {
char V_37 ;
if ( ! ( V_19 . V_25 & V_28 ) ) {
while ( -- V_19 . V_31 > 0 ) {
if ( V_123 < V_17 )
* V_123 = ' ' ;
++ V_123 ;
}
}
V_37 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_123 < V_17 )
* V_123 = V_37 ;
++ V_123 ;
while ( -- V_19 . V_31 > 0 ) {
if ( V_123 < V_17 )
* V_123 = ' ' ;
++ V_123 ;
}
break;
}
case V_106 :
V_123 = string ( V_123 , V_17 , va_arg ( args , char * ) , V_19 ) ;
break;
case V_107 :
V_123 = F_40 ( V_47 + 1 , V_123 , V_17 , va_arg ( args , void * ) ,
V_19 ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_109 :
if ( V_123 < V_17 )
* V_123 = '%' ;
++ V_123 ;
break;
case V_110 :
if ( V_123 < V_17 )
* V_123 = '%' ;
++ V_123 ;
break;
case V_108 : {
T_2 V_103 = V_19 . V_103 ;
if ( V_103 == 'l' ) {
long * V_127 = va_arg ( args , long * ) ;
* V_127 = ( V_123 - V_9 ) ;
} else if ( F_47 ( V_103 ) == 'z' ) {
T_4 * V_127 = va_arg ( args , T_4 * ) ;
* V_127 = ( V_123 - V_9 ) ;
} else {
int * V_127 = va_arg ( args , int * ) ;
* V_127 = ( V_123 - V_9 ) ;
}
break;
}
default:
switch ( V_19 . type ) {
case V_111 :
V_15 = va_arg (args, long long) ;
break;
case V_113 :
V_15 = va_arg (args, unsigned long) ;
break;
case V_112 :
V_15 = va_arg ( args , long ) ;
break;
case V_114 :
V_15 = va_arg ( args , T_4 ) ;
break;
case V_115 :
V_15 = va_arg ( args , V_128 ) ;
break;
case V_117 :
V_15 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_116 :
V_15 = ( signed char ) va_arg ( args , int ) ;
break;
case V_119 :
V_15 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_118 :
V_15 = ( short ) va_arg ( args , int ) ;
break;
case V_120 :
V_15 = ( int ) va_arg ( args , int ) ;
break;
default:
V_15 = va_arg (args, unsigned int) ;
}
V_123 = F_12 ( V_123 , V_17 , V_15 , V_19 ) ;
}
}
if ( V_122 > 0 ) {
if ( V_123 < V_17 )
* V_123 = '\0' ;
else
V_17 [ - 1 ] = '\0' ;
}
return V_123 - V_9 ;
}
int F_50 ( char * V_9 , T_4 V_122 , const char * V_47 , T_5 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_122 , V_47 , args ) ;
if ( F_51 ( V_8 < V_122 ) )
return V_8 ;
if ( V_122 != 0 )
return V_122 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_4 V_122 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = vsnprintf ( V_9 , V_122 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_52 ( char * V_9 , T_4 V_122 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = F_50 ( V_9 , V_122 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_47 , T_5 args )
{
return vsnprintf ( V_9 , V_129 , V_47 , args ) ;
}
int sprintf ( char * V_9 , const char * V_47 , ... )
{
T_5 args ;
int V_8 ;
va_start ( args , V_47 ) ;
V_8 = vsnprintf ( V_9 , V_129 , V_47 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_53 ( T_6 * V_130 , T_4 V_122 , const char * V_47 , T_5 args )
{
struct V_18 V_19 = { 0 } ;
char * V_123 , * V_17 ;
V_123 = ( char * ) V_130 ;
V_17 = ( char * ) ( V_130 + V_122 ) ;
#define F_54 ( type ) \
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
int V_125 = F_46 ( V_47 , & V_19 ) ;
V_47 += V_125 ;
switch ( V_19 . type ) {
case V_101 :
case V_110 :
case V_109 :
break;
case V_100 :
case V_102 :
F_54 ( int ) ;
break;
case V_105 :
F_54 ( char ) ;
break;
case V_106 : {
const char * V_131 = va_arg ( args , char * ) ;
T_4 V_38 ;
if ( ( unsigned long ) V_131 > ( unsigned long ) - V_39
|| ( unsigned long ) V_131 < V_39 )
V_131 = L_2 ;
V_38 = strlen ( V_131 ) + 1 ;
if ( V_123 + V_38 < V_17 )
memcpy ( V_123 , V_131 , V_38 ) ;
V_123 += V_38 ;
break;
}
case V_107 :
F_54 ( void * ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_108 : {
T_2 V_103 = V_19 . V_103 ;
void * V_132 ;
if ( V_103 == 'l' )
V_132 = va_arg ( args , long * ) ;
else if ( F_47 ( V_103 ) == 'z' )
V_132 = va_arg ( args , T_4 * ) ;
else
V_132 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_19 . type ) {
case V_111 :
F_54 (long long) ;
break;
case V_113 :
case V_112 :
F_54 (unsigned long) ;
break;
case V_114 :
F_54 ( T_4 ) ;
break;
case V_115 :
F_54 ( V_128 ) ;
break;
case V_117 :
case V_116 :
F_54 ( char ) ;
break;
case V_119 :
case V_118 :
F_54 ( short ) ;
break;
default:
F_54 ( int ) ;
}
}
}
return ( T_6 * ) ( F_55 ( V_123 , sizeof( T_6 ) ) ) - V_130 ;
#undef F_54
}
int F_56 ( char * V_9 , T_4 V_122 , const char * V_47 , const T_6 * V_130 )
{
struct V_18 V_19 = { 0 } ;
char * V_123 , * V_17 ;
const char * args = ( const char * ) V_130 ;
if ( F_49 ( ( int ) V_122 < 0 ) )
return 0 ;
V_123 = V_9 ;
V_17 = V_9 + V_122 ;
#define F_57 ( type ) \
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
if ( V_17 < V_9 ) {
V_17 = ( ( void * ) - 1 ) ;
V_122 = V_17 - V_9 ;
}
while ( * V_47 ) {
const char * V_124 = V_47 ;
int V_125 = F_46 ( V_47 , & V_19 ) ;
V_47 += V_125 ;
switch ( V_19 . type ) {
case V_101 : {
int V_126 = V_125 ;
if ( V_123 < V_17 ) {
if ( V_126 > V_17 - V_123 )
V_126 = V_17 - V_123 ;
memcpy ( V_123 , V_124 , V_126 ) ;
}
V_123 += V_125 ;
break;
}
case V_100 :
V_19 . V_31 = F_57 ( int ) ;
break;
case V_102 :
V_19 . V_36 = F_57 ( int ) ;
break;
case V_105 : {
char V_37 ;
if ( ! ( V_19 . V_25 & V_28 ) ) {
while ( -- V_19 . V_31 > 0 ) {
if ( V_123 < V_17 )
* V_123 = ' ' ;
++ V_123 ;
}
}
V_37 = ( unsigned char ) F_57 ( char ) ;
if ( V_123 < V_17 )
* V_123 = V_37 ;
++ V_123 ;
while ( -- V_19 . V_31 > 0 ) {
if ( V_123 < V_17 )
* V_123 = ' ' ;
++ V_123 ;
}
break;
}
case V_106 : {
const char * V_133 = args ;
args += strlen ( V_133 ) + 1 ;
V_123 = string ( V_123 , V_17 , ( char * ) V_133 , V_19 ) ;
break;
}
case V_107 :
V_123 = F_40 ( V_47 + 1 , V_123 , V_17 , F_57 ( void * ) , V_19 ) ;
while ( isalnum ( * V_47 ) )
V_47 ++ ;
break;
case V_109 :
case V_110 :
if ( V_123 < V_17 )
* V_123 = '%' ;
++ V_123 ;
break;
case V_108 :
break;
default: {
unsigned long long V_15 ;
switch ( V_19 . type ) {
case V_111 :
V_15 = F_57 (long long) ;
break;
case V_113 :
case V_112 :
V_15 = F_57 (unsigned long) ;
break;
case V_114 :
V_15 = F_57 ( T_4 ) ;
break;
case V_115 :
V_15 = F_57 ( V_128 ) ;
break;
case V_117 :
V_15 = F_57 (unsigned char) ;
break;
case V_116 :
V_15 = F_57 (signed char) ;
break;
case V_119 :
V_15 = F_57 (unsigned short) ;
break;
case V_118 :
V_15 = F_57 ( short ) ;
break;
case V_121 :
V_15 = F_57 (unsigned int) ;
break;
default:
V_15 = F_57 ( int ) ;
}
V_123 = F_12 ( V_123 , V_17 , V_15 , V_19 ) ;
}
}
}
if ( V_122 > 0 ) {
if ( V_123 < V_17 )
* V_123 = '\0' ;
else
V_17 [ - 1 ] = '\0' ;
}
#undef F_57
return V_123 - V_9 ;
}
int F_58 ( T_6 * V_130 , T_4 V_122 , const char * V_47 , ... )
{
T_5 args ;
int V_134 ;
va_start ( args , V_47 ) ;
V_134 = F_53 ( V_130 , V_122 , V_47 , args ) ;
va_end ( args ) ;
return V_134 ;
}
int vsscanf ( const char * V_9 , const char * V_47 , T_5 args )
{
const char * V_123 = V_9 ;
char * V_135 ;
char V_136 ;
int V_15 = 0 ;
T_2 V_103 ;
T_2 V_3 ;
T_7 V_31 ;
bool V_137 ;
while ( * V_47 && * V_123 ) {
if ( isspace ( * V_47 ) ) {
V_47 = F_59 ( ++ V_47 ) ;
V_123 = F_59 ( V_123 ) ;
}
if ( * V_47 != '%' && * V_47 ) {
if ( * V_47 ++ != * V_123 ++ )
break;
continue;
}
if ( ! * V_47 )
break;
++ V_47 ;
if ( * V_47 == '*' ) {
while ( ! isspace ( * V_47 ) && * V_47 != '%' && * V_47 )
V_47 ++ ;
while ( ! isspace ( * V_123 ) && * V_123 )
V_123 ++ ;
continue;
}
V_31 = - 1 ;
if ( isdigit ( * V_47 ) )
V_31 = F_7 ( & V_47 ) ;
V_103 = - 1 ;
if ( * V_47 == 'h' || F_47 ( * V_47 ) == 'l' ||
F_47 ( * V_47 ) == 'z' ) {
V_103 = * V_47 ++ ;
if ( F_48 ( V_103 == * V_47 ) ) {
if ( V_103 == 'h' ) {
V_103 = 'H' ;
V_47 ++ ;
} else if ( V_103 == 'l' ) {
V_103 = 'L' ;
V_47 ++ ;
}
}
}
if ( ! * V_47 || ! * V_123 )
break;
V_3 = 10 ;
V_137 = 0 ;
switch ( * V_47 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_31 == - 1 )
V_31 = 1 ;
do {
* V_7 ++ = * V_123 ++ ;
} while ( -- V_31 > 0 && * V_123 );
V_15 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_31 == - 1 )
V_31 = V_138 ;
V_123 = F_59 ( V_123 ) ;
while ( * V_123 && ! isspace ( * V_123 ) && V_31 -- )
* V_7 ++ = * V_123 ++ ;
* V_7 = '\0' ;
V_15 ++ ;
}
continue;
case 'n' :
{
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = V_123 - V_9 ;
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
V_137 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_123 ++ != '%' )
return V_15 ;
continue;
default:
return V_15 ;
}
V_123 = F_59 ( V_123 ) ;
V_136 = * V_123 ;
if ( V_137 && V_136 == '-' )
V_136 = * ( V_123 + 1 ) ;
if ( ! V_136
|| ( V_3 == 16 && ! isxdigit ( V_136 ) )
|| ( V_3 == 10 && ! isdigit ( V_136 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_136 ) || V_136 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_136 ) ) )
break;
switch ( V_103 ) {
case 'H' :
if ( V_137 ) {
signed char * V_7 = ( signed char * ) va_arg (args, signed char *) ;
* V_7 = ( signed char ) F_5 ( V_123 , & V_135 , V_3 ) ;
} else {
unsigned char * V_7 = ( unsigned char * ) va_arg (args, unsigned char *) ;
* V_7 = ( unsigned char ) F_4 ( V_123 , & V_135 , V_3 ) ;
}
break;
case 'h' :
if ( V_137 ) {
short * V_7 = ( short * ) va_arg ( args , short * ) ;
* V_7 = ( short ) F_5 ( V_123 , & V_135 , V_3 ) ;
} else {
unsigned short * V_7 = ( unsigned short * ) va_arg (args, unsigned short *) ;
* V_7 = ( unsigned short ) F_4 ( V_123 , & V_135 , V_3 ) ;
}
break;
case 'l' :
if ( V_137 ) {
long * V_139 = ( long * ) va_arg ( args , long * ) ;
* V_139 = F_5 ( V_123 , & V_135 , V_3 ) ;
} else {
unsigned long * V_139 = ( unsigned long * ) va_arg (args, unsigned long *) ;
* V_139 = F_4 ( V_123 , & V_135 , V_3 ) ;
}
break;
case 'L' :
if ( V_137 ) {
long long * V_139 = ( long long * ) va_arg (args, long long *) ;
* V_139 = F_6 ( V_123 , & V_135 , V_3 ) ;
} else {
unsigned long long * V_139 = ( unsigned long long * ) va_arg (args, unsigned long long *) ;
* V_139 = F_1 ( V_123 , & V_135 , V_3 ) ;
}
break;
case 'Z' :
case 'z' :
{
T_4 * V_7 = ( T_4 * ) va_arg ( args , T_4 * ) ;
* V_7 = ( T_4 ) F_4 ( V_123 , & V_135 , V_3 ) ;
}
break;
default:
if ( V_137 ) {
int * V_8 = ( int * ) va_arg ( args , int * ) ;
* V_8 = ( int ) F_5 ( V_123 , & V_135 , V_3 ) ;
} else {
unsigned int * V_8 = ( unsigned int * ) va_arg (args, unsigned int*) ;
* V_8 = ( unsigned int ) F_4 ( V_123 , & V_135 , V_3 ) ;
}
break;
}
V_15 ++ ;
if ( ! V_135 )
break;
V_123 = V_135 ;
}
if ( * V_47 == '%' && * ( V_47 + 1 ) == 'n' ) {
int * V_54 = ( int * ) va_arg ( args , int * ) ;
* V_54 = V_123 - V_9 ;
}
return V_15 ;
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
