static T_1 F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( & V_2 -> V_3 -> V_4 ) >> 8 ) & 3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
T_2 V_6 ;
F_4 ( V_2 -> V_7 . V_8 [ V_9 ] . V_6 ) ;
F_5 ( & V_2 -> V_10 . V_11 , V_5 ) ;
V_6 = ~ V_2 -> V_10 . V_12 & ( ( 1ul << ( 1 << V_2 -> V_10 . V_13 ) ) - 1 ) ;
if ( ! V_6 )
goto V_14;
V_6 |= V_15 ;
F_6 ( & V_2 -> V_10 . V_11 , V_5 ) ;
F_7 ( V_2 , L_1 , V_6 ) ;
F_8 ( V_2 , V_6 , true ) ;
return;
V_14:
F_6 ( & V_2 -> V_10 . V_11 , V_5 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
struct V_18 T_3 * V_19 = V_17 -> V_17 ;
if ( F_1 ( V_2 ) == V_20 )
return 1 ;
if ( F_2 ( & V_19 -> V_21 ) == 0xffffffff )
return 1 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , bool V_22 )
{
F_11 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 == V_25 )
goto V_26;
F_12 ( V_2 , L_2 ) ;
if ( F_13 ( V_2 -> V_27 ) || F_9 ( V_2 ) || V_22 ) {
V_2 -> V_24 = V_25 ;
F_3 ( V_2 ) ;
}
F_14 ( V_2 , V_28 , 0 ) ;
F_12 ( V_2 , L_3 ) ;
V_26:
F_15 ( & V_2 -> V_23 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_29 = F_1 ( V_2 ) ;
switch ( V_29 ) {
case V_30 :
F_17 ( V_2 , L_4 ) ;
break;
case V_20 :
F_17 ( V_2 , L_5 ) ;
break;
case V_31 :
F_17 ( V_2 , L_6 ) ;
break;
default:
F_17 ( V_2 , L_7 ,
V_29 ) ;
}
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_32 * V_33 )
{
struct V_16 * V_17 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
struct V_36 * V_7 ;
T_1 V_37 ;
V_35 = F_20 ( V_33 , struct V_34 , V_33 ) ;
V_17 = F_20 ( V_35 , struct V_16 , V_38 ) ;
V_7 = F_20 ( V_17 , struct V_36 , V_17 ) ;
V_2 = F_20 ( V_7 , struct V_1 , V_7 ) ;
V_37 = F_1 ( V_2 ) ;
if ( V_37 == V_39 ) {
F_21 ( & V_2 -> V_27 -> V_2 , L_8 ) ;
return;
}
F_21 ( & V_2 -> V_27 -> V_2 , L_9 ) ;
F_22 ( V_2 ) ;
}
static void F_23 ( struct V_32 * V_33 )
{
unsigned long V_40 = F_24 ( V_41 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_36 * V_7 ;
unsigned long V_5 ;
V_17 = F_20 ( V_33 , struct V_16 , V_33 ) ;
V_7 = F_20 ( V_17 , struct V_36 , V_17 ) ;
V_2 = F_20 ( V_7 , struct V_1 , V_7 ) ;
F_17 ( V_2 , L_10 ) ;
F_16 ( V_2 ) ;
F_5 ( & V_17 -> V_42 , V_5 ) ;
if ( ! F_25 ( V_43 , & V_17 -> V_5 ) )
F_26 ( & V_17 -> V_38 , V_40 ) ;
else
F_21 ( & V_2 -> V_27 -> V_2 ,
L_11 ) ;
F_6 ( & V_17 -> V_42 , V_5 ) ;
}
static const char * F_27 ( T_1 V_44 )
{
switch ( V_44 ) {
case V_45 :
return L_12 ;
case V_46 :
return L_13 ;
case V_47 :
return L_14 ;
case V_48 :
return L_15 ;
case V_49 :
return L_16 ;
case V_50 :
return L_17 ;
case V_51 :
return L_18 ;
case V_52 :
return L_19 ;
case V_53 :
return L_20 ;
case V_54 :
return L_21 ;
case V_55 :
return L_22 ;
default:
return L_23 ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
struct V_18 T_3 * V_19 = V_17 -> V_17 ;
char V_56 [ 18 ] ;
T_4 V_57 ;
int V_58 ;
if ( ! F_29 ( & V_19 -> V_44 ) )
return;
for ( V_58 = 0 ; V_58 < F_30 ( V_19 -> V_59 ) ; V_58 ++ )
F_21 ( & V_2 -> V_27 -> V_2 , L_24 , V_58 , F_2 ( V_19 -> V_59 + V_58 ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_25 , F_2 ( & V_19 -> V_60 ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_26 , F_2 ( & V_19 -> V_61 ) ) ;
sprintf ( V_56 , L_27 , F_31 ( V_2 ) , F_32 ( V_2 ) , F_33 ( V_2 ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_28 , V_56 ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_29 , F_2 ( & V_19 -> V_62 ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_30 , F_29 ( & V_19 -> V_63 ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_31 , F_29 ( & V_19 -> V_44 ) , F_27 ( F_29 ( & V_19 -> V_44 ) ) ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_32 , F_34 ( & V_19 -> V_64 ) ) ;
V_57 = F_2 ( & V_19 -> V_21 ) ;
F_21 ( & V_2 -> V_27 -> V_2 , L_33 , V_57 ) ;
}
static unsigned long F_35 ( void )
{
unsigned long V_65 ;
F_36 ( & V_65 , sizeof( V_65 ) ) ;
V_65 %= V_66 ;
V_65 += V_67 + V_68 ;
return V_65 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
unsigned long V_5 ;
F_5 ( & V_17 -> V_42 , V_5 ) ;
if ( ! F_25 ( V_69 , & V_17 -> V_5 ) )
F_38 ( V_17 -> V_70 , & V_17 -> V_33 ) ;
else
F_21 ( & V_2 -> V_27 -> V_2 ,
L_11 ) ;
F_6 ( & V_17 -> V_42 , V_5 ) ;
}
static void F_39 ( unsigned long V_71 )
{
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
T_4 V_72 ;
if ( V_2 -> V_24 == V_25 )
goto V_73;
V_72 = F_2 ( V_17 -> V_74 ) ;
if ( V_72 == V_17 -> V_75 )
++ V_17 -> V_76 ;
else
V_17 -> V_76 = 0 ;
V_17 -> V_75 = V_72 ;
if ( V_17 -> V_76 == V_77 ) {
F_21 ( & V_2 -> V_27 -> V_2 , L_34 ) ;
F_28 ( V_2 ) ;
}
if ( F_9 ( V_2 ) && ! V_17 -> V_78 ) {
V_17 -> V_78 = true ;
F_28 ( V_2 ) ;
F_37 ( V_2 ) ;
}
V_73:
F_40 ( & V_17 -> V_79 , F_35 () ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_42 ( & V_17 -> V_79 ) ;
V_17 -> V_78 = 0 ;
F_43 ( V_69 , & V_17 -> V_5 ) ;
F_43 ( V_43 , & V_17 -> V_5 ) ;
V_17 -> V_17 = & V_2 -> V_3 -> V_17 ;
V_17 -> V_74 = & V_2 -> V_3 -> V_74 ;
V_17 -> V_79 . V_71 = ( unsigned long ) V_2 ;
V_17 -> V_79 . V_80 = F_39 ;
V_17 -> V_79 . V_81 = F_44 ( V_67 + V_68 ) ;
F_45 ( & V_17 -> V_79 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_47 ( & V_17 -> V_79 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
unsigned long V_5 ;
F_5 ( & V_17 -> V_42 , V_5 ) ;
F_49 ( V_69 , & V_17 -> V_5 ) ;
F_49 ( V_43 , & V_17 -> V_5 ) ;
F_6 ( & V_17 -> V_42 , V_5 ) ;
F_50 ( & V_17 -> V_38 ) ;
F_51 ( & V_17 -> V_33 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_53 ( & V_17 -> V_42 ) ;
F_49 ( V_43 , & V_17 -> V_5 ) ;
F_54 ( & V_17 -> V_42 ) ;
F_50 ( & V_2 -> V_7 . V_17 . V_38 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_56 ( V_17 -> V_70 ) ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
char * V_82 ;
V_17 = & V_2 -> V_7 . V_17 ;
V_82 = F_58 ( 64 , V_83 ) ;
if ( ! V_82 )
return - V_84 ;
strcpy ( V_82 , L_35 ) ;
strcat ( V_82 , F_59 ( & V_2 -> V_27 -> V_2 ) ) ;
V_17 -> V_70 = F_60 ( V_82 ) ;
F_61 ( V_82 ) ;
if ( ! V_17 -> V_70 )
return - V_84 ;
F_62 ( & V_17 -> V_42 ) ;
F_63 ( & V_17 -> V_33 , F_23 ) ;
F_64 ( & V_17 -> V_38 , F_19 ) ;
return 0 ;
}
