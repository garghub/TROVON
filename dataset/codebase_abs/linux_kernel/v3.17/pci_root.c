static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
int F_3 ( T_1 V_3 )
{
int V_4 ;
struct V_1 * V_5 ;
V_4 = F_4 ( V_3 , & V_5 ) ;
if ( V_4 )
return 0 ;
V_4 = F_5 ( V_5 , V_6 ) ;
if ( V_4 )
return 0 ;
else
return 1 ;
}
static T_2
F_6 ( struct V_7 * V_8 , void * V_9 )
{
struct V_8 * V_10 = V_9 ;
struct V_11 V_12 ;
T_2 V_13 ;
V_13 = F_7 ( V_8 , & V_12 ) ;
if ( F_8 ( V_13 ) )
return V_14 ;
if ( ( V_12 . V_15 > 0 ) &&
( V_12 . V_16 == V_17 ) ) {
V_10 -> V_18 = V_12 . V_19 ;
V_10 -> V_20 = V_12 . V_19 + V_12 . V_15 - 1 ;
}
return V_14 ;
}
static T_2 F_9 ( T_1 V_3 ,
struct V_8 * V_10 )
{
T_2 V_13 ;
V_10 -> V_18 = - 1 ;
V_13 =
F_10 ( V_3 , V_21 ,
F_6 , V_10 ) ;
if ( F_8 ( V_13 ) )
return V_13 ;
if ( V_10 -> V_18 == - 1 )
return V_22 ;
return V_14 ;
}
static void F_11 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 ,
struct V_27 * V_28 , int V_29 )
{
char V_30 [ 80 ] ;
int V_31 , V_32 = 0 ;
struct V_27 * V_33 ;
V_30 [ 0 ] = '\0' ;
for ( V_31 = 0 , V_33 = V_28 ; V_31 < V_29 ; V_31 ++ , V_33 ++ )
if ( V_26 & V_33 -> V_34 )
V_32 += snprintf ( V_30 + V_32 , sizeof( V_30 ) - V_32 , L_1 ,
V_32 ? L_2 : L_3 , V_33 -> V_35 ) ;
F_12 ( & V_24 -> V_5 -> V_36 , L_4 , V_25 , V_30 ) ;
}
static void F_13 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 )
{
F_11 ( V_24 , V_25 , V_26 , V_37 ,
F_14 ( V_37 ) ) ;
}
static void F_15 ( struct V_23 * V_24 , char * V_25 , T_3 V_26 )
{
F_11 ( V_24 , V_25 , V_26 , V_38 ,
F_14 ( V_38 ) ) ;
}
static T_2 F_16 ( T_1 V_3 ,
const T_3 * V_39 , T_3 * V_40 )
{
struct V_41 V_42 = {
. V_43 = V_44 ,
. V_45 = 1 ,
. V_46 . V_47 = 12 ,
. V_46 . V_48 = ( void * ) V_39 ,
} ;
T_2 V_13 ;
V_13 = F_17 ( V_3 , & V_42 ) ;
if ( F_18 ( V_13 ) ) {
* V_40 = * ( ( T_3 * ) ( V_42 . V_4 . V_48 + 8 ) ) ;
F_19 ( V_42 . V_4 . V_48 ) ;
}
return V_13 ;
}
static T_2 F_20 ( struct V_23 * V_24 ,
T_3 V_49 ,
T_3 * V_50 )
{
T_2 V_13 ;
T_3 V_51 , V_39 [ 3 ] ;
V_49 &= V_52 ;
V_49 |= V_24 -> V_53 ;
V_39 [ V_54 ] = V_55 ;
V_39 [ V_56 ] = V_49 ;
if ( V_50 ) {
* V_50 &= V_57 ;
V_39 [ V_58 ] = * V_50 | V_24 -> V_59 ;
} else {
V_39 [ V_58 ] = V_24 -> V_59 ;
}
V_13 = F_16 ( V_24 -> V_5 -> V_3 , V_39 , & V_51 ) ;
if ( F_18 ( V_13 ) ) {
V_24 -> V_53 = V_49 ;
if ( V_50 )
* V_50 = V_51 ;
}
return V_13 ;
}
static T_2 F_21 ( struct V_23 * V_24 , T_3 V_60 )
{
T_2 V_13 ;
F_22 ( & V_61 ) ;
V_13 = F_20 ( V_24 , V_60 , NULL ) ;
F_23 ( & V_61 ) ;
return V_13 ;
}
struct V_23 * F_24 ( T_1 V_3 )
{
struct V_23 * V_24 ;
struct V_1 * V_5 ;
if ( F_4 ( V_3 , & V_5 ) ||
F_5 ( V_5 , V_6 ) )
return NULL ;
V_24 = F_25 ( V_5 ) ;
return V_24 ;
}
struct V_62 * F_26 ( T_1 V_3 )
{
int V_36 , V_63 ;
unsigned long long V_64 ;
T_2 V_13 ;
T_1 V_65 ;
struct V_66 * V_67 ;
struct V_62 * V_68 = NULL ;
struct V_69 * V_70 , * V_71 ;
struct V_23 * V_24 ;
F_27 ( V_72 ) ;
V_65 = V_3 ;
while ( ! F_3 ( V_65 ) ) {
V_70 = F_28 ( sizeof( struct V_69 ) , V_73 ) ;
if ( ! V_70 )
goto V_74;
F_29 ( & V_70 -> V_70 ) ;
V_70 -> V_3 = V_65 ;
F_30 ( & V_70 -> V_70 , & V_72 ) ;
V_13 = F_31 ( V_65 , & V_65 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
}
V_24 = F_24 ( V_65 ) ;
if ( ! V_24 )
goto V_74;
V_67 = V_24 -> V_75 ;
F_32 (node, &device_list, node) {
T_1 V_76 = V_70 -> V_3 ;
V_13 = F_33 ( V_76 , L_5 , NULL , & V_64 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
V_36 = ( V_64 >> 16 ) & 0xffff ;
V_63 = V_64 & 0xffff ;
V_68 = F_34 ( V_67 , F_35 ( V_36 , V_63 ) ) ;
if ( ! V_68 || V_76 == V_3 )
break;
V_67 = V_68 -> V_77 ;
F_36 ( V_68 ) ;
if ( ! V_67 ) {
F_37 ( & V_68 -> V_36 , L_6 ) ;
V_68 = NULL ;
break;
}
}
V_74:
F_38 (node, tmp, &device_list, node)
F_19 ( V_70 ) ;
return V_68 ;
}
T_2 F_39 ( T_1 V_3 , T_3 * V_78 , T_3 V_79 )
{
struct V_23 * V_24 ;
T_2 V_13 = V_14 ;
T_3 V_80 , V_39 [ 3 ] ;
if ( ! V_78 )
return V_81 ;
V_80 = * V_78 & V_57 ;
if ( ( V_80 & V_79 ) != V_79 )
return V_82 ;
V_24 = F_24 ( V_3 ) ;
if ( ! V_24 )
return V_83 ;
F_22 ( & V_61 ) ;
* V_78 = V_80 | V_24 -> V_59 ;
if ( ( V_24 -> V_59 & V_80 ) == V_80 )
goto V_74;
while ( * V_78 ) {
V_13 = F_20 ( V_24 , V_24 -> V_53 , V_78 ) ;
if ( F_8 ( V_13 ) )
goto V_74;
if ( V_80 == * V_78 )
break;
F_15 ( V_24 , L_7 ,
V_80 & ~ ( * V_78 ) ) ;
V_80 = * V_78 ;
}
if ( ( V_80 & V_79 ) != V_79 ) {
F_15 ( V_24 , L_8 ,
V_79 & ~ ( V_80 ) ) ;
V_13 = V_84 ;
goto V_74;
}
V_39 [ V_54 ] = 0 ;
V_39 [ V_56 ] = V_24 -> V_53 ;
V_39 [ V_58 ] = V_80 ;
V_13 = F_16 ( V_3 , V_39 , V_78 ) ;
if ( F_18 ( V_13 ) )
V_24 -> V_59 = * V_78 ;
V_74:
F_23 ( & V_61 ) ;
return V_13 ;
}
static void F_40 ( struct V_23 * V_24 , int * V_85 ,
int * V_86 )
{
T_3 V_49 , V_50 , V_87 ;
T_2 V_13 ;
struct V_1 * V_5 = V_24 -> V_5 ;
T_1 V_3 = V_5 -> V_3 ;
V_49 = V_88 ;
if ( F_41 () )
V_49 |= V_89 ;
if ( F_42 () )
V_49 |= V_90 | V_91 ;
if ( F_43 () )
V_49 |= V_92 ;
F_13 ( V_24 , L_9 , V_49 ) ;
V_13 = F_21 ( V_24 , V_49 ) ;
if ( F_8 ( V_13 ) ) {
F_12 ( & V_5 -> V_36 , L_10 ,
F_44 ( V_13 ) ) ;
* V_85 = 1 ;
return;
}
if ( V_93 ) {
F_12 ( & V_5 -> V_36 , L_11 ) ;
return;
}
if ( ( V_49 & V_94 ) != V_94 ) {
F_13 ( V_24 , L_12 ,
V_94 ) ;
return;
}
V_50 = V_95
| V_96
| V_97 ;
if ( F_45 () ) {
if ( F_46 () )
F_12 ( & V_5 -> V_36 ,
L_13 ) ;
else
V_50 |= V_98 ;
}
V_87 = V_50 ;
V_13 = F_39 ( V_3 , & V_50 ,
V_95 ) ;
if ( F_18 ( V_13 ) ) {
F_15 ( V_24 , L_14 , V_50 ) ;
if ( V_99 . V_100 & V_101 ) {
* V_86 = 1 ;
}
} else {
F_15 ( V_24 , L_15 , V_87 ) ;
F_15 ( V_24 , L_16 , V_50 ) ;
F_12 ( & V_5 -> V_36 , L_10 ,
F_44 ( V_13 ) ) ;
* V_85 = 1 ;
}
}
static int F_47 ( struct V_1 * V_5 ,
const struct V_102 * V_103 )
{
unsigned long long V_104 , V_75 ;
T_2 V_13 ;
int V_51 ;
struct V_23 * V_24 ;
T_1 V_3 = V_5 -> V_3 ;
int V_85 = 0 , V_86 = 0 ;
V_24 = F_28 ( sizeof( struct V_23 ) , V_73 ) ;
if ( ! V_24 )
return - V_105 ;
V_104 = 0 ;
V_13 = F_33 ( V_3 , V_106 , NULL ,
& V_104 ) ;
if ( F_8 ( V_13 ) && V_13 != V_107 ) {
F_48 ( & V_5 -> V_36 , L_17 ) ;
V_51 = - V_108 ;
goto V_20;
}
V_24 -> V_109 . V_60 = V_110 ;
V_13 = F_9 ( V_3 , & V_24 -> V_109 ) ;
if ( F_8 ( V_13 ) ) {
V_24 -> V_109 . V_20 = 0xFF ;
F_49 ( & V_5 -> V_36 ,
V_111 L_18 ) ;
V_13 = F_33 ( V_3 , V_112 ,
NULL , & V_75 ) ;
if ( F_18 ( V_13 ) )
V_24 -> V_109 . V_18 = V_75 ;
else if ( V_13 == V_107 )
V_24 -> V_109 . V_18 = 0 ;
else {
F_48 ( & V_5 -> V_36 , L_19 ) ;
V_51 = - V_108 ;
goto V_20;
}
}
V_24 -> V_5 = V_5 ;
V_24 -> V_104 = V_104 & 0xFFFF ;
strcpy ( F_50 ( V_5 ) , V_113 ) ;
strcpy ( F_51 ( V_5 ) , V_114 ) ;
V_5 -> V_115 = V_24 ;
F_52 ( V_116 L_20 ,
F_50 ( V_5 ) , F_53 ( V_5 ) ,
V_24 -> V_104 , & V_24 -> V_109 ) ;
V_24 -> V_117 = F_54 ( V_3 ) ;
F_40 ( V_24 , & V_85 , & V_86 ) ;
V_24 -> V_75 = F_55 ( V_24 ) ;
if ( ! V_24 -> V_75 ) {
F_48 ( & V_5 -> V_36 ,
L_21 ,
V_24 -> V_104 , ( unsigned int ) V_24 -> V_109 . V_18 ) ;
V_5 -> V_115 = NULL ;
V_51 = - V_108 ;
goto V_20;
}
if ( V_86 ) {
F_12 ( & V_5 -> V_36 , L_22 ) ;
F_56 ( V_24 -> V_75 ) ;
}
if ( V_85 )
F_57 () ;
F_58 ( V_5 ) ;
if ( V_5 -> V_118 . V_60 . V_119 )
F_59 ( V_24 -> V_75 -> V_120 , true ) ;
if ( V_121 != V_122 ) {
F_60 ( V_24 -> V_75 ) ;
F_61 ( V_24 -> V_75 ) ;
}
F_62 () ;
F_63 ( V_24 -> V_75 ) ;
F_64 () ;
return 1 ;
V_20:
F_19 ( V_24 ) ;
return V_51 ;
}
static void F_65 ( struct V_1 * V_5 )
{
struct V_23 * V_24 = F_25 ( V_5 ) ;
F_62 () ;
F_66 ( V_24 -> V_75 ) ;
F_59 ( V_24 -> V_75 -> V_120 , false ) ;
F_67 ( V_5 ) ;
F_68 ( V_24 -> V_75 ) ;
F_64 () ;
F_19 ( V_24 ) ;
}
void T_4 F_69 ( void )
{
F_70 () ;
if ( V_123 )
return;
F_71 () ;
F_72 ( & V_124 , L_23 ) ;
}
