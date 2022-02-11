int F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 V_4 ;
T_1 V_5 [ V_6 ] = {} ;
T_2 V_7 = 0 ;
int V_8 = 0 ;
int V_9 = 0 ;
if ( V_10 )
return 0 ;
F_2 ( & V_11 ) ;
V_2 = F_3 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
V_2 = F_4 ( NULL , L_2 ) ;
if ( ! V_2 ) {
F_5 ( L_3 ) ;
V_9 = - V_12 ;
goto V_13;
}
}
V_14 = F_6 ( 0 , - 1 ) ;
if ( ! V_14 ) {
F_5 ( L_4 ) ;
V_9 = - V_15 ;
goto V_13;
}
V_10 = F_7 ( V_2 , V_5 ) ;
if ( V_10 == ( V_16 ) V_17 ) {
F_5 ( L_5 ) ;
V_9 = - V_12 ;
goto V_18;
}
while ( F_8 ( V_2 , V_8 ++ , & V_4 ) == 0 ) {
if ( V_4 . V_19 > V_7 )
V_7 = V_4 . V_19 ;
V_9 = F_9 ( V_14 , V_4 . V_20 - V_10 +
V_21 , F_10 ( & V_4 ) , - 1 ) ;
if ( V_9 ) {
F_5 ( L_6 ) ;
goto V_18;
}
}
V_22 = F_11 ( V_10 , V_7 - V_10 + 1 ) ;
if ( ! V_22 ) {
F_5 ( L_7 ) ;
V_9 = - V_15 ;
goto V_18;
}
goto V_13;
V_18:
F_12 ( V_14 ) ;
V_13:
F_13 ( V_2 ) ;
return V_9 ;
}
static unsigned long F_14 ( unsigned long V_23 ,
T_3 V_24 , void * V_25 )
{
struct V_26 * V_27 ;
unsigned long V_20 ;
if ( ! V_14 && F_1 () )
goto V_28;
V_20 = F_15 ( V_14 , V_23 , V_24 , V_25 ) ;
if ( ! V_20 )
goto V_28;
V_20 = V_20 - V_21 ;
F_16 ( F_17 ( V_20 ) , 0 , V_23 ) ;
V_27 = F_18 ( sizeof( * V_27 ) , V_29 ) ;
if ( ! V_27 )
goto V_30;
V_27 -> V_20 = V_20 ;
V_27 -> V_23 = V_23 ;
F_19 ( & V_27 -> V_31 , & V_32 ) ;
return V_20 ;
V_30:
F_20 ( V_14 , V_20 , V_23 ) ;
V_28:
return ( unsigned long ) - V_15 ;
}
unsigned long F_21 ( unsigned long V_23 , unsigned long V_33 )
{
unsigned long V_20 ;
unsigned long V_34 ;
struct V_35 V_36 ;
F_22 ( & V_11 , V_34 ) ;
V_36 . V_33 = V_33 ;
V_20 = F_14 ( V_23 , V_37 ,
& V_36 ) ;
F_23 ( & V_11 , V_34 ) ;
return V_20 ;
}
int F_24 ( unsigned long V_38 )
{
unsigned long V_34 ;
int V_23 ;
struct V_26 * V_39 ;
V_23 = 0 ;
F_22 ( & V_11 , V_34 ) ;
F_25 (tmp, &muram_block_list, head) {
if ( V_39 -> V_20 == V_38 ) {
V_23 = V_39 -> V_23 ;
F_26 ( & V_39 -> V_31 ) ;
F_27 ( V_39 ) ;
break;
}
}
F_20 ( V_14 , V_38 + V_21 , V_23 ) ;
F_23 ( & V_11 , V_34 ) ;
return V_23 ;
}
unsigned long F_28 ( unsigned long V_38 , unsigned long V_23 )
{
unsigned long V_20 ;
unsigned long V_34 ;
struct V_40 V_41 ;
F_22 ( & V_11 , V_34 ) ;
V_41 . V_38 = V_38 + V_21 ;
V_20 = F_14 ( V_23 , V_42 ,
& V_41 ) ;
F_23 ( & V_11 , V_34 ) ;
return V_20 ;
}
void T_4 * F_17 ( unsigned long V_38 )
{
return V_22 + V_38 ;
}
unsigned long F_29 ( void T_4 * V_43 )
{
return V_43 - ( void T_4 * ) V_22 ;
}
T_5 F_30 ( void T_4 * V_43 )
{
return V_10 + ( ( V_44 T_4 * ) V_43 - V_22 ) ;
}
