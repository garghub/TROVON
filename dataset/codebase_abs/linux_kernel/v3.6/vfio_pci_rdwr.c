T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_4 V_9 = * V_5 & V_10 ;
int V_11 = F_2 ( * V_5 ) ;
void T_5 * V_12 ;
T_3 V_13 = 0 ;
if ( ! F_3 ( V_8 , V_11 ) )
return - V_14 ;
if ( V_9 + V_4 > F_4 ( V_8 , V_11 ) )
return - V_14 ;
if ( ! V_2 -> V_15 [ V_11 ] ) {
int V_16 ;
V_16 = F_5 ( V_8 , 1 << V_11 , L_1 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_15 [ V_11 ] = F_6 ( V_8 , V_11 , 0 ) ;
if ( ! V_2 -> V_15 [ V_11 ] ) {
F_7 ( V_8 , 1 << V_11 ) ;
return - V_14 ;
}
}
V_12 = V_2 -> V_15 [ V_11 ] ;
while ( V_4 ) {
int V_17 ;
if ( V_4 >= 3 && ! ( V_9 % 4 ) ) {
T_6 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 4 ) )
return - V_19 ;
F_9 ( F_10 ( V_18 ) , V_12 + V_9 ) ;
} else {
V_18 = F_11 ( F_12 ( V_12 + V_9 ) ) ;
if ( F_13 ( V_3 , & V_18 , 4 ) )
return - V_19 ;
}
V_17 = 4 ;
} else if ( ( V_9 % 2 ) == 0 && V_4 >= 2 ) {
T_7 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 2 ) )
return - V_19 ;
F_14 ( F_15 ( V_18 ) , V_12 + V_9 ) ;
} else {
V_18 = F_16 ( F_17 ( V_12 + V_9 ) ) ;
if ( F_13 ( V_3 , & V_18 , 2 ) )
return - V_19 ;
}
V_17 = 2 ;
} else {
T_8 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 1 ) )
return - V_19 ;
F_18 ( V_18 , V_12 + V_9 ) ;
} else {
V_18 = F_19 ( V_12 + V_9 ) ;
if ( F_13 ( V_3 , & V_18 , 1 ) )
return - V_19 ;
}
V_17 = 1 ;
}
V_4 -= V_17 ;
V_13 += V_17 ;
V_3 += V_17 ;
V_9 += V_17 ;
}
* V_5 += V_13 ;
return V_13 ;
}
T_1 F_20 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
T_4 V_9 = * V_5 & V_10 ;
int V_11 = F_2 ( * V_5 ) ;
void T_5 * V_12 ;
T_9 V_20 ;
T_3 V_13 = 0 ;
T_3 V_21 = 0 , V_22 = 0 ;
if ( ! F_3 ( V_8 , V_11 ) )
return - V_14 ;
V_20 = F_4 ( V_8 , V_11 ) ;
if ( V_9 > V_20 )
return - V_14 ;
if ( V_9 == V_20 )
return 0 ;
if ( V_9 + V_4 > V_20 )
V_4 = V_20 - V_9 ;
if ( V_11 == V_23 ) {
V_12 = F_21 ( V_8 , & V_21 ) ;
V_22 = V_20 ;
} else {
if ( ! V_2 -> V_15 [ V_11 ] ) {
int V_16 ;
V_16 = F_5 ( V_8 , 1 << V_11 ,
L_1 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_15 [ V_11 ] = F_6 ( V_8 , V_11 , 0 ) ;
if ( ! V_2 -> V_15 [ V_11 ] ) {
F_7 ( V_8 , 1 << V_11 ) ;
return - V_14 ;
}
}
V_12 = V_2 -> V_15 [ V_11 ] ;
if ( V_11 == V_2 -> V_24 ) {
V_21 = V_2 -> V_25 ;
V_22 = V_2 -> V_25 + V_2 -> V_26 ;
}
}
if ( ! V_12 )
return - V_14 ;
while ( V_4 ) {
T_3 V_27 , V_17 ;
if ( V_9 < V_21 )
V_27 = V_21 - V_9 ;
else if ( V_9 >= V_22 )
V_27 = V_20 - V_9 ;
else
V_27 = 0 ;
if ( V_27 >= 4 && ! ( V_9 % 4 ) && ( V_4 >= 4 ) ) {
T_6 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 4 ) )
goto V_28;
F_9 ( F_10 ( V_18 ) , V_12 + V_9 ) ;
} else {
V_18 = F_11 ( F_12 ( V_12 + V_9 ) ) ;
if ( F_13 ( V_3 , & V_18 , 4 ) )
goto V_28;
}
V_17 = 4 ;
} else if ( V_27 >= 2 && ! ( V_9 % 2 ) && ( V_4 >= 2 ) ) {
T_7 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 2 ) )
goto V_28;
F_14 ( F_15 ( V_18 ) , V_12 + V_9 ) ;
} else {
V_18 = F_16 ( F_17 ( V_12 + V_9 ) ) ;
if ( F_13 ( V_3 , & V_18 , 2 ) )
goto V_28;
}
V_17 = 2 ;
} else if ( V_27 ) {
T_8 V_18 ;
if ( V_6 ) {
if ( F_8 ( & V_18 , V_3 , 1 ) )
goto V_28;
F_18 ( V_18 , V_12 + V_9 ) ;
} else {
V_18 = F_19 ( V_12 + V_9 ) ;
if ( F_13 ( V_3 , & V_18 , 1 ) )
goto V_28;
}
V_17 = 1 ;
} else {
if ( ! V_6 ) {
char V_18 = 0xFF ;
T_3 V_29 ;
for ( V_29 = 0 ; V_29 < V_22 - V_9 ; V_29 ++ ) {
if ( F_22 ( V_18 , V_3 + V_29 ) )
goto V_28;
}
}
V_17 = V_22 - V_9 ;
}
V_4 -= V_17 ;
V_13 += V_17 ;
V_3 += V_17 ;
V_9 += V_17 ;
}
* V_5 += V_13 ;
V_28:
if ( V_11 == V_23 )
F_23 ( V_8 , V_12 ) ;
return V_4 ? - V_19 : V_13 ;
}
