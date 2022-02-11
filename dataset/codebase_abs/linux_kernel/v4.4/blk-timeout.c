static int T_1 F_1 ( char * V_1 )
{
return F_2 ( & V_2 , V_1 ) ;
}
int F_3 ( struct V_3 * V_4 )
{
if ( ! F_4 ( V_5 , & V_4 -> V_6 ) )
return 0 ;
return F_5 ( & V_2 , 1 ) ;
}
static int T_1 F_6 ( void )
{
struct V_7 * V_8 = F_7 ( L_1 ,
NULL , & V_2 ) ;
return F_8 ( V_8 ) ;
}
T_2 F_9 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_10 ( V_10 ) ;
int V_16 = F_4 ( V_5 , & V_15 -> V_17 -> V_6 ) ;
return sprintf ( V_13 , L_2 , V_16 != 0 ) ;
}
T_2 F_11 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_18 )
{
struct V_14 * V_15 = F_10 ( V_10 ) ;
int V_19 ;
if ( V_18 ) {
struct V_3 * V_4 = V_15 -> V_17 ;
char * V_20 = ( char * ) V_13 ;
V_19 = F_12 ( V_20 , & V_20 , 10 ) ;
F_13 ( V_4 -> V_21 ) ;
if ( V_19 )
F_14 ( V_5 , V_4 ) ;
else
F_15 ( V_5 , V_4 ) ;
F_16 ( V_4 -> V_21 ) ;
}
return V_18 ;
}
void F_17 ( struct V_22 * V_23 )
{
F_18 ( & V_23 -> V_24 ) ;
}
static void F_19 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
enum V_25 V_26 = V_27 ;
if ( V_4 -> V_28 )
V_26 = V_4 -> V_28 ( V_23 ) ;
switch ( V_26 ) {
case V_29 :
F_20 ( V_23 ) ;
break;
case V_27 :
F_21 ( V_23 ) ;
F_22 ( V_23 ) ;
break;
case V_30 :
break;
default:
F_23 ( V_31 L_3 , V_26 ) ;
break;
}
}
static void F_24 ( struct V_22 * V_32 , unsigned long * V_33 ,
unsigned int * V_34 )
{
if ( F_25 ( V_35 , V_32 -> V_36 ) ) {
F_18 ( & V_32 -> V_24 ) ;
if ( ! F_26 ( V_32 ) )
F_19 ( V_32 ) ;
} else if ( ! * V_34 || F_27 ( * V_33 , V_32 -> V_36 ) ) {
* V_33 = V_32 -> V_36 ;
* V_34 = 1 ;
}
}
void F_28 ( unsigned long V_37 )
{
struct V_3 * V_4 = (struct V_3 * ) V_37 ;
unsigned long V_38 , V_39 = 0 ;
struct V_22 * V_32 , * V_40 ;
int V_34 = 0 ;
F_29 ( V_4 -> V_21 , V_38 ) ;
F_30 (rq, tmp, &q->timeout_list, timeout_list)
F_24 ( V_32 , & V_39 , & V_34 ) ;
if ( V_34 )
F_31 ( & V_4 -> V_41 , F_32 ( V_39 ) ) ;
F_33 ( V_4 -> V_21 , V_38 ) ;
}
void F_34 ( struct V_22 * V_23 )
{
if ( F_26 ( V_23 ) )
return;
if ( V_23 -> V_4 -> V_42 ) {
F_35 ( V_23 , false ) ;
} else {
F_17 ( V_23 ) ;
F_19 ( V_23 ) ;
}
}
unsigned long F_36 ( unsigned long V_41 )
{
unsigned long V_43 ;
V_43 = F_32 ( V_35 + V_44 ) ;
if ( F_27 ( V_41 , V_43 ) )
V_41 = V_43 ;
return V_41 ;
}
void F_21 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
unsigned long V_45 ;
if ( V_23 -> V_46 & V_47 )
return;
if ( ! V_4 -> V_42 && ! V_4 -> V_28 )
return;
F_37 ( ! F_38 ( & V_23 -> V_24 ) ) ;
if ( ! V_23 -> V_41 )
V_23 -> V_41 = V_4 -> V_48 ;
V_23 -> V_36 = V_35 + V_23 -> V_41 ;
if ( ! V_4 -> V_42 )
F_39 ( & V_23 -> V_24 , & V_23 -> V_4 -> V_24 ) ;
V_45 = F_36 ( F_32 ( V_23 -> V_36 ) ) ;
if ( ! F_40 ( & V_4 -> V_41 ) ||
F_41 ( V_45 , V_4 -> V_41 . V_49 ) ) {
unsigned long V_50 = V_4 -> V_41 . V_49 - V_45 ;
if ( ! F_40 ( & V_4 -> V_41 ) || ( V_50 >= V_51 / 2 ) )
F_31 ( & V_4 -> V_41 , V_45 ) ;
}
}
