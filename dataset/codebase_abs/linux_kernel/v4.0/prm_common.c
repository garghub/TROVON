static void F_1 ( unsigned long * V_1 ,
unsigned long * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
V_2 [ V_3 ] =
V_1 [ V_3 ] & V_4 -> V_6 [ V_3 ] ;
V_1 [ V_3 ] ^= V_2 [ V_3 ] ;
}
}
static void F_2 ( unsigned int V_7 , struct V_8 * V_9 )
{
unsigned long V_10 [ V_11 ] ;
unsigned long V_12 [ V_11 ] ;
struct V_13 * V_14 = F_3 ( V_9 ) ;
unsigned int V_15 ;
int V_16 = V_4 -> V_5 * 32 ;
if ( V_4 -> V_17 ) {
V_4 -> V_18 ( V_4 -> V_19 ) ;
V_4 -> V_20 = true ;
}
while ( ! V_4 -> V_17 ) {
V_4 -> V_21 ( V_10 ) ;
if ( F_4 ( V_10 , V_16 ) >= V_16 )
break;
F_1 ( V_10 , V_12 ) ;
F_5 (virtirq, priority_pending, nr_irq)
F_6 ( V_4 -> V_22 + V_15 ) ;
F_5 (virtirq, pending, nr_irq)
F_6 ( V_4 -> V_22 + V_15 ) ;
}
if ( V_14 -> V_23 )
V_14 -> V_23 ( & V_9 -> V_24 ) ;
if ( V_14 -> V_25 )
V_14 -> V_25 ( & V_9 -> V_24 ) ;
V_14 -> V_26 ( & V_9 -> V_24 ) ;
V_4 -> V_27 () ;
}
int F_7 ( const char * V_28 )
{
int V_3 ;
if ( ! V_4 || ! V_28 )
return - V_29 ;
for ( V_3 = 0 ; V_3 < V_4 -> V_30 ; V_3 ++ )
if ( ! strcmp ( V_4 -> V_31 [ V_3 ] . V_28 , V_28 ) )
return V_4 -> V_22 +
V_4 -> V_31 [ V_3 ] . V_32 ;
return - V_29 ;
}
void F_8 ( void )
{
unsigned int V_7 ;
int V_3 ;
if ( ! V_4 ) {
F_9 ( L_1 ) ;
return;
}
if ( V_33 ) {
for ( V_3 = 0 ; V_3 < V_4 -> V_5 ; V_3 ++ ) {
if ( V_33 [ V_3 ] )
F_10 ( V_33 [ V_3 ] ,
0xffffffff , 0 , 0 ) ;
V_33 [ V_3 ] = NULL ;
}
F_11 ( V_33 ) ;
V_33 = NULL ;
}
F_11 ( V_4 -> V_19 ) ;
V_4 -> V_19 = NULL ;
F_11 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
if ( V_4 -> V_34 )
V_7 = V_4 -> V_34 ( V_4 -> V_7 ) ;
else
V_7 = V_4 -> V_7 ;
F_12 ( V_7 , NULL ) ;
if ( V_4 -> V_22 > 0 )
F_13 ( V_4 -> V_22 ,
V_4 -> V_5 * 32 ) ;
V_4 -> V_22 = 0 ;
}
void F_14 ( void )
{
V_4 -> V_17 = true ;
}
void F_15 ( void )
{
V_4 -> V_17 = false ;
if ( ! V_4 -> V_20 )
return;
V_4 -> V_20 = false ;
V_4 -> V_35 ( V_4 -> V_19 ) ;
}
int F_16 ( struct V_36 * V_37 )
{
int V_5 ;
T_1 V_38 [ V_11 ] ;
int V_32 , V_3 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
unsigned int V_7 ;
if ( ! V_37 )
return - V_43 ;
V_5 = V_37 -> V_5 ;
if ( V_4 ) {
F_9 ( L_2 ) ;
return - V_43 ;
}
if ( V_5 > V_11 ) {
F_9 ( L_3 ) ;
return - V_43 ;
}
V_4 = V_37 ;
V_33 = F_17 ( sizeof( void * ) * V_5 , V_44 ) ;
V_4 -> V_19 = F_17 ( sizeof( T_1 ) * V_5 , V_44 ) ;
V_4 -> V_6 = F_17 ( sizeof( T_1 ) * V_5 ,
V_44 ) ;
if ( ! V_33 || ! V_4 -> V_19 ||
! V_4 -> V_6 ) {
F_9 ( L_4 ) ;
goto V_45;
}
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
for ( V_3 = 0 ; V_3 < V_37 -> V_30 ; V_3 ++ ) {
V_32 = V_37 -> V_31 [ V_3 ] . V_32 ;
V_38 [ V_32 >> 5 ] |= 1 << ( V_32 & 0x1f ) ;
if ( V_37 -> V_31 [ V_3 ] . V_46 )
V_37 -> V_6 [ V_32 >> 5 ] |=
1 << ( V_32 & 0x1f ) ;
}
if ( V_37 -> V_34 )
V_7 = V_37 -> V_34 ( V_37 -> V_7 ) ;
else
V_7 = V_37 -> V_7 ;
F_12 ( V_7 , F_2 ) ;
V_37 -> V_22 = F_18 ( - 1 , 0 , V_37 -> V_5 * 32 ,
0 ) ;
if ( V_37 -> V_22 < 0 ) {
F_9 ( L_5 ,
V_37 -> V_22 ) ;
goto V_45;
}
for ( V_3 = 0 ; V_3 < V_37 -> V_5 ; V_3 ++ ) {
V_40 = F_19 ( L_6 , 1 ,
V_37 -> V_22 + V_3 * 32 , V_47 ,
V_48 ) ;
if ( ! V_40 ) {
F_9 ( L_7 ) ;
goto V_45;
}
V_42 = V_40 -> V_49 ;
V_42 -> V_14 . V_23 = V_50 ;
V_42 -> V_14 . V_51 = V_52 ;
V_42 -> V_14 . V_26 = V_53 ;
V_42 -> V_54 . V_55 = V_37 -> V_55 + V_3 * 4 ;
V_42 -> V_54 . V_38 = V_37 -> V_38 + V_3 * 4 ;
F_20 ( V_40 , V_38 [ V_3 ] , 0 , V_56 , 0 ) ;
V_33 [ V_3 ] = V_40 ;
}
if ( F_21 () ) {
int V_7 = F_7 ( L_8 ) ;
F_22 ( V_7 , V_37 -> V_57 ) ;
}
return 0 ;
V_45:
F_8 () ;
return - V_58 ;
}
void T_2 F_23 ( void T_3 * V_59 )
{
V_47 = V_59 ;
}
T_1 F_24 ( void )
{
T_1 V_60 = 1 << V_61 ;
if ( V_62 -> V_63 )
V_60 = V_62 -> V_63 () ;
else
F_25 ( 1 , L_9 , V_64 ) ;
return V_60 ;
}
bool F_26 ( T_4 V_65 , T_5 V_66 , T_6 V_67 )
{
bool V_60 = true ;
if ( V_62 -> V_68 )
V_60 = V_62 -> V_68 ( V_65 , V_66 , V_67 ) ;
else
F_25 ( 1 , L_10 ,
V_64 ) ;
return V_60 ;
}
void F_27 ( T_4 V_65 , T_5 V_66 , T_6 V_67 )
{
if ( V_62 -> V_69 )
V_62 -> V_69 ( V_65 , V_66 , V_67 ) ;
else
F_25 ( 1 , L_10 ,
V_64 ) ;
}
int F_28 ( T_4 V_70 , T_4 V_65 , T_5 V_71 , T_6 V_32 )
{
if ( ! V_62 -> V_72 ) {
F_25 ( 1 , L_10 ,
V_64 ) ;
return - V_43 ;
}
return V_62 -> V_72 ( V_70 , V_65 , V_71 , V_32 ) ;
}
int F_29 ( T_4 V_70 , T_4 V_73 , T_4 V_65 , T_5 V_71 ,
T_6 V_32 , T_6 V_74 )
{
if ( ! V_62 -> V_75 ) {
F_25 ( 1 , L_10 ,
V_64 ) ;
return - V_43 ;
}
return V_62 -> V_75 ( V_70 , V_73 , V_65 , V_71 ,
V_32 , V_74 ) ;
}
int F_30 ( T_4 V_70 , T_4 V_65 , T_5 V_71 , T_6 V_32 )
{
if ( ! V_62 -> V_76 ) {
F_25 ( 1 , L_10 ,
V_64 ) ;
return - V_43 ;
}
return V_62 -> V_76 ( V_70 , V_65 , V_71 , V_32 ) ;
}
void F_31 ( void )
{
if ( ! V_4 || ! V_4 -> V_57 )
return;
V_4 -> V_57 () ;
}
void F_32 ( void )
{
if ( ! V_62 -> V_77 ) {
F_25 ( 1 , L_10 ,
V_64 ) ;
return;
}
V_62 -> V_77 () ;
while ( 1 )
F_33 () ;
}
int F_34 ( struct V_62 * V_78 )
{
if ( ! V_78 )
return - V_43 ;
if ( V_62 != & V_79 )
return - V_80 ;
V_62 = V_78 ;
return 0 ;
}
int F_35 ( struct V_62 * V_78 )
{
if ( ! V_78 || V_62 != V_78 )
return - V_43 ;
V_62 = & V_79 ;
return 0 ;
}
static T_1 F_36 ( void T_3 * V_81 )
{
return F_37 ( & V_82 , V_81 ) ;
}
static void F_38 ( T_1 V_83 , void T_3 * V_81 )
{
F_39 ( V_83 , & V_82 , V_81 ) ;
}
int T_2 F_40 ( void )
{
struct V_84 * V_85 ;
void T_3 * V_86 ;
int V_87 = 0 ;
V_88 = & V_89 ;
F_41 (np, omap_prcm_dt_match_table) {
V_86 = F_42 ( V_85 , 0 ) ;
V_90 [ V_87 ] = V_86 ;
F_43 ( V_85 , V_87 ) ;
V_87 ++ ;
}
return 0 ;
}
void T_2 F_44 ( void )
{
V_88 = & V_89 ;
V_90 [ V_91 ] = V_92 + V_93 ;
V_90 [ V_94 ] = V_47 + V_93 ;
V_90 [ V_95 ] = F_45 () ;
}
static int T_2 F_46 ( void )
{
if ( V_62 -> V_96 )
return V_62 -> V_96 () ;
return 0 ;
}
