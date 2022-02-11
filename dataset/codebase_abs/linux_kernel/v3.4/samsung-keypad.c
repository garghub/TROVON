static void F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
unsigned int V_5 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
if ( V_2 -> type == V_7 ) {
V_5 = V_8 ;
V_5 &= ~ ( 1 << V_4 ) << 8 ;
} else {
V_5 = V_9 ;
V_5 &= ~ ( 1 << V_4 ) ;
}
F_2 ( V_5 , V_2 -> V_10 + V_11 ) ;
F_3 ( 1 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_12 ) ;
V_3 [ V_4 ] = ~ V_5 & ( ( 1 << V_2 -> V_13 ) - 1 ) ;
}
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
}
static bool F_5 ( struct V_1 * V_2 ,
unsigned int * V_3 )
{
struct V_14 * V_14 = V_2 -> V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
unsigned int V_17 = 0 ;
unsigned int V_5 ;
unsigned int V_4 , V_18 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
V_15 = V_3 [ V_4 ] ^ V_2 -> V_3 [ V_4 ] ;
V_17 |= V_3 [ V_4 ] ;
if ( ! V_15 )
continue;
for ( V_18 = 0 ; V_18 < V_2 -> V_13 ; V_18 ++ ) {
if ( ! ( V_15 & ( 1 << V_18 ) ) )
continue;
V_16 = V_3 [ V_4 ] & ( 1 << V_18 ) ;
F_6 ( & V_2 -> V_14 -> V_19 ,
L_1 ,
V_16 ? L_2 : L_3 , V_18 , V_4 ) ;
V_5 = F_7 ( V_18 , V_4 , V_2 -> V_20 ) ;
F_8 ( V_14 , V_21 , V_22 , V_5 ) ;
F_9 ( V_14 ,
V_2 -> V_23 [ V_5 ] , V_16 ) ;
}
F_10 ( V_2 -> V_14 ) ;
}
memcpy ( V_2 -> V_3 , V_3 , sizeof( V_2 -> V_3 ) ) ;
return V_17 ;
}
static T_1 F_11 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
unsigned int V_3 [ V_26 ] ;
unsigned int V_5 ;
bool V_17 ;
F_12 ( & V_2 -> V_27 -> V_19 ) ;
do {
V_5 = F_4 ( V_2 -> V_10 + V_28 ) ;
F_2 ( ~ 0x0 , V_2 -> V_10 + V_28 ) ;
F_1 ( V_2 , V_3 ) ;
V_17 = F_5 ( V_2 , V_3 ) ;
if ( V_17 )
F_13 ( V_2 -> V_29 , V_2 -> V_30 ,
F_14 ( 50 ) ) ;
} while ( V_17 && ! V_2 -> V_30 );
F_15 ( & V_2 -> V_27 -> V_19 ) ;
return V_31 ;
}
static void F_16 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_12 ( & V_2 -> V_27 -> V_19 ) ;
V_2 -> V_30 = false ;
F_17 ( V_2 -> V_32 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 |= V_34 | V_35 ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_2 ( 0 , V_2 -> V_10 + V_11 ) ;
F_15 ( & V_2 -> V_27 -> V_19 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
F_12 ( & V_2 -> V_27 -> V_19 ) ;
V_2 -> V_30 = true ;
F_19 ( & V_2 -> V_29 ) ;
F_20 ( V_2 -> V_24 ) ;
F_2 ( ~ 0x0 , V_2 -> V_10 + V_28 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 &= ~ ( V_34 | V_35 ) ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_21 ( V_2 -> V_32 ) ;
F_22 ( V_2 -> V_24 ) ;
F_15 ( & V_2 -> V_27 -> V_19 ) ;
}
static int F_23 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_24 ( V_14 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = F_24 ( V_14 ) ;
F_18 ( V_2 ) ;
}
static struct V_36 * F_26 (
struct V_37 * V_19 )
{
struct V_36 * V_38 ;
struct V_39 * V_40 ;
T_2 * V_41 , V_42 = 0 , V_43 = 0 ;
struct V_44 * V_45 = V_19 -> V_46 , * V_47 ;
unsigned int V_48 = 0 ;
V_38 = F_27 ( V_19 , sizeof( * V_38 ) , V_49 ) ;
if ( ! V_38 ) {
F_28 ( V_19 , L_4 ) ;
return NULL ;
}
F_29 ( V_45 , L_5 , & V_42 ) ;
F_29 ( V_45 , L_6 , & V_43 ) ;
if ( ! V_42 || ! V_43 ) {
F_28 ( V_19 , L_7 ) ;
return NULL ;
}
V_38 -> V_13 = V_42 ;
V_38 -> V_6 = V_43 ;
V_40 = F_27 ( V_19 , sizeof( * V_40 ) , V_49 ) ;
if ( ! V_40 ) {
F_28 ( V_19 , L_8 ) ;
return NULL ;
}
V_38 -> V_40 = V_40 ;
F_30 (np, key_np)
V_48 ++ ;
V_40 -> V_50 = V_48 ;
V_41 = F_27 ( V_19 , sizeof( T_2 ) * V_48 , V_49 ) ;
if ( ! V_41 ) {
F_28 ( V_19 , L_9 ) ;
return NULL ;
}
V_40 -> V_41 = V_41 ;
F_30 (np, key_np) {
T_3 V_18 , V_4 , V_51 ;
F_29 ( V_47 , L_10 , & V_18 ) ;
F_29 ( V_47 , L_11 , & V_4 ) ;
F_29 ( V_47 , L_12 , & V_51 ) ;
* V_41 ++ = F_31 ( V_18 , V_4 , V_51 ) ;
}
if ( F_32 ( V_45 , L_13 , NULL ) )
V_38 -> V_52 = true ;
if ( F_32 ( V_45 , L_14 , NULL ) )
V_38 -> V_53 = true ;
return V_38 ;
}
static void F_33 ( struct V_37 * V_19 ,
struct V_1 * V_2 )
{
struct V_44 * V_45 = V_19 -> V_46 ;
int V_54 , V_55 , V_18 , V_4 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_13 ; V_18 ++ ) {
V_54 = F_34 ( V_45 , L_15 , V_18 ) ;
V_2 -> V_56 [ V_18 ] = V_54 ;
if ( ! F_35 ( V_54 ) ) {
F_28 ( V_19 , L_16 ,
V_18 , V_54 ) ;
continue;
}
V_55 = F_36 ( V_54 , L_17 ) ;
if ( V_55 )
F_28 ( V_19 , L_18 ,
V_18 ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
V_54 = F_34 ( V_45 , L_19 , V_4 ) ;
V_2 -> V_57 [ V_4 ] = V_54 ;
if ( ! F_35 ( V_54 ) ) {
F_28 ( V_19 , L_20 ,
V_4 , V_54 ) ;
continue;
}
V_55 = F_36 ( V_54 , L_21 ) ;
if ( V_55 )
F_28 ( V_19 , L_22 ,
V_4 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
int V_58 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_13 ; V_58 ++ )
if ( F_35 ( V_2 -> V_56 [ V_58 ] ) )
F_38 ( V_2 -> V_56 [ V_58 ] ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_6 ; V_58 ++ )
if ( F_35 ( V_2 -> V_57 [ V_58 ] ) )
F_38 ( V_2 -> V_57 [ V_58 ] ) ;
}
static
struct V_36 * F_26 ( struct V_37 * V_19 )
{
return NULL ;
}
static void F_37 ( struct V_1 * V_2 )
{
}
static int T_4 F_39 ( struct V_59 * V_27 )
{
const struct V_36 * V_38 ;
const struct V_39 * V_40 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_14 * V_14 ;
unsigned int V_20 ;
unsigned int V_50 ;
int error ;
if ( V_27 -> V_19 . V_46 )
V_38 = F_26 ( & V_27 -> V_19 ) ;
else
V_38 = V_27 -> V_19 . V_62 ;
if ( ! V_38 ) {
F_28 ( & V_27 -> V_19 , L_23 ) ;
return - V_63 ;
}
V_40 = V_38 -> V_40 ;
if ( ! V_40 ) {
F_28 ( & V_27 -> V_19 , L_24 ) ;
return - V_63 ;
}
if ( ! V_38 -> V_13 || V_38 -> V_13 > V_64 )
return - V_63 ;
if ( ! V_38 -> V_6 || V_38 -> V_6 > V_26 )
return - V_63 ;
if ( V_38 -> V_65 )
V_38 -> V_65 ( V_38 -> V_13 , V_38 -> V_6 ) ;
V_20 = F_40 ( V_38 -> V_6 ) ;
V_50 = ( V_38 -> V_13 << V_20 ) * sizeof( V_2 -> V_23 [ 0 ] ) ;
V_2 = F_41 ( sizeof( * V_2 ) + V_50 , V_49 ) ;
V_14 = F_42 () ;
if ( ! V_2 || ! V_14 ) {
error = - V_66 ;
goto V_67;
}
V_61 = F_43 ( V_27 , V_68 , 0 ) ;
if ( ! V_61 ) {
error = - V_69 ;
goto V_67;
}
V_2 -> V_10 = F_44 ( V_61 -> V_70 , F_45 ( V_61 ) ) ;
if ( ! V_2 -> V_10 ) {
error = - V_71 ;
goto V_67;
}
V_2 -> V_32 = F_46 ( & V_27 -> V_19 , L_25 ) ;
if ( F_47 ( V_2 -> V_32 ) ) {
F_28 ( & V_27 -> V_19 , L_26 ) ;
error = F_48 ( V_2 -> V_32 ) ;
goto V_72;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_13 = V_38 -> V_13 ;
V_2 -> V_6 = V_38 -> V_6 ;
V_2 -> V_30 = true ;
F_49 ( & V_2 -> V_29 ) ;
if ( V_27 -> V_19 . V_46 ) {
#ifdef F_50
F_33 ( & V_27 -> V_19 , V_2 ) ;
V_2 -> type = F_51 ( V_27 -> V_19 . V_46 ,
L_27 ) ;
#endif
} else {
V_2 -> type = F_52 ( V_27 ) -> V_73 ;
}
V_14 -> V_74 = V_27 -> V_74 ;
V_14 -> V_75 . V_76 = V_77 ;
V_14 -> V_19 . V_78 = & V_27 -> V_19 ;
F_53 ( V_14 , V_2 ) ;
V_14 -> V_79 = F_23 ;
V_14 -> V_80 = F_25 ;
V_14 -> V_81 [ 0 ] = F_54 ( V_82 ) ;
if ( ! V_38 -> V_52 )
V_14 -> V_81 [ 0 ] |= F_54 ( V_83 ) ;
F_55 ( V_14 , V_21 , V_22 ) ;
V_14 -> V_84 = V_2 -> V_23 ;
V_14 -> V_85 = sizeof( V_2 -> V_23 [ 0 ] ) ;
V_14 -> V_86 = V_38 -> V_13 << V_20 ;
F_56 ( V_40 , V_20 ,
V_14 -> V_84 , V_14 -> V_87 ) ;
V_2 -> V_24 = F_57 ( V_27 , 0 ) ;
if ( V_2 -> V_24 < 0 ) {
error = V_2 -> V_24 ;
goto V_88;
}
error = F_58 ( V_2 -> V_24 , NULL , F_11 ,
V_89 , F_59 ( & V_27 -> V_19 ) , V_2 ) ;
if ( error ) {
F_28 ( & V_27 -> V_19 , L_28 ) ;
goto V_88;
}
F_60 ( & V_27 -> V_19 , V_38 -> V_53 ) ;
F_61 ( V_27 , V_2 ) ;
F_62 ( & V_27 -> V_19 ) ;
error = F_63 ( V_2 -> V_14 ) ;
if ( error )
goto V_90;
if ( V_27 -> V_19 . V_46 ) {
F_64 ( & V_27 -> V_19 , ( void * ) V_38 -> V_40 -> V_41 ) ;
F_64 ( & V_27 -> V_19 , ( void * ) V_38 -> V_40 ) ;
F_64 ( & V_27 -> V_19 , ( void * ) V_38 ) ;
}
return 0 ;
V_90:
F_65 ( V_2 -> V_24 , V_2 ) ;
F_66 ( & V_27 -> V_19 ) ;
F_60 ( & V_27 -> V_19 , 0 ) ;
F_61 ( V_27 , NULL ) ;
V_88:
F_67 ( V_2 -> V_32 ) ;
F_37 ( V_2 ) ;
V_72:
F_68 ( V_2 -> V_10 ) ;
V_67:
F_69 ( V_14 ) ;
F_70 ( V_2 ) ;
return error ;
}
static int T_5 F_71 ( struct V_59 * V_27 )
{
struct V_1 * V_2 = F_72 ( V_27 ) ;
F_66 ( & V_27 -> V_19 ) ;
F_60 ( & V_27 -> V_19 , 0 ) ;
F_61 ( V_27 , NULL ) ;
F_73 ( V_2 -> V_14 ) ;
F_65 ( V_2 -> V_24 , V_2 ) ;
F_67 ( V_2 -> V_32 ) ;
F_37 ( V_2 ) ;
F_68 ( V_2 -> V_10 ) ;
F_70 ( V_2 ) ;
return 0 ;
}
static int F_74 ( struct V_37 * V_19 )
{
struct V_59 * V_27 = F_75 ( V_19 ) ;
struct V_1 * V_2 = F_72 ( V_27 ) ;
unsigned int V_5 ;
int error ;
if ( V_2 -> V_30 )
return 0 ;
error = F_76 ( V_2 -> V_24 ) ;
if ( ! error )
V_2 -> V_91 = true ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 |= V_92 ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_21 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_77 ( struct V_37 * V_19 )
{
struct V_59 * V_27 = F_75 ( V_19 ) ;
struct V_1 * V_2 = F_72 ( V_27 ) ;
unsigned int V_5 ;
if ( V_2 -> V_30 )
return 0 ;
F_17 ( V_2 -> V_32 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 &= ~ V_92 ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
if ( V_2 -> V_91 )
F_78 ( V_2 -> V_24 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_2 ,
bool V_93 )
{
unsigned int V_5 ;
F_17 ( V_2 -> V_32 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
if ( V_93 ) {
V_5 |= V_92 ;
if ( F_80 ( & V_2 -> V_27 -> V_19 ) )
F_76 ( V_2 -> V_24 ) ;
} else {
V_5 &= ~ V_92 ;
if ( F_80 ( & V_2 -> V_27 -> V_19 ) )
F_78 ( V_2 -> V_24 ) ;
}
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_21 ( V_2 -> V_32 ) ;
}
static int F_81 ( struct V_37 * V_19 )
{
struct V_59 * V_27 = F_75 ( V_19 ) ;
struct V_1 * V_2 = F_72 ( V_27 ) ;
struct V_14 * V_14 = V_2 -> V_14 ;
F_82 ( & V_14 -> V_94 ) ;
if ( V_14 -> V_95 )
F_18 ( V_2 ) ;
F_79 ( V_2 , true ) ;
F_83 ( & V_14 -> V_94 ) ;
return 0 ;
}
static int F_84 ( struct V_37 * V_19 )
{
struct V_59 * V_27 = F_75 ( V_19 ) ;
struct V_1 * V_2 = F_72 ( V_27 ) ;
struct V_14 * V_14 = V_2 -> V_14 ;
F_82 ( & V_14 -> V_94 ) ;
F_79 ( V_2 , false ) ;
if ( V_14 -> V_95 )
F_16 ( V_2 ) ;
F_83 ( & V_14 -> V_94 ) ;
return 0 ;
}
