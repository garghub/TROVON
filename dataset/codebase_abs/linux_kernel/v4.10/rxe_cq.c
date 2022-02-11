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
V_4 -> V_16 . V_17 ( & V_4 -> V_16 , V_4 -> V_16 . V_18 ) ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 ,
int V_6 , struct V_19 * V_20 ,
struct V_7 * V_8 )
{
int V_21 ;
V_4 -> V_13 = F_6 ( V_2 , & V_5 ,
sizeof( struct V_22 ) ) ;
if ( ! V_4 -> V_13 ) {
F_2 ( L_4 ) ;
return - V_23 ;
}
V_21 = F_7 ( V_2 , V_8 , false , V_20 , V_4 -> V_13 -> V_24 ,
V_4 -> V_13 -> V_25 , & V_4 -> V_13 -> V_26 ) ;
if ( V_21 ) {
F_8 ( V_4 -> V_13 -> V_24 ) ;
F_9 ( V_4 -> V_13 ) ;
return V_21 ;
}
if ( V_8 )
V_4 -> V_27 = 1 ;
F_10 ( & V_4 -> V_28 , F_4 , ( unsigned long ) V_4 ) ;
F_11 ( & V_4 -> V_29 ) ;
V_4 -> V_16 . V_5 = V_5 ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 , int V_5 , struct V_7 * V_8 )
{
int V_21 ;
V_21 = F_13 ( V_4 -> V_13 , ( unsigned int * ) & V_5 ,
sizeof( struct V_22 ) ,
V_4 -> V_13 -> V_26 ? V_4 -> V_13 -> V_26 -> V_20 : NULL ,
V_8 , NULL , & V_4 -> V_29 ) ;
if ( ! V_21 )
V_4 -> V_16 . V_5 = V_5 ;
return V_21 ;
}
int F_14 ( struct V_3 * V_4 , struct V_22 * V_5 , int V_30 )
{
struct V_31 V_32 ;
unsigned long V_33 ;
F_15 ( & V_4 -> V_29 , V_33 ) ;
if ( F_16 ( F_17 ( V_4 -> V_13 ) ) ) {
F_18 ( & V_4 -> V_29 , V_33 ) ;
if ( V_4 -> V_16 . V_34 ) {
V_32 . V_35 = V_4 -> V_16 . V_35 ;
V_32 . V_36 . V_4 = & V_4 -> V_16 ;
V_32 . V_37 = V_38 ;
V_4 -> V_16 . V_34 ( & V_32 , V_4 -> V_16 . V_18 ) ;
}
return - V_39 ;
}
memcpy ( F_19 ( V_4 -> V_13 ) , V_5 , sizeof( * V_5 ) ) ;
F_20 () ;
F_21 ( V_4 -> V_13 ) ;
F_18 ( & V_4 -> V_29 , V_33 ) ;
if ( ( V_4 -> V_40 == V_41 ) ||
( V_4 -> V_40 == V_42 && V_30 ) ) {
V_4 -> V_40 = 0 ;
F_22 ( & V_4 -> V_28 ) ;
}
return 0 ;
}
void F_23 ( void * V_43 )
{
struct V_3 * V_4 = V_43 ;
if ( V_4 -> V_13 )
F_24 ( V_4 -> V_13 ) ;
}
