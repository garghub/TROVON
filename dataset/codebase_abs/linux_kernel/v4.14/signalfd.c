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
V_23 |= F_15 ( V_22 -> V_28 , & V_21 -> V_29 ) ;
switch ( F_16 ( V_22 -> V_24 , V_22 -> V_28 ) ) {
case V_30 :
V_23 |= F_15 ( V_22 -> V_31 , & V_21 -> V_32 ) ;
V_23 |= F_15 ( V_22 -> V_33 , & V_21 -> V_34 ) ;
break;
case V_35 :
V_23 |= F_15 ( V_22 -> V_36 , & V_21 -> V_37 ) ;
V_23 |= F_15 ( V_22 -> V_38 , & V_21 -> V_39 ) ;
V_23 |= F_15 ( ( long ) V_22 -> V_40 , & V_21 -> V_41 ) ;
V_23 |= F_15 ( V_22 -> V_42 , & V_21 -> V_43 ) ;
break;
case V_44 :
V_23 |= F_15 ( V_22 -> V_45 , & V_21 -> V_46 ) ;
V_23 |= F_15 ( V_22 -> V_47 , & V_21 -> V_48 ) ;
break;
case V_49 :
V_23 |= F_15 ( ( long ) V_22 -> V_50 , & V_21 -> V_51 ) ;
#ifdef F_17
V_23 |= F_15 ( V_22 -> V_52 , & V_21 -> V_53 ) ;
#endif
#ifdef F_18
if ( V_22 -> V_24 == V_54 &&
( V_22 -> V_28 == V_55 ||
V_22 -> V_28 == F_18 ) )
V_23 |= F_15 ( ( short ) V_22 -> V_56 ,
& V_21 -> V_57 ) ;
#endif
break;
case V_58 :
V_23 |= F_15 ( V_22 -> V_31 , & V_21 -> V_32 ) ;
V_23 |= F_15 ( V_22 -> V_33 , & V_21 -> V_34 ) ;
V_23 |= F_15 ( V_22 -> V_59 , & V_21 -> V_60 ) ;
V_23 |= F_15 ( V_22 -> V_61 , & V_21 -> V_62 ) ;
V_23 |= F_15 ( V_22 -> V_63 , & V_21 -> V_64 ) ;
break;
case V_65 :
default:
V_23 |= F_15 ( V_22 -> V_31 , & V_21 -> V_32 ) ;
V_23 |= F_15 ( V_22 -> V_33 , & V_21 -> V_34 ) ;
V_23 |= F_15 ( ( long ) V_22 -> V_40 , & V_21 -> V_41 ) ;
V_23 |= F_15 ( V_22 -> V_42 , & V_21 -> V_43 ) ;
break;
}
return V_23 ? - V_66 : sizeof( * V_21 ) ;
}
static T_5 F_19 ( struct V_11 * V_12 , T_4 * V_67 ,
int V_68 )
{
T_5 V_69 ;
F_20 ( V_10 , V_14 ) ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
V_69 = F_21 ( V_14 , & V_12 -> V_17 , V_67 ) ;
switch ( V_69 ) {
case 0 :
if ( ! V_68 )
break;
V_69 = - V_70 ;
default:
F_11 ( & V_14 -> V_2 -> V_15 ) ;
return V_69 ;
}
F_22 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
for (; ; ) {
F_23 ( V_71 ) ;
V_69 = F_21 ( V_14 , & V_12 -> V_17 , V_67 ) ;
if ( V_69 != 0 )
break;
if ( F_24 ( V_14 ) ) {
V_69 = - V_72 ;
break;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_25 () ;
F_9 ( & V_14 -> V_2 -> V_15 ) ;
}
F_11 ( & V_14 -> V_2 -> V_15 ) ;
F_26 ( & V_14 -> V_2 -> V_4 , & V_10 ) ;
F_27 ( V_73 ) ;
return V_69 ;
}
static T_5 F_28 ( struct V_8 * V_8 , char T_3 * V_74 , T_6 V_75 ,
T_7 * V_76 )
{
struct V_11 * V_12 = V_8 -> V_9 ;
struct V_20 T_3 * V_77 ;
int V_68 = V_8 -> V_78 & V_79 ;
T_5 V_69 , V_80 = 0 ;
T_4 V_67 ;
V_75 /= sizeof( struct V_20 ) ;
if ( ! V_75 )
return - V_81 ;
V_77 = (struct V_20 T_3 * ) V_74 ;
do {
V_69 = F_19 ( V_12 , & V_67 , V_68 ) ;
if ( F_29 ( V_69 <= 0 ) )
break;
V_69 = F_12 ( V_77 , & V_67 ) ;
if ( V_69 < 0 )
break;
V_77 ++ ;
V_80 += V_69 ;
V_68 = 1 ;
} while ( -- V_75 );
return V_80 ? V_80 : V_69 ;
}
static void F_30 ( struct V_82 * V_83 , struct V_8 * V_84 )
{
struct V_11 * V_12 = V_84 -> V_9 ;
T_8 V_17 ;
V_17 = V_12 -> V_17 ;
F_31 ( & V_17 ) ;
F_32 ( V_83 , L_1 , & V_17 ) ;
}
