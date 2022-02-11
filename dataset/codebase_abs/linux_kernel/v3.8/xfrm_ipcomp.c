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
struct V_24 * V_24 ;
V_19 = - V_25 ;
if ( F_8 ( F_9 ( V_4 ) -> V_26 >= V_27 ) )
goto V_20;
V_23 = F_9 ( V_4 ) -> V_28 + F_9 ( V_4 ) -> V_26 ;
V_24 = F_10 ( V_29 ) ;
V_19 = - V_30 ;
if ( ! V_24 )
goto V_20;
F_11 ( V_23 , V_24 ) ;
V_9 = V_31 ;
if ( V_10 < V_9 )
V_9 = V_10 ;
V_23 -> V_32 = 0 ;
F_12 ( V_23 , V_9 ) ;
memcpy ( F_13 ( V_23 ) , V_14 , V_9 ) ;
V_4 -> V_33 += V_9 ;
V_4 -> V_34 += V_9 ;
V_4 -> V_9 += V_9 ;
F_9 ( V_4 ) -> V_26 ++ ;
}
V_19 = 0 ;
V_20:
F_14 () ;
return V_19 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_35 ;
int V_19 = - V_30 ;
struct V_21 * V_36 ;
if ( F_16 ( V_4 ) )
goto V_20;
V_4 -> V_37 = V_38 ;
V_36 = ( void * ) V_4 -> V_7 ;
V_35 = V_36 -> V_35 ;
V_4 -> V_39 = V_4 -> V_40 + sizeof( * V_36 ) ;
F_17 ( V_4 , sizeof( * V_36 ) ) ;
V_19 = F_1 ( V_2 , V_4 ) ;
if ( V_19 )
goto V_20;
V_19 = V_35 ;
V_20:
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const int V_8 = V_4 -> V_9 ;
int V_10 = V_11 ;
T_1 * V_12 = V_4 -> V_7 ;
const int V_13 = F_2 () ;
T_1 * V_14 = * F_3 ( V_15 , V_13 ) ;
struct V_16 * V_17 = * F_3 ( V_6 -> V_18 , V_13 ) ;
int V_19 ;
F_19 () ;
V_19 = F_20 ( V_17 , V_12 , V_8 , V_14 , & V_10 ) ;
F_21 () ;
if ( V_19 )
goto V_20;
if ( ( V_10 + sizeof( struct V_21 ) ) >= V_8 ) {
V_19 = - V_25 ;
goto V_20;
}
memcpy ( V_12 + sizeof( struct V_21 ) , V_14 , V_10 ) ;
F_14 () ;
F_22 ( V_4 , V_10 + sizeof( struct V_21 ) ) ;
return 0 ;
V_20:
F_14 () ;
return V_19 ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_19 ;
struct V_21 * V_36 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 -> V_9 < V_6 -> V_41 ) {
goto V_42;
}
if ( F_16 ( V_4 ) )
goto V_42;
V_19 = F_18 ( V_2 , V_4 ) ;
if ( V_19 ) {
goto V_42;
}
V_36 = V_21 ( V_4 ) ;
V_36 -> V_35 = * F_24 ( V_4 ) ;
V_36 -> V_43 = 0 ;
V_36 -> V_44 = F_25 ( ( V_45 ) F_26 ( V_2 -> V_46 . V_47 ) ) ;
* F_24 ( V_4 ) = V_48 ;
V_42:
F_27 ( V_4 , - F_28 ( V_4 ) ) ;
return 0 ;
}
static void F_29 ( void )
{
int V_49 ;
void * T_3 * V_50 ;
if ( -- V_51 )
return;
V_50 = V_15 ;
if ( ! V_50 )
return;
F_30 (i)
F_31 ( * F_3 ( V_50 , V_49 ) ) ;
F_32 ( V_50 ) ;
}
static void * T_3 * F_33 ( void )
{
int V_49 ;
void * T_3 * V_50 ;
if ( V_51 ++ )
return V_15 ;
V_50 = F_34 ( void * ) ;
if ( ! V_50 )
return NULL ;
V_15 = V_50 ;
F_30 (i) {
void * V_14 = F_35 ( V_11 ) ;
if ( ! V_14 )
return NULL ;
* F_3 ( V_50 , V_49 ) = V_14 ;
}
return V_50 ;
}
static void F_36 ( struct V_16 * T_3 * V_18 )
{
struct V_52 * V_53 ;
int V_13 ;
F_37 (pos, &ipcomp_tfms_list, list) {
if ( V_53 -> V_18 == V_18 )
break;
}
F_8 ( ! V_53 ) ;
if ( -- V_53 -> V_54 )
return;
F_38 ( & V_53 -> V_55 ) ;
F_39 ( V_53 ) ;
if ( ! V_18 )
return;
F_30 (cpu) {
struct V_16 * V_17 = * F_3 ( V_18 , V_13 ) ;
F_40 ( V_17 ) ;
}
F_32 ( V_18 ) ;
}
static struct V_16 * T_3 * F_41 ( const char * V_56 )
{
struct V_52 * V_53 ;
struct V_16 * T_3 * V_18 ;
int V_13 ;
F_37 (pos, &ipcomp_tfms_list, list) {
struct V_16 * V_17 ;
V_17 = F_42 ( * V_53 -> V_18 ) ;
if ( ! strcmp ( F_43 ( V_17 ) , V_56 ) ) {
V_53 -> V_54 ++ ;
return V_53 -> V_18 ;
}
}
V_53 = F_44 ( sizeof( * V_53 ) , V_57 ) ;
if ( ! V_53 )
return NULL ;
V_53 -> V_54 = 1 ;
F_45 ( & V_53 -> V_55 ) ;
F_46 ( & V_53 -> V_55 , & V_58 ) ;
V_53 -> V_18 = V_18 = F_34 ( struct V_16 * ) ;
if ( ! V_18 )
goto error;
F_30 (cpu) {
struct V_16 * V_17 = F_47 ( V_56 , 0 ,
V_59 ) ;
if ( F_48 ( V_17 ) )
goto error;
* F_3 ( V_18 , V_13 ) = V_17 ;
}
return V_18 ;
error:
F_36 ( V_18 ) ;
return NULL ;
}
static void F_49 ( struct V_5 * V_6 )
{
if ( V_6 -> V_18 )
F_36 ( V_6 -> V_18 ) ;
F_29 () ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 )
return;
F_51 ( V_2 ) ;
F_52 ( & V_60 ) ;
F_49 ( V_6 ) ;
F_53 ( & V_60 ) ;
F_39 ( V_6 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_5 * V_6 ;
struct V_61 * V_62 ;
V_19 = - V_22 ;
if ( ! V_2 -> V_63 )
goto V_20;
if ( V_2 -> V_64 )
goto V_20;
V_19 = - V_30 ;
V_6 = F_55 ( sizeof( * V_6 ) , V_57 ) ;
if ( ! V_6 )
goto V_20;
F_52 ( & V_60 ) ;
if ( ! F_33 () )
goto error;
V_6 -> V_18 = F_41 ( V_2 -> V_63 -> V_56 ) ;
if ( ! V_6 -> V_18 )
goto error;
F_53 ( & V_60 ) ;
V_62 = F_56 ( V_2 -> V_63 -> V_56 , 0 ) ;
F_57 ( ! V_62 ) ;
V_6 -> V_41 = V_62 -> V_65 . V_66 . V_41 ;
V_2 -> V_7 = V_6 ;
V_19 = 0 ;
V_20:
return V_19 ;
error:
F_49 ( V_6 ) ;
F_53 ( & V_60 ) ;
F_39 ( V_6 ) ;
goto V_20;
}
