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
struct V_3 * V_4 = V_12 -> V_14 . V_15 ;
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
static void F_6 ( struct V_28 * V_29 )
{
struct V_11 * V_12 = F_7 ( V_29 ,
struct V_11 , V_14 . V_29 . V_29 ) ;
unsigned int V_9 = V_12 -> V_14 . V_15 -> V_9 ;
struct V_11 * V_30 = & F_4 ( V_13 ,
V_9 ) ;
struct V_16 * V_16 = V_12 -> V_14 . V_15 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_18 ;
int V_31 = F_8 ( V_2 -> V_32 ) ;
bool V_33 = true ;
F_9 ( & V_30 -> V_14 . V_34 ) ;
if ( ! F_10 ( & V_30 -> V_14 , V_2 -> V_32 ) )
V_33 = false ;
else
F_11 ( V_16 , V_9 ) ;
F_12 ( V_16 , V_12 -> V_14 . V_15 , V_31 , V_33 ) ;
F_13 ( & V_30 -> V_14 . V_34 ) ;
}
static int F_14 ( struct V_35 * V_36 , unsigned long V_37 ,
void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_11 * V_12 =
& F_4 ( V_13 , V_40 -> V_9 ) ;
struct V_3 * V_4 ;
if ( ! V_12 -> V_41 )
return 0 ;
V_4 = V_12 -> V_14 . V_15 ;
if ( V_12 -> V_21 > V_4 -> V_7
|| V_12 -> V_21 < V_4 -> V_26 )
V_12 -> V_21 = V_40 -> V_42 ;
return 0 ;
}
static T_1 F_15 ( struct V_16 * V_16 ,
const char * V_43 , T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 || V_45 > V_47 || V_45 < 1 )
return - V_48 ;
V_2 -> V_23 = V_45 ;
return V_44 ;
}
static T_1 F_16 ( struct V_16 * V_16 , const char * V_43 ,
T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 )
return - V_48 ;
V_2 -> V_32 = V_7 ( V_45 , V_16 -> V_49 ) ;
return V_44 ;
}
static T_1 F_17 ( struct V_16 * V_16 , const char * V_43 ,
T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 || V_45 > 100 || V_45 <= V_2 -> V_24 )
return - V_48 ;
V_2 -> V_19 = V_45 ;
return V_44 ;
}
static T_1 F_18 ( struct V_16 * V_16 , const char * V_43 ,
T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 || V_45 < 11 || V_45 > 100 ||
V_45 >= V_2 -> V_19 )
return - V_48 ;
V_2 -> V_24 = V_45 ;
return V_44 ;
}
static T_1 F_19 ( struct V_16 * V_16 ,
const char * V_43 , T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 , V_50 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 )
return - V_48 ;
if ( V_45 > 1 )
V_45 = 1 ;
if ( V_45 == V_2 -> V_51 )
return V_44 ;
V_2 -> V_51 = V_45 ;
F_20 (j) {
struct V_11 * V_12 ;
V_12 = & F_4 ( V_13 , V_50 ) ;
V_12 -> V_14 . V_52 = F_21 ( V_50 ,
& V_12 -> V_14 . V_53 , 0 ) ;
if ( V_2 -> V_51 )
V_12 -> V_14 . V_54 =
F_22 ( V_50 ) . V_55 [ V_56 ] ;
}
return V_44 ;
}
static T_1 F_23 ( struct V_16 * V_16 , const char * V_43 ,
T_2 V_44 )
{
struct V_1 * V_2 = V_16 -> V_18 ;
unsigned int V_45 ;
int V_46 ;
V_46 = sscanf ( V_43 , L_1 , & V_45 ) ;
if ( V_46 != 1 )
return - V_48 ;
if ( V_45 > 100 )
V_45 = 100 ;
V_2 -> V_6 = V_45 ;
return V_44 ;
}
static int F_24 ( struct V_16 * V_16 , bool V_57 )
{
struct V_1 * V_18 ;
V_18 = F_25 ( sizeof( * V_18 ) , V_58 ) ;
if ( ! V_18 ) {
F_26 ( L_2 , V_59 ) ;
return - V_60 ;
}
V_18 -> V_19 = V_61 ;
V_18 -> V_24 = V_62 ;
V_18 -> V_23 = V_63 ;
V_18 -> V_51 = 0 ;
V_18 -> V_6 = V_8 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_49 = V_64 *
F_27 ( 10 ) ;
if ( V_57 )
F_28 ( & V_65 ,
V_66 ) ;
return 0 ;
}
static void F_29 ( struct V_16 * V_16 , bool V_57 )
{
if ( V_57 )
F_30 ( & V_65 ,
V_66 ) ;
F_31 ( V_16 -> V_18 ) ;
}
static int F_32 ( struct V_3 * V_4 ,
unsigned int V_67 )
{
return F_33 ( V_4 , & V_68 , V_67 ) ;
}
static int T_3 F_34 ( void )
{
return F_35 ( & V_69 ) ;
}
static void T_4 F_36 ( void )
{
F_37 ( & V_69 ) ;
}
