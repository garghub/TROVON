static T_1 F_1 ( struct V_1 * V_2 ,
char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 ;
unsigned V_11 ;
int V_12 ;
F_2 ( & V_7 -> V_13 ) ;
V_14:
while ( F_3 ( & V_7 -> V_15 ) ) {
F_4 ( & V_7 -> V_13 ) ;
if ( V_2 -> V_16 & V_17 )
return - V_18 ;
V_12 = F_5 ( V_7 -> V_19 ,
! F_3 ( & V_7 -> V_15 ) ) ;
if ( V_12 )
return V_12 ;
F_2 ( & V_7 -> V_13 ) ;
}
V_10 = F_6 ( V_7 -> V_15 . V_20 , struct V_9 , V_21 ) ;
V_11 = 0 ;
while ( V_11 < V_4 ) {
unsigned V_22 = F_7 ( ( unsigned ) V_4 - V_11 , V_10 -> V_4 - V_10 -> V_23 ) ;
V_12 = F_8 ( V_3 + V_11 , & V_10 -> V_24 [ V_10 -> V_23 ] , V_22 ) ;
V_11 += V_22 - V_12 ;
V_10 -> V_23 += V_22 - V_12 ;
if ( V_12 != 0 ) {
if ( V_11 == 0 )
V_11 = - V_25 ;
goto V_26;
}
if ( V_10 -> V_23 == V_10 -> V_4 ) {
F_9 ( & V_10 -> V_21 ) ;
F_10 ( V_10 ) ;
if ( F_3 ( & V_7 -> V_15 ) )
break;
V_10 = F_6 ( V_7 -> V_15 . V_20 ,
struct V_9 , V_21 ) ;
}
}
if ( V_11 == 0 )
goto V_14;
V_26:
F_4 ( & V_7 -> V_13 ) ;
return V_11 ;
}
static int F_11 ( struct V_27 * V_28 , const void * V_29 , T_3 V_4 )
{
struct V_9 * V_10 ;
if ( V_4 == 0 )
return 0 ;
V_10 = F_12 ( sizeof( * V_10 ) + V_4 , V_30 ) ;
if ( V_10 == NULL )
return - V_31 ;
V_10 -> V_23 = 0 ;
V_10 -> V_4 = V_4 ;
memcpy ( V_10 -> V_24 , V_29 , V_4 ) ;
F_13 ( & V_10 -> V_21 , V_28 ) ;
return 0 ;
}
static void F_14 ( struct V_27 * V_21 )
{
struct V_9 * V_10 ;
while ( ! F_3 ( V_21 ) ) {
V_10 = F_6 ( V_21 -> V_20 , struct V_9 , V_21 ) ;
F_9 ( V_21 -> V_20 ) ;
F_10 ( V_10 ) ;
}
}
static void F_15 ( struct V_32 * V_33 )
{
F_10 ( V_33 -> V_33 . V_34 ) ;
F_10 ( V_33 -> V_35 ) ;
F_10 ( V_33 ) ;
}
static struct V_32 * F_16 ( const char * V_36 ,
const char * V_35 )
{
struct V_32 * V_33 ;
V_33 = F_17 ( sizeof( * V_33 ) , V_30 ) ;
if ( V_33 == NULL )
goto V_37;
V_33 -> V_33 . V_34 = F_18 ( V_36 , V_30 ) ;
if ( V_33 -> V_33 . V_34 == NULL )
goto V_38;
V_33 -> V_35 = F_18 ( V_35 , V_30 ) ;
if ( V_33 -> V_35 == NULL )
goto V_38;
return V_33 ;
V_38:
F_15 ( V_33 ) ;
V_37:
return NULL ;
}
static void F_19 ( struct V_39 * V_33 ,
const char * * V_40 ,
unsigned int V_4 )
{
struct V_32 * V_41 ;
struct V_42 V_43 ;
const char * V_36 , * V_35 ;
int V_44 , V_45 , V_46 , V_47 = 0 ;
int V_12 ;
F_20 ( V_48 ) ;
V_41 = F_21 ( V_33 , struct V_32 , V_33 ) ;
V_36 = V_40 [ V_49 ] ;
V_35 = V_41 -> V_35 ;
V_44 = strlen ( V_36 ) + 1 ;
V_45 = strlen ( V_35 ) + 1 ;
if ( V_4 > 2 )
V_47 = V_40 [ V_4 ] - V_40 [ 2 ] + 1 ;
V_46 = V_44 + V_45 + V_47 ;
V_43 . type = V_50 ;
V_43 . V_4 = V_46 ;
F_2 ( & V_41 -> V_51 -> V_13 ) ;
V_12 = F_11 ( & V_48 , & V_43 , sizeof( V_43 ) ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_48 , V_36 , V_44 ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_48 , V_35 , V_45 ) ;
if ( ! V_12 && V_4 > 2 )
V_12 = F_11 ( & V_48 , V_40 [ 2 ] , V_47 ) ;
if ( ! V_12 ) {
F_22 ( & V_48 , & V_41 -> V_51 -> V_15 ) ;
F_23 ( & V_41 -> V_51 -> V_19 ) ;
} else
F_14 ( & V_48 ) ;
F_4 ( & V_41 -> V_51 -> V_13 ) ;
}
static int F_24 ( unsigned V_52 ,
struct V_6 * V_7 )
{
int V_53 ;
void * V_54 ;
struct V_55 * V_56 = NULL ;
F_20 ( V_48 ) ;
if ( V_52 == V_57 ) {
V_56 = F_12 ( sizeof( * V_56 ) , V_30 ) ;
if ( ! V_56 ) {
V_53 = - V_31 ;
goto V_26;
}
}
V_54 = F_25 ( & V_7 -> V_7 . V_24 ) ;
if ( F_26 ( V_54 ) ) {
F_10 ( V_56 ) ;
V_53 = F_27 ( V_54 ) ;
goto V_26;
}
if ( V_52 == V_57 ) {
V_56 -> V_58 . V_59 = F_28 ( V_54 , NULL , 0 ) ;
F_29 ( & V_56 -> V_21 , & V_7 -> V_60 ) ;
} else if ( V_52 == V_61 ) {
F_30 (trans, &u->transactions, list)
if ( V_56 -> V_58 . V_59 == V_7 -> V_7 . V_24 . V_62 )
break;
F_31 ( & V_56 -> V_21 == & V_7 -> V_60 ) ;
F_9 ( & V_56 -> V_21 ) ;
F_10 ( V_56 ) ;
}
F_2 ( & V_7 -> V_13 ) ;
V_53 = F_11 ( & V_48 , & V_7 -> V_7 . V_24 , sizeof( V_7 -> V_7 . V_24 ) ) ;
if ( ! V_53 )
V_53 = F_11 ( & V_48 , V_54 , V_7 -> V_7 . V_24 . V_4 ) ;
if ( ! V_53 ) {
F_22 ( & V_48 , & V_7 -> V_15 ) ;
F_23 ( & V_7 -> V_19 ) ;
} else {
F_14 ( & V_48 ) ;
}
F_4 ( & V_7 -> V_13 ) ;
F_10 ( V_54 ) ;
V_26:
return V_53 ;
}
static int F_32 ( unsigned V_52 , struct V_6 * V_7 )
{
struct V_32 * V_33 , * V_63 ;
char * V_36 , * V_35 ;
int V_64 , V_53 ;
F_20 ( V_48 ) ;
V_36 = V_7 -> V_7 . V_65 + sizeof( V_7 -> V_7 . V_24 ) ;
V_35 = memchr ( V_36 , 0 , V_7 -> V_7 . V_24 . V_4 ) ;
if ( V_35 == NULL ) {
V_53 = - V_66 ;
goto V_26;
}
V_35 ++ ;
if ( memchr ( V_35 , 0 , V_7 -> V_7 . V_24 . V_4 - ( V_35 - V_36 ) ) == NULL ) {
V_53 = - V_66 ;
goto V_26;
}
if ( V_52 == V_67 ) {
V_33 = F_16 ( V_36 , V_35 ) ;
if ( V_33 == NULL ) {
V_53 = - V_31 ;
goto V_26;
}
V_33 -> V_33 . V_68 = F_19 ;
V_33 -> V_51 = V_7 ;
V_64 = F_33 ( & V_33 -> V_33 ) ;
if ( V_64 ) {
F_15 ( V_33 ) ;
V_53 = V_64 ;
goto V_26;
}
F_29 ( & V_33 -> V_21 , & V_7 -> V_69 ) ;
} else {
F_34 (watch, tmp_watch, &u->watches, list) {
if ( ! strcmp ( V_33 -> V_35 , V_35 ) &&
! strcmp ( V_33 -> V_33 . V_34 , V_36 ) ) {
F_35 ( & V_33 -> V_33 ) ;
F_9 ( & V_33 -> V_21 ) ;
F_15 ( V_33 ) ;
break;
}
}
}
{
struct {
struct V_42 V_43 ;
char V_70 [ 3 ] ;
} V_71 V_54 = {
{
. type = V_52 ,
. V_4 = sizeof( V_54 . V_70 )
} ,
L_1
} ;
F_2 ( & V_7 -> V_13 ) ;
V_53 = F_11 ( & V_7 -> V_15 , & V_54 , sizeof( V_54 ) ) ;
F_23 ( & V_7 -> V_19 ) ;
F_4 ( & V_7 -> V_13 ) ;
}
V_26:
return V_53 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_5 V_52 ;
int V_53 = V_4 ;
int V_12 ;
F_20 ( V_48 ) ;
F_2 ( & V_7 -> V_72 ) ;
if ( V_4 == 0 )
goto V_26;
if ( ( V_4 + V_7 -> V_4 ) > sizeof( V_7 -> V_7 . V_65 ) ) {
V_7 -> V_4 = 0 ;
V_53 = - V_73 ;
goto V_26;
}
V_12 = F_37 ( V_7 -> V_7 . V_65 + V_7 -> V_4 , V_3 , V_4 ) ;
if ( V_12 != 0 ) {
V_53 = - V_25 ;
goto V_26;
}
V_4 -= V_12 ;
V_53 = V_4 ;
V_7 -> V_4 += V_4 ;
if ( V_7 -> V_4 < sizeof( V_7 -> V_7 . V_24 ) )
goto V_26;
if ( ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) > sizeof( V_7 -> V_7 . V_65 ) ) {
V_53 = - V_74 ;
V_7 -> V_4 = 0 ;
goto V_26;
}
if ( V_7 -> V_4 < ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) )
goto V_26;
V_52 = V_7 -> V_7 . V_24 . type ;
switch ( V_52 ) {
case V_67 :
case V_75 :
V_12 = F_32 ( V_52 , V_7 ) ;
break;
default:
V_12 = F_24 ( V_52 , V_7 ) ;
break;
}
if ( V_12 != 0 )
V_53 = V_12 ;
V_7 -> V_4 = 0 ;
V_26:
F_4 ( & V_7 -> V_72 ) ;
return V_53 ;
}
static int F_38 ( struct V_76 * V_76 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( V_77 == 0 )
return - V_78 ;
F_39 ( V_76 , V_2 ) ;
V_7 = F_17 ( sizeof( * V_7 ) , V_30 ) ;
if ( V_7 == NULL )
return - V_31 ;
F_40 ( & V_7 -> V_60 ) ;
F_40 ( & V_7 -> V_69 ) ;
F_40 ( & V_7 -> V_15 ) ;
F_41 ( & V_7 -> V_19 ) ;
F_42 ( & V_7 -> V_13 ) ;
F_42 ( & V_7 -> V_72 ) ;
V_2 -> V_8 = V_7 ;
return 0 ;
}
static int F_43 ( struct V_76 * V_76 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_55 * V_56 , * V_79 ;
struct V_32 * V_33 , * V_63 ;
struct V_9 * V_10 , * V_80 ;
F_34 (trans, tmp, &u->transactions, list) {
F_44 ( V_56 -> V_58 , 1 ) ;
F_9 ( & V_56 -> V_21 ) ;
F_10 ( V_56 ) ;
}
F_34 (watch, tmp_watch, &u->watches, list) {
F_35 ( & V_33 -> V_33 ) ;
F_9 ( & V_33 -> V_21 ) ;
F_15 ( V_33 ) ;
}
F_34 (rb, tmp_rb, &u->read_buffers, list) {
F_9 ( & V_10 -> V_21 ) ;
F_10 ( V_10 ) ;
}
F_10 ( V_7 ) ;
return 0 ;
}
static unsigned int F_45 ( struct V_1 * V_1 , T_6 * V_81 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
F_46 ( V_1 , & V_7 -> V_19 , V_81 ) ;
if ( ! F_3 ( & V_7 -> V_15 ) )
return V_82 | V_83 ;
return 0 ;
}
static int T_7 F_47 ( void )
{
int V_64 ;
if ( ! F_48 () )
return - V_84 ;
V_64 = F_49 ( & V_85 ) ;
if ( V_64 )
F_50 ( V_86 L_2 ) ;
return V_64 ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_85 ) ;
}
