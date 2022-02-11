static int F_1 ( const struct V_1 * V_2 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
if ( V_2 -> type != type )
return V_2 -> type - type ;
if ( V_2 -> V_5 != V_4 )
return V_2 -> V_5 - V_4 ;
return memcmp ( V_2 -> V_3 , V_3 , V_4 ) ;
}
static struct V_1 * F_2 ( const struct V_6 * V_7 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_8 * V_9 = V_7 -> V_10 . V_8 ;
struct V_1 * V_2 ;
int V_11 ;
while ( V_9 ) {
V_2 = F_3 ( V_9 , struct V_1 , V_12 ) ;
V_11 = F_1 ( V_2 , V_3 , V_4 , type ) ;
if ( V_11 > 0 )
V_9 = V_9 -> V_13 ;
else if ( V_11 < 0 )
V_9 = V_9 -> V_14 ;
else
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_4 ( struct V_6 * V_7 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_8 * V_9 = NULL , * * V_15 = & V_7 -> V_10 . V_8 ;
struct V_1 * V_2 ;
int V_11 ;
while ( * V_15 ) {
V_9 = * V_15 ;
V_2 = F_3 ( V_9 , struct V_1 , V_12 ) ;
V_11 = F_1 ( V_2 , V_3 , V_4 , type ) ;
if ( V_11 > 0 )
V_15 = & V_9 -> V_13 ;
else if ( V_11 < 0 )
V_15 = & V_9 -> V_14 ;
else {
return V_2 ;
}
}
V_2 = F_5 ( sizeof( * V_2 ) + V_4 , V_16 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_17 = V_18 ;
V_2 -> type = type ;
V_2 -> V_5 = V_4 ;
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
F_6 ( & V_2 -> V_12 , V_9 , V_15 ) ;
F_7 ( & V_2 -> V_12 , & V_7 -> V_10 ) ;
return V_2 ;
}
static void F_8 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_12 , & V_7 -> V_10 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
#define F_12 sizeof(struct llc_pdu_un)
V_20 = F_13 ( V_7 -> V_23 -> V_24 + F_14 ( V_7 -> V_23 ) ,
V_16 ) ;
if ( ! V_20 )
return - V_25 ;
V_20 -> V_23 = V_7 -> V_23 ;
V_20 -> V_26 = F_15 ( V_27 ) ;
F_16 ( V_20 , F_14 ( V_7 -> V_23 ) + F_12 ) ;
V_22 = (struct V_21 * ) F_17 ( V_20 , sizeof( * V_22 ) ) ;
F_18 ( F_15 ( V_28 ) , & V_22 -> V_26 ) ;
V_7 -> V_29 = V_20 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 )
{
if ( F_20 ( V_7 -> V_29 ) < sizeof( T_1 ) )
return - 1 ;
* ( T_1 * ) F_17 ( V_7 -> V_29 , sizeof( T_1 ) ) = V_30 ;
return 0 ;
}
static void F_21 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_29 )
return;
F_19 ( V_7 ) ;
F_19 ( V_7 ) ;
F_22 ( V_7 -> V_29 , V_31 , V_32 ,
V_32 , V_33 ) ;
F_23 ( V_7 -> V_29 ) ;
F_24 ( V_7 -> V_29 , V_7 -> V_23 -> V_34 ,
V_7 -> V_7 -> V_35 . V_36 ) ;
F_25 ( & V_7 -> V_37 , V_7 -> V_29 ) ;
V_7 -> V_29 = NULL ;
}
static void F_26 ( struct V_6 * V_7 )
{
struct V_19 * V_20 ;
while ( ( V_20 = F_27 ( & V_7 -> V_37 ) ) )
F_28 ( V_20 ) ;
}
static int F_29 ( struct V_6 * V_7 , T_1 V_38 )
{
struct V_39 * V_40 ;
if ( F_20 ( V_7 -> V_29 ) < sizeof( * V_40 ) )
return - 1 ;
V_40 = (struct V_39 * ) F_17 ( V_7 -> V_29 , sizeof( * V_40 ) ) ;
V_40 -> V_38 = V_38 ;
F_30 ( V_7 -> V_29 ) -> V_41 = V_38 ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 ,
const struct V_1 * V_2 ,
enum V_42 V_43 )
{
struct V_44 * V_45 ;
unsigned int V_4 ;
int V_46 ;
V_47:
if ( ! V_7 -> V_29 ) {
V_46 = F_11 ( V_7 ) ;
if ( V_46 < 0 )
return V_46 ;
}
if ( F_30 ( V_7 -> V_29 ) -> V_41 != V_2 -> type ) {
if ( F_30 ( V_7 -> V_29 ) -> V_41 &&
F_19 ( V_7 ) < 0 )
goto V_37;
if ( F_29 ( V_7 , V_2 -> type ) < 0 )
goto V_37;
}
V_4 = sizeof( * V_45 ) + V_2 -> V_5 ;
if ( F_20 ( V_7 -> V_29 ) < V_4 )
goto V_37;
V_45 = (struct V_44 * ) F_17 ( V_7 -> V_29 , V_4 ) ;
V_45 -> V_4 = V_4 ;
V_45 -> V_43 = V_43 ;
memcpy ( V_45 -> V_3 , V_2 -> V_3 , V_2 -> V_5 ) ;
return 0 ;
V_37:
F_21 ( V_7 ) ;
goto V_47;
}
static void V_42 ( struct V_6 * V_7 ,
struct V_1 * V_2 , enum V_48 V_43 )
{
enum V_49 V_17 ;
V_17 = V_50 [ V_2 -> V_17 ] [ V_43 ] . V_17 ;
if ( V_17 == V_51 )
return;
switch ( V_50 [ V_2 -> V_17 ] [ V_43 ] . V_52 ) {
case V_53 :
break;
case V_54 :
if ( F_31 ( V_7 , V_2 , V_55 ) < 0 )
return;
break;
case V_56 :
F_31 ( V_7 , V_2 , V_57 ) ;
F_8 ( V_7 , V_2 ) ;
return;
default:
F_32 ( 1 ) ;
}
V_2 -> V_17 = V_17 ;
}
int F_33 ( const struct V_58 * V_23 ,
const struct V_59 * V_60 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_61 * V_62 = F_34 ( V_23 -> V_61 ) ;
struct V_6 * V_7 = F_34 ( V_62 -> V_63 [ V_60 -> type ] ) ;
struct V_1 * V_2 ;
F_35 ( & V_7 -> V_64 ) ;
V_2 = F_4 ( V_7 , V_3 , V_4 , type ) ;
if ( ! V_2 ) {
F_36 ( & V_7 -> V_64 ) ;
return - V_25 ;
}
V_42 ( V_7 , V_2 , V_65 ) ;
F_36 ( & V_7 -> V_64 ) ;
return 0 ;
}
void F_37 ( const struct V_58 * V_23 ,
const struct V_59 * V_60 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_61 * V_62 = F_34 ( V_23 -> V_61 ) ;
struct V_6 * V_7 = F_34 ( V_62 -> V_63 [ V_60 -> type ] ) ;
struct V_1 * V_2 ;
F_35 ( & V_7 -> V_64 ) ;
V_2 = F_2 ( V_7 , V_3 , V_4 , type ) ;
if ( ! V_2 ) {
F_36 ( & V_7 -> V_64 ) ;
return;
}
V_42 ( V_7 , V_2 , V_66 ) ;
F_36 ( & V_7 -> V_64 ) ;
}
static void F_38 ( struct V_6 * V_7 , enum V_48 V_43 )
{
struct V_8 * V_12 , * V_67 ;
struct V_1 * V_2 ;
for ( V_12 = F_39 ( & V_7 -> V_10 ) ;
V_67 = V_12 ? F_40 ( V_12 ) : NULL , V_12 != NULL ;
V_12 = V_67 ) {
V_2 = F_3 ( V_12 , struct V_1 , V_12 ) ;
V_42 ( V_7 , V_2 , V_43 ) ;
}
}
static void F_41 ( struct V_6 * V_7 )
{
unsigned long V_68 ;
V_68 = ( V_69 ) F_42 ( V_70 ) * F_43 () >> 32 ;
F_44 ( & V_7 -> V_71 , V_72 + V_68 ) ;
}
static void F_45 ( unsigned long V_3 )
{
struct V_6 * V_7 = (struct V_6 * ) V_3 ;
F_46 ( & V_7 -> V_64 ) ;
F_38 ( V_7 , V_73 ) ;
F_21 ( V_7 ) ;
F_47 ( & V_7 -> V_64 ) ;
F_26 ( V_7 ) ;
F_41 ( V_7 ) ;
}
static int F_48 ( struct V_19 * V_20 )
{
if ( ! F_49 ( V_20 , sizeof( T_1 ) ) )
return - 1 ;
if ( * V_20 -> V_3 == V_30 ) {
F_50 ( V_20 , sizeof( T_1 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , struct V_19 * V_20 ,
T_1 V_38 )
{
const struct V_44 * V_45 ;
struct V_1 * V_2 ;
enum V_48 V_43 ;
unsigned int V_5 ;
if ( ! F_49 ( V_20 , sizeof( * V_45 ) ) )
return - 1 ;
V_45 = (struct V_44 * ) V_20 -> V_3 ;
if ( V_45 -> V_4 < sizeof( * V_45 ) )
return - 1 ;
if ( ! F_49 ( V_20 , V_45 -> V_4 ) )
return - 1 ;
F_50 ( V_20 , V_45 -> V_4 ) ;
V_5 = sizeof( * V_45 ) - V_45 -> V_4 ;
if ( V_38 > V_7 -> V_7 -> V_74 )
return 0 ;
switch ( V_45 -> V_43 ) {
case V_75 :
if ( V_5 != 0 )
return - 1 ;
F_38 ( V_7 , V_76 ) ;
return 0 ;
case V_77 :
V_43 = V_78 ;
break;
case V_55 :
V_43 = V_79 ;
break;
case V_57 :
V_43 = V_76 ;
break;
case V_80 :
V_43 = V_81 ;
break;
default:
return 0 ;
}
if ( V_5 == 0 )
return - 1 ;
V_2 = F_2 ( V_7 , V_45 -> V_3 , V_5 , V_38 ) ;
if ( V_2 == NULL )
return 0 ;
V_42 ( V_7 , V_2 , V_43 ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 , struct V_19 * V_20 )
{
const struct V_39 * V_40 ;
if ( ! F_49 ( V_20 , sizeof( * V_40 ) ) )
return - 1 ;
V_40 = (struct V_39 * ) V_20 -> V_3 ;
if ( V_40 -> V_38 == 0 )
return - 1 ;
F_50 ( V_20 , sizeof( * V_40 ) ) ;
while ( V_20 -> V_4 > 0 ) {
if ( F_51 ( V_7 , V_20 , V_40 -> V_38 ) < 0 )
return - 1 ;
if ( F_48 ( V_20 ) < 0 )
break;
}
return 0 ;
}
static void F_53 ( const struct V_82 * V_35 , struct V_19 * V_20 ,
struct V_58 * V_23 )
{
struct V_59 * V_60 = V_35 -> V_3 ;
struct V_61 * V_62 ;
struct V_6 * V_7 ;
const struct V_21 * V_22 ;
V_62 = F_54 ( V_23 -> V_61 ) ;
if ( ! V_62 )
goto V_46;
V_7 = F_54 ( V_62 -> V_63 [ V_60 -> type ] ) ;
if ( ! V_7 )
goto V_46;
if ( ! F_49 ( V_20 , sizeof( * V_22 ) ) )
goto V_46;
V_22 = (struct V_21 * ) V_20 -> V_3 ;
if ( F_55 ( & V_22 -> V_26 ) != F_15 ( V_28 ) )
goto V_46;
F_50 ( V_20 , sizeof( * V_22 ) ) ;
F_46 ( & V_7 -> V_64 ) ;
while ( V_20 -> V_4 > 0 ) {
if ( F_52 ( V_7 , V_20 ) < 0 )
break;
if ( F_48 ( V_20 ) < 0 )
break;
}
F_47 ( & V_7 -> V_64 ) ;
V_46:
F_56 ( V_20 ) ;
}
static int F_57 ( struct V_58 * V_23 )
{
struct V_61 * V_62 ;
V_62 = F_58 ( sizeof( * V_62 ) , V_83 ) ;
if ( ! V_62 )
return - V_25 ;
F_59 ( V_23 -> V_61 , V_62 ) ;
return 0 ;
}
static void F_60 ( struct V_58 * V_23 )
{
struct V_61 * V_62 = F_34 ( V_23 -> V_61 ) ;
unsigned int V_84 ;
for ( V_84 = 0 ; V_84 <= V_85 ; V_84 ++ ) {
if ( F_34 ( V_62 -> V_63 [ V_84 ] ) )
return;
}
F_61 ( V_23 -> V_61 , NULL ) ;
F_62 ( V_62 , V_86 ) ;
}
int F_63 ( struct V_58 * V_23 , struct V_59 * V_60 )
{
struct V_6 * V_7 ;
int V_46 ;
F_64 () ;
if ( ! F_34 ( V_23 -> V_61 ) ) {
V_46 = F_57 ( V_23 ) ;
if ( V_46 < 0 )
goto V_87;
}
V_46 = - V_25 ;
V_7 = F_58 ( sizeof( * V_7 ) , V_83 ) ;
if ( ! V_7 )
goto V_88;
V_46 = F_65 ( V_23 , V_60 -> V_35 . V_36 ) ;
if ( V_46 < 0 )
goto V_89;
V_7 -> V_23 = V_23 ;
V_7 -> V_7 = V_60 ;
V_7 -> V_10 = V_90 ;
F_66 ( & V_7 -> V_64 ) ;
F_67 ( & V_7 -> V_37 ) ;
F_59 ( V_23 -> V_61 -> V_63 [ V_60 -> type ] , V_7 ) ;
F_68 ( & V_7 -> V_71 , F_45 , ( unsigned long ) V_7 ) ;
F_41 ( V_7 ) ;
return 0 ;
V_89:
F_10 ( V_7 ) ;
V_88:
F_60 ( V_23 ) ;
V_87:
return V_46 ;
}
void F_69 ( struct V_58 * V_23 , struct V_59 * V_60 )
{
struct V_61 * V_62 = F_34 ( V_23 -> V_61 ) ;
struct V_6 * V_7 = F_34 ( V_62 -> V_63 [ V_60 -> type ] ) ;
F_64 () ;
F_61 ( V_62 -> V_63 [ V_60 -> type ] , NULL ) ;
F_70 ( & V_7 -> V_71 ) ;
F_35 ( & V_7 -> V_64 ) ;
F_38 ( V_7 , V_73 ) ;
F_21 ( V_7 ) ;
F_36 ( & V_7 -> V_64 ) ;
F_26 ( V_7 ) ;
F_71 ( V_23 , V_60 -> V_35 . V_36 ) ;
F_62 ( V_7 , V_86 ) ;
F_60 ( V_23 ) ;
}
int F_72 ( struct V_59 * V_60 )
{
V_60 -> V_35 . V_91 = F_53 ;
V_60 -> V_35 . V_3 = V_60 ;
return F_73 ( & V_60 -> V_35 ) ;
}
void F_74 ( struct V_59 * V_60 )
{
F_75 ( & V_60 -> V_35 ) ;
}
