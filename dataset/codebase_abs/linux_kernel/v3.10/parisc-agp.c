static int
F_1 ( void )
{
int V_1 ;
V_1 = V_2 . V_3 / F_2 ( 1 ) ;
V_4 [ 0 ] . V_1 = V_1 ;
V_5 -> V_6 = ( void * ) & V_4 [ 0 ] ;
return V_1 ;
}
static int
F_3 ( void )
{
struct V_7 * V_8 = & V_2 ;
V_5 -> V_9 = V_8 -> V_10 ;
V_5 -> V_11 = V_8 -> V_12 ;
V_5 -> V_13 = F_4 ( V_8 -> V_14 + V_8 -> V_12 + V_15 ) ;
return 0 ;
}
static void
F_5 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = & V_2 ;
F_6 ( V_8 -> V_10 | F_7 ( V_8 -> V_3 ) , V_8 -> V_18 + V_19 ) ;
F_8 ( V_8 -> V_18 + V_19 ) ;
}
static int
F_9 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = & V_2 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_8 -> V_23 ; V_22 ++ ) {
V_8 -> V_24 [ V_22 ] = ( unsigned long ) V_5 -> V_25 ;
}
return 0 ;
}
static int
F_10 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = & V_2 ;
V_8 -> V_24 [ 0 ] = V_26 ;
return 0 ;
}
static int
F_11 ( struct V_16 * V_17 , T_1 V_27 , int type )
{
struct V_7 * V_8 = & V_2 ;
int V_22 , V_28 ;
T_1 V_29 , V_30 ;
int V_31 ;
if ( type != 0 || V_17 -> type != 0 ) {
return - V_32 ;
}
V_30 = V_8 -> V_33 * V_27 ;
V_31 = V_8 -> V_33 * V_17 -> V_34 ;
if ( ( V_30 + V_31 ) > V_8 -> V_23 ) {
return - V_32 ;
}
V_29 = V_30 ;
while ( V_29 < ( V_30 + V_31 ) ) {
if ( V_8 -> V_24 [ V_29 ] )
return - V_35 ;
V_29 ++ ;
}
if ( ! V_17 -> V_36 ) {
F_12 () ;
V_17 -> V_36 = true ;
}
for ( V_22 = 0 , V_29 = V_30 ; V_22 < V_17 -> V_34 ; V_22 ++ ) {
unsigned long V_37 ;
V_37 = F_13 ( V_17 -> V_38 [ V_22 ] ) ;
for ( V_28 = 0 ;
V_28 < V_8 -> V_33 ;
V_28 ++ , V_29 ++ , V_37 += V_8 -> V_39 ) {
V_8 -> V_24 [ V_29 ] =
F_14 ( V_5 ,
V_37 , type ) ;
}
}
V_5 -> V_40 -> V_41 ( V_17 ) ;
return 0 ;
}
static int
F_15 ( struct V_16 * V_17 , T_1 V_27 , int type )
{
struct V_7 * V_8 = & V_2 ;
int V_22 , V_30 , V_31 ;
if ( type != 0 || V_17 -> type != 0 ) {
return - V_32 ;
}
V_30 = V_8 -> V_33 * V_27 ;
V_31 = V_8 -> V_33 * V_17 -> V_34 ;
for ( V_22 = V_30 ; V_22 < V_31 + V_30 ; V_22 ++ ) {
V_8 -> V_24 [ V_22 ] = V_5 -> V_25 ;
}
V_5 -> V_40 -> V_41 ( V_17 ) ;
return 0 ;
}
static unsigned long
F_14 ( struct V_20 * V_21 , T_2 V_42 ,
int type )
{
return V_43 | V_42 ;
}
static void
F_16 ( struct V_20 * V_21 , T_3 V_13 )
{
struct V_7 * V_8 = & V_2 ;
T_3 V_44 ;
V_44 = F_4 ( V_8 -> V_14 + V_8 -> V_12 + V_15 ) ;
V_44 = F_17 ( V_21 , V_13 , V_44 ) ;
V_44 |= 0x00000100 ;
F_18 ( V_44 , V_8 -> V_14 + V_8 -> V_12 + V_45 ) ;
F_19 ( V_44 , ( V_13 & V_46 ) != 0 ) ;
}
static int T_4
F_20 ( void T_5 * V_18 )
{
struct V_7 * V_8 = & V_2 ;
T_6 V_47 , * V_48 , V_49 ;
int V_50 ;
F_21 (KERN_INFO DRVPFX L_1 ) ;
V_8 -> V_18 = V_18 ;
V_49 = F_8 ( V_8 -> V_18 + V_51 ) ;
switch ( V_49 ) {
case 0 : V_50 = 12 ; break;
case 1 : V_50 = 13 ; break;
case 2 : V_50 = 14 ; break;
case 3 : V_50 = 16 ; break;
default:
F_21 (KERN_ERR DRVPFX L_2
L_3 , io_tlb_ps) ;
V_8 -> V_24 = NULL ;
V_8 -> V_23 = 0 ;
return - V_52 ;
}
V_8 -> V_39 = 1 << V_50 ;
V_8 -> V_33 = V_53 / V_8 -> V_39 ;
V_47 = F_8 ( V_8 -> V_18 + V_54 ) & ~ 0x1 ;
V_8 -> V_10 = V_47 + V_55 - V_56 ;
V_8 -> V_3 = V_56 ;
V_8 -> V_23 = V_8 -> V_3 / V_8 -> V_39 ;
V_48 = F_22 ( F_8 ( V_8 -> V_18 + V_57 ) ) ;
V_8 -> V_24 = & V_48 [ ( V_55 / 2 ) >> V_58 ] ;
if ( V_8 -> V_24 [ 0 ] != V_26 ) {
V_8 -> V_24 = NULL ;
V_8 -> V_23 = 0 ;
F_21 (KERN_ERR DRVPFX L_4
L_5 ) ;
return - V_52 ;
}
return 0 ;
}
static int
F_23 ( int V_59 )
{
struct V_7 * V_8 = & V_2 ;
T_7 V_60 ;
T_8 V_61 , V_62 ;
int V_63 = 48 ;
V_60 = F_24 ( V_8 -> V_14 + V_64 ) ;
if ( ! ( V_60 & V_65 ) )
return 0 ;
V_61 = F_25 ( V_8 -> V_14 + V_66 ) ;
while ( V_63 -- && V_61 >= 0x40 ) {
V_61 &= ~ 3 ;
V_62 = F_25 ( V_8 -> V_14 + V_61 + V_67 ) ;
if ( V_62 == 0xff )
break;
if ( V_62 == V_59 )
return V_61 ;
V_61 = F_25 ( V_8 -> V_14 + V_61 + V_68 ) ;
}
return 0 ;
}
static int T_4
F_26 ( void T_5 * V_69 )
{
struct V_7 * V_8 = & V_2 ;
int V_59 ;
V_8 -> V_14 = V_69 ;
V_8 -> V_12 = F_23 ( V_70 ) ;
V_59 = F_4 ( V_69 + V_8 -> V_12 ) & 0xff ;
if ( V_59 != V_70 ) {
F_21 (KERN_ERR DRVPFX L_6 ,
cap, info->lba_cap_offset) ;
return - V_52 ;
}
return 0 ;
}
static int T_4
F_27 ( void T_5 * V_71 , void T_5 * V_69 )
{
struct V_72 * V_73 = NULL ;
struct V_20 * V_21 ;
int error = 0 ;
V_73 = F_28 () ;
if ( ! V_73 ) {
error = - V_74 ;
goto V_75;
}
error = F_20 ( V_71 ) ;
if ( error )
goto V_75;
error = F_26 ( V_69 ) ;
if ( error )
goto V_75;
V_21 = F_29 () ;
if ( ! V_21 ) {
error = - V_74 ;
goto V_75;
}
V_21 -> V_40 = & V_76 ;
V_73 -> V_77 = V_78 ;
V_73 -> V_79 = V_80 ;
V_21 -> V_81 = V_73 ;
error = F_30 ( V_21 ) ;
if ( error )
goto V_75;
return 0 ;
V_75:
F_31 ( V_73 ) ;
return error ;
}
static int
F_32 ( struct V_79 * V_81 , void * V_82 )
{
struct V_83 * * V_84 = V_82 ;
struct V_83 * V_85 = F_33 ( V_81 ) ;
if ( F_34 ( V_85 ) )
* V_84 = V_85 ;
return 0 ;
}
static int
F_35 ( void )
{
extern struct V_86 * V_87 ;
int V_88 = - 1 ;
struct V_83 * V_89 = NULL , * V_84 = NULL ;
struct V_90 * V_91 = NULL ;
if ( ! V_87 )
goto V_92;
V_89 = V_87 -> V_81 ;
if ( ! F_36 ( V_89 ) ) {
F_21 (KERN_INFO DRVPFX L_7 ) ;
goto V_92;
}
F_37 ( & V_89 -> V_81 , & V_84 , F_32 ) ;
if ( ! V_84 ) {
F_21 (KERN_INFO DRVPFX L_8 ) ;
goto V_92;
}
V_91 = F_38 ( V_84 ) ;
F_27 ( V_87 -> V_93 [ 0 ] . V_71 , V_91 -> V_94 . V_95 ) ;
return 0 ;
V_92:
return V_88 ;
}
