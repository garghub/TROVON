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
static void F_10 ( struct V_8 * V_9 ,
T_1 V_24 , T_1 V_25 )
{
struct V_1 * V_2 ;
T_2 V_11 ;
unsigned char * V_26 ;
T_1 V_27 , V_28 ;
T_1 V_29 = F_11 ( V_9 -> V_30 ) / 512 ;
int V_31 = 0 ;
int V_32 ;
V_27 = V_24 ;
V_28 = V_25 ;
while ( 1 ) {
if ( ++ V_31 > 100 )
return;
if ( V_9 -> V_33 == V_9 -> V_34 )
return;
V_26 = F_8 ( V_9 , V_27 , & V_11 ) ;
if ( ! V_26 )
return;
if ( ! F_6 ( V_26 + 510 ) )
goto V_35;
V_2 = (struct V_1 * ) ( V_26 + 0x1be ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ , V_2 ++ ) {
T_1 V_36 , V_37 , V_33 ;
if ( ! F_1 ( V_2 ) || F_4 ( V_2 ) )
continue;
V_36 = F_3 ( V_2 ) * V_29 ;
V_37 = F_1 ( V_2 ) * V_29 ;
V_33 = V_27 + V_36 ;
if ( V_32 >= 2 ) {
if ( V_36 + V_37 > V_28 )
continue;
if ( V_33 < V_24 )
continue;
if ( V_33 + V_37 > V_24 + V_25 )
continue;
}
F_12 ( V_9 , V_9 -> V_33 , V_33 , V_37 ) ;
if ( F_5 ( V_2 ) == V_21 )
V_9 -> V_38 [ V_9 -> V_33 ] . V_39 = V_40 ;
V_31 = 0 ;
if ( ++ V_9 -> V_33 == V_9 -> V_34 )
goto V_35;
}
V_2 -= 4 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ , V_2 ++ )
if ( F_1 ( V_2 ) && F_4 ( V_2 ) )
break;
if ( V_32 == 4 )
goto V_35;
V_27 = V_24 + F_3 ( V_2 ) * V_29 ;
V_28 = F_1 ( V_2 ) * V_29 ;
F_9 ( V_11 ) ;
}
V_35:
F_9 ( V_11 ) ;
}
static void F_13 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_14
T_2 V_11 ;
struct V_43 * V_44 ;
int V_32 ;
short V_45 ;
V_44 = F_8 ( V_9 , V_41 + 1 , & V_11 ) ;
if ( ! V_44 )
return;
if ( F_15 ( V_44 -> V_46 ) != V_47 ) {
F_9 ( V_11 ) ;
return;
}
{
char V_48 [ 1 + V_49 + 10 + 11 + 1 ] ;
snprintf ( V_48 , sizeof( V_48 ) , L_1 , V_9 -> V_50 , V_42 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
}
if ( F_15 ( V_44 -> V_53 ) != 1 ) {
char V_48 [ 64 ] ;
snprintf ( V_48 , sizeof( V_48 ) , L_2 ,
F_15 ( V_44 -> V_53 ) ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
F_9 ( V_11 ) ;
return;
}
V_45 = F_17 ( V_44 -> V_54 ) > 8 ? V_55 : 8 ;
for ( V_32 = 0 ; V_32 < V_45 && V_9 -> V_33 < V_9 -> V_34 ; V_32 ++ ) {
struct V_56 * V_57 = & V_44 -> V_58 [ V_32 ] ;
char V_48 [ 3 + 10 + 1 + 1 ] ;
if ( V_57 -> V_59 == 0 )
continue;
snprintf ( V_48 , sizeof( V_48 ) , L_3 , V_32 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
F_12 ( V_9 , V_9 -> V_33 ++ ,
F_15 ( V_57 -> V_60 ) + V_41 ,
F_15 ( V_57 -> V_59 ) ) ;
}
F_9 ( V_11 ) ;
F_16 ( V_9 -> V_51 , L_4 , V_52 ) ;
#endif
}
static void F_18 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 , char * V_61 ,
int V_62 )
{
T_2 V_11 ;
struct V_63 * V_64 ;
struct V_65 * V_2 ;
char V_48 [ 64 ] ;
V_64 = F_8 ( V_9 , V_41 + 1 , & V_11 ) ;
if ( ! V_64 )
return;
if ( F_15 ( V_64 -> V_66 ) != V_67 ) {
F_9 ( V_11 ) ;
return;
}
snprintf ( V_48 , sizeof( V_48 ) , L_5 , V_9 -> V_50 , V_42 , V_61 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
if ( F_17 ( V_64 -> V_68 ) < V_62 )
V_62 = F_17 ( V_64 -> V_68 ) ;
for ( V_2 = V_64 -> V_69 ; V_2 - V_64 -> V_69 < V_62 ; V_2 ++ ) {
T_1 V_70 , V_71 ;
if ( V_9 -> V_33 == V_9 -> V_34 )
break;
if ( V_2 -> V_72 == V_73 )
continue;
V_70 = F_15 ( V_2 -> V_74 ) ;
V_71 = F_15 ( V_2 -> V_75 ) ;
if ( V_41 == V_70 && V_37 == V_71 )
continue;
if ( V_41 > V_70 || V_41 + V_37 < V_70 + V_71 ) {
F_16 ( V_9 -> V_51 , L_6 , V_52 ) ;
continue;
}
F_12 ( V_9 , V_9 -> V_33 ++ , V_70 , V_71 ) ;
}
F_9 ( V_11 ) ;
if ( F_17 ( V_64 -> V_68 ) > V_62 ) {
snprintf ( V_48 , sizeof( V_48 ) , L_7 ,
F_17 ( V_64 -> V_68 ) - V_62 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
}
F_16 ( V_9 -> V_51 , L_4 , V_52 ) ;
}
static void F_19 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_20
F_18 ( V_9 , V_41 , V_37 , V_42 , L_8 , V_76 ) ;
#endif
}
static void F_21 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_20
F_18 ( V_9 , V_41 , V_37 , V_42 , L_9 , V_76 ) ;
#endif
}
static void F_22 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_20
F_18 ( V_9 , V_41 , V_37 , V_42 , L_10 ,
V_77 ) ;
#endif
}
static void F_23 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_24
T_2 V_11 ;
struct V_78 * V_64 ;
struct V_79 * V_2 ;
V_64 = F_8 ( V_9 , V_41 + 29 , & V_11 ) ;
if ( ! V_64 )
return;
if ( F_15 ( V_64 -> V_66 ) != V_80 ||
F_15 ( V_64 -> V_81 . V_82 ) != V_83 ) {
F_9 ( V_11 ) ;
return;
}
{
char V_48 [ 1 + V_49 + 10 + 12 + 1 ] ;
snprintf ( V_48 , sizeof( V_48 ) , L_11 , V_9 -> V_50 , V_42 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
}
V_2 = & V_64 -> V_81 . V_58 [ 1 ] ;
while ( V_2 - & V_64 -> V_81 . V_58 [ 0 ] < V_84 ) {
if ( V_9 -> V_33 == V_9 -> V_34 )
break;
if ( V_2 -> V_85 != V_86 )
F_12 ( V_9 , V_9 -> V_33 ++ ,
F_15 ( V_2 -> F_3 ) ,
F_15 ( V_2 -> F_1 ) ) ;
V_2 ++ ;
}
F_9 ( V_11 ) ;
F_16 ( V_9 -> V_51 , L_4 , V_52 ) ;
#endif
}
static void F_25 ( struct V_8 * V_9 ,
T_1 V_41 , T_1 V_37 , int V_42 )
{
#ifdef F_26
T_2 V_11 ;
unsigned char * V_26 ;
struct V_1 * V_2 ;
int V_32 ;
V_26 = F_8 ( V_9 , V_41 , & V_11 ) ;
if ( ! V_26 )
return;
V_2 = (struct V_1 * ) ( V_26 + 0x1be ) ;
if ( F_6 ( V_26 + 510 ) &&
F_5 ( V_2 ) == V_87 ) {
char V_48 [ 1 + V_49 + 10 + 9 + 1 ] ;
snprintf ( V_48 , sizeof( V_48 ) , L_12 , V_9 -> V_50 , V_42 ) ;
F_16 ( V_9 -> V_51 , V_48 , V_52 ) ;
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ , V_2 ++ ) {
if ( V_9 -> V_33 == V_9 -> V_34 )
break;
if ( F_5 ( V_2 ) == V_87 )
F_12 ( V_9 , V_9 -> V_33 ++ ,
F_3 ( V_2 ) , F_1 ( V_2 ) ) ;
}
F_16 ( V_9 -> V_51 , L_4 , V_52 ) ;
}
F_9 ( V_11 ) ;
#endif
}
int F_27 ( struct V_8 * V_9 )
{
T_1 V_29 = F_11 ( V_9 -> V_30 ) / 512 ;
T_2 V_11 ;
unsigned char * V_26 ;
struct V_1 * V_2 ;
struct V_89 * V_90 ;
int V_13 ;
V_26 = F_8 ( V_9 , 0 , & V_11 ) ;
if ( ! V_26 )
return - 1 ;
if ( ! F_6 ( V_26 + 510 ) ) {
F_9 ( V_11 ) ;
return 0 ;
}
if ( F_7 ( V_9 , V_26 ) ) {
F_9 ( V_11 ) ;
F_16 ( V_9 -> V_51 , L_13 , V_52 ) ;
return 0 ;
}
V_2 = (struct V_1 * ) ( V_26 + 0x1be ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
if ( V_2 -> V_91 != 0 && V_2 -> V_91 != 0x80 ) {
V_90 = (struct V_89 * ) V_26 ;
if ( V_13 == 1 && V_90 -> V_92 && V_90 -> V_93
&& F_28 ( V_90 -> V_94 ) ) {
F_16 ( V_9 -> V_51 , L_14 , V_52 ) ;
F_9 ( V_11 ) ;
return 1 ;
} else {
F_9 ( V_11 ) ;
return 0 ;
}
}
}
#ifdef F_29
V_2 = (struct V_1 * ) ( V_26 + 0x1be ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
if ( F_5 ( V_2 ) == V_95 ) {
F_9 ( V_11 ) ;
return 0 ;
}
}
#endif
V_2 = (struct V_1 * ) ( V_26 + 0x1be ) ;
V_9 -> V_33 = 5 ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
T_1 V_96 = F_3 ( V_2 ) * V_29 ;
T_1 V_37 = F_1 ( V_2 ) * V_29 ;
if ( ! V_37 )
continue;
if ( F_4 ( V_2 ) ) {
T_1 V_97 = 2 ;
V_97 = F_30 ( V_37 , F_31 ( V_29 , V_97 ) ) ;
F_12 ( V_9 , V_13 , V_96 , V_97 ) ;
F_16 ( V_9 -> V_51 , L_15 , V_52 ) ;
F_10 ( V_9 , V_96 , V_37 ) ;
F_16 ( V_9 -> V_51 , L_16 , V_52 ) ;
continue;
}
F_12 ( V_9 , V_13 , V_96 , V_37 ) ;
if ( F_5 ( V_2 ) == V_21 )
V_9 -> V_38 [ V_13 ] . V_39 = V_40 ;
if ( F_5 ( V_2 ) == V_98 )
F_16 ( V_9 -> V_51 , L_17 , V_52 ) ;
if ( F_5 ( V_2 ) == V_99 )
F_16 ( V_9 -> V_51 , L_18 , V_52 ) ;
}
F_16 ( V_9 -> V_51 , L_14 , V_52 ) ;
V_2 = (struct V_1 * ) ( 0x1be + V_26 ) ;
for ( V_13 = 1 ; V_13 <= 4 ; V_13 ++ , V_2 ++ ) {
unsigned char V_100 = F_5 ( V_2 ) ;
int V_97 ;
if ( ! F_1 ( V_2 ) )
continue;
for ( V_97 = 0 ; V_101 [ V_97 ] . V_102 && V_100 != V_101 [ V_97 ] . V_100 ; V_97 ++ )
;
if ( ! V_101 [ V_97 ] . V_102 )
continue;
V_101 [ V_97 ] . V_102 ( V_9 , F_3 ( V_2 ) * V_29 ,
F_1 ( V_2 ) * V_29 , V_13 ) ;
}
F_9 ( V_11 ) ;
return 1 ;
}
