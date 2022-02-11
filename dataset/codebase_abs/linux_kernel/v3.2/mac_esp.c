static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 , unsigned long V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + V_3 * 16 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_1 , unsigned long V_3 )
{
return F_4 ( V_1 -> V_4 + V_3 * 16 ) ;
}
static T_2 F_5 ( struct V_1 * V_1 , void * V_5 ,
T_3 V_6 , int V_7 )
{
return ( T_2 ) V_5 ;
}
static int F_6 ( struct V_1 * V_1 , struct V_8 * V_9 ,
int V_10 , int V_7 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_9 [ V_11 ] . V_12 = ( V_13 ) F_7 ( & V_9 [ V_11 ] ) ;
return V_10 ;
}
static void F_8 ( struct V_1 * V_1 , T_2 V_14 ,
T_3 V_6 , int V_7 )
{
}
static void F_9 ( struct V_1 * V_1 , struct V_8 * V_9 ,
int V_10 , int V_7 )
{
}
static void F_10 ( struct V_1 * V_1 )
{
}
static void F_11 ( struct V_1 * V_1 )
{
}
static void F_12 ( struct V_1 * V_1 )
{
}
static int F_13 ( struct V_1 * V_1 )
{
return F_14 ( V_1 ) -> error ;
}
static inline int F_15 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
int V_11 = 500000 ;
do {
if ( ! ( F_16 ( V_17 ) & V_18 ) )
return 0 ;
if ( F_16 ( V_19 ) & V_20 )
return 1 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_1 ,
esp_read8(ESP_STATUS)) ;
V_16 -> error = 1 ;
return 1 ;
}
static inline int F_19 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
int V_11 = 500000 ;
do {
if ( V_16 -> V_21 == NULL ) {
if ( F_20 ( V_22 ) )
return 0 ;
} else {
if ( F_21 ( V_16 -> V_21 ) & 0x200 )
return 0 ;
}
if ( F_16 ( V_19 ) & V_20 )
return 1 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_2 ,
esp_read8(ESP_STATUS)) ;
V_16 -> error = 1 ;
return 1 ;
}
static void F_22 ( struct V_1 * V_1 , V_13 V_14 , V_13 V_23 ,
V_13 V_24 , int V_25 , T_1 V_26 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
V_16 -> error = 0 ;
if ( ! V_25 )
F_23 ( V_1 , V_27 ) ;
F_24 ( ( V_23 >> 0 ) & 0xFF , V_28 ) ;
F_24 ( ( V_23 >> 8 ) & 0xFF , V_29 ) ;
F_23 ( V_1 , V_26 ) ;
do {
unsigned int V_30 = V_23 >> 5 ;
unsigned int V_31 = ( V_23 & 0x1F ) >> 1 ;
unsigned int V_32 = V_23 & 1 ;
unsigned int V_33 = V_14 ;
if ( F_19 ( V_1 ) )
break;
if ( V_25 ) {
F_25 ( L_3 ) ;
V_23 -= V_14 - V_33 ;
} else {
unsigned int V_34 ;
F_25 ( L_4 ) ;
if ( F_15 ( V_1 ) )
break;
V_34 = ( F_16 ( V_29 ) << 8 ) + F_16 ( V_28 ) ;
V_14 = V_33 + V_23 - V_34 ;
V_23 = V_34 ;
}
} while ( V_23 );
}
static inline unsigned int F_26 ( struct V_1 * V_1 )
{
int V_11 = 500000 ;
do {
unsigned int V_35 = F_16 ( V_17 ) & V_18 ;
if ( V_35 )
return V_35 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_5 ,
esp_read8(ESP_STATUS)) ;
return 0 ;
}
static inline int F_27 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
int V_11 = 500000 ;
do {
V_1 -> V_36 = F_16 ( V_19 ) ;
if ( V_1 -> V_36 & V_20 )
return 0 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_6 , esp->sreg) ;
V_16 -> error = 1 ;
return 1 ;
}
static void F_28 ( struct V_1 * V_1 , V_13 V_14 , V_13 V_23 ,
V_13 V_24 , int V_25 , T_1 V_26 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
T_1 * V_37 = V_1 -> V_4 + V_38 * 16 ;
V_26 &= ~ V_39 ;
V_16 -> error = 0 ;
if ( V_25 ) {
F_23 ( V_1 , V_26 ) ;
while ( 1 ) {
unsigned int V_34 ;
V_34 = F_26 ( V_1 ) ;
if ( ! V_34 )
break;
if ( V_34 > V_23 )
V_34 = V_23 ;
V_23 -= V_34 ;
F_29 ( L_7 , V_34 ) ;
if ( ! V_23 )
break;
if ( F_27 ( V_1 ) )
break;
if ( ( ( V_1 -> V_36 & V_40 ) != V_41 ) &&
( ( V_1 -> V_36 & V_40 ) != V_42 ) )
break;
V_1 -> V_43 = F_16 ( V_44 ) ;
if ( ( V_1 -> V_43 & ( V_45 | V_46 ) ) !=
V_46 )
break;
F_23 ( V_1 , V_47 ) ;
}
} else {
F_23 ( V_1 , V_27 ) ;
if ( V_23 >= V_48 )
F_30 ( L_8 , V_23 ) ;
else
F_29 ( L_8 , V_23 ) ;
F_23 ( V_1 , V_26 ) ;
while ( V_23 ) {
unsigned int V_34 ;
if ( F_27 ( V_1 ) )
break;
if ( ( ( V_1 -> V_36 & V_40 ) != V_49 ) &&
( ( V_1 -> V_36 & V_40 ) != V_50 ) )
break;
V_1 -> V_43 = F_16 ( V_44 ) ;
if ( ( V_1 -> V_43 & ( V_45 | V_46 ) ) !=
V_46 )
break;
V_34 = V_48 -
( F_16 ( V_17 ) & V_18 ) ;
if ( V_34 > V_23 )
V_34 = V_23 ;
if ( V_34 == V_48 ) {
F_30 ( L_8 , V_23 ) ;
} else {
V_23 -= V_34 ;
F_29 ( L_8 , V_34 ) ;
}
F_23 ( V_1 , V_47 ) ;
}
}
}
static int F_31 ( struct V_1 * V_1 )
{
if ( F_16 ( V_19 ) & V_20 )
return 1 ;
return 0 ;
}
static V_13 F_32 ( struct V_1 * V_1 , V_13 V_51 , V_13 V_52 )
{
return V_52 > 0xFFFF ? 0xFFFF : V_52 ;
}
static T_4 F_33 ( int V_53 , void * V_54 )
{
int V_55 ;
do {
V_55 = 0 ;
if ( V_56 [ 0 ] &&
( F_3 ( V_56 [ 0 ] , V_19 ) & V_20 ) ) {
( void ) F_34 ( V_53 , V_56 [ 0 ] ) ;
V_55 = 1 ;
}
if ( V_56 [ 1 ] &&
( F_3 ( V_56 [ 1 ] , V_19 ) & V_20 ) ) {
( void ) F_34 ( V_53 , V_56 [ 1 ] ) ;
V_55 = 1 ;
}
} while ( V_55 );
return V_57 ;
}
static int T_5 F_35 ( struct V_58 * V_59 )
{
struct V_60 * V_61 = & V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_1 ;
int V_65 ;
struct V_15 * V_16 ;
if ( ! V_66 )
return - V_67 ;
if ( V_59 -> V_68 > 1 )
return - V_67 ;
V_64 = F_36 ( V_61 , sizeof( struct V_1 ) ) ;
V_65 = - V_69 ;
if ( ! V_64 )
goto V_70;
V_64 -> V_71 = 8 ;
V_64 -> V_72 = V_73 ;
V_1 = F_37 ( V_64 ) ;
V_1 -> V_64 = V_64 ;
V_1 -> V_59 = V_59 ;
V_1 -> V_74 = F_38 ( 16 , V_75 ) ;
if ( ! V_1 -> V_74 )
goto V_76;
V_1 -> V_77 = ( T_2 ) V_1 -> V_74 ;
V_1 -> V_78 = 7 ;
V_64 -> V_79 = V_1 -> V_78 ;
V_1 -> V_80 = 1 << V_1 -> V_78 ;
V_16 = F_38 ( sizeof( struct V_15 ) , V_75 ) ;
if ( ! V_16 )
goto V_81;
V_16 -> V_1 = V_1 ;
F_39 ( V_59 , V_16 ) ;
switch ( V_82 -> V_83 ) {
case V_84 :
V_1 -> V_85 = 16500000 ;
V_1 -> V_4 = ( void V_86 * ) V_87 ;
V_16 -> V_88 = V_1 -> V_4 + V_89 ;
V_16 -> V_21 = NULL ;
break;
case V_90 :
V_1 -> V_85 = 25000000 ;
V_1 -> V_4 = ( void V_86 * ) ( V_91 +
V_59 -> V_68 * V_92 ) ;
V_16 -> V_88 = V_1 -> V_4 + V_89 ;
V_16 -> V_21 = ( void V_86 * ) ( V_93 +
V_59 -> V_68 * V_94 ) ;
F_40 ( 0x1d1 , V_16 -> V_21 ) ;
break;
case V_95 :
V_1 -> V_85 = 25000000 ;
V_1 -> V_4 = ( void V_86 * ) V_96 ;
V_16 -> V_88 = NULL ;
V_16 -> V_21 = NULL ;
break;
}
V_1 -> V_97 = & V_98 ;
if ( V_16 -> V_88 == NULL ) {
F_18 (KERN_INFO PFX L_9 , dev->id) ;
F_24 ( 0 , V_28 ) ;
F_24 ( 0 , V_29 ) ;
V_1 -> V_99 = V_100 ;
V_98 . V_101 = F_28 ;
} else {
F_18 (KERN_INFO PFX L_10 , dev->id) ;
}
V_64 -> V_53 = V_102 ;
V_56 [ V_59 -> V_68 ] = V_1 ;
F_41 () ;
if ( V_56 [ ! V_59 -> V_68 ] == NULL ) {
V_65 = F_42 ( V_64 -> V_53 , F_33 , 0 ,
L_11 , NULL ) ;
if ( V_65 < 0 ) {
V_56 [ V_59 -> V_68 ] = NULL ;
goto V_103;
}
}
V_65 = F_43 ( V_1 , & V_59 -> V_59 ) ;
if ( V_65 )
goto V_104;
return 0 ;
V_104:
if ( V_56 [ ! V_59 -> V_68 ] == NULL )
F_44 ( V_64 -> V_53 , V_1 ) ;
V_103:
F_45 ( V_16 ) ;
V_81:
F_45 ( V_1 -> V_74 ) ;
V_76:
F_46 ( V_64 ) ;
V_70:
return V_65 ;
}
static int T_6 F_47 ( struct V_58 * V_59 )
{
struct V_15 * V_16 = F_48 ( V_59 ) ;
struct V_1 * V_1 = V_16 -> V_1 ;
unsigned int V_53 = V_1 -> V_64 -> V_53 ;
F_49 ( V_1 ) ;
V_56 [ V_59 -> V_68 ] = NULL ;
if ( ! ( V_56 [ 0 ] || V_56 [ 1 ] ) )
F_44 ( V_53 , NULL ) ;
F_45 ( V_16 ) ;
F_45 ( V_1 -> V_74 ) ;
F_46 ( V_1 -> V_64 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
return F_51 ( & V_105 ) ;
}
static void T_8 F_52 ( void )
{
F_53 ( & V_105 ) ;
}
