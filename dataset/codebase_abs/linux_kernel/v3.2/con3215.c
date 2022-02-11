static inline struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
unsigned long V_3 ;
F_2 ( & V_4 , V_3 ) ;
V_2 = V_5 ;
V_5 = V_2 -> V_6 ;
F_3 ( & V_4 , V_3 ) ;
return V_2 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 -> type == V_7 )
return;
V_2 -> type = V_7 ;
F_2 ( & V_4 , V_3 ) ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
F_3 ( & V_4 , V_3 ) ;
}
static void F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
V_2 = V_9 -> V_12 ;
if ( V_2 == NULL ) {
V_2 = F_1 () ;
V_2 -> type = V_13 ;
V_2 -> V_14 = V_9 ;
V_9 -> V_12 = V_2 ;
}
V_11 = V_2 -> V_15 ;
V_11 -> V_16 = 0x0A ;
V_11 -> V_3 = 0x20 ;
V_11 -> V_17 = 160 ;
V_11 -> V_18 = ( V_19 ) F_6 ( V_9 -> V_20 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
int V_21 , V_17 , V_22 , V_23 ;
if ( V_9 -> V_17 <= V_9 -> V_24 )
return;
V_2 = V_9 -> V_25 ;
if ( V_2 == NULL ) {
V_2 = F_1 () ;
V_2 -> type = V_26 ;
V_2 -> V_14 = V_9 ;
V_9 -> V_25 = V_2 ;
} else {
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_11 = V_2 -> V_15 ;
V_2 -> V_27 = ( V_9 -> V_28 - V_9 -> V_17 + V_9 -> V_24 ) &
( V_29 - 1 ) ;
V_23 = 0 ;
V_22 = V_2 -> V_27 ;
while ( V_23 < V_30 && V_22 != V_9 -> V_28 ) {
if ( V_9 -> V_31 [ V_22 ] == 0x15 )
V_23 ++ ;
V_22 = ( V_22 + 1 ) & ( V_29 - 1 ) ;
}
V_21 = ( ( V_22 - 1 - V_2 -> V_27 ) & ( V_29 - 1 ) ) + 1 ;
if ( V_21 > V_32 )
V_21 = V_32 ;
V_2 -> V_21 = V_21 ;
V_9 -> V_24 += V_21 ;
V_2 -> V_33 = ( V_22 == V_9 -> V_28 ) && ( V_21 < V_34 ) ;
V_22 = V_2 -> V_27 ;
while ( V_21 > 0 ) {
if ( V_11 > V_2 -> V_15 )
V_11 [ - 1 ] . V_3 |= 0x40 ;
V_11 -> V_16 = 0x01 ;
V_11 -> V_3 = 0x20 ;
V_11 -> V_18 =
( V_19 ) F_6 ( V_9 -> V_31 + V_22 ) ;
V_17 = V_21 ;
if ( V_22 + V_17 > V_29 )
V_17 = V_29 - V_22 ;
V_11 -> V_17 = V_17 ;
V_21 -= V_17 ;
V_22 = ( V_22 + V_17 ) & ( V_29 - 1 ) ;
V_11 ++ ;
}
if ( V_11 > V_2 -> V_15 )
V_11 [ - 1 ] . V_3 |= 0x40 ;
V_11 -> V_16 = 0x03 ;
V_11 -> V_3 = 0 ;
V_11 -> V_18 = 0 ;
V_11 -> V_17 = 1 ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_35 ;
V_2 = V_9 -> V_12 ;
if ( V_2 != NULL &&
! ( V_9 -> V_3 & ( V_36 | V_37 ) ) ) {
V_9 -> V_12 = NULL ;
V_35 = F_9 ( V_9 -> V_38 , V_2 -> V_15 ,
( unsigned long ) V_2 , 0 , 0 ) ;
if ( V_35 != 0 ) {
V_9 -> V_12 = V_2 ;
} else {
V_9 -> V_3 |= V_36 ;
}
}
V_2 = V_9 -> V_25 ;
if ( V_2 != NULL &&
! ( V_9 -> V_3 & ( V_36 | V_39 ) ) ) {
V_9 -> V_25 = NULL ;
V_35 = F_9 ( V_9 -> V_38 , V_2 -> V_15 ,
( unsigned long ) V_2 , 0 , 0 ) ;
if ( V_35 != 0 ) {
V_9 -> V_25 = V_2 ;
} else {
V_9 -> V_3 |= V_36 ;
}
}
}
static void F_10 ( unsigned long V_40 )
{
struct V_8 * V_9 = (struct V_8 * ) V_40 ;
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_3 & V_41 ) {
F_12 ( & V_9 -> V_42 ) ;
V_9 -> V_3 &= ~ V_41 ;
if ( ! ( V_9 -> V_3 & V_43 ) ) {
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
}
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static inline void F_13 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_3 & V_44 ) || ( V_9 -> V_3 & V_43 ) )
return;
if ( V_9 -> V_12 != NULL )
F_8 ( V_9 ) ;
else if ( V_9 -> V_25 != NULL ) {
if ( ( V_9 -> V_25 -> V_33 == 0 ) ||
( V_9 -> V_3 & V_45 ) ) {
F_8 ( V_9 ) ;
if ( V_9 -> V_3 & V_41 ) {
F_12 ( & V_9 -> V_42 ) ;
V_9 -> V_3 &= ~ V_41 ;
}
} else if ( ! ( V_9 -> V_3 & V_41 ) ) {
F_14 ( & V_9 -> V_42 ) ;
V_9 -> V_42 . V_46 = V_47 + V_48 ;
V_9 -> V_42 . V_49 = ( unsigned long ) V_9 ;
V_9 -> V_42 . V_50 = F_10 ;
F_15 ( & V_9 -> V_42 ) ;
V_9 -> V_3 |= V_41 ;
}
}
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_51 * V_52 ;
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
V_52 = V_9 -> V_52 ;
if ( V_52 != NULL &&
V_29 - V_9 -> V_17 >= V_53 ) {
F_17 ( V_52 ) ;
}
}
static void F_18 ( struct V_54 * V_38 , unsigned long V_55 ,
struct V_56 * V_56 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int V_57 , V_58 ;
int V_17 ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
V_2 = (struct V_1 * ) V_55 ;
V_57 = V_56 -> V_60 . V_61 . V_57 ;
V_58 = V_56 -> V_60 . V_61 . V_58 ;
if ( V_57 != 0 )
F_16 ( V_9 ) ;
if ( V_58 & 0x01 ) {
V_58 &= ~ 0x01 ;
}
switch ( V_58 ) {
case 0x80 :
if ( V_57 != 0 )
break;
F_5 ( V_9 ) ;
F_16 ( V_9 ) ;
break;
case 0x08 :
case 0x0C :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
return;
if ( V_2 -> type == V_13 ) {
V_2 -> V_62 = V_56 -> V_60 . V_61 . V_17 ;
}
if ( V_58 == 0x08 )
break;
case 0x04 :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
return;
if ( V_2 -> type == V_13 && V_9 -> V_52 != NULL ) {
unsigned int V_63 ;
V_52 = V_9 -> V_52 ;
V_17 = 160 - V_2 -> V_62 ;
F_20 ( V_9 -> V_20 , V_17 ) ;
V_63 = F_21 ( V_9 -> V_20 , V_17 , V_52 ) ;
switch ( V_63 & V_64 ) {
case V_65 :
break;
case V_66 :
F_22 ( V_52 , V_63 , V_67 ) ;
F_23 ( V_9 -> V_52 ) ;
break;
case V_68 :
if ( V_17 < 2 ||
( strncmp ( V_9 -> V_20 + V_17 - 2 , L_1 , 2 ) &&
strncmp ( V_9 -> V_20 + V_17 - 2 , L_2 , 2 ) ) ) {
V_9 -> V_20 [ V_17 ] = '\n' ;
V_17 ++ ;
} else
V_17 -= 2 ;
F_24 ( V_52 , V_9 -> V_20 , V_17 ) ;
F_23 ( V_9 -> V_52 ) ;
break;
}
} else if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
if ( F_25 ( & V_9 -> V_69 ) &&
V_9 -> V_25 == NULL &&
V_9 -> V_12 == NULL ) {
F_26 ( & V_9 -> V_69 ) ;
}
F_16 ( V_9 ) ;
break;
default:
if ( V_2 != NULL && V_2 -> type != V_7 ) {
if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
}
F_16 ( V_9 ) ;
}
return;
}
static void F_27 ( struct V_8 * V_9 )
{
int V_22 ;
char V_70 ;
F_28 ( V_9 -> V_24 != 0 ) ;
V_22 = ( V_9 -> V_28 - V_9 -> V_17 ) & ( V_29 - 1 ) ;
while ( V_9 -> V_17 > 0 ) {
V_70 = V_9 -> V_31 [ V_22 ] ;
V_22 = ( V_22 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 -- ;
if ( V_70 == 0x15 )
break;
}
V_9 -> V_28 = V_22 ;
}
static void F_29 ( struct V_8 * V_9 , unsigned int V_71 )
{
while ( V_29 - V_9 -> V_17 < V_71 ) {
if ( V_9 -> V_3 & V_43 ) {
F_27 ( V_9 ) ;
continue;
}
V_9 -> V_3 |= V_45 ;
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
#ifdef F_30
F_31 () ;
#endif
if ( V_29 - V_9 -> V_17 >= V_71 )
break;
F_32 ( F_11 ( V_9 -> V_38 ) ) ;
F_33 ( 100 ) ;
F_34 ( F_11 ( V_9 -> V_38 ) ) ;
}
}
static void F_35 ( struct V_8 * V_9 , const char * V_72 ,
unsigned int V_71 )
{
unsigned long V_3 ;
int V_73 , V_17 ;
while ( V_71 > 0 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_17 = ( V_71 > V_29 ) ?
V_29 : V_71 ;
V_71 -= V_17 ;
F_29 ( V_9 , V_17 ) ;
while ( 1 ) {
V_73 = F_36 ( int , V_17 ,
F_37 ( V_29 - V_9 -> V_17 ,
V_29 - V_9 -> V_28 ) ) ;
if ( V_73 <= 0 )
break;
memcpy ( V_9 -> V_31 + V_9 -> V_28 , V_72 , V_73 ) ;
F_38 ( V_9 -> V_31 + V_9 -> V_28 , V_73 ) ;
V_9 -> V_28 = ( V_9 -> V_28 + V_73 ) & ( V_29 - 1 ) ;
V_9 -> V_17 += V_73 ;
V_9 -> V_74 += V_73 ;
V_72 += V_73 ;
V_17 -= V_73 ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_39 ( struct V_8 * V_9 , unsigned char V_70 )
{
unsigned long V_3 ;
unsigned int V_71 , V_75 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_70 == '\t' ) {
V_71 = V_76 - ( V_9 -> V_74 % V_76 ) ;
V_9 -> V_74 += V_71 ;
V_70 = ' ' ;
} else if ( V_70 == '\n' ) {
V_71 = 1 ;
V_9 -> V_74 = 0 ;
} else {
V_71 = 1 ;
V_9 -> V_74 ++ ;
}
F_29 ( V_9 , V_71 ) ;
for ( V_75 = 0 ; V_75 < V_71 ; V_75 ++ ) {
V_9 -> V_31 [ V_9 -> V_28 ] = ( char ) V_77 [ ( int ) V_70 ] ;
V_9 -> V_28 = ( V_9 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 ++ ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_13 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static void F_40 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_17 > 0 ) {
V_9 -> V_3 |= V_45 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_41 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
if ( V_9 -> V_3 & V_44 )
return 0 ;
V_9 -> V_74 = 0 ;
V_9 -> V_3 |= V_44 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_42 ( struct V_8 * V_9 )
{
F_43 ( V_78 , V_79 ) ;
unsigned long V_3 ;
if ( ! ( V_9 -> V_3 & V_44 ) || ( V_9 -> V_3 & V_80 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( ( V_9 -> V_3 & V_36 ) ||
V_9 -> V_25 != NULL ||
V_9 -> V_12 != NULL ) {
V_9 -> V_3 |= V_81 ;
F_44 ( & V_9 -> V_69 , & V_78 ) ;
F_45 ( V_82 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_46 () ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_47 ( & V_9 -> V_69 , & V_78 ) ;
F_45 ( V_83 ) ;
V_9 -> V_3 &= ~ ( V_44 | V_81 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_48 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
int line ;
if ( V_84 [ 0 ] && ( V_84 [ 0 ] == F_19 ( & V_38 -> V_59 ) ) )
return 0 ;
V_9 = F_49 ( sizeof( struct V_8 ) +
V_85 , V_86 | V_87 ) ;
if ( V_9 == NULL )
return - V_88 ;
F_34 ( & V_89 ) ;
for ( line = 0 ; line < V_90 ; line ++ ) {
if ( ! V_84 [ line ] ) {
V_84 [ line ] = V_9 ;
break;
}
}
F_32 ( & V_89 ) ;
if ( line == V_90 ) {
F_50 ( V_9 ) ;
return - V_91 ;
}
V_9 -> V_38 = V_38 ;
V_9 -> V_20 = ( char * ) V_9 + sizeof( struct V_8 ) ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_31 = F_49 ( V_29 ,
V_86 | V_87 ) ;
if ( V_9 -> V_31 == NULL ) {
F_34 ( & V_89 ) ;
V_84 [ line ] = NULL ;
F_32 ( & V_89 ) ;
F_50 ( V_9 ) ;
return - V_88 ;
}
F_51 ( & V_9 -> V_69 ) ;
F_52 ( & V_38 -> V_59 , V_9 ) ;
V_38 -> V_92 = F_18 ;
return 0 ;
}
static void F_53 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
F_54 ( V_38 ) ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
if ( V_9 ) {
F_52 ( & V_38 -> V_59 , NULL ) ;
F_50 ( V_9 -> V_31 ) ;
F_50 ( V_9 ) ;
}
}
static int F_55 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
if ( ! V_9 )
return - V_91 ;
return F_41 ( V_9 ) ;
}
static int F_56 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
if ( ! V_9 )
return - V_91 ;
F_42 ( V_9 ) ;
return 0 ;
}
static int F_57 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_29 ( V_9 , V_29 ) ;
V_9 -> V_3 |= V_43 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_54 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_19 ( & V_38 -> V_59 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_43 ;
V_9 -> V_3 |= V_45 ;
F_13 ( V_9 ) ;
V_9 -> V_3 &= ~ V_45 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_59 ( struct V_93 * V_94 , const char * V_72 ,
unsigned int V_17 )
{
struct V_8 * V_9 ;
int V_75 ;
if ( V_17 <= 0 )
return;
V_9 = V_84 [ 0 ] ;
while ( V_17 > 0 ) {
for ( V_75 = 0 ; V_75 < V_17 ; V_75 ++ )
if ( V_72 [ V_75 ] == '\t' || V_72 [ V_75 ] == '\n' )
break;
F_35 ( V_9 , V_72 , V_75 ) ;
V_17 -= V_75 ;
V_72 += V_75 ;
if ( V_17 > 0 ) {
F_39 ( V_9 , * V_72 ) ;
V_17 -- ;
V_72 ++ ;
}
}
}
static struct V_95 * F_60 ( struct V_93 * V_73 , int * V_96 )
{
* V_96 = V_73 -> V_96 ;
return V_97 ;
}
static void F_61 ( void )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = V_84 [ 0 ] ;
if ( V_9 -> V_3 & V_43 )
if ( F_62 () )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_29 ( V_9 , V_29 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_63 ( struct V_98 * V_99 ,
unsigned long V_100 , void * V_49 )
{
F_61 () ;
return V_101 ;
}
static int T_1 F_64 ( void )
{
struct V_54 * V_38 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_75 ;
if ( ! V_102 )
return - V_91 ;
if ( V_103 ) {
F_65 ( L_3 , NULL , 0 , NULL ) ;
F_65 ( L_4 , NULL , 0 , NULL ) ;
}
V_5 = NULL ;
F_66 ( & V_4 ) ;
for ( V_75 = 0 ; V_75 < V_104 ; V_75 ++ ) {
V_2 = F_67 ( sizeof( struct V_1 ) , V_86 | V_87 ) ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
V_38 = F_68 () ;
if ( F_69 ( V_38 ) )
return - V_91 ;
V_84 [ 0 ] = V_9 = (struct V_8 * )
F_67 ( sizeof( struct V_8 ) , V_86 | V_87 ) ;
V_9 -> V_31 = F_67 ( V_29 , V_86 | V_87 ) ;
V_9 -> V_20 = F_67 ( V_85 , V_86 | V_87 ) ;
V_9 -> V_38 = V_38 ;
F_52 ( & V_38 -> V_59 , V_9 ) ;
V_38 -> V_92 = F_18 ;
V_9 -> V_3 |= V_80 ;
F_51 ( & V_9 -> V_69 ) ;
if ( F_41 ( V_9 ) != 0 ) {
F_50 ( V_9 -> V_20 ) ;
F_50 ( V_9 -> V_31 ) ;
F_50 ( V_9 ) ;
V_84 [ 0 ] = NULL ;
return - V_91 ;
}
F_70 ( & V_105 , & V_106 ) ;
F_71 ( & V_107 ) ;
F_72 ( & V_108 ) ;
return 0 ;
}
static int F_73 ( struct V_51 * V_52 , struct V_109 * V_110 )
{
struct V_8 * V_9 ;
int V_111 , line ;
line = V_52 -> V_96 ;
if ( ( line < 0 ) || ( line >= V_90 ) )
return - V_91 ;
V_9 = V_84 [ line ] ;
if ( V_9 == NULL )
return - V_91 ;
V_52 -> V_112 = V_9 ;
V_9 -> V_52 = V_52 ;
V_52 -> V_113 = 0 ;
V_111 = F_41 ( V_9 ) ;
if ( V_111 )
return V_111 ;
return 0 ;
}
static void F_74 ( struct V_51 * V_52 , struct V_109 * V_110 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
if ( V_9 == NULL || V_52 -> V_17 > 1 )
return;
V_52 -> V_114 = 1 ;
F_42 ( V_9 ) ;
V_52 -> V_114 = 0 ;
V_9 -> V_52 = NULL ;
}
static int F_75 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
if ( ( V_29 - V_9 -> V_17 - V_76 ) >= 0 )
return V_29 - V_9 -> V_17 - V_76 ;
else
return 0 ;
}
static int F_76 ( struct V_51 * V_52 ,
const unsigned char * V_115 , int V_17 )
{
struct V_8 * V_9 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
F_35 ( V_9 , V_115 , V_17 ) ;
return V_17 ;
}
static int F_77 ( struct V_51 * V_52 , unsigned char V_70 )
{
struct V_8 * V_9 ;
if ( ! V_52 )
return 0 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
F_39 ( V_9 , V_70 ) ;
return 1 ;
}
static void F_78 ( struct V_51 * V_52 )
{
}
static int F_79 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
return V_9 -> V_17 ;
}
static void F_80 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
F_40 ( V_9 ) ;
F_17 ( V_52 ) ;
}
static void F_81 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
V_9 -> V_3 |= V_37 ;
}
static void F_82 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
if ( V_9 -> V_3 & V_37 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_37 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_83 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
V_9 -> V_3 |= V_39 ;
}
static void F_84 ( struct V_51 * V_52 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_52 -> V_112 ;
if ( V_9 -> V_3 & V_39 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_39 ;
F_13 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static int T_1 F_85 ( void )
{
struct V_95 * V_116 ;
int V_117 ;
if ( ! V_102 )
return 0 ;
V_116 = F_86 ( V_90 ) ;
if ( ! V_116 )
return - V_88 ;
V_117 = F_87 ( & V_118 ) ;
if ( V_117 ) {
F_88 ( V_116 ) ;
return V_117 ;
}
V_116 -> V_119 = V_120 ;
V_116 -> V_121 = L_5 ;
V_116 -> V_122 = L_6 ;
V_116 -> V_123 = V_124 ;
V_116 -> V_125 = 64 ;
V_116 -> type = V_126 ;
V_116 -> V_127 = V_128 ;
V_116 -> V_129 = V_130 ;
V_116 -> V_129 . V_131 = V_132 | V_133 ;
V_116 -> V_129 . V_134 = V_135 | V_136 ;
V_116 -> V_129 . V_137 = V_138 ;
V_116 -> V_3 = V_139 ;
F_89 ( V_116 , & V_140 ) ;
V_117 = F_90 ( V_116 ) ;
if ( V_117 ) {
F_88 ( V_116 ) ;
return V_117 ;
}
V_97 = V_116 ;
return 0 ;
}
static void T_2 F_91 ( void )
{
F_92 ( V_97 ) ;
F_88 ( V_97 ) ;
F_93 ( & V_118 ) ;
}
