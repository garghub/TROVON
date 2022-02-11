void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , void * V_5 ,
void (* F_2)( void * V_5 , void * V_6 ,
T_1 V_7 ) )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_4 ] ;
V_9 -> F_2 = F_2 ;
V_9 -> V_5 = V_5 ;
V_9 -> V_10 = V_11 ;
}
void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_8 * V_9 = & V_2 -> V_9 [ V_4 ] ;
V_9 -> V_10 &= ~ V_11 ;
while ( V_9 -> V_10 & V_12 )
F_4 () ;
V_9 -> F_2 = NULL ;
}
void F_5 ( struct V_13 * V_14 ,
enum V_15 V_4 , void * V_5 ,
void (* F_6)( void * V_5 , T_2 V_16 ) )
{
struct V_17 * V_18 = & V_14 -> V_18 [ V_4 ] ;
V_18 -> F_6 = F_6 ;
V_18 -> V_5 = V_5 ;
V_18 -> V_19 = V_11 ;
}
void F_7 ( struct V_13 * V_14 ,
enum V_15 V_4 )
{
struct V_17 * V_18 = & V_14 -> V_18 [ V_4 ] ;
V_18 -> V_19 &= ~ V_11 ;
while ( V_18 -> V_19 & V_12 )
F_4 () ;
V_18 -> F_6 = NULL ;
}
static T_1 F_8 ( T_2 V_20 )
{
T_1 V_21 = 0 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < 32 ; V_22 += 4 )
V_21 ^= ( ( V_20 >> V_22 ) & 0xF ) ;
return ( V_21 & 0xF ) ;
}
static void F_9 ( struct V_23 * V_24 )
{
T_2 V_20 , V_25 = F_10 ( V_24 ) ;
V_20 = F_11 ( V_24 -> V_26 , V_25 ) ;
V_20 = F_12 ( V_20 , V_27 ) &
F_12 ( V_20 , V_28 ) &
F_12 ( V_20 , V_29 ) &
F_12 ( V_20 , V_30 ) ;
V_20 |= F_13 ( V_24 -> V_31 , V_27 ) |
F_13 ( V_24 -> V_32 , V_28 ) |
F_13 ( V_33 , V_29 ) ;
V_20 |= F_13 ( F_8 ( V_20 ) , V_30 ) ;
F_14 ( V_24 -> V_26 , V_25 , V_20 ) ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_16 ( V_24 ) ;
struct V_34 * V_26 = V_2 -> V_26 ;
struct V_35 * V_36 = V_26 -> V_36 ;
struct V_37 * V_38 ;
struct V_8 * V_9 ;
enum V_3 V_4 ;
unsigned long V_39 ;
T_2 V_40 ;
int V_41 , V_7 ;
for ( V_41 = 0 ; V_41 < V_24 -> V_42 ; V_41 ++ ) {
V_38 = F_17 ( V_24 ) ;
V_40 = F_18 ( V_38 -> V_43 ) ;
if ( F_19 ( V_40 , V_28 ) == V_24 -> V_32 )
break;
V_4 = F_19 ( V_40 , TYPE ) ;
if ( V_4 >= V_44 ) {
F_20 ( & V_36 -> V_45 , L_1 , V_4 ) ;
return;
}
if ( ! F_19 ( V_40 , V_46 ) ) {
V_9 = & V_2 -> V_9 [ V_4 ] ;
V_7 = F_19 ( V_40 , V_47 ) ;
V_39 = F_21 ( & V_9 -> V_10 ,
V_11 ,
V_11 |
V_12 ) ;
if ( ( V_39 == V_11 ) &&
( V_9 -> F_2 ) )
V_9 -> F_2 ( V_9 -> V_5 ,
V_38 -> V_6 , V_7 ) ;
else
F_20 ( & V_36 -> V_45 , L_2 ,
V_4 ) ;
V_9 -> V_10 &= ~ V_12 ;
}
V_24 -> V_31 ++ ;
if ( V_24 -> V_31 == V_24 -> V_42 ) {
V_24 -> V_31 = 0 ;
V_24 -> V_32 = ! V_24 -> V_32 ;
}
}
}
static void F_22 ( struct V_13 * V_14 , T_2 V_48 )
{
struct V_34 * V_26 = V_14 -> V_26 ;
struct V_35 * V_36 = V_26 -> V_36 ;
struct V_17 * V_18 ;
enum V_15 V_4 ;
unsigned long V_39 ;
V_4 = F_23 ( V_48 ) ;
if ( V_4 >= V_49 ) {
F_20 ( & V_36 -> V_45 , L_3 , V_4 ) ;
return;
}
V_18 = & V_14 -> V_18 [ V_4 ] ;
V_39 = F_21 ( & V_18 -> V_19 ,
V_11 ,
V_11 | V_12 ) ;
if ( ( V_39 == V_11 ) && ( V_18 -> F_6 ) )
V_18 -> F_6 ( V_18 -> V_5 , F_24 ( V_48 ) ) ;
else
F_20 ( & V_36 -> V_45 , L_4 , V_4 ) ;
V_18 -> V_19 &= ~ V_12 ;
}
static void F_25 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = F_26 ( V_24 ) ;
T_2 V_48 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_24 -> V_42 ; V_41 ++ ) {
V_48 = * ( F_27 ( V_24 ) ) ;
V_48 = F_18 ( V_48 ) ;
if ( F_19 ( V_48 , V_28 ) == V_24 -> V_32 )
break;
F_22 ( V_14 , V_48 ) ;
V_24 -> V_31 ++ ;
if ( V_24 -> V_31 == V_24 -> V_42 ) {
V_24 -> V_31 = 0 ;
V_24 -> V_32 = ! V_24 -> V_32 ;
}
}
}
static void F_28 ( void * V_6 )
{
struct V_23 * V_24 = V_6 ;
if ( V_24 -> type == V_50 )
F_15 ( V_24 ) ;
else if ( V_24 -> type == V_51 )
F_25 ( V_24 ) ;
F_9 ( V_24 ) ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = F_30 ( V_53 ) ;
struct V_23 * V_56 ;
V_56 = V_55 -> V_6 ;
F_28 ( V_56 ) ;
}
static void F_31 ( unsigned long V_57 )
{
struct V_23 * V_58 = (struct V_23 * ) V_57 ;
F_28 ( V_58 ) ;
}
static T_3 F_32 ( int V_59 , void * V_6 )
{
struct V_54 * V_55 ;
struct V_23 * V_56 = V_6 ;
struct V_1 * V_2 ;
F_33 ( V_56 -> V_26 , V_56 -> V_60 . V_61 ) ;
V_55 = & V_56 -> V_55 ;
V_55 -> V_6 = V_56 ;
V_2 = F_16 ( V_56 ) ;
F_34 ( V_2 -> V_62 , & V_55 -> V_53 ) ;
return V_63 ;
}
static T_3 F_35 ( int V_59 , void * V_6 )
{
struct V_23 * V_58 = V_6 ;
F_33 ( V_58 -> V_26 , V_58 -> V_60 . V_61 ) ;
F_36 ( & V_58 -> F_31 ) ;
return V_63 ;
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_60 * V_60 = & V_24 -> V_60 ;
enum V_64 type = V_24 -> type ;
T_2 V_25 , V_20 , V_65 ;
if ( type == V_50 ) {
V_25 = F_38 ( V_24 -> V_66 ) ;
V_20 = F_11 ( V_24 -> V_26 , V_25 ) ;
V_20 = F_39 ( V_20 , V_67 ) &
F_39 ( V_20 , V_68 ) &
F_39 ( V_20 , V_69 ) &
F_39 ( V_20 , V_70 ) ;
V_65 = F_40 ( V_60 -> V_61 , V_67 ) |
F_40 ( V_71 , V_68 ) |
F_40 ( F_41 ( V_24 -> V_26 ) ,
V_69 ) |
F_40 ( V_72 , V_70 ) ;
V_20 |= V_65 ;
F_14 ( V_24 -> V_26 , V_25 , V_20 ) ;
} else if ( type == V_51 ) {
V_25 = F_42 ( V_24 -> V_66 ) ;
V_20 = F_11 ( V_24 -> V_26 , V_25 ) ;
V_20 = F_43 ( V_20 , V_73 ) &
F_43 ( V_20 , V_68 ) &
F_43 ( V_20 , V_74 ) &
F_43 ( V_20 , V_69 ) &
F_43 ( V_20 , V_75 ) ;
V_65 = F_44 ( V_60 -> V_61 , V_73 ) |
F_44 ( V_76 , V_68 ) |
F_44 ( V_77 , V_74 ) |
F_44 ( F_41 ( V_24 -> V_26 ) ,
V_69 ) |
F_44 ( V_72 , V_75 ) ;
V_20 |= V_65 ;
F_14 ( V_24 -> V_26 , V_25 , V_20 ) ;
}
}
static void F_45 ( struct V_23 * V_24 )
{
enum V_64 type = V_24 -> type ;
T_2 V_78 , V_79 ;
T_2 V_25 , V_20 , V_80 ;
if ( type == V_50 ) {
V_25 = F_46 ( V_24 -> V_66 ) ;
V_78 = F_47 ( V_24 ) ;
V_79 = F_48 ( V_24 ) ;
V_20 = F_11 ( V_24 -> V_26 , V_25 ) ;
V_20 = F_49 ( V_20 , V_81 ) &
F_49 ( V_20 , V_82 ) &
F_49 ( V_20 , V_83 ) ;
V_80 = F_50 ( V_24 -> V_42 , V_81 ) |
F_50 ( V_79 , V_82 ) |
F_50 ( V_78 , V_83 ) ;
V_20 |= V_80 ;
F_14 ( V_24 -> V_26 , V_25 , V_20 ) ;
} else if ( type == V_51 ) {
V_25 = F_51 ( V_24 -> V_66 ) ;
V_78 = F_47 ( V_24 ) ;
V_20 = F_11 ( V_24 -> V_26 , V_25 ) ;
V_20 = F_52 ( V_20 , V_81 ) &
F_52 ( V_20 , V_83 ) ;
V_80 = F_53 ( V_24 -> V_42 , V_81 ) |
F_53 ( V_78 , V_83 ) ;
V_20 |= V_80 ;
F_14 ( V_24 -> V_26 , V_25 , V_20 ) ;
}
}
static void F_54 ( struct V_23 * V_24 )
{
F_37 ( V_24 ) ;
F_45 ( V_24 ) ;
}
static void F_55 ( struct V_23 * V_24 , T_2 V_84 )
{
struct V_37 * V_85 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_24 -> V_42 ; V_41 ++ ) {
V_85 = F_56 ( V_24 , V_41 ) ;
V_85 -> V_43 = F_57 ( V_84 ) ;
}
F_58 () ;
}
static void F_59 ( struct V_23 * V_24 , T_2 V_84 )
{
T_2 * V_48 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_24 -> V_42 ; V_41 ++ ) {
V_48 = F_60 ( V_24 , V_41 ) ;
* ( V_48 ) = F_57 ( V_84 ) ;
}
F_58 () ;
}
static int F_61 ( struct V_23 * V_24 )
{
struct V_34 * V_26 = V_24 -> V_26 ;
struct V_35 * V_36 = V_26 -> V_36 ;
T_2 V_84 , V_25 , V_20 ;
T_4 V_86 ;
int V_87 , V_88 ;
V_86 = V_24 -> V_89 * sizeof( * V_24 -> V_90 ) ;
V_24 -> V_90 = F_62 ( & V_36 -> V_45 , V_86 , V_91 ) ;
if ( ! V_24 -> V_90 )
return - V_92 ;
V_86 = V_24 -> V_89 * sizeof( * V_24 -> V_93 ) ;
V_24 -> V_93 = F_62 ( & V_36 -> V_45 , V_86 , V_91 ) ;
if ( ! V_24 -> V_93 ) {
V_87 = - V_92 ;
goto V_94;
}
for ( V_88 = 0 ; V_88 < V_24 -> V_89 ; V_88 ++ ) {
V_24 -> V_93 [ V_88 ] = F_63 ( & V_36 -> V_45 ,
V_24 -> V_95 ,
& V_24 -> V_90 [ V_88 ] ,
V_91 ) ;
if ( ! V_24 -> V_93 [ V_88 ] ) {
V_87 = - V_92 ;
goto V_96;
}
V_25 = F_64 ( V_24 , V_88 ) ;
V_20 = F_65 ( V_24 -> V_90 [ V_88 ] ) ;
F_14 ( V_26 , V_25 , V_20 ) ;
V_25 = F_66 ( V_24 , V_88 ) ;
V_20 = F_67 ( V_24 -> V_90 [ V_88 ] ) ;
F_14 ( V_26 , V_25 , V_20 ) ;
}
V_84 = F_68 ( V_24 -> V_32 , V_28 ) ;
if ( V_24 -> type == V_50 )
F_55 ( V_24 , V_84 ) ;
else if ( V_24 -> type == V_51 )
F_59 ( V_24 , V_84 ) ;
return 0 ;
V_96:
while ( -- V_88 >= 0 )
F_69 ( & V_36 -> V_45 , V_24 -> V_95 ,
V_24 -> V_93 [ V_88 ] ,
V_24 -> V_90 [ V_88 ] ) ;
F_70 ( & V_36 -> V_45 , V_24 -> V_93 ) ;
V_94:
F_70 ( & V_36 -> V_45 , V_24 -> V_90 ) ;
return V_87 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_34 * V_26 = V_24 -> V_26 ;
struct V_35 * V_36 = V_26 -> V_36 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_24 -> V_89 ; V_88 ++ )
F_69 ( & V_36 -> V_45 , V_24 -> V_95 ,
V_24 -> V_93 [ V_88 ] ,
V_24 -> V_90 [ V_88 ] ) ;
F_70 ( & V_36 -> V_45 , V_24 -> V_93 ) ;
F_70 ( & V_36 -> V_45 , V_24 -> V_90 ) ;
}
static int F_72 ( struct V_23 * V_24 , struct V_34 * V_26 ,
enum V_64 type , int V_66 , T_2 V_42 , T_2 V_95 ,
struct V_60 V_61 )
{
struct V_35 * V_36 = V_26 -> V_36 ;
int V_87 ;
V_24 -> V_26 = V_26 ;
V_24 -> type = type ;
V_24 -> V_66 = V_66 ;
V_24 -> V_42 = V_42 ;
V_24 -> V_95 = V_95 ;
F_14 ( V_24 -> V_26 , F_10 ( V_24 ) , 0 ) ;
F_14 ( V_24 -> V_26 , F_73 ( V_24 ) , 0 ) ;
V_24 -> V_31 = 0 ;
V_24 -> V_32 = 0 ;
if ( type == V_50 ) {
V_24 -> V_79 = V_97 ;
} else if ( type == V_51 ) {
V_24 -> V_79 = V_98 ;
} else {
F_20 ( & V_36 -> V_45 , L_5 ) ;
return - V_99 ;
}
V_24 -> V_89 = F_74 ( V_24 , V_95 ) ;
V_24 -> V_100 = F_75 ( V_24 , V_95 ) ;
V_24 -> V_60 = V_61 ;
if ( V_24 -> V_100 & ( V_24 -> V_100 - 1 ) ) {
F_20 ( & V_36 -> V_45 , L_6 ) ;
return - V_99 ;
}
if ( V_24 -> V_89 > V_101 ) {
F_20 ( & V_36 -> V_45 , L_7 ) ;
return - V_99 ;
}
F_54 ( V_24 ) ;
F_9 ( V_24 ) ;
V_87 = F_61 ( V_24 ) ;
if ( V_87 ) {
F_20 ( & V_36 -> V_45 , L_8 ) ;
return V_87 ;
}
if ( type == V_50 ) {
struct V_54 * V_55 = & V_24 -> V_55 ;
F_76 ( & V_55 -> V_53 , F_29 ) ;
} else if ( type == V_51 ) {
F_77 ( & V_24 -> F_31 , F_31 ,
( unsigned long ) V_24 ) ;
}
F_78 ( V_24 -> V_26 , V_24 -> V_60 . V_61 ,
V_102 ,
V_103 ,
V_104 ,
V_105 ,
V_106 ) ;
if ( type == V_50 )
V_87 = F_79 ( V_61 . V_107 , F_32 , 0 ,
L_9 , V_24 ) ;
else if ( type == V_51 )
V_87 = F_79 ( V_61 . V_107 , F_35 , 0 ,
L_10 , V_24 ) ;
if ( V_87 ) {
F_20 ( & V_36 -> V_45 , L_11 ) ;
goto V_108;
}
return 0 ;
V_108:
F_71 ( V_24 ) ;
return V_87 ;
}
static void F_80 ( struct V_23 * V_24 )
{
struct V_60 * V_61 = & V_24 -> V_60 ;
F_81 ( V_61 -> V_107 , V_24 ) ;
if ( V_24 -> type == V_50 ) {
struct V_54 * V_55 = & V_24 -> V_55 ;
F_82 ( & V_55 -> V_53 ) ;
} else if ( V_24 -> type == V_51 ) {
F_83 ( & V_24 -> F_31 ) ;
}
F_71 ( V_24 ) ;
}
int F_84 ( struct V_1 * V_2 , struct V_34 * V_26 ,
int V_109 , T_2 V_42 , T_2 V_95 ,
struct V_60 * V_110 )
{
struct V_35 * V_36 = V_26 -> V_36 ;
int V_87 , V_41 , V_66 ;
V_2 -> V_62 = F_85 ( V_111 ) ;
if ( ! V_2 -> V_62 )
return - V_92 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_109 = V_109 ;
for ( V_66 = 0 ; V_66 < V_109 ; V_66 ++ ) {
V_87 = F_72 ( & V_2 -> V_56 [ V_66 ] , V_26 , V_50 , V_66 , V_42 ,
V_95 , V_110 [ V_66 ] ) ;
if ( V_87 ) {
F_20 ( & V_36 -> V_45 , L_12 , V_66 ) ;
goto V_112;
}
}
return 0 ;
V_112:
for ( V_41 = 0 ; V_41 < V_66 ; V_41 ++ )
F_80 ( & V_2 -> V_56 [ V_41 ] ) ;
F_86 ( V_2 -> V_62 ) ;
return V_87 ;
}
void F_87 ( struct V_1 * V_2 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_2 -> V_109 ; V_66 ++ )
F_80 ( & V_2 -> V_56 [ V_66 ] ) ;
F_86 ( V_2 -> V_62 ) ;
}
int F_88 ( struct V_13 * V_14 , struct V_34 * V_26 ,
int V_113 , T_2 V_42 , T_2 V_95 ,
struct V_60 * V_110 )
{
struct V_35 * V_36 = V_26 -> V_36 ;
int V_41 , V_66 , V_87 ;
V_14 -> V_26 = V_26 ;
V_14 -> V_113 = V_113 ;
for ( V_66 = 0 ; V_66 < V_113 ; V_66 ++ ) {
V_87 = F_72 ( & V_14 -> V_58 [ V_66 ] , V_26 , V_51 , V_66 , V_42 ,
V_95 , V_110 [ V_66 ] ) ;
if ( V_87 ) {
F_20 ( & V_36 -> V_45 , L_13 , V_66 ) ;
goto V_114;
}
}
return 0 ;
V_114:
for ( V_41 = 0 ; V_41 < V_66 ; V_41 ++ )
F_80 ( & V_14 -> V_58 [ V_41 ] ) ;
return V_87 ;
}
void F_89 ( struct V_13 * V_14 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_14 -> V_113 ; V_66 ++ )
F_80 ( & V_14 -> V_58 [ V_66 ] ) ;
}
