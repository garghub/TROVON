static inline unsigned int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 ( V_5 , V_2 -> V_6 . V_7 ) ;
return ( unsigned int ) V_4 -> V_8 ;
}
static void F_3 ( struct V_9 * V_10 )
{
T_1 V_11 , V_12 ;
if ( V_10 -> V_13 == V_14 ) {
V_11 = V_15 ;
F_4 ( V_11 , F_5 ( V_10 -> V_16 ) ) ;
V_12 = V_17 | V_18 |
V_19 | F_6 ( 0 ) ;
F_4 ( V_12 , F_7 ( V_10 -> V_16 ) ) ;
F_4 ( 1 , F_8 ( V_10 -> V_16 ) ) ;
} else {
V_11 = F_9 ( 49 ) | V_20 ;
V_11 |= V_21 ;
F_4 ( V_11 , F_10 ( V_10 -> V_16 ) ) ;
}
}
static int F_11 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_26 ,
int * V_27 ,
long V_28 )
{
struct V_9 * V_10 = F_12 ( V_23 ) ;
unsigned long V_29 ;
T_1 V_11 , V_12 ;
int V_30 ;
if ( V_28 != V_31 )
return - V_32 ;
F_13 ( & V_23 -> V_33 ) ;
F_14 ( & V_10 -> V_34 ) ;
if ( V_10 -> V_13 == V_14 ) {
V_12 = F_15 ( F_7 ( V_10 -> V_16 ) ) ;
V_12 &= ~ V_35 ;
V_12 |= F_16 ( V_25 -> V_36 ) ;
F_4 ( V_12 , F_7 ( V_10 -> V_16 ) ) ;
V_11 = F_15 ( F_5 ( V_10 -> V_16 ) ) ;
F_4 ( V_11 | V_37 ,
F_5 ( V_10 -> V_16 ) ) ;
} else {
F_4 ( V_25 -> V_36 , F_17 ( V_10 -> V_16 ) ) ;
V_11 = F_15 ( F_10 ( V_10 -> V_16 ) ) ;
F_4 ( V_11 | V_37 ,
F_10 ( V_10 -> V_16 ) ) ;
}
V_29 = F_18
( & V_10 -> V_34 , V_38 ) ;
if ( V_29 == 0 ) {
F_19 ( & V_23 -> V_6 , L_1 ) ;
F_3 ( V_10 ) ;
V_30 = - V_39 ;
} else {
* V_26 = V_10 -> V_40 ;
* V_27 = 0 ;
V_30 = V_41 ;
}
F_20 ( & V_23 -> V_33 ) ;
return V_30 ;
}
static T_2 F_21 ( int V_42 , void * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_43 ;
V_10 -> V_40 = F_15 ( F_22 ( V_10 -> V_16 ) ) &
V_44 ;
if ( V_10 -> V_13 == V_14 )
F_4 ( 1 , F_23 ( V_10 -> V_16 ) ) ;
else
F_4 ( 1 , F_24 ( V_10 -> V_16 ) ) ;
F_25 ( & V_10 -> V_34 ) ;
return V_45 ;
}
static int F_26 ( struct V_22 * V_23 ,
unsigned V_46 , unsigned V_47 ,
unsigned * V_48 )
{
struct V_9 * V_10 = F_12 ( V_23 ) ;
if ( V_48 == NULL )
return - V_32 ;
* V_48 = F_15 ( V_10 -> V_16 + V_46 ) ;
return 0 ;
}
static int F_27 ( struct V_49 * V_6 , void * V_50 )
{
struct V_1 * V_2 = F_28 ( V_6 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = NULL ;
struct V_51 * V_52 = V_2 -> V_6 . V_7 ;
struct V_22 * V_23 = NULL ;
struct V_53 * V_54 ;
int V_30 = - V_55 ;
int V_42 ;
if ( ! V_52 )
return V_30 ;
V_23 = F_31 ( & V_2 -> V_6 , sizeof( struct V_9 ) ) ;
if ( ! V_23 ) {
F_32 ( & V_2 -> V_6 , L_2 ) ;
return - V_56 ;
}
V_10 = F_12 ( V_23 ) ;
V_54 = F_33 ( V_2 , V_57 , 0 ) ;
V_10 -> V_16 = F_34 ( & V_2 -> V_6 , V_54 ) ;
if ( F_35 ( V_10 -> V_16 ) )
return F_36 ( V_10 -> V_16 ) ;
V_54 = F_33 ( V_2 , V_57 , 1 ) ;
V_10 -> V_58 = F_34 ( & V_2 -> V_6 , V_54 ) ;
if ( F_35 ( V_10 -> V_58 ) )
return F_36 ( V_10 -> V_58 ) ;
V_42 = F_37 ( V_2 , 0 ) ;
if ( V_42 < 0 ) {
F_32 ( & V_2 -> V_6 , L_3 ) ;
return V_42 ;
}
V_10 -> V_42 = V_42 ;
F_38 ( & V_10 -> V_34 ) ;
V_10 -> V_59 = F_39 ( & V_2 -> V_6 , L_4 ) ;
if ( F_35 ( V_10 -> V_59 ) ) {
F_32 ( & V_2 -> V_6 , L_5 ,
F_36 ( V_10 -> V_59 ) ) ;
return F_36 ( V_10 -> V_59 ) ;
}
V_10 -> V_60 = F_40 ( & V_2 -> V_6 , L_6 ) ;
if ( F_35 ( V_10 -> V_60 ) ) {
F_32 ( & V_2 -> V_6 , L_7 ,
F_36 ( V_10 -> V_60 ) ) ;
return F_36 ( V_10 -> V_60 ) ;
}
V_30 = F_41 ( V_10 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_42 ( V_10 -> V_59 ) ;
if ( V_30 )
goto V_61;
F_4 ( 1 , V_10 -> V_58 ) ;
V_10 -> V_13 = F_1 ( V_2 ) ;
F_43 ( V_2 , V_23 ) ;
V_23 -> V_62 = F_44 ( & V_2 -> V_6 ) ;
V_23 -> V_6 . V_63 = & V_2 -> V_6 ;
V_23 -> V_6 . V_7 = V_2 -> V_6 . V_7 ;
V_23 -> V_10 = & V_64 ;
V_23 -> V_65 = V_66 ;
V_23 -> V_67 = V_68 ;
if ( V_10 -> V_13 == V_69 )
V_23 -> V_70 = V_71 ;
else
V_23 -> V_70 = V_72 ;
V_30 = F_45 ( V_10 -> V_42 , F_21 ,
0 , F_44 ( & V_2 -> V_6 ) , V_10 ) ;
if ( V_30 < 0 ) {
F_32 ( & V_2 -> V_6 , L_8 ,
V_10 -> V_42 ) ;
goto V_73;
}
V_30 = F_46 ( V_23 ) ;
if ( V_30 )
goto V_74;
F_3 ( V_10 ) ;
V_30 = F_47 ( V_52 , V_5 , NULL , & V_23 -> V_6 ) ;
if ( V_30 < 0 ) {
F_32 ( & V_2 -> V_6 , L_9 ) ;
goto V_75;
}
return 0 ;
V_75:
F_48 ( & V_23 -> V_6 , NULL ,
F_27 ) ;
F_49 ( V_23 ) ;
V_74:
F_50 ( V_10 -> V_42 , V_10 ) ;
V_73:
F_4 ( 0 , V_10 -> V_58 ) ;
F_51 ( V_10 -> V_59 ) ;
V_61:
F_52 ( V_10 -> V_60 ) ;
return V_30 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_54 ( V_2 ) ;
struct V_9 * V_10 = F_12 ( V_23 ) ;
F_48 ( & V_23 -> V_6 , NULL ,
F_27 ) ;
F_49 ( V_23 ) ;
F_50 ( V_10 -> V_42 , V_10 ) ;
F_4 ( 0 , V_10 -> V_58 ) ;
F_51 ( V_10 -> V_59 ) ;
F_52 ( V_10 -> V_60 ) ;
return 0 ;
}
static int F_55 ( struct V_49 * V_6 )
{
struct V_22 * V_23 = F_56 ( V_6 ) ;
struct V_9 * V_10 = F_12 ( V_23 ) ;
T_1 V_76 ;
if ( V_10 -> V_13 == V_14 ) {
V_76 = F_15 ( F_5 ( V_10 -> V_16 ) ) ;
V_76 &= ~ V_37 ;
F_4 ( V_76 , F_5 ( V_10 -> V_16 ) ) ;
} else {
V_76 = F_15 ( F_10 ( V_10 -> V_16 ) ) ;
V_76 |= V_77 ;
F_4 ( V_76 , F_10 ( V_10 -> V_16 ) ) ;
}
F_4 ( 0 , V_10 -> V_58 ) ;
F_51 ( V_10 -> V_59 ) ;
F_52 ( V_10 -> V_60 ) ;
return 0 ;
}
static int F_57 ( struct V_49 * V_6 )
{
struct V_22 * V_23 = F_56 ( V_6 ) ;
struct V_9 * V_10 = F_12 ( V_23 ) ;
int V_30 ;
V_30 = F_41 ( V_10 -> V_60 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_42 ( V_10 -> V_59 ) ;
if ( V_30 )
return V_30 ;
F_4 ( 1 , V_10 -> V_58 ) ;
F_3 ( V_10 ) ;
return 0 ;
}
