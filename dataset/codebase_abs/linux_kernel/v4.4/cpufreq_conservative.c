static inline unsigned int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 = ( V_2 -> V_6 * V_4 -> V_7 ) / 100 ;
if ( F_2 ( V_5 == 0 ) )
V_5 = V_8 ;
return V_5 ;
}
static void F_3 ( int V_9 , unsigned int V_10 )
{
struct V_11 * V_12 = & F_4 ( V_13 , V_9 ) ;
struct V_3 * V_4 = V_12 -> V_14 . V_15 -> V_4 ;
struct V_16 * V_16 = V_4 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_18 ;
if ( V_2 -> V_6 == 0 )
return;
if ( V_10 > V_2 -> V_19 ) {
V_12 -> V_20 = 0 ;
if ( V_12 -> V_21 == V_4 -> V_7 )
return;
V_12 -> V_21 += F_1 ( V_2 , V_4 ) ;
if ( V_12 -> V_21 > V_4 -> V_7 )
V_12 -> V_21 = V_4 -> V_7 ;
F_5 ( V_4 , V_12 -> V_21 ,
V_22 ) ;
return;
}
if ( ++ V_12 -> V_20 < V_2 -> V_23 )
return;
V_12 -> V_20 = 0 ;
if ( V_10 < V_2 -> V_24 ) {
unsigned int V_5 ;
if ( V_4 -> V_25 == V_4 -> V_26 )
return;
V_5 = F_1 ( V_2 , V_4 ) ;
if ( V_12 -> V_21 > V_5 )
V_12 -> V_21 -= V_5 ;
else
V_12 -> V_21 = V_4 -> V_26 ;
F_5 ( V_4 , V_12 -> V_21 ,
V_27 ) ;
return;
}
}
static unsigned int F_6 ( struct V_28 * V_14 ,
struct V_16 * V_16 , bool V_29 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
if ( V_29 )
F_7 ( V_16 , V_14 -> V_15 -> V_4 -> V_9 ) ;
return F_8 ( V_2 -> V_30 ) ;
}
static int F_9 ( struct V_31 * V_32 , unsigned long V_33 ,
void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_11 * V_12 =
& F_4 ( V_13 , V_36 -> V_9 ) ;
struct V_3 * V_4 = F_10 ( V_36 -> V_9 ) ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_37 != & V_38 )
return 0 ;
if ( V_12 -> V_21 > V_4 -> V_7
|| V_12 -> V_21 < V_4 -> V_26 )
V_12 -> V_21 = V_36 -> V_39 ;
return 0 ;
}
static T_1 F_11 ( struct V_16 * V_16 ,
const char * V_40 , T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 || V_42 > V_44 || V_42 < 1 )
return - V_45 ;
V_2 -> V_23 = V_42 ;
return V_41 ;
}
static T_1 F_12 ( struct V_16 * V_16 , const char * V_40 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 )
return - V_45 ;
V_2 -> V_30 = V_7 ( V_42 , V_16 -> V_46 ) ;
return V_41 ;
}
static T_1 F_13 ( struct V_16 * V_16 , const char * V_40 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 || V_42 > 100 || V_42 <= V_2 -> V_24 )
return - V_45 ;
V_2 -> V_19 = V_42 ;
return V_41 ;
}
static T_1 F_14 ( struct V_16 * V_16 , const char * V_40 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 || V_42 < 11 || V_42 > 100 ||
V_42 >= V_2 -> V_19 )
return - V_45 ;
V_2 -> V_24 = V_42 ;
return V_41 ;
}
static T_1 F_15 ( struct V_16 * V_16 ,
const char * V_40 , T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 , V_47 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 )
return - V_45 ;
if ( V_42 > 1 )
V_42 = 1 ;
if ( V_42 == V_2 -> V_48 )
return V_41 ;
V_2 -> V_48 = V_42 ;
F_16 (j) {
struct V_11 * V_12 ;
V_12 = & F_4 ( V_13 , V_47 ) ;
V_12 -> V_14 . V_49 = F_17 ( V_47 ,
& V_12 -> V_14 . V_50 , 0 ) ;
if ( V_2 -> V_48 )
V_12 -> V_14 . V_51 =
F_18 ( V_47 ) . V_52 [ V_53 ] ;
}
return V_41 ;
}
static T_1 F_19 ( struct V_16 * V_16 , const char * V_40 ,
T_2 V_41 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_42 ;
int V_43 ;
V_43 = sscanf ( V_40 , L_1 , & V_42 ) ;
if ( V_43 != 1 )
return - V_45 ;
if ( V_42 > 100 )
V_42 = 100 ;
V_2 -> V_6 = V_42 ;
return V_41 ;
}
static int F_20 ( struct V_16 * V_16 , bool V_54 )
{
struct V_1 * V_18 ;
V_18 = F_21 ( sizeof( * V_18 ) , V_55 ) ;
if ( ! V_18 ) {
F_22 ( L_2 , V_56 ) ;
return - V_57 ;
}
V_18 -> V_19 = V_58 ;
V_18 -> V_24 = V_59 ;
V_18 -> V_23 = V_60 ;
V_18 -> V_48 = 0 ;
V_18 -> V_6 = V_8 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_46 = V_61 *
F_23 ( 10 ) ;
if ( V_54 )
F_24 ( & V_62 ,
V_63 ) ;
return 0 ;
}
static void F_25 ( struct V_16 * V_16 , bool V_54 )
{
if ( V_54 )
F_26 ( & V_62 ,
V_63 ) ;
F_27 ( V_16 -> V_18 ) ;
}
static int F_28 ( struct V_3 * V_4 ,
unsigned int V_64 )
{
return F_29 ( V_4 , & V_65 , V_64 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_38 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_38 ) ;
}
