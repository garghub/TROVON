T_1 F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
if ( V_4 > V_2 -> V_5 )
V_4 = V_2 -> V_5 ;
if ( F_2 ( F_3 ( V_2 -> V_6 , V_2 -> V_7 , V_3 , V_4 ) ) )
return 0 ;
V_2 -> V_5 -= V_4 ;
V_2 -> V_7 += V_4 ;
return V_4 ;
}
static T_1 F_4 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
unsigned int V_8 ;
T_2 V_9 ;
if ( V_4 > V_2 -> V_5 )
V_4 = V_2 -> V_5 ;
V_8 = V_2 -> V_7 ;
V_9 = F_5 ( V_2 -> V_6 , V_8 , V_3 , V_4 , 0 ) ;
V_2 -> V_10 = F_6 ( V_2 -> V_10 , V_9 , V_8 ) ;
V_2 -> V_5 -= V_4 ;
V_2 -> V_7 += V_4 ;
return V_4 ;
}
T_3 F_7 ( struct V_11 * V_12 , unsigned int V_13 , struct V_1 * V_2 , T_4 V_14 )
{
struct V_15 * * V_16 = V_12 -> V_17 ;
unsigned int V_4 , V_18 = V_12 -> V_19 ;
T_3 V_20 = 0 ;
T_1 V_21 ;
V_4 = V_12 -> V_22 [ 0 ] . V_23 ;
if ( V_13 < V_4 ) {
V_4 -= V_13 ;
V_21 = V_14 ( V_2 , ( char * ) V_12 -> V_22 [ 0 ] . V_24 + V_13 , V_4 ) ;
V_20 += V_21 ;
if ( V_21 != V_4 || ! V_2 -> V_5 )
goto V_25;
V_13 = 0 ;
} else
V_13 -= V_4 ;
if ( F_2 ( V_18 == 0 ) )
goto V_26;
if ( F_2 ( V_13 >= V_18 ) ) {
V_13 -= V_18 ;
goto V_26;
}
if ( V_13 || V_12 -> V_27 ) {
V_18 -= V_13 ;
V_13 += V_12 -> V_27 ;
V_16 += V_13 >> V_28 ;
V_13 &= ~ V_29 ;
}
do {
char * V_30 ;
if ( F_2 ( * V_16 == NULL ) ) {
* V_16 = F_8 ( V_31 ) ;
if ( F_2 ( * V_16 == NULL ) ) {
if ( V_20 == 0 )
V_20 = - V_32 ;
goto V_25;
}
}
V_4 = V_33 ;
V_30 = F_9 ( * V_16 ) ;
if ( V_13 ) {
V_4 -= V_13 ;
if ( V_18 < V_4 )
V_4 = V_18 ;
V_21 = V_14 ( V_2 , V_30 + V_13 , V_4 ) ;
V_13 = 0 ;
} else {
if ( V_18 < V_4 )
V_4 = V_18 ;
V_21 = V_14 ( V_2 , V_30 , V_4 ) ;
}
F_10 ( * V_16 ) ;
F_11 ( V_30 ) ;
V_20 += V_21 ;
if ( V_21 != V_4 || ! V_2 -> V_5 )
goto V_25;
V_16 ++ ;
} while ( ( V_18 -= V_4 ) != 0 );
V_26:
V_4 = V_12 -> V_34 [ 0 ] . V_23 ;
if ( V_13 < V_4 )
V_20 += V_14 ( V_2 , ( char * ) V_12 -> V_34 [ 0 ] . V_24 + V_13 , V_4 - V_13 ) ;
V_25:
return V_20 ;
}
int F_12 ( struct V_11 * V_12 , struct V_35 * V_6 )
{
struct V_1 V_2 ;
V_2 . V_6 = V_6 ;
V_2 . V_7 = sizeof( struct V_36 ) ;
V_2 . V_5 = V_6 -> V_4 - V_2 . V_7 ;
if ( F_13 ( V_6 ) )
goto V_37;
V_2 . V_10 = F_14 ( V_6 -> V_38 , V_2 . V_7 , V_6 -> V_10 ) ;
if ( F_7 ( V_12 , 0 , & V_2 , F_4 ) < 0 )
return - 1 ;
if ( V_2 . V_7 != V_6 -> V_4 ) {
T_2 V_9 ;
V_9 = F_15 ( V_6 , V_2 . V_7 , V_6 -> V_4 - V_2 . V_7 , 0 ) ;
V_2 . V_10 = F_6 ( V_2 . V_10 , V_9 , V_2 . V_7 ) ;
}
if ( V_2 . V_5 )
return - 1 ;
if ( F_16 ( V_2 . V_10 ) )
return - 1 ;
if ( F_2 ( V_6 -> V_39 == V_40 ) )
F_17 ( V_6 -> V_41 ) ;
return 0 ;
V_37:
if ( F_7 ( V_12 , 0 , & V_2 , F_1 ) < 0 )
return - 1 ;
if ( V_2 . V_5 )
return - 1 ;
return 0 ;
}
