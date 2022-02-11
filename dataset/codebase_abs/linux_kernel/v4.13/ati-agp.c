static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
V_2 -> V_5 = ( unsigned long * ) F_2 ( V_6 ) ;
if ( V_2 -> V_5 == NULL )
return - V_7 ;
F_3 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
V_4 = F_4 ( F_5 ( V_2 -> V_5 ) ) ;
V_2 -> V_8 = V_2 -> V_5 ;
for ( V_3 = 0 ; V_3 < V_9 / sizeof( unsigned long ) ; V_3 ++ ) {
F_6 ( V_10 -> V_11 , V_2 -> V_8 + V_3 ) ;
F_7 ( V_2 -> V_8 + V_3 ) ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_5 ( V_2 -> V_5 ) ) ;
F_10 ( ( unsigned long ) V_2 -> V_5 , 1 ) ;
F_11 ( ( unsigned long ) V_2 -> V_5 ) ;
}
static void F_12 ( void )
{
int V_3 ;
struct V_1 * * V_12 ;
struct V_1 * V_13 ;
V_12 = V_14 . V_15 ;
for ( V_3 = 0 ; V_3 < V_14 . V_16 ; V_3 ++ ) {
V_13 = V_12 [ V_3 ] ;
if ( V_13 != NULL ) {
if ( V_13 -> V_5 != NULL )
F_8 ( V_13 ) ;
F_13 ( V_13 ) ;
}
}
F_13 ( V_12 ) ;
}
static int F_14 ( int V_17 )
{
struct V_1 * * V_12 ;
struct V_1 * V_13 ;
int V_18 = 0 ;
int V_3 ;
V_12 = F_15 ( ( V_17 + 1 ) * sizeof( struct V_1 * ) , V_6 ) ;
if ( V_12 == NULL )
return - V_7 ;
for ( V_3 = 0 ; V_3 < V_17 ; V_3 ++ ) {
V_13 = F_15 ( sizeof( struct V_1 ) , V_6 ) ;
V_12 [ V_3 ] = V_13 ;
if ( V_13 == NULL ) {
V_18 = - V_7 ;
break;
}
V_18 = F_1 ( V_13 ) ;
if ( V_18 != 0 )
break;
}
V_14 . V_16 = V_3 ;
V_14 . V_15 = V_12 ;
if ( V_18 != 0 )
F_12 () ;
return V_18 ;
}
static int F_16 ( void )
{
if ( ( V_10 -> V_19 -> V_20 == V_21 ) ||
( V_10 -> V_19 -> V_20 == V_22 ) ||
( V_10 -> V_19 -> V_20 == V_23 ) ||
( V_10 -> V_19 -> V_20 == V_24 ) )
return 1 ;
return 0 ;
}
static int F_17 ( void )
{
int V_3 ;
T_1 V_25 ;
struct V_26 * V_27 ;
if ( F_16 () )
F_18 ( V_10 -> V_19 , V_28 , & V_25 ) ;
else
F_18 ( V_10 -> V_19 , V_29 , & V_25 ) ;
V_25 = ( V_25 & 0x0000000e ) ;
V_27 = F_19 ( V_10 -> V_30 -> V_31 ) ;
for ( V_3 = 0 ; V_3 < V_10 -> V_30 -> V_32 ; V_3 ++ ) {
if ( V_25 == V_27 [ V_3 ] . V_33 ) {
V_10 -> V_34 =
V_10 -> V_35 = ( void * ) ( V_27 + V_3 ) ;
V_10 -> V_36 = V_3 ;
return V_27 [ V_3 ] . V_37 ;
}
}
return 0 ;
}
static void F_20 ( struct V_38 * V_39 )
{
F_6 ( 1 , V_14 . V_40 + V_41 ) ;
F_7 ( V_14 . V_40 + V_41 ) ;
}
static void F_21 ( void )
{
struct V_26 * V_34 ;
T_1 V_25 ;
V_34 = F_19 ( V_10 -> V_34 ) ;
if ( F_16 () ) {
F_18 ( V_10 -> V_19 , V_28 , & V_25 ) ;
V_25 = ( ( V_25 & ~ ( 0x0000000f ) ) | V_34 -> V_33 ) ;
F_22 ( V_10 -> V_19 , V_28 , V_25 ) ;
} else {
F_18 ( V_10 -> V_19 , V_29 , & V_25 ) ;
V_25 = ( ( V_25 & ~ ( 0x0000000f ) ) | V_34 -> V_33 ) ;
F_22 ( V_10 -> V_19 , V_29 , V_25 ) ;
}
F_23 ( ( volatile V_42 V_43 * ) V_14 . V_40 ) ;
}
static int F_24 ( void )
{
T_2 V_44 ;
T_1 V_25 ;
V_44 = F_25 ( V_10 -> V_19 , V_45 ) ;
V_14 . V_40 = ( volatile V_42 V_43 * ) F_26 ( V_44 , 4096 ) ;
if ( ! V_14 . V_40 )
return - V_7 ;
if ( F_16 () )
F_22 ( V_10 -> V_19 , V_46 , 0x20000 ) ;
else
F_22 ( V_10 -> V_19 , V_47 , 0x20000 ) ;
F_6 ( 0x60000 , V_14 . V_40 + V_48 ) ;
F_7 ( V_14 . V_40 + V_48 ) ;
F_18 ( V_10 -> V_19 , V_49 , & V_25 ) ;
F_22 ( V_10 -> V_19 , V_49 , V_25 | ( 1 << 14 ) ) ;
F_6 ( V_10 -> V_50 , V_14 . V_40 + V_51 ) ;
F_7 ( V_14 . V_40 + V_51 ) ;
return 0 ;
}
static int F_27 ( struct V_52 * V_19 , T_3 V_53 )
{
F_28 ( V_19 ) ;
F_29 ( V_19 , V_54 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_19 )
{
F_29 ( V_19 , V_55 ) ;
F_31 ( V_19 ) ;
return F_24 () ;
}
static int F_32 ( struct V_38 * V_39 ,
T_4 V_56 , int type )
{
int V_3 , V_57 , V_58 ;
unsigned long V_43 * V_59 ;
unsigned long V_60 ;
int V_61 ;
V_58 = F_19 ( V_10 -> V_35 ) -> V_58 ;
V_61 = F_33 ( V_39 -> V_62 , type ) ;
if ( V_61 != 0 || type != V_39 -> type )
return - V_63 ;
if ( V_39 -> V_64 == 0 )
return 0 ;
if ( ( V_56 + V_39 -> V_64 ) > V_58 )
return - V_63 ;
V_57 = V_56 ;
while ( V_57 < ( V_56 + V_39 -> V_64 ) ) {
V_60 = ( V_57 * V_9 ) + V_10 -> V_65 ;
V_59 = F_34 ( V_60 ) ;
if ( ! F_35 ( V_10 , F_7 ( V_59 + F_36 ( V_60 ) ) ) )
return - V_66 ;
V_57 ++ ;
}
if ( ! V_39 -> V_67 ) {
F_37 () ;
V_39 -> V_67 = true ;
}
for ( V_3 = 0 , V_57 = V_56 ; V_3 < V_39 -> V_64 ; V_3 ++ , V_57 ++ ) {
V_60 = ( V_57 * V_9 ) + V_10 -> V_65 ;
V_59 = F_34 ( V_60 ) ;
F_6 ( V_10 -> V_30 -> V_68 ( V_10 ,
F_38 ( V_39 -> V_69 [ V_3 ] ) ,
V_39 -> type ) ,
V_59 + F_36 ( V_60 ) ) ;
}
F_7 ( F_34 ( V_10 -> V_65 ) ) ;
V_10 -> V_30 -> V_70 ( V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_39 , T_4 V_56 ,
int type )
{
int V_3 ;
unsigned long V_43 * V_59 ;
unsigned long V_60 ;
int V_61 ;
V_61 = F_33 ( V_39 -> V_62 , type ) ;
if ( V_61 != 0 || type != V_39 -> type )
return - V_63 ;
if ( V_39 -> V_64 == 0 )
return 0 ;
for ( V_3 = V_56 ; V_3 < ( V_39 -> V_64 + V_56 ) ; V_3 ++ ) {
V_60 = ( V_3 * V_9 ) + V_10 -> V_65 ;
V_59 = F_34 ( V_60 ) ;
F_6 ( V_10 -> V_11 , V_59 + F_36 ( V_60 ) ) ;
}
F_7 ( F_34 ( V_10 -> V_65 ) ) ;
V_10 -> V_30 -> V_70 ( V_39 ) ;
return 0 ;
}
static int F_40 ( struct V_71 * V_62 )
{
struct V_26 * V_72 ;
struct V_1 V_73 ;
unsigned long V_43 * V_59 ;
unsigned long V_60 ;
int V_18 ;
T_1 V_25 ;
int V_3 ;
struct V_26 * V_35 ;
V_72 = F_19 ( V_10 -> V_35 ) ;
V_18 = F_1 ( & V_73 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_14 ( V_72 -> V_58 / 1024 ) ;
if ( V_18 != 0 ) {
F_8 ( & V_73 ) ;
return V_18 ;
}
V_10 -> V_74 = ( T_1 * ) V_73 . V_5 ;
V_10 -> V_75 = ( T_1 V_43 * ) V_73 . V_8 ;
V_10 -> V_50 = F_41 ( V_73 . V_5 ) ;
V_35 = F_19 ( V_10 -> V_35 ) ;
if ( F_16 () ) {
F_18 ( V_10 -> V_19 , V_28 , & V_25 ) ;
V_25 = ( ( ( V_25 & ~ ( 0x0000000e ) ) | V_35 -> V_33 )
| 0x00000001 ) ;
F_22 ( V_10 -> V_19 , V_28 , V_25 ) ;
F_18 ( V_10 -> V_19 , V_28 , & V_25 ) ;
} else {
F_18 ( V_10 -> V_19 , V_29 , & V_25 ) ;
V_25 = ( ( ( V_25 & ~ ( 0x0000000e ) ) | V_35 -> V_33 )
| 0x00000001 ) ;
F_22 ( V_10 -> V_19 , V_29 , V_25 ) ;
F_18 ( V_10 -> V_19 , V_29 , & V_25 ) ;
}
V_60 = F_42 ( V_10 -> V_19 , V_76 ) ;
V_10 -> V_65 = V_60 ;
for ( V_3 = 0 ; V_3 < V_72 -> V_58 / 1024 ; V_3 ++ , V_60 += 0x00400000 ) {
F_6 ( F_41 ( V_14 . V_15 [ V_3 ] -> V_5 ) | 1 ,
V_73 . V_8 + F_43 ( V_60 ) ) ;
F_7 ( V_73 . V_8 + F_43 ( V_60 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_72 -> V_58 ; V_3 ++ ) {
V_60 = ( V_3 * V_9 ) + V_10 -> V_65 ;
V_59 = F_34 ( V_60 ) ;
F_6 ( V_10 -> V_11 , V_59 + F_36 ( V_60 ) ) ;
}
return 0 ;
}
static int F_44 ( struct V_71 * V_62 )
{
struct V_1 V_73 ;
V_73 . V_5 = ( unsigned long * ) V_10 -> V_74 ;
V_73 . V_8 = ( unsigned long V_43 * ) V_10 -> V_75 ;
F_12 () ;
F_8 ( & V_73 ) ;
return 0 ;
}
static int F_45 ( struct V_52 * V_77 , const struct V_78 * V_79 )
{
struct V_80 * V_81 = V_82 ;
struct V_71 * V_62 ;
V_42 V_83 ;
int V_57 ;
V_83 = F_46 ( V_77 , V_84 ) ;
if ( ! V_83 )
return - V_85 ;
for ( V_57 = 0 ; V_81 [ V_57 ] . V_86 ; V_57 ++ ) {
if ( V_77 -> V_20 == V_81 [ V_57 ] . V_87 )
goto V_88;
}
F_47 ( & V_77 -> V_19 , L_1 ,
V_77 -> V_89 , V_77 -> V_20 ) ;
return - V_85 ;
V_88:
V_62 = F_48 () ;
if ( ! V_62 )
return - V_7 ;
V_62 -> V_19 = V_77 ;
V_62 -> V_90 = V_83 ;
V_62 -> V_30 = & V_91 ;
F_49 ( & V_77 -> V_19 , L_2 , V_81 [ V_57 ] . V_86 ) ;
F_18 ( V_77 ,
V_62 -> V_90 + V_92 ,
& V_62 -> V_93 ) ;
F_50 ( V_77 , V_62 ) ;
return F_51 ( V_62 ) ;
}
static void F_52 ( struct V_52 * V_77 )
{
struct V_71 * V_62 = F_53 ( V_77 ) ;
F_54 ( V_62 ) ;
F_55 ( V_62 ) ;
}
static int T_5 F_56 ( void )
{
if ( V_94 )
return - V_63 ;
return F_57 ( & V_95 ) ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_95 ) ;
}
