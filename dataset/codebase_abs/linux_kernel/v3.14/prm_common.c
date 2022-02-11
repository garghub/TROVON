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
F_12 ( V_4 -> V_7 , NULL ) ;
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
V_4 -> V_34 ( V_4 -> V_19 ) ;
}
int F_16 ( struct V_35 * V_36 )
{
int V_5 ;
T_1 V_37 [ V_11 ] ;
int V_32 , V_3 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
if ( ! V_36 )
return - V_42 ;
V_5 = V_36 -> V_5 ;
if ( V_4 ) {
F_9 ( L_2 ) ;
return - V_42 ;
}
if ( V_5 > V_11 ) {
F_9 ( L_3 ) ;
return - V_42 ;
}
V_4 = V_36 ;
V_33 = F_17 ( sizeof( void * ) * V_5 , V_43 ) ;
V_4 -> V_19 = F_17 ( sizeof( T_1 ) * V_5 , V_43 ) ;
V_4 -> V_6 = F_17 ( sizeof( T_1 ) * V_5 ,
V_43 ) ;
if ( ! V_33 || ! V_4 -> V_19 ||
! V_4 -> V_6 ) {
F_9 ( L_4 ) ;
goto V_44;
}
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
for ( V_3 = 0 ; V_3 < V_36 -> V_30 ; V_3 ++ ) {
V_32 = V_36 -> V_31 [ V_3 ] . V_32 ;
V_37 [ V_32 >> 5 ] |= 1 << ( V_32 & 0x1f ) ;
if ( V_36 -> V_31 [ V_3 ] . V_45 )
V_36 -> V_6 [ V_32 >> 5 ] |=
1 << ( V_32 & 0x1f ) ;
}
F_12 ( V_36 -> V_7 , F_2 ) ;
V_36 -> V_22 = F_18 ( - 1 , 0 , V_36 -> V_5 * 32 ,
0 ) ;
if ( V_36 -> V_22 < 0 ) {
F_9 ( L_5 ,
V_36 -> V_22 ) ;
goto V_44;
}
for ( V_3 = 0 ; V_3 < V_36 -> V_5 ; V_3 ++ ) {
V_39 = F_19 ( L_6 , 1 ,
V_36 -> V_22 + V_3 * 32 , V_46 ,
V_47 ) ;
if ( ! V_39 ) {
F_9 ( L_7 ) ;
goto V_44;
}
V_41 = V_39 -> V_48 ;
V_41 -> V_14 . V_23 = V_49 ;
V_41 -> V_14 . V_50 = V_51 ;
V_41 -> V_14 . V_26 = V_52 ;
V_41 -> V_53 . V_54 = V_36 -> V_54 + V_3 * 4 ;
V_41 -> V_53 . V_37 = V_36 -> V_37 + V_3 * 4 ;
F_20 ( V_39 , V_37 [ V_3 ] , 0 , V_55 , 0 ) ;
V_33 [ V_3 ] = V_39 ;
}
if ( F_21 () ) {
int V_7 = F_7 ( L_8 ) ;
if ( F_22 () )
F_23 ( V_7 ,
V_56 ) ;
else
F_23 ( V_7 ,
V_57 ) ;
}
return 0 ;
V_44:
F_8 () ;
return - V_58 ;
}
void T_2 F_24 ( void T_3 * V_59 )
{
V_46 = V_59 ;
}
T_1 F_25 ( void )
{
T_1 V_60 = 1 << V_61 ;
if ( V_62 -> V_63 )
V_60 = V_62 -> V_63 () ;
else
F_26 ( 1 , L_9 , V_64 ) ;
return V_60 ;
}
bool F_27 ( T_4 V_65 , T_5 V_66 , T_6 V_67 )
{
bool V_60 = true ;
if ( V_62 -> V_68 )
V_60 = V_62 -> V_68 ( V_65 , V_66 , V_67 ) ;
else
F_26 ( 1 , L_10 ,
V_64 ) ;
return V_60 ;
}
void F_28 ( T_4 V_65 , T_5 V_66 , T_6 V_67 )
{
if ( V_62 -> V_69 )
V_62 -> V_69 ( V_65 , V_66 , V_67 ) ;
else
F_26 ( 1 , L_10 ,
V_64 ) ;
}
int F_29 ( struct V_62 * V_70 )
{
if ( ! V_70 )
return - V_42 ;
if ( V_62 != & V_71 )
return - V_72 ;
V_62 = V_70 ;
return 0 ;
}
int F_30 ( struct V_62 * V_70 )
{
if ( ! V_70 || V_62 != V_70 )
return - V_42 ;
V_62 = & V_71 ;
return 0 ;
}
static T_1 F_31 ( void T_3 * V_73 )
{
return F_32 ( & V_74 , V_73 ) ;
}
static void F_33 ( T_1 V_75 , void T_3 * V_73 )
{
F_34 ( V_75 , & V_74 , V_73 ) ;
}
int T_2 F_35 ( void )
{
struct V_76 * V_77 ;
void T_3 * V_78 ;
int V_79 = 0 ;
V_80 = & V_81 ;
F_36 (np, omap_prcm_dt_match_table) {
V_78 = F_37 ( V_77 , 0 ) ;
V_82 [ V_79 ] = V_78 ;
F_38 ( V_77 , V_79 ) ;
V_79 ++ ;
}
F_39 () ;
return 0 ;
}
