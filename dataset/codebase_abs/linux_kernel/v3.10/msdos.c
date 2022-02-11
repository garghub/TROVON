static inline T_1 F_1 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( & V_2 -> F_1 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 )
{
return ( T_1 ) F_2 ( & V_2 -> F_3 ) ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return ( F_5 ( V_2 ) == V_3 ||
F_5 ( V_2 ) == V_4 ||
F_5 ( V_2 ) == V_5 ) ;
}
static inline int
F_6 ( unsigned char * V_2 )
{
return ( V_2 [ 0 ] == V_6 && V_2 [ 1 ] == V_7 ) ;
}
static int F_7 ( struct V_8 * V_9 , unsigned char * V_2 )
{
struct V_1 * V_10 = (struct V_1 * ) ( V_2 + 0x1be ) ;
T_2 V_11 ;
unsigned char * V_12 ;
int V_13 , V_14 = 0 ;
if ( ! ( V_2 [ 0 ] == V_15 &&
V_2 [ 1 ] == V_16 &&
V_2 [ 2 ] == V_17 &&
V_2 [ 3 ] == V_18 ) )
return 0 ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_10 ++ ) {
if ( V_10 -> V_19 == V_20 ||
V_10 -> V_19 == V_21 ||
V_10 -> V_19 == V_22 ||
V_10 -> V_19 == V_23 ||
F_4 ( V_10 ) )
return 0 ;
}
V_12 = F_8 ( V_9 , 7 , & V_11 ) ;
if ( V_12 ) {
if ( V_12 [ 0 ] == '_' && V_12 [ 1 ] == 'L' && V_12 [ 2 ] == 'V' && V_12 [ 3 ] == 'M' )
V_14 = 1 ;
F_9 ( V_11 ) ;
} ;
return V_14 ;
}
static void F_10 ( struct V_8 * V_9 , int V_13 ,
T_3 V_24 )
{
struct V_25 * V_26 = & V_9 -> V_27 [ V_13 ] . V_26 ;
snprintf ( V_26 -> V_28 , sizeof( V_26 -> V_28 ) , L_1 , V_24 ,
V_13 ) ;
V_26 -> V_29 [ 0 ] = 0 ;
V_9 -> V_27 [ V_13 ] . V_30 = true ;
}
static void F_11 ( struct V_8 * V_9 ,
T_1 V_31 , T_1 V_32 ,
T_3 V_24 )
{
struct V_1 * V_2 ;
T_2 V_11 ;
unsigned char * V_33 ;
T_1 V_34 , V_35 ;
T_1 V_36 = F_12 ( V_9 -> V_37 ) / 512 ;
int V_38 = 0 ;
int V_39 ;
V_34 = V_31 ;
V_35 = V_32 ;
while ( 1 ) {
if ( ++ V_38 > 100 )
return;
if ( V_9 -> V_40 == V_9 -> V_41 )
return;
V_33 = F_8 ( V_9 , V_34 , & V_11 ) ;
if ( ! V_33 )
return;
if ( ! F_6 ( V_33 + 510 ) )
goto V_42;
V_2 = (struct V_1 * ) ( V_33 + 0x1be ) ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ ) {
T_1 V_43 , V_44 , V_40 ;
if ( ! F_1 ( V_2 ) || F_4 ( V_2 ) )
continue;
V_43 = F_3 ( V_2 ) * V_36 ;
V_44 = F_1 ( V_2 ) * V_36 ;
V_40 = V_34 + V_43 ;
if ( V_39 >= 2 ) {
if ( V_43 + V_44 > V_35 )
continue;
if ( V_40 < V_31 )
continue;
if ( V_40 + V_44 > V_31 + V_32 )
continue;
}
F_13 ( V_9 , V_9 -> V_40 , V_40 , V_44 ) ;
F_10 ( V_9 , V_9 -> V_40 , V_24 ) ;
if ( F_5 ( V_2 ) == V_21 )
V_9 -> V_27 [ V_9 -> V_40 ] . V_45 = V_46 ;
V_38 = 0 ;
if ( ++ V_9 -> V_40 == V_9 -> V_41 )
goto V_42;
}
V_2 -= 4 ;
for ( V_39 = 0 ; V_39 < 4 ; V_39 ++ , V_2 ++ )
if ( F_1 ( V_2 ) && F_4 ( V_2 ) )
break;
if ( V_39 == 4 )
goto V_42;
V_34 = V_31 + F_3 ( V_2 ) * V_36 ;
V_35 = F_1 ( V_2 ) * V_36 ;
F_9 ( V_11 ) ;
}
V_42:
F_9 ( V_11 ) ;
}
static void F_14 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_15
T_2 V_11 ;
struct V_49 * V_50 ;
int V_39 ;
short V_51 ;
V_50 = F_8 ( V_9 , V_47 + 1 , & V_11 ) ;
if ( ! V_50 )
return;
if ( F_16 ( V_50 -> V_52 ) != V_53 ) {
F_9 ( V_11 ) ;
return;
}
{
char V_54 [ 1 + V_55 + 10 + 11 + 1 ] ;
snprintf ( V_54 , sizeof( V_54 ) , L_2 , V_9 -> V_56 , V_48 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
}
if ( F_16 ( V_50 -> V_59 ) != 1 ) {
char V_54 [ 64 ] ;
snprintf ( V_54 , sizeof( V_54 ) , L_3 ,
F_16 ( V_50 -> V_59 ) ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
F_9 ( V_11 ) ;
return;
}
V_51 = F_18 ( V_50 -> V_60 ) > 8 ? V_61 : 8 ;
for ( V_39 = 0 ; V_39 < V_51 && V_9 -> V_40 < V_9 -> V_41 ; V_39 ++ ) {
struct V_62 * V_63 = & V_50 -> V_64 [ V_39 ] ;
char V_54 [ 3 + 10 + 1 + 1 ] ;
if ( V_63 -> V_65 == 0 )
continue;
snprintf ( V_54 , sizeof( V_54 ) , L_4 , V_39 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
F_13 ( V_9 , V_9 -> V_40 ++ ,
F_16 ( V_63 -> V_66 ) + V_47 ,
F_16 ( V_63 -> V_65 ) ) ;
}
F_9 ( V_11 ) ;
F_17 ( V_9 -> V_57 , L_5 , V_58 ) ;
#endif
}
static void F_19 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 , char * V_67 ,
int V_68 )
{
T_2 V_11 ;
struct V_69 * V_70 ;
struct V_71 * V_2 ;
char V_54 [ 64 ] ;
V_70 = F_8 ( V_9 , V_47 + 1 , & V_11 ) ;
if ( ! V_70 )
return;
if ( F_16 ( V_70 -> V_72 ) != V_73 ) {
F_9 ( V_11 ) ;
return;
}
snprintf ( V_54 , sizeof( V_54 ) , L_6 , V_9 -> V_56 , V_48 , V_67 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
if ( F_18 ( V_70 -> V_74 ) < V_68 )
V_68 = F_18 ( V_70 -> V_74 ) ;
for ( V_2 = V_70 -> V_75 ; V_2 - V_70 -> V_75 < V_68 ; V_2 ++ ) {
T_1 V_76 , V_77 ;
if ( V_9 -> V_40 == V_9 -> V_41 )
break;
if ( V_2 -> V_78 == V_79 )
continue;
V_76 = F_16 ( V_2 -> V_80 ) ;
V_77 = F_16 ( V_2 -> V_81 ) ;
if ( V_47 == V_76 && V_44 == V_77 )
continue;
if ( V_47 > V_76 || V_47 + V_44 < V_76 + V_77 ) {
F_17 ( V_9 -> V_57 , L_7 , V_58 ) ;
continue;
}
F_13 ( V_9 , V_9 -> V_40 ++ , V_76 , V_77 ) ;
}
F_9 ( V_11 ) ;
if ( F_18 ( V_70 -> V_74 ) > V_68 ) {
snprintf ( V_54 , sizeof( V_54 ) , L_8 ,
F_18 ( V_70 -> V_74 ) - V_68 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
}
F_17 ( V_9 -> V_57 , L_5 , V_58 ) ;
}
static void F_20 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_21
F_19 ( V_9 , V_47 , V_44 , V_48 , L_9 , V_82 ) ;
#endif
}
static void F_22 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_21
F_19 ( V_9 , V_47 , V_44 , V_48 , L_10 , V_82 ) ;
#endif
}
static void F_23 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_21
F_19 ( V_9 , V_47 , V_44 , V_48 , L_11 ,
V_83 ) ;
#endif
}
static void F_24 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_25
T_2 V_11 ;
struct V_84 * V_70 ;
struct V_85 * V_2 ;
V_70 = F_8 ( V_9 , V_47 + 29 , & V_11 ) ;
if ( ! V_70 )
return;
if ( F_16 ( V_70 -> V_72 ) != V_86 ||
F_16 ( V_70 -> V_87 . V_88 ) != V_89 ) {
F_9 ( V_11 ) ;
return;
}
{
char V_54 [ 1 + V_55 + 10 + 12 + 1 ] ;
snprintf ( V_54 , sizeof( V_54 ) , L_12 , V_9 -> V_56 , V_48 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
}
V_2 = & V_70 -> V_87 . V_64 [ 1 ] ;
while ( V_2 - & V_70 -> V_87 . V_64 [ 0 ] < V_90 ) {
if ( V_9 -> V_40 == V_9 -> V_41 )
break;
if ( V_2 -> V_91 != V_92 )
F_13 ( V_9 , V_9 -> V_40 ++ ,
F_16 ( V_2 -> F_3 ) ,
F_16 ( V_2 -> F_1 ) ) ;
V_2 ++ ;
}
F_9 ( V_11 ) ;
F_17 ( V_9 -> V_57 , L_5 , V_58 ) ;
#endif
}
static void F_26 ( struct V_8 * V_9 ,
T_1 V_47 , T_1 V_44 , int V_48 )
{
#ifdef F_27
T_2 V_11 ;
unsigned char * V_33 ;
struct V_1 * V_2 ;
int V_39 ;
V_33 = F_8 ( V_9 , V_47 , & V_11 ) ;
if ( ! V_33 )
return;
V_2 = (struct V_1 * ) ( V_33 + 0x1be ) ;
if ( F_6 ( V_33 + 510 ) &&
F_5 ( V_2 ) == V_93 ) {
char V_54 [ 1 + V_55 + 10 + 9 + 1 ] ;
snprintf ( V_54 , sizeof( V_54 ) , L_13 , V_9 -> V_56 , V_48 ) ;
F_17 ( V_9 -> V_57 , V_54 , V_58 ) ;
for ( V_39 = 0 ; V_39 < V_94 ; V_39 ++ , V_2 ++ ) {
if ( V_9 -> V_40 == V_9 -> V_41 )
break;
if ( F_5 ( V_2 ) == V_93 )
F_13 ( V_9 , V_9 -> V_40 ++ ,
F_3 ( V_2 ) , F_1 ( V_2 ) ) ;
}
F_17 ( V_9 -> V_57 , L_5 , V_58 ) ;
}
F_9 ( V_11 ) ;
#endif
}
int F_28 ( struct V_8 * V_9 )
{
T_1 V_36 = F_12 ( V_9 -> V_37 ) / 512 ;
T_2 V_11 ;
unsigned char * V_33 ;
struct V_1 * V_2 ;
struct V_95 * V_96 ;
int V_13 ;
T_3 V_24 ;
V_33 = F_8 ( V_9 , 0 , & V_11 ) ;
if ( ! V_33 )
return - 1 ;
if ( F_7 ( V_9 , V_33 ) ) {
F_9 ( V_11 ) ;
F_17 ( V_9 -> V_57 , L_14 , V_58 ) ;
return 0 ;
}
if ( ! F_6 ( V_33 + 510 ) ) {
F_9 ( V_11 ) ;
return 0 ;
}
V_2 = (struct V_1 * ) ( V_33 + 0x1be ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
if ( V_2 -> V_97 != 0 && V_2 -> V_97 != 0x80 ) {
V_96 = (struct V_95 * ) V_33 ;
if ( V_13 == 1 && V_96 -> V_98 && V_96 -> V_99
&& F_29 ( V_96 -> V_100 ) ) {
F_17 ( V_9 -> V_57 , L_15 , V_58 ) ;
F_9 ( V_11 ) ;
return 1 ;
} else {
F_9 ( V_11 ) ;
return 0 ;
}
}
}
#ifdef F_30
V_2 = (struct V_1 * ) ( V_33 + 0x1be ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
if ( F_5 ( V_2 ) == V_101 ) {
F_9 ( V_11 ) ;
return 0 ;
}
}
#endif
V_2 = (struct V_1 * ) ( V_33 + 0x1be ) ;
V_24 = F_31 ( ( V_102 * ) ( V_33 + 0x1b8 ) ) ;
V_9 -> V_40 = 5 ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
T_1 V_103 = F_3 ( V_2 ) * V_36 ;
T_1 V_44 = F_1 ( V_2 ) * V_36 ;
if ( ! V_44 )
continue;
if ( F_4 ( V_2 ) ) {
T_1 V_104 = 2 ;
V_104 = F_32 ( V_44 , F_33 ( V_36 , V_104 ) ) ;
F_13 ( V_9 , V_13 , V_103 , V_104 ) ;
F_17 ( V_9 -> V_57 , L_16 , V_58 ) ;
F_11 ( V_9 , V_103 , V_44 , V_24 ) ;
F_17 ( V_9 -> V_57 , L_17 , V_58 ) ;
continue;
}
F_13 ( V_9 , V_13 , V_103 , V_44 ) ;
F_10 ( V_9 , V_13 , V_24 ) ;
if ( F_5 ( V_2 ) == V_21 )
V_9 -> V_27 [ V_13 ] . V_45 = V_46 ;
if ( F_5 ( V_2 ) == V_105 )
F_17 ( V_9 -> V_57 , L_18 , V_58 ) ;
if ( F_5 ( V_2 ) == V_106 )
F_17 ( V_9 -> V_57 , L_19 , V_58 ) ;
}
F_17 ( V_9 -> V_57 , L_15 , V_58 ) ;
V_2 = (struct V_1 * ) ( 0x1be + V_33 ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
unsigned char V_107 = F_5 ( V_2 ) ;
int V_104 ;
if ( ! F_1 ( V_2 ) )
continue;
for ( V_104 = 0 ; V_108 [ V_104 ] . V_109 && V_107 != V_108 [ V_104 ] . V_107 ; V_104 ++ )
;
if ( ! V_108 [ V_104 ] . V_109 )
continue;
V_108 [ V_104 ] . V_109 ( V_9 , F_3 ( V_2 ) * V_36 ,
F_1 ( V_2 ) * V_36 , V_13 ) ;
}
F_9 ( V_11 ) ;
return 1 ;
}
