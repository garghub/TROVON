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
}
static void F_10 ( struct V_1 * V_2 , unsigned long V_13 )
{
int V_15 ;
for ( V_15 = 10 ; V_15 < 250 ; V_15 += 10 ) {
if ( F_2 ( V_2 , V_13 ) & V_18 )
return;
F_8 ( 10 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned long V_13 ;
int V_14 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_4 ; ++ V_3 ) {
V_13 = V_5 + 2 * V_3 ;
V_14 = F_2 ( V_2 , V_13 ) ;
if ( F_12 ( V_14 & V_19 ) ) {
if ( F_13 ( V_20 , V_2 -> V_21 ) ) {
F_6 ( V_19 ) ;
F_8 ( 10 ) ;
if ( V_2 -> V_22 )
F_10 ( V_2 , V_13 ) ;
F_6 ( V_18 | V_23 ) ;
F_14 ( V_24 ) ;
}
}
if ( F_12 ( V_14 & V_25 ) ) {
if ( ! F_3 ( V_3 , & V_2 -> V_17 ) ) {
F_7 ( V_3 , & V_2 -> V_17 ) ;
V_2 -> V_21 = V_20 +
F_15 ( 25 ) ;
F_16 ( & F_17 ( V_2 ) -> V_26 ,
V_2 -> V_21 ) ;
} else if ( F_13 ( V_20 ,
V_2 -> V_21 ) ) {
F_5 ( V_2 , V_3 , V_13 ) ;
}
}
}
}
static int F_18 ( struct V_27 * V_28 , char * V_9 )
{
struct V_1 * V_2 = F_19 ( V_28 ) ;
unsigned long V_29 ;
int V_14 = 0 ;
F_20 ( & V_2 -> V_30 , V_29 ) ;
F_21 ( V_2 ) ;
if ( ! F_22 ( V_28 ) || V_2 -> V_31 )
goto V_32;
F_11 ( V_2 ) ;
V_14 = F_4 ( V_2 , V_9 ) ;
switch ( V_2 -> V_33 ) {
case V_34 :
if ( V_14 || V_2 -> V_17 ) {
V_14 = 1 ;
F_23 ( V_28 ) ;
}
break;
case V_35 :
if ( V_14 )
F_24 ( V_2 ) ;
break;
case V_36 :
if ( ! F_1 ( V_2 ) ) {
V_2 -> V_33 = V_37 ;
V_2 -> V_38 = V_20 + V_39 ;
}
break;
case V_37 :
if ( F_1 ( V_2 ) )
V_2 -> V_33 = V_36 ;
else if ( F_13 ( V_20 , V_2 -> V_38 ) )
F_25 ( V_2 , V_35 ) ;
break;
default:
break;
}
V_32:
F_26 ( & V_2 -> V_30 , V_29 ) ;
return V_14 ;
}
static int F_27 ( struct V_27 * V_28 , T_1 V_40 , T_1 V_41 ,
T_1 V_42 , char * V_9 , T_1 V_43 )
{
struct V_1 * V_2 = F_19 ( V_28 ) ;
int V_14 , V_44 , V_45 = 0 , V_46 = 0 ;
unsigned int V_3 = V_42 - 1 ;
unsigned long V_13 = V_5 + 2 * V_3 ;
T_1 V_47 , V_48 ;
unsigned long V_29 ;
if ( ! F_22 ( V_28 ) || V_2 -> V_31 )
return - V_49 ;
F_20 ( & V_2 -> V_30 , V_29 ) ;
switch ( V_40 ) {
case V_50 :
* ( V_51 * ) V_9 = F_28 ( 0 ) ;
F_29 ( 4 ) ;
case V_52 :
if ( V_3 >= V_2 -> V_4 )
goto V_53;
F_11 ( V_2 ) ;
V_14 = F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_54 )
V_14 ^= V_55 ;
V_47 = V_44 = 0 ;
if ( V_14 & V_18 )
V_47 |= V_56 ;
if ( V_14 & V_23 )
V_47 |= V_57 ;
if ( ( V_14 & V_12 ) && ! V_11 )
V_47 |= V_58 ;
if ( F_3 ( V_3 , & V_2 -> V_8 ) ) {
V_47 |= V_59 ;
V_44 |= 1 ;
}
if ( F_3 ( V_3 , & V_2 -> V_17 ) )
V_44 |= 4 ;
V_48 = V_60 ;
if ( V_14 & V_6 )
V_48 |= V_61 ;
if ( V_14 & V_24 ) {
V_48 |= V_62 ;
if ( V_14 & V_16 )
V_48 |= V_63 ;
}
if ( V_14 & V_55 )
V_48 |= V_64 ;
if ( V_14 & V_19 )
V_48 |= V_65 ;
if ( V_14 & V_66 )
V_48 |= V_67 ;
if ( V_47 )
F_30 ( F_31 ( V_2 ) , L_1 ,
V_42 , V_14 , V_44 ) ;
* ( V_68 * ) V_9 = F_32 ( V_48 ) ;
* ( V_68 * ) ( V_9 + 2 ) = F_32 ( V_47 ) ;
F_29 ( 4 ) ;
case V_69 :
case V_70 :
switch ( V_41 ) {
case V_71 :
case V_72 :
F_29 ( 0 ) ;
default:
goto V_53;
}
break;
case V_73 :
if ( V_3 >= V_2 -> V_4 )
goto V_53;
switch ( V_41 ) {
case V_74 :
F_14 ( V_75 ) ;
F_29 ( 0 ) ;
case V_76 :
F_14 ( V_19 ) ;
F_5 ( V_2 , V_3 , V_13 ) ;
V_2 -> V_21 = V_20 + F_15 ( 50 ) ;
F_29 ( 0 ) ;
case V_77 :
F_29 ( 0 ) ;
default:
goto V_53;
}
break;
case V_78 :
if ( V_3 >= V_2 -> V_4 )
goto V_53;
switch ( V_41 ) {
case V_79 :
F_6 ( V_24 ) ;
F_5 ( V_2 , V_3 , V_13 ) ;
F_29 ( 0 ) ;
case V_80 :
F_6 ( V_23 ) ;
F_29 ( 0 ) ;
case V_74 :
if ( ! ( F_2 ( V_2 , V_13 ) & V_75 ) ) {
F_5 ( V_2 , V_3 , V_13 ) ;
} else if ( ! F_33 ( V_3 ,
& V_2 -> V_17 ) ) {
F_14 ( V_25 ) ;
if ( ! ( F_2 ( V_2 , V_13 ) &
V_25 ) )
F_5 ( V_2 , V_3 ,
V_13 ) ;
else
V_2 -> V_21 = V_20 +
F_15 ( 20 ) ;
}
F_29 ( 0 ) ;
case V_81 :
F_9 ( V_3 , & V_2 -> V_8 ) ;
F_29 ( 0 ) ;
case V_77 :
goto V_53;
case V_82 :
F_6 ( V_18 ) ;
F_29 ( 0 ) ;
case V_83 :
F_6 ( V_12 ) ;
F_29 ( 0 ) ;
case V_84 :
F_29 ( 0 ) ;
default:
goto V_53;
}
break;
case V_85 :
V_46 = F_34 (unsigned int, sizeof(root_hub_hub_des), wLength) ;
memcpy ( V_9 , V_86 , V_46 ) ;
if ( V_46 > 2 )
V_9 [ 2 ] = V_2 -> V_4 ;
F_29 ( V_46 ) ;
default:
V_53:
V_45 = - V_87 ;
}
F_26 ( & V_2 -> V_30 , V_29 ) ;
return V_45 ;
}
