static void F_1 ( T_1 * V_1 )
{
* V_1 = V_2 . V_3 +
( F_2 ( V_2 . V_4 + V_5 ) & 0xffffff ) * 4 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
T_2 V_13 ;
F_4 ( & V_11 -> V_14 ) ;
V_11 -> V_15 = ( void * ) V_7 ;
F_5 ( & V_11 -> V_14 ) ;
V_13 = V_2 . V_3 + V_11 -> V_16 ;
F_6 ( V_13 , V_2 . V_4 + V_17 ) ;
V_13 = V_2 . V_3 ;
F_6 ( V_13 , V_2 . V_4 + V_18 ) ;
V_13 = F_2 ( V_2 . V_4 + V_19 ) ;
V_13 &= ~ ( V_20 << V_21 ) ;
V_13 |= ( ( ( V_9 -> V_22 >> 2 ) &
V_20 ) << V_21 ) ;
F_6 ( V_13 , V_2 . V_4 + V_19 ) ;
V_13 = F_2 ( V_2 . V_4 + V_23 ) ;
V_13 |= V_24 ;
F_6 ( V_13 , V_2 . V_4 + V_23 ) ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 ,
void (* F_8)( void * , int ) )
{
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
F_4 ( & V_11 -> V_14 ) ;
V_11 -> F_8 = F_8 ;
F_5 ( & V_11 -> V_14 ) ;
}
static void F_9 ( int V_25 )
{
T_2 V_13 = F_2 ( V_2 . V_4 + V_23 ) ;
F_4 ( & V_2 . V_14 ) ;
switch ( V_25 ) {
case V_26 :
V_13 |= ( V_24 | V_27 ) ;
break;
case V_28 :
V_13 &= ~ ( V_24 | V_27 ) ;
break;
default:
F_5 ( & V_2 . V_14 ) ;
return;
}
F_6 ( V_13 , V_2 . V_4 + V_23 ) ;
F_5 ( & V_2 . V_14 ) ;
}
static void F_10 ( void * V_29 , int V_30 )
{
struct V_6 * V_7 = V_29 ;
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
if ( V_11 && ( V_11 -> V_31 & V_32 ) )
F_11 ( V_7 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_33 * V_34 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
T_2 V_35 = F_2 ( V_2 . V_4 + V_36 ) ;
T_2 V_37 = F_2 ( V_2 . V_4 + V_23 ) ;
V_37 |= ( V_38 | V_39 ) ;
V_35 |= V_40 ;
F_6 ( V_37 , V_2 . V_4 + V_23 ) ;
F_6 ( V_35 , V_2 . V_4 + V_36 ) ;
F_13 ( V_7 , & V_7 -> V_41 ) ;
V_9 -> V_22 = F_14 ( V_34 ) ;
V_11 -> V_42 = V_11 -> V_43 = V_9 -> V_44 ;
V_11 -> V_45 = F_15 ( V_34 ) ;
V_11 -> V_16 = F_16 ( V_34 ) ;
V_11 -> V_46 = V_9 -> V_44 + V_9 -> V_22 ;
F_7 ( V_7 , F_10 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
F_13 ( V_7 , NULL ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
V_11 -> V_43 = V_11 -> V_42 ;
F_9 ( V_28 ) ;
F_3 ( V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , int V_47 )
{
struct V_10 * V_11 = V_7 -> V_9 -> V_12 ;
int V_48 = 0 ;
F_4 ( & V_11 -> V_14 ) ;
switch ( V_47 ) {
case V_49 :
case V_50 :
case V_51 :
V_11 -> V_31 |= V_32 ;
F_9 ( V_26 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
V_11 -> V_31 &= ~ V_32 ;
F_9 ( V_28 ) ;
break;
default:
V_48 = - V_55 ;
break;
}
F_5 ( & V_11 -> V_14 ) ;
return V_48 ;
}
static T_3
F_20 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_1 ;
unsigned long V_56 ;
F_4 ( & V_11 -> V_14 ) ;
F_1 ( & V_1 ) ;
V_56 = V_1 - V_11 -> V_42 ;
F_5 ( & V_11 -> V_14 ) ;
return F_21 ( V_7 -> V_9 , V_56 ) ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long V_59 , V_60 ;
int V_48 ;
V_58 -> V_61 = F_23 ( V_58 -> V_61 ) ;
V_58 -> V_62 |= V_63 ;
V_59 = V_58 -> V_64 - V_58 -> V_65 ;
V_60 = V_58 -> V_66 << V_67 ;
V_48 = F_24 ( V_58 , V_58 -> V_65 ,
( V_9 -> V_44 + V_60 ) >> V_67 ,
V_59 , V_58 -> V_61 ) ;
return V_48 ;
}
static T_4 F_25 ( int V_68 , void * V_69 )
{
struct V_10 * V_11 = (struct V_10 * ) V_69 ;
T_2 V_70 , V_71 , V_13 , V_72 ;
V_71 = F_2 ( V_2 . V_4 + V_23 ) ;
V_70 = F_2 ( V_2 . V_4 + V_73 ) ;
V_13 = ( V_71 & V_74 ) ? V_75 : 0 ;
if ( V_13 ) {
V_71 |= V_13 ;
F_6 ( V_71 , V_2 . V_4 + V_23 ) ;
V_72 = F_2 ( V_2 . V_4 + V_17 ) - V_2 . V_3 ;
V_72 += V_11 -> V_16 ;
V_72 %= ( V_11 -> V_46 - V_11 -> V_42 ) ;
V_72 += V_2 . V_3 ;
F_6 ( V_72 , V_2 . V_4 + V_17 ) ;
if ( V_11 -> F_8 )
V_11 -> F_8 ( V_11 -> V_15 , V_11 -> V_45 ) ;
}
return V_76 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 ;
int V_48 ;
F_27 ( V_7 , & V_77 ) ;
V_11 = F_28 ( sizeof( struct V_10 ) , V_78 ) ;
if ( V_11 == NULL )
return - V_79 ;
V_48 = F_29 ( V_80 , F_25 , 0 , L_1 , V_11 ) ;
if ( V_48 < 0 ) {
F_30 ( L_2 , V_48 ) ;
F_31 ( V_11 ) ;
return V_48 ;
}
F_32 ( & V_11 -> V_14 ) ;
V_9 -> V_12 = V_11 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_34 ( V_80 , V_11 ) ;
if ( ! V_11 )
F_30 ( L_3 ) ;
F_31 ( V_11 ) ;
return 0 ;
}
static void F_35 ( struct V_81 * V_82 )
{
struct V_6 * V_7 ;
struct V_83 * V_84 ;
V_7 = V_82 -> V_85 [ V_86 ] . V_7 ;
if ( ! V_7 )
return;
V_84 = & V_7 -> V_41 ;
if ( ! V_84 -> V_87 )
return;
F_36 ( V_84 -> V_87 ) ;
V_84 -> V_87 = NULL ;
V_84 -> V_72 = 0 ;
}
static int F_37 ( struct V_81 * V_82 , int V_88 )
{
struct V_6 * V_7 = V_82 -> V_85 [ V_88 ] . V_7 ;
struct V_83 * V_84 = & V_7 -> V_41 ;
V_84 -> V_89 . V_89 = V_82 -> V_90 -> V_89 ;
V_84 -> V_12 = NULL ;
V_84 -> V_89 . type = V_91 ;
V_84 -> V_72 = V_2 . V_3 ;
V_84 -> V_92 = V_77 . V_93 ;
V_84 -> V_87 = ( unsigned char * ) F_38 ( V_84 -> V_72 , V_84 -> V_92 ) ;
return 0 ;
}
static int F_39 ( struct V_94 * V_95 )
{
struct V_96 * V_90 = V_95 -> V_90 -> V_96 ;
struct V_81 * V_82 = V_95 -> V_82 ;
int V_48 = 0 ;
if ( ! V_90 -> V_89 -> V_97 )
V_90 -> V_89 -> V_97 = & V_98 ;
if ( ! V_90 -> V_89 -> V_99 )
V_90 -> V_89 -> V_99 = F_40 ( 32 ) ;
if ( V_82 -> V_85 [ V_86 ] . V_7 ) {
V_48 = F_37 ( V_82 ,
V_86 ) ;
}
return V_48 ;
}
void F_41 ( void T_5 * V_4 , T_1 V_72 )
{
F_32 ( & V_2 . V_14 ) ;
V_2 . V_4 = V_4 ;
V_2 . V_3 = V_72 ;
}
static int T_6 F_42 ( struct V_100 * V_101 )
{
return F_43 ( & V_101 -> V_89 , & V_102 ) ;
}
static int T_7 F_44 ( struct V_100 * V_101 )
{
F_45 ( & V_101 -> V_89 ) ;
return 0 ;
}
