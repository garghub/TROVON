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
return F_8 ( V_8 ) ? F_9 ( V_8 ) : 0 ;
}
T_2 F_10 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_11 ( V_10 ) ;
int V_16 = F_4 ( V_5 , & V_15 -> V_17 -> V_6 ) ;
return sprintf ( V_13 , L_2 , V_16 != 0 ) ;
}
T_2 F_12 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_18 )
{
struct V_14 * V_15 = F_11 ( V_10 ) ;
int V_19 ;
if ( V_18 ) {
struct V_3 * V_4 = V_15 -> V_17 ;
char * V_20 = ( char * ) V_13 ;
V_19 = F_13 ( V_20 , & V_20 , 10 ) ;
F_14 ( V_4 -> V_21 ) ;
if ( V_19 )
F_15 ( V_5 , V_4 ) ;
else
F_16 ( V_5 , V_4 ) ;
F_17 ( V_4 -> V_21 ) ;
}
return V_18 ;
}
void F_18 ( struct V_22 * V_23 )
{
F_19 ( & V_23 -> V_24 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
enum V_25 V_26 ;
V_26 = V_4 -> V_27 ( V_23 ) ;
switch ( V_26 ) {
case V_28 :
F_21 ( V_23 ) ;
break;
case V_29 :
F_22 ( V_23 ) ;
F_23 ( V_23 ) ;
break;
case V_30 :
break;
default:
F_24 ( V_31 L_3 , V_26 ) ;
break;
}
}
void F_25 ( unsigned long V_32 )
{
struct V_3 * V_4 = (struct V_3 * ) V_32 ;
unsigned long V_33 , V_34 = 0 ;
struct V_22 * V_35 , * V_36 ;
int V_37 = 0 ;
F_26 ( V_4 -> V_21 , V_33 ) ;
F_27 (rq, tmp, &q->timeout_list, timeout_list) {
if ( F_28 ( V_38 , V_35 -> V_39 ) ) {
F_19 ( & V_35 -> V_24 ) ;
if ( F_29 ( V_35 ) )
continue;
F_20 ( V_35 ) ;
} else if ( ! V_37 || F_30 ( V_34 , V_35 -> V_39 ) ) {
V_34 = V_35 -> V_39 ;
V_37 = 1 ;
}
}
if ( V_37 )
F_31 ( & V_4 -> V_40 , F_32 ( V_34 ) ) ;
F_33 ( V_4 -> V_21 , V_33 ) ;
}
void F_34 ( struct V_22 * V_23 )
{
if ( F_29 ( V_23 ) )
return;
F_18 ( V_23 ) ;
F_20 ( V_23 ) ;
}
void F_23 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_4 ;
unsigned long V_41 ;
if ( ! V_4 -> V_27 )
return;
F_35 ( ! F_36 ( & V_23 -> V_24 ) ) ;
F_35 ( F_4 ( V_42 , & V_23 -> V_43 ) ) ;
if ( ! V_23 -> V_40 )
V_23 -> V_40 = V_4 -> V_44 ;
V_23 -> V_39 = V_38 + V_23 -> V_40 ;
F_37 ( & V_23 -> V_24 , & V_4 -> V_24 ) ;
V_41 = F_32 ( V_23 -> V_39 ) ;
if ( ! F_38 ( & V_4 -> V_40 ) ||
F_39 ( V_41 , V_4 -> V_40 . V_45 ) )
F_31 ( & V_4 -> V_40 , V_41 ) ;
}
void F_40 ( struct V_3 * V_4 )
{
unsigned long V_33 ;
struct V_22 * V_35 , * V_36 ;
F_41 ( V_46 ) ;
if ( ! V_4 -> V_47 )
return;
F_26 ( V_4 -> V_21 , V_33 ) ;
F_42 ( V_4 ) ;
F_43 ( & V_4 -> V_24 , & V_46 ) ;
F_27 (rq, tmp, &list, timeout_list)
F_34 ( V_35 ) ;
F_44 ( & V_46 , & V_4 -> V_24 ) ;
F_33 ( V_4 -> V_21 , V_33 ) ;
}
