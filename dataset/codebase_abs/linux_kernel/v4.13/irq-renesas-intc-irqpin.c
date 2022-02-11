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
int V_12 = 32 - ( V_17 + 1 ) * V_19 ;
F_14 ( V_4 , V_20 ,
V_12 , V_19 ,
V_18 ? 0 : ( 1 << V_19 ) - 1 ) ;
}
static int F_18 ( struct V_3 * V_4 , int V_17 , int V_13 )
{
int V_19 = V_4 -> V_21 ;
int V_12 = 32 - ( V_17 + 1 ) * V_19 ;
F_19 ( & V_4 -> V_22 -> V_23 , L_1 , V_17 , V_13 ) ;
if ( V_13 >= ( 1 << V_19 ) )
return - V_24 ;
F_14 ( V_4 , V_25 , V_12 ,
V_19 , V_13 ) ;
return 0 ;
}
static void F_20 ( struct V_26 * V_7 , char * V_27 )
{
F_19 ( & V_7 -> V_4 -> V_22 -> V_23 , L_2 ,
V_27 , V_7 -> V_28 , V_7 -> V_10 , V_7 -> V_29 ) ;
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_10 = F_23 ( V_31 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_3 ) ;
F_13 ( V_4 , V_32 , V_10 ) ;
}
static void F_24 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_10 = F_23 ( V_31 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_4 ) ;
F_13 ( V_4 , V_33 , V_10 ) ;
}
static void F_25 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_10 = F_23 ( V_31 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_5 ) ;
F_13 ( V_4 , V_32 , V_10 ) ;
V_4 -> V_34 &= ~ F_12 ( V_10 ) ;
}
static void F_26 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_10 = F_23 ( V_31 ) ;
F_20 ( & V_4 -> V_17 [ V_10 ] , L_6 ) ;
F_13 ( V_4 , V_33 , V_10 ) ;
V_4 -> V_34 |= F_12 ( V_10 ) ;
}
static void F_27 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_17 = V_4 -> V_17 [ F_23 ( V_31 ) ] . V_28 ;
F_21 ( V_31 ) ;
F_28 ( V_17 ) -> F_29 ( F_30 ( V_17 ) ) ;
}
static void F_31 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_17 = V_4 -> V_17 [ F_23 ( V_31 ) ] . V_28 ;
F_28 ( V_17 ) -> F_32 ( F_30 ( V_17 ) ) ;
F_24 ( V_31 ) ;
}
static int F_33 ( struct V_30 * V_31 , unsigned int type )
{
unsigned char V_13 = V_35 [ type & V_36 ] ;
struct V_3 * V_4 = F_22 ( V_31 ) ;
if ( ! ( V_13 & V_37 ) )
return - V_24 ;
return F_18 ( V_4 , F_23 ( V_31 ) ,
V_13 ^ V_37 ) ;
}
static int F_34 ( struct V_30 * V_31 , unsigned int V_38 )
{
struct V_3 * V_4 = F_22 ( V_31 ) ;
int V_10 = F_23 ( V_31 ) ;
F_35 ( V_4 -> V_17 [ V_10 ] . V_28 , V_38 ) ;
if ( ! V_4 -> V_39 )
return 0 ;
if ( V_38 )
F_36 ( V_4 -> V_39 ) ;
else
F_37 ( V_4 -> V_39 ) ;
return 0 ;
}
static T_2 F_38 ( int V_17 , void * V_40 )
{
struct V_26 * V_7 = V_40 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_41 ;
F_20 ( V_7 , L_7 ) ;
V_41 = F_11 ( V_4 , V_42 , V_7 -> V_10 ) ;
if ( F_9 ( V_4 , V_42 ) & V_41 ) {
F_10 ( V_4 , V_42 , ~ V_41 ) ;
F_20 ( V_7 , L_8 ) ;
F_39 ( V_7 -> V_29 ) ;
return V_43 ;
}
return V_44 ;
}
static T_2 F_40 ( int V_17 , void * V_40 )
{
struct V_3 * V_4 = V_40 ;
unsigned int V_45 = F_9 ( V_4 , V_42 ) ;
T_2 V_46 = V_44 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < 8 ; V_47 ++ ) {
if ( V_45 & F_12 ( 7 - V_47 ) ) {
if ( F_12 ( V_47 ) & V_4 -> V_34 )
continue;
V_46 |= F_38 ( V_17 , & V_4 -> V_17 [ V_47 ] ) ;
}
}
return V_46 ;
}
static int F_41 ( struct V_48 * V_49 , unsigned int V_50 ,
T_3 V_51 )
{
struct V_3 * V_4 = V_49 -> V_52 ;
V_4 -> V_17 [ V_51 ] . V_29 = V_50 ;
V_4 -> V_17 [ V_51 ] . V_10 = V_51 ;
F_20 ( & V_4 -> V_17 [ V_51 ] , L_9 ) ;
F_42 ( V_50 , V_49 -> V_52 ) ;
F_43 ( V_50 , & V_53 ) ;
F_44 ( V_50 , & V_4 -> V_54 , V_55 ) ;
return 0 ;
}
static int F_45 ( struct V_56 * V_22 )
{
const struct V_57 * V_58 = NULL ;
struct V_59 * V_23 = & V_22 -> V_23 ;
const struct V_60 * V_61 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_62 * V_63 [ V_64 ] ;
struct V_62 * V_17 ;
struct V_54 * V_54 ;
void (* F_46)( struct V_30 * V_31 );
void (* F_47)( struct V_30 * V_31 );
const char * V_65 = F_48 ( V_23 ) ;
bool V_66 ;
unsigned int V_67 ;
int V_68 ;
int V_69 ;
int V_47 ;
V_4 = F_49 ( V_23 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 ) {
F_50 ( V_23 , L_10 ) ;
return - V_71 ;
}
F_51 ( V_23 -> V_72 , L_11 ,
& V_4 -> V_21 ) ;
V_66 = F_52 ( V_23 -> V_72 , L_12 ) ;
if ( ! V_4 -> V_21 )
V_4 -> V_21 = 4 ;
V_4 -> V_22 = V_22 ;
F_53 ( V_22 , V_4 ) ;
V_61 = F_54 ( V_73 , V_23 ) ;
if ( V_61 && V_61 -> V_2 ) {
V_58 = V_61 -> V_2 ;
V_4 -> V_74 = V_58 -> V_74 ;
}
V_4 -> V_39 = F_55 ( V_23 , NULL ) ;
if ( F_56 ( V_4 -> V_39 ) ) {
if ( V_4 -> V_74 ) {
F_50 ( V_23 , L_13 ) ;
V_69 = F_57 ( V_4 -> V_39 ) ;
goto V_75;
}
V_4 -> V_39 = NULL ;
}
F_58 ( V_23 ) ;
F_59 ( V_23 ) ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
for ( V_47 = 0 ; V_47 < V_64 ; V_47 ++ ) {
V_63 [ V_47 ] = F_60 ( V_22 , V_76 , V_47 ) ;
if ( ! V_63 [ V_47 ] && V_47 < V_77 ) {
F_50 ( V_23 , L_14 ) ;
V_69 = - V_24 ;
goto V_75;
}
}
for ( V_47 = 0 ; V_47 < V_78 ; V_47 ++ ) {
V_17 = F_60 ( V_22 , V_79 , V_47 ) ;
if ( ! V_17 )
break;
V_4 -> V_17 [ V_47 ] . V_4 = V_4 ;
V_4 -> V_17 [ V_47 ] . V_28 = V_17 -> V_80 ;
}
V_67 = V_47 ;
if ( V_67 < 1 ) {
F_50 ( V_23 , L_15 ) ;
V_69 = - V_24 ;
goto V_75;
}
for ( V_47 = 0 ; V_47 < V_64 ; V_47 ++ ) {
V_7 = & V_4 -> V_1 [ V_47 ] ;
if ( ! V_63 [ V_47 ] )
continue;
switch ( F_61 ( V_63 [ V_47 ] ) ) {
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
F_50 ( V_23 , L_16 ) ;
V_69 = - V_24 ;
goto V_75;
}
V_7 -> V_1 = F_62 ( V_23 , V_63 [ V_47 ] -> V_80 ,
F_61 ( V_63 [ V_47 ] ) ) ;
if ( ! V_7 -> V_1 ) {
F_50 ( V_23 , L_17 ) ;
V_69 = - V_81 ;
goto V_75;
}
}
if ( V_58 && V_58 -> V_82 ) {
if ( V_63 [ V_83 ] )
F_14 ( V_4 , V_83 ,
V_58 -> V_84 , 1 , 1 ) ;
else
F_63 ( V_23 , L_18 ) ;
}
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ )
F_17 ( V_4 , V_47 , 1 ) ;
F_10 ( V_4 , V_42 , 0x0 ) ;
V_68 = V_4 -> V_17 [ 0 ] . V_28 ;
V_4 -> V_85 = 1 ;
for ( V_47 = 1 ; V_47 < V_67 ; V_47 ++ ) {
if ( V_68 != V_4 -> V_17 [ V_47 ] . V_28 ) {
V_4 -> V_85 = 0 ;
break;
}
}
if ( V_66 ) {
F_46 = F_27 ;
F_47 = F_31 ;
} else if ( ! V_4 -> V_85 ) {
F_46 = F_21 ;
F_47 = F_24 ;
} else {
F_46 = F_25 ;
F_47 = F_26 ;
}
V_54 = & V_4 -> V_54 ;
V_54 -> V_65 = V_65 ;
V_54 -> F_32 = F_47 ;
V_54 -> F_29 = F_46 ;
V_54 -> V_86 = F_33 ;
V_54 -> V_87 = F_34 ;
V_54 -> V_14 = V_88 ;
V_4 -> V_48 = F_64 ( V_23 -> V_72 , V_67 , 0 ,
& V_89 , V_4 ) ;
if ( ! V_4 -> V_48 ) {
V_69 = - V_81 ;
F_50 ( V_23 , L_19 ) ;
goto V_75;
}
if ( V_4 -> V_85 ) {
if ( F_65 ( V_23 , V_4 -> V_17 [ 0 ] . V_28 ,
F_40 ,
V_90 , V_65 , V_4 ) ) {
F_50 ( V_23 , L_20 ) ;
V_69 = - V_91 ;
goto V_92;
}
} else {
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ ) {
if ( F_65 ( V_23 , V_4 -> V_17 [ V_47 ] . V_28 ,
F_38 , 0 , V_65 ,
& V_4 -> V_17 [ V_47 ] ) ) {
F_50 ( V_23 , L_20 ) ;
V_69 = - V_91 ;
goto V_92;
}
}
}
for ( V_47 = 0 ; V_47 < V_67 ; V_47 ++ )
F_17 ( V_4 , V_47 , 0 ) ;
F_66 ( V_23 , L_21 , V_67 ) ;
return 0 ;
V_92:
F_67 ( V_4 -> V_48 ) ;
V_75:
F_68 ( V_23 ) ;
F_69 ( V_23 ) ;
return V_69 ;
}
static int F_70 ( struct V_56 * V_22 )
{
struct V_3 * V_4 = F_71 ( V_22 ) ;
F_67 ( V_4 -> V_48 ) ;
F_68 ( & V_22 -> V_23 ) ;
F_69 ( & V_22 -> V_23 ) ;
return 0 ;
}
static int T_4 F_72 ( void )
{
return F_73 ( & V_93 ) ;
}
static void T_5 F_74 ( void )
{
F_75 ( & V_93 ) ;
}
