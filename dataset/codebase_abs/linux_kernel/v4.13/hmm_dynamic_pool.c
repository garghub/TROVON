static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
unsigned int V_4 , bool V_5 )
{
struct V_6 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 = 0 ;
struct V_9 * V_10 = V_1 ;
if ( ! V_10 )
return 0 ;
F_2 ( & V_10 -> V_11 , V_7 ) ;
if ( V_10 -> V_12 ) {
while ( ! F_3 ( & V_10 -> V_13 ) ) {
V_6 = F_4 ( V_10 -> V_13 . V_14 ,
struct V_6 , V_15 ) ;
F_5 ( & V_6 -> V_15 ) ;
V_10 -> V_16 -- ;
F_6 ( & V_10 -> V_11 , V_7 ) ;
V_3 [ V_8 ] . V_17 = V_6 -> V_17 ;
V_3 [ V_8 ++ ] . type = V_18 ;
F_7 ( V_10 -> V_19 , V_6 ) ;
if ( V_8 == V_4 )
return V_8 ;
F_2 ( & V_10 -> V_11 , V_7 ) ;
}
}
F_6 ( & V_10 -> V_11 , V_7 ) ;
return V_8 ;
}
static void F_8 ( void * V_1 ,
struct V_2 * V_3 )
{
struct V_6 * V_6 ;
unsigned long V_7 ;
int V_20 ;
struct V_9 * V_10 = V_1 ;
if ( ! V_10 )
return;
F_2 ( & V_10 -> V_11 , V_7 ) ;
if ( ! V_10 -> V_12 ) {
F_6 ( & V_10 -> V_11 , V_7 ) ;
return;
}
F_6 ( & V_10 -> V_11 , V_7 ) ;
if ( V_3 -> type == V_21 )
return;
if ( V_10 -> V_16 >= V_10 -> V_22 ) {
V_20 = F_9 ( V_3 -> V_17 , 1 ) ;
if ( V_20 )
F_10 ( V_23 ,
L_1 , V_20 ) ;
if ( ! V_20 ) {
F_11 ( V_3 -> V_17 , 0 ) ;
V_24 . V_25 -- ;
}
return;
}
V_6 = F_12 ( V_10 -> V_19 ,
V_26 ) ;
if ( ! V_6 ) {
F_10 ( V_23 , L_2 ) ;
V_20 = F_9 ( V_3 -> V_17 , 1 ) ;
if ( V_20 )
F_10 ( V_23 ,
L_1 , V_20 ) ;
if ( ! V_20 ) {
F_11 ( V_3 -> V_17 , 0 ) ;
V_24 . V_25 -- ;
}
return;
}
V_6 -> V_17 = V_3 -> V_17 ;
F_2 ( & V_10 -> V_11 , V_7 ) ;
F_13 ( & V_6 -> V_15 , & V_10 -> V_13 ) ;
V_10 -> V_16 ++ ;
F_6 ( & V_10 -> V_11 , V_7 ) ;
V_24 . V_27 ++ ;
}
static int F_14 ( void * * V_1 , unsigned int V_22 )
{
struct V_9 * V_10 ;
if ( V_22 == 0 )
return 0 ;
V_10 = F_15 ( sizeof( struct V_9 ) ,
V_26 ) ;
if ( F_16 ( ! V_10 ) ) {
F_10 ( V_23 , L_3 ) ;
return - V_28 ;
}
V_10 -> V_19 = F_17 ( L_4 ,
sizeof( struct V_6 ) , 0 ,
V_29 , NULL ) ;
if ( ! V_10 -> V_19 ) {
F_18 ( V_10 ) ;
return - V_28 ;
}
F_19 ( & V_10 -> V_13 ) ;
F_20 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = true ;
V_10 -> V_22 = V_22 ;
V_10 -> V_16 = 0 ;
* V_1 = V_10 ;
return 0 ;
}
static void F_21 ( void * * V_1 )
{
struct V_9 * V_10 = * V_1 ;
struct V_6 * V_6 ;
unsigned long V_7 ;
int V_20 ;
if ( ! V_10 )
return;
F_2 ( & V_10 -> V_11 , V_7 ) ;
if ( ! V_10 -> V_12 ) {
F_6 ( & V_10 -> V_11 , V_7 ) ;
return;
}
V_10 -> V_12 = false ;
while ( ! F_3 ( & V_10 -> V_13 ) ) {
V_6 = F_4 ( V_10 -> V_13 . V_14 ,
struct V_6 , V_15 ) ;
F_5 ( & V_6 -> V_15 ) ;
F_6 ( & V_10 -> V_11 , V_7 ) ;
V_20 = F_9 ( V_6 -> V_17 , 1 ) ;
if ( V_20 )
F_10 ( V_23 ,
L_5 , V_20 ) ;
if ( ! V_20 ) {
F_11 ( V_6 -> V_17 , 0 ) ;
V_24 . V_27 -- ;
V_24 . V_25 -- ;
}
F_7 ( V_10 -> V_19 , V_6 ) ;
F_2 ( & V_10 -> V_11 , V_7 ) ;
}
F_6 ( & V_10 -> V_11 , V_7 ) ;
F_22 ( V_10 -> V_19 ) ;
F_18 ( V_10 ) ;
* V_1 = NULL ;
}
static int F_23 ( void * V_1 )
{
struct V_9 * V_10 = V_1 ;
if ( ! V_10 )
return 0 ;
return V_10 -> V_12 ;
}
