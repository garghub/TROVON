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
int V_19 = V_4 -> V_21 . V_22 ;
int V_12 = 32 - ( V_17 + 1 ) * V_19 ;
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
static int F_34 ( struct V_31 * V_32 , unsigned int V_39 )
{
struct V_3 * V_4 = F_22 ( V_32 ) ;
if ( ! V_4 -> V_40 )
return 0 ;
if ( V_39 )
F_35 ( V_4 -> V_40 ) ;
else
F_36 ( V_4 -> V_40 ) ;
return 0 ;
}
static T_2 F_37 ( int V_17 , void * V_41 )
{
struct V_27 * V_7 = V_41 ;
struct V_3 * V_4 = V_7 -> V_4 ;
unsigned long V_42 ;
F_20 ( V_7 , L_7 ) ;
V_42 = F_11 ( V_4 , V_43 , V_7 -> V_10 ) ;
if ( F_9 ( V_4 , V_43 ) & V_42 ) {
F_10 ( V_4 , V_43 , ~ V_42 ) ;
F_20 ( V_7 , L_8 ) ;
F_38 ( V_7 -> V_30 ) ;
return V_44 ;
}
return V_45 ;
}
static T_2 F_39 ( int V_17 , void * V_41 )
{
struct V_3 * V_4 = V_41 ;
unsigned int V_46 = F_9 ( V_4 , V_43 ) ;
T_2 V_47 = V_45 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
if ( V_46 & F_12 ( 7 - V_48 ) ) {
if ( F_12 ( V_48 ) & V_4 -> V_35 )
continue;
V_47 |= F_37 ( V_17 , & V_4 -> V_17 [ V_48 ] ) ;
}
}
return V_47 ;
}
static int F_40 ( struct V_49 * V_50 , unsigned int V_51 ,
T_3 V_52 )
{
struct V_3 * V_4 = V_50 -> V_53 ;
V_4 -> V_17 [ V_52 ] . V_30 = V_51 ;
V_4 -> V_17 [ V_52 ] . V_10 = V_52 ;
F_20 ( & V_4 -> V_17 [ V_52 ] , L_9 ) ;
F_41 ( V_51 , V_50 -> V_53 ) ;
F_42 ( V_51 , & V_4 -> V_54 , V_55 ) ;
F_43 ( V_51 , V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_57 * V_23 )
{
struct V_58 * V_24 = & V_23 -> V_24 ;
struct V_59 * V_60 = V_24 -> V_61 ;
const struct V_62 * V_63 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_64 * V_65 [ V_66 ] ;
struct V_64 * V_17 ;
struct V_54 * V_54 ;
void (* F_45)( struct V_31 * V_32 );
void (* F_46)( struct V_31 * V_32 );
const char * V_67 = F_47 ( V_24 ) ;
int V_68 ;
int V_69 ;
int V_48 ;
V_4 = F_48 ( V_24 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 ) {
F_49 ( V_24 , L_10 ) ;
return - V_71 ;
}
if ( V_60 ) {
memcpy ( & V_4 -> V_21 , V_60 , sizeof( * V_60 ) ) ;
} else {
F_50 ( V_24 -> V_72 , L_11 ,
& V_4 -> V_21 . V_22 ) ;
V_4 -> V_21 . V_73 = F_51 ( V_24 -> V_72 ,
L_12 ) ;
}
if ( ! V_4 -> V_21 . V_22 )
V_4 -> V_21 . V_22 = 4 ;
V_4 -> V_23 = V_23 ;
F_52 ( V_23 , V_4 ) ;
V_4 -> V_40 = F_53 ( V_24 , NULL ) ;
if ( F_54 ( V_4 -> V_40 ) ) {
F_55 ( V_24 , L_13 ) ;
V_4 -> V_40 = NULL ;
}
F_56 ( V_24 ) ;
F_57 ( V_24 ) ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
V_65 [ V_48 ] = F_58 ( V_23 , V_74 , V_48 ) ;
if ( ! V_65 [ V_48 ] && V_48 < V_75 ) {
F_49 ( V_24 , L_14 ) ;
V_69 = - V_25 ;
goto V_76;
}
}
for ( V_48 = 0 ; V_48 < V_77 ; V_48 ++ ) {
V_17 = F_58 ( V_23 , V_78 , V_48 ) ;
if ( ! V_17 )
break;
V_4 -> V_17 [ V_48 ] . V_4 = V_4 ;
V_4 -> V_17 [ V_48 ] . V_29 = V_17 -> V_79 ;
}
V_4 -> V_80 = V_48 ;
if ( V_4 -> V_80 < 1 ) {
F_49 ( V_24 , L_15 ) ;
V_69 = - V_25 ;
goto V_76;
}
for ( V_48 = 0 ; V_48 < V_66 ; V_48 ++ ) {
V_7 = & V_4 -> V_1 [ V_48 ] ;
if ( ! V_65 [ V_48 ] )
continue;
switch ( F_59 ( V_65 [ V_48 ] ) ) {
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
F_49 ( V_24 , L_16 ) ;
V_69 = - V_25 ;
goto V_76;
}
V_7 -> V_1 = F_60 ( V_24 , V_65 [ V_48 ] -> V_79 ,
F_59 ( V_65 [ V_48 ] ) ) ;
if ( ! V_7 -> V_1 ) {
F_49 ( V_24 , L_17 ) ;
V_69 = - V_81 ;
goto V_76;
}
}
V_63 = F_61 ( V_82 , V_24 ) ;
if ( V_63 && V_63 -> V_2 ) {
const struct V_83 * V_84 = V_63 -> V_2 ;
if ( V_65 [ V_85 ] )
F_14 ( V_4 , V_85 ,
V_84 -> V_86 ,
1 , 1 ) ;
else
F_55 ( V_24 , L_18 ) ;
}
for ( V_48 = 0 ; V_48 < V_4 -> V_80 ; V_48 ++ )
F_17 ( V_4 , V_48 , 1 ) ;
F_10 ( V_4 , V_43 , 0x0 ) ;
V_68 = V_4 -> V_17 [ 0 ] . V_29 ;
V_4 -> V_87 = true ;
for ( V_48 = 1 ; V_48 < V_4 -> V_80 ; V_48 ++ ) {
if ( V_68 != V_4 -> V_17 [ V_48 ] . V_29 ) {
V_4 -> V_87 = false ;
break;
}
}
if ( V_4 -> V_21 . V_73 ) {
F_45 = F_27 ;
F_46 = F_31 ;
} else if ( ! V_4 -> V_87 ) {
F_45 = F_21 ;
F_46 = F_24 ;
} else {
F_45 = F_25 ;
F_46 = F_26 ;
}
V_54 = & V_4 -> V_54 ;
V_54 -> V_67 = V_67 ;
V_54 -> F_32 = F_46 ;
V_54 -> F_29 = F_45 ;
V_54 -> V_88 = F_33 ;
V_54 -> V_89 = F_34 ;
V_54 -> V_14 = V_90 ;
V_4 -> V_49 = F_62 ( V_24 -> V_72 ,
V_4 -> V_80 ,
V_4 -> V_21 . V_91 ,
& V_92 , V_4 ) ;
if ( ! V_4 -> V_49 ) {
V_69 = - V_81 ;
F_49 ( V_24 , L_19 ) ;
goto V_76;
}
if ( V_4 -> V_87 ) {
if ( F_63 ( V_24 , V_4 -> V_17 [ 0 ] . V_29 ,
F_39 ,
V_93 , V_67 , V_4 ) ) {
F_49 ( V_24 , L_20 ) ;
V_69 = - V_94 ;
goto V_95;
}
} else {
for ( V_48 = 0 ; V_48 < V_4 -> V_80 ; V_48 ++ ) {
if ( F_63 ( V_24 , V_4 -> V_17 [ V_48 ] . V_29 ,
F_37 , 0 , V_67 ,
& V_4 -> V_17 [ V_48 ] ) ) {
F_49 ( V_24 , L_20 ) ;
V_69 = - V_94 ;
goto V_95;
}
}
}
for ( V_48 = 0 ; V_48 < V_4 -> V_80 ; V_48 ++ )
F_17 ( V_4 , V_48 , 0 ) ;
F_64 ( V_24 , L_21 , V_4 -> V_80 ) ;
if ( V_4 -> V_21 . V_91 ) {
if ( V_4 -> V_21 . V_91 != V_4 -> V_17 [ 0 ] . V_30 )
F_55 ( V_24 , L_22 ,
V_4 -> V_21 . V_91 , V_4 -> V_17 [ 0 ] . V_30 ) ;
}
return 0 ;
V_95:
F_65 ( V_4 -> V_49 ) ;
V_76:
F_66 ( V_24 ) ;
F_67 ( V_24 ) ;
return V_69 ;
}
static int F_68 ( struct V_57 * V_23 )
{
struct V_3 * V_4 = F_69 ( V_23 ) ;
F_65 ( V_4 -> V_49 ) ;
F_66 ( & V_23 -> V_24 ) ;
F_67 ( & V_23 -> V_24 ) ;
return 0 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_96 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_96 ) ;
}
