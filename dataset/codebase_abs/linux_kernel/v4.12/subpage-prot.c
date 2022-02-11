void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
unsigned long V_6 , V_7 , V_8 ;
T_1 * * V_9 ;
for ( V_6 = 0 ; V_6 < 4 ; ++ V_6 ) {
if ( V_4 -> V_10 [ V_6 ] ) {
F_2 ( ( unsigned long ) V_4 -> V_10 [ V_6 ] ) ;
V_4 -> V_10 [ V_6 ] = NULL ;
}
}
V_8 = 0 ;
for ( V_6 = 0 ; V_6 < 2 ; ++ V_6 ) {
V_9 = V_4 -> V_11 [ V_6 ] ;
if ( ! V_9 )
continue;
V_4 -> V_11 [ V_6 ] = NULL ;
for ( V_7 = 0 ; V_7 < V_12 && V_8 < V_4 -> V_13 ;
++ V_7 , V_8 += V_14 )
if ( V_9 [ V_7 ] )
F_2 ( ( unsigned long ) V_9 [ V_7 ] ) ;
F_2 ( ( unsigned long ) V_9 ) ;
}
V_4 -> V_13 = 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned long V_8 ,
int V_15 )
{
T_2 * V_16 ;
T_3 * V_17 ;
T_4 * V_18 ;
T_5 * V_19 ;
T_6 * V_20 ;
V_16 = F_5 ( V_2 , V_8 ) ;
if ( F_6 ( * V_16 ) )
return;
V_17 = F_7 ( V_16 , V_8 ) ;
if ( F_8 ( * V_17 ) )
return;
V_18 = F_9 ( V_17 , V_8 ) ;
if ( F_10 ( * V_18 ) )
return;
V_19 = F_11 ( V_2 , V_18 , V_8 , & V_20 ) ;
F_12 () ;
for (; V_15 > 0 ; -- V_15 ) {
F_13 ( V_2 , V_8 , V_19 , 0 , 0 , 0 ) ;
V_8 += V_14 ;
++ V_19 ;
}
F_14 () ;
F_15 ( V_19 - 1 , V_20 ) ;
}
static void F_16 ( unsigned long V_8 , unsigned long V_21 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
T_1 * * V_23 , * V_24 ;
unsigned long V_6 ;
T_7 V_25 ;
unsigned long V_26 , V_27 ;
F_17 ( & V_2 -> V_28 ) ;
V_27 = V_8 + V_21 ;
if ( V_27 > V_4 -> V_13 )
V_27 = V_4 -> V_13 ;
for (; V_8 < V_27 ; V_8 = V_26 ) {
V_26 = F_18 ( V_8 , V_27 ) ;
if ( V_8 < 0x100000000UL ) {
V_23 = V_4 -> V_10 ;
} else {
V_23 = V_4 -> V_11 [ V_8 >> V_29 ] ;
if ( ! V_23 )
continue;
}
V_24 = V_23 [ ( V_8 >> V_30 ) & ( V_12 - 1 ) ] ;
if ( ! V_24 )
continue;
V_24 += ( V_8 >> V_31 ) & ( V_32 - 1 ) ;
V_6 = ( V_8 >> V_31 ) & ( V_33 - 1 ) ;
V_25 = V_33 - V_6 ;
if ( V_8 + ( V_25 << V_31 ) > V_26 )
V_25 = ( V_26 - V_8 ) >> V_31 ;
memset ( V_24 , 0 , V_25 * sizeof( T_1 ) ) ;
F_4 ( V_2 , V_8 , V_25 ) ;
}
F_19 ( & V_2 -> V_28 ) ;
}
static int F_20 ( T_4 * V_18 , unsigned long V_8 ,
unsigned long V_34 , struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
F_21 ( V_38 , V_18 , V_8 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_21 )
{
struct V_37 * V_38 ;
struct V_35 V_39 = {
. V_2 = V_2 ,
. V_40 = F_20 ,
} ;
V_38 = F_23 ( V_2 , V_8 ) ;
if ( V_38 && ( ( V_8 + V_21 ) <= V_38 -> V_41 ) )
return;
while ( V_38 ) {
if ( V_38 -> V_41 >= ( V_8 + V_21 ) )
break;
V_38 -> V_42 |= V_43 ;
F_24 ( V_38 , & V_39 ) ;
V_38 = V_38 -> V_44 ;
}
}
static void F_22 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_21 )
{
return;
}
long F_25 ( unsigned long V_8 , unsigned long V_21 , T_1 T_8 * V_45 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
T_1 * * V_23 , * V_24 ;
unsigned long V_6 ;
T_7 V_25 ;
unsigned long V_26 , V_27 ;
int V_46 ;
if ( ( V_8 & ~ V_47 ) || ( V_21 & ~ V_47 ) ||
V_8 >= V_2 -> V_48 || V_21 >= V_2 -> V_48 ||
V_8 + V_21 > V_2 -> V_48 )
return - V_49 ;
if ( F_26 ( V_2 , V_8 , V_21 ) )
return - V_49 ;
if ( ! V_45 ) {
F_16 ( V_8 , V_21 ) ;
return 0 ;
}
if ( ! F_27 ( V_50 , V_45 , ( V_21 >> V_31 ) * sizeof( T_1 ) ) )
return - V_51 ;
F_17 ( & V_2 -> V_28 ) ;
F_22 ( V_2 , V_8 , V_21 ) ;
for ( V_27 = V_8 + V_21 ; V_8 < V_27 ; V_8 = V_26 ) {
V_26 = F_18 ( V_8 , V_27 ) ;
V_46 = - V_52 ;
if ( V_8 < 0x100000000UL ) {
V_23 = V_4 -> V_10 ;
} else {
V_23 = V_4 -> V_11 [ V_8 >> V_29 ] ;
if ( ! V_23 ) {
V_23 = ( T_1 * * ) F_28 ( V_53 ) ;
if ( ! V_23 )
goto V_54;
V_4 -> V_11 [ V_8 >> V_29 ] = V_23 ;
}
}
V_23 += ( V_8 >> V_30 ) & ( V_12 - 1 ) ;
V_24 = * V_23 ;
if ( ! V_24 ) {
V_24 = ( T_1 * ) F_28 ( V_53 ) ;
if ( ! V_24 )
goto V_54;
* V_23 = V_24 ;
}
V_24 += ( V_8 >> V_31 ) & ( V_32 - 1 ) ;
F_29 () ;
F_30 ( V_2 , V_8 ) ;
F_31 () ;
V_6 = ( V_8 >> V_31 ) & ( V_33 - 1 ) ;
V_25 = V_33 - V_6 ;
if ( V_8 + ( V_25 << V_31 ) > V_26 )
V_25 = ( V_26 - V_8 ) >> V_31 ;
F_19 ( & V_2 -> V_28 ) ;
if ( F_32 ( V_24 , V_45 , V_25 * sizeof( T_1 ) ) )
return - V_51 ;
V_45 += V_25 ;
F_17 ( & V_2 -> V_28 ) ;
F_4 ( V_2 , V_8 , V_25 ) ;
}
if ( V_27 > V_4 -> V_13 )
V_4 -> V_13 = V_27 ;
V_46 = 0 ;
V_54:
F_19 ( & V_2 -> V_28 ) ;
return V_46 ;
}
