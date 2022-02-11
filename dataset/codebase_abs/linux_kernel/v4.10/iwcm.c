const char * T_1 F_1 ( int V_1 )
{
T_2 V_2 ;
V_2 = - V_1 ;
if ( V_2 < F_2 ( V_3 ) &&
V_3 [ V_2 ] )
return V_3 [ V_2 ] ;
else
return L_1 ;
}
static struct V_4 * F_3 ( struct V_5 * V_6 )
{
struct V_4 * V_7 ;
if ( F_4 ( & V_6 -> V_8 ) )
return NULL ;
V_7 = F_5 ( V_6 -> V_8 . V_9 , struct V_4 ,
V_10 ) ;
F_6 ( & V_7 -> V_10 ) ;
return V_7 ;
}
static void F_7 ( struct V_4 * V_7 )
{
F_8 ( & V_7 -> V_10 , & V_7 -> V_11 -> V_8 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
struct V_12 * V_13 , * V_14 ;
F_10 (e, tmp, &cm_id_priv->work_free_list)
F_11 ( F_5 ( V_13 , struct V_4 , V_10 ) ) ;
}
static int F_12 ( struct V_5 * V_6 , int V_15 )
{
struct V_4 * V_7 ;
F_13 ( ! F_4 ( & V_6 -> V_8 ) ) ;
while ( V_15 -- ) {
V_7 = F_14 ( sizeof( struct V_4 ) , V_16 ) ;
if ( ! V_7 ) {
F_9 ( V_6 ) ;
return - V_17 ;
}
V_7 -> V_11 = V_6 ;
F_15 ( & V_7 -> V_18 ) ;
F_7 ( V_7 ) ;
}
return 0 ;
}
static int F_16 ( struct V_19 * V_20 )
{
void * V_21 ;
V_21 = F_17 ( V_20 -> V_22 , V_20 -> V_23 , V_24 ) ;
if ( ! V_21 )
return - V_17 ;
V_20 -> V_22 = V_21 ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 )
{
F_9 ( V_6 ) ;
F_11 ( V_6 ) ;
}
static int F_19 ( struct V_5 * V_6 )
{
F_13 ( F_20 ( & V_6 -> V_25 ) == 0 ) ;
if ( F_21 ( & V_6 -> V_25 ) ) {
F_13 ( ! F_4 ( & V_6 -> V_26 ) ) ;
F_18 ( V_6 ) ;
return 1 ;
}
return 0 ;
}
static void F_22 ( struct V_27 * V_11 )
{
struct V_5 * V_6 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_24 ( & V_6 -> V_25 ) ;
}
static void F_25 ( struct V_27 * V_11 )
{
struct V_5 * V_6 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
( void ) F_19 ( V_6 ) ;
}
struct V_27 * F_26 ( struct V_29 * V_30 ,
T_3 V_31 ,
void * V_32 )
{
struct V_5 * V_6 ;
V_6 = F_27 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return F_28 ( - V_17 ) ;
V_6 -> V_33 = V_34 ;
V_6 -> V_28 . V_30 = V_30 ;
V_6 -> V_28 . V_31 = V_31 ;
V_6 -> V_28 . V_32 = V_32 ;
V_6 -> V_28 . V_35 = V_36 ;
V_6 -> V_28 . F_22 = F_22 ;
V_6 -> V_28 . F_25 = F_25 ;
F_29 ( & V_6 -> V_37 ) ;
F_30 ( & V_6 -> V_25 , 1 ) ;
F_31 ( & V_6 -> V_38 ) ;
F_32 ( & V_6 -> V_39 ) ;
F_15 ( & V_6 -> V_26 ) ;
F_15 ( & V_6 -> V_8 ) ;
return & V_6 -> V_28 ;
}
static int F_33 ( struct V_40 * V_41 )
{
struct V_42 V_43 ;
if ( ! V_41 )
return - V_44 ;
V_43 . V_45 = V_46 ;
return F_34 ( V_41 , & V_43 , V_47 ) ;
}
static int F_35 ( struct V_40 * V_41 )
{
struct V_42 V_43 ;
F_13 ( V_41 == NULL ) ;
V_43 . V_45 = V_48 ;
return F_34 ( V_41 , & V_43 , V_47 ) ;
}
int F_36 ( struct V_27 * V_11 , int V_49 )
{
struct V_5 * V_6 ;
unsigned long V_50 ;
int V_51 = 0 ;
struct V_40 * V_41 = NULL ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_37 ( V_6 -> V_38 ,
! F_38 ( V_52 , & V_6 -> V_50 ) ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
switch ( V_6 -> V_33 ) {
case V_53 :
V_6 -> V_33 = V_54 ;
if ( V_6 -> V_41 )
V_41 = V_6 -> V_41 ;
else
V_51 = - V_44 ;
break;
case V_55 :
V_51 = - V_44 ;
break;
case V_54 :
case V_34 :
break;
case V_56 :
break;
case V_57 :
default:
F_40 () ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
if ( V_41 ) {
if ( V_49 )
V_51 = F_33 ( V_41 ) ;
else
V_51 = F_35 ( V_41 ) ;
V_51 = 0 ;
}
return V_51 ;
}
static void F_42 ( struct V_27 * V_11 )
{
struct V_5 * V_6 ;
unsigned long V_50 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_37 ( V_6 -> V_38 ,
! F_38 ( V_52 , & V_6 -> V_50 ) ) ;
F_43 ( V_58 , & V_6 -> V_50 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
switch ( V_6 -> V_33 ) {
case V_55 :
V_6 -> V_33 = V_59 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_11 -> V_30 -> V_60 -> V_61 ( V_11 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
break;
case V_53 :
V_6 -> V_33 = V_59 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
( void ) F_33 ( V_6 -> V_41 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
break;
case V_34 :
case V_54 :
V_6 -> V_33 = V_59 ;
break;
case V_56 :
V_6 -> V_33 = V_59 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_11 -> V_30 -> V_60 -> V_62 ( V_11 , NULL , 0 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
break;
case V_57 :
case V_59 :
default:
F_40 () ;
break;
}
if ( V_6 -> V_41 ) {
V_6 -> V_28 . V_30 -> V_60 -> F_25 ( V_6 -> V_41 ) ;
V_6 -> V_41 = NULL ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
if ( V_11 -> V_63 ) {
F_44 ( & V_11 -> V_64 , & V_11 -> V_65 ) ;
F_45 ( & V_11 -> V_64 , V_66 ) ;
}
( void ) F_19 ( V_6 ) ;
}
void F_46 ( struct V_27 * V_11 )
{
struct V_5 * V_6 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_42 ( V_11 ) ;
}
static void F_47 ( struct V_67 * V_68 ,
struct V_67 * V_69 ,
struct V_67 * V_70 )
{
if ( V_68 -> V_71 == V_72 ) {
struct V_73 * V_74 = (struct V_73 * ) V_68 ;
if ( V_74 -> V_75 . V_76 == F_48 ( V_77 ) ) {
struct V_73 * V_78 =
(struct V_73 * ) V_69 ;
struct V_73 * V_79 =
(struct V_73 * ) V_70 ;
V_79 -> V_75 = V_78 -> V_75 ;
}
} else {
struct V_80 * V_81 = (struct V_80 * ) V_68 ;
if ( F_49 ( & V_81 -> V_82 ) == V_83 ) {
struct V_80 * V_84 =
(struct V_80 * ) V_69 ;
struct V_80 * V_85 =
(struct V_80 * ) V_70 ;
V_85 -> V_82 = V_84 -> V_82 ;
}
}
}
static int F_50 ( struct V_27 * V_11 , bool V_86 )
{
struct V_87 V_88 ;
struct V_89 V_90 ;
int V_91 ;
V_11 -> V_65 = V_11 -> V_64 ;
V_11 -> V_92 = V_11 -> V_93 ;
memcpy ( V_88 . V_94 , V_11 -> V_30 -> V_95 ,
sizeof( V_88 . V_94 ) ) ;
memcpy ( V_88 . V_96 , V_11 -> V_30 -> V_60 -> V_97 ,
sizeof( V_88 . V_96 ) ) ;
if ( F_51 ( & V_88 , V_66 ) ||
! F_52 () )
return 0 ;
V_11 -> V_63 = true ;
V_90 . V_98 = V_11 -> V_64 ;
V_90 . V_99 = V_11 -> V_93 ;
if ( V_86 )
V_91 = F_53 ( & V_90 ,
V_66 ) ;
else
V_91 = F_54 ( & V_90 , V_66 ) ;
if ( ! V_91 ) {
V_11 -> V_65 = V_90 . V_100 ;
if ( V_86 ) {
V_11 -> V_92 = V_90 . V_101 ;
F_47 ( & V_90 . V_101 ,
& V_11 -> V_93 ,
& V_11 -> V_92 ) ;
}
}
return F_55 ( & V_11 -> V_64 ,
& V_11 -> V_65 ,
V_66 ) ;
}
int F_56 ( struct V_27 * V_11 , int V_102 )
{
struct V_5 * V_6 ;
unsigned long V_50 ;
int V_51 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
if ( ! V_102 )
V_102 = V_103 ;
V_51 = F_12 ( V_6 , V_102 ) ;
if ( V_51 )
return V_51 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
switch ( V_6 -> V_33 ) {
case V_34 :
V_6 -> V_33 = V_55 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = F_50 ( V_11 , false ) ;
if ( ! V_51 )
V_51 = V_11 -> V_30 -> V_60 -> V_104 ( V_11 , V_102 ) ;
if ( V_51 )
V_6 -> V_33 = V_34 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
break;
default:
V_51 = - V_44 ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
return V_51 ;
}
int F_57 ( struct V_27 * V_11 ,
const void * V_22 ,
T_4 V_23 )
{
struct V_5 * V_6 ;
unsigned long V_50 ;
int V_51 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_43 ( V_52 , & V_6 -> V_50 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_33 != V_56 ) {
F_41 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
return - V_44 ;
}
V_6 -> V_33 = V_34 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = V_11 -> V_30 -> V_60 -> V_62 ( V_11 , V_22 ,
V_23 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
return V_51 ;
}
int F_60 ( struct V_27 * V_11 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 ;
struct V_40 * V_41 ;
unsigned long V_50 ;
int V_51 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_43 ( V_52 , & V_6 -> V_50 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_33 != V_56 ) {
F_41 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
return - V_44 ;
}
V_41 = V_11 -> V_30 -> V_60 -> V_107 ( V_11 -> V_30 , V_106 -> V_108 ) ;
if ( ! V_41 ) {
F_41 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
return - V_44 ;
}
V_11 -> V_30 -> V_60 -> F_22 ( V_41 ) ;
V_6 -> V_41 = V_41 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = V_11 -> V_30 -> V_60 -> V_109 ( V_11 , V_106 ) ;
if ( V_51 ) {
F_13 ( V_6 -> V_33 != V_56 ) ;
V_6 -> V_33 = V_34 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_41 ) {
V_11 -> V_30 -> V_60 -> F_25 ( V_41 ) ;
V_6 -> V_41 = NULL ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
}
return V_51 ;
}
int F_61 ( struct V_27 * V_11 , struct V_105 * V_106 )
{
struct V_5 * V_6 ;
int V_51 ;
unsigned long V_50 ;
struct V_40 * V_41 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
V_51 = F_12 ( V_6 , 4 ) ;
if ( V_51 )
return V_51 ;
F_43 ( V_52 , & V_6 -> V_50 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_33 != V_34 ) {
V_51 = - V_44 ;
goto V_110;
}
V_41 = V_11 -> V_30 -> V_60 -> V_107 ( V_11 -> V_30 , V_106 -> V_108 ) ;
if ( ! V_41 ) {
V_51 = - V_44 ;
goto V_110;
}
V_11 -> V_30 -> V_60 -> F_22 ( V_41 ) ;
V_6 -> V_41 = V_41 ;
V_6 -> V_33 = V_57 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = F_50 ( V_11 , true ) ;
if ( ! V_51 )
V_51 = V_11 -> V_30 -> V_60 -> V_111 ( V_11 , V_106 ) ;
if ( ! V_51 )
return 0 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_41 ) {
V_11 -> V_30 -> V_60 -> F_25 ( V_41 ) ;
V_6 -> V_41 = NULL ;
}
V_6 -> V_33 = V_34 ;
V_110:
F_41 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_59 ( & V_6 -> V_38 ) ;
return V_51 ;
}
static void F_62 ( struct V_5 * V_112 ,
struct V_19 * V_113 )
{
unsigned long V_50 ;
struct V_27 * V_11 ;
struct V_5 * V_6 ;
int V_51 ;
F_13 ( V_113 -> V_91 ) ;
V_11 = F_26 ( V_112 -> V_28 . V_30 ,
V_112 -> V_28 . V_31 ,
V_112 -> V_28 . V_32 ) ;
if ( F_63 ( V_11 ) )
goto V_114;
V_11 -> V_115 = V_113 -> V_115 ;
V_11 -> V_65 = V_113 -> V_64 ;
V_11 -> V_92 = V_113 -> V_93 ;
V_11 -> V_64 = V_112 -> V_28 . V_64 ;
V_51 = F_64 ( & V_112 -> V_28 . V_65 ,
& V_113 -> V_93 ,
& V_11 -> V_93 ,
V_66 ) ;
if ( V_51 ) {
V_11 -> V_93 = V_113 -> V_93 ;
} else {
F_47 ( & V_112 -> V_28 . V_65 ,
& V_113 -> V_64 ,
& V_11 -> V_64 ) ;
V_113 -> V_64 = V_11 -> V_64 ;
V_113 -> V_93 = V_11 -> V_93 ;
}
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
V_6 -> V_33 = V_56 ;
F_39 ( & V_112 -> V_37 , V_50 ) ;
if ( V_112 -> V_33 != V_55 ) {
F_41 ( & V_112 -> V_37 , V_50 ) ;
F_57 ( V_11 , NULL , 0 ) ;
F_46 ( V_11 ) ;
goto V_114;
}
F_41 ( & V_112 -> V_37 , V_50 ) ;
V_51 = F_12 ( V_6 , 3 ) ;
if ( V_51 ) {
F_57 ( V_11 , NULL , 0 ) ;
F_46 ( V_11 ) ;
goto V_114;
}
V_51 = V_11 -> V_31 ( V_11 , V_113 ) ;
if ( V_51 ) {
F_57 ( V_11 , NULL , 0 ) ;
F_46 ( V_11 ) ;
}
V_114:
if ( V_113 -> V_23 )
F_11 ( V_113 -> V_22 ) ;
}
static int F_65 ( struct V_5 * V_6 ,
struct V_19 * V_113 )
{
unsigned long V_50 ;
int V_51 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_13 ( V_6 -> V_33 != V_56 ) ;
V_6 -> V_33 = V_53 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = V_6 -> V_28 . V_31 ( & V_6 -> V_28 , V_113 ) ;
F_59 ( & V_6 -> V_38 ) ;
return V_51 ;
}
static int F_66 ( struct V_5 * V_6 ,
struct V_19 * V_113 )
{
unsigned long V_50 ;
int V_51 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
F_58 ( V_52 , & V_6 -> V_50 ) ;
F_13 ( V_6 -> V_33 != V_57 ) ;
if ( V_113 -> V_91 == 0 ) {
V_6 -> V_28 . V_65 = V_113 -> V_64 ;
V_6 -> V_28 . V_92 = V_113 -> V_93 ;
V_113 -> V_64 = V_6 -> V_28 . V_64 ;
V_113 -> V_93 = V_6 -> V_28 . V_93 ;
V_6 -> V_33 = V_53 ;
} else {
V_6 -> V_28 . V_30 -> V_60 -> F_25 ( V_6 -> V_41 ) ;
V_6 -> V_41 = NULL ;
V_6 -> V_33 = V_34 ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = V_6 -> V_28 . V_31 ( & V_6 -> V_28 , V_113 ) ;
if ( V_113 -> V_23 )
F_11 ( V_113 -> V_22 ) ;
F_59 ( & V_6 -> V_38 ) ;
return V_51 ;
}
static void F_67 ( struct V_5 * V_6 ,
struct V_19 * V_113 )
{
unsigned long V_50 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_33 == V_53 )
V_6 -> V_33 = V_54 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
}
static int F_68 ( struct V_5 * V_6 ,
struct V_19 * V_113 )
{
unsigned long V_50 ;
int V_51 = 0 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
if ( V_6 -> V_41 ) {
V_6 -> V_28 . V_30 -> V_60 -> F_25 ( V_6 -> V_41 ) ;
V_6 -> V_41 = NULL ;
}
switch ( V_6 -> V_33 ) {
case V_53 :
case V_54 :
V_6 -> V_33 = V_34 ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
V_51 = V_6 -> V_28 . V_31 ( & V_6 -> V_28 , V_113 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
break;
case V_59 :
break;
default:
F_40 () ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
return V_51 ;
}
static int F_69 ( struct V_5 * V_6 ,
struct V_19 * V_113 )
{
int V_51 = 0 ;
switch ( V_113 -> V_20 ) {
case V_116 :
F_62 ( V_6 , V_113 ) ;
break;
case V_117 :
V_51 = F_66 ( V_6 , V_113 ) ;
break;
case V_118 :
V_51 = F_65 ( V_6 , V_113 ) ;
break;
case V_119 :
F_67 ( V_6 , V_113 ) ;
break;
case V_120 :
V_51 = F_68 ( V_6 , V_113 ) ;
break;
default:
F_40 () ;
}
return V_51 ;
}
static void F_70 ( struct V_121 * V_122 )
{
struct V_4 * V_7 = F_23 ( V_122 , struct V_4 , V_7 ) ;
struct V_19 V_123 ;
struct V_5 * V_6 = V_7 -> V_11 ;
unsigned long V_50 ;
int V_124 ;
int V_51 = 0 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
V_124 = F_4 ( & V_6 -> V_26 ) ;
while ( ! V_124 ) {
V_7 = F_5 ( V_6 -> V_26 . V_9 ,
struct V_4 , V_18 ) ;
F_6 ( & V_7 -> V_18 ) ;
V_124 = F_4 ( & V_6 -> V_26 ) ;
V_123 = V_7 -> V_20 ;
F_7 ( V_7 ) ;
F_41 ( & V_6 -> V_37 , V_50 ) ;
if ( ! F_38 ( V_58 , & V_6 -> V_50 ) ) {
V_51 = F_69 ( V_6 , & V_123 ) ;
if ( V_51 )
F_42 ( & V_6 -> V_28 ) ;
} else
F_71 ( L_2 , V_123 . V_20 ) ;
if ( F_19 ( V_6 ) )
return;
if ( V_124 )
return;
F_39 ( & V_6 -> V_37 , V_50 ) ;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
}
static int V_36 ( struct V_27 * V_11 ,
struct V_19 * V_113 )
{
struct V_4 * V_7 ;
struct V_5 * V_6 ;
unsigned long V_50 ;
int V_51 = 0 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
V_7 = F_3 ( V_6 ) ;
if ( ! V_7 ) {
V_51 = - V_17 ;
goto V_114;
}
F_72 ( & V_7 -> V_7 , F_70 ) ;
V_7 -> V_11 = V_6 ;
V_7 -> V_20 = * V_113 ;
if ( ( V_7 -> V_20 . V_20 == V_116 ||
V_7 -> V_20 . V_20 == V_117 ) &&
V_7 -> V_20 . V_23 ) {
V_51 = F_16 ( & V_7 -> V_20 ) ;
if ( V_51 ) {
F_7 ( V_7 ) ;
goto V_114;
}
}
F_24 ( & V_6 -> V_25 ) ;
if ( F_4 ( & V_6 -> V_26 ) ) {
F_73 ( & V_7 -> V_18 , & V_6 -> V_26 ) ;
F_74 ( V_125 , & V_7 -> V_7 ) ;
} else
F_73 ( & V_7 -> V_18 , & V_6 -> V_26 ) ;
V_114:
F_41 ( & V_6 -> V_37 , V_50 ) ;
return V_51 ;
}
static int F_75 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
int * V_126 )
{
unsigned long V_50 ;
int V_51 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
switch ( V_6 -> V_33 ) {
case V_34 :
case V_57 :
case V_56 :
case V_53 :
* V_126 = V_47 | V_127 ;
V_43 -> V_128 = V_129 |
V_130 ;
V_51 = 0 ;
break;
default:
V_51 = - V_44 ;
break;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
return V_51 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_42 * V_43 ,
int * V_126 )
{
unsigned long V_50 ;
int V_51 ;
F_39 ( & V_6 -> V_37 , V_50 ) ;
switch ( V_6 -> V_33 ) {
case V_34 :
case V_57 :
case V_56 :
case V_53 :
* V_126 = 0 ;
V_51 = 0 ;
break;
default:
V_51 = - V_44 ;
break;
}
F_41 ( & V_6 -> V_37 , V_50 ) ;
return V_51 ;
}
int F_77 ( struct V_27 * V_11 ,
struct V_42 * V_43 ,
int * V_126 )
{
struct V_5 * V_6 ;
int V_51 ;
V_6 = F_23 ( V_11 , struct V_5 , V_28 ) ;
switch ( V_43 -> V_45 ) {
case V_131 :
case V_132 :
V_51 = F_75 ( V_6 ,
V_43 , V_126 ) ;
break;
case V_133 :
V_51 = F_76 ( V_6 ,
V_43 , V_126 ) ;
break;
default:
V_51 = - V_44 ;
break;
}
return V_51 ;
}
static int T_5 F_78 ( void )
{
int V_51 ;
V_51 = F_79 ( V_66 ) ;
if ( V_51 )
F_80 ( L_3 ) ;
V_51 = F_81 ( V_66 , F_2 ( V_134 ) ,
V_134 ) ;
if ( V_51 )
F_80 ( L_4 ) ;
V_125 = F_82 ( L_5 , V_135 ) ;
if ( ! V_125 )
return - V_17 ;
V_136 = F_83 ( & V_137 , L_6 ,
V_138 ) ;
if ( ! V_136 ) {
F_80 ( L_7 ) ;
F_84 ( V_125 ) ;
return - V_17 ;
}
return 0 ;
}
static void T_6 F_85 ( void )
{
F_86 ( V_136 ) ;
F_84 ( V_125 ) ;
F_87 ( V_66 ) ;
F_88 ( V_66 ) ;
}
