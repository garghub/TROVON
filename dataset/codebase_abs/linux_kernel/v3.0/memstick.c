static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 & V_6 ) {
if ( ( V_4 -> type == V_2 -> V_4 . type )
&& ( V_4 -> V_7 == V_2 -> V_4 . V_7 )
&& ( V_4 -> V_8 == V_2 -> V_4 . V_8 ) )
return 1 ;
}
return 0 ;
}
static int F_2 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
struct V_13 * V_14 = F_3 ( V_12 ,
struct V_13 ,
V_15 ) ;
struct V_3 * V_16 = V_14 -> V_17 ;
if ( V_16 ) {
while ( V_16 -> V_5 ) {
if ( F_1 ( V_2 , V_16 ) )
return 1 ;
++ V_16 ;
}
}
return 0 ;
}
static int F_4 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
if ( F_5 ( V_19 , L_1 , V_2 -> V_4 . type ) )
return - V_20 ;
if ( F_5 ( V_19 , L_2 , V_2 -> V_4 . V_7 ) )
return - V_20 ;
if ( F_5 ( V_19 , L_3 , V_2 -> V_4 . V_8 ) )
return - V_20 ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
struct V_13 * V_12 = F_3 ( V_10 -> V_15 ,
struct V_13 ,
V_15 ) ;
int V_21 = - V_22 ;
if ( V_10 -> V_15 && V_12 -> V_23 ) {
V_21 = V_12 -> V_23 ( V_2 ) ;
if ( ! V_21 )
F_7 ( V_10 ) ;
}
return V_21 ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
struct V_13 * V_12 = F_3 ( V_10 -> V_15 ,
struct V_13 ,
V_15 ) ;
if ( V_10 -> V_15 && V_12 -> remove ) {
V_12 -> remove ( V_2 ) ;
V_2 -> V_10 . V_15 = NULL ;
}
F_9 ( V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , T_1 V_24 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
struct V_13 * V_12 = F_3 ( V_10 -> V_15 ,
struct V_13 ,
V_15 ) ;
if ( V_10 -> V_15 && V_12 -> V_25 )
return V_12 -> V_25 ( V_2 , V_24 ) ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
struct V_13 * V_12 = F_3 ( V_10 -> V_15 ,
struct V_13 ,
V_15 ) ;
if ( V_10 -> V_15 && V_12 -> V_26 )
return V_12 -> V_26 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_27 * V_28 = F_3 ( V_10 , struct V_27 ,
V_10 ) ;
F_13 ( V_28 ) ;
}
static void F_14 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_3 ( V_10 , struct V_1 ,
V_10 ) ;
F_13 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_16 ( struct V_27 * V_28 )
{
F_17 ( V_29 , & V_28 -> V_30 ) ;
}
int F_18 ( struct V_27 * V_28 , struct V_31 * * V_32 )
{
int V_21 = - V_33 ;
if ( ( * V_32 ) && ( * V_32 ) -> error && V_28 -> V_34 ) {
( * V_32 ) -> error = V_21 ;
V_28 -> V_34 -- ;
return 0 ;
}
if ( V_28 -> V_2 && V_28 -> V_2 -> V_35 )
V_21 = V_28 -> V_2 -> V_35 ( V_28 -> V_2 , V_32 ) ;
if ( ! V_21 )
V_28 -> V_34 = V_36 > 1 ? V_36 - 1 : 1 ;
else
* V_32 = NULL ;
return V_21 ;
}
void F_19 ( struct V_27 * V_28 )
{
if ( V_28 -> V_2 ) {
V_28 -> V_34 = V_36 ;
F_20 ( V_28 -> V_2 -> V_37 ) ;
V_28 -> V_38 ( V_28 ) ;
}
}
void F_21 ( struct V_31 * V_32 , unsigned char V_39 ,
const struct V_40 * V_41 )
{
V_32 -> V_39 = V_39 ;
if ( V_39 & 8 )
V_32 -> V_42 = V_43 ;
else
V_32 -> V_42 = V_44 ;
V_32 -> V_41 = * V_41 ;
V_32 -> V_45 = 1 ;
if ( V_39 == V_46 || V_39 == V_47 )
V_32 -> V_48 = 1 ;
else
V_32 -> V_48 = 0 ;
}
void F_22 ( struct V_31 * V_32 , unsigned char V_39 ,
const void * V_49 , T_2 V_50 )
{
V_32 -> V_39 = V_39 ;
if ( V_39 & 8 )
V_32 -> V_42 = V_43 ;
else
V_32 -> V_42 = V_44 ;
V_32 -> V_51 = V_50 > sizeof( V_32 -> V_52 ) ? sizeof( V_32 -> V_52 ) : V_50 ;
if ( V_32 -> V_42 == V_43 )
memcpy ( V_32 -> V_52 , V_49 , V_32 -> V_51 ) ;
V_32 -> V_45 = 0 ;
if ( V_39 == V_46 || V_39 == V_47 )
V_32 -> V_48 = 1 ;
else
V_32 -> V_48 = 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_31 * * V_32 )
{
struct V_53 V_54 ;
if ( ! ( * V_32 ) ) {
F_22 ( & V_2 -> V_55 , V_56 , NULL ,
sizeof( struct V_53 ) ) ;
* V_32 = & V_2 -> V_55 ;
return 0 ;
} else {
if ( ! ( * V_32 ) -> error ) {
memcpy ( & V_54 , ( * V_32 ) -> V_52 , sizeof( V_54 ) ) ;
V_2 -> V_4 . V_5 = V_6 ;
V_2 -> V_4 . type = V_54 . type ;
V_2 -> V_4 . V_7 = V_54 . V_7 ;
V_2 -> V_4 . V_8 = V_54 . V_8 ;
F_24 ( & V_2 -> V_10 , L_4 , V_54 . V_57 ) ;
}
F_25 ( & V_2 -> V_37 ) ;
return - V_58 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_31 * * V_32 )
{
if ( ! ( * V_32 ) ) {
F_22 ( & V_2 -> V_55 , V_59 ,
( char * ) & V_2 -> V_60 ,
sizeof( V_2 -> V_60 ) ) ;
* V_32 = & V_2 -> V_55 ;
return 0 ;
} else {
F_25 ( & V_2 -> V_37 ) ;
return - V_58 ;
}
}
int F_27 ( struct V_1 * V_2 )
{
V_2 -> V_35 = F_26 ;
F_19 ( V_2 -> V_28 ) ;
F_28 ( & V_2 -> V_37 ) ;
return V_2 -> V_55 . error ;
}
static struct V_1 * F_29 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_30 ( sizeof( struct V_1 ) ,
V_61 ) ;
struct V_1 * V_62 = V_28 -> V_2 ;
struct V_53 V_54 ;
if ( V_2 ) {
V_2 -> V_28 = V_28 ;
F_31 ( & V_2 -> V_10 , L_5 , F_32 ( & V_28 -> V_10 ) ) ;
V_2 -> V_10 . V_63 = & V_28 -> V_10 ;
V_2 -> V_10 . V_64 = & V_65 ;
V_2 -> V_10 . V_66 = F_14 ;
V_2 -> V_67 = F_15 ;
V_2 -> V_60 . V_68 = F_33 ( struct V_69 , V_4 ) ;
V_2 -> V_60 . V_70 = sizeof( V_54 ) ;
V_2 -> V_60 . V_71 = F_33 ( struct V_69 , V_4 ) ;
V_2 -> V_60 . V_72 = sizeof( V_54 ) ;
F_34 ( & V_2 -> V_37 ) ;
V_28 -> V_2 = V_2 ;
if ( F_27 ( V_2 ) )
goto V_73;
V_2 -> V_35 = F_23 ;
F_19 ( V_28 ) ;
F_28 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_55 . error )
goto V_73;
}
V_28 -> V_2 = V_62 ;
return V_2 ;
V_73:
V_28 -> V_2 = V_62 ;
F_13 ( V_2 ) ;
return NULL ;
}
static int F_35 ( struct V_27 * V_28 )
{
int V_21 = V_28 -> V_74 ( V_28 , V_75 , V_76 ) ;
if ( ! V_21 )
V_21 = V_28 -> V_74 ( V_28 , V_77 , V_78 ) ;
return V_21 ;
}
static void F_36 ( struct V_79 * V_80 )
{
struct V_27 * V_28 = F_3 ( V_80 , struct V_27 ,
V_30 ) ;
struct V_1 * V_2 ;
F_24 ( & V_28 -> V_10 , L_6 ) ;
F_37 ( & V_28 -> V_81 ) ;
if ( ! V_28 -> V_2 ) {
if ( F_35 ( V_28 ) )
goto V_82;
} else if ( V_28 -> V_2 -> V_83 )
V_28 -> V_2 -> V_83 ( V_28 -> V_2 ) ;
V_2 = F_29 ( V_28 ) ;
if ( ! V_2 ) {
if ( V_28 -> V_2 ) {
F_38 ( & V_28 -> V_2 -> V_10 ) ;
V_28 -> V_2 = NULL ;
}
} else {
F_24 ( & V_28 -> V_10 , L_7 ,
V_2 -> V_4 . type , V_2 -> V_4 . V_7 , V_2 -> V_4 . V_8 ) ;
if ( V_28 -> V_2 ) {
if ( F_27 ( V_28 -> V_2 )
|| ! F_1 ( V_28 -> V_2 , & V_2 -> V_4 )
|| ! ( V_28 -> V_2 -> V_67 ( V_28 -> V_2 ) ) ) {
F_38 ( & V_28 -> V_2 -> V_10 ) ;
V_28 -> V_2 = NULL ;
} else if ( V_28 -> V_2 -> V_84 )
V_28 -> V_2 -> V_84 ( V_28 -> V_2 ) ;
}
if ( ! V_28 -> V_2 ) {
V_28 -> V_2 = V_2 ;
if ( F_39 ( & V_2 -> V_10 ) ) {
F_9 ( & V_2 -> V_10 ) ;
F_13 ( V_28 -> V_2 ) ;
V_28 -> V_2 = NULL ;
}
} else
F_13 ( V_2 ) ;
}
V_82:
if ( ! V_28 -> V_2 )
V_28 -> V_74 ( V_28 , V_75 , V_85 ) ;
F_40 ( & V_28 -> V_81 ) ;
F_24 ( & V_28 -> V_10 , L_8 ) ;
}
struct V_27 * F_41 ( unsigned int V_86 ,
struct V_9 * V_10 )
{
struct V_27 * V_28 ;
V_28 = F_30 ( sizeof( struct V_27 ) + V_86 , V_61 ) ;
if ( V_28 ) {
F_42 ( & V_28 -> V_81 ) ;
F_43 ( & V_28 -> V_30 , F_36 ) ;
V_28 -> V_10 . V_8 = & V_87 ;
V_28 -> V_10 . V_63 = V_10 ;
F_44 ( & V_28 -> V_10 ) ;
}
return V_28 ;
}
int F_45 ( struct V_27 * V_28 )
{
int V_21 ;
while ( 1 ) {
if ( ! F_46 ( & V_88 , V_61 ) )
return - V_20 ;
F_47 ( & V_89 ) ;
V_21 = F_48 ( & V_88 , V_28 , & V_28 -> V_4 ) ;
F_49 ( & V_89 ) ;
if ( ! V_21 )
break;
else if ( V_21 != - V_58 )
return V_21 ;
}
F_31 ( & V_28 -> V_10 , L_9 , V_28 -> V_4 ) ;
V_21 = F_50 ( & V_28 -> V_10 ) ;
if ( V_21 ) {
F_47 ( & V_89 ) ;
F_51 ( & V_88 , V_28 -> V_4 ) ;
F_49 ( & V_89 ) ;
return V_21 ;
}
V_28 -> V_74 ( V_28 , V_75 , V_85 ) ;
F_16 ( V_28 ) ;
return 0 ;
}
void F_52 ( struct V_27 * V_28 )
{
F_53 ( V_29 ) ;
F_37 ( & V_28 -> V_81 ) ;
if ( V_28 -> V_2 )
F_38 ( & V_28 -> V_2 -> V_10 ) ;
V_28 -> V_2 = NULL ;
V_28 -> V_74 ( V_28 , V_75 , V_85 ) ;
F_40 ( & V_28 -> V_81 ) ;
F_47 ( & V_89 ) ;
F_51 ( & V_88 , V_28 -> V_4 ) ;
F_49 ( & V_89 ) ;
F_54 ( & V_28 -> V_10 ) ;
}
void F_55 ( struct V_27 * V_28 )
{
F_56 ( & V_28 -> V_81 ) ;
F_9 ( & V_28 -> V_10 ) ;
}
void F_57 ( struct V_27 * V_28 )
{
F_37 ( & V_28 -> V_81 ) ;
V_28 -> V_74 ( V_28 , V_75 , V_85 ) ;
F_40 ( & V_28 -> V_81 ) ;
}
void F_58 ( struct V_27 * V_28 )
{
int V_21 = 0 ;
F_37 ( & V_28 -> V_81 ) ;
if ( V_28 -> V_2 )
V_21 = F_35 ( V_28 ) ;
F_40 ( & V_28 -> V_81 ) ;
if ( ! V_21 )
F_16 ( V_28 ) ;
}
int F_59 ( struct V_13 * V_12 )
{
V_12 -> V_15 . V_64 = & V_65 ;
return F_60 ( & V_12 -> V_15 ) ;
}
void F_61 ( struct V_13 * V_12 )
{
F_62 ( & V_12 -> V_15 ) ;
}
static int T_3 F_63 ( void )
{
int V_21 ;
V_29 = F_64 ( L_10 ) ;
if ( ! V_29 )
return - V_20 ;
V_21 = F_65 ( & V_65 ) ;
if ( ! V_21 )
V_21 = F_66 ( & V_87 ) ;
if ( ! V_21 )
return 0 ;
F_67 ( & V_65 ) ;
F_68 ( V_29 ) ;
return V_21 ;
}
static void T_4 F_69 ( void )
{
F_70 ( & V_87 ) ;
F_67 ( & V_65 ) ;
F_68 ( V_29 ) ;
F_71 ( & V_88 ) ;
}
