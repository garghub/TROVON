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
T_1 V_43 ;
T_1 V_44 = 0 ;
F_11 ( & V_7 -> V_38 -> V_39 ) ;
V_43 = F_4 ( V_8 + V_34 ) & F_4 ( V_8 + V_40 ) ;
F_6 ( V_43 , V_8 + V_34 ) ;
if ( V_43 & V_45 ) {
V_44 |= ( V_46 | V_47 ) ;
F_10 ( & V_5 -> V_2 , V_45 , 0 ) ;
}
if ( V_43 & V_48 )
V_44 |= ( V_49 | V_47 ) ;
if ( V_43 & V_50 )
V_44 |= ( V_51 | V_47 ) ;
F_14 ( V_7 -> V_38 , 1 , V_44 ) ;
F_12 ( & V_7 -> V_38 -> V_39 ) ;
return V_52 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_11 ( & V_7 -> V_38 -> V_39 ) ;
F_6 ( 0 , V_8 + V_40 ) ;
F_6 ( 0xffffffff , V_8 + V_34 ) ;
F_12 ( & V_7 -> V_38 -> V_39 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_36 )
{
F_10 ( V_2 , V_45 , V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_23 * V_53 )
{
T_1 V_54 ;
do {
V_54 = F_1 ( V_2 , V_14 ) ;
} while ( V_54 != F_1 ( V_2 , V_14 ) );
F_8 ( V_54 , V_53 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned long time )
{
if ( F_19 () ) {
struct V_23 V_53 ;
F_8 ( time , & V_53 ) ;
V_53 . V_28 = 70 ;
F_9 ( & V_53 , & time ) ;
}
do {
F_5 ( V_2 , V_14 , time ) ;
} while ( time != F_1 ( V_2 , V_14 ) );
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_55 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
void T_2 * V_8 = V_7 -> V_8 ;
F_8 ( F_1 ( V_2 , V_18 ) , & V_24 -> time ) ;
V_24 -> V_56 = ( ( F_4 ( V_8 + V_34 ) & V_45 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_55 * V_24 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_57 ;
V_57 = F_7 ( V_2 , & V_24 -> time ) ;
if ( V_57 )
return V_57 ;
memcpy ( & V_7 -> V_58 , & V_24 -> time , sizeof( struct V_23 ) ) ;
F_10 ( V_2 , V_45 , V_24 -> V_36 ) ;
return 0 ;
}
static int T_4 F_22 ( struct V_4 * V_5 )
{
struct V_59 * V_60 ;
struct V_61 * V_38 ;
struct V_6 * V_7 = NULL ;
T_1 V_37 ;
unsigned long V_62 ;
int V_57 ;
V_60 = F_23 ( V_5 , V_63 , 0 ) ;
if ( ! V_60 )
return - V_64 ;
V_7 = F_24 ( & V_5 -> V_2 , sizeof( * V_7 ) , V_65 ) ;
if ( ! V_7 )
return - V_66 ;
if ( ! F_25 ( & V_5 -> V_2 , V_60 -> V_67 ,
F_26 ( V_60 ) , V_5 -> V_68 ) )
return - V_69 ;
V_7 -> V_8 = F_27 ( & V_5 -> V_2 , V_60 -> V_67 ,
F_26 ( V_60 ) ) ;
V_7 -> V_70 = F_28 ( & V_5 -> V_2 , L_1 ) ;
if ( F_29 ( V_7 -> V_70 ) ) {
F_30 ( & V_5 -> V_2 , L_2 ) ;
V_57 = F_31 ( V_7 -> V_70 ) ;
goto V_71;
}
F_32 ( V_7 -> V_70 ) ;
V_62 = F_33 ( V_7 -> V_70 ) ;
if ( V_62 == 32768 )
V_37 = V_72 ;
else if ( V_62 == 32000 )
V_37 = V_73 ;
else if ( V_62 == 38400 )
V_37 = V_74 ;
else {
F_30 ( & V_5 -> V_2 , L_3 , V_62 ) ;
V_57 = - V_75 ;
goto V_76;
}
V_37 |= V_77 ;
F_6 ( V_37 , ( V_7 -> V_8 + V_78 ) ) ;
if ( ( ( F_4 ( V_7 -> V_8 + V_78 ) ) & V_77 ) == 0 ) {
F_30 ( & V_5 -> V_2 , L_4 ) ;
V_57 = - V_79 ;
goto V_76;
}
F_34 ( V_5 , V_7 ) ;
V_7 -> V_41 = F_35 ( V_5 , 0 ) ;
if ( V_7 -> V_41 >= 0 &&
F_36 ( & V_5 -> V_2 , V_7 -> V_41 , F_13 ,
V_80 , V_5 -> V_68 , V_5 ) < 0 ) {
F_37 ( & V_5 -> V_2 , L_5 ) ;
V_7 -> V_41 = - 1 ;
}
if ( V_7 -> V_41 >= 0 )
F_38 ( & V_5 -> V_2 , 1 ) ;
V_38 = F_39 ( V_5 -> V_68 , & V_5 -> V_2 , & V_81 ,
V_82 ) ;
if ( F_29 ( V_38 ) ) {
V_57 = F_31 ( V_38 ) ;
goto V_83;
}
V_7 -> V_38 = V_38 ;
return 0 ;
V_83:
F_34 ( V_5 , NULL ) ;
V_76:
F_40 ( V_7 -> V_70 ) ;
F_41 ( V_7 -> V_70 ) ;
V_71:
return V_57 ;
}
static int T_5 F_42 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_43 ( V_7 -> V_38 ) ;
F_40 ( V_7 -> V_70 ) ;
F_41 ( V_7 -> V_70 ) ;
F_34 ( V_5 , NULL ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_45 ( V_2 ) ;
if ( F_46 ( V_2 ) )
F_47 ( V_7 -> V_41 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_45 ( V_2 ) ;
if ( F_46 ( V_2 ) )
F_49 ( V_7 -> V_41 ) ;
return 0 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_84 , F_22 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_84 ) ;
}
