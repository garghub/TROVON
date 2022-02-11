static void F_1 ( void * V_1 , unsigned V_2 )
{
unsigned char * V_3 ;
int V_4 ;
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 ;
if ( V_2 != V_9 )
return;
V_8 = F_2 ( & V_6 -> V_10 ) ;
if ( ! V_8 )
return;
for (; ; ) {
if ( F_3 ( V_11 , & V_8 -> V_12 ) )
break;
V_4 = F_4 ( V_6 -> V_13 ) ;
if ( V_4 == 0 )
break;
V_4 = F_5 ( & V_6 -> V_10 , & V_3 , V_4 ) ;
if ( F_6 ( V_6 -> V_13 , V_3 , V_4 ) != V_4 ) {
F_7 ( L_1 ) ;
}
F_8 ( & V_6 -> V_10 ) ;
}
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
}
static int F_11 ( struct V_14 * V_15 , struct V_7 * V_8 )
{
struct V_5 * V_6 = F_12 ( V_15 , struct V_5 ,
V_10 ) ;
int V_16 , V_17 = 0 ;
const char * V_18 = NULL ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
if ( V_20 [ V_16 ] . V_21 == V_8 -> V_22 ) {
V_18 = V_20 [ V_16 ] . V_18 ;
break;
}
}
if ( ! V_18 )
return - V_23 ;
if ( V_6 -> V_13 )
F_13 ( V_6 -> V_13 ) ;
else
V_17 = F_14 ( V_18 , & V_6 -> V_13 , V_6 , F_1 ) ;
if ( ! V_17 )
V_8 -> V_24 = V_6 ;
return V_17 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_5 * V_6 = F_12 ( V_15 , struct V_5 ,
V_10 ) ;
if ( V_6 -> V_13 ) {
F_16 ( V_6 -> V_13 ) ;
V_6 -> V_13 = 0 ;
}
}
static int F_17 ( struct V_7 * V_8 , struct V_25 * V_26 )
{
struct V_5 * V_6 = V_27 + V_8 -> V_22 ;
return F_18 ( & V_6 -> V_10 , V_8 , V_26 ) ;
}
static void F_19 ( struct V_7 * V_8 , struct V_25 * V_26 )
{
struct V_5 * V_6 = V_8 -> V_24 ;
F_20 ( & V_6 -> V_10 , V_8 , V_26 ) ;
}
static int F_21 ( struct V_7 * V_8 ,
const unsigned char * V_28 , int V_29 )
{
struct V_5 * V_6 = V_8 -> V_24 ;
int V_4 ;
V_4 = F_22 ( V_6 -> V_13 ) ;
if ( V_29 > V_4 )
V_29 = V_4 ;
return F_23 ( V_6 -> V_13 , V_28 , V_29 ) ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_24 ;
return F_22 ( V_6 -> V_13 ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_24 ;
return F_4 ( V_6 -> V_13 ) ;
}
static void F_26 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_24 ;
F_13 ( V_6 -> V_13 ) ;
}
static int T_1 F_27 ( void )
{
int V_30 , V_16 ;
V_31 = F_28 ( V_32 ) ;
if ( V_31 == 0 )
return - V_33 ;
V_31 -> V_34 = L_2 ;
V_31 -> V_18 = L_3 ;
V_31 -> V_35 = 0 ;
V_31 -> V_36 = 0 ;
V_31 -> type = V_37 ;
V_31 -> V_38 = V_39 ;
V_31 -> V_40 = V_41 ;
V_31 -> V_40 . V_42 = 0 ;
V_31 -> V_40 . V_43 = 0 ;
V_31 -> V_40 . V_44 = V_45 | V_46 | V_47 ;
V_31 -> V_40 . V_48 = 0 ;
V_31 -> V_12 = V_49 |
V_50 | V_51 ;
F_29 ( V_31 , & V_52 ) ;
V_30 = F_30 ( V_31 ) ;
if ( V_30 )
return V_30 ;
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
struct V_14 * V_10 = & V_27 [ V_20 [ V_16 ] . V_21 ] . V_10 ;
F_31 ( V_10 ) ;
V_10 -> V_53 = & V_54 ;
F_32 ( V_10 , V_31 ,
V_20 [ V_16 ] . V_21 , NULL ) ;
}
return 0 ;
}
