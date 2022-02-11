static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
return 0 ;
}
static unsigned int F_3 ( struct V_2 * V_2 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
unsigned int V_7 = 0 ;
F_4 ( V_2 , & V_8 -> V_9 -> V_10 , V_4 ) ;
F_5 ( & V_8 -> V_9 -> V_11 ) ;
if ( F_6 ( & V_8 -> V_12 , & V_6 -> V_13 ) ||
F_6 ( & V_8 -> signal -> V_14 ,
& V_6 -> V_13 ) )
V_7 |= V_15 ;
F_7 ( & V_8 -> V_9 -> V_11 ) ;
return V_7 ;
}
static int F_8 ( struct V_16 T_2 * V_17 ,
T_3 const * V_18 )
{
long V_19 ;
F_9 ( sizeof( struct V_16 ) != 128 ) ;
V_19 = F_10 ( V_17 , sizeof( * V_17 ) ) ;
V_19 |= F_11 ( V_18 -> V_20 , & V_17 -> V_21 ) ;
V_19 |= F_11 ( V_18 -> V_22 , & V_17 -> V_23 ) ;
V_19 |= F_11 ( ( short ) V_18 -> V_24 , & V_17 -> V_25 ) ;
switch ( V_18 -> V_24 & V_26 ) {
case V_27 :
V_19 |= F_11 ( V_18 -> V_28 , & V_17 -> V_29 ) ;
V_19 |= F_11 ( V_18 -> V_30 , & V_17 -> V_31 ) ;
break;
case V_32 :
V_19 |= F_11 ( V_18 -> V_33 , & V_17 -> V_34 ) ;
V_19 |= F_11 ( V_18 -> V_35 , & V_17 -> V_36 ) ;
V_19 |= F_11 ( ( long ) V_18 -> V_37 , & V_17 -> V_38 ) ;
V_19 |= F_11 ( V_18 -> V_39 , & V_17 -> V_40 ) ;
break;
case V_41 :
V_19 |= F_11 ( V_18 -> V_42 , & V_17 -> V_43 ) ;
V_19 |= F_11 ( V_18 -> V_44 , & V_17 -> V_45 ) ;
break;
case V_46 :
V_19 |= F_11 ( ( long ) V_18 -> V_47 , & V_17 -> V_48 ) ;
#ifdef F_12
V_19 |= F_11 ( V_18 -> V_49 , & V_17 -> V_50 ) ;
#endif
#ifdef F_13
if ( V_18 -> V_24 == V_51 ||
V_18 -> V_24 == F_13 )
V_19 |= F_11 ( ( short ) V_18 -> V_52 ,
& V_17 -> V_53 ) ;
#endif
break;
case V_54 :
V_19 |= F_11 ( V_18 -> V_28 , & V_17 -> V_29 ) ;
V_19 |= F_11 ( V_18 -> V_30 , & V_17 -> V_31 ) ;
V_19 |= F_11 ( V_18 -> V_55 , & V_17 -> V_56 ) ;
V_19 |= F_11 ( V_18 -> V_57 , & V_17 -> V_58 ) ;
V_19 |= F_11 ( V_18 -> V_59 , & V_17 -> V_60 ) ;
break;
case V_61 :
case V_62 :
V_19 |= F_11 ( V_18 -> V_28 , & V_17 -> V_29 ) ;
V_19 |= F_11 ( V_18 -> V_30 , & V_17 -> V_31 ) ;
V_19 |= F_11 ( ( long ) V_18 -> V_37 , & V_17 -> V_38 ) ;
V_19 |= F_11 ( V_18 -> V_39 , & V_17 -> V_40 ) ;
break;
default:
V_19 |= F_11 ( V_18 -> V_28 , & V_17 -> V_29 ) ;
V_19 |= F_11 ( V_18 -> V_30 , & V_17 -> V_31 ) ;
V_19 |= F_11 ( ( long ) V_18 -> V_37 , & V_17 -> V_38 ) ;
V_19 |= F_11 ( V_18 -> V_39 , & V_17 -> V_40 ) ;
break;
}
return V_19 ? - V_63 : sizeof( * V_17 ) ;
}
static T_4 F_14 ( struct V_5 * V_6 , T_3 * V_64 ,
int V_65 )
{
T_4 V_66 ;
F_15 ( V_4 , V_8 ) ;
F_5 ( & V_8 -> V_9 -> V_11 ) ;
V_66 = F_16 ( V_8 , & V_6 -> V_13 , V_64 ) ;
switch ( V_66 ) {
case 0 :
if ( ! V_65 )
break;
V_66 = - V_67 ;
default:
F_7 ( & V_8 -> V_9 -> V_11 ) ;
return V_66 ;
}
F_17 ( & V_8 -> V_9 -> V_10 , & V_4 ) ;
for (; ; ) {
F_18 ( V_68 ) ;
V_66 = F_16 ( V_8 , & V_6 -> V_13 , V_64 ) ;
if ( V_66 != 0 )
break;
if ( F_19 ( V_8 ) ) {
V_66 = - V_69 ;
break;
}
F_7 ( & V_8 -> V_9 -> V_11 ) ;
F_20 () ;
F_5 ( & V_8 -> V_9 -> V_11 ) ;
}
F_7 ( & V_8 -> V_9 -> V_11 ) ;
F_21 ( & V_8 -> V_9 -> V_10 , & V_4 ) ;
F_22 ( V_70 ) ;
return V_66 ;
}
static T_4 F_23 ( struct V_2 * V_2 , char T_2 * V_71 , T_5 V_72 ,
T_6 * V_73 )
{
struct V_5 * V_6 = V_2 -> V_3 ;
struct V_16 T_2 * V_74 ;
int V_65 = V_2 -> V_75 & V_76 ;
T_4 V_66 , V_77 = 0 ;
T_3 V_64 ;
V_72 /= sizeof( struct V_16 ) ;
if ( ! V_72 )
return - V_78 ;
V_74 = (struct V_16 T_2 * ) V_71 ;
do {
V_66 = F_14 ( V_6 , & V_64 , V_65 ) ;
if ( F_24 ( V_66 <= 0 ) )
break;
V_66 = F_8 ( V_74 , & V_64 ) ;
if ( V_66 < 0 )
break;
V_74 ++ ;
V_77 += V_66 ;
V_65 = 1 ;
} while ( -- V_72 );
return V_77 ? V_77 : V_66 ;
}
