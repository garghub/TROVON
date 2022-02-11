static inline void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) & ~ V_7 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_6 ( void * V_8 , int V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
T_1 V_10 , V_3 ;
V_10 = F_2 ( V_2 -> V_4 + V_11 ) & ~ V_7 ;
F_3 ( V_10 , V_2 -> V_4 + V_11 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_9 )
V_3 &= ~ V_7 ;
else
V_3 |= V_7 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static void F_7 ( void * V_8 , int V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
T_1 V_10 , V_3 ;
V_10 = F_2 ( V_2 -> V_4 + V_11 ) & ~ V_6 ;
F_3 ( V_10 , V_2 -> V_4 + V_11 ) ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( V_9 )
V_3 &= ~ V_6 ;
else
V_3 |= V_6 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
}
static int F_8 ( void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_4 ( V_2 ) ;
return ( F_2 ( V_2 -> V_4 + V_12 ) & V_7 ) ? 1 : 0 ;
}
static int F_9 ( void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
F_1 ( V_2 ) ;
return ( F_2 ( V_2 -> V_4 + V_12 ) & V_6 ) ? 1 : 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_13 , T_1 V_8 )
{
T_1 V_14 [ 2 ] = {
V_13 ,
V_8
} ;
struct V_15 V_16 = {
. V_17 = V_18 ,
. V_19 = 2 ,
. V_20 = V_14 ,
} ;
int V_21 ;
if ( ( V_13 == 5 ) && ( V_8 == V_2 -> V_22 ) )
return 0 ;
V_21 = F_11 ( & V_2 -> V_23 , & V_16 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_13 == 5 )
V_2 -> V_22 = V_8 ;
return 0 ;
}
static void F_12 ( struct V_24 * V_25 )
{
struct V_1 * V_2 =
F_13 ( V_25 , struct V_1 , V_26 . V_25 ) ;
struct V_27 * V_28 ;
T_1 V_29 = V_2 -> V_22 ;
int V_30 , V_31 = 0 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_32 ; V_30 ++ ) {
V_29 &= ~ F_14 ( V_30 ) ;
V_29 |= F_15 ( V_30 ) ;
V_28 = V_2 -> V_33 [ V_30 ] . V_28 ;
if ( ! V_28 || ! ( V_28 -> V_34 & V_35 ) )
continue;
V_31 ++ ;
V_29 &= ~ F_14 ( V_30 ) ;
V_29 |= F_16 ( V_30 ) ;
if ( V_28 -> V_36 . V_37 != V_2 -> V_33 [ V_30 ] . V_38 ) {
V_2 -> V_33 [ V_30 ] . V_38 = V_28 -> V_36 . V_37 ;
V_29 &= ~ F_14 ( V_30 ) ;
V_29 |= F_17 ( V_30 ) ;
}
if ( V_28 -> V_36 . V_39 != V_2 -> V_33 [ V_30 ] . V_40 ) {
V_2 -> V_33 [ V_30 ] . V_40 = V_28 -> V_36 . V_39 ;
V_29 &= ~ F_14 ( V_30 ) ;
V_29 |= F_17 ( V_30 ) ;
}
}
F_10 ( V_2 , 5 , V_29 ) ;
if ( V_31 )
F_18 ( & V_2 -> V_26 , V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_42 , T_1 V_43 )
{
T_1 V_29 = V_2 -> V_22 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_32 ; V_30 ++ )
if ( V_42 & F_20 ( V_30 ) ) {
V_29 &= ~ F_14 ( V_30 ) ;
V_29 |= F_21 ( V_43 , V_30 ) ;
}
F_10 ( V_2 , 5 , V_29 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_26 , V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( & V_2 -> V_26 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_10 ( V_2 , 1 , 44 / 1 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_10 ( V_2 , 2 , 0x80 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_10 ( V_2 , 3 , 44 / 5 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_10 ( V_2 , 4 , 0x80 ) ;
if ( V_44 )
return V_44 ;
return F_10 ( V_2 , 5 , V_45 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 5 , V_46 ) ;
}
static void F_27 ( const struct V_47 * V_48 ,
int V_49 , T_1 V_50 )
{
struct V_51 * V_52 = V_48 -> V_48 ;
struct V_1 * V_2 = V_52 -> V_53 ;
int V_54 = ( V_48 -> V_55 - V_2 -> V_55 ) / V_56 ;
if ( V_49 == V_57 )
switch ( V_50 ) {
case V_58 :
F_19 ( V_2 , F_20 ( V_54 ) , V_59 ) ;
break;
case 0x00 :
F_19 ( V_2 , F_20 ( V_54 ) , V_60 ) ;
F_22 ( V_2 ) ;
break;
default:
break;
}
F_28 ( V_48 , V_49 , V_50 ) ;
}
static int F_29 ( struct V_61 * V_62 , struct V_27 * V_63 )
{
struct V_47 * V_48 = F_30 ( V_63 ) ;
struct V_51 * V_52 = V_48 -> V_48 ;
struct V_1 * V_2 ;
int V_44 ;
if ( V_52 -> V_64 ) {
struct V_47 * V_65 = F_30 ( V_52 -> V_64 ) ;
struct V_51 * V_66 = V_65 -> V_48 ;
V_2 = V_66 -> V_53 ;
if ( ! V_2 )
return - V_67 ;
} else {
V_2 = F_31 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_4 = V_52 -> V_4 ;
V_2 -> V_55 = V_48 -> V_55 ;
V_2 -> V_23 . V_70 = V_71 ;
V_2 -> V_23 . V_63 . V_72 = & V_62 -> V_63 ;
V_2 -> V_23 . V_73 = & V_2 -> V_74 ;
strncpy ( V_2 -> V_23 . V_75 , L_1 ,
sizeof( V_2 -> V_23 . V_75 ) ) ;
V_2 -> V_74 = V_76 ;
V_2 -> V_74 . V_77 = 10 ;
V_2 -> V_74 . V_78 = V_41 ;
V_2 -> V_74 . V_8 = V_2 ;
F_5 ( V_2 ) ;
V_44 = F_32 ( & V_2 -> V_23 ) ;
if ( V_44 ) {
F_33 ( & V_62 -> V_63 , L_2 ) ;
goto V_79;
}
V_44 = F_25 ( V_2 ) ;
if ( V_44 ) {
F_33 ( & V_62 -> V_63 , L_3 ) ;
goto V_80;
}
F_34 ( & V_2 -> V_26 , F_12 ) ;
V_48 -> V_81 = F_27 ;
}
V_52 -> V_53 = V_2 ;
V_2 -> V_33 [ V_2 -> V_32 ++ ] . V_28 = V_63 ;
return 0 ;
V_80:
F_35 ( & V_2 -> V_23 ) ;
V_79:
F_5 ( V_2 ) ;
F_36 ( V_2 ) ;
return V_44 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_26 ( V_2 ) ;
F_35 ( & V_2 -> V_23 ) ;
F_5 ( V_2 ) ;
F_36 ( V_2 ) ;
}
static inline int F_29 ( struct V_61 * V_62 , struct V_27 * V_63 )
{
return - V_67 ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
}
static T_1 F_38 ( const struct V_47 * V_48 , int V_49 )
{
return F_2 ( V_48 -> V_55 + ( V_49 << 2 ) ) ;
}
static void F_28 ( const struct V_47 * V_48 ,
int V_49 , T_1 V_50 )
{
F_3 ( V_50 , V_48 -> V_55 + ( V_49 << 2 ) ) ;
}
static void F_39 ( const struct V_47 * V_48 )
{
struct V_51 * V_52 = V_48 -> V_48 ;
T_2 V_82 ;
V_82 = F_40 ( V_52 -> V_4 + V_83 ) ;
if ( V_82 & V_52 -> V_84 )
F_41 ( V_52 -> V_84 , V_52 -> V_4 + V_83 ) ;
}
static int F_42 ( struct V_61 * V_62 , const struct V_85 * V_86 )
{
struct V_47 * V_48 ;
struct V_51 * V_52 ;
struct V_27 * V_63 , * V_64 ;
void T_3 * V_4 , * V_55 ;
T_2 V_87 , V_82 ;
int V_30 , V_44 , V_88 ;
V_44 = F_43 ( V_62 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_44 ( V_62 , V_89 ) ;
if ( V_44 )
goto V_90;
V_44 = F_45 ( V_62 , 0x2e , & V_87 ) ;
if ( V_44 )
goto V_91;
F_46 ( & V_62 -> V_63 , L_4 ,
V_62 -> V_92 , V_62 -> V_93 , V_87 ) ;
V_44 = F_47 ( V_62 , 0x44 , 0 ) ;
if ( V_44 )
goto V_91;
if ( V_87 >= 12 )
V_88 = 4 ;
else if ( V_87 >= 10 )
V_88 = 3 ;
else if ( V_87 >= 4 )
V_88 = 2 ;
else
V_88 = 1 ;
V_4 = F_48 ( V_62 , 0 , V_94 ) ;
if ( ! V_4 ) {
F_33 ( & V_62 -> V_63 , L_5 ) ;
V_44 = - V_69 ;
goto V_91;
}
V_55 = F_48 ( V_62 , 1 , V_56 * V_88 ) ;
if ( ! V_55 ) {
F_33 ( & V_62 -> V_63 , L_6 ) ;
V_44 = - V_69 ;
goto V_95;
}
F_41 ( 0x0005 , V_4 + V_96 + 2 ) ;
F_3 ( 0x00 , V_4 + V_96 ) ;
F_3 ( 0x05 , V_4 + V_97 + 3 ) ;
F_49 ( 5 ) ;
F_3 ( 0x04 , V_4 + V_97 + 3 ) ;
V_82 = F_40 ( V_4 + V_83 + 2 ) ;
for ( V_30 = 0 ; V_30 < V_88 ; V_30 ++ ) {
V_63 = F_50 ( sizeof( struct V_51 ) ) ;
if ( ! V_63 ) {
V_44 = - V_69 ;
goto V_98;
}
V_48 = F_30 ( V_63 ) ;
V_52 = V_48 -> V_48 ;
V_52 -> V_4 = V_4 ;
V_48 -> V_55 = V_55 + V_30 * V_56 ;
V_48 -> V_99 = F_38 ;
V_48 -> V_81 = F_28 ;
V_48 -> V_100 = F_39 ;
V_48 -> V_101 . clock . V_102 = V_103 ;
V_48 -> V_104 = V_105 ;
V_48 -> V_106 = V_107 ;
if ( V_88 == 1 || V_30 > 0 )
V_48 -> V_106 |= V_108 ;
V_48 -> V_109 = V_110 ;
V_63 -> V_111 = V_62 -> V_111 ;
V_52 -> V_84 = V_112 [ V_30 ] ;
V_82 |= V_52 -> V_84 ;
F_51 ( V_63 , & V_62 -> V_63 ) ;
V_63 -> V_113 = V_30 ;
V_52 -> V_64 = F_52 ( V_62 ) ;
F_53 ( V_62 , V_63 ) ;
if ( V_62 -> V_93 == V_114 ||
V_62 -> V_93 == V_115 ) {
V_44 = F_29 ( V_62 , V_63 ) ;
if ( V_44 ) {
F_33 ( & V_62 -> V_63 ,
L_7 ,
V_44 ) ;
goto V_116;
}
}
V_44 = F_54 ( V_63 ) ;
if ( V_44 ) {
F_33 ( & V_62 -> V_63 , L_8 ) ;
goto V_116;
}
F_55 ( & V_62 -> V_63 ,
L_9 ,
V_63 -> V_75 , V_48 -> V_55 , V_52 -> V_4 , V_63 -> V_111 ) ;
}
F_41 ( V_82 , V_4 + V_83 + 2 ) ;
return 0 ;
V_116:
F_53 ( V_62 , V_52 -> V_64 ) ;
F_56 ( V_63 ) ;
V_98:
F_41 ( 0x0 , V_4 + V_83 + 2 ) ;
V_52 = NULL ;
for ( V_63 = F_52 ( V_62 ) ; V_63 ; V_63 = V_64 ) {
V_48 = F_30 ( V_63 ) ;
V_52 = V_48 -> V_48 ;
V_64 = V_52 -> V_64 ;
F_57 ( V_63 ) ;
F_56 ( V_63 ) ;
}
if ( V_52 && V_52 -> V_53 )
F_37 ( V_52 -> V_53 ) ;
F_58 ( V_62 , V_55 ) ;
V_95:
F_58 ( V_62 , V_4 ) ;
V_91:
F_59 ( V_62 ) ;
V_90:
F_60 ( V_62 ) ;
return V_44 ;
}
static void F_61 ( struct V_61 * V_62 )
{
struct V_27 * V_63 = F_52 ( V_62 ) ;
struct V_47 * V_48 = F_30 ( V_63 ) ;
struct V_51 * V_52 = V_48 -> V_48 ;
void T_3 * V_4 = V_52 -> V_4 ;
void T_3 * V_55 = V_48 -> V_55 ;
F_41 ( 0x0 , V_4 + V_83 + 2 ) ;
while ( 1 ) {
struct V_27 * V_64 = V_52 -> V_64 ;
F_55 ( & V_62 -> V_63 , L_10 , V_63 -> V_75 ) ;
F_57 ( V_63 ) ;
F_56 ( V_63 ) ;
V_63 = V_64 ;
if ( ! V_63 ) {
if ( V_52 -> V_53 )
F_37 ( V_52 -> V_53 ) ;
break;
}
V_48 = F_30 ( V_63 ) ;
V_52 = V_48 -> V_48 ;
}
F_58 ( V_62 , V_55 ) ;
F_58 ( V_62 , V_4 ) ;
F_59 ( V_62 ) ;
F_60 ( V_62 ) ;
}
