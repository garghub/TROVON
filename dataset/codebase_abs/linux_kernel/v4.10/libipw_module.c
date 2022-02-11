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
struct V_20 * F_14 ( int V_21 , int V_22 )
{
struct V_1 * V_2 ;
struct V_20 * V_23 ;
int V_24 ;
F_15 ( L_2 ) ;
V_23 = F_16 ( sizeof( struct V_1 ) + V_21 ) ;
if ( ! V_23 )
goto V_25;
V_2 = F_17 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
if ( ! V_22 ) {
V_2 -> V_26 . V_27 = F_18 ( & V_28 , 0 ) ;
if ( ! V_2 -> V_26 . V_27 ) {
F_3 ( L_3 ) ;
goto V_29;
}
V_2 -> V_23 -> V_30 = & V_2 -> V_26 ;
V_2 -> V_26 . V_31 = V_32 ;
V_2 -> V_26 . V_27 -> V_33 = V_34 ;
V_2 -> V_26 . V_27 -> V_35 = 1 ;
V_2 -> V_26 . V_27 -> V_36 = 0 ;
V_2 -> V_26 . V_27 -> V_37 = F_19 ( V_32 )
| F_19 ( V_38 ) ;
}
V_24 = F_1 ( V_2 ) ;
if ( V_24 ) {
F_3 ( L_4 , V_24 ) ;
goto V_39;
}
F_11 ( V_2 ) ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_41 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = 1 ;
V_2 -> V_46 = 1 ;
V_2 -> V_47 = 1 ;
V_2 -> V_48 = 1 ;
V_2 -> V_49 = 1 ;
V_2 -> V_50 = 1 ;
F_20 ( & V_2 -> V_15 ) ;
F_21 ( & V_2 -> V_51 , V_23 -> V_52 , & V_2 -> V_15 ) ;
V_2 -> V_53 = 0 ;
V_2 -> V_54 = 0 ;
V_2 -> V_55 = 0 ;
return V_23 ;
V_39:
if ( ! V_22 )
F_22 ( V_2 -> V_26 . V_27 ) ;
V_29:
F_23 ( V_23 ) ;
V_25:
return NULL ;
}
void F_24 ( struct V_20 * V_23 , int V_22 )
{
struct V_1 * V_2 = F_17 ( V_23 ) ;
F_25 ( & V_2 -> V_51 ) ;
F_5 ( V_2 ) ;
if ( ! V_22 )
F_22 ( V_2 -> V_26 . V_27 ) ;
F_23 ( V_23 ) ;
}
static int F_26 ( struct V_56 * V_57 , void * V_58 )
{
F_27 ( V_57 , L_5 , V_59 ) ;
return 0 ;
}
static int F_28 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_29 ( V_61 , F_26 , NULL ) ;
}
static T_1 F_30 ( struct V_61 * V_61 ,
const char T_2 * V_62 , T_3 V_63 , T_4 * V_64 )
{
char V_65 [] = L_6 ;
T_3 V_66 = F_31 ( sizeof( V_65 ) - 1 , V_63 ) ;
unsigned long V_67 ;
if ( F_32 ( V_65 , V_62 , V_66 ) )
return V_63 ;
V_65 [ V_66 ] = 0 ;
if ( sscanf ( V_65 , L_7 , & V_67 ) != 1 )
F_33 (KERN_INFO DRV_NAME
L_8 , buf) ;
else
V_59 = V_67 ;
return F_34 ( V_65 , V_66 ) ;
}
static int T_5 F_35 ( void )
{
#ifdef F_36
struct V_68 * V_69 ;
V_59 = V_70 ;
V_71 = F_37 ( V_72 , V_73 . V_74 ) ;
if ( V_71 == NULL ) {
F_3 ( L_9 V_72
L_10 ) ;
return - V_75 ;
}
V_69 = F_38 ( L_11 , V_76 | V_77 , V_71 ,
& V_78 ) ;
if ( ! V_69 ) {
F_39 ( V_72 , V_73 . V_74 ) ;
V_71 = NULL ;
return - V_75 ;
}
#endif
F_33 (KERN_INFO DRV_NAME L_12 DRV_DESCRIPTION L_13 DRV_VERSION L_14 ) ;
F_33 (KERN_INFO DRV_NAME L_12 DRV_COPYRIGHT L_14 ) ;
return 0 ;
}
static void T_6 F_40 ( void )
{
#ifdef F_36
if ( V_71 ) {
F_39 ( L_11 , V_71 ) ;
F_39 ( V_72 , V_73 . V_74 ) ;
V_71 = NULL ;
}
#endif
}
