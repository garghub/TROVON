static void F_1 ( T_1 V_1 , void T_2 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
static unsigned int F_3 ( void T_2 * V_2 )
{
return F_4 ( V_2 ) ;
}
static void F_5 ( T_1 V_1 , void T_2 * V_2 )
{
F_6 ( V_1 , V_2 ) ;
}
static unsigned int F_7 ( void T_2 * V_2 )
{
return F_8 ( V_2 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( * V_4 -> V_6 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 ++ ;
}
static void F_10 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( * ( V_9 * ) ( V_4 -> V_6 ) , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 += 2 ;
}
static void F_11 ( struct V_3 * V_4 )
{
V_4 -> V_5 ( * ( T_1 * ) ( V_4 -> V_6 ) , V_4 -> V_7 + V_8 ) ;
V_4 -> V_6 += 4 ;
}
static void F_12 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* V_4 -> V_13 = V_10 & 0xff ;
V_4 -> V_13 ++ ;
}
}
static void F_13 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* ( V_9 * ) ( V_4 -> V_13 ) = V_10 & 0xffff ;
V_4 -> V_13 += 2 ;
}
}
static void F_14 ( struct V_3 * V_4 )
{
T_1 V_10 = V_4 -> V_11 ( V_4 -> V_7 + V_12 ) ;
if ( V_4 -> V_13 ) {
* ( T_1 * ) ( V_4 -> V_13 ) = V_10 ;
V_4 -> V_13 += 4 ;
}
}
static void F_15 ( struct V_3 * V_4 )
{
void T_2 * V_14 = V_4 -> V_7 ;
V_4 -> V_5 ( V_15 ,
V_14 + V_16 ) ;
V_4 -> V_5 ( 0 , V_14 + V_17 ) ;
V_4 -> V_5 ( V_18 ,
V_14 + V_19 ) ;
V_4 -> V_5 ( 0xffff , V_14 + V_20 ) ;
V_4 -> V_5 ( V_21 | V_22 |
V_23 | V_24 | V_25 |
V_26 , V_14 + V_27 ) ;
}
static void F_16 ( struct V_28 * V_29 , int V_30 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
if ( V_30 == V_32 ) {
V_4 -> V_5 ( 0xffff , V_4 -> V_7 + V_20 ) ;
} else if ( V_30 == V_33 ) {
V_9 V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 )
& ~ V_35 ;
if ( V_29 -> V_36 & V_37 )
V_34 |= V_38 ;
if ( V_29 -> V_36 & V_39 )
V_34 |= V_40 ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
V_4 -> V_5 ( ~ ( 0x0001 << V_29 -> V_41 ) ,
V_4 -> V_7 + V_20 ) ;
}
}
static int F_18 ( struct V_28 * V_29 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
T_3 V_44 ;
V_44 = ( V_43 && V_43 -> V_44 )
? V_43 -> V_44 : V_29 -> V_44 ;
if ( V_44 != V_4 -> V_44 ) {
F_19 ( & V_29 -> V_45 , L_1 ,
V_46 , V_44 ) ;
return - V_47 ;
}
return 0 ;
}
static int F_20 ( struct V_28 * V_29 )
{
return 0 ;
}
static void F_21 ( struct V_3 * V_4 )
{
T_3 V_48 ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
while ( ( V_48 & V_50 ) == 0 && V_4 -> V_51 > 0 ) {
if ( V_4 -> V_6 )
V_4 -> V_52 ( V_4 ) ;
else
V_4 -> V_5 ( 0 , V_4 -> V_7 + V_8 ) ;
V_4 -> V_51 -= V_4 -> V_44 / 8 ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
}
}
static int F_22 ( struct V_28 * V_29 , struct V_42 * V_43 )
{
struct V_3 * V_4 = F_17 ( V_29 -> V_31 ) ;
T_1 V_53 ;
V_9 V_34 ;
V_4 -> V_6 = V_43 -> V_54 ;
V_4 -> V_13 = V_43 -> V_55 ;
V_4 -> V_51 = V_43 -> V_56 ;
F_23 ( V_4 -> V_57 ) ;
F_21 ( V_4 ) ;
V_53 = V_4 -> V_11 ( V_4 -> V_7 + V_17 ) ;
V_4 -> V_5 ( V_53 | V_58 ,
V_4 -> V_7 + V_17 ) ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) &
~ V_21 ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
F_24 ( & V_4 -> V_57 ) ;
V_4 -> V_5 ( V_53 , V_4 -> V_7 + V_17 ) ;
return V_43 -> V_56 - V_4 -> V_51 ;
}
static T_4 F_25 ( int V_59 , void * V_60 )
{
struct V_3 * V_4 = V_60 ;
T_1 V_61 ;
V_61 = V_4 -> V_11 ( V_4 -> V_7 + V_62 ) ;
V_4 -> V_5 ( V_61 , V_4 -> V_7 + V_62 ) ;
if ( V_61 & V_58 ) {
V_9 V_34 ;
T_3 V_48 ;
V_34 = V_4 -> V_11 ( V_4 -> V_7 + V_27 ) ;
V_4 -> V_5 ( V_34 | V_21 ,
V_4 -> V_7 + V_27 ) ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
while ( ( V_48 & V_63 ) == 0 ) {
V_4 -> V_64 ( V_4 ) ;
V_48 = V_4 -> V_11 ( V_4 -> V_7 + V_49 ) ;
}
if ( V_4 -> V_51 > 0 ) {
F_21 ( V_4 ) ;
V_4 -> V_5 ( V_34 , V_4 -> V_7 + V_27 ) ;
} else {
F_26 ( & V_4 -> V_57 ) ;
}
}
return V_65 ;
}
struct V_66 * F_27 ( struct V_67 * V_45 , struct V_68 * V_69 ,
T_1 V_59 , T_5 V_70 , int V_71 , int V_72 , int V_44 )
{
struct V_66 * V_31 ;
struct V_3 * V_4 ;
int V_73 ;
V_31 = F_28 ( V_45 , sizeof( struct V_3 ) ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_74 = V_39 | V_37 ;
V_4 = F_17 ( V_31 ) ;
V_4 -> V_75 . V_31 = F_29 ( V_31 ) ;
V_4 -> V_75 . V_76 = F_16 ;
V_4 -> V_75 . V_77 = F_18 ;
V_4 -> V_75 . V_78 = F_22 ;
V_4 -> V_75 . V_31 -> V_79 = F_20 ;
F_30 ( & V_4 -> V_57 ) ;
if ( ! F_31 ( V_69 -> V_80 , F_32 ( V_69 ) ,
V_81 ) )
goto V_82;
V_4 -> V_7 = F_33 ( V_69 -> V_80 , F_32 ( V_69 ) ) ;
if ( V_4 -> V_7 == NULL ) {
F_34 ( V_45 , L_2 ) ;
goto V_83;
}
V_31 -> V_70 = V_70 ;
V_31 -> V_84 = V_71 ;
V_31 -> V_45 . V_85 = V_45 -> V_85 ;
V_4 -> V_69 = * V_69 ;
V_4 -> V_59 = V_59 ;
if ( V_72 ) {
V_4 -> V_11 = F_3 ;
V_4 -> V_5 = F_1 ;
} else {
V_4 -> V_11 = F_7 ;
V_4 -> V_5 = F_5 ;
}
V_4 -> V_44 = V_44 ;
if ( V_4 -> V_44 == 8 ) {
V_4 -> V_52 = F_9 ;
V_4 -> V_64 = F_12 ;
} else if ( V_4 -> V_44 == 16 ) {
V_4 -> V_52 = F_10 ;
V_4 -> V_64 = F_13 ;
} else if ( V_4 -> V_44 == 32 ) {
V_4 -> V_52 = F_11 ;
V_4 -> V_64 = F_14 ;
} else
goto V_86;
F_15 ( V_4 ) ;
V_73 = F_35 ( V_4 -> V_59 , F_25 , 0 , V_81 , V_4 ) ;
if ( V_73 )
goto V_86;
V_73 = F_36 ( & V_4 -> V_75 ) ;
if ( V_73 ) {
F_19 ( V_45 , L_3 ) ;
goto V_87;
}
F_37 ( V_45 , L_4 ,
( unsigned long long ) V_69 -> V_80 , V_4 -> V_7 , V_4 -> V_59 ) ;
return V_31 ;
V_87:
V_87 ( V_4 -> V_59 , V_4 ) ;
V_86:
F_38 ( V_4 -> V_7 ) ;
V_83:
F_39 ( V_69 -> V_80 , F_32 ( V_69 ) ) ;
V_82:
F_40 ( V_31 ) ;
return NULL ;
}
void F_41 ( struct V_66 * V_31 )
{
struct V_3 * V_4 ;
V_4 = F_17 ( V_31 ) ;
F_42 ( & V_4 -> V_75 ) ;
V_87 ( V_4 -> V_59 , V_4 ) ;
F_38 ( V_4 -> V_7 ) ;
F_39 ( V_4 -> V_69 . V_80 , F_32 ( & V_4 -> V_69 ) ) ;
F_40 ( V_4 -> V_75 . V_31 ) ;
}
static int T_6 F_43 ( struct V_88 * V_45 )
{
struct V_89 * V_90 ;
struct V_68 * V_91 ;
int V_59 , V_71 = 0 , V_72 = 0 , V_44 = 8 ;
struct V_66 * V_31 ;
T_3 V_92 ;
V_90 = V_45 -> V_45 . V_93 ;
if ( V_90 ) {
V_71 = V_90 -> V_84 ;
V_72 = V_90 -> V_72 ;
V_44 = V_90 -> V_44 ;
}
#ifdef F_44
if ( V_45 -> V_45 . V_85 ) {
const T_7 * V_94 ;
int V_56 ;
V_94 = F_45 ( V_45 -> V_45 . V_85 , L_5 ,
& V_56 ) ;
if ( V_94 && V_56 >= sizeof( * V_94 ) )
V_71 = F_46 ( V_94 ) ;
}
#endif
if ( ! V_71 ) {
F_19 ( & V_45 -> V_45 , L_6 ) ;
return - V_47 ;
}
V_91 = F_47 ( V_45 , V_95 , 0 ) ;
if ( ! V_91 )
return - V_96 ;
V_59 = F_48 ( V_45 , 0 ) ;
if ( V_59 < 0 )
return - V_97 ;
V_31 = F_27 ( & V_45 -> V_45 , V_91 , V_59 , V_45 -> V_98 , V_71 ,
V_72 , V_44 ) ;
if ( ! V_31 )
return - V_96 ;
if ( V_90 ) {
for ( V_92 = 0 ; V_92 < V_90 -> V_99 ; V_92 ++ )
F_49 ( V_31 , V_90 -> V_100 + V_92 ) ;
}
F_50 ( V_45 , V_31 ) ;
return 0 ;
}
static int T_8 F_51 ( struct V_88 * V_45 )
{
F_41 ( F_52 ( V_45 ) ) ;
F_50 ( V_45 , 0 ) ;
return 0 ;
}
static int T_9 F_53 ( void )
{
return F_54 ( & V_101 ) ;
}
static void T_10 F_55 ( void )
{
F_56 ( & V_101 ) ;
}
