int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_2 ( struct V_1 * V_2 )
{
}
static int F_3 ( struct V_3 * V_3 ,
struct V_1 * V_2 )
{
V_3 -> V_4 . V_5 = (struct V_6 * ) V_2 -> V_5 ;
return 0 ;
}
static void F_4 ( const struct V_3 * V_3 ,
struct V_7 * V_8 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 ;
F_5 ( V_8 , L_1 ) ;
F_5 ( V_8 , V_3 -> V_10 ) ;
if ( F_6 ( V_3 ) )
F_7 ( V_8 , L_2 , V_9 -> V_11 , V_9 -> V_12 ) ;
}
static long F_8 ( const struct V_3 * V_3 ,
char T_1 * V_13 , T_2 V_14 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 ;
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
struct V_6 * V_9 = V_3 -> V_4 . V_5 ;
F_11 ( L_3 , V_3 -> V_19 ) ;
if ( V_9 -> V_20 ) {
F_12 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
}
}
static void F_13 ( struct V_3 * V_3 )
{
struct V_6 * V_9 = V_3 -> V_4 . V_5 ;
F_11 ( L_3 , V_3 -> V_19 ) ;
if ( V_9 -> V_20 ) {
F_12 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
}
F_14 ( V_9 -> V_21 ) ;
F_14 ( V_9 -> V_22 ) ;
F_15 ( V_9 -> V_17 ) ;
F_15 ( V_9 ) ;
}
struct V_3 * F_16 ( struct V_3 * V_23 , const void * V_17 ,
T_2 V_12 , struct V_3 * V_22 )
{
struct V_6 * V_9 , * V_24 ;
const struct V_20 * V_20 = V_25 -> V_20 ;
struct V_3 * V_26 = NULL ;
char V_27 [ 20 ] ;
int V_16 ;
F_11 ( L_4 , V_23 -> V_19 ) ;
V_9 = F_17 ( sizeof( * V_9 ) , V_28 ) ;
if ( ! V_9 ) {
F_18 ( L_5 ) ;
return F_19 ( - V_29 ) ;
}
V_9 -> V_17 = F_17 ( V_12 , V_28 ) ;
if ( ! V_9 -> V_17 ) {
F_18 ( L_5 ) ;
F_15 ( V_9 ) ;
return F_19 ( - V_29 ) ;
}
if ( V_20 -> V_6 ) {
F_20 ( & V_20 -> V_6 -> V_30 ) ;
if ( F_21 ( V_31 , & V_20 -> V_6 -> V_32 ) )
goto V_33;
V_24 = V_20 -> V_6 -> V_4 . V_5 ;
V_9 -> V_20 = F_22 ( V_24 -> V_20 ) ;
V_9 -> V_11 = V_24 -> V_11 ;
F_23 ( & V_20 -> V_6 -> V_30 ) ;
}
else {
V_9 -> V_20 = F_22 ( V_20 ) ;
V_9 -> V_11 = V_25 -> V_11 ;
}
V_9 -> V_21 = F_24 ( V_23 ) ;
V_9 -> V_22 = F_24 ( V_22 ) ;
memcpy ( V_9 -> V_17 , V_17 , V_12 ) ;
V_9 -> V_12 = V_12 ;
sprintf ( V_27 , L_6 , V_23 -> V_19 ) ;
V_26 = F_25 ( & V_34 , V_27 ,
V_20 -> V_35 , V_20 -> V_36 , V_20 ,
V_37 | V_38 | V_39 |
V_40 , V_41 ) ;
if ( F_26 ( V_26 ) ) {
V_16 = F_27 ( V_26 ) ;
goto V_42;
}
V_16 = F_28 ( V_26 , V_9 , 0 , NULL , NULL ) ;
if ( V_16 < 0 )
goto V_43;
F_18 ( L_7 , V_26 -> V_19 , F_29 ( & V_26 -> V_44 ) ) ;
return V_26 ;
V_33:
F_23 ( & V_20 -> V_6 -> V_30 ) ;
F_15 ( V_9 -> V_17 ) ;
F_15 ( V_9 ) ;
F_18 ( L_8 ) ;
return F_19 ( - V_45 ) ;
V_43:
F_30 ( V_26 ) ;
F_14 ( V_26 ) ;
V_42:
F_14 ( V_9 -> V_21 ) ;
F_14 ( V_9 -> V_22 ) ;
F_15 ( V_9 -> V_17 ) ;
F_15 ( V_9 ) ;
F_18 ( L_9 , V_16 ) ;
return F_19 ( V_16 ) ;
}
struct V_3 * F_31 ( T_3 V_46 )
{
char V_10 [ 16 ] ;
struct V_47 V_48 = {
. V_49 . type = & V_34 ,
. V_49 . V_10 = V_10 ,
. V_20 = F_32 () ,
. V_50 = V_51 ,
. V_52 = V_10 ,
. V_32 = V_53 ,
} ;
struct V_3 * V_26 ;
T_4 V_54 ;
sprintf ( V_10 , L_6 , V_46 ) ;
V_54 = F_33 ( & V_48 ) ;
if ( F_26 ( V_54 ) ) {
V_26 = F_34 ( V_54 ) ;
if ( V_26 == F_19 ( - V_55 ) )
V_26 = F_19 ( - V_56 ) ;
goto error;
}
V_26 = F_35 ( V_54 ) ;
if ( F_21 ( V_31 , & V_26 -> V_32 ) ) {
F_14 ( V_26 ) ;
V_26 = F_19 ( - V_45 ) ;
}
error:
return V_26 ;
}
