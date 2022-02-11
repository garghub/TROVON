static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline unsigned int F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
unsigned int V_8 = ( V_5 -> V_8 * V_7 -> V_9 ) / 100 ;
if ( F_4 ( V_8 == 0 ) )
V_8 = V_10 ;
return V_8 ;
}
static unsigned int F_5 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_11 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned int V_13 = V_12 -> V_13 ;
struct V_14 * V_14 = V_3 -> V_14 ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_16 = F_6 ( V_7 ) ;
unsigned int V_8 ;
if ( V_5 -> V_8 == 0 )
goto V_17;
if ( V_13 > V_7 -> V_9 || V_13 < V_7 -> V_18 )
V_13 = V_7 -> V_19 ;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_3 -> V_20 < V_21 ) {
unsigned int V_22 = V_3 -> V_20 * V_8 ;
if ( V_13 > V_22 )
V_13 -= V_22 ;
else
V_13 = V_7 -> V_18 ;
V_3 -> V_20 = V_21 ;
}
if ( V_16 > V_14 -> V_23 ) {
V_12 -> V_24 = 0 ;
if ( V_13 == V_7 -> V_9 )
goto V_17;
V_13 += V_8 ;
if ( V_13 > V_7 -> V_9 )
V_13 = V_7 -> V_9 ;
F_7 ( V_7 , V_13 , V_25 ) ;
V_12 -> V_13 = V_13 ;
goto V_17;
}
if ( ++ V_12 -> V_24 < V_14 -> V_26 )
goto V_17;
V_12 -> V_24 = 0 ;
if ( V_16 < V_5 -> V_27 ) {
if ( V_13 == V_7 -> V_18 )
goto V_17;
if ( V_13 > V_8 )
V_13 -= V_8 ;
else
V_13 = V_7 -> V_18 ;
F_7 ( V_7 , V_13 , V_28 ) ;
V_12 -> V_13 = V_13 ;
}
V_17:
return V_14 -> V_29 ;
}
static T_1 F_8 ( struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_14 = F_9 ( V_31 ) ;
unsigned int V_34 ;
int V_35 ;
V_35 = sscanf ( V_32 , L_1 , & V_34 ) ;
if ( V_35 != 1 || V_34 > V_36 || V_34 < 1 )
return - V_37 ;
V_14 -> V_26 = V_34 ;
return V_33 ;
}
static T_1 F_10 ( struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_14 = F_9 ( V_31 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_34 ;
int V_35 ;
V_35 = sscanf ( V_32 , L_1 , & V_34 ) ;
if ( V_35 != 1 || V_34 > 100 || V_34 <= V_5 -> V_27 )
return - V_37 ;
V_14 -> V_23 = V_34 ;
return V_33 ;
}
static T_1 F_11 ( struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_14 = F_9 ( V_31 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_34 ;
int V_35 ;
V_35 = sscanf ( V_32 , L_1 , & V_34 ) ;
if ( V_35 != 1 || V_34 < 11 || V_34 > 100 ||
V_34 >= V_14 -> V_23 )
return - V_37 ;
V_5 -> V_27 = V_34 ;
return V_33 ;
}
static T_1 F_12 ( struct V_30 * V_31 ,
const char * V_32 , T_2 V_33 )
{
struct V_14 * V_14 = F_9 ( V_31 ) ;
unsigned int V_34 ;
int V_35 ;
V_35 = sscanf ( V_32 , L_1 , & V_34 ) ;
if ( V_35 != 1 )
return - V_37 ;
if ( V_34 > 1 )
V_34 = 1 ;
if ( V_34 == V_14 -> V_38 )
return V_33 ;
V_14 -> V_38 = V_34 ;
F_13 ( V_14 ) ;
return V_33 ;
}
static T_1 F_14 ( struct V_30 * V_31 , const char * V_32 ,
T_2 V_33 )
{
struct V_14 * V_14 = F_9 ( V_31 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_34 ;
int V_35 ;
V_35 = sscanf ( V_32 , L_1 , & V_34 ) ;
if ( V_35 != 1 )
return - V_37 ;
if ( V_34 > 100 )
V_34 = 100 ;
V_5 -> V_8 = V_34 ;
return V_33 ;
}
static struct V_2 * F_15 ( void )
{
struct V_1 * V_12 ;
V_12 = F_16 ( sizeof( * V_12 ) , V_39 ) ;
return V_12 ? & V_12 -> V_3 : NULL ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_18 ( F_1 ( V_3 ) ) ;
}
static int F_19 ( struct V_14 * V_14 )
{
struct V_4 * V_15 ;
V_15 = F_16 ( sizeof( * V_15 ) , V_39 ) ;
if ( ! V_15 )
return - V_40 ;
V_15 -> V_27 = V_41 ;
V_15 -> V_8 = V_10 ;
V_14 -> V_23 = V_42 ;
V_14 -> V_26 = V_43 ;
V_14 -> V_38 = 0 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_44 = V_45 *
F_20 ( 10 ) ;
return 0 ;
}
static void F_21 ( struct V_14 * V_14 )
{
F_18 ( V_14 -> V_15 ) ;
}
static void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_12 = F_1 ( V_7 -> V_11 ) ;
V_12 -> V_24 = 0 ;
V_12 -> V_13 = V_7 -> V_19 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( V_46 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( V_46 ) ;
}
struct V_47 * F_27 ( void )
{
return V_46 ;
}
