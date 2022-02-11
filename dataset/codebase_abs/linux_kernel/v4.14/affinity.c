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
V_10 . V_23 = V_23 () ;
F_3 () ;
V_24 = F_11 ( V_10 . V_21 ,
sizeof( * V_24 ) , V_25 ) ;
if ( ! V_24 )
return - V_26 ;
while ( V_17 -> V_27 ) {
V_15 = NULL ;
while ( ( V_15 = F_12 ( V_17 -> V_27 , V_17 -> V_28 , V_15 ) ) ) {
V_13 = F_13 ( V_15 -> V_29 ) ;
if ( V_13 < 0 )
V_13 = F_14 () ;
V_24 [ V_13 ] ++ ;
}
V_17 ++ ;
}
return 0 ;
}
void F_15 ( void )
{
struct V_30 * V_31 , * V_32 ;
struct V_33 * V_34 ;
F_16 ( & V_10 . V_35 ) ;
F_17 (pos, q, &node_affinity.list) {
V_34 = F_18 ( V_31 , struct V_33 ,
V_36 ) ;
F_19 ( V_31 ) ;
F_20 ( V_34 ) ;
}
F_21 ( & V_10 . V_35 ) ;
F_20 ( V_24 ) ;
}
static struct V_33 * F_22 ( int V_13 )
{
struct V_33 * V_34 ;
V_34 = F_23 ( sizeof( * V_34 ) , V_25 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_13 = V_13 ;
F_24 ( & V_34 -> V_36 ) ;
return V_34 ;
}
static void F_25 ( struct V_33 * V_34 )
{
F_26 ( & V_34 -> V_36 , & V_10 . V_36 ) ;
}
static struct V_33 * F_27 ( int V_13 )
{
struct V_30 * V_31 ;
struct V_33 * V_34 ;
F_28 (pos, &node_affinity.list) {
V_34 = F_18 ( V_31 , struct V_33 , V_36 ) ;
if ( V_34 -> V_13 == V_13 )
return V_34 ;
}
return NULL ;
}
int F_29 ( struct V_37 * V_38 )
{
int V_13 = F_13 ( V_38 -> V_39 -> V_29 ) ;
struct V_33 * V_34 ;
const struct V_40 * V_41 ;
int V_7 , V_6 , V_8 ;
if ( V_13 < 0 )
V_13 = F_14 () ;
V_38 -> V_13 = V_13 ;
V_41 = F_30 ( V_38 -> V_13 ) ;
if ( F_7 ( V_41 ) >= V_42 )
V_41 = F_31 ( 0 ) ;
F_16 ( & V_10 . V_35 ) ;
V_34 = F_27 ( V_38 -> V_13 ) ;
if ( ! V_34 ) {
V_34 = F_22 ( V_13 ) ;
if ( ! V_34 ) {
F_32 ( V_38 ,
L_1 ) ;
F_21 ( & V_10 . V_35 ) ;
return - V_26 ;
}
F_1 ( & V_34 -> V_43 ) ;
F_1 ( & V_34 -> V_44 ) ;
F_2 ( & V_34 -> V_45 ) ;
F_33 ( & V_34 -> V_43 . V_3 , & V_10 . V_11 ,
V_41 ) ;
V_6 = F_5 ( & V_34 -> V_43 . V_3 ) ;
V_7 = F_7 ( & V_34 -> V_43 . V_3 ) ;
if ( V_6 == 1 ) {
F_34 ( V_7 , & V_34 -> V_44 . V_3 ) ;
F_34 ( V_7 , & V_34 -> V_45 ) ;
} else {
F_9 ( V_7 , & V_34 -> V_43 . V_3 ) ;
F_34 ( V_7 , & V_34 -> V_45 ) ;
V_7 = F_8 ( V_7 ,
& V_34 -> V_43 . V_3 ) ;
for ( V_8 = 0 ;
V_8 < ( V_38 -> V_46 - 1 ) *
V_24 [ V_38 -> V_13 ] ;
V_8 ++ ) {
F_9 ( V_7 ,
& V_34 -> V_43 . V_3 ) ;
F_34 ( V_7 ,
& V_34 -> V_44 . V_3 ) ;
V_7 = F_8 ( V_7 ,
& V_34 -> V_43 . V_3 ) ;
if ( V_7 >= V_42 )
break;
}
if ( F_5 ( & V_34 -> V_43 . V_3 ) == 0 )
F_4 ( & V_34 -> V_43 . V_3 ,
& V_34 -> V_45 ) ;
}
F_25 ( V_34 ) ;
}
F_21 ( & V_10 . V_35 ) ;
return 0 ;
}
static void F_35 ( struct V_47 * V_48 , int V_49 )
{
struct V_50 * V_51 = V_48 -> V_52 ;
struct V_37 * V_38 = V_51 -> V_38 ;
struct V_33 * V_34 ;
struct V_1 * V_2 ;
int V_8 , V_53 ;
if ( V_49 > V_23 () || V_49 == V_51 -> V_49 )
return;
F_16 ( & V_10 . V_35 ) ;
V_34 = F_27 ( V_38 -> V_13 ) ;
if ( ! V_34 )
goto V_54;
V_53 = V_51 -> V_49 ;
V_51 -> V_49 = V_49 ;
F_2 ( & V_48 -> V_3 ) ;
F_34 ( V_49 , & V_48 -> V_3 ) ;
F_36 ( V_38 , L_2 ,
V_48 -> V_55 , V_56 [ V_48 -> type ] ,
V_51 -> V_57 , V_49 ) ;
F_37 ( V_48 -> V_55 , & V_48 -> V_3 ) ;
V_2 = & V_34 -> V_43 ;
F_34 ( V_49 , & V_2 -> V_3 ) ;
F_34 ( V_49 , & V_2 -> V_4 ) ;
for ( V_8 = 0 ; V_8 < V_38 -> V_58 ; V_8 ++ ) {
struct V_47 * V_59 ;
V_59 = & V_38 -> V_60 [ V_8 ] ;
if ( V_59 -> type != V_61 || V_59 == V_48 )
continue;
if ( F_38 ( V_53 , & V_59 -> V_3 ) )
goto V_54;
}
F_9 ( V_53 , & V_2 -> V_3 ) ;
F_9 ( V_53 , & V_2 -> V_4 ) ;
V_54:
F_21 ( & V_10 . V_35 ) ;
}
static void F_39 ( struct V_62 * V_63 ,
const T_1 * V_3 )
{
int V_49 = F_7 ( V_3 ) ;
struct V_47 * V_48 = F_40 ( V_63 ,
struct V_47 ,
V_63 ) ;
F_35 ( V_48 , V_49 ) ;
}
static void F_41 ( struct V_64 * V_65 )
{
}
static void F_42 ( struct V_47 * V_48 )
{
struct V_62 * V_63 = & V_48 -> V_63 ;
V_63 -> V_55 = V_48 -> V_55 ;
V_63 -> V_63 = F_39 ;
V_63 -> V_66 = F_41 ;
if ( F_43 ( V_63 -> V_55 , V_63 ) )
F_44 ( L_3 ,
V_63 -> V_55 ) ;
}
static void F_45 ( struct V_47 * V_48 )
{
struct V_62 * V_63 = & V_48 -> V_63 ;
if ( F_43 ( V_63 -> V_55 , NULL ) )
F_44 ( L_4 ,
V_63 -> V_55 ) ;
}
static int F_46 ( struct V_37 * V_38 ,
struct V_47 * V_48 )
{
int V_67 ;
T_2 V_68 ;
struct V_33 * V_34 ;
struct V_1 * V_2 = NULL ;
struct V_50 * V_51 = NULL ;
struct V_69 * V_70 = NULL ;
char V_71 [ 64 ] ;
int V_49 = - 1 ;
V_71 [ 0 ] = '\0' ;
F_2 ( & V_48 -> V_3 ) ;
V_67 = F_47 ( & V_68 , V_25 ) ;
if ( ! V_67 )
return - V_26 ;
V_34 = F_27 ( V_38 -> V_13 ) ;
switch ( V_48 -> type ) {
case V_61 :
V_51 = (struct V_50 * ) V_48 -> V_52 ;
F_48 ( V_71 , 64 , L_5 , V_51 -> V_57 ) ;
V_2 = & V_34 -> V_43 ;
break;
case V_72 :
V_49 = F_7 ( & V_34 -> V_45 ) ;
break;
case V_73 :
V_70 = (struct V_69 * ) V_48 -> V_52 ;
if ( V_70 -> V_74 == V_75 )
V_49 = F_7 ( & V_34 -> V_45 ) ;
else
V_2 = & V_34 -> V_44 ;
F_48 ( V_71 , 64 , L_6 , V_70 -> V_74 ) ;
break;
default:
F_32 ( V_38 , L_7 , V_48 -> type ) ;
return - V_76 ;
}
if ( V_49 == - 1 && V_2 ) {
if ( F_49 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
F_50 ( V_68 , & V_2 -> V_3 , & V_2 -> V_4 ) ;
V_49 = F_7 ( V_68 ) ;
F_34 ( V_49 , & V_2 -> V_4 ) ;
}
F_34 ( V_49 , & V_48 -> V_3 ) ;
F_51 ( V_38 , L_8 ,
V_48 -> V_55 , V_56 [ V_48 -> type ] ,
V_71 , V_49 ) ;
F_37 ( V_48 -> V_55 , & V_48 -> V_3 ) ;
if ( V_48 -> type == V_61 ) {
V_51 -> V_49 = V_49 ;
F_42 ( V_48 ) ;
}
F_52 ( V_68 ) ;
return 0 ;
}
int F_53 ( struct V_37 * V_38 , struct V_47 * V_48 )
{
int V_67 ;
F_16 ( & V_10 . V_35 ) ;
V_67 = F_46 ( V_38 , V_48 ) ;
F_21 ( & V_10 . V_35 ) ;
return V_67 ;
}
void F_54 ( struct V_37 * V_38 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = NULL ;
struct V_69 * V_70 ;
struct V_33 * V_34 ;
F_16 ( & V_10 . V_35 ) ;
V_34 = F_27 ( V_38 -> V_13 ) ;
switch ( V_48 -> type ) {
case V_61 :
V_2 = & V_34 -> V_43 ;
F_45 ( V_48 ) ;
break;
case V_72 :
break;
case V_73 :
V_70 = (struct V_69 * ) V_48 -> V_52 ;
if ( V_70 -> V_74 != V_75 )
V_2 = & V_34 -> V_44 ;
break;
default:
F_21 ( & V_10 . V_35 ) ;
return;
}
if ( V_2 ) {
F_50 ( & V_2 -> V_4 , & V_2 -> V_4 , & V_48 -> V_3 ) ;
if ( F_55 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
}
F_37 ( V_48 -> V_55 , NULL ) ;
F_2 ( & V_48 -> V_3 ) ;
F_21 ( & V_10 . V_35 ) ;
}
static void F_56 ( T_3 V_77 , T_2 V_78 ,
struct V_79 * V_80 )
{
int V_6 , V_7 , V_8 ;
T_3 V_81 = V_10 . V_23 /
V_80 -> V_20 /
V_10 . V_22 ;
F_4 ( V_78 , & V_80 -> V_19 . V_3 ) ;
if ( V_80 -> V_20 > 0 ) {
V_6 = F_5 ( V_78 ) ;
V_7 = F_7 ( V_78 ) ;
for ( V_8 = 0 ;
V_8 < V_81 * V_10 . V_22 ;
V_8 ++ )
V_7 = F_8 ( V_7 , V_78 ) ;
for (; V_8 < V_6 ; V_8 ++ ) {
F_9 ( V_7 , V_78 ) ;
V_7 = F_8 ( V_7 , V_78 ) ;
}
F_57 ( V_78 , V_78 ,
V_81 *
V_10 . V_22 *
V_77 ) ;
}
}
int F_58 ( int V_13 )
{
int V_49 = - 1 , V_67 , V_8 ;
struct V_33 * V_34 ;
T_2 V_68 , V_78 , V_82 , V_83 ;
const struct V_40 * V_84 ,
* V_85 = & V_86 -> V_87 ;
struct V_79 * V_80 = & V_10 ;
struct V_1 * V_2 = & V_80 -> V_19 ;
if ( F_5 ( V_85 ) == 1 ) {
F_59 ( V_88 , L_9 ,
V_86 -> V_89 , V_86 -> V_90 ,
F_60 ( V_85 ) ) ;
V_49 = F_7 ( V_85 ) ;
F_34 ( V_49 , & V_2 -> V_4 ) ;
goto V_91;
} else if ( F_5 ( V_85 ) < F_5 ( & V_2 -> V_3 ) ) {
F_59 ( V_88 , L_10 ,
V_86 -> V_89 , V_86 -> V_90 ,
F_60 ( V_85 ) ) ;
goto V_91;
}
V_67 = F_47 ( & V_68 , V_25 ) ;
if ( ! V_67 )
goto V_91;
V_67 = F_47 ( & V_78 , V_25 ) ;
if ( ! V_67 )
goto V_92;
V_67 = F_47 ( & V_82 , V_25 ) ;
if ( ! V_67 )
goto V_93;
V_67 = F_47 ( & V_83 , V_25 ) ;
if ( ! V_67 )
goto V_94;
F_16 ( & V_80 -> V_35 ) ;
if ( F_49 ( & V_2 -> V_3 , & V_2 -> V_4 ) ) {
V_2 -> V_5 ++ ;
F_2 ( & V_2 -> V_4 ) ;
}
V_34 = F_27 ( V_13 ) ;
if ( V_34 ) {
F_4 ( V_83 , ( V_34 -> V_43 . V_5 ?
& V_34 -> V_43 . V_3 :
& V_34 -> V_43 . V_4 ) ) ;
F_61 ( V_83 , V_83 , ( V_34 -> V_44 . V_5 ?
& V_34 -> V_44 . V_3 :
& V_34 -> V_44 . V_4 ) ) ;
F_61 ( V_83 , V_83 , & V_34 -> V_45 ) ;
}
F_59 ( V_88 , L_11 ,
F_60 ( V_83 ) ) ;
F_4 ( V_78 , & V_2 -> V_3 ) ;
if ( V_80 -> V_20 > 0 ) {
for ( V_8 = 0 ; V_8 < V_80 -> V_20 ; V_8 ++ ) {
F_56 ( V_8 , V_78 , V_80 ) ;
F_50 ( V_68 , V_78 , & V_2 -> V_4 ) ;
if ( ! F_55 ( V_68 ) )
break;
}
}
F_59 ( V_88 , L_12 ,
F_60 ( V_78 ) ) ;
V_84 = F_30 ( V_13 ) ;
F_59 ( V_88 , L_13 , V_13 ,
F_60 ( V_84 ) ) ;
F_33 ( V_82 , V_78 , V_84 ) ;
F_50 ( V_82 , V_82 , & V_2 -> V_4 ) ;
F_59 ( V_88 , L_14 , V_13 ,
F_60 ( V_82 ) ) ;
F_50 ( V_68 , V_82 , V_83 ) ;
if ( ! F_55 ( V_68 ) )
F_4 ( V_82 , V_68 ) ;
if ( F_55 ( V_82 ) ) {
F_50 ( V_82 , V_78 , & V_2 -> V_4 ) ;
F_50 ( V_82 , V_82 , V_84 ) ;
F_59 ( V_88 ,
L_15 ,
F_60 ( V_82 ) ) ;
F_50 ( V_68 , V_82 , V_83 ) ;
if ( ! F_55 ( V_68 ) )
F_4 ( V_82 , V_68 ) ;
}
F_59 ( V_88 , L_16 ,
F_60 ( V_82 ) ) ;
V_49 = F_7 ( V_82 ) ;
if ( V_49 >= V_42 )
V_49 = - 1 ;
else
F_34 ( V_49 , & V_2 -> V_4 ) ;
F_21 ( & V_80 -> V_35 ) ;
F_59 ( V_88 , L_17 , V_49 ) ;
F_52 ( V_83 ) ;
V_94:
F_52 ( V_82 ) ;
V_93:
F_52 ( V_78 ) ;
V_92:
F_52 ( V_68 ) ;
V_91:
return V_49 ;
}
void F_62 ( int V_49 )
{
struct V_79 * V_80 = & V_10 ;
struct V_1 * V_2 = & V_80 -> V_19 ;
if ( V_49 < 0 )
return;
F_16 ( & V_80 -> V_35 ) ;
F_9 ( V_49 , & V_2 -> V_4 ) ;
F_59 ( V_88 , L_18 , V_49 ) ;
if ( F_55 ( & V_2 -> V_4 ) && V_2 -> V_5 ) {
V_2 -> V_5 -- ;
F_4 ( & V_2 -> V_4 , & V_2 -> V_3 ) ;
}
F_21 ( & V_80 -> V_35 ) ;
}
