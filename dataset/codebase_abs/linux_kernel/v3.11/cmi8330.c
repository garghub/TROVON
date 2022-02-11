static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , 0x00 , 0x00 ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_7 ) ; V_3 ++ ) {
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_2 , V_7 [ V_3 ] [ 0 ] ,
V_7 [ V_3 ] [ 1 ] ) ;
F_4 ( & V_2 -> V_6 , V_5 ) ;
}
for ( V_3 = 0 ; V_3 < F_5 ( V_8 ) ; V_3 ++ ) {
if ( ( V_4 = F_6 ( V_2 , & V_8 [ V_3 ] ) ) < 0 )
return V_4 ;
}
return 0 ;
}
static int F_7 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
unsigned int V_3 ;
int V_4 ;
strcpy ( V_10 -> V_13 , ( V_12 -> type == V_14 ) ? L_1 : L_2 ) ;
for ( V_3 = 0 ; V_3 < F_5 ( V_15 ) ; V_3 ++ ) {
V_4 = F_8 ( V_10 ,
F_9 ( & V_15 [ V_3 ] ,
V_12 -> V_16 ) ) ;
if ( V_4 < 0 )
return V_4 ;
}
#ifdef F_10
if ( ( V_4 = F_1 ( V_12 -> V_17 ) ) < 0 )
return V_4 ;
#endif
return 0 ;
}
static int F_11 ( int V_18 , struct V_11 * V_12 ,
struct V_19 * V_10 ,
const struct V_20 * V_21 )
{
struct V_22 * V_23 ;
int V_4 ;
V_12 -> type = ( V_21 -> V_24 [ 3 ] . V_21 [ 0 ] ) ? V_14 : V_25 ;
V_12 -> V_26 = F_12 ( V_10 , V_21 -> V_24 [ 0 ] . V_21 , NULL ) ;
if ( V_12 -> V_26 == NULL )
return - V_27 ;
V_12 -> V_28 = F_12 ( V_10 , V_21 -> V_24 [ 1 ] . V_21 , NULL ) ;
if ( V_12 -> V_28 == NULL )
return - V_27 ;
V_12 -> V_29 = F_12 ( V_10 , V_21 -> V_24 [ 2 ] . V_21 , NULL ) ;
if ( V_12 -> V_29 == NULL )
return - V_27 ;
V_23 = V_12 -> V_26 ;
V_4 = F_13 ( V_23 ) ;
if ( V_4 < 0 ) {
F_14 ( V_30 L_3 ) ;
return - V_27 ;
}
V_31 [ V_18 ] = F_15 ( V_23 , 0 ) ;
V_32 [ V_18 ] = F_16 ( V_23 , 0 ) ;
V_33 [ V_18 ] = F_17 ( V_23 , 0 ) ;
if ( F_15 ( V_23 , 1 ) )
V_34 [ V_18 ] = F_15 ( V_23 , 1 ) ;
V_23 = V_12 -> V_28 ;
V_4 = F_13 ( V_23 ) ;
if ( V_4 < 0 ) {
F_14 ( V_30 L_4 ) ;
return - V_27 ;
}
V_35 [ V_18 ] = F_15 ( V_23 , 0 ) ;
V_36 [ V_18 ] = F_16 ( V_23 , 0 ) ;
V_37 [ V_18 ] = F_16 ( V_23 , 1 ) ;
V_38 [ V_18 ] = F_17 ( V_23 , 0 ) ;
if ( V_34 [ V_18 ] == V_39 ) {
if ( F_15 ( V_23 , 1 ) )
V_34 [ V_18 ] = F_15 ( V_23 , 1 ) ;
else
V_34 [ V_18 ] = 0x388 ;
}
V_23 = V_12 -> V_29 ;
V_4 = F_13 ( V_23 ) ;
if ( V_4 < 0 )
F_14 ( V_30 L_5 ) ;
else {
V_40 [ V_18 ] = F_15 ( V_23 , 0 ) ;
V_41 [ V_18 ] = F_17 ( V_23 , 0 ) ;
}
return 0 ;
}
static int F_18 ( struct V_42 * V_43 )
{
struct V_11 * V_2 = F_19 ( V_43 ) ;
V_43 -> V_44 = V_2 -> V_45 [ V_46 ] . V_44 ;
return V_2 -> V_45 [ V_46 ] . F_20 ( V_43 ) ;
}
static int F_21 ( struct V_42 * V_43 )
{
struct V_11 * V_2 = F_19 ( V_43 ) ;
V_43 -> V_44 = V_2 -> V_45 [ V_47 ] . V_44 ;
return V_2 -> V_45 [ V_47 ] . F_20 ( V_43 ) ;
}
static int F_22 ( struct V_9 * V_10 , struct V_11 * V_2 )
{
struct V_48 * V_49 ;
const struct V_50 * V_51 ;
int V_4 ;
static T_1 V_52 [ 2 ] = {
F_18 ,
F_21
} ;
if ( ( V_4 = F_23 ( V_10 , ( V_2 -> type == V_14 ) ? L_1 : L_6 , 0 , 1 , 1 , & V_49 ) ) < 0 )
return V_4 ;
strcpy ( V_49 -> V_53 , ( V_2 -> type == V_14 ) ? L_1 : L_6 ) ;
V_49 -> V_44 = V_2 ;
V_51 = F_24 ( V_54 ) ;
V_2 -> V_45 [ V_54 ] . V_51 = * V_51 ;
V_2 -> V_45 [ V_54 ] . F_20 = V_51 -> F_20 ;
V_2 -> V_45 [ V_54 ] . V_51 . F_20 = V_52 [ V_54 ] ;
V_2 -> V_45 [ V_54 ] . V_44 = V_2 -> V_17 ;
V_51 = F_25 ( V_55 ) ;
V_2 -> V_45 [ V_55 ] . V_51 = * V_51 ;
V_2 -> V_45 [ V_55 ] . F_20 = V_51 -> F_20 ;
V_2 -> V_45 [ V_55 ] . V_51 . F_20 = V_52 [ V_55 ] ;
V_2 -> V_45 [ V_55 ] . V_44 = V_2 -> V_16 ;
F_26 ( V_49 , V_46 , & V_2 -> V_45 [ V_46 ] . V_51 ) ;
F_26 ( V_49 , V_47 , & V_2 -> V_45 [ V_47 ] . V_51 ) ;
F_27 ( V_49 , V_56 ,
F_28 () ,
64 * 1024 , 128 * 1024 ) ;
V_2 -> V_49 = V_49 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_44 ;
F_30 ( V_10 , V_57 ) ;
F_31 ( V_12 -> V_49 ) ;
V_12 -> V_16 -> V_58 ( V_12 -> V_16 ) ;
F_32 ( V_12 -> V_17 ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_44 ;
F_34 ( V_12 -> V_17 ) ;
F_32 ( V_12 -> V_17 ) ;
V_12 -> V_16 -> V_59 ( V_12 -> V_16 ) ;
F_30 ( V_10 , V_60 ) ;
return 0 ;
}
static int F_35 ( int V_18 , struct V_9 * * V_61 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_4 ;
V_4 = F_36 ( V_62 [ V_18 ] , V_21 [ V_18 ] , V_63 ,
sizeof( struct V_11 ) , & V_10 ) ;
if ( V_4 < 0 ) {
F_14 (KERN_ERR PFX L_7 ) ;
return V_4 ;
}
V_12 = V_10 -> V_44 ;
V_12 -> V_10 = V_10 ;
* V_61 = V_10 ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 , int V_18 )
{
struct V_11 * V_12 ;
int V_64 , V_4 ;
struct V_65 * V_66 ;
V_12 = V_10 -> V_44 ;
V_4 = F_38 ( V_10 , V_31 [ V_18 ] + 4 , - 1 ,
V_33 [ V_18 ] ,
V_32 [ V_18 ] , - 1 ,
V_67 , 0 , & V_12 -> V_16 ) ;
if ( V_4 < 0 ) {
F_14 (KERN_ERR PFX L_8 ) ;
return V_4 ;
}
if ( V_12 -> V_16 -> V_68 != V_69 ) {
F_14 (KERN_ERR PFX L_9 ) ;
return - V_70 ;
}
if ( ( V_4 = F_39 ( V_10 , V_35 [ V_18 ] ,
V_38 [ V_18 ] ,
V_71 ,
V_36 [ V_18 ] ,
V_37 [ V_18 ] ,
V_72 , & V_12 -> V_17 ) ) < 0 ) {
F_14 (KERN_ERR PFX L_10 ) ;
return V_4 ;
}
if ( V_12 -> V_17 -> V_68 != V_73 ) {
F_14 (KERN_ERR PFX L_11 ) ;
return V_4 ;
}
F_40 ( V_12 -> V_16 , V_74 , 0x40 ) ;
for ( V_64 = V_75 ; V_64 <= V_76 ; V_64 ++ )
F_40 ( V_12 -> V_16 , V_64 ,
V_77 [ V_64 - V_75 ] ) ;
if ( ( V_4 = F_7 ( V_10 , V_12 ) ) < 0 ) {
F_14 (KERN_ERR PFX L_12 ) ;
return V_4 ;
}
if ( ( V_4 = F_22 ( V_10 , V_12 ) ) < 0 ) {
F_14 (KERN_ERR PFX L_13 ) ;
return V_4 ;
}
if ( V_34 [ V_18 ] != V_39 ) {
if ( F_41 ( V_10 ,
V_34 [ V_18 ] , V_34 [ V_18 ] + 2 ,
V_78 , 0 , & V_66 ) < 0 ) {
F_14 (KERN_ERR PFX
L_14 ,
fmport[dev], fmport[dev] + 2 ) ;
} else {
V_4 = F_42 ( V_66 , 0 , 1 , NULL ) ;
if ( V_4 < 0 )
return V_4 ;
}
}
if ( V_40 [ V_18 ] != V_39 ) {
if ( F_43 ( V_10 , 0 , V_79 ,
V_40 [ V_18 ] , 0 , V_41 [ V_18 ] ,
NULL ) < 0 )
F_44 (KERN_ERR PFX L_15 ,
mpuport[dev]) ;
}
strcpy ( V_10 -> V_80 , ( V_12 -> type == V_14 ) ? L_1 : L_2 ) ;
strcpy ( V_10 -> V_81 , ( V_12 -> type == V_14 ) ? L_16 : L_17 ) ;
sprintf ( V_10 -> V_82 , L_18 ,
V_10 -> V_81 ,
V_12 -> V_16 -> V_83 ,
V_33 [ V_18 ] ,
V_32 [ V_18 ] ) ;
return F_45 ( V_10 ) ;
}
static int F_46 ( struct V_84 * V_23 ,
unsigned int V_18 )
{
if ( ! V_85 [ V_18 ] || F_47 ( V_18 ) )
return 0 ;
if ( V_31 [ V_18 ] == V_39 ) {
F_14 (KERN_ERR PFX L_19 ) ;
return 0 ;
}
if ( V_35 [ V_18 ] == V_39 ) {
F_14 (KERN_ERR PFX L_20 ) ;
return 0 ;
}
return 1 ;
}
static int F_48 ( struct V_84 * V_23 ,
unsigned int V_18 )
{
struct V_9 * V_10 ;
int V_4 ;
V_4 = F_35 ( V_18 , & V_10 ) ;
if ( V_4 < 0 )
return V_4 ;
F_49 ( V_10 , V_23 ) ;
if ( ( V_4 = F_37 ( V_10 , V_18 ) ) < 0 ) {
F_50 ( V_10 ) ;
return V_4 ;
}
F_51 ( V_23 , V_10 ) ;
return 0 ;
}
static int F_52 ( struct V_84 * V_86 ,
unsigned int V_18 )
{
F_50 ( F_53 ( V_86 ) ) ;
return 0 ;
}
static int F_54 ( struct V_84 * V_18 , unsigned int V_87 ,
T_2 V_88 )
{
return F_29 ( F_53 ( V_18 ) ) ;
}
static int F_55 ( struct V_84 * V_18 , unsigned int V_87 )
{
return F_33 ( F_53 ( V_18 ) ) ;
}
static int F_56 ( struct V_19 * V_89 ,
const struct V_20 * V_90 )
{
static int V_18 ;
struct V_9 * V_10 ;
int V_91 ;
for ( ; V_18 < V_92 ; V_18 ++ ) {
if ( V_85 [ V_18 ] && V_93 [ V_18 ] )
break;
}
if ( V_18 >= V_92 )
return - V_70 ;
V_91 = F_35 ( V_18 , & V_10 ) ;
if ( V_91 < 0 )
return V_91 ;
if ( ( V_91 = F_11 ( V_18 , V_10 -> V_44 , V_89 , V_90 ) ) < 0 ) {
F_14 (KERN_ERR PFX L_21 ) ;
F_50 ( V_10 ) ;
return V_91 ;
}
F_49 ( V_10 , & V_89 -> V_10 -> V_18 ) ;
if ( ( V_91 = F_37 ( V_10 , V_18 ) ) < 0 ) {
F_50 ( V_10 ) ;
return V_91 ;
}
F_57 ( V_89 , V_10 ) ;
V_18 ++ ;
return 0 ;
}
static void F_58 ( struct V_19 * V_89 )
{
F_50 ( F_59 ( V_89 ) ) ;
F_57 ( V_89 , NULL ) ;
}
static int F_60 ( struct V_19 * V_89 , T_2 V_88 )
{
return F_29 ( F_59 ( V_89 ) ) ;
}
static int F_61 ( struct V_19 * V_89 )
{
return F_33 ( F_59 ( V_89 ) ) ;
}
static int T_3 F_62 ( void )
{
int V_4 ;
V_4 = F_63 ( & V_94 , V_92 ) ;
#ifdef F_64
if ( ! V_4 )
V_95 = 1 ;
V_4 = F_65 ( & V_96 ) ;
if ( ! V_4 )
V_97 = 1 ;
if ( V_95 )
V_4 = 0 ;
#endif
return V_4 ;
}
static void T_4 F_66 ( void )
{
#ifdef F_64
if ( V_97 )
F_67 ( & V_96 ) ;
if ( V_95 )
#endif
F_68 ( & V_94 ) ;
}
