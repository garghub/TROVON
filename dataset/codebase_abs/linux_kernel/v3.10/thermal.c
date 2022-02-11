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
if ( ! V_2 -> V_50 ) {
F_16 ( L_27 ) ;
return;
}
F_17 ( V_2 -> V_51 ) ;
}
static int F_18 ( struct V_52 * V_53 ,
unsigned long * V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_56 ;
if ( ! V_2 )
return - V_6 ;
V_56 = F_1 ( V_2 ) ;
if ( V_56 )
return V_56 ;
* V_54 = F_19 ( V_2 -> V_8 , V_2 -> V_57 ) ;
return 0 ;
}
static int F_20 ( struct V_52 * V_53 ,
enum V_58 * V_14 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
if ( ! V_2 )
return - V_6 ;
* V_14 = V_2 -> V_50 ? V_59 :
V_60 ;
return 0 ;
}
static int F_21 ( struct V_52 * V_53 ,
enum V_58 V_14 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_61 ;
if ( ! V_2 )
return - V_6 ;
if ( V_14 == V_59 )
V_61 = 1 ;
else if ( V_14 == V_60 )
V_61 = 0 ;
else
return - V_6 ;
if ( V_61 != V_2 -> V_50 ) {
V_2 -> V_50 = V_61 ;
F_4 ( ( V_12 ,
L_28 ,
V_2 -> V_50 ? L_29 : L_30 ) ) ;
F_15 ( V_2 ) ;
}
return 0 ;
}
static int F_22 ( struct V_52 * V_53 ,
int V_62 , enum V_63 * type )
{
struct V_1 * V_2 = V_53 -> V_55 ;
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
static int F_23 ( struct V_52 * V_53 ,
int V_62 , unsigned long * V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
int V_25 ;
if ( ! V_2 || V_62 < 0 )
return - V_6 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_54 = F_19 (
V_2 -> V_27 . V_28 . V_8 ,
V_2 -> V_57 ) ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_33 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_54 = F_19 (
V_2 -> V_27 . V_33 . V_8 ,
V_2 -> V_57 ) ;
return 0 ;
}
V_62 -- ;
}
if ( V_2 -> V_27 . V_35 . V_29 . V_24 ) {
if ( ! V_62 ) {
* V_54 = F_19 (
V_2 -> V_27 . V_35 . V_8 ,
V_2 -> V_57 ) ;
return 0 ;
}
V_62 -- ;
}
for ( V_25 = 0 ; V_25 < V_43 &&
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 ; V_25 ++ ) {
if ( ! V_62 ) {
* V_54 = F_19 (
V_2 -> V_27 . V_45 [ V_25 ] . V_8 ,
V_2 -> V_57 ) ;
return 0 ;
}
V_62 -- ;
}
return - V_6 ;
}
static int F_24 ( struct V_52 * V_53 ,
unsigned long * V_8 ) {
struct V_1 * V_2 = V_53 -> V_55 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 ) {
* V_8 = F_19 (
V_2 -> V_27 . V_28 . V_8 ,
V_2 -> V_57 ) ;
return 0 ;
} else
return - V_6 ;
}
static int F_25 ( struct V_52 * V_53 ,
int V_62 , enum V_68 * V_69 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
enum V_63 type ;
int V_25 ;
if ( F_22 ( V_53 , V_62 , & type ) )
return - V_6 ;
if ( type == V_67 ) {
unsigned long V_70 ;
unsigned long V_54 = F_19 ( V_2 -> V_8 ,
V_2 -> V_57 ) ;
if ( F_23 ( V_53 , V_62 , & V_70 ) )
return - V_6 ;
if ( V_54 > V_70 ) {
* V_69 = V_71 ;
return 0 ;
} else {
return - V_6 ;
}
}
V_25 = ( V_2 -> V_27 . V_35 . V_39 * ( V_2 -> V_8 - V_2 -> V_7 ) )
+ ( V_2 -> V_27 . V_35 . V_40
* ( V_2 -> V_8 - V_2 -> V_27 . V_35 . V_8 ) ) ;
if ( V_25 > 0 )
* V_69 = V_71 ;
else if ( V_25 < 0 )
* V_69 = V_72 ;
else
* V_69 = V_73 ;
return 0 ;
}
static int F_26 ( struct V_52 * V_53 , int V_62 ,
enum V_63 V_74 )
{
T_3 type = 0 ;
struct V_1 * V_2 = V_53 -> V_55 ;
if ( V_74 == V_64 )
type = V_75 ;
else if ( V_74 == V_65 )
type = V_76 ;
else
return 0 ;
F_27 ( V_2 -> V_9 , type , 1 ) ;
F_28 ( V_2 -> V_9 -> V_77 . V_78 ,
F_29 ( & V_2 -> V_9 -> V_79 ) , type , 1 ) ;
if ( V_74 == V_64 && V_80 )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_81 * V_82 ,
bool V_83 )
{
struct V_84 * V_9 = V_82 -> V_55 ;
struct V_1 * V_2 = V_53 -> V_55 ;
struct V_84 * V_79 ;
T_1 V_3 ;
T_2 V_10 ;
int V_25 ;
int V_85 ;
int V_62 = - 1 ;
int V_56 = 0 ;
if ( V_2 -> V_27 . V_28 . V_29 . V_24 )
V_62 ++ ;
if ( V_2 -> V_27 . V_33 . V_29 . V_24 )
V_62 ++ ;
if ( V_2 -> V_27 . V_35 . V_29 . V_24 ) {
V_62 ++ ;
for ( V_25 = 0 ; V_25 < V_2 -> V_27 . V_35 . V_23 . V_86 ;
V_25 ++ ) {
V_10 = V_2 -> V_27 . V_35 . V_23 . V_87 [ V_25 ] ;
V_3 = F_31 ( V_10 , & V_79 ) ;
if ( F_3 ( V_3 ) || V_79 != V_9 )
continue;
if ( V_83 )
V_56 =
F_32
( V_53 , V_62 , V_82 ,
V_88 , V_88 ) ;
else
V_56 =
F_33
( V_53 , V_62 , V_82 ) ;
if ( V_56 )
goto V_89;
}
}
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
if ( ! V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
break;
V_62 ++ ;
for ( V_85 = 0 ;
V_85 < V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_86 ;
V_85 ++ ) {
V_10 = V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_87 [ V_85 ] ;
V_3 = F_31 ( V_10 , & V_79 ) ;
if ( F_3 ( V_3 ) || V_79 != V_9 )
continue;
if ( V_83 )
V_56 = F_32
( V_53 , V_62 , V_82 ,
V_88 , V_88 ) ;
else
V_56 = F_33
( V_53 , V_62 , V_82 ) ;
if ( V_56 )
goto V_89;
}
}
for ( V_25 = 0 ; V_25 < V_2 -> V_23 . V_86 ; V_25 ++ ) {
V_10 = V_2 -> V_23 . V_87 [ V_25 ] ;
V_3 = F_31 ( V_10 , & V_79 ) ;
if ( F_34 ( V_3 ) && ( V_79 == V_9 ) ) {
if ( V_83 )
V_56 = F_32
( V_53 , - 1 , V_82 ,
V_88 ,
V_88 ) ;
else
V_56 = F_33
( V_53 , - 1 , V_82 ) ;
if ( V_56 )
goto V_89;
}
}
V_89:
return V_56 ;
}
static int
F_35 ( struct V_52 * V_53 ,
struct V_81 * V_82 )
{
return F_30 ( V_53 , V_82 , true ) ;
}
static int
F_36 ( struct V_52 * V_53 ,
struct V_81 * V_82 )
{
return F_30 ( V_53 , V_82 , false ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_27 = 0 ;
int V_56 ;
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
V_2 -> V_51 =
F_38 ( L_31 , V_27 , 0 , V_2 ,
& V_90 , NULL ,
V_2 -> V_27 . V_35 . V_41 * 100 ,
V_2 -> V_13 * 100 ) ;
else
V_2 -> V_51 =
F_38 ( L_31 , V_27 , 0 , V_2 ,
& V_90 , NULL ,
0 , V_2 -> V_13 * 100 ) ;
if ( F_39 ( V_2 -> V_51 ) )
return - V_11 ;
V_56 = F_40 ( & V_2 -> V_9 -> V_79 . V_91 ,
& V_2 -> V_51 -> V_9 . V_91 , L_32 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_40 ( & V_2 -> V_51 -> V_9 . V_91 ,
& V_2 -> V_9 -> V_79 . V_91 , L_22 ) ;
if ( V_56 )
return V_56 ;
V_3 = F_41 ( V_2 -> V_9 -> V_10 ,
V_92 ,
V_2 -> V_51 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_ERR PREFIX
L_33 ) ;
return - V_11 ;
}
V_2 -> V_50 = 1 ;
F_42 ( & V_2 -> V_9 -> V_79 , L_34 ,
V_2 -> V_51 -> V_93 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_9 -> V_79 . V_91 , L_32 ) ;
F_44 ( & V_2 -> V_51 -> V_9 . V_91 , L_22 ) ;
F_45 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
F_46 ( V_2 -> V_9 -> V_10 , V_92 ) ;
}
static void F_47 ( struct V_84 * V_9 , T_4 V_94 )
{
struct V_1 * V_2 = F_48 ( V_9 ) ;
if ( ! V_2 )
return;
switch ( V_94 ) {
case V_95 :
F_15 ( V_2 ) ;
break;
case V_96 :
F_9 ( V_2 , V_97 ) ;
F_15 ( V_2 ) ;
F_27 ( V_9 , V_94 , 0 ) ;
F_28 ( V_9 -> V_77 . V_78 ,
F_29 ( & V_9 -> V_79 ) , V_94 , 0 ) ;
break;
case V_98 :
F_9 ( V_2 , V_99 ) ;
F_15 ( V_2 ) ;
F_27 ( V_9 , V_94 , 0 ) ;
F_28 ( V_9 -> V_77 . V_78 ,
F_29 ( & V_9 -> V_79 ) , V_94 , 0 ) ;
break;
default:
F_4 ( ( V_12 ,
L_35 , V_94 ) ) ;
break;
}
}
static void F_49 ( struct V_1 * V_2 )
{
T_2 V_10 = V_2 -> V_9 -> V_10 ;
unsigned long long V_20 ;
int V_25 ;
F_2 ( V_10 , L_7 , NULL , & V_20 ) ;
F_2 ( V_10 , L_13 , NULL , & V_20 ) ;
F_2 ( V_10 , L_16 , NULL , & V_20 ) ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
char V_44 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_25 ) , '\0' } ;
T_1 V_3 ;
V_3 = F_2 ( V_10 , V_44 , NULL , & V_20 ) ;
if ( V_3 == V_100 )
break;
}
F_2 ( V_10 , L_1 , NULL , & V_20 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_56 = 0 ;
if ( ! V_2 )
return - V_6 ;
F_49 ( V_2 ) ;
V_56 = F_14 ( V_2 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_1 ( V_2 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_6 ( V_2 , V_101 ) ;
if ( ! V_56 )
V_2 -> V_29 . V_102 = 1 ;
if ( V_103 )
V_2 -> V_13 = V_103 ;
else
F_5 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 . V_28 . V_29 . V_24 &&
( V_2 -> V_27 . V_28 . V_8 % 5 ) == 1 )
V_2 -> V_57 = 2731 ;
else
V_2 -> V_57 = 2732 ;
}
static int F_52 ( struct V_84 * V_9 )
{
int V_56 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_9 )
return - V_6 ;
V_2 = F_53 ( sizeof( struct V_1 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_44 , V_9 -> V_77 . V_106 ) ;
strcpy ( F_54 ( V_9 ) , V_107 ) ;
strcpy ( F_55 ( V_9 ) , V_108 ) ;
V_9 -> V_109 = V_2 ;
F_56 ( & V_2 -> V_110 ) ;
V_56 = F_50 ( V_2 ) ;
if ( V_56 )
goto V_111;
F_51 ( V_2 ) ;
V_56 = F_37 ( V_2 ) ;
if ( V_56 )
goto V_111;
F_10 (KERN_INFO PREFIX L_36 ,
acpi_device_name(device), acpi_device_bid(device),
KELVIN_TO_CELSIUS(tz->temperature)) ;
goto V_112;
V_111:
F_57 ( V_2 ) ;
V_112:
return V_56 ;
}
static int F_58 ( struct V_84 * V_9 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_9 || ! F_48 ( V_9 ) )
return - V_6 ;
V_2 = F_48 ( V_9 ) ;
F_43 ( V_2 ) ;
F_59 ( & V_2 -> V_110 ) ;
F_57 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_79 )
{
struct V_1 * V_2 ;
int V_25 , V_85 , V_113 , V_56 ;
if ( ! V_79 )
return - V_6 ;
V_2 = F_48 ( F_61 ( V_79 ) ) ;
if ( ! V_2 )
return - V_6 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ ) {
if ( ! ( & V_2 -> V_27 . V_45 [ V_25 ] ) )
break;
if ( ! V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_24 )
break;
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_114 = 1 ;
for ( V_85 = 0 ; V_85 < V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_86 ; V_85 ++ ) {
V_56 = F_62 (
V_2 -> V_27 . V_45 [ V_25 ] . V_23 . V_87 [ V_85 ] ,
& V_113 ) ;
if ( V_56 || ( V_113 != V_115 ) ) {
V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_114 = 0 ;
break;
}
}
V_2 -> V_116 . V_45 |= V_2 -> V_27 . V_45 [ V_25 ] . V_29 . V_114 ;
}
F_15 ( V_2 ) ;
return V_4 ;
}
static int F_63 ( const struct V_117 * V_118 ) {
if ( V_46 == 0 ) {
F_10 ( V_119 L_37
L_38 , V_118 -> V_120 ) ;
V_46 = - 1 ;
}
return 0 ;
}
static int F_64 ( const struct V_117 * V_118 ) {
F_10 ( V_119 L_37
L_39 , V_118 -> V_120 ) ;
V_80 = 1 ;
return 0 ;
}
static int F_65 ( const struct V_117 * V_118 ) {
if ( V_103 == 0 ) {
F_10 ( V_119 L_37
L_40 , V_118 -> V_120 ) ;
V_103 = 300 ;
}
return 0 ;
}
static int F_66 ( const struct V_117 * V_118 ) {
if ( V_37 == 0 ) {
F_10 ( V_119 L_37
L_41 , V_118 -> V_120 ) ;
V_37 = - 1 ;
}
return 0 ;
}
static int T_5 F_67 ( void )
{
int V_56 = 0 ;
F_68 ( V_121 ) ;
if ( V_122 ) {
F_10 ( V_119 L_42 ) ;
return - V_11 ;
}
V_56 = F_69 ( & V_123 ) ;
if ( V_56 < 0 )
return - V_11 ;
return 0 ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_123 ) ;
return;
}
