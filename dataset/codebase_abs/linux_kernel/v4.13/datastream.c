struct V_1 *
F_1 ( struct V_2 * V_3 , const T_1 * V_4 ,
T_2 V_5 , T_3 * V_6 )
{
struct V_1 * V_7 ;
T_4 V_8 ;
T_5 V_9 ;
F_2 ( V_3 , L_1 , V_10 , V_5 ) ;
V_9 = V_5 >> F_3 ( V_3 ) -> V_11 ;
if ( V_6 )
* V_6 = V_5 - ( V_9 << F_3 ( V_3 ) -> V_11 ) ;
if ( F_4 ( V_3 , V_4 , V_9 , & V_8 ) != V_12 ) {
F_5 ( V_3 , L_2 ,
( unsigned long ) V_9 ) ;
F_2 ( V_3 , L_3 , V_10 ) ;
return NULL ;
}
V_7 = F_6 ( V_3 , V_8 ) ;
if ( ! V_7 ) {
F_5 ( V_3 , L_4 ,
( unsigned long ) V_9 ) ;
return NULL ;
}
F_2 ( V_3 , L_5 , V_10 , V_5 ) ;
return V_7 ;
}
int
F_4 ( struct V_2 * V_3 , const T_1 * V_13 ,
T_5 V_14 , T_4 * V_8 )
{
int V_15 ;
T_2 V_5 = V_14 << F_3 ( V_3 ) -> V_11 ;
if ( V_5 < V_13 -> V_16 ) {
V_15 = F_7 ( V_3 , V_13 , V_14 , V_8 ) ;
} else if ( V_5 < V_13 -> V_17 ) {
V_15 = F_8 ( V_3 , V_13 , V_14 , V_8 ) ;
} else if ( V_5 < V_13 -> V_18 ) {
V_15 = F_9 ( V_3 , V_13 , V_14 , V_8 ) ;
} else {
F_5 ( V_3 ,
L_6
L_7 ,
( unsigned long ) V_14 ) ;
V_15 = V_19 ;
}
return V_15 ;
}
T_6
F_10 ( struct V_2 * V_3 , const T_1 * V_4 ,
void * V_20 , T_2 V_21 )
{
T_2 V_22 = 0 ;
T_7 V_23 ;
struct V_1 * V_7 ;
F_2 ( V_3 , L_8 , V_10 , V_21 ) ;
while ( V_22 < V_21 ) {
V_7 = F_1 ( V_3 , V_4 , V_22 , NULL ) ;
if ( ! V_7 ) {
F_5 ( V_3 , L_9
L_10 , V_22 ) ;
F_2 ( V_3 , L_3 , V_10 ) ;
return V_22 ;
}
V_23 = ( ( V_22 + F_3 ( V_3 ) -> V_24 ) < V_21 ) ?
F_3 ( V_3 ) -> V_24 : V_21 - V_22 ;
memcpy ( V_20 + V_22 , V_7 -> V_25 , V_23 ) ;
F_11 ( V_7 ) ;
V_22 += V_23 ;
}
F_2 ( V_3 , L_11 , V_10 , ( unsigned int )
V_22 ) ;
return V_22 ;
}
T_5
F_12 ( struct V_2 * V_3 , const T_1 * V_4 )
{
T_5 V_26 ;
T_5 V_27 ;
T_5 V_28 ;
struct V_29 * V_30 = F_3 ( V_3 ) ;
F_2 ( V_3 , L_12 , V_10 ) ;
V_27 = V_4 -> V_31 >> V_30 -> V_11 ;
if ( V_4 -> V_31 & ( V_30 -> V_24 - 1 ) )
V_27 += 1 ;
V_28 = 1 ;
if ( V_4 -> V_31 > V_4 -> V_16 )
V_28 += V_4 -> V_32 . V_21 ;
if ( V_4 -> V_31 > V_4 -> V_17 && V_4 -> V_17 != 0 ) {
T_3 V_33 ;
T_3 V_34 ;
T_3 V_35 ;
V_33 =
V_4 -> V_18 - V_4 -> V_17 ;
V_34 =
V_33 / ( V_30 -> V_24 * V_36 ) ;
V_35 = V_34 / F_13 ( V_3 ) ;
V_28 += V_4 -> V_37 . V_21 ;
V_28 += V_35 ;
}
V_26 = V_27 + V_28 ;
F_2 ( V_3 , L_13 , V_10 , ( unsigned int ) V_26 ) ;
return V_26 ;
}
static int
F_7 ( struct V_2 * V_3 , const T_1 * V_13 ,
T_5 V_38 , T_4 * V_8 )
{
int V_39 ;
const T_4 * V_40 = V_13 -> V_41 ;
T_5 V_42 ;
F_2 ( V_3 , L_14 , V_10 , ( unsigned long ) V_38 ) ;
for ( V_39 = 0 , V_42 = 0 ; V_39 < V_43 ;
V_42 += V_40 [ V_39 ] . V_21 , V_39 ++ ) {
if ( V_38 >= V_42 && V_38 < V_42 + ( V_40 [ V_39 ] . V_21 ) ) {
int V_44 = V_38 - V_42 ;
V_8 -> V_45 = V_40 [ V_39 ] . V_45 ;
V_8 -> V_46 = V_40 [ V_39 ] . V_46 + V_44 ;
V_8 -> V_21 = V_40 [ V_39 ] . V_21 - V_44 ;
F_2 ( V_3 , L_15
L_16 , V_10 ,
( unsigned long ) V_38 , V_39 ) ;
return V_12 ;
}
}
F_5 ( V_3 , L_17 , V_10 ,
( unsigned long ) V_38 ) ;
F_2 ( V_3 , L_18 , V_10 ) ;
return V_19 ;
}
static int
F_8 ( struct V_2 * V_3 ,
const T_1 * V_13 ,
T_5 V_38 ,
T_4 * V_8 )
{
int V_39 , V_47 ;
T_5 V_42 = 0 ;
T_5 V_48 ;
T_5 V_49 ;
struct V_1 * V_50 ;
T_8 * V_40 ;
T_4 V_32 = V_13 -> V_32 ;
T_5 V_51 = F_14 ( V_3 , & V_32 ) ;
int V_52 = F_13 ( V_3 ) ;
F_2 ( V_3 , L_14 , V_10 , ( unsigned long ) V_38 ) ;
V_48 = V_13 -> V_16 >> F_3 ( V_3 ) -> V_11 ;
V_49 = V_38 - V_48 ;
for ( V_39 = 0 ; V_39 < V_32 . V_21 ; V_39 ++ ) {
V_50 = F_15 ( V_3 , V_51 + V_39 ) ;
if ( V_50 == NULL ) {
F_5 ( V_3 , L_19
L_20 ,
V_10 , ( unsigned long ) V_51 + V_39 ) ;
F_2 ( V_3 , L_3 , V_10 ) ;
return V_19 ;
}
V_40 = ( T_8 * ) V_50 -> V_25 ;
for ( V_47 = 0 ; V_47 < V_52 ; ++ V_47 ) {
int V_21 = F_16 ( V_3 , V_40 [ V_47 ] . V_21 ) ;
if ( V_49 >= V_42 && V_49 < V_42 + V_21 ) {
int V_44 = V_49 - V_42 ;
V_8 -> V_45 =
F_17 ( V_3 , V_40 [ V_47 ] . V_45 ) ;
V_8 -> V_46 =
F_16 ( V_3 , V_40 [ V_47 ] . V_46 ) + V_44 ;
V_8 -> V_21 =
F_16 ( V_3 , V_40 [ V_47 ] . V_21 ) - V_44 ;
F_11 ( V_50 ) ;
F_2 ( V_3 ,
L_21
L_22 , V_10 ,
( unsigned long ) V_38 ,
V_47 + ( V_39 * V_52 ) ) ;
return V_12 ;
}
V_42 += V_21 ;
}
F_11 ( V_50 ) ;
}
F_5 ( V_3 , L_23
L_24 , V_10 , ( unsigned long ) V_38 ) ;
F_2 ( V_3 , L_3 , V_10 ) ;
return V_19 ;
}
static int
F_9 ( struct V_2 * V_3 ,
const T_1 * V_13 ,
T_5 V_38 ,
T_4 * V_8 )
{
int V_53 ;
int V_54 ;
int V_44 ;
int V_55 ;
int V_56 ;
int V_57 ;
int V_58 ;
T_9 V_59 ;
T_5 V_60 ;
struct V_1 * V_61 ;
struct V_1 * V_62 ;
T_4 V_63 ;
T_10 * V_64 ;
T_5 V_48 =
V_13 -> V_17 >> F_3 ( V_3 ) -> V_11 ;
T_9 V_65 = V_38 - V_48 ;
T_6 V_66 = V_36 ;
T_6 V_67 = V_66 * F_13 ( V_3 )
* V_36 ;
F_2 ( V_3 , L_25 , V_10 , ( unsigned long ) V_38 ) ;
V_53 = V_65 / V_67 ;
V_59 = V_65 % V_67 ;
V_54 = V_59 / V_67 ;
V_55 = V_53 / F_13 ( V_3 ) ;
if ( V_55 > V_13 -> V_37 . V_21 ) {
F_5 ( V_3 , L_26
L_27
L_28 , V_10 ,
V_53 ) ;
return V_19 ;
}
V_61 =
F_15 ( V_3 , F_14 ( V_3 , & V_13 -> V_37 ) +
V_55 ) ;
if ( V_61 == NULL ) {
F_5 ( V_3 , L_29
L_30 , V_10 ,
( unsigned long )
F_14 ( V_3 , & V_13 -> V_37 ) +
V_55 ) ;
return V_19 ;
}
V_57 =
V_53 - ( V_55 * F_13 ( V_3 ) ) ;
V_64 = ( T_10 * ) V_61 -> V_25 ;
V_63 = F_18 ( V_3 , V_64 [ V_57 ] ) ;
F_11 ( V_61 ) ;
V_56 = V_54 / F_13 ( V_3 ) ;
if ( V_56 > V_63 . V_21 ) {
F_5 ( V_3 , L_31
L_27
L_32 , V_10 , V_54 ) ;
return V_19 ;
}
V_62 =
F_15 ( V_3 , F_14 ( V_3 , & V_63 ) + V_56 ) ;
if ( V_62 == NULL ) {
F_5 ( V_3 , L_33
L_34 , V_10 , ( unsigned long )
F_14 ( V_3 , & V_63 ) + V_56 ) ;
return V_19 ;
}
V_58 = V_54 - ( V_56 * F_13 ( V_3 ) ) ;
V_64 = ( T_10 * ) V_62 -> V_25 ;
* V_8 = F_18 ( V_3 , V_64 [ V_58 ] ) ;
F_11 ( V_62 ) ;
V_60 = V_48 ;
V_60 += V_67 * V_53 ;
V_60 += V_66 * V_54 ;
V_44 = V_38 - V_60 ;
V_8 -> V_46 += V_44 ;
V_8 -> V_21 -= V_44 ;
F_2 ( V_3 , L_35
L_36 , ( unsigned long )
V_38 , V_53 , V_54 , V_59 ) ;
return V_12 ;
}
