static T_1 F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
T_5 V_4 ;
int V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < V_6 ) {
return V_5 ;
}
V_4 = F_3 ( V_2 , V_3 + 2 ) ;
return V_6 + V_4 ;
}
static T_1 F_4 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
int V_7 = V_3 ;
int V_8 = V_3 + V_6 + V_9 ;
int V_10 ;
while ( V_10 = F_2 ( V_2 , V_3 ) , V_10 > 0 ) {
T_5 V_4 = 0 ;
int V_11 ;
T_5 V_12 ;
T_6 V_13 ;
T_7 V_14 ;
int V_15 = V_3 + V_6 ;
V_8 = V_15 + V_9 ;
if ( V_10 < V_6 ) {
return V_8 - V_7 ;
}
V_4 = F_1 ( T_3 , V_2 , V_3 ) ;
V_8 = V_3 + V_4 ;
if ( V_10 < V_4 ) {
return V_8 - V_7 ;
}
V_12 = F_3 ( V_2 , V_15 + 0 ) ;
V_13 = F_5 ( V_2 , V_15 + 2 ) ;
if ( V_3 == V_7 && ! F_6 ( V_13 ) ) {
return V_8 - V_7 ;
}
if ( F_6 ( V_13 ) ) {
V_11 = ( ( V_12 & 0x2000 ) ? 128 : 8 ) ;
if ( V_11 == 8 ) {
V_14 = V_13 & V_16 ;
} else {
V_14 = F_5 ( V_2 , V_15 + 3 ) & V_17 ;
}
if ( ! V_14 ) {
return V_8 - V_7 ;
}
}
V_3 = V_8 ;
V_8 += V_6 + V_9 ;
}
T_3 -> V_18 = V_19 ;
return V_8 - V_7 ;
}
static int F_7 ( T_4 * V_2 , T_2 * T_3 , T_8 * V_20 , void * T_9 V_1 )
{
int V_3 = 0 ;
T_5 V_21 ;
T_5 V_4 ;
T_6 V_13 ;
T_10 * V_22 = NULL ;
T_8 * V_23 = NULL ;
T_4 * V_24 ;
F_8 ( T_3 -> V_25 , V_26 , L_1 ) ;
V_21 = F_3 ( V_2 , V_3 + 0 ) ;
V_4 = F_3 ( V_2 , V_3 + 2 ) ;
F_9 ( T_3 -> V_25 , V_27 , L_2 ,
V_21 , V_4 ) ;
if ( V_3 == 0 &&
F_2 ( V_2 , V_3 ) > V_6 + V_4 )
F_10 ( T_3 -> V_25 , V_27 , L_3 ,
F_2 ( V_2 , V_3 ) ) ;
if ( V_20 ) {
V_22 = F_11 ( V_20 , V_28 , V_2 , V_3 , V_6 ,
L_4 ) ;
V_23 = F_12 ( V_22 , V_29 ) ;
F_13 ( V_23 , V_30 , V_2 , V_3 , 2 , V_21 ) ;
F_13 ( V_23 , V_31 , V_2 , V_3 + 2 , 2 , V_4 ) ;
}
V_3 += V_6 ;
if ( V_4 >= V_9 ) {
V_13 = F_5 ( V_2 , V_3 + 2 ) ;
if ( V_13 == V_32 ) {
T_1 V_33 , V_34 , V_35 ;
T_11 V_36 = V_3 ;
F_8 ( T_3 -> V_25 , V_27 , L_5 ) ;
F_14 ( V_22 , V_6 + V_4 ) ;
F_15 ( V_23 , V_37 , V_2 , V_36 , 2 , V_38 ) ;
F_15 ( V_23 , V_39 , V_2 , V_36 , 2 , V_38 ) ;
V_36 += 2 ;
F_15 ( V_23 , V_40 , V_2 , V_36 , 1 , V_38 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_41 , V_2 , V_36 , 1 , V_38 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_42 , V_2 , V_36 , 1 , V_38 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_43 , V_2 , V_36 , 1 , V_38 ) ;
V_33 = F_5 ( V_2 , V_36 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_44 , V_2 , V_36 , 2 , V_38 ) ;
V_36 += 2 ;
F_15 ( V_23 , V_45 , V_2 , V_36 , 1 , V_38 ) ;
V_34 = F_5 ( V_2 , V_36 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_46 , V_2 , V_36 , 2 , V_38 ) ;
V_36 += 2 ;
F_15 ( V_23 , V_47 , V_2 , V_36 , 1 , V_38 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_48 , V_2 , V_36 , 1 , V_38 ) ;
V_36 += 1 ;
V_35 = 1 << F_5 ( V_2 , V_36 ) ;
F_13 ( V_23 , V_49 , V_2 , V_36 , 1 , V_35 ) ;
V_36 += 1 ;
V_35 = 1 << F_5 ( V_2 , V_36 ) ;
F_13 ( V_23 , V_50 , V_2 , V_36 , 1 , V_35 ) ;
V_36 += 1 ;
F_15 ( V_23 , V_51 , V_2 , V_36 , V_33 , V_52 | V_53 ) ;
V_36 += V_33 ;
F_15 ( V_23 , V_54 , V_2 , V_36 , V_34 , V_52 | V_53 ) ;
} else {
V_24 = F_16 ( V_2 , V_3 ,
F_17 ( V_4 , F_2 ( V_2 , V_3 ) ) , V_4 ) ;
F_18 ( V_55 , V_24 , T_3 , V_20 ) ;
}
}
return F_19 ( V_2 ) ;
}
static int F_20 ( T_4 * V_2 , T_2 * T_3 , T_8 * V_20 , void * T_9 )
{
int V_3 = 0 ;
int V_56 = F_4 ( T_3 , V_2 , V_3 ) ;
T_4 * V_24 ;
int V_57 = V_3 + F_17 ( V_56 , F_2 ( V_2 , V_3 ) ) ;
T_10 * V_22 ;
T_8 * V_23 ;
if ( V_20 ) {
V_22 = F_11 ( V_20 , V_28 , V_2 , V_3 , V_57 - V_3 ,
L_6 ) ;
V_23 = F_12 ( V_22 , V_29 ) ;
F_13 ( V_23 , V_31 , V_2 , V_3 , V_57 , V_56 ) ;
}
while ( V_3 <= V_57 - V_6 ) {
int V_4 = F_1 ( T_3 , V_2 , V_3 ) ;
V_24 = F_16 ( V_2 , V_3 , V_4 , V_4 ) ;
F_7 ( V_24 , T_3 , V_20 , T_9 ) ;
V_3 += V_4 ;
}
return F_19 ( V_2 ) ;
}
static int F_21 ( T_4 * V_2 , T_2 * T_3 , T_8 * V_20 , void * T_9 )
{
int V_10 = F_19 ( V_2 ) ;
int V_56 = 0 ;
if ( V_10 >= 2 && F_3 ( V_2 , 0 ) != V_58 ) {
return 0 ;
}
if ( ! V_59 || ! V_60 ) {
F_22 ( V_2 , T_3 , V_20 , V_60 ,
V_6 ,
F_1 ,
F_7 , T_9 ) ;
V_56 = F_1 ( T_3 , V_2 , 0 ) ;
} else {
F_22 ( V_2 , T_3 , V_20 , V_60 ,
V_6 ,
F_4 ,
F_20 , T_9 ) ;
V_56 = F_4 ( T_3 , V_2 , 0 ) ;
}
if ( V_56 < V_6 ) {
V_56 = 0 ;
} else if ( V_10 < V_6 ) {
T_3 -> V_18 = V_19 ;
V_56 = V_10 - V_6 ;
} else if ( V_10 < V_56 ) {
if ( V_59 ) {
T_3 -> V_18 = V_19 ;
} else {
T_3 -> V_18 = V_56 - V_10 ;
}
V_56 = V_10 - V_56 ;
}
return V_56 ;
}
void
F_23 ( void )
{
static T_12 V_61 [] = {
{ & V_30 ,
{ L_7 , L_8 , V_62 , V_63 ,
NULL , 0 , L_9 , V_64 } } ,
{ & V_31 ,
{ L_10 , L_11 , V_62 , V_63 ,
NULL , 0 , L_12 , V_64 } } ,
{ & V_37 ,
{ L_13 , L_14 , V_62 , V_63 ,
NULL , 0xF000 , L_15 , V_64 } } ,
{ & V_39 ,
{ L_16 , L_17 , V_62 , V_63 ,
NULL , 0x0FFF , L_18 , V_64 } } ,
{ & V_40 ,
{ L_19 , L_20 , V_65 , V_66 ,
F_24 ( V_67 ) , 0x0 , NULL , V_64 } } ,
{ & V_41 ,
{ L_7 , L_21 , V_65 , V_66 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_42 ,
{ L_22 , L_23 , V_65 , V_66 ,
F_24 ( V_68 ) , 0 , NULL , V_64 } } ,
{ & V_43 ,
{ L_24 , L_25 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_44 ,
{ L_26 , L_27 , V_65 , V_63 ,
NULL , 0 , L_28 , V_64 } } ,
{ & V_45 ,
{ L_29 , L_30 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_46 ,
{ L_31 , L_32 , V_62 , V_63 ,
NULL , 0 , L_33 , V_64 } } ,
{ & V_47 ,
{ L_34 , L_35 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_48 ,
{ L_36 , L_37 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_49 ,
{ L_38 , L_39 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_50 ,
{ L_40 , L_41 , V_65 , V_63 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_51 ,
{ L_42 , L_43 , V_69 , V_70 ,
NULL , 0 , NULL , V_64 } } ,
{ & V_54 ,
{ L_44 , L_45 , V_69 , V_70 ,
NULL , 0 , NULL , V_64 } }
} ;
static T_11 * V_71 [] = {
& V_29
} ;
T_13 * V_72 ;
V_28 = F_25 ( L_4 , L_1 , L_46 ) ;
F_26 ( V_28 , V_61 , F_27 ( V_61 ) ) ;
F_28 ( V_71 , F_27 ( V_71 ) ) ;
V_73 = F_29 ( L_46 , F_21 , V_28 ) ;
V_72 = F_30 ( V_28 , NULL ) ;
F_31 ( V_72 , L_47 ,
L_48 ,
L_49
L_50 ,
& V_60 ) ;
F_31 ( V_72 , L_51 ,
L_52 ,
L_53
L_54
L_55 ,
& V_59 ) ;
}
void
F_32 ( void )
{
F_33 ( L_56 , V_74 , V_73 ) ;
V_55 = F_34 ( L_57 ) ;
}
