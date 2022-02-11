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
const char * V_38 ,
const char * V_37 )
{
struct V_34 * V_42 ;
struct V_43 V_44 ;
const char * V_45 ;
int V_46 , V_47 , V_48 ;
int V_12 ;
F_20 ( V_49 ) ;
V_42 = F_21 ( V_35 , struct V_34 , V_35 ) ;
V_45 = V_42 -> V_37 ;
V_46 = strlen ( V_38 ) + 1 ;
V_47 = strlen ( V_45 ) + 1 ;
V_48 = V_46 + V_47 ;
V_44 . type = V_50 ;
V_44 . V_4 = V_48 ;
F_2 ( & V_42 -> V_51 -> V_13 ) ;
V_12 = F_11 ( & V_49 , & V_44 , sizeof( V_44 ) ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_49 , V_38 , V_46 ) ;
if ( ! V_12 )
V_12 = F_11 ( & V_49 , V_45 , V_47 ) ;
if ( ! V_12 ) {
F_22 ( & V_49 , & V_42 -> V_51 -> V_15 ) ;
F_23 ( & V_42 -> V_51 -> V_19 ) ;
} else
F_14 ( & V_49 ) ;
F_4 ( & V_42 -> V_51 -> V_13 ) ;
}
static void F_24 ( struct V_52 * V_52 )
{
struct V_6 * V_7 ;
struct V_53 * V_54 , * V_55 ;
struct V_34 * V_35 , * V_56 ;
struct V_9 * V_10 , * V_57 ;
V_7 = F_21 ( V_52 , struct V_6 , V_52 ) ;
F_25 (trans, tmp, &u->transactions, list) {
F_26 ( V_54 -> V_58 , 1 ) ;
F_9 ( & V_54 -> V_21 ) ;
F_10 ( V_54 ) ;
}
F_25 (watch, tmp_watch, &u->watches, list) {
F_27 ( & V_35 -> V_35 ) ;
F_9 ( & V_35 -> V_21 ) ;
F_15 ( V_35 ) ;
}
F_25 (rb, tmp_rb, &u->read_buffers, list) {
F_9 ( & V_10 -> V_21 ) ;
F_10 ( V_10 ) ;
}
F_10 ( V_7 ) ;
}
static struct V_53 * F_28 (
struct V_6 * V_7 , T_5 V_59 )
{
struct V_53 * V_54 ;
F_29 (trans, &u->transactions, list)
if ( V_54 -> V_58 . V_60 == V_59 )
return V_54 ;
return NULL ;
}
void F_30 ( struct V_61 * V_62 )
{
struct V_6 * V_7 = V_62 -> V_63 ;
struct V_53 * V_54 = NULL ;
int V_64 ;
F_20 ( V_49 ) ;
F_31 ( V_62 ) ;
F_2 ( & V_7 -> V_65 ) ;
if ( V_62 -> type == V_66 ) {
V_54 = F_28 ( V_7 , 0 ) ;
if ( F_32 ( ! V_54 ) )
goto V_26;
if ( V_62 -> V_24 . type == V_67 ) {
F_9 ( & V_54 -> V_21 ) ;
F_10 ( V_54 ) ;
} else {
V_64 = F_33 ( V_62 -> V_68 , 10 , & V_54 -> V_58 . V_60 ) ;
if ( F_32 ( V_64 ) )
goto V_26;
}
} else if ( V_62 -> V_24 . type == V_69 ) {
V_54 = F_28 ( V_7 , V_62 -> V_24 . V_59 ) ;
if ( F_32 ( ! V_54 ) )
goto V_26;
F_9 ( & V_54 -> V_21 ) ;
F_10 ( V_54 ) ;
}
F_4 ( & V_7 -> V_65 ) ;
F_2 ( & V_7 -> V_13 ) ;
V_64 = F_11 ( & V_49 , & V_62 -> V_24 , sizeof( V_62 -> V_24 ) ) ;
if ( ! V_64 )
V_64 = F_11 ( & V_49 , V_62 -> V_68 , V_62 -> V_24 . V_4 ) ;
if ( ! V_64 ) {
F_22 ( & V_49 , & V_7 -> V_15 ) ;
F_23 ( & V_7 -> V_19 ) ;
} else {
F_14 ( & V_49 ) ;
}
F_4 ( & V_7 -> V_13 ) ;
F_10 ( V_62 -> V_68 ) ;
F_10 ( V_62 ) ;
F_34 ( & V_7 -> V_52 , F_24 ) ;
return;
V_26:
F_4 ( & V_7 -> V_65 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
unsigned int V_70 , const char * V_71 )
{
struct {
struct V_43 V_44 ;
const char V_68 [ 16 ] ;
} V_24 ;
int V_64 ;
V_24 . V_44 = V_7 -> V_7 . V_24 ;
V_24 . V_44 . type = V_70 ;
V_24 . V_44 . V_4 = strlen ( V_71 ) + 1 ;
if ( V_24 . V_44 . V_4 > sizeof( V_24 . V_68 ) )
return - V_72 ;
F_2 ( & V_7 -> V_13 ) ;
V_64 = F_11 ( & V_7 -> V_15 , & V_24 , sizeof( V_24 . V_44 ) + V_24 . V_44 . V_4 ) ;
F_23 ( & V_7 -> V_19 ) ;
F_4 ( & V_7 -> V_13 ) ;
if ( ! V_64 )
F_34 ( & V_7 -> V_52 , F_24 ) ;
return V_64 ;
}
static int F_36 ( unsigned V_70 ,
struct V_6 * V_7 )
{
int V_64 ;
struct V_53 * V_54 = NULL ;
if ( V_70 == V_66 ) {
V_54 = F_17 ( sizeof( * V_54 ) , V_32 ) ;
if ( ! V_54 ) {
V_64 = - V_33 ;
goto V_26;
}
F_37 ( & V_54 -> V_21 , & V_7 -> V_73 ) ;
} else if ( V_7 -> V_7 . V_24 . V_59 != 0 &&
! F_28 ( V_7 , V_7 -> V_7 . V_24 . V_59 ) )
return F_35 ( V_7 , V_67 , L_1 ) ;
V_64 = F_38 ( & V_7 -> V_7 . V_24 , V_7 ) ;
if ( V_64 && V_54 ) {
F_9 ( & V_54 -> V_21 ) ;
F_10 ( V_54 ) ;
}
V_26:
return V_64 ;
}
static int F_39 ( unsigned V_70 , struct V_6 * V_7 )
{
struct V_34 * V_35 ;
char * V_38 , * V_37 ;
int V_74 , V_64 ;
F_20 ( V_49 ) ;
V_38 = V_7 -> V_7 . V_75 + sizeof( V_7 -> V_7 . V_24 ) ;
V_37 = memchr ( V_38 , 0 , V_7 -> V_7 . V_24 . V_4 ) ;
if ( V_37 == NULL ) {
V_64 = F_35 ( V_7 , V_67 , L_2 ) ;
goto V_26;
}
V_37 ++ ;
if ( memchr ( V_37 , 0 , V_7 -> V_7 . V_24 . V_4 - ( V_37 - V_38 ) ) == NULL ) {
V_64 = F_35 ( V_7 , V_67 , L_2 ) ;
goto V_26;
}
if ( V_70 == V_76 ) {
V_35 = F_16 ( V_38 , V_37 ) ;
if ( V_35 == NULL ) {
V_64 = - V_33 ;
goto V_26;
}
V_35 -> V_35 . V_77 = F_19 ;
V_35 -> V_51 = V_7 ;
V_74 = F_40 ( & V_35 -> V_35 ) ;
if ( V_74 ) {
F_15 ( V_35 ) ;
V_64 = V_74 ;
goto V_26;
}
F_37 ( & V_35 -> V_21 , & V_7 -> V_78 ) ;
} else {
F_29 (watch, &u->watches, list) {
if ( ! strcmp ( V_35 -> V_37 , V_37 ) &&
! strcmp ( V_35 -> V_35 . V_36 , V_38 ) ) {
F_27 ( & V_35 -> V_35 ) ;
F_9 ( & V_35 -> V_21 ) ;
F_15 ( V_35 ) ;
break;
}
}
}
V_64 = F_35 ( V_7 , V_70 , L_3 ) ;
V_26:
return V_64 ;
}
static T_1 F_41 ( struct V_1 * V_2 ,
const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_5 V_70 ;
int V_64 = V_4 ;
int V_12 ;
F_20 ( V_49 ) ;
F_2 ( & V_7 -> V_65 ) ;
if ( V_4 == 0 )
goto V_26;
if ( V_4 > sizeof( V_7 -> V_7 . V_75 ) - V_7 -> V_4 ) {
V_7 -> V_4 = 0 ;
V_64 = - V_31 ;
goto V_26;
}
V_12 = F_42 ( V_7 -> V_7 . V_75 + V_7 -> V_4 , V_3 , V_4 ) ;
if ( V_12 != 0 ) {
V_64 = - V_25 ;
goto V_26;
}
V_4 -= V_12 ;
V_64 = V_4 ;
V_7 -> V_4 += V_4 ;
if ( V_7 -> V_4 < sizeof( V_7 -> V_7 . V_24 ) )
goto V_26;
if ( ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) > sizeof( V_7 -> V_7 . V_75 ) ) {
V_64 = - V_72 ;
V_7 -> V_4 = 0 ;
goto V_26;
}
if ( V_7 -> V_4 < ( sizeof( V_7 -> V_7 . V_24 ) + V_7 -> V_7 . V_24 . V_4 ) )
goto V_26;
F_43 ( & V_7 -> V_52 ) ;
V_70 = V_7 -> V_7 . V_24 . type ;
switch ( V_70 ) {
case V_76 :
case V_79 :
V_12 = F_39 ( V_70 , V_7 ) ;
break;
default:
V_12 = F_36 ( V_70 , V_7 ) ;
break;
}
if ( V_12 != 0 ) {
V_64 = V_12 ;
F_34 ( & V_7 -> V_52 , F_24 ) ;
}
V_7 -> V_4 = 0 ;
V_26:
F_4 ( & V_7 -> V_65 ) ;
return V_64 ;
}
static int F_44 ( struct V_80 * V_80 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
if ( V_81 == 0 )
return - V_82 ;
F_45 ( V_80 , V_2 ) ;
V_2 -> V_83 &= ~ V_84 ;
V_7 = F_17 ( sizeof( * V_7 ) , V_32 ) ;
if ( V_7 == NULL )
return - V_33 ;
F_46 ( & V_7 -> V_52 ) ;
F_47 ( & V_7 -> V_73 ) ;
F_47 ( & V_7 -> V_78 ) ;
F_47 ( & V_7 -> V_15 ) ;
F_48 ( & V_7 -> V_19 ) ;
F_49 ( & V_7 -> V_13 ) ;
F_49 ( & V_7 -> V_65 ) ;
V_2 -> V_8 = V_7 ;
return 0 ;
}
static int F_50 ( struct V_80 * V_80 , struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_34 ( & V_7 -> V_52 , F_24 ) ;
return 0 ;
}
static unsigned int F_51 ( struct V_1 * V_1 , T_6 * V_85 )
{
struct V_6 * V_7 = V_1 -> V_8 ;
F_52 ( V_1 , & V_7 -> V_19 , V_85 ) ;
if ( ! F_3 ( & V_7 -> V_15 ) )
return V_86 | V_87 ;
return 0 ;
}
static int T_7 F_53 ( void )
{
int V_74 ;
if ( ! F_54 () )
return - V_88 ;
V_74 = F_55 ( & V_89 ) ;
if ( V_74 )
F_56 ( L_4 ) ;
return V_74 ;
}
