int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
if ( V_6 != V_7 )
return - V_8 ;
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_9 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_11 , V_12 , ( unsigned long ) V_2 ) ;
V_2 -> V_13 = 0 ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( ! F_8 ( V_2 -> V_9 ) ) ;
F_9 ( & V_2 -> V_10 ) ;
F_10 ( V_2 -> V_4 ) ;
}
void F_11 ( struct V_1 * V_2 , unsigned int V_14 )
{
static const struct {
unsigned int V_14 ;
unsigned int V_15 ;
} V_16 [] = {
[ V_17 ] = { 32000 , 8 , } ,
[ V_18 ] = { 44100 , 8 , } ,
[ V_19 ] = { 48000 , 8 , } ,
[ V_20 ] = { 88200 , 16 , } ,
[ V_21 ] = { 96000 , 16 , } ,
[ V_22 ] = { 176400 , 32 , } ,
[ V_23 ] = { 192000 , 32 , } ,
} ;
unsigned int V_24 ;
if ( F_7 ( ! F_8 ( V_2 -> V_9 ) ) )
return;
for ( V_24 = 0 ; V_24 < F_12 ( V_16 ) ; ++ V_24 )
if ( V_16 [ V_24 ] . V_14 == V_14 ) {
V_2 -> V_24 = V_24 ;
V_2 -> V_15 = V_16 [ V_24 ] . V_15 ;
return;
}
F_7 ( 1 ) ;
}
unsigned int F_13 ( struct V_1 * V_2 )
{
static const unsigned int V_25 [] = {
[ V_17 ] = 4 ,
[ V_18 ] = 6 ,
[ V_19 ] = 6 ,
[ V_20 ] = 12 ,
[ V_21 ] = 12 ,
[ V_22 ] = 23 ,
[ V_23 ] = 24 ,
} ;
V_2 -> V_26 = V_2 -> V_27 ;
V_2 -> V_26 += F_14 ( V_2 -> V_28 , 8 ) ;
return 8 + V_25 [ V_2 -> V_24 ] * 4 * V_2 -> V_26 ;
}
void F_15 ( struct V_1 * V_2 ,
T_1 V_29 )
{
if ( F_7 ( ! F_8 ( V_2 -> V_9 ) ) )
return;
switch ( V_29 ) {
default:
F_7 ( 1 ) ;
case V_30 :
V_2 -> V_31 = V_32 ;
break;
case V_33 :
V_2 -> V_31 = V_34 ;
break;
}
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_11 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_37 = true ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
unsigned int V_38 , V_39 ;
if ( ! F_19 ( V_2 -> V_24 ) ) {
V_39 = V_2 -> V_40 ;
} else {
V_38 = V_2 -> V_40 ;
if ( V_2 -> V_24 == V_18 )
V_39 = 5 + ( ( V_38 & 1 ) ^
( V_38 == 0 || V_38 >= 40 ) ) ;
else
V_39 = 11 * ( V_2 -> V_24 >> 1 ) + ( V_38 == 0 ) ;
if ( ++ V_38 >= ( 80 >> ( V_2 -> V_24 >> 1 ) ) )
V_38 = 0 ;
V_2 -> V_40 = V_38 ;
}
return V_39 ;
}
static unsigned int F_20 ( struct V_1 * V_2 ,
unsigned int V_41 )
{
unsigned int V_42 , V_38 , V_43 , V_44 ;
if ( V_2 -> V_45 < V_46 ) {
if ( ! F_19 ( V_2 -> V_24 ) )
V_42 = V_2 -> V_45 + V_2 -> V_47 ;
else {
V_38 = V_2 -> V_47 ;
V_43 = V_38 % 13 ;
V_42 = V_2 -> V_45 ;
V_42 += 1386 + ( ( V_43 && ! ( V_43 & 3 ) ) ||
V_38 == 146 ) ;
if ( ++ V_38 >= 147 )
V_38 = 0 ;
V_2 -> V_47 = V_38 ;
}
} else
V_42 = V_2 -> V_45 - V_46 ;
V_2 -> V_45 = V_42 ;
if ( V_42 < V_46 ) {
V_42 += V_48 - V_46 ;
V_44 = ( V_41 + V_42 / V_46 ) << 12 ;
V_44 += V_42 % V_46 ;
return V_44 & 0xffff ;
} else {
return 0xffff ;
}
}
static void V_34 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_2 * V_51 , unsigned int V_52 )
{
struct V_53 * V_54 = V_50 -> V_54 ;
unsigned int V_55 , V_56 , V_57 , V_58 , V_59 ;
const T_3 * V_60 ;
V_55 = V_2 -> V_27 ;
V_60 = ( void * ) V_54 -> V_61 +
V_2 -> V_35 * ( V_54 -> V_62 / 8 ) ;
V_56 = V_54 -> V_63 - V_2 -> V_35 ;
V_57 = V_2 -> V_26 - V_55 ;
for ( V_58 = 0 ; V_58 < V_52 ; ++ V_58 ) {
for ( V_59 = 0 ; V_59 < V_55 ; ++ V_59 ) {
* V_51 = F_21 ( ( * V_60 >> 8 ) | 0x40000000 ) ;
V_60 ++ ;
V_51 ++ ;
}
V_51 += V_57 ;
if ( -- V_56 == 0 )
V_60 = ( void * ) V_54 -> V_61 ;
}
}
static void V_32 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_2 * V_51 , unsigned int V_52 )
{
struct V_53 * V_54 = V_50 -> V_54 ;
unsigned int V_55 , V_56 , V_57 , V_58 , V_59 ;
const T_4 * V_60 ;
V_55 = V_2 -> V_27 ;
V_60 = ( void * ) V_54 -> V_61 +
V_2 -> V_35 * ( V_54 -> V_62 / 8 ) ;
V_56 = V_54 -> V_63 - V_2 -> V_35 ;
V_57 = V_2 -> V_26 - V_55 ;
for ( V_58 = 0 ; V_58 < V_52 ; ++ V_58 ) {
for ( V_59 = 0 ; V_59 < V_55 ; ++ V_59 ) {
* V_51 = F_21 ( ( * V_60 << 8 ) | 0x40000000 ) ;
V_60 ++ ;
V_51 ++ ;
}
V_51 += V_57 ;
if ( -- V_56 == 0 )
V_60 = ( void * ) V_54 -> V_61 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
T_2 * V_51 , unsigned int V_52 )
{
unsigned int V_58 , V_59 ;
for ( V_58 = 0 ; V_58 < V_52 ; ++ V_58 ) {
for ( V_59 = 0 ; V_59 < V_2 -> V_27 ; ++ V_59 )
V_51 [ V_59 ] = F_21 ( 0x40000000 ) ;
V_51 += V_2 -> V_26 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
T_2 * V_51 , unsigned int V_52 )
{
unsigned int V_58 ;
for ( V_58 = 0 ; V_58 < V_52 ; ++ V_58 )
V_51 [ V_2 -> V_27 + V_58 * V_2 -> V_26 ] =
F_21 ( 0x80000000 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_41 )
{
T_2 * V_51 ;
unsigned int V_43 , V_39 , V_44 , V_64 ;
struct V_49 * V_50 ;
struct V_65 V_66 ;
int V_67 ;
if ( V_2 -> V_13 < 0 )
return;
V_43 = V_2 -> V_13 ;
V_39 = F_18 ( V_2 ) ;
V_44 = F_20 ( V_2 , V_41 ) ;
V_51 = V_2 -> V_51 . V_68 [ V_43 ] . V_51 ;
V_51 [ 0 ] = F_21 ( F_25 ( V_2 -> V_69 ) |
( V_2 -> V_26 << 16 ) |
V_2 -> V_70 ) ;
V_51 [ 1 ] = F_21 ( V_71 | V_72 | V_73 |
( V_2 -> V_24 << V_74 ) | V_44 ) ;
V_51 += 2 ;
V_50 = F_25 ( V_2 -> V_50 ) ;
if ( V_50 )
V_2 -> V_31 ( V_2 , V_50 , V_51 , V_39 ) ;
else
F_22 ( V_2 , V_51 , V_39 ) ;
if ( V_2 -> V_28 )
F_23 ( V_2 , V_51 , V_39 ) ;
V_2 -> V_70 = ( V_2 -> V_70 + V_39 ) & 0xff ;
V_66 . V_75 = 8 + V_39 * 4 * V_2 -> V_26 ;
V_66 . V_76 = F_26 ( V_43 + 1 , V_77 ) ;
V_66 . V_78 = 0 ;
V_66 . V_79 = V_80 ;
V_66 . V_81 = 0 ;
V_66 . V_82 = 0 ;
V_67 = F_27 ( V_2 -> V_9 , & V_66 , & V_2 -> V_51 . V_83 ,
V_2 -> V_51 . V_68 [ V_43 ] . V_84 ) ;
if ( V_67 < 0 ) {
F_28 ( & V_2 -> V_4 -> V_85 , L_1 , V_67 ) ;
V_2 -> V_13 = - 1 ;
F_29 ( V_2 ) ;
return;
}
if ( ++ V_43 >= V_86 )
V_43 = 0 ;
V_2 -> V_13 = V_43 ;
if ( V_50 ) {
V_64 = V_2 -> V_35 + V_39 ;
if ( V_64 >= V_50 -> V_54 -> V_63 )
V_64 -= V_50 -> V_54 -> V_63 ;
F_25 ( V_2 -> V_35 ) = V_64 ;
V_2 -> V_36 += V_39 ;
if ( V_2 -> V_36 >= V_50 -> V_54 -> V_87 ) {
V_2 -> V_36 -= V_50 -> V_54 -> V_87 ;
V_2 -> V_37 = false ;
F_30 ( & V_2 -> V_11 ) ;
}
}
}
static void V_12 ( unsigned long V_88 )
{
struct V_1 * V_2 = ( void * ) V_88 ;
struct V_49 * V_50 = F_25 ( V_2 -> V_50 ) ;
if ( V_50 )
F_31 ( V_50 ) ;
}
static void F_32 ( struct V_89 * V_9 , T_3 V_41 ,
T_5 V_82 , void * V_90 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
unsigned int V_58 , V_68 = V_82 / 4 ;
V_41 += V_86 - V_68 ;
for ( V_58 = 0 ; V_58 < V_68 ; ++ V_58 )
F_24 ( V_2 , ++ V_41 ) ;
F_33 ( V_2 -> V_9 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_65 V_91 = {
. V_78 = 1 ,
} ;
unsigned int V_58 ;
int V_67 ;
for ( V_58 = 0 ; V_58 < V_86 ; ++ V_58 ) {
V_91 . V_76 = F_26 ( V_2 -> V_13 + 1 ,
V_77 ) ;
V_67 = F_27 ( V_2 -> V_9 , & V_91 , NULL , 0 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ++ V_2 -> V_13 >= V_86 )
V_2 -> V_13 = 0 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_2 , int V_92 , int V_93 )
{
static const struct {
unsigned int V_94 ;
unsigned int V_42 ;
} V_95 [] = {
[ V_17 ] = { 4 , 3072 } ,
[ V_19 ] = { 6 , 1024 } ,
[ V_21 ] = { 12 , 1024 } ,
[ V_23 ] = { 24 , 1024 } ,
[ V_18 ] = { 0 , 67 } ,
[ V_20 ] = { 0 , 67 } ,
[ V_22 ] = { 0 , 67 } ,
} ;
int V_67 ;
F_36 ( & V_2 -> V_10 ) ;
if ( F_7 ( ! F_8 ( V_2 -> V_9 ) ||
( ! V_2 -> V_27 && ! V_2 -> V_28 ) ) ) {
V_67 = - V_96 ;
goto V_97;
}
V_2 -> V_40 = V_95 [ V_2 -> V_24 ] . V_94 ;
V_2 -> V_47 = V_95 [ V_2 -> V_24 ] . V_42 ;
V_2 -> V_45 = V_46 ;
V_67 = F_37 ( & V_2 -> V_51 , V_2 -> V_4 , V_86 ,
F_13 ( V_2 ) ,
V_98 ) ;
if ( V_67 < 0 )
goto V_97;
V_2 -> V_9 = F_38 ( F_39 ( V_2 -> V_4 ) -> V_99 ,
V_100 ,
V_92 , V_93 , 0 ,
F_32 , V_2 ) ;
if ( F_8 ( V_2 -> V_9 ) ) {
V_67 = F_40 ( V_2 -> V_9 ) ;
if ( V_67 == - V_101 )
F_28 ( & V_2 -> V_4 -> V_85 ,
L_2 ) ;
goto V_102;
}
F_41 ( V_2 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_70 = 0 ;
V_67 = F_34 ( V_2 ) ;
if ( V_67 < 0 )
goto V_103;
V_67 = F_42 ( V_2 -> V_9 , - 1 , 0 , 0 ) ;
if ( V_67 < 0 )
goto V_103;
F_43 ( & V_2 -> V_10 ) ;
return 0 ;
V_103:
F_44 ( V_2 -> V_9 ) ;
V_2 -> V_9 = F_3 ( - 1 ) ;
V_102:
F_45 ( & V_2 -> V_51 , V_2 -> V_4 ) ;
V_97:
F_43 ( & V_2 -> V_10 ) ;
return V_67 ;
}
unsigned long F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 )
F_47 ( V_2 -> V_9 ) ;
else
V_2 -> V_37 = true ;
return F_25 ( V_2 -> V_35 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_69 ) =
( F_39 ( V_2 -> V_4 ) -> V_99 -> V_104 & 0x3f ) << 24 ;
}
void F_48 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_10 ) ;
if ( F_8 ( V_2 -> V_9 ) ) {
F_43 ( & V_2 -> V_10 ) ;
return;
}
F_17 ( & V_2 -> V_11 ) ;
F_49 ( V_2 -> V_9 ) ;
F_44 ( V_2 -> V_9 ) ;
V_2 -> V_9 = F_3 ( - 1 ) ;
F_45 ( & V_2 -> V_51 , V_2 -> V_4 ) ;
F_43 ( & V_2 -> V_10 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
V_50 = F_25 ( V_2 -> V_50 ) ;
if ( V_50 ) {
F_50 ( V_50 ) ;
if ( F_51 ( V_50 ) )
F_52 ( V_50 , V_105 ) ;
F_53 ( V_50 ) ;
}
}
