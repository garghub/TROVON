static long long T_1 F_1 ( unsigned char * V_1 , int V_2 )
{
int V_3 ;
long long V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
V_4 = ( V_4 << 8 ) | V_1 [ V_2 - V_3 - 1 ] ;
return V_4 ;
}
static long T_1 F_2 ( void * V_5 , unsigned long V_6 )
{
return - 1 ;
}
static void T_1 F_3 ( struct V_7 * V_7 )
{
V_7 -> V_8 = V_7 -> V_9 ( ( char * ) V_7 -> V_5 , V_10 ) ;
if ( V_7 -> V_8 <= 0 )
V_7 -> error ( L_1 ) ;
V_7 -> V_1 = V_7 -> V_5 ;
V_7 -> V_11 = V_7 -> V_5 + V_7 -> V_8 ;
}
static inline void T_1 F_4 ( struct V_7 * V_7 ,
long (* V_9)( void * , unsigned long ) ,
char * V_5 , long V_8 )
{
if ( V_9 )
V_7 -> V_9 = V_9 ;
else
V_7 -> V_9 = F_2 ;
V_7 -> V_5 = ( V_12 * ) V_5 ;
V_7 -> V_8 = V_8 ;
V_7 -> V_11 = V_7 -> V_5 + V_7 -> V_8 ;
V_7 -> V_1 = V_7 -> V_5 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = 0xFFFFFFFF ;
}
static inline void T_1 F_5 ( struct V_7 * V_7 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 5 ; V_3 ++ ) {
if ( V_7 -> V_1 >= V_7 -> V_11 )
F_3 ( V_7 ) ;
V_7 -> V_13 = ( V_7 -> V_13 << 8 ) | * V_7 -> V_1 ++ ;
}
}
static void T_1 F_6 ( struct V_7 * V_7 )
{
if ( V_7 -> V_1 >= V_7 -> V_11 )
F_3 ( V_7 ) ;
V_7 -> V_14 <<= 8 ;
V_7 -> V_13 = ( V_7 -> V_13 << 8 ) | * V_7 -> V_1 ++ ;
}
static inline void T_1 F_7 ( struct V_7 * V_7 )
{
if ( V_7 -> V_14 < ( 1 << V_15 ) )
F_6 ( V_7 ) ;
}
static inline T_2 T_1 F_8 ( struct V_7 * V_7 , T_3 * V_16 )
{
F_7 ( V_7 ) ;
V_7 -> V_17 = * V_16 * ( V_7 -> V_14 >> V_18 ) ;
return V_7 -> V_17 ;
}
static inline int T_1 F_9 ( struct V_7 * V_7 , T_3 * V_16 )
{
T_2 V_19 = F_8 ( V_7 , V_16 ) ;
return V_7 -> V_13 < V_19 ;
}
static inline void T_1 F_10 ( struct V_7 * V_7 , T_3 * V_16 )
{
V_7 -> V_14 = V_7 -> V_17 ;
* V_16 += ( ( 1 << V_18 ) - * V_16 ) >> V_20 ;
}
static inline void T_1 F_11 ( struct V_7 * V_7 , T_3 * V_16 )
{
V_7 -> V_14 -= V_7 -> V_17 ;
V_7 -> V_13 -= V_7 -> V_17 ;
* V_16 -= * V_16 >> V_20 ;
}
static int T_1 F_12 ( struct V_7 * V_7 , T_3 * V_16 , int * V_21 )
{
if ( F_9 ( V_7 , V_16 ) ) {
F_10 ( V_7 , V_16 ) ;
* V_21 *= 2 ;
return 0 ;
} else {
F_11 ( V_7 , V_16 ) ;
* V_21 = * V_21 * 2 + 1 ;
return 1 ;
}
}
static inline int T_1 F_13 ( struct V_7 * V_7 )
{
F_7 ( V_7 ) ;
V_7 -> V_14 >>= 1 ;
if ( V_7 -> V_13 >= V_7 -> V_14 ) {
V_7 -> V_13 -= V_7 -> V_14 ;
return 1 ;
}
return 0 ;
}
static inline void T_1
F_14 ( struct V_7 * V_7 , T_3 * V_16 , int V_22 , int * V_21 )
{
int V_3 = V_22 ;
* V_21 = 1 ;
while ( V_3 -- )
F_12 ( V_7 , V_16 + * V_21 , V_21 ) ;
* V_21 -= 1 << V_22 ;
}
static inline T_4 T_1 F_15 ( struct V_23 * V_24 )
{
return
V_24 -> V_25 + V_24 -> V_26 ;
}
static inline V_12 T_1 F_16 ( struct V_23 * V_24 ,
T_2 V_27 )
{
if ( ! V_24 -> V_28 ) {
T_5 V_29 ;
while ( V_27 > V_24 -> V_30 -> V_31 )
V_27 -= V_24 -> V_30 -> V_31 ;
V_29 = V_24 -> V_26 - V_27 ;
return V_24 -> V_5 [ V_29 ] ;
} else {
T_2 V_29 = V_24 -> V_26 - V_27 ;
while ( V_29 >= V_24 -> V_30 -> V_31 )
V_29 += V_24 -> V_30 -> V_31 ;
return V_24 -> V_5 [ V_29 ] ;
}
}
static inline int T_1 F_17 ( struct V_23 * V_24 , V_12 V_32 )
{
V_24 -> V_5 [ V_24 -> V_26 ++ ] = V_24 -> V_33 = V_32 ;
if ( V_24 -> V_28 && V_24 -> V_26 == V_24 -> V_30 -> V_31 ) {
V_24 -> V_26 = 0 ;
V_24 -> V_25 += V_24 -> V_30 -> V_31 ;
if ( V_24 -> V_28 ( ( char * ) V_24 -> V_5 , V_24 -> V_30 -> V_31 )
!= V_24 -> V_30 -> V_31 )
return - 1 ;
}
return 0 ;
}
static inline int T_1 F_18 ( struct V_23 * V_24 , T_2 V_27 )
{
return F_17 ( V_24 , F_16 ( V_24 , V_27 ) ) ;
}
static inline int T_1 F_19 ( struct V_23 * V_24 ,
T_2 V_34 , int V_6 )
{
do {
if ( F_18 ( V_24 , V_34 ) )
return - 1 ;
V_6 -- ;
} while ( V_6 != 0 && V_24 -> V_26 < V_24 -> V_30 -> V_35 );
return V_6 ;
}
static inline int T_1 F_20 ( struct V_23 * V_24 , struct V_7 * V_7 ,
struct V_36 * V_37 , T_3 * V_16 ,
int V_38 , T_3 * V_39 ,
int V_40 , T_2 V_41 ) {
int V_42 = 1 ;
F_10 ( V_7 , V_39 ) ;
V_39 = ( V_16 + V_43 +
( V_44
* ( ( ( F_15 ( V_24 ) & V_41 ) << V_40 )
+ ( V_24 -> V_33 >> ( 8 - V_40 ) ) ) )
) ;
if ( V_37 -> V_45 >= V_46 ) {
int V_47 = F_16 ( V_24 , V_37 -> V_34 ) ;
do {
int V_48 ;
T_3 * V_49 ;
V_47 <<= 1 ;
V_48 = V_47 & 0x100 ;
V_49 = V_39 + 0x100 + V_48 + V_42 ;
if ( F_12 ( V_7 , V_49 , & V_42 ) ) {
if ( ! V_48 )
break;
} else {
if ( V_48 )
break;
}
} while ( V_42 < 0x100 );
}
while ( V_42 < 0x100 ) {
T_3 * V_49 = V_39 + V_42 ;
F_12 ( V_7 , V_49 , & V_42 ) ;
}
if ( V_37 -> V_45 < 4 )
V_37 -> V_45 = 0 ;
else if ( V_37 -> V_45 < 10 )
V_37 -> V_45 -= 3 ;
else
V_37 -> V_45 -= 6 ;
return F_17 ( V_24 , V_42 ) ;
}
static inline int T_1 F_21 ( struct V_23 * V_24 , struct V_7 * V_7 ,
struct V_36 * V_37 , T_3 * V_16 ,
int V_38 , T_3 * V_39 ) {
int V_50 ;
T_3 * V_51 ;
int V_52 ;
int V_6 ;
F_11 ( V_7 , V_39 ) ;
V_39 = V_16 + V_53 + V_37 -> V_45 ;
if ( F_9 ( V_7 , V_39 ) ) {
F_10 ( V_7 , V_39 ) ;
V_37 -> V_54 = V_37 -> V_55 ;
V_37 -> V_55 = V_37 -> V_56 ;
V_37 -> V_56 = V_37 -> V_34 ;
V_37 -> V_45 = V_37 -> V_45 < V_46 ? 0 : 3 ;
V_39 = V_16 + V_57 ;
} else {
F_11 ( V_7 , V_39 ) ;
V_39 = V_16 + V_58 + V_37 -> V_45 ;
if ( F_9 ( V_7 , V_39 ) ) {
F_10 ( V_7 , V_39 ) ;
V_39 = ( V_16 + V_59
+ ( V_37 -> V_45 <<
V_60 ) +
V_38 ) ;
if ( F_9 ( V_7 , V_39 ) ) {
F_10 ( V_7 , V_39 ) ;
V_37 -> V_45 = V_37 -> V_45 < V_46 ?
9 : 11 ;
return F_18 ( V_24 , V_37 -> V_34 ) ;
} else {
F_11 ( V_7 , V_39 ) ;
}
} else {
T_2 V_61 ;
F_11 ( V_7 , V_39 ) ;
V_39 = V_16 + V_62 + V_37 -> V_45 ;
if ( F_9 ( V_7 , V_39 ) ) {
F_10 ( V_7 , V_39 ) ;
V_61 = V_37 -> V_56 ;
} else {
F_11 ( V_7 , V_39 ) ;
V_39 = V_16 + V_63 + V_37 -> V_45 ;
if ( F_9 ( V_7 , V_39 ) ) {
F_10 ( V_7 , V_39 ) ;
V_61 = V_37 -> V_55 ;
} else {
F_11 ( V_7 , V_39 ) ;
V_61 = V_37 -> V_54 ;
V_37 -> V_54 = V_37 -> V_55 ;
}
V_37 -> V_55 = V_37 -> V_56 ;
}
V_37 -> V_56 = V_37 -> V_34 ;
V_37 -> V_34 = V_61 ;
}
V_37 -> V_45 = V_37 -> V_45 < V_46 ? 8 : 11 ;
V_39 = V_16 + V_64 ;
}
V_51 = V_39 + V_65 ;
if ( F_9 ( V_7 , V_51 ) ) {
F_10 ( V_7 , V_51 ) ;
V_51 = ( V_39 + V_66
+ ( V_38 <<
V_67 ) ) ;
V_50 = 0 ;
V_52 = V_67 ;
} else {
F_11 ( V_7 , V_51 ) ;
V_51 = V_39 + V_68 ;
if ( F_9 ( V_7 , V_51 ) ) {
F_10 ( V_7 , V_51 ) ;
V_51 = ( V_39 + V_69
+ ( V_38 <<
V_70 ) ) ;
V_50 = 1 << V_67 ;
V_52 = V_70 ;
} else {
F_11 ( V_7 , V_51 ) ;
V_51 = V_39 + V_71 ;
V_50 = ( ( 1 << V_67 )
+ ( 1 << V_70 ) ) ;
V_52 = V_72 ;
}
}
F_14 ( V_7 , V_51 , V_52 , & V_6 ) ;
V_6 += V_50 ;
if ( V_37 -> V_45 < 4 ) {
int V_73 ;
V_37 -> V_45 += V_46 ;
V_39 =
V_16 + V_74 +
( ( V_6 <
V_75 ? V_6 :
V_75 - 1 )
<< V_76 ) ;
F_14 ( V_7 , V_39 ,
V_76 ,
& V_73 ) ;
if ( V_73 >= V_77 ) {
int V_3 , V_42 ;
V_52 = ( V_73 >> 1 ) - 1 ;
V_37 -> V_34 = 2 | ( V_73 & 1 ) ;
if ( V_73 < V_78 ) {
V_37 -> V_34 <<= V_52 ;
V_39 = V_16 + V_79 +
V_37 -> V_34 - V_73 - 1 ;
} else {
V_52 -= V_80 ;
while ( V_52 -- )
V_37 -> V_34 = ( V_37 -> V_34 << 1 ) |
F_13 ( V_7 ) ;
V_39 = V_16 + V_81 ;
V_37 -> V_34 <<= V_80 ;
V_52 = V_80 ;
}
V_3 = 1 ;
V_42 = 1 ;
while ( V_52 -- ) {
if ( F_12 ( V_7 , V_39 + V_42 , & V_42 ) )
V_37 -> V_34 |= V_3 ;
V_3 <<= 1 ;
}
} else
V_37 -> V_34 = V_73 ;
if ( ++ ( V_37 -> V_34 ) == 0 )
return 0 ;
if ( V_37 -> V_34 > V_24 -> V_30 -> V_31
|| V_37 -> V_34 > F_15 ( V_24 ) )
return - 1 ;
}
V_6 += V_82 ;
return F_19 ( V_24 , V_37 -> V_34 , V_6 ) ;
}
STATIC inline int T_1 F_22 ( unsigned char * V_83 , long V_84 ,
long (* V_9)( void * , unsigned long ) ,
long (* V_28)( void * , unsigned long ) ,
unsigned char * V_85 ,
long * V_86 ,
void (* error)( char * V_87 )
)
{
struct V_88 V_30 ;
int V_40 , V_89 , V_90 ;
T_2 V_91 ;
T_2 V_41 ;
T_3 * V_16 ;
int V_92 ;
struct V_7 V_7 ;
int V_3 , V_42 ;
struct V_23 V_24 ;
struct V_36 V_37 ;
unsigned char * V_93 ;
int V_4 = - 1 ;
V_7 . error = error ;
if ( V_83 )
V_93 = V_83 ;
else
V_93 = malloc ( V_10 ) ;
if ( ! V_93 ) {
error ( L_2 ) ;
goto V_94;
}
V_37 . V_45 = 0 ;
V_37 . V_34 = V_37 . V_56 = V_37 . V_55 = V_37 . V_54 = 1 ;
V_24 . V_30 = & V_30 ;
V_24 . V_28 = V_28 ;
V_24 . V_25 = 0 ;
V_24 . V_33 = 0 ;
V_24 . V_26 = 0 ;
F_4 ( & V_7 , V_9 , V_93 , V_84 ) ;
for ( V_3 = 0 ; V_3 < sizeof( V_30 ) ; V_3 ++ ) {
if ( V_7 . V_1 >= V_7 . V_11 )
F_3 ( & V_7 ) ;
( ( unsigned char * ) & V_30 ) [ V_3 ] = * V_7 . V_1 ++ ;
}
if ( V_30 . V_29 >= ( 9 * 5 * 5 ) ) {
error ( L_3 ) ;
goto V_95;
}
V_42 = 0 ;
V_40 = V_30 . V_29 ;
while ( V_40 >= 9 ) {
V_42 ++ ;
V_40 -= 9 ;
}
V_89 = 0 ;
V_90 = V_42 ;
while ( V_90 >= 5 ) {
V_89 ++ ;
V_90 -= 5 ;
}
V_91 = ( 1 << V_89 ) - 1 ;
V_41 = ( 1 << V_90 ) - 1 ;
F_23 ( V_30 . V_31 ) ;
F_23 ( V_30 . V_35 ) ;
if ( V_30 . V_31 == 0 )
V_30 . V_31 = 1 ;
if ( V_85 )
V_24 . V_5 = V_85 ;
else {
V_24 . V_96 = F_24 ( V_30 . V_35 , V_30 . V_31 ) ;
V_24 . V_5 = F_25 ( V_24 . V_96 ) ;
}
if ( V_24 . V_5 == NULL )
goto V_95;
V_92 = V_97 + ( V_44 << ( V_40 + V_90 ) ) ;
V_16 = ( T_3 * ) F_25 ( V_92 * sizeof( * V_16 ) ) ;
if ( V_16 == NULL )
goto V_98;
V_92 = V_43 + ( V_44 << ( V_40 + V_90 ) ) ;
for ( V_3 = 0 ; V_3 < V_92 ; V_3 ++ )
V_16 [ V_3 ] = ( 1 << V_18 ) >> 1 ;
F_5 ( & V_7 ) ;
while ( F_15 ( & V_24 ) < V_30 . V_35 ) {
int V_38 = F_15 ( & V_24 ) & V_91 ;
T_3 * V_39 = V_16 + V_99 +
( V_37 . V_45 << V_60 ) + V_38 ;
if ( F_9 ( & V_7 , V_39 ) ) {
if ( F_20 ( & V_24 , & V_7 , & V_37 , V_16 , V_38 , V_39 ,
V_40 , V_41 ) ) {
error ( L_4 ) ;
goto V_100;
}
} else {
if ( F_21 ( & V_24 , & V_7 , & V_37 , V_16 , V_38 , V_39 ) ) {
error ( L_4 ) ;
goto V_100;
}
if ( V_37 . V_34 == 0 )
break;
}
if ( V_7 . V_8 <= 0 )
goto V_100;
}
if ( V_86 )
* V_86 = V_7 . V_1 - V_7 . V_5 ;
if ( ! V_24 . V_28 || V_24 . V_28 ( V_24 . V_5 , V_24 . V_26 ) == V_24 . V_26 )
V_4 = 0 ;
V_100:
F_26 ( V_16 ) ;
V_98:
if ( ! V_85 )
F_26 ( V_24 . V_5 ) ;
V_95:
if ( ! V_83 )
free ( V_93 ) ;
V_94:
return V_4 ;
}
STATIC int T_1 F_27 ( unsigned char * V_83 , long V_84 ,
long (* V_9)( void * , unsigned long ) ,
long (* V_28)( void * , unsigned long ) ,
unsigned char * V_85 , long V_101 ,
long * V_86 ,
void (* error)( char * V_87 ) )
{
return F_22 ( V_83 , V_84 - 4 , V_9 , V_28 , V_85 , V_86 , error ) ;
}
