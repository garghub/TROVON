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
int V_39 = V_32 . V_39 ;
int V_40 = V_32 . V_40 ;
F_16 ( sizeof( struct V_31 ) != 8 ) ;
V_34 = ( V_32 . V_36 & V_41 ) ;
if ( V_32 . V_36 & V_42 )
V_32 . V_36 &= ~ V_43 ;
V_33 = 0 ;
if ( V_32 . V_36 & V_44 ) {
if ( ( signed long long ) V_25 < 0 ) {
V_33 = '-' ;
V_25 = - ( signed long long ) V_25 ;
V_39 -- ;
} else if ( V_32 . V_36 & V_45 ) {
V_33 = '+' ;
V_39 -- ;
} else if ( V_32 . V_36 & V_46 ) {
V_33 = ' ' ;
V_39 -- ;
}
}
if ( V_35 ) {
if ( V_32 . V_3 == 16 )
V_39 -= 2 ;
else if ( ! V_38 )
V_39 -- ;
}
V_8 = 0 ;
if ( V_25 < V_32 . V_3 )
V_26 [ V_8 ++ ] = V_47 [ V_25 ] | V_34 ;
else if ( V_32 . V_3 != 10 ) {
int V_48 = V_32 . V_3 - 1 ;
int V_49 = 3 ;
if ( V_32 . V_3 == 16 )
V_49 = 4 ;
do {
V_26 [ V_8 ++ ] = ( V_47 [ ( ( unsigned char ) V_25 ) & V_48 ] | V_34 ) ;
V_25 >>= V_49 ;
} while ( V_25 );
} else {
V_8 = F_10 ( V_26 , V_25 ) - V_26 ;
}
if ( V_8 > V_40 )
V_40 = V_8 ;
V_39 -= V_40 ;
if ( ! ( V_32 . V_36 & ( V_43 | V_42 ) ) ) {
while ( -- V_39 >= 0 ) {
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
if ( ! ( V_32 . V_36 & V_42 ) ) {
char V_50 = ' ' + ( V_32 . V_36 & V_43 ) ;
F_16 ( ' ' + V_43 != '0' ) ;
while ( -- V_39 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = V_50 ;
++ V_9 ;
}
}
while ( V_8 <= -- V_40 ) {
if ( V_9 < V_30 )
* V_9 = '0' ;
++ V_9 ;
}
while ( -- V_8 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = V_26 [ V_8 ] ;
++ V_9 ;
}
while ( -- V_39 >= 0 ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * F_17 ( char * V_9 , char * V_30 , unsigned long long V_25 , int V_24 )
{
struct V_31 V_32 ;
V_32 . type = V_51 ;
V_32 . V_39 = 2 + 2 * V_24 ;
V_32 . V_36 = V_37 | V_41 | V_43 ;
V_32 . V_3 = 16 ;
V_32 . V_40 = - 1 ;
return F_15 ( V_9 , V_30 , V_25 , V_32 ) ;
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
char * F_19 ( char * V_9 , int V_17 , char * V_30 , struct V_31 V_32 )
{
unsigned V_52 ;
if ( F_20 ( V_17 >= V_32 . V_39 ) )
return V_9 ;
V_52 = V_32 . V_39 - V_17 ;
if ( ! ( V_32 . V_36 & V_42 ) ) {
F_18 ( V_9 - V_17 , V_30 , V_17 , V_52 ) ;
return V_9 + V_52 ;
}
while ( V_52 -- ) {
if ( V_9 < V_30 )
* V_9 = ' ' ;
++ V_9 ;
}
return V_9 ;
}
static T_1
char * string ( char * V_9 , char * V_30 , const char * V_7 , struct V_31 V_32 )
{
int V_29 = 0 ;
T_3 V_53 = V_32 . V_40 ;
if ( ( unsigned long ) V_7 < V_54 )
V_7 = L_1 ;
while ( V_53 -- ) {
char V_50 = * V_7 ++ ;
if ( ! V_50 )
break;
if ( V_9 < V_30 )
* V_9 = V_50 ;
++ V_9 ;
++ V_29 ;
}
return F_19 ( V_9 , V_29 , V_30 , V_32 ) ;
}
static T_1
char * F_21 ( char * V_9 , char * V_30 , const struct V_55 * V_56 , struct V_31 V_32 ,
const char * V_57 )
{
const char * V_58 [ 4 ] , * V_7 ;
const struct V_55 * V_59 ;
int V_60 ;
int V_8 , V_17 ;
switch ( V_57 [ 1 ] ) {
case '2' : case '3' : case '4' :
V_60 = V_57 [ 1 ] - '0' ;
break;
default:
V_60 = 1 ;
}
F_22 () ;
for ( V_8 = 0 ; V_8 < V_60 ; V_8 ++ , V_56 = V_59 ) {
V_59 = F_23 ( V_56 -> V_61 ) ;
V_58 [ V_8 ] = F_23 ( V_56 -> V_62 . V_63 ) ;
if ( V_59 == V_56 ) {
if ( V_8 )
V_58 [ V_8 ] = L_2 ;
V_8 ++ ;
break;
}
}
V_7 = V_58 [ -- V_8 ] ;
for ( V_17 = 0 ; V_17 != V_32 . V_40 ; V_17 ++ , V_9 ++ ) {
char V_50 = * V_7 ++ ;
if ( ! V_50 ) {
if ( ! V_8 )
break;
V_50 = '/' ;
V_7 = V_58 [ -- V_8 ] ;
}
if ( V_9 < V_30 )
* V_9 = V_50 ;
}
F_24 () ;
return F_19 ( V_9 , V_17 , V_30 , V_32 ) ;
}
static T_1
char * F_25 ( char * V_9 , char * V_30 , struct V_64 * V_65 ,
struct V_31 V_32 , const char * V_57 )
{
struct V_66 * V_67 = V_65 -> V_68 ;
V_9 = string ( V_9 , V_30 , V_67 -> V_69 , V_32 ) ;
if ( V_65 -> V_70 -> V_71 ) {
if ( isdigit ( V_67 -> V_69 [ strlen ( V_67 -> V_69 ) - 1 ] ) ) {
if ( V_9 < V_30 )
* V_9 = 'p' ;
V_9 ++ ;
}
V_9 = F_15 ( V_9 , V_30 , V_65 -> V_70 -> V_71 , V_32 ) ;
}
return V_9 ;
}
static T_1
char * F_26 ( char * V_9 , char * V_30 , void * V_72 ,
struct V_31 V_32 , const char * V_57 )
{
unsigned long V_73 ;
#ifdef F_27
char V_74 [ V_75 ] ;
#endif
if ( V_57 [ 1 ] == 'R' )
V_72 = F_28 ( V_72 ) ;
V_73 = ( unsigned long ) V_72 ;
#ifdef F_27
if ( * V_57 == 'B' )
F_29 ( V_74 , V_73 ) ;
else if ( * V_57 != 'f' && * V_57 != 's' )
F_30 ( V_74 , V_73 ) ;
else
F_31 ( V_74 , V_73 ) ;
return string ( V_9 , V_30 , V_74 , V_32 ) ;
#else
return F_17 ( V_9 , V_30 , V_73 , sizeof( void * ) ) ;
#endif
}
static T_1
char * F_32 ( char * V_9 , char * V_30 , struct V_76 * V_77 ,
struct V_31 V_32 , const char * V_57 )
{
#ifndef F_33
#define F_33 6
#endif
#ifndef F_34
#define F_34 10
#endif
static const struct V_31 V_78 = {
. V_3 = 16 ,
. V_39 = F_33 ,
. V_40 = - 1 ,
. V_36 = V_37 | V_41 | V_43 ,
} ;
static const struct V_31 V_79 = {
. V_3 = 16 ,
. V_39 = F_34 ,
. V_40 = - 1 ,
. V_36 = V_37 | V_41 | V_43 ,
} ;
static const struct V_31 V_80 = {
. V_3 = 16 ,
. V_39 = 2 ,
. V_40 = - 1 ,
. V_36 = V_41 | V_43 ,
} ;
static const struct V_31 V_81 = {
. V_3 = 10 ,
. V_40 = - 1 ,
. V_36 = 0 ,
} ;
static const struct V_31 V_82 = {
. V_39 = - 1 ,
. V_40 = 10 ,
. V_36 = V_42 ,
} ;
static const struct V_31 V_83 = {
. V_3 = 16 ,
. V_40 = - 1 ,
. V_36 = V_37 | V_41 ,
} ;
#define F_35 ((2 * sizeof(resource_size_t)) + 4)
#define F_36 (2 * sizeof(res->flags))
#define F_37 sizeof("[mem - 64bit pref window disabled]")
#define F_38 sizeof("[mem - flags 0x]")
char V_74 [ F_39 ( 2 * F_35 + F_37 ,
2 * F_35 + F_36 + F_38 ) ] ;
char * V_59 = V_74 , * V_84 = V_74 + sizeof( V_74 ) ;
int V_85 = ( V_57 [ 0 ] == 'R' ) ? 1 : 0 ;
const struct V_31 * V_86 ;
* V_59 ++ = '[' ;
if ( V_77 -> V_36 & V_87 ) {
V_59 = string ( V_59 , V_84 , L_3 , V_82 ) ;
V_86 = & V_78 ;
} else if ( V_77 -> V_36 & V_88 ) {
V_59 = string ( V_59 , V_84 , L_4 , V_82 ) ;
V_86 = & V_79 ;
} else if ( V_77 -> V_36 & V_89 ) {
V_59 = string ( V_59 , V_84 , L_5 , V_82 ) ;
V_86 = & V_81 ;
} else if ( V_77 -> V_36 & V_90 ) {
V_59 = string ( V_59 , V_84 , L_6 , V_82 ) ;
V_86 = & V_81 ;
} else if ( V_77 -> V_36 & V_91 ) {
V_59 = string ( V_59 , V_84 , L_7 , V_82 ) ;
V_86 = & V_80 ;
} else {
V_59 = string ( V_59 , V_84 , L_8 , V_82 ) ;
V_86 = & V_79 ;
V_85 = 0 ;
}
if ( V_85 && V_77 -> V_36 & V_92 ) {
V_59 = string ( V_59 , V_84 , L_9 , V_82 ) ;
V_59 = F_15 ( V_59 , V_84 , F_40 ( V_77 ) , * V_86 ) ;
} else {
V_59 = F_15 ( V_59 , V_84 , V_77 -> V_93 , * V_86 ) ;
if ( V_77 -> V_93 != V_77 -> V_30 ) {
* V_59 ++ = '-' ;
V_59 = F_15 ( V_59 , V_84 , V_77 -> V_30 , * V_86 ) ;
}
}
if ( V_85 ) {
if ( V_77 -> V_36 & V_94 )
V_59 = string ( V_59 , V_84 , L_10 , V_82 ) ;
if ( V_77 -> V_36 & V_95 )
V_59 = string ( V_59 , V_84 , L_11 , V_82 ) ;
if ( V_77 -> V_36 & V_96 )
V_59 = string ( V_59 , V_84 , L_12 , V_82 ) ;
if ( V_77 -> V_36 & V_97 )
V_59 = string ( V_59 , V_84 , L_13 , V_82 ) ;
} else {
V_59 = string ( V_59 , V_84 , L_14 , V_82 ) ;
V_59 = F_15 ( V_59 , V_84 , V_77 -> V_36 , V_83 ) ;
}
* V_59 ++ = ']' ;
* V_59 = '\0' ;
return string ( V_9 , V_30 , V_74 , V_32 ) ;
}
static T_1
char * F_41 ( char * V_9 , char * V_30 , T_4 * V_98 , struct V_31 V_32 ,
const char * V_57 )
{
int V_8 , V_29 = 1 ;
char V_99 ;
if ( V_32 . V_39 == 0 )
return V_9 ;
if ( F_42 ( V_98 ) )
return string ( V_9 , V_30 , NULL , V_32 ) ;
switch ( V_57 [ 1 ] ) {
case 'C' :
V_99 = ':' ;
break;
case 'D' :
V_99 = '-' ;
break;
case 'N' :
V_99 = 0 ;
break;
default:
V_99 = ' ' ;
break;
}
if ( V_32 . V_39 > 0 )
V_29 = F_43 ( int , V_32 . V_39 , 64 ) ;
for ( V_8 = 0 ; V_8 < V_29 ; ++ V_8 ) {
if ( V_9 < V_30 )
* V_9 = F_44 ( V_98 [ V_8 ] ) ;
++ V_9 ;
if ( V_9 < V_30 )
* V_9 = F_45 ( V_98 [ V_8 ] ) ;
++ V_9 ;
if ( V_99 && V_8 != V_29 - 1 ) {
if ( V_9 < V_30 )
* V_9 = V_99 ;
++ V_9 ;
}
}
return V_9 ;
}
static T_1
char * F_46 ( char * V_9 , char * V_30 , unsigned long * V_100 ,
struct V_31 V_32 , const char * V_57 )
{
const int V_101 = 32 ;
int V_102 = F_47 ( int , V_32 . V_39 , 0 ) ;
int V_8 , V_103 ;
bool V_104 = true ;
V_32 = (struct V_31 ) { . V_36 = V_41 | V_43 , . V_3 = 16 } ;
V_103 = V_102 & ( V_101 - 1 ) ;
if ( V_103 == 0 )
V_103 = V_101 ;
V_8 = F_48 ( V_102 , V_101 ) - V_101 ;
for (; V_8 >= 0 ; V_8 -= V_101 ) {
T_5 V_105 , V_106 ;
int V_107 , V_108 ;
V_105 = ( ( 1ULL << V_103 ) - 1 ) ;
V_107 = V_8 / V_109 ;
V_108 = V_8 % V_109 ;
V_106 = ( V_100 [ V_107 ] >> V_108 ) & V_105 ;
if ( ! V_104 ) {
if ( V_9 < V_30 )
* V_9 = ',' ;
V_9 ++ ;
}
V_104 = false ;
V_32 . V_39 = F_49 ( V_103 , 4 ) ;
V_9 = F_15 ( V_9 , V_30 , V_106 , V_32 ) ;
V_103 = V_101 ;
}
return V_9 ;
}
static T_1
char * F_50 ( char * V_9 , char * V_30 , unsigned long * V_100 ,
struct V_31 V_32 , const char * V_57 )
{
int V_102 = F_47 ( int , V_32 . V_39 , 0 ) ;
int V_110 , V_111 , V_112 ;
bool V_104 = true ;
V_32 = (struct V_31 ) { . V_3 = 10 } ;
V_111 = V_110 = F_51 ( V_100 , V_102 ) ;
while ( V_110 < V_102 ) {
V_112 = V_110 ;
V_110 = F_52 ( V_100 , V_102 , V_110 + 1 ) ;
if ( V_110 < V_102 && V_110 <= V_112 + 1 )
continue;
if ( ! V_104 ) {
if ( V_9 < V_30 )
* V_9 = ',' ;
V_9 ++ ;
}
V_104 = false ;
V_9 = F_15 ( V_9 , V_30 , V_111 , V_32 ) ;
if ( V_111 < V_112 ) {
if ( V_9 < V_30 )
* V_9 = '-' ;
V_9 ++ ;
V_9 = F_15 ( V_9 , V_30 , V_112 , V_32 ) ;
}
V_111 = V_110 ;
}
return V_9 ;
}
static T_1
char * F_53 ( char * V_9 , char * V_30 , T_4 * V_98 ,
struct V_31 V_32 , const char * V_57 )
{
char V_113 [ sizeof( L_15 ) ] ;
char * V_59 = V_113 ;
int V_8 ;
char V_99 ;
bool V_114 = false ;
switch ( V_57 [ 1 ] ) {
case 'F' :
V_99 = '-' ;
break;
case 'R' :
V_114 = true ;
default:
V_99 = ':' ;
break;
}
for ( V_8 = 0 ; V_8 < 6 ; V_8 ++ ) {
if ( V_114 )
V_59 = F_54 ( V_59 , V_98 [ 5 - V_8 ] ) ;
else
V_59 = F_54 ( V_59 , V_98 [ V_8 ] ) ;
if ( V_57 [ 0 ] == 'M' && V_8 != 5 )
* V_59 ++ = V_99 ;
}
* V_59 = '\0' ;
return string ( V_9 , V_30 , V_113 , V_32 ) ;
}
static T_1
char * F_55 ( char * V_59 , const T_4 * V_98 , const char * V_57 )
{
int V_8 ;
bool V_115 = ( V_57 [ 0 ] == 'i' ) ;
int V_116 ;
int V_117 ;
switch ( V_57 [ 2 ] ) {
case 'h' :
#ifdef F_56
V_116 = 0 ;
V_117 = 1 ;
#else
V_116 = 3 ;
V_117 = - 1 ;
#endif
break;
case 'l' :
V_116 = 3 ;
V_117 = - 1 ;
break;
case 'n' :
case 'b' :
default:
V_116 = 0 ;
V_117 = 1 ;
break;
}
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ ) {
char V_118 [ 4 ] V_27 ( 2 ) ;
int V_119 = F_8 ( V_118 , V_98 [ V_116 ] ) - V_118 ;
if ( V_115 ) {
if ( V_119 < 3 )
* V_59 ++ = '0' ;
if ( V_119 < 2 )
* V_59 ++ = '0' ;
}
while ( V_119 -- )
* V_59 ++ = V_118 [ V_119 ] ;
if ( V_8 < 3 )
* V_59 ++ = '.' ;
V_116 += V_117 ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_57 ( char * V_59 , const char * V_98 )
{
int V_8 , V_120 , V_121 ;
unsigned char V_122 [ 8 ] ;
int V_123 = 1 ;
int V_124 = - 1 ;
V_14 V_107 ;
T_4 V_125 , V_126 ;
bool V_127 = false ;
bool V_128 ;
struct V_129 V_130 ;
memcpy ( & V_130 , V_98 , sizeof( struct V_129 ) ) ;
V_128 = F_58 ( & V_130 ) || F_59 ( & V_130 ) ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
if ( V_128 )
V_121 = 6 ;
else
V_121 = 8 ;
for ( V_8 = 0 ; V_8 < V_121 ; V_8 ++ ) {
for ( V_120 = V_8 ; V_120 < V_121 ; V_120 ++ ) {
if ( V_130 . V_131 [ V_120 ] != 0 )
break;
V_122 [ V_8 ] ++ ;
}
}
for ( V_8 = 0 ; V_8 < V_121 ; V_8 ++ ) {
if ( V_122 [ V_8 ] > V_123 ) {
V_123 = V_122 [ V_8 ] ;
V_124 = V_8 ;
}
}
if ( V_123 == 1 )
V_124 = - 1 ;
for ( V_8 = 0 ; V_8 < V_121 ; V_8 ++ ) {
if ( V_8 == V_124 ) {
if ( V_127 || V_8 == 0 )
* V_59 ++ = ':' ;
* V_59 ++ = ':' ;
V_127 = false ;
V_8 += V_123 - 1 ;
continue;
}
if ( V_127 ) {
* V_59 ++ = ':' ;
V_127 = false ;
}
V_107 = F_60 ( V_130 . V_131 [ V_8 ] ) ;
V_125 = V_107 >> 8 ;
V_126 = V_107 & 0xff ;
if ( V_125 ) {
if ( V_125 > 0x0f )
V_59 = F_54 ( V_59 , V_125 ) ;
else
* V_59 ++ = F_45 ( V_125 ) ;
V_59 = F_54 ( V_59 , V_126 ) ;
}
else if ( V_126 > 0x0f )
V_59 = F_54 ( V_59 , V_126 ) ;
else
* V_59 ++ = F_45 ( V_126 ) ;
V_127 = true ;
}
if ( V_128 ) {
if ( V_127 )
* V_59 ++ = ':' ;
V_59 = F_55 ( V_59 , & V_130 . V_132 [ 12 ] , L_16 ) ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_61 ( char * V_59 , const char * V_98 , const char * V_57 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ ) {
V_59 = F_54 ( V_59 , * V_98 ++ ) ;
V_59 = F_54 ( V_59 , * V_98 ++ ) ;
if ( V_57 [ 0 ] == 'I' && V_8 != 7 )
* V_59 ++ = ':' ;
}
* V_59 = '\0' ;
return V_59 ;
}
static T_1
char * F_62 ( char * V_9 , char * V_30 , const T_4 * V_98 ,
struct V_31 V_32 , const char * V_57 )
{
char V_133 [ sizeof( L_17 ) ] ;
if ( V_57 [ 0 ] == 'I' && V_57 [ 2 ] == 'c' )
F_57 ( V_133 , V_98 ) ;
else
F_61 ( V_133 , V_98 , V_57 ) ;
return string ( V_9 , V_30 , V_133 , V_32 ) ;
}
static T_1
char * F_63 ( char * V_9 , char * V_30 , const T_4 * V_98 ,
struct V_31 V_32 , const char * V_57 )
{
char V_134 [ sizeof( L_18 ) ] ;
F_55 ( V_134 , V_98 , V_57 ) ;
return string ( V_9 , V_30 , V_134 , V_32 ) ;
}
static T_1
char * F_64 ( char * V_9 , char * V_30 , const struct V_135 * V_136 ,
struct V_31 V_32 , const char * V_57 )
{
bool V_137 = false , V_138 = false , V_139 = false , V_140 = false ;
char V_133 [ sizeof( L_19 ) +
sizeof( L_20 ) + sizeof( L_21 ) +
sizeof( L_22 ) ] ;
char * V_59 = V_133 , * V_84 = V_133 + sizeof( V_133 ) ;
const T_4 * V_98 = ( const T_4 * ) & V_136 -> V_141 ;
char V_142 [ 2 ] = { V_57 [ 0 ] , '6' } ;
T_4 V_143 = 0 ;
V_57 ++ ;
while ( isalpha ( * ++ V_57 ) ) {
switch ( * V_57 ) {
case 'p' :
V_137 = true ;
break;
case 'f' :
V_139 = true ;
break;
case 's' :
V_138 = true ;
break;
case 'c' :
V_140 = true ;
break;
}
}
if ( V_137 || V_138 || V_139 ) {
* V_59 = '[' ;
V_143 = 1 ;
}
if ( V_142 [ 0 ] == 'I' && V_140 )
V_59 = F_57 ( V_133 + V_143 , V_98 ) ;
else
V_59 = F_61 ( V_133 + V_143 , V_98 , V_142 ) ;
if ( V_137 || V_138 || V_139 )
* V_59 ++ = ']' ;
if ( V_137 ) {
* V_59 ++ = ':' ;
V_59 = F_15 ( V_59 , V_84 , F_60 ( V_136 -> V_144 ) , V_32 ) ;
}
if ( V_139 ) {
* V_59 ++ = '/' ;
V_59 = F_15 ( V_59 , V_84 , F_65 ( V_136 -> V_145 &
V_146 ) , V_32 ) ;
}
if ( V_138 ) {
* V_59 ++ = '%' ;
V_59 = F_15 ( V_59 , V_84 , V_136 -> V_147 , V_32 ) ;
}
* V_59 = '\0' ;
return string ( V_9 , V_30 , V_133 , V_32 ) ;
}
static T_1
char * F_66 ( char * V_9 , char * V_30 , const struct V_148 * V_136 ,
struct V_31 V_32 , const char * V_57 )
{
bool V_137 = false ;
char * V_59 , V_134 [ sizeof( L_18 ) + sizeof( L_20 ) ] ;
char * V_84 = V_134 + sizeof( V_134 ) ;
const T_4 * V_98 = ( const T_4 * ) & V_136 -> V_149 . V_150 ;
char V_151 [ 3 ] = { V_57 [ 0 ] , '4' , 0 } ;
V_57 ++ ;
while ( isalpha ( * ++ V_57 ) ) {
switch ( * V_57 ) {
case 'p' :
V_137 = true ;
break;
case 'h' :
case 'l' :
case 'n' :
case 'b' :
V_151 [ 2 ] = * V_57 ;
break;
}
}
V_59 = F_55 ( V_134 , V_98 , V_151 ) ;
if ( V_137 ) {
* V_59 ++ = ':' ;
V_59 = F_15 ( V_59 , V_84 , F_60 ( V_136 -> V_152 ) , V_32 ) ;
}
* V_59 = '\0' ;
return string ( V_9 , V_30 , V_134 , V_32 ) ;
}
static T_1
char * F_67 ( char * V_9 , char * V_30 , T_4 * V_98 , struct V_31 V_32 ,
const char * V_57 )
{
bool V_153 = true ;
int V_154 = 1 ;
unsigned int V_36 = 0 ;
int V_29 ;
if ( V_32 . V_39 == 0 )
return V_9 ;
if ( F_42 ( V_98 ) )
return string ( V_9 , V_30 , NULL , V_32 ) ;
do {
switch ( V_57 [ V_154 ++ ] ) {
case 'a' :
V_36 |= V_155 ;
break;
case 'c' :
V_36 |= V_156 ;
break;
case 'h' :
V_36 |= V_157 ;
break;
case 'n' :
V_36 |= V_158 ;
break;
case 'o' :
V_36 |= V_159 ;
break;
case 'p' :
V_36 |= V_160 ;
break;
case 's' :
V_36 |= V_161 ;
break;
default:
V_153 = false ;
break;
}
} while ( V_153 );
if ( ! V_36 )
V_36 = V_162 ;
V_29 = V_32 . V_39 < 0 ? 1 : V_32 . V_39 ;
V_9 += F_68 ( V_98 , V_29 , V_9 , V_9 < V_30 ? V_30 - V_9 : 0 , V_36 , NULL ) ;
return V_9 ;
}
static T_1
char * F_69 ( char * V_9 , char * V_30 , const T_4 * V_98 ,
struct V_31 V_32 , const char * V_57 )
{
char V_163 [ V_164 + 1 ] ;
char * V_59 = V_163 ;
int V_8 ;
const T_4 * V_116 = V_165 ;
bool V_166 = false ;
switch ( * ( ++ V_57 ) ) {
case 'L' :
V_166 = true ;
case 'l' :
V_116 = V_167 ;
break;
case 'B' :
V_166 = true ;
break;
}
for ( V_8 = 0 ; V_8 < 16 ; V_8 ++ ) {
if ( V_166 )
V_59 = F_70 ( V_59 , V_98 [ V_116 [ V_8 ] ] ) ;
else
V_59 = F_54 ( V_59 , V_98 [ V_116 [ V_8 ] ] ) ;
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
return string ( V_9 , V_30 , V_163 , V_32 ) ;
}
static T_1
char * F_71 ( char * V_9 , char * V_30 , const void * V_98 , const char * V_57 )
{
unsigned long long V_25 ;
int V_24 ;
switch ( V_57 [ 1 ] ) {
case 'F' :
V_25 = * ( const V_168 * ) V_98 ;
V_24 = sizeof( V_168 ) ;
break;
default:
V_25 = ( unsigned long ) V_98 ;
V_24 = sizeof( unsigned long ) ;
break;
}
return F_17 ( V_9 , V_30 , V_25 , V_24 ) ;
}
static T_1
char * F_72 ( char * V_9 , char * V_30 , const void * V_98 , const char * V_57 )
{
unsigned long long V_25 ;
int V_24 ;
switch ( V_57 [ 1 ] ) {
case 'd' :
V_25 = * ( const V_169 * ) V_98 ;
V_24 = sizeof( V_169 ) ;
break;
case 'p' :
default:
V_25 = * ( const V_170 * ) V_98 ;
V_24 = sizeof( V_170 ) ;
break;
}
return F_17 ( V_9 , V_30 , V_25 , V_24 ) ;
}
static T_1
char * clock ( char * V_9 , char * V_30 , struct V_171 * V_171 , struct V_31 V_32 ,
const char * V_57 )
{
if ( ! F_73 ( V_172 ) || ! V_171 )
return string ( V_9 , V_30 , NULL , V_32 ) ;
switch ( V_57 [ 1 ] ) {
case 'r' :
return F_15 ( V_9 , V_30 , F_74 ( V_171 ) , V_32 ) ;
case 'n' :
default:
#ifdef F_75
return string ( V_9 , V_30 , F_76 ( V_171 ) , V_32 ) ;
#else
return F_17 ( V_9 , V_30 , ( unsigned long ) V_171 , sizeof( unsigned long ) ) ;
#endif
}
}
static
char * F_77 ( char * V_9 , char * V_30 , unsigned long V_36 ,
const struct V_173 * V_174 )
{
unsigned long V_48 ;
const struct V_31 V_175 = {
. V_39 = - 1 ,
. V_40 = - 1 ,
} ;
const struct V_31 V_176 = {
. V_36 = V_37 | V_41 ,
. V_39 = - 1 ,
. V_40 = - 1 ,
. V_3 = 16 ,
} ;
for ( ; V_36 && V_174 -> V_63 ; V_174 ++ ) {
V_48 = V_174 -> V_48 ;
if ( ( V_36 & V_48 ) != V_48 )
continue;
V_9 = string ( V_9 , V_30 , V_174 -> V_63 , V_175 ) ;
V_36 &= ~ V_48 ;
if ( V_36 ) {
if ( V_9 < V_30 )
* V_9 = '|' ;
V_9 ++ ;
}
}
if ( V_36 )
V_9 = F_15 ( V_9 , V_30 , V_36 , V_176 ) ;
return V_9 ;
}
static T_1
char * F_78 ( char * V_9 , char * V_30 , void * V_177 , const char * V_57 )
{
unsigned long V_36 ;
const struct V_173 * V_174 ;
switch ( V_57 [ 1 ] ) {
case 'p' :
V_36 = * ( unsigned long * ) V_177 ;
V_36 &= ( 1UL << V_178 ) - 1 ;
V_174 = V_179 ;
break;
case 'v' :
V_36 = * ( unsigned long * ) V_177 ;
V_174 = V_180 ;
break;
case 'g' :
V_36 = * ( V_181 * ) V_177 ;
V_174 = V_182 ;
break;
default:
F_79 ( 1 , L_23 , V_57 [ 1 ] ) ;
return V_9 ;
}
return F_77 ( V_9 , V_30 , V_36 , V_174 ) ;
}
static T_1
char * F_80 ( const char * V_57 , char * V_9 , char * V_30 , void * V_72 ,
struct V_31 V_32 )
{
const int V_183 = 2 * sizeof( void * ) ;
if ( ! V_72 && * V_57 != 'K' ) {
if ( V_32 . V_39 == - 1 )
V_32 . V_39 = V_183 ;
return string ( V_9 , V_30 , L_1 , V_32 ) ;
}
switch ( * V_57 ) {
case 'F' :
case 'f' :
V_72 = F_81 ( V_72 ) ;
case 'S' :
case 's' :
case 'B' :
return F_26 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'R' :
case 'r' :
return F_32 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'h' :
return F_41 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'b' :
switch ( V_57 [ 1 ] ) {
case 'l' :
return F_50 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
default:
return F_46 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
}
case 'M' :
case 'm' :
return F_53 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'I' :
case 'i' :
switch ( V_57 [ 1 ] ) {
case '6' :
return F_62 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case '4' :
return F_63 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'S' : {
const union {
struct V_184 V_185 ;
struct V_148 V_186 ;
struct V_135 V_187 ;
} * V_136 = V_72 ;
switch ( V_136 -> V_185 . V_188 ) {
case V_189 :
return F_66 ( V_9 , V_30 , & V_136 -> V_186 , V_32 , V_57 ) ;
case V_190 :
return F_64 ( V_9 , V_30 , & V_136 -> V_187 , V_32 , V_57 ) ;
default:
return string ( V_9 , V_30 , L_24 , V_32 ) ;
} }
}
break;
case 'E' :
return F_67 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'U' :
return F_69 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'V' :
{
T_6 V_191 ;
F_82 ( V_191 , * ( (struct V_192 * ) V_72 ) -> V_191 ) ;
V_9 += vsnprintf ( V_9 , V_30 > V_9 ? V_30 - V_9 : 0 ,
( (struct V_192 * ) V_72 ) -> V_57 , V_191 ) ;
va_end ( V_191 ) ;
return V_9 ;
}
case 'K' :
switch ( V_193 ) {
case 0 :
break;
case 1 : {
const struct V_194 * V_194 ;
if ( F_83 () || F_84 () || F_85 () ) {
if ( V_32 . V_39 == - 1 )
V_32 . V_39 = V_183 ;
return string ( V_9 , V_30 , L_25 , V_32 ) ;
}
V_194 = F_86 () ;
if ( ! F_87 ( V_195 , V_196 ) ||
! F_88 ( V_194 -> V_197 , V_194 -> V_198 ) ||
! F_89 ( V_194 -> V_199 , V_194 -> V_200 ) )
V_72 = NULL ;
break;
}
case 2 :
default:
V_72 = NULL ;
break;
}
break;
case 'N' :
return F_71 ( V_9 , V_30 , V_72 , V_57 ) ;
case 'a' :
return F_72 ( V_9 , V_30 , V_72 , V_57 ) ;
case 'd' :
return F_21 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'C' :
return clock ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
case 'D' :
return F_21 ( V_9 , V_30 ,
( ( const struct V_201 * ) V_72 ) -> V_202 . V_55 ,
V_32 , V_57 ) ;
#ifdef F_90
case 'g' :
return F_25 ( V_9 , V_30 , V_72 , V_32 , V_57 ) ;
#endif
case 'G' :
return F_78 ( V_9 , V_30 , V_72 , V_57 ) ;
}
V_32 . V_36 |= V_41 ;
if ( V_32 . V_39 == - 1 ) {
V_32 . V_39 = V_183 ;
V_32 . V_36 |= V_43 ;
}
V_32 . V_3 = 16 ;
return F_15 ( V_9 , V_30 , ( unsigned long ) V_72 , V_32 ) ;
}
static T_1
int F_91 ( const char * V_57 , struct V_31 * V_32 )
{
const char * V_93 = V_57 ;
char V_203 ;
if ( V_32 -> type == V_204 ) {
if ( V_32 -> V_39 < 0 ) {
V_32 -> V_39 = - V_32 -> V_39 ;
V_32 -> V_36 |= V_42 ;
}
V_32 -> type = V_205 ;
goto V_40;
}
if ( V_32 -> type == V_206 ) {
if ( V_32 -> V_40 < 0 )
V_32 -> V_40 = 0 ;
V_32 -> type = V_205 ;
goto V_203;
}
V_32 -> type = V_205 ;
for (; * V_57 ; ++ V_57 ) {
if ( * V_57 == '%' )
break;
}
if ( V_57 != V_93 || ! * V_57 )
return V_57 - V_93 ;
V_32 -> V_36 = 0 ;
while ( 1 ) {
bool V_153 = true ;
++ V_57 ;
switch ( * V_57 ) {
case '-' : V_32 -> V_36 |= V_42 ; break;
case '+' : V_32 -> V_36 |= V_45 ; break;
case ' ' : V_32 -> V_36 |= V_46 ; break;
case '#' : V_32 -> V_36 |= V_37 ; break;
case '0' : V_32 -> V_36 |= V_43 ; break;
default: V_153 = false ;
}
if ( ! V_153 )
break;
}
V_32 -> V_39 = - 1 ;
if ( isdigit ( * V_57 ) )
V_32 -> V_39 = F_7 ( & V_57 ) ;
else if ( * V_57 == '*' ) {
V_32 -> type = V_204 ;
return ++ V_57 - V_93 ;
}
V_40:
V_32 -> V_40 = - 1 ;
if ( * V_57 == '.' ) {
++ V_57 ;
if ( isdigit ( * V_57 ) ) {
V_32 -> V_40 = F_7 ( & V_57 ) ;
if ( V_32 -> V_40 < 0 )
V_32 -> V_40 = 0 ;
} else if ( * V_57 == '*' ) {
V_32 -> type = V_206 ;
return ++ V_57 - V_93 ;
}
}
V_203:
V_203 = 0 ;
if ( * V_57 == 'h' || F_92 ( * V_57 ) == 'l' ||
F_92 ( * V_57 ) == 'z' || * V_57 == 't' ) {
V_203 = * V_57 ++ ;
if ( F_93 ( V_203 == * V_57 ) ) {
if ( V_203 == 'l' ) {
V_203 = 'L' ;
++ V_57 ;
} else if ( V_203 == 'h' ) {
V_203 = 'H' ;
++ V_57 ;
}
}
}
V_32 -> V_3 = 10 ;
switch ( * V_57 ) {
case 'c' :
V_32 -> type = V_207 ;
return ++ V_57 - V_93 ;
case 's' :
V_32 -> type = V_208 ;
return ++ V_57 - V_93 ;
case 'p' :
V_32 -> type = V_51 ;
return ++ V_57 - V_93 ;
case '%' :
V_32 -> type = V_209 ;
return ++ V_57 - V_93 ;
case 'o' :
V_32 -> V_3 = 8 ;
break;
case 'x' :
V_32 -> V_36 |= V_41 ;
case 'X' :
V_32 -> V_3 = 16 ;
break;
case 'd' :
case 'i' :
V_32 -> V_36 |= V_44 ;
case 'u' :
break;
case 'n' :
default:
F_79 ( 1 , L_26 , * V_57 ) ;
V_32 -> type = V_210 ;
return V_57 - V_93 ;
}
if ( V_203 == 'L' )
V_32 -> type = V_211 ;
else if ( V_203 == 'l' ) {
F_16 ( V_212 + V_44 != V_213 ) ;
V_32 -> type = V_212 + ( V_32 -> V_36 & V_44 ) ;
} else if ( F_92 ( V_203 ) == 'z' ) {
V_32 -> type = V_214 ;
} else if ( V_203 == 't' ) {
V_32 -> type = V_215 ;
} else if ( V_203 == 'H' ) {
F_16 ( V_216 + V_44 != V_217 ) ;
V_32 -> type = V_216 + ( V_32 -> V_36 & V_44 ) ;
} else if ( V_203 == 'h' ) {
F_16 ( V_218 + V_44 != V_219 ) ;
V_32 -> type = V_218 + ( V_32 -> V_36 & V_44 ) ;
} else {
F_16 ( V_220 + V_44 != V_221 ) ;
V_32 -> type = V_220 + ( V_32 -> V_36 & V_44 ) ;
}
return ++ V_57 - V_93 ;
}
static void
F_94 ( struct V_31 * V_32 , int V_222 )
{
V_32 -> V_39 = V_222 ;
if ( F_79 ( V_32 -> V_39 != V_222 , L_27 , V_222 ) ) {
V_32 -> V_39 = F_95 ( V_222 , - V_223 , V_223 ) ;
}
}
static void
F_96 ( struct V_31 * V_32 , int V_224 )
{
V_32 -> V_40 = V_224 ;
if ( F_79 ( V_32 -> V_40 != V_224 , L_28 , V_224 ) ) {
V_32 -> V_40 = F_95 ( V_224 , 0 , V_225 ) ;
}
}
int vsnprintf ( char * V_9 , T_3 V_24 , const char * V_57 , T_6 args )
{
unsigned long long V_25 ;
char * V_226 , * V_30 ;
struct V_31 V_32 = { 0 } ;
if ( F_97 ( V_24 > V_227 ) )
return 0 ;
V_226 = V_9 ;
V_30 = V_9 + V_24 ;
if ( V_30 < V_9 ) {
V_30 = ( ( void * ) - 1 ) ;
V_24 = V_30 - V_9 ;
}
while ( * V_57 ) {
const char * V_228 = V_57 ;
int V_229 = F_91 ( V_57 , & V_32 ) ;
V_57 += V_229 ;
switch ( V_32 . type ) {
case V_205 : {
int V_230 = V_229 ;
if ( V_226 < V_30 ) {
if ( V_230 > V_30 - V_226 )
V_230 = V_30 - V_226 ;
memcpy ( V_226 , V_228 , V_230 ) ;
}
V_226 += V_229 ;
break;
}
case V_204 :
F_94 ( & V_32 , va_arg ( args , int ) ) ;
break;
case V_206 :
F_96 ( & V_32 , va_arg ( args , int ) ) ;
break;
case V_207 : {
char V_50 ;
if ( ! ( V_32 . V_36 & V_42 ) ) {
while ( -- V_32 . V_39 > 0 ) {
if ( V_226 < V_30 )
* V_226 = ' ' ;
++ V_226 ;
}
}
V_50 = ( unsigned char ) va_arg ( args , int ) ;
if ( V_226 < V_30 )
* V_226 = V_50 ;
++ V_226 ;
while ( -- V_32 . V_39 > 0 ) {
if ( V_226 < V_30 )
* V_226 = ' ' ;
++ V_226 ;
}
break;
}
case V_208 :
V_226 = string ( V_226 , V_30 , va_arg ( args , char * ) , V_32 ) ;
break;
case V_51 :
V_226 = F_80 ( V_57 , V_226 , V_30 , va_arg ( args , void * ) ,
V_32 ) ;
while ( isalnum ( * V_57 ) )
V_57 ++ ;
break;
case V_209 :
if ( V_226 < V_30 )
* V_226 = '%' ;
++ V_226 ;
break;
case V_210 :
goto V_231;
default:
switch ( V_32 . type ) {
case V_211 :
V_25 = va_arg (args, long long) ;
break;
case V_212 :
V_25 = va_arg (args, unsigned long) ;
break;
case V_213 :
V_25 = va_arg ( args , long ) ;
break;
case V_214 :
if ( V_32 . V_36 & V_44 )
V_25 = va_arg ( args , V_232 ) ;
else
V_25 = va_arg ( args , T_3 ) ;
break;
case V_215 :
V_25 = va_arg ( args , V_233 ) ;
break;
case V_216 :
V_25 = ( unsigned char ) va_arg ( args , int ) ;
break;
case V_217 :
V_25 = ( signed char ) va_arg ( args , int ) ;
break;
case V_218 :
V_25 = ( unsigned short ) va_arg ( args , int ) ;
break;
case V_219 :
V_25 = ( short ) va_arg ( args , int ) ;
break;
case V_221 :
V_25 = ( int ) va_arg ( args , int ) ;
break;
default:
V_25 = va_arg (args, unsigned int) ;
}
V_226 = F_15 ( V_226 , V_30 , V_25 , V_32 ) ;
}
}
V_231:
if ( V_24 > 0 ) {
if ( V_226 < V_30 )
* V_226 = '\0' ;
else
V_30 [ - 1 ] = '\0' ;
}
return V_226 - V_9 ;
}
int F_98 ( char * V_9 , T_3 V_24 , const char * V_57 , T_6 args )
{
int V_8 ;
V_8 = vsnprintf ( V_9 , V_24 , V_57 , args ) ;
if ( F_20 ( V_8 < V_24 ) )
return V_8 ;
if ( V_24 != 0 )
return V_24 - 1 ;
return 0 ;
}
int snprintf ( char * V_9 , T_3 V_24 , const char * V_57 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_57 ) ;
V_8 = vsnprintf ( V_9 , V_24 , V_57 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_99 ( char * V_9 , T_3 V_24 , const char * V_57 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_57 ) ;
V_8 = F_98 ( V_9 , V_24 , V_57 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int vsprintf ( char * V_9 , const char * V_57 , T_6 args )
{
return vsnprintf ( V_9 , V_227 , V_57 , args ) ;
}
int sprintf ( char * V_9 , const char * V_57 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_57 ) ;
V_8 = vsnprintf ( V_9 , V_227 , V_57 , args ) ;
va_end ( args ) ;
return V_8 ;
}
int F_100 ( T_5 * V_234 , T_3 V_24 , const char * V_57 , T_6 args )
{
struct V_31 V_32 = { 0 } ;
char * V_226 , * V_30 ;
V_226 = ( char * ) V_234 ;
V_30 = ( char * ) ( V_234 + V_24 ) ;
#define F_101 ( type ) \
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
while ( * V_57 ) {
int V_229 = F_91 ( V_57 , & V_32 ) ;
V_57 += V_229 ;
switch ( V_32 . type ) {
case V_205 :
case V_209 :
break;
case V_210 :
goto V_231;
case V_204 :
case V_206 :
F_101 ( int ) ;
break;
case V_207 :
F_101 ( char ) ;
break;
case V_208 : {
const char * V_235 = va_arg ( args , char * ) ;
T_3 V_29 ;
if ( ( unsigned long ) V_235 > ( unsigned long ) - V_54
|| ( unsigned long ) V_235 < V_54 )
V_235 = L_1 ;
V_29 = strlen ( V_235 ) + 1 ;
if ( V_226 + V_29 < V_30 )
memcpy ( V_226 , V_235 , V_29 ) ;
V_226 += V_29 ;
break;
}
case V_51 :
F_101 ( void * ) ;
while ( isalnum ( * V_57 ) )
V_57 ++ ;
break;
default:
switch ( V_32 . type ) {
case V_211 :
F_101 (long long) ;
break;
case V_212 :
case V_213 :
F_101 (unsigned long) ;
break;
case V_214 :
F_101 ( T_3 ) ;
break;
case V_215 :
F_101 ( V_233 ) ;
break;
case V_216 :
case V_217 :
F_101 ( char ) ;
break;
case V_218 :
case V_219 :
F_101 ( short ) ;
break;
default:
F_101 ( int ) ;
}
}
}
V_231:
return ( T_5 * ) ( F_102 ( V_226 , sizeof( T_5 ) ) ) - V_234 ;
#undef F_101
}
int F_103 ( char * V_9 , T_3 V_24 , const char * V_57 , const T_5 * V_234 )
{
struct V_31 V_32 = { 0 } ;
char * V_226 , * V_30 ;
const char * args = ( const char * ) V_234 ;
if ( F_97 ( V_24 > V_227 ) )
return 0 ;
V_226 = V_9 ;
V_30 = V_9 + V_24 ;
#define F_104 ( type ) \
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
while ( * V_57 ) {
const char * V_228 = V_57 ;
int V_229 = F_91 ( V_57 , & V_32 ) ;
V_57 += V_229 ;
switch ( V_32 . type ) {
case V_205 : {
int V_230 = V_229 ;
if ( V_226 < V_30 ) {
if ( V_230 > V_30 - V_226 )
V_230 = V_30 - V_226 ;
memcpy ( V_226 , V_228 , V_230 ) ;
}
V_226 += V_229 ;
break;
}
case V_204 :
F_94 ( & V_32 , F_104 ( int ) ) ;
break;
case V_206 :
F_96 ( & V_32 , F_104 ( int ) ) ;
break;
case V_207 : {
char V_50 ;
if ( ! ( V_32 . V_36 & V_42 ) ) {
while ( -- V_32 . V_39 > 0 ) {
if ( V_226 < V_30 )
* V_226 = ' ' ;
++ V_226 ;
}
}
V_50 = ( unsigned char ) F_104 ( char ) ;
if ( V_226 < V_30 )
* V_226 = V_50 ;
++ V_226 ;
while ( -- V_32 . V_39 > 0 ) {
if ( V_226 < V_30 )
* V_226 = ' ' ;
++ V_226 ;
}
break;
}
case V_208 : {
const char * V_236 = args ;
args += strlen ( V_236 ) + 1 ;
V_226 = string ( V_226 , V_30 , ( char * ) V_236 , V_32 ) ;
break;
}
case V_51 :
V_226 = F_80 ( V_57 , V_226 , V_30 , F_104 ( void * ) , V_32 ) ;
while ( isalnum ( * V_57 ) )
V_57 ++ ;
break;
case V_209 :
if ( V_226 < V_30 )
* V_226 = '%' ;
++ V_226 ;
break;
case V_210 :
goto V_231;
default: {
unsigned long long V_25 ;
switch ( V_32 . type ) {
case V_211 :
V_25 = F_104 (long long) ;
break;
case V_212 :
case V_213 :
V_25 = F_104 (unsigned long) ;
break;
case V_214 :
V_25 = F_104 ( T_3 ) ;
break;
case V_215 :
V_25 = F_104 ( V_233 ) ;
break;
case V_216 :
V_25 = F_104 (unsigned char) ;
break;
case V_217 :
V_25 = F_104 (signed char) ;
break;
case V_218 :
V_25 = F_104 (unsigned short) ;
break;
case V_219 :
V_25 = F_104 ( short ) ;
break;
case V_220 :
V_25 = F_104 (unsigned int) ;
break;
default:
V_25 = F_104 ( int ) ;
}
V_226 = F_15 ( V_226 , V_30 , V_25 , V_32 ) ;
}
}
}
V_231:
if ( V_24 > 0 ) {
if ( V_226 < V_30 )
* V_226 = '\0' ;
else
V_30 [ - 1 ] = '\0' ;
}
#undef F_104
return V_226 - V_9 ;
}
int F_105 ( T_5 * V_234 , T_3 V_24 , const char * V_57 , ... )
{
T_6 args ;
int V_237 ;
va_start ( args , V_57 ) ;
V_237 = F_100 ( V_234 , V_24 , V_57 , args ) ;
va_end ( args ) ;
return V_237 ;
}
int vsscanf ( const char * V_9 , const char * V_57 , T_6 args )
{
const char * V_226 = V_9 ;
char * V_238 ;
char V_239 ;
int V_25 = 0 ;
T_4 V_203 ;
unsigned int V_3 ;
union {
long long V_7 ;
unsigned long long V_240 ;
} V_106 ;
T_7 V_39 ;
bool V_241 ;
while ( * V_57 ) {
if ( isspace ( * V_57 ) ) {
V_57 = F_106 ( ++ V_57 ) ;
V_226 = F_106 ( V_226 ) ;
}
if ( * V_57 != '%' && * V_57 ) {
if ( * V_57 ++ != * V_226 ++ )
break;
continue;
}
if ( ! * V_57 )
break;
++ V_57 ;
if ( * V_57 == '*' ) {
if ( ! * V_226 )
break;
while ( ! isspace ( * V_57 ) && * V_57 != '%' && * V_57 ) {
if ( * V_57 == '[' )
return V_25 ;
V_57 ++ ;
}
while ( ! isspace ( * V_226 ) && * V_226 )
V_226 ++ ;
continue;
}
V_39 = - 1 ;
if ( isdigit ( * V_57 ) ) {
V_39 = F_7 ( & V_57 ) ;
if ( V_39 <= 0 )
break;
}
V_203 = - 1 ;
if ( * V_57 == 'h' || F_92 ( * V_57 ) == 'l' ||
F_92 ( * V_57 ) == 'z' ) {
V_203 = * V_57 ++ ;
if ( F_93 ( V_203 == * V_57 ) ) {
if ( V_203 == 'h' ) {
V_203 = 'H' ;
V_57 ++ ;
} else if ( V_203 == 'l' ) {
V_203 = 'L' ;
V_57 ++ ;
}
}
}
if ( ! * V_57 )
break;
if ( * V_57 == 'n' ) {
* va_arg ( args , int * ) = V_226 - V_9 ;
++ V_57 ;
continue;
}
if ( ! * V_226 )
break;
V_3 = 10 ;
V_241 = false ;
switch ( * V_57 ++ ) {
case 'c' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_39 == - 1 )
V_39 = 1 ;
do {
* V_7 ++ = * V_226 ++ ;
} while ( -- V_39 > 0 && * V_226 );
V_25 ++ ;
}
continue;
case 's' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
if ( V_39 == - 1 )
V_39 = V_242 ;
V_226 = F_106 ( V_226 ) ;
while ( * V_226 && ! isspace ( * V_226 ) && V_39 -- )
* V_7 ++ = * V_226 ++ ;
* V_7 = '\0' ;
V_25 ++ ;
}
continue;
case '[' :
{
char * V_7 = ( char * ) va_arg ( args , char * ) ;
F_107 ( V_243 , 256 ) = { 0 } ;
unsigned int V_29 = 0 ;
bool V_244 = ( * V_57 == '^' ) ;
if ( V_39 == - 1 )
return V_25 ;
if ( V_244 )
++ V_57 ;
for ( ; * V_57 && * V_57 != ']' ; ++ V_57 , ++ V_29 )
F_108 ( ( T_4 ) * V_57 , V_243 ) ;
if ( ! * V_57 || ! V_29 )
return V_25 ;
++ V_57 ;
if ( V_244 ) {
F_109 ( V_243 , V_243 , 256 ) ;
F_110 ( 0 , V_243 ) ;
}
if ( ! F_111 ( ( T_4 ) * V_226 , V_243 ) )
return V_25 ;
while ( F_111 ( ( T_4 ) * V_226 , V_243 ) && V_39 -- )
* V_7 ++ = * V_226 ++ ;
* V_7 = '\0' ;
++ V_25 ;
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
V_241 = true ;
case 'u' :
break;
case '%' :
if ( * V_226 ++ != '%' )
return V_25 ;
continue;
default:
return V_25 ;
}
V_226 = F_106 ( V_226 ) ;
V_239 = * V_226 ;
if ( V_241 && V_239 == '-' )
V_239 = * ( V_226 + 1 ) ;
if ( ! V_239
|| ( V_3 == 16 && ! isxdigit ( V_239 ) )
|| ( V_3 == 10 && ! isdigit ( V_239 ) )
|| ( V_3 == 8 && ( ! isdigit ( V_239 ) || V_239 > '7' ) )
|| ( V_3 == 0 && ! isdigit ( V_239 ) ) )
break;
if ( V_241 )
V_106 . V_7 = V_203 != 'L' ?
F_5 ( V_226 , & V_238 , V_3 ) :
F_6 ( V_226 , & V_238 , V_3 ) ;
else
V_106 . V_240 = V_203 != 'L' ?
F_4 ( V_226 , & V_238 , V_3 ) :
F_1 ( V_226 , & V_238 , V_3 ) ;
if ( V_39 > 0 && V_238 - V_226 > V_39 ) {
if ( V_3 == 0 )
F_2 ( V_226 , & V_3 ) ;
while ( V_238 - V_226 > V_39 ) {
if ( V_241 )
V_106 . V_7 = F_112 ( V_106 . V_7 , V_3 ) ;
else
V_106 . V_240 = F_113 ( V_106 . V_240 , V_3 ) ;
-- V_238 ;
}
}
switch ( V_203 ) {
case 'H' :
if ( V_241 )
* va_arg (args, signed char *) = V_106 . V_7 ;
else
* va_arg (args, unsigned char *) = V_106 . V_240 ;
break;
case 'h' :
if ( V_241 )
* va_arg ( args , short * ) = V_106 . V_7 ;
else
* va_arg (args, unsigned short *) = V_106 . V_240 ;
break;
case 'l' :
if ( V_241 )
* va_arg ( args , long * ) = V_106 . V_7 ;
else
* va_arg (args, unsigned long *) = V_106 . V_240 ;
break;
case 'L' :
if ( V_241 )
* va_arg (args, long long *) = V_106 . V_7 ;
else
* va_arg (args, unsigned long long *) = V_106 . V_240 ;
break;
case 'Z' :
case 'z' :
* va_arg ( args , T_3 * ) = V_106 . V_240 ;
break;
default:
if ( V_241 )
* va_arg ( args , int * ) = V_106 . V_7 ;
else
* va_arg (args, unsigned int *) = V_106 . V_240 ;
break;
}
V_25 ++ ;
if ( ! V_238 )
break;
V_226 = V_238 ;
}
return V_25 ;
}
int sscanf ( const char * V_9 , const char * V_57 , ... )
{
T_6 args ;
int V_8 ;
va_start ( args , V_57 ) ;
V_8 = vsscanf ( V_9 , V_57 , args ) ;
va_end ( args ) ;
return V_8 ;
}
