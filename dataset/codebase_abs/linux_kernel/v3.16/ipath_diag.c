int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 16 ] ;
int V_4 = 0 ;
if ( F_2 ( & V_5 ) == 1 ) {
V_4 = F_3 ( V_6 ,
L_1 , & V_7 ,
& V_8 , & V_9 ) ;
if ( V_4 ) {
F_4 ( V_2 , L_2
L_3 , V_4 ) ;
goto V_10;
}
}
snprintf ( V_3 , sizeof( V_3 ) , L_4 , V_2 -> V_11 ) ;
V_4 = F_3 ( V_12 + V_2 -> V_11 , V_3 ,
& V_13 , & V_2 -> V_14 ,
& V_2 -> V_15 ) ;
if ( V_4 )
F_4 ( V_2 , L_5 ,
V_3 , V_4 ) ;
V_10:
return V_4 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_6 ( & V_5 ) )
F_7 ( & V_8 , & V_9 ) ;
F_7 ( & V_2 -> V_14 , & V_2 -> V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 , void T_1 * V_16 ,
const void T_2 * V_17 , T_3 V_18 )
{
const T_4 T_2 * V_19 = V_17 ;
const T_4 T_2 * V_20 = V_19 + ( V_18 / sizeof( T_4 ) ) ;
int V_4 ;
if ( V_19 < V_2 -> V_21 || V_20 > V_2 -> V_22 ) {
V_4 = - V_23 ;
goto V_24;
}
while ( V_19 < V_20 ) {
T_4 V_25 = F_9 ( V_19 ) ;
if ( F_10 ( V_16 , & V_25 , sizeof( T_4 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
V_19 ++ ;
V_16 += sizeof( T_4 ) ;
}
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 , void T_2 * V_17 ,
const void T_1 * V_16 , T_3 V_18 )
{
T_4 T_2 * V_19 = V_17 ;
const T_4 T_2 * V_20 = V_19 + ( V_18 / sizeof( T_4 ) ) ;
int V_4 ;
if ( V_19 < V_2 -> V_21 || V_20 > V_2 -> V_22 ) {
V_4 = - V_23 ;
goto V_24;
}
while ( V_19 < V_20 ) {
T_4 V_25 ;
if ( F_12 ( & V_25 , V_16 , sizeof( V_25 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
F_13 ( V_25 , V_19 ) ;
V_19 ++ ;
V_16 += sizeof( T_4 ) ;
}
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_14 ( struct V_1 * V_2 , void T_1 * V_16 ,
const void T_2 * V_17 , T_3 V_18 )
{
const T_5 T_2 * V_19 = V_17 ;
const T_5 T_2 * V_20 = V_19 + ( V_18 / sizeof( T_5 ) ) ;
int V_4 ;
if ( V_19 < ( T_5 T_2 * ) V_2 -> V_21 ||
V_20 > ( T_5 T_2 * ) V_2 -> V_22 ) {
V_4 = - V_23 ;
goto V_24;
}
while ( V_19 < V_20 ) {
T_5 V_25 = F_15 ( V_19 ) ;
if ( F_10 ( V_16 , & V_25 , sizeof( V_25 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
V_19 ++ ;
V_16 += sizeof( T_5 ) ;
}
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 , void T_2 * V_17 ,
const void T_1 * V_16 , T_3 V_18 )
{
T_5 T_2 * V_19 = V_17 ;
const T_5 T_2 * V_20 = V_19 + ( V_18 / sizeof( T_5 ) ) ;
int V_4 ;
if ( V_19 < ( T_5 T_2 * ) V_2 -> V_21 ||
V_20 > ( T_5 T_2 * ) V_2 -> V_22 ) {
V_4 = - V_23 ;
goto V_24;
}
while ( V_19 < V_20 ) {
T_5 V_25 ;
if ( F_12 ( & V_25 , V_16 , sizeof( V_25 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
F_17 ( V_25 , V_19 ) ;
V_19 ++ ;
V_16 += sizeof( T_5 ) ;
}
V_4 = 0 ;
V_24:
return V_4 ;
}
static int F_18 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
int V_31 = F_19 ( V_28 ) - V_12 ;
struct V_1 * V_2 ;
int V_4 ;
F_20 ( & V_32 ) ;
if ( V_33 ) {
V_4 = - V_34 ;
goto V_24;
}
V_2 = F_21 ( V_31 ) ;
if ( V_2 == NULL || ! ( V_2 -> V_35 & V_36 ) ||
! V_2 -> V_21 ) {
V_4 = - V_37 ;
goto V_24;
}
V_30 -> V_38 = V_2 ;
V_33 = - 2 ;
V_39 = 0 ;
V_4 = 0 ;
F_22 ( & V_2 -> V_40 -> V_41 ) ;
V_24:
F_23 ( & V_32 ) ;
return V_4 ;
}
static T_6 F_24 ( struct V_29 * V_30 ,
const char T_1 * V_25 ,
T_3 V_18 , T_7 * V_42 )
{
T_5 T_2 * V_43 ;
T_5 V_44 , V_45 , V_46 ;
struct V_47 V_48 ;
struct V_49 V_50 ;
T_5 * V_51 = NULL ;
struct V_1 * V_2 ;
T_6 V_4 = 0 ;
T_4 V_52 ;
T_5 V_53 , V_54 ;
if ( V_18 == sizeof( V_50 ) ) {
if ( F_12 ( & V_50 , V_25 , sizeof( V_50 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
} else if ( V_18 == sizeof( V_48 ) ) {
if ( F_12 ( & V_48 , V_25 , sizeof( V_48 ) ) ) {
V_4 = - V_26 ;
goto V_24;
}
V_50 . V_55 = V_48 . V_55 ;
V_50 . V_31 = V_48 . V_31 ;
V_50 . V_25 = V_48 . V_25 ;
V_50 . V_56 = 0 ;
} else {
V_4 = - V_23 ;
goto V_24;
}
if ( V_50 . V_55 & 3 ) {
V_4 = - V_23 ;
goto V_24;
}
V_44 = V_50 . V_55 >> 2 ;
V_2 = F_21 ( V_50 . V_31 ) ;
if ( ! V_2 || ! ( V_2 -> V_35 & V_36 ) ||
! V_2 -> V_21 ) {
F_25 ( V_57 , L_6 ,
V_50 . V_31 ) ;
V_4 = - V_37 ;
goto V_24;
}
if ( V_33 && ! V_39 &&
! ( V_2 -> V_35 & V_58 ) ) {
V_39 = 1 ;
F_25 ( V_57 , L_7
L_8 ) ;
F_26 ( V_2 , V_59 ) ;
F_26 ( V_2 , V_60 ) ;
}
if ( ! ( V_2 -> V_35 & V_61 ) ) {
F_25 ( V_57 , L_9 , V_2 -> V_11 ) ;
V_4 = - V_37 ;
goto V_24;
}
V_52 = F_27 ( V_2 , V_2 -> V_62 ) ;
V_54 = F_28 ( V_2 , V_2 -> V_62 ) ;
V_53 = F_29 ( V_2 , V_2 -> V_62 ) ;
if ( ! V_50 . V_56 && ( V_54 != V_63 ||
( V_52 != V_2 -> V_64 && V_52 != V_2 -> V_65 &&
V_52 != V_2 -> V_66 ) ) ) {
F_25 ( V_57 , L_10 ,
V_2 -> V_11 , ( unsigned long long ) V_52 ) ;
V_4 = - V_23 ;
goto V_24;
}
V_46 = 2 * sizeof( T_5 ) ;
if ( V_50 . V_55 > V_2 -> V_67 - V_46 ) {
F_30 ( L_11 ,
V_50 . V_55 , V_2 -> V_67 ) ;
V_4 = - V_23 ;
goto V_24;
}
V_44 = sizeof( T_5 ) + V_50 . V_55 ;
V_51 = F_31 ( V_44 ) ;
if ( ! V_51 ) {
F_32 ( & V_2 -> V_40 -> V_41 , L_12
L_13 ) ;
V_4 = - V_68 ;
goto V_24;
}
if ( F_12 ( V_51 ,
( const void T_1 * ) ( unsigned long ) V_50 . V_25 ,
V_50 . V_55 ) ) {
V_4 = - V_26 ;
goto V_24;
}
V_44 >>= 2 ;
V_43 = F_33 ( V_2 , V_44 , & V_45 ) ;
if ( ! V_43 ) {
F_25 ( V_57 , L_14 ,
V_2 -> V_11 ) ;
V_4 = - V_34 ;
goto V_24;
}
F_34 ( V_2 , V_45 , 1 ) ;
if ( V_69 & V_70 )
F_25 ( V_57 , L_15 ,
V_2 -> V_11 , V_44 - 1 , V_45 ) ;
if ( V_50 . V_56 == 0 )
V_50 . V_56 = V_44 ;
F_13 ( V_50 . V_56 , V_43 ) ;
if ( V_2 -> V_35 & V_71 ) {
F_35 () ;
F_36 ( V_43 + 2 , V_51 , V_44 - 1 ) ;
F_35 () ;
F_37 ( V_51 [ V_44 - 1 ] , V_43 + V_44 + 1 ) ;
} else
F_36 ( V_43 + 2 , V_51 , V_44 ) ;
F_35 () ;
V_4 = sizeof( V_50 ) ;
V_24:
F_38 ( V_51 ) ;
return V_4 ;
}
static int F_39 ( struct V_27 * V_28 , struct V_29 * V_30 )
{
F_20 ( & V_32 ) ;
V_33 = 0 ;
V_30 -> V_38 = NULL ;
F_23 ( & V_32 ) ;
return 0 ;
}
static T_6 F_40 ( struct V_29 * V_30 , char T_1 * V_25 ,
T_3 V_18 , T_7 * V_42 )
{
struct V_1 * V_2 = V_30 -> V_38 ;
void T_2 * V_72 ;
T_6 V_4 ;
V_72 = V_2 -> V_21 ;
if ( V_18 == 0 )
V_4 = 0 ;
else if ( ( V_18 % 4 ) || ( * V_42 % 4 ) )
V_4 = - V_23 ;
else if ( V_33 < 1 && ( * V_42 || V_18 != 8 ) )
V_4 = - V_23 ;
else if ( ( V_18 % 8 ) || ( * V_42 % 8 ) )
V_4 = F_14 ( V_2 , V_25 , V_72 + * V_42 , V_18 ) ;
else
V_4 = F_8 ( V_2 , V_25 , V_72 + * V_42 , V_18 ) ;
if ( V_4 >= 0 ) {
* V_42 += V_18 ;
V_4 = V_18 ;
if ( V_33 == - 2 )
V_33 ++ ;
}
return V_4 ;
}
static T_6 F_41 ( struct V_29 * V_30 , const char T_1 * V_25 ,
T_3 V_18 , T_7 * V_42 )
{
struct V_1 * V_2 = V_30 -> V_38 ;
void T_2 * V_72 ;
T_6 V_4 ;
V_72 = V_2 -> V_21 ;
if ( V_18 == 0 )
V_4 = 0 ;
else if ( ( V_18 % 4 ) || ( * V_42 % 4 ) )
V_4 = - V_23 ;
else if ( ( V_33 == - 1 && ( * V_42 || V_18 != 8 ) ) ||
V_33 == - 2 )
V_4 = - V_23 ;
else if ( ( V_18 % 8 ) || ( * V_42 % 8 ) )
V_4 = F_16 ( V_2 , V_72 + * V_42 , V_25 , V_18 ) ;
else
V_4 = F_11 ( V_2 , V_72 + * V_42 , V_25 , V_18 ) ;
if ( V_4 >= 0 ) {
* V_42 += V_18 ;
V_4 = V_18 ;
if ( V_33 == - 1 )
V_33 = 1 ;
}
return V_4 ;
}
