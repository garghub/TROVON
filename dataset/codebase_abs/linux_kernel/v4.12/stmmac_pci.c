static int F_1 ( struct V_1 * V_2 )
{
const char * V_3 = F_2 ( V_4 ) ;
const char * V_5 = F_2 ( V_6 ) ;
unsigned int V_7 = F_3 ( V_2 -> V_8 -> V_9 ) ;
struct V_10 * V_11 ;
if ( ! V_3 )
return 1 ;
for ( V_11 = V_2 -> V_11 ; V_11 -> V_3 && * V_11 -> V_3 ; V_11 ++ ) {
if ( ! strcmp ( V_11 -> V_3 , V_3 ) && V_11 -> V_7 == V_7 ) {
if ( V_11 -> V_5 && strcmp ( V_11 -> V_5 , V_5 ) )
continue;
return V_11 -> V_12 ;
}
}
return - V_13 ;
}
static void F_4 ( struct V_14 * V_15 )
{
V_15 -> V_16 = 2 ;
V_15 -> V_17 = 1 ;
V_15 -> V_18 = 1 ;
V_15 -> V_19 -> V_20 = NULL ;
V_15 -> V_19 -> V_21 = 0 ;
V_15 -> V_22 = V_23 ;
V_15 -> V_24 = 1 ;
V_15 -> V_25 = V_26 ;
V_15 -> V_27 = 1 ;
V_15 -> V_28 = 1 ;
V_15 -> V_29 [ 0 ] . V_30 = false ;
V_15 -> V_31 [ 0 ] . V_30 = false ;
V_15 -> V_31 [ 0 ] . V_32 = 0x0 ;
}
static void F_5 ( struct V_14 * V_15 )
{
F_4 ( V_15 ) ;
V_15 -> V_33 = 1 ;
V_15 -> V_12 = 0 ;
V_15 -> V_34 = V_35 ;
V_15 -> V_36 -> V_37 = 32 ;
V_15 -> V_36 -> V_38 = true ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_39 * V_8 = V_2 -> V_8 ;
int V_40 ;
F_4 ( V_15 ) ;
V_40 = F_1 ( V_2 ) ;
if ( V_40 < 0 )
return V_40 ;
V_15 -> V_33 = F_7 ( V_8 -> V_41 -> V_42 , V_8 -> V_9 ) ;
V_15 -> V_12 = V_40 ;
V_15 -> V_34 = V_43 ;
V_15 -> V_36 -> V_37 = 16 ;
V_15 -> V_36 -> V_38 = true ;
V_15 -> V_36 -> V_44 = 1 ;
return 0 ;
}
static int F_8 ( struct V_39 * V_8 ,
const struct V_45 * V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_46 -> V_47 ;
struct V_14 * V_15 ;
struct V_48 V_49 ;
int V_50 ;
int V_40 ;
V_15 = F_9 ( & V_8 -> V_51 , sizeof( * V_15 ) , V_52 ) ;
if ( ! V_15 )
return - V_53 ;
V_15 -> V_19 = F_9 ( & V_8 -> V_51 ,
sizeof( * V_15 -> V_19 ) ,
V_52 ) ;
if ( ! V_15 -> V_19 )
return - V_53 ;
V_15 -> V_36 = F_9 ( & V_8 -> V_51 , sizeof( * V_15 -> V_36 ) ,
V_52 ) ;
if ( ! V_15 -> V_36 )
return - V_53 ;
V_40 = F_10 ( V_8 ) ;
if ( V_40 ) {
F_11 ( & V_8 -> V_51 , L_1 ,
V_54 ) ;
return V_40 ;
}
for ( V_50 = 0 ; V_50 <= V_55 ; V_50 ++ ) {
if ( F_12 ( V_8 , V_50 ) == 0 )
continue;
V_40 = F_13 ( V_8 , F_14 ( V_50 ) , F_15 ( V_8 ) ) ;
if ( V_40 )
return V_40 ;
break;
}
F_16 ( V_8 ) ;
if ( V_2 ) {
V_2 -> V_8 = V_8 ;
if ( V_2 -> V_56 ) {
V_40 = V_2 -> V_56 ( V_15 , V_2 ) ;
if ( V_40 )
return V_40 ;
}
} else
F_5 ( V_15 ) ;
F_17 ( V_8 ) ;
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_57 = F_18 ( V_8 ) [ V_50 ] ;
V_49 . V_58 = V_8 -> V_59 ;
V_49 . V_59 = V_8 -> V_59 ;
return F_19 ( & V_8 -> V_51 , V_15 , & V_49 ) ;
}
static void F_20 ( struct V_39 * V_8 )
{
F_21 ( & V_8 -> V_51 ) ;
}
