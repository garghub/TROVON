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
unsigned int V_48 ;
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
V_48 = F_30 ( V_45 ) ;
V_40 -> V_50 = V_48 ;
V_41 = F_27 ( V_19 , sizeof( T_2 ) * V_48 , V_49 ) ;
if ( ! V_41 ) {
F_28 ( V_19 , L_9 ) ;
return NULL ;
}
V_40 -> V_41 = V_41 ;
F_31 (np, key_np) {
T_3 V_18 , V_4 , V_51 ;
F_29 ( V_47 , L_10 , & V_18 ) ;
F_29 ( V_47 , L_11 , & V_4 ) ;
F_29 ( V_47 , L_12 , & V_51 ) ;
* V_41 ++ = F_32 ( V_18 , V_4 , V_51 ) ;
}
if ( F_33 ( V_45 , L_13 , NULL ) )
V_38 -> V_52 = true ;
if ( F_33 ( V_45 , L_14 , NULL ) )
V_38 -> V_53 = true ;
return V_38 ;
}
static void F_34 ( struct V_37 * V_19 ,
struct V_1 * V_2 )
{
struct V_44 * V_45 = V_19 -> V_46 ;
int V_54 , error , V_18 , V_4 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_13 ; V_18 ++ ) {
V_54 = F_35 ( V_45 , L_15 , V_18 ) ;
V_2 -> V_55 [ V_18 ] = V_54 ;
if ( ! F_36 ( V_54 ) ) {
F_28 ( V_19 , L_16 ,
V_18 , V_54 ) ;
continue;
}
error = F_37 ( V_19 , V_54 , L_17 ) ;
if ( error )
F_28 ( V_19 ,
L_18 ,
V_18 , error ) ;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ ) {
V_54 = F_35 ( V_45 , L_19 , V_4 ) ;
V_2 -> V_56 [ V_4 ] = V_54 ;
if ( ! F_36 ( V_54 ) ) {
F_28 ( V_19 , L_20 ,
V_4 , V_54 ) ;
continue;
}
error = F_37 ( V_19 , V_54 , L_21 ) ;
if ( error )
F_28 ( V_19 ,
L_22 ,
V_4 , error ) ;
}
}
static
struct V_36 * F_26 ( struct V_37 * V_19 )
{
return NULL ;
}
static int F_38 ( struct V_57 * V_27 )
{
const struct V_36 * V_38 ;
const struct V_39 * V_40 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_14 * V_14 ;
unsigned int V_20 ;
unsigned int V_50 ;
int error ;
if ( V_27 -> V_19 . V_46 )
V_38 = F_26 ( & V_27 -> V_19 ) ;
else
V_38 = V_27 -> V_19 . V_60 ;
if ( ! V_38 ) {
F_28 ( & V_27 -> V_19 , L_23 ) ;
return - V_61 ;
}
V_40 = V_38 -> V_40 ;
if ( ! V_40 ) {
F_28 ( & V_27 -> V_19 , L_24 ) ;
return - V_61 ;
}
if ( ! V_38 -> V_13 || V_38 -> V_13 > V_62 )
return - V_61 ;
if ( ! V_38 -> V_6 || V_38 -> V_6 > V_26 )
return - V_61 ;
if ( V_38 -> V_63 )
V_38 -> V_63 ( V_38 -> V_13 , V_38 -> V_6 ) ;
V_20 = F_39 ( V_38 -> V_6 ) ;
V_50 = ( V_38 -> V_13 << V_20 ) * sizeof( V_2 -> V_23 [ 0 ] ) ;
V_2 = F_27 ( & V_27 -> V_19 , sizeof( * V_2 ) + V_50 ,
V_49 ) ;
V_14 = F_40 ( & V_27 -> V_19 ) ;
if ( ! V_2 || ! V_14 )
return - V_64 ;
V_59 = F_41 ( V_27 , V_65 , 0 ) ;
if ( ! V_59 )
return - V_66 ;
V_2 -> V_10 = F_42 ( & V_27 -> V_19 , V_59 -> V_67 , F_43 ( V_59 ) ) ;
if ( ! V_2 -> V_10 )
return - V_68 ;
V_2 -> V_32 = F_44 ( & V_27 -> V_19 , L_25 ) ;
if ( F_45 ( V_2 -> V_32 ) ) {
F_28 ( & V_27 -> V_19 , L_26 ) ;
return F_46 ( V_2 -> V_32 ) ;
}
error = F_47 ( V_2 -> V_32 ) ;
if ( error ) {
F_28 ( & V_27 -> V_19 , L_27 ) ;
return error ;
}
V_2 -> V_14 = V_14 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_13 = V_38 -> V_13 ;
V_2 -> V_6 = V_38 -> V_6 ;
V_2 -> V_30 = true ;
F_48 ( & V_2 -> V_29 ) ;
if ( V_27 -> V_19 . V_46 ) {
#ifdef F_49
F_34 ( & V_27 -> V_19 , V_2 ) ;
V_2 -> type = F_50 ( V_27 -> V_19 . V_46 ,
L_28 ) ;
#endif
} else {
V_2 -> type = F_51 ( V_27 ) -> V_69 ;
}
V_14 -> V_70 = V_27 -> V_70 ;
V_14 -> V_71 . V_72 = V_73 ;
V_14 -> V_19 . V_74 = & V_27 -> V_19 ;
V_14 -> V_75 = F_23 ;
V_14 -> V_76 = F_25 ;
error = F_52 ( V_40 , NULL ,
V_38 -> V_13 , V_38 -> V_6 ,
V_2 -> V_23 , V_14 ) ;
if ( error ) {
F_28 ( & V_27 -> V_19 , L_29 ) ;
goto V_77;
}
F_53 ( V_14 , V_21 , V_22 ) ;
if ( ! V_38 -> V_52 )
F_54 ( V_78 , V_14 -> V_79 ) ;
F_55 ( V_14 , V_2 ) ;
V_2 -> V_24 = F_56 ( V_27 , 0 ) ;
if ( V_2 -> V_24 < 0 ) {
error = V_2 -> V_24 ;
goto V_77;
}
error = F_57 ( & V_27 -> V_19 , V_2 -> V_24 , NULL ,
F_11 , V_80 ,
F_58 ( & V_27 -> V_19 ) , V_2 ) ;
if ( error ) {
F_28 ( & V_27 -> V_19 , L_30 ) ;
goto V_77;
}
F_59 ( & V_27 -> V_19 , V_38 -> V_53 ) ;
F_60 ( V_27 , V_2 ) ;
F_61 ( & V_27 -> V_19 ) ;
error = F_62 ( V_2 -> V_14 ) ;
if ( error )
goto V_81;
if ( V_27 -> V_19 . V_46 ) {
F_63 ( & V_27 -> V_19 , ( void * ) V_38 -> V_40 -> V_41 ) ;
F_63 ( & V_27 -> V_19 , ( void * ) V_38 -> V_40 ) ;
F_63 ( & V_27 -> V_19 , ( void * ) V_38 ) ;
}
return 0 ;
V_81:
F_64 ( & V_27 -> V_19 ) ;
F_59 ( & V_27 -> V_19 , 0 ) ;
F_60 ( V_27 , NULL ) ;
V_77:
F_65 ( V_2 -> V_32 ) ;
return error ;
}
static int F_66 ( struct V_57 * V_27 )
{
struct V_1 * V_2 = F_67 ( V_27 ) ;
F_64 ( & V_27 -> V_19 ) ;
F_59 ( & V_27 -> V_19 , 0 ) ;
F_60 ( V_27 , NULL ) ;
F_68 ( V_2 -> V_14 ) ;
F_65 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_69 ( struct V_37 * V_19 )
{
struct V_57 * V_27 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_27 ) ;
unsigned int V_5 ;
int error ;
if ( V_2 -> V_30 )
return 0 ;
error = F_71 ( V_2 -> V_24 ) ;
if ( ! error )
V_2 -> V_82 = true ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 |= V_83 ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_21 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_72 ( struct V_37 * V_19 )
{
struct V_57 * V_27 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_27 ) ;
unsigned int V_5 ;
if ( V_2 -> V_30 )
return 0 ;
F_17 ( V_2 -> V_32 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
V_5 &= ~ V_83 ;
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
if ( V_2 -> V_82 )
F_73 ( V_2 -> V_24 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 ,
bool V_84 )
{
unsigned int V_5 ;
F_17 ( V_2 -> V_32 ) ;
V_5 = F_4 ( V_2 -> V_10 + V_33 ) ;
if ( V_84 ) {
V_5 |= V_83 ;
if ( F_75 ( & V_2 -> V_27 -> V_19 ) )
F_71 ( V_2 -> V_24 ) ;
} else {
V_5 &= ~ V_83 ;
if ( F_75 ( & V_2 -> V_27 -> V_19 ) )
F_73 ( V_2 -> V_24 ) ;
}
F_2 ( V_5 , V_2 -> V_10 + V_33 ) ;
F_21 ( V_2 -> V_32 ) ;
}
static int F_76 ( struct V_37 * V_19 )
{
struct V_57 * V_27 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_27 ) ;
struct V_14 * V_14 = V_2 -> V_14 ;
F_77 ( & V_14 -> V_85 ) ;
if ( V_14 -> V_86 )
F_18 ( V_2 ) ;
F_74 ( V_2 , true ) ;
F_78 ( & V_14 -> V_85 ) ;
return 0 ;
}
static int F_79 ( struct V_37 * V_19 )
{
struct V_57 * V_27 = F_70 ( V_19 ) ;
struct V_1 * V_2 = F_67 ( V_27 ) ;
struct V_14 * V_14 = V_2 -> V_14 ;
F_77 ( & V_14 -> V_85 ) ;
F_74 ( V_2 , false ) ;
if ( V_14 -> V_86 )
F_16 ( V_2 ) ;
F_78 ( & V_14 -> V_85 ) ;
return 0 ;
}
