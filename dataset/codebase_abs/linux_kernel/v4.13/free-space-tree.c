void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 , V_6 ;
V_3 = V_2 -> V_7 -> V_8 * V_9 ;
V_5 = F_2 ( V_2 -> V_10 . V_11 + V_3 - 1 ,
V_3 ) ;
V_4 = sizeof( struct V_12 ) + V_13 ;
V_6 = V_5 * V_4 ;
V_2 -> V_14 = F_2 ( V_6 ,
sizeof( struct V_12 ) ) ;
if ( V_2 -> V_14 > 100 )
V_2 -> V_15 = V_2 -> V_14 - 100 ;
else
V_2 -> V_15 = 0 ;
}
static int F_3 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_10 ;
struct V_28 * V_29 ;
int V_30 ;
V_10 . V_31 = V_19 -> V_10 . V_31 ;
V_10 . type = V_32 ;
V_10 . V_11 = V_19 -> V_10 . V_11 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , sizeof( * V_26 ) ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_26 = F_5 ( V_29 , V_21 -> V_35 [ 0 ] ,
struct V_25 ) ;
F_6 ( V_29 , V_26 , 0 ) ;
F_7 ( V_29 , V_26 , 0 ) ;
F_8 ( V_29 ) ;
V_30 = 0 ;
V_33:
F_9 ( V_21 ) ;
return V_30 ;
}
struct V_25 *
F_10 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , int V_36 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 ;
int V_30 ;
V_10 . V_31 = V_19 -> V_10 . V_31 ;
V_10 . type = V_32 ;
V_10 . V_11 = V_19 -> V_10 . V_11 ;
V_30 = F_11 ( V_17 , V_23 , & V_10 , V_21 , 0 , V_36 ) ;
if ( V_30 < 0 )
return F_12 ( V_30 ) ;
if ( V_30 != 0 ) {
F_13 ( V_7 , L_1 ,
V_19 -> V_10 . V_31 ) ;
ASSERT ( 0 ) ;
return F_12 ( - V_37 ) ;
}
return F_5 ( V_21 -> V_34 [ 0 ] , V_21 -> V_35 [ 0 ] ,
struct V_25 ) ;
}
static int F_14 ( struct V_16 * V_17 ,
struct V_22 * V_23 ,
struct V_27 * V_10 , struct V_20 * V_38 ,
int V_39 , int V_36 )
{
int V_30 ;
V_30 = F_11 ( V_17 , V_23 , V_10 , V_38 , V_39 , V_36 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_30 == 0 ) {
ASSERT ( 0 ) ;
return - V_40 ;
}
if ( V_38 -> V_35 [ 0 ] == 0 ) {
ASSERT ( 0 ) ;
return - V_40 ;
}
V_38 -> V_35 [ 0 ] -- ;
return 0 ;
}
static inline T_1 F_15 ( T_3 V_41 , T_1 V_8 )
{
return F_16 ( ( T_1 ) F_2 ( V_41 , V_8 ) , V_42 ) ;
}
static T_4 * F_17 ( T_1 V_4 )
{
T_4 * V_30 ;
unsigned int V_43 ;
V_43 = F_18 () ;
V_30 = F_19 ( V_4 , V_44 ) ;
F_20 ( V_43 ) ;
return V_30 ;
}
int F_21 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_10 , V_45 ;
struct V_28 * V_29 ;
T_4 * V_46 , * V_47 ;
T_3 V_48 , V_49 ;
T_3 V_3 , V_50 ;
T_1 V_4 , V_51 , V_52 ;
T_1 V_53 = 0 ;
int V_54 = 0 , V_55 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_10 . V_11 ,
V_7 -> V_8 ) ;
V_46 = F_17 ( V_4 ) ;
if ( ! V_46 ) {
V_30 = - V_56 ;
goto V_33;
}
V_48 = V_19 -> V_10 . V_31 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_49 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_54 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_55 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_22 ( V_29 , & V_45 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_45 . type == V_32 ) {
ASSERT ( V_45 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_45 . V_11 == V_19 -> V_10 . V_11 ) ;
V_54 = 1 ;
break;
} else if ( V_45 . type == V_57 ) {
T_3 V_58 , V_59 ;
ASSERT ( V_45 . V_31 >= V_48 ) ;
ASSERT ( V_45 . V_31 < V_49 ) ;
ASSERT ( V_45 . V_31 + V_45 . V_11 <= V_49 ) ;
V_58 = F_2 ( V_45 . V_31 - V_48 ,
V_7 -> V_8 ) ;
V_59 = F_2 ( V_45 . V_31 + V_45 . V_11 - V_48 ,
V_7 -> V_8 ) ;
F_23 ( V_46 , V_58 , V_59 - V_58 ) ;
V_53 ++ ;
V_55 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_24 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_55 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_25 ( V_26 ) ) {
V_30 = F_26 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_51 = F_27 ( V_29 , V_26 ) ;
V_51 |= V_60 ;
F_7 ( V_29 , V_26 , V_51 ) ;
V_52 = F_28 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
if ( V_53 != V_52 ) {
F_29 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_53 ,
V_52 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_47 = V_46 ;
V_3 = V_7 -> V_8 * V_9 ;
V_50 = V_48 ;
while ( V_50 < V_49 ) {
unsigned long V_61 ;
T_3 V_62 ;
T_1 V_63 ;
V_62 = F_30 ( V_49 - V_50 , V_3 ) ;
V_63 = F_15 ( V_62 ,
V_7 -> V_8 ) ;
V_10 . V_31 = V_50 ;
V_10 . type = V_64 ;
V_10 . V_11 = V_62 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 ,
V_63 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_61 = F_31 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
F_32 ( V_29 , V_47 , V_61 ,
V_63 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_50 += V_62 ;
V_47 += V_63 ;
}
V_30 = 0 ;
V_33:
F_33 ( V_46 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
int F_35 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_10 , V_45 ;
struct V_28 * V_29 ;
T_4 * V_46 ;
T_3 V_48 , V_49 ;
T_3 V_65 = 0 ;
T_3 V_11 ;
T_1 V_4 , V_51 , V_52 ;
int V_66 = 0 , V_67 , V_68 ;
T_1 V_53 = 0 ;
int V_54 = 0 , V_55 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_10 . V_11 ,
V_7 -> V_8 ) ;
V_46 = F_17 ( V_4 ) ;
if ( ! V_46 ) {
V_30 = - V_56 ;
goto V_33;
}
V_48 = V_19 -> V_10 . V_31 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_49 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_54 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_55 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_22 ( V_29 , & V_45 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_45 . type == V_32 ) {
ASSERT ( V_45 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_45 . V_11 == V_19 -> V_10 . V_11 ) ;
V_54 = 1 ;
break;
} else if ( V_45 . type == V_64 ) {
unsigned long V_61 ;
T_4 * V_47 ;
T_1 V_69 , V_63 ;
ASSERT ( V_45 . V_31 >= V_48 ) ;
ASSERT ( V_45 . V_31 < V_49 ) ;
ASSERT ( V_45 . V_31 + V_45 . V_11 <= V_49 ) ;
V_69 = F_2 ( V_45 . V_31 - V_48 ,
V_7 -> V_8 *
V_42 ) ;
V_47 = V_46 + V_69 ;
V_63 = F_15 ( V_45 . V_11 ,
V_7 -> V_8 ) ;
V_61 = F_31 ( V_29 , V_21 -> V_35 [ 0 ] - 1 ) ;
F_36 ( V_29 , V_47 , V_61 ,
V_63 ) ;
V_55 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_24 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_55 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_25 ( V_26 ) ) {
V_30 = F_26 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_51 = F_27 ( V_29 , V_26 ) ;
V_51 &= ~ V_60 ;
F_7 ( V_29 , V_26 , V_51 ) ;
V_52 = F_28 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_11 = V_48 ;
V_68 = 0 ;
while ( V_11 < V_49 ) {
V_67 = ! ! F_37 ( V_68 , V_46 ) ;
if ( V_66 == 0 && V_67 == 1 ) {
V_65 = V_11 ;
} else if ( V_66 == 1 && V_67 == 0 ) {
V_10 . V_31 = V_65 ;
V_10 . type = V_57 ;
V_10 . V_11 = V_11 - V_65 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_53 ++ ;
}
V_66 = V_67 ;
V_11 += V_7 -> V_8 ;
V_68 ++ ;
}
if ( V_66 == 1 ) {
V_10 . V_31 = V_65 ;
V_10 . type = V_57 ;
V_10 . V_11 = V_49 - V_65 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_53 ++ ;
}
if ( V_53 != V_52 ) {
F_29 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_53 ,
V_52 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_30 = 0 ;
V_33:
F_33 ( V_46 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_38 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
int V_70 )
{
struct V_25 * V_26 ;
T_1 V_51 ;
T_1 V_53 ;
int V_30 = 0 ;
if ( V_70 == 0 )
return 0 ;
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_25 ( V_26 ) ) {
V_30 = F_26 ( V_26 ) ;
goto V_33;
}
V_51 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_53 = F_28 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_53 += V_70 ;
F_6 ( V_21 -> V_34 [ 0 ] , V_26 , V_53 ) ;
F_8 ( V_21 -> V_34 [ 0 ] ) ;
F_9 ( V_21 ) ;
if ( ! ( V_51 & V_60 ) &&
V_53 > V_19 -> V_14 ) {
V_30 = F_21 ( V_17 , V_7 , V_19 ,
V_21 ) ;
} else if ( ( V_51 & V_60 ) &&
V_53 < V_19 -> V_15 ) {
V_30 = F_35 ( V_17 , V_7 , V_19 ,
V_21 ) ;
}
V_33:
return V_30 ;
}
int F_39 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_11 )
{
struct V_28 * V_29 ;
struct V_27 V_10 ;
T_3 V_71 , V_72 ;
unsigned long V_61 , V_50 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_22 ( V_29 , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_64 ) ;
V_71 = V_10 . V_31 ;
V_72 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_11 >= V_71 && V_11 < V_72 ) ;
V_61 = F_31 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_50 = F_2 ( V_11 - V_71 ,
V_19 -> V_7 -> V_8 ) ;
return ! ! F_40 ( V_29 , V_61 , V_50 ) ;
}
static void F_41 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 * V_48 , T_3 * V_41 ,
int V_67 )
{
struct V_18 * V_7 = V_19 -> V_7 ;
struct V_28 * V_29 ;
struct V_27 V_10 ;
T_3 V_49 = * V_48 + * V_41 ;
T_3 V_71 , V_72 ;
unsigned long V_61 , V_58 , V_59 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_22 ( V_29 , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_64 ) ;
V_71 = V_10 . V_31 ;
V_72 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( * V_48 >= V_71 && * V_48 < V_72 ) ;
ASSERT ( V_49 > V_71 ) ;
if ( V_49 > V_72 )
V_49 = V_72 ;
V_61 = F_31 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_58 = F_2 ( * V_48 - V_71 , V_7 -> V_8 ) ;
V_59 = F_2 ( V_49 - V_71 , V_7 -> V_8 ) ;
if ( V_67 )
F_42 ( V_29 , V_61 , V_58 , V_59 - V_58 ) ;
else
F_43 ( V_29 , V_61 , V_58 , V_59 - V_58 ) ;
F_8 ( V_29 ) ;
* V_41 -= V_49 - * V_48 ;
* V_48 = V_49 ;
}
static int F_44 ( struct V_16 * V_17 ,
struct V_22 * V_23 , struct V_20 * V_38 )
{
struct V_27 V_10 ;
if ( V_38 -> V_35 [ 0 ] + 1 < F_45 ( V_38 -> V_34 [ 0 ] ) ) {
V_38 -> V_35 [ 0 ] ++ ;
return 0 ;
}
F_22 ( V_38 -> V_34 [ 0 ] , & V_10 , V_38 -> V_35 [ 0 ] ) ;
F_9 ( V_38 ) ;
V_10 . V_31 += V_10 . V_11 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
return F_14 ( V_17 , V_23 , & V_10 , V_38 , 0 , 1 ) ;
}
static int F_46 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_48 , T_3 V_41 , int remove )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 ;
T_3 V_49 = V_48 + V_41 ;
T_3 V_73 , V_74 ;
int V_66 , V_75 ;
int V_70 ;
int V_30 ;
if ( V_48 > V_19 -> V_10 . V_31 ) {
T_3 V_76 = V_48 - V_19 -> V_7 -> V_8 ;
V_10 . V_31 = V_76 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_66 = F_39 ( V_19 , V_21 , V_76 ) ;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_48 >= V_10 . V_31 + V_10 . V_11 ) {
V_30 = F_44 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
} else {
V_10 . V_31 = V_48 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_66 = - 1 ;
}
V_73 = V_48 ;
V_74 = V_41 ;
while ( 1 ) {
F_41 ( V_19 , V_21 , & V_73 , & V_74 ,
! remove ) ;
if ( V_74 == 0 )
break;
V_30 = F_44 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
if ( V_49 < V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ) {
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_49 >= V_10 . V_31 + V_10 . V_11 ) {
V_30 = F_44 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
V_75 = F_39 ( V_19 , V_21 , V_49 ) ;
} else {
V_75 = - 1 ;
}
if ( remove ) {
V_70 = - 1 ;
if ( V_66 == 1 ) {
V_70 ++ ;
}
if ( V_75 == 1 ) {
V_70 ++ ;
}
} else {
V_70 = 1 ;
if ( V_66 == 1 ) {
V_70 -- ;
}
if ( V_75 == 1 ) {
V_70 -- ;
}
}
F_9 ( V_21 ) ;
V_30 = F_38 ( V_17 , V_7 , V_19 , V_21 ,
V_70 ) ;
V_33:
return V_30 ;
}
static int F_47 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_48 , T_3 V_41 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 ;
T_3 V_71 , V_72 ;
T_3 V_49 = V_48 + V_41 ;
int V_70 = - 1 ;
int V_30 ;
V_10 . V_31 = V_48 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_57 ) ;
V_71 = V_10 . V_31 ;
V_72 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_48 >= V_71 && V_49 <= V_72 ) ;
V_30 = F_48 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
if ( V_48 > V_71 ) {
V_10 . V_31 = V_71 ;
V_10 . type = V_57 ;
V_10 . V_11 = V_48 - V_71 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
V_70 ++ ;
}
if ( V_49 < V_72 ) {
V_10 . V_31 = V_49 ;
V_10 . type = V_57 ;
V_10 . V_11 = V_72 - V_49 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
V_70 ++ ;
}
F_9 ( V_21 ) ;
V_30 = F_38 ( V_17 , V_7 , V_19 , V_21 ,
V_70 ) ;
V_33:
return V_30 ;
}
int F_49 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_48 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_51 ;
int V_30 ;
if ( V_19 -> V_77 ) {
V_30 = F_50 ( V_17 , V_7 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_25 ( V_26 ) )
return F_26 ( V_26 ) ;
V_51 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_51 & V_60 ) {
return F_46 ( V_17 , V_7 , V_19 ,
V_21 , V_48 , V_41 , 1 ) ;
} else {
return F_47 ( V_17 , V_7 , V_19 ,
V_21 , V_48 , V_41 ) ;
}
}
int F_51 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
T_3 V_48 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_52 ( V_7 , V_78 ) )
return 0 ;
V_21 = F_53 () ;
if ( ! V_21 ) {
V_30 = - V_56 ;
goto V_33;
}
V_19 = F_54 ( V_7 , V_48 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_55 ( & V_19 -> V_79 ) ;
V_30 = F_49 ( V_17 , V_7 , V_19 , V_21 ,
V_48 , V_41 ) ;
F_56 ( & V_19 -> V_79 ) ;
F_57 ( V_19 ) ;
V_33:
F_58 ( V_21 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_59 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_48 , T_3 V_41 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 , V_80 ;
T_3 V_71 , V_72 ;
T_3 V_49 = V_48 + V_41 ;
int V_70 = 1 ;
int V_30 ;
V_80 . V_31 = V_48 ;
V_80 . type = V_57 ;
V_80 . V_11 = V_41 ;
if ( V_48 == V_19 -> V_10 . V_31 )
goto V_81;
V_10 . V_31 = V_48 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type != V_57 ) {
ASSERT ( V_10 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_81;
}
V_71 = V_10 . V_31 ;
V_72 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_71 >= V_19 -> V_10 . V_31 &&
V_72 > V_19 -> V_10 . V_31 ) ;
ASSERT ( V_71 < V_48 && V_72 <= V_48 ) ;
if ( V_72 == V_48 ) {
V_30 = F_48 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_80 . V_31 = V_71 ;
V_80 . V_11 += V_10 . V_11 ;
V_70 -- ;
}
F_9 ( V_21 ) ;
V_81:
if ( V_49 == V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 )
goto V_82;
V_10 . V_31 = V_49 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type != V_57 ) {
ASSERT ( V_10 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_82;
}
V_71 = V_10 . V_31 ;
V_72 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_71 >= V_19 -> V_10 . V_31 &&
V_72 > V_19 -> V_10 . V_31 ) ;
ASSERT ( ( V_71 < V_48 && V_72 <= V_48 ) ||
( V_71 >= V_49 && V_72 > V_49 ) ) ;
if ( V_71 == V_49 ) {
V_30 = F_48 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_80 . V_11 += V_10 . V_11 ;
V_70 -- ;
}
F_9 ( V_21 ) ;
V_82:
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_80 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_30 = F_38 ( V_17 , V_7 , V_19 , V_21 ,
V_70 ) ;
V_33:
return V_30 ;
}
int F_60 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_48 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_51 ;
int V_30 ;
if ( V_19 -> V_77 ) {
V_30 = F_50 ( V_17 , V_7 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_25 ( V_26 ) )
return F_26 ( V_26 ) ;
V_51 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_51 & V_60 ) {
return F_46 ( V_17 , V_7 , V_19 ,
V_21 , V_48 , V_41 , 0 ) ;
} else {
return F_59 ( V_17 , V_7 , V_19 , V_21 ,
V_48 , V_41 ) ;
}
}
int F_61 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
T_3 V_48 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_52 ( V_7 , V_78 ) )
return 0 ;
V_21 = F_53 () ;
if ( ! V_21 ) {
V_30 = - V_56 ;
goto V_33;
}
V_19 = F_54 ( V_7 , V_48 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_55 ( & V_19 -> V_79 ) ;
V_30 = F_60 ( V_17 , V_7 , V_19 , V_21 , V_48 ,
V_41 ) ;
F_56 ( & V_19 -> V_79 ) ;
F_57 ( V_19 ) ;
V_33:
F_58 ( V_21 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_62 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_22 * V_83 = V_7 -> V_83 ;
struct V_20 * V_21 , * V_84 ;
struct V_27 V_10 ;
T_3 V_48 , V_49 ;
int V_30 ;
V_21 = F_53 () ;
if ( ! V_21 )
return - V_56 ;
V_21 -> V_85 = 1 ;
V_84 = F_53 () ;
if ( ! V_84 ) {
F_58 ( V_21 ) ;
return - V_56 ;
}
V_30 = F_3 ( V_17 , V_7 , V_19 , V_84 ) ;
if ( V_30 )
goto V_33;
F_55 ( & V_19 -> V_79 ) ;
V_10 . V_31 = V_19 -> V_10 . V_31 ;
V_10 . type = V_86 ;
V_10 . V_11 = 0 ;
V_30 = F_63 ( V_83 , & V_10 , V_21 , 1 , 0 ) ;
if ( V_30 < 0 )
goto V_87;
ASSERT ( V_30 == 0 ) ;
V_48 = V_19 -> V_10 . V_31 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_86 ||
V_10 . type == V_88 ) {
if ( V_10 . V_31 >= V_49 )
break;
if ( V_48 < V_10 . V_31 ) {
V_30 = F_60 ( V_17 , V_7 ,
V_19 ,
V_84 , V_48 ,
V_10 . V_31 -
V_48 ) ;
if ( V_30 )
goto V_87;
}
V_48 = V_10 . V_31 ;
if ( V_10 . type == V_88 )
V_48 += V_7 -> V_89 ;
else
V_48 += V_10 . V_11 ;
} else if ( V_10 . type == V_90 ) {
if ( V_10 . V_31 != V_19 -> V_10 . V_31 )
break;
}
V_30 = F_64 ( V_83 , V_21 ) ;
if ( V_30 < 0 )
goto V_87;
if ( V_30 )
break;
}
if ( V_48 < V_49 ) {
V_30 = F_60 ( V_17 , V_7 , V_19 ,
V_84 , V_48 , V_49 - V_48 ) ;
if ( V_30 )
goto V_87;
}
V_30 = 0 ;
V_87:
F_56 ( & V_19 -> V_79 ) ;
V_33:
F_58 ( V_84 ) ;
F_58 ( V_21 ) ;
return V_30 ;
}
int F_65 ( struct V_18 * V_7 )
{
struct V_16 * V_17 ;
struct V_22 * V_91 = V_7 -> V_91 ;
struct V_22 * V_24 ;
struct V_1 * V_19 ;
struct V_92 * V_93 ;
int V_30 ;
V_17 = F_66 ( V_91 , 0 ) ;
if ( F_25 ( V_17 ) )
return F_26 ( V_17 ) ;
F_67 ( V_94 , & V_7 -> V_51 ) ;
V_24 = F_68 ( V_17 , V_7 ,
V_95 ) ;
if ( F_25 ( V_24 ) ) {
V_30 = F_26 ( V_24 ) ;
goto abort;
}
V_7 -> V_24 = V_24 ;
V_93 = F_69 ( & V_7 -> V_96 ) ;
while ( V_93 ) {
V_19 = F_70 ( V_93 , struct V_1 ,
V_97 ) ;
V_30 = F_62 ( V_17 , V_7 , V_19 ) ;
if ( V_30 )
goto abort;
V_93 = F_71 ( V_93 ) ;
}
F_72 ( V_7 , V_78 ) ;
F_72 ( V_7 , V_98 ) ;
F_73 ( V_94 , & V_7 -> V_51 ) ;
return F_74 ( V_17 ) ;
abort:
F_73 ( V_94 , & V_7 -> V_51 ) ;
F_34 ( V_17 , V_30 ) ;
F_75 ( V_17 ) ;
return V_30 ;
}
static int F_76 ( struct V_16 * V_17 ,
struct V_22 * V_23 )
{
struct V_20 * V_21 ;
struct V_27 V_10 ;
int V_55 ;
int V_30 ;
V_21 = F_53 () ;
if ( ! V_21 )
return - V_56 ;
V_21 -> V_99 = 1 ;
V_10 . V_31 = 0 ;
V_10 . type = 0 ;
V_10 . V_11 = 0 ;
while ( 1 ) {
V_30 = F_11 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 < 0 )
goto V_33;
V_55 = F_45 ( V_21 -> V_34 [ 0 ] ) ;
if ( ! V_55 )
break;
V_21 -> V_35 [ 0 ] = 0 ;
V_30 = F_24 ( V_17 , V_23 , V_21 , 0 , V_55 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_58 ( V_21 ) ;
return V_30 ;
}
int F_77 ( struct V_18 * V_7 )
{
struct V_16 * V_17 ;
struct V_22 * V_91 = V_7 -> V_91 ;
struct V_22 * V_24 = V_7 -> V_24 ;
int V_30 ;
V_17 = F_66 ( V_91 , 0 ) ;
if ( F_25 ( V_17 ) )
return F_26 ( V_17 ) ;
F_78 ( V_7 , V_78 ) ;
F_78 ( V_7 , V_98 ) ;
V_7 -> V_24 = NULL ;
V_30 = F_76 ( V_17 , V_24 ) ;
if ( V_30 )
goto abort;
V_30 = F_79 ( V_17 , V_91 , & V_24 -> V_100 ) ;
if ( V_30 )
goto abort;
F_80 ( & V_24 -> V_101 ) ;
F_81 ( V_24 -> V_93 ) ;
F_82 ( V_7 , V_24 -> V_93 ) ;
F_83 ( V_24 -> V_93 ) ;
F_84 ( V_17 , V_24 , V_24 -> V_93 ,
0 , 1 ) ;
F_85 ( V_24 -> V_93 ) ;
F_85 ( V_24 -> V_102 ) ;
F_86 ( V_24 ) ;
return F_74 ( V_17 ) ;
abort:
F_34 ( V_17 , V_30 ) ;
F_75 ( V_17 ) ;
return V_30 ;
}
static int F_50 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
T_3 V_48 , V_49 ;
int V_30 ;
V_48 = V_19 -> V_10 . V_31 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_19 -> V_77 = 0 ;
V_30 = F_3 ( V_17 , V_7 , V_19 , V_21 ) ;
if ( V_30 )
return V_30 ;
return F_60 ( V_17 , V_7 , V_19 , V_21 ,
V_19 -> V_10 . V_31 ,
V_19 -> V_10 . V_11 ) ;
}
int F_87 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = NULL ;
int V_30 = 0 ;
if ( ! F_52 ( V_7 , V_78 ) )
return 0 ;
F_55 ( & V_19 -> V_79 ) ;
if ( ! V_19 -> V_77 )
goto V_33;
V_21 = F_53 () ;
if ( ! V_21 ) {
V_30 = - V_56 ;
goto V_33;
}
V_30 = F_50 ( V_17 , V_7 , V_19 , V_21 ) ;
V_33:
F_58 ( V_21 ) ;
F_56 ( & V_19 -> V_79 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
int F_88 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_20 * V_21 ;
struct V_27 V_10 , V_45 ;
struct V_28 * V_29 ;
T_3 V_48 , V_49 ;
int V_54 = 0 , V_55 ;
int V_30 ;
if ( ! F_52 ( V_7 , V_78 ) )
return 0 ;
if ( V_19 -> V_77 ) {
return 0 ;
}
V_21 = F_53 () ;
if ( ! V_21 ) {
V_30 = - V_56 ;
goto V_33;
}
V_48 = V_19 -> V_10 . V_31 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_49 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_54 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_55 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_22 ( V_29 , & V_45 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_45 . type == V_32 ) {
ASSERT ( V_45 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_45 . V_11 == V_19 -> V_10 . V_11 ) ;
V_54 = 1 ;
V_55 ++ ;
V_21 -> V_35 [ 0 ] -- ;
break;
} else if ( V_45 . type == V_57 ||
V_45 . type == V_64 ) {
ASSERT ( V_45 . V_31 >= V_48 ) ;
ASSERT ( V_45 . V_31 < V_49 ) ;
ASSERT ( V_45 . V_31 + V_45 . V_11 <= V_49 ) ;
V_55 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_24 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_55 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_58 ( V_21 ) ;
if ( V_30 )
F_34 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_89 ( struct V_103 * V_104 ,
struct V_20 * V_21 ,
T_1 V_52 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_22 * V_23 ;
struct V_27 V_10 ;
int V_66 = 0 , V_67 ;
T_3 V_65 = 0 ;
T_3 V_49 , V_11 ;
T_3 V_105 = 0 ;
T_1 V_53 = 0 ;
int V_30 ;
V_19 = V_104 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_23 = V_7 -> V_24 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
V_30 = F_64 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_32 )
break;
ASSERT ( V_10 . type == V_64 ) ;
ASSERT ( V_10 . V_31 < V_49 && V_10 . V_31 + V_10 . V_11 <= V_49 ) ;
V_104 -> V_106 = V_10 . V_31 ;
V_11 = V_10 . V_31 ;
while ( V_11 < V_10 . V_31 + V_10 . V_11 ) {
V_67 = F_39 ( V_19 , V_21 , V_11 ) ;
if ( V_66 == 0 && V_67 == 1 ) {
V_65 = V_11 ;
} else if ( V_66 == 1 && V_67 == 0 ) {
V_105 += F_90 ( V_19 ,
V_7 ,
V_65 ,
V_11 ) ;
if ( V_105 > V_107 ) {
V_105 = 0 ;
F_91 ( & V_104 -> V_108 ) ;
}
V_53 ++ ;
}
V_66 = V_67 ;
V_11 += V_7 -> V_8 ;
}
}
if ( V_66 == 1 ) {
V_105 += F_90 ( V_19 , V_7 ,
V_65 , V_49 ) ;
V_53 ++ ;
}
if ( V_53 != V_52 ) {
F_29 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_53 ,
V_52 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_104 -> V_106 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
static int F_92 ( struct V_103 * V_104 ,
struct V_20 * V_21 ,
T_1 V_52 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_22 * V_23 ;
struct V_27 V_10 ;
T_3 V_49 ;
T_3 V_105 = 0 ;
T_1 V_53 = 0 ;
int V_30 ;
V_19 = V_104 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_23 = V_7 -> V_24 ;
V_49 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
V_30 = F_64 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_22 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_32 )
break;
ASSERT ( V_10 . type == V_57 ) ;
ASSERT ( V_10 . V_31 < V_49 && V_10 . V_31 + V_10 . V_11 <= V_49 ) ;
V_104 -> V_106 = V_10 . V_31 ;
V_105 += F_90 ( V_19 , V_7 ,
V_10 . V_31 ,
V_10 . V_31 + V_10 . V_11 ) ;
if ( V_105 > V_107 ) {
V_105 = 0 ;
F_91 ( & V_104 -> V_108 ) ;
}
V_53 ++ ;
}
if ( V_53 != V_52 ) {
F_29 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_53 ,
V_52 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_104 -> V_106 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
int F_93 ( struct V_103 * V_104 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
T_1 V_53 , V_51 ;
int V_30 ;
V_19 = V_104 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_21 = F_53 () ;
if ( ! V_21 )
return - V_56 ;
V_21 -> V_109 = 1 ;
V_21 -> V_110 = 1 ;
V_21 -> V_85 = 1 ;
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_25 ( V_26 ) ) {
V_30 = F_26 ( V_26 ) ;
goto V_33;
}
V_53 = F_28 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_51 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
if ( V_51 & V_60 )
V_30 = F_89 ( V_104 , V_21 , V_53 ) ;
else
V_30 = F_92 ( V_104 , V_21 , V_53 ) ;
V_33:
F_58 ( V_21 ) ;
return V_30 ;
}
