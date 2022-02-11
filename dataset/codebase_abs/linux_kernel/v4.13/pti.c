static int F_1 ( unsigned int V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] == V_1 )
return V_2 ;
return - V_4 ;
}
static T_1 F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
return F_5 ( V_9 , V_12 , L_1 , V_3 [ V_11 -> V_13 ] ) ;
}
static T_1 F_6 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_2 V_14 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_7 ( V_9 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_15 ) ;
if ( V_16 < 0 )
return V_16 ;
V_11 -> V_13 = V_16 ;
return V_14 ;
}
static T_1
F_8 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
return F_5 ( V_9 , V_12 , L_1 , V_11 -> V_17 ) ;
}
static T_1
F_9 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_2 V_14 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_7 ( V_9 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
V_11 -> V_17 = ! ! V_15 ;
return V_14 ;
}
static T_1
F_10 ( struct V_5 * V_6 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
return F_5 ( V_9 , V_12 , L_1 , 1u << V_11 -> V_18 ) ;
}
static T_1
F_11 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const char * V_9 , T_2 V_14 )
{
struct V_10 * V_11 = F_4 ( V_6 ) ;
unsigned long V_15 ;
int V_16 ;
V_16 = F_7 ( V_9 , 10 , & V_15 ) ;
if ( V_16 )
return V_16 ;
if ( ! F_12 ( V_15 ) || V_15 > 8 || ! V_15 )
return - V_4 ;
V_11 -> V_18 = V_15 ;
return V_14 ;
}
static int F_13 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = F_4 ( & V_20 -> V_6 ) ;
T_3 V_21 = V_22 ;
if ( V_11 -> V_23 )
V_21 |= V_11 -> V_23 << F_14 ( V_24 ) ;
if ( V_11 -> V_17 )
V_21 |= V_25 ;
V_21 |= V_11 -> V_13 << F_14 ( V_26 ) ;
V_21 |= V_11 -> V_18 << F_14 ( V_27 ) ;
F_15 ( V_21 , V_11 -> V_28 + V_29 ) ;
F_16 ( V_20 ) ;
return 0 ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = F_4 ( & V_20 -> V_6 ) ;
F_18 ( V_20 ) ;
F_15 ( 0 , V_11 -> V_28 + V_29 ) ;
}
static void F_19 ( struct V_10 * V_11 )
{
T_3 V_21 = F_20 ( V_11 -> V_28 + V_29 ) ;
V_11 -> V_13 = ( V_21 & V_26 ) >> F_14 ( V_26 ) ;
V_11 -> V_18 = ( V_21 & V_27 ) >> F_14 ( V_27 ) ;
V_11 -> V_17 = ! ! ( V_21 & V_25 ) ;
if ( ! V_3 [ V_11 -> V_13 ] )
V_11 -> V_13 = F_1 ( 4 ) ;
if ( ! V_11 -> V_18 )
V_11 -> V_18 = 1 ;
}
static int F_21 ( struct V_19 * V_20 )
{
struct V_5 * V_6 = & V_20 -> V_6 ;
struct V_30 * V_31 ;
struct V_10 * V_11 ;
void T_4 * V_28 ;
V_31 = F_22 ( V_20 , V_32 , 0 ) ;
if ( ! V_31 )
return - V_33 ;
V_28 = F_23 ( V_6 , V_31 -> V_34 , F_24 ( V_31 ) ) ;
if ( ! V_28 )
return - V_35 ;
V_11 = F_25 ( V_6 , sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return - V_35 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_28 = V_28 ;
F_19 ( V_11 ) ;
F_26 ( V_6 , V_11 ) ;
return 0 ;
}
static void F_27 ( struct V_19 * V_20 )
{
}
