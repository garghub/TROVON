static void F_1 ( unsigned int V_1 )
{
T_1 * V_2 = & V_3 [ V_1 ] ;
if ( F_2 ( & V_2 -> V_4 ) ) {
F_3 ( L_1 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
if ( ! V_2 -> V_5 ) {
F_3 ( L_2 ) ;
return;
}
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_8 = V_9 ;
F_5 ( V_2 -> V_5 ) . V_10 = V_1 + 1 ;
F_3 ( L_3 ,
V_2 -> V_6 , V_1 + 1 ) ;
F_6 ( V_11 , V_2 -> V_5 , 0 , V_1 + 1 , V_12 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_5 = NULL ;
V_2 -> V_7 = NULL ;
}
static void F_7 ( unsigned long V_13 )
{
F_3 ( L_4 ) ;
F_8 ( & V_14 ) ;
F_1 ( V_13 ) ;
F_9 ( & V_14 ) ;
}
static struct V_15 * F_10 ( unsigned int V_16 )
{
struct V_15 * V_5 ;
unsigned int V_17 ;
V_17 = F_11 ( V_16 , V_18 ) ;
V_5 = F_12 ( V_17 , V_12 ) ;
if ( ! V_5 ) {
F_3 ( L_5 , V_17 ) ;
if ( V_17 > V_16 ) {
V_5 = F_12 ( V_16 , V_12 ) ;
if ( ! V_5 )
F_3 ( L_6 , V_16 ) ;
}
}
return V_5 ;
}
static void F_13 ( unsigned int V_19 ,
const struct V_15 * V_5 ,
const struct V_20 * V_21 ,
const struct V_20 * V_22 ,
const struct V_23 * V_24 ,
const char * V_25 )
{
T_1 * V_2 ;
T_2 * V_26 ;
T_3 V_16 , V_27 ;
struct V_28 * V_29 ;
struct V_30 V_31 ;
unsigned int V_32 = F_14 ( V_24 -> V_33 ) - 1 ;
if ( V_24 -> V_34 == 0 || V_24 -> V_34 > V_5 -> V_35 )
V_27 = V_5 -> V_35 ;
else
V_27 = V_24 -> V_34 ;
V_16 = F_15 ( sizeof( * V_26 ) + V_27 ) ;
V_2 = & V_3 [ V_32 ] ;
F_8 ( & V_14 ) ;
if ( ! V_2 -> V_5 ) {
if ( ! ( V_2 -> V_5 = F_10 ( V_16 ) ) )
goto V_36;
} else if ( V_2 -> V_6 >= V_24 -> V_37 ||
V_16 > F_16 ( V_2 -> V_5 ) ) {
F_1 ( V_32 ) ;
if ( ! ( V_2 -> V_5 = F_10 ( V_16 ) ) )
goto V_36;
}
F_3 ( L_7 , V_2 -> V_6 , V_24 -> V_37 ) ;
V_29 = F_17 ( V_2 -> V_5 , 0 , V_2 -> V_6 , V_38 ,
sizeof( * V_26 ) + V_27 ) ;
V_2 -> V_6 ++ ;
V_26 = F_18 ( V_29 ) ;
if ( V_5 -> V_39 . V_40 == 0 )
F_19 ( (struct V_15 * ) V_5 ) ;
V_26 -> V_41 = V_27 ;
V_31 = F_20 ( V_5 -> V_39 ) ;
F_21 ( V_31 . V_42 , & V_26 -> V_43 ) ;
F_21 ( V_31 . V_44 , & V_26 -> V_45 ) ;
F_21 ( V_5 -> V_46 , & V_26 -> V_46 ) ;
V_26 -> V_47 = V_19 ;
if ( V_25 != NULL )
strncpy ( V_26 -> V_25 , V_25 , sizeof( V_26 -> V_25 ) ) ;
else if ( V_24 -> V_25 [ 0 ] != '\0' )
strncpy ( V_26 -> V_25 , V_24 -> V_25 , sizeof( V_26 -> V_25 ) ) ;
else
* ( V_26 -> V_25 ) = '\0' ;
if ( V_21 && V_21 -> V_48 > 0 &&
V_5 -> V_49 != V_5 -> V_50 &&
V_21 -> V_48 <= V_51 ) {
memcpy ( V_26 -> V_52 , F_22 ( V_5 ) , V_21 -> V_48 ) ;
V_26 -> V_53 = V_21 -> V_48 ;
} else
V_26 -> V_53 = 0 ;
if ( V_21 )
strncpy ( V_26 -> V_54 , V_21 -> V_55 , sizeof( V_26 -> V_54 ) ) ;
else
V_26 -> V_54 [ 0 ] = '\0' ;
if ( V_22 )
strncpy ( V_26 -> V_56 , V_22 -> V_55 , sizeof( V_26 -> V_56 ) ) ;
else
V_26 -> V_56 [ 0 ] = '\0' ;
if ( F_23 ( V_5 , 0 , V_26 -> V_57 , V_27 ) < 0 )
F_24 () ;
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_58 |= V_59 ;
V_2 -> V_7 = V_29 ;
if ( ! F_2 ( & V_2 -> V_4 ) ) {
V_2 -> V_4 . V_60 = V_61 + V_62 * V_63 / 100 ;
F_25 ( & V_2 -> V_4 ) ;
}
if ( V_2 -> V_6 >= V_24 -> V_37 ) {
if ( V_24 -> V_37 > 1 )
V_29 -> V_8 = V_9 ;
F_1 ( V_32 ) ;
}
F_9 ( & V_14 ) ;
return;
V_64:
F_3 ( L_8 ) ;
V_36:
F_3 ( L_9 ) ;
F_9 ( & V_14 ) ;
}
static unsigned int
F_26 ( struct V_15 * V_5 , const struct V_65 * V_66 )
{
F_13 ( V_66 -> V_19 , V_5 , V_66 -> V_21 , V_66 -> V_22 ,
V_66 -> V_67 , NULL ) ;
return V_68 ;
}
static void F_27 ( T_4 V_69 ,
unsigned int V_19 ,
const struct V_15 * V_5 ,
const struct V_20 * V_21 ,
const struct V_20 * V_22 ,
const struct V_70 * V_71 ,
const char * V_25 )
{
struct V_23 V_24 ;
if ( ! V_71 || V_71 -> type != V_72 ) {
V_24 . V_33 = V_73 ;
V_24 . V_34 = 0 ;
V_24 . V_37 = V_74 ;
V_24 . V_25 [ 0 ] = '\0' ;
} else {
V_24 . V_33 = V_71 -> V_75 . V_76 . V_77 ;
V_24 . V_34 = V_71 -> V_75 . V_76 . V_27 ;
V_24 . V_37 = V_71 -> V_75 . V_76 . V_37 ;
F_28 ( V_24 . V_25 , V_25 , sizeof( V_24 . V_25 ) ) ;
}
F_13 ( V_19 , V_5 , V_21 , V_22 , & V_24 , V_25 ) ;
}
static int F_29 ( const struct V_78 * V_66 )
{
const struct V_23 * V_24 = V_66 -> V_67 ;
if ( V_24 -> V_25 [ sizeof( V_24 -> V_25 ) - 1 ] != '\0' ) {
F_3 ( L_10 ) ;
return - V_79 ;
}
if ( V_24 -> V_37 > V_80 ) {
F_3 ( L_11 ,
V_24 -> V_37 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_30 ( void * V_81 , const void * V_82 )
{
const struct V_83 * V_84 = V_82 ;
struct V_23 V_85 = {
. V_33 = V_84 -> V_33 ,
. V_34 = V_84 -> V_34 ,
. V_37 = V_84 -> V_37 ,
} ;
memcpy ( V_85 . V_25 , V_84 -> V_25 , sizeof( V_85 . V_25 ) ) ;
memcpy ( V_81 , & V_85 , sizeof( V_85 ) ) ;
}
static int F_31 ( void T_5 * V_81 , const void * V_82 )
{
const struct V_23 * V_85 = V_82 ;
struct V_83 V_84 = {
. V_33 = V_85 -> V_33 ,
. V_34 = V_85 -> V_34 ,
. V_37 = V_85 -> V_37 ,
} ;
memcpy ( V_84 . V_25 , V_85 -> V_25 , sizeof( V_84 . V_25 ) ) ;
return F_32 ( V_81 , & V_84 , sizeof( V_84 ) ) ? - V_86 : 0 ;
}
static int T_6 F_33 ( void )
{
int V_87 , V_88 ;
F_3 ( L_12 ) ;
if ( V_18 > 128 * 1024 ) {
F_34 ( L_13 ) ;
return - V_79 ;
}
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ )
F_35 ( & V_3 [ V_88 ] . V_4 , F_7 , V_88 ) ;
V_11 = F_36 ( & V_90 ,
V_91 , V_89 , NULL ,
NULL , V_92 ) ;
if ( ! V_11 )
return - V_93 ;
V_87 = F_37 ( & V_94 ) ;
if ( V_87 < 0 ) {
F_38 ( V_11 ) ;
return V_87 ;
}
if ( V_95 )
F_39 ( V_96 , & V_97 ) ;
return 0 ;
}
static void T_7 F_40 ( void )
{
T_1 * V_2 ;
int V_88 ;
F_3 ( L_14 ) ;
if ( V_95 )
F_41 ( & V_97 ) ;
F_42 ( & V_94 ) ;
F_38 ( V_11 ) ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
V_2 = & V_3 [ V_88 ] ;
if ( F_2 ( & V_2 -> V_4 ) ) {
F_3 ( L_15 ) ;
F_4 ( & V_2 -> V_4 ) ;
}
if ( V_2 -> V_5 ) {
F_43 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
}
}
