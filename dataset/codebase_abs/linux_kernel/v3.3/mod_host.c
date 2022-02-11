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
if ( F_23 ( F_24 ( V_24 ) ) ) {
F_5 ( V_10 , L_2 ) ;
goto V_36;
}
F_25 (pipe, priv, i) {
if ( ! F_26 ( V_21 , F_27 ( V_19 ) ) )
continue;
if ( ! V_31 ) {
V_33 = ! ! F_28 ( V_21 ) ;
if ( 0 != ( V_33 - V_30 ) )
continue;
}
if ( F_29 ( V_21 ) )
continue;
F_24 ( V_24 ) = V_21 ;
F_29 ( V_21 ) = V_24 ;
F_30 ( V_21 ,
F_31 ( V_3 , V_26 ) ,
F_32 ( V_19 ) ,
F_12 ( V_19 ) ) ;
F_33 ( V_10 , L_3 , V_37 ,
F_31 ( V_3 , V_26 ) ,
F_32 ( V_19 ) ,
F_34 ( V_21 ) ,
V_30 ? L_4 : L_5 ) ;
V_34 = 0 ;
break;
}
V_36:
F_35 ( V_8 , V_29 ) ;
return V_34 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_27 * V_21 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
unsigned long V_29 ;
F_22 ( V_8 , V_29 ) ;
V_21 = F_24 ( V_24 ) ;
if ( F_23 ( ! V_21 ) ) {
F_5 ( V_10 , L_6 ) ;
} else {
struct V_38 * V_18 = F_37 ( V_24 ) ;
struct V_25 * V_26 = F_38 ( V_24 ) ;
F_24 ( V_24 ) = NULL ;
F_29 ( V_21 ) = NULL ;
F_33 ( V_10 , L_7 , V_37 ,
F_31 ( V_3 , V_26 ) ,
F_32 ( & V_18 -> V_19 ) ,
F_34 ( V_21 ) ) ;
}
F_35 ( V_8 , V_29 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_25 * V_26 = F_19 ( V_3 , V_4 ) ;
struct V_38 * V_18 = V_4 -> V_18 ;
struct V_23 * V_24 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_28 * V_19 = & V_18 -> V_19 ;
unsigned long V_29 ;
V_24 = F_4 ( sizeof( struct V_23 ) , V_5 ) ;
if ( ! V_24 ) {
F_5 ( V_10 , L_8 ) ;
return - V_39 ;
}
F_22 ( V_8 , V_29 ) ;
F_40 ( & V_24 -> V_40 ) ;
F_41 ( & V_24 -> V_40 , & V_26 -> V_41 ) ;
F_38 ( V_24 ) = V_26 ;
F_37 ( V_24 ) = V_18 ;
F_18 ( V_18 ) = V_24 ;
F_35 ( V_8 , V_29 ) ;
F_33 ( V_10 , L_9 , V_37 ,
F_31 ( V_3 , V_26 ) ,
F_32 ( V_19 ) ) ;
return 0 ;
}
static void F_42 ( struct V_2 * V_3 ,
struct V_38 * V_18 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_23 * V_24 = F_18 ( V_18 ) ;
unsigned long V_29 ;
if ( ! V_24 )
return;
F_33 ( V_10 , L_9 , V_37 ,
F_31 ( V_3 , F_38 ( V_24 ) ) ,
F_32 ( & V_18 -> V_19 ) ) ;
if ( F_24 ( V_24 ) )
F_36 ( V_3 , V_24 ) ;
F_22 ( V_8 , V_29 ) ;
F_43 ( & V_24 -> V_40 ) ;
F_38 ( V_24 ) = NULL ;
F_37 ( V_24 ) = NULL ;
F_18 ( V_18 ) = NULL ;
F_35 ( V_8 , V_29 ) ;
F_9 ( V_24 ) ;
}
static void F_44 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_23 * V_24 , * V_42 ;
F_45 (uep, next, &udev->ep_list_head, ep_list)
F_42 ( V_3 , F_37 ( V_24 ) ) ;
}
static int F_46 ( struct V_43 * V_44 ,
struct V_25 * V_26 )
{
struct V_45 * V_46 = F_47 ( V_26 ) ;
return V_44 -> V_47 . V_48 == V_46 -> V_49 ;
}
static int F_48 ( struct V_25 * V_26 )
{
return ! F_49 ( & V_26 -> V_41 ) ;
}
static struct V_25 * F_19 ( struct V_2 * V_3 ,
struct V_4 * V_4 )
{
struct V_45 * V_46 = F_50 ( V_4 ) ;
struct V_25 * V_26 = F_51 ( V_46 ) ;
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
struct V_25 * V_50 = F_53 ( V_3 ) ;
struct V_25 * V_51 ;
struct V_43 * V_44 = F_55 ( V_3 ) ;
struct V_9 * V_10 = F_56 ( V_44 ) ;
struct V_45 * V_46 = F_50 ( V_4 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
unsigned long V_29 ;
T_2 V_52 , V_53 ;
int V_32 ;
if ( 0 != F_52 ( V_4 -> V_21 ) ) {
F_5 ( V_10 , L_10 , V_37 ) ;
return NULL ;
}
F_22 ( V_8 , V_29 ) ;
F_57 (pos, hpriv, i) {
if ( F_58 ( V_51 ) )
continue;
V_26 = V_51 ;
break;
}
if ( V_26 ) {
F_59 ( & V_46 -> V_10 , V_26 ) ;
V_26 -> V_46 = V_46 ;
}
F_35 ( V_8 , V_29 ) ;
if ( ! V_26 ) {
F_5 ( V_10 , L_11 ) ;
return NULL ;
}
if ( F_48 ( V_26 ) ) {
F_60 ( V_10 , L_12 ) ;
F_44 ( V_3 , V_26 ) ;
}
if ( F_48 ( V_50 ) ) {
F_60 ( V_10 , L_13 ) ;
F_44 ( V_3 , V_50 ) ;
}
F_40 ( & V_50 -> V_41 ) ;
F_40 ( & V_26 -> V_41 ) ;
F_61 ( V_8 ,
0 , 0 , 0 , V_46 -> V_54 ) ;
V_52 = 0 ;
V_53 = 0 ;
if ( ! F_46 ( V_44 , V_26 ) ) {
struct V_25 * V_49 = F_62 ( V_26 ) ;
V_52 = F_31 ( V_3 , V_49 ) ;
V_53 = F_63 ( V_26 ) ;
F_33 ( V_10 , L_14 , V_37 ,
V_52 , V_53 , V_49 ) ;
}
F_61 ( V_8 ,
F_31 ( V_3 , V_26 ) ,
V_52 , V_53 , V_46 -> V_54 ) ;
F_33 ( V_10 , L_15 , V_37 ,
F_31 ( V_3 , V_26 ) , V_26 ) ;
return V_26 ;
}
static void F_64 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_43 * V_44 = F_55 ( V_3 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_56 ( V_44 ) ;
struct V_45 * V_46 = F_47 ( V_26 ) ;
unsigned long V_29 ;
F_33 ( V_10 , L_15 , V_37 ,
F_31 ( V_3 , V_26 ) , V_26 ) ;
if ( F_48 ( V_26 ) ) {
F_60 ( V_10 , L_16 ) ;
F_44 ( V_3 , V_26 ) ;
}
if ( 0 == F_31 ( V_3 , V_26 ) )
return;
F_22 ( V_8 , V_29 ) ;
F_59 ( & V_46 -> V_10 , NULL ) ;
V_26 -> V_46 = NULL ;
F_35 ( V_8 , V_29 ) ;
}
static void F_65 ( struct V_7 * V_8 , struct V_14 * V_11 )
{
struct V_1 * V_6 = F_66 ( V_11 ) ;
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_43 * V_44 = F_55 ( V_3 ) ;
struct V_4 * V_4 = V_6 -> V_4 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_55 = 0 ;
F_33 ( V_10 , L_17 , V_37 ) ;
if ( ! V_4 ) {
F_60 ( V_10 , L_18 ) ;
return;
}
if ( ! F_10 ( V_3 ) )
V_55 = - V_56 ;
V_4 -> V_16 = V_11 -> V_57 ;
F_8 ( V_3 , V_6 ) ;
F_11 ( V_3 , V_4 , V_11 ) ;
F_36 ( V_3 , F_18 ( V_4 -> V_18 ) ) ;
F_68 ( V_44 , V_4 ) ;
F_69 ( V_44 , V_4 , V_55 ) ;
}
static int F_70 ( struct V_43 * V_44 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_23 * V_24 = F_18 ( V_4 -> V_18 ) ;
struct V_27 * V_21 = F_24 ( V_24 ) ;
struct V_9 * V_10 = F_56 ( V_44 ) ;
struct V_1 * V_6 ;
void * V_58 ;
int V_15 , V_59 ;
if ( F_72 ( V_4 -> V_21 ) ) {
F_5 ( V_10 , L_19 ) ;
return - V_60 ;
}
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_23 ( ! V_6 ) ) {
F_5 ( V_10 , L_1 ) ;
return - V_39 ;
}
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_61 = & V_62 ;
else
V_21 -> V_61 = & V_63 ;
V_58 = ( void * ) ( V_4 -> V_64 + V_4 -> V_16 ) ;
V_15 = V_4 -> V_65 - V_4 -> V_16 ;
V_59 = F_73 ( V_4 -> V_10 ,
F_15 ( V_4 -> V_21 ) ,
F_16 ( V_4 -> V_21 ) ) ;
F_33 ( V_10 , L_17 , V_37 ) ;
F_74 ( V_21 , & V_6 -> V_11 , F_65 ,
V_58 , V_15 , ( V_4 -> V_66 & V_67 ) ,
V_59 ) ;
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
struct V_27 * V_51 ;
int V_32 ;
F_25 (pos, priv, i)
F_76 ( V_8 , V_51 ) ;
}
static int F_79 ( struct V_4 * V_4 )
{
struct V_68 * V_69 ;
V_69 = (struct V_68 * ) V_4 -> V_70 ;
if ( ( V_71 == V_69 -> V_72 << 8 ) &&
( V_73 == V_69 -> V_74 ) )
return 1 ;
else
return 0 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_4 * V_4 ,
struct V_27 * V_21 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_68 V_69 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_81 ( & V_3 -> V_75 ) ;
memcpy ( & V_69 , V_4 -> V_70 , sizeof( struct V_68 ) ) ;
if ( F_79 ( V_4 ) ) {
struct V_45 * V_46 = F_50 ( V_4 ) ;
struct V_25 * V_26 = F_51 ( V_46 ) ;
V_69 . V_76 = F_31 ( V_3 , V_26 ) ;
F_33 ( V_10 , L_20 , V_69 . V_76 ) ;
}
F_82 ( V_8 , & V_69 ) ;
F_83 ( & V_3 -> V_75 ) ;
F_33 ( V_10 , L_21 , V_37 ) ;
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
if ( F_23 ( ! V_6 ) )
return - V_39 ;
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_61 = & V_77 ;
else
V_21 -> V_61 = & V_78 ;
F_74 ( V_21 , & V_6 -> V_11 ,
F_84 ,
V_4 -> V_64 ,
V_4 -> V_65 ,
( V_4 -> V_66 & V_67 ) ,
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
if ( F_23 ( ! V_6 ) )
return - V_39 ;
if ( F_20 ( V_4 -> V_21 ) )
V_21 -> V_61 = & V_79 ;
else
V_21 -> V_61 = & V_80 ;
F_74 ( V_21 , & V_6 -> V_11 ,
F_65 ,
NULL ,
V_4 -> V_65 ,
0 , - 1 ) ;
return 0 ;
}
static int F_87 ( struct V_43 * V_44 ,
struct V_4 * V_4 ,
T_1 V_81 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_23 * V_24 = F_18 ( V_4 -> V_18 ) ;
struct V_27 * V_21 = F_24 ( V_24 ) ;
struct V_9 * V_10 = F_56 ( V_44 ) ;
int V_34 ;
F_33 ( V_10 , L_17 , V_37 ) ;
F_80 ( V_3 , V_4 , V_21 ) ;
if ( V_4 -> V_65 ) {
V_34 = F_85 ( V_3 , V_4 , V_21 , V_81 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_22 ) ;
return V_34 ;
}
}
V_34 = F_86 ( V_3 , V_4 , V_21 , V_81 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_23 ) ;
return V_34 ;
}
F_75 ( V_21 ) ;
return 0 ;
}
static int F_88 ( struct V_14 * V_11 , int V_82 )
{
return 0 ;
}
static int F_89 ( struct V_43 * V_44 )
{
return 0 ;
}
static void F_90 ( struct V_43 * V_44 )
{
}
static int F_91 ( struct V_43 * V_44 ,
struct V_4 * V_4 ,
T_1 V_5 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
struct V_38 * V_18 = V_4 -> V_18 ;
struct V_25 * V_83 = NULL ;
int V_84 = F_20 ( V_4 -> V_21 ) ;
int V_32 ;
int V_34 ;
F_33 ( V_10 , L_24 , V_37 , V_84 ? L_4 : L_5 ) ;
if ( ! F_10 ( V_3 ) ) {
V_34 = - V_60 ;
F_5 ( V_10 , L_25 ) ;
goto V_85;
}
V_34 = F_92 ( V_44 , V_4 ) ;
if ( V_34 ) {
F_5 ( V_10 , L_26 ) ;
goto V_85;
}
if ( ! F_19 ( V_3 , V_4 ) ) {
V_83 = F_54 ( V_3 , V_4 ) ;
if ( ! V_83 ) {
V_34 = - V_60 ;
F_5 ( V_10 , L_27 ) ;
goto V_85;
}
}
if ( ! F_18 ( V_18 ) ) {
V_34 = F_39 ( V_3 , V_4 , V_5 ) ;
if ( V_34 < 0 ) {
F_5 ( V_10 , L_28 ) ;
goto V_86;
}
}
for ( V_32 = 0 ; V_32 < 1024 ; V_32 ++ ) {
V_34 = F_17 ( V_3 , V_4 ) ;
if ( V_34 < 0 )
F_93 ( 100 ) ;
else
break;
}
if ( V_34 < 0 ) {
F_5 ( V_10 , L_29 ) ;
goto V_87;
}
if ( F_13 ( V_4 -> V_21 ) )
V_34 = F_87 ( V_44 , V_4 , V_5 ) ;
else
V_34 = F_70 ( V_44 , V_4 , V_5 ) ;
return V_34 ;
V_87:
F_42 ( V_3 , V_18 ) ;
V_86:
if ( V_83 )
F_64 ( V_3 , V_83 ) ;
V_85:
F_33 ( V_10 , L_30 , V_37 ) ;
return V_34 ;
}
static int F_94 ( struct V_43 * V_44 , struct V_4 * V_4 , int V_55 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_1 * V_6 = F_7 ( V_4 ) ;
if ( V_6 ) {
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_14 * V_11 = & V_6 -> V_11 ;
F_77 ( V_11 -> V_21 , V_11 ) ;
F_65 ( V_8 , V_11 ) ;
}
return 0 ;
}
static void F_95 ( struct V_43 * V_44 ,
struct V_38 * V_18 )
{
struct V_23 * V_24 = F_18 ( V_18 ) ;
struct V_25 * V_26 ;
struct V_2 * V_3 ;
if ( ! V_24 )
return;
V_26 = F_38 ( V_24 ) ;
V_3 = F_71 ( V_44 ) ;
F_42 ( V_3 , V_18 ) ;
if ( ! F_48 ( V_26 ) )
F_64 ( V_3 , V_26 ) ;
}
static int F_96 ( struct V_43 * V_44 , char * V_58 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_88 = 1 ;
if ( F_97 ( V_3 ) & 0xFFFF0000 )
* V_58 = ( 1 << V_88 ) ;
else
* V_58 = 0 ;
F_33 ( V_10 , L_31 , V_37 , * V_58 ) ;
return ! ! ( * V_58 ) ;
}
static int F_98 ( struct V_2 * V_3 ,
T_2 V_89 , T_2 V_76 ,
T_2 V_90 , char * V_58 , T_2 V_91 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
switch ( V_76 ) {
case V_92 :
case V_93 :
F_33 ( V_10 , L_32 , V_37 ) ;
return 0 ;
}
return - V_94 ;
}
static int F_99 ( struct V_2 * V_3 ,
T_2 V_89 , T_2 V_76 ,
T_2 V_90 , char * V_58 , T_2 V_91 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_95 = ( V_89 == V_96 ) ;
int V_54 , V_32 , V_97 = 128 ;
int V_88 = 1 ;
if ( V_90 > V_88 || V_91 != 0 )
return - V_94 ;
switch ( V_76 ) {
case V_98 :
F_100 ( V_8 , V_95 ) ;
F_33 ( V_10 , L_33 , V_37 ) ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
F_33 ( V_10 , L_34 , V_37 ) ;
break;
case V_106 :
if ( ! V_95 )
break;
F_101 ( V_3 ,
V_107 |
V_108 ) ;
F_78 ( V_8 ) ;
F_102 ( V_8 ) ;
F_93 ( 20 ) ;
F_103 ( V_8 ) ;
for ( V_32 = 0 ; V_32 < V_97 ; V_32 ++ ) {
switch ( F_104 ( V_8 ) ) {
case V_109 :
V_54 = V_108 ;
goto V_110;
case V_111 :
V_54 = V_107 ;
goto V_110;
case V_112 :
V_54 = 0 ;
goto V_110;
}
F_93 ( 20 ) ;
}
return - V_94 ;
V_110:
F_105 ( V_3 , V_54 ) ;
F_105 ( V_3 , V_113 ) ;
F_33 ( V_10 , L_35 ,
V_37 , V_54 ) ;
return 0 ;
default:
return - V_94 ;
}
if ( V_95 )
F_105 ( V_3 , ( 1 << V_76 ) ) ;
else
F_101 ( V_3 , ( 1 << V_76 ) ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 ,
T_2 V_89 , T_2 V_76 ,
T_2 V_90 , char * V_58 , T_2 V_91 )
{
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_114 * V_19 = (struct V_114 * ) V_58 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_88 = 1 ;
switch ( V_89 ) {
case V_115 :
F_33 ( V_10 , L_36 , V_37 ) ;
* V_58 = 0x00 ;
break;
case V_116 :
if ( V_90 != V_88 )
return - V_94 ;
F_33 ( V_10 , L_37 , V_37 ) ;
* ( V_117 * ) V_58 = F_107 ( F_97 ( V_3 ) ) ;
break;
case V_118 :
V_19 -> V_119 = 0x29 ;
V_19 -> V_120 = 0 ;
V_19 -> V_121 = V_88 ;
V_19 -> V_122 = 9 ;
V_19 -> V_123 = 0 ;
V_19 -> V_124 = F_108 ( 0x0011 ) ;
V_19 -> V_125 . V_126 . V_127 [ 0 ] = ( V_88 << 1 ) ;
V_19 -> V_125 . V_126 . V_127 [ 1 ] = ~ 0 ;
F_33 ( V_10 , L_38 , V_37 ) ;
break;
}
return 0 ;
}
static int F_109 ( struct V_43 * V_44 , T_2 V_89 , T_2 V_76 ,
T_2 V_90 , char * V_58 , T_2 V_91 )
{
struct V_2 * V_3 = F_71 ( V_44 ) ;
struct V_7 * V_8 = F_2 ( V_3 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_34 = - V_94 ;
switch ( V_89 ) {
case V_128 :
case V_129 :
V_34 = F_98 ( V_3 , V_89 ,
V_76 , V_90 , V_58 , V_91 ) ;
break;
case V_96 :
case V_130 :
V_34 = F_99 ( V_3 , V_89 ,
V_76 , V_90 , V_58 , V_91 ) ;
break;
case V_115 :
case V_116 :
case V_118 :
V_34 = F_106 ( V_3 , V_89 ,
V_76 , V_90 , V_58 , V_91 ) ;
break;
}
F_33 ( V_10 , L_39 ,
V_89 , V_34 , F_97 ( V_3 ) ) ;
return V_34 ;
}
static int F_110 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_33 ( V_10 , L_40 ) ;
F_105 ( V_3 , V_133 ) ;
F_105 ( V_3 , V_134 << 16 ) ;
V_3 -> V_12 . V_13 = NULL ;
F_111 ( V_8 , & V_3 -> V_12 ) ;
return 0 ;
}
static int F_112 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_33 ( V_10 , L_41 ) ;
F_101 ( V_3 , V_133 ) ;
F_105 ( V_3 , V_134 << 16 ) ;
V_3 -> V_12 . V_13 = F_110 ;
F_111 ( V_8 , & V_3 -> V_12 ) ;
F_78 ( V_8 ) ;
return 0 ;
}
static int F_113 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_33 ( V_10 , L_42 ) ;
F_114 ( & V_3 -> V_75 ) ;
return 0 ;
}
static int F_115 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_33 ( V_10 , L_43 ) ;
F_114 ( & V_3 -> V_75 ) ;
return 0 ;
}
static void F_116 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_27 * V_21 ;
T_3 * V_135 = F_117 ( V_8 , V_135 ) ;
int V_136 = F_117 ( V_8 , V_136 ) ;
int V_137 , V_33 , V_32 ;
V_137 = V_138 ;
for ( V_32 = 0 ; V_32 < V_136 ; V_32 ++ ) {
V_33 = ( V_135 [ V_32 ] == V_137 ) ;
V_137 = V_135 [ V_32 ] ;
if ( V_138 == V_135 [ V_32 ] ) {
V_21 = F_118 ( V_8 ) ;
F_119 ( V_3 ) = V_21 ;
} else {
V_21 = F_120 ( V_8 ,
V_135 [ V_32 ] ,
V_33 ) ;
}
V_21 -> V_139 = NULL ;
}
}
static int F_121 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_43 * V_44 = F_55 ( V_3 ) ;
struct V_140 * V_12 = F_122 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_34 ;
V_34 = F_123 ( V_44 , 0 , 0 ) ;
if ( V_34 < 0 )
return 0 ;
F_124 ( V_8 ,
F_88 ) ;
F_125 ( V_8 ) ;
F_116 ( V_8 ) ;
F_126 ( V_8 , 1 ) ;
V_12 -> V_13 = F_110 ;
V_12 -> V_141 = F_112 ;
V_12 -> V_142 = F_113 ;
V_12 -> V_143 = F_115 ;
F_111 ( V_8 , V_12 ) ;
F_33 ( V_10 , L_44 ) ;
return V_34 ;
}
static int F_127 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_43 * V_44 = F_55 ( V_3 ) ;
struct V_140 * V_12 = F_122 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
V_12 -> V_13 = NULL ;
V_12 -> V_141 = NULL ;
V_12 -> V_142 = NULL ;
V_12 -> V_143 = NULL ;
F_111 ( V_8 , V_12 ) ;
F_128 ( V_44 ) ;
F_126 ( V_8 , 0 ) ;
F_33 ( V_10 , L_45 ) ;
return 0 ;
}
int F_129 ( struct V_7 * V_8 )
{
struct V_2 * V_3 ;
struct V_43 * V_44 ;
struct V_25 * V_26 ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_32 ;
V_44 = F_130 ( & V_144 , V_10 , V_145 ) ;
if ( ! V_44 ) {
F_5 ( V_10 , L_46 ) ;
return - V_39 ;
}
V_44 -> V_146 = 1 ;
V_3 = F_71 ( V_44 ) ;
F_131 ( V_8 , & V_3 -> V_12 , V_147 ) ;
V_3 -> V_12 . V_148 = L_47 ;
V_3 -> V_12 . V_149 = F_121 ;
V_3 -> V_12 . V_150 = F_127 ;
F_132 ( V_3 ) ;
F_133 (udev, hpriv, i) {
V_26 -> V_46 = NULL ;
F_40 ( & V_26 -> V_41 ) ;
}
F_134 ( V_10 , L_48 ) ;
return 0 ;
}
int F_135 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_67 ( V_8 ) ;
struct V_43 * V_44 = F_55 ( V_3 ) ;
F_136 ( V_44 ) ;
return 0 ;
}
