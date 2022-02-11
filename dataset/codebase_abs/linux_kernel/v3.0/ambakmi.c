static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned int V_5 = F_2 ( V_6 ) ;
int V_7 = V_8 ;
while ( V_5 & V_9 ) {
F_3 ( V_4 -> V_10 , F_2 ( V_11 ) , 0 ) ;
V_5 = F_2 ( V_6 ) ;
V_7 = V_12 ;
}
return V_7 ;
}
static int F_4 ( struct V_13 * V_10 , unsigned char V_14 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
unsigned int V_16 = 10000 ;
while ( ( F_2 ( V_17 ) & V_18 ) == 0 && -- V_16 )
F_5 ( 10 ) ;
if ( V_16 )
F_6 ( V_14 , V_11 ) ;
return V_16 ? 0 : V_19 ;
}
static int F_7 ( struct V_13 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
unsigned int V_20 ;
int V_21 ;
V_21 = F_8 ( V_4 -> V_22 ) ;
if ( V_21 )
goto V_23;
V_20 = F_9 ( V_4 -> V_22 ) / 8000000 - 1 ;
F_6 ( V_20 , V_24 ) ;
F_6 ( V_25 , V_26 ) ;
V_21 = F_10 ( V_4 -> V_1 , F_1 , 0 , L_1 , V_4 ) ;
if ( V_21 ) {
F_11 ( V_27 L_2 , V_4 -> V_1 ) ;
F_6 ( 0 , V_26 ) ;
goto V_28;
}
F_6 ( V_25 | V_29 , V_26 ) ;
return 0 ;
V_28:
V_28 ( V_4 -> V_22 ) ;
V_23:
return V_21 ;
}
static void F_12 ( struct V_13 * V_10 )
{
struct V_3 * V_4 = V_10 -> V_15 ;
F_6 ( 0 , V_26 ) ;
F_13 ( V_4 -> V_1 , V_4 ) ;
V_28 ( V_4 -> V_22 ) ;
}
static int T_2 F_14 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_3 * V_4 ;
struct V_13 * V_10 ;
int V_21 ;
V_21 = F_15 ( V_31 , NULL ) ;
if ( V_21 )
return V_21 ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_34 ) ;
V_10 = F_16 ( sizeof( struct V_13 ) , V_34 ) ;
if ( ! V_4 || ! V_10 ) {
V_21 = - V_35 ;
goto V_23;
}
V_10 -> V_33 . type = V_36 ;
V_10 -> V_37 = F_4 ;
V_10 -> V_38 = F_7 ;
V_10 -> V_39 = F_12 ;
F_17 ( V_10 -> V_40 , F_18 ( & V_31 -> V_31 ) , sizeof( V_10 -> V_40 ) ) ;
F_17 ( V_10 -> V_41 , F_18 ( & V_31 -> V_31 ) , sizeof( V_10 -> V_41 ) ) ;
V_10 -> V_15 = V_4 ;
V_10 -> V_31 . V_42 = & V_31 -> V_31 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_43 = F_19 ( V_31 -> V_44 . V_45 , F_20 ( & V_31 -> V_44 ) ) ;
if ( ! V_4 -> V_43 ) {
V_21 = - V_35 ;
goto V_23;
}
V_4 -> V_22 = F_21 ( & V_31 -> V_31 , L_3 ) ;
if ( F_22 ( V_4 -> V_22 ) ) {
V_21 = F_23 ( V_4 -> V_22 ) ;
goto V_46;
}
V_4 -> V_1 = V_31 -> V_1 [ 0 ] ;
F_24 ( V_31 , V_4 ) ;
F_25 ( V_4 -> V_10 ) ;
return 0 ;
V_46:
F_26 ( V_4 -> V_43 ) ;
V_23:
F_27 ( V_4 ) ;
F_27 ( V_10 ) ;
F_28 ( V_31 ) ;
return V_21 ;
}
static int T_3 F_29 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_30 ( V_31 ) ;
F_24 ( V_31 , NULL ) ;
F_31 ( V_4 -> V_10 ) ;
F_32 ( V_4 -> V_22 ) ;
F_26 ( V_4 -> V_43 ) ;
F_27 ( V_4 ) ;
F_28 ( V_31 ) ;
return 0 ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_30 ( V_31 ) ;
F_34 ( V_4 -> V_10 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_47 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_47 ) ;
}
