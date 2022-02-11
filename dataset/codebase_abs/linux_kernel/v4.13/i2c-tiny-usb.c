static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
unsigned char * V_6 ;
struct V_3 * V_7 ;
int V_8 , V_9 ;
F_2 ( & V_2 -> V_10 , L_1 , V_5 ) ;
V_6 = F_3 ( sizeof( * V_6 ) , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ ) {
int V_13 = V_14 ;
if ( V_8 == 0 )
V_13 |= V_15 ;
if ( V_8 == V_5 - 1 )
V_13 |= V_16 ;
V_7 = & V_4 [ V_8 ] ;
F_2 ( & V_2 -> V_10 ,
L_2 ,
V_8 , V_7 -> V_17 & V_18 ? L_3 : L_4 ,
V_7 -> V_17 , V_7 -> V_19 , V_7 -> V_20 ) ;
if ( V_7 -> V_17 & V_18 ) {
if ( F_4 ( V_2 , V_13 ,
V_7 -> V_17 , V_7 -> V_20 ,
V_7 -> V_21 , V_7 -> V_19 ) != V_7 -> V_19 ) {
F_5 ( & V_2 -> V_10 ,
L_5 ) ;
V_9 = - V_22 ;
goto V_23;
}
} else {
if ( F_6 ( V_2 , V_13 ,
V_7 -> V_17 , V_7 -> V_20 ,
V_7 -> V_21 , V_7 -> V_19 ) != V_7 -> V_19 ) {
F_5 ( & V_2 -> V_10 ,
L_6 ) ;
V_9 = - V_22 ;
goto V_23;
}
}
if ( F_4 ( V_2 , V_24 , 0 , 0 , V_6 , 1 ) != 1 ) {
F_5 ( & V_2 -> V_10 , L_7 ) ;
V_9 = - V_22 ;
goto V_23;
}
F_2 ( & V_2 -> V_10 , L_8 , * V_6 ) ;
if ( * V_6 == V_25 ) {
V_9 = - V_22 ;
goto V_23;
}
}
V_9 = V_8 ;
V_23:
F_7 ( V_6 ) ;
return V_9 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
T_2 * V_26 ;
T_1 V_9 ;
V_26 = F_3 ( sizeof( * V_26 ) , V_11 ) ;
if ( ! V_26 || F_4 ( V_2 , V_27 , 0 , 0 , V_26 ,
sizeof( * V_26 ) ) != sizeof( * V_26 ) ) {
F_5 ( & V_2 -> V_10 , L_9 ) ;
V_9 = 0 ;
goto V_23;
}
V_9 = F_9 ( V_26 ) ;
V_23:
F_7 ( V_26 ) ;
return V_9 ;
}
static int F_4 ( struct V_1 * V_2 , int V_13 ,
int V_28 , int V_29 , void * V_30 , int V_19 )
{
struct V_31 * V_10 = (struct V_31 * ) V_2 -> V_32 ;
void * V_33 = F_3 ( V_19 , V_11 ) ;
int V_9 ;
if ( ! V_33 )
return - V_12 ;
V_9 = F_10 ( V_10 -> V_34 , F_11 ( V_10 -> V_34 , 0 ) ,
V_13 , V_35 | V_36 |
V_37 , V_28 , V_29 , V_33 , V_19 , 2000 ) ;
memcpy ( V_30 , V_33 , V_19 ) ;
F_7 ( V_33 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , int V_13 ,
int V_28 , int V_29 , void * V_30 , int V_19 )
{
struct V_31 * V_10 = (struct V_31 * ) V_2 -> V_32 ;
void * V_33 = F_12 ( V_30 , V_19 , V_11 ) ;
int V_9 ;
if ( ! V_33 )
return - V_12 ;
V_9 = F_10 ( V_10 -> V_34 , F_13 ( V_10 -> V_34 , 0 ) ,
V_13 , V_35 | V_36 ,
V_28 , V_29 , V_33 , V_19 , 2000 ) ;
F_7 ( V_33 ) ;
return V_9 ;
}
static void F_14 ( struct V_31 * V_10 )
{
F_15 ( V_10 -> V_34 ) ;
F_7 ( V_10 ) ;
}
static int F_16 ( struct V_38 * V_39 ,
const struct V_40 * V_41 )
{
struct V_31 * V_10 ;
int V_42 = - V_12 ;
T_3 V_43 ;
F_2 ( & V_39 -> V_10 , L_10 ) ;
V_10 = F_17 ( sizeof( * V_10 ) , V_11 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_39 -> V_10 , L_11 ) ;
goto error;
}
V_10 -> V_34 = F_18 ( F_19 ( V_39 ) ) ;
V_10 -> V_39 = V_39 ;
F_20 ( V_39 , V_10 ) ;
V_43 = F_21 ( V_10 -> V_34 -> V_44 . V_45 ) ;
F_22 ( & V_39 -> V_10 ,
L_12 ,
V_43 >> 8 , V_43 & 0xff ,
V_10 -> V_34 -> V_46 -> V_47 , V_10 -> V_34 -> V_48 ) ;
V_10 -> V_2 . V_49 = V_50 ;
V_10 -> V_2 . V_51 = V_52 ;
V_10 -> V_2 . V_53 = & V_54 ;
V_10 -> V_2 . V_32 = V_10 ;
snprintf ( V_10 -> V_2 . V_55 , sizeof( V_10 -> V_2 . V_55 ) ,
L_13 ,
V_10 -> V_34 -> V_46 -> V_47 , V_10 -> V_34 -> V_48 ) ;
if ( F_6 ( & V_10 -> V_2 , V_56 , V_57 , 0 , NULL , 0 ) != 0 ) {
F_5 ( & V_10 -> V_2 . V_10 ,
L_14 , V_57 ) ;
V_42 = - V_58 ;
goto error;
}
V_10 -> V_2 . V_10 . V_59 = & V_10 -> V_39 -> V_10 ;
F_23 ( & V_10 -> V_2 ) ;
F_22 ( & V_10 -> V_2 . V_10 , L_15 ) ;
return 0 ;
error:
if ( V_10 )
F_14 ( V_10 ) ;
return V_42 ;
}
static void F_24 ( struct V_38 * V_39 )
{
struct V_31 * V_10 = F_25 ( V_39 ) ;
F_26 ( & V_10 -> V_2 ) ;
F_20 ( V_39 , NULL ) ;
F_14 ( V_10 ) ;
F_2 ( & V_39 -> V_10 , L_16 ) ;
}
