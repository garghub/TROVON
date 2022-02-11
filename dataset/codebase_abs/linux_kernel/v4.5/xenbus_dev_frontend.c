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
if ( V_4 > V_30 )
return - V_31 ;
V_10 = F_12 ( sizeof( * V_10 ) + V_4 , V_32 ) ;
if ( V_10 == NULL )
return - V_33 ;
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
static void F_15 ( struct V_34 * V_35 )
{
F_10 ( V_35 -> V_35 . V_36 ) ;
F_10 ( V_35 -> V_37 ) ;
F_10 ( V_35 ) ;
}
static struct V_34 * F_16 ( const char * V_38 ,
const char * V_37 )
{
struct V_34 * V_35 ;
V_35 = F_17 ( sizeof( * V_35 ) , V_32 ) ;
if ( V_35 == NULL )
goto V_39;
V_35 -> V_35 . V_36 = F_18 ( V_38 , V_32 ) ;
if ( V_35 -> V_35 . V_36 == NULL )
goto V_40;
V_35 -> V_37 = F_18 ( V_37 , V_32 ) ;
if ( V_35 -> V_37 == NULL )
goto V_40;
return V_35 ;
V_40:
F_15 ( V_35 ) ;
V_39:
return NULL ;
}
static void F_19 ( struct V_41 * V_35 ,
const char * * V_42 ,
unsigned int V_4 )
{
struct V_34 * V_43 ;
struct V_44 V_45 ;
const char * V_38 , * V_37 ;
int V_46 , V_47 , V_48 , V_49 = 0 ;
int V_12 ;
F_20 ( V_50 ) ;
V_43 = F_21 ( V_35 , struct V_34 , V_35 ) ;
V_38 = V_42 [ V_51 ] ;
V_37 = V_43 -> V_37 ;
V_46 = strlen ( V_38 ) + 1 ;
V_47 = strlen ( V_37 ) + 1 ;
if ( V_4 > 2 )
V_49 = V_42 [ V_4 ] - V_42 [ 2 ] + 1 ;
V_48 = V_46 + V_47 + V_49 ;
V_45 . type = V_52 ;
V_45 . V_4 = V_48 ;
F_2 ( & V_43 -> V_53 -> V_13 ) ;
V_12 = F_11 ( & V_50 , & V_45 , sizeof( V_45 ) ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_50 , V_38 , V_46 ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_50 , V_37 , V_47 ) ;
if ( ! V_12 && V_4 > 2 )
V_12 = F_11 ( & V_50 , V_42 [ 2 ] , V_49 ) ;
if ( ! V_12 ) {
F_22 ( & V_50 , & V_43 -> V_53 -> V_15 ) ;
F_23 ( & V_43 -> V_53 -> V_19 ) ;
} else
F_14 ( & V_50 ) ;
F_4 ( & V_43 -> V_53 -> V_13 ) ;
}
static int F_24 ( unsigned V_54 ,
struct V_6 * V_7 )
{
int V_55 ;
void * V_56 ;
struct V_57 * V_58 = NULL ;
F_20 ( V_50 ) ;
if ( V_54 == V_59 ) {
V_58 = F_12 ( sizeof( * V_58 ) , V_32 ) ;
if ( ! V_58 ) {
V_55 = - V_33 ;
goto V_26;
}
}
V_56 = F_25 ( & V_7 -> V_7 . V_24 ) ;
if ( F_26 ( V_56 ) ) {
F_10 ( V_58 ) ;
V_55 = F_27 ( V_56 ) ;
goto V_26;
}
if ( V_54 == V_59 ) {
if ( V_7 -> V_7 . V_24 . type == V_60 )
F_10 ( V_58 ) ;
else {
V_58 -> V_61 . V_62 = F_28 ( V_56 , NULL , 0 ) ;
F_29 ( & V_58 -> V_21 , & V_7 -> V_63 ) ;
}
} else if ( V_7 -> V_7 . V_24 . type == V_64 ) {
F_30 (trans, &u->transactions, list)
if ( V_58 -> V_61 . V_62 == V_7 -> V_7 . V_24 . V_65 )
break;
F_31 ( & V_58 -> V_21 == & V_7 -> V_63 ) ;
F_9 ( & V_58 -> V_21 ) ;
F_10 ( V_58 ) ;
}
F_2 ( & V_7 -> V_13 ) ;
V_55 = F_11 ( & V_50 , & V_7 -> V_7 . V_24 , sizeof( V_7 -> V_7 . V_24 ) ) ;
if ( ! V_55 )
V_55 = F_11 ( & V_50 , V_56 , V_7 -> V_7 . V_24 . V_4 ) ;
if ( ! V_55 ) {
F_22 ( & V_50 , & V_7 -> V_15 ) ;
F_23 ( & V_7 -> V_19 ) ;
} else {
F_14 ( & V_50 ) ;
}
F_4 ( & V_7 -> V_13 ) ;
F_10 ( V_56 ) ;
V_26:
return V_55 ;
}
static int F_32 ( unsigned V_54 , struct V_6 * V_7 )
{
struct V_34 * V_35 , * V_66 ;
char * V_38 , * V_37 ;
int V_67 , V_55 ;
F_20 ( V_50 ) ;
V_38 = V_7 -> V_7 . V_68 + sizeof( V_7 -> V_7 . V_24 ) ;
V_37 = memchr ( V_38 , 0 , V_7 -> V_7 . V_24 . V_4 ) ;
if ( V_37 == NULL ) {
V_55 = - V_69 ;
goto V_26;
}
V_37 ++ ;
if ( memchr ( V_37 , 0 , V_7 -> V_7 . V_24 . V_4 - ( V_37 - V_38 ) ) == NULL ) {
V_55 = - V_69 ;
goto V_26;
}
if ( V_54 == V_70 ) {
V_35 = F_16 ( V_38 , V_37 ) ;
if ( V_35 == NULL ) {
V_55 = - V_33 ;
goto V_26;
}
V_35 -> V_35 . V_71 = F_19 ;
V_35 -> V_53 = V_7 ;
V_67 = F_33 ( & V_35 -> V_35 ) ;
if ( V_67 ) {
F_15 ( V_35 ) ;
V_55 = V_67 ;
goto V_26;
}
F_29 ( & V_35 -> V_21 , & V_7 -> V_72 ) ;
} else {
F_34 (watch, tmp_watch, &u->watches, list) {
if ( ! strcmp ( V_35 -> V_37 , V_37 ) &&
! strcmp ( V_35 -> V_35 . V_36 , V_38 ) ) {
F_35 ( & V_35 -> V_35 ) ;
F_9 ( & V_35 -> V_21 ) ;
F_15 ( V_35 ) ;
break;
}
}
}
{
struct {
struct V_44 V_45 ;
char V_73 [ 3 ] ;
} V_74 V_56 = {
{
. type = V_54 ,
. V_4 = sizeof( V_56 . V_73 )
} ,
L_1
} ;
F_2 ( & V_7 -> V_13 ) ;
V_55 = F_11 ( & V_7 -> V_15 , & V_56 , sizeof( V_56 ) ) ;
F_23 ( & V_7 -> V_19 ) ;
F_4 ( & V_7 -> V_13 ) ;
}
V_26:
return V_55 ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_5 V_54 ;
int V_55 = V_4 ;
int V_12 ;
F_20 ( V_50 ) ;
F_2 ( & V_7 -> V_75 ) ;
if ( V_4 == 0 )
goto V_26;
if ( V_4 > sizeof( V_7 -> V_7 . V_68 ) - V_7 -> V_4 ) {
V_7 -> V_4 = 0 ;
V_55 = - V_31 ;
goto V_26;
}
V_12 = F_37 ( V_7 -> V_7 . V_68 + V_7 -> V_4 , V_3 , V_4 ) ;
if ( V_12 != 0 ) {
V_55 = - V_25 ;
goto V_26;
}
V_4 -= V_12 ;
V_55 = V_4 ;
V_7 -> V_4 += V_4 ;
if ( V_7 -> V_4 < sizeof( V_7 -> V_7 . V_24 ) )
goto V_26;
if ( ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) > sizeof( V_7 -> V_7 . V_68 ) ) {
V_55 = - V_76 ;
V_7 -> V_4 = 0 ;
goto V_26;
}
if ( V_7 -> V_4 < ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) )
goto V_26;
V_54 = V_7 -> V_7 . V_24 . type ;
switch ( V_54 ) {
case V_70 :
case V_77 :
V_12 = F_32 ( V_54 , V_7 ) ;
break;
default:
V_12 = F_24 ( V_54 , V_7 ) ;
break;
}
if ( V_12 != 0 )
V_55 = V_12 ;
V_7 -> V_4 = 0 ;
V_26:
F_4 ( & V_7 -> V_75 ) ;
return V_55 ;
}
static int F_38 ( struct V_78 * V_78 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( V_79 == 0 )
return - V_80 ;
F_39 ( V_78 , V_2 ) ;
V_7 = F_17 ( sizeof( * V_7 ) , V_32 ) ;
if ( V_7 == NULL )
return - V_33 ;
F_40 ( & V_7 -> V_63 ) ;
F_40 ( & V_7 -> V_72 ) ;
F_40 ( & V_7 -> V_15 ) ;
F_41 ( & V_7 -> V_19 ) ;
F_42 ( & V_7 -> V_13 ) ;
F_42 ( & V_7 -> V_75 ) ;
V_2 -> V_8 = V_7 ;
return 0 ;
}
static int F_43 ( struct V_78 * V_78 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_57 * V_58 , * V_81 ;
struct V_34 * V_35 , * V_66 ;
struct V_9 * V_10 , * V_82 ;
F_34 (trans, tmp, &u->transactions, list) {
F_44 ( V_58 -> V_61 , 1 ) ;
F_9 ( & V_58 -> V_21 ) ;
F_10 ( V_58 ) ;
}
F_34 (watch, tmp_watch, &u->watches, list) {
F_35 ( & V_35 -> V_35 ) ;
F_9 ( & V_35 -> V_21 ) ;
F_15 ( V_35 ) ;
}
F_34 (rb, tmp_rb, &u->read_buffers, list) {
F_9 ( & V_10 -> V_21 ) ;
F_10 ( V_10 ) ;
}
F_10 ( V_7 ) ;
return 0 ;
}
static unsigned int F_45 ( struct V_1 * V_1 , T_6 * V_83 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
F_46 ( V_1 , & V_7 -> V_19 , V_83 ) ;
if ( ! F_3 ( & V_7 -> V_15 ) )
return V_84 | V_85 ;
return 0 ;
}
static int T_7 F_47 ( void )
{
int V_67 ;
if ( ! F_48 () )
return - V_86 ;
V_67 = F_49 ( & V_87 ) ;
if ( V_67 )
F_50 ( L_2 ) ;
return V_67 ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_87 ) ;
}
