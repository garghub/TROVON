static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_3 ) ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
T_1 V_9 ;
T_1 V_10 ;
T_1 V_11 ;
int type = V_12 ;
V_10 = F_3 ( V_2 -> V_13 , V_14 ) ;
V_11 = F_3 ( V_2 -> V_13 , V_15 ) ;
V_9 = V_16 | V_17 ;
F_4 ( V_2 -> V_13 , F_5 ( V_15 ) , V_9 ) ;
F_4 ( V_2 -> V_13 , F_5 ( V_14 ) ,
V_18 ) ;
F_4 ( V_2 -> V_13 , F_6 ( V_14 ) ,
V_19 ) ;
V_9 = V_20 | V_21 ;
F_4 ( V_2 -> V_13 , F_6 ( V_14 ) , V_9 ) ;
F_7 ( 1000 , 2000 ) ;
V_9 = F_3 ( V_2 -> V_13 , V_22 ) ;
if ( ( V_9 & 3 ) != 3 )
type = V_23 ;
F_4 ( V_2 -> V_13 , V_14 , V_10 ) ;
F_4 ( V_2 -> V_13 , V_15 , V_11 ) ;
return type ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
int V_24 = 0 ;
T_1 V_25 ;
V_25 = F_3 ( V_2 -> V_13 , V_14 ) ;
V_25 |= V_21 ;
F_4 ( V_2 -> V_13 , V_14 , V_25 ) ;
F_7 ( 1000 , 2000 ) ;
V_25 &= ~ ( V_21 | V_26 ) ;
F_4 ( V_2 -> V_13 , V_14 , V_25 ) ;
V_25 = V_17 | V_16 ;
F_4 ( V_2 -> V_13 , F_5 ( V_15 ) , V_25 ) ;
V_25 = V_20 | V_21 ;
F_4 ( V_2 -> V_13 , F_6 ( V_14 ) , V_25 ) ;
F_7 ( 1000 , 2000 ) ;
if ( ! F_3 ( V_2 -> V_13 , V_22 ) ) {
F_4 ( V_2 -> V_13 , F_5 ( V_14 ) ,
V_20 ) ;
return 1 ;
}
F_4 ( V_2 -> V_13 , F_6 ( V_27 ) ,
V_28 ) ;
F_4 ( V_2 -> V_13 , F_5 ( V_14 ) ,
V_20 ) ;
F_4 ( V_2 -> V_13 , F_6 ( V_15 ) ,
V_16 ) ;
if ( ! ( F_3 ( V_2 -> V_13 , V_22 ) ) )
V_24 = 1 ;
F_4 ( V_2 -> V_13 , F_5 ( V_27 ) ,
V_28 ) ;
return V_24 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
T_1 V_30 ;
int V_24 = 0 ;
V_30 = F_3 ( V_2 -> V_13 , V_27 ) ;
F_4 ( V_2 -> V_13 , V_27 ,
V_31 ) ;
F_4 ( V_2 -> V_13 , F_6 ( V_27 ) ,
V_31
| V_32 ) ;
F_7 ( 1000 , 2000 ) ;
V_29 = V_33 + F_10 ( 300 ) ;
do {
if ( F_3 ( V_2 -> V_13 , V_27 )
& V_34 ) {
V_24 = F_8 ( V_2 ) ;
break;
}
} while ( ! F_11 ( V_33 , V_29 ) && V_2 -> V_35 );
F_4 ( V_2 -> V_13 , V_27 , V_30 ) ;
return V_24 ;
}
static void F_12 ( struct V_36 * V_37 )
{
int V_38 ;
unsigned long V_39 ;
unsigned V_40 ;
struct V_1 * V_2 =
F_13 ( V_37 , struct V_1 , V_41 ) ;
static F_14 ( V_42 ) ;
V_39 = V_2 -> V_39 ;
V_40 = V_2 -> V_43 ;
F_15 ( & V_42 ) ;
if ( V_39 != V_44 )
F_1 ( V_2 , 1 ) ;
switch ( V_39 ) {
case V_45 :
V_2 -> V_35 = true ;
V_38 = F_9 ( V_2 ) ;
if ( V_38 ) {
V_2 -> V_46 = V_38 ;
V_2 -> V_47 . type = F_2 ( V_2 ) ;
}
switch ( V_2 -> V_47 . type ) {
case V_12 :
V_2 -> V_48 = 1800 ;
break;
case V_23 :
V_2 -> V_48 = 500 ;
case V_49 :
default:
if ( V_2 -> V_13 -> V_50 )
F_16 ( V_2 -> V_13 -> V_50 ) ;
}
break;
case V_44 :
V_2 -> V_35 = false ;
V_2 -> V_48 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_47 . type = V_49 ;
if ( V_2 -> V_13 -> V_50 )
F_17 ( V_2 -> V_13 -> V_50 ) ;
F_1 ( V_2 , 0 ) ;
break;
case V_51 :
if ( V_2 -> V_46 )
V_2 -> V_48 = 1800 ;
else
V_2 -> V_48 = V_40 ;
break;
default:
goto V_52;
}
F_18 ( & V_2 -> V_47 ) ;
V_52:
F_19 ( & V_42 ) ;
}
static int F_20 ( struct V_53 * V_54 ,
unsigned long V_39 , void * V_40 )
{
struct V_1 * V_2 =
F_13 ( V_54 , struct V_1 , V_54 ) ;
V_2 -> V_39 = V_39 ;
if ( V_40 )
V_2 -> V_43 = * ( ( unsigned * ) V_40 ) ;
F_21 ( & V_2 -> V_41 ) ;
return V_55 ;
}
static int F_22 ( struct V_56 * V_47 ,
enum V_57 V_58 ,
union V_59 * V_60 )
{
struct V_1 * V_2 =
F_13 ( V_47 , struct V_1 , V_47 ) ;
switch ( V_58 ) {
case V_61 :
V_60 -> V_62 = V_2 -> V_46 ;
break;
case V_63 :
V_60 -> V_62 = V_2 -> V_35 ;
break;
case V_64 :
V_60 -> V_62 = V_2 -> V_48 ;
break;
case V_65 :
V_60 -> V_66 = V_2 -> V_67 ;
break;
case V_68 :
V_60 -> V_66 = L_1 ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static inline int F_23 ( struct V_1 * V_2 )
{
int V_70 ;
int V_71 ;
int V_72 ;
int V_24 = - V_73 ;
V_24 = F_4 ( V_2 -> V_13 , V_74 , 0xaa ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_3 ( V_2 -> V_13 , V_74 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_24 != 0xaa )
return - V_73 ;
V_70 = F_3 ( V_2 -> V_13 , V_75 ) ;
V_70 |= F_3 ( V_2 -> V_13 , V_76 ) << 8 ;
if ( V_70 != V_77 )
return - V_73 ;
V_71 = F_3 ( V_2 -> V_13 , V_78 ) ;
V_71 |= F_3 ( V_2 -> V_13 , V_79 ) << 8 ;
for ( V_72 = 0 ; V_72 < F_24 ( V_80 ) ; V_72 ++ ) {
if ( V_71 == V_80 [ V_72 ] ) {
sprintf ( V_2 -> V_67 , L_2 , V_71 ) ;
return V_71 ;
}
}
F_25 ( V_2 -> V_6 , L_3 , V_71 ) ;
return - V_73 ;
}
static int T_2 F_26 ( struct V_81 * V_82 )
{
struct V_1 * V_2 ;
int V_24 = - V_73 ;
V_2 = F_27 ( sizeof *V_2 , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
V_2 -> V_13 = F_28 () ;
if ( ! V_2 -> V_13 )
goto V_85;
V_2 -> V_6 = & V_82 -> V_6 ;
F_29 ( V_82 , V_2 ) ;
F_1 ( V_2 , 1 ) ;
V_24 = F_23 ( V_2 ) ;
if ( V_24 < 0 )
goto V_86;
V_2 -> V_47 . V_87 = L_4 ;
V_2 -> V_47 . type = V_49 ;
V_2 -> V_47 . V_88 = V_89 ;
V_2 -> V_47 . V_90 = F_24 ( V_89 ) ;
V_2 -> V_47 . V_91 = F_22 ;
V_24 = F_30 ( V_2 -> V_6 , & V_2 -> V_47 ) ;
if ( V_24 )
goto V_86;
F_31 ( & V_2 -> V_41 , F_12 ) ;
V_2 -> V_54 . V_92 = F_20 ;
V_24 = F_32 ( V_2 -> V_13 , & V_2 -> V_54 ) ;
if ( V_24 )
goto V_93;
F_33 ( V_2 -> V_6 , L_5 , V_2 -> V_67 ) ;
if ( V_2 -> V_13 -> V_50 )
F_17 ( V_2 -> V_13 -> V_50 ) ;
V_24 = F_3 ( V_2 -> V_13 , V_94 ) ;
F_1 ( V_2 , 0 ) ;
if ( ( V_24 & V_95 ) && ! V_2 -> V_13 -> V_96 ) {
V_2 -> V_39 = V_45 ;
F_21 ( & V_2 -> V_41 ) ;
}
return 0 ;
V_93:
F_34 ( & V_2 -> V_47 ) ;
V_86:
F_35 ( V_2 -> V_13 ) ;
V_85:
F_36 ( V_2 ) ;
F_25 ( & V_82 -> V_6 , L_6 , V_24 ) ;
return V_24 ;
}
static int T_3 F_37 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_38 ( V_82 ) ;
F_39 ( V_2 -> V_13 , & V_2 -> V_54 ) ;
F_34 ( & V_2 -> V_47 ) ;
F_35 ( V_2 -> V_13 ) ;
F_1 ( V_2 , 0 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
