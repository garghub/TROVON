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
F_24 ( V_33 ) ;
F_25 ( V_33 ) ;
if ( V_33 -> V_39 ) {
V_33 -> V_39 ( V_33 -> V_40 ) ;
V_33 -> V_39 = NULL ;
}
}
if ( V_33 -> V_30 == V_31 )
V_34 = true ;
}
F_26 () ;
V_2 -> V_12 = V_36 + V_37 ;
F_27 ( V_35 && ! V_34 ) ;
V_4 -> V_41 = V_31 ;
if ( V_35 - V_37 == 0 ) {
F_4 ( F_5 ( V_4 ) , L_4 ,
V_11 ) ;
F_28 ( V_42 , & V_4 -> V_43 ) ;
F_29 ( & V_4 -> V_44 , V_45 + V_46 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_31 ;
F_8 ( & V_4 -> V_47 ) ;
if ( F_31 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_9 ( & V_4 -> V_47 ) ;
}
void F_32 ( unsigned long V_48 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_48 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
F_30 ( V_2 ) ;
if ( ! F_33 ( V_49 , & V_4 -> V_43 ) )
return;
F_3 ( V_50 , V_2 -> V_5 . V_9 + V_51 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_2 -> V_7 = V_2 -> V_12 ;
V_2 -> V_6 = 0 ;
F_35 ( V_42 , & V_4 -> V_43 ) ;
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
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
int F_36 ( struct V_3 * V_4 , unsigned long V_53 )
{
unsigned long V_54 = V_45 + V_53 ;
int V_55 = 0 ;
T_3 V_56 ;
V_56 = F_37 ( V_4 ) ;
if ( F_38 ( V_56 ) || F_39 ( V_56 ) )
F_40 ( V_4 ) ;
while ( F_38 ( V_56 ) || F_39 ( V_56 ) ) {
if ( V_53 && F_41 ( V_45 , V_54 ) ) {
V_55 = - V_57 ;
break;
}
V_56 = F_37 ( V_4 ) ;
F_42 () ;
}
return V_55 ;
}
int F_43 ( struct V_3 * V_4 , unsigned long V_53 )
{
unsigned long V_54 = V_45 + V_53 ;
int V_55 = 0 ;
F_44 ( V_4 ) ;
while ( F_45 ( V_4 ) ) {
if ( V_54 && F_41 ( V_45 , V_54 ) ) {
V_55 = - V_57 ;
break;
}
F_42 () ;
}
return V_55 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_31 ;
F_36 ( V_4 , 0 ) ;
if ( F_31 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
F_34 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_21 ( V_2 ) ) {
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
return;
}
if ( F_48 ( V_58 , & V_4 -> V_43 ) )
F_29 ( & V_4 -> V_44 , V_45 + V_46 ) ;
else if ( V_2 -> V_59 > F_49 () ) {
F_50 ( V_2 , V_2 -> V_59 - 1 ) ;
if ( V_2 -> V_59 > F_49 () )
F_29 ( & V_4 -> V_44 , V_45 + V_46 ) ;
}
}
void F_51 ( unsigned long V_48 )
{
struct V_1 * V_2 = F_7 ( ( void * ) V_48 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_1 V_31 ;
T_4 V_56 ;
V_56 = F_37 ( V_4 ) ;
if ( F_52 ( V_56 ) ) {
T_3 V_60 ;
V_60 = F_53 ( V_4 -> V_9 + V_61 ) ;
F_13 ( F_5 ( V_4 ) , L_5 ,
V_11 , V_60 ) ;
if ( F_33 ( V_49 , & V_4 -> V_43 ) )
F_27 ( F_54 ( V_60 ) ) ;
else
return;
}
F_8 ( & V_4 -> V_47 ) ;
if ( F_31 ( V_4 , & V_31 ) )
F_20 ( V_2 , V_31 ) ;
else if ( F_33 ( V_62 , & V_4 -> V_43 ) ) {
F_8 ( & V_2 -> V_15 ) ;
F_46 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_47 ) ;
return;
} else {
F_35 ( V_62 , & V_4 -> V_43 ) ;
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
}
if ( F_21 ( V_2 ) )
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
else {
F_8 ( & V_2 -> V_15 ) ;
F_47 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
}
F_9 ( & V_4 -> V_47 ) ;
}
static int F_55 ( struct V_3 * V_4 )
{
T_3 V_60 ;
F_36 ( V_4 , F_56 ( 100 ) ) ;
V_60 = F_53 ( V_4 -> V_9 + V_61 ) ;
F_57 ( V_60 , V_4 -> V_9 + V_61 ) ;
return F_43 ( V_4 , F_56 ( 200 ) ) ;
}
int F_58 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 = & V_64 -> V_66 -> V_65 ;
struct V_67 * V_68 = & V_64 -> V_69 ;
T_5 V_70 ;
int V_37 ;
F_59 ( & V_68 -> V_71 ) ;
V_68 -> V_72 = F_60 ( V_64 -> V_9 + V_73 ) ;
V_68 -> V_72 &= 0x1f ;
if ( V_68 -> V_72 > F_61 ( V_64 -> V_36 ) ) {
F_62 ( V_65 , L_6 ,
V_68 -> V_72 , F_61 ( V_64 -> V_36 ) ) ;
V_68 -> V_72 = F_61 ( V_64 -> V_36 ) ;
}
V_70 = F_60 ( V_64 -> V_9 + V_74 ) ;
V_70 &= 0x1f ;
if ( V_70 == 0 )
return 0 ;
F_4 ( V_65 , L_7 , V_11 , 1 << V_70 ) ;
#ifdef F_63
if ( F_64 ( NULL , NULL , 1 ) == 0 )
V_68 -> V_72 -- ;
#endif
for ( V_37 = 0 ; V_37 < V_68 -> V_72 ; V_37 ++ ) {
V_2 = F_65 ( V_65 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
break;
F_66 ( V_64 , & V_2 -> V_5 , V_37 ) ;
V_2 -> V_70 = V_70 ;
F_67 ( & V_2 -> V_15 ) ;
if ( V_64 -> V_76 ( & V_2 -> V_5 ) ) {
V_37 = 0 ;
break;
}
}
V_68 -> V_72 = V_37 ;
return V_37 ;
}
static T_6 F_68 ( struct V_32 * V_33 )
{
struct V_13 * V_14 = V_33 -> V_4 ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
T_6 V_38 ;
V_38 = F_69 ( V_33 ) ;
F_4 ( F_5 ( & V_2 -> V_5 ) , L_8 , V_11 , V_38 ) ;
if ( ! F_70 ( V_58 , & V_4 -> V_43 ) )
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
F_18 () ;
V_2 -> V_8 += V_2 -> V_77 ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_15 ) ;
return V_38 ;
}
static struct V_17 * F_71 ( struct V_13 * V_4 , T_7 V_78 )
{
struct V_19 * V_20 ;
struct V_17 * V_18 ;
struct V_63 * V_68 ;
T_1 V_30 ;
V_68 = F_72 ( V_4 -> V_64 ) ;
V_20 = F_73 ( V_68 -> V_79 , V_78 , & V_30 ) ;
if ( ! V_20 )
return NULL ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_18 = F_74 ( V_80 , V_78 ) ;
if ( ! V_18 ) {
F_75 ( V_68 -> V_79 , V_20 , V_30 ) ;
return NULL ;
}
F_76 ( & V_18 -> V_29 , V_4 ) ;
V_18 -> V_29 . V_81 = F_68 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_29 . V_30 = V_30 ;
return V_18 ;
}
static void F_77 ( struct V_17 * V_18 , struct V_13 * V_4 )
{
struct V_63 * V_68 ;
V_68 = F_72 ( V_4 -> V_64 ) ;
F_75 ( V_68 -> V_79 , V_18 -> V_20 , V_18 -> V_29 . V_30 ) ;
F_78 ( V_80 , V_18 ) ;
}
static struct V_17 * * F_79 ( struct V_13 * V_14 , int V_82 , T_7 V_78 )
{
struct V_17 * * V_83 ;
int V_84 = 1 << V_82 ;
int V_37 ;
if ( V_82 > F_80 () )
return NULL ;
V_83 = F_81 ( V_84 , sizeof( * V_83 ) , V_78 ) ;
if ( ! V_83 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_84 ; V_37 ++ ) {
V_83 [ V_37 ] = F_71 ( V_14 , V_78 ) ;
if ( ! V_83 [ V_37 ] ) {
while ( V_37 -- )
F_77 ( V_83 [ V_37 ] , V_14 ) ;
F_82 ( V_83 ) ;
return NULL ;
}
F_83 ( V_83 [ V_37 ] , V_37 ) ;
}
for ( V_37 = 0 ; V_37 < V_84 - 1 ; V_37 ++ ) {
struct V_17 * V_85 = V_83 [ V_37 + 1 ] ;
struct V_19 * V_20 = V_83 [ V_37 ] -> V_20 ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
V_83 [ V_37 ] -> V_20 -> V_85 = V_83 [ 0 ] -> V_29 . V_30 ;
return V_83 ;
}
int F_84 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_17 * * V_83 ;
T_4 V_56 ;
int V_82 ;
int V_37 = 0 ;
if ( V_2 -> V_83 )
return 1 << V_2 -> V_59 ;
F_3 ( V_50 , V_4 -> V_9 + V_51 ) ;
V_4 -> V_86 = F_73 ( V_4 -> V_64 -> V_87 ,
V_75 , & V_4 -> V_88 ) ;
if ( ! V_4 -> V_86 )
return - V_89 ;
memset ( V_4 -> V_86 , 0 , sizeof( * V_4 -> V_86 ) ) ;
F_57 ( ( ( T_4 ) V_4 -> V_88 ) & 0x00000000FFFFFFFF ,
V_4 -> V_9 + V_90 ) ;
F_57 ( ( ( T_4 ) V_4 -> V_88 ) >> 32 ,
V_4 -> V_9 + V_91 ) ;
V_82 = F_49 () ;
V_83 = F_79 ( V_14 , V_82 , V_75 ) ;
if ( ! V_83 )
return - V_89 ;
F_8 ( & V_4 -> V_47 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_59 = V_82 ;
F_35 ( V_49 , & V_4 -> V_43 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_47 ) ;
F_19 ( V_2 ) ;
do {
F_85 ( 1 ) ;
V_56 = F_37 ( V_4 ) ;
} while ( V_37 ++ < 20 && ! F_38 ( V_56 ) && ! F_39 ( V_56 ) );
if ( F_38 ( V_56 ) || F_39 ( V_56 ) ) {
return 1 << V_2 -> V_59 ;
} else {
T_3 V_60 = F_53 ( V_4 -> V_9 + V_61 ) ;
F_86 ( F_5 ( V_4 ) ,
L_9 , V_60 ) ;
F_87 ( V_14 ) ;
return - V_92 ;
}
}
bool F_50 ( struct V_1 * V_2 , int V_82 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & V_4 -> V_69 ;
const T_3 V_93 = F_88 ( V_2 ) ;
const T_2 V_35 = F_21 ( V_2 ) ;
const T_3 V_94 = 1 << V_82 ;
struct V_17 * * V_83 ;
T_2 V_37 ;
if ( V_82 > F_80 () )
return false ;
if ( V_35 == V_93 )
return false ;
if ( V_35 >= V_94 )
return false ;
V_83 = F_81 ( V_94 , sizeof( * V_83 ) , V_95 ) ;
if ( ! V_83 )
return false ;
if ( V_94 > V_93 ) {
for ( V_37 = 0 ; V_37 < V_93 ; V_37 ++ ) {
T_2 V_96 = ( V_2 -> V_12 + V_37 ) & ( V_93 - 1 ) ;
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
V_83 [ V_97 ] = V_2 -> V_83 [ V_96 ] ;
F_83 ( V_83 [ V_97 ] , V_97 ) ;
}
for ( V_37 = V_93 ; V_37 < V_94 ; V_37 ++ ) {
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
V_83 [ V_97 ] = F_71 ( V_14 , V_95 ) ;
if ( ! V_83 [ V_97 ] ) {
while ( V_37 -- ) {
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
F_77 ( V_83 [ V_97 ] , V_14 ) ;
}
F_82 ( V_83 ) ;
return false ;
}
F_83 ( V_83 [ V_97 ] , V_97 ) ;
}
for ( V_37 = V_93 - 1 ; V_37 < V_94 ; V_37 ++ ) {
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
struct V_17 * V_85 = V_83 [ ( V_97 + 1 ) & ( V_94 - 1 ) ] ;
struct V_19 * V_20 = V_83 [ V_97 ] -> V_20 ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
} else {
struct V_19 * V_20 ;
struct V_17 * V_85 ;
for ( V_37 = 0 ; V_37 < V_94 ; V_37 ++ ) {
T_2 V_96 = ( V_2 -> V_12 + V_37 ) & ( V_93 - 1 ) ;
T_2 V_97 = ( V_2 -> V_12 + V_37 ) & ( V_94 - 1 ) ;
V_83 [ V_97 ] = V_2 -> V_83 [ V_96 ] ;
F_83 ( V_83 [ V_97 ] , V_97 ) ;
}
for ( V_37 = V_94 ; V_37 < V_93 ; V_37 ++ ) {
struct V_17 * V_98 ;
V_98 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_77 ( V_98 , V_14 ) ;
}
V_20 = V_83 [ ( V_2 -> V_12 + V_94 - 1 ) & ( V_94 - 1 ) ] -> V_20 ;
V_85 = V_83 [ ( V_2 -> V_12 + V_94 ) & ( V_94 - 1 ) ] ;
V_20 -> V_85 = V_85 -> V_29 . V_30 ;
}
F_4 ( F_5 ( V_4 ) , L_10 ,
V_11 , V_94 ) ;
F_82 ( V_2 -> V_83 ) ;
V_2 -> V_83 = V_83 ;
V_2 -> V_59 = V_82 ;
return true ;
}
int F_89 ( struct V_1 * V_2 , int V_99 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
bool V_100 ;
V_100:
F_8 ( & V_2 -> V_15 ) ;
if ( F_90 ( F_12 ( V_2 ) > V_99 ) ) {
F_4 ( F_5 ( V_4 ) , L_11 ,
V_11 , V_99 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
V_2 -> V_77 = V_99 ;
return 0 ;
}
V_100 = F_70 ( V_101 , & V_4 -> V_43 ) ;
F_9 ( & V_2 -> V_15 ) ;
if ( V_100 )
goto V_100;
F_8 ( & V_4 -> V_47 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_100 = F_50 ( V_2 , V_2 -> V_59 + 1 ) ;
F_28 ( V_101 , & V_4 -> V_43 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_47 ) ;
if ( V_100 )
goto V_100;
if ( F_91 () )
F_4 ( F_5 ( V_4 ) , L_12 ,
V_11 , V_99 , V_2 -> V_8 , V_2 -> V_12 , V_2 -> V_7 ) ;
if ( V_45 > V_4 -> V_44 . V_102 && F_92 ( & V_4 -> V_44 ) ) {
struct V_63 * V_64 = V_4 -> V_64 ;
F_29 ( & V_4 -> V_44 , V_45 + V_52 ) ;
V_64 -> V_103 ( ( unsigned long ) & V_4 -> V_69 ) ;
}
return - V_89 ;
}
struct V_32 *
F_93 ( struct V_13 * V_14 , T_1 V_104 ,
T_1 V_105 , T_8 V_106 , unsigned long V_78 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_19 * V_20 ;
struct V_17 * V_18 ;
T_1 V_107 = V_104 ;
T_1 V_108 = V_105 ;
T_8 V_109 = V_106 ;
int V_99 , V_36 , V_37 ;
V_99 = F_94 ( V_2 , V_106 ) ;
if ( F_90 ( V_99 ) && F_89 ( V_2 , V_99 ) == 0 )
V_36 = V_2 -> V_8 ;
else
return NULL ;
V_37 = 0 ;
do {
T_8 V_110 = F_95 ( T_8 , V_106 , 1 << V_2 -> V_70 ) ;
V_18 = F_14 ( V_2 , V_36 + V_37 ) ;
V_20 = V_18 -> V_20 ;
V_20 -> V_25 = V_110 ;
V_20 -> V_21 = 0 ;
V_20 -> V_27 = V_108 ;
V_20 -> V_28 = V_107 ;
V_106 -= V_110 ;
V_107 += V_110 ;
V_108 += V_110 ;
F_17 ( V_2 , V_18 ) ;
} while ( ++ V_37 < V_99 );
V_18 -> V_29 . V_78 = V_78 ;
V_18 -> V_106 = V_109 ;
V_20 -> V_22 . V_23 = ! ! ( V_78 & V_111 ) ;
V_20 -> V_22 . V_112 = ! ! ( V_78 & V_113 ) ;
V_20 -> V_22 . V_24 = 1 ;
F_17 ( V_2 , V_18 ) ;
return & V_18 -> V_29 ;
}
void F_87 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_63 * V_64 = V_4 -> V_64 ;
struct V_17 * V_18 ;
const T_2 V_114 = 1 << V_2 -> V_59 ;
int V_84 ;
int V_37 ;
if ( ! V_2 -> V_83 )
return;
F_96 ( V_4 ) ;
V_64 -> V_76 ( V_4 ) ;
F_8 ( & V_4 -> V_47 ) ;
F_8 ( & V_2 -> V_15 ) ;
V_84 = F_12 ( V_2 ) ;
F_4 ( F_5 ( V_4 ) , L_13 , V_84 ) ;
for ( V_37 = 0 ; V_37 < V_84 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_8 + V_37 ) ;
F_77 ( V_18 , V_14 ) ;
}
if ( V_84 < V_114 )
F_13 ( F_5 ( V_4 ) , L_14 ,
V_114 - V_84 ) ;
for ( V_37 = 0 ; V_37 < V_114 - V_84 ; V_37 ++ ) {
V_18 = F_14 ( V_2 , V_2 -> V_12 + V_37 ) ;
F_17 ( V_2 , V_18 ) ;
F_77 ( V_18 , V_14 ) ;
}
F_82 ( V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
V_2 -> V_59 = 0 ;
F_75 ( V_64 -> V_87 , V_4 -> V_86 ,
V_4 -> V_88 ) ;
F_9 ( & V_2 -> V_15 ) ;
F_9 ( & V_4 -> V_47 ) ;
V_4 -> V_41 = 0 ;
V_4 -> V_88 = 0 ;
V_2 -> V_6 = 0 ;
}
static T_9 F_97 ( struct V_13 * V_14 , char * V_115 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_115 , L_15 , ( 1 << V_2 -> V_59 ) & ~ 1 ) ;
}
static T_9 F_98 ( struct V_13 * V_14 , char * V_115 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
return sprintf ( V_115 , L_15 , F_21 ( V_2 ) ) ;
}
int F_99 ( struct V_63 * V_64 , int V_116 )
{
struct V_117 * V_66 = V_64 -> V_66 ;
struct V_67 * V_68 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
int V_55 ;
V_64 -> V_118 = F_58 ;
V_64 -> V_76 = F_55 ;
V_64 -> V_119 = F_32 ;
V_64 -> V_103 = F_51 ;
V_64 -> V_120 = V_121 ;
V_68 = & V_64 -> V_69 ;
V_68 -> V_122 = F_93 ;
V_68 -> V_123 = F_6 ;
V_68 -> V_124 = F_84 ;
V_68 -> V_125 = F_87 ;
V_68 -> V_126 = V_127 ;
V_55 = F_100 ( V_64 ) ;
if ( V_55 )
return V_55 ;
F_101 ( 2048 ) ;
F_102 (c, &dma->channels, device_node) {
V_4 = F_103 ( V_14 ) ;
F_57 ( V_128 | V_129 ,
V_4 -> V_9 + V_130 ) ;
}
V_55 = F_104 ( V_64 ) ;
if ( V_55 )
return V_55 ;
F_105 ( V_64 , & V_131 ) ;
if ( V_116 )
V_64 -> V_116 = F_106 ( V_66 , V_64 -> V_9 ) ;
return V_55 ;
}
