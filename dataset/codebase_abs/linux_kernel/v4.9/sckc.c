static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & ( V_7 | V_8 ) )
return 0 ;
F_4 ( V_6 | V_8 , V_5 ) ;
F_5 ( V_4 -> V_9 , V_4 -> V_9 + 1 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & V_7 )
return;
F_4 ( V_6 & ~ V_8 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = F_3 ( V_5 ) ;
if ( V_6 & V_7 )
return 1 ;
return ! ! ( V_6 & V_8 ) ;
}
static struct V_1 * T_3
F_8 ( void T_1 * V_5 ,
const char * V_10 ,
const char * V_11 ,
unsigned long V_12 ,
bool V_13 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_14 V_15 ;
int V_16 ;
if ( ! V_5 || ! V_10 || ! V_11 )
return F_9 ( - V_17 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_9 ( - V_19 ) ;
V_15 . V_10 = V_10 ;
V_15 . V_20 = & V_21 ;
V_15 . V_22 = & V_11 ;
V_15 . V_23 = 1 ;
V_15 . V_24 = V_25 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_9 = V_12 ;
if ( V_13 )
F_4 ( ( F_3 ( V_5 ) & ~ V_8 ) | V_7 ,
V_5 ) ;
V_2 = & V_4 -> V_2 ;
V_16 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( V_16 ) {
F_12 ( V_4 ) ;
V_2 = F_9 ( V_16 ) ;
}
return V_2 ;
}
static void T_3
F_13 ( struct V_26 * V_27 , void T_1 * V_5 )
{
struct V_1 * V_2 ;
const char * V_11 ;
const char * V_10 = V_27 -> V_10 ;
T_2 V_12 ;
bool V_13 ;
V_11 = F_14 ( V_27 , 0 ) ;
F_15 ( V_27 , L_1 , & V_10 ) ;
F_16 ( V_27 , L_2 , & V_12 ) ;
V_13 = F_17 ( V_27 , L_3 ) ;
V_2 = F_8 ( V_5 , V_10 , V_11 , V_12 ,
V_13 ) ;
if ( F_18 ( V_2 ) )
return;
F_19 ( V_27 , V_28 , V_2 ) ;
}
static unsigned long F_20 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return V_4 -> V_31 ;
}
static unsigned long F_22 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return V_4 -> V_33 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_4 ( F_3 ( V_5 ) | V_34 , V_5 ) ;
F_5 ( V_4 -> V_9 , V_4 -> V_9 + 1 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
void T_1 * V_5 = V_4 -> V_5 ;
F_4 ( F_3 ( V_5 ) & ~ V_34 , V_5 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_30 * V_4 = F_21 ( V_2 ) ;
return ! ! ( F_3 ( V_4 -> V_5 ) & V_34 ) ;
}
static struct V_1 * T_3
F_26 ( void T_1 * V_5 ,
const char * V_10 ,
unsigned long V_31 ,
unsigned long V_33 ,
unsigned long V_12 )
{
struct V_30 * V_4 ;
struct V_1 * V_2 ;
struct V_14 V_15 ;
int V_16 ;
if ( ! V_5 || ! V_10 )
return F_9 ( - V_17 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return F_9 ( - V_19 ) ;
V_15 . V_10 = V_10 ;
V_15 . V_20 = & V_35 ;
V_15 . V_22 = NULL ;
V_15 . V_23 = 0 ;
V_15 . V_24 = V_25 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_31 = V_31 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_9 = V_12 ;
V_2 = & V_4 -> V_2 ;
V_16 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( V_16 ) {
F_12 ( V_4 ) ;
V_2 = F_9 ( V_16 ) ;
}
return V_2 ;
}
static void T_3
F_27 ( struct V_26 * V_27 , void T_1 * V_5 )
{
struct V_1 * V_2 ;
T_2 V_31 = 0 ;
T_2 V_33 = 0 ;
T_2 V_12 = 0 ;
const char * V_10 = V_27 -> V_10 ;
F_15 ( V_27 , L_1 , & V_10 ) ;
F_16 ( V_27 , L_4 , & V_31 ) ;
F_16 ( V_27 , L_5 , & V_33 ) ;
F_16 ( V_27 , L_2 , & V_12 ) ;
V_2 = F_26 ( V_5 , V_10 , V_31 , V_33 ,
V_12 ) ;
if ( F_18 ( V_2 ) )
return;
F_19 ( V_27 , V_28 , V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_4 V_36 )
{
struct V_37 * V_38 = F_29 ( V_2 ) ;
void T_1 * V_5 = V_38 -> V_5 ;
T_2 V_6 ;
if ( V_36 > 1 )
return - V_17 ;
V_6 = F_3 ( V_5 ) ;
if ( ( ! V_36 && ! ( V_6 & V_39 ) ) ||
( V_36 && ( V_6 & V_39 ) ) )
return 0 ;
if ( V_36 )
V_6 |= V_39 ;
else
V_6 &= ~ V_39 ;
F_4 ( V_6 , V_5 ) ;
F_5 ( V_40 , V_40 + 1 ) ;
return 0 ;
}
static T_4 F_30 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_29 ( V_2 ) ;
return ! ! ( F_3 ( V_38 -> V_5 ) & V_39 ) ;
}
static struct V_1 * T_3
F_31 ( void T_1 * V_5 ,
const char * V_10 ,
const char * * V_22 ,
int V_23 )
{
struct V_37 * V_38 ;
struct V_1 * V_2 ;
struct V_14 V_15 ;
int V_16 ;
if ( ! V_5 || ! V_10 || ! V_22 || ! V_23 )
return F_9 ( - V_17 ) ;
V_38 = F_10 ( sizeof( * V_38 ) , V_18 ) ;
if ( ! V_38 )
return F_9 ( - V_19 ) ;
V_15 . V_10 = V_10 ;
V_15 . V_20 = & V_41 ;
V_15 . V_22 = V_22 ;
V_15 . V_23 = V_23 ;
V_15 . V_24 = 0 ;
V_38 -> V_2 . V_15 = & V_15 ;
V_38 -> V_5 = V_5 ;
V_38 -> V_42 = ! ! ( F_3 ( V_5 ) & V_39 ) ;
V_2 = & V_38 -> V_2 ;
V_16 = F_11 ( NULL , & V_38 -> V_2 ) ;
if ( V_16 ) {
F_12 ( V_38 ) ;
V_2 = F_9 ( V_16 ) ;
}
return V_2 ;
}
static void T_3
F_32 ( struct V_26 * V_27 , void T_1 * V_5 )
{
struct V_1 * V_2 ;
const char * V_22 [ 2 ] ;
unsigned int V_23 ;
const char * V_10 = V_27 -> V_10 ;
V_23 = F_33 ( V_27 ) ;
if ( V_23 == 0 || V_23 > 2 )
return;
F_34 ( V_27 , V_22 , V_23 ) ;
F_15 ( V_27 , L_1 , & V_10 ) ;
V_2 = F_31 ( V_5 , V_10 , V_22 ,
V_23 ) ;
if ( F_18 ( V_2 ) )
return;
F_19 ( V_27 , V_28 , V_2 ) ;
}
static void T_3 F_35 ( struct V_26 * V_27 )
{
struct V_26 * V_43 ;
void (* F_36)( struct V_26 * , void T_1 * );
const struct V_44 * V_45 ;
void T_1 * V_46 = F_37 ( V_27 , 0 ) ;
if ( ! V_46 )
return;
F_38 (np, childnp) {
V_45 = F_39 ( V_47 , V_43 ) ;
if ( ! V_45 )
continue;
F_36 = V_45 -> V_48 ;
F_36 ( V_43 , V_46 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_49 * V_4 = F_41 ( V_2 ) ;
if ( V_4 -> V_50 )
return 0 ;
if ( ( F_3 ( V_4 -> V_5 ) & V_39 ) ) {
V_4 -> V_50 = true ;
return 0 ;
}
F_5 ( V_4 -> V_9 , V_4 -> V_9 + 1 ) ;
V_4 -> V_50 = true ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_49 * V_4 = F_41 ( V_2 ) ;
return V_4 -> V_50 ;
}
static void T_3 F_43 ( struct V_26 * V_27 )
{
void T_1 * V_46 = F_37 ( V_27 , 0 ) ;
struct V_1 * V_2 ;
struct V_49 * V_4 ;
struct V_14 V_15 ;
const char * V_51 ;
const char * V_22 [ 2 ] = { L_6 , L_7 } ;
bool V_13 ;
int V_16 ;
if ( ! V_46 )
return;
V_2 = F_44 ( NULL , V_22 [ 0 ] ,
NULL , 0 , 32768 ,
250000000 ) ;
if ( F_18 ( V_2 ) )
return;
V_51 = F_14 ( V_27 , 0 ) ;
V_13 = F_17 ( V_27 , L_3 ) ;
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return;
V_15 . V_10 = V_22 [ 1 ] ;
V_15 . V_20 = & V_52 ;
V_15 . V_22 = & V_51 ;
V_15 . V_23 = 1 ;
V_15 . V_24 = V_25 ;
V_4 -> V_2 . V_15 = & V_15 ;
V_4 -> V_5 = V_46 ;
V_4 -> V_9 = 1200000 ;
if ( V_13 )
F_4 ( ( F_3 ( V_46 ) | V_7 ) , V_46 ) ;
V_2 = & V_4 -> V_2 ;
V_16 = F_11 ( NULL , & V_4 -> V_2 ) ;
if ( V_16 ) {
F_12 ( V_4 ) ;
return;
}
V_2 = F_31 ( V_46 , L_8 , V_22 , 2 ) ;
if ( F_18 ( V_2 ) )
return;
F_19 ( V_27 , V_28 , V_2 ) ;
}
