static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
void T_1 * V_6 ;
struct V_7 * V_8 ;
if ( ! V_4 ) {
F_2 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_8 = F_3 ( V_2 , V_11 , 1 ) ;
if ( ! V_8 ) {
F_2 ( & V_2 -> V_9 , L_2 ) ;
return - V_10 ;
}
V_6 = F_4 ( V_8 -> V_12 , F_5 ( V_8 ) ) ;
if ( ! V_6 ) {
F_2 ( & V_2 -> V_9 , L_3 ) ;
return - V_13 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
F_6 ( 0 , V_6 + F_7 ( V_5 ) ) ;
F_6 ( 0 , V_6 + F_8 ( V_5 ) ) ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_15 ; V_5 ++ ) {
const struct V_16 * V_17 = V_4 -> V_17 + V_5 ;
F_6 ( ( ( V_17 -> V_18 - 1 ) & 0xffff0000 ) |
( V_17 -> V_19 << 8 ) |
( V_4 -> V_20 << 4 ) | 1 ,
V_6 + F_7 ( V_5 ) ) ;
F_6 ( V_17 -> V_21 , V_6 + F_8 ( V_5 ) ) ;
}
F_9 ( V_6 ) ;
return 0 ;
}
static void F_10 ( struct V_22 * V_23 , T_2 V_24 )
{
struct V_1 * V_2 = F_11 ( F_12 ( V_23 -> V_25 ) ) ;
struct V_26 * V_27 = V_2 -> V_9 . V_28 ;
F_13 ( V_23 , V_24 ) ;
if ( V_24 == V_29 ) {
if ( V_27 && 0 != V_27 -> V_30 ) {
T_3 V_31 ;
V_31 = F_14 ( V_23 -> V_32 + V_33 ) ;
V_31 |= ( V_27 -> V_30 & V_34 )
<< V_35 ;
V_31 |= V_36 ;
F_15 ( V_31 , V_23 -> V_32 + V_33 ) ;
}
}
}
static void F_16 ( struct V_22 * V_23 , T_2 V_37 )
{
struct V_38 * V_39 = F_17 ( V_23 ) ;
struct V_40 * V_41 = V_39 -> V_42 ;
T_3 V_31 ;
int V_43 ;
if ( V_41 -> V_37 == V_44
&& V_37 == V_45 ) {
F_18 ( F_12 ( V_23 -> V_25 ) ,
L_4
L_5 ,
V_46 ,
V_41 -> V_37 ,
V_37 ) ;
V_31 = F_14 ( V_23 -> V_32 + V_47 ) ;
V_31 |= V_48 ;
F_15 ( V_31 , V_23 -> V_32 + V_47 ) ;
V_31 = F_14 ( V_23 -> V_32 + V_49 ) ;
V_31 |= V_50 ;
F_15 ( V_31 , V_23 -> V_32 + V_49 ) ;
F_19 ( 740 ) ;
V_43 = 0 ;
while ( V_43 ++ < V_51 ) {
if ( ( F_14 ( V_23 -> V_32 + V_47 )
& V_52 ) == 0 )
break;
F_19 ( 10 ) ;
}
if ( V_43 == V_51 )
F_20 ( F_12 ( V_23 -> V_25 ) , L_6 ) ;
V_31 = F_14 ( V_23 -> V_32 + V_47 ) ;
V_31 |= V_52 ;
F_15 ( V_31 , V_23 -> V_32 + V_47 ) ;
}
V_41 -> V_37 = V_37 ;
}
static void F_21 ( struct V_22 * V_23 , unsigned int V_53 )
{
T_3 V_54 ;
V_54 = F_22 ( V_23 , V_55 ) ;
V_54 &= ~ V_56 ;
switch ( V_53 ) {
case V_57 :
V_54 |= V_58 ;
break;
case V_59 :
V_54 |= V_60 ;
break;
case V_61 :
V_54 |= V_62 | V_63 ;
break;
case V_64 :
V_54 |= V_65 | V_63 ;
break;
case V_66 :
V_54 |= V_67 | V_63 ;
break;
}
F_23 ( V_23 , V_54 , V_55 ) ;
F_18 ( F_12 ( V_23 -> V_25 ) ,
L_7 ,
V_46 , V_53 , V_54 ) ;
}
static struct V_26 * F_24 ( struct V_68 * V_9 )
{
struct V_26 * V_27 ;
struct V_69 * V_70 = V_9 -> V_71 ;
T_4 V_30 ;
V_27 = F_25 ( V_9 , sizeof( * V_27 ) , V_72 ) ;
if ( ! V_27 )
return NULL ;
F_26 ( V_70 , L_8 , & V_30 ) ;
if ( V_30 > 0 )
V_27 -> V_30 = V_30 ;
return V_27 ;
}
static inline struct V_26 * F_24 ( struct V_68 * V_9 )
{
return NULL ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_26 * V_27 = V_2 -> V_9 . V_28 ;
struct V_68 * V_9 = & V_2 -> V_9 ;
struct V_69 * V_70 = V_2 -> V_9 . V_71 ;
struct V_22 * V_23 = NULL ;
struct V_40 * V_41 = NULL ;
const struct V_73 * V_74 ;
int V_75 ;
struct V_76 * V_76 ;
V_41 = F_25 ( & V_2 -> V_9 , sizeof( struct V_40 ) , V_72 ) ;
if ( ! V_41 )
return - V_13 ;
V_23 = F_28 ( V_2 , & V_77 , 0 ) ;
if ( F_29 ( V_23 ) )
return F_30 ( V_23 ) ;
if ( F_31 ( V_70 , L_9 ) ) {
V_75 = F_1 ( V_2 , F_32 () ) ;
if ( V_75 < 0 )
goto V_78;
}
V_39 = F_17 ( V_23 ) ;
V_39 -> V_42 = V_41 ;
V_76 = F_33 ( V_9 , NULL ) ;
if ( F_29 ( V_76 ) ) {
F_2 ( V_9 , L_10 ) ;
V_75 = F_30 ( V_76 ) ;
goto V_79;
}
V_39 -> V_76 = V_76 ;
F_34 ( V_76 ) ;
V_23 -> V_25 -> V_80 |= V_81 ;
V_74 = F_35 ( F_36 ( V_82 ) , & V_2 -> V_9 ) ;
if ( V_74 ) {
V_75 = F_37 ( V_23 -> V_25 ) ;
if ( V_75 )
goto V_83;
F_38 ( V_2 ) ;
V_27 = F_24 ( V_9 ) ;
} else if ( V_27 ) {
if ( V_27 -> V_84 & V_85 )
V_23 -> V_25 -> V_80 |= V_86 ;
if ( V_27 -> V_84 & V_87 )
V_23 -> V_25 -> V_80 |= V_88 ;
if ( V_27 -> V_89 )
V_23 -> V_89 |= V_27 -> V_89 ;
if ( V_27 -> V_90 )
V_23 -> V_90 |= V_27 -> V_90 ;
if ( V_27 -> V_91 )
V_23 -> V_25 -> V_80 |= V_27 -> V_91 ;
if ( V_27 -> V_92 )
V_23 -> V_25 -> V_93 |= V_27 -> V_92 ;
if ( V_27 -> V_94 )
V_23 -> V_25 -> V_94 |= V_27 -> V_94 ;
if ( F_39 ( V_27 -> V_95 ) ) {
V_75 = F_40 ( V_23 -> V_25 , V_27 -> V_95 ,
0 ) ;
if ( V_75 ) {
F_2 ( F_12 ( V_23 -> V_25 ) ,
L_11 ) ;
goto V_96;
}
}
}
F_41 ( & V_2 -> V_9 ) ;
F_42 ( & V_2 -> V_9 ) ;
F_43 ( & V_2 -> V_9 , V_97 ) ;
F_44 ( & V_2 -> V_9 ) ;
F_45 ( & V_2 -> V_9 , 1 ) ;
V_75 = F_46 ( V_23 ) ;
if ( V_75 ) {
F_2 ( & V_2 -> V_9 , L_12 ) ;
goto V_98;
}
F_47 ( V_2 , V_23 ) ;
if ( V_23 -> V_25 -> V_94 & V_99 ) {
F_48 ( & V_2 -> V_9 , 1 ) ;
V_23 -> V_25 -> V_100 |= V_101 ;
} else {
F_48 ( & V_2 -> V_9 , 0 ) ;
}
F_49 ( & V_2 -> V_9 ) ;
return 0 ;
V_98:
F_50 ( & V_2 -> V_9 ) ;
F_51 ( & V_2 -> V_9 ) ;
V_83:
V_96:
F_52 ( V_76 ) ;
V_79:
V_78:
F_53 ( V_2 ) ;
return V_75 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_55 ( V_2 ) ;
struct V_38 * V_39 = F_17 ( V_23 ) ;
F_42 ( & V_2 -> V_9 ) ;
F_56 ( V_23 , 1 ) ;
F_51 ( & V_2 -> V_9 ) ;
F_52 ( V_39 -> V_76 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_68 * V_9 )
{
int V_75 ;
struct V_22 * V_23 = F_58 ( V_9 ) ;
F_42 ( V_9 ) ;
V_75 = F_59 ( V_23 ) ;
F_60 ( V_9 ) ;
F_49 ( V_9 ) ;
return V_75 ;
}
static int F_61 ( struct V_68 * V_9 )
{
int V_75 ;
struct V_22 * V_23 = F_58 ( V_9 ) ;
F_42 ( V_9 ) ;
V_75 = F_62 ( V_23 ) ;
F_60 ( V_9 ) ;
F_49 ( V_9 ) ;
return V_75 ;
}
static int F_63 ( struct V_68 * V_9 )
{
struct V_22 * V_23 = F_58 ( V_9 ) ;
struct V_38 * V_39 = F_17 ( V_23 ) ;
unsigned long V_84 ;
if ( V_39 -> V_76 ) {
F_64 ( & V_23 -> V_102 , V_84 ) ;
V_23 -> V_103 = true ;
F_65 ( & V_23 -> V_102 , V_84 ) ;
F_52 ( V_39 -> V_76 ) ;
}
return 0 ;
}
static int F_66 ( struct V_68 * V_9 )
{
struct V_22 * V_23 = F_58 ( V_9 ) ;
struct V_38 * V_39 = F_17 ( V_23 ) ;
unsigned long V_84 ;
if ( V_39 -> V_76 ) {
F_34 ( V_39 -> V_76 ) ;
F_64 ( & V_23 -> V_102 , V_84 ) ;
V_23 -> V_103 = false ;
F_65 ( & V_23 -> V_102 , V_84 ) ;
}
return 0 ;
}
