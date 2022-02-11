static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
enum V_9 V_10 ;
int V_11 ;
V_8 = F_2 ( & V_2 -> V_5 , sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 )
return NULL ;
V_11 = F_3 ( V_4 , 0 , & V_10 ) ;
if ( V_11 < 0 )
return NULL ;
V_8 -> V_13 = V_11 ;
V_8 -> V_14 = V_10 & V_15 ;
V_11 = F_3 ( V_4 , 1 , & V_10 ) ;
if ( V_11 < 0 )
return NULL ;
V_8 -> V_16 = V_11 ;
V_8 -> V_17 = V_10 & V_15 ;
V_11 = F_3 ( V_4 , 2 , & V_10 ) ;
if ( V_11 > 0 ) {
V_8 -> V_18 = V_11 ;
V_8 -> V_19 = V_10 & V_15 ;
}
return V_8 ;
}
static void F_4 ( struct V_20 * V_21 , int V_22 )
{
struct V_23 * V_24 =
F_5 ( V_21 , struct V_23 , V_21 ) ;
if ( V_24 -> V_18 ) {
F_6 ( V_24 -> V_18 , 1 ) ;
return;
}
if ( V_22 )
F_7 ( V_24 -> V_16 , 1 ) ;
else
F_8 ( V_24 -> V_16 ) ;
}
static int F_9 ( struct V_20 * V_21 )
{
struct V_23 * V_24 =
F_5 ( V_21 , struct V_23 , V_21 ) ;
return F_10 ( V_24 -> V_16 ) ;
}
static void F_11 ( struct V_20 * V_21 , int V_25 )
{
struct V_23 * V_24 =
F_5 ( V_21 , struct V_23 , V_21 ) ;
if ( V_24 -> V_18 )
F_6 ( V_24 -> V_18 , V_25 ) ;
else
F_6 ( V_24 -> V_16 , V_25 ) ;
}
static void F_12 ( struct V_20 * V_21 , int V_25 )
{
struct V_23 * V_24 =
F_5 ( V_21 , struct V_23 , V_21 ) ;
F_6 ( V_24 -> V_13 , V_25 ) ;
}
static struct V_26 * F_13 ( struct V_27 * V_5 ,
struct V_7 * V_8 ,
int V_28 )
{
struct V_26 * V_29 ;
struct V_23 * V_24 ;
int V_30 ;
int V_13 , V_16 , V_18 ;
unsigned long V_31 = V_32 ;
unsigned long V_33 = V_34 ;
unsigned long V_35 = V_36 ;
V_24 = F_2 ( V_5 , sizeof( * V_24 ) , V_12 ) ;
if ( ! V_24 )
goto V_37;
V_24 -> V_21 . V_38 = & V_39 ;
V_24 -> V_21 . V_40 = V_8 -> V_40 ;
V_13 = V_8 -> V_13 ;
V_24 -> V_13 = F_14 ( V_13 ) ;
if ( V_8 -> V_14 )
V_31 = V_36 | V_41 ;
V_16 = V_8 -> V_16 ;
V_24 -> V_16 = F_14 ( V_16 ) ;
if ( V_8 -> V_17 )
V_33 |= V_41 ;
V_18 = V_8 -> V_18 ;
if ( V_18 ) {
V_24 -> V_18 = F_14 ( V_18 ) ;
if ( V_8 -> V_19 )
V_35 = V_32 | V_41 ;
}
V_29 = F_15 ( & V_24 -> V_21 ) ;
if ( ! V_29 )
goto V_37;
V_29 -> V_42 = L_1 ,
V_29 -> V_43 = V_8 -> V_43 ;
V_29 -> V_44 = V_8 -> V_44 ;
memcpy ( V_29 -> V_45 , V_8 -> V_46 , sizeof( V_29 -> V_45 ) ) ;
V_29 -> V_47 = V_5 ;
if ( V_29 -> V_43 == ~ 0 )
goto V_48;
for ( V_30 = 0 ; V_30 < V_49 ; V_30 ++ )
if ( ! V_29 -> V_45 [ V_30 ] )
V_29 -> V_45 [ V_30 ] = V_50 ;
if ( V_28 != - 1 )
snprintf ( V_29 -> V_51 , V_52 , L_2 , V_28 ) ;
else
strncpy ( V_29 -> V_51 , L_3 , V_52 ) ;
if ( F_16 ( V_5 , V_13 , V_31 , L_4 ) )
goto V_48;
if ( F_16 ( V_5 , V_16 , V_33 , L_5 ) )
goto V_48;
if ( V_18 && F_16 ( V_5 , V_18 , V_35 , L_6 ) )
goto V_48;
F_17 ( V_5 , V_29 ) ;
return V_29 ;
V_48:
F_18 ( V_29 ) ;
V_37:
return NULL ;
}
static void F_19 ( struct V_27 * V_5 )
{
struct V_26 * V_53 = F_20 ( V_5 ) ;
F_18 ( V_53 ) ;
}
static void F_21 ( struct V_27 * V_5 )
{
struct V_26 * V_53 = F_20 ( V_5 ) ;
F_22 ( V_53 ) ;
F_19 ( V_5 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_26 * V_29 ;
int V_11 , V_28 ;
if ( V_2 -> V_5 . V_6 ) {
V_8 = F_1 ( V_2 ) ;
V_28 = F_24 ( V_2 -> V_5 . V_6 , L_7 ) ;
if ( V_28 < 0 ) {
F_25 ( & V_2 -> V_5 , L_8 ) ;
V_28 = 0 ;
}
} else {
V_8 = F_26 ( & V_2 -> V_5 ) ;
V_28 = V_2 -> V_51 ;
}
if ( ! V_8 )
return - V_54 ;
V_29 = F_13 ( & V_2 -> V_5 , V_8 , V_28 ) ;
if ( ! V_29 )
return - V_54 ;
if ( V_2 -> V_5 . V_6 )
V_11 = F_27 ( V_29 , V_2 -> V_5 . V_6 ) ;
else
V_11 = F_28 ( V_29 ) ;
if ( V_11 )
F_19 ( & V_2 -> V_5 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_5 ) ;
return 0 ;
}
