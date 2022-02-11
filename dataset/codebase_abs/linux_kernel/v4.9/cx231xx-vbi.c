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
F_2 ( V_2 -> V_2 ,
L_10 , V_4 , V_5 ) ;
} else {
F_2 ( V_2 -> V_2 ,
L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static inline int F_3 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
int V_18 = 1 ;
unsigned char * V_19 ;
T_1 V_20 = 0 , V_21 = 0 ;
T_2 V_22 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_23 & V_24 )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
V_19 = V_14 -> V_25 ;
V_21 = V_14 -> V_26 ;
if ( V_21 > 0 ) {
V_20 = 0 ;
if ( V_16 -> V_27 ) {
V_22 = V_16 -> V_28 ;
} else {
V_22 = F_4 ( V_19 ,
V_16 -> V_29 ,
& V_20 ) ;
}
V_22 &= 0xF0 ;
if ( V_22 ) {
V_20 += F_5 ( V_2 , V_16 ,
V_22 ,
V_19 + V_20 ,
V_21 - V_20 ) ;
}
V_16 -> V_27 = 0 ;
while ( V_20 < V_21 ) {
T_1 V_30 = 0 ;
V_22 = F_6 (
V_19 + V_20 ,
V_21 - V_20 ,
& V_30 ) ;
V_20 += V_30 ;
V_22 &= 0xF0 ;
if ( V_22 && ( V_20 < V_21 ) ) {
V_20 += F_5 ( V_2 ,
V_16 , V_22 ,
V_19 + V_20 ,
V_21 - V_20 ) ;
}
}
memcpy ( V_16 -> V_29 , V_19 + V_21 - 4 , 4 ) ;
V_20 = 0 ;
}
return V_18 ;
}
static int
F_7 ( struct V_31 * V_32 , unsigned int * V_33 ,
unsigned int * V_34 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_1 * V_2 = V_36 -> V_2 ;
T_1 V_38 = 0 ;
V_38 = ( ( V_2 -> V_39 & V_40 ) ?
V_41 : V_42 ) ;
* V_34 = ( V_2 -> V_43 * V_38 * 2 * 2 ) ;
if ( 0 == * V_33 )
* V_33 = V_44 ;
if ( * V_33 < V_45 )
* V_33 = V_45 ;
return 0 ;
}
static void F_8 ( struct V_31 * V_32 , struct V_46 * V_47 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_1 * V_2 = V_36 -> V_2 ;
unsigned long V_48 = 0 ;
F_9 ( F_10 () ) ;
F_11 ( & V_2 -> V_49 . V_50 , V_48 ) ;
if ( V_2 -> V_49 . V_51 . V_47 == V_47 )
V_2 -> V_49 . V_51 . V_47 = NULL ;
F_12 ( & V_2 -> V_49 . V_50 , V_48 ) ;
F_13 ( & V_47 -> V_52 ) ;
V_47 -> V_52 . V_23 = V_53 ;
}
static int
F_14 ( struct V_31 * V_32 , struct V_54 * V_52 ,
enum V_55 V_56 )
{
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_46 * V_47 =
F_15 ( V_52 , struct V_46 , V_52 ) ;
struct V_1 * V_2 = V_36 -> V_2 ;
int V_18 = 0 , V_57 = 0 ;
T_1 V_38 = 0 ;
V_38 = ( ( V_2 -> V_39 & V_40 ) ?
V_41 : V_42 ) ;
V_47 -> V_52 . V_34 = ( ( V_2 -> V_43 << 1 ) * V_38 * 2 ) ;
if ( 0 != V_47 -> V_52 . V_58 && V_47 -> V_52 . V_59 < V_47 -> V_52 . V_34 )
return - V_60 ;
V_47 -> V_52 . V_43 = V_2 -> V_43 ;
V_47 -> V_52 . V_38 = V_38 ;
V_47 -> V_52 . V_56 = V_56 ;
V_47 -> V_52 . V_56 = V_61 ;
if ( V_53 == V_47 -> V_52 . V_23 ) {
V_18 = F_16 ( V_32 , & V_47 -> V_52 , NULL ) ;
if ( V_18 < 0 )
goto V_62;
}
if ( ! V_2 -> V_49 . V_51 . V_63 )
V_57 = 1 ;
if ( V_57 ) {
V_18 = F_17 ( V_2 , V_64 ,
V_65 ,
V_2 -> V_49 . V_66 [ 0 ] ,
F_3 ) ;
if ( V_18 < 0 )
goto V_62;
}
V_47 -> V_52 . V_23 = V_67 ;
return 0 ;
V_62:
F_8 ( V_32 , V_47 ) ;
return V_18 ;
}
static void
F_18 ( struct V_31 * V_32 , struct V_54 * V_52 )
{
struct V_46 * V_47 =
F_15 ( V_52 , struct V_46 , V_52 ) ;
struct V_35 * V_36 = V_32 -> V_37 ;
struct V_1 * V_2 = V_36 -> V_2 ;
struct V_15 * V_68 = & V_2 -> V_49 . V_68 ;
V_47 -> V_52 . V_23 = V_69 ;
F_19 ( & V_47 -> V_52 . V_70 , & V_68 -> V_71 ) ;
}
static void F_20 ( struct V_31 * V_32 ,
struct V_54 * V_52 )
{
struct V_46 * V_47 =
F_15 ( V_52 , struct V_46 , V_52 ) ;
F_8 ( V_32 , V_47 ) ;
}
static void F_21 ( struct V_14 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
struct V_72 * V_73 =
F_15 ( V_16 , struct V_72 , V_68 ) ;
struct V_1 * V_2 = F_15 ( V_73 , struct V_1 , V_49 ) ;
switch ( V_14 -> V_4 ) {
case 0 :
case - V_74 :
break;
case - V_7 :
case - V_6 :
case - V_75 :
return;
default:
F_2 ( V_2 -> V_2 ,
L_12 , V_14 -> V_4 ) ;
break;
}
F_22 ( & V_2 -> V_49 . V_50 ) ;
V_2 -> V_49 . V_51 . V_76 ( V_2 , V_14 ) ;
F_23 ( & V_2 -> V_49 . V_50 ) ;
V_14 -> V_4 = 0 ;
V_14 -> V_4 = F_24 ( V_14 , V_77 ) ;
if ( V_14 -> V_4 ) {
F_2 ( V_2 -> V_2 , L_13 ,
V_14 -> V_4 ) ;
}
}
void F_25 ( struct V_1 * V_2 )
{
struct V_14 * V_14 ;
int V_78 ;
F_26 ( V_2 -> V_2 , L_14 ) ;
V_2 -> V_49 . V_51 . V_79 = - 1 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_49 . V_51 . V_63 ; V_78 ++ ) {
V_14 = V_2 -> V_49 . V_51 . V_14 [ V_78 ] ;
if ( V_14 ) {
if ( ! F_27 () )
F_28 ( V_14 ) ;
else
F_29 ( V_14 ) ;
if ( V_2 -> V_49 . V_51 . V_25 [ V_78 ] ) {
F_30 ( V_2 -> V_49 . V_51 .
V_25 [ V_78 ] ) ;
V_2 -> V_49 . V_51 . V_25 [ V_78 ] =
NULL ;
}
F_31 ( V_14 ) ;
V_2 -> V_49 . V_51 . V_14 [ V_78 ] = NULL ;
}
V_2 -> V_49 . V_51 . V_25 [ V_78 ] = NULL ;
}
F_30 ( V_2 -> V_49 . V_51 . V_14 ) ;
F_30 ( V_2 -> V_49 . V_51 . V_25 ) ;
V_2 -> V_49 . V_51 . V_14 = NULL ;
V_2 -> V_49 . V_51 . V_25 = NULL ;
V_2 -> V_49 . V_51 . V_63 = 0 ;
F_32 ( V_2 , 0 , V_80 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_81 ,
int V_63 , int V_82 ,
int (* V_76) ( struct V_1 * V_2 ,
struct V_14 * V_14 ) )
{
struct V_15 * V_16 = & V_2 -> V_49 . V_68 ;
int V_78 ;
int V_83 , V_84 ;
struct V_14 * V_14 ;
int V_18 ;
F_26 ( V_2 -> V_2 , L_15 ) ;
F_25 ( V_2 ) ;
F_33 ( V_2 -> V_85 ,
F_34 ( V_2 -> V_85 ,
V_2 -> V_49 . V_86 ) ) ;
V_2 -> V_49 . V_51 . V_76 = V_76 ;
V_2 -> V_49 . V_51 . V_63 = V_63 ;
V_16 -> V_87 = 0 ;
V_16 -> V_27 = 0 ;
V_16 -> V_28 = 0 ;
V_16 -> V_88 = - 1 ;
V_16 -> V_89 = V_2 -> V_43 << 1 ;
V_16 -> V_90 = ( ( V_2 -> V_39 & V_40 ) ?
V_41 : V_42 ) ;
V_16 -> V_91 = 0 ;
for ( V_78 = 0 ; V_78 < 8 ; V_78 ++ )
V_16 -> V_29 [ V_78 ] = 0 ;
V_2 -> V_49 . V_51 . V_14 = F_35 ( sizeof( void * ) * V_63 ,
V_92 ) ;
if ( ! V_2 -> V_49 . V_51 . V_14 ) {
F_2 ( V_2 -> V_2 ,
L_16 ) ;
return - V_93 ;
}
V_2 -> V_49 . V_51 . V_25 =
F_35 ( sizeof( void * ) * V_63 , V_92 ) ;
if ( ! V_2 -> V_49 . V_51 . V_25 ) {
F_2 ( V_2 -> V_2 ,
L_17 ) ;
F_30 ( V_2 -> V_49 . V_51 . V_14 ) ;
return - V_93 ;
}
V_2 -> V_49 . V_51 . V_82 = V_82 ;
V_2 -> V_49 . V_51 . V_47 = NULL ;
V_83 = V_81 * V_2 -> V_49 . V_51 . V_82 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_49 . V_51 . V_63 ; V_78 ++ ) {
V_14 = F_36 ( 0 , V_92 ) ;
if ( ! V_14 ) {
F_25 ( V_2 ) ;
return - V_93 ;
}
V_2 -> V_49 . V_51 . V_14 [ V_78 ] = V_14 ;
V_14 -> V_94 = 0 ;
V_2 -> V_49 . V_51 . V_25 [ V_78 ] =
F_35 ( V_83 , V_92 ) ;
if ( ! V_2 -> V_49 . V_51 . V_25 [ V_78 ] ) {
F_2 ( V_2 -> V_2 ,
L_18 ,
V_83 , V_78 ,
F_10 () ? L_19 : L_20 ) ;
F_25 ( V_2 ) ;
return - V_93 ;
}
V_84 = F_34 ( V_2 -> V_85 , V_2 -> V_49 . V_86 ) ;
F_37 ( V_14 , V_2 -> V_85 , V_84 ,
V_2 -> V_49 . V_51 . V_25 [ V_78 ] ,
V_83 , F_21 , V_16 ) ;
}
F_38 ( & V_16 -> V_95 ) ;
for ( V_78 = 0 ; V_78 < V_2 -> V_49 . V_51 . V_63 ; V_78 ++ ) {
V_18 = F_24 ( V_2 -> V_49 . V_51 . V_14 [ V_78 ] , V_77 ) ;
if ( V_18 ) {
F_2 ( V_2 -> V_2 ,
L_21 , V_78 , V_18 ) ;
F_25 ( V_2 ) ;
return V_18 ;
}
}
F_32 ( V_2 , 1 , V_80 ) ;
return 0 ;
}
T_1 F_5 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_2 V_22 , T_2 * V_19 , T_1 V_21 )
{
T_1 V_96 = 0 ;
int V_88 = - 1 ;
switch ( V_22 ) {
case V_97 :
V_88 = 1 ;
break;
case V_98 :
V_88 = 2 ;
break;
default:
break;
}
if ( V_88 < 0 )
return V_96 ;
V_16 -> V_28 = V_22 ;
V_96 =
F_39 ( V_2 , V_16 , V_19 , V_21 ,
V_88 ) ;
return V_96 ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_15 * V_16 ,
struct V_46 * V_47 )
{
V_47 -> V_52 . V_23 = V_99 ;
V_47 -> V_52 . V_100 ++ ;
F_41 ( & V_47 -> V_52 . V_101 ) ;
V_2 -> V_49 . V_51 . V_47 = NULL ;
F_42 ( & V_47 -> V_52 . V_70 ) ;
F_43 ( & V_47 -> V_52 . V_102 ) ;
}
T_1 F_39 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_2 * V_103 , T_1 V_104 , int V_105 )
{
T_1 V_106 ;
struct V_46 * V_47 ;
T_1 V_107 = V_2 -> V_43 * 2 ;
if ( V_16 -> V_88 == - 1 ) {
F_44 ( V_2 , V_16 ) ;
}
if ( V_16 -> V_88 != V_105 )
V_16 -> V_91 = 0 ;
V_47 = V_2 -> V_49 . V_51 . V_47 ;
V_16 -> V_88 = V_105 ;
V_106 = V_16 -> V_89 ;
if ( V_106 > V_104 )
V_106 = V_104 ;
if ( V_16 -> V_91 >= V_16 -> V_90 ) {
V_16 -> V_89 -= V_106 ;
V_16 -> V_27 =
( V_16 -> V_89 == 0 ) ? 0 : 1 ;
return 0 ;
}
V_16 -> V_27 = 1 ;
if ( ! V_47 ) {
V_16 -> V_89 -= V_106 ;
V_16 -> V_27 =
( V_16 -> V_89 == 0 ) ? 0 : 1 ;
return V_106 ;
}
F_45 ( V_2 , V_16 , V_103 , V_106 ) ;
V_16 -> V_87 += V_106 ;
V_16 -> V_89 -= V_106 ;
if ( V_16 -> V_89 == 0 ) {
V_16 -> V_89 = V_107 ;
V_16 -> V_91 ++ ;
V_16 -> V_27 = 0 ;
if ( F_46 ( V_2 , V_16 ) && V_47 ) {
F_40 ( V_2 , V_16 , V_47 ) ;
V_16 -> V_87 = 0 ;
V_16 -> V_91 = 0 ;
F_44 ( V_2 , V_16 ) ;
}
}
return V_106 ;
}
static inline void F_47 ( struct V_15 * V_16 ,
struct V_46 * * V_47 )
{
struct V_72 * V_73 =
F_15 ( V_16 , struct V_72 , V_68 ) ;
struct V_1 * V_2 = F_15 ( V_73 , struct V_1 , V_49 ) ;
char * V_108 ;
if ( F_48 ( & V_16 -> V_71 ) ) {
F_2 ( V_2 -> V_2 , L_22 ) ;
V_2 -> V_49 . V_51 . V_47 = NULL ;
* V_47 = NULL ;
return;
}
* V_47 = F_49 ( V_16 -> V_71 . V_109 , struct V_46 , V_52 . V_70 ) ;
V_108 = F_50 ( & ( * V_47 ) -> V_52 ) ;
memset ( V_108 , 0 , ( * V_47 ) -> V_52 . V_34 ) ;
V_2 -> V_49 . V_51 . V_47 = * V_47 ;
return;
}
void F_44 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_46 * V_47 ;
V_47 = V_2 -> V_49 . V_51 . V_47 ;
if ( V_47 == NULL ) {
F_47 ( V_16 , & V_47 ) ;
V_16 -> V_87 = 0 ;
V_16 -> V_88 = - 1 ;
}
V_16 -> V_89 = V_2 -> V_43 << 1 ;
V_16 -> V_91 = 0 ;
}
int F_45 ( struct V_1 * V_2 , struct V_15 * V_16 ,
T_2 * V_19 , T_1 V_106 )
{
T_2 * V_110 = NULL ;
T_1 V_111 = 0 ;
struct V_46 * V_47 ;
T_1 V_107 = V_2 -> V_43 << 1 ;
void * V_112 ;
int V_113 , V_114 ;
V_47 = V_2 -> V_49 . V_51 . V_47 ;
if ( V_47 == NULL )
return - V_60 ;
V_110 = F_50 ( & V_47 -> V_52 ) ;
if ( V_16 -> V_89 != V_107 ) {
V_111 =
V_107 - V_16 -> V_89 ;
}
V_113 = ( V_16 -> V_91 * V_107 ) +
V_111 ;
if ( V_16 -> V_88 == 2 ) {
V_113 += ( V_2 -> V_43 * 2 * V_16 -> V_90 ) ;
}
V_112 = V_110 + V_113 ;
V_114 = V_16 -> V_89 > V_106 ?
V_106 : V_16 -> V_89 ;
memcpy ( V_112 , V_19 , V_114 ) ;
return 0 ;
}
T_2 F_46 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
T_1 V_38 = 0 ;
V_38 = ( ( V_2 -> V_39 & V_40 ) ?
V_41 : V_42 ) ;
if ( V_16 -> V_91 == V_38 && V_16 -> V_88 == 2 )
return 1 ;
else
return 0 ;
}
