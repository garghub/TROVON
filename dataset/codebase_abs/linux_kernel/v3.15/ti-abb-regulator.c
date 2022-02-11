static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 , void T_2 * V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_3 ) ;
V_4 &= ~ V_1 ;
V_4 |= ( V_2 << F_3 ( V_1 ) ) & V_1 ;
F_4 ( V_4 , V_3 ) ;
return V_4 ;
}
static inline bool F_5 ( const struct V_5 * V_6 )
{
return ! ! ( F_2 ( V_6 -> V_7 ) & V_6 -> V_8 ) ;
}
static inline void F_6 ( const struct V_5 * V_6 )
{
F_4 ( V_6 -> V_8 , V_6 -> V_7 ) ;
}
static int F_7 ( struct V_9 * V_10 , struct V_5 * V_6 )
{
int V_11 = 0 ;
bool V_12 ;
while ( V_11 ++ <= V_6 -> V_13 ) {
V_12 = F_5 ( V_6 ) ;
if ( V_12 )
break;
F_8 ( 1 ) ;
}
if ( V_11 > V_6 -> V_13 ) {
F_9 ( V_10 ,
L_1 ,
V_14 , V_11 , F_2 ( V_6 -> V_7 ) ) ;
return - V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , const struct V_5 * V_6 )
{
int V_11 = 0 ;
bool V_12 ;
while ( V_11 ++ <= V_6 -> V_13 ) {
F_6 ( V_6 ) ;
V_12 = F_5 ( V_6 ) ;
if ( ! V_12 )
break;
F_8 ( 1 ) ;
}
if ( V_11 > V_6 -> V_13 ) {
F_9 ( V_10 ,
L_1 ,
V_14 , V_11 , F_2 ( V_6 -> V_7 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void F_11 ( struct V_9 * V_10 , const struct V_5 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_4 ;
V_4 = F_2 ( V_6 -> V_18 ) ;
V_4 &= ~ ( V_6 -> V_19 | V_6 -> V_20 ) ;
switch ( V_17 -> V_21 ) {
case V_22 :
case V_23 :
V_4 |= V_6 -> V_19 ;
V_4 |= V_17 -> V_24 << F_3 ( V_6 -> V_20 ) ;
break;
}
F_4 ( V_4 , V_6 -> V_18 ) ;
}
static int F_12 ( struct V_25 * V_26 , struct V_5 * V_6 ,
struct V_16 * V_17 )
{
const struct V_27 * V_28 = V_6 -> V_28 ;
struct V_9 * V_10 = & V_26 -> V_10 ;
int V_29 ;
V_29 = F_10 ( V_10 , V_6 ) ;
if ( V_29 )
goto V_30;
F_1 ( V_28 -> V_31 | V_28 -> V_32 , 0 , V_6 -> V_33 ) ;
switch ( V_17 -> V_21 ) {
case V_22 :
F_1 ( V_28 -> V_32 , 1 , V_6 -> V_33 ) ;
break;
case V_23 :
F_1 ( V_28 -> V_31 , 1 , V_6 -> V_33 ) ;
break;
}
F_1 ( V_28 -> V_34 , V_17 -> V_21 , V_6 -> V_35 ) ;
if ( V_6 -> V_18 && V_17 -> V_21 != V_36 )
F_11 ( V_10 , V_6 , V_17 ) ;
F_1 ( V_28 -> V_37 , 1 , V_6 -> V_35 ) ;
V_29 = F_7 ( V_10 , V_6 ) ;
if ( V_29 )
goto V_30;
V_29 = F_10 ( V_10 , V_6 ) ;
if ( V_29 )
goto V_30;
if ( V_6 -> V_18 && V_17 -> V_21 == V_36 )
F_11 ( V_10 , V_6 , V_17 ) ;
V_30:
return V_29 ;
}
static int F_13 ( struct V_25 * V_26 , unsigned V_38 )
{
const struct V_39 * V_40 = V_26 -> V_40 ;
struct V_5 * V_6 = F_14 ( V_26 ) ;
struct V_9 * V_10 = & V_26 -> V_10 ;
struct V_16 * V_17 , * V_41 ;
int V_29 = 0 ;
if ( ! V_6 ) {
F_15 ( V_10 , L_2 ,
V_14 ) ;
return - V_42 ;
}
if ( ! V_40 -> V_43 || ! V_6 -> V_17 ) {
F_15 ( V_10 ,
L_3 ,
V_14 ) ;
return - V_44 ;
}
if ( V_38 >= V_40 -> V_43 ) {
F_16 ( V_10 , L_4 , V_14 ,
V_38 , V_40 -> V_43 ) ;
return - V_44 ;
}
if ( V_38 == V_6 -> V_45 ) {
F_17 ( V_10 , L_5 , V_14 , V_38 ) ;
return V_29 ;
}
V_17 = & V_6 -> V_17 [ V_38 ] ;
V_41 = & V_6 -> V_17 [ V_6 -> V_45 ] ;
if ( ! memcmp ( V_17 , V_41 , sizeof( * V_17 ) ) ) {
F_17 ( V_10 , L_6 , V_14 ,
V_38 , V_6 -> V_45 ) ;
goto V_30;
}
V_29 = F_12 ( V_26 , V_6 , V_17 ) ;
V_30:
if ( ! V_29 )
V_6 -> V_45 = V_38 ;
else
F_15 ( V_10 ,
L_7 ,
V_14 , V_40 -> V_46 [ V_38 ] , V_38 ,
V_17 -> V_21 , V_29 ) ;
return V_29 ;
}
static int F_18 ( struct V_25 * V_26 )
{
const struct V_39 * V_40 = V_26 -> V_40 ;
struct V_5 * V_6 = F_14 ( V_26 ) ;
struct V_9 * V_10 = & V_26 -> V_10 ;
if ( ! V_6 ) {
F_15 ( V_10 , L_2 ,
V_14 ) ;
return - V_42 ;
}
if ( ! V_40 -> V_43 || ! V_6 -> V_17 ) {
F_15 ( V_10 ,
L_3 ,
V_14 ) ;
return - V_44 ;
}
if ( V_6 -> V_45 >= ( int ) V_40 -> V_43 ) {
F_16 ( V_10 , L_8 ,
V_14 , V_6 -> V_45 , V_40 -> V_43 ) ;
return - V_44 ;
}
return V_6 -> V_45 ;
}
static int F_19 ( struct V_9 * V_10 , struct V_5 * V_6 )
{
T_1 V_47 ;
T_1 V_48 , V_49 , V_50 ;
const struct V_27 * V_28 = V_6 -> V_28 ;
int V_29 ;
char * V_51 = L_9 ;
V_29 = F_20 ( V_10 -> V_52 , V_51 , & V_6 -> V_13 ) ;
if ( V_29 ) {
F_16 ( V_10 , L_10 , V_51 , V_29 ) ;
return V_29 ;
}
if ( ! V_6 -> V_13 ) {
F_16 ( V_10 , L_11 , V_51 ) ;
return - V_44 ;
}
V_51 = L_12 ;
V_29 = F_20 ( V_10 -> V_52 , V_51 , & V_47 ) ;
if ( V_29 ) {
F_16 ( V_10 , L_10 , V_51 , V_29 ) ;
return V_29 ;
}
if ( ! V_47 ) {
F_16 ( V_10 , L_11 , V_51 ) ;
return - V_44 ;
}
V_6 -> V_53 = F_21 ( V_10 , NULL ) ;
if ( F_22 ( V_6 -> V_53 ) ) {
V_29 = F_23 ( V_6 -> V_53 ) ;
F_16 ( V_10 , L_13 , V_14 , V_29 ) ;
return V_29 ;
}
V_48 = F_24 ( F_25 ( V_6 -> V_53 ) , 1000000 ) ;
V_50 = F_24 ( V_47 * 10 , V_48 ) ;
V_49 = F_24 ( V_6 -> V_13 * 10 , V_50 ) ;
F_17 ( V_10 , L_14 , V_14 ,
F_25 ( V_6 -> V_53 ) , V_49 ) ;
F_1 ( V_28 -> V_54 , V_49 , V_6 -> V_33 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_5 * V_6 ,
struct V_55 * V_56 )
{
struct V_16 * V_17 ;
const T_1 V_57 = 6 ;
char * V_51 = L_15 ;
T_1 V_58 ;
unsigned int * V_46 ;
int V_59 , V_60 = V_61 , V_62 = 0 ;
struct V_63 * V_64 = & V_56 -> V_65 ;
V_59 = F_27 ( V_10 -> V_52 , V_51 ) ;
if ( V_59 < 0 ) {
F_16 ( V_10 , L_16 , V_51 ) ;
return V_59 ;
}
if ( ! V_59 || ( V_59 % V_57 ) ) {
F_16 ( V_10 , L_17 , V_51 ,
V_57 ) ;
return - V_44 ;
}
V_59 /= V_57 ;
V_17 = F_28 ( V_10 , sizeof( * V_17 ) * V_59 , V_66 ) ;
if ( ! V_17 )
return - V_67 ;
V_6 -> V_17 = V_17 ;
V_46 = F_28 ( V_10 , sizeof( unsigned int ) * V_59 ,
V_66 ) ;
if ( ! V_46 )
return - V_67 ;
V_6 -> V_68 . V_43 = V_59 ;
V_6 -> V_68 . V_46 = V_46 ;
V_6 -> V_45 = - V_44 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ , V_17 ++ , V_46 ++ ) {
T_1 V_69 , V_70 , V_71 , V_72 ;
T_1 V_73 ;
F_29 ( V_10 -> V_52 , V_51 , V_58 * V_57 ,
V_46 ) ;
F_29 ( V_10 -> V_52 , V_51 ,
V_58 * V_57 + 1 , & V_17 -> V_21 ) ;
F_29 ( V_10 -> V_52 , V_51 ,
V_58 * V_57 + 2 , & V_69 ) ;
F_29 ( V_10 -> V_52 , V_51 ,
V_58 * V_57 + 3 , & V_70 ) ;
F_29 ( V_10 -> V_52 , V_51 ,
V_58 * V_57 + 4 , & V_71 ) ;
F_29 ( V_10 -> V_52 , V_51 ,
V_58 * V_57 + 5 , & V_72 ) ;
F_17 ( V_10 ,
L_18 ,
V_58 , * V_46 , V_17 -> V_21 , V_69 , V_70 ,
V_71 , V_72 ) ;
if ( V_60 > * V_46 )
V_60 = * V_46 ;
if ( V_62 < * V_46 )
V_62 = * V_46 ;
if ( ! V_6 -> V_74 ) {
if ( V_69 || V_70 || V_71 || V_72 )
F_16 ( V_10 , L_19 ,
V_51 , * V_46 ) ;
goto V_75;
}
V_73 = F_2 ( V_6 -> V_74 + V_69 ) ;
if ( V_73 & V_70 )
V_17 -> V_21 = V_22 ;
else if ( V_73 & V_71 )
V_17 -> V_21 = V_23 ;
else if ( V_70 || V_71 )
V_17 -> V_21 = V_36 ;
F_17 ( V_10 ,
L_20 ,
V_58 , * V_46 , V_73 , V_17 -> V_21 ) ;
if ( ! V_6 -> V_18 ) {
if ( V_72 )
F_16 ( V_10 , L_21 ,
V_51 , * V_46 , V_72 ) ;
continue;
}
V_17 -> V_24 = ( V_73 & V_72 ) >> F_3 ( V_72 ) ;
F_17 ( V_10 , L_22 , V_58 , * V_46 , V_17 -> V_24 ) ;
V_75:
switch ( V_17 -> V_21 ) {
case V_36 :
case V_23 :
case V_22 :
break;
default:
F_16 ( V_10 , L_23 ,
V_14 , V_58 , * V_46 , V_17 -> V_21 ) ;
return - V_44 ;
}
}
V_64 -> V_60 = V_60 ;
V_64 -> V_62 = V_62 ;
return 0 ;
}
static int F_30 ( struct V_76 * V_77 )
{
struct V_9 * V_10 = & V_77 -> V_10 ;
const struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_5 * V_6 ;
struct V_55 * V_82 = NULL ;
struct V_25 * V_26 = NULL ;
struct V_39 * V_40 ;
struct V_63 * V_64 ;
struct V_83 V_84 = { } ;
char * V_51 ;
int V_29 = 0 ;
V_79 = F_31 ( V_85 , V_10 ) ;
if ( ! V_79 ) {
F_16 ( V_10 , L_24 , V_14 ) ;
return - V_42 ;
}
if ( ! V_79 -> V_86 ) {
F_16 ( V_10 , L_25 , V_14 ) ;
return - V_44 ;
}
V_6 = F_28 ( V_10 , sizeof( struct V_5 ) , V_66 ) ;
if ( ! V_6 )
return - V_67 ;
V_6 -> V_28 = V_79 -> V_86 ;
if ( V_6 -> V_28 -> V_87 || V_6 -> V_28 -> V_88 ) {
V_51 = L_26 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
V_6 -> V_90 = F_33 ( V_10 , V_81 ) ;
if ( F_22 ( V_6 -> V_90 ) )
return F_23 ( V_6 -> V_90 ) ;
V_6 -> V_33 = V_6 -> V_90 + V_6 -> V_28 -> V_87 ;
V_6 -> V_35 = V_6 -> V_90 + V_6 -> V_28 -> V_88 ;
} else {
V_51 = L_27 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
V_6 -> V_35 = F_33 ( V_10 , V_81 ) ;
if ( F_22 ( V_6 -> V_35 ) )
return F_23 ( V_6 -> V_35 ) ;
V_51 = L_28 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
V_6 -> V_33 = F_33 ( V_10 , V_81 ) ;
if ( F_22 ( V_6 -> V_33 ) )
return F_23 ( V_6 -> V_33 ) ;
}
V_51 = L_29 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
if ( ! V_81 ) {
F_16 ( V_10 , L_30 , V_51 ) ;
return - V_42 ;
}
V_6 -> V_7 = F_34 ( V_10 , V_81 -> V_91 ,
F_35 ( V_81 ) ) ;
if ( ! V_6 -> V_7 ) {
F_16 ( V_10 , L_31 , V_51 ) ;
return - V_67 ;
}
V_51 = L_32 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
if ( ! V_81 ) {
F_17 ( V_10 , L_30 , V_51 ) ;
V_29 = - V_42 ;
goto V_92;
}
V_6 -> V_74 = F_34 ( V_10 , V_81 -> V_91 ,
F_35 ( V_81 ) ) ;
if ( ! V_6 -> V_74 ) {
F_16 ( V_10 , L_31 , V_51 ) ;
return - V_67 ;
}
V_51 = L_33 ;
V_81 = F_32 ( V_77 , V_89 , V_51 ) ;
if ( ! V_81 ) {
F_17 ( V_10 , L_30 , V_51 ) ;
V_29 = - V_42 ;
goto V_92;
}
V_6 -> V_18 = F_33 ( V_10 , V_81 ) ;
if ( F_22 ( V_6 -> V_18 ) )
return F_23 ( V_6 -> V_18 ) ;
V_51 = L_34 ;
V_29 =
F_20 ( V_77 -> V_10 . V_52 , V_51 ,
& V_6 -> V_19 ) ;
if ( V_29 ) {
F_16 ( V_10 , L_35 , V_51 , V_29 ) ;
return V_29 ;
}
if ( ! V_6 -> V_19 ) {
F_16 ( V_10 , L_11 , V_51 ) ;
return - V_44 ;
}
V_51 = L_36 ;
V_29 =
F_20 ( V_77 -> V_10 . V_52 , V_51 ,
& V_6 -> V_20 ) ;
if ( V_29 ) {
F_16 ( V_10 , L_35 , V_51 , V_29 ) ;
return V_29 ;
}
if ( ! V_6 -> V_20 ) {
F_16 ( V_10 , L_11 , V_51 ) ;
return - V_44 ;
}
V_92:
V_51 = L_37 ;
V_29 =
F_20 ( V_77 -> V_10 . V_52 , V_51 ,
& V_6 -> V_8 ) ;
if ( V_29 ) {
F_16 ( V_10 , L_35 , V_51 , V_29 ) ;
return V_29 ;
}
if ( ! V_6 -> V_8 ) {
F_16 ( V_10 , L_11 , V_51 ) ;
return - V_44 ;
}
V_82 = F_36 ( V_10 , V_77 -> V_10 . V_52 ) ;
if ( ! V_82 ) {
F_16 ( V_10 , L_38 ,
V_14 ) ;
return - V_67 ;
}
V_29 = F_26 ( V_10 , V_6 , V_82 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_19 ( V_10 , V_6 ) ;
if ( V_29 )
return V_29 ;
V_40 = & V_6 -> V_68 ;
V_40 -> V_93 = F_37 ( V_10 ) ;
V_40 -> V_94 = V_95 ;
V_40 -> type = V_96 ;
V_40 -> V_97 = & V_98 ;
V_64 = & V_82 -> V_65 ;
if ( V_40 -> V_43 > 1 )
V_64 -> V_99 |= V_100 ;
V_64 -> V_101 = true ;
V_84 . V_10 = V_10 ;
V_84 . V_102 = V_82 ;
V_84 . V_103 = V_6 ;
V_84 . V_52 = V_77 -> V_10 . V_52 ;
V_26 = F_38 ( V_10 , V_40 , & V_84 ) ;
if ( F_22 ( V_26 ) ) {
V_29 = F_23 ( V_26 ) ;
F_16 ( V_10 , L_39 ,
V_14 , V_29 ) ;
return V_29 ;
}
F_39 ( V_77 , V_26 ) ;
F_1 ( V_6 -> V_28 -> V_104 , 1 , V_6 -> V_33 ) ;
return 0 ;
}
