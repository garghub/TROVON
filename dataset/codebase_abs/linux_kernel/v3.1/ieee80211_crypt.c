void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 , * V_6 ;
struct V_7 * V_8 ;
for ( V_5 = V_2 -> V_9 . V_10 , V_6 = V_5 -> V_10 ;
V_5 != & V_2 -> V_9 ; V_5 = V_6 , V_6 = V_5 -> V_10 ) {
V_8 = F_2 ( V_5 , struct V_7 , V_11 ) ;
if ( F_3 ( & V_8 -> V_12 ) != 0 && ! V_3 )
continue;
F_4 ( V_5 ) ;
if ( V_8 -> V_13 )
V_8 -> V_13 -> V_14 ( V_8 -> V_15 ) ;
F_5 ( V_8 ) ;
}
}
void F_6 ( unsigned long V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 ;
unsigned long V_17 ;
F_7 ( & V_2 -> V_18 , V_17 ) ;
F_1 ( V_2 , 0 ) ;
if ( ! F_8 ( & V_2 -> V_9 ) ) {
F_9 ( V_19 L_1
L_2 , V_2 -> V_20 -> V_21 ) ;
V_2 -> V_22 . V_23 = V_24 + V_25 ;
F_10 ( & V_2 -> V_22 ) ;
}
F_11 ( & V_2 -> V_18 , V_17 ) ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_7 * * V_26 )
{
struct V_7 * V_27 ;
unsigned long V_17 ;
if ( * V_26 == NULL )
return;
V_27 = * V_26 ;
* V_26 = NULL ;
F_7 ( & V_2 -> V_18 , V_17 ) ;
F_13 ( & V_27 -> V_11 , & V_2 -> V_9 ) ;
if ( ! F_14 ( & V_2 -> V_22 ) ) {
V_2 -> V_22 . V_23 = V_24 + V_25 ;
F_10 ( & V_2 -> V_22 ) ;
}
F_11 ( & V_2 -> V_18 , V_17 ) ;
}
int F_15 ( struct V_28 * V_13 )
{
unsigned long V_17 ;
struct V_29 * V_30 ;
if ( V_31 == NULL )
return - 1 ;
V_30 = F_16 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL )
return - V_33 ;
V_30 -> V_13 = V_13 ;
F_7 ( & V_31 -> V_18 , V_17 ) ;
F_13 ( & V_30 -> V_11 , & V_31 -> V_34 ) ;
F_11 ( & V_31 -> V_18 , V_17 ) ;
F_9 ( V_19 L_3 ,
V_13 -> V_21 ) ;
return 0 ;
}
int F_17 ( struct V_28 * V_13 )
{
unsigned long V_17 ;
struct V_4 * V_5 ;
struct V_29 * V_35 = NULL ;
if ( V_31 == NULL )
return - 1 ;
F_7 ( & V_31 -> V_18 , V_17 ) ;
for ( V_5 = V_31 -> V_34 . V_10 ; V_5 != & V_31 -> V_34 ; V_5 = V_5 -> V_10 ) {
struct V_29 * V_30 =
(struct V_29 * ) V_5 ;
if ( V_30 -> V_13 == V_13 ) {
F_4 ( & V_30 -> V_11 ) ;
V_35 = V_30 ;
break;
}
}
F_11 ( & V_31 -> V_18 , V_17 ) ;
if ( V_35 ) {
F_9 ( V_19 L_4
L_5 , V_13 -> V_21 ) ;
F_5 ( V_35 ) ;
}
return V_35 ? 0 : - 1 ;
}
struct V_28 * F_18 ( const char * V_21 )
{
unsigned long V_17 ;
struct V_4 * V_5 ;
struct V_29 * V_36 = NULL ;
if ( V_31 == NULL )
return NULL ;
F_7 ( & V_31 -> V_18 , V_17 ) ;
for ( V_5 = V_31 -> V_34 . V_10 ; V_5 != & V_31 -> V_34 ; V_5 = V_5 -> V_10 ) {
struct V_29 * V_30 =
(struct V_29 * ) V_5 ;
if ( strcmp ( V_30 -> V_13 -> V_21 , V_21 ) == 0 ) {
V_36 = V_30 ;
break;
}
}
F_11 ( & V_31 -> V_18 , V_17 ) ;
if ( V_36 )
return V_36 -> V_13 ;
else
return NULL ;
}
static void * F_19 ( int V_37 ) { return ( void * ) 1 ; }
static void F_20 ( void * V_15 ) {}
int T_1 F_21 ( void )
{
int V_38 = - V_33 ;
V_31 = F_16 ( sizeof( * V_31 ) , V_32 ) ;
if ( ! V_31 )
goto V_39;
F_22 ( & V_31 -> V_34 ) ;
F_23 ( & V_31 -> V_18 ) ;
V_38 = F_15 ( & V_40 ) ;
if ( V_38 < 0 ) {
F_5 ( V_31 ) ;
V_31 = NULL ;
}
V_39:
return V_38 ;
}
void F_24 ( void )
{
struct V_4 * V_5 , * V_6 ;
if ( V_31 == NULL )
return;
for ( V_5 = V_31 -> V_34 . V_10 , V_6 = V_5 -> V_10 ; V_5 != & V_31 -> V_34 ;
V_5 = V_6 , V_6 = V_5 -> V_10 ) {
struct V_29 * V_30 =
(struct V_29 * ) V_5 ;
F_4 ( V_5 ) ;
F_9 ( V_19 L_4
L_6 , V_30 -> V_13 -> V_21 ) ;
F_5 ( V_30 ) ;
}
F_5 ( V_31 ) ;
}
