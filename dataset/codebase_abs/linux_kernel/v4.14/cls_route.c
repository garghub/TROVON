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
V_2 = F_13 ( V_12 ) ;
V_9 = F_1 ( V_1 , V_2 ) ;
F_14 ( & V_5 ) ;
if ( V_1 == V_4 -> V_6 [ V_9 ] . V_1 &&
V_2 == V_4 -> V_6 [ V_9 ] . V_2 &&
( V_8 = V_4 -> V_6 [ V_9 ] . V_10 ) != NULL ) {
if ( V_8 == V_25 ) {
F_15 ( & V_5 ) ;
goto V_23;
}
* V_16 = V_8 -> V_16 ;
F_15 ( & V_5 ) ;
return 0 ;
}
F_15 ( & V_5 ) ;
V_9 = F_6 ( V_1 ) ;
V_26:
V_21 = F_11 ( V_4 -> V_27 [ V_9 ] ) ;
if ( V_21 ) {
for ( V_8 = F_11 ( V_21 -> V_28 [ F_7 ( V_1 ) ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_29 ) )
if ( V_8 -> V_1 == V_1 )
F_16 () ;
for ( V_8 = F_11 ( V_21 -> V_28 [ F_8 ( V_2 ) ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_29 ) )
if ( V_8 -> V_2 == V_2 )
F_16 () ;
for ( V_8 = F_11 ( V_21 -> V_28 [ F_9 () ] ) ;
V_8 ;
V_8 = F_11 ( V_8 -> V_29 ) )
F_16 () ;
}
if ( V_9 < 256 ) {
V_9 = 256 ;
V_1 &= ~ 0xFFFF ;
goto V_26;
}
if ( ! V_22 )
F_5 ( V_4 , V_1 , V_2 , V_25 ) ;
V_23:
return - 1 ;
}
static inline T_1 F_17 ( T_1 V_1 )
{
T_1 V_9 = V_1 & 0xFF ;
if ( V_1 & 0x8000 )
V_9 += 256 ;
return V_9 ;
}
static inline T_1 F_18 ( T_1 V_1 )
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
static void * F_19 ( struct V_13 * V_14 , T_1 V_30 )
{
struct V_3 * V_4 = F_20 ( V_14 -> V_17 ) ;
struct V_20 * V_21 ;
struct V_7 * V_8 ;
unsigned int V_31 , V_32 ;
V_31 = F_17 ( V_30 ) ;
if ( V_31 > 256 )
return NULL ;
V_32 = F_18 ( V_30 >> 16 ) ;
if ( V_32 > 32 )
return NULL ;
V_21 = F_20 ( V_4 -> V_27 [ V_31 ] ) ;
if ( V_21 ) {
for ( V_8 = F_20 ( V_21 -> V_28 [ V_32 ] ) ;
V_8 ;
V_8 = F_20 ( V_8 -> V_29 ) )
if ( V_8 -> V_30 == V_30 )
return V_8 ;
}
return NULL ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
V_4 = F_22 ( sizeof( struct V_3 ) , V_33 ) ;
if ( V_4 == NULL )
return - V_34 ;
F_23 ( V_14 -> V_17 , V_4 ) ;
return 0 ;
}
static void F_24 ( struct V_7 * V_8 )
{
F_25 ( & V_8 -> V_35 ) ;
F_26 ( & V_8 -> V_35 ) ;
F_27 ( V_8 ) ;
}
static void F_28 ( struct V_36 * V_37 )
{
struct V_7 * V_8 = F_29 ( V_37 , struct V_7 , V_37 ) ;
F_30 () ;
F_24 ( V_8 ) ;
F_31 () ;
}
static void F_32 ( struct V_38 * V_4 )
{
struct V_7 * V_8 = F_29 ( V_4 , struct V_7 , V_39 ) ;
F_33 ( & V_8 -> V_37 , F_28 ) ;
F_34 ( & V_8 -> V_37 ) ;
}
static void F_35 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_20 ( V_14 -> V_17 ) ;
int V_31 , V_32 ;
if ( V_4 == NULL )
return;
for ( V_31 = 0 ; V_31 <= 256 ; V_31 ++ ) {
struct V_20 * V_21 ;
V_21 = F_20 ( V_4 -> V_27 [ V_31 ] ) ;
if ( V_21 ) {
for ( V_32 = 0 ; V_32 <= 32 ; V_32 ++ ) {
struct V_7 * V_8 ;
while ( ( V_8 = F_20 ( V_21 -> V_28 [ V_32 ] ) ) != NULL ) {
struct V_7 * V_29 ;
V_29 = F_20 ( V_8 -> V_29 ) ;
F_36 ( V_21 -> V_28 [ V_32 ] , V_29 ) ;
F_37 ( V_14 , & V_8 -> V_16 ) ;
if ( F_38 ( & V_8 -> V_35 ) )
F_39 ( & V_8 -> V_39 , F_32 ) ;
else
F_24 ( V_8 ) ;
}
}
F_36 ( V_4 -> V_27 [ V_31 ] , NULL ) ;
F_40 ( V_21 , V_39 ) ;
}
}
F_40 ( V_4 , V_39 ) ;
}
static int F_41 ( struct V_13 * V_14 , void * V_40 , bool * V_41 )
{
struct V_3 * V_4 = F_20 ( V_14 -> V_17 ) ;
struct V_7 * V_8 = V_40 ;
struct V_7 T_2 * * V_42 ;
struct V_7 * V_43 ;
struct V_20 * V_21 ;
unsigned int V_9 = 0 ;
int V_44 , V_31 ;
if ( ! V_4 || ! V_8 )
return - V_45 ;
V_9 = V_8 -> V_30 ;
V_21 = V_8 -> V_46 ;
V_42 = & V_21 -> V_28 [ F_18 ( V_9 >> 16 ) ] ;
for ( V_43 = F_20 ( * V_42 ) ; V_43 ;
V_42 = & V_43 -> V_29 , V_43 = F_20 ( * V_42 ) ) {
if ( V_43 == V_8 ) {
F_36 ( * V_42 , F_20 ( V_8 -> V_29 ) ) ;
F_2 ( V_4 ) ;
F_37 ( V_14 , & V_8 -> V_16 ) ;
F_38 ( & V_8 -> V_35 ) ;
F_39 ( & V_8 -> V_39 , F_32 ) ;
for ( V_44 = 0 ; V_44 <= 32 ; V_44 ++ ) {
struct V_7 * V_47 ;
V_47 = F_20 ( V_21 -> V_28 [ V_44 ] ) ;
if ( V_47 )
goto V_48;
}
F_36 ( V_4 -> V_27 [ F_17 ( V_9 ) ] , NULL ) ;
F_40 ( V_21 , V_39 ) ;
break;
}
}
V_48:
* V_41 = true ;
for ( V_31 = 0 ; V_31 <= 256 ; V_31 ++ ) {
if ( F_42 ( V_4 -> V_27 [ V_31 ] ) ) {
* V_41 = false ;
break;
}
}
return 0 ;
}
static int F_43 ( struct V_49 * V_49 , struct V_13 * V_14 ,
unsigned long V_50 , struct V_7 * V_8 ,
T_1 V_30 , struct V_3 * V_4 ,
struct V_51 * * V_52 , struct V_51 * V_53 , int V_54 ,
bool V_55 )
{
T_1 V_1 = 0 , V_56 = 0 , V_57 = 0x8000 ;
struct V_7 * V_42 ;
unsigned int V_31 ;
struct V_20 * V_21 ;
int V_58 ;
V_58 = F_44 ( V_49 , V_14 , V_52 , V_53 , & V_8 -> V_35 , V_55 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_52 [ V_59 ] ) {
if ( V_54 && V_30 & 0x8000 )
return - V_45 ;
V_56 = F_45 ( V_52 [ V_59 ] ) ;
if ( V_56 > 0xFF )
return - V_45 ;
V_57 = V_56 ;
}
if ( V_52 [ V_60 ] ) {
if ( V_52 [ V_61 ] )
return - V_45 ;
V_1 = F_45 ( V_52 [ V_60 ] ) ;
if ( V_1 > 0xFF )
return - V_45 ;
V_57 |= V_1 << 16 ;
} else if ( V_52 [ V_61 ] ) {
V_1 = F_45 ( V_52 [ V_61 ] ) ;
if ( V_1 > 0x7FFF )
return - V_45 ;
V_57 |= ( V_1 | 0x8000 ) << 16 ;
} else
V_57 |= 0xFFFF << 16 ;
if ( V_30 && V_54 ) {
V_57 |= V_30 & 0x7F00 ;
if ( V_57 != V_30 )
return - V_45 ;
}
V_31 = F_17 ( V_57 ) ;
V_21 = F_20 ( V_4 -> V_27 [ V_31 ] ) ;
if ( ! V_21 ) {
V_21 = F_22 ( sizeof( struct V_20 ) , V_33 ) ;
if ( V_21 == NULL )
return - V_34 ;
F_23 ( V_4 -> V_27 [ V_31 ] , V_21 ) ;
} else {
unsigned int V_32 = F_18 ( V_57 >> 16 ) ;
for ( V_42 = F_20 ( V_21 -> V_28 [ V_32 ] ) ;
V_42 ;
V_42 = F_20 ( V_42 -> V_29 ) )
if ( V_42 -> V_30 == V_8 -> V_30 )
return - V_62 ;
}
if ( V_52 [ V_59 ] )
V_8 -> V_1 = V_56 ;
if ( V_52 [ V_60 ] )
V_8 -> V_1 = V_56 | V_1 << 16 ;
else if ( V_52 [ V_61 ] )
V_8 -> V_2 = V_1 ;
V_8 -> V_30 = V_57 ;
V_8 -> V_46 = V_21 ;
V_8 -> V_14 = V_14 ;
if ( V_52 [ V_63 ] ) {
V_8 -> V_16 . V_64 = F_45 ( V_52 [ V_63 ] ) ;
F_46 ( V_14 , & V_8 -> V_16 , V_50 ) ;
}
return 0 ;
}
static int F_47 ( struct V_49 * V_49 , struct V_11 * V_65 ,
struct V_13 * V_14 , unsigned long V_50 , T_1 V_30 ,
struct V_51 * * V_66 , void * * V_40 , bool V_55 )
{
struct V_3 * V_4 = F_20 ( V_14 -> V_17 ) ;
struct V_7 T_2 * * V_42 ;
struct V_7 * V_67 , * V_68 , * V_69 , * V_8 = NULL ;
struct V_20 * V_21 ;
struct V_51 * V_70 = V_66 [ V_71 ] ;
struct V_51 * V_52 [ V_72 + 1 ] ;
unsigned int V_9 , V_73 ;
int V_58 ;
bool V_54 = true ;
if ( V_70 == NULL )
return V_30 ? - V_45 : 0 ;
V_58 = F_48 ( V_52 , V_72 , V_70 , V_74 , NULL ) ;
if ( V_58 < 0 )
return V_58 ;
V_67 = * V_40 ;
if ( V_67 && V_30 && V_67 -> V_30 != V_30 )
return - V_45 ;
V_58 = - V_34 ;
V_8 = F_22 ( sizeof( struct V_7 ) , V_33 ) ;
if ( ! V_8 )
goto V_75;
V_58 = F_49 ( & V_8 -> V_35 , V_76 , V_77 ) ;
if ( V_58 < 0 )
goto V_75;
if ( V_67 ) {
V_8 -> V_1 = V_67 -> V_1 ;
V_8 -> V_2 = V_67 -> V_2 ;
V_8 -> V_16 = V_67 -> V_16 ;
V_8 -> V_30 = V_67 -> V_30 ;
V_8 -> V_14 = V_67 -> V_14 ;
V_8 -> V_46 = V_67 -> V_46 ;
V_54 = false ;
}
V_58 = F_43 ( V_49 , V_14 , V_50 , V_8 , V_30 , V_4 , V_52 ,
V_66 [ V_78 ] , V_54 , V_55 ) ;
if ( V_58 < 0 )
goto V_75;
V_9 = F_18 ( V_8 -> V_30 >> 16 ) ;
V_42 = & V_8 -> V_46 -> V_28 [ V_9 ] ;
for ( V_69 = F_20 ( * V_42 ) ;
( V_68 = F_20 ( * V_42 ) ) != NULL ;
V_42 = & V_68 -> V_29 )
if ( V_8 -> V_30 < V_68 -> V_30 )
break;
F_50 ( F_51 ( V_14 -> V_79 ) ) ;
F_23 ( V_8 -> V_29 , V_68 ) ;
F_23 ( * V_42 , V_8 ) ;
if ( V_67 && V_67 -> V_30 && V_8 -> V_30 != V_67 -> V_30 ) {
V_73 = F_17 ( V_67 -> V_30 ) ;
V_9 = F_18 ( V_67 -> V_30 >> 16 ) ;
V_21 = F_20 ( V_4 -> V_27 [ V_73 ] ) ;
if ( V_21 ) {
V_42 = & V_21 -> V_28 [ V_9 ] ;
for ( V_69 = F_20 ( * V_42 ) ; V_69 ;
V_42 = & V_69 -> V_29 , V_69 = F_20 ( * V_42 ) ) {
if ( V_69 == V_8 ) {
* V_42 = V_8 -> V_29 ;
break;
}
}
}
}
F_2 ( V_4 ) ;
* V_40 = V_8 ;
if ( V_67 ) {
F_37 ( V_14 , & V_67 -> V_16 ) ;
F_38 ( & V_67 -> V_35 ) ;
F_39 ( & V_67 -> V_39 , F_32 ) ;
}
return 0 ;
V_75:
if ( V_8 )
F_25 ( & V_8 -> V_35 ) ;
F_27 ( V_8 ) ;
return V_58 ;
}
static void F_52 ( struct V_13 * V_14 , struct V_80 * V_40 )
{
struct V_3 * V_4 = F_20 ( V_14 -> V_17 ) ;
unsigned int V_9 , V_31 ;
if ( V_4 == NULL )
V_40 -> V_81 = 1 ;
if ( V_40 -> V_81 )
return;
for ( V_9 = 0 ; V_9 <= 256 ; V_9 ++ ) {
struct V_20 * V_21 = F_20 ( V_4 -> V_27 [ V_9 ] ) ;
if ( V_21 ) {
for ( V_31 = 0 ; V_31 <= 32 ; V_31 ++ ) {
struct V_7 * V_8 ;
for ( V_8 = F_20 ( V_21 -> V_28 [ V_31 ] ) ;
V_8 ;
V_8 = F_20 ( V_8 -> V_29 ) ) {
if ( V_40 -> V_82 < V_40 -> V_83 ) {
V_40 -> V_82 ++ ;
continue;
}
if ( V_40 -> V_84 ( V_14 , V_8 , V_40 ) < 0 ) {
V_40 -> V_81 = 1 ;
return;
}
V_40 -> V_82 ++ ;
}
}
}
}
}
static int F_53 ( struct V_49 * V_49 , struct V_13 * V_14 , void * V_85 ,
struct V_11 * V_12 , struct V_86 * V_87 )
{
struct V_7 * V_8 = V_85 ;
struct V_51 * V_88 ;
T_1 V_1 ;
if ( V_8 == NULL )
return V_12 -> V_89 ;
V_87 -> V_90 = V_8 -> V_30 ;
V_88 = F_54 ( V_12 , V_71 ) ;
if ( V_88 == NULL )
goto V_91;
if ( ! ( V_8 -> V_30 & 0x8000 ) ) {
V_1 = V_8 -> V_1 & 0xFF ;
if ( F_55 ( V_12 , V_59 , V_1 ) )
goto V_91;
}
if ( V_8 -> V_30 & 0x80000000 ) {
if ( ( V_8 -> V_30 >> 16 ) != 0xFFFF &&
F_55 ( V_12 , V_61 , V_8 -> V_2 ) )
goto V_91;
} else {
V_1 = V_8 -> V_1 >> 16 ;
if ( F_55 ( V_12 , V_60 , V_1 ) )
goto V_91;
}
if ( V_8 -> V_16 . V_64 &&
F_55 ( V_12 , V_63 , V_8 -> V_16 . V_64 ) )
goto V_91;
if ( F_56 ( V_12 , & V_8 -> V_35 ) < 0 )
goto V_91;
F_57 ( V_12 , V_88 ) ;
if ( F_58 ( V_12 , & V_8 -> V_35 ) < 0 )
goto V_91;
return V_12 -> V_89 ;
V_91:
F_59 ( V_12 , V_88 ) ;
return - 1 ;
}
static void F_60 ( void * V_85 , T_1 V_64 , unsigned long V_92 )
{
struct V_7 * V_8 = V_85 ;
if ( V_8 && V_8 -> V_16 . V_64 == V_64 )
V_8 -> V_16 . V_93 = V_92 ;
}
static int T_3 F_61 ( void )
{
return F_62 ( & V_94 ) ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_94 ) ;
}
