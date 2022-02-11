static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
F_2 ( V_2 , V_6 , F_3 ( V_3 ) ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ )
V_4 [ V_5 ] = ( T_1 ) F_4 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_6 , V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 , void * V_12 )
{
T_1 V_13 [ V_7 ] ;
T_1 V_14 ;
T_1 V_15 ;
T_1 V_16 ;
T_1 V_17 ;
if ( V_11 == 0 )
return 0 ;
V_14 = V_10 + V_11 ;
if ( V_14 > ( 1 << V_18 ) )
return - V_19 ;
V_15 = V_10 & V_20 ;
if ( V_15 ) {
V_16 = V_10 & ~ V_20 ;
F_1 ( V_2 , V_16 , V_13 ) ;
V_17 = V_21 - V_15 ;
if ( V_11 <= V_17 ) {
memcpy ( V_12 , ( V_22 * ) V_13 + V_15 , V_11 ) ;
return 0 ;
}
memcpy ( V_12 , ( V_22 * ) V_13 + V_15 , V_17 ) ;
V_10 += V_17 ;
V_11 -= V_17 ;
V_12 += V_17 ;
}
while ( V_11 >= V_21 ) {
F_1 ( V_2 , V_10 , V_13 ) ;
memcpy ( V_12 , V_13 , V_21 ) ;
V_10 += V_21 ;
V_11 -= V_21 ;
V_12 += V_21 ;
}
if ( V_11 ) {
F_1 ( V_2 , V_10 , V_13 ) ;
memcpy ( V_12 , V_13 , V_11 ) ;
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
if ( V_2 -> V_24 -> V_25 != V_26 )
return 0 ;
V_23 = F_7 ( V_2 , V_27 , V_28 ) ;
if ( V_23 ) {
F_8 ( V_2 ,
L_1 ,
V_29 ) ;
goto V_30;
}
F_2 ( V_2 , V_31 , V_32 ) ;
F_2 ( V_2 , V_31 ,
V_33 << V_34 ) ;
F_2 ( V_2 , V_6 , V_35 ) ;
V_2 -> V_36 = true ;
F_9 ( V_2 , V_27 ) ;
V_30:
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 , void * * V_37 ,
T_1 * V_38 )
{
void * V_13 ;
void * V_39 ;
T_1 V_40 ;
int V_23 ;
V_13 = F_11 ( V_41 , V_42 ) ;
if ( ! V_13 )
return - V_43 ;
V_23 = F_5 ( V_2 , V_44 , V_41 , V_13 ) ;
if ( V_23 ) {
F_12 ( V_13 ) ;
return V_23 ;
}
V_39 = F_13 ( V_13 , V_45 , V_41 ) ;
if ( V_39 )
V_40 = V_39 - V_13 ;
else
V_40 = V_41 ;
* V_37 = V_13 ;
* V_38 = V_40 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
void * V_46 , void * * V_37 , T_1 * V_38 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_49 * V_51 ;
void * V_13 = NULL ;
void * V_52 = NULL ;
int V_23 , V_5 ;
T_1 V_53 ;
T_1 V_54 , V_55 ;
T_1 V_56 , V_57 , V_58 ;
V_48 = (struct V_47 * )
( V_46 + V_21 - sizeof( * V_48 ) ) ;
if ( V_48 -> V_59 != V_60 )
return - V_19 ;
if ( V_48 -> V_61 >= V_62 )
return - V_19 ;
if ( V_48 -> V_63 >
F_15 ( V_62 - V_48 -> V_61 ) )
return - V_19 ;
V_53 = F_16 ( V_48 -> V_63 ) ;
if ( V_53 <= V_21 ) {
V_50 = (struct V_49 * )
( V_46 + V_21 - V_53 ) ;
} else {
V_52 = F_11 ( V_53 , V_42 ) ;
if ( ! V_52 )
return - V_43 ;
V_23 = F_5 ( V_2 , V_62 - V_53 ,
V_53 , V_52 ) ;
if ( V_23 )
goto V_64;
V_50 = V_52 ;
}
for ( V_51 = NULL , V_5 = 0 ; V_5 < V_48 -> V_63 ; V_5 ++ ) {
if ( V_50 [ V_5 ] . type == V_65 ) {
V_51 = & V_50 [ V_5 ] ;
break;
}
}
if ( ! V_51 ) {
V_23 = - V_66 ;
goto V_64;
}
if ( V_51 -> V_38 > ( 4 * 1024 ) ) {
F_8 ( V_2 , L_2 ,
V_51 -> V_38 ) ;
V_23 = - V_19 ;
goto V_64;
}
if ( V_51 -> V_3 + V_51 -> V_38 < V_51 -> V_3 ) {
F_8 ( V_2 ,
L_3 ,
V_51 -> V_3 , V_51 -> V_38 ) ;
V_23 = - V_19 ;
goto V_64;
}
V_13 = F_11 ( V_51 -> V_38 , V_42 ) ;
if ( ! V_13 ) {
V_23 = - V_43 ;
goto V_64;
}
V_55 = V_51 -> V_3 % V_62 ;
V_54 = V_51 -> V_3 - V_55 ;
V_57 = 0 ;
while ( V_57 < V_51 -> V_38 ) {
V_56 = V_62 - V_55 ;
if ( V_54 == 0 ) {
if ( V_56 <= V_53 ) {
F_8 ( V_2 ,
L_4 ,
V_51 -> V_3 ) ;
V_23 = - V_19 ;
goto V_64;
}
V_56 -= V_53 ;
}
V_58 = V_51 -> V_38 - V_57 ;
if ( V_58 > V_56 )
V_58 = V_56 ;
V_23 = F_5 ( V_2 , V_54 + V_55 , V_58 ,
V_13 + V_57 ) ;
if ( V_23 )
goto V_64;
V_57 += V_58 ;
V_55 = V_48 -> V_61 ;
V_54 += V_62 ;
}
V_23 = 0 ;
* V_37 = V_13 ;
* V_38 = V_51 -> V_38 ;
V_64:
F_12 ( V_52 ) ;
if ( V_23 )
F_12 ( V_13 ) ;
return V_23 ;
}
int F_17 ( struct V_1 * V_2 , void * * V_37 , T_1 * V_38 )
{
T_1 V_46 [ V_7 ] ;
int V_23 ;
if ( ! V_2 -> V_36 )
return - V_67 ;
V_23 = F_7 ( V_2 , V_27 , V_28 ) ;
if ( V_23 )
return - V_68 ;
V_23 = F_5 ( V_2 , V_62 - V_21 , V_21 , V_46 ) ;
if ( V_23 )
goto V_64;
if ( V_46 [ V_7 - 1 ] == V_69 ) {
V_23 = F_14 ( V_2 , V_46 , V_37 , V_38 ) ;
} else {
V_23 = F_10 ( V_2 , V_37 , V_38 ) ;
}
V_64:
F_9 ( V_2 , V_27 ) ;
return V_23 ;
}
