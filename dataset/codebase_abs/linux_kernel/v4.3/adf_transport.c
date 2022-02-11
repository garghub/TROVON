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
memcpy ( V_15 -> V_27 + V_15 -> V_28 , V_23 ,
F_19 ( V_15 -> V_7 ) ) ;
V_15 -> V_28 = F_1 ( V_15 -> V_28 +
F_19 ( V_15 -> V_7 ) ,
F_20 ( V_15 -> V_25 ) ) ;
F_21 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_29 , V_15 -> V_28 ) ;
F_11 ( & V_15 -> V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_22 * V_15 )
{
T_1 V_30 = 0 ;
T_1 * V_23 = ( T_1 * ) ( V_15 -> V_27 + V_15 -> V_31 ) ;
while ( * V_23 != V_32 ) {
V_15 -> V_33 ( ( T_1 * ) V_23 ) ;
* V_23 = V_32 ;
V_15 -> V_31 = F_1 ( V_15 -> V_31 +
F_19 ( V_15 -> V_7 ) ,
F_20 ( V_15 -> V_25 ) ) ;
V_30 ++ ;
V_23 = ( T_1 * ) ( V_15 -> V_27 + V_15 -> V_31 ) ;
}
if ( V_30 > 0 ) {
F_23 ( V_15 -> V_14 -> V_19 ,
V_15 -> V_14 -> V_20 ,
V_15 -> V_29 , V_15 -> V_31 ) ;
F_24 ( V_30 , V_15 -> V_24 ) ;
}
return 0 ;
}
static void F_25 ( struct V_22 * V_15 )
{
T_1 V_34 = F_26 ( V_15 -> V_25 ) ;
F_27 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_29 , V_34 ) ;
}
static void F_28 ( struct V_22 * V_15 )
{
T_1 V_34 =
F_29 ( V_15 -> V_25 ,
V_35 ,
V_36 ) ;
F_27 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_29 , V_34 ) ;
}
static int F_30 ( struct V_22 * V_15 )
{
struct V_13 * V_14 = V_15 -> V_14 ;
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_41 ;
T_2 V_42 ;
T_1 V_43 =
F_4 ( V_15 -> V_25 ) ;
V_43 = F_31 ( V_43 ) ;
V_15 -> V_27 = F_32 ( & F_33 ( V_38 ) ,
V_43 , & V_15 -> V_44 ,
V_45 ) ;
if ( ! V_15 -> V_27 )
return - V_46 ;
memset ( V_15 -> V_27 , 0x7F , V_43 ) ;
if ( F_2 ( V_15 -> V_44 , V_43 ) ) {
F_34 ( & F_33 ( V_38 ) , L_1 ) ;
F_35 ( & F_33 ( V_38 ) , V_43 ,
V_15 -> V_27 , V_15 -> V_44 ) ;
return - V_6 ;
}
if ( V_40 -> V_47 & ( 1 << V_15 -> V_29 ) )
F_25 ( V_15 ) ;
else
F_28 ( V_15 ) ;
V_42 = F_36 ( V_15 -> V_44 , V_15 -> V_25 ) ;
F_37 ( V_15 -> V_14 -> V_19 , V_15 -> V_14 -> V_20 ,
V_15 -> V_29 , V_42 ) ;
F_38 ( & V_15 -> V_16 ) ;
return 0 ;
}
static void F_39 ( struct V_22 * V_15 )
{
T_1 V_43 =
F_4 ( V_15 -> V_25 ) ;
V_43 = F_31 ( V_43 ) ;
if ( V_15 -> V_27 ) {
memset ( V_15 -> V_27 , 0x7F , V_43 ) ;
F_35 ( & F_33 ( V_15 -> V_14 -> V_38 ) ,
V_43 , V_15 -> V_27 ,
V_15 -> V_44 ) ;
}
}
int F_40 ( struct V_37 * V_38 , const char * V_48 ,
T_1 V_49 , T_1 V_50 ,
T_1 V_7 , const char * V_51 ,
T_3 V_33 , int V_52 ,
struct V_22 * * V_53 )
{
struct V_54 * V_55 = V_38 -> V_56 ;
struct V_13 * V_14 ;
struct V_22 * V_15 ;
char V_57 [ V_58 ] ;
T_1 V_59 ;
int V_60 ;
if ( V_49 >= F_41 ( V_38 ) ) {
F_34 ( & F_33 ( V_38 ) , L_2 ) ;
return - V_6 ;
}
if ( V_7 > F_19 ( V_61 ) ) {
F_34 ( & F_33 ( V_38 ) , L_3 ) ;
return - V_6 ;
}
if ( F_17 ( F_3 ( V_7 , V_50 ) ,
F_42 ( V_7 ) ) < 2 ) {
F_34 ( & F_33 ( V_38 ) ,
L_4 ) ;
return - V_6 ;
}
if ( F_43 ( V_38 , V_48 , V_51 , V_57 ) ) {
F_34 ( & F_33 ( V_38 ) , L_5 ,
V_48 , V_51 ) ;
return - V_6 ;
}
if ( F_44 ( V_57 , 10 , & V_59 ) ) {
F_34 ( & F_33 ( V_38 ) , L_6 ) ;
return - V_6 ;
}
if ( V_59 >= V_62 ) {
F_34 ( & F_33 ( V_38 ) , L_7 ) ;
return - V_6 ;
}
V_14 = & V_55 -> V_63 [ V_49 ] ;
if ( F_5 ( V_14 , V_59 ) ) {
F_34 ( & F_33 ( V_38 ) , L_8 ,
V_59 , V_51 ) ;
return - V_6 ;
}
V_15 = & V_14 -> V_64 [ V_59 ] ;
V_15 -> V_29 = V_59 ;
V_15 -> V_14 = V_14 ;
V_15 -> V_33 = V_33 ;
V_15 -> V_7 = F_42 ( V_7 ) ;
V_15 -> V_25 = F_3 ( V_7 , V_50 ) ;
V_15 -> V_31 = 0 ;
V_15 -> V_28 = 0 ;
F_45 ( V_15 -> V_24 , 0 ) ;
V_60 = F_30 ( V_15 ) ;
if ( V_60 )
goto V_65;
F_46 ( V_15 ) ;
if ( F_47 ( V_15 , V_51 ) ) {
F_34 ( & F_33 ( V_38 ) ,
L_9 ) ;
V_60 = - V_6 ;
goto V_65;
}
if ( V_33 && ( ! V_52 ) )
F_9 ( V_14 , V_15 -> V_29 ) ;
* V_53 = V_15 ;
return 0 ;
V_65:
F_39 ( V_15 ) ;
F_8 ( V_14 , V_59 ) ;
F_46 ( V_15 ) ;
return V_60 ;
}
void F_48 ( struct V_22 * V_15 )
{
struct V_13 * V_14 = V_15 -> V_14 ;
F_14 ( V_14 , V_15 -> V_29 ) ;
F_27 ( V_14 -> V_19 , V_14 -> V_20 ,
V_15 -> V_29 , 0 ) ;
F_37 ( V_14 -> V_19 , V_14 -> V_20 ,
V_15 -> V_29 , 0 ) ;
F_49 ( V_15 ) ;
F_8 ( V_14 , V_15 -> V_29 ) ;
F_46 ( V_15 ) ;
F_39 ( V_15 ) ;
}
static void F_50 ( struct V_13 * V_14 )
{
T_1 V_66 , V_9 ;
V_66 = F_51 ( V_14 -> V_19 , V_14 -> V_20 ) ;
V_66 = ~ V_66 & V_14 -> V_18 ;
for ( V_9 = 0 ; V_9 < V_62 ; ++ V_9 ) {
if ( V_66 & ( 1 << V_9 ) )
F_22 ( & V_14 -> V_64 [ V_9 ] ) ;
}
}
void F_52 ( unsigned long V_67 )
{
struct V_13 * V_14 = ( void * ) V_67 ;
F_50 ( V_14 ) ;
F_53 ( V_14 -> V_19 , V_14 -> V_20 ,
V_14 -> V_18 ) ;
}
static inline int F_54 ( struct V_37 * V_38 ,
const char * V_48 , const char * V_68 ,
T_1 V_69 , T_1 * V_70 )
{
char V_71 [ V_72 ] ;
char V_73 [ V_58 ] ;
snprintf ( V_71 , V_72 , V_68 , V_69 ) ;
if ( F_43 ( V_38 , V_48 , V_71 , V_73 ) )
return - V_6 ;
if ( F_44 ( V_73 , 10 , V_70 ) )
return - V_6 ;
return 0 ;
}
static void F_55 ( struct V_13 * V_14 ,
const char * V_48 ,
T_1 V_74 )
{
if ( F_54 ( V_14 -> V_38 , V_48 ,
V_75 ,
V_74 , & V_14 -> V_21 ) )
V_14 -> V_21 = V_76 ;
if ( V_77 < V_14 -> V_21 ||
V_78 > V_14 -> V_21 )
V_14 -> V_21 = V_76 ;
}
static int F_56 ( struct V_37 * V_38 ,
struct V_13 * V_14 ,
T_1 V_49 , void T_4 * V_19 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_22 * V_15 ;
struct V_22 * V_79 ;
T_1 V_9 , V_80 = 0 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_20 = V_49 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_38 = V_38 ;
F_38 ( & V_14 -> V_16 ) ;
if ( ( F_54 ( V_38 , L_10 ,
V_81 , V_49 ,
& V_80 ) == 0 ) && V_80 )
F_55 ( V_14 , L_10 , V_49 ) ;
else
V_14 -> V_21 = V_78 ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
F_27 ( V_19 , V_49 , V_9 , 0 ) ;
F_37 ( V_19 , V_49 , V_9 , 0 ) ;
V_15 = & V_14 -> V_64 [ V_9 ] ;
if ( V_40 -> V_47 & ( 1 << V_9 ) ) {
V_15 -> V_24 =
F_57 ( sizeof( V_82 ) ,
V_45 ,
F_58 ( & F_33 ( V_38 ) ) ) ;
if ( ! V_15 -> V_24 )
goto V_65;
} else {
if ( V_9 < V_40 -> V_83 ) {
F_34 ( & F_33 ( V_38 ) ,
L_11 ) ;
goto V_65;
}
V_79 = & V_14 -> V_64 [ V_9 - V_40 -> V_83 ] ;
V_15 -> V_24 = V_79 -> V_24 ;
}
}
if ( F_59 ( V_14 ) ) {
F_34 ( & F_33 ( V_38 ) ,
L_12 ) ;
goto V_65;
}
F_60 ( V_19 , V_49 ) ;
return 0 ;
V_65:
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
V_15 = & V_14 -> V_64 [ V_9 ] ;
if ( V_40 -> V_47 & ( 1 << V_9 ) )
F_61 ( V_15 -> V_24 ) ;
}
return - V_46 ;
}
int F_62 ( struct V_37 * V_38 )
{
struct V_54 * V_84 ;
struct V_39 * V_40 = V_38 -> V_41 ;
void T_4 * V_19 ;
T_1 V_5 ;
T_1 V_85 = 0 ;
int V_9 , V_60 ;
V_84 = F_57 ( sizeof( * V_84 ) , V_45 ,
F_58 ( & F_33 ( V_38 ) ) ) ;
if ( ! V_84 )
return - V_46 ;
V_85 = F_41 ( V_38 ) ;
V_5 = V_85 * sizeof( struct V_13 ) ;
V_84 -> V_63 = F_57 ( V_5 , V_45 ,
F_58 ( & F_33 ( V_38 ) ) ) ;
if ( ! V_84 -> V_63 ) {
V_60 = - V_46 ;
goto V_86;
}
V_38 -> V_56 = V_84 ;
V_9 = V_40 -> V_87 ( V_40 ) ;
V_19 = V_38 -> V_88 . V_89 [ V_9 ] . V_90 ;
V_84 -> V_91 = F_63 ( L_13 ,
V_38 -> V_92 ) ;
if ( ! V_84 -> V_91 ) {
F_34 ( & F_33 ( V_38 ) ,
L_14 ) ;
V_60 = - V_93 ;
goto V_94;
}
for ( V_9 = 0 ; V_9 < V_85 ; V_9 ++ ) {
V_60 = F_56 ( V_38 , & V_84 -> V_63 [ V_9 ] , V_9 ,
V_19 ) ;
if ( V_60 )
goto V_95;
}
return 0 ;
V_95:
F_64 ( V_84 -> V_91 ) ;
V_94:
F_61 ( V_84 -> V_63 ) ;
V_86:
F_61 ( V_84 ) ;
V_38 -> V_56 = NULL ;
return V_60 ;
}
static void F_65 ( struct V_13 * V_14 )
{
T_1 V_9 ;
for ( V_9 = 0 ; V_9 < V_62 ; V_9 ++ ) {
struct V_37 * V_38 = V_14 -> V_38 ;
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_22 * V_15 = & V_14 -> V_64 [ V_9 ] ;
if ( V_14 -> V_17 & ( 1 << V_9 ) )
F_39 ( V_15 ) ;
if ( V_40 -> V_47 & ( 1 << V_9 ) )
F_61 ( V_15 -> V_24 ) ;
}
F_66 ( V_14 ) ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
}
static void F_67 ( struct V_37 * V_38 )
{
struct V_54 * V_84 = V_38 -> V_56 ;
T_1 V_9 , V_85 = F_41 ( V_38 ) ;
for ( V_9 = 0 ; V_9 < V_85 ; V_9 ++ )
F_65 ( & V_84 -> V_63 [ V_9 ] ) ;
}
void F_68 ( struct V_37 * V_38 )
{
struct V_54 * V_84 = V_38 -> V_56 ;
if ( V_84 ) {
F_67 ( V_38 ) ;
F_64 ( V_84 -> V_91 ) ;
F_61 ( V_84 -> V_63 ) ;
F_61 ( V_84 ) ;
V_38 -> V_56 = NULL ;
}
}
