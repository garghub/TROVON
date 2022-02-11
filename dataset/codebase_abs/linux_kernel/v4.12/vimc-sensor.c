static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( V_6 -> V_9 )
return - V_10 ;
V_6 -> V_6 = V_8 -> V_11 . V_6 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
if ( V_13 -> V_9 )
return - V_10 ;
if ( V_13 -> V_6 != V_8 -> V_11 . V_6 )
return - V_10 ;
V_13 -> V_14 = V_8 -> V_11 . V_15 ;
V_13 -> V_16 = V_8 -> V_11 . V_15 ;
V_13 -> V_17 = V_8 -> V_11 . V_18 ;
V_13 -> V_19 = V_8 -> V_11 . V_18 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_20 * V_21 )
{
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
V_21 -> V_21 = V_8 -> V_11 ;
return 0 ;
}
static int F_5 ( void * V_22 )
{
struct V_7 * V_8 = V_22 ;
unsigned int V_23 ;
F_6 () ;
F_7 ( V_24 ) ;
for (; ; ) {
F_8 () ;
if ( F_9 () )
break;
memset ( V_8 -> V_25 , 100 , V_8 -> V_26 ) ;
for ( V_23 = 0 ; V_23 < V_8 -> V_2 . V_27 . V_28 ; V_23 ++ )
F_10 ( & V_8 -> V_2 . V_27 . V_29 [ V_23 ] ,
V_8 -> V_25 ) ;
F_11 ( V_30 / 60 ) ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_31 )
{
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
int V_32 ;
if ( V_31 ) {
const struct V_33 * V_34 ;
if ( V_8 -> V_35 )
return - V_10 ;
V_34 = F_13 ( V_8 -> V_11 . V_6 ) ;
V_8 -> V_26 = V_8 -> V_11 . V_15 * V_34 -> V_36 *
V_8 -> V_11 . V_18 ;
V_8 -> V_25 = F_14 ( V_8 -> V_26 ) ;
if ( ! V_8 -> V_25 )
return - V_37 ;
V_8 -> V_35 = F_15 ( F_5 , V_8 , L_1 ,
V_8 -> V_2 . V_38 -> V_39 ) ;
if ( F_16 ( V_8 -> V_35 ) ) {
F_17 ( V_8 -> V_2 . V_38 -> V_40 ,
L_2 , V_8 -> V_2 . V_39 ) ;
F_18 ( V_8 -> V_25 ) ;
V_8 -> V_25 = NULL ;
return F_19 ( V_8 -> V_35 ) ;
}
} else {
if ( ! V_8 -> V_35 )
return - V_10 ;
V_32 = F_20 ( V_8 -> V_35 ) ;
V_8 -> V_35 = NULL ;
F_18 ( V_8 -> V_25 ) ;
V_8 -> V_25 = NULL ;
return V_32 ;
}
return 0 ;
}
static void F_21 ( struct V_41 * V_42 )
{
struct V_7 * V_8 =
F_2 ( V_42 , struct V_7 , V_42 ) ;
F_22 ( & V_8 -> V_2 ) ;
F_23 ( V_42 -> V_43 ) ;
F_24 ( V_8 ) ;
}
struct V_41 * F_25 ( struct V_44 * V_38 ,
const char * const V_39 ,
T_1 V_28 ,
const unsigned long * V_45 )
{
struct V_7 * V_8 ;
unsigned int V_23 ;
int V_32 ;
if ( ! V_39 || ! V_28 || ! V_45 )
return F_26 ( - V_10 ) ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ )
if ( ! ( V_45 [ V_23 ] & V_46 ) )
return F_26 ( - V_10 ) ;
V_8 = F_27 ( sizeof( * V_8 ) , V_47 ) ;
if ( ! V_8 )
return F_26 ( - V_37 ) ;
V_8 -> V_42 . V_29 = F_28 ( V_28 , V_45 ) ;
if ( F_16 ( V_8 -> V_42 . V_29 ) ) {
V_32 = F_19 ( V_8 -> V_42 . V_29 ) ;
goto V_48;
}
V_8 -> V_42 . V_49 = F_21 ;
V_8 -> V_42 . V_43 = & V_8 -> V_2 . V_27 ;
F_29 ( & V_8 -> V_2 , & V_50 ) ;
V_8 -> V_2 . V_27 . V_51 = V_52 ;
V_8 -> V_2 . V_27 . V_53 = & V_54 ;
V_8 -> V_2 . V_55 = V_56 ;
F_30 ( V_8 -> V_2 . V_39 , V_39 , sizeof( V_8 -> V_2 . V_39 ) ) ;
F_31 ( & V_8 -> V_2 , & V_8 -> V_42 ) ;
V_8 -> V_2 . V_57 = V_58 ;
V_32 = F_32 ( & V_8 -> V_2 . V_27 ,
V_28 , V_8 -> V_42 . V_29 ) ;
if ( V_32 )
goto V_59;
V_8 -> V_11 . V_15 = 640 ;
V_8 -> V_11 . V_18 = 480 ;
V_8 -> V_11 . V_6 = V_60 ;
V_8 -> V_11 . V_61 = V_62 ;
V_8 -> V_11 . V_63 = V_64 ;
V_8 -> V_11 . V_65 = V_66 ;
V_8 -> V_11 . V_67 = V_68 ;
V_32 = F_33 ( V_38 , & V_8 -> V_2 ) ;
if ( V_32 ) {
F_17 ( V_8 -> V_2 . V_38 -> V_40 ,
L_3 ,
V_8 -> V_2 . V_39 , V_32 ) ;
goto V_69;
}
return & V_8 -> V_42 ;
V_69:
F_23 ( & V_8 -> V_2 . V_27 ) ;
V_59:
F_34 ( V_8 -> V_42 . V_29 ) ;
V_48:
F_24 ( V_8 ) ;
return F_26 ( V_32 ) ;
}
