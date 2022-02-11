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
F_15 ( V_22 ) ;
V_19 = (struct V_19 * ) & F_16 () -> V_23 ;
F_17 ( V_19 ) ;
V_21 = & V_16 [ V_19 -> V_5 ] ;
F_18 () ;
F_19 (airq, head, list)
if ( ( * V_2 -> V_8 & V_2 -> V_13 ) != 0 )
V_2 -> V_4 ( V_2 ) ;
F_20 () ;
return V_24 ;
}
void T_2 F_21 ( void )
{
F_22 ( V_25 ,
& V_26 , V_27 ) ;
F_23 ( V_25 , & V_28 ) ;
}
struct V_29 * F_24 ( unsigned long V_30 , unsigned long V_11 )
{
struct V_29 * V_31 ;
unsigned long V_32 ;
V_31 = F_2 ( sizeof( * V_31 ) , V_9 ) ;
if ( ! V_31 )
goto V_33;
V_31 -> V_30 = V_30 ;
V_32 = F_25 ( V_30 ) * sizeof( unsigned long ) ;
V_31 -> V_34 = F_2 ( V_32 , V_9 ) ;
if ( ! V_31 -> V_34 )
goto V_35;
if ( V_11 & V_36 ) {
V_31 -> V_37 = F_26 ( V_32 , V_9 ) ;
if ( ! V_31 -> V_37 )
goto V_35;
memset ( V_31 -> V_37 , 0xff , V_32 ) ;
V_31 -> V_38 = 0 ;
} else
V_31 -> V_38 = V_30 ;
if ( V_11 & V_39 ) {
V_31 -> V_40 = F_2 ( V_32 , V_9 ) ;
if ( ! V_31 -> V_40 )
goto V_35;
}
if ( V_11 & V_41 ) {
V_32 = V_30 * sizeof( unsigned long ) ;
V_31 -> V_42 = F_2 ( V_32 , V_9 ) ;
if ( ! V_31 -> V_42 )
goto V_35;
}
if ( V_11 & V_43 ) {
V_32 = V_30 * sizeof( unsigned int ) ;
V_31 -> V_44 = F_2 ( V_32 , V_9 ) ;
if ( ! V_31 -> V_44 )
goto V_35;
}
F_27 ( & V_31 -> V_45 ) ;
return V_31 ;
V_35:
F_13 ( V_31 -> V_42 ) ;
F_13 ( V_31 -> V_40 ) ;
F_13 ( V_31 -> V_37 ) ;
F_13 ( V_31 -> V_34 ) ;
F_13 ( V_31 ) ;
V_33:
return NULL ;
}
void F_28 ( struct V_29 * V_31 )
{
F_13 ( V_31 -> V_44 ) ;
F_13 ( V_31 -> V_42 ) ;
F_13 ( V_31 -> V_40 ) ;
F_13 ( V_31 -> V_34 ) ;
F_13 ( V_31 -> V_37 ) ;
F_13 ( V_31 ) ;
}
unsigned long F_29 ( struct V_29 * V_31 , unsigned long V_46 )
{
unsigned long V_47 , V_48 , V_11 ;
if ( ! V_31 -> V_37 || V_46 == 0 )
return - 1UL ;
F_30 ( & V_31 -> V_45 , V_11 ) ;
V_47 = F_31 ( V_31 -> V_37 , V_31 -> V_30 ) ;
while ( V_47 + V_46 <= V_31 -> V_30 ) {
for ( V_48 = 1 ; V_48 < V_46 ; V_48 ++ )
if ( ! F_32 ( V_47 + V_48 , V_31 -> V_37 ) )
break;
if ( V_48 >= V_46 ) {
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ )
F_33 ( V_47 + V_48 , V_31 -> V_37 ) ;
if ( V_47 + V_46 >= V_31 -> V_38 )
V_31 -> V_38 = V_47 + V_46 + 1 ;
break;
}
V_47 = F_34 ( V_31 -> V_37 , V_31 -> V_30 , V_47 + V_48 + 1 ) ;
}
if ( V_47 + V_46 > V_31 -> V_30 )
V_47 = - 1UL ;
F_35 ( & V_31 -> V_45 , V_11 ) ;
return V_47 ;
}
void F_36 ( struct V_29 * V_31 , unsigned long V_47 , unsigned long V_46 )
{
unsigned long V_48 , V_11 ;
if ( ! V_31 -> V_37 || V_46 == 0 )
return;
F_30 ( & V_31 -> V_45 , V_11 ) ;
for ( V_48 = 0 ; V_48 < V_46 ; V_48 ++ ) {
F_33 ( V_47 + V_48 , V_31 -> V_34 ) ;
F_37 ( V_47 + V_48 , V_31 -> V_37 ) ;
}
if ( V_47 + V_46 >= V_31 -> V_38 ) {
while ( V_31 -> V_38 > 0 && ! F_32 ( V_31 -> V_38 - 1 , V_31 -> V_37 ) )
V_31 -> V_38 -- ;
}
F_35 ( & V_31 -> V_45 , V_11 ) ;
}
unsigned long F_38 ( struct V_29 * V_31 , unsigned long V_49 ,
unsigned long V_38 )
{
unsigned long V_47 ;
V_47 = F_34 ( V_31 -> V_34 , V_38 , V_49 ) ;
if ( V_47 >= V_38 )
return - 1UL ;
F_33 ( V_47 , V_31 -> V_34 ) ;
return V_47 ;
}
