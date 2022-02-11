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
else if ( V_2 -> V_6 . V_9 == V_10 )
V_25 = 1 ;
return V_25 ;
}
static int F_13 ( int (* F_14)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_15 ( struct V_1 * V_2 , int V_36 )
{
int (* F_16)( struct V_1 * );
int V_25 ;
F_17 ( V_2 , V_36 ) ;
V_25 = F_10 ( V_2 ) ;
if ( V_25 < 0 )
;
else if ( V_2 -> V_6 . V_9 != V_37 )
V_25 = - V_30 ;
else if ( V_2 -> V_6 . V_34 &&
V_2 -> V_6 . V_17 > V_38 )
V_25 = - V_30 ;
else if ( V_2 -> V_6 . V_39 )
V_25 = - V_40 ;
if ( V_25 )
goto V_24;
V_2 -> V_6 . V_17 = V_18 ;
if ( V_2 -> V_6 . V_41 ) {
V_25 = F_18 ( V_2 , V_36 ) ;
goto V_24;
}
if ( V_36 & V_42 ) {
V_2 -> V_6 . V_17 = V_38 ;
if ( ! V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_34 = true ;
F_19 ( V_43 , & V_2 -> V_6 . V_44 ) ;
}
goto V_24;
}
V_2 -> V_6 . V_39 = true ;
if ( V_2 -> V_45 )
F_16 = V_2 -> V_45 -> V_46 . V_47 ;
else if ( V_2 -> type && V_2 -> type -> V_48 )
F_16 = V_2 -> type -> V_48 -> V_47 ;
else if ( V_2 -> V_49 && V_2 -> V_49 -> V_48 )
F_16 = V_2 -> V_49 -> V_48 -> V_47 ;
else if ( V_2 -> V_50 && V_2 -> V_50 -> V_48 )
F_16 = V_2 -> V_50 -> V_48 -> V_47 ;
else
F_16 = NULL ;
if ( ! F_16 && V_2 -> V_51 && V_2 -> V_51 -> V_48 )
F_16 = V_2 -> V_51 -> V_48 -> V_47 ;
if ( F_16 )
F_13 ( F_16 , V_2 ) ;
V_2 -> V_6 . V_39 = false ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_24:
F_21 ( V_2 , V_53 , V_25 ) ;
return V_25 ;
}
static int F_22 ( int (* F_14)( struct V_1 * ) , struct V_1 * V_2 )
{
int V_25 ;
if ( ! F_14 )
return - V_54 ;
V_25 = F_13 ( F_14 , V_2 ) ;
V_2 -> V_6 . V_26 = V_25 ;
return V_25 != - V_28 ? V_25 : - V_55 ;
}
static int F_23 ( struct V_1 * V_2 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
unsigned long V_59 ;
T_1 V_60 ;
int V_61 = 0 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( V_2 -> V_6 . V_63 < 0 )
goto V_24;
V_60 = V_2 -> V_6 . V_63 -
F_25 ( F_26 ( V_58 -> V_64 , V_2 -> V_6 . V_65 ) ) ;
if ( V_60 <= 0 ) {
V_61 = - V_31 ;
goto V_24;
}
if ( V_58 -> V_66 > V_60 || V_58 -> V_66 == 0 )
V_58 -> V_66 = V_60 ;
V_24:
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
return V_61 ;
}
static int F_18 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static int F_28 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static void F_29 ( struct V_67 * V_44 )
{
struct V_1 * V_2 = F_30 ( V_44 , struct V_1 , V_6 . V_44 ) ;
enum V_68 V_69 ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
if ( ! V_2 -> V_6 . V_34 )
goto V_24;
V_69 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_34 = false ;
switch ( V_69 ) {
case V_18 :
break;
case V_38 :
F_15 ( V_2 , V_70 ) ;
break;
case V_71 :
F_18 ( V_2 , V_70 ) ;
break;
case V_72 :
F_18 ( V_2 , V_70 | V_73 ) ;
break;
case V_35 :
F_28 ( V_2 , V_70 ) ;
break;
}
V_24:
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
static void F_33 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
unsigned long V_59 ;
unsigned long V_22 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_34 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_18 ( V_2 , V_2 -> V_6 . V_74 ?
( V_42 | V_73 ) : V_42 ) ;
}
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
}
int F_35 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_59 ;
int V_25 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( ! V_75 ) {
V_25 = F_18 ( V_2 , V_42 ) ;
goto V_24;
}
V_25 = F_10 ( V_2 ) ;
if ( V_25 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_75 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_74 = 0 ;
F_36 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
return V_25 ;
}
int F_37 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_59 ;
int V_25 ;
F_38 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_76 ) ;
if ( V_36 & V_77 ) {
if ( ! F_39 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
V_25 = F_15 ( V_2 , V_36 ) ;
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
return V_25 ;
}
int F_40 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_59 ;
int V_25 ;
F_38 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_76 ) ;
if ( V_36 & V_77 ) {
if ( ! F_39 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
V_25 = F_18 ( V_2 , V_36 ) ;
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
return V_25 ;
}
int F_41 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_59 ;
int V_25 ;
F_38 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_76 ) ;
if ( V_36 & V_77 )
F_42 ( & V_2 -> V_6 . V_29 ) ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
V_25 = F_28 ( V_2 , V_36 ) ;
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
return V_25 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_78 = V_2 -> V_78 ;
unsigned long V_59 ;
bool V_79 = false ;
int error = 0 ;
if ( V_14 != V_37 && V_14 != V_10 )
return - V_27 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( ! V_2 -> V_6 . V_26 && ! V_2 -> V_6 . V_8 ) {
error = - V_30 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_80;
if ( V_14 == V_10 ) {
if ( V_78 ) {
F_44 ( & V_78 -> V_6 . V_81 , - 1 , 0 ) ;
V_79 = ! V_78 -> V_6 . V_82 ;
}
goto V_80;
}
if ( V_78 ) {
F_45 ( & V_78 -> V_6 . V_62 , V_83 ) ;
if ( ! V_78 -> V_6 . V_8
&& ! V_78 -> V_6 . V_82
&& V_78 -> V_6 . V_9 != V_37 )
error = - V_31 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_42 ( & V_78 -> V_6 . V_81 ) ;
F_46 ( & V_78 -> V_6 . V_62 ) ;
if ( error )
goto V_24;
}
V_80:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_26 = 0 ;
V_24:
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( V_79 )
F_47 ( V_78 ) ;
return error ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
F_49 ( & V_2 -> V_6 . V_44 ) ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
V_2 -> V_6 . V_34 = false ;
}
if ( V_2 -> V_6 . V_9 == V_33
|| V_2 -> V_6 . V_9 == V_84
|| V_2 -> V_6 . V_39 ) {
F_50 ( V_85 ) ;
for (; ; ) {
F_51 ( & V_2 -> V_6 . V_52 , & V_85 ,
V_86 ) ;
if ( V_2 -> V_6 . V_9 != V_33
&& V_2 -> V_6 . V_9 != V_84
&& ! V_2 -> V_6 . V_39 )
break;
F_32 ( & V_2 -> V_6 . V_62 ) ;
F_52 () ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
}
F_53 ( & V_2 -> V_6 . V_52 , & V_85 ) ;
}
}
int F_54 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_55 ( V_2 ) ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
if ( V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_28 ( V_2 , 0 ) ;
V_25 = 1 ;
}
F_48 ( V_2 ) ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
F_56 ( V_2 ) ;
return V_25 ;
}
void F_57 ( struct V_1 * V_2 , bool V_87 )
{
F_31 ( & V_2 -> V_6 . V_62 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_87 && V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_55 ( V_2 ) ;
F_28 ( V_2 , 0 ) ;
F_56 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_48 ( V_2 ) ;
V_24:
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
unsigned long V_59 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_59 ( V_2 , L_1 , V_88 ) ;
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_6 . V_62 ) ;
if ( ! V_2 -> V_6 . V_89 )
goto V_24;
V_2 -> V_6 . V_89 = false ;
F_42 ( & V_2 -> V_6 . V_29 ) ;
F_28 ( V_2 , 0 ) ;
V_24:
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_6 . V_62 ) ;
if ( V_2 -> V_6 . V_89 )
goto V_24;
V_2 -> V_6 . V_89 = true ;
if ( F_39 ( & V_2 -> V_6 . V_29 ) )
F_15 ( V_2 , V_73 ) ;
V_24:
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_6 . V_62 ) ;
V_2 -> V_6 . V_41 = 1 ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
if ( F_63 ( V_2 ) )
F_64 ( V_2 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 )
F_66 ( V_2 -> V_78 ) ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
V_2 -> V_6 . V_76 = 1 ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
static void F_67 ( struct V_1 * V_2 , int V_90 , int V_91 )
{
int V_75 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_75 < 0 ) {
if ( ! V_91 || V_90 >= 0 ) {
F_42 ( & V_2 -> V_6 . V_29 ) ;
F_28 ( V_2 , 0 ) ;
}
}
else {
if ( V_91 && V_90 < 0 )
F_68 ( & V_2 -> V_6 . V_29 ) ;
F_15 ( V_2 , V_73 ) ;
}
}
void F_69 ( struct V_1 * V_2 , int V_75 )
{
int V_90 , V_91 ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
V_90 = V_2 -> V_6 . V_19 ;
V_91 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_75 ;
F_67 ( V_2 , V_90 , V_91 ) ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
void F_70 ( struct V_1 * V_2 , bool V_92 )
{
int V_90 , V_91 ;
F_31 ( & V_2 -> V_6 . V_62 ) ;
V_90 = V_2 -> V_6 . V_19 ;
V_91 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_92 ;
F_67 ( V_2 , V_90 , V_91 ) ;
F_32 ( & V_2 -> V_6 . V_62 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_39 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_72 ( & V_2 -> V_6 . V_29 , 0 ) ;
V_2 -> V_6 . V_26 = 0 ;
F_72 ( & V_2 -> V_6 . V_81 , 0 ) ;
F_73 ( V_2 , false ) ;
V_2 -> V_6 . V_89 = true ;
V_2 -> V_6 . V_34 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_32 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_74 ( & V_2 -> V_6 . V_44 , F_29 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_75 ( & V_2 -> V_6 . V_16 , F_33 ,
( unsigned long ) V_2 ) ;
V_2 -> V_6 . V_65 = F_76 ( 0 , 0 ) ;
V_2 -> V_6 . V_63 = - 1 ;
F_77 ( & V_2 -> V_6 . V_52 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_57 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_37 )
F_79 ( V_2 ) ;
if ( V_2 -> V_6 . V_76 && V_2 -> V_78 )
F_80 ( V_2 -> V_78 ) ;
}
void F_81 ( struct V_1 * V_2 , T_1 V_60 )
{
unsigned long V_59 ;
F_24 ( & V_2 -> V_6 . V_62 , V_59 ) ;
if ( V_60 > 0 && V_2 -> V_6 . V_63 > 0 ) {
if ( V_2 -> V_6 . V_63 > V_60 )
V_2 -> V_6 . V_63 -= V_60 ;
else
V_2 -> V_6 . V_63 = 0 ;
}
F_27 ( & V_2 -> V_6 . V_62 , V_59 ) ;
}
