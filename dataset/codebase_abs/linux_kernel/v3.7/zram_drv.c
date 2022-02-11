static void F_1 ( T_1 * V_1 )
{
* V_1 = * V_1 + 1 ;
}
static void F_2 ( T_1 * V_1 )
{
* V_1 = * V_1 - 1 ;
}
static void F_3 ( struct V_2 * V_2 , T_2 * V_1 , T_2 V_3 )
{
F_4 ( & V_2 -> V_4 ) ;
* V_1 = * V_1 + V_3 ;
F_5 ( & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_2 * V_2 , T_2 * V_1 , T_2 V_5 )
{
F_4 ( & V_2 -> V_4 ) ;
* V_1 = * V_1 - V_5 ;
F_5 ( & V_2 -> V_4 ) ;
}
static void F_7 ( struct V_2 * V_2 , T_2 * V_1 )
{
F_3 ( V_2 , V_1 , 1 ) ;
}
static int F_8 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
return V_2 -> V_9 [ V_6 ] . V_10 & F_9 ( V_8 ) ;
}
static void F_10 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
V_2 -> V_9 [ V_6 ] . V_10 |= F_9 ( V_8 ) ;
}
static void F_11 ( struct V_2 * V_2 , T_1 V_6 ,
enum V_7 V_8 )
{
V_2 -> V_9 [ V_6 ] . V_10 &= ~ F_9 ( V_8 ) ;
}
static int F_12 ( void * V_11 )
{
unsigned int V_12 ;
unsigned long * V_13 ;
V_13 = ( unsigned long * ) V_11 ;
for ( V_12 = 0 ; V_12 != V_14 / sizeof( * V_13 ) ; V_12 ++ ) {
if ( V_13 [ V_12 ] )
return 0 ;
}
return 1 ;
}
static void F_13 ( struct V_2 * V_2 , T_3 V_15 )
{
if ( ! V_2 -> V_16 ) {
F_14 (
L_1
L_2 ,
V_17
) ;
V_2 -> V_16 = V_17 *
( V_15 / 100 ) ;
}
if ( V_2 -> V_16 > 2 * ( V_15 ) ) {
F_14 (
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10 ,
V_15 >> 10 , V_2 -> V_16
) ;
}
V_2 -> V_16 &= V_18 ;
}
static void F_15 ( struct V_2 * V_2 , T_3 V_6 )
{
unsigned long V_19 = V_2 -> V_9 [ V_6 ] . V_19 ;
T_4 V_20 = V_2 -> V_9 [ V_6 ] . V_20 ;
if ( F_16 ( ! V_19 ) ) {
if ( F_8 ( V_2 , V_6 , V_21 ) ) {
F_11 ( V_2 , V_6 , V_21 ) ;
F_2 ( & V_2 -> V_22 . V_23 ) ;
}
return;
}
if ( F_16 ( V_20 > V_24 ) )
F_2 ( & V_2 -> V_22 . V_25 ) ;
F_17 ( V_2 -> V_26 , V_19 ) ;
if ( V_20 <= V_14 / 2 )
F_2 ( & V_2 -> V_22 . V_27 ) ;
F_6 ( V_2 , & V_2 -> V_22 . V_28 ,
V_2 -> V_9 [ V_6 ] . V_20 ) ;
F_2 ( & V_2 -> V_22 . V_29 ) ;
V_2 -> V_9 [ V_6 ] . V_19 = 0 ;
V_2 -> V_9 [ V_6 ] . V_20 = 0 ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_13 * V_13 = V_31 -> V_32 ;
void * V_33 ;
V_33 = F_19 ( V_13 ) ;
memset ( V_33 + V_31 -> V_34 , 0 , V_31 -> V_35 ) ;
F_20 ( V_33 ) ;
F_21 ( V_13 ) ;
}
static inline int F_22 ( struct V_30 * V_31 )
{
return V_31 -> V_35 != V_14 ;
}
static int F_23 ( struct V_2 * V_2 , struct V_30 * V_31 ,
T_1 V_6 , int V_36 , struct V_37 * V_37 )
{
int V_38 ;
T_3 V_39 ;
struct V_13 * V_13 ;
unsigned char * V_33 , * V_40 , * V_41 = NULL ;
V_13 = V_31 -> V_32 ;
if ( F_8 ( V_2 , V_6 , V_21 ) ) {
F_18 ( V_31 ) ;
return 0 ;
}
if ( F_16 ( ! V_2 -> V_9 [ V_6 ] . V_19 ) ) {
F_24 ( L_11 ,
( V_42 ) ( V_37 -> V_43 ) , V_37 -> V_44 ) ;
F_18 ( V_31 ) ;
return 0 ;
}
if ( F_22 ( V_31 ) ) {
V_41 = F_25 ( V_14 , V_45 ) ;
if ( ! V_41 ) {
F_14 ( L_12 ) ;
return - V_46 ;
}
}
V_33 = F_19 ( V_13 ) ;
if ( ! F_22 ( V_31 ) )
V_41 = V_33 ;
V_39 = V_14 ;
V_40 = F_26 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ,
V_47 ) ;
if ( V_2 -> V_9 [ V_6 ] . V_20 == V_14 ) {
memcpy ( V_41 , V_40 , V_14 ) ;
V_38 = V_48 ;
} else {
V_38 = F_27 ( V_40 , V_2 -> V_9 [ V_6 ] . V_20 ,
V_41 , & V_39 ) ;
}
if ( F_22 ( V_31 ) ) {
memcpy ( V_33 + V_31 -> V_34 , V_41 + V_36 ,
V_31 -> V_35 ) ;
F_28 ( V_41 ) ;
}
F_29 ( V_2 -> V_26 , V_2 -> V_9 [ V_6 ] . V_19 ) ;
F_20 ( V_33 ) ;
if ( F_16 ( V_38 != V_48 ) ) {
F_30 ( L_13 , V_38 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_49 ) ;
return V_38 ;
}
F_21 ( V_13 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_2 , char * V_50 , T_1 V_6 )
{
int V_38 ;
T_3 V_39 = V_14 ;
unsigned char * V_40 ;
unsigned long V_19 = V_2 -> V_9 [ V_6 ] . V_19 ;
if ( F_8 ( V_2 , V_6 , V_21 ) || ! V_19 ) {
memset ( V_50 , 0 , V_14 ) ;
return 0 ;
}
V_40 = F_26 ( V_2 -> V_26 , V_19 , V_47 ) ;
V_38 = F_27 ( V_40 , V_2 -> V_9 [ V_6 ] . V_20 ,
V_50 , & V_39 ) ;
F_29 ( V_2 -> V_26 , V_19 ) ;
if ( F_16 ( V_38 != V_48 ) ) {
F_30 ( L_13 , V_38 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_49 ) ;
return V_38 ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_2 , struct V_30 * V_31 , T_1 V_6 ,
int V_36 )
{
int V_38 ;
T_3 V_39 ;
unsigned long V_19 ;
struct V_13 * V_13 ;
unsigned char * V_33 , * V_40 , * V_51 , * V_41 = NULL ;
V_13 = V_31 -> V_32 ;
V_51 = V_2 -> V_52 ;
if ( F_22 ( V_31 ) ) {
V_41 = F_25 ( V_14 , V_45 ) ;
if ( ! V_41 ) {
F_14 ( L_12 ) ;
V_38 = - V_46 ;
goto V_53;
}
V_38 = F_31 ( V_2 , V_41 , V_6 ) ;
if ( V_38 ) {
F_28 ( V_41 ) ;
goto V_53;
}
}
if ( V_2 -> V_9 [ V_6 ] . V_19 ||
F_8 ( V_2 , V_6 , V_21 ) )
F_15 ( V_2 , V_6 ) ;
V_33 = F_19 ( V_13 ) ;
if ( F_22 ( V_31 ) )
memcpy ( V_41 + V_36 , V_33 + V_31 -> V_34 ,
V_31 -> V_35 ) ;
else
V_41 = V_33 ;
if ( F_12 ( V_41 ) ) {
F_20 ( V_33 ) ;
if ( F_22 ( V_31 ) )
F_28 ( V_41 ) ;
F_1 ( & V_2 -> V_22 . V_23 ) ;
F_10 ( V_2 , V_6 , V_21 ) ;
V_38 = 0 ;
goto V_53;
}
V_38 = F_33 ( V_41 , V_14 , V_51 , & V_39 ,
V_2 -> V_54 ) ;
F_20 ( V_33 ) ;
if ( F_22 ( V_31 ) )
F_28 ( V_41 ) ;
if ( F_16 ( V_38 != V_48 ) ) {
F_30 ( L_14 , V_38 ) ;
goto V_53;
}
if ( F_16 ( V_39 > V_24 ) ) {
F_1 ( & V_2 -> V_22 . V_25 ) ;
V_51 = V_41 ;
V_39 = V_14 ;
}
V_19 = F_34 ( V_2 -> V_26 , V_39 ) ;
if ( ! V_19 ) {
F_14 ( L_15
L_16 , V_6 , V_39 ) ;
V_38 = - V_46 ;
goto V_53;
}
V_40 = F_26 ( V_2 -> V_26 , V_19 , V_55 ) ;
memcpy ( V_40 , V_51 , V_39 ) ;
F_29 ( V_2 -> V_26 , V_19 ) ;
V_2 -> V_9 [ V_6 ] . V_19 = V_19 ;
V_2 -> V_9 [ V_6 ] . V_20 = V_39 ;
F_3 ( V_2 , & V_2 -> V_22 . V_28 , V_39 ) ;
F_1 ( & V_2 -> V_22 . V_29 ) ;
if ( V_39 <= V_14 / 2 )
F_1 ( & V_2 -> V_22 . V_27 ) ;
return 0 ;
V_53:
if ( V_38 )
F_7 ( V_2 , & V_2 -> V_22 . V_56 ) ;
return V_38 ;
}
static int F_35 ( struct V_2 * V_2 , struct V_30 * V_31 , T_1 V_6 ,
int V_36 , struct V_37 * V_37 , int V_57 )
{
int V_38 ;
if ( V_57 == V_58 ) {
F_36 ( & V_2 -> V_59 ) ;
V_38 = F_23 ( V_2 , V_31 , V_6 , V_36 , V_37 ) ;
F_37 ( & V_2 -> V_59 ) ;
} else {
F_38 ( & V_2 -> V_59 ) ;
V_38 = F_32 ( V_2 , V_31 , V_6 , V_36 ) ;
F_39 ( & V_2 -> V_59 ) ;
}
return V_38 ;
}
static void F_40 ( T_1 * V_6 , int * V_36 , struct V_30 * V_31 )
{
if ( * V_36 + V_31 -> V_35 >= V_14 )
( * V_6 ) ++ ;
* V_36 = ( * V_36 + V_31 -> V_35 ) % V_14 ;
}
static void F_41 ( struct V_2 * V_2 , struct V_37 * V_37 , int V_57 )
{
int V_60 , V_36 ;
T_1 V_6 ;
struct V_30 * V_31 ;
switch ( V_57 ) {
case V_58 :
F_7 ( V_2 , & V_2 -> V_22 . V_61 ) ;
break;
case V_62 :
F_7 ( V_2 , & V_2 -> V_22 . V_63 ) ;
break;
}
V_6 = V_37 -> V_43 >> V_64 ;
V_36 = ( V_37 -> V_43 & ( V_65 - 1 ) ) << V_66 ;
F_42 (bvec, bio, i) {
int V_67 = V_14 - V_36 ;
if ( V_31 -> V_35 > V_67 ) {
struct V_30 V_68 ;
V_68 . V_32 = V_31 -> V_32 ;
V_68 . V_35 = V_67 ;
V_68 . V_34 = V_31 -> V_34 ;
if ( F_35 ( V_2 , & V_68 , V_6 , V_36 , V_37 , V_57 ) < 0 )
goto V_53;
V_68 . V_35 = V_31 -> V_35 - V_67 ;
V_68 . V_34 += V_67 ;
if ( F_35 ( V_2 , & V_68 , V_6 + 1 , 0 , V_37 , V_57 ) < 0 )
goto V_53;
} else
if ( F_35 ( V_2 , V_31 , V_6 , V_36 , V_37 , V_57 )
< 0 )
goto V_53;
F_40 ( & V_6 , & V_36 , V_31 ) ;
}
F_43 ( V_69 , & V_37 -> V_70 ) ;
F_44 ( V_37 , 0 ) ;
return;
V_53:
F_45 ( V_37 ) ;
}
static inline int F_46 ( struct V_2 * V_2 , struct V_37 * V_37 )
{
if ( F_16 (
( V_37 -> V_43 >= ( V_2 -> V_16 >> V_66 ) ) ||
( V_37 -> V_43 & ( V_71 - 1 ) ) ||
( V_37 -> V_44 & ( V_72 - 1 ) ) ) ) {
return 0 ;
}
return 1 ;
}
static void F_47 ( struct V_73 * V_74 , struct V_37 * V_37 )
{
struct V_2 * V_2 = V_74 -> V_75 ;
if ( F_16 ( ! V_2 -> V_76 ) && F_48 ( V_2 ) )
goto error;
F_36 ( & V_2 -> V_77 ) ;
if ( F_16 ( ! V_2 -> V_76 ) )
goto V_78;
if ( ! F_46 ( V_2 , V_37 ) ) {
F_7 ( V_2 , & V_2 -> V_22 . V_79 ) ;
goto V_78;
}
F_41 ( V_2 , V_37 , F_49 ( V_37 ) ) ;
F_37 ( & V_2 -> V_77 ) ;
return;
V_78:
F_37 ( & V_2 -> V_77 ) ;
error:
F_45 ( V_37 ) ;
}
void F_50 ( struct V_2 * V_2 )
{
T_3 V_6 ;
V_2 -> V_76 = 0 ;
F_28 ( V_2 -> V_54 ) ;
F_51 ( ( unsigned long ) V_2 -> V_52 , 1 ) ;
V_2 -> V_54 = NULL ;
V_2 -> V_52 = NULL ;
for ( V_6 = 0 ; V_6 < V_2 -> V_16 > > V_80 ; V_6 ++ ) {
unsigned long V_19 = V_2 -> V_9 [ V_6 ] . V_19 ;
if ( ! V_19 )
continue;
F_17 ( V_2 -> V_26 , V_19 ) ;
}
F_52 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_53 ( V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
memset ( & V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
V_2 -> V_16 = 0 ;
}
void F_54 ( struct V_2 * V_2 )
{
F_38 ( & V_2 -> V_77 ) ;
F_50 ( V_2 ) ;
F_39 ( & V_2 -> V_77 ) ;
}
int F_48 ( struct V_2 * V_2 )
{
int V_38 ;
T_3 V_81 ;
F_38 ( & V_2 -> V_77 ) ;
if ( V_2 -> V_76 ) {
F_39 ( & V_2 -> V_77 ) ;
return 0 ;
}
F_13 ( V_2 , V_82 << V_80 ) ;
V_2 -> V_54 = F_55 ( V_83 , V_45 ) ;
if ( ! V_2 -> V_54 ) {
F_30 ( L_17 ) ;
V_38 = - V_46 ;
goto V_84;
}
V_2 -> V_52 =
( void * ) F_56 ( V_45 | V_85 , 1 ) ;
if ( ! V_2 -> V_52 ) {
F_30 ( L_18 ) ;
V_38 = - V_46 ;
goto V_84;
}
V_81 = V_2 -> V_16 >> V_80 ;
V_2 -> V_9 = F_57 ( V_81 * sizeof( * V_2 -> V_9 ) ) ;
if ( ! V_2 -> V_9 ) {
F_30 ( L_19 ) ;
V_38 = - V_46 ;
goto V_84;
}
F_58 ( V_2 -> V_86 , V_2 -> V_16 >> V_66 ) ;
F_59 ( V_87 , V_2 -> V_86 -> V_74 ) ;
V_2 -> V_26 = F_60 ( L_20 , V_88 | V_89 ) ;
if ( ! V_2 -> V_26 ) {
F_30 ( L_21 ) ;
V_38 = - V_46 ;
goto V_90;
}
V_2 -> V_76 = 1 ;
F_39 ( & V_2 -> V_77 ) ;
F_24 ( L_22 ) ;
return 0 ;
V_84:
V_2 -> V_16 = 0 ;
V_90:
F_50 ( V_2 ) ;
F_39 ( & V_2 -> V_77 ) ;
F_30 ( L_23 , V_38 ) ;
return V_38 ;
}
static void F_61 ( struct V_91 * V_92 ,
unsigned long V_6 )
{
struct V_2 * V_2 ;
V_2 = V_92 -> V_93 -> V_94 ;
F_15 ( V_2 , V_6 ) ;
F_7 ( V_2 , & V_2 -> V_22 . V_95 ) ;
}
static int F_62 ( struct V_2 * V_2 , int V_96 )
{
int V_38 = 0 ;
F_63 ( & V_2 -> V_59 ) ;
F_63 ( & V_2 -> V_77 ) ;
F_64 ( & V_2 -> V_4 ) ;
V_2 -> V_74 = F_65 ( V_45 ) ;
if ( ! V_2 -> V_74 ) {
F_30 ( L_24 ,
V_96 ) ;
V_38 = - V_46 ;
goto V_53;
}
F_66 ( V_2 -> V_74 , F_47 ) ;
V_2 -> V_74 -> V_75 = V_2 ;
V_2 -> V_86 = F_67 ( 1 ) ;
if ( ! V_2 -> V_86 ) {
F_68 ( V_2 -> V_74 ) ;
F_69 ( L_25 ,
V_96 ) ;
V_38 = - V_46 ;
goto V_53;
}
V_2 -> V_86 -> V_97 = V_98 ;
V_2 -> V_86 -> V_99 = V_96 ;
V_2 -> V_86 -> V_100 = & V_101 ;
V_2 -> V_86 -> V_74 = V_2 -> V_74 ;
V_2 -> V_86 -> V_94 = V_2 ;
snprintf ( V_2 -> V_86 -> V_102 , 16 , L_26 , V_96 ) ;
F_58 ( V_2 -> V_86 , 0 ) ;
F_70 ( V_2 -> V_86 -> V_74 , V_14 ) ;
F_71 ( V_2 -> V_86 -> V_74 ,
V_72 ) ;
F_72 ( V_2 -> V_86 -> V_74 , V_14 ) ;
F_73 ( V_2 -> V_86 -> V_74 , V_14 ) ;
F_74 ( V_2 -> V_86 ) ;
V_38 = F_75 ( & F_76 ( V_2 -> V_86 ) -> V_103 ,
& V_104 ) ;
if ( V_38 < 0 ) {
F_69 ( L_27 ) ;
goto V_53;
}
V_2 -> V_76 = 0 ;
V_53:
return V_38 ;
}
static void F_77 ( struct V_2 * V_2 )
{
F_78 ( & F_76 ( V_2 -> V_86 ) -> V_103 ,
& V_104 ) ;
if ( V_2 -> V_86 ) {
F_79 ( V_2 -> V_86 ) ;
F_80 ( V_2 -> V_86 ) ;
}
if ( V_2 -> V_74 )
F_68 ( V_2 -> V_74 ) ;
}
unsigned int F_81 ( void )
{
return V_105 ;
}
static int T_5 F_82 ( void )
{
int V_38 , V_106 ;
if ( V_105 > V_107 ) {
F_69 ( L_28 ,
V_105 ) ;
V_38 = - V_108 ;
goto V_53;
}
V_98 = F_83 ( 0 , L_20 ) ;
if ( V_98 <= 0 ) {
F_69 ( L_29 ) ;
V_38 = - V_109 ;
goto V_53;
}
if ( ! V_105 ) {
F_14 ( L_30 ) ;
V_105 = 1 ;
}
F_14 ( L_31 , V_105 ) ;
V_110 = F_55 ( V_105 * sizeof( struct V_2 ) , V_45 ) ;
if ( ! V_110 ) {
V_38 = - V_46 ;
goto V_111;
}
for ( V_106 = 0 ; V_106 < V_105 ; V_106 ++ ) {
V_38 = F_62 ( & V_110 [ V_106 ] , V_106 ) ;
if ( V_38 )
goto V_112;
}
return 0 ;
V_112:
while ( V_106 )
F_77 ( & V_110 [ -- V_106 ] ) ;
F_28 ( V_110 ) ;
V_111:
F_84 ( V_98 , L_20 ) ;
V_53:
return V_38 ;
}
static void T_6 F_85 ( void )
{
int V_60 ;
struct V_2 * V_2 ;
for ( V_60 = 0 ; V_60 < V_105 ; V_60 ++ ) {
V_2 = & V_110 [ V_60 ] ;
F_77 ( V_2 ) ;
if ( V_2 -> V_76 )
F_54 ( V_2 ) ;
}
F_84 ( V_98 , L_20 ) ;
F_28 ( V_110 ) ;
F_24 ( L_32 ) ;
}
