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
if ( V_4 -> V_30 )
F_20 ( V_23 ) ;
else
F_21 ( V_23 ) ;
break;
case V_27 :
F_22 ( V_23 ) ;
F_23 ( V_23 ) ;
break;
case V_31 :
break;
default:
F_24 ( V_32 L_3 , V_26 ) ;
break;
}
}
void F_25 ( struct V_22 * V_33 , unsigned long * V_34 ,
unsigned int * V_35 )
{
if ( F_26 ( V_36 , V_33 -> V_37 ) ) {
F_18 ( & V_33 -> V_24 ) ;
if ( ! F_27 ( V_33 ) )
F_19 ( V_33 ) ;
} else if ( ! * V_35 || F_28 ( * V_34 , V_33 -> V_37 ) ) {
* V_34 = V_33 -> V_37 ;
* V_35 = 1 ;
}
}
void F_29 ( unsigned long V_38 )
{
struct V_3 * V_4 = (struct V_3 * ) V_38 ;
unsigned long V_39 , V_40 = 0 ;
struct V_22 * V_33 , * V_41 ;
int V_35 = 0 ;
F_30 ( V_4 -> V_21 , V_39 ) ;
F_31 (rq, tmp, &q->timeout_list, timeout_list)
F_25 ( V_33 , & V_40 , & V_35 ) ;
if ( V_35 )
F_32 ( & V_4 -> V_42 , F_33 ( V_40 ) ) ;
F_34 ( V_4 -> V_21 , V_39 ) ;
}
void F_35 ( struct V_22 * V_23 )
{
if ( F_27 ( V_23 ) )
return;
F_17 ( V_23 ) ;
F_19 ( V_23 ) ;
}
unsigned long F_36 ( unsigned long V_42 )
{
unsigned long V_43 ;
V_43 = F_33 ( V_36 + V_44 ) ;
if ( F_28 ( V_42 , V_43 ) )
V_42 = V_43 ;
return V_42 ;
}
void F_22 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
unsigned long V_45 ;
if ( ! V_4 -> V_28 )
return;
F_37 ( ! F_38 ( & V_23 -> V_24 ) ) ;
if ( ! V_23 -> V_42 )
V_23 -> V_42 = V_4 -> V_46 ;
V_23 -> V_37 = V_36 + V_23 -> V_42 ;
if ( ! V_4 -> V_30 )
F_39 ( & V_23 -> V_24 , & V_23 -> V_4 -> V_24 ) ;
V_45 = F_36 ( F_33 ( V_23 -> V_37 ) ) ;
if ( ! F_40 ( & V_4 -> V_42 ) ||
F_41 ( V_45 , V_4 -> V_42 . V_47 ) ) {
unsigned long V_48 = V_4 -> V_42 . V_47 - V_45 ;
if ( ! F_40 ( & V_4 -> V_42 ) || ( V_48 >= V_49 / 2 ) )
F_32 ( & V_4 -> V_42 , V_45 ) ;
}
}
