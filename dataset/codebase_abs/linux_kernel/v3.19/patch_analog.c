static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 ;
if ( ! V_4 -> V_7 )
return 0 ;
for ( V_6 = V_8 ; V_6 -> V_9 ; V_6 ++ ) {
int V_10 ;
struct V_11 * V_12 ;
V_12 = F_2 ( V_6 , V_2 ) ;
if ( ! V_12 )
return - V_13 ;
V_12 -> V_14 = V_4 -> V_7 ;
V_10 = F_3 ( V_2 , 0 , V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_15 ,
T_1 V_16 )
{
if ( F_5 ( V_2 , V_15 ) & V_17 )
F_6 ( V_2 , V_15 , 0 , V_18 ,
! V_2 -> V_19 ? 0x00 : 0x02 ) ;
if ( F_5 ( V_2 , V_16 ) & V_17 )
F_6 ( V_2 , V_16 , 0 , V_18 ,
! V_2 -> V_19 ? 0x00 : 0x02 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_20 ) {
case 0x11d41882 :
case 0x11d4882a :
case 0x11d41884 :
case 0x11d41984 :
case 0x11d41883 :
case 0x11d4184a :
case 0x11d4194a :
case 0x11d4194b :
case 0x11d41988 :
case 0x11d4198b :
case 0x11d4989a :
case 0x11d4989b :
F_4 ( V_2 , 0x12 , 0x11 ) ;
break;
case 0x11d41981 :
case 0x11d41983 :
F_4 ( V_2 , 0x05 , 0x06 ) ;
break;
case 0x11d41986 :
F_4 ( V_2 , 0x1b , 0x1a ) ;
break;
}
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
return 0 ;
}
static void F_11 ( void * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_23 )
return;
if ( V_2 -> V_19 )
V_22 = ! V_22 ;
F_12 ( V_2 , V_4 -> V_23 , 0 ,
V_18 ,
V_22 ? 0x02 : 0x00 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_14 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_24 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_25 * V_26 = & V_4 -> V_27 . V_28 ;
int V_10 ;
V_2 -> V_29 = 1 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = 1 ;
V_4 -> V_27 . V_24 = V_24 ;
if ( ! V_4 -> V_27 . V_32 )
V_4 -> V_27 . V_32 = V_33 ;
V_10 = F_16 ( V_2 , V_26 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_34 = V_35 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_4 -> V_27 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_39 == V_40 ) {
V_2 -> V_41 = 1 ;
V_4 -> V_27 . V_42 = 1 ;
V_4 -> V_27 . V_43 . V_44 = F_11 ;
V_4 -> V_23 = 0x1b ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_39 == V_40 ) {
V_2 -> V_19 = 0 ;
V_4 -> V_27 . V_42 = 1 ;
V_4 -> V_23 = 0x1b ;
}
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_39 == V_40 ) {
F_22 ( V_2 , V_38 , V_39 ) ;
V_4 -> V_27 . V_32 = V_45 ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_3 * V_4 ;
static T_1 V_46 [] = {
0x1a , 0x03 ,
0x1b , 0x03 ,
0x1c , 0x04 ,
0x1d , 0x05 ,
0x1e , 0x03 ,
0
} ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_19 = 1 ;
V_4 -> V_27 . V_47 = 0x07 ;
V_4 -> V_27 . V_48 = 0x19 ;
F_25 ( V_4 , 0x18 , 0 , V_49 ) ;
V_4 -> V_27 . V_50 . V_51 = 1 ;
V_4 -> V_27 . V_52 = V_46 ;
V_4 -> V_27 . V_53 = 1 ;
F_26 ( V_2 , V_54 , V_55 ,
V_56 ) ;
F_27 ( V_2 , V_40 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 ) {
F_28 ( V_2 ) ;
return V_10 ;
}
F_27 ( V_2 , V_57 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_61 [] = { L_1 , L_2 } ;
static const char * const V_62 [] = { L_1 , L_3 , L_4 } ;
T_1 V_63 = V_4 -> V_27 . V_50 . V_64 ;
int V_65 = F_31 ( V_2 , V_63 ) ;
if ( V_65 == 2 )
return F_32 ( V_58 , V_60 , 2 , V_61 ) ;
else if ( V_65 == 3 )
return F_32 ( V_58 , V_60 , 3 , V_62 ) ;
else
return - V_66 ;
}
static int F_33 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_68 -> V_69 . V_70 . V_71 [ 0 ] = V_4 -> V_72 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = V_68 -> V_69 . V_70 . V_71 [ 0 ] ;
T_1 V_63 = V_4 -> V_27 . V_50 . V_64 ;
int V_65 = F_31 ( V_2 , V_63 ) ;
if ( V_73 >= V_65 )
return - V_66 ;
if ( V_4 -> V_72 == V_73 )
return 0 ;
V_4 -> V_72 = V_73 ;
F_35 ( V_2 , V_63 , 0 ,
V_74 , V_73 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_63 = V_4 -> V_27 . V_50 . V_64 ;
int V_65 ;
if ( ! V_63 )
return 0 ;
V_65 = F_31 ( V_2 , V_63 ) ;
if ( V_65 != 2 && V_65 != 3 )
return 0 ;
if ( ! F_37 ( & V_4 -> V_27 , NULL , & V_75 ) )
return - V_13 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
static T_1 V_76 [] = { 0x08 } ;
static T_1 V_77 [] = { 0x09 } ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_47 = 0x0e ;
V_4 -> V_27 . V_48 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_49 ) ;
F_39 ( V_2 , 0x0c , F_40 ( V_76 ) , V_76 ) ;
F_39 ( V_2 , 0x0d , F_40 ( V_77 ) , V_77 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_36 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static void F_41 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_39 == V_40 ) {
V_4 -> V_27 . V_43 . V_44 = F_11 ;
V_4 -> V_23 = 0x05 ;
}
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
if ( V_39 == V_40 )
F_43 ( V_2 , 0x11 , V_78 ,
( 0x17 << V_79 ) |
( 0x17 << V_80 ) |
( 0x05 << V_81 ) |
( 1 << V_82 ) ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_47 = 0x0e ;
V_4 -> V_27 . V_48 = 0x10 ;
F_25 ( V_4 , 0x0d , 0 , V_49 ) ;
F_26 ( V_2 , NULL , V_83 , V_84 ) ;
F_27 ( V_2 , V_40 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_36 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_57 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static int F_45 ( struct V_11 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_46 ( V_2 , V_60 , V_4 -> V_85 ,
V_4 -> V_86 ) ;
}
static int F_47 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_48 ( V_2 , V_68 , V_4 -> V_85 ,
V_4 -> V_86 , V_4 -> V_50 . V_87 ) ;
}
static int F_49 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_10 = F_50 ( V_2 , V_68 , V_4 -> V_85 ,
V_4 -> V_86 ,
& V_4 -> V_50 . V_87 ) ;
if ( V_10 >= 0 && V_4 -> V_88 )
V_4 -> V_50 . V_89 = V_4 -> V_50 . V_87 / 2 ;
return V_10 ;
}
static int F_51 ( struct V_11 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
static const char * const V_90 [] = {
L_1 , L_3 , L_4 , L_5 ,
} ;
int V_65 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_65 > 4 )
V_65 = 4 ;
return F_32 ( V_58 , V_60 , V_65 , V_90 ) ;
}
static int F_52 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_68 -> V_69 . V_70 . V_71 [ 0 ] = V_4 -> V_72 ;
return 0 ;
}
static int F_53 ( struct V_11 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_30 ( V_58 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_73 = V_68 -> V_69 . V_70 . V_71 [ 0 ] ;
struct V_91 * V_92 ;
int V_65 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_73 >= V_65 )
return - V_66 ;
if ( V_4 -> V_72 == V_73 )
return 0 ;
F_54 ( & V_2 -> V_93 ) ;
V_2 -> V_94 = 1 ;
V_92 = F_55 ( V_2 ,
V_4 -> V_95 [ V_4 -> V_72 ] ) ;
if ( V_92 )
F_56 ( V_2 , V_92 , false , true ) ;
V_92 = F_55 ( V_2 , V_4 -> V_95 [ V_73 ] ) ;
if ( V_92 )
F_56 ( V_2 , V_92 , true , true ) ;
V_4 -> V_72 = V_73 ;
V_2 -> V_94 = 0 ;
F_57 ( & V_2 -> V_93 ) ;
F_58 ( V_2 ) ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_96 , V_10 ;
V_10 = F_60 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_4 -> V_27 . V_28 . V_97 )
return 0 ;
for ( V_96 = 0 ; V_96 < 4 ; V_96 ++ ) {
struct V_91 * V_92 ;
V_92 = F_55 ( V_2 , V_4 -> V_95 [ V_96 ] ) ;
if ( V_92 )
F_56 ( V_2 , V_92 , V_92 -> V_98 , false ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_96 , V_65 ;
static struct V_91 V_99 [ 4 ] = {
{
. V_100 = 3 ,
. V_92 = { 0x02 , 0x1d , 0x1b } ,
. V_101 = { 0 , 0 , 0 } ,
. V_102 = { 0 , 0 , 0 } ,
} ,
{
. V_100 = 4 ,
. V_92 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_101 = { 0 , 0 , 1 , 0 } ,
. V_102 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_100 = 4 ,
. V_92 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_101 = { 0 , 1 , 1 , 0 } ,
. V_102 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_100 = 4 ,
. V_92 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_101 = { 0 , 2 , 1 , 0 } ,
. V_102 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_4 -> V_27 . V_28 . V_97 ||
F_62 ( F_63 ( V_2 , 0x1d ) ) != V_103 )
return 0 ;
V_65 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_65 != 3 && V_65 != 4 )
return 0 ;
for ( V_96 = 0 ; V_96 < V_65 ; V_96 ++ ) {
struct V_91 * V_92 = F_64 ( & V_4 -> V_27 . V_104 ) ;
if ( ! V_92 )
return - V_13 ;
* V_92 = V_99 [ V_96 ] ;
if ( ! V_96 )
V_92 -> V_98 = 1 ;
V_4 -> V_95 [ V_96 ] = F_65 ( V_2 , V_92 ) ;
}
if ( ! F_37 ( & V_4 -> V_27 , NULL , & V_105 ) )
return - V_13 ;
V_2 -> V_34 . V_106 = F_59 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_47 = 0x20 ;
V_4 -> V_27 . V_107 = 0x21 ;
V_4 -> V_27 . V_48 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_49 ) ;
F_26 ( V_2 , V_108 , NULL , V_109 ) ;
F_27 ( V_2 , V_40 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_61 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_57 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static void F_67 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
if ( V_39 == V_40 )
F_43 ( V_2 , 0x20 , V_78 ,
( 0x17 << V_79 ) |
( 0x17 << V_80 ) |
( 0x05 << V_81 ) |
( 1 << V_82 ) ) ;
}
static void F_68 ( void * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_23 )
F_11 ( V_21 , V_22 ) ;
F_12 ( V_2 , 0x01 , 0 ,
V_110 ,
V_22 ? 0x00 : 0x02 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
static const struct V_111 V_112 [] = {
{ 0x01 , V_113 , 0x02 } ,
{ 0x01 , V_114 , 0x02 } ,
{ 0x01 , V_110 , 0x02 } ,
{} ,
} ;
switch ( V_39 ) {
case V_40 :
V_4 -> V_27 . V_43 . V_44 = F_68 ;
V_4 -> V_27 . V_115 = 1 ;
F_70 ( V_2 , V_112 ) ;
break;
case V_57 :
if ( V_4 -> V_27 . V_28 . V_116 == V_117 )
V_4 -> V_23 = V_4 -> V_27 . V_28 . V_118 [ 0 ] ;
else
V_4 -> V_23 = V_4 -> V_27 . V_28 . V_119 [ 0 ] ;
break;
}
}
static void F_71 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_39 == V_40 ) {
V_4 -> V_27 . V_42 = 1 ;
V_4 -> V_27 . V_43 . V_44 = F_11 ;
V_4 -> V_23 = 0x12 ;
V_4 -> V_7 = F_72 ( 0x20 , 3 , 3 , V_78 ) ;
V_4 -> V_27 . V_48 = 0 ;
}
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_47 = 0x20 ;
V_4 -> V_27 . V_107 = 0x21 ;
V_4 -> V_27 . V_48 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_49 ) ;
F_26 ( V_2 , NULL , V_120 , V_121 ) ;
F_27 ( V_2 , V_40 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_36 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_57 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_47 = 0x20 ;
V_4 -> V_27 . V_107 = 0x21 ;
V_4 -> V_27 . V_48 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_49 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_61 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_75 ( void )
{
return F_76 ( & V_122 ) ;
}
static void T_3 F_77 ( void )
{
F_78 ( & V_122 ) ;
}
