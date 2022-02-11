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
V_13 -> V_23 -> V_25 = V_26 ;
V_13 -> V_27 = V_28 ;
V_13 -> V_29 = 1 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_30 * V_6 = V_2 -> V_6 ;
int V_31 ;
V_31 = F_1 ( V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_13 -> V_14 = F_6 ( V_6 -> V_32 -> V_33 , V_6 -> V_7 ) ;
V_13 -> V_10 = V_31 ;
V_13 -> V_15 = V_34 ;
V_13 -> V_17 = 2 ;
V_13 -> V_18 = 1 ;
V_13 -> V_19 = 1 ;
V_13 -> V_20 -> V_21 = NULL ;
V_13 -> V_20 -> V_22 = 0 ;
V_13 -> V_23 -> V_24 = 16 ;
V_13 -> V_23 -> V_25 = V_26 ;
V_13 -> V_23 -> V_35 = 1 ;
V_13 -> V_27 = V_28 ;
V_13 -> V_29 = 1 ;
return 0 ;
}
static int F_7 ( struct V_30 * V_6 ,
const struct V_36 * V_37 )
{
struct V_1 * V_2 = (struct V_1 * ) V_37 -> V_38 ;
struct V_12 * V_13 ;
struct V_39 V_40 ;
int V_41 ;
int V_31 ;
V_13 = F_8 ( & V_6 -> V_42 , sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 )
return - V_44 ;
V_13 -> V_20 = F_8 ( & V_6 -> V_42 ,
sizeof( * V_13 -> V_20 ) ,
V_43 ) ;
if ( ! V_13 -> V_20 )
return - V_44 ;
V_13 -> V_23 = F_8 ( & V_6 -> V_42 , sizeof( * V_13 -> V_23 ) ,
V_43 ) ;
if ( ! V_13 -> V_23 )
return - V_44 ;
V_31 = F_9 ( V_6 ) ;
if ( V_31 ) {
F_10 ( & V_6 -> V_42 , L_1 ,
V_45 ) ;
return V_31 ;
}
for ( V_41 = 0 ; V_41 <= V_46 ; V_41 ++ ) {
if ( F_11 ( V_6 , V_41 ) == 0 )
continue;
V_31 = F_12 ( V_6 , F_13 ( V_41 ) , F_14 ( V_6 ) ) ;
if ( V_31 )
return V_31 ;
break;
}
F_15 ( V_6 ) ;
if ( V_2 ) {
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_47 ) {
V_31 = V_2 -> V_47 ( V_13 , V_2 ) ;
if ( V_31 )
return V_31 ;
}
} else
F_4 ( V_13 ) ;
F_16 ( V_6 ) ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
V_40 . V_48 = F_17 ( V_6 ) [ V_41 ] ;
V_40 . V_49 = V_6 -> V_50 ;
V_40 . V_50 = V_6 -> V_50 ;
return F_18 ( & V_6 -> V_42 , V_13 , & V_40 ) ;
}
static void F_19 ( struct V_30 * V_6 )
{
struct V_51 * V_52 = F_20 ( V_6 ) ;
F_21 ( V_52 ) ;
}
static int F_22 ( struct V_53 * V_42 )
{
struct V_30 * V_6 = F_23 ( V_42 ) ;
struct V_51 * V_52 = F_20 ( V_6 ) ;
return F_24 ( V_52 ) ;
}
static int F_25 ( struct V_53 * V_42 )
{
struct V_30 * V_6 = F_23 ( V_42 ) ;
struct V_51 * V_52 = F_20 ( V_6 ) ;
return F_26 ( V_52 ) ;
}
