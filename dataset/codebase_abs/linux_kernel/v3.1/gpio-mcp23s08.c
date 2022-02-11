static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
return F_4 ( V_2 -> V_4 , V_3 , V_5 ) ;
}
static int
F_5 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
while ( V_7 -- ) {
int V_8 = F_1 ( V_2 , V_3 ++ ) ;
if ( V_8 < 0 )
return V_8 ;
* V_6 ++ = V_8 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_7 ( V_2 -> V_4 , V_3 << 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
return F_9 ( V_2 -> V_4 , V_3 << 1 , V_5 ) ;
}
static int
F_10 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
while ( V_7 -- ) {
int V_8 = F_6 ( V_2 , V_3 ++ ) ;
if ( V_8 < 0 )
return V_8 ;
* V_6 ++ = V_8 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_9 [ 2 ] , V_10 [ 1 ] ;
int V_11 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 , V_10 , sizeof V_10 ) ;
return ( V_11 < 0 ) ? V_11 : V_10 [ 0 ] ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
T_2 V_9 [ 3 ] ;
V_9 [ 0 ] = V_2 -> V_12 ;
V_9 [ 1 ] = V_3 ;
V_9 [ 2 ] = V_5 ;
return F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 , NULL , 0 ) ;
}
static int
F_14 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
T_2 V_9 [ 2 ] , * V_13 ;
int V_11 ;
if ( ( V_7 + V_3 ) > sizeof V_2 -> V_14 )
return - V_15 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 ;
V_13 = ( T_2 * ) V_6 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 , V_13 , V_7 ) ;
if ( V_11 >= 0 ) {
while ( V_7 -- )
V_6 [ V_7 ] = V_13 [ V_7 ] ;
}
return V_11 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 )
{
T_2 V_9 [ 2 ] , V_10 [ 2 ] ;
int V_11 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 << 1 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 , V_10 , sizeof V_10 ) ;
return ( V_11 < 0 ) ? V_11 : ( V_10 [ 0 ] | ( V_10 [ 1 ] << 8 ) ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
T_2 V_9 [ 4 ] ;
V_9 [ 0 ] = V_2 -> V_12 ;
V_9 [ 1 ] = V_3 << 1 ;
V_9 [ 2 ] = V_5 ;
V_9 [ 3 ] = V_5 >> 8 ;
return F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 , NULL , 0 ) ;
}
static int
F_17 ( struct V_1 * V_2 , unsigned V_3 , T_1 * V_6 , unsigned V_7 )
{
T_2 V_9 [ 2 ] ;
int V_11 ;
if ( ( V_7 + V_3 ) > sizeof V_2 -> V_14 )
return - V_15 ;
V_9 [ 0 ] = V_2 -> V_12 | 0x01 ;
V_9 [ 1 ] = V_3 << 1 ;
V_11 = F_12 ( V_2 -> V_4 , V_9 , sizeof V_9 ,
( T_2 * ) V_6 , V_7 * 2 ) ;
if ( V_11 >= 0 ) {
while ( V_7 -- )
V_6 [ V_7 ] = F_18 ( ( V_16 ) V_6 [ V_7 ] ) ;
}
return V_11 ;
}
static int F_19 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_14 [ V_21 ] |= ( 1 << V_19 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_21 , V_2 -> V_14 [ V_21 ] ) ;
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static int F_23 ( struct V_17 * V_18 , unsigned V_19 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_11 = V_2 -> V_22 -> V_24 ( V_2 , V_25 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
else {
V_2 -> V_14 [ V_25 ] = V_11 ;
V_11 = ! ! ( V_11 & ( 1 << V_19 ) ) ;
}
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_26 , int V_27 )
{
unsigned V_28 = V_2 -> V_14 [ V_29 ] ;
if ( V_27 )
V_28 |= V_26 ;
else
V_28 &= ~ V_26 ;
V_2 -> V_14 [ V_29 ] = V_28 ;
return V_2 -> V_22 -> V_23 ( V_2 , V_29 , V_28 ) ;
}
static void F_25 ( struct V_17 * V_18 , unsigned V_19 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
unsigned V_26 = 1 << V_19 ;
F_21 ( & V_2 -> V_20 ) ;
F_24 ( V_2 , V_26 , V_27 ) ;
F_22 ( & V_2 -> V_20 ) ;
}
static int
F_26 ( struct V_17 * V_18 , unsigned V_19 , int V_27 )
{
struct V_1 * V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
unsigned V_26 = 1 << V_19 ;
int V_11 ;
F_21 ( & V_2 -> V_20 ) ;
V_11 = F_24 ( V_2 , V_26 , V_27 ) ;
if ( V_11 == 0 ) {
V_2 -> V_14 [ V_21 ] &= ~ V_26 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_21 , V_2 -> V_14 [ V_21 ] ) ;
}
F_22 ( & V_2 -> V_20 ) ;
return V_11 ;
}
static void F_27 ( struct V_30 * V_31 , struct V_17 * V_18 )
{
struct V_1 * V_2 ;
char V_32 ;
int V_33 ;
unsigned V_26 ;
V_2 = F_20 ( V_18 , struct V_1 , V_18 ) ;
V_32 = '0' + ( ( V_2 -> V_12 >> 1 ) & 0x7 ) ;
F_21 ( & V_2 -> V_20 ) ;
V_33 = V_2 -> V_22 -> V_34 ( V_2 , 0 , V_2 -> V_14 , F_28 ( V_2 -> V_14 ) ) ;
if ( V_33 < 0 ) {
F_29 ( V_31 , L_1 , V_33 ) ;
goto V_35;
}
for ( V_33 = 0 , V_26 = 1 ; V_33 < V_18 -> V_36 ; V_33 ++ , V_26 <<= 1 ) {
const char * V_37 ;
V_37 = F_30 ( V_18 , V_33 ) ;
if ( ! V_37 )
continue;
F_29 ( V_31 , L_2 ,
V_18 -> V_38 + V_33 , V_32 , V_33 , V_37 ,
( V_2 -> V_14 [ V_21 ] & V_26 ) ? L_3 : L_4 ,
( V_2 -> V_14 [ V_25 ] & V_26 ) ? L_5 : L_6 ,
( V_2 -> V_14 [ V_39 ] & V_26 ) ? L_7 : L_8 ) ;
F_29 ( V_31 , L_9 ) ;
}
V_35:
F_22 ( & V_2 -> V_20 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_40 * V_41 ,
void * V_4 , unsigned V_12 ,
unsigned type , unsigned V_38 , unsigned V_42 )
{
int V_11 ;
F_32 ( & V_2 -> V_20 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_18 . V_43 = F_19 ;
V_2 -> V_18 . V_44 = F_23 ;
V_2 -> V_18 . V_45 = F_26 ;
V_2 -> V_18 . V_46 = F_25 ;
V_2 -> V_18 . V_47 = F_27 ;
switch ( type ) {
#ifdef F_33
case V_48 :
V_2 -> V_22 = & V_49 ;
V_2 -> V_18 . V_36 = 8 ;
V_2 -> V_18 . V_37 = L_10 ;
break;
case V_50 :
V_2 -> V_22 = & V_51 ;
V_2 -> V_18 . V_36 = 16 ;
V_2 -> V_18 . V_37 = L_11 ;
break;
#endif
#ifdef F_34
case V_52 :
V_2 -> V_22 = & V_53 ;
V_2 -> V_18 . V_36 = 8 ;
V_2 -> V_18 . V_37 = L_12 ;
break;
case V_54 :
V_2 -> V_22 = & V_55 ;
V_2 -> V_18 . V_36 = 16 ;
V_2 -> V_18 . V_37 = L_13 ;
break;
#endif
default:
F_35 ( V_41 , L_14 , type ) ;
return - V_15 ;
}
V_2 -> V_18 . V_38 = V_38 ;
V_2 -> V_18 . V_56 = 1 ;
V_2 -> V_18 . V_41 = V_41 ;
V_2 -> V_18 . V_57 = V_58 ;
V_11 = V_2 -> V_22 -> V_24 ( V_2 , V_59 ) ;
if ( V_11 < 0 )
goto V_60;
if ( ( V_11 & V_61 ) || ! ( V_11 & V_62 ) ) {
V_11 &= ~ ( V_61 | ( V_61 << 8 ) ) ;
V_11 |= V_62 | ( V_62 << 8 ) ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_59 , V_11 ) ;
if ( V_11 < 0 )
goto V_60;
}
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_39 , V_42 ) ;
if ( V_11 < 0 )
goto V_60;
V_11 = V_2 -> V_22 -> V_34 ( V_2 , 0 , V_2 -> V_14 , F_28 ( V_2 -> V_14 ) ) ;
if ( V_11 < 0 )
goto V_60;
if ( V_2 -> V_14 [ V_63 ] != 0 ) {
V_2 -> V_14 [ V_63 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_63 , 0 ) ;
if ( V_11 < 0 )
goto V_60;
}
if ( V_2 -> V_14 [ V_64 ] != 0 ) {
V_2 -> V_14 [ V_64 ] = 0 ;
V_11 = V_2 -> V_22 -> V_23 ( V_2 , V_64 , 0 ) ;
if ( V_11 < 0 )
goto V_60;
}
V_11 = F_36 ( & V_2 -> V_18 ) ;
V_60:
if ( V_11 < 0 )
F_37 ( V_41 , L_15 ,
V_12 , V_11 ) ;
return V_11 ;
}
static int T_3 F_38 ( struct V_65 * V_66 ,
const struct V_67 * V_68 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 ;
int V_11 ;
V_70 = V_66 -> V_41 . V_71 ;
if ( ! V_70 || ! F_39 ( V_70 -> V_38 ) ) {
F_37 ( & V_66 -> V_41 , L_16 ) ;
return - V_15 ;
}
V_2 = F_40 ( sizeof *V_2 , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_11 = F_31 ( V_2 , & V_66 -> V_41 , V_66 , V_66 -> V_12 ,
V_68 -> V_74 , V_70 -> V_38 ,
V_70 -> V_18 [ 0 ] . V_42 ) ;
if ( V_11 )
goto V_60;
F_41 ( V_66 , V_2 ) ;
return 0 ;
V_60:
F_42 ( V_2 ) ;
return V_11 ;
}
static int T_4 F_43 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = F_44 ( V_66 ) ;
int V_11 ;
V_11 = F_45 ( & V_2 -> V_18 ) ;
if ( V_11 == 0 )
F_42 ( V_2 ) ;
return V_11 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_75 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_75 ) ;
}
static int T_5 F_46 ( void ) { return 0 ; }
static void F_48 ( void ) { }
static int F_50 ( struct V_76 * V_77 )
{
struct V_69 * V_70 ;
unsigned V_12 ;
unsigned V_78 = 0 ;
struct V_79 * V_4 ;
int V_11 , type ;
unsigned V_38 ;
type = F_51 ( V_77 ) -> V_74 ;
V_70 = V_77 -> V_41 . V_71 ;
if ( ! V_70 || ! F_39 ( V_70 -> V_38 ) ) {
F_37 ( & V_77 -> V_41 , L_16 ) ;
return - V_15 ;
}
for ( V_12 = 0 ; V_12 < F_28 ( V_70 -> V_18 ) ; V_12 ++ ) {
if ( ! V_70 -> V_18 [ V_12 ] . V_80 )
continue;
V_78 ++ ;
if ( ( type == V_48 ) && ( V_12 > 3 ) ) {
F_35 ( & V_77 -> V_41 ,
L_17 ) ;
return - V_15 ;
}
}
if ( ! V_78 )
return - V_81 ;
V_4 = F_40 ( sizeof *V_4 + V_78 * sizeof( struct V_1 ) ,
V_72 ) ;
if ( ! V_4 )
return - V_73 ;
F_52 ( V_77 , V_4 ) ;
V_38 = V_70 -> V_38 ;
for ( V_12 = 0 ; V_12 < F_28 ( V_70 -> V_18 ) ; V_12 ++ ) {
if ( ! V_70 -> V_18 [ V_12 ] . V_80 )
continue;
V_78 -- ;
V_4 -> V_2 [ V_12 ] = & V_4 -> V_18 [ V_78 ] ;
V_11 = F_31 ( V_4 -> V_2 [ V_12 ] , & V_77 -> V_41 , V_77 ,
0x40 | ( V_12 << 1 ) , type , V_38 ,
V_70 -> V_18 [ V_12 ] . V_42 ) ;
if ( V_11 < 0 )
goto V_60;
V_38 += ( type == V_50 ) ? 16 : 8 ;
}
V_4 -> V_36 = V_38 - V_70 -> V_38 ;
return 0 ;
V_60:
for ( V_12 = 0 ; V_12 < F_28 ( V_4 -> V_2 ) ; V_12 ++ ) {
int V_13 ;
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
V_13 = F_45 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
if ( V_13 < 0 )
F_35 ( & V_77 -> V_41 , L_18 , L_19 , V_13 ) ;
}
F_42 ( V_4 ) ;
return V_11 ;
}
static int F_53 ( struct V_76 * V_77 )
{
struct V_79 * V_4 = F_54 ( V_77 ) ;
unsigned V_12 ;
int V_11 = 0 ;
for ( V_12 = 0 ; V_12 < F_28 ( V_4 -> V_2 ) ; V_12 ++ ) {
int V_13 ;
if ( ! V_4 -> V_2 [ V_12 ] )
continue;
V_13 = F_45 ( & V_4 -> V_2 [ V_12 ] -> V_18 ) ;
if ( V_13 < 0 ) {
F_35 ( & V_77 -> V_41 , L_18 , L_19 , V_13 ) ;
V_11 = V_13 ;
}
}
if ( V_11 == 0 )
F_42 ( V_4 ) ;
return V_11 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_82 ) ;
}
static void F_57 ( void )
{
F_58 ( & V_82 ) ;
}
static int T_5 F_55 ( void ) { return 0 ; }
static void F_57 ( void ) { }
static int T_5 F_59 ( void )
{
int V_8 ;
V_8 = F_55 () ;
if ( V_8 )
goto V_83;
V_8 = F_46 () ;
if ( V_8 )
goto V_84;
return 0 ;
V_84:
F_57 () ;
V_83:
return V_8 ;
}
static void T_6 F_60 ( void )
{
F_57 () ;
F_48 () ;
}
