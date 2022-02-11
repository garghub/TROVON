static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 ,
void T_2 * V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_4 + V_3 ) ;
V_5 &= ~ V_1 ;
V_5 |= ( V_2 << F_3 ( V_1 ) ) & V_1 ;
F_4 ( V_5 , V_4 + V_3 ) ;
return V_5 ;
}
static inline bool F_5 ( const struct V_6 * V_7 )
{
return ! ! ( F_2 ( V_7 -> V_8 ) & V_7 -> V_9 ) ;
}
static inline void F_6 ( const struct V_6 * V_7 )
{
F_4 ( V_7 -> V_9 , V_7 -> V_8 ) ;
}
static int F_7 ( struct V_10 * V_11 , struct V_6 * V_7 )
{
int V_12 = 0 ;
bool V_13 ;
while ( V_12 ++ <= V_7 -> V_14 ) {
V_13 = F_5 ( V_7 ) ;
if ( V_13 )
break;
F_8 ( 1 ) ;
}
if ( V_12 > V_7 -> V_14 ) {
F_9 ( V_11 ,
L_1 ,
V_15 , V_12 , F_2 ( V_7 -> V_8 ) ) ;
return - V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , const struct V_6 * V_7 )
{
int V_12 = 0 ;
bool V_13 ;
while ( V_12 ++ <= V_7 -> V_14 ) {
F_6 ( V_7 ) ;
V_13 = F_5 ( V_7 ) ;
if ( ! V_13 )
break;
F_8 ( 1 ) ;
}
if ( V_12 > V_7 -> V_14 ) {
F_9 ( V_11 ,
L_1 ,
V_15 , V_12 , F_2 ( V_7 -> V_8 ) ) ;
return - V_16 ;
}
return 0 ;
}
static void F_11 ( struct V_10 * V_11 , const struct V_6 * V_7 ,
struct V_17 * V_18 )
{
T_1 V_5 ;
V_5 = F_2 ( V_7 -> V_19 ) ;
V_5 &= ~ ( V_7 -> V_20 | V_7 -> V_21 ) ;
switch ( V_18 -> V_22 ) {
case V_23 :
case V_24 :
V_5 |= V_7 -> V_20 ;
V_5 |= V_18 -> V_25 << F_3 ( V_7 -> V_21 ) ;
break;
}
F_4 ( V_5 , V_7 -> V_19 ) ;
}
static int F_12 ( struct V_26 * V_27 , struct V_6 * V_7 ,
struct V_17 * V_18 )
{
const struct V_28 * V_29 = V_7 -> V_29 ;
struct V_10 * V_11 = & V_27 -> V_11 ;
int V_30 ;
V_30 = F_10 ( V_11 , V_7 ) ;
if ( V_30 )
goto V_31;
F_1 ( V_29 -> V_32 | V_29 -> V_33 , 0 , V_29 -> V_34 ,
V_7 -> V_4 ) ;
switch ( V_18 -> V_22 ) {
case V_23 :
F_1 ( V_29 -> V_33 , 1 , V_29 -> V_34 , V_7 -> V_4 ) ;
break;
case V_24 :
F_1 ( V_29 -> V_32 , 1 , V_29 -> V_34 , V_7 -> V_4 ) ;
break;
}
F_1 ( V_29 -> V_35 , V_18 -> V_22 , V_29 -> V_36 ,
V_7 -> V_4 ) ;
if ( V_7 -> V_19 )
F_11 ( V_11 , V_7 , V_18 ) ;
F_1 ( V_29 -> V_37 , 1 , V_29 -> V_36 , V_7 -> V_4 ) ;
V_30 = F_7 ( V_11 , V_7 ) ;
if ( V_30 )
goto V_31;
V_30 = F_10 ( V_11 , V_7 ) ;
if ( V_30 )
goto V_31;
V_31:
return V_30 ;
}
static int F_13 ( struct V_26 * V_27 , unsigned V_38 )
{
const struct V_39 * V_40 = V_27 -> V_40 ;
struct V_6 * V_7 = F_14 ( V_27 ) ;
struct V_10 * V_11 = & V_27 -> V_11 ;
struct V_17 * V_18 , * V_41 ;
int V_30 = 0 ;
if ( ! V_7 ) {
F_15 ( V_11 , L_2 ,
V_15 ) ;
return - V_42 ;
}
if ( ! V_40 -> V_43 || ! V_7 -> V_18 ) {
F_15 ( V_11 ,
L_3 ,
V_15 ) ;
return - V_44 ;
}
if ( V_38 >= V_40 -> V_43 ) {
F_16 ( V_11 , L_4 , V_15 ,
V_38 , V_40 -> V_43 ) ;
return - V_44 ;
}
if ( V_38 == V_7 -> V_45 ) {
F_17 ( V_11 , L_5 , V_15 , V_38 ) ;
return V_30 ;
}
V_18 = & V_7 -> V_18 [ V_38 ] ;
V_41 = & V_7 -> V_18 [ V_7 -> V_45 ] ;
if ( ! memcmp ( V_18 , V_41 , sizeof( * V_18 ) ) ) {
F_17 ( V_11 , L_6 , V_15 ,
V_38 , V_7 -> V_45 ) ;
goto V_31;
}
V_30 = F_12 ( V_27 , V_7 , V_18 ) ;
V_31:
if ( ! V_30 )
V_7 -> V_45 = V_38 ;
else
F_15 ( V_11 ,
L_7 ,
V_15 , V_40 -> V_46 [ V_38 ] , V_38 ,
V_18 -> V_22 , V_30 ) ;
return V_30 ;
}
static int F_18 ( struct V_26 * V_27 )
{
const struct V_39 * V_40 = V_27 -> V_40 ;
struct V_6 * V_7 = F_14 ( V_27 ) ;
struct V_10 * V_11 = & V_27 -> V_11 ;
if ( ! V_7 ) {
F_15 ( V_11 , L_2 ,
V_15 ) ;
return - V_42 ;
}
if ( ! V_40 -> V_43 || ! V_7 -> V_18 ) {
F_15 ( V_11 ,
L_3 ,
V_15 ) ;
return - V_44 ;
}
if ( V_7 -> V_45 >= ( int ) V_40 -> V_43 ) {
F_16 ( V_11 , L_8 ,
V_15 , V_7 -> V_45 , V_40 -> V_43 ) ;
return - V_44 ;
}
return V_7 -> V_45 ;
}
static int F_19 ( struct V_10 * V_11 , struct V_6 * V_7 )
{
T_1 V_47 ;
T_1 V_48 , V_49 , V_50 ;
const struct V_28 * V_29 = V_7 -> V_29 ;
int V_30 ;
char * V_51 = L_9 ;
V_30 = F_20 ( V_11 -> V_52 , V_51 , & V_7 -> V_14 ) ;
if ( V_30 ) {
F_16 ( V_11 , L_10 , V_51 , V_30 ) ;
return V_30 ;
}
if ( ! V_7 -> V_14 ) {
F_16 ( V_11 , L_11 , V_51 ) ;
return - V_44 ;
}
V_51 = L_12 ;
V_30 = F_20 ( V_11 -> V_52 , V_51 , & V_47 ) ;
if ( V_30 ) {
F_16 ( V_11 , L_10 , V_51 , V_30 ) ;
return V_30 ;
}
if ( ! V_47 ) {
F_16 ( V_11 , L_11 , V_51 ) ;
return - V_44 ;
}
V_7 -> V_53 = F_21 ( V_11 , NULL ) ;
if ( F_22 ( V_7 -> V_53 ) ) {
V_30 = F_23 ( V_7 -> V_53 ) ;
F_16 ( V_11 , L_13 , V_15 , V_30 ) ;
return V_30 ;
}
V_48 = F_24 ( F_25 ( V_7 -> V_53 ) , 1000000 ) ;
V_50 = F_24 ( V_47 * 10 , V_48 ) ;
V_49 = F_24 ( V_7 -> V_14 * 10 , V_50 ) ;
F_17 ( V_11 , L_14 , V_15 ,
F_25 ( V_7 -> V_53 ) , V_49 ) ;
F_1 ( V_29 -> V_54 , V_49 , V_29 -> V_34 ,
V_7 -> V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_6 * V_7 ,
struct V_55 * V_56 )
{
struct V_17 * V_18 ;
const struct V_57 * V_58 ;
const T_3 * V_59 ;
const T_1 V_60 = 6 ;
char * V_51 = L_15 ;
T_1 V_61 , V_62 ;
unsigned int * V_46 ;
int V_63 = V_64 , V_65 = 0 ;
struct V_66 * V_67 = & V_56 -> V_68 ;
V_58 = F_27 ( V_11 -> V_52 , V_51 , NULL ) ;
if ( ! V_58 ) {
F_16 ( V_11 , L_16 , V_51 ) ;
return - V_42 ;
}
if ( ! V_58 -> V_2 ) {
F_16 ( V_11 , L_17 , V_51 ) ;
return - V_69 ;
}
V_61 = V_58 -> V_70 / sizeof( T_1 ) ;
if ( ! V_61 || ( V_61 % V_60 ) ) {
F_16 ( V_11 , L_18 , V_51 ,
V_60 ) ;
return - V_44 ;
}
V_61 /= V_60 ;
V_18 = F_28 ( V_11 , sizeof( * V_18 ) * V_61 , V_71 ) ;
if ( ! V_18 ) {
F_16 ( V_11 , L_19 ,
V_51 ) ;
return - V_72 ;
}
V_7 -> V_18 = V_18 ;
V_46 = F_28 ( V_11 , sizeof( unsigned int ) * V_61 ,
V_71 ) ;
if ( ! V_46 ) {
F_16 ( V_11 , L_20 ,
V_51 ) ;
return - V_72 ;
}
V_7 -> V_73 . V_43 = V_61 ;
V_7 -> V_73 . V_46 = V_46 ;
V_7 -> V_45 = - V_44 ;
V_59 = V_58 -> V_2 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ , V_18 ++ , V_46 ++ ) {
T_1 V_74 , V_75 , V_76 , V_77 ;
T_1 V_78 ;
* V_46 = F_29 ( V_59 ++ ) ;
V_18 -> V_22 = F_29 ( V_59 ++ ) ;
V_74 = F_29 ( V_59 ++ ) ;
V_75 = F_29 ( V_59 ++ ) ;
V_76 = F_29 ( V_59 ++ ) ;
V_77 = F_29 ( V_59 ++ ) ;
F_17 ( V_11 ,
L_21 ,
V_62 , * V_46 , V_18 -> V_22 , V_74 , V_75 ,
V_76 , V_77 ) ;
if ( V_63 > * V_46 )
V_63 = * V_46 ;
if ( V_65 < * V_46 )
V_65 = * V_46 ;
if ( ! V_7 -> V_79 ) {
if ( V_74 || V_75 || V_76 || V_77 )
F_16 ( V_11 , L_22 ,
V_51 , * V_46 ) ;
goto V_80;
}
V_78 = F_2 ( V_7 -> V_79 + V_74 ) ;
if ( V_78 & V_75 )
V_18 -> V_22 = V_23 ;
else if ( V_78 & V_76 )
V_18 -> V_22 = V_24 ;
else if ( V_75 || V_76 )
V_18 -> V_22 = V_81 ;
F_17 ( V_11 ,
L_23 ,
V_62 , * V_46 , V_78 , V_18 -> V_22 ) ;
if ( ! V_7 -> V_19 ) {
if ( V_77 )
F_16 ( V_11 , L_24 ,
V_51 , * V_46 , V_77 ) ;
continue;
}
V_18 -> V_25 = V_78 & V_77 >> F_3 ( V_77 ) ;
F_17 ( V_11 , L_25 , V_62 , * V_46 , V_18 -> V_25 ) ;
V_80:
switch ( V_18 -> V_22 ) {
case V_81 :
case V_24 :
case V_23 :
break;
default:
F_16 ( V_11 , L_26 ,
V_15 , V_62 , * V_46 , V_18 -> V_22 ) ;
return - V_44 ;
}
}
V_67 -> V_63 = V_63 ;
V_67 -> V_65 = V_65 ;
return 0 ;
}
static int F_30 ( struct V_82 * V_83 )
{
struct V_10 * V_11 = & V_83 -> V_11 ;
const struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_6 * V_7 ;
struct V_55 * V_88 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_39 * V_40 ;
struct V_66 * V_67 ;
struct V_89 V_90 = { } ;
char * V_51 ;
int V_30 = 0 ;
V_85 = F_31 ( V_91 , V_11 ) ;
if ( ! V_85 ) {
V_30 = - V_42 ;
F_16 ( V_11 , L_27 , V_15 ) ;
goto V_92;
}
if ( ! V_85 -> V_93 ) {
V_30 = - V_44 ;
F_16 ( V_11 , L_28 , V_15 ) ;
goto V_92;
}
V_7 = F_28 ( V_11 , sizeof( struct V_6 ) , V_71 ) ;
if ( ! V_7 ) {
F_16 ( V_11 , L_29 , V_15 ) ;
V_30 = - V_72 ;
goto V_92;
}
V_7 -> V_29 = V_85 -> V_93 ;
V_51 = L_30 ;
V_87 = F_32 ( V_83 , V_94 , V_51 ) ;
if ( ! V_87 ) {
F_16 ( V_11 , L_31 , V_51 ) ;
V_30 = - V_42 ;
goto V_92;
}
V_7 -> V_4 = F_33 ( V_11 , V_87 ) ;
if ( F_22 ( V_7 -> V_4 ) ) {
V_30 = F_23 ( V_7 -> V_4 ) ;
goto V_92;
}
V_51 = L_32 ;
V_87 = F_32 ( V_83 , V_94 , V_51 ) ;
if ( ! V_87 ) {
F_16 ( V_11 , L_31 , V_51 ) ;
V_30 = - V_42 ;
goto V_92;
}
V_7 -> V_8 = F_34 ( V_11 , V_87 -> V_95 ,
F_35 ( V_87 ) ) ;
if ( ! V_7 -> V_8 ) {
F_16 ( V_11 , L_33 , V_51 ) ;
V_30 = - V_72 ;
goto V_92;
}
V_51 = L_34 ;
V_87 = F_32 ( V_83 , V_94 , V_51 ) ;
if ( ! V_87 ) {
F_17 ( V_11 , L_31 , V_51 ) ;
V_30 = - V_42 ;
goto V_96;
}
V_7 -> V_79 = F_34 ( V_11 , V_87 -> V_95 ,
F_35 ( V_87 ) ) ;
if ( ! V_7 -> V_79 ) {
F_16 ( V_11 , L_33 , V_51 ) ;
V_30 = - V_72 ;
goto V_92;
}
V_51 = L_35 ;
V_87 = F_32 ( V_83 , V_94 , V_51 ) ;
if ( ! V_87 ) {
F_17 ( V_11 , L_31 , V_51 ) ;
V_30 = - V_42 ;
goto V_96;
}
V_7 -> V_19 = F_33 ( V_11 , V_87 ) ;
if ( F_22 ( V_7 -> V_19 ) ) {
V_30 = F_23 ( V_7 -> V_19 ) ;
goto V_92;
}
V_51 = L_36 ;
V_30 =
F_20 ( V_83 -> V_11 . V_52 , V_51 ,
& V_7 -> V_20 ) ;
if ( V_30 ) {
F_16 ( V_11 , L_37 , V_51 , V_30 ) ;
goto V_92;
}
if ( ! V_7 -> V_20 ) {
F_16 ( V_11 , L_11 , V_51 ) ;
V_30 = - V_44 ;
goto V_92;
}
V_51 = L_38 ;
V_30 =
F_20 ( V_83 -> V_11 . V_52 , V_51 ,
& V_7 -> V_21 ) ;
if ( V_30 ) {
F_16 ( V_11 , L_37 , V_51 , V_30 ) ;
goto V_92;
}
if ( ! V_7 -> V_21 ) {
F_16 ( V_11 , L_11 , V_51 ) ;
V_30 = - V_44 ;
goto V_92;
}
V_96:
V_51 = L_39 ;
V_30 =
F_20 ( V_83 -> V_11 . V_52 , V_51 ,
& V_7 -> V_9 ) ;
if ( V_30 ) {
F_16 ( V_11 , L_37 , V_51 , V_30 ) ;
goto V_92;
}
if ( ! V_7 -> V_9 ) {
F_16 ( V_11 , L_11 , V_51 ) ;
V_30 = - V_44 ;
goto V_92;
}
V_88 = F_36 ( V_11 , V_83 -> V_11 . V_52 ) ;
if ( ! V_88 ) {
V_30 = - V_72 ;
F_16 ( V_11 , L_40 ,
V_15 ) ;
goto V_92;
}
V_30 = F_26 ( V_11 , V_7 , V_88 ) ;
if ( V_30 )
goto V_92;
V_30 = F_19 ( V_11 , V_7 ) ;
if ( V_30 )
goto V_92;
V_40 = & V_7 -> V_73 ;
V_40 -> V_97 = F_37 ( V_11 ) ;
V_40 -> V_98 = V_99 ;
V_40 -> type = V_100 ;
V_40 -> V_101 = & V_102 ;
V_67 = & V_88 -> V_68 ;
if ( V_40 -> V_43 > 1 )
V_67 -> V_103 |= V_104 ;
V_67 -> V_105 = true ;
V_90 . V_11 = V_11 ;
V_90 . V_106 = V_88 ;
V_90 . V_107 = V_7 ;
V_90 . V_52 = V_83 -> V_11 . V_52 ;
V_27 = F_38 ( V_40 , & V_90 ) ;
if ( F_22 ( V_27 ) ) {
V_30 = F_23 ( V_27 ) ;
F_16 ( V_11 , L_41 ,
V_15 , V_30 ) ;
goto V_92;
}
F_39 ( V_83 , V_27 ) ;
F_1 ( V_7 -> V_29 -> V_108 , 1 , V_7 -> V_29 -> V_34 , V_7 -> V_4 ) ;
return 0 ;
V_92:
F_16 ( V_11 , L_42 , V_15 , V_30 ) ;
return V_30 ;
}
static int F_40 ( struct V_82 * V_83 )
{
struct V_26 * V_27 = F_41 ( V_83 ) ;
F_42 ( V_27 ) ;
return 0 ;
}
