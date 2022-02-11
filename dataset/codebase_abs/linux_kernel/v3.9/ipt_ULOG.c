static void F_1 ( unsigned int V_1 )
{
T_1 * V_2 = & V_3 [ V_1 ] ;
F_2 ( L_1 ) ;
F_3 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_5 ) {
F_2 ( L_2 ) ;
return;
}
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_8 = V_9 ;
F_4 ( V_2 -> V_5 ) . V_10 = V_1 + 1 ;
F_2 ( L_3 ,
V_2 -> V_6 , V_1 + 1 ) ;
F_5 ( V_11 , V_2 -> V_5 , 0 , V_1 + 1 , V_12 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_5 = NULL ;
V_2 -> V_7 = NULL ;
}
static void F_6 ( unsigned long V_13 )
{
F_2 ( L_4 ) ;
F_7 ( & V_14 ) ;
F_1 ( V_13 ) ;
F_8 ( & V_14 ) ;
}
static struct V_15 * F_9 ( unsigned int V_16 )
{
struct V_15 * V_5 ;
unsigned int V_17 ;
V_17 = F_10 ( V_16 , V_18 ) ;
V_5 = F_11 ( V_17 , V_12 | V_19 ) ;
if ( ! V_5 ) {
if ( V_17 > V_16 ) {
V_5 = F_11 ( V_16 , V_12 ) ;
if ( ! V_5 )
F_2 ( L_5 , V_16 ) ;
}
}
return V_5 ;
}
static void F_12 ( unsigned int V_20 ,
const struct V_15 * V_5 ,
const struct V_21 * V_22 ,
const struct V_21 * V_23 ,
const struct V_24 * V_25 ,
const char * V_26 )
{
T_1 * V_2 ;
T_2 * V_27 ;
T_3 V_16 , V_28 ;
struct V_29 * V_30 ;
struct V_31 V_32 ;
unsigned int V_33 = F_13 ( V_25 -> V_34 ) - 1 ;
if ( V_25 -> V_35 == 0 || V_25 -> V_35 > V_5 -> V_36 )
V_28 = V_5 -> V_36 ;
else
V_28 = V_25 -> V_35 ;
V_16 = F_14 ( sizeof( * V_27 ) + V_28 ) ;
V_2 = & V_3 [ V_33 ] ;
F_7 ( & V_14 ) ;
if ( ! V_2 -> V_5 ) {
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_37;
} else if ( V_2 -> V_6 >= V_25 -> V_38 ||
V_16 > F_15 ( V_2 -> V_5 ) ) {
F_1 ( V_33 ) ;
if ( ! ( V_2 -> V_5 = F_9 ( V_16 ) ) )
goto V_37;
}
F_2 ( L_6 , V_2 -> V_6 , V_25 -> V_38 ) ;
V_30 = F_16 ( V_2 -> V_5 , 0 , V_2 -> V_6 , V_39 ,
sizeof( * V_27 ) + V_28 , 0 ) ;
if ( ! V_30 ) {
F_2 ( L_7 ) ;
goto V_40;
}
V_2 -> V_6 ++ ;
V_27 = F_17 ( V_30 ) ;
if ( V_5 -> V_41 . V_42 == 0 )
F_18 ( (struct V_15 * ) V_5 ) ;
V_27 -> V_43 = V_28 ;
V_32 = F_19 ( V_5 -> V_41 ) ;
F_20 ( V_32 . V_44 , & V_27 -> V_45 ) ;
F_20 ( V_32 . V_46 , & V_27 -> V_47 ) ;
F_20 ( V_5 -> V_48 , & V_27 -> V_48 ) ;
V_27 -> V_49 = V_20 ;
if ( V_26 != NULL )
strncpy ( V_27 -> V_26 , V_26 , sizeof( V_27 -> V_26 ) ) ;
else if ( V_25 -> V_26 [ 0 ] != '\0' )
strncpy ( V_27 -> V_26 , V_25 -> V_26 , sizeof( V_27 -> V_26 ) ) ;
else
* ( V_27 -> V_26 ) = '\0' ;
if ( V_22 && V_22 -> V_50 > 0 &&
V_5 -> V_51 != V_5 -> V_52 &&
V_22 -> V_50 <= V_53 ) {
memcpy ( V_27 -> V_54 , F_21 ( V_5 ) , V_22 -> V_50 ) ;
V_27 -> V_55 = V_22 -> V_50 ;
} else
V_27 -> V_55 = 0 ;
if ( V_22 )
strncpy ( V_27 -> V_56 , V_22 -> V_57 , sizeof( V_27 -> V_56 ) ) ;
else
V_27 -> V_56 [ 0 ] = '\0' ;
if ( V_23 )
strncpy ( V_27 -> V_58 , V_23 -> V_57 , sizeof( V_27 -> V_58 ) ) ;
else
V_27 -> V_58 [ 0 ] = '\0' ;
if ( F_22 ( V_5 , 0 , V_27 -> V_59 , V_28 ) < 0 )
F_23 () ;
if ( V_2 -> V_6 > 1 )
V_2 -> V_7 -> V_60 |= V_61 ;
V_2 -> V_7 = V_30 ;
if ( ! F_24 ( & V_2 -> V_4 ) ) {
V_2 -> V_4 . V_62 = V_63 + V_64 * V_65 / 100 ;
F_25 ( & V_2 -> V_4 ) ;
}
if ( V_2 -> V_6 >= V_25 -> V_38 ) {
if ( V_25 -> V_38 > 1 )
V_30 -> V_8 = V_9 ;
F_1 ( V_33 ) ;
}
V_40:
F_8 ( & V_14 ) ;
return;
V_37:
F_2 ( L_8 ) ;
F_8 ( & V_14 ) ;
}
static unsigned int
F_26 ( struct V_15 * V_5 , const struct V_66 * V_67 )
{
F_12 ( V_67 -> V_20 , V_5 , V_67 -> V_22 , V_67 -> V_23 ,
V_67 -> V_68 , NULL ) ;
return V_69 ;
}
static void F_27 ( T_4 V_70 ,
unsigned int V_20 ,
const struct V_15 * V_5 ,
const struct V_21 * V_22 ,
const struct V_21 * V_23 ,
const struct V_71 * V_72 ,
const char * V_26 )
{
struct V_24 V_25 ;
if ( ! V_72 || V_72 -> type != V_73 ) {
V_25 . V_34 = V_74 ;
V_25 . V_35 = 0 ;
V_25 . V_38 = V_75 ;
V_25 . V_26 [ 0 ] = '\0' ;
} else {
V_25 . V_34 = V_72 -> V_76 . V_77 . V_78 ;
V_25 . V_35 = V_72 -> V_76 . V_77 . V_28 ;
V_25 . V_38 = V_72 -> V_76 . V_77 . V_38 ;
F_28 ( V_25 . V_26 , V_26 , sizeof( V_25 . V_26 ) ) ;
}
F_12 ( V_20 , V_5 , V_22 , V_23 , & V_25 , V_26 ) ;
}
static int F_29 ( const struct V_79 * V_67 )
{
const struct V_24 * V_25 = V_67 -> V_68 ;
if ( V_25 -> V_26 [ sizeof( V_25 -> V_26 ) - 1 ] != '\0' ) {
F_2 ( L_9 ) ;
return - V_80 ;
}
if ( V_25 -> V_38 > V_81 ) {
F_2 ( L_10 ,
V_25 -> V_38 ) ;
return - V_80 ;
}
return 0 ;
}
static void F_30 ( void * V_82 , const void * V_83 )
{
const struct V_84 * V_85 = V_83 ;
struct V_24 V_86 = {
. V_34 = V_85 -> V_34 ,
. V_35 = V_85 -> V_35 ,
. V_38 = V_85 -> V_38 ,
} ;
memcpy ( V_86 . V_26 , V_85 -> V_26 , sizeof( V_86 . V_26 ) ) ;
memcpy ( V_82 , & V_86 , sizeof( V_86 ) ) ;
}
static int F_31 ( void T_5 * V_82 , const void * V_83 )
{
const struct V_24 * V_86 = V_83 ;
struct V_84 V_85 = {
. V_34 = V_86 -> V_34 ,
. V_35 = V_86 -> V_35 ,
. V_38 = V_86 -> V_38 ,
} ;
memcpy ( V_85 . V_26 , V_86 -> V_26 , sizeof( V_85 . V_26 ) ) ;
return F_32 ( V_82 , & V_85 , sizeof( V_85 ) ) ? - V_87 : 0 ;
}
static int T_6 F_33 ( void )
{
int V_88 , V_89 ;
struct V_90 V_91 = {
. V_92 = V_93 ,
} ;
F_2 ( L_11 ) ;
if ( V_18 > 128 * 1024 ) {
F_34 ( L_12 ) ;
return - V_80 ;
}
for ( V_89 = 0 ; V_89 < V_93 ; V_89 ++ )
F_35 ( & V_3 [ V_89 ] . V_4 , F_6 , V_89 ) ;
V_11 = F_36 ( & V_94 , V_95 , & V_91 ) ;
if ( ! V_11 )
return - V_96 ;
V_88 = F_37 ( & V_97 ) ;
if ( V_88 < 0 ) {
F_38 ( V_11 ) ;
return V_88 ;
}
if ( V_98 )
F_39 ( V_99 , & V_100 ) ;
return 0 ;
}
static void T_7 F_40 ( void )
{
T_1 * V_2 ;
int V_89 ;
F_2 ( L_13 ) ;
if ( V_98 )
F_41 ( & V_100 ) ;
F_42 ( & V_97 ) ;
F_38 ( V_11 ) ;
for ( V_89 = 0 ; V_89 < V_93 ; V_89 ++ ) {
V_2 = & V_3 [ V_89 ] ;
F_2 ( L_14 ) ;
F_3 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_5 ) {
F_43 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
}
}
