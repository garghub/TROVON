static T_1 F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( & V_2 -> V_3 -> V_4 ) >> 8 ) & 3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
T_2 V_6 ;
F_4 ( F_5 ( V_2 -> V_7 , V_8 ) ) ;
F_6 ( & V_2 -> V_9 . V_10 , V_5 ) ;
V_6 = ~ V_2 -> V_9 . V_11 & ( ( 1ul << ( 1 << V_2 -> V_9 . V_12 ) ) - 1 ) ;
if ( ! V_6 )
goto V_13;
V_6 |= V_14 ;
F_7 ( & V_2 -> V_9 . V_10 , V_5 ) ;
F_8 ( V_2 , L_1 , V_6 ) ;
F_9 ( V_2 , V_6 , true ) ;
return;
V_13:
F_7 ( & V_2 -> V_9 . V_10 , V_5 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
struct V_18 T_3 * V_19 = V_16 -> V_16 ;
if ( F_1 ( V_2 ) == V_20 )
return 1 ;
if ( F_2 ( & V_19 -> V_21 ) == 0xffffffff )
return 1 ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , bool V_22 )
{
F_12 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_24 == V_25 )
goto V_26;
F_13 ( V_2 , L_2 ) ;
if ( F_14 ( V_2 -> V_7 ) || F_10 ( V_2 ) || V_22 ) {
V_2 -> V_24 = V_25 ;
F_3 ( V_2 ) ;
}
F_15 ( V_2 , V_27 , 0 ) ;
F_13 ( V_2 , L_3 ) ;
V_26:
F_16 ( & V_2 -> V_23 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_28 = F_1 ( V_2 ) ;
switch ( V_28 ) {
case V_29 :
F_18 ( V_2 , L_4 ) ;
break;
case V_20 :
F_18 ( V_2 , L_5 ) ;
break;
case V_30 :
F_18 ( V_2 , L_6 ) ;
break;
default:
F_18 ( V_2 , L_7 ,
V_28 ) ;
}
F_19 ( V_2 ) ;
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_15 * V_16 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
struct V_35 * V_17 ;
T_1 V_36 ;
V_34 = F_21 ( V_32 , struct V_33 , V_32 ) ;
V_16 = F_21 ( V_34 , struct V_15 , V_37 ) ;
V_17 = F_21 ( V_16 , struct V_35 , V_16 ) ;
V_2 = F_21 ( V_17 , struct V_1 , V_17 ) ;
V_36 = F_1 ( V_2 ) ;
if ( V_36 == V_38 ) {
F_22 ( & V_2 -> V_7 -> V_2 , L_8 ) ;
return;
}
F_22 ( & V_2 -> V_7 -> V_2 , L_9 ) ;
F_23 ( V_2 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
unsigned long V_39 = F_25 ( V_40 ) ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_35 * V_17 ;
unsigned long V_5 ;
V_16 = F_21 ( V_32 , struct V_15 , V_32 ) ;
V_17 = F_21 ( V_16 , struct V_35 , V_16 ) ;
V_2 = F_21 ( V_17 , struct V_1 , V_17 ) ;
F_18 ( V_2 , L_10 ) ;
F_17 ( V_2 ) ;
F_6 ( & V_16 -> V_41 , V_5 ) ;
if ( ! F_26 ( V_42 , & V_16 -> V_5 ) )
F_27 ( & V_16 -> V_37 , V_39 ) ;
else
F_22 ( & V_2 -> V_7 -> V_2 ,
L_11 ) ;
F_7 ( & V_16 -> V_41 , V_5 ) ;
}
static const char * F_28 ( T_1 V_43 )
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
static void F_29 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
struct V_18 T_3 * V_19 = V_16 -> V_16 ;
char V_55 [ 18 ] ;
T_4 V_56 ;
int V_57 ;
if ( ! F_30 ( & V_19 -> V_43 ) )
return;
for ( V_57 = 0 ; V_57 < F_31 ( V_19 -> V_58 ) ; V_57 ++ )
F_22 ( & V_2 -> V_7 -> V_2 , L_24 , V_57 , F_2 ( V_19 -> V_58 + V_57 ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_25 , F_2 ( & V_19 -> V_59 ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_26 , F_2 ( & V_19 -> V_60 ) ) ;
sprintf ( V_55 , L_27 , F_32 ( V_2 ) , F_33 ( V_2 ) , F_34 ( V_2 ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_28 , V_55 ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_29 , F_2 ( & V_19 -> V_61 ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_30 , F_30 ( & V_19 -> V_62 ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_31 , F_30 ( & V_19 -> V_43 ) , F_28 ( F_30 ( & V_19 -> V_43 ) ) ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_32 , F_35 ( & V_19 -> V_63 ) ) ;
V_56 = F_2 ( & V_19 -> V_21 ) ;
F_22 ( & V_2 -> V_7 -> V_2 , L_33 , V_56 ) ;
}
static unsigned long F_36 ( void )
{
unsigned long V_64 ;
F_37 ( & V_64 , sizeof( V_64 ) ) ;
V_64 %= V_65 ;
V_64 += V_66 + V_67 ;
return V_64 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
unsigned long V_5 ;
F_6 ( & V_16 -> V_41 , V_5 ) ;
if ( ! F_26 ( V_68 , & V_16 -> V_5 ) )
F_39 ( V_16 -> V_69 , & V_16 -> V_32 ) ;
else
F_22 ( & V_2 -> V_7 -> V_2 ,
L_11 ) ;
F_7 ( & V_16 -> V_41 , V_5 ) ;
}
static void F_40 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
T_4 V_71 ;
if ( V_2 -> V_24 == V_25 )
goto V_72;
V_71 = F_2 ( V_16 -> V_73 ) ;
if ( V_71 == V_16 -> V_74 )
++ V_16 -> V_75 ;
else
V_16 -> V_75 = 0 ;
V_16 -> V_74 = V_71 ;
if ( V_16 -> V_75 == V_76 ) {
F_22 ( & V_2 -> V_7 -> V_2 , L_34 ) ;
F_29 ( V_2 ) ;
}
if ( F_10 ( V_2 ) && ! V_16 -> V_77 ) {
V_16 -> V_77 = true ;
F_29 ( V_2 ) ;
F_38 ( V_2 ) ;
}
V_72:
F_41 ( & V_16 -> V_78 , F_36 () ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
F_43 ( & V_16 -> V_78 ) ;
V_16 -> V_77 = 0 ;
F_44 ( V_68 , & V_16 -> V_5 ) ;
F_44 ( V_42 , & V_16 -> V_5 ) ;
V_16 -> V_16 = & V_2 -> V_3 -> V_16 ;
V_16 -> V_73 = & V_2 -> V_3 -> V_73 ;
V_16 -> V_78 . V_70 = ( unsigned long ) V_2 ;
V_16 -> V_78 . V_79 = F_40 ;
V_16 -> V_78 . V_80 = F_45 ( V_66 + V_67 ) ;
F_46 ( & V_16 -> V_78 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
F_48 ( & V_16 -> V_78 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
unsigned long V_5 ;
F_6 ( & V_16 -> V_41 , V_5 ) ;
F_50 ( V_68 , & V_16 -> V_5 ) ;
F_50 ( V_42 , & V_16 -> V_5 ) ;
F_7 ( & V_16 -> V_41 , V_5 ) ;
F_51 ( & V_16 -> V_37 ) ;
F_52 ( & V_16 -> V_32 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
unsigned long V_5 ;
F_6 ( & V_16 -> V_41 , V_5 ) ;
F_50 ( V_42 , & V_16 -> V_5 ) ;
F_7 ( & V_16 -> V_41 , V_5 ) ;
F_51 ( & V_2 -> V_17 . V_16 . V_37 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 . V_16 ;
F_55 ( V_16 -> V_69 ) ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
char * V_81 ;
V_16 = & V_2 -> V_17 . V_16 ;
V_81 = F_57 ( 64 , V_82 ) ;
if ( ! V_81 )
return - V_83 ;
strcpy ( V_81 , L_35 ) ;
strcat ( V_81 , F_58 ( & V_2 -> V_7 -> V_2 ) ) ;
V_16 -> V_69 = F_59 ( V_81 ) ;
F_60 ( V_81 ) ;
if ( ! V_16 -> V_69 )
return - V_83 ;
F_61 ( & V_16 -> V_41 ) ;
F_62 ( & V_16 -> V_32 , F_24 ) ;
F_63 ( & V_16 -> V_37 , F_20 ) ;
return 0 ;
}
