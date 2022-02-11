static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
unsigned long long V_5 ;
if ( ! V_2 )
return - V_6 ;
V_2 -> V_7 = V_2 -> V_8 ;
V_3 = F_2 ( V_2 -> V_9 -> V_10 , L_1 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
return - V_11 ;
V_2 -> V_8 = V_5 ;
F_4 ( ( V_12 , L_2 ,
V_2 -> V_8 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
unsigned long long V_5 ;
if ( ! V_2 )
return - V_6 ;
V_3 = F_2 ( V_2 -> V_9 -> V_10 , L_3 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
return - V_11 ;
V_2 -> V_13 = V_5 ;
F_4 ( ( V_12 , L_4 ,
V_2 -> V_13 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_14 )
{
T_1 V_3 = V_4 ;
union V_15 V_16 = { V_17 } ;
struct V_18 V_19 = { 1 , & V_16 } ;
T_2 V_10 = NULL ;
if ( ! V_2 )
return - V_6 ;
V_3 = F_7 ( V_2 -> V_9 -> V_10 , L_5 , & V_10 ) ;
if ( F_3 ( V_3 ) ) {
F_4 ( ( V_12 , L_6 ) ) ;
return - V_11 ;
}
V_16 . integer . V_20 = V_14 ;
V_3 = F_8 ( V_10 , NULL , & V_19 , NULL ) ;
if ( F_3 ( V_3 ) )
return - V_11 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_21 )
{
T_1 V_3 = V_4 ;
unsigned long long V_5 ;
struct V_22 V_23 ;
int V_24 = 0 ;
int V_25 ;
if ( V_21 & V_26 ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_7 , NULL , & V_5 ) ;
V_2 -> V_27 . V_28 . V_8 = V_5 ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_27 . V_28 . V_29 . V_24 = 0 ;
F_4 ( ( V_12 ,
L_8 ) ) ;
} else if ( V_5 <= 2732 ) {
F_10 (KERN_WARNING FW_BUG L_9
L_10 , tmp) ;
V_2 -> V_27 . V_28 . V_29 . V_24 = 0 ;
} else {
V_2 -> V_27 . V_28 . V_29 . V_24 = 1 ;
F_4 ( ( V_12 ,
L_11 ,
V_2 -> V_27 . V_28 . V_8 ) ) ;
}
if ( V_2 -> V_27 . V_28 . V_29 . V_24 == 1 ) {
if ( V_30 == - 1 ) {
V_2 -> V_27 . V_28 . V_29 . V_24 = 0 ;
} else if ( V_30 > 0 ) {
unsigned long V_31 = F_11 ( V_30 ) ;
if ( V_31 > V_2 -> V_27 . V_28 . V_8 )
F_10 (KERN_WARNING PREFIX
L_12 , crt) ;
V_2 -> V_27 . V_28 . V_8 = V_31 ;
}
}
}
if ( V_21 & V_32 ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_13 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_27 . V_33 . V_29 . V_24 = 0 ;
F_4 ( ( V_12 ,
L_14 ) ) ;
} else {
V_2 -> V_27 . V_33 . V_8 = V_5 ;
V_2 -> V_27 . V_33 . V_29 . V_24 = 1 ;
F_4 ( ( V_12 ,
L_15 ,
V_2 -> V_27 . V_28 . V_8 ) ) ;
}
}
if ( ( ( V_21 & V_34 ) && V_2 -> V_27 . V_35 . V_29 . V_24 ) ||
( V_21 == V_36 ) ) {
V_24 = V_2 -> V_27 . V_35 . V_29 . V_24 ;
if ( V_37 == - 1 ) {
V_3 = V_38 ;
} else if ( V_37 > 0 ) {
V_5 = F_11 ( V_37 ) ;
V_3 = V_4 ;
} else {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_16 , NULL , & V_5 ) ;
}
if ( F_3 ( V_3 ) )
V_2 -> V_27 . V_35 . V_29 . V_24 = 0 ;
else {
V_2 -> V_27 . V_35 . V_8 = V_5 ;
V_2 -> V_27 . V_35 . V_29 . V_24 = 1 ;
if ( V_21 == V_36 ) {
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_17 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_27 . V_35 . V_29 . V_24 = 0 ;
else
V_2 -> V_27 . V_35 . V_39 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_18 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_27 . V_35 . V_29 . V_24 = 0 ;
else
V_2 -> V_27 . V_35 . V_40 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_19 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_27 . V_35 . V_29 . V_24 = 0 ;
else
V_2 -> V_27 . V_35 . V_41 = V_5 ;
}
}
}
if ( ( V_21 & V_42 ) && V_2 -> V_27 . V_35 . V_29 . V_24 ) {
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_20 ,
NULL , & V_23 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_WARNING PREFIX
L_21 ) ;
V_2 -> V_27 . V_35 . V_29 . V_24 = 0 ;
}
else
V_2 -> V_27 . V_35 . V_29 . V_24 = 1 ;
if ( memcmp ( & V_2 -> V_27 . V_35 . V_23 , & V_23 ,
sizeof( struct V_22 ) ) ) {
memcpy ( & V_2 -> V_27 . V_35 . V_23 , & V_23 ,
sizeof( struct V_22 ) ) ;
F_13 ( V_21 , L_22 ) ;
}
}
if ( ( V_21 & V_34 ) || ( V_21 & V_42 ) ) {
if ( V_24 != V_2 -> V_27 . V_35 . V_29 . V_24 )
F_13 ( V_21 , L_23 ) ;
}
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
char V_44 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_25 ) , '\0' } ;
V_24 = V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ;
if ( V_46 == - 1 )
break;
if ( ( V_21 == V_36 ) || ( ( V_21 & V_47 ) &&
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ) ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
V_44 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 = 0 ;
if ( V_25 == 0 )
break;
if ( V_46 <= 0 )
break;
if ( V_25 == 1 )
V_2 -> V_27 . V_45 [ 0 ] . V_8 =
F_11 ( V_46 ) ;
else
V_2 -> V_27 . V_45 [ V_25 - 1 ] . V_8 =
( V_2 -> V_27 . V_45 [ V_25 - 2 ] . V_8 <
F_11 ( V_46 ) ?
V_2 -> V_27 . V_45 [ V_25 - 2 ] . V_8 :
F_11 ( V_46 ) ) ;
break;
} else {
V_2 -> V_27 . V_45 [ V_25 ] . V_8 = V_5 ;
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 = 1 ;
}
}
V_44 [ 2 ] = 'L' ;
if ( ( V_21 & V_42 ) && V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ) {
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 ,
V_44 , NULL , & V_23 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_WARNING PREFIX
L_24 , i) ;
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 = 0 ;
}
else
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 = 1 ;
if ( memcmp ( & V_2 -> V_27 . V_45 [ V_25 ] . V_23 , & V_23 ,
sizeof( struct V_22 ) ) ) {
memcpy ( & V_2 -> V_27 . V_45 [ V_25 ] . V_23 , & V_23 ,
sizeof( struct V_22 ) ) ;
F_13 ( V_21 , L_22 ) ;
}
}
if ( ( V_21 & V_47 ) || ( V_21 & V_42 ) )
if ( V_24 != V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
F_13 ( V_21 , L_23 ) ;
if ( ! V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
break;
}
if ( V_21 & V_42 ) {
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_25 ,
NULL , & V_23 ) ;
if ( memcmp ( & V_2 -> V_23 , & V_23 ,
sizeof( struct V_22 ) ) ) {
memcpy ( & V_2 -> V_23 , & V_23 ,
sizeof( struct V_22 ) ) ;
F_13 ( V_21 , L_22 ) ;
}
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_25 , V_24 , V_48 = F_9 ( V_2 , V_36 ) ;
if ( V_48 )
return V_48 ;
V_24 = V_2 -> V_27 . V_28 . V_29 . V_24 |
V_2 -> V_27 . V_33 . V_29 . V_24 |
V_2 -> V_27 . V_35 . V_29 . V_24 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ )
V_24 |= V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ;
if ( ! V_24 ) {
F_10 (KERN_WARNING FW_BUG L_26 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_15 ( void * V_49 )
{
struct V_1 * V_2 = V_49 ;
F_16 ( V_2 -> V_50 ) ;
}
static int F_17 ( struct V_51 * V_52 ,
unsigned long * V_53 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
int V_55 ;
if ( ! V_2 )
return - V_6 ;
V_55 = F_1 ( V_2 ) ;
if ( V_55 )
return V_55 ;
* V_53 = F_18 ( V_2 -> V_8 , V_2 -> V_56 ) ;
return 0 ;
}
static int F_19 ( struct V_51 * V_52 ,
enum V_57 * V_14 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
if ( ! V_2 )
return - V_6 ;
* V_14 = V_2 -> V_58 ? V_59 :
V_60 ;
return 0 ;
}
static int F_20 ( struct V_51 * V_52 ,
enum V_57 V_14 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
int V_61 ;
if ( ! V_2 )
return - V_6 ;
if ( V_14 == V_59 )
V_61 = 1 ;
else if ( V_14 == V_60 )
V_61 = 0 ;
else
return - V_6 ;
if ( V_61 != V_2 -> V_58 ) {
V_2 -> V_58 = V_61 ;
F_4 ( ( V_12 ,
L_27 ,
V_2 -> V_58 ? L_28 : L_29 ) ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int F_21 ( struct V_51 * V_52 ,
int V_62 , enum V_63 * type )
{
struct V_1 * V_2 = V_52 -> V_54 ;
int V_25 ;
if ( ! V_2 || V_62 < 0 )
return - V_6 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 ) {
if ( ! V_62 ) {
* type = V_64 ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_33 . V_29 . V_24 ) {
if ( ! V_62 ) {
* type = V_65 ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_35 . V_29 . V_24 ) {
if ( ! V_62 ) {
* type = V_66 ;
return 0 ;
}
V_62 -- ;
}
for ( V_25 = 0 ; V_25 < V_43 &&
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ; V_25 ++ ) {
if ( ! V_62 ) {
* type = V_67 ;
return 0 ;
}
V_62 -- ;
}
return - V_6 ;
}
static int F_22 ( struct V_51 * V_52 ,
int V_62 , unsigned long * V_53 )
{
struct V_1 * V_2 = V_52 -> V_54 ;
int V_25 ;
if ( ! V_2 || V_62 < 0 )
return - V_6 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_53 = F_18 (
V_2 -> V_27 . V_28 . V_8 ,
V_2 -> V_56 ) ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_33 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_53 = F_18 (
V_2 -> V_27 . V_33 . V_8 ,
V_2 -> V_56 ) ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_35 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_53 = F_18 (
V_2 -> V_27 . V_35 . V_8 ,
V_2 -> V_56 ) ;
return 0 ;
}
V_62 -- ;
}
for ( V_25 = 0 ; V_25 < V_43 &&
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ; V_25 ++ ) {
if ( ! V_62 ) {
* V_53 = F_18 (
V_2 -> V_27 . V_45 [ V_25 ] . V_8 ,
V_2 -> V_56 ) ;
return 0 ;
}
V_62 -- ;
}
return - V_6 ;
}
static int F_23 ( struct V_51 * V_52 ,
unsigned long * V_8 ) {
struct V_1 * V_2 = V_52 -> V_54 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 ) {
* V_8 = F_18 (
V_2 -> V_27 . V_28 . V_8 ,
V_2 -> V_56 ) ;
return 0 ;
} else
return - V_6 ;
}
static int F_24 ( struct V_51 * V_52 , int V_62 ,
enum V_63 V_68 )
{
T_3 type = 0 ;
struct V_1 * V_2 = V_52 -> V_54 ;
if ( V_68 == V_64 )
type = V_69 ;
else if ( V_68 == V_65 )
type = V_70 ;
else
return 0 ;
F_25 ( V_2 -> V_9 , type , 1 ) ;
F_26 ( V_2 -> V_9 -> V_71 . V_72 ,
F_27 ( & V_2 -> V_9 -> V_73 ) , type , 1 ) ;
if ( V_68 == V_64 && V_74 )
return 1 ;
return 0 ;
}
static int F_28 ( struct V_51 * V_52 ,
struct V_75 * V_76 ,
T_4 V_77 )
{
struct V_78 * V_9 = V_76 -> V_54 ;
struct V_1 * V_2 = V_52 -> V_54 ;
struct V_78 * V_73 ;
T_1 V_3 ;
T_2 V_10 ;
int V_25 ;
int V_79 ;
int V_62 = - 1 ;
int V_55 = 0 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 )
V_62 ++ ;
if ( V_2 -> V_27 . V_33 . V_29 . V_24 )
V_62 ++ ;
if ( V_2 -> V_27 . V_35 . V_29 . V_24 ) {
V_62 ++ ;
for ( V_25 = 0 ; V_25 < V_2 -> V_27 . V_35 . V_23 . V_80 ;
V_25 ++ ) {
V_10 = V_2 -> V_27 . V_35 . V_23 . V_81 [ V_25 ] ;
V_3 = F_29 ( V_10 , & V_73 ) ;
if ( F_30 ( V_3 ) && ( V_73 == V_9 ) ) {
V_55 = V_77 ( V_52 , V_62 , V_76 ) ;
if ( V_55 )
goto V_82;
}
}
}
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
if ( ! V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
break;
V_62 ++ ;
for ( V_79 = 0 ;
V_79 < V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_80 ;
V_79 ++ ) {
V_10 = V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_81 [ V_79 ] ;
V_3 = F_29 ( V_10 , & V_73 ) ;
if ( F_30 ( V_3 ) && ( V_73 == V_9 ) ) {
V_55 = V_77 ( V_52 , V_62 , V_76 ) ;
if ( V_55 )
goto V_82;
}
}
}
for ( V_25 = 0 ; V_25 < V_2 -> V_23 . V_80 ; V_25 ++ ) {
V_10 = V_2 -> V_23 . V_81 [ V_25 ] ;
V_3 = F_29 ( V_10 , & V_73 ) ;
if ( F_30 ( V_3 ) && ( V_73 == V_9 ) ) {
V_55 = V_77 ( V_52 , - 1 , V_76 ) ;
if ( V_55 )
goto V_82;
}
}
V_82:
return V_55 ;
}
static int
F_31 ( struct V_51 * V_52 ,
struct V_75 * V_76 )
{
return F_28 ( V_52 , V_76 ,
V_83 ) ;
}
static int
F_32 ( struct V_51 * V_52 ,
struct V_75 * V_76 )
{
return F_28 ( V_52 , V_76 ,
V_84 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
int V_55 ;
T_1 V_3 ;
int V_25 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 )
V_27 ++ ;
if ( V_2 -> V_27 . V_33 . V_29 . V_24 )
V_27 ++ ;
if ( V_2 -> V_27 . V_35 . V_29 . V_24 )
V_27 ++ ;
for ( V_25 = 0 ; V_25 < V_43 &&
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ; V_25 ++ , V_27 ++ ) ;
if ( V_2 -> V_27 . V_35 . V_29 . V_24 )
V_2 -> V_50 =
F_34 ( L_30 , V_27 , 0 , V_2 ,
& V_85 ,
V_2 -> V_27 . V_35 . V_39 ,
V_2 -> V_27 . V_35 . V_40 ,
V_2 -> V_27 . V_35 . V_41 * 100 ,
V_2 -> V_13 * 100 ) ;
else
V_2 -> V_50 =
F_34 ( L_30 , V_27 , 0 , V_2 ,
& V_85 ,
0 , 0 , 0 ,
V_2 -> V_13 * 100 ) ;
if ( F_35 ( V_2 -> V_50 ) )
return - V_11 ;
V_55 = F_36 ( & V_2 -> V_9 -> V_73 . V_86 ,
& V_2 -> V_50 -> V_9 . V_86 , L_31 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_36 ( & V_2 -> V_50 -> V_9 . V_86 ,
& V_2 -> V_9 -> V_73 . V_86 , L_22 ) ;
if ( V_55 )
return V_55 ;
V_3 = F_37 ( V_2 -> V_9 -> V_10 ,
V_87 ,
V_2 -> V_50 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_ERR PREFIX
L_32 ) ;
return - V_11 ;
}
V_2 -> V_58 = 1 ;
F_38 ( & V_2 -> V_9 -> V_73 , L_33 ,
V_2 -> V_50 -> V_88 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( & V_2 -> V_9 -> V_73 . V_86 , L_31 ) ;
F_40 ( & V_2 -> V_50 -> V_9 . V_86 , L_22 ) ;
F_41 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
F_42 ( V_2 -> V_9 -> V_10 , V_87 ) ;
}
static void F_43 ( struct V_78 * V_9 , T_5 V_89 )
{
struct V_1 * V_2 = F_44 ( V_9 ) ;
if ( ! V_2 )
return;
switch ( V_89 ) {
case V_90 :
F_15 ( V_2 ) ;
break;
case V_91 :
F_9 ( V_2 , V_92 ) ;
F_15 ( V_2 ) ;
F_25 ( V_9 , V_89 , 0 ) ;
F_26 ( V_9 -> V_71 . V_72 ,
F_27 ( & V_9 -> V_73 ) , V_89 , 0 ) ;
break;
case V_93 :
F_9 ( V_2 , V_94 ) ;
F_15 ( V_2 ) ;
F_25 ( V_9 , V_89 , 0 ) ;
F_26 ( V_9 -> V_71 . V_72 ,
F_27 ( & V_9 -> V_73 ) , V_89 , 0 ) ;
break;
default:
F_4 ( ( V_12 ,
L_34 , V_89 ) ) ;
break;
}
}
static int F_45 ( struct V_1 * V_2 )
{
int V_55 = 0 ;
if ( ! V_2 )
return - V_6 ;
V_55 = F_14 ( V_2 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_1 ( V_2 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_6 ( V_2 , V_95 ) ;
if ( ! V_55 )
V_2 -> V_29 . V_96 = 1 ;
if ( V_97 )
V_2 -> V_13 = V_97 ;
else
F_5 ( V_2 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 . V_28 . V_29 . V_24 &&
( V_2 -> V_27 . V_28 . V_8 % 5 ) == 1 )
V_2 -> V_56 = 2731 ;
else
V_2 -> V_56 = 2732 ;
}
static int F_47 ( struct V_78 * V_9 )
{
int V_55 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_9 )
return - V_6 ;
V_2 = F_48 ( sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_44 , V_9 -> V_71 . V_100 ) ;
strcpy ( F_49 ( V_9 ) , V_101 ) ;
strcpy ( F_50 ( V_9 ) , V_102 ) ;
V_9 -> V_103 = V_2 ;
F_51 ( & V_2 -> V_104 ) ;
V_55 = F_45 ( V_2 ) ;
if ( V_55 )
goto V_105;
F_46 ( V_2 ) ;
V_55 = F_33 ( V_2 ) ;
if ( V_55 )
goto V_105;
F_10 (KERN_INFO PREFIX L_35 ,
acpi_device_name(device), acpi_device_bid(device),
KELVIN_TO_CELSIUS(tz->temperature)) ;
goto V_106;
V_105:
F_52 ( V_2 ) ;
V_106:
return V_55 ;
}
static int F_53 ( struct V_78 * V_9 , int type )
{
struct V_1 * V_2 = NULL ;
if ( ! V_9 || ! F_44 ( V_9 ) )
return - V_6 ;
V_2 = F_44 ( V_9 ) ;
F_39 ( V_2 ) ;
F_54 ( & V_2 -> V_104 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_9 * V_73 )
{
struct V_1 * V_2 ;
int V_25 , V_79 , V_107 , V_55 ;
if ( ! V_73 )
return - V_6 ;
V_2 = F_44 ( F_56 ( V_73 ) ) ;
if ( ! V_2 )
return - V_6 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
if ( ! ( & V_2 -> V_27 . V_45 [ V_25 ] ) )
break;
if ( ! V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
break;
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_108 = 1 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_80 ; V_79 ++ ) {
V_55 = F_57 (
V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_81 [ V_79 ] ,
& V_107 ) ;
if ( V_55 || ( V_107 != V_109 ) ) {
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_108 = 0 ;
break;
}
}
V_2 -> V_110 . V_45 |= V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_108 ;
}
F_15 ( V_2 ) ;
return V_4 ;
}
static int F_58 ( const struct V_111 * V_112 ) {
if ( V_46 == 0 ) {
F_10 ( V_113 L_36
L_37 , V_112 -> V_114 ) ;
V_46 = - 1 ;
}
return 0 ;
}
static int F_59 ( const struct V_111 * V_112 ) {
F_10 ( V_113 L_36
L_38 , V_112 -> V_114 ) ;
V_74 = 1 ;
return 0 ;
}
static int F_60 ( const struct V_111 * V_112 ) {
if ( V_97 == 0 ) {
F_10 ( V_113 L_36
L_39 , V_112 -> V_114 ) ;
V_97 = 300 ;
}
return 0 ;
}
static int F_61 ( const struct V_111 * V_112 ) {
if ( V_37 == 0 ) {
F_10 ( V_113 L_36
L_40 , V_112 -> V_114 ) ;
V_37 = - 1 ;
}
return 0 ;
}
static int T_6 F_62 ( void )
{
int V_55 = 0 ;
F_63 ( V_115 ) ;
if ( V_116 ) {
F_10 ( V_113 L_41 ) ;
return - V_11 ;
}
V_55 = F_64 ( & V_117 ) ;
if ( V_55 < 0 )
return - V_11 ;
return 0 ;
}
static void T_7 F_65 ( void )
{
F_66 ( & V_117 ) ;
return;
}
