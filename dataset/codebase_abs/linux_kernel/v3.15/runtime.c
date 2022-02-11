void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
unsigned long V_5 ;
V_5 = V_3 - V_2 -> V_6 . V_7 ;
V_2 -> V_6 . V_7 = V_3 ;
if ( V_2 -> V_6 . V_8 > 0 )
return;
if ( V_2 -> V_6 . V_9 == V_10 )
V_2 -> V_6 . V_11 += V_5 ;
else
V_2 -> V_6 . V_12 += V_5 ;
}
static void F_2 ( struct V_1 * V_2 , enum V_13 V_14 )
{
F_1 ( V_2 ) ;
V_2 -> V_6 . V_9 = V_14 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_15 > 0 ) {
F_4 ( & V_2 -> V_6 . V_16 ) ;
V_2 -> V_6 . V_15 = 0 ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
V_2 -> V_6 . V_17 = V_18 ;
}
unsigned long F_6 ( struct V_1 * V_2 )
{
int V_19 ;
long V_20 ;
unsigned long V_21 ;
unsigned long V_22 = 0 ;
if ( ! V_2 -> V_6 . V_23 )
goto V_24;
V_19 = F_7 ( V_2 -> V_6 . V_19 ) ;
if ( V_19 < 0 )
goto V_24;
V_21 = F_7 ( V_2 -> V_6 . V_21 ) ;
V_20 = V_4 - V_21 ;
if ( V_20 < 0 )
goto V_24;
V_22 = V_21 + F_8 ( V_19 ) ;
if ( V_19 >= 1000 )
V_22 = F_9 ( V_22 ) ;
V_22 += ! V_22 ;
if ( V_20 >= V_22 - V_21 )
V_22 = 0 ;
V_24:
return V_22 ;
}
static int F_10 ( struct V_1 * V_2 , void * V_25 )
{
return V_2 -> V_6 . V_26 ;
}
void F_11 ( struct V_1 * V_2 , bool V_27 )
{
static F_12 ( V_28 ) ;
F_13 ( & V_28 ) ;
for (; ; ) {
bool V_29 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_29 = V_2 -> V_6 . V_26 ;
V_2 -> V_6 . V_26 = V_27 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
if ( V_29 && V_27 )
break;
V_2 = V_2 -> V_31 ;
if ( ! V_2 || ( ! V_27 &&
F_16 ( V_2 , NULL ,
F_10 ) ) )
break;
}
F_17 ( & V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
if ( V_2 -> V_6 . V_33 )
V_32 = - V_34 ;
else if ( V_2 -> V_6 . V_8 > 0 )
V_32 = - V_35 ;
else if ( F_19 ( & V_2 -> V_6 . V_36 ) > 0 )
V_32 = - V_37 ;
else if ( ! F_20 ( V_2 ) )
V_32 = - V_38 ;
else if ( ( V_2 -> V_6 . V_39
&& V_2 -> V_6 . V_9 == V_40 )
|| ( V_2 -> V_6 . V_41
&& V_2 -> V_6 . V_17 == V_42 ) )
V_32 = - V_37 ;
else if ( F_21 ( V_2 ) < 0 )
V_32 = - V_43 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
V_32 = 1 ;
return V_32 ;
}
static int F_22 ( int (* F_23)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_24 ( struct V_1 * V_2 , int V_44 )
{
int (* F_25)( struct V_1 * );
int V_32 ;
F_26 ( V_2 , V_44 ) ;
V_32 = F_18 ( V_2 ) ;
if ( V_32 < 0 )
;
else if ( V_2 -> V_6 . V_9 != V_45 )
V_32 = - V_37 ;
else if ( V_2 -> V_6 . V_41 &&
V_2 -> V_6 . V_17 > V_46 )
V_32 = - V_37 ;
else if ( V_2 -> V_6 . V_47 )
V_32 = - V_48 ;
if ( V_32 )
goto V_24;
V_2 -> V_6 . V_17 = V_18 ;
if ( V_2 -> V_6 . V_49 )
goto V_24;
if ( V_44 & V_50 ) {
V_2 -> V_6 . V_17 = V_46 ;
if ( ! V_2 -> V_6 . V_41 ) {
V_2 -> V_6 . V_41 = true ;
F_27 ( V_51 , & V_2 -> V_6 . V_52 ) ;
}
F_28 ( V_2 , V_53 , 0 ) ;
return 0 ;
}
V_2 -> V_6 . V_47 = true ;
F_25 = F_29 ( V_2 ) ;
if ( F_25 )
V_32 = F_22 ( F_25 , V_2 ) ;
V_2 -> V_6 . V_47 = false ;
F_30 ( & V_2 -> V_6 . V_54 ) ;
V_24:
F_28 ( V_2 , V_53 , V_32 ) ;
return V_32 ? V_32 : F_31 ( V_2 , V_44 | V_55 ) ;
}
static int F_32 ( int (* F_23)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_23 )
return - V_56 ;
if ( V_2 -> V_6 . V_26 ) {
unsigned int V_57 ;
V_57 = F_33 () ;
V_32 = F_22 ( F_23 , V_2 ) ;
F_34 ( V_57 ) ;
} else {
V_32 = F_22 ( F_23 , V_2 ) ;
}
V_2 -> V_6 . V_33 = V_32 ;
return V_32 != - V_35 ? V_32 : - V_58 ;
}
static int F_31 ( struct V_1 * V_2 , int V_44 )
__releases( &dev->power.lock
static int F_35 ( struct V_1 * V_2 , int V_44 )
__releases( &dev->power.lock
static void F_36 ( struct V_59 * V_52 )
{
struct V_1 * V_2 = F_37 ( V_52 , struct V_1 , V_6 . V_52 ) ;
enum V_60 V_61 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( ! V_2 -> V_6 . V_41 )
goto V_24;
V_61 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_41 = false ;
switch ( V_61 ) {
case V_18 :
break;
case V_46 :
F_24 ( V_2 , V_62 ) ;
break;
case V_63 :
F_31 ( V_2 , V_62 ) ;
break;
case V_64 :
F_31 ( V_2 , V_62 | V_55 ) ;
break;
case V_42 :
F_35 ( V_2 , V_62 ) ;
break;
}
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
static void F_38 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned long V_65 ;
unsigned long V_22 ;
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_40 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_31 ( V_2 , V_2 -> V_6 . V_66 ?
( V_50 | V_55 ) : V_50 ) ;
}
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
}
int F_42 ( struct V_1 * V_2 , unsigned int V_67 )
{
unsigned long V_65 ;
int V_32 ;
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
if ( ! V_67 ) {
V_32 = F_31 ( V_2 , V_50 ) ;
goto V_24;
}
V_32 = F_18 ( V_2 ) ;
if ( V_32 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_67 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_66 = 0 ;
F_43 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
return V_32 ;
}
int F_44 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_65 ;
int V_32 ;
F_45 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_44 & V_69 ) {
if ( ! F_46 ( & V_2 -> V_6 . V_36 ) )
return 0 ;
}
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
V_32 = F_24 ( V_2 , V_44 ) ;
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
return V_32 ;
}
int F_47 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_65 ;
int V_32 ;
F_45 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_44 & V_69 ) {
if ( ! F_46 ( & V_2 -> V_6 . V_36 ) )
return 0 ;
}
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
V_32 = F_31 ( V_2 , V_44 ) ;
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
return V_32 ;
}
int F_48 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_65 ;
int V_32 ;
F_45 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_44 & V_69 )
F_49 ( & V_2 -> V_6 . V_36 ) ;
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
V_32 = F_35 ( V_2 , V_44 ) ;
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
return V_32 ;
}
int F_50 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_31 = V_2 -> V_31 ;
unsigned long V_65 ;
bool V_70 = false ;
int error = 0 ;
if ( V_14 != V_45 && V_14 != V_10 )
return - V_34 ;
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
if ( ! V_2 -> V_6 . V_33 && ! V_2 -> V_6 . V_8 ) {
error = - V_37 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_71;
if ( V_14 == V_10 ) {
if ( V_31 ) {
F_51 ( & V_31 -> V_6 . V_72 , - 1 , 0 ) ;
V_70 = ! V_31 -> V_6 . V_73 ;
}
goto V_71;
}
if ( V_31 ) {
F_52 ( & V_31 -> V_6 . V_30 , V_74 ) ;
if ( ! V_31 -> V_6 . V_8
&& ! V_31 -> V_6 . V_73
&& V_31 -> V_6 . V_9 != V_45 )
error = - V_38 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_49 ( & V_31 -> V_6 . V_72 ) ;
F_53 ( & V_31 -> V_6 . V_30 ) ;
if ( error )
goto V_24;
}
V_71:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_33 = 0 ;
V_24:
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
if ( V_70 )
F_54 ( V_31 ) ;
return error ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_41 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_56 ( & V_2 -> V_6 . V_52 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_41 = false ;
}
if ( V_2 -> V_6 . V_9 == V_40
|| V_2 -> V_6 . V_9 == V_75
|| V_2 -> V_6 . V_47 ) {
F_57 ( V_76 ) ;
for (; ; ) {
F_58 ( & V_2 -> V_6 . V_54 , & V_76 ,
V_77 ) ;
if ( V_2 -> V_6 . V_9 != V_40
&& V_2 -> V_6 . V_9 != V_75
&& ! V_2 -> V_6 . V_47 )
break;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_59 () ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
}
F_60 ( & V_2 -> V_6 . V_54 , & V_76 ) ;
}
}
int F_61 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
F_62 ( V_2 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_41
&& V_2 -> V_6 . V_17 == V_42 ) {
F_35 ( V_2 , 0 ) ;
V_32 = 1 ;
}
F_55 ( V_2 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_63 ( V_2 ) ;
return V_32 ;
}
void F_64 ( struct V_1 * V_2 , bool V_78 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_78 && V_2 -> V_6 . V_41
&& V_2 -> V_6 . V_17 == V_42 ) {
F_62 ( V_2 ) ;
F_35 ( V_2 , 0 ) ;
F_63 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_55 ( V_2 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_39 ( & V_2 -> V_6 . V_30 , V_65 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_66 ( V_2 , L_1 , V_79 ) ;
F_41 ( & V_2 -> V_6 . V_30 , V_65 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( ! V_2 -> V_6 . V_80 )
goto V_24;
V_2 -> V_6 . V_80 = false ;
F_49 ( & V_2 -> V_6 . V_36 ) ;
F_35 ( V_2 , 0 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_80 )
goto V_24;
V_2 -> V_6 . V_80 = true ;
if ( F_46 ( & V_2 -> V_6 . V_36 ) )
F_24 ( V_2 , V_55 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_49 = 1 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
if ( F_70 ( V_2 ) )
F_71 ( V_2 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
F_73 ( V_2 -> V_31 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_68 = 1 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
static void F_74 ( struct V_1 * V_2 , int V_81 , int V_82 )
{
int V_67 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_67 < 0 ) {
if ( ! V_82 || V_81 >= 0 ) {
F_49 ( & V_2 -> V_6 . V_36 ) ;
F_35 ( V_2 , 0 ) ;
}
}
else {
if ( V_82 && V_81 < 0 )
F_75 ( & V_2 -> V_6 . V_36 ) ;
F_24 ( V_2 , V_55 ) ;
}
}
void F_76 ( struct V_1 * V_2 , int V_67 )
{
int V_81 , V_82 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_81 = V_2 -> V_6 . V_19 ;
V_82 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_67 ;
F_74 ( V_2 , V_81 , V_82 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_77 ( struct V_1 * V_2 , bool V_83 )
{
int V_81 , V_82 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_81 = V_2 -> V_6 . V_19 ;
V_82 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_83 ;
F_74 ( V_2 , V_81 , V_82 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_47 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_79 ( & V_2 -> V_6 . V_36 , 0 ) ;
V_2 -> V_6 . V_33 = 0 ;
F_79 ( & V_2 -> V_6 . V_72 , 0 ) ;
F_80 ( V_2 , false ) ;
V_2 -> V_6 . V_80 = true ;
V_2 -> V_6 . V_41 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_39 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_81 ( & V_2 -> V_6 . V_52 , F_36 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_82 ( & V_2 -> V_6 . V_16 , F_38 ,
( unsigned long ) V_2 ) ;
F_83 ( & V_2 -> V_6 . V_54 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
F_64 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_45 )
F_85 ( V_2 ) ;
if ( V_2 -> V_6 . V_68 && V_2 -> V_31 )
F_86 ( V_2 -> V_31 ) ;
}
int F_87 ( struct V_1 * V_2 )
{
int (* F_25)( struct V_1 * );
int V_84 = 0 ;
F_88 ( V_2 ) ;
if ( F_89 ( V_2 ) )
return 0 ;
F_25 = F_90 ( V_2 ) ;
if ( ! F_25 ) {
V_84 = - V_56 ;
goto V_85;
}
V_84 = F_25 ( V_2 ) ;
if ( V_84 )
goto V_85;
F_85 ( V_2 ) ;
return 0 ;
V_85:
F_65 ( V_2 ) ;
return V_84 ;
}
int F_91 ( struct V_1 * V_2 )
{
int (* F_25)( struct V_1 * );
int V_84 = 0 ;
F_25 = F_92 ( V_2 ) ;
if ( ! F_25 ) {
V_84 = - V_56 ;
goto V_24;
}
V_84 = F_25 ( V_2 ) ;
if ( V_84 )
goto V_24;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_24:
F_65 ( V_2 ) ;
return V_84 ;
}
