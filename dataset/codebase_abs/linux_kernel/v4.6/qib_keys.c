int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
T_1 V_6 ;
int V_7 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 ;
F_3 ( & V_13 -> V_15 , V_4 ) ;
if ( V_3 ) {
struct V_1 * V_16 ;
V_16 = F_4 ( V_9 -> V_17 ) ;
if ( ! V_16 ) {
F_5 ( V_2 ) ;
F_6 ( V_9 -> V_17 , V_2 ) ;
V_2 -> V_18 = 1 ;
}
goto V_19;
}
V_5 = V_13 -> V_20 ;
V_6 = V_5 ;
for (; ; ) {
if ( V_13 -> V_21 [ V_5 ] == NULL )
break;
V_5 = ( V_5 + 1 ) & ( V_13 -> V_22 - 1 ) ;
if ( V_5 == V_6 )
goto V_23;
}
V_13 -> V_20 = ( V_5 + 1 ) & ( V_13 -> V_22 - 1 ) ;
V_13 -> V_24 ++ ;
V_2 -> V_25 = ( V_5 << ( 32 - V_26 ) ) |
( ( ( ( 1 << ( 24 - V_26 ) ) - 1 ) & V_13 -> V_24 )
<< 8 ) ;
if ( V_2 -> V_25 == 0 ) {
V_2 -> V_25 |= 1 << 8 ;
V_13 -> V_24 ++ ;
}
F_5 ( V_2 ) ;
F_6 ( V_13 -> V_21 [ V_5 ] , V_2 ) ;
V_2 -> V_18 = 1 ;
V_19:
F_7 ( & V_13 -> V_15 , V_4 ) ;
V_27:
return V_7 ;
V_23:
F_7 ( & V_13 -> V_15 , V_4 ) ;
V_7 = - V_28 ;
goto V_27;
}
void F_8 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
T_1 V_25 = V_2 -> V_25 ;
T_1 V_5 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_11 ) ;
struct V_12 * V_13 = & V_9 -> V_14 ;
F_3 ( & V_13 -> V_15 , V_4 ) ;
if ( ! V_2 -> V_18 )
goto V_27;
if ( V_25 == 0 )
F_9 ( V_9 -> V_17 , NULL ) ;
else {
V_5 = V_25 >> ( 32 - V_26 ) ;
F_9 ( V_13 -> V_21 [ V_5 ] , NULL ) ;
}
F_10 ( V_2 ) ;
V_2 -> V_18 = 0 ;
V_27:
F_7 ( & V_13 -> V_15 , V_4 ) ;
}
int F_11 ( struct V_29 * V_30 , struct V_31 * V_32 ,
T_1 V_33 , T_2 V_34 , T_1 V_35 , int V_36 )
{
struct V_12 * V_13 = & F_2 ( V_30 -> V_37 . V_11 ) -> V_14 ;
struct V_1 * V_2 ;
unsigned V_6 , V_38 ;
T_3 V_39 ;
F_12 () ;
if ( V_35 == 0 ) {
struct V_40 * V_10 = F_13 ( V_30 -> V_37 . V_10 ) ;
struct V_8 * V_9 = F_2 ( V_10 -> V_41 . V_11 ) ;
if ( V_10 -> V_42 )
goto V_23;
V_2 = F_14 ( V_9 -> V_17 ) ;
if ( ! V_2 )
goto V_23;
if ( F_15 ( ! F_16 ( & V_2 -> V_43 ) ) )
goto V_23;
F_17 () ;
V_32 -> V_2 = V_2 ;
V_32 -> V_34 = ( void * ) V_34 ;
V_32 -> V_44 = V_33 ;
V_32 -> V_45 = V_33 ;
V_32 -> V_38 = 0 ;
V_32 -> V_6 = 0 ;
goto V_46;
}
V_2 = F_14 (
V_13 -> V_21 [ ( V_35 >> ( 32 - V_26 ) ) ] ) ;
if ( F_15 ( ! V_2 || V_2 -> V_25 != V_35 || V_30 -> V_37 . V_10 != V_2 -> V_10 ) )
goto V_23;
V_39 = V_34 - V_2 -> V_47 ;
if ( F_15 ( V_34 < V_2 -> V_47 || V_39 + V_33 > V_2 -> V_44 ||
( V_2 -> V_48 & V_36 ) == 0 ) )
goto V_23;
if ( F_15 ( ! F_16 ( & V_2 -> V_43 ) ) )
goto V_23;
F_17 () ;
V_39 += V_2 -> V_49 ;
if ( V_2 -> V_50 ) {
T_3 V_51 ;
V_51 = V_39 >> V_2 -> V_50 ;
V_39 -= ( V_51 << V_2 -> V_50 ) ;
V_38 = V_51 / V_52 ;
V_6 = V_51 % V_52 ;
} else {
V_38 = 0 ;
V_6 = 0 ;
while ( V_39 >= V_2 -> V_53 [ V_38 ] -> V_54 [ V_6 ] . V_44 ) {
V_39 -= V_2 -> V_53 [ V_38 ] -> V_54 [ V_6 ] . V_44 ;
V_6 ++ ;
if ( V_6 >= V_52 ) {
V_38 ++ ;
V_6 = 0 ;
}
}
}
V_32 -> V_2 = V_2 ;
V_32 -> V_34 = V_2 -> V_53 [ V_38 ] -> V_54 [ V_6 ] . V_34 + V_39 ;
V_32 -> V_44 = V_2 -> V_53 [ V_38 ] -> V_54 [ V_6 ] . V_44 - V_39 ;
V_32 -> V_45 = V_33 ;
V_32 -> V_38 = V_38 ;
V_32 -> V_6 = V_6 ;
V_46:
return 1 ;
V_23:
F_17 () ;
return 0 ;
}
