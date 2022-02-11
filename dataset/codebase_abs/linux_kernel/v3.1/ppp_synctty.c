static void
F_1 ( register T_1 * V_1 , const T_1 * V_2 , int V_3 )
{
register T_1 V_4 ;
static const char V_5 [] = L_1 ;
while ( V_3 -- > 0 ) {
V_4 = * V_2 ++ ;
* V_1 ++ = V_5 [ ( V_4 >> 4 ) & 0x0F ] ;
* V_1 ++ = V_5 [ V_4 & 0x0F ] ;
++ V_1 ;
}
}
static void
F_2 ( register T_1 * V_1 , const T_1 * V_2 , int V_3 )
{
register T_1 V_4 ;
while ( V_3 -- > 0 ) {
V_4 = * V_2 ++ ;
if ( V_4 < 0x20 || V_4 > 0x7e )
* V_1 ++ = '.' ;
else {
* V_1 ++ = V_4 ;
if ( V_4 == '%' )
* V_1 ++ = '%' ;
}
}
* V_1 = '\0' ;
}
static void
F_3 ( const char * V_6 , const T_1 * V_7 , int V_3 )
{
T_1 line [ 44 ] ;
if ( V_6 != NULL )
F_4 ( V_8 L_2 , V_6 , V_3 ) ;
while ( V_3 > 8 ) {
memset ( line , 32 , 44 ) ;
F_1 ( line , V_7 , 8 ) ;
F_2 ( & line [ 8 * 3 ] , V_7 , 8 ) ;
F_4 ( V_8 L_3 , line ) ;
V_3 -= 8 ;
V_7 += 8 ;
}
if ( V_3 > 0 ) {
memset ( line , 32 , 44 ) ;
F_1 ( line , V_7 , V_3 ) ;
F_2 ( & line [ 8 * 3 ] , V_7 , V_3 ) ;
F_4 ( V_8 L_3 , line ) ;
}
}
static struct V_9 * F_5 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
F_6 ( & V_13 ) ;
V_12 = V_11 -> V_14 ;
if ( V_12 != NULL )
F_7 ( & V_12 -> V_15 ) ;
F_8 ( & V_13 ) ;
return V_12 ;
}
static void F_9 ( struct V_9 * V_12 )
{
if ( F_10 ( & V_12 -> V_15 ) )
F_11 ( & V_12 -> V_16 ) ;
}
static int
F_12 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
int V_17 ;
int V_18 ;
if ( V_11 -> V_19 -> V_20 == NULL )
return - V_21 ;
V_12 = F_13 ( sizeof( * V_12 ) , V_22 ) ;
V_17 = - V_23 ;
if ( ! V_12 )
goto V_1;
V_12 -> V_11 = V_11 ;
V_12 -> V_24 = V_25 ;
F_14 ( & V_12 -> V_26 ) ;
F_14 ( & V_12 -> V_27 ) ;
V_12 -> V_28 [ 0 ] = ~ 0U ;
V_12 -> V_28 [ 3 ] = 0x60000000U ;
V_12 -> V_29 = ~ 0U ;
F_15 ( & V_12 -> V_30 ) ;
F_16 ( & V_12 -> V_31 , V_32 , ( unsigned long ) V_12 ) ;
F_17 ( & V_12 -> V_15 , 1 ) ;
F_18 ( & V_12 -> V_16 ) ;
V_12 -> V_33 . V_34 = V_12 ;
V_12 -> V_33 . V_19 = & V_35 ;
V_12 -> V_33 . V_36 = V_25 ;
V_12 -> V_33 . V_37 = 2 ;
V_18 = F_19 ( V_11 ) ;
V_12 -> V_33 . V_18 = V_18 ;
V_17 = F_20 ( & V_12 -> V_33 ) ;
if ( V_17 )
goto V_38;
V_11 -> V_14 = V_12 ;
V_11 -> V_39 = 65536 ;
return 0 ;
V_38:
F_21 ( V_12 ) ;
V_1:
return V_17 ;
}
static void
F_22 ( struct V_10 * V_11 )
{
struct V_9 * V_12 ;
F_23 ( & V_13 ) ;
V_12 = V_11 -> V_14 ;
V_11 -> V_14 = NULL ;
F_24 ( & V_13 ) ;
if ( ! V_12 )
return;
if ( ! F_10 ( & V_12 -> V_15 ) )
F_25 ( & V_12 -> V_16 ) ;
F_26 ( & V_12 -> V_31 ) ;
F_27 ( & V_12 -> V_33 ) ;
F_28 ( & V_12 -> V_30 ) ;
F_29 ( V_12 -> V_40 ) ;
F_21 ( V_12 ) ;
}
static int F_30 ( struct V_10 * V_11 )
{
F_22 ( V_11 ) ;
return 0 ;
}
static T_2
F_31 ( struct V_10 * V_11 , struct V_41 * V_41 ,
unsigned char T_3 * V_7 , T_4 V_3 )
{
return - V_42 ;
}
static T_2
F_32 ( struct V_10 * V_11 , struct V_41 * V_41 ,
const unsigned char * V_7 , T_4 V_3 )
{
return - V_42 ;
}
static int
F_33 ( struct V_10 * V_11 , struct V_41 * V_41 ,
unsigned int V_43 , unsigned long V_44 )
{
struct V_9 * V_12 = F_5 ( V_11 ) ;
int T_3 * V_45 = ( int T_3 * ) V_44 ;
int V_17 , V_46 ;
if ( ! V_12 )
return - V_47 ;
V_17 = - V_48 ;
switch ( V_43 ) {
case V_49 :
V_17 = - V_48 ;
if ( F_34 ( F_35 ( & V_12 -> V_33 ) , V_45 ) )
break;
V_17 = 0 ;
break;
case V_50 :
V_17 = - V_48 ;
if ( F_34 ( F_36 ( & V_12 -> V_33 ) , V_45 ) )
break;
V_17 = 0 ;
break;
case V_51 :
if ( V_44 == V_52 || V_44 == V_53 )
F_37 ( V_12 ) ;
V_17 = F_38 ( V_11 , V_44 ) ;
break;
case V_54 :
V_46 = 0 ;
if ( F_34 ( V_46 , V_45 ) )
break;
V_17 = 0 ;
break;
default:
V_17 = F_39 ( V_11 , V_41 , V_43 , V_44 ) ;
break;
}
F_9 ( V_12 ) ;
return V_17 ;
}
static unsigned int
F_40 ( struct V_10 * V_11 , struct V_41 * V_41 , T_5 * V_55 )
{
return 0 ;
}
static void
F_41 ( struct V_10 * V_11 , const unsigned char * V_7 ,
char * V_56 , int V_3 )
{
struct V_9 * V_12 = F_5 ( V_11 ) ;
unsigned long V_57 ;
if ( ! V_12 )
return;
F_42 ( & V_12 -> V_27 , V_57 ) ;
F_43 ( V_12 , V_7 , V_56 , V_3 ) ;
F_44 ( & V_12 -> V_27 , V_57 ) ;
if ( ! F_45 ( & V_12 -> V_30 ) )
F_46 ( & V_12 -> V_31 ) ;
F_9 ( V_12 ) ;
F_47 ( V_11 ) ;
}
static void
F_48 ( struct V_10 * V_11 )
{
struct V_9 * V_12 = F_5 ( V_11 ) ;
F_49 ( V_58 , & V_11 -> V_57 ) ;
if ( ! V_12 )
return;
F_50 ( V_59 , & V_12 -> V_60 ) ;
F_46 ( & V_12 -> V_31 ) ;
F_9 ( V_12 ) ;
}
static int T_6
F_51 ( void )
{
int V_17 ;
V_17 = F_52 ( V_61 , & V_62 ) ;
if ( V_17 != 0 )
F_4 ( V_63 L_4 ,
V_17 ) ;
return V_17 ;
}
static int
F_53 ( struct V_64 * V_33 , unsigned int V_43 , unsigned long V_44 )
{
struct V_9 * V_12 = V_33 -> V_34 ;
int V_17 , V_46 ;
T_7 V_65 [ 8 ] ;
void T_3 * V_66 = ( void T_3 * ) V_44 ;
T_7 T_3 * V_45 = V_66 ;
V_17 = - V_48 ;
switch ( V_43 ) {
case V_67 :
V_46 = V_12 -> V_57 | V_12 -> V_68 ;
if ( F_34 ( V_46 , ( int T_3 * ) V_66 ) )
break;
V_17 = 0 ;
break;
case V_69 :
if ( F_54 ( V_46 , ( int T_3 * ) V_66 ) )
break;
V_12 -> V_57 = V_46 & ~ V_70 ;
F_55 ( & V_12 -> V_27 ) ;
V_12 -> V_68 = V_46 & V_70 ;
F_56 ( & V_12 -> V_27 ) ;
V_17 = 0 ;
break;
case V_71 :
if ( F_34 ( V_12 -> V_28 [ 0 ] , V_45 ) )
break;
V_17 = 0 ;
break;
case V_72 :
if ( F_54 ( V_12 -> V_28 [ 0 ] , V_45 ) )
break;
V_17 = 0 ;
break;
case V_73 :
if ( F_34 ( V_12 -> V_29 , V_45 ) )
break;
V_17 = 0 ;
break;
case V_74 :
if ( F_54 ( V_12 -> V_29 , V_45 ) )
break;
V_17 = 0 ;
break;
case V_75 :
if ( F_57 ( V_66 , V_12 -> V_28 , sizeof( V_12 -> V_28 ) ) )
break;
V_17 = 0 ;
break;
case V_76 :
if ( F_58 ( V_65 , V_66 , sizeof( V_65 ) ) )
break;
V_65 [ 2 ] &= ~ 0x40000000U ;
V_65 [ 3 ] |= 0x60000000U ;
memcpy ( V_12 -> V_28 , V_65 , sizeof( V_12 -> V_28 ) ) ;
V_17 = 0 ;
break;
case V_77 :
if ( F_34 ( V_12 -> V_24 , ( int T_3 * ) V_66 ) )
break;
V_17 = 0 ;
break;
case V_78 :
if ( F_54 ( V_46 , ( int T_3 * ) V_66 ) )
break;
if ( V_46 < V_25 )
V_46 = V_25 ;
V_12 -> V_24 = V_46 ;
V_17 = 0 ;
break;
default:
V_17 = - V_79 ;
}
return V_17 ;
}
static void V_32 ( unsigned long V_44 )
{
struct V_9 * V_12 = (struct V_9 * ) V_44 ;
struct V_80 * V_81 ;
while ( ( V_81 = F_59 ( & V_12 -> V_30 ) ) != NULL ) {
if ( V_81 -> V_82 == 0 ) {
F_60 ( & V_12 -> V_33 , 0 ) ;
F_29 ( V_81 ) ;
}
else
F_61 ( & V_12 -> V_33 , V_81 ) ;
}
if ( F_62 ( V_59 , & V_12 -> V_60 ) && F_63 ( V_12 ) )
F_64 ( & V_12 -> V_33 ) ;
}
static struct V_80 *
F_65 ( struct V_9 * V_12 , struct V_80 * V_81 )
{
int V_83 ;
unsigned char * V_84 ;
int V_85 ;
V_84 = V_81 -> V_84 ;
V_83 = F_66 ( V_84 ) ;
V_85 = V_83 == V_86 && 1 <= V_84 [ 2 ] && V_84 [ 2 ] <= 7 ;
if ( V_84 [ 0 ] == 0 && ( V_12 -> V_57 & V_87 ) && ! V_85 )
F_67 ( V_81 , 1 ) ;
if ( ( V_12 -> V_57 & V_88 ) == 0 || V_85 ) {
if ( F_68 ( V_81 ) < 2 ) {
struct V_80 * V_89 = F_69 ( V_81 -> V_82 + 2 ) ;
if ( V_89 == NULL ) {
F_29 ( V_81 ) ;
return NULL ;
}
F_70 ( V_89 , 2 ) ;
F_71 ( V_81 ,
F_72 ( V_89 , V_81 -> V_82 ) , V_81 -> V_82 ) ;
F_29 ( V_81 ) ;
V_81 = V_89 ;
}
F_73 ( V_81 , 2 ) ;
V_81 -> V_84 [ 0 ] = V_90 ;
V_81 -> V_84 [ 1 ] = V_91 ;
}
V_12 -> V_92 = V_93 ;
if ( V_81 && V_12 -> V_57 & V_94 )
F_3 ( L_5 , V_81 -> V_84 , V_81 -> V_82 ) ;
return V_81 ;
}
static int
F_74 ( struct V_64 * V_33 , struct V_80 * V_81 )
{
struct V_9 * V_12 = V_33 -> V_34 ;
F_63 ( V_12 ) ;
if ( F_75 ( V_95 , & V_12 -> V_60 ) )
return 0 ;
V_81 = F_65 ( V_12 , V_81 ) ;
if ( V_81 != NULL )
V_12 -> V_40 = V_81 ;
else
F_49 ( V_95 , & V_12 -> V_60 ) ;
F_63 ( V_12 ) ;
return 1 ;
}
static int
F_63 ( struct V_9 * V_12 )
{
int V_96 , V_97 = 0 ;
struct V_10 * V_11 = V_12 -> V_11 ;
int V_98 = 0 ;
if ( ! F_76 ( & V_12 -> V_26 ) )
return 0 ;
for (; ; ) {
if ( F_77 ( V_59 , & V_12 -> V_60 ) )
V_98 = 0 ;
if ( ! V_98 && V_12 -> V_40 ) {
F_50 ( V_58 , & V_11 -> V_57 ) ;
V_96 = V_11 -> V_19 -> V_20 ( V_11 , V_12 -> V_40 -> V_84 , V_12 -> V_40 -> V_82 ) ;
if ( V_96 < 0 )
goto V_99;
if ( V_96 < V_12 -> V_40 -> V_82 ) {
V_98 = 1 ;
} else {
F_29 ( V_12 -> V_40 ) ;
V_12 -> V_40 = NULL ;
F_49 ( V_95 , & V_12 -> V_60 ) ;
V_97 = 1 ;
}
continue;
}
F_78 ( & V_12 -> V_26 ) ;
if ( ! ( F_62 ( V_59 , & V_12 -> V_60 ) ||
( ! V_98 && V_12 -> V_40 ) ) )
break;
if ( ! F_76 ( & V_12 -> V_26 ) )
break;
}
return V_97 ;
V_99:
if ( V_12 -> V_40 ) {
F_29 ( V_12 -> V_40 ) ;
V_12 -> V_40 = NULL ;
F_49 ( V_95 , & V_12 -> V_60 ) ;
V_97 = 1 ;
}
F_78 ( & V_12 -> V_26 ) ;
return V_97 ;
}
static void
F_37 ( struct V_9 * V_12 )
{
int V_97 = 0 ;
F_79 ( & V_12 -> V_26 ) ;
if ( V_12 -> V_40 != NULL ) {
F_29 ( V_12 -> V_40 ) ;
V_12 -> V_40 = NULL ;
F_49 ( V_95 , & V_12 -> V_60 ) ;
V_97 = 1 ;
}
F_78 ( & V_12 -> V_26 ) ;
if ( V_97 )
F_64 ( & V_12 -> V_33 ) ;
}
static void
F_43 ( struct V_9 * V_12 , const unsigned char * V_7 ,
char * V_57 , int V_3 )
{
struct V_80 * V_81 ;
unsigned char * V_45 ;
if ( V_3 == 0 )
return;
if ( V_12 -> V_57 & V_100 )
F_3 ( L_6 , V_7 , V_3 ) ;
V_81 = F_69 ( V_12 -> V_24 + V_101 + 2 ) ;
if ( ! V_81 ) {
F_4 ( V_63 L_7 ) ;
goto V_17;
}
if ( V_7 [ 0 ] != V_90 )
F_70 ( V_81 , 2 + ( V_7 [ 0 ] & 1 ) ) ;
if ( V_57 && * V_57 ) {
goto V_17;
} else if ( V_3 > F_80 ( V_81 ) ) {
goto V_17;
}
V_45 = F_72 ( V_81 , V_3 ) ;
memcpy ( V_45 , V_7 , V_3 ) ;
V_45 = V_81 -> V_84 ;
if ( V_45 [ 0 ] == V_90 && V_45 [ 1 ] == V_91 ) {
if ( V_81 -> V_82 < 3 )
goto V_17;
V_45 = F_67 ( V_81 , 2 ) ;
}
if ( V_45 [ 0 ] & 1 ) {
F_73 ( V_81 , 1 ) [ 0 ] = 0 ;
} else if ( V_81 -> V_82 < 2 )
goto V_17;
F_81 ( & V_12 -> V_30 , V_81 ) ;
return;
V_17:
if ( V_81 || ( V_81 = F_69 ( 0 ) ) ) {
F_82 ( V_81 , 0 ) ;
F_81 ( & V_12 -> V_30 , V_81 ) ;
}
}
static void T_8
F_83 ( void )
{
if ( F_84 ( V_61 ) != 0 )
F_4 ( V_63 L_8 ) ;
}
