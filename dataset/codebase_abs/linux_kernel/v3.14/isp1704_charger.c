static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
return F_4 ( V_2 -> V_4 , V_5 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , bool V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
if ( V_8 && V_8 -> V_11 )
V_8 -> V_11 ( V_6 ) ;
else if ( V_8 )
F_6 ( V_8 -> V_12 , V_6 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
T_2 V_3 ;
T_2 V_13 ;
T_2 V_14 ;
int type = V_15 ;
V_13 = F_1 ( V_2 , V_16 ) ;
V_14 = F_1 ( V_2 , V_17 ) ;
V_3 = V_18 | V_19 ;
F_3 ( V_2 , F_8 ( V_17 ) , V_3 ) ;
F_3 ( V_2 , F_8 ( V_16 ) ,
V_20 ) ;
F_3 ( V_2 , F_9 ( V_16 ) ,
V_21 ) ;
V_3 = V_22 | V_23 ;
F_3 ( V_2 , F_9 ( V_16 ) , V_3 ) ;
F_10 ( 1000 , 2000 ) ;
V_3 = F_1 ( V_2 , V_24 ) ;
if ( ( V_3 & 3 ) != 3 )
type = V_25 ;
F_3 ( V_2 , V_16 , V_13 ) ;
F_3 ( V_2 , V_17 , V_14 ) ;
return type ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
T_2 V_27 ;
V_27 = F_1 ( V_2 , V_16 ) ;
V_27 |= V_23 ;
F_3 ( V_2 , V_16 , V_27 ) ;
F_10 ( 1000 , 2000 ) ;
V_27 &= ~ ( V_23 | V_28 ) ;
F_3 ( V_2 , V_16 , V_27 ) ;
V_27 = V_19 | V_18 ;
F_3 ( V_2 , F_8 ( V_17 ) , V_27 ) ;
V_27 = V_22 | V_23 ;
F_3 ( V_2 , F_9 ( V_16 ) , V_27 ) ;
F_10 ( 1000 , 2000 ) ;
if ( ! F_1 ( V_2 , V_24 ) ) {
F_3 ( V_2 , F_8 ( V_16 ) ,
V_22 ) ;
return 1 ;
}
F_3 ( V_2 , F_9 ( V_29 ) ,
V_30 ) ;
F_3 ( V_2 , F_8 ( V_16 ) ,
V_22 ) ;
F_3 ( V_2 , F_9 ( V_17 ) ,
V_18 ) ;
if ( ! ( F_1 ( V_2 , V_24 ) ) )
V_26 = 1 ;
F_3 ( V_2 , F_8 ( V_29 ) ,
V_30 ) ;
return V_26 ;
}
static inline int F_12 ( struct V_1 * V_2 )
{
unsigned long V_31 ;
T_2 V_32 ;
int V_26 = 0 ;
V_32 = F_1 ( V_2 , V_29 ) ;
F_3 ( V_2 , V_29 ,
V_33 ) ;
F_3 ( V_2 , F_9 ( V_29 ) ,
V_33
| V_34 ) ;
F_10 ( 1000 , 2000 ) ;
V_31 = V_35 + F_13 ( 300 ) ;
do {
if ( F_1 ( V_2 , V_29 )
& V_36 ) {
V_26 = F_11 ( V_2 ) ;
break;
}
} while ( ! F_14 ( V_35 , V_31 ) && V_2 -> V_37 );
F_3 ( V_2 , V_29 , V_32 ) ;
return V_26 ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) &&
F_7 ( V_2 ) == V_15 )
return true ;
else
return false ;
}
static void F_16 ( struct V_38 * V_39 )
{
struct V_1 * V_2 =
F_17 ( V_39 , struct V_1 , V_40 ) ;
static F_18 ( V_41 ) ;
F_19 ( & V_41 ) ;
switch ( V_2 -> V_4 -> V_42 ) {
case V_43 :
if ( ! V_2 -> V_44 ) {
V_2 -> V_37 = true ;
V_2 -> V_44 = 1 ;
F_5 ( V_2 , 1 ) ;
if ( F_15 ( V_2 ) ) {
V_2 -> V_45 . type = V_15 ;
V_2 -> V_46 = 1800 ;
} else {
V_2 -> V_45 . type = V_47 ;
V_2 -> V_46 = 500 ;
}
if ( V_2 -> V_4 -> V_48 -> V_49 )
F_20 ( V_2 -> V_4 -> V_48 -> V_49 ) ;
}
if ( V_2 -> V_45 . type != V_15 ) {
if ( V_2 -> V_46 > 500 )
V_2 -> V_46 = 500 ;
if ( V_2 -> V_46 > 100 )
V_2 -> V_45 . type = V_25 ;
}
break;
case V_50 :
V_2 -> V_37 = false ;
V_2 -> V_44 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_45 . type = V_47 ;
if ( V_2 -> V_4 -> V_48 -> V_49 )
F_21 ( V_2 -> V_4 -> V_48 -> V_49 ) ;
F_5 ( V_2 , 0 ) ;
break;
default:
goto V_51;
}
F_22 ( & V_2 -> V_45 ) ;
V_51:
F_23 ( & V_41 ) ;
}
static int F_24 ( struct V_52 * V_53 ,
unsigned long V_5 , void * V_54 )
{
struct V_1 * V_2 =
F_17 ( V_53 , struct V_1 , V_53 ) ;
F_25 ( & V_2 -> V_40 ) ;
return V_55 ;
}
static int F_26 ( struct V_56 * V_45 ,
enum V_57 V_58 ,
union V_59 * V_5 )
{
struct V_1 * V_2 =
F_17 ( V_45 , struct V_1 , V_45 ) ;
switch ( V_58 ) {
case V_60 :
V_5 -> V_61 = V_2 -> V_44 ;
break;
case V_62 :
V_5 -> V_61 = V_2 -> V_37 ;
break;
case V_63 :
V_5 -> V_61 = V_2 -> V_46 ;
break;
case V_64 :
V_5 -> V_65 = V_2 -> V_66 ;
break;
case V_67 :
V_5 -> V_65 = L_1 ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static inline int F_27 ( struct V_1 * V_2 )
{
int V_69 ;
int V_70 ;
int V_71 ;
int V_26 = - V_72 ;
V_26 = F_3 ( V_2 , V_73 , 0xaa ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_1 ( V_2 , V_73 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 != 0xaa )
return - V_72 ;
V_69 = F_1 ( V_2 , V_74 ) ;
V_69 |= F_1 ( V_2 , V_75 ) << 8 ;
if ( V_69 != V_76 )
return - V_72 ;
V_70 = F_1 ( V_2 , V_77 ) ;
V_70 |= F_1 ( V_2 , V_78 ) << 8 ;
for ( V_71 = 0 ; V_71 < F_28 ( V_79 ) ; V_71 ++ ) {
if ( V_70 == V_79 [ V_71 ] ) {
sprintf ( V_2 -> V_66 , L_2 , V_70 ) ;
return V_70 ;
}
}
F_29 ( V_2 -> V_9 , L_3 , V_70 ) ;
return - V_72 ;
}
static int F_30 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
int V_26 = - V_72 ;
struct V_7 * V_82 = F_31 ( & V_81 -> V_9 ) ;
struct V_83 * V_84 = V_81 -> V_9 . V_85 ;
if ( V_84 ) {
int V_86 = F_32 ( V_84 , L_4 , 0 ) ;
if ( V_86 < 0 )
return V_86 ;
V_82 = F_33 ( & V_81 -> V_9 ,
sizeof( struct V_7 ) , V_87 ) ;
V_82 -> V_12 = V_86 ;
F_34 ( & V_81 -> V_9 , L_5 , V_82 -> V_12 ) ;
V_26 = F_35 ( & V_81 -> V_9 , V_82 -> V_12 ,
V_88 , L_6 ) ;
if ( V_26 )
goto V_89;
}
if ( ! V_82 ) {
F_29 ( & V_81 -> V_9 , L_7 ) ;
return - V_72 ;
}
V_2 = F_33 ( & V_81 -> V_9 , sizeof( * V_2 ) , V_87 ) ;
if ( ! V_2 )
return - V_90 ;
if ( V_84 )
V_2 -> V_4 = F_36 ( & V_81 -> V_9 , L_8 , 0 ) ;
else
V_2 -> V_4 = F_37 ( & V_81 -> V_9 , V_91 ) ;
if ( F_38 ( V_2 -> V_4 ) ) {
V_26 = F_39 ( V_2 -> V_4 ) ;
goto V_89;
}
V_2 -> V_9 = & V_81 -> V_9 ;
F_40 ( V_81 , V_2 ) ;
F_5 ( V_2 , 1 ) ;
V_26 = F_27 ( V_2 ) ;
if ( V_26 < 0 )
goto V_92;
V_2 -> V_45 . V_93 = L_9 ;
V_2 -> V_45 . type = V_47 ;
V_2 -> V_45 . V_94 = V_95 ;
V_2 -> V_45 . V_96 = F_28 ( V_95 ) ;
V_2 -> V_45 . V_97 = F_26 ;
V_26 = F_41 ( V_2 -> V_9 , & V_2 -> V_45 ) ;
if ( V_26 )
goto V_92;
F_42 ( & V_2 -> V_40 , F_16 ) ;
V_2 -> V_53 . V_98 = F_24 ;
V_26 = F_43 ( V_2 -> V_4 , & V_2 -> V_53 ) ;
if ( V_26 )
goto V_99;
F_34 ( V_2 -> V_9 , L_10 , V_2 -> V_66 ) ;
if ( V_2 -> V_4 -> V_48 -> V_49 )
F_21 ( V_2 -> V_4 -> V_48 -> V_49 ) ;
if ( V_2 -> V_4 -> V_42 == V_50 )
F_5 ( V_2 , 0 ) ;
if ( V_2 -> V_4 -> V_42 == V_43 &&
! V_2 -> V_4 -> V_48 -> V_100 )
F_25 ( & V_2 -> V_40 ) ;
return 0 ;
V_99:
F_44 ( & V_2 -> V_45 ) ;
V_92:
F_5 ( V_2 , 0 ) ;
V_89:
F_29 ( & V_81 -> V_9 , L_11 , V_26 ) ;
return V_26 ;
}
static int F_45 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_46 ( V_81 ) ;
F_47 ( V_2 -> V_4 , & V_2 -> V_53 ) ;
F_44 ( & V_2 -> V_45 ) ;
F_5 ( V_2 , 0 ) ;
return 0 ;
}
