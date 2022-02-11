static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( V_14 L_10 , V_4 ,
V_5 ) ;
} else {
F_2 ( V_14 L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static inline int F_3 ( struct V_1 * V_2 , struct V_15 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
int V_19 = 1 ;
unsigned char * V_20 ;
T_1 V_21 = 0 , V_22 = 0 ;
T_2 V_23 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_24 & V_25 )
return 0 ;
if ( V_15 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_15 -> V_4 ) ;
if ( V_15 -> V_4 == - V_6 )
return 0 ;
}
V_20 = V_15 -> V_26 ;
V_22 = V_15 -> V_27 ;
if ( V_22 > 0 ) {
V_21 = 0 ;
if ( V_17 -> V_28 ) {
V_23 = V_17 -> V_29 ;
} else {
V_23 = F_4 ( V_20 ,
V_17 -> V_30 ,
& V_21 ) ;
}
V_23 &= 0xF0 ;
if ( V_23 ) {
V_21 += F_5 ( V_2 , V_17 ,
V_23 ,
V_20 + V_21 ,
V_22 - V_21 ) ;
}
V_17 -> V_28 = 0 ;
while ( V_21 < V_22 ) {
T_1 V_31 = 0 ;
V_23 = F_6 (
V_20 + V_21 ,
V_22 - V_21 ,
& V_31 ) ;
V_21 += V_31 ;
V_23 &= 0xF0 ;
if ( V_23 && ( V_21 < V_22 ) ) {
V_21 += F_5 ( V_2 ,
V_17 , V_23 ,
V_20 + V_21 ,
V_22 - V_21 ) ;
}
}
memcpy ( V_17 -> V_30 , V_20 + V_22 - 4 , 4 ) ;
V_21 = 0 ;
}
return V_19 ;
}
static int
F_7 ( struct V_32 * V_33 , unsigned int * V_34 ,
unsigned int * V_35 )
{
struct V_36 * V_37 = V_33 -> V_38 ;
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_39 = 0 ;
V_39 = ( ( V_2 -> V_40 & V_41 ) ?
V_42 : V_43 ) ;
* V_35 = ( V_2 -> V_44 * V_39 * 2 * 2 ) ;
if ( 0 == * V_34 )
* V_34 = V_45 ;
if ( * V_34 < V_46 )
* V_34 = V_46 ;
return 0 ;
}
static void F_8 ( struct V_32 * V_33 , struct V_47 * V_48 )
{
struct V_36 * V_37 = V_33 -> V_38 ;
struct V_1 * V_2 = V_37 -> V_2 ;
unsigned long V_49 = 0 ;
if ( F_9 () )
F_10 () ;
F_11 ( & V_2 -> V_50 . V_51 , V_49 ) ;
if ( V_2 -> V_50 . V_52 . V_48 == V_48 )
V_2 -> V_50 . V_52 . V_48 = NULL ;
F_12 ( & V_2 -> V_50 . V_51 , V_49 ) ;
F_13 ( & V_48 -> V_53 ) ;
V_48 -> V_53 . V_24 = V_54 ;
}
static int
F_14 ( struct V_32 * V_33 , struct V_55 * V_53 ,
enum V_56 V_57 )
{
struct V_36 * V_37 = V_33 -> V_38 ;
struct V_47 * V_48 =
F_15 ( V_53 , struct V_47 , V_53 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
int V_19 = 0 , V_58 = 0 ;
T_1 V_39 = 0 ;
V_39 = ( ( V_2 -> V_40 & V_41 ) ?
V_42 : V_43 ) ;
V_48 -> V_53 . V_35 = ( ( V_2 -> V_44 << 1 ) * V_39 * 2 ) ;
if ( 0 != V_48 -> V_53 . V_59 && V_48 -> V_53 . V_60 < V_48 -> V_53 . V_35 )
return - V_61 ;
V_48 -> V_53 . V_44 = V_2 -> V_44 ;
V_48 -> V_53 . V_39 = V_39 ;
V_48 -> V_53 . V_57 = V_57 ;
V_48 -> V_53 . V_57 = V_62 ;
if ( V_54 == V_48 -> V_53 . V_24 ) {
V_19 = F_16 ( V_33 , & V_48 -> V_53 , NULL ) ;
if ( V_19 < 0 )
goto V_63;
}
if ( ! V_2 -> V_50 . V_52 . V_64 )
V_58 = 1 ;
if ( V_58 ) {
V_19 = F_17 ( V_2 , V_65 ,
V_66 ,
V_2 -> V_50 . V_67 [ 0 ] ,
F_3 ) ;
if ( V_19 < 0 )
goto V_63;
}
V_48 -> V_53 . V_24 = V_68 ;
return 0 ;
V_63:
F_8 ( V_33 , V_48 ) ;
return V_19 ;
}
static void
F_18 ( struct V_32 * V_33 , struct V_55 * V_53 )
{
struct V_47 * V_48 =
F_15 ( V_53 , struct V_47 , V_53 ) ;
struct V_36 * V_37 = V_33 -> V_38 ;
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_16 * V_69 = & V_2 -> V_50 . V_69 ;
V_48 -> V_53 . V_24 = V_70 ;
F_19 ( & V_48 -> V_53 . V_71 , & V_69 -> V_72 ) ;
}
static void F_20 ( struct V_32 * V_33 ,
struct V_55 * V_53 )
{
struct V_47 * V_48 =
F_15 ( V_53 , struct V_47 , V_53 ) ;
F_8 ( V_33 , V_48 ) ;
}
static void F_21 ( struct V_15 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_73 * V_74 =
F_15 ( V_17 , struct V_73 , V_69 ) ;
struct V_1 * V_2 = F_15 ( V_74 , struct V_1 , V_50 ) ;
switch ( V_15 -> V_4 ) {
case 0 :
case - V_75 :
break;
case - V_7 :
case - V_6 :
case - V_76 :
return;
default:
F_2 ( V_14 L_12 ,
V_15 -> V_4 ) ;
break;
}
F_22 ( & V_2 -> V_50 . V_51 ) ;
V_2 -> V_50 . V_52 . V_77 ( V_2 , V_15 ) ;
F_23 ( & V_2 -> V_50 . V_51 ) ;
V_15 -> V_4 = 0 ;
V_15 -> V_4 = F_24 ( V_15 , V_78 ) ;
if ( V_15 -> V_4 ) {
F_2 ( V_14 L_13 ,
V_15 -> V_4 ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_15 * V_15 ;
int V_79 ;
F_26 ( V_14 L_14 ) ;
V_2 -> V_50 . V_52 . V_80 = - 1 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_50 . V_52 . V_64 ; V_79 ++ ) {
V_15 = V_2 -> V_50 . V_52 . V_15 [ V_79 ] ;
if ( V_15 ) {
if ( ! F_27 () )
F_28 ( V_15 ) ;
else
F_29 ( V_15 ) ;
if ( V_2 -> V_50 . V_52 . V_26 [ V_79 ] ) {
F_30 ( V_2 -> V_50 . V_52 .
V_26 [ V_79 ] ) ;
V_2 -> V_50 . V_52 . V_26 [ V_79 ] =
NULL ;
}
F_31 ( V_15 ) ;
V_2 -> V_50 . V_52 . V_15 [ V_79 ] = NULL ;
}
V_2 -> V_50 . V_52 . V_26 [ V_79 ] = NULL ;
}
F_30 ( V_2 -> V_50 . V_52 . V_15 ) ;
F_30 ( V_2 -> V_50 . V_52 . V_26 ) ;
V_2 -> V_50 . V_52 . V_15 = NULL ;
V_2 -> V_50 . V_52 . V_26 = NULL ;
V_2 -> V_50 . V_52 . V_64 = 0 ;
F_32 ( V_2 , 0 , V_81 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_82 ,
int V_64 , int V_83 ,
int (* V_77) ( struct V_1 * V_2 ,
struct V_15 * V_15 ) )
{
struct V_16 * V_17 = & V_2 -> V_50 . V_69 ;
int V_79 ;
int V_84 , V_85 ;
struct V_15 * V_15 ;
int V_19 ;
F_26 ( V_14 L_15 ) ;
F_25 ( V_2 ) ;
F_33 ( V_2 -> V_86 ,
F_34 ( V_2 -> V_86 ,
V_2 -> V_50 . V_87 ) ) ;
V_2 -> V_50 . V_52 . V_77 = V_77 ;
V_2 -> V_50 . V_52 . V_64 = V_64 ;
V_17 -> V_88 = 0 ;
V_17 -> V_28 = 0 ;
V_17 -> V_29 = 0 ;
V_17 -> V_89 = - 1 ;
V_17 -> V_90 = V_2 -> V_44 << 1 ;
V_17 -> V_91 = ( ( V_2 -> V_40 & V_41 ) ?
V_42 : V_43 ) ;
V_17 -> V_92 = 0 ;
for ( V_79 = 0 ; V_79 < 8 ; V_79 ++ )
V_17 -> V_30 [ V_79 ] = 0 ;
V_2 -> V_50 . V_52 . V_15 = F_35 ( sizeof( void * ) * V_64 ,
V_93 ) ;
if ( ! V_2 -> V_50 . V_52 . V_15 ) {
F_36 ( L_16 ) ;
return - V_94 ;
}
V_2 -> V_50 . V_52 . V_26 =
F_35 ( sizeof( void * ) * V_64 , V_93 ) ;
if ( ! V_2 -> V_50 . V_52 . V_26 ) {
F_36 ( L_17 ) ;
F_30 ( V_2 -> V_50 . V_52 . V_15 ) ;
return - V_94 ;
}
V_2 -> V_50 . V_52 . V_83 = V_83 ;
V_2 -> V_50 . V_52 . V_48 = NULL ;
V_84 = V_82 * V_2 -> V_50 . V_52 . V_83 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_50 . V_52 . V_64 ; V_79 ++ ) {
V_15 = F_37 ( 0 , V_93 ) ;
if ( ! V_15 ) {
F_2 ( V_14
L_18 , V_79 ) ;
F_25 ( V_2 ) ;
return - V_94 ;
}
V_2 -> V_50 . V_52 . V_15 [ V_79 ] = V_15 ;
V_15 -> V_95 = 0 ;
V_2 -> V_50 . V_52 . V_26 [ V_79 ] =
F_35 ( V_84 , V_93 ) ;
if ( ! V_2 -> V_50 . V_52 . V_26 [ V_79 ] ) {
F_2 ( V_14
L_19
L_20 , V_84 , V_79 ,
F_9 () ? L_21 : L_22 ) ;
F_25 ( V_2 ) ;
return - V_94 ;
}
V_85 = F_34 ( V_2 -> V_86 , V_2 -> V_50 . V_87 ) ;
F_38 ( V_15 , V_2 -> V_86 , V_85 ,
V_2 -> V_50 . V_52 . V_26 [ V_79 ] ,
V_84 , F_21 , V_17 ) ;
}
F_39 ( & V_17 -> V_96 ) ;
for ( V_79 = 0 ; V_79 < V_2 -> V_50 . V_52 . V_64 ; V_79 ++ ) {
V_19 = F_24 ( V_2 -> V_50 . V_52 . V_15 [ V_79 ] , V_78 ) ;
if ( V_19 ) {
F_2 ( V_14
L_23 , V_79 ,
V_19 ) ;
F_25 ( V_2 ) ;
return V_19 ;
}
}
F_32 ( V_2 , 1 , V_81 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_2 V_23 , T_2 * V_20 , T_1 V_22 )
{
T_1 V_97 = 0 ;
int V_89 = - 1 ;
switch ( V_23 ) {
case V_98 :
V_89 = 1 ;
break;
case V_99 :
V_89 = 2 ;
break;
default:
break;
}
if ( V_89 < 0 )
return V_97 ;
V_17 -> V_29 = V_23 ;
V_97 =
F_40 ( V_2 , V_17 , V_20 , V_22 ,
V_89 ) ;
return V_97 ;
}
static inline void F_41 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_47 * V_48 )
{
V_48 -> V_53 . V_24 = V_100 ;
V_48 -> V_53 . V_101 ++ ;
F_42 ( & V_48 -> V_53 . V_102 ) ;
V_2 -> V_50 . V_52 . V_48 = NULL ;
F_43 ( & V_48 -> V_53 . V_71 ) ;
F_44 ( & V_48 -> V_53 . V_103 ) ;
}
T_1 F_40 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_2 * V_104 , T_1 V_105 , int V_106 )
{
T_1 V_107 ;
struct V_47 * V_48 ;
T_1 V_108 = V_2 -> V_44 * 2 ;
if ( V_17 -> V_89 == - 1 ) {
F_45 ( V_2 , V_17 ) ;
}
if ( V_17 -> V_89 != V_106 )
V_17 -> V_92 = 0 ;
V_48 = V_2 -> V_50 . V_52 . V_48 ;
V_17 -> V_89 = V_106 ;
V_107 = V_17 -> V_90 ;
if ( V_107 > V_105 )
V_107 = V_105 ;
if ( V_17 -> V_92 >= V_17 -> V_91 ) {
V_17 -> V_90 -= V_107 ;
V_17 -> V_28 =
( V_17 -> V_90 == 0 ) ? 0 : 1 ;
return 0 ;
}
V_17 -> V_28 = 1 ;
if ( ! V_48 ) {
V_17 -> V_90 -= V_107 ;
V_17 -> V_28 =
( V_17 -> V_90 == 0 ) ? 0 : 1 ;
return V_107 ;
}
F_46 ( V_2 , V_17 , V_104 , V_107 ) ;
V_17 -> V_88 += V_107 ;
V_17 -> V_90 -= V_107 ;
if ( V_17 -> V_90 == 0 ) {
V_17 -> V_90 = V_108 ;
V_17 -> V_92 ++ ;
V_17 -> V_28 = 0 ;
if ( F_47 ( V_2 , V_17 ) && V_48 ) {
F_41 ( V_2 , V_17 , V_48 ) ;
V_17 -> V_88 = 0 ;
V_17 -> V_92 = 0 ;
F_45 ( V_2 , V_17 ) ;
}
}
return V_107 ;
}
static inline void F_48 ( struct V_16 * V_17 ,
struct V_47 * * V_48 )
{
struct V_73 * V_74 =
F_15 ( V_17 , struct V_73 , V_69 ) ;
struct V_1 * V_2 = F_15 ( V_74 , struct V_1 , V_50 ) ;
char * V_109 ;
if ( F_49 ( & V_17 -> V_72 ) ) {
F_2 ( V_14 L_24 ) ;
V_2 -> V_50 . V_52 . V_48 = NULL ;
* V_48 = NULL ;
return;
}
* V_48 = F_50 ( V_17 -> V_72 . V_110 , struct V_47 , V_53 . V_71 ) ;
V_109 = F_51 ( & ( * V_48 ) -> V_53 ) ;
memset ( V_109 , 0 , ( * V_48 ) -> V_53 . V_35 ) ;
V_2 -> V_50 . V_52 . V_48 = * V_48 ;
return;
}
void F_45 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_47 * V_48 ;
V_48 = V_2 -> V_50 . V_52 . V_48 ;
if ( V_48 == NULL ) {
F_48 ( V_17 , & V_48 ) ;
V_17 -> V_88 = 0 ;
V_17 -> V_89 = - 1 ;
}
V_17 -> V_90 = V_2 -> V_44 << 1 ;
V_17 -> V_92 = 0 ;
}
int F_46 ( struct V_1 * V_2 , struct V_16 * V_17 ,
T_2 * V_20 , T_1 V_107 )
{
T_2 * V_111 = NULL ;
T_1 V_112 = 0 ;
struct V_47 * V_48 ;
T_1 V_108 = V_2 -> V_44 << 1 ;
void * V_113 ;
int V_114 , V_115 ;
V_48 = V_2 -> V_50 . V_52 . V_48 ;
if ( V_48 == NULL )
return - V_61 ;
V_111 = F_51 ( & V_48 -> V_53 ) ;
if ( V_17 -> V_90 != V_108 ) {
V_112 =
V_108 - V_17 -> V_90 ;
}
V_114 = ( V_17 -> V_92 * V_108 ) +
V_112 ;
if ( V_17 -> V_89 == 2 ) {
V_114 += ( V_2 -> V_44 * 2 * V_17 -> V_91 ) ;
}
V_113 = V_111 + V_114 ;
V_115 = V_17 -> V_90 > V_107 ?
V_107 : V_17 -> V_90 ;
memcpy ( V_113 , V_20 , V_115 ) ;
return 0 ;
}
T_2 F_47 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
T_1 V_39 = 0 ;
V_39 = ( ( V_2 -> V_40 & V_41 ) ?
V_42 : V_43 ) ;
if ( V_17 -> V_92 == V_39 && V_17 -> V_89 == 2 )
return 1 ;
else
return 0 ;
}
