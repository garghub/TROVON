static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_4 [ V_3 -> V_5 ] ) ;
}
static struct V_6 * F_3 ( struct V_7 * V_8 ,
struct V_9 * args )
{
struct V_1 * V_10 = F_4 ( V_8 ) ;
if ( args -> V_11 == 0 )
return V_10 -> V_4 [ 0 ] . V_6 ;
if ( F_5 ( args -> args [ 0 ] >= V_12 ) )
return F_6 ( - V_13 ) ;
return V_10 -> V_4 [ args -> args [ 0 ] ] . V_6 ;
}
static inline void F_7 ( struct V_1 * V_10 ,
T_1 V_14 , T_1 V_15 )
{
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_15 ,
V_19 ,
V_20 ) |
F_9 ( V_14 ,
V_21 ,
V_22 ) ) ;
F_10 ( 1 ) ;
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_23 ,
V_24 ,
V_25 ) ) ;
F_10 ( 1 ) ;
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_26 ,
V_24 ,
V_25 ) ) ;
}
static inline T_1 F_11 ( struct V_1 * V_10 ,
T_1 V_14 )
{
T_1 V_27 ;
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_14 ,
V_28 ,
V_22 ) ) ;
F_12 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_29 ,
& V_27 ) ;
return V_27 ;
}
static int F_13 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = F_14 ( V_6 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_30 = 0 ;
F_15 ( & V_10 -> V_31 ) ;
F_8 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_32 ,
F_9 ( V_33 ,
V_34 ,
V_35 + V_3 -> V_5 ) ) ;
if ( -- V_10 -> V_36 )
goto V_37;
V_30 = F_16 ( V_10 -> V_38 ) ;
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_1 , V_30 ) ;
goto V_39;
}
V_37:
F_18 ( & V_10 -> V_31 ) ;
return 0 ;
V_39:
V_10 -> V_36 ++ ;
F_8 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_32 ,
F_9 ( ! V_33 ,
V_34 ,
V_35 + V_3 -> V_5 ) ) ;
F_18 ( & V_10 -> V_31 ) ;
return V_30 ;
}
static int F_19 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = F_14 ( V_6 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_30 = 0 ;
T_1 V_40 ;
unsigned long V_41 ;
F_15 ( & V_10 -> V_31 ) ;
if ( V_10 -> V_36 ++ )
goto V_37;
V_30 = F_20 ( V_10 -> V_38 ) ;
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_2 , V_30 ) ;
goto V_42;
}
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_43 ,
V_21 ,
V_22 ) ) ;
F_8 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_32 ,
F_9 ( ! V_33 ,
V_34 ,
V_35 + V_3 -> V_5 ) ) ;
V_41 = V_44 + F_21 ( 1000 ) ;
V_30 = - V_45 ;
while ( F_22 ( V_44 , V_41 ) ) {
F_12 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_29 ,
& V_40 ) ;
if ( V_40 & V_46 ) {
F_23 ( & V_6 -> V_8 , L_3 ) ;
V_30 = 0 ;
break;
}
F_24 ( 20 ) ;
}
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_4 ) ;
goto V_47;
}
F_7 ( V_10 , V_48 , V_49 ) ;
F_7 ( V_10 , V_50 , V_51 ) ;
V_30 = - V_52 ;
while ( F_22 ( V_44 , V_41 ) ) {
F_12 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_29 ,
& V_40 ) ;
if ( ! ( V_40 & V_53 ) ) {
F_23 ( & V_6 -> V_8 , L_5 ) ;
V_30 = 0 ;
break;
}
F_24 ( 20 ) ;
}
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_6 ) ;
goto V_47;
}
F_8 ( V_10 -> V_16 , V_10 -> V_17 -> V_18 ,
F_9 ( V_43 ,
V_21 ,
V_22 ) ) ;
V_30 = - V_45 ;
while ( F_22 ( V_44 , V_41 ) ) {
F_12 ( V_10 -> V_16 ,
V_10 -> V_17 -> V_29 ,
& V_40 ) ;
if ( V_40 & V_46 ) {
F_23 ( & V_6 -> V_8 , L_7 ) ;
V_30 = 0 ;
break;
}
F_24 ( 20 ) ;
}
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_8 ) ;
goto V_47;
}
V_37:
F_18 ( & V_10 -> V_31 ) ;
return 0 ;
V_47:
F_16 ( V_10 -> V_38 ) ;
V_42:
V_10 -> V_36 -- ;
F_18 ( & V_10 -> V_31 ) ;
return V_30 ;
}
static int F_25 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = F_14 ( V_6 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_30 = 0 ;
F_15 ( & V_10 -> V_31 ) ;
if ( V_10 -> V_54 ++ )
goto V_37;
V_30 = F_26 ( V_10 -> V_55 ) ;
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_9 ) ;
goto V_56;
}
V_30 = F_16 ( V_10 -> V_38 ) ;
if ( V_30 ) {
F_17 ( & V_6 -> V_8 , L_1 , V_30 ) ;
goto V_57;
}
V_37:
F_18 ( & V_10 -> V_31 ) ;
return 0 ;
V_57:
F_27 ( V_10 -> V_55 ) ;
V_56:
V_10 -> V_54 -- ;
F_18 ( & V_10 -> V_31 ) ;
return V_30 ;
}
static int F_28 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = F_14 ( V_6 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_15 ( & V_10 -> V_31 ) ;
if ( -- V_10 -> V_54 )
goto V_58;
F_27 ( V_10 -> V_55 ) ;
V_58:
F_18 ( & V_10 -> V_31 ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_60 )
{
struct V_7 * V_8 = & V_60 -> V_8 ;
struct V_1 * V_10 ;
struct V_61 * V_61 ;
struct V_62 * V_63 ;
const struct V_64 * V_65 ;
int V_66 ;
T_1 V_67 ;
V_63 = F_30 ( V_8 -> V_68 -> V_69 ) ;
if ( F_31 ( V_63 ) ) {
F_17 ( V_8 , L_10 ) ;
return F_32 ( V_63 ) ;
}
V_10 = F_33 ( V_8 , sizeof( * V_10 ) , V_70 ) ;
if ( ! V_10 )
return - V_71 ;
V_65 = F_34 ( V_72 , & V_60 -> V_8 ) ;
if ( ! V_65 )
return - V_45 ;
V_10 -> V_17 = (struct V_73 * ) V_65 -> V_15 ;
V_10 -> V_16 = V_63 ;
F_35 ( & V_10 -> V_31 ) ;
V_10 -> V_38 = F_36 ( V_8 , L_11 ) ;
if ( F_31 ( V_10 -> V_38 ) ) {
if ( F_32 ( V_10 -> V_38 ) != - V_74 )
F_17 ( V_8 ,
L_12 ) ;
return F_32 ( V_10 -> V_38 ) ;
}
V_10 -> V_55 = F_37 ( V_8 , L_13 ) ;
if ( F_31 ( V_10 -> V_55 ) ) {
F_17 ( V_8 , L_14 ) ;
return F_32 ( V_10 -> V_55 ) ;
}
if ( F_38 ( V_8 -> V_69 , L_15 , & V_67 ) )
return - V_75 ;
V_67 = ( V_67 == 0 ) ? 1 : V_12 ;
F_23 ( V_8 , L_16 , V_67 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_10 -> V_4 [ V_66 ] . V_6 = F_39 ( V_8 , V_8 -> V_69 , & V_76 ) ;
if ( F_31 ( V_10 -> V_4 [ V_66 ] . V_6 ) ) {
F_17 ( V_8 , L_17 , V_66 ) ;
return F_32 ( V_10 -> V_4 [ V_66 ] . V_6 ) ;
}
V_10 -> V_4 [ V_66 ] . V_5 = V_66 ;
F_40 ( V_10 -> V_4 [ V_66 ] . V_6 , & V_10 -> V_4 [ V_66 ] ) ;
}
F_41 ( V_60 , V_10 ) ;
V_61 = F_42 ( V_8 ,
F_3 ) ;
return F_43 ( V_61 ) ;
}
