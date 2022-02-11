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
int F_17 ( struct V_17 * V_10 , enum V_22 type )
{
T_1 V_23 ;
T_2 V_24 ;
F_18 ( V_3 ) ;
int V_25 = 0 ;
int V_26 ;
if ( ! V_10 -> V_7 )
return - V_18 ;
V_23 = F_19 () ;
V_24 = F_20 ( F_21 ( V_23 , V_10 -> V_7 -> V_27 ) ) ;
V_26 = F_22 ( V_10 -> V_28 -> V_29 [ V_30 ] ) ;
if ( V_24 > V_26 || ! V_10 -> V_7 -> V_31 )
type |= V_32 ;
else
V_3 . V_19 = V_24 ;
if ( type & V_32 )
F_23 ( V_10 ) ;
else if ( V_10 -> V_7 -> V_31 & V_33 ) {
V_3 . V_20 = false ;
V_25 = F_11 ( V_10 , & V_3 ) ;
} else if ( V_10 -> V_7 -> V_31 & V_34 ) {
V_3 . V_20 = true ;
V_25 = F_11 ( V_10 , & V_3 ) ;
} else
return 0 ;
V_10 -> V_7 -> V_27 = V_23 ;
V_10 -> V_7 -> V_31 = type ;
return V_25 ;
}
int F_24 ( struct V_17 * V_10 , struct V_2 * V_3 )
{
if ( ! V_10 -> V_7 )
return - V_18 ;
if ( V_10 -> V_35 && ! V_3 -> V_20 )
return 0 ;
else if ( V_10 -> V_35 )
F_25 ( V_10 , false ) ;
if ( ! V_10 -> V_7 -> V_36 . V_19 )
V_10 -> V_7 -> V_36 = * V_3 ;
else if ( V_3 -> V_20 == V_10 -> V_7 -> V_36 . V_20 )
V_10 -> V_7 -> V_36 . V_19 += V_3 -> V_19 ;
else {
F_11 ( V_10 , & V_10 -> V_7 -> V_36 ) ;
V_10 -> V_7 -> V_36 = * V_3 ;
}
if ( ! V_3 -> V_20 && V_10 -> V_37 &&
V_10 -> V_7 -> V_36 . V_19 >= V_10 -> V_37 )
F_25 ( V_10 , true ) ;
return 1 ;
}
void F_25 ( struct V_17 * V_10 , bool V_35 )
{
if ( ! V_10 -> V_7 )
return;
F_12 ( 2 , L_3 , V_35 ? L_4 : L_5 ) ;
if ( V_35 ) {
V_10 -> V_7 -> V_36 . V_37 = true ;
F_11 ( V_10 , & V_10 -> V_7 -> V_36 ) ;
F_26 ( & V_10 -> V_7 -> V_36 ) ;
}
if ( V_10 -> V_38 )
V_10 -> V_38 ( V_10 , V_35 ) ;
V_10 -> V_35 = V_35 ;
}
void F_27 ( struct V_17 * V_10 )
{
if ( ! V_10 -> V_7 || ! V_10 -> V_7 -> V_39 )
return;
F_28 ( V_10 -> V_7 -> V_39 ) ;
}
T_3
F_29 ( void )
{
return F_30 ( & V_40 ) ;
}
static int F_31 ( struct V_17 * V_10 , T_3 * V_41 )
{
return 0 ;
}
static void F_32 ( struct V_17 * V_10 , T_3 V_12 )
{
F_2 ( & V_10 -> V_42 ) ;
V_10 -> V_11 &= ~ V_12 ;
F_5 ( & V_10 -> V_42 ) ;
}
int F_33 ( struct V_2 * * V_3 , unsigned int V_43 ,
const struct V_44 * V_45 ,
unsigned int V_46 , T_3 V_1 )
{
bool V_47 ;
T_3 V_48 ;
int V_49 = - V_50 ;
V_48 = F_34 ( V_46 - 1 ) ;
if ( V_45 -> V_51 ) {
if ( ! V_43 -- )
return V_49 ;
if ( V_45 -> V_52 ) {
F_35 ( ( * V_3 ) ++ , 1 , V_45 -> V_51 ) ;
if ( ! V_43 -- )
return V_49 ;
F_35 ( ( * V_3 ) , 0 , V_45 -> V_51 ) ;
} else {
F_35 ( ( * V_3 ) , 1 , V_45 -> V_51 ) ;
}
V_48 >>= 1 ;
} else {
-- ( * V_3 ) ;
}
while ( V_46 && V_48 > 0 ) {
V_47 = ! ( V_1 & V_48 ) ;
if ( V_45 -> V_53 )
V_47 = ! V_47 ;
if ( V_47 == ! ! ( * V_3 ) -> V_20 ) {
( * V_3 ) -> V_19 += V_45 -> clock ;
} else {
if ( ! V_43 -- )
goto V_54;
F_35 ( ++ ( * V_3 ) , V_47 ,
V_45 -> clock ) ;
}
if ( ! V_43 -- )
goto V_54;
F_35 ( ++ ( * V_3 ) , ! V_47 ,
V_45 -> clock ) ;
V_48 >>= 1 ;
}
if ( V_45 -> V_55 ) {
if ( ! ( * V_3 ) -> V_20 )
( * V_3 ) -> V_19 += V_45 -> V_55 ;
else if ( ! V_43 -- )
goto V_54;
else
F_35 ( ++ ( * V_3 ) , 0 ,
V_45 -> V_55 ) ;
}
V_49 = 0 ;
V_54:
++ ( * V_3 ) ;
return V_49 ;
}
int F_36 ( struct V_2 * * V_3 , unsigned int V_43 ,
const struct V_56 * V_45 ,
unsigned int V_46 , T_3 V_1 )
{
int V_48 ;
int V_49 ;
unsigned int V_57 ;
if ( V_45 -> V_58 ) {
V_49 = F_37 ( V_3 , & V_43 , V_45 -> V_58 ,
V_45 -> V_59 ) ;
if ( V_49 )
return V_49 ;
}
if ( V_45 -> V_60 ) {
for ( V_48 = V_46 - 1 ; V_48 >= 0 ; -- V_48 ) {
V_57 = V_45 -> V_61 [ ( V_1 >> V_48 ) & 1 ] ;
V_49 = F_37 ( V_3 , & V_43 ,
V_45 -> V_62 ,
V_57 ) ;
if ( V_49 )
return V_49 ;
}
} else {
for ( V_48 = 0 ; V_48 < V_46 ; ++ V_48 , V_1 >>= 1 ) {
V_57 = V_45 -> V_61 [ V_1 & 1 ] ;
V_49 = F_37 ( V_3 , & V_43 ,
V_45 -> V_62 ,
V_57 ) ;
if ( V_49 )
return V_49 ;
}
}
V_49 = F_37 ( V_3 , & V_43 , V_45 -> V_63 ,
V_45 -> V_55 ) ;
return V_49 ;
}
int F_38 ( struct V_2 * * V_3 , unsigned int V_43 ,
const struct V_64 * V_45 ,
unsigned int V_46 , T_3 V_1 )
{
int V_48 ;
int V_49 = - V_50 ;
unsigned int V_20 ;
if ( ! V_43 -- )
return V_49 ;
F_35 ( ( * V_3 ) ++ , 1 , V_45 -> V_58 ) ;
if ( V_45 -> V_60 ) {
for ( V_48 = V_46 - 1 ; V_48 >= 0 ; -- V_48 ) {
if ( ! V_43 -- )
return V_49 ;
F_35 ( ( * V_3 ) ++ , 0 ,
V_45 -> V_61 ) ;
if ( ! V_43 -- )
return V_49 ;
V_20 = V_45 -> V_62 [ ( V_1 >> V_48 ) & 1 ] ;
F_35 ( ( * V_3 ) ++ , 1 , V_20 ) ;
}
} else {
for ( V_48 = 0 ; V_48 < V_46 ; ++ V_48 , V_1 >>= 1 ) {
if ( ! V_43 -- )
return V_49 ;
F_35 ( ( * V_3 ) ++ , 0 ,
V_45 -> V_61 ) ;
if ( ! V_43 -- )
return V_49 ;
V_20 = V_45 -> V_62 [ V_1 & 1 ] ;
F_35 ( ( * V_3 ) ++ , 1 , V_20 ) ;
}
}
if ( ! V_43 -- )
return V_49 ;
F_35 ( ( * V_3 ) ++ , 0 , V_45 -> V_55 ) ;
return 0 ;
}
int F_39 ( enum V_41 V_65 , T_4 V_66 ,
struct V_2 * V_67 , unsigned int V_43 )
{
struct V_4 * V_5 ;
int V_49 = - V_18 ;
T_3 V_68 = 1ULL << V_65 ;
F_2 ( & V_8 ) ;
F_4 (handler, &ir_raw_handler_list, list) {
if ( V_5 -> V_12 & V_68 && V_5 -> V_69 ) {
V_49 = V_5 -> V_69 ( V_65 , V_66 , V_67 , V_43 ) ;
if ( V_49 >= 0 || V_49 == - V_50 )
break;
}
}
F_5 ( & V_8 ) ;
return V_49 ;
}
int F_40 ( struct V_17 * V_10 )
{
static bool V_70 ;
if ( ! V_10 )
return - V_18 ;
if ( ! V_70 ) {
F_41 ( L_6 ) ;
V_70 = true ;
}
V_10 -> V_7 = F_42 ( sizeof( * V_10 -> V_7 ) , V_71 ) ;
if ( ! V_10 -> V_7 )
return - V_72 ;
V_10 -> V_7 -> V_10 = V_10 ;
V_10 -> F_31 = F_31 ;
F_43 ( V_10 -> V_7 -> V_9 ) ;
return 0 ;
}
int F_44 ( struct V_17 * V_10 )
{
struct V_4 * V_5 ;
struct V_73 * V_39 ;
if ( V_10 -> V_74 != V_75 ) {
V_39 = F_45 ( F_1 , V_10 -> V_7 , L_7 ,
V_10 -> V_76 ) ;
if ( F_46 ( V_39 ) )
return F_47 ( V_39 ) ;
V_10 -> V_7 -> V_39 = V_39 ;
}
F_2 ( & V_8 ) ;
F_48 ( & V_10 -> V_7 -> V_77 , & V_78 ) ;
F_4 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_79 )
V_5 -> V_79 ( V_10 ) ;
F_5 ( & V_8 ) ;
return 0 ;
}
void F_49 ( struct V_17 * V_10 )
{
if ( ! V_10 )
return;
F_50 ( V_10 -> V_7 ) ;
V_10 -> V_7 = NULL ;
}
void F_51 ( struct V_17 * V_10 )
{
struct V_4 * V_5 ;
if ( ! V_10 || ! V_10 -> V_7 )
return;
F_52 ( V_10 -> V_7 -> V_39 ) ;
F_2 ( & V_8 ) ;
F_53 ( & V_10 -> V_7 -> V_77 ) ;
F_4 (handler, &ir_raw_handler_list, list)
if ( V_5 -> V_80 )
V_5 -> V_80 ( V_10 ) ;
F_5 ( & V_8 ) ;
F_49 ( V_10 ) ;
}
int F_54 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
F_2 ( & V_8 ) ;
F_48 ( & V_4 -> V_77 , & V_81 ) ;
if ( V_4 -> V_79 )
F_4 (raw, &ir_raw_client_list, list)
V_4 -> V_79 ( V_7 -> V_10 ) ;
F_55 ( V_4 -> V_12 , & V_40 ) ;
F_5 ( & V_8 ) ;
return 0 ;
}
void F_56 ( struct V_4 * V_4 )
{
struct V_6 * V_7 ;
T_3 V_12 = V_4 -> V_12 ;
F_2 ( & V_8 ) ;
F_53 ( & V_4 -> V_77 ) ;
F_4 (raw, &ir_raw_client_list, list) {
F_32 ( V_7 -> V_10 , V_12 ) ;
if ( V_4 -> V_80 )
V_4 -> V_80 ( V_7 -> V_10 ) ;
}
F_57 ( V_12 , & V_40 ) ;
F_5 ( & V_8 ) ;
}
