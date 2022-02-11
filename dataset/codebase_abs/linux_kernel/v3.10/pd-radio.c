static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 2 ) ;
V_3 = F_4 ( V_2 -> V_7 , 0 , V_8 ) ;
if ( V_3 < 0 )
goto V_9;
V_3 = F_5 ( V_2 , V_10 ) ;
if ( V_3 != 0 )
goto V_9;
V_3 = F_6 ( V_2 , V_11 , V_12 , & V_4 ) ;
V_3 = F_6 ( V_2 , V_13 ,
V_2 -> V_14 . V_15 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_16 ,
V_17 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_18 ,
V_19 , & V_4 ) ;
V_3 |= F_6 ( V_2 , V_20 , V_21 , & V_4 ) ;
V_9:
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
F_4 ( V_2 -> V_7 , 0 , 0 ) ;
F_10 ( 300 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_12 ( V_2 , V_2 -> V_14 . V_22 ) ;
F_13 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
int V_3 = 0 ;
F_16 ( & V_2 -> V_25 ) ;
if ( V_2 -> V_26 & V_27 ) {
V_3 = - V_28 ;
goto V_9;
}
if ( V_2 -> V_26 && ! ( V_2 -> V_26 & V_29 ) ) {
V_3 = - V_30 ;
goto V_9;
}
V_3 = F_17 ( V_24 ) ;
if ( V_3 )
goto V_9;
F_18 ( V_2 -> V_31 ) ;
if ( 0 == V_2 -> V_26 ) {
struct V_32 * V_33 = & V_2 -> V_14 . V_34 ;
if ( V_2 -> V_14 . V_15 == 0 )
V_2 -> V_14 . V_15 = V_35 ;
F_19 ( V_33 , V_36 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_20 ( V_2 -> V_31 ) ;
goto V_9;
}
V_2 -> V_26 |= V_29 ;
}
F_21 ( & V_2 -> V_37 ) ;
V_9:
F_22 ( & V_2 -> V_25 ) ;
return V_3 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_24 ) ;
struct V_14 * V_38 = & V_2 -> V_14 ;
T_2 V_4 ;
F_16 ( & V_2 -> V_25 ) ;
if ( F_24 ( V_24 ) )
V_2 -> V_26 &= ~ V_29 ;
if ( V_38 -> V_39 && V_24 == V_2 -> V_40 ) {
V_38 -> V_39 = 0 ;
F_6 ( V_2 , V_41 , V_42 , & V_4 ) ;
}
F_20 ( V_2 -> V_31 ) ;
F_22 ( & V_2 -> V_25 ) ;
F_25 ( & V_2 -> V_37 , V_43 ) ;
return F_26 ( V_24 ) ;
}
static int F_27 ( struct V_23 * V_23 , void * V_44 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
F_28 ( V_46 -> V_47 , L_1 , sizeof( V_46 -> V_47 ) ) ;
F_28 ( V_46 -> V_48 , L_2 , sizeof( V_46 -> V_48 ) ) ;
F_29 ( V_2 -> V_7 , V_46 -> V_49 , sizeof( V_46 -> V_49 ) ) ;
V_46 -> V_50 = V_51 | V_52 ;
V_46 -> V_53 = V_46 -> V_50 | V_54 |
V_55 | V_56 |
V_57 | V_58 |
V_59 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_23 , void * V_44 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_62 V_63 = {} ;
int V_3 , V_4 , V_64 = 5 ;
if ( V_61 -> V_65 != 0 )
return - V_66 ;
V_61 -> type = V_67 ;
V_61 -> V_68 = V_69 | V_70 ;
V_61 -> V_71 = V_21 * 2 / 125 ;
V_61 -> V_72 = V_73 * 2 / 125 ;
V_61 -> V_74 = V_75 ;
V_61 -> V_76 = V_77 ;
V_61 -> signal = 0 ;
V_61 -> V_78 = 0 ;
F_28 ( V_61 -> V_79 , L_3 , sizeof( V_61 -> V_79 ) ) ;
F_16 ( & V_2 -> V_25 ) ;
V_3 = F_31 ( V_2 , V_80 , V_10 ,
& V_63 , & V_4 , sizeof( V_63 ) ) ;
while ( V_63 . V_81 && V_64 -- && ! V_3 ) {
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
V_3 = F_31 ( V_2 , V_80 , V_10 ,
& V_63 , & V_4 , sizeof( V_63 ) ) ;
}
F_22 ( & V_2 -> V_25 ) ;
if ( V_3 || V_4 ) {
V_61 -> signal = 0 ;
} else if ( ( V_63 . V_82 || V_63 . V_83 )
&& V_63 . V_84 == 0 ) {
V_61 -> signal = 0xffff ;
} else
V_61 -> signal = ( V_63 . V_84 * 255 / 10 ) << 8 ;
return 0 ;
}
static int F_32 ( struct V_23 * V_23 , void * V_44 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
if ( V_86 -> V_87 )
return - V_66 ;
V_86 -> V_88 = V_2 -> V_14 . V_22 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 V_88 )
{
T_3 V_89 ;
int V_3 , V_4 ;
F_16 ( & V_2 -> V_25 ) ;
V_3 = F_6 ( V_2 , V_13 ,
V_2 -> V_14 . V_15 , & V_4 ) ;
V_89 = ( V_88 * 125 ) / 2 ;
V_89 = F_33 ( V_89 , V_21 , V_73 ) ;
V_3 = F_6 ( V_2 , V_20 , V_89 , & V_4 ) ;
if ( V_3 < 0 )
goto error ;
V_3 = F_6 ( V_2 , V_90 , 0 , & V_4 ) ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 4 ) ;
if ( ! V_2 -> V_14 . V_39 ) {
V_3 = F_6 ( V_2 , V_90 , 0 , & V_4 ) ;
V_3 = F_6 ( V_2 , V_41 ,
V_91 , & V_4 ) ;
V_2 -> V_14 . V_39 = 1 ;
}
V_2 -> V_14 . V_22 = V_89 * 2 / 125 ;
error:
F_22 ( & V_2 -> V_25 ) ;
return V_3 ;
}
static int F_34 ( struct V_23 * V_23 , void * V_44 ,
const struct V_85 * V_86 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
if ( V_86 -> V_87 )
return - V_66 ;
V_2 -> V_40 = V_23 ;
#ifdef F_35
V_2 -> V_92 = F_7 ;
V_2 -> V_93 = F_11 ;
#endif
return F_12 ( V_2 , V_86 -> V_88 ) ;
}
static int F_36 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_37 ( V_95 -> V_96 , struct V_1 ,
V_14 . V_97 ) ;
int V_15 ;
T_1 V_4 ;
switch ( V_95 -> V_98 ) {
case V_99 :
V_15 = V_100 [ V_95 -> V_101 ] ;
F_6 ( V_2 , V_13 , V_15 , & V_4 ) ;
V_2 -> V_14 . V_15 = V_15 ;
return 0 ;
}
return - V_66 ;
}
static int F_38 ( struct V_23 * V_23 , void * V_44 , const struct V_60 * V_61 )
{
return V_61 -> V_65 > 0 ? - V_66 : 0 ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = & V_2 -> V_14 . V_34 ;
struct V_102 * V_103 = & V_2 -> V_14 . V_97 ;
* V_33 = V_104 ;
F_12 ( V_2 , V_21 ) ;
F_40 ( V_103 , 1 ) ;
F_41 ( V_103 , & V_105 , V_99 ,
V_106 , 0 , V_107 ) ;
if ( V_103 -> error ) {
F_42 ( V_103 ) ;
return V_103 -> error ;
}
V_33 -> V_108 = & V_2 -> V_108 ;
V_33 -> V_97 = V_103 ;
F_43 ( V_109 , & V_33 -> V_110 ) ;
F_44 ( V_33 , V_2 ) ;
return F_45 ( V_33 , V_111 , - 1 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_14 . V_34 ) ;
F_42 ( & V_2 -> V_14 . V_97 ) ;
return 0 ;
}
