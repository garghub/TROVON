void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 ;
int V_5 ;
V_5 = V_3 - V_2 -> V_6 . V_7 ;
if ( V_5 < 0 )
V_5 = 0 ;
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
else if ( F_11 ( & V_2 -> V_6 . V_28 ) > 0
|| V_2 -> V_6 . V_8 > 0 )
V_25 = - V_29 ;
else if ( ! F_12 ( V_2 ) )
V_25 = - V_30 ;
else if ( ( V_2 -> V_6 . V_31
&& V_2 -> V_6 . V_9 == V_32 )
|| ( V_2 -> V_6 . V_33
&& V_2 -> V_6 . V_17 == V_34 ) )
V_25 = - V_29 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
V_25 = 1 ;
return V_25 ;
}
static int F_13 ( struct V_1 * V_2 , int V_35 )
{
int (* F_14)( struct V_1 * );
int V_25 ;
V_25 = F_10 ( V_2 ) ;
if ( V_25 < 0 )
;
else if ( V_2 -> V_6 . V_9 != V_36 )
V_25 = - V_29 ;
else if ( V_2 -> V_6 . V_33 &&
V_2 -> V_6 . V_17 > V_37 )
V_25 = - V_29 ;
else if ( V_2 -> V_6 . V_38 )
V_25 = - V_39 ;
if ( V_25 )
goto V_24;
V_2 -> V_6 . V_17 = V_18 ;
if ( V_2 -> V_6 . V_40 ) {
V_25 = F_15 ( V_2 , V_35 ) ;
goto V_24;
}
if ( V_35 & V_41 ) {
V_2 -> V_6 . V_17 = V_37 ;
if ( ! V_2 -> V_6 . V_33 ) {
V_2 -> V_6 . V_33 = true ;
F_16 ( V_42 , & V_2 -> V_6 . V_43 ) ;
}
goto V_24;
}
V_2 -> V_6 . V_38 = true ;
if ( V_2 -> V_44 )
F_14 = V_2 -> V_44 -> V_45 . V_46 ;
else if ( V_2 -> type && V_2 -> type -> V_47 )
F_14 = V_2 -> type -> V_47 -> V_46 ;
else if ( V_2 -> V_48 && V_2 -> V_48 -> V_47 )
F_14 = V_2 -> V_48 -> V_47 -> V_46 ;
else if ( V_2 -> V_49 && V_2 -> V_49 -> V_47 )
F_14 = V_2 -> V_49 -> V_47 -> V_46 ;
else
F_14 = NULL ;
if ( F_14 ) {
F_17 ( & V_2 -> V_6 . V_50 ) ;
F_14 ( V_2 ) ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
}
V_2 -> V_6 . V_38 = false ;
F_19 ( & V_2 -> V_6 . V_51 ) ;
V_24:
return V_25 ;
}
static int F_20 ( int (* F_21)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_15 ( struct V_1 * V_2 , int V_35 )
__releases( &dev->power.lock
static int F_22 ( struct V_1 * V_2 , int V_35 )
__releases( &dev->power.lock
static void F_23 ( struct V_52 * V_43 )
{
struct V_1 * V_2 = F_24 ( V_43 , struct V_1 , V_6 . V_43 ) ;
enum V_53 V_54 ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
if ( ! V_2 -> V_6 . V_33 )
goto V_24;
V_54 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_33 = false ;
switch ( V_54 ) {
case V_18 :
break;
case V_37 :
F_13 ( V_2 , V_55 ) ;
break;
case V_56 :
F_15 ( V_2 , V_55 ) ;
break;
case V_57 :
F_15 ( V_2 , V_55 | V_58 ) ;
break;
case V_34 :
F_22 ( V_2 , V_55 ) ;
break;
}
V_24:
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
static void F_25 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
unsigned long V_60 ;
unsigned long V_22 ;
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_27 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_15 ( V_2 , V_2 -> V_6 . V_61 ?
( V_41 | V_58 ) : V_41 ) ;
}
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
}
int F_29 ( struct V_1 * V_2 , unsigned int V_62 )
{
unsigned long V_60 ;
int V_25 ;
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
if ( ! V_62 ) {
V_25 = F_15 ( V_2 , V_41 ) ;
goto V_24;
}
V_25 = F_10 ( V_2 ) ;
if ( V_25 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_62 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_61 = 0 ;
F_30 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
return V_25 ;
}
int F_31 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_60 ;
int V_25 ;
if ( V_35 & V_63 ) {
if ( ! F_32 ( & V_2 -> V_6 . V_28 ) )
return 0 ;
}
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
V_25 = F_13 ( V_2 , V_35 ) ;
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
return V_25 ;
}
int F_33 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_60 ;
int V_25 ;
if ( V_35 & V_63 ) {
if ( ! F_32 ( & V_2 -> V_6 . V_28 ) )
return 0 ;
}
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
V_25 = F_15 ( V_2 , V_35 ) ;
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
return V_25 ;
}
int F_34 ( struct V_1 * V_2 , int V_35 )
{
unsigned long V_60 ;
int V_25 ;
if ( V_35 & V_63 )
F_35 ( & V_2 -> V_6 . V_28 ) ;
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
V_25 = F_22 ( V_2 , V_35 ) ;
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
return V_25 ;
}
int F_36 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_64 = V_2 -> V_64 ;
unsigned long V_60 ;
bool V_65 = false ;
int error = 0 ;
if ( V_14 != V_36 && V_14 != V_10 )
return - V_27 ;
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
if ( ! V_2 -> V_6 . V_26 && ! V_2 -> V_6 . V_8 ) {
error = - V_29 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_66;
if ( V_14 == V_10 ) {
if ( V_64 ) {
F_37 ( & V_64 -> V_6 . V_67 , - 1 , 0 ) ;
V_65 = ! V_64 -> V_6 . V_68 ;
}
goto V_66;
}
if ( V_64 ) {
F_38 ( & V_64 -> V_6 . V_50 , V_69 ) ;
if ( ! V_64 -> V_6 . V_8
&& ! V_64 -> V_6 . V_68
&& V_64 -> V_6 . V_9 != V_36 )
error = - V_30 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_35 ( & V_64 -> V_6 . V_67 ) ;
F_39 ( & V_64 -> V_6 . V_50 ) ;
if ( error )
goto V_24;
}
V_66:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_26 = 0 ;
V_24:
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
if ( V_65 )
F_40 ( V_64 ) ;
return error ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_33 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
F_42 ( & V_2 -> V_6 . V_43 ) ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
V_2 -> V_6 . V_33 = false ;
}
if ( V_2 -> V_6 . V_9 == V_32
|| V_2 -> V_6 . V_9 == V_70
|| V_2 -> V_6 . V_38 ) {
F_43 ( V_71 ) ;
for (; ; ) {
F_44 ( & V_2 -> V_6 . V_51 , & V_71 ,
V_72 ) ;
if ( V_2 -> V_6 . V_9 != V_32
&& V_2 -> V_6 . V_9 != V_70
&& ! V_2 -> V_6 . V_38 )
break;
F_17 ( & V_2 -> V_6 . V_50 ) ;
F_45 () ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
}
F_46 ( & V_2 -> V_6 . V_51 , & V_71 ) ;
}
}
int F_47 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_48 ( V_2 ) ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
if ( V_2 -> V_6 . V_33
&& V_2 -> V_6 . V_17 == V_34 ) {
F_22 ( V_2 , 0 ) ;
V_25 = 1 ;
}
F_41 ( V_2 ) ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
F_49 ( V_2 ) ;
return V_25 ;
}
void F_50 ( struct V_1 * V_2 , bool V_73 )
{
F_18 ( & V_2 -> V_6 . V_50 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_73 && V_2 -> V_6 . V_33
&& V_2 -> V_6 . V_17 == V_34 ) {
F_48 ( V_2 ) ;
F_22 ( V_2 , 0 ) ;
F_49 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_41 ( V_2 ) ;
V_24:
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
unsigned long V_60 ;
F_26 ( & V_2 -> V_6 . V_50 , V_60 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_52 ( V_2 , L_1 , V_74 ) ;
F_28 ( & V_2 -> V_6 . V_50 , V_60 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_6 . V_50 ) ;
if ( ! V_2 -> V_6 . V_75 )
goto V_24;
V_2 -> V_6 . V_75 = false ;
F_35 ( & V_2 -> V_6 . V_28 ) ;
F_22 ( V_2 , 0 ) ;
V_24:
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_6 . V_50 ) ;
if ( V_2 -> V_6 . V_75 )
goto V_24;
V_2 -> V_6 . V_75 = true ;
if ( F_32 ( & V_2 -> V_6 . V_28 ) )
F_13 ( V_2 , V_58 ) ;
V_24:
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_6 . V_50 ) ;
V_2 -> V_6 . V_40 = 1 ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
if ( F_56 ( V_2 ) )
F_57 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
if ( V_2 -> V_64 )
F_59 ( V_2 -> V_64 ) ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
V_2 -> V_6 . V_76 = 1 ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
static void F_60 ( struct V_1 * V_2 , int V_77 , int V_78 )
{
int V_62 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_62 < 0 ) {
if ( ! V_78 || V_77 >= 0 ) {
F_35 ( & V_2 -> V_6 . V_28 ) ;
F_22 ( V_2 , 0 ) ;
}
}
else {
if ( V_78 && V_77 < 0 )
F_61 ( & V_2 -> V_6 . V_28 ) ;
F_13 ( V_2 , V_58 ) ;
}
}
void F_62 ( struct V_1 * V_2 , int V_62 )
{
int V_77 , V_78 ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
V_77 = V_2 -> V_6 . V_19 ;
V_78 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_62 ;
F_60 ( V_2 , V_77 , V_78 ) ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
void F_63 ( struct V_1 * V_2 , bool V_79 )
{
int V_77 , V_78 ;
F_18 ( & V_2 -> V_6 . V_50 ) ;
V_77 = V_2 -> V_6 . V_19 ;
V_78 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_79 ;
F_60 ( V_2 , V_77 , V_78 ) ;
F_17 ( & V_2 -> V_6 . V_50 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_38 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_65 ( & V_2 -> V_6 . V_28 , 0 ) ;
V_2 -> V_6 . V_26 = 0 ;
F_65 ( & V_2 -> V_6 . V_67 , 0 ) ;
F_66 ( V_2 , false ) ;
V_2 -> V_6 . V_75 = true ;
V_2 -> V_6 . V_33 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_31 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_67 ( & V_2 -> V_6 . V_43 , F_23 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_68 ( & V_2 -> V_6 . V_16 , F_25 ,
( unsigned long ) V_2 ) ;
F_69 ( & V_2 -> V_6 . V_51 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
F_50 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_36 )
F_71 ( V_2 ) ;
if ( V_2 -> V_6 . V_76 && V_2 -> V_64 )
F_72 ( V_2 -> V_64 ) ;
}
