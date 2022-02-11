static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_6 = F_4 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_6 ) {
F_5 ( V_10 , L_1 ) ;
return NULL ;
}
F_6 ( & V_6 -> V_11 ) ;
V_6 -> V_4 = V_4 ;
F_7 ( V_4 ) = V_6 ;
return V_6 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
F_7 ( V_6 -> V_4 ) = NULL ;
V_6 -> V_4 = NULL ;
F_9 ( V_6 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
return ( V_3 -> V_12 . V_13 == NULL ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_14 * V_11 )
{
int V_15 = V_4 -> V_16 ;
int V_17 = F_12 ( & V_4 -> V_18 -> V_19 ) ;
int V_20 = 0 ;
if ( F_13 ( V_4 -> V_21 ) )
return;
V_20 = V_15 / V_17 ;
if ( V_15 % V_17 )
V_20 ++ ;
if ( V_11 -> V_22 )
V_20 ++ ;
V_20 %= 2 ;
if ( V_20 )
F_14 ( V_4 -> V_10 ,
F_15 ( V_4 -> V_21 ) ,
F_16 ( V_4 -> V_21 ) ) ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_23 * V_24 = F_18 ( V_4 -> V_18 ) ;
struct V_25 * V_26 = F_19 ( V_3 , V_4 ) ;
struct V_27 * V_21 ;
struct V_28 * V_19 = & V_4 -> V_18 -> V_19 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_29 ;
int V_30 = ! ! F_20 ( V_4 -> V_21 ) ;
int V_31 = F_21 ( V_19 ) ;
int V_32 , V_33 ;
int V_34 = - V_35 ;
F_22 ( V_8 , V_29 ) ;
if ( F_23 ( V_24 ) ) {
V_34 = 0 ;
goto V_36;
}
F_24 (pipe, priv, i) {
if ( ! F_25 ( V_21 , F_26 ( V_19 ) ) )
continue;
if ( ! V_31 ) {
V_33 = ! ! F_27 ( V_21 ) ;
if ( 0 != ( V_33 - V_30 ) )
continue;
}
if ( F_28 ( V_21 ) )
continue;
F_23 ( V_24 ) = V_21 ;
F_28 ( V_21 ) = V_24 ;
F_29 ( V_21 ,
F_30 ( V_3 , V_26 ) ,
F_31 ( V_19 ) ,
F_12 ( V_19 ) ) ;
F_32 ( V_10 , L_2 , V_37 ,
F_30 ( V_3 , V_26 ) ,
F_31 ( V_19 ) ,
F_33 ( V_21 ) ,
V_30 ? L_3 : L_4 ) ;
V_34 = 0 ;
break;
}
V_36:
if ( 0 == V_34 )
V_24 -> V_38 ++ ;
F_34 ( V_8 , V_29 ) ;
return V_34 ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_27 * V_21 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_29 ;
if ( F_36 ( ! V_24 ) ) {
F_5 ( V_10 , L_5 ) ;
return;
}
F_22 ( V_8 , V_29 ) ;
V_21 = F_23 ( V_24 ) ;
if ( F_36 ( ! V_21 ) ) {
F_5 ( V_10 , L_6 ) ;
} else if ( 1 == V_24 -> V_38 -- ) {
struct V_39 * V_18 = F_37 ( V_24 ) ;
struct V_25 * V_26 = F_38 ( V_24 ) ;
F_23 ( V_24 ) = NULL ;
F_28 ( V_21 ) = NULL ;
F_32 ( V_10 , L_7 , V_37 ,
F_30 ( V_3 , V_26 ) ,
F_31 ( & V_18 -> V_19 ) ,
F_33 ( V_21 ) ) ;
}
F_34 ( V_8 , V_29 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_25 * V_26 = F_19 ( V_3 , V_4 ) ;
struct V_39 * V_18 = V_4 -> V_18 ;
struct V_23 * V_24 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_28 * V_19 = & V_18 -> V_19 ;
unsigned long V_29 ;
V_24 = F_4 ( sizeof( struct V_23 ) , V_5 ) ;
if ( ! V_24 ) {
F_5 ( V_10 , L_8 ) ;
return - V_40 ;
}
F_22 ( V_8 , V_29 ) ;
V_24 -> V_38 = 0 ;
F_40 ( & V_24 -> V_41 ) ;
F_41 ( & V_24 -> V_41 , & V_26 -> V_42 ) ;
F_38 ( V_24 ) = V_26 ;
F_37 ( V_24 ) = V_18 ;
F_18 ( V_18 ) = V_24 ;
F_34 ( V_8 , V_29 ) ;
F_32 ( V_10 , L_9 , V_37 ,
F_30 ( V_3 , V_26 ) ,
F_31 ( V_19 ) ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_39 * V_18 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_23 * V_24 = F_18 ( V_18 ) ;
unsigned long V_29 ;
if ( ! V_24 )
return;
F_32 ( V_10 , L_9 , V_37 ,
F_30 ( V_3 , F_38 ( V_24 ) ) ,
F_31 ( & V_18 -> V_19 ) ) ;
if ( F_23 ( V_24 ) )
F_35 ( V_3 , V_24 ) ;
F_22 ( V_8 , V_29 ) ;
F_43 ( & V_24 -> V_41 ) ;
F_38 ( V_24 ) = NULL ;
F_37 ( V_24 ) = NULL ;
F_18 ( V_18 ) = NULL ;
F_34 ( V_8 , V_29 ) ;
F_9 ( V_24 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_23 * V_24 , * V_43 ;
F_45 (uep, next, &udev->ep_list_head, ep_list)
F_42 ( V_3 , F_37 ( V_24 ) ) ;
}
static int F_46 ( struct V_44 * V_45 ,
struct V_25 * V_26 )
{
struct V_46 * V_47 = F_47 ( V_26 ) ;
return V_45 -> V_48 . V_49 == V_47 -> V_50 ;
}
static int F_48 ( struct V_25 * V_26 )
{
return ! F_49 ( & V_26 -> V_42 ) ;
}
static struct V_25 * F_19 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_25 * V_26 = F_51 ( V_47 ) ;
if ( ! V_26 )
return NULL ;
if ( 0 == F_52 ( V_4 -> V_21 ) )
return F_53 ( V_3 ) ;
return V_26 ;
}
static struct V_25 * F_54 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_25 * V_26 = NULL ;
struct V_25 * V_51 = F_53 ( V_3 ) ;
struct V_25 * V_52 ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_9 * V_10 = F_56 ( V_45 ) ;
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
unsigned long V_29 ;
T_2 V_53 , V_54 ;
int V_32 ;
if ( 0 != F_52 ( V_4 -> V_21 ) ) {
F_5 ( V_10 , L_10 , V_37 ) ;
return NULL ;
}
F_22 ( V_8 , V_29 ) ;
F_57 (pos, hpriv, i) {
if ( F_58 ( V_52 ) )
continue;
V_26 = V_52 ;
break;
}
if ( V_26 ) {
F_59 ( & V_47 -> V_10 , V_26 ) ;
V_26 -> V_47 = V_47 ;
}
F_34 ( V_8 , V_29 ) ;
if ( ! V_26 ) {
F_5 ( V_10 , L_11 ) ;
return NULL ;
}
if ( F_48 ( V_26 ) ) {
F_60 ( V_10 , L_12 ) ;
F_44 ( V_3 , V_26 ) ;
}
if ( F_48 ( V_51 ) ) {
F_60 ( V_10 , L_13 ) ;
F_44 ( V_3 , V_51 ) ;
}
F_40 ( & V_51 -> V_42 ) ;
F_40 ( & V_26 -> V_42 ) ;
F_61 ( V_8 ,
0 , 0 , 0 , V_47 -> V_55 ) ;
V_53 = 0 ;
V_54 = 0 ;
if ( ! F_46 ( V_45 , V_26 ) ) {
struct V_25 * V_50 = F_62 ( V_26 ) ;
V_53 = F_30 ( V_3 , V_50 ) ;
V_54 = F_63 ( V_26 ) ;
F_32 ( V_10 , L_14 , V_37 ,
V_53 , V_54 , V_50 ) ;
}
F_61 ( V_8 ,
F_30 ( V_3 , V_26 ) ,
V_53 , V_54 , V_47 -> V_55 ) ;
F_32 ( V_10 , L_15 , V_37 ,
F_30 ( V_3 , V_26 ) , V_26 ) ;
return V_26 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_56 ( V_45 ) ;
struct V_46 * V_47 = F_47 ( V_26 ) ;
unsigned long V_29 ;
F_32 ( V_10 , L_15 , V_37 ,
F_30 ( V_3 , V_26 ) , V_26 ) ;
if ( F_48 ( V_26 ) ) {
F_60 ( V_10 , L_16 ) ;
F_44 ( V_3 , V_26 ) ;
}
if ( 0 == F_30 ( V_3 , V_26 ) )
return;
F_22 ( V_8 , V_29 ) ;
F_59 ( & V_47 -> V_10 , NULL ) ;
V_26 -> V_47 = NULL ;
F_34 ( V_8 , V_29 ) ;
}
static void F_65 ( struct V_7 * V_8 , struct V_14 * V_11 )
{
struct V_1 * V_6 = F_66 ( V_11 ) ;
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_4 * V_4 = V_6 -> V_4 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_56 = 0 ;
F_32 ( V_10 , L_17 , V_37 ) ;
if ( ! V_4 ) {
F_60 ( V_10 , L_18 ) ;
return;
}
if ( ! F_10 ( V_3 ) )
V_56 = - V_57 ;
V_4 -> V_16 = V_11 -> V_58 ;
F_11 ( V_3 , V_4 , V_11 ) ;
F_8 ( V_3 , V_6 ) ;
F_35 ( V_3 , F_18 ( V_4 -> V_18 ) ) ;
F_68 ( V_45 , V_4 ) ;
F_69 ( V_45 , V_4 , V_56 ) ;
}
static int F_70 ( struct V_44 * V_45 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_23 * V_24 = F_18 ( V_4 -> V_18 ) ;
struct V_27 * V_21 = F_23 ( V_24 ) ;
struct V_9 * V_10 = F_56 ( V_45 ) ;
struct V_1 * V_6 ;
void * V_59 ;
int V_15 , V_60 ;
if ( F_72 ( V_4 -> V_21 ) ) {
F_5 ( V_10 , L_19 ) ;
return - V_61 ;
}
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_36 ( ! V_6 ) ) {
F_5 ( V_10 , L_1 ) ;
return - V_40 ;
}
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_62 = & V_63 ;
else
V_21 -> V_62 = & V_64 ;
V_59 = ( void * ) ( V_4 -> V_65 + V_4 -> V_16 ) ;
V_15 = V_4 -> V_66 - V_4 -> V_16 ;
V_60 = F_73 ( V_4 -> V_10 ,
F_15 ( V_4 -> V_21 ) ,
F_16 ( V_4 -> V_21 ) ) ;
F_32 ( V_10 , L_17 , V_37 ) ;
F_74 ( V_21 , & V_6 -> V_11 , F_65 ,
V_59 , V_15 , ( V_4 -> V_67 & V_68 ) ,
V_60 ) ;
F_75 ( V_21 ) ;
return 0 ;
}
static void F_76 ( struct V_7 * V_8 ,
struct V_27 * V_21 )
{
struct V_14 * V_11 ;
while ( 1 ) {
V_11 = F_77 ( V_21 , NULL ) ;
if ( ! V_11 )
break;
F_65 ( V_8 , V_11 ) ;
}
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_27 * V_52 ;
int V_32 ;
F_24 (pos, priv, i)
F_76 ( V_8 , V_52 ) ;
}
static int F_79 ( struct V_4 * V_4 )
{
struct V_69 * V_70 ;
V_70 = (struct V_69 * ) V_4 -> V_71 ;
if ( ( V_72 == V_70 -> V_73 << 8 ) &&
( V_74 == V_70 -> V_75 ) )
return 1 ;
else
return 0 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_27 * V_21 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_69 V_70 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_81 ( & V_3 -> V_76 ) ;
memcpy ( & V_70 , V_4 -> V_71 , sizeof( struct V_69 ) ) ;
if ( F_79 ( V_4 ) ) {
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_25 * V_26 = F_51 ( V_47 ) ;
V_70 . V_77 = F_30 ( V_3 , V_26 ) ;
F_32 ( V_10 , L_20 , V_70 . V_77 ) ;
}
F_82 ( V_8 , & V_70 ) ;
F_83 ( & V_3 -> V_76 ) ;
F_32 ( V_10 , L_21 , V_37 ) ;
}
static void F_84 ( struct V_7 * V_8 ,
struct V_14 * V_11 )
{
struct V_1 * V_6 = F_66 ( V_11 ) ;
struct V_2 * V_3 = F_67 ( V_8 ) ;
F_8 ( V_3 , V_6 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_27 * V_21 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_36 ( ! V_6 ) )
return - V_40 ;
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_62 = & V_78 ;
else
V_21 -> V_62 = & V_79 ;
F_74 ( V_21 , & V_6 -> V_11 ,
F_84 ,
V_4 -> V_65 ,
V_4 -> V_66 ,
( V_4 -> V_67 & V_68 ) ,
- 1 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_27 * V_21 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_36 ( ! V_6 ) )
return - V_40 ;
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_62 = & V_80 ;
else
V_21 -> V_62 = & V_81 ;
F_74 ( V_21 , & V_6 -> V_11 ,
F_65 ,
NULL ,
V_4 -> V_66 ,
0 , - 1 ) ;
return 0 ;
}
static int F_87 ( struct V_44 * V_45 ,
struct V_4 * V_4 ,
T_1 V_82 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_23 * V_24 = F_18 ( V_4 -> V_18 ) ;
struct V_27 * V_21 = F_23 ( V_24 ) ;
struct V_9 * V_10 = F_56 ( V_45 ) ;
int V_34 ;
F_32 ( V_10 , L_17 , V_37 ) ;
F_80 ( V_3 , V_4 , V_21 ) ;
if ( V_4 -> V_66 ) {
V_34 = F_85 ( V_3 , V_4 , V_21 , V_82 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_22 ) ;
return V_34 ;
}
}
V_34 = F_86 ( V_3 , V_4 , V_21 , V_82 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_23 ) ;
return V_34 ;
}
F_75 ( V_21 ) ;
return 0 ;
}
static int F_88 ( struct V_14 * V_11 , int V_83 )
{
if ( V_83 ) {
struct V_1 * V_6 = F_66 ( V_11 ) ;
struct V_4 * V_4 = V_6 -> V_4 ;
if ( V_4 -> V_84 )
return - V_85 ;
V_11 -> V_86 = V_4 -> V_87 ;
if ( ! V_11 -> V_86 )
return - V_85 ;
}
return 0 ;
}
static int F_89 ( struct V_44 * V_45 )
{
return 0 ;
}
static void F_90 ( struct V_44 * V_45 )
{
}
static int F_91 ( struct V_44 * V_45 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_39 * V_18 = V_4 -> V_18 ;
struct V_25 * V_88 = NULL ;
int V_89 = F_20 ( V_4 -> V_21 ) ;
int V_34 ;
F_32 ( V_10 , L_24 , V_37 , V_89 ? L_3 : L_4 ) ;
if ( ! F_10 ( V_3 ) ) {
V_34 = - V_61 ;
F_5 ( V_10 , L_25 ) ;
goto V_90;
}
V_34 = F_92 ( V_45 , V_4 ) ;
if ( V_34 ) {
F_5 ( V_10 , L_26 ) ;
goto V_90;
}
if ( ! F_19 ( V_3 , V_4 ) ) {
V_88 = F_54 ( V_3 , V_4 ) ;
if ( ! V_88 ) {
V_34 = - V_61 ;
F_5 ( V_10 , L_27 ) ;
goto V_90;
}
}
if ( ! F_18 ( V_18 ) ) {
V_34 = F_39 ( V_3 , V_4 , V_5 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_28 ) ;
goto V_91;
}
}
V_34 = F_17 ( V_3 , V_4 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_29 ) ;
goto V_92;
}
if ( F_13 ( V_4 -> V_21 ) )
V_34 = F_87 ( V_45 , V_4 , V_5 ) ;
else
V_34 = F_70 ( V_45 , V_4 , V_5 ) ;
return V_34 ;
V_92:
F_42 ( V_3 , V_18 ) ;
V_91:
if ( V_88 )
F_64 ( V_3 , V_88 ) ;
V_90:
F_32 ( V_10 , L_30 , V_37 ) ;
return V_34 ;
}
static int F_93 ( struct V_44 * V_45 , struct V_4 * V_4 , int V_56 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_1 * V_6 = F_7 ( V_4 ) ;
if ( V_6 ) {
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_14 * V_11 = & V_6 -> V_11 ;
F_77 ( V_11 -> V_21 , V_11 ) ;
F_65 ( V_8 , V_11 ) ;
}
return 0 ;
}
static void F_94 ( struct V_44 * V_45 ,
struct V_39 * V_18 )
{
struct V_23 * V_24 = F_18 ( V_18 ) ;
struct V_25 * V_26 ;
struct V_2 * V_3 ;
if ( ! V_24 )
return;
V_26 = F_38 ( V_24 ) ;
V_3 = F_71 ( V_45 ) ;
F_42 ( V_3 , V_18 ) ;
if ( ! F_48 ( V_26 ) )
F_64 ( V_3 , V_26 ) ;
}
static int F_95 ( struct V_44 * V_45 , char * V_59 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
int V_93 = 1 ;
if ( F_96 ( V_3 ) & 0xFFFF0000 )
* V_59 = ( 1 << V_93 ) ;
else
* V_59 = 0 ;
return ! ! ( * V_59 ) ;
}
static int F_97 ( struct V_2 * V_3 ,
T_2 V_94 , T_2 V_77 ,
T_2 V_95 , char * V_59 , T_2 V_96 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_77 ) {
case V_97 :
case V_98 :
F_32 ( V_10 , L_31 , V_37 ) ;
return 0 ;
}
return - V_99 ;
}
static int F_98 ( struct V_2 * V_3 ,
T_2 V_94 , T_2 V_77 ,
T_2 V_95 , char * V_59 , T_2 V_96 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_100 = ( V_94 == V_101 ) ;
int V_55 , V_32 , V_102 = 128 ;
int V_93 = 1 ;
if ( V_95 > V_93 || V_96 != 0 )
return - V_99 ;
switch ( V_77 ) {
case V_103 :
F_99 ( V_8 , V_100 ) ;
F_32 ( V_10 , L_32 , V_37 ) ;
break;
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
F_32 ( V_10 , L_33 , V_37 ) ;
break;
case V_111 :
if ( ! V_100 )
break;
F_100 ( V_3 ,
V_112 |
V_113 ) ;
F_78 ( V_8 ) ;
F_101 ( V_8 ) ;
F_102 ( 20 ) ;
F_103 ( V_8 ) ;
for ( V_32 = 0 ; V_32 < V_102 ; V_32 ++ ) {
switch ( F_104 ( V_8 ) ) {
case V_114 :
V_55 = V_113 ;
goto V_115;
case V_116 :
V_55 = V_112 ;
goto V_115;
case V_117 :
V_55 = 0 ;
goto V_115;
}
F_102 ( 20 ) ;
}
return - V_99 ;
V_115:
F_105 ( V_3 , V_55 ) ;
F_105 ( V_3 , V_118 ) ;
F_32 ( V_10 , L_34 ,
V_37 , V_55 ) ;
return 0 ;
default:
return - V_99 ;
}
if ( V_100 )
F_105 ( V_3 , ( 1 << V_77 ) ) ;
else
F_100 ( V_3 , ( 1 << V_77 ) ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_2 V_94 , T_2 V_77 ,
T_2 V_95 , char * V_59 , T_2 V_96 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_119 * V_19 = (struct V_119 * ) V_59 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_93 = 1 ;
switch ( V_94 ) {
case V_120 :
F_32 ( V_10 , L_35 , V_37 ) ;
* V_59 = 0x00 ;
break;
case V_121 :
if ( V_95 != V_93 )
return - V_99 ;
F_32 ( V_10 , L_36 , V_37 ) ;
* ( V_122 * ) V_59 = F_107 ( F_96 ( V_3 ) ) ;
break;
case V_123 :
V_19 -> V_124 = 0x29 ;
V_19 -> V_125 = 0 ;
V_19 -> V_126 = V_93 ;
V_19 -> V_127 = 9 ;
V_19 -> V_128 = 0 ;
V_19 -> V_129 =
F_108 ( V_130 | V_131 ) ;
V_19 -> V_132 . V_133 . V_134 [ 0 ] = ( V_93 << 1 ) ;
V_19 -> V_132 . V_133 . V_134 [ 1 ] = ~ 0 ;
F_32 ( V_10 , L_37 , V_37 ) ;
break;
}
return 0 ;
}
static int F_109 ( struct V_44 * V_45 , T_2 V_94 , T_2 V_77 ,
T_2 V_95 , char * V_59 , T_2 V_96 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_34 = - V_99 ;
switch ( V_94 ) {
case V_135 :
case V_136 :
V_34 = F_97 ( V_3 , V_94 ,
V_77 , V_95 , V_59 , V_96 ) ;
break;
case V_101 :
case V_137 :
V_34 = F_98 ( V_3 , V_94 ,
V_77 , V_95 , V_59 , V_96 ) ;
break;
case V_120 :
case V_121 :
case V_123 :
V_34 = F_106 ( V_3 , V_94 ,
V_77 , V_95 , V_59 , V_96 ) ;
break;
}
F_32 ( V_10 , L_38 ,
V_94 , V_34 , F_96 ( V_3 ) ) ;
return V_34 ;
}
static int F_110 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_111 ( struct V_7 * V_8 ,
struct V_138 * V_139 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_32 ( V_10 , L_39 ) ;
F_105 ( V_3 , V_140 ) ;
F_105 ( V_3 , V_141 << 16 ) ;
V_3 -> V_12 . V_13 = NULL ;
F_112 ( V_8 , & V_3 -> V_12 ) ;
return 0 ;
}
static int F_113 ( struct V_7 * V_8 ,
struct V_138 * V_139 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_32 ( V_10 , L_40 ) ;
F_100 ( V_3 , V_140 ) ;
F_105 ( V_3 , V_141 << 16 ) ;
V_3 -> V_12 . V_13 = F_111 ;
F_112 ( V_8 , & V_3 -> V_12 ) ;
F_78 ( V_8 ) ;
return 0 ;
}
static int F_114 ( struct V_7 * V_8 ,
struct V_138 * V_139 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_32 ( V_10 , L_41 ) ;
F_115 ( & V_3 -> V_76 ) ;
return 0 ;
}
static int F_116 ( struct V_7 * V_8 ,
struct V_138 * V_139 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_32 ( V_10 , L_42 ) ;
F_115 ( & V_3 -> V_76 ) ;
return 0 ;
}
static void F_117 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_27 * V_21 ;
T_3 * V_142 = F_118 ( V_8 , V_142 ) ;
int V_143 = F_118 ( V_8 , V_143 ) ;
int V_144 , V_33 , V_32 ;
V_144 = V_145 ;
for ( V_32 = 0 ; V_32 < V_143 ; V_32 ++ ) {
V_33 = ( V_142 [ V_32 ] == V_144 ) ;
V_144 = V_142 [ V_32 ] ;
if ( V_145 == V_142 [ V_32 ] ) {
V_21 = F_119 ( V_8 ) ;
F_120 ( V_3 ) = V_21 ;
} else {
V_21 = F_121 ( V_8 ,
V_142 [ V_32 ] ,
V_33 ) ;
}
V_21 -> V_146 = NULL ;
}
}
static int F_122 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_147 * V_12 = F_123 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_34 ;
V_34 = F_124 ( V_45 , 0 , 0 ) ;
if ( V_34 < 0 )
return 0 ;
F_125 ( V_45 -> V_48 . V_148 ) ;
F_126 ( V_8 ) ;
F_127 ( V_8 ,
F_88 ) ;
F_117 ( V_8 ) ;
F_128 ( V_8 , 1 ) ;
V_12 -> V_13 = F_111 ;
V_12 -> V_149 = F_113 ;
V_12 -> V_150 = F_114 ;
V_12 -> V_151 = F_116 ;
F_112 ( V_8 , V_12 ) ;
F_32 ( V_10 , L_43 ) ;
return V_34 ;
}
static int F_129 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_147 * V_12 = F_123 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_12 -> V_13 = NULL ;
V_12 -> V_149 = NULL ;
V_12 -> V_150 = NULL ;
V_12 -> V_151 = NULL ;
F_112 ( V_8 , V_12 ) ;
F_130 ( V_45 ) ;
F_128 ( V_8 , 0 ) ;
F_32 ( V_10 , L_44 ) ;
return 0 ;
}
int F_131 ( struct V_7 * V_8 )
{
struct V_2 * V_3 ;
struct V_44 * V_45 ;
struct V_25 * V_26 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_32 ;
V_45 = F_132 ( & V_152 , V_10 , V_153 ) ;
if ( ! V_45 ) {
F_5 ( V_10 , L_45 ) ;
return - V_40 ;
}
V_45 -> V_154 = 1 ;
V_3 = F_71 ( V_45 ) ;
F_133 ( V_8 , & V_3 -> V_12 , V_155 ) ;
V_3 -> V_12 . V_156 = L_46 ;
V_3 -> V_12 . V_157 = F_122 ;
V_3 -> V_12 . V_158 = F_129 ;
F_134 ( V_3 ) ;
F_135 (udev, hpriv, i) {
V_26 -> V_47 = NULL ;
F_40 ( & V_26 -> V_42 ) ;
}
F_136 ( V_10 , L_47 ) ;
return 0 ;
}
int F_137 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
F_138 ( V_45 ) ;
return 0 ;
}
