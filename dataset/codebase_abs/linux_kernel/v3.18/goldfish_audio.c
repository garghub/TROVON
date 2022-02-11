static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 ;
int V_10 = 0 ;
if ( ! V_7 -> V_11 )
return - V_12 ;
while ( V_4 > 0 ) {
V_9 = ( V_4 > V_13 ? V_13 : V_4 ) ;
F_2 ( V_7 , V_14 , V_9 ) ;
F_3 ( V_7 -> V_15 , ( V_7 -> V_16 &
V_17 ) ) ;
V_9 = F_4 ( V_7 , V_18 ) ;
if ( F_5 ( V_3 , V_7 -> V_19 , V_9 ) )
return - V_20 ;
V_10 += V_9 ;
V_3 += V_9 ;
V_4 -= V_9 ;
}
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_21 ;
T_1 V_10 = 0 ;
char T_5 * V_22 ;
while ( V_4 > 0 ) {
T_1 V_23 = V_4 ;
if ( V_23 > V_24 )
V_23 = V_24 ;
F_3 ( V_7 -> V_15 , ( V_7 -> V_16 &
( V_25 |
V_26 ) ) ) ;
if ( ( V_7 -> V_16 & V_25 ) != 0 )
V_22 = V_7 -> V_27 ;
else
V_22 = V_7 -> V_28 ;
if ( F_7 ( V_22 , V_3 , V_23 ) ) {
V_10 = - V_20 ;
break;
}
F_8 ( & V_7 -> V_29 , V_21 ) ;
if ( V_22 == V_7 -> V_27 ) {
V_7 -> V_16 &= ~ V_25 ;
F_2 ( V_7 , V_30 , V_23 ) ;
} else {
V_7 -> V_16 &= ~ V_26 ;
F_2 ( V_7 , V_31 , V_23 ) ;
}
F_9 ( & V_7 -> V_29 , V_21 ) ;
V_3 += V_23 ;
V_10 += V_23 ;
V_4 -= V_23 ;
}
return V_10 ;
}
static int F_10 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
if ( ! V_34 )
return - V_12 ;
if ( F_11 ( & V_35 ) == 1 ) {
V_2 -> V_8 = V_34 ;
V_34 -> V_16 = ( V_25 |
V_26 ) ;
F_2 ( V_34 , V_36 , V_37 ) ;
return 0 ;
}
F_12 ( & V_35 ) ;
return - V_38 ;
}
static int F_13 ( struct V_32 * V_33 , struct V_1 * V_2 )
{
F_12 ( & V_35 ) ;
F_2 ( V_34 , V_36 , 0 ) ;
return 0 ;
}
static long F_14 ( struct V_1 * V_2 , unsigned int V_39 ,
unsigned long V_40 )
{
if ( V_39 == 315 )
return - 1 ;
return 0 ;
}
static T_6 F_15 ( int V_41 , void * V_42 )
{
unsigned long V_21 ;
struct V_6 * V_7 = V_42 ;
T_7 V_43 ;
F_8 ( & V_7 -> V_29 , V_21 ) ;
V_43 = F_4 ( V_7 , V_44 ) ;
V_43 &= V_37 ;
if ( V_43 ) {
V_7 -> V_16 = V_43 ;
F_16 ( & V_7 -> V_15 ) ;
}
F_9 ( & V_7 -> V_29 , V_21 ) ;
return V_43 ? V_45 : V_46 ;
}
static int F_17 ( struct V_47 * V_48 )
{
int V_49 ;
struct V_50 * V_51 ;
struct V_6 * V_7 ;
T_8 V_52 ;
V_7 = F_18 ( & V_48 -> V_53 , sizeof( * V_7 ) , V_54 ) ;
if ( V_7 == NULL )
return - V_55 ;
F_19 ( & V_7 -> V_29 ) ;
F_20 ( & V_7 -> V_15 ) ;
F_21 ( V_48 , V_7 ) ;
V_51 = F_22 ( V_48 , V_56 , 0 ) ;
if ( V_51 == NULL ) {
F_23 ( & V_48 -> V_53 , L_1 ) ;
return - V_12 ;
}
V_7 -> V_57 = F_24 ( & V_48 -> V_53 , V_51 -> V_58 , V_59 ) ;
if ( V_7 -> V_57 == NULL )
return - V_55 ;
V_7 -> V_41 = F_25 ( V_48 , 0 ) ;
if ( V_7 -> V_41 < 0 ) {
F_23 ( & V_48 -> V_53 , L_2 ) ;
return - V_12 ;
}
V_7 -> V_60 = F_26 ( & V_48 -> V_53 ,
V_61 , & V_52 , V_54 ) ;
if ( V_7 -> V_60 == NULL ) {
F_23 ( & V_48 -> V_53 , L_3 ) ;
return - V_55 ;
}
V_7 -> V_62 = V_52 ;
V_7 -> V_27 = V_7 -> V_60 ;
V_7 -> V_28 = V_7 -> V_60 + V_24 ;
V_7 -> V_19 = V_7 -> V_60 + 2 * V_24 ;
V_49 = F_27 ( & V_48 -> V_53 , V_7 -> V_41 , F_15 ,
V_63 , V_48 -> V_64 , V_7 ) ;
if ( V_49 ) {
F_23 ( & V_48 -> V_53 , L_4 ) ;
return V_49 ;
}
V_49 = F_28 ( & V_65 ) ;
if ( V_49 ) {
F_23 ( & V_48 -> V_53 ,
L_5 ,
V_49 ) ;
return V_49 ;
}
F_29 ( V_7 , V_66 ,
V_67 , V_52 ) ;
V_52 += V_24 ;
F_29 ( V_7 , V_68 ,
V_69 , V_52 ) ;
V_52 += V_24 ;
V_7 -> V_11 = F_4 ( V_7 , V_70 ) ;
if ( V_7 -> V_11 )
F_29 ( V_7 , V_71 ,
V_72 , V_52 ) ;
V_34 = V_7 ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 )
{
F_31 ( & V_65 ) ;
V_34 = NULL ;
return 0 ;
}
