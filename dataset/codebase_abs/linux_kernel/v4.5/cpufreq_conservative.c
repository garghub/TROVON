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
static unsigned int F_6 ( struct V_3 * V_4 , bool V_28 )
{
struct V_16 * V_16 = V_4 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_18 ;
if ( V_28 )
F_7 ( V_16 , V_4 -> V_9 ) ;
return F_8 ( V_2 -> V_29 ) ;
}
static int F_9 ( struct V_30 * V_31 , unsigned long V_32 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_11 * V_12 =
& F_4 ( V_13 , V_35 -> V_9 ) ;
struct V_3 * V_4 = F_10 ( V_35 -> V_9 ) ;
if ( ! V_4 )
return 0 ;
if ( V_4 -> V_36 != & V_37 )
return 0 ;
if ( V_12 -> V_21 > V_4 -> V_7
|| V_12 -> V_21 < V_4 -> V_26 )
V_12 -> V_21 = V_35 -> V_38 ;
return 0 ;
}
static T_1 F_11 ( struct V_16 * V_16 ,
const char * V_39 , T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 || V_41 > V_43 || V_41 < 1 )
return - V_44 ;
V_2 -> V_23 = V_41 ;
return V_40 ;
}
static T_1 F_12 ( struct V_16 * V_16 , const char * V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 )
return - V_44 ;
V_2 -> V_29 = V_7 ( V_41 , V_16 -> V_45 ) ;
return V_40 ;
}
static T_1 F_13 ( struct V_16 * V_16 , const char * V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 || V_41 > 100 || V_41 <= V_2 -> V_24 )
return - V_44 ;
V_2 -> V_19 = V_41 ;
return V_40 ;
}
static T_1 F_14 ( struct V_16 * V_16 , const char * V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 || V_41 < 11 || V_41 > 100 ||
V_41 >= V_2 -> V_19 )
return - V_44 ;
V_2 -> V_24 = V_41 ;
return V_40 ;
}
static T_1 F_15 ( struct V_16 * V_16 ,
const char * V_39 , T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 , V_46 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 )
return - V_44 ;
if ( V_41 > 1 )
V_41 = 1 ;
if ( V_41 == V_2 -> V_47 )
return V_40 ;
V_2 -> V_47 = V_41 ;
F_16 (j) {
struct V_11 * V_12 ;
V_12 = & F_4 ( V_13 , V_46 ) ;
V_12 -> V_14 . V_48 = F_17 ( V_46 ,
& V_12 -> V_14 . V_49 , 0 ) ;
if ( V_2 -> V_47 )
V_12 -> V_14 . V_50 =
F_18 ( V_46 ) . V_51 [ V_52 ] ;
}
return V_40 ;
}
static T_1 F_19 ( struct V_16 * V_16 , const char * V_39 ,
T_2 V_40 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_41 ;
int V_42 ;
V_42 = sscanf ( V_39 , L_1 , & V_41 ) ;
if ( V_42 != 1 )
return - V_44 ;
if ( V_41 > 100 )
V_41 = 100 ;
V_2 -> V_6 = V_41 ;
return V_40 ;
}
static int F_20 ( struct V_16 * V_16 , bool V_53 )
{
struct V_1 * V_18 ;
V_18 = F_21 ( sizeof( * V_18 ) , V_54 ) ;
if ( ! V_18 ) {
F_22 ( L_2 , V_55 ) ;
return - V_56 ;
}
V_18 -> V_19 = V_57 ;
V_18 -> V_24 = V_58 ;
V_18 -> V_23 = V_59 ;
V_18 -> V_47 = 0 ;
V_18 -> V_6 = V_8 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_45 = V_60 *
F_23 ( 10 ) ;
if ( V_53 )
F_24 ( & V_61 ,
V_62 ) ;
return 0 ;
}
static void F_25 ( struct V_16 * V_16 , bool V_53 )
{
if ( V_53 )
F_26 ( & V_61 ,
V_62 ) ;
F_27 ( V_16 -> V_18 ) ;
}
static int F_28 ( struct V_3 * V_4 ,
unsigned int V_63 )
{
return F_29 ( V_4 , & V_64 , V_63 ) ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_37 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_37 ) ;
}
