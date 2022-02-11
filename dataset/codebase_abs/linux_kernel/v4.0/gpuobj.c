void
F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 & V_5 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 += 4 )
F_2 ( V_2 , V_3 , 0x00000000 ) ;
}
if ( V_2 -> V_7 )
F_3 ( & F_4 ( V_2 -> V_8 ) -> V_9 , & V_2 -> V_7 ) ;
if ( V_2 -> V_9 . V_10 )
F_5 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
int
F_7 ( struct V_12 * V_8 , struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
struct V_12 * V_17 , T_1 V_6 , T_1 V_18 , T_1 V_4 ,
int V_19 , void * * V_20 )
{
struct V_21 * V_22 = V_21 ( V_8 ) ;
struct V_23 * V_24 = V_23 ( V_8 ) ;
struct V_1 * V_2 ;
struct V_25 * V_9 = NULL ;
int V_26 , V_3 ;
T_2 V_27 ;
* V_20 = NULL ;
if ( V_17 ) {
while ( ( V_17 = F_8 ( V_17 , V_28 ) ) ) {
if ( F_4 ( V_17 ) -> V_9 . V_10 )
break;
V_17 = V_17 -> V_8 ;
}
if ( F_9 ( V_17 == NULL ) ) {
F_10 ( V_8 , L_1 ) ;
return - V_29 ;
}
V_27 = F_4 ( V_17 ) -> V_27 ;
V_9 = & F_4 ( V_17 ) -> V_9 ;
F_11 ( & V_8 -> V_30 ) ;
} else {
V_26 = V_22 -> V_31 ( V_22 , V_8 , V_6 , V_18 , & V_8 ) ;
V_17 = V_8 ;
if ( V_26 )
return V_26 ;
V_27 = F_12 ( V_17 ) -> V_27 ;
V_6 = F_12 ( V_17 ) -> V_6 ;
if ( V_24 && V_24 -> V_31 ) {
struct V_32 * V_33 = ( void * ) V_8 ;
struct V_34 * * V_35 = ( void * ) ( V_33 + 1 ) ;
struct V_34 * V_7 = * V_35 ;
if ( ! V_24 -> V_31 ( V_24 , V_8 , V_7 , & V_17 ) ) {
F_13 ( NULL , & V_8 ) ;
V_8 = V_17 ;
}
}
}
V_26 = F_14 ( V_8 , V_13 , V_15 , V_16 |
V_28 , V_19 , V_20 ) ;
F_13 ( NULL , & V_8 ) ;
V_2 = * V_20 ;
if ( V_26 )
return V_26 ;
V_2 -> V_8 = V_17 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_6 = V_6 ;
if ( V_9 ) {
V_26 = F_15 ( V_9 , 0 , 1 , V_6 , V_6 , F_16 ( V_18 , ( T_1 ) 1 ) ,
& V_2 -> V_7 ) ;
if ( V_26 )
return V_26 ;
V_2 -> V_27 += V_2 -> V_7 -> V_36 ;
}
if ( V_2 -> V_4 & V_37 ) {
V_26 = F_17 ( & V_2 -> V_9 , 0 , V_2 -> V_6 , 1 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_4 & V_38 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 += 4 )
F_2 ( V_2 , V_3 , 0x00000000 ) ;
}
return V_26 ;
}
static int
F_18 ( struct V_12 * V_8 , struct V_12 * V_13 ,
struct V_14 * V_15 , void * V_39 , T_1 V_6 ,
struct V_12 * * V_20 )
{
struct V_40 * args = V_39 ;
struct V_1 * V_11 ;
int V_26 ;
V_26 = F_19 ( V_8 , V_13 , V_15 , 0 , args -> V_17 ,
args -> V_6 , args -> V_18 , args -> V_4 ,
& V_11 ) ;
* V_20 = F_20 ( V_11 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
void
F_21 ( struct V_12 * V_11 )
{
F_1 ( F_4 ( V_11 ) ) ;
}
int
F_22 ( struct V_12 * V_11 )
{
return F_23 ( F_4 ( V_11 ) ) ;
}
int
F_24 ( struct V_12 * V_11 , bool V_41 )
{
return F_25 ( F_4 ( V_11 ) , V_41 ) ;
}
T_1
F_26 ( struct V_12 * V_11 , T_2 V_27 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
struct V_42 * V_43 = F_27 ( V_2 -> V_8 ) ;
if ( V_2 -> V_7 )
V_27 += V_2 -> V_7 -> V_36 ;
return V_43 -> V_44 ( V_2 -> V_8 , V_27 ) ;
}
void
F_28 ( struct V_12 * V_11 , T_2 V_27 , T_1 V_39 )
{
struct V_1 * V_2 = F_4 ( V_11 ) ;
struct V_42 * V_43 = F_27 ( V_2 -> V_8 ) ;
if ( V_2 -> V_7 )
V_27 += V_2 -> V_7 -> V_36 ;
V_43 -> V_45 ( V_2 -> V_8 , V_27 , V_39 ) ;
}
int
F_29 ( struct V_12 * V_8 , struct V_12 * V_17 ,
T_1 V_6 , T_1 V_18 , T_1 V_4 ,
struct V_1 * * V_46 )
{
struct V_12 * V_13 = V_8 ;
struct V_40 args = {
. V_17 = V_17 ,
. V_6 = V_6 ,
. V_18 = V_18 ,
. V_4 = V_4 ,
} ;
if ( ! F_30 ( V_13 , V_47 ) )
V_13 = & V_13 -> V_13 -> V_48 . V_11 ;
F_31 ( V_13 == NULL ) ;
return F_32 ( V_8 , V_13 , & V_49 ,
& args , sizeof( args ) ,
(struct V_12 * * ) V_46 ) ;
}
int
F_33 ( struct V_1 * V_2 , T_1 V_50 , struct V_51 * V_52 )
{
struct V_23 * V_24 = V_23 ( V_2 ) ;
int V_26 = - V_29 ;
if ( V_24 && V_24 -> V_53 ) {
struct V_32 * V_33 = ( void * )
F_8 ( F_20 ( V_2 ) , V_54 ) ;
struct V_34 * * V_35 = ( void * ) ( V_33 + 1 ) ;
V_26 = V_24 -> V_53 ( V_24 , * V_35 , V_50 , V_52 ) ;
}
return V_26 ;
}
int
F_34 ( struct V_1 * V_2 , struct V_55 * V_56 ,
T_1 V_50 , struct V_51 * V_52 )
{
struct V_32 * V_33 = ( void * )
F_8 ( F_20 ( V_2 ) , V_54 ) ;
struct V_34 * * V_35 = ( void * ) ( V_33 + 1 ) ;
int V_26 ;
V_26 = F_35 ( V_56 , V_2 -> V_6 , 12 , V_50 , V_52 ) ;
if ( V_26 )
return V_26 ;
F_36 ( V_52 , * V_35 ) ;
return 0 ;
}
void
F_37 ( struct V_51 * V_52 )
{
if ( V_52 -> V_7 ) {
F_38 ( V_52 ) ;
F_39 ( V_52 ) ;
}
}
static void
F_40 ( struct V_12 * V_11 )
{
struct V_1 * V_2 = ( void * ) V_11 ;
F_13 ( NULL , & V_2 -> V_8 ) ;
F_6 ( & V_2 -> V_11 ) ;
}
int
F_41 ( struct V_12 * V_8 , struct V_1 * V_57 ,
struct V_1 * * V_46 )
{
struct V_1 * V_2 ;
int V_26 ;
V_26 = F_42 ( V_8 , & V_8 -> V_13 -> V_48 . V_11 ,
& V_58 , 0 , & V_2 ) ;
* V_46 = V_2 ;
if ( V_26 )
return V_26 ;
F_13 ( F_20 ( V_57 ) , & V_2 -> V_8 ) ;
V_2 -> V_27 = V_57 -> V_27 ;
V_2 -> V_6 = V_57 -> V_6 ;
return 0 ;
}
