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
static void F_14 ( struct V_37 * V_38 )
{
int V_39 ;
unsigned long V_40 ;
unsigned V_41 ;
struct V_1 * V_2 =
F_15 ( V_38 , struct V_1 , V_42 ) ;
static F_16 ( V_43 ) ;
V_40 = V_2 -> V_40 ;
V_41 = V_2 -> V_44 ;
F_17 ( & V_43 ) ;
if ( V_40 != V_45 )
F_5 ( V_2 , 1 ) ;
switch ( V_40 ) {
case V_46 :
V_2 -> V_36 = true ;
V_39 = F_11 ( V_2 ) ;
if ( V_39 ) {
V_2 -> V_47 = V_39 ;
V_2 -> V_48 . type = F_6 ( V_2 ) ;
}
switch ( V_2 -> V_48 . type ) {
case V_14 :
V_2 -> V_49 = 1800 ;
break;
case V_24 :
V_2 -> V_49 = 500 ;
case V_50 :
default:
if ( V_2 -> V_4 -> V_51 -> V_52 )
F_18 ( V_2 -> V_4 -> V_51 -> V_52 ) ;
}
break;
case V_45 :
V_2 -> V_36 = false ;
V_2 -> V_49 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_48 . type = V_50 ;
if ( V_2 -> V_4 -> V_51 -> V_52 )
F_19 ( V_2 -> V_4 -> V_51 -> V_52 ) ;
F_5 ( V_2 , 0 ) ;
break;
case V_53 :
if ( V_2 -> V_47 )
V_2 -> V_49 = 1800 ;
else
V_2 -> V_49 = V_41 ;
break;
default:
goto V_54;
}
F_20 ( & V_2 -> V_48 ) ;
V_54:
F_21 ( & V_43 ) ;
}
static int F_22 ( struct V_55 * V_56 ,
unsigned long V_40 , void * V_41 )
{
struct V_1 * V_2 =
F_15 ( V_56 , struct V_1 , V_56 ) ;
V_2 -> V_40 = V_40 ;
if ( V_41 )
V_2 -> V_44 = * ( ( unsigned * ) V_41 ) ;
F_23 ( & V_2 -> V_42 ) ;
return V_57 ;
}
static int F_24 ( struct V_58 * V_48 ,
enum V_59 V_60 ,
union V_61 * V_5 )
{
struct V_1 * V_2 =
F_15 ( V_48 , struct V_1 , V_48 ) ;
switch ( V_60 ) {
case V_62 :
V_5 -> V_63 = V_2 -> V_47 ;
break;
case V_64 :
V_5 -> V_63 = V_2 -> V_36 ;
break;
case V_65 :
V_5 -> V_63 = V_2 -> V_49 ;
break;
case V_66 :
V_5 -> V_67 = V_2 -> V_68 ;
break;
case V_69 :
V_5 -> V_67 = L_1 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static inline int F_25 ( struct V_1 * V_2 )
{
int V_71 ;
int V_72 ;
int V_73 ;
int V_25 = - V_74 ;
V_25 = F_3 ( V_2 , V_75 , 0xaa ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_1 ( V_2 , V_75 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 != 0xaa )
return - V_74 ;
V_71 = F_1 ( V_2 , V_76 ) ;
V_71 |= F_1 ( V_2 , V_77 ) << 8 ;
if ( V_71 != V_78 )
return - V_74 ;
V_72 = F_1 ( V_2 , V_79 ) ;
V_72 |= F_1 ( V_2 , V_80 ) << 8 ;
for ( V_73 = 0 ; V_73 < F_26 ( V_81 ) ; V_73 ++ ) {
if ( V_72 == V_81 [ V_73 ] ) {
sprintf ( V_2 -> V_68 , L_2 , V_72 ) ;
return V_72 ;
}
}
F_27 ( V_2 -> V_9 , L_3 , V_72 ) ;
return - V_74 ;
}
static int T_3 F_28 ( struct V_82 * V_83 )
{
struct V_1 * V_2 ;
int V_25 = - V_74 ;
V_2 = F_29 ( sizeof *V_2 , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_2 -> V_4 = F_30 ( V_86 ) ;
if ( F_31 ( V_2 -> V_4 ) )
goto V_87;
V_2 -> V_9 = & V_83 -> V_9 ;
F_32 ( V_83 , V_2 ) ;
F_5 ( V_2 , 1 ) ;
V_25 = F_25 ( V_2 ) ;
if ( V_25 < 0 )
goto V_88;
V_2 -> V_48 . V_89 = L_4 ;
V_2 -> V_48 . type = V_50 ;
V_2 -> V_48 . V_90 = V_91 ;
V_2 -> V_48 . V_92 = F_26 ( V_91 ) ;
V_2 -> V_48 . V_93 = F_24 ;
V_25 = F_33 ( V_2 -> V_9 , & V_2 -> V_48 ) ;
if ( V_25 )
goto V_88;
F_34 ( & V_2 -> V_42 , F_14 ) ;
V_2 -> V_56 . V_94 = F_22 ;
V_25 = F_35 ( V_2 -> V_4 , & V_2 -> V_56 ) ;
if ( V_25 )
goto V_95;
F_36 ( V_2 -> V_9 , L_5 , V_2 -> V_68 ) ;
if ( V_2 -> V_4 -> V_51 -> V_52 )
F_19 ( V_2 -> V_4 -> V_51 -> V_52 ) ;
V_25 = F_1 ( V_2 , V_96 ) ;
F_5 ( V_2 , 0 ) ;
if ( ( V_25 & V_97 ) && ! V_2 -> V_4 -> V_51 -> V_98 ) {
V_2 -> V_40 = V_46 ;
F_23 ( & V_2 -> V_42 ) ;
}
return 0 ;
V_95:
F_37 ( & V_2 -> V_48 ) ;
V_88:
F_5 ( V_2 , 0 ) ;
F_38 ( V_2 -> V_4 ) ;
V_87:
F_39 ( V_2 ) ;
F_27 ( & V_83 -> V_9 , L_6 , V_25 ) ;
return V_25 ;
}
static int T_4 F_40 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_41 ( V_83 ) ;
F_42 ( V_2 -> V_4 , & V_2 -> V_56 ) ;
F_37 ( & V_2 -> V_48 ) ;
F_38 ( V_2 -> V_4 ) ;
F_5 ( V_2 , 0 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
