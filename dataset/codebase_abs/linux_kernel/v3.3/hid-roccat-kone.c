static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = V_2 -> V_6 [ V_3 - 1 ] . V_7 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_8 V_9 ;
V_9 . V_10 = V_11 ;
V_9 . V_12 = V_3 ;
V_9 . V_13 = 0 ;
F_3 ( V_2 -> V_14 , ( V_15 * ) & V_9 ) ;
}
static int F_4 ( struct V_16 * V_17 , T_1 V_18 ,
void * V_19 , T_1 V_20 )
{
char * V_21 ;
int V_22 ;
V_21 = F_5 ( V_20 , V_23 ) ;
if ( V_21 == NULL )
return - V_24 ;
V_22 = F_6 ( V_17 , F_7 ( V_17 , 0 ) ,
V_25 ,
V_26 | V_27 | V_28 ,
V_18 , 0 , V_21 , V_20 , V_29 ) ;
memcpy ( V_19 , V_21 , V_20 ) ;
F_8 ( V_21 ) ;
return ( ( V_22 < 0 ) ? V_22 : ( ( V_22 != V_20 ) ? - V_30 : 0 ) ) ;
}
static int F_9 ( struct V_16 * V_17 , T_1 V_18 ,
void const * V_19 , T_1 V_20 )
{
char * V_21 ;
int V_22 ;
V_21 = F_10 ( V_19 , V_20 , V_23 ) ;
if ( V_21 == NULL )
return - V_24 ;
V_22 = F_6 ( V_17 , F_11 ( V_17 , 0 ) ,
V_31 ,
V_26 | V_27 | V_32 ,
V_18 , 0 , V_21 , V_20 , V_29 ) ;
F_8 ( V_21 ) ;
return ( ( V_22 < 0 ) ? V_22 : ( ( V_22 != V_20 ) ? - V_30 : 0 ) ) ;
}
static void F_12 ( struct V_33 * V_34 )
{
T_2 V_35 = 0 ;
unsigned char * V_36 = ( unsigned char * ) V_34 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < sizeof( struct V_33 ) - 2 ; ++ V_37 , ++ V_36 )
V_35 += * V_36 ;
V_34 -> V_35 = F_13 ( V_35 ) ;
}
static int F_14 ( struct V_16 * V_17 )
{
int V_38 ;
V_15 V_19 ;
do {
F_15 ( 80 ) ;
V_38 = F_4 ( V_17 ,
V_39 , & V_19 , 1 ) ;
if ( V_38 )
return V_38 ;
} while ( V_19 == 3 );
if ( V_19 == 1 )
return 0 ;
F_16 ( V_17 , L_1 , V_19 ) ;
return - V_30 ;
}
static int F_17 ( struct V_16 * V_17 ,
struct V_33 * V_21 )
{
return F_4 ( V_17 , V_40 , V_21 ,
sizeof( struct V_33 ) ) ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_33 const * V_34 )
{
int V_38 ;
V_38 = F_9 ( V_17 , V_40 ,
V_34 , sizeof( struct V_33 ) ) ;
if ( V_38 )
return V_38 ;
return F_14 ( V_17 ) ;
}
static int F_19 ( struct V_16 * V_17 ,
struct V_41 * V_21 , int V_42 )
{
int V_22 ;
if ( V_42 < 1 || V_42 > 5 )
return - V_43 ;
V_22 = F_6 ( V_17 , F_7 ( V_17 , 0 ) ,
V_44 ,
V_26 | V_27 | V_28 ,
V_45 , V_42 , V_21 ,
sizeof( struct V_41 ) , V_29 ) ;
if ( V_22 != sizeof( struct V_41 ) )
return - V_30 ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_41 const * V_46 , int V_42 )
{
int V_22 ;
if ( V_42 < 1 || V_42 > 5 )
return - V_43 ;
V_22 = F_6 ( V_17 , F_11 ( V_17 , 0 ) ,
V_47 ,
V_26 | V_27 | V_32 ,
V_45 , V_42 , ( void * ) V_46 ,
sizeof( struct V_41 ) ,
V_29 ) ;
if ( V_22 != sizeof( struct V_41 ) )
return V_22 ;
if ( F_14 ( V_17 ) )
return - V_30 ;
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , int * V_48 )
{
int V_38 ;
V_15 V_19 ;
V_38 = F_4 ( V_17 , V_49 , & V_19 , 1 ) ;
if ( V_38 )
return V_38 ;
* V_48 = ( int ) V_19 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , int * V_48 )
{
int V_38 ;
T_2 V_19 ;
V_38 = F_4 ( V_17 , V_50 ,
& V_19 , 2 ) ;
if ( V_38 )
return V_38 ;
* V_48 = F_23 ( V_19 ) ;
return 0 ;
}
static T_3 F_24 ( struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_55 * V_56 , char * V_21 ,
T_4 V_57 , T_5 V_58 ) {
struct V_59 * V_60 =
F_25 ( V_54 , struct V_59 , V_54 ) -> V_61 -> V_61 ;
struct V_1 * V_2 = F_26 ( F_27 ( V_60 ) ) ;
if ( V_57 >= sizeof( struct V_33 ) )
return 0 ;
if ( V_57 + V_58 > sizeof( struct V_33 ) )
V_58 = sizeof( struct V_33 ) - V_57 ;
F_28 ( & V_2 -> V_62 ) ;
memcpy ( V_21 , ( ( char const * ) & V_2 -> V_34 ) + V_57 , V_58 ) ;
F_29 ( & V_2 -> V_62 ) ;
return V_58 ;
}
static T_3 F_30 ( struct V_51 * V_52 , struct V_53 * V_54 ,
struct V_55 * V_56 , char * V_21 ,
T_4 V_57 , T_5 V_58 ) {
struct V_59 * V_60 =
F_25 ( V_54 , struct V_59 , V_54 ) -> V_61 -> V_61 ;
struct V_1 * V_2 = F_26 ( F_27 ( V_60 ) ) ;
struct V_16 * V_17 = F_31 ( F_32 ( V_60 ) ) ;
int V_38 = 0 , V_63 , V_64 ;
if ( V_57 != 0 || V_58 != sizeof( struct V_33 ) )
return - V_43 ;
F_28 ( & V_2 -> V_62 ) ;
V_63 = memcmp ( V_21 , & V_2 -> V_34 , sizeof( struct V_33 ) ) ;
if ( V_63 ) {
V_38 = F_18 ( V_17 ,
(struct V_33 const * ) V_21 ) ;
if ( V_38 ) {
F_29 ( & V_2 -> V_62 ) ;
return V_38 ;
}
V_64 = V_2 -> V_34 . V_65 ;
memcpy ( & V_2 -> V_34 , V_21 , sizeof( struct V_33 ) ) ;
F_1 ( V_2 , V_2 -> V_34 . V_65 ) ;
if ( V_2 -> V_34 . V_65 != V_64 )
F_2 ( V_2 , V_2 -> V_34 . V_65 ) ;
}
F_29 ( & V_2 -> V_62 ) ;
return sizeof( struct V_33 ) ;
}
static T_3 F_33 ( struct V_51 * V_52 ,
struct V_53 * V_54 , struct V_55 * V_56 ,
char * V_21 , T_4 V_57 , T_5 V_58 ) {
struct V_59 * V_60 =
F_25 ( V_54 , struct V_59 , V_54 ) -> V_61 -> V_61 ;
struct V_1 * V_2 = F_26 ( F_27 ( V_60 ) ) ;
if ( V_57 >= sizeof( struct V_41 ) )
return 0 ;
if ( V_57 + V_58 > sizeof( struct V_41 ) )
V_58 = sizeof( struct V_41 ) - V_57 ;
F_28 ( & V_2 -> V_62 ) ;
memcpy ( V_21 , ( ( char const * ) & V_2 -> V_6 [ * ( T_1 * ) ( V_56 -> V_66 ) ] ) + V_57 , V_58 ) ;
F_29 ( & V_2 -> V_62 ) ;
return V_58 ;
}
static T_3 F_34 ( struct V_51 * V_52 ,
struct V_53 * V_54 , struct V_55 * V_56 ,
char * V_21 , T_4 V_57 , T_5 V_58 ) {
struct V_59 * V_60 =
F_25 ( V_54 , struct V_59 , V_54 ) -> V_61 -> V_61 ;
struct V_1 * V_2 = F_26 ( F_27 ( V_60 ) ) ;
struct V_16 * V_17 = F_31 ( F_32 ( V_60 ) ) ;
struct V_41 * V_46 ;
int V_38 = 0 , V_63 ;
if ( V_57 != 0 || V_58 != sizeof( struct V_41 ) )
return - V_43 ;
V_46 = & V_2 -> V_6 [ * ( T_1 * ) ( V_56 -> V_66 ) ] ;
F_28 ( & V_2 -> V_62 ) ;
V_63 = memcmp ( V_21 , V_46 , sizeof( struct V_41 ) ) ;
if ( V_63 ) {
V_38 = F_20 ( V_17 ,
(struct V_41 const * ) V_21 ,
* ( T_1 * ) ( V_56 -> V_66 ) + 1 ) ;
if ( ! V_38 )
memcpy ( V_46 , V_21 , sizeof( struct V_41 ) ) ;
}
F_29 ( & V_2 -> V_62 ) ;
if ( V_38 )
return V_38 ;
return sizeof( struct V_41 ) ;
}
static T_3 F_35 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 =
F_26 ( F_27 ( V_60 -> V_61 -> V_61 ) ) ;
return snprintf ( V_21 , V_68 , L_2 , V_2 -> V_4 ) ;
}
static T_3 F_36 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 =
F_26 ( F_27 ( V_60 -> V_61 -> V_61 ) ) ;
return snprintf ( V_21 , V_68 , L_2 , V_2 -> V_5 ) ;
}
static T_3 F_37 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_69 = 0 ;
int V_38 ;
V_60 = V_60 -> V_61 -> V_61 ;
V_2 = F_26 ( F_27 ( V_60 ) ) ;
V_17 = F_31 ( F_32 ( V_60 ) ) ;
F_28 ( & V_2 -> V_62 ) ;
V_38 = F_21 ( V_17 , & V_69 ) ;
F_29 ( & V_2 -> V_62 ) ;
if ( V_38 )
return V_38 ;
return snprintf ( V_21 , V_68 , L_2 , V_69 ) ;
}
static T_3 F_38 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 =
F_26 ( F_27 ( V_60 -> V_61 -> V_61 ) ) ;
return snprintf ( V_21 , V_68 , L_2 , V_2 -> V_70 ) ;
}
static T_3 F_39 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 =
F_26 ( F_27 ( V_60 -> V_61 -> V_61 ) ) ;
return snprintf ( V_21 , V_68 , L_2 , V_2 -> V_34 . V_71 ) ;
}
static int F_40 ( struct V_16 * V_17 , int V_42 )
{
unsigned char V_12 ;
V_12 = V_42 ;
return F_9 ( V_17 , V_72 , & V_12 , 1 ) ;
}
static T_3 F_41 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char const * V_21 , T_5 V_20 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_38 ;
unsigned long V_73 ;
V_60 = V_60 -> V_61 -> V_61 ;
V_2 = F_26 ( F_27 ( V_60 ) ) ;
V_17 = F_31 ( F_32 ( V_60 ) ) ;
V_38 = F_42 ( V_21 , 10 , & V_73 ) ;
if ( V_38 )
return V_38 ;
if ( V_73 != 0 && V_73 != 1 )
return - V_43 ;
F_28 ( & V_2 -> V_62 ) ;
if ( V_73 == 1 ) {
V_38 = F_40 ( V_17 , 1 ) ;
if ( V_38 )
goto V_74;
V_38 = F_40 ( V_17 , 2 ) ;
if ( V_38 )
goto V_74;
F_43 ( 5 ) ;
V_38 = F_40 ( V_17 , 3 ) ;
if ( V_38 )
goto V_74;
V_38 = F_40 ( V_17 , 0 ) ;
if ( V_38 )
goto V_74;
V_38 = F_40 ( V_17 , 4 ) ;
if ( V_38 )
goto V_74;
F_43 ( 1 ) ;
}
V_38 = F_17 ( V_17 , & V_2 -> V_34 ) ;
if ( V_38 )
goto V_75;
if ( V_2 -> V_34 . V_71 != V_73 ) {
V_2 -> V_34 . V_71 = V_73 ;
F_12 ( & V_2 -> V_34 ) ;
V_38 = F_18 ( V_17 , & V_2 -> V_34 ) ;
if ( V_38 ) {
F_16 ( V_17 , L_3 ) ;
V_38 = F_17 ( V_17 , & V_2 -> V_34 ) ;
if ( V_38 )
goto V_75;
goto V_74;
}
F_1 ( V_2 , V_2 -> V_34 . V_65 ) ;
}
V_38 = V_20 ;
V_75:
F_16 ( V_17 , L_4 ) ;
V_74:
F_29 ( & V_2 -> V_62 ) ;
return V_38 ;
}
static T_3 F_44 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char * V_21 )
{
struct V_1 * V_2 =
F_26 ( F_27 ( V_60 -> V_61 -> V_61 ) ) ;
return snprintf ( V_21 , V_68 , L_2 , V_2 -> V_34 . V_65 ) ;
}
static T_3 F_45 ( struct V_59 * V_60 ,
struct V_67 * V_56 , char const * V_21 , T_5 V_20 )
{
struct V_1 * V_2 ;
struct V_16 * V_17 ;
int V_38 ;
unsigned long V_76 ;
V_60 = V_60 -> V_61 -> V_61 ;
V_2 = F_26 ( F_27 ( V_60 ) ) ;
V_17 = F_31 ( F_32 ( V_60 ) ) ;
V_38 = F_42 ( V_21 , 10 , & V_76 ) ;
if ( V_38 )
return V_38 ;
if ( V_76 < 1 || V_76 > 5 )
return - V_43 ;
F_28 ( & V_2 -> V_62 ) ;
V_2 -> V_34 . V_65 = V_76 ;
F_12 ( & V_2 -> V_34 ) ;
V_38 = F_18 ( V_17 , & V_2 -> V_34 ) ;
if ( V_38 ) {
F_29 ( & V_2 -> V_62 ) ;
return V_38 ;
}
F_1 ( V_2 , V_76 ) ;
F_2 ( V_2 , V_76 ) ;
F_29 ( & V_2 -> V_62 ) ;
return V_20 ;
}
static int F_46 ( struct V_16 * V_17 ,
struct V_1 * V_2 )
{
T_1 V_37 ;
int V_38 ;
F_47 ( & V_2 -> V_62 ) ;
for ( V_37 = 0 ; V_37 < 5 ; ++ V_37 ) {
V_38 = F_19 ( V_17 , & V_2 -> V_6 [ V_37 ] , V_37 + 1 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_17 ( V_17 , & V_2 -> V_34 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_22 ( V_17 , & V_2 -> V_70 ) ;
if ( V_38 )
return V_38 ;
F_1 ( V_2 , V_2 -> V_34 . V_65 ) ;
return 0 ;
}
static int F_48 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_32 ( V_78 -> V_60 . V_61 ) ;
struct V_16 * V_17 = F_31 ( V_80 ) ;
struct V_1 * V_2 ;
int V_38 ;
if ( V_80 -> V_81 -> V_82 . V_83
== V_84 ) {
V_2 = F_49 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 ) {
F_16 ( V_78 , L_5 ) ;
return - V_24 ;
}
F_50 ( V_78 , V_2 ) ;
V_38 = F_46 ( V_17 , V_2 ) ;
if ( V_38 ) {
F_16 ( V_78 , L_6 ) ;
goto V_85;
}
V_38 = F_51 ( V_86 , V_78 ,
sizeof( struct V_8 ) ) ;
if ( V_38 < 0 ) {
F_16 ( V_78 , L_7 ) ;
} else {
V_2 -> V_87 = 1 ;
V_2 -> V_14 = V_38 ;
}
} else {
F_50 ( V_78 , NULL ) ;
}
return 0 ;
V_85:
F_8 ( V_2 ) ;
return V_38 ;
}
static void F_52 ( struct V_77 * V_78 )
{
struct V_79 * V_80 = F_32 ( V_78 -> V_60 . V_61 ) ;
struct V_1 * V_2 ;
if ( V_80 -> V_81 -> V_82 . V_83
== V_84 ) {
V_2 = F_26 ( V_78 ) ;
if ( V_2 -> V_87 )
F_53 ( V_2 -> V_14 ) ;
F_8 ( F_26 ( V_78 ) ) ;
}
}
static int F_54 ( struct V_77 * V_78 , const struct V_88 * V_89 )
{
int V_38 ;
V_38 = F_55 ( V_78 ) ;
if ( V_38 ) {
F_16 ( V_78 , L_8 ) ;
goto exit;
}
V_38 = F_56 ( V_78 , V_90 ) ;
if ( V_38 ) {
F_16 ( V_78 , L_9 ) ;
goto exit;
}
V_38 = F_48 ( V_78 ) ;
if ( V_38 ) {
F_16 ( V_78 , L_10 ) ;
goto V_91;
}
return 0 ;
V_91:
F_57 ( V_78 ) ;
exit:
return V_38 ;
}
static void F_58 ( struct V_77 * V_78 )
{
F_52 ( V_78 ) ;
F_57 ( V_78 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_92 const * V_10 )
{
switch ( V_10 -> V_10 ) {
case V_11 :
V_2 -> V_5 = V_2 -> V_6 [ V_10 -> V_12 - 1 ] .
V_7 ;
case V_93 :
V_2 -> V_4 = V_10 -> V_12 ;
break;
case V_94 :
case V_95 :
V_2 -> V_5 = V_10 -> V_12 ;
break;
}
}
static void F_60 ( struct V_1 const * V_2 ,
struct V_92 const * V_10 )
{
struct V_8 V_9 ;
switch ( V_10 -> V_10 ) {
case V_11 :
case V_94 :
case V_93 :
case V_95 :
V_9 . V_10 = V_10 -> V_10 ;
V_9 . V_12 = V_10 -> V_12 ;
V_9 . V_13 = 0 ;
F_3 ( V_2 -> V_14 ,
( V_15 * ) & V_9 ) ;
break;
case V_96 :
if ( V_10 -> V_12 == V_97 ) {
V_9 . V_10 = V_96 ;
V_9 . V_12 = V_2 -> V_4 ;
V_9 . V_13 = V_10 -> V_98 ;
F_3 ( V_2 -> V_14 ,
( V_15 * ) & V_9 ) ;
}
break;
}
}
static int F_61 ( struct V_77 * V_78 , struct V_99 * V_100 ,
T_6 * V_19 , int V_20 )
{
struct V_1 * V_2 = F_26 ( V_78 ) ;
struct V_92 * V_10 = (struct V_92 * ) V_19 ;
if ( V_20 != sizeof( struct V_92 ) )
return 0 ;
if ( V_2 == NULL )
return 0 ;
if ( memcmp ( & V_2 -> V_101 . V_102 , & V_10 -> V_102 , 5 ) )
memcpy ( & V_2 -> V_101 , V_10 ,
sizeof( struct V_92 ) ) ;
else
memset ( & V_10 -> V_102 , 0 , 5 ) ;
F_59 ( V_2 , V_10 ) ;
if ( V_2 -> V_87 )
F_60 ( V_2 , V_10 ) ;
return 0 ;
}
static int T_7 F_62 ( void )
{
int V_38 ;
V_86 = F_63 ( V_103 , L_11 ) ;
if ( F_64 ( V_86 ) )
return F_65 ( V_86 ) ;
V_86 -> V_104 = V_105 ;
V_86 -> V_106 = V_107 ;
V_38 = F_66 ( & V_108 ) ;
if ( V_38 )
F_67 ( V_86 ) ;
return V_38 ;
}
static void T_8 F_68 ( void )
{
F_69 ( & V_108 ) ;
F_67 ( V_86 ) ;
}
