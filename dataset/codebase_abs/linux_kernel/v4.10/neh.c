static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 , struct V_2 , V_1 ) ;
F_3 ( V_3 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
F_5 ( & V_3 -> V_1 ) ;
}
void F_6 ( struct V_2 * V_3 )
{
F_7 ( & V_3 -> V_1 , F_1 ) ;
}
static
int F_8 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
int V_6 ;
V_6 = F_9 ( V_5 -> V_7 , V_8 ,
V_5 -> V_9 ++ ) ;
if ( V_6 < V_8 )
goto V_10;
V_6 = F_10 ( V_5 -> V_7 , V_8 ) ;
if ( V_6 < V_8 )
goto V_10;
return - V_11 ;
V_10:
F_11 ( V_6 , V_5 -> V_7 ) ;
V_3 -> V_12 = V_6 ;
return 0 ;
}
static
void F_12 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
if ( V_3 -> V_12 == 0 )
return;
if ( F_13 ( V_3 -> V_12 , V_5 -> V_7 ) == 0 ) {
F_14 ( V_14 , L_1 ,
V_3 -> V_12 ) ;
F_15 ( 1 ) ;
}
F_16 ( V_3 -> V_12 , V_5 -> V_7 ) ;
V_3 -> V_12 = 0 ;
}
struct V_2 * F_17 ( struct V_4 * V_5 , struct V_16 * V_17 ,
T_1 V_18 , T_2 V_19 ,
T_3 V_20 , void * V_21 )
{
int V_6 ;
unsigned long V_22 ;
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
struct V_2 * V_3 ;
V_3 = F_18 ( sizeof( * V_3 ) , V_23 ) ;
if ( V_3 == NULL ) {
V_6 = - V_24 ;
goto V_25;
}
F_19 ( & V_3 -> V_1 ) ;
F_20 ( & V_3 -> V_26 ) ;
F_21 ( & V_3 -> V_27 , V_28 , ( unsigned long ) V_3 ) ;
V_3 -> V_5 = V_5 ;
V_3 -> V_29 = V_18 ;
V_3 -> V_30 = F_22 ( V_19 ) ;
V_3 -> V_20 = V_20 ;
V_3 -> V_21 = V_21 ;
F_23 ( & V_5 -> V_31 , V_22 ) ;
V_6 = F_8 ( V_5 , V_3 ) ;
if ( V_6 >= 0 ) {
V_17 -> V_32 = V_3 -> V_12 ;
F_24 ( & V_3 -> V_26 , & V_5 -> V_33 ) ;
F_4 ( V_3 ) ;
}
F_25 ( & V_5 -> V_31 , V_22 ) ;
if ( V_6 < 0 )
goto V_34;
return V_3 ;
V_34:
F_3 ( V_3 ) ;
V_25:
F_14 ( V_14 , L_2 , V_6 ) ;
return F_26 ( V_6 ) ;
}
static void F_27 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
F_12 ( V_5 , V_3 ) ;
F_28 ( & V_3 -> V_26 ) ;
}
void F_29 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
unsigned long V_22 ;
F_23 ( & V_5 -> V_31 , V_22 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_6 ( V_3 ) ;
}
void F_31 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
unsigned long V_22 ;
F_23 ( & V_5 -> V_31 , V_22 ) ;
if ( V_3 -> V_12 )
F_32 ( & V_3 -> V_27 ,
V_35 + F_33 ( V_36 ) ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
}
static void F_34 ( struct V_2 * V_3 , struct V_37 * V_38 , T_4 V_39 )
{
(* V_3 -> V_20 )( V_3 -> V_5 , V_3 -> V_21 , V_38 , V_39 ) ;
F_6 ( V_3 ) ;
}
static bool F_35 ( struct V_2 * V_3 , const struct V_37 * V_38 )
{
return V_3 -> V_29 == V_38 -> V_40
&& V_3 -> V_30 == V_38 -> V_41
&& V_3 -> V_12 == V_38 -> V_42 ;
}
static
struct V_2 * F_36 ( struct V_4 * V_5 ,
const struct V_37 * V_38 )
{
struct V_2 * V_3 = NULL , * V_43 ;
unsigned long V_22 ;
F_23 ( & V_5 -> V_31 , V_22 ) ;
F_37 (h, &rc->neh_list, list_node) {
if ( F_35 ( V_43 , V_38 ) ) {
V_3 = V_43 ;
break;
}
}
if ( V_3 )
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
return V_3 ;
}
static
void F_38 ( struct V_4 * V_5 , struct V_37 * V_38 , T_5 V_39 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
struct V_44 * V_45 ;
if ( V_39 == - V_46 )
return;
if ( V_39 < 0 ) {
F_14 ( V_14 , L_3 ,
V_39 ) ;
return;
}
V_45 = F_18 ( sizeof( * V_45 ) , V_47 ) ;
if ( F_39 ( V_45 == NULL ) ) {
F_14 ( V_14 , L_4 ,
V_38 -> V_40 , F_40 ( V_38 -> V_41 ) ,
V_38 -> V_42 ) ;
return;
}
V_45 -> V_5 = F_41 ( V_5 ) ;
V_45 -> V_48 = V_35 ;
V_45 -> type = V_49 ;
V_45 -> V_50 . V_39 = V_39 ;
V_45 -> V_50 . V_38 = V_38 ;
F_42 ( V_45 ) ;
}
static void F_43 ( struct V_4 * V_5 , struct V_37 * V_38 , T_4 V_39 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
struct V_2 * V_3 ;
struct V_37 * V_50 ;
unsigned long V_22 ;
if ( V_38 -> V_42 == 0 ) {
V_50 = F_44 ( V_39 , V_47 ) ;
if ( V_50 ) {
memcpy ( V_50 , V_38 , V_39 ) ;
F_38 ( V_5 , V_50 , V_39 ) ;
} else
F_14 ( V_14 , L_5 ,
V_38 -> V_40 , F_40 ( V_38 -> V_41 ) ,
V_38 -> V_42 , V_39 ) ;
} else {
V_3 = F_36 ( V_5 , V_38 ) ;
if ( V_3 ) {
F_23 ( & V_5 -> V_31 , V_22 ) ;
V_3 -> V_51 = 1 ;
F_45 ( & V_3 -> V_27 ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
F_34 ( V_3 , V_38 , V_39 ) ;
} else
F_46 ( V_14 , L_6 ,
V_38 -> V_40 , F_40 ( V_38 -> V_41 ) ,
V_38 -> V_42 , V_39 ) ;
}
}
void F_47 ( struct V_4 * V_5 , void * V_52 , T_4 V_53 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
void * V_54 ;
struct V_37 * V_38 ;
T_4 V_39 , V_55 , V_56 ;
int V_57 ;
V_54 = V_52 ;
V_39 = V_53 ;
while ( V_39 > 0 ) {
if ( V_39 < sizeof( * V_38 ) ) {
F_14 ( V_14 , L_7
L_8
L_9 , V_39 , sizeof( * V_38 ) ) ;
break;
}
V_38 = V_54 ;
if ( V_5 -> V_58 ) {
V_57 = V_5 -> V_58 ( V_5 , & V_38 , V_39 ,
& V_55 , & V_56 ) ;
if ( V_57 < 0 && V_57 != - V_59 ) {
F_14 ( V_14 , L_10
L_11
L_12 , V_38 -> V_40 ,
F_40 ( V_38 -> V_41 ) ,
V_38 -> V_42 ) ;
break;
}
} else
V_57 = - V_59 ;
if ( V_57 == - V_59 ) {
T_5 V_60 = F_48 ( V_5 , V_38 , V_39 ) ;
if ( V_60 < 0 )
break;
if ( V_60 > V_39 ) {
F_14 ( V_14 , L_13
L_14
L_15 ,
V_38 -> V_40 , F_40 ( V_38 -> V_41 ) ,
V_38 -> V_42 , V_60 , V_39 ) ;
break;
}
V_55 = V_56 = V_60 ;
}
F_43 ( V_5 , V_38 , V_56 ) ;
if ( V_57 == 1 )
F_3 ( V_38 ) ;
V_54 += V_55 ;
V_39 -= V_55 ;
}
}
void F_49 ( struct V_4 * V_5 , int error )
{
struct V_2 * V_3 ;
unsigned long V_22 ;
for (; ; ) {
F_23 ( & V_5 -> V_31 , V_22 ) ;
if ( F_50 ( & V_5 -> V_33 ) ) {
F_25 ( & V_5 -> V_31 , V_22 ) ;
break;
}
V_3 = F_51 ( & V_5 -> V_33 , struct V_2 , V_26 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_34 ( V_3 , NULL , error ) ;
}
}
static void V_28 ( unsigned long V_21 )
{
struct V_2 * V_3 = (struct V_2 * ) V_21 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_22 ;
F_23 ( & V_5 -> V_31 , V_22 ) ;
if ( V_3 -> V_51 ) {
F_25 ( & V_5 -> V_31 , V_22 ) ;
return;
}
if ( V_3 -> V_12 )
F_27 ( V_5 , V_3 ) ;
else
V_3 = NULL ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
if ( V_3 )
F_34 ( V_3 , NULL , - V_61 ) ;
}
void F_52 ( struct V_4 * V_5 )
{
F_53 ( & V_5 -> V_31 ) ;
F_20 ( & V_5 -> V_33 ) ;
F_11 ( 0 , V_5 -> V_7 ) ;
F_11 ( 0xff , V_5 -> V_7 ) ;
V_5 -> V_9 = 1 ;
}
void F_54 ( struct V_4 * V_5 )
{
unsigned long V_22 ;
struct V_2 * V_3 ;
for (; ; ) {
F_23 ( & V_5 -> V_31 , V_22 ) ;
if ( F_50 ( & V_5 -> V_33 ) ) {
F_25 ( & V_5 -> V_31 , V_22 ) ;
break;
}
V_3 = F_51 ( & V_5 -> V_33 , struct V_2 , V_26 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_31 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_6 ( V_3 ) ;
}
}
