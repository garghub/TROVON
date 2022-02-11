static void F_1 ( void )
{
if ( V_1 != V_2 )
F_2 () ;
}
static struct V_3 * * F_3 ( void * V_4 , struct V_3 * * V_5 )
{
struct V_3 * * V_6 = & V_7 . V_3 ;
struct V_8 * V_9 ;
* V_5 = NULL ;
while ( * V_6 ) {
V_9 = F_4 ( * V_6 , struct V_8 , V_6 ) ;
* V_5 = * V_6 ;
if ( V_4 < V_9 -> V_10 )
V_6 = & V_9 -> V_6 . V_11 ;
else if ( V_4 > V_9 -> V_10 )
V_6 = & V_9 -> V_6 . V_12 ;
else
return V_6 ;
}
return V_6 ;
}
static inline bool F_5 ( struct V_8 * V_4 )
{
return V_4 >= V_13 && V_4 < V_13 + F_6 ( V_13 ) ;
}
static struct V_8 * F_7 ( void )
{
if ( V_1 != V_2 ) {
int V_14 = V_15 ++ ;
if ( V_14 >= F_6 ( V_13 ) ) {
fprintf ( V_16 ,
L_1 ) ;
exit ( V_17 ) ;
}
return V_13 + V_14 ;
}
return malloc ( sizeof( struct V_8 ) ) ;
}
static inline void F_8 ( struct V_8 * V_4 )
{
if ( F_9 ( ! F_5 ( V_4 ) ) )
free ( V_4 ) ;
}
static struct V_8 * F_10 ( void * V_4 )
{
struct V_3 * * V_6 , * V_5 ;
struct V_8 * V_9 ;
F_11 ( & V_18 ) ;
V_6 = F_3 ( V_4 , & V_5 ) ;
F_12 ( & V_18 ) ;
if ( * V_6 ) {
return F_4 ( * V_6 , struct V_8 , V_6 ) ;
}
V_9 = F_7 () ;
if ( V_9 == NULL )
return NULL ;
V_9 -> V_10 = V_4 ;
sprintf ( V_9 -> V_19 , L_2 , V_4 ) ;
F_13 ( & V_9 -> V_20 , V_9 -> V_19 , & V_9 -> V_21 , 0 ) ;
F_14 ( & V_18 ) ;
V_6 = F_3 ( V_4 , & V_5 ) ;
F_15 ( & V_9 -> V_6 , V_5 , V_6 ) ;
F_16 ( & V_9 -> V_6 , & V_7 ) ;
F_12 ( & V_18 ) ;
return V_9 ;
}
static void F_17 ( struct V_8 * V_4 )
{
F_14 ( & V_18 ) ;
F_18 ( & V_4 -> V_6 , & V_7 ) ;
F_12 ( & V_18 ) ;
F_8 ( V_4 ) ;
}
int F_19 ( T_1 * V_22 ,
const T_2 * V_23 )
{
int V_24 ;
F_1 () ;
V_24 = F_20 ( V_22 , V_23 ) ;
if ( V_24 == 0 )
F_10 ( V_22 ) ;
return V_24 ;
}
int F_21 ( T_1 * V_22 )
{
int V_24 ;
F_1 () ;
F_22 ( & F_10 ( V_22 ) -> V_20 , 0 , 0 , 0 , 1 , NULL ,
( unsigned long ) V_25 ) ;
V_24 = F_23 ( V_22 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_22 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_25 ( T_1 * V_22 )
{
int V_24 ;
F_1 () ;
F_22 ( & F_10 ( V_22 ) -> V_20 , 0 , 1 , 0 , 1 , NULL , ( unsigned long ) V_25 ) ;
V_24 = F_26 ( V_22 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_22 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_27 ( T_1 * V_22 )
{
int V_24 ;
F_1 () ;
F_24 ( & F_10 ( V_22 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
V_24 = F_28 ( V_22 ) ;
if ( V_24 )
F_22 ( & F_10 ( V_22 ) -> V_20 , 0 , 0 , 0 , 1 , NULL , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_29 ( T_1 * V_22 )
{
F_1 () ;
F_30 ( V_22 , sizeof( * V_22 ) ) ;
F_17 ( F_10 ( V_22 ) ) ;
return F_31 ( V_22 ) ;
}
int F_32 ( T_3 * V_26 ,
const T_4 * V_23 )
{
int V_24 ;
F_1 () ;
V_24 = F_33 ( V_26 , V_23 ) ;
if ( V_24 == 0 )
F_10 ( V_26 ) ;
return V_24 ;
}
int F_34 ( T_3 * V_26 )
{
F_1 () ;
F_30 ( V_26 , sizeof( * V_26 ) ) ;
F_17 ( F_10 ( V_26 ) ) ;
return F_35 ( V_26 ) ;
}
int F_36 ( T_3 * V_26 )
{
int V_24 ;
F_2 () ;
F_22 ( & F_10 ( V_26 ) -> V_20 , 0 , 0 , 2 , 1 , NULL , ( unsigned long ) V_25 ) ;
V_24 = F_11 ( V_26 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_26 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_37 ( T_3 * V_26 )
{
int V_24 ;
F_2 () ;
F_22 ( & F_10 ( V_26 ) -> V_20 , 0 , 1 , 2 , 1 , NULL , ( unsigned long ) V_25 ) ;
V_24 = F_38 ( V_26 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_26 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_39 ( T_3 * V_26 )
{
int V_24 ;
F_2 () ;
F_22 ( & F_10 ( V_26 ) -> V_20 , 0 , 1 , 0 , 1 , NULL , ( unsigned long ) V_25 ) ;
V_24 = F_40 ( V_26 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_26 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_41 ( T_3 * V_26 )
{
int V_24 ;
F_2 () ;
F_22 ( & F_10 ( V_26 ) -> V_20 , 0 , 0 , 0 , 1 , NULL , ( unsigned long ) V_25 ) ;
V_24 = F_14 ( V_26 ) ;
if ( V_24 )
F_24 ( & F_10 ( V_26 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
return V_24 ;
}
int F_42 ( T_3 * V_26 )
{
int V_24 ;
F_2 () ;
F_24 ( & F_10 ( V_26 ) -> V_20 , 0 , ( unsigned long ) V_25 ) ;
V_24 = F_12 ( V_26 ) ;
if ( V_24 )
F_22 ( & F_10 ( V_26 ) -> V_20 , 0 , 0 , 0 , 1 , NULL , ( unsigned long ) V_25 ) ;
return V_24 ;
}
static void F_2 ( void )
{
if ( V_1 == V_2 )
return;
#ifndef F_43
V_1 = V_27 ;
F_20 = F_44 ( V_28 , L_3 ) ;
F_23 = F_44 ( V_28 , L_4 ) ;
F_26 = F_44 ( V_28 , L_5 ) ;
F_28 = F_44 ( V_28 , L_6 ) ;
F_31 = F_44 ( V_28 , L_7 ) ;
F_33 = F_44 ( V_28 , L_8 ) ;
F_35 = F_44 ( V_28 , L_9 ) ;
F_11 = F_44 ( V_28 , L_10 ) ;
F_38 = F_44 ( V_28 , L_11 ) ;
F_14 = F_44 ( V_28 , L_12 ) ;
F_40 = F_44 ( V_28 , L_13 ) ;
F_12 = F_44 ( V_28 , L_14 ) ;
#endif
V_1 = V_2 ;
}
