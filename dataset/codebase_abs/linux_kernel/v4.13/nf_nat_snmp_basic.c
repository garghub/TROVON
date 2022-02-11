static void F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 ,
unsigned int V_4 )
{
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_3 + V_4 ;
V_2 -> V_7 = V_3 ;
V_2 -> error = V_8 ;
}
static unsigned char F_2 ( struct V_1 * V_2 , unsigned char * V_9 )
{
if ( V_2 -> V_7 >= V_2 -> V_6 ) {
V_2 -> error = V_10 ;
return 0 ;
}
* V_9 = * ( V_2 -> V_7 ) ++ ;
return 1 ;
}
static unsigned char F_3 ( struct V_1 * V_2 , unsigned int * V_11 )
{
unsigned char V_9 ;
* V_11 = 0 ;
do
{
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_11 <<= 7 ;
* V_11 |= V_9 & 0x7F ;
} while ( ( V_9 & 0x80 ) == 0x80 );
return 1 ;
}
static unsigned char F_4 ( struct V_1 * V_2 ,
unsigned int * V_12 ,
unsigned int * V_13 ,
unsigned int * V_11 )
{
unsigned char V_9 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_12 = ( V_9 & 0xC0 ) >> 6 ;
* V_13 = ( V_9 & 0x20 ) >> 5 ;
* V_11 = ( V_9 & 0x1F ) ;
if ( * V_11 == 0x1F ) {
if ( ! F_3 ( V_2 , V_11 ) )
return 0 ;
}
return 1 ;
}
static unsigned char F_5 ( struct V_1 * V_2 ,
unsigned int * V_14 ,
unsigned int * V_4 )
{
unsigned char V_9 , V_15 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 == 0x80 )
* V_14 = 0 ;
else {
* V_14 = 1 ;
if ( V_9 < 0x80 )
* V_4 = V_9 ;
else {
V_15 = V_9 & 0x7F ;
* V_4 = 0 ;
while ( V_15 > 0 ) {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_4 <<= 8 ;
* V_4 |= V_9 ;
V_15 -- ;
}
}
}
if ( * V_4 > V_2 -> V_6 - V_2 -> V_7 )
return 0 ;
return 1 ;
}
static unsigned char F_6 ( struct V_1 * V_2 ,
unsigned char * * V_16 ,
unsigned int * V_12 ,
unsigned int * V_13 ,
unsigned int * V_11 )
{
unsigned int V_14 , V_4 ;
if ( ! F_4 ( V_2 , V_12 , V_13 , V_11 ) )
return 0 ;
V_14 = V_4 = 0 ;
if ( ! F_5 ( V_2 , & V_14 , & V_4 ) )
return 0 ;
if ( * V_13 == V_17 && ! V_14 )
return 0 ;
if ( V_14 )
* V_16 = V_2 -> V_7 + V_4 ;
else
* V_16 = NULL ;
return 1 ;
}
static unsigned char F_7 ( struct V_1 * V_2 , unsigned char * V_16 )
{
unsigned char V_9 ;
if ( V_16 == NULL ) {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 != 0x00 ) {
V_2 -> error = V_18 ;
return 0 ;
}
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 != 0x00 ) {
V_2 -> error = V_18 ;
return 0 ;
}
return 1 ;
} else {
if ( V_2 -> V_7 != V_16 ) {
V_2 -> error = V_19 ;
return 0 ;
}
return 1 ;
}
}
static unsigned char F_8 ( struct V_1 * V_2 , unsigned char * V_16 )
{
V_2 -> V_7 = V_16 ;
return 1 ;
}
static unsigned char F_9 ( struct V_1 * V_2 ,
unsigned char * V_16 ,
long * integer )
{
unsigned char V_9 ;
unsigned int V_4 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer = ( signed char ) V_9 ;
V_4 = 1 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ++ V_4 > sizeof ( long ) ) {
V_2 -> error = V_20 ;
return 0 ;
}
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer <<= 8 ;
* integer |= V_9 ;
}
return 1 ;
}
static unsigned char F_10 ( struct V_1 * V_2 ,
unsigned char * V_16 ,
unsigned int * integer )
{
unsigned char V_9 ;
unsigned int V_4 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer = V_9 ;
if ( V_9 == 0 ) V_4 = 0 ;
else V_4 = 1 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ++ V_4 > sizeof ( unsigned int ) ) {
V_2 -> error = V_20 ;
return 0 ;
}
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer <<= 8 ;
* integer |= V_9 ;
}
return 1 ;
}
static unsigned char F_11 ( struct V_1 * V_2 ,
unsigned char * V_16 ,
unsigned long * integer )
{
unsigned char V_9 ;
unsigned int V_4 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer = V_9 ;
if ( V_9 == 0 ) V_4 = 0 ;
else V_4 = 1 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ++ V_4 > sizeof ( unsigned long ) ) {
V_2 -> error = V_20 ;
return 0 ;
}
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* integer <<= 8 ;
* integer |= V_9 ;
}
return 1 ;
}
static unsigned char F_12 ( struct V_1 * V_2 ,
unsigned char * V_16 ,
unsigned char * * V_21 ,
unsigned int * V_4 )
{
unsigned char * V_22 ;
* V_4 = 0 ;
* V_21 = F_13 ( V_16 - V_2 -> V_7 , V_23 ) ;
if ( * V_21 == NULL )
return 0 ;
V_22 = * V_21 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ! F_2 ( V_2 , V_22 ++ ) ) {
F_14 ( * V_21 ) ;
* V_21 = NULL ;
return 0 ;
}
( * V_4 ) ++ ;
}
return 1 ;
}
static unsigned char F_15 ( struct V_1 * V_2 ,
unsigned long * V_24 )
{
unsigned char V_9 ;
* V_24 = 0 ;
do {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_24 <<= 7 ;
* V_24 |= V_9 & 0x7F ;
} while ( ( V_9 & 0x80 ) == 0x80 );
return 1 ;
}
static unsigned char F_16 ( struct V_1 * V_2 ,
unsigned char * V_16 ,
unsigned long * * V_25 ,
unsigned int * V_4 )
{
unsigned long V_24 ;
unsigned long * V_26 ;
T_1 V_27 ;
V_27 = V_16 - V_2 -> V_7 + 1 ;
if ( V_27 < 2 || V_27 > V_28 /sizeof( unsigned long ) )
return 0 ;
* V_25 = F_13 ( V_27 * sizeof( unsigned long ) , V_23 ) ;
if ( * V_25 == NULL )
return 0 ;
V_26 = * V_25 ;
if ( ! F_15 ( V_2 , & V_24 ) ) {
F_14 ( * V_25 ) ;
* V_25 = NULL ;
return 0 ;
}
if ( V_24 < 40 ) {
V_26 [ 0 ] = 0 ;
V_26 [ 1 ] = V_24 ;
} else if ( V_24 < 80 ) {
V_26 [ 0 ] = 1 ;
V_26 [ 1 ] = V_24 - 40 ;
} else {
V_26 [ 0 ] = 2 ;
V_26 [ 1 ] = V_24 - 80 ;
}
* V_4 = 2 ;
V_26 += 2 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ++ ( * V_4 ) > V_27 ) {
V_2 -> error = V_20 ;
F_14 ( * V_25 ) ;
* V_25 = NULL ;
return 0 ;
}
if ( ! F_15 ( V_2 , V_26 ++ ) ) {
F_14 ( * V_25 ) ;
* V_25 = NULL ;
return 0 ;
}
}
return 1 ;
}
static unsigned char F_17 ( unsigned int V_11 ,
unsigned int V_12 ,
unsigned short * V_29 )
{
const struct V_30 * V_31 ;
V_31 = V_32 ;
while ( V_31 -> V_29 != - 1 ) {
if ( V_31 -> V_11 == V_11 && V_31 -> V_33 == V_12 ) {
* V_29 = V_31 -> V_29 ;
return 1 ;
}
V_31 ++ ;
}
return 0 ;
}
static unsigned char F_18 ( struct V_1 * V_2 ,
struct V_34 * * V_35 )
{
unsigned int V_12 , V_13 , V_11 , V_4 , V_36 ;
unsigned short type ;
unsigned char * V_16 , * V_6 , * V_37 ;
unsigned long * V_38 , * V_39 ;
unsigned long V_40 ;
long V_41 ;
* V_35 = NULL ;
V_39 = NULL ;
if ( ! F_6 ( V_2 , & V_16 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_43 || V_11 != V_44 )
return 0 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_45 )
return 0 ;
if ( ! F_16 ( V_2 , V_6 , & V_39 , & V_36 ) )
return 0 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
if ( V_13 != V_17 ) {
F_14 ( V_39 ) ;
return 0 ;
}
type = 0 ;
if ( ! F_17 ( V_11 , V_12 , & type ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
V_41 = 0 ;
switch ( type ) {
case V_46 :
V_4 = sizeof( long ) ;
if ( ! F_9 ( V_2 , V_6 , & V_41 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
* V_35 = F_13 ( sizeof( struct V_34 ) + V_4 , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_39 ) ;
return 0 ;
}
( * V_35 ) -> V_29 . V_41 [ 0 ] = V_41 ;
break;
case V_47 :
case V_48 :
if ( ! F_12 ( V_2 , V_6 , & V_37 , & V_4 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
* V_35 = F_13 ( sizeof( struct V_34 ) + V_4 , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_37 ) ;
F_14 ( V_39 ) ;
return 0 ;
}
memcpy ( ( * V_35 ) -> V_29 . V_49 , V_37 , V_4 ) ;
F_14 ( V_37 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
V_4 = 0 ;
* V_35 = F_13 ( sizeof( struct V_34 ) , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_39 ) ;
return 0 ;
}
if ( ! F_8 ( V_2 , V_6 ) ) {
F_14 ( V_39 ) ;
F_14 ( * V_35 ) ;
* V_35 = NULL ;
return 0 ;
}
break;
case V_54 :
if ( ! F_16 ( V_2 , V_6 , & V_38 , & V_4 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
V_4 *= sizeof( unsigned long ) ;
* V_35 = F_13 ( sizeof( struct V_34 ) + V_4 , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_38 ) ;
F_14 ( V_39 ) ;
return 0 ;
}
memcpy ( ( * V_35 ) -> V_29 . V_40 , V_38 , V_4 ) ;
F_14 ( V_38 ) ;
break;
case V_55 :
if ( ! F_12 ( V_2 , V_6 , & V_37 , & V_4 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
if ( V_4 != 4 ) {
F_14 ( V_37 ) ;
F_14 ( V_39 ) ;
return 0 ;
}
* V_35 = F_13 ( sizeof( struct V_34 ) + V_4 , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_37 ) ;
F_14 ( V_39 ) ;
return 0 ;
}
memcpy ( ( * V_35 ) -> V_29 . V_56 , V_37 , V_4 ) ;
F_14 ( V_37 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
V_4 = sizeof( unsigned long ) ;
if ( ! F_11 ( V_2 , V_6 , & V_40 ) ) {
F_14 ( V_39 ) ;
return 0 ;
}
* V_35 = F_13 ( sizeof( struct V_34 ) + V_4 , V_23 ) ;
if ( * V_35 == NULL ) {
F_14 ( V_39 ) ;
return 0 ;
}
( * V_35 ) -> V_29 . V_40 [ 0 ] = V_40 ;
break;
default:
F_14 ( V_39 ) ;
return 0 ;
}
( * V_35 ) -> V_60 = V_4 ;
( * V_35 ) -> type = type ;
( * V_35 ) -> V_39 = V_39 ;
( * V_35 ) -> V_61 = V_36 ;
if ( ! F_7 ( V_2 , V_16 ) ) {
F_14 ( V_39 ) ;
F_14 ( * V_35 ) ;
* V_35 = NULL ;
return 0 ;
}
return 1 ;
}
static unsigned char T_2
F_19 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
unsigned int V_12 , V_13 , V_11 ;
unsigned char * V_6 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
return 0 ;
if ( ! F_11 ( V_2 , V_6 , & V_63 -> V_39 ) )
return 0 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
return 0 ;
if ( ! F_10 ( V_2 , V_6 , & V_63 -> V_65 ) )
return 0 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
return 0 ;
if ( ! F_10 ( V_2 , V_6 , & V_63 -> V_66 ) )
return 0 ;
return 1 ;
}
static void F_20 ( T_3 * V_67 ,
const unsigned char * V_26 ,
const unsigned char * V_68 ,
int V_69 )
{
unsigned char V_70 [ 4 ] ;
if ( V_69 & 1 ) {
V_70 [ 0 ] = ~ 0 ;
V_70 [ 1 ] = ~ * V_26 ;
V_70 [ 2 ] = 0 ;
V_70 [ 3 ] = * V_68 ;
} else {
V_70 [ 0 ] = ~ * V_26 ;
V_70 [ 1 ] = ~ 0 ;
V_70 [ 2 ] = * V_68 ;
V_70 [ 3 ] = 0 ;
}
* V_67 = F_21 ( F_22 ( V_70 , 4 , ~ F_23 ( * V_67 ) ) ) ;
}
static inline void F_24 ( unsigned char * V_5 ,
unsigned char * V_71 ,
const struct V_72 * V_73 ,
T_3 * V_74 )
{
if ( V_73 -> V_75 == F_25 ( V_71 ) ) {
T_4 V_76 ;
if ( V_77 )
memcpy ( & V_76 , V_71 , sizeof( V_76 ) ) ;
* V_71 = V_73 -> V_78 ;
if ( * V_74 ) {
F_20 ( V_74 ,
& V_73 -> V_75 , & V_73 -> V_78 , V_71 - V_5 ) ;
}
if ( V_77 )
F_26 ( V_79 L_1 ,
& V_76 , V_71 ) ;
}
}
static unsigned char T_2
F_27 ( struct V_1 * V_2 , struct V_80 * V_81 ,
const struct V_72 * V_73 ,
T_3 * V_74 )
{
unsigned int V_12 , V_13 , V_11 , V_4 ;
unsigned char * V_6 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_45 )
return 0 ;
if ( ! F_16 ( V_2 , V_6 , & V_81 -> V_39 , & V_81 -> V_61 ) )
return 0 ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
goto V_82;
if ( ! ( ( V_12 == V_83 && V_13 == V_17 && V_11 == V_84 ) ||
( V_12 == V_42 && V_13 == V_17 && V_11 == V_85 ) ) )
goto V_82;
if ( ! F_12 ( V_2 , V_6 , ( unsigned char * * ) & V_81 -> V_86 , & V_4 ) )
goto V_82;
if ( V_4 != 4 )
goto V_87;
F_24 ( V_2 -> V_5 , V_2 -> V_7 - 4 , V_73 , V_74 ) ;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
goto V_87;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
goto V_87;
if ( ! F_10 ( V_2 , V_6 , & V_81 -> V_88 ) )
goto V_87;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
goto V_87;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
goto V_87;
if ( ! F_10 ( V_2 , V_6 , & V_81 -> V_89 ) )
goto V_87;
if ( ! F_6 ( V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
goto V_87;
if ( ! ( ( V_12 == V_83 && V_13 == V_17 && V_11 == V_90 ) ||
( V_12 == V_42 && V_13 == V_17 && V_11 == V_64 ) ) )
goto V_87;
if ( ! F_11 ( V_2 , V_6 , & V_81 -> time ) )
goto V_87;
return 1 ;
V_87:
F_14 ( ( unsigned long * ) V_81 -> V_86 ) ;
V_82:
F_14 ( V_81 -> V_39 ) ;
return 0 ;
}
static int F_28 ( unsigned char * V_91 ,
T_5 V_4 ,
const struct V_72 * V_73 ,
T_3 * V_74 )
{
unsigned char * V_16 , * V_6 ;
unsigned int V_12 , V_13 , V_11 , V_92 , V_93 ;
struct V_1 V_2 ;
struct V_94 V_95 ;
struct V_34 * V_35 ;
if ( V_77 > 1 )
F_29 ( V_79 , L_2 , V_96 , 16 , 1 ,
V_91 , V_4 , 0 ) ;
F_1 ( & V_2 , V_91 , V_4 ) ;
if ( ! F_6 ( & V_2 , & V_16 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_43 || V_11 != V_44 )
return 0 ;
if ( ! F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_64 )
return 0 ;
if ( ! F_10 ( & V_2 , V_6 , & V_92 ) )
return 0 ;
if ( V_77 > 1 )
F_30 ( L_3 , V_92 + 1 ) ;
if ( V_92 > 1 )
return 1 ;
if ( ! F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_17 || V_11 != V_85 )
return 0 ;
if ( ! F_12 ( & V_2 , V_6 , & V_95 . V_97 , & V_95 . V_4 ) )
return 0 ;
if ( V_77 > 1 ) {
unsigned int V_98 ;
F_30 ( L_4 ) ;
for ( V_98 = 0 ; V_98 < V_95 . V_4 ; V_98 ++ )
F_31 ( L_5 , V_95 . V_97 [ V_98 ] ) ;
F_31 ( L_6 ) ;
}
F_14 ( V_95 . V_97 ) ;
if ( ! F_6 ( & V_2 , & V_16 , & V_12 , & V_13 , & V_93 ) )
return 0 ;
if ( V_12 != V_99 || V_13 != V_43 )
return 0 ;
if ( V_77 > 1 ) {
static const unsigned char * const V_100 [] = {
[ V_101 ] = L_7 ,
[ V_102 ] = L_8 ,
[ V_103 ] = L_9 ,
[ V_104 ] = L_10 ,
[ V_105 ] = L_11 ,
[ V_106 ] = L_12 ,
[ V_107 ] = L_13 ,
[ V_108 ] = L_14
} ;
if ( V_93 > V_108 )
F_30 ( L_15 , V_93 ) ;
else
F_30 ( L_16 , V_100 [ V_93 ] ) ;
}
if ( V_93 != V_103 &&
V_93 != V_105 && V_93 != V_108 )
return 1 ;
if ( V_93 == V_105 ) {
struct V_80 V_81 ;
unsigned char V_109 = F_27 ( & V_2 , & V_81 , V_73 , V_74 ) ;
if ( V_109 ) {
F_14 ( V_81 . V_39 ) ;
F_14 ( ( unsigned long * ) V_81 . V_86 ) ;
} else
return V_109 ;
} else {
struct V_62 V_110 ;
if ( ! F_19 ( & V_2 , & V_110 ) )
return 0 ;
if ( V_77 > 1 )
F_30 ( L_17
L_18 , V_110 . V_39 , V_110 . V_65 ,
V_110 . V_66 ) ;
}
if ( ! F_6 ( & V_2 , & V_16 , & V_12 , & V_13 , & V_11 ) )
return 0 ;
if ( V_12 != V_42 || V_13 != V_43 || V_11 != V_44 )
return 0 ;
while ( ! F_7 ( & V_2 , V_16 ) ) {
unsigned int V_98 ;
if ( ! F_18 ( & V_2 , & V_35 ) ) {
if ( V_35 ) {
F_14 ( V_35 -> V_39 ) ;
F_14 ( V_35 ) ;
}
return 0 ;
}
if ( V_77 > 1 ) {
F_30 ( L_19 ) ;
for ( V_98 = 0 ; V_98 < V_35 -> V_61 ; V_98 ++ ) {
if ( V_98 > 0 )
F_31 ( L_20 ) ;
F_31 ( L_21 , V_35 -> V_39 [ V_98 ] ) ;
}
F_31 ( L_22 , V_35 -> type ) ;
}
if ( V_35 -> type == V_55 )
F_24 ( V_2 . V_5 , V_2 . V_7 - 4 , V_73 , V_74 ) ;
F_14 ( V_35 -> V_39 ) ;
F_14 ( V_35 ) ;
}
if ( ! F_7 ( & V_2 , V_16 ) )
return 0 ;
return 1 ;
}
static int F_32 ( struct V_111 * V_112 ,
enum V_113 V_114 ,
struct V_115 * V_116 )
{
struct V_117 * V_118 = F_33 ( V_116 ) ;
struct V_119 * V_120 = (struct V_119 * ) ( ( V_121 * ) V_118 + V_118 -> V_122 ) ;
T_5 V_123 = F_34 ( V_120 -> V_4 ) ;
T_5 V_124 = V_123 - sizeof( struct V_119 ) ;
int V_125 = F_35 ( V_114 ) ;
struct V_72 V_73 ;
if ( V_125 == V_126 ) {
V_73 . V_75 = F_25 ( & V_112 -> V_127 [ V_125 ] . V_128 . V_129 . V_130 . V_131 ) ;
V_73 . V_78 = F_25 ( & V_112 -> V_127 [ ! V_125 ] . V_128 . V_132 . V_130 . V_131 ) ;
} else {
V_73 . V_75 = F_25 ( & V_112 -> V_127 [ ! V_125 ] . V_128 . V_129 . V_130 . V_131 ) ;
V_73 . V_78 = F_25 ( & V_112 -> V_127 [ V_125 ] . V_128 . V_132 . V_130 . V_131 ) ;
}
if ( V_73 . V_75 == V_73 . V_78 )
return V_133 ;
if ( ! F_28 ( ( unsigned char * ) V_120 + sizeof( struct V_119 ) ,
V_124 , & V_73 , & V_120 -> V_74 ) ) {
F_36 ( L_23 ) ;
return V_134 ;
}
return V_133 ;
}
static int F_37 ( struct V_115 * V_116 , unsigned int V_135 ,
struct V_111 * V_112 ,
enum V_113 V_114 )
{
int V_125 = F_35 ( V_114 ) ;
unsigned int V_109 ;
const struct V_117 * V_118 = F_33 ( V_116 ) ;
const struct V_119 * V_120 = (struct V_119 * ) ( ( V_121 * ) V_118 + V_118 -> V_122 ) ;
if ( V_120 -> V_136 == F_38 ( V_137 ) && V_125 != V_138 )
return V_133 ;
if ( V_120 -> V_139 == F_38 ( V_140 ) && V_125 != V_126 )
return V_133 ;
if ( ! ( V_112 -> V_141 & V_142 ) )
return V_133 ;
if ( F_34 ( V_120 -> V_4 ) != V_116 -> V_4 - ( V_118 -> V_122 << 2 ) ) {
F_36 ( L_24 ,
& V_118 -> V_143 , & V_118 -> V_144 ) ;
return V_134 ;
}
if ( ! F_39 ( V_116 , V_116 -> V_4 ) )
return V_134 ;
F_40 ( & V_145 ) ;
V_109 = F_32 ( V_112 , V_114 , V_116 ) ;
F_41 ( & V_145 ) ;
return V_109 ;
}
static int T_6 F_42 ( void )
{
F_43 ( V_146 != NULL ) ;
F_44 ( V_146 , F_37 ) ;
return F_45 ( & V_147 ) ;
}
static void T_7 F_46 ( void )
{
F_44 ( V_146 , NULL ) ;
F_47 () ;
F_48 ( & V_147 ) ;
}
