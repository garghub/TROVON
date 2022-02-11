void F_1 ( int V_1 , T_1 V_2 )
{
int V_3 = V_1 - V_4 ;
F_2 ( V_1 < V_4 || V_1 > V_5 ) ;
F_3 ( & V_6 ) ;
F_2 ( V_7 [ V_3 ] ) ;
V_7 [ V_3 ] = V_2 ;
F_4 ( & V_6 ) ;
}
void F_5 ( int V_1 , T_1 V_2 )
{
int V_3 = V_1 - V_4 ;
F_2 ( V_1 < V_4 || V_1 > V_5 ) ;
F_3 ( & V_6 ) ;
F_2 ( V_7 [ V_3 ] != V_2 ) ;
V_7 [ V_3 ] = NULL ;
F_4 ( & V_6 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 ) {
F_7 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
}
}
void F_8 ( struct V_8 * V_9 , void * V_11 ,
unsigned long V_12 )
{
unsigned long V_13 ;
while ( V_12 ) {
if ( ! V_9 -> V_10 )
V_9 -> V_10 = F_9 ( * V_9 -> V_14 ) ;
V_13 = F_10 ( V_12 , V_15 - V_9 -> V_3 ) ;
F_11 ( L_1
L_2 , * V_9 -> V_14 , V_9 -> V_10 ,
V_9 -> V_3 , V_13 , V_11 , V_12 ) ;
memcpy ( V_9 -> V_10 + V_9 -> V_3 , V_11 , V_13 ) ;
V_11 += V_13 ;
V_12 -= V_13 ;
V_9 -> V_3 += V_13 ;
if ( V_9 -> V_3 == V_15 ) {
F_7 ( V_9 -> V_10 ) ;
V_9 -> V_10 = NULL ;
V_9 -> V_3 = 0 ;
V_9 -> V_14 ++ ;
}
}
}
int F_12 ( struct V_16 * V_17 , int V_1 , char T_2 * V_18 ,
int T_2 * V_19 )
{
struct V_8 V_9 ;
struct V_20 V_21 ;
unsigned long V_22 = 0 ;
unsigned long V_23 ;
unsigned long V_24 ;
T_1 V_2 ;
struct V_25 * * V_14 = NULL ;
int V_26 ;
int V_27 ;
int V_28 ;
if ( F_13 ( V_27 , V_19 ) ) {
V_26 = - V_29 ;
goto V_30;
}
V_23 = ( unsigned long ) V_18 ;
if ( V_27 < 0 || V_27 > V_31 - V_15 + 1 || V_23 + V_27 < V_23 ) {
V_26 = - V_32 ;
goto V_30;
}
if ( V_27 == 0 )
goto V_33;
V_22 = ( F_14 ( V_23 + V_27 ) - ( V_23 & V_34 ) )
>> V_35 ;
V_14 = F_15 ( V_22 * sizeof( struct V_25 * ) , V_36 ) ;
if ( ! V_14 ) {
V_26 = - V_37 ;
goto V_30;
}
V_26 = F_16 ( V_23 , V_22 , 1 , V_14 ) ;
if ( V_26 != V_22 ) {
if ( V_26 > 0 )
V_22 = V_26 ;
else
V_22 = 0 ;
V_26 = - V_38 ;
goto V_30;
}
F_11 ( L_3 , V_27 , V_22 ) ;
V_33:
V_2 = V_7 [ V_1 - V_4 ] ;
if ( ! V_2 ) {
V_26 = - V_39 ;
goto V_30;
}
V_9 . V_14 = V_14 ;
V_9 . V_10 = NULL ;
V_9 . V_3 = V_23 & ( V_15 - 1 ) ;
V_2 ( V_17 , V_27 , & V_9 , & V_21 ) ;
F_2 ( V_21 . V_40 == 0 ) ;
V_28 = V_21 . V_41 * V_21 . V_40 ;
F_6 ( & V_9 ) ;
if ( V_28 > V_27 ) {
V_27 = V_28 ;
V_26 = - V_42 ;
} else {
V_27 = V_28 ;
V_26 = V_21 . V_40 ;
}
if ( F_17 ( V_27 , V_19 ) )
V_26 = - V_29 ;
V_30:
for ( V_24 = 0 ; V_14 && V_24 < V_22 ; V_24 ++ )
F_18 ( V_14 [ V_24 ] ) ;
F_19 ( V_14 ) ;
return V_26 ;
}
