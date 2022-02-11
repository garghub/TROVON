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
else if ( ! F_21 ( V_2 ) )
V_41 = - V_47 ;
else if ( ( V_2 -> V_15 . V_48
&& V_2 -> V_15 . V_18 == V_49 )
|| ( V_2 -> V_15 . V_50
&& V_2 -> V_15 . V_26 == V_51 ) )
V_41 = - V_46 ;
else if ( F_22 ( V_2 ) < 0 )
V_41 = - V_52 ;
else if ( V_2 -> V_15 . V_18 == V_19 )
V_41 = 1 ;
return V_41 ;
}
static int F_23 ( int (* V_4)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_24 ( struct V_1 * V_2 , int V_53 )
{
int (* F_25)( struct V_1 * );
int V_41 ;
F_26 ( V_2 , V_53 ) ;
V_41 = F_19 ( V_2 ) ;
if ( V_41 < 0 )
;
else if ( V_2 -> V_15 . V_18 != V_54 )
V_41 = - V_46 ;
else if ( V_2 -> V_15 . V_50 &&
V_2 -> V_15 . V_26 > V_55 )
V_41 = - V_46 ;
else if ( V_2 -> V_15 . V_56 )
V_41 = - V_57 ;
if ( V_41 )
goto V_33;
V_2 -> V_15 . V_26 = V_27 ;
if ( V_2 -> V_15 . V_58 )
goto V_33;
if ( V_53 & V_59 ) {
V_2 -> V_15 . V_26 = V_55 ;
if ( ! V_2 -> V_15 . V_50 ) {
V_2 -> V_15 . V_50 = true ;
F_27 ( V_60 , & V_2 -> V_15 . V_61 ) ;
}
F_28 ( V_2 , V_62 , 0 ) ;
return 0 ;
}
V_2 -> V_15 . V_56 = true ;
F_25 = F_29 ( V_2 , V_63 ) ;
if ( F_25 )
V_41 = F_23 ( F_25 , V_2 ) ;
V_2 -> V_15 . V_56 = false ;
F_30 ( & V_2 -> V_15 . V_64 ) ;
V_33:
F_28 ( V_2 , V_62 , V_41 ) ;
return V_41 ? V_41 : F_31 ( V_2 , V_53 | V_65 ) ;
}
static int F_32 ( int (* V_4)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_41 ;
if ( ! V_4 )
return - V_66 ;
if ( V_2 -> V_15 . V_35 ) {
unsigned int V_67 ;
V_67 = F_33 () ;
V_41 = F_23 ( V_4 , V_2 ) ;
F_34 ( V_67 ) ;
} else {
V_41 = F_23 ( V_4 , V_2 ) ;
}
V_2 -> V_15 . V_42 = V_41 ;
return V_41 != - V_44 ? V_41 : - V_68 ;
}
static int F_31 ( struct V_1 * V_2 , int V_53 )
__releases( &dev->power.lock
static int F_35 ( struct V_1 * V_2 , int V_53 )
__releases( &dev->power.lock
static void F_36 ( struct V_69 * V_61 )
{
struct V_1 * V_2 = F_37 ( V_61 , struct V_1 , V_15 . V_61 ) ;
enum V_70 V_71 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( ! V_2 -> V_15 . V_50 )
goto V_33;
V_71 = V_2 -> V_15 . V_26 ;
V_2 -> V_15 . V_26 = V_27 ;
V_2 -> V_15 . V_50 = false ;
switch ( V_71 ) {
case V_27 :
break;
case V_55 :
F_24 ( V_2 , V_72 ) ;
break;
case V_73 :
F_31 ( V_2 , V_72 ) ;
break;
case V_74 :
F_31 ( V_2 , V_72 | V_65 ) ;
break;
case V_51 :
F_35 ( V_2 , V_72 ) ;
break;
}
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
static void F_38 ( unsigned long V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_34 ;
unsigned long V_75 ;
unsigned long V_31 ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
V_31 = V_2 -> V_15 . V_24 ;
if ( V_31 > 0 && ! F_40 ( V_31 , V_13 ) ) {
V_2 -> V_15 . V_24 = 0 ;
F_31 ( V_2 , V_2 -> V_15 . V_76 ?
( V_59 | V_65 ) : V_59 ) ;
}
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
}
int F_42 ( struct V_1 * V_2 , unsigned int V_77 )
{
unsigned long V_75 ;
int V_41 ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
if ( ! V_77 ) {
V_41 = F_31 ( V_2 , V_59 ) ;
goto V_33;
}
V_41 = F_19 ( V_2 ) ;
if ( V_41 )
goto V_33;
F_6 ( V_2 ) ;
V_2 -> V_15 . V_24 = V_13 + F_9 ( V_77 ) ;
V_2 -> V_15 . V_24 += ! V_2 -> V_15 . V_24 ;
V_2 -> V_15 . V_76 = 0 ;
F_43 ( & V_2 -> V_15 . V_25 , V_2 -> V_15 . V_24 ) ;
V_33:
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
return V_41 ;
}
int F_44 ( struct V_1 * V_2 , int V_53 )
{
unsigned long V_75 ;
int V_41 ;
F_45 ( ! ( V_53 & V_59 ) && ! V_2 -> V_15 . V_78 ) ;
if ( V_53 & V_79 ) {
if ( ! F_46 ( & V_2 -> V_15 . V_45 ) )
return 0 ;
}
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
V_41 = F_24 ( V_2 , V_53 ) ;
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
return V_41 ;
}
int F_47 ( struct V_1 * V_2 , int V_53 )
{
unsigned long V_75 ;
int V_41 ;
F_45 ( ! ( V_53 & V_59 ) && ! V_2 -> V_15 . V_78 ) ;
if ( V_53 & V_79 ) {
if ( ! F_46 ( & V_2 -> V_15 . V_45 ) )
return 0 ;
}
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
V_41 = F_31 ( V_2 , V_53 ) ;
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
return V_41 ;
}
int F_48 ( struct V_1 * V_2 , int V_53 )
{
unsigned long V_75 ;
int V_41 ;
F_45 ( ! ( V_53 & V_59 ) && ! V_2 -> V_15 . V_78 ) ;
if ( V_53 & V_79 )
F_49 ( & V_2 -> V_15 . V_45 ) ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
V_41 = F_35 ( V_2 , V_53 ) ;
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
return V_41 ;
}
int F_50 ( struct V_1 * V_2 )
{
unsigned long V_75 ;
int V_41 ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
V_41 = V_2 -> V_15 . V_17 > 0 ? - V_43 :
V_2 -> V_15 . V_18 == V_54
&& F_51 ( & V_2 -> V_15 . V_45 ) ;
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
return V_41 ;
}
int F_52 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_1 * V_40 = V_2 -> V_40 ;
unsigned long V_75 ;
bool V_80 = false ;
int error = 0 ;
if ( V_23 != V_54 && V_23 != V_19 )
return - V_43 ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
if ( ! V_2 -> V_15 . V_42 && ! V_2 -> V_15 . V_17 ) {
error = - V_46 ;
goto V_33;
}
if ( V_2 -> V_15 . V_18 == V_23 )
goto V_81;
if ( V_23 == V_19 ) {
if ( V_40 ) {
F_53 ( & V_40 -> V_15 . V_82 , - 1 , 0 ) ;
V_80 = ! V_40 -> V_15 . V_83 ;
}
goto V_81;
}
if ( V_40 ) {
F_54 ( & V_40 -> V_15 . V_39 , V_84 ) ;
if ( ! V_40 -> V_15 . V_17
&& ! V_40 -> V_15 . V_83
&& V_40 -> V_15 . V_18 != V_54 )
error = - V_47 ;
else if ( V_2 -> V_15 . V_18 == V_19 )
F_49 ( & V_40 -> V_15 . V_82 ) ;
F_55 ( & V_40 -> V_15 . V_39 ) ;
if ( error )
goto V_33;
}
V_81:
F_3 ( V_2 , V_23 ) ;
V_2 -> V_15 . V_42 = 0 ;
V_33:
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
if ( V_80 )
F_56 ( V_40 ) ;
return error ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
if ( V_2 -> V_15 . V_50 ) {
V_2 -> V_15 . V_26 = V_27 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_58 ( & V_2 -> V_15 . V_61 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_50 = false ;
}
if ( V_2 -> V_15 . V_18 == V_49
|| V_2 -> V_15 . V_18 == V_85
|| V_2 -> V_15 . V_56 ) {
F_59 ( V_86 ) ;
for (; ; ) {
F_60 ( & V_2 -> V_15 . V_64 , & V_86 ,
V_87 ) ;
if ( V_2 -> V_15 . V_18 != V_49
&& V_2 -> V_15 . V_18 != V_85
&& ! V_2 -> V_15 . V_56 )
break;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_61 () ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
}
F_62 ( & V_2 -> V_15 . V_64 , & V_86 ) ;
}
}
int F_63 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
F_64 ( V_2 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_50
&& V_2 -> V_15 . V_26 == V_51 ) {
F_35 ( V_2 , 0 ) ;
V_41 = 1 ;
}
F_57 ( V_2 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
F_65 ( V_2 ) ;
return V_41 ;
}
void F_66 ( struct V_1 * V_2 , bool V_88 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_17 > 0 ) {
V_2 -> V_15 . V_17 ++ ;
goto V_33;
}
if ( V_88 && V_2 -> V_15 . V_50
&& V_2 -> V_15 . V_26 == V_51 ) {
F_64 ( V_2 ) ;
F_35 ( V_2 , 0 ) ;
F_65 ( V_2 ) ;
}
if ( ! V_2 -> V_15 . V_17 ++ )
F_57 ( V_2 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
unsigned long V_75 ;
F_39 ( & V_2 -> V_15 . V_39 , V_75 ) ;
if ( V_2 -> V_15 . V_17 > 0 )
V_2 -> V_15 . V_17 -- ;
else
F_68 ( V_2 , L_1 , V_89 ) ;
F_41 ( & V_2 -> V_15 . V_39 , V_75 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( ! V_2 -> V_15 . V_90 )
goto V_33;
V_2 -> V_15 . V_90 = false ;
F_49 ( & V_2 -> V_15 . V_45 ) ;
F_35 ( V_2 , 0 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_15 . V_90 )
goto V_33;
V_2 -> V_15 . V_90 = true ;
if ( F_46 ( & V_2 -> V_15 . V_45 ) )
F_24 ( V_2 , V_65 ) ;
V_33:
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_58 = 1 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
if ( F_72 ( V_2 ) )
F_73 ( V_2 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 )
F_75 ( V_2 -> V_40 ) ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_78 = 1 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
static void F_76 ( struct V_1 * V_2 , int V_91 , int V_92 )
{
int V_77 = V_2 -> V_15 . V_28 ;
if ( V_2 -> V_15 . V_32 && V_77 < 0 ) {
if ( ! V_92 || V_91 >= 0 ) {
F_49 ( & V_2 -> V_15 . V_45 ) ;
F_35 ( V_2 , 0 ) ;
}
}
else {
if ( V_92 && V_91 < 0 )
F_77 ( & V_2 -> V_15 . V_45 ) ;
F_24 ( V_2 , V_65 ) ;
}
}
void F_78 ( struct V_1 * V_2 , int V_77 )
{
int V_91 , V_92 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_91 = V_2 -> V_15 . V_28 ;
V_92 = V_2 -> V_15 . V_32 ;
V_2 -> V_15 . V_28 = V_77 ;
F_76 ( V_2 , V_91 , V_92 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_79 ( struct V_1 * V_2 , bool V_93 )
{
int V_91 , V_92 ;
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_91 = V_2 -> V_15 . V_28 ;
V_92 = V_2 -> V_15 . V_32 ;
V_2 -> V_15 . V_32 = V_93 ;
F_76 ( V_2 , V_91 , V_92 ) ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
V_2 -> V_15 . V_18 = V_19 ;
V_2 -> V_15 . V_56 = false ;
V_2 -> V_15 . V_17 = 1 ;
F_81 ( & V_2 -> V_15 . V_45 , 0 ) ;
V_2 -> V_15 . V_42 = 0 ;
F_81 ( & V_2 -> V_15 . V_82 , 0 ) ;
F_82 ( V_2 , false ) ;
V_2 -> V_15 . V_90 = true ;
V_2 -> V_15 . V_50 = false ;
V_2 -> V_15 . V_26 = V_27 ;
V_2 -> V_15 . V_48 = false ;
V_2 -> V_15 . V_16 = V_13 ;
F_83 ( & V_2 -> V_15 . V_61 , F_36 ) ;
V_2 -> V_15 . V_24 = 0 ;
F_84 ( & V_2 -> V_15 . V_25 , F_38 ,
( unsigned long ) V_2 ) ;
F_85 ( & V_2 -> V_15 . V_64 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
if ( ! F_87 ( V_2 ) ) {
if ( V_2 -> V_15 . V_18 == V_54 )
F_88 ( V_2 ) ;
if ( V_2 -> V_15 . V_78 ) {
F_15 ( & V_2 -> V_15 . V_39 ) ;
V_2 -> V_15 . V_78 = 0 ;
F_16 ( & V_2 -> V_15 . V_39 ) ;
if ( V_2 -> V_40 )
F_89 ( V_2 -> V_40 ) ;
}
}
}
void F_90 ( struct V_1 * V_2 )
{
F_66 ( V_2 , false ) ;
F_86 ( V_2 ) ;
}
int F_91 ( struct V_1 * V_2 )
{
int (* F_25)( struct V_1 * );
int V_94 = 0 ;
F_92 ( V_2 ) ;
if ( F_93 ( V_2 ) )
return 0 ;
F_25 = F_29 ( V_2 , V_95 ) ;
if ( ! F_25 ) {
V_94 = - V_66 ;
goto V_96;
}
V_94 = F_25 ( V_2 ) ;
if ( V_94 )
goto V_96;
F_88 ( V_2 ) ;
return 0 ;
V_96:
F_67 ( V_2 ) ;
return V_94 ;
}
int F_94 ( struct V_1 * V_2 )
{
int (* F_25)( struct V_1 * );
int V_94 = 0 ;
F_25 = F_29 ( V_2 , V_97 ) ;
if ( ! F_25 ) {
V_94 = - V_66 ;
goto V_33;
}
V_94 = F_25 ( V_2 ) ;
if ( V_94 )
goto V_33;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
V_33:
F_67 ( V_2 ) ;
return V_94 ;
}
