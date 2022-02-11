void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_2 -> V_6 += F_2 ( V_2 ) ;
V_2 -> V_7 = V_2 -> V_8 ;
F_3 ( V_2 -> V_6 , V_4 -> V_9 + V_10 ) ;
F_4 ( F_5 ( V_4 ) ,
L_1 ,
V_11 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 , V_2 -> V_6 ) ;
}
void F_6 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
if ( F_2 ( V_2 ) ) {
F_8 ( & V_2 -> V_15 ) ;
F_1 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) > V_16 )
F_1 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
if ( F_12 ( V_2 ) < 1 ) {
F_13 ( F_5 ( & V_2 -> V_5 ) ,
L_2 ) ;
return;
}
F_4 ( F_5 ( & V_2 -> V_5 ) , L_3 ,
V_11 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
V_18 = F_14 ( V_2 , V_2 -> V_8 ) ;
V_20 = V_18 -> V_20 ;
V_20 -> V_21 = 0 ;
V_20 -> V_22 . null = 1 ;
V_20 -> V_22 . V_23 = 1 ;
V_20 -> V_22 . V_24 = 1 ;
V_20 -> V_25 = V_26 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 = 0 ;
F_15 ( & V_18 -> V_29 ) ;
F_16 ( V_2 , V_18 -> V_29 . V_30 ) ;
F_17 ( V_2 , V_18 ) ;
F_18 () ;
V_2 -> V_8 += 1 ;
F_1 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_15 ) ;
F_11 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_32 * V_33 ;
struct V_17 * V_18 ;
bool V_34 = false ;
T_2 V_35 ;
int V_36 = V_2 -> V_12 , V_37 ;
F_4 ( F_5 ( V_4 ) , L_3 ,
V_11 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
V_35 = F_21 ( V_2 ) ;
for ( V_37 = 0 ; V_37 < V_35 && ! V_34 ; V_37 ++ ) {
F_22 () ;
F_23 ( F_14 ( V_2 , V_36 + V_37 + 1 ) ) ;
V_18 = F_14 ( V_2 , V_36 + V_37 ) ;
V_33 = & V_18 -> V_29 ;
F_17 ( V_2 , V_18 ) ;
if ( V_33 -> V_38 ) {
F_24 ( V_4 , V_33 -> V_39 , V_18 -> V_40 , V_18 -> V_20 ) ;
F_25 ( V_33 ) ;
if ( V_33 -> V_41 ) {
V_33 -> V_41 ( V_33 -> V_42 ) ;
V_33 -> V_41 = NULL ;
}
}
if ( V_33 -> V_30 == V_31 )
V_34 = true ;
}
F_26 () ;
V_2 -> V_12 = V_36 + V_37 ;
F_27 ( V_35 && ! V_34 ) ;
V_4 -> V_43 = V_31 ;
if ( V_35 - V_37 == 0 ) {
F_4 ( F_5 ( V_4 ) , L_4 ,
V_11 ) ;
F_28 ( V_44 , & V_4 -> V_45 ) ;
F_29 ( & V_4 -> V_46 , V_47 + V_48 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_31 ;
F_8 ( & V_4 -> V_49 ) ;
if ( F_31 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_9 ( & V_4 -> V_49 ) ;
}
void F_32 ( unsigned long V_50 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_50 ) ;
F_30 ( V_2 ) ;
F_3 ( V_51 , V_2 -> V_5 . V_9 + V_52 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_2 -> V_7 = V_2 -> V_12 ;
V_2 -> V_6 = 0 ;
F_34 ( V_44 , & V_4 -> V_45 ) ;
F_29 ( & V_4 -> V_46 , V_47 + V_53 ) ;
F_4 ( F_5 ( V_4 ) ,
L_1 ,
V_11 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 , V_2 -> V_6 ) ;
if ( F_2 ( V_2 ) ) {
struct V_17 * V_18 ;
V_18 = F_14 ( V_2 , V_2 -> V_12 ) ;
F_16 ( V_2 , V_18 -> V_29 . V_30 ) ;
F_1 ( V_2 ) ;
} else
F_11 ( V_2 ) ;
}
int F_35 ( struct V_3 * V_4 , unsigned long V_54 )
{
unsigned long V_55 = V_47 + V_54 ;
int V_56 = 0 ;
T_3 V_57 ;
V_57 = F_36 ( V_4 ) ;
if ( F_37 ( V_57 ) || F_38 ( V_57 ) )
F_39 ( V_4 ) ;
while ( F_37 ( V_57 ) || F_38 ( V_57 ) ) {
if ( V_54 && F_40 ( V_47 , V_55 ) ) {
V_56 = - V_58 ;
break;
}
V_57 = F_36 ( V_4 ) ;
F_41 () ;
}
return V_56 ;
}
int F_42 ( struct V_3 * V_4 , unsigned long V_54 )
{
unsigned long V_55 = V_47 + V_54 ;
int V_56 = 0 ;
F_43 ( V_4 ) ;
while ( F_44 ( V_4 ) ) {
if ( V_55 && F_40 ( V_47 , V_55 ) ) {
V_56 = - V_58 ;
break;
}
F_41 () ;
}
return V_56 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_31 ;
F_35 ( V_4 , 0 ) ;
if ( F_31 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_33 ( V_2 ) ;
}
void F_46 ( unsigned long V_50 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_50 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_47 ( V_44 , & V_4 -> V_45 ) ) {
T_1 V_31 ;
T_4 V_57 ;
V_57 = F_36 ( V_4 ) ;
if ( F_48 ( V_57 ) ) {
T_3 V_59 ;
V_59 = F_49 ( V_4 -> V_9 + V_60 ) ;
F_13 ( F_5 ( V_4 ) , L_5 ,
V_11 , V_59 ) ;
if ( F_47 ( V_61 , & V_4 -> V_45 ) )
F_27 ( F_50 ( V_59 ) ) ;
else
return;
}
F_8 ( & V_4 -> V_49 ) ;
if ( F_31 ( V_4 , & V_31 ) ) {
F_20 ( V_2 , V_31 ) ;
} else if ( F_47 ( V_62 , & V_4 -> V_45 ) ) {
F_8 ( & V_2 -> V_15 ) ;
F_45 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
} else {
F_34 ( V_62 , & V_4 -> V_45 ) ;
F_29 ( & V_4 -> V_46 , V_47 + V_53 ) ;
}
F_9 ( & V_4 -> V_49 ) ;
} else {
T_2 V_35 ;
F_8 ( & V_4 -> V_49 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_35 = F_21 ( V_2 ) ;
if ( V_35 == 0 && V_2 -> V_63 > F_51 () )
F_52 ( V_2 , V_2 -> V_63 - 1 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_49 ) ;
if ( V_2 -> V_63 > F_51 () )
F_29 ( & V_4 -> V_46 , V_47 + V_48 ) ;
}
}
static int F_53 ( struct V_3 * V_4 )
{
T_3 V_59 ;
F_35 ( V_4 , F_54 ( 100 ) ) ;
V_59 = F_49 ( V_4 -> V_9 + V_60 ) ;
F_55 ( V_59 , V_4 -> V_9 + V_60 ) ;
return F_42 ( V_4 , F_54 ( 200 ) ) ;
}
int F_56 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 = & V_65 -> V_67 -> V_66 ;
struct V_68 * V_69 = & V_65 -> V_70 ;
T_5 V_71 ;
int V_37 ;
F_57 ( & V_69 -> V_72 ) ;
V_69 -> V_73 = F_58 ( V_65 -> V_9 + V_74 ) ;
V_69 -> V_73 &= 0x1f ;
if ( V_69 -> V_73 > F_59 ( V_65 -> V_36 ) ) {
F_60 ( V_66 , L_6 ,
V_69 -> V_73 , F_59 ( V_65 -> V_36 ) ) ;
V_69 -> V_73 = F_59 ( V_65 -> V_36 ) ;
}
V_71 = F_58 ( V_65 -> V_9 + V_75 ) ;
V_71 &= 0x1f ;
if ( V_71 == 0 )
return 0 ;
F_4 ( V_66 , L_7 , V_11 , 1 << V_71 ) ;
#ifdef F_61
if ( F_62 ( NULL , NULL , 1 ) == 0 )
V_69 -> V_73 -- ;
#endif
for ( V_37 = 0 ; V_37 < V_69 -> V_73 ; V_37 ++ ) {
V_2 = F_63 ( V_66 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
break;
F_64 ( V_65 , & V_2 -> V_5 , V_37 ) ;
V_2 -> V_71 = V_71 ;
F_65 ( & V_2 -> V_15 ) ;
if ( V_65 -> V_77 ( & V_2 -> V_5 ) ) {
V_37 = 0 ;
break;
}
}
V_69 -> V_73 = V_37 ;
return V_37 ;
}
static T_6 F_66 ( struct V_32 * V_33 )
{
struct V_13 * V_14 = V_33 -> V_4 ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_6 V_38 ;
V_38 = F_67 ( V_33 ) ;
F_4 ( F_5 ( & V_2 -> V_5 ) , L_8 , V_11 , V_38 ) ;
if ( ! F_68 ( V_44 , & V_4 -> V_45 ) )
F_29 ( & V_4 -> V_46 , V_47 + V_53 ) ;
F_18 () ;
V_2 -> V_8 += V_2 -> V_78 ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
return V_38 ;
}
static struct V_17 * F_69 ( struct V_13 * V_4 , T_7 V_39 )
{
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_64 * V_69 ;
T_1 V_30 ;
V_69 = F_70 ( V_4 -> V_65 ) ;
V_20 = F_71 ( V_69 -> V_79 , V_39 , & V_30 ) ;
if ( ! V_20 )
return NULL ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_18 = F_72 ( V_80 , V_39 ) ;
if ( ! V_18 ) {
F_73 ( V_69 -> V_79 , V_20 , V_30 ) ;
return NULL ;
}
F_74 ( & V_18 -> V_29 , V_4 ) ;
V_18 -> V_29 . V_81 = F_66 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_29 . V_30 = V_30 ;
return V_18 ;
}
static void F_75 ( struct V_17 * V_18 , struct V_13 * V_4 )
{
struct V_64 * V_69 ;
V_69 = F_70 ( V_4 -> V_65 ) ;
F_73 ( V_69 -> V_79 , V_18 -> V_20 , V_18 -> V_29 . V_30 ) ;
F_76 ( V_80 , V_18 ) ;
}
static struct V_17 * * F_77 ( struct V_13 * V_14 , int V_82 , T_7 V_39 )
{
struct V_17 * * V_83 ;
int V_84 = 1 << V_82 ;
int V_37 ;
if ( V_82 > F_78 () )
return NULL ;
V_83 = F_79 ( V_84 , sizeof( * V_83 ) , V_39 ) ;
if ( ! V_83 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_84 ; V_37 ++ ) {
V_83 [ V_37 ] = F_69 ( V_14 , V_39 ) ;
if ( ! V_83 [ V_37 ] ) {
while ( V_37 -- )
F_75 ( V_83 [ V_37 ] , V_14 ) ;
F_80 ( V_83 ) ;
return NULL ;
}
F_81 ( V_83 [ V_37 ] , V_37 ) ;
}
for ( V_37 = 0 ; V_37 < V_84 - 1 ; V_37 ++ ) {
struct V_17 * V_85 = V_83 [ V_37 + 1 ] ;
struct V_19 * V_20 = V_83 [ V_37 ] -> V_20 ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
V_83 [ V_37 ] -> V_20 -> V_85 = V_83 [ 0 ] -> V_29 . V_30 ;
return V_83 ;
}
int F_82 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * * V_83 ;
T_4 V_57 ;
int V_82 ;
int V_37 = 0 ;
if ( V_2 -> V_83 )
return 1 << V_2 -> V_63 ;
F_3 ( V_51 , V_4 -> V_9 + V_52 ) ;
V_4 -> V_86 = F_71 ( V_4 -> V_65 -> V_87 ,
V_76 , & V_4 -> V_88 ) ;
if ( ! V_4 -> V_86 )
return - V_89 ;
memset ( V_4 -> V_86 , 0 , sizeof( * V_4 -> V_86 ) ) ;
F_55 ( ( ( T_4 ) V_4 -> V_88 ) & 0x00000000FFFFFFFF ,
V_4 -> V_9 + V_90 ) ;
F_55 ( ( ( T_4 ) V_4 -> V_88 ) >> 32 ,
V_4 -> V_9 + V_91 ) ;
V_82 = F_51 () ;
V_83 = F_77 ( V_14 , V_82 , V_76 ) ;
if ( ! V_83 )
return - V_89 ;
F_8 ( & V_4 -> V_49 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_63 = V_82 ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_49 ) ;
F_83 ( & V_4 -> V_92 ) ;
F_19 ( V_2 ) ;
do {
F_84 ( 1 ) ;
V_57 = F_36 ( V_4 ) ;
} while ( V_37 ++ < 20 && ! F_37 ( V_57 ) && ! F_38 ( V_57 ) );
if ( F_37 ( V_57 ) || F_38 ( V_57 ) ) {
F_34 ( V_61 , & V_4 -> V_45 ) ;
return 1 << V_2 -> V_63 ;
} else {
T_3 V_59 = F_49 ( V_4 -> V_9 + V_60 ) ;
F_85 ( F_5 ( V_4 ) ,
L_9 , V_59 ) ;
F_86 ( V_14 ) ;
return - V_93 ;
}
}
bool F_52 ( struct V_1 * V_2 , int V_82 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & V_4 -> V_70 ;
const T_3 V_94 = F_87 ( V_2 ) ;
const T_2 V_35 = F_21 ( V_2 ) ;
const T_3 V_95 = 1 << V_82 ;
struct V_17 * * V_83 ;
T_2 V_37 ;
if ( V_82 > F_78 () )
return false ;
if ( V_35 == V_94 )
return false ;
if ( V_35 >= V_95 )
return false ;
V_83 = F_79 ( V_95 , sizeof( * V_83 ) , V_96 ) ;
if ( ! V_83 )
return false ;
if ( V_95 > V_94 ) {
for ( V_37 = 0 ; V_37 < V_94 ; V_37 ++ ) {
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
T_2 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
V_83 [ V_98 ] = V_2 -> V_83 [ V_97 ] ;
F_81 ( V_83 [ V_98 ] , V_98 ) ;
}
for ( V_37 = V_94 ; V_37 < V_95 ; V_37 ++ ) {
T_2 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
V_83 [ V_98 ] = F_69 ( V_14 , V_96 ) ;
if ( ! V_83 [ V_98 ] ) {
while ( V_37 -- ) {
T_2 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
F_75 ( V_83 [ V_98 ] , V_14 ) ;
}
F_80 ( V_83 ) ;
return false ;
}
F_81 ( V_83 [ V_98 ] , V_98 ) ;
}
for ( V_37 = V_94 - 1 ; V_37 < V_95 ; V_37 ++ ) {
T_2 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
struct V_17 * V_85 = V_83 [ ( V_98 + 1 ) & ( V_95 - 1 ) ] ;
struct V_19 * V_20 = V_83 [ V_98 ] -> V_20 ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
} else {
struct V_19 * V_20 ;
struct V_17 * V_85 ;
for ( V_37 = 0 ; V_37 < V_95 ; V_37 ++ ) {
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
T_2 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
V_83 [ V_98 ] = V_2 -> V_83 [ V_97 ] ;
F_81 ( V_83 [ V_98 ] , V_98 ) ;
}
for ( V_37 = V_95 ; V_37 < V_94 ; V_37 ++ ) {
struct V_17 * V_99 ;
V_99 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_75 ( V_99 , V_14 ) ;
}
V_20 = V_83 [ ( V_2 -> V_12 + V_95 - 1 ) & ( V_95 - 1 ) ] -> V_20 ;
V_85 = V_83 [ ( V_2 -> V_12 + V_95 ) & ( V_95 - 1 ) ] ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
F_4 ( F_5 ( V_4 ) , L_10 ,
V_11 , V_95 ) ;
F_80 ( V_2 -> V_83 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_63 = V_82 ;
return true ;
}
int F_88 ( struct V_1 * V_2 , int V_100 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
bool V_101 ;
V_101:
F_8 ( & V_2 -> V_15 ) ;
if ( F_89 ( F_12 ( V_2 ) > V_100 ) ) {
F_4 ( F_5 ( V_4 ) , L_11 ,
V_11 , V_100 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
V_2 -> V_78 = V_100 ;
return 0 ;
}
V_101 = F_68 ( V_102 , & V_4 -> V_45 ) ;
F_9 ( & V_2 -> V_15 ) ;
if ( V_101 )
goto V_101;
F_8 ( & V_4 -> V_49 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_101 = F_52 ( V_2 , V_2 -> V_63 + 1 ) ;
F_28 ( V_102 , & V_4 -> V_45 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_49 ) ;
if ( V_101 )
goto V_101;
if ( F_90 () )
F_4 ( F_5 ( V_4 ) , L_12 ,
V_11 , V_100 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
if ( V_47 > V_4 -> V_46 . V_103 && F_91 ( & V_4 -> V_46 ) ) {
struct V_64 * V_65 = V_4 -> V_65 ;
F_29 ( & V_4 -> V_46 , V_47 + V_53 ) ;
V_65 -> V_104 ( ( unsigned long ) & V_4 -> V_70 ) ;
}
return - V_89 ;
}
struct V_32 *
F_92 ( struct V_13 * V_14 , T_1 V_105 ,
T_1 V_106 , T_8 V_40 , unsigned long V_39 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
T_1 V_107 = V_105 ;
T_1 V_108 = V_106 ;
T_8 V_109 = V_40 ;
int V_100 , V_36 , V_37 ;
V_100 = F_93 ( V_2 , V_40 ) ;
if ( F_89 ( V_100 ) && F_88 ( V_2 , V_100 ) == 0 )
V_36 = V_2 -> V_8 ;
else
return NULL ;
V_37 = 0 ;
do {
T_8 V_110 = F_94 ( T_8 , V_40 , 1 << V_2 -> V_71 ) ;
V_18 = F_14 ( V_2 , V_36 + V_37 ) ;
V_20 = V_18 -> V_20 ;
V_20 -> V_25 = V_110 ;
V_20 -> V_21 = 0 ;
V_20 -> V_27 = V_108 ;
V_20 -> V_28 = V_107 ;
V_40 -= V_110 ;
V_107 += V_110 ;
V_108 += V_110 ;
F_17 ( V_2 , V_18 ) ;
} while ( ++ V_37 < V_100 );
V_18 -> V_29 . V_39 = V_39 ;
V_18 -> V_40 = V_109 ;
V_20 -> V_22 . V_23 = ! ! ( V_39 & V_111 ) ;
V_20 -> V_22 . V_112 = ! ! ( V_39 & V_113 ) ;
V_20 -> V_22 . V_24 = 1 ;
F_17 ( V_2 , V_18 ) ;
return & V_18 -> V_29 ;
}
void F_86 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_64 * V_65 = V_4 -> V_65 ;
struct V_17 * V_18 ;
const T_2 V_114 = 1 << V_2 -> V_63 ;
int V_84 ;
int V_37 ;
if ( ! V_2 -> V_83 )
return;
F_95 ( & V_4 -> V_92 ) ;
F_96 ( & V_4 -> V_46 ) ;
V_65 -> V_115 ( ( unsigned long ) V_14 ) ;
V_65 -> V_77 ( V_4 ) ;
F_28 ( V_61 , & V_4 -> V_45 ) ;
F_8 ( & V_4 -> V_49 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_84 = F_12 ( V_2 ) ;
F_4 ( F_5 ( V_4 ) , L_13 , V_84 ) ;
for ( V_37 = 0 ; V_37 < V_84 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_8 + V_37 ) ;
F_75 ( V_18 , V_14 ) ;
}
if ( V_84 < V_114 )
F_13 ( F_5 ( V_4 ) , L_14 ,
V_114 - V_84 ) ;
for ( V_37 = 0 ; V_37 < V_114 - V_84 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_17 ( V_2 , V_18 ) ;
F_75 ( V_18 , V_14 ) ;
}
F_80 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
V_2 -> V_63 = 0 ;
F_73 ( V_65 -> V_87 , V_4 -> V_86 ,
V_4 -> V_88 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_49 ) ;
V_4 -> V_43 = 0 ;
V_4 -> V_88 = 0 ;
V_2 -> V_6 = 0 ;
}
static T_9 F_97 ( struct V_13 * V_14 , char * V_116 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_116 , L_15 , ( 1 << V_2 -> V_63 ) & ~ 1 ) ;
}
static T_9 F_98 ( struct V_13 * V_14 , char * V_116 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_116 , L_15 , F_21 ( V_2 ) ) ;
}
int F_99 ( struct V_64 * V_65 , int V_117 )
{
struct V_118 * V_67 = V_65 -> V_67 ;
struct V_68 * V_69 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_56 ;
V_65 -> V_119 = F_56 ;
V_65 -> V_77 = F_53 ;
V_65 -> V_115 = F_32 ;
V_65 -> V_104 = F_46 ;
V_65 -> V_120 = V_121 ;
V_69 = & V_65 -> V_70 ;
V_69 -> V_122 = F_92 ;
V_69 -> V_123 = F_6 ;
V_69 -> V_124 = F_82 ;
V_69 -> V_125 = F_86 ;
V_69 -> V_126 = V_127 ;
V_56 = F_100 ( V_65 ) ;
if ( V_56 )
return V_56 ;
F_101 ( 2048 ) ;
F_102 (c, &dma->channels, device_node) {
V_4 = F_103 ( V_14 ) ;
F_55 ( V_128 | V_129 ,
V_4 -> V_9 + V_130 ) ;
}
V_56 = F_104 ( V_65 ) ;
if ( V_56 )
return V_56 ;
F_105 ( V_65 , & V_131 ) ;
if ( V_117 )
V_65 -> V_117 = F_106 ( V_67 , V_65 -> V_9 ) ;
return V_56 ;
}
