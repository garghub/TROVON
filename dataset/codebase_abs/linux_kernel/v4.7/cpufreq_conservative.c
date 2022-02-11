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
static T_1 F_8 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_14 * V_14 = F_9 ( V_29 ) ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 > V_34 || V_32 < 1 )
return - V_35 ;
V_14 -> V_22 = V_32 ;
return V_31 ;
}
static T_1 F_10 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_14 * V_14 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 > 100 || V_32 <= V_5 -> V_23 )
return - V_35 ;
V_14 -> V_18 = V_32 ;
return V_31 ;
}
static T_1 F_11 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_14 * V_14 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 || V_32 < 11 || V_32 > 100 ||
V_32 >= V_14 -> V_18 )
return - V_35 ;
V_5 -> V_23 = V_32 ;
return V_31 ;
}
static T_1 F_12 ( struct V_28 * V_29 ,
const char * V_30 , T_2 V_31 )
{
struct V_14 * V_14 = F_9 ( V_29 ) ;
unsigned int V_32 ;
int V_33 ;
V_33 = sscanf ( V_30 , L_1 , & V_32 ) ;
if ( V_33 != 1 )
return - V_35 ;
if ( V_32 > 1 )
V_32 = 1 ;
if ( V_32 == V_14 -> V_36 )
return V_31 ;
V_14 -> V_36 = V_32 ;
F_13 ( V_14 ) ;
return V_31 ;
}
static T_1 F_14 ( struct V_28 * V_29 , const char * V_30 ,
T_2 V_31 )
{
struct V_14 * V_14 = F_9 ( V_29 ) ;
struct V_4 * V_5 = V_14 -> V_15 ;
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
static int F_19 ( struct V_14 * V_14 , bool V_38 )
{
struct V_4 * V_15 ;
V_15 = F_16 ( sizeof( * V_15 ) , V_37 ) ;
if ( ! V_15 ) {
F_20 ( L_2 , V_39 ) ;
return - V_40 ;
}
V_15 -> V_23 = V_41 ;
V_15 -> V_9 = V_11 ;
V_14 -> V_18 = V_42 ;
V_14 -> V_22 = V_43 ;
V_14 -> V_36 = 0 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_44 = V_45 *
F_21 ( 10 ) ;
if ( V_38 )
F_22 ( & V_46 ,
V_47 ) ;
return 0 ;
}
static void F_23 ( struct V_14 * V_14 , bool V_38 )
{
if ( V_38 )
F_24 ( & V_46 ,
V_47 ) ;
F_18 ( V_14 -> V_15 ) ;
}
static void F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_13 = F_1 ( V_7 -> V_12 ) ;
V_13 -> V_19 = 0 ;
V_13 -> V_20 = V_7 -> V_24 ;
}
static int F_26 ( struct V_48 * V_49 , unsigned long V_50 ,
void * V_51 )
{
struct V_52 * V_53 = V_51 ;
struct V_6 * V_7 = F_27 ( V_53 -> V_54 ) ;
struct V_1 * V_13 ;
if ( ! V_7 )
return 0 ;
if ( V_7 -> V_55 != V_56 )
return 0 ;
V_13 = F_1 ( V_7 -> V_12 ) ;
if ( V_13 -> V_20 > V_7 -> V_10
|| V_13 -> V_20 < V_7 -> V_25 )
V_13 -> V_20 = V_53 -> V_57 ;
return 0 ;
}
static int T_3 F_28 ( void )
{
return F_29 ( V_56 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( V_56 ) ;
}
struct V_58 * F_32 ( void )
{
return V_56 ;
}
