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
V_4 -> V_27 . V_32 = 1 ;
V_10 = F_16 ( V_2 , V_26 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_33 = V_34 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_4 -> V_27 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_38 == V_39 ) {
V_2 -> V_40 = 1 ;
V_4 -> V_27 . V_41 = 1 ;
V_4 -> V_27 . V_42 . V_43 = F_11 ;
V_4 -> V_23 = 0x1b ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_38 == V_39 ) {
V_2 -> V_19 = 0 ;
V_4 -> V_27 . V_41 = 1 ;
V_4 -> V_23 = 0x1b ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_3 * V_4 ;
static T_1 V_44 [] = {
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
V_4 -> V_27 . V_45 = 0x07 ;
V_4 -> V_27 . V_46 = 0x19 ;
F_24 ( V_4 , 0x18 , 0 , V_47 ) ;
V_4 -> V_27 . V_48 . V_49 = 1 ;
V_4 -> V_27 . V_50 = V_44 ;
V_4 -> V_27 . V_51 = 1 ;
F_25 ( V_2 , V_52 , V_53 ,
V_54 ) ;
F_26 ( V_2 , V_39 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 ) {
F_27 ( V_2 ) ;
return V_10 ;
}
F_26 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_59 [] = { L_1 , L_2 } ;
static const char * const V_60 [] = { L_1 , L_3 , L_4 } ;
T_1 V_61 = V_4 -> V_27 . V_48 . V_62 ;
int V_63 = F_30 ( V_2 , V_61 ) ;
if ( V_63 == 2 )
return F_31 ( V_56 , V_58 , 2 , V_59 ) ;
else if ( V_63 == 3 )
return F_31 ( V_56 , V_58 , 3 , V_60 ) ;
else
return - V_64 ;
}
static int F_32 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_66 -> V_67 . V_68 . V_69 [ 0 ] = V_4 -> V_70 ;
return 0 ;
}
static int F_33 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_71 = V_66 -> V_67 . V_68 . V_69 [ 0 ] ;
T_1 V_61 = V_4 -> V_27 . V_48 . V_62 ;
int V_63 = F_30 ( V_2 , V_61 ) ;
if ( V_71 >= V_63 )
return - V_64 ;
if ( V_4 -> V_70 == V_71 )
return 0 ;
V_4 -> V_70 = V_71 ;
F_34 ( V_2 , V_61 , 0 ,
V_72 , V_71 ) ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_61 = V_4 -> V_27 . V_48 . V_62 ;
int V_63 ;
if ( ! V_61 )
return 0 ;
V_63 = F_30 ( V_2 , V_61 ) ;
if ( V_63 != 2 && V_63 != 3 )
return 0 ;
if ( ! F_36 ( & V_4 -> V_27 , NULL , & V_73 ) )
return - V_13 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
static T_1 V_74 [] = { 0x08 } ;
static T_1 V_75 [] = { 0x09 } ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_45 = 0x0e ;
V_4 -> V_27 . V_46 = 0x10 ;
F_24 ( V_4 , 0x10 , 0 , V_47 ) ;
F_38 ( V_2 , 0x0c , F_39 ( V_74 ) , V_74 ) ;
F_38 ( V_2 , 0x0d , F_39 ( V_75 ) , V_75 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_35 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_27 ( V_2 ) ;
return V_10 ;
}
static void F_40 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_38 == V_39 ) {
V_4 -> V_27 . V_42 . V_43 = F_11 ;
V_4 -> V_23 = 0x05 ;
}
}
static void F_41 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
if ( V_38 == V_39 )
F_42 ( V_2 , 0x11 , V_76 ,
( 0x17 << V_77 ) |
( 0x17 << V_78 ) |
( 0x05 << V_79 ) |
( 1 << V_80 ) ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_45 = 0x0e ;
V_4 -> V_27 . V_46 = 0x10 ;
F_24 ( V_4 , 0x0d , 0 , V_47 ) ;
F_25 ( V_2 , NULL , V_81 , V_82 ) ;
F_26 ( V_2 , V_39 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_35 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_26 ( V_2 , V_55 ) ;
return 0 ;
error:
F_27 ( V_2 ) ;
return V_10 ;
}
static int F_44 ( struct V_11 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_45 ( V_2 , V_58 , V_4 -> V_83 ,
V_4 -> V_84 ) ;
}
static int F_46 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_47 ( V_2 , V_66 , V_4 -> V_83 ,
V_4 -> V_84 , V_4 -> V_48 . V_85 ) ;
}
static int F_48 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_10 = F_49 ( V_2 , V_66 , V_4 -> V_83 ,
V_4 -> V_84 ,
& V_4 -> V_48 . V_85 ) ;
if ( V_10 >= 0 && V_4 -> V_86 )
V_4 -> V_48 . V_87 = V_4 -> V_48 . V_85 / 2 ;
return V_10 ;
}
static int F_50 ( struct V_11 * V_56 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
static const char * const V_88 [] = {
L_1 , L_3 , L_4 , L_5 ,
} ;
int V_63 = F_30 ( V_2 , 0x0b ) + 1 ;
if ( V_63 > 4 )
V_63 = 4 ;
return F_31 ( V_56 , V_58 , V_63 , V_88 ) ;
}
static int F_51 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_66 -> V_67 . V_68 . V_69 [ 0 ] = V_4 -> V_70 ;
return 0 ;
}
static int F_52 ( struct V_11 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_29 ( V_56 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_71 = V_66 -> V_67 . V_68 . V_69 [ 0 ] ;
struct V_89 * V_90 ;
int V_63 = F_30 ( V_2 , 0x0b ) + 1 ;
if ( V_71 >= V_63 )
return - V_64 ;
if ( V_4 -> V_70 == V_71 )
return 0 ;
F_53 ( & V_2 -> V_91 ) ;
V_2 -> V_92 = 1 ;
V_90 = F_54 ( V_2 ,
V_4 -> V_93 [ V_4 -> V_70 ] ) ;
if ( V_90 )
F_55 ( V_2 , V_90 , false , true ) ;
V_90 = F_54 ( V_2 , V_4 -> V_93 [ V_71 ] ) ;
if ( V_90 )
F_55 ( V_2 , V_90 , true , true ) ;
V_4 -> V_70 = V_71 ;
V_2 -> V_92 = 0 ;
F_56 ( & V_2 -> V_91 ) ;
F_57 ( V_2 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_94 , V_10 ;
V_10 = F_59 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_4 -> V_27 . V_28 . V_95 )
return 0 ;
for ( V_94 = 0 ; V_94 < 4 ; V_94 ++ ) {
struct V_89 * V_90 ;
V_90 = F_54 ( V_2 , V_4 -> V_93 [ V_94 ] ) ;
if ( V_90 )
F_55 ( V_2 , V_90 , V_90 -> V_96 , false ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_94 , V_63 ;
static struct V_89 V_97 [ 4 ] = {
{
. V_98 = 3 ,
. V_90 = { 0x02 , 0x1d , 0x1b } ,
. V_99 = { 0 , 0 , 0 } ,
. V_100 = { 0 , 0 , 0 } ,
} ,
{
. V_98 = 4 ,
. V_90 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_99 = { 0 , 0 , 1 , 0 } ,
. V_100 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_98 = 4 ,
. V_90 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_99 = { 0 , 1 , 1 , 0 } ,
. V_100 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_98 = 4 ,
. V_90 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_99 = { 0 , 2 , 1 , 0 } ,
. V_100 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_4 -> V_27 . V_28 . V_95 ||
F_61 ( F_62 ( V_2 , 0x1d ) ) != V_101 )
return 0 ;
V_63 = F_30 ( V_2 , 0x0b ) + 1 ;
if ( V_63 != 3 && V_63 != 4 )
return 0 ;
for ( V_94 = 0 ; V_94 < V_63 ; V_94 ++ ) {
struct V_89 * V_90 = F_63 ( & V_4 -> V_27 . V_102 ) ;
if ( ! V_90 )
return - V_13 ;
* V_90 = V_97 [ V_94 ] ;
if ( ! V_94 )
V_90 -> V_96 = 1 ;
V_4 -> V_93 [ V_94 ] = F_64 ( V_2 , V_90 ) ;
}
if ( ! F_36 ( & V_4 -> V_27 , NULL , & V_103 ) )
return - V_13 ;
V_2 -> V_33 . V_104 = F_58 ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_45 = 0x20 ;
V_4 -> V_27 . V_105 = 0x21 ;
V_4 -> V_27 . V_46 = 0x10 ;
F_24 ( V_4 , 0x10 , 0 , V_47 ) ;
F_25 ( V_2 , V_106 , NULL , V_107 ) ;
F_26 ( V_2 , V_39 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_60 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_26 ( V_2 , V_55 ) ;
return 0 ;
error:
F_27 ( V_2 ) ;
return V_10 ;
}
static void F_66 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
if ( V_38 == V_39 )
F_42 ( V_2 , 0x20 , V_76 ,
( 0x17 << V_77 ) |
( 0x17 << V_78 ) |
( 0x05 << V_79 ) |
( 1 << V_80 ) ) ;
}
static void F_67 ( void * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_23 )
F_11 ( V_21 , V_22 ) ;
F_12 ( V_2 , 0x01 , 0 ,
V_108 ,
V_22 ? 0x00 : 0x02 ) ;
}
static void F_68 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
static const struct V_109 V_110 [] = {
{ 0x01 , V_111 , 0x02 } ,
{ 0x01 , V_112 , 0x02 } ,
{ 0x01 , V_108 , 0x02 } ,
{} ,
} ;
switch ( V_38 ) {
case V_39 :
V_4 -> V_27 . V_42 . V_43 = F_67 ;
V_4 -> V_27 . V_113 = 1 ;
F_69 ( V_2 , V_110 ) ;
break;
case V_55 :
if ( V_4 -> V_27 . V_28 . V_114 == V_115 )
V_4 -> V_23 = V_4 -> V_27 . V_28 . V_116 [ 0 ] ;
else
V_4 -> V_23 = V_4 -> V_27 . V_28 . V_117 [ 0 ] ;
break;
}
}
static void F_70 ( struct V_1 * V_2 ,
const struct V_36 * V_37 , int V_38 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_38 == V_39 ) {
V_4 -> V_27 . V_41 = 1 ;
V_4 -> V_27 . V_42 . V_43 = F_11 ;
V_4 -> V_23 = 0x12 ;
V_4 -> V_7 = F_71 ( 0x20 , 3 , 3 , V_76 ) ;
V_4 -> V_27 . V_46 = 0 ;
}
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_45 = 0x20 ;
V_4 -> V_27 . V_105 = 0x21 ;
V_4 -> V_27 . V_46 = 0x10 ;
F_24 ( V_4 , 0x10 , 0 , V_47 ) ;
F_25 ( V_2 , NULL , V_118 , V_119 ) ;
F_26 ( V_2 , V_39 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_35 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_26 ( V_2 , V_55 ) ;
return 0 ;
error:
F_27 ( V_2 ) ;
return V_10 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_27 . V_45 = 0x20 ;
V_4 -> V_27 . V_105 = 0x21 ;
V_4 -> V_27 . V_46 = 0x10 ;
F_24 ( V_4 , 0x10 , 0 , V_47 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_60 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_27 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_74 ( void )
{
return F_75 ( & V_120 ) ;
}
static void T_3 F_76 ( void )
{
F_77 ( & V_120 ) ;
}
