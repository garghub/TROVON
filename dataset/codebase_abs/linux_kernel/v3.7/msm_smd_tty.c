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
V_4 = F_5 ( V_8 , & V_3 , V_4 ) ;
if ( F_6 ( V_6 -> V_13 , V_3 , V_4 ) != V_4 ) {
F_7 ( L_1 ) ;
}
F_8 ( V_8 ) ;
}
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
}
static int F_11 ( struct V_14 * V_15 , struct V_7 * V_8 )
{
int V_16 , V_17 = 0 ;
int V_18 = V_8 -> V_19 ;
const char * V_20 = NULL ;
struct V_5 * V_6 = V_21 + V_18 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( V_23 [ V_16 ] . V_24 == V_18 ) {
V_20 = V_23 [ V_16 ] . V_20 ;
break;
}
}
if ( ! V_20 )
return - V_25 ;
if ( V_6 -> V_13 )
F_12 ( V_6 -> V_13 ) ;
else
V_17 = F_13 ( V_20 , & V_6 -> V_13 , V_6 , F_1 ) ;
if ( ! V_17 )
V_8 -> V_26 = V_6 ;
return V_17 ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_15 ) ;
V_6 = V_8 -> V_26 ;
if ( V_6 -> V_13 ) {
F_15 ( V_6 -> V_13 ) ;
V_6 -> V_13 = 0 ;
}
V_8 -> V_26 = 0 ;
F_10 ( V_8 ) ;
}
static int F_16 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_21 + V_8 -> V_19 ;
return F_17 ( & V_6 -> V_10 , V_8 , V_28 ) ;
}
static void F_18 ( struct V_7 * V_8 , struct V_27 * V_28 )
{
struct V_5 * V_6 = V_8 -> V_26 ;
F_19 ( & V_6 -> V_10 , V_8 , V_28 ) ;
}
static int F_20 ( struct V_7 * V_8 ,
const unsigned char * V_29 , int V_30 )
{
struct V_5 * V_6 = V_8 -> V_26 ;
int V_4 ;
V_4 = F_21 ( V_6 -> V_13 ) ;
if ( V_30 > V_4 )
V_30 = V_4 ;
return F_22 ( V_6 -> V_13 , V_29 , V_30 ) ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_26 ;
return F_21 ( V_6 -> V_13 ) ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_26 ;
return F_4 ( V_6 -> V_13 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_26 ;
F_12 ( V_6 -> V_13 ) ;
}
static int T_1 F_26 ( void )
{
int V_31 , V_16 ;
V_32 = F_27 ( V_33 ) ;
if ( V_32 == 0 )
return - V_34 ;
V_32 -> V_35 = L_2 ;
V_32 -> V_20 = L_3 ;
V_32 -> V_36 = 0 ;
V_32 -> V_37 = 0 ;
V_32 -> type = V_38 ;
V_32 -> V_39 = V_40 ;
V_32 -> V_41 = V_42 ;
V_32 -> V_41 . V_43 = 0 ;
V_32 -> V_41 . V_44 = 0 ;
V_32 -> V_41 . V_45 = V_46 | V_47 | V_48 ;
V_32 -> V_41 . V_49 = 0 ;
V_32 -> V_12 = V_50 |
V_51 | V_52 ;
F_28 ( V_32 , & V_53 ) ;
V_31 = F_29 ( V_32 ) ;
if ( V_31 )
return V_31 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
struct V_14 * V_10 = & V_21 [ V_23 [ V_16 ] . V_24 ] . V_10 ;
F_30 ( V_10 ) ;
V_10 -> V_54 = & V_55 ;
F_31 ( V_10 , V_32 ,
V_23 [ V_16 ] . V_24 , NULL ) ;
}
return 0 ;
}
