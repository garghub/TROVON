static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( 1 , V_4 -> V_6 + V_7 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
F_5 ( V_4 -> V_9 , 1 , V_10 ) ;
return V_11 ;
}
static int F_6 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
if ( F_8 ( V_4 -> V_6 + V_16 ) ) {
F_9 ( F_8 ( V_4 -> V_6 + V_17 ) , V_15 ) ;
F_4 ( V_4 -> V_5 ) ;
return F_10 ( V_15 ) ;
}
F_4 ( V_4 -> V_5 ) ;
return - V_18 ;
}
static int F_11 ( struct V_12 * V_13 , unsigned long V_19 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_19 , V_4 -> V_6 + V_20 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_9 ( F_8 ( V_4 -> V_6 + V_23 ) , & V_22 -> time ) ;
V_22 -> V_24 = F_8 ( V_4 -> V_6 + V_7 ) & 1U ;
V_22 -> V_25 = F_8 ( V_4 -> V_6 + V_8 ) & 1U ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 , struct V_21 * V_22 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
unsigned long time ;
F_14 ( & V_22 -> time , & time ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( time , V_4 -> V_6 + V_23 ) ;
F_3 ( V_22 -> V_25 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 , unsigned int V_25 )
{
struct V_3 * V_4 = F_7 ( V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
if ( V_25 )
F_3 ( 1 , V_4 -> V_6 + V_8 ) ;
else
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
if ( V_4 ) {
F_17 ( V_4 -> V_9 ) ;
F_18 ( V_4 -> V_5 ) ;
F_19 ( V_27 , NULL ) ;
}
return 0 ;
}
static int T_3 F_20 ( struct V_26 * V_27 )
{
int V_28 ;
struct V_3 * V_4 ;
struct V_29 * V_30 ;
V_4 = F_21 ( & V_27 -> V_13 ,
sizeof( struct V_3 ) , V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_30 = F_22 ( V_27 , V_33 , 0 ) ;
if ( ! V_30 )
return - V_34 ;
V_4 -> V_35 = V_30 -> V_36 ;
V_4 -> V_37 = F_23 ( V_30 ) ;
if ( F_24 ( & V_27 -> V_13 , V_4 -> V_35 , V_4 -> V_37 ,
L_1 ) == NULL )
return - V_38 ;
V_4 -> V_6 = F_25 ( & V_27 -> V_13 , V_4 -> V_35 , V_4 -> V_37 ) ;
if ( ! V_4 -> V_6 )
return - V_32 ;
V_4 -> V_1 = F_26 ( V_27 , 0 ) ;
if ( F_27 ( & V_27 -> V_13 , V_4 -> V_1 , F_1 , 0 ,
L_2 , V_4 ) )
return - V_39 ;
V_4 -> V_5 = F_28 ( & V_27 -> V_13 , NULL ) ;
if ( F_29 ( V_4 -> V_5 ) ) {
V_28 = F_30 ( V_4 -> V_5 ) ;
F_31 ( & V_27 -> V_13 , L_3 ) ;
return V_28 ;
}
V_28 = F_32 ( V_4 -> V_5 ) ;
if ( V_28 ) {
F_31 ( & V_27 -> V_13 , L_4 ) ;
return V_28 ;
}
F_4 ( V_4 -> V_5 ) ;
F_19 ( V_27 , V_4 ) ;
V_4 -> V_9 = F_33 ( L_5 , & V_27 -> V_13 , & V_40 ,
V_41 ) ;
if ( F_29 ( V_4 -> V_9 ) ) {
V_28 = F_30 ( V_4 -> V_9 ) ;
goto V_42;
}
return 0 ;
V_42:
F_19 ( V_27 , NULL ) ;
F_18 ( V_4 -> V_5 ) ;
return V_28 ;
}
static int F_34 ( struct V_26 * V_27 , T_4 V_43 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
if ( F_35 ( & V_27 -> V_13 ) ) {
F_36 ( V_4 -> V_1 ) ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_4 -> V_44 = F_8 ( V_4 -> V_6 + V_8 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
}
F_18 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_37 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
F_38 ( V_4 -> V_5 ) ;
if ( F_35 ( & V_27 -> V_13 ) ) {
F_39 ( V_4 -> V_1 ) ;
} else {
F_2 ( V_4 -> V_5 ) ;
F_3 ( V_4 -> V_44 , V_4 -> V_6 + V_8 ) ;
F_4 ( V_4 -> V_5 ) ;
}
return 0 ;
}
static void F_40 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_7 ( & V_27 -> V_13 ) ;
F_2 ( V_4 -> V_5 ) ;
F_3 ( 0 , V_4 -> V_6 + V_8 ) ;
F_41 ( V_4 -> V_5 ) ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_45 , F_20 ) ;
}
static void T_2 F_44 ( void )
{
F_45 ( & V_45 ) ;
}
