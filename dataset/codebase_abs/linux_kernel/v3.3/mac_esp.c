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
if ( F_20 () )
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
static void F_22 ( struct V_1 * V_1 , V_13 V_14 , V_13 V_22 ,
V_13 V_23 , int V_24 , T_1 V_25 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
V_16 -> error = 0 ;
if ( ! V_24 )
F_23 ( V_1 , V_26 ) ;
F_24 ( ( V_22 >> 0 ) & 0xFF , V_27 ) ;
F_24 ( ( V_22 >> 8 ) & 0xFF , V_28 ) ;
F_23 ( V_1 , V_25 ) ;
do {
unsigned int V_29 = V_22 >> 5 ;
unsigned int V_30 = ( V_22 & 0x1F ) >> 1 ;
unsigned int V_31 = V_22 & 1 ;
unsigned int V_32 = V_14 ;
if ( F_19 ( V_1 ) )
break;
if ( V_24 ) {
F_25 ( L_3 ) ;
V_22 -= V_14 - V_32 ;
} else {
unsigned int V_33 ;
F_25 ( L_4 ) ;
if ( F_15 ( V_1 ) )
break;
V_33 = ( F_16 ( V_28 ) << 8 ) + F_16 ( V_27 ) ;
V_14 = V_32 + V_22 - V_33 ;
V_22 = V_33 ;
}
} while ( V_22 );
}
static inline unsigned int F_26 ( struct V_1 * V_1 )
{
int V_11 = 500000 ;
do {
unsigned int V_34 = F_16 ( V_17 ) & V_18 ;
if ( V_34 )
return V_34 ;
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
V_1 -> V_35 = F_16 ( V_19 ) ;
if ( V_1 -> V_35 & V_20 )
return 0 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_6 , esp->sreg) ;
V_16 -> error = 1 ;
return 1 ;
}
static void F_28 ( struct V_1 * V_1 , V_13 V_14 , V_13 V_22 ,
V_13 V_23 , int V_24 , T_1 V_25 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
T_1 * V_36 = V_1 -> V_4 + V_37 * 16 ;
V_25 &= ~ V_38 ;
V_16 -> error = 0 ;
if ( V_24 ) {
F_23 ( V_1 , V_25 ) ;
while ( 1 ) {
unsigned int V_33 ;
V_33 = F_26 ( V_1 ) ;
if ( ! V_33 )
break;
if ( V_33 > V_22 )
V_33 = V_22 ;
V_22 -= V_33 ;
F_29 ( L_7 , V_33 ) ;
if ( ! V_22 )
break;
if ( F_27 ( V_1 ) )
break;
if ( ( ( V_1 -> V_35 & V_39 ) != V_40 ) &&
( ( V_1 -> V_35 & V_39 ) != V_41 ) )
break;
V_1 -> V_42 = F_16 ( V_43 ) ;
if ( ( V_1 -> V_42 & ( V_44 | V_45 ) ) !=
V_45 )
break;
F_23 ( V_1 , V_46 ) ;
}
} else {
F_23 ( V_1 , V_26 ) ;
if ( V_22 >= V_47 )
F_30 ( L_8 , V_22 ) ;
else
F_29 ( L_8 , V_22 ) ;
F_23 ( V_1 , V_25 ) ;
while ( V_22 ) {
unsigned int V_33 ;
if ( F_27 ( V_1 ) )
break;
if ( ( ( V_1 -> V_35 & V_39 ) != V_48 ) &&
( ( V_1 -> V_35 & V_39 ) != V_49 ) )
break;
V_1 -> V_42 = F_16 ( V_43 ) ;
if ( ( V_1 -> V_42 & ( V_44 | V_45 ) ) !=
V_45 )
break;
V_33 = V_47 -
( F_16 ( V_17 ) & V_18 ) ;
if ( V_33 > V_22 )
V_33 = V_22 ;
if ( V_33 == V_47 ) {
F_30 ( L_8 , V_22 ) ;
} else {
V_22 -= V_33 ;
F_29 ( L_8 , V_33 ) ;
}
F_23 ( V_1 , V_46 ) ;
}
}
}
static int F_31 ( struct V_1 * V_1 )
{
if ( F_16 ( V_19 ) & V_20 )
return 1 ;
return 0 ;
}
static V_13 F_32 ( struct V_1 * V_1 , V_13 V_50 , V_13 V_51 )
{
return V_51 > 0xFFFF ? 0xFFFF : V_51 ;
}
static T_4 F_33 ( int V_52 , void * V_53 )
{
int V_54 ;
do {
V_54 = 0 ;
if ( V_55 [ 0 ] &&
( F_3 ( V_55 [ 0 ] , V_19 ) & V_20 ) ) {
( void ) F_34 ( V_52 , V_55 [ 0 ] ) ;
V_54 = 1 ;
}
if ( V_55 [ 1 ] &&
( F_3 ( V_55 [ 1 ] , V_19 ) & V_20 ) ) {
( void ) F_34 ( V_52 , V_55 [ 1 ] ) ;
V_54 = 1 ;
}
} while ( V_54 );
return V_56 ;
}
static int T_5 F_35 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = & V_61 ;
struct V_62 * V_63 ;
struct V_1 * V_1 ;
int V_64 ;
struct V_15 * V_16 ;
if ( ! V_65 )
return - V_66 ;
if ( V_58 -> V_67 > 1 )
return - V_66 ;
V_63 = F_36 ( V_60 , sizeof( struct V_1 ) ) ;
V_64 = - V_68 ;
if ( ! V_63 )
goto V_69;
V_63 -> V_70 = 8 ;
V_63 -> V_71 = V_72 ;
V_1 = F_37 ( V_63 ) ;
V_1 -> V_63 = V_63 ;
V_1 -> V_58 = V_58 ;
V_1 -> V_73 = F_38 ( 16 , V_74 ) ;
if ( ! V_1 -> V_73 )
goto V_75;
V_1 -> V_76 = ( T_2 ) V_1 -> V_73 ;
V_1 -> V_77 = 7 ;
V_63 -> V_78 = V_1 -> V_77 ;
V_1 -> V_79 = 1 << V_1 -> V_77 ;
V_16 = F_38 ( sizeof( struct V_15 ) , V_74 ) ;
if ( ! V_16 )
goto V_80;
V_16 -> V_1 = V_1 ;
F_39 ( V_58 , V_16 ) ;
switch ( V_81 -> V_82 ) {
case V_83 :
V_1 -> V_84 = 16500000 ;
V_1 -> V_4 = ( void V_85 * ) V_86 ;
V_16 -> V_87 = V_1 -> V_4 + V_88 ;
V_16 -> V_21 = NULL ;
break;
case V_89 :
V_1 -> V_84 = 25000000 ;
V_1 -> V_4 = ( void V_85 * ) ( V_90 +
V_58 -> V_67 * V_91 ) ;
V_16 -> V_87 = V_1 -> V_4 + V_88 ;
V_16 -> V_21 = ( void V_85 * ) ( V_92 +
V_58 -> V_67 * V_93 ) ;
F_40 ( 0x1d1 , V_16 -> V_21 ) ;
break;
case V_94 :
V_1 -> V_84 = 25000000 ;
V_1 -> V_4 = ( void V_85 * ) V_95 ;
V_16 -> V_87 = NULL ;
V_16 -> V_21 = NULL ;
break;
}
V_1 -> V_96 = & V_97 ;
if ( V_16 -> V_87 == NULL ) {
F_18 (KERN_INFO PFX L_9 , dev->id) ;
F_24 ( 0 , V_27 ) ;
F_24 ( 0 , V_28 ) ;
V_1 -> V_98 = V_99 ;
V_97 . V_100 = F_28 ;
} else {
F_18 (KERN_INFO PFX L_10 , dev->id) ;
}
V_63 -> V_52 = V_101 ;
V_55 [ V_58 -> V_67 ] = V_1 ;
F_41 () ;
if ( V_55 [ ! V_58 -> V_67 ] == NULL ) {
V_64 = F_42 ( V_63 -> V_52 , F_33 , 0 , L_11 , NULL ) ;
if ( V_64 < 0 ) {
V_55 [ V_58 -> V_67 ] = NULL ;
goto V_102;
}
}
V_64 = F_43 ( V_1 , & V_58 -> V_58 ) ;
if ( V_64 )
goto V_103;
return 0 ;
V_103:
if ( V_55 [ ! V_58 -> V_67 ] == NULL )
F_44 ( V_63 -> V_52 , V_1 ) ;
V_102:
F_45 ( V_16 ) ;
V_80:
F_45 ( V_1 -> V_73 ) ;
V_75:
F_46 ( V_63 ) ;
V_69:
return V_64 ;
}
static int T_6 F_47 ( struct V_57 * V_58 )
{
struct V_15 * V_16 = F_48 ( V_58 ) ;
struct V_1 * V_1 = V_16 -> V_1 ;
unsigned int V_52 = V_1 -> V_63 -> V_52 ;
F_49 ( V_1 ) ;
V_55 [ V_58 -> V_67 ] = NULL ;
if ( ! ( V_55 [ 0 ] || V_55 [ 1 ] ) )
F_44 ( V_52 , NULL ) ;
F_45 ( V_16 ) ;
F_45 ( V_1 -> V_73 ) ;
F_46 ( V_1 -> V_63 ) ;
return 0 ;
}
static int T_7 F_50 ( void )
{
return F_51 ( & V_104 ) ;
}
static void T_8 F_52 ( void )
{
F_53 ( & V_104 ) ;
}
