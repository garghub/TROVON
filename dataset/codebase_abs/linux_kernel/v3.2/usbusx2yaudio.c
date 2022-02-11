static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
unsigned char * V_8 ;
int V_9 , V_10 , V_11 = 0 , V_12 = V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_14 ;
for ( V_9 = 0 ; V_9 < F_2 () ; V_9 ++ ) {
V_8 = ( unsigned char * ) V_3 -> V_15 + V_3 -> V_16 [ V_9 ] . V_17 ;
if ( V_3 -> V_16 [ V_9 ] . V_18 ) {
F_3 ( V_19 L_1
L_2 ,
V_3 -> V_16 [ V_9 ] . V_18 ) ;
return V_3 -> V_16 [ V_9 ] . V_18 ;
}
V_10 = V_3 -> V_16 [ V_9 ] . V_20 / V_14 -> V_21 ;
if ( ! V_10 ) {
F_4 ( L_3 ) ;
continue;
}
if ( ( V_12 + V_10 ) > V_6 -> V_22 ) {
int V_23 = V_6 -> V_22 - V_12 ;
int V_24 = V_23 * V_14 -> V_21 ;
memcpy ( V_6 -> V_25 + V_12 * V_14 -> V_21 , V_8 , V_24 ) ;
memcpy ( V_6 -> V_25 , V_8 + V_24 , V_10 * V_14 -> V_21 - V_24 ) ;
} else {
memcpy ( V_6 -> V_25 + V_12 * V_14 -> V_21 , V_8 ,
V_10 * V_14 -> V_21 ) ;
}
V_11 += V_10 ;
if ( ( V_12 += V_10 ) >= V_6 -> V_22 )
V_12 -= V_6 -> V_22 ;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_26 += V_11 ;
if ( V_2 -> V_26 >= V_6 -> V_27 ) {
V_2 -> V_26 -= V_6 -> V_27 ;
F_5 ( V_2 -> V_7 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_28 ,
struct V_3 * V_3 )
{
int V_29 , V_30 , V_31 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_29 = 0 ;
for ( V_31 = 0 ; V_31 < F_2 () ; V_31 ++ ) {
V_30 = V_28 -> V_16 [ V_31 ] . V_20 / V_14 -> V_21 ;
V_29 += V_30 ;
if ( V_30 < 43 || V_30 > 50 ) {
F_3 ( V_19 L_4 , V_30 ) ;
return - V_32 ;
}
V_3 -> V_16 [ V_31 ] . V_17 = V_31 ?
V_3 -> V_16 [ V_31 - 1 ] . V_17 +
V_3 -> V_16 [ V_31 - 1 ] . V_33 :
0 ;
V_3 -> V_16 [ V_31 ] . V_33 = V_28 -> V_16 [ V_31 ] . V_20 ;
}
if ( F_7 ( & V_2 -> V_34 ) >= V_35 )
if ( V_2 -> V_36 + V_29 > V_6 -> V_22 ) {
int V_10 ;
V_10 = V_6 -> V_22 - V_2 -> V_36 ;
V_3 -> V_15 = V_2 -> V_37 ;
memcpy ( V_2 -> V_37 , V_6 -> V_25 +
V_2 -> V_36 * V_14 -> V_21 , V_10 * V_14 -> V_21 ) ;
memcpy ( V_2 -> V_37 + V_10 * V_14 -> V_21 ,
V_6 -> V_25 , ( V_29 - V_10 ) * V_14 -> V_21 ) ;
V_2 -> V_36 += V_29 ;
V_2 -> V_36 -= V_6 -> V_22 ;
} else {
V_3 -> V_15 = V_6 -> V_25 + V_2 -> V_36 * V_14 -> V_21 ;
if ( ( V_2 -> V_36 += V_29 ) >= V_6 -> V_22 )
V_2 -> V_36 -= V_6 -> V_22 ;
}
else
V_3 -> V_15 = V_2 -> V_37 ;
V_3 -> V_38 = V_29 * V_14 -> V_21 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_10 = V_3 -> V_20 / V_2 -> V_14 -> V_21 ;
V_2 -> V_26 += V_10 ;
V_2 -> V_12 += V_10 ;
if ( V_2 -> V_12 >= V_6 -> V_22 )
V_2 -> V_12 -= V_6 -> V_22 ;
if ( V_2 -> V_26 >= V_6 -> V_27 ) {
V_2 -> V_26 -= V_6 -> V_27 ;
F_5 ( V_2 -> V_7 ) ;
}
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_3 , int V_39 )
{
int V_40 ;
if ( ! V_3 )
return - V_41 ;
V_3 -> V_42 = ( V_39 + V_43 * F_2 () ) ;
V_3 -> V_44 = NULL ;
V_3 -> V_45 = V_2 -> V_14 -> V_45 ;
if ( ( V_40 = F_10 ( V_3 , V_46 ) ) < 0 ) {
F_3 ( V_19 L_5 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static inline int F_11 ( struct V_1 * V_47 ,
struct V_1 * V_48 ,
int V_39 )
{
int V_40 , V_34 ;
struct V_3 * V_3 = V_48 -> V_4 ;
V_34 = F_7 ( & V_48 -> V_34 ) ;
if ( NULL != V_3 ) {
if ( V_34 == V_49 )
F_8 ( V_48 , V_3 ) ;
else if ( V_34 >= V_35 )
F_12 ( & V_48 -> V_34 ) ;
} else {
switch ( V_34 ) {
case V_50 :
V_3 = V_48 -> V_3 [ 0 ] ;
F_12 ( & V_48 -> V_34 ) ;
break;
case V_51 :
V_3 = V_48 -> V_3 [ 1 ] ;
F_12 ( & V_48 -> V_34 ) ;
break;
}
}
if ( V_3 ) {
if ( ( V_40 = F_6 ( V_48 , V_47 -> V_4 , V_3 ) ) ||
( V_40 = F_9 ( V_48 , V_3 , V_39 ) ) ) {
return V_40 ;
}
}
V_48 -> V_4 = NULL ;
V_34 = F_7 ( & V_47 -> V_34 ) ;
if ( V_34 >= V_52 ) {
if ( V_34 == V_49 ) {
if ( ( V_40 = F_1 ( V_47 ) ) )
return V_40 ;
} else if ( V_34 >= V_35 )
F_12 ( & V_47 -> V_34 ) ;
if ( ( V_40 = F_9 ( V_47 , V_47 -> V_4 , V_39 ) ) )
return V_40 ;
}
V_47 -> V_4 = NULL ;
return 0 ;
}
static void F_13 ( struct V_13 * V_14 )
{
int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_53 ] ;
if ( V_2 ) {
F_14 ( L_6 , V_53 , V_2 , F_7 ( & V_2 -> V_34 ) ) ;
F_15 ( & V_2 -> V_34 , V_55 ) ;
}
}
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_53 ] ;
if ( V_2 ) {
if ( F_7 ( & V_2 -> V_34 ) >= V_35 ) {
F_16 ( V_2 -> V_7 , V_56 ) ;
}
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
F_14 ( L_7 ,
V_54 , V_3 -> V_18 , V_3 -> V_42 ) ;
}
}
}
V_14 -> V_57 = NULL ;
F_17 ( & V_14 -> V_58 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_3 * V_3 )
{
F_3 ( V_19 L_8 , V_2 -> V_59 , V_3 -> V_18 ) ;
V_3 -> V_18 = 0 ;
F_13 ( V_14 ) ;
}
static void F_19 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_3 * V_3 )
{
F_3 ( V_19
L_9
L_10
L_11 ,
F_20 ( V_14 -> V_45 ) ,
V_2 -> V_59 , F_21 ( V_3 -> V_60 ) ? L_12 : L_13 ,
V_14 -> V_61 , V_3 -> V_42 , V_14 -> V_61 ) ;
F_13 ( V_14 ) ;
}
static void F_22 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_62 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( F_23 ( F_7 ( & V_2 -> V_34 ) < V_52 ) ) {
F_14 ( L_14 ,
F_20 ( V_14 -> V_45 ) ,
V_2 -> V_59 , F_21 ( V_3 -> V_60 ) ? L_12 : L_13 ,
V_3 -> V_18 , V_3 -> V_42 ) ;
return;
}
if ( F_23 ( V_3 -> V_18 ) ) {
F_18 ( V_14 , V_2 , V_3 ) ;
return;
}
if ( F_24 ( ( V_3 -> V_42 & 0xFFFF ) == ( V_14 -> V_61 & 0xFFFF ) ) )
V_2 -> V_4 = V_3 ;
else {
F_19 ( V_14 , V_2 , V_3 ) ;
return;
}
{
struct V_1 * V_47 = V_14 -> V_2 [ V_63 ] ,
* V_48 = V_14 -> V_2 [ V_64 ] ;
if ( V_47 -> V_4 &&
F_7 ( & V_47 -> V_34 ) >= V_52 &&
( V_48 -> V_4 ||
F_7 ( & V_48 -> V_34 ) < V_52 ) ) {
if ( ! F_11 ( V_47 , V_48 , V_3 -> V_42 ) )
V_14 -> V_61 += F_2 () ;
else {
F_14 ( L_15 ) ;
F_13 ( V_14 ) ;
}
}
}
}
static void F_25 ( struct V_13 * V_14 ,
void (* F_26)( struct V_3 * ) )
{
int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_53 ] ;
if ( NULL != V_2 )
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
V_3 -> F_26 = F_26 ;
}
}
}
static void F_27 ( struct V_13 * V_14 )
{
F_25 ( V_14 , F_22 ) ;
V_14 -> V_57 = NULL ;
}
static void F_28 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_62 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_57 = V_14 -> V_57 ;
if ( NULL != V_57 )
if ( V_3 -> V_42 == V_57 -> V_3 [ 0 ] -> V_42 ) {
F_27 ( V_14 ) ;
F_12 ( & V_57 -> V_34 ) ;
F_17 ( & V_14 -> V_58 ) ;
}
F_22 ( V_3 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_14 ( L_16 ,
V_2 , V_2 -> V_59 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_26 = 0 ;
}
static void F_30 ( struct V_3 * * V_3 , int V_65 )
{
if ( * V_3 ) {
F_31 ( * V_3 ) ;
if ( V_65 )
F_32 ( ( * V_3 ) -> V_15 ) ;
F_33 ( * V_3 ) ;
* V_3 = NULL ;
}
}
static void F_34 ( struct V_1 * V_2 )
{
int V_9 ;
F_14 ( L_17 , V_2 -> V_59 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ )
F_30 ( V_2 -> V_3 + V_9 ,
V_2 != V_2 -> V_14 -> V_2 [ V_64 ] ) ;
F_32 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned int V_60 ;
int V_66 = V_2 == V_2 -> V_14 -> V_2 [ V_64 ] ;
struct V_67 * V_45 = V_2 -> V_14 -> V_45 ;
V_60 = V_66 ? F_36 ( V_45 , V_2 -> V_59 ) :
F_37 ( V_45 , V_2 -> V_59 ) ;
V_2 -> V_68 = F_38 ( V_45 , V_60 , V_66 ) ;
if ( ! V_2 -> V_68 )
return - V_69 ;
if ( V_66 && NULL == V_2 -> V_37 ) {
V_2 -> V_37 = F_39 ( F_2 () , V_2 -> V_68 , V_70 ) ;
if ( NULL == V_2 -> V_37 ) {
F_3 ( V_19 L_18 ) ;
return - V_71 ;
}
}
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * * V_72 = V_2 -> V_3 + V_9 ;
if ( * V_72 ) {
F_31 ( * V_72 ) ;
continue;
}
* V_72 = F_40 ( F_2 () , V_70 ) ;
if ( NULL == * V_72 ) {
F_34 ( V_2 ) ;
return - V_71 ;
}
if ( ! V_66 && ! ( * V_72 ) -> V_15 ) {
( * V_72 ) -> V_15 = F_41 ( V_2 -> V_68 * F_2 () , V_70 ) ;
if ( NULL == ( * V_72 ) -> V_15 ) {
F_34 ( V_2 ) ;
return - V_71 ;
}
}
( * V_72 ) -> V_45 = V_45 ;
( * V_72 ) -> V_60 = V_60 ;
( * V_72 ) -> V_73 = F_2 () ;
( * V_72 ) -> V_62 = V_2 ;
( * V_72 ) -> V_74 = 1 ;
( * V_72 ) -> F_26 = F_28 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_57 = V_2 ;
V_2 -> V_3 [ 0 ] -> V_42 = - 1 ;
F_43 () ;
F_25 ( V_14 , F_28 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_9 , V_40 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ( V_40 = F_35 ( V_2 ) ) < 0 )
return V_40 ;
V_2 -> V_4 = NULL ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_9 ] ;
if ( V_2 != NULL && F_7 ( & V_2 -> V_34 ) >= V_52 )
goto V_75;
}
V_75:
F_42 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_9 ] ;
if ( F_21 ( V_3 -> V_60 ) ) {
unsigned long V_31 ;
if ( 0 == V_9 )
F_15 ( & V_2 -> V_34 , V_76 ) ;
V_3 -> V_45 = V_14 -> V_45 ;
V_3 -> V_77 = V_78 ;
for ( V_31 = 0 ; V_31 < F_2 () ; V_31 ++ ) {
V_3 -> V_16 [ V_31 ] . V_17 = V_2 -> V_68 * V_31 ;
V_3 -> V_16 [ V_31 ] . V_33 = V_2 -> V_68 ;
}
V_3 -> V_38 = V_2 -> V_68 * F_2 () ;
if ( ( V_40 = F_10 ( V_3 , V_46 ) ) < 0 ) {
F_3 ( V_19 L_19 , V_9 , V_40 ) ;
V_40 = - V_32 ;
goto V_79;
} else
if ( V_9 == 0 )
V_14 -> V_61 = V_3 -> V_42 ;
V_3 -> V_77 = 0 ;
} else {
F_15 ( & V_2 -> V_34 , V_50 ) ;
break;
}
}
V_40 = 0 ;
F_45 ( V_14 -> V_58 , NULL == V_14 -> V_57 ) ;
if ( F_7 ( & V_2 -> V_34 ) != V_52 )
V_40 = - V_32 ;
V_79:
if ( V_40 ) {
F_27 ( V_14 ) ;
F_13 ( V_14 ) ;
}
return V_40 ;
}
static T_1 F_46 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_6 -> V_82 ;
return V_2 -> V_12 ;
}
static int F_47 ( struct V_80 * V_81 , int V_83 )
{
struct V_1 * V_2 = V_81 -> V_6 -> V_82 ;
switch ( V_83 ) {
case V_84 :
F_14 ( L_20 ) ;
if ( F_7 ( & V_2 -> V_34 ) == V_52 &&
F_7 ( & V_2 -> V_14 -> V_2 [ V_63 ] -> V_34 ) >= V_52 ) {
F_15 ( & V_2 -> V_34 , V_35 ) ;
} else {
F_14 ( L_15 ) ;
return - V_32 ;
}
break;
case V_85 :
F_14 ( L_21 ) ;
if ( F_7 ( & V_2 -> V_34 ) >= V_35 )
F_15 ( & V_2 -> V_34 , V_52 ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static void F_48 ( struct V_3 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_62 ;
if ( V_3 -> V_18 )
F_3 ( V_19 L_22 , V_3 -> V_18 ) ;
if ( 0 == -- V_14 -> V_86 -> V_10 )
F_17 ( & V_14 -> V_87 ) ;
}
static int F_49 ( struct V_13 * V_14 , int V_88 )
{
int V_40 = 0 , V_9 ;
struct V_89 * V_90 = NULL ;
int * V_91 = NULL ;
struct V_92 * V_93 = V_88 == 48000 ? V_94 : V_95 ;
if ( V_14 -> V_88 != V_88 ) {
V_90 = F_50 ( sizeof( * V_90 ) + sizeof( struct V_3 * ) * V_96 , V_70 ) ;
if ( NULL == V_90 ) {
V_40 = - V_71 ;
goto V_79;
}
V_91 = F_41 ( sizeof( int ) * V_96 , V_70 ) ;
if ( NULL == V_91 ) {
V_40 = - V_71 ;
goto V_79;
}
for ( V_9 = 0 ; V_9 < V_96 ; ++ V_9 ) {
if ( NULL == ( V_90 -> V_3 [ V_9 ] = F_40 ( 0 , V_70 ) ) ) {
V_40 = - V_71 ;
goto V_79;
}
( ( char * ) ( V_91 + V_9 ) ) [ 0 ] = V_93 [ V_9 ] . V_97 ;
( ( char * ) ( V_91 + V_9 ) ) [ 1 ] = V_93 [ V_9 ] . V_98 ;
F_51 ( V_90 -> V_3 [ V_9 ] , V_14 -> V_45 , F_52 ( V_14 -> V_45 , 4 ) ,
V_91 + V_9 , 2 , F_48 , V_14 ) ;
#ifdef F_53
V_90 -> V_3 [ V_9 ] -> V_77 = V_99 ;
#endif
}
V_90 -> V_100 = 0 ;
V_90 -> V_10 = V_96 ;
V_14 -> V_86 = V_90 ;
F_54 ( V_14 -> V_87 , 0 == V_90 -> V_10 , V_101 ) ;
V_14 -> V_86 = NULL ;
if ( V_90 -> V_10 )
V_40 = - V_41 ;
V_79:
if ( V_90 ) {
V_90 -> V_100 = 2 * V_96 ;
for ( V_9 = 0 ; V_9 < V_96 ; ++ V_9 ) {
struct V_3 * V_3 = V_90 -> V_3 [ V_9 ] ;
if ( V_3 -> V_18 ) {
if ( ! V_40 )
V_40 = - V_41 ;
F_31 ( V_3 ) ;
}
F_33 ( V_3 ) ;
}
V_14 -> V_86 = NULL ;
F_32 ( V_91 ) ;
F_32 ( V_90 ) ;
if ( ! V_40 )
V_14 -> V_88 = V_88 ;
}
}
return V_40 ;
}
static int F_55 ( struct V_13 * V_14 , T_2 V_102 )
{
int V_103 , V_40 ;
struct V_104 * V_105 ;
if ( V_102 == V_106 ) {
V_103 = 2 ;
V_14 -> V_21 = 6 ;
} else {
V_103 = 1 ;
V_14 -> V_21 = 4 ;
}
F_56 (p, &usX2Y->midi_list) {
F_57 ( V_105 ) ;
}
F_31 ( V_14 -> V_107 ) ;
if ( ( V_40 = F_58 ( V_14 -> V_45 , 0 , V_103 ) ) ) {
F_3 ( V_19 L_23 ) ;
return V_40 ;
}
V_14 -> V_107 -> V_45 = V_14 -> V_45 ;
V_40 = F_10 ( V_14 -> V_107 , V_70 ) ;
F_56 (p, &usX2Y->midi_list) {
F_59 ( V_105 ) ;
}
V_14 -> V_102 = V_102 ;
V_14 -> V_88 = 0 ;
return V_40 ;
}
static int F_60 ( struct V_80 * V_81 ,
struct V_108 * V_109 )
{
int V_40 = 0 ;
unsigned int V_88 = F_61 ( V_109 ) ;
T_2 V_102 = F_62 ( V_109 ) ;
struct V_110 * V_111 = V_81 -> V_112 -> V_113 -> V_111 ;
struct V_104 * V_114 ;
F_14 ( L_24 , V_81 , V_109 ) ;
F_56 (list, &card->devices) {
struct V_115 * V_45 ;
struct V_116 * V_113 ;
int V_53 ;
V_45 = V_115 ( V_114 ) ;
if ( V_45 -> type != V_117 )
continue;
V_113 = V_45 -> V_118 ;
for ( V_53 = 0 ; V_53 < 2 ; ++ V_53 ) {
struct V_80 * V_119 ;
V_119 = V_113 -> V_120 [ V_53 ] . V_81 ;
if ( V_119 && V_119 != V_81 &&
V_119 -> V_6 &&
( ( V_119 -> V_6 -> V_102 &&
V_119 -> V_6 -> V_102 != V_102 ) ||
( V_119 -> V_6 -> V_88 &&
V_119 -> V_6 -> V_88 != V_88 ) ) )
return - V_69 ;
}
}
if ( 0 > ( V_40 = F_63 ( V_81 , F_64 ( V_109 ) ) ) ) {
F_3 ( V_19 L_25 ,
V_81 , F_64 ( V_109 ) , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_65 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
F_66 ( & V_2 -> V_14 -> V_121 ) ;
F_14 ( L_26 , V_81 ) ;
if ( V_64 == V_81 -> V_122 ) {
struct V_1 * V_123 = V_2 -> V_14 -> V_2 [ V_63 ] ;
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_34 ( V_2 ) ;
if ( ! V_123 -> V_7 ||
! V_123 -> V_7 -> V_6 ||
! V_123 -> V_7 -> V_6 -> V_18 ||
V_123 -> V_7 -> V_6 -> V_18 -> V_34 < V_124 ) {
F_15 ( & V_123 -> V_34 , V_55 ) ;
F_34 ( V_123 ) ;
}
} else {
struct V_1 * V_125 = V_2 -> V_14 -> V_2 [ V_64 ] ;
if ( F_7 ( & V_125 -> V_34 ) < V_52 ) {
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_34 ( V_2 ) ;
}
}
F_67 ( & V_2 -> V_14 -> V_121 ) ;
return F_68 ( V_81 ) ;
}
static int F_69 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_47 = V_2 -> V_14 -> V_2 [ V_63 ] ;
int V_40 = 0 ;
F_14 ( L_27 , V_81 ) ;
F_66 ( & V_14 -> V_121 ) ;
F_29 ( V_2 ) ;
if ( F_7 ( & V_47 -> V_34 ) < V_52 ) {
if ( V_14 -> V_102 != V_6 -> V_102 )
if ( ( V_40 = F_55 ( V_14 , V_6 -> V_102 ) ) < 0 )
goto V_126;
if ( V_14 -> V_88 != V_6 -> V_88 )
if ( ( V_40 = F_49 ( V_14 , V_6 -> V_88 ) ) < 0 )
goto V_126;
F_14 ( L_28 , V_2 == V_47 ? L_29 : L_30 ) ;
if ( 0 > ( V_40 = F_44 ( V_47 ) ) )
goto V_126;
}
if ( V_2 != V_47 && F_7 ( & V_2 -> V_34 ) < V_52 )
V_40 = F_44 ( V_2 ) ;
V_126:
F_67 ( & V_14 -> V_121 ) ;
return V_40 ;
}
static int F_70 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = ( (struct V_1 * * )
F_71 ( V_81 ) ) [ V_81 -> V_122 ] ;
struct V_5 * V_6 = V_81 -> V_6 ;
if ( V_2 -> V_14 -> V_127 & V_128 )
return - V_129 ;
V_6 -> V_130 = V_131 ;
V_6 -> V_82 = V_2 ;
V_2 -> V_7 = V_81 ;
F_72 ( V_6 , V_132 , 1000 , 200000 ) ;
return 0 ;
}
static int F_73 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
V_2 -> V_7 = NULL ;
return 0 ;
}
static void F_74 ( struct V_1 * * V_133 )
{
F_32 ( V_133 [ V_64 ] ) ;
V_133 [ V_64 ] = NULL ;
F_32 ( V_133 [ V_63 ] ) ;
V_133 [ V_63 ] = NULL ;
}
static void F_75 ( struct V_116 * V_113 )
{
struct V_1 * * V_134 = V_113 -> V_82 ;
if ( V_134 )
F_74 ( V_134 ) ;
}
static int F_76 ( struct V_110 * V_111 , int V_135 , int V_136 )
{
struct V_116 * V_113 ;
int V_40 , V_9 ;
struct V_1 * * V_133 =
V_14 ( V_111 ) -> V_2 + 2 * V_14 ( V_111 ) -> V_137 ;
for ( V_9 = V_135 ? V_64 : V_63 ;
V_9 <= V_63 ; ++ V_9 ) {
V_133 [ V_9 ] = F_50 ( sizeof( struct V_1 ) , V_70 ) ;
if ( NULL == V_133 [ V_9 ] ) {
F_3 ( V_19 L_31 ) ;
return - V_71 ;
}
V_133 [ V_9 ] -> V_14 = V_14 ( V_111 ) ;
}
if ( V_135 )
V_133 [ V_64 ] -> V_59 = V_135 ;
V_133 [ V_63 ] -> V_59 = V_136 ;
V_40 = F_77 ( V_111 , V_138 L_32 , V_14 ( V_111 ) -> V_137 ,
V_135 ? 1 : 0 , 1 ,
& V_113 ) ;
if ( V_40 < 0 ) {
F_74 ( V_133 ) ;
return V_40 ;
}
if ( V_135 )
F_78 ( V_113 , V_64 , & V_139 ) ;
F_78 ( V_113 , V_63 , & V_139 ) ;
V_113 -> V_82 = V_133 ;
V_113 -> V_140 = F_75 ;
V_113 -> V_141 = 0 ;
sprintf ( V_113 -> V_142 , V_138 L_33 , V_14 ( V_111 ) -> V_137 ) ;
if ( ( V_135 &&
0 > ( V_40 = F_79 ( V_113 -> V_120 [ V_64 ] . V_81 ,
V_143 ,
F_80 ( V_70 ) ,
64 * 1024 , 128 * 1024 ) ) ) ||
0 > ( V_40 = F_79 ( V_113 -> V_120 [ V_63 ] . V_81 ,
V_143 ,
F_80 ( V_70 ) ,
64 * 1024 , 128 * 1024 ) ) ) {
F_75 ( V_113 ) ;
return V_40 ;
}
V_14 ( V_111 ) -> V_137 ++ ;
return 0 ;
}
int F_81 ( struct V_110 * V_111 )
{
int V_40 = 0 ;
F_82 ( & V_14 ( V_111 ) -> V_144 ) ;
if ( 0 > ( V_40 = F_76 ( V_111 , 0xA , 0x8 ) ) )
return V_40 ;
if ( F_83 ( V_14 ( V_111 ) -> V_45 -> V_145 . V_146 ) == V_147 )
if ( 0 > ( V_40 = F_76 ( V_111 , 0 , 0xA ) ) )
return V_40 ;
if ( F_83 ( V_14 ( V_111 ) -> V_45 -> V_145 . V_146 ) != V_148 )
V_40 = F_49 ( V_14 ( V_111 ) , 44100 ) ;
return V_40 ;
}
