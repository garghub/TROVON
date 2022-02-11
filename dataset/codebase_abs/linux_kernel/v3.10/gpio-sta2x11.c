static inline struct V_1 T_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
return V_3 -> V_5 [ V_4 / V_6 ] ;
}
static inline T_2 F_2 ( int V_4 )
{
return 1U << ( V_4 % V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 , unsigned V_4 , int V_9 )
{
struct V_2 * V_3 = F_4 ( V_8 , struct V_2 , V_8 ) ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
if ( V_9 )
F_5 ( V_10 , & V_5 -> V_11 ) ;
else
F_5 ( V_10 , & V_5 -> V_12 ) ;
}
static int F_6 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_2 * V_3 = F_4 ( V_8 , struct V_2 , V_8 ) ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
return F_7 ( & V_5 -> V_13 ) & V_10 ;
}
static int F_8 ( struct V_7 * V_8 , unsigned V_4 ,
int V_9 )
{
struct V_2 * V_3 = F_4 ( V_8 , struct V_2 , V_8 ) ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
F_5 ( V_10 , & V_5 -> V_14 ) ;
if ( V_9 )
F_5 ( V_10 , & V_5 -> V_11 ) ;
else
F_5 ( V_10 , & V_5 -> V_12 ) ;
return 0 ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_4 )
{
struct V_2 * V_3 = F_4 ( V_8 , struct V_2 , V_8 ) ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
F_5 ( V_10 , & V_5 -> V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , unsigned V_16 )
{
struct V_2 * V_3 = F_4 ( V_8 , struct V_2 , V_8 ) ;
return V_3 -> V_17 + V_16 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_8 ;
static int V_18 ;
V_8 -> V_19 = F_12 ( V_3 -> V_20 ) ;
V_8 -> V_21 = V_22 ;
V_8 -> V_23 = F_9 ;
V_8 -> V_24 = F_6 ;
V_8 -> V_25 = F_8 ;
V_8 -> V_26 = F_3 ;
V_8 -> V_27 = NULL ;
V_8 -> V_28 = V_18 ;
V_8 -> V_29 = V_30 ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = F_10 ;
if ( ! V_18 )
V_18 = - 1 ;
}
static void F_13 ( struct V_2 * V_3 , int V_4 , unsigned V_33 )
{
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
unsigned long V_34 ;
T_2 V_10 = F_2 ( V_4 ) ;
T_2 V_9 ;
int V_35 = 0 ;
F_14 ( L_1 , V_36 , V_3 , V_4 , V_33 ) ;
if ( V_33 == V_37 )
return;
F_15 ( & V_3 -> V_38 , V_34 ) ;
V_9 = F_7 ( & V_5 -> V_39 ) ;
if ( V_33 == V_40 )
V_9 |= V_10 ;
else
V_9 &= ~ V_10 ;
F_5 ( V_9 | V_10 , & V_5 -> V_39 ) ;
if ( V_33 == V_40 ) {
F_16 ( & V_3 -> V_38 , V_34 ) ;
return;
}
switch ( V_33 ) {
case V_41 :
F_5 ( V_10 , & V_5 -> V_14 ) ;
F_5 ( V_10 , & V_5 -> V_12 ) ;
break;
case V_42 :
F_5 ( V_10 , & V_5 -> V_14 ) ;
F_5 ( V_10 , & V_5 -> V_11 ) ;
break;
case V_43 :
F_5 ( V_10 , & V_5 -> V_15 ) ;
V_9 = F_7 ( & V_5 -> V_44 ) | V_10 ;
F_5 ( V_9 , & V_5 -> V_44 ) ;
break;
case V_45 :
F_5 ( V_10 , & V_5 -> V_15 ) ;
V_9 = F_7 ( & V_5 -> V_44 ) & ~ V_10 ;
F_5 ( V_9 , & V_5 -> V_44 ) ;
F_5 ( V_10 , & V_5 -> V_11 ) ;
break;
case V_46 :
F_5 ( V_10 , & V_5 -> V_15 ) ;
V_9 = F_7 ( & V_5 -> V_44 ) & ~ V_10 ;
F_5 ( V_9 , & V_5 -> V_44 ) ;
F_5 ( V_10 , & V_5 -> V_12 ) ;
break;
default:
V_35 = 1 ;
}
F_16 ( & V_3 -> V_38 , V_34 ) ;
if ( V_35 )
F_17 ( L_2 ,
V_36 , V_3 , V_4 , V_33 ) ;
}
static void F_18 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_19 ( V_48 ) ;
struct V_2 * V_3 = V_50 -> V_51 ;
int V_4 = V_48 -> V_52 - V_3 -> V_17 ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
T_2 V_9 ;
unsigned long V_34 ;
F_15 ( & V_3 -> V_38 , V_34 ) ;
if ( V_3 -> V_53 [ V_4 ] & V_54 ) {
V_9 = F_7 ( & V_5 -> V_55 ) & ~ V_10 ;
F_5 ( V_9 , & V_5 -> V_55 ) ;
}
if ( V_3 -> V_53 [ V_4 ] & V_56 ) {
V_9 = F_7 ( & V_5 -> V_57 ) & ~ V_10 ;
F_5 ( V_9 , & V_5 -> V_57 ) ;
}
F_16 ( & V_3 -> V_38 , V_34 ) ;
return;
}
static void F_20 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_19 ( V_48 ) ;
struct V_2 * V_3 = V_50 -> V_51 ;
int V_4 = V_48 -> V_52 - V_3 -> V_17 ;
struct V_1 T_1 * V_5 = F_1 ( V_3 , V_4 ) ;
T_2 V_10 = F_2 ( V_4 ) ;
T_2 V_9 ;
int type ;
unsigned long V_34 ;
type = V_3 -> V_53 [ V_4 ] ;
F_15 ( & V_3 -> V_38 , V_34 ) ;
V_9 = F_7 ( & V_5 -> V_55 ) ;
if ( type & V_54 )
F_5 ( V_9 | V_10 , & V_5 -> V_55 ) ;
else
F_5 ( V_9 & ~ V_10 , & V_5 -> V_55 ) ;
V_9 = F_7 ( & V_5 -> V_55 ) ;
if ( type & V_56 )
F_5 ( V_9 | V_10 , & V_5 -> V_57 ) ;
else
F_5 ( V_9 & ~ V_10 , & V_5 -> V_57 ) ;
F_16 ( & V_3 -> V_38 , V_34 ) ;
return;
}
static int F_21 ( struct V_47 * V_58 , unsigned int type )
{
struct V_49 * V_50 = F_19 ( V_58 ) ;
struct V_2 * V_3 = V_50 -> V_51 ;
int V_4 = V_58 -> V_52 - V_3 -> V_17 ;
if ( ! ( type & ( V_54 | V_56 ) ) ) {
F_22 ( L_3 , V_36 , type ) ;
return - V_59 ;
}
V_3 -> V_53 [ V_4 ] = type ;
F_20 ( V_58 ) ;
return 0 ;
}
static T_3 F_23 ( int V_52 , void * V_60 )
{
struct V_2 * V_3 = V_60 ;
struct V_1 T_1 * V_5 ;
T_2 V_61 ;
int V_62 , V_4 , V_28 ;
T_3 V_63 = V_64 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
V_5 = V_3 -> V_5 [ V_62 ] ;
V_28 = V_3 -> V_17 + V_62 * V_6 ;
while ( ( V_61 = F_7 ( & V_5 -> V_61 ) ) ) {
V_4 = F_24 ( V_61 ) ;
V_52 = V_28 + V_4 ;
F_25 ( V_52 ) ;
F_5 ( 1 << V_4 , & V_5 -> V_66 ) ;
V_63 = V_67 ;
}
}
return V_63 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_49 * V_50 ;
struct V_68 * V_69 ;
V_50 = F_27 ( V_70 , 1 , V_3 -> V_17 ,
V_3 -> V_71 , V_72 ) ;
V_50 -> V_51 = V_3 ;
V_69 = V_50 -> V_73 ;
V_69 -> V_3 . V_74 = F_21 ;
V_69 -> V_3 . V_75 = F_18 ;
V_69 -> V_3 . V_76 = F_20 ;
F_28 ( V_50 , 0 , 0 ,
V_77 | V_78 , 0 ) ;
{
struct V_68 * V_69 = V_50 -> V_73 ;
int V_62 , V_79 ;
for ( V_79 = 0 ; V_79 < V_30 ; V_79 ++ ) {
V_62 = V_3 -> V_17 + V_79 ;
F_29 ( V_62 , & V_69 -> V_3 , V_69 -> V_80 ) ;
F_30 ( V_62 , V_50 ) ;
F_31 ( V_62 , V_77 | V_78 , 0 ) ;
}
V_50 -> V_81 = V_62 - V_50 -> V_17 ;
}
}
static int F_32 ( struct V_82 * V_20 )
{
int V_62 , V_35 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_2 * V_3 ;
struct V_87 * V_88 ;
V_84 = * (struct V_83 * * ) ( V_20 -> V_20 . V_89 ) ;
V_86 = F_33 ( & V_84 -> V_20 ) ;
if ( V_86 == NULL )
F_34 ( & V_20 -> V_20 , L_4 ) ;
F_22 ( L_5 , V_86 ) ;
V_88 = F_35 ( V_20 , V_90 , 0 ) ;
V_3 = F_36 ( & V_20 -> V_20 , sizeof( * V_3 ) , V_91 ) ;
V_3 -> V_20 = & V_20 -> V_20 ;
V_3 -> V_71 = F_37 ( & V_20 -> V_20 , V_88 ) ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
V_3 -> V_5 [ V_62 ] = V_3 -> V_71 + V_62 * 4096 ;
F_5 ( 0 , & V_3 -> V_5 [ V_62 ] -> V_55 ) ;
F_5 ( 0 , & V_3 -> V_5 [ V_62 ] -> V_57 ) ;
F_5 ( ~ 0 , & V_3 -> V_5 [ V_62 ] -> V_66 ) ;
}
F_38 ( & V_3 -> V_38 ) ;
F_11 ( V_3 ) ;
if ( V_86 )
for ( V_62 = 0 ; V_62 < V_30 ; V_62 ++ )
F_13 ( V_3 , V_62 , V_86 -> V_92 [ V_62 ] ) ;
V_35 = F_39 ( - 1 , 384 , V_30 , V_93 ) ;
if ( V_35 < 0 ) {
F_40 ( & V_20 -> V_20 , L_6 ,
- V_35 ) ;
return V_35 ;
}
V_3 -> V_17 = V_35 ;
F_26 ( V_3 ) ;
V_35 = F_41 ( V_84 -> V_52 , F_23 ,
V_94 , V_70 , V_3 ) ;
if ( V_35 < 0 ) {
F_34 ( & V_20 -> V_20 , L_7 ,
- V_35 ) ;
goto V_95;
}
V_35 = F_42 ( & V_3 -> V_8 ) ;
if ( V_35 < 0 ) {
F_34 ( & V_20 -> V_20 , L_8 ,
- V_35 ) ;
goto V_96;
}
F_43 ( V_20 , V_3 ) ;
return 0 ;
V_96:
F_44 ( V_84 -> V_52 , V_3 ) ;
V_95:
F_45 ( V_3 -> V_17 , V_30 ) ;
return V_35 ;
}
