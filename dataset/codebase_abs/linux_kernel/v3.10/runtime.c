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
if ( V_2 -> V_6 . V_49 ) {
V_32 = F_27 ( V_2 , V_44 ) ;
goto V_24;
}
if ( V_44 & V_50 ) {
V_2 -> V_6 . V_17 = V_46 ;
if ( ! V_2 -> V_6 . V_41 ) {
V_2 -> V_6 . V_41 = true ;
F_28 ( V_51 , & V_2 -> V_6 . V_52 ) ;
}
goto V_24;
}
V_2 -> V_6 . V_47 = true ;
if ( V_2 -> V_53 )
F_25 = V_2 -> V_53 -> V_54 . V_55 ;
else if ( V_2 -> type && V_2 -> type -> V_56 )
F_25 = V_2 -> type -> V_56 -> V_55 ;
else if ( V_2 -> V_57 && V_2 -> V_57 -> V_56 )
F_25 = V_2 -> V_57 -> V_56 -> V_55 ;
else if ( V_2 -> V_58 && V_2 -> V_58 -> V_56 )
F_25 = V_2 -> V_58 -> V_56 -> V_55 ;
else
F_25 = NULL ;
if ( ! F_25 && V_2 -> V_59 && V_2 -> V_59 -> V_56 )
F_25 = V_2 -> V_59 -> V_56 -> V_55 ;
if ( F_25 )
F_22 ( F_25 , V_2 ) ;
V_2 -> V_6 . V_47 = false ;
F_29 ( & V_2 -> V_6 . V_60 ) ;
V_24:
F_30 ( V_2 , V_61 , V_32 ) ;
return V_32 ;
}
static int F_31 ( int (* F_23)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_23 )
return - V_62 ;
if ( V_2 -> V_6 . V_26 ) {
unsigned int V_63 ;
V_63 = F_32 () ;
V_32 = F_22 ( F_23 , V_2 ) ;
F_33 ( V_63 ) ;
} else {
V_32 = F_22 ( F_23 , V_2 ) ;
}
V_2 -> V_6 . V_33 = V_32 ;
return V_32 != - V_35 ? V_32 : - V_64 ;
}
static int F_27 ( struct V_1 * V_2 , int V_44 )
__releases( &dev->power.lock
static int F_34 ( struct V_1 * V_2 , int V_44 )
__releases( &dev->power.lock
static void F_35 ( struct V_65 * V_52 )
{
struct V_1 * V_2 = F_36 ( V_52 , struct V_1 , V_6 . V_52 ) ;
enum V_66 V_67 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( ! V_2 -> V_6 . V_41 )
goto V_24;
V_67 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_41 = false ;
switch ( V_67 ) {
case V_18 :
break;
case V_46 :
F_24 ( V_2 , V_68 ) ;
break;
case V_69 :
F_27 ( V_2 , V_68 ) ;
break;
case V_70 :
F_27 ( V_2 , V_68 | V_71 ) ;
break;
case V_42 :
F_34 ( V_2 , V_68 ) ;
break;
}
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
static void F_37 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
unsigned long V_72 ;
unsigned long V_22 ;
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_39 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_27 ( V_2 , V_2 -> V_6 . V_73 ?
( V_50 | V_71 ) : V_50 ) ;
}
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
}
int F_41 ( struct V_1 * V_2 , unsigned int V_74 )
{
unsigned long V_72 ;
int V_32 ;
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
if ( ! V_74 ) {
V_32 = F_27 ( V_2 , V_50 ) ;
goto V_24;
}
V_32 = F_18 ( V_2 ) ;
if ( V_32 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_74 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_73 = 0 ;
F_42 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
return V_32 ;
}
int F_43 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_72 ;
int V_32 ;
F_44 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_75 ) ;
if ( V_44 & V_76 ) {
if ( ! F_45 ( & V_2 -> V_6 . V_36 ) )
return 0 ;
}
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
V_32 = F_24 ( V_2 , V_44 ) ;
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
return V_32 ;
}
int F_46 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_72 ;
int V_32 ;
F_44 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_75 ) ;
if ( V_44 & V_76 ) {
if ( ! F_45 ( & V_2 -> V_6 . V_36 ) )
return 0 ;
}
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
V_32 = F_27 ( V_2 , V_44 ) ;
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
return V_32 ;
}
int F_47 ( struct V_1 * V_2 , int V_44 )
{
unsigned long V_72 ;
int V_32 ;
F_44 ( ! ( V_44 & V_50 ) && ! V_2 -> V_6 . V_75 ) ;
if ( V_44 & V_76 )
F_48 ( & V_2 -> V_6 . V_36 ) ;
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
V_32 = F_34 ( V_2 , V_44 ) ;
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
return V_32 ;
}
int F_49 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_31 = V_2 -> V_31 ;
unsigned long V_72 ;
bool V_77 = false ;
int error = 0 ;
if ( V_14 != V_45 && V_14 != V_10 )
return - V_34 ;
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
if ( ! V_2 -> V_6 . V_33 && ! V_2 -> V_6 . V_8 ) {
error = - V_37 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_78;
if ( V_14 == V_10 ) {
if ( V_31 ) {
F_50 ( & V_31 -> V_6 . V_79 , - 1 , 0 ) ;
V_77 = ! V_31 -> V_6 . V_80 ;
}
goto V_78;
}
if ( V_31 ) {
F_51 ( & V_31 -> V_6 . V_30 , V_81 ) ;
if ( ! V_31 -> V_6 . V_8
&& ! V_31 -> V_6 . V_80
&& V_31 -> V_6 . V_9 != V_45 )
error = - V_38 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_48 ( & V_31 -> V_6 . V_79 ) ;
F_52 ( & V_31 -> V_6 . V_30 ) ;
if ( error )
goto V_24;
}
V_78:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_33 = 0 ;
V_24:
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
if ( V_77 )
F_53 ( V_31 ) ;
return error ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_41 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_55 ( & V_2 -> V_6 . V_52 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_41 = false ;
}
if ( V_2 -> V_6 . V_9 == V_40
|| V_2 -> V_6 . V_9 == V_82
|| V_2 -> V_6 . V_47 ) {
F_56 ( V_83 ) ;
for (; ; ) {
F_57 ( & V_2 -> V_6 . V_60 , & V_83 ,
V_84 ) ;
if ( V_2 -> V_6 . V_9 != V_40
&& V_2 -> V_6 . V_9 != V_82
&& ! V_2 -> V_6 . V_47 )
break;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_58 () ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
}
F_59 ( & V_2 -> V_6 . V_60 , & V_83 ) ;
}
}
int F_60 ( struct V_1 * V_2 )
{
int V_32 = 0 ;
F_61 ( V_2 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_41
&& V_2 -> V_6 . V_17 == V_42 ) {
F_34 ( V_2 , 0 ) ;
V_32 = 1 ;
}
F_54 ( V_2 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
F_62 ( V_2 ) ;
return V_32 ;
}
void F_63 ( struct V_1 * V_2 , bool V_85 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_85 && V_2 -> V_6 . V_41
&& V_2 -> V_6 . V_17 == V_42 ) {
F_61 ( V_2 ) ;
F_34 ( V_2 , 0 ) ;
F_62 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_54 ( V_2 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
unsigned long V_72 ;
F_38 ( & V_2 -> V_6 . V_30 , V_72 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_65 ( V_2 , L_1 , V_86 ) ;
F_40 ( & V_2 -> V_6 . V_30 , V_72 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( ! V_2 -> V_6 . V_87 )
goto V_24;
V_2 -> V_6 . V_87 = false ;
F_48 ( & V_2 -> V_6 . V_36 ) ;
F_34 ( V_2 , 0 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
if ( V_2 -> V_6 . V_87 )
goto V_24;
V_2 -> V_6 . V_87 = true ;
if ( F_45 ( & V_2 -> V_6 . V_36 ) )
F_24 ( V_2 , V_71 ) ;
V_24:
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_49 = 1 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
if ( F_69 ( V_2 ) )
F_70 ( V_2 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
F_72 ( V_2 -> V_31 ) ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_2 -> V_6 . V_75 = 1 ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
static void F_73 ( struct V_1 * V_2 , int V_88 , int V_89 )
{
int V_74 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_74 < 0 ) {
if ( ! V_89 || V_88 >= 0 ) {
F_48 ( & V_2 -> V_6 . V_36 ) ;
F_34 ( V_2 , 0 ) ;
}
}
else {
if ( V_89 && V_88 < 0 )
F_74 ( & V_2 -> V_6 . V_36 ) ;
F_24 ( V_2 , V_71 ) ;
}
}
void F_75 ( struct V_1 * V_2 , int V_74 )
{
int V_88 , V_89 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_88 = V_2 -> V_6 . V_19 ;
V_89 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_74 ;
F_73 ( V_2 , V_88 , V_89 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_76 ( struct V_1 * V_2 , bool V_90 )
{
int V_88 , V_89 ;
F_14 ( & V_2 -> V_6 . V_30 ) ;
V_88 = V_2 -> V_6 . V_19 ;
V_89 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_90 ;
F_73 ( V_2 , V_88 , V_89 ) ;
F_15 ( & V_2 -> V_6 . V_30 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_47 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_78 ( & V_2 -> V_6 . V_36 , 0 ) ;
V_2 -> V_6 . V_33 = 0 ;
F_78 ( & V_2 -> V_6 . V_79 , 0 ) ;
F_79 ( V_2 , false ) ;
V_2 -> V_6 . V_87 = true ;
V_2 -> V_6 . V_41 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_39 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_80 ( & V_2 -> V_6 . V_52 , F_35 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_81 ( & V_2 -> V_6 . V_16 , F_37 ,
( unsigned long ) V_2 ) ;
F_82 ( & V_2 -> V_6 . V_60 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_63 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_45 )
F_84 ( V_2 ) ;
if ( V_2 -> V_6 . V_75 && V_2 -> V_31 )
F_85 ( V_2 -> V_31 ) ;
}
