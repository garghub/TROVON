static unsigned long F_1 ( void T_1 * V_1 )
{
return F_2 ( V_1 ) ;
}
static unsigned long F_3 ( void T_1 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( void T_1 * V_1 , unsigned long V_2 )
{
F_6 ( V_2 , V_1 ) ;
}
static void F_7 ( void T_1 * V_1 , unsigned long V_2 )
{
F_8 ( V_2 , V_1 ) ;
}
static inline unsigned long F_9 ( struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_4 -> V_1 [ V_5 ] ;
return V_7 -> V_8 ( V_7 -> V_1 ) ;
}
static inline void F_10 ( struct V_3 * V_4 ,
int V_5 , unsigned long V_2 )
{
struct V_6 * V_7 = & V_4 -> V_1 [ V_5 ] ;
V_7 -> V_9 ( V_7 -> V_1 , V_2 ) ;
}
static inline unsigned long F_11 ( struct V_3 * V_4 ,
int V_5 , int V_10 )
{
return F_12 ( ( V_4 -> V_1 [ V_5 ] . V_11 - 1 ) - V_10 ) ;
}
static inline void F_13 ( struct V_3 * V_4 ,
int V_5 , int V_10 )
{
F_10 ( V_4 , V_5 , F_11 ( V_4 , V_5 , V_10 ) ) ;
}
static void F_14 ( struct V_3 * V_4 ,
int V_5 , int V_12 ,
int V_11 , int V_13 )
{
unsigned long V_14 ;
unsigned long V_15 ;
F_15 ( & V_16 , V_14 ) ;
V_15 = F_9 ( V_4 , V_5 ) ;
V_15 &= ~ ( ( ( 1 << V_11 ) - 1 ) << V_12 ) ;
V_15 |= V_13 << V_12 ;
F_10 ( V_4 , V_5 , V_15 ) ;
F_16 ( & V_16 , V_14 ) ;
}
static void F_17 ( struct V_3 * V_4 ,
int V_17 , int V_18 )
{
int V_19 = 4 ;
int V_12 = ( 7 - V_17 ) * V_19 ;
F_14 ( V_4 , V_20 ,
V_12 , V_19 ,
V_18 ? 0 : ( 1 << V_19 ) - 1 ) ;
}
static int F_18 ( struct V_3 * V_4 , int V_17 , int V_13 )
{
int V_19 = V_4 -> V_21 . V_22 ;
int V_12 = ( 7 - V_17 ) * V_19 ;
F_19 ( & V_4 -> V_23 -> V_24 , L_1 , V_17 , V_13 ) ;
if ( V_13 >= ( 1 << V_19 ) )
return - V_25 ;
F_14 ( V_4 , V_26 , V_12 ,
V_19 , V_13 ) ;
return 0 ;
}
static void F_20 ( struct V_27 * V_7 , char * V_28 )
{
F_19 ( & V_7 -> V_4 -> V_23 -> V_24 , L_2 ,
V_28 , V_7 -> V_29 , V_7 -> V_10 , V_7 -> V_30 ) ;
}
static void F_21 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_10 = F_23 ( V_32 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_3 ) ;
F_13 ( V_4 , V_33 , V_10 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_10 = F_23 ( V_32 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_4 ) ;
F_13 ( V_4 , V_34 , V_10 ) ;
}
static void F_25 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_10 = F_23 ( V_32 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_5 ) ;
F_13 ( V_4 , V_33 , V_10 ) ;
V_4 -> V_35 &= ~ F_12 ( V_10 ) ;
}
static void F_26 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_10 = F_23 ( V_32 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_6 ) ;
F_13 ( V_4 , V_34 , V_10 ) ;
V_4 -> V_35 |= F_12 ( V_10 ) ;
}
static void F_27 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_17 = V_4 -> V_17 [ F_23 ( V_32 ) ] . V_29 ;
F_21 ( V_32 ) ;
F_28 ( V_17 ) -> F_29 ( F_30 ( V_17 ) ) ;
}
static void F_31 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
int V_17 = V_4 -> V_17 [ F_23 ( V_32 ) ] . V_29 ;
F_28 ( V_17 ) -> F_32 ( F_30 ( V_17 ) ) ;
F_24 ( V_32 ) ;
}
static int F_33 ( struct V_31 * V_32 , unsigned int type )
{
unsigned char V_13 = V_36 [ type & V_37 ] ;
struct V_3 * V_4 = F_22 ( V_32 ) ;
if ( ! ( V_13 & V_38 ) )
return - V_25 ;
return F_18 ( V_4 , F_23 ( V_32 ) ,
V_13 ^ V_38 ) ;
}
static T_2 F_34 ( int V_17 , void * V_39 )
{
struct V_27 * V_7 = V_39 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_40 ;
F_20 ( V_7 , L_7 ) ;
V_40 = F_11 ( V_4 , V_41 , V_7 -> V_10 ) ;
if ( F_9 ( V_4 , V_41 ) & V_40 ) {
F_10 ( V_4 , V_41 , ~ V_40 ) ;
F_20 ( V_7 , L_8 ) ;
F_35 ( V_7 -> V_30 ) ;
return V_42 ;
}
return V_43 ;
}
static T_2 F_36 ( int V_17 , void * V_39 )
{
struct V_3 * V_4 = V_39 ;
unsigned int V_44 = F_9 ( V_4 , V_41 ) ;
T_2 V_45 = V_43 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < 8 ; V_46 ++ ) {
if ( V_44 & F_12 ( 7 - V_46 ) ) {
if ( F_12 ( V_46 ) & V_4 -> V_35 )
continue;
V_45 |= F_34 ( V_17 , & V_4 -> V_17 [ V_46 ] ) ;
}
}
return V_45 ;
}
static int F_37 ( struct V_47 * V_48 , unsigned int V_49 ,
T_3 V_50 )
{
struct V_3 * V_4 = V_48 -> V_51 ;
V_4 -> V_17 [ V_50 ] . V_30 = V_49 ;
V_4 -> V_17 [ V_50 ] . V_10 = V_50 ;
F_20 ( & V_4 -> V_17 [ V_50 ] , L_9 ) ;
F_38 ( V_49 , V_48 -> V_51 ) ;
F_39 ( V_49 , & V_4 -> V_52 , V_53 ) ;
F_40 ( V_49 , V_54 ) ;
return 0 ;
}
static int F_41 ( struct V_55 * V_23 )
{
struct V_56 * V_57 = V_23 -> V_24 . V_58 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_59 * V_60 [ V_61 ] ;
struct V_59 * V_17 ;
struct V_52 * V_52 ;
void (* F_42)( struct V_31 * V_32 );
void (* F_43)( struct V_31 * V_32 );
const char * V_62 = F_44 ( & V_23 -> V_24 ) ;
int V_63 ;
int V_64 ;
int V_46 ;
V_4 = F_45 ( & V_23 -> V_24 , sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 ) {
F_46 ( & V_23 -> V_24 , L_10 ) ;
V_64 = - V_66 ;
goto V_67;
}
if ( V_57 )
memcpy ( & V_4 -> V_21 , V_57 , sizeof( * V_57 ) ) ;
if ( ! V_4 -> V_21 . V_22 )
V_4 -> V_21 . V_22 = 4 ;
V_4 -> V_23 = V_23 ;
F_47 ( V_23 , V_4 ) ;
for ( V_46 = 0 ; V_46 < V_61 ; V_46 ++ ) {
V_60 [ V_46 ] = F_48 ( V_23 , V_68 , V_46 ) ;
if ( ! V_60 [ V_46 ] ) {
F_46 ( & V_23 -> V_24 , L_11 ) ;
V_64 = - V_25 ;
goto V_67;
}
}
for ( V_46 = 0 ; V_46 < V_69 ; V_46 ++ ) {
V_17 = F_48 ( V_23 , V_70 , V_46 ) ;
if ( ! V_17 )
break;
V_4 -> V_17 [ V_46 ] . V_4 = V_4 ;
V_4 -> V_17 [ V_46 ] . V_29 = V_17 -> V_71 ;
}
V_4 -> V_72 = V_46 ;
if ( V_4 -> V_72 < 1 ) {
F_46 ( & V_23 -> V_24 , L_12 ) ;
V_64 = - V_25 ;
goto V_67;
}
for ( V_46 = 0 ; V_46 < V_61 ; V_46 ++ ) {
V_7 = & V_4 -> V_1 [ V_46 ] ;
switch ( F_49 ( V_60 [ V_46 ] ) ) {
case 1 :
V_7 -> V_11 = 8 ;
V_7 -> V_8 = F_3 ;
V_7 -> V_9 = F_7 ;
break;
case 4 :
V_7 -> V_11 = 32 ;
V_7 -> V_8 = F_1 ;
V_7 -> V_9 = F_5 ;
break;
default:
F_46 ( & V_23 -> V_24 , L_13 ) ;
V_64 = - V_25 ;
goto V_67;
}
V_7 -> V_1 = F_50 ( & V_23 -> V_24 , V_60 [ V_46 ] -> V_71 ,
F_49 ( V_60 [ V_46 ] ) ) ;
if ( ! V_7 -> V_1 ) {
F_46 ( & V_23 -> V_24 , L_14 ) ;
V_64 = - V_73 ;
goto V_67;
}
}
for ( V_46 = 0 ; V_46 < V_4 -> V_72 ; V_46 ++ )
F_17 ( V_4 , V_46 , 1 ) ;
F_10 ( V_4 , V_41 , 0x0 ) ;
V_63 = V_4 -> V_17 [ 0 ] . V_29 ;
V_4 -> V_74 = true ;
for ( V_46 = 1 ; V_46 < V_4 -> V_72 ; V_46 ++ ) {
if ( V_63 != V_4 -> V_17 [ V_46 ] . V_29 ) {
V_4 -> V_74 = false ;
break;
}
}
if ( V_4 -> V_21 . V_75 ) {
F_42 = F_27 ;
F_43 = F_31 ;
} else if ( ! V_4 -> V_74 ) {
F_42 = F_21 ;
F_43 = F_24 ;
} else {
F_42 = F_25 ;
F_43 = F_26 ;
}
V_52 = & V_4 -> V_52 ;
V_52 -> V_62 = V_62 ;
V_52 -> F_32 = F_43 ;
V_52 -> F_29 = F_42 ;
V_52 -> V_76 = F_42 ;
V_52 -> V_77 = F_43 ;
V_52 -> V_78 = F_33 ;
V_52 -> V_14 = V_79 ;
V_4 -> V_47 = F_51 ( V_23 -> V_24 . V_80 ,
V_4 -> V_72 ,
V_4 -> V_21 . V_81 ,
& V_82 , V_4 ) ;
if ( ! V_4 -> V_47 ) {
V_64 = - V_73 ;
F_46 ( & V_23 -> V_24 , L_15 ) ;
goto V_67;
}
if ( V_4 -> V_74 ) {
if ( F_52 ( & V_23 -> V_24 , V_4 -> V_17 [ 0 ] . V_29 ,
F_36 ,
V_83 , V_62 , V_4 ) ) {
F_46 ( & V_23 -> V_24 , L_16 ) ;
V_64 = - V_84 ;
goto V_85;
}
} else {
for ( V_46 = 0 ; V_46 < V_4 -> V_72 ; V_46 ++ ) {
if ( F_52 ( & V_23 -> V_24 ,
V_4 -> V_17 [ V_46 ] . V_29 ,
F_34 ,
0 , V_62 , & V_4 -> V_17 [ V_46 ] ) ) {
F_46 ( & V_23 -> V_24 ,
L_16 ) ;
V_64 = - V_84 ;
goto V_85;
}
}
}
for ( V_46 = 0 ; V_46 < V_4 -> V_72 ; V_46 ++ )
F_17 ( V_4 , V_46 , 0 ) ;
F_53 ( & V_23 -> V_24 , L_17 , V_4 -> V_72 ) ;
if ( V_4 -> V_21 . V_81 ) {
if ( V_4 -> V_21 . V_81 != V_4 -> V_17 [ 0 ] . V_30 )
F_54 ( & V_23 -> V_24 , L_18 ,
V_4 -> V_21 . V_81 , V_4 -> V_17 [ 0 ] . V_30 ) ;
}
return 0 ;
V_85:
F_55 ( V_4 -> V_47 ) ;
V_67:
return V_64 ;
}
static int F_56 ( struct V_55 * V_23 )
{
struct V_3 * V_4 = F_57 ( V_23 ) ;
F_55 ( V_4 -> V_47 ) ;
return 0 ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_86 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_86 ) ;
}
