static int F_1 ( void )
{
int V_1 , V_2 = 0 ;
struct V_3 * V_4 =
F_2 ( V_5 -> V_6 -> V_7 ) ;
if ( V_8 ) {
char * V_9 = V_8 ;
V_2 = F_3 ( V_8 , & V_8 ) >> 20 ;
V_8 = V_9 ;
for ( V_1 = 0 ; V_1 < V_5 -> V_6 -> V_10 ; V_1 ++ )
if ( V_2 == V_4 [ V_1 ] . V_2 )
break;
if ( V_1 == V_5 -> V_6 -> V_10 ) {
F_4 ( & V_5 -> V_11 -> V_11 , L_1
L_2 ) ;
V_2 = 0 ;
V_8 = NULL ;
}
}
if ( ! V_2 ) {
for ( V_1 = 0 ; V_1 < V_5 -> V_6 -> V_10 ; V_1 ++ )
if ( V_4 [ V_1 ] . V_2 == V_12 )
break;
}
V_5 -> V_13 =
V_5 -> V_14 = ( void * ) ( V_4 + V_1 ) ;
V_5 -> V_15 = V_1 ;
return V_4 [ V_1 ] . V_2 ;
}
static void F_5 ( struct V_16 * V_17 )
{
T_1 V_18 = V_19 ;
if ( V_20 )
V_18 |= V_21 ;
F_6 ( V_5 -> V_11 , V_22 ,
V_18 | V_23 ) ;
F_6 ( V_5 -> V_11 , V_22 , V_18 ) ;
if ( ! V_17 && V_24 <= 0x30 ) {
F_6 ( V_5 -> V_11 , V_22 ,
V_18 | V_25 ) ;
F_6 ( V_5 -> V_11 , V_22 ,
V_18 ) ;
}
}
static void F_7 ( void )
{
T_1 V_26 ;
F_8 ( V_5 -> V_11 , V_22 , & V_26 ) ;
if ( ! ( V_26 & V_19 ) )
return;
V_26 |= V_23 ;
F_6 ( V_5 -> V_11 , V_22 , V_26 ) ;
F_6 ( V_5 -> V_11 , V_22 , 0 ) ;
if ( V_24 <= 0x30 ) {
F_6 ( V_5 -> V_11 , V_22 ,
V_25 ) ;
F_6 ( V_5 -> V_11 , V_22 ,
0 ) ;
}
}
static int F_9 ( void )
{
struct V_3 * V_14 ;
V_14 = F_2 ( V_5 -> V_14 ) ;
F_10 ( & V_5 -> V_11 -> V_11 , L_3 ,
V_14 -> V_27 ) ;
F_6 ( V_5 -> V_11 ,
V_28 ,
( V_5 -> V_29 & 0xfffff000 )
| V_14 -> V_27 ) ;
V_5 -> V_30 = 0 ;
#ifdef F_11
F_6 ( V_5 -> V_11 , V_31 ,
( V_5 -> V_29 >> 32 ) & 0xf ) ;
#else
F_6 ( V_5 -> V_11 ,
V_31 , V_5 -> V_30 ) ;
#endif
if ( V_20 ) {
F_6 ( V_5 -> V_11 ,
V_32 ,
F_12 ( V_5 -> V_33 ) >> 12 ) ;
}
return 0 ;
}
static int F_13 ( struct V_16 * V_17 , T_2 V_34 , int type )
{
int V_1 , V_35 ;
void * V_36 ;
T_1 * V_37 ;
int V_38 ;
if ( type != V_17 -> type )
return - V_39 ;
V_38 = V_5 -> V_6 -> V_40 ( V_5 , type ) ;
if ( V_38 != 0 ) {
return - V_39 ;
}
if ( V_17 -> V_41 == 0 )
return 0 ;
V_36 = V_5 -> V_14 ;
V_35 = F_2 ( V_36 ) -> V_35 ;
if ( ( V_34 + V_17 -> V_41 ) > V_35 )
return - V_39 ;
V_37 = ( T_1 * ) & V_5 -> V_42 [ V_34 ] ;
for ( V_1 = 0 ; V_1 < V_17 -> V_41 ; ++ V_1 ) {
if ( V_37 [ V_1 ] != V_43 ) {
F_10 ( & V_5 -> V_11 -> V_11 ,
L_4 ,
V_1 , V_37 [ V_1 ] ) ;
return - V_44 ;
}
}
for ( V_1 = 0 ; V_1 < V_17 -> V_41 ; V_1 ++ ) {
if ( V_20 )
V_37 [ V_1 ] = ( F_12 ( V_17 -> V_45 [ V_1 ] ) >> V_46 ) | 0x80000000UL ;
else
V_37 [ V_1 ] = F_14 ( ( F_12 ( V_17 -> V_45 [ V_1 ] ) & 0xFFFFF000UL ) |
0x1UL ) ;
F_15 ( ( unsigned long ) F_16 ( F_12 ( V_17 -> V_45 [ V_1 ] ) ) ,
( unsigned long ) F_16 ( F_12 ( V_17 -> V_45 [ V_1 ] ) ) + 0x1000 ) ;
}
F_17 () ;
F_5 ( V_17 ) ;
return 0 ;
}
int F_18 ( struct V_16 * V_17 , T_2 V_34 , int type )
{
T_3 V_1 ;
T_1 * V_37 ;
int V_38 ;
if ( type != V_17 -> type )
return - V_39 ;
V_38 = V_5 -> V_6 -> V_40 ( V_5 , type ) ;
if ( V_38 != 0 ) {
return - V_39 ;
}
if ( V_17 -> V_41 == 0 )
return 0 ;
V_37 = ( T_1 * ) & V_5 -> V_42 [ V_34 ] ;
for ( V_1 = 0 ; V_1 < V_17 -> V_41 ; ++ V_1 ) {
V_37 [ V_1 ] = V_43 ;
}
F_17 () ;
F_5 ( V_17 ) ;
return 0 ;
}
static void F_19 ( struct V_47 * V_48 , T_1 V_49 )
{
T_1 V_50 , V_51 , V_52 ;
int V_53 ;
F_8 ( V_48 -> V_11 ,
V_48 -> V_54 + V_55 ,
& V_52 ) ;
V_50 = F_20 ( V_48 , V_49 , V_52 ) ;
V_50 |= V_56 ;
if ( V_24 == 0x21 ) {
V_50 &= ~ V_57 ;
}
if ( ( V_24 >= 0x30 ) && ( V_24 <= 0x33 ) ) {
if ( ( V_50 >> V_58 ) > 7 )
V_50 = ( V_50 & ~ V_59 )
| ( 7 << V_58 ) ;
}
F_5 ( NULL ) ;
V_53 = 0 ;
do {
F_6 ( V_48 -> V_11 ,
V_48 -> V_54 + V_60 ,
V_50 ) ;
F_8 ( V_48 -> V_11 ,
V_48 -> V_54 + V_60 ,
& V_51 ) ;
} while ( ( V_51 & V_56 ) == 0 && ++ V_53 < 1000 );
if ( ( V_51 & V_56 ) == 0 )
F_4 ( & V_48 -> V_11 -> V_11 , L_5
L_6 ) ;
if ( V_24 >= 0x30 ) {
F_21 ( V_50 , ( V_52 & V_61 ) != 0 ) ;
} else {
F_21 ( V_50 , false ) ;
}
F_5 ( NULL ) ;
}
static int F_22 ( struct V_62 * V_63 )
{
struct V_47 * V_48 ;
T_1 V_64 ;
T_4 V_65 ;
struct V_62 * V_66 = NULL ;
V_48 = F_23 ( V_63 ) ;
if ( V_48 == NULL )
return - V_67 ;
if ( V_48 -> V_68 )
return 0 ;
F_24 (device) {
if ( V_66 == V_63 )
continue;
if ( V_66 -> V_69 != V_63 -> V_69 )
continue;
V_65 = F_25 ( V_66 , V_70 ) ;
if ( ! V_65 )
continue;
F_8 ( V_66 , V_65 + V_60 , & V_64 ) ;
if ( ! ( V_64 & V_56 ) )
continue;
F_10 ( & V_63 -> V_11 , L_7 ,
F_26 ( V_66 ) ) ;
V_64 &= ~ V_56 ;
F_6 ( V_66 , V_65 + V_60 , V_64 ) ;
}
V_65 = F_25 ( V_63 , V_70 ) ;
F_8 ( V_63 , V_65 + V_60 , & V_64 ) ;
V_48 -> V_68 = ( void * ) ( long ) V_64 ;
if ( V_64 & V_56 ) {
F_10 ( & V_63 -> V_11 , L_8 ) ;
V_64 &= ~ V_56 ;
F_6 ( V_63 , V_65 + V_60 , V_64 ) ;
}
F_7 () ;
return 0 ;
}
static int F_27 ( struct V_62 * V_63 )
{
struct V_47 * V_48 ;
T_1 V_50 ;
V_48 = F_23 ( V_63 ) ;
if ( V_48 == NULL )
return - V_67 ;
V_50 = ( long ) V_48 -> V_68 ;
V_48 -> V_68 = NULL ;
if ( ! ( V_50 & V_56 ) )
return 0 ;
F_19 ( V_48 , V_50 ) ;
return 0 ;
}
static int F_28 ( struct V_47 * V_48 )
{
char * V_71 ;
char * V_72 ;
int V_2 ;
int V_73 ;
int V_35 ;
int V_1 ;
void * V_36 ;
struct V_74 * V_74 ;
struct V_74 * * V_45 ;
if ( V_48 -> V_6 -> V_75 == V_76 )
return - V_39 ;
V_71 = NULL ;
V_1 = V_48 -> V_15 ;
V_36 = V_48 -> V_14 ;
V_2 = V_73 = V_35 = 0 ;
do {
V_2 = F_2 ( V_36 ) -> V_2 ;
V_73 = F_2 ( V_36 ) -> V_73 ;
V_35 = F_2 ( V_36 ) -> V_35 ;
V_71 = ( char * ) F_29 ( V_77 , V_73 ) ;
if ( V_71 == NULL ) {
V_1 ++ ;
V_48 -> V_14 = F_30 ( V_48 ) ;
} else {
V_48 -> V_15 = V_1 ;
}
} while ( ! V_71 && ( V_1 < V_48 -> V_6 -> V_10 ) );
if ( V_71 == NULL )
return - V_78 ;
V_45 = F_31 ( ( 1 << V_73 ) * sizeof( struct V_74 * ) , V_77 ) ;
if ( V_45 == NULL )
goto V_79;
V_72 = V_71 + ( ( V_80 * ( 1 << V_73 ) ) - 1 ) ;
for ( V_74 = F_32 ( V_71 ) , V_1 = 0 ; V_74 <= F_32 ( V_72 ) ;
V_74 ++ , V_1 ++ ) {
F_33 ( V_74 ) ;
V_45 [ V_1 ] = V_74 ;
}
V_48 -> V_81 = ( T_1 * ) V_71 ;
F_15 ( ( unsigned long ) V_71 ,
( unsigned long ) V_72 + 1 ) ;
V_48 -> V_42 = F_34 ( V_45 , ( 1 << V_73 ) , 0 , V_82 ) ;
if ( V_48 -> V_42 == NULL )
goto V_79;
V_48 -> V_29 = F_35 ( V_71 ) ;
if ( V_20 )
V_43 = ( F_12 ( V_5 -> V_33 ) >> V_46 ) | 0x80000000UL ;
else
V_43 = F_14 ( ( F_12 ( V_5 -> V_33 ) & 0xFFFFF000UL ) |
0x1UL ) ;
for ( V_1 = 0 ; V_1 < V_35 ; V_1 ++ )
V_48 -> V_42 [ V_1 ] = V_43 ;
return 0 ;
V_79:
F_36 ( V_45 ) ;
if ( V_71 )
F_37 ( ( unsigned long ) V_71 , V_73 ) ;
return - V_78 ;
}
static int F_38 ( struct V_47 * V_48 )
{
int V_73 ;
char * V_71 , * V_72 ;
void * V_36 ;
struct V_74 * V_74 ;
V_36 = V_48 -> V_14 ;
V_73 = F_2 ( V_36 ) -> V_73 ;
F_39 ( V_48 -> V_42 ) ;
V_71 = ( char * ) V_48 -> V_81 ;
V_72 = V_71 + ( ( V_80 * ( 1 << V_73 ) ) - 1 ) ;
for ( V_74 = F_32 ( V_71 ) ; V_74 <= F_32 ( V_72 ) ; V_74 ++ )
F_40 ( V_74 ) ;
F_37 ( ( unsigned long ) V_48 -> V_81 , V_73 ) ;
return 0 ;
}
void F_41 ( void )
{
F_17 () ;
}
static int T_5 F_42 ( struct V_62 * V_63 ,
const struct V_83 * V_84 )
{
struct V_85 * V_86 = V_87 ;
struct V_47 * V_48 ;
struct V_88 * V_89 ;
T_4 V_90 ;
int V_91 ;
V_90 = F_25 ( V_63 , V_70 ) ;
if ( V_90 == 0 )
return - V_67 ;
for ( V_91 = 0 ; V_86 [ V_91 ] . V_92 != NULL ; ++ V_91 ) {
if ( V_63 -> V_66 == V_86 [ V_91 ] . V_93 ) {
F_10 ( & V_63 -> V_11 , L_9 ,
V_86 [ V_91 ] . V_92 ) ;
goto V_94;
}
}
F_4 ( & V_63 -> V_11 , L_10 ,
V_63 -> V_95 , V_63 -> V_66 ) ;
return - V_67 ;
V_94:
V_24 = 0 ;
V_20 = 0 ;
V_89 = F_43 ( NULL , L_11 ) ;
if ( V_89 == NULL ) {
V_20 = 1 ;
V_89 = F_43 ( NULL , L_12 ) ;
}
if ( V_89 ) {
const int * V_96 = F_44 ( V_89 ,
L_13 , NULL ) ;
if ( V_96 != NULL )
V_24 = * V_96 & 0x3f ;
F_45 ( V_89 ) ;
}
#ifdef F_46
F_47 ( V_63 , F_22 , F_27 ) ;
#endif
V_48 = F_48 () ;
if ( ! V_48 )
return - V_78 ;
if ( V_20 )
V_48 -> V_6 = & V_97 ;
else
V_48 -> V_6 = & V_98 ;
V_48 -> V_11 = V_63 ;
V_48 -> V_54 = V_90 ;
V_48 -> V_99 = V_100 ;
F_8 ( V_63 , V_90 + V_55 , & V_48 -> V_49 ) ;
F_49 ( V_63 , V_48 ) ;
return F_50 ( V_48 ) ;
}
static void T_6 F_51 ( struct V_62 * V_63 )
{
struct V_47 * V_48 = F_52 ( V_63 ) ;
#ifdef F_46
F_47 ( V_63 , NULL , NULL ) ;
#endif
F_53 ( V_48 ) ;
F_54 ( V_48 ) ;
}
static int T_7 F_55 ( void )
{
if ( V_101 )
return - V_39 ;
return F_56 ( & V_102 ) ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_102 ) ;
}
