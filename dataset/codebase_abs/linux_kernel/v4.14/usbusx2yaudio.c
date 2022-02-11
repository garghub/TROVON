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
if ( F_7 ( & V_2 -> V_34 ) >= V_35 )
F_16 ( V_2 -> V_7 ) ;
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
F_14 ( L_7 ,
V_54 , V_3 -> V_18 , V_3 -> V_42 ) ;
}
}
}
V_14 -> V_56 = NULL ;
F_17 ( & V_14 -> V_57 ) ;
}
static void F_18 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_3 * V_3 )
{
F_3 ( V_19 L_8 , V_2 -> V_58 , V_3 -> V_18 ) ;
V_3 -> V_18 = 0 ;
F_13 ( V_14 ) ;
}
static void F_19 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_59 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( F_20 ( F_7 ( & V_2 -> V_34 ) < V_52 ) ) {
F_14 ( L_9 ,
F_21 ( V_14 -> V_45 ) ,
V_2 -> V_58 , F_22 ( V_3 -> V_60 ) ? L_10 : L_11 ,
V_3 -> V_18 , V_3 -> V_42 ) ;
return;
}
if ( F_20 ( V_3 -> V_18 ) ) {
F_18 ( V_14 , V_2 , V_3 ) ;
return;
}
V_2 -> V_4 = V_3 ;
{
struct V_1 * V_47 = V_14 -> V_2 [ V_61 ] ,
* V_48 = V_14 -> V_2 [ V_62 ] ;
if ( V_47 -> V_4 &&
F_7 ( & V_47 -> V_34 ) >= V_52 &&
( V_48 -> V_4 ||
F_7 ( & V_48 -> V_34 ) < V_52 ) ) {
if ( ! F_11 ( V_47 , V_48 , V_3 -> V_42 ) )
V_14 -> V_63 += F_2 () ;
else {
F_14 ( L_12 ) ;
F_13 ( V_14 ) ;
}
}
}
}
static void F_23 ( struct V_13 * V_14 ,
void (* F_24)( struct V_3 * ) )
{
int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_53 ] ;
if ( NULL != V_2 )
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
V_3 -> F_24 = F_24 ;
}
}
}
static void F_25 ( struct V_13 * V_14 )
{
F_23 ( V_14 , F_19 ) ;
V_14 -> V_56 = NULL ;
}
static void F_26 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_59 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_56 = V_14 -> V_56 ;
if ( NULL != V_56 )
if ( V_3 -> V_42 == V_56 -> V_3 [ 0 ] -> V_42 ) {
F_25 ( V_14 ) ;
F_12 ( & V_56 -> V_34 ) ;
F_17 ( & V_14 -> V_57 ) ;
}
F_19 ( V_3 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_14 ( L_13 ,
V_2 , V_2 -> V_58 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_26 = 0 ;
}
static void F_28 ( struct V_3 * * V_3 , int V_64 )
{
if ( * V_3 ) {
F_29 ( * V_3 ) ;
if ( V_64 )
F_30 ( ( * V_3 ) -> V_15 ) ;
F_31 ( * V_3 ) ;
* V_3 = NULL ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
int V_9 ;
F_14 ( L_14 , V_2 -> V_58 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ )
F_28 ( V_2 -> V_3 + V_9 ,
V_2 != V_2 -> V_14 -> V_2 [ V_62 ] ) ;
F_30 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned int V_60 ;
int V_65 = V_2 == V_2 -> V_14 -> V_2 [ V_62 ] ;
struct V_66 * V_45 = V_2 -> V_14 -> V_45 ;
V_60 = V_65 ? F_34 ( V_45 , V_2 -> V_58 ) :
F_35 ( V_45 , V_2 -> V_58 ) ;
V_2 -> V_67 = F_36 ( V_45 , V_60 , V_65 ) ;
if ( ! V_2 -> V_67 )
return - V_68 ;
if ( V_65 && NULL == V_2 -> V_37 ) {
V_2 -> V_37 = F_37 ( F_2 () , V_2 -> V_67 , V_69 ) ;
if ( ! V_2 -> V_37 )
return - V_70 ;
}
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * * V_71 = V_2 -> V_3 + V_9 ;
if ( * V_71 ) {
F_29 ( * V_71 ) ;
continue;
}
* V_71 = F_38 ( F_2 () , V_69 ) ;
if ( NULL == * V_71 ) {
F_32 ( V_2 ) ;
return - V_70 ;
}
if ( ! V_65 && ! ( * V_71 ) -> V_15 ) {
( * V_71 ) -> V_15 = F_39 ( V_2 -> V_67 * F_2 () , V_69 ) ;
if ( NULL == ( * V_71 ) -> V_15 ) {
F_32 ( V_2 ) ;
return - V_70 ;
}
}
( * V_71 ) -> V_45 = V_45 ;
( * V_71 ) -> V_60 = V_60 ;
( * V_71 ) -> V_72 = F_2 () ;
( * V_71 ) -> V_59 = V_2 ;
( * V_71 ) -> V_73 = 1 ;
( * V_71 ) -> F_24 = F_26 ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_56 = V_2 ;
V_2 -> V_3 [ 0 ] -> V_42 = - 1 ;
F_41 () ;
F_23 ( V_14 , F_26 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_9 , V_40 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ( V_40 = F_33 ( V_2 ) ) < 0 )
return V_40 ;
V_2 -> V_4 = NULL ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_9 ] ;
if ( V_2 != NULL && F_7 ( & V_2 -> V_34 ) >= V_52 )
goto V_74;
}
V_74:
F_40 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_9 ] ;
if ( F_22 ( V_3 -> V_60 ) ) {
unsigned long V_31 ;
if ( 0 == V_9 )
F_15 ( & V_2 -> V_34 , V_75 ) ;
V_3 -> V_45 = V_14 -> V_45 ;
for ( V_31 = 0 ; V_31 < F_2 () ; V_31 ++ ) {
V_3 -> V_16 [ V_31 ] . V_17 = V_2 -> V_67 * V_31 ;
V_3 -> V_16 [ V_31 ] . V_33 = V_2 -> V_67 ;
}
V_3 -> V_38 = V_2 -> V_67 * F_2 () ;
if ( ( V_40 = F_10 ( V_3 , V_46 ) ) < 0 ) {
F_3 ( V_19 L_15 , V_9 , V_40 ) ;
V_40 = - V_32 ;
goto V_76;
} else
if ( V_9 == 0 )
V_14 -> V_63 = V_3 -> V_42 ;
V_3 -> V_77 = 0 ;
} else {
F_15 ( & V_2 -> V_34 , V_50 ) ;
break;
}
}
V_40 = 0 ;
F_43 ( V_14 -> V_57 , NULL == V_14 -> V_56 ) ;
if ( F_7 ( & V_2 -> V_34 ) != V_52 )
V_40 = - V_32 ;
V_76:
if ( V_40 ) {
F_25 ( V_14 ) ;
F_13 ( V_14 ) ;
}
return V_40 ;
}
static T_1 F_44 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = V_79 -> V_6 -> V_80 ;
return V_2 -> V_12 ;
}
static int F_45 ( struct V_78 * V_79 , int V_81 )
{
struct V_1 * V_2 = V_79 -> V_6 -> V_80 ;
switch ( V_81 ) {
case V_82 :
F_14 ( L_16 ) ;
if ( F_7 ( & V_2 -> V_34 ) == V_52 &&
F_7 ( & V_2 -> V_14 -> V_2 [ V_61 ] -> V_34 ) >= V_52 ) {
F_15 ( & V_2 -> V_34 , V_35 ) ;
} else {
F_14 ( L_12 ) ;
return - V_32 ;
}
break;
case V_83 :
F_14 ( L_17 ) ;
if ( F_7 ( & V_2 -> V_34 ) >= V_35 )
F_15 ( & V_2 -> V_34 , V_52 ) ;
break;
default:
return - V_68 ;
}
return 0 ;
}
static void F_46 ( struct V_3 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_59 ;
if ( V_3 -> V_18 )
F_3 ( V_19 L_18 , V_3 -> V_18 ) ;
if ( 0 == -- V_14 -> V_84 -> V_10 )
F_17 ( & V_14 -> V_85 ) ;
}
static int F_47 ( struct V_13 * V_14 , int V_86 )
{
int V_40 = 0 , V_9 ;
struct V_87 * V_88 = NULL ;
int * V_89 = NULL ;
struct V_90 * V_91 = V_86 == 48000 ? V_92 : V_93 ;
if ( V_14 -> V_86 != V_86 ) {
V_88 = F_48 ( sizeof( * V_88 ) + sizeof( struct V_3 * ) * V_94 , V_69 ) ;
if ( NULL == V_88 ) {
V_40 = - V_70 ;
goto V_76;
}
V_89 = F_39 ( sizeof( int ) * V_94 , V_69 ) ;
if ( NULL == V_89 ) {
V_40 = - V_70 ;
goto V_76;
}
for ( V_9 = 0 ; V_9 < V_94 ; ++ V_9 ) {
if ( NULL == ( V_88 -> V_3 [ V_9 ] = F_38 ( 0 , V_69 ) ) ) {
V_40 = - V_70 ;
goto V_76;
}
( ( char * ) ( V_89 + V_9 ) ) [ 0 ] = V_91 [ V_9 ] . V_95 ;
( ( char * ) ( V_89 + V_9 ) ) [ 1 ] = V_91 [ V_9 ] . V_96 ;
F_49 ( V_88 -> V_3 [ V_9 ] , V_14 -> V_45 , F_50 ( V_14 -> V_45 , 4 ) ,
V_89 + V_9 , 2 , F_46 , V_14 ) ;
}
V_88 -> V_97 = 0 ;
V_88 -> V_10 = V_94 ;
V_14 -> V_84 = V_88 ;
F_51 ( V_14 -> V_85 , 0 == V_88 -> V_10 , V_98 ) ;
V_14 -> V_84 = NULL ;
if ( V_88 -> V_10 )
V_40 = - V_41 ;
V_76:
if ( V_88 ) {
V_88 -> V_97 = 2 * V_94 ;
for ( V_9 = 0 ; V_9 < V_94 ; ++ V_9 ) {
struct V_3 * V_3 = V_88 -> V_3 [ V_9 ] ;
if ( V_3 -> V_18 ) {
if ( ! V_40 )
V_40 = - V_41 ;
F_29 ( V_3 ) ;
}
F_31 ( V_3 ) ;
}
V_14 -> V_84 = NULL ;
F_30 ( V_89 ) ;
F_30 ( V_88 ) ;
if ( ! V_40 )
V_14 -> V_86 = V_86 ;
}
}
return V_40 ;
}
static int F_52 ( struct V_13 * V_14 , T_2 V_99 )
{
int V_100 , V_40 ;
struct V_101 * V_102 ;
if ( V_99 == V_103 ) {
V_100 = 2 ;
V_14 -> V_21 = 6 ;
} else {
V_100 = 1 ;
V_14 -> V_21 = 4 ;
}
F_53 (p, &usX2Y->midi_list) {
F_54 ( V_102 ) ;
}
F_29 ( V_14 -> V_104 ) ;
if ( ( V_40 = F_55 ( V_14 -> V_45 , 0 , V_100 ) ) ) {
F_3 ( V_19 L_19 ) ;
return V_40 ;
}
V_14 -> V_104 -> V_45 = V_14 -> V_45 ;
V_40 = F_10 ( V_14 -> V_104 , V_69 ) ;
F_53 (p, &usX2Y->midi_list) {
F_56 ( V_102 ) ;
}
V_14 -> V_99 = V_99 ;
V_14 -> V_86 = 0 ;
return V_40 ;
}
static int F_57 ( struct V_78 * V_79 ,
struct V_105 * V_106 )
{
int V_40 = 0 ;
unsigned int V_86 = F_58 ( V_106 ) ;
T_2 V_99 = F_59 ( V_106 ) ;
struct V_107 * V_108 = V_79 -> V_109 -> V_110 -> V_108 ;
struct V_13 * V_45 = V_14 ( V_108 ) ;
int V_9 ;
F_60 ( & V_14 ( V_108 ) -> V_111 ) ;
F_14 ( L_20 , V_79 , V_106 ) ;
for ( V_9 = 0 ; V_9 < V_45 -> V_112 * 2 ; V_9 ++ ) {
struct V_1 * V_2 = V_45 -> V_2 [ V_9 ] ;
struct V_78 * V_113 ;
if ( ! V_2 )
continue;
V_113 = V_2 -> V_7 ;
if ( ! V_113 || V_113 == V_79 ||
! V_113 -> V_6 )
continue;
if ( ( V_113 -> V_6 -> V_99 &&
V_113 -> V_6 -> V_99 != V_99 ) ||
( V_113 -> V_6 -> V_86 &&
V_113 -> V_6 -> V_86 != V_86 ) ) {
V_40 = - V_68 ;
goto error;
}
}
V_40 = F_61 ( V_79 ,
F_62 ( V_106 ) ) ;
if ( V_40 < 0 ) {
F_3 ( V_19 L_21 ,
V_79 , F_62 ( V_106 ) , V_40 ) ;
goto error;
}
error:
F_63 ( & V_14 ( V_108 ) -> V_111 ) ;
return V_40 ;
}
static int F_64 ( struct V_78 * V_79 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_80 ;
F_60 ( & V_2 -> V_14 -> V_111 ) ;
F_14 ( L_22 , V_79 ) ;
if ( V_62 == V_79 -> V_114 ) {
struct V_1 * V_115 = V_2 -> V_14 -> V_2 [ V_61 ] ;
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_32 ( V_2 ) ;
if ( ! V_115 -> V_7 ||
! V_115 -> V_7 -> V_6 ||
! V_115 -> V_7 -> V_6 -> V_18 ||
V_115 -> V_7 -> V_6 -> V_18 -> V_34 < V_116 ) {
F_15 ( & V_115 -> V_34 , V_55 ) ;
F_32 ( V_115 ) ;
}
} else {
struct V_1 * V_117 = V_2 -> V_14 -> V_2 [ V_62 ] ;
if ( F_7 ( & V_117 -> V_34 ) < V_52 ) {
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_32 ( V_2 ) ;
}
}
F_63 ( & V_2 -> V_14 -> V_111 ) ;
return F_65 ( V_79 ) ;
}
static int F_66 ( struct V_78 * V_79 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_80 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_47 = V_2 -> V_14 -> V_2 [ V_61 ] ;
int V_40 = 0 ;
F_14 ( L_23 , V_79 ) ;
F_60 ( & V_14 -> V_111 ) ;
F_27 ( V_2 ) ;
if ( F_7 ( & V_47 -> V_34 ) < V_52 ) {
if ( V_14 -> V_99 != V_6 -> V_99 )
if ( ( V_40 = F_52 ( V_14 , V_6 -> V_99 ) ) < 0 )
goto V_118;
if ( V_14 -> V_86 != V_6 -> V_86 )
if ( ( V_40 = F_47 ( V_14 , V_6 -> V_86 ) ) < 0 )
goto V_118;
F_14 ( L_24 , V_2 == V_47 ? L_25 : L_26 ) ;
if ( 0 > ( V_40 = F_42 ( V_47 ) ) )
goto V_118;
}
if ( V_2 != V_47 && F_7 ( & V_2 -> V_34 ) < V_52 )
V_40 = F_42 ( V_2 ) ;
V_118:
F_63 ( & V_14 -> V_111 ) ;
return V_40 ;
}
static int F_67 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = ( (struct V_1 * * )
F_68 ( V_79 ) ) [ V_79 -> V_114 ] ;
struct V_5 * V_6 = V_79 -> V_6 ;
if ( V_2 -> V_14 -> V_119 & V_120 )
return - V_121 ;
V_6 -> V_122 = V_123 ;
V_6 -> V_80 = V_2 ;
V_2 -> V_7 = V_79 ;
F_69 ( V_6 , V_124 , 1000 , 200000 ) ;
return 0 ;
}
static int F_70 ( struct V_78 * V_79 )
{
struct V_5 * V_6 = V_79 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_80 ;
V_2 -> V_7 = NULL ;
return 0 ;
}
static void F_71 ( struct V_1 * * V_125 )
{
F_30 ( V_125 [ V_62 ] ) ;
V_125 [ V_62 ] = NULL ;
F_30 ( V_125 [ V_61 ] ) ;
V_125 [ V_61 ] = NULL ;
}
static void F_72 ( struct V_126 * V_110 )
{
struct V_1 * * V_127 = V_110 -> V_80 ;
if ( V_127 )
F_71 ( V_127 ) ;
}
static int F_73 ( struct V_107 * V_108 , int V_128 , int V_129 )
{
struct V_126 * V_110 ;
int V_40 , V_9 ;
struct V_1 * * V_125 =
V_14 ( V_108 ) -> V_2 + 2 * V_14 ( V_108 ) -> V_112 ;
for ( V_9 = V_128 ? V_62 : V_61 ;
V_9 <= V_61 ; ++ V_9 ) {
V_125 [ V_9 ] = F_48 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_125 [ V_9 ] )
return - V_70 ;
V_125 [ V_9 ] -> V_14 = V_14 ( V_108 ) ;
}
if ( V_128 )
V_125 [ V_62 ] -> V_58 = V_128 ;
V_125 [ V_61 ] -> V_58 = V_129 ;
V_40 = F_74 ( V_108 , V_130 L_27 , V_14 ( V_108 ) -> V_112 ,
V_128 ? 1 : 0 , 1 ,
& V_110 ) ;
if ( V_40 < 0 ) {
F_71 ( V_125 ) ;
return V_40 ;
}
if ( V_128 )
F_75 ( V_110 , V_62 , & V_131 ) ;
F_75 ( V_110 , V_61 , & V_131 ) ;
V_110 -> V_80 = V_125 ;
V_110 -> V_132 = F_72 ;
V_110 -> V_133 = 0 ;
sprintf ( V_110 -> V_134 , V_130 L_28 , V_14 ( V_108 ) -> V_112 ) ;
if ( ( V_128 &&
0 > ( V_40 = F_76 ( V_110 -> V_135 [ V_62 ] . V_79 ,
V_136 ,
F_77 ( V_69 ) ,
64 * 1024 , 128 * 1024 ) ) ) ||
0 > ( V_40 = F_76 ( V_110 -> V_135 [ V_61 ] . V_79 ,
V_136 ,
F_77 ( V_69 ) ,
64 * 1024 , 128 * 1024 ) ) ) {
F_72 ( V_110 ) ;
return V_40 ;
}
V_14 ( V_108 ) -> V_112 ++ ;
return 0 ;
}
int F_78 ( struct V_107 * V_108 )
{
int V_40 = 0 ;
F_79 ( & V_14 ( V_108 ) -> V_137 ) ;
if ( 0 > ( V_40 = F_73 ( V_108 , 0xA , 0x8 ) ) )
return V_40 ;
if ( F_80 ( V_14 ( V_108 ) -> V_45 -> V_138 . V_139 ) == V_140 )
if ( 0 > ( V_40 = F_73 ( V_108 , 0 , 0xA ) ) )
return V_40 ;
if ( F_80 ( V_14 ( V_108 ) -> V_45 -> V_138 . V_139 ) != V_141 )
V_40 = F_47 ( V_14 ( V_108 ) , 44100 ) ;
return V_40 ;
}
