static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 , V_4 ;
while ( V_2 -> V_5 ( V_2 , V_3 ) )
V_3 ++ ;
V_2 -> V_6 = F_2 ( V_3 , sizeof( struct V_7 ) ,
V_8 ) ;
if ( ! V_2 -> V_6 )
return - V_9 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
struct V_10 * V_11 =
V_2 -> V_5 ( V_2 , V_4 ) ;
if ( ! V_11 )
goto V_12;
V_2 -> V_6 [ V_4 ] . V_13 = V_11 -> V_14 ;
V_2 -> V_6 [ V_4 ] . V_15 = F_3 ( V_11 ) ;
V_2 -> V_6 [ V_4 ] . V_16 = 0 ;
switch ( F_4 ( V_11 ) ) {
case V_17 :
V_2 -> V_6 [ V_4 ] . type = V_18 ;
V_2 -> V_6 [ V_4 ] . V_16 |= V_19 ;
if ( ! ( V_11 -> V_16 & V_20 ) )
V_2 -> V_6 [ V_4 ] . V_16 |=
V_21 ;
if ( ! ( V_2 -> V_6 [ V_4 ] . V_13 & ~ V_22 ) &&
! ( V_2 -> V_6 [ V_4 ] . V_15 & ~ V_22 ) )
V_2 -> V_6 [ V_4 ] . V_16 |=
V_23 ;
break;
case V_24 :
V_2 -> V_6 [ V_4 ] . type = V_25 ;
break;
default:
goto V_12;
}
}
V_2 -> V_26 = V_3 ;
return 0 ;
V_12:
F_5 ( V_2 -> V_6 ) ;
return - V_27 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_26 ; V_4 ++ )
F_7 ( V_2 -> V_6 [ V_4 ] . V_28 ) ;
V_2 -> V_26 = 0 ;
F_5 ( V_2 -> V_6 ) ;
}
static void F_8 ( void * V_29 )
{
struct V_1 * V_2 = V_29 ;
F_9 ( & V_30 ) ;
if ( ! ( -- V_2 -> V_31 ) ) {
F_6 ( V_2 ) ;
F_10 ( V_2 ) ;
}
F_11 ( & V_30 ) ;
F_12 ( V_32 ) ;
}
static int F_13 ( void * V_29 )
{
struct V_1 * V_2 = V_29 ;
int V_33 ;
if ( ! F_14 ( V_32 ) )
return - V_34 ;
F_9 ( & V_30 ) ;
if ( ! V_2 -> V_31 ) {
V_33 = F_1 ( V_2 ) ;
if ( V_33 )
goto V_35;
V_33 = F_15 ( V_2 ) ;
if ( V_33 )
goto V_36;
}
V_2 -> V_31 ++ ;
F_11 ( & V_30 ) ;
return 0 ;
V_36:
F_6 ( V_2 ) ;
V_35:
F_11 ( & V_30 ) ;
F_12 ( V_32 ) ;
return V_33 ;
}
static long F_16 ( void * V_29 ,
unsigned int V_37 , unsigned long V_38 )
{
struct V_1 * V_2 = V_29 ;
unsigned long V_39 ;
if ( V_37 == V_40 ) {
struct V_41 V_42 ;
V_39 = F_17 ( struct V_41 , V_43 ) ;
if ( F_18 ( & V_42 , ( void V_44 * ) V_38 , V_39 ) )
return - V_45 ;
if ( V_42 . V_46 < V_39 )
return - V_27 ;
V_42 . V_16 = V_2 -> V_16 ;
V_42 . V_26 = V_2 -> V_26 ;
V_42 . V_43 = V_2 -> V_43 ;
return F_19 ( ( void V_44 * ) V_38 , & V_42 , V_39 ) ;
} else if ( V_37 == V_47 ) {
struct V_48 V_42 ;
V_39 = F_17 ( struct V_48 , V_49 ) ;
if ( F_18 ( & V_42 , ( void V_44 * ) V_38 , V_39 ) )
return - V_45 ;
if ( V_42 . V_46 < V_39 )
return - V_27 ;
if ( V_42 . V_50 >= V_2 -> V_26 )
return - V_27 ;
V_42 . V_49 = F_20 ( V_42 . V_50 ) ;
V_42 . V_15 = V_2 -> V_6 [ V_42 . V_50 ] . V_15 ;
V_42 . V_16 = V_2 -> V_6 [ V_42 . V_50 ] . V_16 ;
return F_19 ( ( void V_44 * ) V_38 , & V_42 , V_39 ) ;
} else if ( V_37 == V_51 ) {
struct V_52 V_42 ;
V_39 = F_17 ( struct V_52 , V_53 ) ;
if ( F_18 ( & V_42 , ( void V_44 * ) V_38 , V_39 ) )
return - V_45 ;
if ( V_42 . V_46 < V_39 )
return - V_27 ;
if ( V_42 . V_50 >= V_2 -> V_43 )
return - V_27 ;
V_42 . V_16 = V_2 -> V_54 [ V_42 . V_50 ] . V_16 ;
V_42 . V_53 = V_2 -> V_54 [ V_42 . V_50 ] . V_53 ;
return F_19 ( ( void V_44 * ) V_38 , & V_42 , V_39 ) ;
} else if ( V_37 == V_55 ) {
struct V_56 V_57 ;
T_1 * V_58 = NULL ;
int V_33 = 0 ;
V_39 = F_17 ( struct V_56 , V_53 ) ;
if ( F_18 ( & V_57 , ( void V_44 * ) V_38 , V_39 ) )
return - V_45 ;
if ( V_57 . V_46 < V_39 )
return - V_27 ;
if ( V_57 . V_50 >= V_2 -> V_43 )
return - V_27 ;
if ( V_57 . V_16 & ~ ( V_59 |
V_60 ) )
return - V_27 ;
if ( ! ( V_57 . V_16 & V_61 ) ) {
T_2 V_15 ;
if ( V_57 . V_16 & V_62 )
V_15 = sizeof( V_63 ) ;
else if ( V_57 . V_16 & V_64 )
V_15 = sizeof( V_65 ) ;
else
return - V_27 ;
if ( V_57 . V_46 - V_39 < V_15 )
return - V_27 ;
V_58 = F_21 ( ( void V_44 * ) ( V_38 + V_39 ) , V_15 ) ;
if ( F_22 ( V_58 ) )
return F_23 ( V_58 ) ;
}
F_9 ( & V_2 -> V_66 ) ;
V_33 = F_24 ( V_2 , V_57 . V_16 , V_57 . V_50 ,
V_57 . V_14 , V_57 . V_53 , V_58 ) ;
F_11 ( & V_2 -> V_66 ) ;
F_5 ( V_58 ) ;
return V_33 ;
} else if ( V_37 == V_67 )
return - V_27 ;
return - V_68 ;
}
static T_3 F_25 ( struct V_7 V_69 ,
char V_44 * V_70 , T_2 V_53 ,
T_4 V_71 )
{
unsigned int V_72 = 0 ;
if ( ! V_69 . V_28 ) {
V_69 . V_28 =
F_26 ( V_69 . V_13 , V_69 . V_15 ) ;
if ( ! V_69 . V_28 )
return - V_9 ;
}
while ( V_53 ) {
T_2 V_73 ;
if ( V_53 >= 4 && ! ( V_71 % 4 ) ) {
T_5 V_74 ;
V_74 = F_27 ( V_69 . V_28 + V_71 ) ;
if ( F_19 ( V_70 , & V_74 , 4 ) )
goto V_12;
V_73 = 4 ;
} else if ( V_53 >= 2 && ! ( V_71 % 2 ) ) {
T_6 V_74 ;
V_74 = F_28 ( V_69 . V_28 + V_71 ) ;
if ( F_19 ( V_70 , & V_74 , 2 ) )
goto V_12;
V_73 = 2 ;
} else {
T_1 V_74 ;
V_74 = F_29 ( V_69 . V_28 + V_71 ) ;
if ( F_19 ( V_70 , & V_74 , 1 ) )
goto V_12;
V_73 = 1 ;
}
V_53 -= V_73 ;
V_72 += V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
return V_72 ;
V_12:
return - V_45 ;
}
static T_3 F_30 ( void * V_29 , char V_44 * V_70 ,
T_2 V_53 , T_4 * V_75 )
{
struct V_1 * V_2 = V_29 ;
unsigned int V_50 = F_31 ( * V_75 ) ;
T_4 V_71 = * V_75 & V_76 ;
if ( V_50 >= V_2 -> V_26 )
return - V_27 ;
if ( ! ( V_2 -> V_6 [ V_50 ] . V_16 & V_19 ) )
return - V_27 ;
if ( V_2 -> V_6 [ V_50 ] . type & V_18 )
return F_25 ( V_2 -> V_6 [ V_50 ] ,
V_70 , V_53 , V_71 ) ;
else if ( V_2 -> V_6 [ V_50 ] . type & V_25 )
return - V_27 ;
return - V_27 ;
}
static T_3 F_32 ( struct V_7 V_69 ,
const char V_44 * V_70 , T_2 V_53 ,
T_4 V_71 )
{
unsigned int V_72 = 0 ;
if ( ! V_69 . V_28 ) {
V_69 . V_28 =
F_26 ( V_69 . V_13 , V_69 . V_15 ) ;
if ( ! V_69 . V_28 )
return - V_9 ;
}
while ( V_53 ) {
T_2 V_73 ;
if ( V_53 >= 4 && ! ( V_71 % 4 ) ) {
T_5 V_74 ;
if ( F_18 ( & V_74 , V_70 , 4 ) )
goto V_12;
F_33 ( V_74 , V_69 . V_28 + V_71 ) ;
V_73 = 4 ;
} else if ( V_53 >= 2 && ! ( V_71 % 2 ) ) {
T_6 V_74 ;
if ( F_18 ( & V_74 , V_70 , 2 ) )
goto V_12;
F_34 ( V_74 , V_69 . V_28 + V_71 ) ;
V_73 = 2 ;
} else {
T_1 V_74 ;
if ( F_18 ( & V_74 , V_70 , 1 ) )
goto V_12;
F_35 ( V_74 , V_69 . V_28 + V_71 ) ;
V_73 = 1 ;
}
V_53 -= V_73 ;
V_72 += V_73 ;
V_71 += V_73 ;
V_70 += V_73 ;
}
return V_72 ;
V_12:
return - V_45 ;
}
static T_3 F_36 ( void * V_29 , const char V_44 * V_70 ,
T_2 V_53 , T_4 * V_75 )
{
struct V_1 * V_2 = V_29 ;
unsigned int V_50 = F_31 ( * V_75 ) ;
T_4 V_71 = * V_75 & V_76 ;
if ( V_50 >= V_2 -> V_26 )
return - V_27 ;
if ( ! ( V_2 -> V_6 [ V_50 ] . V_16 & V_21 ) )
return - V_27 ;
if ( V_2 -> V_6 [ V_50 ] . type & V_18 )
return F_32 ( V_2 -> V_6 [ V_50 ] ,
V_70 , V_53 , V_71 ) ;
else if ( V_2 -> V_6 [ V_50 ] . type & V_25 )
return - V_27 ;
return - V_27 ;
}
static int F_37 ( struct V_7 V_77 ,
struct V_78 * V_79 )
{
T_7 V_80 , V_81 , V_82 ;
V_80 = V_79 -> V_83 - V_79 -> V_84 ;
V_81 = V_79 -> V_85 &
( ( 1U << ( V_86 - V_87 ) ) - 1 ) ;
V_82 = V_81 << V_87 ;
if ( V_77 . V_15 < V_88 || V_82 + V_80 > V_77 . V_15 )
return - V_27 ;
V_79 -> V_89 = F_38 ( V_79 -> V_89 ) ;
V_79 -> V_85 = ( V_77 . V_13 >> V_87 ) + V_81 ;
return F_39 ( V_79 , V_79 -> V_84 , V_79 -> V_85 ,
V_80 , V_79 -> V_89 ) ;
}
static int F_40 ( void * V_29 , struct V_78 * V_79 )
{
struct V_1 * V_2 = V_29 ;
unsigned int V_50 ;
V_50 = V_79 -> V_85 >> ( V_86 - V_87 ) ;
if ( V_79 -> V_83 < V_79 -> V_84 )
return - V_27 ;
if ( ! ( V_79 -> V_90 & V_91 ) )
return - V_27 ;
if ( V_50 >= V_2 -> V_26 )
return - V_27 ;
if ( V_79 -> V_84 & ~ V_22 )
return - V_27 ;
if ( V_79 -> V_83 & ~ V_22 )
return - V_27 ;
if ( ! ( V_2 -> V_6 [ V_50 ] . V_16 & V_23 ) )
return - V_27 ;
if ( ! ( V_2 -> V_6 [ V_50 ] . V_16 & V_19 )
&& ( V_79 -> V_90 & V_92 ) )
return - V_27 ;
if ( ! ( V_2 -> V_6 [ V_50 ] . V_16 & V_21 )
&& ( V_79 -> V_90 & V_93 ) )
return - V_27 ;
V_79 -> V_94 = V_2 ;
if ( V_2 -> V_6 [ V_50 ] . type & V_18 )
return F_37 ( V_2 -> V_6 [ V_50 ] , V_79 ) ;
else if ( V_2 -> V_6 [ V_50 ] . type & V_25 )
return - V_27 ;
return - V_27 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 ;
int V_33 ;
if ( ! V_2 )
return - V_27 ;
V_98 = F_42 ( V_96 ) ;
if ( ! V_98 ) {
F_43 ( L_1 , V_2 -> V_99 ) ;
return - V_27 ;
}
V_33 = F_44 ( V_96 , & V_100 , V_2 ) ;
if ( V_33 ) {
F_45 ( V_98 ) ;
return V_33 ;
}
F_46 ( & V_2 -> V_66 ) ;
return 0 ;
}
struct V_1 * F_47 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
V_2 = F_48 ( V_96 ) ;
if ( V_2 )
F_45 ( V_96 -> V_97 ) ;
return V_2 ;
}
