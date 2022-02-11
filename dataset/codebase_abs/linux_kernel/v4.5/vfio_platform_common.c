static T_1 F_1 ( const char * V_1 ,
struct V_2 * * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (iter, &reset_list, link) {
if ( ! strcmp ( V_4 -> V_1 , V_1 ) &&
F_4 ( V_4 -> V_7 ) ) {
* V_2 = V_4 -> V_7 ;
V_5 = V_4 -> V_8 ;
break;
}
}
F_5 ( & V_6 ) ;
return V_5 ;
}
static void F_6 ( struct V_9 * V_10 )
{
V_10 -> V_8 = F_1 ( V_10 -> V_1 ,
& V_10 -> V_11 ) ;
if ( ! V_10 -> V_8 ) {
F_7 ( L_1 , V_10 -> V_1 ) ;
V_10 -> V_8 = F_1 ( V_10 -> V_1 ,
& V_10 -> V_11 ) ;
}
}
static void F_8 ( struct V_9 * V_10 )
{
if ( V_10 -> V_8 )
F_9 ( V_10 -> V_11 ) ;
}
static int F_10 ( struct V_9 * V_10 )
{
int V_12 = 0 , V_13 ;
while ( V_10 -> V_14 ( V_10 , V_12 ) )
V_12 ++ ;
V_10 -> V_15 = F_11 ( V_12 , sizeof( struct V_16 ) ,
V_17 ) ;
if ( ! V_10 -> V_15 )
return - V_18 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
struct V_19 * V_20 =
V_10 -> V_14 ( V_10 , V_13 ) ;
if ( ! V_20 )
goto V_21;
V_10 -> V_15 [ V_13 ] . V_22 = V_20 -> V_23 ;
V_10 -> V_15 [ V_13 ] . V_24 = F_12 ( V_20 ) ;
V_10 -> V_15 [ V_13 ] . V_25 = 0 ;
switch ( F_13 ( V_20 ) ) {
case V_26 :
V_10 -> V_15 [ V_13 ] . type = V_27 ;
V_10 -> V_15 [ V_13 ] . V_25 |= V_28 ;
if ( ! ( V_20 -> V_25 & V_29 ) )
V_10 -> V_15 [ V_13 ] . V_25 |=
V_30 ;
if ( ! ( V_10 -> V_15 [ V_13 ] . V_22 & ~ V_31 ) &&
! ( V_10 -> V_15 [ V_13 ] . V_24 & ~ V_31 ) )
V_10 -> V_15 [ V_13 ] . V_25 |=
V_32 ;
break;
case V_33 :
V_10 -> V_15 [ V_13 ] . type = V_34 ;
break;
default:
goto V_21;
}
}
V_10 -> V_35 = V_12 ;
return 0 ;
V_21:
F_14 ( V_10 -> V_15 ) ;
return - V_36 ;
}
static void F_15 ( struct V_9 * V_10 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_10 -> V_35 ; V_13 ++ )
F_16 ( V_10 -> V_15 [ V_13 ] . V_37 ) ;
V_10 -> V_35 = 0 ;
F_14 ( V_10 -> V_15 ) ;
}
static void F_17 ( void * V_38 )
{
struct V_9 * V_10 = V_38 ;
F_2 ( & V_6 ) ;
if ( ! ( -- V_10 -> V_39 ) ) {
if ( V_10 -> V_8 ) {
F_18 ( V_10 -> V_40 , L_2 ) ;
V_10 -> V_8 ( V_10 ) ;
} else {
F_19 ( V_10 -> V_40 , L_3 ) ;
}
F_15 ( V_10 ) ;
F_20 ( V_10 ) ;
}
F_5 ( & V_6 ) ;
F_9 ( V_10 -> V_41 ) ;
}
static int F_21 ( void * V_38 )
{
struct V_9 * V_10 = V_38 ;
int V_42 ;
if ( ! F_4 ( V_10 -> V_41 ) )
return - V_43 ;
F_2 ( & V_6 ) ;
if ( ! V_10 -> V_39 ) {
V_42 = F_10 ( V_10 ) ;
if ( V_42 )
goto V_44;
V_42 = F_22 ( V_10 ) ;
if ( V_42 )
goto V_45;
if ( V_10 -> V_8 ) {
F_18 ( V_10 -> V_40 , L_2 ) ;
V_10 -> V_8 ( V_10 ) ;
} else {
F_19 ( V_10 -> V_40 , L_3 ) ;
}
}
V_10 -> V_39 ++ ;
F_5 ( & V_6 ) ;
return 0 ;
V_45:
F_15 ( V_10 ) ;
V_44:
F_5 ( & V_6 ) ;
F_9 ( V_46 ) ;
return V_42 ;
}
static long F_23 ( void * V_38 ,
unsigned int V_47 , unsigned long V_48 )
{
struct V_9 * V_10 = V_38 ;
unsigned long V_49 ;
if ( V_47 == V_50 ) {
struct V_51 V_52 ;
V_49 = F_24 ( struct V_51 , V_53 ) ;
if ( F_25 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 )
return - V_36 ;
if ( V_10 -> V_8 )
V_10 -> V_25 |= V_57 ;
V_52 . V_25 = V_10 -> V_25 ;
V_52 . V_35 = V_10 -> V_35 ;
V_52 . V_53 = V_10 -> V_53 ;
return F_26 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ?
- V_55 : 0 ;
} else if ( V_47 == V_58 ) {
struct V_59 V_52 ;
V_49 = F_24 ( struct V_59 , V_60 ) ;
if ( F_25 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 )
return - V_36 ;
if ( V_52 . V_61 >= V_10 -> V_35 )
return - V_36 ;
V_52 . V_60 = F_27 ( V_52 . V_61 ) ;
V_52 . V_24 = V_10 -> V_15 [ V_52 . V_61 ] . V_24 ;
V_52 . V_25 = V_10 -> V_15 [ V_52 . V_61 ] . V_25 ;
return F_26 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ?
- V_55 : 0 ;
} else if ( V_47 == V_62 ) {
struct V_63 V_52 ;
V_49 = F_24 ( struct V_63 , V_64 ) ;
if ( F_25 ( & V_52 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_52 . V_56 < V_49 )
return - V_36 ;
if ( V_52 . V_61 >= V_10 -> V_53 )
return - V_36 ;
V_52 . V_25 = V_10 -> V_65 [ V_52 . V_61 ] . V_25 ;
V_52 . V_64 = V_10 -> V_65 [ V_52 . V_61 ] . V_64 ;
return F_26 ( ( void V_54 * ) V_48 , & V_52 , V_49 ) ?
- V_55 : 0 ;
} else if ( V_47 == V_66 ) {
struct V_67 V_68 ;
T_2 * V_69 = NULL ;
int V_42 = 0 ;
V_49 = F_24 ( struct V_67 , V_64 ) ;
if ( F_25 ( & V_68 , ( void V_54 * ) V_48 , V_49 ) )
return - V_55 ;
if ( V_68 . V_56 < V_49 )
return - V_36 ;
if ( V_68 . V_61 >= V_10 -> V_53 )
return - V_36 ;
if ( V_68 . V_25 & ~ ( V_70 |
V_71 ) )
return - V_36 ;
if ( ! ( V_68 . V_25 & V_72 ) ) {
T_3 V_24 ;
if ( V_68 . V_25 & V_73 )
V_24 = sizeof( V_74 ) ;
else if ( V_68 . V_25 & V_75 )
V_24 = sizeof( V_76 ) ;
else
return - V_36 ;
if ( V_68 . V_56 - V_49 < V_24 )
return - V_36 ;
V_69 = F_28 ( ( void V_54 * ) ( V_48 + V_49 ) , V_24 ) ;
if ( F_29 ( V_69 ) )
return F_30 ( V_69 ) ;
}
F_2 ( & V_10 -> V_77 ) ;
V_42 = F_31 ( V_10 , V_68 . V_25 , V_68 . V_61 ,
V_68 . V_23 , V_68 . V_64 , V_69 ) ;
F_5 ( & V_10 -> V_77 ) ;
F_14 ( V_69 ) ;
return V_42 ;
} else if ( V_47 == V_78 ) {
if ( V_10 -> V_8 )
return V_10 -> V_8 ( V_10 ) ;
else
return - V_36 ;
}
return - V_79 ;
}
static T_4 F_32 ( struct V_16 * V_80 ,
char V_54 * V_81 , T_3 V_64 ,
T_5 V_82 )
{
unsigned int V_83 = 0 ;
if ( ! V_80 -> V_37 ) {
V_80 -> V_37 =
F_33 ( V_80 -> V_22 , V_80 -> V_24 ) ;
if ( ! V_80 -> V_37 )
return - V_18 ;
}
while ( V_64 ) {
T_3 V_84 ;
if ( V_64 >= 4 && ! ( V_82 % 4 ) ) {
T_6 V_85 ;
V_85 = F_34 ( V_80 -> V_37 + V_82 ) ;
if ( F_26 ( V_81 , & V_85 , 4 ) )
goto V_21;
V_84 = 4 ;
} else if ( V_64 >= 2 && ! ( V_82 % 2 ) ) {
T_7 V_85 ;
V_85 = F_35 ( V_80 -> V_37 + V_82 ) ;
if ( F_26 ( V_81 , & V_85 , 2 ) )
goto V_21;
V_84 = 2 ;
} else {
T_2 V_85 ;
V_85 = F_36 ( V_80 -> V_37 + V_82 ) ;
if ( F_26 ( V_81 , & V_85 , 1 ) )
goto V_21;
V_84 = 1 ;
}
V_64 -= V_84 ;
V_83 += V_84 ;
V_82 += V_84 ;
V_81 += V_84 ;
}
return V_83 ;
V_21:
return - V_55 ;
}
static T_4 F_37 ( void * V_38 , char V_54 * V_81 ,
T_3 V_64 , T_5 * V_86 )
{
struct V_9 * V_10 = V_38 ;
unsigned int V_61 = F_38 ( * V_86 ) ;
T_5 V_82 = * V_86 & V_87 ;
if ( V_61 >= V_10 -> V_35 )
return - V_36 ;
if ( ! ( V_10 -> V_15 [ V_61 ] . V_25 & V_28 ) )
return - V_36 ;
if ( V_10 -> V_15 [ V_61 ] . type & V_27 )
return F_32 ( & V_10 -> V_15 [ V_61 ] ,
V_81 , V_64 , V_82 ) ;
else if ( V_10 -> V_15 [ V_61 ] . type & V_34 )
return - V_36 ;
return - V_36 ;
}
static T_4 F_39 ( struct V_16 * V_80 ,
const char V_54 * V_81 , T_3 V_64 ,
T_5 V_82 )
{
unsigned int V_83 = 0 ;
if ( ! V_80 -> V_37 ) {
V_80 -> V_37 =
F_33 ( V_80 -> V_22 , V_80 -> V_24 ) ;
if ( ! V_80 -> V_37 )
return - V_18 ;
}
while ( V_64 ) {
T_3 V_84 ;
if ( V_64 >= 4 && ! ( V_82 % 4 ) ) {
T_6 V_85 ;
if ( F_25 ( & V_85 , V_81 , 4 ) )
goto V_21;
F_40 ( V_85 , V_80 -> V_37 + V_82 ) ;
V_84 = 4 ;
} else if ( V_64 >= 2 && ! ( V_82 % 2 ) ) {
T_7 V_85 ;
if ( F_25 ( & V_85 , V_81 , 2 ) )
goto V_21;
F_41 ( V_85 , V_80 -> V_37 + V_82 ) ;
V_84 = 2 ;
} else {
T_2 V_85 ;
if ( F_25 ( & V_85 , V_81 , 1 ) )
goto V_21;
F_42 ( V_85 , V_80 -> V_37 + V_82 ) ;
V_84 = 1 ;
}
V_64 -= V_84 ;
V_83 += V_84 ;
V_82 += V_84 ;
V_81 += V_84 ;
}
return V_83 ;
V_21:
return - V_55 ;
}
static T_4 F_43 ( void * V_38 , const char V_54 * V_81 ,
T_3 V_64 , T_5 * V_86 )
{
struct V_9 * V_10 = V_38 ;
unsigned int V_61 = F_38 ( * V_86 ) ;
T_5 V_82 = * V_86 & V_87 ;
if ( V_61 >= V_10 -> V_35 )
return - V_36 ;
if ( ! ( V_10 -> V_15 [ V_61 ] . V_25 & V_30 ) )
return - V_36 ;
if ( V_10 -> V_15 [ V_61 ] . type & V_27 )
return F_39 ( & V_10 -> V_15 [ V_61 ] ,
V_81 , V_64 , V_82 ) ;
else if ( V_10 -> V_15 [ V_61 ] . type & V_34 )
return - V_36 ;
return - V_36 ;
}
static int F_44 ( struct V_16 V_88 ,
struct V_89 * V_90 )
{
T_8 V_91 , V_92 , V_93 ;
V_91 = V_90 -> V_94 - V_90 -> V_95 ;
V_92 = V_90 -> V_96 &
( ( 1U << ( V_97 - V_98 ) ) - 1 ) ;
V_93 = V_92 << V_98 ;
if ( V_88 . V_24 < V_99 || V_93 + V_91 > V_88 . V_24 )
return - V_36 ;
V_90 -> V_100 = F_45 ( V_90 -> V_100 ) ;
V_90 -> V_96 = ( V_88 . V_22 >> V_98 ) + V_92 ;
return F_46 ( V_90 , V_90 -> V_95 , V_90 -> V_96 ,
V_91 , V_90 -> V_100 ) ;
}
static int F_47 ( void * V_38 , struct V_89 * V_90 )
{
struct V_9 * V_10 = V_38 ;
unsigned int V_61 ;
V_61 = V_90 -> V_96 >> ( V_97 - V_98 ) ;
if ( V_90 -> V_94 < V_90 -> V_95 )
return - V_36 ;
if ( ! ( V_90 -> V_101 & V_102 ) )
return - V_36 ;
if ( V_61 >= V_10 -> V_35 )
return - V_36 ;
if ( V_90 -> V_95 & ~ V_31 )
return - V_36 ;
if ( V_90 -> V_94 & ~ V_31 )
return - V_36 ;
if ( ! ( V_10 -> V_15 [ V_61 ] . V_25 & V_32 ) )
return - V_36 ;
if ( ! ( V_10 -> V_15 [ V_61 ] . V_25 & V_28 )
&& ( V_90 -> V_101 & V_103 ) )
return - V_36 ;
if ( ! ( V_10 -> V_15 [ V_61 ] . V_25 & V_30 )
&& ( V_90 -> V_101 & V_104 ) )
return - V_36 ;
V_90 -> V_105 = V_10 ;
if ( V_10 -> V_15 [ V_61 ] . type & V_27 )
return F_44 ( V_10 -> V_15 [ V_61 ] , V_90 ) ;
else if ( V_10 -> V_15 [ V_61 ] . type & V_34 )
return - V_36 ;
return - V_36 ;
}
int F_48 ( struct V_9 * V_10 ,
struct V_40 * V_106 )
{
struct V_107 * V_108 ;
int V_42 ;
if ( ! V_10 )
return - V_36 ;
V_42 = F_49 ( V_106 , L_4 , & V_10 -> V_1 ) ;
if ( V_42 ) {
F_50 ( L_5 , V_10 -> V_109 ) ;
return - V_36 ;
}
V_10 -> V_40 = V_106 ;
V_108 = F_51 ( V_106 ) ;
if ( ! V_108 ) {
F_50 ( L_6 , V_10 -> V_109 ) ;
return - V_36 ;
}
V_42 = F_52 ( V_106 , & V_110 , V_10 ) ;
if ( V_42 ) {
F_53 ( V_108 ) ;
return V_42 ;
}
F_6 ( V_10 ) ;
F_54 ( & V_10 -> V_77 ) ;
return 0 ;
}
struct V_9 * F_55 ( struct V_40 * V_106 )
{
struct V_9 * V_10 ;
V_10 = F_56 ( V_106 ) ;
if ( V_10 ) {
F_8 ( V_10 ) ;
F_53 ( V_106 -> V_107 ) ;
}
return V_10 ;
}
void F_57 ( struct V_3 * V_111 )
{
F_2 ( & V_6 ) ;
F_58 ( & V_111 -> V_112 , & V_113 ) ;
F_5 ( & V_6 ) ;
}
void F_59 ( const char * V_1 ,
T_1 V_114 )
{
struct V_3 * V_4 , * V_115 ;
F_2 ( & V_6 ) ;
F_60 (iter, temp, &reset_list, link) {
if ( ! strcmp ( V_4 -> V_1 , V_1 ) && ( V_4 -> V_8 == V_114 ) ) {
F_61 ( & V_4 -> V_112 ) ;
break;
}
}
F_5 ( & V_6 ) ;
}
