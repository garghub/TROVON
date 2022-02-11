static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static T_1 F_2 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
T_3 V_12 = 0 , V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 ;
switch ( V_7 ) {
case V_17 :
V_12 = F_5 ( V_11 + V_18 ) ;
V_16 = F_5 ( V_11 + V_19 ) ;
V_15 = F_5 ( V_11 + V_20 ) ;
break;
case V_21 :
V_12 = F_5 ( V_11 + V_22 ) ;
V_16 = F_5 ( V_11 + V_23 ) & 0xffff ;
V_15 = F_5 ( V_11 + V_24 ) ;
break;
}
V_13 = V_16 >> 8 ;
V_14 = V_16 & 0xff ;
return ( ( ( ( T_1 ) V_12 * 24 + V_13 ) * 60 ) + V_14 ) * 60 + V_15 ;
}
static void F_6 ( struct V_5 * V_6 , int V_7 , T_1 time )
{
T_3 V_25 , V_12 , V_13 , V_14 , V_15 , V_26 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
V_12 = F_7 ( time , 86400 , & V_25 ) ;
V_13 = V_25 / 3600 ;
V_25 -= V_13 * 3600 ;
V_14 = V_25 / 60 ;
V_15 = V_25 - V_14 * 60 ;
V_26 = ( V_13 << 8 ) + V_14 ;
switch ( V_7 ) {
case V_17 :
F_8 ( V_12 , V_11 + V_18 ) ;
F_8 ( V_15 , V_11 + V_20 ) ;
F_8 ( V_26 , V_11 + V_19 ) ;
break;
case V_21 :
F_8 ( V_12 , V_11 + V_22 ) ;
F_8 ( V_15 , V_11 + V_24 ) ;
F_8 ( V_26 , V_11 + V_23 ) ;
break;
}
}
static void F_9 ( struct V_5 * V_6 , struct V_27 * V_28 )
{
T_1 time ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
time = F_10 ( V_28 ) ;
F_8 ( F_5 ( V_11 + V_29 ) , V_11 + V_29 ) ;
F_6 ( V_6 , V_21 , time ) ;
}
static void F_11 ( struct V_5 * V_6 , unsigned int V_30 ,
unsigned int V_31 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
T_3 V_32 ;
F_12 ( & V_10 -> V_33 -> V_34 ) ;
V_32 = F_5 ( V_11 + V_35 ) ;
if ( V_31 )
V_32 |= V_30 ;
else
V_32 &= ~ V_30 ;
F_8 ( V_32 , V_11 + V_35 ) ;
F_13 ( & V_10 -> V_33 -> V_34 ) ;
}
static T_4 F_14 ( int V_36 , void * V_37 )
{
struct V_8 * V_9 = V_37 ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
unsigned long V_38 ;
T_3 V_39 ;
T_3 V_40 = 0 ;
F_15 ( & V_10 -> V_33 -> V_34 , V_38 ) ;
V_39 = F_5 ( V_11 + V_29 ) & F_5 ( V_11 + V_35 ) ;
F_8 ( V_39 , V_11 + V_29 ) ;
if ( V_39 & V_41 ) {
V_40 |= ( V_42 | V_43 ) ;
F_11 ( & V_9 -> V_6 , V_41 , 0 ) ;
}
if ( V_39 & V_44 )
V_40 |= ( V_45 | V_43 ) ;
if ( V_39 & V_46 )
V_40 |= ( V_47 | V_43 ) ;
F_16 ( V_10 -> V_33 , 1 , V_40 ) ;
F_17 ( & V_10 -> V_33 -> V_34 , V_38 ) ;
return V_48 ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
F_12 ( & V_10 -> V_33 -> V_34 ) ;
F_8 ( 0 , V_11 + V_35 ) ;
F_8 ( 0xffffffff , V_11 + V_29 ) ;
F_13 ( & V_10 -> V_33 -> V_34 ) ;
}
static int F_19 ( struct V_5 * V_6 , unsigned int V_31 )
{
F_11 ( V_6 , V_41 , V_31 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_27 * V_49 )
{
T_1 V_50 ;
do {
V_50 = F_2 ( V_6 , V_17 ) ;
} while ( V_50 != F_2 ( V_6 , V_17 ) );
F_21 ( V_50 , V_49 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 , T_1 time )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
if ( F_1 ( V_10 ) ) {
struct V_27 V_49 ;
F_21 ( time , & V_49 ) ;
V_49 . V_51 = 70 ;
time = F_10 ( & V_49 ) ;
}
do {
F_6 ( V_6 , V_17 , time ) ;
} while ( time != F_2 ( V_6 , V_17 ) );
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_52 * V_28 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
F_21 ( F_2 ( V_6 , V_21 ) , & V_28 -> time ) ;
V_28 -> V_53 = ( ( F_5 ( V_11 + V_29 ) & V_41 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , struct V_52 * V_28 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
F_9 ( V_6 , & V_28 -> time ) ;
memcpy ( & V_10 -> V_54 , & V_28 -> time , sizeof( struct V_27 ) ) ;
F_11 ( V_6 , V_41 , V_28 -> V_31 ) ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_55 * V_56 ;
struct V_57 * V_33 ;
struct V_1 * V_10 = NULL ;
T_3 V_32 ;
unsigned long V_58 ;
int V_59 ;
const struct V_60 * V_61 ;
V_10 = F_26 ( & V_9 -> V_6 , sizeof( * V_10 ) , V_62 ) ;
if ( ! V_10 )
return - V_63 ;
V_61 = F_27 ( V_64 , & V_9 -> V_6 ) ;
if ( V_61 )
V_10 -> V_3 = (enum V_65 ) V_61 -> V_2 ;
else
V_10 -> V_3 = V_9 -> V_66 -> V_67 ;
V_56 = F_28 ( V_9 , V_68 , 0 ) ;
V_10 -> V_11 = F_29 ( & V_9 -> V_6 , V_56 ) ;
if ( F_30 ( V_10 -> V_11 ) )
return F_31 ( V_10 -> V_11 ) ;
V_10 -> V_69 = F_32 ( & V_9 -> V_6 , L_1 ) ;
if ( F_30 ( V_10 -> V_69 ) ) {
F_33 ( & V_9 -> V_6 , L_2 ) ;
return F_31 ( V_10 -> V_69 ) ;
}
V_59 = F_34 ( V_10 -> V_69 ) ;
if ( V_59 )
return V_59 ;
V_10 -> V_70 = F_32 ( & V_9 -> V_6 , L_3 ) ;
if ( F_30 ( V_10 -> V_70 ) ) {
F_33 ( & V_9 -> V_6 , L_4 ) ;
V_59 = F_31 ( V_10 -> V_70 ) ;
goto V_71;
}
V_59 = F_34 ( V_10 -> V_70 ) ;
if ( V_59 )
goto V_71;
V_58 = F_35 ( V_10 -> V_70 ) ;
if ( V_58 == 32768 )
V_32 = V_72 ;
else if ( V_58 == 32000 )
V_32 = V_73 ;
else if ( V_58 == 38400 )
V_32 = V_74 ;
else {
F_33 ( & V_9 -> V_6 , L_5 , V_58 ) ;
V_59 = - V_75 ;
goto V_76;
}
V_32 |= V_77 ;
F_8 ( V_32 , ( V_10 -> V_11 + V_78 ) ) ;
if ( ( ( F_5 ( V_10 -> V_11 + V_78 ) ) & V_77 ) == 0 ) {
F_33 ( & V_9 -> V_6 , L_6 ) ;
V_59 = - V_79 ;
goto V_76;
}
F_36 ( V_9 , V_10 ) ;
V_10 -> V_36 = F_37 ( V_9 , 0 ) ;
if ( V_10 -> V_36 >= 0 &&
F_38 ( & V_9 -> V_6 , V_10 -> V_36 , F_14 ,
V_80 , V_9 -> V_81 , V_9 ) < 0 ) {
F_39 ( & V_9 -> V_6 , L_7 ) ;
V_10 -> V_36 = - 1 ;
}
if ( V_10 -> V_36 >= 0 )
F_40 ( & V_9 -> V_6 , 1 ) ;
V_33 = F_41 ( & V_9 -> V_6 , V_9 -> V_81 , & V_82 ,
V_83 ) ;
if ( F_30 ( V_33 ) ) {
V_59 = F_31 ( V_33 ) ;
goto V_76;
}
V_10 -> V_33 = V_33 ;
return 0 ;
V_76:
F_42 ( V_10 -> V_70 ) ;
V_71:
F_42 ( V_10 -> V_69 ) ;
return V_59 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_4 ( V_9 ) ;
F_42 ( V_10 -> V_70 ) ;
F_42 ( V_10 -> V_69 ) ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_10 = F_45 ( V_6 ) ;
if ( F_46 ( V_6 ) )
F_47 ( V_10 -> V_36 ) ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_1 * V_10 = F_45 ( V_6 ) ;
if ( F_46 ( V_6 ) )
F_49 ( V_10 -> V_36 ) ;
return 0 ;
}
