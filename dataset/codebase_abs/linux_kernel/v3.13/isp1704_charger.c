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
}
static inline int F_6 ( struct V_1 * V_2 )
{
T_2 V_3 ;
T_2 V_12 ;
T_2 V_13 ;
int type = V_14 ;
V_12 = F_1 ( V_2 , V_15 ) ;
V_13 = F_1 ( V_2 , V_16 ) ;
V_3 = V_17 | V_18 ;
F_3 ( V_2 , F_7 ( V_16 ) , V_3 ) ;
F_3 ( V_2 , F_7 ( V_15 ) ,
V_19 ) ;
F_3 ( V_2 , F_8 ( V_15 ) ,
V_20 ) ;
V_3 = V_21 | V_22 ;
F_3 ( V_2 , F_8 ( V_15 ) , V_3 ) ;
F_9 ( 1000 , 2000 ) ;
V_3 = F_1 ( V_2 , V_23 ) ;
if ( ( V_3 & 3 ) != 3 )
type = V_24 ;
F_3 ( V_2 , V_15 , V_12 ) ;
F_3 ( V_2 , V_16 , V_13 ) ;
return type ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
T_2 V_26 ;
V_26 = F_1 ( V_2 , V_15 ) ;
V_26 |= V_22 ;
F_3 ( V_2 , V_15 , V_26 ) ;
F_9 ( 1000 , 2000 ) ;
V_26 &= ~ ( V_22 | V_27 ) ;
F_3 ( V_2 , V_15 , V_26 ) ;
V_26 = V_18 | V_17 ;
F_3 ( V_2 , F_7 ( V_16 ) , V_26 ) ;
V_26 = V_21 | V_22 ;
F_3 ( V_2 , F_8 ( V_15 ) , V_26 ) ;
F_9 ( 1000 , 2000 ) ;
if ( ! F_1 ( V_2 , V_23 ) ) {
F_3 ( V_2 , F_7 ( V_15 ) ,
V_21 ) ;
return 1 ;
}
F_3 ( V_2 , F_8 ( V_28 ) ,
V_29 ) ;
F_3 ( V_2 , F_7 ( V_15 ) ,
V_21 ) ;
F_3 ( V_2 , F_8 ( V_16 ) ,
V_17 ) ;
if ( ! ( F_1 ( V_2 , V_23 ) ) )
V_25 = 1 ;
F_3 ( V_2 , F_7 ( V_28 ) ,
V_29 ) ;
return V_25 ;
}
static inline int F_11 ( struct V_1 * V_2 )
{
unsigned long V_30 ;
T_2 V_31 ;
int V_25 = 0 ;
V_31 = F_1 ( V_2 , V_28 ) ;
F_3 ( V_2 , V_28 ,
V_32 ) ;
F_3 ( V_2 , F_8 ( V_28 ) ,
V_32
| V_33 ) ;
F_9 ( 1000 , 2000 ) ;
V_30 = V_34 + F_12 ( 300 ) ;
do {
if ( F_1 ( V_2 , V_28 )
& V_35 ) {
V_25 = F_10 ( V_2 ) ;
break;
}
} while ( ! F_13 ( V_34 , V_30 ) && V_2 -> V_36 );
F_3 ( V_2 , V_28 , V_31 ) ;
return V_25 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) &&
F_6 ( V_2 ) == V_14 )
return true ;
else
return false ;
}
static void F_15 ( struct V_37 * V_38 )
{
struct V_1 * V_2 =
F_16 ( V_38 , struct V_1 , V_39 ) ;
static F_17 ( V_40 ) ;
F_18 ( & V_40 ) ;
switch ( V_2 -> V_4 -> V_41 ) {
case V_42 :
if ( ! V_2 -> V_43 ) {
V_2 -> V_36 = true ;
V_2 -> V_43 = 1 ;
F_5 ( V_2 , 1 ) ;
if ( F_14 ( V_2 ) ) {
V_2 -> V_44 . type = V_14 ;
V_2 -> V_45 = 1800 ;
} else {
V_2 -> V_44 . type = V_46 ;
V_2 -> V_45 = 500 ;
}
if ( V_2 -> V_4 -> V_47 -> V_48 )
F_19 ( V_2 -> V_4 -> V_47 -> V_48 ) ;
}
if ( V_2 -> V_44 . type != V_14 ) {
if ( V_2 -> V_45 > 500 )
V_2 -> V_45 = 500 ;
if ( V_2 -> V_45 > 100 )
V_2 -> V_44 . type = V_24 ;
}
break;
case V_49 :
V_2 -> V_36 = false ;
V_2 -> V_43 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_44 . type = V_46 ;
if ( V_2 -> V_4 -> V_47 -> V_48 )
F_20 ( V_2 -> V_4 -> V_47 -> V_48 ) ;
F_5 ( V_2 , 0 ) ;
break;
default:
goto V_50;
}
F_21 ( & V_2 -> V_44 ) ;
V_50:
F_22 ( & V_40 ) ;
}
static int F_23 ( struct V_51 * V_52 ,
unsigned long V_5 , void * V_53 )
{
struct V_1 * V_2 =
F_16 ( V_52 , struct V_1 , V_52 ) ;
F_24 ( & V_2 -> V_39 ) ;
return V_54 ;
}
static int F_25 ( struct V_55 * V_44 ,
enum V_56 V_57 ,
union V_58 * V_5 )
{
struct V_1 * V_2 =
F_16 ( V_44 , struct V_1 , V_44 ) ;
switch ( V_57 ) {
case V_59 :
V_5 -> V_60 = V_2 -> V_43 ;
break;
case V_61 :
V_5 -> V_60 = V_2 -> V_36 ;
break;
case V_62 :
V_5 -> V_60 = V_2 -> V_45 ;
break;
case V_63 :
V_5 -> V_64 = V_2 -> V_65 ;
break;
case V_66 :
V_5 -> V_64 = L_1 ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static inline int F_26 ( struct V_1 * V_2 )
{
int V_68 ;
int V_69 ;
int V_70 ;
int V_25 = - V_71 ;
V_25 = F_3 ( V_2 , V_72 , 0xaa ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_1 ( V_2 , V_72 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 != 0xaa )
return - V_71 ;
V_68 = F_1 ( V_2 , V_73 ) ;
V_68 |= F_1 ( V_2 , V_74 ) << 8 ;
if ( V_68 != V_75 )
return - V_71 ;
V_69 = F_1 ( V_2 , V_76 ) ;
V_69 |= F_1 ( V_2 , V_77 ) << 8 ;
for ( V_70 = 0 ; V_70 < F_27 ( V_78 ) ; V_70 ++ ) {
if ( V_69 == V_78 [ V_70 ] ) {
sprintf ( V_2 -> V_65 , L_2 , V_69 ) ;
return V_69 ;
}
}
F_28 ( V_2 -> V_9 , L_3 , V_69 ) ;
return - V_71 ;
}
static int F_29 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
int V_25 = - V_71 ;
V_2 = F_30 ( & V_80 -> V_9 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
V_2 -> V_4 = F_31 ( V_83 ) ;
if ( F_32 ( V_2 -> V_4 ) )
goto V_84;
V_2 -> V_9 = & V_80 -> V_9 ;
F_33 ( V_80 , V_2 ) ;
F_5 ( V_2 , 1 ) ;
V_25 = F_26 ( V_2 ) ;
if ( V_25 < 0 )
goto V_85;
V_2 -> V_44 . V_86 = L_4 ;
V_2 -> V_44 . type = V_46 ;
V_2 -> V_44 . V_87 = V_88 ;
V_2 -> V_44 . V_89 = F_27 ( V_88 ) ;
V_2 -> V_44 . V_90 = F_25 ;
V_25 = F_34 ( V_2 -> V_9 , & V_2 -> V_44 ) ;
if ( V_25 )
goto V_85;
F_35 ( & V_2 -> V_39 , F_15 ) ;
V_2 -> V_52 . V_91 = F_23 ;
V_25 = F_36 ( V_2 -> V_4 , & V_2 -> V_52 ) ;
if ( V_25 )
goto V_92;
F_37 ( V_2 -> V_9 , L_5 , V_2 -> V_65 ) ;
if ( V_2 -> V_4 -> V_47 -> V_48 )
F_20 ( V_2 -> V_4 -> V_47 -> V_48 ) ;
if ( V_2 -> V_4 -> V_41 == V_49 )
F_5 ( V_2 , 0 ) ;
if ( V_2 -> V_4 -> V_41 == V_42 &&
! V_2 -> V_4 -> V_47 -> V_93 )
F_24 ( & V_2 -> V_39 ) ;
return 0 ;
V_92:
F_38 ( & V_2 -> V_44 ) ;
V_85:
F_5 ( V_2 , 0 ) ;
F_39 ( V_2 -> V_4 ) ;
V_84:
F_28 ( & V_80 -> V_9 , L_6 , V_25 ) ;
return V_25 ;
}
static int F_40 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_41 ( V_80 ) ;
F_42 ( V_2 -> V_4 , & V_2 -> V_52 ) ;
F_38 ( & V_2 -> V_44 ) ;
F_39 ( V_2 -> V_4 ) ;
F_5 ( V_2 , 0 ) ;
return 0 ;
}
