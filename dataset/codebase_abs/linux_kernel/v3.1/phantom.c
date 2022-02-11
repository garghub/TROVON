static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( L_1 , V_2 -> V_4 , V_3 ) ;
if ( ! ( V_2 -> V_4 & V_5 ) && ( V_3 & V_5 ) ) {
F_3 ( & V_2 -> V_6 , 0 ) ;
F_4 ( V_7 , V_2 -> V_8 + V_9 ) ;
F_4 ( 0x43 , V_2 -> V_10 + V_11 ) ;
F_5 ( V_2 -> V_10 + V_11 ) ;
} else if ( ( V_2 -> V_4 & V_5 ) && ! ( V_3 & V_5 ) ) {
F_4 ( 0 , V_2 -> V_10 + V_11 ) ;
F_5 ( V_2 -> V_10 + V_11 ) ;
}
V_2 -> V_4 = V_3 ;
return 0 ;
}
static long F_6 ( struct V_12 * V_12 , unsigned int V_13 ,
unsigned long V_14 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
void T_1 * V_20 = ( void T_1 * ) V_14 ;
unsigned long V_21 ;
unsigned int V_22 ;
switch ( V_13 ) {
case V_23 :
case V_24 :
if ( F_7 ( & V_19 , V_20 , sizeof( V_19 ) ) )
return - V_25 ;
if ( V_19 . V_26 > 7 )
return - V_27 ;
F_8 ( & V_2 -> V_28 , V_21 ) ;
if ( V_19 . V_26 == V_9 && ( V_19 . V_29 & V_7 ) &&
F_1 ( V_2 , V_2 -> V_4 | V_5 ) ) {
F_9 ( & V_2 -> V_28 , V_21 ) ;
return - V_30 ;
}
F_2 ( L_2 , V_19 . V_29 , V_19 . V_26 ) ;
if ( V_19 . V_26 == V_9 && ( V_2 -> V_4 & V_31 ) ) {
V_19 . V_29 &= ~ V_32 ;
V_19 . V_29 |= V_2 -> V_33 & V_32 ;
V_2 -> V_33 = V_19 . V_29 ;
}
F_4 ( V_19 . V_29 , V_2 -> V_8 + V_19 . V_26 ) ;
F_5 ( V_2 -> V_8 ) ;
if ( V_19 . V_26 == V_9 && ! ( V_19 . V_29 & V_7 ) )
F_1 ( V_2 , V_2 -> V_4 & ~ V_5 ) ;
F_9 ( & V_2 -> V_28 , V_21 ) ;
break;
case V_34 :
case V_35 :
if ( F_7 ( & V_17 , V_20 , sizeof( V_17 ) ) )
return - V_25 ;
F_2 ( L_3 , V_17 . V_36 , V_17 . V_37 ) ;
F_8 ( & V_2 -> V_28 , V_21 ) ;
if ( V_2 -> V_4 & V_31 )
memcpy ( & V_2 -> V_38 , & V_17 , sizeof( V_17 ) ) ;
else {
T_2 V_39 = F_10 ( V_17 . V_36 , 8U ) ;
for ( V_22 = 0 ; V_22 < V_39 ; V_22 ++ )
if ( V_17 . V_37 & F_11 ( V_22 ) )
F_4 ( V_17 . V_40 [ V_22 ] , V_2 -> V_41 + V_22 ) ;
F_5 ( V_2 -> V_8 ) ;
}
F_9 ( & V_2 -> V_28 , V_21 ) ;
break;
case V_42 :
case V_43 :
if ( F_7 ( & V_19 , V_20 , sizeof( V_19 ) ) )
return - V_25 ;
if ( V_19 . V_26 > 7 )
return - V_27 ;
V_19 . V_29 = F_5 ( V_2 -> V_8 + V_19 . V_26 ) ;
if ( F_12 ( V_20 , & V_19 , sizeof( V_19 ) ) )
return - V_25 ;
break;
case V_44 :
case V_45 : {
T_2 V_39 ;
if ( F_7 ( & V_17 , V_20 , sizeof( V_17 ) ) )
return - V_25 ;
V_39 = F_10 ( V_17 . V_36 , 8U ) ;
F_2 ( L_4 , V_17 . V_36 , V_17 . V_37 ) ;
F_8 ( & V_2 -> V_28 , V_21 ) ;
for ( V_22 = 0 ; V_22 < V_39 ; V_22 ++ )
if ( V_17 . V_37 & F_11 ( V_22 ) )
V_17 . V_40 [ V_22 ] = F_5 ( V_2 -> V_8 + V_22 ) ;
F_3 ( & V_2 -> V_6 , 0 ) ;
F_9 ( & V_2 -> V_28 , V_21 ) ;
if ( F_12 ( V_20 , & V_17 , sizeof( V_17 ) ) )
return - V_25 ;
break;
} case V_46 :
F_8 ( & V_2 -> V_28 , V_21 ) ;
if ( V_2 -> V_4 & V_5 ) {
F_13 ( V_47 L_5
L_6 ) ;
F_9 ( & V_2 -> V_28 , V_21 ) ;
return - V_27 ;
}
V_2 -> V_4 |= V_31 ;
F_9 ( & V_2 -> V_28 , V_21 ) ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static long F_14 ( struct V_12 * V_49 , unsigned int V_13 ,
unsigned long V_14 )
{
if ( F_15 ( V_13 ) <= 3 && F_16 ( V_13 ) == sizeof( V_50 ) ) {
V_13 &= ~ ( V_51 << V_52 ) ;
V_13 |= sizeof( void * ) << V_52 ;
}
return F_6 ( V_49 , V_13 , ( unsigned long ) F_17 ( V_14 ) ) ;
}
static int F_18 ( struct V_53 * V_53 , struct V_12 * V_12 )
{
struct V_1 * V_2 = F_19 ( V_53 -> V_54 ,
struct V_1 , V_55 ) ;
F_20 ( & V_56 ) ;
F_21 ( V_53 , V_12 ) ;
if ( F_22 ( & V_2 -> V_57 ) ) {
F_23 ( & V_56 ) ;
return - V_58 ;
}
if ( V_2 -> V_59 ) {
F_23 ( & V_2 -> V_57 ) ;
F_23 ( & V_56 ) ;
return - V_27 ;
}
F_24 ( V_2 -> V_4 & V_31 ) ;
V_12 -> V_15 = V_2 ;
F_3 ( & V_2 -> V_6 , 0 ) ;
V_2 -> V_59 ++ ;
F_23 ( & V_2 -> V_57 ) ;
F_23 ( & V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_53 , struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
F_20 ( & V_2 -> V_57 ) ;
V_2 -> V_59 = 0 ;
F_1 ( V_2 , V_2 -> V_4 & ~ V_5 ) ;
V_2 -> V_4 &= ~ V_31 ;
F_23 ( & V_2 -> V_57 ) ;
return 0 ;
}
static unsigned int F_26 ( struct V_12 * V_12 , T_3 * V_60 )
{
struct V_1 * V_2 = V_12 -> V_15 ;
unsigned int V_37 = 0 ;
F_2 ( L_7 , F_27 ( & V_2 -> V_6 ) ) ;
F_28 ( V_12 , & V_2 -> V_60 , V_60 ) ;
if ( ! ( V_2 -> V_4 & V_5 ) )
V_37 = V_61 ;
else if ( F_27 ( & V_2 -> V_6 ) )
V_37 = V_62 | V_63 ;
F_2 ( L_8 , V_37 , F_27 ( & V_2 -> V_6 ) ) ;
return V_37 ;
}
static T_4 F_29 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_22 ;
T_2 V_66 ;
F_30 ( & V_2 -> V_28 ) ;
V_66 = F_5 ( V_2 -> V_8 + V_9 ) ;
if ( ! ( V_66 & V_7 ) ) {
F_31 ( & V_2 -> V_28 ) ;
return V_67 ;
}
F_4 ( 0 , V_2 -> V_8 ) ;
F_4 ( 0xc0 , V_2 -> V_8 ) ;
if ( V_2 -> V_4 & V_31 ) {
struct V_16 * V_19 = & V_2 -> V_38 ;
T_2 V_39 = F_10 ( V_19 -> V_36 , 8U ) ;
for ( V_22 = 0 ; V_22 < V_39 ; V_22 ++ )
if ( V_19 -> V_37 & F_11 ( V_22 ) )
F_4 ( V_19 -> V_40 [ V_22 ] , V_2 -> V_41 + V_22 ) ;
V_2 -> V_33 ^= V_32 ;
F_4 ( V_2 -> V_33 , V_2 -> V_8 + V_9 ) ;
}
F_31 ( & V_2 -> V_28 ) ;
F_5 ( V_2 -> V_8 ) ;
F_32 ( & V_2 -> V_6 ) ;
F_33 ( & V_2 -> V_60 ) ;
return V_68 ;
}
static unsigned int T_5 F_34 ( void )
{
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_69 ; V_22 ++ )
if ( V_70 [ V_22 ] == 0 )
break;
return V_22 ;
}
static int T_5 F_35 ( struct V_71 * V_72 ,
const struct V_73 * V_74 )
{
struct V_1 * V_75 ;
unsigned int V_76 ;
int V_77 ;
V_77 = F_36 ( V_72 ) ;
if ( V_77 ) {
F_37 ( & V_72 -> V_2 , L_9 ) ;
goto V_78;
}
V_76 = F_34 () ;
if ( V_76 == V_69 ) {
F_37 ( & V_72 -> V_2 , L_10 ) ;
V_77 = - V_79 ;
goto V_80;
}
V_70 [ V_76 ] = 1 ;
V_77 = F_38 ( V_72 , L_11 ) ;
if ( V_77 ) {
F_37 ( & V_72 -> V_2 , L_12 ) ;
goto V_81;
}
V_77 = - V_82 ;
V_75 = F_39 ( sizeof( * V_75 ) , V_83 ) ;
if ( V_75 == NULL ) {
F_37 ( & V_72 -> V_2 , L_13 ) ;
goto V_84;
}
V_75 -> V_10 = F_40 ( V_72 , 0 , 0 ) ;
if ( V_75 -> V_10 == NULL ) {
F_37 ( & V_72 -> V_2 , L_14 ) ;
goto V_85;
}
V_75 -> V_8 = F_40 ( V_72 , 2 , 0 ) ;
if ( V_75 -> V_8 == NULL ) {
F_37 ( & V_72 -> V_2 , L_15 ) ;
goto V_86;
}
V_75 -> V_41 = F_40 ( V_72 , 3 , 0 ) ;
if ( V_75 -> V_41 == NULL ) {
F_37 ( & V_72 -> V_2 , L_16 ) ;
goto V_87;
}
F_41 ( & V_75 -> V_57 ) ;
F_42 ( & V_75 -> V_28 ) ;
F_43 ( & V_75 -> V_60 ) ;
F_44 ( & V_75 -> V_55 , & V_88 ) ;
V_75 -> V_55 . V_89 = V_90 ;
F_4 ( 0 , V_75 -> V_10 + V_11 ) ;
F_5 ( V_75 -> V_10 + V_11 ) ;
V_77 = F_45 ( V_72 -> V_64 , F_29 ,
V_91 | V_92 , L_11 , V_75 ) ;
if ( V_77 ) {
F_37 ( & V_72 -> V_2 , L_17 ) ;
goto V_93;
}
V_77 = F_46 ( & V_75 -> V_55 , F_47 ( V_94 , V_76 ) , 1 ) ;
if ( V_77 ) {
F_37 ( & V_72 -> V_2 , L_18 ) ;
goto V_95;
}
if ( F_48 ( F_49 ( V_96 , & V_72 -> V_2 ,
F_47 ( V_94 , V_76 ) , NULL ,
L_19 , V_76 ) ) )
F_37 ( & V_72 -> V_2 , L_20 ) ;
F_50 ( V_72 , V_75 ) ;
return 0 ;
V_95:
F_51 ( V_72 -> V_64 , V_75 ) ;
V_93:
F_52 ( V_72 , V_75 -> V_41 ) ;
V_87:
F_52 ( V_72 , V_75 -> V_8 ) ;
V_86:
F_52 ( V_72 , V_75 -> V_10 ) ;
V_85:
F_53 ( V_75 ) ;
V_84:
F_54 ( V_72 ) ;
V_81:
V_70 [ V_76 ] = 0 ;
V_80:
F_55 ( V_72 ) ;
V_78:
return V_77 ;
}
static void T_6 F_56 ( struct V_71 * V_72 )
{
struct V_1 * V_75 = F_57 ( V_72 ) ;
unsigned int V_76 = F_58 ( V_75 -> V_55 . V_2 ) ;
F_59 ( V_96 , F_47 ( V_94 , V_76 ) ) ;
F_60 ( & V_75 -> V_55 ) ;
F_4 ( 0 , V_75 -> V_10 + V_11 ) ;
F_5 ( V_75 -> V_10 + V_11 ) ;
F_51 ( V_72 -> V_64 , V_75 ) ;
F_52 ( V_72 , V_75 -> V_41 ) ;
F_52 ( V_72 , V_75 -> V_8 ) ;
F_52 ( V_72 , V_75 -> V_10 ) ;
F_53 ( V_75 ) ;
F_54 ( V_72 ) ;
V_70 [ V_76 ] = 0 ;
F_55 ( V_72 ) ;
}
static int F_61 ( struct V_71 * V_72 , T_7 V_97 )
{
struct V_1 * V_2 = F_57 ( V_72 ) ;
F_4 ( 0 , V_2 -> V_10 + V_11 ) ;
F_5 ( V_2 -> V_10 + V_11 ) ;
F_62 ( V_72 -> V_64 ) ;
return 0 ;
}
static int F_63 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_57 ( V_72 ) ;
F_4 ( 0 , V_2 -> V_10 + V_11 ) ;
return 0 ;
}
static int T_8 F_64 ( void )
{
int V_77 ;
T_9 V_2 ;
V_96 = F_65 ( V_90 , L_11 ) ;
if ( F_48 ( V_96 ) ) {
V_77 = F_66 ( V_96 ) ;
F_13 ( V_47 L_21 ) ;
goto V_78;
}
V_77 = F_67 ( V_96 , & V_98 . V_99 ) ;
if ( V_77 ) {
F_13 ( V_47 L_22 ) ;
goto V_100;
}
V_77 = F_68 ( & V_2 , 0 , V_69 , L_11 ) ;
if ( V_77 ) {
F_13 ( V_47 L_23 ) ;
goto V_101;
}
V_94 = F_69 ( V_2 ) ;
V_77 = F_70 ( & V_102 ) ;
if ( V_77 ) {
F_13 ( V_47 L_24 ) ;
goto V_103;
}
F_13 ( V_104 L_25 V_105 L_26
L_27 ) ;
return 0 ;
V_103:
F_71 ( V_2 , V_69 ) ;
V_101:
F_72 ( V_96 , & V_98 . V_99 ) ;
V_100:
F_73 ( V_96 ) ;
V_78:
return V_77 ;
}
static void T_10 F_74 ( void )
{
F_75 ( & V_102 ) ;
F_71 ( F_47 ( V_94 , 0 ) , V_69 ) ;
F_72 ( V_96 , & V_98 . V_99 ) ;
F_73 ( V_96 ) ;
F_2 ( L_28 ) ;
}
