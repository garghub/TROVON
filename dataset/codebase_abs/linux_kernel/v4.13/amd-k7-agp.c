static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = ( unsigned long * ) F_2 ( V_5 ) ;
if ( V_2 -> V_4 == NULL )
return - V_6 ;
F_3 ( ( unsigned long ) V_2 -> V_4 , 1 ) ;
V_2 -> V_7 = V_2 -> V_4 ;
for ( V_3 = 0 ; V_3 < V_8 / sizeof( unsigned long ) ; V_3 ++ ) {
F_4 ( V_9 -> V_10 , V_2 -> V_7 + V_3 ) ;
F_5 ( V_2 -> V_7 + V_3 ) ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( ( unsigned long ) V_2 -> V_4 , 1 ) ;
F_8 ( ( unsigned long ) V_2 -> V_4 ) ;
}
static void F_9 ( void )
{
int V_3 ;
struct V_1 * * V_11 ;
struct V_1 * V_12 ;
V_11 = V_13 . V_14 ;
for ( V_3 = 0 ; V_3 < V_13 . V_15 ; V_3 ++ ) {
V_12 = V_11 [ V_3 ] ;
if ( V_12 != NULL ) {
if ( V_12 -> V_4 != NULL )
F_6 ( V_12 ) ;
F_10 ( V_12 ) ;
}
}
F_10 ( V_11 ) ;
V_13 . V_14 = NULL ;
}
static int F_11 ( int V_16 )
{
struct V_1 * * V_11 ;
struct V_1 * V_12 ;
int V_17 = 0 ;
int V_3 ;
V_11 = F_12 ( ( V_16 + 1 ) * sizeof( struct V_1 * ) , V_5 ) ;
if ( V_11 == NULL )
return - V_6 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_12 = F_12 ( sizeof( struct V_1 ) , V_5 ) ;
V_11 [ V_3 ] = V_12 ;
if ( V_12 == NULL ) {
V_17 = - V_6 ;
break;
}
V_17 = F_1 ( V_12 ) ;
if ( V_17 != 0 )
break;
}
V_13 . V_15 = V_3 ;
V_13 . V_14 = V_11 ;
if ( V_17 != 0 )
F_9 () ;
return V_17 ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 V_22 ;
unsigned long T_1 * V_23 ;
unsigned long V_24 ;
int V_17 ;
int V_3 ;
V_21 = F_14 ( V_9 -> V_25 ) ;
V_17 = F_1 ( & V_22 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_11 ( V_21 -> V_26 / 1024 ) ;
if ( V_17 != 0 ) {
F_6 ( & V_22 ) ;
return V_17 ;
}
V_9 -> V_27 = ( V_28 * ) V_22 . V_4 ;
V_9 -> V_29 = ( V_28 T_1 * ) V_22 . V_7 ;
V_9 -> V_30 = F_15 ( V_22 . V_4 ) ;
V_24 = F_16 ( V_9 -> V_31 , V_32 ) ;
V_9 -> V_33 = V_24 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_26 / 1024 ; V_3 ++ , V_24 += 0x00400000 ) {
F_4 ( F_15 ( V_13 . V_14 [ V_3 ] -> V_4 ) | 1 ,
V_22 . V_7 + F_17 ( V_24 ) ) ;
F_5 ( V_22 . V_7 + F_17 ( V_24 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_21 -> V_26 ; V_3 ++ ) {
V_24 = ( V_3 * V_8 ) + V_9 -> V_33 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( V_9 -> V_10 , V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_1 V_22 ;
V_22 . V_4 = ( unsigned long * ) V_9 -> V_27 ;
V_22 . V_7 = ( unsigned long T_1 * ) V_9 -> V_29 ;
F_9 () ;
F_6 ( & V_22 ) ;
return 0 ;
}
static int F_21 ( void )
{
int V_3 ;
V_28 V_34 ;
struct V_20 * V_35 ;
F_22 ( V_9 -> V_31 , V_36 , & V_34 ) ;
V_34 = ( V_34 & 0x0000000e ) ;
V_35 = F_14 ( V_9 -> V_37 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_37 -> V_39 ; V_3 ++ ) {
if ( V_34 == V_35 [ V_3 ] . V_40 ) {
V_9 -> V_41 =
V_9 -> V_25 = ( void * ) ( V_35 + V_3 ) ;
V_9 -> V_42 = V_3 ;
return V_35 [ V_3 ] . V_43 ;
}
}
return 0 ;
}
static int F_23 ( void )
{
struct V_20 * V_25 ;
T_2 V_44 ;
V_28 V_34 ;
T_3 V_45 ;
V_25 = F_14 ( V_9 -> V_25 ) ;
if ( ! V_13 . V_46 ) {
V_44 = F_24 ( V_9 -> V_31 , V_47 ) ;
V_13 . V_46 = ( volatile V_48 T_1 * ) F_25 ( V_44 , 4096 ) ;
if ( ! V_13 . V_46 )
return - V_6 ;
}
F_4 ( V_9 -> V_30 , V_13 . V_46 + V_49 ) ;
F_5 ( V_13 . V_46 + V_49 ) ;
F_26 ( V_9 -> V_31 , V_50 , 0x80 ) ;
F_26 ( V_9 -> V_31 , V_51 , 0x00 ) ;
V_45 = F_27 ( V_13 . V_46 + V_52 ) ;
V_45 = ( V_45 | 0x0004 ) ;
F_28 ( V_45 , V_13 . V_46 + V_52 ) ;
F_27 ( V_13 . V_46 + V_52 ) ;
F_22 ( V_9 -> V_31 , V_36 , & V_34 ) ;
V_34 = ( ( ( V_34 & ~ ( 0x0000000e ) ) | V_25 -> V_40 ) | 1 ) ;
F_29 ( V_9 -> V_31 , V_36 , V_34 ) ;
F_4 ( 1 , V_13 . V_46 + V_53 ) ;
F_5 ( V_13 . V_46 + V_53 ) ;
return 0 ;
}
static void F_30 ( void )
{
struct V_20 * V_41 ;
V_28 V_34 ;
T_3 V_45 ;
V_41 = F_14 ( V_9 -> V_41 ) ;
V_45 = F_27 ( V_13 . V_46 + V_52 ) ;
V_45 = ( V_45 & ~ ( 0x0004 ) ) ;
F_28 ( V_45 , V_13 . V_46 + V_52 ) ;
F_27 ( V_13 . V_46 + V_52 ) ;
F_22 ( V_9 -> V_31 , V_36 , & V_34 ) ;
V_34 = ( ( V_34 & ~ ( 0x0000000f ) ) | V_41 -> V_40 ) ;
F_29 ( V_9 -> V_31 , V_36 , V_34 ) ;
F_31 ( ( void T_1 * ) V_13 . V_46 ) ;
}
static void F_32 ( struct V_54 * V_34 )
{
F_4 ( 1 , V_13 . V_46 + V_53 ) ;
F_5 ( V_13 . V_46 + V_53 ) ;
}
static int F_33 ( struct V_54 * V_55 , T_4 V_56 , int type )
{
int V_3 , V_57 , V_26 ;
unsigned long T_1 * V_23 ;
unsigned long V_24 ;
V_26 = F_14 ( V_9 -> V_25 ) -> V_26 ;
if ( type != V_55 -> type ||
V_9 -> V_37 -> V_58 ( V_9 , type ) )
return - V_59 ;
if ( ( V_56 + V_55 -> V_60 ) > V_26 )
return - V_59 ;
V_57 = V_56 ;
while ( V_57 < ( V_56 + V_55 -> V_60 ) ) {
V_24 = ( V_57 * V_8 ) + V_9 -> V_33 ;
V_23 = F_18 ( V_24 ) ;
if ( ! F_34 ( V_9 , F_5 ( V_23 + F_19 ( V_24 ) ) ) )
return - V_61 ;
V_57 ++ ;
}
if ( ! V_55 -> V_62 ) {
F_35 () ;
V_55 -> V_62 = true ;
}
for ( V_3 = 0 , V_57 = V_56 ; V_3 < V_55 -> V_60 ; V_3 ++ , V_57 ++ ) {
V_24 = ( V_57 * V_8 ) + V_9 -> V_33 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( F_36 ( V_9 ,
F_37 ( V_55 -> V_63 [ V_3 ] ) ,
V_55 -> type ) ,
V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
F_32 ( V_55 ) ;
return 0 ;
}
static int F_38 ( struct V_54 * V_55 , T_4 V_56 , int type )
{
int V_3 ;
unsigned long T_1 * V_23 ;
unsigned long V_24 ;
if ( type != V_55 -> type ||
V_9 -> V_37 -> V_58 ( V_9 , type ) )
return - V_59 ;
for ( V_3 = V_56 ; V_3 < ( V_55 -> V_60 + V_56 ) ; V_3 ++ ) {
V_24 = ( V_3 * V_8 ) + V_9 -> V_33 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( V_9 -> V_10 , V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
F_32 ( V_55 ) ;
return 0 ;
}
static int F_39 ( struct V_64 * V_65 ,
const struct V_66 * V_67 )
{
struct V_18 * V_19 ;
V_48 V_68 ;
int V_57 ;
V_68 = F_40 ( V_65 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_57 = V_67 - V_71 ;
F_41 ( & V_65 -> V_31 , L_1 ,
V_72 [ V_57 ] . V_73 ) ;
V_19 = F_42 () ;
if ( ! V_19 )
return - V_6 ;
V_19 -> V_37 = & V_74 ;
V_19 -> V_75 = & V_13 ,
V_19 -> V_31 = V_65 ;
V_19 -> V_76 = V_68 ;
if ( V_9 -> V_31 -> V_77 == V_78 ) {
struct V_64 * V_79 = NULL ;
V_68 = 0 ;
while ( ! V_68 ) {
V_79 = F_43 ( V_80 << 8 , V_79 ) ;
if ( ! V_79 ) {
F_41 ( & V_65 -> V_31 , L_2 ) ;
return - V_70 ;
}
V_68 = F_40 ( V_79 , V_69 ) ;
}
if ( V_79 -> V_81 == V_82 ) {
V_9 -> V_83 |= V_84 ;
F_41 ( & V_65 -> V_31 , L_3 ) ;
}
F_44 ( V_79 ) ;
}
if ( V_9 -> V_31 -> V_77 == V_85 ) {
if ( V_65 -> V_86 == 0x10 || V_65 -> V_86 == 0x11 ) {
V_9 -> V_83 = V_87 ;
V_9 -> V_83 |= V_88 ;
V_9 -> V_83 |= V_84 ;
F_41 ( & V_65 -> V_31 , L_4 ) ;
}
}
F_22 ( V_65 ,
V_19 -> V_76 + V_89 ,
& V_19 -> V_90 ) ;
F_45 ( V_65 , V_19 ) ;
return F_46 ( V_19 ) ;
}
static void F_47 ( struct V_64 * V_65 )
{
struct V_18 * V_19 = F_48 ( V_65 ) ;
F_49 ( V_19 ) ;
F_50 ( V_19 ) ;
}
static int F_51 ( struct V_64 * V_65 , T_5 V_91 )
{
F_52 ( V_65 ) ;
F_53 ( V_65 , F_54 ( V_65 , V_91 ) ) ;
return 0 ;
}
static int F_55 ( struct V_64 * V_65 )
{
F_53 ( V_65 , V_92 ) ;
F_56 ( V_65 ) ;
return V_74 . V_93 () ;
}
static int T_6 F_57 ( void )
{
if ( V_94 )
return - V_59 ;
return F_58 ( & V_95 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_95 ) ;
}
