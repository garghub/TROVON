static inline bool F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return V_2 & V_4 ? 1 : 0 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
while ( ! F_1 ( V_8 -> V_1 ) )
F_5 () ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
return F_1 ( V_8 -> V_1 ) ;
}
static unsigned long F_7 ( struct V_5 * V_6 ,
unsigned long V_9 )
{
T_1 V_10 ;
T_1 div ;
unsigned long V_11 = V_9 ;
struct V_7 * V_8 = F_4 ( V_6 ) ;
const struct V_12 * V_13 = V_8 -> V_13 ;
const struct V_14 * V_15 =
V_8 -> V_15 ;
unsigned int V_16 ;
F_2 ( V_8 -> V_1 , V_17 , & V_16 ) ;
V_16 &= V_13 -> V_18 ;
V_10 = ( V_16 >> V_13 -> V_19 ) & V_20 ;
div = ( V_16 >> V_21 ) & V_22 ;
if ( V_15 -> V_23 && V_10 == V_24 )
V_11 /= 3 ;
else
V_11 >>= V_10 ;
V_11 /= V_15 -> V_25 [ div ] ;
if ( V_11 < V_15 -> V_26 . V_27 )
F_8 ( L_1 ) ;
else if ( V_11 > V_15 -> V_26 . V_28 )
F_8 ( L_2 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
unsigned int V_16 ;
F_2 ( V_8 -> V_1 , V_17 , & V_16 ) ;
return V_16 & V_29 ;
}
static struct V_5 * T_2
F_10 ( struct V_1 * V_1 ,
const char * V_30 , int V_31 ,
const char * * V_32 ,
const struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_7 * V_8 ;
struct V_33 V_34 ;
struct V_5 * V_6 ;
int V_35 ;
if ( ! V_30 || ! V_31 || ! V_32 )
return F_11 ( - V_36 ) ;
V_8 = F_12 ( sizeof( * V_8 ) , V_37 ) ;
if ( ! V_8 )
return F_11 ( - V_38 ) ;
V_34 . V_30 = V_30 ;
V_34 . V_39 = & V_40 ;
V_34 . V_32 = V_32 ;
V_34 . V_31 = V_31 ;
V_34 . V_41 = 0 ;
V_8 -> V_6 . V_34 = & V_34 ;
V_8 -> V_13 = V_13 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_1 = V_1 ;
V_6 = & V_8 -> V_6 ;
V_35 = F_13 ( NULL , & V_8 -> V_6 ) ;
if ( V_35 ) {
F_14 ( V_8 ) ;
V_6 = F_11 ( V_35 ) ;
}
return V_6 ;
}
static struct V_14 * T_2
F_15 ( struct V_42 * V_43 )
{
struct V_14 * V_15 ;
V_15 = F_12 ( sizeof( * V_15 ) , V_37 ) ;
if ( ! V_15 )
return NULL ;
if ( F_16 ( V_43 , L_3 , & V_15 -> V_26 ) )
goto V_44;
F_17 ( V_43 , L_4 ,
V_15 -> V_25 , 4 ) ;
V_15 -> V_23 =
F_18 ( V_43 , L_5 ) ;
return V_15 ;
V_44:
F_14 ( V_15 ) ;
return NULL ;
}
static void T_2
F_19 ( struct V_42 * V_43 ,
const struct V_12 * V_13 )
{
struct V_5 * V_6 ;
unsigned int V_31 ;
const char * V_32 [ V_45 ] ;
const char * V_30 = V_43 -> V_30 ;
struct V_14 * V_15 ;
struct V_1 * V_1 ;
V_31 = F_20 ( V_43 ) ;
if ( V_31 == 0 || V_31 > V_45 )
return;
F_21 ( V_43 , V_32 , V_31 ) ;
F_22 ( V_43 , L_6 , & V_30 ) ;
V_15 = F_15 ( V_43 ) ;
if ( ! V_15 )
return;
V_1 = F_23 ( F_24 ( V_43 ) ) ;
if ( F_25 ( V_1 ) )
return;
V_6 = F_10 ( V_1 , V_30 , V_31 ,
V_32 , V_13 ,
V_15 ) ;
if ( F_25 ( V_6 ) )
goto V_44;
F_26 ( V_43 , V_46 , V_6 ) ;
return;
V_44:
F_14 ( V_15 ) ;
}
static void T_2 F_27 ( struct V_42 * V_43 )
{
F_19 ( V_43 , & V_47 ) ;
}
static void T_2 F_28 ( struct V_42 * V_43 )
{
F_19 ( V_43 , & V_48 ) ;
}
