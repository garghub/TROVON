static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_2 -> V_5 & V_6 )
F_2 ( V_2 -> V_7 + ( V_3 << 2 ) , V_4 ) ;
#ifdef F_3
else
F_4 ( V_2 -> V_8 , V_3 , V_4 ) ;
#endif
}
static int
F_5 ( unsigned V_9 , unsigned V_10 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 , struct V_14 * V_15 )
{
T_1 * V_16 = V_15 -> V_17 ;
if ( V_9 >= V_18 )
return - V_19 ;
if ( V_15 -> V_20 . V_21 ) {
V_10 = V_11 = V_12 =
( V_10 * 77 + V_11 * 151 + V_12 * 28 + 127 ) >> 8 ;
}
V_10 >>= 8 ;
V_11 >>= 8 ;
V_12 >>= 8 ;
V_16 [ V_9 ] = ( V_10 << V_22 ) | ( V_11 << V_23 ) |
( V_12 << V_24 ) ;
return 0 ;
}
static int
F_6 ( int V_25 , struct V_14 * V_15 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
switch ( V_25 ) {
case V_26 :
F_1 ( V_2 , V_27 , V_2 -> V_28 ) ;
break;
case V_29 :
case V_30 :
case V_31 :
case V_32 :
F_1 ( V_2 , V_27 , 0 ) ;
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_33 * V_34 ,
struct V_1 * V_2 ,
unsigned long V_35 ,
struct V_36 * V_37 )
{
int V_38 ;
int V_39 = V_37 -> V_40 * V_37 -> V_41 * V_42 ;
if ( V_2 -> V_5 & V_6 ) {
if ( ! F_9 ( V_35 , 8 , V_43 ) ) {
F_10 ( V_34 , L_1 ,
V_35 ) ;
V_38 = - V_44 ;
goto V_45;
}
V_2 -> V_46 = V_35 ;
V_2 -> V_7 = F_11 ( V_35 , 8 ) ;
if ( ! V_2 -> V_7 ) {
F_10 ( V_34 , L_1 ,
V_35 ) ;
V_38 = - V_44 ;
goto V_47;
}
}
if ( V_37 -> V_48 ) {
V_2 -> V_48 = V_37 -> V_48 ;
V_2 -> V_49 = F_11 ( V_37 -> V_48 , V_39 ) ;
} else {
V_2 -> V_50 = 1 ;
V_2 -> V_49 = F_12 ( V_34 , F_13 ( V_39 ) ,
& V_2 -> V_48 , V_51 ) ;
}
if ( ! V_2 -> V_49 ) {
F_10 ( V_34 , L_2 ) ;
V_38 = - V_52 ;
if ( V_2 -> V_5 & V_6 )
goto V_53;
else
goto V_45;
}
F_14 ( ( void V_54 * ) V_2 -> V_49 , 0 , V_39 ) ;
F_1 ( V_2 , V_55 , V_2 -> V_48 ) ;
V_2 -> V_28 = V_56 ;
if ( V_37 -> V_57 )
V_2 -> V_28 |= V_58 ;
F_1 ( V_2 , V_27 ,
V_2 -> V_28 ) ;
V_2 -> V_59 . V_33 = V_34 ;
V_2 -> V_59 . V_60 = ( void V_54 * ) V_2 -> V_49 ;
V_2 -> V_59 . V_61 = & V_62 ;
V_2 -> V_59 . V_63 = V_64 ;
V_2 -> V_59 . V_63 . V_65 = V_2 -> V_48 ;
V_2 -> V_59 . V_63 . V_66 = V_39 ;
V_2 -> V_59 . V_63 . V_67 = V_37 -> V_40 * V_42 ;
V_2 -> V_59 . V_17 = V_2 -> V_17 ;
V_2 -> V_59 . V_5 = V_68 ;
V_2 -> V_59 . V_20 = V_69 ;
V_2 -> V_59 . V_20 . V_70 = V_37 -> V_71 ;
V_2 -> V_59 . V_20 . V_72 = V_37 -> V_73 ;
V_2 -> V_59 . V_20 . V_74 = V_37 -> V_74 ;
V_2 -> V_59 . V_20 . V_75 = V_37 -> V_75 ;
V_2 -> V_59 . V_20 . V_76 = V_37 -> V_40 ;
V_2 -> V_59 . V_20 . V_77 = V_37 -> V_41 ;
V_38 = F_15 ( & V_2 -> V_59 . V_78 , V_18 , 0 ) ;
if ( V_38 ) {
F_10 ( V_34 , L_3 ,
V_18 ) ;
goto V_79;
}
V_38 = F_16 ( & V_2 -> V_59 ) ;
if ( V_38 ) {
F_10 ( V_34 , L_4 ) ;
goto V_80;
}
if ( V_2 -> V_5 & V_6 ) {
F_17 ( V_34 , L_5 , V_35 ,
V_2 -> V_7 ) ;
}
F_17 ( V_34 , L_6 ,
( unsigned long long ) V_2 -> V_48 , V_2 -> V_49 , V_39 ) ;
return 0 ;
V_80:
F_18 ( & V_2 -> V_59 . V_78 ) ;
V_79:
if ( V_2 -> V_50 )
F_19 ( V_34 , F_13 ( V_39 ) , V_2 -> V_49 ,
V_2 -> V_48 ) ;
else
F_20 ( V_2 -> V_49 ) ;
F_1 ( V_2 , V_27 , 0 ) ;
V_53:
if ( V_2 -> V_5 & V_6 )
F_20 ( V_2 -> V_7 ) ;
V_47:
if ( V_2 -> V_5 & V_6 )
F_21 ( V_35 , 8 ) ;
V_45:
F_22 ( V_2 ) ;
F_23 ( V_34 , NULL ) ;
return V_38 ;
}
static int F_24 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_25 ( V_34 ) ;
#if ! F_26 ( V_81 ) && F_26 ( V_82 )
F_6 ( V_83 , & V_2 -> V_59 ) ;
#endif
F_27 ( & V_2 -> V_59 ) ;
F_18 ( & V_2 -> V_59 . V_78 ) ;
if ( V_2 -> V_50 )
F_19 ( V_34 , F_13 ( V_2 -> V_59 . V_63 . V_66 ) ,
V_2 -> V_49 , V_2 -> V_48 ) ;
else
F_20 ( V_2 -> V_49 ) ;
F_1 ( V_2 , V_27 , 0 ) ;
if ( V_2 -> V_5 & V_6 ) {
F_20 ( V_2 -> V_7 ) ;
F_21 ( V_2 -> V_46 , 8 ) ;
}
#ifdef F_3
else
F_28 ( V_2 -> V_8 , V_2 -> V_84 ) ;
#endif
F_22 ( V_2 ) ;
F_23 ( V_34 , NULL ) ;
return 0 ;
}
static int F_29 ( struct V_85 * V_86 )
{
const T_1 * V_87 ;
T_1 * V_88 ;
T_1 V_89 ;
struct V_36 V_37 ;
struct V_90 V_91 ;
int V_92 , V_38 ;
struct V_1 * V_2 ;
V_37 = V_93 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 ) {
F_10 ( & V_86 -> V_34 , L_7 ) ;
return - V_52 ;
}
V_88 = ( T_1 * ) F_31 ( V_86 -> V_34 . V_94 , L_8 , NULL ) ;
V_89 = V_88 ? * V_88 : 0 ;
if ( V_89 ) {
V_2 -> V_5 |= V_6 ;
V_38 = F_32 ( V_86 -> V_34 . V_94 , 0 , & V_91 ) ;
if ( V_38 ) {
F_10 ( & V_86 -> V_34 , L_9 ) ;
goto V_95;
}
}
#ifdef F_3
else {
int V_96 ;
V_91 . V_96 = 0 ;
V_96 = F_33 ( V_86 -> V_34 . V_94 , 0 ) ;
V_2 -> V_84 = F_34 ( V_86 -> V_34 . V_94 , 0 ) ;
V_2 -> V_8 = F_35 ( V_86 -> V_34 . V_94 , V_96 , V_2 -> V_84 ) ;
if ( ! F_36 ( V_2 -> V_8 ) ) {
F_10 ( & V_86 -> V_34 , L_10 ) ;
goto V_95;
}
}
#endif
V_87 = F_31 ( V_86 -> V_34 . V_94 , L_11 , & V_92 ) ;
if ( ( V_87 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_73 = V_87 [ 0 ] ;
V_37 . V_71 = V_87 [ 1 ] ;
}
V_87 = F_31 ( V_86 -> V_34 . V_94 , L_12 , & V_92 ) ;
if ( ( V_87 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_74 = V_87 [ 0 ] ;
V_37 . V_75 = V_87 [ 1 ] ;
}
V_87 = F_31 ( V_86 -> V_34 . V_94 , L_13 , & V_92 ) ;
if ( ( V_87 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_40 = V_87 [ 0 ] ;
V_37 . V_41 = V_87 [ 1 ] ;
}
if ( F_37 ( V_86 -> V_34 . V_94 , L_14 , NULL ) )
V_37 . V_57 = 1 ;
F_23 ( & V_86 -> V_34 , V_2 ) ;
return F_8 ( & V_86 -> V_34 , V_2 , V_91 . V_96 , & V_37 ) ;
V_95:
F_22 ( V_2 ) ;
return - V_44 ;
}
static int F_38 ( struct V_85 * V_86 )
{
return F_24 ( & V_86 -> V_34 ) ;
}
