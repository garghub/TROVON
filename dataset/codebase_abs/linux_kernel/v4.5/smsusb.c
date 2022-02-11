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
F_2 ( L_2 ,
V_11 -> V_14 ,
V_3 -> V_12 -> V_19 ,
V_1 -> V_9 ) ;
goto V_20;
}
memcpy ( ( char * ) V_11 + V_3 -> V_12 -> V_19 ,
V_11 , sizeof( struct V_10 ) ) ;
} else
V_3 -> V_12 -> V_19 = 0 ;
F_4 ( L_3 ,
F_5 ( V_11 -> V_21 ) ,
V_11 -> V_21 , V_11 -> V_14 ) ;
F_6 ( (struct V_22 * ) V_11 ) ;
F_7 ( V_6 -> V_23 , V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
} else {
F_2 ( L_4 ,
V_11 -> V_14 , V_1 -> V_9 ) ;
}
} else
F_2 ( L_5 ,
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
F_2 ( L_6 ) ;
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
F_2 ( L_7 ) ;
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
F_4 ( L_8 ) ;
return - V_41 ;
}
F_4 ( L_9 ,
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
F_2 ( L_10 , V_47 ) ;
return - V_54 ;
}
V_50 = F_21 ( V_47 , V_43 ) ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_11 ,
V_50 , V_47 ) ;
V_50 = V_45 [ V_47 ] ;
V_36 = F_24 ( & V_44 , V_50 , & V_25 -> V_6 ) ;
if ( V_36 < 0 ) {
F_25 ( L_12 ,
V_50 , V_47 ) ;
return V_36 ;
}
}
V_49 = F_26 ( V_44 -> V_15 , V_55 ) ;
if ( V_49 ) {
memcpy ( V_49 , V_44 -> V_56 , V_44 -> V_15 ) ;
V_36 = F_19 ( V_25 , F_20 ( V_25 , 2 ) ,
V_49 , V_44 -> V_15 , & V_38 , 1000 ) ;
F_4 ( L_13 , V_44 -> V_15 , V_38 , V_36 ) ;
F_27 ( V_49 ) ;
} else {
F_2 ( L_14 ) ;
V_36 = - V_24 ;
}
F_4 ( L_15 , V_50 , V_44 -> V_15 ) ;
F_28 ( V_44 ) ;
return V_36 ;
}
static void F_29 ( void * V_4 , int * V_42 )
{
char * V_57 =
( (struct V_5 * ) V_4 ) -> V_25 -> V_58 ;
* V_42 = V_59 ;
if ( ! V_57 ) {
V_57 = L_16 ;
F_2 ( L_17 ) ;
} else if ( strstr ( V_57 , L_18 ) )
* V_42 = 1 ;
else if ( strstr ( V_57 , L_19 ) )
* V_42 = 4 ;
else if ( strstr ( V_57 , L_20 ) )
* V_42 = 0 ;
else if ( strstr ( V_57 , L_21 ) )
* V_42 = 2 ;
F_4 ( L_22 , * V_42 , V_57 ) ;
}
static int F_30 ( void * V_4 , int V_42 )
{
struct V_10 V_60 = { V_61 , 0 , V_62 ,
sizeof( struct V_10 ) , 0 } ;
if ( V_42 < V_52 || V_42 > V_53 ) {
F_2 ( L_10 , V_42 ) ;
return - V_54 ;
}
return F_17 ( V_4 , & V_60 , sizeof( V_60 ) ) ;
}
static void F_31 ( struct V_63 * V_64 )
{
struct V_5 * V_6 = F_32 ( V_64 ) ;
if ( V_6 ) {
V_6 -> V_39 = V_65 ;
F_13 ( V_6 ) ;
if ( V_6 -> V_23 )
F_33 ( V_6 -> V_23 ) ;
F_4 ( L_23 , V_6 ) ;
F_27 ( V_6 ) ;
}
F_34 ( V_64 , NULL ) ;
}
static void * F_35 ( struct V_5 * V_6 ,
int V_43 )
{
#ifdef F_36
struct V_66 * V_67 ;
struct V_46 * V_25 = V_6 -> V_25 ;
struct V_68 * V_69 = F_22 ( V_43 ) ;
int V_70 ;
V_67 = F_37 ( sizeof( * V_67 ) , V_55 ) ;
if ( ! V_67 )
return NULL ;
V_67 -> V_6 = & V_25 -> V_6 ;
F_38 ( V_67 -> V_71 , V_69 -> V_72 , sizeof( V_67 -> V_71 ) ) ;
if ( V_25 -> V_73 )
F_38 ( V_67 -> V_73 , V_25 -> V_73 , sizeof( V_67 -> V_73 ) ) ;
strcpy ( V_67 -> V_74 , V_25 -> V_75 ) ;
V_67 -> V_76 = F_39 ( V_25 -> V_77 . V_78 ) ;
V_67 -> V_79 = V_80 ;
F_40 ( V_67 ) ;
V_70 = F_41 ( V_67 ) ;
if ( V_70 ) {
F_42 ( V_67 ) ;
F_27 ( V_67 ) ;
return NULL ;
}
F_43 ( L_24 ) ;
return V_67 ;
#else
return NULL ;
#endif
}
static int F_44 ( struct V_63 * V_64 , int V_43 )
{
struct V_81 V_82 ;
struct V_5 * V_6 ;
void * V_67 ;
int V_33 , V_36 ;
V_6 = F_37 ( sizeof( struct V_5 ) , V_55 ) ;
if ( ! V_6 )
return - V_24 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
F_34 ( V_64 , V_6 ) ;
V_6 -> V_25 = F_45 ( V_64 ) ;
V_6 -> V_39 = V_65 ;
V_82 . V_83 = F_22 ( V_43 ) -> type ;
switch ( V_82 . V_83 ) {
case V_84 :
V_6 -> V_27 = V_85 ;
V_82 . V_86 = F_30 ;
V_82 . V_87 = F_29 ;
break;
case V_88 :
F_2 ( L_25 ) ;
default:
V_6 -> V_27 = V_89 ;
V_6 -> V_16 =
F_39 ( V_6 -> V_25 -> V_90 [ 1 ] -> V_91 . V_92 ) -
sizeof( struct V_10 ) ;
V_82 . V_93 |= V_94 ;
break;
}
for ( V_33 = 0 ; V_33 < V_64 -> V_95 -> V_91 . V_96 ; V_33 ++ ) {
if ( V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 & V_99 )
V_6 -> V_26 = V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ;
else
V_6 -> V_100 = V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ;
}
F_4 ( L_26 ,
V_6 -> V_26 , V_6 -> V_100 ) ;
V_82 . V_101 = & V_6 -> V_25 -> V_6 ;
V_82 . V_27 = V_6 -> V_27 ;
V_82 . V_102 = V_103 ;
V_82 . V_104 = F_17 ;
V_82 . V_4 = V_6 ;
F_46 ( V_6 -> V_25 , V_82 . V_75 , sizeof( V_82 . V_75 ) ) ;
V_67 = F_35 ( V_6 , V_43 ) ;
V_36 = F_47 ( & V_82 , & V_6 -> V_23 , V_67 ) ;
if ( V_36 < 0 ) {
F_2 ( L_27 , V_36 ) ;
F_31 ( V_64 ) ;
#ifdef F_36
F_48 ( V_67 ) ;
#endif
F_27 ( V_67 ) ;
return V_36 ;
}
F_49 ( V_6 -> V_23 , V_43 ) ;
V_6 -> V_23 -> V_105 = true ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_6 -> V_35 [ V_33 ] . V_6 = V_6 ;
F_50 ( & V_6 -> V_35 [ V_33 ] . V_1 ) ;
}
F_4 ( L_28 ) ;
V_36 = F_16 ( V_6 ) ;
if ( V_36 < 0 ) {
F_2 ( L_29 ) ;
F_31 ( V_64 ) ;
return V_36 ;
}
V_6 -> V_39 = V_40 ;
V_36 = F_51 ( V_6 -> V_23 ) ;
if ( V_36 < 0 ) {
F_2 ( L_30 ) ;
F_31 ( V_64 ) ;
return V_36 ;
}
F_4 ( L_31 , V_6 ) ;
return V_36 ;
}
static int F_52 ( struct V_63 * V_64 ,
const struct V_106 * V_47 )
{
struct V_46 * V_25 = F_45 ( V_64 ) ;
char V_75 [ 32 ] ;
int V_33 , V_36 ;
F_43 ( L_32 ,
V_47 -> V_107 ,
V_64 -> V_95 -> V_91 . V_108 ) ;
if ( F_22 ( V_47 -> V_107 ) -> V_109 !=
V_64 -> V_95 -> V_91 . V_108 ) {
F_4 ( L_33 ,
V_64 -> V_95 -> V_91 . V_108 ,
F_22 ( V_47 -> V_107 ) -> V_109 ) ;
return - V_110 ;
}
if ( V_64 -> V_111 > 1 ) {
V_36 = F_53 ( V_25 ,
V_64 -> V_95 -> V_91 . V_108 ,
0 ) ;
if ( V_36 < 0 ) {
F_2 ( L_34 , V_36 ) ;
return V_36 ;
}
}
F_4 ( L_35 ,
V_64 -> V_95 -> V_91 . V_108 ) ;
for ( V_33 = 0 ; V_33 < V_64 -> V_95 -> V_91 . V_96 ; V_33 ++ ) {
F_4 ( L_36 , V_33 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_112 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_92 ) ;
if ( V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 &
V_99 )
V_36 = F_54 ( V_25 , F_11 ( V_25 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ) ) ;
else
V_36 = F_54 ( V_25 , F_20 ( V_25 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ) ) ;
}
if ( ( V_25 -> V_113 -> V_91 . V_114 == 2 ) &&
( V_64 -> V_95 -> V_91 . V_108 == 0 ) ) {
F_4 ( L_37 ) ;
return - V_110 ;
}
if ( V_47 -> V_107 == V_115 ) {
snprintf ( V_75 , sizeof( V_75 ) , L_38 ,
V_25 -> V_116 -> V_117 , V_25 -> V_75 ) ;
F_43 ( L_39 ,
V_75 ) ;
V_36 = F_23 (
V_25 , F_55 ( V_75 ) ,
V_47 -> V_107 ) ;
if ( ! V_36 )
F_43 ( L_40 ) ;
else
F_2 ( L_41 ,
V_36 ) ;
return V_36 ;
} else {
V_36 = F_44 ( V_64 , V_47 -> V_107 ) ;
}
F_43 ( L_42 , V_36 ) ;
F_56 ( V_47 -> V_107 ) ;
return V_36 ;
}
static void F_57 ( struct V_63 * V_64 )
{
F_31 ( V_64 ) ;
}
static int F_58 ( struct V_63 * V_64 , T_3 V_60 )
{
struct V_5 * V_6 = F_32 ( V_64 ) ;
F_59 ( V_118 L_43 , V_119 , V_60 . V_120 ) ;
V_6 -> V_39 = V_121 ;
F_13 ( V_6 ) ;
return 0 ;
}
static int F_60 ( struct V_63 * V_64 )
{
int V_36 , V_33 ;
struct V_5 * V_6 = F_32 ( V_64 ) ;
struct V_46 * V_25 = F_45 ( V_64 ) ;
F_59 ( V_118 L_44 , V_119 ) ;
F_54 ( V_25 , F_11 ( V_25 , V_6 -> V_26 ) ) ;
F_54 ( V_25 , F_20 ( V_25 , V_6 -> V_100 ) ) ;
for ( V_33 = 0 ; V_33 < V_64 -> V_95 -> V_91 . V_96 ; V_33 ++ )
F_59 ( V_118 L_36 , V_33 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_98 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_112 ,
V_64 -> V_95 -> V_97 [ V_33 ] . V_91 . V_92 ) ;
if ( V_64 -> V_111 > 0 ) {
V_36 = F_53 ( V_25 ,
V_64 -> V_95 -> V_91 .
V_108 , 0 ) ;
if ( V_36 < 0 ) {
F_59 ( V_118 L_45
L_46 , V_119 , V_36 ) ;
return V_36 ;
}
}
F_16 ( V_6 ) ;
return 0 ;
}
