static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_3 || V_5 -> V_6 )
return V_5 -> V_6 ;
F_3 ( & V_5 -> V_7 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_9 ;
T_2 V_10 ;
* V_8 = F_5 ( V_5 -> V_11 ) ;
V_9 = V_12 ;
V_10 = V_9 - V_5 -> V_13 ;
V_10 = V_5 -> V_14 - ( V_10 % V_5 -> V_14 ) ;
V_5 -> V_13 = V_9 + V_10 ;
V_5 -> V_6 = 0 ;
F_6 ( & V_5 -> V_7 ) ;
F_7 ( & V_5 -> V_15 , V_5 -> V_13 ) ;
return 4 ;
}
static void F_8 ( unsigned long V_8 )
{
struct V_4 * V_5
= (struct V_4 * ) V_8 ;
V_5 -> V_6 = 1 ;
F_9 ( & V_5 -> V_7 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_4 * V_5 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
int V_14 ;
if ( ! V_17 -> V_20 . V_25 && ! V_19 ) {
F_11 ( & V_17 -> V_20 , L_1 ) ;
return - V_26 ;
}
V_23 = F_12 ( V_17 , V_27 , 0 ) ;
if ( ! V_23 )
return - V_28 ;
if ( V_23 -> V_29 % 4 != 0 || F_13 ( V_23 ) != 4 ) {
F_11 ( & V_17 -> V_20 ,
L_2 ) ;
return - V_26 ;
}
V_5 = F_14 ( & V_17 -> V_20 ,
sizeof( struct V_4 ) , V_30 ) ;
if ( ! V_5 )
return - V_31 ;
F_15 ( V_17 , V_5 ) ;
if ( V_17 -> V_20 . V_25 ) {
int V_32 ;
if ( ! F_16 ( V_17 -> V_20 . V_25 ,
L_3 , & V_32 ) )
V_14 = V_32 ;
else {
F_11 ( & V_17 -> V_20 , L_4 ) ;
return - V_26 ;
}
} else {
V_14 = V_19 -> V_14 ;
}
V_5 -> V_14 = F_17 ( V_14 ) ;
if ( V_5 -> V_14 < 1 ) {
F_11 ( & V_17 -> V_20 , L_5 ) ;
return - V_26 ;
}
V_5 -> V_13 = V_12 ;
V_5 -> V_6 = 1 ;
F_18 ( & V_5 -> V_7 ) ;
F_9 ( & V_5 -> V_7 ) ;
F_19 ( & V_5 -> V_15 , F_8 , ( unsigned long ) V_5 ) ;
V_5 -> V_33 . V_34 = F_20 ( & V_17 -> V_20 ) ;
V_5 -> V_33 . V_35 = F_1 ;
V_5 -> V_33 . V_36 = F_4 ;
V_5 -> V_33 . V_5 = ( unsigned long ) V_5 ;
V_5 -> V_11 = F_21 ( & V_17 -> V_20 , V_23 ) ;
if ( F_22 ( V_5 -> V_11 ) ) {
V_24 = F_23 ( V_5 -> V_11 ) ;
goto V_37;
}
V_24 = F_24 ( & V_5 -> V_33 ) ;
if ( V_24 ) {
F_11 ( & V_17 -> V_20 , L_6 ) ;
goto V_37;
}
F_25 ( & V_17 -> V_20 , L_7 ,
V_5 -> V_11 , V_14 ) ;
return 0 ;
V_37:
F_26 ( & V_5 -> V_15 ) ;
return V_24 ;
}
static int F_27 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = F_28 ( V_17 ) ;
F_29 ( & V_5 -> V_33 ) ;
F_26 ( & V_5 -> V_15 ) ;
return 0 ;
}
