static int F_1 ( void * V_1 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
while ( ! F_2 () ) {
if ( F_3 ( & V_7 ) )
break;
F_4 ( & V_8 , V_2 ) ;
V_4 = NULL ;
if ( ! F_5 ( & V_9 ) ) {
V_4 = F_6 ( V_9 . V_10 ,
struct V_3 , V_11 ) ;
F_7 ( & V_4 -> V_11 ) ;
}
F_8 ( & V_8 , V_2 ) ;
if ( ! V_4 )
continue;
V_6 = V_4 -> V_6 ;
if ( V_6 ) {
F_9 ( V_6 , V_12 ) ;
F_10 ( L_1 ,
V_6 -> V_13 -> V_14 , V_6 -> V_15 ) ;
F_11 ( V_6 ) ;
F_12 ( V_6 , V_12 ) ;
} else {
F_11 ( NULL ) ;
}
F_13 ( V_4 ) ;
}
return 0 ;
}
int F_14 ( void )
{
struct V_16 * V_17 ;
int V_18 = 0 ;
F_15 ( & V_7 , 0 ) ;
V_17 = F_16 ( F_1 , NULL , L_2 ) ;
if ( F_17 ( V_17 ) ) {
V_18 = F_18 ( V_17 ) ;
F_19 ( L_3 ,
V_19 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
int F_20 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
struct V_3 * V_4 ;
V_4 = F_21 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 ) {
F_19 ( L_4 ) ;
return - V_21 ;
}
V_4 -> V_6 = V_6 ;
F_4 ( & V_8 , V_2 ) ;
F_22 ( & V_4 -> V_11 , & V_9 ) ;
F_8 ( & V_8 , V_2 ) ;
F_23 ( & V_7 ) ;
return 0 ;
}
void F_24 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
struct V_3 * V_4 , * V_22 ;
F_4 ( & V_8 , V_2 ) ;
F_25 (event, tmp, &eeh_eventlist, list) {
if ( ! V_6 ) {
F_7 ( & V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
} else if ( V_6 -> type & V_23 ) {
if ( V_4 -> V_6 && V_4 -> V_6 -> V_13 == V_6 -> V_13 ) {
F_7 ( & V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
}
} else if ( V_4 -> V_6 == V_6 ) {
F_7 ( & V_4 -> V_11 ) ;
F_13 ( V_4 ) ;
}
}
F_8 ( & V_8 , V_2 ) ;
}
