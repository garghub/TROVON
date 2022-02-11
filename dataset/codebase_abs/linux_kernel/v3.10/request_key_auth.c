static int F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
V_1 -> V_4 . V_5 = (struct V_6 * ) V_3 -> V_5 ;
return 0 ;
}
static void F_2 ( const struct V_1 * V_1 ,
struct V_7 * V_8 )
{
struct V_6 * V_9 = V_1 -> V_4 . V_5 ;
F_3 ( V_8 , L_1 ) ;
F_3 ( V_8 , V_1 -> V_10 ) ;
if ( F_4 ( V_1 ) )
F_5 ( V_8 , L_2 , V_9 -> V_11 , V_9 -> V_12 ) ;
}
static long F_6 ( const struct V_1 * V_1 ,
char T_1 * V_13 , T_2 V_14 )
{
struct V_6 * V_9 = V_1 -> V_4 . V_5 ;
T_2 V_15 ;
long V_16 ;
V_15 = V_9 -> V_12 ;
V_16 = V_15 ;
if ( V_13 && V_14 > 0 ) {
if ( V_14 > V_15 )
V_14 = V_15 ;
if ( F_7 ( V_13 , V_9 -> V_17 , V_14 ) != 0 )
V_16 = - V_18 ;
}
return V_16 ;
}
static void F_8 ( struct V_1 * V_1 )
{
struct V_6 * V_9 = V_1 -> V_4 . V_5 ;
F_9 ( L_3 , V_1 -> V_19 ) ;
if ( V_9 -> V_20 ) {
F_10 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
}
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_6 * V_9 = V_1 -> V_4 . V_5 ;
F_9 ( L_3 , V_1 -> V_19 ) ;
if ( V_9 -> V_20 ) {
F_10 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
}
F_12 ( V_9 -> V_21 ) ;
F_12 ( V_9 -> V_22 ) ;
F_13 ( V_9 -> V_17 ) ;
F_13 ( V_9 ) ;
}
struct V_1 * F_14 ( struct V_1 * V_23 , const void * V_17 ,
T_2 V_12 , struct V_1 * V_22 )
{
struct V_6 * V_9 , * V_24 ;
const struct V_20 * V_20 = V_25 -> V_20 ;
struct V_1 * V_26 = NULL ;
char V_27 [ 20 ] ;
int V_16 ;
F_9 ( L_4 , V_23 -> V_19 ) ;
V_9 = F_15 ( sizeof( * V_9 ) , V_28 ) ;
if ( ! V_9 ) {
F_16 ( L_5 ) ;
return F_17 ( - V_29 ) ;
}
V_9 -> V_17 = F_15 ( V_12 , V_28 ) ;
if ( ! V_9 -> V_17 ) {
F_16 ( L_5 ) ;
F_13 ( V_9 ) ;
return F_17 ( - V_29 ) ;
}
if ( V_20 -> V_6 ) {
F_18 ( & V_20 -> V_6 -> V_30 ) ;
if ( F_19 ( V_31 , & V_20 -> V_6 -> V_32 ) )
goto V_33;
V_24 = V_20 -> V_6 -> V_4 . V_5 ;
V_9 -> V_20 = F_20 ( V_24 -> V_20 ) ;
V_9 -> V_11 = V_24 -> V_11 ;
F_21 ( & V_20 -> V_6 -> V_30 ) ;
}
else {
V_9 -> V_20 = F_20 ( V_20 ) ;
V_9 -> V_11 = V_25 -> V_11 ;
}
V_9 -> V_21 = F_22 ( V_23 ) ;
V_9 -> V_22 = F_22 ( V_22 ) ;
memcpy ( V_9 -> V_17 , V_17 , V_12 ) ;
V_9 -> V_12 = V_12 ;
sprintf ( V_27 , L_6 , V_23 -> V_19 ) ;
V_26 = F_23 ( & V_34 , V_27 ,
V_20 -> V_35 , V_20 -> V_36 , V_20 ,
V_37 | V_38 | V_39 |
V_40 , V_41 ) ;
if ( F_24 ( V_26 ) ) {
V_16 = F_25 ( V_26 ) ;
goto V_42;
}
V_16 = F_26 ( V_26 , V_9 , 0 , NULL , NULL ) ;
if ( V_16 < 0 )
goto V_43;
F_16 ( L_7 , V_26 -> V_19 , F_27 ( & V_26 -> V_44 ) ) ;
return V_26 ;
V_33:
F_21 ( & V_20 -> V_6 -> V_30 ) ;
F_13 ( V_9 -> V_17 ) ;
F_13 ( V_9 ) ;
F_16 ( L_8 ) ;
return F_17 ( - V_45 ) ;
V_43:
F_28 ( V_26 ) ;
F_12 ( V_26 ) ;
V_42:
F_12 ( V_9 -> V_21 ) ;
F_12 ( V_9 -> V_22 ) ;
F_13 ( V_9 -> V_17 ) ;
F_13 ( V_9 ) ;
F_16 ( L_9 , V_16 ) ;
return F_17 ( V_16 ) ;
}
static int F_29 ( const struct V_1 * V_1 ,
const void * V_46 )
{
struct V_6 * V_9 = V_1 -> V_4 . V_5 ;
T_3 V_47 = ( T_3 ) ( unsigned long ) V_46 ;
return V_9 -> V_21 -> V_19 == V_47 ;
}
struct V_1 * F_30 ( T_3 V_48 )
{
const struct V_20 * V_20 = F_31 () ;
struct V_1 * V_26 ;
T_4 V_49 ;
V_49 = F_32 (
& V_34 ,
( void * ) ( unsigned long ) V_48 ,
F_29 ,
V_20 ) ;
if ( F_24 ( V_49 ) ) {
V_26 = F_33 ( V_49 ) ;
if ( V_26 == F_17 ( - V_50 ) )
V_26 = F_17 ( - V_51 ) ;
goto error;
}
V_26 = F_34 ( V_49 ) ;
if ( F_19 ( V_31 , & V_26 -> V_32 ) ) {
F_12 ( V_26 ) ;
V_26 = F_17 ( - V_45 ) ;
}
error:
return V_26 ;
}
