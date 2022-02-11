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
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_1 * V_15 ;
long V_16 = - V_17 ;
unsigned long V_18 ;
int V_19 = - 1 ;
int V_20 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < F_6 ( V_2 ) ; V_21 ++ ) {
int div ;
V_15 = F_7 ( V_2 , V_21 ) ;
if ( ! V_15 )
continue;
for ( div = 1 ; div < V_22 + 2 ; div ++ ) {
unsigned long V_23 ;
V_23 = V_14 -> V_24 * div ;
V_23 = F_8 ( V_15 ,
V_23 ) ;
V_18 = F_4 ( V_23 , div ) ;
if ( V_18 < V_14 -> V_24 )
V_20 = V_14 -> V_24 - V_18 ;
else
V_20 = V_18 - V_14 -> V_24 ;
if ( V_19 < 0 || V_19 > V_20 ) {
V_16 = V_18 ;
V_19 = V_20 ;
V_14 -> V_25 = V_23 ;
V_14 -> V_26 = V_15 ;
}
if ( ! V_19 || V_18 < V_14 -> V_24 )
break;
}
if ( ! V_19 )
break;
}
if ( V_16 < 0 )
return V_16 ;
V_14 -> V_24 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_27 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_27 > 1 )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_28 ;
if ( V_27 )
V_4 |= V_28 ;
F_10 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_3 ( V_9 , V_10 ) & V_28 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_24 )
return - V_17 ;
div = F_4 ( V_3 , V_24 ) ;
if ( div > V_22 + 1 || ! div )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_11 ;
V_4 |= ( div - 1 ) << V_12 ;
F_10 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_10 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) | V_28 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_10 ( V_9 , V_10 ,
F_3 ( V_9 , V_10 ) & ~ V_28 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return ! ! ( F_3 ( V_9 , V_10 ) & V_28 ) ;
}
static struct V_29 * T_3
F_16 ( struct V_8 * V_9 , const char * V_30 ,
const char * * V_31 , T_2 V_32 )
{
struct V_6 * V_7 ;
struct V_29 * V_29 = NULL ;
struct V_33 V_34 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_18 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_38 ;
V_34 . V_31 = V_31 ;
V_34 . V_32 = V_32 ;
V_34 . V_39 = V_40 | V_41 |
V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
V_29 = F_19 ( NULL , & V_7 -> V_2 ) ;
if ( F_20 ( V_29 ) )
F_21 ( V_7 ) ;
return V_29 ;
}
static struct V_29 * T_3
F_22 ( struct V_8 * V_9 , const char * V_30 ,
const char * V_43 )
{
struct V_6 * V_7 ;
struct V_29 * V_29 = NULL ;
struct V_33 V_34 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_18 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_44 ;
V_34 . V_31 = & V_43 ;
V_34 . V_32 = 1 ;
V_34 . V_39 = V_40 | V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
V_29 = F_19 ( NULL , & V_7 -> V_2 ) ;
if ( F_20 ( V_29 ) )
F_21 ( V_7 ) ;
return V_29 ;
}
static unsigned long F_23 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_45 * V_7 = F_24 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_4 ;
T_2 V_5 ;
V_4 = F_3 ( V_9 , V_46 ) ;
V_5 = ( V_4 & V_47 ) >> V_48 ;
if ( V_7 -> V_49 [ V_5 ] )
return V_3 / V_7 -> V_49 [ V_5 ] ;
return 0 ;
}
static long F_25 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long * V_3 )
{
struct V_45 * V_7 = F_24 ( V_2 ) ;
struct V_1 * V_15 = F_26 ( V_2 ) ;
unsigned long V_50 = 0 ;
int V_51 = - 1 ;
unsigned long V_52 ;
int V_53 ;
int V_21 = 0 ;
for ( V_21 = 0 ; V_21 < V_54 ; V_21 ++ ) {
unsigned long V_23 ;
if ( ! V_7 -> V_49 [ V_21 ] )
continue;
V_23 = V_24 * V_7 -> V_49 [ V_21 ] ;
V_23 = F_8 ( V_15 , V_23 ) ;
V_52 = F_4 ( V_23 , V_7 -> V_49 [ V_21 ] ) ;
if ( V_52 < V_24 )
V_53 = V_24 - V_52 ;
else
V_53 = V_52 - V_24 ;
if ( V_51 < 0 || V_51 > V_53 ) {
V_50 = V_52 ;
V_51 = V_53 ;
* V_3 = V_23 ;
}
if ( ! V_51 )
break;
}
return V_50 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned long V_24 ,
unsigned long V_3 )
{
T_1 V_4 ;
int V_21 ;
struct V_45 * V_7 = F_24 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div ;
if ( ! V_24 )
return - V_17 ;
div = F_4 ( V_3 , V_24 ) ;
for ( V_21 = 0 ; V_21 < V_54 ; V_21 ++ ) {
if ( V_7 -> V_49 [ V_21 ] == div ) {
V_4 = F_3 ( V_9 , V_46 ) &
~ V_47 ;
V_4 |= V_21 << V_48 ;
F_10 ( V_9 , V_46 , V_4 ) ;
return 0 ;
}
}
return - V_17 ;
}
static struct V_29 * T_3
F_28 ( struct V_8 * V_9 , const char * V_30 ,
const char * V_43 , const T_1 * V_49 )
{
struct V_45 * V_7 ;
struct V_29 * V_29 = NULL ;
struct V_33 V_34 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return F_18 ( - V_36 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_37 = & V_55 ;
V_34 . V_31 = & V_43 ;
V_34 . V_32 = 1 ;
V_34 . V_39 = V_42 ;
V_7 -> V_2 . V_34 = & V_34 ;
V_7 -> V_9 = V_9 ;
memcpy ( V_7 -> V_49 , V_49 , sizeof( V_7 -> V_49 ) ) ;
V_29 = F_19 ( NULL , & V_7 -> V_2 ) ;
if ( F_20 ( V_29 ) )
F_21 ( V_7 ) ;
return V_29 ;
}
void T_3 F_29 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_29 * V_29 ;
int V_32 ;
const char * V_31 [ V_58 ] ;
const char * V_30 = V_57 -> V_30 ;
V_32 = F_30 ( V_57 ) ;
if ( V_32 <= 0 || V_32 > V_58 )
return;
F_31 ( V_57 , V_31 , V_32 ) ;
F_32 ( V_57 , L_1 , & V_30 ) ;
V_29 = F_16 ( V_9 , V_30 , V_31 , V_32 ) ;
if ( F_20 ( V_29 ) )
return;
F_33 ( V_57 , V_59 , V_29 ) ;
}
void T_3 F_34 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_29 * V_29 ;
const char * V_43 ;
const char * V_30 = V_57 -> V_30 ;
V_43 = F_35 ( V_57 , 0 ) ;
if ( ! V_43 )
return;
F_32 ( V_57 , L_1 , & V_30 ) ;
V_29 = F_22 ( V_9 , V_30 , V_43 ) ;
if ( F_20 ( V_29 ) )
return;
F_33 ( V_57 , V_59 , V_29 ) ;
}
void T_3 F_36 ( struct V_56 * V_57 ,
struct V_8 * V_9 )
{
struct V_29 * V_29 ;
const char * V_43 ;
const char * V_30 = V_57 -> V_30 ;
T_1 V_49 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_43 = F_35 ( V_57 , 0 ) ;
if ( ! V_43 )
return;
F_37 ( V_57 , L_2 , V_49 , 4 ) ;
if ( ! V_49 [ 0 ] )
return;
F_32 ( V_57 , L_1 , & V_30 ) ;
V_29 = F_28 ( V_9 , V_30 , V_43 , V_49 ) ;
if ( F_20 ( V_29 ) )
return;
F_33 ( V_57 , V_59 , V_29 ) ;
}
