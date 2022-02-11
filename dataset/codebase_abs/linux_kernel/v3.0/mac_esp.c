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
unsigned long V_27 ;
F_23 ( V_27 ) ;
V_16 -> error = 0 ;
if ( ! V_25 )
F_24 ( V_1 , V_28 ) ;
F_25 ( ( V_23 >> 0 ) & 0xFF , V_29 ) ;
F_25 ( ( V_23 >> 8 ) & 0xFF , V_30 ) ;
F_24 ( V_1 , V_26 ) ;
do {
unsigned int V_31 = V_23 >> 5 ;
unsigned int V_32 = ( V_23 & 0x1F ) >> 1 ;
unsigned int V_33 = V_23 & 1 ;
unsigned int V_34 = V_14 ;
if ( F_19 ( V_1 ) )
break;
if ( V_25 ) {
F_26 ( L_3 ) ;
V_23 -= V_14 - V_34 ;
} else {
unsigned int V_35 ;
F_26 ( L_4 ) ;
if ( F_15 ( V_1 ) )
break;
V_35 = ( F_16 ( V_30 ) << 8 ) + F_16 ( V_29 ) ;
V_14 = V_34 + V_23 - V_35 ;
V_23 = V_35 ;
}
} while ( V_23 );
F_27 ( V_27 ) ;
}
static inline unsigned int F_28 ( struct V_1 * V_1 )
{
int V_11 = 500000 ;
do {
unsigned int V_36 = F_16 ( V_17 ) & V_18 ;
if ( V_36 )
return V_36 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_5 ,
esp_read8(ESP_STATUS)) ;
return 0 ;
}
static inline int F_29 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
int V_11 = 500000 ;
do {
V_1 -> V_37 = F_16 ( V_19 ) ;
if ( V_1 -> V_37 & V_20 )
return 0 ;
F_17 ( 2 ) ;
} while ( -- V_11 );
F_18 (KERN_ERR PFX L_6 , esp->sreg) ;
V_16 -> error = 1 ;
return 1 ;
}
static void F_30 ( struct V_1 * V_1 , V_13 V_14 , V_13 V_23 ,
V_13 V_24 , int V_25 , T_1 V_26 )
{
struct V_15 * V_16 = F_14 ( V_1 ) ;
T_1 * V_38 = V_1 -> V_4 + V_39 * 16 ;
F_31 ( V_1 -> V_40 -> V_41 ) ;
V_26 &= ~ V_42 ;
V_16 -> error = 0 ;
if ( V_25 ) {
F_24 ( V_1 , V_26 ) ;
while ( 1 ) {
unsigned int V_35 ;
V_35 = F_28 ( V_1 ) ;
if ( ! V_35 )
break;
if ( V_35 > V_23 )
V_35 = V_23 ;
V_23 -= V_35 ;
F_32 ( L_7 , V_35 ) ;
if ( ! V_23 )
break;
if ( F_29 ( V_1 ) )
break;
if ( ( ( V_1 -> V_37 & V_43 ) != V_44 ) &&
( ( V_1 -> V_37 & V_43 ) != V_45 ) )
break;
V_1 -> V_46 = F_16 ( V_47 ) ;
if ( ( V_1 -> V_46 & ( V_48 | V_49 ) ) !=
V_49 )
break;
F_24 ( V_1 , V_50 ) ;
}
} else {
F_24 ( V_1 , V_28 ) ;
if ( V_23 >= V_51 )
F_33 ( L_8 , V_23 ) ;
else
F_32 ( L_8 , V_23 ) ;
F_24 ( V_1 , V_26 ) ;
while ( V_23 ) {
unsigned int V_35 ;
if ( F_29 ( V_1 ) )
break;
if ( ( ( V_1 -> V_37 & V_43 ) != V_52 ) &&
( ( V_1 -> V_37 & V_43 ) != V_53 ) )
break;
V_1 -> V_46 = F_16 ( V_47 ) ;
if ( ( V_1 -> V_46 & ( V_48 | V_49 ) ) !=
V_49 )
break;
V_35 = V_51 -
( F_16 ( V_17 ) & V_18 ) ;
if ( V_35 > V_23 )
V_35 = V_23 ;
if ( V_35 == V_51 ) {
F_33 ( L_8 , V_23 ) ;
} else {
V_23 -= V_35 ;
F_32 ( L_8 , V_35 ) ;
}
F_24 ( V_1 , V_50 ) ;
}
}
F_34 ( V_1 -> V_40 -> V_41 ) ;
}
static int F_35 ( struct V_1 * V_1 )
{
if ( F_16 ( V_19 ) & V_20 )
return 1 ;
return 0 ;
}
static V_13 F_36 ( struct V_1 * V_1 , V_13 V_54 , V_13 V_55 )
{
return V_55 > 0xFFFF ? 0xFFFF : V_55 ;
}
static T_4 F_37 ( int V_41 , void * V_56 )
{
int V_57 ;
do {
V_57 = 0 ;
if ( V_58 [ 0 ] &&
( F_3 ( V_58 [ 0 ] , V_19 ) & V_20 ) ) {
( void ) F_38 ( V_41 , V_58 [ 0 ] ) ;
V_57 = 1 ;
}
if ( V_58 [ 1 ] &&
( F_3 ( V_58 [ 1 ] , V_19 ) & V_20 ) ) {
( void ) F_38 ( V_41 , V_58 [ 1 ] ) ;
V_57 = 1 ;
}
} while ( V_57 );
return V_59 ;
}
static int T_5 F_39 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_64 ;
struct V_65 * V_40 ;
struct V_1 * V_1 ;
int V_66 ;
struct V_15 * V_16 ;
if ( ! V_67 )
return - V_68 ;
if ( V_61 -> V_69 > 1 )
return - V_68 ;
V_40 = F_40 ( V_63 , sizeof( struct V_1 ) ) ;
V_66 = - V_70 ;
if ( ! V_40 )
goto V_71;
V_40 -> V_72 = 8 ;
V_40 -> V_73 = V_74 ;
V_1 = F_41 ( V_40 ) ;
V_1 -> V_40 = V_40 ;
V_1 -> V_61 = V_61 ;
V_1 -> V_75 = F_42 ( 16 , V_76 ) ;
if ( ! V_1 -> V_75 )
goto V_77;
V_1 -> V_78 = ( T_2 ) V_1 -> V_75 ;
V_1 -> V_79 = 7 ;
V_40 -> V_80 = V_1 -> V_79 ;
V_1 -> V_81 = 1 << V_1 -> V_79 ;
V_16 = F_42 ( sizeof( struct V_15 ) , V_76 ) ;
if ( ! V_16 )
goto V_82;
V_16 -> V_1 = V_1 ;
F_43 ( V_61 , V_16 ) ;
switch ( V_83 -> V_84 ) {
case V_85 :
V_1 -> V_86 = 16500000 ;
V_1 -> V_4 = ( void V_87 * ) V_88 ;
V_16 -> V_89 = V_1 -> V_4 + V_90 ;
V_16 -> V_21 = NULL ;
break;
case V_91 :
V_1 -> V_86 = 25000000 ;
V_1 -> V_4 = ( void V_87 * ) ( V_92 +
V_61 -> V_69 * V_93 ) ;
V_16 -> V_89 = V_1 -> V_4 + V_90 ;
V_16 -> V_21 = ( void V_87 * ) ( V_94 +
V_61 -> V_69 * V_95 ) ;
F_44 ( 0x1d1 , V_16 -> V_21 ) ;
break;
case V_96 :
V_1 -> V_86 = 25000000 ;
V_1 -> V_4 = ( void V_87 * ) V_97 ;
V_16 -> V_89 = NULL ;
V_16 -> V_21 = NULL ;
break;
}
V_1 -> V_98 = & V_99 ;
if ( V_16 -> V_89 == NULL ) {
F_18 (KERN_INFO PFX L_9 , dev->id) ;
F_25 ( 0 , V_29 ) ;
F_25 ( 0 , V_30 ) ;
V_1 -> V_27 = V_100 ;
V_99 . V_101 = F_30 ;
} else {
F_18 (KERN_INFO PFX L_10 , dev->id) ;
}
V_40 -> V_41 = V_102 ;
V_58 [ V_61 -> V_69 ] = V_1 ;
F_45 () ;
if ( V_58 [ ! V_61 -> V_69 ] == NULL ) {
V_66 = F_46 ( V_40 -> V_41 , F_37 , 0 ,
L_11 , NULL ) ;
if ( V_66 < 0 ) {
V_58 [ V_61 -> V_69 ] = NULL ;
goto V_103;
}
}
V_66 = F_47 ( V_1 , & V_61 -> V_61 ) ;
if ( V_66 )
goto V_104;
return 0 ;
V_104:
if ( V_58 [ ! V_61 -> V_69 ] == NULL )
F_48 ( V_40 -> V_41 , V_1 ) ;
V_103:
F_49 ( V_16 ) ;
V_82:
F_49 ( V_1 -> V_75 ) ;
V_77:
F_50 ( V_40 ) ;
V_71:
return V_66 ;
}
static int T_6 F_51 ( struct V_60 * V_61 )
{
struct V_15 * V_16 = F_52 ( V_61 ) ;
struct V_1 * V_1 = V_16 -> V_1 ;
unsigned int V_41 = V_1 -> V_40 -> V_41 ;
F_53 ( V_1 ) ;
V_58 [ V_61 -> V_69 ] = NULL ;
if ( ! ( V_58 [ 0 ] || V_58 [ 1 ] ) )
F_48 ( V_41 , NULL ) ;
F_49 ( V_16 ) ;
F_49 ( V_1 -> V_75 ) ;
F_50 ( V_1 -> V_40 ) ;
return 0 ;
}
static int T_7 F_54 ( void )
{
return F_55 ( & V_105 ) ;
}
static void T_8 F_56 ( void )
{
F_57 ( & V_105 ) ;
}
