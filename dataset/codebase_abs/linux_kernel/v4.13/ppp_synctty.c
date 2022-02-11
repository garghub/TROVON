static void
F_1 ( const char * V_1 , const T_1 * V_2 , int V_3 )
{
if ( V_1 != NULL )
F_2 ( V_4 L_1 , V_1 , V_3 ) ;
F_3 ( L_2 , V_5 , V_2 , V_3 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
F_5 ( & V_10 ) ;
V_9 = V_8 -> V_11 ;
if ( V_9 != NULL )
F_6 ( & V_9 -> V_12 ) ;
F_7 ( & V_10 ) ;
return V_9 ;
}
static void F_8 ( struct V_6 * V_9 )
{
if ( F_9 ( & V_9 -> V_12 ) )
F_10 ( & V_9 -> V_13 ) ;
}
static int
F_11 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
int V_14 ;
int V_15 ;
if ( V_8 -> V_16 -> V_17 == NULL )
return - V_18 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_19 ) ;
V_14 = - V_20 ;
if ( ! V_9 )
goto V_21;
V_9 -> V_8 = V_8 ;
V_9 -> V_22 = V_23 ;
F_13 ( & V_9 -> V_24 ) ;
F_13 ( & V_9 -> V_25 ) ;
V_9 -> V_26 [ 0 ] = ~ 0U ;
V_9 -> V_26 [ 3 ] = 0x60000000U ;
V_9 -> V_27 = ~ 0U ;
F_14 ( & V_9 -> V_28 ) ;
F_15 ( & V_9 -> V_29 , V_30 , ( unsigned long ) V_9 ) ;
F_16 ( & V_9 -> V_12 , 1 ) ;
F_17 ( & V_9 -> V_13 ) ;
V_9 -> V_31 . V_32 = V_9 ;
V_9 -> V_31 . V_16 = & V_33 ;
V_9 -> V_31 . V_34 = V_23 ;
V_9 -> V_31 . V_35 = 2 ;
V_15 = F_18 ( V_8 ) ;
V_9 -> V_31 . V_15 = V_15 ;
V_14 = F_19 ( & V_9 -> V_31 ) ;
if ( V_14 )
goto V_36;
V_8 -> V_11 = V_9 ;
V_8 -> V_37 = 65536 ;
return 0 ;
V_36:
F_20 ( V_9 ) ;
V_21:
return V_14 ;
}
static void
F_21 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
F_22 ( & V_10 ) ;
V_9 = V_8 -> V_11 ;
V_8 -> V_11 = NULL ;
F_23 ( & V_10 ) ;
if ( ! V_9 )
return;
if ( ! F_9 ( & V_9 -> V_12 ) )
F_24 ( & V_9 -> V_13 ) ;
F_25 ( & V_9 -> V_29 ) ;
F_26 ( & V_9 -> V_31 ) ;
F_27 ( & V_9 -> V_28 ) ;
F_28 ( V_9 -> V_38 ) ;
F_20 ( V_9 ) ;
}
static int F_29 ( struct V_7 * V_8 )
{
F_21 ( V_8 ) ;
return 0 ;
}
static T_2
F_30 ( struct V_7 * V_8 , struct V_39 * V_39 ,
unsigned char T_3 * V_2 , T_4 V_3 )
{
return - V_40 ;
}
static T_2
F_31 ( struct V_7 * V_8 , struct V_39 * V_39 ,
const unsigned char * V_2 , T_4 V_3 )
{
return - V_40 ;
}
static int
F_32 ( struct V_7 * V_8 , struct V_39 * V_39 ,
unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_9 = F_4 ( V_8 ) ;
int T_3 * V_43 = ( int T_3 * ) V_42 ;
int V_14 , V_44 ;
if ( ! V_9 )
return - V_45 ;
V_14 = - V_46 ;
switch ( V_41 ) {
case V_47 :
V_14 = - V_46 ;
if ( F_33 ( F_34 ( & V_9 -> V_31 ) , V_43 ) )
break;
V_14 = 0 ;
break;
case V_48 :
V_14 = - V_46 ;
if ( F_33 ( F_35 ( & V_9 -> V_31 ) , V_43 ) )
break;
V_14 = 0 ;
break;
case V_49 :
if ( V_42 == V_50 || V_42 == V_51 )
F_36 ( V_9 ) ;
V_14 = F_37 ( V_8 , V_39 , V_41 , V_42 ) ;
break;
case V_52 :
V_44 = 0 ;
if ( F_33 ( V_44 , V_43 ) )
break;
V_14 = 0 ;
break;
default:
V_14 = F_38 ( V_8 , V_39 , V_41 , V_42 ) ;
break;
}
F_8 ( V_9 ) ;
return V_14 ;
}
static unsigned int
F_39 ( struct V_7 * V_8 , struct V_39 * V_39 , T_5 * V_53 )
{
return 0 ;
}
static void
F_40 ( struct V_7 * V_8 , const unsigned char * V_2 ,
char * V_54 , int V_3 )
{
struct V_6 * V_9 = F_4 ( V_8 ) ;
unsigned long V_55 ;
if ( ! V_9 )
return;
F_41 ( & V_9 -> V_25 , V_55 ) ;
F_42 ( V_9 , V_2 , V_54 , V_3 ) ;
F_43 ( & V_9 -> V_25 , V_55 ) ;
if ( ! F_44 ( & V_9 -> V_28 ) )
F_45 ( & V_9 -> V_29 ) ;
F_8 ( V_9 ) ;
F_46 ( V_8 ) ;
}
static void
F_47 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_4 ( V_8 ) ;
F_48 ( V_56 , & V_8 -> V_55 ) ;
if ( ! V_9 )
return;
F_49 ( V_57 , & V_9 -> V_58 ) ;
F_45 ( & V_9 -> V_29 ) ;
F_8 ( V_9 ) ;
}
static int T_6
F_50 ( void )
{
int V_14 ;
V_14 = F_51 ( V_59 , & V_60 ) ;
if ( V_14 != 0 )
F_2 ( V_61 L_3 ,
V_14 ) ;
return V_14 ;
}
static int
F_52 ( struct V_62 * V_31 , unsigned int V_41 , unsigned long V_42 )
{
struct V_6 * V_9 = V_31 -> V_32 ;
int V_14 , V_44 ;
T_7 V_63 [ 8 ] ;
void T_3 * V_64 = ( void T_3 * ) V_42 ;
T_7 T_3 * V_43 = V_64 ;
V_14 = - V_46 ;
switch ( V_41 ) {
case V_65 :
V_44 = V_9 -> V_55 | V_9 -> V_66 ;
if ( F_33 ( V_44 , ( int T_3 * ) V_64 ) )
break;
V_14 = 0 ;
break;
case V_67 :
if ( F_53 ( V_44 , ( int T_3 * ) V_64 ) )
break;
V_9 -> V_55 = V_44 & ~ V_68 ;
F_54 ( & V_9 -> V_25 ) ;
V_9 -> V_66 = V_44 & V_68 ;
F_55 ( & V_9 -> V_25 ) ;
V_14 = 0 ;
break;
case V_69 :
if ( F_33 ( V_9 -> V_26 [ 0 ] , V_43 ) )
break;
V_14 = 0 ;
break;
case V_70 :
if ( F_53 ( V_9 -> V_26 [ 0 ] , V_43 ) )
break;
V_14 = 0 ;
break;
case V_71 :
if ( F_33 ( V_9 -> V_27 , V_43 ) )
break;
V_14 = 0 ;
break;
case V_72 :
if ( F_53 ( V_9 -> V_27 , V_43 ) )
break;
V_14 = 0 ;
break;
case V_73 :
if ( F_56 ( V_64 , V_9 -> V_26 , sizeof( V_9 -> V_26 ) ) )
break;
V_14 = 0 ;
break;
case V_74 :
if ( F_57 ( V_63 , V_64 , sizeof( V_63 ) ) )
break;
V_63 [ 2 ] &= ~ 0x40000000U ;
V_63 [ 3 ] |= 0x60000000U ;
memcpy ( V_9 -> V_26 , V_63 , sizeof( V_9 -> V_26 ) ) ;
V_14 = 0 ;
break;
case V_75 :
if ( F_33 ( V_9 -> V_22 , ( int T_3 * ) V_64 ) )
break;
V_14 = 0 ;
break;
case V_76 :
if ( F_53 ( V_44 , ( int T_3 * ) V_64 ) )
break;
if ( V_44 < V_23 )
V_44 = V_23 ;
V_9 -> V_22 = V_44 ;
V_14 = 0 ;
break;
default:
V_14 = - V_77 ;
}
return V_14 ;
}
static void V_30 ( unsigned long V_42 )
{
struct V_6 * V_9 = (struct V_6 * ) V_42 ;
struct V_78 * V_79 ;
while ( ( V_79 = F_58 ( & V_9 -> V_28 ) ) != NULL ) {
if ( V_79 -> V_80 == 0 ) {
F_59 ( & V_9 -> V_31 , 0 ) ;
F_28 ( V_79 ) ;
}
else
F_60 ( & V_9 -> V_31 , V_79 ) ;
}
if ( F_61 ( V_57 , & V_9 -> V_58 ) && F_62 ( V_9 ) )
F_63 ( & V_9 -> V_31 ) ;
}
static struct V_78 *
F_64 ( struct V_6 * V_9 , struct V_78 * V_79 )
{
int V_81 ;
unsigned char * V_82 ;
int V_83 ;
V_82 = V_79 -> V_82 ;
V_81 = F_65 ( V_82 ) ;
V_83 = V_81 == V_84 && 1 <= V_82 [ 2 ] && V_82 [ 2 ] <= 7 ;
if ( V_82 [ 0 ] == 0 && ( V_9 -> V_55 & V_85 ) && ! V_83 )
F_66 ( V_79 , 1 ) ;
if ( ( V_9 -> V_55 & V_86 ) == 0 || V_83 ) {
if ( F_67 ( V_79 ) < 2 ) {
struct V_78 * V_87 = F_68 ( V_79 -> V_80 + 2 ) ;
if ( V_87 == NULL ) {
F_28 ( V_79 ) ;
return NULL ;
}
F_69 ( V_87 , 2 ) ;
F_70 ( V_79 ,
F_71 ( V_87 , V_79 -> V_80 ) , V_79 -> V_80 ) ;
F_72 ( V_79 ) ;
V_79 = V_87 ;
}
F_73 ( V_79 , 2 ) ;
V_79 -> V_82 [ 0 ] = V_88 ;
V_79 -> V_82 [ 1 ] = V_89 ;
}
V_9 -> V_90 = V_91 ;
if ( V_79 && V_9 -> V_55 & V_92 )
F_1 ( L_4 , V_79 -> V_82 , V_79 -> V_80 ) ;
return V_79 ;
}
static int
F_74 ( struct V_62 * V_31 , struct V_78 * V_79 )
{
struct V_6 * V_9 = V_31 -> V_32 ;
F_62 ( V_9 ) ;
if ( F_75 ( V_93 , & V_9 -> V_58 ) )
return 0 ;
V_79 = F_64 ( V_9 , V_79 ) ;
if ( V_79 != NULL )
V_9 -> V_38 = V_79 ;
else
F_48 ( V_93 , & V_9 -> V_58 ) ;
F_62 ( V_9 ) ;
return 1 ;
}
static int
F_62 ( struct V_6 * V_9 )
{
int V_94 , V_95 = 0 ;
struct V_7 * V_8 = V_9 -> V_8 ;
int V_96 = 0 ;
if ( ! F_76 ( & V_9 -> V_24 ) )
return 0 ;
for (; ; ) {
if ( F_77 ( V_57 , & V_9 -> V_58 ) )
V_96 = 0 ;
if ( ! V_96 && V_9 -> V_38 ) {
F_49 ( V_56 , & V_8 -> V_55 ) ;
V_94 = V_8 -> V_16 -> V_17 ( V_8 , V_9 -> V_38 -> V_82 , V_9 -> V_38 -> V_80 ) ;
if ( V_94 < 0 )
goto V_97;
if ( V_94 < V_9 -> V_38 -> V_80 ) {
V_96 = 1 ;
} else {
F_72 ( V_9 -> V_38 ) ;
V_9 -> V_38 = NULL ;
F_48 ( V_93 , & V_9 -> V_58 ) ;
V_95 = 1 ;
}
continue;
}
F_78 ( & V_9 -> V_24 ) ;
if ( ! ( F_61 ( V_57 , & V_9 -> V_58 ) ||
( ! V_96 && V_9 -> V_38 ) ) )
break;
if ( ! F_76 ( & V_9 -> V_24 ) )
break;
}
return V_95 ;
V_97:
if ( V_9 -> V_38 ) {
F_28 ( V_9 -> V_38 ) ;
V_9 -> V_38 = NULL ;
F_48 ( V_93 , & V_9 -> V_58 ) ;
V_95 = 1 ;
}
F_78 ( & V_9 -> V_24 ) ;
return V_95 ;
}
static void
F_36 ( struct V_6 * V_9 )
{
int V_95 = 0 ;
F_79 ( & V_9 -> V_24 ) ;
if ( V_9 -> V_38 != NULL ) {
F_28 ( V_9 -> V_38 ) ;
V_9 -> V_38 = NULL ;
F_48 ( V_93 , & V_9 -> V_58 ) ;
V_95 = 1 ;
}
F_78 ( & V_9 -> V_24 ) ;
if ( V_95 )
F_63 ( & V_9 -> V_31 ) ;
}
static void
F_42 ( struct V_6 * V_9 , const unsigned char * V_2 ,
char * V_55 , int V_3 )
{
struct V_78 * V_79 ;
unsigned char * V_43 ;
if ( V_3 == 0 )
return;
if ( V_9 -> V_55 & V_98 )
F_1 ( L_5 , V_2 , V_3 ) ;
V_79 = F_68 ( V_9 -> V_22 + V_99 + 2 ) ;
if ( ! V_79 ) {
F_2 ( V_61 L_6 ) ;
goto V_14;
}
if ( V_2 [ 0 ] != V_88 )
F_69 ( V_79 , 2 + ( V_2 [ 0 ] & 1 ) ) ;
if ( V_55 && * V_55 ) {
goto V_14;
} else if ( V_3 > F_80 ( V_79 ) ) {
goto V_14;
}
F_81 ( V_79 , V_2 , V_3 ) ;
V_43 = V_79 -> V_82 ;
if ( V_43 [ 0 ] == V_88 && V_43 [ 1 ] == V_89 ) {
if ( V_79 -> V_80 < 3 )
goto V_14;
V_43 = F_66 ( V_79 , 2 ) ;
}
if ( V_43 [ 0 ] & 1 ) {
* ( V_100 * ) F_73 ( V_79 , 1 ) = 0 ;
} else if ( V_79 -> V_80 < 2 )
goto V_14;
F_82 ( & V_9 -> V_28 , V_79 ) ;
return;
V_14:
if ( V_79 || ( V_79 = F_68 ( 0 ) ) ) {
F_83 ( V_79 , 0 ) ;
F_82 ( & V_9 -> V_28 , V_79 ) ;
}
}
static void T_8
F_84 ( void )
{
if ( F_85 ( V_59 ) != 0 )
F_2 ( V_61 L_7 ) ;
}
