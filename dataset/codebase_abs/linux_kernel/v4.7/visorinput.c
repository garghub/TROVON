static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_5 ,
L_1 ,
V_6 , V_2 ) ;
return - V_7 ;
}
F_4 ( & V_2 -> V_5 , L_2 , V_6 ) ;
F_5 ( V_4 -> V_5 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_5 ,
L_1 ,
V_6 , V_2 ) ;
return;
}
F_4 ( & V_2 -> V_5 , L_3 , V_6 ) ;
F_7 ( V_4 -> V_5 ) ;
}
static struct V_1 *
F_8 ( void * V_4 ,
unsigned char * V_8 )
{
int V_9 , error ;
struct V_1 * V_2 ;
V_2 = F_9 () ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = L_4 ;
V_2 -> V_11 = L_5 ;
V_2 -> V_12 . V_13 = V_14 ;
V_2 -> V_12 . V_15 = 0x0001 ;
V_2 -> V_12 . V_16 = 0x0001 ;
V_2 -> V_12 . V_17 = 0x0100 ;
V_2 -> V_18 [ 0 ] = F_10 ( V_19 ) |
F_10 ( V_20 ) |
F_10 ( V_21 ) ;
V_2 -> V_22 [ 0 ] = F_10 ( V_23 ) |
F_10 ( V_24 ) |
F_10 ( V_25 ) ;
V_2 -> V_26 = V_8 ;
V_2 -> V_27 = 1 ;
V_2 -> V_28 = V_29 ;
for ( V_9 = 1 ; V_9 < V_2 -> V_28 ; V_9 ++ )
F_11 ( V_8 [ V_9 ] , V_2 -> V_30 ) ;
for ( V_9 = 1 ; V_9 < V_2 -> V_28 ; V_9 ++ )
F_11 ( V_8 [ V_9 + V_29 ] ,
V_2 -> V_30 ) ;
V_2 -> V_31 = F_1 ;
V_2 -> V_32 = F_6 ;
F_12 ( V_2 , V_4 ) ;
error = F_13 ( V_2 ) ;
if ( error ) {
F_14 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_1 *
F_15 ( void * V_4 )
{
int error ;
struct V_1 * V_2 = NULL ;
int V_33 , V_34 ;
struct V_35 * V_36 ;
V_2 = F_9 () ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = L_6 ;
V_2 -> V_11 = L_7 ;
V_2 -> V_12 . V_13 = V_14 ;
V_2 -> V_12 . V_15 = 0x0001 ;
V_2 -> V_12 . V_16 = 0x0002 ;
V_2 -> V_12 . V_17 = 0x0100 ;
V_2 -> V_18 [ 0 ] = F_10 ( V_19 ) | F_10 ( V_37 ) ;
F_11 ( V_38 , V_2 -> V_30 ) ;
F_11 ( V_39 , V_2 -> V_30 ) ;
F_11 ( V_40 , V_2 -> V_30 ) ;
if ( V_41 [ 0 ] ) {
V_36 = V_41 [ 0 ] ;
V_33 = V_36 -> V_42 . V_43 ;
V_34 = V_36 -> V_42 . V_44 ;
} else {
V_33 = V_45 ;
V_34 = V_46 ;
}
F_16 ( V_2 , V_47 , 0 , V_33 , 0 , 0 ) ;
F_16 ( V_2 , V_48 , 0 , V_34 , 0 , 0 ) ;
V_2 -> V_31 = F_1 ;
V_2 -> V_32 = F_6 ;
F_12 ( V_2 , V_4 ) ;
error = F_13 ( V_2 ) ;
if ( error ) {
F_14 ( V_2 ) ;
return NULL ;
}
F_17 ( V_2 , V_49 , V_50 ) ;
return V_2 ;
}
static struct V_3 *
F_18 ( struct V_51 * V_5 , enum V_52 V_53 )
{
struct V_3 * V_4 = NULL ;
unsigned int V_54 = 0 ;
if ( V_53 == V_55 )
V_54 = V_29 * 2 ;
V_4 = F_19 ( sizeof( * V_4 ) + V_54 , V_56 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_5 = V_5 ;
switch ( V_53 ) {
case V_55 :
V_4 -> V_57 = V_54 ;
memcpy ( V_4 -> V_8 , V_58 ,
V_29 ) ;
memcpy ( V_4 -> V_8 + V_29 ,
V_59 , V_29 ) ;
V_4 -> V_2 = F_8
( V_4 , V_4 -> V_8 ) ;
if ( ! V_4 -> V_2 )
goto V_60;
break;
case V_61 :
V_4 -> V_2 = F_15 ( V_4 ) ;
if ( ! V_4 -> V_2 )
goto V_60;
break;
}
F_20 ( & V_4 -> V_62 ) ;
return V_4 ;
V_60:
F_21 ( V_4 ) ;
return NULL ;
}
static int
F_22 ( struct V_51 * V_5 )
{
struct V_3 * V_4 = NULL ;
T_1 V_63 ;
enum V_52 V_53 ;
V_63 = F_23 ( V_5 -> V_64 ) ;
if ( F_24 ( V_63 , V_65 ) == 0 )
V_53 = V_61 ;
else if ( F_24 ( V_63 , V_66 ) == 0 )
V_53 = V_55 ;
else
return - V_67 ;
V_4 = F_18 ( V_5 , V_53 ) ;
if ( ! V_4 )
return - V_68 ;
F_25 ( & V_5 -> V_69 , V_4 ) ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
if ( V_2 )
F_27 ( V_2 ) ;
}
static void
F_28 ( struct V_51 * V_5 )
{
struct V_3 * V_4 = F_29 ( & V_5 -> V_69 ) ;
if ( ! V_4 )
return;
F_7 ( V_5 ) ;
F_30 ( & V_4 -> V_62 ) ;
F_25 ( & V_5 -> V_69 , NULL ) ;
F_26 ( V_4 -> V_2 ) ;
F_31 ( & V_4 -> V_62 ) ;
F_21 ( V_4 ) ;
}
static void
F_32 ( struct V_1 * V_2 ,
int V_26 , int V_70 )
{
int V_71 ;
switch ( V_26 ) {
case V_72 :
V_71 = V_23 ;
break;
case V_73 :
V_71 = V_24 ;
break;
case V_74 :
V_71 = V_25 ;
break;
default:
V_71 = - 1 ;
return;
}
if ( F_33 ( V_71 , V_2 -> V_71 ) != V_70 ) {
F_34 ( V_2 , V_26 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_26 , 0 ) ;
F_35 ( V_2 ) ;
F_36 ( V_71 , V_2 -> V_71 ) ;
}
}
static int
F_37 ( int V_75 )
{
int V_26 ;
if ( V_75 > 0xff )
V_26 = V_59 [ ( V_75 >> 8 ) & 0xff ] ;
else
V_26 = V_58 [ V_75 ] ;
return V_26 ;
}
static int
F_38 ( int V_76 )
{
switch ( V_76 ) {
case 1 :
return V_38 ;
case 2 :
return V_40 ;
case 3 :
return V_39 ;
default:
return - 1 ;
}
}
static void
F_39 ( struct V_51 * V_5 )
{
struct V_77 V_78 ;
int V_75 , V_26 ;
struct V_1 * V_2 ;
int V_79 , V_80 , V_81 ;
int V_9 ;
struct V_3 * V_4 = F_29 ( & V_5 -> V_69 ) ;
if ( ! V_4 )
return;
F_30 ( & V_4 -> V_62 ) ;
if ( V_4 -> V_82 )
goto V_83;
V_2 = V_4 -> V_2 ;
if ( ! V_2 )
goto V_83;
while ( F_40 ( V_5 -> V_64 , 0 , & V_78 ) ) {
V_75 = V_78 . V_84 . V_85 ;
V_26 = F_37 ( V_75 ) ;
switch ( V_78 . V_84 . V_86 ) {
case V_87 :
F_34 ( V_2 , V_26 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_88 :
F_34 ( V_2 , V_26 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_89 :
F_34 ( V_2 , V_26 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_26 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_90 :
F_32 ( V_2 , V_26 ,
V_78 . V_84 . V_91 ) ;
break;
case V_92 :
V_79 = V_78 . V_84 . V_85 ;
V_80 = V_78 . V_84 . V_91 ;
F_41 ( V_2 , V_47 , V_79 ) ;
F_41 ( V_2 , V_48 , V_80 ) ;
F_35 ( V_2 ) ;
break;
case V_93 :
V_81 = F_38 ( V_78 . V_84 . V_85 ) ;
if ( V_81 < 0 )
break;
F_34 ( V_2 , V_81 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_94 :
V_81 = F_38 ( V_78 . V_84 . V_85 ) ;
if ( V_81 < 0 )
break;
F_34 ( V_2 , V_81 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_95 :
V_81 = F_38 ( V_78 . V_84 . V_85 ) ;
if ( V_81 < 0 )
break;
F_34 ( V_2 , V_81 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_81 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_96 :
V_81 = F_38 ( V_78 . V_84 . V_85 ) ;
if ( V_81 < 0 )
break;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_34 ( V_2 , V_81 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_81 , 0 ) ;
F_35 ( V_2 ) ;
}
break;
case V_97 :
F_42 ( V_2 , V_50 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_98 :
F_42 ( V_2 , V_50 , - 1 ) ;
F_35 ( V_2 ) ;
break;
}
}
V_83:
F_31 ( & V_4 -> V_62 ) ;
}
static int
F_43 ( struct V_51 * V_5 ,
T_2 V_99 )
{
int V_100 ;
struct V_3 * V_4 = F_29 ( & V_5 -> V_69 ) ;
if ( ! V_4 ) {
V_100 = - V_67 ;
goto V_101;
}
F_30 ( & V_4 -> V_62 ) ;
if ( V_4 -> V_82 ) {
V_100 = - V_102 ;
goto V_83;
}
V_4 -> V_82 = true ;
V_99 ( V_5 , 0 ) ;
V_100 = 0 ;
V_83:
F_31 ( & V_4 -> V_62 ) ;
V_101:
return V_100 ;
}
static int
F_44 ( struct V_51 * V_5 ,
T_2 V_99 )
{
int V_100 ;
struct V_3 * V_4 = F_29 ( & V_5 -> V_69 ) ;
if ( ! V_4 ) {
V_100 = - V_67 ;
goto V_101;
}
F_30 ( & V_4 -> V_62 ) ;
if ( ! V_4 -> V_82 ) {
V_100 = - V_102 ;
goto V_83;
}
V_4 -> V_82 = false ;
V_99 ( V_5 , 0 ) ;
V_100 = 0 ;
V_83:
F_31 ( & V_4 -> V_62 ) ;
V_101:
return V_100 ;
}
static int
F_45 ( void )
{
return F_46 ( & V_103 ) ;
}
static void
F_47 ( void )
{
F_48 ( & V_103 ) ;
}
