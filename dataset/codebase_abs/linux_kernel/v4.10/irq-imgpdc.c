static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static unsigned int F_5 ( T_1 V_6 )
{
return V_6 >= V_7 ;
}
static unsigned int F_6 ( T_1 V_6 )
{
return V_6 - V_7 ;
}
static T_1 F_7 ( unsigned int V_8 )
{
return V_7 + V_8 ;
}
static struct V_1 * F_8 ( struct V_9 * V_4 )
{
return (struct V_1 * ) V_4 -> V_10 -> V_11 ;
}
static void F_9 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_4 ) ;
F_10 ( & V_2 -> V_12 ) ;
V_2 -> V_13 &= ~ V_4 -> V_14 ;
F_1 ( V_2 , V_15 , V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_12 ) ;
}
static void F_12 ( struct V_9 * V_4 )
{
struct V_1 * V_2 = F_8 ( V_4 ) ;
F_10 ( & V_2 -> V_12 ) ;
V_2 -> V_13 |= V_4 -> V_14 ;
F_1 ( V_2 , V_15 , V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_12 ) ;
}
static int F_13 ( struct V_9 * V_4 , unsigned int V_16 )
{
struct V_1 * V_2 = F_8 ( V_4 ) ;
unsigned int V_8 = F_6 ( V_4 -> V_17 ) ;
unsigned int V_18 ;
unsigned int V_19 , V_20 ;
switch ( V_16 ) {
case V_21 :
V_18 = V_22 ;
break;
case V_23 :
V_18 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
break;
case V_27 :
V_18 = V_28 ;
break;
case V_29 :
V_18 = V_30 ;
break;
default:
return - V_31 ;
}
F_10 ( & V_2 -> V_12 ) ;
V_19 = V_32 + V_8 * V_33 ;
V_20 = F_3 ( V_2 , V_19 ) ;
V_20 &= ~ V_34 ;
V_20 |= V_18 << V_35 ;
F_1 ( V_2 , V_19 , V_20 ) ;
F_14 ( V_4 , V_16 ) ;
F_11 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_4 , unsigned int V_36 )
{
struct V_1 * V_2 = F_8 ( V_4 ) ;
T_1 V_6 = V_4 -> V_17 ;
unsigned int V_14 = ( 1 << 16 ) << V_6 ;
unsigned int V_37 ;
F_10 ( & V_2 -> V_12 ) ;
if ( V_36 )
V_2 -> V_13 |= V_14 ;
else
V_2 -> V_13 &= ~ V_14 ;
F_1 ( V_2 , V_15 , V_2 -> V_13 ) ;
F_11 ( & V_2 -> V_12 ) ;
if ( F_5 ( V_6 ) )
V_37 = V_2 -> V_38 ;
else
V_37 = V_2 -> V_39 [ V_6 ] ;
F_16 ( V_37 , V_36 ) ;
return 0 ;
}
static void F_17 ( struct V_40 * V_41 )
{
unsigned int V_42 = F_18 ( V_41 ) ;
struct V_1 * V_2 ;
unsigned int V_43 , V_44 ;
V_2 = (struct V_1 * ) F_19 ( V_41 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_45 ; ++ V_43 )
if ( V_42 == V_2 -> V_39 [ V_43 ] )
goto V_46;
return;
V_46:
V_44 = F_20 ( V_2 -> V_10 , V_43 ) ;
F_21 ( V_44 ) ;
}
static void F_22 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
unsigned int V_8 , V_44 ;
unsigned int V_47 ;
V_2 = (struct V_1 * ) F_19 ( V_41 ) ;
V_47 = F_3 ( V_2 , V_48 ) &
F_3 ( V_2 , V_49 ) ;
V_47 &= ( 1 << V_2 -> V_50 ) - 1 ;
for ( V_8 = 0 ; V_47 ; V_47 >>= 1 , ++ V_8 ) {
if ( ! ( V_47 & 1 ) )
continue;
V_44 = F_20 ( V_2 -> V_10 ,
F_7 ( V_8 ) ) ;
F_21 ( V_44 ) ;
}
}
static void F_23 ( struct V_1 * V_2 )
{
int V_43 ;
unsigned int V_19 ;
unsigned int V_20 ;
F_1 ( V_2 , V_49 , 0 ) ;
V_2 -> V_13 = ( ( V_51 << V_2 -> V_50 ) -
V_51 ) ;
F_1 ( V_2 , V_15 , V_2 -> V_13 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_50 ; ++ V_43 ) {
V_19 = V_32 + V_43 * V_33 ;
V_20 = V_52
<< V_35 ;
F_1 ( V_2 , V_19 , V_20 ) ;
}
}
static int F_24 ( struct V_53 * V_54 )
{
struct V_1 * V_2 ;
struct V_55 * V_56 = V_54 -> V_57 . V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
unsigned int V_43 ;
int V_42 , V_63 ;
T_2 V_64 ;
if ( ! V_56 )
return - V_65 ;
V_60 = F_25 ( V_54 , V_66 , 0 ) ;
if ( V_60 == NULL ) {
F_26 ( & V_54 -> V_57 , L_1 ) ;
return - V_65 ;
}
V_2 = F_27 ( & V_54 -> V_57 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 ) {
F_26 ( & V_54 -> V_57 , L_2 ) ;
return - V_68 ;
}
F_28 ( & V_2 -> V_12 ) ;
F_29 ( V_54 , V_2 ) ;
V_2 -> V_5 = F_30 ( & V_54 -> V_57 , V_60 -> V_69 ,
V_60 -> V_70 - V_60 -> V_69 ) ;
if ( ! V_2 -> V_5 )
return - V_71 ;
V_63 = F_31 ( V_56 , L_3 , & V_64 ) ;
if ( V_63 ) {
F_26 ( & V_54 -> V_57 , L_4 ) ;
return - V_31 ;
}
if ( V_64 > V_7 ) {
F_26 ( & V_54 -> V_57 , L_5 , V_64 ) ;
return - V_31 ;
}
V_2 -> V_45 = V_64 ;
V_63 = F_31 ( V_56 , L_6 , & V_64 ) ;
if ( V_63 ) {
F_26 ( & V_54 -> V_57 , L_7 ) ;
return - V_31 ;
}
if ( V_64 > V_7 ) {
F_26 ( & V_54 -> V_57 , L_8 , V_64 ) ;
return - V_31 ;
}
V_2 -> V_50 = V_64 ;
V_2 -> V_39 = F_27 ( & V_54 -> V_57 , 4 * V_2 -> V_45 ,
V_67 ) ;
if ( ! V_2 -> V_39 ) {
F_26 ( & V_54 -> V_57 , L_9 ) ;
return - V_68 ;
}
for ( V_43 = 0 ; V_43 < V_2 -> V_45 ; ++ V_43 ) {
V_42 = F_32 ( V_54 , 1 + V_43 ) ;
if ( V_42 < 0 ) {
F_26 ( & V_54 -> V_57 , L_10 , V_43 ) ;
return V_42 ;
}
V_2 -> V_39 [ V_43 ] = V_42 ;
}
if ( F_32 ( V_54 , 1 + V_43 ) >= 0 ) {
F_26 ( & V_54 -> V_57 , L_11 ) ;
return - V_31 ;
}
V_42 = F_32 ( V_54 , 0 ) ;
if ( V_42 < 0 ) {
F_26 ( & V_54 -> V_57 , L_12 ) ;
return V_42 ;
}
V_2 -> V_38 = V_42 ;
V_2 -> V_10 = F_33 ( V_56 , 16 , & V_72 ,
V_2 ) ;
if ( F_34 ( ! V_2 -> V_10 ) ) {
F_26 ( & V_54 -> V_57 , L_13 ) ;
return - V_68 ;
}
V_63 = F_35 ( V_2 -> V_10 , 8 , 2 , L_14 ,
V_73 , 0 , 0 ,
V_74 ) ;
if ( V_63 )
goto V_75;
V_62 = F_36 ( V_2 -> V_10 , 0 ) ;
V_62 -> V_76 = ~ ( F_37 ( V_2 -> V_45 ) - 1 ) ;
V_62 -> V_77 = V_2 -> V_5 ;
V_62 -> V_78 [ 0 ] . V_79 . V_14 = V_15 ;
V_62 -> V_78 [ 0 ] . V_80 . V_81 = F_9 ;
V_62 -> V_78 [ 0 ] . V_80 . V_82 = F_12 ;
V_62 -> V_78 [ 0 ] . V_80 . V_83 = F_15 ;
V_62 = F_36 ( V_2 -> V_10 , 8 ) ;
V_62 -> V_76 = ~ ( F_37 ( V_2 -> V_50 ) - 1 ) ;
V_62 -> V_77 = V_2 -> V_5 ;
V_62 -> V_78 [ 0 ] . type = V_21 ;
V_62 -> V_78 [ 0 ] . V_84 = V_85 ;
V_62 -> V_78 [ 0 ] . V_79 . V_86 = V_87 ;
V_62 -> V_78 [ 0 ] . V_79 . V_14 = V_49 ;
V_62 -> V_78 [ 0 ] . V_80 . V_88 = V_89 ;
V_62 -> V_78 [ 0 ] . V_80 . V_81 = V_90 ;
V_62 -> V_78 [ 0 ] . V_80 . V_82 = V_91 ;
V_62 -> V_78 [ 0 ] . V_80 . V_92 = F_13 ;
V_62 -> V_78 [ 0 ] . V_80 . V_83 = F_15 ;
V_62 -> V_78 [ 0 ] . V_80 . V_93 = V_94 ;
V_62 -> V_78 [ 1 ] . type = V_95 ;
V_62 -> V_78 [ 1 ] . V_84 = V_73 ;
V_62 -> V_78 [ 1 ] . V_79 . V_86 = V_87 ;
V_62 -> V_78 [ 1 ] . V_79 . V_14 = V_49 ;
V_62 -> V_78 [ 1 ] . V_80 . V_88 = V_89 ;
V_62 -> V_78 [ 1 ] . V_80 . V_81 = V_90 ;
V_62 -> V_78 [ 1 ] . V_80 . V_82 = V_91 ;
V_62 -> V_78 [ 1 ] . V_80 . V_92 = F_13 ;
V_62 -> V_78 [ 1 ] . V_80 . V_83 = F_15 ;
V_62 -> V_78 [ 1 ] . V_80 . V_93 = V_94 ;
F_23 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < V_2 -> V_45 ; ++ V_43 ) {
V_42 = V_2 -> V_39 [ V_43 ] ;
F_38 ( V_42 , F_17 ,
V_2 ) ;
}
F_38 ( V_2 -> V_38 ,
F_22 , V_2 ) ;
F_39 ( & V_54 -> V_57 ,
L_15 ,
V_2 -> V_45 ,
V_2 -> V_50 ) ;
return 0 ;
V_75:
F_40 ( V_2 -> V_10 ) ;
return V_63 ;
}
static int F_41 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_42 ( V_54 ) ;
F_40 ( V_2 -> V_10 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_96 ) ;
}
