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
unsigned long V_56 ;
F_16 ( V_2 -> V_7 , V_56 ) ;
F_17 ( V_2 -> V_7 , V_57 ) ;
F_18 ( V_2 -> V_7 , V_56 ) ;
}
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
F_14 ( L_7 ,
V_54 , V_3 -> V_18 , V_3 -> V_42 ) ;
}
}
}
V_14 -> V_58 = NULL ;
F_19 ( & V_14 -> V_59 ) ;
}
static void F_20 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_3 * V_3 )
{
F_3 ( V_19 L_8 , V_2 -> V_60 , V_3 -> V_18 ) ;
V_3 -> V_18 = 0 ;
F_13 ( V_14 ) ;
}
static void F_21 ( struct V_13 * V_14 ,
struct V_1 * V_2 , struct V_3 * V_3 )
{
F_3 ( V_19
L_9
L_10
L_11 ,
F_22 ( V_14 -> V_45 ) ,
V_2 -> V_60 , F_23 ( V_3 -> V_61 ) ? L_12 : L_13 ,
V_14 -> V_62 , V_3 -> V_42 , V_14 -> V_62 ) ;
F_13 ( V_14 ) ;
}
static void F_24 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_63 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( F_25 ( F_7 ( & V_2 -> V_34 ) < V_52 ) ) {
F_14 ( L_14 ,
F_22 ( V_14 -> V_45 ) ,
V_2 -> V_60 , F_23 ( V_3 -> V_61 ) ? L_12 : L_13 ,
V_3 -> V_18 , V_3 -> V_42 ) ;
return;
}
if ( F_25 ( V_3 -> V_18 ) ) {
F_20 ( V_14 , V_2 , V_3 ) ;
return;
}
if ( F_26 ( ( V_3 -> V_42 & 0xFFFF ) == ( V_14 -> V_62 & 0xFFFF ) ) )
V_2 -> V_4 = V_3 ;
else {
F_21 ( V_14 , V_2 , V_3 ) ;
return;
}
{
struct V_1 * V_47 = V_14 -> V_2 [ V_64 ] ,
* V_48 = V_14 -> V_2 [ V_65 ] ;
if ( V_47 -> V_4 &&
F_7 ( & V_47 -> V_34 ) >= V_52 &&
( V_48 -> V_4 ||
F_7 ( & V_48 -> V_34 ) < V_52 ) ) {
if ( ! F_11 ( V_47 , V_48 , V_3 -> V_42 ) )
V_14 -> V_62 += F_2 () ;
else {
F_14 ( L_15 ) ;
F_13 ( V_14 ) ;
}
}
}
}
static void F_27 ( struct V_13 * V_14 ,
void (* F_28)( struct V_3 * ) )
{
int V_53 , V_54 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_53 ] ;
if ( NULL != V_2 )
for ( V_54 = 0 ; V_54 < V_43 ; V_54 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_54 ] ;
if ( NULL != V_3 )
V_3 -> F_28 = F_28 ;
}
}
}
static void F_29 ( struct V_13 * V_14 )
{
F_27 ( V_14 , F_24 ) ;
V_14 -> V_58 = NULL ;
}
static void F_30 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_63 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_58 = V_14 -> V_58 ;
if ( NULL != V_58 )
if ( V_3 -> V_42 == V_58 -> V_3 [ 0 ] -> V_42 ) {
F_29 ( V_14 ) ;
F_12 ( & V_58 -> V_34 ) ;
F_19 ( & V_14 -> V_59 ) ;
}
F_24 ( V_3 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_14 ( L_16 ,
V_2 , V_2 -> V_60 , V_2 -> V_3 [ 0 ] , V_2 -> V_3 [ 1 ] ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_26 = 0 ;
}
static void F_32 ( struct V_3 * * V_3 , int V_66 )
{
if ( * V_3 ) {
F_33 ( * V_3 ) ;
if ( V_66 )
F_34 ( ( * V_3 ) -> V_15 ) ;
F_35 ( * V_3 ) ;
* V_3 = NULL ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
int V_9 ;
F_14 ( L_17 , V_2 -> V_60 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ )
F_32 ( V_2 -> V_3 + V_9 ,
V_2 != V_2 -> V_14 -> V_2 [ V_65 ] ) ;
F_34 ( V_2 -> V_37 ) ;
V_2 -> V_37 = NULL ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
unsigned int V_61 ;
int V_67 = V_2 == V_2 -> V_14 -> V_2 [ V_65 ] ;
struct V_68 * V_45 = V_2 -> V_14 -> V_45 ;
V_61 = V_67 ? F_38 ( V_45 , V_2 -> V_60 ) :
F_39 ( V_45 , V_2 -> V_60 ) ;
V_2 -> V_69 = F_40 ( V_45 , V_61 , V_67 ) ;
if ( ! V_2 -> V_69 )
return - V_70 ;
if ( V_67 && NULL == V_2 -> V_37 ) {
V_2 -> V_37 = F_41 ( F_2 () , V_2 -> V_69 , V_71 ) ;
if ( NULL == V_2 -> V_37 ) {
F_3 ( V_19 L_18 ) ;
return - V_72 ;
}
}
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * * V_73 = V_2 -> V_3 + V_9 ;
if ( * V_73 ) {
F_33 ( * V_73 ) ;
continue;
}
* V_73 = F_42 ( F_2 () , V_71 ) ;
if ( NULL == * V_73 ) {
F_36 ( V_2 ) ;
return - V_72 ;
}
if ( ! V_67 && ! ( * V_73 ) -> V_15 ) {
( * V_73 ) -> V_15 = F_43 ( V_2 -> V_69 * F_2 () , V_71 ) ;
if ( NULL == ( * V_73 ) -> V_15 ) {
F_36 ( V_2 ) ;
return - V_72 ;
}
}
( * V_73 ) -> V_45 = V_45 ;
( * V_73 ) -> V_61 = V_61 ;
( * V_73 ) -> V_74 = F_2 () ;
( * V_73 ) -> V_63 = V_2 ;
( * V_73 ) -> V_75 = 1 ;
( * V_73 ) -> F_28 = F_30 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_58 = V_2 ;
V_2 -> V_3 [ 0 ] -> V_42 = - 1 ;
F_45 () ;
F_27 ( V_14 , F_30 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_9 , V_40 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ( V_40 = F_37 ( V_2 ) ) < 0 )
return V_40 ;
V_2 -> V_4 = NULL ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ ) {
struct V_1 * V_2 = V_14 -> V_2 [ V_9 ] ;
if ( V_2 != NULL && F_7 ( & V_2 -> V_34 ) >= V_52 )
goto V_76;
}
V_76:
F_44 ( V_2 ) ;
for ( V_9 = 0 ; V_9 < V_43 ; V_9 ++ ) {
struct V_3 * V_3 = V_2 -> V_3 [ V_9 ] ;
if ( F_23 ( V_3 -> V_61 ) ) {
unsigned long V_31 ;
if ( 0 == V_9 )
F_15 ( & V_2 -> V_34 , V_77 ) ;
V_3 -> V_45 = V_14 -> V_45 ;
for ( V_31 = 0 ; V_31 < F_2 () ; V_31 ++ ) {
V_3 -> V_16 [ V_31 ] . V_17 = V_2 -> V_69 * V_31 ;
V_3 -> V_16 [ V_31 ] . V_33 = V_2 -> V_69 ;
}
V_3 -> V_38 = V_2 -> V_69 * F_2 () ;
if ( ( V_40 = F_10 ( V_3 , V_46 ) ) < 0 ) {
F_3 ( V_19 L_19 , V_9 , V_40 ) ;
V_40 = - V_32 ;
goto V_78;
} else
if ( V_9 == 0 )
V_14 -> V_62 = V_3 -> V_42 ;
V_3 -> V_79 = 0 ;
} else {
F_15 ( & V_2 -> V_34 , V_50 ) ;
break;
}
}
V_40 = 0 ;
F_47 ( V_14 -> V_59 , NULL == V_14 -> V_58 ) ;
if ( F_7 ( & V_2 -> V_34 ) != V_52 )
V_40 = - V_32 ;
V_78:
if ( V_40 ) {
F_29 ( V_14 ) ;
F_13 ( V_14 ) ;
}
return V_40 ;
}
static T_1 F_48 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_6 -> V_82 ;
return V_2 -> V_12 ;
}
static int F_49 ( struct V_80 * V_81 , int V_83 )
{
struct V_1 * V_2 = V_81 -> V_6 -> V_82 ;
switch ( V_83 ) {
case V_84 :
F_14 ( L_20 ) ;
if ( F_7 ( & V_2 -> V_34 ) == V_52 &&
F_7 ( & V_2 -> V_14 -> V_2 [ V_64 ] -> V_34 ) >= V_52 ) {
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
return - V_70 ;
}
return 0 ;
}
static void F_50 ( struct V_3 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_63 ;
if ( V_3 -> V_18 )
F_3 ( V_19 L_22 , V_3 -> V_18 ) ;
if ( 0 == -- V_14 -> V_86 -> V_10 )
F_19 ( & V_14 -> V_87 ) ;
}
static int F_51 ( struct V_13 * V_14 , int V_88 )
{
int V_40 = 0 , V_9 ;
struct V_89 * V_90 = NULL ;
int * V_91 = NULL ;
struct V_92 * V_93 = V_88 == 48000 ? V_94 : V_95 ;
if ( V_14 -> V_88 != V_88 ) {
V_90 = F_52 ( sizeof( * V_90 ) + sizeof( struct V_3 * ) * V_96 , V_71 ) ;
if ( NULL == V_90 ) {
V_40 = - V_72 ;
goto V_78;
}
V_91 = F_43 ( sizeof( int ) * V_96 , V_71 ) ;
if ( NULL == V_91 ) {
V_40 = - V_72 ;
goto V_78;
}
for ( V_9 = 0 ; V_9 < V_96 ; ++ V_9 ) {
if ( NULL == ( V_90 -> V_3 [ V_9 ] = F_42 ( 0 , V_71 ) ) ) {
V_40 = - V_72 ;
goto V_78;
}
( ( char * ) ( V_91 + V_9 ) ) [ 0 ] = V_93 [ V_9 ] . V_97 ;
( ( char * ) ( V_91 + V_9 ) ) [ 1 ] = V_93 [ V_9 ] . V_98 ;
F_53 ( V_90 -> V_3 [ V_9 ] , V_14 -> V_45 , F_54 ( V_14 -> V_45 , 4 ) ,
V_91 + V_9 , 2 , F_50 , V_14 ) ;
}
V_90 -> V_99 = 0 ;
V_90 -> V_10 = V_96 ;
V_14 -> V_86 = V_90 ;
F_55 ( V_14 -> V_87 , 0 == V_90 -> V_10 , V_100 ) ;
V_14 -> V_86 = NULL ;
if ( V_90 -> V_10 )
V_40 = - V_41 ;
V_78:
if ( V_90 ) {
V_90 -> V_99 = 2 * V_96 ;
for ( V_9 = 0 ; V_9 < V_96 ; ++ V_9 ) {
struct V_3 * V_3 = V_90 -> V_3 [ V_9 ] ;
if ( V_3 -> V_18 ) {
if ( ! V_40 )
V_40 = - V_41 ;
F_33 ( V_3 ) ;
}
F_35 ( V_3 ) ;
}
V_14 -> V_86 = NULL ;
F_34 ( V_91 ) ;
F_34 ( V_90 ) ;
if ( ! V_40 )
V_14 -> V_88 = V_88 ;
}
}
return V_40 ;
}
static int F_56 ( struct V_13 * V_14 , T_2 V_101 )
{
int V_102 , V_40 ;
struct V_103 * V_104 ;
if ( V_101 == V_105 ) {
V_102 = 2 ;
V_14 -> V_21 = 6 ;
} else {
V_102 = 1 ;
V_14 -> V_21 = 4 ;
}
F_57 (p, &usX2Y->midi_list) {
F_58 ( V_104 ) ;
}
F_33 ( V_14 -> V_106 ) ;
if ( ( V_40 = F_59 ( V_14 -> V_45 , 0 , V_102 ) ) ) {
F_3 ( V_19 L_23 ) ;
return V_40 ;
}
V_14 -> V_106 -> V_45 = V_14 -> V_45 ;
V_40 = F_10 ( V_14 -> V_106 , V_71 ) ;
F_57 (p, &usX2Y->midi_list) {
F_60 ( V_104 ) ;
}
V_14 -> V_101 = V_101 ;
V_14 -> V_88 = 0 ;
return V_40 ;
}
static int F_61 ( struct V_80 * V_81 ,
struct V_107 * V_108 )
{
int V_40 = 0 ;
unsigned int V_88 = F_62 ( V_108 ) ;
T_2 V_101 = F_63 ( V_108 ) ;
struct V_109 * V_110 = V_81 -> V_111 -> V_112 -> V_110 ;
struct V_103 * V_113 ;
F_14 ( L_24 , V_81 , V_108 ) ;
F_57 (list, &card->devices) {
struct V_114 * V_45 ;
struct V_115 * V_112 ;
int V_53 ;
V_45 = V_114 ( V_113 ) ;
if ( V_45 -> type != V_116 )
continue;
V_112 = V_45 -> V_117 ;
for ( V_53 = 0 ; V_53 < 2 ; ++ V_53 ) {
struct V_80 * V_118 ;
V_118 = V_112 -> V_119 [ V_53 ] . V_81 ;
if ( V_118 && V_118 != V_81 &&
V_118 -> V_6 &&
( ( V_118 -> V_6 -> V_101 &&
V_118 -> V_6 -> V_101 != V_101 ) ||
( V_118 -> V_6 -> V_88 &&
V_118 -> V_6 -> V_88 != V_88 ) ) )
return - V_70 ;
}
}
if ( 0 > ( V_40 = F_64 ( V_81 , F_65 ( V_108 ) ) ) ) {
F_3 ( V_19 L_25 ,
V_81 , F_65 ( V_108 ) , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_66 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
F_67 ( & V_2 -> V_14 -> V_120 ) ;
F_14 ( L_26 , V_81 ) ;
if ( V_65 == V_81 -> V_121 ) {
struct V_1 * V_122 = V_2 -> V_14 -> V_2 [ V_64 ] ;
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_36 ( V_2 ) ;
if ( ! V_122 -> V_7 ||
! V_122 -> V_7 -> V_6 ||
! V_122 -> V_7 -> V_6 -> V_18 ||
V_122 -> V_7 -> V_6 -> V_18 -> V_34 < V_123 ) {
F_15 ( & V_122 -> V_34 , V_55 ) ;
F_36 ( V_122 ) ;
}
} else {
struct V_1 * V_124 = V_2 -> V_14 -> V_2 [ V_65 ] ;
if ( F_7 ( & V_124 -> V_34 ) < V_52 ) {
F_15 ( & V_2 -> V_34 , V_55 ) ;
F_36 ( V_2 ) ;
}
}
F_68 ( & V_2 -> V_14 -> V_120 ) ;
return F_69 ( V_81 ) ;
}
static int F_70 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_1 * V_47 = V_2 -> V_14 -> V_2 [ V_64 ] ;
int V_40 = 0 ;
F_14 ( L_27 , V_81 ) ;
F_67 ( & V_14 -> V_120 ) ;
F_31 ( V_2 ) ;
if ( F_7 ( & V_47 -> V_34 ) < V_52 ) {
if ( V_14 -> V_101 != V_6 -> V_101 )
if ( ( V_40 = F_56 ( V_14 , V_6 -> V_101 ) ) < 0 )
goto V_125;
if ( V_14 -> V_88 != V_6 -> V_88 )
if ( ( V_40 = F_51 ( V_14 , V_6 -> V_88 ) ) < 0 )
goto V_125;
F_14 ( L_28 , V_2 == V_47 ? L_29 : L_30 ) ;
if ( 0 > ( V_40 = F_46 ( V_47 ) ) )
goto V_125;
}
if ( V_2 != V_47 && F_7 ( & V_2 -> V_34 ) < V_52 )
V_40 = F_46 ( V_2 ) ;
V_125:
F_68 ( & V_14 -> V_120 ) ;
return V_40 ;
}
static int F_71 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = ( (struct V_1 * * )
F_72 ( V_81 ) ) [ V_81 -> V_121 ] ;
struct V_5 * V_6 = V_81 -> V_6 ;
if ( V_2 -> V_14 -> V_126 & V_127 )
return - V_128 ;
V_6 -> V_129 = V_130 ;
V_6 -> V_82 = V_2 ;
V_2 -> V_7 = V_81 ;
F_73 ( V_6 , V_131 , 1000 , 200000 ) ;
return 0 ;
}
static int F_74 ( struct V_80 * V_81 )
{
struct V_5 * V_6 = V_81 -> V_6 ;
struct V_1 * V_2 = V_6 -> V_82 ;
V_2 -> V_7 = NULL ;
return 0 ;
}
static void F_75 ( struct V_1 * * V_132 )
{
F_34 ( V_132 [ V_65 ] ) ;
V_132 [ V_65 ] = NULL ;
F_34 ( V_132 [ V_64 ] ) ;
V_132 [ V_64 ] = NULL ;
}
static void F_76 ( struct V_115 * V_112 )
{
struct V_1 * * V_133 = V_112 -> V_82 ;
if ( V_133 )
F_75 ( V_133 ) ;
}
static int F_77 ( struct V_109 * V_110 , int V_134 , int V_135 )
{
struct V_115 * V_112 ;
int V_40 , V_9 ;
struct V_1 * * V_132 =
V_14 ( V_110 ) -> V_2 + 2 * V_14 ( V_110 ) -> V_136 ;
for ( V_9 = V_134 ? V_65 : V_64 ;
V_9 <= V_64 ; ++ V_9 ) {
V_132 [ V_9 ] = F_52 ( sizeof( struct V_1 ) , V_71 ) ;
if ( NULL == V_132 [ V_9 ] ) {
F_3 ( V_19 L_31 ) ;
return - V_72 ;
}
V_132 [ V_9 ] -> V_14 = V_14 ( V_110 ) ;
}
if ( V_134 )
V_132 [ V_65 ] -> V_60 = V_134 ;
V_132 [ V_64 ] -> V_60 = V_135 ;
V_40 = F_78 ( V_110 , V_137 L_32 , V_14 ( V_110 ) -> V_136 ,
V_134 ? 1 : 0 , 1 ,
& V_112 ) ;
if ( V_40 < 0 ) {
F_75 ( V_132 ) ;
return V_40 ;
}
if ( V_134 )
F_79 ( V_112 , V_65 , & V_138 ) ;
F_79 ( V_112 , V_64 , & V_138 ) ;
V_112 -> V_82 = V_132 ;
V_112 -> V_139 = F_76 ;
V_112 -> V_140 = 0 ;
sprintf ( V_112 -> V_141 , V_137 L_33 , V_14 ( V_110 ) -> V_136 ) ;
if ( ( V_134 &&
0 > ( V_40 = F_80 ( V_112 -> V_119 [ V_65 ] . V_81 ,
V_142 ,
F_81 ( V_71 ) ,
64 * 1024 , 128 * 1024 ) ) ) ||
0 > ( V_40 = F_80 ( V_112 -> V_119 [ V_64 ] . V_81 ,
V_142 ,
F_81 ( V_71 ) ,
64 * 1024 , 128 * 1024 ) ) ) {
F_76 ( V_112 ) ;
return V_40 ;
}
V_14 ( V_110 ) -> V_136 ++ ;
return 0 ;
}
int F_82 ( struct V_109 * V_110 )
{
int V_40 = 0 ;
F_83 ( & V_14 ( V_110 ) -> V_143 ) ;
if ( 0 > ( V_40 = F_77 ( V_110 , 0xA , 0x8 ) ) )
return V_40 ;
if ( F_84 ( V_14 ( V_110 ) -> V_45 -> V_144 . V_145 ) == V_146 )
if ( 0 > ( V_40 = F_77 ( V_110 , 0 , 0xA ) ) )
return V_40 ;
if ( F_84 ( V_14 ( V_110 ) -> V_45 -> V_144 . V_145 ) != V_147 )
V_40 = F_51 ( V_14 ( V_110 ) , 44100 ) ;
return V_40 ;
}
