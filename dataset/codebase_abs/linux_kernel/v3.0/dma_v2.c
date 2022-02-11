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
static void F_20 ( struct V_1 * V_2 , unsigned long V_31 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_32 * V_33 ;
struct V_17 * V_18 ;
bool V_34 = false ;
T_1 V_35 ;
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
V_4 -> V_41 = V_33 -> V_38 ;
V_33 -> V_38 = 0 ;
if ( V_33 -> V_42 ) {
V_33 -> V_42 ( V_33 -> V_43 ) ;
V_33 -> V_42 = NULL ;
}
}
if ( V_33 -> V_30 == V_31 )
V_34 = true ;
}
F_25 () ;
V_2 -> V_12 = V_36 + V_37 ;
F_26 ( V_35 && ! V_34 ) ;
V_4 -> V_44 = V_31 ;
if ( V_35 - V_37 == 0 ) {
F_4 ( F_5 ( V_4 ) , L_4 ,
V_11 ) ;
F_27 ( V_45 , & V_4 -> V_46 ) ;
F_28 ( & V_4 -> V_47 , V_48 + V_49 ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_31 ;
F_8 ( & V_4 -> V_50 ) ;
if ( F_30 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_9 ( & V_4 -> V_50 ) ;
}
void F_31 ( unsigned long V_51 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_51 ) ;
F_29 ( V_2 ) ;
F_3 ( V_52 , V_2 -> V_5 . V_9 + V_53 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_2 -> V_7 = V_2 -> V_12 ;
V_2 -> V_6 = 0 ;
F_33 ( V_45 , & V_4 -> V_46 ) ;
F_28 ( & V_4 -> V_47 , V_48 + V_54 ) ;
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
int F_34 ( struct V_3 * V_4 , unsigned long V_55 )
{
unsigned long V_56 = V_48 + V_55 ;
int V_57 = 0 ;
T_2 V_58 ;
V_58 = F_35 ( V_4 ) ;
if ( F_36 ( V_58 ) || F_37 ( V_58 ) )
F_38 ( V_4 ) ;
while ( F_36 ( V_58 ) || F_37 ( V_58 ) ) {
if ( V_55 && F_39 ( V_48 , V_56 ) ) {
V_57 = - V_59 ;
break;
}
V_58 = F_35 ( V_4 ) ;
F_40 () ;
}
return V_57 ;
}
int F_41 ( struct V_3 * V_4 , unsigned long V_55 )
{
unsigned long V_56 = V_48 + V_55 ;
int V_57 = 0 ;
F_42 ( V_4 ) ;
while ( F_43 ( V_4 ) ) {
if ( V_56 && F_39 ( V_48 , V_56 ) ) {
V_57 = - V_59 ;
break;
}
F_40 () ;
}
return V_57 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
unsigned long V_31 ;
F_34 ( V_4 , 0 ) ;
if ( F_30 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_32 ( V_2 ) ;
}
void F_45 ( unsigned long V_51 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_51 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_46 ( V_45 , & V_4 -> V_46 ) ) {
unsigned long V_31 ;
T_3 V_58 ;
V_58 = F_35 ( V_4 ) ;
if ( F_47 ( V_58 ) ) {
T_2 V_60 ;
V_60 = F_48 ( V_4 -> V_9 + V_61 ) ;
F_13 ( F_5 ( V_4 ) , L_5 ,
V_11 , V_60 ) ;
if ( F_46 ( V_62 , & V_4 -> V_46 ) )
F_26 ( F_49 ( V_60 ) ) ;
else
return;
}
F_8 ( & V_4 -> V_50 ) ;
if ( F_30 ( V_4 , & V_31 ) ) {
F_20 ( V_2 , V_31 ) ;
} else if ( F_46 ( V_63 , & V_4 -> V_46 ) ) {
F_8 ( & V_2 -> V_15 ) ;
F_44 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
} else {
F_33 ( V_63 , & V_4 -> V_46 ) ;
F_28 ( & V_4 -> V_47 , V_48 + V_54 ) ;
}
F_9 ( & V_4 -> V_50 ) ;
} else {
T_1 V_35 ;
F_8 ( & V_4 -> V_50 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_35 = F_21 ( V_2 ) ;
if ( V_35 == 0 && V_2 -> V_64 > F_50 () )
F_51 ( V_2 , V_2 -> V_64 - 1 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_50 ) ;
if ( V_2 -> V_64 > F_50 () )
F_28 ( & V_4 -> V_47 , V_48 + V_49 ) ;
}
}
static int F_52 ( struct V_3 * V_4 )
{
T_2 V_60 ;
F_34 ( V_4 , F_53 ( 100 ) ) ;
V_60 = F_48 ( V_4 -> V_9 + V_61 ) ;
F_54 ( V_60 , V_4 -> V_9 + V_61 ) ;
return F_41 ( V_4 , F_53 ( 200 ) ) ;
}
int F_55 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 = & V_66 -> V_68 -> V_67 ;
struct V_69 * V_70 = & V_66 -> V_71 ;
T_4 V_72 ;
int V_37 ;
F_56 ( & V_70 -> V_73 ) ;
V_70 -> V_74 = F_57 ( V_66 -> V_9 + V_75 ) ;
V_70 -> V_74 &= 0x1f ;
if ( V_70 -> V_74 > F_58 ( V_66 -> V_36 ) ) {
F_59 ( V_67 , L_6 ,
V_70 -> V_74 , F_58 ( V_66 -> V_36 ) ) ;
V_70 -> V_74 = F_58 ( V_66 -> V_36 ) ;
}
V_72 = F_57 ( V_66 -> V_9 + V_76 ) ;
V_72 &= 0x1f ;
if ( V_72 == 0 )
return 0 ;
F_4 ( V_67 , L_7 , V_11 , 1 << V_72 ) ;
#ifdef F_60
if ( F_61 ( NULL , NULL , 1 ) == 0 )
V_70 -> V_74 -- ;
#endif
for ( V_37 = 0 ; V_37 < V_70 -> V_74 ; V_37 ++ ) {
V_2 = F_62 ( V_67 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
break;
F_63 ( V_66 , & V_2 -> V_5 , V_37 ) ;
V_2 -> V_72 = V_72 ;
F_64 ( & V_2 -> V_15 ) ;
if ( V_66 -> V_78 ( & V_2 -> V_5 ) ) {
V_37 = 0 ;
break;
}
}
V_70 -> V_74 = V_37 ;
return V_37 ;
}
static T_5 F_65 ( struct V_32 * V_33 )
{
struct V_13 * V_14 = V_33 -> V_4 ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_5 V_38 = V_14 -> V_38 ;
V_38 ++ ;
if ( V_38 < 0 )
V_38 = 1 ;
V_33 -> V_38 = V_38 ;
V_14 -> V_38 = V_38 ;
F_4 ( F_5 ( & V_2 -> V_5 ) , L_8 , V_11 , V_38 ) ;
if ( ! F_66 ( V_45 , & V_4 -> V_46 ) )
F_28 ( & V_4 -> V_47 , V_48 + V_54 ) ;
F_18 () ;
V_2 -> V_8 += V_2 -> V_79 ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
return V_38 ;
}
static struct V_17 * F_67 ( struct V_13 * V_4 , T_6 V_39 )
{
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_65 * V_70 ;
T_7 V_30 ;
V_70 = F_68 ( V_4 -> V_66 ) ;
V_20 = F_69 ( V_70 -> V_80 , V_39 , & V_30 ) ;
if ( ! V_20 )
return NULL ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_18 = F_70 ( V_81 , V_39 ) ;
if ( ! V_18 ) {
F_71 ( V_70 -> V_80 , V_20 , V_30 ) ;
return NULL ;
}
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
F_72 ( & V_18 -> V_29 , V_4 ) ;
V_18 -> V_29 . V_82 = F_65 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_29 . V_30 = V_30 ;
return V_18 ;
}
static void F_73 ( struct V_17 * V_18 , struct V_13 * V_4 )
{
struct V_65 * V_70 ;
V_70 = F_68 ( V_4 -> V_66 ) ;
F_71 ( V_70 -> V_80 , V_18 -> V_20 , V_18 -> V_29 . V_30 ) ;
F_74 ( V_81 , V_18 ) ;
}
static struct V_17 * * F_75 ( struct V_13 * V_14 , int V_83 , T_6 V_39 )
{
struct V_17 * * V_84 ;
int V_85 = 1 << V_83 ;
int V_37 ;
if ( V_83 > F_76 () )
return NULL ;
V_84 = F_77 ( V_85 , sizeof( * V_84 ) , V_39 ) ;
if ( ! V_84 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_85 ; V_37 ++ ) {
V_84 [ V_37 ] = F_67 ( V_14 , V_39 ) ;
if ( ! V_84 [ V_37 ] ) {
while ( V_37 -- )
F_73 ( V_84 [ V_37 ] , V_14 ) ;
F_78 ( V_84 ) ;
return NULL ;
}
F_79 ( V_84 [ V_37 ] , V_37 ) ;
}
for ( V_37 = 0 ; V_37 < V_85 - 1 ; V_37 ++ ) {
struct V_17 * V_86 = V_84 [ V_37 + 1 ] ;
struct V_19 * V_20 = V_84 [ V_37 ] -> V_20 ;
V_20 -> V_86 = V_86 -> V_29 . V_30 ;
}
V_84 [ V_37 ] -> V_20 -> V_86 = V_84 [ 0 ] -> V_29 . V_30 ;
return V_84 ;
}
int F_80 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * * V_84 ;
T_3 V_58 ;
int V_83 ;
int V_37 = 0 ;
if ( V_2 -> V_84 )
return 1 << V_2 -> V_64 ;
F_3 ( V_52 , V_4 -> V_9 + V_53 ) ;
V_4 -> V_87 = F_69 ( V_4 -> V_66 -> V_88 ,
V_77 , & V_4 -> V_89 ) ;
if ( ! V_4 -> V_87 )
return - V_90 ;
memset ( V_4 -> V_87 , 0 , sizeof( * V_4 -> V_87 ) ) ;
F_54 ( ( ( T_3 ) V_4 -> V_89 ) & 0x00000000FFFFFFFF ,
V_4 -> V_9 + V_91 ) ;
F_54 ( ( ( T_3 ) V_4 -> V_89 ) >> 32 ,
V_4 -> V_9 + V_92 ) ;
V_83 = F_50 () ;
V_84 = F_75 ( V_14 , V_83 , V_77 ) ;
if ( ! V_84 )
return - V_90 ;
F_8 ( & V_4 -> V_50 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_64 = V_83 ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_50 ) ;
F_81 ( & V_4 -> V_93 ) ;
F_19 ( V_2 ) ;
do {
F_82 ( 1 ) ;
V_58 = F_35 ( V_4 ) ;
} while ( V_37 ++ < 20 && ! F_36 ( V_58 ) && ! F_37 ( V_58 ) );
if ( F_36 ( V_58 ) || F_37 ( V_58 ) ) {
F_33 ( V_62 , & V_4 -> V_46 ) ;
return 1 << V_2 -> V_64 ;
} else {
T_2 V_60 = F_48 ( V_4 -> V_9 + V_61 ) ;
F_83 ( F_5 ( V_4 ) ,
L_9 , V_60 ) ;
F_84 ( V_14 ) ;
return - V_94 ;
}
}
bool F_51 ( struct V_1 * V_2 , int V_83 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & V_4 -> V_71 ;
const T_1 V_95 = F_85 ( V_2 ) ;
const T_1 V_35 = F_21 ( V_2 ) ;
const T_1 V_96 = 1 << V_83 ;
struct V_17 * * V_84 ;
T_1 V_37 ;
if ( V_83 > F_76 () )
return false ;
if ( V_35 == V_95 )
return false ;
if ( V_35 >= V_96 )
return false ;
V_84 = F_77 ( V_96 , sizeof( * V_84 ) , V_97 ) ;
if ( ! V_84 )
return false ;
if ( V_96 > V_95 ) {
for ( V_37 = 0 ; V_37 < V_95 ; V_37 ++ ) {
T_1 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
T_1 V_99 = ( V_2 -> V_12 + V_37 ) & ( V_96 - 1 ) ;
V_84 [ V_99 ] = V_2 -> V_84 [ V_98 ] ;
F_79 ( V_84 [ V_99 ] , V_99 ) ;
}
for ( V_37 = V_95 ; V_37 < V_96 ; V_37 ++ ) {
T_1 V_99 = ( V_2 -> V_12 + V_37 ) & ( V_96 - 1 ) ;
V_84 [ V_99 ] = F_67 ( V_14 , V_97 ) ;
if ( ! V_84 [ V_99 ] ) {
while ( V_37 -- ) {
T_1 V_99 = ( V_2 -> V_12 + V_37 ) & ( V_96 - 1 ) ;
F_73 ( V_84 [ V_99 ] , V_14 ) ;
}
F_78 ( V_84 ) ;
return false ;
}
F_79 ( V_84 [ V_99 ] , V_99 ) ;
}
for ( V_37 = V_95 - 1 ; V_37 < V_96 ; V_37 ++ ) {
T_1 V_99 = ( V_2 -> V_12 + V_37 ) & ( V_96 - 1 ) ;
struct V_17 * V_86 = V_84 [ ( V_99 + 1 ) & ( V_96 - 1 ) ] ;
struct V_19 * V_20 = V_84 [ V_99 ] -> V_20 ;
V_20 -> V_86 = V_86 -> V_29 . V_30 ;
}
} else {
struct V_19 * V_20 ;
struct V_17 * V_86 ;
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ ) {
T_1 V_98 = ( V_2 -> V_12 + V_37 ) & ( V_95 - 1 ) ;
T_1 V_99 = ( V_2 -> V_12 + V_37 ) & ( V_96 - 1 ) ;
V_84 [ V_99 ] = V_2 -> V_84 [ V_98 ] ;
F_79 ( V_84 [ V_99 ] , V_99 ) ;
}
for ( V_37 = V_96 ; V_37 < V_95 ; V_37 ++ ) {
struct V_17 * V_100 ;
V_100 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_73 ( V_100 , V_14 ) ;
}
V_20 = V_84 [ ( V_2 -> V_12 + V_96 - 1 ) & ( V_96 - 1 ) ] -> V_20 ;
V_86 = V_84 [ ( V_2 -> V_12 + V_96 ) & ( V_96 - 1 ) ] ;
V_20 -> V_86 = V_86 -> V_29 . V_30 ;
}
F_4 ( F_5 ( V_4 ) , L_10 ,
V_11 , V_96 ) ;
F_78 ( V_2 -> V_84 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_64 = V_83 ;
return true ;
}
int F_86 ( struct V_1 * V_2 , int V_101 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
bool V_102 ;
V_102:
F_8 ( & V_2 -> V_15 ) ;
if ( F_87 ( F_12 ( V_2 ) > V_101 ) ) {
F_4 ( F_5 ( V_4 ) , L_11 ,
V_11 , V_101 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
V_2 -> V_79 = V_101 ;
return 0 ;
}
V_102 = F_66 ( V_103 , & V_4 -> V_46 ) ;
F_9 ( & V_2 -> V_15 ) ;
if ( V_102 )
goto V_102;
F_8 ( & V_4 -> V_50 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_102 = F_51 ( V_2 , V_2 -> V_64 + 1 ) ;
F_27 ( V_103 , & V_4 -> V_46 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_50 ) ;
if ( V_102 )
goto V_102;
if ( F_88 () )
F_4 ( F_5 ( V_4 ) , L_12 ,
V_11 , V_101 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
if ( V_48 > V_4 -> V_47 . V_104 && F_89 ( & V_4 -> V_47 ) ) {
struct V_65 * V_66 = V_4 -> V_66 ;
F_28 ( & V_4 -> V_47 , V_48 + V_54 ) ;
V_66 -> V_105 ( ( unsigned long ) & V_4 -> V_71 ) ;
}
return - V_90 ;
}
struct V_32 *
F_90 ( struct V_13 * V_14 , T_7 V_106 ,
T_7 V_107 , T_8 V_40 , unsigned long V_39 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
T_7 V_108 = V_106 ;
T_7 V_109 = V_107 ;
T_8 V_110 = V_40 ;
int V_101 , V_36 , V_37 ;
V_101 = F_91 ( V_2 , V_40 ) ;
if ( F_87 ( V_101 ) && F_86 ( V_2 , V_101 ) == 0 )
V_36 = V_2 -> V_8 ;
else
return NULL ;
V_37 = 0 ;
do {
T_8 V_111 = F_92 ( T_8 , V_40 , 1 << V_2 -> V_72 ) ;
V_18 = F_14 ( V_2 , V_36 + V_37 ) ;
V_20 = V_18 -> V_20 ;
V_20 -> V_25 = V_111 ;
V_20 -> V_21 = 0 ;
V_20 -> V_27 = V_109 ;
V_20 -> V_28 = V_108 ;
V_40 -= V_111 ;
V_108 += V_111 ;
V_109 += V_111 ;
F_17 ( V_2 , V_18 ) ;
} while ( ++ V_37 < V_101 );
V_18 -> V_29 . V_39 = V_39 ;
V_18 -> V_40 = V_110 ;
V_20 -> V_22 . V_23 = ! ! ( V_39 & V_112 ) ;
V_20 -> V_22 . V_113 = ! ! ( V_39 & V_114 ) ;
V_20 -> V_22 . V_24 = 1 ;
F_17 ( V_2 , V_18 ) ;
return & V_18 -> V_29 ;
}
void F_84 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_65 * V_66 = V_4 -> V_66 ;
struct V_17 * V_18 ;
const T_1 V_115 = 1 << V_2 -> V_64 ;
int V_85 ;
int V_37 ;
if ( ! V_2 -> V_84 )
return;
F_93 ( & V_4 -> V_93 ) ;
F_94 ( & V_4 -> V_47 ) ;
V_66 -> V_116 ( ( unsigned long ) V_14 ) ;
V_66 -> V_78 ( V_4 ) ;
F_27 ( V_62 , & V_4 -> V_46 ) ;
F_8 ( & V_4 -> V_50 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_85 = F_12 ( V_2 ) ;
F_4 ( F_5 ( V_4 ) , L_13 , V_85 ) ;
for ( V_37 = 0 ; V_37 < V_85 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_8 + V_37 ) ;
F_73 ( V_18 , V_14 ) ;
}
if ( V_85 < V_115 )
F_13 ( F_5 ( V_4 ) , L_14 ,
V_115 - V_85 ) ;
for ( V_37 = 0 ; V_37 < V_115 - V_85 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_17 ( V_2 , V_18 ) ;
F_73 ( V_18 , V_14 ) ;
}
F_78 ( V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
V_2 -> V_64 = 0 ;
F_71 ( V_66 -> V_88 , V_4 -> V_87 ,
V_4 -> V_89 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_50 ) ;
V_4 -> V_44 = 0 ;
V_4 -> V_89 = 0 ;
V_2 -> V_6 = 0 ;
}
static T_9 F_95 ( struct V_13 * V_14 , char * V_117 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_117 , L_15 , ( 1 << V_2 -> V_64 ) & ~ 1 ) ;
}
static T_9 F_96 ( struct V_13 * V_14 , char * V_117 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_117 , L_15 , F_21 ( V_2 ) ) ;
}
int T_10 F_97 ( struct V_65 * V_66 , int V_118 )
{
struct V_119 * V_68 = V_66 -> V_68 ;
struct V_69 * V_70 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_57 ;
V_66 -> V_120 = F_55 ;
V_66 -> V_78 = F_52 ;
V_66 -> V_116 = F_31 ;
V_66 -> V_105 = F_45 ;
V_66 -> V_121 = V_122 ;
V_70 = & V_66 -> V_71 ;
V_70 -> V_123 = F_90 ;
V_70 -> V_124 = F_6 ;
V_70 -> V_125 = F_80 ;
V_70 -> V_126 = F_84 ;
V_70 -> V_127 = V_128 ;
V_57 = F_98 ( V_66 ) ;
if ( V_57 )
return V_57 ;
F_99 ( 2048 ) ;
F_100 (c, &dma->channels, device_node) {
V_4 = F_101 ( V_14 ) ;
F_54 ( V_129 | V_130 ,
V_4 -> V_9 + V_131 ) ;
}
V_57 = F_102 ( V_66 ) ;
if ( V_57 )
return V_57 ;
F_103 ( V_66 , & V_132 ) ;
if ( V_118 )
V_66 -> V_118 = F_104 ( V_68 , V_66 -> V_9 ) ;
return V_57 ;
}
