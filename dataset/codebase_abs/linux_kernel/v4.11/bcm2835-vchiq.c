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
F_5 ( L_1 , V_7 -> V_10 , V_7 -> V_11 ) ;
switch ( V_7 -> V_11 ) {
case V_12 :
V_9 = F_6 ( V_7 -> V_10 ) ;
break;
case V_13 :
V_9 = F_7 ( V_7 -> V_10 ) ;
break;
case V_14 :
V_9 = F_8 ( V_7 -> V_10 , V_7 -> V_15 ,
V_7 -> V_16 ) ;
break;
default:
F_9 ( L_2 , V_7 -> V_10 , V_7 -> V_11 ) ;
break;
}
F_10 ( ( void * ) V_5 ) ;
F_5 ( L_3 , V_9 ) ;
}
int F_11 ( struct V_17 * V_10 )
{
int V_9 = - 1 ;
F_5 ( L_4 ) ;
if ( V_10 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_19 ) ;
if ( V_5 ) {
F_13 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_12 ;
if ( F_14 ( V_10 -> V_18 , & V_5 -> V_8 ) )
V_9 = 0 ;
} else
F_9 ( L_5 ) ;
}
F_5 ( L_3 , V_9 ) ;
return V_9 ;
}
int F_15 ( struct V_17 * V_10 )
{
int V_9 = - 1 ;
F_5 ( L_4 ) ;
if ( V_10 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_19 ) ;
if ( V_5 ) {
F_13 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_13 ;
if ( F_14 ( V_10 -> V_18 , & V_5 -> V_8 ) )
V_9 = 0 ;
} else
F_9 ( L_5 ) ;
}
F_5 ( L_3 , V_9 ) ;
return V_9 ;
}
int F_16 ( struct V_17 * V_10 ,
unsigned int V_15 , void * V_16 )
{
int V_9 = - 1 ;
F_5 ( L_4 ) ;
if ( V_10 -> V_18 ) {
struct V_6 * V_5 ;
V_5 = F_12 ( sizeof( * V_5 ) , V_19 ) ;
if ( V_5 ) {
F_13 ( & V_5 -> V_8 , F_3 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_11 = V_14 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_15 = V_15 ;
if ( F_14 ( V_10 -> V_18 , & V_5 -> V_8 ) )
V_9 = 0 ;
} else
F_9 ( L_5 ) ;
}
F_5 ( L_3 , V_9 ) ;
return V_9 ;
}
static void F_17 ( struct V_17 * V_10 )
{
V_10 -> V_18 = F_18 ( L_6 , V_20 , 1 ) ;
return;
}
static void F_19 ( struct V_17 * V_10 )
{
if ( V_10 -> V_18 ) {
F_20 ( V_10 -> V_18 ) ;
F_21 ( V_10 -> V_18 ) ;
V_10 -> V_18 = NULL ;
}
return;
}
static void F_22 ( void * V_21 ,
const T_2 V_22 ,
void * V_23 )
{
struct V_24 * V_25 = V_21 ;
int V_26 ;
int V_27 ;
struct V_28 V_29 ;
F_5 ( L_7 ,
V_25 , V_25 ? V_25 -> V_30 [ 0 ] : NULL , V_25 ? V_25 -> V_10 : NULL , V_22 , V_23 ) ;
if ( V_22 != V_31 ) {
return;
}
if ( ! V_25 ) {
F_9 ( L_8 ) ;
F_23 () ;
return;
}
if ( ! V_25 -> V_30 [ 0 ] ) {
F_9 ( L_9 ) ;
F_23 () ;
return;
}
V_26 = F_24 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) , & V_27 , V_32 ) ;
if ( V_29 . type == V_33 ) {
F_5 ( L_10 ,
V_25 , V_29 . V_34 . V_35 . V_36 ) ;
V_25 -> V_35 = V_29 . V_34 . V_35 . V_36 ;
F_25 ( & V_25 -> V_37 ) ;
} else if ( V_29 . type == V_38 ) {
struct V_17 * V_10 = V_25 -> V_10 ;
F_5 ( L_11 ,
V_25 , V_29 . V_34 . F_25 . V_15 ) ;
if ( V_29 . V_34 . F_25 . V_39 != V_40 ||
V_29 . V_34 . F_25 . V_41 != V_42 )
F_9 ( L_12 ) ;
else if ( V_10 ) {
F_26 ( V_29 . V_34 . F_25 . V_15 ,
& V_10 -> V_43 ) ;
F_27 ( V_10 ) ;
} else {
F_9 ( L_13 ,
V_10 ) ;
}
} else {
F_9 ( L_14 , V_29 . type ) ;
}
F_5 ( L_15 ) ;
}
static struct V_24 *
F_28 ( T_3 V_44 ,
T_4 * * V_45 ,
unsigned int V_46 )
{
unsigned int V_47 ;
struct V_24 * V_25 ;
int V_26 ;
F_5 ( L_16 , V_48 ) ;
if ( V_46 > V_49 ) {
F_9 ( L_17 ,
V_48 , V_46 , V_49 ) ;
return NULL ;
}
V_25 = F_12 ( sizeof( * V_25 ) , V_50 ) ;
if ( ! V_25 )
return NULL ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_46 = V_46 ;
F_29 ( & V_25 -> V_51 ) ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ ) {
T_5 V_52 = {
F_30 ( V_53 , V_54 ) ,
V_55 ,
V_45 [ V_47 ] ,
0 ,
0 ,
F_22 ,
V_25 ,
1 ,
1 ,
0
} ;
F_5 ( L_18 , V_48 , V_47 ) ;
V_26 = F_31 ( V_44 , & V_52 ,
& V_25 -> V_30 [ V_47 ] ) ;
F_5 ( L_19 , V_48 , V_47 , V_25 -> V_30 [ V_47 ] , V_26 ) ;
if ( V_26 ) {
F_9 ( L_20 ,
V_48 , V_26 ) ;
goto V_56;
}
F_32 ( V_25 -> V_30 [ V_47 ] ) ;
}
F_5 ( L_21 , V_48 ) ;
return V_25 ;
V_56:
for ( V_47 = 0 ; V_47 < V_25 -> V_46 ; V_47 ++ ) {
F_9 ( L_22 , V_48 , V_47 , V_25 -> V_30 [ V_47 ] ) ;
if ( V_25 -> V_30 [ V_47 ] )
F_33 ( V_25 -> V_30 [ V_47 ] ) ;
}
F_10 ( V_25 ) ;
F_9 ( L_23 , V_48 ) ;
return NULL ;
}
static int F_34 ( struct V_24 * V_25 )
{
unsigned int V_47 ;
F_5 ( L_4 ) ;
if ( ! V_25 ) {
F_9 ( L_24 , V_48 , V_25 ) ;
return - 1 ;
}
F_5 ( L_25 , V_25 -> V_46 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
for ( V_47 = 0 ; V_47 < V_25 -> V_46 ; V_47 ++ ) {
int V_26 ;
F_5 ( L_27 , V_47 , V_25 -> V_30 [ V_47 ] ) ;
F_36 ( V_25 -> V_30 [ V_47 ] ) ;
V_26 = F_33 ( V_25 -> V_30 [ V_47 ] ) ;
if ( V_26 ) {
F_5 ( L_28 ,
V_48 , V_26 ) ;
}
}
F_37 ( & V_25 -> V_51 ) ;
F_10 ( V_25 ) ;
F_5 ( L_15 ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_10 )
{
static T_3 V_44 ;
static T_4 * V_58 ;
static int V_59 ;
struct V_24 * V_25 =
(struct V_24 * ) V_10 -> V_25 ;
int V_9 ;
F_5 ( L_4 ) ;
F_39 ( L_29 , V_48 ) ;
F_40 ( V_25 ) ;
if ( V_25 ) {
F_9 ( L_30 ,
V_48 , V_25 ) ;
V_25 -> V_10 = V_10 ;
V_10 -> V_25 = V_25 ;
V_9 = 0 ;
goto V_60;
}
if ( ! V_59 ) {
V_9 = F_41 ( & V_44 ) ;
if ( V_9 ) {
F_9 ( L_31 ,
V_48 , V_9 ) ;
V_9 = - V_61 ;
goto V_60;
}
V_9 = F_42 ( NULL , 0 , V_44 ) ;
if ( V_9 ) {
F_9 ( L_32 ,
V_48 , V_9 ) ;
V_9 = - V_61 ;
goto V_60;
}
V_59 = 1 ;
}
V_25 = F_28 ( V_44 , & V_58 , 1 ) ;
if ( ! V_25 ) {
F_9 ( L_33 , V_48 ) ;
V_9 = - V_62 ;
goto V_60;
}
V_25 -> V_10 = V_10 ;
V_10 -> V_25 = V_25 ;
F_5 ( L_34 ) ;
V_9 = 0 ;
V_60:
F_5 ( L_15 ) ;
return V_9 ;
}
int F_43 ( struct V_17 * V_10 )
{
struct V_24 * V_25 ;
struct V_28 V_29 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
F_17 ( V_10 ) ;
V_9 = F_38 ( V_10 ) ;
if ( V_9 ) {
V_9 = - 1 ;
goto exit;
}
V_25 = V_10 -> V_25 ;
F_5 ( L_35 , V_25 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 , V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_29 . type = V_63 ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
exit:
F_5 ( L_15 ) ;
return V_9 ;
}
static int F_44 ( struct V_17 * V_10 ,
struct V_65 * V_66 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
F_39 ( L_37 ,
V_66 -> V_67 , V_66 -> V_68 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_25 -> V_35 = - 1 ;
V_29 . type = V_69 ;
V_29 . V_34 . V_70 . V_67 = V_66 -> V_67 ;
V_29 . V_34 . V_70 . V_68 = V_66 -> V_68 ;
F_45 ( & V_25 -> V_37 ) ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
F_46 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_35 ) {
F_9 ( L_38 , V_48 , V_25 -> V_35 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_5 ( L_15 ) ;
return V_9 ;
}
int F_47 ( struct V_65 * V_66 )
{
int V_47 ;
int V_9 = 0 ;
F_5 ( L_4 ) ;
F_5 ( L_37 , V_66 -> V_67 , V_66 -> V_68 ) ;
for ( V_47 = 0 ; V_47 < V_71 ; V_47 ++ ) {
if ( V_66 -> V_72 & ( 1 << V_47 ) ) {
if ( ! V_66 -> V_10 [ V_47 ] ) {
F_5 ( L_39 , V_47 , V_66 -> V_10 [ V_47 ] , V_66 -> V_72 ) ;
V_9 = 0 ;
} else if ( F_44 ( V_66 -> V_10 [ V_47 ] , V_66 ) != 0 ) {
F_9 ( L_40 , V_47 ) ;
V_9 = - 1 ;
} else {
F_5 ( L_41 , V_47 ) ;
}
}
}
F_5 ( L_42 , V_9 ) ;
return V_9 ;
}
int F_48 ( struct V_17 * V_10 ,
unsigned int V_73 , unsigned int V_74 ,
unsigned int V_75 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
F_39 ( L_43 ,
V_73 , V_74 , V_75 ) ;
V_9 = F_44 ( V_10 , V_10 -> V_66 ) ;
if ( V_9 ) {
F_9 ( L_44 ) ;
return - V_76 ;
}
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 , V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_25 -> V_35 = - 1 ;
V_29 . type = V_77 ;
V_29 . V_34 . V_78 . V_73 = V_73 ;
V_29 . V_34 . V_78 . V_74 = V_74 ;
V_29 . V_34 . V_78 . V_75 = V_75 ;
F_45 ( & V_25 -> V_37 ) ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
F_46 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_35 ) {
F_9 ( L_45 , V_48 , V_25 -> V_35 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_5 ( L_15 ) ;
return V_9 ;
}
int F_49 ( struct V_17 * V_10 )
{
F_5 ( L_4 ) ;
F_5 ( L_15 ) ;
return 0 ;
}
static int F_6 ( struct V_17 * V_10 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_29 . type = V_79 ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_5 ( L_15 ) ;
return V_9 ;
}
static int F_7 ( struct V_17 * V_10 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_29 . type = V_80 ;
V_29 . V_34 . V_81 . V_82 = V_10 -> V_82 ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_5 ( L_15 ) ;
return V_9 ;
}
int F_50 ( struct V_17 * V_10 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
F_19 ( V_10 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
V_29 . type = V_83 ;
F_45 ( & V_25 -> V_37 ) ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
F_46 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_35 ) {
F_9 ( L_46 ,
V_48 , V_25 -> V_35 ) ;
V_9 = - 1 ;
goto V_64;
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_34 ( V_25 ) ;
V_10 -> V_25 = NULL ;
F_5 ( L_15 ) ;
return V_9 ;
}
static int F_8 ( struct V_17 * V_10 ,
unsigned int V_15 , void * V_16 )
{
struct V_28 V_29 ;
struct V_24 * V_25 = V_10 -> V_25 ;
int V_26 ;
int V_9 ;
F_5 ( L_4 ) ;
F_39 ( L_47 , V_15 , V_16 ) ;
if ( F_35 ( & V_25 -> V_51 ) ) {
F_5 ( L_26 ,
V_25 -> V_46 ) ;
return - V_57 ;
}
F_36 ( V_25 -> V_30 [ 0 ] ) ;
if ( V_25 -> V_84 == 0 && F_51 ( V_25 -> V_30 [ 0 ] , & V_25 -> V_84 ) == 0 ) {
F_5 ( L_48 , V_48 , V_25 -> V_84 ) ;
}
V_29 . type = V_85 ;
V_29 . V_34 . V_86 . V_15 = V_15 ;
V_29 . V_34 . V_86 . V_87 = V_25 -> V_84 < 2 || V_88 ? 0 : 4000 ;
V_29 . V_34 . V_86 . V_39 = V_40 ;
V_29 . V_34 . V_86 . V_41 = V_42 ;
V_29 . V_34 . V_86 . V_89 = V_16 == NULL ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_26 ) {
F_9 ( L_36 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
if ( ! V_29 . V_34 . V_86 . V_89 ) {
if ( ! V_29 . V_34 . V_86 . V_87 ) {
V_26 = F_52 ( V_25 -> V_30 [ 0 ] ,
V_16 , V_15 ,
0 *
V_90
+
1 *
V_91 ,
NULL ) ;
} else {
while ( V_15 > 0 ) {
int V_92 = F_53 ( ( int ) V_29 . V_34 . V_86 . V_87 , ( int ) V_15 ) ;
V_26 = F_1 ( V_25 -> V_30 [ 0 ] ,
V_16 , V_92 ) ;
V_16 = ( char * ) V_16 + V_92 ;
V_15 -= V_92 ;
}
}
if ( V_26 ) {
F_9 ( L_49 ,
V_48 , V_26 ) ;
V_9 = - 1 ;
goto V_64;
}
}
V_9 = 0 ;
V_64:
F_32 ( V_25 -> V_30 [ 0 ] ) ;
F_37 ( & V_25 -> V_51 ) ;
F_5 ( L_15 ) ;
return V_9 ;
}
void F_54 ( struct V_17 * V_10 )
{
F_5 ( L_4 ) ;
F_5 ( L_15 ) ;
return;
}
void F_55 ( struct V_17 * V_10 )
{
F_5 ( L_4 ) ;
F_5 ( L_15 ) ;
}
unsigned int F_56 ( struct V_17 * V_10 )
{
unsigned int V_15 = F_57 ( & V_10 -> V_43 ) ;
F_58 ( V_15 , & V_10 -> V_43 ) ;
return V_15 ;
}
