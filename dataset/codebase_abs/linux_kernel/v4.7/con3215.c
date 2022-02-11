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
V_9 -> V_3 &= ~ V_41 ;
if ( ! F_12 ( & V_9 -> V_42 ) ) {
F_7 ( V_9 ) ;
F_8 ( V_9 ) ;
if ( ( V_9 -> V_12 || V_9 -> V_25 ) &&
! ( V_9 -> V_3 & V_36 ) &&
! ( V_9 -> V_3 & V_41 ) ) {
V_9 -> V_43 . V_44 = V_45 + V_46 ;
F_13 ( & V_9 -> V_43 ) ;
V_9 -> V_3 |= V_41 ;
}
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static inline void F_14 ( struct V_8 * V_9 )
{
if ( ! F_15 ( & V_9 -> V_42 ) || F_12 ( & V_9 -> V_42 ) )
return;
if ( V_9 -> V_12 != NULL )
F_8 ( V_9 ) ;
else if ( V_9 -> V_25 != NULL ) {
if ( ( V_9 -> V_25 -> V_33 == 0 ) ||
( V_9 -> V_3 & V_47 ) ) {
F_8 ( V_9 ) ;
}
}
if ( ( V_9 -> V_12 || V_9 -> V_25 ) &&
! ( V_9 -> V_3 & V_36 ) &&
! ( V_9 -> V_3 & V_41 ) ) {
V_9 -> V_43 . V_44 = V_45 + V_46 ;
F_13 ( & V_9 -> V_43 ) ;
V_9 -> V_3 |= V_41 ;
}
}
static void F_16 ( unsigned long V_48 )
{
struct V_8 * V_9 = (struct V_8 * ) V_48 ;
struct V_49 * V_50 ;
V_50 = F_17 ( & V_9 -> V_42 ) ;
if ( V_50 ) {
F_18 ( V_50 ) ;
F_19 ( V_50 ) ;
}
}
static void F_20 ( struct V_8 * V_9 , struct V_49 * V_50 )
{
F_7 ( V_9 ) ;
F_14 ( V_9 ) ;
if ( V_50 && V_29 - V_9 -> V_17 >= V_51 )
F_21 ( & V_9 -> V_52 ) ;
}
static void F_22 ( struct V_53 * V_38 , unsigned long V_54 ,
struct V_55 * V_55 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
int V_56 , V_57 ;
int V_17 ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
V_2 = (struct V_1 * ) V_54 ;
V_50 = F_17 ( & V_9 -> V_42 ) ;
V_56 = V_55 -> V_59 . V_60 . V_56 ;
V_57 = V_55 -> V_59 . V_60 . V_57 ;
if ( V_56 != 0 )
F_20 ( V_9 , V_50 ) ;
if ( V_57 & 0x01 ) {
V_57 &= ~ 0x01 ;
}
switch ( V_57 ) {
case 0x80 :
if ( V_56 != 0 )
break;
F_5 ( V_9 ) ;
F_20 ( V_9 , V_50 ) ;
break;
case 0x08 :
case 0x0C :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
goto V_61;
if ( V_2 -> type == V_13 ) {
V_2 -> V_62 = V_55 -> V_59 . V_60 . V_17 ;
}
if ( V_57 == 0x08 )
break;
case 0x04 :
if ( ( V_9 = V_2 -> V_14 ) == NULL )
goto V_61;
if ( V_2 -> type == V_13 && V_50 != NULL ) {
unsigned int V_63 ;
V_17 = 160 - V_2 -> V_62 ;
F_24 ( V_9 -> V_20 , V_17 ) ;
V_63 = F_25 ( V_9 -> V_20 , V_17 , V_50 ) ;
switch ( V_63 & V_64 ) {
case V_65 :
break;
case V_66 :
F_26 ( & V_9 -> V_42 , V_63 ,
V_67 ) ;
F_27 ( & V_9 -> V_42 ) ;
break;
case V_68 :
if ( V_17 < 2 ||
( strncmp ( V_9 -> V_20 + V_17 - 2 , L_1 , 2 ) &&
strncmp ( V_9 -> V_20 + V_17 - 2 , L_2 , 2 ) ) ) {
V_9 -> V_20 [ V_17 ] = '\n' ;
V_17 ++ ;
} else
V_17 -= 2 ;
F_28 ( & V_9 -> V_42 , V_9 -> V_20 ,
V_17 ) ;
F_27 ( & V_9 -> V_42 ) ;
break;
}
} else if ( V_2 -> type == V_26 ) {
V_9 -> V_17 -= V_2 -> V_21 ;
V_9 -> V_24 -= V_2 -> V_21 ;
}
V_9 -> V_3 &= ~ V_36 ;
F_4 ( V_2 ) ;
if ( F_29 ( & V_9 -> V_69 ) &&
V_9 -> V_25 == NULL &&
V_9 -> V_12 == NULL ) {
F_30 ( & V_9 -> V_69 ) ;
}
F_20 ( V_9 , V_50 ) ;
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
F_20 ( V_9 , V_50 ) ;
}
V_61:
F_19 ( V_50 ) ;
}
static void F_31 ( struct V_8 * V_9 )
{
int V_22 ;
char V_70 ;
F_32 ( V_9 -> V_24 != 0 ) ;
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
static void F_33 ( struct V_8 * V_9 , unsigned int V_71 )
{
while ( V_29 - V_9 -> V_17 < V_71 ) {
if ( F_12 ( & V_9 -> V_42 ) ) {
F_31 ( V_9 ) ;
continue;
}
V_9 -> V_3 |= V_47 ;
F_7 ( V_9 ) ;
F_14 ( V_9 ) ;
V_9 -> V_3 &= ~ V_47 ;
#ifdef F_34
F_35 ( V_9 -> V_38 ) ;
#endif
if ( V_29 - V_9 -> V_17 >= V_71 )
break;
F_36 ( F_11 ( V_9 -> V_38 ) ) ;
F_37 ( 100 ) ;
F_38 ( F_11 ( V_9 -> V_38 ) ) ;
}
}
static void F_39 ( struct V_8 * V_9 , const char * V_72 ,
unsigned int V_71 )
{
unsigned long V_3 ;
int V_73 , V_17 ;
while ( V_71 > 0 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_17 = ( V_71 > V_29 ) ?
V_29 : V_71 ;
V_71 -= V_17 ;
F_33 ( V_9 , V_17 ) ;
while ( 1 ) {
V_73 = F_40 ( int , V_17 ,
F_41 ( V_29 - V_9 -> V_17 ,
V_29 - V_9 -> V_28 ) ) ;
if ( V_73 <= 0 )
break;
memcpy ( V_9 -> V_31 + V_9 -> V_28 , V_72 , V_73 ) ;
F_42 ( V_9 -> V_31 + V_9 -> V_28 , V_73 ) ;
V_9 -> V_28 = ( V_9 -> V_28 + V_73 ) & ( V_29 - 1 ) ;
V_9 -> V_17 += V_73 ;
V_9 -> V_74 += V_73 ;
V_72 += V_73 ;
V_17 -= V_73 ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_14 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_43 ( struct V_8 * V_9 , unsigned char V_70 )
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
F_33 ( V_9 , V_71 ) ;
for ( V_75 = 0 ; V_75 < V_71 ; V_75 ++ ) {
V_9 -> V_31 [ V_9 -> V_28 ] = ( char ) V_77 [ ( int ) V_70 ] ;
V_9 -> V_28 = ( V_9 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_9 -> V_17 ++ ;
}
if ( ! ( V_9 -> V_3 & V_36 ) ) {
F_7 ( V_9 ) ;
F_14 ( V_9 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( V_9 -> V_17 > 0 ) {
V_9 -> V_3 |= V_47 ;
F_14 ( V_9 ) ;
V_9 -> V_3 &= ~ V_47 ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_45 ( struct V_8 * V_9 )
{
unsigned long V_3 ;
if ( F_15 ( & V_9 -> V_42 ) )
return 0 ;
V_9 -> V_74 = 0 ;
F_46 ( & V_9 -> V_42 , 1 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_14 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_47 ( struct V_8 * V_9 )
{
F_48 ( V_78 , V_79 ) ;
unsigned long V_3 ;
if ( ! F_15 ( & V_9 -> V_42 ) || ( V_9 -> V_3 & V_80 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
if ( ( V_9 -> V_3 & V_36 ) ||
V_9 -> V_25 != NULL ||
V_9 -> V_12 != NULL ) {
F_49 ( & V_9 -> V_69 , & V_78 ) ;
F_50 ( V_81 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_51 () ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_52 ( & V_9 -> V_69 , & V_78 ) ;
F_50 ( V_82 ) ;
F_46 ( & V_9 -> V_42 , 1 ) ;
}
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static struct V_8 * F_53 ( void )
{
struct V_8 * V_14 ;
V_14 = F_54 ( sizeof( struct V_8 ) , V_83 | V_84 ) ;
if ( ! V_14 )
return NULL ;
V_14 -> V_31 = F_54 ( V_29 , V_83 | V_84 ) ;
V_14 -> V_20 = F_54 ( V_85 , V_83 | V_84 ) ;
if ( ! V_14 -> V_31 || ! V_14 -> V_20 ) {
F_55 ( V_14 -> V_20 ) ;
F_55 ( V_14 -> V_31 ) ;
F_55 ( V_14 ) ;
return NULL ;
}
F_56 ( & V_14 -> V_43 , F_10 , ( unsigned long ) V_14 ) ;
F_57 ( & V_14 -> V_69 ) ;
F_58 ( & V_14 -> V_52 , F_16 , ( unsigned long ) V_14 ) ;
F_59 ( & V_14 -> V_42 ) ;
return V_14 ;
}
static void F_60 ( struct V_8 * V_9 )
{
F_55 ( V_9 -> V_20 ) ;
F_55 ( V_9 -> V_31 ) ;
F_61 ( & V_9 -> V_42 ) ;
F_55 ( V_9 ) ;
}
static int F_62 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
int line ;
if ( V_86 [ 0 ] && ( V_86 [ 0 ] == F_23 ( & V_38 -> V_58 ) ) )
return 0 ;
V_9 = F_53 () ;
if ( V_9 == NULL )
return - V_87 ;
V_9 -> V_38 = V_38 ;
F_63 ( & V_38 -> V_58 , V_9 ) ;
V_38 -> V_88 = F_22 ;
F_38 ( & V_89 ) ;
for ( line = 0 ; line < V_90 ; line ++ ) {
if ( ! V_86 [ line ] ) {
V_86 [ line ] = V_9 ;
break;
}
}
F_36 ( & V_89 ) ;
if ( line == V_90 ) {
F_60 ( V_9 ) ;
return - V_91 ;
}
return 0 ;
}
static void F_64 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
unsigned int line ;
F_65 ( V_38 ) ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
if ( V_9 ) {
F_38 ( & V_89 ) ;
for ( line = 0 ; line < V_90 ; line ++ )
if ( V_86 [ line ] == V_9 )
break;
V_86 [ line ] = NULL ;
F_36 ( & V_89 ) ;
F_63 ( & V_38 -> V_58 , NULL ) ;
F_60 ( V_9 ) ;
}
}
static int F_66 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
if ( ! V_9 )
return - V_91 ;
return F_45 ( V_9 ) ;
}
static int F_67 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
if ( ! V_9 )
return - V_91 ;
F_47 ( V_9 ) ;
return 0 ;
}
static int F_68 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_33 ( V_9 , V_29 ) ;
F_69 ( & V_9 -> V_42 , 1 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static int F_70 ( struct V_53 * V_38 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = F_23 ( & V_38 -> V_58 ) ;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_69 ( & V_9 -> V_42 , 0 ) ;
V_9 -> V_3 |= V_47 ;
F_14 ( V_9 ) ;
V_9 -> V_3 &= ~ V_47 ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
return 0 ;
}
static void F_71 ( struct V_92 * V_93 , const char * V_72 ,
unsigned int V_17 )
{
struct V_8 * V_9 ;
int V_75 ;
if ( V_17 <= 0 )
return;
V_9 = V_86 [ 0 ] ;
while ( V_17 > 0 ) {
for ( V_75 = 0 ; V_75 < V_17 ; V_75 ++ )
if ( V_72 [ V_75 ] == '\t' || V_72 [ V_75 ] == '\n' )
break;
F_39 ( V_9 , V_72 , V_75 ) ;
V_17 -= V_75 ;
V_72 += V_75 ;
if ( V_17 > 0 ) {
F_43 ( V_9 , * V_72 ) ;
V_17 -- ;
V_72 ++ ;
}
}
}
static struct V_94 * F_72 ( struct V_92 * V_73 , int * V_95 )
{
* V_95 = V_73 -> V_95 ;
return V_96 ;
}
static void F_73 ( void )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = V_86 [ 0 ] ;
if ( F_12 ( & V_9 -> V_42 ) )
if ( F_74 ( V_9 -> V_38 ) )
return;
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
F_33 ( V_9 , V_29 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
static int F_75 ( struct V_97 * V_98 ,
unsigned long V_99 , void * V_48 )
{
F_73 () ;
return V_100 ;
}
static int T_1 F_76 ( void )
{
struct V_53 * V_38 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
int V_75 ;
if ( ! V_101 )
return - V_91 ;
if ( V_102 ) {
F_77 ( L_3 , NULL , 0 , NULL ) ;
F_77 ( L_4 , NULL , 0 , NULL ) ;
}
V_5 = NULL ;
F_78 ( & V_4 ) ;
for ( V_75 = 0 ; V_75 < V_103 ; V_75 ++ ) {
V_2 = F_54 ( sizeof( struct V_1 ) , V_83 | V_84 ) ;
if ( ! V_2 )
return - V_87 ;
V_2 -> V_6 = V_5 ;
V_5 = V_2 ;
}
V_38 = F_79 ( & V_104 ) ;
if ( F_80 ( V_38 ) )
return - V_91 ;
V_86 [ 0 ] = V_9 = F_53 () ;
V_9 -> V_38 = V_38 ;
F_63 ( & V_38 -> V_58 , V_9 ) ;
V_38 -> V_88 = F_22 ;
V_9 -> V_3 |= V_80 ;
if ( F_81 ( V_38 ) ) {
F_82 ( V_38 ) ;
F_60 ( V_9 ) ;
V_86 [ 0 ] = NULL ;
return - V_91 ;
}
if ( F_45 ( V_9 ) != 0 ) {
F_60 ( V_9 ) ;
V_86 [ 0 ] = NULL ;
return - V_91 ;
}
F_83 ( & V_105 , & V_106 ) ;
F_84 ( & V_107 ) ;
F_85 ( & V_108 ) ;
return 0 ;
}
static int F_86 ( struct V_94 * V_109 , struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = V_86 [ V_50 -> V_95 ] ;
if ( V_9 == NULL )
return - V_91 ;
V_50 -> V_110 = V_9 ;
return F_87 ( & V_9 -> V_42 , V_109 , V_50 ) ;
}
static int F_88 ( struct V_49 * V_50 , struct V_111 * V_112 )
{
struct V_8 * V_9 = V_50 -> V_110 ;
int V_113 ;
F_89 ( & V_9 -> V_42 , V_50 ) ;
V_9 -> V_42 . V_114 = 0 ;
V_113 = F_45 ( V_9 ) ;
if ( V_113 )
return V_113 ;
return 0 ;
}
static void F_90 ( struct V_49 * V_50 , struct V_111 * V_112 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
if ( V_9 == NULL || V_50 -> V_17 > 1 )
return;
V_50 -> V_115 = 1 ;
F_47 ( V_9 ) ;
F_91 ( & V_9 -> V_52 ) ;
V_50 -> V_115 = 0 ;
F_89 ( & V_9 -> V_42 , NULL ) ;
}
static int F_92 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
if ( ( V_29 - V_9 -> V_17 - V_76 ) >= 0 )
return V_29 - V_9 -> V_17 - V_76 ;
else
return 0 ;
}
static int F_93 ( struct V_49 * V_50 ,
const unsigned char * V_116 , int V_17 )
{
struct V_8 * V_9 ;
int V_75 , V_24 ;
if ( ! V_50 )
return 0 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
V_24 = V_17 ;
while ( V_17 > 0 ) {
for ( V_75 = 0 ; V_75 < V_17 ; V_75 ++ )
if ( V_116 [ V_75 ] == '\t' || V_116 [ V_75 ] == '\n' )
break;
F_39 ( V_9 , V_116 , V_75 ) ;
V_17 -= V_75 ;
V_116 += V_75 ;
if ( V_17 > 0 ) {
F_43 ( V_9 , * V_116 ) ;
V_17 -- ;
V_116 ++ ;
}
}
return V_24 ;
}
static int F_94 ( struct V_49 * V_50 , unsigned char V_70 )
{
struct V_8 * V_9 ;
if ( ! V_50 )
return 0 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
F_43 ( V_9 , V_70 ) ;
return 1 ;
}
static void F_95 ( struct V_49 * V_50 )
{
}
static int F_96 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
return V_9 -> V_17 ;
}
static void F_97 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
F_44 ( V_9 ) ;
F_18 ( V_50 ) ;
}
static void F_98 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
V_9 -> V_3 |= V_37 ;
}
static void F_99 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
if ( V_9 -> V_3 & V_37 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_37 ;
F_14 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static void F_100 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
V_9 -> V_3 |= V_39 ;
}
static void F_101 ( struct V_49 * V_50 )
{
struct V_8 * V_9 ;
unsigned long V_3 ;
V_9 = (struct V_8 * ) V_50 -> V_110 ;
if ( V_9 -> V_3 & V_39 ) {
F_2 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
V_9 -> V_3 &= ~ V_39 ;
F_14 ( V_9 ) ;
F_3 ( F_11 ( V_9 -> V_38 ) , V_3 ) ;
}
}
static int T_1 F_102 ( void )
{
struct V_94 * V_109 ;
int V_117 ;
if ( ! V_101 )
return 0 ;
V_109 = F_103 ( V_90 ) ;
if ( ! V_109 )
return - V_87 ;
V_117 = F_104 ( & V_104 ) ;
if ( V_117 ) {
F_105 ( V_109 ) ;
return V_117 ;
}
V_109 -> V_118 = L_5 ;
V_109 -> V_119 = L_6 ;
V_109 -> V_120 = V_121 ;
V_109 -> V_122 = 64 ;
V_109 -> type = V_123 ;
V_109 -> V_124 = V_125 ;
V_109 -> V_126 = V_127 ;
V_109 -> V_126 . V_128 = V_129 | V_130 ;
V_109 -> V_126 . V_131 = V_132 ;
V_109 -> V_126 . V_133 = V_134 ;
V_109 -> V_3 = V_135 ;
F_106 ( V_109 , & V_136 ) ;
V_117 = F_107 ( V_109 ) ;
if ( V_117 ) {
F_105 ( V_109 ) ;
return V_117 ;
}
V_96 = V_109 ;
return 0 ;
}
static void T_2 F_108 ( void )
{
F_109 ( V_96 ) ;
F_105 ( V_96 ) ;
F_110 ( & V_104 ) ;
}
