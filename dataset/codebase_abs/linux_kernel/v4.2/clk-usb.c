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
static long F_5 ( struct V_1 * V_2 ,
unsigned long V_13 ,
unsigned long V_14 ,
unsigned long V_15 ,
unsigned long * V_16 ,
struct V_1 * * V_17 )
{
struct V_18 * V_19 = NULL ;
long V_20 = - V_21 ;
unsigned long V_22 ;
int V_23 = - 1 ;
int V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_6 ( V_2 -> V_18 ) ; V_25 ++ ) {
int div ;
V_19 = F_7 ( V_2 -> V_18 , V_25 ) ;
if ( ! V_19 )
continue;
for ( div = 1 ; div < V_26 + 2 ; div ++ ) {
unsigned long V_27 ;
V_27 = V_13 * div ;
V_27 = F_8 ( V_19 ,
V_27 ) ;
V_22 = F_4 ( V_27 , div ) ;
if ( V_22 < V_13 )
V_24 = V_13 - V_22 ;
else
V_24 = V_22 - V_13 ;
if ( V_23 < 0 || V_23 > V_24 ) {
V_20 = V_22 ;
V_23 = V_24 ;
* V_16 = V_27 ;
* V_17 = F_9 ( V_19 ) ;
}
if ( ! V_23 || V_22 < V_13 )
break;
}
if ( ! V_23 )
break;
}
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_28 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_28 > 1 )
return - V_21 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_29 ;
if ( V_28 )
V_4 |= V_29 ;
F_11 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static T_2 F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_3 ( V_9 , V_10 ) & V_29 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_13 )
return - V_21 ;
div = F_4 ( V_3 , V_13 ) ;
if ( div > V_26 + 1 || ! div )
return - V_21 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_11 ;
V_4 |= ( div - 1 ) << V_12 ;
F_11 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_11 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) | V_29 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_11 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) & ~ V_29 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return ! ! ( F_3 ( V_9 , V_10 ) & V_29 ) ;
}
static struct V_18 * T_3
F_17 ( struct V_8 * V_9 , const char * V_30 ,
const char * * V_31 , T_2 V_32 )
{
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_33 V_34 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_19 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_38 ;
V_34 . V_31 = V_31 ;
V_34 . V_32 = V_32 ;
V_34 . V_39 = V_40 | V_41 |
V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
V_18 = F_20 ( NULL , & V_7 -> V_2 ) ;
if ( F_21 ( V_18 ) )
F_22 ( V_7 ) ;
return V_18 ;
}
static struct V_18 * T_3
F_23 ( struct V_8 * V_9 , const char * V_30 ,
const char * V_43 )
{
struct V_6 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_33 V_34 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_19 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_44 ;
V_34 . V_31 = & V_43 ;
V_34 . V_32 = 1 ;
V_34 . V_39 = V_40 | V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
V_18 = F_20 ( NULL , & V_7 -> V_2 ) ;
if ( F_21 ( V_18 ) )
F_22 ( V_7 ) ;
return V_18 ;
}
static unsigned long F_24 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_45 * V_7 = F_25 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_4 ;
T_2 V_5 ;
V_4 = F_3 ( V_9 , V_46 ) ;
V_5 = ( V_4 & V_47 ) >> V_48 ;
if ( V_7 -> V_49 [ V_5 ] )
return V_3 / V_7 -> V_49 [ V_5 ] ;
return 0 ;
}
static long F_26 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
struct V_45 * V_7 = F_25 ( V_2 ) ;
struct V_18 * V_19 = F_27 ( V_2 -> V_18 ) ;
unsigned long V_50 = 0 ;
int V_51 = - 1 ;
unsigned long V_52 ;
int V_53 ;
int V_25 = 0 ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
unsigned long V_27 ;
if ( ! V_7 -> V_49 [ V_25 ] )
continue;
V_27 = V_13 * V_7 -> V_49 [ V_25 ] ;
V_27 = F_8 ( V_19 , V_27 ) ;
V_52 = F_4 ( V_27 , V_7 -> V_49 [ V_25 ] ) ;
if ( V_52 < V_13 )
V_53 = V_13 - V_52 ;
else
V_53 = V_52 - V_13 ;
if ( V_51 < 0 || V_51 > V_53 ) {
V_50 = V_52 ;
V_51 = V_53 ;
* V_3 = V_27 ;
}
if ( ! V_51 )
break;
}
return V_50 ;
}
static int F_28 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
int V_25 ;
struct V_45 * V_7 = F_25 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_13 )
return - V_21 ;
div = F_4 ( V_3 , V_13 ) ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
if ( V_7 -> V_49 [ V_25 ] == div ) {
V_4 = F_3 ( V_9 , V_46 ) &
~ V_47 ;
V_4 |= V_25 << V_48 ;
F_11 ( V_9 , V_46 , V_4 ) ;
return 0 ;
}
}
return - V_21 ;
}
static struct V_18 * T_3
F_29 ( struct V_8 * V_9 , const char * V_30 ,
const char * V_43 , const T_1 * V_49 )
{
struct V_45 * V_7 ;
struct V_18 * V_18 = NULL ;
struct V_33 V_34 ;
V_7 = F_18 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_19 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_55 ;
V_34 . V_31 = & V_43 ;
V_34 . V_32 = 1 ;
V_34 . V_39 = V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
memcpy ( V_7 -> V_49 , V_49 , sizeof( V_7 -> V_49 ) ) ;
V_18 = F_20 ( NULL , & V_7 -> V_2 ) ;
if ( F_21 ( V_18 ) )
F_22 ( V_7 ) ;
return V_18 ;
}
void T_3 F_30 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
int V_25 ;
int V_32 ;
const char * V_31 [ V_58 ] ;
const char * V_30 = V_57 -> V_30 ;
V_32 = F_31 ( V_57 ) ;
if ( V_32 <= 0 || V_32 > V_58 )
return;
for ( V_25 = 0 ; V_25 < V_32 ; V_25 ++ ) {
V_31 [ V_25 ] = F_32 ( V_57 , V_25 ) ;
if ( ! V_31 [ V_25 ] )
return;
}
F_33 ( V_57 , L_1 , & V_30 ) ;
V_18 = F_17 ( V_9 , V_30 , V_31 , V_32 ) ;
if ( F_21 ( V_18 ) )
return;
F_34 ( V_57 , V_59 , V_18 ) ;
}
void T_3 F_35 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
const char * V_43 ;
const char * V_30 = V_57 -> V_30 ;
V_43 = F_32 ( V_57 , 0 ) ;
if ( ! V_43 )
return;
F_33 ( V_57 , L_1 , & V_30 ) ;
V_18 = F_23 ( V_9 , V_30 , V_43 ) ;
if ( F_21 ( V_18 ) )
return;
F_34 ( V_57 , V_59 , V_18 ) ;
}
void T_3 F_36 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_18 * V_18 ;
const char * V_43 ;
const char * V_30 = V_57 -> V_30 ;
T_1 V_49 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_43 = F_32 ( V_57 , 0 ) ;
if ( ! V_43 )
return;
F_37 ( V_57 , L_2 , V_49 , 4 ) ;
if ( ! V_49 [ 0 ] )
return;
F_33 ( V_57 , L_1 , & V_30 ) ;
V_18 = F_29 ( V_9 , V_30 , V_43 , V_49 ) ;
if ( F_21 ( V_18 ) )
return;
F_34 ( V_57 , V_59 , V_18 ) ;
}
