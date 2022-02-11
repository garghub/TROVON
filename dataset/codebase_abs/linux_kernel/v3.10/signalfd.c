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
if ( V_22 -> V_28 == V_55 ||
V_22 -> V_28 == F_17 )
V_23 |= F_15 ( ( short ) V_22 -> V_56 ,
& V_21 -> V_57 ) ;
#endif
break;
case V_58 :
V_23 |= F_15 ( V_22 -> V_32 , & V_21 -> V_33 ) ;
V_23 |= F_15 ( V_22 -> V_34 , & V_21 -> V_35 ) ;
V_23 |= F_15 ( V_22 -> V_59 , & V_21 -> V_60 ) ;
V_23 |= F_15 ( V_22 -> V_61 , & V_21 -> V_62 ) ;
V_23 |= F_15 ( V_22 -> V_63 , & V_21 -> V_64 ) ;
break;
case V_65 :
case V_66 :
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
return V_23 ? - V_67 : sizeof( * V_21 ) ;
}
static T_5 F_18 ( struct V_11 * V_12 , T_4 * V_68 ,
int V_69 )
{
T_5 V_70 ;
F_19 ( V_10 , V_14 ) ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
V_70 = F_20 ( V_14 , & V_12 -> V_17 , V_68 ) ;
switch ( V_70 ) {
case 0 :
if ( ! V_69 )
break;
V_70 = - V_71 ;
default:
F_11 ( & V_14 -> V_2 -> V_15 ) ;
return V_70 ;
}
F_21 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
for (; ; ) {
F_22 ( V_72 ) ;
V_70 = F_20 ( V_14 , & V_12 -> V_17 , V_68 ) ;
if ( V_70 != 0 )
break;
if ( F_23 ( V_14 ) ) {
V_70 = - V_73 ;
break;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_24 () ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_25 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
F_26 ( V_74 ) ;
return V_70 ;
}
static T_5 F_27 ( struct V_8 * V_8 , char T_3 * V_75 , T_6 V_76 ,
T_7 * V_77 )
{
struct V_11 * V_12 = V_8 -> V_9 ;
struct V_20 T_3 * V_78 ;
int V_69 = V_8 -> V_79 & V_80 ;
T_5 V_70 , V_81 = 0 ;
T_4 V_68 ;
V_76 /= sizeof( struct V_20 ) ;
if ( ! V_76 )
return - V_82 ;
V_78 = (struct V_20 T_3 * ) V_75 ;
do {
V_70 = F_18 ( V_12 , & V_68 , V_69 ) ;
if ( F_28 ( V_70 <= 0 ) )
break;
V_70 = F_12 ( V_78 , & V_68 ) ;
if ( V_70 < 0 )
break;
V_78 ++ ;
V_81 += V_70 ;
V_69 = 1 ;
} while ( -- V_76 );
return V_81 ? V_81 : V_70 ;
}
static int F_29 ( struct V_83 * V_84 , struct V_8 * V_85 )
{
struct V_11 * V_12 = V_85 -> V_9 ;
T_8 V_17 ;
V_17 = V_12 -> V_17 ;
F_30 ( & V_17 ) ;
F_31 ( V_84 , L_1 , & V_17 ) ;
return 0 ;
}
