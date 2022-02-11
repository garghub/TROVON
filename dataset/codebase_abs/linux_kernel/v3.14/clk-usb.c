static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_4 = F_3 ( V_9 , V_10 ) ;
V_5 = ( V_4 & V_11 ) >> V_12 ;
return V_3 / ( V_5 + 1 ) ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
unsigned long div ;
unsigned long V_14 ;
unsigned long V_4 ;
if ( V_13 >= * V_3 )
return * V_3 ;
div = * V_3 / V_13 ;
if ( div >= V_15 )
return * V_3 / ( V_15 + 1 ) ;
V_14 = * V_3 / div ;
V_4 = * V_3 / ( div + 1 ) ;
if ( V_14 - V_13 > V_13 - V_4 )
V_14 = V_4 ;
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_16 > 1 )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_18 ;
if ( V_16 )
V_4 |= V_18 ;
F_6 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_3 ( V_9 , V_10 ) & V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div = V_3 / V_13 ;
if ( V_3 % V_13 || div < 1 || div >= V_15 )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_11 ;
V_4 |= ( div - 1 ) << V_12 ;
F_6 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_6 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) | V_18 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_6 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) & ~ V_18 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return ! ! ( F_3 ( V_9 , V_10 ) & V_18 ) ;
}
static struct V_19 * T_3
F_12 ( struct V_8 * V_9 , const char * V_20 ,
const char * * V_21 , T_2 V_22 )
{
struct V_6 * V_7 ;
struct V_19 * V_19 = NULL ;
struct V_23 V_24 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return F_14 ( - V_26 ) ;
V_24 . V_20 = V_20 ;
V_24 . V_27 = & V_28 ;
V_24 . V_21 = V_21 ;
V_24 . V_22 = V_22 ;
V_24 . V_29 = V_30 | V_31 ;
V_7 -> V_2 . V_24 = & V_24 ;
V_7 -> V_9 = V_9 ;
V_19 = F_15 ( NULL , & V_7 -> V_2 ) ;
if ( F_16 ( V_19 ) )
F_17 ( V_7 ) ;
return V_19 ;
}
static struct V_19 * T_3
F_18 ( struct V_8 * V_9 , const char * V_20 ,
const char * V_32 )
{
struct V_6 * V_7 ;
struct V_19 * V_19 = NULL ;
struct V_23 V_24 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return F_14 ( - V_26 ) ;
V_24 . V_20 = V_20 ;
V_24 . V_27 = & V_33 ;
V_24 . V_21 = & V_32 ;
V_24 . V_22 = 1 ;
V_24 . V_29 = V_30 ;
V_7 -> V_2 . V_24 = & V_24 ;
V_7 -> V_9 = V_9 ;
V_19 = F_15 ( NULL , & V_7 -> V_2 ) ;
if ( F_16 ( V_19 ) )
F_17 ( V_7 ) ;
return V_19 ;
}
static unsigned long F_19 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_34 * V_7 = F_20 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_4 ;
T_2 V_5 ;
V_4 = F_3 ( V_9 , V_35 ) ;
V_5 = ( V_4 & V_36 ) >> V_37 ;
if ( V_7 -> V_38 [ V_5 ] )
return V_3 / V_7 -> V_38 [ V_5 ] ;
return 0 ;
}
static long F_21 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
struct V_34 * V_7 = F_20 ( V_2 ) ;
unsigned long V_14 = 0 ;
int V_39 = - 1 ;
unsigned long V_40 ;
int V_41 ;
int V_42 = 0 ;
for ( V_42 = 0 ; V_42 < 4 ; V_42 ++ ) {
if ( ! V_7 -> V_38 [ V_42 ] )
continue;
V_40 = * V_3 / V_7 -> V_38 [ V_42 ] ;
if ( V_40 < V_13 )
V_41 = V_13 - V_40 ;
else
V_41 = V_40 - V_13 ;
if ( V_39 < 0 || V_39 > V_41 ) {
V_14 = V_40 ;
V_39 = V_41 ;
}
if ( ! V_39 )
break;
}
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
int V_42 ;
struct V_34 * V_7 = F_20 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div = V_3 / V_13 ;
if ( V_3 % V_13 )
return - V_17 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_7 -> V_38 [ V_42 ] == div ) {
V_4 = F_3 ( V_9 , V_35 ) &
~ V_36 ;
V_4 |= V_42 << V_37 ;
F_6 ( V_9 , V_35 , V_4 ) ;
return 0 ;
}
}
return - V_17 ;
}
static struct V_19 * T_3
F_23 ( struct V_8 * V_9 , const char * V_20 ,
const char * V_32 , const T_1 * V_38 )
{
struct V_34 * V_7 ;
struct V_19 * V_19 = NULL ;
struct V_23 V_24 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return F_14 ( - V_26 ) ;
V_24 . V_20 = V_20 ;
V_24 . V_27 = & V_44 ;
V_24 . V_21 = & V_32 ;
V_24 . V_22 = 1 ;
V_24 . V_29 = 0 ;
V_7 -> V_2 . V_24 = & V_24 ;
V_7 -> V_9 = V_9 ;
memcpy ( V_7 -> V_38 , V_38 , sizeof( V_7 -> V_38 ) ) ;
V_19 = F_15 ( NULL , & V_7 -> V_2 ) ;
if ( F_16 ( V_19 ) )
F_17 ( V_7 ) ;
return V_19 ;
}
void T_3 F_24 ( struct V_45 * V_46 ,
struct V_8 * V_9 )
{
struct V_19 * V_19 ;
int V_42 ;
int V_22 ;
const char * V_21 [ V_47 ] ;
const char * V_20 = V_46 -> V_20 ;
V_22 = F_25 ( V_46 , L_1 , L_2 ) ;
if ( V_22 <= 0 || V_22 > V_47 )
return;
for ( V_42 = 0 ; V_42 < V_22 ; V_42 ++ ) {
V_21 [ V_42 ] = F_26 ( V_46 , V_42 ) ;
if ( ! V_21 [ V_42 ] )
return;
}
F_27 ( V_46 , L_3 , & V_20 ) ;
V_19 = F_12 ( V_9 , V_20 , V_21 , V_22 ) ;
if ( F_16 ( V_19 ) )
return;
F_28 ( V_46 , V_48 , V_19 ) ;
}
void T_3 F_29 ( struct V_45 * V_46 ,
struct V_8 * V_9 )
{
struct V_19 * V_19 ;
const char * V_32 ;
const char * V_20 = V_46 -> V_20 ;
V_32 = F_26 ( V_46 , 0 ) ;
if ( ! V_32 )
return;
F_27 ( V_46 , L_3 , & V_20 ) ;
V_19 = F_18 ( V_9 , V_20 , V_32 ) ;
if ( F_16 ( V_19 ) )
return;
F_28 ( V_46 , V_48 , V_19 ) ;
}
void T_3 F_30 ( struct V_45 * V_46 ,
struct V_8 * V_9 )
{
struct V_19 * V_19 ;
const char * V_32 ;
const char * V_20 = V_46 -> V_20 ;
T_1 V_38 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_32 = F_26 ( V_46 , 0 ) ;
if ( ! V_32 )
return;
F_31 ( V_46 , L_4 , V_38 , 4 ) ;
if ( ! V_38 [ 0 ] )
return;
F_27 ( V_46 , L_3 , & V_20 ) ;
V_19 = F_23 ( V_9 , V_20 , V_32 , V_38 ) ;
if ( F_16 ( V_19 ) )
return;
F_28 ( V_46 , V_48 , V_19 ) ;
}
