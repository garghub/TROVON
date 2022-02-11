static T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_2 -> V_9 ] ;
F_3 ( V_2 , V_10 , V_11 ) ;
F_3 ( V_2 , V_12 , V_7 -> V_13 << 1 |
( V_7 -> V_14 & V_15 ? 1 : 0 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_2 -> V_9 ] ;
if ( V_2 -> V_16 >= V_7 -> V_17 ) {
V_2 -> V_16 = 0 ;
V_2 -> V_9 += 1 ;
if ( V_2 -> V_9 >= V_2 -> V_18 ) {
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_20 ) ;
} else {
F_5 ( V_2 ) ;
}
} else {
F_3 ( V_2 , V_12 ,
V_7 -> V_21 [ V_2 -> V_16 ++ ] ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 [ V_2 -> V_9 ] ;
V_7 -> V_21 [ V_2 -> V_16 ] = F_1 ( V_2 , V_22 ) ;
V_2 -> V_16 += 1 ;
if ( V_2 -> V_16 >= V_7 -> V_17 ) {
V_2 -> V_16 = 0 ;
V_2 -> V_9 += 1 ;
F_3 ( V_2 , V_10 , V_23 ) ;
if ( V_2 -> V_9 >= V_2 -> V_18 ) {
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_20 ) ;
} else {
F_5 ( V_2 ) ;
}
} else {
F_3 ( V_2 , V_10 , V_24 ) ;
}
}
static T_2 F_9 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_6 * V_7 = & V_2 -> V_8 [ V_2 -> V_9 ] ;
T_1 V_27 = F_1 ( V_2 , V_28 ) ;
T_1 V_29 = F_1 ( V_2 , V_30 ) ;
F_3 ( V_2 , V_31 , V_27 & V_32 ) ;
switch ( V_29 & V_33 ) {
case V_34 :
V_2 -> V_35 = - V_36 ;
F_7 ( & V_2 -> V_20 ) ;
break;
case V_37 :
V_2 -> V_35 = - V_38 ;
F_3 ( V_2 , V_10 ,
V_19 | V_39 |
V_40 | V_41 ) ;
F_7 ( & V_2 -> V_20 ) ;
break;
case V_42 :
break;
case V_43 :
break;
case V_44 :
if ( V_29 & V_45 ) {
F_3 ( V_2 , V_10 , V_19 ) ;
V_2 -> V_35 = - V_46 ;
F_7 ( & V_2 -> V_20 ) ;
} else if ( V_7 -> V_14 & V_15 ) {
} else {
F_6 ( V_2 ) ;
}
break;
case V_47 :
if ( V_7 -> V_14 & V_15 ) {
F_8 ( V_2 ) ;
} else {
}
break;
case V_48 :
if ( V_29 & V_45 ) {
F_3 ( V_2 , V_10 , V_19 ) ;
F_7 ( & V_2 -> V_20 ) ;
} else {
F_6 ( V_2 ) ;
}
}
return V_49 ;
}
static int F_10 ( struct V_50 * V_51 ,
struct V_6 * V_8 , int V_52 )
{
struct V_1 * V_2 = F_11 ( V_51 ) ;
int V_53 ;
if ( V_2 -> V_8 )
return - V_54 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_52 ;
V_2 -> V_16 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_35 = - V_38 ;
F_12 ( & V_2 -> V_20 ) ;
F_13 ( & V_2 -> V_55 . V_56 , L_1 ,
F_1 ( V_2 , V_30 ) ,
F_1 ( V_2 , V_57 ) ) ;
F_5 ( V_2 ) ;
F_14 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_9 >= V_2 -> V_18 )
V_53 = V_2 -> V_18 ;
else
V_53 = V_2 -> V_35 ;
return V_53 ;
}
static T_1 F_15 ( struct V_50 * V_51 )
{
return V_58 | V_59 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_1 V_60 = F_1 ( V_2 , V_61 ) ;
return ( V_60 & V_62 ) >>
F_17 ( V_62 ) ;
}
static int F_18 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
unsigned long V_67 ;
struct V_68 * V_69 = V_64 -> V_56 . V_70 ;
T_1 V_71 , V_72 ;
int V_53 ;
T_1 V_73 ;
if ( ! V_69 )
return - V_74 ;
V_2 = F_19 ( & V_64 -> V_56 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
F_20 ( V_64 , V_2 ) ;
F_21 ( & V_2 -> V_20 ) ;
F_22 ( V_2 -> V_55 . V_77 , V_64 -> V_77 , sizeof( V_2 -> V_55 . V_77 ) ) ;
V_2 -> V_55 . V_78 = V_79 ;
V_2 -> V_55 . V_80 = & V_81 ;
V_2 -> V_55 . V_56 . V_82 = & V_64 -> V_56 ;
V_2 -> V_55 . V_56 . V_70 = V_64 -> V_56 . V_70 ;
F_23 ( & V_2 -> V_55 , V_2 ) ;
V_2 -> V_83 = F_24 ( & V_64 -> V_56 , NULL ) ;
if ( F_25 ( V_2 -> V_83 ) ) {
V_53 = F_26 ( V_2 -> V_83 ) ;
F_27 ( & V_64 -> V_56 , L_2 , V_53 ) ;
return V_53 ;
}
V_66 = F_28 ( V_64 , V_84 , 0 ) ;
if ( ! V_66 ) {
F_27 ( & V_64 -> V_56 , L_3 ) ;
return - V_85 ;
}
if ( F_29 ( V_66 ) < 0x42 ) {
F_27 ( & V_64 -> V_56 , L_4 ) ;
return - V_74 ;
}
V_2 -> V_4 = F_30 ( & V_64 -> V_56 , V_66 ) ;
if ( F_25 ( V_2 -> V_4 ) )
return F_26 ( V_2 -> V_4 ) ;
V_53 = F_31 ( V_64 , 0 ) ;
if ( V_53 <= 0 ) {
F_27 ( & V_64 -> V_56 , L_5 , V_53 ) ;
if ( ! V_53 )
V_53 = - V_74 ;
return V_53 ;
}
V_2 -> V_25 = V_53 ;
V_53 = F_32 ( V_2 -> V_83 ) ;
if ( V_53 < 0 ) {
F_27 ( & V_64 -> V_56 , L_6 , V_53 ) ;
return V_53 ;
}
V_53 = F_33 ( V_69 , L_7 , & V_71 ) ;
if ( V_53 )
V_53 = F_33 ( V_69 , L_8 , & V_71 ) ;
if ( ! V_53 ) {
F_13 ( & V_64 -> V_56 , L_9 , V_71 ) ;
} else {
V_71 = F_16 ( V_2 ) ;
F_34 ( & V_64 -> V_56 , L_10 , V_71 ) ;
}
V_2 -> V_71 = V_71 ;
V_53 = F_33 ( V_69 , L_11 , & V_72 ) ;
if ( ! V_53 ) {
F_13 ( & V_64 -> V_56 , L_12 , V_72 ) ;
} else {
V_72 = 100000 ;
F_34 ( & V_64 -> V_56 , L_13 ) ;
}
V_2 -> V_72 = V_72 ;
V_67 = F_35 ( V_2 -> V_83 ) ;
if ( ! V_67 ) {
F_27 ( & V_64 -> V_56 , L_14 ) ;
V_53 = - V_74 ;
goto V_86;
}
V_73 = F_36 ( V_67 , 8 * V_2 -> V_72 ) - 1 ;
if ( V_73 >= 0x200 ) {
F_27 ( & V_64 -> V_56 ,
L_15 ,
V_67 , V_2 -> V_72 ) ;
V_53 = - V_74 ;
goto V_86;
}
F_13 ( & V_64 -> V_56 , L_16 ,
V_67 , V_2 -> V_72 , ( unsigned long ) V_73 ) ;
F_3 ( V_2 , V_87 , F_37 ( V_73 ) ) ;
F_3 ( V_2 , V_61 , V_88 |
V_89 |
F_38 ( V_2 -> V_71 ) ) ;
F_3 ( V_2 , V_90 , V_91 |
V_92 | 0 * V_93 ) ;
F_3 ( V_2 , V_31 , V_32 ) ;
F_3 ( V_2 , V_94 , V_95 | V_96 | V_97
| V_98 | V_99 | V_100 ) ;
F_3 ( V_2 , V_10 , V_39 ) ;
V_53 = F_39 ( V_2 -> V_25 , F_9 , 0 , V_101 , V_2 ) ;
if ( V_53 < 0 ) {
F_27 ( & V_64 -> V_56 , L_17 , V_53 ) ;
goto V_86;
}
V_53 = F_40 ( & V_2 -> V_55 ) ;
if ( V_53 ) {
F_41 ( V_2 -> V_25 , V_2 ) ;
V_86:
F_42 ( V_2 -> V_83 ) ;
}
return V_53 ;
}
static int F_43 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( V_64 ) ;
F_45 ( & V_2 -> V_55 ) ;
F_41 ( V_2 -> V_25 , V_2 ) ;
F_42 ( V_2 -> V_83 ) ;
return 0 ;
}
