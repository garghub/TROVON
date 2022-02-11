static T_1 T_2 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static int F_3 ( unsigned long V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 ,
struct V_5 , V_7 ) ;
F_5 ( F_2 ( V_1 ) + V_2 ,
V_6 -> V_8 ) ;
return 0 ;
}
static T_3 F_6 ( int V_9 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
void (* F_7)( struct V_3 * );
if ( F_2 ( V_6 -> V_11 ) & V_6 -> V_12 ) {
F_5 ( V_6 -> V_12 , V_6 -> V_11 ) ;
F_7 = F_8 ( V_6 -> V_7 . F_7 ) ;
if ( F_7 )
F_7 ( & V_6 -> V_7 ) ;
return V_13 ;
} else {
return V_14 ;
}
}
static int T_4 F_9 ( struct V_15 * V_16 )
{
void T_5 * V_17 ;
T_6 V_18 ;
int V_9 , V_19 ;
struct V_5 * V_6 ;
V_17 = F_10 ( V_16 , 0 ) ;
if ( ! V_17 ) {
F_11 ( L_1 ) ;
return - V_20 ;
}
V_19 = F_12 ( V_16 , L_2 , & V_18 ) ;
if ( V_19 ) {
F_11 ( L_3 ) ;
goto V_21;
}
V_1 = V_17 + V_22 ;
F_13 ( F_1 , 32 , V_18 ) ;
F_14 ( V_17 + V_22 , V_16 -> V_23 ,
V_18 , 300 , 32 , V_24 ) ;
V_9 = F_15 ( V_16 , V_25 ) ;
if ( V_9 <= 0 ) {
F_11 ( L_4 ) ;
V_19 = - V_26 ;
goto V_21;
}
V_6 = F_16 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 ) {
V_19 = - V_28 ;
goto V_21;
}
V_6 -> V_11 = V_17 + V_29 ;
V_6 -> V_8 = V_17 + F_17 ( V_25 ) ;
V_6 -> V_12 = F_18 ( V_25 ) ;
V_6 -> V_7 . V_23 = V_16 -> V_23 ;
V_6 -> V_7 . V_30 = 300 ;
V_6 -> V_7 . V_31 = V_32 ;
V_6 -> V_7 . V_33 = F_3 ;
V_6 -> V_7 . V_34 = F_19 ( 0 ) ;
V_6 -> V_35 . V_23 = V_16 -> V_23 ;
V_6 -> V_35 . V_36 = V_37 | V_38 ;
V_6 -> V_35 . V_10 = V_6 ;
V_6 -> V_35 . V_39 = F_6 ;
V_19 = F_20 ( V_9 , & V_6 -> V_35 ) ;
if ( V_19 ) {
F_11 ( L_5 ) ;
goto V_21;
}
F_21 ( & V_6 -> V_7 , V_18 , 0xf , 0xffffffff ) ;
F_22 ( L_6 , V_9 ) ;
return 0 ;
V_21:
F_23 ( V_17 ) ;
return V_19 ;
}
