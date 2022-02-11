static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
enum V_5 V_6 )
{
int V_7 = 0 , V_8 = 0 , V_9 = 0 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_11 -> V_12 -> V_13 ; V_9 ++ ) {
if ( V_11 -> V_14 [ V_9 ] . type == V_15 &&
V_11 -> V_14 [ V_9 ] . V_16 == V_17 + V_3 ) {
V_7 ++ ;
V_8 += V_11 -> V_14 [ V_9 ] . V_18 . V_19 ;
}
}
if ( V_7 == 0 ) {
F_3 ( & V_2 -> V_20 ,
L_1 ,
V_8 , V_7 , V_6 ) ;
return - V_21 ;
}
V_8 = V_8 / V_7 ;
if ( V_8 > 0xFF )
return - V_21 ;
V_11 -> V_3 [ V_3 ] = V_8 ;
V_11 -> V_22 [ V_3 ] = V_4 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
F_5 ( & V_11 -> V_24 ) ;
F_6 ( V_2 , F_7 ( V_23 , V_3 ) ,
V_11 -> V_3 [ V_3 ] ) ;
F_6 ( V_2 , F_8 ( V_23 , V_3 ) ,
V_11 -> V_22 [ V_3 ] ) ;
F_9 ( & V_11 -> V_24 ) ;
return 0 ;
}
static void F_10 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
char V_27 ;
F_5 ( & V_11 -> V_24 ) ;
V_27 = F_11 ( V_2 , F_12 ( V_23 , V_26 -> V_28 ) ) ;
V_27 = V_27 & ~ ( 0x3 << F_13 ( V_26 -> V_28 ) * 2 ) ;
V_27 = V_27 | ( V_26 -> V_16 << F_13 ( V_26 -> V_28 ) * 2 ) ;
F_6 ( V_2 , F_12 ( V_23 , V_26 -> V_28 ) , V_27 ) ;
F_9 ( & V_11 -> V_24 ) ;
}
static int F_14 ( struct V_29 * V_30 ,
enum V_5 V_6 )
{
int V_31 = 0 ;
struct V_25 * V_26 = F_15 ( V_30 ) ;
if ( V_6 == V_32 )
V_26 -> V_16 = V_33 ;
else if ( V_6 == V_34 )
V_26 -> V_16 = V_35 ;
else {
V_26 -> V_16 = V_17 ;
V_31 = F_1 ( V_26 -> V_2 , 0 , 0 , V_6 ) ;
if ( V_31 )
return V_31 ;
}
if ( V_26 -> V_16 == V_17 )
F_4 ( V_26 -> V_2 , 0 ) ;
F_10 ( V_26 ) ;
return V_31 ;
}
static int F_16 ( struct V_29 * V_30 ,
unsigned long * V_36 , unsigned long * V_37 )
{
struct V_25 * V_26 = F_15 ( V_30 ) ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_22 ;
int V_31 = 0 ;
if ( * V_36 == 0 && * V_37 == 0 ) {
* V_36 = 1000 ;
* V_37 = 1000 ;
}
if ( * V_36 != * V_37 || * V_36 > 1690 || * V_36 < 6 )
return - V_21 ;
V_22 = ( * V_36 * 152 - 1 ) / 1000 ;
V_31 = F_1 ( V_2 , 0 , V_22 , V_30 -> V_19 ) ;
if ( V_31 )
return V_31 ;
if ( V_26 -> V_16 == V_17 )
F_4 ( V_26 -> V_2 , 0 ) ;
F_10 ( V_26 ) ;
return 0 ;
}
static int F_17 ( struct V_38 * V_20 , unsigned int type ,
unsigned int V_39 , int V_6 )
{
struct V_10 * V_11 = F_18 ( V_20 ) ;
if ( ! ( type == V_40 && ( V_39 == V_41 || V_39 == V_42 ) ) )
return - 1 ;
if ( V_6 > 1 && V_6 < 32767 )
V_11 -> V_3 [ 1 ] = 127 ;
else
V_11 -> V_3 [ 1 ] = 0 ;
F_19 ( & V_11 -> V_43 ) ;
return 0 ;
}
static void F_20 ( struct V_44 * V_43 )
{
struct V_10 * V_11 =
F_21 ( V_43 , struct V_10 , V_43 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
F_5 ( & V_11 -> V_24 ) ;
F_6 ( V_11 -> V_2 , F_7 ( V_23 , 1 ) ,
V_11 -> V_3 [ 1 ] ) ;
F_9 ( & V_11 -> V_24 ) ;
}
static enum V_45 F_22 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
char V_27 ;
enum V_45 V_46 ;
F_5 ( & V_11 -> V_24 ) ;
V_27 = F_11 ( V_2 , F_12 ( V_23 , V_26 -> V_28 ) ) ;
V_46 = V_27 >> F_13 ( V_26 -> V_28 ) / 2 ;
F_9 ( & V_11 -> V_24 ) ;
return V_46 ;
}
static int F_23 ( struct V_47 * V_48 , unsigned V_49 )
{
struct V_10 * V_11 = F_24 ( V_48 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_49 ] ;
if ( V_26 -> type == V_50 )
return 0 ;
return - V_51 ;
}
static void F_25 ( struct V_47 * V_48 , unsigned V_49 , int V_52 )
{
struct V_10 * V_11 = F_24 ( V_48 ) ;
struct V_25 * V_26 = & V_11 -> V_14 [ V_49 ] ;
if ( V_52 )
V_26 -> V_16 = V_35 ;
else
V_26 -> V_16 = V_33 ;
F_10 ( V_26 ) ;
}
static int F_26 ( struct V_47 * V_48 , unsigned V_49 )
{
struct V_10 * V_11 = F_24 ( V_48 ) ;
unsigned char V_27 ;
V_27 = F_11 ( V_11 -> V_2 , F_27 ( V_49 ) ) ;
return ! ! ( V_27 & ( 1 << ( V_49 % 8 ) ) ) ;
}
static int F_28 ( struct V_47 * V_48 , unsigned V_49 )
{
F_25 ( V_48 , V_49 , 0 ) ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 , unsigned V_49 , int V_52 )
{
F_25 ( V_48 , V_49 , V_52 ) ;
return 0 ;
}
static int F_30 ( struct V_10 * V_11 , int V_53 )
{
int V_9 = V_53 ;
if ( ! V_11 )
return - V_21 ;
while ( -- V_9 >= 0 ) {
switch ( V_11 -> V_14 [ V_9 ] . type ) {
case V_54 :
case V_50 :
break;
case V_15 :
F_31 ( & V_11 -> V_14 [ V_9 ] . V_18 ) ;
break;
case V_55 :
if ( V_11 -> V_56 != NULL ) {
F_32 ( & V_11 -> V_43 ) ;
V_11 -> V_56 = NULL ;
}
break;
}
}
#ifdef F_33
if ( V_11 -> V_57 . V_58 )
F_34 ( & V_11 -> V_57 ) ;
#endif
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_10 * V_11 , struct V_59 * V_60 )
{
int V_9 , V_31 = 0 ;
int V_61 = 0 ;
T_1 V_23 = V_11 -> V_12 -> V_13 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
V_11 -> V_3 [ V_9 ] = V_60 -> V_3 [ V_9 ] ;
V_11 -> V_22 [ V_9 ] = V_60 -> V_22 [ V_9 ] ;
F_6 ( V_2 , F_7 ( V_23 , V_9 ) ,
V_11 -> V_3 [ V_9 ] ) ;
F_6 ( V_2 , F_8 ( V_23 , V_9 ) ,
V_11 -> V_22 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_11 -> V_12 -> V_13 ; V_9 ++ ) {
struct V_25 * V_26 = & V_11 -> V_14 [ V_9 ] ;
struct V_25 * V_62 = & V_60 -> V_14 [ V_9 ] ;
V_26 -> V_2 = V_2 ;
V_26 -> V_28 = V_9 ;
V_26 -> type = V_62 -> type ;
switch ( V_26 -> type ) {
case V_54 :
break;
case V_50 :
V_61 ++ ;
break;
case V_15 :
if ( V_62 -> V_16 == V_63 )
V_26 -> V_16 = F_22 ( V_26 ) ;
else
V_26 -> V_16 = V_62 -> V_16 ;
V_26 -> V_64 = V_62 -> V_64 ;
V_26 -> V_18 . V_64 = V_26 -> V_64 ;
V_26 -> V_18 . V_65 = V_62 -> V_65 ;
V_26 -> V_18 . V_19 = V_32 ;
V_26 -> V_18 . V_66 =
F_14 ;
V_26 -> V_18 . V_67 = F_16 ;
V_31 = F_36 ( & V_2 -> V_20 , & V_26 -> V_18 ) ;
if ( V_31 < 0 ) {
F_3 ( & V_2 -> V_20 ,
L_2 ,
V_26 -> V_64 ) ;
goto exit;
}
F_10 ( V_26 ) ;
break;
case V_55 :
F_37 ( V_11 -> V_56 ) ;
V_26 -> V_16 = V_68 ;
F_10 ( V_26 ) ;
V_11 -> V_56 = F_38 ( & V_2 -> V_20 ) ;
if ( V_11 -> V_56 == NULL ) {
V_31 = - V_69 ;
goto exit;
}
V_11 -> V_56 -> V_64 = V_62 -> V_64 ;
V_11 -> V_56 -> V_70 = L_3 ;
V_11 -> V_56 -> V_28 . V_71 = V_72 ;
V_11 -> V_56 -> V_28 . V_73 = 0x001f ;
V_11 -> V_56 -> V_28 . V_74 = 0x0001 ;
V_11 -> V_56 -> V_28 . V_75 = 0x0100 ;
V_11 -> V_56 -> V_76 [ 0 ] = F_39 ( V_40 ) ;
V_11 -> V_56 -> V_77 [ 0 ] = F_39 ( V_41 ) |
F_39 ( V_42 ) ;
V_11 -> V_56 -> V_78 = F_17 ;
F_40 ( V_11 -> V_56 , V_11 ) ;
F_41 ( & V_11 -> V_43 , F_20 ) ;
V_31 = F_42 ( V_11 -> V_56 ) ;
if ( V_31 ) {
F_32 ( & V_11 -> V_43 ) ;
V_11 -> V_56 = NULL ;
goto exit;
}
break;
}
}
#ifdef F_33
if ( V_61 ) {
V_11 -> V_57 . V_79 = L_4 ;
V_11 -> V_57 . V_80 = F_28 ;
V_11 -> V_57 . V_81 = F_29 ;
V_11 -> V_57 . V_82 = F_25 ;
V_11 -> V_57 . V_83 = F_26 ;
V_11 -> V_57 . V_84 = F_23 ;
V_11 -> V_57 . V_85 = 1 ;
V_11 -> V_57 . V_86 = V_60 -> V_87 ;
V_11 -> V_57 . V_88 = V_11 -> V_12 -> V_13 ;
V_11 -> V_57 . V_58 = & V_2 -> V_20 ;
V_11 -> V_57 . V_89 = V_90 ;
V_31 = F_43 ( & V_11 -> V_57 , V_11 ) ;
if ( V_31 ) {
V_11 -> V_57 . V_58 = NULL ;
F_44 ( & V_2 -> V_20 , L_5 ) ;
} else {
F_45 ( & V_2 -> V_20 , L_6 ,
V_11 -> V_57 . V_86 , V_11 -> V_57 . V_86 +
V_11 -> V_57 . V_88 - 1 ) ;
}
}
#endif
return 0 ;
exit:
F_30 ( V_11 , V_9 ) ;
return V_31 ;
}
static struct V_59 *
F_46 ( struct V_91 * V_20 , struct V_92 * V_93 )
{
struct V_59 * V_60 ;
struct V_92 * V_94 ;
const struct V_95 * V_96 ;
int V_97 , V_23 ;
int V_9 = 0 ;
const char * V_16 ;
V_96 = F_47 ( V_98 , V_20 ) ;
if ( ! V_96 )
return F_48 ( - V_99 ) ;
V_97 = ( int ) ( V_100 ) V_96 -> V_11 ;
V_23 = V_101 [ V_97 ] . V_13 ;
V_60 = F_49 ( V_20 , sizeof( * V_60 ) , V_102 ) ;
if ( ! V_60 )
return F_48 ( - V_69 ) ;
F_50 (np, child) {
if ( F_51 ( V_94 , L_7 ,
& V_60 -> V_14 [ V_9 ] . V_64 ) )
V_60 -> V_14 [ V_9 ] . V_64 = V_94 -> V_64 ;
F_52 ( V_94 , L_8 , & V_60 -> V_14 [ V_9 ] . type ) ;
F_51 ( V_94 , L_9 ,
& V_60 -> V_14 [ V_9 ] . V_65 ) ;
if ( ! F_51 ( V_94 , L_10 , & V_16 ) ) {
if ( ! strcmp ( V_16 , L_11 ) )
V_60 -> V_14 [ V_9 ] . V_16 = V_35 ;
else if ( ! strcmp ( V_16 , L_12 ) )
V_60 -> V_14 [ V_9 ] . V_16 = V_63 ;
}
if ( ++ V_9 >= V_23 ) {
F_53 ( V_94 ) ;
break;
}
}
return V_60 ;
}
static int F_54 ( struct V_1 * V_2 ,
const struct V_103 * V_28 )
{
int V_97 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_59 * V_104 =
F_55 ( & V_2 -> V_20 ) ;
struct V_92 * V_93 = V_2 -> V_20 . V_105 ;
if ( ! V_104 ) {
if ( V_93 ) {
V_104 =
F_46 ( & V_2 -> V_20 , V_93 ) ;
if ( F_56 ( V_104 ) )
return F_57 ( V_104 ) ;
} else {
F_3 ( & V_2 -> V_20 , L_13 ) ;
return - V_21 ;
}
V_97 = ( int ) ( V_100 ) F_47 (
V_98 , & V_2 -> V_20 ) -> V_11 ;
} else {
V_97 = V_28 -> V_106 ;
}
if ( ! F_58 ( V_2 -> V_107 ,
V_108 ) )
return - V_109 ;
V_11 = F_49 ( & V_2 -> V_20 , sizeof( * V_11 ) , V_102 ) ;
if ( ! V_11 )
return - V_69 ;
V_11 -> V_12 = & V_101 [ V_97 ] ;
F_45 ( & V_2 -> V_20 , L_14 ) ;
F_59 ( V_2 , V_11 ) ;
V_11 -> V_2 = V_2 ;
F_60 ( & V_11 -> V_24 ) ;
return F_35 ( V_2 , V_11 , V_104 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_31 ;
V_31 = F_30 ( V_11 , V_11 -> V_12 -> V_13 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
