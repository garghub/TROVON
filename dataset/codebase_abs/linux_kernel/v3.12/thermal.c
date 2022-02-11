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
if ( ! V_2 )
return - V_6 ;
if ( ! F_7 ( V_2 -> V_9 -> V_10 , L_5 ) ) {
F_4 ( ( V_12 , L_6 ) ) ;
return - V_11 ;
} else if ( F_3 ( F_8 ( V_2 -> V_9 -> V_10 ,
L_5 , V_14 ) ) ) {
return - V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_15 )
{
T_1 V_3 = V_4 ;
unsigned long long V_5 ;
struct V_16 V_17 ;
int V_18 = 0 ;
int V_19 ;
if ( V_15 & V_20 ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_7 , NULL , & V_5 ) ;
V_2 -> V_21 . V_22 . V_8 = V_5 ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_21 . V_22 . V_23 . V_18 = 0 ;
F_4 ( ( V_12 ,
L_8 ) ) ;
} else if ( V_5 <= 2732 ) {
F_10 (KERN_WARNING FW_BUG L_9
L_10 , tmp) ;
V_2 -> V_21 . V_22 . V_23 . V_18 = 0 ;
} else {
V_2 -> V_21 . V_22 . V_23 . V_18 = 1 ;
F_4 ( ( V_12 ,
L_11 ,
V_2 -> V_21 . V_22 . V_8 ) ) ;
}
if ( V_2 -> V_21 . V_22 . V_23 . V_18 == 1 ) {
if ( V_24 == - 1 ) {
V_2 -> V_21 . V_22 . V_23 . V_18 = 0 ;
} else if ( V_24 > 0 ) {
unsigned long V_25 = F_11 ( V_24 ) ;
if ( V_25 > V_2 -> V_21 . V_22 . V_8 )
F_10 (KERN_WARNING PREFIX
L_12 , crt) ;
V_2 -> V_21 . V_22 . V_8 = V_25 ;
}
}
}
if ( V_15 & V_26 ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_13 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_21 . V_27 . V_23 . V_18 = 0 ;
F_4 ( ( V_12 ,
L_14 ) ) ;
} else {
V_2 -> V_21 . V_27 . V_8 = V_5 ;
V_2 -> V_21 . V_27 . V_23 . V_18 = 1 ;
F_4 ( ( V_12 ,
L_15 ,
V_2 -> V_21 . V_22 . V_8 ) ) ;
}
}
if ( ( ( V_15 & V_28 ) && V_2 -> V_21 . V_29 . V_23 . V_18 ) ||
( V_15 == V_30 ) ) {
V_18 = V_2 -> V_21 . V_29 . V_23 . V_18 ;
if ( V_31 == - 1 ) {
V_3 = V_32 ;
} else if ( V_31 > 0 ) {
V_5 = F_11 ( V_31 ) ;
V_3 = V_4 ;
} else {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_16 , NULL , & V_5 ) ;
}
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
else {
V_2 -> V_21 . V_29 . V_8 = V_5 ;
V_2 -> V_21 . V_29 . V_23 . V_18 = 1 ;
if ( V_15 == V_30 ) {
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_17 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_29 . V_33 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_18 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_29 . V_34 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_19 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_29 . V_35 = V_5 ;
}
}
}
if ( ( V_15 & V_36 ) && V_2 -> V_21 . V_29 . V_23 . V_18 ) {
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_20 ,
NULL , & V_17 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_WARNING PREFIX
L_21 ) ;
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
}
else
V_2 -> V_21 . V_29 . V_23 . V_18 = 1 ;
if ( memcmp ( & V_2 -> V_21 . V_29 . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ) {
memcpy ( & V_2 -> V_21 . V_29 . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ;
F_13 ( V_15 , L_22 ) ;
}
}
if ( ( V_15 & V_28 ) || ( V_15 & V_36 ) ) {
if ( V_18 != V_2 -> V_21 . V_29 . V_23 . V_18 )
F_13 ( V_15 , L_23 ) ;
}
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
char V_38 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_19 ) , '\0' } ;
V_18 = V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ;
if ( V_40 == - 1 )
break;
if ( ( V_15 == V_30 ) || ( ( V_15 & V_41 ) &&
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ) ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
V_38 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 = 0 ;
if ( V_19 == 0 )
break;
if ( V_40 <= 0 )
break;
if ( V_19 == 1 )
V_2 -> V_21 . V_39 [ 0 ] . V_8 =
F_11 ( V_40 ) ;
else
V_2 -> V_21 . V_39 [ V_19 - 1 ] . V_8 =
( V_2 -> V_21 . V_39 [ V_19 - 2 ] . V_8 <
F_11 ( V_40 ) ?
V_2 -> V_21 . V_39 [ V_19 - 2 ] . V_8 :
F_11 ( V_40 ) ) ;
break;
} else {
V_2 -> V_21 . V_39 [ V_19 ] . V_8 = V_5 ;
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 = 1 ;
}
}
V_38 [ 2 ] = 'L' ;
if ( ( V_15 & V_36 ) && V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ) {
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 ,
V_38 , NULL , & V_17 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_WARNING PREFIX
L_24 , i) ;
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 = 0 ;
}
else
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 = 1 ;
if ( memcmp ( & V_2 -> V_21 . V_39 [ V_19 ] . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ) {
memcpy ( & V_2 -> V_21 . V_39 [ V_19 ] . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ;
F_13 ( V_15 , L_22 ) ;
}
}
if ( ( V_15 & V_41 ) || ( V_15 & V_36 ) )
if ( V_18 != V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 )
F_13 ( V_15 , L_23 ) ;
if ( ! V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 )
break;
}
if ( ( V_15 & V_36 )
&& F_7 ( V_2 -> V_9 -> V_10 , L_25 ) ) {
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_25 ,
NULL , & V_17 ) ;
if ( F_14 ( V_3 )
&& memcmp ( & V_2 -> V_17 , & V_17 , sizeof( V_17 ) ) ) {
V_2 -> V_17 = V_17 ;
F_13 ( V_15 , L_22 ) ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_19 , V_18 , V_42 = F_9 ( V_2 , V_30 ) ;
if ( V_42 )
return V_42 ;
V_18 = V_2 -> V_21 . V_22 . V_23 . V_18 |
V_2 -> V_21 . V_27 . V_23 . V_18 |
V_2 -> V_21 . V_29 . V_23 . V_18 ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ )
V_18 |= V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ;
if ( ! V_18 ) {
F_10 (KERN_WARNING FW_BUG L_26 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_16 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
if ( ! V_2 -> V_44 ) {
F_17 ( L_27 ) ;
return;
}
F_18 ( V_2 -> V_45 ) ;
}
static int F_19 ( struct V_46 * V_47 ,
unsigned long * V_48 )
{
struct V_1 * V_2 = V_47 -> V_49 ;
int V_50 ;
if ( ! V_2 )
return - V_6 ;
V_50 = F_1 ( V_2 ) ;
if ( V_50 )
return V_50 ;
* V_48 = F_20 ( V_2 -> V_8 , V_2 -> V_51 ) ;
return 0 ;
}
static int F_21 ( struct V_46 * V_47 ,
enum V_52 * V_14 )
{
struct V_1 * V_2 = V_47 -> V_49 ;
if ( ! V_2 )
return - V_6 ;
* V_14 = V_2 -> V_44 ? V_53 :
V_54 ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
enum V_52 V_14 )
{
struct V_1 * V_2 = V_47 -> V_49 ;
int V_55 ;
if ( ! V_2 )
return - V_6 ;
if ( V_14 == V_53 )
V_55 = 1 ;
else if ( V_14 == V_54 )
V_55 = 0 ;
else
return - V_6 ;
if ( V_55 != V_2 -> V_44 ) {
V_2 -> V_44 = V_55 ;
F_4 ( ( V_12 ,
L_28 ,
V_2 -> V_44 ? L_29 : L_30 ) ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_23 ( struct V_46 * V_47 ,
int V_56 , enum V_57 * type )
{
struct V_1 * V_2 = V_47 -> V_49 ;
int V_19 ;
if ( ! V_2 || V_56 < 0 )
return - V_6 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
if ( ! V_56 ) {
* type = V_58 ;
return 0 ;
}
V_56 -- ;
}
if ( V_2 -> V_21 . V_27 . V_23 . V_18 ) {
if ( ! V_56 ) {
* type = V_59 ;
return 0 ;
}
V_56 -- ;
}
if ( V_2 -> V_21 . V_29 . V_23 . V_18 ) {
if ( ! V_56 ) {
* type = V_60 ;
return 0 ;
}
V_56 -- ;
}
for ( V_19 = 0 ; V_19 < V_37 &&
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ; V_19 ++ ) {
if ( ! V_56 ) {
* type = V_61 ;
return 0 ;
}
V_56 -- ;
}
return - V_6 ;
}
static int F_24 ( struct V_46 * V_47 ,
int V_56 , unsigned long * V_48 )
{
struct V_1 * V_2 = V_47 -> V_49 ;
int V_19 ;
if ( ! V_2 || V_56 < 0 )
return - V_6 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
if ( ! V_56 ) {
* V_48 = F_20 (
V_2 -> V_21 . V_22 . V_8 ,
V_2 -> V_51 ) ;
return 0 ;
}
V_56 -- ;
}
if ( V_2 -> V_21 . V_27 . V_23 . V_18 ) {
if ( ! V_56 ) {
* V_48 = F_20 (
V_2 -> V_21 . V_27 . V_8 ,
V_2 -> V_51 ) ;
return 0 ;
}
V_56 -- ;
}
if ( V_2 -> V_21 . V_29 . V_23 . V_18 ) {
if ( ! V_56 ) {
* V_48 = F_20 (
V_2 -> V_21 . V_29 . V_8 ,
V_2 -> V_51 ) ;
return 0 ;
}
V_56 -- ;
}
for ( V_19 = 0 ; V_19 < V_37 &&
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ; V_19 ++ ) {
if ( ! V_56 ) {
* V_48 = F_20 (
V_2 -> V_21 . V_39 [ V_19 ] . V_8 ,
V_2 -> V_51 ) ;
return 0 ;
}
V_56 -- ;
}
return - V_6 ;
}
static int F_25 ( struct V_46 * V_47 ,
unsigned long * V_8 ) {
struct V_1 * V_2 = V_47 -> V_49 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
* V_8 = F_20 (
V_2 -> V_21 . V_22 . V_8 ,
V_2 -> V_51 ) ;
return 0 ;
} else
return - V_6 ;
}
static int F_26 ( struct V_46 * V_47 ,
int V_56 , enum V_62 * V_63 )
{
struct V_1 * V_2 = V_47 -> V_49 ;
enum V_57 type ;
int V_19 ;
if ( F_23 ( V_47 , V_56 , & type ) )
return - V_6 ;
if ( type == V_61 ) {
unsigned long V_64 ;
unsigned long V_48 = F_20 ( V_2 -> V_8 ,
V_2 -> V_51 ) ;
if ( F_24 ( V_47 , V_56 , & V_64 ) )
return - V_6 ;
if ( V_48 > V_64 ) {
* V_63 = V_65 ;
return 0 ;
} else {
return - V_6 ;
}
}
V_19 = ( V_2 -> V_21 . V_29 . V_33 * ( V_2 -> V_8 - V_2 -> V_7 ) )
+ ( V_2 -> V_21 . V_29 . V_34
* ( V_2 -> V_8 - V_2 -> V_21 . V_29 . V_8 ) ) ;
if ( V_19 > 0 )
* V_63 = V_65 ;
else if ( V_19 < 0 )
* V_63 = V_66 ;
else
* V_63 = V_67 ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 , int V_56 ,
enum V_57 V_68 )
{
T_2 type = 0 ;
struct V_1 * V_2 = V_47 -> V_49 ;
if ( V_68 == V_58 )
type = V_69 ;
else if ( V_68 == V_59 )
type = V_70 ;
else
return 0 ;
F_28 ( V_2 -> V_9 -> V_71 . V_72 ,
F_29 ( & V_2 -> V_9 -> V_73 ) , type , 1 ) ;
if ( V_68 == V_58 && V_74 )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_46 * V_47 ,
struct V_75 * V_76 ,
bool V_77 )
{
struct V_78 * V_9 = V_76 -> V_49 ;
struct V_1 * V_2 = V_47 -> V_49 ;
struct V_78 * V_73 ;
T_1 V_3 ;
T_3 V_10 ;
int V_19 ;
int V_79 ;
int V_56 = - 1 ;
int V_50 = 0 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 )
V_56 ++ ;
if ( V_2 -> V_21 . V_27 . V_23 . V_18 )
V_56 ++ ;
if ( V_2 -> V_21 . V_29 . V_23 . V_18 ) {
V_56 ++ ;
for ( V_19 = 0 ; V_19 < V_2 -> V_21 . V_29 . V_17 . V_80 ;
V_19 ++ ) {
V_10 = V_2 -> V_21 . V_29 . V_17 . V_81 [ V_19 ] ;
V_3 = F_31 ( V_10 , & V_73 ) ;
if ( F_3 ( V_3 ) || V_73 != V_9 )
continue;
if ( V_77 )
V_50 =
F_32
( V_47 , V_56 , V_76 ,
V_82 , V_82 ) ;
else
V_50 =
F_33
( V_47 , V_56 , V_76 ) ;
if ( V_50 )
goto V_83;
}
}
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
if ( ! V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 )
break;
V_56 ++ ;
for ( V_79 = 0 ;
V_79 < V_2 -> V_21 . V_39 [ V_19 ] . V_17 . V_80 ;
V_79 ++ ) {
V_10 = V_2 -> V_21 . V_39 [ V_19 ] . V_17 . V_81 [ V_79 ] ;
V_3 = F_31 ( V_10 , & V_73 ) ;
if ( F_3 ( V_3 ) || V_73 != V_9 )
continue;
if ( V_77 )
V_50 = F_32
( V_47 , V_56 , V_76 ,
V_82 , V_82 ) ;
else
V_50 = F_33
( V_47 , V_56 , V_76 ) ;
if ( V_50 )
goto V_83;
}
}
for ( V_19 = 0 ; V_19 < V_2 -> V_17 . V_80 ; V_19 ++ ) {
V_10 = V_2 -> V_17 . V_81 [ V_19 ] ;
V_3 = F_31 ( V_10 , & V_73 ) ;
if ( F_14 ( V_3 ) && ( V_73 == V_9 ) ) {
if ( V_77 )
V_50 = F_32
( V_47 , V_84 ,
V_76 , V_82 ,
V_82 ) ;
else
V_50 = F_33
( V_47 , V_84 ,
V_76 ) ;
if ( V_50 )
goto V_83;
}
}
V_83:
return V_50 ;
}
static int
F_34 ( struct V_46 * V_47 ,
struct V_75 * V_76 )
{
return F_30 ( V_47 , V_76 , true ) ;
}
static int
F_35 ( struct V_46 * V_47 ,
struct V_75 * V_76 )
{
return F_30 ( V_47 , V_76 , false ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
int V_50 ;
T_1 V_3 ;
int V_19 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 )
V_21 ++ ;
if ( V_2 -> V_21 . V_27 . V_23 . V_18 )
V_21 ++ ;
if ( V_2 -> V_21 . V_29 . V_23 . V_18 )
V_21 ++ ;
for ( V_19 = 0 ; V_19 < V_37 &&
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 ; V_19 ++ , V_21 ++ ) ;
if ( V_2 -> V_21 . V_29 . V_23 . V_18 )
V_2 -> V_45 =
F_37 ( L_31 , V_21 , 0 , V_2 ,
& V_85 , NULL ,
V_2 -> V_21 . V_29 . V_35 * 100 ,
V_2 -> V_13 * 100 ) ;
else
V_2 -> V_45 =
F_37 ( L_31 , V_21 , 0 , V_2 ,
& V_85 , NULL ,
0 , V_2 -> V_13 * 100 ) ;
if ( F_38 ( V_2 -> V_45 ) )
return - V_11 ;
V_50 = F_39 ( & V_2 -> V_9 -> V_73 . V_86 ,
& V_2 -> V_45 -> V_9 . V_86 , L_32 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_39 ( & V_2 -> V_45 -> V_9 . V_86 ,
& V_2 -> V_9 -> V_73 . V_86 , L_22 ) ;
if ( V_50 )
return V_50 ;
V_3 = F_40 ( V_2 -> V_9 -> V_10 ,
V_87 ,
V_2 -> V_45 ) ;
if ( F_3 ( V_3 ) ) {
F_10 (KERN_ERR PREFIX
L_33 ) ;
return - V_11 ;
}
V_2 -> V_44 = 1 ;
F_41 ( & V_2 -> V_9 -> V_73 , L_34 ,
V_2 -> V_45 -> V_88 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_9 -> V_73 . V_86 , L_32 ) ;
F_43 ( & V_2 -> V_45 -> V_9 . V_86 , L_22 ) ;
F_44 ( V_2 -> V_45 ) ;
V_2 -> V_45 = NULL ;
F_45 ( V_2 -> V_9 -> V_10 , V_87 ) ;
}
static void F_46 ( struct V_78 * V_9 , T_4 V_89 )
{
struct V_1 * V_2 = F_47 ( V_9 ) ;
if ( ! V_2 )
return;
switch ( V_89 ) {
case V_90 :
F_16 ( V_2 ) ;
break;
case V_91 :
F_9 ( V_2 , V_92 ) ;
F_16 ( V_2 ) ;
F_28 ( V_9 -> V_71 . V_72 ,
F_29 ( & V_9 -> V_73 ) , V_89 , 0 ) ;
break;
case V_93 :
F_9 ( V_2 , V_94 ) ;
F_16 ( V_2 ) ;
F_28 ( V_9 -> V_71 . V_72 ,
F_29 ( & V_9 -> V_73 ) , V_89 , 0 ) ;
break;
default:
F_4 ( ( V_12 ,
L_35 , V_89 ) ) ;
break;
}
}
static void F_48 ( struct V_1 * V_2 )
{
T_3 V_10 = V_2 -> V_9 -> V_10 ;
unsigned long long V_95 ;
int V_19 ;
F_2 ( V_10 , L_7 , NULL , & V_95 ) ;
F_2 ( V_10 , L_13 , NULL , & V_95 ) ;
F_2 ( V_10 , L_16 , NULL , & V_95 ) ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
char V_38 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_19 ) , '\0' } ;
T_1 V_3 ;
V_3 = F_2 ( V_10 , V_38 , NULL , & V_95 ) ;
if ( V_3 == V_96 )
break;
}
F_2 ( V_10 , L_1 , NULL , & V_95 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_50 = 0 ;
if ( ! V_2 )
return - V_6 ;
F_48 ( V_2 ) ;
V_50 = F_15 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_1 ( V_2 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_6 ( V_2 , V_97 ) ;
if ( ! V_50 )
V_2 -> V_23 . V_98 = 1 ;
if ( V_99 )
V_2 -> V_13 = V_99 ;
else
F_5 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 . V_22 . V_23 . V_18 &&
( V_2 -> V_21 . V_22 . V_8 % 5 ) == 1 )
V_2 -> V_51 = 2731 ;
else
V_2 -> V_51 = 2732 ;
}
static int F_51 ( struct V_78 * V_9 )
{
int V_50 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_9 )
return - V_6 ;
V_2 = F_52 ( sizeof( struct V_1 ) , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_38 , V_9 -> V_71 . V_102 ) ;
strcpy ( F_53 ( V_9 ) , V_103 ) ;
strcpy ( F_54 ( V_9 ) , V_104 ) ;
V_9 -> V_105 = V_2 ;
V_50 = F_49 ( V_2 ) ;
if ( V_50 )
goto V_106;
F_50 ( V_2 ) ;
V_50 = F_36 ( V_2 ) ;
if ( V_50 )
goto V_106;
F_10 (KERN_INFO PREFIX L_36 ,
acpi_device_name(device), acpi_device_bid(device),
KELVIN_TO_CELSIUS(tz->temperature)) ;
goto V_107;
V_106:
F_55 ( V_2 ) ;
V_107:
return V_50 ;
}
static int F_56 ( struct V_78 * V_9 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_9 || ! F_47 ( V_9 ) )
return - V_6 ;
V_2 = F_47 ( V_9 ) ;
F_42 ( V_2 ) ;
F_55 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_9 * V_73 )
{
struct V_1 * V_2 ;
int V_19 , V_79 , V_108 , V_50 ;
if ( ! V_73 )
return - V_6 ;
V_2 = F_47 ( F_58 ( V_73 ) ) ;
if ( ! V_2 )
return - V_6 ;
for ( V_19 = 0 ; V_19 < V_37 ; V_19 ++ ) {
if ( ! ( & V_2 -> V_21 . V_39 [ V_19 ] ) )
break;
if ( ! V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_18 )
break;
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_109 = 1 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_21 . V_39 [ V_19 ] . V_17 . V_80 ; V_79 ++ ) {
V_50 = F_59 (
V_2 -> V_21 . V_39 [ V_19 ] . V_17 . V_81 [ V_79 ] ,
& V_108 ) ;
if ( V_50 || ( V_108 != V_110 ) ) {
V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_109 = 0 ;
break;
}
}
V_2 -> V_111 . V_39 |= V_2 -> V_21 . V_39 [ V_19 ] . V_23 . V_109 ;
}
F_16 ( V_2 ) ;
return V_4 ;
}
static int F_60 ( const struct V_112 * V_113 ) {
if ( V_40 == 0 ) {
F_10 ( V_114 L_37
L_38 , V_113 -> V_115 ) ;
V_40 = - 1 ;
}
return 0 ;
}
static int F_61 ( const struct V_112 * V_113 ) {
F_10 ( V_114 L_37
L_39 , V_113 -> V_115 ) ;
V_74 = 1 ;
return 0 ;
}
static int F_62 ( const struct V_112 * V_113 ) {
if ( V_99 == 0 ) {
F_10 ( V_114 L_37
L_40 , V_113 -> V_115 ) ;
V_99 = 300 ;
}
return 0 ;
}
static int F_63 ( const struct V_112 * V_113 ) {
if ( V_31 == 0 ) {
F_10 ( V_114 L_37
L_41 , V_113 -> V_115 ) ;
V_31 = - 1 ;
}
return 0 ;
}
static int T_5 F_64 ( void )
{
int V_50 = 0 ;
F_65 ( V_116 ) ;
if ( V_117 ) {
F_10 ( V_114 L_42 ) ;
return - V_11 ;
}
V_50 = F_66 ( & V_118 ) ;
if ( V_50 < 0 )
return - V_11 ;
return 0 ;
}
static void T_6 F_67 ( void )
{
F_68 ( & V_118 ) ;
return;
}
