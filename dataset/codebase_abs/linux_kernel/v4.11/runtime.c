static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_1 V_4 ;
const struct V_5 * V_6 ;
if ( V_2 -> V_7 )
V_6 = & V_2 -> V_7 -> V_6 ;
else if ( V_2 -> type && V_2 -> type -> V_8 )
V_6 = V_2 -> type -> V_8 ;
else if ( V_2 -> V_9 && V_2 -> V_9 -> V_8 )
V_6 = V_2 -> V_9 -> V_8 ;
else if ( V_2 -> V_10 && V_2 -> V_10 -> V_8 )
V_6 = V_2 -> V_10 -> V_8 ;
else
V_6 = NULL ;
if ( V_6 )
V_4 = * ( T_1 * ) ( ( void * ) V_6 + V_3 ) ;
else
V_4 = NULL ;
if ( ! V_4 && V_2 -> V_11 && V_2 -> V_11 -> V_8 )
V_4 = * ( T_1 * ) ( ( void * ) V_2 -> V_11 -> V_8 + V_3 ) ;
return V_4 ;
}
void F_2 ( struct V_1 * V_2 )
{
unsigned long V_12 = V_13 ;
unsigned long V_14 ;
V_14 = V_12 - V_2 -> V_15 . V_16 ;
V_2 -> V_15 . V_16 = V_12 ;
if ( V_2 -> V_15 . V_17 > 0 )
return;
if ( V_2 -> V_15 . V_18 == V_19 )
V_2 -> V_15 . V_20 += V_14 ;
else
V_2 -> V_15 . V_21 += V_14 ;
}
static void F_3 ( struct V_1 * V_2 , enum V_22 V_23 )
{
F_2 ( V_2 ) ;
V_2 -> V_15 . V_18 = V_23 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 . V_24 > 0 ) {
F_5 ( & V_2 -> V_15 . V_25 ) ;
V_2 -> V_15 . V_24 = 0 ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
V_2 -> V_15 . V_26 = V_27 ;
}
unsigned long F_7 ( struct V_1 * V_2 )
{
int V_28 ;
long V_29 ;
unsigned long V_30 ;
unsigned long V_31 = 0 ;
if ( ! V_2 -> V_15 . V_32 )
goto V_33;
V_28 = F_8 ( V_2 -> V_15 . V_28 ) ;
if ( V_28 < 0 )
goto V_33;
V_30 = F_8 ( V_2 -> V_15 . V_30 ) ;
V_29 = V_13 - V_30 ;
if ( V_29 < 0 )
goto V_33;
V_31 = V_30 + F_9 ( V_28 ) ;
if ( V_28 >= 1000 )
V_31 = F_10 ( V_31 ) ;
V_31 += ! V_31 ;
if ( V_29 >= V_31 - V_30 )
V_31 = 0 ;
V_33:
return V_31 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_34 )
{
return V_2 -> V_15 . V_35 ;
}
void F_12 ( struct V_1 * V_2 , bool V_36 )
{
static F_13 ( V_37 ) ;
F_14 ( & V_37 ) ;
for (; ; ) {
bool V_38 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_38 = V_2 -> V_15 . V_35 ;
V_2 -> V_15 . V_35 = V_36 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
if ( V_38 && V_36 )
break;
V_2 = V_2 -> V_40 ;
if ( ! V_2 || ( ! V_36 &&
F_17 ( V_2 , NULL ,
F_11 ) ) )
break;
}
F_18 ( & V_37 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
if ( V_2 -> V_15 . V_42 )
V_41 = - V_43 ;
else if ( V_2 -> V_15 . V_17 > 0 )
V_41 = - V_44 ;
else if ( F_20 ( & V_2 -> V_15 . V_45 ) > 0 )
V_41 = - V_46 ;
else if ( ! V_2 -> V_15 . V_47 &&
F_20 ( & V_2 -> V_15 . V_48 ) )
V_41 = - V_49 ;
else if ( ( V_2 -> V_15 . V_50
&& V_2 -> V_15 . V_18 == V_51 )
|| ( V_2 -> V_15 . V_52
&& V_2 -> V_15 . V_26 == V_53 ) )
V_41 = - V_46 ;
else if ( F_21 ( V_2 ) < 0 )
V_41 = - V_54 ;
else if ( V_2 -> V_15 . V_18 == V_19 )
V_41 = 1 ;
return V_41 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
F_23 (link, &dev->links.suppliers, c_node) {
int V_41 ;
if ( ! ( V_56 -> V_57 & V_58 ) )
continue;
if ( F_24 ( V_56 -> V_23 ) == V_59 ||
V_56 -> V_60 )
continue;
V_41 = F_25 ( V_56 -> V_61 ) ;
if ( V_41 < 0 ) {
F_26 ( V_56 -> V_61 ) ;
return V_41 ;
}
V_56 -> V_60 = true ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
F_23 (link, &dev->links.suppliers, c_node)
if ( V_56 -> V_60 &&
F_24 ( V_56 -> V_23 ) != V_59 ) {
F_28 ( V_56 -> V_61 ) ;
V_56 -> V_60 = false ;
}
}
static int F_29 ( int (* V_4)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_30 ( struct V_1 * V_2 , int V_62 )
{
int (* F_31)( struct V_1 * );
int V_41 ;
F_32 ( V_2 , V_62 ) ;
V_41 = F_19 ( V_2 ) ;
if ( V_41 < 0 )
;
else if ( V_2 -> V_15 . V_18 != V_63 )
V_41 = - V_46 ;
else if ( V_2 -> V_15 . V_52 &&
V_2 -> V_15 . V_26 > V_64 )
V_41 = - V_46 ;
else if ( V_2 -> V_15 . V_65 )
V_41 = - V_66 ;
if ( V_41 )
goto V_33;
V_2 -> V_15 . V_26 = V_27 ;
if ( V_2 -> V_15 . V_67 )
goto V_33;
if ( V_62 & V_68 ) {
V_2 -> V_15 . V_26 = V_64 ;
if ( ! V_2 -> V_15 . V_52 ) {
V_2 -> V_15 . V_52 = true ;
F_33 ( V_69 , & V_2 -> V_15 . V_70 ) ;
}
F_34 ( V_2 , V_71 , 0 ) ;
return 0 ;
}
V_2 -> V_15 . V_65 = true ;
F_31 = F_35 ( V_2 , V_72 ) ;
if ( F_31 )
V_41 = F_29 ( F_31 , V_2 ) ;
V_2 -> V_15 . V_65 = false ;
F_36 ( & V_2 -> V_15 . V_73 ) ;
V_33:
F_34 ( V_2 , V_71 , V_41 ) ;
return V_41 ? V_41 : F_37 ( V_2 , V_62 | V_74 ) ;
}
static int F_38 ( int (* V_4)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_41 ;
if ( ! V_4 )
return - V_75 ;
if ( V_2 -> V_15 . V_35 ) {
unsigned int V_76 ;
V_76 = F_39 () ;
V_41 = F_29 ( V_4 , V_2 ) ;
F_40 ( V_76 ) ;
} else {
V_41 = F_29 ( V_4 , V_2 ) ;
}
V_2 -> V_15 . V_42 = V_41 ;
return V_41 != - V_44 ? V_41 : - V_77 ;
}
static int F_37 ( struct V_1 * V_2 , int V_62 )
__releases( &dev->power.lock
static int F_41 ( struct V_1 * V_2 , int V_62 )
__releases( &dev->power.lock
static void F_42 ( struct V_78 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 , struct V_1 , V_15 . V_70 ) ;
enum V_79 V_80 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( ! V_2 -> V_15 . V_52 )
goto V_33;
V_80 = V_2 -> V_15 . V_26 ;
V_2 -> V_15 . V_26 = V_27 ;
V_2 -> V_15 . V_52 = false ;
switch ( V_80 ) {
case V_27 :
break;
case V_64 :
F_30 ( V_2 , V_81 ) ;
break;
case V_82 :
F_37 ( V_2 , V_81 ) ;
break;
case V_83 :
F_37 ( V_2 , V_81 | V_74 ) ;
break;
case V_53 :
F_41 ( V_2 , V_81 ) ;
break;
}
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
static void F_44 ( unsigned long V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned long V_57 ;
unsigned long V_31 ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
V_31 = V_2 -> V_15 . V_24 ;
if ( V_31 > 0 && ! F_46 ( V_31 , V_13 ) ) {
V_2 -> V_15 . V_24 = 0 ;
F_37 ( V_2 , V_2 -> V_15 . V_84 ?
( V_68 | V_74 ) : V_68 ) ;
}
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
}
int F_48 ( struct V_1 * V_2 , unsigned int V_85 )
{
unsigned long V_57 ;
int V_41 ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
if ( ! V_85 ) {
V_41 = F_37 ( V_2 , V_68 ) ;
goto V_33;
}
V_41 = F_19 ( V_2 ) ;
if ( V_41 )
goto V_33;
F_6 ( V_2 ) ;
V_2 -> V_15 . V_24 = V_13 + F_9 ( V_85 ) ;
V_2 -> V_15 . V_24 += ! V_2 -> V_15 . V_24 ;
V_2 -> V_15 . V_84 = 0 ;
F_49 ( & V_2 -> V_15 . V_25 , V_2 -> V_15 . V_24 ) ;
V_33:
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
return V_41 ;
}
int F_50 ( struct V_1 * V_2 , int V_62 )
{
unsigned long V_57 ;
int V_41 ;
if ( V_62 & V_86 ) {
if ( ! F_51 ( & V_2 -> V_15 . V_45 ) )
return 0 ;
}
F_52 ( ! ( V_62 & V_68 ) && ! V_2 -> V_15 . V_87 ) ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
V_41 = F_30 ( V_2 , V_62 ) ;
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
return V_41 ;
}
int F_53 ( struct V_1 * V_2 , int V_62 )
{
unsigned long V_57 ;
int V_41 ;
if ( V_62 & V_86 ) {
if ( ! F_51 ( & V_2 -> V_15 . V_45 ) )
return 0 ;
}
F_52 ( ! ( V_62 & V_68 ) && ! V_2 -> V_15 . V_87 ) ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
V_41 = F_37 ( V_2 , V_62 ) ;
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
return V_41 ;
}
int F_54 ( struct V_1 * V_2 , int V_62 )
{
unsigned long V_57 ;
int V_41 ;
F_52 ( ! ( V_62 & V_68 ) && ! V_2 -> V_15 . V_87 &&
V_2 -> V_15 . V_18 != V_63 ) ;
if ( V_62 & V_86 )
F_55 ( & V_2 -> V_15 . V_45 ) ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
V_41 = F_41 ( V_2 , V_62 ) ;
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
return V_41 ;
}
int F_56 ( struct V_1 * V_2 )
{
unsigned long V_57 ;
int V_41 ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
V_41 = V_2 -> V_15 . V_17 > 0 ? - V_43 :
V_2 -> V_15 . V_18 == V_63
&& F_57 ( & V_2 -> V_15 . V_45 ) ;
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
return V_41 ;
}
int F_58 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_1 * V_40 = V_2 -> V_40 ;
unsigned long V_57 ;
bool V_88 = false ;
int error = 0 ;
if ( V_23 != V_63 && V_23 != V_19 )
return - V_43 ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
if ( ! V_2 -> V_15 . V_42 && ! V_2 -> V_15 . V_17 ) {
error = - V_46 ;
goto V_33;
}
if ( V_2 -> V_15 . V_18 == V_23 )
goto V_89;
if ( V_23 == V_19 ) {
if ( ! V_2 -> V_15 . V_47 &&
F_20 ( & V_2 -> V_15 . V_48 ) ) {
F_59 ( V_2 , L_1 ) ;
error = - V_49 ;
goto V_33;
}
if ( V_40 ) {
F_60 ( & V_40 -> V_15 . V_48 , - 1 , 0 ) ;
V_88 = ! V_40 -> V_15 . V_47 ;
}
goto V_89;
}
if ( V_40 ) {
F_61 ( & V_40 -> V_15 . V_39 , V_90 ) ;
if ( ! V_40 -> V_15 . V_17
&& ! V_40 -> V_15 . V_47
&& V_40 -> V_15 . V_18 != V_63 ) {
F_59 ( V_2 , L_2 ,
F_62 ( V_2 ) ,
F_62 ( V_40 ) ) ;
error = - V_49 ;
} else if ( V_2 -> V_15 . V_18 == V_19 ) {
F_55 ( & V_40 -> V_15 . V_48 ) ;
}
F_63 ( & V_40 -> V_15 . V_39 ) ;
if ( error )
goto V_33;
}
V_89:
F_3 ( V_2 , V_23 ) ;
V_2 -> V_15 . V_42 = 0 ;
V_33:
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
if ( V_88 )
F_64 ( V_40 ) ;
return error ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_15 . V_52 ) {
V_2 -> V_15 . V_26 = V_27 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_66 ( & V_2 -> V_15 . V_70 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_52 = false ;
}
if ( V_2 -> V_15 . V_18 == V_51
|| V_2 -> V_15 . V_18 == V_91
|| V_2 -> V_15 . V_65 ) {
F_67 ( V_92 ) ;
for (; ; ) {
F_68 ( & V_2 -> V_15 . V_73 , & V_92 ,
V_93 ) ;
if ( V_2 -> V_15 . V_18 != V_51
&& V_2 -> V_15 . V_18 != V_91
&& ! V_2 -> V_15 . V_65 )
break;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_69 () ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
}
F_70 ( & V_2 -> V_15 . V_73 , & V_92 ) ;
}
}
int F_71 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
F_72 ( V_2 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_52
&& V_2 -> V_15 . V_26 == V_53 ) {
F_41 ( V_2 , 0 ) ;
V_41 = 1 ;
}
F_65 ( V_2 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_26 ( V_2 ) ;
return V_41 ;
}
void F_73 ( struct V_1 * V_2 , bool V_94 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_17 > 0 ) {
V_2 -> V_15 . V_17 ++ ;
goto V_33;
}
if ( V_94 && V_2 -> V_15 . V_52
&& V_2 -> V_15 . V_26 == V_53 ) {
F_72 ( V_2 ) ;
F_41 ( V_2 , 0 ) ;
F_26 ( V_2 ) ;
}
if ( ! V_2 -> V_15 . V_17 ++ )
F_65 ( V_2 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
unsigned long V_57 ;
F_45 ( & V_2 -> V_15 . V_39 , V_57 ) ;
if ( V_2 -> V_15 . V_17 > 0 )
V_2 -> V_15 . V_17 -- ;
else
F_75 ( V_2 , L_3 , V_95 ) ;
F_47 ( & V_2 -> V_15 . V_39 , V_57 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( ! V_2 -> V_15 . V_96 )
goto V_33;
V_2 -> V_15 . V_96 = false ;
F_55 ( & V_2 -> V_15 . V_45 ) ;
F_41 ( V_2 , 0 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_96 )
goto V_33;
V_2 -> V_15 . V_96 = true ;
if ( F_51 ( & V_2 -> V_15 . V_45 ) )
F_30 ( V_2 , V_74 | V_68 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_67 = 1 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
if ( F_79 ( V_2 ) )
F_80 ( V_2 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 )
F_25 ( V_2 -> V_40 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_87 = 1 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
static void F_82 ( struct V_1 * V_2 , int V_97 , int V_98 )
{
int V_85 = V_2 -> V_15 . V_28 ;
if ( V_2 -> V_15 . V_32 && V_85 < 0 ) {
if ( ! V_98 || V_97 >= 0 ) {
F_55 ( & V_2 -> V_15 . V_45 ) ;
F_41 ( V_2 , 0 ) ;
}
}
else {
if ( V_98 && V_97 < 0 )
F_83 ( & V_2 -> V_15 . V_45 ) ;
F_30 ( V_2 , V_74 ) ;
}
}
void F_84 ( struct V_1 * V_2 , int V_85 )
{
int V_97 , V_98 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_97 = V_2 -> V_15 . V_28 ;
V_98 = V_2 -> V_15 . V_32 ;
V_2 -> V_15 . V_28 = V_85 ;
F_82 ( V_2 , V_97 , V_98 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_85 ( struct V_1 * V_2 , bool V_99 )
{
int V_97 , V_98 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_97 = V_2 -> V_15 . V_28 ;
V_98 = V_2 -> V_15 . V_32 ;
V_2 -> V_15 . V_32 = V_99 ;
F_82 ( V_2 , V_97 , V_98 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_18 = V_19 ;
V_2 -> V_15 . V_65 = false ;
V_2 -> V_15 . V_17 = 1 ;
F_87 ( & V_2 -> V_15 . V_45 , 0 ) ;
V_2 -> V_15 . V_42 = 0 ;
F_87 ( & V_2 -> V_15 . V_48 , 0 ) ;
F_88 ( V_2 , false ) ;
V_2 -> V_15 . V_96 = true ;
V_2 -> V_15 . V_52 = false ;
V_2 -> V_15 . V_26 = V_27 ;
V_2 -> V_15 . V_50 = false ;
V_2 -> V_15 . V_16 = V_13 ;
F_89 ( & V_2 -> V_15 . V_70 , F_42 ) ;
V_2 -> V_15 . V_24 = 0 ;
F_90 ( & V_2 -> V_15 . V_25 , F_44 ,
( unsigned long ) V_2 ) ;
F_91 ( & V_2 -> V_15 . V_73 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
if ( ! F_93 ( V_2 ) ) {
if ( V_2 -> V_15 . V_18 == V_63 )
F_94 ( V_2 ) ;
if ( V_2 -> V_15 . V_87 ) {
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_87 = 0 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_40 )
F_28 ( V_2 -> V_40 ) ;
}
}
}
void F_95 ( struct V_1 * V_2 )
{
F_73 ( V_2 , false ) ;
F_92 ( V_2 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
int V_100 ;
V_100 = F_97 () ;
F_23 (link, &dev->links.consumers, s_node) {
if ( V_56 -> V_57 & V_101 )
continue;
if ( V_56 -> V_60 ) {
F_26 ( V_2 ) ;
V_56 -> V_60 = false ;
}
}
F_98 ( V_100 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
int V_100 ;
V_100 = F_97 () ;
F_23 (link, &dev->links.suppliers, c_node)
if ( V_56 -> V_57 & V_58 )
F_25 ( V_56 -> V_61 ) ;
F_98 ( V_100 ) ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
int V_100 ;
V_100 = F_97 () ;
F_23 (link, &dev->links.suppliers, c_node)
if ( V_56 -> V_57 & V_58 )
F_28 ( V_56 -> V_61 ) ;
F_98 ( V_100 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_102 ++ ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
F_103 ( V_2 -> V_15 . V_102 == 0 ) ;
V_2 -> V_15 . V_102 -- ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
int F_104 ( struct V_1 * V_2 )
{
int (* F_31)( struct V_1 * );
int V_103 = 0 ;
F_105 ( V_2 ) ;
if ( F_106 ( V_2 ) )
return 0 ;
F_31 = F_35 ( V_2 , V_104 ) ;
if ( ! F_31 ) {
V_103 = - V_75 ;
goto V_105;
}
V_103 = F_31 ( V_2 ) ;
if ( V_103 )
goto V_105;
if ( V_2 -> V_40 && F_20 ( & V_2 -> V_15 . V_45 ) > 1 )
F_72 ( V_2 -> V_40 ) ;
F_94 ( V_2 ) ;
return 0 ;
V_105:
F_74 ( V_2 ) ;
return V_103 ;
}
int F_107 ( struct V_1 * V_2 )
{
int (* F_31)( struct V_1 * );
int V_103 = 0 ;
F_31 = F_35 ( V_2 , V_106 ) ;
if ( ! F_31 ) {
V_103 = - V_75 ;
goto V_33;
}
if ( ! F_106 ( V_2 ) )
goto V_33;
if ( F_20 ( & V_2 -> V_15 . V_45 ) > 1 ) {
if ( V_2 -> V_40 )
F_26 ( V_2 -> V_40 ) ;
} else {
goto V_33;
}
V_103 = F_108 ( V_2 ) ;
if ( V_103 )
goto V_33;
V_103 = F_31 ( V_2 ) ;
if ( V_103 ) {
F_94 ( V_2 ) ;
goto V_33;
}
F_109 ( V_2 ) ;
V_33:
F_74 ( V_2 ) ;
return V_103 ;
}
