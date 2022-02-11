static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
T_1 V_4 ;
V_4 = ( F_3 ( clock -> V_5 ) & ~ ( V_6 | V_7 ) )
| F_4 ( clock -> div - 1 ) ;
F_5 ( V_4 , clock -> V_5 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
T_1 V_4 ;
V_4 = F_3 ( clock -> V_5 ) ;
V_4 |= V_7 ;
if ( ! ( V_4 & V_6 ) )
V_4 |= V_6 ;
F_5 ( V_4 , clock -> V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
return ! ( F_3 ( clock -> V_5 ) & V_7 ) ;
}
static unsigned long F_8 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = ( F_3 ( clock -> V_5 ) & V_6 ) + 1 ;
return V_8 / div ;
}
static unsigned int F_9 ( unsigned long V_9 ,
unsigned long V_8 )
{
unsigned int div ;
if ( ! V_9 )
V_9 = 1 ;
div = F_10 ( V_8 , V_9 ) ;
return F_11 (unsigned int, div, 1 , 64 ) ;
}
static long F_12 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_8 )
{
unsigned int div = F_9 ( V_9 , * V_8 ) ;
return * V_8 / div ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_8 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int div = F_9 ( V_9 , V_8 ) ;
T_1 V_4 ;
clock -> div = div ;
V_4 = F_3 ( clock -> V_5 ) & ~ V_6 ;
if ( ! ( V_4 & V_7 ) )
F_5 ( V_4 | F_4 ( clock -> div - 1 ) , clock -> V_5 ) ;
return 0 ;
}
static T_2 F_14 ( struct V_1 * V_2 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
unsigned int V_10 ;
T_2 V_11 ;
if ( clock -> V_12 == 0 )
return 0 ;
V_11 = ( F_3 ( clock -> V_5 ) >> clock -> V_13 ) &
( F_15 ( clock -> V_12 ) - 1 ) ;
for ( V_10 = 0 ; V_10 < F_16 ( V_2 ) ; V_10 ++ ) {
if ( clock -> V_14 [ V_10 ] == V_11 )
return V_10 ;
}
F_17 ( L_1 ,
V_15 , F_18 ( V_2 ) , V_11 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_16 )
{
struct V_3 * clock = F_2 ( V_2 ) ;
T_2 V_11 ;
T_1 V_17 ;
if ( V_16 >= F_16 ( V_2 ) )
return - V_18 ;
V_17 = ~ ( ( F_15 ( clock -> V_12 ) - 1 ) << clock -> V_13 ) ;
V_11 = clock -> V_14 [ V_16 ] ;
F_5 ( ( F_3 ( clock -> V_5 ) & V_17 ) |
( V_11 << clock -> V_13 ) , clock -> V_5 ) ;
return 0 ;
}
struct V_19 * T_3 F_20 ( const char * V_20 ,
unsigned int V_21 ,
const char * * V_22 ,
void T_4 * V_5 )
{
unsigned int V_23 ;
struct V_24 V_25 ;
struct V_3 * clock ;
struct V_19 * V_19 ;
unsigned int V_10 ;
clock = F_21 ( sizeof( * clock ) , V_26 ) ;
if ( ! clock )
return F_22 ( - V_27 ) ;
clock -> V_14 = F_23 ( V_21 , sizeof( * clock -> V_14 ) ,
V_26 ) ;
if ( ! clock -> V_14 ) {
V_19 = F_22 ( - V_27 ) ;
goto V_28;
}
clock -> V_5 = V_5 ;
clock -> div = ( F_3 ( clock -> V_5 ) & V_6 ) + 1 ;
switch ( V_21 ) {
case 1 :
clock -> V_13 = clock -> V_12 = 0 ;
break;
case 4 :
clock -> V_13 = 6 ;
clock -> V_12 = 2 ;
break;
case 8 :
clock -> V_13 = 12 ;
clock -> V_12 = 3 ;
break;
default:
F_17 ( L_2 ,
V_15 , V_20 ) ;
V_19 = F_22 ( - V_18 ) ;
goto V_29;
}
for ( V_10 = 0 , V_23 = 0 ; V_10 < V_21 ; V_10 ++ ) {
if ( V_22 [ V_10 ] ) {
V_22 [ V_23 ] = V_22 [ V_10 ] ;
clock -> V_14 [ V_23 ] = V_10 ;
V_23 ++ ;
}
}
V_25 . V_20 = V_20 ;
V_25 . V_30 = & V_31 ;
V_25 . V_32 = V_33 ;
V_25 . V_22 = V_22 ;
V_25 . V_21 = V_23 ;
clock -> V_2 . V_25 = & V_25 ;
V_19 = F_24 ( NULL , & clock -> V_2 ) ;
if ( F_25 ( V_19 ) )
goto V_29;
return V_19 ;
V_29:
F_26 ( clock -> V_14 ) ;
V_28:
F_26 ( clock ) ;
return V_19 ;
}
static void T_3 F_27 ( struct V_34 * V_35 )
{
unsigned int V_21 ;
const char * * V_22 ;
const char * V_36 = V_35 -> V_20 ;
void T_4 * V_5 ;
struct V_19 * V_19 ;
unsigned int V_10 ;
V_21 = F_28 ( V_35 ) ;
if ( V_21 < 1 ) {
F_17 ( L_3 ,
V_15 , V_35 -> V_20 ) ;
return;
}
V_22 = F_23 ( V_21 , sizeof( * V_22 ) ,
V_26 ) ;
if ( ! V_22 )
return;
V_5 = F_29 ( V_35 , 0 ) ;
if ( V_5 == NULL ) {
F_17 ( L_4 ,
V_15 , V_35 -> V_20 ) ;
goto error;
}
F_30 ( V_35 , L_5 , & V_36 ) ;
for ( V_10 = 0 ; V_10 < V_21 ; V_10 ++ )
V_22 [ V_10 ] = F_31 ( V_35 , V_10 ) ;
V_19 = F_20 ( V_36 , V_21 , V_22 , V_5 ) ;
if ( F_25 ( V_19 ) ) {
F_17 ( L_6 ,
V_15 , V_35 -> V_20 , F_32 ( V_19 ) ) ;
goto error;
}
F_33 ( V_35 , V_37 , V_19 ) ;
F_26 ( V_22 ) ;
return;
error:
if ( V_5 )
F_34 ( V_5 ) ;
F_26 ( V_22 ) ;
}
