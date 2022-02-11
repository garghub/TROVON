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
static int F_8 ( struct V_3 * V_4 )
{
unsigned long V_24 = V_25 << 1 ;
while ( ( F_9 ( V_4 , V_26 ) & V_27 ) && -- V_24 )
F_10 () ;
return V_24 ;
}
static int F_11 ( int V_28 )
{
unsigned long V_24 = V_25 << 1 ;
while ( ! ( F_12 ( V_28 ) & V_29 ) && -- V_24 )
F_10 () ;
return V_24 ;
}
static void F_13 ( struct V_3 * V_4 ,
const char * V_6 )
{
F_12 ( V_4 -> V_30 ) = V_31 ;
F_12 ( V_4 -> V_32 ) = V_31 ;
F_14 ( V_4 , V_4 -> V_33 ) ;
F_15 ( V_4 , V_34 ,
F_9 ( V_4 , V_34 )
& ~ V_4 -> V_35 ) ;
if ( ! F_16 ( V_4 ) )
F_15 ( V_4 , V_36 , 0 ) ;
F_17 ( V_4 ) ;
F_15 ( V_4 , V_37 ,
F_9 ( V_4 , V_37 ) & ~ V_38 ) ;
F_7 ( V_4 ) ;
F_18 ( & V_4 -> V_39 -> V_9 , L_1 , V_6 ) ;
V_4 -> V_7 -> V_40 = V_41 ;
F_19 ( & V_4 -> V_42 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_15 ( V_4 , V_34 ,
F_9 ( V_4 , V_34 )
& ~ V_4 -> V_35 ) ;
F_14 ( V_4 , V_4 -> V_33 ) ;
F_12 ( V_4 -> V_32 ) = V_31 ;
F_12 ( V_4 -> V_30 ) = V_31 ;
if ( F_11 ( V_4 -> V_30 ) == 0 )
F_18 ( & V_4 -> V_39 -> V_9 ,
L_2 ) ;
if ( F_8 ( V_4 -> V_43 ) == 0 )
F_18 ( & V_4 -> V_39 -> V_9 ,
L_3 ) ;
F_7 ( V_4 ) ;
V_4 -> V_16 += V_4 -> V_1 -
( F_21 ( V_4 -> V_30 ) & V_44 ) ;
V_4 -> V_45 ( V_4 ) ;
V_6 -> V_46 += V_4 -> V_1 -
( V_4 -> V_47 - V_4 -> V_16 ) ;
V_6 -> V_40 = F_22 ( V_4 ) ;
F_19 ( & V_4 -> V_42 ) ;
}
void F_23 ( int V_28 , void * V_48 )
{
struct V_3 * V_4 = V_48 ;
T_2 V_49 = F_12 ( V_28 ) & V_50 ;
if ( V_49 & V_51 ) {
if ( V_28 == V_4 -> V_32 )
F_13 ( V_4 ,
L_4 ) ;
else
F_13 ( V_4 ,
L_5 ) ;
return;
}
if ( ( V_28 == V_4 -> V_32 )
&& ( V_49 & V_52 )
&& ( V_4 -> V_53 == V_54 ) ) {
if ( F_8 ( V_4 ) == 0 )
F_18 ( & V_4 -> V_39 -> V_9 ,
L_6 ) ;
F_20 ( V_4 ) ;
}
}
T_3 F_24 ( struct V_3 * V_4 )
{
T_2 V_49 ;
V_49 = F_9 ( V_4 , V_26 ) & V_4 -> V_55 ;
if ( V_49 & V_56 ) {
F_13 ( V_4 ,
L_7 ) ;
return V_57 ;
}
if ( ( V_49 & V_58 )
&& ( F_12 ( V_4 -> V_32 ) & V_59 ) ) {
F_15 ( V_4 , V_26 , V_58 ) ;
return V_57 ;
}
if ( V_49 & V_58 || V_4 -> V_16 == V_4 -> V_47 ) {
if ( ! F_16 ( V_4 ) )
F_15 ( V_4 , V_36 , 0 ) ;
F_20 ( V_4 ) ;
return V_57 ;
}
return V_60 ;
}
int F_25 ( struct V_3 * V_4 , T_2 V_61 )
{
T_2 V_62 ;
switch ( V_4 -> V_63 ) {
case 1 :
V_62 = V_64 ;
break;
case 2 :
V_62 = V_65 ;
break;
default:
V_62 = V_66 ;
break;
}
F_12 ( V_4 -> V_30 ) = V_31 ;
F_26 ( V_4 -> V_30 ) = V_4 -> V_67 ;
F_27 ( V_4 -> V_30 ) = V_4 -> V_14 ;
if ( V_4 -> V_16 == V_4 -> V_18 )
F_21 ( V_4 -> V_30 ) = V_68
| V_62
| V_61
| V_4 -> V_1 ;
else
F_21 ( V_4 -> V_30 ) = V_69
| V_68
| V_62
| V_61
| V_4 -> V_1 ;
F_12 ( V_4 -> V_32 ) = V_31 ;
F_26 ( V_4 -> V_32 ) = V_4 -> V_15 ;
F_27 ( V_4 -> V_32 ) = V_4 -> V_67 ;
if ( V_4 -> V_17 == V_4 -> V_18 )
F_21 ( V_4 -> V_32 ) = V_70
| V_62
| V_61
| V_4 -> V_1 ;
else
F_21 ( V_4 -> V_32 ) = V_71
| V_70
| V_62
| V_61
| V_4 -> V_1 ;
if ( V_4 -> V_53 == V_54 )
F_21 ( V_4 -> V_32 ) |= V_72 ;
return 0 ;
}
void F_28 ( struct V_3 * V_4 )
{
F_12 ( V_4 -> V_30 ) |= V_59 ;
F_12 ( V_4 -> V_32 ) |= V_59 ;
}
int F_29 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = & V_4 -> V_39 -> V_9 ;
struct V_73 * V_74 = V_4 -> V_74 ;
V_4 -> V_30 = F_30 ( L_8 ,
V_75 ,
F_23 ,
V_4 ) ;
if ( V_4 -> V_30 < 0 ) {
F_18 ( V_9 , L_9 ,
V_4 -> V_30 ) ;
return - V_76 ;
}
V_4 -> V_32 = F_30 ( L_10 ,
V_77 ,
F_23 ,
V_4 ) ;
if ( V_4 -> V_32 < 0 ) {
F_18 ( V_9 , L_11 ,
V_4 -> V_32 ) ;
F_31 ( V_4 -> V_30 ) ;
return - V_76 ;
}
F_32 ( V_74 -> V_78 ) = V_79 | V_4 -> V_30 ;
F_32 ( V_74 -> V_80 ) = V_79 | V_4 -> V_32 ;
return 0 ;
}
void F_33 ( struct V_3 * V_4 )
{
struct V_73 * V_74 = V_4 -> V_74 ;
F_32 ( V_74 -> V_78 ) = 0 ;
F_32 ( V_74 -> V_80 ) = 0 ;
if ( V_4 -> V_32 != 0 )
F_31 ( V_4 -> V_32 ) ;
if ( V_4 -> V_30 != 0 )
F_31 ( V_4 -> V_30 ) ;
}
void F_34 ( struct V_3 * V_4 )
{
if ( V_4 -> V_30 != - 1 )
F_32 ( V_4 -> V_74 -> V_78 ) =
V_79 | V_4 -> V_30 ;
if ( V_4 -> V_32 != - 1 )
F_32 ( V_4 -> V_74 -> V_80 ) =
V_79 | V_4 -> V_32 ;
}
int F_35 ( struct V_81 * V_82 ,
struct V_83 * V_10 ,
T_4 V_84 , T_2 * V_85 ,
T_2 * V_86 )
{
struct V_87 * V_88 =
(struct V_87 * ) V_10 -> V_89 ;
int V_90 ;
int V_91 ;
int V_92 ;
int V_93 ;
int V_94 = 0 ;
if ( V_84 <= 8 )
V_90 = 1 ;
else if ( V_84 <= 16 )
V_90 = 2 ;
else
V_90 = 4 ;
if ( V_88 )
V_93 = V_88 -> V_95 ;
else {
switch ( V_82 -> V_95 ) {
default:
V_82 -> V_95 = V_96 ;
case V_96 :
V_93 = 8 ;
break;
case V_97 :
V_93 = 16 ;
break;
case V_98 :
V_93 = 32 ;
break;
}
}
if ( V_93 <= 8 ) {
* V_85 = V_96 ;
V_91 = 8 ;
} else if ( V_93 <= 16 ) {
if ( V_90 == 1 ) {
* V_85 = V_96 ;
V_91 = 8 ;
V_94 = 1 ;
} else {
* V_85 = V_97 ;
V_91 = 16 ;
}
} else {
if ( V_90 == 1 ) {
* V_85 = V_96 ;
V_91 = 8 ;
V_94 = 1 ;
} else if ( V_90 == 2 ) {
* V_85 = V_97 ;
V_91 = 16 ;
V_94 = 1 ;
} else {
* V_85 = V_98 ;
V_91 = 32 ;
}
}
V_92 = V_91 / V_90 ;
* V_86 = ( F_36 ( V_92 ) & V_99 )
| ( F_37 ( 16 - V_92 ) & V_100 ) ;
return V_94 ;
}
