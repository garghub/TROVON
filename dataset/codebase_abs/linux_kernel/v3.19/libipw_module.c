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
static inline void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
F_4 ( V_2 -> V_6 [ V_3 ] ) ;
}
void F_6 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
struct V_7 * V_11 = NULL ;
unsigned long V_12 ;
unsigned long V_13 = F_7 ( V_10 * V_14 ) ;
F_8 ( & V_2 -> V_15 , V_12 ) ;
F_9 (network, &ieee->network_list, list) {
V_11 -> V_16 -= V_13 ;
}
F_10 ( & V_2 -> V_15 , V_12 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_3 ;
F_12 ( & V_2 -> V_17 ) ;
F_12 ( & V_2 -> V_18 ) ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ )
F_13 ( & V_2 -> V_6 [ V_3 ] -> V_19 ,
& V_2 -> V_17 ) ;
}
int F_14 ( struct V_20 * V_21 , int V_22 )
{
if ( ( V_22 < 68 ) || ( V_22 > V_23 ) )
return - V_24 ;
V_21 -> V_25 = V_22 ;
return 0 ;
}
struct V_20 * F_15 ( int V_26 , int V_27 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_28 ;
F_16 ( L_2 ) ;
V_21 = F_17 ( sizeof( struct V_1 ) + V_26 ) ;
if ( ! V_21 )
goto V_29;
V_2 = F_18 ( V_21 ) ;
V_2 -> V_21 = V_21 ;
if ( ! V_27 ) {
V_2 -> V_30 . V_31 = F_19 ( & V_32 , 0 ) ;
if ( ! V_2 -> V_30 . V_31 ) {
F_3 ( L_3 ) ;
goto V_33;
}
V_2 -> V_21 -> V_34 = & V_2 -> V_30 ;
V_2 -> V_30 . V_35 = V_36 ;
V_2 -> V_30 . V_31 -> V_37 = V_38 ;
V_2 -> V_30 . V_31 -> V_39 = 1 ;
V_2 -> V_30 . V_31 -> V_40 = 0 ;
V_2 -> V_30 . V_31 -> V_41 = F_20 ( V_36 )
| F_20 ( V_42 ) ;
}
V_28 = F_1 ( V_2 ) ;
if ( V_28 ) {
F_3 ( L_4 , V_28 ) ;
goto V_43;
}
F_11 ( V_2 ) ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_45 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = 1 ;
V_2 -> V_50 = 1 ;
V_2 -> V_51 = 1 ;
V_2 -> V_52 = 1 ;
V_2 -> V_53 = 1 ;
V_2 -> V_54 = 1 ;
F_21 ( & V_2 -> V_15 ) ;
F_22 ( & V_2 -> V_55 , V_21 -> V_56 , & V_2 -> V_15 ) ;
V_2 -> V_57 = 0 ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
return V_21 ;
V_43:
if ( ! V_27 )
F_23 ( V_2 -> V_30 . V_31 ) ;
V_33:
F_24 ( V_21 ) ;
V_29:
return NULL ;
}
void F_25 ( struct V_20 * V_21 , int V_27 )
{
struct V_1 * V_2 = F_18 ( V_21 ) ;
F_26 ( & V_2 -> V_55 ) ;
F_5 ( V_2 ) ;
if ( ! V_27 )
F_23 ( V_2 -> V_30 . V_31 ) ;
F_24 ( V_21 ) ;
}
static int F_27 ( struct V_60 * V_61 , void * V_62 )
{
F_28 ( V_61 , L_5 , V_63 ) ;
return 0 ;
}
static int F_29 ( struct V_64 * V_64 , struct V_65 * V_65 )
{
return F_30 ( V_65 , F_27 , NULL ) ;
}
static T_1 F_31 ( struct V_65 * V_65 ,
const char T_2 * V_66 , T_3 V_67 , T_4 * V_68 )
{
char V_69 [] = L_6 ;
T_3 V_70 = F_32 ( sizeof( V_69 ) - 1 , V_67 ) ;
unsigned long V_71 ;
if ( F_33 ( V_69 , V_66 , V_70 ) )
return V_67 ;
V_69 [ V_70 ] = 0 ;
if ( sscanf ( V_69 , L_7 , & V_71 ) != 1 )
F_34 (KERN_INFO DRV_NAME
L_8 , buf) ;
else
V_63 = V_71 ;
return F_35 ( V_69 , V_70 ) ;
}
static int T_5 F_36 ( void )
{
#ifdef F_37
struct V_72 * V_73 ;
V_63 = V_74 ;
V_75 = F_38 ( V_76 , V_77 . V_78 ) ;
if ( V_75 == NULL ) {
F_3 ( L_9 V_76
L_10 ) ;
return - V_79 ;
}
V_73 = F_39 ( L_11 , V_80 | V_81 , V_75 ,
& V_82 ) ;
if ( ! V_73 ) {
F_40 ( V_76 , V_77 . V_78 ) ;
V_75 = NULL ;
return - V_79 ;
}
#endif
F_34 (KERN_INFO DRV_NAME L_12 DRV_DESCRIPTION L_13 DRV_VERSION L_14 ) ;
F_34 (KERN_INFO DRV_NAME L_12 DRV_COPYRIGHT L_14 ) ;
return 0 ;
}
static void T_6 F_41 ( void )
{
#ifdef F_37
if ( V_75 ) {
F_40 ( L_11 , V_75 ) ;
F_40 ( V_76 , V_77 . V_78 ) ;
V_75 = NULL ;
}
#endif
}
