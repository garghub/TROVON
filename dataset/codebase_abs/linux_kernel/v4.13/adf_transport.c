static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
T_1 div = V_1 >> V_2 ;
T_1 V_3 = div << V_2 ;
return V_1 - V_3 ;
}
static inline int F_2 ( T_2 V_4 , T_2 V_5 )
{
if ( ( ( V_5 - 1 ) & V_4 ) != 0 )
return - V_6 ;
return 0 ;
}
static int F_3 ( T_1 V_7 , T_1 V_8 )
{
int V_9 = V_10 ;
for (; V_9 <= V_11 ; V_9 ++ )
if ( ( V_7 * V_8 ) == F_4 ( V_9 ) )
return V_9 ;
return V_12 ;
}
static int F_5 ( struct V_13 * V_14 , T_1 V_15 )
{
F_6 ( & V_14 -> V_16 ) ;
if ( V_14 -> V_17 & ( 1 << V_15 ) ) {
F_7 ( & V_14 -> V_16 ) ;
return - V_6 ;
}
V_14 -> V_17 |= ( 1 << V_15 ) ;
F_7 ( & V_14 -> V_16 ) ;
return 0 ;
}
static void F_8 ( struct V_13 * V_14 , T_1 V_15 )
{
F_6 ( & V_14 -> V_16 ) ;
V_14 -> V_17 &= ~ ( 1 << V_15 ) ;
F_7 ( & V_14 -> V_16 ) ;
}
static void F_9 ( struct V_13 * V_14 , T_1 V_15 )
{
F_10 ( & V_14 -> V_16 ) ;
V_14 -> V_18 |= ( 1 << V_15 ) ;
F_11 ( & V_14 -> V_16 ) ;
F_12 ( V_14 -> V_19 , V_14 -> V_20 , V_14 -> V_18 ) ;
F_13 ( V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_21 ) ;
}
static void F_14 ( struct V_13 * V_14 , T_1 V_15 )
{
F_10 ( & V_14 -> V_16 ) ;
V_14 -> V_18 &= ~ ( 1 << V_15 ) ;
F_11 ( & V_14 -> V_16 ) ;
F_12 ( V_14 -> V_19 , V_14 -> V_20 , V_14 -> V_18 ) ;
}
int F_15 ( struct V_22 * V_15 , T_1 * V_23 )
{
if ( F_16 ( 1 , V_15 -> V_24 ) >
F_17 ( V_15 -> V_25 , V_15 -> V_7 ) ) {
F_18 ( V_15 -> V_24 ) ;
return - V_26 ;
}
F_10 ( & V_15 -> V_16 ) ;
memcpy ( ( void * ) ( ( V_27 ) V_15 -> V_28 + V_15 -> V_29 ) , V_23 ,
F_19 ( V_15 -> V_7 ) ) ;
V_15 -> V_29 = F_1 ( V_15 -> V_29 +
F_19 ( V_15 -> V_7 ) ,
F_20 ( V_15 -> V_25 ) ) ;
F_21 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_30 , V_15 -> V_29 ) ;
F_11 ( & V_15 -> V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_15 )
{
T_1 V_31 = 0 ;
T_1 * V_23 = ( T_1 * ) ( ( V_27 ) V_15 -> V_28 + V_15 -> V_32 ) ;
while ( * V_23 != V_33 ) {
V_15 -> V_34 ( ( T_1 * ) V_23 ) ;
F_18 ( V_15 -> V_24 ) ;
* V_23 = V_33 ;
V_15 -> V_32 = F_1 ( V_15 -> V_32 +
F_19 ( V_15 -> V_7 ) ,
F_20 ( V_15 -> V_25 ) ) ;
V_31 ++ ;
V_23 = ( T_1 * ) ( ( V_27 ) V_15 -> V_28 + V_15 -> V_32 ) ;
}
if ( V_31 > 0 )
F_23 ( V_15 -> V_14 -> V_19 ,
V_15 -> V_14 -> V_20 ,
V_15 -> V_30 , V_15 -> V_32 ) ;
return 0 ;
}
static void F_24 ( struct V_22 * V_15 )
{
T_1 V_35 = F_25 ( V_15 -> V_25 ) ;
F_26 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_30 , V_35 ) ;
}
static void F_27 ( struct V_22 * V_15 )
{
T_1 V_35 =
F_28 ( V_15 -> V_25 ,
V_36 ,
V_37 ) ;
F_26 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_30 , V_35 ) ;
}
static int F_29 ( struct V_22 * V_15 )
{
struct V_13 * V_14 = V_15 -> V_14 ;
struct V_38 * V_39 = V_14 -> V_39 ;
struct V_40 * V_41 = V_39 -> V_42 ;
T_2 V_43 ;
T_1 V_44 =
F_4 ( V_15 -> V_25 ) ;
V_44 = F_30 ( V_44 ) ;
V_15 -> V_28 = F_31 ( & F_32 ( V_39 ) ,
V_44 , & V_15 -> V_45 ,
V_46 ) ;
if ( ! V_15 -> V_28 )
return - V_47 ;
memset ( V_15 -> V_28 , 0x7F , V_44 ) ;
if ( F_2 ( V_15 -> V_45 , V_44 ) ) {
F_33 ( & F_32 ( V_39 ) , L_1 ) ;
F_34 ( & F_32 ( V_39 ) , V_44 ,
V_15 -> V_28 , V_15 -> V_45 ) ;
return - V_6 ;
}
if ( V_41 -> V_48 & ( 1 << V_15 -> V_30 ) )
F_24 ( V_15 ) ;
else
F_27 ( V_15 ) ;
V_43 = F_35 ( V_15 -> V_45 , V_15 -> V_25 ) ;
F_36 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_30 , V_43 ) ;
F_37 ( & V_15 -> V_16 ) ;
return 0 ;
}
static void F_38 ( struct V_22 * V_15 )
{
T_1 V_44 =
F_4 ( V_15 -> V_25 ) ;
V_44 = F_30 ( V_44 ) ;
if ( V_15 -> V_28 ) {
memset ( V_15 -> V_28 , 0x7F , V_44 ) ;
F_34 ( & F_32 ( V_15 -> V_14 -> V_39 ) ,
V_44 , V_15 -> V_28 ,
V_15 -> V_45 ) ;
}
}
int F_39 ( struct V_38 * V_39 , const char * V_49 ,
T_1 V_50 , T_1 V_51 ,
T_1 V_7 , const char * V_52 ,
T_3 V_34 , int V_53 ,
struct V_22 * * V_54 )
{
struct V_55 * V_56 = V_39 -> V_57 ;
struct V_13 * V_14 ;
struct V_22 * V_15 ;
char V_58 [ V_59 ] ;
T_1 V_60 ;
int V_61 ;
if ( V_50 >= F_40 ( V_39 ) ) {
F_33 ( & F_32 ( V_39 ) , L_2 ) ;
return - V_6 ;
}
if ( V_7 > F_19 ( V_62 ) ) {
F_33 ( & F_32 ( V_39 ) , L_3 ) ;
return - V_6 ;
}
if ( F_17 ( F_3 ( V_7 , V_51 ) ,
F_41 ( V_7 ) ) < 2 ) {
F_33 ( & F_32 ( V_39 ) ,
L_4 ) ;
return - V_6 ;
}
if ( F_42 ( V_39 , V_49 , V_52 , V_58 ) ) {
F_33 ( & F_32 ( V_39 ) , L_5 ,
V_49 , V_52 ) ;
return - V_6 ;
}
if ( F_43 ( V_58 , 10 , & V_60 ) ) {
F_33 ( & F_32 ( V_39 ) , L_6 ) ;
return - V_6 ;
}
if ( V_60 >= V_63 ) {
F_33 ( & F_32 ( V_39 ) , L_7 ) ;
return - V_6 ;
}
V_14 = & V_56 -> V_64 [ V_50 ] ;
if ( F_5 ( V_14 , V_60 ) ) {
F_33 ( & F_32 ( V_39 ) , L_8 ,
V_60 , V_52 ) ;
return - V_6 ;
}
V_15 = & V_14 -> V_65 [ V_60 ] ;
V_15 -> V_30 = V_60 ;
V_15 -> V_14 = V_14 ;
V_15 -> V_34 = V_34 ;
V_15 -> V_7 = F_41 ( V_7 ) ;
V_15 -> V_25 = F_3 ( V_7 , V_51 ) ;
V_15 -> V_32 = 0 ;
V_15 -> V_29 = 0 ;
F_44 ( V_15 -> V_24 , 0 ) ;
V_61 = F_29 ( V_15 ) ;
if ( V_61 )
goto V_66;
F_45 ( V_15 ) ;
if ( F_46 ( V_15 , V_52 ) ) {
F_33 ( & F_32 ( V_39 ) ,
L_9 ) ;
V_61 = - V_6 ;
goto V_66;
}
if ( V_34 && ( ! V_53 ) )
F_9 ( V_14 , V_15 -> V_30 ) ;
* V_54 = V_15 ;
return 0 ;
V_66:
F_38 ( V_15 ) ;
F_8 ( V_14 , V_60 ) ;
F_45 ( V_15 ) ;
return V_61 ;
}
void F_47 ( struct V_22 * V_15 )
{
struct V_13 * V_14 = V_15 -> V_14 ;
F_14 ( V_14 , V_15 -> V_30 ) ;
F_26 ( V_14 -> V_19 , V_14 -> V_20 ,
V_15 -> V_30 , 0 ) ;
F_36 ( V_14 -> V_19 , V_14 -> V_20 ,
V_15 -> V_30 , 0 ) ;
F_48 ( V_15 ) ;
F_8 ( V_14 , V_15 -> V_30 ) ;
F_45 ( V_15 ) ;
F_38 ( V_15 ) ;
}
static void F_49 ( struct V_13 * V_14 )
{
T_1 V_67 , V_9 ;
V_67 = F_50 ( V_14 -> V_19 , V_14 -> V_20 ) ;
V_67 = ~ V_67 & V_14 -> V_18 ;
for ( V_9 = 0 ; V_9 < V_63 ; ++ V_9 ) {
if ( V_67 & ( 1 << V_9 ) )
F_22 ( & V_14 -> V_65 [ V_9 ] ) ;
}
}
void F_51 ( V_27 V_68 )
{
struct V_13 * V_14 = ( void * ) V_68 ;
F_49 ( V_14 ) ;
F_52 ( V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_18 ) ;
}
static inline int F_53 ( struct V_38 * V_39 ,
const char * V_49 , const char * V_69 ,
T_1 V_70 , T_1 * V_71 )
{
char V_72 [ V_73 ] ;
char V_74 [ V_59 ] ;
snprintf ( V_72 , V_73 , V_69 , V_70 ) ;
if ( F_42 ( V_39 , V_49 , V_72 , V_74 ) )
return - V_6 ;
if ( F_43 ( V_74 , 10 , V_71 ) )
return - V_6 ;
return 0 ;
}
static void F_54 ( struct V_13 * V_14 ,
const char * V_49 ,
T_1 V_75 )
{
if ( F_53 ( V_14 -> V_39 , V_49 ,
V_76 ,
V_75 , & V_14 -> V_21 ) )
V_14 -> V_21 = V_77 ;
if ( V_78 < V_14 -> V_21 ||
V_79 > V_14 -> V_21 )
V_14 -> V_21 = V_77 ;
}
static int F_55 ( struct V_38 * V_39 ,
struct V_13 * V_14 ,
T_1 V_50 , void T_4 * V_19 )
{
struct V_40 * V_41 = V_39 -> V_42 ;
struct V_22 * V_15 ;
struct V_22 * V_80 ;
T_1 V_9 , V_81 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_20 = V_50 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_39 = V_39 ;
F_37 ( & V_14 -> V_16 ) ;
if ( ( F_53 ( V_39 , L_10 ,
V_82 , V_50 ,
& V_81 ) == 0 ) && V_81 )
F_54 ( V_14 , L_10 , V_50 ) ;
else
V_14 -> V_21 = V_79 ;
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ ) {
F_26 ( V_19 , V_50 , V_9 , 0 ) ;
F_36 ( V_19 , V_50 , V_9 , 0 ) ;
V_15 = & V_14 -> V_65 [ V_9 ] ;
if ( V_41 -> V_48 & ( 1 << V_9 ) ) {
V_15 -> V_24 =
F_56 ( sizeof( V_83 ) ,
V_46 ,
F_57 ( & F_32 ( V_39 ) ) ) ;
if ( ! V_15 -> V_24 )
goto V_66;
} else {
if ( V_9 < V_41 -> V_84 ) {
F_33 ( & F_32 ( V_39 ) ,
L_11 ) ;
goto V_66;
}
V_80 = & V_14 -> V_65 [ V_9 - V_41 -> V_84 ] ;
V_15 -> V_24 = V_80 -> V_24 ;
}
}
if ( F_58 ( V_14 ) ) {
F_33 ( & F_32 ( V_39 ) ,
L_12 ) ;
goto V_66;
}
F_59 ( V_19 , V_50 , V_85 ) ;
F_60 ( V_19 , V_50 ) ;
return 0 ;
V_66:
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ ) {
V_15 = & V_14 -> V_65 [ V_9 ] ;
if ( V_41 -> V_48 & ( 1 << V_9 ) )
F_61 ( V_15 -> V_24 ) ;
}
return - V_47 ;
}
int F_62 ( struct V_38 * V_39 )
{
struct V_55 * V_86 ;
struct V_40 * V_41 = V_39 -> V_42 ;
void T_4 * V_19 ;
T_1 V_5 ;
T_1 V_87 = 0 ;
int V_9 , V_61 ;
V_86 = F_56 ( sizeof( * V_86 ) , V_46 ,
F_57 ( & F_32 ( V_39 ) ) ) ;
if ( ! V_86 )
return - V_47 ;
V_87 = F_40 ( V_39 ) ;
V_5 = V_87 * sizeof( struct V_13 ) ;
V_86 -> V_64 = F_56 ( V_5 , V_46 ,
F_57 ( & F_32 ( V_39 ) ) ) ;
if ( ! V_86 -> V_64 ) {
V_61 = - V_47 ;
goto V_88;
}
V_39 -> V_57 = V_86 ;
V_9 = V_41 -> V_89 ( V_41 ) ;
V_19 = V_39 -> V_90 . V_91 [ V_9 ] . V_92 ;
V_86 -> V_93 = F_63 ( L_13 ,
V_39 -> V_94 ) ;
if ( ! V_86 -> V_93 ) {
F_33 ( & F_32 ( V_39 ) ,
L_14 ) ;
V_61 = - V_95 ;
goto V_96;
}
for ( V_9 = 0 ; V_9 < V_87 ; V_9 ++ ) {
V_61 = F_55 ( V_39 , & V_86 -> V_64 [ V_9 ] , V_9 ,
V_19 ) ;
if ( V_61 )
goto V_97;
}
return 0 ;
V_97:
F_64 ( V_86 -> V_93 ) ;
V_96:
F_61 ( V_86 -> V_64 ) ;
V_88:
F_61 ( V_86 ) ;
V_39 -> V_57 = NULL ;
return V_61 ;
}
static void F_65 ( struct V_13 * V_14 )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ ) {
struct V_38 * V_39 = V_14 -> V_39 ;
struct V_40 * V_41 = V_39 -> V_42 ;
struct V_22 * V_15 = & V_14 -> V_65 [ V_9 ] ;
if ( V_14 -> V_17 & ( 1 << V_9 ) )
F_38 ( V_15 ) ;
if ( V_41 -> V_48 & ( 1 << V_9 ) )
F_61 ( V_15 -> V_24 ) ;
}
F_66 ( V_14 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
static void F_67 ( struct V_38 * V_39 )
{
struct V_55 * V_86 = V_39 -> V_57 ;
T_1 V_9 , V_87 = F_40 ( V_39 ) ;
for ( V_9 = 0 ; V_9 < V_87 ; V_9 ++ )
F_65 ( & V_86 -> V_64 [ V_9 ] ) ;
}
void F_68 ( struct V_38 * V_39 )
{
struct V_55 * V_86 = V_39 -> V_57 ;
if ( V_86 ) {
F_67 ( V_39 ) ;
F_64 ( V_86 -> V_93 ) ;
F_61 ( V_86 -> V_64 ) ;
F_61 ( V_86 ) ;
V_39 -> V_57 = NULL ;
}
}
