static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
F_2 ( V_1 , V_4 , V_2 ,
V_5 + V_3 , 1 , V_6 ) ;
F_2 ( V_1 , V_7 , V_2 ,
V_8 + V_3 , 1 , V_6 ) ;
}
static void
F_3 ( T_1 * V_9 , T_2 * V_2 , int V_3 )
{
F_4 ( V_9 , V_2 , V_10 + V_3 ,
V_11 , V_12 , V_13 , V_6 ) ;
}
static T_3
F_5 ( T_1 * V_9 , T_2 * V_2 , T_3 V_14 , T_4 V_15 )
{
T_3 V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; ) {
T_5 V_17 ;
T_5 V_18 [ 3 ] ;
V_17 = F_6 ( V_2 , V_14 ) ;
V_18 [ 0 ] = V_17 / 36 ;
V_17 -= 36 * V_18 [ 0 ] ;
V_18 [ 1 ] = V_17 / 6 ;
V_17 -= 6 * V_18 [ 1 ] ;
V_18 [ 2 ] = V_17 ;
F_7 ( V_9 , V_19 , V_2 , V_14 , sizeof( T_5 ) ,
V_18 [ 0 ] ) ;
V_16 ++ ;
if ( V_16 < V_15 ) {
F_7 ( V_9 , V_19 , V_2 , V_14 , sizeof( T_5 ) ,
V_18 [ 1 ] ) ;
V_16 ++ ;
}
if ( V_16 < V_15 ) {
F_7 ( V_9 , V_19 , V_2 , V_14 , sizeof( T_5 ) ,
V_18 [ 2 ] ) ;
V_16 ++ ;
}
V_14 ++ ;
}
return ( V_14 ) ;
}
static int
F_8 ( T_2 * V_2 , T_6 * V_20 , T_1 * V_21 , void * T_7 V_22 ) {
T_8 * V_23 , * V_24 , * V_25 , * V_26 ;
T_1 * V_27 , * V_1 , * V_28 , * V_9 ;
F_9 ( V_20 -> V_29 , V_30 , L_1 ) ;
F_9 ( V_20 -> V_29 , V_31 , L_2 ) ;
if ( V_21 ) {
T_5 V_32 ;
T_5 V_33 ;
T_4 V_15 ;
T_3 V_14 = 0 ;
int V_34 ;
int V_3 ;
int V_35 ;
V_23 = F_2 ( V_21 , V_36 , V_2 , 0 , - 1 , V_37 ) ;
V_27 = F_10 ( V_23 , V_38 ) ;
F_2 ( V_27 , V_39 , V_2 , V_40 , 1 , V_6 ) ;
V_3 = 0 ;
while ( F_11 ( V_2 , V_5 + V_3 ) != V_41 ) {
V_32 = F_6 ( V_2 , V_5 + V_3 ) ;
V_33 = F_6 ( V_2 , V_8 + V_3 ) ;
V_24 = F_2 ( V_27 , V_42 , V_2 ,
V_43 + V_3 ,
- 1 , V_37 ) ;
V_1 = F_10 ( V_24 , V_44 ) ;
F_12 ( V_1 , L_3 ,
F_13 ( V_32 , V_45 , L_4 ) ,
V_32 ) ;
F_1 ( V_1 , V_2 , V_3 ) ;
V_25 = F_2 ( V_1 , V_46 , V_2 ,
V_47 + V_3 ,
- 1 , V_37 ) ;
V_28 = F_10 ( V_25 , V_48 ) ;
V_35 = 0 ;
while ( F_11 ( V_2 , V_10 + V_3 + V_35 ) != V_41 ) {
V_15 = F_11 ( V_2 , V_49 + V_3 + V_35 )
& V_50 ;
V_34 = 2 + V_33 + ( V_15 + 2 ) / 3 ;
V_26 = F_2 ( V_28 , V_51 , V_2 ,
V_52 + V_3 + V_35 ,
V_34 , V_37 ) ;
V_9 = F_10 ( V_26 , V_53 ) ;
F_3 ( V_9 , V_2 , V_3 + V_35 ) ;
if ( V_32 == V_54 ) {
F_2 ( V_9 , V_55 , V_2 ,
V_56 + V_3 + V_35 ,
V_33 , V_37 ) ;
V_14 = F_5 ( V_9 , V_2 ,
V_57 + V_3 + V_35 ,
V_15 ) ;
}
else if ( V_32 == V_58 ) {
F_2 ( V_9 , V_55 , V_2 ,
V_56 + V_3 + V_35 ,
V_33 , V_37 ) ;
V_14 = F_5 ( V_9 , V_2 ,
V_57 + V_3 + V_35 ,
V_15 ) ;
}
V_35 += V_34 ;
}
F_2 ( V_28 , V_59 , V_2 , V_14 , 2 , V_6 ) ;
F_14 ( V_25 , V_35 ) ;
V_3 += V_35 + 2 ;
F_14 ( V_24 , V_35 + 2 ) ;
}
F_2 ( V_27 , V_59 , V_2 , V_14 + 2 , 2 , V_6 ) ;
}
return F_15 ( V_2 ) ;
}
void
F_16 ( void )
{
static T_9 V_60 [] = {
{ & V_39 ,
{ L_5 , L_6 ,
V_61 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_42 ,
{ L_7 , L_8 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_4 ,
{ L_9 , L_10 ,
V_61 , V_62 , F_17 ( V_45 ) , 0x0 , NULL , V_63 }
} ,
{ & V_7 ,
{ L_11 , L_12 ,
V_61 , V_62 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_46 ,
{ L_13 , L_14 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_51 ,
{ L_15 , L_16 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_11 ,
{ L_17 , L_18 ,
V_66 , V_67 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_68 ,
{ L_19 , L_20 ,
V_66 , V_62 , F_17 ( V_69 ) , V_70 , NULL , V_63 }
} ,
{ & V_71 ,
{ L_21 , L_22 ,
V_66 , V_62 , NULL , V_50 , NULL , V_63 }
} ,
{ & V_55 ,
{ L_23 , L_24 ,
V_64 , V_65 , NULL , 0x0 , NULL , V_63 }
} ,
{ & V_19 ,
{ L_25 , L_26 ,
V_61 , V_62 , F_17 ( V_72 ) , 0x0 , NULL , V_63 }
} ,
{ & V_59 ,
{ L_27 , L_28 ,
V_66 , V_67 , NULL , 0x0 , NULL , V_63 }
} ,
} ;
static T_10 * V_73 [] = {
& V_38 ,
& V_44 ,
& V_48 ,
& V_53 ,
& V_12 ,
& V_74
} ;
V_36 = F_18 ( L_2 ,
L_1 , L_29 ) ;
F_19 ( V_36 , V_60 , F_20 ( V_60 ) ) ;
F_21 ( V_73 , F_20 ( V_73 ) ) ;
}
void
F_22 ( void )
{
T_11 V_75 ;
V_75 = F_23 ( F_8 , V_36 ) ;
F_24 ( L_30 , V_76 , V_75 ) ;
}
