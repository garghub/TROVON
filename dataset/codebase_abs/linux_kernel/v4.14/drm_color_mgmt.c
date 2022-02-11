T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
T_1 V_3 = V_1 ;
T_1 V_4 = 0xffff >> ( 16 - V_2 ) ;
if ( V_2 < 16 ) {
V_3 += 1UL << ( 16 - V_2 - 1 ) ;
V_3 >>= 16 - V_2 ;
}
return F_2 ( V_3 , 0 , V_4 ) ;
}
void F_3 ( struct V_5 * V_6 ,
T_2 V_7 ,
bool V_8 ,
T_2 V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = & V_11 -> V_14 ;
if ( V_7 ) {
F_4 ( & V_6 -> V_15 ,
V_13 -> V_16 , 0 ) ;
F_4 ( & V_6 -> V_15 ,
V_13 -> V_17 ,
V_7 ) ;
}
if ( V_8 )
F_4 ( & V_6 -> V_15 ,
V_13 -> V_18 , 0 ) ;
if ( V_9 ) {
F_4 ( & V_6 -> V_15 ,
V_13 -> V_19 , 0 ) ;
F_4 ( & V_6 -> V_15 ,
V_13 -> V_20 ,
V_9 ) ;
}
}
int F_5 ( struct V_5 * V_6 ,
int V_21 )
{
T_3 * V_22 , * V_23 , * V_24 ;
int V_25 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_26 = F_6 ( V_21 , sizeof( T_3 ) * 3 ,
V_27 ) ;
if ( ! V_6 -> V_26 ) {
V_6 -> V_21 = 0 ;
return - V_28 ;
}
V_22 = V_6 -> V_26 ;
V_23 = V_22 + V_21 ;
V_24 = V_23 + V_21 ;
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ ) {
V_22 [ V_25 ] = V_25 << 8 ;
V_23 [ V_25 ] = V_25 << 8 ;
V_24 [ V_25 ] = V_25 << 8 ;
}
return 0 ;
}
int F_7 ( struct V_10 * V_11 ,
void * V_29 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_29 ;
struct V_5 * V_6 ;
void * V_22 , * V_23 , * V_24 ;
int V_34 ;
struct V_35 V_36 ;
int V_37 = 0 ;
if ( ! F_8 ( V_11 , V_38 ) )
return - V_39 ;
V_6 = F_9 ( V_11 , V_33 -> V_40 ) ;
if ( ! V_6 )
return - V_41 ;
if ( V_6 -> V_42 -> V_43 == NULL )
return - V_44 ;
if ( V_33 -> V_21 != V_6 -> V_21 )
return - V_39 ;
F_10 ( & V_36 , 0 ) ;
V_45:
V_37 = F_11 ( V_11 , & V_36 ) ;
if ( V_37 )
goto V_46;
V_34 = V_33 -> V_21 * ( sizeof( T_3 ) ) ;
V_22 = V_6 -> V_26 ;
if ( F_12 ( V_22 , ( void V_47 * ) ( unsigned long ) V_33 -> V_48 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_23 = V_22 + V_34 ;
if ( F_12 ( V_23 , ( void V_47 * ) ( unsigned long ) V_33 -> V_50 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_24 = V_23 + V_34 ;
if ( F_12 ( V_24 , ( void V_47 * ) ( unsigned long ) V_33 -> V_51 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_37 = V_6 -> V_42 -> V_43 ( V_6 , V_22 , V_23 , V_24 ,
V_6 -> V_21 , & V_36 ) ;
V_46:
if ( V_37 == - V_52 ) {
F_13 ( & V_36 ) ;
goto V_45;
}
F_14 ( & V_36 ) ;
F_15 ( & V_36 ) ;
return V_37 ;
}
int F_16 ( struct V_10 * V_11 ,
void * V_29 , struct V_30 * V_31 )
{
struct V_32 * V_33 = V_29 ;
struct V_5 * V_6 ;
void * V_22 , * V_23 , * V_24 ;
int V_34 ;
int V_37 = 0 ;
if ( ! F_8 ( V_11 , V_38 ) )
return - V_39 ;
V_6 = F_9 ( V_11 , V_33 -> V_40 ) ;
if ( ! V_6 )
return - V_41 ;
if ( V_33 -> V_21 != V_6 -> V_21 )
return - V_39 ;
F_17 ( & V_6 -> V_53 , NULL ) ;
V_34 = V_33 -> V_21 * ( sizeof( T_3 ) ) ;
V_22 = V_6 -> V_26 ;
if ( F_18 ( ( void V_47 * ) ( unsigned long ) V_33 -> V_48 , V_22 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_23 = V_22 + V_34 ;
if ( F_18 ( ( void V_47 * ) ( unsigned long ) V_33 -> V_50 , V_23 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_24 = V_23 + V_34 ;
if ( F_18 ( ( void V_47 * ) ( unsigned long ) V_33 -> V_51 , V_24 , V_34 ) ) {
V_37 = - V_49 ;
goto V_46;
}
V_46:
F_19 ( & V_6 -> V_53 ) ;
return V_37 ;
}
