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
if ( V_10 < 100 )
goto V_12;
V_11 = ( V_10 * ( V_13 ) 0x28f5c29 ) >> 32 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 - 100 * V_11 ] ;
V_9 += 2 ;
if ( V_11 < 100 )
goto V_16;
V_10 = ( V_11 * ( V_13 ) 0x28f5c29 ) >> 32 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_11 - 100 * V_10 ] ;
V_9 += 2 ;
if ( V_10 < 100 )
goto V_12;
V_11 = ( V_10 * 0x147b ) >> 19 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 - 100 * V_11 ] ;
V_9 += 2 ;
V_16:
V_10 = V_11 ;
V_12:
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 ] ;
V_9 += V_10 < 10 ? 1 : 2 ;
return V_9 ;
}
static T_1
char * F_9 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 ;
V_11 = ( V_10 * ( V_13 ) 0x28f5c29 ) >> 32 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 - 100 * V_11 ] ;
V_9 += 2 ;
V_10 = ( V_11 * ( V_13 ) 0x28f5c29 ) >> 32 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_11 - 100 * V_10 ] ;
V_9 += 2 ;
V_11 = ( V_10 * 0x147b ) >> 19 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 - 100 * V_11 ] ;
V_9 += 2 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_11 ] ;
V_9 += 2 ;
return V_9 ;
}
static T_1
char * F_10 ( char * V_9 , unsigned long long V_17 )
{
if ( V_17 >= 100 * 1000 * 1000 )
V_9 = F_9 ( V_9 , F_11 ( V_17 , 100 * 1000 * 1000 ) ) ;
if ( V_17 >= 100 * 1000 * 1000 )
V_9 = F_9 ( V_9 , F_11 ( V_17 , 100 * 1000 * 1000 ) ) ;
return F_8 ( V_9 , V_17 ) ;
}
static void
F_12 ( char * V_9 , unsigned V_10 )
{
unsigned V_11 ;
V_11 = ( V_10 * 0x147b ) >> 19 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_10 - 100 * V_11 ] ;
V_9 += 2 ;
* ( ( V_14 * ) V_9 ) = V_15 [ V_11 ] ;
}
static T_1
unsigned F_13 ( char * V_9 , unsigned V_18 )
{
T_2 V_11 = ( V_18 * ( V_19 ) 0x346DC5D7 ) >> 43 ;
F_12 ( V_9 , V_18 - V_11 * 10000 ) ;
return V_11 ;
}
static
char * F_10 ( char * V_9 , unsigned long long V_17 )
{
T_2 V_20 , V_21 , V_22 , V_11 , V_23 ;
if ( V_17 < 100 * 1000 * 1000 )
return F_8 ( V_9 , V_17 ) ;
V_22 = ( ( T_2 ) V_17 >> 16 ) ;
V_23 = ( V_17 >> 32 ) ;
V_21 = ( V_23 ) & 0xffff ;
V_20 = ( V_23 >> 16 ) ;
V_11 = 656 * V_20 + 7296 * V_21 + 5536 * V_22 + ( ( T_2 ) V_17 & 0xffff ) ;
V_11 = F_13 ( V_9 , V_11 ) ;
V_11 += 7671 * V_20 + 9496 * V_21 + 6 * V_22 ;
V_11 = F_13 ( V_9 + 4 , V_11 ) ;
V_11 += 4749 * V_20 + 42 * V_21 ;
V_11 = F_13 ( V_9 + 8 , V_11 ) ;
V_11 += 281 * V_20 ;
V_9 += 12 ;
if ( V_11 )
V_9 = F_8 ( V_9 , V_11 ) ;
else while ( V_9 [ - 1 ] == '0' )
-- V_9 ;
return V_9 ;
}
int F_14 ( char * V_9 , int V_24 , unsigned long long V_25 )
{
char V_26 [ sizeof( V_25 ) * 3 ] V_27 ( 2 ) ;
int V_28 , V_29 ;
if ( V_25 <= 9 ) {
V_26 [ 0 ] = '0' + V_25 ;
V_29 = 1 ;
} else {
V_29 = F_10 ( V_26 , V_25 ) - V_26 ;
}
if ( V_29 > V_24 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_29 ; ++ V_28 )
V_9 [ V_28 ] = V_26 [ V_29 - V_28 - 1 ] ;
return V_29 ;
}
static T_1
char * F_15 ( char * V_9 , char * V_30 , unsigned long long V_25 ,
struct V_31 V_32 )
{
char V_26 [ 3 * sizeof( V_25 ) ] V_27 ( 2 ) ;
char V_33 ;
char V_34 ;
int V_35 = ( ( V_32 . V_36 & V_37 ) && V_32 . V_3 != 10 ) ;
int V_8 ;
bool V_38 = V_25 == 0LL ;
V_34 = ( V_32 . V_36 & V_39 ) ;
if ( V_32 . V_36 & V_40 )
V_32 . V_36 &= ~ V_41 ;
V_33 = 0 ;
if ( V_32 . V_36 & V_42 ) {
if ( ( signed long long ) V_25 < 0 ) {
V_33 = '-' ;
V_25 = - ( signed long long ) V_25 ;
V_32 . V_43 -- ;
} else if ( V_32 . V_36 & V_44 ) {
V_33 = '+' ;
V_32 . V_43 -- ;
} else if ( V_32 . V_36 & V_45 ) {
V_33 = ' ' ;
V_32 . V_43 -- ;
}
}
if ( V_35 ) {
if ( V_32 . V_3 == 16 )
V_32 . V_43 -= 2 ;
else if ( ! V_38 )
V_32 . V_43 -- ;
}
V_8 = 0 ;
if ( V_25 < V_32 . V_3 )
V_26 [ V_8 ++ ] = V_46 [ V_25 ] | V_34 ;
else if ( V_32 . V_3 != 10 ) {
int V_47 = V_32 . V_3 - 1 ;
int V_48 = 3 ;
if ( V_32 . V_3 == 16 )
V_48 = 4 ;
do {
V_26 [ V_8 ++ ] = ( V_46 [ ( ( unsigned char ) V_25 ) & V_47 ] | V_34 ) ;
V_25 >>= V_48 ;
} while ( V_25 );
} else {
V_8 = F_10 ( V_26 , V_25 ) - V_26 ;
}
if ( V_8 > V_32 . V_49 )
V_32 . V_49 = V_8 ;
V_32 . V_43 -= V_32 . V_49 ;
if ( ! ( V_32 . V_36 & ( V_41 | V_40 ) ) ) {
while ( -- V_32 . V_43 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
}
if ( V_33 ) {
if ( V_9 < V_30 )
* V_9 = V_33 ;
++ V_9 ;
}
if ( V_35 ) {
if ( V_32 . V_3 == 16 || ! V_38 ) {
if ( V_9 < V_30 )
* V_9 = '0' ;
++ V_9 ;
}
if ( V_32 . V_3 == 16 ) {
if ( V_9 < V_30 )
* V_9 = ( 'X' | V_34 ) ;
++ V_9 ;
}
}
if ( ! ( V_32 . V_36 & V_40 ) ) {
char V_50 = ' ' + ( V_32 . V_36 & V_41 ) ;
F_16 ( ' ' + V_41 != '0' ) ;
while ( -- V_32 . V_43 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = V_50 ;
++ V_9 ;
}
}
while ( V_8 <= -- V_32 . V_49 ) {
if ( V_9 < V_30 )
* V_9 = '0' ;
++ V_9 ;
}
while ( -- V_8 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = V_26 [ V_8 ] ;
++ V_9 ;
}
while ( -- V_32 . V_43 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * string ( char * V_9 , char * V_30 , const char * V_7 , struct V_31 V_32 )
{
int V_29 , V_8 ;
if ( ( unsigned long ) V_7 < V_51 )
V_7 = L_1 ;
V_29 = F_17 ( V_7 , V_32 . V_49 ) ;
if ( ! ( V_32 . V_36 & V_40 ) ) {
while ( V_29 < V_32 . V_43 -- ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
}
for ( V_8 = 0 ; V_8 < V_29 ; ++ V_8 ) {
if ( V_9 < V_30 )
* V_9 = * V_7 ;
++ V_9 ; ++ V_7 ;
}
while ( V_29 < V_32 . V_43 -- ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static void F_18 ( char * V_9 , char * V_30 , unsigned V_29 , unsigned V_52 )
{
T_3 V_24 ;
if ( V_9 >= V_30 )
return;
V_24 = V_30 - V_9 ;
if ( V_24 <= V_52 ) {
memset ( V_9 , ' ' , V_24 ) ;
return;
}
if ( V_29 ) {
if ( V_29 > V_24 - V_52 )
V_29 = V_24 - V_52 ;
memmove ( V_9 + V_52 , V_9 , V_29 ) ;
}
memset ( V_9 , ' ' , V_52 ) ;
}
static T_1
char * F_19 ( char * V_9 , char * V_30 , const struct V_53 * V_54 , struct V_31 V_32 ,
const char * V_55 )
{
const char * V_56 [ 4 ] , * V_7 ;
const struct V_53 * V_57 ;
int V_58 ;
int V_8 , V_17 ;
switch ( V_55 [ 1 ] ) {
case '2' : case '3' : case '4' :
V_58 = V_55 [ 1 ] - '0' ;
break;
default:
V_58 = 1 ;
}
F_20 () ;
for ( V_8 = 0 ; V_8 < V_58 ; V_8 ++ , V_54 = V_57 ) {
V_57 = F_21 ( V_54 -> V_59 ) ;
V_56 [ V_8 ] = F_21 ( V_54 -> V_60 . V_61 ) ;
if ( V_57 == V_54 ) {
if ( V_8 )
V_56 [ V_8 ] = L_2 ;
V_8 ++ ;
break;
}
}
V_7 = V_56 [ -- V_8 ] ;
for ( V_17 = 0 ; V_17 != V_32 . V_49 ; V_17 ++ , V_9 ++ ) {
char V_50 = * V_7 ++ ;
if ( ! V_50 ) {
if ( ! V_8 )
break;
V_50 = '/' ;
V_7 = V_56 [ -- V_8 ] ;
}
if ( V_9 < V_30 )
* V_9 = V_50 ;
}
F_22 () ;
if ( V_17 < V_32 . V_43 ) {
unsigned V_52 = V_32 . V_43 - V_17 ;
if ( ! ( V_32 . V_36 & V_40 ) ) {
F_18 ( V_9 - V_17 , V_30 , V_17 , V_52 ) ;
return V_9 + V_52 ;
}
while ( V_52 -- ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
}
return V_9 ;
}
static T_1
char * F_23 ( char * V_9 , char * V_30 , void * V_62 ,
struct V_31 V_32 , const char * V_55 )
{
unsigned long V_63 ;
#ifdef F_24
char V_64 [ V_65 ] ;
#endif
if ( V_55 [ 1 ] == 'R' )
V_62 = F_25 ( V_62 ) ;
V_63 = ( unsigned long ) V_62 ;
#ifdef F_24
if ( * V_55 == 'B' )
F_26 ( V_64 , V_63 ) ;
else if ( * V_55 != 'f' && * V_55 != 's' )
F_27 ( V_64 , V_63 ) ;
else
F_28 ( V_64 , V_63 ) ;
return string ( V_9 , V_30 , V_64 , V_32 ) ;
#else
V_32 . V_43 = 2 * sizeof( void * ) ;
V_32 . V_36 |= V_37 | V_39 | V_41 ;
V_32 . V_3 = 16 ;
return F_15 ( V_9 , V_30 , V_63 , V_32 ) ;
#endif
}
static T_1
char * F_29 ( char * V_9 , char * V_30 , struct V_66 * V_67 ,
struct V_31 V_32 , const char * V_55 )
{
#ifndef F_30
#define F_30 6
#endif
#ifndef F_31
#define F_31 10
#endif
static const struct V_31 V_68 = {
. V_3 = 16 ,
. V_43 = F_30 ,
. V_49 = - 1 ,
. V_36 = V_37 | V_39 | V_41 ,
} ;
static const struct V_31 V_69 = {
. V_3 = 16 ,
. V_43 = F_31 ,
. V_49 = - 1 ,
. V_36 = V_37 | V_39 | V_41 ,
} ;
static const struct V_31 V_70 = {
. V_3 = 16 ,
. V_43 = 2 ,
. V_49 = - 1 ,
. V_36 = V_39 | V_41 ,
} ;
static const struct V_31 V_71 = {
. V_3 = 10 ,
. V_49 = - 1 ,
. V_36 = 0 ,
} ;
static const struct V_31 V_72 = {
. V_43 = - 1 ,
. V_49 = 10 ,
. V_36 = V_40 ,
} ;
static const struct V_31 V_73 = {
. V_3 = 16 ,
. V_49 = - 1 ,
. V_36 = V_37 | V_39 ,
} ;
#define F_32 ((2 * sizeof(resource_size_t)) + 4)
#define F_33 (2 * sizeof(res->flags))
#define F_34 sizeof("[mem - 64bit pref window disabled]")
#define F_35 sizeof("[mem - flags 0x]")
char V_64 [ F_36 ( 2 * F_32 + F_34 ,
2 * F_32 + F_33 + F_35 ) ] ;
char * V_57 = V_64 , * V_74 = V_64 + sizeof( V_64 ) ;
int V_75 = ( V_55 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_31 * V_76 ;
* V_57 ++ = '[' ;
if ( V_67 -> V_36 & V_77 ) {
V_57 = string ( V_57 , V_74 , L_3 , V_72 ) ;
V_76 = & V_68 ;
} else if ( V_67 -> V_36 & V_78 ) {
V_57 = string ( V_57 , V_74 , L_4 , V_72 ) ;
V_76 = & V_69 ;
} else if ( V_67 -> V_36 & V_79 ) {
V_57 = string ( V_57 , V_74 , L_5 , V_72 ) ;
V_76 = & V_71 ;
} else if ( V_67 -> V_36 & V_80 ) {
V_57 = string ( V_57 , V_74 , L_6 , V_72 ) ;
V_76 = & V_71 ;
} else if ( V_67 -> V_36 & V_81 ) {
V_57 = string ( V_57 , V_74 , L_7 , V_72 ) ;
V_76 = & V_70 ;
} else {
V_57 = string ( V_57 , V_74 , L_8 , V_72 ) ;
V_76 = & V_69 ;
V_75 = 0 ;
}
if ( V_75 && V_67 -> V_36 & V_82 ) {
V_57 = string ( V_57 , V_74 , L_9 , V_72 ) ;
V_57 = F_15 ( V_57 , V_74 , F_37 ( V_67 ) , * V_76 ) ;
} else {
V_57 = F_15 ( V_57 , V_74 , V_67 -> V_83 , * V_76 ) ;
if ( V_67 -> V_83 != V_67 -> V_30 ) {
* V_57 ++ = '-' ;
V_57 = F_15 ( V_57 , V_74 , V_67 -> V_30 , * V_76 ) ;
}
}
if ( V_75 ) {
if ( V_67 -> V_36 & V_84 )
V_57 = string ( V_57 , V_74 , L_10 , V_72 ) ;
if ( V_67 -> V_36 & V_85 )
V_57 = string ( V_57 , V_74 , L_11 , V_72 ) ;
if ( V_67 -> V_36 & V_86 )
V_57 = string ( V_57 , V_74 , L_12 , V_72 ) ;
if ( V_67 -> V_36 & V_87 )
V_57 = string ( V_57 , V_74 , L_13 , V_72 ) ;
} else {
V_57 = string ( V_57 , V_74 , L_14 , V_72 ) ;
V_57 = F_15 ( V_57 , V_74 , V_67 -> V_36 , V_73 ) ;
}
* V_57 ++ = ']' ;
* V_57 = '\0' ;
return string ( V_9 , V_30 , V_64 , V_32 ) ;
}
static T_1
char * F_38 ( char * V_9 , char * V_30 , T_4 * V_88 , struct V_31 V_32 ,
const char * V_55 )
{
int V_8 , V_29 = 1 ;
char V_89 ;
if ( V_32 . V_43 == 0 )
return V_9 ;
if ( F_39 ( V_88 ) )
return string ( V_9 , V_30 , NULL , V_32 ) ;
switch ( V_55 [ 1 ] ) {
case 'C' :
V_89 = ':' ;
break;
case 'D' :
V_89 = '-' ;
break;
case 'N' :
V_89 = 0 ;
break;
default:
V_89 = ' ' ;
break;
}
if ( V_32 . V_43 > 0 )
V_29 = F_40 ( int , V_32 . V_43 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_29 ; ++ V_8 ) {
if ( V_9 < V_30 )
* V_9 = F_41 ( V_88 [ V_8 ] ) ;
++ V_9 ;
if ( V_9 < V_30 )
* V_9 = F_42 ( V_88 [ V_8 ] ) ;
++ V_9 ;
if ( V_89 && V_8 != V_29 - 1 ) {
if ( V_9 < V_30 )
* V_9 = V_89 ;
++ V_9 ;
}
}
return V_9 ;
}
static T_1
char * F_43 ( char * V_9 , char * V_30 , unsigned long * V_90 ,
struct V_31 V_32 , const char * V_55 )
{
const int V_91 = 32 ;
int V_92 = F_44 ( int , V_32 . V_43 , 0 ) ;
int V_8 , V_93 ;
bool V_94 = true ;
V_32 = (struct V_31 ) { . V_36 = V_39 | V_41 , . V_3 = 16 } ;
V_93 = V_92 & ( V_91 - 1 ) ;
if ( V_93 == 0 )
V_93 = V_91 ;
V_8 = F_45 ( V_92 , V_91 ) - V_91 ;
for (; V_8 >= 0 ; V_8 -= V_91 ) {
T_5 V_95 , V_96 ;
int V_97 , V_98 ;
V_95 = ( ( 1ULL << V_93 ) - 1 ) ;
V_97 = V_8 / V_99 ;
V_98 = V_8 % V_99 ;
V_96 = ( V_90 [ V_97 ] >> V_98 ) & V_95 ;
if ( ! V_94 ) {
if ( V_9 < V_30 )
* V_9 = ',' ;
V_9 ++ ;
}
V_94 = false ;
V_32 . V_43 = F_46 ( V_93 , 4 ) ;
V_9 = F_15 ( V_9 , V_30 , V_96 , V_32 ) ;
V_93 = V_91 ;
}
return V_9 ;
}
static T_1
char * F_47 ( char * V_9 , char * V_30 , unsigned long * V_90 ,
struct V_31 V_32 , const char * V_55 )
{
int V_92 = F_44 ( int , V_32 . V_43 , 0 ) ;
int V_100 , V_101 , V_102 ;
bool V_94 = true ;
V_32 = (struct V_31 ) { . V_3 = 10 } ;
V_101 = V_100 = F_48 ( V_90 , V_92 ) ;
while ( V_100 < V_92 ) {
V_102 = V_100 ;
V_100 = F_49 ( V_90 , V_92 , V_100 + 1 ) ;
if ( V_100 < V_92 && V_100 <= V_102 + 1 )
continue;
if ( ! V_94 ) {
if ( V_9 < V_30 )
* V_9 = ',' ;
V_9 ++ ;
}
V_94 = false ;
V_9 = F_15 ( V_9 , V_30 , V_101 , V_32 ) ;
if ( V_101 < V_102 ) {
if ( V_9 < V_30 )
* V_9 = '-' ;
V_9 ++ ;
V_9 = F_15 ( V_9 , V_30 , V_102 , V_32 ) ;
}
V_101 = V_100 ;
}
return V_9 ;
}
static T_1
char * F_50 ( char * V_9 , char * V_30 , T_4 * V_88 ,
struct V_31 V_32 , const char * V_55 )
{
char V_103 [ sizeof( L_15 ) ] ;
char * V_57 = V_103 ;
int V_8 ;
char V_89 ;
bool V_104 = false ;
switch ( V_55 [ 1 ] ) {
case 'F' :
V_89 = '-' ;
break;
case 'R' :
V_104 = true ;
default:
V_89 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_104 )
V_57 = F_51 ( V_57 , V_88 [ 5 - V_8 ] ) ;
else
V_57 = F_51 ( V_57 , V_88 [ V_8 ] ) ;
if ( V_55 [ 0 ] == 'M' && V_8 != 5 )
* V_57 ++ = V_89 ;
}
* V_57 = '\0' ;
return string ( V_9 , V_30 , V_103 , V_32 ) ;
}
static T_1
char * F_52 ( char * V_57 , const T_4 * V_88 , const char * V_55 )
{
int V_8 ;
bool V_105 = ( V_55 [ 0 ] == 'i' ) ;
int V_106 ;
int V_107 ;
switch ( V_55 [ 2 ] ) {
case 'h' :
#ifdef F_53
V_106 = 0 ;
V_107 = 1 ;
#else
V_106 = 3 ;
V_107 = - 1 ;
#endif
break;
case 'l' :
V_106 = 3 ;
V_107 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_106 = 0 ;
V_107 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_108 [ 4 ] V_27 ( 2 ) ;
int V_109 = F_8 ( V_108 , V_88 [ V_106 ] ) - V_108 ;
if ( V_105 ) {
if ( V_109 < 3 )
* V_57 ++ = '0' ;
if ( V_109 < 2 )
* V_57 ++ = '0' ;
}
while ( V_109 -- )
* V_57 ++ = V_108 [ V_109 ] ;
if ( V_8 < 3 )
* V_57 ++ = '.' ;
V_106 += V_107 ;
}
* V_57 = '\0' ;
return V_57 ;
}
static T_1
char * F_54 ( char * V_57 , const char * V_88 )
{
int V_8 , V_110 , V_111 ;
unsigned char V_112 [ 8 ] ;
int V_113 = 1 ;
int V_114 = - 1 ;
V_14 V_97 ;
T_4 V_115 , V_116 ;
bool V_117 = false ;
bool V_118 ;
struct V_119 V_120 ;
memcpy ( & V_120 , V_88 , sizeof( struct V_119 ) ) ;
V_118 = F_55 ( & V_120 ) || F_56 ( & V_120 ) ;
memset ( V_112 , 0 , sizeof( V_112 ) ) ;
if ( V_118 )
V_111 = 6 ;
else
V_111 = 8 ;
for ( V_8 = 0 ; V_8 < V_111 ; V_8 ++ ) {
for ( V_110 = V_8 ; V_110 < V_111 ; V_110 ++ ) {
if ( V_120 . V_121 [ V_110 ] != 0 )
break;
V_112 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_111 ; V_8 ++ ) {
if ( V_112 [ V_8 ] > V_113 ) {
V_113 = V_112 [ V_8 ] ;
V_114 = V_8 ;
}
}
if ( V_113 == 1 )
V_114 = - 1 ;
for ( V_8 = 0 ; V_8 < V_111 ; V_8 ++ ) {
if ( V_8 == V_114 ) {
if ( V_117 || V_8 == 0 )
* V_57 ++ = ':' ;
* V_57 ++ = ':' ;
V_117 = false ;
V_8 += V_113 - 1 ;
continue;
}
if ( V_117 ) {
* V_57 ++ = ':' ;
V_117 = false ;
}
V_97 = F_57 ( V_120 . V_121 [ V_8 ] ) ;
V_115 = V_97 >> 8 ;
V_116 = V_97 & 0xff ;
if ( V_115 ) {
if ( V_115 > 0x0f )
V_57 = F_51 ( V_57 , V_115 ) ;
else
* V_57 ++ = F_42 ( V_115 ) ;
V_57 = F_51 ( V_57 , V_116 ) ;
}
else if ( V_116 > 0x0f )
V_57 = F_51 ( V_57 , V_116 ) ;
else
* V_57 ++ = F_42 ( V_116 ) ;
V_117 = true ;
}
if ( V_118 ) {
if ( V_117 )
* V_57 ++ = ':' ;
V_57 = F_52 ( V_57 , & V_120 . V_122 [ 12 ] , L_16 ) ;
}
* V_57 = '\0' ;
return V_57 ;
}
static T_1
char * F_58 ( char * V_57 , const char * V_88 , const char * V_55 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_57 = F_51 ( V_57 , * V_88 ++ ) ;
V_57 = F_51 ( V_57 , * V_88 ++ ) ;
if ( V_55 [ 0 ] == 'I' && V_8 != 7 )
* V_57 ++ = ':' ;
}
* V_57 = '\0' ;
return V_57 ;
}
static T_1
char * F_59 ( char * V_9 , char * V_30 , const T_4 * V_88 ,
struct V_31 V_32 , const char * V_55 )
{
char V_123 [ sizeof( L_17 ) ] ;
if ( V_55 [ 0 ] == 'I' && V_55 [ 2 ] == 'c' )
F_54 ( V_123 , V_88 ) ;
else
F_58 ( V_123 , V_88 , V_55 ) ;
return string ( V_9 , V_30 , V_123 , V_32 ) ;
}
static T_1
char * F_60 ( char * V_9 , char * V_30 , const T_4 * V_88 ,
struct V_31 V_32 , const char * V_55 )
{
char V_124 [ sizeof( L_18 ) ] ;
F_52 ( V_124 , V_88 , V_55 ) ;
return string ( V_9 , V_30 , V_124 , V_32 ) ;
}
static T_1
char * F_61 ( char * V_9 , char * V_30 , const struct V_125 * V_126 ,
struct V_31 V_32 , const char * V_55 )
{
bool V_127 = false , V_128 = false , V_129 = false , V_130 = false ;
char V_123 [ sizeof( L_19 ) +
sizeof( L_20 ) + sizeof( L_21 ) +
sizeof( L_22 ) ] ;
char * V_57 = V_123 , * V_74 = V_123 + sizeof( V_123 ) ;
const T_4 * V_88 = ( const T_4 * ) & V_126 -> V_131 ;
char V_132 [ 2 ] = { V_55 [ 0 ] , '6' } ;
T_4 V_133 = 0 ;
V_55 ++ ;
while ( isalpha ( * ++ V_55 ) ) {
switch ( * V_55 ) {
case 'p' :
V_127 = true ;
break;
case 'f' :
V_129 = true ;
break;
case 's' :
V_128 = true ;
break;
case 'c' :
V_130 = true ;
break;
}
}
if ( V_127 || V_128 || V_129 ) {
* V_57 = '[' ;
V_133 = 1 ;
}
if ( V_132 [ 0 ] == 'I' && V_130 )
V_57 = F_54 ( V_123 + V_133 , V_88 ) ;
else
V_57 = F_58 ( V_123 + V_133 , V_88 , V_132 ) ;
if ( V_127 || V_128 || V_129 )
* V_57 ++ = ']' ;
if ( V_127 ) {
* V_57 ++ = ':' ;
V_57 = F_15 ( V_57 , V_74 , F_57 ( V_126 -> V_134 ) , V_32 ) ;
}
if ( V_129 ) {
* V_57 ++ = '/' ;
V_57 = F_15 ( V_57 , V_74 , F_62 ( V_126 -> V_135 &
V_136 ) , V_32 ) ;
}
if ( V_128 ) {
* V_57 ++ = '%' ;
V_57 = F_15 ( V_57 , V_74 , V_126 -> V_137 , V_32 ) ;
}
* V_57 = '\0' ;
return string ( V_9 , V_30 , V_123 , V_32 ) ;
}
static T_1
char * F_63 ( char * V_9 , char * V_30 , const struct V_138 * V_126 ,
struct V_31 V_32 , const char * V_55 )
{
bool V_127 = false ;
char * V_57 , V_124 [ sizeof( L_18 ) + sizeof( L_20 ) ] ;
char * V_74 = V_124 + sizeof( V_124 ) ;
const T_4 * V_88 = ( const T_4 * ) & V_126 -> V_139 . V_140 ;
char V_141 [ 3 ] = { V_55 [ 0 ] , '4' , 0 } ;
V_55 ++ ;
while ( isalpha ( * ++ V_55 ) ) {
switch ( * V_55 ) {
case 'p' :
V_127 = true ;
break;
case 'h' :
case 'l' :
case 'n' :
case 'b' :
V_141 [ 2 ] = * V_55 ;
break;
}
}
V_57 = F_52 ( V_124 , V_88 , V_141 ) ;
if ( V_127 ) {
* V_57 ++ = ':' ;
V_57 = F_15 ( V_57 , V_74 , F_57 ( V_126 -> V_142 ) , V_32 ) ;
}
* V_57 = '\0' ;
return string ( V_9 , V_30 , V_124 , V_32 ) ;
}
static T_1
char * F_64 ( char * V_9 , char * V_30 , T_4 * V_88 , struct V_31 V_32 ,
const char * V_55 )
{
bool V_143 = true ;
int V_144 = 1 ;
unsigned int V_36 = 0 ;
int V_29 ;
if ( V_32 . V_43 == 0 )
return V_9 ;
if ( F_39 ( V_88 ) )
return string ( V_9 , V_30 , NULL , V_32 ) ;
do {
switch ( V_55 [ V_144 ++ ] ) {
case 'a' :
V_36 |= V_145 ;
break;
case 'c' :
V_36 |= V_146 ;
break;
case 'h' :
V_36 |= V_147 ;
break;
case 'n' :
V_36 |= V_148 ;
break;
case 'o' :
V_36 |= V_149 ;
break;
case 'p' :
V_36 |= V_150 ;
break;
case 's' :
V_36 |= V_151 ;
break;
default:
V_143 = false ;
break;
}
} while ( V_143 );
if ( ! V_36 )
V_36 = V_152 ;
V_29 = V_32 . V_43 < 0 ? 1 : V_32 . V_43 ;
V_9 += F_65 ( V_88 , V_29 , V_9 , V_9 < V_30 ? V_30 - V_9 : 0 , V_36 , NULL ) ;
return V_9 ;
}
static T_1
char * F_66 ( char * V_9 , char * V_30 , const T_4 * V_88 ,
struct V_31 V_32 , const char * V_55 )
{
char V_153 [ sizeof( L_23 ) ] ;
char * V_57 = V_153 ;
int V_8 ;
static const T_4 V_154 [ 16 ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
static const T_4 V_155 [ 16 ] = { 3 , 2 , 1 , 0 , 5 , 4 , 7 , 6 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 } ;
const T_4 * V_106 = V_154 ;
bool V_156 = false ;
switch ( * ( ++ V_55 ) ) {
case 'L' :
V_156 = true ;
case 'l' :
V_106 = V_155 ;
break;
case 'B' :
V_156 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
V_57 = F_51 ( V_57 , V_88 [ V_106 [ V_8 ] ] ) ;
switch ( V_8 ) {
case 3 :
case 5 :
case 7 :
case 9 :
* V_57 ++ = '-' ;
break;
}
}
* V_57 = 0 ;
if ( V_156 ) {
V_57 = V_153 ;
do {
* V_57 = toupper ( * V_57 ) ;
} while ( * ( ++ V_57 ) );
}
return string ( V_9 , V_30 , V_153 , V_32 ) ;
}
static
char * F_67 ( char * V_9 , char * V_30 , const T_4 * V_88 ,
struct V_31 V_32 )
{
V_32 . V_36 |= V_37 | V_39 | V_41 ;
if ( V_32 . V_43 == - 1 )
V_32 . V_43 = 2 + 2 * sizeof( V_157 ) ;
V_32 . V_3 = 16 ;
return F_15 ( V_9 , V_30 , * ( const V_157 * ) V_88 , V_32 ) ;
}
static T_1
char * F_68 ( char * V_9 , char * V_30 , const void * V_88 ,
struct V_31 V_32 , const char * V_55 )
{
unsigned long long V_25 ;
V_32 . V_36 |= V_37 | V_39 | V_41 ;
V_32 . V_3 = 16 ;
switch ( V_55 [ 1 ] ) {
case 'd' :
V_25 = * ( const V_158 * ) V_88 ;
V_32 . V_43 = sizeof( V_158 ) * 2 + 2 ;
break;
case 'p' :
default:
V_25 = * ( const V_159 * ) V_88 ;
V_32 . V_43 = sizeof( V_159 ) * 2 + 2 ;
break;
}
return F_15 ( V_9 , V_30 , V_25 , V_32 ) ;
}
static T_1
char * clock ( char * V_9 , char * V_30 , struct V_160 * V_160 , struct V_31 V_32 ,
const char * V_55 )
{
if ( ! F_69 ( V_161 ) || ! V_160 )
return string ( V_9 , V_30 , NULL , V_32 ) ;
switch ( V_55 [ 1 ] ) {
case 'r' :
return F_15 ( V_9 , V_30 , F_70 ( V_160 ) , V_32 ) ;
case 'n' :
default:
#ifdef F_71
return string ( V_9 , V_30 , F_72 ( V_160 ) , V_32 ) ;
#else
V_32 . V_3 = 16 ;
V_32 . V_43 = sizeof( unsigned long ) * 2 + 2 ;
V_32 . V_36 |= V_37 | V_39 | V_41 ;
return F_15 ( V_9 , V_30 , ( unsigned long ) V_160 , V_32 ) ;
#endif
}
}
static T_1
char * F_73 ( const char * V_55 , char * V_9 , char * V_30 , void * V_62 ,
struct V_31 V_32 )
{
int V_162 = 2 * sizeof( void * ) + ( V_32 . V_36 & V_37 ? 2 : 0 ) ;
if ( ! V_62 && * V_55 != 'K' ) {
if ( V_32 . V_43 == - 1 )
V_32 . V_43 = V_162 ;
return string ( V_9 , V_30 , L_1 , V_32 ) ;
}
switch ( * V_55 ) {
case 'F' :
case 'f' :
V_62 = F_74 ( V_62 ) ;
case 'S' :
case 's' :
case 'B' :
return F_23 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'R' :
case 'r' :
return F_29 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'h' :
return F_38 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'b' :
switch ( V_55 [ 1 ] ) {
case 'l' :
return F_47 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
default:
return F_43 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
}
case 'M' :
case 'm' :
return F_50 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'I' :
case 'i' :
switch ( V_55 [ 1 ] ) {
case '6' :
return F_59 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case '4' :
return F_60 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'S' : {
const union {
struct V_163 V_164 ;
struct V_138 V_165 ;
struct V_125 V_166 ;
} * V_126 = V_62 ;
switch ( V_126 -> V_164 . V_167 ) {
case V_168 :
return F_63 ( V_9 , V_30 , & V_126 -> V_165 , V_32 , V_55 ) ;
case V_169 :
return F_61 ( V_9 , V_30 , & V_126 -> V_166 , V_32 , V_55 ) ;
default:
return string ( V_9 , V_30 , L_24 , V_32 ) ;
} }
}
break;
case 'E' :
return F_64 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'U' :
return F_66 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'V' :
{
T_6 V_170 ;
F_75 ( V_170 , * ( (struct V_171 * ) V_62 ) -> V_170 ) ;
V_9 += vsnprintf ( V_9 , V_30 > V_9 ? V_30 - V_9 : 0 ,
( (struct V_171 * ) V_62 ) -> V_55 , V_170 ) ;
va_end ( V_170 ) ;
return V_9 ;
}
case 'K' :
if ( V_172 && ( F_76 () || F_77 () ||
F_78 () ) ) {
if ( V_32 . V_43 == - 1 )
V_32 . V_43 = V_162 ;
return string ( V_9 , V_30 , L_25 , V_32 ) ;
}
switch ( V_172 ) {
case 0 :
break;
case 1 : {
const struct V_173 * V_173 = F_79 () ;
if ( ! F_80 ( V_174 , V_175 ) ||
! F_81 ( V_173 -> V_176 , V_173 -> V_177 ) ||
! F_82 ( V_173 -> V_178 , V_173 -> V_179 ) )
V_62 = NULL ;
break;
}
case 2 :
default:
V_62 = NULL ;
break;
}
break;
case 'N' :
switch ( V_55 [ 1 ] ) {
case 'F' :
return F_67 ( V_9 , V_30 , V_62 , V_32 ) ;
}
break;
case 'a' :
return F_68 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'd' :
return F_19 ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'C' :
return clock ( V_9 , V_30 , V_62 , V_32 , V_55 ) ;
case 'D' :
return F_19 ( V_9 , V_30 ,
( ( const struct V_180 * ) V_62 ) -> V_181 . V_53 ,
V_32 , V_55 ) ;
}
V_32 . V_36 |= V_39 ;
if ( V_32 . V_43 == - 1 ) {
V_32 . V_43 = V_162 ;
V_32 . V_36 |= V_41 ;
}
V_32 . V_3 = 16 ;
return F_15 ( V_9 , V_30 , ( unsigned long ) V_62 , V_32 ) ;
}
static T_1
int F_83 ( const char * V_55 , struct V_31 * V_32 )
{
const char * V_83 = V_55 ;
if ( V_32 -> type == V_182 ) {
if ( V_32 -> V_43 < 0 ) {
V_32 -> V_43 = - V_32 -> V_43 ;
V_32 -> V_36 |= V_40 ;
}
V_32 -> type = V_183 ;
goto V_49;
}
if ( V_32 -> type == V_184 ) {
if ( V_32 -> V_49 < 0 )
V_32 -> V_49 = 0 ;
V_32 -> type = V_183 ;
goto V_185;
}
V_32 -> type = V_183 ;
for (; * V_55 ; ++ V_55 ) {
if ( * V_55 == '%' )
break;
}
if ( V_55 != V_83 || ! * V_55 )
return V_55 - V_83 ;
V_32 -> V_36 = 0 ;
while ( 1 ) {
bool V_143 = true ;
++ V_55 ;
switch ( * V_55 ) {
case '-' : V_32 -> V_36 |= V_40 ; break;
case '+' : V_32 -> V_36 |= V_44 ; break;
case ' ' : V_32 -> V_36 |= V_45 ; break;
case '#' : V_32 -> V_36 |= V_37 ; break;
case '0' : V_32 -> V_36 |= V_41 ; break;
default: V_143 = false ;
}
if ( ! V_143 )
break;
}
V_32 -> V_43 = - 1 ;
if ( isdigit ( * V_55 ) )
V_32 -> V_43 = F_7 ( & V_55 ) ;
else if ( * V_55 == '*' ) {
V_32 -> type = V_182 ;
return ++ V_55 - V_83 ;
}
V_49:
V_32 -> V_49 = - 1 ;
if ( * V_55 == '.' ) {
++ V_55 ;
if ( isdigit ( * V_55 ) ) {
V_32 -> V_49 = F_7 ( & V_55 ) ;
if ( V_32 -> V_49 < 0 )
V_32 -> V_49 = 0 ;
} else if ( * V_55 == '*' ) {
V_32 -> type = V_184 ;
return ++ V_55 - V_83 ;
}
}
V_185:
V_32 -> V_185 = - 1 ;
if ( * V_55 == 'h' || F_84 ( * V_55 ) == 'l' ||
F_84 ( * V_55 ) == 'z' || * V_55 == 't' ) {
V_32 -> V_185 = * V_55 ++ ;
if ( F_85 ( V_32 -> V_185 == * V_55 ) ) {
if ( V_32 -> V_185 == 'l' ) {
V_32 -> V_185 = 'L' ;
++ V_55 ;
} else if ( V_32 -> V_185 == 'h' ) {
V_32 -> V_185 = 'H' ;
++ V_55 ;
}
}
}
V_32 -> V_3 = 10 ;
switch ( * V_55 ) {
case 'c' :
V_32 -> type = V_186 ;
return ++ V_55 - V_83 ;
case 's' :
V_32 -> type = V_187 ;
return ++ V_55 - V_83 ;
case 'p' :
V_32 -> type = V_188 ;
return ++ V_55 - V_83 ;
case '%' :
V_32 -> type = V_189 ;
return ++ V_55 - V_83 ;
case 'o' :
V_32 -> V_3 = 8 ;
break;
case 'x' :
V_32 -> V_36 |= V_39 ;
case 'X' :
V_32 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_32 -> V_36 |= V_42 ;
case 'u' :
break;
case 'n' :
F_86 ( 1 , L_26 , V_55 ) ;
default:
V_32 -> type = V_190 ;
return V_55 - V_83 ;
}
if ( V_32 -> V_185 == 'L' )
V_32 -> type = V_191 ;
else if ( V_32 -> V_185 == 'l' ) {
F_16 ( V_192 + V_42 != V_193 ) ;
V_32 -> type = V_192 + ( V_32 -> V_36 & V_42 ) ;
} else if ( F_84 ( V_32 -> V_185 ) == 'z' ) {
V_32 -> type = V_194 ;
} else if ( V_32 -> V_185 == 't' ) {
V_32 -> type = V_195 ;
} else if ( V_32 -> V_185 == 'H' ) {
F_16 ( V_196 + V_42 != V_197 ) ;
V_32 -> type = V_196 + ( V_32 -> V_36 & V_42 ) ;
} else if ( V_32 -> V_185 == 'h' ) {
F_16 ( V_198 + V_42 != V_199 ) ;
V_32 -> type = V_198 + ( V_32 -> V_36 & V_42 ) ;
} else {
F_16 ( V_200 + V_42 != V_201 ) ;
V_32 -> type = V_200 + ( V_32 -> V_36 & V_42 ) ;
}
return ++ V_55 - V_83 ;
}
int vsnprintf ( char * V_9 , T_3 V_24 , const char * V_55 , T_6 args )
{
unsigned long long V_25 ;
char * V_202 , * V_30 ;
struct V_31 V_32 = { 0 } ;
if ( F_87 ( V_24 > V_203 ) )
return 0 ;
V_202 = V_9 ;
V_30 = V_9 + V_24 ;
if ( V_30 < V_9 ) {
V_30 = ( ( void * ) - 1 ) ;
V_24 = V_30 - V_9 ;
}
while ( * V_55 ) {
const char * V_204 = V_55 ;
int V_205 = F_83 ( V_55 , & V_32 ) ;
V_55 += V_205 ;
switch ( V_32 . type ) {
case V_183 : {
int V_206 = V_205 ;
if ( V_202 < V_30 ) {
if ( V_206 > V_30 - V_202 )
V_206 = V_30 - V_202 ;
memcpy ( V_202 , V_204 , V_206 ) ;
}
V_202 += V_205 ;
break;
}
case V_182 :
V_32 . V_43 = va_arg ( args , int ) ;
break;
case V_184 :
V_32 . V_49 = va_arg ( args , int ) ;
break;
case V_186 : {
char V_50 ;
if ( ! ( V_32 . V_36 & V_40 ) ) {
while ( -- V_32 . V_43 > 0 ) {
if ( V_202 < V_30 )
* V_202 = ' ' ;
++ V_202 ;
}
}
V_50 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_202 < V_30 )
* V_202 = V_50 ;
++ V_202 ;
while ( -- V_32 . V_43 > 0 ) {
if ( V_202 < V_30 )
* V_202 = ' ' ;
++ V_202 ;
}
break;
}
case V_187 :
V_202 = string ( V_202 , V_30 , va_arg ( args , char * ) , V_32 ) ;
break;
case V_188 :
V_202 = F_73 ( V_55 , V_202 , V_30 , va_arg ( args , void * ) ,
V_32 ) ;
while ( isalnum ( * V_55 ) )
V_55 ++ ;
break;
case V_189 :
if ( V_202 < V_30 )
* V_202 = '%' ;
++ V_202 ;
break;
case V_190 :
if ( V_202 < V_30 )
* V_202 = '%' ;
++ V_202 ;
break;
default:
switch ( V_32 . type ) {
case V_191 :
V_25 = va_arg (args, long long) ;
break;
case V_192 :
V_25 = va_arg (args, unsigned long) ;
break;
case V_193 :
V_25 = va_arg ( args , long ) ;
break;
case V_194 :
if ( V_32 . V_36 & V_42 )
V_25 = va_arg ( args , V_207 ) ;
else
V_25 = va_arg ( args , T_3 ) ;
break;
case V_195 :
V_25 = va_arg ( args , V_208 ) ;
break;
case V_196 :
V_25 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_197 :
V_25 = ( signed char ) va_arg ( args , int ) ;
break;
case V_198 :
V_25 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_199 :
V_25 = ( short ) va_arg ( args , int ) ;
break;
case V_201 :
V_25 = ( int ) va_arg ( args , int ) ;
break;
default:
V_25 = va_arg (args, unsigned int) ;
}
V_202 = F_15 ( V_202 , V_30 , V_25 , V_32 ) ;
}
}
if ( V_24 > 0 ) {
if ( V_202 < V_30 )
* V_202 = '\0' ;
else
V_30 [ - 1 ] = '\0' ;
}
return V_202 - V_9 ;
}
int F_88 ( char * V_9 , T_3 V_24 , const char * V_55 , T_6 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_24 , V_55 , args ) ;
if ( F_89 ( V_8 < V_24 ) )
return V_8 ;
if ( V_24 != 0 )
return V_24 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_3 V_24 , const char * V_55 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_55 ) ;
V_8 = vsnprintf ( V_9 , V_24 , V_55 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_90 ( char * V_9 , T_3 V_24 , const char * V_55 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_55 ) ;
V_8 = F_88 ( V_9 , V_24 , V_55 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_55 , T_6 args )
{
return vsnprintf ( V_9 , V_203 , V_55 , args ) ;
}
int sprintf ( char * V_9 , const char * V_55 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_55 ) ;
V_8 = vsnprintf ( V_9 , V_203 , V_55 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_91 ( T_5 * V_209 , T_3 V_24 , const char * V_55 , T_6 args )
{
struct V_31 V_32 = { 0 } ;
char * V_202 , * V_30 ;
V_202 = ( char * ) V_209 ;
V_30 = ( char * ) ( V_209 + V_24 ) ;
#define F_92 ( type ) \
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
while ( * V_55 ) {
int V_205 = F_83 ( V_55 , & V_32 ) ;
V_55 += V_205 ;
switch ( V_32 . type ) {
case V_183 :
case V_190 :
case V_189 :
break;
case V_182 :
case V_184 :
F_92 ( int ) ;
break;
case V_186 :
F_92 ( char ) ;
break;
case V_187 : {
const char * V_210 = va_arg ( args , char * ) ;
T_3 V_29 ;
if ( ( unsigned long ) V_210 > ( unsigned long ) - V_51
|| ( unsigned long ) V_210 < V_51 )
V_210 = L_1 ;
V_29 = strlen ( V_210 ) + 1 ;
if ( V_202 + V_29 < V_30 )
memcpy ( V_202 , V_210 , V_29 ) ;
V_202 += V_29 ;
break;
}
case V_188 :
F_92 ( void * ) ;
while ( isalnum ( * V_55 ) )
V_55 ++ ;
break;
default:
switch ( V_32 . type ) {
case V_191 :
F_92 (long long) ;
break;
case V_192 :
case V_193 :
F_92 (unsigned long) ;
break;
case V_194 :
F_92 ( T_3 ) ;
break;
case V_195 :
F_92 ( V_208 ) ;
break;
case V_196 :
case V_197 :
F_92 ( char ) ;
break;
case V_198 :
case V_199 :
F_92 ( short ) ;
break;
default:
F_92 ( int ) ;
}
}
}
return ( T_5 * ) ( F_93 ( V_202 , sizeof( T_5 ) ) ) - V_209 ;
#undef F_92
}
int F_94 ( char * V_9 , T_3 V_24 , const char * V_55 , const T_5 * V_209 )
{
struct V_31 V_32 = { 0 } ;
char * V_202 , * V_30 ;
const char * args = ( const char * ) V_209 ;
if ( F_87 ( ( int ) V_24 < 0 ) )
return 0 ;
V_202 = V_9 ;
V_30 = V_9 + V_24 ;
#define F_95 ( type ) \
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
if ( V_30 < V_9 ) {
V_30 = ( ( void * ) - 1 ) ;
V_24 = V_30 - V_9 ;
}
while ( * V_55 ) {
const char * V_204 = V_55 ;
int V_205 = F_83 ( V_55 , & V_32 ) ;
V_55 += V_205 ;
switch ( V_32 . type ) {
case V_183 : {
int V_206 = V_205 ;
if ( V_202 < V_30 ) {
if ( V_206 > V_30 - V_202 )
V_206 = V_30 - V_202 ;
memcpy ( V_202 , V_204 , V_206 ) ;
}
V_202 += V_205 ;
break;
}
case V_182 :
V_32 . V_43 = F_95 ( int ) ;
break;
case V_184 :
V_32 . V_49 = F_95 ( int ) ;
break;
case V_186 : {
char V_50 ;
if ( ! ( V_32 . V_36 & V_40 ) ) {
while ( -- V_32 . V_43 > 0 ) {
if ( V_202 < V_30 )
* V_202 = ' ' ;
++ V_202 ;
}
}
V_50 = ( unsigned char ) F_95 ( char ) ;
if ( V_202 < V_30 )
* V_202 = V_50 ;
++ V_202 ;
while ( -- V_32 . V_43 > 0 ) {
if ( V_202 < V_30 )
* V_202 = ' ' ;
++ V_202 ;
}
break;
}
case V_187 : {
const char * V_211 = args ;
args += strlen ( V_211 ) + 1 ;
V_202 = string ( V_202 , V_30 , ( char * ) V_211 , V_32 ) ;
break;
}
case V_188 :
V_202 = F_73 ( V_55 , V_202 , V_30 , F_95 ( void * ) , V_32 ) ;
while ( isalnum ( * V_55 ) )
V_55 ++ ;
break;
case V_189 :
case V_190 :
if ( V_202 < V_30 )
* V_202 = '%' ;
++ V_202 ;
break;
default: {
unsigned long long V_25 ;
switch ( V_32 . type ) {
case V_191 :
V_25 = F_95 (long long) ;
break;
case V_192 :
case V_193 :
V_25 = F_95 (unsigned long) ;
break;
case V_194 :
V_25 = F_95 ( T_3 ) ;
break;
case V_195 :
V_25 = F_95 ( V_208 ) ;
break;
case V_196 :
V_25 = F_95 (unsigned char) ;
break;
case V_197 :
V_25 = F_95 (signed char) ;
break;
case V_198 :
V_25 = F_95 (unsigned short) ;
break;
case V_199 :
V_25 = F_95 ( short ) ;
break;
case V_200 :
V_25 = F_95 (unsigned int) ;
break;
default:
V_25 = F_95 ( int ) ;
}
V_202 = F_15 ( V_202 , V_30 , V_25 , V_32 ) ;
}
}
}
if ( V_24 > 0 ) {
if ( V_202 < V_30 )
* V_202 = '\0' ;
else
V_30 [ - 1 ] = '\0' ;
}
#undef F_95
return V_202 - V_9 ;
}
int F_96 ( T_5 * V_209 , T_3 V_24 , const char * V_55 , ... )
{
T_6 args ;
int V_212 ;
va_start ( args , V_55 ) ;
V_212 = F_91 ( V_209 , V_24 , V_55 , args ) ;
va_end ( args ) ;
return V_212 ;
}
int vsscanf ( const char * V_9 , const char * V_55 , T_6 args )
{
const char * V_202 = V_9 ;
char * V_213 ;
char V_214 ;
int V_25 = 0 ;
T_4 V_185 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_215 ;
} V_96 ;
T_7 V_43 ;
bool V_216 ;
while ( * V_55 ) {
if ( isspace ( * V_55 ) ) {
V_55 = F_97 ( ++ V_55 ) ;
V_202 = F_97 ( V_202 ) ;
}
if ( * V_55 != '%' && * V_55 ) {
if ( * V_55 ++ != * V_202 ++ )
break;
continue;
}
if ( ! * V_55 )
break;
++ V_55 ;
if ( * V_55 == '*' ) {
if ( ! * V_202 )
break;
while ( ! isspace ( * V_55 ) && * V_55 != '%' && * V_55 )
V_55 ++ ;
while ( ! isspace ( * V_202 ) && * V_202 )
V_202 ++ ;
continue;
}
V_43 = - 1 ;
if ( isdigit ( * V_55 ) ) {
V_43 = F_7 ( & V_55 ) ;
if ( V_43 <= 0 )
break;
}
V_185 = - 1 ;
if ( * V_55 == 'h' || F_84 ( * V_55 ) == 'l' ||
F_84 ( * V_55 ) == 'z' ) {
V_185 = * V_55 ++ ;
if ( F_85 ( V_185 == * V_55 ) ) {
if ( V_185 == 'h' ) {
V_185 = 'H' ;
V_55 ++ ;
} else if ( V_185 == 'l' ) {
V_185 = 'L' ;
V_55 ++ ;
}
}
}
if ( ! * V_55 )
break;
if ( * V_55 == 'n' ) {
* va_arg ( args , int * ) = V_202 - V_9 ;
++ V_55 ;
continue;
}
if ( ! * V_202 )
break;
V_3 = 10 ;
V_216 = false ;
switch ( * V_55 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_43 == - 1 )
V_43 = 1 ;
do {
* V_7 ++ = * V_202 ++ ;
} while ( -- V_43 > 0 && * V_202 );
V_25 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_43 == - 1 )
V_43 = V_217 ;
V_202 = F_97 ( V_202 ) ;
while ( * V_202 && ! isspace ( * V_202 ) && V_43 -- )
* V_7 ++ = * V_202 ++ ;
* V_7 = '\0' ;
V_25 ++ ;
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
V_216 = true ;
case 'u' :
break;
case '%' :
if ( * V_202 ++ != '%' )
return V_25 ;
continue;
default:
return V_25 ;
}
V_202 = F_97 ( V_202 ) ;
V_214 = * V_202 ;
if ( V_216 && V_214 == '-' )
V_214 = * ( V_202 + 1 ) ;
if ( ! V_214
|| ( V_3 == 16 && ! isxdigit ( V_214 ) )
|| ( V_3 == 10 && ! isdigit ( V_214 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_214 ) || V_214 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_214 ) ) )
break;
if ( V_216 )
V_96 . V_7 = V_185 != 'L' ?
F_5 ( V_202 , & V_213 , V_3 ) :
F_6 ( V_202 , & V_213 , V_3 ) ;
else
V_96 . V_215 = V_185 != 'L' ?
F_4 ( V_202 , & V_213 , V_3 ) :
F_1 ( V_202 , & V_213 , V_3 ) ;
if ( V_43 > 0 && V_213 - V_202 > V_43 ) {
if ( V_3 == 0 )
F_2 ( V_202 , & V_3 ) ;
while ( V_213 - V_202 > V_43 ) {
if ( V_216 )
V_96 . V_7 = F_98 ( V_96 . V_7 , V_3 ) ;
else
V_96 . V_215 = F_99 ( V_96 . V_215 , V_3 ) ;
-- V_213 ;
}
}
switch ( V_185 ) {
case 'H' :
if ( V_216 )
* va_arg (args, signed char *) = V_96 . V_7 ;
else
* va_arg (args, unsigned char *) = V_96 . V_215 ;
break;
case 'h' :
if ( V_216 )
* va_arg ( args , short * ) = V_96 . V_7 ;
else
* va_arg (args, unsigned short *) = V_96 . V_215 ;
break;
case 'l' :
if ( V_216 )
* va_arg ( args , long * ) = V_96 . V_7 ;
else
* va_arg (args, unsigned long *) = V_96 . V_215 ;
break;
case 'L' :
if ( V_216 )
* va_arg (args, long long *) = V_96 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_96 . V_215 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_3 * ) = V_96 . V_215 ;
break;
default:
if ( V_216 )
* va_arg ( args , int * ) = V_96 . V_7 ;
else
* va_arg (args, unsigned int *) = V_96 . V_215 ;
break;
}
V_25 ++ ;
if ( ! V_213 )
break;
V_202 = V_213 ;
}
return V_25 ;
}
int sscanf ( const char * V_9 , const char * V_55 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_55 ) ;
V_8 = vsscanf ( V_9 , V_55 , args ) ;
va_end ( args ) ;
return V_8 ;
}
