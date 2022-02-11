static int F_1 ( struct V_1 * V_1 )
{
char V_2 [ V_3 ] ;
int V_4 ;
F_2 ( V_2 , V_1 -> V_5 ,
0xffff , 0xffff / 2 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
const struct V_7 * V_8 ;
V_8 = & V_9 [ V_4 ] ;
F_3 ( V_2 , V_8 -> V_10 , V_8 -> V_11 ) ;
}
return F_4 ( V_1 -> V_12 -> V_13 ,
F_5 ( V_14 ) , V_2 ) ;
}
static int F_6 ( struct V_12 * V_12 )
{
char V_15 [ V_16 ] ;
int V_4 ;
int V_17 ;
for ( V_4 = 0 ; V_4 < V_18 ; V_4 ++ ) {
const struct V_19 * V_20 ;
V_20 = & V_21 [ V_4 ] ;
F_7 ( V_15 , V_20 -> V_20 , V_20 -> V_22 ,
V_20 -> V_23 , V_20 -> V_11 ) ;
V_17 = F_4 ( V_12 -> V_13 , F_5 ( V_24 ) , V_15 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_12 * V_12 , T_1 V_5 ,
const struct V_25 * V_26 ,
T_2 V_27 )
{
char V_28 [ V_29 ] ;
int V_4 ;
int V_17 ;
for ( V_4 = 0 ; V_4 < V_27 ; V_4 ++ ) {
const struct V_25 * V_30 ;
V_30 = & V_26 [ V_4 ] ;
F_9 ( V_28 , V_5 , V_30 -> V_31 . V_32 , V_30 -> V_22 ,
V_30 -> V_33 , V_30 -> V_34 , V_30 -> V_20 ) ;
V_17 = F_4 ( V_12 -> V_13 , F_5 ( V_35 ) , V_28 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 )
{
return F_8 ( V_1 -> V_12 ,
V_1 -> V_5 , V_36 ,
V_37 ) ;
}
static int F_11 ( struct V_12 * V_12 )
{
return F_8 ( V_12 , 0 , V_38 ,
V_39 ) ;
}
static int F_12 ( struct V_1 * V_1 )
{
char V_40 [ V_41 ] ;
int V_4 ;
int V_17 ;
for ( V_4 = 0 ; V_4 < V_42 ; V_4 ++ ) {
const struct V_43 * V_44 ;
V_44 = & V_45 [ V_4 ] ;
F_13 ( V_40 , V_1 -> V_5 ,
V_44 -> V_20 , V_44 -> V_22 ,
V_44 -> V_33 , V_44 -> V_34 ) ;
V_17 = F_4 ( V_1 -> V_12 -> V_13 ,
F_5 ( V_46 ) , V_40 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
static int F_14 ( struct V_12 * V_12 )
{
char V_47 [ V_48 ] ;
int V_4 ;
int V_17 ;
for ( V_4 = 0 ; V_4 < V_49 ; V_4 ++ ) {
const struct V_50 * V_51 ;
V_51 = & V_52 [ V_4 ] ;
F_15 ( V_47 , V_51 -> V_53 , V_51 -> V_33 ,
V_51 -> V_34 , V_51 -> V_20 ) ;
V_17 = F_4 ( V_12 -> V_13 , F_5 ( V_54 ) , V_47 ) ;
if ( V_17 )
return V_17 ;
}
return 0 ;
}
int F_16 ( struct V_12 * V_12 )
{
int V_17 ;
V_17 = F_6 ( V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_11 ( V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_14 ( V_12 ) ;
return V_17 ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_17 ;
V_17 = F_1 ( V_1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_10 ( V_1 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_12 ( V_1 ) ;
return V_17 ;
}
