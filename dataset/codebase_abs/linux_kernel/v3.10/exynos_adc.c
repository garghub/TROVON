static inline unsigned int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
V_4 = F_2 ( V_5 , V_2 -> V_6 . V_7 ) ;
return ( unsigned int ) V_4 -> V_8 ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int * V_13 ,
int * V_14 ,
long V_15 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
unsigned long V_18 ;
T_1 V_19 , V_20 ;
if ( V_15 != V_21 )
return - V_22 ;
F_5 ( & V_10 -> V_23 ) ;
if ( V_17 -> V_24 == V_25 ) {
V_20 = F_6 ( F_7 ( V_17 -> V_26 ) ) ;
V_20 &= ~ V_27 ;
V_20 |= F_8 ( V_12 -> V_28 ) ;
F_9 ( V_20 , F_7 ( V_17 -> V_26 ) ) ;
V_19 = F_6 ( F_10 ( V_17 -> V_26 ) ) ;
F_9 ( V_19 | V_29 ,
F_10 ( V_17 -> V_26 ) ) ;
} else {
F_9 ( V_12 -> V_28 , F_11 ( V_17 -> V_26 ) ) ;
V_19 = F_6 ( F_12 ( V_17 -> V_26 ) ) ;
F_9 ( V_19 | V_29 ,
F_12 ( V_17 -> V_26 ) ) ;
}
V_18 = F_13
( & V_17 -> V_30 , V_31 ) ;
* V_13 = V_17 -> V_32 ;
F_14 ( & V_10 -> V_23 ) ;
if ( V_18 == 0 )
return - V_33 ;
return V_34 ;
}
static T_2 F_15 ( int V_35 , void * V_36 )
{
struct V_16 * V_17 = (struct V_16 * ) V_36 ;
V_17 -> V_32 = F_6 ( F_16 ( V_17 -> V_26 ) ) &
V_37 ;
if ( V_17 -> V_24 == V_25 )
F_9 ( 1 , F_17 ( V_17 -> V_26 ) ) ;
else
F_9 ( 1 , F_18 ( V_17 -> V_26 ) ) ;
F_19 ( & V_17 -> V_30 ) ;
return V_38 ;
}
static int F_20 ( struct V_9 * V_10 ,
unsigned V_39 , unsigned V_40 ,
unsigned * V_41 )
{
struct V_16 * V_17 = F_4 ( V_10 ) ;
if ( V_41 == NULL )
return - V_22 ;
* V_41 = F_6 ( V_17 -> V_26 + V_39 ) ;
return 0 ;
}
static int F_21 ( struct V_42 * V_6 , void * V_43 )
{
struct V_1 * V_2 = F_22 ( V_6 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_16 * V_17 )
{
T_1 V_19 , V_20 ;
if ( V_17 -> V_24 == V_25 ) {
V_19 = V_44 ;
F_9 ( V_19 , F_10 ( V_17 -> V_26 ) ) ;
V_20 = V_45 | V_46 |
V_47 | F_25 ( 0 ) ;
F_9 ( V_20 , F_7 ( V_17 -> V_26 ) ) ;
F_9 ( 1 , F_26 ( V_17 -> V_26 ) ) ;
} else {
V_19 = F_27 ( 49 ) | V_48 ;
V_19 |= V_49 ;
F_9 ( V_19 , F_12 ( V_17 -> V_26 ) ) ;
}
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
struct V_50 * V_51 = V_2 -> V_6 . V_7 ;
struct V_9 * V_10 = NULL ;
struct V_52 * V_53 ;
int V_54 = - V_55 ;
int V_35 ;
if ( ! V_51 )
return V_54 ;
V_10 = F_29 ( sizeof( struct V_16 ) ) ;
if ( ! V_10 ) {
F_30 ( & V_2 -> V_6 , L_1 ) ;
return - V_56 ;
}
V_17 = F_4 ( V_10 ) ;
V_53 = F_31 ( V_2 , V_57 , 0 ) ;
V_17 -> V_26 = F_32 ( & V_2 -> V_6 , V_53 ) ;
if ( ! V_17 -> V_26 ) {
V_54 = - V_56 ;
goto V_58;
}
V_53 = F_31 ( V_2 , V_57 , 1 ) ;
V_17 -> V_59 = F_32 ( & V_2 -> V_6 , V_53 ) ;
if ( ! V_17 -> V_59 ) {
V_54 = - V_56 ;
goto V_58;
}
V_35 = F_33 ( V_2 , 0 ) ;
if ( V_35 < 0 ) {
F_30 ( & V_2 -> V_6 , L_2 ) ;
V_54 = V_35 ;
goto V_58;
}
V_17 -> V_35 = V_35 ;
F_34 ( & V_17 -> V_30 ) ;
V_54 = F_35 ( V_17 -> V_35 , F_15 ,
0 , F_36 ( & V_2 -> V_6 ) , V_17 ) ;
if ( V_54 < 0 ) {
F_30 ( & V_2 -> V_6 , L_3 ,
V_17 -> V_35 ) ;
goto V_58;
}
F_9 ( 1 , V_17 -> V_59 ) ;
V_17 -> V_60 = F_37 ( & V_2 -> V_6 , L_4 ) ;
if ( F_38 ( V_17 -> V_60 ) ) {
F_30 ( & V_2 -> V_6 , L_5 ,
F_39 ( V_17 -> V_60 ) ) ;
V_54 = F_39 ( V_17 -> V_60 ) ;
goto V_61;
}
V_17 -> V_62 = F_40 ( & V_2 -> V_6 , L_6 ) ;
if ( F_38 ( V_17 -> V_62 ) ) {
F_30 ( & V_2 -> V_6 , L_7 ,
F_39 ( V_17 -> V_62 ) ) ;
V_54 = F_39 ( V_17 -> V_62 ) ;
goto V_61;
}
V_17 -> V_24 = F_1 ( V_2 ) ;
F_41 ( V_2 , V_10 ) ;
V_10 -> V_63 = F_36 ( & V_2 -> V_6 ) ;
V_10 -> V_6 . V_64 = & V_2 -> V_6 ;
V_10 -> V_6 . V_7 = V_2 -> V_6 . V_7 ;
V_10 -> V_17 = & V_65 ;
V_10 -> V_66 = V_67 ;
V_10 -> V_68 = V_69 ;
if ( V_17 -> V_24 == V_70 )
V_10 -> V_71 = V_72 ;
else
V_10 -> V_71 = V_73 ;
V_54 = F_42 ( V_10 ) ;
if ( V_54 )
goto V_61;
V_54 = F_43 ( V_17 -> V_62 ) ;
if ( V_54 )
goto V_74;
F_44 ( V_17 -> V_60 ) ;
F_24 ( V_17 ) ;
V_54 = F_45 ( V_51 , V_5 , NULL , & V_2 -> V_6 ) ;
if ( V_54 < 0 ) {
F_30 ( & V_2 -> V_6 , L_8 ) ;
goto V_75;
}
return 0 ;
V_75:
F_46 ( & V_2 -> V_6 , NULL ,
F_21 ) ;
F_47 ( V_17 -> V_62 ) ;
F_48 ( V_17 -> V_60 ) ;
V_74:
F_49 ( V_10 ) ;
V_61:
F_50 ( V_17 -> V_35 , V_17 ) ;
V_58:
F_51 ( V_10 ) ;
return V_54 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_53 ( V_2 ) ;
struct V_16 * V_17 = F_4 ( V_10 ) ;
F_46 ( & V_2 -> V_6 , NULL ,
F_21 ) ;
F_47 ( V_17 -> V_62 ) ;
F_48 ( V_17 -> V_60 ) ;
F_9 ( 0 , V_17 -> V_59 ) ;
F_49 ( V_10 ) ;
F_50 ( V_17 -> V_35 , V_17 ) ;
F_51 ( V_10 ) ;
return 0 ;
}
static int F_54 ( struct V_42 * V_6 )
{
struct V_9 * V_10 = F_55 ( V_6 ) ;
struct V_16 * V_17 = F_4 ( V_10 ) ;
T_1 V_76 ;
if ( V_17 -> V_24 == V_25 ) {
V_76 = F_6 ( F_10 ( V_17 -> V_26 ) ) ;
V_76 &= ~ V_29 ;
F_9 ( V_76 , F_10 ( V_17 -> V_26 ) ) ;
} else {
V_76 = F_6 ( F_12 ( V_17 -> V_26 ) ) ;
V_76 |= V_77 ;
F_9 ( V_76 , F_12 ( V_17 -> V_26 ) ) ;
}
F_48 ( V_17 -> V_60 ) ;
F_9 ( 0 , V_17 -> V_59 ) ;
F_47 ( V_17 -> V_62 ) ;
return 0 ;
}
static int F_56 ( struct V_42 * V_6 )
{
struct V_9 * V_10 = F_55 ( V_6 ) ;
struct V_16 * V_17 = F_4 ( V_10 ) ;
int V_54 ;
V_54 = F_43 ( V_17 -> V_62 ) ;
if ( V_54 )
return V_54 ;
F_9 ( 1 , V_17 -> V_59 ) ;
F_44 ( V_17 -> V_60 ) ;
F_24 ( V_17 ) ;
return 0 ;
}
