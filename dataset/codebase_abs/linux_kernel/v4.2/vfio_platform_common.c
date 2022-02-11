static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const char * V_5 ;
int (* F_2)( struct V_1 * );
int V_6 , V_7 ;
V_6 = F_3 ( V_4 , L_1 , & V_5 ) ;
if ( V_6 )
return;
for ( V_7 = 0 ; V_7 < F_4 ( V_8 ) ; V_7 ++ ) {
if ( ! strcmp ( V_8 [ V_7 ] . V_5 , V_5 ) ) {
F_5 ( V_8 [ V_7 ] . V_9 ) ;
F_2 = F_6 (
V_8 [ V_7 ] . V_10 ) ;
if ( F_2 ) {
V_2 -> F_2 = F_2 ;
return;
}
}
}
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> F_2 )
F_8 ( V_2 -> F_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_11 = 0 , V_7 ;
while ( V_2 -> V_12 ( V_2 , V_11 ) )
V_11 ++ ;
V_2 -> V_13 = F_10 ( V_11 , sizeof( struct V_14 ) ,
V_15 ) ;
if ( ! V_2 -> V_13 )
return - V_16 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
struct V_17 * V_18 =
V_2 -> V_12 ( V_2 , V_7 ) ;
if ( ! V_18 )
goto V_19;
V_2 -> V_13 [ V_7 ] . V_20 = V_18 -> V_21 ;
V_2 -> V_13 [ V_7 ] . V_22 = F_11 ( V_18 ) ;
V_2 -> V_13 [ V_7 ] . V_23 = 0 ;
switch ( F_12 ( V_18 ) ) {
case V_24 :
V_2 -> V_13 [ V_7 ] . type = V_25 ;
V_2 -> V_13 [ V_7 ] . V_23 |= V_26 ;
if ( ! ( V_18 -> V_23 & V_27 ) )
V_2 -> V_13 [ V_7 ] . V_23 |=
V_28 ;
if ( ! ( V_2 -> V_13 [ V_7 ] . V_20 & ~ V_29 ) &&
! ( V_2 -> V_13 [ V_7 ] . V_22 & ~ V_29 ) )
V_2 -> V_13 [ V_7 ] . V_23 |=
V_30 ;
break;
case V_31 :
V_2 -> V_13 [ V_7 ] . type = V_32 ;
break;
default:
goto V_19;
}
}
V_2 -> V_33 = V_11 ;
return 0 ;
V_19:
F_13 ( V_2 -> V_13 ) ;
return - V_34 ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_33 ; V_7 ++ )
F_15 ( V_2 -> V_13 [ V_7 ] . V_35 ) ;
V_2 -> V_33 = 0 ;
F_13 ( V_2 -> V_13 ) ;
}
static void F_16 ( void * V_36 )
{
struct V_1 * V_2 = V_36 ;
F_17 ( & V_37 ) ;
if ( ! ( -- V_2 -> V_38 ) ) {
if ( V_2 -> F_2 )
V_2 -> F_2 ( V_2 ) ;
F_14 ( V_2 ) ;
F_18 ( V_2 ) ;
}
F_19 ( & V_37 ) ;
F_20 ( V_39 ) ;
}
static int F_21 ( void * V_36 )
{
struct V_1 * V_2 = V_36 ;
int V_6 ;
if ( ! F_22 ( V_39 ) )
return - V_40 ;
F_17 ( & V_37 ) ;
if ( ! V_2 -> V_38 ) {
V_6 = F_9 ( V_2 ) ;
if ( V_6 )
goto V_41;
V_6 = F_23 ( V_2 ) ;
if ( V_6 )
goto V_42;
if ( V_2 -> F_2 )
V_2 -> F_2 ( V_2 ) ;
}
V_2 -> V_38 ++ ;
F_19 ( & V_37 ) ;
return 0 ;
V_42:
F_14 ( V_2 ) ;
V_41:
F_19 ( & V_37 ) ;
F_20 ( V_39 ) ;
return V_6 ;
}
static long F_24 ( void * V_36 ,
unsigned int V_43 , unsigned long V_44 )
{
struct V_1 * V_2 = V_36 ;
unsigned long V_45 ;
if ( V_43 == V_46 ) {
struct V_47 V_48 ;
V_45 = F_25 ( struct V_47 , V_49 ) ;
if ( F_26 ( & V_48 , ( void V_50 * ) V_44 , V_45 ) )
return - V_51 ;
if ( V_48 . V_52 < V_45 )
return - V_34 ;
if ( V_2 -> F_2 )
V_2 -> V_23 |= V_53 ;
V_48 . V_23 = V_2 -> V_23 ;
V_48 . V_33 = V_2 -> V_33 ;
V_48 . V_49 = V_2 -> V_49 ;
return F_27 ( ( void V_50 * ) V_44 , & V_48 , V_45 ) ;
} else if ( V_43 == V_54 ) {
struct V_55 V_48 ;
V_45 = F_25 ( struct V_55 , V_56 ) ;
if ( F_26 ( & V_48 , ( void V_50 * ) V_44 , V_45 ) )
return - V_51 ;
if ( V_48 . V_52 < V_45 )
return - V_34 ;
if ( V_48 . V_57 >= V_2 -> V_33 )
return - V_34 ;
V_48 . V_56 = F_28 ( V_48 . V_57 ) ;
V_48 . V_22 = V_2 -> V_13 [ V_48 . V_57 ] . V_22 ;
V_48 . V_23 = V_2 -> V_13 [ V_48 . V_57 ] . V_23 ;
return F_27 ( ( void V_50 * ) V_44 , & V_48 , V_45 ) ;
} else if ( V_43 == V_58 ) {
struct V_59 V_48 ;
V_45 = F_25 ( struct V_59 , V_60 ) ;
if ( F_26 ( & V_48 , ( void V_50 * ) V_44 , V_45 ) )
return - V_51 ;
if ( V_48 . V_52 < V_45 )
return - V_34 ;
if ( V_48 . V_57 >= V_2 -> V_49 )
return - V_34 ;
V_48 . V_23 = V_2 -> V_61 [ V_48 . V_57 ] . V_23 ;
V_48 . V_60 = V_2 -> V_61 [ V_48 . V_57 ] . V_60 ;
return F_27 ( ( void V_50 * ) V_44 , & V_48 , V_45 ) ;
} else if ( V_43 == V_62 ) {
struct V_63 V_64 ;
T_1 * V_65 = NULL ;
int V_6 = 0 ;
V_45 = F_25 ( struct V_63 , V_60 ) ;
if ( F_26 ( & V_64 , ( void V_50 * ) V_44 , V_45 ) )
return - V_51 ;
if ( V_64 . V_52 < V_45 )
return - V_34 ;
if ( V_64 . V_57 >= V_2 -> V_49 )
return - V_34 ;
if ( V_64 . V_23 & ~ ( V_66 |
V_67 ) )
return - V_34 ;
if ( ! ( V_64 . V_23 & V_68 ) ) {
T_2 V_22 ;
if ( V_64 . V_23 & V_69 )
V_22 = sizeof( V_70 ) ;
else if ( V_64 . V_23 & V_71 )
V_22 = sizeof( V_72 ) ;
else
return - V_34 ;
if ( V_64 . V_52 - V_45 < V_22 )
return - V_34 ;
V_65 = F_29 ( ( void V_50 * ) ( V_44 + V_45 ) , V_22 ) ;
if ( F_30 ( V_65 ) )
return F_31 ( V_65 ) ;
}
F_17 ( & V_2 -> V_73 ) ;
V_6 = F_32 ( V_2 , V_64 . V_23 , V_64 . V_57 ,
V_64 . V_21 , V_64 . V_60 , V_65 ) ;
F_19 ( & V_2 -> V_73 ) ;
F_13 ( V_65 ) ;
return V_6 ;
} else if ( V_43 == V_74 ) {
if ( V_2 -> F_2 )
return V_2 -> F_2 ( V_2 ) ;
else
return - V_34 ;
}
return - V_75 ;
}
static T_3 F_33 ( struct V_14 V_76 ,
char V_50 * V_77 , T_2 V_60 ,
T_4 V_78 )
{
unsigned int V_79 = 0 ;
if ( ! V_76 . V_35 ) {
V_76 . V_35 =
F_34 ( V_76 . V_20 , V_76 . V_22 ) ;
if ( ! V_76 . V_35 )
return - V_16 ;
}
while ( V_60 ) {
T_2 V_80 ;
if ( V_60 >= 4 && ! ( V_78 % 4 ) ) {
T_5 V_81 ;
V_81 = F_35 ( V_76 . V_35 + V_78 ) ;
if ( F_27 ( V_77 , & V_81 , 4 ) )
goto V_19;
V_80 = 4 ;
} else if ( V_60 >= 2 && ! ( V_78 % 2 ) ) {
T_6 V_81 ;
V_81 = F_36 ( V_76 . V_35 + V_78 ) ;
if ( F_27 ( V_77 , & V_81 , 2 ) )
goto V_19;
V_80 = 2 ;
} else {
T_1 V_81 ;
V_81 = F_37 ( V_76 . V_35 + V_78 ) ;
if ( F_27 ( V_77 , & V_81 , 1 ) )
goto V_19;
V_80 = 1 ;
}
V_60 -= V_80 ;
V_79 += V_80 ;
V_78 += V_80 ;
V_77 += V_80 ;
}
return V_79 ;
V_19:
return - V_51 ;
}
static T_3 F_38 ( void * V_36 , char V_50 * V_77 ,
T_2 V_60 , T_4 * V_82 )
{
struct V_1 * V_2 = V_36 ;
unsigned int V_57 = F_39 ( * V_82 ) ;
T_4 V_78 = * V_82 & V_83 ;
if ( V_57 >= V_2 -> V_33 )
return - V_34 ;
if ( ! ( V_2 -> V_13 [ V_57 ] . V_23 & V_26 ) )
return - V_34 ;
if ( V_2 -> V_13 [ V_57 ] . type & V_25 )
return F_33 ( V_2 -> V_13 [ V_57 ] ,
V_77 , V_60 , V_78 ) ;
else if ( V_2 -> V_13 [ V_57 ] . type & V_32 )
return - V_34 ;
return - V_34 ;
}
static T_3 F_40 ( struct V_14 V_76 ,
const char V_50 * V_77 , T_2 V_60 ,
T_4 V_78 )
{
unsigned int V_79 = 0 ;
if ( ! V_76 . V_35 ) {
V_76 . V_35 =
F_34 ( V_76 . V_20 , V_76 . V_22 ) ;
if ( ! V_76 . V_35 )
return - V_16 ;
}
while ( V_60 ) {
T_2 V_80 ;
if ( V_60 >= 4 && ! ( V_78 % 4 ) ) {
T_5 V_81 ;
if ( F_26 ( & V_81 , V_77 , 4 ) )
goto V_19;
F_41 ( V_81 , V_76 . V_35 + V_78 ) ;
V_80 = 4 ;
} else if ( V_60 >= 2 && ! ( V_78 % 2 ) ) {
T_6 V_81 ;
if ( F_26 ( & V_81 , V_77 , 2 ) )
goto V_19;
F_42 ( V_81 , V_76 . V_35 + V_78 ) ;
V_80 = 2 ;
} else {
T_1 V_81 ;
if ( F_26 ( & V_81 , V_77 , 1 ) )
goto V_19;
F_43 ( V_81 , V_76 . V_35 + V_78 ) ;
V_80 = 1 ;
}
V_60 -= V_80 ;
V_79 += V_80 ;
V_78 += V_80 ;
V_77 += V_80 ;
}
return V_79 ;
V_19:
return - V_51 ;
}
static T_3 F_44 ( void * V_36 , const char V_50 * V_77 ,
T_2 V_60 , T_4 * V_82 )
{
struct V_1 * V_2 = V_36 ;
unsigned int V_57 = F_39 ( * V_82 ) ;
T_4 V_78 = * V_82 & V_83 ;
if ( V_57 >= V_2 -> V_33 )
return - V_34 ;
if ( ! ( V_2 -> V_13 [ V_57 ] . V_23 & V_28 ) )
return - V_34 ;
if ( V_2 -> V_13 [ V_57 ] . type & V_25 )
return F_40 ( V_2 -> V_13 [ V_57 ] ,
V_77 , V_60 , V_78 ) ;
else if ( V_2 -> V_13 [ V_57 ] . type & V_32 )
return - V_34 ;
return - V_34 ;
}
static int F_45 ( struct V_14 V_84 ,
struct V_85 * V_86 )
{
T_7 V_87 , V_88 , V_89 ;
V_87 = V_86 -> V_90 - V_86 -> V_91 ;
V_88 = V_86 -> V_92 &
( ( 1U << ( V_93 - V_94 ) ) - 1 ) ;
V_89 = V_88 << V_94 ;
if ( V_84 . V_22 < V_95 || V_89 + V_87 > V_84 . V_22 )
return - V_34 ;
V_86 -> V_96 = F_46 ( V_86 -> V_96 ) ;
V_86 -> V_92 = ( V_84 . V_20 >> V_94 ) + V_88 ;
return F_47 ( V_86 , V_86 -> V_91 , V_86 -> V_92 ,
V_87 , V_86 -> V_96 ) ;
}
static int F_48 ( void * V_36 , struct V_85 * V_86 )
{
struct V_1 * V_2 = V_36 ;
unsigned int V_57 ;
V_57 = V_86 -> V_92 >> ( V_93 - V_94 ) ;
if ( V_86 -> V_90 < V_86 -> V_91 )
return - V_34 ;
if ( ! ( V_86 -> V_97 & V_98 ) )
return - V_34 ;
if ( V_57 >= V_2 -> V_33 )
return - V_34 ;
if ( V_86 -> V_91 & ~ V_29 )
return - V_34 ;
if ( V_86 -> V_90 & ~ V_29 )
return - V_34 ;
if ( ! ( V_2 -> V_13 [ V_57 ] . V_23 & V_30 ) )
return - V_34 ;
if ( ! ( V_2 -> V_13 [ V_57 ] . V_23 & V_26 )
&& ( V_86 -> V_97 & V_99 ) )
return - V_34 ;
if ( ! ( V_2 -> V_13 [ V_57 ] . V_23 & V_28 )
&& ( V_86 -> V_97 & V_100 ) )
return - V_34 ;
V_86 -> V_101 = V_2 ;
if ( V_2 -> V_13 [ V_57 ] . type & V_25 )
return F_45 ( V_2 -> V_13 [ V_57 ] , V_86 ) ;
else if ( V_2 -> V_13 [ V_57 ] . type & V_32 )
return - V_34 ;
return - V_34 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_102 * V_103 ;
int V_6 ;
if ( ! V_2 )
return - V_34 ;
V_103 = F_50 ( V_4 ) ;
if ( ! V_103 ) {
F_51 ( L_2 , V_2 -> V_104 ) ;
return - V_34 ;
}
V_6 = F_52 ( V_4 , & V_105 , V_2 ) ;
if ( V_6 ) {
F_53 ( V_103 ) ;
return V_6 ;
}
F_1 ( V_2 , V_4 ) ;
F_54 ( & V_2 -> V_73 ) ;
return 0 ;
}
struct V_1 * F_55 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( V_4 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_53 ( V_4 -> V_102 ) ;
}
return V_2 ;
}
