static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
return V_4 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_4 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_6 )
{
unsigned int V_7 ;
V_7 = V_8 | V_9 |
V_10 | V_11 ;
F_3 ( V_6 , V_12 , V_7 ) ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_18 ;
struct V_19 * V_20 = V_14 -> V_21 . V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 ;
int V_27 , V_28 ;
int V_29 , V_30 = 0 , V_31 ;
if ( ! V_20 ) {
F_7 ( & V_14 -> V_21 , L_1 ) ;
return - V_32 ;
}
if ( V_20 -> V_33 )
V_30 = V_20 -> V_33 -> V_30 ;
V_29 = V_20 -> V_34 -> V_35 ;
V_31 = V_29 + V_30 ;
if ( V_31 > 8 ) {
F_7 ( & V_14 -> V_21 , L_2 ) ;
return - V_32 ;
}
V_17 = F_8 ( V_14 , V_36 , 0 ) ;
if ( ! V_17 ) {
F_7 ( & V_14 -> V_21 , L_3 ) ;
return - V_32 ;
}
V_15 = F_9 ( & V_14 -> V_21 ,
sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_15 ) {
F_7 ( & V_14 -> V_21 , L_4 ) ;
return - V_38 ;
}
V_15 -> V_21 = & V_14 -> V_21 ;
V_25 = F_10 ( V_14 , 0 ) ;
if ( V_25 < 0 ) {
F_7 ( & V_14 -> V_21 , L_5 ) ;
goto V_39;
} else
V_15 -> V_40 = V_25 ;
V_17 = F_11 ( & V_14 -> V_21 ,
V_17 -> V_41 , F_12 ( V_17 ) , V_14 -> V_42 ) ;
if ( ! V_17 ) {
F_7 ( & V_14 -> V_21 , L_6 ) ;
return - V_43 ;
}
V_15 -> V_44 = F_13 ( & V_14 -> V_21 ,
V_17 -> V_41 , F_12 ( V_17 ) ) ;
if ( ! V_15 -> V_44 ) {
F_7 ( & V_14 -> V_21 , L_7 ) ;
return - V_38 ;
}
V_15 -> V_5 = F_14 ( & V_14 -> V_21 ,
V_15 -> V_44 , & V_45 ) ;
if ( F_15 ( V_15 -> V_5 ) ) {
F_7 ( & V_14 -> V_21 , L_8 ) ;
V_25 = F_16 ( V_15 -> V_5 ) ;
goto V_39;
}
F_17 ( & V_14 -> V_21 ) ;
F_18 ( & V_14 -> V_21 ) ;
V_18 = F_19 ( & V_14 -> V_21 , L_9 ) ;
if ( F_15 ( V_18 ) ) {
F_7 ( & V_14 -> V_21 , L_10 ) ;
V_25 = F_16 ( V_18 ) ;
goto V_46;
}
V_28 = F_20 ( V_18 ) ;
F_21 ( V_18 ) ;
V_27 = V_28 / V_47 ;
if ( V_27 < V_48 ) {
F_7 ( & V_14 -> V_21 , L_11 ) ;
V_25 = - V_32 ;
goto V_46;
}
V_27 = V_27 - 1 ;
F_3 ( V_15 , V_49 , V_27 ) ;
V_26 = V_50 |
V_51 |
V_52 |
V_53 ;
F_3 ( V_15 , V_54 , V_26 ) ;
F_5 ( V_15 ) ;
V_26 = F_1 ( V_15 , V_54 ) ;
V_26 |= V_55 ;
F_3 ( V_15 , V_54 , V_26 ) ;
V_24 = & V_15 -> V_56 [ V_57 ] ;
V_24 -> V_42 = L_12 ;
V_24 -> V_22 = V_15 ;
V_24 -> V_58 = sizeof( * V_15 ) ;
V_24 = & V_15 -> V_56 [ V_59 ] ;
V_24 -> V_42 = L_13 ;
V_24 -> V_22 = V_15 ;
V_24 -> V_58 = sizeof( * V_15 ) ;
V_25 = F_22 ( & V_14 -> V_21 , V_14 -> V_60 , V_15 -> V_56 ,
V_61 , NULL , 0 , NULL ) ;
if ( V_25 < 0 )
goto V_46;
F_23 ( & V_14 -> V_21 , true ) ;
F_24 ( V_14 , V_15 ) ;
return 0 ;
V_46:
F_25 ( & V_14 -> V_21 ) ;
F_26 ( & V_14 -> V_21 ) ;
V_39:
return V_25 ;
}
static int F_27 ( struct V_13 * V_14 )
{
struct V_1 * V_15 = F_28 ( V_14 ) ;
F_3 ( V_15 , V_62 , 0x00 ) ;
F_25 ( & V_14 -> V_21 ) ;
F_26 ( & V_14 -> V_21 ) ;
F_29 ( V_15 -> V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_63 * V_21 )
{
struct V_1 * V_64 = F_31 ( V_21 ) ;
F_3 ( V_64 , V_62 , 0x00 ) ;
F_25 ( V_21 ) ;
return 0 ;
}
static int F_32 ( struct V_63 * V_21 )
{
struct V_1 * V_64 = F_31 ( V_21 ) ;
unsigned int V_65 , V_26 ;
F_18 ( V_21 ) ;
V_26 = V_50 | V_51 |
V_52 | V_53 ;
F_3 ( V_64 , V_54 , V_26 ) ;
F_5 ( V_64 ) ;
F_3 ( V_64 , V_62 , V_66 ) ;
V_65 = F_1 ( V_64 , V_54 ) ;
F_3 ( V_64 , V_54 ,
( V_65 | V_55 ) ) ;
return 0 ;
}
