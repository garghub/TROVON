static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_1 -> V_7 == - V_8 ) {
F_2 ( L_1 ,
V_1 -> V_7 , V_1 -> V_9 ) ;
return;
}
if ( ( V_1 -> V_9 > 0 ) && ( V_1 -> V_7 == 0 ) ) {
struct V_10 * V_11 = (struct V_10 * ) V_3 -> V_12 -> V_13 ;
F_3 ( V_11 ) ;
if ( V_1 -> V_9 >= V_11 -> V_14 ) {
V_3 -> V_12 -> V_15 = V_11 -> V_14 ;
if ( V_6 -> V_16 &&
( V_11 -> V_17 & V_18 ) ) {
V_3 -> V_12 -> V_19 =
V_6 -> V_16 +
( ( V_11 -> V_17 >> 8 ) & 3 ) ;
if ( ( ( int ) V_11 -> V_14 +
V_3 -> V_12 -> V_19 ) > V_1 -> V_9 ) {
F_2 ( L_2
L_3
L_4 ,
V_11 -> V_14 ,
V_3 -> V_12 -> V_19 ,
V_1 -> V_9 ) ;
goto V_20;
}
memcpy ( ( char * ) V_11 + V_3 -> V_12 -> V_19 ,
V_11 , sizeof( struct V_10 ) ) ;
} else
V_3 -> V_12 -> V_19 = 0 ;
F_4 ( L_5 ,
F_5 ( V_11 -> V_21 ) ,
V_11 -> V_21 , V_11 -> V_14 ) ;
F_6 ( (struct V_22 * ) V_11 ) ;
F_7 ( V_6 -> V_23 , V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
} else {
F_2 ( L_2
L_6 ,
V_11 -> V_14 , V_1 -> V_9 ) ;
}
} else
F_2 ( L_7 ,
V_1 -> V_7 , V_1 -> V_9 ) ;
V_20:
F_8 ( V_6 , V_3 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
if ( ! V_3 -> V_12 ) {
V_3 -> V_12 = F_9 ( V_6 -> V_23 ) ;
if ( ! V_3 -> V_12 ) {
F_2 ( L_8 ) ;
return - V_24 ;
}
}
F_10 (
& V_3 -> V_1 ,
V_6 -> V_25 ,
F_11 ( V_6 -> V_25 , V_6 -> V_26 ) ,
V_3 -> V_12 -> V_13 ,
V_6 -> V_27 ,
F_1 ,
V_3
) ;
V_3 -> V_1 . V_28 = V_3 -> V_12 -> V_29 ;
V_3 -> V_1 . V_30 |= V_31 ;
return F_12 ( & V_3 -> V_1 , V_32 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
F_14 ( & V_6 -> V_35 [ V_33 ] . V_1 ) ;
if ( V_6 -> V_35 [ V_33 ] . V_12 ) {
F_15 ( V_6 -> V_23 , V_6 -> V_35 [ V_33 ] . V_12 ) ;
V_6 -> V_35 [ V_33 ] . V_12 = NULL ;
}
}
}
static int F_16 ( struct V_5 * V_6 )
{
int V_33 , V_36 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_36 = F_8 ( V_6 , & V_6 -> V_35 [ V_33 ] ) ;
if ( V_36 < 0 ) {
F_2 ( L_9 ) ;
F_13 ( V_6 ) ;
break;
}
}
return V_36 ;
}
static int F_17 ( void * V_4 , void * V_37 , T_1 V_15 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
struct V_10 * V_11 = (struct V_10 * ) V_37 ;
int V_38 ;
if ( V_6 -> V_39 != V_40 )
return - V_41 ;
F_4 ( L_10 ,
F_5 ( V_11 -> V_21 ) , V_11 -> V_21 ,
V_11 -> V_14 ) ;
F_18 ( (struct V_22 * ) V_11 ) ;
F_3 ( (struct V_10 * ) V_37 ) ;
return F_19 ( V_6 -> V_25 , F_20 ( V_6 -> V_25 , 2 ) ,
V_37 , V_15 , & V_38 , 1000 ) ;
}
static inline char * F_21 ( int V_42 , int V_43 )
{
char * * V_44 = F_22 ( V_43 ) -> V_44 ;
return ( V_44 && V_44 [ V_42 ] ) ? V_44 [ V_42 ] : V_45 [ V_42 ] ;
}
static int F_23 ( struct V_46 * V_25 , int V_47 , int V_43 )
{
const struct V_48 * V_44 ;
T_2 * V_49 ;
int V_36 , V_38 ;
char * V_50 ;
if ( V_47 < V_51 || V_47 > V_52 ) {
F_2 ( L_11 , V_47 ) ;
return - V_53 ;
}
V_50 = F_21 ( V_47 , V_43 ) ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_12
L_13 , V_50 , V_47 ) ;
V_50 = V_45 [ V_47 ] ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_14 ,
V_50 , V_47 ) ;
return V_36 ;
}
}
V_49 = F_26 ( V_44 -> V_15 , V_54 ) ;
if ( V_49 ) {
memcpy ( V_49 , V_44 -> V_55 , V_44 -> V_15 ) ;
V_36 = F_19 ( V_25 , F_20 ( V_25 , 2 ) ,
V_49 , V_44 -> V_15 , & V_38 , 1000 ) ;
F_27 ( L_15 , V_44 -> V_15 , V_38 , V_36 ) ;
F_28 ( V_49 ) ;
} else {
F_2 ( L_16 ) ;
V_36 = - V_24 ;
}
F_27 ( L_17 , V_50 , V_44 -> V_15 ) ;
F_29 ( V_44 ) ;
return V_36 ;
}
static void F_30 ( void * V_4 , int * V_42 )
{
char * V_56 =
( (struct V_5 * ) V_4 ) -> V_25 -> V_57 ;
* V_42 = V_58 ;
if ( ! V_56 ) {
V_56 = L_18 ;
F_2 ( L_19 ) ;
} else if ( strstr ( V_56 , L_20 ) )
* V_42 = 1 ;
else if ( strstr ( V_56 , L_21 ) )
* V_42 = 4 ;
else if ( strstr ( V_56 , L_22 ) )
* V_42 = 0 ;
else if ( strstr ( V_56 , L_23 ) )
* V_42 = 2 ;
F_27 ( L_24 , * V_42 , V_56 ) ;
}
static int F_31 ( void * V_4 , int V_42 )
{
struct V_10 V_59 = { V_60 , 0 , V_61 ,
sizeof( struct V_10 ) , 0 } ;
if ( V_42 < V_51 || V_42 > V_52 ) {
F_2 ( L_11 , V_42 ) ;
return - V_53 ;
}
return F_17 ( V_4 , & V_59 , sizeof( V_59 ) ) ;
}
static void F_32 ( struct V_62 * V_63 )
{
struct V_5 * V_6 = F_33 ( V_63 ) ;
if ( V_6 ) {
V_6 -> V_39 = V_64 ;
F_13 ( V_6 ) ;
if ( V_6 -> V_23 )
F_34 ( V_6 -> V_23 ) ;
F_27 ( L_25 , V_6 ) ;
F_28 ( V_6 ) ;
}
F_35 ( V_63 , NULL ) ;
}
static int F_36 ( struct V_62 * V_63 , int V_43 )
{
struct V_65 V_66 ;
struct V_5 * V_6 ;
int V_33 , V_36 ;
V_6 = F_37 ( sizeof( struct V_5 ) , V_54 ) ;
if ( ! V_6 ) {
F_2 ( L_26 ) ;
return - V_24 ;
}
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
F_35 ( V_63 , V_6 ) ;
V_6 -> V_25 = F_38 ( V_63 ) ;
V_6 -> V_39 = V_64 ;
V_66 . V_67 = F_22 ( V_43 ) -> type ;
switch ( V_66 . V_67 ) {
case V_68 :
V_6 -> V_27 = V_69 ;
V_66 . V_70 = F_31 ;
V_66 . V_71 = F_30 ;
break;
case V_72 :
F_2 ( L_27 ) ;
default:
V_6 -> V_27 = V_73 ;
V_6 -> V_16 =
F_39 ( V_6 -> V_25 -> V_74 [ 1 ] -> V_75 . V_76 ) -
sizeof( struct V_10 ) ;
V_66 . V_77 |= V_78 ;
break;
}
for ( V_33 = 0 ; V_33 < V_63 -> V_79 -> V_75 . V_80 ; V_33 ++ ) {
if ( V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 & V_83 )
V_6 -> V_26 = V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ;
else
V_6 -> V_84 = V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ;
}
F_27 ( L_28 ,
V_6 -> V_26 , V_6 -> V_84 ) ;
V_66 . V_85 = & V_6 -> V_25 -> V_6 ;
V_66 . V_27 = V_6 -> V_27 ;
V_66 . V_86 = V_87 ;
V_66 . V_88 = F_17 ;
V_66 . V_4 = V_6 ;
F_40 ( V_6 -> V_25 , V_66 . V_89 , sizeof( V_66 . V_89 ) ) ;
V_36 = F_41 ( & V_66 , & V_6 -> V_23 ) ;
if ( V_36 < 0 ) {
F_2 ( L_29 , V_36 ) ;
F_32 ( V_63 ) ;
return V_36 ;
}
F_42 ( V_6 -> V_23 , V_43 ) ;
V_6 -> V_23 -> V_90 = true ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_6 -> V_35 [ V_33 ] . V_6 = V_6 ;
F_43 ( & V_6 -> V_35 [ V_33 ] . V_1 ) ;
}
F_27 ( L_30 ) ;
V_36 = F_16 ( V_6 ) ;
if ( V_36 < 0 ) {
F_2 ( L_31 ) ;
F_32 ( V_63 ) ;
return V_36 ;
}
V_6 -> V_39 = V_40 ;
V_36 = F_44 ( V_6 -> V_23 ) ;
if ( V_36 < 0 ) {
F_2 ( L_32 ) ;
F_32 ( V_63 ) ;
return V_36 ;
}
F_27 ( L_33 , V_6 ) ;
return V_36 ;
}
static int F_45 ( struct V_62 * V_63 ,
const struct V_91 * V_47 )
{
struct V_46 * V_25 = F_38 ( V_63 ) ;
char V_89 [ 32 ] ;
int V_33 , V_36 ;
F_27 ( L_34 ,
V_63 -> V_79 -> V_75 . V_92 ) ;
if ( F_22 ( V_47 -> V_93 ) -> V_94 !=
V_63 -> V_79 -> V_75 . V_92 ) {
F_2 ( L_35 ,
F_22 ( V_47 -> V_93 ) -> V_94 ,
V_63 -> V_79 -> V_75 . V_92 ) ;
return - V_95 ;
}
if ( V_63 -> V_96 > 1 ) {
V_36 = F_46 ( V_25 ,
V_63 -> V_79 -> V_75 . V_92 ,
0 ) ;
if ( V_36 < 0 ) {
F_2 ( L_36 , V_36 ) ;
return V_36 ;
}
}
F_27 ( L_37 ,
V_63 -> V_79 -> V_75 . V_92 ) ;
for ( V_33 = 0 ; V_33 < V_63 -> V_79 -> V_75 . V_80 ; V_33 ++ ) {
F_27 ( L_38 , V_33 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_97 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_76 ) ;
if ( V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 &
V_83 )
V_36 = F_47 ( V_25 , F_11 ( V_25 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ) ) ;
else
V_36 = F_47 ( V_25 , F_20 ( V_25 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ) ) ;
}
if ( ( V_25 -> V_98 -> V_75 . V_99 == 2 ) &&
( V_63 -> V_79 -> V_75 . V_92 == 0 ) ) {
F_2 ( L_39 ) ;
return - V_95 ;
}
if ( V_47 -> V_93 == V_100 ) {
F_27 ( L_40 ) ;
snprintf ( V_89 , sizeof( V_89 ) , L_41 ,
V_25 -> V_101 -> V_102 , V_25 -> V_89 ) ;
F_27 ( L_40 ) ;
return F_23 (
V_25 , F_48 ( V_89 ) ,
V_47 -> V_93 ) ;
}
V_36 = F_36 ( V_63 , V_47 -> V_93 ) ;
F_27 ( L_42 , V_36 ) ;
F_49 ( V_47 -> V_93 ) ;
return V_36 ;
}
static void F_50 ( struct V_62 * V_63 )
{
F_32 ( V_63 ) ;
}
static int F_51 ( struct V_62 * V_63 , T_3 V_59 )
{
struct V_5 * V_6 = F_33 ( V_63 ) ;
F_52 ( V_103 L_43 , V_104 , V_59 . V_105 ) ;
V_6 -> V_39 = V_106 ;
F_13 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_62 * V_63 )
{
int V_36 , V_33 ;
struct V_5 * V_6 = F_33 ( V_63 ) ;
struct V_46 * V_25 = F_38 ( V_63 ) ;
F_52 ( V_103 L_44 , V_104 ) ;
F_47 ( V_25 , F_11 ( V_25 , V_6 -> V_26 ) ) ;
F_47 ( V_25 , F_20 ( V_25 , V_6 -> V_84 ) ) ;
for ( V_33 = 0 ; V_33 < V_63 -> V_79 -> V_75 . V_80 ; V_33 ++ )
F_52 ( V_103 L_45 , V_33 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_82 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_97 ,
V_63 -> V_79 -> V_81 [ V_33 ] . V_75 . V_76 ) ;
if ( V_63 -> V_96 > 0 ) {
V_36 = F_46 ( V_25 ,
V_63 -> V_79 -> V_75 .
V_92 , 0 ) ;
if ( V_36 < 0 ) {
F_52 ( V_103 L_46
L_47 , V_104 , V_36 ) ;
return V_36 ;
}
}
F_16 ( V_6 ) ;
return 0 ;
}
