static struct V_1 *
F_1 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_3 == 0 )
return NULL ;
return (struct V_1 * ) V_2 -> V_4 ;
}
int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
T_1 V_9 , T_1 V_10 )
{
F_3 ( & V_6 -> V_11 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_12 = F_4 ( L_1 , V_8 , V_9 , V_10 , 0 ) ;
F_5 ( V_6 ) ;
return 0 ;
}
int F_6 ( struct V_5 * V_6 )
{
F_7 ( V_6 -> V_12 ) ;
return 0 ;
}
struct V_1 *
F_8 ( struct V_5 * V_6 , unsigned int V_13 )
{
int V_14 ;
struct V_1 * V_15 ;
struct V_1 * V_16 ;
struct V_1 * V_17 ;
T_2 V_18 ;
if ( V_13 == 0 )
return NULL ;
F_9 ( & V_6 -> V_11 ) ;
V_15 = F_10 ( V_6 -> V_12 , V_19 , & V_18 ) ;
if ( V_15 == NULL )
goto V_20;
F_11 ( V_6 , 1 ) ;
V_16 = V_15 ;
V_16 -> V_21 = V_18 ;
V_16 -> V_3 = 0x00000000 ;
V_16 -> V_4 = 0x00000000U ;
for ( V_14 = 1 ; V_14 < V_13 ; V_14 ++ ) {
V_17 = V_16 ;
V_16 = F_10 ( V_6 -> V_12 , V_19 , & V_18 ) ;
if ( V_16 == NULL )
goto V_22;
F_11 ( V_6 , 1 ) ;
V_16 -> V_21 = V_18 ;
V_16 -> V_3 = 0x00000000 ;
V_16 -> V_4 = 0x00000000U ;
V_17 -> V_3 = V_18 ;
V_17 -> V_4 = V_16 ;
}
F_12 ( & V_6 -> V_11 ) ;
return V_15 ;
V_20:
F_12 ( & V_6 -> V_11 ) ;
return NULL ;
V_22:
V_17 -> V_3 = 0x00000000U ;
F_12 ( & V_6 -> V_11 ) ;
F_13 ( V_6 , & V_15 ) ;
return NULL ;
}
void F_13 ( struct V_5 * V_6 ,
struct V_1 * * V_16 )
{
struct V_1 * V_23 ;
struct V_1 * V_24 ;
if ( V_16 == NULL )
return;
V_23 = * V_16 ;
if ( V_23 == NULL )
return;
F_9 ( & V_6 -> V_11 ) ;
while ( V_23 -> V_3 ) {
V_24 = V_23 -> V_4 ;
F_14 ( V_6 -> V_12 , V_23 , V_23 -> V_21 ) ;
F_11 ( V_6 , - 1 ) ;
V_23 = V_24 ;
}
F_14 ( V_6 -> V_12 , V_23 , V_23 -> V_21 ) ;
F_11 ( V_6 , - 1 ) ;
F_12 ( & V_6 -> V_11 ) ;
* V_16 = NULL ;
}
int
F_15 ( struct V_5 * V_6 ,
struct V_1 * V_16 ,
T_2 V_25 , unsigned int V_9 ,
T_2 V_26 , T_3 V_27 ,
T_3 V_28 )
{
int V_29 = V_9 ;
T_2 V_30 = V_25 ;
T_2 V_31 = V_26 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
while ( V_16 -> V_3 ) {
V_16 -> V_34 = V_27 | V_35 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
V_29 -= V_35 ;
V_16 = F_1 ( V_16 ) ;
V_30 += V_35 ;
V_31 += V_35 ;
}
V_16 -> V_34 = V_28 | V_29 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
return 0 ;
}
int
F_16 ( struct V_5 * V_6 ,
struct V_1 * V_16 ,
T_2 V_36 , unsigned int V_9 ,
T_2 V_37 , T_3 V_27 , T_3 V_28 ,
enum V_38 V_39 )
{
int V_29 = V_9 ;
T_2 V_30 ;
T_2 V_31 ;
if ( V_39 == V_40 ) {
V_30 = V_36 ;
V_31 = V_37 ;
} else if ( V_39 == V_41 ) {
V_30 = V_37 ;
V_31 = V_36 ;
} else {
return - V_42 ;
}
while ( V_16 -> V_3 ) {
T_1 V_43 = V_35 ;
V_16 -> V_34 = V_27 | V_35 ;
if ( V_29 < ( V_35 + V_35 / 2 ) )
V_43 = V_35 / 2 ;
V_29 -= V_43 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
V_16 = F_1 ( V_16 ) ;
if ( V_39 == V_40 )
V_30 += V_43 ;
else if ( V_39 == V_41 )
V_31 += V_43 ;
}
V_16 -> V_34 = V_28 | V_29 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
return 0 ;
}
int
F_17 ( struct V_5 * V_6 ,
struct V_1 * V_16 ,
struct V_44 * V_45 , unsigned int V_46 ,
T_2 V_37 , T_3 V_27 , T_3 V_47 ,
T_3 V_48 ,
enum V_38 V_39 , T_3 V_49 )
{
int V_14 ;
struct V_44 * V_50 ;
T_3 V_51 ;
T_2 V_30 = 0 ;
T_2 V_31 = 0 ;
T_3 V_52 ;
T_3 V_53 ;
if ( V_16 == NULL )
goto V_20;
F_9 ( & V_6 -> V_11 ) ;
if ( V_39 == V_40 )
V_31 = V_37 ;
else if ( V_39 == V_41 )
V_30 = V_37 ;
else
goto V_20;
F_18 (sgl, sg, nents, i) {
if ( F_19 ( V_50 ) ) {
V_51 = V_27 ;
} else if ( V_14 == V_46 - 1 )
V_51 = V_48 ;
else
V_51 = V_47 ? V_47 : V_48 ;
if ( V_39 == V_40 )
V_30 = F_20 ( V_50 ) ;
else
V_31 = F_20 ( V_50 ) ;
V_52 = F_21 ( V_50 ) ;
while ( V_52 ) {
T_3 V_54 ;
if ( V_52 > V_35 ) {
V_53 = V_35 ;
V_54 = V_27 ;
} else {
V_53 = V_52 ;
V_54 = V_51 ;
}
V_16 -> V_34 = V_54 | V_53 ;
V_16 -> V_32 = V_30 ;
V_16 -> V_33 = V_31 ;
if ( V_39 == V_41 )
V_31 += V_53 ;
else
V_30 += V_53 ;
F_22 ( V_16 -> V_3 & 3 ) ;
V_52 -= V_53 ;
V_16 = F_1 ( V_16 ) ;
}
}
F_12 ( & V_6 -> V_11 ) ;
return 0 ;
V_20:
F_12 ( & V_6 -> V_11 ) ;
return - V_42 ;
}
