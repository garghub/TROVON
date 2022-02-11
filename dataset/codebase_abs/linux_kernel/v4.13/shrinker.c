static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , int * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 , * V_9 ;
int time = F_2 () ;
F_3 ( F_4 ( & V_2 -> V_10 ) ) ;
F_3 ( F_4 ( & V_2 -> V_11 ) ) ;
if ( ! V_2 -> V_12 . V_8 || F_5 ( & V_2 -> V_13 ) == 0 )
return 0 ;
V_9 = NULL ;
V_8 = F_6 ( V_2 -> V_12 . V_8 , NULL ) ;
while ( V_8 && V_6 < V_3 &&
F_5 ( & V_2 -> V_13 ) > 0 ) {
int V_14 ;
if ( V_8 -> V_15 ) {
* V_5 = 1 ;
} else if ( ! F_7 ( V_8 ) &&
abs ( time - V_8 -> time ) >= V_4 ) {
if ( V_8 -> V_16 )
V_8 -> V_16 -> V_17 [ V_8 -> V_18 ] . V_8 = NULL ;
else
V_2 -> V_12 . V_8 = NULL ;
V_14 = F_8 ( V_8 ) ;
F_9 ( V_14 , & V_19 ) ;
F_9 ( V_14 , & V_2 -> V_13 ) ;
V_6 += V_14 ;
V_8 = V_9 ;
}
if ( F_10 ( ! V_2 -> V_12 . V_8 ) )
break;
V_9 = V_8 ;
V_8 = F_6 ( V_2 -> V_12 . V_8 , V_8 ) ;
F_11 () ;
}
return V_6 ;
}
static int F_12 ( int V_3 , int V_4 , int * V_5 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
unsigned int V_22 ;
int V_14 = 0 ;
F_13 ( & V_23 ) ;
do {
V_22 = ++ V_24 ;
} while ( V_22 == 0 );
V_21 = V_25 . V_26 ;
while ( V_21 != & V_25 ) {
V_2 = F_14 ( V_21 , struct V_1 , V_27 ) ;
if ( V_2 -> V_24 == V_22 )
break;
if ( ! F_15 ( & V_2 -> V_10 ) ) {
* V_5 = 1 ;
V_21 = V_21 -> V_26 ;
continue;
}
if ( ! F_15 ( & V_2 -> V_11 ) ) {
F_16 ( & V_2 -> V_10 ) ;
* V_5 = 1 ;
V_21 = V_21 -> V_26 ;
continue;
}
F_17 ( & V_23 ) ;
V_2 -> V_24 = V_22 ;
V_14 += F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
F_16 ( & V_2 -> V_11 ) ;
F_13 ( & V_23 ) ;
V_21 = V_21 -> V_26 ;
F_18 ( & V_2 -> V_27 , & V_25 ) ;
F_16 ( & V_2 -> V_10 ) ;
if ( V_14 >= V_3 )
break;
}
F_17 ( & V_23 ) ;
return V_14 ;
}
static int F_19 ( void )
{
int V_28 ;
struct V_1 * V_2 ;
F_13 ( & V_23 ) ;
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
F_20 (c, &ubifs_infos, infos_list) {
long V_29 ;
if ( ! F_15 ( & V_2 -> V_10 ) ) {
F_17 ( & V_23 ) ;
return - 1 ;
}
V_29 = F_5 ( & V_2 -> V_29 ) ;
if ( ! V_29 || V_2 -> V_30 == V_31 ||
V_2 -> V_32 || V_2 -> V_33 ) {
F_16 ( & V_2 -> V_10 ) ;
continue;
}
if ( V_2 -> V_30 != V_34 ) {
F_17 ( & V_23 ) ;
F_16 ( & V_2 -> V_10 ) ;
return - 1 ;
}
if ( V_28 == 1 ) {
F_18 ( & V_2 -> V_27 , & V_25 ) ;
F_17 ( & V_23 ) ;
F_21 ( V_2 ) ;
F_16 ( & V_2 -> V_10 ) ;
return - 1 ;
}
F_16 ( & V_2 -> V_10 ) ;
}
}
F_17 ( & V_23 ) ;
return 0 ;
}
unsigned long F_22 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
long V_13 = F_5 ( & V_19 ) ;
return V_13 >= 0 ? V_13 : 1 ;
}
unsigned long F_23 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
unsigned long V_3 = V_38 -> V_39 ;
int V_5 = 0 ;
unsigned long V_14 ;
long V_13 = F_5 ( & V_19 ) ;
if ( ! V_13 ) {
F_24 ( L_1 ) ;
return F_19 () ;
}
V_14 = F_12 ( V_3 , V_40 , & V_5 ) ;
if ( V_14 >= V_3 )
goto V_41;
F_24 ( L_2 ) ;
V_14 += F_12 ( V_3 - V_14 , V_42 , & V_5 ) ;
if ( V_14 >= V_3 )
goto V_41;
F_24 ( L_3 ) ;
V_14 += F_12 ( V_3 - V_14 , 0 , & V_5 ) ;
if ( ! V_14 && V_5 ) {
F_24 ( L_4 ) ;
return V_43 ;
}
V_41:
F_24 ( L_5 , V_14 , V_3 ) ;
return V_14 ;
}
