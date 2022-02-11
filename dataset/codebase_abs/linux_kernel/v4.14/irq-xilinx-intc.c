static void F_1 ( int V_1 , T_1 V_2 )
{
if ( F_2 ( & V_3 ) )
F_3 ( V_2 , V_4 -> V_5 + V_1 ) ;
else
F_4 ( V_2 , V_4 -> V_5 + V_1 ) ;
}
static unsigned int F_5 ( int V_1 )
{
if ( F_2 ( & V_3 ) )
return F_6 ( V_4 -> V_5 + V_1 ) ;
else
return F_7 ( V_4 -> V_5 + V_1 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
unsigned long V_8 = 1 << V_7 -> V_9 ;
F_9 ( L_1 , V_7 -> V_9 ) ;
if ( F_10 ( V_7 ) )
F_1 ( V_10 , V_8 ) ;
F_1 ( V_11 , V_8 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
F_9 ( L_2 , V_7 -> V_9 ) ;
F_1 ( V_12 , 1 << V_7 -> V_9 ) ;
}
static void F_12 ( struct V_6 * V_7 )
{
F_9 ( L_3 , V_7 -> V_9 ) ;
F_1 ( V_10 , 1 << V_7 -> V_9 ) ;
}
static void F_13 ( struct V_6 * V_7 )
{
unsigned long V_8 = 1 << V_7 -> V_9 ;
F_9 ( L_4 , V_7 -> V_9 ) ;
F_1 ( V_12 , V_8 ) ;
F_1 ( V_10 , V_8 ) ;
}
unsigned int F_14 ( void )
{
unsigned int V_9 , V_13 = - 1 ;
V_9 = F_5 ( V_14 ) ;
if ( V_9 != - 1U )
V_13 = F_15 ( V_4 -> V_15 , V_9 ) ;
F_9 ( L_5 , V_9 , V_13 ) ;
return V_13 ;
}
static int F_16 ( struct V_16 * V_7 , unsigned int V_13 , T_2 V_17 )
{
if ( V_4 -> V_18 & ( 1 << V_17 ) ) {
F_17 ( V_13 , & V_19 ,
V_20 , L_6 ) ;
F_18 ( V_13 , V_21 ) ;
} else {
F_17 ( V_13 , & V_19 ,
V_22 , L_7 ) ;
F_19 ( V_13 , V_21 ) ;
}
return 0 ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_21 ( V_24 ) ;
T_1 V_27 ;
F_22 ( V_26 , V_24 ) ;
do {
V_27 = F_14 () ;
if ( V_27 == - 1U )
break;
F_23 ( V_27 ) ;
} while ( true );
F_24 ( V_26 , V_24 ) ;
}
static int T_3 F_25 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
T_1 V_31 ;
int V_32 , V_13 ;
struct V_33 * V_34 ;
if ( V_4 ) {
F_26 ( L_8 ) ;
return - V_35 ;
}
V_34 = F_27 ( sizeof( * V_34 ) , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
V_4 = V_34 ;
V_34 -> V_5 = F_28 ( V_29 , 0 ) ;
F_29 ( ! V_34 -> V_5 ) ;
V_32 = F_30 ( V_29 , L_9 , & V_31 ) ;
if ( V_32 < 0 ) {
F_26 ( L_10 ) ;
goto V_38;
}
V_32 = F_30 ( V_29 , L_11 , & V_34 -> V_18 ) ;
if ( V_32 < 0 ) {
F_31 ( L_12 ) ;
V_34 -> V_18 = 0 ;
}
if ( V_34 -> V_18 >> V_31 )
F_31 ( L_13 ) ;
F_32 ( L_14 ,
V_29 , V_31 , V_34 -> V_18 ) ;
F_1 ( V_39 , 0 ) ;
F_1 ( V_10 , 0xffffffff ) ;
F_1 ( V_40 , V_41 | V_42 ) ;
if ( ! ( F_5 ( V_40 ) & ( V_41 | V_42 ) ) ) {
F_33 ( & V_3 ) ;
F_1 ( V_40 , V_41 | V_42 ) ;
}
V_34 -> V_15 = F_34 ( V_29 , V_31 ,
& V_43 , V_34 ) ;
if ( ! V_34 -> V_15 ) {
F_26 ( L_15 ) ;
goto V_38;
}
if ( V_30 ) {
V_13 = F_35 ( V_29 , 0 ) ;
if ( V_13 ) {
F_36 ( V_13 ,
F_20 ,
V_34 ) ;
} else {
F_26 ( L_16 ) ;
V_32 = - V_35 ;
goto V_38;
}
} else {
F_37 ( V_34 -> V_15 ) ;
}
return 0 ;
V_38:
V_4 = NULL ;
F_38 ( V_34 ) ;
return V_32 ;
}
