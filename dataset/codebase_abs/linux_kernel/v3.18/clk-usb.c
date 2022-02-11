static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_4 = F_3 ( V_9 , V_10 ) ;
V_5 = ( V_4 & V_11 ) >> V_12 ;
return F_4 ( V_3 , ( V_5 + 1 ) ) ;
}
static long F_5 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
unsigned long div ;
if ( ! V_13 )
return - V_14 ;
if ( V_13 >= * V_3 )
return * V_3 ;
div = F_4 ( * V_3 , V_13 ) ;
if ( div > V_15 + 1 )
div = V_15 + 1 ;
return F_4 ( * V_3 , div ) ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_16 > 1 )
return - V_14 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_17 ;
if ( V_16 )
V_4 |= V_17 ;
F_7 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static T_2 F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_3 ( V_9 , V_10 ) & V_17 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_13 )
return - V_14 ;
div = F_4 ( V_3 , V_13 ) ;
if ( div > V_15 + 1 || ! div )
return - V_14 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_11 ;
V_4 |= ( div - 1 ) << V_12 ;
F_7 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_7 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) | V_17 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_7 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) & ~ V_17 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return ! ! ( F_3 ( V_9 , V_10 ) & V_17 ) ;
}
static struct V_18 * T_3
F_13 ( struct V_8 * V_9 , const char * V_19 ,
const char * * V_20 , T_2 V_21 )
{
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_22 V_23 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return F_15 ( - V_25 ) ;
V_23 . V_19 = V_19 ;
V_23 . V_26 = & V_27 ;
V_23 . V_20 = V_20 ;
V_23 . V_21 = V_21 ;
V_23 . V_28 = V_29 | V_30 ;
V_7 -> V_2 . V_23 = & V_23 ;
V_7 -> V_9 = V_9 ;
V_18 = F_16 ( NULL , & V_7 -> V_2 ) ;
if ( F_17 ( V_18 ) )
F_18 ( V_7 ) ;
return V_18 ;
}
static struct V_18 * T_3
F_19 ( struct V_8 * V_9 , const char * V_19 ,
const char * V_31 )
{
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_22 V_23 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return F_15 ( - V_25 ) ;
V_23 . V_19 = V_19 ;
V_23 . V_26 = & V_32 ;
V_23 . V_20 = & V_31 ;
V_23 . V_21 = 1 ;
V_23 . V_28 = V_29 ;
V_7 -> V_2 . V_23 = & V_23 ;
V_7 -> V_9 = V_9 ;
V_18 = F_16 ( NULL , & V_7 -> V_2 ) ;
if ( F_17 ( V_18 ) )
F_18 ( V_7 ) ;
return V_18 ;
}
static unsigned long F_20 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_33 * V_7 = F_21 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_4 ;
T_2 V_5 ;
V_4 = F_3 ( V_9 , V_34 ) ;
V_5 = ( V_4 & V_35 ) >> V_36 ;
if ( V_7 -> V_37 [ V_5 ] )
return V_3 / V_7 -> V_37 [ V_5 ] ;
return 0 ;
}
static long F_22 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
struct V_33 * V_7 = F_21 ( V_2 ) ;
struct V_18 * V_38 = F_23 ( V_2 -> V_18 ) ;
unsigned long V_39 = 0 ;
int V_40 = - 1 ;
unsigned long V_41 ;
int V_42 ;
int V_43 = 0 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
unsigned long V_45 ;
if ( ! V_7 -> V_37 [ V_43 ] )
continue;
V_45 = V_13 * V_7 -> V_37 [ V_43 ] ;
V_45 = F_24 ( V_38 , V_45 ) ;
V_41 = F_4 ( V_45 , V_7 -> V_37 [ V_43 ] ) ;
if ( V_41 < V_13 )
V_42 = V_13 - V_41 ;
else
V_42 = V_41 - V_13 ;
if ( V_40 < 0 || V_40 > V_42 ) {
V_39 = V_41 ;
V_40 = V_42 ;
* V_3 = V_45 ;
}
if ( ! V_40 )
break;
}
return V_39 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
int V_43 ;
struct V_33 * V_7 = F_21 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_13 )
return - V_14 ;
div = F_4 ( V_3 , V_13 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_7 -> V_37 [ V_43 ] == div ) {
V_4 = F_3 ( V_9 , V_34 ) &
~ V_35 ;
V_4 |= V_43 << V_36 ;
F_7 ( V_9 , V_34 , V_4 ) ;
return 0 ;
}
}
return - V_14 ;
}
static struct V_18 * T_3
F_26 ( struct V_8 * V_9 , const char * V_19 ,
const char * V_31 , const T_1 * V_37 )
{
struct V_33 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_22 V_23 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return F_15 ( - V_25 ) ;
V_23 . V_19 = V_19 ;
V_23 . V_26 = & V_46 ;
V_23 . V_20 = & V_31 ;
V_23 . V_21 = 1 ;
V_23 . V_28 = V_47 ;
V_7 -> V_2 . V_23 = & V_23 ;
V_7 -> V_9 = V_9 ;
memcpy ( V_7 -> V_37 , V_37 , sizeof( V_7 -> V_37 ) ) ;
V_18 = F_16 ( NULL , & V_7 -> V_2 ) ;
if ( F_17 ( V_18 ) )
F_18 ( V_7 ) ;
return V_18 ;
}
void T_3 F_27 ( struct V_48 * V_49 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
int V_43 ;
int V_21 ;
const char * V_20 [ V_50 ] ;
const char * V_19 = V_49 -> V_19 ;
V_21 = F_28 ( V_49 , L_1 , L_2 ) ;
if ( V_21 <= 0 || V_21 > V_50 )
return;
for ( V_43 = 0 ; V_43 < V_21 ; V_43 ++ ) {
V_20 [ V_43 ] = F_29 ( V_49 , V_43 ) ;
if ( ! V_20 [ V_43 ] )
return;
}
F_30 ( V_49 , L_3 , & V_19 ) ;
V_18 = F_13 ( V_9 , V_19 , V_20 , V_21 ) ;
if ( F_17 ( V_18 ) )
return;
F_31 ( V_49 , V_51 , V_18 ) ;
}
void T_3 F_32 ( struct V_48 * V_49 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
const char * V_31 ;
const char * V_19 = V_49 -> V_19 ;
V_31 = F_29 ( V_49 , 0 ) ;
if ( ! V_31 )
return;
F_30 ( V_49 , L_3 , & V_19 ) ;
V_18 = F_19 ( V_9 , V_19 , V_31 ) ;
if ( F_17 ( V_18 ) )
return;
F_31 ( V_49 , V_51 , V_18 ) ;
}
void T_3 F_33 ( struct V_48 * V_49 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
const char * V_31 ;
const char * V_19 = V_49 -> V_19 ;
T_1 V_37 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_31 = F_29 ( V_49 , 0 ) ;
if ( ! V_31 )
return;
F_34 ( V_49 , L_4 , V_37 , 4 ) ;
if ( ! V_37 [ 0 ] )
return;
F_30 ( V_49 , L_3 , & V_19 ) ;
V_18 = F_26 ( V_9 , V_19 , V_31 , V_37 ) ;
if ( F_17 ( V_18 ) )
return;
F_31 ( V_49 , V_51 , V_18 ) ;
}
