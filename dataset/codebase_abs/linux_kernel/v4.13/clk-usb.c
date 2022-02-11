static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
T_1 V_7 ;
F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
V_7 = ( V_6 & V_10 ) >> V_11 ;
return F_4 ( V_3 , ( V_7 + 1 ) ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_1 * V_14 ;
long V_15 = - V_16 ;
unsigned long V_17 ;
int V_18 = - 1 ;
int V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_6 ( V_2 ) ; V_20 ++ ) {
int div ;
V_14 = F_7 ( V_2 , V_20 ) ;
if ( ! V_14 )
continue;
for ( div = 1 ; div < V_21 + 2 ; div ++ ) {
unsigned long V_22 ;
V_22 = V_13 -> V_23 * div ;
V_22 = F_8 ( V_14 ,
V_22 ) ;
V_17 = F_4 ( V_22 , div ) ;
if ( V_17 < V_13 -> V_23 )
V_19 = V_13 -> V_23 - V_17 ;
else
V_19 = V_17 - V_13 -> V_23 ;
if ( V_18 < 0 || V_18 > V_19 ) {
V_15 = V_17 ;
V_18 = V_19 ;
V_13 -> V_24 = V_22 ;
V_13 -> V_25 = V_14 ;
}
if ( ! V_18 || V_17 < V_13 -> V_23 )
break;
}
if ( ! V_18 )
break;
}
if ( V_15 < 0 )
return V_15 ;
V_13 -> V_23 = V_15 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_26 > 1 )
return - V_16 ;
F_10 ( V_5 -> V_8 , V_9 , V_27 ,
V_26 ? V_27 : 0 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
return V_6 & V_27 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long div ;
if ( ! V_23 )
return - V_16 ;
div = F_4 ( V_3 , V_23 ) ;
if ( div > V_21 + 1 || ! div )
return - V_16 ;
F_10 ( V_5 -> V_8 , V_9 , V_10 ,
( div - 1 ) << V_11 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_5 -> V_8 , V_9 , V_27 ,
V_27 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_5 -> V_8 , V_9 , V_27 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
return V_6 & V_27 ;
}
static struct V_1 * T_2
F_16 ( struct V_8 * V_8 , const char * V_28 ,
const char * * V_29 , T_1 V_30 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_31 V_32 ;
int V_33 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
return F_18 ( - V_35 ) ;
V_32 . V_28 = V_28 ;
V_32 . V_36 = & V_37 ;
V_32 . V_29 = V_29 ;
V_32 . V_30 = V_30 ;
V_32 . V_38 = V_39 | V_40 |
V_41 ;
V_5 -> V_2 . V_32 = & V_32 ;
V_5 -> V_8 = V_8 ;
V_2 = & V_5 -> V_2 ;
V_33 = F_19 ( NULL , & V_5 -> V_2 ) ;
if ( V_33 ) {
F_20 ( V_5 ) ;
V_2 = F_18 ( V_33 ) ;
}
return V_2 ;
}
static struct V_1 * T_2
F_21 ( struct V_8 * V_8 , const char * V_28 ,
const char * V_42 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_31 V_32 ;
int V_33 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
return F_18 ( - V_35 ) ;
V_32 . V_28 = V_28 ;
V_32 . V_36 = & V_43 ;
V_32 . V_29 = & V_42 ;
V_32 . V_30 = 1 ;
V_32 . V_38 = V_39 | V_41 ;
V_5 -> V_2 . V_32 = & V_32 ;
V_5 -> V_8 = V_8 ;
V_2 = & V_5 -> V_2 ;
V_33 = F_19 ( NULL , & V_5 -> V_2 ) ;
if ( V_33 ) {
F_20 ( V_5 ) ;
V_2 = F_18 ( V_33 ) ;
}
return V_2 ;
}
static unsigned long F_22 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_44 * V_5 = F_23 ( V_2 ) ;
unsigned int V_45 ;
T_1 V_7 ;
F_3 ( V_5 -> V_8 , V_46 , & V_45 ) ;
V_7 = ( V_45 & V_47 ) >> V_48 ;
if ( V_5 -> V_49 [ V_7 ] )
return V_3 / V_5 -> V_49 [ V_7 ] ;
return 0 ;
}
static long F_24 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long * V_3 )
{
struct V_44 * V_5 = F_23 ( V_2 ) ;
struct V_1 * V_14 = F_25 ( V_2 ) ;
unsigned long V_50 = 0 ;
int V_51 = - 1 ;
unsigned long V_52 ;
int V_53 ;
int V_20 = 0 ;
for ( V_20 = 0 ; V_20 < V_54 ; V_20 ++ ) {
unsigned long V_22 ;
if ( ! V_5 -> V_49 [ V_20 ] )
continue;
V_22 = V_23 * V_5 -> V_49 [ V_20 ] ;
V_22 = F_8 ( V_14 , V_22 ) ;
V_52 = F_4 ( V_22 , V_5 -> V_49 [ V_20 ] ) ;
if ( V_52 < V_23 )
V_53 = V_23 - V_52 ;
else
V_53 = V_52 - V_23 ;
if ( V_51 < 0 || V_51 > V_53 ) {
V_50 = V_52 ;
V_51 = V_53 ;
* V_3 = V_22 ;
}
if ( ! V_51 )
break;
}
return V_50 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_23 ,
unsigned long V_3 )
{
int V_20 ;
struct V_44 * V_5 = F_23 ( V_2 ) ;
unsigned long div ;
if ( ! V_23 )
return - V_16 ;
div = F_4 ( V_3 , V_23 ) ;
for ( V_20 = 0 ; V_20 < V_54 ; V_20 ++ ) {
if ( V_5 -> V_49 [ V_20 ] == div ) {
F_10 ( V_5 -> V_8 , V_46 ,
V_47 ,
V_20 << V_48 ) ;
return 0 ;
}
}
return - V_16 ;
}
static struct V_1 * T_2
F_27 ( struct V_8 * V_8 , const char * V_28 ,
const char * V_42 , const T_3 * V_49 )
{
struct V_44 * V_5 ;
struct V_1 * V_2 ;
struct V_31 V_32 ;
int V_33 ;
V_5 = F_17 ( sizeof( * V_5 ) , V_34 ) ;
if ( ! V_5 )
return F_18 ( - V_35 ) ;
V_32 . V_28 = V_28 ;
V_32 . V_36 = & V_55 ;
V_32 . V_29 = & V_42 ;
V_32 . V_30 = 1 ;
V_32 . V_38 = V_41 ;
V_5 -> V_2 . V_32 = & V_32 ;
V_5 -> V_8 = V_8 ;
memcpy ( V_5 -> V_49 , V_49 , sizeof( V_5 -> V_49 ) ) ;
V_2 = & V_5 -> V_2 ;
V_33 = F_19 ( NULL , & V_5 -> V_2 ) ;
if ( V_33 ) {
F_20 ( V_5 ) ;
V_2 = F_18 ( V_33 ) ;
}
return V_2 ;
}
static void T_2 F_28 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
unsigned int V_30 ;
const char * V_29 [ V_58 ] ;
const char * V_28 = V_57 -> V_28 ;
struct V_8 * V_8 ;
V_30 = F_29 ( V_57 ) ;
if ( V_30 == 0 || V_30 > V_58 )
return;
F_30 ( V_57 , V_29 , V_30 ) ;
F_31 ( V_57 , L_1 , & V_28 ) ;
V_8 = F_32 ( F_33 ( V_57 ) ) ;
if ( F_34 ( V_8 ) )
return;
V_2 = F_16 ( V_8 , V_28 , V_29 ,
V_30 ) ;
if ( F_34 ( V_2 ) )
return;
F_35 ( V_57 , V_59 , V_2 ) ;
}
static void T_2 F_36 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
const char * V_42 ;
const char * V_28 = V_57 -> V_28 ;
struct V_8 * V_8 ;
V_42 = F_37 ( V_57 , 0 ) ;
if ( ! V_42 )
return;
F_31 ( V_57 , L_1 , & V_28 ) ;
V_8 = F_32 ( F_33 ( V_57 ) ) ;
if ( F_34 ( V_8 ) )
return;
V_2 = F_21 ( V_8 , V_28 , V_42 ) ;
if ( F_34 ( V_2 ) )
return;
F_35 ( V_57 , V_59 , V_2 ) ;
}
static void T_2 F_38 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
const char * V_42 ;
const char * V_28 = V_57 -> V_28 ;
T_3 V_49 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_8 * V_8 ;
V_42 = F_37 ( V_57 , 0 ) ;
if ( ! V_42 )
return;
F_39 ( V_57 , L_2 , V_49 , 4 ) ;
if ( ! V_49 [ 0 ] )
return;
F_31 ( V_57 , L_1 , & V_28 ) ;
V_8 = F_32 ( F_33 ( V_57 ) ) ;
if ( F_34 ( V_8 ) )
return;
V_2 = F_27 ( V_8 , V_28 , V_42 , V_49 ) ;
if ( F_34 ( V_2 ) )
return;
F_35 ( V_57 , V_59 , V_2 ) ;
}
