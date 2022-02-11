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
F_9 ( V_2 -> V_19 , L_1 ,
V_2 -> V_19 -> V_20 ) ;
V_2 -> V_21 . V_22 = V_23 + V_24 ;
F_10 ( & V_2 -> V_21 ) ;
}
F_11 ( & V_2 -> V_18 , V_17 ) ;
}
void F_12 ( struct V_1 * V_2 ,
struct V_7 * * V_25 )
{
struct V_7 * V_26 ;
unsigned long V_17 ;
if ( * V_25 == NULL )
return;
V_26 = * V_25 ;
* V_25 = NULL ;
F_7 ( & V_2 -> V_18 , V_17 ) ;
F_13 ( & V_26 -> V_11 , & V_2 -> V_9 ) ;
if ( ! F_14 ( & V_2 -> V_21 ) ) {
V_2 -> V_21 . V_22 = V_23 + V_24 ;
F_10 ( & V_2 -> V_21 ) ;
}
F_11 ( & V_2 -> V_18 , V_17 ) ;
}
int F_15 ( struct V_27 * V_13 )
{
unsigned long V_17 ;
struct V_28 * V_29 ;
if ( V_30 == NULL )
return - 1 ;
V_29 = F_16 ( sizeof( * V_29 ) , V_31 ) ;
if ( V_29 == NULL )
return - V_32 ;
V_29 -> V_13 = V_13 ;
F_7 ( & V_30 -> V_18 , V_17 ) ;
F_13 ( & V_29 -> V_11 , & V_30 -> V_33 ) ;
F_11 ( & V_30 -> V_18 , V_17 ) ;
F_17 ( L_2 ,
V_13 -> V_20 ) ;
return 0 ;
}
int F_18 ( struct V_27 * V_13 )
{
unsigned long V_17 ;
struct V_4 * V_5 ;
struct V_28 * V_34 = NULL ;
if ( V_30 == NULL )
return - 1 ;
F_7 ( & V_30 -> V_18 , V_17 ) ;
for ( V_5 = V_30 -> V_33 . V_10 ; V_5 != & V_30 -> V_33 ; V_5 = V_5 -> V_10 ) {
struct V_28 * V_29 =
(struct V_28 * ) V_5 ;
if ( V_29 -> V_13 == V_13 ) {
F_4 ( & V_29 -> V_11 ) ;
V_34 = V_29 ;
break;
}
}
F_11 ( & V_30 -> V_18 , V_17 ) ;
if ( V_34 ) {
F_17 ( L_3 ,
V_13 -> V_20 ) ;
F_5 ( V_34 ) ;
}
return V_34 ? 0 : - 1 ;
}
struct V_27 * F_19 ( const char * V_20 )
{
unsigned long V_17 ;
struct V_4 * V_5 ;
struct V_28 * V_35 = NULL ;
if ( V_30 == NULL )
return NULL ;
F_7 ( & V_30 -> V_18 , V_17 ) ;
for ( V_5 = V_30 -> V_33 . V_10 ; V_5 != & V_30 -> V_33 ; V_5 = V_5 -> V_10 ) {
struct V_28 * V_29 =
(struct V_28 * ) V_5 ;
if ( strcmp ( V_29 -> V_13 -> V_20 , V_20 ) == 0 ) {
V_35 = V_29 ;
break;
}
}
F_11 ( & V_30 -> V_18 , V_17 ) ;
if ( V_35 )
return V_35 -> V_13 ;
return NULL ;
}
static void * F_20 ( int V_36 ) { return ( void * ) 1 ; }
static void F_21 ( void * V_15 ) {}
int T_1 F_22 ( void )
{
int V_37 = - V_32 ;
V_30 = F_16 ( sizeof( * V_30 ) , V_31 ) ;
if ( ! V_30 )
goto V_38;
F_23 ( & V_30 -> V_33 ) ;
F_24 ( & V_30 -> V_18 ) ;
V_37 = F_15 ( & V_39 ) ;
if ( V_37 < 0 ) {
F_5 ( V_30 ) ;
V_30 = NULL ;
}
V_38:
return V_37 ;
}
void T_2 F_25 ( void )
{
struct V_4 * V_5 , * V_6 ;
if ( V_30 == NULL )
return;
for ( V_5 = V_30 -> V_33 . V_10 , V_6 = V_5 -> V_10 ; V_5 != & V_30 -> V_33 ;
V_5 = V_6 , V_6 = V_5 -> V_10 ) {
struct V_28 * V_29 =
(struct V_28 * ) V_5 ;
F_4 ( V_5 ) ;
F_17 ( L_4 ,
V_29 -> V_13 -> V_20 ) ;
F_5 ( V_29 ) ;
}
F_5 ( V_30 ) ;
}
