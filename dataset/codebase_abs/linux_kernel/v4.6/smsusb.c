static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_3 ( V_7 , V_4 ) ;
}
static void F_4 ( struct V_8 * V_8 )
{
struct V_3 * V_4 = (struct V_3 * ) V_8 -> V_9 ;
struct V_6 * V_7 = V_4 -> V_7 ;
if ( V_8 -> V_10 == - V_11 ) {
F_5 ( L_1 ,
V_8 -> V_10 , V_8 -> V_12 ) ;
return;
}
if ( ( V_8 -> V_12 > 0 ) && ( V_8 -> V_10 == 0 ) ) {
struct V_13 * V_14 = (struct V_13 * ) V_4 -> V_15 -> V_16 ;
F_6 ( V_14 ) ;
if ( V_8 -> V_12 >= V_14 -> V_17 ) {
V_4 -> V_15 -> V_18 = V_14 -> V_17 ;
if ( V_7 -> V_19 &&
( V_14 -> V_20 & V_21 ) ) {
V_4 -> V_15 -> V_22 =
V_7 -> V_19 +
( ( V_14 -> V_20 >> 8 ) & 3 ) ;
if ( ( ( int ) V_14 -> V_17 +
V_4 -> V_15 -> V_22 ) > V_8 -> V_12 ) {
F_5 ( L_2 ,
V_14 -> V_17 ,
V_4 -> V_15 -> V_22 ,
V_8 -> V_12 ) ;
goto V_23;
}
memcpy ( ( char * ) V_14 + V_4 -> V_15 -> V_22 ,
V_14 , sizeof( struct V_13 ) ) ;
} else
V_4 -> V_15 -> V_22 = 0 ;
F_7 ( L_3 ,
F_8 ( V_14 -> V_24 ) ,
V_14 -> V_24 , V_14 -> V_17 ) ;
F_9 ( (struct V_25 * ) V_14 ) ;
F_10 ( V_7 -> V_26 , V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
} else {
F_5 ( L_4 ,
V_14 -> V_17 , V_8 -> V_12 ) ;
}
} else
F_5 ( L_5 ,
V_8 -> V_10 , V_8 -> V_12 ) ;
V_23:
F_11 ( & V_4 -> V_5 , F_1 ) ;
F_12 ( & V_4 -> V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
if ( ! V_4 -> V_15 ) {
V_4 -> V_15 = F_13 ( V_7 -> V_26 ) ;
if ( ! V_4 -> V_15 ) {
F_5 ( L_6 ) ;
return - V_27 ;
}
}
F_14 (
& V_4 -> V_8 ,
V_7 -> V_28 ,
F_15 ( V_7 -> V_28 , V_7 -> V_29 ) ,
V_4 -> V_15 -> V_16 ,
V_7 -> V_30 ,
F_4 ,
V_4
) ;
V_4 -> V_8 . V_31 = V_4 -> V_15 -> V_32 ;
V_4 -> V_8 . V_33 |= V_34 ;
return F_16 ( & V_4 -> V_8 , V_35 ) ;
}
static void F_17 ( struct V_6 * V_7 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
F_18 ( & V_7 -> V_38 [ V_36 ] . V_8 ) ;
if ( V_7 -> V_38 [ V_36 ] . V_15 ) {
F_19 ( V_7 -> V_26 , V_7 -> V_38 [ V_36 ] . V_15 ) ;
V_7 -> V_38 [ V_36 ] . V_15 = NULL ;
}
}
}
static int F_20 ( struct V_6 * V_7 )
{
int V_36 , V_39 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_39 = F_3 ( V_7 , & V_7 -> V_38 [ V_36 ] ) ;
if ( V_39 < 0 ) {
F_5 ( L_7 ) ;
F_17 ( V_7 ) ;
break;
}
}
return V_39 ;
}
static int F_21 ( void * V_9 , void * V_40 , T_1 V_18 )
{
struct V_6 * V_7 = (struct V_6 * ) V_9 ;
struct V_13 * V_14 = (struct V_13 * ) V_40 ;
int V_41 ;
if ( V_7 -> V_42 != V_43 ) {
F_7 ( L_8 ) ;
return - V_44 ;
}
F_7 ( L_9 ,
F_8 ( V_14 -> V_24 ) , V_14 -> V_24 ,
V_14 -> V_17 ) ;
F_22 ( (struct V_25 * ) V_14 ) ;
F_6 ( (struct V_13 * ) V_40 ) ;
return F_23 ( V_7 -> V_28 , F_24 ( V_7 -> V_28 , 2 ) ,
V_40 , V_18 , & V_41 , 1000 ) ;
}
static inline char * F_25 ( int V_45 , int V_46 )
{
char * * V_47 = F_26 ( V_46 ) -> V_47 ;
return ( V_47 && V_47 [ V_45 ] ) ? V_47 [ V_45 ] : V_48 [ V_45 ] ;
}
static int F_27 ( struct V_49 * V_28 , int V_50 , int V_46 )
{
const struct V_51 * V_47 ;
T_2 * V_52 ;
int V_39 , V_41 ;
char * V_53 ;
if ( V_50 < 0 )
V_50 = F_26 ( V_46 ) -> V_54 ;
if ( V_50 < V_55 || V_50 > V_56 ) {
F_5 ( L_10 , V_50 ) ;
return - V_57 ;
}
V_53 = F_25 ( V_50 , V_46 ) ;
V_39 = F_28 ( & V_47 , V_53 , & V_28 -> V_7 ) ;
if ( V_39 < 0 ) {
F_29 ( L_11 ,
V_53 , V_50 ) ;
V_53 = V_48 [ V_50 ] ;
V_39 = F_28 ( & V_47 , V_53 , & V_28 -> V_7 ) ;
if ( V_39 < 0 ) {
F_29 ( L_12 ,
V_53 , V_50 ) ;
return V_39 ;
}
}
V_52 = F_30 ( V_47 -> V_18 , V_58 ) ;
if ( V_52 ) {
memcpy ( V_52 , V_47 -> V_59 , V_47 -> V_18 ) ;
V_39 = F_23 ( V_28 , F_24 ( V_28 , 2 ) ,
V_52 , V_47 -> V_18 , & V_41 , 1000 ) ;
F_7 ( L_13 , V_47 -> V_18 , V_41 , V_39 ) ;
F_31 ( V_52 ) ;
} else {
F_5 ( L_14 ) ;
V_39 = - V_27 ;
}
F_7 ( L_15 , V_53 , V_47 -> V_18 ) ;
F_32 ( V_47 ) ;
return V_39 ;
}
static void F_33 ( void * V_9 , int * V_45 )
{
char * V_60 =
( (struct V_6 * ) V_9 ) -> V_28 -> V_61 ;
* V_45 = V_62 ;
if ( ! V_60 ) {
V_60 = L_16 ;
F_5 ( L_17 ) ;
} else if ( strstr ( V_60 , L_18 ) )
* V_45 = 1 ;
else if ( strstr ( V_60 , L_19 ) )
* V_45 = 4 ;
else if ( strstr ( V_60 , L_20 ) )
* V_45 = 0 ;
else if ( strstr ( V_60 , L_21 ) )
* V_45 = 2 ;
F_7 ( L_22 , * V_45 , V_60 ) ;
}
static int F_34 ( void * V_9 , int V_45 )
{
struct V_13 V_63 = { V_64 , 0 , V_65 ,
sizeof( struct V_13 ) , 0 } ;
if ( V_45 < V_55 || V_45 > V_56 ) {
F_5 ( L_10 , V_45 ) ;
return - V_57 ;
}
return F_21 ( V_9 , & V_63 , sizeof( V_63 ) ) ;
}
static void F_35 ( struct V_66 * V_67 )
{
struct V_6 * V_7 = F_36 ( V_67 ) ;
if ( V_7 ) {
V_7 -> V_42 = V_68 ;
F_17 ( V_7 ) ;
if ( V_7 -> V_26 )
F_37 ( V_7 -> V_26 ) ;
F_7 ( L_23 , V_7 ) ;
F_31 ( V_7 ) ;
}
F_38 ( V_67 , NULL ) ;
}
static void * F_39 ( struct V_6 * V_7 ,
int V_46 )
{
#ifdef F_40
struct V_69 * V_70 ;
struct V_49 * V_28 = V_7 -> V_28 ;
struct V_71 * V_72 = F_26 ( V_46 ) ;
int V_73 ;
V_70 = F_41 ( sizeof( * V_70 ) , V_58 ) ;
if ( ! V_70 )
return NULL ;
F_42 ( V_70 , V_28 , V_72 -> V_74 ) ;
V_73 = F_43 ( V_70 ) ;
if ( V_73 ) {
F_44 ( V_70 ) ;
F_31 ( V_70 ) ;
return NULL ;
}
F_45 ( L_24 ) ;
return V_70 ;
#else
return NULL ;
#endif
}
static int F_46 ( struct V_66 * V_67 , int V_46 )
{
struct V_75 V_76 ;
struct V_6 * V_7 ;
void * V_70 ;
int V_36 , V_39 ;
V_7 = F_41 ( sizeof( struct V_6 ) , V_58 ) ;
if ( ! V_7 )
return - V_27 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
F_38 ( V_67 , V_7 ) ;
V_7 -> V_28 = F_47 ( V_67 ) ;
V_7 -> V_42 = V_68 ;
V_76 . V_77 = F_26 ( V_46 ) -> type ;
switch ( V_76 . V_77 ) {
case V_78 :
V_7 -> V_30 = V_79 ;
V_76 . V_80 = F_34 ;
V_76 . V_81 = F_33 ;
break;
case V_82 :
F_5 ( L_25 ) ;
default:
V_7 -> V_30 = V_83 ;
V_7 -> V_19 =
F_48 ( V_7 -> V_28 -> V_84 [ 1 ] -> V_85 . V_86 ) -
sizeof( struct V_13 ) ;
V_76 . V_87 |= V_88 ;
break;
}
for ( V_36 = 0 ; V_36 < V_67 -> V_89 -> V_85 . V_90 ; V_36 ++ ) {
if ( V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 & V_93 )
V_7 -> V_29 = V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ;
else
V_7 -> V_94 = V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ;
}
F_7 ( L_26 ,
V_7 -> V_29 , V_7 -> V_94 ) ;
V_76 . V_95 = & V_7 -> V_28 -> V_7 ;
V_76 . V_30 = V_7 -> V_30 ;
V_76 . V_96 = V_97 ;
V_76 . V_98 = F_21 ;
V_76 . V_9 = V_7 ;
F_49 ( V_7 -> V_28 , V_76 . V_99 , sizeof( V_76 . V_99 ) ) ;
V_70 = F_39 ( V_7 , V_46 ) ;
V_39 = F_50 ( & V_76 , & V_7 -> V_26 , V_70 ) ;
if ( V_39 < 0 ) {
F_5 ( L_27 , V_39 ) ;
F_35 ( V_67 ) ;
#ifdef F_40
F_51 ( V_70 ) ;
#endif
F_31 ( V_70 ) ;
return V_39 ;
}
F_52 ( V_7 -> V_26 , V_46 ) ;
V_7 -> V_26 -> V_100 = true ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ ) {
V_7 -> V_38 [ V_36 ] . V_7 = V_7 ;
F_53 ( & V_7 -> V_38 [ V_36 ] . V_8 ) ;
}
F_7 ( L_28 ) ;
V_39 = F_20 ( V_7 ) ;
if ( V_39 < 0 ) {
F_5 ( L_29 ) ;
F_35 ( V_67 ) ;
return V_39 ;
}
V_7 -> V_42 = V_43 ;
V_39 = F_54 ( V_7 -> V_26 ) ;
if ( V_39 < 0 ) {
F_5 ( L_30 ) ;
F_35 ( V_67 ) ;
return V_39 ;
}
F_7 ( L_31 , V_7 ) ;
return V_39 ;
}
static int F_55 ( struct V_66 * V_67 ,
const struct V_101 * V_50 )
{
struct V_49 * V_28 = F_47 ( V_67 ) ;
char V_99 [ 32 ] ;
int V_36 , V_39 ;
F_45 ( L_32 ,
V_50 -> V_102 ,
V_67 -> V_89 -> V_85 . V_103 ) ;
if ( F_26 ( V_50 -> V_102 ) -> V_104 !=
V_67 -> V_89 -> V_85 . V_103 ) {
F_7 ( L_33 ,
V_67 -> V_89 -> V_85 . V_103 ,
F_26 ( V_50 -> V_102 ) -> V_104 ) ;
return - V_105 ;
}
if ( V_67 -> V_106 > 1 ) {
V_39 = F_56 ( V_28 ,
V_67 -> V_89 -> V_85 . V_103 ,
0 ) ;
if ( V_39 < 0 ) {
F_5 ( L_34 , V_39 ) ;
return V_39 ;
}
}
F_7 ( L_35 ,
V_67 -> V_89 -> V_85 . V_103 ) ;
for ( V_36 = 0 ; V_36 < V_67 -> V_89 -> V_85 . V_90 ; V_36 ++ ) {
F_7 ( L_36 , V_36 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_107 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_86 ) ;
if ( V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 &
V_93 )
V_39 = F_57 ( V_28 , F_15 ( V_28 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ) ) ;
else
V_39 = F_57 ( V_28 , F_24 ( V_28 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ) ) ;
}
if ( ( V_28 -> V_108 -> V_85 . V_109 == 2 ) &&
( V_67 -> V_89 -> V_85 . V_103 == 0 ) ) {
F_7 ( L_37 ) ;
return - V_105 ;
}
if ( V_50 -> V_102 == V_110 ) {
snprintf ( V_99 , sizeof( V_99 ) , L_38 ,
V_28 -> V_111 -> V_112 , V_28 -> V_99 ) ;
F_45 ( L_39 ,
V_99 ) ;
V_39 = F_27 (
V_28 , F_58 ( V_99 ) ,
V_50 -> V_102 ) ;
if ( ! V_39 )
F_45 ( L_40 ) ;
else
F_5 ( L_41 ,
V_39 ) ;
return V_39 ;
} else {
V_39 = F_46 ( V_67 , V_50 -> V_102 ) ;
}
F_45 ( L_42 , V_39 ) ;
F_59 ( V_50 -> V_102 ) ;
return V_39 ;
}
static void F_60 ( struct V_66 * V_67 )
{
F_35 ( V_67 ) ;
}
static int F_61 ( struct V_66 * V_67 , T_3 V_63 )
{
struct V_6 * V_7 = F_36 ( V_67 ) ;
F_62 ( V_113 L_43 , V_114 , V_63 . V_115 ) ;
V_7 -> V_42 = V_116 ;
F_17 ( V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_66 * V_67 )
{
int V_39 , V_36 ;
struct V_6 * V_7 = F_36 ( V_67 ) ;
struct V_49 * V_28 = F_47 ( V_67 ) ;
F_62 ( V_113 L_44 , V_114 ) ;
F_57 ( V_28 , F_15 ( V_28 , V_7 -> V_29 ) ) ;
F_57 ( V_28 , F_24 ( V_28 , V_7 -> V_94 ) ) ;
for ( V_36 = 0 ; V_36 < V_67 -> V_89 -> V_85 . V_90 ; V_36 ++ )
F_62 ( V_113 L_36 , V_36 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_92 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_107 ,
V_67 -> V_89 -> V_91 [ V_36 ] . V_85 . V_86 ) ;
if ( V_67 -> V_106 > 0 ) {
V_39 = F_56 ( V_28 ,
V_67 -> V_89 -> V_85 .
V_103 , 0 ) ;
if ( V_39 < 0 ) {
F_62 ( V_113 L_45
L_46 , V_114 , V_39 ) ;
return V_39 ;
}
}
F_20 ( V_7 ) ;
return 0 ;
}
