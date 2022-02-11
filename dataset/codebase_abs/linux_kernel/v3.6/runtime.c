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
static int F_10 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( V_2 -> V_6 . V_26 )
V_25 = - V_27 ;
else if ( V_2 -> V_6 . V_8 > 0 )
V_25 = - V_28 ;
else if ( F_11 ( & V_2 -> V_6 . V_29 ) > 0 )
V_25 = - V_30 ;
else if ( ! F_12 ( V_2 ) )
V_25 = - V_31 ;
else if ( ( V_2 -> V_6 . V_32
&& V_2 -> V_6 . V_9 == V_33 )
|| ( V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) )
V_25 = - V_30 ;
else if ( F_13 ( V_2 ) < 0 )
V_25 = - V_36 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
V_25 = 1 ;
return V_25 ;
}
static int F_14 ( int (* F_15)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_16 ( struct V_1 * V_2 , int V_37 )
{
int (* F_17)( struct V_1 * );
int V_25 ;
F_18 ( V_2 , V_37 ) ;
V_25 = F_10 ( V_2 ) ;
if ( V_25 < 0 )
;
else if ( V_2 -> V_6 . V_9 != V_38 )
V_25 = - V_30 ;
else if ( V_2 -> V_6 . V_34 &&
V_2 -> V_6 . V_17 > V_39 )
V_25 = - V_30 ;
else if ( V_2 -> V_6 . V_40 )
V_25 = - V_41 ;
if ( V_25 )
goto V_24;
V_2 -> V_6 . V_17 = V_18 ;
if ( V_2 -> V_6 . V_42 ) {
V_25 = F_19 ( V_2 , V_37 ) ;
goto V_24;
}
if ( V_37 & V_43 ) {
V_2 -> V_6 . V_17 = V_39 ;
if ( ! V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_34 = true ;
F_20 ( V_44 , & V_2 -> V_6 . V_45 ) ;
}
goto V_24;
}
V_2 -> V_6 . V_40 = true ;
if ( V_2 -> V_46 )
F_17 = V_2 -> V_46 -> V_47 . V_48 ;
else if ( V_2 -> type && V_2 -> type -> V_49 )
F_17 = V_2 -> type -> V_49 -> V_48 ;
else if ( V_2 -> V_50 && V_2 -> V_50 -> V_49 )
F_17 = V_2 -> V_50 -> V_49 -> V_48 ;
else if ( V_2 -> V_51 && V_2 -> V_51 -> V_49 )
F_17 = V_2 -> V_51 -> V_49 -> V_48 ;
else
F_17 = NULL ;
if ( ! F_17 && V_2 -> V_52 && V_2 -> V_52 -> V_49 )
F_17 = V_2 -> V_52 -> V_49 -> V_48 ;
if ( F_17 )
F_14 ( F_17 , V_2 ) ;
V_2 -> V_6 . V_40 = false ;
F_21 ( & V_2 -> V_6 . V_53 ) ;
V_24:
F_22 ( V_2 , V_54 , V_25 ) ;
return V_25 ;
}
static int F_23 ( int (* F_15)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_25 ;
if ( ! F_15 )
return - V_55 ;
V_25 = F_14 ( F_15 , V_2 ) ;
V_2 -> V_6 . V_26 = V_25 ;
return V_25 != - V_28 ? V_25 : - V_56 ;
}
static int F_19 ( struct V_1 * V_2 , int V_37 )
__releases( &dev->power.lock
static int F_24 ( struct V_1 * V_2 , int V_37 )
__releases( &dev->power.lock
static void F_25 ( struct V_57 * V_45 )
{
struct V_1 * V_2 = F_26 ( V_45 , struct V_1 , V_6 . V_45 ) ;
enum V_58 V_59 ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
if ( ! V_2 -> V_6 . V_34 )
goto V_24;
V_59 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_34 = false ;
switch ( V_59 ) {
case V_18 :
break;
case V_39 :
F_16 ( V_2 , V_61 ) ;
break;
case V_62 :
F_19 ( V_2 , V_61 ) ;
break;
case V_63 :
F_19 ( V_2 , V_61 | V_64 ) ;
break;
case V_35 :
F_24 ( V_2 , V_61 ) ;
break;
}
V_24:
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
static void F_29 ( unsigned long V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
unsigned long V_66 ;
unsigned long V_22 ;
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_31 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_19 ( V_2 , V_2 -> V_6 . V_67 ?
( V_43 | V_64 ) : V_43 ) ;
}
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
}
int F_33 ( struct V_1 * V_2 , unsigned int V_68 )
{
unsigned long V_66 ;
int V_25 ;
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
if ( ! V_68 ) {
V_25 = F_19 ( V_2 , V_43 ) ;
goto V_24;
}
V_25 = F_10 ( V_2 ) ;
if ( V_25 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_68 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_67 = 0 ;
F_34 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
return V_25 ;
}
int F_35 ( struct V_1 * V_2 , int V_37 )
{
unsigned long V_66 ;
int V_25 ;
F_36 ( ! ( V_37 & V_43 ) && ! V_2 -> V_6 . V_69 ) ;
if ( V_37 & V_70 ) {
if ( ! F_37 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
V_25 = F_16 ( V_2 , V_37 ) ;
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
return V_25 ;
}
int F_38 ( struct V_1 * V_2 , int V_37 )
{
unsigned long V_66 ;
int V_25 ;
F_36 ( ! ( V_37 & V_43 ) && ! V_2 -> V_6 . V_69 ) ;
if ( V_37 & V_70 ) {
if ( ! F_37 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
V_25 = F_19 ( V_2 , V_37 ) ;
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
return V_25 ;
}
int F_39 ( struct V_1 * V_2 , int V_37 )
{
unsigned long V_66 ;
int V_25 ;
F_36 ( ! ( V_37 & V_43 ) && ! V_2 -> V_6 . V_69 ) ;
if ( V_37 & V_70 )
F_40 ( & V_2 -> V_6 . V_29 ) ;
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
V_25 = F_24 ( V_2 , V_37 ) ;
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
return V_25 ;
}
int F_41 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_71 = V_2 -> V_71 ;
unsigned long V_66 ;
bool V_72 = false ;
int error = 0 ;
if ( V_14 != V_38 && V_14 != V_10 )
return - V_27 ;
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
if ( ! V_2 -> V_6 . V_26 && ! V_2 -> V_6 . V_8 ) {
error = - V_30 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_73;
if ( V_14 == V_10 ) {
if ( V_71 ) {
F_42 ( & V_71 -> V_6 . V_74 , - 1 , 0 ) ;
V_72 = ! V_71 -> V_6 . V_75 ;
}
goto V_73;
}
if ( V_71 ) {
F_43 ( & V_71 -> V_6 . V_60 , V_76 ) ;
if ( ! V_71 -> V_6 . V_8
&& ! V_71 -> V_6 . V_75
&& V_71 -> V_6 . V_9 != V_38 )
error = - V_31 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_40 ( & V_71 -> V_6 . V_74 ) ;
F_44 ( & V_71 -> V_6 . V_60 ) ;
if ( error )
goto V_24;
}
V_73:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_26 = 0 ;
V_24:
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
if ( V_72 )
F_45 ( V_71 ) ;
return error ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
F_47 ( & V_2 -> V_6 . V_45 ) ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
V_2 -> V_6 . V_34 = false ;
}
if ( V_2 -> V_6 . V_9 == V_33
|| V_2 -> V_6 . V_9 == V_77
|| V_2 -> V_6 . V_40 ) {
F_48 ( V_78 ) ;
for (; ; ) {
F_49 ( & V_2 -> V_6 . V_53 , & V_78 ,
V_79 ) ;
if ( V_2 -> V_6 . V_9 != V_33
&& V_2 -> V_6 . V_9 != V_77
&& ! V_2 -> V_6 . V_40 )
break;
F_28 ( & V_2 -> V_6 . V_60 ) ;
F_50 () ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
}
F_51 ( & V_2 -> V_6 . V_53 , & V_78 ) ;
}
}
int F_52 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_53 ( V_2 ) ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
if ( V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_24 ( V_2 , 0 ) ;
V_25 = 1 ;
}
F_46 ( V_2 ) ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
F_54 ( V_2 ) ;
return V_25 ;
}
void F_55 ( struct V_1 * V_2 , bool V_80 )
{
F_27 ( & V_2 -> V_6 . V_60 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_80 && V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_53 ( V_2 ) ;
F_24 ( V_2 , 0 ) ;
F_54 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_46 ( V_2 ) ;
V_24:
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
unsigned long V_66 ;
F_30 ( & V_2 -> V_6 . V_60 , V_66 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_57 ( V_2 , L_1 , V_81 ) ;
F_32 ( & V_2 -> V_6 . V_60 , V_66 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 . V_60 ) ;
if ( ! V_2 -> V_6 . V_82 )
goto V_24;
V_2 -> V_6 . V_82 = false ;
F_40 ( & V_2 -> V_6 . V_29 ) ;
F_24 ( V_2 , 0 ) ;
V_24:
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 . V_60 ) ;
if ( V_2 -> V_6 . V_82 )
goto V_24;
V_2 -> V_6 . V_82 = true ;
if ( F_37 ( & V_2 -> V_6 . V_29 ) )
F_16 ( V_2 , V_64 ) ;
V_24:
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_6 . V_60 ) ;
V_2 -> V_6 . V_42 = 1 ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
if ( F_61 ( V_2 ) )
F_62 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 )
F_64 ( V_2 -> V_71 ) ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
V_2 -> V_6 . V_69 = 1 ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
static void F_65 ( struct V_1 * V_2 , int V_83 , int V_84 )
{
int V_68 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_68 < 0 ) {
if ( ! V_84 || V_83 >= 0 ) {
F_40 ( & V_2 -> V_6 . V_29 ) ;
F_24 ( V_2 , 0 ) ;
}
}
else {
if ( V_84 && V_83 < 0 )
F_66 ( & V_2 -> V_6 . V_29 ) ;
F_16 ( V_2 , V_64 ) ;
}
}
void F_67 ( struct V_1 * V_2 , int V_68 )
{
int V_83 , V_84 ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
V_83 = V_2 -> V_6 . V_19 ;
V_84 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_68 ;
F_65 ( V_2 , V_83 , V_84 ) ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
void F_68 ( struct V_1 * V_2 , bool V_85 )
{
int V_83 , V_84 ;
F_27 ( & V_2 -> V_6 . V_60 ) ;
V_83 = V_2 -> V_6 . V_19 ;
V_84 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_85 ;
F_65 ( V_2 , V_83 , V_84 ) ;
F_28 ( & V_2 -> V_6 . V_60 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_40 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_70 ( & V_2 -> V_6 . V_29 , 0 ) ;
V_2 -> V_6 . V_26 = 0 ;
F_70 ( & V_2 -> V_6 . V_74 , 0 ) ;
F_71 ( V_2 , false ) ;
V_2 -> V_6 . V_82 = true ;
V_2 -> V_6 . V_34 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_32 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_72 ( & V_2 -> V_6 . V_45 , F_25 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_73 ( & V_2 -> V_6 . V_16 , F_29 ,
( unsigned long ) V_2 ) ;
F_74 ( & V_2 -> V_6 . V_53 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_55 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_38 )
F_76 ( V_2 ) ;
if ( V_2 -> V_6 . V_69 && V_2 -> V_71 )
F_77 ( V_2 -> V_71 ) ;
}
