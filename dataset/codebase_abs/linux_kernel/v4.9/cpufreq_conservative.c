static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
unsigned int V_8 = ( V_5 -> V_9 * V_7 -> V_10 ) / 100 ;
if ( F_4 ( V_8 == 0 ) )
V_8 = V_11 ;
return V_8 ;
}
static unsigned int F_5 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned int V_14 = V_13 -> V_14 ;
struct V_15 * V_15 = V_3 -> V_15 ;
struct V_4 * V_5 = V_15 -> V_16 ;
unsigned int V_17 = F_6 ( V_7 ) ;
if ( V_5 -> V_9 == 0 )
goto V_18;
if ( V_14 > V_7 -> V_10 || V_14 < V_7 -> V_19 )
V_14 = V_7 -> V_20 ;
if ( V_17 > V_15 -> V_21 ) {
V_13 -> V_22 = 0 ;
if ( V_14 == V_7 -> V_10 )
goto V_18;
V_14 += F_3 ( V_5 , V_7 ) ;
if ( V_14 > V_7 -> V_10 )
V_14 = V_7 -> V_10 ;
F_7 ( V_7 , V_14 , V_23 ) ;
V_13 -> V_14 = V_14 ;
goto V_18;
}
if ( ++ V_13 -> V_22 < V_15 -> V_24 )
goto V_18;
V_13 -> V_22 = 0 ;
if ( V_17 < V_5 -> V_25 ) {
unsigned int V_8 ;
if ( V_14 == V_7 -> V_19 )
goto V_18;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_14 > V_8 )
V_14 -= V_8 ;
else
V_14 = V_7 -> V_19 ;
F_7 ( V_7 , V_14 , V_26 ) ;
V_13 -> V_14 = V_14 ;
}
V_18:
return V_15 -> V_27 ;
}
static T_1 F_8 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_15 * V_15 = F_9 ( V_29 ) ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 > V_34 || V_32 < 1 )
return - V_35 ;
V_15 -> V_24 = V_32 ;
return V_31 ;
}
static T_1 F_10 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_15 * V_15 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_15 -> V_16 ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 > 100 || V_32 <= V_5 -> V_25 )
return - V_35 ;
V_15 -> V_21 = V_32 ;
return V_31 ;
}
static T_1 F_11 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_15 * V_15 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_15 -> V_16 ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 < 11 || V_32 > 100 ||
V_32 >= V_15 -> V_21 )
return - V_35 ;
V_5 -> V_25 = V_32 ;
return V_31 ;
}
static T_1 F_12 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_15 * V_15 = F_9 ( V_29 ) ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 )
return - V_35 ;
if ( V_32 > 1 )
V_32 = 1 ;
if ( V_32 == V_15 -> V_36 )
return V_31 ;
V_15 -> V_36 = V_32 ;
F_13 ( V_15 ) ;
return V_31 ;
}
static T_1 F_14 ( struct V_28 * V_29 , const char * V_30 ,
T_2 V_31 )
{
struct V_15 * V_15 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_15 -> V_16 ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 )
return - V_35 ;
if ( V_32 > 100 )
V_32 = 100 ;
V_5 -> V_9 = V_32 ;
return V_31 ;
}
static struct V_2 * F_15 ( void )
{
struct V_1 * V_13 ;
V_13 = F_16 ( sizeof( * V_13 ) , V_37 ) ;
return V_13 ? & V_13 -> V_3 : NULL ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_18 ( F_1 ( V_3 ) ) ;
}
static int F_19 ( struct V_15 * V_15 )
{
struct V_4 * V_16 ;
V_16 = F_16 ( sizeof( * V_16 ) , V_37 ) ;
if ( ! V_16 )
return - V_38 ;
V_16 -> V_25 = V_39 ;
V_16 -> V_9 = V_11 ;
V_15 -> V_21 = V_40 ;
V_15 -> V_24 = V_41 ;
V_15 -> V_36 = 0 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_42 = V_43 *
F_20 ( 10 ) ;
return 0 ;
}
static void F_21 ( struct V_15 * V_15 )
{
F_18 ( V_15 -> V_16 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_13 = F_1 ( V_7 -> V_12 ) ;
V_13 -> V_22 = 0 ;
V_13 -> V_14 = V_7 -> V_20 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( V_44 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( V_44 ) ;
}
struct V_45 * F_27 ( void )
{
return V_44 ;
}
