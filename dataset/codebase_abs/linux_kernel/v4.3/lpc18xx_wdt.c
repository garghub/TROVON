static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
F_4 ( V_7 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_10 , V_4 -> V_8 + V_9 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return 0 ;
}
static void F_6 ( unsigned long V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_4 -> V_12 , V_13 +
F_8 ( ( V_2 -> V_14 * V_15 ) / 2 ) ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_6 ( ( unsigned long ) V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 )
{
unsigned int V_16 ;
V_16 = F_11 ( V_4 -> V_2 . V_14 * V_4 -> V_17 ,
V_18 ) ;
F_4 ( V_16 , V_4 -> V_8 + V_19 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_20 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 . V_14 = V_20 ;
F_10 ( V_4 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_16 ;
V_16 = F_14 ( V_4 -> V_8 + V_21 ) ;
return ( V_16 * V_18 ) / V_4 -> V_17 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_16 ;
if ( F_16 ( & V_4 -> V_12 ) )
F_17 ( & V_4 -> V_12 ) ;
V_16 = F_14 ( V_4 -> V_8 + V_22 ) ;
V_16 |= V_23 ;
V_16 |= V_24 ;
F_4 ( V_16 , V_4 -> V_8 + V_22 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 , unsigned long V_27 ,
void * V_28 )
{
struct V_3 * V_4 = F_19 ( V_26 ,
struct V_3 , V_29 ) ;
unsigned long V_5 ;
int V_16 ;
F_3 ( & V_4 -> V_6 , V_5 ) ;
V_16 = F_14 ( V_4 -> V_8 + V_22 ) ;
V_16 |= V_23 ;
V_16 |= V_24 ;
F_4 ( V_16 , V_4 -> V_8 + V_22 ) ;
F_4 ( V_7 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_10 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_7 , V_4 -> V_8 + V_9 ) ;
F_4 ( V_7 , V_4 -> V_8 + V_9 ) ;
F_5 ( & V_4 -> V_6 , V_5 ) ;
return V_30 ;
}
static int F_20 ( struct V_31 * V_32 )
{
struct V_3 * V_4 ;
struct V_33 * V_34 = & V_32 -> V_34 ;
struct V_35 * V_36 ;
int V_37 ;
V_4 = F_21 ( V_34 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_36 = F_22 ( V_32 , V_40 , 0 ) ;
V_4 -> V_8 = F_23 ( V_34 , V_36 ) ;
if ( F_24 ( V_4 -> V_8 ) )
return F_25 ( V_4 -> V_8 ) ;
V_4 -> V_41 = F_26 ( V_34 , L_1 ) ;
if ( F_24 ( V_4 -> V_41 ) ) {
F_27 ( V_34 , L_2 ) ;
return F_25 ( V_4 -> V_41 ) ;
}
V_4 -> V_42 = F_26 ( V_34 , L_3 ) ;
if ( F_24 ( V_4 -> V_42 ) ) {
F_27 ( V_34 , L_4 ) ;
return F_25 ( V_4 -> V_42 ) ;
}
V_37 = F_28 ( V_4 -> V_41 ) ;
if ( V_37 ) {
F_27 ( V_34 , L_5 ) ;
return V_37 ;
}
V_37 = F_28 ( V_4 -> V_42 ) ;
if ( V_37 ) {
F_27 ( V_34 , L_6 ) ;
goto V_43;
}
V_4 -> V_17 = F_29 ( V_4 -> V_42 ) ;
if ( V_4 -> V_17 == 0 ) {
F_27 ( V_34 , L_7 ) ;
V_37 = - V_44 ;
goto V_45;
}
V_4 -> V_2 . V_46 = & V_47 ;
V_4 -> V_2 . V_48 = & V_49 ;
V_4 -> V_2 . V_50 = F_11 ( V_51 *
V_18 , V_4 -> V_17 ) ;
V_4 -> V_2 . V_52 = ( V_53 *
V_18 ) / V_4 -> V_17 ;
V_4 -> V_2 . V_14 = F_30 ( V_4 -> V_2 . V_52 ,
V_54 ) ;
F_31 ( & V_4 -> V_6 ) ;
V_4 -> V_2 . V_55 = V_34 ;
F_32 ( & V_4 -> V_2 , V_4 ) ;
V_37 = F_33 ( & V_4 -> V_2 , V_56 , V_34 ) ;
F_10 ( V_4 ) ;
F_34 ( & V_4 -> V_12 , F_6 ,
( unsigned long ) & V_4 -> V_2 ) ;
F_35 ( & V_4 -> V_2 , V_57 ) ;
F_36 ( V_32 , V_4 ) ;
V_37 = F_37 ( & V_4 -> V_2 ) ;
if ( V_37 )
goto V_45;
V_4 -> V_29 . V_58 = F_18 ;
V_4 -> V_29 . V_59 = 128 ;
V_37 = F_38 ( & V_4 -> V_29 ) ;
if ( V_37 )
F_39 ( V_34 , L_8 , V_37 ) ;
return 0 ;
V_45:
F_40 ( V_4 -> V_42 ) ;
V_43:
F_40 ( V_4 -> V_41 ) ;
return V_37 ;
}
static void F_41 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_42 ( V_32 ) ;
F_9 ( & V_4 -> V_2 ) ;
}
static int F_43 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_42 ( V_32 ) ;
F_44 ( & V_4 -> V_29 ) ;
F_39 ( & V_32 -> V_34 , L_9 ) ;
F_17 ( & V_4 -> V_12 ) ;
F_45 ( & V_4 -> V_2 ) ;
F_40 ( V_4 -> V_42 ) ;
F_40 ( V_4 -> V_41 ) ;
return 0 ;
}
