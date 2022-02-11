static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
unsigned char * V_4 = ( unsigned char * ) V_2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < sizeof( struct V_1 ) - 2 ; ++ V_5 , ++ V_4 )
V_3 += * V_4 ;
V_2 -> V_3 = F_2 ( V_3 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
int V_8 ;
T_2 V_9 ;
do {
F_4 ( 80 ) ;
V_8 = F_5 ( V_7 ,
V_10 , & V_9 , 1 ) ;
if ( V_8 )
return V_8 ;
} while ( V_9 == 3 );
if ( V_9 == 1 )
return 0 ;
F_6 ( V_7 , L_1 , V_9 ) ;
return - V_11 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_1 * V_12 )
{
return F_5 ( V_7 , V_13 , V_12 ,
sizeof( struct V_1 ) ) ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_1 const * V_2 )
{
int V_8 ;
V_8 = F_9 ( V_7 , V_13 ,
V_2 , sizeof( struct V_1 ) ) ;
if ( V_8 )
return V_8 ;
return F_3 ( V_7 ) ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_14 * V_12 , int V_15 )
{
int V_16 ;
if ( V_15 < 1 || V_15 > 5 )
return - V_17 ;
V_16 = F_11 ( V_7 , F_12 ( V_7 , 0 ) ,
V_18 ,
V_19 | V_20 | V_21 ,
V_22 , V_15 , V_12 ,
sizeof( struct V_14 ) , V_23 ) ;
if ( V_16 != sizeof( struct V_14 ) )
return - V_11 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_14 const * V_24 , int V_15 )
{
int V_16 ;
if ( V_15 < 1 || V_15 > 5 )
return - V_17 ;
V_16 = F_11 ( V_7 , F_14 ( V_7 , 0 ) ,
V_25 ,
V_19 | V_20 | V_26 ,
V_22 , V_15 , ( void * ) V_24 ,
sizeof( struct V_14 ) ,
V_23 ) ;
if ( V_16 != sizeof( struct V_14 ) )
return V_16 ;
if ( F_3 ( V_7 ) )
return - V_11 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , int * V_27 )
{
int V_8 ;
T_2 V_9 ;
V_8 = F_5 ( V_7 , V_28 , & V_9 , 1 ) ;
if ( V_8 )
return V_8 ;
* V_27 = ( int ) V_9 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , int * V_27 )
{
int V_8 ;
T_1 V_9 ;
V_8 = F_5 ( V_7 , V_29 ,
& V_9 , 2 ) ;
if ( V_8 )
return V_8 ;
* V_27 = F_17 ( V_9 ) ;
return 0 ;
}
static T_3 F_18 ( struct V_30 * V_31 , struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_12 ,
T_4 V_36 , T_5 V_37 ) {
struct V_38 * V_39 =
F_19 ( V_33 , struct V_38 , V_33 ) -> V_40 -> V_40 ;
struct V_41 * V_42 = F_20 ( F_21 ( V_39 ) ) ;
if ( V_36 >= sizeof( struct V_1 ) )
return 0 ;
if ( V_36 + V_37 > sizeof( struct V_1 ) )
V_37 = sizeof( struct V_1 ) - V_36 ;
F_22 ( & V_42 -> V_43 ) ;
memcpy ( V_12 , ( ( char const * ) & V_42 -> V_2 ) + V_36 , V_37 ) ;
F_23 ( & V_42 -> V_43 ) ;
return V_37 ;
}
static T_3 F_24 ( struct V_30 * V_31 , struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_12 ,
T_4 V_36 , T_5 V_37 ) {
struct V_38 * V_39 =
F_19 ( V_33 , struct V_38 , V_33 ) -> V_40 -> V_40 ;
struct V_41 * V_42 = F_20 ( F_21 ( V_39 ) ) ;
struct V_6 * V_7 = F_25 ( F_26 ( V_39 ) ) ;
int V_8 = 0 , V_44 ;
if ( V_36 != 0 || V_37 != sizeof( struct V_1 ) )
return - V_17 ;
F_22 ( & V_42 -> V_43 ) ;
V_44 = memcmp ( V_12 , & V_42 -> V_2 , sizeof( struct V_1 ) ) ;
if ( V_44 ) {
V_8 = F_8 ( V_7 ,
(struct V_1 const * ) V_12 ) ;
if ( ! V_8 )
memcpy ( & V_42 -> V_2 , V_12 ,
sizeof( struct V_1 ) ) ;
}
F_23 ( & V_42 -> V_43 ) ;
if ( V_8 )
return V_8 ;
V_42 -> V_45 = V_42 -> V_2 . V_46 ;
V_42 -> V_47 = V_42 -> V_48 [ V_42 -> V_45 - 1 ] . V_49 ;
return sizeof( struct V_1 ) ;
}
static T_3 F_27 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_12 , T_4 V_36 , T_5 V_37 ) {
struct V_38 * V_39 =
F_19 ( V_33 , struct V_38 , V_33 ) -> V_40 -> V_40 ;
struct V_41 * V_42 = F_20 ( F_21 ( V_39 ) ) ;
if ( V_36 >= sizeof( struct V_14 ) )
return 0 ;
if ( V_36 + V_37 > sizeof( struct V_14 ) )
V_37 = sizeof( struct V_14 ) - V_36 ;
F_22 ( & V_42 -> V_43 ) ;
memcpy ( V_12 , ( ( char const * ) & V_42 -> V_48 [ * ( V_50 * ) ( V_35 -> V_51 ) ] ) + V_36 , V_37 ) ;
F_23 ( & V_42 -> V_43 ) ;
return V_37 ;
}
static T_3 F_28 ( struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_34 * V_35 ,
char * V_12 , T_4 V_36 , T_5 V_37 ) {
struct V_38 * V_39 =
F_19 ( V_33 , struct V_38 , V_33 ) -> V_40 -> V_40 ;
struct V_41 * V_42 = F_20 ( F_21 ( V_39 ) ) ;
struct V_6 * V_7 = F_25 ( F_26 ( V_39 ) ) ;
struct V_14 * V_24 ;
int V_8 = 0 , V_44 ;
if ( V_36 != 0 || V_37 != sizeof( struct V_14 ) )
return - V_17 ;
V_24 = & V_42 -> V_48 [ * ( V_50 * ) ( V_35 -> V_51 ) ] ;
F_22 ( & V_42 -> V_43 ) ;
V_44 = memcmp ( V_12 , V_24 , sizeof( struct V_14 ) ) ;
if ( V_44 ) {
V_8 = F_13 ( V_7 ,
(struct V_14 const * ) V_12 ,
* ( V_50 * ) ( V_35 -> V_51 ) + 1 ) ;
if ( ! V_8 )
memcpy ( V_24 , V_12 , sizeof( struct V_14 ) ) ;
}
F_23 ( & V_42 -> V_43 ) ;
if ( V_8 )
return V_8 ;
return sizeof( struct V_14 ) ;
}
static T_3 F_29 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 =
F_20 ( F_21 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_12 , V_53 , L_2 , V_42 -> V_45 ) ;
}
static T_3 F_30 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 =
F_20 ( F_21 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_12 , V_53 , L_2 , V_42 -> V_47 ) ;
}
static T_3 F_31 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 ;
struct V_6 * V_7 ;
int V_54 = 0 ;
int V_8 ;
V_39 = V_39 -> V_40 -> V_40 ;
V_42 = F_20 ( F_21 ( V_39 ) ) ;
V_7 = F_25 ( F_26 ( V_39 ) ) ;
F_22 ( & V_42 -> V_43 ) ;
V_8 = F_15 ( V_7 , & V_54 ) ;
F_23 ( & V_42 -> V_43 ) ;
if ( V_8 )
return V_8 ;
return snprintf ( V_12 , V_53 , L_2 , V_54 ) ;
}
static T_3 F_32 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 =
F_20 ( F_21 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_12 , V_53 , L_2 , V_42 -> V_55 ) ;
}
static T_3 F_33 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 =
F_20 ( F_21 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_12 , V_53 , L_2 , V_42 -> V_2 . V_56 ) ;
}
static int F_34 ( struct V_6 * V_7 , int V_15 )
{
unsigned char V_57 ;
V_57 = V_15 ;
return F_9 ( V_7 , V_58 , & V_57 , 1 ) ;
}
static T_3 F_35 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char const * V_12 , T_5 V_59 )
{
struct V_41 * V_42 ;
struct V_6 * V_7 ;
int V_8 ;
unsigned long V_60 ;
V_39 = V_39 -> V_40 -> V_40 ;
V_42 = F_20 ( F_21 ( V_39 ) ) ;
V_7 = F_25 ( F_26 ( V_39 ) ) ;
V_8 = F_36 ( V_12 , 10 , & V_60 ) ;
if ( V_8 )
return V_8 ;
if ( V_60 != 0 && V_60 != 1 )
return - V_17 ;
F_22 ( & V_42 -> V_43 ) ;
if ( V_60 == 1 ) {
V_8 = F_34 ( V_7 , 1 ) ;
if ( V_8 )
goto V_61;
V_8 = F_34 ( V_7 , 2 ) ;
if ( V_8 )
goto V_61;
F_37 ( 5 ) ;
V_8 = F_34 ( V_7 , 3 ) ;
if ( V_8 )
goto V_61;
V_8 = F_34 ( V_7 , 0 ) ;
if ( V_8 )
goto V_61;
V_8 = F_34 ( V_7 , 4 ) ;
if ( V_8 )
goto V_61;
F_37 ( 1 ) ;
}
V_8 = F_7 ( V_7 , & V_42 -> V_2 ) ;
if ( V_8 )
goto V_62;
if ( V_42 -> V_2 . V_56 != V_60 ) {
V_42 -> V_2 . V_56 = V_60 ;
F_1 ( & V_42 -> V_2 ) ;
V_8 = F_8 ( V_7 , & V_42 -> V_2 ) ;
if ( V_8 ) {
F_6 ( V_7 , L_3 ) ;
V_8 = F_7 ( V_7 , & V_42 -> V_2 ) ;
if ( V_8 )
goto V_62;
goto V_61;
}
}
V_8 = V_59 ;
V_62:
F_6 ( V_7 , L_4 ) ;
V_61:
F_23 ( & V_42 -> V_43 ) ;
return V_8 ;
}
static T_3 F_38 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char * V_12 )
{
struct V_41 * V_42 =
F_20 ( F_21 ( V_39 -> V_40 -> V_40 ) ) ;
return snprintf ( V_12 , V_53 , L_2 , V_42 -> V_2 . V_46 ) ;
}
static T_3 F_39 ( struct V_38 * V_39 ,
struct V_52 * V_35 , char const * V_12 , T_5 V_59 )
{
struct V_41 * V_42 ;
struct V_6 * V_7 ;
int V_8 ;
unsigned long V_63 ;
V_39 = V_39 -> V_40 -> V_40 ;
V_42 = F_20 ( F_21 ( V_39 ) ) ;
V_7 = F_25 ( F_26 ( V_39 ) ) ;
V_8 = F_36 ( V_12 , 10 , & V_63 ) ;
if ( V_8 )
return V_8 ;
if ( V_63 < 1 || V_63 > 5 )
return - V_17 ;
F_22 ( & V_42 -> V_43 ) ;
V_42 -> V_2 . V_46 = V_63 ;
F_1 ( & V_42 -> V_2 ) ;
V_8 = F_8 ( V_7 , & V_42 -> V_2 ) ;
F_23 ( & V_42 -> V_43 ) ;
if ( V_8 )
return V_8 ;
V_42 -> V_45 = V_63 ;
V_42 -> V_47 = V_42 -> V_48 [ V_42 -> V_45 - 1 ] . V_49 ;
return V_59 ;
}
static int F_40 ( struct V_6 * V_7 ,
struct V_41 * V_42 )
{
V_50 V_5 ;
int V_8 ;
F_41 ( & V_42 -> V_43 ) ;
for ( V_5 = 0 ; V_5 < 5 ; ++ V_5 ) {
V_8 = F_10 ( V_7 , & V_42 -> V_48 [ V_5 ] , V_5 + 1 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_7 ( V_7 , & V_42 -> V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_7 , & V_42 -> V_55 ) ;
if ( V_8 )
return V_8 ;
V_42 -> V_45 = V_42 -> V_2 . V_46 ;
V_42 -> V_47 = V_42 -> V_48 [ V_42 -> V_45 ] . V_49 ;
return 0 ;
}
static int F_42 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_26 ( V_65 -> V_39 . V_40 ) ;
struct V_6 * V_7 = F_25 ( V_67 ) ;
struct V_41 * V_42 ;
int V_8 ;
if ( V_67 -> V_68 -> V_69 . V_70
== V_71 ) {
V_42 = F_43 ( sizeof( * V_42 ) , V_72 ) ;
if ( ! V_42 ) {
F_6 ( V_65 , L_5 ) ;
return - V_73 ;
}
F_44 ( V_65 , V_42 ) ;
V_8 = F_40 ( V_7 , V_42 ) ;
if ( V_8 ) {
F_6 ( V_65 , L_6 ) ;
goto V_74;
}
V_8 = F_45 ( V_75 , V_65 ,
sizeof( struct V_76 ) ) ;
if ( V_8 < 0 ) {
F_6 ( V_65 , L_7 ) ;
} else {
V_42 -> V_77 = 1 ;
V_42 -> V_78 = V_8 ;
}
} else {
F_44 ( V_65 , NULL ) ;
}
return 0 ;
V_74:
F_46 ( V_42 ) ;
return V_8 ;
}
static void F_47 ( struct V_64 * V_65 )
{
struct V_66 * V_67 = F_26 ( V_65 -> V_39 . V_40 ) ;
struct V_41 * V_42 ;
if ( V_67 -> V_68 -> V_69 . V_70
== V_71 ) {
V_42 = F_20 ( V_65 ) ;
if ( V_42 -> V_77 )
F_48 ( V_42 -> V_78 ) ;
F_46 ( F_20 ( V_65 ) ) ;
}
}
static int F_49 ( struct V_64 * V_65 , const struct V_79 * V_80 )
{
int V_8 ;
V_8 = F_50 ( V_65 ) ;
if ( V_8 ) {
F_6 ( V_65 , L_8 ) ;
goto exit;
}
V_8 = F_51 ( V_65 , V_81 ) ;
if ( V_8 ) {
F_6 ( V_65 , L_9 ) ;
goto exit;
}
V_8 = F_42 ( V_65 ) ;
if ( V_8 ) {
F_6 ( V_65 , L_10 ) ;
goto V_82;
}
return 0 ;
V_82:
F_52 ( V_65 ) ;
exit:
return V_8 ;
}
static void F_53 ( struct V_64 * V_65 )
{
F_47 ( V_65 ) ;
F_52 ( V_65 ) ;
}
static void F_54 ( struct V_41 * V_42 ,
struct V_83 const * V_84 )
{
switch ( V_84 -> V_84 ) {
case V_85 :
case V_86 :
V_42 -> V_45 = V_84 -> V_57 ;
V_42 -> V_47 = V_42 -> V_48 [ V_42 -> V_45 - 1 ] .
V_49 ;
break;
case V_87 :
case V_88 :
V_42 -> V_47 = V_84 -> V_57 ;
break;
}
}
static void F_55 ( struct V_41 const * V_42 ,
struct V_83 const * V_84 )
{
struct V_76 V_89 ;
switch ( V_84 -> V_84 ) {
case V_85 :
case V_87 :
case V_86 :
case V_88 :
V_89 . V_84 = V_84 -> V_84 ;
V_89 . V_57 = V_84 -> V_57 ;
V_89 . V_90 = 0 ;
F_56 ( V_42 -> V_78 ,
( T_2 * ) & V_89 ) ;
break;
case V_91 :
if ( V_84 -> V_57 == V_92 ) {
V_89 . V_84 = V_91 ;
V_89 . V_57 = V_42 -> V_45 ;
V_89 . V_90 = V_84 -> V_93 ;
F_56 ( V_42 -> V_78 ,
( T_2 * ) & V_89 ) ;
}
break;
}
}
static int F_57 ( struct V_64 * V_65 , struct V_94 * V_95 ,
T_6 * V_9 , int V_59 )
{
struct V_41 * V_42 = F_20 ( V_65 ) ;
struct V_83 * V_84 = (struct V_83 * ) V_9 ;
if ( V_59 != sizeof( struct V_83 ) )
return 0 ;
if ( memcmp ( & V_42 -> V_96 . V_97 , & V_84 -> V_97 , 5 ) )
memcpy ( & V_42 -> V_96 , V_84 ,
sizeof( struct V_83 ) ) ;
else
memset ( & V_84 -> V_97 , 0 , 5 ) ;
F_54 ( V_42 , V_84 ) ;
if ( V_42 -> V_77 )
F_55 ( V_42 , V_84 ) ;
return 0 ;
}
static int T_7 F_58 ( void )
{
int V_8 ;
V_75 = F_59 ( V_98 , L_11 ) ;
if ( F_60 ( V_75 ) )
return F_61 ( V_75 ) ;
V_75 -> V_99 = V_100 ;
V_75 -> V_101 = V_102 ;
V_8 = F_62 ( & V_103 ) ;
if ( V_8 )
F_63 ( V_75 ) ;
return V_8 ;
}
static void T_8 F_64 ( void )
{
F_65 ( & V_103 ) ;
F_63 ( V_75 ) ;
}
