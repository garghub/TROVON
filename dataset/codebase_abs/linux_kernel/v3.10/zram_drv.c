static void F_1 ( struct V_1 * V_1 , T_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_1 -> V_4 ) ;
* V_2 = * V_2 + V_3 ;
F_3 ( & V_1 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_1 , T_1 * V_2 , T_1 V_5 )
{
F_2 ( & V_1 -> V_4 ) ;
* V_2 = * V_2 - V_5 ;
F_3 ( & V_1 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_1 * V_2 )
{
F_1 ( V_1 , V_2 , 1 ) ;
}
static int F_6 ( struct V_6 * V_7 , T_2 V_8 ,
enum V_9 V_10 )
{
return V_7 -> V_11 [ V_8 ] . V_12 & F_7 ( V_10 ) ;
}
static void F_8 ( struct V_6 * V_7 , T_2 V_8 ,
enum V_9 V_10 )
{
V_7 -> V_11 [ V_8 ] . V_12 |= F_7 ( V_10 ) ;
}
static void F_9 ( struct V_6 * V_7 , T_2 V_8 ,
enum V_9 V_10 )
{
V_7 -> V_11 [ V_8 ] . V_12 &= ~ F_7 ( V_10 ) ;
}
static int F_10 ( void * V_13 )
{
unsigned int V_14 ;
unsigned long * V_15 ;
V_15 = ( unsigned long * ) V_13 ;
for ( V_14 = 0 ; V_14 != V_16 / sizeof( * V_15 ) ; V_14 ++ ) {
if ( V_15 [ V_14 ] )
return 0 ;
}
return 1 ;
}
static void F_11 ( struct V_1 * V_1 , T_3 V_8 )
{
struct V_6 * V_7 = V_1 -> V_7 ;
unsigned long V_17 = V_7 -> V_11 [ V_8 ] . V_17 ;
T_4 V_18 = V_7 -> V_11 [ V_8 ] . V_18 ;
if ( F_12 ( ! V_17 ) ) {
if ( F_6 ( V_7 , V_8 , V_19 ) ) {
F_9 ( V_7 , V_8 , V_19 ) ;
V_1 -> V_20 . V_21 -- ;
}
return;
}
if ( F_12 ( V_18 > V_22 ) )
V_1 -> V_20 . V_23 -- ;
F_13 ( V_7 -> V_24 , V_17 ) ;
if ( V_18 <= V_16 / 2 )
V_1 -> V_20 . V_25 -- ;
F_4 ( V_1 , & V_1 -> V_20 . V_26 ,
V_7 -> V_11 [ V_8 ] . V_18 ) ;
V_1 -> V_20 . V_27 -- ;
V_7 -> V_11 [ V_8 ] . V_17 = 0 ;
V_7 -> V_11 [ V_8 ] . V_18 = 0 ;
}
static void F_14 ( struct V_28 * V_29 )
{
struct V_15 * V_15 = V_29 -> V_30 ;
void * V_31 ;
V_31 = F_15 ( V_15 ) ;
memset ( V_31 + V_29 -> V_32 , 0 , V_29 -> V_33 ) ;
F_16 ( V_31 ) ;
F_17 ( V_15 ) ;
}
static inline int F_18 ( struct V_28 * V_29 )
{
return V_29 -> V_33 != V_16 ;
}
static int F_19 ( struct V_1 * V_1 , char * V_34 , T_2 V_8 )
{
int V_35 = V_36 ;
T_3 V_37 = V_16 ;
unsigned char * V_38 ;
struct V_6 * V_7 = V_1 -> V_7 ;
unsigned long V_17 = V_7 -> V_11 [ V_8 ] . V_17 ;
if ( ! V_17 || F_6 ( V_7 , V_8 , V_19 ) ) {
memset ( V_34 , 0 , V_16 ) ;
return 0 ;
}
V_38 = F_20 ( V_7 -> V_24 , V_17 , V_39 ) ;
if ( V_7 -> V_11 [ V_8 ] . V_18 == V_16 )
memcpy ( V_34 , V_38 , V_16 ) ;
else
V_35 = F_21 ( V_38 , V_7 -> V_11 [ V_8 ] . V_18 ,
V_34 , & V_37 ) ;
F_22 ( V_7 -> V_24 , V_17 ) ;
if ( F_12 ( V_35 != V_36 ) ) {
F_23 ( L_1 , V_35 , V_8 ) ;
F_5 ( V_1 , & V_1 -> V_20 . V_40 ) ;
return V_35 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , struct V_28 * V_29 ,
T_2 V_8 , int V_41 , struct V_42 * V_42 )
{
int V_35 ;
struct V_15 * V_15 ;
unsigned char * V_31 , * V_43 = NULL ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_15 = V_29 -> V_30 ;
if ( F_12 ( ! V_7 -> V_11 [ V_8 ] . V_17 ) ||
F_6 ( V_7 , V_8 , V_19 ) ) {
F_14 ( V_29 ) ;
return 0 ;
}
if ( F_18 ( V_29 ) )
V_43 = F_25 ( V_16 , V_44 ) ;
V_31 = F_15 ( V_15 ) ;
if ( ! F_18 ( V_29 ) )
V_43 = V_31 ;
if ( ! V_43 ) {
F_26 ( L_2 ) ;
V_35 = - V_45 ;
goto V_46;
}
V_35 = F_19 ( V_1 , V_43 , V_8 ) ;
if ( F_12 ( V_35 != V_36 ) )
goto V_46;
if ( F_18 ( V_29 ) )
memcpy ( V_31 + V_29 -> V_32 , V_43 + V_41 ,
V_29 -> V_33 ) ;
F_17 ( V_15 ) ;
V_35 = 0 ;
V_46:
F_16 ( V_31 ) ;
if ( F_18 ( V_29 ) )
F_27 ( V_43 ) ;
return V_35 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_28 * V_29 , T_2 V_8 ,
int V_41 )
{
int V_35 = 0 ;
T_3 V_37 ;
unsigned long V_17 ;
struct V_15 * V_15 ;
unsigned char * V_31 , * V_38 , * V_47 , * V_43 = NULL ;
struct V_6 * V_7 = V_1 -> V_7 ;
V_15 = V_29 -> V_30 ;
V_47 = V_7 -> V_48 ;
if ( F_18 ( V_29 ) ) {
V_43 = F_25 ( V_16 , V_44 ) ;
if ( ! V_43 ) {
V_35 = - V_45 ;
goto V_49;
}
V_35 = F_19 ( V_1 , V_43 , V_8 ) ;
if ( V_35 )
goto V_49;
}
if ( V_7 -> V_11 [ V_8 ] . V_17 ||
F_6 ( V_7 , V_8 , V_19 ) )
F_11 ( V_1 , V_8 ) ;
V_31 = F_15 ( V_15 ) ;
if ( F_18 ( V_29 ) ) {
memcpy ( V_43 + V_41 , V_31 + V_29 -> V_32 ,
V_29 -> V_33 ) ;
F_16 ( V_31 ) ;
V_31 = NULL ;
} else {
V_43 = V_31 ;
}
if ( F_10 ( V_43 ) ) {
F_16 ( V_31 ) ;
if ( F_18 ( V_29 ) )
F_27 ( V_43 ) ;
V_1 -> V_20 . V_21 ++ ;
F_8 ( V_7 , V_8 , V_19 ) ;
V_35 = 0 ;
goto V_49;
}
V_35 = F_29 ( V_43 , V_16 , V_47 , & V_37 ,
V_7 -> V_50 ) ;
if ( ! F_18 ( V_29 ) ) {
F_16 ( V_31 ) ;
V_31 = NULL ;
V_43 = NULL ;
}
if ( F_12 ( V_35 != V_36 ) ) {
F_23 ( L_3 , V_35 ) ;
goto V_49;
}
if ( F_12 ( V_37 > V_22 ) ) {
V_1 -> V_20 . V_23 ++ ;
V_37 = V_16 ;
V_47 = NULL ;
if ( F_18 ( V_29 ) )
V_47 = V_43 ;
}
V_17 = F_30 ( V_7 -> V_24 , V_37 ) ;
if ( ! V_17 ) {
F_26 ( L_4
L_5 , V_8 , V_37 ) ;
V_35 = - V_45 ;
goto V_49;
}
V_38 = F_20 ( V_7 -> V_24 , V_17 , V_51 ) ;
if ( ( V_37 == V_16 ) && ! F_18 ( V_29 ) )
V_47 = F_15 ( V_15 ) ;
memcpy ( V_38 , V_47 , V_37 ) ;
if ( ( V_37 == V_16 ) && ! F_18 ( V_29 ) )
F_16 ( V_47 ) ;
F_22 ( V_7 -> V_24 , V_17 ) ;
V_7 -> V_11 [ V_8 ] . V_17 = V_17 ;
V_7 -> V_11 [ V_8 ] . V_18 = V_37 ;
F_1 ( V_1 , & V_1 -> V_20 . V_26 , V_37 ) ;
V_1 -> V_20 . V_27 ++ ;
if ( V_37 <= V_16 / 2 )
V_1 -> V_20 . V_25 ++ ;
V_49:
if ( F_18 ( V_29 ) )
F_27 ( V_43 ) ;
if ( V_35 )
F_5 ( V_1 , & V_1 -> V_20 . V_52 ) ;
return V_35 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_28 * V_29 , T_2 V_8 ,
int V_41 , struct V_42 * V_42 , int V_53 )
{
int V_35 ;
if ( V_53 == V_54 ) {
F_32 ( & V_1 -> V_55 ) ;
V_35 = F_24 ( V_1 , V_29 , V_8 , V_41 , V_42 ) ;
F_33 ( & V_1 -> V_55 ) ;
} else {
F_34 ( & V_1 -> V_55 ) ;
V_35 = F_28 ( V_1 , V_29 , V_8 , V_41 ) ;
F_35 ( & V_1 -> V_55 ) ;
}
return V_35 ;
}
static void F_36 ( T_2 * V_8 , int * V_41 , struct V_28 * V_29 )
{
if ( * V_41 + V_29 -> V_33 >= V_16 )
( * V_8 ) ++ ;
* V_41 = ( * V_41 + V_29 -> V_33 ) % V_16 ;
}
static void F_37 ( struct V_1 * V_1 , struct V_42 * V_42 , int V_53 )
{
int V_56 , V_41 ;
T_2 V_8 ;
struct V_28 * V_29 ;
switch ( V_53 ) {
case V_54 :
F_5 ( V_1 , & V_1 -> V_20 . V_57 ) ;
break;
case V_58 :
F_5 ( V_1 , & V_1 -> V_20 . V_59 ) ;
break;
}
V_8 = V_42 -> V_60 >> V_61 ;
V_41 = ( V_42 -> V_60 & ( V_62 - 1 ) ) << V_63 ;
F_38 (bvec, bio, i) {
int V_64 = V_16 - V_41 ;
if ( V_29 -> V_33 > V_64 ) {
struct V_28 V_65 ;
V_65 . V_30 = V_29 -> V_30 ;
V_65 . V_33 = V_64 ;
V_65 . V_32 = V_29 -> V_32 ;
if ( F_31 ( V_1 , & V_65 , V_8 , V_41 , V_42 , V_53 ) < 0 )
goto V_49;
V_65 . V_33 = V_29 -> V_33 - V_64 ;
V_65 . V_32 += V_64 ;
if ( F_31 ( V_1 , & V_65 , V_8 + 1 , 0 , V_42 , V_53 ) < 0 )
goto V_49;
} else
if ( F_31 ( V_1 , V_29 , V_8 , V_41 , V_42 , V_53 )
< 0 )
goto V_49;
F_36 ( & V_8 , & V_41 , V_29 ) ;
}
F_39 ( V_66 , & V_42 -> V_67 ) ;
F_40 ( V_42 , 0 ) ;
return;
V_49:
F_41 ( V_42 ) ;
}
static inline int F_42 ( struct V_1 * V_1 , struct V_42 * V_42 )
{
if ( F_12 (
( V_42 -> V_60 >= ( V_1 -> V_68 >> V_63 ) ) ||
( V_42 -> V_60 & ( V_69 - 1 ) ) ||
( V_42 -> V_70 & ( V_71 - 1 ) ) ) ) {
return 0 ;
}
return 1 ;
}
static void F_43 ( struct V_72 * V_73 , struct V_42 * V_42 )
{
struct V_1 * V_1 = V_73 -> V_74 ;
F_32 ( & V_1 -> V_75 ) ;
if ( F_12 ( ! V_1 -> V_76 ) )
goto error;
if ( ! F_42 ( V_1 , V_42 ) ) {
F_5 ( V_1 , & V_1 -> V_20 . V_77 ) ;
goto error;
}
F_37 ( V_1 , V_42 , F_44 ( V_42 ) ) ;
F_33 ( & V_1 -> V_75 ) ;
return;
error:
F_33 ( & V_1 -> V_75 ) ;
F_41 ( V_42 ) ;
}
static void F_45 ( struct V_1 * V_1 )
{
T_3 V_8 ;
struct V_6 * V_7 ;
if ( ! V_1 -> V_76 )
return;
V_7 = V_1 -> V_7 ;
V_1 -> V_76 = 0 ;
for ( V_8 = 0 ; V_8 < V_1 -> V_68 > > V_78 ; V_8 ++ ) {
unsigned long V_17 = V_7 -> V_11 [ V_8 ] . V_17 ;
if ( ! V_17 )
continue;
F_13 ( V_7 -> V_24 , V_17 ) ;
}
F_46 ( V_1 -> V_7 ) ;
V_1 -> V_7 = NULL ;
memset ( & V_1 -> V_20 , 0 , sizeof( V_1 -> V_20 ) ) ;
V_1 -> V_68 = 0 ;
F_47 ( V_1 -> V_79 , 0 ) ;
}
void F_48 ( struct V_1 * V_1 )
{
F_34 ( & V_1 -> V_75 ) ;
F_45 ( V_1 ) ;
F_35 ( & V_1 -> V_75 ) ;
}
void F_46 ( struct V_6 * V_7 )
{
F_49 ( V_7 -> V_24 ) ;
F_27 ( V_7 -> V_50 ) ;
F_50 ( ( unsigned long ) V_7 -> V_48 , 1 ) ;
F_51 ( V_7 -> V_11 ) ;
F_27 ( V_7 ) ;
}
struct V_6 * F_52 ( T_1 V_68 )
{
T_3 V_80 ;
struct V_6 * V_7 = F_25 ( sizeof( * V_7 ) , V_81 ) ;
if ( ! V_7 )
goto V_49;
V_7 -> V_50 = F_53 ( V_82 , V_81 ) ;
if ( ! V_7 -> V_50 )
goto V_83;
V_7 -> V_48 =
( void * ) F_54 ( V_81 | V_84 , 1 ) ;
if ( ! V_7 -> V_48 ) {
F_23 ( L_6 ) ;
goto V_85;
}
V_80 = V_68 >> V_78 ;
V_7 -> V_11 = F_55 ( V_80 * sizeof( * V_7 -> V_11 ) ) ;
if ( ! V_7 -> V_11 ) {
F_23 ( L_7 ) ;
goto V_86;
}
V_7 -> V_24 = F_56 ( V_44 | V_87 ) ;
if ( ! V_7 -> V_24 ) {
F_23 ( L_8 ) ;
goto V_88;
}
return V_7 ;
V_88:
F_51 ( V_7 -> V_11 ) ;
V_86:
F_50 ( ( unsigned long ) V_7 -> V_48 , 1 ) ;
V_85:
F_27 ( V_7 -> V_50 ) ;
V_83:
F_27 ( V_7 ) ;
V_7 = NULL ;
V_49:
return V_7 ;
}
void F_57 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
if ( V_1 -> V_68 > 2 * ( V_89 << V_78 ) ) {
F_26 (
L_9
L_10
L_11
L_12
L_13
L_14
L_15
L_16 ,
( V_89 << V_78 ) >> 10 , V_1 -> V_68 >> 10
) ;
}
F_58 ( V_90 , V_1 -> V_79 -> V_73 ) ;
V_1 -> V_7 = V_7 ;
V_1 -> V_76 = 1 ;
F_59 ( L_17 ) ;
}
static void F_60 ( struct V_91 * V_92 ,
unsigned long V_8 )
{
struct V_1 * V_1 ;
V_1 = V_92 -> V_93 -> V_94 ;
F_11 ( V_1 , V_8 ) ;
F_5 ( V_1 , & V_1 -> V_20 . V_95 ) ;
}
static int F_61 ( struct V_1 * V_1 , int V_96 )
{
int V_35 = 0 ;
F_62 ( & V_1 -> V_55 ) ;
F_62 ( & V_1 -> V_75 ) ;
F_63 ( & V_1 -> V_4 ) ;
V_1 -> V_73 = F_64 ( V_81 ) ;
if ( ! V_1 -> V_73 ) {
F_23 ( L_18 ,
V_96 ) ;
V_35 = - V_45 ;
goto V_49;
}
F_65 ( V_1 -> V_73 , F_43 ) ;
V_1 -> V_73 -> V_74 = V_1 ;
V_1 -> V_79 = F_66 ( 1 ) ;
if ( ! V_1 -> V_79 ) {
F_67 ( V_1 -> V_73 ) ;
F_68 ( L_19 ,
V_96 ) ;
V_35 = - V_45 ;
goto V_49;
}
V_1 -> V_79 -> V_97 = V_98 ;
V_1 -> V_79 -> V_99 = V_96 ;
V_1 -> V_79 -> V_100 = & V_101 ;
V_1 -> V_79 -> V_73 = V_1 -> V_73 ;
V_1 -> V_79 -> V_94 = V_1 ;
snprintf ( V_1 -> V_79 -> V_102 , 16 , L_20 , V_96 ) ;
F_47 ( V_1 -> V_79 , 0 ) ;
F_69 ( V_1 -> V_79 -> V_73 , V_16 ) ;
F_70 ( V_1 -> V_79 -> V_73 ,
V_71 ) ;
F_71 ( V_1 -> V_79 -> V_73 , V_16 ) ;
F_72 ( V_1 -> V_79 -> V_73 , V_16 ) ;
F_73 ( V_1 -> V_79 ) ;
V_35 = F_74 ( & F_75 ( V_1 -> V_79 ) -> V_103 ,
& V_104 ) ;
if ( V_35 < 0 ) {
F_68 ( L_21 ) ;
goto V_49;
}
V_1 -> V_76 = 0 ;
V_49:
return V_35 ;
}
static void F_76 ( struct V_1 * V_1 )
{
F_77 ( & F_75 ( V_1 -> V_79 ) -> V_103 ,
& V_104 ) ;
if ( V_1 -> V_79 ) {
F_78 ( V_1 -> V_79 ) ;
F_79 ( V_1 -> V_79 ) ;
}
if ( V_1 -> V_73 )
F_67 ( V_1 -> V_73 ) ;
}
unsigned int F_80 ( void )
{
return V_105 ;
}
static int T_5 F_81 ( void )
{
int V_35 , V_106 ;
if ( V_105 > V_107 ) {
F_68 ( L_22 ,
V_105 ) ;
V_35 = - V_108 ;
goto V_49;
}
V_98 = F_82 ( 0 , L_23 ) ;
if ( V_98 <= 0 ) {
F_68 ( L_24 ) ;
V_35 = - V_109 ;
goto V_49;
}
V_110 = F_53 ( V_105 * sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_110 ) {
V_35 = - V_45 ;
goto V_111;
}
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
V_35 = F_61 ( & V_110 [ V_106 ] , V_106 ) ;
if ( V_35 )
goto V_112;
}
F_26 ( L_25 , V_105 ) ;
return 0 ;
V_112:
while ( V_106 )
F_76 ( & V_110 [ -- V_106 ] ) ;
F_27 ( V_110 ) ;
V_111:
F_83 ( V_98 , L_23 ) ;
V_49:
return V_35 ;
}
static void T_6 F_84 ( void )
{
int V_56 ;
struct V_1 * V_1 ;
for ( V_56 = 0 ; V_56 < V_105 ; V_56 ++ ) {
V_1 = & V_110 [ V_56 ] ;
F_76 ( V_1 ) ;
F_48 ( V_1 ) ;
}
F_83 ( V_98 , L_23 ) ;
F_27 ( V_110 ) ;
F_59 ( L_26 ) ;
}
