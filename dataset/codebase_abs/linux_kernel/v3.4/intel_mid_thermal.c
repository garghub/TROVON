static int F_1 ( T_1 V_1 )
{
return ( 368 * ( V_1 ) / 1000 ) - 220 ;
}
static int F_2 ( T_1 V_1 , T_1 V_2 , T_1 V_3 )
{
return ( V_1 >= V_2 ) && ( V_1 <= V_3 ) ;
}
static int F_3 ( int V_4 , T_1 V_1 , unsigned long * V_5 )
{
int V_6 ;
if ( V_4 ) {
if ( F_2 ( V_1 , V_7 , V_8 ) ) {
* V_5 = F_1 ( V_1 ) * 1000 ;
return 0 ;
}
return - V_9 ;
}
if ( ! F_2 ( V_1 , V_10 , V_11 ) )
return - V_9 ;
if ( V_1 > V_12 )
V_6 = 177 - ( V_1 / 5 ) ;
else if ( ( V_1 <= V_12 ) && ( V_1 > V_13 ) )
V_6 = 111 - ( V_1 / 8 ) ;
else if ( ( V_1 <= V_13 ) && ( V_1 > V_14 ) )
V_6 = 92 - ( V_1 / 10 ) ;
else if ( ( V_1 <= V_14 ) && ( V_1 > V_15 ) )
V_6 = 91 - ( V_1 / 10 ) ;
else
V_6 = 112 - ( V_1 / 6 ) ;
* V_5 = V_6 * 1000 ;
return 0 ;
}
static int F_4 ( struct V_16 * V_17 , unsigned long * V_6 )
{
struct V_18 * V_19 = V_17 -> V_20 ;
T_1 V_1 , V_21 ;
T_2 V_22 = 0 ;
int V_23 ;
unsigned long V_24 ;
V_21 = V_19 -> V_25 ;
V_23 = F_5 ( V_26 , V_27 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_5 ( V_26 , V_28 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_6 ( V_21 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_1 = ( V_22 << 2 ) ;
V_21 ++ ;
V_23 = F_6 ( V_21 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_22 &= 03 ;
V_1 += V_22 ;
V_23 = F_3 ( V_19 -> V_4 , V_1 , & V_24 ) ;
if ( V_23 == 0 )
* V_6 = V_19 -> V_24 = V_24 ;
return V_23 ;
}
static int F_7 ( int V_29 )
{
int V_23 ;
T_2 V_22 ;
V_23 = F_6 ( V_30 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_29 ) {
V_22 |= ( V_31 | V_32 ) ;
} else {
V_22 &= ( ~ V_32 ) ;
}
return F_5 ( V_30 , V_22 ) ;
}
static int F_8 ( T_3 V_33 )
{
int V_23 ;
V_23 = F_5 ( V_33 , V_34 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_5 ( V_33 + 1 , V_35 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_5 ( V_33 + 2 , V_36 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_5 ( V_33 + 3 ,
( V_37 | 0x10 ) ) ;
if ( V_23 )
return V_23 ;
return F_7 ( 1 ) ;
}
static int F_9 ( T_1 V_21 )
{
int V_23 ;
T_2 V_22 ;
V_23 = F_6 ( V_21 , & V_22 ) ;
if ( V_23 )
return V_23 ;
return F_5 ( V_21 , ( V_22 & 0xEF ) ) ;
}
static int F_10 ( void )
{
int V_23 ;
int V_38 ;
T_2 V_22 ;
V_23 = F_6 ( V_30 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( ( V_22 & V_31 ) == 0 )
return 0 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_23 = F_6 ( V_40 + V_38 , & V_22 ) ;
if ( V_23 )
return V_23 ;
if ( V_22 & V_41 ) {
V_23 = V_38 ;
break;
}
}
return ( V_23 > V_42 ) ? ( - V_43 ) : V_23 ;
}
static int F_11 ( struct V_44 * V_45 )
{
T_4 V_22 ;
T_3 V_33 ;
int V_23 ;
V_23 = F_6 ( V_26 , & V_22 ) ;
if ( V_23 )
return V_23 ;
V_22 &= ~ V_46 ;
V_23 = F_5 ( V_26 , V_22 ) ;
if ( V_23 )
return V_23 ;
V_47 = F_10 () ;
if ( V_47 < 0 ) {
F_12 ( V_45 , L_1 ) ;
return V_47 ;
}
V_33 = V_40 + V_47 ;
if ( ! ( V_47 == 0 || V_47 == V_42 ) ) {
V_23 = F_9 ( V_33 ) ;
if ( V_23 )
return V_23 ;
V_33 ++ ;
V_47 ++ ;
}
V_23 = F_8 ( V_33 ) ;
if ( V_23 ) {
F_12 ( V_45 , L_2 ) ;
return V_23 ;
}
F_13 ( V_45 , L_3 ) ;
return V_23 ;
}
static struct V_18 * F_14 ( int V_48 )
{
struct V_18 * V_19 =
F_15 ( sizeof( struct V_18 ) , V_49 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_25 = V_50 + 2 * ( V_47 + V_48 ) ;
if ( V_48 == 3 )
V_19 -> V_4 = 1 ;
return V_19 ;
}
static int F_16 ( struct V_51 * V_52 )
{
return F_11 ( & V_52 -> V_45 ) ;
}
static int F_17 ( struct V_51 * V_52 , T_5 V_53 )
{
return F_7 ( 0 ) ;
}
static int F_18 ( struct V_16 * V_17 , unsigned long * V_6 )
{
F_19 ( V_17 == NULL ) ;
return F_4 ( V_17 , V_6 ) ;
}
static int F_20 ( struct V_51 * V_52 )
{
static char * V_54 [ V_55 ] = {
L_4 , L_5 , L_6 , L_7
} ;
int V_23 ;
int V_38 ;
struct V_56 * V_57 ;
V_57 = F_15 ( sizeof( struct V_56 ) , V_49 ) ;
if ( ! V_57 )
return - V_58 ;
V_23 = F_11 ( & V_52 -> V_45 ) ;
if ( V_23 ) {
F_12 ( & V_52 -> V_45 , L_8 ) ;
F_21 ( V_57 ) ;
return V_23 ;
}
for ( V_38 = 0 ; V_38 < V_55 ; V_38 ++ ) {
struct V_18 * V_19 = F_14 ( V_38 ) ;
if ( ! V_19 ) {
V_23 = - V_58 ;
goto V_59;
}
V_57 -> V_17 [ V_38 ] = F_22 ( V_54 [ V_38 ] ,
0 , V_19 , & V_60 , 0 , 0 , 0 , 0 ) ;
if ( F_23 ( V_57 -> V_17 [ V_38 ] ) ) {
F_21 ( V_19 ) ;
V_23 = F_24 ( V_57 -> V_17 [ V_38 ] ) ;
goto V_59;
}
}
V_57 -> V_52 = V_52 ;
F_25 ( V_52 , V_57 ) ;
return 0 ;
V_59:
while ( -- V_38 >= 0 ) {
F_21 ( V_57 -> V_17 [ V_38 ] -> V_20 ) ;
F_26 ( V_57 -> V_17 [ V_38 ] ) ;
}
F_7 ( 0 ) ;
F_21 ( V_57 ) ;
return V_23 ;
}
static int F_27 ( struct V_51 * V_52 )
{
int V_38 ;
struct V_56 * V_57 = F_28 ( V_52 ) ;
for ( V_38 = 0 ; V_38 < V_55 ; V_38 ++ ) {
F_21 ( V_57 -> V_17 [ V_38 ] -> V_20 ) ;
F_26 ( V_57 -> V_17 [ V_38 ] ) ;
}
F_21 ( V_57 ) ;
F_25 ( V_52 , NULL ) ;
return F_7 ( 0 ) ;
}
