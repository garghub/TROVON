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
return F_7 ( & V_2 , L_1 ) ;
}
T_2 F_8 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_9 ( V_8 ) ;
int V_14 = F_4 ( V_5 , & V_13 -> V_15 -> V_6 ) ;
return sprintf ( V_11 , L_2 , V_14 != 0 ) ;
}
T_2 F_10 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_16 )
{
struct V_12 * V_13 = F_9 ( V_8 ) ;
int V_17 ;
if ( V_16 ) {
struct V_3 * V_4 = V_13 -> V_15 ;
char * V_18 = ( char * ) V_11 ;
V_17 = F_11 ( V_18 , & V_18 , 10 ) ;
F_12 ( V_4 -> V_19 ) ;
if ( V_17 )
F_13 ( V_5 , V_4 ) ;
else
F_14 ( V_5 , V_4 ) ;
F_15 ( V_4 -> V_19 ) ;
}
return V_16 ;
}
void F_16 ( struct V_20 * V_21 )
{
F_17 ( & V_21 -> V_22 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
enum V_23 V_24 ;
V_24 = V_4 -> V_25 ( V_21 ) ;
switch ( V_24 ) {
case V_26 :
F_19 ( V_21 ) ;
break;
case V_27 :
F_20 ( V_21 ) ;
F_21 ( V_21 ) ;
break;
case V_28 :
break;
default:
F_22 ( V_29 L_3 , V_24 ) ;
break;
}
}
void F_23 ( unsigned long V_30 )
{
struct V_3 * V_4 = (struct V_3 * ) V_30 ;
unsigned long V_31 , V_32 = 0 ;
struct V_20 * V_33 , * V_34 ;
int V_35 = 0 ;
F_24 ( V_4 -> V_19 , V_31 ) ;
F_25 (rq, tmp, &q->timeout_list, timeout_list) {
if ( F_26 ( V_36 , V_33 -> V_37 ) ) {
F_17 ( & V_33 -> V_22 ) ;
if ( F_27 ( V_33 ) )
continue;
F_18 ( V_33 ) ;
} else if ( ! V_35 || F_28 ( V_32 , V_33 -> V_37 ) ) {
V_32 = V_33 -> V_37 ;
V_35 = 1 ;
}
}
if ( V_35 )
F_29 ( & V_4 -> V_38 , F_30 ( V_32 ) ) ;
F_31 ( V_4 -> V_19 , V_31 ) ;
}
void F_32 ( struct V_20 * V_21 )
{
if ( F_27 ( V_21 ) )
return;
F_16 ( V_21 ) ;
F_18 ( V_21 ) ;
}
void F_21 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
unsigned long V_39 ;
if ( ! V_4 -> V_25 )
return;
F_33 ( ! F_34 ( & V_21 -> V_22 ) ) ;
F_33 ( F_4 ( V_40 , & V_21 -> V_41 ) ) ;
if ( ! V_21 -> V_38 )
V_21 -> V_38 = V_4 -> V_42 ;
V_21 -> V_37 = V_36 + V_21 -> V_38 ;
F_35 ( & V_21 -> V_22 , & V_4 -> V_22 ) ;
V_39 = F_30 ( V_21 -> V_37 ) ;
if ( ! F_36 ( & V_4 -> V_38 ) ||
F_37 ( V_39 , V_4 -> V_38 . V_43 ) )
F_29 ( & V_4 -> V_38 , V_39 ) ;
}
void F_38 ( struct V_3 * V_4 )
{
unsigned long V_31 ;
struct V_20 * V_33 , * V_34 ;
F_39 ( V_44 ) ;
if ( ! V_4 -> V_45 )
return;
F_24 ( V_4 -> V_19 , V_31 ) ;
F_40 ( V_4 ) ;
F_41 ( & V_4 -> V_22 , & V_44 ) ;
F_25 (rq, tmp, &list, timeout_list)
F_32 ( V_33 ) ;
F_42 ( & V_44 , & V_4 -> V_22 ) ;
F_31 ( V_4 -> V_19 , V_31 ) ;
}
