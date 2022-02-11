struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( V_3 -> V_5 < sizeof( * V_4 ) ) ;
if ( ! V_3 -> V_6 || ! V_3 -> V_6 -> V_7 ) {
F_3 ( V_8 L_1 ) ;
F_4 () ;
}
V_4 = V_3 -> V_6 -> V_7 ( V_3 -> V_5 ) ;
if ( NULL != V_4 ) {
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = V_11 ;
}
return V_4 ;
}
static int F_6 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
unsigned long V_12 ;
bool V_13 ;
F_7 ( V_3 -> V_14 , V_12 ) ;
V_13 = V_4 -> V_15 != V_16 && V_4 -> V_15 != V_17 ;
F_8 ( V_3 -> V_14 , V_12 ) ;
return V_13 ;
}
int F_9 ( struct V_2 * V_3 , struct V_1 * V_4 ,
int V_18 , int V_19 )
{
bool V_20 ;
int V_21 = 0 ;
F_10 ( V_4 -> V_10 , V_11 ) ;
if ( V_18 ) {
if ( F_6 ( V_3 , V_4 ) )
return 0 ;
return - V_22 ;
}
V_20 = V_3 -> V_23 && F_11 ( V_3 -> V_23 ) ;
if ( V_20 )
F_12 ( V_3 -> V_23 ) ;
if ( V_19 )
V_21 = F_13 ( V_4 -> V_9 , F_6 ( V_3 , V_4 ) ) ;
else
F_14 ( V_4 -> V_9 , F_6 ( V_3 , V_4 ) ) ;
if ( V_20 )
F_15 ( V_3 -> V_23 ) ;
return V_21 ;
}
int F_16 ( struct V_2 * V_3 , struct V_1 * V_4 ,
struct V_24 * V_25 )
{
F_10 ( V_4 -> V_10 , V_11 ) ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
return F_17 ( V_3 , V_27 , V_3 , V_4 , V_25 ) ;
}
void * F_18 ( struct V_2 * V_3 ,
struct V_1 * V_28 )
{
if ( V_3 -> V_6 -> V_29 )
return V_3 -> V_6 -> V_29 ( V_28 ) ;
return NULL ;
}
void F_19 ( struct V_2 * V_3 ,
const struct V_30 * V_31 ,
struct V_32 * V_33 ,
T_1 * V_14 ,
enum V_34 type ,
enum V_35 V_36 ,
unsigned int V_5 ,
void * V_37 ,
struct V_38 * V_6 ,
struct V_39 * V_23 )
{
F_2 ( ! V_3 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_14 = V_14 ;
V_3 -> V_23 = V_23 ;
V_3 -> V_33 = V_33 ;
V_3 -> type = type ;
V_3 -> V_36 = V_36 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_31 = V_31 ;
V_3 -> V_40 = V_37 ;
V_3 -> V_6 = V_6 ;
F_2 ( ! V_3 -> V_31 -> V_41 ) ;
F_2 ( ! V_3 -> V_31 -> V_42 ) ;
F_2 ( ! V_3 -> V_31 -> V_43 ) ;
F_2 ( ! V_3 -> V_31 -> V_44 ) ;
F_2 ( ! V_14 ) ;
F_2 ( ! V_3 -> V_6 ) ;
F_20 ( & V_3 -> V_45 ) ;
F_5 ( & V_3 -> V_46 ) ;
F_21 ( & V_3 -> V_47 ) ;
}
int F_22 ( struct V_2 * V_3 )
{
int V_48 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
if ( V_3 -> V_49 ) {
F_23 ( 1 , L_2 ) ;
return 1 ;
}
if ( V_3 -> V_50 ) {
F_23 ( 1 , L_3 ) ;
return 1 ;
}
if ( V_3 -> V_51 ) {
F_23 ( 1 , L_4 ) ;
return 1 ;
}
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( NULL == V_3 -> V_53 [ V_48 ] )
continue;
if ( V_3 -> V_53 [ V_48 ] -> V_54 ) {
F_23 ( 1 , L_5 , V_48 ) ;
return 1 ;
}
if ( V_3 -> V_53 [ V_48 ] -> V_15 == V_17 ) {
F_23 ( 1 , L_6 , V_48 ) ;
return 1 ;
}
if ( V_3 -> V_53 [ V_48 ] -> V_15 == V_16 ) {
F_23 ( 1 , L_7 , V_48 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_48 ;
F_23 ( 1 , L_8 , V_55 ) ;
if ( ! V_3 )
return 0 ;
if ( V_3 -> V_49 || V_3 -> V_50 ) {
F_23 ( 1 , L_9 ) ;
return - V_56 ;
}
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ )
if ( V_3 -> V_53 [ V_48 ] && V_3 -> V_53 [ V_48 ] -> V_54 ) {
F_23 ( 1 , L_10 ) ;
return - V_56 ;
}
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( NULL == V_3 -> V_53 [ V_48 ] )
continue;
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_53 [ V_48 ] ) ;
F_25 ( V_3 -> V_53 [ V_48 ] ) ;
V_3 -> V_53 [ V_48 ] = NULL ;
}
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
unsigned long V_12 = 0 ;
int V_48 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
F_27 ( & V_3 -> V_46 ) ;
F_7 ( V_3 -> V_14 , V_12 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( NULL == V_3 -> V_53 [ V_48 ] )
continue;
if ( V_3 -> V_53 [ V_48 ] -> V_15 == V_17 ) {
F_28 ( & V_3 -> V_53 [ V_48 ] -> V_57 ) ;
V_3 -> V_53 [ V_48 ] -> V_15 = V_58 ;
F_29 ( & V_3 -> V_53 [ V_48 ] -> V_9 ) ;
}
}
F_8 ( V_3 -> V_14 , V_12 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( NULL == V_3 -> V_53 [ V_48 ] )
continue;
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_53 [ V_48 ] ) ;
}
F_21 ( & V_3 -> V_47 ) ;
}
enum V_35 F_30 ( struct V_2 * V_3 )
{
enum V_35 V_36 = V_3 -> V_36 ;
F_2 ( V_59 == V_36 ) ;
if ( V_60 == V_36 ) {
if ( V_61 == V_3 -> V_62 ) {
V_36 = V_63 ;
V_3 -> V_62 = V_63 ;
} else {
V_36 = V_61 ;
V_3 -> V_62 = V_61 ;
}
}
return V_36 ;
}
static void F_31 ( struct V_2 * V_3 , struct V_64 * V_65 ,
struct V_1 * V_4 , enum V_34 type )
{
F_10 ( V_4 -> V_10 , V_11 ) ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
V_65 -> V_66 = V_4 -> V_48 ;
V_65 -> type = type ;
V_65 -> V_67 = V_4 -> V_67 ;
switch ( V_65 -> V_67 ) {
case V_68 :
V_65 -> V_69 . V_70 = V_4 -> V_71 ;
V_65 -> V_72 = V_4 -> V_73 ;
break;
case V_74 :
V_65 -> V_69 . V_75 = V_4 -> V_76 ;
V_65 -> V_72 = V_4 -> V_73 ;
break;
case V_77 :
V_65 -> V_69 . V_70 = V_4 -> V_71 ;
break;
case V_78 :
break;
}
V_65 -> V_12 = V_79 ;
if ( V_4 -> V_54 )
V_65 -> V_12 |= V_80 ;
switch ( V_4 -> V_15 ) {
case V_81 :
case V_17 :
case V_16 :
V_65 -> V_12 |= V_82 ;
break;
case V_58 :
V_65 -> V_12 |= V_83 ;
case V_84 :
V_65 -> V_12 |= V_85 ;
break;
case V_86 :
case V_87 :
break;
}
V_65 -> V_36 = V_4 -> V_36 ;
V_65 -> V_88 = V_4 -> V_89 ;
V_65 -> V_90 = V_4 -> V_91 ;
V_65 -> V_92 = V_4 -> V_93 >> 1 ;
}
int F_32 ( struct V_2 * V_3 )
{
int V_21 ;
F_33 ( V_3 ) ;
V_21 = F_24 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_21 ;
}
int F_35 ( struct V_2 * V_3 ,
unsigned int V_94 , unsigned int V_73 ,
enum V_95 V_67 )
{
unsigned int V_48 ;
int V_96 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
V_96 = F_24 ( V_3 ) ;
if ( 0 != V_96 )
return V_96 ;
for ( V_48 = 0 ; V_48 < V_94 ; V_48 ++ ) {
V_3 -> V_53 [ V_48 ] = F_1 ( V_3 ) ;
if ( NULL == V_3 -> V_53 [ V_48 ] )
break;
V_3 -> V_53 [ V_48 ] -> V_48 = V_48 ;
V_3 -> V_53 [ V_48 ] -> V_67 = V_67 ;
V_3 -> V_53 [ V_48 ] -> V_73 = V_73 ;
switch ( V_67 ) {
case V_68 :
V_3 -> V_53 [ V_48 ] -> V_71 = F_36 ( V_73 ) * V_48 ;
break;
case V_74 :
case V_77 :
case V_78 :
break;
}
}
if ( ! V_48 )
return - V_97 ;
F_23 ( 1 , L_11 , V_48 , V_73 ) ;
return V_48 ;
}
int F_37 ( struct V_2 * V_3 ,
unsigned int V_94 , unsigned int V_73 ,
enum V_95 V_67 )
{
int V_21 ;
F_33 ( V_3 ) ;
V_21 = F_35 ( V_3 , V_94 , V_73 , V_67 ) ;
F_34 ( V_3 ) ;
return V_21 ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_98 * V_99 )
{
unsigned int V_91 , V_100 ;
int V_101 ;
if ( V_99 -> V_67 != V_68 &&
V_99 -> V_67 != V_74 &&
V_99 -> V_67 != V_77 ) {
F_23 ( 1 , L_12 ) ;
return - V_102 ;
}
F_33 ( V_3 ) ;
if ( V_99 -> type != V_3 -> type ) {
F_23 ( 1 , L_13 ) ;
V_101 = - V_102 ;
goto V_9;
}
if ( V_3 -> V_49 ) {
F_23 ( 1 , L_14 ) ;
V_101 = - V_56 ;
goto V_9;
}
if ( ! F_39 ( & V_3 -> V_47 ) ) {
F_23 ( 1 , L_15 ) ;
V_101 = - V_56 ;
goto V_9;
}
if ( V_99 -> V_100 == 0 ) {
F_23 ( 1 , L_16 , V_99 -> V_100 ) ;
V_101 = F_24 ( V_3 ) ;
goto V_9;
}
V_100 = V_99 -> V_100 ;
if ( V_100 > V_52 )
V_100 = V_52 ;
V_91 = 0 ;
V_3 -> V_31 -> V_41 ( V_3 , & V_100 , & V_91 ) ;
F_23 ( 1 , L_17 ,
V_100 , V_91 ,
( unsigned int ) ( ( V_100 * F_36 ( V_91 ) ) >> V_103 ) ) ;
V_101 = F_35 ( V_3 , V_100 , V_91 , V_99 -> V_67 ) ;
if ( V_101 < 0 ) {
F_23 ( 1 , L_18 , V_101 ) ;
goto V_9;
}
V_99 -> V_100 = V_101 ;
V_101 = 0 ;
V_9:
F_34 ( V_3 ) ;
return V_101 ;
}
int F_40 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
int V_21 = - V_102 ;
F_33 ( V_3 ) ;
if ( F_41 ( V_65 -> type != V_3 -> type ) ) {
F_23 ( 1 , L_19 ) ;
goto V_9;
}
if ( F_41 ( V_65 -> V_66 >= V_52 ) ) {
F_23 ( 1 , L_20 ) ;
goto V_9;
}
if ( F_41 ( NULL == V_3 -> V_53 [ V_65 -> V_66 ] ) ) {
F_23 ( 1 , L_21 ) ;
goto V_9;
}
F_31 ( V_3 , V_65 , V_3 -> V_53 [ V_65 -> V_66 ] , V_3 -> type ) ;
V_21 = 0 ;
V_9:
F_34 ( V_3 ) ;
return V_21 ;
}
int F_42 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
struct V_1 * V_28 ;
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
int V_101 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
if ( V_65 -> V_67 == V_68 )
F_43 ( & V_104 -> V_105 -> V_106 ) ;
F_33 ( V_3 ) ;
V_101 = - V_56 ;
if ( V_3 -> V_50 ) {
F_23 ( 1 , L_22 ) ;
goto V_9;
}
V_101 = - V_102 ;
if ( V_65 -> type != V_3 -> type ) {
F_23 ( 1 , L_23 ) ;
goto V_9;
}
if ( V_65 -> V_66 >= V_52 ) {
F_23 ( 1 , L_24 ) ;
goto V_9;
}
V_28 = V_3 -> V_53 [ V_65 -> V_66 ] ;
if ( NULL == V_28 ) {
F_23 ( 1 , L_25 ) ;
goto V_9;
}
F_10 ( V_28 -> V_10 , V_11 ) ;
if ( V_28 -> V_67 != V_65 -> V_67 ) {
F_23 ( 1 , L_26 ) ;
goto V_9;
}
if ( V_28 -> V_15 != V_86 && V_28 -> V_15 != V_87 ) {
F_23 ( 1 , L_27 ) ;
goto V_9;
}
switch ( V_65 -> V_67 ) {
case V_68 :
if ( 0 == V_28 -> V_76 ) {
F_23 ( 1 , L_28
L_29 ) ;
goto V_9;
}
if ( V_3 -> type == V_107
|| V_3 -> type == V_108
|| V_3 -> type == V_109 ) {
V_28 -> V_91 = V_65 -> V_90 ;
V_28 -> V_36 = V_65 -> V_36 ;
V_28 -> V_89 = V_65 -> V_88 ;
}
break;
case V_74 :
if ( V_65 -> V_72 < V_28 -> V_73 ) {
F_23 ( 1 , L_30 ) ;
goto V_9;
}
if ( V_86 != V_28 -> V_15 &&
V_28 -> V_76 != V_65 -> V_69 . V_75 )
V_3 -> V_31 -> V_44 ( V_3 , V_28 ) ;
V_28 -> V_76 = V_65 -> V_69 . V_75 ;
break;
case V_77 :
V_28 -> V_71 = V_65 -> V_69 . V_70 ;
break;
default:
F_23 ( 1 , L_31 ) ;
goto V_9;
}
F_23 ( 1 , L_32 ) ;
V_36 = F_30 ( V_3 ) ;
V_101 = V_3 -> V_31 -> V_42 ( V_3 , V_28 , V_36 ) ;
if ( 0 != V_101 ) {
F_23 ( 1 , L_33 , V_101 ) ;
goto V_9;
}
F_44 ( & V_28 -> V_47 , & V_3 -> V_47 ) ;
if ( V_3 -> V_49 ) {
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_28 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
}
F_23 ( 1 , L_34 ) ;
V_101 = 0 ;
F_27 ( & V_3 -> V_46 ) ;
V_9:
F_34 ( V_3 ) ;
if ( V_65 -> V_67 == V_68 )
F_45 ( & V_104 -> V_105 -> V_106 ) ;
return V_101 ;
}
static int F_46 ( struct V_2 * V_3 , int V_110 )
{
int V_101 ;
V_111:
if ( ! V_3 -> V_49 ) {
F_23 ( 1 , L_35 ) ;
V_101 = - V_102 ;
goto V_9;
}
if ( F_39 ( & V_3 -> V_47 ) ) {
if ( V_110 ) {
V_101 = - V_22 ;
F_23 ( 2 , L_36 ) ;
goto V_9;
} else {
F_23 ( 2 , L_37 ) ;
F_34 ( V_3 ) ;
V_101 = F_13 ( V_3 -> V_46 ,
! F_39 ( & V_3 -> V_47 ) || ! V_3 -> V_49 ) ;
F_33 ( V_3 ) ;
if ( V_101 )
goto V_9;
goto V_111;
}
}
V_101 = 0 ;
V_9:
return V_101 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 * * V_4 , int V_112 )
{
int V_101 ;
struct V_1 * V_28 = NULL ;
V_101 = F_46 ( V_3 , V_112 ) ;
if ( V_101 )
goto V_9;
V_28 = F_48 ( V_3 -> V_47 . V_113 , struct V_1 , V_47 ) ;
V_101 = F_9 ( V_3 , V_28 , V_112 , 1 ) ;
if ( V_101 < 0 )
goto V_9;
* V_4 = V_28 ;
V_9:
return V_101 ;
}
int F_49 ( struct V_2 * V_3 ,
struct V_64 * V_65 , int V_112 )
{
struct V_1 * V_28 = NULL ;
int V_101 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_33 ( V_3 ) ;
V_101 = F_47 ( V_3 , & V_28 , V_112 ) ;
if ( V_101 < 0 ) {
F_23 ( 1 , L_38 , V_101 ) ;
goto V_9;
}
switch ( V_28 -> V_15 ) {
case V_58 :
F_23 ( 1 , L_39 ) ;
break;
case V_84 :
F_23 ( 1 , L_40 ) ;
break;
default:
F_23 ( 1 , L_41 ) ;
V_101 = - V_102 ;
goto V_9;
}
F_17 ( V_3 , V_114 , V_3 , V_28 ) ;
F_31 ( V_3 , V_65 , V_28 , V_3 -> type ) ;
F_28 ( & V_28 -> V_47 ) ;
V_28 -> V_15 = V_87 ;
V_65 -> V_12 &= ~ V_85 ;
V_9:
F_34 ( V_3 ) ;
return V_101 ;
}
int F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_28 ;
unsigned long V_12 = 0 ;
int V_101 ;
F_33 ( V_3 ) ;
V_101 = - V_56 ;
if ( V_3 -> V_50 )
goto V_9;
V_101 = 0 ;
if ( V_3 -> V_49 )
goto V_9;
V_3 -> V_49 = 1 ;
F_7 ( V_3 -> V_14 , V_12 ) ;
F_51 (buf, &q->stream, stream)
if ( V_28 -> V_15 == V_81 )
V_3 -> V_31 -> V_43 ( V_3 , V_28 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
F_27 ( & V_3 -> V_46 ) ;
V_9:
F_34 ( V_3 ) ;
return V_101 ;
}
static int F_52 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_49 )
return - V_102 ;
F_26 ( V_3 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 )
{
int V_101 ;
F_33 ( V_3 ) ;
V_101 = F_52 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_101 ;
}
static T_2 F_54 ( struct V_2 * V_3 ,
char T_3 * V_115 ,
T_4 V_100 , T_5 * V_116 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
int V_101 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
V_3 -> V_51 = F_1 ( V_3 ) ;
if ( NULL == V_3 -> V_51 )
return - V_97 ;
V_3 -> V_51 -> V_67 = V_74 ;
V_3 -> V_51 -> V_76 = ( unsigned long ) V_115 ;
V_3 -> V_51 -> V_73 = V_100 ;
V_36 = F_30 ( V_3 ) ;
V_101 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_51 , V_36 ) ;
if ( 0 != V_101 )
goto V_9;
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_101 = F_9 ( V_3 , V_3 -> V_51 , 0 , 0 ) ;
if ( 0 == V_101 ) {
F_17 ( V_3 , V_114 , V_3 , V_3 -> V_51 ) ;
if ( V_58 == V_3 -> V_51 -> V_15 )
V_101 = - V_117 ;
else
V_101 = V_3 -> V_51 -> V_91 ;
}
V_9:
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
return V_101 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_1 * V_28 ,
char T_3 * V_115 , T_4 V_100 ,
int V_112 )
{
void * V_29 = F_17 ( V_3 , V_29 , V_28 ) ;
if ( V_100 > V_28 -> V_91 - V_3 -> V_118 )
V_100 = V_28 -> V_91 - V_3 -> V_118 ;
if ( F_56 ( V_115 , V_29 + V_3 -> V_118 , V_100 ) )
return - V_119 ;
return V_100 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_1 * V_28 ,
char T_3 * V_115 , T_4 V_100 , T_4 V_120 ,
int V_121 , int V_112 )
{
unsigned int * V_122 = F_17 ( V_3 , V_29 , V_28 ) ;
if ( V_121 ) {
V_122 += ( V_28 -> V_91 >> 2 ) - 1 ;
* V_122 = V_28 -> V_93 >> 1 ;
F_23 ( 1 , L_42 , * V_122 ) ;
}
V_100 = F_55 ( V_3 , V_28 , V_115 , V_100 , V_112 ) ;
if ( ( V_100 == - V_119 ) && ( V_120 == 0 ) )
return - V_119 ;
return V_100 ;
}
T_2 F_58 ( struct V_2 * V_3 ,
char T_3 * V_115 , T_4 V_100 , T_5 * V_116 ,
int V_112 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
unsigned V_91 = 0 , V_123 = 1 ;
int V_101 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
F_33 ( V_3 ) ;
V_3 -> V_31 -> V_41 ( V_3 , & V_123 , & V_91 ) ;
if ( NULL == V_3 -> V_51 &&
V_100 >= V_91 &&
! V_112 ) {
V_101 = F_54 ( V_3 , V_115 , V_100 , V_116 ) ;
if ( V_101 >= 0 || V_101 == - V_117 )
goto V_9;
}
if ( NULL == V_3 -> V_51 ) {
V_101 = - V_97 ;
V_3 -> V_51 = F_1 ( V_3 ) ;
F_23 ( 1 , L_43 , V_3 -> V_51 ) ;
if ( NULL == V_3 -> V_51 )
goto V_9;
V_3 -> V_51 -> V_67 = V_74 ;
V_3 -> V_51 -> V_73 = V_100 ;
V_36 = F_30 ( V_3 ) ;
V_101 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_51 , V_36 ) ;
if ( 0 != V_101 ) {
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
goto V_9;
}
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_118 = 0 ;
}
V_101 = F_9 ( V_3 , V_3 -> V_51 , V_112 , 1 ) ;
if ( 0 != V_101 )
goto V_9;
F_17 ( V_3 , V_114 , V_3 , V_3 -> V_51 ) ;
if ( V_58 == V_3 -> V_51 -> V_15 ) {
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
V_101 = - V_117 ;
goto V_9;
}
V_101 = F_55 ( V_3 , V_3 -> V_51 , V_115 , V_100 , V_112 ) ;
if ( V_101 < 0 )
goto V_9;
V_3 -> V_118 += V_101 ;
if ( V_3 -> V_118 == V_3 -> V_51 -> V_91 ) {
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
}
V_9:
F_34 ( V_3 ) ;
return V_101 ;
}
static int F_59 ( struct V_2 * V_3 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
unsigned int V_100 = 0 , V_91 = 0 ;
int V_96 , V_48 ;
V_3 -> V_31 -> V_41 ( V_3 , & V_100 , & V_91 ) ;
if ( V_100 < 2 )
V_100 = 2 ;
if ( V_100 > V_52 )
V_100 = V_52 ;
V_91 = F_36 ( V_91 ) ;
V_96 = F_35 ( V_3 , V_100 , V_91 , V_74 ) ;
if ( V_96 < 0 )
return V_96 ;
V_100 = V_96 ;
for ( V_48 = 0 ; V_48 < V_100 ; V_48 ++ ) {
V_36 = F_30 ( V_3 ) ;
V_96 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_53 [ V_48 ] , V_36 ) ;
if ( V_96 )
return V_96 ;
F_44 ( & V_3 -> V_53 [ V_48 ] -> V_47 , & V_3 -> V_47 ) ;
}
F_7 ( V_3 -> V_14 , V_12 ) ;
for ( V_48 = 0 ; V_48 < V_100 ; V_48 ++ )
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_53 [ V_48 ] ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_50 = 1 ;
return 0 ;
}
static void F_60 ( struct V_2 * V_3 )
{
int V_48 ;
F_26 ( V_3 ) ;
F_24 ( V_3 ) ;
F_21 ( & V_3 -> V_47 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( NULL == V_3 -> V_53 [ V_48 ] )
continue;
F_25 ( V_3 -> V_53 [ V_48 ] ) ;
V_3 -> V_53 [ V_48 ] = NULL ;
}
V_3 -> V_51 = NULL ;
}
int F_61 ( struct V_2 * V_3 )
{
int V_13 ;
F_33 ( V_3 ) ;
V_13 = F_59 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_13 ;
}
void F_62 ( struct V_2 * V_3 )
{
F_33 ( V_3 ) ;
F_60 ( V_3 ) ;
F_34 ( V_3 ) ;
}
void F_63 ( struct V_2 * V_3 )
{
F_33 ( V_3 ) ;
if ( V_3 -> V_49 )
F_52 ( V_3 ) ;
if ( V_3 -> V_50 )
F_60 ( V_3 ) ;
F_34 ( V_3 ) ;
}
T_2 F_64 ( struct V_2 * V_3 ,
char T_3 * V_115 , T_4 V_100 , T_5 * V_116 ,
int V_121 , int V_112 )
{
int V_13 , V_101 ;
unsigned long V_12 = 0 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
F_23 ( 2 , L_8 , V_55 ) ;
F_33 ( V_3 ) ;
V_101 = - V_56 ;
if ( V_3 -> V_49 )
goto V_9;
if ( ! V_3 -> V_50 ) {
V_101 = F_59 ( V_3 ) ;
if ( V_101 < 0 )
goto V_9;
}
V_101 = 0 ;
while ( V_100 > 0 ) {
if ( NULL == V_3 -> V_51 ) {
V_3 -> V_51 = F_48 ( V_3 -> V_47 . V_113 ,
struct V_1 ,
V_47 ) ;
F_28 ( & V_3 -> V_51 -> V_47 ) ;
V_3 -> V_118 = 0 ;
}
V_13 = F_9 ( V_3 , V_3 -> V_51 , V_112 , 1 ) ;
if ( V_13 < 0 ) {
if ( 0 == V_101 )
V_101 = V_13 ;
break;
}
if ( V_3 -> V_51 -> V_15 == V_84 ) {
V_13 = F_57 ( V_3 , V_3 -> V_51 , V_115 + V_101 , V_100 ,
V_101 , V_121 , V_112 ) ;
if ( V_13 < 0 ) {
V_101 = V_13 ;
break;
}
V_101 += V_13 ;
V_100 -= V_13 ;
V_3 -> V_118 += V_13 ;
} else {
V_3 -> V_118 = V_3 -> V_51 -> V_91 ;
if ( 0 == V_101 )
V_101 = - V_117 ;
}
if ( V_3 -> V_118 == V_3 -> V_51 -> V_91 ) {
F_44 ( & V_3 -> V_51 -> V_47 ,
& V_3 -> V_47 ) ;
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_51 = NULL ;
}
if ( V_101 < 0 )
break;
}
V_9:
F_34 ( V_3 ) ;
return V_101 ;
}
unsigned int F_65 ( struct V_124 * V_124 ,
struct V_2 * V_3 ,
T_6 * V_46 )
{
unsigned long V_125 = F_66 ( V_46 ) ;
struct V_1 * V_28 = NULL ;
unsigned int V_13 = 0 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_49 ) {
if ( ! F_39 ( & V_3 -> V_47 ) )
V_28 = F_48 ( V_3 -> V_47 . V_113 ,
struct V_1 , V_47 ) ;
} else if ( V_125 & ( V_126 | V_127 ) ) {
if ( ! V_3 -> V_50 )
F_59 ( V_3 ) ;
if ( ! V_3 -> V_50 ) {
V_13 = V_128 ;
} else if ( NULL == V_3 -> V_51 ) {
V_3 -> V_51 = F_48 ( V_3 -> V_47 . V_113 ,
struct V_1 ,
V_47 ) ;
F_28 ( & V_3 -> V_51 -> V_47 ) ;
V_3 -> V_118 = 0 ;
}
V_28 = V_3 -> V_51 ;
}
if ( ! V_28 )
V_13 = V_128 ;
if ( 0 == V_13 ) {
F_67 ( V_124 , & V_28 -> V_9 , V_46 ) ;
if ( V_28 -> V_15 == V_84 ||
V_28 -> V_15 == V_58 ) {
switch ( V_3 -> type ) {
case V_107 :
case V_108 :
case V_109 :
V_13 = V_129 | V_130 ;
break;
default:
V_13 = V_126 | V_127 ;
break;
}
}
}
F_34 ( V_3 ) ;
return V_13 ;
}
int F_68 ( struct V_2 * V_3 , struct V_131 * V_132 )
{
int V_13 = - V_102 ;
int V_48 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
if ( ! ( V_132 -> V_133 & V_134 ) || ! ( V_132 -> V_133 & V_135 ) ) {
F_23 ( 1 , L_44 ) ;
return - V_102 ;
}
F_33 ( V_3 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
struct V_1 * V_28 = V_3 -> V_53 [ V_48 ] ;
if ( V_28 && V_28 -> V_67 == V_68 &&
V_28 -> V_71 == ( V_132 -> V_136 << V_103 ) ) {
V_13 = F_17 ( V_3 , V_137 , V_3 , V_28 , V_132 ) ;
break;
}
}
F_34 ( V_3 ) ;
return V_13 ;
}
