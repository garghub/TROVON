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
if ( V_2 -> V_22 == V_23 )
return;
F_11 ( V_2 , L_2 ) ;
if ( F_12 ( V_2 -> V_24 ) || F_9 ( V_2 ) )
V_2 -> V_22 = V_23 ;
F_13 ( V_2 , V_25 , 0 ) ;
F_11 ( V_2 , L_3 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_26 = F_1 ( V_2 ) ;
switch ( V_26 ) {
case V_27 :
F_15 ( V_2 , L_4 ) ;
break;
case V_20 :
F_15 ( V_2 , L_5 ) ;
break;
case V_28 :
F_15 ( V_2 , L_6 ) ;
break;
default:
F_15 ( V_2 , L_7 ,
V_26 ) ;
}
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
struct V_31 * V_7 ;
V_17 = F_18 ( V_30 , struct V_16 , V_30 ) ;
V_7 = F_18 ( V_17 , struct V_31 , V_17 ) ;
V_2 = F_18 ( V_7 , struct V_1 , V_7 ) ;
F_15 ( V_2 , L_8 ) ;
F_14 ( V_2 ) ;
}
static const char * F_19 ( T_1 V_32 )
{
switch ( V_32 ) {
case V_33 :
return L_9 ;
case V_34 :
return L_10 ;
case V_35 :
return L_11 ;
case V_36 :
return L_12 ;
case V_37 :
return L_13 ;
case V_38 :
return L_14 ;
case V_39 :
return L_15 ;
case V_40 :
return L_16 ;
case V_41 :
return L_17 ;
case V_42 :
return L_18 ;
case V_43 :
return L_19 ;
default:
return L_20 ;
}
}
static T_4 F_20 ( T_5 V_44 )
{
return V_44 >> 28 ;
}
static T_4 F_21 ( T_5 V_44 )
{
return V_44 >> 16 & 0xfff ;
}
static T_4 F_22 ( T_5 V_44 )
{
return V_44 & 0xffff ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
struct V_18 T_3 * V_19 = V_17 -> V_17 ;
char V_45 [ 18 ] ;
T_5 V_44 ;
int V_46 ;
if ( ! F_24 ( & V_19 -> V_32 ) )
return;
for ( V_46 = 0 ; V_46 < F_25 ( V_19 -> V_47 ) ; V_46 ++ )
F_26 ( & V_2 -> V_24 -> V_2 , L_21 , V_46 , F_2 ( V_19 -> V_47 + V_46 ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_22 , F_2 ( & V_19 -> V_48 ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_23 , F_2 ( & V_19 -> V_49 ) ) ;
V_44 = F_2 ( & V_19 -> V_21 ) ;
sprintf ( V_45 , L_24 , F_20 ( V_44 ) , F_21 ( V_44 ) , F_22 ( V_44 ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_25 , V_45 ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_26 , F_2 ( & V_19 -> V_50 ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_27 , F_24 ( & V_19 -> V_51 ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_28 , F_24 ( & V_19 -> V_32 ) , F_19 ( F_24 ( & V_19 -> V_32 ) ) ) ;
F_26 ( & V_2 -> V_24 -> V_2 , L_29 , F_27 ( & V_19 -> V_52 ) ) ;
}
static unsigned long F_28 ( void )
{
unsigned long V_53 ;
F_29 ( & V_53 , sizeof( V_53 ) ) ;
V_53 %= V_54 ;
V_53 += V_55 + V_56 ;
return V_53 ;
}
static void F_30 ( unsigned long V_57 )
{
struct V_1 * V_2 = (struct V_1 * ) V_57 ;
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
T_5 V_58 ;
if ( V_2 -> V_22 == V_23 ) {
F_3 ( V_2 ) ;
F_31 ( & V_17 -> V_59 , F_28 () ) ;
return;
}
V_58 = F_2 ( V_17 -> V_60 ) ;
if ( V_58 == V_17 -> V_61 )
++ V_17 -> V_62 ;
else
V_17 -> V_62 = 0 ;
V_17 -> V_61 = V_58 ;
if ( V_17 -> V_62 == V_63 ) {
F_26 ( & V_2 -> V_24 -> V_2 , L_30 ) ;
F_23 ( V_2 ) ;
} else {
F_31 ( & V_17 -> V_59 , F_28 () ) ;
}
if ( F_9 ( V_2 ) && ! V_17 -> V_64 ) {
V_17 -> V_64 = true ;
F_23 ( V_2 ) ;
F_32 ( V_17 -> V_65 , & V_17 -> V_30 ) ;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_34 ( & V_17 -> V_59 ) ;
V_17 -> V_17 = & V_2 -> V_3 -> V_17 ;
V_17 -> V_60 = & V_2 -> V_3 -> V_60 ;
V_17 -> V_59 . V_57 = ( unsigned long ) V_2 ;
V_17 -> V_59 . V_66 = F_30 ;
V_17 -> V_59 . V_67 = F_35 ( V_55 + V_56 ) ;
F_36 ( & V_17 -> V_59 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_38 ( & V_17 -> V_59 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_7 . V_17 ;
F_40 ( V_17 -> V_65 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
char * V_68 ;
V_17 = & V_2 -> V_7 . V_17 ;
V_68 = F_42 ( 64 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
strcpy ( V_68 , L_31 ) ;
strcat ( V_68 , F_43 ( & V_2 -> V_24 -> V_2 ) ) ;
V_17 -> V_65 = F_44 ( V_68 ) ;
F_45 ( V_68 ) ;
if ( ! V_17 -> V_65 )
return - V_70 ;
F_46 ( & V_17 -> V_30 , F_17 ) ;
return 0 ;
}
