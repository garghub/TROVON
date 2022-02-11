static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const int V_8 = V_4 -> V_9 ;
int V_10 = V_11 ;
const T_1 * V_12 = V_4 -> V_7 ;
const int V_13 = F_2 () ;
T_1 * V_14 = * F_3 ( V_15 , V_13 ) ;
struct V_16 * V_17 = * F_3 ( V_6 -> V_18 , V_13 ) ;
int V_19 = F_4 ( V_17 , V_12 , V_8 , V_14 , & V_10 ) ;
int V_9 ;
if ( V_19 )
goto V_20;
if ( V_10 < ( V_8 + sizeof( struct V_21 ) ) ) {
V_19 = - V_22 ;
goto V_20;
}
V_9 = V_10 - V_8 ;
if ( V_9 > F_5 ( V_4 ) )
V_9 = F_5 ( V_4 ) ;
F_6 ( V_4 , V_9 ) ;
V_9 += V_8 ;
F_7 ( V_4 , V_14 , V_9 ) ;
while ( ( V_14 += V_9 , V_10 -= V_9 ) > 0 ) {
T_2 * V_23 ;
V_19 = - V_24 ;
if ( F_8 ( F_9 ( V_4 ) -> V_25 >= V_26 ) )
goto V_20;
V_23 = F_9 ( V_4 ) -> V_27 + F_9 ( V_4 ) -> V_25 ;
V_23 -> V_28 = F_10 ( V_29 ) ;
V_19 = - V_30 ;
if ( ! V_23 -> V_28 )
goto V_20;
V_9 = V_31 ;
if ( V_10 < V_9 )
V_9 = V_10 ;
memcpy ( F_11 ( V_23 -> V_28 ) , V_14 , V_9 ) ;
V_23 -> V_32 = 0 ;
V_23 -> V_33 = V_9 ;
V_4 -> V_34 += V_9 ;
V_4 -> V_35 += V_9 ;
V_4 -> V_9 += V_9 ;
F_9 ( V_4 ) -> V_25 ++ ;
}
V_19 = 0 ;
V_20:
F_12 () ;
return V_19 ;
}
int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_36 ;
int V_19 = - V_30 ;
struct V_21 * V_37 ;
if ( F_14 ( V_4 ) )
goto V_20;
V_4 -> V_38 = V_39 ;
V_37 = ( void * ) V_4 -> V_7 ;
V_36 = V_37 -> V_36 ;
V_4 -> V_40 = V_4 -> V_41 + sizeof( * V_37 ) ;
F_15 ( V_4 , sizeof( * V_37 ) ) ;
V_19 = F_1 ( V_2 , V_4 ) ;
if ( V_19 )
goto V_20;
V_19 = V_36 ;
V_20:
return V_19 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const int V_8 = V_4 -> V_9 ;
int V_10 = V_11 ;
T_1 * V_12 = V_4 -> V_7 ;
const int V_13 = F_2 () ;
T_1 * V_14 = * F_3 ( V_15 , V_13 ) ;
struct V_16 * V_17 = * F_3 ( V_6 -> V_18 , V_13 ) ;
int V_19 ;
F_17 () ;
V_19 = F_18 ( V_17 , V_12 , V_8 , V_14 , & V_10 ) ;
F_19 () ;
if ( V_19 )
goto V_20;
if ( ( V_10 + sizeof( struct V_21 ) ) >= V_8 ) {
V_19 = - V_24 ;
goto V_20;
}
memcpy ( V_12 + sizeof( struct V_21 ) , V_14 , V_10 ) ;
F_12 () ;
F_20 ( V_4 , V_10 + sizeof( struct V_21 ) ) ;
return 0 ;
V_20:
F_12 () ;
return V_19 ;
}
int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_19 ;
struct V_21 * V_37 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_9 < V_6 -> V_42 ) {
goto V_43;
}
if ( F_14 ( V_4 ) )
goto V_43;
V_19 = F_16 ( V_2 , V_4 ) ;
if ( V_19 ) {
goto V_43;
}
V_37 = V_21 ( V_4 ) ;
V_37 -> V_36 = * F_22 ( V_4 ) ;
V_37 -> V_44 = 0 ;
V_37 -> V_45 = F_23 ( ( V_46 ) F_24 ( V_2 -> V_47 . V_48 ) ) ;
* F_22 ( V_4 ) = V_49 ;
V_43:
F_25 ( V_4 , - F_26 ( V_4 ) ) ;
return 0 ;
}
static void F_27 ( void )
{
int V_50 ;
void * T_3 * V_51 ;
if ( -- V_52 )
return;
V_51 = V_15 ;
if ( ! V_51 )
return;
F_28 (i)
F_29 ( * F_3 ( V_51 , V_50 ) ) ;
F_30 ( V_51 ) ;
}
static void * T_3 * F_31 ( void )
{
int V_50 ;
void * T_3 * V_51 ;
if ( V_52 ++ )
return V_15 ;
V_51 = F_32 ( void * ) ;
if ( ! V_51 )
return NULL ;
V_15 = V_51 ;
F_28 (i) {
void * V_14 = F_33 ( V_11 ) ;
if ( ! V_14 )
return NULL ;
* F_3 ( V_51 , V_50 ) = V_14 ;
}
return V_51 ;
}
static void F_34 ( struct V_16 * T_3 * V_18 )
{
struct V_53 * V_54 ;
int V_13 ;
F_35 (pos, &ipcomp_tfms_list, list) {
if ( V_54 -> V_18 == V_18 )
break;
}
F_8 ( ! V_54 ) ;
if ( -- V_54 -> V_55 )
return;
F_36 ( & V_54 -> V_56 ) ;
F_37 ( V_54 ) ;
if ( ! V_18 )
return;
F_28 (cpu) {
struct V_16 * V_17 = * F_3 ( V_18 , V_13 ) ;
F_38 ( V_17 ) ;
}
F_30 ( V_18 ) ;
}
static struct V_16 * T_3 * F_39 ( const char * V_57 )
{
struct V_53 * V_54 ;
struct V_16 * T_3 * V_18 ;
int V_13 ;
V_13 = F_40 () ;
F_35 (pos, &ipcomp_tfms_list, list) {
struct V_16 * V_17 ;
V_18 = V_54 -> V_18 ;
V_17 = * F_3 ( V_18 , V_13 ) ;
if ( ! strcmp ( F_41 ( V_17 ) , V_57 ) ) {
V_54 -> V_55 ++ ;
return V_18 ;
}
}
V_54 = F_42 ( sizeof( * V_54 ) , V_58 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_55 = 1 ;
F_43 ( & V_54 -> V_56 ) ;
F_44 ( & V_54 -> V_56 , & V_59 ) ;
V_54 -> V_18 = V_18 = F_32 ( struct V_16 * ) ;
if ( ! V_18 )
goto error;
F_28 (cpu) {
struct V_16 * V_17 = F_45 ( V_57 , 0 ,
V_60 ) ;
if ( F_46 ( V_17 ) )
goto error;
* F_3 ( V_18 , V_13 ) = V_17 ;
}
return V_18 ;
error:
F_34 ( V_18 ) ;
return NULL ;
}
static void F_47 ( struct V_5 * V_6 )
{
if ( V_6 -> V_18 )
F_34 ( V_6 -> V_18 ) ;
F_27 () ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 )
return;
F_49 ( V_2 ) ;
F_50 ( & V_61 ) ;
F_47 ( V_6 ) ;
F_51 ( & V_61 ) ;
F_37 ( V_6 ) ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
V_19 = - V_22 ;
if ( ! V_2 -> V_64 )
goto V_20;
if ( V_2 -> V_65 )
goto V_20;
V_19 = - V_30 ;
V_6 = F_53 ( sizeof( * V_6 ) , V_58 ) ;
if ( ! V_6 )
goto V_20;
F_50 ( & V_61 ) ;
if ( ! F_31 () )
goto error;
V_6 -> V_18 = F_39 ( V_2 -> V_64 -> V_57 ) ;
if ( ! V_6 -> V_18 )
goto error;
F_51 ( & V_61 ) ;
V_63 = F_54 ( V_2 -> V_64 -> V_57 , 0 ) ;
F_55 ( ! V_63 ) ;
V_6 -> V_42 = V_63 -> V_66 . V_67 . V_42 ;
V_2 -> V_7 = V_6 ;
V_19 = 0 ;
V_20:
return V_19 ;
error:
F_47 ( V_6 ) ;
F_51 ( & V_61 ) ;
F_37 ( V_6 ) ;
goto V_20;
}
