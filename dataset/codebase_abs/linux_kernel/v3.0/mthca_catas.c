static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( V_6 ) ;
int V_7 ;
F_3 ( & V_8 ) ;
F_4 ( & V_9 ) ;
F_5 ( & V_10 , & V_6 ) ;
F_6 ( & V_9 ) ;
F_7 (dev, tmpdev, &tlist, catas_err.list) {
struct V_11 * V_12 = V_4 -> V_12 ;
V_7 = F_8 ( V_4 -> V_12 ) ;
if ( V_7 )
F_9 ( V_13 L_1 ,
F_10 ( V_12 ) , V_7 ) ;
else {
struct V_3 * V_14 = F_11 ( V_12 ) ;
F_12 ( V_14 , L_2 ) ;
}
}
F_13 ( & V_8 ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_15 V_16 ;
unsigned long V_17 ;
const char * type ;
int V_18 ;
V_16 . V_19 = & V_4 -> V_20 ;
V_16 . V_16 = V_21 ;
V_16 . V_22 . V_23 = 0 ;
V_4 -> V_24 = false ;
F_15 ( & V_16 ) ;
switch ( F_16 ( F_17 ( V_4 -> V_25 . V_26 ) ) >> 24 ) {
case V_27 :
type = L_3 ;
break;
case V_28 :
type = L_4 ;
break;
case V_29 :
type = L_5 ;
break;
case V_30 :
type = L_6 ;
break;
default:
type = L_7 ;
break;
}
F_18 ( V_4 , L_8 , type ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_25 . V_31 ; ++ V_18 )
F_18 ( V_4 , L_9 ,
V_18 , F_16 ( F_17 ( V_4 -> V_25 . V_26 + V_18 ) ) ) ;
if ( V_32 )
return;
F_19 ( & V_9 , V_17 ) ;
F_20 ( & V_4 -> V_25 . V_33 , & V_10 ) ;
F_21 ( V_34 , & V_35 ) ;
F_22 ( & V_9 , V_17 ) ;
}
static void F_23 ( unsigned long V_36 )
{
struct V_3 * V_4 = (struct V_3 * ) V_36 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_25 . V_31 ; ++ V_18 )
if ( F_17 ( V_4 -> V_25 . V_26 + V_18 ) ) {
F_14 ( V_4 ) ;
return;
}
F_24 ( & V_4 -> V_25 . V_37 ,
F_25 ( V_38 + V_39 ) ) ;
}
void F_26 ( struct V_3 * V_4 )
{
T_1 V_40 ;
F_27 ( & V_4 -> V_25 . V_37 ) ;
V_4 -> V_25 . V_26 = NULL ;
V_40 = F_28 ( V_4 -> V_12 , 0 ) +
( ( F_29 ( V_4 -> V_12 , 0 ) - 1 ) &
V_4 -> V_25 . V_40 ) ;
V_4 -> V_25 . V_26 = F_30 ( V_40 , V_4 -> V_25 . V_31 * 4 ) ;
if ( ! V_4 -> V_25 . V_26 ) {
F_31 ( V_4 , L_10
L_11 , ( unsigned long long ) V_40 ,
V_4 -> V_25 . V_31 * 4 ) ;
return;
}
V_4 -> V_25 . V_37 . V_41 = ( unsigned long ) V_4 ;
V_4 -> V_25 . V_37 . V_42 = F_23 ;
V_4 -> V_25 . V_37 . V_43 = V_38 + V_39 ;
F_32 ( & V_4 -> V_25 . V_33 ) ;
F_33 ( & V_4 -> V_25 . V_37 ) ;
}
void F_34 ( struct V_3 * V_4 )
{
F_35 ( & V_4 -> V_25 . V_37 ) ;
if ( V_4 -> V_25 . V_26 )
F_36 ( V_4 -> V_25 . V_26 ) ;
F_4 ( & V_9 ) ;
F_37 ( & V_4 -> V_25 . V_33 ) ;
F_6 ( & V_9 ) ;
}
int T_2 F_38 ( void )
{
F_39 ( & V_35 , F_1 ) ;
V_34 = F_40 ( L_12 ) ;
if ( ! V_34 )
return - V_44 ;
return 0 ;
}
void F_41 ( void )
{
F_42 ( V_34 ) ;
}
