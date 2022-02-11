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
struct V_14 * V_14 = V_3 -> V_14 ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_16 = F_6 ( V_7 ) ;
if ( V_5 -> V_9 == 0 )
goto V_17;
if ( V_16 > V_14 -> V_18 ) {
V_13 -> V_19 = 0 ;
if ( V_13 -> V_20 == V_7 -> V_10 )
goto V_17;
V_13 -> V_20 += F_3 ( V_5 , V_7 ) ;
if ( V_13 -> V_20 > V_7 -> V_10 )
V_13 -> V_20 = V_7 -> V_10 ;
F_7 ( V_7 , V_13 -> V_20 ,
V_21 ) ;
goto V_17;
}
if ( ++ V_13 -> V_19 < V_14 -> V_22 )
goto V_17;
V_13 -> V_19 = 0 ;
if ( V_16 < V_5 -> V_23 ) {
unsigned int V_8 ;
if ( V_7 -> V_24 == V_7 -> V_25 )
goto V_17;
V_8 = F_3 ( V_5 , V_7 ) ;
if ( V_13 -> V_20 > V_8 )
V_13 -> V_20 -= V_8 ;
else
V_13 -> V_20 = V_7 -> V_25 ;
F_7 ( V_7 , V_13 -> V_20 ,
V_26 ) ;
}
V_17:
return V_14 -> V_27 ;
}
static T_1 F_8 ( struct V_14 * V_14 ,
const char * V_28 , T_2 V_29 )
{
unsigned int V_30 ;
int V_31 ;
V_31 = sscanf ( V_28 , L_1 , & V_30 ) ;
if ( V_31 != 1 || V_30 > V_32 || V_30 < 1 )
return - V_33 ;
V_14 -> V_22 = V_30 ;
return V_29 ;
}
static T_1 F_9 ( struct V_14 * V_14 , const char * V_28 ,
T_2 V_29 )
{
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_30 ;
int V_31 ;
V_31 = sscanf ( V_28 , L_1 , & V_30 ) ;
if ( V_31 != 1 || V_30 > 100 || V_30 <= V_5 -> V_23 )
return - V_33 ;
V_14 -> V_18 = V_30 ;
return V_29 ;
}
static T_1 F_10 ( struct V_14 * V_14 , const char * V_28 ,
T_2 V_29 )
{
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_30 ;
int V_31 ;
V_31 = sscanf ( V_28 , L_1 , & V_30 ) ;
if ( V_31 != 1 || V_30 < 11 || V_30 > 100 ||
V_30 >= V_14 -> V_18 )
return - V_33 ;
V_5 -> V_23 = V_30 ;
return V_29 ;
}
static T_1 F_11 ( struct V_14 * V_14 ,
const char * V_28 , T_2 V_29 )
{
unsigned int V_30 ;
int V_31 ;
V_31 = sscanf ( V_28 , L_1 , & V_30 ) ;
if ( V_31 != 1 )
return - V_33 ;
if ( V_30 > 1 )
V_30 = 1 ;
if ( V_30 == V_14 -> V_34 )
return V_29 ;
V_14 -> V_34 = V_30 ;
F_12 ( V_14 ) ;
return V_29 ;
}
static T_1 F_13 ( struct V_14 * V_14 , const char * V_28 ,
T_2 V_29 )
{
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_30 ;
int V_31 ;
V_31 = sscanf ( V_28 , L_1 , & V_30 ) ;
if ( V_31 != 1 )
return - V_33 ;
if ( V_30 > 100 )
V_30 = 100 ;
V_5 -> V_9 = V_30 ;
return V_29 ;
}
static struct V_2 * F_14 ( void )
{
struct V_1 * V_13 ;
V_13 = F_15 ( sizeof( * V_13 ) , V_35 ) ;
return V_13 ? & V_13 -> V_3 : NULL ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_17 ( F_1 ( V_3 ) ) ;
}
static int F_18 ( struct V_14 * V_14 , bool V_36 )
{
struct V_4 * V_15 ;
V_15 = F_15 ( sizeof( * V_15 ) , V_35 ) ;
if ( ! V_15 ) {
F_19 ( L_2 , V_37 ) ;
return - V_38 ;
}
V_15 -> V_23 = V_39 ;
V_15 -> V_9 = V_11 ;
V_14 -> V_18 = V_40 ;
V_14 -> V_22 = V_41 ;
V_14 -> V_34 = 0 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_42 = V_43 *
F_20 ( 10 ) ;
if ( V_36 )
F_21 ( & V_44 ,
V_45 ) ;
return 0 ;
}
static void F_22 ( struct V_14 * V_14 , bool V_36 )
{
if ( V_36 )
F_23 ( & V_44 ,
V_45 ) ;
F_17 ( V_14 -> V_15 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_13 = F_1 ( V_7 -> V_12 ) ;
V_13 -> V_19 = 0 ;
V_13 -> V_20 = V_7 -> V_24 ;
}
static int F_25 ( struct V_46 * V_47 , unsigned long V_48 ,
void * V_49 )
{
struct V_50 * V_51 = V_49 ;
struct V_6 * V_7 = F_26 ( V_51 -> V_52 ) ;
struct V_1 * V_13 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_53 != V_54 )
return 0 ;
V_13 = F_1 ( V_7 -> V_12 ) ;
if ( V_13 -> V_20 > V_7 -> V_10
|| V_13 -> V_20 < V_7 -> V_25 )
V_13 -> V_20 = V_51 -> V_55 ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( V_54 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( V_54 ) ;
}
struct V_56 * F_31 ( void )
{
return V_54 ;
}
