static int
F_1 ( T_1 V_1 ,
void * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_1 ,
V_2 ,
V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_4 ( V_5 , struct V_6 , V_8 ) ;
int V_9 = - 9 ;
switch ( V_7 -> V_10 ) {
case V_11 :
V_9 = F_5 ( V_7 -> V_12 ) ;
break;
case V_13 :
V_9 = F_6 ( V_7 -> V_12 ) ;
break;
case V_14 :
V_9 = F_7 ( V_7 -> V_12 , V_7 -> V_15 ,
V_7 -> V_16 ) ;
break;
default:
F_8 ( L_1 , V_7 -> V_12 , V_7 -> V_10 ) ;
break;
}
F_9 ( ( void * ) V_5 ) ;
}
int F_10 ( struct V_17 * V_12 )
{
if ( V_12 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_8 ( L_2 ) ;
return - V_20 ;
}
F_12 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_10 = V_11 ;
if ( ! F_13 ( V_12 -> V_18 , & V_5 -> V_8 ) ) {
F_9 ( V_5 ) ;
return - V_21 ;
}
}
return 0 ;
}
int F_14 ( struct V_17 * V_12 )
{
if ( V_12 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_8 ( L_2 ) ;
return - V_20 ;
}
F_12 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_10 = V_13 ;
if ( ! F_13 ( V_12 -> V_18 , & V_5 -> V_8 ) ) {
F_9 ( V_5 ) ;
return - V_21 ;
}
}
return 0 ;
}
int F_15 ( struct V_17 * V_12 ,
unsigned int V_15 , void * V_16 )
{
if ( V_12 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_11 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_8 ( L_2 ) ;
return - V_20 ;
}
F_12 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_10 = V_14 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_15 = V_15 ;
if ( ! F_13 ( V_12 -> V_18 , & V_5 -> V_8 ) ) {
F_9 ( V_5 ) ;
return - V_21 ;
}
}
return 0 ;
}
static void F_16 ( struct V_17 * V_12 )
{
V_12 -> V_18 = F_17 ( L_3 , V_22 , 1 ) ;
}
static void F_18 ( struct V_17 * V_12 )
{
if ( V_12 -> V_18 ) {
F_19 ( V_12 -> V_18 ) ;
F_20 ( V_12 -> V_18 ) ;
V_12 -> V_18 = NULL ;
}
}
static void F_21 ( void * V_23 ,
const T_2 V_24 ,
void * V_25 )
{
struct V_26 * V_27 = V_23 ;
int V_28 ;
int V_29 ;
struct V_30 V_31 ;
if ( V_24 != V_32 )
return;
if ( ! V_27 ) {
F_8 ( L_4 ) ;
F_22 () ;
return;
}
if ( ! V_27 -> V_33 [ 0 ] ) {
F_8 ( L_5 ) ;
F_22 () ;
return;
}
V_28 = F_23 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) , & V_29 , V_34 ) ;
if ( V_31 . type == V_35 ) {
F_24 ( L_6 ,
V_27 , V_31 . V_36 . V_37 . V_38 ) ;
V_27 -> V_37 = V_31 . V_36 . V_37 . V_38 ;
F_25 ( & V_27 -> V_39 ) ;
} else if ( V_31 . type == V_40 ) {
struct V_17 * V_12 = V_27 -> V_12 ;
F_24 ( L_7 ,
V_27 , V_31 . V_36 . F_25 . V_15 ) ;
if ( V_31 . V_36 . F_25 . V_41 != V_42 ||
V_31 . V_36 . F_25 . V_43 != V_44 )
F_8 ( L_8 ) ;
else if ( V_12 ) {
F_26 ( V_31 . V_36 . F_25 . V_15 ,
& V_12 -> V_45 ) ;
F_27 ( V_12 ) ;
} else {
F_8 ( L_9 ,
V_12 ) ;
}
} else {
F_8 ( L_10 , V_31 . type ) ;
}
}
static struct V_26 *
F_28 ( T_3 V_46 ,
T_4 * * V_47 ,
unsigned int V_48 )
{
unsigned int V_49 ;
struct V_26 * V_27 ;
int V_28 ;
int V_9 ;
F_24 ( L_11 , V_50 ) ;
if ( V_48 > V_51 ) {
F_8 ( L_12 ,
V_50 , V_48 , V_51 ) ;
return F_29 ( - V_52 ) ;
}
V_27 = F_30 ( sizeof( * V_27 ) , V_53 ) ;
if ( ! V_27 )
return F_29 ( - V_20 ) ;
V_27 -> V_48 = V_48 ;
F_31 ( & V_27 -> V_54 ) ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
T_5 V_55 = {
. V_56 = F_32 ( V_57 , V_58 ) ,
. V_59 = V_60 ,
. V_61 = V_47 [ V_49 ] ,
. V_62 = 0 ,
. V_63 = 0 ,
. V_64 = F_21 ,
. V_65 = V_27 ,
. V_66 = 1 ,
. V_67 = 1 ,
. V_68 = 0
} ;
F_24 ( L_13 , V_50 , V_49 ) ;
V_28 = F_33 ( V_46 , & V_55 ,
& V_27 -> V_33 [ V_49 ] ) ;
F_24 ( L_14 , V_50 , V_49 , V_27 -> V_33 [ V_49 ] , V_28 ) ;
if ( V_28 ) {
F_8 ( L_15 ,
V_50 , V_28 ) ;
V_9 = - V_69 ;
goto V_70;
}
F_34 ( V_27 -> V_33 [ V_49 ] ) ;
}
F_24 ( L_16 , V_50 ) ;
return V_27 ;
V_70:
for ( V_49 = 0 ; V_49 < V_27 -> V_48 ; V_49 ++ ) {
F_8 ( L_17 , V_50 , V_49 , V_27 -> V_33 [ V_49 ] ) ;
if ( V_27 -> V_33 [ V_49 ] )
F_35 ( V_27 -> V_33 [ V_49 ] ) ;
}
F_9 ( V_27 ) ;
F_8 ( L_18 , V_50 ) ;
return F_29 ( V_9 ) ;
}
static int F_36 ( struct V_26 * V_27 )
{
unsigned int V_49 ;
if ( ! V_27 ) {
F_8 ( L_19 , V_50 , V_27 ) ;
return - 1 ;
}
F_24 ( L_20 , V_27 -> V_48 ) ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
for ( V_49 = 0 ; V_49 < V_27 -> V_48 ; V_49 ++ ) {
int V_28 ;
F_24 ( L_22 , V_49 , V_27 -> V_33 [ V_49 ] ) ;
F_38 ( V_27 -> V_33 [ V_49 ] ) ;
V_28 = F_35 ( V_27 -> V_33 [ V_49 ] ) ;
if ( V_28 ) {
F_24 ( L_23 ,
V_50 , V_28 ) ;
}
}
F_39 ( & V_27 -> V_54 ) ;
F_9 ( V_27 ) ;
return 0 ;
}
static int F_40 ( struct V_17 * V_12 )
{
static T_3 V_46 ;
static T_4 * V_72 ;
static int V_73 ;
struct V_26 * V_27 =
(struct V_26 * ) V_12 -> V_27 ;
int V_9 ;
F_41 ( L_24 , V_50 ) ;
F_42 ( V_27 ) ;
if ( V_27 ) {
F_8 ( L_25 ,
V_50 , V_27 ) ;
V_27 -> V_12 = V_12 ;
V_12 -> V_27 = V_27 ;
return 0 ;
}
if ( ! V_73 ) {
V_9 = F_43 ( & V_46 ) ;
if ( V_9 ) {
F_8 ( L_26 ,
V_50 , V_9 ) ;
return - V_74 ;
}
V_9 = F_44 ( NULL , 0 , V_46 ) ;
if ( V_9 ) {
F_8 ( L_27 ,
V_50 , V_9 ) ;
F_9 ( V_46 ) ;
return - V_74 ;
}
V_73 = 1 ;
}
V_27 = F_28 ( V_46 , & V_72 , 1 ) ;
if ( F_45 ( V_27 ) ) {
F_8 ( L_28 , V_50 ) ;
return F_46 ( V_27 ) ;
}
V_27 -> V_12 = V_12 ;
V_12 -> V_27 = V_27 ;
F_24 ( L_29 ) ;
return 0 ;
}
int F_47 ( struct V_17 * V_12 )
{
struct V_26 * V_27 ;
struct V_30 V_31 ;
int V_28 ;
int V_9 ;
F_16 ( V_12 ) ;
V_9 = F_40 ( V_12 ) ;
if ( V_9 ) {
V_9 = - 1 ;
goto exit;
}
V_27 = V_12 -> V_27 ;
F_24 ( L_30 , V_27 ) ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 , V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_31 . type = V_75 ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
exit:
return V_9 ;
}
static int F_48 ( struct V_17 * V_12 ,
struct V_77 * V_78 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
F_41 ( L_32 ,
V_78 -> V_79 , V_78 -> V_80 ) ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_27 -> V_37 = - 1 ;
V_31 . type = V_81 ;
V_31 . V_36 . V_82 . V_79 = V_78 -> V_79 ;
V_31 . V_36 . V_82 . V_80 = V_78 -> V_80 ;
F_49 ( & V_27 -> V_39 ) ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
F_50 ( & V_27 -> V_39 ) ;
if ( V_27 -> V_37 ) {
F_8 ( L_33 , V_50 , V_27 -> V_37 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
return V_9 ;
}
int F_51 ( struct V_77 * V_78 )
{
int V_49 ;
int V_9 = 0 ;
F_24 ( L_32 , V_78 -> V_79 , V_78 -> V_80 ) ;
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ ) {
if ( V_78 -> V_84 & ( 1 << V_49 ) ) {
if ( ! V_78 -> V_12 [ V_49 ] ) {
F_24 ( L_34 , V_49 , V_78 -> V_12 [ V_49 ] , V_78 -> V_84 ) ;
V_9 = 0 ;
} else if ( F_48 ( V_78 -> V_12 [ V_49 ] , V_78 ) != 0 ) {
F_8 ( L_35 , V_49 ) ;
V_9 = - 1 ;
} else {
F_24 ( L_36 , V_49 ) ;
}
}
}
return V_9 ;
}
int F_52 ( struct V_17 * V_12 ,
unsigned int V_85 , unsigned int V_86 ,
unsigned int V_87 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
F_41 ( L_37 ,
V_85 , V_86 , V_87 ) ;
V_9 = F_48 ( V_12 , V_12 -> V_78 ) ;
if ( V_9 ) {
F_8 ( L_38 ) ;
return - V_52 ;
}
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 , V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_27 -> V_37 = - 1 ;
V_31 . type = V_88 ;
V_31 . V_36 . V_89 . V_85 = V_85 ;
V_31 . V_36 . V_89 . V_86 = V_86 ;
V_31 . V_36 . V_89 . V_87 = V_87 ;
F_49 ( & V_27 -> V_39 ) ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
F_50 ( & V_27 -> V_39 ) ;
if ( V_27 -> V_37 ) {
F_8 ( L_39 , V_50 , V_27 -> V_37 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
return V_9 ;
}
int F_53 ( struct V_17 * V_12 )
{
return 0 ;
}
static int F_5 ( struct V_17 * V_12 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_31 . type = V_90 ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
return V_9 ;
}
static int F_6 ( struct V_17 * V_12 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_31 . type = V_91 ;
V_31 . V_36 . V_92 . V_93 = V_12 -> V_93 ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
return V_9 ;
}
int F_54 ( struct V_17 * V_12 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
F_18 ( V_12 ) ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
V_31 . type = V_94 ;
F_49 ( & V_27 -> V_39 ) ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
F_50 ( & V_27 -> V_39 ) ;
if ( V_27 -> V_37 ) {
F_8 ( L_40 ,
V_50 , V_27 -> V_37 ) ;
V_9 = - 1 ;
goto V_76;
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
F_36 ( V_27 ) ;
V_12 -> V_27 = NULL ;
return V_9 ;
}
static int F_7 ( struct V_17 * V_12 ,
unsigned int V_15 , void * V_16 )
{
struct V_30 V_31 ;
struct V_26 * V_27 = V_12 -> V_27 ;
int V_28 ;
int V_9 ;
F_41 ( L_41 , V_15 , V_16 ) ;
if ( F_37 ( & V_27 -> V_54 ) ) {
F_24 ( L_21 ,
V_27 -> V_48 ) ;
return - V_71 ;
}
F_38 ( V_27 -> V_33 [ 0 ] ) ;
if ( V_27 -> V_95 == 0 &&
F_55 ( V_27 -> V_33 [ 0 ] , & V_27 -> V_95 ) == 0 )
F_24 ( L_42 , V_50 , V_27 -> V_95 ) ;
V_31 . type = V_96 ;
V_31 . V_36 . V_97 . V_15 = V_15 ;
V_31 . V_36 . V_97 . V_98 = V_27 -> V_95 < 2 || V_99 ? 0 : 4000 ;
V_31 . V_36 . V_97 . V_41 = V_42 ;
V_31 . V_36 . V_97 . V_43 = V_44 ;
V_31 . V_36 . V_97 . V_100 = V_16 == NULL ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
& V_31 , sizeof( V_31 ) ) ;
if ( V_28 ) {
F_8 ( L_31 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
if ( ! V_31 . V_36 . V_97 . V_100 ) {
if ( ! V_31 . V_36 . V_97 . V_98 ) {
V_28 = F_56 ( V_27 -> V_33 [ 0 ] ,
V_16 , V_15 ,
0 * V_101
+
1 * V_102 ,
NULL ) ;
} else {
while ( V_15 > 0 ) {
int V_103 = F_57 ( int , V_31 . V_36 . V_97 . V_98 , V_15 ) ;
V_28 = F_1 ( V_27 -> V_33 [ 0 ] ,
V_16 , V_103 ) ;
V_16 = ( char * ) V_16 + V_103 ;
V_15 -= V_103 ;
}
}
if ( V_28 ) {
F_8 ( L_43 ,
V_50 , V_28 ) ;
V_9 = - 1 ;
goto V_76;
}
}
V_9 = 0 ;
V_76:
F_34 ( V_27 -> V_33 [ 0 ] ) ;
F_39 ( & V_27 -> V_54 ) ;
return V_9 ;
}
void F_58 ( struct V_17 * V_12 )
{
}
void F_59 ( struct V_17 * V_12 )
{
}
unsigned int F_60 ( struct V_17 * V_12 )
{
unsigned int V_15 = F_61 ( & V_12 -> V_45 ) ;
F_62 ( V_15 , & V_12 -> V_45 ) ;
return V_15 ;
}
