static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned char V_5 , V_6 , V_7 , V_8 , V_9 ;
int V_10 [ 2 ] , V_11 [ 2 ] , V_12 ;
unsigned long V_13 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_3 [ V_12 ] . V_14 = - 1 ;
V_10 [ V_12 ] = F_2 ( V_4 , V_15 ) ;
V_11 [ V_12 ] = 0 ;
}
F_3 ( V_13 ) ;
F_4 ( V_4 ) ;
V_6 = V_9 = F_5 ( V_4 ) ;
do {
V_5 = V_6 ;
V_7 = V_5 ^ ( V_6 = V_8 = F_5 ( V_4 ) ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ , V_7 >>= 2 , V_8 >>= 2 ) {
V_10 [ V_12 ] -- ;
if ( ( V_7 & 0x30 ) && V_11 [ V_12 ] ) {
if ( ( V_7 & 0x30 ) < 0x30 && V_3 [ V_12 ] . V_14 < V_16 && V_10 [ V_12 ] > 0 ) {
V_3 [ V_12 ] . V_17 [ ++ V_3 [ V_12 ] . V_14 ] = V_7 ;
V_10 [ V_12 ] = F_2 ( V_4 , V_18 ) ;
} else V_10 [ V_12 ] = 0 ;
} else if ( ! ( V_8 & 0x30 ) ) V_11 [ V_12 ] = 1 ;
}
} while ( V_10 [ 0 ] > 0 || V_10 [ 1 ] > 0 );
F_6 ( V_13 ) ;
return;
}
static void F_7 ( struct V_1 * V_2 , int V_19 )
{
int V_12 ;
struct V_3 * V_3 = V_2 -> V_3 ;
V_3 [ 0 ] . V_20 = V_3 [ 1 ] . V_20 = 0 ;
if ( V_3 [ 0 ] . V_14 <= 0 || V_3 [ 1 ] . V_14 <= 0 ) return;
if ( V_3 [ 0 ] . V_17 [ 0 ] & 0x20 || ~ V_3 [ 1 ] . V_17 [ 0 ] & 0x20 ) return;
for ( V_12 = 1 ; V_12 <= V_3 [ 1 ] . V_14 ; V_12 ++ )
V_3 [ 0 ] . V_17 [ ( ( V_19 - 1 ) >> 1 ) + V_12 + 1 ] = V_3 [ 1 ] . V_17 [ V_12 ] ;
V_3 [ 0 ] . V_14 += V_3 [ 1 ] . V_14 ;
V_3 [ 1 ] . V_14 = - 1 ;
}
static inline int F_8 ( struct V_3 * V_3 , int V_21 )
{
int V_22 = 0 ;
int V_12 ;
if ( ( V_3 -> V_20 += V_21 ) > V_3 -> V_14 ) return 0 ;
for ( V_12 = 0 ; V_12 < V_21 ; V_12 ++ )
V_22 |= ( ( V_3 -> V_17 [ V_3 -> V_20 - V_12 ] >> 5 ) & 1 ) << V_12 ;
return V_22 ;
}
static int F_9 ( struct V_3 * V_3 )
{
struct V_23 * V_24 = V_3 -> V_24 ;
char * abs = V_3 -> abs ;
short * V_25 = V_3 -> V_25 ;
int V_12 , V_10 ;
if ( V_3 -> V_14 < V_3 -> V_19 || V_3 -> V_26 != ( F_8 ( V_3 , 4 ) | ( F_8 ( V_3 , 4 ) << 4 ) ) )
return - 1 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_27 ; V_12 ++ )
F_10 ( V_24 , * abs ++ , F_8 ( V_3 , 10 ) ) ;
for ( V_12 = 0 ; V_12 < V_3 -> V_28 ; V_12 ++ )
F_10 ( V_24 , * abs ++ , F_8 ( V_3 , 8 ) ) ;
for ( V_12 = 0 ; V_12 < V_3 -> V_29 && V_12 < 63 ; V_12 ++ ) {
if ( V_12 == V_3 -> V_30 ) {
V_10 = F_8 ( V_3 , 4 ) ;
F_10 ( V_24 , * abs ++ , ( ( V_10 >> 2 ) & 1 ) - ( V_10 & 1 ) ) ;
F_10 ( V_24 , * abs ++ , ( ( V_10 >> 1 ) & 1 ) - ( ( V_10 >> 3 ) & 1 ) ) ;
}
F_11 ( V_24 , * V_25 ++ , F_8 ( V_3 , 1 ) ) ;
}
for ( V_12 = 0 ; V_12 < V_3 -> V_31 ; V_12 ++ ) {
if ( ( V_10 = F_8 ( V_3 , 4 ) ) > 8 ) V_10 = 0 ;
F_10 ( V_24 , * abs ++ , V_32 [ V_10 ] . V_8 ) ;
F_10 ( V_24 , * abs ++ , V_32 [ V_10 ] . V_33 ) ;
}
for ( V_12 = 63 ; V_12 < V_3 -> V_29 ; V_12 ++ )
F_11 ( V_24 , * V_25 ++ , F_8 ( V_3 , 1 ) ) ;
F_12 ( V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_12 ;
int V_34 = 0 ;
F_1 ( V_2 ) ;
F_7 ( V_2 , V_2 -> V_3 [ 0 ] . V_19 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
if ( V_2 -> V_3 [ V_12 ] . V_19 )
V_34 |= F_9 ( V_2 -> V_3 + V_12 ) ;
return V_34 ;
}
static void F_14 ( struct V_4 * V_4 )
{
struct V_1 * V_2 = F_15 ( V_4 ) ;
V_2 -> V_35 -= F_13 ( V_2 ) ;
V_2 -> V_36 ++ ;
}
static int F_16 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
F_18 ( V_2 -> V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_17 ( V_24 ) ;
F_20 ( V_2 -> V_4 ) ;
}
static void F_21 ( struct V_4 * V_4 )
{
int V_37 [] = { 4 , - 2 , - 3 , 10 , - 6 , - 11 , - 7 , - 9 , 11 , 0 } ;
int V_12 ;
for ( V_12 = 0 ; V_37 [ V_12 ] ; V_12 ++ ) {
F_4 ( V_4 ) ;
if ( V_37 [ V_12 ] > 0 )
F_22 ( V_37 [ V_12 ] ) ;
if ( V_37 [ V_12 ] < 0 ) {
F_23 ( - V_37 [ V_12 ] ) ;
F_24 ( - V_37 [ V_12 ] * 14 ) ;
}
}
}
static void F_25 ( struct V_3 * V_3 , struct V_1 * V_2 )
{
int V_12 , V_10 ;
if ( V_3 -> V_14 < V_38 )
return;
if ( V_3 -> V_14 < ( V_10 = F_8 ( V_3 , 10 ) ) ) {
F_26 ( V_39 L_1 , V_10 , V_3 -> V_14 ) ;
return;
}
V_3 -> V_26 = F_8 ( V_3 , 4 ) | ( F_8 ( V_3 , 4 ) << 4 ) ;
if ( ( V_10 = F_8 ( V_3 , 4 ) ) & V_40 ) V_3 -> V_31 ++ ;
V_3 -> V_19 = F_8 ( V_3 , 10 ) ;
if ( V_3 -> V_19 >= V_16 || V_3 -> V_19 < V_41 ) {
F_26 ( V_39 L_2 , V_3 -> V_19 ) ;
V_3 -> V_19 = 0 ;
return;
}
V_3 -> V_28 = F_8 ( V_3 , 4 ) ;
V_3 -> V_29 = F_8 ( V_3 , 6 ) ;
if ( F_8 ( V_3 , 6 ) != 8 && V_3 -> V_31 ) {
F_26 ( V_39 L_3 ) ;
V_3 -> V_19 = 0 ;
return;
}
V_3 -> V_29 += F_8 ( V_3 , 6 ) ;
V_3 -> V_31 += F_8 ( V_3 , 4 ) ;
V_12 = F_8 ( V_3 , 4 ) ;
if ( V_10 & V_42 ) {
V_3 -> V_27 = V_3 -> V_28 - V_12 ;
V_3 -> V_28 = V_12 ;
}
V_10 = F_8 ( V_3 , 4 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ )
V_3 -> V_43 [ V_12 ] = F_8 ( V_3 , 8 ) ;
V_3 -> V_43 [ V_12 ] = 0 ;
V_10 = 8 + V_3 -> V_29 + V_3 -> V_27 * 10 + V_3 -> V_28 * 8 + V_3 -> V_31 * 4 ;
if ( V_3 -> V_19 != V_10 && V_3 -> V_19 != V_10 + ( V_10 & 1 ) ) {
F_26 ( V_39 L_4 , V_10 , V_3 -> V_19 ) ;
V_3 -> V_19 = 0 ;
return;
}
switch ( V_3 -> V_26 ) {
case V_44 :
V_3 -> V_30 = 4 ;
V_3 -> V_29 -= 4 ;
break;
case V_45 :
V_3 -> V_30 = 0 ;
V_3 -> V_29 -= 4 ;
break;
default:
V_3 -> V_30 = - 1 ;
break;
}
}
static int F_27 ( struct V_3 * V_3 , struct V_1 * V_2 , int V_46 )
{
struct V_23 * V_23 ;
char V_47 [ V_48 ] ;
int V_12 , V_10 ;
V_3 -> V_24 = V_23 = F_28 () ;
if ( ! V_23 )
return - V_49 ;
V_10 = V_3 -> V_26 < V_50 ? V_3 -> V_26 : V_50 ;
snprintf ( V_47 , V_51 , V_52 [ V_10 ] , V_3 -> V_26 ) ;
snprintf ( V_3 -> V_53 , V_48 , L_5 , V_47 , V_3 -> V_43 ) ;
snprintf ( V_3 -> V_54 , V_51 , L_6 , V_2 -> V_4 -> V_54 , V_46 ) ;
V_3 -> abs = V_55 [ V_10 ] ;
V_3 -> V_25 = V_56 [ V_10 ] ;
V_23 -> V_53 = V_3 -> V_53 ;
V_23 -> V_54 = V_3 -> V_54 ;
V_23 -> V_26 . V_57 = V_58 ;
V_23 -> V_26 . V_59 = V_60 ;
V_23 -> V_26 . V_61 = V_3 -> V_26 ;
V_23 -> V_26 . V_62 = 0x0100 ;
V_23 -> V_24 . V_63 = & V_2 -> V_4 -> V_24 ;
F_29 ( V_23 , V_2 ) ;
V_23 -> V_64 = F_16 ;
V_23 -> V_65 = F_19 ;
V_23 -> V_66 [ 0 ] = F_30 ( V_67 ) | F_30 ( V_68 ) ;
for ( V_12 = 0 ; V_12 < V_3 -> V_27 + V_3 -> V_28 + ( V_3 -> V_31 + ( V_3 -> V_30 != - 1 ) ) * 2 ; V_12 ++ )
F_31 ( V_3 -> abs [ V_12 ] , V_23 -> V_69 ) ;
for ( V_12 = 0 ; V_12 < V_3 -> V_29 ; V_12 ++ )
F_31 ( V_3 -> V_25 [ V_12 ] , V_23 -> V_70 ) ;
return 0 ;
}
static void F_32 ( struct V_3 * V_3 )
{
int V_12 , V_10 , V_8 ;
if ( ! V_3 -> V_19 )
return;
for ( V_12 = 0 ; V_12 < V_3 -> V_27 + V_3 -> V_28 + ( V_3 -> V_31 + ( V_3 -> V_30 != - 1 ) ) * 2 ; V_12 ++ ) {
V_10 = V_3 -> abs [ V_12 ] ;
V_8 = F_33 ( V_3 -> V_24 , V_10 ) ;
if ( V_10 == V_71 || V_10 == V_72 || V_3 -> V_26 == V_73 )
V_8 = V_12 < V_3 -> V_27 ? 512 : 128 ;
if ( V_12 < V_3 -> V_27 )
F_34 ( V_3 -> V_24 , V_10 , 64 , V_8 * 2 - 64 , 2 , 16 ) ;
else if ( V_12 < V_3 -> V_27 + V_3 -> V_28 )
F_34 ( V_3 -> V_24 , V_10 , 48 , V_8 * 2 - 48 , 1 , 16 ) ;
else
F_34 ( V_3 -> V_24 , V_10 , - 1 , 1 , 0 , 0 ) ;
}
}
static int F_35 ( struct V_4 * V_4 , struct V_74 * V_75 )
{
struct V_1 * V_2 ;
int V_12 ;
int V_76 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_4 = V_4 ;
F_37 ( V_4 , V_2 ) ;
V_76 = F_38 ( V_4 , V_75 , V_78 ) ;
if ( V_76 )
goto V_79;
F_21 ( V_4 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_3 [ 0 ] . V_14 >= V_80 )
F_7 ( V_2 , F_8 ( V_2 -> V_3 , 10 ) ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
F_25 ( V_2 -> V_3 + V_12 , V_2 ) ;
if ( ! V_2 -> V_3 [ V_12 ] . V_19 )
continue;
V_76 = F_27 ( V_2 -> V_3 + V_12 , V_2 , V_12 ) ;
if ( V_76 )
goto V_81;
}
if ( ! V_2 -> V_3 [ 0 ] . V_19 && ! V_2 -> V_3 [ 1 ] . V_19 ) {
V_76 = - V_82 ;
goto V_81;
}
F_39 ( V_4 , F_14 ) ;
F_40 ( V_4 , 20 ) ;
F_22 ( V_83 ) ;
if ( F_13 ( V_2 ) ) {
F_22 ( V_84 ) ;
F_13 ( V_2 ) ;
}
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
if ( V_2 -> V_3 [ V_12 ] . V_19 > 0 ) {
F_32 ( V_2 -> V_3 + V_12 ) ;
V_76 = F_41 ( V_2 -> V_3 [ V_12 ] . V_24 ) ;
if ( V_76 )
goto V_85;
}
return 0 ;
V_85: while ( -- V_12 >= 0 ) {
if ( V_2 -> V_3 [ V_12 ] . V_19 > 0 ) {
F_42 ( V_2 -> V_3 [ V_12 ] . V_24 ) ;
V_2 -> V_3 [ V_12 ] . V_24 = NULL ;
}
}
V_81: for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
if ( V_2 -> V_3 [ V_12 ] . V_24 )
F_43 ( V_2 -> V_3 [ V_12 ] . V_24 ) ;
F_44 ( V_4 ) ;
V_79: F_37 ( V_4 , NULL ) ;
F_45 ( V_2 ) ;
return V_76 ;
}
static void F_46 ( struct V_4 * V_4 )
{
int V_12 ;
struct V_1 * V_2 = F_15 ( V_4 ) ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
if ( V_2 -> V_3 [ V_12 ] . V_19 > 0 )
F_42 ( V_2 -> V_3 [ V_12 ] . V_24 ) ;
F_44 ( V_4 ) ;
F_37 ( V_4 , NULL ) ;
F_45 ( V_2 ) ;
}
