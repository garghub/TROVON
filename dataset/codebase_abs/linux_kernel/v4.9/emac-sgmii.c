static void F_1 ( void T_1 * V_1 ,
const struct V_2 * V_3 , T_2 V_4 )
{
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_3 , ++ V_5 )
F_2 ( V_3 -> V_6 , V_1 + V_3 -> V_7 ) ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_12 * V_13 = & V_9 -> V_13 ;
T_3 V_6 ;
V_6 = F_4 ( V_13 -> V_1 + V_14 ) ;
if ( V_11 -> V_15 == V_16 ) {
V_6 &= ~ ( V_17 | V_18 ) ;
V_6 |= V_19 ;
F_2 ( V_6 , V_13 -> V_1 + V_14 ) ;
} else {
T_3 V_20 ;
switch ( V_11 -> V_21 ) {
case V_22 :
V_20 = V_23 ;
break;
case V_24 :
V_20 = V_25 ;
break;
case V_26 :
V_20 = V_27 ;
break;
default:
return - V_28 ;
}
if ( V_11 -> V_29 == V_30 )
V_20 |= V_31 ;
V_6 &= ~ V_19 ;
F_2 ( V_20 , V_13 -> V_1 + V_32 ) ;
F_2 ( V_6 , V_13 -> V_1 + V_14 ) ;
}
return 0 ;
}
static int F_5 ( struct V_8 * V_9 , T_3 V_33 )
{
struct V_12 * V_13 = & V_9 -> V_13 ;
T_3 V_34 ;
F_6 ( V_33 , V_13 -> V_1 + V_35 ) ;
F_6 ( V_36 , V_13 -> V_1 + V_37 ) ;
F_7 () ;
if ( F_8 ( V_13 -> V_1 +
V_38 ,
V_34 , ! ( V_34 & V_33 ) , 1 ,
V_39 ) ) {
F_9 ( V_9 -> V_40 ,
L_1 ,
V_34 , V_33 ) ;
return - V_41 ;
}
F_6 ( 0 , V_13 -> V_1 + V_37 ) ;
F_6 ( 0 , V_13 -> V_1 + V_35 ) ;
F_7 () ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_13 ;
unsigned int V_5 ;
int V_42 ;
V_42 = F_3 ( V_9 ) ;
if ( V_42 )
return V_42 ;
F_1 ( V_13 -> V_1 , V_43 ,
F_11 ( V_43 ) ) ;
F_1 ( V_13 -> V_1 , V_44 ,
F_11 ( V_44 ) ) ;
F_1 ( V_13 -> V_1 , V_45 , F_11 ( V_45 ) ) ;
F_1 ( V_13 -> V_1 , V_46 , F_11 ( V_46 ) ) ;
F_1 ( V_13 -> V_1 , V_47 ,
F_11 ( V_47 ) ) ;
F_2 ( V_48 , V_13 -> V_1 + V_49 ) ;
for ( V_5 = 0 ; V_5 < V_50 ; V_5 ++ ) {
if ( F_4 ( V_13 -> V_1 + V_51 ) & V_52 )
break;
F_12 ( 100 , 200 ) ;
}
if ( V_5 == V_50 ) {
F_9 ( V_9 -> V_40 , L_2 ) ;
return - V_41 ;
}
F_2 ( 0 , V_13 -> V_1 + V_53 ) ;
F_5 ( V_9 , V_54 ) ;
return 0 ;
}
int F_13 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_13 ;
void T_1 * V_55 = V_13 -> V_1 ;
void T_1 * V_56 = V_13 -> V_57 ;
unsigned int V_5 ;
T_3 V_58 ;
int V_42 ;
V_42 = F_3 ( V_9 ) ;
if ( V_42 )
return V_42 ;
F_1 ( V_13 -> V_1 , V_59 ,
F_11 ( V_59 ) ) ;
F_1 ( V_13 -> V_57 ,
V_60 , F_11 ( V_60 ) ) ;
F_2 ( 0 , V_55 + V_61 ) ;
F_2 ( 1 , V_56 + V_62 ) ;
for ( V_5 = 0 ; V_5 < V_50 ; V_5 ++ ) {
V_58 = F_4 ( V_55 + V_63 ) ;
if ( V_58 & F_14 ( 1 ) )
break;
F_12 ( 100 , 200 ) ;
}
if ( V_5 == V_50 ) {
F_9 ( V_9 -> V_40 , L_3 ) ;
return - V_41 ;
}
F_2 ( 0 , V_55 + V_64 ) ;
F_2 ( 0 , V_55 + V_65 ) ;
F_2 ( 0 , V_55 + V_66 ) ;
F_2 ( 0 , V_55 + V_53 ) ;
F_5 ( V_9 , V_54 ) ;
return 0 ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = & V_9 -> V_13 ;
T_3 V_6 ;
V_6 = F_4 ( V_13 -> V_1 + V_67 ) ;
F_2 ( ( ( V_6 & ~ V_68 ) | V_68 ) , V_13 -> V_1 +
V_67 ) ;
F_16 ( 50 ) ;
V_6 = F_4 ( V_13 -> V_1 + V_67 ) ;
F_2 ( ( V_6 & ~ V_68 ) , V_13 -> V_1 + V_67 ) ;
F_16 ( 50 ) ;
}
void F_17 ( struct V_8 * V_9 )
{
int V_42 ;
F_18 ( V_9 -> V_69 [ V_70 ] , 19200000 ) ;
F_15 ( V_9 ) ;
V_42 = V_9 -> V_13 . V_71 ( V_9 ) ;
if ( V_42 )
F_9 ( V_9 -> V_40 ,
L_4 ,
V_42 ) ;
F_18 ( V_9 -> V_69 [ V_70 ] , 125000000 ) ;
}
static int F_19 ( struct V_72 * V_73 , void * V_74 )
{
static const struct V_75 V_76 [] = {
{
. V_77 = L_5 ,
. V_78 = ( V_79 ) F_13 ,
} ,
{}
} ;
const struct V_75 * V_77 = F_20 ( V_76 , V_73 ) ;
T_4 * V_71 = V_74 ;
if ( V_77 )
* V_71 = ( T_4 ) V_77 -> V_78 ;
return ! ! V_77 ;
}
int F_21 ( struct V_80 * V_81 , struct V_8 * V_9 )
{
struct V_80 * V_82 = NULL ;
struct V_12 * V_13 = & V_9 -> V_13 ;
struct V_83 * V_84 ;
int V_42 ;
if ( F_22 ( & V_81 -> V_73 ) ) {
struct V_72 * V_73 ;
V_73 = F_23 ( & V_81 -> V_73 , & V_13 -> V_71 ,
F_19 ) ;
if ( ! V_73 ) {
F_24 ( & V_81 -> V_73 , L_6 ) ;
return - V_85 ;
}
V_82 = F_25 ( V_73 ) ;
} else {
const struct V_86 * V_87 ;
struct V_88 * V_89 ;
V_89 = F_26 ( V_81 -> V_73 . V_90 , L_7 , 0 ) ;
if ( ! V_89 ) {
F_24 ( & V_81 -> V_73 , L_8 ) ;
return - V_85 ;
}
V_82 = F_27 ( V_89 ) ;
if ( ! V_82 ) {
F_24 ( & V_81 -> V_73 , L_9 ) ;
return - V_85 ;
}
V_87 = F_28 ( V_91 , & V_82 -> V_73 ) ;
if ( ! V_87 ) {
F_24 ( & V_81 -> V_73 , L_10 ) ;
V_42 = - V_85 ;
goto V_92;
}
V_13 -> V_71 = ( T_4 ) V_87 -> V_74 ;
}
V_84 = F_29 ( V_82 , V_93 , 0 ) ;
if ( ! V_84 ) {
V_42 = - V_28 ;
goto V_92;
}
V_13 -> V_1 = F_30 ( V_84 -> V_94 , F_31 ( V_84 ) ) ;
if ( ! V_13 -> V_1 ) {
V_42 = - V_95 ;
goto V_92;
}
V_84 = F_29 ( V_82 , V_93 , 1 ) ;
if ( V_84 ) {
V_13 -> V_57 = F_30 ( V_84 -> V_94 , F_31 ( V_84 ) ) ;
if ( ! V_13 -> V_57 ) {
V_42 = - V_95 ;
goto V_96;
}
}
V_42 = V_13 -> V_71 ( V_9 ) ;
if ( V_42 )
goto error;
F_32 ( & V_82 -> V_73 ) ;
return 0 ;
error:
if ( V_13 -> V_57 )
F_33 ( V_13 -> V_57 ) ;
V_96:
F_33 ( V_13 -> V_1 ) ;
V_92:
F_32 ( & V_82 -> V_73 ) ;
return V_42 ;
}
