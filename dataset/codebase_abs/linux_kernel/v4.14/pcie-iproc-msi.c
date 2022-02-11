static inline T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
unsigned int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
return F_2 ( V_7 -> V_8 + V_2 -> V_9 [ V_5 ] [ V_4 ] ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
int V_5 , T_1 V_10 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
F_4 ( V_10 , V_7 -> V_8 + V_2 -> V_9 [ V_5 ] [ V_4 ] ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned long V_11 )
{
return ( V_11 % V_2 -> V_12 ) ;
}
static inline unsigned int F_6 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
if ( V_2 -> V_13 > 1 )
return F_5 ( V_2 , V_11 ) * V_14 ;
else
return F_5 ( V_2 , V_11 ) * sizeof( T_1 ) ;
}
static inline unsigned int F_7 ( struct V_1 * V_2 , T_1 V_5 )
{
if ( V_2 -> V_15 > 1 )
return V_5 * V_16 ;
else
return V_5 * V_17 * sizeof( T_1 ) ;
}
static inline int F_8 ( struct V_1 * V_2 , unsigned long V_11 )
{
return ( V_11 % V_2 -> V_18 ) ;
}
static inline unsigned long F_9 ( struct V_1 * V_2 ,
unsigned long V_11 )
{
return ( V_11 - F_8 ( V_2 , V_11 ) ) ;
}
static int F_10 ( struct V_19 * V_20 ,
const struct V_21 * V_22 , bool V_23 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
int V_24 = F_12 ( V_22 ) ;
int V_25 ;
V_25 = F_8 ( V_2 , V_20 -> V_11 ) ;
if ( V_25 == V_24 )
return V_26 ;
V_20 -> V_11 = F_9 ( V_2 , V_20 -> V_11 ) + V_24 ;
return V_27 ;
}
static void F_13 ( struct V_19 * V_20 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_11 ( V_20 ) ;
T_2 V_30 ;
V_30 = V_2 -> V_31 + F_6 ( V_2 , V_20 -> V_11 ) ;
V_29 -> V_32 = F_14 ( V_30 ) ;
V_29 -> V_33 = F_15 ( V_30 ) ;
V_29 -> V_20 = V_20 -> V_11 ;
}
static int F_16 ( struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_12 ,
void * args )
{
struct V_1 * V_2 = V_35 -> V_37 ;
int V_11 ;
F_17 ( & V_2 -> V_38 ) ;
V_11 = F_18 ( V_2 -> V_39 , V_2 -> V_40 , 0 ,
V_2 -> V_18 , 0 ) ;
if ( V_11 < V_2 -> V_40 ) {
F_19 ( V_2 -> V_39 , V_11 , V_2 -> V_18 ) ;
} else {
F_20 ( & V_2 -> V_38 ) ;
return - V_41 ;
}
F_20 ( & V_2 -> V_38 ) ;
F_21 ( V_35 , V_36 , V_11 , & V_42 ,
V_35 -> V_37 , V_43 , NULL , NULL ) ;
return 0 ;
}
static void F_22 ( struct V_34 * V_35 ,
unsigned int V_36 , unsigned int V_12 )
{
struct V_19 * V_20 = F_23 ( V_35 , V_36 ) ;
struct V_1 * V_2 = F_11 ( V_20 ) ;
unsigned int V_11 ;
F_17 ( & V_2 -> V_38 ) ;
V_11 = F_9 ( V_2 , V_20 -> V_11 ) ;
F_24 ( V_2 -> V_39 , V_11 , V_2 -> V_18 ) ;
F_20 ( & V_2 -> V_38 ) ;
F_25 ( V_35 , V_36 , V_12 ) ;
}
static inline T_1 F_26 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_44 )
{
T_1 * V_29 , V_11 ;
unsigned int V_45 ;
V_45 = F_7 ( V_2 , V_5 ) + V_44 * sizeof( T_1 ) ;
V_29 = ( T_1 * ) ( V_2 -> V_46 + V_45 ) ;
V_11 = * V_29 & V_47 ;
return F_9 ( V_2 , V_11 ) ;
}
static void F_27 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = F_28 ( V_49 ) ;
struct V_52 * V_53 ;
struct V_1 * V_2 ;
T_1 V_5 , V_44 , V_54 , V_55 ;
unsigned long V_11 ;
int V_36 ;
F_29 ( V_51 , V_49 ) ;
V_53 = F_30 ( V_49 ) ;
V_2 = V_53 -> V_2 ;
V_5 = V_53 -> V_5 ;
V_44 = F_1 ( V_2 , V_56 ,
V_5 ) & V_47 ;
do {
V_54 = F_1 ( V_2 , V_57 ,
V_5 ) & V_47 ;
V_55 = ( V_54 < V_44 ) ?
( V_17 - ( V_44 - V_54 ) ) : ( V_54 - V_44 ) ;
if ( ! V_55 )
break;
while ( V_55 -- ) {
V_11 = F_26 ( V_2 , V_5 , V_44 ) ;
V_36 = F_31 ( V_2 -> V_58 , V_11 ) ;
F_32 ( V_36 ) ;
V_44 ++ ;
V_44 %= V_17 ;
}
F_3 ( V_2 , V_56 , V_5 , V_44 ) ;
} while ( true );
F_33 ( V_51 , V_49 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
int V_59 , V_5 ;
T_1 V_10 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_15 ; V_59 ++ ) {
T_2 V_30 = V_2 -> V_60 + ( V_59 * V_16 ) ;
F_3 ( V_2 , V_61 , V_59 ,
F_14 ( V_30 ) ) ;
F_3 ( V_2 , V_62 , V_59 ,
F_15 ( V_30 ) ) ;
}
for ( V_59 = 0 ; V_59 < V_2 -> V_13 ; V_59 ++ ) {
T_3 V_30 = V_2 -> V_31 + ( V_59 * V_14 ) ;
F_3 ( V_2 , V_63 , V_59 ,
F_14 ( V_30 ) ) ;
F_3 ( V_2 , V_64 , V_59 ,
F_15 ( V_30 ) ) ;
}
for ( V_5 = 0 ; V_5 < V_2 -> V_12 ; V_5 ++ ) {
V_10 = V_65 | V_66 |
V_67 ;
F_3 ( V_2 , V_68 , V_5 , V_10 ) ;
if ( V_2 -> V_69 ) {
V_10 = F_1 ( V_2 , V_70 , V_5 ) ;
V_10 |= F_35 ( V_5 ) ;
F_3 ( V_2 , V_70 , V_5 , V_10 ) ;
}
}
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_5 , V_10 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_12 ; V_5 ++ ) {
if ( V_2 -> V_69 ) {
V_10 = F_1 ( V_2 , V_70 , V_5 ) ;
V_10 &= ~ F_35 ( V_5 ) ;
F_3 ( V_2 , V_70 , V_5 , V_10 ) ;
}
V_10 = F_1 ( V_2 , V_68 , V_5 ) ;
V_10 &= ~ ( V_65 | V_66 |
V_67 ) ;
F_3 ( V_2 , V_68 , V_5 , V_10 ) ;
}
}
static int F_37 ( struct V_71 * V_72 ,
struct V_1 * V_2 )
{
V_2 -> V_58 = F_38 ( NULL , V_2 -> V_40 ,
& V_73 , V_2 ) ;
if ( ! V_2 -> V_58 )
return - V_74 ;
V_2 -> V_75 = F_39 ( F_40 ( V_72 ) ,
& V_76 ,
V_2 -> V_58 ) ;
if ( ! V_2 -> V_75 ) {
F_41 ( V_2 -> V_58 ) ;
return - V_74 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_75 )
F_41 ( V_2 -> V_75 ) ;
if ( V_2 -> V_58 )
F_41 ( V_2 -> V_58 ) ;
}
static void F_43 ( struct V_1 * V_2 , unsigned int V_77 )
{
int V_59 ;
for ( V_59 = V_77 ; V_59 < V_2 -> V_12 ; V_59 += V_2 -> V_18 ) {
F_44 ( V_2 -> V_78 [ V_59 ] . V_79 ,
NULL , NULL ) ;
}
}
static int F_45 ( struct V_1 * V_2 , unsigned int V_77 )
{
int V_59 , V_80 ;
T_4 V_22 ;
struct V_6 * V_7 = V_2 -> V_7 ;
for ( V_59 = V_77 ; V_59 < V_2 -> V_12 ; V_59 += V_2 -> V_18 ) {
F_44 ( V_2 -> V_78 [ V_59 ] . V_79 ,
F_27 ,
& V_2 -> V_78 [ V_59 ] ) ;
if ( F_46 ( & V_22 , V_81 ) ) {
F_47 ( V_22 ) ;
F_48 ( V_77 , V_22 ) ;
V_80 = F_49 ( V_2 -> V_78 [ V_59 ] . V_79 , V_22 ) ;
if ( V_80 )
F_50 ( V_7 -> V_82 ,
L_1 ,
V_2 -> V_78 [ V_59 ] . V_79 ) ;
F_51 ( V_22 ) ;
} else {
F_50 ( V_7 -> V_82 , L_2 ) ;
V_80 = - V_83 ;
}
if ( V_80 ) {
F_43 ( V_2 , V_77 ) ;
return V_80 ;
}
}
return 0 ;
}
int F_52 ( struct V_6 * V_7 , struct V_71 * V_72 )
{
struct V_1 * V_2 ;
int V_59 , V_80 ;
unsigned int V_77 ;
if ( ! F_53 ( V_72 , L_3 ) )
return - V_84 ;
if ( ! F_54 ( V_72 , L_4 , NULL ) )
return - V_84 ;
if ( V_7 -> V_2 )
return - V_85 ;
V_2 = F_55 ( V_7 -> V_82 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_2 = V_2 ;
V_2 -> V_31 = V_7 -> V_86 ;
F_56 ( & V_2 -> V_38 ) ;
V_2 -> V_18 = F_57 () ;
V_2 -> V_12 = F_58 ( V_72 ) ;
if ( ! V_2 -> V_12 ) {
F_50 ( V_7 -> V_82 , L_5 ) ;
return - V_84 ;
}
if ( V_2 -> V_12 > V_87 ) {
F_59 ( V_7 -> V_82 , L_6 ,
V_2 -> V_12 ) ;
V_2 -> V_12 = V_87 ;
}
if ( V_2 -> V_12 < V_2 -> V_18 ) {
F_50 ( V_7 -> V_82 ,
L_7 ) ;
return - V_83 ;
}
if ( V_2 -> V_12 % V_2 -> V_18 != 0 ) {
V_2 -> V_12 -= V_2 -> V_12 % V_2 -> V_18 ;
F_59 ( V_7 -> V_82 , L_8 ,
V_2 -> V_12 ) ;
}
switch ( V_7 -> type ) {
case V_88 :
case V_89 :
V_2 -> V_9 = V_90 ;
V_2 -> V_15 = 1 ;
V_2 -> V_13 = 1 ;
break;
case V_91 :
V_2 -> V_9 = V_92 ;
V_2 -> V_15 = V_2 -> V_12 ;
V_2 -> V_13 = V_2 -> V_12 ;
break;
default:
F_50 ( V_7 -> V_82 , L_9 ) ;
return - V_83 ;
}
if ( F_54 ( V_72 , L_10 , NULL ) )
V_2 -> V_69 = true ;
V_2 -> V_40 = V_2 -> V_12 * V_17 ;
V_2 -> V_39 = F_60 ( V_7 -> V_82 , F_61 ( V_2 -> V_40 ) ,
sizeof( * V_2 -> V_39 ) , V_81 ) ;
if ( ! V_2 -> V_39 )
return - V_74 ;
V_2 -> V_78 = F_60 ( V_7 -> V_82 , V_2 -> V_12 , sizeof( * V_2 -> V_78 ) ,
V_81 ) ;
if ( ! V_2 -> V_78 )
return - V_74 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_12 ; V_59 ++ ) {
unsigned int V_93 = F_62 ( V_72 , V_59 ) ;
if ( ! V_93 ) {
F_50 ( V_7 -> V_82 , L_11 ) ;
V_80 = - V_84 ;
goto V_94;
}
V_2 -> V_78 [ V_59 ] . V_79 = V_93 ;
V_2 -> V_78 [ V_59 ] . V_2 = V_2 ;
V_2 -> V_78 [ V_59 ] . V_5 = V_59 ;
}
V_2 -> V_46 = F_63 ( V_7 -> V_82 ,
V_2 -> V_15 * V_16 ,
& V_2 -> V_60 , V_81 ) ;
if ( ! V_2 -> V_46 ) {
V_80 = - V_74 ;
goto V_94;
}
V_80 = F_37 ( V_72 , V_2 ) ;
if ( V_80 ) {
F_50 ( V_7 -> V_82 , L_12 ) ;
goto V_95;
}
F_64 (cpu) {
V_80 = F_45 ( V_2 , V_77 ) ;
if ( V_80 )
goto V_96;
}
F_34 ( V_2 ) ;
return 0 ;
V_96:
F_64 (cpu)
F_43 ( V_2 , V_77 ) ;
F_42 ( V_2 ) ;
V_95:
F_65 ( V_7 -> V_82 , V_2 -> V_15 * V_16 ,
V_2 -> V_46 , V_2 -> V_60 ) ;
V_94:
for ( V_59 = 0 ; V_59 < V_2 -> V_12 ; V_59 ++ ) {
if ( V_2 -> V_78 [ V_59 ] . V_79 )
F_66 ( V_2 -> V_78 [ V_59 ] . V_79 ) ;
}
V_7 -> V_2 = NULL ;
return V_80 ;
}
void F_67 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
unsigned int V_59 , V_77 ;
if ( ! V_2 )
return;
F_36 ( V_2 ) ;
F_64 (cpu)
F_43 ( V_2 , V_77 ) ;
F_42 ( V_2 ) ;
F_65 ( V_7 -> V_82 , V_2 -> V_15 * V_16 ,
V_2 -> V_46 , V_2 -> V_60 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_12 ; V_59 ++ ) {
if ( V_2 -> V_78 [ V_59 ] . V_79 )
F_66 ( V_2 -> V_78 [ V_59 ] . V_79 ) ;
}
}
