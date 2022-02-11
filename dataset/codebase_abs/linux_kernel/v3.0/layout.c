static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
V_3 = V_4 ;
while ( V_3 -> V_5 [ 0 ] . V_6 ) {
if ( V_3 -> V_7 == V_2 )
return V_3 ;
V_3 ++ ;
}
return NULL ;
}
static struct V_1 * F_2 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
V_3 = V_4 ;
while ( V_3 -> V_5 [ 0 ] . V_6 ) {
if ( V_3 -> V_8 == V_2 )
return V_3 ;
V_3 ++ ;
}
return NULL ;
}
static void F_3 ( struct V_1 * V_3 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_3 -> V_5 [ V_9 ] . V_6 ) {
F_4 ( L_1 , V_3 -> V_5 [ V_9 ] . V_6 ) ;
}
}
}
static int F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
switch ( V_12 -> V_17 ) {
case 0 :
V_14 -> V_18 . integer . V_18 [ 0 ] = V_16 -> V_19 ;
break;
case 1 :
V_14 -> V_18 . integer . V_18 [ 0 ] = V_16 -> V_20 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
switch ( V_12 -> V_17 ) {
case 0 :
V_16 -> V_19 = ! ! V_14 -> V_18 . integer . V_18 [ 0 ] ;
break;
case 1 :
V_16 -> V_20 = ! ! V_14 -> V_18 . integer . V_18 [ 0 ] ;
break;
default:
return - V_21 ;
}
return 1 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( V_12 ) ;
int V_22 ;
switch ( V_12 -> V_17 ) {
case 0 :
V_22 = V_16 -> V_23 . V_24 -> V_25 ( & V_16 -> V_23 ,
V_26 ) ;
break;
case 1 :
V_22 = V_16 -> V_23 . V_24 -> V_25 ( & V_16 -> V_23 ,
V_27 ) ;
break;
default:
return - V_21 ;
}
V_14 -> V_18 . integer . V_18 [ 0 ] = V_22 ;
return 0 ;
}
static int F_9 ( struct V_28 * V_29 ,
struct V_15 * V_16 ,
struct V_30 * V_31 )
{
const T_1 * V_32 ;
char V_33 [ 32 ] ;
struct V_34 * V_35 ;
if ( V_29 -> V_36 && ( strcmp ( V_29 -> V_36 -> V_6 , L_2 ) == 0 ) ) {
snprintf ( V_33 , sizeof( V_33 ) ,
L_3 , V_29 -> V_6 ) ;
V_32 = F_10 ( V_16 -> V_37 , V_33 , NULL ) ;
if ( ! V_32 ) {
F_11 ( V_38 L_4
L_5 , V_33 ) ;
return - V_21 ;
}
if ( * V_32 != V_29 -> V_36 -> V_39 ) {
F_11 ( V_38 L_4
L_6 , V_33 ) ;
return - V_21 ;
}
} else {
if ( V_40 != 1 ) {
F_11 ( V_38 L_4
L_7 ) ;
return - V_21 ;
}
}
V_29 -> V_41 = V_16 -> V_42 ;
V_29 -> V_23 = & V_16 -> V_23 ;
V_35 = V_31 -> V_43 ;
if ( ! V_35 )
return - V_44 ;
F_11 ( V_38 L_8 ) ;
V_29 -> V_45 = 0 ;
V_29 -> V_46 = V_35 ;
while ( V_35 -> V_45 ) {
V_29 -> V_45 |= 1 << V_35 -> V_47 ;
V_35 ++ ;
}
return 0 ;
}
static int F_12 ( struct V_28 * V_29 )
{
struct V_15 * V_16 ;
int V_9 ;
F_13 (ldev, &layouts_list, list) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( ! V_16 -> V_1 -> V_5 [ V_9 ] . V_6 )
continue;
if ( strcmp ( V_16 -> V_1 -> V_5 [ V_9 ] . V_6 , V_29 -> V_6 ) == 0 ) {
if ( F_9 ( V_29 ,
V_16 ,
& V_16 -> V_1 -> V_5 [ V_9 ] ) == 0 )
return 0 ;
}
}
}
return - V_21 ;
}
static void F_14 ( struct V_28 * V_29 )
{
int V_9 ;
V_29 -> V_41 = NULL ;
V_29 -> V_23 = NULL ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
}
}
static void F_15 ( void * V_48 )
{
struct V_49 * V_50 = V_48 ;
struct V_15 * V_16 ;
int V_22 , V_51 ;
struct V_11 * V_52 , * V_53 ;
struct V_54 * V_55 = F_16 () ;
V_16 = V_50 -> V_56 ;
if ( V_48 == & V_16 -> V_57 ) {
V_22 = V_16 -> V_23 . V_24 -> V_25 ( & V_16 -> V_23 , V_26 ) ;
V_52 = V_16 -> V_58 ;
V_51 = V_16 -> V_19 ;
if ( V_51 ) {
V_16 -> V_23 . V_24 -> V_59 ( & V_16 -> V_23 , ! V_22 ) ;
V_16 -> V_23 . V_24 -> V_60 ( & V_16 -> V_23 , V_22 ) ;
V_16 -> V_23 . V_24 -> V_61 ( & V_16 -> V_23 , 0 ) ;
}
} else if ( V_48 == & V_16 -> V_62 ) {
V_22 = V_16 -> V_23 . V_24 -> V_25 ( & V_16 -> V_23 , V_27 ) ;
V_52 = V_16 -> V_63 ;
V_51 = V_16 -> V_20 ;
if ( V_51 ) {
V_16 -> V_23 . V_24 -> V_59 ( & V_16 -> V_23 , ! V_22 ) ;
V_16 -> V_23 . V_24 -> V_60 ( & V_16 -> V_23 , 0 ) ;
V_16 -> V_23 . V_24 -> V_61 ( & V_16 -> V_23 , V_22 ) ;
}
} else
return;
if ( V_52 )
F_17 ( V_55 , V_64 , & V_52 -> V_2 ) ;
if ( V_51 ) {
V_53 = V_16 -> V_65 ;
if ( V_53 )
F_17 ( V_55 , V_64 , & V_53 -> V_2 ) ;
V_53 = V_16 -> V_66 ;
if ( V_53 )
F_17 ( V_55 , V_64 , & V_53 -> V_2 ) ;
V_53 = V_16 -> V_67 ;
if ( V_53 )
F_17 ( V_55 , V_64 , & V_53 -> V_2 ) ;
}
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_34 * V_35 ;
struct V_11 * V_68 ;
int V_69 , V_70 ;
struct V_15 * V_16 = V_71 ;
V_35 = V_29 -> V_46 ;
V_69 = V_29 -> V_23 -> V_24 -> V_25 ( V_29 -> V_23 ,
V_26 ) ;
V_70 = V_29 -> V_23 -> V_24 -> V_25 ( V_29 -> V_23 ,
V_27 ) ;
if ( V_29 -> V_23 -> V_24 -> V_72 ) {
V_68 = F_19 ( & V_73 , V_29 -> V_23 ) ;
V_16 -> V_74 = V_68 ;
F_20 ( V_68 ) ;
}
while ( V_35 -> V_45 ) {
if ( V_35 -> V_45 & V_75 ) {
if ( V_69 <= 0 && V_70 <= 0 )
V_16 -> V_23 . V_24 -> V_59 ( V_29 -> V_23 , 1 ) ;
V_68 = F_19 ( & V_76 , V_29 -> V_23 ) ;
V_16 -> V_66 = V_68 ;
F_20 ( V_68 ) ;
}
if ( V_35 -> V_45 & V_77 ) {
if ( V_69 == 1 )
V_16 -> V_23 . V_24 -> V_60 ( V_29 -> V_23 , 1 ) ;
V_68 = F_19 ( & V_78 , V_29 -> V_23 ) ;
V_16 -> V_65 = V_68 ;
F_20 ( V_68 ) ;
V_16 -> V_79 =
! V_16 -> V_23 . V_24
-> V_80 ( & V_16 -> V_23 ,
V_26 ,
F_15 ,
& V_16 -> V_57 ) ;
if ( V_16 -> V_79 ) {
V_68 = F_19 ( & V_81 ,
V_16 ) ;
F_20 ( V_68 ) ;
V_68 = F_19 ( & V_82 ,
V_16 ) ;
V_16 -> V_58 = V_68 ;
F_20 ( V_68 ) ;
}
}
if ( V_35 -> V_45 & V_83 ) {
if ( V_70 == 1 )
V_16 -> V_23 . V_24 -> V_61 ( V_29 -> V_23 , 1 ) ;
V_68 = F_19 ( & V_84 , V_29 -> V_23 ) ;
if ( V_35 -> V_45 & V_85 )
F_21 ( V_68 -> V_2 . V_6 ,
L_9 , sizeof( V_68 -> V_2 . V_6 ) ) ;
V_16 -> V_67 = V_68 ;
F_20 ( V_68 ) ;
V_16 -> V_86 =
! V_16 -> V_23 . V_24
-> V_80 ( & V_16 -> V_23 ,
V_27 ,
F_15 ,
& V_16 -> V_62 ) ;
if ( V_16 -> V_86 ) {
V_68 = F_19 ( & V_87 ,
V_16 ) ;
if ( V_35 -> V_45 & V_85 )
F_21 ( V_68 -> V_2 . V_6 ,
L_10 ,
sizeof( V_68 -> V_2 . V_6 ) ) ;
F_20 ( V_68 ) ;
V_68 = F_19 ( & V_88 ,
V_16 ) ;
if ( V_35 -> V_45 & V_85 )
F_21 ( V_68 -> V_2 . V_6 ,
L_11 ,
sizeof( V_68 -> V_2 . V_6 ) ) ;
V_16 -> V_63 = V_68 ;
F_20 ( V_68 ) ;
}
}
V_35 ++ ;
}
if ( V_16 -> V_79 )
F_15 ( & V_16 -> V_57 ) ;
if ( V_16 -> V_86 )
F_15 ( & V_16 -> V_62 ) ;
}
static int F_22 ( struct V_41 * V_42 )
{
struct V_89 * V_37 = NULL ;
const unsigned int * V_2 ;
struct V_1 * V_1 = NULL ;
struct V_15 * V_16 = NULL ;
int V_90 ;
if ( V_71 )
return - V_21 ;
while ( ( V_37 = F_23 ( V_42 -> V_91 . V_92 . V_93 , V_37 ) ) ) {
if ( V_37 -> type && strcasecmp ( V_37 -> type , L_12 ) == 0 )
break;
}
if ( ! V_37 )
return - V_21 ;
V_2 = F_10 ( V_37 , L_13 , NULL ) ;
if ( V_2 ) {
V_1 = F_1 ( * V_2 ) ;
} else {
V_2 = F_10 ( V_37 , L_14 , NULL ) ;
if ( V_2 )
V_1 = F_2 ( * V_2 ) ;
}
if ( ! V_1 ) {
F_11 ( V_94 L_15 ) ;
goto V_95;
}
V_16 = F_24 ( sizeof( struct V_15 ) , V_96 ) ;
if ( ! V_16 )
goto V_95;
V_71 = V_16 ;
V_16 -> V_42 = V_42 ;
V_16 -> V_37 = V_37 ;
V_16 -> V_1 = V_1 ;
V_16 -> V_23 . V_36 = V_37 -> V_97 ;
switch ( V_1 -> V_7 ) {
case 0 :
case 41 :
case 51 :
case 58 :
V_16 -> V_23 . V_24 = V_98 ;
F_11 ( V_99
L_16 ) ;
break;
default:
V_16 -> V_23 . V_24 = V_100 ;
F_11 ( V_99
L_17 ) ;
}
V_16 -> V_57 . V_56 = V_16 ;
V_16 -> V_62 . V_56 = V_16 ;
F_25 ( & V_42 -> V_91 . V_92 , V_16 ) ;
F_26 ( & V_16 -> V_101 , & V_102 ) ;
V_40 ++ ;
V_42 -> V_103 = V_16 -> V_1 -> V_103 ;
if ( V_16 -> V_1 -> V_104 ) {
V_42 -> V_105 = V_16 -> V_1 -> V_104 ;
} else {
V_42 -> V_105 = L_18 ;
}
V_16 -> V_23 . V_24 -> V_106 ( & V_16 -> V_23 ) ;
V_90 = F_27 ( & V_107 , & V_42 -> V_91 . V_92 ) ;
if ( V_90 && V_90 != - V_108 ) {
F_11 ( V_38 L_19
L_20 ) ;
goto V_109;
}
F_3 ( V_1 ) ;
V_16 -> V_19 = 1 ;
V_16 -> V_20 = 1 ;
return 0 ;
V_109:
V_16 -> V_23 . V_24 -> exit ( & V_16 -> V_23 ) ;
V_42 -> V_105 = NULL ;
V_42 -> V_103 = - 1 ;
F_28 ( & V_16 -> V_101 ) ;
V_40 -- ;
V_95:
F_29 ( V_37 ) ;
V_71 = NULL ;
F_30 ( V_16 ) ;
return - V_21 ;
}
static int F_31 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = F_32 ( & V_42 -> V_91 . V_92 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
if ( V_16 -> V_5 [ V_9 ] ) {
F_33 ( V_16 -> V_5 [ V_9 ] ) ;
}
V_16 -> V_5 [ V_9 ] = NULL ;
}
F_28 ( & V_16 -> V_101 ) ;
V_40 -- ;
F_29 ( V_16 -> V_37 ) ;
V_16 -> V_23 . V_24 -> V_80 ( & V_16 -> V_23 ,
V_26 ,
NULL ,
NULL ) ;
V_16 -> V_23 . V_24 -> V_80 ( & V_16 -> V_23 ,
V_27 ,
NULL ,
NULL ) ;
V_16 -> V_23 . V_24 -> exit ( & V_16 -> V_23 ) ;
V_71 = NULL ;
F_30 ( V_16 ) ;
V_42 -> V_103 = - 1 ;
V_42 -> V_105 = NULL ;
return 0 ;
}
static int F_34 ( struct V_41 * V_42 , T_2 V_110 )
{
struct V_15 * V_16 = F_32 ( & V_42 -> V_91 . V_92 ) ;
if ( V_16 -> V_23 . V_24 && V_16 -> V_23 . V_24 -> V_111 )
V_16 -> V_23 . V_24 -> V_111 ( & V_16 -> V_23 ) ;
return 0 ;
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_15 * V_16 = F_32 ( & V_42 -> V_91 . V_92 ) ;
if ( V_16 -> V_23 . V_24 && V_16 -> V_23 . V_24 -> V_111 )
V_16 -> V_23 . V_24 -> V_112 ( & V_16 -> V_23 ) ;
return 0 ;
}
static int T_3 F_36 ( void )
{
int V_90 ;
V_90 = F_37 ( & V_113 ) ;
if ( V_90 )
return V_90 ;
return 0 ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_113 ) ;
F_40 ( & V_107 ) ;
}
