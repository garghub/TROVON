static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( V_6 ) ;
F_3 ( & V_7 ) ;
F_4 ( & V_8 , & V_6 ) ;
F_5 ( & V_7 ) ;
if ( F_6 ( & V_6 ) )
return;
F_7 (p, n, &list, gc_list) {
if( F_8 () )
F_9 () ;
if ( V_4 -> V_9 != V_10 ) {
F_10 ( & V_4 -> V_9 -> V_8 , & V_6 ) ;
V_4 -> V_9 = V_10 ;
}
if ( V_4 -> V_11 != V_10 ) {
F_10 ( & V_4 -> V_11 -> V_8 , & V_6 ) ;
V_4 -> V_11 = V_10 ;
}
V_5 = F_11 ( V_4 -> V_8 . V_12 , struct V_3 , V_8 ) ;
if ( ! F_12 ( & V_4 -> V_13 ) ) {
F_13 ( & V_4 -> V_8 ) ;
F_14 ( V_14 , V_4 ) ;
}
}
if ( F_6 ( & V_6 ) )
return;
F_3 ( & V_7 ) ;
F_15 ( & V_6 , & V_8 ) ;
F_5 ( & V_7 ) ;
F_16 ( & V_15 , V_16 ) ;
}
void T_1 F_17 ( void )
{
struct V_17 V_18 ;
F_18 ( & V_18 ) ;
if ( V_18 . V_19 <= ( 32768 * 1024 ) / V_20 )
V_21 >>= 1 ;
if ( V_18 . V_19 <= ( 16384 * 1024 ) / V_20 )
V_21 >>= 1 ;
if ( V_18 . V_19 <= ( 8192 * 1024 ) / V_20 )
V_21 >>= 2 ;
V_14 = F_19 ( L_1 ,
sizeof( struct V_3 ) ,
0 , V_22 | V_23 ,
NULL ) ;
F_20 ( & V_15 , F_1 ) ;
}
static int F_21 ( const struct V_24 * V_25 ,
const struct V_24 * V_26 )
{
int V_27 , V_5 = ( V_25 -> V_28 == V_29 ? 1 : 4 ) ;
for ( V_27 = 0 ; V_27 < V_5 ; V_27 ++ ) {
if ( V_25 -> V_30 . V_31 [ V_27 ] == V_26 -> V_30 . V_31 [ V_27 ] )
continue;
if ( ( V_32 V_33 ) V_25 -> V_30 . V_31 [ V_27 ] < ( V_32 V_33 ) V_26 -> V_30 . V_31 [ V_27 ] )
return - 1 ;
return 1 ;
}
return 0 ;
}
static struct V_3 * F_22 ( const struct V_24 * V_34 ,
struct V_35 * V_36 )
{
struct V_3 * V_37 = F_23 ( V_36 -> V_38 ) ;
int V_39 = 0 ;
while ( V_37 != V_10 ) {
int V_40 = F_21 ( V_34 , & V_37 -> V_34 ) ;
if ( V_40 == 0 ) {
if ( ! F_24 ( & V_37 -> V_13 , 1 , - 1 ) )
V_37 = NULL ;
return V_37 ;
}
if ( V_40 == - 1 )
V_37 = F_23 ( V_37 -> V_9 ) ;
else
V_37 = F_23 ( V_37 -> V_11 ) ;
if ( F_25 ( ++ V_39 == V_41 ) )
break;
}
return NULL ;
}
static void F_26 ( struct V_3 T_2 * * V_42 [] ,
struct V_3 T_2 * * * V_43 ,
struct V_35 * V_36 )
{
struct V_3 T_2 * * V_44 ;
struct V_3 * V_45 , * V_46 , * V_47 ;
int V_48 , V_49 ;
while ( V_43 > V_42 ) {
V_44 = * -- V_43 ;
V_45 = F_27 ( * V_44 , V_36 ) ;
V_46 = F_27 ( V_45 -> V_9 , V_36 ) ;
V_47 = F_27 ( V_45 -> V_11 , V_36 ) ;
V_48 = F_28 ( V_46 ) ;
V_49 = F_28 ( V_47 ) ;
if ( V_48 > V_49 + 1 ) {
struct V_3 * V_50 , * V_51 , * V_52 , * V_53 ;
int V_54 ;
V_50 = F_27 ( V_46 -> V_9 , V_36 ) ;
V_51 = F_27 ( V_46 -> V_11 , V_36 ) ;
V_54 = F_28 ( V_51 ) ;
if ( V_54 <= F_28 ( V_50 ) ) {
F_29 ( V_45 -> V_9 , V_51 ) ;
F_29 ( V_45 -> V_11 , V_47 ) ;
V_45 -> V_55 = V_54 + 1 ;
F_29 ( V_46 -> V_9 , V_50 ) ;
F_29 ( V_46 -> V_11 , V_45 ) ;
V_46 -> V_55 = V_45 -> V_55 + 1 ;
F_29 ( * V_44 , V_46 ) ;
} else {
V_52 = F_27 ( V_51 -> V_9 , V_36 ) ;
V_53 = F_27 ( V_51 -> V_11 , V_36 ) ;
F_29 ( V_45 -> V_9 , V_53 ) ;
F_29 ( V_45 -> V_11 , V_47 ) ;
V_45 -> V_55 = V_49 + 1 ;
F_29 ( V_46 -> V_9 , V_50 ) ;
F_29 ( V_46 -> V_11 , V_52 ) ;
V_46 -> V_55 = V_49 + 1 ;
F_29 ( V_51 -> V_9 , V_46 ) ;
F_29 ( V_51 -> V_11 , V_45 ) ;
V_51 -> V_55 = V_49 + 2 ;
F_29 ( * V_44 , V_51 ) ;
}
} else if ( V_49 > V_48 + 1 ) {
struct V_3 * V_56 , * V_57 , * V_58 , * V_59 ;
int V_60 ;
V_56 = F_27 ( V_47 -> V_11 , V_36 ) ;
V_57 = F_27 ( V_47 -> V_9 , V_36 ) ;
V_60 = F_28 ( V_57 ) ;
if ( V_60 <= F_28 ( V_56 ) ) {
F_29 ( V_45 -> V_11 , V_57 ) ;
F_29 ( V_45 -> V_9 , V_46 ) ;
V_45 -> V_55 = V_60 + 1 ;
F_29 ( V_47 -> V_11 , V_56 ) ;
F_29 ( V_47 -> V_9 , V_45 ) ;
V_47 -> V_55 = V_45 -> V_55 + 1 ;
F_29 ( * V_44 , V_47 ) ;
} else {
V_58 = F_27 ( V_57 -> V_11 , V_36 ) ;
V_59 = F_27 ( V_57 -> V_9 , V_36 ) ;
F_29 ( V_45 -> V_11 , V_59 ) ;
F_29 ( V_45 -> V_9 , V_46 ) ;
V_45 -> V_55 = V_48 + 1 ;
F_29 ( V_47 -> V_11 , V_56 ) ;
F_29 ( V_47 -> V_9 , V_58 ) ;
V_47 -> V_55 = V_48 + 1 ;
F_29 ( V_57 -> V_11 , V_47 ) ;
F_29 ( V_57 -> V_9 , V_45 ) ;
V_57 -> V_55 = V_48 + 2 ;
F_29 ( * V_44 , V_57 ) ;
}
} else {
V_45 -> V_55 = ( V_48 > V_49 ? V_48 : V_49 ) + 1 ;
}
}
}
static void F_30 ( struct V_61 * V_62 )
{
F_14 ( V_14 , F_31 ( V_62 , struct V_3 , V_63 ) ) ;
}
static void F_32 ( struct V_3 * V_4 , struct V_35 * V_36 ,
struct V_3 T_2 * * V_42 [ V_41 ] )
{
struct V_3 T_2 * * * V_64 , * * * V_65 ;
if ( F_33 ( & V_4 -> V_34 , V_42 , V_36 ) != V_4 )
F_34 () ;
V_65 = V_64 - 1 ;
if ( V_4 -> V_9 == V_66 ) {
* V_65 [ 0 ] = V_4 -> V_11 ;
-- V_64 ;
} else {
struct V_3 * V_67 ;
V_67 = F_35 ( V_4 , V_36 ) ;
F_36 ( F_27 ( * V_64 [ - 1 ] , V_36 ) != V_67 ) ;
* * -- V_64 = V_67 -> V_9 ;
F_29 ( * V_65 [ 0 ] , V_67 ) ;
V_67 -> V_9 = V_4 -> V_9 ;
V_67 -> V_11 = V_4 -> V_11 ;
V_67 -> V_55 = V_4 -> V_55 ;
F_36 ( V_65 [ 1 ] != & V_4 -> V_9 ) ;
V_65 [ 1 ] = & V_67 -> V_9 ;
}
F_26 ( V_42 , V_64 , V_36 ) ;
V_36 -> V_68 -- ;
F_37 ( & V_4 -> V_63 , F_30 ) ;
}
static struct V_35 * F_38 ( int V_28 )
{
return V_28 == V_29 ? & V_69 : & V_70 ;
}
static int F_39 ( struct V_35 * V_36 ,
struct V_3 T_2 * * V_42 [ V_41 ] ,
struct V_3 T_2 * * * V_64 )
{
struct V_3 * V_4 , * V_71 = NULL ;
T_3 V_72 , V_73 ;
int V_74 = 0 ;
if ( V_36 -> V_68 >= V_21 )
V_73 = 0 ;
else
V_73 = V_75
- ( V_75 - V_76 ) / V_77 *
V_36 -> V_68 / V_21 * V_77 ;
V_64 -- ;
while ( V_64 > V_42 ) {
V_64 -- ;
V_4 = F_27 ( * * V_64 , V_36 ) ;
if ( F_12 ( & V_4 -> V_13 ) == 0 ) {
F_40 () ;
V_72 = ( T_3 ) V_78 - V_4 -> V_79 ;
if ( V_72 >= V_73 &&
F_41 ( & V_4 -> V_13 , 0 , - 1 ) == 0 ) {
V_4 -> V_80 = V_71 ;
V_71 = V_4 ;
}
}
}
while ( ( V_4 = V_71 ) != NULL ) {
V_71 = V_4 -> V_80 ;
V_74 ++ ;
F_32 ( V_4 , V_36 , V_42 ) ;
}
return V_74 ;
}
struct V_3 * F_42 ( const struct V_24 * V_34 , int V_81 )
{
struct V_3 T_2 * * V_42 [ V_41 ] , * * * V_64 ;
struct V_35 * V_36 = F_38 ( V_34 -> V_28 ) ;
struct V_3 * V_4 ;
unsigned int V_82 ;
int V_83 , V_84 = 0 ;
F_43 () ;
V_82 = F_44 ( & V_36 -> V_85 ) ;
V_4 = F_22 ( V_34 , V_36 ) ;
V_83 = F_45 ( & V_36 -> V_85 , V_82 ) ;
F_46 () ;
if ( V_4 )
return V_4 ;
if ( ! V_81 && ! V_83 )
return NULL ;
F_47 ( & V_36 -> V_85 ) ;
V_86:
V_4 = F_33 ( V_34 , V_42 , V_36 ) ;
if ( V_4 != V_10 ) {
F_48 ( & V_4 -> V_13 ) ;
F_49 ( & V_36 -> V_85 ) ;
return V_4 ;
}
if ( ! V_84 ) {
V_84 = F_39 ( V_36 , V_42 , V_64 ) ;
if ( V_84 && V_81 )
goto V_86;
}
V_4 = V_81 ? F_50 ( V_14 , V_87 ) : NULL ;
if ( V_4 ) {
V_4 -> V_34 = * V_34 ;
F_51 ( & V_4 -> V_13 , 1 ) ;
F_51 ( & V_4 -> V_88 , 0 ) ;
F_51 ( & V_4 -> V_89 ,
( V_34 -> V_28 == V_29 ) ?
F_52 ( V_34 -> V_30 . V_90 ) :
F_53 ( V_34 -> V_30 . V_31 ) ) ;
V_4 -> V_91 = 0 ;
V_4 -> V_92 [ V_93 - 1 ] = V_94 ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = 0 ;
V_4 -> V_97 = 0 ;
V_4 -> V_98 = 0 ;
memset ( & V_4 -> V_99 , 0 , sizeof( V_4 -> V_99 ) ) ;
F_54 ( & V_4 -> V_8 ) ;
F_55 ( V_4 , V_36 ) ;
V_36 -> V_68 ++ ;
}
F_49 ( & V_36 -> V_85 ) ;
return V_4 ;
}
void F_56 ( struct V_3 * V_4 )
{
V_4 -> V_79 = ( T_3 ) V_78 ;
F_57 () ;
F_58 ( & V_4 -> V_13 ) ;
}
bool F_59 ( struct V_3 * V_100 , int V_101 )
{
unsigned long V_102 , V_103 ;
bool V_104 = false ;
if ( ! V_100 )
return true ;
V_103 = V_100 -> V_95 ;
V_102 = V_78 ;
V_103 += V_102 - V_100 -> V_96 ;
V_100 -> V_96 = V_102 ;
if ( V_103 > V_105 * V_101 )
V_103 = V_105 * V_101 ;
if ( V_103 >= V_101 ) {
V_103 -= V_101 ;
V_104 = true ;
}
V_100 -> V_95 = V_103 ;
return V_104 ;
}
static void F_60 ( struct V_61 * V_62 )
{
struct V_3 * V_4 = F_31 ( V_62 , struct V_3 , V_106 ) ;
F_3 ( & V_7 ) ;
F_10 ( & V_4 -> V_8 , & V_8 ) ;
F_5 ( & V_7 ) ;
F_16 ( & V_15 , V_16 ) ;
}
void F_61 ( int V_28 )
{
struct V_3 * V_107 , * V_108 , * V_109 ;
struct V_35 * V_36 = F_38 ( V_28 ) ;
F_47 ( & V_36 -> V_85 ) ;
V_107 = V_36 -> V_38 ;
if ( V_107 == V_66 )
goto V_110;
V_108 = V_66 ;
V_109 = F_62 ( & V_36 -> V_38 , V_107 , V_108 ) ;
if ( V_109 == V_107 ) {
V_36 -> V_68 = 0 ;
F_37 ( & V_109 -> V_106 , F_60 ) ;
}
V_110:
F_49 ( & V_36 -> V_85 ) ;
}
