static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 V_5 ;
unsigned long V_6 = 0 , V_7 = 0 ;
int V_8 , V_9 = 0 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_10 ; V_8 ++ ) {
if ( ! V_2 -> V_11 [ V_8 ] )
continue;
V_9 = F_2 ( V_2 -> V_11 [ V_8 ] , & V_5 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_8 == 0 || V_5 . V_6 > V_6 ) {
V_6 = V_5 . V_6 ;
V_7 = V_5 . V_7 ;
}
}
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_7 ;
return V_9 ;
}
static int F_3 ( struct V_12 * V_13 , unsigned long * V_14 , T_1 V_15 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 , V_19 , V_20 , V_21 , V_22 ;
int V_9 = 0 ;
F_5 () ;
V_17 = F_6 ( V_13 , V_14 , V_15 ) ;
if ( F_7 ( V_17 ) ) {
F_8 ( V_13 , L_1 ) ;
F_9 () ;
return F_10 ( V_17 ) ;
}
V_19 = F_11 ( V_17 ) ;
V_21 = F_12 ( V_17 ) ;
V_18 = F_11 ( V_2 -> V_23 ) ;
V_20 = F_12 ( V_2 -> V_23 ) ;
F_9 () ;
if ( V_18 == V_19 )
return 0 ;
V_22 = V_21 * V_2 -> V_24 / 100 ;
F_13 ( & V_2 -> V_25 ) ;
if ( V_18 < V_19 ) {
V_9 = F_14 ( V_2 -> V_26 , V_21 , V_22 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_13 , L_2 ) ;
goto V_27;
}
}
V_9 = F_15 ( V_2 -> V_28 , V_19 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_3 ) ;
F_15 ( V_2 -> V_28 , V_18 ) ;
goto V_27;
}
if ( V_18 > V_19 ) {
V_9 = F_14 ( V_2 -> V_26 , V_21 , V_22 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 -> V_13 , L_2 ) ;
goto V_27;
}
}
V_2 -> V_23 = V_17 ;
F_16 ( V_13 , L_4 ,
V_18 / 1000 , V_19 / 1000 ) ;
V_27:
F_17 ( & V_2 -> V_25 ) ;
return V_9 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_3 V_4 ;
int V_9 ;
F_5 () ;
V_30 -> V_31 = F_11 ( V_2 -> V_23 ) ;
F_9 () ;
V_9 = F_1 ( V_2 , & V_4 ) ;
if ( V_9 < 0 ) {
V_30 -> V_32 = V_30 -> V_33 = 0 ;
goto V_34;
}
V_30 -> V_33 = ( V_4 . V_6 * 100 ) / V_2 -> V_35 ;
V_30 -> V_32 = V_4 . V_7 ;
F_16 ( V_13 , L_5 , V_30 -> V_33 ,
V_30 -> V_32 ) ;
V_34:
V_9 = F_19 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_6 ) ;
return V_9 ;
}
return V_9 ;
}
static void F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_9 ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 < 0 )
F_22 ( V_13 , L_7 ) ;
if ( V_2 -> V_26 )
F_23 ( V_2 -> V_26 ) ;
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_28 ) ;
}
static int F_26 ( struct V_12 * V_13 , unsigned long * V_14 ,
T_1 V_15 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 , V_19 ;
int V_9 = 0 ;
F_5 () ;
V_17 = F_6 ( V_13 , V_14 , V_15 ) ;
if ( F_7 ( V_17 ) ) {
F_8 ( V_13 , L_1 ) ;
F_9 () ;
return F_10 ( V_17 ) ;
}
V_19 = F_11 ( V_17 ) ;
V_18 = F_11 ( V_2 -> V_23 ) ;
F_9 () ;
if ( V_18 == V_19 )
return 0 ;
F_13 ( & V_2 -> V_25 ) ;
V_9 = F_15 ( V_2 -> V_28 , V_19 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_8 ) ;
goto V_27;
}
* V_14 = V_19 ;
V_2 -> V_23 = V_17 ;
F_16 ( V_13 , L_4 ,
V_18 / 1000 , V_19 / 1000 ) ;
V_27:
F_17 ( & V_2 -> V_25 ) ;
return V_9 ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_28 ) ;
}
static int F_28 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_8 , V_9 , V_38 , V_39 ;
V_2 -> V_26 = F_29 ( V_13 , L_9 ) ;
if ( F_7 ( V_2 -> V_26 ) ) {
F_8 ( V_13 , L_10 ) ;
return F_10 ( V_2 -> V_26 ) ;
}
V_9 = F_30 ( V_2 -> V_26 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_11 ) ;
return V_9 ;
}
V_38 = F_31 ( V_13 ) ;
if ( V_38 < 0 ) {
F_8 ( V_13 , L_12 ) ;
V_9 = V_38 ;
goto V_40;
}
V_2 -> V_10 = V_38 ;
V_39 = sizeof( * V_2 -> V_11 ) * V_38 ;
V_2 -> V_11 = F_32 ( V_13 , V_39 , V_41 ) ;
if ( ! V_2 -> V_11 ) {
V_9 = - V_42 ;
goto V_40;
}
for ( V_8 = 0 ; V_8 < V_38 ; V_8 ++ ) {
V_2 -> V_11 [ V_8 ] = F_33 ( V_13 , V_8 ) ;
if ( F_7 ( V_2 -> V_11 [ V_8 ] ) ) {
V_9 = - V_43 ;
goto V_40;
}
}
if ( F_34 ( V_37 , L_13 , & V_2 -> V_35 ) )
V_2 -> V_35 = V_44 ;
if ( F_34 ( V_37 , L_14 ,
& V_2 -> V_24 ) )
V_2 -> V_24 = V_45 ;
return 0 ;
V_40:
F_23 ( V_2 -> V_26 ) ;
return V_9 ;
}
static int F_35 ( struct V_36 * V_37 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
unsigned long V_46 ;
int V_9 ;
V_2 -> V_28 = F_36 ( V_13 , L_15 ) ;
if ( F_7 ( V_2 -> V_28 ) ) {
F_8 ( V_13 , L_16 ) ;
return F_10 ( V_2 -> V_28 ) ;
}
V_9 = F_37 ( V_2 -> V_28 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_17 ) ;
return V_9 ;
}
F_5 () ;
V_9 = F_38 ( V_13 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_18 ) ;
F_9 () ;
goto V_47;
}
V_46 = F_39 ( V_2 -> V_28 ) ;
V_2 -> V_23 = F_6 ( V_13 , & V_46 , 0 ) ;
if ( F_7 ( V_2 -> V_23 ) ) {
F_8 ( V_13 , L_19 ) ;
F_9 () ;
V_9 = F_10 ( V_2 -> V_23 ) ;
goto V_48;
}
F_9 () ;
return 0 ;
V_48:
F_24 ( V_13 ) ;
V_47:
F_25 ( V_2 -> V_28 ) ;
return V_9 ;
}
static int F_40 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = & V_50 -> V_13 ;
struct V_36 * V_37 = V_13 -> V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
int V_9 , V_60 ;
unsigned long V_61 , V_62 ;
if ( ! V_37 ) {
F_8 ( V_13 , L_20 ) ;
return - V_63 ;
}
V_2 = F_32 ( & V_50 -> V_13 , sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
F_41 ( & V_2 -> V_25 ) ;
V_2 -> V_13 = & V_50 -> V_13 ;
F_42 ( V_50 , V_2 ) ;
V_9 = F_35 ( V_37 , V_2 ) ;
if ( V_9 < 0 )
goto V_34;
V_53 = F_32 ( V_13 , sizeof( * V_53 ) , V_41 ) ;
if ( ! V_53 ) {
V_9 = - V_42 ;
goto V_34;
}
if ( F_43 ( V_13 -> V_51 , L_21 , 0 ) )
goto V_64;
else
V_9 = F_28 ( V_37 , V_2 ) ;
if ( V_9 < 0 )
goto V_34;
V_53 -> V_65 = 50 ;
V_53 -> V_66 = F_3 ;
V_53 -> V_67 = F_18 ;
V_53 -> exit = F_20 ;
V_55 = F_32 ( V_13 , sizeof( * V_55 ) , V_41 ) ;
if ( ! V_55 ) {
V_9 = - V_42 ;
goto V_34;
}
V_55 -> V_68 = 40 ;
V_55 -> V_69 = 5 ;
V_2 -> V_58 = F_44 ( V_13 , V_53 , L_22 ,
V_55 ) ;
if ( F_7 ( V_2 -> V_58 ) ) {
F_8 ( V_13 , L_23 ) ;
V_9 = F_10 ( V_2 -> V_58 ) ;
goto V_34;
}
V_9 = F_45 ( V_13 , V_2 -> V_58 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_24 ) ;
goto V_34;
}
V_9 = F_46 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_25 ) ;
goto V_34;
}
V_9 = F_19 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_6 ) ;
goto V_34;
}
goto V_27;
V_64:
V_53 -> V_66 = F_26 ;
V_53 -> exit = F_27 ;
V_59 = F_47 ( V_13 , 0 ) ;
if ( F_7 ( V_59 ) ) {
V_9 = - V_43 ;
goto V_34;
}
V_57 = F_32 ( V_13 , sizeof( * V_57 ) , V_41 ) ;
if ( ! V_57 ) {
V_9 = - V_42 ;
goto V_34;
}
V_57 -> V_70 = V_59 ;
V_2 -> V_58 = F_44 ( V_13 , V_53 , L_26 ,
V_57 ) ;
if ( F_7 ( V_2 -> V_58 ) ) {
F_8 ( V_13 ,
L_27 ) ;
V_9 = - V_43 ;
goto V_34;
}
V_27:
V_60 = V_2 -> V_58 -> V_53 -> V_60 ;
V_61 = ( V_2 -> V_58 -> V_53 -> V_71 [ 0 ] / 1000 ) ;
V_62 = ( V_2 -> V_58 -> V_53 -> V_71 [ V_60 - 1 ] / 1000 ) ;
F_48 ( L_28 ,
F_49 ( V_13 ) , V_61 , V_62 ) ;
return 0 ;
V_34:
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_28 ) ;
return V_9 ;
}
static int F_50 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_9 ;
V_9 = F_46 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_29 ) ;
return V_9 ;
}
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_9 ;
V_9 = F_21 ( V_2 ) ;
if ( V_9 < 0 ) {
F_8 ( V_13 , L_7 ) ;
return V_9 ;
}
return 0 ;
}
