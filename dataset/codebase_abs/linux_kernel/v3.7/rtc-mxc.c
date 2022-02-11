static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
T_1 V_9 = 0 , V_10 = 0 , V_11 = 0 , V_12 = 0 , V_13 = 0 ;
switch ( V_3 ) {
case V_14 :
V_9 = F_4 ( V_8 + V_15 ) ;
V_13 = F_4 ( V_8 + V_16 ) ;
V_12 = F_4 ( V_8 + V_17 ) ;
break;
case V_18 :
V_9 = F_4 ( V_8 + V_19 ) ;
V_13 = F_4 ( V_8 + V_20 ) & 0xffff ;
V_12 = F_4 ( V_8 + V_21 ) ;
break;
}
V_10 = V_13 >> 8 ;
V_11 = V_13 & 0xff ;
return ( ( ( V_9 * 24 + V_10 ) * 60 ) + V_11 ) * 60 + V_12 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , T_1 time )
{
T_1 V_9 , V_10 , V_11 , V_12 , V_22 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
V_9 = time / 86400 ;
time -= V_9 * 86400 ;
V_10 = time / 3600 ;
time -= V_10 * 3600 ;
V_11 = time / 60 ;
V_12 = time - V_11 * 60 ;
V_22 = ( V_10 << 8 ) + V_11 ;
switch ( V_3 ) {
case V_14 :
F_6 ( V_9 , V_8 + V_15 ) ;
F_6 ( V_12 , V_8 + V_17 ) ;
F_6 ( V_22 , V_8 + V_16 ) ;
break;
case V_18 :
F_6 ( V_9 , V_8 + V_19 ) ;
F_6 ( V_12 , V_8 + V_21 ) ;
F_6 ( V_22 , V_8 + V_20 ) ;
break;
}
}
static int F_7 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_23 V_25 , V_26 ;
unsigned long V_27 , time ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
V_27 = F_1 ( V_2 , V_14 ) ;
F_8 ( V_27 , & V_26 ) ;
V_25 . V_28 = V_26 . V_28 ;
V_25 . V_29 = V_26 . V_29 ;
V_25 . V_30 = V_26 . V_30 ;
V_25 . V_31 = V_24 -> V_31 ;
V_25 . V_32 = V_24 -> V_32 ;
V_25 . V_33 = V_24 -> V_33 ;
F_9 ( & V_25 , & time ) ;
F_6 ( F_4 ( V_8 + V_34 ) , V_8 + V_34 ) ;
F_5 ( V_2 , V_18 , time ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_35 ,
unsigned int V_36 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
T_1 V_37 ;
F_11 ( & V_7 -> V_38 -> V_39 ) ;
V_37 = F_4 ( V_8 + V_40 ) ;
if ( V_36 )
V_37 |= V_35 ;
else
V_37 &= ~ V_35 ;
F_6 ( V_37 , V_8 + V_40 ) ;
F_12 ( & V_7 -> V_38 -> V_39 ) ;
}
static T_3 F_13 ( int V_41 , void * V_42 )
{
struct V_4 * V_5 = V_42 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
unsigned long V_43 ;
T_1 V_44 ;
T_1 V_45 = 0 ;
F_14 ( & V_7 -> V_38 -> V_39 , V_43 ) ;
V_44 = F_4 ( V_8 + V_34 ) & F_4 ( V_8 + V_40 ) ;
F_6 ( V_44 , V_8 + V_34 ) ;
if ( V_44 & V_46 ) {
V_45 |= ( V_47 | V_48 ) ;
F_10 ( & V_5 -> V_2 , V_46 , 0 ) ;
}
if ( V_44 & V_49 )
V_45 |= ( V_50 | V_48 ) ;
if ( V_44 & V_51 )
V_45 |= ( V_52 | V_48 ) ;
F_15 ( V_7 -> V_38 , 1 , V_45 ) ;
F_16 ( & V_7 -> V_38 -> V_39 , V_43 ) ;
return V_53 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_11 ( & V_7 -> V_38 -> V_39 ) ;
F_6 ( 0 , V_8 + V_40 ) ;
F_6 ( 0xffffffff , V_8 + V_34 ) ;
F_12 ( & V_7 -> V_38 -> V_39 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_36 )
{
F_10 ( V_2 , V_46 , V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_23 * V_54 )
{
T_1 V_55 ;
do {
V_55 = F_1 ( V_2 , V_14 ) ;
} while ( V_55 != F_1 ( V_2 , V_14 ) );
F_8 ( V_55 , V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , unsigned long time )
{
if ( F_21 () ) {
struct V_23 V_54 ;
F_8 ( time , & V_54 ) ;
V_54 . V_28 = 70 ;
F_9 ( & V_54 , & time ) ;
}
do {
F_5 ( V_2 , V_14 , time ) ;
} while ( time != F_1 ( V_2 , V_14 ) );
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_56 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_8 ( F_1 ( V_2 , V_18 ) , & V_24 -> time ) ;
V_24 -> V_57 = ( ( F_4 ( V_8 + V_34 ) & V_46 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_56 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_58 ;
V_58 = F_7 ( V_2 , & V_24 -> time ) ;
if ( V_58 )
return V_58 ;
memcpy ( & V_7 -> V_59 , & V_24 -> time , sizeof( struct V_23 ) ) ;
F_10 ( V_2 , V_46 , V_24 -> V_36 ) ;
return 0 ;
}
static int T_4 F_24 ( struct V_4 * V_5 )
{
struct V_60 * V_61 ;
struct V_62 * V_38 ;
struct V_6 * V_7 = NULL ;
T_1 V_37 ;
unsigned long V_63 ;
int V_58 ;
V_61 = F_25 ( V_5 , V_64 , 0 ) ;
if ( ! V_61 )
return - V_65 ;
V_7 = F_26 ( & V_5 -> V_2 , sizeof( * V_7 ) , V_66 ) ;
if ( ! V_7 )
return - V_67 ;
if ( ! F_27 ( & V_5 -> V_2 , V_61 -> V_68 ,
F_28 ( V_61 ) , V_5 -> V_69 ) )
return - V_70 ;
V_7 -> V_8 = F_29 ( & V_5 -> V_2 , V_61 -> V_68 ,
F_28 ( V_61 ) ) ;
V_7 -> V_71 = F_30 ( & V_5 -> V_2 , NULL ) ;
if ( F_31 ( V_7 -> V_71 ) ) {
F_32 ( & V_5 -> V_2 , L_1 ) ;
V_58 = F_33 ( V_7 -> V_71 ) ;
goto V_72;
}
F_34 ( V_7 -> V_71 ) ;
V_63 = F_35 ( V_7 -> V_71 ) ;
if ( V_63 == 32768 )
V_37 = V_73 ;
else if ( V_63 == 32000 )
V_37 = V_74 ;
else if ( V_63 == 38400 )
V_37 = V_75 ;
else {
F_32 ( & V_5 -> V_2 , L_2 , V_63 ) ;
V_58 = - V_76 ;
goto V_77;
}
V_37 |= V_78 ;
F_6 ( V_37 , ( V_7 -> V_8 + V_79 ) ) ;
if ( ( ( F_4 ( V_7 -> V_8 + V_79 ) ) & V_78 ) == 0 ) {
F_32 ( & V_5 -> V_2 , L_3 ) ;
V_58 = - V_80 ;
goto V_77;
}
F_36 ( V_5 , V_7 ) ;
V_7 -> V_41 = F_37 ( V_5 , 0 ) ;
if ( V_7 -> V_41 >= 0 &&
F_38 ( & V_5 -> V_2 , V_7 -> V_41 , F_13 ,
V_81 , V_5 -> V_69 , V_5 ) < 0 ) {
F_39 ( & V_5 -> V_2 , L_4 ) ;
V_7 -> V_41 = - 1 ;
}
if ( V_7 -> V_41 >= 0 )
F_40 ( & V_5 -> V_2 , 1 ) ;
V_38 = F_41 ( V_5 -> V_69 , & V_5 -> V_2 , & V_82 ,
V_83 ) ;
if ( F_31 ( V_38 ) ) {
V_58 = F_33 ( V_38 ) ;
goto V_84;
}
V_7 -> V_38 = V_38 ;
return 0 ;
V_84:
F_36 ( V_5 , NULL ) ;
V_77:
F_42 ( V_7 -> V_71 ) ;
V_72:
return V_58 ;
}
static int T_5 F_43 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_44 ( V_7 -> V_38 ) ;
F_42 ( V_7 -> V_71 ) ;
F_36 ( V_5 , NULL ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_46 ( V_2 ) ;
if ( F_47 ( V_2 ) )
F_48 ( V_7 -> V_41 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_46 ( V_2 ) ;
if ( F_47 ( V_2 ) )
F_50 ( V_7 -> V_41 ) ;
return 0 ;
}
