static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_5 = 0 ;
}
void F_3 ( void )
{
int V_6 , V_7 , V_8 , V_9 ;
F_2 ( & V_10 . V_11 ) ;
F_4 ( & V_10 . V_11 , V_12 ) ;
V_6 = F_5 ( & V_10 . V_11 ) ;
V_9 = F_5 ( F_6 (
F_7 ( & V_10 . V_11 ) ) ) ;
V_7 = F_7 ( & V_10 . V_11 ) ;
for ( V_8 = 0 ; V_8 < V_6 / V_9 ; V_8 ++ )
V_7 = F_8 ( V_7 , & V_10 . V_11 ) ;
for (; V_8 < V_6 ; V_8 ++ ) {
F_9 ( V_7 , & V_10 . V_11 ) ;
V_7 = F_8 ( V_7 , & V_10 . V_11 ) ;
}
}
int F_10 ( void )
{
int V_13 ;
struct V_14 * V_15 = NULL ;
const struct V_16 * V_17 = V_18 ;
F_2 ( & V_10 . V_19 . V_4 ) ;
F_4 ( & V_10 . V_19 . V_3 , V_12 ) ;
V_10 . V_19 . V_5 = 0 ;
V_10 . V_20 =
F_5 ( F_6 (
F_7 ( & V_10 . V_19 . V_3 )
) ) ;
V_10 . V_21 = V_21 () ;
V_10 . V_22 = V_22 () ;
F_3 () ;
V_23 = F_11 ( F_12 () ,
sizeof( * V_23 ) , V_24 ) ;
if ( ! V_23 )
return - V_25 ;
while ( V_17 -> V_26 ) {
V_15 = NULL ;
while ( ( V_15 = F_13 ( V_17 -> V_26 , V_17 -> V_27 , V_15 ) ) ) {
V_13 = F_14 ( V_15 -> V_28 ) ;
if ( V_13 < 0 )
V_13 = F_15 () ;
V_23 [ V_13 ] ++ ;
}
V_17 ++ ;
}
return 0 ;
}
void F_16 ( void )
{
struct V_29 * V_30 , * V_31 ;
struct V_32 * V_33 ;
F_17 ( & V_10 . V_34 ) ;
F_18 (pos, q, &node_affinity.list) {
V_33 = F_19 ( V_30 , struct V_32 ,
V_35 ) ;
F_20 ( V_30 ) ;
F_21 ( V_33 ) ;
}
F_22 ( & V_10 . V_34 ) ;
F_21 ( V_23 ) ;
}
static struct V_32 * F_23 ( int V_13 )
{
struct V_32 * V_33 ;
V_33 = F_24 ( sizeof( * V_33 ) , V_24 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_13 = V_13 ;
F_25 ( & V_33 -> V_35 ) ;
return V_33 ;
}
static void F_26 ( struct V_32 * V_33 )
{
F_27 ( & V_33 -> V_35 , & V_10 . V_35 ) ;
}
static struct V_32 * F_28 ( int V_13 )
{
struct V_29 * V_30 ;
struct V_32 * V_33 ;
F_29 (pos, &node_affinity.list) {
V_33 = F_19 ( V_30 , struct V_32 , V_35 ) ;
if ( V_33 -> V_13 == V_13 )
return V_33 ;
}
return NULL ;
}
int F_30 ( struct V_36 * V_37 )
{
int V_13 = F_14 ( V_37 -> V_38 -> V_28 ) ;
struct V_32 * V_33 ;
const struct V_39 * V_40 ;
int V_7 , V_6 , V_8 ;
if ( V_13 < 0 )
V_13 = F_15 () ;
V_37 -> V_13 = V_13 ;
V_40 = F_31 ( V_37 -> V_13 ) ;
if ( F_7 ( V_40 ) >= V_41 )
V_40 = F_32 ( 0 ) ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
if ( ! V_33 ) {
V_33 = F_23 ( V_13 ) ;
if ( ! V_33 ) {
F_33 ( V_37 ,
L_1 ) ;
F_22 ( & V_10 . V_34 ) ;
return - V_25 ;
}
F_1 ( & V_33 -> V_42 ) ;
F_1 ( & V_33 -> V_43 ) ;
F_2 ( & V_33 -> V_44 ) ;
F_34 ( & V_33 -> V_42 . V_3 , & V_10 . V_11 ,
V_40 ) ;
V_6 = F_5 ( & V_33 -> V_42 . V_3 ) ;
V_7 = F_7 ( & V_33 -> V_42 . V_3 ) ;
if ( V_6 == 1 ) {
F_35 ( V_7 , & V_33 -> V_43 . V_3 ) ;
F_35 ( V_7 , & V_33 -> V_44 ) ;
} else {
F_9 ( V_7 , & V_33 -> V_42 . V_3 ) ;
F_35 ( V_7 , & V_33 -> V_44 ) ;
V_7 = F_8 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
for ( V_8 = 0 ;
V_8 < ( V_37 -> V_45 - 1 ) *
V_23 [ V_37 -> V_13 ] ;
V_8 ++ ) {
F_9 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
F_35 ( V_7 ,
& V_33 -> V_43 . V_3 ) ;
V_7 = F_8 ( V_7 ,
& V_33 -> V_42 . V_3 ) ;
if ( V_7 >= V_41 )
break;
}
if ( F_5 ( & V_33 -> V_42 . V_3 ) == 0 )
F_4 ( & V_33 -> V_42 . V_3 ,
& V_33 -> V_44 ) ;
}
F_26 ( V_33 ) ;
}
F_22 ( & V_10 . V_34 ) ;
return 0 ;
}
static void F_36 ( struct V_46 * V_47 , int V_48 )
{
struct V_49 * V_50 = V_47 -> V_51 ;
struct V_36 * V_37 = V_50 -> V_37 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
int V_8 , V_52 ;
if ( V_48 > V_22 () || V_48 == V_50 -> V_48 )
return;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
if ( ! V_33 )
goto V_53;
V_52 = V_50 -> V_48 ;
V_50 -> V_48 = V_48 ;
F_2 ( & V_47 -> V_3 ) ;
F_35 ( V_48 , & V_47 -> V_3 ) ;
F_37 ( V_37 , L_2 ,
V_47 -> V_47 . V_54 , V_55 [ V_47 -> type ] ,
V_50 -> V_56 , V_48 ) ;
F_38 ( V_47 -> V_47 . V_54 , & V_47 -> V_3 ) ;
V_2 = & V_33 -> V_42 ;
F_35 ( V_48 , & V_2 -> V_3 ) ;
F_35 ( V_48 , & V_2 -> V_4 ) ;
for ( V_8 = 0 ; V_8 < V_37 -> V_57 ; V_8 ++ ) {
struct V_46 * V_58 ;
V_58 = & V_37 -> V_59 [ V_8 ] ;
if ( V_58 -> type != V_60 || V_58 == V_47 )
continue;
if ( F_39 ( V_52 , & V_58 -> V_3 ) )
goto V_53;
}
F_9 ( V_52 , & V_2 -> V_3 ) ;
F_9 ( V_52 , & V_2 -> V_4 ) ;
V_53:
F_22 ( & V_10 . V_34 ) ;
}
static void F_40 ( struct V_61 * V_62 ,
const T_1 * V_3 )
{
int V_48 = F_7 ( V_3 ) ;
struct V_46 * V_47 = F_41 ( V_62 ,
struct V_46 ,
V_62 ) ;
F_36 ( V_47 , V_48 ) ;
}
static void F_42 ( struct V_63 * V_64 )
{
}
static void F_43 ( struct V_46 * V_47 )
{
struct V_61 * V_62 = & V_47 -> V_62 ;
V_62 -> V_65 = V_47 -> V_47 . V_54 ;
V_62 -> V_62 = F_40 ;
V_62 -> V_66 = F_42 ;
if ( F_44 ( V_62 -> V_65 , V_62 ) )
F_45 ( L_3 ,
V_62 -> V_65 ) ;
}
static void F_46 ( struct V_46 * V_47 )
{
struct V_61 * V_62 = & V_47 -> V_62 ;
if ( F_44 ( V_62 -> V_65 , NULL ) )
F_45 ( L_4 ,
V_62 -> V_65 ) ;
}
static int F_47 ( struct V_36 * V_37 ,
struct V_46 * V_47 )
{
int V_67 ;
T_2 V_68 ;
struct V_32 * V_33 ;
struct V_1 * V_2 = NULL ;
struct V_49 * V_50 = NULL ;
struct V_69 * V_70 = NULL ;
char V_71 [ 64 ] ;
int V_48 = - 1 ;
V_71 [ 0 ] = '\0' ;
F_2 ( & V_47 -> V_3 ) ;
V_67 = F_48 ( & V_68 , V_24 ) ;
if ( ! V_67 )
return - V_25 ;
V_33 = F_28 ( V_37 -> V_13 ) ;
switch ( V_47 -> type ) {
case V_60 :
V_50 = (struct V_49 * ) V_47 -> V_51 ;
F_49 ( V_71 , 64 , L_5 , V_50 -> V_56 ) ;
V_2 = & V_33 -> V_42 ;
break;
case V_72 :
V_48 = F_7 ( & V_33 -> V_44 ) ;
break;
case V_73 :
V_70 = (struct V_69 * ) V_47 -> V_51 ;
if ( V_70 -> V_74 == V_75 )
V_48 = F_7 ( & V_33 -> V_44 ) ;
else
V_2 = & V_33 -> V_43 ;
F_49 ( V_71 , 64 , L_6 , V_70 -> V_74 ) ;
break;
default:
F_33 ( V_37 , L_7 , V_47 -> type ) ;
return - V_76 ;
}
if ( V_48 == - 1 && V_2 ) {
if ( F_50 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
F_51 ( V_68 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
V_48 = F_7 ( V_68 ) ;
F_35 ( V_48 , & V_2 -> V_4 ) ;
}
F_35 ( V_48 , & V_47 -> V_3 ) ;
F_52 ( V_37 , L_8 ,
V_47 -> V_47 . V_54 , V_55 [ V_47 -> type ] ,
V_71 , V_48 ) ;
F_38 ( V_47 -> V_47 . V_54 , & V_47 -> V_3 ) ;
if ( V_47 -> type == V_60 ) {
V_50 -> V_48 = V_48 ;
F_43 ( V_47 ) ;
}
F_53 ( V_68 ) ;
return 0 ;
}
int F_54 ( struct V_36 * V_37 , struct V_46 * V_47 )
{
int V_67 ;
F_17 ( & V_10 . V_34 ) ;
V_67 = F_47 ( V_37 , V_47 ) ;
F_22 ( & V_10 . V_34 ) ;
return V_67 ;
}
void F_55 ( struct V_36 * V_37 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = NULL ;
struct V_69 * V_70 ;
struct V_32 * V_33 ;
F_17 ( & V_10 . V_34 ) ;
V_33 = F_28 ( V_37 -> V_13 ) ;
switch ( V_47 -> type ) {
case V_60 :
V_2 = & V_33 -> V_42 ;
F_46 ( V_47 ) ;
break;
case V_72 :
break;
case V_73 :
V_70 = (struct V_69 * ) V_47 -> V_51 ;
if ( V_70 -> V_74 != V_75 )
V_2 = & V_33 -> V_43 ;
break;
default:
F_22 ( & V_10 . V_34 ) ;
return;
}
if ( V_2 ) {
F_51 ( & V_2 -> V_4 , & V_2 -> V_4 , & V_47 -> V_3 ) ;
if ( F_56 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
}
F_38 ( V_47 -> V_47 . V_54 , NULL ) ;
F_2 ( & V_47 -> V_3 ) ;
F_22 ( & V_10 . V_34 ) ;
}
static void F_57 ( T_3 V_77 , T_2 V_78 ,
struct V_79 * V_80 )
{
int V_6 , V_7 , V_8 ;
T_3 V_81 = V_10 . V_22 /
V_80 -> V_20 /
V_10 . V_21 ;
F_4 ( V_78 , & V_80 -> V_19 . V_3 ) ;
if ( V_80 -> V_20 > 0 ) {
V_6 = F_5 ( V_78 ) ;
V_7 = F_7 ( V_78 ) ;
for ( V_8 = 0 ;
V_8 < V_81 * V_10 . V_21 ;
V_8 ++ )
V_7 = F_8 ( V_7 , V_78 ) ;
for (; V_8 < V_6 ; V_8 ++ ) {
F_9 ( V_7 , V_78 ) ;
V_7 = F_8 ( V_7 , V_78 ) ;
}
F_58 ( V_78 , V_78 ,
V_81 *
V_10 . V_21 *
V_77 ) ;
}
}
int F_59 ( int V_13 )
{
int V_48 = - 1 , V_67 , V_8 ;
struct V_32 * V_33 ;
T_2 V_68 , V_78 , V_82 , V_83 ;
const struct V_39 * V_84 ,
* V_85 = F_60 ( V_86 ) ;
struct V_79 * V_80 = & V_10 ;
struct V_1 * V_2 = & V_80 -> V_19 ;
if ( F_5 ( V_85 ) == 1 ) {
F_61 ( V_87 , L_9 ,
V_86 -> V_88 , V_86 -> V_89 ,
F_62 ( V_85 ) ) ;
V_48 = F_7 ( V_85 ) ;
F_35 ( V_48 , & V_2 -> V_4 ) ;
goto V_90;
} else if ( F_5 ( V_85 ) < F_5 ( & V_2 -> V_3 ) ) {
F_61 ( V_87 , L_10 ,
V_86 -> V_88 , V_86 -> V_89 ,
F_62 ( V_85 ) ) ;
goto V_90;
}
V_67 = F_48 ( & V_68 , V_24 ) ;
if ( ! V_67 )
goto V_90;
V_67 = F_48 ( & V_78 , V_24 ) ;
if ( ! V_67 )
goto V_91;
V_67 = F_48 ( & V_82 , V_24 ) ;
if ( ! V_67 )
goto V_92;
V_67 = F_48 ( & V_83 , V_24 ) ;
if ( ! V_67 )
goto V_93;
F_17 ( & V_80 -> V_34 ) ;
if ( F_50 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
V_33 = F_28 ( V_13 ) ;
if ( V_33 ) {
F_4 ( V_83 , ( V_33 -> V_42 . V_5 ?
& V_33 -> V_42 . V_3 :
& V_33 -> V_42 . V_4 ) ) ;
F_63 ( V_83 , V_83 , ( V_33 -> V_43 . V_5 ?
& V_33 -> V_43 . V_3 :
& V_33 -> V_43 . V_4 ) ) ;
F_63 ( V_83 , V_83 , & V_33 -> V_44 ) ;
}
F_61 ( V_87 , L_11 ,
F_62 ( V_83 ) ) ;
F_4 ( V_78 , & V_2 -> V_3 ) ;
if ( V_80 -> V_20 > 0 ) {
for ( V_8 = 0 ; V_8 < V_80 -> V_20 ; V_8 ++ ) {
F_57 ( V_8 , V_78 , V_80 ) ;
F_51 ( V_68 , V_78 , & V_2 -> V_4 ) ;
if ( ! F_56 ( V_68 ) )
break;
}
}
F_61 ( V_87 , L_12 ,
F_62 ( V_78 ) ) ;
V_84 = F_31 ( V_13 ) ;
F_61 ( V_87 , L_13 , V_13 ,
F_62 ( V_84 ) ) ;
F_34 ( V_82 , V_78 , V_84 ) ;
F_51 ( V_82 , V_82 , & V_2 -> V_4 ) ;
F_61 ( V_87 , L_14 , V_13 ,
F_62 ( V_82 ) ) ;
F_51 ( V_68 , V_82 , V_83 ) ;
if ( ! F_56 ( V_68 ) )
F_4 ( V_82 , V_68 ) ;
if ( F_56 ( V_82 ) ) {
F_51 ( V_82 , V_78 , & V_2 -> V_4 ) ;
F_51 ( V_82 , V_82 , V_84 ) ;
F_61 ( V_87 ,
L_15 ,
F_62 ( V_82 ) ) ;
F_51 ( V_68 , V_82 , V_83 ) ;
if ( ! F_56 ( V_68 ) )
F_4 ( V_82 , V_68 ) ;
}
F_61 ( V_87 , L_16 ,
F_62 ( V_82 ) ) ;
V_48 = F_7 ( V_82 ) ;
if ( V_48 >= V_41 )
V_48 = - 1 ;
else
F_35 ( V_48 , & V_2 -> V_4 ) ;
F_22 ( & V_80 -> V_34 ) ;
F_61 ( V_87 , L_17 , V_48 ) ;
F_53 ( V_83 ) ;
V_93:
F_53 ( V_82 ) ;
V_92:
F_53 ( V_78 ) ;
V_91:
F_53 ( V_68 ) ;
V_90:
return V_48 ;
}
void F_64 ( int V_48 )
{
struct V_79 * V_80 = & V_10 ;
struct V_1 * V_2 = & V_80 -> V_19 ;
if ( V_48 < 0 )
return;
F_17 ( & V_80 -> V_34 ) ;
F_9 ( V_48 , & V_2 -> V_4 ) ;
F_61 ( V_87 , L_18 , V_48 ) ;
if ( F_56 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_22 ( & V_80 -> V_34 ) ;
}
