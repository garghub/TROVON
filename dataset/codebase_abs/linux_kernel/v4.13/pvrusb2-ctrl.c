static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 -> V_5 ) {
if ( ! V_2 -> V_4 -> V_5 ( V_2 , V_3 ) ) return - V_6 ;
} else if ( V_2 -> V_4 -> type == V_7 ) {
if ( V_3 < 0 ) return - V_6 ;
if ( V_3 >= V_2 -> V_4 -> V_8 . V_9 . V_10 ) return - V_6 ;
} else {
int V_11 ;
V_11 = V_2 -> V_4 -> V_8 . V_12 . V_13 ;
if ( V_2 -> V_4 -> V_14 ) {
V_2 -> V_4 -> V_14 ( V_2 , & V_11 ) ;
}
if ( V_3 < V_11 ) return - V_6 ;
V_11 = V_2 -> V_4 -> V_8 . V_12 . V_15 ;
if ( V_2 -> V_4 -> V_16 ) {
V_2 -> V_4 -> V_16 ( V_2 , & V_11 ) ;
}
if ( V_3 > V_11 ) return - V_6 ;
}
return 0 ;
}
int F_2 ( struct V_1 * V_2 , int V_3 )
{
return F_3 ( V_2 , ~ 0 , V_3 ) ;
}
int F_3 ( struct V_1 * V_2 , int V_17 , int V_3 )
{
int V_18 = 0 ;
if ( ! V_2 ) return - V_19 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> V_22 ) {
if ( V_2 -> V_4 -> type == V_23 ) {
V_17 &= V_2 -> V_4 -> V_8 . V_24 . V_25 ;
} else if ( ( V_2 -> V_4 -> type == V_26 ) ||
( V_2 -> V_4 -> type == V_7 ) ) {
V_18 = F_1 ( V_2 , V_3 ) ;
if ( V_18 < 0 ) break;
} else if ( V_2 -> V_4 -> type != V_27 ) {
break;
}
V_18 = V_2 -> V_4 -> V_22 ( V_2 , V_17 , V_3 ) ;
} else {
V_18 = - V_28 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_6 ( struct V_1 * V_2 , int * V_29 )
{
int V_18 = 0 ;
if ( ! V_2 ) return - V_19 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
V_18 = V_2 -> V_4 -> V_30 ( V_2 , V_29 ) ;
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
enum V_31 F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return V_26 ;
return V_2 -> V_4 -> type ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( ! V_2 ) return 0 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> V_16 ) {
V_2 -> V_4 -> V_16 ( V_2 , & V_18 ) ;
} else if ( V_2 -> V_4 -> type == V_26 ) {
V_18 = V_2 -> V_4 -> V_8 . V_12 . V_15 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( ! V_2 ) return 0 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> V_14 ) {
V_2 -> V_4 -> V_14 ( V_2 , & V_18 ) ;
} else if ( V_2 -> V_4 -> type == V_26 ) {
V_18 = V_2 -> V_4 -> V_8 . V_12 . V_13 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_10 ( struct V_1 * V_2 , int * V_29 )
{
int V_18 = 0 ;
if ( ! V_2 ) return - V_19 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> V_32 ) {
V_18 = V_2 -> V_4 -> V_32 ( V_2 , V_29 ) ;
} else {
* V_29 = V_2 -> V_4 -> V_33 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( ! V_2 ) return 0 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> type == V_7 ) {
V_18 = V_2 -> V_4 -> V_8 . V_9 . V_10 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_18 = 0 ;
if ( ! V_2 ) return 0 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> type == V_23 ) {
V_18 = V_2 -> V_4 -> V_8 . V_24 . V_25 ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
const char * F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return NULL ;
return V_2 -> V_4 -> V_34 ;
}
const char * F_14 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return NULL ;
return V_2 -> V_4 -> V_35 ;
}
int F_15 ( struct V_1 * V_2 , int V_3 ,
char * V_36 , unsigned int V_37 ,
unsigned int * V_38 )
{
int V_18 = - V_19 ;
if ( ! V_2 ) return 0 ;
* V_38 = 0 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> type == V_7 ) {
const char * const * V_39 ;
V_39 = V_2 -> V_4 -> V_8 . V_9 . V_40 ;
if ( F_1 ( V_2 , V_3 ) == 0 ) {
if ( V_39 [ V_3 ] ) {
* V_38 = F_16 (
V_36 , V_37 , L_1 ,
V_39 [ V_3 ] ) ;
} else {
* V_38 = 0 ;
}
V_18 = 0 ;
}
} else if ( V_2 -> V_4 -> type == V_23 ) {
const char * * V_39 ;
unsigned int V_41 ;
int V_42 ;
V_39 = V_2 -> V_4 -> V_8 . V_24 . V_43 ;
V_3 &= V_2 -> V_4 -> V_8 . V_24 . V_25 ;
for ( V_41 = 0 , V_42 = 1 ; V_3 ; V_41 ++ , V_42 <<= 1 ) {
if ( V_3 & V_42 ) {
* V_38 = F_16 ( V_36 , V_37 , L_1 ,
V_39 [ V_41 ] ) ;
V_18 = 0 ;
break;
}
}
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return 0 ;
return V_2 -> V_4 -> V_44 ;
}
unsigned int F_18 ( struct V_1 * V_2 )
{
unsigned int V_45 = 0 ;
if ( V_2 -> V_4 -> V_46 ) {
V_45 = V_2 -> V_4 -> V_46 ( V_2 ) ;
}
if ( V_2 -> V_4 -> V_22 ) {
V_45 &= ~ V_47 ;
} else {
V_45 |= V_47 ;
}
return V_45 ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return 0 ;
return V_2 -> V_4 -> V_22 != NULL ;
}
int F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 ) return 0 ;
if ( ! V_2 -> V_4 -> V_48 ) return 0 ;
if ( ! V_2 -> V_4 -> V_49 ) return 0 ;
return ! 0 ;
}
int F_21 ( struct V_1 * V_2 ,
int V_17 , int V_3 ,
char * V_50 , unsigned int V_51 ,
unsigned int * V_52 )
{
if ( ! V_2 ) return - V_19 ;
if ( ! V_2 -> V_4 -> V_48 ) return - V_19 ;
return V_2 -> V_4 -> V_48 ( V_2 , V_17 , V_3 , V_50 , V_51 , V_52 ) ;
}
int F_22 ( struct V_1 * V_2 ,
const char * V_50 , unsigned int V_52 ,
int * V_53 , int * V_29 )
{
if ( ! V_2 ) return - V_19 ;
if ( ! V_2 -> V_4 -> V_49 ) return - V_19 ;
return V_2 -> V_4 -> V_49 ( V_2 , V_50 , V_52 , V_53 , V_29 ) ;
}
static unsigned int F_23 ( int V_42 , int V_3 , int V_54 ,
const char * * V_39 ,
char * V_55 , unsigned int V_52 )
{
unsigned int V_41 ;
long V_56 , V_57 ;
int V_58 ;
unsigned int V_59 , V_60 ;
const char * V_61 ;
V_58 = 0 ;
V_59 = 0 ;
V_57 = 0 ;
for ( V_41 = 0 , V_56 = 1 ; V_42 ; V_41 ++ , V_56 <<= 1 ) {
if ( V_56 & V_42 ) {
V_42 &= ~ V_56 ;
V_61 = V_39 [ V_41 ] ;
if ( V_61 ) {
V_60 = F_16 ( V_55 , V_52 , L_2 ,
( V_58 ? L_3 : L_4 ) ,
( V_54 ? L_4 :
( ( V_3 & V_56 ) ? L_5 : L_6 ) ) ,
V_61 ) ;
V_55 += V_60 ; V_52 -= V_60 ; V_59 += V_60 ;
V_58 = ! 0 ;
} else {
V_57 |= V_56 ;
}
}
}
if ( V_57 ) {
if ( V_54 ) {
V_60 = F_16 ( V_55 , V_52 , L_7 ,
( V_58 ? L_3 : L_4 ) ,
V_57 ) ;
V_55 += V_60 ; V_52 -= V_60 ; V_59 += V_60 ;
V_58 = ! 0 ;
} else if ( V_57 & V_3 ) {
V_60 = F_16 ( V_55 , V_52 , L_8 ,
( V_58 ? L_3 : L_4 ) ,
V_57 & V_3 ) ;
V_55 += V_60 ; V_52 -= V_60 ; V_59 += V_60 ;
V_58 = ! 0 ;
} else if ( V_57 & ~ V_3 ) {
V_60 = F_16 ( V_55 , V_52 , L_8 ,
( V_58 ? L_3 : L_4 ) ,
V_57 & ~ V_3 ) ;
V_55 += V_60 ; V_52 -= V_60 ; V_59 += V_60 ;
V_58 = ! 0 ;
}
}
return V_59 ;
}
static int F_24 ( const char * V_55 , unsigned int V_52 ,
int * V_29 ,
const char * const * V_39 , unsigned int V_62 )
{
char V_50 [ 33 ] ;
unsigned int V_63 ;
unsigned int V_41 ;
int V_64 ;
char * V_65 ;
* V_29 = 0 ;
if ( ! V_39 ) V_62 = 0 ;
for ( V_41 = 0 ; V_41 < V_62 ; V_41 ++ ) {
if ( ! V_39 [ V_41 ] ) continue;
V_63 = strlen ( V_39 [ V_41 ] ) ;
if ( V_63 != V_52 ) continue;
if ( memcmp ( V_39 [ V_41 ] , V_55 , V_63 ) ) continue;
* V_29 = V_41 ;
return 0 ;
}
V_64 = 0 ;
if ( ( * V_55 == '-' ) || ( * V_55 == '+' ) ) {
V_64 = ( * V_55 == '-' ) ;
V_55 ++ ; V_52 -- ;
}
if ( V_52 >= sizeof( V_50 ) ) return - V_19 ;
memcpy ( V_50 , V_55 , V_52 ) ;
V_50 [ V_52 ] = 0 ;
* V_29 = F_25 ( V_50 , & V_65 , 0 ) ;
if ( V_64 ) * V_29 = - ( * V_29 ) ;
if ( * V_65 ) return - V_19 ;
return 1 ;
}
static int F_26 ( const char * V_55 , unsigned int V_52 ,
int * V_29 ,
const char * * V_39 , int V_25 )
{
char V_50 [ 33 ] ;
unsigned int V_63 ;
unsigned int V_41 ;
char * V_65 ;
int V_42 ;
* V_29 = 0 ;
for ( V_41 = 0 , V_42 = 1 ; V_25 ; V_41 ++ , V_42 <<= 1 ) {
if ( ! ( V_42 & V_25 ) ) continue;
V_25 &= ~ V_42 ;
if ( ! V_39 [ V_41 ] ) continue;
V_63 = strlen ( V_39 [ V_41 ] ) ;
if ( V_63 != V_52 ) continue;
if ( memcmp ( V_39 [ V_41 ] , V_55 , V_63 ) ) continue;
* V_29 = V_42 ;
return 0 ;
}
if ( V_52 >= sizeof( V_50 ) ) return - V_19 ;
memcpy ( V_50 , V_55 , V_52 ) ;
V_50 [ V_52 ] = 0 ;
* V_29 = F_25 ( V_50 , & V_65 , 0 ) ;
if ( * V_65 ) return - V_19 ;
return 0 ;
}
static int F_27 ( const char * V_55 , unsigned int V_52 ,
int * V_53 , int * V_29 ,
const char * * V_39 , int V_25 )
{
unsigned int V_60 ;
int V_17 , V_3 , V_66 , V_67 , V_18 ;
V_17 = 0 ;
V_3 = 0 ;
V_18 = 0 ;
while ( V_52 ) {
V_60 = 0 ;
while ( ( V_60 < V_52 ) &&
( ( V_55 [ V_60 ] <= 32 ) ||
( V_55 [ V_60 ] >= 127 ) ) ) V_60 ++ ;
V_55 += V_60 ;
V_52 -= V_60 ;
V_67 = 0 ;
if ( ( * V_55 == '-' ) || ( * V_55 == '+' ) ) {
V_67 = ( * V_55 == '-' ) ? - 1 : 1 ;
V_55 ++ ;
V_52 -- ;
}
V_60 = 0 ;
while ( V_60 < V_52 ) {
if ( V_55 [ V_60 ] <= 32 ) break;
if ( V_55 [ V_60 ] >= 127 ) break;
V_60 ++ ;
}
if ( ! V_60 ) break;
if ( F_26 ( V_55 , V_60 , & V_66 , V_39 , V_25 ) ) {
V_18 = - V_19 ;
break;
}
V_55 += V_60 ;
V_52 -= V_60 ;
switch ( V_67 ) {
case 0 :
V_17 = V_25 ;
V_3 |= V_66 ;
break;
case - 1 :
V_17 |= V_66 ;
V_3 &= ~ V_66 ;
break;
case 1 :
V_17 |= V_66 ;
V_3 |= V_66 ;
break;
default:
break;
}
}
* V_53 = V_17 ;
* V_29 = V_3 ;
return V_18 ;
}
int F_28 ( struct V_1 * V_2 ,
const char * V_55 , unsigned int V_52 ,
int * V_53 , int * V_29 )
{
int V_18 = - V_19 ;
unsigned int V_60 ;
* V_53 = 0 ;
* V_29 = 0 ;
V_60 = 0 ;
while ( ( V_60 < V_52 ) && ( ( V_55 [ V_60 ] <= 32 ) || ( V_55 [ V_60 ] >= 127 ) ) ) V_60 ++ ;
V_52 -= V_60 ; V_55 += V_60 ;
V_60 = 0 ;
while ( ( V_60 < V_52 ) && ( ( V_55 [ V_52 - ( V_60 + 1 ) ] <= 32 ) ||
( V_55 [ V_52 - ( V_60 + 1 ) ] >= 127 ) ) ) V_60 ++ ;
V_52 -= V_60 ;
if ( ! V_52 ) return - V_19 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
if ( V_2 -> V_4 -> type == V_26 ) {
V_18 = F_24 ( V_55 , V_52 , V_29 , NULL , 0 ) ;
if ( V_18 >= 0 ) {
V_18 = F_1 ( V_2 , * V_29 ) ;
}
* V_53 = ~ 0 ;
} else if ( V_2 -> V_4 -> type == V_27 ) {
V_18 = F_24 ( V_55 , V_52 , V_29 , V_68 ,
F_29 ( V_68 ) ) ;
if ( V_18 == 1 ) {
* V_29 = * V_29 ? ! 0 : 0 ;
} else if ( V_18 == 0 ) {
* V_29 = ( * V_29 & 1 ) ? ! 0 : 0 ;
}
* V_53 = 1 ;
} else if ( V_2 -> V_4 -> type == V_7 ) {
V_18 = F_24 (
V_55 , V_52 , V_29 ,
V_2 -> V_4 -> V_8 . V_9 . V_40 ,
V_2 -> V_4 -> V_8 . V_9 . V_10 ) ;
if ( V_18 >= 0 ) {
V_18 = F_1 ( V_2 , * V_29 ) ;
}
* V_53 = ~ 0 ;
} else if ( V_2 -> V_4 -> type == V_23 ) {
V_18 = F_27 (
V_55 , V_52 , V_53 , V_29 ,
V_2 -> V_4 -> V_8 . V_24 . V_43 ,
V_2 -> V_4 -> V_8 . V_24 . V_25 ) ;
}
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
int F_30 ( struct V_1 * V_2 ,
int V_17 , int V_3 ,
char * V_50 , unsigned int V_51 ,
unsigned int * V_52 )
{
int V_18 = - V_19 ;
* V_52 = 0 ;
if ( V_2 -> V_4 -> type == V_26 ) {
* V_52 = F_16 ( V_50 , V_51 , L_9 , V_3 ) ;
V_18 = 0 ;
} else if ( V_2 -> V_4 -> type == V_27 ) {
* V_52 = F_16 ( V_50 , V_51 , L_1 , V_3 ? L_10 : L_11 ) ;
V_18 = 0 ;
} else if ( V_2 -> V_4 -> type == V_7 ) {
const char * const * V_39 ;
V_39 = V_2 -> V_4 -> V_8 . V_9 . V_40 ;
if ( ( V_3 >= 0 ) &&
( V_3 < V_2 -> V_4 -> V_8 . V_9 . V_10 ) ) {
if ( V_39 [ V_3 ] ) {
* V_52 = F_16 (
V_50 , V_51 , L_1 ,
V_39 [ V_3 ] ) ;
} else {
* V_52 = 0 ;
}
V_18 = 0 ;
}
} else if ( V_2 -> V_4 -> type == V_23 ) {
* V_52 = F_23 (
V_3 & V_17 & V_2 -> V_4 -> V_8 . V_24 . V_25 ,
~ 0 , ! 0 ,
V_2 -> V_4 -> V_8 . V_24 . V_43 ,
V_50 , V_51 ) ;
}
return V_18 ;
}
int F_31 ( struct V_1 * V_2 ,
int V_17 , int V_3 ,
char * V_50 , unsigned int V_51 ,
unsigned int * V_52 )
{
int V_18 ;
F_4 ( V_2 -> V_20 -> V_21 ) ; do {
V_18 = F_30 ( V_2 , V_17 , V_3 ,
V_50 , V_51 , V_52 ) ;
} while( 0 ); F_5 ( V_2 -> V_20 -> V_21 ) ;
return V_18 ;
}
