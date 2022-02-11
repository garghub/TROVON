static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; ++ V_3 ) {
if ( ( F_2 ( V_2 , V_5 + V_3 * 2 ) &
( V_6 | V_7 ) ) ||
F_3 ( V_3 , & V_2 -> V_8 ) )
return 1 ;
}
return 0 ;
}
static inline int F_4 ( struct V_1 * V_2 , char * V_9 )
{
int V_3 ;
int V_10 = V_7 ;
if ( V_11 )
V_10 &= ~ V_12 ;
* V_9 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; ++ V_3 ) {
if ( ( F_2 ( V_2 , V_5 + V_3 * 2 ) & V_10 ) ||
F_3 ( V_3 , & V_2 -> V_8 ) )
* V_9 |= ( 1 << ( V_3 + 1 ) ) ;
}
return ! ! * V_9 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
unsigned long V_13 )
{
int V_14 ;
int V_15 ;
if ( F_2 ( V_2 , V_13 ) & V_16 ) {
F_6 ( V_16 ) ;
if ( F_3 ( V_3 , & V_2 -> V_17 ) )
F_7 ( V_3 , & V_2 -> V_8 ) ;
for ( V_15 = 0 ; V_15 < 10 ; ++ V_15 ) {
if ( ! ( F_2 ( V_2 , V_13 ) & V_16 ) )
break;
F_8 ( 1 ) ;
}
}
F_9 ( V_3 , & V_2 -> V_17 ) ;
F_10 ( & F_11 ( V_2 ) -> V_18 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned long V_13 )
{
int V_15 ;
for ( V_15 = 10 ; V_15 < 250 ; V_15 += 10 ) {
if ( F_2 ( V_2 , V_13 ) & V_19 )
return;
F_8 ( 10 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned long V_13 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; ++ V_3 ) {
V_13 = V_5 + 2 * V_3 ;
V_14 = F_2 ( V_2 , V_13 ) ;
if ( F_14 ( V_14 & V_20 ) ) {
if ( F_15 ( V_21 , V_2 -> V_22 ) ) {
F_6 ( V_20 ) ;
F_8 ( 10 ) ;
if ( V_2 -> V_23 )
F_12 ( V_2 , V_13 ) ;
F_6 ( V_19 | V_24 ) ;
F_16 ( V_25 ) ;
}
}
if ( F_14 ( V_14 & V_26 ) ) {
if ( ! F_3 ( V_3 , & V_2 -> V_17 ) ) {
F_7 ( V_3 , & V_2 -> V_17 ) ;
V_2 -> V_22 = V_21 +
F_17 ( 25 ) ;
F_18 (
& F_11 ( V_2 ) -> V_18 , V_3 ) ;
F_19 ( & F_11 ( V_2 ) -> V_27 ,
V_2 -> V_22 ) ;
} else if ( F_15 ( V_21 ,
V_2 -> V_22 ) ) {
F_5 ( V_2 , V_3 , V_13 ) ;
}
}
}
}
static int F_20 ( struct V_28 * V_29 , char * V_9 )
{
struct V_1 * V_2 = F_21 ( V_29 ) ;
unsigned long V_30 ;
int V_14 = 0 ;
F_22 ( & V_2 -> V_31 , V_30 ) ;
F_23 ( V_2 ) ;
if ( ! F_24 ( V_29 ) || V_2 -> V_32 )
goto V_33;
F_13 ( V_2 ) ;
V_14 = F_4 ( V_2 , V_9 ) ;
switch ( V_2 -> V_34 ) {
case V_35 :
if ( V_14 || V_2 -> V_17 ) {
V_14 = 1 ;
F_25 ( V_29 ) ;
}
break;
case V_36 :
if ( V_14 )
F_26 ( V_2 ) ;
break;
case V_37 :
if ( ! F_1 ( V_2 ) ) {
V_2 -> V_34 = V_38 ;
V_2 -> V_39 = V_21 + V_40 ;
}
break;
case V_38 :
if ( F_1 ( V_2 ) )
V_2 -> V_34 = V_37 ;
else if ( F_15 ( V_21 , V_2 -> V_39 ) )
F_27 ( V_2 , V_36 ) ;
break;
default:
break;
}
V_33:
F_28 ( & V_2 -> V_31 , V_30 ) ;
return V_14 ;
}
static int F_29 ( struct V_28 * V_29 , T_1 V_41 , T_1 V_42 ,
T_1 V_43 , char * V_9 , T_1 V_44 )
{
struct V_1 * V_2 = F_21 ( V_29 ) ;
int V_14 , V_45 , V_46 = 0 , V_47 = 0 ;
unsigned int V_3 = V_43 - 1 ;
unsigned long V_13 = V_5 + 2 * V_3 ;
T_1 V_48 , V_49 ;
unsigned long V_30 ;
if ( ! F_24 ( V_29 ) || V_2 -> V_32 )
return - V_50 ;
F_22 ( & V_2 -> V_31 , V_30 ) ;
switch ( V_41 ) {
case V_51 :
* ( V_52 * ) V_9 = F_30 ( 0 ) ;
F_31 ( 4 ) ;
case V_53 :
if ( V_3 >= V_2 -> V_4 )
goto V_54;
F_13 ( V_2 ) ;
V_14 = F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_55 )
V_14 ^= V_56 ;
V_48 = V_45 = 0 ;
if ( V_14 & V_19 )
V_48 |= V_57 ;
if ( V_14 & V_24 )
V_48 |= V_58 ;
if ( ( V_14 & V_12 ) && ! V_11 )
V_48 |= V_59 ;
if ( F_3 ( V_3 , & V_2 -> V_8 ) ) {
V_48 |= V_60 ;
V_45 |= 1 ;
}
if ( F_3 ( V_3 , & V_2 -> V_17 ) )
V_45 |= 4 ;
V_49 = V_61 ;
if ( V_14 & V_6 )
V_49 |= V_62 ;
if ( V_14 & V_25 ) {
V_49 |= V_63 ;
if ( V_14 & V_16 )
V_49 |= V_64 ;
}
if ( V_14 & V_56 )
V_49 |= V_65 ;
if ( V_14 & V_20 )
V_49 |= V_66 ;
if ( V_14 & V_67 )
V_49 |= V_68 ;
if ( V_48 )
F_32 ( F_33 ( V_2 ) , L_1 ,
V_43 , V_14 , V_45 ) ;
* ( V_69 * ) V_9 = F_34 ( V_49 ) ;
* ( V_69 * ) ( V_9 + 2 ) = F_34 ( V_48 ) ;
F_31 ( 4 ) ;
case V_70 :
case V_71 :
switch ( V_42 ) {
case V_72 :
case V_73 :
F_31 ( 0 ) ;
default:
goto V_54;
}
break;
case V_74 :
if ( V_3 >= V_2 -> V_4 )
goto V_54;
switch ( V_42 ) {
case V_75 :
F_16 ( V_76 ) ;
F_31 ( 0 ) ;
case V_77 :
F_16 ( V_20 ) ;
F_5 ( V_2 , V_3 , V_13 ) ;
V_2 -> V_22 = V_21 + F_17 ( 50 ) ;
F_31 ( 0 ) ;
case V_78 :
F_31 ( 0 ) ;
default:
goto V_54;
}
break;
case V_79 :
if ( V_3 >= V_2 -> V_4 )
goto V_54;
switch ( V_42 ) {
case V_80 :
F_6 ( V_25 ) ;
F_5 ( V_2 , V_3 , V_13 ) ;
F_31 ( 0 ) ;
case V_81 :
F_6 ( V_24 ) ;
F_31 ( 0 ) ;
case V_75 :
if ( ! ( F_2 ( V_2 , V_13 ) & V_76 ) ) {
F_5 ( V_2 , V_3 , V_13 ) ;
} else if ( ! F_35 ( V_3 ,
& V_2 -> V_17 ) ) {
F_16 ( V_26 ) ;
if ( ! ( F_2 ( V_2 , V_13 ) &
V_26 ) )
F_5 ( V_2 , V_3 ,
V_13 ) ;
else
V_2 -> V_22 = V_21 +
F_17 ( 20 ) ;
}
F_31 ( 0 ) ;
case V_82 :
F_9 ( V_3 , & V_2 -> V_8 ) ;
F_31 ( 0 ) ;
case V_78 :
goto V_54;
case V_83 :
F_6 ( V_19 ) ;
F_31 ( 0 ) ;
case V_84 :
F_6 ( V_12 ) ;
F_31 ( 0 ) ;
case V_85 :
F_31 ( 0 ) ;
default:
goto V_54;
}
break;
case V_86 :
V_47 = F_36 (unsigned int, sizeof(root_hub_hub_des), wLength) ;
memcpy ( V_9 , V_87 , V_47 ) ;
if ( V_47 > 2 )
V_9 [ 2 ] = V_2 -> V_4 ;
F_31 ( V_47 ) ;
default:
V_54:
V_46 = - V_88 ;
}
F_28 ( & V_2 -> V_31 , V_30 ) ;
return V_46 ;
}
