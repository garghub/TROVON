static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_2 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_7 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
V_3 , 0 , V_6 , V_5 , V_14 ) ;
memcpy ( V_4 , V_6 , V_5 ) ;
F_5 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
void const * V_4 , T_1 V_5 )
{
char * V_6 ;
int V_7 ;
V_6 = F_2 ( V_5 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
memcpy ( V_6 , V_4 , V_5 ) ;
V_7 = F_3 ( V_2 , F_7 ( V_2 , 0 ) ,
V_16 ,
V_11 | V_12 | V_17 ,
V_3 , 0 , V_6 , V_5 , V_14 ) ;
F_5 ( V_6 ) ;
return ( ( V_7 < 0 ) ? V_7 : ( ( V_7 != V_5 ) ? - V_15 : 0 ) ) ;
}
static void F_8 ( struct V_18 * V_19 )
{
T_2 V_20 = 0 ;
unsigned char * V_21 = ( unsigned char * ) V_19 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < sizeof( struct V_18 ) - 2 ; ++ V_22 , ++ V_21 )
V_20 += * V_21 ;
V_19 -> V_20 = F_9 ( V_20 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_23 ;
T_3 V_4 ;
do {
F_11 ( 80 ) ;
V_23 = F_1 ( V_2 ,
V_24 , & V_4 , 1 ) ;
if ( V_23 )
return V_23 ;
} while ( V_4 == 3 );
if ( V_4 == 1 )
return 0 ;
F_12 ( V_2 , L_1 , V_4 ) ;
return - V_15 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_18 * V_6 )
{
return F_1 ( V_2 , V_25 , V_6 ,
sizeof( struct V_18 ) ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_18 const * V_19 )
{
int V_23 ;
V_23 = F_6 ( V_2 , V_25 ,
V_19 , sizeof( struct V_18 ) ) ;
if ( V_23 )
return V_23 ;
return F_10 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 * V_6 , int V_27 )
{
int V_7 ;
if ( V_27 < 1 || V_27 > 5 )
return - V_28 ;
V_7 = F_3 ( V_2 , F_4 ( V_2 , 0 ) ,
V_29 ,
V_11 | V_12 | V_13 ,
V_30 , V_27 , V_6 ,
sizeof( struct V_26 ) , V_14 ) ;
if ( V_7 != sizeof( struct V_26 ) )
return - V_15 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_26 const * V_31 , int V_27 )
{
int V_7 ;
if ( V_27 < 1 || V_27 > 5 )
return - V_28 ;
V_7 = F_3 ( V_2 , F_7 ( V_2 , 0 ) ,
V_32 ,
V_11 | V_12 | V_17 ,
V_30 , V_27 , ( void * ) V_31 ,
sizeof( struct V_26 ) ,
V_14 ) ;
if ( V_7 != sizeof( struct V_26 ) )
return V_7 ;
if ( F_10 ( V_2 ) )
return - V_15 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int * V_33 )
{
int V_23 ;
T_3 V_4 ;
V_23 = F_1 ( V_2 , V_34 , & V_4 , 1 ) ;
if ( V_23 )
return V_23 ;
* V_33 = ( int ) V_4 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int * V_33 )
{
int V_23 ;
T_2 V_4 ;
V_23 = F_1 ( V_2 , V_35 ,
& V_4 , 2 ) ;
if ( V_23 )
return V_23 ;
* V_33 = F_19 ( V_4 ) ;
return 0 ;
}
static T_4 F_20 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_6 ,
T_5 V_42 , T_6 V_43 ) {
struct V_44 * V_45 =
F_21 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_47 * V_48 = F_22 ( F_23 ( V_45 ) ) ;
if ( V_42 >= sizeof( struct V_18 ) )
return 0 ;
if ( V_42 + V_43 > sizeof( struct V_18 ) )
V_43 = sizeof( struct V_18 ) - V_42 ;
F_24 ( & V_48 -> V_49 ) ;
memcpy ( V_6 , ( ( char const * ) & V_48 -> V_19 ) + V_42 , V_43 ) ;
F_25 ( & V_48 -> V_49 ) ;
return V_43 ;
}
static T_4 F_26 ( struct V_36 * V_37 , struct V_38 * V_39 ,
struct V_40 * V_41 , char * V_6 ,
T_5 V_42 , T_6 V_43 ) {
struct V_44 * V_45 =
F_21 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_47 * V_48 = F_22 ( F_23 ( V_45 ) ) ;
struct V_1 * V_2 = F_27 ( F_28 ( V_45 ) ) ;
int V_23 = 0 , V_50 ;
if ( V_42 != 0 || V_43 != sizeof( struct V_18 ) )
return - V_28 ;
F_24 ( & V_48 -> V_49 ) ;
V_50 = memcmp ( V_6 , & V_48 -> V_19 , sizeof( struct V_18 ) ) ;
if ( V_50 ) {
V_23 = F_14 ( V_2 ,
(struct V_18 const * ) V_6 ) ;
if ( ! V_23 )
memcpy ( & V_48 -> V_19 , V_6 ,
sizeof( struct V_18 ) ) ;
}
F_25 ( & V_48 -> V_49 ) ;
if ( V_23 )
return V_23 ;
V_48 -> V_51 = V_48 -> V_19 . V_52 ;
V_48 -> V_53 = V_48 -> V_54 [ V_48 -> V_51 - 1 ] . V_55 ;
return sizeof( struct V_18 ) ;
}
static T_4 F_29 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 ,
char * V_6 , T_5 V_42 , T_6 V_43 ) {
struct V_44 * V_45 =
F_21 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_47 * V_48 = F_22 ( F_23 ( V_45 ) ) ;
if ( V_42 >= sizeof( struct V_26 ) )
return 0 ;
if ( V_42 + V_43 > sizeof( struct V_26 ) )
V_43 = sizeof( struct V_26 ) - V_42 ;
F_24 ( & V_48 -> V_49 ) ;
memcpy ( V_6 , ( ( char const * ) & V_48 -> V_54 [ * ( T_1 * ) ( V_41 -> V_56 ) ] ) + V_42 , V_43 ) ;
F_25 ( & V_48 -> V_49 ) ;
return V_43 ;
}
static T_4 F_30 ( struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_41 ,
char * V_6 , T_5 V_42 , T_6 V_43 ) {
struct V_44 * V_45 =
F_21 ( V_39 , struct V_44 , V_39 ) -> V_46 -> V_46 ;
struct V_47 * V_48 = F_22 ( F_23 ( V_45 ) ) ;
struct V_1 * V_2 = F_27 ( F_28 ( V_45 ) ) ;
struct V_26 * V_31 ;
int V_23 = 0 , V_50 ;
if ( V_42 != 0 || V_43 != sizeof( struct V_26 ) )
return - V_28 ;
V_31 = & V_48 -> V_54 [ * ( T_1 * ) ( V_41 -> V_56 ) ] ;
F_24 ( & V_48 -> V_49 ) ;
V_50 = memcmp ( V_6 , V_31 , sizeof( struct V_26 ) ) ;
if ( V_50 ) {
V_23 = F_16 ( V_2 ,
(struct V_26 const * ) V_6 ,
* ( T_1 * ) ( V_41 -> V_56 ) + 1 ) ;
if ( ! V_23 )
memcpy ( V_31 , V_6 , sizeof( struct V_26 ) ) ;
}
F_25 ( & V_48 -> V_49 ) ;
if ( V_23 )
return V_23 ;
return sizeof( struct V_26 ) ;
}
static T_4 F_31 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 =
F_22 ( F_23 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_6 , V_58 , L_2 , V_48 -> V_51 ) ;
}
static T_4 F_32 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 =
F_22 ( F_23 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_6 , V_58 , L_2 , V_48 -> V_53 ) ;
}
static T_4 F_33 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_59 = 0 ;
int V_23 ;
V_45 = V_45 -> V_46 -> V_46 ;
V_48 = F_22 ( F_23 ( V_45 ) ) ;
V_2 = F_27 ( F_28 ( V_45 ) ) ;
F_24 ( & V_48 -> V_49 ) ;
V_23 = F_17 ( V_2 , & V_59 ) ;
F_25 ( & V_48 -> V_49 ) ;
if ( V_23 )
return V_23 ;
return snprintf ( V_6 , V_58 , L_2 , V_59 ) ;
}
static T_4 F_34 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 =
F_22 ( F_23 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_6 , V_58 , L_2 , V_48 -> V_60 ) ;
}
static T_4 F_35 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 =
F_22 ( F_23 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_6 , V_58 , L_2 , V_48 -> V_19 . V_61 ) ;
}
static int F_36 ( struct V_1 * V_2 , int V_27 )
{
unsigned char V_62 ;
V_62 = V_27 ;
return F_6 ( V_2 , V_63 , & V_62 , 1 ) ;
}
static T_4 F_37 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char const * V_6 , T_6 V_5 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_23 ;
unsigned long V_64 ;
V_45 = V_45 -> V_46 -> V_46 ;
V_48 = F_22 ( F_23 ( V_45 ) ) ;
V_2 = F_27 ( F_28 ( V_45 ) ) ;
V_23 = F_38 ( V_6 , 10 , & V_64 ) ;
if ( V_23 )
return V_23 ;
if ( V_64 != 0 && V_64 != 1 )
return - V_28 ;
F_24 ( & V_48 -> V_49 ) ;
if ( V_64 == 1 ) {
V_23 = F_36 ( V_2 , 1 ) ;
if ( V_23 )
goto V_65;
V_23 = F_36 ( V_2 , 2 ) ;
if ( V_23 )
goto V_65;
F_39 ( 5 ) ;
V_23 = F_36 ( V_2 , 3 ) ;
if ( V_23 )
goto V_65;
V_23 = F_36 ( V_2 , 0 ) ;
if ( V_23 )
goto V_65;
V_23 = F_36 ( V_2 , 4 ) ;
if ( V_23 )
goto V_65;
F_39 ( 1 ) ;
}
V_23 = F_13 ( V_2 , & V_48 -> V_19 ) ;
if ( V_23 )
goto V_66;
if ( V_48 -> V_19 . V_61 != V_64 ) {
V_48 -> V_19 . V_61 = V_64 ;
F_8 ( & V_48 -> V_19 ) ;
V_23 = F_14 ( V_2 , & V_48 -> V_19 ) ;
if ( V_23 ) {
F_12 ( V_2 , L_3 ) ;
V_23 = F_13 ( V_2 , & V_48 -> V_19 ) ;
if ( V_23 )
goto V_66;
goto V_65;
}
}
V_23 = V_5 ;
V_66:
F_12 ( V_2 , L_4 ) ;
V_65:
F_25 ( & V_48 -> V_49 ) ;
return V_23 ;
}
static T_4 F_40 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char * V_6 )
{
struct V_47 * V_48 =
F_22 ( F_23 ( V_45 -> V_46 -> V_46 ) ) ;
return snprintf ( V_6 , V_58 , L_2 , V_48 -> V_19 . V_52 ) ;
}
static T_4 F_41 ( struct V_44 * V_45 ,
struct V_57 * V_41 , char const * V_6 , T_6 V_5 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
int V_23 ;
unsigned long V_67 ;
V_45 = V_45 -> V_46 -> V_46 ;
V_48 = F_22 ( F_23 ( V_45 ) ) ;
V_2 = F_27 ( F_28 ( V_45 ) ) ;
V_23 = F_38 ( V_6 , 10 , & V_67 ) ;
if ( V_23 )
return V_23 ;
if ( V_67 < 1 || V_67 > 5 )
return - V_28 ;
F_24 ( & V_48 -> V_49 ) ;
V_48 -> V_19 . V_52 = V_67 ;
F_8 ( & V_48 -> V_19 ) ;
V_23 = F_14 ( V_2 , & V_48 -> V_19 ) ;
F_25 ( & V_48 -> V_49 ) ;
if ( V_23 )
return V_23 ;
V_48 -> V_51 = V_67 ;
V_48 -> V_53 = V_48 -> V_54 [ V_48 -> V_51 - 1 ] . V_55 ;
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
T_1 V_22 ;
int V_23 ;
F_43 ( & V_48 -> V_49 ) ;
for ( V_22 = 0 ; V_22 < 5 ; ++ V_22 ) {
V_23 = F_15 ( V_2 , & V_48 -> V_54 [ V_22 ] , V_22 + 1 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_13 ( V_2 , & V_48 -> V_19 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_18 ( V_2 , & V_48 -> V_60 ) ;
if ( V_23 )
return V_23 ;
V_48 -> V_51 = V_48 -> V_19 . V_52 ;
V_48 -> V_53 = V_48 -> V_54 [ V_48 -> V_51 ] . V_55 ;
return 0 ;
}
static int F_44 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_28 ( V_69 -> V_45 . V_46 ) ;
struct V_1 * V_2 = F_27 ( V_71 ) ;
struct V_47 * V_48 ;
int V_23 ;
if ( V_71 -> V_72 -> V_73 . V_74
== V_75 ) {
V_48 = F_45 ( sizeof( * V_48 ) , V_8 ) ;
if ( ! V_48 ) {
F_12 ( V_69 , L_5 ) ;
return - V_9 ;
}
F_46 ( V_69 , V_48 ) ;
V_23 = F_42 ( V_2 , V_48 ) ;
if ( V_23 ) {
F_12 ( V_69 , L_6 ) ;
goto V_76;
}
V_23 = F_47 ( V_77 , V_69 ,
sizeof( struct V_78 ) ) ;
if ( V_23 < 0 ) {
F_12 ( V_69 , L_7 ) ;
} else {
V_48 -> V_79 = 1 ;
V_48 -> V_80 = V_23 ;
}
} else {
F_46 ( V_69 , NULL ) ;
}
return 0 ;
V_76:
F_5 ( V_48 ) ;
return V_23 ;
}
static void F_48 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_28 ( V_69 -> V_45 . V_46 ) ;
struct V_47 * V_48 ;
if ( V_71 -> V_72 -> V_73 . V_74
== V_75 ) {
V_48 = F_22 ( V_69 ) ;
if ( V_48 -> V_79 )
F_49 ( V_48 -> V_80 ) ;
F_5 ( F_22 ( V_69 ) ) ;
}
}
static int F_50 ( struct V_68 * V_69 , const struct V_81 * V_82 )
{
int V_23 ;
V_23 = F_51 ( V_69 ) ;
if ( V_23 ) {
F_12 ( V_69 , L_8 ) ;
goto exit;
}
V_23 = F_52 ( V_69 , V_83 ) ;
if ( V_23 ) {
F_12 ( V_69 , L_9 ) ;
goto exit;
}
V_23 = F_44 ( V_69 ) ;
if ( V_23 ) {
F_12 ( V_69 , L_10 ) ;
goto V_84;
}
return 0 ;
V_84:
F_53 ( V_69 ) ;
exit:
return V_23 ;
}
static void F_54 ( struct V_68 * V_69 )
{
F_48 ( V_69 ) ;
F_53 ( V_69 ) ;
}
static void F_55 ( struct V_47 * V_48 ,
struct V_85 const * V_86 )
{
switch ( V_86 -> V_86 ) {
case V_87 :
case V_88 :
V_48 -> V_51 = V_86 -> V_62 ;
V_48 -> V_53 = V_48 -> V_54 [ V_48 -> V_51 - 1 ] .
V_55 ;
break;
case V_89 :
case V_90 :
V_48 -> V_53 = V_86 -> V_62 ;
break;
}
}
static void F_56 ( struct V_47 const * V_48 ,
struct V_85 const * V_86 )
{
struct V_78 V_91 ;
switch ( V_86 -> V_86 ) {
case V_87 :
case V_89 :
case V_88 :
case V_90 :
V_91 . V_86 = V_86 -> V_86 ;
V_91 . V_62 = V_86 -> V_62 ;
V_91 . V_92 = 0 ;
F_57 ( V_48 -> V_80 ,
( T_3 * ) & V_91 ) ;
break;
case V_93 :
if ( V_86 -> V_62 == V_94 ) {
V_91 . V_86 = V_93 ;
V_91 . V_62 = V_48 -> V_51 ;
V_91 . V_92 = V_86 -> V_95 ;
F_57 ( V_48 -> V_80 ,
( T_3 * ) & V_91 ) ;
}
break;
}
}
static int F_58 ( struct V_68 * V_69 , struct V_96 * V_97 ,
T_7 * V_4 , int V_5 )
{
struct V_47 * V_48 = F_22 ( V_69 ) ;
struct V_85 * V_86 = (struct V_85 * ) V_4 ;
if ( V_5 != sizeof( struct V_85 ) )
return 0 ;
if ( V_48 == NULL )
return 0 ;
if ( memcmp ( & V_48 -> V_98 . V_99 , & V_86 -> V_99 , 5 ) )
memcpy ( & V_48 -> V_98 , V_86 ,
sizeof( struct V_85 ) ) ;
else
memset ( & V_86 -> V_99 , 0 , 5 ) ;
F_55 ( V_48 , V_86 ) ;
if ( V_48 -> V_79 )
F_56 ( V_48 , V_86 ) ;
return 0 ;
}
static int T_8 F_59 ( void )
{
int V_23 ;
V_77 = F_60 ( V_100 , L_11 ) ;
if ( F_61 ( V_77 ) )
return F_62 ( V_77 ) ;
V_77 -> V_101 = V_102 ;
V_77 -> V_103 = V_104 ;
V_23 = F_63 ( & V_105 ) ;
if ( V_23 )
F_64 ( V_77 ) ;
return V_23 ;
}
static void T_9 F_65 ( void )
{
F_66 ( & V_105 ) ;
F_64 ( V_77 ) ;
}
