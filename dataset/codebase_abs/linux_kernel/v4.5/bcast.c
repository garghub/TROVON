static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_3 ;
}
int F_2 ( struct V_2 * V_2 )
{
return F_3 ( F_4 ( V_2 ) ) ;
}
static void F_5 ( struct V_2 * V_2 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
int V_5 = F_6 ( V_4 -> V_6 ) ;
int V_7 , V_8 ;
V_4 -> V_9 = V_10 ;
if ( ! V_5 )
return;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( ! V_4 -> V_12 [ V_7 ] )
continue;
V_8 = F_7 ( V_2 , V_7 ) ;
if ( V_8 < F_3 ( V_4 -> V_6 ) )
F_8 ( V_4 -> V_6 , V_8 ) ;
if ( V_4 -> V_12 [ V_7 ] < V_5 )
continue;
V_4 -> V_9 = V_7 ;
if ( ( V_7 ^ F_9 ( V_2 ) ) & 1 )
break;
}
}
void F_10 ( struct V_2 * V_2 , int V_13 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
F_11 ( V_2 ) ;
V_4 -> V_12 [ V_13 ] ++ ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_2 * V_2 , int V_13 )
{
struct V_1 * V_4 = V_1 ( V_2 ) ;
F_11 ( V_2 ) ;
V_4 -> V_12 [ V_13 ] -- ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_2 * V_2 , struct V_14 * V_15 )
{
int V_13 ;
struct V_1 * V_4 = V_1 ( V_2 ) ;
struct V_16 * V_17 , * V_18 ;
struct V_14 V_19 ;
if ( F_15 ( V_15 ) )
return;
V_13 = V_4 -> V_9 ;
if ( V_13 >= 0 ) {
F_16 ( V_2 , V_13 , V_15 ) ;
return;
}
F_17 ( & V_19 ) ;
for ( V_13 = 0 ; V_13 < V_11 ; V_13 ++ ) {
if ( ! V_4 -> V_12 [ V_13 ] )
continue;
F_18 (xmitq, skb) {
V_18 = F_19 ( V_17 , V_20 ) ;
if ( ! V_18 )
break;
F_20 ( & V_19 , V_18 ) ;
}
F_16 ( V_2 , V_13 , & V_19 ) ;
}
F_21 ( V_15 ) ;
F_21 ( & V_19 ) ;
}
int F_22 ( struct V_2 * V_2 , struct V_14 * V_21 )
{
struct V_22 * V_23 = F_4 ( V_2 ) ;
struct V_14 V_15 , V_24 , V_25 ;
int V_26 = 0 ;
F_23 ( & V_25 ) ;
F_23 ( & V_15 ) ;
F_17 ( & V_24 ) ;
if ( F_24 ( ! F_25 ( V_21 , & V_25 ) ) )
return - V_27 ;
F_11 ( V_2 ) ;
if ( F_6 ( V_23 ) )
V_26 = F_26 ( V_23 , V_21 , & V_15 ) ;
F_12 ( V_2 ) ;
if ( F_24 ( V_26 ) ) {
F_21 ( & V_25 ) ;
return V_26 ;
}
F_14 ( V_2 , & V_15 ) ;
F_27 ( V_2 , & V_25 , & V_24 ) ;
F_21 ( V_21 ) ;
return 0 ;
}
int F_28 ( struct V_2 * V_2 , struct V_22 * V_23 , struct V_16 * V_17 )
{
struct V_28 * V_29 = F_29 ( V_17 ) ;
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
int V_26 ;
F_23 ( & V_15 ) ;
if ( F_30 ( V_29 ) != F_31 ( V_2 ) || ! F_32 ( V_23 ) ) {
F_33 ( V_17 ) ;
return 0 ;
}
F_11 ( V_2 ) ;
if ( F_34 ( V_29 ) == V_30 )
V_26 = F_35 ( V_23 , V_17 , & V_15 ) ;
else
V_26 = F_36 ( V_23 , V_17 , NULL ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
return V_26 ;
}
void F_38 ( struct V_2 * V_2 , struct V_22 * V_23 , T_1 V_31 )
{
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
F_39 ( V_23 , V_31 , & V_15 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
void F_40 ( struct V_2 * V_2 , struct V_22 * V_23 ,
struct V_28 * V_29 )
{
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
if ( F_41 ( V_29 ) == V_32 ) {
F_39 ( V_23 , F_42 ( V_29 ) , & V_15 ) ;
F_43 ( V_23 , V_29 , & V_15 ) ;
} else {
F_44 ( V_23 , V_29 ) ;
}
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
void F_45 ( struct V_2 * V_2 , struct V_22 * V_33 ,
struct V_14 * V_15 )
{
struct V_22 * V_34 = F_4 ( V_2 ) ;
F_11 ( V_2 ) ;
F_46 ( V_34 , V_33 , V_15 ) ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_47 ( struct V_2 * V_2 , struct V_22 * V_35 )
{
struct V_22 * V_34 = F_4 ( V_2 ) ;
struct V_14 * V_24 = & V_1 ( V_2 ) -> V_24 ;
struct V_14 V_15 ;
F_23 ( & V_15 ) ;
F_11 ( V_2 ) ;
F_48 ( V_34 , V_35 , & V_15 ) ;
F_5 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 , & V_15 ) ;
if ( ! F_15 ( V_24 ) )
F_37 ( V_2 , V_24 ) ;
}
int F_49 ( struct V_2 * V_2 )
{
struct V_22 * V_23 = F_4 ( V_2 ) ;
if ( ! V_23 )
return - V_36 ;
F_11 ( V_2 ) ;
F_50 ( V_23 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_2 , T_1 V_37 )
{
struct V_22 * V_23 = F_4 ( V_2 ) ;
if ( ! V_23 )
return - V_36 ;
if ( V_37 < V_38 )
V_37 = V_38 ;
if ( V_37 > V_39 )
return - V_40 ;
F_11 ( V_2 ) ;
F_52 ( V_23 , V_37 ) ;
F_12 ( V_2 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_2 , struct V_41 * V_42 [] )
{
int V_43 ;
T_1 V_44 ;
struct V_41 * V_45 [ V_46 + 1 ] ;
if ( ! V_42 [ V_47 ] )
return - V_40 ;
V_43 = F_54 ( V_42 [ V_47 ] , V_45 ) ;
if ( V_43 )
return V_43 ;
if ( ! V_45 [ V_48 ] )
return - V_49 ;
V_44 = F_55 ( V_45 [ V_48 ] ) ;
return F_51 ( V_2 , V_44 ) ;
}
int F_56 ( struct V_2 * V_2 )
{
struct F_1 * V_50 = F_1 ( V_2 ) ;
struct V_1 * V_4 = NULL ;
struct V_22 * V_23 = NULL ;
V_4 = F_57 ( sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
goto V_51;
V_50 -> V_3 = V_4 ;
F_58 ( & F_1 ( V_2 ) -> V_52 ) ;
if ( ! F_59 ( V_2 , 0 , 0 ,
V_53 ,
V_54 ,
0 ,
& V_4 -> V_24 ,
NULL ,
NULL ,
& V_23 ) )
goto V_51;
V_4 -> V_6 = V_23 ;
V_50 -> V_55 = V_23 ;
return 0 ;
V_51:
F_60 ( V_4 ) ;
F_60 ( V_23 ) ;
return - V_56 ;
}
void F_61 ( struct V_2 * V_2 )
{
F_62 ( F_4 ( V_2 ) , F_9 ( V_2 ) ) ;
}
void F_63 ( struct V_2 * V_2 )
{
struct F_1 * V_50 = F_64 ( V_2 , V_57 ) ;
F_65 () ;
F_60 ( V_50 -> V_3 ) ;
F_60 ( V_50 -> V_55 ) ;
}
