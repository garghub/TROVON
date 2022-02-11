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
if ( V_10 != V_20 -> V_10 )
F_10 ( L_2 ) ;
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
if ( ! V_13 -> V_29 ) {
V_13 -> V_30 = V_31 ;
V_13 -> V_32 = 0 ;
V_13 -> V_29 = F_17 ( V_33 , V_34 ) ;
if ( ! V_13 -> V_29 ) {
F_10 ( L_3 ) ;
return;
}
}
if ( V_13 -> V_30 == V_31 ) {
F_18 ( V_13 -> V_29 ) = F_6 ( V_1 + V_6 ) ;
F_6 ( V_1 + V_7 ) ;
switch ( F_18 ( V_13 -> V_29 ) ) {
case V_35 :
V_13 -> V_30 = V_36 ;
V_13 -> V_32 = V_37 ;
break;
case V_38 :
V_13 -> V_30 = V_39 ;
V_13 -> V_32 = V_40 ;
break;
case V_41 :
V_13 -> V_30 = V_42 ;
V_13 -> V_32 = V_43 ;
break;
default:
F_10 ( L_4 ,
F_18 ( V_13 -> V_29 ) ) ;
V_13 -> V_23 -> V_24 . V_44 ++ ;
F_15 ( V_13 -> V_29 ) ;
V_13 -> V_29 = NULL ;
break;
}
} else {
T_1 V_45 = F_6 ( V_1 + V_6 ) ;
* F_19 ( V_13 -> V_29 , 1 ) = V_45 ;
F_6 ( V_1 + V_7 ) ;
V_13 -> V_32 -- ;
if ( V_13 -> V_32 == 0 ) {
int V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
switch ( V_13 -> V_30 ) {
case V_36 :
V_48 = V_47 ( V_13 -> V_29 ) ;
V_13 -> V_30 = V_53 ;
V_13 -> V_32 = V_48 -> V_54 ;
break;
case V_39 :
V_50 = V_49 ( V_13 -> V_29 ) ;
V_46 = F_20 ( V_50 -> V_46 ) ;
V_13 -> V_30 = V_53 ;
V_13 -> V_32 = V_46 ;
break;
case V_42 :
V_52 = V_51 ( V_13 -> V_29 ) ;
V_13 -> V_30 = V_53 ;
V_13 -> V_32 = V_52 -> V_46 ;
break;
case V_53 :
F_21 ( V_13 -> V_23 , V_13 -> V_29 ) ;
V_13 -> V_29 = NULL ;
break;
}
}
}
}
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
}
static T_2 F_22 ( int V_55 , void * V_56 )
{
struct V_12 * V_13 = V_56 ;
unsigned int V_1 ;
int V_57 ;
T_2 V_58 = V_59 ;
if ( ! V_13 || ! V_13 -> V_23 )
return V_59 ;
V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
F_23 ( & ( V_13 -> V_60 ) ) ;
V_57 = F_6 ( V_1 + V_61 ) ;
if ( V_57 & 0x80 ) {
int V_24 = F_7 ( V_1 , 0x7001 ) ;
if ( ( V_24 & 0xff ) == 0x7f ) {
F_10 ( L_5 , V_24 ) ;
} else if ( ( V_24 & 0xff ) != 0xff ) {
if ( V_24 & 0x0020 ) {
int V_62 = F_7 ( V_1 , 0x7002 ) & 0x10 ;
F_24 ( L_6 , V_13 -> V_23 -> V_63 ,
V_62 ? L_7 : L_8 ) ;
}
if ( V_24 & 0x0001 )
F_16 ( V_13 ) ;
if ( V_24 & 0x0002 ) {
F_14 ( V_14 , & ( V_13 -> V_15 ) ) ;
F_9 ( V_13 ) ;
}
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
F_2 ( V_57 , V_1 + V_61 ) ;
}
V_58 = V_64 ;
}
F_25 ( & ( V_13 -> V_60 ) ) ;
return V_58 ;
}
static int F_26 ( struct V_65 * V_23 )
{
struct V_12 * V_13 = F_27 ( V_23 ) ;
F_28 ( & ( V_13 -> V_21 ) ) ;
return 0 ;
}
static int F_29 ( struct V_65 * V_23 )
{
return 0 ;
}
static int F_30 ( struct V_65 * V_23 )
{
F_26 ( V_23 ) ;
return 0 ;
}
static int F_31 ( struct V_65 * V_23 , struct V_19 * V_20 )
{
struct V_12 * V_13 = F_27 ( V_23 ) ;
unsigned long V_66 ;
switch ( F_18 ( V_20 ) ) {
case V_67 :
V_23 -> V_24 . V_68 ++ ;
break;
case V_38 :
V_23 -> V_24 . V_69 ++ ;
break;
case V_41 :
V_23 -> V_24 . V_70 ++ ;
break;
}
memcpy ( F_32 ( V_20 , 1 ) , & F_18 ( V_20 ) , 1 ) ;
F_33 ( & ( V_13 -> V_21 ) , V_20 ) ;
F_34 ( & ( V_13 -> V_60 ) , V_66 ) ;
F_9 ( V_13 ) ;
F_35 ( & ( V_13 -> V_60 ) , V_66 ) ;
return 0 ;
}
static int F_36 ( struct V_12 * V_13 ,
const unsigned char * V_71 ,
int V_72 )
{
char * V_73 = ( char * ) V_71 ;
char V_74 [ 9 ] ;
unsigned int V_1 , V_75 ;
unsigned long V_26 , V_2 , V_76 ;
int V_77 , V_78 = 0 ;
V_1 = V_13 -> V_16 -> V_17 [ 0 ] -> V_18 ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_4 ( V_1 , 0x8040 , 0x0400 ) ;
F_37 ( 1 ) ;
F_4 ( V_1 , 0x8040 , 0x0404 ) ;
F_37 ( 17 ) ;
while ( V_72 ) {
if ( V_73 [ 0 ] != 'S' ) {
F_10 ( L_9 ) ;
V_78 = - V_79 ;
goto error;
}
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 + 2 , 2 ) ;
if ( F_38 ( V_74 , 16 , & V_26 ) < 0 )
return - V_80 ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 + 4 , 8 ) ;
if ( F_38 ( V_74 , 16 , & V_2 ) < 0 )
return - V_80 ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memcpy ( V_74 , V_73 + ( V_26 * 2 ) + 2 , 2 ) ;
if ( F_38 ( V_74 , 16 , & V_76 ) < 0 )
return - V_80 ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
for ( V_75 = 0 , V_77 = 0 ; V_77 < V_26 ; V_77 ++ ) {
memcpy ( V_74 , V_73 + ( V_77 * 2 ) + 2 , 2 ) ;
V_75 += F_39 ( V_74 , NULL , 16 ) ;
}
if ( ( ( V_75 + V_76 ) & 0xff ) != 0xff ) {
F_10 ( L_10 ) ;
V_78 = - V_81 ;
goto error;
}
if ( V_73 [ 1 ] == '3' ) {
F_1 ( V_1 , V_2 ) ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
for ( V_77 = 0 ; V_77 < ( V_26 - 4 ) / 2 ; V_77 ++ ) {
memcpy ( V_74 , V_73 + ( V_77 * 4 ) + 12 , 4 ) ;
V_75 = F_40 ( V_74 , NULL , 16 ) ;
F_3 ( V_1 , V_75 ) ;
}
}
V_73 += ( V_26 * 2 ) + 6 ;
V_72 -= ( V_26 * 2 ) + 6 ;
}
F_37 ( 17 ) ;
F_1 ( V_1 , 0x3000 ) ;
F_2 ( F_6 ( V_1 + V_61 ) | 0x40 , V_1 + V_61 ) ;
error:
F_37 ( 17 ) ;
F_4 ( V_1 , 0x7006 , 0x0000 ) ;
F_4 ( V_1 , 0x7005 , 0x0000 ) ;
F_4 ( V_1 , 0x7001 , 0x0000 ) ;
return V_78 ;
}
static int F_41 ( struct V_12 * V_13 )
{
const struct V_71 * V_71 ;
struct V_65 * V_23 ;
int V_78 ;
F_42 ( & ( V_13 -> V_60 ) ) ;
F_43 ( & ( V_13 -> V_21 ) ) ;
V_13 -> V_30 = V_31 ;
V_13 -> V_32 = 0 ;
V_13 -> V_29 = NULL ;
V_23 = F_44 () ;
if ( ! V_23 ) {
F_10 ( L_11 ) ;
return - V_82 ;
}
V_13 -> V_23 = V_23 ;
V_23 -> V_83 = V_84 ;
F_45 ( V_23 , V_13 ) ;
F_46 ( V_23 , & V_13 -> V_16 -> V_85 ) ;
V_23 -> V_86 = F_29 ;
V_23 -> V_87 = F_30 ;
V_23 -> V_88 = F_26 ;
V_23 -> V_89 = F_31 ;
V_78 = F_47 ( & V_71 , L_12 , & V_13 -> V_16 -> V_85 ) ;
if ( V_78 < 0 ) {
F_10 ( L_13 ) ;
goto error;
}
V_78 = F_36 ( V_13 , V_71 -> V_22 , V_71 -> V_26 ) ;
F_48 ( V_71 ) ;
if ( V_78 < 0 ) {
F_10 ( L_14 ) ;
goto error;
}
F_49 ( 1000 ) ;
V_78 = F_50 ( V_23 ) ;
if ( V_78 < 0 ) {
F_10 ( L_15 ) ;
goto error;
}
return 0 ;
error:
V_13 -> V_23 = NULL ;
F_51 ( V_23 ) ;
return V_78 ;
}
static int F_52 ( struct V_12 * V_13 )
{
struct V_65 * V_23 = V_13 -> V_23 ;
if ( ! V_23 )
return - V_90 ;
F_30 ( V_23 ) ;
F_53 ( V_23 ) ;
F_51 ( V_23 ) ;
return 0 ;
}
static int F_54 ( struct V_91 * V_92 )
{
struct V_12 * V_13 ;
V_13 = F_55 ( & V_92 -> V_85 , sizeof( * V_13 ) , V_93 ) ;
if ( ! V_13 )
return - V_82 ;
V_13 -> V_16 = V_92 ;
V_92 -> V_94 = V_13 ;
V_92 -> V_95 |= V_96 | V_97 |
V_98 ;
return F_56 ( V_92 ) ;
}
static void F_57 ( struct V_91 * V_92 )
{
F_58 ( V_92 ) ;
}
static int F_59 ( struct V_91 * V_16 , void * V_99 )
{
int * V_100 = V_99 ;
if ( ! V_100 )
V_16 -> V_101 = 16 ;
if ( ( V_16 -> V_17 [ 0 ] -> V_102 != 8 ) || ( V_16 -> V_17 [ 0 ] -> V_18 == 0 ) )
return - V_80 ;
V_16 -> V_17 [ 0 ] -> V_102 = 8 ;
V_16 -> V_17 [ 0 ] -> V_66 &= ~ V_103 ;
V_16 -> V_17 [ 0 ] -> V_66 |= V_104 ;
return F_60 ( V_16 ) ;
}
static int F_61 ( struct V_91 * V_16 ,
void * V_99 )
{
static unsigned int V_105 [ 5 ] = { 0x3f8 , 0x2f8 , 0x3e8 , 0x2e8 , 0x0 } ;
int V_106 ;
if ( V_16 -> V_101 > 3 )
return - V_90 ;
V_16 -> V_17 [ 0 ] -> V_66 &= ~ V_103 ;
V_16 -> V_17 [ 0 ] -> V_66 |= V_104 ;
V_16 -> V_17 [ 0 ] -> V_102 = 8 ;
for ( V_106 = 0 ; V_106 < 5 ; V_106 ++ ) {
V_16 -> V_17 [ 0 ] -> V_18 = V_105 [ V_106 ] ;
V_16 -> V_101 = V_105 [ V_106 ] ? 16 : 3 ;
if ( ! F_60 ( V_16 ) )
return 0 ;
}
return - V_90 ;
}
static int F_56 ( struct V_91 * V_92 )
{
struct V_12 * V_13 = V_92 -> V_94 ;
int V_77 ;
unsigned long V_100 ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ )
if ( ! F_62 ( V_92 , F_59 , ( void * ) V_100 ) )
goto V_107;
if ( ! F_62 ( V_92 , F_61 , NULL ) )
goto V_107;
F_10 ( L_16 ) ;
goto V_108;
V_107:
V_77 = F_63 ( V_92 , & F_22 ) ;
if ( V_77 != 0 )
goto V_108;
V_77 = F_64 ( V_92 ) ;
if ( V_77 != 0 )
goto V_108;
if ( F_41 ( V_13 ) != 0 )
goto V_108;
return 0 ;
V_108:
F_58 ( V_92 ) ;
return - V_90 ;
}
static void F_58 ( struct V_91 * V_92 )
{
struct V_12 * V_13 = V_92 -> V_94 ;
F_52 ( V_13 ) ;
F_65 ( V_92 ) ;
}
