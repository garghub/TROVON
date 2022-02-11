static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 + V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
F_6 ( ( V_7 ) V_2 -> V_8 != V_2 -> V_8 ) ;
F_7 ( V_2 -> V_8 , V_4 -> V_5 + V_9 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , unsigned V_10 ,
void * V_11 , unsigned V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_5 = V_4 -> V_5 +
F_9 ( V_4 ) + V_10 ;
T_3 * V_13 = V_11 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
V_13 [ V_14 ] = F_10 ( V_5 + V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_10 ,
const void * V_11 , unsigned V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_5 = V_4 -> V_5 +
F_9 ( V_4 ) + V_10 ;
const T_3 * V_13 = V_11 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ )
F_12 ( V_13 [ V_14 ] , V_5 + V_14 ) ;
}
static T_3 F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_10 ( V_4 -> V_5 + V_15 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_3 V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_16 == 0 ) ;
F_12 ( V_16 , V_4 -> V_5 + V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( 0 , V_4 -> V_5 + V_15 ) ;
F_10 ( V_4 -> V_5 + V_15 ) ;
F_16 ( V_2 ) ;
}
static T_4 F_17 ( struct V_3 * V_4 , T_4 V_17 )
{
F_18 ( V_17 , V_4 -> V_5 + V_18 ) ;
return F_19 ( V_4 -> V_5 + V_18 ) ;
}
static struct V_19 * F_20 ( struct V_3 * V_4 ,
struct V_20 * V_21 ,
unsigned V_22 ,
void (* F_21)( struct V_19 * V_23 ) ,
const char * V_24 ,
T_4 V_25 )
{
struct V_19 * V_23 ;
unsigned long V_26 ;
T_4 V_27 ;
int V_28 ;
F_18 ( V_22 , V_4 -> V_5 + V_29 ) ;
V_27 = F_19 ( V_4 -> V_5 + V_30 ) ;
if ( ! V_27 || F_3 ( V_4 -> V_5 + V_31 ) )
return F_22 ( - V_32 ) ;
V_21 -> V_27 = V_27 ;
V_21 -> V_33 = V_25 ;
V_26 = F_23 ( F_24 ( V_27 , V_34 ) ) ;
V_21 -> V_35 = F_25 ( V_26 , V_36 | V_37 ) ;
if ( V_21 -> V_35 == NULL )
return F_22 ( - V_38 ) ;
F_7 ( F_26 ( V_21 -> V_35 ) >> V_39 ,
V_4 -> V_5 + V_31 ) ;
V_23 = F_27 ( V_22 , V_21 -> V_27 ,
V_34 , & V_4 -> V_2 ,
true , V_21 -> V_35 , V_40 , F_21 , V_24 ) ;
if ( ! V_23 ) {
V_28 = - V_38 ;
goto V_41;
}
V_23 -> V_42 = ( void V_43 * ) V_4 -> V_5 + V_44 ;
if ( V_25 != V_45 ) {
F_18 ( V_25 , V_4 -> V_5 + V_46 ) ;
V_25 = F_19 ( V_4 -> V_5 + V_46 ) ;
if ( V_25 == V_45 ) {
V_28 = - V_47 ;
goto V_48;
}
}
return V_23 ;
V_48:
F_28 ( V_23 ) ;
V_41:
F_7 ( 0 , V_4 -> V_5 + V_31 ) ;
F_29 ( V_21 -> V_35 , V_26 ) ;
return F_22 ( V_28 ) ;
}
static void F_30 ( struct V_20 * V_21 )
{
struct V_19 * V_23 = V_21 -> V_23 ;
struct V_3 * V_4 = F_2 ( V_23 -> V_2 ) ;
unsigned long V_26 ;
F_18 ( V_23 -> V_22 , V_4 -> V_5 + V_29 ) ;
if ( V_4 -> V_49 ) {
F_18 ( V_45 ,
V_4 -> V_5 + V_46 ) ;
F_10 ( V_4 -> V_5 + V_50 ) ;
}
F_28 ( V_23 ) ;
F_7 ( 0 , V_4 -> V_5 + V_31 ) ;
V_26 = F_23 ( F_24 ( V_21 -> V_27 , V_34 ) ) ;
F_29 ( V_21 -> V_35 , V_26 ) ;
}
int F_31 ( struct V_3 * V_4 )
{
struct V_51 * V_51 = V_4 -> V_51 ;
int V_52 ;
if ( V_51 -> V_53 < 0x1000 || V_51 -> V_53 > 0x103f )
return - V_54 ;
if ( V_51 -> V_55 != V_56 ) {
F_32 ( V_57 L_1 ,
V_56 , V_51 -> V_55 ) ;
return - V_54 ;
}
V_52 = F_33 ( V_51 , 0 , L_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = - V_38 ;
V_4 -> V_5 = F_34 ( V_51 , 0 , 0 ) ;
if ( ! V_4 -> V_5 )
goto V_58;
V_4 -> V_59 = V_4 -> V_5 + V_50 ;
V_4 -> V_2 . V_60 . V_61 = V_51 -> V_62 ;
V_4 -> V_2 . V_60 . V_53 = V_51 -> V_63 ;
V_4 -> V_2 . V_64 = & V_65 ;
V_4 -> V_66 = F_17 ;
V_4 -> F_20 = F_20 ;
V_4 -> F_30 = F_30 ;
return 0 ;
V_58:
F_35 ( V_51 , 0 ) ;
return V_52 ;
}
void F_36 ( struct V_3 * V_4 )
{
struct V_51 * V_51 = V_4 -> V_51 ;
F_37 ( V_51 , V_4 -> V_5 ) ;
F_35 ( V_51 , 0 ) ;
}
