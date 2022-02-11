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
static int F_11 ( struct V_13 * V_14 , struct V_15 * V_16 ,
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
V_2 = ( (struct V_28 * ) V_21 ) -> V_29 ;
V_11 = F_1 ( V_1 , V_2 ) ;
if ( V_1 == V_6 -> V_8 [ V_11 ] . V_1 &&
V_2 == V_6 -> V_8 [ V_11 ] . V_2 &&
( V_10 = V_6 -> V_8 [ V_11 ] . V_12 ) != NULL ) {
if ( V_10 == V_30 )
goto V_25;
* V_18 = V_10 -> V_18 ;
return 0 ;
}
V_11 = F_7 ( V_1 ) ;
V_31:
V_23 = V_6 -> V_32 [ V_11 ] ;
if ( V_23 ) {
for ( V_10 = V_23 -> V_33 [ F_8 ( V_1 ) ] ; V_10 ; V_10 = V_10 -> V_34 )
if ( V_10 -> V_1 == V_1 )
F_13 () ;
for ( V_10 = V_23 -> V_33 [ F_9 ( V_2 ) ] ; V_10 ; V_10 = V_10 -> V_34 )
if ( V_10 -> V_2 == V_2 )
F_13 () ;
for ( V_10 = V_23 -> V_33 [ F_10 () ] ; V_10 ; V_10 = V_10 -> V_34 )
F_13 () ;
}
if ( V_11 < 256 ) {
V_11 = 256 ;
V_1 &= ~ 0xFFFF ;
goto V_31;
}
if ( ! V_24 )
F_6 ( V_6 , V_1 , V_2 , V_30 ) ;
V_25:
return - 1 ;
V_27:
if ( V_1 && ( F_14 ( V_1 ) == 0 ||
! ( F_14 ( V_1 ^ V_16 -> V_4 -> V_35 ) ) ) ) {
V_18 -> V_36 = V_1 ;
V_18 -> V_37 = 0 ;
return 0 ;
}
return - 1 ;
}
static inline T_1 F_15 ( T_1 V_1 )
{
T_1 V_11 = V_1 & 0xFF ;
if ( V_1 & 0x8000 )
V_11 += 256 ;
return V_11 ;
}
static inline T_1 F_16 ( T_1 V_1 )
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
static unsigned long F_17 ( struct V_15 * V_16 , T_1 V_35 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 -> V_19 ;
struct V_22 * V_23 ;
struct V_9 * V_10 ;
unsigned int V_38 , V_39 ;
if ( ! V_6 )
return 0 ;
V_38 = F_15 ( V_35 ) ;
if ( V_38 > 256 )
return 0 ;
V_39 = F_16 ( V_35 >> 16 ) ;
if ( V_39 > 32 )
return 0 ;
V_23 = V_6 -> V_32 [ V_38 ] ;
if ( V_23 ) {
for ( V_10 = V_23 -> V_33 [ V_39 ] ; V_10 ; V_10 = V_10 -> V_34 )
if ( V_10 -> V_35 == V_35 )
return ( unsigned long ) V_10 ;
}
return 0 ;
}
static void F_18 ( struct V_15 * V_16 , unsigned long V_10 )
{
}
static int F_19 ( struct V_15 * V_16 )
{
return 0 ;
}
static void
F_20 ( struct V_15 * V_16 , struct V_9 * V_10 )
{
F_21 ( V_16 , & V_10 -> V_18 ) ;
F_22 ( V_16 , & V_10 -> V_40 ) ;
F_23 ( V_10 ) ;
}
static void F_24 ( struct V_15 * V_16 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
int V_38 , V_39 ;
if ( V_6 == NULL )
return;
for ( V_38 = 0 ; V_38 <= 256 ; V_38 ++ ) {
struct V_22 * V_23 ;
V_23 = V_6 -> V_32 [ V_38 ] ;
if ( V_23 ) {
for ( V_39 = 0 ; V_39 <= 32 ; V_39 ++ ) {
struct V_9 * V_10 ;
while ( ( V_10 = V_23 -> V_33 [ V_39 ] ) != NULL ) {
V_23 -> V_33 [ V_39 ] = V_10 -> V_34 ;
F_20 ( V_16 , V_10 ) ;
}
}
F_23 ( V_23 ) ;
}
}
F_23 ( V_6 ) ;
}
static int F_25 ( struct V_15 * V_16 , unsigned long V_41 )
{
struct V_5 * V_6 = (struct V_5 * ) V_16 -> V_19 ;
struct V_9 * * V_42 , * V_10 = (struct V_9 * ) V_41 ;
unsigned int V_11 = 0 ;
struct V_22 * V_23 ;
int V_43 ;
if ( ! V_6 || ! V_10 )
return - V_44 ;
V_11 = V_10 -> V_35 ;
V_23 = V_10 -> V_45 ;
for ( V_42 = & V_23 -> V_33 [ F_16 ( V_11 >> 16 ) ] ; * V_42 ; V_42 = & ( * V_42 ) -> V_34 ) {
if ( * V_42 == V_10 ) {
F_26 ( V_16 ) ;
* V_42 = V_10 -> V_34 ;
F_27 ( V_16 ) ;
F_2 ( V_16 -> V_4 , V_6 , V_10 -> V_1 ) ;
F_20 ( V_16 , V_10 ) ;
for ( V_43 = 0 ; V_43 <= 32 ; V_43 ++ )
if ( V_23 -> V_33 [ V_43 ] )
return 0 ;
F_26 ( V_16 ) ;
V_6 -> V_32 [ F_15 ( V_11 ) ] = NULL ;
F_27 ( V_16 ) ;
F_23 ( V_23 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_28 ( struct V_15 * V_16 , unsigned long V_46 ,
struct V_9 * V_10 , T_1 V_35 , struct V_5 * V_6 ,
struct V_47 * * V_48 , struct V_47 * V_49 , int V_50 )
{
int V_51 ;
T_1 V_1 = 0 , V_52 = 0 , V_53 = 0x8000 ;
struct V_9 * V_42 ;
unsigned int V_38 ;
struct V_22 * V_23 ;
struct V_54 V_55 ;
V_51 = F_29 ( V_16 , V_48 , V_49 , & V_55 , & V_56 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 = - V_44 ;
if ( V_48 [ V_57 ] ) {
if ( V_50 && V_35 & 0x8000 )
goto V_58;
V_52 = F_30 ( V_48 [ V_57 ] ) ;
if ( V_52 > 0xFF )
goto V_58;
V_53 = V_52 ;
}
if ( V_48 [ V_59 ] ) {
if ( V_48 [ V_60 ] )
goto V_58;
V_1 = F_30 ( V_48 [ V_59 ] ) ;
if ( V_1 > 0xFF )
goto V_58;
V_53 |= V_1 << 16 ;
} else if ( V_48 [ V_60 ] ) {
V_1 = F_30 ( V_48 [ V_60 ] ) ;
if ( V_1 > 0x7FFF )
goto V_58;
V_53 |= ( V_1 | 0x8000 ) << 16 ;
} else
V_53 |= 0xFFFF << 16 ;
if ( V_35 && V_50 ) {
V_53 |= V_35 & 0x7F00 ;
if ( V_53 != V_35 )
goto V_58;
}
V_38 = F_15 ( V_53 ) ;
V_23 = V_6 -> V_32 [ V_38 ] ;
if ( ! V_23 ) {
V_51 = - V_61 ;
V_23 = F_31 ( sizeof( struct V_22 ) , V_62 ) ;
if ( V_23 == NULL )
goto V_58;
F_26 ( V_16 ) ;
V_6 -> V_32 [ V_38 ] = V_23 ;
F_27 ( V_16 ) ;
} else {
unsigned int V_39 = F_16 ( V_53 >> 16 ) ;
V_51 = - V_63 ;
for ( V_42 = V_23 -> V_33 [ V_39 ] ; V_42 ; V_42 = V_42 -> V_34 )
if ( V_42 -> V_35 == V_10 -> V_35 )
goto V_58;
}
F_26 ( V_16 ) ;
if ( V_48 [ V_57 ] )
V_10 -> V_1 = V_52 ;
if ( V_48 [ V_59 ] )
V_10 -> V_1 = V_52 | V_1 << 16 ;
else if ( V_48 [ V_60 ] )
V_10 -> V_2 = V_1 ;
V_10 -> V_35 = V_53 ;
V_10 -> V_45 = V_23 ;
F_27 ( V_16 ) ;
if ( V_48 [ V_64 ] ) {
V_10 -> V_18 . V_36 = F_30 ( V_48 [ V_64 ] ) ;
F_32 ( V_16 , & V_10 -> V_18 , V_46 ) ;
}
F_33 ( V_16 , & V_10 -> V_40 , & V_55 ) ;
return 0 ;
V_58:
F_22 ( V_16 , & V_55 ) ;
return V_51 ;
}
static int F_34 ( struct V_15 * V_16 , unsigned long V_46 ,
T_1 V_35 ,
struct V_47 * * V_65 ,
unsigned long * V_41 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
struct V_9 * V_10 , * V_66 , * * V_42 ;
struct V_22 * V_23 ;
struct V_47 * V_67 = V_65 [ V_68 ] ;
struct V_47 * V_48 [ V_69 + 1 ] ;
unsigned int V_11 , V_70 ;
T_1 V_71 = 0 ;
int V_51 ;
if ( V_67 == NULL )
return V_35 ? - V_44 : 0 ;
V_51 = F_35 ( V_48 , V_69 , V_67 , V_72 ) ;
if ( V_51 < 0 )
return V_51 ;
V_10 = (struct V_9 * ) * V_41 ;
if ( V_10 ) {
if ( V_10 -> V_35 != V_35 && V_35 )
return - V_44 ;
if ( V_10 -> V_45 )
V_71 = V_10 -> V_35 ;
V_51 = F_28 ( V_16 , V_46 , V_10 , V_35 , V_6 , V_48 ,
V_65 [ V_73 ] , 0 ) ;
if ( V_51 < 0 )
return V_51 ;
goto V_74;
}
V_51 = - V_61 ;
if ( V_6 == NULL ) {
V_6 = F_31 ( sizeof( struct V_5 ) , V_62 ) ;
if ( V_6 == NULL )
goto V_58;
F_26 ( V_16 ) ;
V_16 -> V_19 = V_6 ;
F_27 ( V_16 ) ;
}
V_10 = F_31 ( sizeof( struct V_9 ) , V_62 ) ;
if ( V_10 == NULL )
goto V_58;
V_51 = F_28 ( V_16 , V_46 , V_10 , V_35 , V_6 , V_48 ,
V_65 [ V_73 ] , 1 ) ;
if ( V_51 < 0 )
goto V_58;
V_74:
V_11 = F_16 ( V_10 -> V_35 >> 16 ) ;
for ( V_42 = & V_10 -> V_45 -> V_33 [ V_11 ] ; ( V_66 = * V_42 ) != NULL ; V_42 = & V_66 -> V_34 )
if ( V_10 -> V_35 < V_66 -> V_35 )
break;
V_10 -> V_34 = V_66 ;
F_26 ( V_16 ) ;
* V_42 = V_10 ;
if ( V_71 && V_10 -> V_35 != V_71 ) {
V_70 = F_15 ( V_71 ) ;
V_11 = F_16 ( V_71 >> 16 ) ;
V_23 = V_6 -> V_32 [ V_70 ] ;
if ( V_23 ) {
for ( V_42 = & V_23 -> V_33 [ V_11 ] ; * V_42 ; V_42 = & ( * V_42 ) -> V_34 ) {
if ( * V_42 == V_10 ) {
* V_42 = V_10 -> V_34 ;
break;
}
}
}
}
F_27 ( V_16 ) ;
F_2 ( V_16 -> V_4 , V_6 , V_10 -> V_1 ) ;
* V_41 = ( unsigned long ) V_10 ;
return 0 ;
V_58:
F_23 ( V_10 ) ;
return V_51 ;
}
static void F_36 ( struct V_15 * V_16 , struct V_75 * V_41 )
{
struct V_5 * V_6 = V_16 -> V_19 ;
unsigned int V_11 , V_38 ;
if ( V_6 == NULL )
V_41 -> V_76 = 1 ;
if ( V_41 -> V_76 )
return;
for ( V_11 = 0 ; V_11 <= 256 ; V_11 ++ ) {
struct V_22 * V_23 = V_6 -> V_32 [ V_11 ] ;
if ( V_23 ) {
for ( V_38 = 0 ; V_38 <= 32 ; V_38 ++ ) {
struct V_9 * V_10 ;
for ( V_10 = V_23 -> V_33 [ V_38 ] ; V_10 ; V_10 = V_10 -> V_34 ) {
if ( V_41 -> V_77 < V_41 -> V_78 ) {
V_41 -> V_77 ++ ;
continue;
}
if ( V_41 -> V_79 ( V_16 , ( unsigned long ) V_10 , V_41 ) < 0 ) {
V_41 -> V_76 = 1 ;
return;
}
V_41 -> V_77 ++ ;
}
}
}
}
}
static int F_37 ( struct V_15 * V_16 , unsigned long V_80 ,
struct V_13 * V_14 , struct V_81 * V_82 )
{
struct V_9 * V_10 = (struct V_9 * ) V_80 ;
unsigned char * V_23 = F_38 ( V_14 ) ;
struct V_47 * V_83 ;
T_1 V_1 ;
if ( V_10 == NULL )
return V_14 -> V_84 ;
V_82 -> V_85 = V_10 -> V_35 ;
V_83 = F_39 ( V_14 , V_68 ) ;
if ( V_83 == NULL )
goto V_86;
if ( ! ( V_10 -> V_35 & 0x8000 ) ) {
V_1 = V_10 -> V_1 & 0xFF ;
F_40 ( V_14 , V_57 , V_1 ) ;
}
if ( V_10 -> V_35 & 0x80000000 ) {
if ( ( V_10 -> V_35 >> 16 ) != 0xFFFF )
F_40 ( V_14 , V_60 , V_10 -> V_2 ) ;
} else {
V_1 = V_10 -> V_1 >> 16 ;
F_40 ( V_14 , V_59 , V_1 ) ;
}
if ( V_10 -> V_18 . V_36 )
F_40 ( V_14 , V_64 , V_10 -> V_18 . V_36 ) ;
if ( F_41 ( V_14 , & V_10 -> V_40 , & V_56 ) < 0 )
goto V_86;
F_42 ( V_14 , V_83 ) ;
if ( F_43 ( V_14 , & V_10 -> V_40 , & V_56 ) < 0 )
goto V_86;
return V_14 -> V_84 ;
V_86:
F_44 ( V_14 , V_23 ) ;
return - 1 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_87 ) ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_87 ) ;
}
