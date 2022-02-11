void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
char * V_3 ;
char * V_4 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_3 = ( char * ) V_6 + F_5 ( V_6 -> V_8 ) ;
V_2 -> V_3 = F_6 ( V_3 , V_7 ) ;
V_2 -> V_9 = F_5 ( V_6 -> V_10 ) ;
V_4 = ( char * ) V_6 + F_5 ( V_6 -> V_11 ) ;
V_2 -> V_4 = F_7 ( V_4 , V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_12 * F_8 ( struct V_5 * V_6 ,
const char * V_13 )
{
struct V_12 * V_14 ;
char * V_3 ;
if ( ! V_13 [ 1 ] )
V_13 ++ ;
V_14 = F_4 ( sizeof( * V_14 ) , V_7 ) ;
if ( ! V_14 )
return NULL ;
V_3 = ( char * ) V_6 + F_5 ( V_6 -> V_8 ) ;
V_14 -> V_15 = F_9 ( V_7 , L_1 , V_13 , V_3 ) ;
if ( ! V_14 -> V_15 ) {
F_2 ( V_14 ) ;
return NULL ;
}
F_10 ( V_14 , V_16 ) ;
F_11 ( V_14 ) ;
return V_14 ;
}
static void F_12 ( struct V_12 * V_14 )
{
struct V_1 * V_2 ;
while ( V_14 -> V_17 ) {
V_2 = V_14 -> V_17 ;
V_14 -> V_17 = V_2 -> V_18 ;
F_1 ( V_2 ) ;
}
F_2 ( V_14 -> V_15 ) ;
F_2 ( V_14 ) ;
}
void F_13 ( struct V_12 * V_14 )
{
if ( V_14 -> V_19 )
F_13 ( V_14 -> V_19 ) ;
if ( V_14 -> V_20 )
F_13 ( V_14 -> V_20 ) ;
F_12 ( V_14 ) ;
}
struct V_12 * F_14 ( T_1 V_21 ,
struct V_12 * V_22 )
{
struct V_12 * V_14 ;
struct V_12 * V_23 = NULL ;
struct V_12 * V_24 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_25 = NULL ;
struct V_5 * V_6 ;
char * V_26 ;
const char * V_27 = V_22 -> V_15 ;
int V_28 ;
int V_29 = - 1 ;
V_28 = F_15 ( L_2 ) ;
if ( V_28 == V_30 )
return NULL ;
V_26 = F_4 ( V_31 , V_7 ) ;
if ( ! V_26 )
return NULL ;
V_6 = (struct V_5 * ) & V_26 [ 0 ] ;
V_6 -> V_21 = V_21 ;
V_6 -> V_32 = 0 ;
do {
F_16 ( & V_33 ) ;
memcpy ( V_34 , V_26 , V_31 ) ;
V_29 = F_17 ( V_28 , 2 , 1 , NULL , V_34 , NULL ) ;
memcpy ( V_26 , V_34 , V_31 ) ;
F_18 ( & V_33 ) ;
switch ( V_29 ) {
case V_35 :
break;
case V_36 :
V_14 = F_8 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
V_14 -> V_22 = V_24 -> V_22 ;
V_24 -> V_20 = V_14 ;
V_24 = V_14 ;
break;
case V_38 :
if ( V_23 )
V_27 = V_24 -> V_15 ;
V_14 = F_8 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
if ( ! V_23 ) {
V_14 -> V_22 = V_22 ;
V_23 = V_14 ;
} else {
V_14 -> V_22 = V_24 ;
if ( V_24 )
V_24 -> V_19 = V_14 ;
}
V_24 = V_14 ;
break;
case V_39 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_37;
if ( ! V_24 -> V_17 )
V_24 -> V_17 = V_1 ;
else
V_25 -> V_18 = V_1 ;
V_25 = V_1 ;
break;
case V_40 :
V_24 = V_24 -> V_22 ;
V_27 = V_24 -> V_22 -> V_15 ;
break;
case V_41 :
break;
case V_42 :
case V_43 :
default:
F_19 ( V_44 L_3
L_4 , V_29 ) ;
goto V_37;
}
} while ( V_29 );
V_37:
F_2 ( V_26 ) ;
if ( V_29 ) {
if ( V_23 )
F_13 ( V_23 ) ;
return NULL ;
}
return V_23 ;
}
int F_20 ( struct V_12 * V_14 )
{
int V_29 ;
V_14 -> V_22 = F_21 ( V_14 -> V_15 ) ;
if ( F_22 ( V_14 -> V_22 ) )
return F_23 ( V_14 -> V_22 ) ;
V_29 = F_24 ( V_14 ) ;
if ( V_29 ) {
F_19 ( V_44 L_5 ,
V_14 -> V_15 ) ;
return V_29 ;
}
F_25 ( V_14 -> V_22 ) ;
return 0 ;
}
int F_26 ( struct V_12 * V_14 )
{
struct V_12 * V_19 ;
int V_29 ;
V_19 = F_27 ( V_14 , NULL ) ;
while ( V_19 ) {
F_26 ( V_19 ) ;
V_19 = F_27 ( V_14 , V_19 ) ;
}
V_29 = F_28 ( V_14 ) ;
if ( V_29 )
return V_29 ;
F_25 ( V_14 ) ;
return 0 ;
}
int F_29 ( T_2 V_21 )
{
int V_45 , V_29 ;
V_29 = F_17 ( F_15 ( L_6 ) , 2 , 2 , & V_45 ,
V_46 , V_21 ) ;
if ( V_29 || V_45 != V_47 )
return - 1 ;
V_29 = F_30 ( V_48 , V_21 , V_49 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_50 , V_21 , V_51 ) ;
if ( V_29 ) {
F_30 ( V_48 , V_21 , V_52 ) ;
return V_29 ;
}
return 0 ;
}
int F_31 ( T_2 V_21 )
{
int V_45 , V_29 ;
V_29 = F_17 ( F_15 ( L_6 ) , 2 , 2 , & V_45 ,
V_46 , V_21 ) ;
if ( V_29 || V_45 != V_53 )
return - 1 ;
V_29 = F_30 ( V_50 , V_21 , V_54 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_48 , V_21 , V_52 ) ;
if ( V_29 ) {
F_30 ( V_50 , V_21 , V_51 ) ;
return V_29 ;
}
return 0 ;
}
static int F_32 ( struct V_55 * V_56 )
{
int V_29 ;
switch ( V_56 -> V_57 ) {
case V_58 :
V_56 -> V_59 . V_60 =
F_5 ( V_56 -> V_59 . V_60 ) ;
break;
case V_61 :
V_56 -> V_59 . V_21 =
F_5 ( V_56 -> V_59 . V_21 ) ;
break;
case V_62 :
V_56 -> V_59 . V_63 . V_64 =
F_5 ( V_56 -> V_59 . V_63 . V_64 ) ;
V_56 -> V_59 . V_63 . V_65 =
F_5 ( V_56 -> V_59 . V_63 . V_65 ) ;
}
switch ( V_56 -> V_66 ) {
case V_67 :
V_29 = F_33 ( V_56 ) ;
break;
case V_68 :
V_29 = F_34 ( V_56 ) ;
break;
default:
F_35 ( L_7 ,
V_56 -> V_66 ) ;
V_29 = - V_69 ;
}
return V_29 ;
}
static void F_36 ( struct V_70 * V_71 )
{
struct V_72 * V_73 =
F_37 ( V_71 , struct V_72 , V_71 ) ;
if ( V_73 -> V_29 )
* ( V_73 -> V_29 ) = F_32 ( V_73 -> V_74 ) ;
else
F_32 ( V_73 -> V_74 ) ;
if ( V_73 -> V_75 )
F_38 ( V_73 -> V_75 ) ;
F_2 ( V_73 -> V_74 ) ;
F_2 ( ( void * ) V_71 ) ;
}
void F_39 ( struct V_55 * V_76 ,
struct V_77 * V_78 , int * V_29 )
{
struct V_72 * V_71 ;
struct V_55 * V_79 ;
V_79 = F_40 ( sizeof( struct V_55 ) ,
V_7 ) ;
memcpy ( V_79 , V_76 , sizeof( struct V_55 ) ) ;
V_71 = F_40 ( sizeof( struct V_72 ) , V_7 ) ;
if ( V_71 ) {
F_41 ( (struct V_70 * ) V_71 , F_36 ) ;
V_71 -> V_74 = V_79 ;
V_71 -> V_75 = V_78 ;
V_71 -> V_29 = V_29 ;
F_42 ( V_80 , (struct V_70 * ) V_71 ) ;
} else {
* V_29 = - V_81 ;
F_2 ( V_79 ) ;
F_38 ( V_78 ) ;
}
}
static int F_43 ( char * * V_82 , struct V_55 * V_56 )
{
char * V_83 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 )
return - V_69 ;
if ( F_45 ( V_83 , L_9 ) ) {
V_56 -> V_66 = V_67 ;
} else if ( F_45 ( V_83 , L_10 ) ) {
V_56 -> V_66 = V_68 ;
} else {
F_46 ( L_11 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_47 ( char * * V_82 , struct V_55 * V_56 )
{
char * V_83 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 )
return - V_69 ;
if ( F_45 ( V_83 , L_12 ) ) {
V_56 -> V_84 = V_85 ;
} else if ( F_45 ( V_83 , L_13 ) ) {
V_56 -> V_84 = V_86 ;
} else {
F_46 ( L_14 ) ;
return - V_69 ;
}
return 0 ;
}
static int F_48 ( char * * V_82 , struct V_55 * V_56 )
{
char * V_83 ;
T_2 V_64 , V_65 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 )
return - V_69 ;
if ( F_45 ( V_83 , L_15 ) ) {
V_56 -> V_57 = V_62 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 ) {
F_46 ( L_16 ) ;
return - V_69 ;
}
if ( F_49 ( V_83 , 0 , & V_64 ) ) {
F_46 ( L_17 ) ;
return - V_69 ;
}
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 ) {
F_46 ( L_18 ) ;
return - V_69 ;
}
if ( F_49 ( V_83 , 0 , & V_65 ) ) {
F_46 ( L_19 ) ;
return - V_69 ;
}
V_56 -> V_59 . V_63 . V_64 = F_50 ( V_64 ) ;
V_56 -> V_59 . V_63 . V_65 = F_50 ( V_65 ) ;
} else if ( F_45 ( V_83 , L_20 ) ) {
V_56 -> V_57 = V_61 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 ) {
F_46 ( L_18 ) ;
return - V_69 ;
}
if ( F_49 ( V_83 , 0 , & V_65 ) ) {
F_46 ( L_19 ) ;
return - V_69 ;
}
V_56 -> V_59 . V_21 = F_50 ( V_65 ) ;
} else if ( F_45 ( V_83 , L_21 ) ) {
V_56 -> V_57 = V_58 ;
V_83 = F_44 ( V_82 , L_8 ) ;
if ( ! V_83 ) {
F_46 ( L_16 ) ;
return - V_69 ;
}
if ( F_49 ( V_83 , 0 , & V_64 ) ) {
F_46 ( L_17 ) ;
return - V_69 ;
}
V_56 -> V_59 . V_60 = F_50 ( V_64 ) ;
} else {
F_46 ( L_22 ) ;
return - V_69 ;
}
return 0 ;
}
static T_3 F_51 ( struct V_87 * V_87 , struct V_88 * V_89 ,
const char * V_90 , T_4 V_64 )
{
struct V_55 * V_56 ;
struct V_77 V_78 ;
char * V_91 ;
char * args ;
int V_29 ;
args = V_91 = F_6 ( V_90 , V_7 ) ;
V_56 = F_4 ( sizeof( * V_56 ) , V_7 ) ;
if ( ! V_56 || ! V_91 ) {
F_52 ( L_23 ) ;
F_2 ( V_91 ) ;
F_2 ( V_56 ) ;
return - V_81 ;
}
V_29 = F_43 ( & args , V_56 ) ;
if ( V_29 )
goto V_92;
V_29 = F_47 ( & args , V_56 ) ;
if ( V_29 )
goto V_92;
V_29 = F_48 ( & args , V_56 ) ;
if ( V_29 )
goto V_92;
F_53 ( & V_78 ) ;
F_39 ( V_56 , & V_78 , & V_29 ) ;
F_54 ( & V_78 ) ;
V_92:
F_2 ( V_91 ) ;
F_2 ( V_56 ) ;
if ( V_29 )
F_46 ( L_24 , V_90 ) ;
return V_29 ? V_29 : V_64 ;
}
static T_3 F_55 ( struct V_87 * V_87 , struct V_88 * V_89 ,
char * V_90 )
{
return sprintf ( V_90 , L_25 , L_26 ) ;
}
static int T_5 F_56 ( void )
{
V_80 = F_57 ( L_27 ,
V_93 , 1 ) ;
return F_58 ( V_94 , & V_95 . V_89 ) ;
}
