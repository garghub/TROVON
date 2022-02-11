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
F_8 ( V_2 , V_6 ) ;
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
struct V_1 * V_2 ;
struct V_33 * V_7 ;
V_17 = F_20 ( V_32 , struct V_16 , V_32 ) ;
V_7 = F_20 ( V_17 , struct V_33 , V_17 ) ;
V_2 = F_20 ( V_7 , struct V_1 , V_7 ) ;
F_17 ( V_2 , L_8 ) ;
F_16 ( V_2 ) ;
}
static const char * F_21 ( T_1 V_34 )
{
switch ( V_34 ) {
case V_35 :
return L_9 ;
case V_36 :
return L_10 ;
case V_37 :
return L_11 ;
case V_38 :
return L_12 ;
case V_39 :
return L_13 ;
case V_40 :
return L_14 ;
case V_41 :
return L_15 ;
case V_42 :
return L_16 ;
case V_43 :
return L_17 ;
case V_44 :
return L_18 ;
case V_45 :
return L_19 ;
default:
return L_20 ;
}
}
static T_4 F_22 ( T_5 V_46 )
{
return V_46 >> 28 ;
}
static T_4 F_23 ( T_5 V_46 )
{
return V_46 >> 16 & 0xfff ;
}
static T_4 F_24 ( T_5 V_46 )
{
return V_46 & 0xffff ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
struct V_18 T_3 * V_19 = V_17 -> V_17 ;
char V_47 [ 18 ] ;
T_5 V_46 ;
int V_48 ;
if ( ! F_26 ( & V_19 -> V_34 ) )
return;
for ( V_48 = 0 ; V_48 < F_27 ( V_19 -> V_49 ) ; V_48 ++ )
F_28 ( & V_2 -> V_26 -> V_2 , L_21 , V_48 , F_2 ( V_19 -> V_49 + V_48 ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_22 , F_2 ( & V_19 -> V_50 ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_23 , F_2 ( & V_19 -> V_51 ) ) ;
V_46 = F_2 ( & V_19 -> V_21 ) ;
sprintf ( V_47 , L_24 , F_22 ( V_46 ) , F_23 ( V_46 ) , F_24 ( V_46 ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_25 , V_47 ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_26 , F_2 ( & V_19 -> V_52 ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_27 , F_26 ( & V_19 -> V_53 ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_28 , F_26 ( & V_19 -> V_34 ) , F_21 ( F_26 ( & V_19 -> V_34 ) ) ) ;
F_28 ( & V_2 -> V_26 -> V_2 , L_29 , F_29 ( & V_19 -> V_54 ) ) ;
}
static unsigned long F_30 ( void )
{
unsigned long V_55 ;
F_31 ( & V_55 , sizeof( V_55 ) ) ;
V_55 %= V_56 ;
V_55 += V_57 + V_58 ;
return V_55 ;
}
static void F_32 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
T_5 V_60 ;
if ( V_2 -> V_23 == V_24 ) {
F_33 ( & V_17 -> V_61 , F_30 () ) ;
return;
}
V_60 = F_2 ( V_17 -> V_62 ) ;
if ( V_60 == V_17 -> V_63 )
++ V_17 -> V_64 ;
else
V_17 -> V_64 = 0 ;
V_17 -> V_63 = V_60 ;
if ( V_17 -> V_64 == V_65 ) {
F_28 ( & V_2 -> V_26 -> V_2 , L_30 ) ;
F_25 ( V_2 ) ;
} else {
F_33 ( & V_17 -> V_61 , F_30 () ) ;
}
if ( F_9 ( V_2 ) && ! V_17 -> V_66 ) {
V_17 -> V_66 = true ;
F_25 ( V_2 ) ;
F_34 ( V_17 -> V_67 , & V_17 -> V_32 ) ;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_36 ( & V_17 -> V_61 ) ;
V_17 -> V_17 = & V_2 -> V_3 -> V_17 ;
V_17 -> V_62 = & V_2 -> V_3 -> V_62 ;
V_17 -> V_61 . V_59 = ( unsigned long ) V_2 ;
V_17 -> V_61 . V_68 = F_32 ;
V_17 -> V_61 . V_69 = F_37 ( V_57 + V_58 ) ;
F_38 ( & V_17 -> V_61 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_40 ( & V_17 -> V_61 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_42 ( V_17 -> V_67 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
char * V_70 ;
V_17 = & V_2 -> V_7 . V_17 ;
V_70 = F_44 ( 64 , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
strcpy ( V_70 , L_31 ) ;
strcat ( V_70 , F_45 ( & V_2 -> V_26 -> V_2 ) ) ;
V_17 -> V_67 = F_46 ( V_70 ) ;
F_47 ( V_70 ) ;
if ( ! V_17 -> V_67 )
return - V_72 ;
F_48 ( & V_17 -> V_32 , F_19 ) ;
return 0 ;
}
