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
F_21 ( & V_3 -> V_27 ) ;
V_3 -> V_27 . V_28 = V_29 ;
V_3 -> V_27 . V_30 = ( unsigned long ) V_3 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_31 = V_18 ;
V_3 -> V_32 = F_22 ( V_19 ) ;
V_3 -> V_20 = V_20 ;
V_3 -> V_21 = V_21 ;
F_23 ( & V_5 -> V_33 , V_22 ) ;
V_6 = F_8 ( V_5 , V_3 ) ;
if ( V_6 >= 0 ) {
V_17 -> V_34 = V_3 -> V_12 ;
F_24 ( & V_3 -> V_26 , & V_5 -> V_35 ) ;
F_4 ( V_3 ) ;
}
F_25 ( & V_5 -> V_33 , V_22 ) ;
if ( V_6 < 0 )
goto V_36;
return V_3 ;
V_36:
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
F_23 ( & V_5 -> V_33 , V_22 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_6 ( V_3 ) ;
}
void F_31 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
unsigned long V_22 ;
F_23 ( & V_5 -> V_33 , V_22 ) ;
if ( V_3 -> V_12 )
F_32 ( & V_3 -> V_27 ,
V_37 + F_33 ( V_38 ) ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
}
static void F_34 ( struct V_2 * V_3 , struct V_39 * V_40 , T_4 V_41 )
{
(* V_3 -> V_20 )( V_3 -> V_5 , V_3 -> V_21 , V_40 , V_41 ) ;
F_6 ( V_3 ) ;
}
static bool F_35 ( struct V_2 * V_3 , const struct V_39 * V_40 )
{
return V_3 -> V_31 == V_40 -> V_42
&& V_3 -> V_32 == V_40 -> V_43
&& V_3 -> V_12 == V_40 -> V_44 ;
}
static
struct V_2 * F_36 ( struct V_4 * V_5 ,
const struct V_39 * V_40 )
{
struct V_2 * V_3 = NULL , * V_45 ;
unsigned long V_22 ;
F_23 ( & V_5 -> V_33 , V_22 ) ;
F_37 (h, &rc->neh_list, list_node) {
if ( F_35 ( V_45 , V_40 ) ) {
V_3 = V_45 ;
break;
}
}
if ( V_3 )
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
return V_3 ;
}
static
void F_38 ( struct V_4 * V_5 , struct V_39 * V_40 , T_5 V_41 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
struct V_46 * V_47 ;
if ( V_41 == - V_48 )
return;
if ( V_41 < 0 ) {
F_14 ( V_14 , L_3 ,
V_41 ) ;
return;
}
V_47 = F_18 ( sizeof( * V_47 ) , V_49 ) ;
if ( F_39 ( V_47 == NULL ) ) {
F_14 ( V_14 , L_4 ,
V_40 -> V_42 , F_40 ( V_40 -> V_43 ) ,
V_40 -> V_44 ) ;
return;
}
V_47 -> V_5 = F_41 ( V_5 ) ;
V_47 -> V_50 = V_37 ;
V_47 -> type = V_51 ;
V_47 -> V_52 . V_41 = V_41 ;
V_47 -> V_52 . V_40 = V_40 ;
F_42 ( V_47 ) ;
}
static void F_43 ( struct V_4 * V_5 , struct V_39 * V_40 , T_4 V_41 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
struct V_2 * V_3 ;
struct V_39 * V_52 ;
unsigned long V_22 ;
if ( V_40 -> V_44 == 0 ) {
V_52 = F_44 ( V_41 , V_49 ) ;
if ( V_52 ) {
memcpy ( V_52 , V_40 , V_41 ) ;
F_38 ( V_5 , V_52 , V_41 ) ;
} else
F_14 ( V_14 , L_5 ,
V_40 -> V_42 , F_40 ( V_40 -> V_43 ) ,
V_40 -> V_44 , V_41 ) ;
} else {
V_3 = F_36 ( V_5 , V_40 ) ;
if ( V_3 ) {
F_23 ( & V_5 -> V_33 , V_22 ) ;
V_3 -> V_53 = 1 ;
F_45 ( & V_3 -> V_27 ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
F_34 ( V_3 , V_40 , V_41 ) ;
} else
F_46 ( V_14 , L_6 ,
V_40 -> V_42 , F_40 ( V_40 -> V_43 ) ,
V_40 -> V_44 , V_41 ) ;
}
}
void F_47 ( struct V_4 * V_5 , void * V_54 , T_4 V_55 )
{
struct V_13 * V_14 = & V_5 -> V_15 . V_14 ;
void * V_56 ;
struct V_39 * V_40 ;
T_4 V_41 , V_57 , V_58 ;
int V_59 ;
V_56 = V_54 ;
V_41 = V_55 ;
while ( V_41 > 0 ) {
if ( V_41 < sizeof( * V_40 ) ) {
F_14 ( V_14 , L_7
L_8
L_9 , V_41 , sizeof( * V_40 ) ) ;
break;
}
V_40 = V_56 ;
if ( V_5 -> V_60 ) {
V_59 = V_5 -> V_60 ( V_5 , & V_40 , V_41 ,
& V_57 , & V_58 ) ;
if ( V_59 < 0 && V_59 != - V_61 ) {
F_14 ( V_14 , L_10
L_11
L_12 , V_40 -> V_42 ,
F_40 ( V_40 -> V_43 ) ,
V_40 -> V_44 ) ;
break;
}
} else
V_59 = - V_61 ;
if ( V_59 == - V_61 ) {
T_5 V_62 = F_48 ( V_5 , V_40 , V_41 ) ;
if ( V_62 < 0 )
break;
if ( V_62 > V_41 ) {
F_14 ( V_14 , L_13
L_14
L_15 ,
V_40 -> V_42 , F_40 ( V_40 -> V_43 ) ,
V_40 -> V_44 , V_62 , V_41 ) ;
break;
}
V_57 = V_58 = V_62 ;
}
F_43 ( V_5 , V_40 , V_58 ) ;
if ( V_59 == 1 )
F_3 ( V_40 ) ;
V_56 += V_57 ;
V_41 -= V_57 ;
}
}
void F_49 ( struct V_4 * V_5 , int error )
{
struct V_2 * V_3 ;
unsigned long V_22 ;
for (; ; ) {
F_23 ( & V_5 -> V_33 , V_22 ) ;
if ( F_50 ( & V_5 -> V_35 ) ) {
F_25 ( & V_5 -> V_33 , V_22 ) ;
break;
}
V_3 = F_51 ( & V_5 -> V_35 , struct V_2 , V_26 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_34 ( V_3 , NULL , error ) ;
}
}
static void V_29 ( unsigned long V_21 )
{
struct V_2 * V_3 = (struct V_2 * ) V_21 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_22 ;
F_23 ( & V_5 -> V_33 , V_22 ) ;
if ( V_3 -> V_53 ) {
F_25 ( & V_5 -> V_33 , V_22 ) ;
return;
}
if ( V_3 -> V_12 )
F_27 ( V_5 , V_3 ) ;
else
V_3 = NULL ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
if ( V_3 )
F_34 ( V_3 , NULL , - V_63 ) ;
}
void F_52 ( struct V_4 * V_5 )
{
F_53 ( & V_5 -> V_33 ) ;
F_20 ( & V_5 -> V_35 ) ;
F_11 ( 0 , V_5 -> V_7 ) ;
F_11 ( 0xff , V_5 -> V_7 ) ;
V_5 -> V_9 = 1 ;
}
void F_54 ( struct V_4 * V_5 )
{
unsigned long V_22 ;
struct V_2 * V_3 ;
for (; ; ) {
F_23 ( & V_5 -> V_33 , V_22 ) ;
if ( F_50 ( & V_5 -> V_35 ) ) {
F_25 ( & V_5 -> V_33 , V_22 ) ;
break;
}
V_3 = F_51 ( & V_5 -> V_35 , struct V_2 , V_26 ) ;
F_27 ( V_5 , V_3 ) ;
F_25 ( & V_5 -> V_33 , V_22 ) ;
F_30 ( & V_3 -> V_27 ) ;
F_6 ( V_3 ) ;
}
}
