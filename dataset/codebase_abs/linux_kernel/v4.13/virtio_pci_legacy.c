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
bool V_25 ,
T_4 V_26 )
{
struct V_19 * V_23 ;
T_4 V_27 ;
int V_28 ;
F_18 ( V_22 , V_4 -> V_5 + V_29 ) ;
V_27 = F_19 ( V_4 -> V_5 + V_30 ) ;
if ( ! V_27 || F_3 ( V_4 -> V_5 + V_31 ) )
return F_22 ( - V_32 ) ;
V_21 -> V_33 = V_26 ;
V_23 = F_23 ( V_22 , V_27 ,
V_34 , & V_4 -> V_2 ,
true , false , V_25 ,
V_35 , F_21 , V_24 ) ;
if ( ! V_23 )
return F_22 ( - V_36 ) ;
F_7 ( F_24 ( V_23 ) >> V_37 ,
V_4 -> V_5 + V_31 ) ;
V_23 -> V_38 = ( void V_39 * ) V_4 -> V_5 + V_40 ;
if ( V_26 != V_41 ) {
F_18 ( V_26 , V_4 -> V_5 + V_42 ) ;
V_26 = F_19 ( V_4 -> V_5 + V_42 ) ;
if ( V_26 == V_41 ) {
V_28 = - V_43 ;
goto V_44;
}
}
return V_23 ;
V_44:
F_7 ( 0 , V_4 -> V_5 + V_31 ) ;
F_25 ( V_23 ) ;
return F_22 ( V_28 ) ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_19 * V_23 = V_21 -> V_23 ;
struct V_3 * V_4 = F_2 ( V_23 -> V_2 ) ;
F_18 ( V_23 -> V_22 , V_4 -> V_5 + V_29 ) ;
if ( V_4 -> V_45 ) {
F_18 ( V_41 ,
V_4 -> V_5 + V_42 ) ;
F_10 ( V_4 -> V_5 + V_46 ) ;
}
F_7 ( 0 , V_4 -> V_5 + V_31 ) ;
F_25 ( V_23 ) ;
}
int F_27 ( struct V_3 * V_4 )
{
struct V_47 * V_47 = V_4 -> V_47 ;
int V_48 ;
if ( V_47 -> V_49 < 0x1000 || V_47 -> V_49 > 0x103f )
return - V_50 ;
if ( V_47 -> V_51 != V_52 ) {
F_28 ( V_53 L_1 ,
V_52 , V_47 -> V_51 ) ;
return - V_50 ;
}
V_48 = F_29 ( & V_47 -> V_54 , F_30 ( 64 ) ) ;
if ( V_48 ) {
V_48 = F_31 ( & V_47 -> V_54 , F_30 ( 32 ) ) ;
} else {
F_32 ( & V_47 -> V_54 ,
F_30 ( 32 + V_37 ) ) ;
}
if ( V_48 )
F_33 ( & V_47 -> V_54 , L_2 ) ;
V_48 = F_34 ( V_47 , 0 , L_3 ) ;
if ( V_48 )
return V_48 ;
V_48 = - V_36 ;
V_4 -> V_5 = F_35 ( V_47 , 0 , 0 ) ;
if ( ! V_4 -> V_5 )
goto V_55;
V_4 -> V_56 = V_4 -> V_5 + V_46 ;
V_4 -> V_2 . V_57 . V_58 = V_47 -> V_59 ;
V_4 -> V_2 . V_57 . V_49 = V_47 -> V_60 ;
V_4 -> V_2 . V_61 = & V_62 ;
V_4 -> V_63 = F_17 ;
V_4 -> F_20 = F_20 ;
V_4 -> F_26 = F_26 ;
return 0 ;
V_55:
F_36 ( V_47 , 0 ) ;
return V_48 ;
}
void F_37 ( struct V_3 * V_4 )
{
struct V_47 * V_47 = V_4 -> V_47 ;
F_38 ( V_47 , V_4 -> V_5 ) ;
F_36 ( V_47 , 0 ) ;
}
