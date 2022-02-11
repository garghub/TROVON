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
V_65 -> V_12 = 0 ;
if ( V_4 -> V_54 )
V_65 -> V_12 |= V_79 ;
switch ( V_4 -> V_15 ) {
case V_80 :
case V_17 :
case V_16 :
V_65 -> V_12 |= V_81 ;
break;
case V_58 :
V_65 -> V_12 |= V_82 ;
case V_83 :
V_65 -> V_12 |= V_84 ;
break;
case V_85 :
case V_86 :
break;
}
V_65 -> V_36 = V_4 -> V_36 ;
V_65 -> V_87 = V_4 -> V_88 ;
V_65 -> V_89 = V_4 -> V_90 ;
V_65 -> V_91 = V_4 -> V_92 >> 1 ;
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
unsigned int V_93 , unsigned int V_73 ,
enum V_94 V_67 )
{
unsigned int V_48 ;
int V_95 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
V_95 = F_24 ( V_3 ) ;
if ( 0 != V_95 )
return V_95 ;
for ( V_48 = 0 ; V_48 < V_93 ; V_48 ++ ) {
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
return - V_96 ;
F_23 ( 1 , L_11 , V_48 , V_73 ) ;
return V_48 ;
}
int F_37 ( struct V_2 * V_3 ,
unsigned int V_93 , unsigned int V_73 ,
enum V_94 V_67 )
{
int V_21 ;
F_33 ( V_3 ) ;
V_21 = F_35 ( V_3 , V_93 , V_73 , V_67 ) ;
F_34 ( V_3 ) ;
return V_21 ;
}
int F_38 ( struct V_2 * V_3 ,
struct V_97 * V_98 )
{
unsigned int V_90 , V_99 ;
int V_100 ;
if ( V_98 -> V_99 < 1 ) {
F_23 ( 1 , L_12 , V_98 -> V_99 ) ;
return - V_101 ;
}
if ( V_98 -> V_67 != V_68 &&
V_98 -> V_67 != V_74 &&
V_98 -> V_67 != V_77 ) {
F_23 ( 1 , L_13 ) ;
return - V_101 ;
}
F_33 ( V_3 ) ;
if ( V_98 -> type != V_3 -> type ) {
F_23 ( 1 , L_14 ) ;
V_100 = - V_101 ;
goto V_9;
}
if ( V_3 -> V_49 ) {
F_23 ( 1 , L_15 ) ;
V_100 = - V_56 ;
goto V_9;
}
if ( ! F_39 ( & V_3 -> V_47 ) ) {
F_23 ( 1 , L_16 ) ;
V_100 = - V_56 ;
goto V_9;
}
V_99 = V_98 -> V_99 ;
if ( V_99 > V_52 )
V_99 = V_52 ;
V_90 = 0 ;
V_3 -> V_31 -> V_41 ( V_3 , & V_99 , & V_90 ) ;
F_23 ( 1 , L_17 ,
V_99 , V_90 ,
( unsigned int ) ( ( V_99 * F_36 ( V_90 ) ) >> V_102 ) ) ;
V_100 = F_35 ( V_3 , V_99 , V_90 , V_98 -> V_67 ) ;
if ( V_100 < 0 ) {
F_23 ( 1 , L_18 , V_100 ) ;
goto V_9;
}
V_98 -> V_99 = V_100 ;
V_100 = 0 ;
V_9:
F_34 ( V_3 ) ;
return V_100 ;
}
int F_40 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
int V_21 = - V_101 ;
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
int V_100 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
if ( V_65 -> V_67 == V_68 )
F_43 ( & V_103 -> V_104 -> V_105 ) ;
F_33 ( V_3 ) ;
V_100 = - V_56 ;
if ( V_3 -> V_50 ) {
F_23 ( 1 , L_22 ) ;
goto V_9;
}
V_100 = - V_101 ;
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
if ( V_28 -> V_15 != V_85 && V_28 -> V_15 != V_86 ) {
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
if ( V_3 -> type == V_106
|| V_3 -> type == V_107
|| V_3 -> type == V_108 ) {
V_28 -> V_90 = V_65 -> V_89 ;
V_28 -> V_36 = V_65 -> V_36 ;
V_28 -> V_88 = V_65 -> V_87 ;
}
break;
case V_74 :
if ( V_65 -> V_72 < V_28 -> V_73 ) {
F_23 ( 1 , L_30 ) ;
goto V_9;
}
if ( V_85 != V_28 -> V_15 &&
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
V_100 = V_3 -> V_31 -> V_42 ( V_3 , V_28 , V_36 ) ;
if ( 0 != V_100 ) {
F_23 ( 1 , L_33 , V_100 ) ;
goto V_9;
}
F_44 ( & V_28 -> V_47 , & V_3 -> V_47 ) ;
if ( V_3 -> V_49 ) {
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_28 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
}
F_23 ( 1 , L_34 ) ;
V_100 = 0 ;
F_27 ( & V_3 -> V_46 ) ;
V_9:
F_34 ( V_3 ) ;
if ( V_65 -> V_67 == V_68 )
F_45 ( & V_103 -> V_104 -> V_105 ) ;
return V_100 ;
}
static int F_46 ( struct V_2 * V_3 , int V_109 )
{
int V_100 ;
V_110:
if ( ! V_3 -> V_49 ) {
F_23 ( 1 , L_35 ) ;
V_100 = - V_101 ;
goto V_9;
}
if ( F_39 ( & V_3 -> V_47 ) ) {
if ( V_109 ) {
V_100 = - V_22 ;
F_23 ( 2 , L_36 ) ;
goto V_9;
} else {
F_23 ( 2 , L_37 ) ;
F_34 ( V_3 ) ;
V_100 = F_13 ( V_3 -> V_46 ,
! F_39 ( & V_3 -> V_47 ) || ! V_3 -> V_49 ) ;
F_33 ( V_3 ) ;
if ( V_100 )
goto V_9;
goto V_110;
}
}
V_100 = 0 ;
V_9:
return V_100 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_1 * * V_4 , int V_111 )
{
int V_100 ;
struct V_1 * V_28 = NULL ;
V_100 = F_46 ( V_3 , V_111 ) ;
if ( V_100 )
goto V_9;
V_28 = F_48 ( V_3 -> V_47 . V_112 , struct V_1 , V_47 ) ;
V_100 = F_9 ( V_3 , V_28 , V_111 , 1 ) ;
if ( V_100 < 0 )
goto V_9;
* V_4 = V_28 ;
V_9:
return V_100 ;
}
int F_49 ( struct V_2 * V_3 ,
struct V_64 * V_65 , int V_111 )
{
struct V_1 * V_28 = NULL ;
int V_100 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_33 ( V_3 ) ;
V_100 = F_47 ( V_3 , & V_28 , V_111 ) ;
if ( V_100 < 0 ) {
F_23 ( 1 , L_38 , V_100 ) ;
goto V_9;
}
switch ( V_28 -> V_15 ) {
case V_58 :
F_23 ( 1 , L_39 ) ;
break;
case V_83 :
F_23 ( 1 , L_40 ) ;
break;
default:
F_23 ( 1 , L_41 ) ;
V_100 = - V_101 ;
goto V_9;
}
F_17 ( V_3 , V_113 , V_3 , V_28 ) ;
F_31 ( V_3 , V_65 , V_28 , V_3 -> type ) ;
F_28 ( & V_28 -> V_47 ) ;
V_28 -> V_15 = V_86 ;
V_65 -> V_12 &= ~ V_84 ;
V_9:
F_34 ( V_3 ) ;
return V_100 ;
}
int F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_28 ;
unsigned long V_12 = 0 ;
int V_100 ;
F_33 ( V_3 ) ;
V_100 = - V_56 ;
if ( V_3 -> V_50 )
goto V_9;
V_100 = 0 ;
if ( V_3 -> V_49 )
goto V_9;
V_3 -> V_49 = 1 ;
F_7 ( V_3 -> V_14 , V_12 ) ;
F_51 (buf, &q->stream, stream)
if ( V_28 -> V_15 == V_80 )
V_3 -> V_31 -> V_43 ( V_3 , V_28 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
F_27 ( & V_3 -> V_46 ) ;
V_9:
F_34 ( V_3 ) ;
return V_100 ;
}
static int F_52 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_49 )
return - V_101 ;
F_26 ( V_3 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 )
{
int V_100 ;
F_33 ( V_3 ) ;
V_100 = F_52 ( V_3 ) ;
F_34 ( V_3 ) ;
return V_100 ;
}
static T_2 F_54 ( struct V_2 * V_3 ,
char T_3 * V_114 ,
T_4 V_99 , T_5 * V_115 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
int V_100 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
V_3 -> V_51 = F_1 ( V_3 ) ;
if ( NULL == V_3 -> V_51 )
return - V_96 ;
V_3 -> V_51 -> V_67 = V_74 ;
V_3 -> V_51 -> V_76 = ( unsigned long ) V_114 ;
V_3 -> V_51 -> V_73 = V_99 ;
V_36 = F_30 ( V_3 ) ;
V_100 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_51 , V_36 ) ;
if ( 0 != V_100 )
goto V_9;
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_100 = F_9 ( V_3 , V_3 -> V_51 , 0 , 0 ) ;
if ( 0 == V_100 ) {
F_17 ( V_3 , V_113 , V_3 , V_3 -> V_51 ) ;
if ( V_58 == V_3 -> V_51 -> V_15 )
V_100 = - V_116 ;
else
V_100 = V_3 -> V_51 -> V_90 ;
}
V_9:
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
return V_100 ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_1 * V_28 ,
char T_3 * V_114 , T_4 V_99 ,
int V_111 )
{
void * V_29 = F_17 ( V_3 , V_29 , V_28 ) ;
if ( V_99 > V_28 -> V_90 - V_3 -> V_117 )
V_99 = V_28 -> V_90 - V_3 -> V_117 ;
if ( F_56 ( V_114 , V_29 + V_3 -> V_117 , V_99 ) )
return - V_118 ;
return V_99 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_1 * V_28 ,
char T_3 * V_114 , T_4 V_99 , T_4 V_119 ,
int V_120 , int V_111 )
{
unsigned int * V_121 = F_17 ( V_3 , V_29 , V_28 ) ;
if ( V_120 ) {
V_121 += ( V_28 -> V_90 >> 2 ) - 1 ;
* V_121 = V_28 -> V_92 >> 1 ;
F_23 ( 1 , L_42 , * V_121 ) ;
}
V_99 = F_55 ( V_3 , V_28 , V_114 , V_99 , V_111 ) ;
if ( ( V_99 == - V_118 ) && ( V_119 == 0 ) )
return - V_118 ;
return V_99 ;
}
T_2 F_58 ( struct V_2 * V_3 ,
char T_3 * V_114 , T_4 V_99 , T_5 * V_115 ,
int V_111 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
unsigned V_90 = 0 , V_122 = 1 ;
int V_100 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
F_33 ( V_3 ) ;
V_3 -> V_31 -> V_41 ( V_3 , & V_122 , & V_90 ) ;
if ( NULL == V_3 -> V_51 &&
V_99 >= V_90 &&
! V_111 ) {
V_100 = F_54 ( V_3 , V_114 , V_99 , V_115 ) ;
if ( V_100 >= 0 || V_100 == - V_116 )
goto V_9;
}
if ( NULL == V_3 -> V_51 ) {
V_100 = - V_96 ;
V_3 -> V_51 = F_1 ( V_3 ) ;
F_23 ( 1 , L_43 , V_3 -> V_51 ) ;
if ( NULL == V_3 -> V_51 )
goto V_9;
V_3 -> V_51 -> V_67 = V_74 ;
V_3 -> V_51 -> V_73 = V_99 ;
V_36 = F_30 ( V_3 ) ;
V_100 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_51 , V_36 ) ;
if ( 0 != V_100 ) {
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
goto V_9;
}
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_117 = 0 ;
}
V_100 = F_9 ( V_3 , V_3 -> V_51 , V_111 , 1 ) ;
if ( 0 != V_100 )
goto V_9;
F_17 ( V_3 , V_113 , V_3 , V_3 -> V_51 ) ;
if ( V_58 == V_3 -> V_51 -> V_15 ) {
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
V_100 = - V_116 ;
goto V_9;
}
V_100 = F_55 ( V_3 , V_3 -> V_51 , V_114 , V_99 , V_111 ) ;
if ( V_100 < 0 )
goto V_9;
V_3 -> V_117 += V_100 ;
if ( V_3 -> V_117 == V_3 -> V_51 -> V_90 ) {
V_3 -> V_31 -> V_44 ( V_3 , V_3 -> V_51 ) ;
F_25 ( V_3 -> V_51 ) ;
V_3 -> V_51 = NULL ;
}
V_9:
F_34 ( V_3 ) ;
return V_100 ;
}
static int F_59 ( struct V_2 * V_3 )
{
enum V_35 V_36 ;
unsigned long V_12 = 0 ;
unsigned int V_99 = 0 , V_90 = 0 ;
int V_95 , V_48 ;
V_3 -> V_31 -> V_41 ( V_3 , & V_99 , & V_90 ) ;
if ( V_99 < 2 )
V_99 = 2 ;
if ( V_99 > V_52 )
V_99 = V_52 ;
V_90 = F_36 ( V_90 ) ;
V_95 = F_35 ( V_3 , V_99 , V_90 , V_74 ) ;
if ( V_95 < 0 )
return V_95 ;
V_99 = V_95 ;
for ( V_48 = 0 ; V_48 < V_99 ; V_48 ++ ) {
V_36 = F_30 ( V_3 ) ;
V_95 = V_3 -> V_31 -> V_42 ( V_3 , V_3 -> V_53 [ V_48 ] , V_36 ) ;
if ( V_95 )
return V_95 ;
F_44 ( & V_3 -> V_53 [ V_48 ] -> V_47 , & V_3 -> V_47 ) ;
}
F_7 ( V_3 -> V_14 , V_12 ) ;
for ( V_48 = 0 ; V_48 < V_99 ; V_48 ++ )
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
char T_3 * V_114 , T_4 V_99 , T_5 * V_115 ,
int V_120 , int V_111 )
{
int V_13 , V_100 ;
unsigned long V_12 = 0 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
F_23 ( 2 , L_8 , V_55 ) ;
F_33 ( V_3 ) ;
V_100 = - V_56 ;
if ( V_3 -> V_49 )
goto V_9;
if ( ! V_3 -> V_50 ) {
V_100 = F_59 ( V_3 ) ;
if ( V_100 < 0 )
goto V_9;
}
V_100 = 0 ;
while ( V_99 > 0 ) {
if ( NULL == V_3 -> V_51 ) {
V_3 -> V_51 = F_48 ( V_3 -> V_47 . V_112 ,
struct V_1 ,
V_47 ) ;
F_28 ( & V_3 -> V_51 -> V_47 ) ;
V_3 -> V_117 = 0 ;
}
V_13 = F_9 ( V_3 , V_3 -> V_51 , V_111 , 1 ) ;
if ( V_13 < 0 ) {
if ( 0 == V_100 )
V_100 = V_13 ;
break;
}
if ( V_3 -> V_51 -> V_15 == V_83 ) {
V_13 = F_57 ( V_3 , V_3 -> V_51 , V_114 + V_100 , V_99 ,
V_100 , V_120 , V_111 ) ;
if ( V_13 < 0 ) {
V_100 = V_13 ;
break;
}
V_100 += V_13 ;
V_99 -= V_13 ;
V_3 -> V_117 += V_13 ;
} else {
V_3 -> V_117 = V_3 -> V_51 -> V_90 ;
if ( 0 == V_100 )
V_100 = - V_116 ;
}
if ( V_3 -> V_117 == V_3 -> V_51 -> V_90 ) {
F_44 ( & V_3 -> V_51 -> V_47 ,
& V_3 -> V_47 ) ;
F_7 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_31 -> V_43 ( V_3 , V_3 -> V_51 ) ;
F_8 ( V_3 -> V_14 , V_12 ) ;
V_3 -> V_51 = NULL ;
}
if ( V_100 < 0 )
break;
}
V_9:
F_34 ( V_3 ) ;
return V_100 ;
}
unsigned int F_65 ( struct V_123 * V_123 ,
struct V_2 * V_3 ,
T_6 * V_46 )
{
unsigned long V_124 = F_66 ( V_46 ) ;
struct V_1 * V_28 = NULL ;
unsigned int V_13 = 0 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_49 ) {
if ( ! F_39 ( & V_3 -> V_47 ) )
V_28 = F_48 ( V_3 -> V_47 . V_112 ,
struct V_1 , V_47 ) ;
} else if ( V_124 & ( V_125 | V_126 ) ) {
if ( ! V_3 -> V_50 )
F_59 ( V_3 ) ;
if ( ! V_3 -> V_50 ) {
V_13 = V_127 ;
} else if ( NULL == V_3 -> V_51 ) {
V_3 -> V_51 = F_48 ( V_3 -> V_47 . V_112 ,
struct V_1 ,
V_47 ) ;
F_28 ( & V_3 -> V_51 -> V_47 ) ;
V_3 -> V_117 = 0 ;
}
V_28 = V_3 -> V_51 ;
}
if ( ! V_28 )
V_13 = V_127 ;
if ( 0 == V_13 ) {
F_67 ( V_123 , & V_28 -> V_9 , V_46 ) ;
if ( V_28 -> V_15 == V_83 ||
V_28 -> V_15 == V_58 ) {
switch ( V_3 -> type ) {
case V_106 :
case V_107 :
case V_108 :
V_13 = V_128 | V_129 ;
break;
default:
V_13 = V_125 | V_126 ;
break;
}
}
}
F_34 ( V_3 ) ;
return V_13 ;
}
int F_68 ( struct V_2 * V_3 , struct V_130 * V_131 )
{
int V_13 = - V_101 ;
int V_48 ;
F_10 ( V_3 -> V_6 -> V_10 , V_26 ) ;
if ( ! ( V_131 -> V_132 & V_133 ) || ! ( V_131 -> V_132 & V_134 ) ) {
F_23 ( 1 , L_44 ) ;
return - V_101 ;
}
F_33 ( V_3 ) ;
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
struct V_1 * V_28 = V_3 -> V_53 [ V_48 ] ;
if ( V_28 && V_28 -> V_67 == V_68 &&
V_28 -> V_71 == ( V_131 -> V_135 << V_102 ) ) {
V_13 = F_17 ( V_3 , V_136 , V_3 , V_28 , V_131 ) ;
break;
}
}
F_34 ( V_3 ) ;
return V_13 ;
}
