static void F_1 ( struct V_1 * V_2 )
{
while ( F_2 ( V_2 -> V_3 + V_4 ) &
( 0x80 << V_5 ) )
F_3 () ;
}
static int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_1 ( V_2 ) ;
F_6 ( F_2 ( V_2 -> V_3 + V_10 ) , V_9 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , unsigned long V_11 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_8 ( V_11 , V_2 -> V_3 + V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static T_1 F_9 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = F_5 ( V_13 ) ;
T_2 V_14 = F_2 ( V_2 -> V_3 + V_15 ) ;
if ( V_14 & V_16 ) {
F_8 ( V_16 ,
V_2 -> V_3 + V_17 ) ;
F_10 ( V_2 -> V_18 , 1 , V_19 | V_20 ) ;
return V_21 ;
}
return V_22 ;
}
static int F_11 ( struct V_6 * V_7 , unsigned int V_23 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
if ( V_23 ) {
F_8 ( V_24 |
V_25 ,
V_2 -> V_3 + V_26 ) ;
F_8 ( V_27 ,
V_2 -> V_3 + V_28 ) ;
} else {
F_8 ( V_24 |
V_25 ,
V_2 -> V_3 + V_29 ) ;
F_8 ( V_27 ,
V_2 -> V_3 + V_17 ) ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_6 ( F_2 ( V_2 -> V_3 + V_32 ) , & V_31 -> time ) ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_30 * V_31 )
{
unsigned long V_11 ;
struct V_1 * V_2 = F_5 ( V_7 ) ;
F_14 ( & V_31 -> time , & V_11 ) ;
F_8 ( V_11 , V_2 -> V_3 + V_32 ) ;
F_11 ( V_7 , V_31 -> V_23 ) ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_16 ( V_34 ) ;
if ( ! V_2 )
return 0 ;
F_8 ( V_27 ,
V_2 -> V_3 + V_17 ) ;
F_17 ( V_2 -> V_35 , & V_34 -> V_7 ) ;
F_18 ( V_2 -> V_18 ) ;
F_19 ( V_34 , NULL ) ;
F_20 ( V_2 -> V_3 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 )
{
struct V_1 * V_2 ;
struct V_36 * V_37 ;
int V_38 ;
V_2 = F_23 ( sizeof *V_2 , V_39 ) ;
if ( ! V_2 )
return - V_40 ;
V_37 = F_24 ( V_34 , V_41 , 0 ) ;
if ( ! V_37 ) {
F_25 ( & V_34 -> V_7 , L_1 ) ;
V_38 = - V_42 ;
goto V_43;
}
V_2 -> V_3 = F_26 ( V_37 -> V_44 , F_27 ( V_37 ) ) ;
if ( ! V_2 -> V_3 ) {
F_25 ( & V_34 -> V_7 , L_2 ) ;
V_38 = - V_45 ;
goto V_43;
}
V_2 -> V_35 = F_28 ( V_34 , 0 ) ;
if ( ! ( F_2 ( V_4 + V_2 -> V_3 ) &
V_46 ) ) {
F_25 ( & V_34 -> V_7 , L_3 ) ;
V_38 = - V_47 ;
goto V_48;
}
F_19 ( V_34 , V_2 ) ;
F_29 ( V_2 -> V_3 ) ;
F_8 ( V_24 |
V_25 |
V_49 ,
V_2 -> V_3 + V_29 ) ;
F_8 ( V_50 |
V_27 ,
V_2 -> V_3 + V_17 ) ;
V_2 -> V_18 = F_30 ( V_34 -> V_51 , & V_34 -> V_7 ,
& V_52 , V_53 ) ;
if ( F_31 ( V_2 -> V_18 ) ) {
V_38 = F_32 ( V_2 -> V_18 ) ;
goto V_48;
}
V_38 = F_33 ( V_2 -> V_35 , F_9 , 0 ,
L_4 , & V_34 -> V_7 ) ;
if ( V_38 ) {
F_25 ( & V_34 -> V_7 , L_5 ,
V_2 -> V_35 ) ;
goto V_54;
}
return 0 ;
V_54:
F_18 ( V_2 -> V_18 ) ;
V_48:
F_19 ( V_34 , NULL ) ;
F_20 ( V_2 -> V_3 ) ;
V_43:
F_21 ( V_2 ) ;
return V_38 ;
}
static int F_34 ( struct V_33 * V_7 , T_3 V_55 )
{
return 0 ;
}
static int F_35 ( struct V_33 * V_7 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
F_29 ( V_2 -> V_3 ) ;
F_8 ( V_24 |
V_25 |
V_49 ,
V_2 -> V_3 + V_29 ) ;
return 0 ;
}
