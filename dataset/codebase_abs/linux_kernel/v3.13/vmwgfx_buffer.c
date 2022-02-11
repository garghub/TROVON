static bool F_1 ( struct V_1 * V_2 )
{
return ++ ( V_2 -> V_3 ) < V_2 -> V_4 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
return F_3 ( & V_2 -> V_5 ) ;
}
static struct V_6 * F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_7 [ V_2 -> V_3 ] ;
}
static struct V_6 * F_5 ( struct V_1 * V_2 )
{
return F_6 ( & V_2 -> V_5 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 -> V_7 [ V_2 -> V_3 ] ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
return V_2 -> V_8 [ V_2 -> V_3 ] ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_5 ) ;
}
void F_12 ( struct V_1 * V_2 , const struct V_9 * V_10 ,
unsigned long V_11 )
{
V_2 -> V_3 = V_11 - 1 ;
V_2 -> V_4 = V_10 -> V_4 ;
switch ( V_10 -> V_12 ) {
case V_13 :
V_2 -> V_14 = & F_1 ;
V_2 -> V_15 = & F_7 ;
V_2 -> V_6 = & F_4 ;
V_2 -> V_7 = V_10 -> V_7 ;
break;
case V_16 :
V_2 -> V_14 = & F_1 ;
V_2 -> V_15 = & F_9 ;
V_2 -> V_6 = & F_4 ;
V_2 -> V_8 = V_10 -> V_8 ;
break;
case V_17 :
case V_18 :
V_2 -> V_14 = & F_2 ;
V_2 -> V_15 = & F_10 ;
V_2 -> V_6 = & F_5 ;
F_13 ( & V_2 -> V_5 , V_10 -> V_19 -> V_20 ,
V_10 -> V_19 -> V_21 , V_11 ) ;
break;
default:
F_14 () ;
}
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 -> V_25 -> V_25 ;
F_16 ( V_25 , V_23 -> V_19 . V_20 , V_23 -> V_19 . V_27 ,
V_28 ) ;
V_23 -> V_19 . V_27 = V_23 -> V_19 . V_21 ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 -> V_25 -> V_25 ;
int V_29 ;
V_29 = F_18 ( V_25 , V_23 -> V_19 . V_20 , V_23 -> V_19 . V_21 ,
V_28 ) ;
if ( F_19 ( V_29 == 0 ) )
return - V_30 ;
V_23 -> V_19 . V_27 = V_29 ;
return 0 ;
}
static int F_20 ( struct V_22 * V_23 )
{
struct V_31 * V_26 = V_23 -> V_26 ;
struct V_32 * V_33 = F_21 ( V_26 ) ;
struct V_9 * V_10 = & V_23 -> V_10 ;
struct V_1 V_5 ;
T_1 V_34 ;
int V_29 = 0 ;
static T_2 V_35 ;
static T_2 V_36 ;
if ( V_23 -> V_37 )
return 0 ;
V_10 -> V_12 = V_26 -> V_38 ;
V_10 -> V_7 = V_23 -> V_39 . V_40 . V_7 ;
V_10 -> V_4 = V_23 -> V_39 . V_40 . V_4 ;
V_10 -> V_8 = V_23 -> V_39 . V_15 ;
V_10 -> V_19 = & V_23 -> V_19 ;
switch ( V_26 -> V_38 ) {
case V_18 :
case V_17 :
if ( F_19 ( ! V_35 ) ) {
V_35 = F_22 ( sizeof( struct V_41 ) ) ;
V_36 = F_22 ( sizeof( struct V_42 ) ) ;
}
V_23 -> V_43 = V_36 + V_35 * V_10 -> V_4 ;
V_29 = F_23 ( V_33 , V_23 -> V_43 , false ,
true ) ;
if ( F_19 ( V_29 != 0 ) )
return V_29 ;
V_29 = F_24 ( & V_23 -> V_19 , V_10 -> V_7 ,
V_10 -> V_4 , 0 ,
( unsigned long )
V_10 -> V_4 << V_44 ,
V_45 ) ;
if ( F_19 ( V_29 != 0 ) )
goto V_46;
if ( V_10 -> V_4 > V_23 -> V_19 . V_27 ) {
T_3 V_47 =
V_35 * ( V_10 -> V_4 -
V_23 -> V_19 . V_27 ) ;
F_25 ( V_33 , V_47 ) ;
V_23 -> V_43 -= V_47 ;
}
V_29 = F_17 ( V_23 ) ;
if ( F_19 ( V_29 != 0 ) )
goto V_48;
break;
default:
break;
}
V_34 = ~ ( ( T_1 ) 0 ) ;
V_23 -> V_10 . V_49 = 0 ;
for ( F_12 ( & V_5 , V_10 , 0 ) ; F_26 ( & V_5 ) ; ) {
T_1 V_50 = F_27 ( & V_5 ) ;
if ( V_50 != V_34 + V_51 )
V_23 -> V_10 . V_49 ++ ;
V_34 = V_50 ;
}
V_23 -> V_37 = true ;
return 0 ;
V_48:
F_28 ( V_23 -> V_10 . V_19 ) ;
V_23 -> V_10 . V_19 = NULL ;
V_46:
F_25 ( V_33 , V_23 -> V_43 ) ;
return V_29 ;
}
static void F_29 ( struct V_22 * V_23 )
{
struct V_31 * V_26 = V_23 -> V_26 ;
if ( ! V_23 -> V_10 . V_19 )
return;
switch ( V_26 -> V_38 ) {
case V_18 :
case V_17 :
F_15 ( V_23 ) ;
F_28 ( V_23 -> V_10 . V_19 ) ;
V_23 -> V_10 . V_19 = NULL ;
F_25 ( F_21 ( V_26 ) ,
V_23 -> V_43 ) ;
break;
default:
break;
}
V_23 -> V_37 = false ;
}
static int F_30 ( struct V_52 * V_40 , struct V_53 * V_54 )
{
struct V_22 * V_55 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
int V_29 ;
V_29 = F_20 ( V_55 ) ;
if ( F_19 ( V_29 != 0 ) )
return V_29 ;
V_55 -> V_56 = V_54 -> V_57 ;
return F_32 ( V_55 -> V_26 , & V_55 -> V_10 ,
V_40 -> V_4 , V_55 -> V_56 ) ;
}
static int F_33 ( struct V_52 * V_40 )
{
struct V_22 * V_55 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
F_34 ( V_55 -> V_26 , V_55 -> V_56 ) ;
if ( V_55 -> V_26 -> V_38 == V_18 )
F_29 ( V_55 ) ;
return 0 ;
}
static void F_35 ( struct V_52 * V_40 )
{
struct V_22 * V_55 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
F_29 ( V_55 ) ;
if ( V_55 -> V_26 -> V_38 == V_16 )
F_36 ( & V_55 -> V_39 ) ;
else
F_37 ( V_40 ) ;
F_38 ( V_55 ) ;
}
static int F_39 ( struct V_52 * V_40 )
{
struct V_22 * V_23 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
struct V_31 * V_26 = V_23 -> V_26 ;
struct V_32 * V_33 = F_21 ( V_26 ) ;
int V_29 ;
if ( V_40 -> V_58 != V_59 )
return 0 ;
if ( V_26 -> V_38 == V_16 ) {
T_2 V_60 =
F_22 ( V_40 -> V_4 * sizeof( T_1 ) ) ;
V_29 = F_23 ( V_33 , V_60 , false , true ) ;
if ( F_19 ( V_29 != 0 ) )
return V_29 ;
V_29 = F_40 ( & V_23 -> V_39 , V_26 -> V_25 -> V_25 ) ;
if ( F_19 ( V_29 != 0 ) )
F_25 ( V_33 , V_60 ) ;
} else
V_29 = F_41 ( V_40 ) ;
return V_29 ;
}
static void F_42 ( struct V_52 * V_40 )
{
struct V_22 * V_23 = F_31 ( V_40 , struct V_22 ,
V_39 . V_40 ) ;
struct V_31 * V_26 = V_23 -> V_26 ;
struct V_32 * V_33 = F_21 ( V_26 ) ;
F_29 ( V_23 ) ;
if ( V_26 -> V_38 == V_16 ) {
T_2 V_60 =
F_22 ( V_40 -> V_4 * sizeof( T_1 ) ) ;
F_43 ( & V_23 -> V_39 , V_26 -> V_25 -> V_25 ) ;
F_25 ( V_33 , V_60 ) ;
} else
F_44 ( V_40 ) ;
}
struct V_52 * F_45 ( struct V_61 * V_62 ,
unsigned long V_60 , T_4 V_63 ,
struct V_6 * V_64 )
{
struct V_22 * V_55 ;
int V_29 ;
V_55 = F_46 ( sizeof( * V_55 ) , V_45 ) ;
if ( ! V_55 )
return NULL ;
V_55 -> V_39 . V_40 . V_65 = & V_66 ;
V_55 -> V_26 = F_31 ( V_62 , struct V_31 , V_62 ) ;
if ( V_55 -> V_26 -> V_38 == V_16 )
V_29 = F_47 ( & V_55 -> V_39 , V_62 , V_60 , V_63 ,
V_64 ) ;
else
V_29 = F_48 ( & V_55 -> V_39 . V_40 , V_62 , V_60 , V_63 ,
V_64 ) ;
if ( F_19 ( V_29 != 0 ) )
goto V_67;
return & V_55 -> V_39 . V_40 ;
V_67:
F_38 ( V_55 ) ;
return NULL ;
}
int F_49 ( struct V_61 * V_62 , T_4 V_68 )
{
return 0 ;
}
int F_50 ( struct V_61 * V_62 , T_4 type ,
struct V_69 * V_70 )
{
switch ( type ) {
case V_71 :
V_70 -> V_68 = V_72 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = V_74 ;
break;
case V_76 :
V_70 -> V_65 = & V_77 ;
V_70 -> V_78 = 0 ;
V_70 -> V_68 = V_79 | V_72 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = V_74 ;
break;
case V_80 :
V_70 -> V_65 = & V_81 ;
V_70 -> V_78 = 0 ;
V_70 -> V_68 = V_82 | V_72 ;
V_70 -> V_73 = V_74 ;
V_70 -> V_75 = V_74 ;
break;
default:
F_51 ( L_1 , ( unsigned ) type ) ;
return - V_83 ;
}
return 0 ;
}
void F_52 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
* V_87 = V_88 ;
}
static int F_53 ( struct V_84 * V_85 , struct V_89 * V_90 )
{
struct V_91 * V_92 =
F_54 ( (struct V_93 * ) V_90 -> V_94 ) -> V_92 ;
return F_55 ( V_85 , V_92 ) ;
}
static int F_56 ( struct V_61 * V_62 , struct V_53 * V_95 )
{
struct V_69 * V_70 = & V_62 -> V_70 [ V_95 -> V_96 ] ;
struct V_31 * V_26 = F_31 ( V_62 , struct V_31 , V_62 ) ;
V_95 -> V_97 . V_98 = NULL ;
V_95 -> V_97 . V_99 = false ;
V_95 -> V_97 . V_100 = 0 ;
V_95 -> V_97 . V_60 = V_95 -> V_4 << V_44 ;
V_95 -> V_97 . V_101 = 0 ;
if ( ! ( V_70 -> V_68 & V_72 ) )
return - V_83 ;
switch ( V_95 -> V_96 ) {
case V_71 :
case V_80 :
return 0 ;
case V_76 :
V_95 -> V_97 . V_100 = V_95 -> V_57 << V_44 ;
V_95 -> V_97 . V_101 = V_26 -> V_102 ;
V_95 -> V_97 . V_99 = true ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static void F_57 ( struct V_61 * V_62 , struct V_53 * V_95 )
{
}
static int F_58 ( struct V_84 * V_85 )
{
return 0 ;
}
static void * F_59 ( void * V_103 )
{
return ( void * )
F_60 ( (struct V_104 * ) V_103 ) ;
}
static void F_61 ( void * * V_103 )
{
F_62 ( (struct V_104 * * ) V_103 ) ;
}
static int F_63 ( void * V_103 )
{
F_64 ( (struct V_104 * ) V_103 ) ;
return 0 ;
}
static bool F_65 ( void * V_103 )
{
return F_66 ( (struct V_104 * ) V_103 ,
V_105 ) ;
}
static int F_67 ( void * V_103 , bool V_106 , bool V_107 )
{
return F_68 ( (struct V_104 * ) V_103 ,
V_105 ,
V_106 , V_107 ,
V_108 ) ;
}
