static int F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_1 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
T_1 V_9 ;
T_1 V_10 ;
T_1 V_11 ;
T_1 V_12 ;
F_2 ( & V_5 -> V_13 , V_8 ) ;
V_12 = V_11 = F_3 ( V_5 -> V_14 ) ;
V_12 &= ~ V_2 ;
V_12 |= V_3 ;
V_9 = V_12 ^ V_11 ;
if ( ! V_9 ) {
F_4 ( & V_5 -> V_13 , V_8 ) ;
goto V_15;
}
F_5 ( V_12 , V_5 -> V_14 ) ;
F_4 ( & V_5 -> V_13 , V_8 ) ;
F_6 () ;
for ( V_10 = 0 ; V_10 < V_5 -> V_16 ; V_10 ++ ) {
V_7 = & V_5 -> V_17 [ V_10 ] ;
V_12 = F_3 ( V_5 -> V_18 + V_10 ) ;
if ( V_12 & V_9 && V_7 -> V_19 ) {
F_7 ( V_7 -> V_19 ,
V_7 -> V_20 ,
F_8 ( V_7 -> V_21 ) ) ;
}
}
V_15:
return 0 ;
}
static T_2 F_9 ( int V_22 , void * V_1 )
{
struct V_23 * V_24 = V_1 ;
unsigned V_25 ;
int V_26 ;
T_1 V_27 ;
T_1 V_12 ;
V_12 = F_3 ( V_24 -> V_28 ) ;
V_27 = V_12 ^ V_24 -> V_29 ;
V_24 -> V_29 = V_12 ;
F_10 (i, entry->irq_enabled, 32 ) {
if ( ! ( V_27 & F_8 ( V_25 ) ) )
continue;
if ( V_12 & F_8 ( V_25 ) ) {
if ( F_11 ( V_25 , V_24 -> V_30 ) ) {
V_26 = F_12 ( V_24 -> V_31 , V_25 ) ;
F_13 ( V_26 ) ;
}
} else {
if ( F_11 ( V_25 , V_24 -> V_32 ) ) {
V_26 = F_12 ( V_24 -> V_31 , V_25 ) ;
F_13 ( V_26 ) ;
}
}
}
return V_33 ;
}
static void F_14 ( struct V_34 * V_35 )
{
struct V_23 * V_24 = F_15 ( V_35 ) ;
T_3 V_22 = F_16 ( V_35 ) ;
struct V_4 * V_5 = V_24 -> V_5 ;
T_1 V_12 ;
if ( V_24 -> V_18 ) {
V_12 = F_3 ( V_24 -> V_18 + V_5 -> V_36 ) ;
V_12 &= ~ F_8 ( V_22 ) ;
F_5 ( V_12 , V_24 -> V_18 + V_5 -> V_36 ) ;
}
F_17 ( V_22 , V_24 -> V_37 ) ;
}
static void F_18 ( struct V_34 * V_35 )
{
struct V_23 * V_24 = F_15 ( V_35 ) ;
T_3 V_22 = F_16 ( V_35 ) ;
struct V_4 * V_5 = V_24 -> V_5 ;
T_1 V_12 ;
F_19 ( V_22 , V_24 -> V_37 ) ;
if ( V_24 -> V_18 ) {
V_12 = F_3 ( V_24 -> V_18 + V_5 -> V_36 ) ;
V_12 |= F_8 ( V_22 ) ;
F_5 ( V_12 , V_24 -> V_18 + V_5 -> V_36 ) ;
}
}
static int F_20 ( struct V_34 * V_35 , unsigned int type )
{
struct V_23 * V_24 = F_15 ( V_35 ) ;
T_3 V_22 = F_16 ( V_35 ) ;
if ( ! ( type & V_38 ) )
return - V_39 ;
if ( type & V_40 )
F_19 ( V_22 , V_24 -> V_30 ) ;
else
F_17 ( V_22 , V_24 -> V_30 ) ;
if ( type & V_41 )
F_19 ( V_22 , V_24 -> V_32 ) ;
else
F_17 ( V_22 , V_24 -> V_32 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_43 ,
unsigned int V_22 ,
T_3 V_44 )
{
struct V_23 * V_24 = V_43 -> V_45 ;
F_22 ( V_22 , & V_46 , V_47 ) ;
F_23 ( V_22 , V_24 ) ;
F_24 ( V_22 , 1 ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 , unsigned V_48 )
{
struct V_49 * V_50 ;
struct V_49 * V_51 = V_5 -> V_52 -> V_53 ;
struct V_6 * V_10 = & V_5 -> V_17 [ V_48 ] ;
char V_54 [ 16 ] ;
int V_55 ;
snprintf ( V_54 , sizeof( V_54 ) , L_1 , V_48 ) ;
V_50 = F_26 ( V_51 , V_54 , 0 ) ;
if ( ! V_50 )
return 0 ;
V_10 -> V_19 = F_27 ( V_50 ) ;
if ( F_28 ( V_10 -> V_19 ) )
return F_29 ( V_10 -> V_19 ) ;
V_55 = F_30 ( V_51 , V_54 , 1 , & V_10 -> V_20 ) ;
if ( V_55 < 0 ) {
F_31 ( V_5 -> V_52 , L_2 , V_54 ) ;
return - V_39 ;
}
V_55 = F_30 ( V_51 , V_54 , 2 , & V_10 -> V_21 ) ;
if ( V_55 < 0 ) {
F_31 ( V_5 -> V_52 , L_3 , V_54 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_32 ( struct V_4 * V_5 ,
struct V_23 * V_24 ,
struct V_49 * V_51 )
{
int V_55 ;
int V_22 ;
V_22 = F_33 ( V_51 , 0 ) ;
if ( ! V_22 ) {
F_31 ( V_5 -> V_52 , L_4 ) ;
return - V_39 ;
}
V_55 = F_34 ( V_5 -> V_52 , V_22 ,
NULL , F_9 ,
V_56 ,
L_5 , ( void * ) V_24 ) ;
if ( V_55 ) {
F_31 ( V_5 -> V_52 , L_6 ) ;
return V_55 ;
}
V_24 -> V_31 = F_35 ( V_51 , 32 , & V_57 , V_24 ) ;
if ( ! V_24 -> V_31 ) {
F_31 ( V_5 -> V_52 , L_7 ) ;
return - V_58 ;
}
return 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
T_4 V_59 ;
struct {
T_1 V_16 ;
T_1 V_60 ;
T_1 V_61 ;
T_1 V_62 ;
} * V_63 ;
V_63 = F_37 ( V_64 , V_65 , & V_59 ) ;
if ( F_28 ( V_63 ) && F_29 ( V_63 ) != - V_66 ) {
if ( F_29 ( V_63 ) != - V_67 )
F_31 ( V_5 -> V_52 , L_8 ) ;
return F_29 ( V_63 ) ;
} else if ( F_28 ( V_63 ) || V_59 != sizeof( * V_63 ) ) {
F_38 ( V_5 -> V_52 , L_9 ) ;
V_5 -> V_60 = V_68 ;
V_5 -> V_16 = V_69 ;
return 0 ;
}
V_5 -> V_60 = V_63 -> V_60 ;
V_5 -> V_16 = V_63 -> V_16 ;
F_39 ( V_5 -> V_52 ,
L_10 ,
V_5 -> V_60 , V_5 -> V_16 ) ;
return 0 ;
}
static int F_40 ( struct V_70 * V_71 )
{
struct V_49 * V_72 ;
struct V_49 * V_51 ;
struct V_23 * V_24 ;
struct V_4 * V_5 ;
T_1 * V_73 ;
T_4 V_59 ;
T_1 * V_74 ;
T_1 V_75 ;
int V_55 ;
V_5 = F_41 ( & V_71 -> V_52 , sizeof( * V_5 ) , V_76 ) ;
if ( ! V_5 )
return - V_58 ;
V_5 -> V_52 = & V_71 -> V_52 ;
F_42 ( & V_5 -> V_13 ) ;
V_55 = F_36 ( V_5 ) ;
if ( V_55 )
return V_55 ;
V_5 -> V_77 = F_43 ( & V_71 -> V_52 ,
V_5 -> V_60 ,
sizeof( struct V_23 ) ,
V_76 ) ;
if ( ! V_5 -> V_77 )
return - V_58 ;
V_5 -> V_17 = F_43 ( & V_71 -> V_52 ,
V_5 -> V_16 ,
sizeof( struct V_6 ) ,
V_76 ) ;
if ( ! V_5 -> V_17 )
return - V_58 ;
V_72 = F_44 ( F_45 ( V_71 -> V_52 . V_53 ) ,
L_11 ) ;
if ( ! V_72 ) {
F_31 ( & V_71 -> V_52 , L_12 ) ;
return - V_39 ;
}
F_46 ( V_71 -> V_52 . V_53 ,
L_13 ,
& V_5 -> V_36 ) ;
for ( V_75 = 0 ; V_75 < V_5 -> V_16 ; V_75 ++ ) {
V_55 = F_25 ( V_5 , V_75 ) ;
if ( V_55 < 0 )
return V_55 ;
}
V_55 = F_47 ( V_64 , V_78 ,
V_5 -> V_60 * sizeof( T_1 ) ) ;
if ( V_55 < 0 && V_55 != - V_79 ) {
F_31 ( & V_71 -> V_52 , L_14 ) ;
return V_55 ;
}
V_74 = F_37 ( V_64 , V_78 , NULL ) ;
if ( F_28 ( V_74 ) ) {
F_31 ( & V_71 -> V_52 , L_15 ) ;
return F_29 ( V_74 ) ;
}
V_59 = V_5 -> V_60 * V_5 -> V_16 * sizeof( T_1 ) ;
V_55 = F_47 ( V_64 , V_80 , V_59 ) ;
if ( V_55 < 0 && V_55 != - V_79 ) {
F_31 ( & V_71 -> V_52 , L_16 ) ;
return V_55 ;
}
V_73 = F_37 ( V_64 , V_80 , NULL ) ;
if ( F_28 ( V_73 ) ) {
F_31 ( & V_71 -> V_52 , L_17 ) ;
return F_29 ( V_73 ) ;
}
V_5 -> V_14 = V_74 + V_5 -> V_36 ;
V_5 -> V_18 = V_73 + V_5 -> V_36 * V_5 -> V_16 ;
V_5 -> V_81 = F_48 ( V_72 , & V_82 , V_5 ) ;
if ( F_28 ( V_5 -> V_81 ) ) {
F_31 ( V_5 -> V_52 , L_18 ) ;
return F_29 ( V_5 -> V_81 ) ;
}
F_49 (pdev->dev.of_node, node) {
if ( ! F_50 ( V_51 , L_19 ) )
continue;
V_55 = F_46 ( V_51 , L_20 , & V_75 ) ;
if ( V_55 || V_75 >= V_5 -> V_60 ) {
F_31 ( & V_71 -> V_52 , L_21 ) ;
if ( ! V_55 )
V_55 = - V_39 ;
goto V_83;
}
V_24 = & V_5 -> V_77 [ V_75 ] ;
V_24 -> V_5 = V_5 ;
V_24 -> V_28 = V_74 + V_75 ;
V_24 -> V_18 = V_73 + V_75 * V_5 -> V_16 ;
F_5 ( 0 , V_24 -> V_18 + V_5 -> V_36 ) ;
V_55 = F_32 ( V_5 , V_24 , V_51 ) ;
if ( V_55 < 0 )
goto V_83;
}
F_51 ( V_71 , V_5 ) ;
return 0 ;
V_83:
for ( V_75 = 0 ; V_75 < V_5 -> V_60 ; V_75 ++ )
if ( V_5 -> V_77 [ V_75 ] . V_31 )
F_52 ( V_5 -> V_77 [ V_75 ] . V_31 ) ;
F_53 ( V_5 -> V_81 ) ;
return V_55 ;
}
static int F_54 ( struct V_70 * V_71 )
{
struct V_4 * V_5 = F_55 ( V_71 ) ;
unsigned V_75 ;
for ( V_75 = 0 ; V_75 < V_5 -> V_60 ; V_75 ++ )
if ( V_5 -> V_77 [ V_75 ] . V_31 )
F_52 ( V_5 -> V_77 [ V_75 ] . V_31 ) ;
F_53 ( V_5 -> V_81 ) ;
return 0 ;
}
