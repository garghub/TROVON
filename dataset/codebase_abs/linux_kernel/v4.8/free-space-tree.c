void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
T_3 V_5 , V_6 ;
V_3 = V_2 -> V_7 * V_8 ;
V_5 = F_2 ( V_2 -> V_9 . V_10 + V_3 - 1 ,
V_3 ) ;
V_4 = sizeof( struct V_11 ) + V_12 ;
V_6 = V_5 * V_4 ;
V_2 -> V_13 = F_2 ( V_6 ,
sizeof( struct V_11 ) ) ;
if ( V_2 -> V_13 > 100 )
V_2 -> V_14 = V_2 -> V_13 - 100 ;
else
V_2 -> V_14 = 0 ;
}
static int F_3 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_9 ;
struct V_28 * V_29 ;
int V_30 ;
V_9 . V_31 = V_19 -> V_9 . V_31 ;
V_9 . type = V_32 ;
V_9 . V_10 = V_19 -> V_9 . V_10 ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 , sizeof( * V_26 ) ) ;
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
F_10 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , int V_36 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_27 V_9 ;
int V_30 ;
V_9 . V_31 = V_19 -> V_9 . V_31 ;
V_9 . type = V_32 ;
V_9 . V_10 = V_19 -> V_9 . V_10 ;
V_30 = F_11 ( V_16 , V_23 , & V_9 , V_21 , 0 , V_36 ) ;
if ( V_30 < 0 )
return F_12 ( V_30 ) ;
if ( V_30 != 0 ) {
F_13 ( V_18 , L_1 ,
V_19 -> V_9 . V_31 ) ;
ASSERT ( 0 ) ;
return F_12 ( - V_37 ) ;
}
return F_5 ( V_21 -> V_34 [ 0 ] , V_21 -> V_35 [ 0 ] ,
struct V_25 ) ;
}
static int F_14 ( struct V_15 * V_16 ,
struct V_22 * V_23 ,
struct V_27 * V_9 , struct V_20 * V_38 ,
int V_39 , int V_36 )
{
int V_30 ;
V_30 = F_11 ( V_16 , V_23 , V_9 , V_38 , V_39 , V_36 ) ;
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
static inline T_1 F_15 ( T_3 V_41 , T_1 V_7 )
{
return F_16 ( ( T_1 ) F_2 ( V_41 , V_7 ) , V_42 ) ;
}
static unsigned long * F_17 ( T_1 V_4 )
{
void * V_43 ;
if ( V_4 <= V_44 )
return F_18 ( V_4 , V_45 ) ;
V_43 = F_18 ( V_4 , V_45 | V_46 ) ;
if ( V_43 )
return V_43 ;
return F_19 ( V_4 , V_45 | V_47 | V_48 ,
V_49 ) ;
}
int F_20 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_9 , V_50 ;
struct V_28 * V_29 ;
unsigned long * V_51 ;
char * V_52 ;
T_3 V_53 , V_54 ;
T_3 V_3 , V_55 ;
T_1 V_4 , V_56 , V_57 ;
T_1 V_58 = 0 ;
int V_59 = 0 , V_60 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_9 . V_10 ,
V_19 -> V_7 ) ;
V_51 = F_17 ( V_4 ) ;
if ( ! V_51 ) {
V_30 = - V_61 ;
goto V_33;
}
V_53 = V_19 -> V_9 . V_31 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
V_9 . V_31 = V_54 - 1 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
while ( ! V_59 ) {
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_60 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_50 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_50 . type == V_32 ) {
ASSERT ( V_50 . V_31 == V_19 -> V_9 . V_31 ) ;
ASSERT ( V_50 . V_10 == V_19 -> V_9 . V_10 ) ;
V_59 = 1 ;
break;
} else if ( V_50 . type == V_63 ) {
T_3 V_64 , V_65 ;
ASSERT ( V_50 . V_31 >= V_53 ) ;
ASSERT ( V_50 . V_31 < V_54 ) ;
ASSERT ( V_50 . V_31 + V_50 . V_10 <= V_54 ) ;
V_64 = F_2 ( V_50 . V_31 - V_53 ,
V_19 -> V_7 ) ;
V_65 = F_2 ( V_50 . V_31 + V_50 . V_10 - V_53 ,
V_19 -> V_7 ) ;
F_22 ( V_51 , V_64 , V_65 - V_64 ) ;
V_58 ++ ;
V_60 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_16 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_60 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_16 , V_18 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_56 = F_26 ( V_29 , V_26 ) ;
V_56 |= V_66 ;
F_7 ( V_29 , V_26 , V_56 ) ;
V_57 = F_27 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
if ( V_58 != V_57 ) {
F_28 ( V_18 , L_2 ,
V_19 -> V_9 . V_31 , V_58 ,
V_57 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_52 = ( char * ) V_51 ;
V_3 = V_19 -> V_7 * V_8 ;
V_55 = V_53 ;
while ( V_55 < V_54 ) {
unsigned long V_67 ;
T_3 V_68 ;
T_1 V_69 ;
V_68 = F_29 ( V_54 - V_55 , V_3 ) ;
V_69 = F_15 ( V_68 ,
V_19 -> V_7 ) ;
V_9 . V_31 = V_55 ;
V_9 . type = V_70 ;
V_9 . V_10 = V_68 ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 ,
V_69 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_67 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
F_31 ( V_29 , V_52 , V_67 ,
V_69 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_55 += V_68 ;
V_52 += V_69 ;
}
V_30 = 0 ;
V_33:
F_32 ( V_51 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
int F_34 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_25 * V_26 ;
struct V_27 V_9 , V_50 ;
struct V_28 * V_29 ;
unsigned long * V_51 ;
T_3 V_53 , V_54 ;
T_3 V_71 = 0 ;
T_3 V_10 ;
T_1 V_4 , V_56 , V_57 ;
int V_72 = 0 , V_73 , V_74 ;
T_1 V_58 = 0 ;
int V_59 = 0 , V_60 ;
int V_30 ;
V_4 = F_15 ( V_19 -> V_9 . V_10 ,
V_19 -> V_7 ) ;
V_51 = F_17 ( V_4 ) ;
if ( ! V_51 ) {
V_30 = - V_61 ;
goto V_33;
}
V_53 = V_19 -> V_9 . V_31 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
V_9 . V_31 = V_54 - 1 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
while ( ! V_59 ) {
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_60 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_50 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_50 . type == V_32 ) {
ASSERT ( V_50 . V_31 == V_19 -> V_9 . V_31 ) ;
ASSERT ( V_50 . V_10 == V_19 -> V_9 . V_10 ) ;
V_59 = 1 ;
break;
} else if ( V_50 . type == V_70 ) {
unsigned long V_67 ;
char * V_52 ;
T_1 V_75 , V_69 ;
ASSERT ( V_50 . V_31 >= V_53 ) ;
ASSERT ( V_50 . V_31 < V_54 ) ;
ASSERT ( V_50 . V_31 + V_50 . V_10 <= V_54 ) ;
V_75 = F_2 ( V_50 . V_31 - V_53 ,
V_19 -> V_7 *
V_42 ) ;
V_52 = ( ( char * ) V_51 ) + V_75 ;
V_69 = F_15 ( V_50 . V_10 ,
V_19 -> V_7 ) ;
V_67 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] - 1 ) ;
F_35 ( V_29 , V_52 , V_67 ,
V_69 ) ;
V_60 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_16 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_60 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_26 = F_10 ( V_16 , V_18 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_29 = V_21 -> V_34 [ 0 ] ;
V_56 = F_26 ( V_29 , V_26 ) ;
V_56 &= ~ V_66 ;
F_7 ( V_29 , V_26 , V_56 ) ;
V_57 = F_27 ( V_29 , V_26 ) ;
F_8 ( V_29 ) ;
F_9 ( V_21 ) ;
V_10 = V_53 ;
V_74 = 0 ;
while ( V_10 < V_54 ) {
V_73 = ! ! F_36 ( V_74 , V_51 ) ;
if ( V_72 == 0 && V_73 == 1 ) {
V_71 = V_10 ;
} else if ( V_72 == 1 && V_73 == 0 ) {
V_9 . V_31 = V_71 ;
V_9 . type = V_63 ;
V_9 . V_10 = V_10 - V_71 ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_58 ++ ;
}
V_72 = V_73 ;
V_10 += V_19 -> V_7 ;
V_74 ++ ;
}
if ( V_72 == 1 ) {
V_9 . V_31 = V_71 ;
V_9 . type = V_63 ;
V_9 . V_10 = V_54 - V_71 ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_58 ++ ;
}
if ( V_58 != V_57 ) {
F_28 ( V_18 , L_2 ,
V_19 -> V_9 . V_31 , V_58 ,
V_57 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_30 = 0 ;
V_33:
F_32 ( V_51 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
static int F_37 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
int V_76 )
{
struct V_25 * V_26 ;
T_1 V_56 ;
T_1 V_58 ;
int V_30 = 0 ;
if ( V_76 == 0 )
return 0 ;
V_26 = F_10 ( V_16 , V_18 , V_19 , V_21 , 1 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_56 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_58 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_58 += V_76 ;
F_6 ( V_21 -> V_34 [ 0 ] , V_26 , V_58 ) ;
F_8 ( V_21 -> V_34 [ 0 ] ) ;
F_9 ( V_21 ) ;
if ( ! ( V_56 & V_66 ) &&
V_58 > V_19 -> V_13 ) {
V_30 = F_20 ( V_16 , V_18 , V_19 ,
V_21 ) ;
} else if ( ( V_56 & V_66 ) &&
V_58 < V_19 -> V_14 ) {
V_30 = F_34 ( V_16 , V_18 , V_19 ,
V_21 ) ;
}
V_33:
return V_30 ;
}
int F_38 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_10 )
{
struct V_28 * V_29 ;
struct V_27 V_9 ;
T_3 V_77 , V_78 ;
unsigned long V_67 , V_55 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_21 ( V_29 , & V_9 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_9 . type == V_70 ) ;
V_77 = V_9 . V_31 ;
V_78 = V_9 . V_31 + V_9 . V_10 ;
ASSERT ( V_10 >= V_77 && V_10 < V_78 ) ;
V_67 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_55 = F_2 ( V_10 - V_77 , V_19 -> V_7 ) ;
return ! ! F_39 ( V_29 , V_67 , V_55 ) ;
}
static void F_40 ( struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 * V_53 , T_3 * V_41 ,
int V_73 )
{
struct V_28 * V_29 ;
struct V_27 V_9 ;
T_3 V_54 = * V_53 + * V_41 ;
T_3 V_77 , V_78 ;
unsigned long V_67 , V_64 , V_65 ;
V_29 = V_21 -> V_34 [ 0 ] ;
F_21 ( V_29 , & V_9 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_9 . type == V_70 ) ;
V_77 = V_9 . V_31 ;
V_78 = V_9 . V_31 + V_9 . V_10 ;
ASSERT ( * V_53 >= V_77 && * V_53 < V_78 ) ;
ASSERT ( V_54 > V_77 ) ;
if ( V_54 > V_78 )
V_54 = V_78 ;
V_67 = F_30 ( V_29 , V_21 -> V_35 [ 0 ] ) ;
V_64 = F_2 ( * V_53 - V_77 , V_19 -> V_7 ) ;
V_65 = F_2 ( V_54 - V_77 , V_19 -> V_7 ) ;
if ( V_73 )
F_41 ( V_29 , V_67 , V_64 , V_65 - V_64 ) ;
else
F_42 ( V_29 , V_67 , V_64 , V_65 - V_64 ) ;
F_8 ( V_29 ) ;
* V_41 -= V_54 - * V_53 ;
* V_53 = V_54 ;
}
static int F_43 ( struct V_15 * V_16 ,
struct V_22 * V_23 , struct V_20 * V_38 )
{
struct V_27 V_9 ;
if ( V_38 -> V_35 [ 0 ] + 1 < F_44 ( V_38 -> V_34 [ 0 ] ) ) {
V_38 -> V_35 [ 0 ] ++ ;
return 0 ;
}
F_21 ( V_38 -> V_34 [ 0 ] , & V_9 , V_38 -> V_35 [ 0 ] ) ;
F_9 ( V_38 ) ;
V_9 . V_31 += V_9 . V_10 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
return F_14 ( V_16 , V_23 , & V_9 , V_38 , 0 , 1 ) ;
}
static int F_45 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_53 , T_3 V_41 , int remove )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_27 V_9 ;
T_3 V_54 = V_53 + V_41 ;
T_3 V_79 , V_80 ;
int V_72 , V_81 ;
int V_76 ;
int V_30 ;
if ( V_53 > V_19 -> V_9 . V_31 ) {
T_3 V_82 = V_53 - V_19 -> V_7 ;
V_9 . V_31 = V_82 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_72 = F_38 ( V_19 , V_21 , V_82 ) ;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_53 >= V_9 . V_31 + V_9 . V_10 ) {
V_30 = F_43 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
} else {
V_9 . V_31 = V_53 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , 0 , 1 ) ;
if ( V_30 )
goto V_33;
V_72 = - 1 ;
}
V_79 = V_53 ;
V_80 = V_41 ;
while ( 1 ) {
F_40 ( V_19 , V_21 , & V_79 , & V_80 ,
! remove ) ;
if ( V_80 == 0 )
break;
V_30 = F_43 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
if ( V_54 < V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ) {
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_54 >= V_9 . V_31 + V_9 . V_10 ) {
V_30 = F_43 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
}
V_81 = F_38 ( V_19 , V_21 , V_54 ) ;
} else {
V_81 = - 1 ;
}
if ( remove ) {
V_76 = - 1 ;
if ( V_72 == 1 ) {
V_76 ++ ;
}
if ( V_81 == 1 ) {
V_76 ++ ;
}
} else {
V_76 = 1 ;
if ( V_72 == 1 ) {
V_76 -- ;
}
if ( V_81 == 1 ) {
V_76 -- ;
}
}
F_9 ( V_21 ) ;
V_30 = F_37 ( V_16 , V_18 , V_19 , V_21 ,
V_76 ) ;
V_33:
return V_30 ;
}
static int F_46 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_53 , T_3 V_41 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_27 V_9 ;
T_3 V_77 , V_78 ;
T_3 V_54 = V_53 + V_41 ;
int V_76 = - 1 ;
int V_30 ;
V_9 . V_31 = V_53 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
ASSERT ( V_9 . type == V_63 ) ;
V_77 = V_9 . V_31 ;
V_78 = V_9 . V_31 + V_9 . V_10 ;
ASSERT ( V_53 >= V_77 && V_54 <= V_78 ) ;
V_30 = F_47 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
if ( V_53 > V_77 ) {
V_9 . V_31 = V_77 ;
V_9 . type = V_63 ;
V_9 . V_10 = V_53 - V_77 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 , 0 ) ;
if ( V_30 )
goto V_33;
V_76 ++ ;
}
if ( V_54 < V_78 ) {
V_9 . V_31 = V_54 ;
V_9 . type = V_63 ;
V_9 . V_10 = V_78 - V_54 ;
F_9 ( V_21 ) ;
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_9 , 0 ) ;
if ( V_30 )
goto V_33;
V_76 ++ ;
}
F_9 ( V_21 ) ;
V_30 = F_37 ( V_16 , V_18 , V_19 , V_21 ,
V_76 ) ;
V_33:
return V_30 ;
}
int F_48 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_53 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_56 ;
int V_30 ;
if ( V_19 -> V_83 ) {
V_30 = F_49 ( V_16 , V_18 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_18 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_56 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_56 & V_66 ) {
return F_45 ( V_16 , V_18 , V_19 ,
V_21 , V_53 , V_41 , 1 ) ;
} else {
return F_46 ( V_16 , V_18 , V_19 ,
V_21 , V_53 , V_41 ) ;
}
}
int F_50 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_3 V_53 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_51 ( V_18 , V_84 ) )
return 0 ;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_61 ;
goto V_33;
}
V_19 = F_53 ( V_18 , V_53 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_54 ( & V_19 -> V_85 ) ;
V_30 = F_48 ( V_16 , V_18 , V_19 , V_21 ,
V_53 , V_41 ) ;
F_55 ( & V_19 -> V_85 ) ;
F_56 ( V_19 ) ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
static int F_58 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 ,
T_3 V_53 , T_3 V_41 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_27 V_9 , V_86 ;
T_3 V_77 , V_78 ;
T_3 V_54 = V_53 + V_41 ;
int V_76 = 1 ;
int V_30 ;
V_86 . V_31 = V_53 ;
V_86 . type = V_63 ;
V_86 . V_10 = V_41 ;
if ( V_53 == V_19 -> V_9 . V_31 )
goto V_87;
V_9 . V_31 = V_53 - 1 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_9 . type != V_63 ) {
ASSERT ( V_9 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_87;
}
V_77 = V_9 . V_31 ;
V_78 = V_9 . V_31 + V_9 . V_10 ;
ASSERT ( V_77 >= V_19 -> V_9 . V_31 &&
V_78 > V_19 -> V_9 . V_31 ) ;
ASSERT ( V_77 < V_53 && V_78 <= V_53 ) ;
if ( V_78 == V_53 ) {
V_30 = F_47 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_86 . V_31 = V_77 ;
V_86 . V_10 += V_9 . V_10 ;
V_76 -- ;
}
F_9 ( V_21 ) ;
V_87:
if ( V_54 == V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 )
goto V_88;
V_9 . V_31 = V_54 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_9 . type != V_63 ) {
ASSERT ( V_9 . type == V_32 ) ;
F_9 ( V_21 ) ;
goto V_88;
}
V_77 = V_9 . V_31 ;
V_78 = V_9 . V_31 + V_9 . V_10 ;
ASSERT ( V_77 >= V_19 -> V_9 . V_31 &&
V_78 > V_19 -> V_9 . V_31 ) ;
ASSERT ( ( V_77 < V_53 && V_78 <= V_53 ) ||
( V_77 >= V_54 && V_78 > V_54 ) ) ;
if ( V_77 == V_54 ) {
V_30 = F_47 ( V_16 , V_23 , V_21 ) ;
if ( V_30 )
goto V_33;
V_86 . V_10 += V_9 . V_10 ;
V_76 -- ;
}
F_9 ( V_21 ) ;
V_88:
V_30 = F_4 ( V_16 , V_23 , V_21 , & V_86 , 0 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
V_30 = F_37 ( V_16 , V_18 , V_19 , V_21 ,
V_76 ) ;
V_33:
return V_30 ;
}
int F_59 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 , T_3 V_53 , T_3 V_41 )
{
struct V_25 * V_26 ;
T_1 V_56 ;
int V_30 ;
if ( V_19 -> V_83 ) {
V_30 = F_49 ( V_16 , V_18 , V_19 ,
V_21 ) ;
if ( V_30 )
return V_30 ;
}
V_26 = F_10 ( NULL , V_18 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_56 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
F_9 ( V_21 ) ;
if ( V_56 & V_66 ) {
return F_45 ( V_16 , V_18 , V_19 ,
V_21 , V_53 , V_41 , 0 ) ;
} else {
return F_58 ( V_16 , V_18 , V_19 , V_21 ,
V_53 , V_41 ) ;
}
}
int F_60 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
T_3 V_53 , T_3 V_41 )
{
struct V_1 * V_19 ;
struct V_20 * V_21 ;
int V_30 ;
if ( ! F_51 ( V_18 , V_84 ) )
return 0 ;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_61 ;
goto V_33;
}
V_19 = F_53 ( V_18 , V_53 ) ;
if ( ! V_19 ) {
ASSERT ( 0 ) ;
V_30 = - V_37 ;
goto V_33;
}
F_54 ( & V_19 -> V_85 ) ;
V_30 = F_59 ( V_16 , V_18 , V_19 , V_21 , V_53 ,
V_41 ) ;
F_55 ( & V_19 -> V_85 ) ;
F_56 ( V_19 ) ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
static int F_61 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_22 * V_89 = V_18 -> V_89 ;
struct V_20 * V_21 , * V_90 ;
struct V_27 V_9 ;
T_3 V_53 , V_54 ;
int V_30 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_61 ;
V_21 -> V_91 = 1 ;
V_90 = F_52 () ;
if ( ! V_90 ) {
F_57 ( V_21 ) ;
return - V_61 ;
}
V_30 = F_3 ( V_16 , V_18 , V_19 , V_90 ) ;
if ( V_30 )
goto V_33;
F_54 ( & V_19 -> V_85 ) ;
V_9 . V_31 = V_19 -> V_9 . V_31 ;
V_9 . type = V_92 ;
V_9 . V_10 = 0 ;
V_30 = F_62 ( V_89 , & V_9 , V_21 , 1 , 0 ) ;
if ( V_30 < 0 )
goto V_93;
ASSERT ( V_30 == 0 ) ;
V_53 = V_19 -> V_9 . V_31 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
while ( 1 ) {
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_9 . type == V_92 ||
V_9 . type == V_94 ) {
if ( V_9 . V_31 >= V_54 )
break;
if ( V_53 < V_9 . V_31 ) {
V_30 = F_59 ( V_16 , V_18 ,
V_19 ,
V_90 , V_53 ,
V_9 . V_31 -
V_53 ) ;
if ( V_30 )
goto V_93;
}
V_53 = V_9 . V_31 ;
if ( V_9 . type == V_94 )
V_53 += V_18 -> V_95 -> V_96 ;
else
V_53 += V_9 . V_10 ;
} else if ( V_9 . type == V_97 ) {
if ( V_9 . V_31 != V_19 -> V_9 . V_31 )
break;
}
V_30 = F_63 ( V_89 , V_21 ) ;
if ( V_30 < 0 )
goto V_93;
if ( V_30 )
break;
}
if ( V_53 < V_54 ) {
V_30 = F_59 ( V_16 , V_18 , V_19 ,
V_90 , V_53 , V_54 - V_53 ) ;
if ( V_30 )
goto V_93;
}
V_30 = 0 ;
V_93:
F_55 ( & V_19 -> V_85 ) ;
V_33:
F_57 ( V_90 ) ;
F_57 ( V_21 ) ;
return V_30 ;
}
int F_64 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_22 * V_95 = V_18 -> V_95 ;
struct V_22 * V_24 ;
struct V_1 * V_19 ;
struct V_98 * V_99 ;
int V_30 ;
V_16 = F_65 ( V_95 , 0 ) ;
if ( F_24 ( V_16 ) )
return F_25 ( V_16 ) ;
V_18 -> V_100 = 1 ;
V_24 = F_66 ( V_16 , V_18 ,
V_101 ) ;
if ( F_24 ( V_24 ) ) {
V_30 = F_25 ( V_24 ) ;
goto abort;
}
V_18 -> V_24 = V_24 ;
V_99 = F_67 ( & V_18 -> V_102 ) ;
while ( V_99 ) {
V_19 = F_68 ( V_99 , struct V_1 ,
V_103 ) ;
V_30 = F_61 ( V_16 , V_18 , V_19 ) ;
if ( V_30 )
goto abort;
V_99 = F_69 ( V_99 ) ;
}
F_70 ( V_18 , V_84 ) ;
V_18 -> V_100 = 0 ;
V_30 = F_71 ( V_16 , V_95 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
abort:
V_18 -> V_100 = 0 ;
F_33 ( V_16 , V_30 ) ;
F_72 ( V_16 , V_95 ) ;
return V_30 ;
}
static int F_73 ( struct V_15 * V_16 ,
struct V_22 * V_23 )
{
struct V_20 * V_21 ;
struct V_27 V_9 ;
int V_60 ;
int V_30 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_61 ;
V_21 -> V_104 = 1 ;
V_9 . V_31 = 0 ;
V_9 . type = 0 ;
V_9 . V_10 = 0 ;
while ( 1 ) {
V_30 = F_11 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 < 0 )
goto V_33;
V_60 = F_44 ( V_21 -> V_34 [ 0 ] ) ;
if ( ! V_60 )
break;
V_21 -> V_35 [ 0 ] = 0 ;
V_30 = F_23 ( V_16 , V_23 , V_21 , 0 , V_60 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_57 ( V_21 ) ;
return V_30 ;
}
int F_74 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_22 * V_95 = V_18 -> V_95 ;
struct V_22 * V_24 = V_18 -> V_24 ;
int V_30 ;
V_16 = F_65 ( V_95 , 0 ) ;
if ( F_24 ( V_16 ) )
return F_25 ( V_16 ) ;
F_75 ( V_18 , V_84 ) ;
V_18 -> V_24 = NULL ;
V_30 = F_73 ( V_16 , V_24 ) ;
if ( V_30 )
goto abort;
V_30 = F_76 ( V_16 , V_95 , & V_24 -> V_105 ) ;
if ( V_30 )
goto abort;
F_77 ( & V_24 -> V_106 ) ;
F_78 ( V_24 -> V_99 ) ;
F_79 ( V_16 , V_95 -> V_18 , V_24 -> V_99 ) ;
F_80 ( V_24 -> V_99 ) ;
F_81 ( V_16 , V_24 , V_24 -> V_99 ,
0 , 1 ) ;
F_82 ( V_24 -> V_99 ) ;
F_82 ( V_24 -> V_107 ) ;
F_83 ( V_24 ) ;
V_30 = F_71 ( V_16 , V_95 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
abort:
F_33 ( V_16 , V_30 ) ;
F_72 ( V_16 , V_95 ) ;
return V_30 ;
}
static int F_49 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 ,
struct V_20 * V_21 )
{
T_3 V_53 , V_54 ;
int V_30 ;
V_53 = V_19 -> V_9 . V_31 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
V_19 -> V_83 = 0 ;
V_30 = F_3 ( V_16 , V_18 , V_19 , V_21 ) ;
if ( V_30 )
return V_30 ;
return F_59 ( V_16 , V_18 , V_19 , V_21 ,
V_19 -> V_9 . V_31 ,
V_19 -> V_9 . V_10 ) ;
}
int F_84 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 = NULL ;
int V_30 = 0 ;
if ( ! F_51 ( V_18 , V_84 ) )
return 0 ;
F_54 ( & V_19 -> V_85 ) ;
if ( ! V_19 -> V_83 )
goto V_33;
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_61 ;
goto V_33;
}
V_30 = F_49 ( V_16 , V_18 , V_19 , V_21 ) ;
V_33:
F_57 ( V_21 ) ;
F_55 ( & V_19 -> V_85 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
int F_85 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_22 * V_23 = V_18 -> V_24 ;
struct V_20 * V_21 ;
struct V_27 V_9 , V_50 ;
struct V_28 * V_29 ;
T_3 V_53 , V_54 ;
int V_59 = 0 , V_60 ;
int V_30 ;
if ( ! F_51 ( V_18 , V_84 ) )
return 0 ;
if ( V_19 -> V_83 ) {
return 0 ;
}
V_21 = F_52 () ;
if ( ! V_21 ) {
V_30 = - V_61 ;
goto V_33;
}
V_53 = V_19 -> V_9 . V_31 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
V_9 . V_31 = V_54 - 1 ;
V_9 . type = ( V_62 ) - 1 ;
V_9 . V_10 = ( T_3 ) - 1 ;
while ( ! V_59 ) {
V_30 = F_14 ( V_16 , V_23 , & V_9 , V_21 , - 1 , 1 ) ;
if ( V_30 )
goto V_33;
V_29 = V_21 -> V_34 [ 0 ] ;
V_60 = 0 ;
V_21 -> V_35 [ 0 ] ++ ;
while ( V_21 -> V_35 [ 0 ] > 0 ) {
F_21 ( V_29 , & V_50 , V_21 -> V_35 [ 0 ] - 1 ) ;
if ( V_50 . type == V_32 ) {
ASSERT ( V_50 . V_31 == V_19 -> V_9 . V_31 ) ;
ASSERT ( V_50 . V_10 == V_19 -> V_9 . V_10 ) ;
V_59 = 1 ;
V_60 ++ ;
V_21 -> V_35 [ 0 ] -- ;
break;
} else if ( V_50 . type == V_63 ||
V_50 . type == V_70 ) {
ASSERT ( V_50 . V_31 >= V_53 ) ;
ASSERT ( V_50 . V_31 < V_54 ) ;
ASSERT ( V_50 . V_31 + V_50 . V_10 <= V_54 ) ;
V_60 ++ ;
V_21 -> V_35 [ 0 ] -- ;
} else {
ASSERT ( 0 ) ;
}
}
V_30 = F_23 ( V_16 , V_23 , V_21 , V_21 -> V_35 [ 0 ] , V_60 ) ;
if ( V_30 )
goto V_33;
F_9 ( V_21 ) ;
}
V_30 = 0 ;
V_33:
F_57 ( V_21 ) ;
if ( V_30 )
F_33 ( V_16 , V_30 ) ;
return V_30 ;
}
static int F_86 ( struct V_108 * V_109 ,
struct V_20 * V_21 ,
T_1 V_57 )
{
struct V_1 * V_19 ;
struct V_17 * V_18 ;
struct V_22 * V_23 ;
struct V_27 V_9 ;
int V_72 = 0 , V_73 ;
T_3 V_71 = 0 ;
T_3 V_54 , V_10 ;
T_3 V_110 = 0 ;
T_1 V_58 = 0 ;
int V_30 ;
V_19 = V_109 -> V_19 ;
V_18 = V_19 -> V_18 ;
V_23 = V_18 -> V_24 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
while ( 1 ) {
V_30 = F_63 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_9 . type == V_32 )
break;
ASSERT ( V_9 . type == V_70 ) ;
ASSERT ( V_9 . V_31 < V_54 && V_9 . V_31 + V_9 . V_10 <= V_54 ) ;
V_109 -> V_111 = V_9 . V_31 ;
V_10 = V_9 . V_31 ;
while ( V_10 < V_9 . V_31 + V_9 . V_10 ) {
V_73 = F_38 ( V_19 , V_21 , V_10 ) ;
if ( V_72 == 0 && V_73 == 1 ) {
V_71 = V_10 ;
} else if ( V_72 == 1 && V_73 == 0 ) {
V_110 += F_87 ( V_19 ,
V_18 ,
V_71 ,
V_10 ) ;
if ( V_110 > V_112 ) {
V_110 = 0 ;
F_88 ( & V_109 -> V_113 ) ;
}
V_58 ++ ;
}
V_72 = V_73 ;
V_10 += V_19 -> V_7 ;
}
}
if ( V_72 == 1 ) {
V_110 += F_87 ( V_19 , V_18 ,
V_71 , V_54 ) ;
V_58 ++ ;
}
if ( V_58 != V_57 ) {
F_28 ( V_18 , L_2 ,
V_19 -> V_9 . V_31 , V_58 ,
V_57 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_109 -> V_111 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
static int F_89 ( struct V_108 * V_109 ,
struct V_20 * V_21 ,
T_1 V_57 )
{
struct V_1 * V_19 ;
struct V_17 * V_18 ;
struct V_22 * V_23 ;
struct V_27 V_9 ;
T_3 V_54 ;
T_3 V_110 = 0 ;
T_1 V_58 = 0 ;
int V_30 ;
V_19 = V_109 -> V_19 ;
V_18 = V_19 -> V_18 ;
V_23 = V_18 -> V_24 ;
V_54 = V_19 -> V_9 . V_31 + V_19 -> V_9 . V_10 ;
while ( 1 ) {
V_30 = F_63 ( V_23 , V_21 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_30 )
break;
F_21 ( V_21 -> V_34 [ 0 ] , & V_9 , V_21 -> V_35 [ 0 ] ) ;
if ( V_9 . type == V_32 )
break;
ASSERT ( V_9 . type == V_63 ) ;
ASSERT ( V_9 . V_31 < V_54 && V_9 . V_31 + V_9 . V_10 <= V_54 ) ;
V_109 -> V_111 = V_9 . V_31 ;
V_110 += F_87 ( V_19 , V_18 ,
V_9 . V_31 ,
V_9 . V_31 + V_9 . V_10 ) ;
if ( V_110 > V_112 ) {
V_110 = 0 ;
F_88 ( & V_109 -> V_113 ) ;
}
V_58 ++ ;
}
if ( V_58 != V_57 ) {
F_28 ( V_18 , L_2 ,
V_19 -> V_9 . V_31 , V_58 ,
V_57 ) ;
ASSERT ( 0 ) ;
V_30 = - V_40 ;
goto V_33;
}
V_109 -> V_111 = ( T_3 ) - 1 ;
V_30 = 0 ;
V_33:
return V_30 ;
}
int F_90 ( struct V_108 * V_109 )
{
struct V_1 * V_19 ;
struct V_17 * V_18 ;
struct V_25 * V_26 ;
struct V_20 * V_21 ;
T_1 V_58 , V_56 ;
int V_30 ;
V_19 = V_109 -> V_19 ;
V_18 = V_19 -> V_18 ;
V_21 = F_52 () ;
if ( ! V_21 )
return - V_61 ;
V_21 -> V_114 = 1 ;
V_21 -> V_115 = 1 ;
V_21 -> V_91 = 1 ;
V_26 = F_10 ( NULL , V_18 , V_19 , V_21 , 0 ) ;
if ( F_24 ( V_26 ) ) {
V_30 = F_25 ( V_26 ) ;
goto V_33;
}
V_58 = F_27 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
V_56 = F_26 ( V_21 -> V_34 [ 0 ] , V_26 ) ;
if ( V_56 & V_66 )
V_30 = F_86 ( V_109 , V_21 , V_58 ) ;
else
V_30 = F_89 ( V_109 , V_21 , V_58 ) ;
V_33:
F_57 ( V_21 ) ;
return V_30 ;
}
