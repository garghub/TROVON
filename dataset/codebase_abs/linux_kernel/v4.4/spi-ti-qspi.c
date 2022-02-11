static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_11 = 0 , V_12 ;
T_1 V_13 , V_14 , V_15 ;
if ( V_7 -> V_8 -> V_16 ) {
F_7 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( ! V_2 -> V_19 ) {
F_8 ( V_2 -> V_17 , L_2 ) ;
return - V_20 ;
}
V_14 = F_9 ( V_2 -> V_21 ) ;
V_11 = F_10 ( V_14 , V_2 -> V_19 ) - 1 ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_17 , L_3 ) ;
return - V_20 ;
}
if ( V_11 > V_22 ) {
F_7 ( V_2 -> V_17 , L_4 ,
V_22 , V_22 + 1 ) ;
return - V_20 ;
}
F_7 ( V_2 -> V_17 , L_5 ,
V_2 -> V_19 , V_11 ) ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
V_13 = F_1 ( V_2 , V_23 ) ;
V_13 &= ~ V_24 ;
F_3 ( V_2 , V_13 , V_23 ) ;
V_15 = V_24 | V_11 ;
F_3 ( V_2 , V_15 , V_23 ) ;
V_10 -> V_25 = V_15 ;
F_12 ( V_2 -> V_17 ) ;
V_12 = F_13 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_3 ( V_2 , V_10 -> V_25 , V_23 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
V_26 = F_1 ( V_2 , V_30 ) ;
while ( ( V_26 & V_31 ) && F_16 ( V_27 , V_28 ) ) {
F_17 () ;
V_26 = F_1 ( V_2 , V_30 ) ;
}
F_18 ( V_26 & V_31 , L_8 ) ;
return V_26 & V_31 ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
do {
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
F_17 () ;
} while ( F_16 ( V_27 , V_28 ) );
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 & V_32 )
return 0 ;
return - V_33 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_36 , V_37 , V_38 ;
unsigned int V_39 ;
const T_2 * V_40 ;
T_1 V_41 ;
V_40 = V_35 -> V_42 ;
V_39 = V_2 -> V_39 | V_43 ;
V_37 = V_35 -> V_44 ;
V_36 = V_35 -> V_45 >> 3 ;
V_38 = V_36 ;
while ( V_37 ) {
if ( F_15 ( V_2 ) )
return - V_18 ;
switch ( V_36 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_9 ,
V_39 , V_2 -> V_46 , * V_40 ) ;
if ( V_37 >= V_47 ) {
T_1 * V_48 = ( T_1 * ) V_40 ;
V_41 = F_21 ( * V_48 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_49 ) ;
V_41 = F_21 ( * V_48 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_50 ) ;
V_41 = F_21 ( * V_48 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_51 ) ;
V_41 = F_21 ( * V_48 ++ ) ;
F_4 ( V_41 , V_2 -> V_4 +
V_52 ) ;
V_38 = V_47 ;
V_39 |= F_22 ( V_53 ) ;
} else {
F_23 ( * V_40 , V_2 -> V_4 + V_52 ) ;
V_39 = V_2 -> V_39 | V_43 ;
V_38 = V_36 ;
V_39 |= F_22 ( V_36 ) ;
}
break;
case 2 :
F_7 ( V_2 -> V_17 , L_10 ,
V_39 , V_2 -> V_46 , * V_40 ) ;
F_24 ( * ( ( V_54 * ) V_40 ) , V_2 -> V_4 + V_52 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_11 ,
V_39 , V_2 -> V_46 , * V_40 ) ;
F_4 ( * ( ( T_1 * ) V_40 ) , V_2 -> V_4 + V_52 ) ;
break;
}
F_3 ( V_2 , V_39 , V_55 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_12 ) ;
return - V_33 ;
}
V_40 += V_38 ;
V_37 -= V_38 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_36 , V_37 ;
unsigned int V_39 ;
T_2 * V_56 ;
V_56 = V_35 -> V_57 ;
V_39 = V_2 -> V_39 ;
switch ( V_35 -> V_58 ) {
case V_59 :
V_39 |= V_60 ;
break;
case V_61 :
V_39 |= V_62 ;
break;
default:
V_39 |= V_63 ;
break;
}
V_37 = V_35 -> V_44 ;
V_36 = V_35 -> V_45 >> 3 ;
while ( V_37 ) {
F_7 ( V_2 -> V_17 , L_13 , V_39 , V_2 -> V_46 ) ;
if ( F_15 ( V_2 ) )
return - V_18 ;
F_3 ( V_2 , V_39 , V_55 ) ;
if ( F_19 ( V_2 ) ) {
F_8 ( V_2 -> V_17 , L_14 ) ;
return - V_33 ;
}
switch ( V_36 ) {
case 1 :
* V_56 = F_26 ( V_2 -> V_4 + V_52 ) ;
break;
case 2 :
* ( ( V_54 * ) V_56 ) = F_27 ( V_2 -> V_4 + V_52 ) ;
break;
case 4 :
* ( ( T_1 * ) V_56 ) = F_2 ( V_2 -> V_4 + V_52 ) ;
break;
}
V_56 += V_36 ;
V_37 -= V_36 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
int V_12 ;
if ( V_35 -> V_42 ) {
V_12 = F_20 ( V_2 , V_35 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
if ( V_35 -> V_57 ) {
V_12 = F_25 ( V_2 , V_35 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_29 ( struct V_64 * V_8 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_66 -> V_7 ;
struct V_34 * V_35 ;
int V_67 = 0 , V_12 ;
int V_68 ;
V_2 -> V_46 = 0 ;
if ( V_7 -> V_69 & V_70 )
V_2 -> V_46 |= F_30 ( V_7 -> V_71 ) ;
if ( V_7 -> V_69 & V_72 )
V_2 -> V_46 |= F_31 ( V_7 -> V_71 ) ;
if ( V_7 -> V_69 & V_73 )
V_2 -> V_46 |= F_32 ( V_7 -> V_71 ) ;
V_68 = ( V_66 -> V_68 << 3 ) / V_7 -> V_45 ;
V_68 = F_33 ( V_68 , 0 , V_74 ) ;
V_2 -> V_39 = 0 ;
V_2 -> V_39 |= F_34 ( V_7 -> V_71 ) ;
V_2 -> V_39 |= F_35 ( V_68 ) ;
F_3 ( V_2 , V_2 -> V_46 , V_75 ) ;
F_36 ( & V_2 -> V_76 ) ;
F_37 (t, &m->transfers, transfer_list) {
V_2 -> V_39 |= F_22 ( V_35 -> V_45 ) ;
V_12 = F_28 ( V_2 , V_35 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_17 ) ;
F_38 ( & V_2 -> V_76 ) ;
return - V_20 ;
}
V_66 -> V_77 += V_35 -> V_44 ;
}
F_38 ( & V_2 -> V_76 ) ;
F_3 ( V_2 , V_2 -> V_39 | V_78 , V_55 ) ;
V_66 -> V_67 = V_67 ;
F_39 ( V_8 ) ;
return V_67 ;
}
static int F_40 ( struct V_79 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_41 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_80 * V_81 )
{
struct V_1 * V_2 ;
struct V_64 * V_8 ;
struct V_82 * V_83 , * V_84 , * V_85 ;
struct V_86 * V_87 = V_81 -> V_17 . V_88 ;
T_1 V_89 ;
int V_12 = 0 , V_90 , V_91 ;
V_8 = F_43 ( & V_81 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_92 ;
V_8 -> V_93 = V_72 | V_70 | V_94 | V_95 ;
V_8 -> V_96 = V_97 ;
V_8 -> V_98 = F_5 ;
V_8 -> V_99 = true ;
V_8 -> V_100 = F_29 ;
V_8 -> V_17 . V_88 = V_81 -> V_17 . V_88 ;
V_8 -> V_101 = F_44 ( 32 ) | F_44 ( 16 ) |
F_44 ( 8 ) ;
if ( ! F_45 ( V_87 , L_18 , & V_90 ) )
V_8 -> V_102 = V_90 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_81 -> V_17 ;
F_46 ( V_81 , V_2 ) ;
V_83 = F_47 ( V_81 , V_103 , L_19 ) ;
if ( V_83 == NULL ) {
V_83 = F_48 ( V_81 , V_103 , 0 ) ;
if ( V_83 == NULL ) {
F_8 ( & V_81 -> V_17 , L_20 ) ;
return - V_104 ;
}
}
V_85 = F_47 ( V_81 ,
V_103 , L_21 ) ;
if ( V_85 == NULL ) {
V_85 = F_48 ( V_81 , V_103 , 1 ) ;
if ( V_85 == NULL ) {
F_8 ( & V_81 -> V_17 ,
L_22 ) ;
}
}
V_84 = F_47 ( V_81 ,
V_103 , L_23 ) ;
if ( V_84 == NULL ) {
V_84 = F_48 ( V_81 , V_103 , 2 ) ;
if ( V_84 == NULL ) {
F_7 ( & V_81 -> V_17 ,
L_24 ) ;
}
}
V_91 = F_49 ( V_81 , 0 ) ;
if ( V_91 < 0 ) {
F_8 ( & V_81 -> V_17 , L_25 ) ;
return V_91 ;
}
F_50 ( & V_2 -> V_76 ) ;
V_2 -> V_4 = F_51 ( & V_81 -> V_17 , V_83 ) ;
if ( F_52 ( V_2 -> V_4 ) ) {
V_12 = F_53 ( V_2 -> V_4 ) ;
goto V_105;
}
if ( V_84 ) {
V_2 -> V_106 = true ;
V_2 -> V_107 = F_51 ( & V_81 -> V_17 , V_84 ) ;
if ( F_52 ( V_2 -> V_107 ) ) {
V_12 = F_53 ( V_2 -> V_107 ) ;
goto V_105;
}
}
if ( V_85 ) {
V_2 -> V_108 = F_51 ( & V_81 -> V_17 , V_85 ) ;
if ( F_52 ( V_2 -> V_108 ) ) {
V_12 = F_53 ( V_2 -> V_108 ) ;
goto V_105;
}
}
V_2 -> V_21 = F_54 ( & V_81 -> V_17 , L_26 ) ;
if ( F_52 ( V_2 -> V_21 ) ) {
V_12 = F_53 ( V_2 -> V_21 ) ;
F_8 ( & V_81 -> V_17 , L_27 , V_12 ) ;
}
F_55 ( & V_81 -> V_17 ) ;
F_56 ( & V_81 -> V_17 , V_109 ) ;
F_57 ( & V_81 -> V_17 ) ;
if ( ! F_45 ( V_87 , L_28 , & V_89 ) )
V_2 -> V_19 = V_89 ;
V_12 = F_58 ( & V_81 -> V_17 , V_8 ) ;
if ( V_12 )
goto V_105;
return 0 ;
V_105:
F_59 ( V_8 ) ;
return V_12 ;
}
static int F_60 ( struct V_80 * V_81 )
{
F_61 ( & V_81 -> V_17 ) ;
F_62 ( & V_81 -> V_17 ) ;
return 0 ;
}
