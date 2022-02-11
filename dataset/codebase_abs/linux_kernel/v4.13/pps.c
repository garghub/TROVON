static unsigned int F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
F_2 ( V_1 , & V_4 -> V_6 , V_2 ) ;
return V_7 | V_8 ;
}
static int F_3 ( int V_9 , struct V_1 * V_1 , int V_10 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_4 ( V_9 , V_1 , V_10 , & V_4 -> V_11 ) ;
}
static int F_5 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
unsigned int V_14 = V_4 -> V_15 ;
int V_16 = 0 ;
if ( V_13 -> V_17 . V_18 & V_19 )
V_16 = F_6 ( V_4 -> V_6 ,
V_14 != V_4 -> V_15 ) ;
else {
unsigned long V_20 ;
F_7 ( V_4 -> V_21 , L_1 ,
( long long ) V_13 -> V_17 . V_22 ,
V_13 -> V_17 . V_23 ) ;
V_20 = V_13 -> V_17 . V_22 * V_24 ;
V_20 += V_13 -> V_17 . V_23 / ( V_25 / V_24 ) ;
if ( V_20 != 0 ) {
V_16 = F_8 (
V_4 -> V_6 ,
V_14 != V_4 -> V_15 ,
V_20 ) ;
if ( V_16 == 0 )
return - V_26 ;
}
}
if ( V_16 == - V_27 ) {
F_7 ( V_4 -> V_21 , L_2 ) ;
return - V_28 ;
}
return 0 ;
}
static long F_9 ( struct V_1 * V_1 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_31 V_32 ;
void T_2 * V_33 = ( void T_2 * ) V_30 ;
int T_2 * V_34 = ( int T_2 * ) V_30 ;
int V_16 ;
switch ( V_29 ) {
case V_35 :
F_7 ( V_4 -> V_21 , L_3 ) ;
F_10 ( & V_4 -> V_36 ) ;
V_32 = V_4 -> V_32 ;
F_11 ( & V_4 -> V_36 ) ;
V_16 = F_12 ( V_33 , & V_32 , sizeof( struct V_31 ) ) ;
if ( V_16 )
return - V_37 ;
break;
case V_38 :
F_7 ( V_4 -> V_21 , L_4 ) ;
if ( ! F_13 ( V_39 ) )
return - V_40 ;
V_16 = F_14 ( & V_32 , V_33 , sizeof( struct V_31 ) ) ;
if ( V_16 )
return - V_37 ;
if ( ! ( V_32 . V_41 & ( V_42 | V_43 ) ) ) {
F_7 ( V_4 -> V_21 , L_5 ,
V_32 . V_41 ) ;
return - V_44 ;
}
if ( ( V_32 . V_41 & ~ V_4 -> V_45 . V_41 ) != 0 ) {
F_7 ( V_4 -> V_21 , L_6 ,
V_32 . V_41 ) ;
return - V_44 ;
}
F_10 ( & V_4 -> V_36 ) ;
V_4 -> V_32 = V_32 ;
if ( ( V_32 . V_41 & ( V_46 | V_47 ) ) == 0 ) {
F_7 ( V_4 -> V_21 , L_7 ,
V_32 . V_41 ) ;
V_4 -> V_32 . V_41 |= V_46 ;
}
if ( V_4 -> V_45 . V_41 & V_48 )
V_4 -> V_32 . V_41 |= V_48 ;
V_4 -> V_32 . V_49 = V_50 ;
F_11 ( & V_4 -> V_36 ) ;
break;
case V_51 :
F_7 ( V_4 -> V_21 , L_8 ) ;
V_16 = F_15 ( V_4 -> V_45 . V_41 , V_34 ) ;
if ( V_16 )
return - V_37 ;
break;
case V_52 : {
struct V_12 V_13 ;
F_7 ( V_4 -> V_21 , L_9 ) ;
V_16 = F_14 ( & V_13 , V_33 , sizeof( struct V_12 ) ) ;
if ( V_16 )
return - V_37 ;
V_16 = F_5 ( V_4 , & V_13 ) ;
if ( V_16 )
return V_16 ;
F_10 ( & V_4 -> V_36 ) ;
V_13 . V_45 . V_53 = V_4 -> V_53 ;
V_13 . V_45 . V_54 = V_4 -> V_54 ;
V_13 . V_45 . V_55 = V_4 -> V_55 ;
V_13 . V_45 . V_56 = V_4 -> V_56 ;
V_13 . V_45 . V_57 = V_4 -> V_57 ;
F_11 ( & V_4 -> V_36 ) ;
V_16 = F_12 ( V_33 , & V_13 , sizeof( struct V_12 ) ) ;
if ( V_16 )
return - V_37 ;
break;
}
case V_58 : {
struct V_59 V_60 ;
F_7 ( V_4 -> V_21 , L_10 ) ;
if ( ! F_13 ( V_39 ) )
return - V_40 ;
if ( F_14 ( & V_60 , V_33 ,
sizeof( struct V_59 ) ) )
return - V_37 ;
if ( ( V_60 . V_61 & ~ V_4 -> V_45 . V_41 ) != 0 ) {
F_16 ( V_4 -> V_21 , L_6 ,
V_60 . V_61 ) ;
return - V_44 ;
}
if ( V_60 . V_62 != V_46 ||
( V_60 . V_61 & ~ V_63 ) != 0 ||
V_60 . V_64 != V_65 ) {
F_16 ( V_4 -> V_21 , L_11
L_12 , V_60 . V_61 ) ;
return - V_44 ;
}
V_16 = F_17 ( V_4 , & V_60 ) ;
if ( V_16 < 0 )
return V_16 ;
break;
}
default:
return - V_66 ;
}
return 0 ;
}
static long F_18 ( struct V_1 * V_1 ,
unsigned int V_29 , unsigned long V_30 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
void T_2 * V_33 = ( void T_2 * ) V_30 ;
V_29 = F_19 ( F_20 ( V_29 ) , F_21 ( V_29 ) , F_22 ( V_29 ) , sizeof( void * ) ) ;
if ( V_29 == V_52 ) {
struct V_67 V_68 ;
struct V_12 V_13 ;
int V_16 ;
F_7 ( V_4 -> V_21 , L_9 ) ;
V_16 = F_14 ( & V_68 , V_33 , sizeof( struct V_67 ) ) ;
if ( V_16 )
return - V_37 ;
memcpy ( & V_13 . V_17 , & V_68 . V_17 ,
sizeof( struct V_69 ) ) ;
V_16 = F_5 ( V_4 , & V_13 ) ;
if ( V_16 )
return V_16 ;
F_10 ( & V_4 -> V_36 ) ;
V_68 . V_45 . V_53 = V_4 -> V_53 ;
V_68 . V_45 . V_54 = V_4 -> V_54 ;
V_68 . V_45 . V_57 = V_4 -> V_57 ;
memcpy ( & V_68 . V_45 . V_55 , & V_4 -> V_55 ,
sizeof( struct V_69 ) ) ;
memcpy ( & V_68 . V_45 . V_56 , & V_4 -> V_56 ,
sizeof( struct V_69 ) ) ;
F_11 ( & V_4 -> V_36 ) ;
return F_12 ( V_33 , & V_68 ,
sizeof( struct V_67 ) ) ? - V_37 : 0 ;
}
return F_9 ( V_1 , V_29 , V_30 ) ;
}
static int F_23 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_3 * V_4 = F_24 ( V_70 -> V_71 ,
struct V_3 , V_72 ) ;
V_1 -> V_5 = V_4 ;
F_25 ( & V_4 -> V_21 -> V_73 ) ;
return 0 ;
}
static int F_26 ( struct V_70 * V_70 , struct V_1 * V_1 )
{
struct V_3 * V_4 = F_24 ( V_70 -> V_71 ,
struct V_3 , V_72 ) ;
F_27 ( & V_4 -> V_21 -> V_73 ) ;
return 0 ;
}
static void F_28 ( struct V_74 * V_21 )
{
struct V_3 * V_4 = F_29 ( V_21 ) ;
F_30 ( & V_4 -> V_72 ) ;
F_31 ( L_13 , V_4 -> V_75 ) ;
F_32 ( & V_76 ) ;
F_33 ( & V_77 , V_4 -> V_75 ) ;
F_34 ( & V_76 ) ;
F_35 ( V_21 ) ;
F_35 ( V_4 ) ;
}
int F_36 ( struct V_3 * V_4 )
{
int V_16 ;
T_3 V_78 ;
F_32 ( & V_76 ) ;
V_16 = F_37 ( & V_77 , V_4 , 0 , V_79 , V_80 ) ;
if ( V_16 < 0 ) {
if ( V_16 == - V_81 ) {
F_38 ( L_14 ,
V_4 -> V_45 . V_82 ) ;
V_16 = - V_83 ;
}
goto V_84;
}
V_4 -> V_75 = V_16 ;
F_34 ( & V_76 ) ;
V_78 = F_39 ( F_40 ( V_85 ) , V_4 -> V_75 ) ;
F_41 ( & V_4 -> V_72 , & V_86 ) ;
V_4 -> V_72 . V_87 = V_4 -> V_45 . V_87 ;
V_16 = F_42 ( & V_4 -> V_72 , V_78 , 1 ) ;
if ( V_16 ) {
F_38 ( L_15 ,
V_4 -> V_45 . V_82 , F_40 ( V_85 ) , V_4 -> V_75 ) ;
goto V_88;
}
V_4 -> V_21 = F_43 ( V_89 , V_4 -> V_45 . V_21 , V_78 , V_4 ,
L_16 , V_4 -> V_75 ) ;
if ( F_44 ( V_4 -> V_21 ) ) {
V_16 = F_45 ( V_4 -> V_21 ) ;
goto V_90;
}
V_4 -> V_21 -> V_91 = F_28 ;
F_31 ( L_17 , V_4 -> V_45 . V_82 ,
F_40 ( V_85 ) , V_4 -> V_75 ) ;
return 0 ;
V_90:
F_30 ( & V_4 -> V_72 ) ;
V_88:
F_32 ( & V_76 ) ;
F_33 ( & V_77 , V_4 -> V_75 ) ;
V_84:
F_34 ( & V_76 ) ;
return V_16 ;
}
void F_46 ( struct V_3 * V_4 )
{
F_31 ( L_18 , V_4 -> V_75 ) ;
V_4 -> V_92 = NULL ;
F_47 ( V_89 , V_4 -> V_21 -> V_78 ) ;
}
struct V_3 * F_48 ( void const * V_93 )
{
struct V_3 * V_4 ;
unsigned V_75 ;
F_49 () ;
F_50 (&pps_idr, pps, id)
if ( V_93 == V_4 -> V_92 )
break;
F_51 () ;
return V_4 ;
}
static void T_4 F_52 ( void )
{
F_53 ( V_89 ) ;
F_54 ( V_85 , V_79 ) ;
}
static int T_5 F_55 ( void )
{
int V_16 ;
V_89 = F_56 ( V_94 , L_19 ) ;
if ( F_44 ( V_89 ) ) {
F_38 ( L_20 ) ;
return F_45 ( V_89 ) ;
}
V_89 -> V_95 = V_96 ;
V_16 = F_57 ( & V_85 , 0 , V_79 , L_19 ) ;
if ( V_16 < 0 ) {
F_38 ( L_21 ) ;
goto V_97;
}
F_58 ( L_22 , V_50 ) ;
F_58 ( L_23
L_24 , V_98 ) ;
return 0 ;
V_97:
F_53 ( V_89 ) ;
return V_16 ;
}
