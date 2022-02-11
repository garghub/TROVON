static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( & V_3 -> V_5 ) )
return NULL ;
V_4 = F_3 ( V_3 -> V_5 . V_6 , struct V_1 ,
V_7 ) ;
F_4 ( & V_4 -> V_7 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_4 )
{
F_6 ( & V_4 -> V_7 , & V_4 -> V_8 -> V_5 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_9 * V_10 , * V_11 ;
F_8 (e, tmp, &cm_id_priv->work_free_list)
F_9 ( F_3 ( V_10 , struct V_1 , V_7 ) ) ;
}
static int F_10 ( struct V_2 * V_3 , int V_12 )
{
struct V_1 * V_4 ;
F_11 ( ! F_2 ( & V_3 -> V_5 ) ) ;
while ( V_12 -- ) {
V_4 = F_12 ( sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_4 ) {
F_7 ( V_3 ) ;
return - V_14 ;
}
V_4 -> V_8 = V_3 ;
F_13 ( & V_4 -> V_15 ) ;
F_5 ( V_4 ) ;
}
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
void * V_18 ;
V_18 = F_15 ( V_17 -> V_19 , V_17 -> V_20 , V_21 ) ;
if ( ! V_18 )
return - V_14 ;
V_17 -> V_19 = V_18 ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_7 ( V_3 ) ;
F_9 ( V_3 ) ;
}
static int F_17 ( struct V_2 * V_3 )
{
F_11 ( F_18 ( & V_3 -> V_22 ) == 0 ) ;
if ( F_19 ( & V_3 -> V_22 ) ) {
F_11 ( ! F_2 ( & V_3 -> V_23 ) ) ;
F_16 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_24 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_22 ( & V_3 -> V_22 ) ;
}
static void F_23 ( struct V_24 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
( void ) F_17 ( V_3 ) ;
}
struct V_24 * F_24 ( struct V_26 * V_27 ,
T_1 V_28 ,
void * V_29 )
{
struct V_2 * V_3 ;
V_3 = F_25 ( sizeof( * V_3 ) , V_13 ) ;
if ( ! V_3 )
return F_26 ( - V_14 ) ;
V_3 -> V_30 = V_31 ;
V_3 -> V_25 . V_27 = V_27 ;
V_3 -> V_25 . V_28 = V_28 ;
V_3 -> V_25 . V_29 = V_29 ;
V_3 -> V_25 . V_32 = V_33 ;
V_3 -> V_25 . F_20 = F_20 ;
V_3 -> V_25 . F_23 = F_23 ;
F_27 ( & V_3 -> V_34 ) ;
F_28 ( & V_3 -> V_22 , 1 ) ;
F_29 ( & V_3 -> V_35 ) ;
F_30 ( & V_3 -> V_36 ) ;
F_13 ( & V_3 -> V_23 ) ;
F_13 ( & V_3 -> V_5 ) ;
return & V_3 -> V_25 ;
}
static int F_31 ( struct V_37 * V_38 )
{
struct V_39 V_40 ;
if ( ! V_38 )
return - V_41 ;
V_40 . V_42 = V_43 ;
return F_32 ( V_38 , & V_40 , V_44 ) ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_39 V_40 ;
F_11 ( V_38 == NULL ) ;
V_40 . V_42 = V_45 ;
return F_32 ( V_38 , & V_40 , V_44 ) ;
}
int F_34 ( struct V_24 * V_8 , int V_46 )
{
struct V_2 * V_3 ;
unsigned long V_47 ;
int V_48 = 0 ;
struct V_37 * V_38 = NULL ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_35 ( V_3 -> V_35 ,
! F_36 ( V_49 , & V_3 -> V_47 ) ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
switch ( V_3 -> V_30 ) {
case V_50 :
V_3 -> V_30 = V_51 ;
if ( V_3 -> V_38 )
V_38 = V_3 -> V_38 ;
else
V_48 = - V_41 ;
break;
case V_52 :
V_48 = - V_41 ;
break;
case V_51 :
case V_31 :
break;
case V_53 :
break;
case V_54 :
default:
F_38 () ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
if ( V_38 ) {
if ( V_46 )
V_48 = F_31 ( V_38 ) ;
else
V_48 = F_33 ( V_38 ) ;
V_48 = 0 ;
}
return V_48 ;
}
static void F_40 ( struct V_24 * V_8 )
{
struct V_2 * V_3 ;
unsigned long V_47 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_35 ( V_3 -> V_35 ,
! F_36 ( V_49 , & V_3 -> V_47 ) ) ;
F_41 ( V_55 , & V_3 -> V_47 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
switch ( V_3 -> V_30 ) {
case V_52 :
V_3 -> V_30 = V_56 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_8 -> V_27 -> V_57 -> V_58 ( V_8 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
break;
case V_50 :
V_3 -> V_30 = V_56 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
( void ) F_31 ( V_3 -> V_38 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
break;
case V_31 :
case V_51 :
V_3 -> V_30 = V_56 ;
break;
case V_53 :
V_3 -> V_30 = V_56 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_8 -> V_27 -> V_57 -> V_59 ( V_8 , NULL , 0 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
break;
case V_54 :
case V_56 :
default:
F_38 () ;
break;
}
if ( V_3 -> V_38 ) {
V_3 -> V_25 . V_27 -> V_57 -> F_23 ( V_3 -> V_38 ) ;
V_3 -> V_38 = NULL ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
if ( V_8 -> V_60 ) {
F_42 ( & V_8 -> V_61 , & V_8 -> V_62 ) ;
F_43 ( & V_8 -> V_61 , V_63 ) ;
}
( void ) F_17 ( V_3 ) ;
}
void F_44 ( struct V_24 * V_8 )
{
struct V_2 * V_3 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_40 ( V_8 ) ;
}
static void F_45 ( struct V_64 * V_65 ,
struct V_64 * V_66 ,
struct V_64 * V_67 )
{
if ( V_65 -> V_68 == V_69 ) {
struct V_70 * V_71 = (struct V_70 * ) V_65 ;
if ( V_71 -> V_72 . V_73 == F_46 ( V_74 ) ) {
struct V_70 * V_75 =
(struct V_70 * ) V_66 ;
struct V_70 * V_76 =
(struct V_70 * ) V_67 ;
V_76 -> V_72 = V_75 -> V_72 ;
}
} else {
struct V_77 * V_78 = (struct V_77 * ) V_65 ;
if ( F_47 ( & V_78 -> V_79 ) == V_80 ) {
struct V_77 * V_81 =
(struct V_77 * ) V_66 ;
struct V_77 * V_82 =
(struct V_77 * ) V_67 ;
V_82 -> V_79 = V_81 -> V_79 ;
}
}
}
static int F_48 ( struct V_24 * V_8 , bool V_83 )
{
struct V_84 V_85 ;
struct V_86 V_87 ;
int V_88 ;
V_8 -> V_62 = V_8 -> V_61 ;
V_8 -> V_89 = V_8 -> V_90 ;
memcpy ( V_85 . V_91 , V_8 -> V_27 -> V_92 ,
sizeof( V_85 . V_91 ) ) ;
memcpy ( V_85 . V_93 , V_8 -> V_27 -> V_57 -> V_94 ,
sizeof( V_85 . V_93 ) ) ;
if ( F_49 ( & V_85 , V_63 ) ||
! F_50 () )
return 0 ;
V_8 -> V_60 = true ;
V_87 . V_95 = V_8 -> V_61 ;
V_87 . V_96 = V_8 -> V_90 ;
if ( V_83 )
V_88 = F_51 ( & V_87 ,
V_63 ) ;
else
V_88 = F_52 ( & V_87 , V_63 ) ;
if ( ! V_88 ) {
V_8 -> V_62 = V_87 . V_97 ;
if ( V_83 ) {
V_8 -> V_89 = V_87 . V_98 ;
F_45 ( & V_87 . V_98 ,
& V_8 -> V_90 ,
& V_8 -> V_89 ) ;
}
}
return F_53 ( & V_8 -> V_61 ,
& V_8 -> V_62 ,
V_63 ) ;
}
int F_54 ( struct V_24 * V_8 , int V_99 )
{
struct V_2 * V_3 ;
unsigned long V_47 ;
int V_48 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
if ( ! V_99 )
V_99 = V_100 ;
V_48 = F_10 ( V_3 , V_99 ) ;
if ( V_48 )
return V_48 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
switch ( V_3 -> V_30 ) {
case V_31 :
V_3 -> V_30 = V_52 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = F_48 ( V_8 , false ) ;
if ( ! V_48 )
V_48 = V_8 -> V_27 -> V_57 -> V_101 ( V_8 , V_99 ) ;
if ( V_48 )
V_3 -> V_30 = V_31 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
break;
default:
V_48 = - V_41 ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
return V_48 ;
}
int F_55 ( struct V_24 * V_8 ,
const void * V_19 ,
T_2 V_20 )
{
struct V_2 * V_3 ;
unsigned long V_47 ;
int V_48 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_41 ( V_49 , & V_3 -> V_47 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_30 != V_53 ) {
F_39 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
return - V_41 ;
}
V_3 -> V_30 = V_31 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = V_8 -> V_27 -> V_57 -> V_59 ( V_8 , V_19 ,
V_20 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
return V_48 ;
}
int F_58 ( struct V_24 * V_8 ,
struct V_102 * V_103 )
{
struct V_2 * V_3 ;
struct V_37 * V_38 ;
unsigned long V_47 ;
int V_48 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_41 ( V_49 , & V_3 -> V_47 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_30 != V_53 ) {
F_39 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
return - V_41 ;
}
V_38 = V_8 -> V_27 -> V_57 -> V_104 ( V_8 -> V_27 , V_103 -> V_105 ) ;
if ( ! V_38 ) {
F_39 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
return - V_41 ;
}
V_8 -> V_27 -> V_57 -> F_20 ( V_38 ) ;
V_3 -> V_38 = V_38 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = V_8 -> V_27 -> V_57 -> V_106 ( V_8 , V_103 ) ;
if ( V_48 ) {
F_11 ( V_3 -> V_30 != V_53 ) ;
V_3 -> V_30 = V_31 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_38 ) {
V_8 -> V_27 -> V_57 -> F_23 ( V_38 ) ;
V_3 -> V_38 = NULL ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
}
return V_48 ;
}
int F_59 ( struct V_24 * V_8 , struct V_102 * V_103 )
{
struct V_2 * V_3 ;
int V_48 ;
unsigned long V_47 ;
struct V_37 * V_38 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
V_48 = F_10 ( V_3 , 4 ) ;
if ( V_48 )
return V_48 ;
F_41 ( V_49 , & V_3 -> V_47 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_30 != V_31 ) {
V_48 = - V_41 ;
goto V_107;
}
V_38 = V_8 -> V_27 -> V_57 -> V_104 ( V_8 -> V_27 , V_103 -> V_105 ) ;
if ( ! V_38 ) {
V_48 = - V_41 ;
goto V_107;
}
V_8 -> V_27 -> V_57 -> F_20 ( V_38 ) ;
V_3 -> V_38 = V_38 ;
V_3 -> V_30 = V_54 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = F_48 ( V_8 , true ) ;
if ( ! V_48 )
V_48 = V_8 -> V_27 -> V_57 -> V_108 ( V_8 , V_103 ) ;
if ( ! V_48 )
return 0 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_38 ) {
V_8 -> V_27 -> V_57 -> F_23 ( V_38 ) ;
V_3 -> V_38 = NULL ;
}
V_3 -> V_30 = V_31 ;
V_107:
F_39 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_57 ( & V_3 -> V_35 ) ;
return V_48 ;
}
static void F_60 ( struct V_2 * V_109 ,
struct V_16 * V_110 )
{
unsigned long V_47 ;
struct V_24 * V_8 ;
struct V_2 * V_3 ;
int V_48 ;
F_11 ( V_110 -> V_88 ) ;
V_8 = F_24 ( V_109 -> V_25 . V_27 ,
V_109 -> V_25 . V_28 ,
V_109 -> V_25 . V_29 ) ;
if ( F_61 ( V_8 ) )
goto V_111;
V_8 -> V_112 = V_110 -> V_112 ;
V_8 -> V_62 = V_110 -> V_61 ;
V_8 -> V_89 = V_110 -> V_90 ;
V_8 -> V_61 = V_109 -> V_25 . V_61 ;
V_48 = F_62 ( & V_109 -> V_25 . V_62 ,
& V_110 -> V_90 ,
& V_8 -> V_90 ,
V_63 ) ;
if ( V_48 ) {
V_8 -> V_90 = V_110 -> V_90 ;
} else {
F_45 ( & V_109 -> V_25 . V_62 ,
& V_110 -> V_61 ,
& V_8 -> V_61 ) ;
V_110 -> V_61 = V_8 -> V_61 ;
V_110 -> V_90 = V_8 -> V_90 ;
}
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
V_3 -> V_30 = V_53 ;
F_37 ( & V_109 -> V_34 , V_47 ) ;
if ( V_109 -> V_30 != V_52 ) {
F_39 ( & V_109 -> V_34 , V_47 ) ;
F_55 ( V_8 , NULL , 0 ) ;
F_44 ( V_8 ) ;
goto V_111;
}
F_39 ( & V_109 -> V_34 , V_47 ) ;
V_48 = F_10 ( V_3 , 3 ) ;
if ( V_48 ) {
F_55 ( V_8 , NULL , 0 ) ;
F_44 ( V_8 ) ;
goto V_111;
}
V_48 = V_8 -> V_28 ( V_8 , V_110 ) ;
if ( V_48 ) {
F_55 ( V_8 , NULL , 0 ) ;
F_44 ( V_8 ) ;
}
V_111:
if ( V_110 -> V_20 )
F_9 ( V_110 -> V_19 ) ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_16 * V_110 )
{
unsigned long V_47 ;
int V_48 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_11 ( V_3 -> V_30 != V_53 ) ;
V_3 -> V_30 = V_50 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = V_3 -> V_25 . V_28 ( & V_3 -> V_25 , V_110 ) ;
F_57 ( & V_3 -> V_35 ) ;
return V_48 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_16 * V_110 )
{
unsigned long V_47 ;
int V_48 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
F_56 ( V_49 , & V_3 -> V_47 ) ;
F_11 ( V_3 -> V_30 != V_54 ) ;
if ( V_110 -> V_88 == 0 ) {
V_3 -> V_25 . V_62 = V_110 -> V_61 ;
V_3 -> V_25 . V_89 = V_110 -> V_90 ;
V_110 -> V_61 = V_3 -> V_25 . V_61 ;
V_110 -> V_90 = V_3 -> V_25 . V_90 ;
V_3 -> V_30 = V_50 ;
} else {
V_3 -> V_25 . V_27 -> V_57 -> F_23 ( V_3 -> V_38 ) ;
V_3 -> V_38 = NULL ;
V_3 -> V_30 = V_31 ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = V_3 -> V_25 . V_28 ( & V_3 -> V_25 , V_110 ) ;
if ( V_110 -> V_20 )
F_9 ( V_110 -> V_19 ) ;
F_57 ( & V_3 -> V_35 ) ;
return V_48 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_16 * V_110 )
{
unsigned long V_47 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_30 == V_50 )
V_3 -> V_30 = V_51 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
}
static int F_66 ( struct V_2 * V_3 ,
struct V_16 * V_110 )
{
unsigned long V_47 ;
int V_48 = 0 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
if ( V_3 -> V_38 ) {
V_3 -> V_25 . V_27 -> V_57 -> F_23 ( V_3 -> V_38 ) ;
V_3 -> V_38 = NULL ;
}
switch ( V_3 -> V_30 ) {
case V_50 :
case V_51 :
V_3 -> V_30 = V_31 ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
V_48 = V_3 -> V_25 . V_28 ( & V_3 -> V_25 , V_110 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
break;
case V_56 :
break;
default:
F_38 () ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
return V_48 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_16 * V_110 )
{
int V_48 = 0 ;
switch ( V_110 -> V_17 ) {
case V_113 :
F_60 ( V_3 , V_110 ) ;
break;
case V_114 :
V_48 = F_64 ( V_3 , V_110 ) ;
break;
case V_115 :
V_48 = F_63 ( V_3 , V_110 ) ;
break;
case V_116 :
F_65 ( V_3 , V_110 ) ;
break;
case V_117 :
V_48 = F_66 ( V_3 , V_110 ) ;
break;
default:
F_38 () ;
}
return V_48 ;
}
static void F_68 ( struct V_118 * V_119 )
{
struct V_1 * V_4 = F_21 ( V_119 , struct V_1 , V_4 ) ;
struct V_16 V_120 ;
struct V_2 * V_3 = V_4 -> V_8 ;
unsigned long V_47 ;
int V_121 ;
int V_48 = 0 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
V_121 = F_2 ( & V_3 -> V_23 ) ;
while ( ! V_121 ) {
V_4 = F_3 ( V_3 -> V_23 . V_6 ,
struct V_1 , V_15 ) ;
F_4 ( & V_4 -> V_15 ) ;
V_121 = F_2 ( & V_3 -> V_23 ) ;
V_120 = V_4 -> V_17 ;
F_5 ( V_4 ) ;
F_39 ( & V_3 -> V_34 , V_47 ) ;
if ( ! F_36 ( V_55 , & V_3 -> V_47 ) ) {
V_48 = F_67 ( V_3 , & V_120 ) ;
if ( V_48 )
F_40 ( & V_3 -> V_25 ) ;
} else
F_69 ( L_1 , V_120 . V_17 ) ;
if ( F_17 ( V_3 ) )
return;
if ( V_121 )
return;
F_37 ( & V_3 -> V_34 , V_47 ) ;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
}
static int V_33 ( struct V_24 * V_8 ,
struct V_16 * V_110 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
unsigned long V_47 ;
int V_48 = 0 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_48 = - V_14 ;
goto V_111;
}
F_70 ( & V_4 -> V_4 , F_68 ) ;
V_4 -> V_8 = V_3 ;
V_4 -> V_17 = * V_110 ;
if ( ( V_4 -> V_17 . V_17 == V_113 ||
V_4 -> V_17 . V_17 == V_114 ) &&
V_4 -> V_17 . V_20 ) {
V_48 = F_14 ( & V_4 -> V_17 ) ;
if ( V_48 ) {
F_5 ( V_4 ) ;
goto V_111;
}
}
F_22 ( & V_3 -> V_22 ) ;
if ( F_2 ( & V_3 -> V_23 ) ) {
F_71 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
F_72 ( V_122 , & V_4 -> V_4 ) ;
} else
F_71 ( & V_4 -> V_15 , & V_3 -> V_23 ) ;
V_111:
F_39 ( & V_3 -> V_34 , V_47 ) ;
return V_48 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int * V_123 )
{
unsigned long V_47 ;
int V_48 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
switch ( V_3 -> V_30 ) {
case V_31 :
case V_54 :
case V_53 :
case V_50 :
* V_123 = V_44 | V_124 ;
V_40 -> V_125 = V_126 |
V_127 ;
V_48 = 0 ;
break;
default:
V_48 = - V_41 ;
break;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
return V_48 ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_39 * V_40 ,
int * V_123 )
{
unsigned long V_47 ;
int V_48 ;
F_37 ( & V_3 -> V_34 , V_47 ) ;
switch ( V_3 -> V_30 ) {
case V_31 :
case V_54 :
case V_53 :
case V_50 :
* V_123 = 0 ;
V_48 = 0 ;
break;
default:
V_48 = - V_41 ;
break;
}
F_39 ( & V_3 -> V_34 , V_47 ) ;
return V_48 ;
}
int F_75 ( struct V_24 * V_8 ,
struct V_39 * V_40 ,
int * V_123 )
{
struct V_2 * V_3 ;
int V_48 ;
V_3 = F_21 ( V_8 , struct V_2 , V_25 ) ;
switch ( V_40 -> V_42 ) {
case V_128 :
case V_129 :
V_48 = F_73 ( V_3 ,
V_40 , V_123 ) ;
break;
case V_130 :
V_48 = F_74 ( V_3 ,
V_40 , V_123 ) ;
break;
default:
V_48 = - V_41 ;
break;
}
return V_48 ;
}
static int T_3 F_76 ( void )
{
int V_48 ;
V_48 = F_77 ( V_63 ) ;
if ( V_48 )
F_78 ( L_2 ) ;
V_48 = F_79 ( V_63 , F_80 ( V_131 ) ,
V_131 ) ;
if ( V_48 )
F_78 ( L_3 ) ;
V_122 = F_81 ( L_4 ) ;
if ( ! V_122 )
return - V_14 ;
V_132 = F_82 ( & V_133 , L_5 ,
V_134 ) ;
if ( ! V_132 ) {
F_78 ( L_6 ) ;
F_83 ( V_122 ) ;
return - V_14 ;
}
return 0 ;
}
static void T_4 F_84 ( void )
{
F_85 ( V_132 ) ;
F_83 ( V_122 ) ;
F_86 ( V_63 ) ;
F_87 ( V_63 ) ;
}
