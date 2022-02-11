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
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_24 * V_25 = & V_4 -> V_26 . V_27 ;
int V_10 ;
V_2 -> V_28 = 1 ;
V_2 -> V_29 = 1 ;
V_2 -> V_30 = 1 ;
V_4 -> V_26 . V_31 = 1 ;
V_10 = F_16 ( V_2 , V_25 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_2 , V_25 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_32 = V_33 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_4 -> V_26 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_37 == V_38 ) {
V_2 -> V_39 = 1 ;
V_4 -> V_26 . V_40 = 1 ;
V_4 -> V_26 . V_41 . V_42 = F_11 ;
V_4 -> V_23 = 0x1b ;
}
}
static int F_22 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_3 * V_4 ;
static T_1 V_43 [] = {
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
V_4 -> V_26 . V_44 = 0x07 ;
V_4 -> V_26 . V_45 = 0x19 ;
F_23 ( V_4 , 0x18 , 0 , V_46 ) ;
V_4 -> V_26 . V_47 . V_48 = 1 ;
V_4 -> V_26 . V_49 = V_43 ;
V_4 -> V_26 . V_50 = 1 ;
F_24 ( V_2 , V_51 , V_52 ,
V_53 ) ;
F_25 ( V_2 , V_38 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 ) {
F_26 ( V_2 ) ;
return V_10 ;
}
F_25 ( V_2 , V_54 ) ;
return 0 ;
}
static int F_27 ( struct V_11 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_58 [] = { L_1 , L_2 } ;
static const char * const V_59 [] = { L_1 , L_3 , L_4 } ;
T_1 V_60 = V_4 -> V_26 . V_47 . V_61 ;
int V_62 = F_29 ( V_2 , V_60 ) ;
if ( V_62 == 2 )
return F_30 ( V_55 , V_57 , 2 , V_58 ) ;
else if ( V_62 == 3 )
return F_30 ( V_55 , V_57 , 3 , V_59 ) ;
else
return - V_63 ;
}
static int F_31 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_65 -> V_66 . V_67 . V_68 [ 0 ] = V_4 -> V_69 ;
return 0 ;
}
static int F_32 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_70 = V_65 -> V_66 . V_67 . V_68 [ 0 ] ;
T_1 V_60 = V_4 -> V_26 . V_47 . V_61 ;
int V_62 = F_29 ( V_2 , V_60 ) ;
if ( V_70 >= V_62 )
return - V_63 ;
if ( V_4 -> V_69 == V_70 )
return 0 ;
V_4 -> V_69 = V_70 ;
F_33 ( V_2 , V_60 , 0 ,
V_71 , V_70 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_60 = V_4 -> V_26 . V_47 . V_61 ;
int V_62 ;
if ( ! V_60 )
return 0 ;
V_62 = F_29 ( V_2 , V_60 ) ;
if ( V_62 != 2 && V_62 != 3 )
return 0 ;
if ( ! F_35 ( & V_4 -> V_26 , NULL , & V_72 ) )
return - V_13 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_26 . V_45 = 0x10 ;
F_23 ( V_4 , 0x10 , 0 , V_46 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_34 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_10 ;
}
static void F_37 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_37 == V_38 ) {
V_4 -> V_26 . V_41 . V_42 = F_11 ;
V_4 -> V_23 = 0x05 ;
}
}
static void F_38 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
if ( V_37 == V_38 )
F_39 ( V_2 , 0x11 , V_73 ,
( 0x17 << V_74 ) |
( 0x17 << V_75 ) |
( 0x05 << V_76 ) |
( 1 << V_77 ) ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_26 . V_44 = 0x0e ;
V_4 -> V_26 . V_45 = 0x10 ;
F_23 ( V_4 , 0x0d , 0 , V_46 ) ;
F_24 ( V_2 , NULL , V_78 , V_79 ) ;
F_25 ( V_2 , V_38 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_34 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_25 ( V_2 , V_54 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_10 ;
}
static int F_41 ( struct V_11 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_42 ( V_2 , V_57 , V_4 -> V_80 ,
V_4 -> V_81 ) ;
}
static int F_43 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_44 ( V_2 , V_65 , V_4 -> V_80 ,
V_4 -> V_81 , V_4 -> V_47 . V_82 ) ;
}
static int F_45 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_10 = F_46 ( V_2 , V_65 , V_4 -> V_80 ,
V_4 -> V_81 ,
& V_4 -> V_47 . V_82 ) ;
if ( V_10 >= 0 && V_4 -> V_83 )
V_4 -> V_47 . V_84 = V_4 -> V_47 . V_82 / 2 ;
return V_10 ;
}
static int F_47 ( struct V_11 * V_55 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
static const char * const V_85 [] = {
L_1 , L_3 , L_4 , L_5 ,
} ;
int V_62 = F_29 ( V_2 , 0x0b ) + 1 ;
if ( V_62 > 4 )
V_62 = 4 ;
return F_30 ( V_55 , V_57 , V_62 , V_85 ) ;
}
static int F_48 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_65 -> V_66 . V_67 . V_68 [ 0 ] = V_4 -> V_69 ;
return 0 ;
}
static int F_49 ( struct V_11 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_28 ( V_55 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_70 = V_65 -> V_66 . V_67 . V_68 [ 0 ] ;
struct V_86 * V_87 ;
int V_62 = F_29 ( V_2 , 0x0b ) + 1 ;
if ( V_70 >= V_62 )
return - V_63 ;
if ( V_4 -> V_69 == V_70 )
return 0 ;
F_50 ( & V_2 -> V_88 ) ;
V_2 -> V_89 = 1 ;
V_87 = F_51 ( V_2 ,
V_4 -> V_90 [ V_4 -> V_69 ] ) ;
if ( V_87 )
F_52 ( V_2 , V_87 , false , true ) ;
V_87 = F_51 ( V_2 , V_4 -> V_90 [ V_70 ] ) ;
if ( V_87 )
F_52 ( V_2 , V_87 , true , true ) ;
V_4 -> V_69 = V_70 ;
V_2 -> V_89 = 0 ;
F_53 ( & V_2 -> V_88 ) ;
F_54 ( V_2 ) ;
return 1 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_91 , V_10 ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_4 -> V_26 . V_27 . V_92 )
return 0 ;
for ( V_91 = 0 ; V_91 < 4 ; V_91 ++ ) {
struct V_86 * V_87 ;
V_87 = F_51 ( V_2 , V_4 -> V_90 [ V_91 ] ) ;
if ( V_87 )
F_52 ( V_2 , V_87 , V_87 -> V_93 , false ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_91 , V_62 ;
static struct V_86 V_94 [ 4 ] = {
{
. V_95 = 3 ,
. V_87 = { 0x02 , 0x1d , 0x1b } ,
. V_96 = { 0 , 0 , 0 } ,
. V_97 = { 0 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_87 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 0 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_87 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 1 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_87 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 2 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_4 -> V_26 . V_27 . V_92 ||
F_58 ( F_59 ( V_2 , 0x1d ) ) != V_98 )
return 0 ;
V_62 = F_29 ( V_2 , 0x0b ) + 1 ;
if ( V_62 != 3 && V_62 != 4 )
return 0 ;
for ( V_91 = 0 ; V_91 < V_62 ; V_91 ++ ) {
struct V_86 * V_87 = F_60 ( & V_4 -> V_26 . V_99 ) ;
if ( ! V_87 )
return - V_13 ;
* V_87 = V_94 [ V_91 ] ;
if ( ! V_91 )
V_87 -> V_93 = 1 ;
V_4 -> V_90 [ V_91 ] = F_61 ( V_2 , V_87 ) ;
}
if ( ! F_35 ( & V_4 -> V_26 , NULL , & V_100 ) )
return - V_13 ;
V_2 -> V_32 . V_101 = F_55 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_26 . V_44 = 0x20 ;
V_4 -> V_26 . V_102 = 0x21 ;
V_4 -> V_26 . V_45 = 0x10 ;
F_23 ( V_4 , 0x10 , 0 , V_46 ) ;
F_24 ( V_2 , V_103 , NULL , V_104 ) ;
F_25 ( V_2 , V_38 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_57 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_25 ( V_2 , V_54 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_10 ;
}
static void F_63 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
if ( V_37 == V_38 )
F_39 ( V_2 , 0x20 , V_73 ,
( 0x17 << V_74 ) |
( 0x17 << V_75 ) |
( 0x05 << V_76 ) |
( 1 << V_77 ) ) ;
}
static void F_64 ( void * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_23 )
F_11 ( V_21 , V_22 ) ;
F_12 ( V_2 , 0x01 , 0 ,
V_105 ,
V_22 ? 0x00 : 0x02 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
static const struct V_106 V_107 [] = {
{ 0x01 , V_108 , 0x02 } ,
{ 0x01 , V_109 , 0x02 } ,
{ 0x01 , V_105 , 0x02 } ,
{} ,
} ;
switch ( V_37 ) {
case V_38 :
V_4 -> V_26 . V_41 . V_42 = F_64 ;
V_4 -> V_26 . V_110 = 1 ;
F_66 ( V_2 , V_107 ) ;
break;
case V_54 :
if ( V_4 -> V_26 . V_27 . V_111 == V_112 )
V_4 -> V_23 = V_4 -> V_26 . V_27 . V_113 [ 0 ] ;
else
V_4 -> V_23 = V_4 -> V_26 . V_27 . V_114 [ 0 ] ;
break;
}
}
static void F_67 ( struct V_1 * V_2 ,
const struct V_35 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_37 == V_38 ) {
V_4 -> V_26 . V_40 = 1 ;
V_4 -> V_26 . V_41 . V_42 = F_11 ;
V_4 -> V_23 = 0x12 ;
}
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_26 . V_44 = 0x20 ;
V_4 -> V_26 . V_45 = 0x10 ;
F_23 ( V_4 , 0x10 , 0 , V_46 ) ;
F_24 ( V_2 , NULL , V_115 , V_116 ) ;
F_25 ( V_2 , V_38 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_34 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_25 ( V_2 , V_54 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_10 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_26 . V_44 = 0x20 ;
V_4 -> V_26 . V_102 = 0x21 ;
V_4 -> V_26 . V_45 = 0x10 ;
F_23 ( V_4 , 0x10 , 0 , V_46 ) ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_57 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_70 ( void )
{
return F_71 ( & V_117 ) ;
}
static void T_3 F_72 ( void )
{
F_73 ( & V_117 ) ;
}
