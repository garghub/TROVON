static inline void F_1 ( unsigned int V_1 , unsigned short V_2 )
{
F_2 ( V_2 & 0xff , V_1 + V_3 ) ;
F_2 ( ( V_2 >> 8 ) & 0xff , V_1 + V_4 ) ;
}
static inline void F_3 ( unsigned int V_1 , unsigned short V_5 )
{
F_2 ( V_5 & 0xff , V_1 + V_6 ) ;
F_2 ( ( V_5 >> 8 ) & 0xff , V_1 + V_7 ) ;
}
static inline void F_4 ( unsigned int V_1 , unsigned short V_2 , unsigned short V_5 )
{
F_1 ( V_1 , V_2 ) ;
F_3 ( V_1 , V_5 ) ;
}
static inline unsigned short F_5 ( unsigned int V_1 )
{
unsigned short V_5 = F_6 ( V_1 + V_6 ) ;
V_5 |= F_6 ( V_1 + V_7 ) << 8 ;
return V_5 ;
}
static inline unsigned short F_7 ( unsigned int V_1 , unsigned short V_2 )
{
F_1 ( V_1 , V_2 ) ;
return F_5 ( V_1 ) ;
}
static int F_8 ( unsigned int V_1 , int V_8 , T_1 * V_9 , int V_10 )
{
int V_11 = 0 ;
F_1 ( V_1 , 0x7080 ) ;
while ( V_11 < V_10 ) {
F_3 ( V_1 , V_9 [ V_11 ] ) ;
V_11 ++ ;
}
F_4 ( V_1 , 0x7005 , V_11 ) ;
return V_11 ;
}
static void F_9 ( struct V_12 * V_13 )
{
if ( ! V_13 ) {
F_10 ( L_1 ) ;
return;
}
if ( F_11 ( V_14 , & ( V_13 -> V_15 ) ) )
return;
do {
unsigned int V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
register struct V_19 * V_20 ;
int V_10 ;
if ( ! F_12 ( V_13 -> V_16 ) )
break;
V_20 = F_13 ( & ( V_13 -> V_21 ) ) ;
if ( ! V_20 ) {
F_14 ( V_14 , & ( V_13 -> V_15 ) ) ;
break;
}
V_10 = F_8 ( V_1 , 256 , V_20 -> V_22 , V_20 -> V_10 ) ;
if ( V_10 != V_20 -> V_10 ) {
F_10 ( L_2 ) ;
}
F_15 ( V_20 ) ;
V_13 -> V_23 -> V_24 . V_25 += V_10 ;
} while ( 0 );
}
static void F_16 ( struct V_12 * V_13 )
{
unsigned int V_1 ;
int V_26 = 0 , V_27 ;
if ( ! V_13 ) {
F_10 ( L_1 ) ;
return;
}
V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
V_27 = F_7 ( V_1 , 0x7006 ) ;
F_1 ( V_1 , 0x7480 ) ;
while ( V_26 < V_27 ) {
V_26 ++ ;
V_13 -> V_23 -> V_24 . V_28 ++ ;
if ( V_13 -> V_29 == NULL ) {
V_13 -> V_30 = V_31 ;
V_13 -> V_32 = 0 ;
V_13 -> V_29 = F_17 ( V_33 , V_34 ) ;
if ( ! V_13 -> V_29 ) {
F_10 ( L_3 ) ;
return;
}
}
if ( V_13 -> V_30 == V_31 ) {
F_18 ( V_13 -> V_29 ) -> V_35 = F_6 ( V_1 + V_6 ) ;
F_6 ( V_1 + V_7 ) ;
switch ( F_18 ( V_13 -> V_29 ) -> V_35 ) {
case V_36 :
V_13 -> V_30 = V_37 ;
V_13 -> V_32 = V_38 ;
break;
case V_39 :
V_13 -> V_30 = V_40 ;
V_13 -> V_32 = V_41 ;
break;
case V_42 :
V_13 -> V_30 = V_43 ;
V_13 -> V_32 = V_44 ;
break;
default:
F_10 ( L_4 , F_18 ( V_13 -> V_29 ) -> V_35 ) ;
V_13 -> V_23 -> V_24 . V_45 ++ ;
F_14 ( V_46 , & ( V_13 -> V_23 -> V_47 ) ) ;
F_15 ( V_13 -> V_29 ) ;
V_13 -> V_29 = NULL ;
break;
}
} else {
T_1 V_48 = F_6 ( V_1 + V_6 ) ;
* F_19 ( V_13 -> V_29 , 1 ) = V_48 ;
F_6 ( V_1 + V_7 ) ;
V_13 -> V_32 -- ;
if ( V_13 -> V_32 == 0 ) {
int V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
switch ( V_13 -> V_30 ) {
case V_37 :
V_51 = V_50 ( V_13 -> V_29 ) ;
V_13 -> V_30 = V_56 ;
V_13 -> V_32 = V_51 -> V_57 ;
break;
case V_40 :
V_53 = V_52 ( V_13 -> V_29 ) ;
V_49 = F_20 ( V_53 -> V_49 ) ;
V_13 -> V_30 = V_56 ;
V_13 -> V_32 = V_49 ;
break;
case V_43 :
V_55 = V_54 ( V_13 -> V_29 ) ;
V_13 -> V_30 = V_56 ;
V_13 -> V_32 = V_55 -> V_49 ;
break;
case V_56 :
F_21 ( V_13 -> V_23 , V_13 -> V_29 ) ;
V_13 -> V_29 = NULL ;
break;
}
}
}
}
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
}
static T_2 F_22 ( int V_58 , void * V_59 )
{
struct V_12 * V_13 = V_59 ;
unsigned int V_1 ;
int V_60 ;
T_2 V_61 = V_62 ;
if ( ! V_13 || ! V_13 -> V_23 )
return V_62 ;
V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
F_23 ( & ( V_13 -> V_63 ) ) ;
V_60 = F_6 ( V_1 + V_64 ) ;
if ( V_60 & 0x80 ) {
int V_24 = F_7 ( V_1 , 0x7001 ) ;
if ( ( V_24 & 0xff ) == 0x7f ) {
F_10 ( L_5 , V_24 ) ;
} else if ( ( V_24 & 0xff ) != 0xff ) {
if ( V_24 & 0x0020 ) {
int V_65 = F_7 ( V_1 , 0x7002 ) & 0x10 ;
F_24 ( L_6 , V_13 -> V_23 -> V_66 ,
V_65 ? L_7 : L_8 ) ;
}
if ( V_24 & 0x0001 )
F_16 ( V_13 ) ;
if ( V_24 & 0x0002 ) {
F_14 ( V_14 , & ( V_13 -> V_15 ) ) ;
F_9 ( V_13 ) ;
}
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
F_2 ( V_60 , V_1 + V_64 ) ;
}
V_61 = V_67 ;
}
F_25 ( & ( V_13 -> V_63 ) ) ;
return V_61 ;
}
static int F_26 ( struct V_68 * V_23 )
{
struct V_12 * V_13 = F_27 ( V_23 ) ;
F_28 ( & ( V_13 -> V_21 ) ) ;
return 0 ;
}
static int F_29 ( struct V_68 * V_23 )
{
F_30 ( V_46 , & ( V_23 -> V_47 ) ) ;
return 0 ;
}
static int F_31 ( struct V_68 * V_23 )
{
if ( ! F_32 ( V_46 , & ( V_23 -> V_47 ) ) )
return 0 ;
F_26 ( V_23 ) ;
return 0 ;
}
static int F_33 ( struct V_68 * V_23 , struct V_19 * V_20 )
{
struct V_12 * V_13 = F_27 ( V_23 ) ;
unsigned long V_47 ;
switch ( F_18 ( V_20 ) -> V_35 ) {
case V_69 :
V_23 -> V_24 . V_70 ++ ;
break;
case V_39 :
V_23 -> V_24 . V_71 ++ ;
break;
case V_42 :
V_23 -> V_24 . V_72 ++ ;
break;
} ;
memcpy ( F_34 ( V_20 , 1 ) , & F_18 ( V_20 ) -> V_35 , 1 ) ;
F_35 ( & ( V_13 -> V_21 ) , V_20 ) ;
F_36 ( & ( V_13 -> V_63 ) , V_47 ) ;
F_9 ( V_13 ) ;
F_37 ( & ( V_13 -> V_63 ) , V_47 ) ;
return 0 ;
}
static int F_38 ( struct V_12 * V_13 ,
const unsigned char * V_73 ,
int V_74 )
{
char * V_75 = ( char * ) V_73 ;
char V_76 [ 9 ] ;
unsigned int V_1 , V_26 , V_2 , V_77 , V_78 ;
int V_79 , V_80 = 0 ;
V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_4 ( V_1 , 0x8040 , 0x0400 ) ;
F_39 ( 1 ) ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_39 ( 17 ) ;
while ( V_74 ) {
if ( V_75 [ 0 ] != 'S' ) {
F_10 ( L_9 ) ;
V_80 = - V_81 ;
goto error;
}
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
memcpy ( V_76 , V_75 + 2 , 2 ) ;
V_26 = F_40 ( V_76 , NULL , 16 ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
memcpy ( V_76 , V_75 + 4 , 8 ) ;
V_2 = F_40 ( V_76 , NULL , 16 ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
memcpy ( V_76 , V_75 + ( V_26 * 2 ) + 2 , 2 ) ;
V_77 = F_40 ( V_76 , NULL , 16 ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
for ( V_78 = 0 , V_79 = 0 ; V_79 < V_26 ; V_79 ++ ) {
memcpy ( V_76 , V_75 + ( V_79 * 2 ) + 2 , 2 ) ;
V_78 += F_41 ( V_76 , NULL , 16 ) ;
}
if ( ( ( V_78 + V_77 ) & 0xff ) != 0xff ) {
F_10 ( L_10 ) ;
V_80 = - V_82 ;
goto error;
}
if ( V_75 [ 1 ] == '3' ) {
F_1 ( V_1 , V_2 ) ;
memset ( V_76 , 0 , sizeof( V_76 ) ) ;
for ( V_79 = 0 ; V_79 < ( V_26 - 4 ) / 2 ; V_79 ++ ) {
memcpy ( V_76 , V_75 + ( V_79 * 4 ) + 12 , 4 ) ;
V_78 = F_40 ( V_76 , NULL , 16 ) ;
F_3 ( V_1 , V_78 ) ;
}
}
V_75 += ( V_26 * 2 ) + 6 ;
V_74 -= ( V_26 * 2 ) + 6 ;
}
F_39 ( 17 ) ;
F_1 ( V_1 , 0x3000 ) ;
F_2 ( F_6 ( V_1 + V_64 ) | 0x40 , V_1 + V_64 ) ;
error:
F_39 ( 17 ) ;
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
F_4 ( V_1 , 0x7005 , 0x0000 ) ;
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
return V_80 ;
}
static int F_42 ( struct V_12 * V_13 )
{
const struct V_73 * V_73 ;
struct V_68 * V_23 ;
int V_80 ;
F_43 ( & ( V_13 -> V_63 ) ) ;
F_44 ( & ( V_13 -> V_21 ) ) ;
V_13 -> V_30 = V_31 ;
V_13 -> V_32 = 0 ;
V_13 -> V_29 = NULL ;
V_23 = F_45 () ;
if ( ! V_23 ) {
F_10 ( L_11 ) ;
return - V_83 ;
}
V_13 -> V_23 = V_23 ;
V_23 -> V_84 = V_85 ;
F_46 ( V_23 , V_13 ) ;
F_47 ( V_23 , & V_13 -> V_16 -> V_86 ) ;
V_23 -> V_87 = F_29 ;
V_23 -> V_88 = F_31 ;
V_23 -> V_89 = F_26 ;
V_23 -> V_90 = F_33 ;
V_80 = F_48 ( & V_73 , L_12 , & V_13 -> V_16 -> V_86 ) ;
if ( V_80 < 0 ) {
F_10 ( L_13 ) ;
goto error;
}
V_80 = F_38 ( V_13 , V_73 -> V_22 , V_73 -> V_26 ) ;
F_49 ( V_73 ) ;
if ( V_80 < 0 ) {
F_10 ( L_14 ) ;
goto error;
}
F_50 ( 1000 ) ;
V_80 = F_51 ( V_23 ) ;
if ( V_80 < 0 ) {
F_10 ( L_15 ) ;
goto error;
}
return 0 ;
error:
V_13 -> V_23 = NULL ;
F_52 ( V_23 ) ;
return V_80 ;
}
static int F_53 ( struct V_12 * V_13 )
{
struct V_68 * V_23 = V_13 -> V_23 ;
if ( ! V_23 )
return - V_91 ;
F_31 ( V_23 ) ;
F_54 ( V_23 ) ;
F_52 ( V_23 ) ;
return 0 ;
}
static int F_55 ( struct V_92 * V_93 )
{
struct V_12 * V_13 ;
V_13 = F_56 ( & V_93 -> V_86 , sizeof( * V_13 ) , V_94 ) ;
if ( ! V_13 )
return - V_83 ;
V_13 -> V_16 = V_93 ;
V_93 -> V_95 = V_13 ;
V_93 -> V_96 |= V_97 | V_98 |
V_99 ;
return F_57 ( V_93 ) ;
}
static void F_58 ( struct V_92 * V_93 )
{
F_59 ( V_93 ) ;
}
static int F_60 ( struct V_92 * V_16 , void * V_100 )
{
int * V_101 = V_100 ;
if ( ! V_101 )
V_16 -> V_102 = 16 ;
if ( ( V_16 -> V_17 [ 0 ] -> V_103 != 8 ) || ( V_16 -> V_17 [ 0 ] -> V_18 == 0 ) )
return - V_104 ;
V_16 -> V_17 [ 0 ] -> V_103 = 8 ;
V_16 -> V_17 [ 0 ] -> V_47 &= ~ V_105 ;
V_16 -> V_17 [ 0 ] -> V_47 |= V_106 ;
return F_61 ( V_16 ) ;
}
static int F_62 ( struct V_92 * V_16 ,
void * V_100 )
{
static unsigned int V_107 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_108 ;
if ( V_16 -> V_102 > 3 )
return - V_91 ;
V_16 -> V_17 [ 0 ] -> V_47 &= ~ V_105 ;
V_16 -> V_17 [ 0 ] -> V_47 |= V_106 ;
V_16 -> V_17 [ 0 ] -> V_103 = 8 ;
for ( V_108 = 0 ; V_108 < 5 ; V_108 ++ ) {
V_16 -> V_17 [ 0 ] -> V_18 = V_107 [ V_108 ] ;
V_16 -> V_102 = V_107 [ V_108 ] ? 16 : 3 ;
if ( ! F_61 ( V_16 ) )
return 0 ;
}
return - V_91 ;
}
static int F_57 ( struct V_92 * V_93 )
{
struct V_12 * V_13 = V_93 -> V_95 ;
int V_79 ;
unsigned long V_101 ;
for ( V_101 = 0 ; V_101 < 2 ; V_101 ++ )
if ( ! F_63 ( V_93 , F_60 , ( void * ) V_101 ) )
goto V_109;
if ( ! F_63 ( V_93 , F_62 , NULL ) )
goto V_109;
F_10 ( L_16 ) ;
goto V_110;
V_109:
V_79 = F_64 ( V_93 , & F_22 ) ;
if ( V_79 != 0 )
goto V_110;
V_79 = F_65 ( V_93 ) ;
if ( V_79 != 0 )
goto V_110;
if ( F_42 ( V_13 ) != 0 )
goto V_110;
return 0 ;
V_110:
F_59 ( V_93 ) ;
return - V_91 ;
}
static void F_59 ( struct V_92 * V_93 )
{
struct V_12 * V_13 = V_93 -> V_95 ;
F_53 ( V_13 ) ;
F_66 ( V_93 ) ;
}
