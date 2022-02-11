static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
unsigned char V_6 ;
struct V_3 * V_7 ;
int V_8 ;
F_2 ( & V_2 -> V_9 , L_1 , V_5 ) ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ ) {
int V_10 = V_11 ;
if ( V_8 == 0 )
V_10 |= V_12 ;
if ( V_8 == V_5 - 1 )
V_10 |= V_13 ;
V_7 = & V_4 [ V_8 ] ;
F_2 ( & V_2 -> V_9 ,
L_2 ,
V_8 , V_7 -> V_14 & V_15 ? L_3 : L_4 ,
V_7 -> V_14 , V_7 -> V_16 , V_7 -> V_17 ) ;
if ( V_7 -> V_14 & V_15 ) {
if ( F_3 ( V_2 , V_10 ,
V_7 -> V_14 , V_7 -> V_17 ,
V_7 -> V_18 , V_7 -> V_16 ) != V_7 -> V_16 ) {
F_4 ( & V_2 -> V_9 ,
L_5 ) ;
return - V_19 ;
}
} else {
if ( F_5 ( V_2 , V_10 ,
V_7 -> V_14 , V_7 -> V_17 ,
V_7 -> V_18 , V_7 -> V_16 ) != V_7 -> V_16 ) {
F_4 ( & V_2 -> V_9 ,
L_6 ) ;
return - V_19 ;
}
}
if ( F_3 ( V_2 , V_20 , 0 , 0 , & V_6 , 1 ) != 1 ) {
F_4 ( & V_2 -> V_9 , L_7 ) ;
return - V_19 ;
}
F_2 ( & V_2 -> V_9 , L_8 , V_6 ) ;
if ( V_6 == V_21 )
return - V_19 ;
}
return V_8 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
T_2 V_22 ;
if ( F_3 ( V_2 , V_23 , 0 , 0 , & V_22 , sizeof( V_22 ) ) !=
sizeof( V_22 ) ) {
F_4 ( & V_2 -> V_9 , L_9 ) ;
return 0 ;
}
return F_7 ( V_22 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 ,
int V_24 , int V_25 , void * V_26 , int V_16 )
{
struct V_27 * V_9 = (struct V_27 * ) V_2 -> V_28 ;
return F_8 ( V_9 -> V_29 , F_9 ( V_9 -> V_29 , 0 ) ,
V_10 , V_30 | V_31 |
V_32 , V_24 , V_25 , V_26 , V_16 , 2000 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 ,
int V_24 , int V_25 , void * V_26 , int V_16 )
{
struct V_27 * V_9 = (struct V_27 * ) V_2 -> V_28 ;
return F_8 ( V_9 -> V_29 , F_10 ( V_9 -> V_29 , 0 ) ,
V_10 , V_30 | V_31 ,
V_24 , V_25 , V_26 , V_16 , 2000 ) ;
}
static void F_11 ( struct V_27 * V_9 )
{
F_12 ( V_9 -> V_29 ) ;
F_13 ( V_9 ) ;
}
static int F_14 ( struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
struct V_27 * V_9 ;
int V_37 = - V_38 ;
T_3 V_39 ;
F_2 ( & V_34 -> V_9 , L_10 ) ;
V_9 = F_15 ( sizeof( * V_9 ) , V_40 ) ;
if ( V_9 == NULL ) {
F_4 ( & V_34 -> V_9 , L_11 ) ;
goto error;
}
V_9 -> V_29 = F_16 ( F_17 ( V_34 ) ) ;
V_9 -> V_34 = V_34 ;
F_18 ( V_34 , V_9 ) ;
V_39 = F_19 ( V_9 -> V_29 -> V_41 . V_42 ) ;
F_20 ( & V_34 -> V_9 ,
L_12 ,
V_39 >> 8 , V_39 & 0xff ,
V_9 -> V_29 -> V_43 -> V_44 , V_9 -> V_29 -> V_45 ) ;
V_9 -> V_2 . V_46 = V_47 ;
V_9 -> V_2 . V_48 = V_49 ;
V_9 -> V_2 . V_50 = & V_51 ;
V_9 -> V_2 . V_28 = V_9 ;
snprintf ( V_9 -> V_2 . V_52 , sizeof( V_9 -> V_2 . V_52 ) ,
L_13 ,
V_9 -> V_29 -> V_43 -> V_44 , V_9 -> V_29 -> V_45 ) ;
if ( F_5 ( & V_9 -> V_2 , V_53 , V_54 , 0 , NULL , 0 ) != 0 ) {
F_4 ( & V_9 -> V_2 . V_9 ,
L_14 , V_54 ) ;
V_37 = - V_55 ;
goto error;
}
V_9 -> V_2 . V_9 . V_56 = & V_9 -> V_34 -> V_9 ;
F_21 ( & V_9 -> V_2 ) ;
F_20 ( & V_9 -> V_2 . V_9 , L_15 ) ;
return 0 ;
error:
if ( V_9 )
F_11 ( V_9 ) ;
return V_37 ;
}
static void F_22 ( struct V_33 * V_34 )
{
struct V_27 * V_9 = F_23 ( V_34 ) ;
F_24 ( & V_9 -> V_2 ) ;
F_18 ( V_34 , NULL ) ;
F_11 ( V_9 ) ;
F_2 ( & V_34 -> V_9 , L_16 ) ;
}
