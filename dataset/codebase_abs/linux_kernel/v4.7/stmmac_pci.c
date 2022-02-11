static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = F_2 ( V_4 ) ;
unsigned int V_5 = F_3 ( V_2 -> V_6 -> V_7 ) ;
struct V_8 * V_9 ;
if ( ! V_3 )
return 1 ;
for ( V_9 = V_2 -> V_9 ; V_9 -> V_3 && * V_9 -> V_3 ; V_9 ++ ) {
if ( ! strcmp ( V_9 -> V_3 , V_3 ) && V_9 -> V_5 == V_5 )
return V_9 -> V_10 ;
}
return - V_11 ;
}
static void F_4 ( struct V_12 * V_13 )
{
V_13 -> V_14 = 1 ;
V_13 -> V_10 = 0 ;
V_13 -> V_15 = V_16 ;
V_13 -> V_17 = 2 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = 1 ;
V_13 -> V_20 -> V_21 = NULL ;
V_13 -> V_20 -> V_22 = 0 ;
V_13 -> V_23 -> V_24 = 32 ;
V_13 -> V_25 = V_26 ;
V_13 -> V_27 = 1 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_28 * V_6 = V_2 -> V_6 ;
int V_29 ;
V_29 = F_1 ( V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_13 -> V_14 = F_6 ( V_6 -> V_30 -> V_31 , V_6 -> V_7 ) ;
V_13 -> V_10 = V_29 ;
V_13 -> V_15 = V_32 ;
V_13 -> V_17 = 2 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = 1 ;
V_13 -> V_20 -> V_21 = NULL ;
V_13 -> V_20 -> V_22 = 0 ;
V_13 -> V_23 -> V_24 = 16 ;
V_13 -> V_23 -> V_33 = 1 ;
V_13 -> V_25 = V_26 ;
V_13 -> V_27 = 1 ;
return 0 ;
}
static int F_7 ( struct V_28 * V_6 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 = (struct V_1 * ) V_35 -> V_36 ;
struct V_12 * V_13 ;
struct V_37 V_38 ;
int V_39 ;
int V_29 ;
V_13 = F_8 ( & V_6 -> V_40 , sizeof( * V_13 ) , V_41 ) ;
if ( ! V_13 )
return - V_42 ;
V_13 -> V_20 = F_8 ( & V_6 -> V_40 ,
sizeof( * V_13 -> V_20 ) ,
V_41 ) ;
if ( ! V_13 -> V_20 )
return - V_42 ;
V_13 -> V_23 = F_8 ( & V_6 -> V_40 , sizeof( * V_13 -> V_23 ) ,
V_41 ) ;
if ( ! V_13 -> V_23 )
return - V_42 ;
V_29 = F_9 ( V_6 ) ;
if ( V_29 ) {
F_10 ( & V_6 -> V_40 , L_1 ,
V_43 ) ;
return V_29 ;
}
for ( V_39 = 0 ; V_39 <= V_44 ; V_39 ++ ) {
if ( F_11 ( V_6 , V_39 ) == 0 )
continue;
V_29 = F_12 ( V_6 , F_13 ( V_39 ) , F_14 ( V_6 ) ) ;
if ( V_29 )
return V_29 ;
break;
}
F_15 ( V_6 ) ;
if ( V_2 ) {
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_45 ) {
V_29 = V_2 -> V_45 ( V_13 , V_2 ) ;
if ( V_29 )
return V_29 ;
}
} else
F_4 ( V_13 ) ;
F_16 ( V_6 ) ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
V_38 . V_46 = F_17 ( V_6 ) [ V_39 ] ;
V_38 . V_47 = V_6 -> V_48 ;
V_38 . V_48 = V_6 -> V_48 ;
return F_18 ( & V_6 -> V_40 , V_13 , & V_38 ) ;
}
static void F_19 ( struct V_28 * V_6 )
{
F_20 ( & V_6 -> V_40 ) ;
}
