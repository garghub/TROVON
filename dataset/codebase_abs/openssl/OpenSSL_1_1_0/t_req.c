int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
int V_4 ;
if ( ( V_3 = F_2 ( F_3 () ) ) == NULL ) {
F_4 ( V_5 , V_6 ) ;
return ( 0 ) ;
}
F_5 ( V_3 , V_1 , V_7 ) ;
V_4 = F_6 ( V_3 , V_2 ) ;
F_7 ( V_3 ) ;
return ( V_4 ) ;
}
int F_8 ( T_3 * V_8 , T_2 * V_2 , unsigned long V_9 ,
unsigned long V_10 )
{
long V_11 ;
int V_12 ;
T_4 * V_13 ;
F_9 ( V_14 ) * V_15 ;
char V_16 = ' ' ;
int V_17 = 0 ;
if ( ( V_9 & V_18 ) == V_19 ) {
V_16 = '\n' ;
V_17 = 12 ;
}
if ( V_9 == V_20 )
V_17 = 16 ;
if ( ! ( V_10 & V_21 ) ) {
if ( F_10 ( V_8 , L_1 , 21 ) <= 0 )
goto V_22;
if ( F_10 ( V_8 , L_2 , 10 ) <= 0 )
goto V_22;
}
if ( ! ( V_10 & V_23 ) ) {
V_11 = F_11 ( V_2 ) ;
if ( F_12 ( V_8 , L_3 , L_4 , V_11 + 1 , V_11 ) <= 0 )
goto V_22;
}
if ( ! ( V_10 & V_24 ) ) {
if ( F_12 ( V_8 , L_5 , V_16 ) <= 0 )
goto V_22;
if ( F_13 ( V_8 , F_14 ( V_2 ) ,
V_17 , V_9 ) < 0 )
goto V_22;
if ( F_10 ( V_8 , L_6 , 1 ) <= 0 )
goto V_22;
}
if ( ! ( V_10 & V_25 ) ) {
T_5 * V_26 ;
T_6 * V_27 ;
if ( F_10 ( V_8 , L_7 , 33 ) <= 0 )
goto V_22;
if ( F_12 ( V_8 , L_8 , L_4 ) <= 0 )
goto V_22;
V_26 = F_15 ( V_2 ) ;
F_16 ( & V_27 , NULL , NULL , NULL , V_26 ) ;
if ( F_17 ( V_8 , V_27 ) <= 0 )
goto V_22;
if ( F_18 ( V_8 , L_6 ) <= 0 )
goto V_22;
V_13 = F_19 ( V_2 ) ;
if ( V_13 == NULL ) {
F_12 ( V_8 , L_9 , L_4 ) ;
F_20 ( V_8 ) ;
} else {
F_21 ( V_8 , V_13 , 16 , NULL ) ;
}
}
if ( ! ( V_10 & V_28 ) ) {
if ( F_12 ( V_8 , L_10 , L_4 ) <= 0 )
goto V_22;
if ( F_22 ( V_2 ) == 0 ) {
if ( F_12 ( V_8 , L_11 , L_4 ) <= 0 )
goto V_22;
} else {
for ( V_12 = 0 ; V_12 < F_22 ( V_2 ) ; V_12 ++ ) {
T_7 * V_29 ;
T_8 * V_30 ;
T_9 * V_31 = NULL ;
T_6 * V_32 ;
int V_33 , type = 0 , V_34 = 1 , V_35 = 0 ;
V_30 = F_23 ( V_2 , V_12 ) ;
V_32 = F_24 ( V_30 ) ;
if ( F_25 ( F_26 ( V_32 ) ) )
continue;
if ( F_12 ( V_8 , L_12 , L_4 ) <= 0 )
goto V_22;
if ( ( V_33 = F_17 ( V_8 , V_32 ) ) > 0 ) {
V_35 = 0 ;
V_34 = F_27 ( V_30 ) ;
V_36:
V_29 = F_28 ( V_30 , V_35 ) ;
type = V_29 -> type ;
V_31 = V_29 -> V_37 . V_38 ;
}
for ( V_33 = 25 - V_33 ; V_33 > 0 ; V_33 -- )
if ( F_10 ( V_8 , L_13 , 1 ) != 1 )
goto V_22;
if ( F_18 ( V_8 , L_14 ) <= 0 )
goto V_22;
if ( ( type == V_39 ) ||
( type == V_40 ) ||
( type == V_41 ) ||
( type == V_42 ) ) {
if ( F_10 ( V_8 , ( char * ) V_31 -> V_43 , V_31 -> V_44 )
!= V_31 -> V_44 )
goto V_22;
F_18 ( V_8 , L_6 ) ;
} else {
F_18 ( V_8 , L_15 ) ;
}
if ( ++ V_35 < V_34 )
goto V_36;
}
}
}
if ( ! ( V_10 & V_45 ) ) {
V_15 = F_29 ( V_2 ) ;
if ( V_15 ) {
F_12 ( V_8 , L_16 , L_4 ) ;
for ( V_12 = 0 ; V_12 < F_30 ( V_15 ) ; V_12 ++ ) {
T_6 * V_46 ;
V_14 * V_47 ;
int V_48 ;
V_47 = F_31 ( V_15 , V_12 ) ;
if ( F_12 ( V_8 , L_12 , L_4 ) <= 0 )
goto V_22;
V_46 = F_32 ( V_47 ) ;
F_17 ( V_8 , V_46 ) ;
V_48 = F_33 ( V_47 ) ;
if ( F_12 ( V_8 , L_17 , V_48 ? L_18 : L_4 ) <= 0 )
goto V_22;
if ( ! F_34 ( V_8 , V_47 , V_10 , 16 ) ) {
F_12 ( V_8 , L_19 , L_4 ) ;
F_35 ( V_8 , F_36 ( V_47 ) ) ;
}
if ( F_10 ( V_8 , L_6 , 1 ) <= 0 )
goto V_22;
}
F_37 ( V_15 , V_49 ) ;
}
}
if ( ! ( V_10 & V_50 ) ) {
const T_10 * V_51 ;
const T_9 * V_52 ;
F_38 ( V_2 , & V_52 , & V_51 ) ;
if ( ! F_39 ( V_8 , V_51 , V_52 ) )
goto V_22;
}
return ( 1 ) ;
V_22:
F_4 ( V_53 , V_6 ) ;
return ( 0 ) ;
}
int F_6 ( T_3 * V_8 , T_2 * V_2 )
{
return F_8 ( V_8 , V_2 , V_54 , V_20 ) ;
}
