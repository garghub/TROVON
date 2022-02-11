void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = & V_2 -> V_4 ;
if ( F_2 ( ! F_3 ( V_3 ) ) )
return;
F_4 ( V_3 , V_5 | V_6 ) ;
}
static int F_5 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
F_6 ( V_8 -> V_9 ) ;
return 0 ;
}
static unsigned int F_7 ( struct V_8 * V_8 , T_2 * V_10 )
{
struct V_11 * V_12 = V_8 -> V_9 ;
unsigned int V_13 = 0 ;
F_8 ( V_8 , & V_14 -> V_2 -> V_4 , V_10 ) ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
if ( F_10 ( & V_14 -> V_16 , & V_12 -> V_17 ) ||
F_10 ( & V_14 -> signal -> V_18 ,
& V_12 -> V_17 ) )
V_13 |= V_19 ;
F_11 ( & V_14 -> V_2 -> V_15 ) ;
return V_13 ;
}
static int F_12 ( struct V_20 T_3 * V_21 ,
T_4 const * V_22 )
{
long V_23 ;
F_13 ( sizeof( struct V_20 ) != 128 ) ;
V_23 = F_14 ( V_21 , sizeof( * V_21 ) ) ;
V_23 |= F_15 ( V_22 -> V_24 , & V_21 -> V_25 ) ;
V_23 |= F_15 ( V_22 -> V_26 , & V_21 -> V_27 ) ;
V_23 |= F_15 ( ( short ) V_22 -> V_28 , & V_21 -> V_29 ) ;
switch ( V_22 -> V_28 & V_30 ) {
case V_31 :
V_23 |= F_15 ( V_22 -> V_32 , & V_21 -> V_33 ) ;
V_23 |= F_15 ( V_22 -> V_34 , & V_21 -> V_35 ) ;
break;
case V_36 :
V_23 |= F_15 ( V_22 -> V_37 , & V_21 -> V_38 ) ;
V_23 |= F_15 ( V_22 -> V_39 , & V_21 -> V_40 ) ;
V_23 |= F_15 ( ( long ) V_22 -> V_41 , & V_21 -> V_42 ) ;
V_23 |= F_15 ( V_22 -> V_43 , & V_21 -> V_44 ) ;
break;
case V_45 :
V_23 |= F_15 ( V_22 -> V_46 , & V_21 -> V_47 ) ;
V_23 |= F_15 ( V_22 -> V_48 , & V_21 -> V_49 ) ;
break;
case V_50 :
V_23 |= F_15 ( ( long ) V_22 -> V_51 , & V_21 -> V_52 ) ;
#ifdef F_16
V_23 |= F_15 ( V_22 -> V_53 , & V_21 -> V_54 ) ;
#endif
#ifdef F_17
if ( V_22 -> V_24 == V_55 &&
( V_22 -> V_28 == V_56 ||
V_22 -> V_28 == F_17 ) )
V_23 |= F_15 ( ( short ) V_22 -> V_57 ,
& V_21 -> V_58 ) ;
#endif
break;
case V_59 :
V_23 |= F_15 ( V_22 -> V_32 , & V_21 -> V_33 ) ;
V_23 |= F_15 ( V_22 -> V_34 , & V_21 -> V_35 ) ;
V_23 |= F_15 ( V_22 -> V_60 , & V_21 -> V_61 ) ;
V_23 |= F_15 ( V_22 -> V_62 , & V_21 -> V_63 ) ;
V_23 |= F_15 ( V_22 -> V_64 , & V_21 -> V_65 ) ;
break;
case V_66 :
case V_67 :
V_23 |= F_15 ( V_22 -> V_32 , & V_21 -> V_33 ) ;
V_23 |= F_15 ( V_22 -> V_34 , & V_21 -> V_35 ) ;
V_23 |= F_15 ( ( long ) V_22 -> V_41 , & V_21 -> V_42 ) ;
V_23 |= F_15 ( V_22 -> V_43 , & V_21 -> V_44 ) ;
break;
default:
V_23 |= F_15 ( V_22 -> V_32 , & V_21 -> V_33 ) ;
V_23 |= F_15 ( V_22 -> V_34 , & V_21 -> V_35 ) ;
V_23 |= F_15 ( ( long ) V_22 -> V_41 , & V_21 -> V_42 ) ;
V_23 |= F_15 ( V_22 -> V_43 , & V_21 -> V_44 ) ;
break;
}
return V_23 ? - V_68 : sizeof( * V_21 ) ;
}
static T_5 F_18 ( struct V_11 * V_12 , T_4 * V_69 ,
int V_70 )
{
T_5 V_71 ;
F_19 ( V_10 , V_14 ) ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
V_71 = F_20 ( V_14 , & V_12 -> V_17 , V_69 ) ;
switch ( V_71 ) {
case 0 :
if ( ! V_70 )
break;
V_71 = - V_72 ;
default:
F_11 ( & V_14 -> V_2 -> V_15 ) ;
return V_71 ;
}
F_21 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
for (; ; ) {
F_22 ( V_73 ) ;
V_71 = F_20 ( V_14 , & V_12 -> V_17 , V_69 ) ;
if ( V_71 != 0 )
break;
if ( F_23 ( V_14 ) ) {
V_71 = - V_74 ;
break;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_24 () ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_25 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
F_26 ( V_75 ) ;
return V_71 ;
}
static T_5 F_27 ( struct V_8 * V_8 , char T_3 * V_76 , T_6 V_77 ,
T_7 * V_78 )
{
struct V_11 * V_12 = V_8 -> V_9 ;
struct V_20 T_3 * V_79 ;
int V_70 = V_8 -> V_80 & V_81 ;
T_5 V_71 , V_82 = 0 ;
T_4 V_69 ;
V_77 /= sizeof( struct V_20 ) ;
if ( ! V_77 )
return - V_83 ;
V_79 = (struct V_20 T_3 * ) V_76 ;
do {
V_71 = F_18 ( V_12 , & V_69 , V_70 ) ;
if ( F_28 ( V_71 <= 0 ) )
break;
V_71 = F_12 ( V_79 , & V_69 ) ;
if ( V_71 < 0 )
break;
V_79 ++ ;
V_82 += V_71 ;
V_70 = 1 ;
} while ( -- V_77 );
return V_82 ? V_82 : V_71 ;
}
static void F_29 ( struct V_84 * V_85 , struct V_8 * V_86 )
{
struct V_11 * V_12 = V_86 -> V_9 ;
T_8 V_17 ;
V_17 = V_12 -> V_17 ;
F_30 ( & V_17 ) ;
F_31 ( V_85 , L_1 , & V_17 ) ;
}
