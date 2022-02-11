static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
unsigned long * V_4 ,
enum V_5 V_6 )
{
int V_7 ;
unsigned long V_8 = 0 , V_9 = 0 ;
unsigned int V_10 = V_11 ;
int V_12 = - 1 ;
struct V_13 * V_14 , * V_15 = V_2 -> V_16 ;
if ( ! V_4 )
return - V_17 ;
if ( ! V_15 )
return - V_17 ;
F_2 (pos, table) {
if ( V_10 == V_14 -> V_18 )
continue;
if ( V_10 != V_11 && V_12 == - 1 )
V_12 = V_10 > V_14 -> V_18 ;
V_10 = V_14 -> V_18 ;
V_8 ++ ;
}
if ( V_8 == 0 )
return - V_17 ;
V_8 -- ;
if ( V_6 == V_19 ) {
* V_4 = V_8 ;
return 0 ;
}
if ( V_6 == V_20 )
V_9 = V_12 ? V_3 : ( V_8 - V_3 ) ;
V_7 = 0 ;
F_2 (pos, table) {
if ( V_10 == V_14 -> V_18 )
continue;
V_10 = V_14 -> V_18 ;
if ( V_6 == V_21 && ( unsigned int ) V_3 == V_10 ) {
* V_4 = V_12 ? V_7 : ( V_8 - V_7 ) ;
return 0 ;
}
if ( V_6 == V_20 && V_9 == V_7 ) {
* V_4 = V_10 ;
return 0 ;
}
V_7 ++ ;
}
return - V_17 ;
}
unsigned long F_3 ( struct V_22 * V_23 ,
unsigned long V_10 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_25 ;
if ( F_1 ( V_2 , ( unsigned long ) V_10 , & V_25 ,
V_21 ) )
return V_26 ;
return V_25 ;
}
static unsigned long
F_4 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
int V_27 = 0 ;
unsigned long V_10 ;
V_27 = F_1 ( V_2 , V_9 , & V_10 , V_20 ) ;
if ( V_27 )
return 0 ;
return V_10 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
unsigned long V_29 , V_30 ;
int V_27 = 0 ;
if ( V_2 -> V_31 == V_28 )
return 0 ;
V_29 = F_4 ( V_2 , V_28 ) ;
if ( ! V_29 )
return - V_17 ;
V_30 = F_6 ( V_2 -> V_32 ) ;
F_7 ( & V_2 -> V_33 ) ;
V_2 -> V_31 = V_28 ;
V_2 -> V_34 = V_29 ;
if ( V_30 > V_29 )
V_27 = F_8 ( V_2 -> V_32 , V_29 ) ;
F_9 ( & V_2 -> V_33 ) ;
return V_27 ;
}
static int F_10 ( struct V_35 * V_36 ,
unsigned long V_37 , void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_1 * V_2 = F_11 ( V_36 ) ;
switch ( V_37 ) {
case V_41 :
if ( V_40 -> V_42 > V_2 -> V_34 )
return V_43 ;
case V_44 :
case V_45 :
default:
return V_46 ;
}
}
static int F_12 ( struct V_22 * V_23 ,
unsigned long * V_47 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
unsigned long V_48 = 0 ;
int V_27 ;
V_27 = F_1 ( V_2 , 0 , & V_48 , V_19 ) ;
if ( ! V_27 )
* V_47 = V_48 ;
return V_27 ;
}
static int F_13 ( struct V_22 * V_23 ,
unsigned long * V_47 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
* V_47 = V_2 -> V_31 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 ,
unsigned long V_47 )
{
struct V_1 * V_49 = V_23 -> V_24 ;
return F_5 ( V_49 , V_47 ) ;
}
struct V_22 *
F_15 ( struct V_50 * V_51 , const char * V_52 )
{
struct V_22 * V_23 ;
struct V_1 * V_2 = NULL ;
char V_53 [ V_54 ] ;
int V_27 = 0 ;
V_2 = F_16 ( V_51 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return F_17 ( - V_56 ) ;
F_18 ( & V_2 -> V_33 ) ;
V_2 -> V_51 = V_51 ;
V_2 -> V_32 = F_19 ( V_51 , V_52 ) ;
if ( F_20 ( V_2 -> V_32 ) )
return F_21 ( V_2 -> V_32 ) ;
V_27 = F_22 ( & V_57 , 0 , 0 , V_55 ) ;
if ( V_27 < 0 )
return F_17 ( V_27 ) ;
V_2 -> V_58 = V_27 ;
snprintf ( V_53 , sizeof( V_53 ) , L_1 , V_2 -> V_58 ) ;
V_23 = F_23 ( V_53 , V_2 ,
& V_59 ) ;
if ( F_20 ( V_23 ) ) {
F_24 ( & V_57 , V_2 -> V_58 ) ;
return F_17 ( - V_17 ) ;
}
V_2 -> V_23 = V_23 ;
V_2 -> V_60 . V_61 = F_10 ;
V_27 = F_25 ( V_51 , & V_2 -> V_16 ) ;
if ( V_27 ) {
F_24 ( & V_57 , V_2 -> V_58 ) ;
return F_17 ( V_27 ) ;
}
V_2 -> V_31 = 0 ;
V_2 -> V_34 = F_4 ( V_2 , 0 ) ;
F_26 ( V_2 -> V_32 , & V_2 -> V_60 ) ;
return V_23 ;
}
void F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
if ( ! V_23 )
return;
V_2 = V_23 -> V_24 ;
F_28 ( V_2 -> V_32 , & V_2 -> V_60 ) ;
F_29 ( V_2 -> V_51 , & V_2 -> V_16 ) ;
F_30 ( V_2 -> V_23 ) ;
F_24 ( & V_57 , V_2 -> V_58 ) ;
}
