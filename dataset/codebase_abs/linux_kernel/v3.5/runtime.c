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
static int F_18 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static int F_23 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static void F_24 ( struct V_56 * V_44 )
{
struct V_1 * V_2 = F_25 ( V_44 , struct V_1 , V_6 . V_44 ) ;
enum V_57 V_58 ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
if ( ! V_2 -> V_6 . V_34 )
goto V_24;
V_58 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_34 = false ;
switch ( V_58 ) {
case V_18 :
break;
case V_38 :
F_15 ( V_2 , V_60 ) ;
break;
case V_61 :
F_18 ( V_2 , V_60 ) ;
break;
case V_62 :
F_18 ( V_2 , V_60 | V_63 ) ;
break;
case V_35 :
F_23 ( V_2 , V_60 ) ;
break;
}
V_24:
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
static void F_28 ( unsigned long V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
unsigned long V_65 ;
unsigned long V_22 ;
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_30 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_18 ( V_2 , V_2 -> V_6 . V_66 ?
( V_42 | V_63 ) : V_42 ) ;
}
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_67 )
{
unsigned long V_65 ;
int V_25 ;
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
if ( ! V_67 ) {
V_25 = F_18 ( V_2 , V_42 ) ;
goto V_24;
}
V_25 = F_10 ( V_2 ) ;
if ( V_25 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_67 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_66 = 0 ;
F_33 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
return V_25 ;
}
int F_34 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_65 ;
int V_25 ;
F_35 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_36 & V_69 ) {
if ( ! F_36 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
V_25 = F_15 ( V_2 , V_36 ) ;
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
return V_25 ;
}
int F_37 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_65 ;
int V_25 ;
F_35 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_36 & V_69 ) {
if ( ! F_36 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
V_25 = F_18 ( V_2 , V_36 ) ;
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
return V_25 ;
}
int F_38 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_65 ;
int V_25 ;
F_35 ( ! ( V_36 & V_42 ) && ! V_2 -> V_6 . V_68 ) ;
if ( V_36 & V_69 )
F_39 ( & V_2 -> V_6 . V_29 ) ;
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
V_25 = F_23 ( V_2 , V_36 ) ;
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
return V_25 ;
}
int F_40 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_70 = V_2 -> V_70 ;
unsigned long V_65 ;
bool V_71 = false ;
int error = 0 ;
if ( V_14 != V_37 && V_14 != V_10 )
return - V_27 ;
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
if ( ! V_2 -> V_6 . V_26 && ! V_2 -> V_6 . V_8 ) {
error = - V_30 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_72;
if ( V_14 == V_10 ) {
if ( V_70 ) {
F_41 ( & V_70 -> V_6 . V_73 , - 1 , 0 ) ;
V_71 = ! V_70 -> V_6 . V_74 ;
}
goto V_72;
}
if ( V_70 ) {
F_42 ( & V_70 -> V_6 . V_59 , V_75 ) ;
if ( ! V_70 -> V_6 . V_8
&& ! V_70 -> V_6 . V_74
&& V_70 -> V_6 . V_9 != V_37 )
error = - V_31 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_39 ( & V_70 -> V_6 . V_73 ) ;
F_43 ( & V_70 -> V_6 . V_59 ) ;
if ( error )
goto V_24;
}
V_72:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_26 = 0 ;
V_24:
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
if ( V_71 )
F_44 ( V_70 ) ;
return error ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
F_46 ( & V_2 -> V_6 . V_44 ) ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
V_2 -> V_6 . V_34 = false ;
}
if ( V_2 -> V_6 . V_9 == V_33
|| V_2 -> V_6 . V_9 == V_76
|| V_2 -> V_6 . V_39 ) {
F_47 ( V_77 ) ;
for (; ; ) {
F_48 ( & V_2 -> V_6 . V_52 , & V_77 ,
V_78 ) ;
if ( V_2 -> V_6 . V_9 != V_33
&& V_2 -> V_6 . V_9 != V_76
&& ! V_2 -> V_6 . V_39 )
break;
F_27 ( & V_2 -> V_6 . V_59 ) ;
F_49 () ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
}
F_50 ( & V_2 -> V_6 . V_52 , & V_77 ) ;
}
}
int F_51 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_52 ( V_2 ) ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
if ( V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_23 ( V_2 , 0 ) ;
V_25 = 1 ;
}
F_45 ( V_2 ) ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
F_53 ( V_2 ) ;
return V_25 ;
}
void F_54 ( struct V_1 * V_2 , bool V_79 )
{
F_26 ( & V_2 -> V_6 . V_59 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_79 && V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_52 ( V_2 ) ;
F_23 ( V_2 , 0 ) ;
F_53 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_45 ( V_2 ) ;
V_24:
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
unsigned long V_65 ;
F_29 ( & V_2 -> V_6 . V_59 , V_65 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_56 ( V_2 , L_1 , V_80 ) ;
F_31 ( & V_2 -> V_6 . V_59 , V_65 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_6 . V_59 ) ;
if ( ! V_2 -> V_6 . V_81 )
goto V_24;
V_2 -> V_6 . V_81 = false ;
F_39 ( & V_2 -> V_6 . V_29 ) ;
F_23 ( V_2 , 0 ) ;
V_24:
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_6 . V_59 ) ;
if ( V_2 -> V_6 . V_81 )
goto V_24;
V_2 -> V_6 . V_81 = true ;
if ( F_36 ( & V_2 -> V_6 . V_29 ) )
F_15 ( V_2 , V_63 ) ;
V_24:
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
F_26 ( & V_2 -> V_6 . V_59 ) ;
V_2 -> V_6 . V_41 = 1 ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
if ( F_60 ( V_2 ) )
F_61 ( V_2 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_70 )
F_63 ( V_2 -> V_70 ) ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
V_2 -> V_6 . V_68 = 1 ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
static void F_64 ( struct V_1 * V_2 , int V_82 , int V_83 )
{
int V_67 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_67 < 0 ) {
if ( ! V_83 || V_82 >= 0 ) {
F_39 ( & V_2 -> V_6 . V_29 ) ;
F_23 ( V_2 , 0 ) ;
}
}
else {
if ( V_83 && V_82 < 0 )
F_65 ( & V_2 -> V_6 . V_29 ) ;
F_15 ( V_2 , V_63 ) ;
}
}
void F_66 ( struct V_1 * V_2 , int V_67 )
{
int V_82 , V_83 ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
V_82 = V_2 -> V_6 . V_19 ;
V_83 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_67 ;
F_64 ( V_2 , V_82 , V_83 ) ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
void F_67 ( struct V_1 * V_2 , bool V_84 )
{
int V_82 , V_83 ;
F_26 ( & V_2 -> V_6 . V_59 ) ;
V_82 = V_2 -> V_6 . V_19 ;
V_83 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_84 ;
F_64 ( V_2 , V_82 , V_83 ) ;
F_27 ( & V_2 -> V_6 . V_59 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_39 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_69 ( & V_2 -> V_6 . V_29 , 0 ) ;
V_2 -> V_6 . V_26 = 0 ;
F_69 ( & V_2 -> V_6 . V_73 , 0 ) ;
F_70 ( V_2 , false ) ;
V_2 -> V_6 . V_81 = true ;
V_2 -> V_6 . V_34 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_32 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_71 ( & V_2 -> V_6 . V_44 , F_24 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_72 ( & V_2 -> V_6 . V_16 , F_28 ,
( unsigned long ) V_2 ) ;
F_73 ( & V_2 -> V_6 . V_52 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_54 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_37 )
F_75 ( V_2 ) ;
if ( V_2 -> V_6 . V_68 && V_2 -> V_70 )
F_76 ( V_2 -> V_70 ) ;
}
