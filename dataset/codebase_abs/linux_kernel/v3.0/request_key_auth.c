static int F_1 ( struct V_1 * V_1 ,
const void * V_2 ,
T_1 V_3 )
{
V_1 -> V_4 . V_2 = (struct V_5 * ) V_2 ;
return 0 ;
}
static void F_2 ( const struct V_1 * V_1 ,
struct V_6 * V_7 )
{
struct V_5 * V_8 = V_1 -> V_4 . V_2 ;
F_3 ( V_7 , L_1 ) ;
F_3 ( V_7 , V_1 -> V_9 ) ;
if ( F_4 ( V_1 ) )
F_5 ( V_7 , L_2 , V_8 -> V_10 , V_8 -> V_11 ) ;
}
static long F_6 ( const struct V_1 * V_1 ,
char T_2 * V_12 , T_1 V_13 )
{
struct V_5 * V_8 = V_1 -> V_4 . V_2 ;
T_1 V_3 ;
long V_14 ;
V_3 = V_8 -> V_11 ;
V_14 = V_3 ;
if ( V_12 && V_13 > 0 ) {
if ( V_13 > V_3 )
V_13 = V_3 ;
if ( F_7 ( V_12 , V_8 -> V_15 , V_13 ) != 0 )
V_14 = - V_16 ;
}
return V_14 ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_5 * V_8 = V_1 -> V_4 . V_2 ;
F_9 ( L_3 , V_1 -> V_17 ) ;
if ( V_8 -> V_18 ) {
F_10 ( V_8 -> V_18 ) ;
V_8 -> V_18 = NULL ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_5 * V_8 = V_1 -> V_4 . V_2 ;
F_9 ( L_3 , V_1 -> V_17 ) ;
if ( V_8 -> V_18 ) {
F_10 ( V_8 -> V_18 ) ;
V_8 -> V_18 = NULL ;
}
F_12 ( V_8 -> V_19 ) ;
F_12 ( V_8 -> V_20 ) ;
F_13 ( V_8 -> V_15 ) ;
F_13 ( V_8 ) ;
}
struct V_1 * F_14 ( struct V_1 * V_21 , const void * V_15 ,
T_1 V_11 , struct V_1 * V_20 )
{
struct V_5 * V_8 , * V_22 ;
const struct V_18 * V_18 = V_23 -> V_18 ;
struct V_1 * V_24 = NULL ;
char V_25 [ 20 ] ;
int V_14 ;
F_9 ( L_4 , V_21 -> V_17 ) ;
V_8 = F_15 ( sizeof( * V_8 ) , V_26 ) ;
if ( ! V_8 ) {
F_16 ( L_5 ) ;
return F_17 ( - V_27 ) ;
}
V_8 -> V_15 = F_15 ( V_11 , V_26 ) ;
if ( ! V_8 -> V_15 ) {
F_16 ( L_5 ) ;
F_13 ( V_8 ) ;
return F_17 ( - V_27 ) ;
}
if ( V_18 -> V_5 ) {
F_18 ( & V_18 -> V_5 -> V_28 ) ;
if ( F_19 ( V_29 , & V_18 -> V_5 -> V_30 ) )
goto V_31;
V_22 = V_18 -> V_5 -> V_4 . V_2 ;
V_8 -> V_18 = F_20 ( V_22 -> V_18 ) ;
V_8 -> V_10 = V_22 -> V_10 ;
F_21 ( & V_18 -> V_5 -> V_28 ) ;
}
else {
V_8 -> V_18 = F_20 ( V_18 ) ;
V_8 -> V_10 = V_23 -> V_10 ;
}
V_8 -> V_19 = F_22 ( V_21 ) ;
V_8 -> V_20 = F_22 ( V_20 ) ;
memcpy ( V_8 -> V_15 , V_15 , V_11 ) ;
V_8 -> V_11 = V_11 ;
sprintf ( V_25 , L_6 , V_21 -> V_17 ) ;
V_24 = F_23 ( & V_32 , V_25 ,
V_18 -> V_33 , V_18 -> V_34 , V_18 ,
V_35 | V_36 | V_37 |
V_38 , V_39 ) ;
if ( F_24 ( V_24 ) ) {
V_14 = F_25 ( V_24 ) ;
goto V_40;
}
V_14 = F_26 ( V_24 , V_8 , 0 , NULL , NULL ) ;
if ( V_14 < 0 )
goto V_41;
F_16 ( L_7 , V_24 -> V_17 , F_27 ( & V_24 -> V_42 ) ) ;
return V_24 ;
V_31:
F_21 ( & V_18 -> V_5 -> V_28 ) ;
F_13 ( V_8 -> V_15 ) ;
F_13 ( V_8 ) ;
F_16 ( L_8 ) ;
return F_17 ( - V_43 ) ;
V_41:
F_28 ( V_24 ) ;
F_12 ( V_24 ) ;
V_40:
F_12 ( V_8 -> V_19 ) ;
F_12 ( V_8 -> V_20 ) ;
F_13 ( V_8 -> V_15 ) ;
F_13 ( V_8 ) ;
F_16 ( L_9 , V_14 ) ;
return F_17 ( V_14 ) ;
}
static int F_29 ( const struct V_1 * V_1 ,
const void * V_44 )
{
struct V_5 * V_8 = V_1 -> V_4 . V_2 ;
T_3 V_45 = ( T_3 ) ( unsigned long ) V_44 ;
return V_8 -> V_19 -> V_17 == V_45 ;
}
struct V_1 * F_30 ( T_3 V_46 )
{
const struct V_18 * V_18 = F_31 () ;
struct V_1 * V_24 ;
T_4 V_47 ;
V_47 = F_32 (
& V_32 ,
( void * ) ( unsigned long ) V_46 ,
F_29 ,
V_18 ) ;
if ( F_24 ( V_47 ) ) {
V_24 = F_33 ( V_47 ) ;
goto error;
}
V_24 = F_34 ( V_47 ) ;
if ( F_19 ( V_29 , & V_24 -> V_30 ) ) {
F_12 ( V_24 ) ;
V_24 = F_17 ( - V_43 ) ;
}
error:
return V_24 ;
}
