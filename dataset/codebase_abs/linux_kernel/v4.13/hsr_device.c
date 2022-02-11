static bool F_1 ( struct V_1 * V_2 )
{
return V_2 && ( V_2 -> V_3 & V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return V_2 && F_1 ( V_2 ) && F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_5 )
{
F_5 ( & V_6 ) ;
if ( V_2 -> V_7 != V_5 ) {
V_2 -> V_7 = V_5 ;
F_6 ( & V_6 ) ;
F_7 ( V_2 ) ;
} else {
F_6 ( & V_6 ) ;
}
}
static void F_8 ( struct V_8 * V_9 , bool V_10 )
{
if ( ! F_1 ( V_9 -> V_2 ) ) {
F_4 ( V_9 -> V_2 , V_11 ) ;
return;
}
if ( V_10 )
F_4 ( V_9 -> V_2 , V_12 ) ;
else
F_4 ( V_9 -> V_2 , V_13 ) ;
}
static bool F_9 ( struct V_8 * V_9 )
{
struct V_8 * V_14 ;
bool V_10 ;
V_10 = false ;
F_10 () ;
F_11 (master->hsr, port)
if ( ( V_14 -> type != V_15 ) && F_2 ( V_14 -> V_2 ) ) {
V_10 = true ;
break;
}
F_12 () ;
if ( V_10 )
F_13 ( V_9 -> V_2 ) ;
else
F_14 ( V_9 -> V_2 ) ;
return V_10 ;
}
static void F_15 ( struct V_1 * V_16 ,
unsigned char V_17 )
{
struct V_18 * V_19 ;
V_19 = F_16 ( V_16 ) ;
if ( ( V_16 -> V_7 == V_12 )
&& ( V_17 != V_12 ) ) {
V_19 -> V_20 = 0 ;
V_19 -> V_21 . V_22 = V_23 +
F_17 ( V_24 ) ;
F_18 ( & V_19 -> V_21 ) ;
}
if ( ( V_16 -> V_7 != V_12 ) && ( V_17 == V_12 ) )
F_19 ( & V_19 -> V_21 ) ;
}
void F_20 ( struct V_18 * V_19 )
{
struct V_8 * V_9 ;
unsigned char V_17 ;
bool V_10 ;
V_9 = F_21 ( V_19 , V_15 ) ;
V_17 = V_9 -> V_2 -> V_7 ;
V_10 = F_9 ( V_9 ) ;
F_8 ( V_9 , V_10 ) ;
F_15 ( V_9 -> V_2 , V_17 ) ;
}
int F_22 ( struct V_18 * V_19 )
{
unsigned int V_25 ;
struct V_8 * V_14 ;
V_25 = V_26 ;
F_10 () ;
F_11 (hsr, port)
if ( V_14 -> type != V_15 )
V_25 = F_23 ( V_14 -> V_2 -> V_27 , V_25 ) ;
F_12 () ;
if ( V_25 < V_28 )
return 0 ;
return V_25 - V_28 ;
}
static int F_24 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 ;
struct V_8 * V_9 ;
V_19 = F_16 ( V_2 ) ;
V_9 = F_21 ( V_19 , V_15 ) ;
if ( V_29 > F_22 ( V_19 ) ) {
F_25 ( V_9 -> V_2 , L_1 ,
V_28 ) ;
return - V_30 ;
}
V_2 -> V_27 = V_29 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_8 * V_14 ;
char V_31 ;
V_19 = F_16 ( V_2 ) ;
V_31 = '\0' ;
F_10 () ;
F_11 (hsr, port) {
if ( V_14 -> type == V_15 )
continue;
switch ( V_14 -> type ) {
case V_32 :
V_31 = 'A' ;
break;
case V_33 :
V_31 = 'B' ;
break;
default:
V_31 = '?' ;
}
if ( ! F_2 ( V_14 -> V_2 ) )
F_27 ( V_2 , L_2 ,
V_31 , V_14 -> V_2 -> V_34 ) ;
}
F_12 () ;
if ( V_31 == '\0' )
F_27 ( V_2 , L_3 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
return 0 ;
}
static T_1 F_29 ( struct V_18 * V_19 ,
T_1 V_35 )
{
T_1 V_36 ;
struct V_8 * V_14 ;
V_36 = V_35 ;
V_35 &= ~ V_37 ;
F_11 (hsr, port)
V_35 = F_30 ( V_35 ,
V_14 -> V_2 -> V_35 ,
V_36 ) ;
return V_35 ;
}
static T_1 F_31 ( struct V_1 * V_2 ,
T_1 V_35 )
{
struct V_18 * V_19 = F_16 ( V_2 ) ;
return F_29 ( V_19 , V_35 ) ;
}
static int F_32 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_16 ( V_2 ) ;
struct V_8 * V_9 ;
V_9 = F_21 ( V_19 , V_15 ) ;
V_39 -> V_2 = V_9 -> V_2 ;
F_33 ( V_39 , V_9 ) ;
return V_40 ;
}
static void F_34 ( struct V_8 * V_9 ,
T_2 type , T_2 V_41 )
{
struct V_38 * V_39 ;
int V_42 , V_43 ;
struct V_44 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
V_42 = F_35 ( V_9 -> V_2 ) ;
V_43 = V_9 -> V_2 -> V_50 ;
V_39 = F_36 (
sizeof( struct V_44 ) +
sizeof( struct V_45 ) +
sizeof( struct V_47 ) + V_42 + V_43 ) ;
if ( V_39 == NULL )
return;
F_37 ( V_39 , V_42 ) ;
V_39 -> V_2 = V_9 -> V_2 ;
V_39 -> V_51 = F_38 ( V_41 ? V_52 : V_53 ) ;
V_39 -> V_54 = V_55 ;
if ( F_39 ( V_39 , V_39 -> V_2 , ( V_41 ? V_52 : V_53 ) ,
V_9 -> V_19 -> V_56 ,
V_39 -> V_2 -> V_57 , V_39 -> V_58 ) <= 0 )
goto V_59;
F_40 ( V_39 ) ;
if ( V_41 > 0 ) {
V_44 = F_41 ( V_39 , sizeof( struct V_44 ) ) ;
V_44 -> V_60 = F_38 ( V_53 ) ;
F_42 ( V_44 , V_61 ) ;
}
V_46 = F_41 ( V_39 , sizeof( struct V_45 ) ) ;
F_43 ( V_46 , ( V_41 ? 0x0 : 0xf ) ) ;
F_44 ( V_46 , V_41 ) ;
F_45 ( & V_9 -> V_19 -> V_62 , V_49 ) ;
if ( V_41 > 0 ) {
V_46 -> V_63 = F_38 ( V_9 -> V_19 -> V_64 ) ;
V_44 -> V_63 = F_38 ( V_9 -> V_19 -> V_63 ) ;
V_9 -> V_19 -> V_64 ++ ;
V_9 -> V_19 -> V_63 ++ ;
} else {
V_46 -> V_63 = F_38 ( V_9 -> V_19 -> V_63 ) ;
V_9 -> V_19 -> V_63 ++ ;
}
F_46 ( & V_9 -> V_19 -> V_62 , V_49 ) ;
V_46 -> V_65 = type ;
V_46 -> V_66 = V_41 ? sizeof( struct V_47 ) : 12 ;
V_48 = F_41 ( V_39 , sizeof( struct V_47 ) ) ;
F_47 ( V_48 -> V_67 , V_9 -> V_2 -> V_57 ) ;
if ( F_48 ( V_39 , V_68 + V_28 ) )
return;
F_33 ( V_39 , V_9 ) ;
return;
V_59:
F_49 ( 1 , L_4 ) ;
F_50 ( V_39 ) ;
}
static void F_51 ( unsigned long V_69 )
{
struct V_18 * V_19 ;
struct V_8 * V_9 ;
V_19 = (struct V_18 * ) V_69 ;
F_10 () ;
V_9 = F_21 ( V_19 , V_15 ) ;
if ( V_19 -> V_20 < 3 && V_19 -> V_70 == 0 ) {
F_34 ( V_9 , V_71 ,
V_19 -> V_70 ) ;
V_19 -> V_20 ++ ;
V_19 -> V_21 . V_22 = V_23 +
F_17 ( V_24 ) ;
} else {
F_34 ( V_9 , V_72 ,
V_19 -> V_70 ) ;
V_19 -> V_21 . V_22 = V_23 +
F_17 ( V_73 ) ;
}
if ( F_1 ( V_9 -> V_2 ) )
F_18 ( & V_19 -> V_21 ) ;
F_12 () ;
}
static void F_52 ( struct V_1 * V_16 )
{
struct V_18 * V_19 ;
struct V_8 * V_14 ;
V_19 = F_16 ( V_16 ) ;
F_53 () ;
F_11 (hsr, port)
F_54 ( V_14 ) ;
F_55 () ;
F_56 ( & V_19 -> V_74 ) ;
F_56 ( & V_19 -> V_21 ) ;
F_57 () ;
}
void F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_60 ( V_2 ) ;
V_2 -> V_75 = 0 ;
V_2 -> V_76 = & V_77 ;
V_2 -> V_78 = & V_79 ;
F_61 ( V_2 , & V_80 ) ;
V_2 -> V_81 |= V_82 ;
V_2 -> V_83 = true ;
V_2 -> V_84 = F_52 ;
V_2 -> V_85 = V_86 | V_87 | V_88 |
V_89 | V_90 |
V_91 ;
V_2 -> V_35 = V_2 -> V_85 ;
V_2 -> V_35 |= V_92 ;
V_2 -> V_35 |= V_93 ;
V_2 -> V_35 |= V_94 ;
}
inline bool F_62 ( struct V_1 * V_2 )
{
return ( V_2 -> V_78 -> V_95 == F_32 ) ;
}
int F_63 ( struct V_1 * V_16 , struct V_1 * V_96 [ 2 ] ,
unsigned char V_97 , T_2 V_98 )
{
struct V_18 * V_19 ;
struct V_8 * V_14 ;
int V_99 ;
V_19 = F_16 ( V_16 ) ;
F_64 ( & V_19 -> V_100 ) ;
F_64 ( & V_19 -> V_101 ) ;
F_64 ( & V_19 -> V_102 ) ;
F_47 ( V_16 -> V_57 , V_96 [ 0 ] -> V_57 ) ;
V_99 = F_65 ( & V_19 -> V_102 , V_16 -> V_57 ,
V_96 [ 1 ] -> V_57 ) ;
if ( V_99 < 0 )
return V_99 ;
F_66 ( & V_19 -> V_62 ) ;
V_19 -> V_63 = V_103 ;
V_19 -> V_64 = V_104 ;
F_67 ( & V_19 -> V_21 , F_51 , ( unsigned long ) V_19 ) ;
F_67 ( & V_19 -> V_74 , V_105 , ( unsigned long ) V_19 ) ;
F_47 ( V_19 -> V_56 , V_106 ) ;
V_19 -> V_56 [ V_107 - 1 ] = V_97 ;
V_19 -> V_70 = V_98 ;
F_14 ( V_16 ) ;
V_99 = F_68 ( V_19 , V_16 , V_15 ) ;
if ( V_99 )
return V_99 ;
V_99 = F_69 ( V_16 ) ;
if ( V_99 )
goto V_108;
V_99 = F_68 ( V_19 , V_96 [ 0 ] , V_32 ) ;
if ( V_99 )
goto V_108;
V_99 = F_68 ( V_19 , V_96 [ 1 ] , V_33 ) ;
if ( V_99 )
goto V_108;
F_70 ( & V_19 -> V_74 , V_23 + F_17 ( V_109 ) ) ;
return 0 ;
V_108:
F_11 (hsr, port)
F_54 ( V_14 ) ;
return V_99 ;
}
