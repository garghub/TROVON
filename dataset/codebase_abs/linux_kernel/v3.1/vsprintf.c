static unsigned int F_1 ( const char * V_1 )
{
if ( V_1 [ 0 ] == '0' ) {
if ( F_2 ( V_1 [ 1 ] ) == 'x' && isxdigit ( V_1 [ 2 ] ) )
return 16 ;
else
return 8 ;
} else {
return 10 ;
}
}
unsigned long long F_3 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
unsigned long long V_4 = 0 ;
if ( ! V_3 )
V_3 = F_1 ( V_1 ) ;
if ( V_3 == 16 && V_1 [ 0 ] == '0' && F_2 ( V_1 [ 1 ] ) == 'x' )
V_1 += 2 ;
while ( isxdigit ( * V_1 ) ) {
unsigned int V_5 ;
V_5 = isdigit ( * V_1 ) ? * V_1 - '0' : F_2 ( * V_1 ) - 'a' + 10 ;
if ( V_5 >= V_3 )
break;
V_4 = V_4 * V_3 + V_5 ;
V_1 ++ ;
}
if ( V_2 )
* V_2 = ( char * ) V_1 ;
return V_4 ;
}
unsigned long F_4 ( const char * V_1 , char * * V_2 , unsigned int V_3 )
{
return F_3 ( V_1 , V_2 , V_3 ) ;
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
return - F_3 ( V_1 + 1 , V_2 , V_3 ) ;
return F_3 ( V_1 , V_2 , V_3 ) ;
}
static T_1
int F_7 ( const char * * V_6 )
{
int V_7 = 0 ;
while ( isdigit ( * * V_6 ) )
V_7 = V_7 * 10 + * ( ( * V_6 ) ++ ) - '0' ;
return V_7 ;
}
static T_1
char * F_8 ( char * V_8 , unsigned V_9 )
{
unsigned V_10 , V_11 , V_12 , V_13 ;
V_12 = ( V_9 >> 4 ) & 0xf ;
V_11 = ( V_9 >> 8 ) & 0xf ;
V_10 = ( V_9 >> 12 ) ;
V_13 = 6 * ( V_10 + V_11 + V_12 ) + ( V_9 & 0xf ) ;
V_9 = ( V_13 * 0xcd ) >> 11 ;
V_13 = V_13 - 10 * V_9 ;
* V_8 ++ = V_13 + '0' ;
V_12 = V_9 + 9 * V_10 + 5 * V_11 + V_12 ;
if ( V_12 != 0 ) {
V_9 = ( V_12 * 0xcd ) >> 11 ;
V_12 = V_12 - 10 * V_9 ;
* V_8 ++ = V_12 + '0' ;
V_11 = V_9 + 2 * V_11 ;
if ( ( V_11 != 0 ) || ( V_10 != 0 ) ) {
V_9 = ( V_11 * 0xd ) >> 7 ;
V_11 = V_11 - 10 * V_9 ;
* V_8 ++ = V_11 + '0' ;
V_10 = V_9 + 4 * V_10 ;
if ( V_10 != 0 ) {
V_9 = ( V_10 * 0xcd ) >> 11 ;
V_10 = V_10 - 10 * V_9 ;
* V_8 ++ = V_10 + '0' ;
if ( V_9 != 0 )
* V_8 ++ = V_9 + '0' ;
}
}
}
return V_8 ;
}
static T_1
char * F_9 ( char * V_8 , unsigned V_9 )
{
unsigned V_10 , V_11 , V_12 , V_13 ;
V_12 = ( V_9 >> 4 ) & 0xf ;
V_11 = ( V_9 >> 8 ) & 0xf ;
V_10 = ( V_9 >> 12 ) ;
V_13 = 6 * ( V_10 + V_11 + V_12 ) + ( V_9 & 0xf ) ;
V_9 = ( V_13 * 0xcd ) >> 11 ;
V_13 = V_13 - 10 * V_9 ;
* V_8 ++ = V_13 + '0' ;
V_12 = V_9 + 9 * V_10 + 5 * V_11 + V_12 ;
V_9 = ( V_12 * 0xcd ) >> 11 ;
V_12 = V_12 - 10 * V_9 ;
* V_8 ++ = V_12 + '0' ;
V_11 = V_9 + 2 * V_11 ;
V_9 = ( V_11 * 0xd ) >> 7 ;
V_11 = V_11 - 10 * V_9 ;
* V_8 ++ = V_11 + '0' ;
V_10 = V_9 + 4 * V_10 ;
V_9 = ( V_10 * 0xcd ) >> 11 ;
V_10 = V_10 - 10 * V_9 ;
* V_8 ++ = V_10 + '0' ;
* V_8 ++ = V_9 + '0' ;
return V_8 ;
}
static T_1
char * F_10 ( char * V_8 , unsigned long long V_14 )
{
while ( 1 ) {
unsigned V_15 ;
if ( V_14 < 100000 )
return F_8 ( V_8 , V_14 ) ;
V_15 = F_11 ( V_14 , 100000 ) ;
V_8 = F_9 ( V_8 , V_15 ) ;
}
}
static T_1
char * F_12 ( char * V_8 , char * V_16 , unsigned long long V_14 ,
struct V_17 V_18 )
{
static const char V_19 [ 16 ] = L_1 ;
char V_20 [ 66 ] ;
char V_21 ;
char V_22 ;
int V_23 = ( ( V_18 . V_24 & V_25 ) && V_18 . V_3 != 10 ) ;
int V_7 ;
V_22 = ( V_18 . V_24 & V_26 ) ;
if ( V_18 . V_24 & V_27 )
V_18 . V_24 &= ~ V_28 ;
V_21 = 0 ;
if ( V_18 . V_24 & V_29 ) {
if ( ( signed long long ) V_14 < 0 ) {
V_21 = '-' ;
V_14 = - ( signed long long ) V_14 ;
V_18 . V_30 -- ;
} else if ( V_18 . V_24 & V_31 ) {
V_21 = '+' ;
V_18 . V_30 -- ;
} else if ( V_18 . V_24 & V_32 ) {
V_21 = ' ' ;
V_18 . V_30 -- ;
}
}
if ( V_23 ) {
V_18 . V_30 -- ;
if ( V_18 . V_3 == 16 )
V_18 . V_30 -- ;
}
V_7 = 0 ;
if ( V_14 == 0 )
V_20 [ V_7 ++ ] = '0' ;
else if ( V_18 . V_3 != 10 ) {
int V_33 = V_18 . V_3 - 1 ;
int V_34 = 3 ;
if ( V_18 . V_3 == 16 )
V_34 = 4 ;
do {
V_20 [ V_7 ++ ] = ( V_19 [ ( ( unsigned char ) V_14 ) & V_33 ] | V_22 ) ;
V_14 >>= V_34 ;
} while ( V_14 );
} else {
V_7 = F_10 ( V_20 , V_14 ) - V_20 ;
}
if ( V_7 > V_18 . V_35 )
V_18 . V_35 = V_7 ;
V_18 . V_30 -= V_18 . V_35 ;
if ( ! ( V_18 . V_24 & ( V_28 + V_27 ) ) ) {
while ( -- V_18 . V_30 >= 0 ) {
if ( V_8 < V_16 )
* V_8 = ' ' ;
++ V_8 ;
}
}
if ( V_21 ) {
if ( V_8 < V_16 )
* V_8 = V_21 ;
++ V_8 ;
}
if ( V_23 ) {
if ( V_8 < V_16 )
* V_8 = '0' ;
++ V_8 ;
if ( V_18 . V_3 == 16 ) {
if ( V_8 < V_16 )
* V_8 = ( 'X' | V_22 ) ;
++ V_8 ;
}
}
if ( ! ( V_18 . V_24 & V_27 ) ) {
char V_36 = ( V_18 . V_24 & V_28 ) ? '0' : ' ' ;
while ( -- V_18 . V_30 >= 0 ) {
if ( V_8 < V_16 )
* V_8 = V_36 ;
++ V_8 ;
}
}
while ( V_7 <= -- V_18 . V_35 ) {
if ( V_8 < V_16 )
* V_8 = '0' ;
++ V_8 ;
}
while ( -- V_7 >= 0 ) {
if ( V_8 < V_16 )
* V_8 = V_20 [ V_7 ] ;
++ V_8 ;
}
while ( -- V_18 . V_30 >= 0 ) {
if ( V_8 < V_16 )
* V_8 = ' ' ;
++ V_8 ;
}
return V_8 ;
}
static T_1
char * string ( char * V_8 , char * V_16 , const char * V_6 , struct V_17 V_18 )
{
int V_37 , V_7 ;
if ( ( unsigned long ) V_6 < V_38 )
V_6 = L_2 ;
V_37 = F_13 ( V_6 , V_18 . V_35 ) ;
if ( ! ( V_18 . V_24 & V_27 ) ) {
while ( V_37 < V_18 . V_30 -- ) {
if ( V_8 < V_16 )
* V_8 = ' ' ;
++ V_8 ;
}
}
for ( V_7 = 0 ; V_7 < V_37 ; ++ V_7 ) {
if ( V_8 < V_16 )
* V_8 = * V_6 ;
++ V_8 ; ++ V_6 ;
}
while ( V_37 < V_18 . V_30 -- ) {
if ( V_8 < V_16 )
* V_8 = ' ' ;
++ V_8 ;
}
return V_8 ;
}
static T_1
char * F_14 ( char * V_8 , char * V_16 , void * V_39 ,
struct V_17 V_18 , char V_40 )
{
unsigned long V_5 = ( unsigned long ) V_39 ;
#ifdef F_15
char V_41 [ V_42 ] ;
if ( V_40 == 'B' )
F_16 ( V_41 , V_5 ) ;
else if ( V_40 != 'f' && V_40 != 's' )
F_17 ( V_41 , V_5 ) ;
else
F_18 ( V_5 , NULL , NULL , NULL , V_41 ) ;
return string ( V_8 , V_16 , V_41 , V_18 ) ;
#else
V_18 . V_30 = 2 * sizeof( void * ) ;
V_18 . V_24 |= V_25 | V_26 | V_28 ;
V_18 . V_3 = 16 ;
return F_12 ( V_8 , V_16 , V_5 , V_18 ) ;
#endif
}
static T_1
char * F_19 ( char * V_8 , char * V_16 , struct V_43 * V_44 ,
struct V_17 V_18 , const char * V_45 )
{
#ifndef F_20
#define F_20 6
#endif
#ifndef F_21
#define F_21 10
#endif
static const struct V_17 V_46 = {
. V_3 = 16 ,
. V_30 = F_20 ,
. V_35 = - 1 ,
. V_24 = V_25 | V_26 | V_28 ,
} ;
static const struct V_17 V_47 = {
. V_3 = 16 ,
. V_30 = F_21 ,
. V_35 = - 1 ,
. V_24 = V_25 | V_26 | V_28 ,
} ;
static const struct V_17 V_48 = {
. V_3 = 16 ,
. V_30 = 2 ,
. V_35 = - 1 ,
. V_24 = V_26 | V_28 ,
} ;
static const struct V_17 V_49 = {
. V_3 = 10 ,
. V_35 = - 1 ,
. V_24 = 0 ,
} ;
static const struct V_17 V_50 = {
. V_30 = - 1 ,
. V_35 = 10 ,
. V_24 = V_27 ,
} ;
static const struct V_17 V_51 = {
. V_3 = 16 ,
. V_35 = - 1 ,
. V_24 = V_25 | V_26 ,
} ;
#define F_22 ((2 * sizeof(resource_size_t)) + 4)
#define F_23 (2 * sizeof(res->flags))
#define F_24 sizeof("[mem - 64bit pref window disabled]")
#define F_25 sizeof("[mem - flags 0x]")
char V_41 [ F_26 ( 2 * F_22 + F_24 ,
2 * F_22 + F_23 + F_25 ) ] ;
char * V_52 = V_41 , * V_53 = V_41 + sizeof( V_41 ) ;
int V_54 = ( V_45 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_17 * V_55 ;
* V_52 ++ = '[' ;
if ( V_44 -> V_24 & V_56 ) {
V_52 = string ( V_52 , V_53 , L_3 , V_50 ) ;
V_55 = & V_46 ;
} else if ( V_44 -> V_24 & V_57 ) {
V_52 = string ( V_52 , V_53 , L_4 , V_50 ) ;
V_55 = & V_47 ;
} else if ( V_44 -> V_24 & V_58 ) {
V_52 = string ( V_52 , V_53 , L_5 , V_50 ) ;
V_55 = & V_49 ;
} else if ( V_44 -> V_24 & V_59 ) {
V_52 = string ( V_52 , V_53 , L_6 , V_50 ) ;
V_55 = & V_49 ;
} else if ( V_44 -> V_24 & V_60 ) {
V_52 = string ( V_52 , V_53 , L_7 , V_50 ) ;
V_55 = & V_48 ;
} else {
V_52 = string ( V_52 , V_53 , L_8 , V_50 ) ;
V_55 = & V_47 ;
V_54 = 0 ;
}
V_52 = F_12 ( V_52 , V_53 , V_44 -> V_61 , * V_55 ) ;
if ( V_44 -> V_61 != V_44 -> V_16 ) {
* V_52 ++ = '-' ;
V_52 = F_12 ( V_52 , V_53 , V_44 -> V_16 , * V_55 ) ;
}
if ( V_54 ) {
if ( V_44 -> V_24 & V_62 )
V_52 = string ( V_52 , V_53 , L_9 , V_50 ) ;
if ( V_44 -> V_24 & V_63 )
V_52 = string ( V_52 , V_53 , L_10 , V_50 ) ;
if ( V_44 -> V_24 & V_64 )
V_52 = string ( V_52 , V_53 , L_11 , V_50 ) ;
if ( V_44 -> V_24 & V_65 )
V_52 = string ( V_52 , V_53 , L_12 , V_50 ) ;
} else {
V_52 = string ( V_52 , V_53 , L_13 , V_50 ) ;
V_52 = F_12 ( V_52 , V_53 , V_44 -> V_24 , V_51 ) ;
}
* V_52 ++ = ']' ;
* V_52 = '\0' ;
return string ( V_8 , V_16 , V_41 , V_18 ) ;
}
static T_1
char * F_27 ( char * V_8 , char * V_16 , T_2 * V_66 ,
struct V_17 V_18 , const char * V_45 )
{
char V_67 [ sizeof( L_14 ) ] ;
char * V_52 = V_67 ;
int V_7 ;
char V_68 ;
if ( V_45 [ 1 ] == 'F' ) {
V_68 = '-' ;
} else {
V_68 = ':' ;
}
for ( V_7 = 0 ; V_7 < 6 ; V_7 ++ ) {
V_52 = F_28 ( V_52 , V_66 [ V_7 ] ) ;
if ( V_45 [ 0 ] == 'M' && V_7 != 5 )
* V_52 ++ = V_68 ;
}
* V_52 = '\0' ;
return string ( V_8 , V_16 , V_67 , V_18 ) ;
}
static T_1
char * F_29 ( char * V_52 , const T_2 * V_66 , const char * V_45 )
{
int V_7 ;
bool V_69 = ( V_45 [ 0 ] == 'i' ) ;
int V_70 ;
int V_71 ;
switch ( V_45 [ 2 ] ) {
case 'h' :
#ifdef F_30
V_70 = 0 ;
V_71 = 1 ;
#else
V_70 = 3 ;
V_71 = - 1 ;
#endif
break;
case 'l' :
V_70 = 3 ;
V_71 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_70 = 0 ;
V_71 = 1 ;
break;
}
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
char V_72 [ 3 ] ;
int V_19 = F_8 ( V_72 , V_66 [ V_70 ] ) - V_72 ;
if ( V_69 ) {
if ( V_19 < 3 )
* V_52 ++ = '0' ;
if ( V_19 < 2 )
* V_52 ++ = '0' ;
}
while ( V_19 -- )
* V_52 ++ = V_72 [ V_19 ] ;
if ( V_7 < 3 )
* V_52 ++ = '.' ;
V_70 += V_71 ;
}
* V_52 = '\0' ;
return V_52 ;
}
static T_1
char * F_31 ( char * V_52 , const char * V_66 )
{
int V_7 , V_73 , V_74 ;
unsigned char V_75 [ 8 ] ;
int V_76 = 1 ;
int V_77 = - 1 ;
T_3 V_78 ;
T_2 V_79 , V_80 ;
bool V_81 = false ;
bool V_82 ;
struct V_83 V_84 ;
memcpy ( & V_84 , V_66 , sizeof( struct V_83 ) ) ;
V_82 = F_32 ( & V_84 ) || F_33 ( & V_84 ) ;
memset ( V_75 , 0 , sizeof( V_75 ) ) ;
if ( V_82 )
V_74 = 6 ;
else
V_74 = 8 ;
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ ) {
for ( V_73 = V_7 ; V_73 < V_74 ; V_73 ++ ) {
if ( V_84 . V_85 [ V_73 ] != 0 )
break;
V_75 [ V_7 ] ++ ;
}
}
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ ) {
if ( V_75 [ V_7 ] > V_76 ) {
V_76 = V_75 [ V_7 ] ;
V_77 = V_7 ;
}
}
if ( V_76 == 1 )
V_77 = - 1 ;
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ ) {
if ( V_7 == V_77 ) {
if ( V_81 || V_7 == 0 )
* V_52 ++ = ':' ;
* V_52 ++ = ':' ;
V_81 = false ;
V_7 += V_76 - 1 ;
continue;
}
if ( V_81 ) {
* V_52 ++ = ':' ;
V_81 = false ;
}
V_78 = F_34 ( V_84 . V_85 [ V_7 ] ) ;
V_79 = V_78 >> 8 ;
V_80 = V_78 & 0xff ;
if ( V_79 ) {
if ( V_79 > 0x0f )
V_52 = F_28 ( V_52 , V_79 ) ;
else
* V_52 ++ = F_35 ( V_79 ) ;
V_52 = F_28 ( V_52 , V_80 ) ;
}
else if ( V_80 > 0x0f )
V_52 = F_28 ( V_52 , V_80 ) ;
else
* V_52 ++ = F_35 ( V_80 ) ;
V_81 = true ;
}
if ( V_82 ) {
if ( V_81 )
* V_52 ++ = ':' ;
V_52 = F_29 ( V_52 , & V_84 . V_86 [ 12 ] , L_15 ) ;
}
* V_52 = '\0' ;
return V_52 ;
}
static T_1
char * F_36 ( char * V_52 , const char * V_66 , const char * V_45 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
V_52 = F_28 ( V_52 , * V_66 ++ ) ;
V_52 = F_28 ( V_52 , * V_66 ++ ) ;
if ( V_45 [ 0 ] == 'I' && V_7 != 7 )
* V_52 ++ = ':' ;
}
* V_52 = '\0' ;
return V_52 ;
}
static T_1
char * F_37 ( char * V_8 , char * V_16 , const T_2 * V_66 ,
struct V_17 V_18 , const char * V_45 )
{
char V_87 [ sizeof( L_16 ) ] ;
if ( V_45 [ 0 ] == 'I' && V_45 [ 2 ] == 'c' )
F_31 ( V_87 , V_66 ) ;
else
F_36 ( V_87 , V_66 , V_45 ) ;
return string ( V_8 , V_16 , V_87 , V_18 ) ;
}
static T_1
char * F_38 ( char * V_8 , char * V_16 , const T_2 * V_66 ,
struct V_17 V_18 , const char * V_45 )
{
char V_88 [ sizeof( L_17 ) ] ;
F_29 ( V_88 , V_66 , V_45 ) ;
return string ( V_8 , V_16 , V_88 , V_18 ) ;
}
static T_1
char * F_39 ( char * V_8 , char * V_16 , const T_2 * V_66 ,
struct V_17 V_18 , const char * V_45 )
{
char V_89 [ sizeof( L_18 ) ] ;
char * V_52 = V_89 ;
int V_7 ;
static const T_2 V_90 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_2 V_91 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_2 * V_70 = V_90 ;
bool V_92 = false ;
switch ( * ( ++ V_45 ) ) {
case 'L' :
V_92 = true ;
case 'l' :
V_70 = V_91 ;
break;
case 'B' :
V_92 = true ;
break;
}
for ( V_7 = 0 ; V_7 < 16 ; V_7 ++ ) {
V_52 = F_28 ( V_52 , V_66 [ V_70 [ V_7 ] ] ) ;
switch ( V_7 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_52 ++ = '-' ;
break;
}
}
* V_52 = 0 ;
if ( V_92 ) {
V_52 = V_89 ;
do {
* V_52 = toupper ( * V_52 ) ;
} while ( * ( ++ V_52 ) );
}
return string ( V_8 , V_16 , V_89 , V_18 ) ;
}
static T_1
char * F_40 ( const char * V_45 , char * V_8 , char * V_16 , void * V_39 ,
struct V_17 V_18 )
{
if ( ! V_39 && * V_45 != 'K' ) {
if ( V_18 . V_30 == - 1 )
V_18 . V_30 = 2 * sizeof( void * ) ;
return string ( V_8 , V_16 , L_2 , V_18 ) ;
}
switch ( * V_45 ) {
case 'F' :
case 'f' :
V_39 = F_41 ( V_39 ) ;
case 'S' :
case 's' :
case 'B' :
return F_14 ( V_8 , V_16 , V_39 , V_18 , * V_45 ) ;
case 'R' :
case 'r' :
return F_19 ( V_8 , V_16 , V_39 , V_18 , V_45 ) ;
case 'M' :
case 'm' :
return F_27 ( V_8 , V_16 , V_39 , V_18 , V_45 ) ;
case 'I' :
case 'i' :
switch ( V_45 [ 1 ] ) {
case '6' :
return F_37 ( V_8 , V_16 , V_39 , V_18 , V_45 ) ;
case '4' :
return F_38 ( V_8 , V_16 , V_39 , V_18 , V_45 ) ;
}
break;
case 'U' :
return F_39 ( V_8 , V_16 , V_39 , V_18 , V_45 ) ;
case 'V' :
return V_8 + vsnprintf ( V_8 , V_16 > V_8 ? V_16 - V_8 : 0 ,
( (struct V_93 * ) V_39 ) -> V_45 ,
* ( ( (struct V_93 * ) V_39 ) -> V_94 ) ) ;
case 'K' :
if ( F_42 () || F_43 () || F_44 () ) {
if ( V_18 . V_30 == - 1 )
V_18 . V_30 = 2 * sizeof( void * ) ;
return string ( V_8 , V_16 , L_19 , V_18 ) ;
}
if ( ! ( ( V_95 == 0 ) ||
( V_95 == 1 &&
F_45 ( V_96 , V_97 ) ) ) )
V_39 = NULL ;
break;
}
V_18 . V_24 |= V_26 ;
if ( V_18 . V_30 == - 1 ) {
V_18 . V_30 = 2 * sizeof( void * ) ;
V_18 . V_24 |= V_28 ;
}
V_18 . V_3 = 16 ;
return F_12 ( V_8 , V_16 , ( unsigned long ) V_39 , V_18 ) ;
}
static T_1
int F_46 ( const char * V_45 , struct V_17 * V_18 )
{
const char * V_61 = V_45 ;
if ( V_18 -> type == V_98 ) {
if ( V_18 -> V_30 < 0 ) {
V_18 -> V_30 = - V_18 -> V_30 ;
V_18 -> V_24 |= V_27 ;
}
V_18 -> type = V_99 ;
goto V_35;
}
if ( V_18 -> type == V_100 ) {
if ( V_18 -> V_35 < 0 )
V_18 -> V_35 = 0 ;
V_18 -> type = V_99 ;
goto V_101;
}
V_18 -> type = V_99 ;
for (; * V_45 ; ++ V_45 ) {
if ( * V_45 == '%' )
break;
}
if ( V_45 != V_61 || ! * V_45 )
return V_45 - V_61 ;
V_18 -> V_24 = 0 ;
while ( 1 ) {
bool V_102 = true ;
++ V_45 ;
switch ( * V_45 ) {
case '-' : V_18 -> V_24 |= V_27 ; break;
case '+' : V_18 -> V_24 |= V_31 ; break;
case ' ' : V_18 -> V_24 |= V_32 ; break;
case '#' : V_18 -> V_24 |= V_25 ; break;
case '0' : V_18 -> V_24 |= V_28 ; break;
default: V_102 = false ;
}
if ( ! V_102 )
break;
}
V_18 -> V_30 = - 1 ;
if ( isdigit ( * V_45 ) )
V_18 -> V_30 = F_7 ( & V_45 ) ;
else if ( * V_45 == '*' ) {
V_18 -> type = V_98 ;
return ++ V_45 - V_61 ;
}
V_35:
V_18 -> V_35 = - 1 ;
if ( * V_45 == '.' ) {
++ V_45 ;
if ( isdigit ( * V_45 ) ) {
V_18 -> V_35 = F_7 ( & V_45 ) ;
if ( V_18 -> V_35 < 0 )
V_18 -> V_35 = 0 ;
} else if ( * V_45 == '*' ) {
V_18 -> type = V_100 ;
return ++ V_45 - V_61 ;
}
}
V_101:
V_18 -> V_101 = - 1 ;
if ( * V_45 == 'h' || F_2 ( * V_45 ) == 'l' ||
F_2 ( * V_45 ) == 'z' || * V_45 == 't' ) {
V_18 -> V_101 = * V_45 ++ ;
if ( F_47 ( V_18 -> V_101 == * V_45 ) ) {
if ( V_18 -> V_101 == 'l' ) {
V_18 -> V_101 = 'L' ;
++ V_45 ;
} else if ( V_18 -> V_101 == 'h' ) {
V_18 -> V_101 = 'H' ;
++ V_45 ;
}
}
}
V_18 -> V_3 = 10 ;
switch ( * V_45 ) {
case 'c' :
V_18 -> type = V_103 ;
return ++ V_45 - V_61 ;
case 's' :
V_18 -> type = V_104 ;
return ++ V_45 - V_61 ;
case 'p' :
V_18 -> type = V_105 ;
return V_45 - V_61 ;
case 'n' :
V_18 -> type = V_106 ;
return ++ V_45 - V_61 ;
case '%' :
V_18 -> type = V_107 ;
return ++ V_45 - V_61 ;
case 'o' :
V_18 -> V_3 = 8 ;
break;
case 'x' :
V_18 -> V_24 |= V_26 ;
case 'X' :
V_18 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_18 -> V_24 |= V_29 ;
case 'u' :
break;
default:
V_18 -> type = V_108 ;
return V_45 - V_61 ;
}
if ( V_18 -> V_101 == 'L' )
V_18 -> type = V_109 ;
else if ( V_18 -> V_101 == 'l' ) {
if ( V_18 -> V_24 & V_29 )
V_18 -> type = V_110 ;
else
V_18 -> type = V_111 ;
} else if ( F_2 ( V_18 -> V_101 ) == 'z' ) {
V_18 -> type = V_112 ;
} else if ( V_18 -> V_101 == 't' ) {
V_18 -> type = V_113 ;
} else if ( V_18 -> V_101 == 'H' ) {
if ( V_18 -> V_24 & V_29 )
V_18 -> type = V_114 ;
else
V_18 -> type = V_115 ;
} else if ( V_18 -> V_101 == 'h' ) {
if ( V_18 -> V_24 & V_29 )
V_18 -> type = V_116 ;
else
V_18 -> type = V_117 ;
} else {
if ( V_18 -> V_24 & V_29 )
V_18 -> type = V_118 ;
else
V_18 -> type = V_119 ;
}
return ++ V_45 - V_61 ;
}
int vsnprintf ( char * V_8 , T_4 V_120 , const char * V_45 , T_5 args )
{
unsigned long long V_14 ;
char * V_121 , * V_16 ;
struct V_17 V_18 = { 0 } ;
if ( F_48 ( ( int ) V_120 < 0 ) )
return 0 ;
V_121 = V_8 ;
V_16 = V_8 + V_120 ;
if ( V_16 < V_8 ) {
V_16 = ( ( void * ) - 1 ) ;
V_120 = V_16 - V_8 ;
}
while ( * V_45 ) {
const char * V_122 = V_45 ;
int V_123 = F_46 ( V_45 , & V_18 ) ;
V_45 += V_123 ;
switch ( V_18 . type ) {
case V_99 : {
int V_124 = V_123 ;
if ( V_121 < V_16 ) {
if ( V_124 > V_16 - V_121 )
V_124 = V_16 - V_121 ;
memcpy ( V_121 , V_122 , V_124 ) ;
}
V_121 += V_123 ;
break;
}
case V_98 :
V_18 . V_30 = va_arg ( args , int ) ;
break;
case V_100 :
V_18 . V_35 = va_arg ( args , int ) ;
break;
case V_103 : {
char V_36 ;
if ( ! ( V_18 . V_24 & V_27 ) ) {
while ( -- V_18 . V_30 > 0 ) {
if ( V_121 < V_16 )
* V_121 = ' ' ;
++ V_121 ;
}
}
V_36 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_121 < V_16 )
* V_121 = V_36 ;
++ V_121 ;
while ( -- V_18 . V_30 > 0 ) {
if ( V_121 < V_16 )
* V_121 = ' ' ;
++ V_121 ;
}
break;
}
case V_104 :
V_121 = string ( V_121 , V_16 , va_arg ( args , char * ) , V_18 ) ;
break;
case V_105 :
V_121 = F_40 ( V_45 + 1 , V_121 , V_16 , va_arg ( args , void * ) ,
V_18 ) ;
while ( isalnum ( * V_45 ) )
V_45 ++ ;
break;
case V_107 :
if ( V_121 < V_16 )
* V_121 = '%' ;
++ V_121 ;
break;
case V_108 :
if ( V_121 < V_16 )
* V_121 = '%' ;
++ V_121 ;
break;
case V_106 : {
T_2 V_101 = V_18 . V_101 ;
if ( V_101 == 'l' ) {
long * V_125 = va_arg ( args , long * ) ;
* V_125 = ( V_121 - V_8 ) ;
} else if ( F_2 ( V_101 ) == 'z' ) {
T_4 * V_125 = va_arg ( args , T_4 * ) ;
* V_125 = ( V_121 - V_8 ) ;
} else {
int * V_125 = va_arg ( args , int * ) ;
* V_125 = ( V_121 - V_8 ) ;
}
break;
}
default:
switch ( V_18 . type ) {
case V_109 :
V_14 = va_arg (args, long long) ;
break;
case V_111 :
V_14 = va_arg (args, unsigned long) ;
break;
case V_110 :
V_14 = va_arg ( args , long ) ;
break;
case V_112 :
V_14 = va_arg ( args , T_4 ) ;
break;
case V_113 :
V_14 = va_arg ( args , V_126 ) ;
break;
case V_115 :
V_14 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_114 :
V_14 = ( signed char ) va_arg ( args , int ) ;
break;
case V_117 :
V_14 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_116 :
V_14 = ( short ) va_arg ( args , int ) ;
break;
case V_118 :
V_14 = ( int ) va_arg ( args , int ) ;
break;
default:
V_14 = va_arg (args, unsigned int) ;
}
V_121 = F_12 ( V_121 , V_16 , V_14 , V_18 ) ;
}
}
if ( V_120 > 0 ) {
if ( V_121 < V_16 )
* V_121 = '\0' ;
else
V_16 [ - 1 ] = '\0' ;
}
return V_121 - V_8 ;
}
int F_49 ( char * V_8 , T_4 V_120 , const char * V_45 , T_5 args )
{
int V_7 ;
V_7 = vsnprintf ( V_8 , V_120 , V_45 , args ) ;
if ( F_50 ( V_7 < V_120 ) )
return V_7 ;
if ( V_120 != 0 )
return V_120 - 1 ;
return 0 ;
}
int snprintf ( char * V_8 , T_4 V_120 , const char * V_45 , ... )
{
T_5 args ;
int V_7 ;
va_start ( args , V_45 ) ;
V_7 = vsnprintf ( V_8 , V_120 , V_45 , args ) ;
va_end ( args ) ;
return V_7 ;
}
int F_51 ( char * V_8 , T_4 V_120 , const char * V_45 , ... )
{
T_5 args ;
int V_7 ;
va_start ( args , V_45 ) ;
V_7 = F_49 ( V_8 , V_120 , V_45 , args ) ;
va_end ( args ) ;
return V_7 ;
}
int vsprintf ( char * V_8 , const char * V_45 , T_5 args )
{
return vsnprintf ( V_8 , V_127 , V_45 , args ) ;
}
int sprintf ( char * V_8 , const char * V_45 , ... )
{
T_5 args ;
int V_7 ;
va_start ( args , V_45 ) ;
V_7 = vsnprintf ( V_8 , V_127 , V_45 , args ) ;
va_end ( args ) ;
return V_7 ;
}
int F_52 ( T_6 * V_128 , T_4 V_120 , const char * V_45 , T_5 args )
{
struct V_17 V_18 = { 0 } ;
char * V_121 , * V_16 ;
V_121 = ( char * ) V_128 ;
V_16 = ( char * ) ( V_128 + V_120 ) ;
#define F_53 ( type ) \
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
while ( * V_45 ) {
int V_123 = F_46 ( V_45 , & V_18 ) ;
V_45 += V_123 ;
switch ( V_18 . type ) {
case V_99 :
case V_108 :
case V_107 :
break;
case V_98 :
case V_100 :
F_53 ( int ) ;
break;
case V_103 :
F_53 ( char ) ;
break;
case V_104 : {
const char * V_129 = va_arg ( args , char * ) ;
T_4 V_37 ;
if ( ( unsigned long ) V_129 > ( unsigned long ) - V_38
|| ( unsigned long ) V_129 < V_38 )
V_129 = L_2 ;
V_37 = strlen ( V_129 ) + 1 ;
if ( V_121 + V_37 < V_16 )
memcpy ( V_121 , V_129 , V_37 ) ;
V_121 += V_37 ;
break;
}
case V_105 :
F_53 ( void * ) ;
while ( isalnum ( * V_45 ) )
V_45 ++ ;
break;
case V_106 : {
T_2 V_101 = V_18 . V_101 ;
void * V_130 ;
if ( V_101 == 'l' )
V_130 = va_arg ( args , long * ) ;
else if ( F_2 ( V_101 ) == 'z' )
V_130 = va_arg ( args , T_4 * ) ;
else
V_130 = va_arg ( args , int * ) ;
break;
}
default:
switch ( V_18 . type ) {
case V_109 :
F_53 (long long) ;
break;
case V_111 :
case V_110 :
F_53 (unsigned long) ;
break;
case V_112 :
F_53 ( T_4 ) ;
break;
case V_113 :
F_53 ( V_126 ) ;
break;
case V_115 :
case V_114 :
F_53 ( char ) ;
break;
case V_117 :
case V_116 :
F_53 ( short ) ;
break;
default:
F_53 ( int ) ;
}
}
}
return ( T_6 * ) ( F_54 ( V_121 , sizeof( T_6 ) ) ) - V_128 ;
#undef F_53
}
int F_55 ( char * V_8 , T_4 V_120 , const char * V_45 , const T_6 * V_128 )
{
struct V_17 V_18 = { 0 } ;
char * V_121 , * V_16 ;
const char * args = ( const char * ) V_128 ;
if ( F_48 ( ( int ) V_120 < 0 ) )
return 0 ;
V_121 = V_8 ;
V_16 = V_8 + V_120 ;
#define F_56 ( type ) \
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
if ( V_16 < V_8 ) {
V_16 = ( ( void * ) - 1 ) ;
V_120 = V_16 - V_8 ;
}
while ( * V_45 ) {
const char * V_122 = V_45 ;
int V_123 = F_46 ( V_45 , & V_18 ) ;
V_45 += V_123 ;
switch ( V_18 . type ) {
case V_99 : {
int V_124 = V_123 ;
if ( V_121 < V_16 ) {
if ( V_124 > V_16 - V_121 )
V_124 = V_16 - V_121 ;
memcpy ( V_121 , V_122 , V_124 ) ;
}
V_121 += V_123 ;
break;
}
case V_98 :
V_18 . V_30 = F_56 ( int ) ;
break;
case V_100 :
V_18 . V_35 = F_56 ( int ) ;
break;
case V_103 : {
char V_36 ;
if ( ! ( V_18 . V_24 & V_27 ) ) {
while ( -- V_18 . V_30 > 0 ) {
if ( V_121 < V_16 )
* V_121 = ' ' ;
++ V_121 ;
}
}
V_36 = ( unsigned char ) F_56 ( char ) ;
if ( V_121 < V_16 )
* V_121 = V_36 ;
++ V_121 ;
while ( -- V_18 . V_30 > 0 ) {
if ( V_121 < V_16 )
* V_121 = ' ' ;
++ V_121 ;
}
break;
}
case V_104 : {
const char * V_131 = args ;
args += strlen ( V_131 ) + 1 ;
V_121 = string ( V_121 , V_16 , ( char * ) V_131 , V_18 ) ;
break;
}
case V_105 :
V_121 = F_40 ( V_45 + 1 , V_121 , V_16 , F_56 ( void * ) , V_18 ) ;
while ( isalnum ( * V_45 ) )
V_45 ++ ;
break;
case V_107 :
case V_108 :
if ( V_121 < V_16 )
* V_121 = '%' ;
++ V_121 ;
break;
case V_106 :
break;
default: {
unsigned long long V_14 ;
switch ( V_18 . type ) {
case V_109 :
V_14 = F_56 (long long) ;
break;
case V_111 :
case V_110 :
V_14 = F_56 (unsigned long) ;
break;
case V_112 :
V_14 = F_56 ( T_4 ) ;
break;
case V_113 :
V_14 = F_56 ( V_126 ) ;
break;
case V_115 :
V_14 = F_56 (unsigned char) ;
break;
case V_114 :
V_14 = F_56 (signed char) ;
break;
case V_117 :
V_14 = F_56 (unsigned short) ;
break;
case V_116 :
V_14 = F_56 ( short ) ;
break;
case V_119 :
V_14 = F_56 (unsigned int) ;
break;
default:
V_14 = F_56 ( int ) ;
}
V_121 = F_12 ( V_121 , V_16 , V_14 , V_18 ) ;
}
}
}
if ( V_120 > 0 ) {
if ( V_121 < V_16 )
* V_121 = '\0' ;
else
V_16 [ - 1 ] = '\0' ;
}
#undef F_56
return V_121 - V_8 ;
}
int F_57 ( T_6 * V_128 , T_4 V_120 , const char * V_45 , ... )
{
T_5 args ;
int V_132 ;
va_start ( args , V_45 ) ;
V_132 = F_52 ( V_128 , V_120 , V_45 , args ) ;
va_end ( args ) ;
return V_132 ;
}
int vsscanf ( const char * V_8 , const char * V_45 , T_5 args )
{
const char * V_121 = V_8 ;
char * V_133 ;
char V_134 ;
int V_14 = 0 ;
T_2 V_101 ;
T_2 V_3 ;
T_7 V_30 ;
bool V_135 ;
while ( * V_45 && * V_121 ) {
if ( isspace ( * V_45 ) ) {
V_45 = F_58 ( ++ V_45 ) ;
V_121 = F_58 ( V_121 ) ;
}
if ( * V_45 != '%' && * V_45 ) {
if ( * V_45 ++ != * V_121 ++ )
break;
continue;
}
if ( ! * V_45 )
break;
++ V_45 ;
if ( * V_45 == '*' ) {
while ( ! isspace ( * V_45 ) && * V_45 != '%' && * V_45 )
V_45 ++ ;
while ( ! isspace ( * V_121 ) && * V_121 )
V_121 ++ ;
continue;
}
V_30 = - 1 ;
if ( isdigit ( * V_45 ) )
V_30 = F_7 ( & V_45 ) ;
V_101 = - 1 ;
if ( * V_45 == 'h' || F_2 ( * V_45 ) == 'l' ||
F_2 ( * V_45 ) == 'z' ) {
V_101 = * V_45 ++ ;
if ( F_47 ( V_101 == * V_45 ) ) {
if ( V_101 == 'h' ) {
V_101 = 'H' ;
V_45 ++ ;
} else if ( V_101 == 'l' ) {
V_101 = 'L' ;
V_45 ++ ;
}
}
}
if ( ! * V_45 || ! * V_121 )
break;
V_3 = 10 ;
V_135 = 0 ;
switch ( * V_45 ++ ) {
case 'c' :
{
char * V_6 = ( char * ) va_arg ( args , char * ) ;
if ( V_30 == - 1 )
V_30 = 1 ;
do {
* V_6 ++ = * V_121 ++ ;
} while ( -- V_30 > 0 && * V_121 );
V_14 ++ ;
}
continue;
case 's' :
{
char * V_6 = ( char * ) va_arg ( args , char * ) ;
if ( V_30 == - 1 )
V_30 = V_136 ;
V_121 = F_58 ( V_121 ) ;
while ( * V_121 && ! isspace ( * V_121 ) && V_30 -- )
* V_6 ++ = * V_121 ++ ;
* V_6 = '\0' ;
V_14 ++ ;
}
continue;
case 'n' :
{
int * V_7 = ( int * ) va_arg ( args , int * ) ;
* V_7 = V_121 - V_8 ;
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
V_135 = 1 ;
case 'u' :
break;
case '%' :
if ( * V_121 ++ != '%' )
return V_14 ;
continue;
default:
return V_14 ;
}
V_121 = F_58 ( V_121 ) ;
V_134 = * V_121 ;
if ( V_135 && V_134 == '-' )
V_134 = * ( V_121 + 1 ) ;
if ( ! V_134
|| ( V_3 == 16 && ! isxdigit ( V_134 ) )
|| ( V_3 == 10 && ! isdigit ( V_134 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_134 ) || V_134 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_134 ) ) )
break;
switch ( V_101 ) {
case 'H' :
if ( V_135 ) {
signed char * V_6 = ( signed char * ) va_arg (args, signed char *) ;
* V_6 = ( signed char ) F_5 ( V_121 , & V_133 , V_3 ) ;
} else {
unsigned char * V_6 = ( unsigned char * ) va_arg (args, unsigned char *) ;
* V_6 = ( unsigned char ) F_4 ( V_121 , & V_133 , V_3 ) ;
}
break;
case 'h' :
if ( V_135 ) {
short * V_6 = ( short * ) va_arg ( args , short * ) ;
* V_6 = ( short ) F_5 ( V_121 , & V_133 , V_3 ) ;
} else {
unsigned short * V_6 = ( unsigned short * ) va_arg (args, unsigned short *) ;
* V_6 = ( unsigned short ) F_4 ( V_121 , & V_133 , V_3 ) ;
}
break;
case 'l' :
if ( V_135 ) {
long * V_137 = ( long * ) va_arg ( args , long * ) ;
* V_137 = F_5 ( V_121 , & V_133 , V_3 ) ;
} else {
unsigned long * V_137 = ( unsigned long * ) va_arg (args, unsigned long *) ;
* V_137 = F_4 ( V_121 , & V_133 , V_3 ) ;
}
break;
case 'L' :
if ( V_135 ) {
long long * V_137 = ( long long * ) va_arg (args, long long *) ;
* V_137 = F_6 ( V_121 , & V_133 , V_3 ) ;
} else {
unsigned long long * V_137 = ( unsigned long long * ) va_arg (args, unsigned long long *) ;
* V_137 = F_3 ( V_121 , & V_133 , V_3 ) ;
}
break;
case 'Z' :
case 'z' :
{
T_4 * V_6 = ( T_4 * ) va_arg ( args , T_4 * ) ;
* V_6 = ( T_4 ) F_4 ( V_121 , & V_133 , V_3 ) ;
}
break;
default:
if ( V_135 ) {
int * V_7 = ( int * ) va_arg ( args , int * ) ;
* V_7 = ( int ) F_5 ( V_121 , & V_133 , V_3 ) ;
} else {
unsigned int * V_7 = ( unsigned int * ) va_arg (args, unsigned int*) ;
* V_7 = ( unsigned int ) F_4 ( V_121 , & V_133 , V_3 ) ;
}
break;
}
V_14 ++ ;
if ( ! V_133 )
break;
V_121 = V_133 ;
}
if ( * V_45 == '%' && * ( V_45 + 1 ) == 'n' ) {
int * V_52 = ( int * ) va_arg ( args , int * ) ;
* V_52 = V_121 - V_8 ;
}
return V_14 ;
}
int sscanf ( const char * V_8 , const char * V_45 , ... )
{
T_5 args ;
int V_7 ;
va_start ( args , V_45 ) ;
V_7 = vsscanf ( V_8 , V_45 , args ) ;
va_end ( args ) ;
return V_7 ;
}
