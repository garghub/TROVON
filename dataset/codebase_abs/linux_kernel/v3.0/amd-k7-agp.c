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
T_2 V_25 ;
int V_3 ;
V_21 = F_14 ( V_9 -> V_26 ) ;
V_17 = F_1 ( & V_22 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_11 ( V_21 -> V_27 / 1024 ) ;
if ( V_17 != 0 ) {
F_6 ( & V_22 ) ;
return V_17 ;
}
V_9 -> V_28 = ( T_2 * ) V_22 . V_4 ;
V_9 -> V_29 = ( T_2 T_1 * ) V_22 . V_7 ;
V_9 -> V_30 = F_15 ( V_22 . V_4 ) ;
F_16 ( V_9 -> V_31 , V_32 , & V_25 ) ;
V_24 = ( V_25 & V_33 ) ;
V_9 -> V_34 = V_24 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_27 / 1024 ; V_3 ++ , V_24 += 0x00400000 ) {
F_4 ( F_15 ( V_13 . V_14 [ V_3 ] -> V_4 ) | 1 ,
V_22 . V_7 + F_17 ( V_24 ) ) ;
F_5 ( V_22 . V_7 + F_17 ( V_24 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_21 -> V_27 ; V_3 ++ ) {
V_24 = ( V_3 * V_8 ) + V_9 -> V_34 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( V_9 -> V_10 , V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
struct V_1 V_22 ;
V_22 . V_4 = ( unsigned long * ) V_9 -> V_28 ;
V_22 . V_7 = ( unsigned long T_1 * ) V_9 -> V_29 ;
F_9 () ;
F_6 ( & V_22 ) ;
return 0 ;
}
static int F_21 ( void )
{
int V_3 ;
T_2 V_25 ;
struct V_20 * V_35 ;
F_16 ( V_9 -> V_31 , V_36 , & V_25 ) ;
V_25 = ( V_25 & 0x0000000e ) ;
V_35 = F_14 ( V_9 -> V_37 -> V_38 ) ;
for ( V_3 = 0 ; V_3 < V_9 -> V_37 -> V_39 ; V_3 ++ ) {
if ( V_25 == V_35 [ V_3 ] . V_40 ) {
V_9 -> V_41 =
V_9 -> V_26 = ( void * ) ( V_35 + V_3 ) ;
V_9 -> V_42 = V_3 ;
return V_35 [ V_3 ] . V_43 ;
}
}
return 0 ;
}
static int F_22 ( void )
{
struct V_20 * V_26 ;
T_2 V_25 ;
T_3 V_44 ;
V_26 = F_14 ( V_9 -> V_26 ) ;
if ( ! V_13 . V_45 ) {
F_16 ( V_9 -> V_31 , V_46 , & V_25 ) ;
V_25 = ( V_25 & V_33 ) ;
V_13 . V_45 = ( volatile V_47 T_1 * ) F_23 ( V_25 , 4096 ) ;
if ( ! V_13 . V_45 )
return - V_6 ;
}
F_4 ( V_9 -> V_30 , V_13 . V_45 + V_48 ) ;
F_5 ( V_13 . V_45 + V_48 ) ;
F_24 ( V_9 -> V_31 , V_49 , 0x80 ) ;
F_24 ( V_9 -> V_31 , V_50 , 0x00 ) ;
V_44 = F_25 ( V_13 . V_45 + V_51 ) ;
V_44 = ( V_44 | 0x0004 ) ;
F_26 ( V_44 , V_13 . V_45 + V_51 ) ;
F_25 ( V_13 . V_45 + V_51 ) ;
F_16 ( V_9 -> V_31 , V_36 , & V_25 ) ;
V_25 = ( ( ( V_25 & ~ ( 0x0000000e ) ) | V_26 -> V_40 ) | 1 ) ;
F_27 ( V_9 -> V_31 , V_36 , V_25 ) ;
F_4 ( 1 , V_13 . V_45 + V_52 ) ;
F_5 ( V_13 . V_45 + V_52 ) ;
return 0 ;
}
static void F_28 ( void )
{
struct V_20 * V_41 ;
T_2 V_25 ;
T_3 V_44 ;
V_41 = F_14 ( V_9 -> V_41 ) ;
V_44 = F_25 ( V_13 . V_45 + V_51 ) ;
V_44 = ( V_44 & ~ ( 0x0004 ) ) ;
F_26 ( V_44 , V_13 . V_45 + V_51 ) ;
F_25 ( V_13 . V_45 + V_51 ) ;
F_16 ( V_9 -> V_31 , V_36 , & V_25 ) ;
V_25 = ( ( V_25 & ~ ( 0x0000000f ) ) | V_41 -> V_40 ) ;
F_27 ( V_9 -> V_31 , V_36 , V_25 ) ;
F_29 ( ( void T_1 * ) V_13 . V_45 ) ;
}
static void F_30 ( struct V_53 * V_25 )
{
F_4 ( 1 , V_13 . V_45 + V_52 ) ;
F_5 ( V_13 . V_45 + V_52 ) ;
}
static int F_31 ( struct V_53 * V_54 , T_4 V_55 , int type )
{
int V_3 , V_56 , V_27 ;
unsigned long T_1 * V_23 ;
unsigned long V_24 ;
V_27 = F_14 ( V_9 -> V_26 ) -> V_27 ;
if ( type != V_54 -> type ||
V_9 -> V_37 -> V_57 ( V_9 , type ) )
return - V_58 ;
if ( ( V_55 + V_54 -> V_59 ) > V_27 )
return - V_58 ;
V_56 = V_55 ;
while ( V_56 < ( V_55 + V_54 -> V_59 ) ) {
V_24 = ( V_56 * V_8 ) + V_9 -> V_34 ;
V_23 = F_18 ( V_24 ) ;
if ( ! F_32 ( V_9 , F_5 ( V_23 + F_19 ( V_24 ) ) ) )
return - V_60 ;
V_56 ++ ;
}
if ( ! V_54 -> V_61 ) {
F_33 () ;
V_54 -> V_61 = true ;
}
for ( V_3 = 0 , V_56 = V_55 ; V_3 < V_54 -> V_59 ; V_3 ++ , V_56 ++ ) {
V_24 = ( V_56 * V_8 ) + V_9 -> V_34 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( F_34 ( V_9 ,
F_35 ( V_54 -> V_62 [ V_3 ] ) ,
V_54 -> type ) ,
V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
F_30 ( V_54 ) ;
return 0 ;
}
static int F_36 ( struct V_53 * V_54 , T_4 V_55 , int type )
{
int V_3 ;
unsigned long T_1 * V_23 ;
unsigned long V_24 ;
if ( type != V_54 -> type ||
V_9 -> V_37 -> V_57 ( V_9 , type ) )
return - V_58 ;
for ( V_3 = V_55 ; V_3 < ( V_54 -> V_59 + V_55 ) ; V_3 ++ ) {
V_24 = ( V_3 * V_8 ) + V_9 -> V_34 ;
V_23 = F_18 ( V_24 ) ;
F_4 ( V_9 -> V_10 , V_23 + F_19 ( V_24 ) ) ;
F_5 ( V_23 + F_19 ( V_24 ) ) ;
}
F_30 ( V_54 ) ;
return 0 ;
}
static int T_5 F_37 ( struct V_63 * V_64 ,
const struct V_65 * V_66 )
{
struct V_18 * V_19 ;
V_47 V_67 ;
int V_56 ;
V_67 = F_38 ( V_64 , V_68 ) ;
if ( ! V_67 )
return - V_69 ;
V_56 = V_66 - V_70 ;
F_39 ( & V_64 -> V_31 , L_1 ,
V_71 [ V_56 ] . V_72 ) ;
V_19 = F_40 () ;
if ( ! V_19 )
return - V_6 ;
V_19 -> V_37 = & V_73 ;
V_19 -> V_74 = & V_13 ,
V_19 -> V_31 = V_64 ;
V_19 -> V_75 = V_67 ;
if ( V_9 -> V_31 -> V_76 == V_77 ) {
struct V_63 * V_78 = NULL ;
V_67 = 0 ;
while ( ! V_67 ) {
V_78 = F_41 ( V_79 << 8 , V_78 ) ;
if ( ! V_78 ) {
F_39 ( & V_64 -> V_31 , L_2 ) ;
return - V_69 ;
}
V_67 = F_38 ( V_78 , V_68 ) ;
}
if ( V_78 -> V_80 == V_81 ) {
V_9 -> V_82 |= V_83 ;
F_39 ( & V_64 -> V_31 , L_3 ) ;
}
F_42 ( V_78 ) ;
}
if ( V_9 -> V_31 -> V_76 == V_84 ) {
if ( V_64 -> V_85 == 0x10 || V_64 -> V_85 == 0x11 ) {
V_9 -> V_82 = V_86 ;
V_9 -> V_82 |= V_87 ;
V_9 -> V_82 |= V_83 ;
F_39 ( & V_64 -> V_31 , L_4 ) ;
}
}
F_16 ( V_64 ,
V_19 -> V_75 + V_88 ,
& V_19 -> V_89 ) ;
F_43 ( V_64 , V_19 ) ;
return F_44 ( V_19 ) ;
}
static void T_6 F_45 ( struct V_63 * V_64 )
{
struct V_18 * V_19 = F_46 ( V_64 ) ;
F_47 ( V_19 ) ;
F_48 ( V_19 ) ;
}
static int F_49 ( struct V_63 * V_64 , T_7 V_90 )
{
F_50 ( V_64 ) ;
F_51 ( V_64 , F_52 ( V_64 , V_90 ) ) ;
return 0 ;
}
static int F_53 ( struct V_63 * V_64 )
{
F_51 ( V_64 , V_91 ) ;
F_54 ( V_64 ) ;
return V_73 . V_92 () ;
}
static int T_8 F_55 ( void )
{
if ( V_93 )
return - V_58 ;
return F_56 ( & V_94 ) ;
}
static void T_9 F_57 ( void )
{
F_58 ( & V_94 ) ;
}
