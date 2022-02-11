int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 32 ] ;
if ( ! V_2 -> V_4 || V_2 -> V_5 > V_6 )
return - V_7 ;
if ( ! V_2 -> V_8 ) {
V_2 -> V_8 = F_2 ( 1 , V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
V_2 -> V_11 |= V_12 ;
}
if ( ! V_2 -> V_13 )
V_2 -> V_13 = 0xff ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
F_3 ( 4 , V_3 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( & V_14 ) ;
F_6 ( & V_2 -> V_15 , & V_16 [ V_2 -> V_5 ] ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
char V_3 [ 32 ] ;
if ( F_9 ( & V_2 -> V_15 ) )
return;
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_2 ) ;
F_3 ( 4 , V_3 ) ;
F_5 ( & V_14 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_7 ( & V_14 ) ;
F_11 () ;
F_12 ( V_2 -> V_5 ) ;
if ( V_2 -> V_11 & V_12 ) {
F_13 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_11 &= ~ V_12 ;
}
}
static T_1 F_14 ( int V_17 , void * V_18 )
{
struct V_19 * V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
F_15 ( V_22 . V_23 , 1 ) ;
V_19 = (struct V_19 * ) & F_16 () -> V_24 ;
V_21 = & V_16 [ V_19 -> V_5 ] ;
F_17 () ;
F_18 (airq, head, list)
if ( ( * V_2 -> V_8 & V_2 -> V_13 ) != 0 )
V_2 -> V_4 ( V_2 ) ;
F_19 () ;
return V_25 ;
}
void T_2 F_20 ( void )
{
F_21 ( V_26 ,
& V_27 , V_28 ) ;
F_22 ( V_26 , & V_29 ) ;
}
struct V_30 * F_23 ( unsigned long V_31 , unsigned long V_11 )
{
struct V_30 * V_32 ;
unsigned long V_33 ;
V_32 = F_2 ( sizeof( * V_32 ) , V_9 ) ;
if ( ! V_32 )
goto V_34;
V_32 -> V_31 = V_31 ;
V_33 = F_24 ( V_31 ) * sizeof( unsigned long ) ;
V_32 -> V_35 = F_2 ( V_33 , V_9 ) ;
if ( ! V_32 -> V_35 )
goto V_36;
if ( V_11 & V_37 ) {
V_32 -> V_38 = F_25 ( V_33 , V_9 ) ;
if ( ! V_32 -> V_38 )
goto V_36;
memset ( V_32 -> V_38 , 0xff , V_33 ) ;
V_32 -> V_39 = 0 ;
} else
V_32 -> V_39 = V_31 ;
if ( V_11 & V_40 ) {
V_32 -> V_41 = F_2 ( V_33 , V_9 ) ;
if ( ! V_32 -> V_41 )
goto V_36;
}
if ( V_11 & V_42 ) {
V_33 = V_31 * sizeof( unsigned long ) ;
V_32 -> V_43 = F_2 ( V_33 , V_9 ) ;
if ( ! V_32 -> V_43 )
goto V_36;
}
if ( V_11 & V_44 ) {
V_33 = V_31 * sizeof( unsigned int ) ;
V_32 -> V_45 = F_2 ( V_33 , V_9 ) ;
if ( ! V_32 -> V_45 )
goto V_36;
}
F_26 ( & V_32 -> V_46 ) ;
return V_32 ;
V_36:
F_13 ( V_32 -> V_43 ) ;
F_13 ( V_32 -> V_41 ) ;
F_13 ( V_32 -> V_38 ) ;
F_13 ( V_32 -> V_35 ) ;
F_13 ( V_32 ) ;
V_34:
return NULL ;
}
void F_27 ( struct V_30 * V_32 )
{
F_13 ( V_32 -> V_45 ) ;
F_13 ( V_32 -> V_43 ) ;
F_13 ( V_32 -> V_41 ) ;
F_13 ( V_32 -> V_35 ) ;
F_13 ( V_32 -> V_38 ) ;
F_13 ( V_32 ) ;
}
unsigned long F_28 ( struct V_30 * V_32 )
{
unsigned long V_47 ;
if ( ! V_32 -> V_38 )
return - 1UL ;
F_5 ( & V_32 -> V_46 ) ;
V_47 = F_29 ( V_32 -> V_38 , V_32 -> V_31 ) ;
if ( V_47 < V_32 -> V_31 ) {
F_30 ( V_47 , V_32 -> V_38 ) ;
if ( V_47 >= V_32 -> V_39 )
V_32 -> V_39 = V_47 + 1 ;
} else
V_47 = - 1UL ;
F_7 ( & V_32 -> V_46 ) ;
return V_47 ;
}
void F_31 ( struct V_30 * V_32 , unsigned long V_47 )
{
if ( ! V_32 -> V_38 )
return;
F_5 ( & V_32 -> V_46 ) ;
F_30 ( V_47 , V_32 -> V_35 ) ;
F_32 ( V_47 , V_32 -> V_38 ) ;
if ( V_47 == V_32 -> V_39 - 1 ) {
while ( -- V_32 -> V_39 > 0 )
if ( ! F_33 ( V_32 -> V_39 - 1 , V_32 -> V_38 ) )
break;
}
F_7 ( & V_32 -> V_46 ) ;
}
unsigned long F_34 ( struct V_30 * V_32 , unsigned long V_48 ,
unsigned long V_39 )
{
unsigned long V_47 ;
V_47 = F_35 ( V_32 -> V_35 , V_39 , V_48 ) ;
if ( V_47 >= V_39 )
return - 1UL ;
F_30 ( V_47 , V_32 -> V_35 ) ;
return V_47 ;
}
