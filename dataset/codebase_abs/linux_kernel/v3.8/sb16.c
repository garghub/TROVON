static int F_1 ( int V_1 , struct V_2 * V_3 ,
struct V_4 * V_5 ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_3 -> V_1 = F_2 ( V_5 , V_7 -> V_11 [ 0 ] . V_7 , NULL ) ;
if ( V_3 -> V_1 == NULL )
return - V_12 ;
#ifdef F_3
V_3 -> V_13 = F_2 ( V_5 , V_7 -> V_11 [ 1 ] . V_7 , V_3 -> V_1 ) ;
#endif
V_9 = V_3 -> V_1 ;
V_10 = F_4 ( V_9 ) ;
if ( V_10 < 0 ) {
F_5 (KERN_ERR PFX L_1 ) ;
return V_10 ;
}
V_14 [ V_1 ] = F_6 ( V_9 , 0 ) ;
V_15 [ V_1 ] = F_6 ( V_9 , 1 ) ;
V_16 [ V_1 ] = F_6 ( V_9 , 2 ) ;
V_17 [ V_1 ] = F_7 ( V_9 , 0 ) ;
V_18 [ V_1 ] = F_7 ( V_9 , 1 ) ;
V_19 [ V_1 ] = F_8 ( V_9 , 0 ) ;
F_9 ( L_2 ,
V_14 [ V_1 ] , V_15 [ V_1 ] , V_16 [ V_1 ] ) ;
F_9 ( L_3 ,
V_17 [ V_1 ] , V_18 [ V_1 ] , V_19 [ V_1 ] ) ;
#ifdef F_3
V_9 = V_3 -> V_13 ;
if ( V_9 != NULL ) {
V_10 = F_4 ( V_9 ) ;
if ( V_10 < 0 ) {
goto V_20;
}
V_21 [ V_1 ] = F_6 ( V_9 , 0 ) ;
F_9 ( L_4 ,
( unsigned long long ) F_6 ( V_9 , 0 ) ) ;
} else {
V_20:
if ( V_9 ) {
F_10 ( V_9 ) ;
F_5 (KERN_ERR PFX L_5 ) ;
}
V_3 -> V_13 = NULL ;
V_21 [ V_1 ] = - 1 ;
}
#endif
return 0 ;
}
static void F_11 ( struct V_22 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_23 ;
if ( V_3 == NULL )
return;
F_12 ( V_3 -> V_24 ) ;
}
static int F_13 ( int V_1 , struct V_22 * * V_25 )
{
struct V_22 * V_5 ;
int V_10 ;
V_10 = F_14 ( V_26 [ V_1 ] , V_7 [ V_1 ] , V_27 ,
sizeof( struct V_2 ) , & V_5 ) ;
if ( V_10 < 0 )
return V_10 ;
V_5 -> V_28 = F_11 ;
* V_25 = V_5 ;
return 0 ;
}
static int F_15 ( struct V_22 * V_5 , int V_1 )
{
int V_29 , V_30 , V_31 ;
struct V_32 * V_33 ;
struct V_2 * V_3 = V_5 -> V_23 ;
struct V_34 * V_35 ;
struct V_36 * V_37 = NULL ;
#ifdef F_16
struct V_36 * V_38 = NULL ;
#endif
unsigned long V_39 ;
int V_10 ;
V_29 = V_19 [ V_1 ] ;
V_30 = V_17 [ V_1 ] ;
V_31 = V_18 [ V_1 ] ;
if ( ( V_10 = F_17 ( V_5 ,
V_14 [ V_1 ] ,
V_29 ,
V_40 ,
V_30 ,
V_31 ,
V_41 ,
& V_33 ) ) < 0 )
return V_10 ;
V_3 -> V_33 = V_33 ;
if ( V_33 -> V_42 != V_43 ) {
F_5 (KERN_ERR PFX L_6 , port[dev]) ;
return - V_12 ;
}
V_33 -> V_15 = V_15 [ V_1 ] ;
if ( ! F_18 ( V_1 ) && ( V_10 = F_19 ( V_33 ) ) < 0 )
return V_10 ;
if ( ( V_10 = F_20 ( V_33 , 0 , & V_33 -> V_44 ) ) < 0 )
return V_10 ;
strcpy ( V_5 -> V_45 ,
#ifdef F_3
V_21 [ V_1 ] > 0 ? L_7 :
#endif
L_8 ) ;
strcpy ( V_5 -> V_46 , V_33 -> V_47 ) ;
sprintf ( V_5 -> V_48 , L_9 ,
V_33 -> V_47 ,
V_33 -> V_14 ,
V_29 ) ;
if ( V_30 >= 0 )
sprintf ( V_5 -> V_48 + strlen ( V_5 -> V_48 ) , L_10 , V_30 ) ;
if ( V_31 >= 0 )
sprintf ( V_5 -> V_48 + strlen ( V_5 -> V_48 ) , L_11 ,
V_30 >= 0 ? L_12 : L_13 , V_31 ) ;
if ( V_33 -> V_15 > 0 && V_33 -> V_15 != V_49 ) {
if ( ( V_10 = F_21 ( V_5 , 0 , V_50 ,
V_33 -> V_15 ,
V_51 , - 1 ,
& V_33 -> V_52 ) ) < 0 )
return V_10 ;
V_33 -> V_53 = V_54 ;
}
#ifdef F_3
if ( V_21 [ V_1 ] == V_49 )
V_21 [ V_1 ] = 0 ;
#endif
if ( V_16 [ V_1 ] > 0 && V_16 [ V_1 ] != V_49 ) {
if ( F_22 ( V_5 , V_16 [ V_1 ] , V_16 [ V_1 ] + 2 ,
V_55 ,
V_3 -> V_24 != NULL || V_16 [ V_1 ] == V_14 [ V_1 ] ,
& V_35 ) < 0 ) {
F_5 (KERN_ERR PFX L_14 ,
fm_port[dev], fm_port[dev] + 2 ) ;
} else {
#ifdef F_3
int V_56 = V_21 [ V_1 ] > 0 ? 2 : 1 ;
#else
int V_56 = 1 ;
#endif
if ( ( V_10 = F_23 ( V_35 , 0 , V_56 , & V_37 ) ) < 0 )
return V_10 ;
}
}
if ( ( V_10 = F_24 ( V_33 ) ) < 0 )
return V_10 ;
#ifdef F_16
if ( ( V_33 -> V_42 == V_43 ) && V_57 [ V_1 ] ) {
F_25 ( V_33 , V_37 != NULL ? 1 : 0 , & V_38 ) ;
if ( V_38 ) {
V_33 -> V_57 = V_38 -> V_23 ;
V_33 -> V_42 = V_58 ;
} else {
F_5 (KERN_INFO PFX L_15 , dev + 1 ) ;
}
}
#endif
#ifdef F_3
if ( V_21 [ V_1 ] > 0 ) {
if ( ( V_10 = F_26 ( V_5 , 1 , V_21 [ V_1 ] ,
V_59 [ V_1 ] , NULL ) ) < 0 ) {
F_5 (KERN_ERR PFX L_16 , awe_port[dev]) ;
return V_10 ;
}
}
#endif
F_27 ( & V_33 -> V_60 , V_39 ) ;
F_28 ( V_33 , V_61 ,
( F_29 ( V_33 , V_61 ) & 0x01 ) |
( V_62 [ V_1 ] ? 0x00 : 0x01 ) ) ;
F_30 ( & V_33 -> V_60 , V_39 ) ;
if ( ( V_10 = F_31 ( V_5 ) ) < 0 )
return V_10 ;
return 0 ;
}
static int F_32 ( struct V_22 * V_5 , T_1 V_63 )
{
struct V_2 * V_3 = V_5 -> V_23 ;
struct V_32 * V_33 = V_3 -> V_33 ;
F_33 ( V_5 , V_64 ) ;
F_34 ( V_33 -> V_44 ) ;
F_35 ( V_33 ) ;
return 0 ;
}
static int F_36 ( struct V_22 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_23 ;
struct V_32 * V_33 = V_3 -> V_33 ;
F_37 ( V_33 ) ;
F_38 ( V_33 ) ;
F_33 ( V_5 , V_65 ) ;
return 0 ;
}
static int F_39 ( int V_1 , struct V_66 * V_9 )
{
struct V_2 * V_3 ;
struct V_22 * V_5 ;
int V_10 ;
V_10 = F_13 ( V_1 , & V_5 ) ;
if ( V_10 < 0 )
return V_10 ;
V_3 = V_5 -> V_23 ;
V_16 [ V_1 ] = V_14 [ V_1 ] ;
V_3 -> V_24 = F_40 ( 0x388 , 4 , L_17 ) ;
#ifdef F_3
V_21 [ V_1 ] = V_14 [ V_1 ] + 0x400 ;
#endif
F_41 ( V_5 , V_9 ) ;
if ( ( V_10 = F_15 ( V_5 , V_1 ) ) < 0 ) {
F_42 ( V_5 ) ;
return V_10 ;
}
F_43 ( V_9 , V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_66 * V_9 , unsigned int V_1 )
{
return V_67 [ V_1 ] && ! F_18 ( V_1 ) ;
}
static int F_45 ( struct V_66 * V_9 , unsigned int V_1 )
{
int V_10 ;
static int V_68 [] = { 5 , 9 , 10 , 7 , - 1 } ;
static int V_69 [] = { 1 , 3 , 0 , - 1 } ;
static int V_70 [] = { 5 , 6 , 7 , - 1 } ;
if ( V_19 [ V_1 ] == V_71 ) {
if ( ( V_19 [ V_1 ] = F_46 ( V_68 ) ) < 0 ) {
F_5 (KERN_ERR PFX L_18 ) ;
return - V_72 ;
}
}
if ( V_17 [ V_1 ] == V_73 ) {
if ( ( V_17 [ V_1 ] = F_47 ( V_69 ) ) < 0 ) {
F_5 (KERN_ERR PFX L_19 ) ;
return - V_72 ;
}
}
if ( V_18 [ V_1 ] == V_73 ) {
if ( ( V_18 [ V_1 ] = F_47 ( V_70 ) ) < 0 ) {
F_5 (KERN_ERR PFX L_20 ) ;
return - V_72 ;
}
}
if ( V_14 [ V_1 ] != V_49 )
return F_39 ( V_1 , V_9 ) ;
else {
static int V_74 [] = { 0x220 , 0x240 , 0x260 , 0x280 } ;
int V_75 ;
for ( V_75 = 0 ; V_75 < F_48 ( V_74 ) ; V_75 ++ ) {
V_14 [ V_1 ] = V_74 [ V_75 ] ;
V_10 = F_39 ( V_1 , V_9 ) ;
if ( ! V_10 )
return 0 ;
}
return V_10 ;
}
}
static int F_49 ( struct V_66 * V_9 , unsigned int V_1 )
{
F_42 ( F_50 ( V_9 ) ) ;
F_43 ( V_9 , NULL ) ;
return 0 ;
}
static int F_51 ( struct V_66 * V_1 , unsigned int V_76 ,
T_1 V_63 )
{
return F_32 ( F_50 ( V_1 ) , V_63 ) ;
}
static int F_52 ( struct V_66 * V_1 , unsigned int V_76 )
{
return F_36 ( F_50 ( V_1 ) ) ;
}
static int F_53 ( struct V_4 * V_77 ,
const struct V_6 * V_78 )
{
static int V_1 ;
struct V_22 * V_5 ;
int V_79 ;
for ( ; V_1 < V_80 ; V_1 ++ ) {
if ( ! V_67 [ V_1 ] || ! V_81 [ V_1 ] )
continue;
V_79 = F_13 ( V_1 , & V_5 ) ;
if ( V_79 < 0 )
return V_79 ;
F_41 ( V_5 , & V_77 -> V_5 -> V_1 ) ;
if ( ( V_79 = F_1 ( V_1 , V_5 -> V_23 , V_77 , V_78 ) ) < 0 ||
( V_79 = F_15 ( V_5 , V_1 ) ) < 0 ) {
F_42 ( V_5 ) ;
return V_79 ;
}
F_54 ( V_77 , V_5 ) ;
V_1 ++ ;
return 0 ;
}
return - V_12 ;
}
static void F_55 ( struct V_4 * V_77 )
{
F_42 ( F_56 ( V_77 ) ) ;
F_54 ( V_77 , NULL ) ;
}
static int F_57 ( struct V_4 * V_77 , T_1 V_63 )
{
return F_32 ( F_56 ( V_77 ) , V_63 ) ;
}
static int F_58 ( struct V_4 * V_77 )
{
return F_36 ( F_56 ( V_77 ) ) ;
}
static int T_2 F_59 ( void )
{
int V_10 ;
V_10 = F_60 ( & V_82 , V_80 ) ;
#ifdef F_61
if ( ! V_10 )
V_83 = 1 ;
V_10 = F_62 ( & V_84 ) ;
if ( ! V_10 )
V_85 = 1 ;
if ( V_83 )
V_10 = 0 ;
#endif
return V_10 ;
}
static void T_3 F_63 ( void )
{
#ifdef F_61
if ( V_85 )
F_64 ( & V_84 ) ;
if ( V_83 )
#endif
F_65 ( & V_82 ) ;
}
