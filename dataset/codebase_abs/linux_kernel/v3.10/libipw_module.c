static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_2 -> V_6 [ V_3 ] = F_2 ( sizeof( struct V_7 ) ,
V_8 ) ;
if ( ! V_2 -> V_6 [ V_3 ] ) {
F_3 ( L_1 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_4 ( V_2 -> V_6 [ V_4 ] ) ;
return - V_9 ;
}
}
return 0 ;
}
void F_5 ( struct V_7 * V_10 )
{
if ( ! V_10 )
return;
if ( V_10 -> V_11 ) {
F_4 ( V_10 -> V_11 ) ;
V_10 -> V_11 = NULL ;
}
}
static inline void F_6 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
if ( V_2 -> V_6 [ V_3 ] -> V_11 )
F_4 ( V_2 -> V_6 [ V_3 ] -> V_11 ) ;
F_4 ( V_2 -> V_6 [ V_3 ] ) ;
}
}
void F_7 ( struct V_1 * V_2 ,
unsigned long V_12 )
{
struct V_7 * V_10 = NULL ;
unsigned long V_13 ;
unsigned long V_14 = F_8 ( V_12 * V_15 ) ;
F_9 ( & V_2 -> V_16 , V_13 ) ;
F_10 (network, &ieee->network_list, list) {
V_10 -> V_17 -= V_14 ;
}
F_11 ( & V_2 -> V_16 , V_13 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_3 ;
F_13 ( & V_2 -> V_18 ) ;
F_13 ( & V_2 -> V_19 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
F_14 ( & V_2 -> V_6 [ V_3 ] -> V_20 ,
& V_2 -> V_18 ) ;
}
int F_15 ( struct V_21 * V_22 , int V_23 )
{
if ( ( V_23 < 68 ) || ( V_23 > V_24 ) )
return - V_25 ;
V_22 -> V_26 = V_23 ;
return 0 ;
}
struct V_21 * F_16 ( int V_27 , int V_28 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 ;
int V_29 ;
F_17 ( L_2 ) ;
V_22 = F_18 ( sizeof( struct V_1 ) + V_27 ) ;
if ( ! V_22 )
goto V_30;
V_2 = F_19 ( V_22 ) ;
V_2 -> V_22 = V_22 ;
if ( ! V_28 ) {
V_2 -> V_31 . V_32 = F_20 ( & V_33 , 0 ) ;
if ( ! V_2 -> V_31 . V_32 ) {
F_3 ( L_3 ) ;
goto V_34;
}
V_2 -> V_22 -> V_35 = & V_2 -> V_31 ;
V_2 -> V_31 . V_36 = V_37 ;
V_2 -> V_31 . V_32 -> V_38 = V_39 ;
V_2 -> V_31 . V_32 -> V_40 = 1 ;
V_2 -> V_31 . V_32 -> V_41 = 0 ;
V_2 -> V_31 . V_32 -> V_42 = F_21 ( V_37 )
| F_21 ( V_43 ) ;
}
V_29 = F_1 ( V_2 ) ;
if ( V_29 ) {
F_3 ( L_4 , V_29 ) ;
goto V_44;
}
F_12 ( V_2 ) ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_46 ;
V_2 -> V_48 = V_49 ;
V_2 -> V_50 = 1 ;
V_2 -> V_51 = 1 ;
V_2 -> V_52 = 1 ;
V_2 -> V_53 = 1 ;
V_2 -> V_54 = 1 ;
V_2 -> V_55 = 1 ;
F_22 ( & V_2 -> V_16 ) ;
F_23 ( & V_2 -> V_56 , V_22 -> V_57 , & V_2 -> V_16 ) ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_60 = 0 ;
return V_22 ;
V_44:
if ( ! V_28 )
F_24 ( V_2 -> V_31 . V_32 ) ;
V_34:
F_25 ( V_22 ) ;
V_30:
return NULL ;
}
void F_26 ( struct V_21 * V_22 , int V_28 )
{
struct V_1 * V_2 = F_19 ( V_22 ) ;
F_27 ( & V_2 -> V_56 ) ;
F_6 ( V_2 ) ;
if ( ! V_28 )
F_24 ( V_2 -> V_31 . V_32 ) ;
F_25 ( V_22 ) ;
}
static int F_28 ( struct V_61 * V_62 , void * V_63 )
{
F_29 ( V_62 , L_5 , V_64 ) ;
return 0 ;
}
static int F_30 ( struct V_65 * V_65 , struct V_66 * V_66 )
{
return F_31 ( V_66 , F_28 , NULL ) ;
}
static T_1 F_32 ( struct V_66 * V_66 ,
const char T_2 * V_67 , T_3 V_68 , T_4 * V_69 )
{
char V_70 [] = L_6 ;
T_3 V_71 = F_33 ( sizeof( V_70 ) - 1 , V_68 ) ;
unsigned long V_72 ;
if ( F_34 ( V_70 , V_67 , V_71 ) )
return V_68 ;
V_70 [ V_71 ] = 0 ;
if ( sscanf ( V_70 , L_7 , & V_72 ) != 1 )
F_35 (KERN_INFO DRV_NAME
L_8 , buf) ;
else
V_64 = V_72 ;
return F_36 ( V_70 , V_71 ) ;
}
static int T_5 F_37 ( void )
{
#ifdef F_38
struct V_73 * V_74 ;
V_64 = V_75 ;
V_76 = F_39 ( V_77 , V_78 . V_79 ) ;
if ( V_76 == NULL ) {
F_3 ( L_9 V_77
L_10 ) ;
return - V_80 ;
}
V_74 = F_40 ( L_11 , V_81 | V_82 , V_76 ,
& V_83 ) ;
if ( ! V_74 ) {
F_41 ( V_77 , V_78 . V_79 ) ;
V_76 = NULL ;
return - V_80 ;
}
#endif
F_35 (KERN_INFO DRV_NAME L_12 DRV_DESCRIPTION L_13 DRV_VERSION L_14 ) ;
F_35 (KERN_INFO DRV_NAME L_12 DRV_COPYRIGHT L_14 ) ;
return 0 ;
}
static void T_6 F_42 ( void )
{
#ifdef F_38
if ( V_76 ) {
F_41 ( L_11 , V_76 ) ;
F_41 ( V_77 , V_78 . V_79 ) ;
V_76 = NULL ;
}
#endif
}
