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
if ( V_11 < 0 )
V_9 = V_9 -> V_13 ;
else if ( V_11 > 0 )
V_9 = V_9 -> V_14 ;
else
return V_2 ;
}
return NULL ;
}
static void F_4 ( struct V_6 * V_7 , struct V_1 * V_15 )
{
struct V_8 * V_9 = NULL , * * V_16 = & V_7 -> V_10 . V_8 ;
struct V_1 * V_2 ;
int V_11 ;
while ( * V_16 ) {
V_9 = * V_16 ;
V_2 = F_3 ( V_9 , struct V_1 , V_12 ) ;
V_11 = F_1 ( V_2 , V_15 -> V_3 , V_15 -> V_5 , V_15 -> type ) ;
if ( V_11 < 0 )
V_16 = & V_9 -> V_13 ;
else if ( V_11 > 0 )
V_16 = & V_9 -> V_14 ;
}
F_5 ( & V_15 -> V_12 , V_9 , V_16 ) ;
F_6 ( & V_15 -> V_12 , & V_7 -> V_10 ) ;
}
static struct V_1 * F_7 ( struct V_6 * V_7 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_1 * V_2 ;
V_2 = F_8 ( sizeof( * V_2 ) + V_4 , V_17 ) ;
if ( ! V_2 )
return V_2 ;
V_2 -> V_18 = V_19 ;
V_2 -> type = type ;
V_2 -> V_5 = V_4 ;
memcpy ( V_2 -> V_3 , V_3 , V_4 ) ;
F_4 ( V_7 , V_2 ) ;
return V_2 ;
}
static void F_9 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_12 , & V_7 -> V_10 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
#define F_13 sizeof(struct llc_pdu_un)
V_21 = F_14 ( V_7 -> V_24 -> V_25 + F_15 ( V_7 -> V_24 ) ,
V_17 ) ;
if ( ! V_21 )
return - V_26 ;
V_21 -> V_24 = V_7 -> V_24 ;
V_21 -> V_27 = F_16 ( V_28 ) ;
F_17 ( V_21 , F_15 ( V_7 -> V_24 ) + F_13 ) ;
V_23 = (struct V_22 * ) F_18 ( V_21 , sizeof( * V_23 ) ) ;
F_19 ( F_16 ( V_29 ) , & V_23 -> V_27 ) ;
V_7 -> V_30 = V_21 ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
if ( F_21 ( V_7 -> V_30 ) < sizeof( T_1 ) )
return - 1 ;
* ( T_1 * ) F_18 ( V_7 -> V_30 , sizeof( T_1 ) ) = V_31 ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 )
{
if ( ! V_7 -> V_30 )
return;
F_20 ( V_7 ) ;
F_20 ( V_7 ) ;
F_23 ( V_7 -> V_30 , V_32 , V_33 ,
V_33 , V_34 ) ;
F_24 ( V_7 -> V_30 ) ;
F_25 ( V_7 -> V_30 , V_7 -> V_24 -> V_35 ,
V_7 -> V_7 -> V_36 . V_37 ) ;
F_26 ( & V_7 -> V_38 , V_7 -> V_30 ) ;
V_7 -> V_30 = NULL ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_20 * V_21 ;
while ( ( V_21 = F_28 ( & V_7 -> V_38 ) ) )
F_29 ( V_21 ) ;
}
static int F_30 ( struct V_6 * V_7 , T_1 V_39 )
{
struct V_40 * V_41 ;
if ( F_21 ( V_7 -> V_30 ) < sizeof( * V_41 ) )
return - 1 ;
V_41 = (struct V_40 * ) F_18 ( V_7 -> V_30 , sizeof( * V_41 ) ) ;
V_41 -> V_39 = V_39 ;
F_31 ( V_7 -> V_30 ) -> V_42 = V_39 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 ,
const struct V_1 * V_2 ,
enum V_43 V_44 )
{
struct V_45 * V_46 ;
unsigned int V_4 ;
int V_47 ;
V_48:
if ( ! V_7 -> V_30 ) {
V_47 = F_12 ( V_7 ) ;
if ( V_47 < 0 )
return V_47 ;
}
if ( F_31 ( V_7 -> V_30 ) -> V_42 != V_2 -> type ) {
if ( F_31 ( V_7 -> V_30 ) -> V_42 &&
F_20 ( V_7 ) < 0 )
goto V_38;
if ( F_30 ( V_7 , V_2 -> type ) < 0 )
goto V_38;
}
V_4 = sizeof( * V_46 ) + V_2 -> V_5 ;
if ( F_21 ( V_7 -> V_30 ) < V_4 )
goto V_38;
V_46 = (struct V_45 * ) F_18 ( V_7 -> V_30 , V_4 ) ;
V_46 -> V_4 = V_4 ;
V_46 -> V_44 = V_44 ;
memcpy ( V_46 -> V_3 , V_2 -> V_3 , V_2 -> V_5 ) ;
return 0 ;
V_38:
F_22 ( V_7 ) ;
goto V_48;
}
static void V_43 ( struct V_6 * V_7 ,
struct V_1 * V_2 , enum V_49 V_44 )
{
enum V_50 V_18 ;
V_18 = V_51 [ V_2 -> V_18 ] [ V_44 ] . V_18 ;
if ( V_18 == V_52 )
return;
switch ( V_51 [ V_2 -> V_18 ] [ V_44 ] . V_53 ) {
case V_54 :
break;
case V_55 :
if ( F_32 ( V_7 , V_2 , V_56 ) < 0 )
return;
break;
case V_57 :
F_32 ( V_7 , V_2 , V_58 ) ;
F_9 ( V_7 , V_2 ) ;
return;
default:
F_33 ( 1 ) ;
}
V_2 -> V_18 = V_18 ;
}
int F_34 ( const struct V_59 * V_24 ,
const struct V_60 * V_61 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_62 * V_63 = F_35 ( V_24 -> V_62 ) ;
struct V_6 * V_7 = F_35 ( V_63 -> V_64 [ V_61 -> type ] ) ;
struct V_1 * V_2 ;
F_36 ( & V_7 -> V_65 ) ;
V_2 = F_7 ( V_7 , V_3 , V_4 , type ) ;
if ( ! V_2 ) {
F_37 ( & V_7 -> V_65 ) ;
return - V_26 ;
}
V_43 ( V_7 , V_2 , V_66 ) ;
F_37 ( & V_7 -> V_65 ) ;
return 0 ;
}
void F_38 ( const struct V_59 * V_24 ,
const struct V_60 * V_61 ,
const void * V_3 , T_1 V_4 , T_1 type )
{
struct V_62 * V_63 = F_35 ( V_24 -> V_62 ) ;
struct V_6 * V_7 = F_35 ( V_63 -> V_64 [ V_61 -> type ] ) ;
struct V_1 * V_2 ;
F_36 ( & V_7 -> V_65 ) ;
V_2 = F_2 ( V_7 , V_3 , V_4 , type ) ;
if ( ! V_2 ) {
F_37 ( & V_7 -> V_65 ) ;
return;
}
V_43 ( V_7 , V_2 , V_67 ) ;
F_37 ( & V_7 -> V_65 ) ;
}
static void F_39 ( struct V_6 * V_7 , enum V_49 V_44 )
{
struct V_8 * V_12 , * V_68 ;
struct V_1 * V_2 ;
for ( V_12 = F_40 ( & V_7 -> V_10 ) ;
V_68 = V_12 ? F_41 ( V_12 ) : NULL , V_12 != NULL ;
V_12 = V_68 ) {
V_2 = F_3 ( V_12 , struct V_1 , V_12 ) ;
V_43 ( V_7 , V_2 , V_44 ) ;
}
}
static void F_42 ( struct V_6 * V_7 )
{
unsigned long V_69 ;
V_69 = ( V_70 ) F_43 ( V_71 ) * F_44 () >> 32 ;
F_45 ( & V_7 -> V_72 , V_73 + V_69 ) ;
}
static void F_46 ( unsigned long V_3 )
{
struct V_6 * V_7 = (struct V_6 * ) V_3 ;
F_47 ( & V_7 -> V_65 ) ;
F_39 ( V_7 , V_74 ) ;
F_22 ( V_7 ) ;
F_48 ( & V_7 -> V_65 ) ;
F_27 ( V_7 ) ;
F_42 ( V_7 ) ;
}
static int F_49 ( struct V_20 * V_21 )
{
if ( ! F_50 ( V_21 , sizeof( T_1 ) ) )
return - 1 ;
if ( * V_21 -> V_3 == V_31 ) {
F_51 ( V_21 , sizeof( T_1 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_52 ( struct V_6 * V_7 , struct V_20 * V_21 ,
T_1 V_39 )
{
const struct V_45 * V_46 ;
struct V_1 * V_2 ;
enum V_49 V_44 ;
unsigned int V_5 ;
if ( ! F_50 ( V_21 , sizeof( * V_46 ) ) )
return - 1 ;
V_46 = (struct V_45 * ) V_21 -> V_3 ;
if ( V_46 -> V_4 < sizeof( * V_46 ) )
return - 1 ;
if ( ! F_50 ( V_21 , V_46 -> V_4 ) )
return - 1 ;
F_51 ( V_21 , V_46 -> V_4 ) ;
V_5 = sizeof( * V_46 ) - V_46 -> V_4 ;
if ( V_39 > V_7 -> V_7 -> V_75 )
return 0 ;
switch ( V_46 -> V_44 ) {
case V_76 :
if ( V_5 != 0 )
return - 1 ;
F_39 ( V_7 , V_77 ) ;
return 0 ;
case V_78 :
V_44 = V_79 ;
break;
case V_56 :
V_44 = V_80 ;
break;
case V_58 :
V_44 = V_77 ;
break;
case V_81 :
V_44 = V_82 ;
break;
default:
return 0 ;
}
if ( V_5 == 0 )
return - 1 ;
V_2 = F_2 ( V_7 , V_46 -> V_3 , V_5 , V_39 ) ;
if ( V_2 == NULL )
return 0 ;
V_43 ( V_7 , V_2 , V_44 ) ;
return 0 ;
}
static int F_53 ( struct V_6 * V_7 , struct V_20 * V_21 )
{
const struct V_40 * V_41 ;
if ( ! F_50 ( V_21 , sizeof( * V_41 ) ) )
return - 1 ;
V_41 = (struct V_40 * ) V_21 -> V_3 ;
if ( V_41 -> V_39 == 0 )
return - 1 ;
F_51 ( V_21 , sizeof( * V_41 ) ) ;
while ( V_21 -> V_4 > 0 ) {
if ( F_52 ( V_7 , V_21 , V_41 -> V_39 ) < 0 )
return - 1 ;
if ( F_49 ( V_21 ) < 0 )
break;
}
return 0 ;
}
static void F_54 ( const struct V_83 * V_36 , struct V_20 * V_21 ,
struct V_59 * V_24 )
{
struct V_60 * V_61 = V_36 -> V_3 ;
struct V_62 * V_63 ;
struct V_6 * V_7 ;
const struct V_22 * V_23 ;
V_63 = F_55 ( V_24 -> V_62 ) ;
if ( ! V_63 )
goto V_47;
V_7 = F_55 ( V_63 -> V_64 [ V_61 -> type ] ) ;
if ( ! V_7 )
goto V_47;
if ( ! F_50 ( V_21 , sizeof( * V_23 ) ) )
goto V_47;
V_23 = (struct V_22 * ) V_21 -> V_3 ;
if ( F_56 ( & V_23 -> V_27 ) != F_16 ( V_29 ) )
goto V_47;
F_51 ( V_21 , sizeof( * V_23 ) ) ;
F_47 ( & V_7 -> V_65 ) ;
while ( V_21 -> V_4 > 0 ) {
if ( F_53 ( V_7 , V_21 ) < 0 )
break;
if ( F_49 ( V_21 ) < 0 )
break;
}
F_48 ( & V_7 -> V_65 ) ;
V_47:
F_57 ( V_21 ) ;
}
static int F_58 ( struct V_59 * V_24 )
{
struct V_62 * V_63 ;
V_63 = F_59 ( sizeof( * V_63 ) , V_84 ) ;
if ( ! V_63 )
return - V_26 ;
F_60 ( V_24 -> V_62 , V_63 ) ;
return 0 ;
}
static void F_61 ( struct V_59 * V_24 )
{
struct V_62 * V_63 = F_35 ( V_24 -> V_62 ) ;
unsigned int V_85 ;
for ( V_85 = 0 ; V_85 <= V_86 ; V_85 ++ ) {
if ( F_35 ( V_63 -> V_64 [ V_85 ] ) )
return;
}
F_60 ( V_24 -> V_62 , NULL ) ;
F_62 ( V_63 , V_87 ) ;
}
int F_63 ( struct V_59 * V_24 , struct V_60 * V_61 )
{
struct V_6 * V_7 ;
int V_47 ;
F_64 () ;
if ( ! F_35 ( V_24 -> V_62 ) ) {
V_47 = F_58 ( V_24 ) ;
if ( V_47 < 0 )
goto V_88;
}
V_47 = - V_26 ;
V_7 = F_59 ( sizeof( * V_7 ) , V_84 ) ;
if ( ! V_7 )
goto V_89;
V_47 = F_65 ( V_24 , V_61 -> V_36 . V_37 ) ;
if ( V_47 < 0 )
goto V_90;
V_7 -> V_24 = V_24 ;
V_7 -> V_7 = V_61 ;
V_7 -> V_10 = V_91 ;
F_66 ( & V_7 -> V_65 ) ;
F_67 ( & V_7 -> V_38 ) ;
F_60 ( V_24 -> V_62 -> V_64 [ V_61 -> type ] , V_7 ) ;
F_68 ( & V_7 -> V_72 , F_46 , ( unsigned long ) V_7 ) ;
F_42 ( V_7 ) ;
return 0 ;
V_90:
F_11 ( V_7 ) ;
V_89:
F_61 ( V_24 ) ;
V_88:
return V_47 ;
}
void F_69 ( struct V_59 * V_24 , struct V_60 * V_61 )
{
struct V_62 * V_63 = F_35 ( V_24 -> V_62 ) ;
struct V_6 * V_7 = F_35 ( V_63 -> V_64 [ V_61 -> type ] ) ;
F_64 () ;
F_60 ( V_63 -> V_64 [ V_61 -> type ] , NULL ) ;
F_70 ( & V_7 -> V_72 ) ;
F_39 ( V_7 , V_74 ) ;
F_22 ( V_7 ) ;
F_27 ( V_7 ) ;
F_71 ( V_24 , V_61 -> V_36 . V_37 ) ;
F_62 ( V_7 , V_87 ) ;
F_61 ( V_24 ) ;
}
int F_72 ( struct V_60 * V_61 )
{
V_61 -> V_36 . V_92 = F_54 ;
V_61 -> V_36 . V_3 = V_61 ;
return F_73 ( & V_61 -> V_36 ) ;
}
void F_74 ( struct V_60 * V_61 )
{
F_75 ( & V_61 -> V_36 ) ;
}
