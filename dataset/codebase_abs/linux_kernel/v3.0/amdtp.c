int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 V_6 )
{
if ( V_6 != V_7 )
return - V_8 ;
V_2 -> V_4 = F_2 ( V_4 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_9 = F_3 ( - 1 ) ;
F_4 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = 0 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_7 ( V_2 -> V_9 ) ) ;
F_8 ( & V_2 -> V_10 ) ;
F_9 ( V_2 -> V_4 ) ;
}
void F_10 ( struct V_1 * V_2 , unsigned int V_12 )
{
static const struct {
unsigned int V_12 ;
unsigned int V_13 ;
} V_14 [] = {
[ V_15 ] = { 32000 , 8 , } ,
[ V_16 ] = { 44100 , 8 , } ,
[ V_17 ] = { 48000 , 8 , } ,
[ V_18 ] = { 88200 , 16 , } ,
[ V_19 ] = { 96000 , 16 , } ,
[ V_20 ] = { 176400 , 32 , } ,
[ V_21 ] = { 192000 , 32 , } ,
} ;
unsigned int V_22 ;
if ( F_6 ( ! F_7 ( V_2 -> V_9 ) ) )
return;
for ( V_22 = 0 ; V_22 < F_11 ( V_14 ) ; ++ V_22 )
if ( V_14 [ V_22 ] . V_12 == V_12 ) {
V_2 -> V_22 = V_22 ;
V_2 -> V_13 = V_14 [ V_22 ] . V_13 ;
return;
}
F_6 ( 1 ) ;
}
unsigned int F_12 ( struct V_1 * V_2 )
{
static const unsigned int V_23 [] = {
[ V_15 ] = 4 ,
[ V_16 ] = 6 ,
[ V_17 ] = 6 ,
[ V_18 ] = 12 ,
[ V_19 ] = 12 ,
[ V_20 ] = 23 ,
[ V_21 ] = 24 ,
} ;
V_2 -> V_24 = V_2 -> V_25 ;
V_2 -> V_24 += F_13 ( V_2 -> V_26 , 8 ) ;
return 8 + V_23 [ V_2 -> V_22 ] * 4 * V_2 -> V_24 ;
}
void F_14 ( struct V_1 * V_2 ,
T_1 V_27 )
{
if ( F_6 ( ! F_7 ( V_2 -> V_9 ) ) )
return;
switch ( V_27 ) {
default:
F_6 ( 1 ) ;
case V_28 :
V_2 -> V_29 = V_30 ;
break;
case V_31 :
V_2 -> V_29 = V_32 ;
break;
}
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
unsigned int V_33 , V_34 ;
if ( ! F_16 ( V_2 -> V_22 ) ) {
V_34 = V_2 -> V_35 ;
} else {
V_33 = V_2 -> V_35 ;
if ( V_2 -> V_22 == V_16 )
V_34 = 5 + ( ( V_33 & 1 ) ^
( V_33 == 0 || V_33 >= 40 ) ) ;
else
V_34 = 11 * ( V_2 -> V_22 >> 1 ) + ( V_33 == 0 ) ;
if ( ++ V_33 >= ( 80 >> ( V_2 -> V_22 >> 1 ) ) )
V_33 = 0 ;
V_2 -> V_35 = V_33 ;
}
return V_34 ;
}
static unsigned int F_17 ( struct V_1 * V_2 ,
unsigned int V_36 )
{
unsigned int V_37 , V_33 , V_38 , V_39 ;
if ( V_2 -> V_40 < V_41 ) {
if ( ! F_16 ( V_2 -> V_22 ) )
V_37 = V_2 -> V_40 + V_2 -> V_42 ;
else {
V_33 = V_2 -> V_42 ;
V_38 = V_33 % 13 ;
V_37 = V_2 -> V_40 ;
V_37 += 1386 + ( ( V_38 && ! ( V_38 & 3 ) ) ||
V_33 == 146 ) ;
if ( ++ V_33 >= 147 )
V_33 = 0 ;
V_2 -> V_42 = V_33 ;
}
} else
V_37 = V_2 -> V_40 - V_41 ;
V_2 -> V_40 = V_37 ;
if ( V_37 < V_41 ) {
V_37 += V_43 - V_41 ;
V_39 = ( V_36 + V_37 / V_41 ) << 12 ;
V_39 += V_37 % V_41 ;
return V_39 & 0xffff ;
} else {
return 0xffff ;
}
}
static void V_32 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_2 * V_46 , unsigned int V_47 )
{
struct V_48 * V_49 = V_45 -> V_49 ;
unsigned int V_50 , V_51 , V_52 , V_53 , V_54 ;
const T_3 * V_55 ;
V_50 = V_2 -> V_25 ;
V_55 = ( void * ) V_49 -> V_56 +
V_2 -> V_57 * ( V_49 -> V_58 / 8 ) ;
V_51 = V_49 -> V_59 - V_2 -> V_57 ;
V_52 = V_2 -> V_24 - V_50 ;
for ( V_53 = 0 ; V_53 < V_47 ; ++ V_53 ) {
for ( V_54 = 0 ; V_54 < V_50 ; ++ V_54 ) {
* V_46 = F_18 ( ( * V_55 >> 8 ) | 0x40000000 ) ;
V_55 ++ ;
V_46 ++ ;
}
V_46 += V_52 ;
if ( -- V_51 == 0 )
V_55 = ( void * ) V_49 -> V_56 ;
}
}
static void V_30 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
T_2 * V_46 , unsigned int V_47 )
{
struct V_48 * V_49 = V_45 -> V_49 ;
unsigned int V_50 , V_51 , V_52 , V_53 , V_54 ;
const T_4 * V_55 ;
V_50 = V_2 -> V_25 ;
V_55 = ( void * ) V_49 -> V_56 +
V_2 -> V_57 * ( V_49 -> V_58 / 8 ) ;
V_51 = V_49 -> V_59 - V_2 -> V_57 ;
V_52 = V_2 -> V_24 - V_50 ;
for ( V_53 = 0 ; V_53 < V_47 ; ++ V_53 ) {
for ( V_54 = 0 ; V_54 < V_50 ; ++ V_54 ) {
* V_46 = F_18 ( ( * V_55 << 8 ) | 0x40000000 ) ;
V_55 ++ ;
V_46 ++ ;
}
V_46 += V_52 ;
if ( -- V_51 == 0 )
V_55 = ( void * ) V_49 -> V_56 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
T_2 * V_46 , unsigned int V_47 )
{
unsigned int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < V_47 ; ++ V_53 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_25 ; ++ V_54 )
V_46 [ V_54 ] = F_18 ( 0x40000000 ) ;
V_46 += V_2 -> V_24 ;
}
}
static void F_20 ( struct V_1 * V_2 ,
T_2 * V_46 , unsigned int V_47 )
{
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_47 ; ++ V_53 )
V_46 [ V_2 -> V_25 + V_53 * V_2 -> V_24 ] =
F_18 ( 0x80000000 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_36 )
{
T_2 * V_46 ;
unsigned int V_38 , V_34 , V_39 , V_60 ;
struct V_44 * V_45 ;
struct V_61 V_62 ;
int V_63 ;
if ( V_2 -> V_11 < 0 )
return;
V_38 = V_2 -> V_11 ;
V_34 = F_15 ( V_2 ) ;
V_39 = F_17 ( V_2 , V_36 ) ;
V_46 = V_2 -> V_46 . V_64 [ V_38 ] . V_46 ;
V_46 [ 0 ] = F_18 ( F_22 ( V_2 -> V_65 ) |
( V_2 -> V_24 << 16 ) |
V_2 -> V_66 ) ;
V_46 [ 1 ] = F_18 ( V_67 | V_68 | V_69 |
( V_2 -> V_22 << V_70 ) | V_39 ) ;
V_46 += 2 ;
V_45 = F_22 ( V_2 -> V_45 ) ;
if ( V_45 )
V_2 -> V_29 ( V_2 , V_45 , V_46 , V_34 ) ;
else
F_19 ( V_2 , V_46 , V_34 ) ;
if ( V_2 -> V_26 )
F_20 ( V_2 , V_46 , V_34 ) ;
V_2 -> V_66 = ( V_2 -> V_66 + V_34 ) & 0xff ;
V_62 . V_71 = 8 + V_34 * 4 * V_2 -> V_24 ;
V_62 . V_72 = F_23 ( V_38 + 1 , V_73 ) ;
V_62 . V_74 = 0 ;
V_62 . V_75 = V_76 ;
V_62 . V_77 = 0 ;
V_62 . V_78 = 0 ;
V_63 = F_24 ( V_2 -> V_9 , & V_62 , & V_2 -> V_46 . V_79 ,
V_2 -> V_46 . V_64 [ V_38 ] . V_80 ) ;
if ( V_63 < 0 ) {
F_25 ( & V_2 -> V_4 -> V_81 , L_1 , V_63 ) ;
V_2 -> V_11 = - 1 ;
F_26 ( V_2 ) ;
return;
}
if ( ++ V_38 >= V_82 )
V_38 = 0 ;
V_2 -> V_11 = V_38 ;
if ( V_45 ) {
V_60 = V_2 -> V_57 + V_34 ;
if ( V_60 >= V_45 -> V_49 -> V_59 )
V_60 -= V_45 -> V_49 -> V_59 ;
F_22 ( V_2 -> V_57 ) = V_60 ;
V_2 -> V_83 += V_34 ;
if ( V_2 -> V_83 >= V_45 -> V_49 -> V_84 ) {
V_2 -> V_83 -= V_45 -> V_49 -> V_84 ;
F_27 ( V_45 ) ;
}
}
}
static void F_28 ( struct V_85 * V_9 , T_3 V_36 ,
T_5 V_78 , void * V_86 , void * V_87 )
{
struct V_1 * V_2 = V_87 ;
unsigned int V_53 , V_64 = V_78 / 4 ;
V_36 += V_82 - V_64 ;
for ( V_53 = 0 ; V_53 < V_64 ; ++ V_53 )
F_21 ( V_2 , ++ V_36 ) ;
F_29 ( V_2 -> V_9 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_61 V_88 = {
. V_74 = 1 ,
} ;
unsigned int V_53 ;
int V_63 ;
for ( V_53 = 0 ; V_53 < V_82 ; ++ V_53 ) {
V_88 . V_72 = F_23 ( V_2 -> V_11 + 1 ,
V_73 ) ;
V_63 = F_24 ( V_2 -> V_9 , & V_88 , NULL , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( ++ V_2 -> V_11 >= V_82 )
V_2 -> V_11 = 0 ;
}
return 0 ;
}
int F_31 ( struct V_1 * V_2 , int V_89 , int V_90 )
{
static const struct {
unsigned int V_91 ;
unsigned int V_37 ;
} V_92 [] = {
[ V_15 ] = { 4 , 3072 } ,
[ V_17 ] = { 6 , 1024 } ,
[ V_19 ] = { 12 , 1024 } ,
[ V_21 ] = { 24 , 1024 } ,
[ V_16 ] = { 0 , 67 } ,
[ V_18 ] = { 0 , 67 } ,
[ V_20 ] = { 0 , 67 } ,
} ;
int V_63 ;
F_32 ( & V_2 -> V_10 ) ;
if ( F_6 ( ! F_7 ( V_2 -> V_9 ) ||
( ! V_2 -> V_25 && ! V_2 -> V_26 ) ) ) {
V_63 = - V_93 ;
goto V_94;
}
V_2 -> V_35 = V_92 [ V_2 -> V_22 ] . V_91 ;
V_2 -> V_42 = V_92 [ V_2 -> V_22 ] . V_37 ;
V_2 -> V_40 = V_41 ;
V_63 = F_33 ( & V_2 -> V_46 , V_2 -> V_4 , V_82 ,
F_12 ( V_2 ) ,
V_95 ) ;
if ( V_63 < 0 )
goto V_94;
V_2 -> V_9 = F_34 ( F_35 ( V_2 -> V_4 ) -> V_96 ,
V_97 ,
V_89 , V_90 , 0 ,
F_28 , V_2 ) ;
if ( F_7 ( V_2 -> V_9 ) ) {
V_63 = F_36 ( V_2 -> V_9 ) ;
if ( V_63 == - V_98 )
F_25 ( & V_2 -> V_4 -> V_81 ,
L_2 ) ;
goto V_99;
}
F_37 ( V_2 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_66 = 0 ;
V_63 = F_30 ( V_2 ) ;
if ( V_63 < 0 )
goto V_100;
V_63 = F_38 ( V_2 -> V_9 , - 1 , 0 , 0 ) ;
if ( V_63 < 0 )
goto V_100;
F_39 ( & V_2 -> V_10 ) ;
return 0 ;
V_100:
F_40 ( V_2 -> V_9 ) ;
V_2 -> V_9 = F_3 ( - 1 ) ;
V_99:
F_41 ( & V_2 -> V_46 , V_2 -> V_4 ) ;
V_94:
F_39 ( & V_2 -> V_10 ) ;
return V_63 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_65 ) =
( F_35 ( V_2 -> V_4 ) -> V_96 -> V_101 & 0x3f ) << 24 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_10 ) ;
if ( F_7 ( V_2 -> V_9 ) ) {
F_39 ( & V_2 -> V_10 ) ;
return;
}
F_43 ( V_2 -> V_9 ) ;
F_40 ( V_2 -> V_9 ) ;
V_2 -> V_9 = F_3 ( - 1 ) ;
F_41 ( & V_2 -> V_46 , V_2 -> V_4 ) ;
F_39 ( & V_2 -> V_10 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_44 * V_45 ;
V_45 = F_22 ( V_2 -> V_45 ) ;
if ( V_45 ) {
F_44 ( V_45 ) ;
if ( F_45 ( V_45 ) )
F_46 ( V_45 , V_102 ) ;
F_47 ( V_45 ) ;
}
}
