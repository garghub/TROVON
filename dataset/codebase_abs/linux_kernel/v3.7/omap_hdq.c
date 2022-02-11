static inline T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 -> V_3 + V_2 ) ;
}
static inline void F_3 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_4 )
{
F_4 ( V_4 , V_1 -> V_3 + V_2 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_1 , T_2 V_2 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = ( F_2 ( V_1 -> V_3 + V_2 ) & ~ V_5 )
| ( V_4 & V_5 ) ;
F_4 ( V_6 , V_1 -> V_3 + V_2 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_1 , T_2 V_2 ,
T_1 V_7 , T_1 V_8 , T_1 * V_9 )
{
int V_10 = 0 ;
unsigned long V_11 = V_12 + V_13 ;
if ( V_8 == V_14 ) {
while ( ( ( * V_9 = F_1 ( V_1 , V_2 ) ) & V_7 )
&& F_7 ( V_12 , V_11 ) ) {
F_8 ( 1 ) ;
}
if ( * V_9 & V_7 )
V_10 = - V_15 ;
} else if ( V_8 == V_16 ) {
while ( ! ( ( * V_9 = F_1 ( V_1 , V_2 ) ) & V_7 )
&& F_7 ( V_12 , V_11 ) ) {
F_8 ( 1 ) ;
}
if ( ! ( * V_9 & V_7 ) )
V_10 = - V_15 ;
} else
return - V_17 ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_4 , T_1 * V_9 )
{
int V_10 ;
T_1 V_18 ;
unsigned long V_19 ;
* V_9 = 0 ;
F_10 ( & V_1 -> V_20 , V_19 ) ;
F_1 ( V_1 , V_21 ) ;
V_1 -> V_22 = 0 ;
F_11 ( & V_1 -> V_20 , V_19 ) ;
F_3 ( V_1 , V_23 , V_4 ) ;
F_5 ( V_1 , V_24 , V_25 ,
V_26 | V_25 ) ;
V_10 = F_12 ( V_27 ,
V_1 -> V_22 , V_13 ) ;
if ( V_10 == 0 ) {
F_13 ( V_1 -> V_28 , L_1 ) ;
V_10 = - V_15 ;
goto V_29;
}
* V_9 = V_1 -> V_22 ;
if ( ! ( * V_9 & V_30 ) ) {
F_13 ( V_1 -> V_28 , L_2
L_3 , * V_9 ) ;
V_10 = - V_15 ;
goto V_29;
}
V_10 = F_6 ( V_1 , V_24 ,
V_25 ,
V_14 , & V_18 ) ;
if ( V_10 ) {
F_13 ( V_1 -> V_28 , L_4
L_5 , V_18 ) ;
}
V_29:
return V_10 ;
}
static T_3 F_14 ( int V_31 , void * V_32 )
{
struct V_1 * V_1 = V_32 ;
unsigned long V_19 ;
F_10 ( & V_1 -> V_20 , V_19 ) ;
V_1 -> V_22 = F_1 ( V_1 , V_21 ) ;
F_11 ( & V_1 -> V_20 , V_19 ) ;
F_13 ( V_1 -> V_28 , L_6 , V_1 -> V_22 ) ;
if ( V_1 -> V_22 &
( V_30 | V_33
| V_34 ) ) {
F_15 ( & V_27 ) ;
}
return V_35 ;
}
static T_1 F_16 ( void * V_32 )
{
return 0 ;
}
static void F_17 ( void * V_32 , struct V_36 * V_37 ,
T_1 V_38 , T_4 V_39 )
{
T_5 V_40 , V_41 , V_42 , V_43 ;
if ( V_44 )
V_40 = V_44 ;
else
V_40 = 0x1 ;
V_41 = F_18 ( V_40 ) ;
V_42 = F_19 ( ( T_1 * ) & V_41 , 7 ) ;
V_43 = ( V_42 << 56 ) | V_40 ;
V_39 ( V_37 , V_43 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_10 ;
T_1 V_18 ;
F_3 ( V_1 , V_45 , V_46 ) ;
F_3 ( V_1 , V_24 ,
V_47 |
V_48 ) ;
V_10 = F_6 ( V_1 , V_49 ,
V_50 , V_16 , & V_18 ) ;
if ( V_10 )
F_13 ( V_1 -> V_28 , L_7 ,
V_18 ) ;
else {
F_3 ( V_1 , V_24 ,
V_47 |
V_48 ) ;
F_3 ( V_1 , V_45 ,
V_51 ) ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_10 = 0 ;
T_1 V_18 ;
unsigned long V_19 ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_8 ) ;
V_10 = - V_53 ;
goto V_54;
}
F_10 ( & V_1 -> V_20 , V_19 ) ;
F_1 ( V_1 , V_21 ) ;
V_1 -> V_22 = 0 ;
F_11 ( & V_1 -> V_20 , V_19 ) ;
F_5 ( V_1 , V_24 ,
V_55 | V_25 ,
V_26 | V_55 |
V_25 ) ;
V_10 = F_12 ( V_27 ,
V_1 -> V_22 , V_13 ) ;
if ( V_10 == 0 ) {
F_13 ( V_1 -> V_28 , L_9 ) ;
V_10 = - V_53 ;
goto V_29;
}
V_18 = V_1 -> V_22 ;
if ( ! ( V_18 & V_34 ) ) {
F_13 ( V_1 -> V_28 , L_10 ,
V_18 ) ;
V_10 = - V_15 ;
goto V_29;
}
V_10 = F_6 ( V_1 , V_24 ,
V_55 |
V_25 , V_14 ,
& V_18 ) ;
if ( V_10 )
F_13 ( V_1 -> V_28 , L_11
L_5 , V_18 ) ;
V_29:
F_23 ( & V_1 -> V_52 ) ;
V_54:
return V_10 ;
}
static int F_24 ( struct V_1 * V_1 , T_1 * V_4 )
{
int V_10 = 0 ;
T_1 V_9 ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
V_10 = - V_53 ;
goto V_54;
}
if ( ! V_1 -> V_56 ) {
V_10 = - V_17 ;
goto V_29;
}
if ( ! ( V_1 -> V_22 & V_33 ) ) {
F_5 ( V_1 , V_24 ,
V_26 | V_25 ,
V_26 | V_25 ) ;
F_12 ( V_27 ,
( V_1 -> V_22
& V_33 ) ,
V_13 ) ;
F_5 ( V_1 , V_24 , 0 ,
V_26 ) ;
V_9 = V_1 -> V_22 ;
if ( ! ( V_9 & V_33 ) ) {
F_13 ( V_1 -> V_28 , L_2
L_12 , V_9 ) ;
V_10 = - V_15 ;
goto V_29;
}
}
* V_4 = F_1 ( V_1 , V_57 ) ;
V_29:
F_23 ( & V_1 -> V_52 ) ;
V_54:
return V_10 ;
}
static int F_25 ( struct V_1 * V_1 )
{
int V_10 = 0 ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
V_10 = - V_53 ;
goto V_54;
}
if ( V_58 == V_1 -> V_56 ) {
F_13 ( V_1 -> V_28 , L_13 ) ;
V_10 = - V_17 ;
goto V_29;
} else {
V_1 -> V_56 ++ ;
F_26 ( V_59 ) ;
if ( 1 == V_1 -> V_56 ) {
F_27 ( V_1 -> V_28 ) ;
if ( ! ( F_1 ( V_1 , V_49 ) &
V_50 ) ) {
V_10 = F_20 ( V_1 ) ;
if ( V_10 )
V_1 -> V_56 -- ;
} else {
F_3 ( V_1 , V_24 ,
V_47 |
V_48 ) ;
F_3 ( V_1 , V_45 ,
V_51 ) ;
F_1 ( V_1 , V_21 ) ;
}
}
}
V_29:
F_23 ( & V_1 -> V_52 ) ;
V_54:
return V_10 ;
}
static int F_28 ( struct V_1 * V_1 )
{
int V_10 = 0 ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 )
return - V_53 ;
if ( 0 == V_1 -> V_56 ) {
F_13 ( V_1 -> V_28 , L_14
L_15 ) ;
V_10 = - V_17 ;
} else {
V_1 -> V_56 -- ;
F_29 ( V_59 ) ;
if ( 0 == V_1 -> V_56 )
F_30 ( V_1 -> V_28 ) ;
}
F_23 ( & V_1 -> V_52 ) ;
return V_10 ;
}
static T_1 F_31 ( void * V_32 )
{
struct V_1 * V_1 = V_32 ;
T_1 V_4 = 0 ;
int V_10 ;
V_10 = F_24 ( V_1 , & V_4 ) ;
if ( V_10 ) {
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_8 ) ;
return - V_53 ;
}
V_1 -> V_60 = 0 ;
F_23 ( & V_1 -> V_52 ) ;
F_28 ( V_1 ) ;
return - 1 ;
}
if ( V_1 -> V_60 ) {
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_8 ) ;
return - V_53 ;
}
V_1 -> V_60 = 0 ;
F_23 ( & V_1 -> V_52 ) ;
F_28 ( V_1 ) ;
}
return V_4 ;
}
static void F_32 ( void * V_32 , T_1 V_61 )
{
struct V_1 * V_1 = V_32 ;
int V_10 ;
T_1 V_9 ;
if ( V_1 -> V_60 == 0 )
F_25 ( V_1 ) ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_8 ) ;
return;
}
V_1 -> V_60 ++ ;
F_23 ( & V_1 -> V_52 ) ;
V_10 = F_9 ( V_1 , V_61 , & V_9 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_16 , V_9 ) ;
return;
}
if ( V_1 -> V_60 > 1 ) {
F_28 ( V_1 ) ;
V_10 = F_22 ( & V_1 -> V_52 ) ;
if ( V_10 < 0 ) {
F_13 ( V_1 -> V_28 , L_8 ) ;
return;
}
V_1 -> V_60 = 0 ;
F_23 ( & V_1 -> V_52 ) ;
}
}
static int T_6 F_33 ( struct V_62 * V_63 )
{
struct V_64 * V_28 = & V_63 -> V_28 ;
struct V_1 * V_1 ;
struct V_65 * V_66 ;
int V_10 , V_31 ;
T_1 V_67 ;
V_1 = F_34 ( V_28 , sizeof( * V_1 ) , V_68 ) ;
if ( ! V_1 ) {
F_13 ( & V_63 -> V_28 , L_17 ) ;
return - V_69 ;
}
V_1 -> V_28 = V_28 ;
F_35 ( V_63 , V_1 ) ;
V_66 = F_36 ( V_63 , V_70 , 0 ) ;
if ( ! V_66 ) {
F_13 ( & V_63 -> V_28 , L_18 ) ;
return - V_71 ;
}
V_1 -> V_3 = F_37 ( V_28 , V_66 ) ;
if ( ! V_1 -> V_3 ) {
F_13 ( & V_63 -> V_28 , L_19 ) ;
return - V_69 ;
}
V_1 -> V_56 = 0 ;
F_38 ( & V_1 -> V_52 ) ;
F_39 ( & V_63 -> V_28 ) ;
F_27 ( & V_63 -> V_28 ) ;
V_67 = F_1 ( V_1 , V_72 ) ;
F_40 ( & V_63 -> V_28 , L_20 ,
( V_67 >> 4 ) + '0' , ( V_67 & 0x0f ) + '0' , L_21 ) ;
F_41 ( & V_1 -> V_20 ) ;
V_31 = F_42 ( V_63 , 0 ) ;
if ( V_31 < 0 ) {
V_10 = - V_71 ;
goto V_73;
}
V_10 = F_43 ( V_28 , V_31 , F_14 , V_74 ,
L_22 , V_1 ) ;
if ( V_10 < 0 ) {
F_13 ( & V_63 -> V_28 , L_23 ) ;
goto V_73;
}
F_21 ( V_1 ) ;
F_30 ( & V_63 -> V_28 ) ;
V_75 . V_76 = V_1 ;
V_10 = F_44 ( & V_75 ) ;
if ( V_10 ) {
F_13 ( & V_63 -> V_28 , L_24 ) ;
goto V_77;
}
return 0 ;
V_73:
F_30 ( & V_63 -> V_28 ) ;
V_77:
F_45 ( & V_63 -> V_28 ) ;
return V_10 ;
}
static int T_7 F_46 ( struct V_62 * V_63 )
{
struct V_1 * V_1 = F_47 ( V_63 ) ;
F_48 ( & V_1 -> V_52 ) ;
if ( V_1 -> V_56 ) {
F_13 ( & V_63 -> V_28 , L_25 ) ;
F_23 ( & V_1 -> V_52 ) ;
return - V_78 ;
}
F_23 ( & V_1 -> V_52 ) ;
F_45 ( & V_63 -> V_28 ) ;
return 0 ;
}
