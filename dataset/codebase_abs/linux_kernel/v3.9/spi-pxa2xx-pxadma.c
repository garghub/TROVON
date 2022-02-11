bool F_1 ( T_1 V_1 )
{
return V_1 > 0 && V_1 <= V_2 ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_10 -> V_9 ;
if ( ! V_4 -> V_11 -> V_12 )
return 0 ;
if ( V_6 -> V_13 )
return V_4 -> V_14 && V_4 -> V_15 ;
if ( ! F_3 ( V_4 -> V_16 ) || ! F_3 ( V_4 -> V_17 ) )
return 0 ;
if ( V_4 -> V_16 == NULL ) {
* V_4 -> V_18 = 0 ;
V_4 -> V_16 = V_4 -> V_18 ;
V_4 -> V_19 = 4 ;
} else
V_4 -> V_19 = V_4 -> V_1 ;
if ( V_4 -> V_17 == NULL ) {
* V_4 -> V_18 = 0 ;
V_4 -> V_17 = V_4 -> V_18 ;
V_4 -> V_20 = 4 ;
} else
V_4 -> V_20 = V_4 -> V_1 ;
V_4 -> V_15 = F_4 ( V_9 , V_4 -> V_17 ,
V_4 -> V_20 , V_21 ) ;
if ( F_5 ( V_9 , V_4 -> V_15 ) )
return 0 ;
V_4 -> V_14 = F_4 ( V_9 , V_4 -> V_16 ,
V_4 -> V_19 , V_22 ) ;
if ( F_5 ( V_9 , V_4 -> V_14 ) ) {
F_6 ( V_9 , V_4 -> V_15 ,
V_4 -> V_20 , V_21 ) ;
return 0 ;
}
return 1 ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
if ( ! V_4 -> V_23 )
return;
if ( ! V_4 -> V_7 -> V_13 ) {
V_9 = & V_4 -> V_7 -> V_10 -> V_9 ;
F_6 ( V_9 , V_4 -> V_14 ,
V_4 -> V_19 , V_22 ) ;
F_6 ( V_9 , V_4 -> V_15 ,
V_4 -> V_20 , V_21 ) ;
}
V_4 -> V_23 = 0 ;
}
static int F_8 ( void const T_2 * V_24 )
{
unsigned long V_25 = V_26 << 1 ;
while ( ( F_9 ( V_24 ) & V_27 ) && -- V_25 )
F_10 () ;
return V_25 ;
}
static int F_11 ( int V_28 )
{
unsigned long V_25 = V_26 << 1 ;
while ( ! ( F_12 ( V_28 ) & V_29 ) && -- V_25 )
F_10 () ;
return V_25 ;
}
static void F_13 ( struct V_3 * V_4 ,
const char * V_6 )
{
void T_2 * V_30 = V_4 -> V_24 ;
F_12 ( V_4 -> V_31 ) = V_32 ;
F_12 ( V_4 -> V_33 ) = V_32 ;
F_14 ( V_4 , V_4 -> V_34 ) ;
F_15 ( F_16 ( V_30 ) & ~ V_4 -> V_35 , V_30 ) ;
if ( ! F_17 ( V_4 ) )
F_18 ( 0 , V_30 ) ;
F_19 ( V_4 ) ;
F_20 ( F_21 ( V_30 ) & ~ V_36 , V_30 ) ;
F_7 ( V_4 ) ;
F_22 ( & V_4 -> V_37 -> V_9 , L_1 , V_6 ) ;
V_4 -> V_7 -> V_38 = V_39 ;
F_23 ( & V_4 -> V_40 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
void T_2 * V_30 = V_4 -> V_24 ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_15 ( F_16 ( V_30 ) & ~ V_4 -> V_35 , V_30 ) ;
F_14 ( V_4 , V_4 -> V_34 ) ;
F_12 ( V_4 -> V_33 ) = V_32 ;
F_12 ( V_4 -> V_31 ) = V_32 ;
if ( F_11 ( V_4 -> V_31 ) == 0 )
F_22 ( & V_4 -> V_37 -> V_9 ,
L_2 ) ;
if ( F_8 ( V_4 -> V_24 ) == 0 )
F_22 ( & V_4 -> V_37 -> V_9 ,
L_3 ) ;
F_7 ( V_4 ) ;
V_4 -> V_16 += V_4 -> V_1 -
( F_25 ( V_4 -> V_31 ) & V_41 ) ;
V_4 -> V_42 ( V_4 ) ;
V_6 -> V_43 += V_4 -> V_1 -
( V_4 -> V_44 - V_4 -> V_16 ) ;
V_6 -> V_38 = F_26 ( V_4 ) ;
F_23 ( & V_4 -> V_40 ) ;
}
void F_27 ( int V_28 , void * V_45 )
{
struct V_3 * V_4 = V_45 ;
T_3 V_46 = F_12 ( V_28 ) & V_47 ;
if ( V_46 & V_48 ) {
if ( V_28 == V_4 -> V_33 )
F_13 ( V_4 ,
L_4 ) ;
else
F_13 ( V_4 ,
L_5 ) ;
return;
}
if ( ( V_28 == V_4 -> V_33 )
&& ( V_46 & V_49 )
&& ( V_4 -> V_50 == V_51 ) ) {
if ( F_8 ( V_4 -> V_24 ) == 0 )
F_22 ( & V_4 -> V_37 -> V_9 ,
L_6 ) ;
F_24 ( V_4 ) ;
}
}
T_4 F_28 ( struct V_3 * V_4 )
{
T_3 V_46 ;
void T_2 * V_30 = V_4 -> V_24 ;
V_46 = F_9 ( V_30 ) & V_4 -> V_52 ;
if ( V_46 & V_53 ) {
F_13 ( V_4 ,
L_7 ) ;
return V_54 ;
}
if ( ( V_46 & V_55 )
&& ( F_12 ( V_4 -> V_33 ) & V_56 ) ) {
F_29 ( V_55 , V_30 ) ;
return V_54 ;
}
if ( V_46 & V_55 || V_4 -> V_16 == V_4 -> V_44 ) {
if ( ! F_17 ( V_4 ) )
F_18 ( 0 , V_30 ) ;
F_24 ( V_4 ) ;
return V_54 ;
}
return V_57 ;
}
int F_30 ( struct V_3 * V_4 , T_3 V_58 )
{
T_3 V_59 ;
switch ( V_4 -> V_60 ) {
case 1 :
V_59 = V_61 ;
break;
case 2 :
V_59 = V_62 ;
break;
default:
V_59 = V_63 ;
break;
}
F_12 ( V_4 -> V_31 ) = V_32 ;
F_31 ( V_4 -> V_31 ) = V_4 -> V_64 ;
F_32 ( V_4 -> V_31 ) = V_4 -> V_14 ;
if ( V_4 -> V_16 == V_4 -> V_18 )
F_25 ( V_4 -> V_31 ) = V_65
| V_59
| V_58
| V_4 -> V_1 ;
else
F_25 ( V_4 -> V_31 ) = V_66
| V_65
| V_59
| V_58
| V_4 -> V_1 ;
F_12 ( V_4 -> V_33 ) = V_32 ;
F_31 ( V_4 -> V_33 ) = V_4 -> V_15 ;
F_32 ( V_4 -> V_33 ) = V_4 -> V_64 ;
if ( V_4 -> V_17 == V_4 -> V_18 )
F_25 ( V_4 -> V_33 ) = V_67
| V_59
| V_58
| V_4 -> V_1 ;
else
F_25 ( V_4 -> V_33 ) = V_68
| V_67
| V_59
| V_58
| V_4 -> V_1 ;
if ( V_4 -> V_50 == V_51 )
F_25 ( V_4 -> V_33 ) |= V_69 ;
return 0 ;
}
void F_33 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_31 ) |= V_56 ;
F_12 ( V_4 -> V_33 ) |= V_56 ;
}
int F_34 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_37 -> V_9 ;
struct V_70 * V_71 = V_4 -> V_71 ;
V_4 -> V_31 = F_35 ( L_8 ,
V_72 ,
F_27 ,
V_4 ) ;
if ( V_4 -> V_31 < 0 ) {
F_22 ( V_9 , L_9 ,
V_4 -> V_31 ) ;
return - V_73 ;
}
V_4 -> V_33 = F_35 ( L_10 ,
V_74 ,
F_27 ,
V_4 ) ;
if ( V_4 -> V_33 < 0 ) {
F_22 ( V_9 , L_11 ,
V_4 -> V_33 ) ;
F_36 ( V_4 -> V_31 ) ;
return - V_73 ;
}
F_37 ( V_71 -> V_75 ) = V_76 | V_4 -> V_31 ;
F_37 ( V_71 -> V_77 ) = V_76 | V_4 -> V_33 ;
return 0 ;
}
void F_38 ( struct V_3 * V_4 )
{
struct V_70 * V_71 = V_4 -> V_71 ;
F_37 ( V_71 -> V_75 ) = 0 ;
F_37 ( V_71 -> V_77 ) = 0 ;
if ( V_4 -> V_33 != 0 )
F_36 ( V_4 -> V_33 ) ;
if ( V_4 -> V_31 != 0 )
F_36 ( V_4 -> V_31 ) ;
}
void F_39 ( struct V_3 * V_4 )
{
if ( V_4 -> V_31 != - 1 )
F_37 ( V_4 -> V_71 -> V_75 ) =
V_76 | V_4 -> V_31 ;
if ( V_4 -> V_33 != - 1 )
F_37 ( V_4 -> V_71 -> V_77 ) =
V_76 | V_4 -> V_33 ;
}
int F_40 ( struct V_78 * V_79 ,
struct V_80 * V_10 ,
T_5 V_81 , T_3 * V_82 ,
T_3 * V_83 )
{
struct V_84 * V_85 =
(struct V_84 * ) V_10 -> V_86 ;
int V_87 ;
int V_88 ;
int V_89 ;
int V_90 ;
int V_91 = 0 ;
if ( V_81 <= 8 )
V_87 = 1 ;
else if ( V_81 <= 16 )
V_87 = 2 ;
else
V_87 = 4 ;
if ( V_85 )
V_90 = V_85 -> V_92 ;
else {
switch ( V_79 -> V_92 ) {
default:
V_79 -> V_92 = V_93 ;
case V_93 :
V_90 = 8 ;
break;
case V_94 :
V_90 = 16 ;
break;
case V_95 :
V_90 = 32 ;
break;
}
}
if ( V_90 <= 8 ) {
* V_82 = V_93 ;
V_88 = 8 ;
} else if ( V_90 <= 16 ) {
if ( V_87 == 1 ) {
* V_82 = V_93 ;
V_88 = 8 ;
V_91 = 1 ;
} else {
* V_82 = V_94 ;
V_88 = 16 ;
}
} else {
if ( V_87 == 1 ) {
* V_82 = V_93 ;
V_88 = 8 ;
V_91 = 1 ;
} else if ( V_87 == 2 ) {
* V_82 = V_94 ;
V_88 = 16 ;
V_91 = 1 ;
} else {
* V_82 = V_95 ;
V_88 = 32 ;
}
}
V_89 = V_88 / V_87 ;
* V_83 = ( F_41 ( V_89 ) & V_96 )
| ( F_42 ( 16 - V_89 ) & V_97 ) ;
return V_91 ;
}
