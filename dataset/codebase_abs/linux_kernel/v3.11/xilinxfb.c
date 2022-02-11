static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( V_2 -> V_5 & V_6 ) {
if ( V_2 -> V_5 & V_7 )
F_2 ( V_4 , V_2 -> V_8 + ( V_3 << 2 ) ) ;
else
F_3 ( V_4 , V_2 -> V_8 + ( V_3 << 2 ) ) ;
}
#ifdef F_4
else
F_5 ( V_2 -> V_9 , V_3 , V_4 ) ;
#endif
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 & V_6 ) {
if ( V_2 -> V_5 & V_7 )
return F_7 ( V_2 -> V_8 + ( V_3 << 2 ) ) ;
else
return F_8 ( V_2 -> V_8 + ( V_3 << 2 ) ) ;
}
#ifdef F_4
else
return F_9 ( V_2 -> V_9 , V_3 ) ;
#endif
return 0 ;
}
static int
F_10 ( unsigned V_10 , unsigned V_11 , unsigned V_12 , unsigned V_13 ,
unsigned V_14 , struct V_15 * V_16 )
{
T_1 * V_17 = V_16 -> V_18 ;
if ( V_10 >= V_19 )
return - V_20 ;
if ( V_16 -> V_21 . V_22 ) {
V_11 = V_12 = V_13 =
( V_11 * 77 + V_12 * 151 + V_13 * 28 + 127 ) >> 8 ;
}
V_11 >>= 8 ;
V_12 >>= 8 ;
V_13 >>= 8 ;
V_17 [ V_10 ] = ( V_11 << V_23 ) | ( V_12 << V_24 ) |
( V_13 << V_25 ) ;
return 0 ;
}
static int
F_11 ( int V_26 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
switch ( V_26 ) {
case V_27 :
F_1 ( V_2 , V_28 , V_2 -> V_29 ) ;
break;
case V_30 :
case V_31 :
case V_32 :
case V_33 :
F_1 ( V_2 , V_28 , 0 ) ;
default:
break;
}
return 0 ;
}
static int F_13 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_36 * V_37 )
{
int V_38 ;
struct V_39 * V_40 = & V_35 -> V_40 ;
int V_41 = V_37 -> V_42 * V_37 -> V_43 * V_44 ;
if ( V_2 -> V_5 & V_6 ) {
struct V_45 * V_46 ;
V_46 = F_14 ( V_35 , V_47 , 0 ) ;
V_2 -> V_48 = V_46 -> V_49 ;
V_2 -> V_8 = F_15 ( & V_35 -> V_40 , V_46 ) ;
if ( ! V_2 -> V_8 ) {
V_38 = - V_50 ;
goto V_51;
}
}
if ( V_37 -> V_52 ) {
V_2 -> V_52 = V_37 -> V_52 ;
V_2 -> V_53 = F_16 ( V_37 -> V_52 , V_41 ) ;
} else {
V_2 -> V_54 = 1 ;
V_2 -> V_53 = F_17 ( V_40 , F_18 ( V_41 ) ,
& V_2 -> V_52 , V_55 ) ;
}
if ( ! V_2 -> V_53 ) {
F_19 ( V_40 , L_1 ) ;
V_38 = - V_56 ;
if ( V_2 -> V_5 & V_6 )
goto V_57;
else
goto V_51;
}
F_20 ( ( void V_58 * ) V_2 -> V_53 , 0 , V_41 ) ;
F_1 ( V_2 , V_59 , V_2 -> V_52 ) ;
V_38 = F_6 ( V_2 , V_59 ) ;
if ( V_38 != V_2 -> V_52 ) {
V_2 -> V_5 |= V_7 ;
F_1 ( V_2 , V_59 , V_2 -> V_52 ) ;
}
V_2 -> V_29 = V_60 ;
if ( V_37 -> V_61 )
V_2 -> V_29 |= V_62 ;
F_1 ( V_2 , V_28 ,
V_2 -> V_29 ) ;
V_2 -> V_63 . V_39 = V_40 ;
V_2 -> V_63 . V_64 = ( void V_58 * ) V_2 -> V_53 ;
V_2 -> V_63 . V_65 = & V_66 ;
V_2 -> V_63 . V_67 = V_68 ;
V_2 -> V_63 . V_67 . V_69 = V_2 -> V_52 ;
V_2 -> V_63 . V_67 . V_70 = V_41 ;
V_2 -> V_63 . V_67 . V_71 = V_37 -> V_42 * V_44 ;
V_2 -> V_63 . V_18 = V_2 -> V_18 ;
V_2 -> V_63 . V_5 = V_72 ;
V_2 -> V_63 . V_21 = V_73 ;
V_2 -> V_63 . V_21 . V_74 = V_37 -> V_75 ;
V_2 -> V_63 . V_21 . V_76 = V_37 -> V_77 ;
V_2 -> V_63 . V_21 . V_78 = V_37 -> V_78 ;
V_2 -> V_63 . V_21 . V_79 = V_37 -> V_79 ;
V_2 -> V_63 . V_21 . V_80 = V_37 -> V_42 ;
V_2 -> V_63 . V_21 . V_81 = V_37 -> V_43 ;
V_38 = F_21 ( & V_2 -> V_63 . V_82 , V_19 , 0 ) ;
if ( V_38 ) {
F_19 ( V_40 , L_2 ,
V_19 ) ;
goto V_83;
}
V_38 = F_22 ( & V_2 -> V_63 ) ;
if ( V_38 ) {
F_19 ( V_40 , L_3 ) ;
goto V_84;
}
if ( V_2 -> V_5 & V_6 ) {
F_23 ( V_40 , L_4 ,
& V_2 -> V_48 , V_2 -> V_8 ) ;
}
F_23 ( V_40 , L_5 ,
( unsigned long long ) V_2 -> V_52 , V_2 -> V_53 , V_41 ) ;
return 0 ;
V_84:
F_24 ( & V_2 -> V_63 . V_82 ) ;
V_83:
if ( V_2 -> V_54 )
F_25 ( V_40 , F_18 ( V_41 ) , V_2 -> V_53 ,
V_2 -> V_52 ) ;
else
F_26 ( V_2 -> V_53 ) ;
F_1 ( V_2 , V_28 , 0 ) ;
V_57:
if ( V_2 -> V_5 & V_6 )
F_27 ( V_40 , V_2 -> V_8 ) ;
V_51:
F_28 ( V_2 ) ;
F_29 ( V_40 , NULL ) ;
return V_38 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_31 ( V_40 ) ;
#if ! F_32 ( V_85 ) && F_32 ( V_86 )
F_11 ( V_87 , & V_2 -> V_63 ) ;
#endif
F_33 ( & V_2 -> V_63 ) ;
F_24 ( & V_2 -> V_63 . V_82 ) ;
if ( V_2 -> V_54 )
F_25 ( V_40 , F_18 ( V_2 -> V_63 . V_67 . V_70 ) ,
V_2 -> V_53 , V_2 -> V_52 ) ;
else
F_26 ( V_2 -> V_53 ) ;
F_1 ( V_2 , V_28 , 0 ) ;
if ( V_2 -> V_5 & V_6 )
F_27 ( V_40 , V_2 -> V_8 ) ;
#ifdef F_4
else
F_34 ( V_2 -> V_9 , V_2 -> V_88 ) ;
#endif
F_28 ( V_2 ) ;
F_29 ( V_40 , NULL ) ;
return 0 ;
}
static int F_35 ( struct V_34 * V_89 )
{
const T_1 * V_90 ;
T_1 V_91 = 0 ;
struct V_36 V_37 ;
int V_92 ;
struct V_1 * V_2 ;
V_37 = V_93 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 ) {
F_19 ( & V_89 -> V_40 , L_6 ) ;
return - V_56 ;
}
F_37 ( V_89 -> V_40 . V_94 , L_7 ,
& V_91 ) ;
if ( V_91 ) {
V_2 -> V_5 |= V_6 ;
}
#ifdef F_4
else {
int V_49 ;
V_49 = F_38 ( V_89 -> V_40 . V_94 , 0 ) ;
V_2 -> V_88 = F_39 ( V_89 -> V_40 . V_94 , 0 ) ;
V_2 -> V_9 = F_40 ( V_89 -> V_40 . V_94 , V_49 , V_2 -> V_88 ) ;
if ( ! F_41 ( V_2 -> V_9 ) ) {
F_19 ( & V_89 -> V_40 , L_8 ) ;
F_28 ( V_2 ) ;
return - V_95 ;
}
}
#endif
V_90 = F_42 ( V_89 -> V_40 . V_94 , L_9 , & V_92 ) ;
if ( ( V_90 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_77 = V_90 [ 0 ] ;
V_37 . V_75 = V_90 [ 1 ] ;
}
V_90 = F_42 ( V_89 -> V_40 . V_94 , L_10 , & V_92 ) ;
if ( ( V_90 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_78 = V_90 [ 0 ] ;
V_37 . V_79 = V_90 [ 1 ] ;
}
V_90 = F_42 ( V_89 -> V_40 . V_94 , L_11 , & V_92 ) ;
if ( ( V_90 ) && ( V_92 >= sizeof( T_1 ) * 2 ) ) {
V_37 . V_42 = V_90 [ 0 ] ;
V_37 . V_43 = V_90 [ 1 ] ;
}
if ( F_43 ( V_89 -> V_40 . V_94 , L_12 , NULL ) )
V_37 . V_61 = 1 ;
F_29 ( & V_89 -> V_40 , V_2 ) ;
return F_13 ( V_89 , V_2 , & V_37 ) ;
}
static int F_44 ( struct V_34 * V_89 )
{
return F_30 ( & V_89 -> V_40 ) ;
}
