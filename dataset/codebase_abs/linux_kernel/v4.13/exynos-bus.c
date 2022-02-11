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
unsigned long V_18 , V_19 , V_20 , V_21 ;
int V_9 = 0 ;
V_17 = F_5 ( V_13 , V_14 , V_15 ) ;
if ( F_6 ( V_17 ) ) {
F_7 ( V_13 , L_1 ) ;
return F_8 ( V_17 ) ;
}
V_19 = F_9 ( V_17 ) ;
V_20 = F_10 ( V_17 ) ;
F_11 ( V_17 ) ;
V_18 = V_2 -> V_22 ;
if ( V_18 == V_19 )
return 0 ;
V_21 = V_20 * V_2 -> V_23 / 100 ;
F_12 ( & V_2 -> V_24 ) ;
if ( V_18 < V_19 ) {
V_9 = F_13 ( V_2 -> V_25 , V_20 , V_21 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_13 , L_2 ) ;
goto V_26;
}
}
V_9 = F_14 ( V_2 -> V_27 , V_19 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_3 ) ;
F_14 ( V_2 -> V_27 , V_18 ) ;
goto V_26;
}
if ( V_18 > V_19 ) {
V_9 = F_13 ( V_2 -> V_25 , V_20 , V_21 ) ;
if ( V_9 < 0 ) {
F_7 ( V_2 -> V_13 , L_2 ) ;
goto V_26;
}
}
V_2 -> V_22 = V_19 ;
F_15 ( V_13 , L_4 ,
V_18 , V_19 , F_16 ( V_2 -> V_27 ) ) ;
V_26:
F_17 ( & V_2 -> V_24 ) ;
return V_9 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_3 V_4 ;
int V_9 ;
V_29 -> V_30 = V_2 -> V_22 ;
V_9 = F_1 ( V_2 , & V_4 ) ;
if ( V_9 < 0 ) {
V_29 -> V_31 = V_29 -> V_32 = 0 ;
goto V_33;
}
V_29 -> V_32 = ( V_4 . V_6 * 100 ) / V_2 -> V_34 ;
V_29 -> V_31 = V_4 . V_7 ;
F_15 ( V_13 , L_5 , V_29 -> V_32 ,
V_29 -> V_31 ) ;
V_33:
V_9 = F_19 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_6 ) ;
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
if ( V_2 -> V_25 )
F_23 ( V_2 -> V_25 ) ;
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_27 ) ;
}
static int F_26 ( struct V_12 * V_13 , unsigned long * V_14 ,
T_1 V_15 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
struct V_16 * V_17 ;
unsigned long V_18 , V_19 ;
int V_9 = 0 ;
V_17 = F_5 ( V_13 , V_14 , V_15 ) ;
if ( F_6 ( V_17 ) ) {
F_7 ( V_13 , L_1 ) ;
return F_8 ( V_17 ) ;
}
V_19 = F_9 ( V_17 ) ;
F_11 ( V_17 ) ;
V_18 = V_2 -> V_22 ;
if ( V_18 == V_19 )
return 0 ;
F_12 ( & V_2 -> V_24 ) ;
V_9 = F_14 ( V_2 -> V_27 , V_19 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_8 ) ;
goto V_26;
}
* V_14 = V_19 ;
V_2 -> V_22 = V_19 ;
F_15 ( V_13 , L_4 ,
V_18 , V_19 , F_16 ( V_2 -> V_27 ) ) ;
V_26:
F_17 ( & V_2 -> V_24 ) ;
return V_9 ;
}
static void F_27 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_27 ) ;
}
static int F_28 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_8 , V_9 , V_37 , V_38 ;
V_2 -> V_25 = F_29 ( V_13 , L_9 ) ;
if ( F_6 ( V_2 -> V_25 ) ) {
F_7 ( V_13 , L_10 ) ;
return F_8 ( V_2 -> V_25 ) ;
}
V_9 = F_30 ( V_2 -> V_25 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_11 ) ;
return V_9 ;
}
V_37 = F_31 ( V_13 ) ;
if ( V_37 < 0 ) {
F_7 ( V_13 , L_12 ) ;
V_9 = V_37 ;
goto V_39;
}
V_2 -> V_10 = V_37 ;
V_38 = sizeof( * V_2 -> V_11 ) * V_37 ;
V_2 -> V_11 = F_32 ( V_13 , V_38 , V_40 ) ;
if ( ! V_2 -> V_11 ) {
V_9 = - V_41 ;
goto V_39;
}
for ( V_8 = 0 ; V_8 < V_37 ; V_8 ++ ) {
V_2 -> V_11 [ V_8 ] = F_33 ( V_13 , V_8 ) ;
if ( F_6 ( V_2 -> V_11 [ V_8 ] ) ) {
V_9 = - V_42 ;
goto V_39;
}
}
if ( F_34 ( V_36 , L_13 , & V_2 -> V_34 ) )
V_2 -> V_34 = V_43 ;
if ( F_34 ( V_36 , L_14 ,
& V_2 -> V_23 ) )
V_2 -> V_23 = V_44 ;
return 0 ;
V_39:
F_23 ( V_2 -> V_25 ) ;
return V_9 ;
}
static int F_35 ( struct V_35 * V_36 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_16 * V_45 ;
unsigned long V_46 ;
int V_9 ;
V_2 -> V_27 = F_36 ( V_13 , L_15 ) ;
if ( F_6 ( V_2 -> V_27 ) ) {
F_7 ( V_13 , L_16 ) ;
return F_8 ( V_2 -> V_27 ) ;
}
V_9 = F_37 ( V_2 -> V_27 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_17 ) ;
return V_9 ;
}
V_9 = F_38 ( V_13 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_18 ) ;
goto V_47;
}
V_46 = F_16 ( V_2 -> V_27 ) ;
V_45 = F_5 ( V_13 , & V_46 , 0 ) ;
if ( F_6 ( V_45 ) ) {
F_7 ( V_13 , L_19 ) ;
V_9 = F_8 ( V_45 ) ;
goto V_48;
}
V_2 -> V_22 = F_9 ( V_45 ) ;
F_11 ( V_45 ) ;
return 0 ;
V_48:
F_24 ( V_13 ) ;
V_47:
F_25 ( V_2 -> V_27 ) ;
return V_9 ;
}
static int F_39 ( struct V_49 * V_50 )
{
struct V_12 * V_13 = & V_50 -> V_13 ;
struct V_35 * V_36 = V_13 -> V_51 , * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
int V_9 , V_61 ;
unsigned long V_62 , V_63 ;
if ( ! V_36 ) {
F_7 ( V_13 , L_20 ) ;
return - V_64 ;
}
V_2 = F_32 ( & V_50 -> V_13 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
F_40 ( & V_2 -> V_24 ) ;
V_2 -> V_13 = & V_50 -> V_13 ;
F_41 ( V_50 , V_2 ) ;
V_9 = F_35 ( V_36 , V_2 ) ;
if ( V_9 < 0 )
return V_9 ;
V_54 = F_32 ( V_13 , sizeof( * V_54 ) , V_40 ) ;
if ( ! V_54 ) {
V_9 = - V_41 ;
goto V_33;
}
V_52 = F_42 ( V_13 -> V_51 , L_21 , 0 ) ;
if ( V_52 ) {
F_43 ( V_52 ) ;
goto V_65;
} else {
V_9 = F_28 ( V_36 , V_2 ) ;
}
if ( V_9 < 0 )
goto V_33;
V_54 -> V_66 = 50 ;
V_54 -> V_67 = F_3 ;
V_54 -> V_68 = F_18 ;
V_54 -> exit = F_20 ;
V_56 = F_32 ( V_13 , sizeof( * V_56 ) , V_40 ) ;
if ( ! V_56 ) {
V_9 = - V_41 ;
goto V_33;
}
V_56 -> V_69 = 40 ;
V_56 -> V_70 = 5 ;
V_2 -> V_59 = F_44 ( V_13 , V_54 , L_22 ,
V_56 ) ;
if ( F_6 ( V_2 -> V_59 ) ) {
F_7 ( V_13 , L_23 ) ;
V_9 = F_8 ( V_2 -> V_59 ) ;
goto V_33;
}
V_9 = F_45 ( V_13 , V_2 -> V_59 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_24 ) ;
goto V_33;
}
V_9 = F_46 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_25 ) ;
goto V_33;
}
V_9 = F_19 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_6 ) ;
goto V_33;
}
goto V_26;
V_65:
V_54 -> V_67 = F_26 ;
V_54 -> exit = F_27 ;
V_60 = F_47 ( V_13 , 0 ) ;
if ( F_6 ( V_60 ) ) {
V_9 = - V_42 ;
goto V_33;
}
V_58 = F_32 ( V_13 , sizeof( * V_58 ) , V_40 ) ;
if ( ! V_58 ) {
V_9 = - V_41 ;
goto V_33;
}
V_58 -> V_71 = V_60 ;
V_2 -> V_59 = F_44 ( V_13 , V_54 , L_26 ,
V_58 ) ;
if ( F_6 ( V_2 -> V_59 ) ) {
F_7 ( V_13 ,
L_27 ) ;
V_9 = F_8 ( V_2 -> V_59 ) ;
goto V_33;
}
V_26:
V_61 = V_2 -> V_59 -> V_54 -> V_61 ;
V_62 = ( V_2 -> V_59 -> V_54 -> V_72 [ 0 ] / 1000 ) ;
V_63 = ( V_2 -> V_59 -> V_54 -> V_72 [ V_61 - 1 ] / 1000 ) ;
F_48 ( L_28 ,
F_49 ( V_13 ) , V_62 , V_63 ) ;
return 0 ;
V_33:
F_24 ( V_13 ) ;
F_25 ( V_2 -> V_27 ) ;
return V_9 ;
}
static int F_50 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 ) ;
int V_9 ;
V_9 = F_46 ( V_2 ) ;
if ( V_9 < 0 ) {
F_7 ( V_13 , L_29 ) ;
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
F_7 ( V_13 , L_7 ) ;
return V_9 ;
}
return 0 ;
}
