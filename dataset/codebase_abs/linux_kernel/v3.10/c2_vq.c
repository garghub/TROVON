int F_1 ( struct V_1 * V_2 )
{
sprintf ( V_2 -> V_3 , L_1 ,
( char ) ( '0' + V_2 -> V_4 ) ) ;
V_2 -> V_5 =
F_2 ( V_2 -> V_3 , V_2 -> V_6 . V_7 , 0 ,
V_8 , NULL ) ;
if ( V_2 -> V_5 == NULL ) {
return - V_9 ;
}
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_5 ) ;
}
struct V_10 * F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
V_11 = F_6 ( sizeof( struct V_10 ) , V_12 ) ;
if ( V_11 ) {
F_7 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 = 0 ;
V_11 -> V_16 = NULL ;
V_11 -> V_17 = NULL ;
F_8 ( & V_11 -> V_18 , 1 ) ;
F_8 ( & V_11 -> V_19 , 0 ) ;
}
return V_11 ;
}
void F_9 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
V_11 -> V_14 = 0 ;
if ( F_10 ( & V_11 -> V_18 ) ) {
F_11 ( V_11 ) ;
}
}
void F_12 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
F_13 ( & V_11 -> V_18 ) ;
}
void F_14 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( F_10 ( & V_11 -> V_18 ) ) {
if ( V_11 -> V_14 != 0 )
F_15 ( V_2 ,
( void * ) ( unsigned long ) V_11 -> V_14 ) ;
F_11 ( V_11 ) ;
}
}
void * F_16 ( struct V_1 * V_2 )
{
return F_17 ( V_2 -> V_5 , V_20 ) ;
}
int F_18 ( struct V_1 * V_2 , union V_21 * V_22 )
{
void * V_23 ;
T_1 V_24 ;
F_19 ( & V_2 -> V_25 ) ;
V_23 = F_20 ( & V_2 -> V_26 ) ;
while ( V_23 == NULL ) {
F_21 ( L_2 ,
V_27 , __LINE__ ) ;
F_22 ( & V_24 , V_28 ) ;
F_23 ( & V_2 -> V_29 , & V_24 ) ;
F_24 ( & V_2 -> V_25 ) ;
for (; ; ) {
F_25 ( V_30 ) ;
if ( ! F_26 ( & V_2 -> V_26 ) ) {
break;
}
if ( ! F_27 ( V_28 ) ) {
F_28 ( 1 * V_31 ) ;
continue;
}
F_25 ( V_32 ) ;
F_29 ( & V_2 -> V_29 , & V_24 ) ;
return - V_33 ;
}
F_25 ( V_32 ) ;
F_29 ( & V_2 -> V_29 , & V_24 ) ;
F_19 ( & V_2 -> V_25 ) ;
V_23 = F_20 ( & V_2 -> V_26 ) ;
}
memcpy ( V_23 , V_22 , V_2 -> V_26 . V_7 ) ;
F_30 ( & V_2 -> V_26 ) ;
F_24 ( & V_2 -> V_25 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_10 * V_34 )
{
if ( ! F_32 ( V_34 -> V_13 ,
F_33 ( & V_34 -> V_19 ) ,
60 * V_31 ) )
return - V_35 ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , void * V_36 )
{
F_34 ( V_2 -> V_5 , V_36 ) ;
}
