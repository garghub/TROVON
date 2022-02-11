static int F_1 ( void * V_1 )
{
struct V_2 V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_1 ;
while ( 1 ) {
F_2 ( & V_8 ) ;
while ( F_3 ( & V_7 -> V_9 , & V_3 , 1 ) ) {
F_4 (handler, &ir_raw_handler_list, list)
if ( V_7 -> V_10 -> V_11 &
V_5 -> V_12 || ! V_5 -> V_12 )
V_5 -> V_13 ( V_7 -> V_10 , V_3 ) ;
V_7 -> V_14 = V_3 ;
}
F_5 ( & V_8 ) ;
F_6 ( V_15 ) ;
if ( F_7 () ) {
F_8 ( V_16 ) ;
break;
} else if ( ! F_9 ( & V_7 -> V_9 ) )
F_6 ( V_16 ) ;
F_10 () ;
}
return 0 ;
}
int F_11 ( struct V_17 * V_10 , struct V_2 * V_3 )
{
if ( ! V_10 -> V_7 )
return - V_18 ;
F_12 ( 2 , L_1 ,
F_13 ( V_3 -> V_19 ) , F_14 ( V_3 -> V_20 ) ) ;
if ( ! F_15 ( & V_10 -> V_7 -> V_9 , * V_3 ) ) {
F_16 ( & V_10 -> V_10 , L_2 ) ;
return - V_21 ;
}
return 0 ;
}
int F_17 ( struct V_17 * V_10 , bool V_20 )
{
T_1 V_22 ;
F_18 ( V_3 ) ;
int V_23 = 0 ;
if ( ! V_10 -> V_7 )
return - V_18 ;
V_22 = F_19 () ;
V_3 . V_19 = F_20 ( F_21 ( V_22 , V_10 -> V_7 -> V_24 ) ) ;
V_3 . V_20 = ! V_20 ;
V_23 = F_11 ( V_10 , & V_3 ) ;
V_10 -> V_7 -> V_24 = V_22 ;
if ( ! F_22 ( & V_10 -> V_7 -> V_25 ) ||
F_23 ( V_10 -> V_7 -> V_25 . V_26 ,
V_27 + F_24 ( 15 ) ) ) {
F_25 ( & V_10 -> V_7 -> V_25 ,
V_27 + F_24 ( 15 ) ) ;
}
return V_23 ;
}
int F_26 ( struct V_17 * V_10 , struct V_2 * V_3 )
{
if ( ! V_10 -> V_7 )
return - V_18 ;
if ( V_10 -> V_28 && ! V_3 -> V_20 )
return 0 ;
else if ( V_10 -> V_28 )
F_27 ( V_10 , false ) ;
if ( ! V_10 -> V_7 -> V_29 . V_19 )
V_10 -> V_7 -> V_29 = * V_3 ;
else if ( V_3 -> V_20 == V_10 -> V_7 -> V_29 . V_20 )
V_10 -> V_7 -> V_29 . V_19 += V_3 -> V_19 ;
else {
F_11 ( V_10 , & V_10 -> V_7 -> V_29 ) ;
V_10 -> V_7 -> V_29 = * V_3 ;
}
if ( ! V_3 -> V_20 && V_10 -> V_30 &&
V_10 -> V_7 -> V_29 . V_19 >= V_10 -> V_30 )
F_27 ( V_10 , true ) ;
return 1 ;
}
void F_27 ( struct V_17 * V_10 , bool V_28 )
{
if ( ! V_10 -> V_7 )
return;
F_12 ( 2 , L_3 , V_28 ? L_4 : L_5 ) ;
if ( V_28 ) {
V_10 -> V_7 -> V_29 . V_30 = true ;
F_11 ( V_10 , & V_10 -> V_7 -> V_29 ) ;
F_28 ( & V_10 -> V_7 -> V_29 ) ;
}
if ( V_10 -> V_31 )
V_10 -> V_31 ( V_10 , V_28 ) ;
V_10 -> V_28 = V_28 ;
}
void F_29 ( struct V_17 * V_10 )
{
if ( ! V_10 -> V_7 || ! V_10 -> V_7 -> V_32 )
return;
F_30 ( V_10 -> V_7 -> V_32 ) ;
}
T_2
F_31 ( void )
{
return F_32 ( & V_33 ) ;
}
static int F_33 ( struct V_17 * V_10 , T_2 * V_34 )
{
return 0 ;
}
static void F_34 ( struct V_17 * V_10 , T_2 V_12 )
{
F_2 ( & V_10 -> V_35 ) ;
V_10 -> V_11 &= ~ V_12 ;
F_5 ( & V_10 -> V_35 ) ;
}
int F_35 ( struct V_2 * * V_3 , unsigned int V_36 ,
const struct V_37 * V_38 ,
unsigned int V_39 , T_2 V_1 )
{
bool V_40 ;
T_2 V_41 ;
int V_42 = - V_43 ;
V_41 = F_36 ( V_39 - 1 ) ;
if ( V_38 -> V_44 ) {
if ( ! V_36 -- )
return V_42 ;
if ( V_38 -> V_45 ) {
F_37 ( ( * V_3 ) ++ , 1 , V_38 -> V_44 ) ;
if ( ! V_36 -- )
return V_42 ;
F_37 ( ( * V_3 ) , 0 , V_38 -> V_44 ) ;
} else {
F_37 ( ( * V_3 ) , 1 , V_38 -> V_44 ) ;
}
V_41 >>= 1 ;
} else {
-- ( * V_3 ) ;
}
while ( V_39 && V_41 > 0 ) {
V_40 = ! ( V_1 & V_41 ) ;
if ( V_38 -> V_46 )
V_40 = ! V_40 ;
if ( V_40 == ! ! ( * V_3 ) -> V_20 ) {
( * V_3 ) -> V_19 += V_38 -> clock ;
} else {
if ( ! V_36 -- )
goto V_47;
F_37 ( ++ ( * V_3 ) , V_40 ,
V_38 -> clock ) ;
}
if ( ! V_36 -- )
goto V_47;
F_37 ( ++ ( * V_3 ) , ! V_40 ,
V_38 -> clock ) ;
V_41 >>= 1 ;
}
if ( V_38 -> V_48 ) {
if ( ! ( * V_3 ) -> V_20 )
( * V_3 ) -> V_19 += V_38 -> V_48 ;
else if ( ! V_36 -- )
goto V_47;
else
F_37 ( ++ ( * V_3 ) , 0 ,
V_38 -> V_48 ) ;
}
V_42 = 0 ;
V_47:
++ ( * V_3 ) ;
return V_42 ;
}
int F_38 ( struct V_2 * * V_3 , unsigned int V_36 ,
const struct V_49 * V_38 ,
unsigned int V_39 , T_2 V_1 )
{
int V_41 ;
int V_42 ;
unsigned int V_50 ;
if ( V_38 -> V_51 ) {
V_42 = F_39 ( V_3 , & V_36 , V_38 -> V_51 ,
V_38 -> V_52 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_38 -> V_53 ) {
for ( V_41 = V_39 - 1 ; V_41 >= 0 ; -- V_41 ) {
V_50 = V_38 -> V_54 [ ( V_1 >> V_41 ) & 1 ] ;
V_42 = F_39 ( V_3 , & V_36 ,
V_38 -> V_55 ,
V_50 ) ;
if ( V_42 )
return V_42 ;
}
} else {
for ( V_41 = 0 ; V_41 < V_39 ; ++ V_41 , V_1 >>= 1 ) {
V_50 = V_38 -> V_54 [ V_1 & 1 ] ;
V_42 = F_39 ( V_3 , & V_36 ,
V_38 -> V_55 ,
V_50 ) ;
if ( V_42 )
return V_42 ;
}
}
V_42 = F_39 ( V_3 , & V_36 , V_38 -> V_56 ,
V_38 -> V_48 ) ;
return V_42 ;
}
int F_40 ( struct V_2 * * V_3 , unsigned int V_36 ,
const struct V_57 * V_38 ,
unsigned int V_39 , T_2 V_1 )
{
int V_41 ;
int V_42 = - V_43 ;
unsigned int V_20 ;
if ( ! V_36 -- )
return V_42 ;
F_37 ( ( * V_3 ) ++ , 1 , V_38 -> V_51 ) ;
if ( V_38 -> V_53 ) {
for ( V_41 = V_39 - 1 ; V_41 >= 0 ; -- V_41 ) {
if ( ! V_36 -- )
return V_42 ;
F_37 ( ( * V_3 ) ++ , 0 ,
V_38 -> V_54 ) ;
if ( ! V_36 -- )
return V_42 ;
V_20 = V_38 -> V_55 [ ( V_1 >> V_41 ) & 1 ] ;
F_37 ( ( * V_3 ) ++ , 1 , V_20 ) ;
}
} else {
for ( V_41 = 0 ; V_41 < V_39 ; ++ V_41 , V_1 >>= 1 ) {
if ( ! V_36 -- )
return V_42 ;
F_37 ( ( * V_3 ) ++ , 0 ,
V_38 -> V_54 ) ;
if ( ! V_36 -- )
return V_42 ;
V_20 = V_38 -> V_55 [ V_1 & 1 ] ;
F_37 ( ( * V_3 ) ++ , 1 , V_20 ) ;
}
}
if ( ! V_36 -- )
return V_42 ;
F_37 ( ( * V_3 ) ++ , 0 , V_38 -> V_48 ) ;
return 0 ;
}
int F_41 ( enum V_34 V_58 , T_3 V_59 ,
struct V_2 * V_60 , unsigned int V_36 )
{
struct V_4 * V_5 ;
int V_42 = - V_18 ;
T_2 V_61 = 1ULL << V_58 ;
F_2 ( & V_8 ) ;
F_4 (handler, &ir_raw_handler_list, list) {
if ( V_5 -> V_12 & V_61 && V_5 -> V_62 ) {
V_42 = V_5 -> V_62 ( V_58 , V_59 , V_60 , V_36 ) ;
if ( V_42 >= 0 || V_42 == - V_43 )
break;
}
}
F_5 ( & V_8 ) ;
return V_42 ;
}
static void V_25 ( unsigned long V_63 )
{
struct V_17 * V_10 = (struct V_17 * ) V_63 ;
T_1 V_64 = F_21 ( F_19 () , V_10 -> V_7 -> V_24 ) ;
if ( F_20 ( V_64 ) >= V_10 -> V_30 ) {
F_18 ( V_3 ) ;
V_3 . V_30 = true ;
V_3 . V_19 = F_20 ( V_64 ) ;
F_11 ( V_10 , & V_3 ) ;
} else {
F_25 ( & V_10 -> V_7 -> V_25 ,
V_27 + F_42 ( V_10 -> V_30 -
F_20 ( V_64 ) ) ) ;
}
F_29 ( V_10 ) ;
}
int F_43 ( struct V_17 * V_10 )
{
static bool V_65 ;
if ( ! V_10 )
return - V_18 ;
if ( ! V_65 ) {
F_44 ( L_6 ) ;
V_65 = true ;
}
V_10 -> V_7 = F_45 ( sizeof( * V_10 -> V_7 ) , V_66 ) ;
if ( ! V_10 -> V_7 )
return - V_67 ;
V_10 -> V_7 -> V_10 = V_10 ;
V_10 -> F_33 = F_33 ;
F_46 ( & V_10 -> V_7 -> V_25 , V_25 ,
( unsigned long ) V_10 ) ;
F_47 ( V_10 -> V_7 -> V_9 ) ;
return 0 ;
}
int F_48 ( struct V_17 * V_10 )
{
struct V_4 * V_5 ;
struct V_68 * V_32 ;
if ( V_10 -> V_69 != V_70 ) {
V_32 = F_49 ( F_1 , V_10 -> V_7 , L_7 ,
V_10 -> V_71 ) ;
if ( F_50 ( V_32 ) )
return F_51 ( V_32 ) ;
V_10 -> V_7 -> V_32 = V_32 ;
}
F_2 ( & V_8 ) ;
F_52 ( & V_10 -> V_7 -> V_72 , & V_73 ) ;
F_4 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_74 )
V_5 -> V_74 ( V_10 ) ;
F_5 ( & V_8 ) ;
return 0 ;
}
void F_53 ( struct V_17 * V_10 )
{
if ( ! V_10 )
return;
F_54 ( V_10 -> V_7 ) ;
V_10 -> V_7 = NULL ;
}
void F_55 ( struct V_17 * V_10 )
{
struct V_4 * V_5 ;
if ( ! V_10 || ! V_10 -> V_7 )
return;
F_56 ( V_10 -> V_7 -> V_32 ) ;
F_57 ( & V_10 -> V_7 -> V_25 ) ;
F_2 ( & V_8 ) ;
F_58 ( & V_10 -> V_7 -> V_72 ) ;
F_4 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_75 )
V_5 -> V_75 ( V_10 ) ;
F_5 ( & V_8 ) ;
F_53 ( V_10 ) ;
}
int F_59 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_2 ( & V_8 ) ;
F_52 ( & V_4 -> V_72 , & V_76 ) ;
if ( V_4 -> V_74 )
F_4 (raw, &ir_raw_client_list, list)
V_4 -> V_74 ( V_7 -> V_10 ) ;
F_60 ( V_4 -> V_12 , & V_33 ) ;
F_5 ( & V_8 ) ;
return 0 ;
}
void F_61 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
T_2 V_12 = V_4 -> V_12 ;
F_2 ( & V_8 ) ;
F_58 ( & V_4 -> V_72 ) ;
F_4 (raw, &ir_raw_client_list, list) {
F_34 ( V_7 -> V_10 , V_12 ) ;
if ( V_4 -> V_75 )
V_4 -> V_75 ( V_7 -> V_10 ) ;
}
F_62 ( V_12 , & V_33 ) ;
F_5 ( & V_8 ) ;
}
