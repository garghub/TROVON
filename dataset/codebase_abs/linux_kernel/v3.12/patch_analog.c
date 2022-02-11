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
static int F_11 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_1 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_21 * V_22 = & V_4 -> V_23 . V_24 ;
int V_10 ;
V_2 -> V_25 = 1 ;
V_2 -> V_26 = 1 ;
V_2 -> V_27 = 1 ;
V_4 -> V_23 . V_28 = 1 ;
V_10 = F_14 ( V_2 , V_22 , NULL , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_15 ( V_2 , V_22 ) ;
if ( V_10 < 0 )
return V_10 ;
V_2 -> V_29 = V_30 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return - V_13 ;
V_2 -> V_4 = V_4 ;
F_18 ( & V_4 -> V_23 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
if ( V_34 == V_35 )
V_2 -> V_36 = 1 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_10 ;
struct V_3 * V_4 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_2 -> V_19 = 1 ;
V_4 -> V_23 . V_37 = 0x07 ;
V_4 -> V_23 . V_38 = 0x19 ;
F_21 ( V_4 , 0x18 , 0 , V_39 ) ;
V_4 -> V_23 . V_40 . V_41 = 1 ;
F_22 ( V_2 , V_42 , V_43 ,
V_44 ) ;
F_23 ( V_2 , V_35 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 ) {
F_24 ( V_2 ) ;
return V_10 ;
}
F_23 ( V_2 , V_45 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
static const char * const V_49 [] = { L_1 , L_2 } ;
static const char * const V_50 [] = { L_1 , L_3 , L_4 } ;
T_1 V_51 = V_4 -> V_23 . V_40 . V_52 ;
int V_53 = F_27 ( V_2 , V_51 ) ;
if ( V_53 == 2 )
return F_28 ( V_46 , V_48 , 2 , V_49 ) ;
else if ( V_53 == 3 )
return F_28 ( V_46 , V_48 , 3 , V_50 ) ;
else
return - V_54 ;
}
static int F_29 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_56 -> V_57 . V_58 . V_59 [ 0 ] = V_4 -> V_60 ;
return 0 ;
}
static int F_30 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_61 = V_56 -> V_57 . V_58 . V_59 [ 0 ] ;
T_1 V_51 = V_4 -> V_23 . V_40 . V_52 ;
int V_53 = F_27 ( V_2 , V_51 ) ;
if ( V_61 >= V_53 )
return - V_54 ;
if ( V_4 -> V_60 == V_61 )
return 0 ;
V_4 -> V_60 = V_61 ;
F_31 ( V_2 , V_51 , 0 ,
V_62 , V_61 ) ;
return 1 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_51 = V_4 -> V_23 . V_40 . V_52 ;
int V_53 ;
if ( ! V_51 )
return 0 ;
V_53 = F_27 ( V_2 , V_51 ) ;
if ( V_53 != 2 && V_53 != 3 )
return 0 ;
if ( ! F_33 ( & V_4 -> V_23 , NULL , & V_63 ) )
return - V_13 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_23 . V_38 = 0x10 ;
F_21 ( V_4 , 0x10 , 0 , V_39 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_32 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_24 ( V_2 ) ;
return V_10 ;
}
static void F_35 ( void * V_64 , int V_65 )
{
struct V_1 * V_2 = V_64 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 -> V_66 )
return;
F_36 ( V_2 , V_4 -> V_66 , 0 ,
V_18 ,
V_65 ? 0x02 : 0x00 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_34 == V_35 ) {
V_4 -> V_23 . V_67 . V_68 = F_35 ;
V_4 -> V_66 = 0x05 ;
}
}
static void F_38 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
if ( V_34 == V_35 )
F_39 ( V_2 , 0x11 , V_69 ,
( 0x17 << V_70 ) |
( 0x17 << V_71 ) |
( 0x05 << V_72 ) |
( 1 << V_73 ) ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return - V_13 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_23 . V_37 = 0x0e ;
V_4 -> V_23 . V_38 = 0x10 ;
F_21 ( V_4 , 0x0d , 0 , V_39 ) ;
F_22 ( V_2 , NULL , V_74 , V_75 ) ;
F_23 ( V_2 , V_35 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_32 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_23 ( V_2 , V_45 ) ;
return 0 ;
error:
F_24 ( V_2 ) ;
return V_10 ;
}
static int F_41 ( struct V_11 * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_42 ( V_2 , V_48 , V_4 -> V_76 ,
V_4 -> V_77 ) ;
}
static int F_43 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
return F_44 ( V_2 , V_56 , V_4 -> V_76 ,
V_4 -> V_77 , V_4 -> V_40 . V_78 ) ;
}
static int F_45 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_10 = F_46 ( V_2 , V_56 , V_4 -> V_76 ,
V_4 -> V_77 ,
& V_4 -> V_40 . V_78 ) ;
if ( V_10 >= 0 && V_4 -> V_79 )
V_4 -> V_40 . V_80 = V_4 -> V_40 . V_78 / 2 ;
return V_10 ;
}
static int F_47 ( struct V_11 * V_46 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
static const char * const V_81 [] = {
L_1 , L_3 , L_4 , L_5 ,
} ;
int V_53 = F_27 ( V_2 , 0x0b ) + 1 ;
if ( V_53 > 4 )
V_53 = 4 ;
return F_28 ( V_46 , V_48 , V_53 , V_81 ) ;
}
static int F_48 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_56 -> V_57 . V_58 . V_59 [ 0 ] = V_4 -> V_60 ;
return 0 ;
}
static int F_49 ( struct V_11 * V_46 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( V_46 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_61 = V_56 -> V_57 . V_58 . V_59 [ 0 ] ;
struct V_82 * V_83 ;
int V_53 = F_27 ( V_2 , 0x0b ) + 1 ;
if ( V_61 >= V_53 )
return - V_54 ;
if ( V_4 -> V_60 == V_61 )
return 0 ;
F_50 ( & V_2 -> V_84 ) ;
V_2 -> V_85 = 1 ;
V_83 = F_51 ( V_2 ,
V_4 -> V_86 [ V_4 -> V_60 ] ) ;
if ( V_83 )
F_52 ( V_2 , V_83 , false , true ) ;
V_83 = F_51 ( V_2 , V_4 -> V_86 [ V_61 ] ) ;
if ( V_83 )
F_52 ( V_2 , V_83 , true , true ) ;
V_4 -> V_60 = V_61 ;
V_2 -> V_85 = 0 ;
F_53 ( & V_2 -> V_84 ) ;
F_54 ( V_2 ) ;
return 1 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_87 , V_10 ;
V_10 = F_56 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_4 -> V_23 . V_24 . V_88 )
return 0 ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ ) {
struct V_82 * V_83 ;
V_83 = F_51 ( V_2 , V_4 -> V_86 [ V_87 ] ) ;
if ( V_83 )
F_52 ( V_2 , V_83 , V_83 -> V_89 , false ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_87 , V_53 ;
static struct V_82 V_90 [ 4 ] = {
{
. V_91 = 3 ,
. V_83 = { 0x02 , 0x1d , 0x1b } ,
. V_92 = { 0 , 0 , 0 } ,
. V_93 = { 0 , 0 , 0 } ,
} ,
{
. V_91 = 4 ,
. V_83 = { 0x08 , 0x0b , 0x1d , 0x1b } ,
. V_92 = { 0 , 0 , 1 , 0 } ,
. V_93 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_91 = 4 ,
. V_83 = { 0x09 , 0x0b , 0x1d , 0x1b } ,
. V_92 = { 0 , 1 , 1 , 0 } ,
. V_93 = { 0 , 1 , 0 , 0 } ,
} ,
{
. V_91 = 4 ,
. V_83 = { 0x0f , 0x0b , 0x1d , 0x1b } ,
. V_92 = { 0 , 2 , 1 , 0 } ,
. V_93 = { 0 , 1 , 0 , 0 } ,
} ,
} ;
if ( ! V_4 -> V_23 . V_24 . V_88 ||
F_58 ( F_59 ( V_2 , 0x1d ) ) != V_94 )
return 0 ;
V_53 = F_27 ( V_2 , 0x0b ) + 1 ;
if ( V_53 != 3 && V_53 != 4 )
return 0 ;
for ( V_87 = 0 ; V_87 < V_53 ; V_87 ++ ) {
struct V_82 * V_83 = F_60 ( & V_4 -> V_23 . V_95 ) ;
if ( ! V_83 )
return - V_13 ;
* V_83 = V_90 [ V_87 ] ;
if ( ! V_87 )
V_83 -> V_89 = 1 ;
V_4 -> V_86 [ V_87 ] = F_61 ( V_2 , V_83 ) ;
}
if ( ! F_33 ( & V_4 -> V_23 , NULL , & V_96 ) )
return - V_13 ;
V_2 -> V_29 . V_97 = F_55 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_23 . V_37 = 0x20 ;
V_4 -> V_23 . V_98 = 0x21 ;
V_4 -> V_23 . V_38 = 0x10 ;
F_21 ( V_4 , 0x10 , 0 , V_39 ) ;
F_22 ( V_2 , V_99 , NULL , V_100 ) ;
F_23 ( V_2 , V_35 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_57 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_23 ( V_2 , V_45 ) ;
return 0 ;
error:
F_24 ( V_2 ) ;
return V_10 ;
}
static void F_63 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
if ( V_34 == V_35 )
F_39 ( V_2 , 0x20 , V_69 ,
( 0x17 << V_70 ) |
( 0x17 << V_71 ) |
( 0x05 << V_72 ) |
( 1 << V_73 ) ) ;
}
static void F_64 ( void * V_64 , int V_65 )
{
struct V_1 * V_2 = V_64 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_66 )
F_35 ( V_64 , V_65 ) ;
F_36 ( V_2 , 0x01 , 0 ,
V_101 ,
V_65 ? 0x00 : 0x02 ) ;
}
static void F_65 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
static const struct V_102 V_103 [] = {
{ 0x01 , V_104 , 0x02 } ,
{ 0x01 , V_105 , 0x02 } ,
{ 0x01 , V_101 , 0x02 } ,
{} ,
} ;
switch ( V_34 ) {
case V_35 :
V_4 -> V_23 . V_67 . V_68 = F_64 ;
F_66 ( V_2 , V_103 ) ;
break;
case V_45 :
if ( V_4 -> V_23 . V_24 . V_106 == V_107 )
V_4 -> V_66 = V_4 -> V_23 . V_24 . V_108 [ 0 ] ;
else
V_4 -> V_66 = V_4 -> V_23 . V_24 . V_109 [ 0 ] ;
break;
}
}
static void F_67 ( struct V_1 * V_2 ,
const struct V_32 * V_33 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_34 == V_35 )
V_4 -> V_23 . V_110 = 1 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_23 . V_37 = 0x20 ;
V_4 -> V_23 . V_38 = 0x10 ;
F_21 ( V_4 , 0x10 , 0 , V_39 ) ;
F_22 ( V_2 , NULL , V_111 , V_112 ) ;
F_23 ( V_2 , V_35 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_32 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
F_23 ( V_2 , V_45 ) ;
return 0 ;
error:
F_24 ( V_2 ) ;
return V_10 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_10 ;
V_10 = F_16 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 = V_2 -> V_4 ;
V_4 -> V_23 . V_37 = 0x20 ;
V_4 -> V_23 . V_98 = 0x21 ;
V_4 -> V_23 . V_38 = 0x10 ;
F_21 ( V_4 , 0x10 , 0 , V_39 ) ;
V_10 = F_13 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
V_10 = F_57 ( V_2 ) ;
if ( V_10 < 0 )
goto error;
return 0 ;
error:
F_24 ( V_2 ) ;
return V_10 ;
}
static int T_2 F_70 ( void )
{
return F_71 ( & V_113 ) ;
}
static void T_3 F_72 ( void )
{
F_73 ( & V_113 ) ;
}
