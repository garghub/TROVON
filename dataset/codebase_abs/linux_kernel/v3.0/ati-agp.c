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
T_1 V_25 ;
F_18 ( V_10 -> V_19 , V_44 , & V_25 ) ;
V_25 = ( V_25 & 0xfffff000 ) ;
V_14 . V_40 = ( volatile V_42 V_43 * ) F_25 ( V_25 , 4096 ) ;
if ( ! V_14 . V_40 )
return - V_7 ;
if ( F_16 () )
F_22 ( V_10 -> V_19 , V_45 , 0x20000 ) ;
else
F_22 ( V_10 -> V_19 , V_46 , 0x20000 ) ;
F_6 ( 0x60000 , V_14 . V_40 + V_47 ) ;
F_7 ( V_14 . V_40 + V_47 ) ;
F_18 ( V_10 -> V_19 , 4 , & V_25 ) ;
F_22 ( V_10 -> V_19 , 4 , V_25 | ( 1 << 14 ) ) ;
F_6 ( V_10 -> V_48 , V_14 . V_40 + V_49 ) ;
F_7 ( V_14 . V_40 + V_49 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_19 , T_2 V_51 )
{
F_27 ( V_19 ) ;
F_28 ( V_19 , 3 ) ;
return 0 ;
}
static int F_29 ( struct V_50 * V_19 )
{
F_28 ( V_19 , 0 ) ;
F_30 ( V_19 ) ;
return F_24 () ;
}
static int F_31 ( struct V_38 * V_39 ,
T_3 V_52 , int type )
{
int V_3 , V_53 , V_54 ;
unsigned long V_43 * V_55 ;
unsigned long V_56 ;
int V_57 ;
V_54 = F_19 ( V_10 -> V_35 ) -> V_54 ;
V_57 = F_32 ( V_39 -> V_58 , type ) ;
if ( V_57 != 0 || type != V_39 -> type )
return - V_59 ;
if ( V_39 -> V_60 == 0 )
return 0 ;
if ( ( V_52 + V_39 -> V_60 ) > V_54 )
return - V_59 ;
V_53 = V_52 ;
while ( V_53 < ( V_52 + V_39 -> V_60 ) ) {
V_56 = ( V_53 * V_9 ) + V_10 -> V_61 ;
V_55 = F_33 ( V_56 ) ;
if ( ! F_34 ( V_10 , F_7 ( V_55 + F_35 ( V_56 ) ) ) )
return - V_62 ;
V_53 ++ ;
}
if ( ! V_39 -> V_63 ) {
F_36 () ;
V_39 -> V_63 = true ;
}
for ( V_3 = 0 , V_53 = V_52 ; V_3 < V_39 -> V_60 ; V_3 ++ , V_53 ++ ) {
V_56 = ( V_53 * V_9 ) + V_10 -> V_61 ;
V_55 = F_33 ( V_56 ) ;
F_6 ( V_10 -> V_30 -> V_64 ( V_10 ,
F_37 ( V_39 -> V_65 [ V_3 ] ) ,
V_39 -> type ) ,
V_55 + F_35 ( V_56 ) ) ;
}
F_7 ( F_33 ( V_10 -> V_61 ) ) ;
V_10 -> V_30 -> V_66 ( V_39 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 , T_3 V_52 ,
int type )
{
int V_3 ;
unsigned long V_43 * V_55 ;
unsigned long V_56 ;
int V_57 ;
V_57 = F_32 ( V_39 -> V_58 , type ) ;
if ( V_57 != 0 || type != V_39 -> type )
return - V_59 ;
if ( V_39 -> V_60 == 0 )
return 0 ;
for ( V_3 = V_52 ; V_3 < ( V_39 -> V_60 + V_52 ) ; V_3 ++ ) {
V_56 = ( V_3 * V_9 ) + V_10 -> V_61 ;
V_55 = F_33 ( V_56 ) ;
F_6 ( V_10 -> V_11 , V_55 + F_35 ( V_56 ) ) ;
}
F_7 ( F_33 ( V_10 -> V_61 ) ) ;
V_10 -> V_30 -> V_66 ( V_39 ) ;
return 0 ;
}
static int F_39 ( struct V_67 * V_58 )
{
struct V_26 * V_68 ;
struct V_1 V_69 ;
unsigned long V_43 * V_55 ;
unsigned long V_56 ;
int V_18 ;
T_1 V_25 ;
int V_3 ;
struct V_26 * V_35 ;
V_68 = F_19 ( V_10 -> V_35 ) ;
V_18 = F_1 ( & V_69 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_14 ( V_68 -> V_54 / 1024 ) ;
if ( V_18 != 0 ) {
F_8 ( & V_69 ) ;
return V_18 ;
}
V_10 -> V_70 = ( T_1 * ) V_69 . V_5 ;
V_10 -> V_71 = ( T_1 V_43 * ) V_69 . V_8 ;
V_10 -> V_48 = F_40 ( V_69 . V_5 ) ;
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
F_18 ( V_10 -> V_19 , V_72 , & V_25 ) ;
V_56 = ( V_25 & V_73 ) ;
V_10 -> V_61 = V_56 ;
for ( V_3 = 0 ; V_3 < V_68 -> V_54 / 1024 ; V_3 ++ , V_56 += 0x00400000 ) {
F_6 ( F_40 ( V_14 . V_15 [ V_3 ] -> V_5 ) | 1 ,
V_69 . V_8 + F_41 ( V_56 ) ) ;
F_7 ( V_69 . V_8 + F_41 ( V_56 ) ) ;
}
for ( V_3 = 0 ; V_3 < V_68 -> V_54 ; V_3 ++ ) {
V_56 = ( V_3 * V_9 ) + V_10 -> V_61 ;
V_55 = F_33 ( V_56 ) ;
F_6 ( V_10 -> V_11 , V_55 + F_35 ( V_56 ) ) ;
}
return 0 ;
}
static int F_42 ( struct V_67 * V_58 )
{
struct V_1 V_69 ;
V_69 . V_5 = ( unsigned long * ) V_10 -> V_70 ;
V_69 . V_8 = ( unsigned long V_43 * ) V_10 -> V_71 ;
F_12 () ;
F_8 ( & V_69 ) ;
return 0 ;
}
static int T_4 F_43 ( struct V_50 * V_74 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 = V_79 ;
struct V_67 * V_58 ;
V_42 V_80 ;
int V_53 ;
V_80 = F_44 ( V_74 , V_81 ) ;
if ( ! V_80 )
return - V_82 ;
for ( V_53 = 0 ; V_78 [ V_53 ] . V_83 ; V_53 ++ ) {
if ( V_74 -> V_20 == V_78 [ V_53 ] . V_84 )
goto V_85;
}
F_45 ( & V_74 -> V_19 , L_1 ,
V_74 -> V_86 , V_74 -> V_20 ) ;
return - V_82 ;
V_85:
V_58 = F_46 () ;
if ( ! V_58 )
return - V_7 ;
V_58 -> V_19 = V_74 ;
V_58 -> V_87 = V_80 ;
V_58 -> V_30 = & V_88 ;
F_47 ( & V_74 -> V_19 , L_2 , V_78 [ V_53 ] . V_83 ) ;
F_18 ( V_74 ,
V_58 -> V_87 + V_89 ,
& V_58 -> V_90 ) ;
F_48 ( V_74 , V_58 ) ;
return F_49 ( V_58 ) ;
}
static void T_5 F_50 ( struct V_50 * V_74 )
{
struct V_67 * V_58 = F_51 ( V_74 ) ;
F_52 ( V_58 ) ;
F_53 ( V_58 ) ;
}
static int T_6 F_54 ( void )
{
if ( V_91 )
return - V_59 ;
return F_55 ( & V_92 ) ;
}
static void T_7 F_56 ( void )
{
F_57 ( & V_92 ) ;
}
