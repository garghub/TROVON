static int F_1 ( struct V_1 * V_1 , unsigned char V_2 [ 2 ] [ V_3 ] )
{
unsigned char V_4 , V_5 , V_6 , V_7 ;
unsigned long V_8 ;
int V_9 [ 2 ] , V_10 [ 2 ] , V_11 [ 2 ] , V_12 , V_13 ;
V_12 = F_2 ( V_1 , V_14 ) ;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
V_11 [ V_13 ] = F_2 ( V_1 , V_15 ) ;
V_9 [ V_13 ] = V_10 [ V_13 ] = 0 ;
}
F_3 ( V_8 ) ;
F_4 ( V_1 ) ;
V_6 = F_5 ( V_1 ) >> 4 ;
do {
V_7 = V_6 ;
V_6 = F_5 ( V_1 ) >> 4 ;
for ( V_13 = 0 , V_5 = V_6 , V_4 = V_7 ; V_13 < 2 ; V_13 ++ , V_5 >>= 2 , V_4 >>= 2 ) {
if ( ~ V_5 & V_4 & 2 ) {
if ( V_11 [ V_13 ] <= 0 || V_9 [ V_13 ] >= V_3 ) continue;
V_11 [ V_13 ] = V_12 ;
if ( V_10 [ V_13 ] == 0 ) {
if ( ~ V_5 & 1 ) V_11 [ V_13 ] = 0 ;
V_2 [ V_13 ] [ V_9 [ V_13 ] ] = 0 ; V_10 [ V_13 ] ++ ; continue;
}
if ( V_10 [ V_13 ] == 9 ) {
if ( V_5 & 1 ) V_11 [ V_13 ] = 0 ;
V_10 [ V_13 ] = 0 ; V_9 [ V_13 ] ++ ; continue;
}
V_2 [ V_13 ] [ V_9 [ V_13 ] ] |= ( ~ V_5 & 1 ) << ( V_10 [ V_13 ] ++ - 1 ) ;
}
V_11 [ V_13 ] -- ;
}
} while ( V_11 [ 0 ] > 0 || V_11 [ 1 ] > 0 );
F_6 ( V_8 ) ;
return ( V_9 [ 0 ] == V_3 ) | ( ( V_9 [ 1 ] == V_3 ) << 1 ) ;
}
static int F_7 ( struct V_16 * V_17 , unsigned char * V_2 )
{
int V_9 , V_13 , V_18 ;
if ( V_2 [ V_19 ] != V_17 -> V_20 )
return - 1 ;
for ( V_9 = 0 ; V_9 < V_17 -> V_21 ; V_9 ++ ) {
if ( V_17 -> abs [ V_9 ] < 0 )
return 0 ;
F_8 ( V_17 -> V_22 , V_17 -> abs [ V_9 ] , V_2 [ V_23 [ V_9 ] ] ) ;
}
switch ( V_17 -> V_20 ) {
case V_24 :
V_9 = V_25 [ 0 ] ;
F_8 ( V_17 -> V_22 , V_26 , ( ( V_2 [ V_9 ] >> 3 ) & 1 ) - ( ( V_2 [ V_9 ] >> 1 ) & 1 ) ) ;
F_8 ( V_17 -> V_22 , V_27 , ( ( V_2 [ V_9 ] >> 2 ) & 1 ) - ( V_2 [ V_9 ] & 1 ) ) ;
break;
case V_28 :
V_9 = V_23 [ 3 ] ;
F_8 ( V_17 -> V_22 , V_26 , V_29 [ ( V_2 [ V_9 ] - 141 ) / 25 ] . V_7 ) ;
F_8 ( V_17 -> V_22 , V_27 , V_29 [ ( V_2 [ V_9 ] - 141 ) / 25 ] . V_30 ) ;
break;
}
for ( V_13 = V_18 = 0 ; V_13 < 4 ; V_13 ++ ) {
for ( V_9 = 0 ; V_9 < V_17 -> V_31 [ V_13 ] ; V_9 ++ )
F_9 ( V_17 -> V_22 , V_17 -> V_32 [ V_9 + V_18 ] ,
( ( V_2 [ V_25 [ V_13 ] ] >> ( V_9 + V_17 -> V_33 [ V_13 ] ) ) & 1 ) ) ;
V_18 += V_17 -> V_31 [ V_13 ] ;
}
F_10 ( V_17 -> V_22 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
unsigned char V_2 [ 2 ] [ V_3 ] ;
struct V_34 * V_34 = F_12 ( V_1 ) ;
unsigned char V_35 , V_36 = 0 ;
int V_9 ;
V_34 -> V_37 ++ ;
if ( ( V_35 = F_1 ( V_34 -> V_1 , V_2 ) ) != V_34 -> V_38 )
V_36 = 1 ;
else {
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
if ( V_35 & ( 1 << V_9 ) & V_34 -> V_38 ) {
if ( F_7 ( V_34 -> V_17 [ V_9 ] , V_2 [ V_9 ] ) )
V_36 = 1 ;
}
}
}
V_34 -> V_39 += V_36 ;
}
static int F_13 ( struct V_40 * V_22 )
{
struct V_34 * V_34 = F_14 ( V_22 ) ;
F_15 ( V_34 -> V_1 ) ;
return 0 ;
}
static void F_16 ( struct V_40 * V_22 )
{
struct V_34 * V_34 = F_14 ( V_22 ) ;
F_17 ( V_34 -> V_1 ) ;
}
static int F_18 ( struct V_34 * V_34 , int V_41 , unsigned char * V_2 )
{
const struct V_42 * V_43 ;
struct V_16 * V_17 ;
struct V_40 * V_40 ;
int V_9 , V_10 , V_44 = 0 ;
int V_45 ;
V_34 -> V_17 [ V_41 ] = V_17 = F_19 ( sizeof ( struct V_16 ) , V_46 ) ;
V_40 = F_20 () ;
if ( ! V_17 || ! V_40 ) {
V_45 = - V_47 ;
goto V_48;
}
V_17 -> V_20 = V_2 [ V_19 ] ;
for ( V_43 = V_49 ; V_43 -> V_50 && V_43 -> V_50 != V_17 -> V_20 ; V_43 ++ )
;
V_17 -> abs = V_43 -> V_51 ;
V_17 -> V_32 = V_43 -> V_52 ;
if ( ! V_43 -> V_50 ) {
V_17 -> V_21 = V_2 [ V_53 ] >> 4 ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
V_17 -> V_31 [ V_9 ] = V_9 < ( V_2 [ V_53 ] & 0xf ) ? 8 : 0 ;
} else {
V_17 -> V_21 = V_43 -> abs ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
V_17 -> V_31 [ V_9 ] = V_43 -> V_31 [ V_9 ] ;
}
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
V_17 -> V_33 [ V_9 ] = V_43 -> V_33 [ V_9 ] ;
snprintf ( V_17 -> V_54 , sizeof( V_17 -> V_54 ) , V_43 -> V_54 ,
V_17 -> V_21 , ( V_2 [ V_53 ] & 0xf ) << 3 , V_17 -> V_20 ) ;
snprintf ( V_17 -> V_55 , sizeof( V_17 -> V_55 ) , L_1 , V_34 -> V_1 -> V_55 , V_9 ) ;
V_17 -> V_22 = V_40 ;
V_40 -> V_54 = V_17 -> V_54 ;
V_40 -> V_55 = V_17 -> V_55 ;
V_40 -> V_50 . V_56 = V_57 ;
V_40 -> V_50 . V_58 = V_59 ;
V_40 -> V_50 . V_60 = V_43 -> V_50 ;
V_40 -> V_50 . V_61 = 0x0100 ;
V_40 -> V_22 . V_62 = & V_34 -> V_1 -> V_22 ;
F_21 ( V_40 , V_34 ) ;
V_40 -> V_63 = F_13 ;
V_40 -> V_64 = F_16 ;
V_40 -> V_65 [ 0 ] = F_22 ( V_66 ) | F_22 ( V_67 ) ;
for ( V_9 = 0 ; V_9 < V_17 -> V_21 && V_9 < V_68 ; V_9 ++ )
if ( V_17 -> abs [ V_9 ] >= 0 )
F_23 ( V_40 , V_17 -> abs [ V_9 ] , 8 , 248 , 2 , 4 ) ;
for ( V_9 = 0 ; V_9 < V_43 -> V_69 && V_9 < V_70 ; V_9 ++ )
F_23 ( V_40 , V_71 [ V_9 ] , - 1 , 1 , 0 , 0 ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_17 -> V_31 [ V_9 ] && V_10 < V_72 ; V_10 ++ )
F_24 ( V_17 -> V_32 [ V_10 + V_44 ] , V_40 -> V_73 ) ;
V_44 += V_17 -> V_31 [ V_9 ] ;
}
V_45 = F_25 ( V_17 -> V_22 ) ;
if ( V_45 )
goto V_48;
return 0 ;
V_48: F_26 ( V_40 ) ;
F_27 ( V_17 ) ;
return V_45 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_74 * V_75 )
{
unsigned char V_2 [ 2 ] [ V_3 ] ;
struct V_34 * V_34 ;
int V_9 ;
int V_45 ;
if ( ! ( V_34 = F_19 ( sizeof( struct V_34 ) , V_46 ) ) )
return - V_47 ;
V_34 -> V_1 = V_1 ;
F_29 ( V_1 , V_34 ) ;
V_45 = F_30 ( V_1 , V_75 , V_76 ) ;
if ( V_45 )
goto V_77;
if ( ! ( V_34 -> V_38 = F_1 ( V_1 , V_2 ) ) ) {
V_45 = - V_78 ;
goto V_79;
}
F_31 ( V_1 , F_11 ) ;
F_32 ( V_1 , 20 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
if ( V_34 -> V_38 & ( 1 << V_9 ) ) {
V_45 = F_18 ( V_34 , V_9 , V_2 [ V_9 ] ) ;
if ( V_45 )
goto V_80;
}
}
return 0 ;
V_80: while ( -- V_9 >= 0 ) {
if ( V_34 -> V_17 [ V_9 ] ) {
F_33 ( V_34 -> V_17 [ V_9 ] -> V_22 ) ;
F_27 ( V_34 -> V_17 [ V_9 ] ) ;
}
}
V_79: F_34 ( V_1 ) ;
V_77: F_29 ( V_1 , NULL ) ;
F_27 ( V_34 ) ;
return V_45 ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_34 * V_34 = F_12 ( V_1 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
if ( V_34 -> V_17 [ V_9 ] ) {
F_33 ( V_34 -> V_17 [ V_9 ] -> V_22 ) ;
F_27 ( V_34 -> V_17 [ V_9 ] ) ;
}
}
F_34 ( V_1 ) ;
F_29 ( V_1 , NULL ) ;
F_27 ( V_34 ) ;
}
static int T_1 F_36 ( void )
{
return F_37 ( & V_81 ) ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_81 ) ;
}
