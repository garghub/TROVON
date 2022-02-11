int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 , struct V_7 * V_8 )
{
int V_9 ;
if ( V_5 <= 0 ) {
F_2 ( L_1 , V_5 ) ;
goto V_10;
}
if ( V_5 > V_2 -> V_11 . V_12 ) {
F_2 ( L_2 ,
V_5 , V_2 -> V_11 . V_12 ) ;
goto V_10;
}
if ( V_4 ) {
V_9 = F_3 ( V_4 -> V_13 ) ;
if ( V_5 < V_9 ) {
F_2 ( L_3 ,
V_5 , V_9 ) ;
goto V_10;
}
}
return 0 ;
V_10:
return - V_14 ;
}
static void F_4 ( unsigned long V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) V_15 ;
unsigned long V_16 ;
F_5 ( & V_4 -> V_17 , V_16 ) ;
if ( V_4 -> V_18 ) {
F_6 ( & V_4 -> V_17 , V_16 ) ;
return;
}
F_6 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_19 . V_20 ( & V_4 -> V_19 , V_4 -> V_19 . V_21 ) ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 , struct V_22 * V_23 ,
struct V_7 * V_8 )
{
int V_24 ;
V_4 -> V_13 = F_8 ( V_2 , & V_5 ,
sizeof( struct V_25 ) ) ;
if ( ! V_4 -> V_13 ) {
F_2 ( L_4 ) ;
return - V_26 ;
}
V_24 = F_9 ( V_2 , V_8 , false , V_23 , V_4 -> V_13 -> V_27 ,
V_4 -> V_13 -> V_28 , & V_4 -> V_13 -> V_29 ) ;
if ( V_24 ) {
F_10 ( V_4 -> V_13 -> V_27 ) ;
F_11 ( V_4 -> V_13 ) ;
return V_24 ;
}
if ( V_8 )
V_4 -> V_30 = 1 ;
V_4 -> V_18 = false ;
F_12 ( & V_4 -> V_31 , F_4 , ( unsigned long ) V_4 ) ;
F_13 ( & V_4 -> V_17 ) ;
V_4 -> V_19 . V_5 = V_5 ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 , int V_5 , struct V_7 * V_8 )
{
int V_24 ;
V_24 = F_15 ( V_4 -> V_13 , ( unsigned int * ) & V_5 ,
sizeof( struct V_25 ) ,
V_4 -> V_13 -> V_29 ? V_4 -> V_13 -> V_29 -> V_23 : NULL ,
V_8 , NULL , & V_4 -> V_17 ) ;
if ( ! V_24 )
V_4 -> V_19 . V_5 = V_5 ;
return V_24 ;
}
int F_16 ( struct V_3 * V_4 , struct V_25 * V_5 , int V_32 )
{
struct V_33 V_34 ;
unsigned long V_16 ;
F_5 ( & V_4 -> V_17 , V_16 ) ;
if ( F_17 ( F_18 ( V_4 -> V_13 ) ) ) {
F_6 ( & V_4 -> V_17 , V_16 ) ;
if ( V_4 -> V_19 . V_35 ) {
V_34 . V_36 = V_4 -> V_19 . V_36 ;
V_34 . V_37 . V_4 = & V_4 -> V_19 ;
V_34 . V_38 = V_39 ;
V_4 -> V_19 . V_35 ( & V_34 , V_4 -> V_19 . V_21 ) ;
}
return - V_40 ;
}
memcpy ( F_19 ( V_4 -> V_13 ) , V_5 , sizeof( * V_5 ) ) ;
F_20 () ;
F_21 ( V_4 -> V_13 ) ;
F_6 ( & V_4 -> V_17 , V_16 ) ;
if ( ( V_4 -> V_41 == V_42 ) ||
( V_4 -> V_41 == V_43 && V_32 ) ) {
V_4 -> V_41 = 0 ;
F_22 ( & V_4 -> V_31 ) ;
}
return 0 ;
}
void F_23 ( struct V_3 * V_4 )
{
unsigned long V_16 ;
F_5 ( & V_4 -> V_17 , V_16 ) ;
V_4 -> V_18 = true ;
F_6 ( & V_4 -> V_17 , V_16 ) ;
}
void F_24 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_25 ( V_45 , F_26 ( * V_4 ) , V_46 ) ;
if ( V_4 -> V_13 )
F_27 ( V_4 -> V_13 ) ;
}
