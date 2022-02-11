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
F_10 ( V_24 L_9 ,
V_5 ) ;
V_2 -> V_21 . V_22 . V_23 . V_18 = 0 ;
} else {
V_2 -> V_21 . V_22 . V_23 . V_18 = 1 ;
F_4 ( ( V_12 ,
L_10 ,
V_2 -> V_21 . V_22 . V_8 ) ) ;
}
if ( V_2 -> V_21 . V_22 . V_23 . V_18 == 1 ) {
if ( V_25 == - 1 ) {
V_2 -> V_21 . V_22 . V_23 . V_18 = 0 ;
} else if ( V_25 > 0 ) {
unsigned long V_26 = F_11 ( V_25 ) ;
if ( V_26 > V_2 -> V_21 . V_22 . V_8 )
F_10 ( V_27 L_11 ,
V_25 ) ;
V_2 -> V_21 . V_22 . V_8 = V_26 ;
}
}
}
if ( V_15 & V_28 ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_12 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_21 . V_29 . V_23 . V_18 = 0 ;
F_4 ( ( V_12 ,
L_13 ) ) ;
} else {
V_2 -> V_21 . V_29 . V_8 = V_5 ;
V_2 -> V_21 . V_29 . V_23 . V_18 = 1 ;
F_4 ( ( V_12 ,
L_14 ,
V_2 -> V_21 . V_22 . V_8 ) ) ;
}
}
if ( ( ( V_15 & V_30 ) && V_2 -> V_21 . V_31 . V_23 . V_18 ) ||
( V_15 == V_32 ) ) {
V_18 = V_2 -> V_21 . V_31 . V_23 . V_18 ;
if ( V_33 == - 1 ) {
V_3 = V_34 ;
} else if ( V_33 > 0 ) {
V_5 = F_11 ( V_33 ) ;
V_3 = V_4 ;
} else {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
L_15 , NULL , & V_5 ) ;
}
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_31 . V_23 . V_18 = 0 ;
else {
V_2 -> V_21 . V_31 . V_8 = V_5 ;
V_2 -> V_21 . V_31 . V_23 . V_18 = 1 ;
if ( V_15 == V_32 ) {
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_16 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_31 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_31 . V_35 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_17 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_31 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_31 . V_36 = V_5 ;
V_3 = F_2 (
V_2 -> V_9 -> V_10 , L_18 ,
NULL , & V_5 ) ;
if ( F_3 ( V_3 ) )
V_2 -> V_21 . V_31 . V_23 . V_18 = 0 ;
else
V_2 -> V_21 . V_31 . V_37 = V_5 ;
}
}
}
if ( ( V_15 & V_38 ) && V_2 -> V_21 . V_31 . V_23 . V_18 ) {
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_19 ,
NULL , & V_17 ) ;
if ( F_3 ( V_3 ) ) {
F_10 ( V_27 L_20 ) ;
V_2 -> V_21 . V_31 . V_23 . V_18 = 0 ;
}
else
V_2 -> V_21 . V_31 . V_23 . V_18 = 1 ;
if ( memcmp ( & V_2 -> V_21 . V_31 . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ) {
memcpy ( & V_2 -> V_21 . V_31 . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ;
F_13 ( V_15 , L_21 ) ;
}
}
if ( ( V_15 & V_30 ) || ( V_15 & V_38 ) ) {
if ( V_18 != V_2 -> V_21 . V_31 . V_23 . V_18 )
F_13 ( V_15 , L_22 ) ;
}
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ ) {
char V_40 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_19 ) , '\0' } ;
V_18 = V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ;
if ( V_42 == - 1 )
break;
if ( ( V_15 == V_32 ) || ( ( V_15 & V_43 ) &&
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ) ) {
V_3 = F_2 ( V_2 -> V_9 -> V_10 ,
V_40 , NULL , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 = 0 ;
if ( V_19 == 0 )
break;
if ( V_42 <= 0 )
break;
if ( V_19 == 1 )
V_2 -> V_21 . V_41 [ 0 ] . V_8 =
F_11 ( V_42 ) ;
else
V_2 -> V_21 . V_41 [ V_19 - 1 ] . V_8 =
( V_2 -> V_21 . V_41 [ V_19 - 2 ] . V_8 <
F_11 ( V_42 ) ?
V_2 -> V_21 . V_41 [ V_19 - 2 ] . V_8 :
F_11 ( V_42 ) ) ;
break;
} else {
V_2 -> V_21 . V_41 [ V_19 ] . V_8 = V_5 ;
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 = 1 ;
}
}
V_40 [ 2 ] = 'L' ;
if ( ( V_15 & V_38 ) && V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ) {
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 ,
V_40 , NULL , & V_17 ) ;
if ( F_3 ( V_3 ) ) {
F_10 ( V_27 L_23 ,
V_19 ) ;
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 = 0 ;
}
else
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 = 1 ;
if ( memcmp ( & V_2 -> V_21 . V_41 [ V_19 ] . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ) {
memcpy ( & V_2 -> V_21 . V_41 [ V_19 ] . V_17 , & V_17 ,
sizeof( struct V_16 ) ) ;
F_13 ( V_15 , L_21 ) ;
}
}
if ( ( V_15 & V_43 ) || ( V_15 & V_38 ) )
if ( V_18 != V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 )
F_13 ( V_15 , L_22 ) ;
if ( ! V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 )
break;
}
if ( ( V_15 & V_38 )
&& F_7 ( V_2 -> V_9 -> V_10 , L_24 ) ) {
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_3 = F_12 ( V_2 -> V_9 -> V_10 , L_24 ,
NULL , & V_17 ) ;
if ( F_14 ( V_3 )
&& memcmp ( & V_2 -> V_17 , & V_17 , sizeof( V_17 ) ) ) {
V_2 -> V_17 = V_17 ;
F_13 ( V_15 , L_21 ) ;
}
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_19 , V_18 , V_44 = F_9 ( V_2 , V_32 ) ;
if ( V_44 )
return V_44 ;
V_18 = V_2 -> V_21 . V_22 . V_23 . V_18 |
V_2 -> V_21 . V_29 . V_23 . V_18 |
V_2 -> V_21 . V_31 . V_23 . V_18 ;
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ )
V_18 |= V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ;
if ( ! V_18 ) {
F_10 ( V_24 L_25 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_16 ( void * V_45 )
{
struct V_1 * V_2 = V_45 ;
if ( ! V_2 -> V_46 )
return;
F_17 ( V_2 -> V_47 ) ;
}
static int F_18 ( struct V_48 * V_49 ,
unsigned long * V_50 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
int V_52 ;
if ( ! V_2 )
return - V_6 ;
V_52 = F_1 ( V_2 ) ;
if ( V_52 )
return V_52 ;
* V_50 = F_19 ( V_2 -> V_8 , V_2 -> V_53 ) ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 ,
enum V_54 * V_14 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
if ( ! V_2 )
return - V_6 ;
* V_14 = V_2 -> V_46 ? V_55 :
V_56 ;
return 0 ;
}
static int F_21 ( struct V_48 * V_49 ,
enum V_54 V_14 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
int V_57 ;
if ( ! V_2 )
return - V_6 ;
if ( V_14 == V_55 )
V_57 = 1 ;
else if ( V_14 == V_56 ) {
V_57 = 0 ;
F_10 ( L_26 ) ;
} else
return - V_6 ;
if ( V_57 != V_2 -> V_46 ) {
V_2 -> V_46 = V_57 ;
F_4 ( ( V_12 ,
L_27 ,
V_2 -> V_46 ? L_28 : L_29 ) ) ;
F_16 ( V_2 ) ;
}
return 0 ;
}
static int F_22 ( struct V_48 * V_49 ,
int V_58 , enum V_59 * type )
{
struct V_1 * V_2 = V_49 -> V_51 ;
int V_19 ;
if ( ! V_2 || V_58 < 0 )
return - V_6 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
if ( ! V_58 ) {
* type = V_60 ;
return 0 ;
}
V_58 -- ;
}
if ( V_2 -> V_21 . V_29 . V_23 . V_18 ) {
if ( ! V_58 ) {
* type = V_61 ;
return 0 ;
}
V_58 -- ;
}
if ( V_2 -> V_21 . V_31 . V_23 . V_18 ) {
if ( ! V_58 ) {
* type = V_62 ;
return 0 ;
}
V_58 -- ;
}
for ( V_19 = 0 ; V_19 < V_39 &&
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ; V_19 ++ ) {
if ( ! V_58 ) {
* type = V_63 ;
return 0 ;
}
V_58 -- ;
}
return - V_6 ;
}
static int F_23 ( struct V_48 * V_49 ,
int V_58 , unsigned long * V_50 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
int V_19 ;
if ( ! V_2 || V_58 < 0 )
return - V_6 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
if ( ! V_58 ) {
* V_50 = F_19 (
V_2 -> V_21 . V_22 . V_8 ,
V_2 -> V_53 ) ;
return 0 ;
}
V_58 -- ;
}
if ( V_2 -> V_21 . V_29 . V_23 . V_18 ) {
if ( ! V_58 ) {
* V_50 = F_19 (
V_2 -> V_21 . V_29 . V_8 ,
V_2 -> V_53 ) ;
return 0 ;
}
V_58 -- ;
}
if ( V_2 -> V_21 . V_31 . V_23 . V_18 ) {
if ( ! V_58 ) {
* V_50 = F_19 (
V_2 -> V_21 . V_31 . V_8 ,
V_2 -> V_53 ) ;
return 0 ;
}
V_58 -- ;
}
for ( V_19 = 0 ; V_19 < V_39 &&
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ; V_19 ++ ) {
if ( ! V_58 ) {
* V_50 = F_19 (
V_2 -> V_21 . V_41 [ V_19 ] . V_8 ,
V_2 -> V_53 ) ;
return 0 ;
}
V_58 -- ;
}
return - V_6 ;
}
static int F_24 ( struct V_48 * V_49 ,
unsigned long * V_8 ) {
struct V_1 * V_2 = V_49 -> V_51 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 ) {
* V_8 = F_19 (
V_2 -> V_21 . V_22 . V_8 ,
V_2 -> V_53 ) ;
return 0 ;
} else
return - V_6 ;
}
static int F_25 ( struct V_48 * V_49 ,
int V_58 , enum V_64 * V_65 )
{
struct V_1 * V_2 = V_49 -> V_51 ;
enum V_59 type ;
int V_19 ;
if ( F_22 ( V_49 , V_58 , & type ) )
return - V_6 ;
if ( type == V_63 ) {
unsigned long V_66 ;
unsigned long V_50 = F_19 ( V_2 -> V_8 ,
V_2 -> V_53 ) ;
if ( F_23 ( V_49 , V_58 , & V_66 ) )
return - V_6 ;
if ( V_50 > V_66 ) {
* V_65 = V_67 ;
return 0 ;
} else {
return - V_6 ;
}
}
V_19 = ( V_2 -> V_21 . V_31 . V_35 * ( V_2 -> V_8 - V_2 -> V_7 ) )
+ ( V_2 -> V_21 . V_31 . V_36
* ( V_2 -> V_8 - V_2 -> V_21 . V_31 . V_8 ) ) ;
if ( V_19 > 0 )
* V_65 = V_67 ;
else if ( V_19 < 0 )
* V_65 = V_68 ;
else
* V_65 = V_69 ;
return 0 ;
}
static int F_26 ( struct V_48 * V_49 , int V_58 ,
enum V_59 V_70 )
{
T_2 type = 0 ;
struct V_1 * V_2 = V_49 -> V_51 ;
if ( V_70 == V_60 )
type = V_71 ;
else if ( V_70 == V_61 )
type = V_72 ;
else
return 0 ;
F_27 ( V_2 -> V_9 -> V_73 . V_74 ,
F_28 ( & V_2 -> V_9 -> V_75 ) , type , 1 ) ;
if ( V_70 == V_60 && V_76 )
return 1 ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 ,
struct V_77 * V_78 ,
bool V_79 )
{
struct V_80 * V_9 = V_78 -> V_51 ;
struct V_1 * V_2 = V_49 -> V_51 ;
struct V_80 * V_75 ;
T_1 V_3 ;
T_3 V_10 ;
int V_19 ;
int V_81 ;
int V_58 = - 1 ;
int V_52 = 0 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 )
V_58 ++ ;
if ( V_2 -> V_21 . V_29 . V_23 . V_18 )
V_58 ++ ;
if ( V_2 -> V_21 . V_31 . V_23 . V_18 ) {
V_58 ++ ;
for ( V_19 = 0 ; V_19 < V_2 -> V_21 . V_31 . V_17 . V_82 ;
V_19 ++ ) {
V_10 = V_2 -> V_21 . V_31 . V_17 . V_83 [ V_19 ] ;
V_3 = F_30 ( V_10 , & V_75 ) ;
if ( F_3 ( V_3 ) || V_75 != V_9 )
continue;
if ( V_79 )
V_52 =
F_31
( V_49 , V_58 , V_78 ,
V_84 , V_84 ) ;
else
V_52 =
F_32
( V_49 , V_58 , V_78 ) ;
if ( V_52 )
goto V_85;
}
}
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ ) {
if ( ! V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 )
break;
V_58 ++ ;
for ( V_81 = 0 ;
V_81 < V_2 -> V_21 . V_41 [ V_19 ] . V_17 . V_82 ;
V_81 ++ ) {
V_10 = V_2 -> V_21 . V_41 [ V_19 ] . V_17 . V_83 [ V_81 ] ;
V_3 = F_30 ( V_10 , & V_75 ) ;
if ( F_3 ( V_3 ) || V_75 != V_9 )
continue;
if ( V_79 )
V_52 = F_31
( V_49 , V_58 , V_78 ,
V_84 , V_84 ) ;
else
V_52 = F_32
( V_49 , V_58 , V_78 ) ;
if ( V_52 )
goto V_85;
}
}
for ( V_19 = 0 ; V_19 < V_2 -> V_17 . V_82 ; V_19 ++ ) {
V_10 = V_2 -> V_17 . V_83 [ V_19 ] ;
V_3 = F_30 ( V_10 , & V_75 ) ;
if ( F_14 ( V_3 ) && ( V_75 == V_9 ) ) {
if ( V_79 )
V_52 = F_31
( V_49 , V_86 ,
V_78 , V_84 ,
V_84 ) ;
else
V_52 = F_32
( V_49 , V_86 ,
V_78 ) ;
if ( V_52 )
goto V_85;
}
}
V_85:
return V_52 ;
}
static int
F_33 ( struct V_48 * V_49 ,
struct V_77 * V_78 )
{
return F_29 ( V_49 , V_78 , true ) ;
}
static int
F_34 ( struct V_48 * V_49 ,
struct V_77 * V_78 )
{
return F_29 ( V_49 , V_78 , false ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
int V_52 ;
T_1 V_3 ;
int V_19 ;
if ( V_2 -> V_21 . V_22 . V_23 . V_18 )
V_21 ++ ;
if ( V_2 -> V_21 . V_29 . V_23 . V_18 )
V_21 ++ ;
if ( V_2 -> V_21 . V_31 . V_23 . V_18 )
V_21 ++ ;
for ( V_19 = 0 ; V_19 < V_39 &&
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 ; V_19 ++ , V_21 ++ ) ;
if ( V_2 -> V_21 . V_31 . V_23 . V_18 )
V_2 -> V_47 =
F_36 ( L_30 , V_21 , 0 , V_2 ,
& V_87 , NULL ,
V_2 -> V_21 . V_31 . V_37 * 100 ,
V_2 -> V_13 * 100 ) ;
else
V_2 -> V_47 =
F_36 ( L_30 , V_21 , 0 , V_2 ,
& V_87 , NULL ,
0 , V_2 -> V_13 * 100 ) ;
if ( F_37 ( V_2 -> V_47 ) )
return - V_11 ;
V_52 = F_38 ( & V_2 -> V_9 -> V_75 . V_88 ,
& V_2 -> V_47 -> V_9 . V_88 , L_31 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_38 ( & V_2 -> V_47 -> V_9 . V_88 ,
& V_2 -> V_9 -> V_75 . V_88 , L_21 ) ;
if ( V_52 )
return V_52 ;
V_3 = F_39 ( V_2 -> V_9 -> V_10 ,
V_89 ,
V_2 -> V_47 ) ;
if ( F_3 ( V_3 ) ) {
F_40 ( V_27 L_32 ) ;
return - V_11 ;
}
V_2 -> V_46 = 1 ;
F_41 ( & V_2 -> V_9 -> V_75 , L_33 ,
V_2 -> V_47 -> V_90 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_9 -> V_75 . V_88 , L_31 ) ;
F_43 ( & V_2 -> V_47 -> V_9 . V_88 , L_21 ) ;
F_44 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
F_45 ( V_2 -> V_9 -> V_10 , V_89 ) ;
}
static void F_46 ( struct V_80 * V_9 , T_4 V_91 )
{
struct V_1 * V_2 = F_47 ( V_9 ) ;
if ( ! V_2 )
return;
switch ( V_91 ) {
case V_92 :
F_16 ( V_2 ) ;
break;
case V_93 :
F_9 ( V_2 , V_94 ) ;
F_16 ( V_2 ) ;
F_27 ( V_9 -> V_73 . V_74 ,
F_28 ( & V_9 -> V_75 ) , V_91 , 0 ) ;
break;
case V_95 :
F_9 ( V_2 , V_96 ) ;
F_16 ( V_2 ) ;
F_27 ( V_9 -> V_73 . V_74 ,
F_28 ( & V_9 -> V_75 ) , V_91 , 0 ) ;
break;
default:
F_4 ( ( V_12 ,
L_34 , V_91 ) ) ;
break;
}
}
static void F_48 ( struct V_1 * V_2 )
{
T_3 V_10 = V_2 -> V_9 -> V_10 ;
unsigned long long V_97 ;
int V_19 ;
F_2 ( V_10 , L_7 , NULL , & V_97 ) ;
F_2 ( V_10 , L_12 , NULL , & V_97 ) ;
F_2 ( V_10 , L_15 , NULL , & V_97 ) ;
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ ) {
char V_40 [ 5 ] = { '_' , 'A' , 'C' , ( '0' + V_19 ) , '\0' } ;
T_1 V_3 ;
V_3 = F_2 ( V_10 , V_40 , NULL , & V_97 ) ;
if ( V_3 == V_98 )
break;
}
F_2 ( V_10 , L_1 , NULL , & V_97 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_52 = 0 ;
if ( ! V_2 )
return - V_6 ;
F_48 ( V_2 ) ;
V_52 = F_15 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_1 ( V_2 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_6 ( V_2 , V_99 ) ;
if ( ! V_52 )
V_2 -> V_23 . V_100 = 1 ;
if ( V_101 )
V_2 -> V_13 = V_101 ;
else
F_5 ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 . V_22 . V_23 . V_18 &&
( V_2 -> V_21 . V_22 . V_8 % 5 ) == 1 )
V_2 -> V_53 = 2731 ;
else
V_2 -> V_53 = 2732 ;
}
static int F_51 ( struct V_80 * V_9 )
{
int V_52 = 0 ;
struct V_1 * V_2 = NULL ;
if ( ! V_9 )
return - V_6 ;
V_2 = F_52 ( sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_9 = V_9 ;
strcpy ( V_2 -> V_40 , V_9 -> V_73 . V_104 ) ;
strcpy ( F_53 ( V_9 ) , V_105 ) ;
strcpy ( F_54 ( V_9 ) , V_106 ) ;
V_9 -> V_107 = V_2 ;
V_52 = F_49 ( V_2 ) ;
if ( V_52 )
goto V_108;
F_50 ( V_2 ) ;
V_52 = F_35 ( V_2 ) ;
if ( V_52 )
goto V_108;
F_55 ( V_27 L_35 , F_53 ( V_9 ) ,
F_56 ( V_9 ) , F_57 ( V_2 -> V_8 ) ) ;
goto V_109;
V_108:
F_58 ( V_2 ) ;
V_109:
return V_52 ;
}
static int F_59 ( struct V_80 * V_9 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_9 || ! F_47 ( V_9 ) )
return - V_6 ;
V_2 = F_47 ( V_9 ) ;
F_42 ( V_2 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_9 * V_75 )
{
struct V_1 * V_2 ;
int V_19 , V_81 , V_110 , V_52 ;
if ( ! V_75 )
return - V_6 ;
V_2 = F_47 ( F_61 ( V_75 ) ) ;
if ( ! V_2 )
return - V_6 ;
for ( V_19 = 0 ; V_19 < V_39 ; V_19 ++ ) {
if ( ! ( & V_2 -> V_21 . V_41 [ V_19 ] ) )
break;
if ( ! V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_18 )
break;
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_111 = 1 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_21 . V_41 [ V_19 ] . V_17 . V_82 ; V_81 ++ ) {
V_52 = F_62 (
V_2 -> V_21 . V_41 [ V_19 ] . V_17 . V_83 [ V_81 ] ,
& V_110 ) ;
if ( V_52 || ( V_110 != V_112 ) ) {
V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_111 = 0 ;
break;
}
}
V_2 -> V_113 . V_41 |= V_2 -> V_21 . V_41 [ V_19 ] . V_23 . V_111 ;
}
F_16 ( V_2 ) ;
return V_4 ;
}
static int F_63 ( const struct V_114 * V_115 ) {
if ( V_42 == 0 ) {
F_64 ( V_27 L_36
L_37 , V_115 -> V_116 ) ;
V_42 = - 1 ;
}
return 0 ;
}
static int F_65 ( const struct V_114 * V_115 ) {
F_64 ( V_27 L_36
L_38 , V_115 -> V_116 ) ;
V_76 = 1 ;
return 0 ;
}
static int F_66 ( const struct V_114 * V_115 ) {
if ( V_101 == 0 ) {
F_64 ( V_27 L_36
L_39 , V_115 -> V_116 ) ;
V_101 = 300 ;
}
return 0 ;
}
static int F_67 ( const struct V_114 * V_115 ) {
if ( V_33 == 0 ) {
F_64 ( V_27 L_36
L_40 , V_115 -> V_116 ) ;
V_33 = - 1 ;
}
return 0 ;
}
static int T_5 F_68 ( void )
{
int V_52 = 0 ;
F_69 ( V_117 ) ;
if ( V_118 ) {
F_64 ( V_27 L_41 ) ;
return - V_11 ;
}
V_52 = F_70 ( & V_119 ) ;
if ( V_52 < 0 )
return - V_11 ;
return 0 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_119 ) ;
return;
}
