void T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 , char * V_5 )
{
unsigned long V_6 = V_2 -> V_7 + V_3 ;
struct V_1 * V_8 ;
if ( V_2 -> V_9 & V_10 )
V_8 = F_2 ( V_6 , V_4 , V_5 ) ;
else
V_8 = F_3 ( V_6 , V_4 , V_5 ) ;
if ( ! V_8 )
V_6 = 0 ;
return ( void T_1 * ) V_6 ;
}
void F_4 ( struct V_1 * V_2 , void T_1 * V_11 , unsigned long V_4 )
{
if ( V_2 -> V_9 & V_10 )
F_5 ( ( unsigned long ) V_11 , V_4 ) ;
else
F_6 ( ( unsigned long ) V_11 , V_4 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
if ( ! strcmp ( V_13 -> V_5 , L_1 ) ) {
const char * V_14 = F_8 ( V_13 , L_2 , NULL ) ;
if ( V_14 && ! strcmp ( V_14 , L_3 ) )
return 0 ;
if ( ! F_9 ( V_13 , L_4 , NULL ) )
return 0 ;
return 1 ;
}
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
const char * V_14 = F_8 ( V_13 , L_2 , NULL ) ;
if ( V_14 && ! strcmp ( V_14 , L_3 ) )
return 1 ;
if ( ! strcmp ( V_13 -> V_5 , L_1 ) ) {
if ( ! F_9 ( V_13 , L_4 , NULL ) )
return 1 ;
}
return 0 ;
}
static int F_11 ( T_2 * V_15 , const T_2 * V_16 ,
int V_17 , int V_18 , int V_19 )
{
return 0 ;
}
static void F_12 ( struct V_12 * V_13 ,
int * V_20 , int * V_21 )
{
if ( V_20 )
* V_20 = 3 ;
if ( V_21 )
* V_21 = 2 ;
}
static int F_13 ( T_2 * V_15 , const T_2 * V_16 ,
int V_17 , int V_18 , int V_19 )
{
T_2 V_22 [ V_23 ] ;
int V_24 ;
if ( ! ( ( V_15 [ 0 ] ^ V_16 [ 0 ] ) & 0x03000000 ) )
goto V_25;
if ( ( V_15 [ 0 ] & 0x03000000 ) == 0x03000000 &&
( V_16 [ 0 ] & 0x03000000 ) == 0x02000000 )
goto V_25;
return - V_26 ;
V_25:
if ( F_14 ( V_15 + 1 , V_16 + 1 , V_16 + V_17 + V_19 ,
V_17 - 1 , V_18 ) )
return - V_26 ;
memcpy ( V_22 , V_16 + V_17 , V_19 * 4 ) ;
for ( V_24 = 0 ; V_24 < V_17 - 1 ; V_24 ++ )
V_22 [ V_19 - 1 - V_24 ] +=
( V_15 [ V_17 - 1 - V_24 ] -
V_16 [ V_17 - 1 - V_24 ] ) ;
memcpy ( V_15 , V_22 , V_19 * 4 ) ;
return 0 ;
}
static unsigned long F_15 ( const T_2 * V_15 , unsigned long V_9 )
{
T_2 V_27 = V_15 [ 0 ] ;
V_9 = 0 ;
switch( ( V_27 >> 24 ) & 0x03 ) {
case 0x01 :
V_9 |= V_28 ;
break;
case 0x02 :
case 0x03 :
V_9 |= V_10 ;
break;
}
if ( V_27 & 0x40000000 )
V_9 |= V_29 ;
return V_9 ;
}
static int F_16 ( struct V_12 * V_13 )
{
return ! strcmp ( V_13 -> V_5 , L_5 ) ||
! strcmp ( V_13 -> V_5 , L_6 ) ;
}
static struct V_30 * F_17 ( struct V_12 * V_13 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < F_18 ( V_31 ) ; V_24 ++ )
if ( ! V_31 [ V_24 ] . V_32 || V_31 [ V_24 ] . V_32 ( V_13 ) )
return & V_31 [ V_24 ] ;
F_19 () ;
return NULL ;
}
static int T_3 F_20 ( struct V_12 * V_33 ,
struct V_30 * V_34 ,
struct V_30 * V_35 ,
T_2 * V_15 ,
int V_17 , int V_18 , int V_19 )
{
const T_2 * V_36 ;
int V_37 , V_38 ;
V_36 = F_8 ( V_33 , L_4 , & V_38 ) ;
if ( V_36 == NULL || V_38 == 0 ) {
T_2 V_22 [ V_23 ] ;
int V_24 ;
memset ( V_22 , 0 , V_19 * 4 ) ;
for ( V_24 = 0 ; V_24 < V_17 ; V_24 ++ )
V_22 [ V_19 - 1 - V_24 ] =
V_15 [ V_17 - 1 - V_24 ] ;
memcpy ( V_15 , V_22 , V_19 * 4 ) ;
return 0 ;
}
V_38 /= 4 ;
V_37 = V_17 + V_19 + V_18 ;
for (; V_38 >= V_37 ; V_38 -= V_37 , V_36 += V_37 ) {
if ( ! V_34 -> V_39 ( V_15 , V_36 , V_17 , V_18 , V_19 ) )
return 0 ;
}
if ( ! strcmp ( V_34 -> V_5 , L_1 ) &&
( V_15 [ 0 ] & 0x03000000 ) == 0x01000000 )
return 0 ;
return 1 ;
}
static int T_3 F_21 ( struct V_12 * V_40 )
{
if ( F_9 ( V_40 , L_4 , NULL ) != NULL )
return 0 ;
if ( ! strcmp ( V_40 -> V_5 , L_7 ) ||
! strcmp ( V_40 -> V_5 , L_8 ) ||
! strcmp ( V_40 -> V_5 , L_9 ) ||
! strcmp ( V_40 -> V_5 , L_10 ) )
return 0 ;
if ( ! strcmp ( V_40 -> V_5 , L_1 ) )
return 0 ;
return 1 ;
}
static void T_3 F_22 ( struct V_41 * V_42 ,
struct V_43 * V_33 )
{
struct V_41 * V_44 ;
struct V_30 * V_34 ;
int V_17 , V_18 ;
int V_45 , V_46 ;
const void * V_47 ;
if ( ! V_33 )
return;
V_44 = F_23 ( V_33 ) ;
V_34 = F_17 ( V_44 -> V_48 . V_49 ) ;
V_34 -> V_50 ( V_42 -> V_48 . V_49 , & V_17 , & V_18 ) ;
V_47 = F_8 ( V_42 -> V_48 . V_49 , V_34 -> V_51 , & V_46 ) ;
if ( ! V_47 || V_46 == 0 )
return;
V_46 /= 4 ;
V_46 /= V_17 + V_18 ;
if ( V_46 > V_52 ) {
F_24 ( V_53 L_11
L_12 ,
V_42 -> V_48 . V_49 -> V_54 , V_46 , V_52 ) ;
V_46 = V_52 ;
}
V_42 -> V_1 = V_42 -> V_55 . V_1 ;
V_42 -> V_56 = V_46 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
struct V_1 * V_8 = & V_42 -> V_1 [ V_45 ] ;
T_2 V_15 [ V_23 ] ;
const T_2 * V_57 = ( V_47 + ( V_45 * ( ( V_17 + V_18 ) * 4 ) ) ) ;
struct V_12 * V_58 = V_42 -> V_48 . V_49 ;
struct V_12 * V_40 = V_44 -> V_48 . V_49 ;
struct V_30 * V_35 , * V_59 ;
T_4 V_4 , V_22 = V_60 ;
unsigned long V_9 ;
int V_61 , V_62 ;
int V_19 , V_63 ;
V_4 = F_25 ( V_57 + V_17 , V_18 ) ;
memcpy ( V_15 , V_57 , V_17 * 4 ) ;
V_9 = V_34 -> V_64 ( V_15 , 0 ) ;
if ( F_21 ( V_40 ) ) {
V_22 = F_25 ( V_15 , V_17 ) ;
goto V_65;
}
V_61 = V_17 ;
V_62 = V_18 ;
V_59 = V_34 ;
while ( 1 ) {
V_58 = V_40 ;
V_40 = V_58 -> V_33 ;
if ( ! V_40 ) {
V_22 = F_25 ( V_15 , V_61 ) ;
break;
}
V_35 = F_17 ( V_40 ) ;
V_35 -> V_50 ( V_58 , & V_19 , & V_63 ) ;
if ( F_20 ( V_58 , V_59 , V_35 , V_15 ,
V_61 , V_62 , V_19 ) )
break;
V_9 = V_35 -> V_64 ( V_15 , V_9 ) ;
V_61 = V_19 ;
V_62 = V_63 ;
V_59 = V_35 ;
}
V_65:
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
if ( V_66 )
F_24 ( L_13 ,
V_42 -> V_48 . V_49 -> V_54 , V_45 ,
V_22 ) ;
if ( V_22 != V_60 ) {
if ( V_67 == V_68 )
V_22 &= 0x0fffffffffffffffUL ;
V_8 -> V_7 = V_22 ;
V_8 -> V_69 = V_22 + V_4 - 1 ;
V_8 -> V_9 = V_9 ;
}
V_8 -> V_5 = V_42 -> V_48 . V_49 -> V_5 ;
}
}
static struct V_12 * T_3
F_26 ( struct V_12 * V_58 , struct V_12 * V_40 ,
const T_2 * V_70 , int V_71 , const T_2 * V_72 ,
unsigned int * V_73 )
{
struct V_12 * V_74 ;
unsigned int V_75 = * V_73 ;
struct V_30 * V_34 ;
T_5 V_76 ;
const T_2 * V_57 ;
int V_17 , V_46 , V_24 ;
V_34 = F_17 ( V_40 ) ;
V_34 -> V_50 ( V_58 , & V_17 , NULL ) ;
V_57 = F_8 ( V_58 , L_14 , & V_46 ) ;
if ( ! V_57 || ! V_46 )
return NULL ;
V_71 /= ( ( V_17 + 3 ) * 4 ) ;
V_76 = 0 ;
for ( V_24 = 0 ; V_24 < V_71 ; V_24 ++ ) {
int V_77 ;
for ( V_77 = 0 ; V_77 < V_17 ; V_77 ++ ) {
if ( ( V_57 [ V_77 ] & V_72 [ V_77 ] ) != V_70 [ V_77 ] )
goto V_78;
}
if ( V_70 [ V_17 ] == V_75 ) {
V_76 = V_70 [ V_17 + 1 ] ;
V_75 = V_70 [ V_17 + 2 ] ;
break;
}
V_78:
V_70 += ( V_17 + 3 ) ;
}
if ( V_24 == V_71 ) {
if ( V_40 -> V_79 )
return V_40 ;
return NULL ;
}
* V_73 = V_75 ;
V_74 = F_27 ( V_76 ) ;
return V_74 ;
}
static unsigned int T_3 F_28 ( struct V_12 * V_58 ,
struct V_12 * V_40 ,
unsigned int V_75 )
{
const struct V_80 * V_81 ;
unsigned int V_34 , V_82 , V_83 , V_6 ;
if ( V_75 < 1 || V_75 > 4 )
return V_75 ;
V_81 = F_8 ( V_58 , L_14 , NULL ) ;
if ( ! V_81 )
return V_75 ;
V_34 = ( V_81 -> V_84 >> 16 ) & 0xff ;
V_82 = ( V_81 -> V_84 >> 8 ) & 0xff ;
V_83 = ( V_82 >> 3 ) & 0x1f ;
if ( V_40 -> V_79 ) {
if ( V_34 & 0x80 ) {
V_34 = 0x00 ;
V_83 = ( V_83 - 1 ) << 2 ;
} else {
V_34 = 0x10 ;
V_83 = ( V_83 - 2 ) << 2 ;
}
V_75 -= 1 ;
V_6 = ( V_34 | V_83 | V_75 ) ;
} else {
V_6 = ( ( V_75 - 1 + ( V_83 & 3 ) ) & 3 ) + 1 ;
}
return V_6 ;
}
static unsigned int T_3 F_29 ( struct V_41 * V_42 ,
struct V_43 * V_33 ,
unsigned int V_75 )
{
struct V_12 * V_58 = V_42 -> V_48 . V_49 ;
struct V_12 * V_40 , * V_85 ;
unsigned int V_86 = V_75 ;
int V_87 ;
if ( V_75 == 0xffffffff )
return V_75 ;
if ( V_58 -> V_79 ) {
V_75 = V_58 -> V_79 -> V_88 ( V_58 , V_75 ,
V_58 -> V_79 -> V_89 ) ;
if ( V_90 )
F_24 ( L_15 ,
V_58 -> V_54 , V_86 , V_75 ) ;
goto V_91;
}
V_40 = V_58 -> V_33 ;
V_85 = NULL ;
while ( V_40 ) {
const void * V_70 , * V_92 ;
int V_71 ;
V_70 = F_8 ( V_40 , L_16 , & V_71 ) ;
V_92 = F_8 ( V_40 , L_17 , NULL ) ;
if ( V_70 && V_92 ) {
struct V_12 * V_93 ;
int V_94 = V_75 ;
V_93 = F_26 ( V_58 , V_40 ,
V_70 , V_71 , V_92 ,
& V_75 ) ;
if ( V_90 )
F_24 ( L_18 ,
V_42 -> V_48 . V_49 -> V_54 ,
V_40 -> V_54 , V_94 ,
( V_93 ? V_93 -> V_54 : L_19 ) , V_75 ) ;
if ( ! V_93 )
break;
if ( V_93 -> V_79 ) {
V_85 = V_93 ;
break;
}
} else {
if ( ! strcmp ( V_40 -> V_5 , L_1 ) ) {
unsigned int V_94 = V_75 ;
V_75 = F_28 ( V_58 , V_40 , V_75 ) ;
if ( V_90 )
F_24 ( L_20
L_21 ,
V_42 -> V_48 . V_49 -> V_54 ,
V_40 -> V_54 , V_94 ,
V_75 ) ;
}
if ( V_40 -> V_79 ) {
V_85 = V_40 ;
break;
}
}
V_58 = V_40 ;
V_40 = V_40 -> V_33 ;
}
if ( ! V_85 )
return V_86 ;
V_75 = V_85 -> V_79 -> V_88 ( V_42 -> V_48 . V_49 , V_75 ,
V_85 -> V_79 -> V_89 ) ;
if ( V_90 )
F_24 ( L_22 ,
V_42 -> V_48 . V_49 -> V_54 , V_85 -> V_54 , V_86 , V_75 ) ;
V_91:
V_87 = F_30 ( V_58 ) ;
if ( V_87 != - 1 ) {
T_6 V_95 ;
F_31 ( & V_95 , F_32 ( V_87 ) ) ;
F_33 ( V_75 , & V_95 ) ;
}
return V_75 ;
}
static struct V_41 * T_3 F_34 ( struct V_12 * V_58 ,
struct V_43 * V_33 )
{
struct V_41 * V_42 = F_35 ( sizeof( * V_42 ) , V_96 ) ;
const unsigned int * V_75 ;
struct V_97 * V_98 ;
int V_99 , V_24 ;
if ( ! V_42 )
return NULL ;
V_98 = & V_42 -> V_48 . V_55 ;
V_98 -> V_42 = V_42 ;
V_42 -> V_48 . V_49 = V_58 ;
V_75 = F_8 ( V_58 , L_23 , & V_99 ) ;
if ( V_75 ) {
V_42 -> V_55 . V_100 = V_99 / 4 ;
if ( V_42 -> V_55 . V_100 > V_101 ) {
F_24 ( V_53 L_24
L_12 ,
V_58 -> V_54 , V_42 -> V_55 . V_100 , V_101 ) ;
V_42 -> V_55 . V_100 = V_101 ;
}
memcpy ( V_42 -> V_55 . V_102 , V_75 , V_42 -> V_55 . V_100 * 4 ) ;
} else {
V_42 -> V_55 . V_100 = 0 ;
}
F_22 ( V_42 , V_33 ) ;
for ( V_24 = 0 ; V_24 < V_42 -> V_55 . V_100 ; V_24 ++ )
V_42 -> V_55 . V_102 [ V_24 ] = F_29 ( V_42 , V_33 , V_42 -> V_55 . V_102 [ V_24 ] ) ;
V_42 -> V_48 . V_33 = V_33 ;
V_42 -> V_48 . V_34 = & V_103 ;
if ( ! V_33 )
F_36 ( & V_42 -> V_48 , L_25 ) ;
else
F_36 ( & V_42 -> V_48 , L_26 , V_58 -> T_5 ) ;
if ( F_37 ( V_42 ) ) {
F_24 ( L_27 ,
V_58 -> V_54 ) ;
F_38 ( V_42 ) ;
V_42 = NULL ;
}
return V_42 ;
}
static void T_3 F_39 ( struct V_12 * V_58 , struct V_43 * V_33 )
{
while ( V_58 ) {
struct V_41 * V_42 = F_34 ( V_58 , V_33 ) ;
if ( V_42 )
F_39 ( V_58 -> V_104 , & V_42 -> V_48 ) ;
V_58 = V_58 -> V_105 ;
}
}
static int T_3 F_40 ( void )
{
struct V_12 * V_106 = F_41 ( L_28 ) ;
struct V_41 * V_33 ;
V_33 = F_34 ( V_106 , NULL ) ;
if ( ! V_33 )
return 0 ;
F_39 ( V_106 -> V_104 , & V_33 -> V_48 ) ;
return 0 ;
}
static int T_3 F_42 ( char * V_107 )
{
int V_108 = 0 ;
F_43 ( & V_107 , & V_108 ) ;
if ( V_108 & 1 )
V_66 = 1 ;
if ( V_108 & 2 )
V_90 = 1 ;
return 1 ;
}
