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
F_5 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = true ;
if ( V_4 -> V_10 )
goto V_11;
F_6 ( V_4 -> V_5 ) ;
V_11:
F_7 ( & V_4 -> V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_5 ,
L_1 ,
V_6 , V_2 ) ;
return;
}
F_4 ( & V_2 -> V_5 , L_3 , V_6 ) ;
F_5 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = false ;
if ( V_4 -> V_10 )
goto V_11;
F_9 ( V_4 -> V_5 ) ;
V_11:
F_7 ( & V_4 -> V_8 ) ;
}
static struct V_1 *
F_10 ( void * V_4 ,
unsigned char * V_12 )
{
int V_13 ;
struct V_1 * V_2 ;
V_2 = F_11 () ;
if ( ! V_2 )
return NULL ;
V_2 -> V_14 = L_4 ;
V_2 -> V_15 = L_5 ;
V_2 -> V_16 . V_17 = V_18 ;
V_2 -> V_16 . V_19 = 0x0001 ;
V_2 -> V_16 . V_20 = 0x0001 ;
V_2 -> V_16 . V_21 = 0x0100 ;
V_2 -> V_22 [ 0 ] = F_12 ( V_23 ) |
F_12 ( V_24 ) |
F_12 ( V_25 ) ;
V_2 -> V_26 [ 0 ] = F_12 ( V_27 ) |
F_12 ( V_28 ) |
F_12 ( V_29 ) ;
V_2 -> V_30 = V_12 ;
V_2 -> V_31 = 1 ;
V_2 -> V_32 = V_33 ;
for ( V_13 = 1 ; V_13 < V_2 -> V_32 ; V_13 ++ )
F_13 ( V_12 [ V_13 ] , V_2 -> V_34 ) ;
for ( V_13 = 1 ; V_13 < V_2 -> V_32 ; V_13 ++ )
F_13 ( V_12 [ V_13 + V_33 ] ,
V_2 -> V_34 ) ;
V_2 -> V_35 = F_1 ;
V_2 -> V_36 = F_8 ;
F_14 ( V_2 , V_4 ) ;
return V_2 ;
}
static struct V_1 *
F_15 ( void * V_4 )
{
struct V_1 * V_2 = NULL ;
int V_37 , V_38 ;
struct V_39 * V_40 ;
V_2 = F_11 () ;
if ( ! V_2 )
return NULL ;
V_2 -> V_14 = L_6 ;
V_2 -> V_15 = L_7 ;
V_2 -> V_16 . V_17 = V_18 ;
V_2 -> V_16 . V_19 = 0x0001 ;
V_2 -> V_16 . V_20 = 0x0002 ;
V_2 -> V_16 . V_21 = 0x0100 ;
V_2 -> V_22 [ 0 ] = F_12 ( V_23 ) | F_12 ( V_41 ) ;
F_13 ( V_42 , V_2 -> V_34 ) ;
F_13 ( V_43 , V_2 -> V_34 ) ;
F_13 ( V_44 , V_2 -> V_34 ) ;
if ( V_45 [ 0 ] ) {
V_40 = V_45 [ 0 ] ;
V_37 = V_40 -> V_46 . V_47 ;
V_38 = V_40 -> V_46 . V_48 ;
} else {
V_37 = V_49 ;
V_38 = V_50 ;
}
F_16 ( V_2 , V_51 , 0 , V_37 , 0 , 0 ) ;
F_16 ( V_2 , V_52 , 0 , V_38 , 0 , 0 ) ;
V_2 -> V_35 = F_1 ;
V_2 -> V_36 = F_8 ;
F_14 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_53 , V_54 ) ;
return V_2 ;
}
static struct V_3 *
F_18 ( struct V_55 * V_5 , enum V_56 V_57 )
{
struct V_3 * V_4 = NULL ;
unsigned int V_58 = 0 ;
if ( V_57 == V_59 )
V_58 = V_33 * 2 ;
V_4 = F_19 ( sizeof( * V_4 ) + V_58 , V_60 ) ;
if ( ! V_4 )
return NULL ;
F_20 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 -> V_8 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_10 = true ;
switch ( V_57 ) {
case V_59 :
V_4 -> V_61 = V_58 ;
memcpy ( V_4 -> V_12 , V_62 ,
V_33 ) ;
memcpy ( V_4 -> V_12 + V_33 ,
V_63 , V_33 ) ;
V_4 -> V_2 = F_10
( V_4 , V_4 -> V_12 ) ;
if ( ! V_4 -> V_2 )
goto V_64;
break;
case V_65 :
V_4 -> V_2 = F_15 ( V_4 ) ;
if ( ! V_4 -> V_2 )
goto V_64;
break;
default:
break;
}
F_21 ( & V_5 -> V_66 , V_4 ) ;
F_7 ( & V_4 -> V_8 ) ;
if ( F_22 ( V_4 -> V_2 ) ) {
F_23 ( V_4 -> V_2 ) ;
goto V_67;
}
F_5 ( & V_4 -> V_8 ) ;
V_4 -> V_10 = false ;
if ( V_4 -> V_9 )
F_6 ( V_5 ) ;
F_7 ( & V_4 -> V_8 ) ;
return V_4 ;
V_64:
F_7 ( & V_4 -> V_8 ) ;
V_67:
F_24 ( V_4 ) ;
return NULL ;
}
static int
F_25 ( struct V_55 * V_5 )
{
T_1 V_68 ;
enum V_56 V_57 ;
V_68 = F_26 ( V_5 -> V_69 ) ;
if ( F_27 ( V_68 , V_70 ) == 0 )
V_57 = V_65 ;
else if ( F_27 ( V_68 , V_71 ) == 0 )
V_57 = V_59 ;
else
return - V_72 ;
F_9 ( V_5 ) ;
if ( ! F_18 ( V_5 , V_57 ) )
return - V_73 ;
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 )
{
if ( V_2 )
F_29 ( V_2 ) ;
}
static void
F_30 ( struct V_55 * V_5 )
{
struct V_3 * V_4 = F_31 ( & V_5 -> V_66 ) ;
if ( ! V_4 )
return;
F_5 ( & V_4 -> V_8 ) ;
F_9 ( V_5 ) ;
F_21 ( & V_5 -> V_66 , NULL ) ;
F_7 ( & V_4 -> V_8 ) ;
F_28 ( V_4 -> V_2 ) ;
F_24 ( V_4 ) ;
}
static void
F_32 ( struct V_1 * V_2 ,
int V_30 , int V_74 )
{
int V_75 ;
switch ( V_30 ) {
case V_76 :
V_75 = V_27 ;
break;
case V_77 :
V_75 = V_28 ;
break;
case V_78 :
V_75 = V_29 ;
break;
default:
V_75 = - 1 ;
return;
}
if ( F_33 ( V_75 , V_2 -> V_75 ) != V_74 ) {
F_34 ( V_2 , V_30 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_30 , 0 ) ;
F_35 ( V_2 ) ;
F_36 ( V_75 , V_2 -> V_75 ) ;
}
}
static int
F_37 ( int V_79 )
{
int V_30 ;
if ( V_79 > 0xff )
V_30 = V_63 [ ( V_79 >> 8 ) & 0xff ] ;
else
V_30 = V_62 [ V_79 ] ;
return V_30 ;
}
static int
F_38 ( int V_80 )
{
switch ( V_80 ) {
case 1 :
return V_42 ;
case 2 :
return V_44 ;
case 3 :
return V_43 ;
default:
return - V_7 ;
}
}
static void
F_39 ( struct V_55 * V_5 )
{
struct V_81 V_82 ;
int V_79 , V_30 ;
struct V_1 * V_2 ;
int V_83 , V_84 , V_85 ;
int V_13 ;
struct V_3 * V_4 = F_31 ( & V_5 -> V_66 ) ;
if ( ! V_4 )
return;
V_2 = V_4 -> V_2 ;
while ( ! F_40 ( V_5 -> V_69 , 0 , & V_82 ) ) {
V_79 = V_82 . V_86 . V_87 ;
V_30 = F_37 ( V_79 ) ;
switch ( V_82 . V_86 . V_88 ) {
case V_89 :
F_34 ( V_2 , V_30 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_90 :
F_34 ( V_2 , V_30 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_91 :
F_34 ( V_2 , V_30 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_30 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_92 :
F_32 ( V_2 , V_30 ,
V_82 . V_86 . V_93 ) ;
break;
case V_94 :
V_83 = V_82 . V_86 . V_87 ;
V_84 = V_82 . V_86 . V_93 ;
F_41 ( V_2 , V_51 , V_83 ) ;
F_41 ( V_2 , V_52 , V_84 ) ;
F_35 ( V_2 ) ;
break;
case V_95 :
V_85 = F_38 ( V_82 . V_86 . V_87 ) ;
if ( V_85 < 0 )
break;
F_34 ( V_2 , V_85 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_96 :
V_85 = F_38 ( V_82 . V_86 . V_87 ) ;
if ( V_85 < 0 )
break;
F_34 ( V_2 , V_85 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_97 :
V_85 = F_38 ( V_82 . V_86 . V_87 ) ;
if ( V_85 < 0 )
break;
F_34 ( V_2 , V_85 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_85 , 0 ) ;
F_35 ( V_2 ) ;
break;
case V_98 :
V_85 = F_38 ( V_82 . V_86 . V_87 ) ;
if ( V_85 < 0 )
break;
for ( V_13 = 0 ; V_13 < 2 ; V_13 ++ ) {
F_34 ( V_2 , V_85 , 1 ) ;
F_35 ( V_2 ) ;
F_34 ( V_2 , V_85 , 0 ) ;
F_35 ( V_2 ) ;
}
break;
case V_99 :
F_42 ( V_2 , V_54 , 1 ) ;
F_35 ( V_2 ) ;
break;
case V_100 :
F_42 ( V_2 , V_54 , - 1 ) ;
F_35 ( V_2 ) ;
break;
default:
break;
}
}
}
static int
F_43 ( struct V_55 * V_5 ,
T_2 V_101 )
{
int V_102 ;
struct V_3 * V_4 = F_31 ( & V_5 -> V_66 ) ;
if ( ! V_4 ) {
V_102 = - V_72 ;
goto V_103;
}
F_5 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_10 ) {
V_102 = - V_104 ;
goto V_105;
}
if ( V_4 -> V_9 )
F_9 ( V_5 ) ;
V_4 -> V_10 = true ;
V_101 ( V_5 , 0 ) ;
V_102 = 0 ;
V_105:
F_7 ( & V_4 -> V_8 ) ;
V_103:
return V_102 ;
}
static int
F_44 ( struct V_55 * V_5 ,
T_2 V_101 )
{
int V_102 ;
struct V_3 * V_4 = F_31 ( & V_5 -> V_66 ) ;
if ( ! V_4 ) {
V_102 = - V_72 ;
goto V_103;
}
F_5 ( & V_4 -> V_8 ) ;
if ( ! V_4 -> V_10 ) {
V_102 = - V_104 ;
goto V_105;
}
V_4 -> V_10 = false ;
V_101 ( V_5 , 0 ) ;
if ( V_4 -> V_9 )
F_6 ( V_5 ) ;
V_102 = 0 ;
V_105:
F_7 ( & V_4 -> V_8 ) ;
V_103:
return V_102 ;
}
static int
F_45 ( void )
{
return F_46 ( & V_106 ) ;
}
static void
F_47 ( void )
{
F_48 ( & V_106 ) ;
}
