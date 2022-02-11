static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
int V_6 , V_7 ;
unsigned short * V_8 = V_9 [ V_5 ] ;
unsigned char * V_10 ;
if ( ! V_4 ) return;
V_10 = V_4 -> V_11 [ V_5 ] ;
if ( ! V_10 ) {
V_10 = V_4 -> V_11 [ V_5 ] = F_2 ( V_12 , V_13 ) ;
if ( ! V_10 ) return;
}
memset ( V_10 , 0 , V_12 ) ;
for ( V_6 = 0 ; V_6 < V_14 ; V_6 ++ ) {
V_7 = F_3 ( V_2 , V_8 [ V_6 ] ) ;
if ( V_7 >= 0 && V_7 < V_12 && V_10 [ V_7 ] < 32 ) {
V_10 [ V_7 ] = V_6 ;
}
}
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 , V_6 , V_15 , V_7 ;
T_1 * * V_16 , * V_17 ;
T_1 * V_10 ;
if ( ! V_4 ) return;
V_10 = V_4 -> V_18 ;
if ( ! V_10 ) {
V_10 = V_4 -> V_18 =
F_2 ( V_12 * sizeof( T_1 ) , V_13 ) ;
if ( ! V_10 )
return;
}
memset ( V_10 , 0 , V_12 * sizeof( T_1 ) ) ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( ! V_16 )
continue;
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
V_17 = V_16 [ V_6 ] ;
if ( ! V_17 )
continue;
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ ) {
V_7 = V_17 [ V_15 ] ;
if ( V_7 >= 0 && V_7 < V_12
&& V_10 [ V_7 ] < 32 )
V_10 [ V_7 ] = ( V_5 << 11 ) + ( V_6 << 6 ) + V_15 ;
}
}
}
}
unsigned short * F_5 ( int V_20 , struct V_1 * V_21 )
{
V_22 [ V_21 -> V_23 ] = V_20 ;
return V_9 [ V_20 ] ;
}
T_1 F_6 ( struct V_1 * V_2 , int V_7 , int V_24 )
{
struct V_3 * V_4 ;
int V_20 ;
if ( V_7 < 0 || V_7 >= V_12 )
return 0 ;
else if ( ! ( V_4 = * V_2 -> V_25 ) )
return V_7 ;
else if ( V_24 ) {
if ( ! V_4 -> V_18 )
return V_7 ;
else
return V_4 -> V_18 [ V_7 ] ;
} else {
V_20 = V_22 [ V_2 -> V_23 ] ;
if ( ! V_4 -> V_11 [ V_20 ] )
return V_7 ;
else
return V_4 -> V_11 [ V_20 ] [ V_7 ] ;
}
}
static void F_7 ( void )
{
int V_5 ;
struct V_3 * V_4 , * V_10 = NULL ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ ) {
if ( ! F_8 ( V_5 ) )
continue;
V_4 = * V_27 [ V_5 ] . V_28 -> V_25 ;
if ( V_4 && V_4 != V_10 ) {
F_1 ( V_27 [ V_5 ] . V_28 , V_4 , V_29 ) ;
F_4 ( V_27 [ V_5 ] . V_28 , V_4 ) ;
V_10 = V_4 ;
}
}
}
int F_9 ( unsigned char T_2 * V_30 )
{
int V_5 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
if ( ! F_10 ( V_31 , V_30 , V_14 ) )
return - V_32 ;
F_11 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
unsigned char V_33 ;
F_12 ( V_33 , V_30 + V_5 ) ;
V_4 [ V_5 ] = V_34 | V_33 ;
}
F_7 () ;
F_13 () ;
return 0 ;
}
int F_14 ( unsigned char T_2 * V_30 )
{
int V_5 , V_35 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
if ( ! F_10 ( V_36 , V_30 , V_14 ) )
return - V_32 ;
F_11 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
{
V_35 = F_3 ( V_27 [ V_37 ] . V_28 , V_4 [ V_5 ] ) ;
F_15 ( ( V_35 & ~ 0xff ) ? 0 : V_35 , V_30 + V_5 ) ;
}
F_13 () ;
return 0 ;
}
int F_16 ( T_3 T_2 * V_30 )
{
int V_5 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
if ( ! F_10 ( V_31 , V_30 , V_14 *sizeof( unsigned short ) ) )
return - V_32 ;
F_11 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
unsigned short V_38 ;
F_12 ( V_38 , V_30 + V_5 ) ;
V_4 [ V_5 ] = V_38 ;
}
F_7 () ;
F_13 () ;
return 0 ;
}
int F_17 ( T_3 T_2 * V_30 )
{
int V_5 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
if ( ! F_10 ( V_36 , V_30 , V_14 *sizeof( unsigned short ) ) )
return - V_32 ;
F_11 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
F_15 ( V_4 [ V_5 ] , V_30 + V_5 ) ;
F_13 () ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
T_1 * * V_16 ;
int V_5 , V_6 ;
if ( V_4 == V_39 ) V_39 = NULL ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
if ( ( V_16 = V_4 -> V_19 [ V_5 ] ) != NULL ) {
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ )
F_19 ( V_16 [ V_6 ] ) ;
F_19 ( V_16 ) ;
}
V_4 -> V_19 [ V_5 ] = NULL ;
}
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
F_19 ( V_4 -> V_11 [ V_5 ] ) ;
V_4 -> V_11 [ V_5 ] = NULL ;
}
F_19 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
}
void F_20 ( struct V_1 * V_21 )
{
struct V_3 * V_4 ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 )
return;
* V_21 -> V_25 = NULL ;
if ( -- V_4 -> V_40 )
return;
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 , V_15 ;
struct V_3 * V_10 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ ) {
if ( ! F_8 ( V_5 ) )
continue;
V_10 = * V_27 [ V_5 ] . V_28 -> V_25 ;
if ( ! V_10 || V_10 == V_4 || V_10 -> V_41 != V_4 -> V_41 )
continue;
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
T_1 * * V_16 , * * V_42 ;
V_16 = V_4 -> V_19 [ V_6 ] ; V_42 = V_10 -> V_19 [ V_6 ] ;
if ( ! V_16 && ! V_42 )
continue;
if ( ! V_16 || ! V_42 )
break;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ! V_16 [ V_15 ] && ! V_42 [ V_15 ] )
continue;
if ( ! V_16 [ V_15 ] || ! V_42 [ V_15 ] )
break;
if ( memcmp ( V_16 [ V_15 ] , V_42 [ V_15 ] , 64 * sizeof( T_1 ) ) )
break;
}
if ( V_15 < 32 )
break;
}
if ( V_6 == 32 ) {
V_10 -> V_40 ++ ;
* V_2 -> V_25 = V_10 ;
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_22 ( struct V_3 * V_4 , T_4 V_43 , T_4 V_44 )
{
int V_5 , V_45 ;
T_1 * * V_16 , * V_17 ;
if ( ! ( V_16 = V_4 -> V_19 [ V_45 = V_43 >> 11 ] ) ) {
V_16 = V_4 -> V_19 [ V_45 ] = F_2 ( 32 * sizeof( T_1 * ) , V_13 ) ;
if ( ! V_16 ) return - V_46 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
V_16 [ V_5 ] = NULL ;
}
if ( ! ( V_17 = V_16 [ V_45 = ( V_43 >> 6 ) & 0x1f ] ) ) {
V_17 = V_16 [ V_45 ] = F_2 ( 64 * sizeof( T_1 ) , V_13 ) ;
if ( ! V_17 ) return - V_46 ;
memset ( V_17 , 0xff , 64 * sizeof( T_1 ) ) ;
}
V_17 [ V_43 & 0x3f ] = V_44 ;
V_4 -> V_41 += ( V_44 << 20 ) + V_43 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_21 , struct V_47 * V_48 )
{
struct V_3 * V_4 , * V_10 ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 || -- V_4 -> V_40 ) {
V_10 = F_24 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_10 ) {
if ( V_4 )
V_4 -> V_40 ++ ;
return - V_46 ;
}
V_10 -> V_40 = 1 ;
* V_21 -> V_25 = V_10 ;
} else {
if ( V_4 == V_39 ) V_39 = NULL ;
V_4 -> V_40 ++ ;
V_4 -> V_41 = 0 ;
F_18 ( V_4 ) ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_21 , struct V_47 * V_48 )
{
int V_49 ;
F_11 () ;
V_49 = F_23 ( V_21 , V_48 ) ;
F_13 () ;
return V_49 ;
}
int F_26 ( struct V_1 * V_21 , T_3 V_50 , struct V_51 T_2 * V_52 )
{
int V_53 = 0 , V_54 , V_5 ;
struct V_3 * V_4 , * V_10 ;
if ( ! V_50 )
return 0 ;
F_11 () ;
V_4 = * V_21 -> V_25 ;
if ( V_4 -> V_40 > 1 ) {
int V_6 , V_15 ;
T_1 * * V_16 , * V_17 , V_55 ;
V_54 = F_23 ( V_21 , NULL ) ;
if ( V_54 ) {
F_13 () ;
return V_54 ;
}
V_10 = * V_21 -> V_25 ;
V_55 = 0 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
if ( ( V_16 = V_4 -> V_19 [ V_5 ] ) )
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ )
if ( ( V_17 = V_16 [ V_6 ] ) ) {
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ , V_55 ++ )
if ( V_17 [ V_15 ] != 0xffff ) {
V_54 = F_22 ( V_10 , V_55 , V_17 [ V_15 ] ) ;
if ( V_54 ) {
V_4 -> V_40 ++ ;
* V_21 -> V_25 = V_4 ;
F_18 ( V_10 ) ;
F_19 ( V_10 ) ;
F_13 () ;
return V_54 ;
}
}
} else {
V_55 += 64 ;
}
else
V_55 += 32 * 64 ;
V_4 = V_10 ;
} else if ( V_4 == V_39 ) {
V_39 = NULL ;
}
while ( V_50 -- ) {
unsigned short V_43 , V_44 ;
F_12 ( V_43 , & V_52 -> V_43 ) ;
F_12 ( V_44 , & V_52 -> V_44 ) ;
if ( ( V_54 = F_22 ( V_4 , V_43 , V_44 ) ) != 0 )
V_53 = V_54 ;
V_52 ++ ;
}
if ( F_21 ( V_21 , V_4 ) ) {
F_13 () ;
return V_53 ;
}
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
F_13 () ;
return V_53 ;
}
int F_27 ( struct V_1 * V_21 )
{
int V_5 , V_6 , V_53 = 0 , V_54 ;
T_1 * V_10 ;
struct V_3 * V_4 ;
if ( V_39 ) {
V_4 = * V_21 -> V_25 ;
if ( V_4 == V_39 )
return 0 ;
V_39 -> V_40 ++ ;
* V_21 -> V_25 = V_39 ;
if ( V_4 && ! -- V_4 -> V_40 ) {
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
}
return 0 ;
}
V_53 = F_23 ( V_21 , NULL ) ;
if ( V_53 )
return V_53 ;
V_4 = * V_21 -> V_25 ;
V_10 = V_56 ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ )
for ( V_6 = V_57 [ V_5 ] ; V_6 ; V_6 -- ) {
V_54 = F_22 ( V_4 , * ( V_10 ++ ) , V_5 ) ;
if ( V_54 )
V_53 = V_54 ;
}
if ( F_21 ( V_21 , V_4 ) ) {
V_39 = * V_21 -> V_25 ;
return V_53 ;
}
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
V_39 = V_4 ;
return V_53 ;
}
int F_28 ( struct V_1 * V_58 , struct V_1 * V_59 )
{
struct V_3 * V_10 ;
if ( ! * V_59 -> V_25 )
return - V_60 ;
if ( * V_58 -> V_25 == * V_59 -> V_25 )
return 0 ;
F_20 ( V_58 ) ;
V_10 = * V_59 -> V_25 ;
V_10 -> V_40 ++ ;
* V_58 -> V_25 = V_10 ;
return 0 ;
}
int F_29 ( struct V_1 * V_21 , T_3 V_50 , T_3 T_2 * V_61 , struct V_51 T_2 * V_52 )
{
int V_5 , V_6 , V_15 , V_62 ;
T_1 * * V_16 , * V_17 ;
struct V_3 * V_4 ;
F_11 () ;
V_62 = 0 ;
if ( * V_21 -> V_25 ) {
V_4 = * V_21 -> V_25 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
if ( ( V_16 = V_4 -> V_19 [ V_5 ] ) )
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ )
if ( ( V_17 = * ( V_16 ++ ) ) )
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ ) {
if ( * V_17 < V_12 && V_62 ++ < V_50 ) {
F_15 ( ( T_4 ) ( ( V_5 << 11 ) + ( V_6 << 6 ) + V_15 ) ,
& V_52 -> V_43 ) ;
F_15 ( ( T_4 ) * V_17 ,
& V_52 -> V_44 ) ;
V_52 ++ ;
}
V_17 ++ ;
}
}
F_15 ( V_62 , V_61 ) ;
F_13 () ;
return ( ( V_62 <= V_50 ) ? 0 : - V_46 ) ;
}
T_5 F_30 ( unsigned char V_63 )
{
unsigned short V_64 = V_9 [ V_29 ] [ V_63 ] ;
return V_64 == ( 0xf000 | V_63 ) ? V_63 : V_64 ;
}
int F_31 ( T_5 V_64 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < 0x100 ; V_63 ++ )
if ( V_9 [ V_29 ] [ V_63 ] == V_64 ||
( V_9 [ V_29 ] [ V_63 ] == ( V_63 | 0xf000 ) && V_64 == V_63 ) )
return V_63 ;
return - 1 ;
}
int
F_3 ( struct V_1 * V_2 , long V_65 )
{
int V_66 ;
T_1 * * V_16 , * V_17 ;
struct V_3 * V_4 ;
if ( V_65 > 0xffff )
return - 4 ;
else if ( V_65 < 0x20 )
return - 1 ;
else if ( V_65 == 0xfeff || ( V_65 >= 0x200b && V_65 <= 0x200f ) )
return - 2 ;
else if ( ( V_65 & ~ V_67 ) == V_34 )
return V_65 & V_67 ;
if ( ! * V_2 -> V_25 )
return - 3 ;
V_4 = * V_2 -> V_25 ;
if ( ( V_16 = V_4 -> V_19 [ V_65 >> 11 ] ) &&
( V_17 = V_16 [ ( V_65 >> 6 ) & 0x1f ] ) &&
( V_66 = V_17 [ V_65 & 0x3f ] ) < V_12 )
return V_66 ;
return - 4 ;
}
void T_6
F_32 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ )
if ( F_8 ( V_5 ) && ! * V_27 [ V_5 ] . V_28 -> V_25 )
F_27 ( V_27 [ V_5 ] . V_28 ) ;
}
