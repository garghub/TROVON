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
V_10 = F_7 ( V_2 , V_5 ) ;
if ( V_10 == ( V_15 ) V_16 ) {
F_5 ( L_4 ) ;
V_9 = - V_12 ;
goto V_17;
}
while ( F_8 ( V_2 , V_8 ++ , & V_4 ) == 0 ) {
if ( V_4 . V_18 > V_7 )
V_7 = V_4 . V_18 ;
V_9 = F_9 ( V_14 , V_4 . V_19 - V_10 +
V_20 , F_10 ( & V_4 ) , - 1 ) ;
if ( V_9 ) {
F_5 ( L_5 ) ;
goto V_17;
}
}
V_21 = F_11 ( V_10 , V_7 - V_10 + 1 ) ;
if ( ! V_21 ) {
F_5 ( L_6 ) ;
V_9 = - V_22 ;
goto V_17;
}
goto V_13;
V_17:
F_12 ( V_14 ) ;
V_13:
F_13 ( V_2 ) ;
return V_9 ;
}
unsigned long F_14 ( unsigned long V_23 , unsigned long V_24 )
{
unsigned long V_19 ;
unsigned long V_25 ;
struct V_26 V_27 ;
F_15 ( & V_11 , V_25 ) ;
V_27 . V_24 = V_24 ;
V_19 = F_16 ( V_23 , V_28 ,
& V_27 ) ;
F_17 ( & V_11 , V_25 ) ;
return V_19 ;
}
int F_18 ( unsigned long V_29 )
{
unsigned long V_25 ;
int V_23 ;
struct V_30 * V_31 ;
V_23 = 0 ;
F_15 ( & V_11 , V_25 ) ;
F_19 (tmp, &muram_block_list, head) {
if ( V_31 -> V_19 == V_29 ) {
V_23 = V_31 -> V_23 ;
F_20 ( & V_31 -> V_32 ) ;
F_21 ( V_31 ) ;
break;
}
}
F_22 ( V_14 , V_29 + V_20 , V_23 ) ;
F_17 ( & V_11 , V_25 ) ;
return V_23 ;
}
unsigned long F_23 ( unsigned long V_29 , unsigned long V_23 )
{
unsigned long V_19 ;
unsigned long V_25 ;
struct V_33 V_34 ;
F_15 ( & V_11 , V_25 ) ;
V_34 . V_29 = V_29 + V_20 ;
V_19 = F_16 ( V_23 , V_35 ,
& V_34 ) ;
F_17 ( & V_11 , V_25 ) ;
return V_19 ;
}
unsigned long F_16 ( unsigned long V_23 , T_3 V_36 ,
void * V_37 )
{
struct V_30 * V_38 ;
unsigned long V_19 ;
V_19 = F_24 ( V_14 , V_23 , V_36 , V_37 ) ;
if ( ! V_19 )
goto V_39;
V_19 = V_19 - V_20 ;
F_25 ( F_26 ( V_19 ) , 0 , V_23 ) ;
V_38 = F_27 ( sizeof( * V_38 ) , V_40 ) ;
if ( ! V_38 )
goto V_41;
V_38 -> V_19 = V_19 ;
V_38 -> V_23 = V_23 ;
F_28 ( & V_38 -> V_32 , & V_42 ) ;
return V_19 ;
V_41:
F_22 ( V_14 , V_19 , V_23 ) ;
V_39:
return ( unsigned long ) - V_22 ;
}
void T_4 * F_26 ( unsigned long V_29 )
{
return V_21 + V_29 ;
}
unsigned long F_29 ( void T_4 * V_43 )
{
return V_43 - ( void T_4 * ) V_21 ;
}
T_5 F_30 ( void T_4 * V_43 )
{
return V_10 + ( ( V_44 T_4 * ) V_43 - V_21 ) ;
}
