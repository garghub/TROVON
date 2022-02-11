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
static void F_5 ( unsigned int V_9 , bool V_10 )
{
int line = F_6 ( V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( V_10 )
V_12 [ V_1 ] |= V_11 ;
else
V_12 [ V_1 ] &= ~ V_11 ;
F_3 ( V_12 [ V_1 ] ,
F_4 ( V_13 [ V_1 ] ) ) ;
}
static void F_7 ( unsigned int V_9 , struct V_14 * V_15 )
{
unsigned char V_16 ;
int V_17 ;
V_16 = F_8 ( V_18 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_9 ( F_10 ( 0 ) ) + V_17 ;
F_11 ( V_19 ) ;
}
}
V_16 = F_8 ( V_20 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_16 & ( 1 << V_17 ) ) {
int V_19 = F_9 ( F_12 ( 0 ) ) + V_17 ;
F_11 ( V_19 ) ;
}
}
}
static void F_13 ( unsigned int V_9 , struct V_14 * V_15 )
{
int V_21 = ( ( V_9 + 1 ) & 7 ) ^ 4 ;
int V_19 = F_9 ( F_14 ( 0 ) ) + V_21 ;
F_11 ( V_19 ) ;
}
static void F_15 ( struct V_22 * V_23 )
{
int line = F_6 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_16 ( V_23 ) == V_24 ) {
V_3 [ V_1 ] ^= V_11 ;
F_1 ( V_1 ) ;
}
F_3 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_17 ( struct V_22 * V_23 )
{
int line = F_6 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
int V_11 = 1 << ( line & 7 ) ;
if ( F_16 ( V_23 ) == V_24 )
V_3 [ V_1 ] ^= V_11 ;
V_7 [ V_1 ] &= ~ V_11 ;
F_1 ( V_1 ) ;
F_3 ( V_11 , F_4 ( V_25 [ V_1 ] ) ) ;
}
static void F_18 ( struct V_22 * V_23 )
{
int line = F_6 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] &= ~ ( 1 << ( line & 7 ) ) ;
F_1 ( V_1 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
int line = F_6 ( V_23 -> V_9 ) ;
int V_1 = line >> 3 ;
V_7 [ V_1 ] |= 1 << ( line & 7 ) ;
F_1 ( V_1 ) ;
}
static int F_20 ( struct V_22 * V_23 , unsigned int type )
{
const int V_26 = F_6 ( V_23 -> V_9 ) ;
const int V_1 = V_26 >> 3 ;
const int V_11 = 1 << ( V_26 & 7 ) ;
T_1 V_27 ;
F_21 ( V_26 ) ;
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
if ( F_22 ( V_26 ) )
V_3 [ V_1 ] &= ~ V_11 ;
else
V_3 [ V_1 ] |= V_11 ;
V_27 = V_29 ;
break;
default:
return - V_34 ;
}
F_23 ( V_23 -> V_9 , V_27 ) ;
V_8 [ V_1 ] |= V_11 ;
F_1 ( V_1 ) ;
return 0 ;
}
static void F_24 ( void )
{
int V_19 ;
for ( V_19 = F_9 ( 0 ) ;
V_19 <= F_9 ( V_35 ) ; ++ V_19 ) {
F_25 ( V_19 , & V_36 ,
V_32 ) ;
F_26 ( V_19 , V_37 ) ;
}
F_27 ( V_38 ,
F_7 ) ;
F_27 ( V_39 ,
F_13 ) ;
F_27 ( V_40 ,
F_13 ) ;
F_27 ( V_41 ,
F_13 ) ;
F_27 ( V_42 ,
F_13 ) ;
F_27 ( V_43 ,
F_13 ) ;
F_27 ( V_44 ,
F_13 ) ;
F_27 ( V_45 ,
F_13 ) ;
F_27 ( V_46 ,
F_13 ) ;
}
static int F_28 ( struct V_47 * V_48 ,
unsigned V_49 , unsigned V_50 )
{
int V_26 = V_48 -> V_51 + V_49 ;
int V_9 = F_9 ( V_26 ) ;
if ( V_9 < 0 )
return - V_34 ;
F_5 ( V_9 , V_50 ? true : false ) ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 , unsigned V_49 )
{
int V_26 = V_48 -> V_51 + V_49 ;
if ( V_26 > V_35 )
return - V_34 ;
return 64 + V_26 ;
}
static int F_30 ( struct V_52 * V_53 , struct V_54 * V_55 ,
void T_2 * V_56 , struct V_57 * V_58 )
{
void T_2 * V_59 = V_56 + V_58 -> V_59 ;
void T_2 * V_60 = V_56 + V_58 -> V_60 ;
int V_61 ;
V_61 = F_31 ( V_53 , V_55 , 1 , V_59 , NULL , NULL , V_60 , NULL , 0 ) ;
if ( V_61 )
return V_61 ;
V_53 -> V_62 . V_63 = V_58 -> V_63 ;
V_53 -> V_62 . V_51 = V_58 -> V_51 ;
if ( V_58 -> V_64 ) {
V_53 -> V_62 . V_65 = F_28 ;
V_53 -> V_62 . V_66 = F_29 ;
}
return F_32 ( & V_53 -> V_62 ) ;
}
static int T_3 F_33 ( struct V_67 * V_68 )
{
struct V_69 * V_69 ;
struct V_70 * V_71 ;
void T_2 * V_72 ;
int V_17 ;
int V_73 ;
V_69 = F_34 ( sizeof( * V_69 ) , V_74 ) ;
if ( ! V_69 )
return - V_75 ;
V_71 = F_35 ( V_68 , V_76 , 0 ) ;
if ( ! V_71 ) {
V_73 = - V_77 ;
goto V_78;
}
if ( ! F_36 ( V_71 -> V_79 , F_37 ( V_71 ) , V_68 -> V_80 ) ) {
V_73 = - V_81 ;
goto V_78;
}
V_72 = F_38 ( V_71 -> V_79 , F_37 ( V_71 ) ) ;
if ( ! V_72 ) {
V_73 = - V_77 ;
goto V_82;
}
V_69 -> V_56 = V_72 ;
for ( V_17 = 0 ; V_17 < F_39 ( V_83 ) ; V_17 ++ ) {
struct V_52 * V_53 = & V_69 -> V_53 [ V_17 ] ;
struct V_57 * V_58 = & V_83 [ V_17 ] ;
if ( F_30 ( V_53 , & V_68 -> V_55 , V_72 , V_58 ) )
F_40 ( & V_68 -> V_55 , L_1 ,
V_58 -> V_63 ) ;
}
F_24 () ;
return 0 ;
V_82:
F_41 ( V_71 -> V_79 , F_37 ( V_71 ) ) ;
V_78:
F_42 ( V_69 ) ;
F_43 ( & V_68 -> V_55 , L_2 , V_84 , V_73 ) ;
return V_73 ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_85 ) ;
}
