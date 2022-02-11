static int F_1 ( int * V_1 )
{
int V_2 ;
F_2 ( & V_3 ) ;
V_2 = F_3 ( & V_4 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_3 ) ;
if ( F_5 ( V_2 < 0 ) )
return V_2 ;
* V_1 = V_2 ;
return 0 ;
}
static void F_6 ( int V_1 )
{
F_2 ( & V_3 ) ;
F_7 ( & V_4 , V_1 ) ;
F_4 ( & V_3 ) ;
}
static int F_8 ( struct V_6 * V_7 ,
unsigned long V_8 ,
unsigned long * V_9 ,
enum V_10 V_11 )
{
int V_12 ;
unsigned long V_13 = 0 , V_14 = 0 ;
unsigned int V_15 = V_16 ;
int V_17 = - 1 ;
struct V_18 * V_19 , * V_20 = V_7 -> V_21 ;
if ( ! V_9 )
return - V_22 ;
if ( ! V_20 )
return - V_22 ;
F_9 (pos, table) {
if ( V_15 == V_19 -> V_23 )
continue;
if ( V_15 != V_16 && V_17 == - 1 )
V_17 = V_15 > V_19 -> V_23 ;
V_15 = V_19 -> V_23 ;
V_13 ++ ;
}
if ( V_13 == 0 )
return - V_22 ;
V_13 -- ;
if ( V_11 == V_24 ) {
* V_9 = V_13 ;
return 0 ;
}
if ( V_11 == V_25 )
V_14 = V_17 ? V_8 : ( V_13 - V_8 ) ;
V_12 = 0 ;
F_9 (pos, table) {
if ( V_15 == V_19 -> V_23 )
continue;
V_15 = V_19 -> V_23 ;
if ( V_11 == V_26 && ( unsigned int ) V_8 == V_15 ) {
* V_9 = V_17 ? V_12 : ( V_13 - V_12 ) ;
return 0 ;
}
if ( V_11 == V_25 && V_14 == V_12 ) {
* V_9 = V_15 ;
return 0 ;
}
V_12 ++ ;
}
return - V_22 ;
}
unsigned long F_10 ( struct V_27 * V_28 ,
unsigned long V_15 )
{
struct V_6 * V_7 = V_28 -> V_29 ;
unsigned long V_30 ;
if ( F_8 ( V_7 , ( unsigned long ) V_15 , & V_30 ,
V_26 ) )
return V_31 ;
return V_30 ;
}
static unsigned long
F_11 ( struct V_6 * V_7 ,
unsigned long V_14 )
{
int V_2 = 0 ;
unsigned long V_15 ;
V_2 = F_8 ( V_7 , V_14 , & V_15 , V_25 ) ;
if ( V_2 )
return 0 ;
return V_15 ;
}
static int F_12 ( struct V_6 * V_7 ,
unsigned long V_32 )
{
unsigned long V_33 , V_34 ;
int V_2 = 0 ;
if ( V_7 -> V_35 == V_32 )
return 0 ;
V_33 = F_11 ( V_7 , V_32 ) ;
if ( ! V_33 )
return - V_22 ;
V_34 = F_13 ( V_7 -> V_36 ) ;
F_2 ( & V_7 -> V_37 ) ;
V_7 -> V_35 = V_32 ;
V_7 -> V_38 = V_33 ;
if ( V_34 > V_33 )
V_2 = F_14 ( V_7 -> V_36 , V_33 ) ;
F_4 ( & V_7 -> V_37 ) ;
return V_2 ;
}
static int F_15 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
struct V_43 * V_44 = V_42 ;
struct V_6 * V_7 = F_16 ( V_40 ) ;
switch ( V_41 ) {
case V_45 :
if ( V_44 -> V_46 > V_7 -> V_38 )
return V_47 ;
case V_48 :
case V_49 :
default:
return V_50 ;
}
}
static int F_17 ( struct V_27 * V_28 ,
unsigned long * V_51 )
{
struct V_6 * V_7 = V_28 -> V_29 ;
unsigned long V_52 = 0 ;
int V_2 ;
V_2 = F_8 ( V_7 , 0 , & V_52 , V_24 ) ;
if ( ! V_2 )
* V_51 = V_52 ;
return V_2 ;
}
static int F_18 ( struct V_27 * V_28 ,
unsigned long * V_51 )
{
struct V_6 * V_7 = V_28 -> V_29 ;
* V_51 = V_7 -> V_35 ;
return 0 ;
}
static int F_19 ( struct V_27 * V_28 ,
unsigned long V_51 )
{
struct V_6 * V_53 = V_28 -> V_29 ;
return F_12 ( V_53 , V_51 ) ;
}
struct V_27 *
F_20 ( struct V_54 * V_55 , const char * V_56 )
{
struct V_27 * V_28 ;
struct V_6 * V_7 = NULL ;
char V_57 [ V_58 ] ;
int V_2 = 0 ;
V_7 = F_21 ( V_55 , sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 )
return F_22 ( - V_59 ) ;
V_7 -> V_55 = V_55 ;
V_7 -> V_36 = F_23 ( V_55 , V_56 ) ;
if ( F_24 ( V_7 -> V_36 ) )
return F_25 ( V_7 -> V_36 ) ;
V_2 = F_1 ( & V_7 -> V_1 ) ;
if ( V_2 )
return F_22 ( - V_22 ) ;
snprintf ( V_57 , sizeof( V_57 ) , L_1 , V_7 -> V_1 ) ;
V_28 = F_26 ( V_57 , V_7 ,
& V_60 ) ;
if ( F_24 ( V_28 ) ) {
F_6 ( V_7 -> V_1 ) ;
return F_22 ( - V_22 ) ;
}
V_7 -> V_28 = V_28 ;
V_7 -> V_61 . V_62 = F_15 ;
V_2 = F_27 ( V_55 , & V_7 -> V_21 ) ;
if ( V_2 ) {
F_6 ( V_7 -> V_1 ) ;
return F_22 ( V_2 ) ;
}
V_7 -> V_35 = 0 ;
V_7 -> V_38 = F_11 ( V_7 , 0 ) ;
F_28 ( V_7 -> V_36 , & V_7 -> V_61 ) ;
return V_28 ;
}
void F_29 ( struct V_27 * V_28 )
{
struct V_6 * V_7 ;
if ( ! V_28 )
return;
V_7 = V_28 -> V_29 ;
F_30 ( V_7 -> V_36 , & V_7 -> V_61 ) ;
F_31 ( V_7 -> V_55 , & V_7 -> V_21 ) ;
F_32 ( V_7 -> V_28 ) ;
F_6 ( V_7 -> V_1 ) ;
}
