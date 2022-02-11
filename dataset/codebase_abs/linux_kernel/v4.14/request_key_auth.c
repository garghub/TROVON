static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
}
static int F_3 ( struct V_3 * V_3 ,
struct V_1 * V_2 )
{
V_3 -> V_4 . V_5 [ 0 ] = (struct V_6 * ) V_2 -> V_5 ;
return 0 ;
}
static void F_4 ( const struct V_3 * V_3 ,
struct V_7 * V_8 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 [ 0 ] ;
F_5 ( V_8 , L_1 ) ;
F_5 ( V_8 , V_3 -> V_10 ) ;
if ( F_6 ( V_3 ) )
F_7 ( V_8 , L_2 , V_9 -> V_11 , V_9 -> V_12 ) ;
}
static long F_8 ( const struct V_3 * V_3 ,
char T_1 * V_13 , T_2 V_14 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 [ 0 ] ;
T_2 V_15 ;
long V_16 ;
V_15 = V_9 -> V_12 ;
V_16 = V_15 ;
if ( V_13 && V_14 > 0 ) {
if ( V_14 > V_15 )
V_14 = V_15 ;
if ( F_9 ( V_13 , V_9 -> V_17 , V_14 ) != 0 )
V_16 = - V_18 ;
}
return V_16 ;
}
static void F_10 ( struct V_3 * V_3 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 [ 0 ] ;
F_11 ( L_3 , V_3 -> V_19 ) ;
if ( V_9 -> V_20 ) {
F_12 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
}
}
static void F_13 ( struct V_6 * V_9 )
{
if ( ! V_9 )
return;
F_14 ( V_9 -> V_21 ) ;
F_14 ( V_9 -> V_22 ) ;
if ( V_9 -> V_20 )
F_12 ( V_9 -> V_20 ) ;
F_15 ( V_9 -> V_17 ) ;
F_15 ( V_9 ) ;
}
static void F_16 ( struct V_3 * V_3 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 [ 0 ] ;
F_11 ( L_3 , V_3 -> V_19 ) ;
F_13 ( V_9 ) ;
}
struct V_3 * F_17 ( struct V_3 * V_23 , const void * V_17 ,
T_2 V_12 , struct V_3 * V_22 )
{
struct V_6 * V_9 , * V_24 ;
const struct V_20 * V_20 = V_25 -> V_20 ;
struct V_3 * V_26 = NULL ;
char V_27 [ 20 ] ;
int V_16 = - V_28 ;
F_11 ( L_4 , V_23 -> V_19 ) ;
V_9 = F_18 ( sizeof( * V_9 ) , V_29 ) ;
if ( ! V_9 )
goto error;
V_9 -> V_17 = F_19 ( V_17 , V_12 , V_29 ) ;
if ( ! V_9 -> V_17 )
goto V_30;
V_9 -> V_12 = V_12 ;
if ( V_20 -> V_6 ) {
F_20 ( & V_20 -> V_6 -> V_31 ) ;
if ( F_21 ( V_32 ,
& V_20 -> V_6 -> V_33 ) ) {
F_22 ( & V_20 -> V_6 -> V_31 ) ;
V_16 = - V_34 ;
goto V_30;
}
V_24 = V_20 -> V_6 -> V_4 . V_5 [ 0 ] ;
V_9 -> V_20 = F_23 ( V_24 -> V_20 ) ;
V_9 -> V_11 = V_24 -> V_11 ;
F_22 ( & V_20 -> V_6 -> V_31 ) ;
}
else {
V_9 -> V_20 = F_23 ( V_20 ) ;
V_9 -> V_11 = V_25 -> V_11 ;
}
V_9 -> V_21 = F_24 ( V_23 ) ;
V_9 -> V_22 = F_24 ( V_22 ) ;
sprintf ( V_27 , L_5 , V_23 -> V_19 ) ;
V_26 = F_25 ( & V_35 , V_27 ,
V_20 -> V_36 , V_20 -> V_37 , V_20 ,
V_38 | V_39 | V_40 |
V_41 , V_42 , NULL ) ;
if ( F_26 ( V_26 ) ) {
V_16 = F_27 ( V_26 ) ;
goto V_30;
}
V_16 = F_28 ( V_26 , V_9 , 0 , NULL , NULL ) ;
if ( V_16 < 0 )
goto V_43;
F_29 ( L_6 , V_26 -> V_19 , F_30 ( & V_26 -> V_44 ) ) ;
return V_26 ;
V_43:
F_14 ( V_26 ) ;
V_30:
F_13 ( V_9 ) ;
error:
F_29 ( L_7 , V_16 ) ;
return F_31 ( V_16 ) ;
}
struct V_3 * F_32 ( T_3 V_45 )
{
char V_10 [ 16 ] ;
struct V_46 V_47 = {
. V_48 . type = & V_35 ,
. V_48 . V_10 = V_10 ,
. V_20 = F_33 () ,
. V_49 . V_50 = V_51 ,
. V_49 . V_52 = V_10 ,
. V_49 . V_53 = V_54 ,
. V_33 = V_55 ,
} ;
struct V_3 * V_26 ;
T_4 V_56 ;
sprintf ( V_10 , L_5 , V_45 ) ;
V_56 = F_34 ( & V_47 ) ;
if ( F_26 ( V_56 ) ) {
V_26 = F_35 ( V_56 ) ;
if ( V_26 == F_31 ( - V_57 ) )
V_26 = F_31 ( - V_58 ) ;
goto error;
}
V_26 = F_36 ( V_56 ) ;
if ( F_21 ( V_32 , & V_26 -> V_33 ) ) {
F_14 ( V_26 ) ;
V_26 = F_31 ( - V_34 ) ;
}
error:
return V_26 ;
}
