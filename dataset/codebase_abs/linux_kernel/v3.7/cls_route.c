static inline int F_1 ( T_1 V_1 , int V_2 )
{
return V_1 & 0xF ;
}
static void
F_2 ( struct V_3 * V_4 , struct V_5 * V_6 , T_1 V_1 )
{
T_2 * V_7 = F_3 ( V_4 ) ;
F_4 ( V_7 ) ;
memset ( V_6 -> V_8 , 0 , sizeof( V_6 -> V_8 ) ) ;
F_5 ( V_7 ) ;
}
static void
F_6 ( struct V_5 * V_6 , T_1 V_1 , int V_2 ,
struct V_9 * V_10 )
{
int V_11 = F_1 ( V_1 , V_2 ) ;
V_6 -> V_8 [ V_11 ] . V_1 = V_1 ;
V_6 -> V_8 [ V_11 ] . V_2 = V_2 ;
V_6 -> V_8 [ V_11 ] . V_12 = V_10 ;
}
static inline int F_7 ( T_1 V_1 )
{
return V_1 & 0xFF ;
}
static inline int F_8 ( T_1 V_1 )
{
return ( V_1 >> 16 ) & 0xF ;
}
static inline int F_9 ( int V_2 )
{
return 16 + ( ( V_2 >> 16 ) & 0xF ) ;
}
static inline int F_10 ( void )
{
return 32 ;
}
static int F_11 ( struct V_13 * V_14 , const struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
struct V_9 * V_10 ;
T_1 V_1 , V_11 ;
int V_2 , V_24 = 0 ;
V_21 = F_12 ( V_14 ) ;
if ( ! V_21 )
goto V_25;
V_1 = V_21 -> V_26 ;
if ( V_6 == NULL )
goto V_27;
V_2 = F_13 ( V_14 ) ;
V_11 = F_1 ( V_1 , V_2 ) ;
if ( V_1 == V_6 -> V_8 [ V_11 ] . V_1 &&
V_2 == V_6 -> V_8 [ V_11 ] . V_2 &&
( V_10 = V_6 -> V_8 [ V_11 ] . V_12 ) != NULL ) {
if ( V_10 == V_28 )
goto V_25;
* V_18 = V_10 -> V_18 ;
return 0 ;
}
V_11 = F_7 ( V_1 ) ;
V_29:
V_23 = V_6 -> V_30 [ V_11 ] ;
if ( V_23 ) {
for ( V_10 = V_23 -> V_31 [ F_8 ( V_1 ) ] ; V_10 ; V_10 = V_10 -> V_32 )
if ( V_10 -> V_1 == V_1 )
F_14 () ;
for ( V_10 = V_23 -> V_31 [ F_9 ( V_2 ) ] ; V_10 ; V_10 = V_10 -> V_32 )
if ( V_10 -> V_2 == V_2 )
F_14 () ;
for ( V_10 = V_23 -> V_31 [ F_10 () ] ; V_10 ; V_10 = V_10 -> V_32 )
F_14 () ;
}
if ( V_11 < 256 ) {
V_11 = 256 ;
V_1 &= ~ 0xFFFF ;
goto V_29;
}
if ( ! V_24 )
F_6 ( V_6 , V_1 , V_2 , V_28 ) ;
V_25:
return - 1 ;
V_27:
if ( V_1 && ( F_15 ( V_1 ) == 0 ||
! ( F_15 ( V_1 ^ V_16 -> V_4 -> V_33 ) ) ) ) {
V_18 -> V_34 = V_1 ;
V_18 -> V_35 = 0 ;
return 0 ;
}
return - 1 ;
}
static inline T_1 F_16 ( T_1 V_1 )
{
T_1 V_11 = V_1 & 0xFF ;
if ( V_1 & 0x8000 )
V_11 += 256 ;
return V_11 ;
}
static inline T_1 F_17 ( T_1 V_1 )
{
V_1 &= 0xFFFF ;
if ( V_1 == 0xFFFF )
return 32 ;
if ( ! ( V_1 & 0x8000 ) ) {
if ( V_1 > 255 )
return 256 ;
return V_1 & 0xF ;
}
return 16 + ( V_1 & 0xF ) ;
}
static unsigned long F_18 ( struct V_15 * V_16 , T_1 V_33 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 -> V_19 ;
struct V_22 * V_23 ;
struct V_9 * V_10 ;
unsigned int V_36 , V_37 ;
if ( ! V_6 )
return 0 ;
V_36 = F_16 ( V_33 ) ;
if ( V_36 > 256 )
return 0 ;
V_37 = F_17 ( V_33 >> 16 ) ;
if ( V_37 > 32 )
return 0 ;
V_23 = V_6 -> V_30 [ V_36 ] ;
if ( V_23 ) {
for ( V_10 = V_23 -> V_31 [ V_37 ] ; V_10 ; V_10 = V_10 -> V_32 )
if ( V_10 -> V_33 == V_33 )
return ( unsigned long ) V_10 ;
}
return 0 ;
}
static void F_19 ( struct V_15 * V_16 , unsigned long V_10 )
{
}
static int F_20 ( struct V_15 * V_16 )
{
return 0 ;
}
static void
F_21 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
F_22 ( V_16 , & V_10 -> V_18 ) ;
F_23 ( V_16 , & V_10 -> V_38 ) ;
F_24 ( V_10 ) ;
}
static void F_25 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
int V_36 , V_37 ;
if ( V_6 == NULL )
return;
for ( V_36 = 0 ; V_36 <= 256 ; V_36 ++ ) {
struct V_22 * V_23 ;
V_23 = V_6 -> V_30 [ V_36 ] ;
if ( V_23 ) {
for ( V_37 = 0 ; V_37 <= 32 ; V_37 ++ ) {
struct V_9 * V_10 ;
while ( ( V_10 = V_23 -> V_31 [ V_37 ] ) != NULL ) {
V_23 -> V_31 [ V_37 ] = V_10 -> V_32 ;
F_21 ( V_16 , V_10 ) ;
}
}
F_24 ( V_23 ) ;
}
}
F_24 ( V_6 ) ;
}
static int F_26 ( struct V_15 * V_16 , unsigned long V_39 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 -> V_19 ;
struct V_9 * * V_40 , * V_10 = (struct V_9 * ) V_39 ;
unsigned int V_11 = 0 ;
struct V_22 * V_23 ;
int V_41 ;
if ( ! V_6 || ! V_10 )
return - V_42 ;
V_11 = V_10 -> V_33 ;
V_23 = V_10 -> V_43 ;
for ( V_40 = & V_23 -> V_31 [ F_17 ( V_11 >> 16 ) ] ; * V_40 ; V_40 = & ( * V_40 ) -> V_32 ) {
if ( * V_40 == V_10 ) {
F_27 ( V_16 ) ;
* V_40 = V_10 -> V_32 ;
F_28 ( V_16 ) ;
F_2 ( V_16 -> V_4 , V_6 , V_10 -> V_1 ) ;
F_21 ( V_16 , V_10 ) ;
for ( V_41 = 0 ; V_41 <= 32 ; V_41 ++ )
if ( V_23 -> V_31 [ V_41 ] )
return 0 ;
F_27 ( V_16 ) ;
V_6 -> V_30 [ F_16 ( V_11 ) ] = NULL ;
F_28 ( V_16 ) ;
F_24 ( V_23 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_29 ( struct V_15 * V_16 , unsigned long V_44 ,
struct V_9 * V_10 , T_1 V_33 , struct V_5 * V_6 ,
struct V_45 * * V_46 , struct V_45 * V_47 , int V_48 )
{
int V_49 ;
T_1 V_1 = 0 , V_50 = 0 , V_51 = 0x8000 ;
struct V_9 * V_40 ;
unsigned int V_36 ;
struct V_22 * V_23 ;
struct V_52 V_53 ;
V_49 = F_30 ( V_16 , V_46 , V_47 , & V_53 , & V_54 ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = - V_42 ;
if ( V_46 [ V_55 ] ) {
if ( V_48 && V_33 & 0x8000 )
goto V_56;
V_50 = F_31 ( V_46 [ V_55 ] ) ;
if ( V_50 > 0xFF )
goto V_56;
V_51 = V_50 ;
}
if ( V_46 [ V_57 ] ) {
if ( V_46 [ V_58 ] )
goto V_56;
V_1 = F_31 ( V_46 [ V_57 ] ) ;
if ( V_1 > 0xFF )
goto V_56;
V_51 |= V_1 << 16 ;
} else if ( V_46 [ V_58 ] ) {
V_1 = F_31 ( V_46 [ V_58 ] ) ;
if ( V_1 > 0x7FFF )
goto V_56;
V_51 |= ( V_1 | 0x8000 ) << 16 ;
} else
V_51 |= 0xFFFF << 16 ;
if ( V_33 && V_48 ) {
V_51 |= V_33 & 0x7F00 ;
if ( V_51 != V_33 )
goto V_56;
}
V_36 = F_16 ( V_51 ) ;
V_23 = V_6 -> V_30 [ V_36 ] ;
if ( ! V_23 ) {
V_49 = - V_59 ;
V_23 = F_32 ( sizeof( struct V_22 ) , V_60 ) ;
if ( V_23 == NULL )
goto V_56;
F_27 ( V_16 ) ;
V_6 -> V_30 [ V_36 ] = V_23 ;
F_28 ( V_16 ) ;
} else {
unsigned int V_37 = F_17 ( V_51 >> 16 ) ;
V_49 = - V_61 ;
for ( V_40 = V_23 -> V_31 [ V_37 ] ; V_40 ; V_40 = V_40 -> V_32 )
if ( V_40 -> V_33 == V_10 -> V_33 )
goto V_56;
}
F_27 ( V_16 ) ;
if ( V_46 [ V_55 ] )
V_10 -> V_1 = V_50 ;
if ( V_46 [ V_57 ] )
V_10 -> V_1 = V_50 | V_1 << 16 ;
else if ( V_46 [ V_58 ] )
V_10 -> V_2 = V_1 ;
V_10 -> V_33 = V_51 ;
V_10 -> V_43 = V_23 ;
F_28 ( V_16 ) ;
if ( V_46 [ V_62 ] ) {
V_10 -> V_18 . V_34 = F_31 ( V_46 [ V_62 ] ) ;
F_33 ( V_16 , & V_10 -> V_18 , V_44 ) ;
}
F_34 ( V_16 , & V_10 -> V_38 , & V_53 ) ;
return 0 ;
V_56:
F_23 ( V_16 , & V_53 ) ;
return V_49 ;
}
static int F_35 ( struct V_13 * V_63 ,
struct V_15 * V_16 , unsigned long V_44 ,
T_1 V_33 ,
struct V_45 * * V_64 ,
unsigned long * V_39 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
struct V_9 * V_10 , * V_65 , * * V_40 ;
struct V_22 * V_23 ;
struct V_45 * V_66 = V_64 [ V_67 ] ;
struct V_45 * V_46 [ V_68 + 1 ] ;
unsigned int V_11 , V_69 ;
T_1 V_70 = 0 ;
int V_49 ;
if ( V_66 == NULL )
return V_33 ? - V_42 : 0 ;
V_49 = F_36 ( V_46 , V_68 , V_66 , V_71 ) ;
if ( V_49 < 0 )
return V_49 ;
V_10 = (struct V_9 * ) * V_39 ;
if ( V_10 ) {
if ( V_10 -> V_33 != V_33 && V_33 )
return - V_42 ;
if ( V_10 -> V_43 )
V_70 = V_10 -> V_33 ;
V_49 = F_29 ( V_16 , V_44 , V_10 , V_33 , V_6 , V_46 ,
V_64 [ V_72 ] , 0 ) ;
if ( V_49 < 0 )
return V_49 ;
goto V_73;
}
V_49 = - V_59 ;
if ( V_6 == NULL ) {
V_6 = F_32 ( sizeof( struct V_5 ) , V_60 ) ;
if ( V_6 == NULL )
goto V_56;
F_27 ( V_16 ) ;
V_16 -> V_19 = V_6 ;
F_28 ( V_16 ) ;
}
V_10 = F_32 ( sizeof( struct V_9 ) , V_60 ) ;
if ( V_10 == NULL )
goto V_56;
V_49 = F_29 ( V_16 , V_44 , V_10 , V_33 , V_6 , V_46 ,
V_64 [ V_72 ] , 1 ) ;
if ( V_49 < 0 )
goto V_56;
V_73:
V_11 = F_17 ( V_10 -> V_33 >> 16 ) ;
for ( V_40 = & V_10 -> V_43 -> V_31 [ V_11 ] ; ( V_65 = * V_40 ) != NULL ; V_40 = & V_65 -> V_32 )
if ( V_10 -> V_33 < V_65 -> V_33 )
break;
V_10 -> V_32 = V_65 ;
F_27 ( V_16 ) ;
* V_40 = V_10 ;
if ( V_70 && V_10 -> V_33 != V_70 ) {
V_69 = F_16 ( V_70 ) ;
V_11 = F_17 ( V_70 >> 16 ) ;
V_23 = V_6 -> V_30 [ V_69 ] ;
if ( V_23 ) {
for ( V_40 = & V_23 -> V_31 [ V_11 ] ; * V_40 ; V_40 = & ( * V_40 ) -> V_32 ) {
if ( * V_40 == V_10 ) {
* V_40 = V_10 -> V_32 ;
break;
}
}
}
}
F_28 ( V_16 ) ;
F_2 ( V_16 -> V_4 , V_6 , V_10 -> V_1 ) ;
* V_39 = ( unsigned long ) V_10 ;
return 0 ;
V_56:
F_24 ( V_10 ) ;
return V_49 ;
}
static void F_37 ( struct V_15 * V_16 , struct V_74 * V_39 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
unsigned int V_11 , V_36 ;
if ( V_6 == NULL )
V_39 -> V_75 = 1 ;
if ( V_39 -> V_75 )
return;
for ( V_11 = 0 ; V_11 <= 256 ; V_11 ++ ) {
struct V_22 * V_23 = V_6 -> V_30 [ V_11 ] ;
if ( V_23 ) {
for ( V_36 = 0 ; V_36 <= 32 ; V_36 ++ ) {
struct V_9 * V_10 ;
for ( V_10 = V_23 -> V_31 [ V_36 ] ; V_10 ; V_10 = V_10 -> V_32 ) {
if ( V_39 -> V_76 < V_39 -> V_77 ) {
V_39 -> V_76 ++ ;
continue;
}
if ( V_39 -> V_78 ( V_16 , ( unsigned long ) V_10 , V_39 ) < 0 ) {
V_39 -> V_75 = 1 ;
return;
}
V_39 -> V_76 ++ ;
}
}
}
}
}
static int F_38 ( struct V_15 * V_16 , unsigned long V_79 ,
struct V_13 * V_14 , struct V_80 * V_81 )
{
struct V_9 * V_10 = (struct V_9 * ) V_79 ;
unsigned char * V_23 = F_39 ( V_14 ) ;
struct V_45 * V_82 ;
T_1 V_1 ;
if ( V_10 == NULL )
return V_14 -> V_83 ;
V_81 -> V_84 = V_10 -> V_33 ;
V_82 = F_40 ( V_14 , V_67 ) ;
if ( V_82 == NULL )
goto V_85;
if ( ! ( V_10 -> V_33 & 0x8000 ) ) {
V_1 = V_10 -> V_1 & 0xFF ;
if ( F_41 ( V_14 , V_55 , V_1 ) )
goto V_85;
}
if ( V_10 -> V_33 & 0x80000000 ) {
if ( ( V_10 -> V_33 >> 16 ) != 0xFFFF &&
F_41 ( V_14 , V_58 , V_10 -> V_2 ) )
goto V_85;
} else {
V_1 = V_10 -> V_1 >> 16 ;
if ( F_41 ( V_14 , V_57 , V_1 ) )
goto V_85;
}
if ( V_10 -> V_18 . V_34 &&
F_41 ( V_14 , V_62 , V_10 -> V_18 . V_34 ) )
goto V_85;
if ( F_42 ( V_14 , & V_10 -> V_38 , & V_54 ) < 0 )
goto V_85;
F_43 ( V_14 , V_82 ) ;
if ( F_44 ( V_14 , & V_10 -> V_38 , & V_54 ) < 0 )
goto V_85;
return V_14 -> V_83 ;
V_85:
F_45 ( V_14 , V_23 ) ;
return - 1 ;
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_86 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_86 ) ;
}
