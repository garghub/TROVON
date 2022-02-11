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
void * V_43 ;
if ( V_4 <= V_44 )
return F_18 ( V_4 , V_45 ) ;
V_43 = F_18 ( V_4 , V_45 | V_46 ) ;
if ( V_43 )
return V_43 ;
return F_19 ( V_4 , V_45 | V_47 , V_48 ) ;
}
int F_20 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_10 , V_49 ;
struct V_28 * V_29 ;
T_4 * V_50 , * V_51 ;
T_3 V_52 , V_53 ;
T_3 V_3 , V_54 ;
T_1 V_4 , V_55 , V_56 ;
T_1 V_57 = 0 ;
int V_58 = 0 , V_59 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_10 . V_11 ,
V_7 -> V_8 ) ;
V_50 = F_17 ( V_4 ) ;
if ( ! V_50 ) {
V_30 = - V_60 ;
goto V_33;
}
V_52 = V_19 -> V_10 . V_31 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_53 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_58 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_59 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_49 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_49 . type == V_32 ) {
ASSERT ( V_49 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_49 . V_11 == V_19 -> V_10 . V_11 ) ;
V_58 = 1 ;
break;
} else if ( V_49 . type == V_61 ) {
T_3 V_62 , V_63 ;
ASSERT ( V_49 . V_31 >= V_52 ) ;
ASSERT ( V_49 . V_31 < V_53 ) ;
ASSERT ( V_49 . V_31 + V_49 . V_11 <= V_53 ) ;
V_62 = F_2 ( V_49 . V_31 - V_52 ,
V_7 -> V_8 ) ;
V_63 = F_2 ( V_49 . V_31 + V_49 . V_11 - V_52 ,
V_7 -> V_8 ) ;
F_22 ( V_50 , V_62 , V_63 - V_62 ) ;
V_57 ++ ;
V_59 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_59 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_55 = F_26 ( V_29 , V_26 ) ;
V_55 |= V_64 ;
F_7 ( V_29 , V_26 , V_55 ) ;
V_56 = F_27 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
if ( V_57 != V_56 ) {
F_28 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_57 ,
V_56 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_51 = V_50 ;
V_3 = V_7 -> V_8 * V_9 ;
V_54 = V_52 ;
while ( V_54 < V_53 ) {
unsigned long V_65 ;
T_3 V_66 ;
T_1 V_67 ;
V_66 = F_29 ( V_53 - V_54 , V_3 ) ;
V_67 = F_15 ( V_66 ,
V_7 -> V_8 ) ;
V_10 . V_31 = V_54 ;
V_10 . type = V_68 ;
V_10 . V_11 = V_66 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 ,
V_67 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_65 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
F_31 ( V_29 , V_51 , V_65 ,
V_67 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_54 += V_66 ;
V_51 += V_67 ;
}
V_30 = 0 ;
V_33:
F_32 ( V_50 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
int F_34 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_10 , V_49 ;
struct V_28 * V_29 ;
T_4 * V_50 ;
T_3 V_52 , V_53 ;
T_3 V_69 = 0 ;
T_3 V_11 ;
T_1 V_4 , V_55 , V_56 ;
int V_70 = 0 , V_71 , V_72 ;
T_1 V_57 = 0 ;
int V_58 = 0 , V_59 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_10 . V_11 ,
V_7 -> V_8 ) ;
V_50 = F_17 ( V_4 ) ;
if ( ! V_50 ) {
V_30 = - V_60 ;
goto V_33;
}
V_52 = V_19 -> V_10 . V_31 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_53 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_58 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_59 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_49 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_49 . type == V_32 ) {
ASSERT ( V_49 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_49 . V_11 == V_19 -> V_10 . V_11 ) ;
V_58 = 1 ;
break;
} else if ( V_49 . type == V_68 ) {
unsigned long V_65 ;
T_4 * V_51 ;
T_1 V_73 , V_67 ;
ASSERT ( V_49 . V_31 >= V_52 ) ;
ASSERT ( V_49 . V_31 < V_53 ) ;
ASSERT ( V_49 . V_31 + V_49 . V_11 <= V_53 ) ;
V_73 = F_2 ( V_49 . V_31 - V_52 ,
V_7 -> V_8 *
V_42 ) ;
V_51 = V_50 + V_73 ;
V_67 = F_15 ( V_49 . V_11 ,
V_7 -> V_8 ) ;
V_65 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] - 1 ) ;
F_35 ( V_29 , V_51 , V_65 ,
V_67 ) ;
V_59 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_59 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_55 = F_26 ( V_29 , V_26 ) ;
V_55 &= ~ V_64 ;
F_7 ( V_29 , V_26 , V_55 ) ;
V_56 = F_27 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_11 = V_52 ;
V_72 = 0 ;
while ( V_11 < V_53 ) {
V_71 = ! ! F_36 ( V_72 , V_50 ) ;
if ( V_70 == 0 && V_71 == 1 ) {
V_69 = V_11 ;
} else if ( V_70 == 1 && V_71 == 0 ) {
V_10 . V_31 = V_69 ;
V_10 . type = V_61 ;
V_10 . V_11 = V_11 - V_69 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_57 ++ ;
}
V_70 = V_71 ;
V_11 += V_7 -> V_8 ;
V_72 ++ ;
}
if ( V_70 == 1 ) {
V_10 . V_31 = V_69 ;
V_10 . type = V_61 ;
V_10 . V_11 = V_53 - V_69 ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_57 ++ ;
}
if ( V_57 != V_56 ) {
F_28 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_57 ,
V_56 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_30 = 0 ;
V_33:
F_32 ( V_50 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_37 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
int V_74 )
{
struct V_25 * V_26 ;
T_1 V_55 ;
T_1 V_57 ;
int V_30 = 0 ;
if ( V_74 == 0 )
return 0 ;
V_26 = F_10 ( V_17 , V_7 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_55 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_57 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_57 += V_74 ;
F_6 ( V_21 -> V_34 [ 0 ] , V_26 , V_57 ) ;
F_8 ( V_21 -> V_34 [ 0 ] ) ;
F_9 ( V_21 ) ;
if ( ! ( V_55 & V_64 ) &&
V_57 > V_19 -> V_14 ) {
V_30 = F_20 ( V_17 , V_7 , V_19 ,
V_21 ) ;
} else if ( ( V_55 & V_64 ) &&
V_57 < V_19 -> V_15 ) {
V_30 = F_34 ( V_17 , V_7 , V_19 ,
V_21 ) ;
}
V_33:
return V_30 ;
}
int F_38 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_11 )
{
struct V_28 * V_29 ;
struct V_27 V_10 ;
T_3 V_75 , V_76 ;
unsigned long V_65 , V_54 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_21 ( V_29 , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_68 ) ;
V_75 = V_10 . V_31 ;
V_76 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_11 >= V_75 && V_11 < V_76 ) ;
V_65 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_54 = F_2 ( V_11 - V_75 ,
V_19 -> V_7 -> V_8 ) ;
return ! ! F_39 ( V_29 , V_65 , V_54 ) ;
}
static void F_40 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 * V_52 , T_3 * V_41 ,
int V_71 )
{
struct V_18 * V_7 = V_19 -> V_7 ;
struct V_28 * V_29 ;
struct V_27 V_10 ;
T_3 V_53 = * V_52 + * V_41 ;
T_3 V_75 , V_76 ;
unsigned long V_65 , V_62 , V_63 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_21 ( V_29 , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_68 ) ;
V_75 = V_10 . V_31 ;
V_76 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( * V_52 >= V_75 && * V_52 < V_76 ) ;
ASSERT ( V_53 > V_75 ) ;
if ( V_53 > V_76 )
V_53 = V_76 ;
V_65 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_62 = F_2 ( * V_52 - V_75 , V_7 -> V_8 ) ;
V_63 = F_2 ( V_53 - V_75 , V_7 -> V_8 ) ;
if ( V_71 )
F_41 ( V_29 , V_65 , V_62 , V_63 - V_62 ) ;
else
F_42 ( V_29 , V_65 , V_62 , V_63 - V_62 ) ;
F_8 ( V_29 ) ;
* V_41 -= V_53 - * V_52 ;
* V_52 = V_53 ;
}
static int F_43 ( struct V_16 * V_17 ,
struct V_22 * V_23 , struct V_20 * V_38 )
{
struct V_27 V_10 ;
if ( V_38 -> V_35 [ 0 ] + 1 < F_44 ( V_38 -> V_34 [ 0 ] ) ) {
V_38 -> V_35 [ 0 ] ++ ;
return 0 ;
}
F_21 ( V_38 -> V_34 [ 0 ] , & V_10 , V_38 -> V_35 [ 0 ] ) ;
F_9 ( V_38 ) ;
V_10 . V_31 += V_10 . V_11 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
return F_14 ( V_17 , V_23 , & V_10 , V_38 , 0 , 1 ) ;
}
static int F_45 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_52 , T_3 V_41 , int remove )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 ;
T_3 V_53 = V_52 + V_41 ;
T_3 V_77 , V_78 ;
int V_70 , V_79 ;
int V_74 ;
int V_30 ;
if ( V_52 > V_19 -> V_10 . V_31 ) {
T_3 V_80 = V_52 - V_19 -> V_7 -> V_8 ;
V_10 . V_31 = V_80 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_70 = F_38 ( V_19 , V_21 , V_80 ) ;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_52 >= V_10 . V_31 + V_10 . V_11 ) {
V_30 = F_43 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
} else {
V_10 . V_31 = V_52 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_70 = - 1 ;
}
V_77 = V_52 ;
V_78 = V_41 ;
while ( 1 ) {
F_40 ( V_19 , V_21 , & V_77 , & V_78 ,
! remove ) ;
if ( V_78 == 0 )
break;
V_30 = F_43 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
if ( V_53 < V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ) {
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_53 >= V_10 . V_31 + V_10 . V_11 ) {
V_30 = F_43 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
V_79 = F_38 ( V_19 , V_21 , V_53 ) ;
} else {
V_79 = - 1 ;
}
if ( remove ) {
V_74 = - 1 ;
if ( V_70 == 1 ) {
V_74 ++ ;
}
if ( V_79 == 1 ) {
V_74 ++ ;
}
} else {
V_74 = 1 ;
if ( V_70 == 1 ) {
V_74 -- ;
}
if ( V_79 == 1 ) {
V_74 -- ;
}
}
F_9 ( V_21 ) ;
V_30 = F_37 ( V_17 , V_7 , V_19 , V_21 ,
V_74 ) ;
V_33:
return V_30 ;
}
static int F_46 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_52 , T_3 V_41 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 ;
T_3 V_75 , V_76 ;
T_3 V_53 = V_52 + V_41 ;
int V_74 = - 1 ;
int V_30 ;
V_10 . V_31 = V_52 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_10 . type == V_61 ) ;
V_75 = V_10 . V_31 ;
V_76 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_52 >= V_75 && V_53 <= V_76 ) ;
V_30 = F_47 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
if ( V_52 > V_75 ) {
V_10 . V_31 = V_75 ;
V_10 . type = V_61 ;
V_10 . V_11 = V_52 - V_75 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
V_74 ++ ;
}
if ( V_53 < V_76 ) {
V_10 . V_31 = V_53 ;
V_10 . type = V_61 ;
V_10 . V_11 = V_76 - V_53 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_10 , 0 ) ;
if ( V_30 )
goto V_33;
V_74 ++ ;
}
F_9 ( V_21 ) ;
V_30 = F_37 ( V_17 , V_7 , V_19 , V_21 ,
V_74 ) ;
V_33:
return V_30 ;
}
int F_48 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_52 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_55 ;
int V_30 ;
if ( V_19 -> V_81 ) {
V_30 = F_49 ( V_17 , V_7 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_55 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_55 & V_64 ) {
return F_45 ( V_17 , V_7 , V_19 ,
V_21 , V_52 , V_41 , 1 ) ;
} else {
return F_46 ( V_17 , V_7 , V_19 ,
V_21 , V_52 , V_41 ) ;
}
}
int F_50 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
T_3 V_52 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_51 ( V_7 , V_82 ) )
return 0 ;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_60 ;
goto V_33;
}
V_19 = F_53 ( V_7 , V_52 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_54 ( & V_19 -> V_83 ) ;
V_30 = F_48 ( V_17 , V_7 , V_19 , V_21 ,
V_52 , V_41 ) ;
F_55 ( & V_19 -> V_83 ) ;
F_56 ( V_19 ) ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_58 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_52 , T_3 V_41 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_27 V_10 , V_84 ;
T_3 V_75 , V_76 ;
T_3 V_53 = V_52 + V_41 ;
int V_74 = 1 ;
int V_30 ;
V_84 . V_31 = V_52 ;
V_84 . type = V_61 ;
V_84 . V_11 = V_41 ;
if ( V_52 == V_19 -> V_10 . V_31 )
goto V_85;
V_10 . V_31 = V_52 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type != V_61 ) {
ASSERT ( V_10 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_85;
}
V_75 = V_10 . V_31 ;
V_76 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_75 >= V_19 -> V_10 . V_31 &&
V_76 > V_19 -> V_10 . V_31 ) ;
ASSERT ( V_75 < V_52 && V_76 <= V_52 ) ;
if ( V_76 == V_52 ) {
V_30 = F_47 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_84 . V_31 = V_75 ;
V_84 . V_11 += V_10 . V_11 ;
V_74 -- ;
}
F_9 ( V_21 ) ;
V_85:
if ( V_53 == V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 )
goto V_86;
V_10 . V_31 = V_53 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type != V_61 ) {
ASSERT ( V_10 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_86;
}
V_75 = V_10 . V_31 ;
V_76 = V_10 . V_31 + V_10 . V_11 ;
ASSERT ( V_75 >= V_19 -> V_10 . V_31 &&
V_76 > V_19 -> V_10 . V_31 ) ;
ASSERT ( ( V_75 < V_52 && V_76 <= V_52 ) ||
( V_75 >= V_53 && V_76 > V_53 ) ) ;
if ( V_75 == V_53 ) {
V_30 = F_47 ( V_17 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_84 . V_11 += V_10 . V_11 ;
V_74 -- ;
}
F_9 ( V_21 ) ;
V_86:
V_30 = F_4 ( V_17 , V_23 , V_21 , & V_84 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_30 = F_37 ( V_17 , V_7 , V_19 , V_21 ,
V_74 ) ;
V_33:
return V_30 ;
}
int F_59 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_52 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_55 ;
int V_30 ;
if ( V_19 -> V_81 ) {
V_30 = F_49 ( V_17 , V_7 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_55 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_55 & V_64 ) {
return F_45 ( V_17 , V_7 , V_19 ,
V_21 , V_52 , V_41 , 0 ) ;
} else {
return F_58 ( V_17 , V_7 , V_19 , V_21 ,
V_52 , V_41 ) ;
}
}
int F_60 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
T_3 V_52 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_51 ( V_7 , V_82 ) )
return 0 ;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_60 ;
goto V_33;
}
V_19 = F_53 ( V_7 , V_52 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_54 ( & V_19 -> V_83 ) ;
V_30 = F_59 ( V_17 , V_7 , V_19 , V_21 , V_52 ,
V_41 ) ;
F_55 ( & V_19 -> V_83 ) ;
F_56 ( V_19 ) ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_61 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_22 * V_87 = V_7 -> V_87 ;
struct V_20 * V_21 , * V_88 ;
struct V_27 V_10 ;
T_3 V_52 , V_53 ;
int V_30 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_60 ;
V_21 -> V_89 = 1 ;
V_88 = F_52 () ;
if ( ! V_88 ) {
F_57 ( V_21 ) ;
return - V_60 ;
}
V_30 = F_3 ( V_17 , V_7 , V_19 , V_88 ) ;
if ( V_30 )
goto V_33;
F_54 ( & V_19 -> V_83 ) ;
V_10 . V_31 = V_19 -> V_10 . V_31 ;
V_10 . type = V_90 ;
V_10 . V_11 = 0 ;
V_30 = F_62 ( V_87 , & V_10 , V_21 , 1 , 0 ) ;
if ( V_30 < 0 )
goto V_91;
ASSERT ( V_30 == 0 ) ;
V_52 = V_19 -> V_10 . V_31 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_90 ||
V_10 . type == V_92 ) {
if ( V_10 . V_31 >= V_53 )
break;
if ( V_52 < V_10 . V_31 ) {
V_30 = F_59 ( V_17 , V_7 ,
V_19 ,
V_88 , V_52 ,
V_10 . V_31 -
V_52 ) ;
if ( V_30 )
goto V_91;
}
V_52 = V_10 . V_31 ;
if ( V_10 . type == V_92 )
V_52 += V_7 -> V_93 ;
else
V_52 += V_10 . V_11 ;
} else if ( V_10 . type == V_94 ) {
if ( V_10 . V_31 != V_19 -> V_10 . V_31 )
break;
}
V_30 = F_63 ( V_87 , V_21 ) ;
if ( V_30 < 0 )
goto V_91;
if ( V_30 )
break;
}
if ( V_52 < V_53 ) {
V_30 = F_59 ( V_17 , V_7 , V_19 ,
V_88 , V_52 , V_53 - V_52 ) ;
if ( V_30 )
goto V_91;
}
V_30 = 0 ;
V_91:
F_55 ( & V_19 -> V_83 ) ;
V_33:
F_57 ( V_88 ) ;
F_57 ( V_21 ) ;
return V_30 ;
}
int F_64 ( struct V_18 * V_7 )
{
struct V_16 * V_17 ;
struct V_22 * V_95 = V_7 -> V_95 ;
struct V_22 * V_24 ;
struct V_1 * V_19 ;
struct V_96 * V_97 ;
int V_30 ;
V_17 = F_65 ( V_95 , 0 ) ;
if ( F_24 ( V_17 ) )
return F_25 ( V_17 ) ;
F_66 ( V_98 , & V_7 -> V_55 ) ;
V_24 = F_67 ( V_17 , V_7 ,
V_99 ) ;
if ( F_24 ( V_24 ) ) {
V_30 = F_25 ( V_24 ) ;
goto abort;
}
V_7 -> V_24 = V_24 ;
V_97 = F_68 ( & V_7 -> V_100 ) ;
while ( V_97 ) {
V_19 = F_69 ( V_97 , struct V_1 ,
V_101 ) ;
V_30 = F_61 ( V_17 , V_7 , V_19 ) ;
if ( V_30 )
goto abort;
V_97 = F_70 ( V_97 ) ;
}
F_71 ( V_7 , V_82 ) ;
F_71 ( V_7 , V_102 ) ;
F_72 ( V_98 , & V_7 -> V_55 ) ;
V_30 = F_73 ( V_17 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
abort:
F_72 ( V_98 , & V_7 -> V_55 ) ;
F_33 ( V_17 , V_30 ) ;
F_74 ( V_17 ) ;
return V_30 ;
}
static int F_75 ( struct V_16 * V_17 ,
struct V_22 * V_23 )
{
struct V_20 * V_21 ;
struct V_27 V_10 ;
int V_59 ;
int V_30 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_60 ;
V_21 -> V_103 = 1 ;
V_10 . V_31 = 0 ;
V_10 . type = 0 ;
V_10 . V_11 = 0 ;
while ( 1 ) {
V_30 = F_11 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 < 0 )
goto V_33;
V_59 = F_44 ( V_21 -> V_34 [ 0 ] ) ;
if ( ! V_59 )
break;
V_21 -> V_35 [ 0 ] = 0 ;
V_30 = F_23 ( V_17 , V_23 , V_21 , 0 , V_59 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_57 ( V_21 ) ;
return V_30 ;
}
int F_76 ( struct V_18 * V_7 )
{
struct V_16 * V_17 ;
struct V_22 * V_95 = V_7 -> V_95 ;
struct V_22 * V_24 = V_7 -> V_24 ;
int V_30 ;
V_17 = F_65 ( V_95 , 0 ) ;
if ( F_24 ( V_17 ) )
return F_25 ( V_17 ) ;
F_77 ( V_7 , V_82 ) ;
F_77 ( V_7 , V_102 ) ;
V_7 -> V_24 = NULL ;
V_30 = F_75 ( V_17 , V_24 ) ;
if ( V_30 )
goto abort;
V_30 = F_78 ( V_17 , V_95 , & V_24 -> V_104 ) ;
if ( V_30 )
goto abort;
F_79 ( & V_24 -> V_105 ) ;
F_80 ( V_24 -> V_97 ) ;
F_81 ( V_7 , V_24 -> V_97 ) ;
F_82 ( V_24 -> V_97 ) ;
F_83 ( V_17 , V_24 , V_24 -> V_97 ,
0 , 1 ) ;
F_84 ( V_24 -> V_97 ) ;
F_84 ( V_24 -> V_106 ) ;
F_85 ( V_24 ) ;
V_30 = F_73 ( V_17 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
abort:
F_33 ( V_17 , V_30 ) ;
F_74 ( V_17 ) ;
return V_30 ;
}
static int F_49 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
T_3 V_52 , V_53 ;
int V_30 ;
V_52 = V_19 -> V_10 . V_31 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_19 -> V_81 = 0 ;
V_30 = F_3 ( V_17 , V_7 , V_19 , V_21 ) ;
if ( V_30 )
return V_30 ;
return F_59 ( V_17 , V_7 , V_19 , V_21 ,
V_19 -> V_10 . V_31 ,
V_19 -> V_10 . V_11 ) ;
}
int F_86 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = NULL ;
int V_30 = 0 ;
if ( ! F_51 ( V_7 , V_82 ) )
return 0 ;
F_54 ( & V_19 -> V_83 ) ;
if ( ! V_19 -> V_81 )
goto V_33;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_60 ;
goto V_33;
}
V_30 = F_49 ( V_17 , V_7 , V_19 , V_21 ) ;
V_33:
F_57 ( V_21 ) ;
F_55 ( & V_19 -> V_83 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
int F_87 ( struct V_16 * V_17 ,
struct V_18 * V_7 ,
struct V_1 * V_19 )
{
struct V_22 * V_23 = V_7 -> V_24 ;
struct V_20 * V_21 ;
struct V_27 V_10 , V_49 ;
struct V_28 * V_29 ;
T_3 V_52 , V_53 ;
int V_58 = 0 , V_59 ;
int V_30 ;
if ( ! F_51 ( V_7 , V_82 ) )
return 0 ;
if ( V_19 -> V_81 ) {
return 0 ;
}
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_60 ;
goto V_33;
}
V_52 = V_19 -> V_10 . V_31 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
V_10 . V_31 = V_53 - 1 ;
V_10 . type = ( T_4 ) - 1 ;
V_10 . V_11 = ( T_3 ) - 1 ;
while ( ! V_58 ) {
V_30 = F_14 ( V_17 , V_23 , & V_10 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_59 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_49 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_49 . type == V_32 ) {
ASSERT ( V_49 . V_31 == V_19 -> V_10 . V_31 ) ;
ASSERT ( V_49 . V_11 == V_19 -> V_10 . V_11 ) ;
V_58 = 1 ;
V_59 ++ ;
V_21 -> V_35 [ 0 ] -- ;
break;
} else if ( V_49 . type == V_61 ||
V_49 . type == V_68 ) {
ASSERT ( V_49 . V_31 >= V_52 ) ;
ASSERT ( V_49 . V_31 < V_53 ) ;
ASSERT ( V_49 . V_31 + V_49 . V_11 <= V_53 ) ;
V_59 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_17 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_59 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_17 , V_30 ) ;
return V_30 ;
}
static int F_88 ( struct V_107 * V_108 ,
struct V_20 * V_21 ,
T_1 V_56 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_22 * V_23 ;
struct V_27 V_10 ;
int V_70 = 0 , V_71 ;
T_3 V_69 = 0 ;
T_3 V_53 , V_11 ;
T_3 V_109 = 0 ;
T_1 V_57 = 0 ;
int V_30 ;
V_19 = V_108 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_23 = V_7 -> V_24 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
V_30 = F_63 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_32 )
break;
ASSERT ( V_10 . type == V_68 ) ;
ASSERT ( V_10 . V_31 < V_53 && V_10 . V_31 + V_10 . V_11 <= V_53 ) ;
V_108 -> V_110 = V_10 . V_31 ;
V_11 = V_10 . V_31 ;
while ( V_11 < V_10 . V_31 + V_10 . V_11 ) {
V_71 = F_38 ( V_19 , V_21 , V_11 ) ;
if ( V_70 == 0 && V_71 == 1 ) {
V_69 = V_11 ;
} else if ( V_70 == 1 && V_71 == 0 ) {
V_109 += F_89 ( V_19 ,
V_7 ,
V_69 ,
V_11 ) ;
if ( V_109 > V_111 ) {
V_109 = 0 ;
F_90 ( & V_108 -> V_112 ) ;
}
V_57 ++ ;
}
V_70 = V_71 ;
V_11 += V_7 -> V_8 ;
}
}
if ( V_70 == 1 ) {
V_109 += F_89 ( V_19 , V_7 ,
V_69 , V_53 ) ;
V_57 ++ ;
}
if ( V_57 != V_56 ) {
F_28 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_57 ,
V_56 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_108 -> V_110 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
static int F_91 ( struct V_107 * V_108 ,
struct V_20 * V_21 ,
T_1 V_56 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_22 * V_23 ;
struct V_27 V_10 ;
T_3 V_53 ;
T_3 V_109 = 0 ;
T_1 V_57 = 0 ;
int V_30 ;
V_19 = V_108 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_23 = V_7 -> V_24 ;
V_53 = V_19 -> V_10 . V_31 + V_19 -> V_10 . V_11 ;
while ( 1 ) {
V_30 = F_63 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_21 ( V_21 -> V_34 [ 0 ] , & V_10 , V_21 -> V_35 [ 0 ] ) ;
if ( V_10 . type == V_32 )
break;
ASSERT ( V_10 . type == V_61 ) ;
ASSERT ( V_10 . V_31 < V_53 && V_10 . V_31 + V_10 . V_11 <= V_53 ) ;
V_108 -> V_110 = V_10 . V_31 ;
V_109 += F_89 ( V_19 , V_7 ,
V_10 . V_31 ,
V_10 . V_31 + V_10 . V_11 ) ;
if ( V_109 > V_111 ) {
V_109 = 0 ;
F_90 ( & V_108 -> V_112 ) ;
}
V_57 ++ ;
}
if ( V_57 != V_56 ) {
F_28 ( V_7 ,
L_2 ,
V_19 -> V_10 . V_31 , V_57 ,
V_56 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_108 -> V_110 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
int F_92 ( struct V_107 * V_108 )
{
struct V_1 * V_19 ;
struct V_18 * V_7 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
T_1 V_57 , V_55 ;
int V_30 ;
V_19 = V_108 -> V_19 ;
V_7 = V_19 -> V_7 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_60 ;
V_21 -> V_113 = 1 ;
V_21 -> V_114 = 1 ;
V_21 -> V_89 = 1 ;
V_26 = F_10 ( NULL , V_7 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_57 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_55 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
if ( V_55 & V_64 )
V_30 = F_88 ( V_108 , V_21 , V_57 ) ;
else
V_30 = F_91 ( V_108 , V_21 , V_57 ) ;
V_33:
F_57 ( V_21 ) ;
return V_30 ;
}
