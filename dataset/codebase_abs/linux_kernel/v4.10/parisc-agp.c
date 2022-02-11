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
if ( type != V_17 -> type ||
V_5 -> V_32 -> V_33 ( V_5 , type ) ) {
return - V_34 ;
}
V_30 = V_8 -> V_35 * V_27 ;
V_31 = V_8 -> V_35 * V_17 -> V_36 ;
if ( ( V_30 + V_31 ) > V_8 -> V_23 ) {
return - V_34 ;
}
V_29 = V_30 ;
while ( V_29 < ( V_30 + V_31 ) ) {
if ( V_8 -> V_24 [ V_29 ] )
return - V_37 ;
V_29 ++ ;
}
if ( ! V_17 -> V_38 ) {
F_12 () ;
V_17 -> V_38 = true ;
}
for ( V_22 = 0 , V_29 = V_30 ; V_22 < V_17 -> V_36 ; V_22 ++ ) {
unsigned long V_39 ;
V_39 = F_13 ( V_17 -> V_40 [ V_22 ] ) ;
for ( V_28 = 0 ;
V_28 < V_8 -> V_35 ;
V_28 ++ , V_29 ++ , V_39 += V_8 -> V_41 ) {
V_8 -> V_24 [ V_29 ] =
F_14 ( V_5 ,
V_39 , type ) ;
}
}
V_5 -> V_32 -> V_42 ( V_17 ) ;
return 0 ;
}
static int
F_15 ( struct V_16 * V_17 , T_1 V_27 , int type )
{
struct V_7 * V_8 = & V_2 ;
int V_22 , V_30 , V_31 ;
if ( type != V_17 -> type ||
V_5 -> V_32 -> V_33 ( V_5 , type ) ) {
return - V_34 ;
}
V_30 = V_8 -> V_35 * V_27 ;
V_31 = V_8 -> V_35 * V_17 -> V_36 ;
for ( V_22 = V_30 ; V_22 < V_31 + V_30 ; V_22 ++ ) {
V_8 -> V_24 [ V_22 ] = V_5 -> V_25 ;
}
V_5 -> V_32 -> V_42 ( V_17 ) ;
return 0 ;
}
static unsigned long
F_14 ( struct V_20 * V_21 , T_2 V_43 ,
int type )
{
return V_44 | V_43 ;
}
static void
F_16 ( struct V_20 * V_21 , T_3 V_13 )
{
struct V_7 * V_8 = & V_2 ;
T_3 V_45 ;
V_45 = F_4 ( V_8 -> V_14 + V_8 -> V_12 + V_15 ) ;
V_45 = F_17 ( V_21 , V_13 , V_45 ) ;
V_45 |= 0x00000100 ;
F_18 ( V_45 , V_8 -> V_14 + V_8 -> V_12 + V_46 ) ;
F_19 ( V_45 , ( V_13 & V_47 ) != 0 ) ;
}
static int T_4
F_20 ( void T_5 * V_18 )
{
struct V_7 * V_8 = & V_2 ;
T_6 V_48 , * V_49 , V_50 ;
int V_51 ;
F_21 (KERN_INFO DRVPFX L_1 ) ;
V_8 -> V_18 = V_18 ;
V_50 = F_8 ( V_8 -> V_18 + V_52 ) ;
switch ( V_50 ) {
case 0 : V_51 = 12 ; break;
case 1 : V_51 = 13 ; break;
case 2 : V_51 = 14 ; break;
case 3 : V_51 = 16 ; break;
default:
F_21 (KERN_ERR DRVPFX L_2
L_3 , io_tlb_ps) ;
V_8 -> V_24 = NULL ;
V_8 -> V_23 = 0 ;
return - V_53 ;
}
V_8 -> V_41 = 1 << V_51 ;
V_8 -> V_35 = V_54 / V_8 -> V_41 ;
V_48 = F_8 ( V_8 -> V_18 + V_55 ) & ~ 0x1 ;
V_8 -> V_10 = V_48 + V_56 - V_57 ;
V_8 -> V_3 = V_57 ;
V_8 -> V_23 = V_8 -> V_3 / V_8 -> V_41 ;
V_49 = F_22 ( F_8 ( V_8 -> V_18 + V_58 ) ) ;
V_8 -> V_24 = & V_49 [ ( V_56 / 2 ) >> V_59 ] ;
if ( V_8 -> V_24 [ 0 ] != V_26 ) {
V_8 -> V_24 = NULL ;
V_8 -> V_23 = 0 ;
F_21 (KERN_ERR DRVPFX L_4
L_5 ) ;
return - V_53 ;
}
return 0 ;
}
static int
F_23 ( int V_60 )
{
struct V_7 * V_8 = & V_2 ;
T_7 V_61 ;
T_8 V_62 , V_63 ;
int V_64 = 48 ;
V_61 = F_24 ( V_8 -> V_14 + V_65 ) ;
if ( ! ( V_61 & V_66 ) )
return 0 ;
V_62 = F_25 ( V_8 -> V_14 + V_67 ) ;
while ( V_64 -- && V_62 >= 0x40 ) {
V_62 &= ~ 3 ;
V_63 = F_25 ( V_8 -> V_14 + V_62 + V_68 ) ;
if ( V_63 == 0xff )
break;
if ( V_63 == V_60 )
return V_62 ;
V_62 = F_25 ( V_8 -> V_14 + V_62 + V_69 ) ;
}
return 0 ;
}
static int T_4
F_26 ( void T_5 * V_70 )
{
struct V_7 * V_8 = & V_2 ;
int V_60 ;
V_8 -> V_14 = V_70 ;
V_8 -> V_12 = F_23 ( V_71 ) ;
V_60 = F_4 ( V_70 + V_8 -> V_12 ) & 0xff ;
if ( V_60 != V_71 ) {
F_21 (KERN_ERR DRVPFX L_6 ,
cap, info->lba_cap_offset) ;
return - V_53 ;
}
return 0 ;
}
static int T_4
F_27 ( void T_5 * V_72 , void T_5 * V_70 )
{
struct V_73 * V_74 = NULL ;
struct V_20 * V_21 ;
int error = 0 ;
V_74 = F_28 ( NULL ) ;
if ( ! V_74 ) {
error = - V_75 ;
goto V_76;
}
error = F_20 ( V_72 ) ;
if ( error )
goto V_76;
error = F_26 ( V_70 ) ;
if ( error )
goto V_76;
V_21 = F_29 () ;
if ( ! V_21 ) {
error = - V_75 ;
goto V_76;
}
V_21 -> V_32 = & V_77 ;
V_74 -> V_78 = V_79 ;
V_74 -> V_80 = V_81 ;
V_21 -> V_82 = V_74 ;
error = F_30 ( V_21 ) ;
if ( error )
goto V_76;
return 0 ;
V_76:
F_31 ( V_74 ) ;
return error ;
}
static int
F_32 ( struct V_80 * V_82 , void * V_83 )
{
struct V_84 * * V_85 = V_83 ;
struct V_84 * V_86 = F_33 ( V_82 ) ;
if ( F_34 ( V_86 ) )
* V_85 = V_86 ;
return 0 ;
}
static int
F_35 ( void )
{
extern struct V_87 * V_88 ;
int V_89 = - 1 ;
struct V_84 * V_90 = NULL , * V_85 = NULL ;
struct V_91 * V_92 = NULL ;
if ( ! V_88 )
goto V_93;
V_90 = V_88 -> V_82 ;
if ( ! F_36 ( V_90 ) ) {
F_21 (KERN_INFO DRVPFX L_7 ) ;
goto V_93;
}
F_37 ( & V_90 -> V_82 , & V_85 , F_32 ) ;
if ( ! V_85 ) {
F_21 (KERN_INFO DRVPFX L_8 ) ;
goto V_93;
}
V_92 = F_38 ( V_85 ) ;
F_27 ( V_88 -> V_94 [ 0 ] . V_72 , V_92 -> V_95 . V_96 ) ;
return 0 ;
V_93:
return V_89 ;
}
