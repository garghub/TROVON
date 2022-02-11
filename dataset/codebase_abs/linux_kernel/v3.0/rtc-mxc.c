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
int V_28 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
V_27 = F_1 ( V_2 , V_14 ) ;
F_8 ( V_27 , & V_26 ) ;
V_25 . V_29 = V_26 . V_29 ;
V_25 . V_30 = V_26 . V_30 ;
V_25 . V_31 = V_26 . V_31 ;
V_25 . V_32 = V_24 -> V_32 ;
V_25 . V_33 = V_24 -> V_33 ;
V_25 . V_34 = V_24 -> V_34 ;
F_9 ( & V_26 , & V_27 ) ;
F_9 ( & V_25 , & time ) ;
if ( time < V_27 ) {
time += 60 * 60 * 24 ;
F_8 ( time , & V_25 ) ;
}
V_28 = F_9 ( & V_25 , & time ) ;
F_6 ( F_4 ( V_8 + V_35 ) , V_8 + V_35 ) ;
F_5 ( V_2 , V_18 , time ) ;
return V_28 ;
}
static T_3 F_10 ( int V_36 , void * V_37 )
{
struct V_4 * V_5 = V_37 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
T_1 V_38 ;
T_1 V_39 = 0 ;
F_11 ( & V_7 -> V_40 -> V_41 ) ;
V_38 = F_4 ( V_8 + V_35 ) & F_4 ( V_8 + V_42 ) ;
F_6 ( V_38 , V_8 + V_35 ) ;
if ( V_38 & V_43 )
V_38 &= ~ V_43 ;
if ( V_38 & V_43 )
V_39 |= ( V_44 | V_45 ) ;
if ( V_38 & V_46 )
V_39 |= ( V_47 | V_45 ) ;
if ( V_38 & V_48 )
V_39 |= ( V_49 | V_45 ) ;
if ( ( V_38 & V_43 ) && F_12 ( & V_7 -> V_50 ) )
F_7 ( & V_5 -> V_2 , & V_7 -> V_50 ) ;
F_13 ( V_7 -> V_40 , 1 , V_39 ) ;
F_14 ( & V_7 -> V_40 -> V_41 ) ;
return V_51 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_11 ( & V_7 -> V_40 -> V_41 ) ;
F_6 ( 0 , V_8 + V_42 ) ;
F_6 ( 0xffffffff , V_8 + V_35 ) ;
F_14 ( & V_7 -> V_40 -> V_41 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_52 ,
unsigned int V_53 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
T_1 V_54 ;
F_11 ( & V_7 -> V_40 -> V_41 ) ;
V_54 = F_4 ( V_8 + V_42 ) ;
if ( V_53 )
V_54 |= V_52 ;
else
V_54 &= ~ V_52 ;
F_6 ( V_54 , V_8 + V_42 ) ;
F_14 ( & V_7 -> V_40 -> V_41 ) ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_53 )
{
F_16 ( V_2 , V_43 , V_53 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_23 * V_55 )
{
T_1 V_56 ;
do {
V_56 = F_1 ( V_2 , V_14 ) ;
} while ( V_56 != F_1 ( V_2 , V_14 ) );
F_8 ( V_56 , V_55 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned long time )
{
do {
F_5 ( V_2 , V_14 , time ) ;
} while ( time != F_1 ( V_2 , V_14 ) );
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_57 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_8 ( F_1 ( V_2 , V_18 ) , & V_24 -> time ) ;
V_24 -> V_58 = ( ( F_4 ( V_8 + V_35 ) & V_43 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_57 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_28 ;
if ( F_12 ( & V_24 -> time ) ) {
if ( V_24 -> time . V_34 > 59 ||
V_24 -> time . V_32 > 23 ||
V_24 -> time . V_33 > 59 )
return - V_59 ;
V_28 = F_7 ( V_2 , & V_24 -> time ) ;
} else {
V_28 = F_12 ( & V_24 -> time ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_2 , & V_24 -> time ) ;
}
if ( V_28 )
return V_28 ;
memcpy ( & V_7 -> V_50 , & V_24 -> time , sizeof( struct V_23 ) ) ;
F_16 ( V_2 , V_43 , V_24 -> V_53 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_4 * V_5 )
{
struct V_60 * V_61 ;
struct V_62 * V_40 ;
struct V_6 * V_7 = NULL ;
T_1 V_54 ;
unsigned long V_63 ;
int V_28 ;
V_61 = F_23 ( V_5 , V_64 , 0 ) ;
if ( ! V_61 )
return - V_65 ;
V_7 = F_24 ( & V_5 -> V_2 , sizeof( * V_7 ) , V_66 ) ;
if ( ! V_7 )
return - V_67 ;
if ( ! F_25 ( & V_5 -> V_2 , V_61 -> V_68 ,
F_26 ( V_61 ) , V_5 -> V_69 ) )
return - V_70 ;
V_7 -> V_8 = F_27 ( & V_5 -> V_2 , V_61 -> V_68 ,
F_26 ( V_61 ) ) ;
V_7 -> V_71 = F_28 ( & V_5 -> V_2 , L_1 ) ;
if ( F_29 ( V_7 -> V_71 ) ) {
F_30 ( & V_5 -> V_2 , L_2 ) ;
V_28 = F_31 ( V_7 -> V_71 ) ;
goto V_72;
}
F_32 ( V_7 -> V_71 ) ;
V_63 = F_33 ( V_7 -> V_71 ) ;
if ( V_63 == 32768 )
V_54 = V_73 ;
else if ( V_63 == 32000 )
V_54 = V_74 ;
else if ( V_63 == 38400 )
V_54 = V_75 ;
else {
F_30 ( & V_5 -> V_2 , L_3 , V_63 ) ;
V_28 = - V_59 ;
goto V_76;
}
V_54 |= V_77 ;
F_6 ( V_54 , ( V_7 -> V_8 + V_78 ) ) ;
if ( ( ( F_4 ( V_7 -> V_8 + V_78 ) ) & V_77 ) == 0 ) {
F_30 ( & V_5 -> V_2 , L_4 ) ;
V_28 = - V_79 ;
goto V_76;
}
F_34 ( V_5 , V_7 ) ;
V_7 -> V_36 = F_35 ( V_5 , 0 ) ;
if ( V_7 -> V_36 >= 0 &&
F_36 ( & V_5 -> V_2 , V_7 -> V_36 , F_10 ,
V_80 , V_5 -> V_69 , V_5 ) < 0 ) {
F_37 ( & V_5 -> V_2 , L_5 ) ;
V_7 -> V_36 = - 1 ;
}
V_40 = F_38 ( V_5 -> V_69 , & V_5 -> V_2 , & V_81 ,
V_82 ) ;
if ( F_29 ( V_40 ) ) {
V_28 = F_31 ( V_40 ) ;
goto V_83;
}
V_7 -> V_40 = V_40 ;
return 0 ;
V_83:
F_34 ( V_5 , NULL ) ;
V_76:
F_39 ( V_7 -> V_71 ) ;
F_40 ( V_7 -> V_71 ) ;
V_72:
return V_28 ;
}
static int T_5 F_41 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_42 ( V_7 -> V_40 ) ;
F_39 ( V_7 -> V_71 ) ;
F_40 ( V_7 -> V_71 ) ;
F_34 ( V_5 , NULL ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
return F_44 ( & V_84 , F_22 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( & V_84 ) ;
}
