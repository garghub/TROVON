static int F_1 ( int V_1 , struct V_2 * V_3 )
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
static int F_8 ( int V_1 , struct V_2 * V_3 )
{
if ( F_2 ( V_3 ) < 0 ) {
F_3 (KERN_ERR IDENT L_4 ) ;
return - V_4 ;
}
V_11 [ V_1 ] = F_4 ( V_3 , 0 ) ;
F_7 ( L_5 , V_11 [ V_1 ] ) ;
return 0 ;
}
static int F_9 ( int V_1 , struct V_2 * V_3 )
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
static int F_11 ( int V_1 , struct V_16 * V_17 ,
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
static int F_12 ( int V_1 , struct V_16 * V_17 ,
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
static int F_16 ( struct V_30 * V_3 , int V_1 ,
struct V_27 * * V_31 )
{
struct V_27 * V_21 ;
int V_32 ;
V_32 = F_17 ( V_3 , V_33 [ V_1 ] , V_23 [ V_1 ] , V_34 ,
sizeof( struct V_16 ) , & V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
V_21 -> V_35 = F_14 ;
* V_31 = V_21 ;
return 0 ;
}
static int F_18 ( struct V_27 * V_21 , int V_1 )
{
struct V_16 * V_17 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_32 ;
V_17 = V_21 -> V_28 ;
if ( V_7 [ V_1 ] > 0 && V_7 [ V_1 ] != V_13 )
if ( ( V_17 -> V_29 = F_19 ( V_7 [ V_1 ] , 16 , V_40 L_8 ) ) == NULL ) {
F_3 (KERN_ERR IDENT L_9 , sb_port[dev]) ;
return - V_4 ;
}
V_32 = F_20 ( V_21 , V_5 [ V_1 ] , V_11 [ V_1 ] ,
V_8 [ V_1 ] ,
V_9 [ V_1 ] , V_10 [ V_1 ] ,
V_41 , 0 , & V_37 ) ;
if ( V_32 < 0 )
return V_32 ;
V_17 -> V_37 = V_37 ;
if ( V_37 -> V_42 & V_43 ) {
V_32 = F_21 ( V_37 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_22 ( V_37 ) ;
if ( V_32 < 0 )
return V_32 ;
} else {
V_32 = F_23 ( V_37 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_24 ( V_37 ) ;
if ( V_32 < 0 )
return V_32 ;
}
strcpy ( V_21 -> V_44 , V_37 -> V_45 -> V_46 ) ;
strcpy ( V_21 -> V_47 , V_37 -> V_45 -> V_46 ) ;
sprintf ( V_21 -> V_48 , L_10 ,
V_37 -> V_45 -> V_46 ,
V_37 -> V_5 ,
V_8 [ V_1 ] ,
V_9 [ V_1 ] ) ;
if ( V_10 [ V_1 ] >= 0 )
sprintf ( V_21 -> V_48 + strlen ( V_21 -> V_48 ) , L_11 , V_10 [ V_1 ] ) ;
V_32 = F_25 ( V_37 , 0 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( V_6 [ V_1 ] > 0 && V_6 [ V_1 ] != V_13 ) {
if ( F_26 ( V_21 ,
V_6 [ V_1 ] , V_6 [ V_1 ] + 2 ,
V_49 , 0 , & V_39 ) < 0 ) {
F_3 (KERN_WARNING IDENT L_12 ) ;
} else {
if ( ( V_32 = F_27 ( V_39 , 0 , 1 , NULL ) ) < 0 )
return V_32 ;
}
}
if ( V_12 [ V_1 ] > 0 && V_12 [ V_1 ] != V_13 ) {
if ( V_14 [ V_1 ] == V_15 )
V_14 [ V_1 ] = - 1 ;
if ( F_28 ( V_21 , 0 , V_50 ,
V_12 [ V_1 ] , 0 ,
V_14 [ V_1 ] , NULL ) < 0 )
F_3 (KERN_WARNING IDENT L_13 ) ;
}
return F_29 ( V_21 ) ;
}
static int F_30 ( struct V_30 * V_3 ,
unsigned int V_1 )
{
if ( ! V_51 [ V_1 ] || F_31 ( V_1 ) )
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
if ( V_9 [ V_1 ] == V_52 ) {
F_32 ( V_3 , L_17 ) ;
return 0 ;
}
return 1 ;
}
static int F_33 ( struct V_30 * V_3 ,
unsigned int V_1 )
{
struct V_27 * V_21 ;
int V_32 ;
V_32 = F_16 ( V_3 , V_1 , & V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ( V_32 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_34 ( V_21 ) ;
return V_32 ;
}
F_35 ( V_3 , V_21 ) ;
return 0 ;
}
static int F_36 ( struct V_30 * V_3 ,
unsigned int V_1 )
{
F_34 ( F_37 ( V_3 ) ) ;
return 0 ;
}
static int F_38 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_28 ;
F_39 ( V_21 , V_53 ) ;
V_17 -> V_37 -> V_54 ( V_17 -> V_37 ) ;
return 0 ;
}
static int F_40 ( struct V_27 * V_21 )
{
struct V_16 * V_17 = V_21 -> V_28 ;
V_17 -> V_37 -> V_55 ( V_17 -> V_37 ) ;
F_39 ( V_21 , V_56 ) ;
return 0 ;
}
static int F_41 ( struct V_30 * V_1 , unsigned int V_57 ,
T_1 V_58 )
{
return F_38 ( F_37 ( V_1 ) ) ;
}
static int F_42 ( struct V_30 * V_1 , unsigned int V_57 )
{
return F_40 ( F_37 ( V_1 ) ) ;
}
static int F_43 ( struct V_2 * V_3 ,
const struct V_59 * V_23 )
{
static int V_1 ;
int V_32 ;
struct V_27 * V_21 ;
struct V_2 * V_18 ;
char V_60 [ V_61 ] ;
if ( F_44 ( V_3 ) )
return - V_62 ;
for (; V_1 < V_63 ; V_1 ++ ) {
if ( V_51 [ V_1 ] && V_64 [ V_1 ] )
break;
}
if ( V_1 >= V_63 )
return - V_65 ;
strcpy ( V_60 , V_3 -> V_23 [ 0 ] . V_23 ) ;
V_60 [ 5 ] = '1' ;
V_18 = NULL ;
F_45 (cdev, &(pdev->protocol->devices), protocol_list) {
if ( ! strcmp ( V_18 -> V_23 [ 0 ] . V_23 , V_60 ) )
break;
}
V_32 = F_16 ( & V_3 -> V_1 , V_1 , & V_21 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_11 ( V_1 , V_21 -> V_28 , V_3 , V_18 ) ;
if ( V_32 < 0 ) {
F_3 ( V_66 L_18 V_40 L_19 ) ;
F_34 ( V_21 ) ;
return V_32 ;
}
if ( ( V_32 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_34 ( V_21 ) ;
return V_32 ;
}
F_46 ( V_3 , V_21 ) ;
V_1 ++ ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
F_34 ( F_48 ( V_3 ) ) ;
}
static int F_49 ( struct V_2 * V_3 , T_1 V_58 )
{
return F_38 ( F_48 ( V_3 ) ) ;
}
static int F_50 ( struct V_2 * V_3 )
{
return F_40 ( F_48 ( V_3 ) ) ;
}
static int F_51 ( struct V_20 * V_67 ,
const struct V_22 * V_68 )
{
static int V_1 ;
struct V_27 * V_21 ;
int V_69 ;
for ( ; V_1 < V_63 ; V_1 ++ ) {
if ( V_51 [ V_1 ] && V_64 [ V_1 ] )
break;
}
if ( V_1 >= V_63 )
return - V_65 ;
V_69 = F_16 ( & V_67 -> V_21 -> V_1 , V_1 , & V_21 ) ;
if ( V_69 < 0 )
return V_69 ;
if ( ( V_69 = F_12 ( V_1 , V_21 -> V_28 , V_67 , V_68 ) ) < 0 ) {
F_3 ( V_66 L_20 V_40
L_21 ) ;
F_34 ( V_21 ) ;
return V_69 ;
}
if ( ( V_69 = F_18 ( V_21 , V_1 ) ) < 0 ) {
F_34 ( V_21 ) ;
return V_69 ;
}
F_52 ( V_67 , V_21 ) ;
V_1 ++ ;
return 0 ;
}
static void F_53 ( struct V_20 * V_67 )
{
F_34 ( F_54 ( V_67 ) ) ;
F_52 ( V_67 , NULL ) ;
}
static int F_55 ( struct V_20 * V_67 , T_1 V_58 )
{
return F_38 ( F_54 ( V_67 ) ) ;
}
static int F_56 ( struct V_20 * V_67 )
{
return F_40 ( F_54 ( V_67 ) ) ;
}
static int T_2 F_57 ( void )
{
int V_32 ;
V_32 = F_58 ( & V_70 , V_63 ) ;
#ifdef F_59
if ( ! V_32 )
V_71 = 1 ;
V_32 = F_60 ( & V_72 ) ;
if ( ! V_32 )
V_73 = 1 ;
V_32 = F_61 ( & V_74 ) ;
if ( ! V_32 )
V_75 = 1 ;
if ( V_73 )
V_32 = 0 ;
if ( V_71 )
V_32 = 0 ;
#endif
return V_32 ;
}
static void T_3 F_62 ( void )
{
#ifdef F_59
if ( V_75 )
F_63 ( & V_74 ) ;
if ( V_73 )
F_64 ( & V_72 ) ;
if ( V_71 )
#endif
F_65 ( & V_70 ) ;
}
