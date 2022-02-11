static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = ( unsigned long * ) F_2 ( V_5 ) ;
if ( V_2 -> V_4 == NULL ) {
return - V_6 ;
}
F_3 ( ( unsigned long ) V_2 -> V_4 , 1 ) ;
V_2 -> V_7 = V_2 -> V_4 ;
for ( V_3 = 0 ; V_3 < V_8 / sizeof( unsigned long ) ; V_3 ++ )
F_4 ( V_9 -> V_10 , V_2 -> V_7 + V_3 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( ( unsigned long ) V_2 -> V_4 , 1 ) ;
F_7 ( ( unsigned long ) V_2 -> V_4 ) ;
}
static void F_8 ( void )
{
int V_3 ;
struct V_1 * * V_11 ;
struct V_1 * V_12 ;
V_11 = V_13 . V_14 ;
for ( V_3 = 0 ; V_3 < V_13 . V_15 ; V_3 ++ ) {
V_12 = V_11 [ V_3 ] ;
if ( V_12 != NULL ) {
if ( V_12 -> V_4 != NULL ) {
F_5 ( V_12 ) ;
}
F_9 ( V_12 ) ;
}
}
F_9 ( V_11 ) ;
}
static int F_10 ( int V_16 )
{
struct V_1 * * V_11 ;
struct V_1 * V_12 ;
int V_17 = 0 ;
int V_3 ;
V_11 = F_11 ( ( V_16 + 1 ) * sizeof( struct V_1 * ) ,
V_5 ) ;
if ( V_11 == NULL )
return - V_6 ;
for ( V_3 = 0 ; V_3 < V_16 ; V_3 ++ ) {
V_12 = F_11 ( sizeof( struct V_1 ) , V_5 ) ;
if ( V_12 == NULL ) {
V_17 = - V_6 ;
break;
}
V_11 [ V_3 ] = V_12 ;
V_17 = F_1 ( V_12 ) ;
if ( V_17 != 0 ) break;
}
V_13 . V_15 = V_16 ;
V_13 . V_14 = V_11 ;
if ( V_17 != 0 ) F_8 () ;
return V_17 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 V_22 ;
int V_17 ;
T_1 V_23 ;
int V_3 ;
V_21 = F_13 ( V_9 -> V_24 ) ;
V_17 = F_1 ( & V_22 ) ;
if ( V_17 != 0 ) {
return V_17 ;
}
V_17 = F_1 ( & V_13 . V_25 ) ;
if ( V_17 != 0 ) {
F_5 ( & V_22 ) ;
return V_17 ;
}
for ( V_3 = 0 ; V_3 < 1024 ; V_3 ++ ) {
F_4 ( V_9 -> V_10 , V_13 . V_25 . V_7 + V_3 ) ;
F_4 ( F_14 ( V_13 . V_25 . V_4 ) | 1 , V_22 . V_7 + V_3 ) ;
}
V_17 = F_10 ( V_21 -> V_26 / 1024 ) ;
if ( V_17 != 0 ) {
F_5 ( & V_22 ) ;
F_5 ( & V_13 . V_25 ) ;
return V_17 ;
}
V_9 -> V_27 = ( T_1 * ) V_22 . V_4 ;
V_9 -> V_28 = ( T_1 V_29 * ) V_22 . V_7 ;
V_9 -> V_30 = F_14 ( V_22 . V_4 ) ;
F_15 ( V_9 -> V_31 , V_13 . V_32 , & V_23 ) ;
V_9 -> V_33 = ( V_23 & V_34 ) ;
for ( V_3 = 0 ; V_3 < V_21 -> V_26 / 1024 ; V_3 ++ )
F_4 ( F_14 ( V_13 . V_14 [ V_3 ] -> V_4 ) | 1 , V_22 . V_7 + V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_1 V_22 ;
V_22 . V_4 = ( unsigned long * ) V_9 -> V_27 ;
V_22 . V_7 = ( unsigned long V_29 * ) V_9 -> V_28 ;
F_8 () ;
F_5 ( & V_22 ) ;
F_5 ( & V_13 . V_25 ) ;
return 0 ;
}
static int F_17 ( void )
{
int V_3 ;
T_1 V_23 ;
T_1 V_35 ;
struct V_20 * V_36 ;
V_36 = F_13 ( V_9 -> V_37 -> V_38 ) ;
F_15 ( V_9 -> V_31 , V_13 . V_32 , & V_23 ) ;
F_18 ( V_9 -> V_31 , V_13 . V_32 ,
V_39 ) ;
F_15 ( V_9 -> V_31 , V_13 . V_32 , & V_35 ) ;
F_18 ( V_9 -> V_31 , V_13 . V_32 , V_23 ) ;
V_35 &= V_39 ;
for ( V_3 = 0 ; V_3 < V_9 -> V_37 -> V_40 ; V_3 ++ ) {
if ( V_35 == V_36 [ V_3 ] . V_41 ) {
V_9 -> V_42 =
V_9 -> V_24 = ( void * ) ( V_36 + V_3 ) ;
V_9 -> V_43 = V_3 ;
return V_36 [ V_3 ] . V_44 ;
}
}
return 0 ;
}
static void F_19 ( struct V_45 * V_23 )
{
unsigned long V_46 ;
F_20 ( 1 , V_13 . V_47 + V_48 ) ;
V_46 = V_49 + 3 * V_50 ;
while ( F_21 ( V_13 . V_47 + V_48 ) == 1 ) {
F_22 () ;
if ( F_23 ( V_49 , V_46 ) ) {
F_24 ( & V_13 . V_51 -> V_31 ,
L_1 ) ;
break;
}
}
F_4 ( 1 , V_13 . V_47 + V_52 ) ;
V_46 = V_49 + 3 * V_50 ;
while ( F_25 ( V_13 . V_47 + V_52 ) == 1 ) {
F_22 () ;
if ( F_23 ( V_49 , V_46 ) ) {
F_24 ( & V_13 . V_51 -> V_31 ,
L_2 ) ;
break;
}
}
}
static int F_26 ( void )
{
struct V_20 * V_24 ;
T_1 V_23 ;
T_2 V_53 ;
T_3 V_54 ;
V_24 = F_13 ( V_9 -> V_24 ) ;
F_15 ( V_9 -> V_31 , V_13 . V_55 , & V_23 ) ;
V_23 = ( V_23 & V_34 ) ;
V_13 . V_47 = ( volatile T_2 V_29 * ) F_27 ( V_23 , 4096 ) ;
if ( ! V_13 . V_47 ) {
F_24 ( & V_9 -> V_31 -> V_31 , L_3 , V_23 ) ;
return - V_6 ;
}
F_20 ( 0xA , V_13 . V_47 + V_56 ) ;
F_21 ( V_13 . V_47 + V_56 ) ;
F_4 ( V_9 -> V_30 , V_13 . V_47 + V_57 ) ;
F_25 ( V_13 . V_47 + V_57 ) ;
V_54 = F_28 ( V_13 . V_47 + V_58 ) ;
V_54 &= ~ 0x0007 ;
V_54 |= 0x4 ;
F_29 ( V_54 , V_13 . V_47 + V_58 ) ;
F_28 ( V_13 . V_47 + V_58 ) ;
F_30 ( V_13 . V_51 , V_59 , & V_53 ) ;
V_53 |= 0x1 ;
F_31 ( V_13 . V_51 , V_59 , V_53 ) ;
F_19 ( NULL ) ;
V_9 -> V_60 = F_32 ( V_13 . V_51 , V_61 ) ;
F_15 ( V_13 . V_51 ,
V_9 -> V_60 + V_62 , & V_9 -> V_63 ) ;
F_30 ( V_9 -> V_31 , V_64 , & V_53 ) ;
V_53 &= ~ 0x3 ;
F_31 ( V_9 -> V_31 , V_64 , V_53 ) ;
F_30 ( V_9 -> V_31 , V_65 , & V_53 ) ;
V_53 |= ( 1 << 6 ) ;
F_31 ( V_9 -> V_31 , V_65 , V_53 ) ;
return 0 ;
}
static void F_33 ( void )
{
F_34 ( ( void V_29 * ) V_13 . V_47 ) ;
}
static int F_35 ( struct V_45 * V_66 ,
T_4 V_67 , int type )
{
int V_3 , V_68 , V_26 ;
unsigned long V_29 * V_69 ;
unsigned long V_70 ;
V_26 = F_13 ( V_9 -> V_24 ) -> V_26 ;
if ( type != 0 || V_66 -> type != 0 ) {
return - V_71 ;
}
if ( ( V_67 + V_66 -> V_72 ) > V_26 ) {
return - V_71 ;
}
V_68 = V_67 ;
while ( V_68 < ( V_67 + V_66 -> V_72 ) ) {
V_70 = ( V_68 * V_8 ) + V_9 -> V_33 ;
V_69 = F_36 ( V_70 ) ;
if ( ! F_37 ( V_9 , F_25 ( V_69 + F_38 ( V_70 ) ) ) )
return - V_73 ;
V_68 ++ ;
}
if ( ! V_66 -> V_74 ) {
F_39 () ;
V_66 -> V_74 = true ;
}
for ( V_3 = 0 , V_68 = V_67 ; V_3 < V_66 -> V_72 ; V_3 ++ , V_68 ++ ) {
V_70 = ( V_68 * V_8 ) + V_9 -> V_33 ;
V_69 = F_36 ( V_70 ) ;
F_4 ( V_9 -> V_37 -> V_75 ( V_9 ,
F_40 ( V_66 -> V_76 [ V_3 ] ) , V_66 -> type ) ,
V_69 + F_38 ( V_70 ) ) ;
}
F_19 ( V_66 ) ;
return 0 ;
}
static int F_41 ( struct V_45 * V_66 , T_4 V_67 ,
int type )
{
int V_3 ;
unsigned long V_29 * V_69 ;
unsigned long V_70 ;
if ( type != 0 || V_66 -> type != 0 ) {
return - V_71 ;
}
F_39 () ;
F_19 ( V_66 ) ;
for ( V_3 = V_67 ; V_3 < ( V_66 -> V_72 + V_67 ) ; V_3 ++ ) {
V_70 = ( V_3 * V_8 ) + V_9 -> V_33 ;
V_69 = F_36 ( V_70 ) ;
F_4 ( V_9 -> V_10 , V_69 + F_38 ( V_70 ) ) ;
}
F_19 ( V_66 ) ;
return 0 ;
}
static void F_42 ( struct V_18 * V_19 , T_1 V_63 )
{
T_1 V_77 ;
F_15 ( V_13 . V_51 ,
V_19 -> V_60 + V_62 ,
& V_77 ) ;
V_77 = F_43 ( V_19 , V_63 , V_77 ) ;
V_77 &= ~ 0x10 ;
V_77 &= ~ 0x08 ;
V_77 |= 0x100 ;
F_18 ( V_13 . V_51 ,
V_19 -> V_60 + V_78 ,
V_77 ) ;
F_44 ( V_77 , false ) ;
}
static int F_45 ( struct V_79 * V_80 ,
const struct V_81 * V_82 )
{
struct V_18 * V_19 ;
struct V_79 * V_83 ;
T_1 V_23 , V_35 ;
T_2 V_84 = 0 ;
V_84 = F_32 ( V_80 , V_61 ) ;
switch ( V_80 -> V_85 ) {
case 0x0006 :
F_24 ( & V_80 -> V_31 , L_4 ) ;
return - V_86 ;
case V_87 :
case V_88 :
case 0x0007 :
break;
default:
if ( V_84 )
F_24 ( & V_80 -> V_31 , L_5
L_6 , V_80 -> V_89 , V_80 -> V_85 ) ;
return - V_86 ;
}
V_83 = F_46 ( ( unsigned int ) V_80 -> V_90 -> V_91 ,
F_47 ( 0 , 1 ) ) ;
if ( ! V_83 ) {
F_48 ( & V_80 -> V_31 , L_7 ) ;
return - V_86 ;
}
V_13 . V_51 = V_83 ;
V_13 . V_32 = 0x10 ;
F_15 ( V_80 , V_92 , & V_23 ) ;
if ( V_23 & V_93 ) {
F_15 ( V_80 , V_92 + 4 , & V_35 ) ;
if ( V_35 != 0 ) {
F_48 ( & V_80 -> V_31 , L_8
L_9 ) ;
return - V_86 ;
}
V_13 . V_55 = 0x18 ;
} else
V_13 . V_55 = 0x14 ;
F_15 ( V_80 , V_13 . V_55 , & V_23 ) ;
if ( V_23 & V_93 ) {
F_15 ( V_80 ,
V_13 . V_55 + 4 , & V_35 ) ;
if ( V_35 != 0 ) {
F_48 ( & V_80 -> V_31 , L_10
L_11 ) ;
return - V_86 ;
}
}
V_19 = F_49 () ;
if ( ! V_19 )
return - V_6 ;
V_19 -> V_37 = & V_94 ;
V_19 -> V_95 = & V_13 ,
V_19 -> V_31 = F_50 ( V_80 ) ;
F_51 ( V_80 , V_19 ) ;
return F_52 ( V_19 ) ;
}
static void F_53 ( struct V_79 * V_80 )
{
struct V_18 * V_19 = F_54 ( V_80 ) ;
F_55 ( V_19 -> V_31 ) ;
F_56 ( V_19 ) ;
F_57 ( V_19 ) ;
F_55 ( V_13 . V_51 ) ;
V_13 . V_51 = NULL ;
}
static int T_5 F_58 ( void )
{
if ( V_96 )
return - V_71 ;
return F_59 ( & V_97 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_97 ) ;
}
