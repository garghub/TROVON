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
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_23 == V_24 )
goto V_25;
F_12 ( V_2 , L_2 ) ;
if ( F_13 ( V_2 -> V_26 ) || F_9 ( V_2 ) ) {
V_2 -> V_23 = V_24 ;
F_3 ( V_2 ) ;
}
F_14 ( V_2 , V_27 , 0 ) ;
F_12 ( V_2 , L_3 ) ;
V_25:
F_15 ( & V_2 -> V_22 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_28 = F_1 ( V_2 ) ;
switch ( V_28 ) {
case V_29 :
F_17 ( V_2 , L_4 ) ;
break;
case V_20 :
F_17 ( V_2 , L_5 ) ;
break;
case V_30 :
F_17 ( V_2 , L_6 ) ;
break;
default:
F_17 ( V_2 , L_7 ,
V_28 ) ;
}
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_31 * V_32 )
{
struct V_16 * V_17 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_35 * V_7 ;
T_1 V_36 ;
V_34 = F_20 ( V_32 , struct V_33 , V_32 ) ;
V_17 = F_20 ( V_34 , struct V_16 , V_37 ) ;
V_7 = F_20 ( V_17 , struct V_35 , V_17 ) ;
V_2 = F_20 ( V_7 , struct V_1 , V_7 ) ;
V_36 = F_1 ( V_2 ) ;
if ( V_36 == V_38 ) {
F_21 ( & V_2 -> V_26 -> V_2 , L_8 ) ;
return;
}
F_21 ( & V_2 -> V_26 -> V_2 , L_9 ) ;
F_22 ( V_2 ) ;
}
static void F_23 ( struct V_31 * V_32 )
{
unsigned long V_39 = F_24 ( V_40 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_35 * V_7 ;
V_17 = F_20 ( V_32 , struct V_16 , V_32 ) ;
V_7 = F_20 ( V_17 , struct V_35 , V_17 ) ;
V_2 = F_20 ( V_7 , struct V_1 , V_7 ) ;
F_17 ( V_2 , L_10 ) ;
F_16 ( V_2 ) ;
F_25 ( & V_17 -> V_41 ) ;
if ( ! F_26 ( V_42 , & V_17 -> V_5 ) )
F_27 ( & V_17 -> V_37 , V_39 ) ;
else
F_21 ( & V_2 -> V_26 -> V_2 ,
L_11 ) ;
F_28 ( & V_17 -> V_41 ) ;
}
static const char * F_29 ( T_1 V_43 )
{
switch ( V_43 ) {
case V_44 :
return L_12 ;
case V_45 :
return L_13 ;
case V_46 :
return L_14 ;
case V_47 :
return L_15 ;
case V_48 :
return L_16 ;
case V_49 :
return L_17 ;
case V_50 :
return L_18 ;
case V_51 :
return L_19 ;
case V_52 :
return L_20 ;
case V_53 :
return L_21 ;
case V_54 :
return L_22 ;
default:
return L_23 ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
struct V_18 T_3 * V_19 = V_17 -> V_17 ;
char V_55 [ 18 ] ;
T_4 V_56 ;
int V_57 ;
if ( ! F_31 ( & V_19 -> V_43 ) )
return;
for ( V_57 = 0 ; V_57 < F_32 ( V_19 -> V_58 ) ; V_57 ++ )
F_21 ( & V_2 -> V_26 -> V_2 , L_24 , V_57 , F_2 ( V_19 -> V_58 + V_57 ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_25 , F_2 ( & V_19 -> V_59 ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_26 , F_2 ( & V_19 -> V_60 ) ) ;
sprintf ( V_55 , L_27 , F_33 ( V_2 ) , F_34 ( V_2 ) , F_35 ( V_2 ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_28 , V_55 ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_29 , F_2 ( & V_19 -> V_61 ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_30 , F_31 ( & V_19 -> V_62 ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_31 , F_31 ( & V_19 -> V_43 ) , F_29 ( F_31 ( & V_19 -> V_43 ) ) ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_32 , F_36 ( & V_19 -> V_63 ) ) ;
V_56 = F_2 ( & V_19 -> V_21 ) ;
F_21 ( & V_2 -> V_26 -> V_2 , L_33 , V_56 ) ;
}
static unsigned long F_37 ( void )
{
unsigned long V_64 ;
F_38 ( & V_64 , sizeof( V_64 ) ) ;
V_64 %= V_65 ;
V_64 += V_66 + V_67 ;
return V_64 ;
}
static void F_39 ( unsigned long V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
T_4 V_69 ;
if ( V_2 -> V_23 == V_24 )
goto V_70;
V_69 = F_2 ( V_17 -> V_71 ) ;
if ( V_69 == V_17 -> V_72 )
++ V_17 -> V_73 ;
else
V_17 -> V_73 = 0 ;
V_17 -> V_72 = V_69 ;
if ( V_17 -> V_73 == V_74 ) {
F_21 ( & V_2 -> V_26 -> V_2 , L_34 ) ;
F_30 ( V_2 ) ;
}
if ( F_9 ( V_2 ) && ! V_17 -> V_75 ) {
V_17 -> V_75 = true ;
F_30 ( V_2 ) ;
F_25 ( & V_17 -> V_41 ) ;
if ( ! F_26 ( V_42 , & V_17 -> V_5 ) )
F_40 ( V_17 -> V_76 , & V_17 -> V_32 ) ;
else
F_21 ( & V_2 -> V_26 -> V_2 ,
L_11 ) ;
F_28 ( & V_17 -> V_41 ) ;
}
V_70:
F_41 ( & V_17 -> V_77 , F_37 () ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_43 ( & V_17 -> V_77 ) ;
V_17 -> V_75 = 0 ;
F_44 ( V_42 , & V_17 -> V_5 ) ;
V_17 -> V_17 = & V_2 -> V_3 -> V_17 ;
V_17 -> V_71 = & V_2 -> V_3 -> V_71 ;
V_17 -> V_77 . V_68 = ( unsigned long ) V_2 ;
V_17 -> V_77 . V_78 = F_39 ;
V_17 -> V_77 . V_79 = F_45 ( V_66 + V_67 ) ;
F_46 ( & V_17 -> V_77 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_48 ( & V_17 -> V_77 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_25 ( & V_17 -> V_41 ) ;
F_50 ( V_42 , & V_17 -> V_5 ) ;
F_28 ( & V_17 -> V_41 ) ;
F_51 ( & V_17 -> V_37 ) ;
F_52 ( & V_17 -> V_32 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_54 ( V_17 -> V_76 ) ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
char * V_80 ;
V_17 = & V_2 -> V_7 . V_17 ;
V_80 = F_56 ( 64 , V_81 ) ;
if ( ! V_80 )
return - V_82 ;
strcpy ( V_80 , L_35 ) ;
strcat ( V_80 , F_57 ( & V_2 -> V_26 -> V_2 ) ) ;
V_17 -> V_76 = F_58 ( V_80 ) ;
F_59 ( V_80 ) ;
if ( ! V_17 -> V_76 )
return - V_82 ;
F_60 ( & V_17 -> V_41 ) ;
F_61 ( & V_17 -> V_32 , F_23 ) ;
F_62 ( & V_17 -> V_37 , F_19 ) ;
return 0 ;
}
