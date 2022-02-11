static void F_1 ( T_1 V_1 )
{
T_1 V_2 ;
unsigned long V_3 ;
unsigned long V_4 ;
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
if ( V_2 == V_8 )
F_4 ( V_9 ,
V_6 + V_10 ) ;
F_4 ( V_11 ,
V_6 + V_12 ) ;
V_3 = F_5 ( V_5 ) ;
V_4 = F_6 ( 1000000000 , V_3 ) ;
V_4 = 3 * V_4 ;
F_7 ( V_4 ) ;
F_4 ( V_13 , V_6 + V_14 ) ;
F_4 ( V_1 , V_6 + V_15 ) ;
F_4 ( V_16 , V_6 + V_17 ) ;
( void ) F_3 ( V_6 + V_18 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
F_8 ( V_5 ) ;
if ( V_2 != V_19 )
F_9 ( V_20 ,
L_1 ,
V_21 , V_2 ) ;
}
static void F_10 ( void )
{
T_1 V_2 ;
F_2 ( V_5 ) ;
F_4 ( 0x0000U , V_6 + V_14 ) ;
V_2 = F_3 ( V_6 + V_7 ) ;
if ( V_2 != V_8 ) {
F_4 ( V_22 ,
V_6 + V_23 ) ;
F_4 ( V_24 ,
V_6 + V_7 ) ;
F_4 ( V_24 ,
V_6 + V_7 ) ;
}
V_2 = F_3 ( V_6 + V_7 ) ;
F_8 ( V_5 ) ;
if ( V_2 != V_8 )
F_9 ( V_20 ,
L_2 ,
V_21 , V_2 ) ;
}
static void F_11 ( void )
{
F_1 ( V_25 * 100 ) ;
}
static void F_12 ( void )
{
F_2 ( V_5 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
F_8 ( V_5 ) ;
}
static int F_13 ( int time )
{
if ( time <= 0 || time > 327 )
return - V_26 ;
V_25 = time ;
F_2 ( V_5 ) ;
F_4 ( V_25 * 100 , V_6 + V_15 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
static T_2 F_14 ( int V_27 , void * V_28 )
{
T_1 V_2 ;
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_12 ) ;
if ( V_2 == V_29 )
F_4 ( V_11 ,
V_6 + V_12 ) ;
F_4 ( 0x0000U , V_6 + V_14 ) ;
F_8 ( V_5 ) ;
F_15 ( V_20 , L_3 ) ;
return V_30 ;
}
static int F_16 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
if ( F_17 ( 1 , & V_33 ) )
return - V_34 ;
F_11 () ;
return F_18 ( V_31 , V_32 ) ;
}
static int F_19 ( struct V_31 * V_31 , struct V_32 * V_32 )
{
F_20 ( 1 , & V_33 ) ;
F_10 () ;
return 0 ;
}
static T_3 F_21 ( struct V_32 * V_32 , const char T_4 * V_28 ,
T_5 V_35 , T_6 * V_36 )
{
if ( V_35 )
F_12 () ;
return V_35 ;
}
static long F_22 ( struct V_32 * V_32 , unsigned int V_37 ,
unsigned long V_38 )
{
int V_39 = - V_40 ;
T_1 V_2 ;
int time ;
int V_41 ;
union {
struct V_42 T_4 * V_43 ;
int T_4 * V_44 ;
} V_45 ;
static const struct V_42 V_43 = {
. V_46 = V_47 |
V_48 |
V_49 ,
. V_50 = L_4 ,
. V_51 = 1 ,
} ;
V_45 . V_44 = ( int T_4 * ) V_38 ;
switch ( V_37 ) {
case V_52 :
V_39 = F_23 ( V_45 . V_43 , & V_43 ,
sizeof( V_43 ) ) ? - V_53 : 0 ;
break;
case V_54 :
V_39 = F_24 ( 0 , V_45 . V_44 ) ;
break;
case V_55 :
V_39 = F_24 ( V_56 , V_45 . V_44 ) ;
break;
case V_57 :
V_39 = F_25 ( V_41 , V_45 . V_44 ) ;
if ( V_39 )
break;
if ( V_41 & V_58 )
F_10 () ;
if ( V_41 & V_59 )
F_11 () ;
V_39 = 0 ;
break;
case V_60 :
F_12 () ;
V_39 = 0 ;
break;
case V_61 :
V_39 = F_25 ( time , V_45 . V_44 ) ;
if ( V_39 )
break;
V_39 = F_13 ( time ) ;
if ( V_39 )
break;
case V_62 :
V_39 = F_24 ( V_25 , V_45 . V_44 ) ;
break;
case V_63 :
F_2 ( V_5 ) ;
V_2 = F_3 ( V_6 + V_18 ) ;
while ( V_2 & V_64 )
V_2 = F_3 ( V_6 + V_18 ) ;
V_2 &= V_65 ;
F_8 ( V_5 ) ;
if ( V_2 != 0 )
V_2 /= 100 ;
V_39 = F_24 ( V_2 , V_45 . V_44 ) ;
break;
}
return V_39 ;
}
static int T_7 F_26 ( struct V_66 * V_67 )
{
F_27 ( & V_68 ) ;
F_10 () ;
F_28 ( V_27 , V_67 ) ;
F_29 ( V_5 ) ;
F_30 ( V_6 ) ;
F_31 ( V_69 , V_70 ) ;
return 0 ;
}
static int T_8 F_32 ( struct V_66 * V_67 )
{
int V_39 ;
T_1 V_2 ;
struct V_71 * V_72 ;
V_72 = F_33 ( V_67 , V_73 , 0 ) ;
if ( ! V_72 )
return - V_74 ;
V_20 = & V_67 -> V_75 ;
V_70 = F_34 ( V_72 ) ;
V_69 = V_72 -> V_76 ;
if ( F_35 ( V_69 , V_70 , V_77 ) == NULL ) {
V_39 = - V_34 ;
goto V_78;
}
V_6 = F_36 ( V_69 , V_70 ) ;
if ( ! V_6 ) {
V_39 = - V_79 ;
goto V_80;
}
V_5 = F_37 ( & V_67 -> V_75 , NULL ) ;
if ( F_38 ( V_5 ) ) {
V_39 = F_39 ( V_5 ) ;
F_9 ( & V_67 -> V_75 , L_5 ) ;
goto V_81;
}
V_39 = F_2 ( V_5 ) ;
if ( V_39 ) {
F_9 ( & V_67 -> V_75 , L_6 ) ;
goto V_82;
}
V_2 = F_3 ( V_6 + V_83 ) ;
switch ( V_2 ) {
case V_84 :
F_40 ( & V_67 -> V_75 ,
L_7 ) ;
V_56 = V_47 ;
break;
case V_85 :
F_40 ( & V_67 -> V_75 ,
L_8 ) ;
break;
default:
F_40 ( & V_67 -> V_75 ,
L_9 , V_2 ) ;
break;
}
V_2 = F_3 ( V_6 + V_7 ) ;
switch ( V_2 ) {
case V_8 :
F_40 ( & V_67 -> V_75 , L_10 ) ;
break;
case V_19 :
F_40 ( & V_67 -> V_75 ,
L_11 ) ;
F_10 () ;
break;
default:
F_9 ( & V_67 -> V_75 ,
L_12 ,
V_2 ) ;
break;
}
F_4 ( V_86 , V_6 + V_83 ) ;
V_27 = F_41 ( V_67 , 0 ) ;
if ( F_42 ( V_27 , F_14 , V_87 ,
V_77 L_13 , V_67 ) ) {
V_39 = - V_88 ;
goto V_89;
}
F_8 ( V_5 ) ;
V_39 = F_43 ( & V_68 ) ;
if ( V_39 == 0 )
F_40 ( & V_67 -> V_75 ,
L_14 , V_25 ) ;
else
goto V_90;
return 0 ;
V_90:
F_28 ( V_27 , V_67 ) ;
V_89:
F_8 ( V_5 ) ;
V_82:
F_29 ( V_5 ) ;
V_81:
F_30 ( V_6 ) ;
V_80:
F_31 ( V_69 , V_91 ) ;
V_78:
return V_39 ;
}
static int F_44 ( struct V_66 * V_67 , T_9 V_92 )
{
V_93 = F_3 ( V_6 + V_14 ) & 0x0001U ;
V_94 = F_3 ( V_6 + V_7 ) ;
if ( V_94 == V_19 )
F_10 () ;
return 0 ;
}
static int F_45 ( struct V_66 * V_67 )
{
F_4 ( V_93 , V_6 + V_14 ) ;
if ( V_94 == V_19 ) {
F_4 ( V_9 ,
V_6 + V_10 ) ;
F_4 ( V_16 ,
V_6 + V_17 ) ;
}
return 0 ;
}
void F_46 ( void )
{
F_4 ( V_95 ,
V_6 + V_96 ) ;
F_1 ( 500 ) ;
}
static int T_8 F_47 ( void )
{
return F_48 ( & V_97 , F_32 ) ;
}
static void T_7 F_49 ( void )
{
F_50 ( & V_97 ) ;
}
