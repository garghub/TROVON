static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static T_1 F_2 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
T_1 V_12 = 0 , V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 ;
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
return ( ( ( V_12 * 24 + V_13 ) * 60 ) + V_14 ) * 60 + V_15 ;
}
static void F_6 ( struct V_5 * V_6 , int V_7 , T_1 time )
{
T_1 V_12 , V_13 , V_14 , V_15 , V_25 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
V_12 = time / 86400 ;
time -= V_12 * 86400 ;
V_13 = time / 3600 ;
time -= V_13 * 3600 ;
V_14 = time / 60 ;
V_15 = time - V_14 * 60 ;
V_25 = ( V_13 << 8 ) + V_14 ;
switch ( V_7 ) {
case V_17 :
F_7 ( V_12 , V_11 + V_18 ) ;
F_7 ( V_15 , V_11 + V_20 ) ;
F_7 ( V_25 , V_11 + V_19 ) ;
break;
case V_21 :
F_7 ( V_12 , V_11 + V_22 ) ;
F_7 ( V_15 , V_11 + V_24 ) ;
F_7 ( V_25 , V_11 + V_23 ) ;
break;
}
}
static int F_8 ( struct V_5 * V_6 , struct V_26 * V_27 )
{
struct V_26 V_28 , V_29 ;
unsigned long V_30 , time ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
V_30 = F_2 ( V_6 , V_17 ) ;
F_9 ( V_30 , & V_29 ) ;
V_28 . V_31 = V_29 . V_31 ;
V_28 . V_32 = V_29 . V_32 ;
V_28 . V_33 = V_29 . V_33 ;
V_28 . V_34 = V_27 -> V_34 ;
V_28 . V_35 = V_27 -> V_35 ;
V_28 . V_36 = V_27 -> V_36 ;
F_10 ( & V_28 , & time ) ;
F_7 ( F_5 ( V_11 + V_37 ) , V_11 + V_37 ) ;
F_6 ( V_6 , V_21 , time ) ;
return 0 ;
}
static void F_11 ( struct V_5 * V_6 , unsigned int V_38 ,
unsigned int V_39 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
T_1 V_40 ;
F_12 ( & V_10 -> V_41 -> V_42 ) ;
V_40 = F_5 ( V_11 + V_43 ) ;
if ( V_39 )
V_40 |= V_38 ;
else
V_40 &= ~ V_38 ;
F_7 ( V_40 , V_11 + V_43 ) ;
F_13 ( & V_10 -> V_41 -> V_42 ) ;
}
static T_3 F_14 ( int V_44 , void * V_45 )
{
struct V_8 * V_9 = V_45 ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
unsigned long V_46 ;
T_1 V_47 ;
T_1 V_48 = 0 ;
F_15 ( & V_10 -> V_41 -> V_42 , V_46 ) ;
V_47 = F_5 ( V_11 + V_37 ) & F_5 ( V_11 + V_43 ) ;
F_7 ( V_47 , V_11 + V_37 ) ;
if ( V_47 & V_49 ) {
V_48 |= ( V_50 | V_51 ) ;
F_11 ( & V_9 -> V_6 , V_49 , 0 ) ;
}
if ( V_47 & V_52 )
V_48 |= ( V_53 | V_51 ) ;
if ( V_47 & V_54 )
V_48 |= ( V_55 | V_51 ) ;
F_16 ( V_10 -> V_41 , 1 , V_48 ) ;
F_17 ( & V_10 -> V_41 -> V_42 , V_46 ) ;
return V_56 ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
F_12 ( & V_10 -> V_41 -> V_42 ) ;
F_7 ( 0 , V_11 + V_43 ) ;
F_7 ( 0xffffffff , V_11 + V_37 ) ;
F_13 ( & V_10 -> V_41 -> V_42 ) ;
}
static int F_19 ( struct V_5 * V_6 , unsigned int V_39 )
{
F_11 ( V_6 , V_49 , V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_26 * V_57 )
{
T_1 V_58 ;
do {
V_58 = F_2 ( V_6 , V_17 ) ;
} while ( V_58 != F_2 ( V_6 , V_17 ) );
F_9 ( V_58 , V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , unsigned long time )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
if ( F_1 ( V_10 ) ) {
struct V_26 V_57 ;
F_9 ( time , & V_57 ) ;
V_57 . V_31 = 70 ;
F_10 ( & V_57 , & time ) ;
}
do {
F_6 ( V_6 , V_17 , time ) ;
} while ( time != F_2 ( V_6 , V_17 ) );
return 0 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_59 * V_27 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
void T_2 * V_11 = V_10 -> V_11 ;
F_9 ( F_2 ( V_6 , V_21 ) , & V_27 -> time ) ;
V_27 -> V_60 = ( ( F_5 ( V_11 + V_37 ) & V_49 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_59 * V_27 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_1 * V_10 = F_4 ( V_9 ) ;
int V_61 ;
V_61 = F_8 ( V_6 , & V_27 -> time ) ;
if ( V_61 )
return V_61 ;
memcpy ( & V_10 -> V_62 , & V_27 -> time , sizeof( struct V_26 ) ) ;
F_11 ( V_6 , V_49 , V_27 -> V_39 ) ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_63 * V_64 ;
struct V_65 * V_41 ;
struct V_1 * V_10 = NULL ;
T_1 V_40 ;
unsigned long V_66 ;
int V_61 ;
V_10 = F_25 ( & V_9 -> V_6 , sizeof( * V_10 ) , V_67 ) ;
if ( ! V_10 )
return - V_68 ;
V_10 -> V_3 = V_9 -> V_69 -> V_70 ;
V_64 = F_26 ( V_9 , V_71 , 0 ) ;
V_10 -> V_11 = F_27 ( & V_9 -> V_6 , V_64 ) ;
if ( F_28 ( V_10 -> V_11 ) )
return F_29 ( V_10 -> V_11 ) ;
V_10 -> V_72 = F_30 ( & V_9 -> V_6 , NULL ) ;
if ( F_28 ( V_10 -> V_72 ) ) {
F_31 ( & V_9 -> V_6 , L_1 ) ;
return F_29 ( V_10 -> V_72 ) ;
}
V_61 = F_32 ( V_10 -> V_72 ) ;
if ( V_61 )
return V_61 ;
V_66 = F_33 ( V_10 -> V_72 ) ;
if ( V_66 == 32768 )
V_40 = V_73 ;
else if ( V_66 == 32000 )
V_40 = V_74 ;
else if ( V_66 == 38400 )
V_40 = V_75 ;
else {
F_31 ( & V_9 -> V_6 , L_2 , V_66 ) ;
V_61 = - V_76 ;
goto V_77;
}
V_40 |= V_78 ;
F_7 ( V_40 , ( V_10 -> V_11 + V_79 ) ) ;
if ( ( ( F_5 ( V_10 -> V_11 + V_79 ) ) & V_78 ) == 0 ) {
F_31 ( & V_9 -> V_6 , L_3 ) ;
V_61 = - V_80 ;
goto V_77;
}
F_34 ( V_9 , V_10 ) ;
V_10 -> V_44 = F_35 ( V_9 , 0 ) ;
if ( V_10 -> V_44 >= 0 &&
F_36 ( & V_9 -> V_6 , V_10 -> V_44 , F_14 ,
V_81 , V_9 -> V_82 , V_9 ) < 0 ) {
F_37 ( & V_9 -> V_6 , L_4 ) ;
V_10 -> V_44 = - 1 ;
}
if ( V_10 -> V_44 >= 0 )
F_38 ( & V_9 -> V_6 , 1 ) ;
V_41 = F_39 ( & V_9 -> V_6 , V_9 -> V_82 , & V_83 ,
V_84 ) ;
if ( F_28 ( V_41 ) ) {
V_61 = F_29 ( V_41 ) ;
goto V_77;
}
V_10 -> V_41 = V_41 ;
return 0 ;
V_77:
F_40 ( V_10 -> V_72 ) ;
return V_61 ;
}
static int F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_4 ( V_9 ) ;
F_40 ( V_10 -> V_72 ) ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 )
{
struct V_1 * V_10 = F_43 ( V_6 ) ;
if ( F_44 ( V_6 ) )
F_45 ( V_10 -> V_44 ) ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_10 = F_43 ( V_6 ) ;
if ( F_44 ( V_6 ) )
F_47 ( V_10 -> V_44 ) ;
return 0 ;
}
