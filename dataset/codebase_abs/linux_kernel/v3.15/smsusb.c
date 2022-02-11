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
if ( V_6 -> V_39 != V_40 ) {
F_4 ( L_10 ) ;
return - V_41 ;
}
F_4 ( L_11 ,
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
if ( V_47 < 0 )
V_47 = F_22 ( V_43 ) -> V_51 ;
if ( V_47 < V_52 || V_47 > V_53 ) {
F_2 ( L_12 , V_47 ) ;
return - V_54 ;
}
V_50 = F_21 ( V_47 , V_43 ) ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_13
L_14 , V_50 , V_47 ) ;
V_50 = V_45 [ V_47 ] ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_15 ,
V_50 , V_47 ) ;
return V_36 ;
}
}
V_49 = F_26 ( V_44 -> V_15 , V_55 ) ;
if ( V_49 ) {
memcpy ( V_49 , V_44 -> V_56 , V_44 -> V_15 ) ;
V_36 = F_19 ( V_25 , F_20 ( V_25 , 2 ) ,
V_49 , V_44 -> V_15 , & V_38 , 1000 ) ;
F_27 ( L_16 , V_44 -> V_15 , V_38 , V_36 ) ;
F_28 ( V_49 ) ;
} else {
F_2 ( L_17 ) ;
V_36 = - V_24 ;
}
F_27 ( L_18 , V_50 , V_44 -> V_15 ) ;
F_29 ( V_44 ) ;
return V_36 ;
}
static void F_30 ( void * V_4 , int * V_42 )
{
char * V_57 =
( (struct V_5 * ) V_4 ) -> V_25 -> V_58 ;
* V_42 = V_59 ;
if ( ! V_57 ) {
V_57 = L_19 ;
F_2 ( L_20 ) ;
} else if ( strstr ( V_57 , L_21 ) )
* V_42 = 1 ;
else if ( strstr ( V_57 , L_22 ) )
* V_42 = 4 ;
else if ( strstr ( V_57 , L_23 ) )
* V_42 = 0 ;
else if ( strstr ( V_57 , L_24 ) )
* V_42 = 2 ;
F_27 ( L_25 , * V_42 , V_57 ) ;
}
static int F_31 ( void * V_4 , int V_42 )
{
struct V_10 V_60 = { V_61 , 0 , V_62 ,
sizeof( struct V_10 ) , 0 } ;
if ( V_42 < V_52 || V_42 > V_53 ) {
F_2 ( L_12 , V_42 ) ;
return - V_54 ;
}
return F_17 ( V_4 , & V_60 , sizeof( V_60 ) ) ;
}
static void F_32 ( struct V_63 * V_64 )
{
struct V_5 * V_6 = F_33 ( V_64 ) ;
if ( V_6 ) {
V_6 -> V_39 = V_65 ;
F_13 ( V_6 ) ;
if ( V_6 -> V_23 )
F_34 ( V_6 -> V_23 ) ;
F_27 ( L_26 , V_6 ) ;
F_28 ( V_6 ) ;
}
F_35 ( V_64 , NULL ) ;
}
static int F_36 ( struct V_63 * V_64 , int V_43 )
{
struct V_66 V_67 ;
struct V_5 * V_6 ;
int V_33 , V_36 ;
V_6 = F_37 ( sizeof( struct V_5 ) , V_55 ) ;
if ( ! V_6 ) {
F_2 ( L_27 ) ;
return - V_24 ;
}
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
F_35 ( V_64 , V_6 ) ;
V_6 -> V_25 = F_38 ( V_64 ) ;
V_6 -> V_39 = V_65 ;
V_67 . V_68 = F_22 ( V_43 ) -> type ;
switch ( V_67 . V_68 ) {
case V_69 :
V_6 -> V_27 = V_70 ;
V_67 . V_71 = F_31 ;
V_67 . V_72 = F_30 ;
break;
case V_73 :
F_2 ( L_28 ) ;
default:
V_6 -> V_27 = V_74 ;
V_6 -> V_16 =
F_39 ( V_6 -> V_25 -> V_75 [ 1 ] -> V_76 . V_77 ) -
sizeof( struct V_10 ) ;
V_67 . V_78 |= V_79 ;
break;
}
for ( V_33 = 0 ; V_33 < V_64 -> V_80 -> V_76 . V_81 ; V_33 ++ ) {
if ( V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 & V_84 )
V_6 -> V_26 = V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ;
else
V_6 -> V_85 = V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ;
}
F_27 ( L_29 ,
V_6 -> V_26 , V_6 -> V_85 ) ;
V_67 . V_86 = & V_6 -> V_25 -> V_6 ;
V_67 . V_27 = V_6 -> V_27 ;
V_67 . V_87 = V_88 ;
V_67 . V_89 = F_17 ;
V_67 . V_4 = V_6 ;
F_40 ( V_6 -> V_25 , V_67 . V_90 , sizeof( V_67 . V_90 ) ) ;
V_36 = F_41 ( & V_67 , & V_6 -> V_23 ) ;
if ( V_36 < 0 ) {
F_2 ( L_30 , V_36 ) ;
F_32 ( V_64 ) ;
return V_36 ;
}
F_42 ( V_6 -> V_23 , V_43 ) ;
V_6 -> V_23 -> V_91 = true ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_6 -> V_35 [ V_33 ] . V_6 = V_6 ;
F_43 ( & V_6 -> V_35 [ V_33 ] . V_1 ) ;
}
F_27 ( L_31 ) ;
V_36 = F_16 ( V_6 ) ;
if ( V_36 < 0 ) {
F_2 ( L_32 ) ;
F_32 ( V_64 ) ;
return V_36 ;
}
V_6 -> V_39 = V_40 ;
V_36 = F_44 ( V_6 -> V_23 ) ;
if ( V_36 < 0 ) {
F_2 ( L_33 ) ;
F_32 ( V_64 ) ;
return V_36 ;
}
F_27 ( L_34 , V_6 ) ;
return V_36 ;
}
static int F_45 ( struct V_63 * V_64 ,
const struct V_92 * V_47 )
{
struct V_46 * V_25 = F_38 ( V_64 ) ;
char V_90 [ 32 ] ;
int V_33 , V_36 ;
F_27 ( L_35 ,
V_47 -> V_93 ,
V_64 -> V_80 -> V_76 . V_94 ) ;
if ( F_22 ( V_47 -> V_93 ) -> V_95 !=
V_64 -> V_80 -> V_76 . V_94 ) {
F_4 ( L_36 ,
V_64 -> V_80 -> V_76 . V_94 ,
F_22 ( V_47 -> V_93 ) -> V_95 ) ;
return - V_96 ;
}
if ( V_64 -> V_97 > 1 ) {
V_36 = F_46 ( V_25 ,
V_64 -> V_80 -> V_76 . V_94 ,
0 ) ;
if ( V_36 < 0 ) {
F_2 ( L_37 , V_36 ) ;
return V_36 ;
}
}
F_27 ( L_38 ,
V_64 -> V_80 -> V_76 . V_94 ) ;
for ( V_33 = 0 ; V_33 < V_64 -> V_80 -> V_76 . V_81 ; V_33 ++ ) {
F_27 ( L_39 , V_33 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_98 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_77 ) ;
if ( V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 &
V_84 )
V_36 = F_47 ( V_25 , F_11 ( V_25 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ) ) ;
else
V_36 = F_47 ( V_25 , F_20 ( V_25 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ) ) ;
}
if ( ( V_25 -> V_99 -> V_76 . V_100 == 2 ) &&
( V_64 -> V_80 -> V_76 . V_94 == 0 ) ) {
F_4 ( L_40 ) ;
return - V_96 ;
}
if ( V_47 -> V_93 == V_101 ) {
snprintf ( V_90 , sizeof( V_90 ) , L_41 ,
V_25 -> V_102 -> V_103 , V_25 -> V_90 ) ;
F_27 ( L_42 , V_90 ) ;
V_36 = F_23 (
V_25 , F_48 ( V_90 ) ,
V_47 -> V_93 ) ;
if ( ! V_36 )
F_27 ( L_43 ) ;
else
F_2 ( L_44 , V_36 ) ;
return V_36 ;
} else {
V_36 = F_36 ( V_64 , V_47 -> V_93 ) ;
}
F_27 ( L_45 , V_36 ) ;
F_49 ( V_47 -> V_93 ) ;
return V_36 ;
}
static void F_50 ( struct V_63 * V_64 )
{
F_32 ( V_64 ) ;
}
static int F_51 ( struct V_63 * V_64 , T_3 V_60 )
{
struct V_5 * V_6 = F_33 ( V_64 ) ;
F_52 ( V_104 L_46 , V_105 , V_60 . V_106 ) ;
V_6 -> V_39 = V_107 ;
F_13 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_63 * V_64 )
{
int V_36 , V_33 ;
struct V_5 * V_6 = F_33 ( V_64 ) ;
struct V_46 * V_25 = F_38 ( V_64 ) ;
F_52 ( V_104 L_47 , V_105 ) ;
F_47 ( V_25 , F_11 ( V_25 , V_6 -> V_26 ) ) ;
F_47 ( V_25 , F_20 ( V_25 , V_6 -> V_85 ) ) ;
for ( V_33 = 0 ; V_33 < V_64 -> V_80 -> V_76 . V_81 ; V_33 ++ )
F_52 ( V_104 L_48 , V_33 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_83 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_98 ,
V_64 -> V_80 -> V_82 [ V_33 ] . V_76 . V_77 ) ;
if ( V_64 -> V_97 > 0 ) {
V_36 = F_46 ( V_25 ,
V_64 -> V_80 -> V_76 .
V_94 , 0 ) ;
if ( V_36 < 0 ) {
F_52 ( V_104 L_49
L_50 , V_105 , V_36 ) ;
return V_36 ;
}
}
F_16 ( V_6 ) ;
return 0 ;
}
