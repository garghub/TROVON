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
if ( ! F_10 ( V_32 , V_30 , V_14 ) )
return - V_33 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
unsigned char V_34 ;
F_11 ( V_34 , V_30 + V_5 ) ;
V_31 [ V_5 ] = V_35 | V_34 ;
}
F_12 () ;
memcpy ( V_9 [ V_29 ] , V_31 , sizeof( V_31 ) ) ;
F_7 () ;
F_13 () ;
return 0 ;
}
int F_14 ( unsigned char T_2 * V_30 )
{
int V_5 , V_36 ;
unsigned short * V_4 = V_9 [ V_29 ] ;
unsigned char V_37 [ V_14 ] ;
if ( ! F_10 ( V_38 , V_30 , V_14 ) )
return - V_33 ;
F_12 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
{
V_36 = F_3 ( V_27 [ V_39 ] . V_28 , V_4 [ V_5 ] ) ;
V_37 [ V_5 ] = ( V_36 & ~ 0xff ) ? 0 : V_36 ;
}
F_13 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
F_15 ( V_37 [ V_5 ] , V_30 + V_5 ) ;
return 0 ;
}
int F_16 ( T_3 T_2 * V_30 )
{
int V_5 ;
unsigned short V_31 [ V_14 ] ;
if ( ! F_10 ( V_32 , V_30 , V_14 *sizeof( unsigned short ) ) )
return - V_33 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
F_11 ( V_31 [ V_5 ] , V_30 + V_5 ) ;
F_12 () ;
memcpy ( V_9 [ V_29 ] , V_31 , sizeof( V_31 ) ) ;
F_7 () ;
F_13 () ;
return 0 ;
}
int F_17 ( T_3 T_2 * V_30 )
{
int V_5 ;
unsigned short V_37 [ V_14 ] ;
if ( ! F_10 ( V_38 , V_30 , V_14 *sizeof( unsigned short ) ) )
return - V_33 ;
F_12 () ;
memcpy ( V_37 , V_9 [ V_29 ] , sizeof( V_37 ) ) ;
F_13 () ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
F_15 ( V_37 [ V_5 ] , V_30 + V_5 ) ;
return 0 ;
}
static void F_18 ( struct V_3 * V_4 )
{
T_1 * * V_16 ;
int V_5 , V_6 ;
if ( V_4 == V_40 ) V_40 = NULL ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( V_16 != NULL ) {
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
if ( -- V_4 -> V_41 )
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
if ( ! V_10 || V_10 == V_4 || V_10 -> V_42 != V_4 -> V_42 )
continue;
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
T_1 * * V_16 , * * V_43 ;
V_16 = V_4 -> V_19 [ V_6 ] ; V_43 = V_10 -> V_19 [ V_6 ] ;
if ( ! V_16 && ! V_43 )
continue;
if ( ! V_16 || ! V_43 )
break;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ! V_16 [ V_15 ] && ! V_43 [ V_15 ] )
continue;
if ( ! V_16 [ V_15 ] || ! V_43 [ V_15 ] )
break;
if ( memcmp ( V_16 [ V_15 ] , V_43 [ V_15 ] , 64 * sizeof( T_1 ) ) )
break;
}
if ( V_15 < 32 )
break;
}
if ( V_6 == 32 ) {
V_10 -> V_41 ++ ;
* V_2 -> V_25 = V_10 ;
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
return 1 ;
}
}
return 0 ;
}
static int
F_22 ( struct V_3 * V_4 , T_4 V_44 , T_4 V_45 )
{
int V_5 , V_46 ;
T_1 * * V_16 , * V_17 ;
V_16 = V_4 -> V_19 [ V_46 = V_44 >> 11 ] ;
if ( ! V_16 ) {
V_16 = V_4 -> V_19 [ V_46 ] = F_2 ( 32 * sizeof( T_1 * ) , V_13 ) ;
if ( ! V_16 ) return - V_47 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ )
V_16 [ V_5 ] = NULL ;
}
V_17 = V_16 [ V_46 = ( V_44 >> 6 ) & 0x1f ] ;
if ( ! V_17 ) {
V_17 = V_16 [ V_46 ] = F_2 ( 64 * sizeof( T_1 ) , V_13 ) ;
if ( ! V_17 ) return - V_47 ;
memset ( V_17 , 0xff , 64 * sizeof( T_1 ) ) ;
}
V_17 [ V_44 & 0x3f ] = V_45 ;
V_4 -> V_42 += ( V_45 << 20 ) + V_44 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_21 )
{
struct V_3 * V_4 , * V_10 ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 || -- V_4 -> V_41 ) {
V_10 = F_24 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_10 ) {
if ( V_4 )
V_4 -> V_41 ++ ;
return - V_47 ;
}
V_10 -> V_41 = 1 ;
* V_21 -> V_25 = V_10 ;
} else {
if ( V_4 == V_40 ) V_40 = NULL ;
V_4 -> V_41 ++ ;
V_4 -> V_42 = 0 ;
F_18 ( V_4 ) ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_21 )
{
int V_48 ;
F_12 () ;
V_48 = F_23 ( V_21 ) ;
F_13 () ;
return V_48 ;
}
int F_26 ( struct V_1 * V_21 , T_3 V_49 , struct V_50 T_2 * V_51 )
{
int V_52 = 0 , V_53 , V_5 ;
struct V_3 * V_4 , * V_10 ;
struct V_50 * V_54 , * V_55 ;
if ( ! V_49 )
return 0 ;
V_54 = F_27 ( V_49 , sizeof( struct V_50 ) , V_13 ) ;
if ( ! V_54 )
return - V_47 ;
for ( V_5 = V_49 , V_55 = V_54 ; V_5 ; V_5 -- , V_55 ++ , V_51 ++ ) {
F_11 ( V_55 -> V_44 , & V_51 -> V_44 ) ;
F_11 ( V_55 -> V_45 , & V_51 -> V_45 ) ;
}
F_12 () ;
V_4 = * V_21 -> V_25 ;
if ( ! V_4 ) {
V_52 = - V_56 ;
goto V_57;
}
if ( V_4 -> V_41 > 1 ) {
int V_6 , V_15 ;
T_1 * * V_16 , * V_17 , V_58 ;
V_53 = F_23 ( V_21 ) ;
if ( V_53 ) {
V_52 = V_53 ;
goto V_57;
}
V_10 = * V_21 -> V_25 ;
V_58 = 0 ;
for ( V_5 = 0 ; V_5 < 32 ; V_5 ++ ) {
V_16 = V_4 -> V_19 [ V_5 ] ;
if ( V_16 )
for ( V_6 = 0 ; V_6 < 32 ; V_6 ++ ) {
V_17 = V_16 [ V_6 ] ;
if ( V_17 ) {
for ( V_15 = 0 ; V_15 < 64 ; V_15 ++ , V_58 ++ )
if ( V_17 [ V_15 ] != 0xffff ) {
V_53 = F_22 ( V_10 , V_58 , V_17 [ V_15 ] ) ;
if ( V_53 ) {
V_4 -> V_41 ++ ;
* V_21 -> V_25 = V_4 ;
F_18 ( V_10 ) ;
F_19 ( V_10 ) ;
V_52 = V_53 ;
goto V_57;
}
}
} else {
V_58 += 64 ;
}
}
else
V_58 += 32 * 64 ;
}
V_4 = V_10 ;
} else if ( V_4 == V_40 ) {
V_40 = NULL ;
}
for ( V_55 = V_54 ; V_49 ; V_49 -- , V_55 ++ ) {
V_53 = F_22 ( V_4 , V_55 -> V_44 , V_55 -> V_45 ) ;
if ( V_53 )
V_52 = V_53 ;
}
if ( F_21 ( V_21 , V_4 ) )
goto V_57;
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
V_57:
F_13 () ;
F_19 ( V_54 ) ;
return V_52 ;
}
int F_28 ( struct V_1 * V_21 )
{
int V_5 , V_6 , V_52 = 0 , V_53 ;
T_1 * V_10 ;
struct V_3 * V_4 ;
if ( V_40 ) {
V_4 = * V_21 -> V_25 ;
if ( V_4 == V_40 )
return 0 ;
V_40 -> V_41 ++ ;
* V_21 -> V_25 = V_40 ;
if ( V_4 && ! -- V_4 -> V_41 ) {
F_18 ( V_4 ) ;
F_19 ( V_4 ) ;
}
return 0 ;
}
V_52 = F_23 ( V_21 ) ;
if ( V_52 )
return V_52 ;
V_4 = * V_21 -> V_25 ;
V_10 = V_59 ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ )
for ( V_6 = V_60 [ V_5 ] ; V_6 ; V_6 -- ) {
V_53 = F_22 ( V_4 , * ( V_10 ++ ) , V_5 ) ;
if ( V_53 )
V_52 = V_53 ;
}
if ( F_21 ( V_21 , V_4 ) ) {
V_40 = * V_21 -> V_25 ;
return V_52 ;
}
for ( V_5 = 0 ; V_5 <= 3 ; V_5 ++ )
F_1 ( V_21 , V_4 , V_5 ) ;
F_4 ( V_21 , V_4 ) ;
V_40 = V_4 ;
return V_52 ;
}
int F_29 ( struct V_1 * V_61 , struct V_1 * V_62 )
{
struct V_3 * V_10 ;
if ( ! * V_62 -> V_25 )
return - V_56 ;
if ( * V_61 -> V_25 == * V_62 -> V_25 )
return 0 ;
F_20 ( V_61 ) ;
V_10 = * V_62 -> V_25 ;
V_10 -> V_41 ++ ;
* V_61 -> V_25 = V_10 ;
return 0 ;
}
int F_30 ( struct V_1 * V_21 , T_3 V_49 , T_3 T_2 * V_63 , struct V_50 T_2 * V_51 )
{
int V_5 , V_6 , V_15 ;
T_3 V_64 ;
T_1 * * V_16 , * V_17 ;
struct V_3 * V_4 ;
struct V_50 * V_54 , * V_55 ;
V_54 = F_27 ( V_49 , sizeof( struct V_50 ) , V_13 ) ;
if ( ! V_54 )
return - V_47 ;
F_12 () ;
V_64 = 0 ;
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
if ( V_64 < V_49 ) {
V_54 [ V_64 ] . V_44 =
( V_5 << 11 ) + ( V_6 << 6 ) + V_15 ;
V_54 [ V_64 ] . V_45 = * V_17 ;
}
V_64 ++ ;
}
}
}
}
F_13 () ;
for ( V_5 = F_31 ( V_64 , V_49 ) , V_55 = V_54 ; V_5 ; V_5 -- , V_51 ++ , V_55 ++ ) {
F_15 ( V_55 -> V_44 , & V_51 -> V_44 ) ;
F_15 ( V_55 -> V_45 , & V_51 -> V_45 ) ;
}
F_15 ( V_64 , V_63 ) ;
F_19 ( V_54 ) ;
return ( ( V_64 <= V_49 ) ? 0 : - V_47 ) ;
}
T_5 F_32 ( unsigned char V_65 )
{
unsigned short V_66 = V_9 [ V_29 ] [ V_65 ] ;
return V_66 == ( 0xf000 | V_65 ) ? V_65 : V_66 ;
}
int F_33 ( T_5 V_66 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < 0x100 ; V_65 ++ )
if ( V_9 [ V_29 ] [ V_65 ] == V_66 ||
( V_9 [ V_29 ] [ V_65 ] == ( V_65 | 0xf000 ) && V_66 == V_65 ) )
return V_65 ;
return - 1 ;
}
int
F_3 ( struct V_1 * V_2 , long V_67 )
{
int V_68 ;
T_1 * * V_16 , * V_17 ;
struct V_3 * V_4 ;
if ( V_67 > 0xffff )
return - 4 ;
else if ( V_67 < 0x20 )
return - 1 ;
else if ( V_67 == 0xfeff || ( V_67 >= 0x200b && V_67 <= 0x200f ) )
return - 2 ;
else if ( ( V_67 & ~ V_69 ) == V_35 )
return V_67 & V_69 ;
if ( ! * V_2 -> V_25 )
return - 3 ;
V_4 = * V_2 -> V_25 ;
if ( ( V_16 = V_4 -> V_19 [ V_67 >> 11 ] ) &&
( V_17 = V_16 [ ( V_67 >> 6 ) & 0x1f ] ) &&
( V_68 = V_17 [ V_67 & 0x3f ] ) < V_12 )
return V_68 ;
return - 4 ;
}
void T_6
F_34 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_26 ; V_5 ++ )
if ( F_8 ( V_5 ) && ! * V_27 [ V_5 ] . V_28 -> V_25 )
F_28 ( V_27 [ V_5 ] . V_28 ) ;
}
