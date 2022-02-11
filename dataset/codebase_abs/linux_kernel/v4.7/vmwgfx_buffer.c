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
V_2 -> V_7 = V_10 -> V_7 ;
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
int F_30 ( struct V_52 * V_53 )
{
struct V_22 * V_23 =
F_31 ( V_53 -> V_40 , struct V_22 , V_39 . V_40 ) ;
return F_20 ( V_23 ) ;
}
void F_32 ( struct V_52 * V_53 )
{
struct V_22 * V_23 =
F_31 ( V_53 -> V_40 , struct V_22 , V_39 . V_40 ) ;
F_29 ( V_23 ) ;
}
const struct V_9 * F_33 ( struct V_52 * V_53 )
{
struct V_22 * V_23 =
F_31 ( V_53 -> V_40 , struct V_22 , V_39 . V_40 ) ;
return & V_23 -> V_10 ;
}
static int F_34 ( struct V_54 * V_40 , struct V_55 * V_56 )
{
struct V_22 * V_57 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
int V_29 ;
V_29 = F_20 ( V_57 ) ;
if ( F_19 ( V_29 != 0 ) )
return V_29 ;
V_57 -> V_58 = V_56 -> V_59 ;
V_57 -> V_60 = V_56 -> V_60 ;
switch ( V_56 -> V_60 ) {
case V_61 :
return F_35 ( V_57 -> V_26 , & V_57 -> V_10 ,
V_40 -> V_4 , V_57 -> V_58 ) ;
case V_62 :
if ( F_19 ( V_57 -> V_63 == NULL ) ) {
V_57 -> V_63 =
F_36 ( V_40 -> V_4 ) ;
if ( F_19 ( V_57 -> V_63 == NULL ) )
return - V_30 ;
}
return F_37 ( V_57 -> V_26 , V_57 -> V_63 ,
& V_57 -> V_10 , V_40 -> V_4 ,
V_57 -> V_58 ) ;
default:
F_14 () ;
}
return 0 ;
}
static int F_38 ( struct V_54 * V_40 )
{
struct V_22 * V_57 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
switch ( V_57 -> V_60 ) {
case V_61 :
F_39 ( V_57 -> V_26 , V_57 -> V_58 ) ;
break;
case V_62 :
F_40 ( V_57 -> V_26 , V_57 -> V_63 ) ;
break;
default:
F_14 () ;
}
if ( V_57 -> V_26 -> V_38 == V_18 )
F_29 ( V_57 ) ;
return 0 ;
}
static void F_41 ( struct V_54 * V_40 )
{
struct V_22 * V_57 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
F_29 ( V_57 ) ;
if ( V_57 -> V_26 -> V_38 == V_16 )
F_42 ( & V_57 -> V_39 ) ;
else
F_43 ( V_40 ) ;
if ( V_57 -> V_63 )
F_44 ( V_57 -> V_63 ) ;
F_45 ( V_57 ) ;
}
static int F_46 ( struct V_54 * V_40 )
{
struct V_22 * V_23 =
F_31 ( V_40 , struct V_22 , V_39 . V_40 ) ;
struct V_31 * V_26 = V_23 -> V_26 ;
struct V_32 * V_33 = F_21 ( V_26 ) ;
int V_29 ;
if ( V_40 -> V_64 != V_65 )
return 0 ;
if ( V_26 -> V_38 == V_16 ) {
T_2 V_66 =
F_22 ( V_40 -> V_4 * sizeof( T_1 ) ) ;
V_29 = F_23 ( V_33 , V_66 , false , true ) ;
if ( F_19 ( V_29 != 0 ) )
return V_29 ;
V_29 = F_47 ( & V_23 -> V_39 , V_26 -> V_25 -> V_25 ) ;
if ( F_19 ( V_29 != 0 ) )
F_25 ( V_33 , V_66 ) ;
} else
V_29 = F_48 ( V_40 ) ;
return V_29 ;
}
static void F_49 ( struct V_54 * V_40 )
{
struct V_22 * V_23 = F_31 ( V_40 , struct V_22 ,
V_39 . V_40 ) ;
struct V_31 * V_26 = V_23 -> V_26 ;
struct V_32 * V_33 = F_21 ( V_26 ) ;
if ( V_23 -> V_63 ) {
F_44 ( V_23 -> V_63 ) ;
V_23 -> V_63 = NULL ;
}
F_29 ( V_23 ) ;
if ( V_26 -> V_38 == V_16 ) {
T_2 V_66 =
F_22 ( V_40 -> V_4 * sizeof( T_1 ) ) ;
F_50 ( & V_23 -> V_39 , V_26 -> V_25 -> V_25 ) ;
F_25 ( V_33 , V_66 ) ;
} else
F_51 ( V_40 ) ;
}
static struct V_54 * F_52 ( struct V_67 * V_68 ,
unsigned long V_66 , T_4 V_69 ,
struct V_6 * V_70 )
{
struct V_22 * V_57 ;
int V_29 ;
V_57 = F_53 ( sizeof( * V_57 ) , V_45 ) ;
if ( ! V_57 )
return NULL ;
V_57 -> V_39 . V_40 . V_71 = & V_72 ;
V_57 -> V_26 = F_31 ( V_68 , struct V_31 , V_68 ) ;
V_57 -> V_63 = NULL ;
if ( V_57 -> V_26 -> V_38 == V_16 )
V_29 = F_54 ( & V_57 -> V_39 , V_68 , V_66 , V_69 ,
V_70 ) ;
else
V_29 = F_55 ( & V_57 -> V_39 . V_40 , V_68 , V_66 , V_69 ,
V_70 ) ;
if ( F_19 ( V_29 != 0 ) )
goto V_73;
return & V_57 -> V_39 . V_40 ;
V_73:
F_45 ( V_57 ) ;
return NULL ;
}
static int F_56 ( struct V_67 * V_68 , T_4 V_74 )
{
return 0 ;
}
static int F_57 ( struct V_67 * V_68 , T_4 type ,
struct V_75 * V_76 )
{
switch ( type ) {
case V_77 :
V_76 -> V_74 = V_78 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_80 ;
break;
case V_82 :
V_76 -> V_71 = & V_83 ;
V_76 -> V_84 = 0 ;
V_76 -> V_74 = V_85 | V_78 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_80 ;
break;
case V_61 :
case V_62 :
V_76 -> V_71 = & V_86 ;
V_76 -> V_84 = 0 ;
V_76 -> V_74 = V_87 | V_78 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_80 ;
break;
default:
F_58 ( L_1 , ( unsigned ) type ) ;
return - V_88 ;
}
return 0 ;
}
static void F_59 ( struct V_52 * V_53 ,
struct V_89 * V_90 )
{
* V_90 = V_91 ;
}
static int F_60 ( struct V_52 * V_53 , struct V_92 * V_93 )
{
struct V_94 * V_95 =
F_61 ( (struct V_96 * ) V_93 -> V_97 ) -> V_95 ;
return F_62 ( V_53 , V_95 ) ;
}
static int F_63 ( struct V_67 * V_68 , struct V_55 * V_98 )
{
struct V_75 * V_76 = & V_68 -> V_76 [ V_98 -> V_60 ] ;
struct V_31 * V_26 = F_31 ( V_68 , struct V_31 , V_68 ) ;
V_98 -> V_99 . V_100 = NULL ;
V_98 -> V_99 . V_101 = false ;
V_98 -> V_99 . V_102 = 0 ;
V_98 -> V_99 . V_66 = V_98 -> V_4 << V_44 ;
V_98 -> V_99 . V_103 = 0 ;
if ( ! ( V_76 -> V_74 & V_78 ) )
return - V_88 ;
switch ( V_98 -> V_60 ) {
case V_77 :
case V_61 :
case V_62 :
return 0 ;
case V_82 :
V_98 -> V_99 . V_102 = V_98 -> V_59 << V_44 ;
V_98 -> V_99 . V_103 = V_26 -> V_104 ;
V_98 -> V_99 . V_101 = true ;
break;
default:
return - V_88 ;
}
return 0 ;
}
static void F_64 ( struct V_67 * V_68 , struct V_55 * V_98 )
{
}
static int F_65 ( struct V_52 * V_53 )
{
return 0 ;
}
static void F_66 ( struct V_52 * V_53 ,
struct V_55 * V_98 )
{
F_67 ( V_53 , V_98 ) ;
F_68 ( V_53 , V_98 ) ;
}
static void F_69 ( struct V_52 * V_53 )
{
F_70 ( V_53 , false , false ) ;
}
