static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
unsigned long V_6 , V_7 , V_8 ;
unsigned int V_9 , V_10 ;
int V_11 ;
V_10 = V_12 [ V_3 ] . V_13 ;
V_6 = V_10 * 1000 ;
V_9 = F_2 ( V_14 ) / 1000 ;
V_5 = F_3 ( V_15 , & V_6 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( V_15 , L_1 , V_6 ) ;
return F_6 ( V_5 ) ;
}
V_7 = F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
V_8 = F_9 ( V_16 ) ;
F_10 ( V_15 , L_2 ,
V_9 / 1000 , V_8 / 1000 ,
V_10 / 1000 , V_7 / 1000 ) ;
if ( V_10 > V_9 ) {
if ( ! F_4 ( V_17 ) ) {
V_11 = F_11 ( V_17 , V_18 [ V_3 ] , 0 ) ;
if ( V_11 ) {
F_5 ( V_15 , L_3 , V_11 ) ;
return V_11 ;
}
}
V_11 = F_11 ( V_19 , V_18 [ V_3 ] , 0 ) ;
if ( V_11 ) {
F_5 ( V_15 , L_4 , V_11 ) ;
return V_11 ;
}
V_11 = F_11 ( V_16 , V_7 , 0 ) ;
if ( V_11 ) {
F_5 ( V_15 ,
L_5 , V_11 ) ;
return V_11 ;
}
}
if ( F_12 ( L_6 ) ||
F_12 ( L_7 ) ) {
F_13 ( V_14 , ( V_9 >> 1 ) * 1000 ) ;
F_14 ( V_20 , V_21 ) ;
if ( V_6 > F_2 ( V_22 ) )
F_14 ( V_23 , V_24 ) ;
else
F_14 ( V_23 , V_22 ) ;
F_14 ( V_25 , V_23 ) ;
F_14 ( V_20 , V_25 ) ;
} else {
F_14 ( V_25 , V_22 ) ;
F_14 ( V_20 , V_25 ) ;
if ( V_6 > F_2 ( V_22 ) ) {
F_13 ( V_21 , V_10 * 1000 ) ;
F_14 ( V_20 , V_21 ) ;
}
}
V_11 = F_13 ( V_14 , V_10 * 1000 ) ;
if ( V_11 ) {
F_5 ( V_15 , L_8 , V_11 ) ;
F_11 ( V_16 , V_8 , 0 ) ;
return V_11 ;
}
if ( V_10 < V_9 ) {
V_11 = F_11 ( V_16 , V_7 , 0 ) ;
if ( V_11 ) {
F_15 ( V_15 ,
L_9 , V_11 ) ;
V_11 = 0 ;
}
V_11 = F_11 ( V_19 , V_18 [ V_3 ] , 0 ) ;
if ( V_11 ) {
F_15 ( V_15 , L_10 , V_11 ) ;
V_11 = 0 ;
}
if ( ! F_4 ( V_17 ) ) {
V_11 = F_11 ( V_17 , V_18 [ V_3 ] , 0 ) ;
if ( V_11 ) {
F_15 ( V_15 , L_11 , V_11 ) ;
V_11 = 0 ;
}
}
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_11 ;
V_2 -> V_26 = V_14 ;
V_11 = F_17 ( V_2 , V_12 , V_27 ) ;
V_2 -> V_28 = V_2 -> V_29 ;
return V_11 ;
}
static int F_18 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
struct V_4 * V_5 ;
unsigned long V_34 , V_35 ;
int V_36 , V_11 ;
const struct V_37 * V_38 ;
const T_1 * V_39 ;
T_2 V_40 , V_41 , V_42 ;
V_15 = F_19 ( 0 ) ;
if ( ! V_15 ) {
F_20 ( L_12 ) ;
return - V_43 ;
}
V_33 = F_21 ( V_15 -> V_44 ) ;
if ( ! V_33 ) {
F_5 ( V_15 , L_13 ) ;
return - V_45 ;
}
V_14 = F_22 ( V_15 , L_14 ) ;
V_21 = F_22 ( V_15 , L_15 ) ;
V_20 = F_22 ( V_15 , L_16 ) ;
V_25 = F_22 ( V_15 , L_17 ) ;
V_22 = F_22 ( V_15 , L_18 ) ;
if ( F_4 ( V_14 ) || F_4 ( V_21 ) || F_4 ( V_20 ) ||
F_4 ( V_25 ) || F_4 ( V_22 ) ) {
F_5 ( V_15 , L_19 ) ;
V_11 = - V_45 ;
goto V_46;
}
if ( F_12 ( L_6 ) ||
F_12 ( L_7 ) ) {
V_24 = F_22 ( V_15 , L_20 ) ;
V_23 = F_22 ( V_15 , L_21 ) ;
if ( F_4 ( V_24 ) || F_4 ( V_23 ) ) {
F_5 ( V_15 , L_22 ) ;
V_11 = - V_45 ;
goto V_46;
}
}
V_16 = F_23 ( V_15 , L_14 ) ;
V_17 = F_24 ( V_15 , L_23 ) ;
V_19 = F_23 ( V_15 , L_24 ) ;
if ( F_6 ( V_16 ) == - V_47 ||
F_6 ( V_19 ) == - V_47 ||
F_6 ( V_17 ) == - V_47 ) {
V_11 = - V_47 ;
F_10 ( V_15 , L_25 ) ;
goto V_48;
}
if ( F_4 ( V_16 ) || F_4 ( V_19 ) ) {
F_5 ( V_15 , L_26 ) ;
V_11 = - V_45 ;
goto V_48;
}
V_36 = F_25 ( V_15 ) ;
if ( V_36 < 0 ) {
V_11 = F_26 ( V_15 ) ;
if ( V_11 < 0 ) {
F_5 ( V_15 , L_27 , V_11 ) ;
goto V_48;
}
V_49 = true ;
V_36 = F_25 ( V_15 ) ;
if ( V_36 < 0 ) {
V_11 = V_36 ;
F_5 ( V_15 , L_28 , V_11 ) ;
goto V_50;
}
}
V_11 = F_27 ( V_15 , & V_12 ) ;
if ( V_11 ) {
F_5 ( V_15 , L_29 , V_11 ) ;
goto V_50;
}
V_18 = F_28 ( V_15 , sizeof( * V_18 ) * V_36 , V_51 ) ;
if ( V_18 == NULL ) {
V_11 = - V_52 ;
goto V_53;
}
V_38 = F_29 ( V_33 , L_30 , NULL ) ;
if ( ! V_38 || ! V_38 -> V_54 )
goto V_55;
V_40 = V_38 -> V_56 / sizeof( T_2 ) ;
if ( V_40 % 2 || ( V_40 / 2 ) < V_36 )
goto V_55;
for ( V_42 = 0 ; V_42 < V_36 ; V_42 ++ ) {
V_39 = V_38 -> V_54 ;
for ( V_41 = 0 ; V_41 < V_40 / 2 ; V_41 ++ ) {
unsigned long V_57 = F_30 ( V_39 ++ ) ;
unsigned long V_7 = F_30 ( V_39 ++ ) ;
if ( V_12 [ V_42 ] . V_13 == V_57 ) {
V_18 [ V_58 ++ ] = V_7 ;
break;
}
}
}
V_55:
if ( V_58 != V_36 ) {
F_15 ( V_15 , L_31 ) ;
for ( V_42 = 0 ; V_42 < V_36 ; V_42 ++ )
V_18 [ V_42 ] = V_59 ;
if ( V_12 [ V_36 - 1 ] . V_13 * 1000 == V_60 )
V_18 [ V_36 - 1 ] = V_61 ;
}
if ( F_31 ( V_33 , L_32 , & V_27 ) )
V_27 = V_62 ;
V_11 = F_32 ( V_19 , V_18 [ 0 ] , V_18 [ V_36 - 1 ] ) ;
if ( V_11 > 0 )
V_27 += V_11 * 1000 ;
if ( ! F_4 ( V_17 ) ) {
V_11 = F_32 ( V_17 , V_18 [ 0 ] , V_18 [ V_36 - 1 ] ) ;
if ( V_11 > 0 )
V_27 += V_11 * 1000 ;
}
V_5 = F_33 ( V_15 ,
V_12 [ 0 ] . V_13 * 1000 , true ) ;
V_34 = F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
V_5 = F_33 ( V_15 ,
V_12 [ -- V_36 ] . V_13 * 1000 , true ) ;
V_35 = F_7 ( V_5 ) ;
F_8 ( V_5 ) ;
V_11 = F_32 ( V_16 , V_34 , V_35 ) ;
if ( V_11 > 0 )
V_27 += V_11 * 1000 ;
V_11 = F_34 ( & V_63 ) ;
if ( V_11 ) {
F_5 ( V_15 , L_33 , V_11 ) ;
goto V_53;
}
F_35 ( V_33 ) ;
return 0 ;
V_53:
F_36 ( V_15 , & V_12 ) ;
V_50:
if ( V_49 )
F_37 ( V_15 ) ;
V_48:
if ( ! F_4 ( V_16 ) )
F_38 ( V_16 ) ;
if ( ! F_4 ( V_17 ) )
F_38 ( V_17 ) ;
if ( ! F_4 ( V_19 ) )
F_38 ( V_19 ) ;
V_46:
if ( ! F_4 ( V_14 ) )
F_39 ( V_14 ) ;
if ( ! F_4 ( V_21 ) )
F_39 ( V_21 ) ;
if ( ! F_4 ( V_20 ) )
F_39 ( V_20 ) ;
if ( ! F_4 ( V_25 ) )
F_39 ( V_25 ) ;
if ( ! F_4 ( V_22 ) )
F_39 ( V_22 ) ;
if ( ! F_4 ( V_24 ) )
F_39 ( V_24 ) ;
if ( ! F_4 ( V_23 ) )
F_39 ( V_23 ) ;
F_35 ( V_33 ) ;
return V_11 ;
}
static int F_40 ( struct V_30 * V_31 )
{
F_41 ( & V_63 ) ;
F_36 ( V_15 , & V_12 ) ;
if ( V_49 )
F_37 ( V_15 ) ;
F_38 ( V_16 ) ;
if ( ! F_4 ( V_17 ) )
F_38 ( V_17 ) ;
F_38 ( V_19 ) ;
F_39 ( V_14 ) ;
F_39 ( V_21 ) ;
F_39 ( V_20 ) ;
F_39 ( V_25 ) ;
F_39 ( V_22 ) ;
F_39 ( V_24 ) ;
F_39 ( V_23 ) ;
return 0 ;
}
