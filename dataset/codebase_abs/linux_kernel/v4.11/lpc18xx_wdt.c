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
static int F_18 ( struct V_1 * V_2 ,
unsigned long V_25 , void * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
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
return 0 ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_3 * V_4 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_4 = F_20 ( V_29 , sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_31 = F_21 ( V_27 , V_35 , 0 ) ;
V_4 -> V_8 = F_22 ( V_29 , V_31 ) ;
if ( F_23 ( V_4 -> V_8 ) )
return F_24 ( V_4 -> V_8 ) ;
V_4 -> V_36 = F_25 ( V_29 , L_1 ) ;
if ( F_23 ( V_4 -> V_36 ) ) {
F_26 ( V_29 , L_2 ) ;
return F_24 ( V_4 -> V_36 ) ;
}
V_4 -> V_37 = F_25 ( V_29 , L_3 ) ;
if ( F_23 ( V_4 -> V_37 ) ) {
F_26 ( V_29 , L_4 ) ;
return F_24 ( V_4 -> V_37 ) ;
}
V_32 = F_27 ( V_4 -> V_36 ) ;
if ( V_32 ) {
F_26 ( V_29 , L_5 ) ;
return V_32 ;
}
V_32 = F_27 ( V_4 -> V_37 ) ;
if ( V_32 ) {
F_26 ( V_29 , L_6 ) ;
goto V_38;
}
V_4 -> V_17 = F_28 ( V_4 -> V_37 ) ;
if ( V_4 -> V_17 == 0 ) {
F_26 ( V_29 , L_7 ) ;
V_32 = - V_39 ;
goto V_40;
}
V_4 -> V_2 . V_41 = & V_42 ;
V_4 -> V_2 . V_43 = & V_44 ;
V_4 -> V_2 . V_45 = F_11 ( V_46 *
V_18 , V_4 -> V_17 ) ;
V_4 -> V_2 . V_47 = ( V_48 *
V_18 ) / V_4 -> V_17 ;
V_4 -> V_2 . V_14 = F_29 ( V_4 -> V_2 . V_47 ,
V_49 ) ;
F_30 ( & V_4 -> V_6 ) ;
V_4 -> V_2 . V_50 = V_29 ;
F_31 ( & V_4 -> V_2 , V_4 ) ;
V_32 = F_32 ( & V_4 -> V_2 , V_51 , V_29 ) ;
F_10 ( V_4 ) ;
F_33 ( & V_4 -> V_12 , F_6 ,
( unsigned long ) & V_4 -> V_2 ) ;
F_34 ( & V_4 -> V_2 , V_52 ) ;
F_35 ( & V_4 -> V_2 , 128 ) ;
F_36 ( V_27 , V_4 ) ;
V_32 = F_37 ( & V_4 -> V_2 ) ;
if ( V_32 )
goto V_40;
return 0 ;
V_40:
F_38 ( V_4 -> V_37 ) ;
V_38:
F_38 ( V_4 -> V_36 ) ;
return V_32 ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_40 ( V_27 ) ;
F_9 ( & V_4 -> V_2 ) ;
}
static int F_41 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_40 ( V_27 ) ;
F_42 ( & V_27 -> V_29 , L_8 ) ;
F_17 ( & V_4 -> V_12 ) ;
F_43 ( & V_4 -> V_2 ) ;
F_38 ( V_4 -> V_37 ) ;
F_38 ( V_4 -> V_36 ) ;
return 0 ;
}
