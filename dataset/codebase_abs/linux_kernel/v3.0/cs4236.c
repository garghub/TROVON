static int T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) < 0 ) {
F_3 (KERN_ERR IDENT L_1 ) ;
return - V_4 ;
}
V_5 [ V_1 ] = F_4 ( V_3 , 0 ) ;
if ( V_6 [ V_1 ] > 0 )
V_6 [ V_1 ] = F_4 ( V_3 , 1 ) ;
V_7 [ V_1 ] = F_4 ( V_3 , 2 ) ;
V_8 [ V_1 ] = F_5 ( V_3 , 0 ) ;
V_9 [ V_1 ] = F_6 ( V_3 , 0 ) ;
V_10 [ V_1 ] = F_6 ( V_3 , 1 ) == 4 ? - 1 : ( int ) F_6 ( V_3 , 1 ) ;
F_7 ( L_2 ,
V_5 [ V_1 ] , V_6 [ V_1 ] , V_7 [ V_1 ] ) ;
F_7 ( L_3 ,
V_8 [ V_1 ] , V_9 [ V_1 ] , V_10 [ V_1 ] ) ;
return 0 ;
}
static int T_1 F_8 ( int V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) < 0 ) {
F_3 (KERN_ERR IDENT L_4 ) ;
return - V_4 ;
}
V_11 [ V_1 ] = F_4 ( V_3 , 0 ) ;
F_7 ( L_5 , V_11 [ V_1 ] ) ;
return 0 ;
}
static int T_1 F_9 ( int V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) < 0 ) {
F_3 (KERN_ERR IDENT L_6 ) ;
V_12 [ V_1 ] = V_13 ;
V_14 [ V_1 ] = V_15 ;
} else {
V_12 [ V_1 ] = F_4 ( V_3 , 0 ) ;
if ( V_14 [ V_1 ] >= 0 &&
F_10 ( V_3 , 0 ) && F_5 ( V_3 , 0 ) >= 0 ) {
V_14 [ V_1 ] = F_5 ( V_3 , 0 ) ;
} else {
V_14 [ V_1 ] = - 1 ;
}
}
F_7 ( L_7 , V_12 [ V_1 ] , V_14 [ V_1 ] ) ;
return 0 ;
}
static int T_1 F_11 ( int V_1 , struct V_16 * V_17 ,
struct V_2 * V_3 ,
struct V_2 * V_18 )
{
V_17 -> V_19 = V_3 ;
if ( F_1 ( V_1 , V_17 -> V_19 ) < 0 )
return - V_4 ;
if ( V_18 )
V_11 [ V_1 ] = F_4 ( V_18 , 0 ) ;
else
V_11 [ V_1 ] = - 1 ;
return 0 ;
}
static int T_1 F_12 ( int V_1 , struct V_16 * V_17 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
V_17 -> V_19 = F_13 ( V_21 , V_23 -> V_24 [ 0 ] . V_23 , NULL ) ;
if ( V_17 -> V_19 == NULL )
return - V_4 ;
V_17 -> V_25 = F_13 ( V_21 , V_23 -> V_24 [ 1 ] . V_23 , NULL ) ;
if ( V_17 -> V_25 == NULL )
return - V_4 ;
if ( V_23 -> V_24 [ 2 ] . V_23 [ 0 ] ) {
V_17 -> V_26 = F_13 ( V_21 , V_23 -> V_24 [ 2 ] . V_23 , NULL ) ;
if ( V_17 -> V_26 == NULL )
return - V_4 ;
}
if ( F_1 ( V_1 , V_17 -> V_19 ) < 0 )
return - V_4 ;
if ( V_17 -> V_25 && V_11 [ V_1 ] > 0 ) {
if ( F_8 ( V_1 , V_17 -> V_25 ) < 0 )
return - V_4 ;
}
if ( V_17 -> V_26 && V_12 [ V_1 ] > 0 ) {
if ( F_9 ( V_1 , V_17 -> V_26 ) < 0 )
return - V_4 ;
}
return 0 ;
}
static void F_14 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_28 ;
F_15 ( V_17 -> V_29 ) ;
}
static int F_16 ( int V_1 , struct V_27 * * V_30 )
{
struct V_27 * V_21 ;
int V_31 ;
V_31 = F_17 ( V_32 [ V_1 ] , V_23 [ V_1 ] , V_33 ,
sizeof( struct V_16 ) , & V_21 ) ;
if ( V_31 < 0 )
return V_31 ;
V_21 -> V_34 = F_14 ;
* V_30 = V_21 ;
return 0 ;
}
static int T_1 F_18 ( struct V_27 * V_21 , int V_1 )
{
struct V_16 * V_17 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_31 ;
V_17 = V_21 -> V_28 ;
if ( V_7 [ V_1 ] > 0 && V_7 [ V_1 ] != V_13 )
if ( ( V_17 -> V_29 = F_19 ( V_7 [ V_1 ] , 16 , V_41 L_8 ) ) == NULL ) {
F_3 (KERN_ERR IDENT L_9 , sb_port[dev]) ;
return - V_4 ;
}
V_31 = F_20 ( V_21 , V_5 [ V_1 ] , V_11 [ V_1 ] ,
V_8 [ V_1 ] ,
V_9 [ V_1 ] , V_10 [ V_1 ] ,
V_42 , 0 , & V_38 ) ;
if ( V_31 < 0 )
return V_31 ;
V_17 -> V_38 = V_38 ;
if ( V_38 -> V_43 & V_44 ) {
V_31 = F_21 ( V_38 , 0 , & V_36 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_22 ( V_38 ) ;
if ( V_31 < 0 )
return V_31 ;
} else {
V_31 = F_23 ( V_38 , 0 , & V_36 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_24 ( V_38 ) ;
if ( V_31 < 0 )
return V_31 ;
}
strcpy ( V_21 -> V_45 , V_36 -> V_46 ) ;
strcpy ( V_21 -> V_47 , V_36 -> V_46 ) ;
sprintf ( V_21 -> V_48 , L_10 ,
V_36 -> V_46 ,
V_38 -> V_5 ,
V_8 [ V_1 ] ,
V_9 [ V_1 ] ) ;
if ( V_10 [ V_1 ] >= 0 )
sprintf ( V_21 -> V_48 + strlen ( V_21 -> V_48 ) , L_11 , V_10 [ V_1 ] ) ;
V_31 = F_25 ( V_38 , 0 , NULL ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_6 [ V_1 ] > 0 && V_6 [ V_1 ] != V_13 ) {
if ( F_26 ( V_21 ,
V_6 [ V_1 ] , V_6 [ V_1 ] + 2 ,
V_49 , 0 , & V_40 ) < 0 ) {
F_3 (KERN_WARNING IDENT L_12 ) ;
} else {
if ( ( V_31 = F_27 ( V_40 , 0 , 1 , NULL ) ) < 0 )
return V_31 ;
}
}
if ( V_12 [ V_1 ] > 0 && V_12 [ V_1 ] != V_13 ) {
if ( V_14 [ V_1 ] == V_15 )
V_14 [ V_1 ] = - 1 ;
if ( F_28 ( V_21 , 0 , V_50 ,
V_12 [ V_1 ] , 0 ,
V_14 [ V_1 ] ,
V_14 [ V_1 ] >= 0 ? V_51 : 0 , NULL ) < 0 )
F_3 (KERN_WARNING IDENT L_13 ) ;
}
return F_29 ( V_21 ) ;
}
static int T_1 F_30 ( struct V_52 * V_3 ,
unsigned int V_1 )
{
if ( ! V_53 [ V_1 ] || F_31 ( V_1 ) )
return 0 ;
if ( V_5 [ V_1 ] == V_13 ) {
F_32 ( V_3 , L_14 ) ;
return 0 ;
}
if ( V_11 [ V_1 ] == V_13 ) {
F_32 ( V_3 , L_15 ) ;
return 0 ;
}
if ( V_8 [ V_1 ] == V_15 ) {
F_32 ( V_3 , L_16 ) ;
return 0 ;
}
if ( V_9 [ V_1 ] == V_54 ) {
F_32 ( V_3 , L_17 ) ;
return 0 ;
}
return 1 ;
}
static int T_1 F_33 ( struct V_52 * V_3 ,
unsigned int V_1 )
{
struct V_27 * V_21 ;
int V_31 ;
V_31 = F_16 ( V_1 , & V_21 ) ;
if ( V_31 < 0 )
return V_31 ;
F_34 ( V_21 , V_3 ) ;
if ( ( V_31 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_35 ( V_21 ) ;
return V_31 ;
}
F_36 ( V_3 , V_21 ) ;
return 0 ;
}
static int T_2 F_37 ( struct V_52 * V_3 ,
unsigned int V_1 )
{
F_35 ( F_38 ( V_3 ) ) ;
F_36 ( V_3 , NULL ) ;
return 0 ;
}
static int F_39 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_28 ;
F_40 ( V_21 , V_55 ) ;
V_17 -> V_38 -> V_56 ( V_17 -> V_38 ) ;
return 0 ;
}
static int F_41 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_28 ;
V_17 -> V_38 -> V_57 ( V_17 -> V_38 ) ;
F_40 ( V_21 , V_58 ) ;
return 0 ;
}
static int F_42 ( struct V_52 * V_1 , unsigned int V_59 ,
T_3 V_60 )
{
return F_39 ( F_38 ( V_1 ) ) ;
}
static int F_43 ( struct V_52 * V_1 , unsigned int V_59 )
{
return F_41 ( F_38 ( V_1 ) ) ;
}
static int T_1 F_44 ( struct V_2 * V_3 ,
const struct V_61 * V_23 )
{
static int V_1 ;
int V_31 ;
struct V_27 * V_21 ;
struct V_2 * V_18 ;
char V_62 [ V_63 ] ;
if ( F_45 ( V_3 ) )
return - V_64 ;
for (; V_1 < V_65 ; V_1 ++ ) {
if ( V_53 [ V_1 ] && V_66 [ V_1 ] )
break;
}
if ( V_1 >= V_65 )
return - V_67 ;
strcpy ( V_62 , V_3 -> V_23 [ 0 ] . V_23 ) ;
V_62 [ 5 ] = '1' ;
V_18 = NULL ;
F_46 (cdev, &(pdev->protocol->devices), protocol_list) {
if ( ! strcmp ( V_18 -> V_23 [ 0 ] . V_23 , V_62 ) )
break;
}
V_31 = F_16 ( V_1 , & V_21 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_11 ( V_1 , V_21 -> V_28 , V_3 , V_18 ) ;
if ( V_31 < 0 ) {
F_3 ( V_68 L_18 V_41 L_19 ) ;
F_35 ( V_21 ) ;
return V_31 ;
}
F_34 ( V_21 , & V_3 -> V_1 ) ;
if ( ( V_31 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_35 ( V_21 ) ;
return V_31 ;
}
F_47 ( V_3 , V_21 ) ;
V_1 ++ ;
return 0 ;
}
static void T_2 F_48 ( struct V_2 * V_3 )
{
F_35 ( F_49 ( V_3 ) ) ;
F_47 ( V_3 , NULL ) ;
}
static int F_50 ( struct V_2 * V_3 , T_3 V_60 )
{
return F_39 ( F_49 ( V_3 ) ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
return F_41 ( F_49 ( V_3 ) ) ;
}
static int T_1 F_52 ( struct V_20 * V_69 ,
const struct V_22 * V_70 )
{
static int V_1 ;
struct V_27 * V_21 ;
int V_71 ;
for ( ; V_1 < V_65 ; V_1 ++ ) {
if ( V_53 [ V_1 ] && V_66 [ V_1 ] )
break;
}
if ( V_1 >= V_65 )
return - V_67 ;
V_71 = F_16 ( V_1 , & V_21 ) ;
if ( V_71 < 0 )
return V_71 ;
if ( ( V_71 = F_12 ( V_1 , V_21 -> V_28 , V_69 , V_70 ) ) < 0 ) {
F_3 ( V_68 L_20 V_41
L_21 ) ;
F_35 ( V_21 ) ;
return V_71 ;
}
F_34 ( V_21 , & V_69 -> V_21 -> V_1 ) ;
if ( ( V_71 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_35 ( V_21 ) ;
return V_71 ;
}
F_53 ( V_69 , V_21 ) ;
V_1 ++ ;
return 0 ;
}
static void T_2 F_54 ( struct V_20 * V_69 )
{
F_35 ( F_55 ( V_69 ) ) ;
F_53 ( V_69 , NULL ) ;
}
static int F_56 ( struct V_20 * V_69 , T_3 V_60 )
{
return F_39 ( F_55 ( V_69 ) ) ;
}
static int F_57 ( struct V_20 * V_69 )
{
return F_41 ( F_55 ( V_69 ) ) ;
}
static int T_4 F_58 ( void )
{
int V_31 ;
V_31 = F_59 ( & V_72 , V_65 ) ;
#ifdef F_60
if ( ! V_31 )
V_73 = 1 ;
V_31 = F_61 ( & V_74 ) ;
if ( ! V_31 )
V_75 = 1 ;
V_31 = F_62 ( & V_76 ) ;
if ( ! V_31 )
V_77 = 1 ;
if ( V_75 )
V_31 = 0 ;
if ( V_73 )
V_31 = 0 ;
#endif
return V_31 ;
}
static void T_5 F_63 ( void )
{
#ifdef F_60
if ( V_77 )
F_64 ( & V_76 ) ;
if ( V_75 )
F_65 ( & V_74 ) ;
if ( V_73 )
#endif
F_66 ( & V_72 ) ;
}
