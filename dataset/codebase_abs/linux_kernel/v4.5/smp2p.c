static void F_1 ( struct V_1 * V_2 )
{
F_2 () ;
F_3 ( V_2 -> V_3 , V_2 -> V_4 , F_4 ( V_2 -> V_5 ) ) ;
}
static T_1 F_5 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_1 * V_2 = V_7 ;
unsigned V_12 = V_2 -> V_13 [ V_14 ] ;
unsigned V_15 = V_2 -> V_16 ;
T_2 V_17 ;
int V_18 ;
T_3 V_19 ;
char V_20 [ V_21 ] ;
T_3 V_22 ;
int V_23 ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 ) {
V_9 = F_6 ( V_15 , V_12 , & V_17 ) ;
if ( F_7 ( V_9 ) ) {
F_8 ( V_2 -> V_24 ,
L_1 ) ;
return V_25 ;
}
V_2 -> V_9 = V_9 ;
}
for ( V_23 = V_2 -> V_26 ; V_23 < V_9 -> V_26 ; V_23 ++ ) {
F_9 (entry, &smp2p->inbound, node) {
F_10 ( V_20 , V_9 -> V_27 [ V_23 ] . V_28 , sizeof( V_20 ) ) ;
if ( ! strcmp ( V_20 , V_11 -> V_28 ) ) {
V_11 -> V_29 = & V_9 -> V_27 [ V_23 ] . V_29 ;
break;
}
}
}
V_2 -> V_26 = V_23 ;
F_9 (entry, &smp2p->inbound, node) {
if ( ! V_11 -> V_29 )
continue;
V_22 = F_11 ( V_11 -> V_29 ) ;
V_19 = V_22 ^ V_11 -> V_30 ;
V_11 -> V_30 = V_22 ;
if ( ! V_19 )
continue;
F_12 (i, entry->irq_enabled, 32 ) {
if ( ! ( V_19 & F_4 ( V_23 ) ) )
continue;
if ( ( V_22 & F_4 ( V_23 ) && F_13 ( V_23 , V_11 -> V_31 ) ) ||
( ! ( V_22 & F_4 ( V_23 ) ) && F_13 ( V_23 , V_11 -> V_32 ) ) ) {
V_18 = F_14 ( V_11 -> V_33 , V_23 ) ;
F_15 ( V_18 ) ;
}
}
}
return V_25 ;
}
static void F_16 ( struct V_34 * V_35 )
{
struct V_10 * V_11 = F_17 ( V_35 ) ;
T_4 V_6 = F_18 ( V_35 ) ;
F_19 ( V_6 , V_11 -> V_36 ) ;
}
static void F_20 ( struct V_34 * V_35 )
{
struct V_10 * V_11 = F_17 ( V_35 ) ;
T_4 V_6 = F_18 ( V_35 ) ;
F_21 ( V_6 , V_11 -> V_36 ) ;
}
static int F_22 ( struct V_34 * V_35 , unsigned int type )
{
struct V_10 * V_11 = F_17 ( V_35 ) ;
T_4 V_6 = F_18 ( V_35 ) ;
if ( ! ( type & V_37 ) )
return - V_38 ;
if ( type & V_39 )
F_21 ( V_6 , V_11 -> V_31 ) ;
else
F_19 ( V_6 , V_11 -> V_31 ) ;
if ( type & V_40 )
F_21 ( V_6 , V_11 -> V_32 ) ;
else
F_19 ( V_6 , V_11 -> V_32 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 ,
unsigned int V_6 ,
T_4 V_43 )
{
struct V_10 * V_11 = V_42 -> V_44 ;
F_24 ( V_6 , & V_45 , V_46 ) ;
F_25 ( V_6 , V_11 ) ;
F_26 ( V_6 , 1 ) ;
F_27 ( V_6 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_47 * V_48 )
{
V_11 -> V_33 = F_29 ( V_48 , 32 , & V_49 , V_11 ) ;
if ( ! V_11 -> V_33 ) {
F_8 ( V_2 -> V_24 , L_2 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_30 ( void * V_7 , T_3 V_51 , T_3 V_29 )
{
struct V_10 * V_11 = V_7 ;
T_3 V_52 ;
T_3 V_22 ;
F_31 ( & V_11 -> V_53 ) ;
V_22 = V_52 = F_11 ( V_11 -> V_29 ) ;
V_22 &= ~ V_51 ;
V_22 |= V_29 ;
F_32 ( V_22 , V_11 -> V_29 ) ;
F_33 ( & V_11 -> V_53 ) ;
if ( V_22 != V_52 )
F_1 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_8 * V_54 = V_2 -> V_54 ;
char V_20 [ V_21 ] = {} ;
F_35 ( V_20 , V_11 -> V_28 , V_21 ) ;
F_36 ( V_54 -> V_27 [ V_54 -> V_26 ] . V_28 , V_20 , V_21 ) ;
V_54 -> V_26 ++ ;
V_11 -> V_29 = & V_54 -> V_27 [ V_54 -> V_26 ] . V_29 ;
V_11 -> V_55 = F_37 ( V_48 , & V_56 , V_11 ) ;
if ( F_7 ( V_11 -> V_55 ) ) {
F_8 ( V_2 -> V_24 , L_3 ) ;
return F_38 ( V_11 -> V_55 ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_54 ;
unsigned V_12 = V_2 -> V_13 [ V_57 ] ;
unsigned V_15 = V_2 -> V_16 ;
int V_58 ;
V_58 = F_40 ( V_15 , V_12 , sizeof( * V_54 ) ) ;
if ( V_58 < 0 && V_58 != - V_59 ) {
if ( V_58 != - V_60 )
F_8 ( V_2 -> V_24 ,
L_4 ) ;
return V_58 ;
}
V_54 = F_6 ( V_15 , V_12 , NULL ) ;
if ( F_7 ( V_54 ) ) {
F_8 ( V_2 -> V_24 , L_5 ) ;
return F_38 ( V_54 ) ;
}
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_61 = V_62 ;
V_54 -> V_63 = V_2 -> V_63 ;
V_54 -> V_16 = V_2 -> V_16 ;
V_54 -> V_64 = V_65 ;
V_54 -> V_26 = 0 ;
F_2 () ;
V_54 -> V_66 = 1 ;
F_1 ( V_2 ) ;
V_2 -> V_54 = V_54 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_47 * V_67 ;
struct V_68 * V_24 = V_2 -> V_24 ;
const char * V_69 ;
int V_58 ;
V_67 = F_42 ( V_24 -> V_70 , L_6 , 0 ) ;
if ( ! V_67 ) {
F_8 ( V_24 , L_7 ) ;
return - V_71 ;
}
V_2 -> V_3 = F_43 ( V_67 ) ;
if ( F_7 ( V_2 -> V_3 ) )
return F_38 ( V_2 -> V_3 ) ;
V_69 = L_6 ;
V_58 = F_44 ( V_24 -> V_70 , V_69 , 1 , & V_2 -> V_4 ) ;
if ( V_58 < 0 ) {
F_8 ( V_24 , L_8 , V_69 ) ;
return - V_38 ;
}
V_58 = F_44 ( V_24 -> V_70 , V_69 , 2 , & V_2 -> V_5 ) ;
if ( V_58 < 0 ) {
F_8 ( V_24 , L_9 , V_69 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_45 ( struct V_72 * V_73 )
{
struct V_10 * V_11 ;
struct V_47 * V_48 ;
struct V_1 * V_2 ;
const char * V_69 ;
int V_6 ;
int V_58 ;
V_2 = F_46 ( & V_73 -> V_24 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_24 = & V_73 -> V_24 ;
F_47 ( & V_2 -> V_75 ) ;
F_47 ( & V_2 -> V_76 ) ;
F_48 ( V_73 , V_2 ) ;
V_58 = F_41 ( V_2 ) ;
if ( V_58 )
return V_58 ;
V_69 = L_10 ;
V_58 = F_49 ( V_73 -> V_24 . V_70 , V_69 ,
V_2 -> V_13 , 2 ) ;
if ( V_58 )
return V_58 ;
V_69 = L_11 ;
V_58 = F_50 ( V_73 -> V_24 . V_70 , V_69 , & V_2 -> V_63 ) ;
if ( V_58 < 0 ) {
F_8 ( & V_73 -> V_24 , L_12 , V_69 ) ;
return - V_38 ;
}
V_69 = L_13 ;
V_58 = F_50 ( V_73 -> V_24 . V_70 , V_69 , & V_2 -> V_16 ) ;
if ( V_58 < 0 ) {
F_8 ( & V_73 -> V_24 , L_12 , V_69 ) ;
return - V_38 ;
}
V_6 = F_51 ( V_73 , 0 ) ;
if ( V_6 < 0 ) {
F_8 ( & V_73 -> V_24 , L_14 ) ;
return V_6 ;
}
V_58 = F_39 ( V_2 ) ;
if ( V_58 < 0 )
return V_58 ;
F_52 (pdev->dev.of_node, node) {
V_11 = F_46 ( & V_73 -> V_24 , sizeof( * V_11 ) , V_74 ) ;
if ( ! V_11 ) {
V_58 = - V_50 ;
goto V_77;
}
V_11 -> V_2 = V_2 ;
F_53 ( & V_11 -> V_53 ) ;
V_58 = F_54 ( V_48 , L_15 , & V_11 -> V_28 ) ;
if ( V_58 < 0 )
goto V_77;
if ( F_55 ( V_48 , L_16 ) ) {
V_58 = F_28 ( V_2 , V_11 , V_48 ) ;
if ( V_58 < 0 )
goto V_77;
F_56 ( & V_11 -> V_48 , & V_2 -> V_75 ) ;
} else {
V_58 = F_34 ( V_2 , V_11 , V_48 ) ;
if ( V_58 < 0 )
goto V_77;
F_56 ( & V_11 -> V_48 , & V_2 -> V_76 ) ;
}
}
F_1 ( V_2 ) ;
V_58 = F_57 ( & V_73 -> V_24 , V_6 ,
NULL , F_5 ,
V_78 ,
L_17 , ( void * ) V_2 ) ;
if ( V_58 ) {
F_8 ( & V_73 -> V_24 , L_18 ) ;
goto V_77;
}
return 0 ;
V_77:
F_9 (entry, &smp2p->inbound, node)
F_58 ( V_11 -> V_33 ) ;
F_9 (entry, &smp2p->outbound, node)
F_59 ( V_11 -> V_55 ) ;
V_2 -> V_54 -> V_26 = 0 ;
return V_58 ;
}
static int F_60 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_61 ( V_73 ) ;
struct V_10 * V_11 ;
F_9 (entry, &smp2p->inbound, node)
F_58 ( V_11 -> V_33 ) ;
F_9 (entry, &smp2p->outbound, node)
F_59 ( V_11 -> V_55 ) ;
V_2 -> V_54 -> V_26 = 0 ;
return 0 ;
}
