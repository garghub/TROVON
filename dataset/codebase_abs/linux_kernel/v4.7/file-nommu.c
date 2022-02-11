static unsigned F_1 ( struct V_1 * V_1 )
{
return V_2 | V_3 | V_4 |
V_5 | V_6 ;
}
int F_2 ( struct V_7 * V_7 , T_1 V_8 )
{
unsigned long V_9 , V_10 , V_11 ;
struct V_12 * V_13 ;
unsigned V_14 ;
void * V_15 ;
int V_16 ;
T_2 V_17 = F_3 ( V_7 -> V_18 ) ;
V_14 = F_4 ( V_8 ) ;
if ( F_5 ( V_14 >= V_19 ) )
return - V_20 ;
V_16 = F_6 ( V_7 , V_8 ) ;
if ( V_16 )
return V_16 ;
F_7 ( V_7 , V_8 ) ;
V_13 = F_8 ( V_17 , V_14 ) ;
if ( ! V_13 )
return - V_21 ;
V_10 = 1UL << V_14 ;
V_9 = ( V_8 + V_22 - 1 ) >> V_23 ;
F_9 ( V_13 , V_14 ) ;
for ( V_11 = V_9 ; V_11 < V_10 ; V_11 ++ )
F_10 ( V_13 + V_11 ) ;
V_8 = V_22 * V_9 ;
V_15 = F_11 ( V_13 ) ;
memset ( V_15 , 0 , V_8 ) ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ ) {
struct V_12 * V_12 = V_13 + V_11 ;
V_16 = F_12 ( V_12 , V_7 -> V_18 , V_11 ,
V_17 ) ;
if ( V_16 < 0 )
goto V_24;
F_13 ( V_12 ) ;
F_14 ( V_12 ) ;
F_15 ( V_12 ) ;
F_16 ( V_12 ) ;
}
return 0 ;
V_24:
while ( V_11 < V_9 )
F_10 ( V_13 + V_11 ++ ) ;
return V_16 ;
}
static int F_17 ( struct V_7 * V_7 , T_3 V_8 , T_3 V_25 )
{
int V_16 ;
if ( V_25 == 0 ) {
if ( F_5 ( V_8 >> 32 ) )
return - V_20 ;
return F_2 ( V_7 , V_8 ) ;
}
if ( V_8 < V_25 ) {
V_16 = F_18 ( V_7 , V_25 , V_8 ) ;
if ( V_16 < 0 )
return V_16 ;
}
F_19 ( V_7 , V_8 ) ;
return 0 ;
}
static int F_20 ( struct V_26 * V_26 , struct V_27 * V_28 )
{
struct V_7 * V_7 = F_21 ( V_26 ) ;
unsigned int V_29 = V_28 -> V_30 ;
int V_16 = 0 ;
V_16 = F_22 ( V_7 , V_28 ) ;
if ( V_16 )
return V_16 ;
if ( V_28 -> V_30 & V_31 ) {
T_3 V_25 = V_7 -> V_32 ;
if ( V_28 -> V_33 != V_25 ) {
V_16 = F_17 ( V_7 , V_28 -> V_33 , V_25 ) ;
if ( V_16 < 0 || V_28 -> V_30 == V_31 )
goto V_34;
} else {
V_28 -> V_30 |= V_35 | V_36 ;
}
}
F_23 ( V_7 , V_28 ) ;
V_34:
V_28 -> V_30 = V_29 ;
return V_16 ;
}
static unsigned long F_24 ( struct V_1 * V_1 ,
unsigned long V_37 , unsigned long V_38 ,
unsigned long V_39 , unsigned long V_40 )
{
unsigned long V_41 , V_42 , V_43 , V_11 , V_16 ;
struct V_7 * V_7 = F_25 ( V_1 ) ;
struct V_12 * * V_13 = NULL , * * V_44 , * V_12 ;
T_3 V_45 ;
V_42 = ( V_38 + V_22 - 1 ) >> V_23 ;
V_45 = F_26 ( V_7 ) ;
V_16 = - V_46 ;
V_41 = ( V_45 + V_22 - 1 ) >> V_23 ;
if ( V_39 >= V_41 )
goto V_34;
if ( V_41 - V_39 < V_42 )
goto V_34;
V_13 = F_27 ( V_42 , sizeof( struct V_12 * ) , V_47 ) ;
if ( ! V_13 )
goto V_48;
V_43 = F_28 ( V_7 -> V_18 , V_39 , V_42 , V_13 ) ;
if ( V_43 != V_42 )
goto V_49;
V_44 = V_13 ;
V_12 = * V_44 ++ ;
V_12 ++ ;
for ( V_11 = V_42 ; V_11 > 1 ; V_11 -- )
if ( * V_44 ++ != V_12 ++ )
goto V_49;
V_16 = ( unsigned long ) F_11 ( V_13 [ 0 ] ) ;
V_49:
V_44 = V_13 ;
for ( V_11 = V_43 ; V_11 > 0 ; V_11 -- )
F_16 ( * V_44 ++ ) ;
V_48:
F_29 ( V_13 ) ;
V_34:
return V_16 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_50 * V_51 )
{
if ( ! ( V_51 -> V_52 & ( V_53 | V_54 ) ) )
return - V_46 ;
F_31 ( V_1 ) ;
V_51 -> V_55 = & V_56 ;
return 0 ;
}
