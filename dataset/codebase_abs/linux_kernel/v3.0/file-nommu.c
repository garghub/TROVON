int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
struct V_6 * V_7 ;
unsigned V_8 ;
void * V_9 ;
int V_10 ;
V_8 = F_2 ( V_2 ) ;
if ( F_3 ( V_8 >= V_11 ) )
return - V_12 ;
V_10 = F_4 ( V_1 , V_2 ) ;
if ( V_10 )
return V_10 ;
F_5 ( V_1 , V_2 ) ;
V_7 = F_6 ( F_7 ( V_1 -> V_13 ) , V_8 ) ;
if ( ! V_7 )
return - V_14 ;
V_4 = 1UL << V_8 ;
V_3 = ( V_2 + V_15 - 1 ) >> V_16 ;
F_8 ( V_7 , V_8 ) ;
for ( V_5 = V_3 ; V_5 < V_4 ; V_5 ++ )
F_9 ( V_7 + V_5 ) ;
V_2 = V_15 * V_3 ;
V_9 = F_10 ( V_7 ) ;
memset ( V_9 , 0 , V_2 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
struct V_6 * V_6 = V_7 + V_5 ;
V_10 = F_11 ( V_6 , V_1 -> V_13 , V_5 ,
V_17 ) ;
if ( V_10 < 0 )
goto V_18;
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
}
return 0 ;
V_18:
while ( V_5 < V_3 )
F_9 ( V_7 + V_5 ++ ) ;
return V_10 ;
}
static int F_15 ( struct V_1 * V_1 , T_2 V_2 , T_2 V_19 )
{
int V_10 ;
if ( V_19 == 0 ) {
if ( F_3 ( V_2 >> 32 ) )
return - V_12 ;
return F_1 ( V_1 , V_2 ) ;
}
if ( V_2 < V_19 ) {
V_10 = F_16 ( V_1 , V_19 , V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
}
F_17 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_20 * V_20 , struct V_21 * V_22 )
{
struct V_1 * V_1 = V_20 -> V_23 ;
unsigned int V_24 = V_22 -> V_25 ;
int V_10 = 0 ;
V_10 = F_19 ( V_1 , V_22 ) ;
if ( V_10 )
return V_10 ;
if ( V_22 -> V_25 & V_26 ) {
T_2 V_19 = V_1 -> V_27 ;
if ( V_22 -> V_28 != V_19 ) {
V_10 = F_15 ( V_1 , V_22 -> V_28 , V_19 ) ;
if ( V_10 < 0 || V_22 -> V_25 == V_26 )
goto V_29;
} else {
V_22 -> V_25 |= V_30 | V_31 ;
}
}
F_20 ( V_1 , V_22 ) ;
V_29:
V_22 -> V_25 = V_24 ;
return V_10 ;
}
unsigned long F_21 ( struct V_32 * V_32 ,
unsigned long V_33 , unsigned long V_34 ,
unsigned long V_35 , unsigned long V_36 )
{
unsigned long V_37 , V_38 , V_39 , V_5 , V_10 ;
struct V_1 * V_1 = V_32 -> V_40 . V_20 -> V_23 ;
struct V_6 * * V_7 = NULL , * * V_41 , * V_6 ;
T_2 V_42 ;
if ( ! ( V_36 & V_43 ) )
return V_33 ;
V_38 = ( V_34 + V_15 - 1 ) >> V_16 ;
V_42 = F_22 ( V_1 ) ;
V_10 = - V_44 ;
V_37 = ( V_42 + V_15 - 1 ) >> V_16 ;
if ( V_35 >= V_37 )
goto V_29;
if ( V_37 - V_35 < V_38 )
goto V_29;
V_10 = - V_14 ;
V_7 = F_23 ( V_38 * sizeof( struct V_6 * ) , V_17 ) ;
if ( ! V_7 )
goto V_45;
V_39 = F_24 ( V_1 -> V_13 , V_35 , V_38 , V_7 ) ;
if ( V_39 != V_38 )
goto V_46;
V_41 = V_7 ;
V_6 = * V_41 ++ ;
V_6 ++ ;
for ( V_5 = V_38 ; V_5 > 1 ; V_5 -- )
if ( * V_41 ++ != V_6 ++ )
goto V_46;
V_10 = ( unsigned long ) F_10 ( V_7 [ 0 ] ) ;
V_46:
V_41 = V_7 ;
for ( V_5 = V_39 ; V_5 > 0 ; V_5 -- )
F_14 ( * V_41 ++ ) ;
V_45:
F_25 ( V_7 ) ;
V_29:
return V_10 ;
}
int F_26 ( struct V_32 * V_32 , struct V_47 * V_48 )
{
if ( ! ( V_48 -> V_49 & V_50 ) )
return - V_51 ;
F_27 ( V_32 ) ;
V_48 -> V_52 = & V_53 ;
return 0 ;
}
