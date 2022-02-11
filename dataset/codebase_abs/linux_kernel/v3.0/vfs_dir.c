static inline int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_2 -> V_4 ;
int V_5 = V_6 ;
if ( V_3 & V_7 )
V_5 = V_8 ;
if ( V_3 & V_9 )
V_5 = V_10 ;
return V_5 ;
}
static void F_2 ( struct V_1 * V_11 )
{
V_11 -> V_12 = NULL ;
V_11 -> V_13 = NULL ;
V_11 -> V_14 = NULL ;
V_11 -> V_15 = NULL ;
V_11 -> V_16 = NULL ;
}
static int F_3 ( struct V_17 * V_18 , int V_19 )
{
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 = 0 ;
V_23 = V_18 -> V_25 ;
if ( ! V_23 -> V_21 ) {
V_21 = F_4 ( sizeof( struct V_20 ) + V_19 , V_26 ) ;
if ( V_21 == NULL ) {
V_24 = - V_27 ;
goto exit;
}
F_5 ( & V_18 -> V_28 -> V_29 ) ;
if ( ! V_23 -> V_21 ) {
V_21 -> V_30 = ( V_31 * ) V_21 + sizeof( struct V_20 ) ;
F_6 ( & V_21 -> V_32 ) ;
V_21 -> V_33 = V_21 -> V_34 = 0 ;
V_23 -> V_21 = ( void * ) V_21 ;
V_21 = NULL ;
}
F_7 ( & V_18 -> V_28 -> V_29 ) ;
F_8 ( V_21 ) ;
}
exit:
return V_24 ;
}
static int F_9 ( struct V_17 * V_18 , void * V_35 , T_1 V_36 )
{
int V_37 ;
struct V_1 V_38 ;
int V_24 = 0 ;
struct V_22 * V_23 ;
int V_19 ;
int V_39 = 0 ;
struct V_20 * V_21 ;
F_10 ( V_40 , L_1 , V_18 -> V_41 . V_42 -> V_43 . V_12 ) ;
V_23 = V_18 -> V_25 ;
V_19 = V_23 -> V_44 -> V_45 - V_46 ;
V_24 = F_3 ( V_18 , V_19 ) ;
if ( V_24 )
goto exit;
V_21 = (struct V_20 * ) V_23 -> V_21 ;
V_24 = F_11 ( & V_21 -> V_32 ) ;
if ( V_24 )
return V_24 ;
while ( V_24 == 0 ) {
if ( V_21 -> V_34 == V_21 -> V_33 ) {
V_24 = F_12 ( V_18 , V_21 -> V_30 , NULL ,
V_19 , V_18 -> V_47 ) ;
if ( V_24 <= 0 )
goto V_48;
V_21 -> V_33 = 0 ;
V_21 -> V_34 = V_24 ;
}
while ( V_21 -> V_33 < V_21 -> V_34 ) {
F_2 ( & V_38 ) ;
V_24 = F_13 ( V_21 -> V_30 + V_21 -> V_33 ,
V_21 -> V_34 - V_21 -> V_33 , & V_38 ,
V_23 -> V_44 -> V_49 ) ;
if ( V_24 ) {
F_10 ( V_40 , L_2 , V_24 ) ;
V_24 = - V_50 ;
F_14 ( & V_38 ) ;
goto V_48;
}
V_39 = V_38 . V_51 + 2 ;
V_37 = V_36 ( V_35 , V_38 . V_12 , strlen ( V_38 . V_12 ) ,
V_18 -> V_47 , F_15 ( & V_38 . V_52 ) , F_1 ( & V_38 ) ) ;
F_14 ( & V_38 ) ;
if ( V_37 ) {
V_24 = 0 ;
goto V_48;
}
V_21 -> V_33 += V_39 ;
V_18 -> V_47 += V_39 ;
}
}
V_48:
F_16 ( & V_21 -> V_32 ) ;
exit:
return V_24 ;
}
static int F_17 ( struct V_17 * V_18 , void * V_35 ,
T_1 V_36 )
{
int V_37 ;
int V_24 = 0 ;
struct V_22 * V_23 ;
int V_19 ;
struct V_20 * V_21 ;
struct V_53 V_54 ;
T_2 V_55 = 0 ;
F_10 ( V_40 , L_1 , V_18 -> V_41 . V_42 -> V_43 . V_12 ) ;
V_23 = V_18 -> V_25 ;
V_19 = V_23 -> V_44 -> V_45 - V_56 ;
V_24 = F_3 ( V_18 , V_19 ) ;
if ( V_24 )
goto exit;
V_21 = (struct V_20 * ) V_23 -> V_21 ;
V_24 = F_11 ( & V_21 -> V_32 ) ;
if ( V_24 )
return V_24 ;
while ( V_24 == 0 ) {
if ( V_21 -> V_34 == V_21 -> V_33 ) {
V_24 = F_18 ( V_23 , V_21 -> V_30 , V_19 ,
V_18 -> V_47 ) ;
if ( V_24 <= 0 )
goto V_48;
V_21 -> V_33 = 0 ;
V_21 -> V_34 = V_24 ;
}
while ( V_21 -> V_33 < V_21 -> V_34 ) {
V_24 = F_19 ( V_21 -> V_30 + V_21 -> V_33 ,
V_21 -> V_34 - V_21 -> V_33 ,
& V_54 ,
V_23 -> V_44 -> V_49 ) ;
if ( V_24 < 0 ) {
F_10 ( V_40 , L_2 , V_24 ) ;
V_24 = - V_50 ;
goto V_48;
}
V_37 = V_36 ( V_35 , V_54 . V_43 ,
strlen ( V_54 . V_43 ) ,
V_55 , F_15 ( & V_54 . V_52 ) ,
V_54 . V_57 ) ;
V_55 = V_54 . V_58 ;
if ( V_37 ) {
V_24 = 0 ;
goto V_48;
}
V_18 -> V_47 = V_54 . V_58 ;
V_21 -> V_33 += V_24 ;
}
}
V_48:
F_16 ( & V_21 -> V_32 ) ;
exit:
return V_24 ;
}
int F_20 ( struct V_59 * V_59 , struct V_17 * V_18 )
{
struct V_22 * V_23 ;
V_23 = V_18 -> V_25 ;
F_10 ( V_40 ,
L_3 ,
V_59 , V_18 , V_23 ? V_23 -> V_23 : - 1 ) ;
if ( V_23 )
F_21 ( V_23 ) ;
return 0 ;
}
