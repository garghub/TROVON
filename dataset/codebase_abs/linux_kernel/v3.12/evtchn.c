static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * * V_6 = & ( V_2 -> V_7 . V_5 ) , * V_8 = NULL ;
while ( * V_6 ) {
struct V_3 * V_9 ;
V_9 = F_2 ( * V_6 , struct V_3 , V_10 ) ;
V_8 = * V_6 ;
if ( V_9 -> V_11 < V_4 -> V_11 )
V_6 = & ( ( * V_6 ) -> V_12 ) ;
else if ( V_9 -> V_11 > V_4 -> V_11 )
V_6 = & ( ( * V_6 ) -> V_13 ) ;
else
return - V_14 ;
}
F_3 ( & V_4 -> V_10 , V_8 , V_6 ) ;
F_4 ( & V_4 -> V_10 , & V_2 -> V_7 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_6 ( & V_4 -> V_10 , & V_2 -> V_7 ) ;
F_7 ( V_4 ) ;
}
static struct V_3 * F_8 ( struct V_1 * V_2 , unsigned V_11 )
{
struct V_5 * V_10 = V_2 -> V_7 . V_5 ;
while ( V_10 ) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_10 , struct V_3 , V_10 ) ;
if ( V_4 -> V_11 < V_11 )
V_10 = V_10 -> V_12 ;
else if ( V_4 -> V_11 > V_11 )
V_10 = V_10 -> V_13 ;
else
return V_4 ;
}
return NULL ;
}
static T_1 F_9 ( int V_15 , void * V_16 )
{
struct V_3 * V_4 = V_16 ;
struct V_1 * V_2 = V_4 -> V_17 ;
F_10 ( ! V_4 -> V_18 ,
L_1 ,
V_4 -> V_11 , V_2 ) ;
F_11 ( V_15 ) ;
V_4 -> V_18 = false ;
F_12 ( & V_2 -> V_19 ) ;
if ( ( V_2 -> V_20 - V_2 -> V_21 ) < V_22 ) {
V_2 -> V_23 [ F_13 ( V_2 -> V_20 ) ] = V_4 -> V_11 ;
F_14 () ;
if ( V_2 -> V_21 == V_2 -> V_20 ++ ) {
F_15 ( & V_2 -> V_24 ) ;
F_16 ( & V_2 -> V_25 ,
V_26 , V_27 ) ;
}
} else
V_2 -> V_28 = 1 ;
F_17 ( & V_2 -> V_19 ) ;
return V_29 ;
}
static T_2 F_18 ( struct V_30 * V_30 , char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
int V_34 ;
unsigned int V_35 , V_36 , V_37 = 0 , V_38 = 0 ;
struct V_1 * V_2 = V_30 -> V_39 ;
V_32 &= ~ ( sizeof( V_40 ) - 1 ) ;
if ( V_32 == 0 )
return 0 ;
if ( V_32 > V_41 )
V_32 = V_41 ;
for (; ; ) {
F_19 ( & V_2 -> V_42 ) ;
V_34 = - V_43 ;
if ( V_2 -> V_28 )
goto V_44;
V_35 = V_2 -> V_21 ;
V_36 = V_2 -> V_20 ;
if ( V_35 != V_36 )
break;
F_20 ( & V_2 -> V_42 ) ;
if ( V_30 -> V_45 & V_46 )
return - V_47 ;
V_34 = F_21 ( V_2 -> V_24 ,
V_2 -> V_21 != V_2 -> V_20 ) ;
if ( V_34 )
return V_34 ;
}
if ( ( ( V_35 ^ V_36 ) & V_22 ) != 0 ) {
V_37 = ( V_22 - F_13 ( V_35 ) ) *
sizeof( V_40 ) ;
V_38 = F_13 ( V_36 ) * sizeof( V_40 ) ;
} else {
V_37 = ( V_36 - V_35 ) * sizeof( V_40 ) ;
V_38 = 0 ;
}
if ( V_37 > V_32 ) {
V_37 = V_32 ;
V_38 = 0 ;
} else if ( ( V_37 + V_38 ) > V_32 ) {
V_38 = V_32 - V_37 ;
}
V_34 = - V_48 ;
F_22 () ;
if ( F_23 ( V_31 , & V_2 -> V_23 [ F_13 ( V_35 ) ] , V_37 ) ||
( ( V_38 != 0 ) &&
F_23 ( & V_31 [ V_37 ] , & V_2 -> V_23 [ 0 ] , V_38 ) ) )
goto V_44;
V_2 -> V_21 += ( V_37 + V_38 ) / sizeof( V_40 ) ;
V_34 = V_37 + V_38 ;
V_44:
F_20 ( & V_2 -> V_42 ) ;
return V_34 ;
}
static T_2 F_24 ( struct V_30 * V_30 , const char T_3 * V_31 ,
T_4 V_32 , T_5 * V_33 )
{
int V_34 , V_49 ;
V_40 * V_50 = ( V_40 * ) F_25 ( V_51 ) ;
struct V_1 * V_2 = V_30 -> V_39 ;
if ( V_50 == NULL )
return - V_52 ;
V_32 &= ~ ( sizeof( V_40 ) - 1 ) ;
V_34 = 0 ;
if ( V_32 == 0 )
goto V_53;
if ( V_32 > V_41 )
V_32 = V_41 ;
V_34 = - V_48 ;
if ( F_26 ( V_50 , V_31 , V_32 ) != 0 )
goto V_53;
F_19 ( & V_2 -> V_54 ) ;
for ( V_49 = 0 ; V_49 < ( V_32 / sizeof( V_40 ) ) ; V_49 ++ ) {
unsigned V_11 = V_50 [ V_49 ] ;
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 , V_11 ) ;
if ( V_4 && ! V_4 -> V_18 ) {
V_4 -> V_18 = true ;
F_27 ( F_28 ( V_11 ) ) ;
}
}
F_20 ( & V_2 -> V_54 ) ;
V_34 = V_32 ;
V_53:
F_29 ( ( unsigned long ) V_50 ) ;
return V_34 ;
}
static int F_30 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 ;
struct V_55 V_56 ;
int V_34 = 0 ;
V_4 = F_31 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_17 = V_2 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_18 = true ;
V_34 = F_1 ( V_2 , V_4 ) ;
if ( V_34 < 0 )
goto V_57;
V_34 = F_32 ( V_11 , F_9 , V_58 ,
V_2 -> V_59 , V_4 ) ;
if ( V_34 < 0 )
goto V_57;
V_34 = F_33 ( V_11 ) ;
return V_34 ;
V_57:
V_56 . V_11 = V_11 ;
if ( F_34 ( V_60 , & V_56 ) != 0 )
F_35 () ;
F_5 ( V_2 , V_4 ) ;
return V_34 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_15 = F_28 ( V_4 -> V_11 ) ;
F_37 ( V_15 < 0 ) ;
F_38 ( V_15 , V_4 ) ;
F_5 ( V_2 , V_4 ) ;
}
static long F_39 ( struct V_30 * V_30 ,
unsigned int V_61 , unsigned long V_62 )
{
int V_34 ;
struct V_1 * V_2 = V_30 -> V_39 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
F_19 ( & V_2 -> V_54 ) ;
switch ( V_61 ) {
case V_64 : {
struct V_65 V_66 ;
struct V_67 V_68 ;
V_34 = - V_48 ;
if ( F_26 ( & V_66 , V_63 , sizeof( V_66 ) ) )
break;
V_68 . V_69 = V_66 . V_69 ;
V_68 . V_70 = 0 ;
V_34 = F_34 ( V_71 ,
& V_68 ) ;
if ( V_34 != 0 )
break;
V_34 = F_30 ( V_2 , V_68 . V_11 ) ;
if ( V_34 == 0 )
V_34 = V_68 . V_11 ;
break;
}
case V_72 : {
struct V_73 V_66 ;
struct V_74 V_75 ;
V_34 = - V_48 ;
if ( F_26 ( & V_66 , V_63 , sizeof( V_66 ) ) )
break;
V_75 . V_76 = V_66 . V_77 ;
V_75 . V_78 = V_66 . V_78 ;
V_34 = F_34 ( V_79 ,
& V_75 ) ;
if ( V_34 != 0 )
break;
V_34 = F_30 ( V_2 , V_75 . V_80 ) ;
if ( V_34 == 0 )
V_34 = V_75 . V_80 ;
break;
}
case V_81 : {
struct V_82 V_66 ;
struct V_83 V_84 ;
V_34 = - V_48 ;
if ( F_26 ( & V_66 , V_63 , sizeof( V_66 ) ) )
break;
V_84 . V_85 = V_86 ;
V_84 . V_76 = V_66 . V_77 ;
V_34 = F_34 ( V_87 ,
& V_84 ) ;
if ( V_34 != 0 )
break;
V_34 = F_30 ( V_2 , V_84 . V_11 ) ;
if ( V_34 == 0 )
V_34 = V_84 . V_11 ;
break;
}
case V_88 : {
struct V_89 V_90 ;
struct V_3 * V_4 ;
V_34 = - V_48 ;
if ( F_26 ( & V_90 , V_63 , sizeof( V_90 ) ) )
break;
V_34 = - V_91 ;
if ( V_90 . V_11 >= V_92 )
break;
V_34 = - V_93 ;
V_4 = F_8 ( V_2 , V_90 . V_11 ) ;
if ( ! V_4 )
break;
F_40 ( F_28 ( V_90 . V_11 ) ) ;
F_36 ( V_2 , V_4 ) ;
V_34 = 0 ;
break;
}
case V_94 : {
struct V_95 V_96 ;
struct V_3 * V_4 ;
V_34 = - V_48 ;
if ( F_26 ( & V_96 , V_63 , sizeof( V_96 ) ) )
break;
V_34 = - V_93 ;
V_4 = F_8 ( V_2 , V_96 . V_11 ) ;
if ( V_4 ) {
F_41 ( V_96 . V_11 ) ;
V_34 = 0 ;
}
break;
}
case V_97 : {
F_19 ( & V_2 -> V_42 ) ;
F_42 ( & V_2 -> V_19 ) ;
V_2 -> V_21 = V_2 -> V_20 = V_2 -> V_28 = 0 ;
F_43 ( & V_2 -> V_19 ) ;
F_20 ( & V_2 -> V_42 ) ;
V_34 = 0 ;
break;
}
default:
V_34 = - V_98 ;
break;
}
F_20 ( & V_2 -> V_54 ) ;
return V_34 ;
}
static unsigned int F_44 ( struct V_30 * V_30 , T_6 * V_99 )
{
unsigned int V_100 = V_101 | V_102 ;
struct V_1 * V_2 = V_30 -> V_39 ;
F_45 ( V_30 , & V_2 -> V_24 , V_99 ) ;
if ( V_2 -> V_21 != V_2 -> V_20 )
V_100 |= V_103 | V_104 ;
if ( V_2 -> V_28 )
V_100 = V_105 ;
return V_100 ;
}
static int F_46 ( int V_106 , struct V_30 * V_107 , int V_108 )
{
struct V_1 * V_2 = V_107 -> V_39 ;
return F_47 ( V_106 , V_107 , V_108 , & V_2 -> V_25 ) ;
}
static int F_48 ( struct V_109 * V_109 , struct V_30 * V_107 )
{
struct V_1 * V_2 ;
V_2 = F_31 ( sizeof( * V_2 ) , V_51 ) ;
if ( V_2 == NULL )
return - V_52 ;
V_2 -> V_59 = F_49 ( V_51 , L_2 , V_110 -> V_111 ) ;
if ( V_2 -> V_59 == NULL ) {
F_7 ( V_2 ) ;
return - V_52 ;
}
F_50 ( & V_2 -> V_24 ) ;
V_2 -> V_23 = ( V_40 * ) F_25 ( V_51 ) ;
if ( V_2 -> V_23 == NULL ) {
F_7 ( V_2 -> V_59 ) ;
F_7 ( V_2 ) ;
return - V_52 ;
}
F_51 ( & V_2 -> V_54 ) ;
F_51 ( & V_2 -> V_42 ) ;
F_52 ( & V_2 -> V_19 ) ;
V_107 -> V_39 = V_2 ;
return F_53 ( V_109 , V_107 ) ;
}
static int F_54 ( struct V_109 * V_109 , struct V_30 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_39 ;
struct V_5 * V_10 ;
while ( ( V_10 = V_2 -> V_7 . V_5 ) ) {
struct V_3 * V_4 ;
V_4 = F_55 ( V_10 , struct V_3 , V_10 ) ;
F_40 ( F_28 ( V_4 -> V_11 ) ) ;
F_36 ( V_2 , V_4 ) ;
}
F_29 ( ( unsigned long ) V_2 -> V_23 ) ;
F_7 ( V_2 -> V_59 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int T_7 F_56 ( void )
{
int V_57 ;
if ( ! F_57 () )
return - V_112 ;
V_57 = F_58 ( & V_113 ) ;
if ( V_57 != 0 ) {
F_59 ( L_3 ) ;
return V_57 ;
}
F_60 ( L_4 ) ;
return 0 ;
}
static void T_8 F_61 ( void )
{
F_62 ( & V_113 ) ;
}
