static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_6 )
return NULL ;
F_3 ( & V_6 -> V_7 ) ;
V_6 -> V_4 = V_4 ;
F_4 ( V_4 ) = V_6 ;
return V_6 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
F_4 ( V_6 -> V_4 ) = NULL ;
V_6 -> V_4 = NULL ;
F_6 ( V_6 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
return ( V_3 -> V_8 . V_9 == NULL ) ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_10 * V_7 )
{
int V_11 = V_4 -> V_12 ;
int V_13 = F_9 ( & V_4 -> V_14 -> V_15 ) ;
int V_16 = 0 ;
if ( F_10 ( V_4 -> V_17 ) )
return;
V_16 = V_11 / V_13 ;
if ( V_11 % V_13 )
V_16 ++ ;
if ( V_7 -> V_18 )
V_16 ++ ;
V_16 %= 2 ;
if ( V_16 )
F_11 ( V_4 -> V_19 ,
F_12 ( V_4 -> V_17 ) ,
F_13 ( V_4 -> V_17 ) ) ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_22 * V_23 = F_16 ( V_4 -> V_14 ) ;
struct V_24 * V_25 = F_17 ( V_3 , V_4 ) ;
struct V_26 * V_17 ;
struct V_27 * V_15 = & V_4 -> V_14 -> V_15 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
unsigned long V_29 ;
int V_30 = ! ! F_19 ( V_4 -> V_17 ) ;
int V_31 = F_20 ( V_15 ) ;
int V_32 , V_33 ;
int V_34 = - V_35 ;
F_21 ( V_21 , V_29 ) ;
if ( F_22 ( V_23 ) ) {
V_34 = 0 ;
goto V_36;
}
F_23 (pipe, priv, i) {
if ( ! F_24 ( V_17 , F_25 ( V_15 ) ) )
continue;
if ( ! V_31 ) {
V_33 = ! ! F_26 ( V_17 ) ;
if ( 0 != ( V_33 - V_30 ) )
continue;
}
if ( F_27 ( V_17 ) )
continue;
F_22 ( V_23 ) = V_17 ;
F_27 ( V_17 ) = V_23 ;
F_28 ( V_17 ,
F_29 ( V_3 , V_25 ) ,
F_30 ( V_15 ) ,
F_9 ( V_15 ) ) ;
F_31 ( V_19 , L_1 , V_37 ,
F_29 ( V_3 , V_25 ) ,
F_30 ( V_15 ) ,
F_32 ( V_17 ) ,
V_30 ? L_2 : L_3 ) ;
V_34 = 0 ;
break;
}
V_36:
if ( 0 == V_34 )
V_23 -> V_38 ++ ;
F_33 ( V_21 , V_29 ) ;
return V_34 ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_26 * V_17 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
unsigned long V_29 ;
if ( F_35 ( ! V_23 ) ) {
F_36 ( V_19 , L_4 ) ;
return;
}
F_21 ( V_21 , V_29 ) ;
V_17 = F_22 ( V_23 ) ;
if ( F_35 ( ! V_17 ) ) {
F_36 ( V_19 , L_5 ) ;
} else if ( 1 == V_23 -> V_38 -- ) {
struct V_39 * V_14 = F_37 ( V_23 ) ;
struct V_24 * V_25 = F_38 ( V_23 ) ;
F_22 ( V_23 ) = NULL ;
F_27 ( V_17 ) = NULL ;
F_31 ( V_19 , L_6 , V_37 ,
F_29 ( V_3 , V_25 ) ,
F_30 ( & V_14 -> V_15 ) ,
F_32 ( V_17 ) ) ;
}
F_33 ( V_21 , V_29 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_24 * V_25 = F_17 ( V_3 , V_4 ) ;
struct V_39 * V_14 = V_4 -> V_14 ;
struct V_22 * V_23 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
struct V_27 * V_15 = & V_14 -> V_15 ;
unsigned long V_29 ;
V_23 = F_2 ( sizeof( struct V_22 ) , V_5 ) ;
if ( ! V_23 )
return - V_40 ;
F_21 ( V_21 , V_29 ) ;
V_23 -> V_38 = 0 ;
F_40 ( & V_23 -> V_41 ) ;
F_41 ( & V_23 -> V_41 , & V_25 -> V_42 ) ;
F_38 ( V_23 ) = V_25 ;
F_37 ( V_23 ) = V_14 ;
F_16 ( V_14 ) = V_23 ;
F_33 ( V_21 , V_29 ) ;
F_31 ( V_19 , L_7 , V_37 ,
F_29 ( V_3 , V_25 ) ,
F_30 ( V_15 ) ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_39 * V_14 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
struct V_22 * V_23 = F_16 ( V_14 ) ;
unsigned long V_29 ;
if ( ! V_23 )
return;
F_31 ( V_19 , L_7 , V_37 ,
F_29 ( V_3 , F_38 ( V_23 ) ) ,
F_30 ( & V_14 -> V_15 ) ) ;
if ( F_22 ( V_23 ) )
F_34 ( V_3 , V_23 ) ;
F_21 ( V_21 , V_29 ) ;
F_43 ( & V_23 -> V_41 ) ;
F_38 ( V_23 ) = NULL ;
F_37 ( V_23 ) = NULL ;
F_16 ( V_14 ) = NULL ;
F_33 ( V_21 , V_29 ) ;
F_6 ( V_23 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 , * V_43 ;
F_45 (uep, next, &udev->ep_list_head, ep_list)
F_42 ( V_3 , F_37 ( V_23 ) ) ;
}
static int F_46 ( struct V_44 * V_45 ,
struct V_24 * V_25 )
{
struct V_46 * V_47 = F_47 ( V_25 ) ;
return V_45 -> V_48 . V_49 == V_47 -> V_50 ;
}
static int F_48 ( struct V_24 * V_25 )
{
return ! F_49 ( & V_25 -> V_42 ) ;
}
static struct V_24 * F_17 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_24 * V_25 = F_51 ( V_47 ) ;
if ( ! V_25 )
return NULL ;
if ( 0 == F_52 ( V_4 -> V_17 ) )
return F_53 ( V_3 ) ;
return V_25 ;
}
static struct V_24 * F_54 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_24 * V_25 = NULL ;
struct V_24 * V_51 = F_53 ( V_3 ) ;
struct V_24 * V_52 ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_28 * V_19 = F_56 ( V_45 ) ;
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_20 * V_21 = F_15 ( V_3 ) ;
unsigned long V_29 ;
T_2 V_53 , V_54 ;
int V_32 ;
if ( 0 != F_52 ( V_4 -> V_17 ) ) {
F_36 ( V_19 , L_8 , V_37 ) ;
return NULL ;
}
F_21 ( V_21 , V_29 ) ;
F_57 (pos, hpriv, i) {
if ( F_58 ( V_52 ) )
continue;
V_25 = V_52 ;
break;
}
if ( V_25 ) {
F_59 ( & V_47 -> V_19 , V_25 ) ;
V_25 -> V_47 = V_47 ;
}
F_33 ( V_21 , V_29 ) ;
if ( ! V_25 ) {
F_36 ( V_19 , L_9 ) ;
return NULL ;
}
if ( F_48 ( V_25 ) ) {
F_60 ( V_19 , L_10 ) ;
F_44 ( V_3 , V_25 ) ;
}
if ( F_48 ( V_51 ) ) {
F_60 ( V_19 , L_11 ) ;
F_44 ( V_3 , V_51 ) ;
}
F_40 ( & V_51 -> V_42 ) ;
F_40 ( & V_25 -> V_42 ) ;
F_61 ( V_21 ,
0 , 0 , 0 , V_47 -> V_55 ) ;
V_53 = 0 ;
V_54 = 0 ;
if ( ! F_46 ( V_45 , V_25 ) ) {
struct V_24 * V_50 = F_62 ( V_25 ) ;
V_53 = F_29 ( V_3 , V_50 ) ;
V_54 = F_63 ( V_25 ) ;
F_31 ( V_19 , L_12 , V_37 ,
V_53 , V_54 , V_50 ) ;
}
F_61 ( V_21 ,
F_29 ( V_3 , V_25 ) ,
V_53 , V_54 , V_47 -> V_55 ) ;
F_31 ( V_19 , L_13 , V_37 ,
F_29 ( V_3 , V_25 ) , V_25 ) ;
return V_25 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_56 ( V_45 ) ;
struct V_46 * V_47 = F_47 ( V_25 ) ;
unsigned long V_29 ;
F_31 ( V_19 , L_13 , V_37 ,
F_29 ( V_3 , V_25 ) , V_25 ) ;
if ( F_48 ( V_25 ) ) {
F_60 ( V_19 , L_14 ) ;
F_44 ( V_3 , V_25 ) ;
}
if ( 0 == F_29 ( V_3 , V_25 ) )
return;
F_21 ( V_21 , V_29 ) ;
F_59 ( & V_47 -> V_19 , NULL ) ;
V_25 -> V_47 = NULL ;
F_33 ( V_21 , V_29 ) ;
}
static void F_65 ( struct V_20 * V_21 , struct V_10 * V_7 )
{
struct V_1 * V_6 = F_66 ( V_7 ) ;
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_4 * V_4 = V_6 -> V_4 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_56 = 0 ;
F_31 ( V_19 , L_15 , V_37 ) ;
if ( ! V_4 ) {
F_60 ( V_19 , L_16 ) ;
return;
}
if ( ! F_7 ( V_3 ) )
V_56 = - V_57 ;
V_4 -> V_12 = V_7 -> V_58 ;
F_8 ( V_3 , V_4 , V_7 ) ;
F_5 ( V_3 , V_6 ) ;
F_34 ( V_3 , F_16 ( V_4 -> V_14 ) ) ;
F_68 ( V_45 , V_4 ) ;
F_69 ( V_45 , V_4 , V_56 ) ;
}
static int F_70 ( struct V_44 * V_45 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_22 * V_23 = F_16 ( V_4 -> V_14 ) ;
struct V_26 * V_17 = F_22 ( V_23 ) ;
struct V_28 * V_19 = F_56 ( V_45 ) ;
struct V_1 * V_6 ;
void * V_59 ;
int V_11 , V_60 ;
if ( F_72 ( V_4 -> V_17 ) ) {
F_36 ( V_19 , L_17 ) ;
return - V_61 ;
}
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_35 ( ! V_6 ) ) {
F_36 ( V_19 , L_18 ) ;
return - V_40 ;
}
if ( F_19 ( V_4 -> V_17 ) )
V_17 -> V_62 = & V_63 ;
else
V_17 -> V_62 = & V_64 ;
V_59 = ( void * ) ( V_4 -> V_65 + V_4 -> V_12 ) ;
V_11 = V_4 -> V_66 - V_4 -> V_12 ;
V_60 = F_73 ( V_4 -> V_19 ,
F_12 ( V_4 -> V_17 ) ,
F_13 ( V_4 -> V_17 ) ) ;
F_31 ( V_19 , L_15 , V_37 ) ;
F_74 ( V_17 , & V_6 -> V_7 , F_65 ,
V_59 , V_11 , ( V_4 -> V_67 & V_68 ) ,
V_60 ) ;
F_75 ( V_17 ) ;
return 0 ;
}
static void F_76 ( struct V_20 * V_21 ,
struct V_26 * V_17 )
{
struct V_10 * V_7 ;
while ( 1 ) {
V_7 = F_77 ( V_17 , NULL ) ;
if ( ! V_7 )
break;
F_65 ( V_21 , V_7 ) ;
}
}
static void F_78 ( struct V_20 * V_21 )
{
struct V_26 * V_52 ;
int V_32 ;
F_23 (pos, priv, i)
F_76 ( V_21 , V_52 ) ;
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
struct V_26 * V_17 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_69 V_70 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
F_81 ( & V_3 -> V_76 ) ;
memcpy ( & V_70 , V_4 -> V_71 , sizeof( struct V_69 ) ) ;
if ( F_79 ( V_4 ) ) {
struct V_46 * V_47 = F_50 ( V_4 ) ;
struct V_24 * V_25 = F_51 ( V_47 ) ;
V_70 . V_77 = F_29 ( V_3 , V_25 ) ;
F_31 ( V_19 , L_19 , V_70 . V_77 ) ;
}
F_82 ( V_21 , & V_70 ) ;
F_83 ( & V_3 -> V_76 ) ;
F_31 ( V_19 , L_20 , V_37 ) ;
}
static void F_84 ( struct V_20 * V_21 ,
struct V_10 * V_7 )
{
struct V_1 * V_6 = F_66 ( V_7 ) ;
struct V_2 * V_3 = F_67 ( V_21 ) ;
F_5 ( V_3 , V_6 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_26 * V_17 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_35 ( ! V_6 ) )
return - V_40 ;
if ( F_19 ( V_4 -> V_17 ) )
V_17 -> V_62 = & V_78 ;
else
V_17 -> V_62 = & V_79 ;
F_74 ( V_17 , & V_6 -> V_7 ,
F_84 ,
V_4 -> V_65 ,
V_4 -> V_66 ,
( V_4 -> V_67 & V_68 ) ,
- 1 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_26 * V_17 ,
T_1 V_5 )
{
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_35 ( ! V_6 ) )
return - V_40 ;
if ( F_19 ( V_4 -> V_17 ) )
V_17 -> V_62 = & V_80 ;
else
V_17 -> V_62 = & V_81 ;
F_74 ( V_17 , & V_6 -> V_7 ,
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
struct V_22 * V_23 = F_16 ( V_4 -> V_14 ) ;
struct V_26 * V_17 = F_22 ( V_23 ) ;
struct V_28 * V_19 = F_56 ( V_45 ) ;
int V_34 ;
F_31 ( V_19 , L_15 , V_37 ) ;
F_80 ( V_3 , V_4 , V_17 ) ;
if ( V_4 -> V_66 ) {
V_34 = F_85 ( V_3 , V_4 , V_17 , V_82 ) ;
if ( V_34 < 0 ) {
F_36 ( V_19 , L_21 ) ;
return V_34 ;
}
}
V_34 = F_86 ( V_3 , V_4 , V_17 , V_82 ) ;
if ( V_34 < 0 ) {
F_36 ( V_19 , L_22 ) ;
return V_34 ;
}
F_75 ( V_17 ) ;
return 0 ;
}
static int F_88 ( struct V_28 * V_83 , struct V_10 * V_7 ,
int V_84 )
{
if ( V_84 ) {
struct V_1 * V_6 = F_66 ( V_7 ) ;
struct V_4 * V_4 = V_6 -> V_4 ;
if ( V_4 -> V_85 )
return - V_86 ;
V_7 -> V_87 = V_4 -> V_88 ;
if ( ! V_7 -> V_87 )
return - V_86 ;
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
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
struct V_39 * V_14 = V_4 -> V_14 ;
struct V_24 * V_89 = NULL ;
int V_90 = F_19 ( V_4 -> V_17 ) ;
int V_34 ;
F_31 ( V_19 , L_23 , V_37 , V_90 ? L_2 : L_3 ) ;
if ( ! F_7 ( V_3 ) ) {
V_34 = - V_61 ;
F_36 ( V_19 , L_24 ) ;
goto V_91;
}
V_34 = F_92 ( V_45 , V_4 ) ;
if ( V_34 ) {
F_36 ( V_19 , L_25 ) ;
goto V_91;
}
if ( ! F_17 ( V_3 , V_4 ) ) {
V_89 = F_54 ( V_3 , V_4 ) ;
if ( ! V_89 ) {
V_34 = - V_61 ;
F_36 ( V_19 , L_26 ) ;
goto V_91;
}
}
if ( ! F_16 ( V_14 ) ) {
V_34 = F_39 ( V_3 , V_4 , V_5 ) ;
if ( V_34 < 0 ) {
F_36 ( V_19 , L_27 ) ;
goto V_92;
}
}
V_34 = F_14 ( V_3 , V_4 ) ;
if ( V_34 < 0 ) {
F_36 ( V_19 , L_28 ) ;
goto V_93;
}
if ( F_10 ( V_4 -> V_17 ) )
V_34 = F_87 ( V_45 , V_4 , V_5 ) ;
else
V_34 = F_70 ( V_45 , V_4 , V_5 ) ;
return V_34 ;
V_93:
F_42 ( V_3 , V_14 ) ;
V_92:
if ( V_89 )
F_64 ( V_3 , V_89 ) ;
V_91:
F_31 ( V_19 , L_29 , V_37 ) ;
return V_34 ;
}
static int F_93 ( struct V_44 * V_45 , struct V_4 * V_4 , int V_56 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_1 * V_6 = F_4 ( V_4 ) ;
if ( V_6 ) {
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_10 * V_7 = & V_6 -> V_7 ;
F_77 ( V_7 -> V_17 , V_7 ) ;
F_65 ( V_21 , V_7 ) ;
}
return 0 ;
}
static void F_94 ( struct V_44 * V_45 ,
struct V_39 * V_14 )
{
struct V_22 * V_23 = F_16 ( V_14 ) ;
struct V_24 * V_25 ;
struct V_2 * V_3 ;
if ( ! V_23 )
return;
V_25 = F_38 ( V_23 ) ;
V_3 = F_71 ( V_45 ) ;
F_42 ( V_3 , V_14 ) ;
if ( ! F_48 ( V_25 ) )
F_64 ( V_3 , V_25 ) ;
}
static int F_95 ( struct V_44 * V_45 , char * V_59 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
int V_94 = 1 ;
if ( F_96 ( V_3 ) & 0xFFFF0000 )
* V_59 = ( 1 << V_94 ) ;
else
* V_59 = 0 ;
return ! ! ( * V_59 ) ;
}
static int F_97 ( struct V_2 * V_3 ,
T_2 V_95 , T_2 V_77 ,
T_2 V_96 , char * V_59 , T_2 V_97 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
switch ( V_77 ) {
case V_98 :
case V_99 :
F_31 ( V_19 , L_30 , V_37 ) ;
return 0 ;
}
return - V_100 ;
}
static int F_98 ( struct V_2 * V_3 ,
T_2 V_95 , T_2 V_77 ,
T_2 V_96 , char * V_59 , T_2 V_97 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_101 = ( V_95 == V_102 ) ;
int V_55 , V_32 , V_103 = 128 ;
int V_94 = 1 ;
if ( V_96 > V_94 || V_97 != 0 )
return - V_100 ;
switch ( V_77 ) {
case V_104 :
F_99 ( V_21 , V_101 ) ;
F_31 ( V_19 , L_31 , V_37 ) ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
F_31 ( V_19 , L_32 , V_37 ) ;
break;
case V_112 :
if ( ! V_101 )
break;
F_100 ( V_3 ,
V_113 |
V_114 ) ;
F_78 ( V_21 ) ;
F_101 ( V_21 ) ;
F_102 ( 20 ) ;
F_103 ( V_21 ) ;
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
switch ( F_104 ( V_21 ) ) {
case V_115 :
V_55 = V_114 ;
goto V_116;
case V_117 :
V_55 = V_113 ;
goto V_116;
case V_118 :
V_55 = 0 ;
goto V_116;
}
F_102 ( 20 ) ;
}
return - V_100 ;
V_116:
F_105 ( V_3 , V_55 ) ;
F_105 ( V_3 , V_119 ) ;
F_31 ( V_19 , L_33 ,
V_37 , V_55 ) ;
return 0 ;
default:
return - V_100 ;
}
if ( V_101 )
F_105 ( V_3 , ( 1 << V_77 ) ) ;
else
F_100 ( V_3 , ( 1 << V_77 ) ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_2 V_95 , T_2 V_77 ,
T_2 V_96 , char * V_59 , T_2 V_97 )
{
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_120 * V_15 = (struct V_120 * ) V_59 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_94 = 1 ;
switch ( V_95 ) {
case V_121 :
F_31 ( V_19 , L_34 , V_37 ) ;
* V_59 = 0x00 ;
break;
case V_122 :
if ( V_96 != V_94 )
return - V_100 ;
F_31 ( V_19 , L_35 , V_37 ) ;
* ( V_123 * ) V_59 = F_107 ( F_96 ( V_3 ) ) ;
break;
case V_124 :
V_15 -> V_125 = V_126 ;
V_15 -> V_127 = 0 ;
V_15 -> V_128 = V_94 ;
V_15 -> V_129 = 9 ;
V_15 -> V_130 = 0 ;
V_15 -> V_131 =
F_108 ( V_132 | V_133 ) ;
V_15 -> V_134 . V_135 . V_136 [ 0 ] = ( V_94 << 1 ) ;
V_15 -> V_134 . V_135 . V_136 [ 1 ] = ~ 0 ;
F_31 ( V_19 , L_36 , V_37 ) ;
break;
}
return 0 ;
}
static int F_109 ( struct V_44 * V_45 , T_2 V_95 , T_2 V_77 ,
T_2 V_96 , char * V_59 , T_2 V_97 )
{
struct V_2 * V_3 = F_71 ( V_45 ) ;
struct V_20 * V_21 = F_15 ( V_3 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_34 = - V_100 ;
switch ( V_95 ) {
case V_137 :
case V_138 :
V_34 = F_97 ( V_3 , V_95 ,
V_77 , V_96 , V_59 , V_97 ) ;
break;
case V_102 :
case V_139 :
V_34 = F_98 ( V_3 , V_95 ,
V_77 , V_96 , V_59 , V_97 ) ;
break;
case V_121 :
case V_122 :
case V_124 :
V_34 = F_106 ( V_3 , V_95 ,
V_77 , V_96 , V_59 , V_97 ) ;
break;
}
F_31 ( V_19 , L_37 ,
V_95 , V_34 , F_96 ( V_3 ) ) ;
return V_34 ;
}
static int F_110 ( struct V_44 * V_45 )
{
return 0 ;
}
static int F_111 ( struct V_20 * V_21 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
F_31 ( V_19 , L_38 ) ;
F_105 ( V_3 , V_142 ) ;
F_105 ( V_3 , V_143 << 16 ) ;
V_3 -> V_8 . V_9 = NULL ;
F_112 ( V_21 , & V_3 -> V_8 ) ;
return 0 ;
}
static int F_113 ( struct V_20 * V_21 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
F_31 ( V_19 , L_39 ) ;
F_100 ( V_3 , V_142 ) ;
F_105 ( V_3 , V_143 << 16 ) ;
V_3 -> V_8 . V_9 = F_111 ;
F_112 ( V_21 , & V_3 -> V_8 ) ;
F_78 ( V_21 ) ;
return 0 ;
}
static int F_114 ( struct V_20 * V_21 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
F_31 ( V_19 , L_40 ) ;
F_115 ( & V_3 -> V_76 ) ;
return 0 ;
}
static int F_116 ( struct V_20 * V_21 ,
struct V_140 * V_141 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
F_31 ( V_19 , L_41 ) ;
F_115 ( & V_3 -> V_76 ) ;
return 0 ;
}
static void F_117 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_26 * V_17 ;
struct V_144 * V_145 =
F_118 ( V_21 , V_145 ) ;
int V_146 = F_118 ( V_21 , V_146 ) ;
int V_147 , V_33 , V_32 ;
V_147 = V_148 ;
for ( V_32 = 0 ; V_32 < V_146 ; V_32 ++ ) {
V_33 = ( V_145 [ V_32 ] . type == V_147 ) ;
V_147 = V_145 [ V_32 ] . type ;
if ( V_148 == V_145 [ V_32 ] . type ) {
V_17 = F_119 ( V_21 ) ;
F_120 ( V_3 ) = V_17 ;
} else {
V_17 = F_121 ( V_21 ,
V_145 [ V_32 ] . type ,
V_33 ) ;
}
V_17 -> V_149 = NULL ;
}
}
static int F_122 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_150 * V_8 = F_123 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_34 ;
V_34 = F_124 ( V_45 , 0 , 0 ) ;
if ( V_34 < 0 )
return 0 ;
F_125 ( V_45 -> V_48 . V_151 ) ;
F_126 ( V_21 ) ;
F_127 ( V_21 ,
F_88 ) ;
F_117 ( V_21 ) ;
F_128 ( V_21 , 1 ) ;
V_8 -> V_9 = F_111 ;
V_8 -> V_152 = F_113 ;
V_8 -> V_153 = F_114 ;
V_8 -> V_154 = F_116 ;
F_112 ( V_21 , V_8 ) ;
F_31 ( V_19 , L_42 ) ;
return V_34 ;
}
static int F_129 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
struct V_150 * V_8 = F_123 ( V_21 ) ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
V_8 -> V_9 = NULL ;
V_8 -> V_152 = NULL ;
V_8 -> V_153 = NULL ;
V_8 -> V_154 = NULL ;
F_112 ( V_21 , V_8 ) ;
F_130 ( V_45 ) ;
F_128 ( V_21 , 0 ) ;
F_31 ( V_19 , L_43 ) ;
return 0 ;
}
int F_131 ( struct V_20 * V_21 )
{
struct V_2 * V_3 ;
struct V_44 * V_45 ;
struct V_24 * V_25 ;
struct V_28 * V_19 = F_18 ( V_21 ) ;
int V_32 ;
V_45 = F_132 ( & V_155 , V_19 , V_156 ) ;
if ( ! V_45 ) {
F_36 ( V_19 , L_44 ) ;
return - V_40 ;
}
V_45 -> V_157 = 1 ;
V_3 = F_71 ( V_45 ) ;
F_133 ( V_21 , & V_3 -> V_8 , V_158 ) ;
V_3 -> V_8 . V_159 = L_45 ;
V_3 -> V_8 . V_160 = F_122 ;
V_3 -> V_8 . V_161 = F_129 ;
F_134 ( V_3 ) ;
F_135 (udev, hpriv, i) {
V_25 -> V_47 = NULL ;
F_40 ( & V_25 -> V_42 ) ;
}
F_136 ( V_19 , L_46 ) ;
return 0 ;
}
int F_137 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_67 ( V_21 ) ;
struct V_44 * V_45 = F_55 ( V_3 ) ;
F_138 ( V_45 ) ;
return 0 ;
}
