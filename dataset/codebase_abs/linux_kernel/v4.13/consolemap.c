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
else {
V_4 = * V_2 -> V_25 ;
if ( ! V_4 )
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
unsigned short V_31 [ V_14 ] ;
unsigned char V_32 [ V_14 ] ;
if ( F_10 ( V_32 , V_30 , V_14 ) )
return - V_33 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
V_31 [ V_5 ] = V_34 | V_32 [ V_5 ] ;
F_11 () ;
memcpy ( V_9 [ V_29 ] , V_31 , sizeof( V_31 ) ) ;
F_7 () ;
F_12 () ;
return 0 ;
}
int F_13 ( unsigned char T_2 * V_30 )
{
int V_5 , V_35 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
unsigned char V_36 [ V_14 ] ;
F_11 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
{
V_35 = F_3 ( V_27 [ V_37 ] . V_28 , V_4 [ V_5 ] ) ;
V_36 [ V_5 ] = ( V_35 & ~ 0xff ) ? 0 : V_35 ;
}
F_12 () ;
return F_14 ( V_30 , V_36 , sizeof( V_36 ) ) ? - V_33 : 0 ;
}
int F_15 ( T_3 T_2 * V_30 )
{
unsigned short V_31 [ V_14 ] ;
if ( F_10 ( V_31 , V_30 , sizeof( V_31 ) ) )
return - V_33 ;
F_11 () ;
memcpy ( V_9 [ V_29 ] , V_31 , sizeof( V_31 ) ) ;
F_7 () ;
F_12 () ;
return 0 ;
}
int F_16 ( T_3 T_2 * V_30 )
{
unsigned short V_36 [ V_14 ] ;
F_11 () ;
memcpy ( V_36 , V_9 [ V_29 ] , sizeof( V_36 ) ) ;
F_12 () ;
return F_14 ( V_30 , V_36 , sizeof( V_36 ) ) ? - V_33 : 0 ;
}
static void F_17 ( struct V_3 * V_4 )
{
T_1 * * V_16 ;
int V_5 , V_6 ;
if ( V_4 == V_38 ) V_38 = NULL ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( V_16 != NULL ) {
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ )
F_18 ( V_16 [ V_6 ] ) ;
F_18 ( V_16 ) ;
}
V_4 -> V_19 [ V_5 ] = NULL ;
}
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
F_18 ( V_4 -> V_11 [ V_5 ] ) ;
V_4 -> V_11 [ V_5 ] = NULL ;
}
F_18 ( V_4 -> V_18 ) ;
V_4 -> V_18 = NULL ;
}
void F_19 ( struct V_1 * V_21 )
{
struct V_3 * V_4 ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 )
return;
* V_21 -> V_25 = NULL ;
if ( -- V_4 -> V_39 )
return;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 , V_15 ;
struct V_3 * V_10 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ ) {
if ( ! F_8 ( V_5 ) )
continue;
V_10 = * V_27 [ V_5 ] . V_28 -> V_25 ;
if ( ! V_10 || V_10 == V_4 || V_10 -> V_40 != V_4 -> V_40 )
continue;
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
T_1 * * V_16 , * * V_41 ;
V_16 = V_4 -> V_19 [ V_6 ] ; V_41 = V_10 -> V_19 [ V_6 ] ;
if ( ! V_16 && ! V_41 )
continue;
if ( ! V_16 || ! V_41 )
break;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ! V_16 [ V_15 ] && ! V_41 [ V_15 ] )
continue;
if ( ! V_16 [ V_15 ] || ! V_41 [ V_15 ] )
break;
if ( memcmp ( V_16 [ V_15 ] , V_41 [ V_15 ] , 64 * sizeof( T_1 ) ) )
break;
}
if ( V_15 < 32 )
break;
}
if ( V_6 == 32 ) {
V_10 -> V_39 ++ ;
* V_2 -> V_25 = V_10 ;
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_21 ( struct V_3 * V_4 , T_4 V_42 , T_4 V_43 )
{
int V_5 , V_44 ;
T_1 * * V_16 , * V_17 ;
V_16 = V_4 -> V_19 [ V_44 = V_42 >> 11 ] ;
if ( ! V_16 ) {
V_16 = V_4 -> V_19 [ V_44 ] = F_2 ( 32 * sizeof( T_1 * ) , V_13 ) ;
if ( ! V_16 ) return - V_45 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
V_16 [ V_5 ] = NULL ;
}
V_17 = V_16 [ V_44 = ( V_42 >> 6 ) & 0x1f ] ;
if ( ! V_17 ) {
V_17 = V_16 [ V_44 ] = F_2 ( 64 * sizeof( T_1 ) , V_13 ) ;
if ( ! V_17 ) return - V_45 ;
memset ( V_17 , 0xff , 64 * sizeof( T_1 ) ) ;
}
V_17 [ V_42 & 0x3f ] = V_43 ;
V_4 -> V_40 += ( V_43 << 20 ) + V_42 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_21 )
{
struct V_3 * V_4 , * V_10 ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 || -- V_4 -> V_39 ) {
V_10 = F_23 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_10 ) {
if ( V_4 )
V_4 -> V_39 ++ ;
return - V_45 ;
}
V_10 -> V_39 = 1 ;
* V_21 -> V_25 = V_10 ;
} else {
if ( V_4 == V_38 ) V_38 = NULL ;
V_4 -> V_39 ++ ;
V_4 -> V_40 = 0 ;
F_17 ( V_4 ) ;
}
return 0 ;
}
int F_24 ( struct V_1 * V_21 )
{
int V_46 ;
F_11 () ;
V_46 = F_22 ( V_21 ) ;
F_12 () ;
return V_46 ;
}
int F_25 ( struct V_1 * V_21 , T_3 V_47 , struct V_48 T_2 * V_49 )
{
int V_50 = 0 , V_51 , V_5 ;
struct V_3 * V_4 , * V_10 ;
struct V_48 * V_52 , * V_53 ;
if ( ! V_47 )
return 0 ;
V_52 = F_26 ( V_49 , V_47 * sizeof( struct V_48 ) ) ;
if ( F_27 ( V_52 ) )
return F_28 ( V_52 ) ;
F_11 () ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 ) {
V_50 = - V_54 ;
goto V_55;
}
if ( V_4 -> V_39 > 1 ) {
int V_6 , V_15 ;
T_1 * * V_16 , * V_17 , V_56 ;
V_51 = F_22 ( V_21 ) ;
if ( V_51 ) {
V_50 = V_51 ;
goto V_55;
}
V_10 = * V_21 -> V_25 ;
V_56 = 0 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( V_16 )
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
V_17 = V_16 [ V_6 ] ;
if ( V_17 ) {
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ , V_56 ++ )
if ( V_17 [ V_15 ] != 0xffff ) {
V_51 = F_21 ( V_10 , V_56 , V_17 [ V_15 ] ) ;
if ( V_51 ) {
V_4 -> V_39 ++ ;
* V_21 -> V_25 = V_4 ;
F_17 ( V_10 ) ;
F_18 ( V_10 ) ;
V_50 = V_51 ;
goto V_55;
}
}
} else {
V_56 += 64 ;
}
}
else
V_56 += 32 * 64 ;
}
V_4 = V_10 ;
} else if ( V_4 == V_38 ) {
V_38 = NULL ;
}
for ( V_53 = V_52 ; V_47 ; V_47 -- , V_53 ++ ) {
V_51 = F_21 ( V_4 , V_53 -> V_42 , V_53 -> V_43 ) ;
if ( V_51 )
V_50 = V_51 ;
}
if ( F_20 ( V_21 , V_4 ) )
goto V_55;
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
V_55:
F_12 () ;
F_18 ( V_52 ) ;
return V_50 ;
}
int F_29 ( struct V_1 * V_21 )
{
int V_5 , V_6 , V_50 = 0 , V_51 ;
T_1 * V_10 ;
struct V_3 * V_4 ;
if ( V_38 ) {
V_4 = * V_21 -> V_25 ;
if ( V_4 == V_38 )
return 0 ;
V_38 -> V_39 ++ ;
* V_21 -> V_25 = V_38 ;
if ( V_4 && ! -- V_4 -> V_39 ) {
F_17 ( V_4 ) ;
F_18 ( V_4 ) ;
}
return 0 ;
}
V_50 = F_22 ( V_21 ) ;
if ( V_50 )
return V_50 ;
V_4 = * V_21 -> V_25 ;
V_10 = V_57 ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ )
for ( V_6 = V_58 [ V_5 ] ; V_6 ; V_6 -- ) {
V_51 = F_21 ( V_4 , * ( V_10 ++ ) , V_5 ) ;
if ( V_51 )
V_50 = V_51 ;
}
if ( F_20 ( V_21 , V_4 ) ) {
V_38 = * V_21 -> V_25 ;
return V_50 ;
}
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
V_38 = V_4 ;
return V_50 ;
}
int F_30 ( struct V_1 * V_59 , struct V_1 * V_60 )
{
struct V_3 * V_10 ;
if ( ! * V_60 -> V_25 )
return - V_54 ;
if ( * V_59 -> V_25 == * V_60 -> V_25 )
return 0 ;
F_19 ( V_59 ) ;
V_10 = * V_60 -> V_25 ;
V_10 -> V_39 ++ ;
* V_59 -> V_25 = V_10 ;
return 0 ;
}
int F_31 ( struct V_1 * V_21 , T_3 V_47 , T_3 T_2 * V_61 , struct V_48 T_2 * V_49 )
{
int V_5 , V_6 , V_15 , V_46 = 0 ;
T_3 V_62 ;
T_1 * * V_16 , * V_17 ;
struct V_3 * V_4 ;
struct V_48 * V_52 ;
V_52 = F_32 ( V_47 , sizeof( struct V_48 ) , V_13 ) ;
if ( ! V_52 )
return - V_45 ;
F_11 () ;
V_62 = 0 ;
if ( * V_21 -> V_25 ) {
V_4 = * V_21 -> V_25 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( V_16 )
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
V_17 = * ( V_16 ++ ) ;
if ( V_17 )
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ , V_17 ++ ) {
if ( * V_17 >= V_12 )
continue;
if ( V_62 < V_47 ) {
V_52 [ V_62 ] . V_42 =
( V_5 << 11 ) + ( V_6 << 6 ) + V_15 ;
V_52 [ V_62 ] . V_43 = * V_17 ;
}
V_62 ++ ;
}
}
}
}
F_12 () ;
if ( F_14 ( V_49 , V_52 , F_33 ( V_62 , V_47 ) * sizeof( struct V_48 ) ) )
V_46 = - V_33 ;
F_34 ( V_62 , V_61 ) ;
F_18 ( V_52 ) ;
return V_46 ? V_46 : ( V_62 <= V_47 ) ? 0 : - V_45 ;
}
T_5 F_35 ( unsigned char V_63 )
{
unsigned short V_64 = V_9 [ V_29 ] [ V_63 ] ;
return V_64 == ( 0xf000 | V_63 ) ? V_63 : V_64 ;
}
int F_36 ( T_5 V_64 )
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
F_37 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ )
if ( F_8 ( V_5 ) && ! * V_27 [ V_5 ] . V_28 -> V_25 )
F_29 ( V_27 [ V_5 ] . V_28 ) ;
}
