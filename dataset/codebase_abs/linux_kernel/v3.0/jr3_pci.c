static int F_1 ( struct V_1 * V_2 , char * V_3 ,
int (* F_2)( struct V_1 * V_2 ,
const T_1 * V_4 , T_2 V_5 ) )
{
int V_6 = 0 ;
const struct V_7 * V_8 ;
char * V_9 ;
static const char * V_10 = L_1 ;
struct V_11 * V_12 = V_2 -> V_13 ;
V_9 = F_3 ( strlen ( V_10 ) + strlen ( V_3 ) + 1 , V_14 ) ;
if ( ! V_9 ) {
V_6 = - V_15 ;
} else {
V_9 [ 0 ] = '\0' ;
strcat ( V_9 , V_10 ) ;
strcat ( V_9 , V_3 ) ;
V_6 = F_4 ( & V_8 , V_9 ,
& V_12 -> V_16 -> V_2 ) ;
if ( V_6 == 0 ) {
if ( ! F_2 )
V_6 = - V_17 ;
else
V_6 = F_2 ( V_2 , V_8 -> V_4 , V_8 -> V_5 ) ;
F_5 ( V_8 ) ;
}
F_6 ( V_9 ) ;
}
return V_6 ;
}
static struct V_18 F_7 ( int V_19 , int V_20 )
{
struct V_18 V_6 ;
V_6 . V_19 = V_19 ;
V_6 . V_20 = V_20 ;
return V_6 ;
}
static int F_8 ( volatile struct V_21 * V_22 )
{
return F_9 ( & V_22 -> V_23 ) == 0 ;
}
static void F_10 ( volatile struct V_21 * V_22 ,
struct V_24 V_25 , short V_26 )
{
int V_27 ;
V_26 &= 0x000f ;
for ( V_27 = 0 ; V_27 < 8 ; V_27 ++ ) {
F_11 ( & V_22 -> V_28 [ V_26 ] . V_29 [ V_27 ] . V_30 ,
V_25 . V_29 [ V_27 ] . V_30 ) ;
F_12 ( 1 ) ;
F_13 ( & V_22 -> V_28 [ V_26 ] . V_29 [ V_27 ] . V_31 ,
V_25 . V_29 [ V_27 ] . V_31 ) ;
F_12 ( 1 ) ;
if ( V_25 . V_29 [ V_27 ] . V_30 == V_32 )
break;
}
}
static void F_14 ( volatile struct V_21 * V_22 ,
short V_33 )
{
F_13 ( & V_22 -> V_23 , 0x0500 + ( V_33 & 0x000f ) ) ;
}
static void F_15 ( volatile struct V_21 * V_22 , short V_34 )
{
F_13 ( & V_22 -> V_23 , 0x0600 + ( V_34 & 0x000f ) ) ;
}
static void F_16 ( volatile struct V_21 * V_22 )
{
F_13 ( & V_22 -> V_23 , 0x0700 ) ;
}
static void F_17 ( volatile struct V_21 * V_22 ,
struct V_35 V_36 )
{
F_18 ( L_2 ,
V_36 . V_37 ,
V_36 . V_38 ,
V_36 . V_39 , V_36 . V_40 , V_36 . V_41 , V_36 . V_42 ) ;
F_13 ( & V_22 -> V_36 . V_37 , V_36 . V_37 ) ;
F_13 ( & V_22 -> V_36 . V_38 , V_36 . V_38 ) ;
F_13 ( & V_22 -> V_36 . V_39 , V_36 . V_39 ) ;
F_13 ( & V_22 -> V_36 . V_40 , V_36 . V_40 ) ;
F_13 ( & V_22 -> V_36 . V_41 , V_36 . V_41 ) ;
F_13 ( & V_22 -> V_36 . V_42 , V_36 . V_42 ) ;
F_13 ( & V_22 -> V_23 , 0x0a00 ) ;
}
static struct V_35 F_19 ( volatile struct V_21
* V_22 )
{
struct V_35 V_6 ;
V_6 . V_37 = F_9 ( & V_22 -> V_43 . V_37 ) ;
V_6 . V_38 = F_9 ( & V_22 -> V_43 . V_38 ) ;
V_6 . V_39 = F_9 ( & V_22 -> V_43 . V_39 ) ;
V_6 . V_40 = F_9 ( & V_22 -> V_43 . V_40 ) ;
V_6 . V_41 = F_9 ( & V_22 -> V_43 . V_41 ) ;
V_6 . V_42 = F_9 ( & V_22 -> V_43 . V_42 ) ;
return V_6 ;
}
static struct V_35 F_20 ( volatile struct V_21
* V_22 )
{
struct V_35 V_6 ;
V_6 . V_37 = F_9 ( & V_22 -> V_44 . V_37 ) ;
V_6 . V_38 = F_9 ( & V_22 -> V_44 . V_38 ) ;
V_6 . V_39 = F_9 ( & V_22 -> V_44 . V_39 ) ;
V_6 . V_40 = F_9 ( & V_22 -> V_44 . V_40 ) ;
V_6 . V_41 = F_9 ( & V_22 -> V_44 . V_41 ) ;
V_6 . V_42 = F_9 ( & V_22 -> V_44 . V_42 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
struct V_47 * V_48 , unsigned int * V_4 )
{
int V_6 ;
struct V_49 * V_50 ;
int V_22 ;
V_50 = V_46 -> V_13 ;
V_22 = F_22 ( V_48 -> V_51 ) ;
if ( V_50 == NULL || V_22 > 57 ) {
V_6 = - V_17 ;
} else {
int V_27 ;
V_6 = V_48 -> V_52 ;
if ( V_50 -> V_53 != V_54 ||
( F_23 ( & V_50 -> V_22 -> V_55 ) & ( V_56 | V_57 |
V_58 ) ) ) {
if ( V_50 -> V_53 == V_54 ) {
V_50 -> V_53 = V_59 ;
}
V_6 = - V_60 ;
}
for ( V_27 = 0 ; V_27 < V_48 -> V_52 ; V_27 ++ ) {
if ( V_22 < 56 ) {
int V_61 , V_62 ;
V_61 = V_22 % 8 ;
V_62 = V_22 / 8 ;
if ( V_50 -> V_53 != V_54 ) {
V_4 [ V_27 ] = 0 ;
} else {
int V_63 = 0 ;
switch ( V_61 ) {
case 0 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_37 ) ;
}
break;
case 1 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_38 ) ;
}
break;
case 2 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_39 ) ;
}
break;
case 3 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_40 ) ;
}
break;
case 4 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_41 ) ;
}
break;
case 5 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_42 ) ;
}
break;
case 6 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_64 ) ;
}
break;
case 7 : {
V_63 = F_9
( & V_50 -> V_22 -> V_62
[ V_62 ] . V_65 ) ;
}
break;
}
V_4 [ V_27 ] = V_63 + 0x4000 ;
}
} else if ( V_22 == 56 ) {
if ( V_50 -> V_53 != V_54 ) {
V_4 [ V_27 ] = 0 ;
} else {
V_4 [ V_27 ] =
F_23 ( & V_50 -> V_22 -> V_66 ) ;
}
} else if ( V_22 == 57 ) {
if ( V_50 -> V_53 != V_54 ) {
V_4 [ V_27 ] = 0 ;
} else {
V_4 [ V_27 ] =
F_23 ( & V_50 -> V_22 -> V_67 ) ;
}
}
}
}
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_18 ( L_3 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_68 ; V_27 ++ ) {
struct V_49 * V_50 ;
V_50 = V_2 -> V_69 [ V_27 ] . V_13 ;
if ( V_50 ) {
F_18 ( L_4 , V_50 , V_50 -> V_67 ,
V_50 -> V_70 ) ;
}
}
return 0 ;
}
int F_25 ( const T_1 * V_4 , T_2 V_5 , int * V_71 , unsigned int * V_72 )
{
int V_6 = 0 ;
if ( V_71 != 0 && V_72 != 0 ) {
for (; * V_71 < V_5 && ! isxdigit ( V_4 [ * V_71 ] ) ; ( * V_71 ) ++ ) {
}
* V_72 = 0 ;
for (; * V_71 < V_5 ; ( * V_71 ) ++ ) {
int V_73 ;
V_73 = F_26 ( V_4 [ * V_71 ] ) ;
if ( V_73 >= 0 ) {
V_6 = 1 ;
* V_72 = ( * V_72 << 4 ) + V_73 ;
} else
break;
}
}
return V_6 ;
}
static int F_27 ( struct V_1 * V_2 , const T_1 * V_4 ,
T_2 V_5 )
{
int V_6 , V_74 , V_71 , V_75 ;
V_6 = 0 ;
V_74 = 1 ;
V_71 = 0 ;
V_75 = 0 ;
while ( V_74 ) {
unsigned int V_76 , V_77 ;
V_74 = V_74 && F_25 ( V_4 , V_5 , & V_71 , & V_76 ) ;
if ( V_74 && V_76 == 0xffff ) {
V_75 = 1 ;
break;
}
V_74 = V_74 && F_25 ( V_4 , V_5 , & V_71 , & V_77 ) ;
while ( V_74 && V_76 > 0 ) {
unsigned int V_78 ;
V_74 = V_74 && F_25 ( V_4 , V_5 , & V_71 , & V_78 ) ;
V_76 -- ;
}
}
if ( ! V_75 ) {
V_6 = - V_79 ;
} else {
int V_27 ;
struct V_11 * V_50 = V_2 -> V_13 ;
for ( V_27 = 0 ; V_27 < V_50 -> V_68 ; V_27 ++ ) {
struct V_49 * V_80 ;
V_80 = V_2 -> V_69 [ V_27 ] . V_13 ;
V_74 = 1 ;
V_71 = 0 ;
while ( V_74 ) {
unsigned int V_76 , V_77 ;
V_74 = V_74
&& F_25 ( V_4 , V_5 , & V_71 , & V_76 ) ;
if ( V_74 && V_76 == 0xffff )
break;
V_74 = V_74
&& F_25 ( V_4 , V_5 , & V_71 , & V_77 ) ;
F_18 ( L_5 , V_27 ,
V_76 , V_77 ) ;
while ( V_74 && V_76 > 0 ) {
if ( V_77 & 0x4000 ) {
unsigned int V_81 ;
V_74 = V_74
&& F_25 ( V_4 ,
V_5 , & V_71 ,
& V_81 ) ;
V_76 -- ;
} else {
unsigned int V_81 , V_82 ;
V_74 = V_74
&& F_25 ( V_4 ,
V_5 , & V_71 ,
& V_81 ) ;
V_74 = V_74
&& F_25 ( V_4 , V_5 ,
& V_71 ,
& V_82 ) ;
V_76 -= 2 ;
if ( V_74 ) {
F_11 ( & V_50 ->
V_83 -> V_22
[ V_27 ] . V_84
[ V_77 ] , V_81 ) ;
F_12 ( 1 ) ;
F_11 ( & V_50 ->
V_83 -> V_22
[ V_27 ] . V_85
[ V_77 ] , V_82 ) ;
F_12 ( 1 ) ;
}
}
V_77 ++ ;
}
}
}
}
return V_6 ;
}
static struct V_18 F_28 ( struct V_45 * V_46 )
{
struct V_18 V_6 = F_7 ( 1000 , 2000 ) ;
struct V_49 * V_50 = V_46 -> V_13 ;
int V_27 ;
if ( V_50 ) {
volatile struct V_21 * V_22 = V_50 -> V_22 ;
int V_55 = F_23 ( & V_22 -> V_55 ) ;
if ( V_55 != V_50 -> V_55 ) {
F_18 ( L_6 , V_50 -> V_55 , V_55 ) ;
V_50 -> V_55 = V_55 ;
}
if ( V_55 & ( V_56 | V_57 | V_58 ) ) {
V_50 -> V_53 = V_59 ;
}
switch ( V_50 -> V_53 ) {
case V_59 : {
T_3 V_66 = F_23 ( & V_22 -> V_66 ) ;
T_3 V_67 = F_23 ( & V_22 -> V_67 ) ;
if ( ( V_55 & ( V_56 | V_57 ) ) ||
V_66 == 0 || V_67 == 0 ) {
V_6 = F_7 ( 1000 , 2000 ) ;
} else {
V_50 -> V_86 = 0 ;
V_50 -> V_53 =
V_87 ;
V_6 = F_7 ( 1000 , 2000 ) ;
}
}
break;
case V_87 : {
V_50 -> V_86 ++ ;
if ( V_50 -> V_86 < 10 ) {
V_6 = F_7 ( 1000 , 2000 ) ;
} else {
struct V_24 V_25 ;
V_50 -> V_66 =
F_23 ( & V_22 -> V_66 ) ;
V_50 -> V_67 =
F_23 ( & V_22 -> V_67 ) ;
F_18
( L_7 ,
V_50 -> V_70 ) ;
F_18 ( L_8 ,
V_50 -> V_66 ) ;
F_18 ( L_9 ,
V_50 -> V_67 ) ;
for ( V_27 = 0 ; V_27 < F_29 ( V_25 . V_29 ) ; V_27 ++ ) {
V_25 . V_29 [ V_27 ] . V_30 =
(enum V_88 ) 0 ;
V_25 . V_29 [ V_27 ] . V_31 = 0 ;
}
F_10 ( V_22 , V_25 , 0 ) ;
F_14 ( V_22 , 0 ) ;
V_50 -> V_53 =
V_89 ;
V_6 = F_7 ( 20 , 100 ) ;
}
} break;
case V_89 : {
if ( ! F_8 ( V_22 ) ) {
F_18
( L_10 ,
F_8 ( V_22 ) ) ;
V_6 = F_7 ( 20 , 100 ) ;
} else {
struct V_35 V_43 ;
struct V_35 V_44 ;
V_43 =
F_19 ( V_22 ) ;
F_18 ( L_11 ) ;
F_18 ( L_12 , ( V_43 ) . V_37 ) ;
F_18 ( L_12 , ( V_43 ) . V_38 ) ;
F_18 ( L_12 , ( V_43 ) . V_39 ) ;
F_18 ( L_12 , ( V_43 ) . V_40 ) ;
F_18 ( L_12 , ( V_43 ) . V_41 ) ;
F_18 ( L_12 , ( V_43 ) . V_42 ) ;
F_18 ( L_13 ) ;
V_44 =
F_20 ( V_22 ) ;
F_18 ( L_14 ) ;
F_18 ( L_12 , ( V_44 ) . V_37 ) ;
F_18 ( L_12 , ( V_44 ) . V_38 ) ;
F_18 ( L_12 , ( V_44 ) . V_39 ) ;
F_18 ( L_12 , ( V_44 ) . V_40 ) ;
F_18 ( L_12 , ( V_44 ) . V_41 ) ;
F_18 ( L_12 , ( V_44 ) . V_42 ) ;
F_18 ( L_13 ) ;
F_17 ( V_22 ,
V_44 ) ;
V_50 -> V_53 =
V_90 ;
V_6 = F_7 ( 20 , 100 ) ;
}
}
break;
case V_90 : {
if ( ! F_8 ( V_22 ) ) {
F_18
( L_15 ,
F_8 ( V_22 ) ) ;
V_6 = F_7 ( 20 , 100 ) ;
} else {
volatile struct V_91 * V_36 ;
V_36 = & V_22 -> V_36 ;
V_50 -> V_92 [ 0 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_37 ) * 1000 ;
V_50 -> V_92 [ 0 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_37 ) * 1000 ;
V_50 -> V_92 [ 1 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_38 ) * 1000 ;
V_50 -> V_92 [ 1 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_38 ) * 1000 ;
V_50 -> V_92 [ 2 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_39 ) * 1000 ;
V_50 -> V_92 [ 2 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_39 ) * 1000 ;
V_50 -> V_92 [ 3 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_40 ) * 100 ;
V_50 -> V_92 [ 3 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_40 ) * 100 ;
V_50 -> V_92 [ 4 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_41 ) * 100 ;
V_50 -> V_92 [ 4 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_41 ) * 100 ;
V_50 -> V_92 [ 5 ] . V_92 . V_19 =
- F_9 ( & V_36 -> V_42 ) * 100 ;
V_50 -> V_92 [ 5 ] . V_92 . V_20 =
F_9 ( & V_36 -> V_42 ) * 100 ;
V_50 -> V_92 [ 6 ] . V_92 . V_19 = - F_9 ( & V_36 -> V_64 ) * 100 ;
V_50 -> V_92 [ 6 ] . V_92 . V_20 = F_9 ( & V_36 -> V_64 ) * 100 ;
V_50 -> V_92 [ 7 ] . V_92 . V_19 = - F_9 ( & V_36 -> V_65 ) * 100 ;
V_50 -> V_92 [ 7 ] . V_92 . V_20 = F_9 ( & V_36 -> V_65 ) * 100 ;
V_50 -> V_92 [ 8 ] . V_92 . V_19 = 0 ;
V_50 -> V_92 [ 8 ] . V_92 . V_20 = 65535 ;
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 9 ; V_27 ++ ) {
F_18 ( L_16 ,
V_27 ,
V_50 ->
V_92 [ V_27 ] . V_92 .
V_19 ,
V_50 ->
V_92 [ V_27 ] . V_92 .
V_20 ) ;
}
}
F_15 ( V_22 , 0 ) ;
V_50 -> V_53 =
V_93 ;
V_6 = F_7 ( 40 , 100 ) ;
}
}
break;
case V_93 : {
if ( ! F_8 ( V_22 ) ) {
F_18
( L_17 ,
F_8 ( V_22 ) ) ;
V_6 = F_7 ( 20 , 100 ) ;
} else {
F_18
( L_18 ,
F_9 ( & V_22 -> V_94 . V_37 ) ,
F_9 ( & V_22 -> V_94 . V_38 ) ,
F_9 ( & V_22 -> V_94 . V_39 ) ,
F_9 ( & V_22 -> V_94 . V_40 ) ,
F_9 ( & V_22 -> V_94 . V_41 ) ,
F_9 ( & V_22 -> V_94 . V_42 ) ) ;
F_13 ( & V_22 -> V_94 . V_37 , 0 ) ;
F_13 ( & V_22 -> V_94 . V_38 , 0 ) ;
F_13 ( & V_22 -> V_94 . V_39 , 0 ) ;
F_13 ( & V_22 -> V_94 . V_40 , 0 ) ;
F_13 ( & V_22 -> V_94 . V_41 , 0 ) ;
F_13 ( & V_22 -> V_94 . V_42 , 0 ) ;
F_16 ( V_22 ) ;
V_50 -> V_53 = V_54 ;
}
}
break;
case V_54 : {
F_7 ( 10000 , 20000 ) ;
}
break;
default: {
F_7 ( 1000 , 2000 ) ;
}
break;
}
}
return V_6 ;
}
static void F_30 ( unsigned long V_4 )
{
unsigned long V_95 ;
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned long V_96 ;
int V_97 ;
int V_27 ;
F_31 ( & V_2 -> V_98 , V_95 ) ;
V_97 = 1000 ;
V_96 = V_99 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_68 ; V_27 ++ ) {
struct V_49 * V_100 =
V_2 -> V_69 [ V_27 ] . V_13 ;
if ( V_96 > V_100 -> V_101 ) {
struct V_18 V_102 ;
V_102 = F_28 ( & V_2 -> V_69 [ V_27 ] ) ;
V_100 -> V_101 =
V_99 + F_32 ( V_102 . V_19 ) ;
V_100 -> V_103 =
V_99 + F_32 ( V_102 . V_20 ) ;
if ( V_102 . V_20 && V_102 . V_20 < V_97 ) {
V_97 = V_102 . V_20 ;
}
}
}
F_33 ( & V_2 -> V_98 , V_95 ) ;
V_12 -> V_104 . V_105 = V_99 + F_32 ( V_97 ) ;
F_34 ( & V_12 -> V_104 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
int V_6 = 0 ;
struct V_16 * V_108 = NULL ;
int V_109 , V_110 , V_27 ;
struct V_11 * V_12 ;
F_18 ( L_19 , V_2 -> V_111 ) ;
V_109 = V_107 -> V_112 [ 0 ] ;
V_110 = V_107 -> V_112 [ 1 ] ;
if ( sizeof( struct V_21 ) != 0xc00 ) {
F_18 ( L_20 ,
( unsigned ) sizeof( struct V_21 ) , 0xc00 ) ;
return - V_17 ;
}
V_6 = F_36 ( V_2 , sizeof( struct V_11 ) ) ;
if ( V_6 < 0 )
return - V_15 ;
V_108 = NULL ;
V_12 = V_2 -> V_13 ;
F_37 ( & V_12 -> V_104 ) ;
while ( 1 ) {
V_108 = F_38 ( V_113 , V_114 , V_108 ) ;
if ( V_108 == NULL ) {
break;
} else {
switch ( V_108 -> V_115 ) {
case V_116 : {
V_12 -> V_68 = 1 ;
}
break;
case V_117 : {
V_12 -> V_68 = 1 ;
}
break;
case V_118 : {
V_12 -> V_68 = 2 ;
}
break;
case V_119 : {
V_12 -> V_68 = 3 ;
}
break;
case V_120 : {
V_12 -> V_68 = 4 ;
}
break;
default: {
V_12 -> V_68 = 0 ;
}
}
if ( V_12 -> V_68 >= 1 ) {
if ( V_109 == 0 && V_110 == 0 ) {
break;
} else if ( V_109 == V_108 -> V_121 -> V_122 &&
V_110 == F_39 ( V_108 -> V_123 ) ) {
break;
}
}
}
}
if ( ! V_108 ) {
F_18 ( L_21 ) ;
return - V_124 ;
} else {
V_12 -> V_16 = V_108 ;
V_2 -> V_125 = L_22 ;
}
V_6 = F_40 ( V_108 , L_22 ) ;
if ( V_6 < 0 )
return - V_124 ;
V_12 -> V_126 = 1 ;
V_12 -> V_83 = F_41 ( F_42 ( V_108 , 0 ) ,
F_43 ( struct V_127 , V_22 [ V_12 -> V_68 ] ) ) ;
if ( ! V_12 -> V_83 )
return - V_15 ;
V_6 = F_44 ( V_2 , V_12 -> V_68 ) ;
if ( V_6 < 0 )
goto V_128;
V_2 -> V_129 = F_24 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_68 ; V_27 ++ ) {
V_2 -> V_69 [ V_27 ] . type = V_130 ;
V_2 -> V_69 [ V_27 ] . V_131 = V_132 | V_133 ;
V_2 -> V_69 [ V_27 ] . V_134 = 8 * 7 + 2 ;
V_2 -> V_69 [ V_27 ] . V_135 = F_21 ;
V_2 -> V_69 [ V_27 ] . V_13 =
F_45 ( sizeof( struct V_49 ) , V_14 ) ;
if ( V_2 -> V_69 [ V_27 ] . V_13 ) {
struct V_49 * V_50 ;
int V_136 ;
V_50 = V_2 -> V_69 [ V_27 ] . V_13 ;
V_50 -> V_22 = & V_12 -> V_83 -> V_22 [ V_27 ] . V_4 ;
F_18 ( L_23 ,
V_50 -> V_22 , V_12 -> V_83 ,
( ( char * ) ( V_50 -> V_22 ) -
( char * ) ( V_12 -> V_83 ) ) ) ;
V_50 -> V_70 = V_27 ;
for ( V_136 = 0 ; V_136 < 8 ; V_136 ++ ) {
int V_137 ;
V_50 -> V_92 [ V_136 ] . V_138 = 1 ;
V_50 -> V_92 [ V_136 ] . V_92 . V_19 = - 1000000 ;
V_50 -> V_92 [ V_136 ] . V_92 . V_20 = 1000000 ;
for ( V_137 = 0 ; V_137 < 7 ; V_137 ++ ) {
V_50 -> V_139 [ V_136 + V_137 * 8 ] =
(struct V_140 * ) & V_50 ->
V_92 [ V_136 ] ;
V_50 -> V_141 [ V_136 + V_137 * 8 ] = 0x7fff ;
}
}
V_50 -> V_92 [ 8 ] . V_138 = 1 ;
V_50 -> V_92 [ 8 ] . V_92 . V_19 = 0 ;
V_50 -> V_92 [ 8 ] . V_92 . V_20 = 65536 ;
V_50 -> V_139 [ 56 ] =
(struct V_140 * ) & V_50 -> V_92 [ 8 ] ;
V_50 -> V_139 [ 57 ] =
(struct V_140 * ) & V_50 -> V_92 [ 8 ] ;
V_50 -> V_141 [ 56 ] = 0xffff ;
V_50 -> V_141 [ 57 ] = 0xffff ;
V_2 -> V_69 [ V_27 ] . V_142 = 0 ;
V_2 -> V_69 [ V_27 ] . V_139 =
V_50 -> V_139 ;
V_2 -> V_69 [ V_27 ] . V_143 = 0 ;
V_2 -> V_69 [ V_27 ] . V_141 = V_50 -> V_141 ;
}
}
V_12 -> V_83 -> V_22 [ 0 ] . V_144 = 0 ;
V_6 = F_1 ( V_2 , L_24 , F_27 ) ;
F_18 ( L_25 , V_6 ) ;
if ( V_6 < 0 )
goto V_128;
F_46 ( 25 ) ;
for ( V_27 = 0 ; V_27 < 0x18 ; V_27 ++ ) {
F_18 ( L_26 ,
F_23 ( & V_12 -> V_83 -> V_22 [ 0 ] .
V_4 . V_145 [ V_27 ] ) >> 8 ) ;
}
for ( V_27 = 0 ; V_27 < V_12 -> V_68 ; V_27 ++ ) {
struct V_49 * V_50 = V_2 -> V_69 [ V_27 ] . V_13 ;
V_50 -> V_101 = V_99 + F_32 ( 500 ) ;
V_50 -> V_103 = V_99 + F_32 ( 2000 ) ;
}
V_12 -> V_104 . V_4 = ( unsigned long ) V_2 ;
V_12 -> V_104 . V_146 = F_30 ;
V_12 -> V_104 . V_105 = V_99 + F_32 ( 1000 ) ;
F_34 ( & V_12 -> V_104 ) ;
V_128:
return V_6 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_18 ( L_27 , V_2 -> V_111 ) ;
if ( V_12 ) {
F_48 ( & V_12 -> V_104 ) ;
if ( V_2 -> V_69 ) {
for ( V_27 = 0 ; V_27 < V_12 -> V_68 ; V_27 ++ )
F_6 ( V_2 -> V_69 [ V_27 ] . V_13 ) ;
}
if ( V_12 -> V_83 )
F_49 ( ( void * ) V_12 -> V_83 ) ;
if ( V_12 -> V_126 )
F_50 ( V_12 -> V_16 ) ;
if ( V_12 -> V_16 )
F_51 ( V_12 -> V_16 ) ;
}
return 0 ;
}
static int T_4 F_52 ( struct V_16 * V_2 ,
const struct V_147 * V_148 )
{
return F_53 ( V_2 , V_149 . V_150 ) ;
}
static void T_5 F_54 ( struct V_16 * V_2 )
{
F_55 ( V_2 ) ;
}
static int T_6 F_56 ( void )
{
int V_151 ;
V_151 = F_57 ( & V_149 ) ;
if ( V_151 < 0 )
return V_151 ;
V_152 . V_3 = ( char * ) V_149 . V_150 ;
return F_58 ( & V_152 ) ;
}
static void T_7 F_59 ( void )
{
F_60 ( & V_152 ) ;
F_61 ( & V_149 ) ;
}
