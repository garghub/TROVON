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
switch ( V_2 -> V_20 . V_21 ) {
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
static void F_11 ( void * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_24 )
return;
if ( V_2 -> V_19 )
V_23 = ! V_23 ;
F_12 ( V_2 , V_4 -> V_24 , 0 ,
V_18 ,
V_23 ? 0x02 : 0x00 ) ;
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
static int F_15 ( struct V_1 * V_2 , bool V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_26 * V_27 = & V_4 -> V_28 . V_29 ;
int V_10 ;
V_2 -> V_30 = 1 ;
V_2 -> V_31 = 1 ;
V_2 -> V_32 = 1 ;
V_4 -> V_28 . V_25 = V_25 ;
if ( ! V_4 -> V_28 . V_33 )
V_4 -> V_28 . V_33 = V_34 ;
V_10 = F_16 ( V_2 , V_27 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_35 = V_36 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_37 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
F_20 ( & V_4 -> V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_40 == V_41 ) {
V_2 -> V_42 = 1 ;
V_4 -> V_28 . V_43 = 1 ;
V_4 -> V_28 . V_44 . V_45 = F_11 ;
V_4 -> V_24 = 0x1b ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_40 == V_41 ) {
V_2 -> V_19 = 0 ;
V_4 -> V_28 . V_43 = 1 ;
V_4 -> V_24 = 0x1b ;
}
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_40 == V_41 ) {
F_22 ( V_2 , V_39 , V_40 ) ;
V_4 -> V_28 . V_33 = V_46 ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_3 * V_4 ;
static T_1 V_47 [] = {
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
V_4 -> V_28 . V_48 = 0x07 ;
V_4 -> V_28 . V_49 = 0x19 ;
F_25 ( V_4 , 0x18 , 0 , V_50 ) ;
V_4 -> V_28 . V_51 . V_52 = 1 ;
V_4 -> V_28 . V_53 = V_47 ;
V_4 -> V_28 . V_54 = 1 ;
F_26 ( V_2 , V_55 , V_56 ,
V_57 ) ;
F_27 ( V_2 , V_41 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 ) {
F_28 ( V_2 ) ;
return V_10 ;
}
F_27 ( V_2 , V_58 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_62 [] = { L_1 , L_2 } ;
static const char * const V_63 [] = { L_1 , L_3 , L_4 } ;
T_1 V_64 = V_4 -> V_28 . V_51 . V_65 ;
int V_66 = F_31 ( V_2 , V_64 ) ;
if ( V_66 == 2 )
return F_32 ( V_59 , V_61 , 2 , V_62 ) ;
else if ( V_66 == 3 )
return F_32 ( V_59 , V_61 , 3 , V_63 ) ;
else
return - V_67 ;
}
static int F_33 ( struct V_11 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_69 -> V_70 . V_71 . V_72 [ 0 ] = V_4 -> V_73 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_74 = V_69 -> V_70 . V_71 . V_72 [ 0 ] ;
T_1 V_64 = V_4 -> V_28 . V_51 . V_65 ;
int V_66 = F_31 ( V_2 , V_64 ) ;
if ( V_74 >= V_66 )
return - V_67 ;
if ( V_4 -> V_73 == V_74 )
return 0 ;
V_4 -> V_73 = V_74 ;
F_35 ( V_2 , V_64 , 0 ,
V_75 , V_74 ) ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_64 = V_4 -> V_28 . V_51 . V_65 ;
int V_66 ;
if ( ! V_64 )
return 0 ;
V_66 = F_31 ( V_2 , V_64 ) ;
if ( V_66 != 2 && V_66 != 3 )
return 0 ;
if ( ! F_37 ( & V_4 -> V_28 , NULL , & V_76 ) )
return - V_13 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
static T_1 V_77 [] = { 0x08 } ;
static T_1 V_78 [] = { 0x09 } ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_28 . V_48 = 0x0e ;
V_4 -> V_28 . V_49 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_50 ) ;
F_39 ( V_2 , 0x0c , F_40 ( V_77 ) , V_77 ) ;
F_39 ( V_2 , 0x0d , F_40 ( V_78 ) , V_78 ) ;
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
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_40 == V_41 ) {
V_4 -> V_28 . V_44 . V_45 = F_11 ;
V_4 -> V_24 = 0x05 ;
}
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
if ( V_40 == V_41 )
F_43 ( V_2 , 0x11 , V_79 ,
( 0x17 << V_80 ) |
( 0x17 << V_81 ) |
( 0x05 << V_82 ) |
( 1 << V_83 ) ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_28 . V_48 = 0x0e ;
V_4 -> V_28 . V_49 = 0x10 ;
F_25 ( V_4 , 0x0d , 0 , V_50 ) ;
F_26 ( V_2 , NULL , V_84 , V_85 ) ;
F_27 ( V_2 , V_41 ) ;
V_10 = F_15 ( V_2 , false ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_36 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_58 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static int F_45 ( struct V_11 * V_59 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
static const char * const V_86 [] = {
L_1 , L_3 , L_4 , L_5 ,
} ;
int V_66 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_66 > 4 )
V_66 = 4 ;
return F_32 ( V_59 , V_61 , V_66 , V_86 ) ;
}
static int F_46 ( struct V_11 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_69 -> V_70 . V_71 . V_72 [ 0 ] = V_4 -> V_73 ;
return 0 ;
}
static int F_47 ( struct V_11 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_74 = V_69 -> V_70 . V_71 . V_72 [ 0 ] ;
struct V_87 * V_88 ;
int V_66 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_74 >= V_66 )
return - V_67 ;
if ( V_4 -> V_73 == V_74 )
return 0 ;
F_48 ( & V_2 -> V_89 ) ;
V_88 = F_49 ( V_2 ,
V_4 -> V_90 [ V_4 -> V_73 ] ) ;
if ( V_88 )
F_50 ( V_2 , V_88 , false , true ) ;
V_88 = F_49 ( V_2 , V_4 -> V_90 [ V_74 ] ) ;
if ( V_88 )
F_50 ( V_2 , V_88 , true , true ) ;
V_4 -> V_73 = V_74 ;
F_51 ( & V_2 -> V_89 ) ;
return 1 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_91 , V_10 ;
V_10 = F_53 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_4 -> V_28 . V_29 . V_92 )
return 0 ;
for ( V_91 = 0 ; V_91 < 4 ; V_91 ++ ) {
struct V_87 * V_88 ;
V_88 = F_49 ( V_2 , V_4 -> V_90 [ V_91 ] ) ;
if ( V_88 )
F_50 ( V_2 , V_88 , V_88 -> V_93 , false ) ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_91 , V_66 ;
static struct V_87 V_94 [ 4 ] = {
{
. V_95 = 3 ,
. V_88 = { 0x02 , 0x1d , 0x1b } ,
. V_96 = { 0 , 0 , 0 } ,
. V_97 = { 0 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_88 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 0 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_88 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 1 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_95 = 4 ,
. V_88 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_96 = { 0 , 2 , 1 , 0 } ,
. V_97 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_4 -> V_28 . V_29 . V_92 ||
F_55 ( F_56 ( V_2 , 0x1d ) ) != V_98 )
return 0 ;
V_66 = F_31 ( V_2 , 0x0b ) + 1 ;
if ( V_66 != 3 && V_66 != 4 )
return 0 ;
for ( V_91 = 0 ; V_91 < V_66 ; V_91 ++ ) {
struct V_87 * V_88 = F_57 ( & V_4 -> V_28 . V_99 ) ;
if ( ! V_88 )
return - V_13 ;
* V_88 = V_94 [ V_91 ] ;
if ( ! V_91 )
V_88 -> V_93 = 1 ;
V_4 -> V_90 [ V_91 ] = F_58 ( V_2 , V_88 ) ;
}
if ( ! F_37 ( & V_4 -> V_28 , NULL , & V_100 ) )
return - V_13 ;
V_2 -> V_35 . V_101 = F_52 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_28 . V_48 = 0x20 ;
V_4 -> V_28 . V_102 = 0x21 ;
V_4 -> V_28 . V_49 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_50 ) ;
F_26 ( V_2 , V_103 , NULL , V_104 ) ;
F_27 ( V_2 , V_41 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_54 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_58 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static void F_60 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
if ( V_40 == V_41 )
F_43 ( V_2 , 0x20 , V_79 ,
( 0x17 << V_80 ) |
( 0x17 << V_81 ) |
( 0x05 << V_82 ) |
( 1 << V_83 ) ) ;
}
static void F_61 ( void * V_22 , int V_23 )
{
struct V_1 * V_2 = V_22 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_24 )
F_11 ( V_22 , V_23 ) ;
F_12 ( V_2 , 0x01 , 0 ,
V_105 ,
V_23 ? 0x00 : 0x02 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
switch ( V_40 ) {
case V_41 :
V_4 -> V_28 . V_44 . V_45 = F_61 ;
V_4 -> V_28 . V_106 = 1 ;
F_35 ( V_2 , 0x01 , 0 ,
V_107 , 0x02 ) ;
F_35 ( V_2 , 0x01 , 0 ,
V_108 , 0x02 ) ;
F_35 ( V_2 , 0x01 , 0 ,
V_105 , 0x02 ) ;
break;
case V_58 :
if ( V_4 -> V_28 . V_29 . V_109 == V_110 )
V_4 -> V_24 = V_4 -> V_28 . V_29 . V_111 [ 0 ] ;
else
V_4 -> V_24 = V_4 -> V_28 . V_29 . V_112 [ 0 ] ;
break;
}
}
static void F_63 ( struct V_1 * V_2 ,
const struct V_38 * V_39 , int V_40 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_40 == V_41 ) {
V_4 -> V_28 . V_43 = 1 ;
V_4 -> V_28 . V_44 . V_45 = F_11 ;
V_4 -> V_24 = 0x12 ;
V_4 -> V_7 = F_64 ( 0x20 , 3 , 3 , V_79 ) ;
V_4 -> V_28 . V_49 = 0 ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_28 . V_48 = 0x20 ;
V_4 -> V_28 . V_102 = 0x21 ;
V_4 -> V_28 . V_49 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_50 ) ;
F_26 ( V_2 , NULL , V_113 , V_114 ) ;
F_27 ( V_2 , V_41 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_36 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_27 ( V_2 , V_58 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_18 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_28 . V_48 = 0x20 ;
V_4 -> V_28 . V_102 = 0x21 ;
V_4 -> V_28 . V_49 = 0x10 ;
F_25 ( V_4 , 0x10 , 0 , V_50 ) ;
V_10 = F_15 ( V_2 , true ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_54 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_10 ;
}
