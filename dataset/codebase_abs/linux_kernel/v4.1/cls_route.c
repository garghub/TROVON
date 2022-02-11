static inline int F_1 ( T_1 V_1 , int V_2 )
{
return V_1 & 0xF ;
}
static void
F_2 ( struct V_3 * V_4 )
{
F_3 ( & V_5 ) ;
memset ( V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
F_4 ( & V_5 ) ;
}
static void
F_5 ( struct V_3 * V_4 , T_1 V_1 , int V_2 ,
struct V_7 * V_8 )
{
int V_9 = F_1 ( V_1 , V_2 ) ;
F_3 ( & V_5 ) ;
V_4 -> V_6 [ V_9 ] . V_1 = V_1 ;
V_4 -> V_6 [ V_9 ] . V_2 = V_2 ;
V_4 -> V_6 [ V_9 ] . V_10 = V_8 ;
F_4 ( & V_5 ) ;
}
static inline int F_6 ( T_1 V_1 )
{
return V_1 & 0xFF ;
}
static inline int F_7 ( T_1 V_1 )
{
return ( V_1 >> 16 ) & 0xF ;
}
static inline int F_8 ( int V_2 )
{
return 16 + ( ( V_2 >> 16 ) & 0xF ) ;
}
static inline int F_9 ( void )
{
return 32 ;
}
static int F_10 ( struct V_11 * V_12 , const struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 = F_11 ( V_14 -> V_17 ) ;
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
T_1 V_1 , V_9 ;
int V_2 , V_22 = 0 ;
V_19 = F_12 ( V_12 ) ;
if ( ! V_19 )
goto V_23;
V_1 = V_19 -> V_24 ;
if ( V_4 == NULL )
goto V_25;
V_2 = F_13 ( V_12 ) ;
V_9 = F_1 ( V_1 , V_2 ) ;
F_14 ( & V_5 ) ;
if ( V_1 == V_4 -> V_6 [ V_9 ] . V_1 &&
V_2 == V_4 -> V_6 [ V_9 ] . V_2 &&
( V_8 = V_4 -> V_6 [ V_9 ] . V_10 ) != NULL ) {
if ( V_8 == V_26 ) {
F_15 ( & V_5 ) ;
goto V_23;
}
* V_16 = V_8 -> V_16 ;
F_15 ( & V_5 ) ;
return 0 ;
}
F_15 ( & V_5 ) ;
V_9 = F_6 ( V_1 ) ;
V_27:
V_21 = F_11 ( V_4 -> V_28 [ V_9 ] ) ;
if ( V_21 ) {
for ( V_8 = F_11 ( V_21 -> V_29 [ F_7 ( V_1 ) ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_30 ) )
if ( V_8 -> V_1 == V_1 )
F_16 () ;
for ( V_8 = F_11 ( V_21 -> V_29 [ F_8 ( V_2 ) ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_30 ) )
if ( V_8 -> V_2 == V_2 )
F_16 () ;
for ( V_8 = F_11 ( V_21 -> V_29 [ F_9 () ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_30 ) )
F_16 () ;
}
if ( V_9 < 256 ) {
V_9 = 256 ;
V_1 &= ~ 0xFFFF ;
goto V_27;
}
if ( ! V_22 )
F_5 ( V_4 , V_1 , V_2 , V_26 ) ;
V_23:
return - 1 ;
V_25:
if ( V_1 && ( F_17 ( V_1 ) == 0 ||
! ( F_17 ( V_1 ^ V_14 -> V_31 -> V_32 ) ) ) ) {
V_16 -> V_33 = V_1 ;
V_16 -> V_34 = 0 ;
return 0 ;
}
return - 1 ;
}
static inline T_1 F_18 ( T_1 V_1 )
{
T_1 V_9 = V_1 & 0xFF ;
if ( V_1 & 0x8000 )
V_9 += 256 ;
return V_9 ;
}
static inline T_1 F_19 ( T_1 V_1 )
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
static unsigned long F_20 ( struct V_13 * V_14 , T_1 V_32 )
{
struct V_3 * V_4 = F_21 ( V_14 -> V_17 ) ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
unsigned int V_35 , V_36 ;
if ( ! V_4 )
return 0 ;
V_35 = F_18 ( V_32 ) ;
if ( V_35 > 256 )
return 0 ;
V_36 = F_19 ( V_32 >> 16 ) ;
if ( V_36 > 32 )
return 0 ;
V_21 = F_21 ( V_4 -> V_28 [ V_35 ] ) ;
if ( V_21 ) {
for ( V_8 = F_21 ( V_21 -> V_29 [ V_36 ] ) ;
V_8 ;
V_8 = F_21 ( V_8 -> V_30 ) )
if ( V_8 -> V_32 == V_32 )
return ( unsigned long ) V_8 ;
}
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_37 ) ;
if ( V_4 == NULL )
return - V_38 ;
F_24 ( V_14 -> V_17 , V_4 ) ;
return 0 ;
}
static void
F_25 ( struct V_39 * V_4 )
{
struct V_7 * V_8 = F_26 ( V_4 , struct V_7 , V_40 ) ;
F_27 ( & V_8 -> V_41 ) ;
F_28 ( V_8 ) ;
}
static bool F_29 ( struct V_13 * V_14 , bool V_42 )
{
struct V_3 * V_4 = F_21 ( V_14 -> V_17 ) ;
int V_35 , V_36 ;
if ( V_4 == NULL )
return true ;
if ( ! V_42 ) {
for ( V_35 = 0 ; V_35 <= 256 ; V_35 ++ ) {
if ( F_30 ( V_4 -> V_28 [ V_35 ] ) )
return false ;
}
}
for ( V_35 = 0 ; V_35 <= 256 ; V_35 ++ ) {
struct V_20 * V_21 ;
V_21 = F_21 ( V_4 -> V_28 [ V_35 ] ) ;
if ( V_21 ) {
for ( V_36 = 0 ; V_36 <= 32 ; V_36 ++ ) {
struct V_7 * V_8 ;
while ( ( V_8 = F_21 ( V_21 -> V_29 [ V_36 ] ) ) != NULL ) {
struct V_7 * V_30 ;
V_30 = F_21 ( V_8 -> V_30 ) ;
F_31 ( V_21 -> V_29 [ V_36 ] , V_30 ) ;
F_32 ( V_14 , & V_8 -> V_16 ) ;
F_33 ( & V_8 -> V_40 , F_25 ) ;
}
}
F_31 ( V_4 -> V_28 [ V_35 ] , NULL ) ;
F_34 ( V_21 , V_40 ) ;
}
}
F_31 ( V_14 -> V_17 , NULL ) ;
F_34 ( V_4 , V_40 ) ;
return true ;
}
static int F_35 ( struct V_13 * V_14 , unsigned long V_43 )
{
struct V_3 * V_4 = F_21 ( V_14 -> V_17 ) ;
struct V_7 * V_8 = (struct V_7 * ) V_43 ;
struct V_7 T_2 * * V_44 ;
struct V_7 * V_45 ;
struct V_20 * V_21 ;
unsigned int V_9 = 0 ;
int V_46 ;
if ( ! V_4 || ! V_8 )
return - V_47 ;
V_9 = V_8 -> V_32 ;
V_21 = V_8 -> V_48 ;
V_44 = & V_21 -> V_29 [ F_19 ( V_9 >> 16 ) ] ;
for ( V_45 = F_21 ( * V_44 ) ; V_45 ;
V_44 = & V_45 -> V_30 , V_45 = F_21 ( * V_44 ) ) {
if ( V_45 == V_8 ) {
F_31 ( * V_44 , F_21 ( V_8 -> V_30 ) ) ;
F_2 ( V_4 ) ;
F_32 ( V_14 , & V_8 -> V_16 ) ;
F_33 ( & V_8 -> V_40 , F_25 ) ;
for ( V_46 = 0 ; V_46 <= 32 ; V_46 ++ ) {
struct V_7 * V_49 ;
V_49 = F_21 ( V_21 -> V_29 [ V_46 ] ) ;
if ( V_49 )
return 0 ;
}
F_31 ( V_4 -> V_28 [ F_18 ( V_9 ) ] , NULL ) ;
F_34 ( V_21 , V_40 ) ;
return 0 ;
}
}
return 0 ;
}
static int F_36 ( struct V_50 * V_50 , struct V_13 * V_14 ,
unsigned long V_51 , struct V_7 * V_8 ,
T_1 V_32 , struct V_3 * V_4 ,
struct V_52 * * V_53 , struct V_52 * V_54 , int V_55 ,
bool V_56 )
{
int V_57 ;
T_1 V_1 = 0 , V_58 = 0 , V_59 = 0x8000 ;
struct V_7 * V_44 ;
unsigned int V_35 ;
struct V_20 * V_21 ;
struct V_60 V_61 ;
F_37 ( & V_61 , V_62 , V_63 ) ;
V_57 = F_38 ( V_50 , V_14 , V_53 , V_54 , & V_61 , V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = - V_47 ;
if ( V_53 [ V_64 ] ) {
if ( V_55 && V_32 & 0x8000 )
goto V_65;
V_58 = F_39 ( V_53 [ V_64 ] ) ;
if ( V_58 > 0xFF )
goto V_65;
V_59 = V_58 ;
}
if ( V_53 [ V_66 ] ) {
if ( V_53 [ V_67 ] )
goto V_65;
V_1 = F_39 ( V_53 [ V_66 ] ) ;
if ( V_1 > 0xFF )
goto V_65;
V_59 |= V_1 << 16 ;
} else if ( V_53 [ V_67 ] ) {
V_1 = F_39 ( V_53 [ V_67 ] ) ;
if ( V_1 > 0x7FFF )
goto V_65;
V_59 |= ( V_1 | 0x8000 ) << 16 ;
} else
V_59 |= 0xFFFF << 16 ;
if ( V_32 && V_55 ) {
V_59 |= V_32 & 0x7F00 ;
if ( V_59 != V_32 )
goto V_65;
}
V_35 = F_18 ( V_59 ) ;
V_21 = F_21 ( V_4 -> V_28 [ V_35 ] ) ;
if ( ! V_21 ) {
V_57 = - V_38 ;
V_21 = F_23 ( sizeof( struct V_20 ) , V_37 ) ;
if ( V_21 == NULL )
goto V_65;
F_24 ( V_4 -> V_28 [ V_35 ] , V_21 ) ;
} else {
unsigned int V_36 = F_19 ( V_59 >> 16 ) ;
V_57 = - V_68 ;
for ( V_44 = F_21 ( V_21 -> V_29 [ V_36 ] ) ;
V_44 ;
V_44 = F_21 ( V_44 -> V_30 ) )
if ( V_44 -> V_32 == V_8 -> V_32 )
goto V_65;
}
if ( V_53 [ V_64 ] )
V_8 -> V_1 = V_58 ;
if ( V_53 [ V_66 ] )
V_8 -> V_1 = V_58 | V_1 << 16 ;
else if ( V_53 [ V_67 ] )
V_8 -> V_2 = V_1 ;
V_8 -> V_32 = V_59 ;
V_8 -> V_48 = V_21 ;
V_8 -> V_14 = V_14 ;
if ( V_53 [ V_69 ] ) {
V_8 -> V_16 . V_33 = F_39 ( V_53 [ V_69 ] ) ;
F_40 ( V_14 , & V_8 -> V_16 , V_51 ) ;
}
F_41 ( V_14 , & V_8 -> V_41 , & V_61 ) ;
return 0 ;
V_65:
F_27 ( & V_61 ) ;
return V_57 ;
}
static int F_42 ( struct V_50 * V_50 , struct V_11 * V_70 ,
struct V_13 * V_14 , unsigned long V_51 ,
T_1 V_32 ,
struct V_52 * * V_71 ,
unsigned long * V_43 , bool V_56 )
{
struct V_3 * V_4 = F_21 ( V_14 -> V_17 ) ;
struct V_7 T_2 * * V_44 ;
struct V_7 * V_72 , * V_73 , * V_74 , * V_8 = NULL ;
struct V_20 * V_21 ;
struct V_52 * V_75 = V_71 [ V_76 ] ;
struct V_52 * V_53 [ V_77 + 1 ] ;
unsigned int V_9 , V_78 ;
int V_57 ;
bool V_55 = true ;
if ( V_75 == NULL )
return V_32 ? - V_47 : 0 ;
V_57 = F_43 ( V_53 , V_77 , V_75 , V_79 ) ;
if ( V_57 < 0 )
return V_57 ;
V_72 = (struct V_7 * ) * V_43 ;
if ( V_72 && V_32 && V_72 -> V_32 != V_32 )
return - V_47 ;
V_57 = - V_38 ;
V_8 = F_23 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_8 )
goto V_65;
F_37 ( & V_8 -> V_41 , V_62 , V_63 ) ;
if ( V_72 ) {
V_8 -> V_1 = V_72 -> V_1 ;
V_8 -> V_2 = V_72 -> V_2 ;
V_8 -> V_16 = V_72 -> V_16 ;
V_8 -> V_32 = V_72 -> V_32 ;
V_8 -> V_14 = V_72 -> V_14 ;
V_8 -> V_48 = V_72 -> V_48 ;
V_55 = false ;
}
V_57 = F_36 ( V_50 , V_14 , V_51 , V_8 , V_32 , V_4 , V_53 ,
V_71 [ V_80 ] , V_55 , V_56 ) ;
if ( V_57 < 0 )
goto V_65;
V_9 = F_19 ( V_8 -> V_32 >> 16 ) ;
V_44 = & V_8 -> V_48 -> V_29 [ V_9 ] ;
for ( V_74 = F_21 ( * V_44 ) ;
( V_73 = F_21 ( * V_44 ) ) != NULL ;
V_44 = & V_73 -> V_30 )
if ( V_8 -> V_32 < V_73 -> V_32 )
break;
F_44 ( F_45 ( V_14 -> V_31 ) ) ;
F_24 ( V_8 -> V_30 , V_73 ) ;
F_24 ( * V_44 , V_8 ) ;
if ( V_72 && V_72 -> V_32 && V_8 -> V_32 != V_72 -> V_32 ) {
V_78 = F_18 ( V_72 -> V_32 ) ;
V_9 = F_19 ( V_72 -> V_32 >> 16 ) ;
V_21 = F_21 ( V_4 -> V_28 [ V_78 ] ) ;
if ( V_21 ) {
V_44 = & V_21 -> V_29 [ V_9 ] ;
for ( V_74 = F_21 ( * V_44 ) ; V_74 ;
V_44 = & V_74 -> V_30 , V_74 = F_21 ( * V_44 ) ) {
if ( V_74 == V_8 ) {
* V_44 = V_8 -> V_30 ;
break;
}
}
}
}
F_2 ( V_4 ) ;
* V_43 = ( unsigned long ) V_8 ;
if ( V_72 ) {
F_32 ( V_14 , & V_72 -> V_16 ) ;
F_33 ( & V_72 -> V_40 , F_25 ) ;
}
return 0 ;
V_65:
F_28 ( V_8 ) ;
return V_57 ;
}
static void F_46 ( struct V_13 * V_14 , struct V_81 * V_43 )
{
struct V_3 * V_4 = F_21 ( V_14 -> V_17 ) ;
unsigned int V_9 , V_35 ;
if ( V_4 == NULL )
V_43 -> V_82 = 1 ;
if ( V_43 -> V_82 )
return;
for ( V_9 = 0 ; V_9 <= 256 ; V_9 ++ ) {
struct V_20 * V_21 = F_21 ( V_4 -> V_28 [ V_9 ] ) ;
if ( V_21 ) {
for ( V_35 = 0 ; V_35 <= 32 ; V_35 ++ ) {
struct V_7 * V_8 ;
for ( V_8 = F_21 ( V_21 -> V_29 [ V_35 ] ) ;
V_8 ;
V_8 = F_21 ( V_8 -> V_30 ) ) {
if ( V_43 -> V_83 < V_43 -> V_84 ) {
V_43 -> V_83 ++ ;
continue;
}
if ( V_43 -> V_85 ( V_14 , ( unsigned long ) V_8 , V_43 ) < 0 ) {
V_43 -> V_82 = 1 ;
return;
}
V_43 -> V_83 ++ ;
}
}
}
}
}
static int F_47 ( struct V_50 * V_50 , struct V_13 * V_14 , unsigned long V_86 ,
struct V_11 * V_12 , struct V_87 * V_88 )
{
struct V_7 * V_8 = (struct V_7 * ) V_86 ;
struct V_52 * V_89 ;
T_1 V_1 ;
if ( V_8 == NULL )
return V_12 -> V_90 ;
V_88 -> V_91 = V_8 -> V_32 ;
V_89 = F_48 ( V_12 , V_76 ) ;
if ( V_89 == NULL )
goto V_92;
if ( ! ( V_8 -> V_32 & 0x8000 ) ) {
V_1 = V_8 -> V_1 & 0xFF ;
if ( F_49 ( V_12 , V_64 , V_1 ) )
goto V_92;
}
if ( V_8 -> V_32 & 0x80000000 ) {
if ( ( V_8 -> V_32 >> 16 ) != 0xFFFF &&
F_49 ( V_12 , V_67 , V_8 -> V_2 ) )
goto V_92;
} else {
V_1 = V_8 -> V_1 >> 16 ;
if ( F_49 ( V_12 , V_66 , V_1 ) )
goto V_92;
}
if ( V_8 -> V_16 . V_33 &&
F_49 ( V_12 , V_69 , V_8 -> V_16 . V_33 ) )
goto V_92;
if ( F_50 ( V_12 , & V_8 -> V_41 ) < 0 )
goto V_92;
F_51 ( V_12 , V_89 ) ;
if ( F_52 ( V_12 , & V_8 -> V_41 ) < 0 )
goto V_92;
return V_12 -> V_90 ;
V_92:
F_53 ( V_12 , V_89 ) ;
return - 1 ;
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_93 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_93 ) ;
}
