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
static int F_13 ( struct V_1 * V_2 , int V_36 )
{
int (* F_14)( struct V_1 * );
int V_25 ;
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
V_25 = F_15 ( V_2 , V_36 ) ;
goto V_24;
}
if ( V_36 & V_42 ) {
V_2 -> V_6 . V_17 = V_38 ;
if ( ! V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_34 = true ;
F_16 ( V_43 , & V_2 -> V_6 . V_44 ) ;
}
goto V_24;
}
V_2 -> V_6 . V_39 = true ;
if ( V_2 -> V_45 )
F_14 = V_2 -> V_45 -> V_46 . V_47 ;
else if ( V_2 -> type && V_2 -> type -> V_48 )
F_14 = V_2 -> type -> V_48 -> V_47 ;
else if ( V_2 -> V_49 && V_2 -> V_49 -> V_48 )
F_14 = V_2 -> V_49 -> V_48 -> V_47 ;
else if ( V_2 -> V_50 && V_2 -> V_50 -> V_48 )
F_14 = V_2 -> V_50 -> V_48 -> V_47 ;
else
F_14 = NULL ;
if ( F_14 ) {
if ( V_2 -> V_6 . V_51 )
F_17 ( & V_2 -> V_6 . V_52 ) ;
else
F_18 ( & V_2 -> V_6 . V_52 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_6 . V_51 )
F_19 ( & V_2 -> V_6 . V_52 ) ;
else
F_20 ( & V_2 -> V_6 . V_52 ) ;
}
V_2 -> V_6 . V_39 = false ;
F_21 ( & V_2 -> V_6 . V_53 ) ;
V_24:
return V_25 ;
}
static int F_22 ( int (* F_23)( struct V_1 * ) , struct V_1 * V_2 )
__releases( &dev->power.lock
static int F_15 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static int F_24 ( struct V_1 * V_2 , int V_36 )
__releases( &dev->power.lock
static void F_25 ( struct V_54 * V_44 )
{
struct V_1 * V_2 = F_26 ( V_44 , struct V_1 , V_6 . V_44 ) ;
enum V_55 V_56 ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
if ( ! V_2 -> V_6 . V_34 )
goto V_24;
V_56 = V_2 -> V_6 . V_17 ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_34 = false ;
switch ( V_56 ) {
case V_18 :
break;
case V_38 :
F_13 ( V_2 , V_57 ) ;
break;
case V_58 :
F_15 ( V_2 , V_57 ) ;
break;
case V_59 :
F_15 ( V_2 , V_57 | V_60 ) ;
break;
case V_35 :
F_24 ( V_2 , V_57 ) ;
break;
}
V_24:
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
static void F_27 ( unsigned long V_61 )
{
struct V_1 * V_2 = (struct V_1 * ) V_61 ;
unsigned long V_62 ;
unsigned long V_22 ;
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
V_22 = V_2 -> V_6 . V_15 ;
if ( V_22 > 0 && ! F_29 ( V_22 , V_4 ) ) {
V_2 -> V_6 . V_15 = 0 ;
F_15 ( V_2 , V_2 -> V_6 . V_63 ?
( V_42 | V_60 ) : V_42 ) ;
}
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_64 )
{
unsigned long V_62 ;
int V_25 ;
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
if ( ! V_64 ) {
V_25 = F_15 ( V_2 , V_42 ) ;
goto V_24;
}
V_25 = F_10 ( V_2 ) ;
if ( V_25 )
goto V_24;
F_5 ( V_2 ) ;
V_2 -> V_6 . V_15 = V_4 + F_8 ( V_64 ) ;
V_2 -> V_6 . V_15 += ! V_2 -> V_6 . V_15 ;
V_2 -> V_6 . V_63 = 0 ;
F_32 ( & V_2 -> V_6 . V_16 , V_2 -> V_6 . V_15 ) ;
V_24:
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
return V_25 ;
}
int F_33 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_62 ;
int V_25 ;
if ( V_36 & V_65 ) {
if ( ! F_34 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
V_25 = F_13 ( V_2 , V_36 ) ;
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
return V_25 ;
}
int F_35 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_62 ;
int V_25 ;
if ( V_36 & V_65 ) {
if ( ! F_34 ( & V_2 -> V_6 . V_29 ) )
return 0 ;
}
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
V_25 = F_15 ( V_2 , V_36 ) ;
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
return V_25 ;
}
int F_36 ( struct V_1 * V_2 , int V_36 )
{
unsigned long V_62 ;
int V_25 ;
if ( V_36 & V_65 )
F_37 ( & V_2 -> V_6 . V_29 ) ;
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
V_25 = F_24 ( V_2 , V_36 ) ;
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
return V_25 ;
}
int F_38 ( struct V_1 * V_2 , unsigned int V_14 )
{
struct V_1 * V_66 = V_2 -> V_66 ;
unsigned long V_62 ;
bool V_67 = false ;
int error = 0 ;
if ( V_14 != V_37 && V_14 != V_10 )
return - V_27 ;
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
if ( ! V_2 -> V_6 . V_26 && ! V_2 -> V_6 . V_8 ) {
error = - V_30 ;
goto V_24;
}
if ( V_2 -> V_6 . V_9 == V_14 )
goto V_68;
if ( V_14 == V_10 ) {
if ( V_66 ) {
F_39 ( & V_66 -> V_6 . V_69 , - 1 , 0 ) ;
V_67 = ! V_66 -> V_6 . V_70 ;
}
goto V_68;
}
if ( V_66 ) {
F_40 ( & V_66 -> V_6 . V_52 , V_71 ) ;
if ( ! V_66 -> V_6 . V_8
&& ! V_66 -> V_6 . V_70
&& V_66 -> V_6 . V_9 != V_37 )
error = - V_31 ;
else if ( V_2 -> V_6 . V_9 == V_10 )
F_37 ( & V_66 -> V_6 . V_69 ) ;
F_17 ( & V_66 -> V_6 . V_52 ) ;
if ( error )
goto V_24;
}
V_68:
F_2 ( V_2 , V_14 ) ;
V_2 -> V_6 . V_26 = 0 ;
V_24:
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
if ( V_67 )
F_41 ( V_66 ) ;
return error ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_6 . V_34 ) {
V_2 -> V_6 . V_17 = V_18 ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
F_43 ( & V_2 -> V_6 . V_44 ) ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_2 -> V_6 . V_34 = false ;
}
if ( V_2 -> V_6 . V_9 == V_33
|| V_2 -> V_6 . V_9 == V_72
|| V_2 -> V_6 . V_39 ) {
F_44 ( V_73 ) ;
for (; ; ) {
F_45 ( & V_2 -> V_6 . V_53 , & V_73 ,
V_74 ) ;
if ( V_2 -> V_6 . V_9 != V_33
&& V_2 -> V_6 . V_9 != V_72
&& ! V_2 -> V_6 . V_39 )
break;
F_18 ( & V_2 -> V_6 . V_52 ) ;
F_46 () ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
}
F_47 ( & V_2 -> V_6 . V_53 , & V_73 ) ;
}
}
int F_48 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
F_49 ( V_2 ) ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
if ( V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_24 ( V_2 , 0 ) ;
V_25 = 1 ;
}
F_42 ( V_2 ) ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
F_50 ( V_2 ) ;
return V_25 ;
}
void F_51 ( struct V_1 * V_2 , bool V_75 )
{
F_20 ( & V_2 -> V_6 . V_52 ) ;
if ( V_2 -> V_6 . V_8 > 0 ) {
V_2 -> V_6 . V_8 ++ ;
goto V_24;
}
if ( V_75 && V_2 -> V_6 . V_34
&& V_2 -> V_6 . V_17 == V_35 ) {
F_49 ( V_2 ) ;
F_24 ( V_2 , 0 ) ;
F_50 ( V_2 ) ;
}
if ( ! V_2 -> V_6 . V_8 ++ )
F_42 ( V_2 ) ;
V_24:
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_28 ( & V_2 -> V_6 . V_52 , V_62 ) ;
if ( V_2 -> V_6 . V_8 > 0 )
V_2 -> V_6 . V_8 -- ;
else
F_53 ( V_2 , L_1 , V_76 ) ;
F_30 ( & V_2 -> V_6 . V_52 , V_62 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_6 . V_52 ) ;
if ( ! V_2 -> V_6 . V_77 )
goto V_24;
V_2 -> V_6 . V_77 = false ;
F_37 ( & V_2 -> V_6 . V_29 ) ;
F_24 ( V_2 , 0 ) ;
V_24:
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_6 . V_52 ) ;
if ( V_2 -> V_6 . V_77 )
goto V_24;
V_2 -> V_6 . V_77 = true ;
if ( F_34 ( & V_2 -> V_6 . V_29 ) )
F_13 ( V_2 , V_60 ) ;
V_24:
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_2 -> V_6 . V_41 = 1 ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
if ( F_57 ( V_2 ) )
F_58 ( V_2 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_66 )
F_60 ( V_2 -> V_66 ) ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_2 -> V_6 . V_51 = 1 ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
static void F_61 ( struct V_1 * V_2 , int V_78 , int V_79 )
{
int V_64 = V_2 -> V_6 . V_19 ;
if ( V_2 -> V_6 . V_23 && V_64 < 0 ) {
if ( ! V_79 || V_78 >= 0 ) {
F_37 ( & V_2 -> V_6 . V_29 ) ;
F_24 ( V_2 , 0 ) ;
}
}
else {
if ( V_79 && V_78 < 0 )
F_62 ( & V_2 -> V_6 . V_29 ) ;
F_13 ( V_2 , V_60 ) ;
}
}
void F_63 ( struct V_1 * V_2 , int V_64 )
{
int V_78 , V_79 ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_78 = V_2 -> V_6 . V_19 ;
V_79 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_19 = V_64 ;
F_61 ( V_2 , V_78 , V_79 ) ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
void F_64 ( struct V_1 * V_2 , bool V_80 )
{
int V_78 , V_79 ;
F_20 ( & V_2 -> V_6 . V_52 ) ;
V_78 = V_2 -> V_6 . V_19 ;
V_79 = V_2 -> V_6 . V_23 ;
V_2 -> V_6 . V_23 = V_80 ;
F_61 ( V_2 , V_78 , V_79 ) ;
F_18 ( & V_2 -> V_6 . V_52 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_9 = V_10 ;
V_2 -> V_6 . V_39 = false ;
V_2 -> V_6 . V_8 = 1 ;
F_66 ( & V_2 -> V_6 . V_29 , 0 ) ;
V_2 -> V_6 . V_26 = 0 ;
F_66 ( & V_2 -> V_6 . V_69 , 0 ) ;
F_67 ( V_2 , false ) ;
V_2 -> V_6 . V_77 = true ;
V_2 -> V_6 . V_34 = false ;
V_2 -> V_6 . V_17 = V_18 ;
V_2 -> V_6 . V_32 = false ;
V_2 -> V_6 . V_7 = V_4 ;
F_68 ( & V_2 -> V_6 . V_44 , F_25 ) ;
V_2 -> V_6 . V_15 = 0 ;
F_69 ( & V_2 -> V_6 . V_16 , F_27 ,
( unsigned long ) V_2 ) ;
F_70 ( & V_2 -> V_6 . V_53 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
F_51 ( V_2 , false ) ;
if ( V_2 -> V_6 . V_9 == V_37 )
F_72 ( V_2 ) ;
if ( V_2 -> V_6 . V_51 && V_2 -> V_66 )
F_73 ( V_2 -> V_66 ) ;
}
