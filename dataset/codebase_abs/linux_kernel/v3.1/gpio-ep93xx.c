static void F_1 ( unsigned V_1 )
{
F_2 ( V_1 > 2 ) ;
F_3 ( 0 , F_4 ( V_2 [ V_1 ] ) ) ;
F_3 ( V_3 [ V_1 ] ,
F_4 ( V_4 [ V_1 ] ) ) ;
F_3 ( V_5 [ V_1 ] ,
F_4 ( V_6 [ V_1 ] ) ) ;
F_3 ( V_7 [ V_1 ] & V_8 [ V_1 ] ,
F_4 ( V_2 [ V_1 ] ) ) ;
}
static inline void F_5 ( unsigned line )
{
V_7 [ line >> 3 ] &= ~ ( 1 << ( line & 7 ) ) ;
}
static void F_6 ( unsigned int V_9 , bool V_10 )
{
int line = F_7 ( V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( V_10 )
V_12 [ V_1 ] |= V_11 ;
else
V_12 [ V_1 ] &= ~ V_11 ;
F_3 ( V_12 [ V_1 ] ,
F_4 ( V_13 [ V_1 ] ) ) ;
}
static void F_8 ( unsigned int V_9 , struct V_14 * V_15 )
{
unsigned char V_16 ;
int V_17 ;
V_16 = F_9 ( V_18 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_10 ( F_11 ( 0 ) ) + V_17 ;
F_12 ( V_19 ) ;
}
}
V_16 = F_9 ( V_20 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_10 ( F_13 ( 0 ) ) + V_17 ;
F_12 ( V_19 ) ;
}
}
}
static void F_14 ( unsigned int V_9 , struct V_14 * V_15 )
{
int V_21 = ( ( V_9 + 1 ) & 7 ) ^ 4 ;
int V_19 = F_10 ( F_15 ( 0 ) ) + V_21 ;
F_12 ( V_19 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_17 ( V_23 ) == V_24 ) {
V_3 [ V_1 ] ^= V_11 ;
F_1 ( V_1 ) ;
}
F_3 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_18 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_17 ( V_23 ) == V_24 )
V_3 [ V_1 ] ^= V_11 ;
V_7 [ V_1 ] &= ~ V_11 ;
F_1 ( V_1 ) ;
F_3 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] &= ~ ( 1 << ( line & 7 ) ) ;
F_1 ( V_1 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
int line = F_7 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] |= 1 << ( line & 7 ) ;
F_1 ( V_1 ) ;
}
static int F_21 ( struct V_22 * V_23 , unsigned int type )
{
const int V_26 = F_7 ( V_23 -> V_9 ) ;
const int V_1 = V_26 >> 3 ;
const int V_11 = 1 << ( V_26 & 7 ) ;
T_1 V_27 ;
F_22 ( V_26 ) ;
switch ( type ) {
case V_28 :
V_5 [ V_1 ] |= V_11 ;
V_3 [ V_1 ] |= V_11 ;
V_27 = V_29 ;
break;
case V_30 :
V_5 [ V_1 ] |= V_11 ;
V_3 [ V_1 ] &= ~ V_11 ;
V_27 = V_29 ;
break;
case V_31 :
V_5 [ V_1 ] &= ~ V_11 ;
V_3 [ V_1 ] |= V_11 ;
V_27 = V_32 ;
break;
case V_33 :
V_5 [ V_1 ] &= ~ V_11 ;
V_3 [ V_1 ] &= ~ V_11 ;
V_27 = V_32 ;
break;
case V_24 :
V_5 [ V_1 ] |= V_11 ;
if ( F_23 ( V_26 ) )
V_3 [ V_1 ] &= ~ V_11 ;
else
V_3 [ V_1 ] |= V_11 ;
V_27 = V_29 ;
break;
default:
F_24 ( L_1 , type , V_26 ) ;
return - V_34 ;
}
F_25 ( V_23 -> V_9 , V_27 ) ;
V_8 [ V_1 ] |= V_11 ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_26 ( void )
{
int V_19 ;
for ( V_19 = F_10 ( 0 ) ;
V_19 <= F_10 ( V_35 ) ; ++ V_19 ) {
F_27 ( V_19 , & V_36 ,
V_32 ) ;
F_28 ( V_19 , V_37 ) ;
}
F_29 ( V_38 ,
F_8 ) ;
F_29 ( V_39 ,
F_14 ) ;
F_29 ( V_40 ,
F_14 ) ;
F_29 ( V_41 ,
F_14 ) ;
F_29 ( V_42 ,
F_14 ) ;
F_29 ( V_43 ,
F_14 ) ;
F_29 ( V_44 ,
F_14 ) ;
F_29 ( V_45 ,
F_14 ) ;
F_29 ( V_46 ,
F_14 ) ;
}
static int F_30 ( struct V_47 * V_48 ,
unsigned V_49 , unsigned V_50 )
{
int V_26 = V_48 -> V_51 + V_49 ;
int V_9 = F_10 ( V_26 ) ;
if ( V_9 < 0 )
return - V_34 ;
F_6 ( V_9 , V_50 ? true : false ) ;
return 0 ;
}
static int F_31 ( struct V_52 * V_53 , struct V_54 * V_55 ,
void T_2 * V_56 , struct V_57 * V_58 )
{
void T_2 * V_59 = V_56 + V_58 -> V_59 ;
void T_2 * V_60 = V_56 + V_58 -> V_60 ;
int V_61 ;
V_61 = F_32 ( V_53 , V_55 , 1 , V_59 , NULL , NULL , V_60 , NULL , false ) ;
if ( V_61 )
return V_61 ;
V_53 -> V_62 . V_63 = V_58 -> V_63 ;
V_53 -> V_62 . V_51 = V_58 -> V_51 ;
if ( V_58 -> V_64 )
V_53 -> V_62 . V_65 = F_30 ;
return F_33 ( & V_53 -> V_62 ) ;
}
static int T_3 F_34 ( struct V_66 * V_67 )
{
struct V_68 * V_68 ;
struct V_69 * V_70 ;
void T_2 * V_71 ;
int V_17 ;
int V_72 ;
V_68 = F_35 ( sizeof( * V_68 ) , V_73 ) ;
if ( ! V_68 )
return - V_74 ;
V_70 = F_36 ( V_67 , V_75 , 0 ) ;
if ( ! V_70 ) {
V_72 = - V_76 ;
goto V_77;
}
if ( ! F_37 ( V_70 -> V_78 , F_38 ( V_70 ) , V_67 -> V_79 ) ) {
V_72 = - V_80 ;
goto V_77;
}
V_71 = F_39 ( V_70 -> V_78 , F_38 ( V_70 ) ) ;
if ( ! V_71 ) {
V_72 = - V_76 ;
goto V_81;
}
V_68 -> V_56 = V_71 ;
F_40 ( V_82 |
V_83 |
V_84 |
V_85 |
V_86 ) ;
for ( V_17 = 0 ; V_17 < F_41 ( V_87 ) ; V_17 ++ ) {
struct V_52 * V_53 = & V_68 -> V_53 [ V_17 ] ;
struct V_57 * V_58 = & V_87 [ V_17 ] ;
if ( F_31 ( V_53 , & V_67 -> V_55 , V_71 , V_58 ) )
F_42 ( & V_67 -> V_55 , L_2 ,
V_58 -> V_63 ) ;
}
F_26 () ;
return 0 ;
V_81:
F_43 ( V_70 -> V_78 , F_38 ( V_70 ) ) ;
V_77:
F_44 ( V_68 ) ;
F_45 ( & V_67 -> V_55 , L_3 , V_88 , V_72 ) ;
return V_72 ;
}
static int T_4 F_46 ( void )
{
return F_47 ( & V_89 ) ;
}
